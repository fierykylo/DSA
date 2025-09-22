#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} node;

node *head = NULL;

void create(int A[], int n);
void display(node *p);
int length(node *p);

void delete(node *p, int index)
{
    if (index < 1 || index > length(head))
    {
        printf("invalid index!!\n"); // condition to check if the given index is valid or not
        return;
    }
    if (index == 1)
    {
        while (p->next != head)
        {
            p = p->next;
        }
        if (p == head)
        {
            free(head);
            head = NULL;
        }
        else
        {
            p->next = head->next;
            free(head);
            head = p->next;
        }
    }
    else
    {
        for (int i = 0; i < index - 2; i++)
        {
            p = p->next;
        }
        node *q = p->next;
        p->next = q->next;
        free(q);
    }
}

int main(void)
{
    int A[] = {10, 20, 30, 40, 50, 60};
    create(A, 6);    // create circular linked list from array
    display(head);   // display the list
    delete(head, 1); // insert value 69 at index 6 (end of list)
    display(head);   // display again after insertion
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
