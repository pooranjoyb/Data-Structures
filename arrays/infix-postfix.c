#include <stdio.h>
#include <ctype.h>
#define size 5

char stack[size];
int top=-1;
                                
void push(int a)
{	 	  	 	   	      	    	  	 	
    if(top==(size-1))
    printf("the stack is full");
    else
    {
        top++;
        stack[top]=a;
    }
}

char pop()
{
    if(top==-1)
    return -1;
    else
    {
        return stack[top--];
    }
}

int pri(char c)
{
    if(c=='^')
    return 3;
    
    else if(c=='/' || c=='*')
        return 2;
    
    else if(c=='+' || c=='-')
        return 1;
    
    else if(c=='(')
        return 0;
}

int main()                      
{	 	  	 	   	      	    	  	 	
    char ar[size];
    char *c,x;
    
    printf("Enter the inflix function: ");
    scanf("%s",ar);
    c=ar;
    while(*c != '\0')
    {                           
        if(isalnum(*c))
        printf("%c",*c);
        
        else if(*c=='(')
        push(*c);
        
        else if(*c==')')
        {
            while((x=pop()) != '(')
            {                       
            printf("%c",x);
            }
        }
        
        else
        {
            while(pri(stack[top]) >= pri(*c))
            printf("%c",pop());
            push(*c);
        }
            c++;
    }
    
    while(top!=-1)
    {
        printf("%c",pop());
    }
    
    return 0;
}	 	  	 	   	      	    	  	 	
