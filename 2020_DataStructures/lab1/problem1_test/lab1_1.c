#include<stdio.h>
int main() {
	int list[105] = { 0, };
	int T;
	int start = 0, end = 0;
	int dab=0;

	scanf("%d", &T);
	for (int i = 0; i < T; i++) {	//index��� ���������� 0����
		scanf("%d", &list[i]);
	}

	scanf("%d %d", &start, &end);
	
	for (int i = start; i <= end; i++) {
		dab += list[i];
	}
	printf("%d", dab);

	return 0;
}