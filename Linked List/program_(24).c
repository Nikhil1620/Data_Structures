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
    PNODE temp = NULL;

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
    PNODE temp = NULL;

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
        temp = (*first);
        
        while(temp->next->next != NULL)         //Type 3 while loop
        {
            temp = temp->next;
        }

        free(temp -> next);
        temp->next = NULL;
    }
}
void InsertAtPos(PPNODE first, int no, int pos)
{
    int iCnt = 0;

    PNODE newn = NULL;
    PNODE temp = NULL;

    int iSize = 0;

    iSize = Count(*first);

    if((pos < 1) || (pos > iSize + 1))        //filter
    {
        printf("Invalid Position.");
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

        temp = (*first);

        for(iCnt = 1; iCnt < pos - 1; iCnt++)
        {
            temp = temp -> next;
        }

        newn -> next = temp -> next;   //1
        temp -> next = newn;           //2
    }


}

void DeleteAtPos(PPNODE first, int pos)
{
    int iCnt = 0;
    
    PNODE temp = NULL;
    PNODE target = NULL;

    int iSize = 0;

    iSize = Count(*first);

    if((pos < 1) || (pos > iSize))        //filter
    {
        printf("Invalid Position.\n");
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
        temp = *first;

        for(iCnt = 1; iCnt < pos - 1; iCnt++)
        {
            temp = temp -> next;
        }

        target = temp -> next;

        temp -> next  = target -> next;   //1
        free(target);

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

    DeleteLast(&head);

    Display(head);

    iRet = Count(head);
    printf("\n");
    printf("%d nodes are in the linked list.",iRet);
    printf("\n");

    InsertAtPos(&head,105,3);

    Display(head);

    iRet = Count(head);
    printf("\n");
    printf("%d nodes are in the linked list.",iRet);
    printf("\n");

    DeleteAtPos(&head,3);

    Display(head);

    iRet = Count(head);
    printf("\n");
    printf("%d nodes are in the linked list.",iRet);
    printf("\n");
    

    return 0;
}