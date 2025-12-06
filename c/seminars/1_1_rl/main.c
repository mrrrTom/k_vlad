#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>

#define true 1

unsigned long long get_neg_mask() {
	unsigned long long mask = 1;
	mask = mask << ((sizeof(unsigned long long) * 8) - 1);
	return mask;
};

unsigned long long is_negative(unsigned long long x) {
	unsigned long long neg_mask = get_neg_mask();
	return (neg_mask & x);
};

unsigned long long neg(unsigned long long x) {
	unsigned long long res = x - 1;
	res = ~res;
	return res;
};

unsigned long long gcd(unsigned long long x, unsigned long long y) {
	unsigned long long left = y > x ? y : x;
	unsigned long long right = y > x ? x : y;

	if (right <= 0) {
		printf("Zero dev!\n");
		exit(-1);
	}

	assert (right > 0);
	unsigned long long q;
	while (true)
	{
		q = left % right;
		if (q == 0) return right;
		left = right;
		right = q;
	}
};

unsigned long long correct_sign(unsigned long long x) {
	if (is_negative(x)) {
		return (neg(x));
	}
	else {
		return x;
	}
};

int main() {
	unsigned long long x = 0, y = 0, g;
	int input_res_count;
	if ((input_res_count = scanf("%llu %llu", &x, &y)) != 2) {
		printf("Bad input, bye!\n");
		exit(-1);
	}

	assert(input_res_count == 2);

	g = gcd(correct_sign(x), correct_sign(y));
	printf("%llu\n", g);
	return 0;
}
