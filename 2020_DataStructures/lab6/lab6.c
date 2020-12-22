#include<stdio.h>
#include<math.h>
#include<stdlib.h>

#define max(x,y) (x>y?x:y)

typedef struct AVLNode* Position;
typedef struct AVLNode* AVLTree;
typedef int ElementType;
struct AVLNode {
	ElementType Element;
	AVLTree left;
	AVLTree right;
	int Height;
};

int Height(Position p) {
	if (p == NULL) {
		return -1;
	}
	return p->Height;
}

AVLTree Insert(ElementType X, AVLTree T);
Position SingleRotateWithLeft(Position node);
Position SingleRotateWithRight(Position node);
Position DoubleRotateWithLeft(Position node);
Position DoubleRotateWithRight(Position node);
void printInorder(AVLTree T);
void deleteTree(AVLTree T);

FILE* f_input;
FILE* f_output;

int main(int argc, char* argv[]) {

	f_input = fopen(argv[1], "r");
	f_output = fopen(argv[2], "wt");

	int value = 0;

	AVLTree root = (AVLTree)malloc(sizeof(struct AVLNode));

	int count = 0;
	while (fscanf(f_input, "%d", &value) != EOF) {
		if (count == 0) {
			root->Element = value;
			root->Height = 0;
			root->left = root->right = NULL;
			count++;
			printInorder(root);
			fprintf(f_output, "\n");
		}
		else {
			root = Insert(value, root);
			printInorder(root);
			fprintf(f_output, "\n");
		}
	}

	deleteTree(root);

	fclose(f_input);
	fclose(f_output);

	return 0;
}

AVLTree Insert(ElementType X, AVLTree T) {
	if (T == NULL) {
		T = (AVLTree)malloc(sizeof(struct AVLNode));

		T->Element = X;
		T->Height = 0;
		T->left = T->right = NULL;
	}
	else if (X == T->Element) {
		fprintf(f_output, "%s %d %s", "[Error]", X, "already in the tree!\n");
	}
	else if(X<T->Element){
		T->left = Insert(X, T->left);

		if ((Height(T->left) - Height(T->right)) >= 2) {
			if (X < T->left->Element) {
				T = SingleRotateWithLeft(T);	//이런거 주의하기
			}
			else {
				T = DoubleRotateWithLeft(T);
			}
		}
	}
	else if(X>T->Element){	//X가 더 크면
		T->right = Insert(X, T->right);

		if ((Height(T->right) - Height(T->left)) >= 2) {
			if (X > T->right->Element) {
				T = SingleRotateWithRight(T);
			}
			else {
				T = DoubleRotateWithRight(T);
			}
		}
	}
	T->Height = max(Height(T->left), Height(T->right)) + 1;
	
	return T;
}
Position SingleRotateWithLeft(Position node) {
	Position k1;
	k1 = node->left;
	node->left = k1->right;
	k1->right = node;

	node->Height = max(Height(node->left), Height(node->right)) + 1;
	k1->Height = max(Height(k1->left), node->Height) + 1;

	return k1;
}
Position SingleRotateWithRight(Position node) {
	Position k1;
	k1 = node->right;
	node->right = k1->left;
	k1->left = node;

	node->Height = max(Height(node->left), Height(node->right)) + 1;
	k1->Height = max(Height(k1->right), node->Height) + 1;

	return k1;
}
Position DoubleRotateWithLeft(Position node) {
	node->left = SingleRotateWithRight(node->left);

	return SingleRotateWithLeft(node);
}
Position DoubleRotateWithRight(Position node) {
	node->right = SingleRotateWithLeft(node->right);

	return SingleRotateWithRight(node);
}
void printInorder(AVLTree T) {
	if (T) {
		printInorder(T->left);
		fprintf(f_output, "%d%s%d%s ", T->Element, "(", T->Height, ")");
		printInorder(T->right);
	}
}
void deleteTree(AVLTree T) {
	if (T) {
		deleteTree(T->left);
		deleteTree(T->right);
		free(T);
	}
}
