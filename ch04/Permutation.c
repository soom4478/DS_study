#include <stdio.h>
#define R 3
int b[R], cnt = 0;

void exchange(int* a, int* b) {
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

void printPer(void) {
	for (int i = 0; i < R; i++) printf("%5d", b[i]);
	printf("\n");
	cnt++;
}

void Permutation(int a[], int n, int r) {
	int i;

	if (r == R) printPer();
	else {
		for (i = r; i < n; i++) {
			exchange(&a[r], &a[i]); // exchange(a+0, a+i)와 동일
			b[r] = a[r];
			Permutation(a, n, r + 1);
			exchange(a + r, a + i);
		}
	}
}

int main(void) {
	int a[] = { 1, 2, 3, 4, 5 };
	int n = sizeof(a) / sizeof(int);

	Permutation(a, n, 0);

	printf("순열 개수: %d\n", cnt);
	return 0;
}