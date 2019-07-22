#include<iostream>
#include<queue>
using namespace std;
struct TreeNode
{
    int val;
    struct TreeNode *left=nullptr,*right=nullptr;
};
typedef TreeNode* tr;
tr root = nullptr;
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
TreeNode* invertTree(TreeNode* root) {
    queue<TreeNode*> q;
        TreeNode* k;
        if(!root)
            return root;

         q.push(root);

        while(!q.empty())
        {

            k=NULL;
           TreeNode* ptr = q.front();

            if(ptr->left || ptr->right)
            {

               if(ptr->left)
              {
                q.push(ptr->left);
                k = ptr->left;
              }

               if(ptr->right)
              {
                q.push(ptr->right);
                 ptr->left=ptr->right;
                  if(k)
                      ptr->right = k;
                   else
                       ptr->right = NULL;
               }
                else
               {
                  ptr->right=k;
                ptr->left=NULL;
               }



            }
             q.pop();
        }
        return root;
    }
    void displayTree(TreeNode* root)
    {
        if(root)
        {

            displayTree(root->left);
            cout<<root->val;
            displayTree(root->right);
        }
    }
int main()

{
     int n;
    cout<<"Enter elements:(Enter -95) to stop:";
    cin>>n;
    while(n!=-95)
    {
        insertNode(root,n);
        cin>>n;
    }
    displayTree(root);cout<<"\n";
    root = invertTree(root);
    displayTree(root);

    return 0;
}
