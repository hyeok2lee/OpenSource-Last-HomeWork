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

	//연산 횟수 입력
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		// 연산 횟수 만큼 표현식 처리 메소드 호출
		printExp(s);
	}

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
	int i, length, order;
	// 표현식 입력받을 문자 배열
	char exp[101];

	scanf("%s", exp);
	length = strlen(exp);
	for (i = 0; i < length; i++) {
		// 현재 문자가 A~Z에 해당하는 피연산자인 경우 그냥 출력
		if ('A' <= exp[i] && exp[i] <= 'Z')
			printf("%c", exp[i]);
		else {
			// 연산자가 &, |라면 각각 &&, ||를 의미하므로 다음 인덱스로
			if (exp[i] == '&' || exp[i] == '|')
				i++;
			// +연산이 단항연산자인 경우 @로 변경
			else if (exp[i] == '+' && (i == 0 || checkOrder(exp[i - 1]) >= 0))
				exp[i] = '@';
			// -연산이 단항연산자인 경우 #으로 변경
			else if (exp[i] == '-' && (i == 0 || checkOrder(exp[i - 1]) >= 0))
				exp[i] = '#';

			// 시작 괄호를 의미하면 스택에 push
			if (isEmpty(S) || exp[i] == '(' || exp[i] == '{' || exp[i] == '[')
				push(S, exp[i]);
			// 닫는 괄호를 의미하는 경우
			else if (exp[i] == ')' || exp[i] == '}' || exp[i] == ']') {
				// 스택에서 시작괄호를 만날 때 까지 pop
				while (S->header->order != 0)
					printOp(pop(S));
				// 시작 괄호 pop
				pop(S);
			}
			else {
				// 현재 연산자 우선순위 가져오기
				order = checkOrder(exp[i]);
				// 현재 연산자보다 우선순위가 낮은 연산자를 만날 때 까지 pop
				while (!isEmpty(S) && order <= S->header->order)
					printOp(pop(S));
				// 현재 연산자 push
				push(S, exp[i]);
			}


		}
	}

	// 표현식을 모두 처리한 후에 스택에 연산자가 남아있다면 모두 pop
	while (!isEmpty(S))
		printOp(pop(S));

	printf("\n");
}
