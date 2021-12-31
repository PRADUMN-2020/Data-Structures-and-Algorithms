#include<iostream>
#define SIZE 10
using namespace std;
int hashval(int key)
{
    return key%SIZE;
}
int probe(int H[],int key)
{
    int index=hashval(key);
    int i=0;
    while(H[(index+i)%SIZE]!=0)
    {
        i++;
    }
    return (index+i)%SIZE;
}
void insert(int H[],int key)
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
int Search(int H[],int key)
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
    int HT[SIZE]={0};
    insert(HT,5);
    insert(HT,25);
    insert(HT,35);
    insert(HT,2);
    insert(HT,12);
    for(int i=0;i<SIZE;i++)
    {
        cout<<i<<" : "<<HT[i]<<endl;
    }
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