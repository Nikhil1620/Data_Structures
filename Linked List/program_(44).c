#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
    struct node *prev;
};

typedef struct node NODE;
typedef struct node* PNODE;
typedef struct node** PPNODE;

void InsertFirst(PPNODE first, PPNODE last, int no)
{
    PNODE newn = NULL;

    newn = (PNODE)malloc(sizeof(NODE));

    newn -> data = no;
    newn -> next = NULL;
    newn -> prev = NULL;

    if(((*first) == NULL) && ((*last) == NULL))    //LL is empty
    {
        (*first) = newn;
        (*last) = newn;
    }
    else                                           //LL contains one or more elements
    {
        newn -> next = (*first);
        (*first) -> prev = newn;
        (*first) = newn;

    }
    (*last) -> next = (*first);
    (*first) -> prev = (*last);
}

void InsertLast(PPNODE first, PPNODE last, int no)
{
    PNODE newn = NULL;

    newn = (PNODE)malloc(sizeof(NODE));

    newn -> data = no;
    newn -> next = NULL;
    newn -> prev = NULL;

    if(((*first) == NULL) && ((*last) == NULL))    //LL is empty
    {
        (*first) = newn;
        (*last) = newn;
    }
    else                                           //LL contains one or more elements
    {
        newn -> next = (*first);
        (*first) = newn;

    }
    (*last) -> next = (*first);
    (*first) -> prev = (*last);
}

void DeleteFirst(PNODE first, PNODE last)
{

}

void DeleteLast(PNODE first, PNODE last)
{

}

void Display(PNODE first,PNODE last)
{
    do
    {
        printf("| %d | <=> ",first -> data);
        first = first -> next;
    }while(first != last -> next);

    printf("\n");
}

int Count(PNODE first, PNODE last)
{
    int iCount = 0;

    do
    {
        iCount++;
        first = first -> next;
    }while(first != last -> next);

    return iCount;
}

void InsertAtPos(PNODE first, PNODE last, int no, int pos)
{

}

void DeleteAtPos(PNODE first, PNODE last, int pos)
{

}
int main()
{
    PNODE head = NULL;
    PNODE tail = NULL;

    int iRet = 0;

    InsertFirst(&head,&tail,101);
    InsertFirst(&head,&tail,51);
    InsertFirst(&head,&tail,21);
    InsertFirst(&head,&tail,11);

    Display(head,tail);

    iRet = Count(head,tail);
    printf("\n");
    printf("%d nodes are in the linked list.",iRet);
    printf("\n");




    return 0;
}