#include <stdio.h>
int cnt = 0;

int binarySearch(int a[], int n, int key) {
	int left = 0, right = n - 1, mid;
	while (left <= right) {
		mid = (left + right) / 2;
		cnt++;
		if (key == a[mid]) return mid;
		if (key > a[mid]) left = mid + 1;
		else right = mid - 1;
	}
	return -1;
}

int main(void) {
	int a[] = { 6, 8, 12, 15, 18, 24, 35, 39, 43, 49 };
	int n = sizeof(a) / sizeof(int);
	int key, index;
	printf("찾을 값 : ");
	scanf_s("%d", &key);
	index = binarySearch(a, n, key);
	if (index >= 0) printf("%d을(를) %d위치에서 %d회 반복하여 찾음\n", key, index, cnt);
	else printf("%d는(은) 없는 자료임\n", key);

	return 0;
}