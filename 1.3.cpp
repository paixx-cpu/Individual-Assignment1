#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int idx = 0;
struct Data
{
    int angka;
    Data* next;
}*head = NULL , *tail = NULL;

struct Data *createNode(int angka)
{
    Data *newNode = (Data*)malloc(sizeof(Data));

    newNode->angka = angka;
    newNode->next = NULL;

    return newNode; 
}
void pushHead(int angka) {

  Data *temp = createNode(angka);

  if(!head) { 
    head = tail = temp;
  } else { 
    temp->next = head; 
    head = temp; 
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
    idx++;
}

void printMiddle()
{
    int mid = ceil(idx/2);
    struct Data* curr = head;
    while (mid--) curr = curr->next;
    printf("%d\n", curr->angka);
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

int main()
{
    for (int i = 1; i<6; i++)
    pushTail(i);
    pushHead(2);
    pushTail(2);
    print();
    printMiddle();

    return 0;
}
