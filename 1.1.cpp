#include <stdio.h>
#include <stdlib.h>

struct firstData
{
    int angka1;
    firstData* next1;
}*head1 = NULL, *tail1 = NULL;

struct Data
{
    int angka;
    Data* next;
}*head = NULL, *tail = NULL;

struct firstData* initialize(int angka)
{
    struct firstData* newData = (firstData*)malloc(sizeof(firstData));

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
    struct firstData* newData = initialize(angka);
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
    struct firstData* curr = head1;
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
        struct firstData* curr = head1;
        head1 = head1->next1;
        free(curr);
        curr = NULL;
    }
}

void merge()
{
    struct firstData* curr = head1;
    while(curr)
    {
        pushMid(curr->angka1);
        curr=  curr->next1;
        popHead();
    }
}

int main()
{
    pushTail1(5);
    pushTail1(25);
    pushTail1(35);
    print2();
    pushTail(1);
    pushTail(2);
    pushTail(3);
    print();
    merge();
    print();


    return 0;
}
