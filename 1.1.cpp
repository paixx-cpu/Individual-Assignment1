#include <stdio.h>
#include <stdlib.h>

struct Data1
{
    int angka1;
    Data1* next1;
}*head1 = NULL, *tail1 = NULL;

struct Data
{
    int angka;
    Data* next;
}*head = NULL, *tail = NULL;

struct Data1* initialize(int angka)
{
    struct Data1* newData = (Data1*)malloc(sizeof(Data1));

    newData->angka1 = angka;
    newData->next1 = NULL;

    return newData;
}

struct Data* createNode(int angka)
{
    struct Data* newNode = (Data*)malloc(sizeof(Data));
    
    newNode->angka = angka;
    newNode->next = NULL;

    return newNode;
}

void pushHead(int angka)
{
    struct Data* newNode = createNode(angka);

    if (!head ) head = tail = newNode;
    else 
    {
        newNode->next  = head;
        head =  newNode;
    }
}

void pushTail(int angka)
{
    struct Data* newNode = createNode(angka);

    if (!head) head = tail = newNode;
    else
    {
        tail->next = newNode;
        tail = newNode;
    }
}

void pushMid(int angka)
{
    struct Data* newNode = createNode(angka);
    if (!head) head = tail = newNode;
    else if (newNode->angka < head->angka) pushHead(angka);
    else if (newNode->angka > tail->angka ) pushTail(angka);
    else
    {
        struct Data *curr = head;
        while (curr)
        {
            if (newNode->angka < curr->next->angka) break;
            curr = curr->next;
        }
        newNode->next = curr->next;
        curr->next = newNode;
    }   
}

void pushTail1(int angka)
{
    struct Data1* newData = initialize(angka);
    if (!head1) head1 = tail1 = newData;
    else
    {
        tail1->next1 = newData;
        tail1 = newData;
    }
}

void print()
{
    struct Data* curr = head;
    while (curr)
    {
        printf("%d ", curr->angka);
        curr = curr->next;
    }
    puts("");
}

void print2()
{
    struct Data1* curr = head1;
    while (curr)
    {
        printf("%d ", curr->angka1);
        curr = curr->next1;
    }
    puts("");
}

void popHead()
{
    if (!head1) return;
    else 
    {
        struct Data1* curr = head1;
        head1 = head1->next1;
        free(curr);
        curr = NULL;
    }
}

void merge()
{
    struct Data1* curr = head1;
    while(curr)
    {
        pushMid(curr->angka1);
        curr=  curr->next1;
        popHead();
    }
}

int main()
{
    pushTail1(10);
    pushTail1(20);
    pushTail1(30);
    print2();
    pushTail(40);
    pushTail(50);
    pushTail(60);
    print();
    merge();
    print();


    return 0;
}