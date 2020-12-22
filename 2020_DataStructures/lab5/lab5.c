#include<stdio.h>
#include<stdlib.h>

typedef struct BinarySearchTree* Tree;
struct BinarySearchTree {
	int value;
	Tree left;
	Tree right;
};

Tree FindMin(Tree root) {
	if (root == NULL) {
		return NULL;
	}
	if (root->left != NULL) {
		FindMin(root->left);
	}
	else {	//root->left == NULL
		return root;	//가장 왼쪽을 출력
	}
}

Tree insertNode(Tree root, int key);
void findNode(Tree root, int key);
void printInorder(Tree root);
Tree deleteNode(Tree root, int key);
void deleteTree(Tree root);

FILE* f_input;
FILE* f_output;

int main(int argc, char* argv[]) {
	char menu[3];
	int key = 0;

	f_input = fopen(argv[1], "r");
	f_output = fopen(argv[2], "wt");

	Tree root = (Tree)malloc(sizeof(struct BinarySearchTree));	//node 하나 만들기

	int count = 0;

	while (1) {
		fscanf(f_input, "%s", menu);
		if (feof(f_input)) {	//없으면 break
			break;
		}
		switch (menu[0]) {
			case 'i':
				fscanf(f_input, "%d", &key);
				if (count == 0) {
					root->value = key;
					root->left = NULL;
					root->right = NULL;
					count++;
				}
				else {
					root = insertNode(root, key);	//성공하면 출력
				}
				break;

			case'd':
				fscanf(f_input, "%d", &key);
				root = deleteNode(root, key);
				break;

			case'f':
				fscanf(f_input, "%d", &key);
				findNode(root, key);
				break;

			case'p':
				printInorder(root);
				fprintf(f_output, "\n");
				break;

			default:
				break;
		}
	}
	
	deleteTree(root);

	fclose(f_input);
	fclose(f_output);
	return 0;
}

Tree insertNode(Tree root, int key) {

	//tree에 없으면 동적할당 하고 insert
	if (root == NULL) {
		root = (Tree)malloc(sizeof(struct BinarySearchTree));

		if (root == NULL) {
			fprintf(f_output, "%s", "Error: allocation error!\n");
		}
		root->value = key;	//자식이 없으면 insert
		root->right = NULL;
		root->left = NULL;
	}

	else if (key > root->value) {
		root->right = insertNode(root->right, key);
	}
	else if (key < root->value) {	//같으면 어차피 걸러지지만
		root->left = insertNode(root->left, key);
	}
	else if (key == root->value) {
		fprintf(f_output, "%s %d %s", "Insertion Error :",key,"is already in the tree.\n");
	}
	return root;
}
void findNode(Tree root, int key) {
	if (root == NULL) {
		fprintf(f_output, "%d %s", key,"is not in the tree\n");
	}
	else if (key > root->value) {
		findNode(root->right, key);
	}
	else if (key < root->value) {
		findNode(root->left, key);
	}
	else {//같으면 찾은거니까
		fprintf(f_output, "%d %s", key, "is in the tree\n");
	}
}

void printInorder(Tree root) {
	if (root) {
		printInorder(root->left);
		fprintf(f_output, "%d ", root->value);
		printInorder(root->right);
	}
	else {
		return;
	}
}
Tree deleteNode(Tree root, int key) {
	Tree tmp=NULL;
	if (root == NULL) {	//없으면 에러
		fprintf(f_output, "%s %d %s", "Deletion Error :",key, "is not in the tree.\n");
	}

	else if (key > root->value) {
		root->right = deleteNode(root->right, key);
	}
	else if (key < root->value) {
		root->left = deleteNode(root->left, key);
	}	//찾기 끝
	else if (key == root->value) {	//찾았을 때
		if (root->left == NULL && root->right == NULL) {
			free(root);
			return NULL;
		}
		else if (root->left == NULL && root->right != NULL) {//둘 중 하나만 NULL
			root = root->right;
			//free(root->right);
		}
		else if (root->left != NULL && root->right == NULL) {//둘 중 하나만 NULL
			root = root->left;
			//free(root->left);
		}
		else {	//자식 node가 둘 다 있는 경우
			tmp = FindMin(root->right);
			root->value = tmp->value;
			root->right = deleteNode(root->right, root->value);
		}
	}
	return root;
}
void deleteTree(Tree root) {
	if (root) {
		deleteTree(root->left);
		deleteTree(root->right);
		free(root);
	}
}
