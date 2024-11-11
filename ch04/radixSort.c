#include <stdio.h>
#include <stdlib.h>

void radixSort(int a[], int n) {
	int digit_cnt[10] = {0,};
	int* b = (int*)malloc(sizeof(int) * n);
	int digit = 1, max = a[0], i;

	for (i = 1; i < n; i++) if (max < a[i]) max = a[i];

	while (digit <= max) { // max의 자리수만큼 반복
		// 개수(자리수 별)
		for (i = 0; i < n; i++) {
			digit_cnt[a[i] / digit % 10]++;
		}
		// 누적(앞의 값과 더하기)
		for (i = 1; i < 10; i++) {
			digit_cnt[i] += digit_cnt[i - 1];
		}
		// 분배(a->b)
		for (i = n - 1; i >= 0; i--) {
			b[--digit_cnt[a[i] / digit % 10]] = a[i];
		}
		// 회수(b->a)
		for (i = 0; i < n; i++) {
			a[i] = b[i];
		}
		// 초기화(b)
		for (i = 0; i < 10; i++) {
			digit_cnt[i] = 0;
		}
		// 중간 출력
		for (i = 0; i < n; i++) {
			printf("%6d", a[i]);
		}
		printf("\n");
		digit *= 10; // 다음 자릿수
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