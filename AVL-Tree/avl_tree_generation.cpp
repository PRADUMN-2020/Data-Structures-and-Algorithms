#include<bits/stdc++.h>
using namespace std;
struct node
{
int data;
int height;
node*left;
node*right;
}*root=0;
int nodeheight(node*p)   //function to calculate given node's height.
{
    int hl=0,hr=0;
    if(p)
    {
        if(p->left)
        {
            hl=p->left->height;
        }
        if(p->right)
        {
            hr=p->right->height;
        }
        return max(hl,hr)+1;
    }
    else
    {
        return 0;
    }
}

void llrotation(node*p,node*q)      //funtion to perform ll rotaion on the given node taking previours node as its another argument.
{
node*pl=p->left;
node*plr=pl->right;
pl->right=p;
p->left=plr;
if(q)
{
    if(q->left==p)
    {
        q->left=pl;
    }
    else
    {
        q->right=pl;
    }
}
else
{
    root=pl;
}
p->height=nodeheight(p);
pl->height=nodeheight(pl);

if(q)
{
    q->height=nodeheight(q);
}

}
void rrrotation(node*p,node*q)   //funtion to perform rr rotaion on the given node taking previours node as its another argument.
{
node*pr=p->right;
node*prl=pr->left;
pr->left=p;
p->right=prl;
if(q)
{
    if(q->left==p)
    {
        q->left=pr;
    }
    else
    {
        q->right=pr;
    }
}
else
{
    root=pr;
}
p->height=nodeheight(p);
pr->height=nodeheight(pr);

if(q)
{
    q->height=nodeheight(q);
}
}
void lrrotation(node*p,node*q)    //funtion to perform lr rotaion on the given node taking previours node as its another argument.
{
node*pl=p->left;
node*plr=pl->right;
pl->right=plr->left;
p->left=plr->right;
plr->left=pl;
plr->right=p;
if(q)
{
    if(q->left==p)
    {
        q->left=plr;
    }
    else
    {
        q->right=plr;
    }
}
else
{
    root=plr;
}
p->height=nodeheight(p);
pl->height=nodeheight(pl);
plr->height=nodeheight(plr);
if(q)
{
    q->height=nodeheight(q);
}
}
void rlrotation(node*p,node*q)    //funtion to perform rl rotaion on the given node taking previours node as its another argument.
{
node*pr=p->right;
node*prl=pr->left;
p->right=prl->left;
pr->left=prl->right;
prl->left=p;
prl->right=pr;
if(q)
{
    if(q->left==p)
    {
        q->left=prl;
    }
    else
    {
        q->right=prl;
    }
}
else
{
    root=prl;
}
p->height=nodeheight(p);
pr->height=nodeheight(pr);
prl->height=nodeheight(prl);
if(q)
{
    q->height=nodeheight(q);
}
}
int balancefactor(node*p)                // function to calculate the balance factror of the given node.
{
    int hl,hr;
    hl=hr=0;
    if(p->left)
    {
        hl=p->left->height;
    }
    if(p->right)
    {
        hr=p->right->height;
    }
    return hl-hr;
}
void rinsert(node*p,int key,node*q)   //recursive function to insert in an AVL tree.
{
 if(p==0)
 {
     p=new node;
     p->data=key;
     p->height=1;
     p->left=p->right=0;
     if(q)
     {
     if(p->data>q->data)
      q->right=p;
     else
      q->left=p;
     }
     else
        root=p; 
 }
 else
 {
     if(key>p->data)
     {
         rinsert(p->right,key,p);
         p->height=nodeheight(p);
         if(balancefactor(p)==2&&balancefactor(p->left)==1)
         {
             llrotation(p,q);
         }
         else if(balancefactor(p)==2&&balancefactor(p->left)==-1)
         {
             lrrotation(p,q);
         }
         else if(balancefactor(p)==-2&&balancefactor(p->right)==1)
         {
             rlrotation(p,q);
         }
         else if(balancefactor(p)==-2&&balancefactor(p->right)==-1)
         {
             rrrotation(p,q);
         }
     }
     else
     {
         rinsert(p->left,key,p);
         p->height=nodeheight(p);
         if(balancefactor(p)==2&&balancefactor(p->left)==1)
         {
             llrotation(p,q);
         }
         else if(balancefactor(p)==2&&balancefactor(p->left)==-1)
         {
             lrrotation(p,q);
         }
         else if(balancefactor(p)==-2&&balancefactor(p->right)==1)
         {
             rlrotation(p,q);
         }
         else if(balancefactor(p)==-2&&balancefactor(p->right)==-1)
         {
             rrrotation(p,q);
         }
     }
 }

}
node* llrotation(node*p)
{
node*pl=p->left;
node*plr=pl->right;
p->left=plr;
pl->right=p;
p->height=nodeheight(p);
pl->height=nodeheight(pl);
return pl;
}
node* lrrotation(node*p)
{
node*pl=p->left;    
node*plr=pl->right;
p->left=plr->right;
pl->right=plr->left;
plr->left=pl;
plr->right=p;
p->height=nodeheight(p);
pl->height=nodeheight(pl);
plr->height=nodeheight(plr);
return plr;
}
node* rrrotation(node*p)
{
node*pr=p->right;
node*prl=pr->left;
p->right=prl;
pr->left=p;
p->height=nodeheight(p);
pr->height=nodeheight(pr);
return pr;
}
node* rlrotation(node*p)
{
node*pr=p->right;
node*prl=pr->left;
p->right=prl->left;
pr->left=prl->right;
prl->left=p;
prl->right=pr;
p->height=nodeheight(p);
pr->height=nodeheight(pr);
prl->height=nodeheight(prl);
return prl;
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
node* rdelete(node*p,int key)          // recursive function to delete the given key from the given tree.
{
    if(p==0)
    {
        return p;
    }
    else if(p->left==0&&p->right==0&&p->data==key)
    {
        delete p;
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
       if(nodeheight(p->left)>nodeheight(p->right))
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
   p->height=nodeheight(p);

   if(balancefactor(p)==2&&balancefactor(p->left)==1)
   {
       return llrotation(p);
   }
   else if(balancefactor(p)==2&&balancefactor(p->left)==-1)
   {

       return lrrotation(p);
   }
   else if(balancefactor(p)==2&&balancefactor(p->left)==0)
   {
       return llrotation(p);
   }
   else if(balancefactor(p)==-2&&balancefactor(p->right)==-1)
   {
       return rrrotation(p);
   }
   else if(balancefactor(p)==-2&&balancefactor(p->right)==1)
   {
       return rlrotation(p);
   }
   else if(balancefactor(p)==-2&&balancefactor(p->right)==0)
   {
    return rrrotation(p);
   }
   return p;
}
void inorder(node*p)   // function to perform inorder traversal on the avl tree.
{
if(p)
{
    inorder(p->left);
    cout<<p->data<<" ";
    inorder(p->right);
}
}
void inorderheight(node*p)   // function to print the heights of the nodes in the order of their inorder traversal or increasing node data values.
{
    if(p)
    {
        inorderheight(p->left);
        cout<<p->height<<" ";
        inorderheight(p->right);
    }
}
int main()
{
    // rinsert(root,10,0);
    // rinsert(root,5,0);
    // rinsert(root,20,0);
    // rinsert(root,15,0);
    // rinsert(root,25,0);
    // inorder(root);
    // cout<<endl;
    // inorderheight(root);
    // cout<<endl;
    // rinsert(root,28,0);
    // inorder(root);
    // cout<<endl;
    // inorderheight(root);
    rinsert(root,30,0);
     
     rinsert(root,20,0);
     
    rinsert(root,40,0);
     
     rinsert(root,10,0);
     
     rinsert(root,25,0);
     
     rinsert(root,35,0);
     
     rinsert(root,5,0);
      inorder(root);
     cout<<endl;
     root=rdelete(root,40);
     inorder(root);
     cout<<endl;
    cout<<root->data<<" expected 20"<<endl;
    cout<<root->left->data<<" expected 10"<<endl;
    cout<<root->right->data<<" expected 30"<<endl;
    cout<<root->left->left->data<<" expected 5"<<endl;
    cout<<root->right->left->data<<" expected 25"<<endl;
    cout<<root->right->right->data<<" expected 35"<<endl;
    
return 0;
}