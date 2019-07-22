#include<iostream>
#include<vector>
#include<queue>
#include<stack>
using namespace std;
struct TreeNode
{
    int val;
    struct TreeNode* left=nullptr;
    struct TreeNode* right=nullptr;
};
TreeNode* root=nullptr;

void displayTree(TreeNode* root)
{
    if(root)
    {
        displayTree(root->left);
        cout<<root->val<<" ";
        displayTree(root->right);
    }
}



TreeNode* arrayToBst(TreeNode* &root,vector<int> &nums,int beg,int end1)
{
    if(beg<=end1)
    {
      int r = (beg+end1)/2;

       root=(TreeNode*)malloc(sizeof(TreeNode));
       root->val=nums[r];
       root->left=root->right=nullptr;

      root->left = arrayToBst(root->left,nums,beg,r-1);
      root->right = arrayToBst(root->right,nums,r+1,end1);

      return root;
    }
    return root;
}
int main()
{
    int n;
    vector<int> nums;
    cout<<"Enter elements:(Enter -95) to stop:";
    cin>>n;
    while(n!=-95)
    {
        nums.push_back(n);
        cin>>n;
    }
   root =  arrayToBst(root,nums,0,nums.size()-1);
      displayTree(root);
}
