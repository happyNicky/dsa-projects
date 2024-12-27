#include<iostream>
#include<math.h>
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
    int findMin(node* root)
    {    if(root==nullptr)
        {  cout<<"the tree is empty"<<endl;
           return -1;
        }
        else if(root->right==nullptr)
            return root->data;
           return findMin(root->left);
    }
    int findMax(node* root)
    {   if(root==nullptr)
        {   cout<<"the tree is empty"<<endl;
             return -1;
        }
        else if(root->right== nullptr)
           return root->data;
        return findMax(root->right);
    }
    int heightOfATree(node* root)
    {   if(root==nullptr)
             return -1;
       return max(heightOfATree(root->right),heightOfATree(root->left))+1;
    }
    void preOrderTraversal(node* root)
    {   if(root==nullptr)
            return;
          cout<<root->data<<" ";
        preOrderTraversal(root->left);
        preOrderTraversal(root->right);

    }
    void inOrderTraversal(node* root)
    {   if(root==nullptr)
             return;
       inOrderTraversal(root->left);
       cout<<root->data<<" ";
       inOrderTraversal(root->right);

    }
    void postOrderTraversal(node* root)
    {   if(root==nullptr)
            return;
        postOrderTraversal(root->right);
        cout<<root->data<<" ";
        postOrderTraversal(root->left);
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
  k.insertNode(k.root,6);
  //cout<<k.search(k.root,11);
 // cout<<"min: "<<k.findMin(k.root);

 cout<<"the height of the tree is: "<<k.heightOfATree(k.root)<<endl;
 cout<<"pre order traversal of the tree is: ";
 k.preOrderTraversal(k.root);
 cout<<endl;
cout<<"in order traversal of the tree is: ";
 k.inOrderTraversal(k.root);
 cout<<endl;
 cout<<"post order traversal of the tree  is: ";
 k.postOrderTraversal(k.root);
 cout<<endl;
}