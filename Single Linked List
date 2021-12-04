#include <stdio.h>
#include <stdlib.h>
#include<stdbool.h>

struct node
{
    int data;
    struct node *next;
};

struct node *create_linkedlist(struct node *start)
{
    printf("\nCreating the Linked List:");
    struct node *new_node;
    int num;
    char choice;
    printf("\nDo you want to enter an element (y/n) : "); scanf("%c%*c",&choice);
    while(choice!='n')
    {
        printf("\nEnter Element : "); scanf("%d%*c",&num);
        
        if(start == NULL)
        {
            start = (struct node*)malloc(sizeof(struct node));
            start -> data = num;
            start -> next = NULL;
        }
        else
        {
            struct node *ptr = start;
            while(ptr->next!=NULL)
                ptr = ptr->next; 
            ptr ->next = (struct node*)malloc(sizeof(struct node));
            ptr -> next -> data = num;
            ptr -> next -> next = NULL;
        }
        printf("\nDo you want to enter an element (y/n) : "); scanf("%c%*c",&choice);
    }
    printf("\nLinked List Successfully Created");
    return start;
}

struct node *display(struct node *start)
{
    printf("\nContents of Linked List : ");
    struct node *ptr;
    ptr = start;
    while(ptr!=NULL)
    {
        printf("%d->", ptr -> data);
        ptr = ptr -> next;
    }
    printf("NULL");
    return start;
}

struct node *insert_beg(struct node *start)
{
    struct node *new_node;
    int num;
    printf("\nEnter data : ");
    scanf("%d",&num);
    new_node = (struct node*)malloc(sizeof(struct node));
    new_node -> data = num;
    new_node -> next = start;
    start = new_node;
    return start;
}

struct node *insert_end(struct node *start)
{
    struct node *new_node, *ptr;
    int num;
    printf("Enter the data : ");
    scanf("%d",&num);
    new_node = (struct node*)malloc(sizeof(struct node));
    new_node -> data = num;
    new_node -> next = NULL;
    ptr = start;
    while(ptr -> next != NULL)
        ptr = ptr -> next;
    ptr -> next = new_node;
    return start;
}

struct node *insert_before(struct node *start)
{
    struct node *new_node, *ptr, *preptr;
    int num,val;
    printf("Enter the data : ");
    scanf("%d",&num);
    printf("\nEnter the value before which value to be inserted : ");
    scanf("%d",&val);
    new_node = (struct node*)malloc(sizeof(struct node));
    new_node -> data = num;
    ptr = start;
    while(ptr -> data !=val)
    {
        preptr = ptr;
        ptr = ptr -> next;
    }
    preptr -> next = new_node;
    new_node -> next = ptr;
    return start;
}

struct node *insert_after(struct node *start)
{
    struct node *new_node, *ptr, *preptr;
    int num,val;
    printf("Enter the data : ");
    scanf("%d",&num);
    printf("\nEnter the value after which value to be inserted : ");
    scanf("%d",&val);
    new_node = (struct node*)malloc(sizeof(struct node));
    new_node -> data = num;
    ptr = start;
    preptr = ptr;
    while(preptr -> data !=val)
    {
        preptr = ptr;
        ptr = ptr -> next;
    }
    preptr -> next = new_node;
    new_node -> next = ptr;
    return start;
}

struct node *delete_beg(struct node *start)
{
    struct node *ptr;
    ptr = start;
    start = start -> next;
    free(ptr);
    return start;
}

struct node *delete_end(struct node *start)
{
    struct node *ptr, *preptr;
    ptr = start;
    while(ptr -> next !=NULL)
    {
        preptr = ptr;
        ptr = ptr -> next;
    }
    preptr -> next = NULL;
    free(ptr);
    return start;
}

struct node *delete_node(struct node *start)
{
    struct node *ptr, *preptr;
    int val;
    printf("\nEnter value of the node to be deleted : ");
    scanf("%d",&val);
    ptr = start;
    if(ptr -> data == val)
    {
        start = delete_beg(start);
        return start;
    }
    else
    {
        while(ptr -> data !=val)
        {
            preptr = ptr;
            ptr = ptr -> next;
        }
        preptr ->  next = ptr -> next;
        free(ptr);
        return start;
    }
}

bool search(struct node *start, int x)
{
    struct node *ptr = start;
    while(ptr != NULL)
    {
        if(ptr->data == x)
            return true;
        ptr = ptr -> next;
    }
    return false;
}

void get_length(struct node *start)
{
    int count = 0;
    struct node *ptr = start;
    while(ptr!=NULL)
    {
        count++;
        ptr = ptr->next;
    }
    printf("\nLength of Linked list : %d", count);
}

int main()
{
    struct node *start = NULL;
    start = create_linkedlist(start);
    start = display(start);
    int opt1, opt2, data;
    do
    {
        printf("\nMAIN MENU:");
        printf("\n\t1. Insert an Element");
        printf("\n\t2. Delete an Element");
        printf("\n\t3. Search for an Element");
        printf("\n\t4. Count total number of Elements");
        printf("\n\t5. Display the linked list");
        printf("\n\t6. Exit");
        printf("\nEnter Choice (1-6) : ");
        scanf("%d",&opt1);
        switch(opt1)
        {
            case 1: printf("\nINSERT MENU:");
                    printf("\n\t1. Insert an beginning");
                    printf("\n\t2. Insert at end");
                    printf("\n\t3. Insert before a given node");
                    printf("\n\t4. Insert after a given node");
                    printf("\nEnter Choice (1-4) : ");
                    scanf("%d",&opt2);
                    if(opt2 == 1)
                        start = insert_beg(start);
                    else if(opt2 == 2)
                        start = insert_end(start);
                    else if(opt2 == 3)
                        start = insert_before(start);
                    else if(opt2 == 4)
                        start = insert_after(start);
                    break;
            case 2: printf("\nDELETE MENU:");
                    printf("\n\t1. Delete first node");
                    printf("\n\t2. Delete last node");
                    printf("\n\t3. Delete a given node");
                    printf("\nEnter Choice (1-3) : ");
                    scanf("%d",&opt2);
                    if(opt2 == 1)
                        start = delete_beg(start);
                    else if(opt2 == 2)
                        start = delete_end(start);
                    else if(opt2 == 3)
                        start = delete_node(start);
                    break;
            case 3: printf("\nEnter data to search : ");
                    scanf("%d",&data);
                    search(start,data)?printf("\nPresent"):printf("\nNot Present");
                    break;
            case 4: get_length(start);
                    break;
            case 5: start = display(start);
                    break;
            case 6: printf("\nProgram Terminated.");
                    break;
            default: printf("Wrong Choice!");
                    break;
        }
    } while (opt1!=6);
    
    return 0;
}
