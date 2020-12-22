#include <stdio.h>
#include <stdlib.h>

struct Data
{
    int age;
    Data* next;
}*head = NULL , *tail = NULL;

struct Data *createNode(int age)
{
    Data *newNode = (Data*)malloc(sizeof(Data));

    newNode->age = age;
    newNode->next = NULL;

    return newNode; 
}

void pushHead(int age)
{
    struct Data* newNode = createNode(age);

    if (!head ) head = tail = newNode;
    else 
    {
        newNode->next  = head;
        head =  newNode;
    }
}

void pushTail(int age)
{
    struct Data* newNode = createNode(age);

    if (!head) head = tail = newNode;
    else
    {
        tail->next = newNode;
        tail = newNode;
    }
}

void sort(int age)
{
    struct Data* newNode = createNode(age);
    if (!head) head = tail = newNode;
    else if (newNode->age > head->age) pushHead(age);
    else if (newNode->age < tail->age ) pushTail(age);
    else
    {
        struct Data *curr = head;
        while (curr)
        {
            if (newNode->age > curr->next->age) break;
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
        struct Data* curr = head;
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
        struct Data* curr = head;
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

void popMid(int age)
{
    if (age == head->age )
    {
        popHead();
        sort(age);
    } 
    else if (age == head->age)
    {
        popTail();
        sort(age);
    }
    else 
    {
        struct Data* curr = head;
        while (curr)
        {
           if (curr->next->age == age) break;
            curr = curr->next;
        } 
        if (!curr->next) return;
        struct Data* temp = curr->next;
        curr->next = temp->next;
        free(temp);
        temp = NULL;
        sort(age);
    }
}

void print()
{
    struct Data* curr=  head;
    while(curr)
    {
        printf("%d ", curr->age);
        curr = curr->next;
    }
    puts("");
}

int main()
{
    for (int i = 1; i<6; i++)
    pushTail(i);
    for (int i = 1; i<6; i++)
    popMid(i);
    print();

    return 0;
}