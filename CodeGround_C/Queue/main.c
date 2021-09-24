/// <summary>
/// 선형 구조이며 삽입된 순서대로 값이 나오는 FIFO로 되어 있다.
/// qnqueue x : x를 큐에 삽입한다.
/// dequeue : 가장 먼저 들어온 인자를 삭제한다.
/// size : 큐의 크기를 출력한다.
/// front : 큐의 맨 앞 인자 값을 출력한다.
/// 입력
/// 첫 줄에 명령어 갯수 1 ~ 1000000
/// 명령어 갯수 만큼 명령어 입력
/// </summary>
#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

struct queue {
	int* data;
	int front, rear;
	int maxsize;
	int size;
};

void queue_init(struct queue* q, int sz) {
	q->maxsize = sz;
	q->front = 0;
	q->rear = 0;
	q->size = 0;
	q->data = (int*)malloc(q->maxsize * sizeof(int));
}

int queue_size(struct  queue* q){
	return q->size;
}

bool queue_empty(struct queue* q) {
	return queue_size(q) == 0;
}

bool queue_full(struct queue* q) {
	return q->size == q->maxsize;
}

void queue_enqueue(struct queue* q, int val) {
	if (queue_empty(q)) {
		printf("가득찼습니다.\n");
		return;
	}
	q->data[q->rear] = val;
	q->rear = (q->rear + 1) % q->maxsize;
	q->size++;
}

void queue_dequeue(struct queue* q) {
	if (queue_empty(q)) {
		printf("비어있습니다.\n");
		return;
	}
	q->front = (q->front + 1) % q->maxsize;
	q->size--;
}

int queue_front(struct queue* q) {
	if(queue_empty(q)) return INT_MAX;
	return q->data[q->front];
}

int val, N;
char cmd[16];
int main() {
	struct queue q;
	printf("명령어 갯수 : "); scanf("%d", &N);
	queue_init(&q, N);
	for (int i = 0; i < N; i++) {
		printf("명령어 : "); scanf("%s", cmd);
		if (cmd[0] == 's') {
			printf("큐의 크기 : %d\n", queue_size(&q));
		}
		else if (cmd[0] == 'e') {
			printf("입력할 값 : "); scanf("%d", &val);
			queue_enqueue(&q, val);
		}
		else if (cmd[0] == 'd') {
			queue_dequeue(&q);
		}
		else if (cmd[0] == 'f') {
			printf("큐의 맨 앞의 값 : %d\n", queue_front(&q));
		}
	}
	return 0;
}