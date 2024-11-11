#include <stdio.h>
void shellSort(int a[], int n) {
	int i, j, key, t;
	for (t = n / 2; t >= 1; t /= 2) {
		for (i = t; i < n; i++) {
			key = a[i];
			for (j = i - t; j >= 0; j-=t) {
				if (a[j] <= key) break;
				else a[j + t] = a[j];
			}
			a[j + t] = key;
		}
	}
}

int main() {
	int a[] = { 7, 12, 6, 11, 3, 8, 5, 2 };
	int n = sizeof(a) / sizeof(int);

	shellSort(a, n);

	for (int i = 0; i < n; i++) {
		printf("%5d ", a[i]);
	}
	return 0;
}