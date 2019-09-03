#include <stdio.h> 
#include <string.h>
#include <stdlib.h>
#define LENGTH 250000

struct gauss {
		// a + bi
		int a;
		int b;
};

// Representative in the 1st quadrant
// under y = x (a <= b) not counting conjugates
void gaussian_factor(int rational_prime, struct gauss
				*gauss_prime, int *squares) {
		int a = 1;
		int b = 1;
		while (squares[a] + squares[b] != rational_prime) {
				if (a == b) {
						b++;
						a = 1;
				} else {
						a++;
				}
		}
		gauss_prime->a = a;
		gauss_prime->b = b;
}

void erasothenes_sieve(int *sieve, int *square) { 
		// sieve[i] == 0 -> i prime
		// square[i] == i^2
		square[0] = 0;
		square[1] = 1; 
		for (int i = 2; i < 500; i++) {
				int j = i * i;
				square[i] = j;
				if (sieve[i] == 0) {
						while (j < LENGTH) {
								sieve[j] = 1;
								j += i;
						}
				}
		}

		struct gauss *gaussian_int = malloc(sizeof(struct gauss));
		for (int i = 2; i < LENGTH; i++) { 
				if (sieve[i] == 0) {
						if (i % 4 == 3) {
								printf("%d 0\n", i);
						} else {
								gaussian_factor(i, gaussian_int, square);
								printf("%d %d\n", gaussian_int->a,
												gaussian_int->b); 
						}
				}
		}
		free(gaussian_int);
}

int main() {
		int *sieve, *square;
		if (!(sieve = calloc(LENGTH, sizeof(int)))) {
				return EXIT_FAILURE;
		}

		if (!(square = malloc(sizeof(int) * 500))) {
				return EXIT_FAILURE;
		}

		erasothenes_sieve(sieve, square); 
		free(sieve);
		free(square); 
}
