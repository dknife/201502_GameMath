#include <stdio.h>
#include <math.h>
#include "vectorMatrix.h"

int main(int argc, char **argv) {
    vec3f v;
    v.e[0] = 1; v.e[1] = 0; v.e[2] = 0; // x axis
    
    vec3f r = rotate(1, 45, v);
    
    printf("rotated to: (%f, %f, %f)\n",
           r.e[0], r.e[1], r.e[2]);
    
    
}





