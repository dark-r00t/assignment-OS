#ifndef PROCESSES_INCLUDED 
#define PROCESSES_INCLUDED

#include <stddef.h>
#include <stdio.h>
#include <printf.h>

typedef struct instruction_ {

	char* name;
	int arrival;
	int burst;
	int burst_left;
	int wait;
	int time_used;

} instruction_;


typedef struct instructions_ {

	int processcount; // 1
	int runfor; // 2
	int use; // 3
	int quantum;

	instruction_** id; //4

} instructions_;

typedef struct node {
	struct node* head;
	instruction_* process;
} node;

void execute_process(instructions_* list);
void fcfs(FILE* output, instructions_* list);
void rr(FILE* output, instructions_* list);
void sjf(FILE* output, instructions_* list);
void schedule_arrival(FILE* output, instructions_* list, int type);
void burst(FILE* output, int time, node* active_node);

#endif