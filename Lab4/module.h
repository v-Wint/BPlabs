#include "math.h"

class Vector3D {
	double x, y, z;
public:
	Vector3D() : x(0.0), y(0.0), z(0.0) {};
	Vector3D(double x, double y, double z) : x(x), y(y), z(z) {};
	Vector3D(double x1, double x2, double y1, double y2, double z1, double z2) : x(x2 - x1), y(y2 - y1), z(z2 - z1) {};
	~Vector3D() {};

	double getX() { return x; };
	double getY() { return y; };
	double getZ() { return z; };

	double getLength() { return sqrt(x * x + y * y + z * z); };

	Vector3D operator-();												//opposite vector

	const Vector3D operator+(const Vector3D obj);						//vector sum
	const friend Vector3D operator+(const double a, const Vector3D b);	//num-vector sum
	const friend Vector3D operator+(const Vector3D a, const double b);	//vector-num sum

	double operator*(const Vector3D obj);								//dot product 

	const friend Vector3D operator*(const double a, const Vector3D b);	//num-vector product
	const friend Vector3D operator*(const Vector3D a, const double b);	//vector-num product
};
