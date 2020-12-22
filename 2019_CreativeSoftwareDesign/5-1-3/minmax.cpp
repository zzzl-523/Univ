#include<iostream>
using namespace std;

void getMinMax(int* arr, int len, int& min, int& max){
	for(int i=0;i<len;i++){
		max<arr[i]?max=arr[i]:max=max;
		min>arr[i]?min=arr[i]:min=min;
	}
}
