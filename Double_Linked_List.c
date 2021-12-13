#include<stdlib.h>
#include<stdio.h>

struct node
{
    int data;
    struct node *next;
    struct node *prev;
};

struct node *create_dll(struct node *start)
{
    struct node *new_node, *ptr;
    int num;
    printf("\nEnter -1 to end");
    printf("\nEnter the data : ");
    scanf("%d",&num);
    while(num != -1)
    {
        if(start == NULL)
        {
            new_node = (struct node*)malloc(sizeof(struct node));
            new_node -> prev = NULL;
            new_node -> data = num;
            new_node -> next = NULL;
            start = new_node;
        }
        else
        {
            ptr = start;
            new_node = (struct node*)malloc(sizeof(struct node));
            new_node -> data = num;
            while(ptr -> next != NULL)
                ptr = ptr -> next;
            ptr -> next = new_node;
            new_node -> prev = ptr;
            new_node -> next = NULL;
        }
        printf("\nEnter data : ");
        scanf("%d",&num);
    }
    return start;
}

struct node *display(struct node *start)
{
    struct node *ptr;
    ptr = start;
    if(ptr == NULL)
    {
        printf("\nEmpty List");
        return start;
    }
    else
    {
        while(ptr!=NULL)
        {
            printf("%d <->",ptr->data);
            ptr = ptr->next;
        }
        return start;
    }
}

struct node *insert_beg(struct node *start)
{
    struct node *new_node;
    int num;
    printf("\nEnter data : ");
    scanf("%d",&num);
    new_node = (struct node*)malloc(sizeof(struct node));
    new_node -> data = num;
    start -> prev = new_node;
    new_node -> next = start;
    new_node -> prev = NULL;
    start = new_node;
    return start;
}

int search_val(struct node *start, int n)
{
    struct node *ptr = start;
    int pos=0;
    while(ptr->data != n && ptr->next!=NULL)
    {
        pos++;
        ptr = ptr -> next;
    }
    if(ptr -> data != n)
        return 0;
    return 1;
}

struct node *insert_before(struct node *start)
{
    int num,data,ans;
    struct node *new_node, *ptr=start;
    printf("\nEnter value before which new val to be inserted : ");
    scanf("%d",&num);
    ans = search_val(start,num);
    if(ans==1)
    {
        if(ptr -> data == num)
        {
            start = insert_beg(start);
            return start;
        }
        else
        {
            printf("\nEnter data : ");
            scanf("%d",&data);
            new_node = (struct node*)malloc(sizeof(struct node));
            new_node -> data = data;
            ptr = start;
            while(ptr -> data != num)
                ptr = ptr -> next;
            new_node -> next = ptr;
            new_node -> prev = ptr -> prev;
            ptr ->prev ->next = new_node;
            ptr -> prev = new_node;
            return start;
        }
    }
    else
    {
        printf("\nValue Not Found");
        return start;
    }
}

struct node *insert_end(struct node *start)
{
    struct node *new_node, *ptr;
    int num;
    printf("\nEnter the data : ");
    scanf("%d",&num);
    new_node = (struct node*)malloc(sizeof(struct node));
    new_node -> data = num;
    ptr = start;
    while(ptr -> next != NULL)
        ptr = ptr -> next;
    ptr -> next = new_node;
    new_node -> prev = ptr;
    new_node -> next = NULL;
    return start;
}

struct node *insert_after(struct node *start)
{
    struct node *new_node, *ptr;
    int num, data, ans;
    printf("\nEnter value after which new val to e inserted : ");
    scanf("%d",&num);
    ans = search_val(start,num);
    if(ans == 1)
    {
        ptr = start;
        while(ptr -> data != num)
            ptr = ptr->next;
        if(ptr -> next !=NULL)
        {
            printf("\nEnter data : ");
            scanf("%d",&data);
            new_node = (struct node*)malloc(sizeof(struct node));
            new_node -> data = data;
            new_node -> prev = ptr;
            new_node -> next = ptr -> next;
            ptr -> next -> prev = new_node;
            ptr -> next = new_node;
            return start;
        }
        else if(ptr -> next == NULL)
        {
            start = insert_end(start);
            return start;
        }
    }
    else
    {
        printf("\nValue not Found");
        return start;
    }
}

struct node *delete_beg(struct node *start)
{
    struct node *ptr;
    ptr = start;
    start = start -> next;
    start -> prev = NULL;
    free(ptr);
    return start;
}

struct node *delete_end(struct node *start)
{
    struct node *ptr;
    ptr = start;
    while(ptr -> next != NULL)
        ptr = ptr -> next;
    ptr -> prev -> next = NULL;
    free(ptr);
    return start;
}

struct node *delete_node(struct node *start, int n)
{
    struct node *ptr=start, *preptr, *postptr,*ptr1=start;
    int ans = search_val(start, n);
    if(ans == 1)
    {
        while(ptr1 -> next != NULL)
            ptr1 = ptr1 -> next;
        if(ptr -> data == n)
        {
            start = delete_beg(start);
            return start;
        }
        else if(ptr1 -> data == n)
        {
            start = delete_end(start);
            return start;
        }
        else
        {
            while(ptr -> data != n)
            {
                preptr = ptr;
                ptr = ptr -> next;
            }
            postptr = ptr -> next;
            preptr -> next = postptr;
            postptr -> prev = preptr;
            return start;
        }
    }
    else
    {
        printf("\nNode not Found");
        return start;
    }
}

void size(struct node *start)
{
    struct node *ptr = start;
    int count = 0;
    while(ptr != NULL)
    {
        count++;
        ptr = ptr -> next;
    }
    printf("\nThe length of DLL is : %d", count);
}

int main()
{
    struct node *start=NULL;
    start = create_dll(start);
    start = display(start);
    int num, data, opt1, opt2;
    do
    {
        printf("\nMAIN MENU:");
        printf("\n\t1.Insert an Element");
        printf("\n\t2.Delete an Element");
        printf("\n\t3.Search for an Element");
        printf("\n\t4.Count total number of Elements");
        printf("\n\t5.Display the Double Linked List");
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
                    {
                        printf("\nEnter value to be deleted : ");
                        scanf("%d",&data);
                        start = delete_node(start, data);
                    }
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
