#include <iostream>
#include "module.h"

int main() {
	Vector3D M1(2, 1, 4), M2(6, 10, -9, -4, -3, 0), M3;
	M3 = M1 + M2;
	printf("M3 length: %.2g\n", M3.getLength());
	printf("M1 * M3 = %.2g\n", M1 * M3);
	return 0;
}
