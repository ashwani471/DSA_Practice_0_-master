#include<iostream>
#include "TreeNode.h"
#include "queue"
using namespace std;

void printTree(TreeNode<int> *root){
  cout<<root->data<<":";
  for(int i = 0 ; i < root->children.size() ; i++){
    cout<<root->children[i]<<",";
  }
  cout<<endl;
  for(int i = 0 ; i<root->children.size() ; i++){
    printTree(root->children[i]); 
  }
}

void printTreeLvlWise(TreeNode<int>* root){
   cout<<root->data<<":";
   queue<TreeNode<int>*> pendingNodes;
   pendingNodes.push(root);
   TreeNode<int>* front = pendingNodes.front();
   pendingNodes.pop();
   for(int i = 0 ; i<front->children.size(); i++){
    cout<<front->children[i]->data<<",";
    pendingNodes.push(front->children[i]);
   }
   cout<<endl;
   while(pendingNodes.size()!=0){
    TreeNode<int>* front = pendingNodes.front();
    cout<<front->data<<":";
    pendingNodes.pop();
    for(int i = 0 ; i<front->children.size(); i++){
    cout<<front->children[i]->data<<",";
    pendingNodes.push(front->children[i]);
   }
   cout<<endl;
  }
}

int countNodes(TreeNode<int>* root){
  int ans = 1;
  for(int i = 0;i<root->children.size();i++){
    ans += countNodes(root->children[i]);
  }
  return ans;
}

int sumNodes(TreeNode<int>* root){
  int ans = root->data;
  for(int i = 0 ; i<root->children.size() ; i++){
    ans += sumNodes(root->children[i]);
  }
  return ans;
}

TreeNode<int>* maxDataNode(TreeNode<int>* root){
  TreeNode<int>* max = root;
  for(int i = 0 ; i<root->children.size();i++){
    TreeNode<int>* temp = maxDataNode(root->children[i]);
    if(temp->data > max->data){
      max= temp;
    }
  }
  return max;
}

TreeNode<int>* takeInputLvlWise(){
  int rootData;
  cout<<"Enter data"<<endl;
  cin>>rootData;

  TreeNode<int>* root = new TreeNode<int>(rootData);
  queue<TreeNode<int>* > pendingNodes;
  pendingNodes.push(root);
  while(pendingNodes.size() != 0 ){
    TreeNode<int>* front = pendingNodes.front();
    pendingNodes.pop();
    cout<<"Enter num of children of "<<front->data<<endl;
    int numChild;
    cin>>numChild;
    for(int i = 0 ; i<numChild ; i++){
      int childData;
      cout<<"Enter"<<i+1<<"child of "<<front->data<<endl;
      cin>>childData;
      TreeNode<int> *child = new TreeNode<int>(childData);
      front->children.push_back(child);
      pendingNodes.push(child);
    }
  }
  return root;
}

TreeNode<int>* takeInput(){
  int rootdata;
  cout<<"Enter data" << endl;
  cin>>rootdata;
  TreeNode<int> *root = new TreeNode<int>(rootdata);

  int n;
  cout<<"Enter number of children of"<<rootdata<<endl;
  cin>>n;
  for(int i = 0 ;i<n ; i++){
    TreeNode<int>* child = takeInput();
    root->children.push_back(child);
  }
  return root;
}

int main(){
  // TreeNode<int> *root = new TreeNode<int>(1);
  // TreeNode<int> *node1 = new TreeNode<int>(2);
  // TreeNode<int> *node2 =  new TreeNode<int>(3);
  // root->children.push_back(node1);
  // root->children.push_back(node2);
  // printTree(root);
  TreeNode<int>* root = takeInputLvlWise();
  printTreeLvlWise(root);
  int sum = sumNodes(root);
  cout<<sum<<endl;
}