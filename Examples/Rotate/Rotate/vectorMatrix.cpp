//
//  vectorMatrix.cpp
//  Matrix2
//
//  Created by 1J519-00 on 2015. 10. 28..
//  Copyright © 2015년 1J519-00. All rights reserved.
//

#include <stdio.h>
#include <math.h>
#include "vectorMatrix.h"

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
    tempVect = matrixGetRow(m, 0);
    vec.e[0] = dotProduct(tempVect, v);
    
    // the second row
    tempVect = matrixGetRow(m, 1);
    vec.e[1] = dotProduct(tempVect, v);
    
    // the third row
    tempVect = matrixGetRow(m, 2);
    vec.e[2] = dotProduct(tempVect, v);
    
    return vec;
}

mat33 matrixTranspose(mat33 m) {
    mat33 rMat;
    for (int i=0; i<3; i++) {
        for (int j=0; j<3; j++) {
            rMat.e[i][j] = m.e[j][i];
        }
    }
    return rMat;
}

vec3f matrixGetRow(mat33 m, int i) {
    vec3f resVec;
    resVec.e[0] = m.e[i][0];
    resVec.e[1] = m.e[i][1];
    resVec.e[2] = m.e[i][2];
    return resVec;
}

vec3f matrixGetCol(mat33 m, int i) {
    vec3f resVec;
    resVec.e[0] = m.e[0][i];
    resVec.e[1] = m.e[1][i];
    resVec.e[2] = m.e[2][i];
    return resVec;
}

mat33 matrixMult(mat33 m1, mat33 m2) {
    mat33 resMat;
    
    for (int i=0; i<3; i++) {
        for (int j=0; j<3; j++) {
            resMat.e[i][j] = dotProduct(
                                        matrixGetRow(m1, i),
                                        matrixGetCol(m2, j));
        }
    }
    
    return resMat;
}

vec3f rotate(int axis, float angleDegree, vec3f v) {
    vec3f res;
    float angleRadian = 3.141592*angleDegree/180.0;
    mat33 R;
    float c, s;
    c = cos(angleRadian);
    s = sin(angleRadian);
    
    switch (axis) {
        case 0: // x axis
            setMatrix(R, 1, 0, 0, 0, c, -s, 0, s, c);
            break;
        case 1: // y axis
            setMatrix(R, c, 0, s, 0, 1, 0, -s, 0, c);
            break;
        case 2: // z axis
            setMatrix(R, c, -s, 0, s,  c, 0, 0,  0, 1);
            break;
        default:
            break;
    }
    res = matrixVectorMult(R, v);
    return res;
}

void printMatrix(mat33 m) {
    for(int i=0;i<3;i++) {
        for(int j=0;j<3; j++) {
            printf(" %4.2f ", m.e[i][j]);
        }   printf("\n");
    }
}