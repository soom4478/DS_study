#include <stdio.h>
#define R 3
int b[R], cnt = 0;

void exchange(int* a, int* b) {
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

void printRePer(void) {
	for (int i = 0; i < R; i++) printf("%5d", b[i]);
	printf("\n");
	cnt++;
}

void RePermutation(int a[], int n, int r) {
	int i;

	if (r == R) printRePer();
	else {
		for (i = 0; i < n; i++) {
			exchange(&a[0], &a[i]); // exchange(a+0, a+i)와 동일
			b[r] = a[0];
			RePermutation(a, n, r + 1);
			exchange(a + 0, a + i);
		}
	}
}

int main(void) {
	int a[] = { 1, 2, 3, 4, 5 };
	int n = sizeof(a) / sizeof(int);

	RePermutation(a, n, 0);

	printf("중복순열 개수: %d\n", cnt);
	return 0;
}