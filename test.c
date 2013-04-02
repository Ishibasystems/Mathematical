#include <stdio.h>
int main(void){ char str[]="38 13 31 18 9 38 13 38 13 31 25 25 15 38 13 31 7 ";
int num, i;
for(i = num = 0; str[i] != '\0'; (str[i++] == ' ') ? num++ : 0);
printf("%d\n",num); return 0; }
