#include <stdio.h>
#include <set>
#include <map>
#include "pstdint.h"

#pragma warning(disable:4996)

struct node;

typedef std::set<node*> nodeset;

struct node
{
	node ( void )
	{
		name = 0;
		mark = 0;
		used = 0;
		next = 0;
	}

	uint32_t name;
	uint32_t mark;
	uint32_t used;

	node * next;

	nodeset edges;
};

typedef std::map<uint32_t,node> nodegraph;

nodegraph graph;

bool can_link ( node * A, node * B )
{
	if(A->edges.find(B) == A->edges.end()) return false;
	if(B->edges.find(A) == B->edges.end()) return false;

	return true;
}

bool can_link_all ( node * A, node * B )
{
	node * cursor = A;

	while(cursor)
	{
		if(!can_link(cursor,B)) return false;

		cursor = cursor->next;
	}

	return true;
}

void print_simplex( node * head )
{
	node * cursor = head;

	while(cursor)
	{
		printf("0x%08x,",cursor->name);
		cursor = cursor->next;
	}
	printf("\n");
}

void find_simplex ( node * head )
{
	bool found = false;

	for(nodeset::iterator it = head->edges.begin(); it != head->edges.end(); it++)
	{
		node * next = (*it);

		if(next->mark) continue;
		if(next->name > head->name) continue;

		if(can_link_all(head,next))
		{
			found = true;
			next->mark = head->mark + 1;
			next->next = head;

			find_simplex(next);

			next->mark = 0;
			next->next = 0;
		}
	}

	if(!found && (head->mark > 3))
	{
		bool used = false;

		node * cursor = head;

		while(cursor)
		{
			if(cursor->used) used = true;

			cursor = cursor->next;
		}

		if(!used) 
		{
			print_simplex(head);

			node * cursor = head;

			while(cursor)
			{
				cursor->used = 1;
				cursor = cursor->next;
			}
		}
	}
}

int simplex_main ( int argc, char * argv[] )
{
	if(argc < 2)
	{
		printf("blah\n");
		return 1;
	}

	FILE * file = fopen(argv[1],"r");

	if(!file)
	{
		printf("Couldn't open file\n");
		return 1;
	}

	char buffer[512];

	while(fgets(buffer,512,file))
	{
		uint32_t nameA;
		uint32_t nameB;

		int found = sscanf(buffer,"0x%08x,0x%08x",&nameA,&nameB);

		if(found != 2) continue;

		node * nodeA = &graph[nameA];
		node * nodeB = &graph[nameB];

		nodeA->name = nameA;
		nodeB->name = nameB;

		nodeA->edges.insert(nodeB);
		nodeB->edges.insert(nodeA);
	}

	for(std::map<uint32_t,node>::iterator it = graph.begin(); it != graph.end(); it++)
	{
		node & n = (*it).second;

		n.mark = 1;

		find_simplex(&n);

		n.mark = 0;
	}

	return 0;
}

