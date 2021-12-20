#include<iostream>
using namespace std;
insert(int heap[],int n)         // function to insert an element at n th (next to the heap array) position of heap array to the max heap
{
    int temp,i=n;
    temp=heap[n];
    while(i>1&&temp>heap[i/2])     // for min heap just put less than sign after temp
    {
        heap[i]=heap[i/2];         // T = O(log(n)) where n are the number of elements in the heap
        i=i/2;
    }
    heap[i]=temp;
}
void create_heap(int a[],int n)  // funtion to convert an array to a heap
{
   for(int i=2;i<=n;i++)
   {
       insert(a,i);
   }
}
void delete_heap(int a[],int n) // funtion to delete an element from the  max heap
{
    int x,i,j;
    x=a[1];
    a[1]=a[n];
    i=1;
    j=2*i;
    while(j<n-1)
    {
        if(a[j+1]>a[j])
        {
            j++;               // T = O(log(n)) where n are the number of elements in the heap
        }
        if(a[i]<a[j])
        {
          swap(a[i],a[j]);
          i=j;
          j=2*i;
        }
        else
        {
            break;
        }
    }
    a[n]=x;
}
void heapsort(int array[],int n)       // funtion to sort array using heap sort.
{
    create_heap(array,n);             // T = O(n*log(n)) where n are the number of elements in the heap
    for(int i=n;i>=2;i--)
    {
        delete_heap(array,i);
    }
}
void adjust(int array[],int i,int n)
{
  int j=2*i;
  while(j<n)
  {
      if(array[j+1]>array[j])
      {
          j++;
      }
      if(array[j]>array[i])
      {
         swap(array[i],array[j]);
         i=j;
         j=2*i;
      }
      else
      break;
  }
}
void heapify(int array[],int n)         // T = O(n) where n are the number of elements in the heap
{
  for(int i=n;i>=1;i--)
  {
      adjust(array,i,n);
  }
}
int main()
{
    int array[]={0,10,20,30,25,5,40,35};
    // create_heap(array,7);
    // for(int i=1;i<=7;i++)
    // {
    //     cout<<array[i]<<" ";
    // }
    // delete_heap(array,7);
    // for(int i=1;i<=6;i++)
    // {
    //     cout<<array[i]<<" ";
    // }
    // cout<<endl;
    // cout<<array[7]<<endl;
    // heapsort(array,7);
    // for(int i=1;i<=7;i++)
    // {
    //  cout<<array[i]<<" ";   
    // }
    heapify(array,7);
    for(int i=1;i<=7;i++)
    {
        cout<<array[i]<<" ";
    }
    return 0;
}