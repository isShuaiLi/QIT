#ifndef SRC_HEADERS_TRANSDYN_HPP_
#define SRC_HEADERS_TRANSDYN_HPP_

#include <headers/vector.hpp>
void transdyn();

void LK4();

void CalcForce(vec* at,vec rt,vec vt,double t);
bool IsOut();
#endif