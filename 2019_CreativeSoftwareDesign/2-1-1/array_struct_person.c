#include<stdio.h>

typedef struct {
	char name[11];
	int age;
}Person;
int main() {
	Person list[3];
	for (int i = 0; i < 3; i++) {
		scanf("%s %d", &list[i].name, &list[i].age);
	}
	for (int i = 0; i < 3; i++) {
		printf("Name:%s, Age:%d\n", list[i].name, list[i].age);
	}
}