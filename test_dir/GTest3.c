#include <gtest/gtest.h>
#include "ostring.h"
#include <string.h>

TEST (mystrlen,MyTEst1){
	char str[] = "abcd";
	int length;

	length = my_strlen(str);
	EXPECT_EQ(4,length);	
}

TEST (mystrcpy,MyTEst2){
	char str[]="abcd";
	char str2[]="abc";

	mystrcpy(str,str2);
	EXPECT_EQ(0,strcmp("abcd",str2));
}

TEST (mystrcmp,MyTEst3){
	char str[]="abcd";
	int cmp;

	cmp= mystrcmp(str,"abcd");
	EXPECT_EQ(0,cmp);
	cmp=mystrcmp(str,"abc");
	EXPECT_EQ(4,cmp);
	cmp=mystrcmp(str,"abcf");
	EXPECT_EQ(-4,cmp);
}

TEST (str2upper,Mytest4){
	char str[]="abcd";
	int change;

	change = str2upper(str);
	EXPECT_EQ(4,change);
	EXPECT_EQ(0,strcmp("ABCD",str));
}

TEST (str2lower,Mytest5){
	char str[]="ABCS";
	int change;

	change= str2lower(str);
	EXPECT_EQ(4,change);
	EXPECT_EQ(0,strcmp("abcs",str));
}

TEST (str_strip_numbers,Mytest6){
	unsigned char str[]="ac12f";
	unsigned char str2[]="acf";
	int number;
	number = str_strip_numbers(str);
	EXPECT_EQ(2,number);
	EXPECT_EQ(0,strcmp((char*)str2,(char *)str));
}

TEST (strdupl,Mytest7){
	char str[]="abc";
	char*  str2;

	str2= strdupl((char *)str);
	EXPECT_EQ(0, strcmp("abc",str2));
}

