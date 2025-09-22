#include <stdio.h>
#include <stdlib.h>

typedef struct stack
{
    int size;
    int top;
    int *s;
} stack;

void push(stack *st,int value)
{
    if(st->top == st->size-1)
    {
        printf("stack overflow \n");
        return;
    }
    else
    {
        st->top++;
        st->s[st->top] = value;
    }
}

void create(stack *st);
void display(stack st);

int main(void)
{
    stack st;
    create(&st);
    push(&st,10);
    push(&st,20);
    push(&st,30);
    push(&st,40);
    display(st);
}
void create(stack *st)
{
    printf("Enter the size of stack : \n");
    scanf("%d", &st->size);
    st->s = (int *) malloc(st->size * sizeof(int));
    st->top = -1;
}
void display(stack st)
{
    printf("the stack is : \n");
    for(int i = st.top; i >= 0; i--)
    {
        printf("%d \n",st.s[i]);
    }
}