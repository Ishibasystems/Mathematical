#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int i;
	double test[10] = {71, 97, 84, 96, 83, 82, 65, 90, 98, 72}, heikin = 0.0, min = 100.0, max = 0.0;
	for (i = 0; i < 10; i++) heikin += test[i];
	heikin /= 10;
	for (i = 0; i < 10; i++) if (test[i] > max) max = test[i];
	for (i = 0; i < 10; i++) if (test[i] < min) min = test[i];
	printf("���ϓ_: %f�_\n", heikin);
	printf("�Œ�_: %f�_�A�ō��_: %f�_\n", min, max);
	exit(0);
}