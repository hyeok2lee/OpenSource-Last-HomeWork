#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {

}node;

typedef struct {
	
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

}

int isEmpty(stack_h* S) {
	return 0;
}
void push(stack_h* S, char item) {
	return;
}
char pop(stack_h* S) {
	return NULL;
}
void printOp(char item) {
	return;
}
int checkOrder(char op) {
	return 0;
}
void printExp(stack_h* S) {

}
