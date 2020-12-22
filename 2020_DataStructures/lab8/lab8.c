#include<stdio.h>
#include<stdlib.h>

typedef struct HeapStruct {
	int Capacity;
	int Size;
	int* Element;
}Heap;

Heap* CreateHeap(int heapSize);
void Insert(Heap* heap, int value);
int Find(Heap* heap, int value);
int DeleteMax(Heap* heap);
void PrintHeap(Heap* heap);

FILE* f_input;
FILE* f_output;

int main(int argc, char* argv[]) {
	f_input = fopen(argv[1], "r");
	f_output = fopen(argv[2], "wt");

	Heap* heap;
	char menu;
	int heap_size, insert_num, find_num;
	int is_in, max_element;
	while (1) {
		if (fscanf(f_input, "%c", &menu) == EOF) {
			break;
		}
		

		switch (menu) {
		case 'n':
			fscanf(f_input, "%d", &heap_size);
			heap = CreateHeap(heap_size);
			break;

		case 'i':
			fscanf(f_input, "%d", &insert_num);
			Insert(heap, insert_num);
			break;

		case 'f':
			fscanf(f_input, "%d", &find_num);
			is_in = Find(heap, find_num);
			if (is_in) {
				fprintf(f_output, "%d %s", find_num, "is in the heap\n");
			}
			else {
				fprintf(f_output, "%d %s", find_num, "is not in the heap\n");
			}
			break;

		case 'd':
			if (heap->Size == 0) {	//empty
				fprintf(f_output, "Delete Error : heap is empty\n");
			}
			else {
				max_element = DeleteMax(heap);
				fprintf(f_output, "Max Element : %d deleted\n", max_element);
			}

			break;

		case 'p':
			PrintHeap(heap);
			break;

		default:
			break;
		}
	}
	free(heap);
	fclose(f_input);
	fclose(f_output);
}

Heap* CreateHeap(int heapSize) {
	Heap* heap = (Heap*)malloc(sizeof(Heap));
	heap->Capacity = heapSize;
	heap->Size = 0;
	heap->Element = (int*)malloc(sizeof(int)*heapSize);

	return heap;
}
void Insert(Heap* heap, int value) {
	int i;
	if (heap->Size == heap->Capacity) {
		fprintf(f_output, "Insert Error : heap is full\n");
		return;
	}
	for (int j = 1; j <= heap->Size; j++) {
		if (value == heap->Element[j]) {
			fprintf(f_output, "%d %s", value, "is already in the heap\n");
			return;
		}
	}

	if (heap->Size == 0) {
		heap->Element[1] = value;
	}
	else {
		for (i = heap->Size + 1; heap->Element[i / 2] < value; i /= 2) {
			heap->Element[i] = heap->Element[i / 2];
			if (i == 1) {
				break;
			}
		}
		heap->Element[i] = value;
	}

	heap->Size++;
	fprintf(f_output, "%s %d%s", "insert", value, "\n");
}
int Find(Heap* heap, int value) {

	for (int i = 1; i <= heap->Size; i++) {
		if (value == heap->Element[i]) {
			return 1;
		}
		else {
			return 0;
		}
	}
}
int DeleteMax(Heap* heap) {
	int i, child;
	int max, last;

	max = heap->Element[1];
	last = heap->Element[heap->Size];

	for (i = 1; i * 2 <= heap->Size; i = child) {	//왼쪽
		child = i * 2;
		if (child<heap->Size&&heap->Element[child + 1]>heap->Element[child]) {	//오른쪽이 존재하고, 오른쪽이 더 작으면
			child++;
		}
		if (last < heap->Element[child]) {	//last랑도 비교해서 더 큰 걸로
			heap->Element[i] = heap->Element[child];
		}
		else {
			break;
		}
	}
	heap->Element[i] = last;
	heap->Size--;
	
	return max;
}
void PrintHeap(Heap* heap) {
	if (heap->Size == 0) {	//empty
		fprintf(f_output, "Print Error : heap is empty\n");
		return;
	}

	for (int i = 1; i <= heap->Size; i++) {
		fprintf(f_output, "%d ", heap->Element[i]);
	}
	fprintf(f_output, "\n");
}
