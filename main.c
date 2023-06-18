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
