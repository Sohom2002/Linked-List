#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *create_cll(struct node *start)
{
    struct node *new_node, *ptr;
    int num;
    printf("\nEnter -1 to stop");
    printf("\nEnter the data : ");
    scanf("%d",&num);
    while(num!=-1)
    {
        new_node = (struct node*)malloc(sizeof(struct node));
        new_node -> data = num;
        if(start == NULL)
        {
            new_node -> next = new_node;
            start = new_node;
        }
        else
        {
            ptr = start;
            while(ptr -> next != start)
                ptr = ptr -> next;
            ptr -> next = new_node;
            new_node -> next = start;
        }
        printf("\nEnter the data : ");
        scanf("%d",&num);
    }
    return start;
}

struct node *display(struct node *start)
{
    struct node *ptr=start;
    while(ptr -> next != start)
    {
        printf("%d\t",ptr->data);
        ptr = ptr -> next;
    }
    printf("%d",ptr -> data);
    return start;
}

struct node *insert_beg(struct node *start)
{
    struct node *new_node, *ptr=start;
    int num;
    printf("\nEnter the data : ");
    scanf("%d",&num);
    new_node = (struct node*)malloc(sizeof(struct node));
    new_node -> data = num;
    while(ptr -> next != start)
        ptr = ptr -> next;
    ptr -> next = new_node;
    new_node -> next = start;
    start = new_node;
    return start;
}

struct node *insert_end(struct node *start)
{
    struct node *new_node, *ptr = start;
    int num;
    printf("\nEnter the data : ");
    scanf("%d",&num);
    new_node = (struct node*)malloc(sizeof(struct node));
    new_node -> data = num;
    while(ptr -> next != start)
        ptr = ptr -> next;
    ptr -> next = new_node;
    new_node -> next = start;
    return start;
}

int search_val(struct node *start, int val)
{
    struct node *ptr = start;
    while(ptr -> next != start)
    {
        if(ptr -> data == val)
            return 1;
        ptr = ptr -> next;
    }
    if(ptr -> data == val)
        return 1;
    return 0;
}

struct node *insert_before(struct node *start)
{
    struct node *new_node, *ptr=start, *preptr;
    int val, num;
    printf("\nEnter value before which new value : ");
    scanf("%d",&val);
    if(search_val(start,val))
    {
        if(start -> data == val)
        {
            start = insert_beg(start);
            return start;
        }
        else
        {
            printf("\nEnter data : ");
            scanf("%d",&num);
            new_node = (struct node*)malloc(sizeof(struct node));
            new_node -> data = num;
            while(ptr -> data != val)
            {
                preptr = ptr;
                ptr = ptr -> next;
            }
            preptr -> next = new_node;
            new_node -> next = ptr;
            return start;
        }
    }
    else
    {
        printf("\nNode not Found!");
        return start;
    }
}

struct node *insert_after(struct node *start)
{
    struct node *ptr=start, *new_node, *ptr1=start, *postptr;
    int num, val;
    printf("\nEnter value after which new value : ");
    scanf("%d",&val);
    if(search_val(start,val))
    {
        while(ptr1 -> next != start)
            ptr1 = ptr1 -> next;
        if(ptr1 -> data == val)
        {
            start = insert_end(start);
            return start;
        }
        else
        {
            printf("\nEnter data : ");
            scanf("%d",&num);
            new_node = (struct node*)malloc(sizeof(struct node));
            new_node -> data = num;
            while(ptr -> data != val)
                ptr = ptr -> next;
            postptr = ptr -> next;
            ptr -> next = new_node;
            new_node -> next = postptr;
            return start;
        }
    }
    else
    {
        printf("\nNode not Found!");
        return start;
    }
}

struct node *delete_beg(struct node *start)
{
    struct node *ptr=start;
    while(ptr -> next != start)
        ptr = ptr -> next;
    ptr -> next = start -> next;
    free(start);
    start = ptr -> next;
    return start;
}

struct node *delete_end(struct node *start)
{
    struct node *ptr=start, *preptr;
    while(ptr -> next != start)
    {
        preptr = ptr;
        ptr = ptr -> next;
    }
    preptr -> next = ptr -> next;
    free(ptr);
    return start;
}

struct node *delete_node(struct node *start)
{
    struct node *ptr=start, *ptr1=start, *preptr, *postptr;
    int val;
    printf("\nEnter value to delete : ");
    scanf("%d",&val);
    if(search_val(start,val))
    {
        while(ptr1 -> next != start)
            ptr1 = ptr1 -> next;
        if(ptr -> data == val)
        {
            start = delete_beg(start);
            return start;
        }
        else if(ptr -> data == val)
        {
            start = delete_end(start);
            return start;
        }
        else
        {
            while(ptr -> next != val)
            {
                preptr = ptr;
                ptr = ptr -> next;
            }
            postptr = ptr ->next;
            preptr -> next = postptr;
            return start;
        }
    } 
    else
    {
        printf("\nValue not found!");
        return start;
    }
}

void size(struct node *start)
{
    int count=0;
    struct node *ptr=start;
    while(ptr -> next != start)
    {
        count++;
        ptr = ptr -> next;
    }
    count++;
    printf("\nSize of CLL : %d",count);
}

int main()
{
    struct node *start=NULL;
    start = create_cll(start);
    start = display(start);
    int num, data, opt1, opt2;
    do
    {
        printf("\nMAIN MENU:");
        printf("\n\t1.Insert an Element");
        printf("\n\t2.Delete an Element");
        printf("\n\t3.Search for an Element");
        printf("\n\t4.Count total number of Elements");
        printf("\n\t5.Display the Circular Linked List");
        printf("\n\t6.Exit");
        printf("\nEnter Choice (1-6) : ");
        scanf("%d",&opt1);
        switch(opt1)
        {
            case 1: printf("\nINSERT MENU:");
                    printf("\n\t1.Insert at beginning");
                    printf("\n\t2.Insert at end");
                    printf("\n\t3.Insert before a node");
                    printf("\n\t4.Insert after a node");
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
                    start = display(start);
                    break;
            case 2: printf("\nDELETE MENU:");
                    printf("\n\t1.Delete Beginning");
                    printf("\n\t2.Delete End");
                    printf("\n\t3.Delete given node");
                    printf("\nEnter Choice(1-3) : ");
                    scanf("%d",&opt2);
                    if(opt2 == 1)
                        start = delete_beg(start);
                    else if(opt2 == 2)
                        start = delete_end(start);
                    else if(opt2 == 3)
                        start = delete_node(start);
                    start = display(start);
                    break;
            case 3: printf("\nEnter value to search : ");
                    scanf("%d",&data);
                    int ans = search_val(start,data);
                    if(ans==1)
                        printf("\nValue Found");
                    else
                        printf("\nValue not Found");
                    break;
            case 4: size(start);
                    break;
            case 5: start = display(start);
                    break;
            case 6: printf("\nProgram Terminating");
                    break;
            default: printf("\nWrong Choice!");
                    break;
        }
    }while(opt1!=6);
    return 0;
}
