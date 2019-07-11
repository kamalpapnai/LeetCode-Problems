#include<iostream>
#include<vector>
#include<stack>
using namespace std;
struct TreeNode
{
    int val;
    struct TreeNode *left=nullptr,*right=nullptr;
};
typedef TreeNode* tr;
tr root = nullptr;

void displayTree(tr root){
if(root!=nullptr){
    displayTree(root->left);
    cout<<root->val<<" ";
    displayTree(root->right);
}}
void IterativeInorder(tr root)
{
   stack<tr> s;
   if(root!=nullptr)
   s.push(root);

   while(!s.empty()){
     tr ptr = s.top();

     if(ptr->left){
         s.push(ptr->left);
         ptr->left=nullptr;
     }
     else{
         cout<<ptr->val;
         s.pop();
         if(ptr->right)
          s.push(ptr->right);
     }
   }
}
TreeNode* insertNode(TreeNode* &root,int k)
{
    if(root==nullptr)
    {
        root = (struct TreeNode*)malloc(sizeof(TreeNode));
        root->val = k;
        root->left= root->right =nullptr;
        return root;
    }
    else if(root->left==nullptr){
        insertNode(root->left,k);
     }
    else if(root->left){
        if(root->right && root->left->right==nullptr){
            insertNode(root->left,k);
        }
        else{
            insertNode(root->right,k);
        }
    }
}
int main(){

    insertNode(root,5);
    insertNode(root,6);
    insertNode(root,7);
    insertNode(root,1);
    insertNode(root,9);
    displayTree(root);cout<<"\n";
    IterativeInorder(root);
    return 0;
}
