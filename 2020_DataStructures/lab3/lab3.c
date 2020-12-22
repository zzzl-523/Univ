#include<stdio.h>
#include<stdlib.h>

FILE* f_input;
FILE* f_output;

typedef struct Stack {
	int* key;	//�迭 ����ų ������
	int top;
	int max_stack_size;
}Stack;

Stack* CreateStack(int max) {//max��ŭ stack �����
	Stack* S = NULL;
	S = (Stack*)malloc(sizeof(struct Stack));
	S->key = (int*)malloc(sizeof(int)*max);	//�迭 ������ֱ�(stack���� �����)
	S->top = -1;
	S->max_stack_size = max;

	return S;
}

void Push(Stack* S, int X);
int Pop(Stack *S);
int Postfix(Stack* S, char input_str);
void DeleteStack(Stack* S);

int main(int argc,char* argv[]) {
	f_input = fopen(argv[1], "r");
	f_output=fopen(argv[2],"wt");

	char input_list[105];
	int max = 10, top = 0, result = 0;
	
	fgets(input_list, 105, f_input);	//���Ͽ��� �� �� �ҷ�����

	Stack* m_stack=CreateStack(max);	//�ϴ� 10���� ������ �ϳ� ������ش�

	fprintf(f_output, "%s", "Top numbers : ");
	for (int i = 0; i < sizeof(input_list)/sizeof(input_list[0])&&input_list[i]!='#'; i++) {
		if ((49 <= (int)input_list[i]) && ((int)input_list[i] <= 57)) {//����
			Push(m_stack, input_list[i]-48);	//���ڸ� stack�� �ִ´�
        }
		else {
			Push(m_stack,Postfix(m_stack, input_list[i]));	//���ڰ� �ƴϸ� ���� �ΰ��� ���� �����ϰ�/ �ٽ� �ִ´�
        }
        fprintf(f_output,"%d ",m_stack->key[m_stack->top]);
	}

	fprintf(f_output, "%s", "\nevaluation result : ");
	fprintf(f_output, "%d", m_stack->key[m_stack->top]);
    
    DeleteStack(m_stack);
	fclose(f_input);
	fclose(f_output);

	return 0;
}

void Push(Stack* S, int X) {
	if (S->top == S->max_stack_size) {
		fprintf(f_output, "%s", "error");
	}
	else {
        S->top++;
		S->key[S->top] = X;	//���� top�� ���� ĭ�� X �ֱ�
	}
}
int Pop(Stack *S) {
	int dab = 0;
	dab = S->key[S->top];

	if (S->top == -1) {	//empty
		fprintf(f_output, "%s", "error");
	}
	else {
		S->key[S->top] = -1;	//���� �����ʿ��X
		S->top--;
	}
	return dab;
}
int Postfix(Stack* S, char input_str) {
	int a = 0, b = 0;
	int dab = 0;
	b = Pop(S);
	a = Pop(S);
	
	//����
	switch (input_str) {
	case '+':
		dab = a + b;
		break;
	case'-':
		dab = a - b;
		break;
	case'*':
		dab = a * b;
		break;
	case'/':
		dab = a / b;
		break;
	case'%':
		dab = a % b;
	
	}

	return dab;
}
void DeleteStack(Stack* S) {
	free(S->key);
}
