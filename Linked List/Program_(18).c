#include<stdio.h>
#include<stdlib.h>

#pragma pack(1)
struct node
{
    int data;
    struct node *next;
};

typedef struct node NODE;
typedef struct node * PNODE;
typedef struct node ** PPNODE;

void InserFirst(PPNODE first, int no)
{
    PNODE newn = NULL;

    newn = (PNODE)malloc(sizeof(NODE));

    newn -> data = no;
    newn -> next = NULL;

    if((*first) == NULL)   //Linked list is empty
    {
        (*first) = newn;
    }
    else                 //Linked list contains atleast one node
    {
        newn -> next = (*first);
        (*first) = newn;
    }
}

void InserLast(PPNODE first, int no)
{
    PNODE newn = NULL;
    PNODE temp = NULL;

    newn = (PNODE)malloc(sizeof(NODE));

    newn -> data = no;
    newn -> next = NULL;

    if(*first == NULL)   //Linked list is empty
    {
        *first = newn;
    }
    else                 //Linked list contains atleast one node
    {
        temp = *first;

        while(temp -> next != NULL)
        {
            temp = temp -> next;
        }
        temp -> next = newn;
    }

}

void Display(PNODE first)
{
    while(first != NULL)
    {
        printf("| %d | -> ",first->data);
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

void DeleteFirst(PPNODE first)
{
    pNODE temp = NULL;

    if((*first) == NULL)               //Case 1
    {
        return;
    }
    else if((*first) -> next == NULL)  //Case 2
    {
        free(*first);
        (*first) = NULL;
    }
    else                               //Case 3
    {
        temp = *first;
        (*first) = (*first) -> next;
        free(temp);
    }
}

void DeleteLast(PPNODE first)
{
    if((*first) == NULL)                //Case 1
    {
        return;
    }
    else if((*first) -> next == NULL)   //Case 2
    {
        free(*first);
        (*first) = NULL;
    }
    else                              //Case 3
    {
         
    }
}

int main()
{
    int iRet = 0;

    PNODE head = NULL;

    InserFirst(&head,75);
    InserFirst(&head,51);
    InserFirst(&head,21);
    InserFirst(&head,11);

    Display(head);

    iRet = Count(head);
    printf("\n");
    printf("%d nodes are in the linked list.",iRet);
    printf("\n");

    InserLast(&head, 101);
    InserLast(&head, 111);
    InserLast(&head, 121);

    Display(head);

    iRet = Count(head);
    printf("\n");
    printf("%d nodes are in the linked list.",iRet);
    printf("\n");

    DeleteFirst(&head);

    Display(head);

    iRet = Count(head);
    printf("\n");
    printf("%d nodes are in the linked list.",iRet);
    printf("\n");

    return 0;

}
