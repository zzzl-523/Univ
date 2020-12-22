#include <stdio.h>
#include <stdlib.h>

int main(void) {
	char** pp_data = NULL;
	int n;
	int length;
	int i=0;

	scanf("%d", &n);

	char temp[100];
	

	//1. define & dynamic allocation
	pp_data = malloc(sizeof(char*)*n);
	
	scanf("%d", &length);
	for (int k = 0; k <= n; k++) {
		*(pp_data + k) = (char*)malloc(sizeof(char)*length);
		gets(temp);
		strcpy(*(pp_data + k), temp);
	}


	//2. print string
	for (int k = 0; k <= n; k++) {
		printf("%s\n", *(pp_data + k));
	}

	//3. free memory
	for (int k = 0; k < n; k++) {
		free(*(pp_data + k));
	}

	return 0;
}
