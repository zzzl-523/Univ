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


int main(int argc, char* argv[]) {	//개수, 배열  int argc, char* argv[]
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
		if (feof(f_input)) {	//없으면 break
			break;
		}

		switch (command) {
		case'i':
			fscanf(f_input, "%d %d", &key1, &key2);
			if (key2 == -1) {
				Insert(key1, header, header);
			}
			else {
				tmp = Find(key2, header);	//key2찾아서 
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
			
			Delete(key1, header); //이게 안되는거임=>free를 지워서 해결
			break;

		case'f':
			fscanf(f_input, "%d", &key1);
			tmp = FindPrevious(key1, header);	//header라는 list, key1찾기
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
	return P->next == NULL;	//마지막이면 1
}
void DeleteList(List L) {	//List를 지우기, 보통 header를 넣으니까
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
		fprintf(f_output,"key: %d	", P->element);	//리스트 출력
		P=P->next; 
	}
}
void Delete(ElementType X, List L) {
	Position P = NULL,tmp = NULL;
	P = FindPrevious(X, L);	//X있는 node 바로 앞 node가 P
	
	if (!IsLast(P, L)) {	//P가 마지막이 아닐 때 돌아간다(X찾았을 때)
		tmp = P->next;	//X있는
		P->next = tmp->next;
		free(tmp);
	}
}
Position Find(ElementType X, List L) {
	Position P = NULL;
	P = L->next;	//header다음을 먼저 배정해주고 찾기 시작
	while ((P != NULL) && P->element != X) {//종료되었거나 찾지 않았을 때
		P=P->next;	//다음으로 넘기기
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
