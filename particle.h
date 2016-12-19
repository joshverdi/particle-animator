#ifndef PARTICLE_H
#define PARTICLE_H

#include <vector>
#include "CGLA/Vec3f.h"

class Particle
{
    CGLA::Vec3f start, end;
    int age, agemax;
public:
    Particle();
    Particle(CGLA::Vec3f _start, CGLA::Vec3f _end);
    Particle(std::vector<float> _vec_start, std::vector<float> _vec_end);
    Particle(std::vector<float> _vecf);
    void        setagemax(int _max);
    void        setage(int _age){age>=0&&age<agemax?age=_age:age=0;}
    CGLA::Vec3f linear_interpol(int _age);
    CGLA::Vec3f current_state();
    void        age_incr(){age!=agemax?age++:age=0;}
    void        age_decr(){age!=0?age--:age=agemax;}
    void        reset(){age=0;};
};

#endif // PARTICLE_H
