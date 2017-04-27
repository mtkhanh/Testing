#include <gtest/gtest.h>
#include "ostring.h"
#include <string.h>


/*
 * my_strlen
 */
TEST(StringLengthTest,SpecialCharacterInStringInput_NormalReturn)
{
  char myStr[100] = "";

  strcpy(myStr,"");
  EXPECT_EQ(0,my_strlen(myStr));

  strcpy(myStr," ");
  EXPECT_EQ(1,my_strlen(myStr));

  strcpy(myStr,"@$*");
  EXPECT_EQ(3,my_strlen(myStr));

  /*
  strcpy(myStr,"§");
  EXPECT_EQ(-1,my_strlen(myStr));

  strcpy(myStr,"\0");  
  EXPECT_EQ(-1,my_strlen(myStr));

  strcpy(myStr,"\n");
  EXPECT_EQ(-1,my_strlen(myStr));

  strcpy(myStr,"@!# ¤");
  EXPECT_EQ(-1,my_strlen(myStr));
  */
}

TEST(StringLengthTest,NormalStringInput_NormalReturn)
{
  char myStr[100] = "";

  strcpy(myStr,"a");
  EXPECT_EQ(1,my_strlen(myStr));

  strcpy(myStr,"aa1aa");
  EXPECT_EQ(5,my_strlen(myStr));

  strcpy(myStr,"aaa1aaa5aa");
  EXPECT_EQ(10,my_strlen(myStr));
}
  

/*
 * mystrcpy
 */
TEST(StringCopyTest,SpecialCharacterInStringInput_NormalReturn)
{
  char myStr[100] = "";
  char dst[100] = "";

  strcpy(myStr,"@*$**");
  mystrcpy(myStr,dst);  
  EXPECT_STREQ(dst,myStr);
 
  strcpy(myStr,"");
  mystrcpy(myStr,dst);  
  ASSERT_STREQ(myStr,dst);

  
  strcpy(myStr," ");
  mystrcpy(myStr,dst);  
  ASSERT_STREQ(myStr,dst);

  
  strcpy(myStr,"§");
  mystrcpy(myStr,dst);  
  ASSERT_STREQ(myStr,dst);
  
  strcpy(myStr,"@!# ¤*");
  mystrcpy(myStr,dst);  
  ASSERT_STREQ(myStr,dst);  
  
}

TEST(StringCopyTest,NormalStringInput_NormalReturn)
{
  char myStr[100] = "";
  char dst[100] = "";


  strcpy(myStr,"aaaaa");
  mystrcpy(myStr,dst);  
  ASSERT_STREQ(myStr,dst);

  strcpy(myStr,"123adas13dasdasd12321321dadasd");
  mystrcpy(myStr,dst);  
  ASSERT_STREQ(myStr,dst);
 
}

/*
 * mystrcmp
 */
TEST(StringCompareTest,EqLengthStringInput_NormalPositiveReturn)
{
  char str1[100] = "";
  char str2[100] = "";

  strcpy(str1,"a");  strcpy(str2,"b");
  EXPECT_EQ(mystrcmp(str1,str2),1);

  strcpy(str1,"a12@");  strcpy(str2,"a12a");
  EXPECT_EQ(mystrcmp(str1,str2),4);
  
  strcpy(str1,"a12@1111");  strcpy(str2,"a12a1111");
  EXPECT_EQ(mystrcmp(str1,str2),4);
}

TEST(StringCompareTest,DifLengthStringInput_NormalPositiveReturn)
{
  char str1[100] = "";
  char str2[100] = "";

  strcpy(str1,"a");  strcpy(str2,"aa");
  EXPECT_EQ(mystrcmp(str1,str2),2);
  
  strcpy(str1,"b");  strcpy(str2,"cd");
  EXPECT_EQ(mystrcmp(str1,str2),1);

  strcpy(str1,"a12@aa");  strcpy(str2,"a12aaa");
  EXPECT_EQ(mystrcmp(str1,str2),4);

  strcpy(str1,"a12@aaa");  strcpy(str2,"a12aa");
  EXPECT_EQ(mystrcmp(str1,str2),4);
}


TEST(StringCompareTest,EqLengthStringInput_NormalNegativeReturn)
{
  char str1[100] = "";
  char str2[100] = "";

  strcpy(str1,"b");  strcpy(str2,"a");
  EXPECT_EQ(mystrcmp(str1,str2),-1);

  strcpy(str1,"a12a");  strcpy(str2,"a12@");
  EXPECT_EQ(mystrcmp(str1,str2),-4);
    
  strcpy(str1,"a12a1111");  strcpy(str2,"a12@1111");
  EXPECT_EQ(mystrcmp(str1,str2),-4);
}

TEST(StringCompareTest,DifLengthStringInput_NormalNegativeReturn)
{
  char str1[100] = "";
  char str2[100] = "";

  strcpy(str1,"aa");  strcpy(str2,"a");
  EXPECT_EQ(mystrcmp(str1,str2),-2);
  
  strcpy(str1,"cd");  strcpy(str2,"b");
  EXPECT_EQ(mystrcmp(str1,str2),-1);

  strcpy(str1,"a12aaa");  strcpy(str2,"a12@a");
  EXPECT_EQ(mystrcmp(str1,str2),-4);

  strcpy(str1,"a12aa");  strcpy(str2,"a12@aa");
  EXPECT_EQ(mystrcmp(str1,str2),-4);
}


TEST(StringCompareTest,NormalStringInput_ZeroReturn)
{
  char str1[100] = "";
  char str2[100] = "";

  strcpy(str1,"abcdefb");  strcpy(str2,"abcdefb");
  EXPECT_EQ(mystrcmp(str1,str2),0);

  strcpy(str1,"a@@@12hjjasdkjashdkjashdkjh2kj3123a");  strcpy(str2,"a@@@12hjjasdkjashdkjashdkjh2kj3123a");
  EXPECT_EQ(mystrcmp(str1,str2),0);

}




/*
 * str2upper
 */
TEST(String2UpperTest,NormalStringInput_NormalReturn)
{
  char str[100] = "";

  strcpy(str,"a");
  ASSERT_EQ(str2upper(str),1);

  strcpy(str,"A");
  ASSERT_EQ(str2upper(str),0);

  strcpy(str,"AAA");
  ASSERT_EQ(str2upper(str),0);

  strcpy(str,"AaaaA");
  ASSERT_EQ(str2upper(str),3);

  strcpy(str,"AAzNzzNzzN");
  ASSERT_EQ(str2upper(str),5);
}



/*
 * str2lower
 */
TEST(String2LowerTest,NormalStringInput_NormalReturn)
{
  char str[100] = "";

  strcpy(str,"A");
  ASSERT_EQ(str2lower_(str),1);

  strcpy(str,"a");
  ASSERT_EQ(str2lower_(str),0);

  strcpy(str,"ljafdsfldjslfjdlasfjlajfldsjfljdlsfj");
  ASSERT_EQ(str2lower_(str),0);

  strcpy(str,"AaasjdklasjdkljasZjasdklasdkljsaaA");
  ASSERT_EQ(str2lower_(str),3);

  strcpy(str,"AAzNzzNzzNjsadjdlasjd");
  ASSERT_EQ(str2lower_(str),5);
}




/*
 * str_strip_numbers
 */
TEST(StringStripNumbersTest,NormalStringInput_NormalReturn)
{
  char str[100] = "";

  strcpy(str,"A"); 
  ASSERT_EQ(str_strip_numbers((unsigned char *)str),0);
  
  strcpy(str,"A0912121aaa121aaa");
  ASSERT_EQ(str_strip_numbers((unsigned char *)str),10);
}


TEST(StringStripNumbersTest,SpecialCharacterStringInput_NormalReturn)
{
  char str[100] = "";

  strcpy(str,"@2");
  ASSERT_EQ(str_strip_numbers((unsigned char *)str),1);

  
  strcpy(str,"A@091$212!1a@aa121aaa");
  ASSERT_EQ(str_strip_numbers((unsigned char *)str),10);

  strcpy(str,"A09@@@@aaa");
  ASSERT_EQ(str_strip_numbers((unsigned char *)str),2);

}


/*
 * strupl
 */
TEST(StringDuplicateTest,NormalStringInput_NormalReturn)
{
  char myStr[100] = "";

  char* newStr;

  strcpy(myStr,"aloha");
  newStr = strdupl(myStr);

  ASSERT_NE(newStr,myStr);
  ASSERT_STREQ(newStr,myStr);

  
  strcpy(myStr,"This is a test string, let's see how it works");
  newStr = strdupl(myStr);

  ASSERT_NE(newStr,myStr);
  ASSERT_STREQ(newStr,myStr);  
  
}

TEST(StringDuplicateStripNumbersTest,SpecialCharacterStringInput_NormalReturn)
{
char myStr[100] = "";

  char* newStr;

  strcpy(myStr,"This contains special characters likes @ $ ! * &* ()");
  newStr = strdupl(myStr);

  ASSERT_NE(newStr,myStr);
  ASSERT_STREQ(newStr,myStr); 
}

