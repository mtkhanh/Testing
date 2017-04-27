#include "linkedlist.h"
#include <stdio.h>
#include <stdlib.h>


int add_to_list(linked_list *ll, char *s)
{
	int ind = 0;
	linked_list *  pHead ;
	while(ll->next != NULL)
	{
		pHead = ll;
		ll = ll->next;
		ind = ll->index;
		
	}

	struct linked_list *lnext = (struct linked_list*) malloc(sizeof(struct linked_list));

	lnext->index = ++ind;
	lnext->data = s;
	lnext->next = NULL;
	
	ll->next = lnext;
	ll = pHead;

        //printf("(%d,%s) ",pHead->index,pHead->data);
	return ind;
}

int display_item(linked_list *ll)
{
	while(ll->next!=NULL)
	{
		ll = ll->next;
	}

	if(ll->data==NULL)
		return -1;
	else	
		return 0;
	
}

int display_list(linked_list *ll)
{
	int count = 0;
	while (ll != NULL)
	{
		printf("(%d,%s) ",ll->index,ll->data);
		ll = ll->next;
		count++;
	}
	printf("\n");
	return count-1;
}
linked_list * search_from_list(linked_list *ll, char *s)
{
	while(ll !=NULL)
	{	
		printf("(%d,%s)\n",ll->index,ll->data);
		if(ll->data == s)
		{	
			return ll;
		}
		ll = ll->next;	
	}
	return NULL;
}
int delete_from_list(linked_list *ll, int index){}
