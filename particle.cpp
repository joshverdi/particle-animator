#include <iostream>
#include "particle.h"
#include "utils.h"

Particle::Particle():start(0.0, 0.0, 0.0),end(0.0, 0.0, 0.0),age(0),agemax(100)
{
}

Particle::Particle(CGLA::Vec3f _start, CGLA::Vec3f _end):start(_start),end(_end),age(0),agemax(100)
{
}

Particle::Particle(std::vector<float> _vec_start, std::vector<float> _vec_end):age(0),agemax(100)
{
    start = Utils::to_vec3f(_vec_start);
    end   = Utils::to_vec3f(_vec_end);
}

Particle::Particle(std::vector<float> _vecf):age(0),agemax(100)
{
    end = start = Utils::to_vec3f(_vecf);
}

void Particle::setagemax(int _max)
{
    if (_max == 0)
    {
        agemax = 1;
        std::cout << std::endl << "WARNING: Cannot set maximum age to 0!";
    }
    else
        agemax = _max;
}

CGLA::Vec3f Particle::linear_interpol(int _age)
{
    CGLA::Vec3f value(start);
    age = _age;
    value[0] += (end[0] - start[0])*_age/agemax;
    value[1] += (end[1] - start[1])*_age/agemax;
    value[2] += (end[2] - start[2])*_age/agemax;
    return value;
}

CGLA::Vec3f Particle::current_state()
{
    CGLA::Vec3f value(start);
    value[0] += (end[0] - start[0])*age/agemax;
    value[1] += (end[1] - start[1])*age/agemax;
    value[2] += (end[2] - start[2])*age/agemax;
    return value;
}
