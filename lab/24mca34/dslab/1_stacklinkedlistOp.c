#include<stdio.h>
#include<stdlib.h>
struct Node {
	int data;
	struct Node *next;

};

struct Node* createNode(int data){
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	if(!newNode){
		printf("Memory error\n");
		return NULL;
	}
	newNode->data = data;
	newNode->next = NULL;
	return newNode;
}


int isEmpty(struct Node* top){
	return top == NULL;
}


void push(struct Node** top, int data){
	struct Node* newNode = createNode(data);
	if(!newNode){
	printf("stack overflow\n");
	return;
	}
	newNode->next = *top;
	*top = newNode;
	printf("%d pushed to stack\n",data);
}

int pop(struct Node** top){
	if(isEmpty(*top)){
	printf("stackunderflow\n");
	return -1;
	}
	struct Node* temp =  *top;
	int popped = temp->data;
	*top = (*top)->next;
	free(temp);
	return popped;
}

void display(struct Node* top){
	if(isEmpty(top)){
		printf("stack is empty\n");
printf("\n");

		return;
	}
struct Node* temp = top;
printf("stack items\n");
while(temp!= NULL){
	printf("%d ->",temp->data);
	temp = temp-> next;
}
printf("NULL\n");
}

void search(struct Node* top,int key){
	if(isEmpty(top)){
		printf("stack is empty\n");
printf("\n");

		return;
}
struct Node* temp = top;
int position = 1;
while(temp != NULL){
	if(temp->data == key){
		printf("Elements %d is found at position %d\n",key,position);
		printf("\n");
		return;
	}
	temp = temp->next;
	position++;
	}
printf("element not found in the stack\n",key);
}

int main(){
	struct Node* stack = NULL;
	int choice,value;

	while(1){
		printf("1.Push\n");
		printf("2.Pop\n");
		printf("3.Display\n");
		printf("4.search\n");
		printf("5.Exit\n");
		printf("Enter yr choice:");
		scanf("%d",&choice);

		switch(choice){
			case 1:
			printf("Enter the value to push:");
			scanf("%d",&value);
			push(&stack,value);
			break;
			case 2:
			value = pop(&stack);
			if(value != -1){
				printf("%d popped from stack\n",value);
			}
			break;
			case  3:
			display(stack);
			break;
			case 4:
			printf("Enter the values to search:");
			scanf("%d",&value);
			search(stack, value);
			break;
			case 5:
			printf("Exiting..\n");
			exit(0);
			default:
			printf("invalid choice! \n");

		}
	}

	return 0;
}
