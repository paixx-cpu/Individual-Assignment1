#include <stdio.h>
#include <stdlib.h>

struct Node{
    int angka;
    Node *next;
}*head=NULL, *tail=NULL;

Node *createNode(int angka){
    Node *newNode=(Node*)malloc(sizeof(Node));
    newNode->angka=angka;
    newNode->next=NULL;
    return newNode;
}
void pushHead(int angka){
	Node *temp = createNode(angka);
if(!head) { 
    head = tail = temp; 
  } else { // >= 1 node
    temp->next = head; 
    head = temp; 
  }
}
void pushTail(int angka){
    Node *temp=createNode(angka);
    if(!head){
        head=tail=temp;
    } else {
        tail->next=temp;
        tail=temp;
    }
}

int detectCycle(){
    Node *slow=head, *fast=head;
    while(slow && fast && fast->next){
        slow=slow->next;
        fast=fast->next->next;

        if(slow==fast){
            return 1;
        }
    }
    return 0;
}

int main(){
    pushHead(5);
    pushTail(105);
    pushHead(2);
    pushHead(45);
    pushHead(54);
    head->next->next->next->next->next=head;
    detectCycle();

    if(detectCycle()){
        puts("There is a cycle");
    } else {
        puts("There is no cycle");
    }
    return 0;
}
