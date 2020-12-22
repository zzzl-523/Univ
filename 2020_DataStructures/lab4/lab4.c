#include<stdio.h>
#include<stdlib.h>

struct CompleteTree {
	int Size;
	int nodeNum;
	int* Element;
};
typedef struct CompleteTree* Tree;

void Insert(Tree tree, int value);
void printPreorder(Tree tree, int index);
void printInorder(Tree tree, int index);
void printPostorder(Tree tree, int index);
void FreeTree(Tree tree);

FILE* f_input;
FILE* f_output;

int main(int argc,char* argv[]) {
	f_input = fopen(argv[1], "r");
	f_output = fopen(argv[2], "wt");

	int max = 0;
	fscanf(f_input, "%d", &max);
	
	Tree ptr_tree=	(Tree)malloc(sizeof(struct CompleteTree) );
	ptr_tree->Size = max;
	ptr_tree->nodeNum = 0;
	ptr_tree->Element = (int*)malloc(sizeof(int)*max);
		
	int value = 0;
	while(1) {	//일단 값을 tree에 insert
      if(fscanf(f_input,"%d",&value)!=EOF) {
              Insert(ptr_tree, value);}
      else{
          break;}
	}

	fprintf(f_output, "Preorder : ");
	printPreorder(ptr_tree, 1);

	fprintf(f_output, "\nInorder : ");
	printInorder(ptr_tree, 1);

	fprintf(f_output, "\nPostorder : ");
	printPostorder(ptr_tree, 1);

	FreeTree(ptr_tree);
	return 0;
}

void Insert(Tree tree, int value) {
	if (tree->nodeNum >= tree->Size) {
		fprintf(f_output, "%s", "Error! Tree is FULL:(\n");
		return;
	}
	
	tree->nodeNum++;
	tree->Element[tree->nodeNum] = value;
}
void printPreorder(Tree tree, int index) {  //root_print-left-right(top)
	if (index <= tree->nodeNum) {
		fprintf(f_output, "%d ", tree->Element[index]);
		printPreorder(tree, index * 2);
		printPreorder(tree, index * 2+1);
	}
}
void printInorder(Tree tree, int index) {   //left-root-right(order)
	if (index <= tree->nodeNum) {
		printInorder(tree, index * 2);
		fprintf(f_output, "%d ", tree->Element[index]);
		printInorder(tree, index * 2 + 1);
	}
}
void printPostorder(Tree tree, int index) { //left-right-root(bottom)
	if (index <= tree->nodeNum) {
		printPostorder(tree, index * 2);
		printPostorder(tree, index * 2 + 1);
		fprintf(f_output, "%d ", tree->Element[index]);
	}
}
void FreeTree(Tree tree) {
	free(tree);
}
