#include <stdio.h>
#include <stdlib.h>

void radixSort(int a[], int n) {
	int digit_cnt[10] = {0,};
	int* b = (int*)malloc(sizeof(int) * n);
	int digit = 1, max = a[0], i;

	for (i = 1; i < n; i++) if (max < a[i]) max = a[i];

	while (digit <= max) { // max�� �ڸ�����ŭ �ݺ�
		// ����(�ڸ��� ��)
		for (i = 0; i < n; i++) {
			digit_cnt[a[i] / digit % 10]++;
		}
		// ����(���� ���� ���ϱ�)
		for (i = 1; i < 10; i++) {
			digit_cnt[i] += digit_cnt[i - 1];
		}
		// �й�(a->b)
		for (i = n - 1; i >= 0; i--) {
			b[--digit_cnt[a[i] / digit % 10]] = a[i];
		}
		// ȸ��(b->a)
		for (i = 0; i < n; i++) {
			a[i] = b[i];
		}
		// �ʱ�ȭ(b)
		for (i = 0; i < 10; i++) {
			digit_cnt[i] = 0;
		}
		// �߰� ���
		for (i = 0; i < n; i++) {
			printf("%6d", a[i]);
		}
		printf("\n");
		digit *= 10; // ���� �ڸ���
	}
}

int main(void) {
	int a[] = {3, 303, 10, 512, 7215, 717, 318, 29, 148, 50, 1283, 99};
	int n = sizeof(a) / sizeof(int);

	radixSort(a, n);

	for (int i = 0; i < n; i++) {
		printf("%5d", a[i]);
	}
	return 0;
}