#include "xnumbers.h"

xNumbers::xNumbers()
{
    std::vector<bool> number;

    // e
    number.push_back( false );
    number.push_back( false );
    number.push_back( false );
    number.push_back( false );
    number.push_back( true );
    number.push_back( true );
    number.push_back( true );
    number.push_back( true );
    number.push_back( false );
    number.push_back( false );

    number.push_back( false );
    number.push_back( false );
    number.push_back( false );
    number.push_back( true );
    number.push_back( false );
    number.push_back( true );
    number.push_back( false );
    number.push_back( false );
    number.push_back( true );
    number.push_back( false );

    number.push_back( false );
    number.push_back( false );
    number.push_back( false );
    number.push_back( true );
    number.push_back( false );
    number.push_back( true );
    number.push_back( false );
    number.push_back( false );
    number.push_back( true );
    number.push_back( false );

    number.push_back( false );
    number.push_back( false );
    number.push_back( false );
    number.push_back( true );
    number.push_back( false );
    number.push_back( true );
    number.push_back( false );
    number.push_back( false );
    number.push_back( true );
    number.push_back( false );

    number.push_back( false );
    number.push_back( false );
    number.push_back( false );
    number.push_back( false );
    number.push_back( true );
    number.push_back( true );
    number.push_back( false );
    number.push_back( true );
    number.push_back( false );
    number.push_back( false );

    _numbers.push_back( std::pair<QString, std::vector<bool> >( "e", number ) );
    number.clear();

    // .
    number.push_back( false );
    number.push_back( false );
    number.push_back( false );
    number.push_back( false );
    number.push_back( false );
    number.push_back( false );
    number.push_back( false );
    number.push_back( false );
    number.push_back( true );
    number.push_back( false );

    number.push_back( false );
    number.push_back( false );
    number.push_back( false );
    number.push_back( false );
    number.push_back( false );
    number.push_back( false );
    number.push_back( false );
    number.push_back( true );
    number.push_back( true );
    number.push_back( true );

    number.push_back( false );
    number.push_back( false );
    number.push_back( false );
    number.push_back( false );
    number.push_back( false );
    number.push_back( false );
    number.push_back( false );
    number.push_back( false );
    number.push_back( true );
    number.push_back( false );

    _numbers.push_back( std::pair<QString, std::vector<bool> >( ".", number ) );
    number.clear();

    // -
    number.push_back( false );
    number.push_back( false );
    number.push_back( false );
    number.push_back( false );
    number.push_back( true );
    number.push_back( false );
    number.push_back( false );
    number.push_back( false );
    number.push_back( false );
    number.push_back( false );

    number.push_back( false );
    number.push_back( false );
    number.push_back( false );
    number.push_back( false );
    number.push_back( true );
    number.push_back( false );
    number.push_back( false );
    number.push_back( false );
    number.push_back( false );
    number.push_back( false );

    number.push_back( false );
    number.push_back( false );
    number.push_back( false );
    number.push_back( false );
    number.push_back( true );
    number.push_back( false );
    number.push_back( false );
    number.push_back( false );
    number.push_back( false );
    number.push_back( false );

    number.push_back( false );
    number.push_back( false );
    number.push_back( false );
    number.push_back( false );
    number.push_back( true );
    number.push_back( false );
    number.push_back( false );
    number.push_back( false );
    number.push_back( false );
    number.push_back( false );

    number.push_back( false );
    number.push_back( false );
    number.push_back( false );
    number.push_back( false );
    number.push_back( true );
    number.push_back( false );
    number.push_back( false );
    number.push_back( false );
    number.push_back( false );
    number.push_back( false );

    _numbers.push_back( std::pair<QString, std::vector<bool> >( "-", number ) );
    number.clear();

    // 0
    number.push_back( false );
    number.push_back( false );
    number.push_back( true );
    number.push_back( true );
    number.push_back( true );
    number.push_back( true );
    number.push_back( true );
    number.push_back( false );
    number.push_back( false );
    number.push_back( false );

    number.push_back( false );
    number.push_back( true );
    number.push_back( false );
    number.push_back( false );
    number.push_back( false );
    number.push_back( false );
    number.push_back( false );
    number.push_back( true );
    number.push_back( false );
    number.push_back( false );

    number.push_back( true );
    number.push_back( false );
    number.push_back( false );
    number.push_back( false );
    number.push_back( false );
    number.push_back( false );
    number.push_back( false );
    number.push_back( false );
    number.push_back( true );
    number.push_back( false );

    number.push_back( false );
    number.push_back( true );
    number.push_back( false );
    number.push_back( false );
    number.push_back( false );
    number.push_back( false );
    number.push_back( false );
    number.push_back( true );
    number.push_back( false );
    number.push_back( false );

    number.push_back( false );
    number.push_back( false );
    number.push_back( true );
    number.push_back( true );
    number.push_back( true );
    number.push_back( true );
    number.push_back( true );
    number.push_back( false );
    number.push_back( false );
    number.push_back( false );

    _numbers.push_back( std::pair<QString, std::vector<bool> >( "0", number ) );
    number.clear();

    // 1
    number.push_back( false );
    number.push_back( false );
    number.push_back( true );
    number.push_back( false );
    number.push_back( false );
    number.push_back( false );
    number.push_back( false );
    number.push_back( false );
    number.push_back( true );
    number.push_back( false );

    number.push_back( false );
    number.push_back( true );
    number.push_back( false );
    number.push_back( false );
    number.push_back( false );
    number.push_back( false );
    number.push_back( false );
    number.push_back( false );
    number.push_back( true );
    number.push_back( false );

    number.push_back( true );
    number.push_back( true );
    number.push_back( true );
    number.push_back( true );
    number.push_back( true );
    number.push_back( true );
    number.push_back( true );
    number.push_back( true );
    number.push_back( true );
    number.push_back( false );

    number.push_back( false );
    number.push_back( false );
    number.push_back( false );
    number.push_back( false );
    number.push_back( false );
    number.push_back( false );
    number.push_back( false );
    number.push_back( false );
    number.push_back( true );
    number.push_back( false );

    number.push_back( false );
    number.push_back( false );
    number.push_back( false );
    number.push_back( false );
    number.push_back( false );
    number.push_back( false );
    number.push_back( false );
    number.push_back( false );
    number.push_back( true );
    number.push_back( false );

    _numbers.push_back( std::pair<QString, std::vector<bool> >( "1", number ) );
    number.clear();

    // 2
    number.push_back( false );
    number.push_back( true );
    number.push_back( true );
    number.push_back( false );
    number.push_back( false );
    number.push_back( false );
    number.push_back( false );
    number.push_back( true );
    number.push_back( true );
    number.push_back( false );

    number.push_back( true );
    number.push_back( false );
    number.push_back( false );
    number.push_back( false );
    number.push_back( false );
    number.push_back( false );
    number.push_back( true );
    number.push_back( false );
    number.push_back( true );
    number.push_back( false );

    number.push_back( true );
    number.push_back( false );
    number.push_back( false );
    number.push_back( false );
    number.push_back( false );
    number.push_back( true );
    number.push_back( false );
    number.push_back( false );
    number.push_back( true );
    number.push_back( false );

    number.push_back( true );
    number.push_back( false );
    number.push_back( false );
    number.push_back( false );
    number.push_back( true );
    number.push_back( false );
    number.push_back( false );
    number.push_back( false );
    number.push_back( true );
    number.push_back( false );

    number.push_back( false );
    number.push_back( true );
    number.push_back( true );
    number.push_back( true );
    number.push_back( false );
    number.push_back( false );
    number.push_back( false );
    number.push_back( false );
    number.push_back( true );
    number.push_back( false );

    _numbers.push_back( std::pair<QString, std::vector<bool> >( "2", number ) );
    number.clear();

    // 3
    number.push_back( true );
    number.push_back( false );
    number.push_back( false );
    number.push_back( false );
    number.push_back( false );
    number.push_back( false );
    number.push_back( false );
    number.push_back( true );
    number.push_back( false );
    number.push_back( false );

    number.push_back( true );
    number.push_back( false );
    number.push_back( false );
    number.push_back( false );
    number.push_back( true );
    number.push_back( false );
    number.push_back( false );
    number.push_back( false );
    number.push_back( true );
    number.push_back( false );

    number.push_back( true );
    number.push_back( false );
    number.push_back( false );
    number.push_back( true );
    number.push_back( true );
    number.push_back( false );
    number.push_back( false );
    number.push_back( false );
    number.push_back( true );
    number.push_back( false );

    number.push_back( true );
    number.push_back( false );
    number.push_back( true );
    number.push_back( false );
    number.push_back( true );
    number.push_back( false );
    number.push_back( false );
    number.push_back( false );
    number.push_back( true );
    number.push_back( false );

    number.push_back( true );
    number.push_back( true );
    number.push_back( false );
    number.push_back( false );
    number.push_back( false );
    number.push_back( true );
    number.push_back( true );
    number.push_back( true );
    number.push_back( false );
    number.push_back( false );

    _numbers.push_back( std::pair<QString, std::vector<bool> >( "3", number ) );
    number.clear();

    // 4
    number.push_back( false );
    number.push_back( false );
    number.push_back( false );
    number.push_back( false );
    number.push_back( false );
    number.push_back( true );
    number.push_back( true );
    number.push_back( false );
    number.push_back( false );
    number.push_back( false );

    number.push_back( false );
    number.push_back( false );
    number.push_back( false );
    number.push_back( true );
    number.push_back( true );
    number.push_back( false );
    number.push_back( true );
    number.push_back( false );
    number.push_back( false );
    number.push_back( false );

    number.push_back( false );
    number.push_back( false );
    number.push_back( true );
    number.push_back( false );
    number.push_back( false );
    number.push_back( false );
    number.push_back( true );
    number.push_back( false );
    number.push_back( false );
    number.push_back( false );

    number.push_back( true );
    number.push_back( true );
    number.push_back( true );
    number.push_back( true );
    number.push_back( true );
    number.push_back( true );
    number.push_back( true );
    number.push_back( true );
    number.push_back( true );
    number.push_back( false );

    number.push_back( false );
    number.push_back( false );
    number.push_back( false );
    number.push_back( false );
    number.push_back( false );
    number.push_back( false );
    number.push_back( true );
    number.push_back( false );
    number.push_back( false );
    number.push_back( false );

    _numbers.push_back( std::pair<QString, std::vector<bool> >( "4", number ) );
    number.clear();

    // 5
    number.push_back( true );
    number.push_back( true );
    number.push_back( true );
    number.push_back( true );
    number.push_back( true );
    number.push_back( false );
    number.push_back( false );
    number.push_back( true );
    number.push_back( false );
    number.push_back( false );

    number.push_back( true );
    number.push_back( false );
    number.push_back( false );
    number.push_back( false );
    number.push_back( true );
    number.push_back( false );
    number.push_back( false );
    number.push_back( false );
    number.push_back( true );
    number.push_back( false );

    number.push_back( true );
    number.push_back( false );
    number.push_back( false );
    number.push_back( true );
    number.push_back( false );
    number.push_back( false );
    number.push_back( false );
    number.push_back( false );
    number.push_back( true );
    number.push_back( false );

    number.push_back( true );
    number.push_back( false );
    number.push_back( false );
    number.push_back( true );
    number.push_back( false );
    number.push_back( false );
    number.push_back( false );
    number.push_back( false );
    number.push_back( true );
    number.push_back( false );

    number.push_back( true );
    number.push_back( false );
    number.push_back( false );
    number.push_back( false );
    number.push_back( true );
    number.push_back( true );
    number.push_back( true );
    number.push_back( true );
    number.push_back( false );
    number.push_back( false );

    _numbers.push_back( std::pair<QString, std::vector<bool> >( "5", number ) );
    number.clear();

    // 6
    number.push_back( false );
    number.push_back( true );
    number.push_back( true );
    number.push_back( true );
    number.push_back( true );
    number.push_back( true );
    number.push_back( true );
    number.push_back( true );
    number.push_back( false );
    number.push_back( false );

    number.push_back( true );
    number.push_back( false );
    number.push_back( false );
    number.push_back( false );
    number.push_back( true );
    number.push_back( false );
    number.push_back( false );
    number.push_back( false );
    number.push_back( true );
    number.push_back( false );

    number.push_back( true );
    number.push_back( false );
    number.push_back( false );
    number.push_back( false );
    number.push_back( true );
    number.push_back( false );
    number.push_back( false );
    number.push_back( false );
    number.push_back( true );
    number.push_back( false );

    number.push_back( true );
    number.push_back( false );
    number.push_back( false );
    number.push_back( false );
    number.push_back( true );
    number.push_back( false );
    number.push_back( false );
    number.push_back( false );
    number.push_back( true );
    number.push_back( false );

    number.push_back( false );
    number.push_back( true );
    number.push_back( false );
    number.push_back( false );
    number.push_back( false );
    number.push_back( true );
    number.push_back( true );
    number.push_back( true );
    number.push_back( false );
    number.push_back( false );

    _numbers.push_back( std::pair<QString, std::vector<bool> >( "6", number ) );
    number.clear();

    // 7
    number.push_back( true );
    number.push_back( false );
    number.push_back( false );
    number.push_back( false );
    number.push_back( false );
    number.push_back( false );
    number.push_back( false );
    number.push_back( false );
    number.push_back( false );
    number.push_back( false );

    number.push_back( true );
    number.push_back( false );
    number.push_back( false );
    number.push_back( false );
    number.push_back( false );
    number.push_back( false );
    number.push_back( true );
    number.push_back( true );
    number.push_back( true );
    number.push_back( false );

    number.push_back( true );
    number.push_back( false );
    number.push_back( false );
    number.push_back( false );
    number.push_back( true );
    number.push_back( true );
    number.push_back( false );
    number.push_back( false );
    number.push_back( false );
    number.push_back( false );

    number.push_back( true );
    number.push_back( false );
    number.push_back( true );
    number.push_back( true );
    number.push_back( false );
    number.push_back( false );
    number.push_back( false );
    number.push_back( false );
    number.push_back( false );
    number.push_back( false );

    number.push_back( true );
    number.push_back( true );
    number.push_back( false );
    number.push_back( false );
    number.push_back( false );
    number.push_back( false );
    number.push_back( false );
    number.push_back( false );
    number.push_back( false );
    number.push_back( false );

    _numbers.push_back( std::pair<QString, std::vector<bool> >( "7", number ) );
    number.clear();

    // 8
    number.push_back( false );
    number.push_back( true );
    number.push_back( true );
    number.push_back( true );
    number.push_back( false );
    number.push_back( true );
    number.push_back( true );
    number.push_back( true );
    number.push_back( false );
    number.push_back( false );

    number.push_back( true );
    number.push_back( false );
    number.push_back( false );
    number.push_back( false );
    number.push_back( true );
    number.push_back( false );
    number.push_back( false );
    number.push_back( false );
    number.push_back( true );
    number.push_back( false );

    number.push_back( true );
    number.push_back( false );
    number.push_back( false );
    number.push_back( false );
    number.push_back( true );
    number.push_back( false );
    number.push_back( false );
    number.push_back( false );
    number.push_back( true );
    number.push_back( false );

    number.push_back( true );
    number.push_back( false );
    number.push_back( false );
    number.push_back( false );
    number.push_back( true );
    number.push_back( false );
    number.push_back( false );
    number.push_back( false );
    number.push_back( true );
    number.push_back( false );

    number.push_back( false );
    number.push_back( true );
    number.push_back( true );
    number.push_back( true );
    number.push_back( false );
    number.push_back( true );
    number.push_back( true );
    number.push_back( true );
    number.push_back( false );
    number.push_back( false );

    _numbers.push_back( std::pair<QString, std::vector<bool> >( "8", number ) );
    number.clear();

    // 9
    number.push_back( false );
    number.push_back( true );
    number.push_back( true );
    number.push_back( true );
    number.push_back( false );
    number.push_back( false );
    number.push_back( false );
    number.push_back( true );
    number.push_back( false );
    number.push_back( false );

    number.push_back( true );
    number.push_back( false );
    number.push_back( false );
    number.push_back( false );
    number.push_back( true );
    number.push_back( false );
    number.push_back( false );
    number.push_back( false );
    number.push_back( true );
    number.push_back( false );

    number.push_back( true );
    number.push_back( false );
    number.push_back( false );
    number.push_back( false );
    number.push_back( true );
    number.push_back( false );
    number.push_back( false );
    number.push_back( false );
    number.push_back( true );
    number.push_back( false );

    number.push_back( true );
    number.push_back( false );
    number.push_back( false );
    number.push_back( false );
    number.push_back( true );
    number.push_back( false );
    number.push_back( false );
    number.push_back( false );
    number.push_back( true );
    number.push_back( false );

    number.push_back( false );
    number.push_back( true );
    number.push_back( true );
    number.push_back( true );
    number.push_back( true );
    number.push_back( true );
    number.push_back( true );
    number.push_back( true );
    number.push_back( false );
    number.push_back( false );

    _numbers.push_back( std::pair<QString, std::vector<bool> >( "9", number ) );
    number.clear();
}

QString xNumbers::getString( const std::vector<bool> &number )
{
    for( int i = 0; i < _numbers.size(); i++ )
    {
        if( _numbers[i].second == number )
        {
            return _numbers[i].first;
        }
    }

    return "?";
}
