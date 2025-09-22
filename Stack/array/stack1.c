#include <stdio.h>
#include <stdlib.h>

// basic stack function to create and display a stack
// this is basically stack as an abstract data type

typedef struct stack
{
    int size;
    int top;
    int *s;
} stack;

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
int main(void)
{
    stack st;
    create(&st);
}