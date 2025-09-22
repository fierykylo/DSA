#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next; // pointer to the next node (circular linked list)
} node;

node *head = NULL; // global head pointer (points to first node)

// Function declarations
void create(int A[], int n);
void display(node *h);
int length(node *h);
void insert(node *p, int index, int value);

int main(void)
{
    int A[] = {10, 20, 30, 40, 50, 60};
    create(A, 6);        // create circular linked list from array
    display(head);       // display the list
    insert(head, 6, 69); // insert value 69 at index 6 (end of list)
    display(head);       // display again after insertion
}

void create(int A[], int n)
{
    node *t, *last;
    // create first node
    head = (node *) malloc(sizeof(node));
    head->data = A[0];
    head->next = head; // first node points to itself (circular)
    last = head;

    // create remaining nodes
    for (int i = 1; i < n; i++)
    {
        t = (node *) malloc(sizeof(node));
        t->data = A[i];
        t->next = head; // new node points back to head
        last->next = t; // last node points to new node
        last = t;       // move last forward
    }
}

void display(node *h)
{
    // traverse circular list using do-while (so head prints once)
    do
    {
        printf("%d-> ", h->data);
        h = h->next;
    }
    while (h != head); // stop once we loop back to head
    printf("\n");
}

int length(node *h)
{
    if (head == NULL) // empty list check
    {
        return 0;
    }
    int len = 0;
    // count nodes until we return to head
    do
    {
        len++;
        h = h->next;
    }
    while (h != head);
    return len;
}

void insert(node *p, int index, int value)
{
    // check for invalid index
    if (index < 0 || index > length(head))
    {
        printf("Invalid index \n");
        return;
    }

    node *t;
    t = (node *) malloc(sizeof(node)); // new node
    t->data = value;
    t->next = NULL;

    if (index == 0) // inserting at the beginning
    {
        if (head == NULL) // if list is empty
        {
            head = t;
            t->next = head; // self loop
        }
        else
        {
            // move to last node (whose next = head)
            while (p->next != head)
            {
                p = p->next;
            }
            p->next = t;    // last node points to new node
            t->next = head; // new node points to old head
            head = t;       // update head to new node
        }
    }
    else // inserting at position > 0
    {
        // move p to node just before insertion position
        for (int i = 0; i < index - 1; i++)
        {
            p = p->next;
        }
        t->next = p->next; // new node points to next node
        p->next = t;       // previous node points to new node
    }
}
