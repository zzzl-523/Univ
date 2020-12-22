//2019060164
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <getopt.h>
#include "cachelab.h"
#include <unistd.h>


typedef struct {
  bool valid;
  int tag;
  int time;
} Line;

typedef struct {
  Line* lines; 
} Set;

typedef struct {
  Set* sets;
  size_t set_howMany; 
  size_t line_howMany;
} Cache;


Cache cache = {};
int set_bits = 0, block_bits = 0;
size_t hit = 0, miss = 0, eviction = 0; 


void cache_simulate(int address);
int main(int argc, char *argv[]) {
  
  FILE* file = 0;
  int setting;
  while((setting = getopt(argc, argv, "s:E:b:t:")) != -1) {
    switch (setting) {
      case 's':
        set_bits = atoi(optarg); 
        cache.set_howMany = 2 << set_bits;
        break;
      case 'E':
        cache.line_howMany = atoi(optarg);
        break;
      case 'b':
        block_bits = atoi(optarg);
        break;
      case 't': 
        if (!(file = fopen(optarg, "r"))) { 
		return 1; 
	}
        break;
      default:
        return 1;
    }
  }

  cache.sets = malloc(sizeof(Set) * cache.set_howMany);
  for (int i = 0; i < cache.set_howMany; ++i) {
    cache.sets[i].lines = calloc(sizeof(Line), cache.line_howMany);
  }

  char menu;
  int address;

  while (fscanf(file, " %c %x%*c%*d", &menu, &address) != EOF) {

    if (menu == 'I') { continue; }
    cache_simulate(address);
    if (menu == 'M') { cache_simulate(address); }
  }
  printSummary(hit, miss, eviction);


  fclose(file);
  for (size_t i = 0; i < cache.set_howMany; ++i) { free(cache.sets[i].lines); }
  free(cache.sets);
  return 0;
}


void cache_simulate(int address) {
  int tag = 0xffffffff & (address >> (set_bits + block_bits));
  size_t index_set = (0x7fffffff >> (31 - set_bits)) & (address >> block_bits);

  Set* set = &cache.sets[index_set];

  for (size_t i = 0; i < cache.line_howMany; ++i) {
    Line* line = &set->lines[i];

    if((line->valid)&&(line->tag==tag)){//hit
        
     ++hit;

     for (size_t i = 0; i < cache.line_howMany; ++i) {
         Line* it = &set->lines[i];
        if (!it->valid){continue;}
        if (it->time <= line->time) {continue;}
       --it->time;
        
        }
 
   line->time = cache.line_howMany - 1;

    
     
     return;
    }
  }


  ++miss;	//miss


  for (size_t i = 0; i < cache.line_howMany; ++i) {
    Line* line = &set->lines[i];

    
    if(!line->valid){

        line->valid = true;
        line->tag = tag;
	
	for (size_t i = 0; i < cache.line_howMany; ++i) {
         Line* it = &set->lines[i];
      	  if (!it->valid){continue;}
     	   if (it->time <= line->time) {continue;}
      	 --it->time;
        
        }
 
  	 line->time = cache.line_howMany - 1;

     return;


    }
  }


  ++eviction;
  for (size_t i = 0; i < cache.line_howMany; ++i) {
    Line* line = &set->lines[i];

    if (!line->time) {
     line->valid = true;
     line->tag = tag;
     for (size_t i = 0; i < cache.line_howMany; ++i) {
         Line* it = &set->lines[i];
        if (!it->valid){continue;}
        if (it->time <= line->time) {continue;}
       --it->time;
        
        }
 
   line->time = cache.line_howMany - 1;

    
     
     return;
    }
  }
}


