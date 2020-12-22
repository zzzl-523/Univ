#include<iostream>
#include<string>
using namespace std;

typedef struct{
	string name;
	double  score;
}Person;
int main(int argc, char** argv ){
	Person* list=new Person[(argc-1)/2];
	for(int i=0;i<(argc-1)/2;i++){
		list[i].name=argv[2*i+1];
	}
	for(int i=0;i<(argc-1)/2;i++){
		list[i].score=atof(argv[2*i+2]);
	}
	for(int i=0;i<(argc-1)/2;i++){
		cout<<"Name:"<<list[i].name<<", "<<"Score:"<<list[i].score<<endl;
	}
	delete[] list;
	return 0;
}

