#include "mainwindow.h"
#include "ui_mainwindow.h"

mainWindow::mainWindow( QWidget *parent ) :
    QMainWindow( parent ),
    _ui( new Ui::mainWindow ),
    _image( nullptr ),
    _pixmap( nullptr )
{
    _ui->setupUi( this );

    connect( _ui->spb_startStep, SIGNAL( valueChanged( int ) ), this, SLOT( checkStepParameter() ) );
    connect( _ui->spb_stepsToCalc, SIGNAL( valueChanged( int ) ), this, SLOT( checkStepParameter() ) );
    connect( _ui->spb_stepsTotal, SIGNAL( valueChanged( int ) ), this, SLOT( checkStepParameter() ) );

    connect( _ui->btn_selectImage, SIGNAL( clicked() ), this, SLOT( selectImage() ) );
    connect( _ui->btn_calculate, SIGNAL( clicked() ), this, SLOT( calculate() ) );
    connect( _ui->btn_calculateAndSave, SIGNAL( clicked() ), this, SLOT( calculateAndSave() ) );
    connect( _ui->btn_clearLog, SIGNAL( clicked() ), this, SLOT( clearLog() ) );
    connect( _ui->btn_clearPointsList, SIGNAL( clicked() ), this, SLOT( clearPointsList() ) );
    connect( _ui->btn_refreshImage, SIGNAL( clicked() ), this, SLOT( refreshImage() ) );
    connect( _ui->btn_clearImage, SIGNAL( clicked() ), this, SLOT( clearImage() ) );
}

mainWindow::~mainWindow()
{
    delete _image;
    delete _pixmap;
    delete _ui;
}

void mainWindow::toLog( const QString &text, logColor type )
{
    QString logText = text;

    if( type == logColor::error )
    {
        _ui->txt_log->setTextColor( Qt::red );
        logText = "Error: " + text;
    }
    else if( type == logColor::success )
    {
        _ui->txt_log->setTextColor( Qt::darkGreen );
    }
    else
    {
        _ui->txt_log->setTextColor( Qt::black );
    }

    _ui->txt_log->append( logText );
}

void mainWindow::clearLog()
{
    _ui->txt_log->clear();
}

void mainWindow::clearPointsList()
{
    _ui->list_pointsFound->clear();
}

void mainWindow::checkStepParameter()
{
    if( _ui->spb_startStep->value() > _ui->spb_stepsTotal->value() )
    {
        _ui->spb_startStep->setValue( _ui->spb_stepsTotal->value() );
        toLog( "Start step must be a number smaller than the number of total steps!", logColor::error );
    }

    if( _ui->spb_startStep->value() + _ui->spb_stepsToCalc->value() > _ui->spb_stepsTotal->value() )
    {
        _ui->spb_stepsToCalc->setValue( _ui->spb_stepsTotal->value() - _ui->spb_startStep->value() );
        toLog( "Start step + steps to calc must be a number smaller or equal the number of total steps!", logColor::error );
    }
}

void mainWindow::clearImage()
{
    _ui->lbl_image->setText( "<image>" );
}

void mainWindow::selectImage()
{
    QString fileName = QFileDialog::getOpenFileName( this, "Select image", "", "Image Files (*.png *.jpg)" );

    if( !fileName.isEmpty() )
    {
        _ui->txt_selectImage->setText( fileName );
        delete _image;
        delete _pixmap;
        _pixmap = new QPixmap( fileName );
        _image = new QImage( _pixmap->toImage() );
        _ui->lbl_image->setPixmap( (*_pixmap).scaled( _ui->lbl_image->width(), _ui->lbl_image->height(), Qt::KeepAspectRatio ) );

        if( _ui->chb_autodetectTopBottomValue->isChecked() )
        {
            detectTopBottomValues();
        }

        if( _ui->chb_autodetectSteps->isChecked() )
        {
            detectSteps();
        }
    }
}

bool mainWindow::checkInput()
{
    if( _ui->txt_selectImage->text().isEmpty() )
    {
        toLog( "No image selected!", logColor::error );
        return false;
    }

    if( _ui->dsp_bottomValue->value() == _ui->dsp_topValue->value() )
    {
        toLog( "Top and bottom values cannot be equal!", logColor::error );
        return false;
    }

    return true;
}

void mainWindow::calculate()
{
    doCalculation( "" );
}

void mainWindow::calculateAndSave()
{
    QString filename = QFileDialog::getSaveFileName( this, "Save image", "", "Images (*.png)" );
    if( !filename.isEmpty() )
    {
        if( !filename.endsWith( ".png", Qt::CaseSensitivity::CaseInsensitive ) )
        {
            filename.append( ".png" );
        }
        doCalculation( filename );
    }
}

void mainWindow::detectTopBottomValues()
{
    int borderTop = getTopBorder();
    int borderBottom = getBottomBorder();
    int borderLeft = getLeftBorder();
    int borderRight = getRightBorder();

    if( !checkBorders( borderTop, borderBottom, borderLeft, borderRight ) )
    {
        toLog( "Unable to find borders at the selected image!", logColor::error );
        return;
    }

    double topValue = 0.0;
    double bottomValue = 0.0;
    bool topValueOk = getTopValue( borderTop, borderLeft, &topValue );
    bool bottomValueOk = getBottomValue( borderBottom, borderLeft, &bottomValue );

    if( topValueOk && bottomValueOk )
    {
        _ui->dsp_topValue->setValue( topValue );
        toLog( "Top value set to " + QString::number( topValue ), logColor::info );

        _ui->dsp_bottomValue->setValue( bottomValue );
        toLog( "Bottom value set to " + QString::number( bottomValue ), logColor::info );
    }
    else
    {
        toLog( "Failed to read top/bottom values!", logColor::error );
        return;
    }
}

void mainWindow::detectSteps()
{
    delete _image;
    _image = new QImage( _pixmap->toImage() );

    int borderTop = getTopBorder();
    int borderBottom = getBottomBorder();
    int borderLeft = getLeftBorder();
    int borderRight = getRightBorder();

    if( !checkBorders( borderTop, borderBottom, borderLeft, borderRight ) )
    {
        toLog( "Auto detecting steps stopped due to errors!", logColor::info );
        return;
    }

    int boardWidth = borderRight - borderLeft;
    std::vector<int> xPositions;
    std::vector<int> yPositions;
    int y1 = 0;
    int y2 = 0;
    int y3 = 0;

    for( int i = 0; i < boardWidth; i++ )
    {
        int x = borderLeft + i;
        for( int y = borderTop; y < borderBottom; y++ )
        {
            if( QColor( _image->pixel( x, y ) ) == _lineColor )
            {
                yPositions.push_back( y );
            }
        }

        if( yPositions.size() > 0 )
        {
            y3 = getAverageInt( yPositions );
            yPositions.clear();
        }
        else
        {
            y3 = y2;
        }

        if( (y1 < y2 && y2 > y3)
                || (y1 > y2 && y2 < y3) )
        {
            xPositions.push_back( x-1 );
        }

        y1 = y2;
        y2 = y3;
    }

    int minDist = boardWidth;
    for( int i = 1; i < xPositions.size(); i++ )
    {
        if( xPositions[i] - xPositions[i-1] < minDist )
        {
            minDist = xPositions[i] - xPositions[i-1];
        }
    }

    std::vector<int> smallDists;
    int x1 = 0;
    int x2 = 0;
    for( int i = 1; i < xPositions.size(); i++ )
    {
        if( xPositions[i] - xPositions[i-1] < minDist - 5 )
        {
            smallDists.push_back( xPositions[i] - xPositions[i-1] );
        }
    }

    if( smallDists.size() > 0 )
    {
        minDist = getAverageInt( smallDists );
    }

    if( minDist < boardWidth )
    {
        int numSteps = boardWidth/minDist;
        _ui->spb_startStep->setValue( 1 );
        _ui->spb_stepsToCalc->setValue( 1 ); // to avoid errors
        _ui->spb_stepsTotal->setValue( numSteps );
        _ui->spb_stepsToCalc->setValue( numSteps - 1 );
        toLog( "Number of steps is set to " + QString::number( numSteps ) );
        numSteps--;

        QPainter painter( _image );
        painter.setPen( Qt::green );
        for( int i = 0; i < numSteps; i++ )
        {
            int x = borderLeft + i*boardWidth/(numSteps - 1);
            if( i == 0 )
            {
                x++;
            }
            if( i == numSteps - 1 )
            {
                x--;
            }
            painter.drawLine( x, borderTop + 1, x, borderBottom - 1 );
        }
        painter.end();

        QPixmap tempPixmap;
        tempPixmap.convertFromImage( (*_image) );
        _ui->lbl_image->setPixmap( tempPixmap.scaled( _ui->lbl_image->width(), _ui->lbl_image->height(), Qt::KeepAspectRatio ) );
    }
    else
    {
        toLog( "Unable to determine steps!", logColor::error );
    }
}

void mainWindow::doCalculation( const QString& filename )
{
    bool saveImg = !filename.isEmpty();
    delete _image;
    _image = new QImage( _pixmap->toImage() );

    QString calcStoppedText = "Calculation stopped due to errors!";
    _ui->list_pointsFound->clear();

    if( !checkInput() )
    {
        toLog( calcStoppedText, logColor::info );
        return;
    }

    int borderTop = getTopBorder();
    int borderBottom = getBottomBorder();
    int borderLeft = getLeftBorder();
    int borderRight = getRightBorder();

    if( !checkBorders( borderTop, borderBottom, borderLeft, borderRight ) )
    {
        toLog( calcStoppedText, logColor::info );
        return;
    }

    int boardWidth = borderRight - borderLeft;
    int numSteps = 0;
    int stepsTotal = _ui->spb_stepsTotal->value() - 1; // 5 steps only gives 4 values!
    std::vector<int> yPositions;
    std::vector<double> yValues;

    for( int i = _ui->spb_startStep->value() - 1; i < _ui->spb_startStep->value() + _ui->spb_stepsToCalc->value() - 1; i++ )
    {
        numSteps++;

        int x = borderLeft + i*boardWidth/(stepsTotal - 1);
        if( i == 0 )
        {
            x++;
        }
        if( i == stepsTotal - 1 )
        {
            x--;
        }

        for( int y = borderTop; y < borderBottom; y++ )
        {
            if( QColor( _image->pixel( x, y ) ) == _lineColor )
            {
                yPositions.push_back( y );
            }
        }

        if( yPositions.size() == 0 )
        {
            x--;
            for( int y = borderTop; y < borderBottom; y++ )
            {
                if( QColor( _image->pixel( x, y ) ) == _lineColor )
                {
                    yPositions.push_back( y );
                }
            }

            x += 2;
            for( int y = borderTop; y < borderBottom; y++ )
            {
                if( QColor( _image->pixel( x, y ) ) == _lineColor )
                {
                    yPositions.push_back( y );
                }
            }
            x--;

            if( yPositions.size() == 0 )
            {
                toLog( "Unable to detect y value at x=" + QString::number( x ) + ", i=" + QString::number( i ), logColor::error );
                toLog( calcStoppedText );
                return;
            }
            else
            {
                toLog( "Using value(s) before/after exact position for point " + QString::number( i ), logColor::info );
            }
        }



        int yPosition = getAverageInt( yPositions );
        double yValue = _ui->dsp_bottomValue->value() + (borderBottom - yPosition)*(_ui->dsp_topValue->value() - _ui->dsp_bottomValue->value())/(borderBottom - borderTop);
        //toLog( "i=" + QString::number( i ) + ", x=" + QString::number( x ) + ", y=" + QString::number( yPosition ) + ", value=" + QString::number( yValue ), logColor::info );
        _ui->list_pointsFound->addItem( QString::number( i ) + ": " + QString::number( yValue ) );
        yValues.push_back( yValue );

        int xTexPos = 0;
        int yTextPos = _image->width()/2 - x - 2;
        if( x >= borderRight - 2 )
        {
            xTexPos = (borderBottom - borderTop)/2 - 40;
            yTextPos += 14;
        }

        QPainter painter( _image );
        painter.setPen( Qt::green );
        painter.drawLine( x, borderTop + 1, x, borderBottom - 1 );
        painter.translate( _image->width()/2, _image->height()/2 );
        painter.rotate( 90 );
        painter.drawText( xTexPos, yTextPos, QString::number( yValue ) );
        painter.end();

        yPositions.clear();
    }

    double averageValue = getAverageDouble( yValues );
    toLog( "Average value: " + QString::number( averageValue ), logColor::info );
    _ui->list_pointsFound->addItem( "points average: " + QString::number( averageValue ) );
    toLog( "Calculating finished.", logColor::success );

    if( _image->height() > (borderBottom - borderTop + 22 ) )
    {
        QString infoText = "Average: " + QString::number( averageValue ) + " (" + QString::number( numSteps ) + " values)" ;
        QPainter painter( _image );
        painter.setPen( Qt::green );

        if( borderTop > 12 )
        {
            painter.drawText( (borderRight + borderLeft)/2 - 100, borderTop - 12, infoText );
        }
        else
        {
            painter.drawText( (borderRight + borderLeft)/2 - 100, borderBottom + 2, infoText );
        }
    }

    if( saveImg )
    {
        if( _image->save( filename, "png" ) )
        {
            toLog( "Image saved to " + filename, logColor::success );
        }
        else
        {
            toLog( "Failed to save image " + filename + "!", logColor::error );
        }
    }

    QPixmap tempPixmap;
    tempPixmap.convertFromImage( (*_image) );
    _ui->lbl_image->setPixmap( tempPixmap.scaled( _ui->lbl_image->width(), _ui->lbl_image->height(), Qt::KeepAspectRatio ) );
}

void mainWindow::refreshImage()
{
    QPixmap tempPixmap;
    tempPixmap.convertFromImage( (*_image) );
    _ui->lbl_image->setPixmap( tempPixmap.scaled( _ui->lbl_image->width(), _ui->lbl_image->height(), Qt::KeepAspectRatio ) );
}

bool mainWindow::getTopValue( int topBorder, int leftBorder, double* topValue )
{
    int yStart = topBorder + 2;
    int yEnd = topBorder + 2 + 10;

    int xStart = findNumberStart( leftBorder > 100 ? leftBorder - 100 : 0, leftBorder, yStart, yEnd );
    if( xStart < 0 )
    {
        toLog( "No start found", logColor::error );
        return false;
    }

    return getImageValue( xStart, yStart, yEnd, topValue );
}

bool mainWindow::getBottomValue( int bottomBorder, int leftBorder, double* topValue )
{
    int yStart = bottomBorder - 1 - 10;
    int yEnd = bottomBorder - 1;

    int xStart = findNumberStart( leftBorder > 100 ? leftBorder - 100 : 0, leftBorder, yStart, yEnd );
    if( xStart < 0 )
    {
        return false;
    }

    return getImageValue( xStart, yStart, yEnd, topValue );
}

bool mainWindow::getImageValue( int xStart, int yStart, int yEnd, double* value )
{
    QString valueStr = "";
    std::vector<bool> number;
    xNumbers xNums;

    while( xStart > 0 )
    {
        int xEnd = findNumberEnd( xStart, xStart + 10, yStart, yEnd );
        if( xEnd < 0 )
        {
            return false;
        }

        std::vector<bool> number;

        for( int x = xStart; x <= xEnd; x++ )
        {
            for( int y = yStart; y < yEnd; y++ )
            {
                number.push_back( QColor( _image->pixel( x, y ) ) == _fontColor );
            }
        }

        valueStr += xNums.getString( number );

        xStart = findNumberStart( xEnd + 1, xEnd + 11, yStart, yEnd );
    }

    if( valueStr.length() == 0
            || valueStr.contains( "?" ) )
    {
        if( valueStr.contains( "?" ) )
        {
            toLog( "Unreadable character(s). (" + valueStr + ")", logColor::error );
        }
        return false;
    }

    bool conversionOkay = false;
    (*value) = valueStr.toDouble( &conversionOkay );

    return conversionOkay;
}

int mainWindow::findNumberStart( int xMin, int xMax, int yMin, int yMax )
{
    for( int x = xMin; x < xMax; x++ )
    {
        for( int y = yMin; y < yMax; y++ )
        {
            if( QColor( _image->pixel( x, y ) ) == _fontColor )
            {
                return x;
            }
        }
    }

    return -1;
}

int mainWindow::findNumberEnd( int xMin, int xMax, int yMin, int yMax )
{
    for( int x = xMin; x < xMax; x++ )
    {
        bool inRow = false;

        for( int y = yMin; y < yMax; y++ )
        {
            if( QColor( _image->pixel( x, y ) ) == _fontColor )
            {
                inRow = true;
            }
        }

        if( !inRow )
        {
            return x-1;
        }
    }

    return -1;
}

bool mainWindow::checkBorders( int borderTop, int borderBottom, int borderLeft, int borderRight )
{
    if( borderTop < 0 )
    {
        toLog( "Top border not found!", logColor::error );
        return false;
    }
    else
    {
        //toLog( "Top border: " + QString::number( borderTop ), logColor::info );
    }

    if( borderBottom < 0 )
    {
        toLog( "Bottom border not found!", logColor::error );
        return false;
    }
    else
    {
        //toLog( "Bottom border: " + QString::number( borderBottom ), logColor::info );
    }

    if( borderLeft < 0 )
    {
        toLog( "Left border not found!", logColor::error );
        return false;
    }
    else
    {
        //toLog( "Left border: " + QString::number( borderLeft ), logColor::info );
    }

    if( borderRight < 0 )
    {
        toLog( "Right border not found!", logColor::error );
        return false;
    }
    else
    {
        //toLog( "Right border: " + QString::number( borderRight ), logColor::info );
    }

    if( borderTop == borderBottom )
    {
        toLog( "Top border and bottom border are equal!", logColor::error );
        return false;
    }
    if( borderLeft == borderRight )
    {
        toLog( "Left border and right border are equal!", logColor::error );
        return false;
    }

    return true;
}

int mainWindow::getTopBorder()
{
    for( int i = 0; i < _image->height(); i++ )
    {
        if( QColor( _image->pixel( _image->width()/2, i ) ) == _borderColor )
        {
            return i;
        }
    }

    return -1;
}

int mainWindow::getBottomBorder()
{
    for( int i = _image->height() - 1; i >= 0; i-- )
    {
        if( QColor( _image->pixel( _image->width()/2, i ) ) == _borderColor )
        {
            return i;
        }
    }

    return -1;
}

int mainWindow::getLeftBorder()
{
    for( int i = 0; i < _image->width(); i++ )
    {
        if( QColor( _image->pixel( i, _image->height()/2 ) ) == _borderColor )
        {
            return i;
        }
    }

    return -1;
}

int mainWindow::getRightBorder()
{
    for( int i = _image->width() - 1; i >= 0; i-- )
    {
        if( QColor( _image->pixel( i, _image->height()/2 ) ) == _borderColor )
        {
            return i;
        }
    }

    return -1;
}

int mainWindow::getAverageInt( const std::vector<int>& values )
{
    int sum = 0;

    for( int i = 0; i < values.size(); i++ )
    {
        sum += values[i];
    }
    return sum / values.size();
}

double mainWindow::getAverageDouble( const std::vector<double>& values )
{
    double sum = 0.0;

    for( int i = 0; i < values.size(); i++ )
    {
        sum += values[i];
    }
    return sum / values.size();
}

double mainWindow::abs( double value )
{
    return value < 0 ? -value : value;
}

QString mainWindow::qColorToRGBString( QColor c )
{
    return "RGB( " + QString::number( c.red() ) + ", " + QString::number( c.green() ) + ", " + QString::number( c.blue() ) + " )";
}
