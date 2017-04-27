#include <gtest/gtest.h>
typedef struct linked_list linked_list;

struct linked_list{
	char *data;
	int index; /* normally not used with Linked Lists, just for exercise */
	struct linked_list *next;
};
linked_list *head = NULL;
linked_list *current = NULL;
TEST(add_to_list,Mytest1)
{
	
}