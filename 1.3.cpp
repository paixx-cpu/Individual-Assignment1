#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int idx = 0;
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

void pushTail(int age)
{
    struct Data* newNode = createNode(age);

    if (!head) head = tail = newNode;
    else
    {
        tail->next = newNode;
        tail = newNode;
    }
    idx++;
}

void printMiddle()
{
    int mid = ceil(idx/2);
    struct Data* curr = head;
    while (mid--) curr = curr->next;
    printf("%d\n", curr->age);
}

void print()
{
    struct Data* curr = head;
    while (curr)
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
    print();
    printMiddle();

    return 0;
}