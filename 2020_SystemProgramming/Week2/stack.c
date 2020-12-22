//Template
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int nData;
	struct Node *next;
}Node;

typedef struct Stack {
	Node *top;
}Stack;

void InitializeStack(Stack *stack);
void Push(Stack *stack, int nData);
int Pop(Stack *stack);

int count = 0;

int main(void) {
	Stack* s = (Stack*)malloc(sizeof(struct Stack));
	InitializeStack(s);

	s->top->next = NULL;
	
	while (1) {
		char m;
		scanf("%c", &m);
		
		if (m == 'i') {
			int num;
			scanf("%d", &num);
			Push(s, num);
		}
		else if (m == 'd') {
			Pop(s);
		}
		else if (m == 'q') {
			break;
		}
	}

	Node* endptr = s->top->next;
	while (endptr != NULL) {
		printf("%d", endptr->nData);
		endptr = endptr->next;
	}
	
	return 0;
}

void InitializeStack(Stack* s) {
	s->top = (Node*)malloc(sizeof(struct Node));

	if (s->top == NULL) {
		printf("error!\n");
	}
	
	s->top->next = NULL;
}

void Push(Stack* s, int nData) {

	Node* tmp;
	tmp = (Node*)malloc(sizeof(struct Node));

	if (tmp == NULL) {
		printf("error!\n");
	}
	else {
		tmp->nData = nData;
		tmp->next = s->top->next;
		s->top->next = tmp;
	}

}

int Pop(Stack* s) {
	Node* tmp = s->top->next;
	int popNum = tmp->nData;
	s->top->next = s->top->next->next;
	free(tmp);

	return popNum;
}