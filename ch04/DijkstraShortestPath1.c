#include <stdio.h>
#include <limits.h>

#define SIZE 8
#define M INT_MAX

typedef enum { false, true } bool;

int minVertex(int D[], int chk[]) {
	int i, minValue = M, minIndex = 0;

	for (i = 0; i < SIZE; i++) {
		if (chk[i] == 0 && minValue > D[i]) {
			minValue = D[i];
			minIndex = i;
		}
	}
	return minIndex;
}

void Dijkstra(int G[][SIZE], int D[], int P[], int i) {
	int j, cnt = 0;
	bool chk[SIZE] = { false };

	//1�ܰ�
	for (j = 0; j < SIZE; j++) {
		if (G[i][j] > 0 && G[i][j] < M) {
			D[j] = G[i][j];
			P[j] = i;
		}
	}
	chk[i] = true;
	cnt++; // chk�� ��� �Ǵ��� Ȯ�� ( ���� 1�� ä������ ���� �� �ֵ��� )

	//2�ܰ�~������
	while (cnt < SIZE) {
		i = minVertex(D, chk); // i�� �������� ����� ������ ������
		for (j = 0; j < SIZE; j++) {
			if (G[i][j] > 0 && G[i][j] < M) {
				if (D[j] > D[i] + G[i][j]) {
					D[j] = D[i] + G[i][j];	// �� ����� �Ÿ��� ������Ʈ
					P[j] = i;				// �� ����� ��η� ������Ʈ
				}
			}
		}
		chk[i] = true;
		cnt++;
	}

}

int main(void) {
	int G[SIZE][SIZE] = { {0, 12, 15, 18, M, M, M, M}, //A�� ���� ����
					  {12, 0, M, M, 33, 26, M, M}, //B�� ���� ����
					  {15, M, 0, 7, M, 10, M, M}, //C�� ���� ����
					  {18, M, 7, 0, M, M, 11, M}, //D�� ���� ����
					  {M, 33, M, M, 0, 17, M, 15}, //E�� ���� ����
					  {M, 26, 10, M, 17, 0, M, 28}, //F�� ���� ����
					  {M, M, M, 11, M, M, 0, 20}, //G�� ���� ����
					  {M, M, M, M, 15, 28, 20, 0} }; //H�� ���� ����
	char V[SIZE] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H' };
	char aV, bV;
	int D[SIZE] = { M, M, M, M, M, M, M, M };
	int P[SIZE] = { 0, }, i;

	printf("��� ����: ");
	scanf_s("%c", &aV, 1);
	getchar();
	printf("���� ����: ");
	scanf_s("%c", &bV, 1);
	getchar();

	//���� ���� �ε��� ���ϱ�
	for (i = 0; i < SIZE; i++) if (bV == V[i]) break;
	//���� ������ ���� �Ÿ� �� ��� �ʱ�ȭ
	D[i] = 0; P[i] = i;

	//�ִ� ��� �� �Ÿ� ���ϱ�
	Dijkstra(G, D, P, i);

	//��������� ���������� �ִ� �Ÿ� �� ��� ����ϱ�
	for (i = 0; i < SIZE; i++) if (aV == V[i]) break;
	printf("\n%c���� %c���� �ִܰŸ�: %d\n", aV, bV, D[i]);
	printf("�ִܰ��: %c", aV);
	while (V[i] != bV) {
		i = P[i];
		printf(" -> %c", V[i]);
	}
	printf("\n");

	return 0;
}