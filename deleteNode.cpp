#include<iostream>
#include<vector>
using namespace std;
struct TreeNode
{
    int value;
    struct TreeNode* left=nullptr;
    struct TreeNode* right=nullptr;
};
vector<TreeNode*> res;
struct TreeNode* root=nullptr;

TreeNode* insertNode(TreeNode* &root,int k)
{
    if(root==nullptr)
    { cout<<"value:"<<k<<"\n";
        root = (struct TreeNode*)malloc(sizeof(TreeNode));
        root->value = k;
        root->left= root->right =nullptr;
        return root;
    }
    else if(root->left==nullptr||root->left->right)
        {
      insertNode(root->right,k);;}

    else{
       insertNode(root->left,k);}
}
TreeNode* findNode(TreeNode* root,int k)
{
    if(root->value==k){
        return root;
    }
    else if(root->value>k)
        findNode(root->left,k);
    else
        findNode(root->right,k);
}
vector<TreeNode*> deleteNode(TreeNode* &root,vector<int> r)
{
    for(int k:r)
    {
        TreeNode* point = findNode(root,k);
        if(point->left)
            res.push_back(point->left);
        if(point->right)
            res.push_back(point->right);
        point=nullptr;

    }
    return res;
}
void displayTree(TreeNode* root)
{
    if(root!=nullptr)
    {
        displayTree(root->left);
        cout<<root->value;
        displayTree(root->right);
    }
}
int main()
{   insertNode(root,1);
    insertNode(root,2);
    insertNode(root,3);
    insertNode(root,4);
    insertNode(root,5);
    insertNode(root,6);
    insertNode(root,7);
    displayTree(root);
    cout<<endl;
    vector<TreeNode*> h;
    h = deleteNode(root,{3,5});
    for(int i=0;i<h.size();i++){
        displayTree(h[i]);
    }
    return 0;
}
