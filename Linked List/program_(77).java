//Singly Circular
import java.util.*;
class node
{
    public int data;
    public node next;

    public node(int no)
    {
        this.data = no;
        this.next = null;
    }
}

class SinglyCL
{
    private node first;
    private node last;
    private int iCount;  

    public SinglyCL()
    {
        System.out.println("Object of SinglyCL gets created.");
        this.first = null;
        this.last = null;

        this.iCount = 0;
    }

    public void InsertFirst(int no)
    {}

    public void InsertLast(int no)
    {}

    public void InsertAtPos(int no, int pos)
    {}

    public void DeleteFirst()
    {}

    public void DeleteLast()
    {}

    public void DeleteAtPos(int pos)
    {}

    public void Display()
    {}

    public int Count()
    {
        return this.iCount;
    }

}

class program447
{
    public static void main(String A[])
    {
        int iRet = 0;

        SinglyCL obj = null;

        obj = new SinglyCL();

        obj.InsertFirst(51);
        obj.InsertFirst(21);
        obj.InsertFirst(11);

        obj.InsertLast(101);
        obj.InsertLast(111);
        obj.InsertLast(121);


        obj.Display();

        iRet = obj.Count();

        System.out.println(iRet+" nodes are in the linked list.");

        obj.DeleteFirst();

        obj.Display();

        iRet = obj.Count();

        System.out.println(iRet+" nodes are in the linked list.");

        obj.DeleteLast();

        obj.Display();

        iRet = obj.Count();

        System.out.println(iRet+" nodes are in the linked list.");

        obj.InsertAtPos(105,4);

        obj.Display();

        iRet = obj.Count();

        System.out.println(iRet+" nodes are in the linked list.");

        obj.DeleteAtPos(4);

        obj.Display();

        iRet = obj.Count();

        System.out.println(iRet+" nodes are in the linked list.");

        obj = null;
        System.gc();
    }
}