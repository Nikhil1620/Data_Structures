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

}

int main()
{
    PNODE head = NULL;

    InserFirst(&head,51);
    InserFirst(&head,21);
    InserFirst(&head,11);
    Display(head);

    return 0;
}