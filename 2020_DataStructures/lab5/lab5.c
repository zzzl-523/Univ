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
		return root;	//���� ������ ���
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

	Tree root = (Tree)malloc(sizeof(struct BinarySearchTree));	//node �ϳ� �����

	int count = 0;

	while (1) {
		fscanf(f_input, "%s", menu);
		if (feof(f_input)) {	//������ break
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
					root = insertNode(root, key);	//�����ϸ� ���
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

	//tree�� ������ �����Ҵ� �ϰ� insert
	if (root == NULL) {
		root = (Tree)malloc(sizeof(struct BinarySearchTree));

		if (root == NULL) {
			fprintf(f_output, "%s", "Error: allocation error!\n");
		}
		root->value = key;	//�ڽ��� ������ insert
		root->right = NULL;
		root->left = NULL;
	}

	else if (key > root->value) {
		root->right = insertNode(root->right, key);
	}
	else if (key < root->value) {	//������ ������ �ɷ�������
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
	else {//������ ã���Ŵϱ�
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
	if (root == NULL) {	//������ ����
		fprintf(f_output, "%s %d %s", "Deletion Error :",key, "is not in the tree.\n");
	}

	else if (key > root->value) {
		root->right = deleteNode(root->right, key);
	}
	else if (key < root->value) {
		root->left = deleteNode(root->left, key);
	}	//ã�� ��
	else if (key == root->value) {	//ã���� ��
		if (root->left == NULL && root->right == NULL) {
			free(root);
			return NULL;
		}
		else if (root->left == NULL && root->right != NULL) {//�� �� �ϳ��� NULL
			root = root->right;
			//free(root->right);
		}
		else if (root->left != NULL && root->right == NULL) {//�� �� �ϳ��� NULL
			root = root->left;
			//free(root->left);
		}
		else {	//�ڽ� node�� �� �� �ִ� ���
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
