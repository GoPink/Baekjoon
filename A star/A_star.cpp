#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

#define MAX		20

// edges             
int road[MAX][MAX] = { { -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,140,118, -1, -1, 75 },
{ -1, -1, -1, -1, -1,211, 90, -1, -1, -1, -1, -1, -1,101, -1, -1, -1, 85, -1, -1 },
{ -1, -1, -1,120, -1, -1, -1, -1, -1, -1, -1, -1, -1,138,146, -1, -1, -1, -1, -1 },
{ -1, -1,120, -1, -1, -1, -1, -1, -1, -1, 75, -1, -1, -1, -1, -1, -1, -1, -1, -1 },
{ -1, -1, -1, -1, -1, -1, -1, 86, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 },
{ -1,211, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 99, -1, -1, -1, -1 },
{ -1, 90, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 },
{ -1, -1, -1, -1, 86, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 98, -1, -1 },
{ -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 87, -1, -1, -1, -1, -1, -1, 92, -1 },
{ -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 70, -1, -1, -1, -1, -1,111, -1, -1, -1 },
{ -1, -1, -1, 75, -1, -1, -1, -1, -1, 70, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 },
{ -1, -1, -1, -1, -1, -1, -1, -1, 87, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 },
{ -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,151, -1, -1, -1, 71 },
{ -1,101,138, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 97, -1, -1, -1, -1, -1 },
{ -1, -1,146, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 97, -1, 80, -1, -1, -1, -1 },
{ 140, -1, -1, -1, -1, 99, -1, -1, -1, -1, -1, -1,151, -1, 80, -1, -1, -1, -1, -1 },
{ 118, -1, -1, -1, -1, -1, -1, -1, -1,111, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 },
{ -1, 85, -1, -1, -1, -1, -1, 98, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,142, -1 },
{ -1, -1, -1, -1, -1, -1, -1, -1, 92, -1, -1, -1, -1, -1, -1, -1, -1,142, -1, -1 },
{ 75, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 71, -1, -1, -1, -1, -1, -1, -1 } };

// h(n)
int distance[MAX] = { 366, 0, 160, 242, 161, 178, 77, 151, 226, 244, 241, 234, 380, 98, 193, 253, 329, 80, 199, 374 };

// data structure for states
struct listnode {
	struct listnode		*parent;		// parent state
	int					id;				// city id
	int					g;				// cost from Start to this state
	int					h;				// estimated cost from this state to Goal
	int					f;				// f = g + h
	struct listnode		*next;
};
typedef struct listnode STATE;

// Global variables for states and state pointers
STATE OPEN, CLOSED, CHILDREN;			// dummy head for OPEN and CLOSED list, CHILDREN list
STATE STARTSTATE, GOALSTATE;			// Start and Goal states

STATE *open = &OPEN, *closed = &CLOSED, *children = &CHILDREN;
STATE *start = &STARTSTATE, *goal = &GOALSTATE, *current;

// functions
void generate_children(STATE *s);
void free_children(void);
int compute_h(STATE *s);
int check_open(STATE *s);
int check_closed(STATE *s);
int is_same(STATE *s1, STATE *s2);
void insert_state(STATE *l, STATE *s);
void remove_state(STATE *l, STATE *s);
STATE * copy_state(STATE *s);
void print_solution(STATE *s);
void print_all_state(STATE *s);
int check_chlid(STATE *s);

void main()
{
	int i, j, id, found = 0, state_count = 0;
	STATE *child;

	printf("\n\n <Finding route to Bucharest> \n");

	// input start city 
	printf("\n Start city : ");
	scanf("%d", &id);
	start->id = id;
	start->parent = NULL;
	start->g = 0;
	start->h = compute_h(start);
	start->f = start->g + start->h;

	// input goal city - fixed goal 1 (Bucharest)
	goal->id = 1;

	// A* search 
	insert_state(open, start);
	while (open->next != NULL) {

		printf(".");
		state_count++;

		// choose
		current = open->next;

		// goal test
		if (is_same(current, goal)) {
			found = 1;
			break;
		}

		// expand
		else {
			child = copy_state(current);
			generate_children(child);
			remove_state(open, child);
			if (!check_closed(child)) insert_state(closed, child);

			while (check_closed(children->next)) {
				remove_state(children, children->next);
			}
			insert_state(open, children->next);
			remove_state(children, children->next);
		}
	}

	if (found == 0) {
		printf("\n There is no path ! \n\n");
	}
	else {
		// display solution path
		printf("\n\n shortest path : ");
		print_solution(current);
		printf("\n path length   : %d km \n\n", current->g);
	}
}

// generate next states of s and put them into children list
void generate_children(STATE *s)
{
	STATE *tmp = (STATE *)malloc(sizeof(STATE));
	STATE *cmp;
	for (int i = 0; i < MAX; i++) {
		if (road[s->id][i] != -1 && !check_closed(s)) {
			tmp->id = i;
			tmp->g = s->g + road[s->id][i];
			tmp->h = compute_h(tmp);
			tmp->f = tmp->g + tmp->h;
			tmp->next = NULL;
			tmp->parent = s;
			if (check_chlid(tmp)) {
				cmp = children->next;
				while (cmp->id != tmp->id) {
					cmp = cmp->next;
				}
				if (cmp->f > tmp->f) {
					remove_state(children, cmp);
					insert_state(children, tmp);
					continue;
				}
				else
					continue;
			}
			insert_state(children, tmp);
		}
	}
}

// free current children list
void free_children()
{
	while (children->next != NULL) {
		remove_state(children, children->next);
	}
}

// compute heuristic value h of state s
int compute_h(STATE *s)
{
	// this code assumes the straight distance to the goal is given
	// usually it must be computed based on each location's coordinates
	return distance[s->id];
}

// check whether s is in OPEN and f(s) is smaller
// if so, update s (insert new s into OPEN)
int check_open(STATE *s)
{
	STATE *tmp = open->next;
	while (tmp != NULL) {
		if (is_same(s, tmp)) return 1;
		tmp = tmp->next;
	}
	return 0;
}

// check whether s is in CLOSED and f(s) is smaller
// if so, insert s back to OPEN
int check_closed(STATE *s)
{
	STATE *tmp = closed->next;
	while (tmp != NULL) {
		if (is_same(s, tmp)) return 1;
		tmp = tmp->next;
	}
	return 0;
}

int check_chlid(STATE *s)
{
	STATE *tmp = children->next;
	while (tmp != NULL) {
		if (is_same(s, tmp)) return 1;
		tmp = tmp->next;
	}
	return 0;
}
// check if two states are same
int is_same(STATE *s1, STATE *s2)
{
	if (s1->id == s2->id) return 1;
	else return 0;
}

// insert a copy of state s to list l. list l is in sorted order
void insert_state(STATE *l, STATE *s)
{
	STATE *temp;

	while (l->next != NULL) {
		if (s->f < l->next->f) break;
		l = l->next;
	}
	temp = copy_state(s);
	temp->next = l->next;
	l->next = temp;
}

// remove state s from list l 
void remove_state(STATE *l, STATE *s)
{
	STATE *temp;
	while (l->next != NULL) {
		if (s->id == l->next->id) {
			temp = l->next;
			l->next = l->next->next;
			free(temp);
			return;
		}
		l = l->next;
	}
}

// make a copy of state s
STATE * copy_state(STATE *s)
{
	STATE *temp;

	temp = (STATE *)malloc(sizeof(STATE));
	temp->parent = s->parent;
	temp->id = s->id;
	temp->g = s->g;
	temp->h = s->h;
	temp->f = s->f;
	temp->next = NULL;

	return temp;
}

// print solution path recursively 
void print_solution(STATE *s)
{
	if (s == NULL) return;
	print_solution(s->parent);
	printf("%d ", s->id);
	if (s->id != goal->id) printf(" -> ");
}

void print_all_state(STATE *s) {
	while (s->next != NULL) {
		printf("%d(%d) -> ", s->next->id, s->next->f);
		s = s->next;
	}
	puts("");
}