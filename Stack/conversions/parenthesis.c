#include <stdio.h>
#include <stdlib.h>

// three basic functions of a stack using linked list in a single code
typedef struct node
{
    char data;
    struct node *next;
} node;

node *top = NULL;


void push(char value)
{
    node *t = (node *) malloc(sizeof(node));
    if (t == NULL)
    {
        printf("stack overflow\n");
        return;
    }
    else
    {
        t->data = value;
        t->next = top;
        top = t;
    }
}
void pop()
{
    if (top == NULL)
    {
        printf("stack underflow\n");
        return;
    }
    else
    {
        node *t = top;
        top = top->next;
        free(t);
    }
}

void display()
{
    node *p;
    p = top;
    while (p != NULL)
    {
        printf("%d \n", p->data);
        p = p->next;
    }
}
int isbalanced(char *exp)
{
    for(int i = 0; exp[i] != '\0'; i++)
    {
        if(exp[i] == '(')
        {
            push(exp[i]);
        }
        else if (exp[i] == ')')
        {
            if (top == NULL)
            {
                return 0;
            }
            pop();
        }
    }
    if(top == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main(void)
{
    char *exp = "((a + b) * (c - d))";
    printf("%d\n",isbalanced(exp));
}
