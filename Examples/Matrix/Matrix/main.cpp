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

// user defined data type: mat33
struct mat33 {
    float e[3][3];
};

void setMatrix(mat33 &m,
               float a00, float a01, float a02,
               float a10, float a11, float a12,
               float a20, float a21, float a22) {
    m.e[0][0] = a00;
    m.e[0][1] = a01;
    m.e[0][2] = a02;
    m.e[1][0] = a10;
    m.e[1][1] = a11;
    m.e[1][2] = a12;
    m.e[2][0] = a20;
    m.e[2][1] = a21;
    m.e[2][2] = a22;
}

void setMatrix(mat33 &m, vec3f u, vec3f v, vec3f w) {
    // u : a00, a10, a20
    // v : a01, a11, a21
    // w : a02, a12, a22
    for(int i=0; i<3; i++) {
        m.e[i][0] = u.e[i];
        m.e[i][1] = v.e[i];
        m.e[i][2] = w.e[i];
    }
}

vec3f matrixVectorMult(mat33 m, vec3f v) {
    vec3f vec;
    vec3f tempVect;
    // the first row
    tempVect.e[0] = m.e[0][0];
    tempVect.e[1] = m.e[0][1];
    tempVect.e[2] = m.e[0][2];
    
    vec.e[0] = dotProduct(tempVect, v);
    
    // the second row
    tempVect.e[0] = m.e[1][0];
    tempVect.e[1] = m.e[1][1];
    tempVect.e[2] = m.e[1][2];
    
    vec.e[1] = dotProduct(tempVect, v);
    
    // the third row
    tempVect.e[0] = m.e[2][0];
    tempVect.e[1] = m.e[2][1];
    tempVect.e[2] = m.e[2][2];
    
    vec.e[2] = dotProduct(tempVect, v);
    
    return vec;
}

void printMatrix(mat33 m) {
    for(int i=0;i<3;i++) {
        for(int j=0;j<3; j++) {
            printf(" %4.2f ", m.e[i][j]);
        }   printf("\n");
    }
}


int main(int argc, char **argv) {
    mat33 myMat;
    setMatrix(myMat, 1, 2, 3, 1, 3, 4, 1, 4, 5);
    printMatrix(myMat);
    
    vec3f v;
    v.e[0] = 1; v.e[1] = 0; v.e[2] = 0; // x axis
    
    vec3f res = matrixVectorMult(myMat, v);
    printf("%f %f %f\n", res.e[0], res.e[1], res.e[2]);
}





