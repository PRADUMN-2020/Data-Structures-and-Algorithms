#include<iostream>
#define SIZE 10        
using namespace std;
int hashval(int key)    // function to give the index at which the key is to be stored in the hash table.
{
    return key%SIZE;
}
int probe(int H[],int key)  // function to give the index to the first vacant space starting from the index given by hash function.
{
    int index=hashval(key);
    int i=0;
    while(H[(index+i)%SIZE]!=0)
    {
        i++;
    }
    return (index+i)%SIZE;
}
void insert(int H[],int key)  // function to store a given key in the given hash table.
{
   int index=hashval(key);
   if(H[index]==0)
   {
       H[index]=key;
   }
   else
   {
     index=probe(H,key);
     H[index]=key;
   }
}
int Search(int H[],int key)  // function to return the index of the given key in the given hash table.
{
    int index=hashval(key);
    int i=0;
    while(H[(index+i)%SIZE]!=key&&H[(index+i)%SIZE]!=0)
    {
        i++;
    }
    if(H[(index+i)%SIZE]==0)
    {
       return -1;
    }
    return (index+i)%SIZE;
}
int main()
{
    int HT[SIZE]={0};   // Creating hash table.
    // Inserting keys in the hash table.
    insert(HT,5);
    insert(HT,25);
    insert(HT,35);
    insert(HT,2);
    insert(HT,12);
    // Printing the hash table.
    for(int i=0;i<SIZE;i++)
    {
        cout<<i<<" : "<<HT[i]<<endl;
    }
    // Searching a key in the hash table.
    int key=21;
    if(Search(HT,key)==-1)
    {
        cout<<"key is not present in the hash table."<<endl;
    }
    else
    {
        cout<<"key is found at index "<<Search(HT,key)<<endl;
    }
    return 0;
}