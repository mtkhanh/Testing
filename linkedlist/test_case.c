#include <gtest/gtest.h>
#include <string.h>
#include "linkedlist.h"


TEST(add_to_list,Mytest1)
{
	linked_list head;
	char stringTest[] = "abd";
	head.index = 0;
	head.next = NULL;
	
	EXPECT_EQ(1,add_to_list(&head,stringTest));
	
	EXPECT_EQ(2,add_to_list(&head,stringTest));
}

TEST(display_item,Mytest2)
{
	linked_list head,lhead;
	head.index = 0;
    head.next = NULL;
	head.data = NULL;

    lhead.index = 0;
	lhead.next=NULL;
	lhead.data = NULL;
	
	char stringTest[] = "abc";
	char stringTest1[] = "def";
	char stringTest2[] = "ghi";
	
	add_to_list(&head,stringTest);
	add_to_list(&head,stringTest1);
	add_to_list(&head,stringTest2);
	
	EXPECT_EQ(0,display_item(&head));
	EXPECT_EQ(-1,display_item(&lhead));
}

TEST(display_list,Mytest3)
{
	linked_list head;
    head.index = 0;
    head.next = NULL;
	head.data = NULL;

	char stringTest[] = "abc";
	char stringTest1[] = "def";
	char stringTest2[] = "ghi";
	
	add_to_list(&head,stringTest);
	add_to_list(&head,stringTest1);
	add_to_list(&head,stringTest2);
	
	EXPECT_EQ(3,display_list(&head));
	
	add_to_list(&head,stringTest);
	
	EXPECT_EQ(4,display_list(&head));
}


TEST(search_from_list,Mytest4)
{
	linked_list head;
    head.index = 0;
    head.next = NULL;
    head.data = NULL;

	char stringTest[] = "abc";
	char stringTest1[] = "def";
	char stringTest2[] = "ghi";
	char stringTest3[] = "1";	
	add_to_list(&head,stringTest);
	add_to_list(&head,stringTest1);
	add_to_list(&head,stringTest2);
	
	head = head->next->next->next;
	EXPECT_EQ(NULL,search_from_list(&head,stringTest3));
	EXPECT_EQ(&head,search_from_list(&head,stringTest));
}
/*
TEST(delete_from_list,Mytest5)
{
	linked_list head;
	
	char stringTest[] = "abc";
	char stringTest1[] = "def";
	char stringTest2[] = "ghi";
	
	add_to_list(&head,stringTest);
	add_to_list(&head,stringTest1);
	add_to_list(&head,stringTest2);
	
	EXPECT_EQ(2,delete_from_list(&head,1));
	EXPECT_EQ(1,delete_from_list(&head,1));
	EXPECT_EQ(-1,delete_from_list(&head,2));
}*/
