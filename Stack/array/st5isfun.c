#include <stdio.h>
#include <stdlib.h>
// two functions are being implemented here the first one is to check if stack is empty and then another one to see if a stack is full or not
typedef struct stack
{
    int size;
    int top;
    int *s;
}stack;

int isempty(stack st)
{
    if(st.top == -1)
    {
        return 1;
    }
    return 0;
}

int isfull(stack st)
{
    return (st.top == st.size - 1); // returns 1 if true 0 if false
}

// another function being implented here is the function to check the top element of stack
int stacktop(stack st)
{
    if(isempty(st))
    {
        return 0;
    }
    else
    {
        return st.s[st.top];
    }
}

void create(stack *st);
void display(stack st);
void push(stack *st,int value);

int main(void)
{
    stack st;
    create(&st);
    push(&st, 10);
    push(&st, 20);
    push(&st, 30);
    push(&st, 40);
    printf("is stack empty %d\n", isempty(st));
    printf("stack full or not ? \n%d \n", isfull(st));
    push(&st, 50);
    printf("the top value of stack is %d \n", stacktop(st));
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
    for (int i = st.top; i >= 0; i--)
    {
        printf("%d \n",st.s[i]);
    }
}
void push(stack *st,int value)
{
    if (st->top == st->size-1)
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