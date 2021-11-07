#include<bits/stdc++.h>
using namespace std;
struct node
{
int data;
node*left;
node*right;
}*root=0;              //root node of BST.
int height(node*p)               // function to calculate height of the given tree.
{
    if(p==0)
    {
        return 0;
    }

    return max(height(p->left),height(p->right))+1;
}
node* inpre(node*p)                      // function to return the inorder predecessor node of a node if its left subtree is given.
{if(p==0)
{
    return p;
}
    while(p->right!=0)
    {
        p=p->right;
    }
    return p;
}
node* insucc(node*p)                  // function to return the inorder successor node of a node if its right subtree is given.
{if(p==0)
{
    return p;
}
    while(p->left!=0)
    {
        p=p->left;
    }
    return p;
}
void rinsert(node*p,int key,node*q)    // recursive funtion to insert a given key in the given tree p is assigned with the tree and q with 0
{
 if(p==0)
 {
     p=new node;
     p->data=key;
     p->left=p->right=0;
     if(q)
     {
     if(p->data>q->data)
     {
        q->right=p;
     }
     else
     {
         q->left=p;
     }
     }
     else
     {
        root=p; 
     }
 }
 else
 {
     if(key>p->data)
     {
         rinsert(p->right,key,p);
        //  p=p->right;
     }
     else
     {
         rinsert(p->left,key,p);
        //  p=p->left;
     }
 }

}
node* search(node*p,int key)        // recursive function to search the given key in the given bst, if found returns its address else returns null.
{
    if(p==0)
    {
        return 0;
    }
    if(key<p->data)
    {
        return search(p->left,key);
    }
    else if(key>p->data)
    {
        return search(p->right,key);
    }
    else
    {
        return p;
    }
}
node* rdelete(node*p,int key)          // recursive function to delete the given key from the given tree.
{
    if(p==0)
    {
        return p;
    }
    else if(p->left==0&&p->right==0&&p->data==key)
    {
        return 0;
    }
    if(p->data<key)
    {
      p->right=rdelete(p->right,key);    
    }
   else if(p->data>key)
   {
       p->left=rdelete(p->left,key);
   }
   else
   {
       if(height(p->left)>height(p->right))
       {   node*q=inpre(p->left);
           p->data=q->data;
           p->left=rdelete(p->left,p->data);
       }
       else
       {
           node*q=insucc(p->right);
           p->data=q->data;
           p->right=rdelete(p->right,p->data);
       }
   }
   return p;
}
void inorder(node*p)            // function to perform inorder traversal on the tree.
{
if(p)
{
    inorder(p->left);
    cout<<p->data<<" ";
    inorder(p->right);
}
}
int main()
{
    rinsert(root,10,0);
    rinsert(root,5,0);
    rinsert(root,20,0);
    rinsert(root,15,0);
    rinsert(root,25,0);
    inorder(root);
    cout<<endl;
    rdelete(root,10);
    inorder(root);
    cout<<root->data<<" expected 15"<<endl;
    cout<<root->left->data<<" expected 5"<<endl;
    cout<<root->right->data<<" expected 20"<<endl;
    cout<<root->right->right->data<<" expected 25"<<endl;
    node*q=search(root,15);
    cout<<q->data<<endl;
return 0;
}