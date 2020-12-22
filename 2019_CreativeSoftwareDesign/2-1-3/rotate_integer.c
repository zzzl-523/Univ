#include<stdio.h>
void rotateLeft(int* pa, int* pb, int* pc) {
	int temp = 0;
	int* pt=&temp;
	*pt = *pa;	//*∫Ÿ¿Ã±‚
	*pa = *pb;
	*pb = *pc;
	*pc = *pt;
}

void rotateRight(int* pa, int* pb, int* pc) {
	int temp = 0;
	int* pt=&temp;
	*pt = *pc;
	*pc = *pb;
	*pb = *pa;
	*pa = *pt;
}

int main() {
	int a = 10,b=20,c=30;
	int menu = 0;
	printf("%d:%d:%d\n",a,b,c);
	while (1) {
		scanf("%d", &menu);
		if (menu == 1) {
			rotateLeft(&a, &b, &c);
			printf("%d:%d:%d\n", a, b, c);
		}
		else if (menu == 2) {
			rotateRight(&a, &b, &c);
			printf("%d:%d:%d\n", a, b, c);
		}
		else {
			break;
		}
	}
}