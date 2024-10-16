#include<stdio.h>
#include<stdlib.h>
struct node{
        int data;
        struct node*next;

};
struct node*head=NULL;

void display(){
         struct node*temp=head;
        if(head==NULL)
        printf("\n Underflow!!");
        while(temp !=NULL){
        printf("%d \n",temp->data);
        temp=temp->next;


}
}
void insert_beg(int data){
        struct node*newnode=(struct node*) malloc(sizeof(struct node));
        newnode->data=data;
        newnode->next=head;
        head=newnode;
        display();

}
void insert_end(int data){
        struct node*newnode=(struct node*) malloc(sizeof(struct node));
         struct node*temp=head;

        newnode->data=data;
        if(head==NULL){
       insert_beg(data);
        return;
        head=newnode;
}
        temp=head;
        while(temp->next!=NULL){
        temp=temp->next;
}
        temp->next=newnode;
        display();
}



void insert_pos(int data,int p){
        struct node*newnode=(struct node*)malloc(sizeof(struct node));
 struct node*temp=head;
        int count=2;
        newnode->data=data;
        if(head==NULL){
        printf("list is empty");
        }
else if(p==1){
        newnode->next=head;
        head=newnode;

        }
else{
        temp=head;
        while(temp!=NULL){
        if(p==count){
                newnode->next=temp->next;
                temp->next=newnode;
                break;
        }
        else{
        temp=temp->next;
        count++;
        }

        }
        }
        display();
}


void search(int s){
        int f=0;
        struct node*temp=head;

        while(temp!=NULL){
                if(temp->data==s){
                        f=1;
                        printf("element found\n");
                }
        temp=temp->next;
}
        if(f!=1)
        printf("element not found\n");


}

int  dele_beg(){
                struct node*temp=head;
        if(temp==NULL){
 printf("List is empty\n");

        }
        else{
        temp=head;
        head=temp->next;
        free(temp);
        display();

}


}

void dele_end(){
        struct node*ptr=head;
        struct node*temp;
        if(ptr==NULL){
        printf("List is empty\n");

        }
        else{
        ptr=head;
        while(ptr->next!=NULL){
        temp=ptr;
        ptr=ptr->next;

        }
        temp->next=NULL;
        free(ptr);
        display();
}
}

void dele_pos(int p){
        struct node*temp=head;
        struct node*prev=NULL;
        if(p<1){
        printf("invalid");
        return;
        }
        if(p==1){
        dele_beg();
        return;
        }
        for(int i=2;i<=p && temp!=NULL;i++){
        prev=temp;
        temp=temp->next;

        }

        if(temp==NULL){
        printf("position not  found\n");
        return;
        }
        prev->next=temp->next;
        free(temp);

        display();
}




void main(){
        int data,ch,p,s;
        do{
printf("-----------------------------------------------------------------------------------------------------");
printf("\n 1.Insert at begning \n 2.Insert at end \n 3.Insert at any position \n 4.Search \n 5.Display \n 6.Delete from begining \n 7.Delete from end \n 8.Delete from any position \n 9.Exit \n\n");

        printf("\n Enter your choice  ");
        scanf("%d",&ch);
        switch(ch){

        case 1:
        printf("\n Enter the data to be insered  ");
        scanf("%d",&data);
        insert_beg(data);
        break;


        case 2:
        printf("Enter the data to be insered  ");
        scanf("%d",&data);
        insert_end(data);
        break;
        case 3:
        printf("Enter the data to be insered  ");
        scanf("%d",&data);
        printf("Enter the position to be insered  ");
        scanf("%d",&p);
        insert_pos(data,p);
        break;
 case 4:
        if(head==NULL){
        printf("List is empty!!  ");

        }
        else{
        printf("Enter the value to be search  ");
        scanf("%d",&s);
        search(s);
        break;
        }
        case 5:
        display();
        break;
        case 6:
        dele_beg();
        break;
        case 7:
        dele_end();
        break;
        case 8:
        if(head==NULL){
        printf("List is empty!!");

        }
else{
        printf("Enter the position to be deleted  ");
        scanf("%d",&p);
        dele_pos(p);
        break;
}
        case 9:
        printf("\n exist from the program ");
        break;

        default:
        printf("Invalid!!");
}


}while(ch!=9);


}



