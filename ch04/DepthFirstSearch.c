#include <stdio.h>
#define SIZE 8
typedef enum {false, true} bool; 
// typedef a b => a�� �ִ� �� b�� ���
// enum => ������, ����� �� ������ ���� ��(����, �� ��) => false = 0, true = 1�� �ڵ�����
int stack[SIZE]; // stack �迭 �غ�
int top = -1;

void push(int index) {
	stack[++top] = index;
}

int pop(void) {
	if (top == -1) return -1;
	return stack[top--];
}

void DepthFirstSearch(char V[], bool G[][SIZE]) {
	int i, j;
	bool searchOK[SIZE] = { false };
	char startVertex;
	printf("��� ����:");
	scanf_s("%c", &startVertex, 1);
	for (i = 0; i < SIZE; i++) if (startVertex == V[i]) break;
	printf("���̿켱Ž�� :%c", startVertex); // startVertex ��� V[i]�� ����
	searchOK[i] = true;
	do {
		for (j = 0; j < SIZE; j++) {
			if (G[i][j] == 1 && searchOK[j] == false) {
				printf("->%c", V[j]);
				push(i);
				searchOK[j] = 1;
				i = j;
				break;
			}
		}
		if (j == SIZE) i = pop();
	} while (i >= 0);
}

int main(void) {
	char V[] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H' };
	bool G[SIZE][SIZE] = { {0, 1, 1, 0, 0, 0, 0, 0},
						   {1, 0, 0, 1, 1, 0, 0, 0},
						   {1, 0, 0, 0, 0, 1, 1, 0},
						   {0, 1, 0, 0, 0, 0, 0, 1},
						   {0, 1, 0, 0, 0, 0, 0, 1},
						   {0, 0, 1, 0, 0, 0, 0, 1},
						   {0, 0, 1, 0, 0, 0, 0, 1},
						   {0, 0, 0, 1, 1, 1, 1, 0}, };
	DepthFirstSearch(V, G);
}