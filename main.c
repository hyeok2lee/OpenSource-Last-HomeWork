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
	return;
}
int checkOrder(char op) {
	// 6 ~ 0 그리고 -1 숫자가 높을수록 우선순위가 높음
	if (op == '!' || op == '@' || op == '#') {
		return 6;
	}
	else if (op == '*' || op == '/') {
		return 5;
	}
	else if (op == '+' || op == '-') {
		return 4;
	}
	else if (op == '<' || op == '>') {
		return 3;
	}
	else if (op == '&') {
		return 2;
	}
	else if (op == '|') {
		return 1;
	}
	else if (op == '(' || op == '{' || op == '[') {
		return 0;
	}
	else {
		return -1;
	}
}
void printExp(stack_h* S) {

}
