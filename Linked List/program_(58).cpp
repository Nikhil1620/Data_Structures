#include<iostream>
using namespace std;

struct node
{
   int data;
   struct node *next; 
};

typedef struct node NODE;
typedef struct node* PNODE;
typedef struct node** PPNODE;

class SinglyLL
{
    public:
        PNODE first;
        int iCount;

        SinglyLL()
        {
            cout<<"Object of SiglyLL gets created.\n";
            first = NULL;
            iCount = 0;

        }

        void InsertFirst(int no)
        {
            PNODE newn = NULL;

            newn = new NODE;

            newn -> data = no;
            newn -> next = NULL;

            if((first) == NULL)
            {
                (first) = newn;
            }
            else
            {
                newn -> next = (first);
                (first) = newn;
            }
            iCount++;
        }
        
        void InsertLast(int no)
        {
            PNODE newn = NULL;
            PNODE temp = NULL;

            newn = new NODE;

            newn -> data = no;
            newn -> next = NULL;

            if(iCount == 0)
            {
                (first) = newn;
            }
            else
            {
                temp = first;

                while(temp -> next != NULL)
                {
                    temp = temp -> next;
                }
                temp -> next = newn;
            }
            iCount++;
        }

        void DeleteFirst()
        {
            PNODE temp = NULL;

            if(first == NULL)
            {
                return;
            }
            else if(first -> next == NULL)       //else if(iCount) == 1
            {
                delete first;
                first = NULL;
            }
            else
            {
                temp = first;

                first = first -> next;
                delete temp;
            }
            iCount--;
        }

        void DeleteLast()
        {
            PNODE temp = NULL;

            if(first == NULL)
            {
                return;
            }
            else if(first -> next == NULL)       //else if(iCount) == 1
            {
                delete first;
                first = NULL;
            }
            else
            {
                temp = first;

                while(temp -> next -> next != NULL)
                {
                    temp = temp -> next;
                }
                delete temp -> next;
                temp -> next =  NULL;
            }
            iCount--;
        }

        void Display()
        {
            PNODE temp = NULL;

            temp = (first);

            while(temp != NULL)
            {
                cout<<"| "<<temp -> data<<" | -> ";
                temp = temp -> next;
            }
            cout<<"NULL\n";
        }

        int Count()
        {
            return iCount;
        }

        void InsertAtPos(int no, int pos)
        {
            PNODE temp = NULL;

            if((pos < 1) || (pos > iCount + 1))        //filter
            {
                printf("Invalid Position.");
                return;
            }

            if(pos == 1)
            {
                InsertFirst(no);
            }
            else if(pos == iCount + 1)
            {
                InsertLast(no);
            }
            else
            {
                int iCnt= 0;

                temp = first;

                PNODE newn = NULL;

                newn = new NODE;

                newn -> data = no;
                newn -> next = NULL;

                temp = first;

                for(iCnt = 1; iCnt < pos - 1; iCnt++)
                {
                    temp = temp -> next;
                }

                newn -> next = temp -> next;   //1
                temp -> next = newn; 
                iCount++;  
            }
        }

        void DeleteAtPos(int pos)
        {
            PNODE temp = NULL;
            PNODE target = NULL;

            if((pos < 1) || (pos > iCount))        //filter
            {
                printf("Invalid Position.");
                return;
            }

            if(pos == 1)
            {
                DeleteFirst();
            }
            else if(pos == iCount)
            {
                DeleteLast();
            }
            else
            {
                int iCnt= 0;

                temp = first;

                temp = first;

                for(iCnt = 1; iCnt < pos - 1; iCnt++)
                {
                    temp = temp -> next;
                }

                target = temp -> next;

                temp -> next  = target -> next;   //1
                delete target;   

                iCount--;
            }
        }
};

int main()
{
    SinglyLL obj;
    int iRet = 0;

    obj.InsertFirst(51);
    obj.InsertFirst(21);
    obj.InsertFirst(11);

    obj.InsertLast(101);
    obj.InsertLast(111);
    obj.InsertLast(121);

    obj.Display();
    iRet = obj.Count();
    cout<<"number of nodes are : "<<iRet<<"\n";

    obj.DeleteFirst();

    obj.Display();

    iRet = obj.Count();
    cout<<"number of nodes are : "<<iRet<<"\n";

    obj.DeleteLast();

    obj.Display();

    iRet = obj.Count();
    cout<<"number of nodes are : "<<iRet<<"\n";

    obj.InsertAtPos(110,4);

    obj.Display();

    iRet = obj.Count();
    cout<<"number of nodes are : "<<iRet<<"\n";

    obj.DeleteAtPos(4);

    obj.Display();

    iRet = obj.Count();
    cout<<"number of nodes are : "<<iRet<<"\n";

    return 0;
}