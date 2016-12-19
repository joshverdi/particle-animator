#ifndef UTILS_H
#define UTILS_H

#include <string>
#include <vector>
#include "CGLA/Vec3f.h"

class Utils
{
public:
    Utils();
    static CGLA::Vec3f                          to_vec3f(float _x, float _y, float _z);
    static CGLA::Vec3f                          to_vec3f(std::vector<float>& _vecf);
    static float                                stdstr_to_float(std::string& _src);
    static std::vector< std::vector<float> >    raw_cast(std::vector< std::vector<std::string> > &_vecs_str);
};

#endif // UTILS_H
