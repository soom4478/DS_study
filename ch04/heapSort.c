#include <stdio.h>

void heapSort(int a[], int n) {
	int i, parent, child, value, size = n;

	// 최대 힙 구성
	for (i = n / 2; i >= 1; i--) {
		value = a[i];
		parent = i;
		while ((child = parent * 2) <= n) {
			if (child + 1 <= n && a[child + 1] > a[child]) child++;
			if (value < a[child]) {
				a[parent] = a[child];
				parent = child;
			}
			else break;
		} //while
		a[parent] = value;
	} //for
	// 정렬(최댓값 이동 및 최대힙 재구성)
	while (n > 1) {
		value = a[n];	// value값을 맨 뒤로 이동
		a[n--] = a[1];	// a[n]에 root값을 넣고 n--
		parent = 1;
		while ((child = parent * 2) <= n) { // 위와 동일
			if (child + 1 <= n && a[child + 1] > a[child]) child++;
			if (value < a[child]) {
				a[parent] = a[child];
				parent = child;
			}
			else break;
		} //while
		a[parent] = value;
		for (i = 1; i <= size; i++)
			printf("%5d", a[i]);
		printf("\n");
	}
}

int main() {
	int a[] = { 0, 21, 17, 12, 15, 11, 1, 9, 3, 21, 25 };
	int n = sizeof(a) / sizeof(int);
	heapSort(a, n-1);
	return 0;
}