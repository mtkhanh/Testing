#include <gtest/gtest.h>
#include "ostring.h"
#include <string.h>
TEST(my_strlen, MyTEst)
{
	char test_string1[]= "dasdsa" ;
	char test_string2[]= "" ;
	
	EXPECT_EQ(6,my_strlen(test_string1));
	EXPECT_EQ(0,my_strlen(test_string2));
}

TEST(mystrcpy, MyTEst2)
{
	char test_string1[] ="";
	char test_string2[] ="abc";
	char test_string3[] ="";
	
	mystrcpy(test_string2,test_string1);
	EXPECT_EQ(0,strcmp((const char*)test_string1,(const char*)test_string2));
	
	mystrcpy(test_string1,test_string3);
	EXPECT_EQ(0,strcmp((const char*)test_string1,(const char*)test_string3));
}

TEST(mystrcmp,MyTEst3)
{
	char test_string1[] = "abc";
	char test_string2[] = "abd";
	char test_string3[] = "def";
	
	EXPECT_EQ(-3,mystrcmp(test_string1,test_string2));
	EXPECT_EQ(-1,mystrcmp(test_string1,test_string3));
	EXPECT_EQ(3,mystrcmp(test_string2,test_string1));
}

TEST(str2upper,MyTEst4)
{
	char test_string[] = "ABCDEF";
	char test_string1[] = "abcdef";
	
	EXPECT_EQ(0,str2upper(test_string));
	EXPECT_EQ(6,str2upper(test_string1));
}

TEST(str2lower_,MyTEst4)
{	
	char test_string[] = "ABCDEF";
	char test_string1[] = "abcdef";
	
    EXPECT_EQ(6,str2lower_(test_string));
    EXPECT_EQ(0,str2lower_(test_string1));
}

TEST(str_strip_numbers,MyTEst5)
{
	unsigned char test_string[] = "a1231321";
	unsigned char test_string1[] = "a1b2c3";
	
	EXPECT_EQ(1,str_strip_numbers(test_string));
	EXPECT_EQ(3,str_strip_numbers(test_string1));
}

TEST(strdupl, MyTEst6)
{
	char* rel;
	char test_string[] = "abcxyz";
	char test_string1[] = "";
	
	rel = strdupl((char*)test_string);
	EXPECT_EQ(0,mystrcmp(test_string,rel));
	
	rel = strdupl((char*)test_string1);
	EXPECT_EQ(0,mystrcmp(test_string1,rel));
}


