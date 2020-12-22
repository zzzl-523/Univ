#include<stdio.h>
#include<stdlib.h>

typedef struct _Queue* Queue;
struct _Queue {
	int* key;
	int first;
	int rear;
	int qsize;
	int max_queue_size;
};

typedef struct _Graph* Graph;
struct _Graph {
	int* node;
	int size;
	int** matrix;
};

Graph CreateGraph(int* nodes);
void InsertEdge(Graph G, int a, int b);
void TopSort(Graph G);
Queue MakeNewQueue(int X);
void Enqueue(Queue Q, int X);
int Dequeue(Queue Q);

FILE* f_input;
FILE* f_output;

int count = 0;

int main(int argc, char* argv[]) {
	f_input = fopen(argv[1], "r");
	f_output = fopen(argv[2], "wt");

	int* nodes = (int*)malloc(sizeof(int) * 100);
	int* new_nodes = (int*)malloc(sizeof(int) * 100);
	int value;
	
	while (1) {
		fscanf(f_input, "%d", &value);
		count++;
		if (getc(f_input) == '\n') {
			nodes[count] = value;
			new_nodes[count] = value;
			break;
		}
		nodes[count] = value;
		new_nodes[count] = value;
	}
	Graph G = CreateGraph(nodes);

	int temp;
	for (int i = 1; i <= G->size; i++) {
		for (int j = 1; j <= G->size - i ; j++) {
			if (new_nodes[j] > new_nodes[j + 1]) {
				temp = new_nodes[j];
				new_nodes[j] = new_nodes[j + 1];
				new_nodes[j + 1] = temp;
			}
		}
	}
	Graph new_G = CreateGraph(new_nodes);
	

	while (1) {
		int u, v;
		fscanf(f_input, "%d-%d", &u, &v);
		InsertEdge(G, u, v);
		InsertEdge(new_G, u, v);

		if (getc(f_input) == EOF) {
			break;
		}
	}
	for (int i = 0; i <= G->size; i++) {
		for (int j = 0; j <= G->size; j++) {
			if (i == 0 && j == 0) {
				fprintf(f_output,"  ");
			}
			else {
				fprintf(f_output,"%d ", G->matrix[i][j]);	//출력
			}
		}
		fprintf(f_output,"\n");//
	}
	fprintf(f_output,"\n");
	TopSort(new_G);

	return 0;

}

Graph CreateGraph(int* nodes) {
	Graph G = (Graph)malloc(sizeof(struct _Graph));
	G->node = nodes;
	G->size = count;
	G->matrix = (int**)malloc(sizeof(int*)*G->size+1);
	for (int i = 0; i <= G->size; i++) {
		G->matrix[i] = (int*)malloc(sizeof(int)*G->size);
	}

	for (int i = 1; i <= G->size; i++) {
		G->matrix[0][i] = G->node[i];
	}
	for (int i = 1; i <= G->size; i++) {
		G->matrix[i][0] = G->node[i];
	}
	for (int i = 1; i <= G->size; i++) {
		for (int j = 1; j <= G->size; j++) {
			G->matrix[i][j] = 0;	//0으로 초기화
		}
	}

	return G;
}
void InsertEdge(Graph G, int a, int b) {
	int index_r = 0, index_c = 0;
	for (int i = 1; i <= G->size; i++) {
		if (a == G->node[i]) {
			index_r = i;
		}

		if (b == G->node[i]) {
			index_c = i;
		}
	}
	G->matrix[index_r][index_c] = 1;
}
void TopSort(Graph G) {
	Queue q = MakeNewQueue(G->size);
	int in_degree[100];
	int in_deg_zero[100];
	int mini = 0;
	int check = 0;
	
	

	for (int i = 1; i <= G->size; i++) {
		int count = 0;
		for (int j = 1; j <= G->size; j++) {
			if (G->matrix[j][i] == 1) {
				count++;
			}
		}
		in_degree[G->node[i]] = count;

		if (in_degree[G->node[i]] == 0) {
			Enqueue(q, G->node[i]);
		}
	}

	while (1) {
		int deq_value = Dequeue(q);
		fprintf(f_output,"%d ", deq_value);
		int row = 0;
		for (int i = 1; i <= G->size; i++) {
			if (G->node[i] == deq_value) {
				row = i;
			}
		}
		for (int i = 1; i <= G->size; i++) {
			if (G->matrix[row][i] == 1) {
				G->matrix[row][i]--;
				in_degree[G->node[i]]--;
				if (in_degree[G->node[i]] == 0) {
					Enqueue(q, G->node[i]);
				}
			}
		}
		if (q->qsize == 0) {
			break;
		}
	}
}
Queue MakeNewQueue(int X) {
	Queue q = (Queue)malloc(sizeof(struct _Queue));
	q->max_queue_size = X;
	q->qsize = 0;
	q->first = 0;
	q->rear = -1;
	q->key = (int*)malloc(sizeof(int)*q->max_queue_size);
	return q;
}
void Enqueue(Queue Q, int X) {
	if (Q->rear == Q->max_queue_size - 1) {
		fprintf(f_output,"Error : Full!\n");
		return;
	}
	Q->key[++Q->rear] = X;
	Q->qsize++;
}
int Dequeue(Queue Q) {
	if (Q->first > Q->rear) {
		fprintf(f_output,"Error : Empty!\n");
		return 0;
	}
	Q->qsize--;
	return Q->key[Q->first++];
}