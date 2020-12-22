#include<stdio.h>
#include<stdlib.h>
typedef struct Node* PtrToNode;
typedef PtrToNode List;
typedef PtrToNode Position;
typedef int ElementType;
struct Node {
	ElementType element;
	Position next;
};

List MakeEmpty(List L);
int IsEmpty(List L);
int IsLast(Position P, List L);
void DeleteList(List L);

void Insert(ElementType X, List L, Position P);
void PrintList(List L,FILE* f_output);
void Delete(ElementType X, List L);
Position Find(ElementType X, List L);
Position FindPrevious(ElementType X, List L);


int main(int argc, char* argv[]) {	//����, �迭  int argc, char* argv[]
	char command;
	int  key1, key2;
	Position header=NULL;
	Position tmp = NULL;

	//FILE* f_input = fopen("input_example.txt", "r");
	FILE* f_input = fopen(argv[1], "r");
	FILE* f_output = fopen(argv[2], "wt");

	header = MakeEmpty(header);
	while (1) {
		command = fgetc(f_input);
		if (feof(f_input)) {	//������ break
			break;
		}

		switch (command) {
		case'i':
			fscanf(f_input, "%d %d", &key1, &key2);
			if (key2 == -1) {
				Insert(key1, header, header);
			}
			else {
				tmp = Find(key2, header);	//key2ã�Ƽ� 
				if (tmp == NULL) {
					fprintf(f_output, "Insertion(%d) Failed: cannot find the location to be inserted\n", key1);
				}
				else Insert(key1, header, tmp);		//insert
			}
			break;

		
		case'd':
			fscanf(f_input, "%d", &key1);
			if (Find(key1, header) == NULL) {
				fprintf(f_output, "Deletion(%d) Failed: Element 9 is not in the list\n", key1);
			}
			
			Delete(key1, header); //�̰� �ȵǴ°���=>free�� ������ �ذ�
			break;

		case'f':
			fscanf(f_input, "%d", &key1);
			tmp = FindPrevious(key1, header);	//header��� list, key1ã��
			if (IsLast(tmp, header)) {
				fprintf(f_output,"Finding(%d) Failed: Element %d is not in the list\n", key1,key1);
			}
			else {
				if (tmp->element > 0) {
					fprintf(f_output,"Key of the previous node of %d is %d.\n", key1, tmp->element);
				}
				else {
					fprintf(f_output,"Key of the previous node of %d is head.\n", key1);
				}
			}
			break;

		case'p':
			PrintList(header,f_output);
			break;

		default:
			break;
		}
	}

	DeleteList(header);
	fclose(f_input);
	fclose(f_output);
	
	return 0;
}


List MakeEmpty(List L) {
	L = (List)malloc(sizeof(struct Node));
	L->element = 0;
	L->next = NULL;
	return L;
}
int IsEmpty(List L) {
	return L->next == NULL;	
}
int IsLast(Position P, List L) {
	return P->next == NULL;	//�������̸� 1
}
void DeleteList(List L) {	//List�� �����, ���� header�� �����ϱ�
	Position P = NULL, tmp = NULL;
	P = L->next;
	L->next = NULL;
	while (P!= NULL) {
		tmp = P->next;
		free(P);
		P = tmp;
	}
}


void Insert(ElementType X, List L, Position P) {
	Position new_node=NULL;
	new_node = MakeEmpty(new_node);
	//new_node = (Position)malloc(sizeof(struct Node));
	if (new_node == NULL) {
		printf("Out of space!!!\n");
	}	
	else {
		new_node->element = X;
		new_node->next = P->next;
		P->next = new_node;
	}
}
void PrintList(List L,FILE* f_output) {
	//f_output = fopen("lab02_output.txt", "wt");

	Position P = NULL;
	P = L->next;
	while (P!=NULL) {
		fprintf(f_output,"key: %d	", P->element);	//����Ʈ ���
		P=P->next; 
	}
}
void Delete(ElementType X, List L) {
	Position P = NULL,tmp = NULL;
	P = FindPrevious(X, L);	//X�ִ� node �ٷ� �� node�� P
	
	if (!IsLast(P, L)) {	//P�� �������� �ƴ� �� ���ư���(Xã���� ��)
		tmp = P->next;	//X�ִ�
		P->next = tmp->next;
		free(tmp);
	}
}
Position Find(ElementType X, List L) {
	Position P = NULL;
	P = L->next;	//header������ ���� �������ְ� ã�� ����
	while ((P != NULL) && P->element != X) {//����Ǿ��ų� ã�� �ʾ��� ��
		P=P->next;	//�������� �ѱ��
	}
	return P;
}
Position FindPrevious(ElementType X, List L) {
	Position P = NULL;
	P = L;
	while ((P->next != NULL) && P->next->element != X) {
		P = P->next;
	}
	return P;
}
