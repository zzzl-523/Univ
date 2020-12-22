#include<stdio.h>
#define SWAP(a,b,temp) ( (temp)=(a), (a)=(b), (b)=(temp))
int main() {
	int list[105] = { 0, };
	int T = 0;

	scanf("%d", &T);
	for (int i = 0; i < T; i++) {
		scanf("%d", &list[i]);
	}

	int max = 0,temp=0;
	for (int i = 0; i < T - 1; i++) {
		max = i;
		for (int j = i + 1; j < T; j++) {
			if (list[j] > list[max]) {
				max = j;
			}
		}
		SWAP(list[max], list[i], temp);
	}

	for (int i = 0; i < T; i++) {
		printf("%d ", list[i]);
	}
	return 0;
}