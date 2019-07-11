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
tr p = nullptr, q=nullptr;

void displayTree(tr root){
if(root!=nullptr){
    displayTree(root->left);
    cout<<root->val<<" ";
    displayTree(root->right);
}}

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
bool b=1;
bool isSameTree(TreeNode* p, TreeNode* q) {


        if(p==NULL && q!=NULL || p!=NULL && q==NULL)
            return 0;

        else if(p==NULL && q==NULL)
            return 1;

        else{

            if(p->val != q->val)
                return 0;

            else{
                  return  isSameTree(p->left,q->left) *  isSameTree(p->right,q->right);
            }
        }
}
int main()
{
    insertNode(p,5);
    insertNode(p,6);
    insertNode(p,7);
    insertNode(p,8);
    insertNode(p,10);

    insertNode(q,5);
    insertNode(q,NULL);
    insertNode(q,7);
    insertNode(q,8);

    cout<<isSameTree(p,q);
    return 0;
}
