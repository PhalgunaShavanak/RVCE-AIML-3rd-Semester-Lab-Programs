#include<stdio.h>
#include<ctype.h>

char stack[100],postfix[100];
int len=0;
int top = -1;

void push(char x)
{
    stack[++top] = x;
}

char pop()
{
    if(top == -1)
	   return -1;
    else
	   return stack[top--];
}
char peek()
{
	if(top == -1)
	   return -1;
    else
	   return stack[top];
}

int priority(char x)
{
    if(x == '(')
	   return 0;
    if(x == '+' || x == '-')
	   return 1;
    if(x == '*' || x == '/')
	   return 2;

    return 0;
}
void ConvertExp(char exp[])
{

    char *e, x,tmp;
    e = exp;

    while(*e != '\0')
    {
		if(isalnum(*e))
		{
		   postfix[len++]=*e;
		}

		else if(*e == '(')
			push(*e);
		else if(*e == ')')
		{
			while((x = pop()) != '(')
			{
				postfix[len++]=x;
			}
	   }
	   else
	   {
			while(priority(peek()) >= priority(*e))
			{
				tmp=pop();
				postfix[len++]=tmp;
			}

		  push(*e);
	   }
	   e++;
    }

    while(top != -1)
    {
	   tmp=pop();
	   postfix[len++]=tmp;
    }
    postfix[len]='\0';
	}

void EvalPostfix(char postfix[])
{
    int i;
    char ch;
    int val,num;
    int A, B;
    printf("Enter values \n");

    /* evaluate postfix expression */
    for (i = 0; postfix[i]!='\0'; i++)
	{
		ch = postfix[i];
		if (isalnum(ch))
		{
		  printf("Enter Value of %c = ", ch);
		  scanf("%d",&num);
		  push(num);
		}
		else if (ch == '+' || ch == '-' || ch == '*' || ch == '/')
		{
		  /* we saw an operator
* pop top element A and next-to-top elemnet B
* from stack and compute B operator A
*/
		  A = pop();
		  //printf("Stack val %d\n",A);
		  B = pop();
		  //printf("Stack val %d\n",B);

		  switch (ch) /* ch is an operator */
		  {
		  case '*':
			 val = B * A;
			 break;

		  case '/':
			 val = B / A;
			 break;

		  case '+':
			 val = B + A;
			 break;

		  case '-':
			 val = B - A;
			 break;
		  }

		  /* push the value obtained above onto the stack */
		  push(val);
	   }
    }
    printf(" \n Result of expression evaluation : %d \n", pop());
}

int main()
{
	char expression[100];
	
	printf("Enter the expression : ");
	scanf("%s",expression);
	printf("\n");
	ConvertExp(expression);
	printf("Postfix Expression is %s \n",postfix);
	EvalPostfix(postfix);
	return 0;
}