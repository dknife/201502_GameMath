#include <stdio.h>
#include <math.h>
#include "vectorMatrix.hpp"

int main(int argc, char **argv) {
    vec3f v;
    transform trans;
    v.e[0] = 0; v.e[1] = 0; v.e[2] = 0; // x axis
    
    initialzeTransform(trans);
    
    translate(trans, 1,0,0);
    rotate(trans, 2, 90.0);
    translate(trans, -1,0,0);
    
    
    vec3f r = apply(trans, v);
    
    
    printf("transformed to: (%f, %f, %f)\n",
           r.e[0], r.e[1], r.e[2]);
    
}