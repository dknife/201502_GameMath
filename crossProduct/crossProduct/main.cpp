#include <stdio.h>
#include <math.h>

// user defined data type: vec3f
struct vec3f {
	float x;	float y;	float z;
};
float length(vec3f v) {
	return sqrt( v.x*v.x + v.y*v.y + v.z*v.z);
}
vec3f normalize(vec3f v) {
	vec3f u;
	float len = length(v);
	u.x = v.x / len;
	u.y = v.y / len;
	u.z = v.z / len;
	return u;
}
float dotProduct(vec3f a, vec3f b) {
	return a.x*b.x + a.y*b.y + a.z*b.z; 
}
vec3f crossProduct(vec3f a, vec3f b) {
	vec3f c;
	c.x = a.y*b.z - a.z*b.y;
	c.y = a.z*b.x - a.x*b.z;
	c.z = a.x*b.y - a.y*b.x;
	return c;
}

int main(int argc, char **argv) {
	vec3f p0, p1, p2;
	p0.x = 0.0; p0.y = 0.0; p0.z = 0.0;
	p1.x = 1.0; p1.y = 0.0; p1.z = 0.0;
	p2.x = 0.0; p2.y = 1.0; p2.z = 0.0;

	// 삼각형 면적 구하기
	vec3f u, v;
	u.x = p1.x - p0.x; u.y = p1.y - p0.y; u.z = p1.z - p0.z;
	v.x = p2.x - p0.x; v.y = p2.y - p0.y; v.z = p2.z - p0.z;

	vec3f c = crossProduct(u, v);
	float len = length(c);
	printf("Triangle Area = %f\n", len/2.0);

	return 0;
}