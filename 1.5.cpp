#include<stdio.h>
#include<stdlib.h>
struct Node { 
	int angka; 
	struct Node* next; 
} *head, *tail;

Node *createNode ( int angka){
	Node *newNode = (Node*)malloc(sizeof(Node));
	newNode->angka = angka;
	newNode->next=NULL;
	return newNode;
}

void printDariAkhir(int angka){
	int len = 0;
	struct Node *temp = head;
	int i = 0;
	while(temp != NULL){
		temp = temp->next;
		len++;
	}
	if(angka>len){
		return;
	}
	temp = head;
	for (i = 1; i < len - angka + 1; i++) 
		temp = temp->next;
		
	printf("%d", temp->angka);
}

void printAll(){
	Node *curr = head;
	while(curr){
		printf("%d ", curr->angka);
		curr = curr->next;
	}
	printf("\n");
}

void pushHead(int angka){
	Node *temp = createNode(angka);
	
	if(head == NULL){
		head =  temp;
	}
	else{
		Node *curr = head;
		while(curr->next != NULL){
			curr = curr->next;
		}
		curr->next = temp;
	}
}

void disposeMemory(){
	Node *temp;
	while(head){
		temp = head;
		head = head->next;
		free(temp);
	}
}

int main(){
	pushHead(1);
	pushHead(2);
	pushHead(3);
	printAll();
	printDariAkhir(1);
	disposeMemory();
	return 0;
}
