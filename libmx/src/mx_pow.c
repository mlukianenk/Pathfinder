#include "libmx.h"

double mx_pow(double n, unsigned int pow) {
	if (n == 0)
		return 0;
	else if (n == 1)
        return n;
	else
		return (n*mx_pow(n, pow-1));
}
