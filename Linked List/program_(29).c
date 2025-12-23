#include<stdio.h>
#include<stdlib.h>

#pragma pack(1)
struct node
{
    int data;
    struct node *next;
    struct node *prev;   //$
};

typedef struct node NODE;
typedef struct node* PNODE;
typedef struct node** PPNODE;

void InserFirst(PPNODE first, int no)
{
    PNODE newn = NULL;

    newn = (PNODE)malloc(sizeof(NODE));

    newn -> data =no;
    newn -> next = NULL;
    newn -> prev = NULL;    //$

    if((*first) == NULL)
    {
        (*first) = newn;
    }
    else
    {
        newn -> next = (*first);
        (*first) -> prev = newn;
        (*first) = newn;
    }
}

void InserLast(PPNODE first, int no)
{
    PNODE newn = NULL;
    PNODE temp = NULL;

    newn = (PNODE)malloc(sizeof(NODE));

    newn -> data =no;
    newn -> next = NULL;
    newn -> prev = NULL;    //$

    if((*first) == NULL)
    {
        (*first) = newn;
    }
    else
    {
        temp = (*first);
        
        while(temp->next != NULL)         //Type 2 while loop
        {
            temp = temp -> next;
        }

        temp -> next = newn;
        temp->prev = temp;           //$
    }
}

void InsertAtPos(PPNODE first, int no, int pos)
{

}

void DeleteFirst(PPNODE first)
{
   
}

void DeleteLast(PPNODE first)
{

}

void DeleteAtPos(PPNODE first, int pos)
{
    
}

void Display(PNODE first)
{
    printf("\nNULL");
    while(first != NULL)
    {
        printf("| %d | <=> ",first->data);
        first = first->next;
    }
    printf("NULL\n");
}

int Count(PNODE first)
{
     int iCount = 0;

    while(first != NULL)
    {
        iCount++;
        first = first->next;
    }

    return iCount;
}

int main()
{
    int iRet = 0;
    PNODE head = NULL;

    InserFirst(&head,51);
    InserFirst(&head,21);
    InserFirst(&head,11);
    Display(head);
    
    iRet = Count(head);
    printf("\n");
    printf("%d nodes are in the linked list.",iRet);
    printf("\n");

    InserLast(&head,101);
    InserLast(&head,111);
    InserLast(&head,121);
    
    Display(head);
    
    iRet = Count(head);
    printf("\n");
    printf("%d nodes are in the linked list.",iRet);
    printf("\n");


    return 0;
}