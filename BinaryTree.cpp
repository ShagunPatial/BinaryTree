// BINARY TREE :-
/** 
 * INSERTION
 * DELETION
 * TRAVERSAL
 ***/

#include<bits/stdc++.h>
using namespace std;
struct Node{
    int data;   // data 
    Node* l;    // address of left node
    Node* r;   // address of right node
};

// initialization of new Node
Node* getnewnode(int data)
{
    Node* temp= new Node;
    temp->data=data;
    temp->l=NULL;
    temp->r=NULL;
    return temp;
}

// Insertion of New Node
Node* insert(Node* root,int data)
{ if(root==NULL) {root=getnewnode(data);}
  else
  {
      queue<Node*>q;
      q.push(root);
      
      while(!q.empty())
      {  Node * t=q.front();
          q.pop();
          if(!t->l) {
              t->l=getnewnode(data);
              break;
          }
          else{
              q.push(t->l);
          }
          if(!t->r)
          {
              t->r=getnewnode(data);
              break;

          }
          else
          {
              q.push(t->r);
          }
          
      }
      
  }
  

return root;
}
// Printing the data in Node (preorder Fashion)
void pri(Node* root)
{
    if(root==NULL) return ;
    cout<<root->data<<" -- ";
    pri(root->l);
    pri(root->r);
}
// Helper Function which delete the Node 't'
void dell(Node* root,Node *t)
{
    queue<Node*>q;
    q.push(root);
    while(!q.empty())
    { Node* ri=q.front();
      q.pop();
      if(ri->l==t)
      {
          ri->l=NULL;
          break;
      }
      if(ri->r==t)
      {
          ri->r=NULL;
          break;
      }
      if(ri->l) q.push(ri->l);
      if(ri->r) q.push(ri->r);

    }
}
// DELETION of specific data from tree
Node* del(Node* root,int k)
{ if(root==NULL) return root;
  //Case 1: if required data is at leaf Node
  if(root->data==k && !root->r && !root->l) 
  {
      root=NULL;
  }
  // Case 2: if required NODE is not a leaf node
  /**In this case we have to replace the the required Node
   *  which is to be deleted with the last Node of Binary tree
   * So for this we have to do following step:
   * 1-  Get the address of Node which is to be deleted 
   * 2-  Get the address of Last node
   * 3-  Replace  the data of required Node with the last Node data
   * 4- Delete the last Node using helper function i.e. "dell" 
  **/
   queue<Node*>q;
   q.push(root);
   Node*w,*t;
   while(!q.empty())
   { t= q.front();
     q.pop();
     if(t->data==k)  w=t;  // w is required Node 
     if(t->l) q.push(t->l);
     if(t->r) q.push(t->r); 

   }   
   // after this t hold  the address of last Node
   w->data= t->data; // replacement of data i.e. assigining the data of last Node 
   dell(root,t);  // delete the last Node
   return root; 
}

  
  



 
int main()
{  Node* root=NULL;  //  initialzing root to NULL
    root=insert(root,1); 
    root=insert(root,2);  
    root=insert(root,3);
    root=insert(root,4);
    root=insert(root,5);
    root=insert(root,6);
    root=insert(root,7);
    
    pri(root);    // printing tree
    cout<<endl;
    
    root=del(root,6);  // deleting 6 from tree
    cout<<"AFTER DELETING 6"<<endl;
    pri(root);
    cout<<endl;
    
    root=del(root,1);
    cout<<"AFTER DELETING 1"<<endl;
    pri(root);
    cout<<endl;
   
    root=del(root,3);
     cout<<"AFTER DELETING 3"<<endl;
    pri(root);
    cout<<endl;
    
    root=del(root,7);
     cout<<"AFTER DELETING 7"<<endl;
    pri(root);
    cout<<endl;
    
    root=del(root,2);
     cout<<"AFTER DELETING 2"<<endl;
    pri(root);
    
    return 0;
}