#include<iostream>
#include"minmax.h"
using namespace std;

int main(int argc, char** argv){
	int N=argc-1;
	int* list=new int[N];
	for(int i=0;i<N;i++){
		list[i]=atoi(argv[i+1]);
	}
	int min=0,max=0;
	getMinMax(list,N,min,max);
	cout<<"min: "<<min<<endl;
	cout<<"max: "<<max<<endl;
	
	delete[] list;
	return 0;
}

