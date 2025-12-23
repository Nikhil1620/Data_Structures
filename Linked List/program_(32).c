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
        (*first) -> prev = newn;  //$
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

void DeleteFirst(PPNODE first)
{
    PNODE temp = NULL;

    if(*first == NULL)
    {
        return;
    }
    else if((*first) -> next == NULL)
    {
        free(*first);
        *first = NULL;
    }
    else
    {
        temp = *first;

        *first = (*first) -> next;
        free(temp);
        (*first) -> prev = NULL;        //$
    }
}

void DeleteLast(PPNODE first)
{
    PNODE temp = NULL;

    if(*first == NULL)
    {
        return;
    }
    else if((*first) -> next == NULL)
    {
        free(*first);
        *first = NULL;
    }
    else
    {
        temp = *first;

        while(temp ->next -> next != NULL)      // Type 3
        {
            temp = temp -> next;
        }

        free(temp->next);
        temp->next = NULL;
    }
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

void InsertAtPos(PPNODE first, int no, int pos)
{
    int iSize = 0;
    int iCnt = 0;

    PNODE newn = NULL;
    PNODE temp = NULL;

    iSize = Count(*first);

    if((pos < 1) || (pos > iSize + 1))           //Filter
    {
        printf("Invalid Position\n");
        return;
    }

    if(pos == 1)
    {
        InserFirst(first,no);
    }
    else if(pos == iSize + 1)
    {
        InserLast(first,no);
    }
    else
    {
        newn = (PNODE)malloc(sizeof(NODE));

        newn -> data = no;
        newn -> next = NULL;
        newn -> prev = NULL;     //$

        temp = (*first); 

        for(iCnt = 1; iCnt < (pos-1); iCnt++)
        {
            temp = temp -> next;
        }

        newn -> next = temp -> next;   //1
        temp -> next -> prev = newn;   //2     //$
        temp -> next = newn;           //3
        newn -> prev = temp;           //4     //$

        
    }    
}

void DeleteAtPos(PPNODE first, int pos)
{
    int iSize = 0;
    int iCnt = 0;

    PNODE temp = NULL;
    PNODE target = NULL;

    iSize = Count(*first);

    if((pos < 1) || (pos > iSize))           //Filter
    {
        printf("Invalid Position\n");
        return;
    }

    if(pos == 1)
    {
        DeleteFirst(first);
    }
    else if(pos == iSize)
    {
        DeleteLast(first);
    }
    else
    {
        temp = (*first); 

        for(iCnt = 1; iCnt < (pos-1); iCnt++)
        {
            temp = temp -> next;
        }
        
    } 
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

    InsertAtPos(&head,105,5);

    Display(head);
    
    iRet = Count(head);
    printf("\n");
    printf("%d nodes are in the linked list.",iRet);
    printf("\n");

    DeleteAtPos(&head,5);

    Display(head);
    
    iRet = Count(head);
    printf("\n");
    printf("%d nodes are in the linked list.",iRet);
    printf("\n");


    return 0;
}