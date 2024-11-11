#include <stdio.h>
void quickSort(int a[], int left, int right) {
	int i = left, j = right, pivot=a[left], temp;
	if (left < right) {
		while (i < j) { // Àç¹èÄ¡
			while (i < right && a[i] <= pivot) i++;
			while (j > left && a[j] >= pivot) j--;
			if (i < j) {temp = a[i]; a[i] = a[j]; a[j] = temp;}
		}
		a[left] = a[j];
		a[j] = pivot;

		quickSort(a, left, j - 1);
		quickSort(a, j + 1, right);
	}
}

int main() {
	int a[] = { 7,17,1,36,2,21,45,30,77,5,52 };
	int n = sizeof(a) / sizeof(int);
	quickSort(a, 0, n - 1);
	for (int i = 0; i < n; i++) {
		printf("%5d", a[i]);
	}
	return 0;
}