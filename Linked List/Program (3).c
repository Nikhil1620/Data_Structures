#include<stdio.h>

#pragma pack(1)
struct node
{
    int data;
    struct node *next;
};

typedef struct node NODE;

int main()
{
    NODE obj;

    obj.data = 11;
    obj.next = NULL;

    return 0;
}