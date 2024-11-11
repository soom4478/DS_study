#include <stdio.h>

void heapSort(int a[], int n) {
	int i, parent, child, value, size = n;

	// �ִ� �� ����
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
	// ����(�ִ� �̵� �� �ִ��� �籸��)
	while (n > 1) {
		value = a[n];	// value���� �� �ڷ� �̵�
		a[n--] = a[1];	// a[n]�� root���� �ְ� n--
		parent = 1;
		while ((child = parent * 2) <= n) { // ���� ����
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