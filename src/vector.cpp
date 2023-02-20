#include <headers/vector.hpp>
#include <cmath>

vec::vec()
{

}
vec::vec(double xset,double yset,double zset)
{
    x = xset;
    y = yset;
    z = zset;
}

vec::~vec()
{}

double vec::Len()
{
    return sqrt(x*x+y*y+z*z);
}

double vec::Len2()
{
    return (x*x+y*y+z*z);
}

void vec::VZero()
{
    x = 0.0;
    y = 0.0;
    z = 0.0;
}

void vec::VNorm()
{
    double L;
    L = sqrt(x*x+y*y+z*z);
    x = x / L;
    y = y / L;
    z = z / L;
}

double vec::VSumAb()
{
    return fabs(x)+fabs(y)+fabs(z);
}

void vec::VSet(double xset,double yset,double zset)
{
    x = xset;
    y = yset;
    z = zset;
}
    
vec vec::operator+ (const vec& v)
{
    vec temp;
    temp.x = x + v.x;
    temp.y = y + v.y;
    temp.z = z + v.z;
    return temp;
}
vec vec::operator- (const vec& v)
{
    vec temp;
    temp.x = x - v.x;
    temp.y = y - v.y;
    temp.z = z - v.z;
    return temp;
}
vec vec::operator* (const vec& v)
{
    vec temp;
    temp.x = y * v.z - z * v.y;
    temp.y = z * v.x - x * v.z;
    temp.z = x * v.y - y * v.x;
    return temp;
}

vec vec::operator* (const double& v)
{
    vec temp;
    temp.x = x * v;
    temp.y = y * v;
    temp.z = z * v;
    return temp;
}