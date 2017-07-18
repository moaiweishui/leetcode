#include <stdio.h>

void main()
{
	int a = 1;
	int b = 4;
	int c = a ^ b;
	int d = 1;
	int cnt = 0;
	while (c)
	{
		cnt += c & d;
		c = c >> 1;
	};
	printf("%d", cnt);
}
