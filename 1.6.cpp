#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int num;
    Node* next;
}*head = NULL , *tail = NULL;

struct Node *createNode(int num)
{
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->num = num;
    newNode->next = NULL;

    return newNode; 
}

void pushHead(int num)
{
    struct Node* newNode = createNode(num);

    if (!head ) head = tail = newNode;
    else 
    {
        newNode->next  = head;
        head =  newNode;
    }
}

void pushTail(int num)
{
    struct Node* newNode = createNode(num);

    if (!head) head = tail = newNode;
    else
    {
        tail->next = newNode;
        tail = newNode;
    }
}

void sort(int num)
{
    struct Node* newNode = createNode(num);
    if (!head) head = tail = newNode;
    else if (newNode->num > head->num) pushHead(num);
    else if (newNode->num < tail->num ) pushTail(num);
    else
    {
        struct Node *curr = head;
        while (curr)
        {
            if (newNode->num > curr->next->num) break;
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
        struct Node* curr = head;
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
        struct Node* curr = head;
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

void popMid(int num)
{
    if (num == head->num )
    {
        popHead();
        sort(num);
    } 
    else if (num == head->num)
    {
        popTail();
        sort(num);
    }
    else 
    {
        struct Node* curr = head;
        while (curr)
        {
           if (curr->next->num == num) break;
            curr = curr->next;
        } 
        if (!curr->next) return;
        struct Node* temp = curr->next;
        curr->next = temp->next;
        free(temp);
        temp = NULL;
        sort(num);
    }
}

void print()
{
    struct Node* curr=  head;
    while(curr)
    {
        printf("%d ", curr->num);
        curr = curr->next;
    }
    puts("");
}

int main()
{
    for (int i = 1; i<15; i++)
    pushTail(i);
    //1 2 3 4 5 6 7 8 9 10 11 12 13 14
    for (int i = 1; i<15; i++)
    popMid(i);
    print();
    return 0;
}
