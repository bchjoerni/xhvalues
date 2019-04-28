#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <QPixmap>
#include <QImage>
#include <QColor>
#include <QRgb>
#include <QPainter>

#include <vector>

#include "xnumbers.h"

namespace Ui
{
    class mainWindow;
}

enum logColor
{
    info, error, success

};

class mainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit mainWindow( QWidget *parent = 0 );
    ~mainWindow();
    void toLog( const QString& text, logColor type = logColor::info );

private slots:
    void checkStepParameter();
    void selectImage();
    void calculate();
    void calculateAndSave();
    void clearLog();
    void clearPointsList();
    void refreshImage();
    void clearImage();

private:
    void detectTopBottomValues();
    void detectSteps();
    bool checkInput();
    bool checkBorders( int top, int bottom, int left, int right );
    bool getTopValue( int topBorder, int leftBorder, double* topValue );
    bool getBottomValue( int bottomBorder, int leftBorder, double* topValue );
    bool getImageValue( int xStart, int yStart, int yEnd, double* topValue );
    int findNumberStart( int xMin, int xMax, int yMin, int yMax );
    int findNumberEnd( int xMin, int xMax, int yMin, int yMax );
    int getTopBorder();
    int getBottomBorder();
    int getLeftBorder();
    int getRightBorder();
    void doCalculation( const QString& filename );
    int getAverageInt( const std::vector<int>& values );
    double getAverageDouble( const std::vector<double>& values );
    double abs( double value );
    QString qColorToRGBString( QColor c );

    Ui::mainWindow *_ui;
    QImage* _image;
    QPixmap* _pixmap;

    const QColor _borderColor = QColor( 255, 0, 0 );
    const QColor _lineColor = QColor( 245, 222, 179 );
    const QColor _fontColor = QColor( 0, 255, 255 );
};

#endif // MAINWINDOW_H
