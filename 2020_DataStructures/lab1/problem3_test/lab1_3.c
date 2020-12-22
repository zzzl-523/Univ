#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct {
	char name[30];
	int id;
}student;
void swap(student* a, student* b) {
	student temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

student list[15];
int main() {
	FILE *file_input;
	FILE *file_output;
	int T = 0;

	file_input = fopen("lab1_3_input.txt","r");
	file_output = fopen("lab1_3.output.txt", "wt");

	fscanf(file_input,"%d", &T);	//명수 입력받기

	char name_[30];
	for (int i = 0; i < T; i++) {
		
		fscanf(file_input,"%s %d", name_, &list[i].id);	//이름, id 입력받기
		//list[i].name = name_; //물어보기
		strcpy(list[i].name, name_);
	}
	
	int min = 0;
	for (int i = 0; i < T - 1; i++) {
		min = i;
		for (int j = i + 1; j < T; j++) {
			if (list[j].id < list[min].id) {
				min = j;
			}
		}
		swap(&list[i], &list[min]);
	}
	
	for (int i = 0; i < T; i++) {
		fprintf(file_output, "%s %d\n", list[i].name, list[i].id);
	}
	
	fclose(file_input);
	fclose(file_output);
	return 0;
	
}