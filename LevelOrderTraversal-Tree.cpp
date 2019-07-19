#include<iostream>
#include<vector>
#include<queue>
using namespace std;
struct TreeNode
{
    int val;
    struct TreeNode* left=nullptr;
    struct TreeNode* right=nullptr;
};
TreeNode* root=nullptr;
TreeNode* insertNode(TreeNode* &root,int k)
{
    if(root==nullptr)
    {
        root = (TreeNode*)malloc(sizeof(TreeNode));
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
void displayTree(TreeNode* root)
{
    if(root)
    {
        displayTree(root->left);
        cout<<root->val<<" ";
        displayTree(root->right);
    }
}
vector<vector<int> > levelOrder(TreeNode* root)
{
    queue<TreeNode*> q;
    vector<vector<int> > res;
    int c;
    vector<int> cur;

    if(!root)
        return res;

    q.push(root);

    while(!q.empty())
    {
       int c=q.size();

       for(int k=0;k<c;k++)
       {
           int g = q.front()->val;
           cur.push_back(g);

            TreeNode* t = q.front();

            if(t->left)
              q.push(t->left);

            if(t->right)
              q.push(t->right);

           q.pop();
       }
       res.push_back(cur);
       cur.clear();
    }
    return res;
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
    displayTree(root);

    vector<vector<int> > r=levelOrder(root);

    cout<<"\n";
    for(int i=0;i<r.size();i++){
        for(int j=0;j<r[i].size();j++){
            cout<<r[i][j]<<" ";
        }
        cout<<"\n";
    }
    return 0;
}
