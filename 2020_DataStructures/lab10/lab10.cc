#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int count = 0;

typedef struct Node {
	int vertex;
	int dist;
	int prev;
}Node;
typedef struct Graph {
	int size;
	int** vertices;
	Node* nodes;
}Graph;
typedef struct Heap {
	int Capacity;
	int Size;
	Node* Element;
}Heap;

Graph* CreateGraph(int size);
void printShortestpath(Graph* g);
Heap* createMinHeap(int heapSize);
void insertToMinHeap(Heap* minHeap, int vertex, int distance);
Node deleteMin(Heap* minHeap);

FILE* f_input;
FILE* f_output;

int list[15];
void print_only(Graph* g, int a) {
	count++;
	list[count] = a;

	if (a == 1) {
		return;
	}
	
	print_only(g, g->nodes[a].prev);
}

int main(int argc, char* argv[]) {
	f_input = fopen(argv[1], "r");
	f_output = fopen(argv[2], "wt");

	Graph* g;
	int size;
	fscanf(f_input, "%d\n", &size);
	g = CreateGraph(size+1);

	int num = 0;
	while (num!=EOF) {
		int node1, node2, weight;
		fscanf(f_input, "%d-%d-%d", &node1, &node2, &weight);
		
		g->vertices[node1][node2] = weight;
		num=fgetc(f_input);
	}
	
	printShortestpath(g);
}

Graph* CreateGraph(int size) {
	Graph* g = (Graph*)malloc(sizeof(Graph));
	g->nodes = (Node*)malloc(sizeof(Node)*size);
	g->size = size;

	g->vertices = (int**)malloc(sizeof(int*)*(size));
	for (int i = 0; i < g->size; i++) {
		g->vertices[i] = (int*)malloc(sizeof(int)*(size));
	}

	for (int i = 0; i < g->size; i++) {
		for (int j = 0; j < g->size; j++) {
			g->vertices[i][j] = 0;
		}
	}
	//printf("CreateGraph\n");//
	return g;
}
void printShortestpath(Graph* g) {
	Heap* heap = createMinHeap(g->size);

	for (int i = 1; i < g->size; i++) {
		g->nodes[i].vertex = i;
		g->nodes[i].dist = 500;
		g->nodes[i].prev = 0;
	}
	g->nodes[1].dist = 0;
	insertToMinHeap(heap, g->nodes[1].vertex, g->nodes[1].dist);
	//printf("%d\n", heap->Size);
	Node value;
	int cost = 0;
	while (heap->Size > 0) {
		
		value = deleteMin(heap);
		//printf("value vertex : %d\n", value.vertex);//
		//printf("%d\n", value.dist);//



		for (int i = 1; i < g->size; i++) {
			if (g->vertices[value.vertex][i] != 0) {
				if (value.dist + g->vertices[value.vertex][i] < g->nodes[i].dist) {
					g->nodes[i].dist = value.dist + g->vertices[value.vertex][i];
					g->nodes[i].prev = value.vertex;
					insertToMinHeap(heap, g->nodes[i].vertex, g->nodes[i].dist);
					//printf("g.nodes print %d %d %d\n", g->nodes[i].vertex, g->nodes[i].dist, g->nodes[i].prev);
				}
			}
		}
	}
	
	for (int i = 2; i < g->size; i++) {
		int a = i;
		while (1) {
			count++;
			list[count] = a;
			a = g->nodes[a].prev;
			if (a == 1) {
				count++;
				list[count] = a;
				break;
			}
		}
		for (int i = count; i >= 1; i--) {
			if (i == 1) {
				fprintf(f_output,"%d", list[i]);
			}
			else {
				fprintf(f_output,"%d->", list[i]);
			}
		}
		fprintf(f_output,"(cost: %d)\n", g->nodes[i].dist);
		count = 0;
	}
	/*
	for (int i = 2; i <= g->size; i++) {
		print_only(g, i);
		for (int i = count; i >= 1; i--) {
			if (i == 1) {
				printf("%d", list[i]);
			}
			else {
				printf("%d->", list[i]);
			}
		}
		printf("(cost: %d)\n", g->nodes[i].dist);
		count = 0;
	}
	*/
	for (int i = 1; i < g->size; i++) {

		

		int check = 0;
		for (int j = 1; j < g->size; j++) {
			if (g->vertices[i][j] == 0) {
				check++;
			}
		}
		if (check == g->size) {
			fprintf(f_output,"Cannot reach to node %d\n", i);
		}
	}
}
Heap* createMinHeap(int heapSize) {
	Heap* heap = (Heap*)malloc(sizeof(Heap));
	heap->Capacity = heapSize;
	heap->Element = (Node*)malloc(sizeof(Node)*heapSize);
	heap->Size = 0;
	return heap;
}
void insertToMinHeap(Heap* minHeap, int vertex, int distance) {
	int i = 0;
	if (minHeap->Size == minHeap->Capacity) {
		printf("Error: full!\n");
		return;
	}

	if (minHeap->Size == 0) {
		minHeap->Element[1].vertex = vertex;
		minHeap->Element[1].dist = distance;
	}
	else {
		for (i = minHeap->Size + 1; minHeap->Element[i / 2].dist > distance; i /= 2) {
			if (i != 1) {
				minHeap->Element[i] = minHeap->Element[i / 2];
			}
		}
		minHeap->Element[i].vertex = vertex;
		minHeap->Element[i].dist = distance;
	}
	minHeap->Size++;
}
Node deleteMin(Heap* minHeap) {
	int i, child;
	Node min_ele, last_ele;
	min_ele = minHeap->Element[1];
	last_ele = minHeap->Element[minHeap->Size--];

	for (i = 1; i * 2 <= minHeap->Size; i = child) {
		child = i * 2;
		if (child < minHeap->Size&&minHeap->Element[child + 1].vertex < minHeap->Element[child].vertex) {
			child++;
		}
		if (last_ele.dist > minHeap->Element[child].dist) {
			minHeap->Element[i] = minHeap->Element[child];
		}
		else {
			break;
		}
	}
	minHeap->Element[i] = last_ele;

	return min_ele;
}