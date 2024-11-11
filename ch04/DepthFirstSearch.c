#include <stdio.h>
#define SIZE 8
typedef enum {false, true} bool; 
// typedef a b => a에 있는 걸 b로 사용
// enum => 열거형, 사용할 게 정해져 있을 때(요일, 월 등) => false = 0, true = 1로 자동으로
int stack[SIZE]; // stack 배열 준비
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
	printf("출발 정점:");
	scanf_s("%c", &startVertex, 1);
	for (i = 0; i < SIZE; i++) if (startVertex == V[i]) break;
	printf("깊이우선탐색 :%c", startVertex); // startVertex 대신 V[i]도 가능
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