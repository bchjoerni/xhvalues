#ifndef XNUMBERS_H
#define XNUMBERS_H

#include <QString>
#include <vector>

class xNumbers
{
public:
    xNumbers();
    QString getString( const std::vector<bool>& number );

private:
    std::vector<std::pair<QString, std::vector<bool> > > _numbers;
};

#endif // XNUMBERS_H
