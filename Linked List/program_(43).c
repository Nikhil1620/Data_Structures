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

}

void InsertLast(PPNODE first, PPNODE last, int no)
{

}

void DeleteFirst(PNODE first, PNODE last)
{

}

void DeleteLast(PNODE first, PNODE last)
{

}

void Display(PNODE first,PNODE last)
{

}

int Count(PNODE first, PNODE last)
{
    return 0;
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


    return 0;
}