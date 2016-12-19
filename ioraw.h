#ifndef IORAW_H
#define IORAW_H

#include <iostream>
#include <sstream>
#include <fstream>
#include <QFile>

class IORaw
{
public:
    IORaw();
    static void csv_to_data(std::vector<std::vector <std::string> >& _datas, std::stringstream& _src);
};

#endif // IORAW_H
