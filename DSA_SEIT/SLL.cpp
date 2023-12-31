/*
Linked list Creation, Insertion and Deletion.
*/
#include <bits/stdc++.h>
using namespace std;

//Defination of Struct Node
//Node is used to store data and address of the next node

struct node
{
    int data;
    node *next;
};

//Creation of node in memory block

node *Create(int val)
{
    struct node *tmp;
    tmp = (struct node*) malloc(sizeof(node));
    tmp->data = val;
    tmp->next = NULL;
    return tmp;
}

//Insertion Functions

node *Insert_front(int val, node *head)
{
    node *temp;
    temp = Create(val);
    if(head==NULL)
    {
        head = temp;
    }
    else
    {
        temp->next = head;
        head = temp;
    }
    return head;
}

node *Insert_End(int val, node *head)
{
    node *temp = Create(val), *ptr=head;
    if(head==NULL)
    {
        head = temp;
    }
    else
    {
        while(ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        ptr->next = temp;
    }
    return head;
}

node *Insert_pos(int val, int pos, node *head)
{
    node *temp = Create(val), *ptr = head;
    if(head == NULL)
    {
        head = temp;
    }
    else
    {
        while(ptr->data != pos)
        {
            ptr = ptr->next;
        }
        temp->next = ptr->next;
        ptr->next = temp;
    }
    return head;
}

//Deletion Functions

node *Delete_Front(node *head)
{
    if(head!=NULL)
    {
        node *ptr;
        ptr = head;
        head = ptr->next;
        cout << "Node with data " << ptr->data << " deleted successfully\n";
        free(ptr);
    }
    return head;
}

node *Delete_end(node *head)
{
    node *ptr, *ptr1;
    ptr = head;
    if(head == NULL)
    {
        return head;
    }
    else if(head->next == NULL)
    {
        head = NULL;
        cout << "Node with data " << ptr->data << " deleted successfully\n";
        delete(ptr);
    }
    else
    {
        while(ptr->next != NULL)
        {
            ptr1 = ptr;
            ptr = ptr->next;
        }
        ptr1->next = NULL;
        cout << "Node with data " << ptr->data << " deleted successfully\n";
        delete(ptr);
    }
    return head;
}


node *delete_position(int pos, node *head)
{
    struct node *ptr, *ptr1;
    ptr = head;
    if(head == NULL)
    {
        return head;
    }
    else if(head->data == pos)
    {
        head == NULL;
    }
    else
    {
        while(ptr->data!=pos)
        {
            ptr1= ptr;
            ptr = ptr->next;
        }
        ptr1->next = ptr->next;
        delete(ptr);
    }
    return head;
}

node *Delete_pos(int pos,node *head)
{
    node *ptr, *ptr1;
    ptr = head;
    if(head == NULL)
    {
        return head;
    }
    else if(head->data == pos)
    {
        cout << "Node with data " << ptr->data << " deleted successfully\n";
        head = NULL;
    }
    else
    {
        while(ptr->data != pos)
        {
            ptr1 = ptr;
            ptr = ptr->next;
        }
        if( ptr->data != pos )
        {
            cout << "Such data does'nt Exists\n" ;
        }
        else
        {
            ptr1->next = ptr->next;
            cout << "Node with data " << ptr->data << " deleted successfully\n";
            delete(ptr);
        }
    }
    return head;
}

node *Delete_left(int pos,node *head)
{
    node *ptr, *ptr1, *ptr2;
    ptr = head;
    if(head == NULL || head->next == NULL || head->data == pos)
    {
        cout << "Such data does'nt Exists\n" ;
    }
    else if(head->next->data == pos)
    {
        cout << "Node with data " << head->data << " deleted successfully\n";
        head = head->next;
        delete(ptr);
    }
    else
    {
        while(ptr->data != pos)
        {
            ptr2 = ptr1;
            ptr1 = ptr;
            ptr = ptr->next;
        }
        if( ptr->data != pos )
        {
            cout << "Such data does'nt Exists\n" ;
        }
        else
        {
            ptr2->next = ptr;
            cout << "Node with data " << ptr1->data << " deleted successfully\n";
            delete(ptr1);
        }
    }
    return head;
}

node *Delete_right(int pos,node *head)
{
    node *ptr, *ptr1, *ptr2;
    ptr = head;
    if(head == NULL || head->next == NULL)
    {
        cout << "Such data does'nt Exists\n" ;
    }
    else if(head->data == pos)
    {
        ptr1 = head->next;
        head->next = ptr1->next;
        cout << "Node with data " << ptr1->data << " deleted successfully\n";
        delete(ptr1);
    }
    else
    {
        while(ptr->data != pos)
        {
            ptr = ptr->next;
        }
        if( ptr->data != pos || ptr->next== NULL)
        {
            cout << "Such data does'nt Exists\n" ;
        }
        else
        {
            ptr1 = ptr->next;
            ptr->next = ptr1->next;
            cout << "Node with data " << ptr1->data << " deleted successfully\n";
            delete(ptr1);
        }
    }
    return head;
}

//Reeverse a Linked list

node *reverse(node *head)
{
    node *ptr, *ptr1, *ptr2;
    ptr = head;
    ptr1 =  NULL;
    if(ptr==NULL)
    {
        cout << "Empty\n";
    }
    else
    {
        while(ptr!=NULL)
        {
            ptr2 = ptr1;
            ptr1 = ptr;
            ptr = ptr->next;
            ptr1->next = ptr2;
        }
        head = ptr1;
    }
    return head;
}

//Function to Showcase Data

void print(node *head)
{
    node *ptr= head;
    while(ptr->next != NULL)
    {
        cout << ptr->data <<' ';
        ptr = ptr->next;
    }
    cout<<ptr->data<<endl;
}

//Menu

void menu()
{
    cout << "Enter 1 To Insert Data at Front\n";
    cout << "Enter 2 To Insert Data at End\n";
    cout << "Enter 3 To Insert Data at Position\n";
    cout << "Enter 4 To Delete Data at Front\n";
    cout << "Enter 5 To Delete Data at End\n";
    cout << "Enter 6 To Delete Data at Position\n";
    cout << "Enter 7 To Delete Data at Left of Position\n";
    cout << "Enter 8 To Delete Data at Right of Position\n";
    cout << "Enter 9 To Reverse Linked List\n";
    cout << "Enter 10 To Show Data \n";
    cout << "Enter 0 To Exit \n";
}

//Main function

int main()
{
    node *head;
    head = NULL;
    int choice = 1, pos, val;
    menu();
    do
    {
        cout << "ENTER YOUR CHOICE : ";
        cin >> choice;
        cout << endl;
        switch (choice)
        {
        case 1:
            cout<<"Enter data of the node :  ";
            cin>>val;
            head = Insert_front(val,head);
            break;
        case 2:
            int val;
            cout<<"Enter data of the node :  ";
            cin>>val;
            head = Insert_End(val,head);
            break;
        case 3:
            cout<<"Enter data of the node :  ";
            cin>>val;
            cout<<"Enter position of the node :  ";
            cin>>pos;
            head = Insert_pos(val,pos,head);
            break;
        case 4:
            head = Delete_Front(head);
            break;
        case 5:
            head = Delete_end(head);
            break;
        case 6:
            cout<<"Enter position of the node :  ";
            cin>>pos;
            head = Delete_pos(pos,head);
            break;
        case 7:
            cout<<"Enter position of the node :  ";
            cin>>pos;
            head = Delete_left(pos,head);
            break;
        case 8:
            cout<<"Enter position of the node :  ";
            cin>>pos;
            head = Delete_right(pos,head);
            break;
        case 9:
            head = reverse(head);
            break;
        case 10:
            print (head);
            break;
        default:
            cout << "!! Invalid Value , Enter the choice again !!\n";
            break;
        }
    }while (choice);
}