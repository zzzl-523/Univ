//Template
#include <stdio.h>
#include <stdlib.h>
#define SIZE 10

int compare(int a, int b) {
	if (a > b)
		return 1;
	else
		return -1;
}


/***************************************************************
define bubble sort that uses pointer to 'compare' function above
***************************************************************/

void bubbleSort(int* addptr) {
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE - 1; j++) {
			if (compare(*(addptr+j), *(addptr+(j + 1))) == 1) {
				int* tmp;
				tmp = *(addptr + j);
				*(addptr + j) = *(addptr + (j + 1));
				*(addptr + (j + 1)) = tmp;
			}
		}
	}
}

int main() {
	int n_array[SIZE] = { 2,-9, 10, 15, 1, 3, -12, 5, 4, 1 };
	
	bubbleSort(n_array);

	printf("{ ");
	for (int i = 0; i < SIZE; i++) {
		if (i == SIZE - 1) {
			printf(" %d ", n_array[i]);
		}
		else {
			printf(" %d,", n_array[i]);
		}		
	}
	printf("} ");
		

	return 0;
}
