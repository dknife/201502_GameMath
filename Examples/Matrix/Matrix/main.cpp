#include <stdio.h>
#include <math.h>

// user defined data type: vec3f
struct vec3f {
    float e[3];
};

float length(vec3f v) {
    float val = 0.0;
    for(int i=0;i<3;i++) {
        val += v.e[i]*v.e[i];
    }
    return sqrt(val);
}

vec3f normalize(vec3f v) {
    vec3f u;
    float len = length(v);
    
    for(int i=0;i<3;i++) u.e[i] = v.e[i] / len;

    return u;
}

float dotProduct(vec3f a, vec3f b) {
    return a.e[0]*b.e[0] + a.e[1]*b.e[1] + a.e[2]*b.e[2];
}

vec3f crossProduct(vec3f a, vec3f b) {
    vec3f c;
    c.e[0] = a.e[1]*b.e[2] - a.e[2]*b.e[1];
    c.e[1] = a.e[2]*b.e[0] - a.e[0]*b.e[2];
    c.e[2] = a.e[0]*b.e[1] - a.e[1]*b.e[0];
    return c;
}

int main(int argc, char **argv) {

}