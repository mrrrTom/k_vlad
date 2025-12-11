#include <stdio.h>
#include <cstdlib>

int main() {
	unsigned long long left, right;
	if (scanf("%llu %llu", &left, &right) != 2) {
		printf("Bad input!\n");
		exit(-1);
	}

	int rem = left % right;
	while (rem != 0) {
		int dev = left / right;
		printf("%llu ", dev);
		int tmp = left - (dev * right);
		left = right;
		right = tmp;
		rem = left % right;
	}
	
	printf("%llu", (left / right));
	return 0;
}
