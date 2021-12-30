#include<iostream>
using namespace std;
class node
{
    public:
    int data;
    node*next;
};
int hashval(int key)    //hash funtion to give the index for a key
{
    return (key%10);
}
node* insortedll(node*head,int val)  // function to insert a given val in the given sorted liked list in its position
{
    
    if(head==0)
    {
        head=new node;
        head->data=val;
        head->next=0;
    }
    else
    {
        node*r=0,*p=head;    
        while(p&&p->data<val)
        {
            r=p;
            p=p->next;
        }
        node*t=new node;
        t->data=val;
        t->next=p;
        if(r)
        r->next=t;
       
    }
    return head;
}


void insert(node*hash_table[],int key)   // Function to insert a given key in the given hash table
{
    hash_table[hashval(key)]=insortedll(hash_table[hashval(key)],key);
}
void printHashTable(node*hash_table[],int size) // Function to print the values in the hash table
{
 for(int i=0;i<size;i++)
 {
     cout<<i<<" : ";
     node*p=hash_table[i];
     if(p)
     {
         while(p!=0)
         {
             cout<<p->data<<" ";
             p=p->next;
         }
     }
     else
      cout<<" ";
      cout<<endl;
 }
}
node* search(node*hash_table[],int key)    // function to search the given key in the given hash table.
{
    node*head=hash_table[hashval(key)];
    
        node*p=head;
        while(p)
        {
            if(p->data<key)
            {
                p=p->next;
            }
            else if(p->data==key)
            {
                return p;
            }
            else
            {
                return 0;
            }
        }
        return 0;

}
void deletefromHTable(node*hash_table[],int key) // Function to delete given key from the given hash table. 
{
    node*head=hash_table[hashval(key)];
    node*r=0,*p=head;
     if(head->data==key)
    {
        head=head->next;
        delete p;
        hash_table[hashval(key)]=head;
    }
    else
    {
    while(p->data!=key)
    {   r=p;
        p=p->next;
    }
    r->next=p->next;
    delete p;
    }
}
int main()
{   
    node* hash_table[10];  // Creating a hash table.
    for(int i=0;i<10;i++)
    {
        hash_table[i]=0;   // Initialising the hash table with null.
    }
    //Inserting keys
    insert(hash_table,10);
    insert(hash_table,20);
    insert(hash_table,30);
    insert(hash_table,40);
    insert(hash_table,50);
    insert(hash_table,60);
    insert(hash_table,11);
    insert(hash_table,121);
    insert(hash_table,2);
    insert(hash_table,12);
    insert(hash_table,22);
    insert(hash_table,3);
    insert(hash_table,33);
    insert(hash_table,73);
    insert(hash_table,4);
    insert(hash_table,14);
    insert(hash_table,44);
    insert(hash_table,5);
    insert(hash_table,55);
    insert(hash_table,85);
    insert(hash_table,36);
    insert(hash_table,96);
    insert(hash_table,7);
    insert(hash_table,17);
    insert(hash_table,77);
    insert(hash_table,8);
    insert(hash_table,18);
    insert(hash_table,28);
    insert(hash_table,9);
    // insert(hash_table,19);
    // Printing the hash table.
    printHashTable(hash_table,10);
    // Searching a key.
    node*p=search(hash_table,19);
    if(p)
    cout<<p->data;
    else
    cout<<"not found";
    //Deleting key if found
    int key=40;
    node*pt=search(hash_table,key);
    if(pt)
    {
        deletefromHTable(hash_table,key);
        cout<<"deleted"<<endl;
    }
    else
     cout<<"not present"<<endl;
      printHashTable(hash_table,10);
    return 0;
}