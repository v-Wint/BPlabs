#include "module.h"

Vector3D Vector3D::operator-() {
	x = -x;
	y = -y;
	z = -z;
	return *this;
}
const Vector3D Vector3D::operator+(const Vector3D obj) {
	Vector3D tmp;
	tmp.x = x + obj.x;
	tmp.y = y + obj.y;
	tmp.z = z + obj.z;
	return tmp;
}
const Vector3D operator+(const double a, const Vector3D b) {
	Vector3D tmp;
	tmp.x = a + b.x;
	tmp.y = a + b.y;
	tmp.z = a + b.z;
	return tmp;
}
const Vector3D operator+(const Vector3D a, const double b) {
	Vector3D tmp;
	tmp.x = a.x + b;
	tmp.y = a.y + b;
	tmp.z = a.z + b;
	return tmp;
}
double Vector3D::operator*(const Vector3D obj) {
	return x * obj.x + y * obj.y + z * obj.z;
}
const Vector3D operator*(const double a, const Vector3D b) {
	Vector3D tmp;
	tmp.x = a * b.x;
	tmp.y = a * b.y;
	tmp.z = a * b.z;
	return tmp;
}
const Vector3D operator*(const Vector3D a, const double b) {
	Vector3D tmp;
	tmp.x = a.x * b;
	tmp.y = a.y * b;
	tmp.z = a.z * b;
	return tmp;
}
