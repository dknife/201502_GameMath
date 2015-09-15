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
float dotProduct(vec3f a, vec3f b) {
	return a.x*b.x + a.y*b.y + a.z*b.z; 
}

int main(int argc, char **argv) {
	vec3f a, b;
	a.x = 3; a.y = 2; a.z = 0;
	b.x = 4; b.y = 1; b.z = 0;

	float angle = 0;
	float ab = dotProduct(a, b);
	float aLen = length(a);
	float bLen = length(b);
	float cosTheta = ab/(aLen*bLen);
	angle = 180.0*acos(cosTheta)/3.141592;  // radian to degree

	printf("a(%f,%f,%f)\nb(%f,%f,%f)\nªÁ¿’∞¢=%fµµ\n", 
		a.x,a.y,a.z, b.x,b.y,b.z, angle);

}