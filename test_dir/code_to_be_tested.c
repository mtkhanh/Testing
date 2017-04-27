#include <stdio.h>
#include "ostring.h"
#include <stdlib.h>

int my_strlen(char *c)
{
    char *p = c;
    //Loop over the data in s.  
    while (*p != '\0')
    //While p reach to the null character increase address of p
        p++;
    return (int)(p-c);
}
	
void mystrcpy(char *s,char *d)
{
	//While s reach to the null character increase , take the value of s
	while ((*d++ = *s++) != '\0'){}
}	

int mystrcmp (char *s,char *d)
{	
    int count = 1;
	for(; *s == *d; ++s, ++d){
		count++;
        if(*s == '\0')
            return 0;
	}
    return *(char *)s < *(char *)d ? (0-count) : (count);
}

int str2upper(char *s)
{
	int i = 0;
	int count = 0;
	for(; s[i]; ++i)
	{
        if((s[i] >= 'a') && (s[i] <= 'z'))
		{
            s[i] = s[i] + 'A' - 'a';
			count++;
        }
		else
            s[i] = s[i];
    }
    s[i] = '\0';
	return count;
}

int str2lower_(char *s)
{
	int i = 0;
	int count = 0;
	for(; s[i]; ++i){ 		
        if((s[i] >= 'A') && (s[i] <= 'Z'))
		{
            s[i] = s[i] - 'A' + 'a';
			count++;
		}
        else
            s[i] = s[i];
    }
    s[i] = '\0';
	return count;

}

int str_strip_numbers(unsigned char *s)
{
	int i = 0;
	int j = 0;
	char *d = (char*)malloc (my_strlen((char *)s)+1);
	
	for(; s[i]; i++)
	{
		if((s[i] < '0') || (s[i] > '9')){	
			d[j] = s[i];
			j++;
		}
	
	}	d[j]='\0';
	return my_strlen(d) ;
	
}

 char * strdupl( char *s)
{
	char *d = ( char*)malloc (my_strlen(s) + 1);   
    if (d == NULL) return NULL;          
    mystrcpy (s,d);                    
    return d;                            
}