# include <gtest/gtest.h>
# include "ostring.h"

 TEST(strlength,string){
  char c[]="hello";
 int d= my_strlen(c) ;
 EXPECT_EQ(5,d);

 }
 TEST(strlength,string_num){
  char num[]="hello123";
 int d= my_strlen(num) ;
 EXPECT_EQ(8,d);

 }
 TEST(strlength,string_character){
  char st_cha[]="hell@!";
 int cha= my_strlen(st_cha) ;
 EXPECT_EQ(6,cha);

 }
 TEST(strlength,string_empty){
  char emp[]=" ";
 int empty= my_strlen(emp) ;
 EXPECT_EQ(1,empty);

 }
 /*********************************************/
 TEST(strcpy,nulldest){
	 char src[]="ascdavda";
	 char dest[]="";
	 mystrcpy(dest,src);
ASSERT_STREQ(src,dest);
 }

 TEST(strcpy,nullsrc){
	 char src[]=" ";
	 char dest[]="asc";
 mystrcpy(dest,src);
 ASSERT_STREQ(src, dest);
 
 }
 TEST(strcpy,samesize){
	  char src[]="qwe";
	 char dest[]="asc";
	 mystrcpy(dest,src);
 ASSERT_STREQ(src,dest);
 
 }
 TEST(strcpy,diffrentarraysize){ 
  char src[10]="asdfghjk";
	 char dest[5]=" ";
  mystrcpy(dest,src);
 ASSERT_STREQ(src,dest);

 }

 TEST(strcpy,diffrentcharacter){ 
  char src[]="asdf12@ghjk";
	 char dest[]="help ";
  mystrcpy(dest,src);
 ASSERT_STREQ(src,dest);

 }
 /**********************************************/
 
 TEST(strcmp,postitve){
 	char src[]="Germa66";
  	char dest[]="apple";
  	int pos= mystrcmp(src,dest) ;
 EXPECT_EQ(1,pos);

 }
 TEST(strcmp,negative){

 char src[]=" ";
  	char dest[]="ABCD";
  	char s[]="HELP";
 char d[]="z";
  	int neg= mystrcmp(src,dest) ;
 EXPECT_EQ(-1,neg);
 
 int trya=mystrcmp(s,d);
 EXPECT_EQ(-1,trya);
 }
 TEST(strcmp,zero){
 	char src[]="ABCD";
  	char dest[]="ABCD";
  	int zero= mystrcmp(src,dest) ;
 EXPECT_EQ(0,zero);
 
 }
 /**********************************************/
TEST(str2upper,empty){
	char src[]=" ";
	int empty=str2upper(src);
	 EXPECT_EQ(0,empty);
 
 }
 TEST(str2upper,string_number){
 char src[]="help123AT ";
	int stnum=str2upper(src);
	 EXPECT_EQ(4,stnum);
 }
 TEST(str2upper,allUpperCase){
 	char src[]="WELCOMETOMACHINE ";
	int empty=str2upper(src);
	 EXPECT_EQ(0,empty);
 
 }
 TEST(str2upper,string_character){
 	char src[]="WEL@come";
	int cha=str2upper(src);
	 EXPECT_EQ(4,cha);
 
 }
  /**********************************************/
TEST(str2lower,empty){
 char src[]=" ";
	int empty=str2lower_(src);
	 EXPECT_EQ(0,empty);
 }
 TEST(str2lower,allLowerCase){
 char src[]="letsseethe ";
	int empty=str2lower_(src);
	 EXPECT_EQ(0,empty);
 }
 TEST(str2lower,string_number){
 char src[]=" OCTAVARIUM24";
	int empty=str2lower_(src);
	 EXPECT_EQ(10,empty);
 }
 TEST(str2lower,string_characer){
 char src[]=" BLink@!";
	int empty=str2lower_(src);
	 EXPECT_EQ(2,empty);
 }
  /**********************************************/
 TEST(stripnumber,empty){
 	unsigned char src[]="";
	int empty=str_strip_numbers(src);
	 EXPECT_EQ(0,empty);
 }
 TEST(stripnumber,numberandstring){
 	unsigned char src[]="BLINK182";
	int numb=str_strip_numbers(src);
	 EXPECT_EQ(3,numb);
 }
  /**********************************************/
 TEST(strduplicate, empty){
 	char s[]="";
 	char *s1;
 	s1=strdupl(s);
 	ASSERT_STREQ(s,s1);
 }
 
 TEST(strduplicate, string){
 	char s[]="illumanation";
 	char *s1;
 	s1=strdupl(s);
 	ASSERT_STREQ(s,s1);
 }
 


 
 