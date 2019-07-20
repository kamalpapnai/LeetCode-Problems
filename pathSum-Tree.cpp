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

void displayTree(tr root)
{

    if(root)
    {
        displayTree(root->left);
        cout<<root->val;
        displayTree(root->right);
    }
}
int cur_sum=0;

 bool hasPathSum(TreeNode* root, int sum) {
    if(root)
    {
       cur_sum +=root->val;
       if(root->left && hasPathSum(root->left,sum))
        return 1;

       if(root->right && hasPathSum(root->right,sum))
        return 1;

        if(cur_sum==sum && root->right==NULL && root->left==NULL)
            return 1;

        cur_sum=cur_sum-root->val;
        return 0;
    }
    else if(root==NULL && sum==0)
    {
        return 0;
    }
    else{
        if(cur_sum==sum)
            return 1;
        else
            return 0;
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
    cout<<"Sum:"<<"\n";
    int s;
    cin>>s;

    displayTree(root);
    cout<<"\n";

    cout<<hasPathSum(root,s);
    return 0;
}

/** Be careful of the smaller corner cases while framing recursion " **/
