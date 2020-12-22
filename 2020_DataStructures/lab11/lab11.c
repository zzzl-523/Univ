#include<stdio.h>
#include<stdlib.h>

typedef struct ListNode* Position;
typedef Position List;
typedef struct hashTbl* HashTable;

struct ListNode {
	int Element;
};
struct hashTbl {
	int TableSize;
	List* TheLists;
};

void Insert(HashTable H, int value, int solution);
void Delete(HashTable H, int value, int solution);
int Find(HashTable H, int value, int solution);
void printTable(HashTable H);
int Hash(int value, int Size, int i, int solution);

FILE* f_input;
FILE* f_output;

int i;
int k = 0;
int find_use = 0;

int main(int argc, char* argv[]) {
	
	f_input = fopen(argv[1], "r");
	f_output = fopen(argv[2], "wt");

	char sol[10];
	int solution = 0;
	
	
	
	fgets(sol, 10, f_input);
	if (sol[0] == 'L') {
		solution = 1;
	}
	else if (sol[0] == 'Q') {
		solution = 2;
	}
	int size = 0;
	fscanf(f_input, "%d", &size);

	HashTable H = (HashTable)malloc(sizeof(struct hashTbl));
	H->TheLists = (List*)malloc(sizeof(List)*size);
	for (int j = 0; j <= size; j++) {
		H->TheLists[j] = (List)malloc(sizeof(struct ListNode));
	}
	
	H->TableSize = size;	
	for (int i = 0; i < size; i++) {
		H->TheLists[i]->Element = -1;
	}
	
	char menu;
	int value;
	while (1) {
		fscanf(f_input, "%c", &menu);
		if (feof(f_input)) {
			break;
		}
		else if (menu == 'i') {
			fscanf(f_input, "%d", &value);
			Insert(H, value, solution);
		}
		else if (menu == 'd') {
			fscanf(f_input, "%d", &value);
			Delete(H, value, solution);
		}
		else if (menu == 'f') {
			fscanf(f_input, "%d", &value);
			int result = Find(H, value, solution);
			if (result == 0) {
				fprintf(f_output, "Not found\n");
			}
			else {
				fprintf(f_output, "%d", result);
			}
		}
		else if (menu == 'p') {
			printTable(H);
		}
	}

	free(H);

	fclose(f_input);
	fclose(f_output);
}

void Insert(HashTable H, int value, int solution) {
	find_use = 0;
	k = 0;
	int index = value % (H->TableSize);
	int dab = index;

	if (Find(H, value, solution) > 0) {
		fprintf(f_output, "Already exists\n");
		return;
	}
	else {
		k = 0;
		while (1) {
			if (H->TheLists[index]->Element <= 0){ 
				H->TheLists[index]->Element = value;
				fprintf(f_output, "Inserted %d\n", value);
				return;
			}
			else {
				index = dab;
				index = Hash(value, H->TableSize, index, solution);					
			
			}
		}
	}
	
}
void Delete(HashTable H, int value, int solution) {
	int index = Find(H, value, solution);
	if (index != 0) {
		H->TheLists[index]->Element = 0;
		fprintf(f_output, "Deleted %d\n", value);
	}
	else {
		fprintf(f_output, "%d not exists\n", value);
	}
}
int Find(HashTable H, int value, int solution) {
	k = 0;
	int j = value % (H->TableSize);
	int dab = j;
	while(1){
		if (H->TheLists[j]->Element == -1) {
			return 0;
		}
		if (value == H->TheLists[j]->Element) {
			return j;
		}
		j = dab;
		j = Hash(value, H->TableSize, j, solution);
		
	}
	return 0;
}
void printTable(HashTable H) {
	for (int j = 0; j < H->TableSize; j++) {
		if (H->TheLists[j]->Element == -1) {
			fprintf(f_output, "0 ");
		}
		else {
			fprintf(f_output, "%d ", H->TheLists[j]->Element);
		}
	}
}
int Hash(int value, int Size, int i, int solution) {
	k++;
	if (solution == 1) {
		i += k;
	}
	if (solution == 2) {
		i = i + k * k;
	}
	if (i > Size - 1) {
		i -= Size - 1;
	}
	return i;
}
