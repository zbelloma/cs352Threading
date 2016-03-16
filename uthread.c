#include <stdlib.h>
#include <stdio.h>

typedef struct node{
	int priorty;
	char *data;
	struct node *next;
	//void (*func)();
	//Each node should have a thread/method associated aswell
}node;

void insert(int priorty, char *info, node *root){
	node *temp;//node setup
	temp = malloc(sizeof(node));
	temp->data = info;
	temp->priorty = priorty;

	if(root->next == NULL){
	root->next = temp;
	return;
	}
	//add to list
	node *currNode = root;//add case for empty queue
	while(currNode->next != NULL){
		if(currNode->next->priorty > temp->priorty){
			break;
		}
		currNode = currNode->next;
	}
	temp->next=currNode->next;
	currNode->next = temp;
	return;
}

node *ini_pq(){
	node *root;
	root = malloc(sizeof(node));
	root->data = "root";
	root->priorty = 0;
	root->next = NULL;
	return root;
}

void printQueue(node *root){
	node *currNode = root;
	while(currNode->next != NULL){
		printf("%s\n", currNode->data);
		currNode = currNode->next;
	}
	printf("%s\n", currNode->data);
}

void uthread_init(){
	//Inilitize a priorty queue
	//node *root = ini_pq(); 
}

int main(int argc, char *argv[]){
	node *root = ini_pq();
	insert(2, "priorty 2: inserted first ", root);
	insert(1, "priorty 1: ", root);
	insert(5, "priorty 5: ", root);
	insert(2, "priorty 2: inserted second", root);
	insert(3, "priorty 3: ", root);
	printQueue(root);
	return 1;
}
