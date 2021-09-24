/// <summary>
/// List
/// 랜덤 접근이 가능한 배열과는 다른 순차적인 자료구조
/// 명령어
/// - push x : x를 리스트 끝에 추가
/// - get x : 리스트의 x 번째 원소 출력
/// - size : 리스트의 크기를 출력
/// - count x : 리스트에 있는 x의 개수 출력
/// - clear : 리스트를 비움
/// 입력
/// 첫 줄에 명령어 갯수 1 ~ 1000000
/// 명령어 갯수 만큼 명령어 입력
/// </summary>

#pragma warning(disable: 4996)
#include <stdio.h>
#include <stdlib.h>

 
typedef struct node {
	struct node* next;
	int value;
}node;

typedef struct list {
	node* head;
	node* last;
	int size;
}list;

void init_list(list* mylist);
void push_back(list* mylist, int value);
int get_idx(list* mylist, int idx);
int count_target(list* mylist, int target);
void clear_list(list* mylist);
void free_node(node* current_node);

int main() {
	int n;
	printf("명령어 갯수 : "); scanf("%d", &n);

	list mylist;
	init_list(&mylist);
	while (n--) {
		printf("\n");
		char command[10];
		printf("명령어 : "); scanf("%s", command);

		if (command[0] == 'p') {
			int value;
			printf("값 : "); scanf("%d", &value);
			push_back(&mylist, value);
		}
		else if (command[0] == 'g') {
			int idx;
			printf("인덱스 : "); scanf("%d", &idx);
			printf("인덱스 %d의 값 : %d\n", idx, get_idx(&mylist, idx));
		}
		else if (command[0] == 's') {
			printf("리스트의 크기 : %d\n", mylist.size);
		}
		else if (command[1] == 'o') {
			int target;
			printf("찾을 값 : "); scanf("%d", &target);
			printf("%d 인 리스트 값의 갯수 %d\n",target, count_target(&mylist, target));
		}
		else {
			clear_list(&mylist);
		}
	}
	return 0;
}

void init_list(list* mylist) {
	mylist->head = (node*)malloc(sizeof(node));
	mylist->head->next = NULL;
	mylist->last = mylist->head;
	mylist->size = 0;
}

void push_back(list* mylist, int value) {
	node* new_node = (node*)malloc(sizeof(node));
	new_node->value = value;
	new_node->next = NULL;
	mylist->last->next = new_node;
	mylist->last = new_node;
	mylist->size++;
}

int get_idx(list* mylist, int idx) {
	node* pre_node = mylist->head;
	while (idx--) {
		pre_node = pre_node->next;
	}
	return pre_node->next->value;
}

int count_target(list* mylist, int target) {
	int count = 0;
	for (node* pre_node = mylist->head; pre_node->next != NULL; pre_node = pre_node->next) {
		if (pre_node->next->value == target) {
			count++;
		}
	}
	return count;
}
void clear_list(list* mylist) {
	free_node(mylist->head);
	init_list(mylist);
}

void free_node(node* current_node) {
	if (current_node->next != NULL) {
		free_node(current_node->next);
	}
	free(current_node);
}