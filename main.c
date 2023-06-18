#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	char item;
	int order;
	struct Node* next;

}node;

typedef struct {
	node* header;
}stack_h;

stack_h* createStack();
int isEmpty(stack_h* S);
void push(stack_h* S, char item);
char pop(stack_h* S);
void printOp(char item);
int checkOrder(char op);
void printExp(stack_h* S);

int main()
{
	stack_h* s;
	int i, n;

	s = createStack();

	return 0;
}

stack_h* createStack() {
	stack_h* S;

	S = (stack_h*)malloc(sizeof(stack_h));
	S->header = NULL;

	return S;
}

int isEmpty(stack_h* S) {
	if (S->header == NULL) {
		return 1;
	}
	return 0;
}
void push(stack_h* S, char item) {
	node* newNode;

	newNode = (node*)malloc(sizeof(node));
	newNode->item = item;
	newNode->order = checkOrder(item);

	if (isEmpty(S)) {
		newNode->next = NULL;
		S->header = newNode;
	}
	else {
		newNode->next = S->header;
		S->header = newNode;
	}
}
char pop(stack_h* S) {
	if (isEmpty(S))
		return -1;

	node* old = S->header;
	char item;

	item = S->header->item;
	S->header = old->next;
	free(old);

	return item;
}
void printOp(char item) {
	// @로 치환한 상태 출력은 + 로
	if (item == '@') {
		printf("%c", '+');
	}
	// #으로 치환한 상태 출력은 -로
	else if (item == '#') {
		printf("%c", '-');
	}
	// &는 && 2개를 의미
	else if (item == '&') {
		printf("%s", "&&");
	}
	// |는 || 2개를 의미
	else if (item == '|') {
		printf("%s", "||");
	}
	// 나머지는 그대로 연산자 출력
	else {
		printf("%c", item);
	}
}
int checkOrder(char op) {
	return 0;
}
void printExp(stack_h* S) {

}
