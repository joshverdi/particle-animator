#include "ioraw.h"

#include <string>
#include <vector>
#include <boost/algorithm/string.hpp>

IORaw::IORaw()
{

}

void IORaw::csv_to_data(std::vector<std::vector <std::string> >& _datas, std::stringstream& _src)
{
    std::vector<std::string> vec_line, vec_strcell;
    std::string line_tmp;
    while (std::getline(_src, line_tmp))
        vec_line.push_back(line_tmp);
    for (std::vector<std::string>::iterator iter = vec_line.begin(); iter!=vec_line.end(); iter++)
    {
        vec_strcell.clear();
        boost::split(vec_strcell, (*iter), boost::is_any_of(","));
        if (!vec_strcell.empty())
        {
            while (vec_strcell.back().empty()==true)
            {
                vec_strcell.pop_back();
                if (vec_strcell.empty()==true)
                    break;
            }
            _datas.push_back(vec_strcell);
        }
    }
}

