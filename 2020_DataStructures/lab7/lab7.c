#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#define min(x,y) x<y?x:y
typedef struct _DisjointSet{
	int size_maze;
	int* ptr_arr;
}DisjointSets;

void init(DisjointSets* sets, DisjointSets* maze_print, int num);
void union_(DisjointSets* sets, int i, int j);
int find(DisjointSets* sets, int i);
void createMaze(DisjointSets* sets, DisjointSets* maze_print, int num);
void printMaze(DisjointSets* sets, int num);
void freeMaze(DisjointSets* sets, DisjointSets* maze_print);

FILE* f_input;
FILE* f_output;

int main(int argc, char* argv[]) {
	srand(time(NULL));

	f_input = fopen(argv[1], "r");
	f_output = fopen(argv[2], "wt");

	DisjointSets* sets = (DisjointSets*)malloc(sizeof(DisjointSets));
	DisjointSets* maze_print = (DisjointSets*)malloc(sizeof(DisjointSets));
	int num = 0;
	fscanf(f_input, "%d", &num);
	sets->size_maze = num * num;
	maze_print->size_maze = num * (num - 1) * 2;

	init(sets, maze_print, num);
	createMaze(sets, maze_print, num);
	printMaze(maze_print, num);
	freeMaze(sets, maze_print);

	fclose(f_input);
	fclose(f_output);
	return 0;
}

void init(DisjointSets* sets, DisjointSets* maze_print, int num) {
	sets->ptr_arr = (int*)malloc(sizeof(int)*sets->size_maze);
	for (int i = 1; i <= num*num; i++) {
		sets->ptr_arr[i] = 0;
	}
	maze_print->ptr_arr = (int*)malloc(sizeof(int)*(maze_print->size_maze+num));	//가장자리 벽도 추가(+num)_
	for (int i = 0; i < num*(num-1)*2+num; i++) {
		maze_print->ptr_arr[i] = -1;	//벽
	}
}
void union_(DisjointSets* sets, int i, int j) {
	if (sets->ptr_arr[i] > sets->ptr_arr[j]) {
		sets->ptr_arr[i] = j;

	}
	else {
		if (sets->ptr_arr[i] == sets->ptr_arr[j]) {
			sets->ptr_arr[i]--;
		}
		sets->ptr_arr[j] = i;
	}
}
int find(DisjointSets* sets, int i) {
	while (sets->ptr_arr[i] > 0) {
		i = sets->ptr_arr[i];	//parent 따라가기
	}
	return i;	//음수이거나 0이면 parent
}
void createMaze(DisjointSets* sets, DisjointSets* maze_print, int num) {
	while (find(sets,1)!=find(sets,sets->size_maze)) {
		int u = rand() % (num*num) + 1;
		int v = rand() % (num*num) + 1;
		
		int count_c = 0;
		int count_r = 0;
		if (abs(u - v) == 1 || abs(u - v) == num) {	//edge(벽)일 때만
			int i = find(sets, u);
			int j = find(sets, v);
			if (i != j) {	//cycle없애기
				int mini = min(u, v);
				if (abs(u - v) == 1) {
					if (mini%num != 0) {
						union_(sets, i, j);
						count_c = (mini / num);
						maze_print->ptr_arr[((mini%num) - 1) + (num*2) * count_c] = 0;	//세로벽 없애기
                       
                    }
				}
				else if (abs(u - v) == num) {
                    if(mini%num!=0){
					union_(sets, i, j);
					count_r = (mini / num);
					maze_print->ptr_arr[((mini%num) - 1 + num) + (num*2) * count_r] = 0;	//가로벽 없애기
                    }
                    else{
						union_(sets, i, j);
	                    maze_print->ptr_arr[(mini*2)-1]=0;
                    }
                }
			}
		}
	}
}
void printMaze(DisjointSets* sets, int num) {
	int count = 0;
	for (int i = 0; i < num; i++) {	//맨 위(테두리)
		fprintf(f_output, "+-");
	}
	fprintf(f_output, "+\n");

	for (int i = 0; i < sets->size_maze+num; i++) {
		
		if ((i / num) % 2 == 0) {	//세로벽
			if (i % num == 0) {
				if (count == 0) {
					fprintf(f_output, " ");
				}
				else {
					fprintf(f_output, "|");
				}
			}
			
            for(int i=0;i<sets->size_maze+num;i++){
                if((i/num)%2==0&&((i+1)%num==0)){
                    sets->ptr_arr[i]=-1;
                }
            }
            sets->ptr_arr[sets->size_maze+num-1]=0;

			if (sets->ptr_arr[i] == -1) {
				fprintf(f_output, " |");
			}
			else if (sets->ptr_arr[i] == 0) {
				fprintf(f_output, "  ");
			}

			if (i % num == num - 1) {
				fprintf(f_output, "\n");
			}
		}
		else if ((i / num) % 2 == 1) {	//가로벽
			if (i % num == 0) {
				fprintf(f_output, "+");
			}

			if (sets->ptr_arr[i] == -1) {
				fprintf(f_output, "-+");
			}
			else if (sets->ptr_arr[i] == 0) {
				fprintf(f_output, " +");
			}

			if (i % num == num - 1) {
				fprintf(f_output, "\n");
			}
		}
		count++;
	}

	for (int i = 0; i < num; i++) {	//맨 아래(테두리)
		fprintf(f_output, "+-");
	}
	fprintf(f_output, "+\n");

}
void freeMaze(DisjointSets* sets, DisjointSets* maze_print) {
	free(sets);
	free(maze_print);
}
