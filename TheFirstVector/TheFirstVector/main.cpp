#include <stdio.h>
#include <math.h>

// user defined data type: vec3f
struct vec3f {
	float x;
	float y;
	float z;
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

int main(int argc, char **argv) {
	vec3f a;
	a.x = 1; a.y = 2; a.z = 3;
	float len = length(a);
	printf("len = %f\n", len);
	vec3f u = normalize(a);
	len = length(u);
	printf("len = %f\n", len);

}