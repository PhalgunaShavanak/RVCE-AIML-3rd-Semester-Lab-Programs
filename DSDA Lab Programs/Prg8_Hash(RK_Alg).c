#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int m, n;
char text[100], pat[100];
int hasher(char st[])
{
    	 int val = st[0];
	 int i;
	 for (i = 1; i < n; i++)
	 {
		 val -= st[i];
 	 }
 return val;
}

void searching()
{
	 int i, j;
	 char a2[100];
	 printf("enter the text:");
	 scanf("%[^\n]", text);
	 printf("enter the pattern:");
	 scanf(" %[^\n]", pat);
	 m = strlen(text);
	 n = strlen(pat);
	 if (m < n)
	 {
		 printf("pattern is too long:");
 	    	 exit(0);
 	 } 
 	else
 	{
 		for (i = 0; i < m; i++)
 		{
 			if (text[i] == pat[0])
 			{
 				for (j = 0; j < n; j++)
 				{
 					a2[j] = text[i + j];
 				}
 				
				if (hasher(a2) == hasher(pat))
 				{
 					printf("the pattern is found at %d\n", i + 1);
 				}
 			}
 		}
	}
}

int main()
{
	 searching();
	 return 0;
}