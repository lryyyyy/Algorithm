#include <stdio.h>
#include <stdlib.h>

double sqrt(double N) {
	if (N < 0) {
		return -1;
	} else if (N == 0) {
		return 0;
	} else {
		double err = 1e-15;
		double xn = N;
		while ((N - xn*xn) > err || (xn*xn - N) > err) {
			xn = (xn + N/xn) / 2.0;
		}
		return xn;
	}
}

int main() {
	double N;
	scanf("%lf",&N);
	printf("%lf\n",sqrt(N));
	return 0;
}
