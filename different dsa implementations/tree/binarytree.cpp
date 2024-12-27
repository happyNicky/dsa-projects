#include<iostream>
using namespace std;

struct node
{ int data;
  node* right;
  node* left;
  node* root=nullptr;

  node* getNewNode(int data)
  {   node* temp=new node;
      temp->data=data;
       temp->right=temp->left=nullptr;
       return temp;
  }
  node* insertNode(node* root,int x)
  {    if(root==nullptr)
          root=getNewNode(x); 
      else if(x>root->data)
        root->right=insertNode(root->right,x);
      else if(x<root->data)
       root->left=insertNode(root->left,x);
   return root;
  }
  bool search(node* root,int x)
    {  if(root==nullptr)
          return false;
       else if(root->data==x)
          return true;
       else if(x>root->data)
         return  search(root->right,x);
        else
         return search(root->left,x);
    }
    int min(node* root)
    {    int prev=root->data;
         if(root==nullptr)
        {  cout<<"the tree is empty"<<endl;
           return -1;
        }
        else if(root->right==nullptr&& root->left==nullptr)
            return prev;
        else 
           return min(root->left);

    }
};

int main()
{  node k;
 k.root= k.insertNode(k.root,10);
  k.insertNode(k.root,5);
  k.insertNode(k.root,11);
  k.insertNode(k.root,20);
  k.insertNode(k.root,3);
  k.insertNode(k.root,0);
  cout<<k.search(k.root,11);
  cout<<"min: "<<k.min(k.root);
}