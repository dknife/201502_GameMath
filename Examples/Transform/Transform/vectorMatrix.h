//
//  vectorMatrix.h
//  Matrix2
//
//  Created by 1J519-00 on 2015. 10. 28..
//  Copyright © 2015년 1J519-00. All rights reserved.
//

#ifndef vectorMatrix2015YMKANG_HHH_h
#define vectorMatrix2015YMKANG_HHH_h

// user defined data type: vec3f
struct vec3f {
    float e[3];
};

// user defined data type: mat33
struct mat33 {
    float e[3][3];
};

// user defined data type: transform (rigid body)
struct transform {
    mat33 R;
    vec3f d;
};

float length(vec3f v);
vec3f normalize(vec3f v);
float dotProduct(vec3f a, vec3f b);
vec3f crossProduct(vec3f a, vec3f b);

void setMatrix(mat33 &m,
               float a00, float a01, float a02,
               float a10, float a11, float a12,
               float a20, float a21, float a22);

void setMatrix(mat33 &m, vec3f u, vec3f v, vec3f w) ;

vec3f matrixGetRow(mat33 m, int i);
vec3f matrixGetCol(mat33 m, int i);


vec3f matrixVectorMult(mat33 m, vec3f v);
mat33 matrixMult(mat33 m1, mat33 m2);
mat33 matrixTranspose(mat33 m);

vec3f rotate(int axis, float angleDegree, vec3f v);

void  initialzeTransform(transform &trans);
void  translate(transform &trans, float dx, float dy, float dz);
vec3f apply(transform trans, vec3f p);



void printMatrix(mat33 m);

#endif /* vectorMatrix_h */
