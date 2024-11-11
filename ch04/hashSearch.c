#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define LEN 21
#define SIZE 30

int main(void) {
	char fruit[LEN];
	char fList[SIZE][LEN];
	char overflowArea[10][LEN];
	char next;
	int fInt = 0, cnt = 0, i = 0, index = 0;

	//�ؽ� ���̺�(��Ŷ) �ʱ�ȭ
	for (; i < SIZE; i++) strcpy_s(fList[i], LEN, "");
	//���� �����÷ο� ���� �ʱ�ȭ
	for (i = 0; i < 10; i++) strcpy_s(overflowArea[i], LEN, "");

	//�����Լ�(������ ������ ��Ű�� ����)�� ����Ͽ� �ؽ����̺� ���ϸ� ����
	do {
		printf("���� ���ϸ�(20���� �̳�): ");
		gets_s(fruit, LEN);

		i = 0;
		while (*(fruit + i)) fInt += (int)*(fruit + i++);

		if (strcmp(fList[fInt % SIZE], "")) {
			printf("%dȸ �浹 �߻�!!\n", ++cnt);
			strcpy_s(overflowArea[index++], LEN, fruit);
		}
		else strcpy_s(fList[fInt % SIZE], LEN, fruit);

		fInt = 0;
		printf("��� �Է�(y/n): ");
		scanf_s("%c", &next, 1);
		getchar();

	} while (next == 'y' || next == 'Y');

	printf("���� ����\n");
	for (i = 0; i < SIZE; i++) {
		printf("�ε��� %d: %s\n", i, fList[i]);
	}

	printf("\n\n���� �����÷ο� ����\n");
	for (i = 0; i < 10; i++) {
		printf("�ε��� %d: %s\n", i, overflowArea[i]);
	}

	return 0;
}