#include "utils.h"

#include <iostream>
#include <boost/lexical_cast.hpp>

Utils::Utils()
{

}

CGLA::Vec3f Utils::to_vec3f(float _x, float _y, float _z)
{
    return CGLA::Vec3f(_x, _y, _z);
}

CGLA::Vec3f Utils::to_vec3f(std::vector<float>& _vecf)
{
    CGLA::Vec3f value(0.0, 0.0, 0.0);
    if (_vecf.size()>=3)
    {
        value.set(_vecf[0], _vecf[1], _vecf[2]);
    }
    return value;
}

float Utils::stdstr_to_float(std::string& _src)
{
    float value;
    try
    {
        value = boost::lexical_cast<float>(_src);
    }
    catch(boost::bad_lexical_cast const&)
    {
        std::cout<<std::endl<<"Boost Lexical Cast Exception";
        return 0;
    }
    return value;
}

std::vector< std::vector<float> > Utils::raw_cast(std::vector< std::vector<std::string> > &_vecs_str)
{
    std::vector< std::vector<float> > value;
    std::vector<float> vec_tmp;
    std::vector<std::string> vec_str;
    for (std::vector< std::vector<std::string> >::iterator iter = _vecs_str.begin(); iter != _vecs_str.end(); iter++)
    {
        vec_str = *iter;
        vec_tmp.clear();
        for (std::vector<std::string>::iterator jter = vec_str.begin(); jter != vec_str.end(); jter++)
        {
            vec_tmp.push_back(stdstr_to_float(*jter));
        }
        value.push_back(vec_tmp);
    }
    return value;
}
