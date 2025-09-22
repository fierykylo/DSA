#include <stdio.h>
#include <stdlib.h>

// Define the stack structure
typedef struct stack
{
    int size; // maximum size of the stack
    int top;  // index of the top element (starts at -1 when empty)
    int *s;   // dynamic array to hold stack elements
} stack;

// Function prototypes
void create(stack *st);          // create stack with given size
void display(stack st);          // display all elements in stack
void push(stack *st, int value); // push an element on top
void pop(stack *st);             // pop/remove the top element
void peek(stack *st, int pos);   // look at element at a given position
int isempty(stack st);           // check if stack is empty
int isfull(stack st);            // check if stack is full
int stacktop(stack st);          // return top element of stack

int main(void)
{
    stack st;
    create(&st); // initialize stack

    // Push some elements
    push(&st, 10);
    push(&st, 20);
    push(&st, 30);
    push(&st, 40);
    push(&st, 50);
    

    display(st); // show contents
    
    // utility functions
    peek(&st,3);
    printf("is stack empty %d\n", isempty(st));
    printf("stack full or not ? \n%d \n", isfull(st));
    printf("the top value of stack is %d \n", stacktop(st));

    // Pop elements (remove from top)
    pop(&st);
    pop(&st);

    display(st); // show stack after popping
}

// Create a stack (dynamic array allocation)
void create(stack *st)
{
    printf("Enter the size of stack : \n");
    scanf("%d", &st->size);                         // user defines stack capacity
    st->s = (int *) malloc(st->size * sizeof(int)); // allocate memory
    st->top = -1;                                   // empty stack initialized
}

// Display elements from top to bottom
void display(stack st)
{
    printf("the stack is : \n");
    for (int i = st.top; i >= 0; i--) // start from top -> 0
    {
        printf("%d \n", st.s[i]);
    }
}

// Push = add new element on top of stack
void push(stack *st, int value)
{
    if (st->top == st->size - 1) // check overflow
    {
        printf("stack overflow \n");
        return;
    }
    else
    {
        st->top++;              // move top forward
        st->s[st->top] = value; // insert new element
    }
}

// Pop = remove element from top of stack
void pop(stack *st)
{
    if (st->top == -1) // empty check
    {
        printf("stack underflow \n");
        return;
    }
    else
    {
        st->top--; // logically remove top element
    }
}

// Peek = look at element at a given position (1-based from top)
void peek(stack *st, int pos)
{
    int x = st->top - pos + 1; // formula to find index
    if (x < 0)                 // if invalid position
    {
        printf("invalid positon");
    }
    else
    {
        printf("%d\n", st->s[x]); // print element at pos
    }
}

// Check if stack is empty
int isempty(stack st)
{
    if (st.top == -1)
    {
        return 1; // true
    }
    return 0; // false
}

// Check if stack is full
int isfull(stack st)
{
    return (st.top == st.size - 1); // returns 1 if true 0 if false
}

// Return the top element of stack
int stacktop(stack st)
{
    if (isempty(st)) // empty stack check
    {
        return 0; // return 0 if stack is empty
    }
    else
    {
        return st.s[st.top]; // return actual top element
    }
}
