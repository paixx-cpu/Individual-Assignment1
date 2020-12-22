#include <stdio.h>
#include <stdlib.h>

struct node
{
    int number;
    node* next;
}*head = NULL , *tail = NULL;

struct node *createNode(int number)
{
    node *newNode = (node*)malloc(sizeof(node));

    newNode->number = number;
    newNode->next = NULL;

    return newNode; 
}


void pushHead(int number)
{
    struct node* newNode = createNode(number);

    if (!head ) head = tail = newNode;
    else 
    {
        newNode->next  = head;
        head =  newNode;
    }
}

void pushTail(int number)
{
    struct node* newNode = createNode(number);

    if (!head) head = tail = newNode;
    else
    {
        tail->next = newNode;
        tail = newNode;
    }
}

void pushMid(int number)
{
    struct node* newNode = createNode(number);
    if (!head) head = tail = newNode;
    else if (newNode->number <= head->number) pushHead(number);
    else if (newNode->number >= tail->number ) pushTail(number);
    else
    {
        struct node *curr = head;
        while (curr)
        {
            if (newNode->number < curr->next->number) break;
            curr = curr->next;
        }
        newNode->next = curr->next;
        curr->next = newNode;
    }   
}
void popHead()
{
    if (!head) return;
    else 
    {
        struct node* curr = head;
        head = head->next;
        free(curr);
        curr = NULL;
    }
}
void popTail()
{
    if (!head) return;
    else if (head == tail)
    {
        free(head);
        head = tail = NULL;
    }
    else
    {
        struct node* curr = head;
        while (curr)
        {
            if (curr->next = tail) break;
            curr = curr->next;
        }
        free(tail);
        tail = curr;
        tail->next = NULL;
    }
}

void popMid(int number)
{
    if (!head) return;
    else if (number == head->number ) popHead();
    else if (number == tail->number) popTail();
    else 
    {
        struct node* curr = head;
        while (curr)
        {
           if (curr->next->number == number) break;
            curr = curr->next;
        } 
        if (!curr->next) return;
        struct node* temp = curr->next;
        curr->next = temp->next;
        free(temp);
        temp = NULL;
    }
}


void removeD()
{
    struct node* curr = head;
    while(curr != NULL)
    {
        if (curr->number == curr->next->number)
        {
            if (!curr->next) return;
            struct node* temp = curr->next;
            curr->next = temp->next;
            free(temp);
            temp = NULL;
        }
        curr = curr->next;
    }
}

void print()
{
    struct node* curr= head;
    while (curr)
    {
        printf("%d ", curr->number);
        curr = curr->next;
    }
    puts("");
}

int main()
{
    for (int i=1 ; i<6; i++)
    pushTail(i);
    //1 2 3 4 5 
    pushMid(3);
    // 1 2 3 3 4 5 
    pushTail(5);
    // 1 2 3 3 4 5 5
    pushMid(2);
    //1 2 3 3 2 4 5 5 ( semua komen tc unsorted )

    print();
    removeD();
    print();



    return 0;
}
