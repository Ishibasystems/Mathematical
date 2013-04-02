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
	printf("平均点: %f点\n", heikin);
	printf("最低点: %f点、最高点: %f点\n", min, max);
	exit(0);
}