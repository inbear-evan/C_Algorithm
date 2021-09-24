/// <summary>
/// ���� �����̸� ���Ե� ������� ���� ������ FIFO�� �Ǿ� �ִ�.
/// qnqueue x : x�� ť�� �����Ѵ�.
/// dequeue : ���� ���� ���� ���ڸ� �����Ѵ�.
/// size : ť�� ũ�⸦ ����Ѵ�.
/// front : ť�� �� �� ���� ���� ����Ѵ�.
/// �Է�
/// ù �ٿ� ��ɾ� ���� 1 ~ 1000000
/// ��ɾ� ���� ��ŭ ��ɾ� �Է�
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
		printf("����á���ϴ�.\n");
		return;
	}
	q->data[q->rear] = val;
	q->rear = (q->rear + 1) % q->maxsize;
	q->size++;
}

void queue_dequeue(struct queue* q) {
	if (queue_empty(q)) {
		printf("����ֽ��ϴ�.\n");
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
	printf("��ɾ� ���� : "); scanf("%d", &N);
	queue_init(&q, N);
	for (int i = 0; i < N; i++) {
		printf("��ɾ� : "); scanf("%s", cmd);
		if (cmd[0] == 's') {
			printf("ť�� ũ�� : %d\n", queue_size(&q));
		}
		else if (cmd[0] == 'e') {
			printf("�Է��� �� : "); scanf("%d", &val);
			queue_enqueue(&q, val);
		}
		else if (cmd[0] == 'd') {
			queue_dequeue(&q);
		}
		else if (cmd[0] == 'f') {
			printf("ť�� �� ���� �� : %d\n", queue_front(&q));
		}
	}
	return 0;
}