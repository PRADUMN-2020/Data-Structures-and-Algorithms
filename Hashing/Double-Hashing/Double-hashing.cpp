#include<iostream>
#define SIZE 10        
using namespace std;
int hashval(int key)    // function to give the index at which the key is to be stored in the hash table.
{
    return key%SIZE;
}
int double_hash(int H[],int key)  // function to give the index to the first vacant space according to the  double hashing hash function h`(x)=(h1(x)+i*h2(x))%SIZE where i=0,1,2......, here h1(x)=x%SIZE and h2(x)= R-(x%R), here R is the just smaller prime no of the size.
{
    int h1=hashval(key);
    int h2=7-(key%7);
    int i=0;
    while(H[(h1+i*h2)%SIZE]!=0)
    {
        i++;
    }
    return (h1+i*h2)%SIZE;
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
     index=double_hash(H,key);
     H[index]=key;
   }
}
int Search(int H[],int key)  // function to return the index of the given key in the given hash table.
{
    int h1=hashval(key);
    int h2=7-(key%7);
    int i=0;
    while(H[(h1+i*h2)%SIZE]!=key&&H[(h1+i*h2)%SIZE]!=0)
    {
        i++;
    }
    if(H[(h1+i*h2)%SIZE]==0)
    {
       return -1;
    }
    return (h1+i*h2)%SIZE;
}
int main()
{
    int HT[SIZE]={0};   // Creating hash table.
    // Inserting keys in the hash table.
    insert(HT,5);
    insert(HT,25);
    insert(HT,15);
    insert(HT,35);
    insert(HT,95);
    // Printing the hash table.
    for(int i=0;i<SIZE;i++)
    {
        cout<<i<<" : "<<HT[i]<<endl;
    }
    // Searching a key in the hash table.
    int key=26;
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