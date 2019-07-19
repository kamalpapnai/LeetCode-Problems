#include<iostream>
#include<vector>
#include<stack>
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
void iterativeInorder(TreeNode* root)
{
    stack<TreeNode*> s;
    s.push(root);

    while(!s.empty())
    {
        TreeNode* top = s.top();

        if(top->left)
        {
            s.push(top->left);
            top->left = nullptr;
        }
        else
            {
            cout<<top->val;
            s.pop();

            if(top->right)
                s.push(top->right);
        }
    }
}
int max_depth(TreeNode* root)
{
    if(root==nullptr)
        return 0;
    else
        return 1+max(max_depth(root->left),max_depth(root->right));

}

int bfs(TreeNode* root)
{
    queue<TreeNode*> q;
    int c,d=0;
    if(root==nullptr)
        return 0;

    q.push(root);

    while(!q.empty())
    {
        d++;
        int c=q.size();
        for(int i=0;i<c;i++)
        {
            if(q.front()->left)
                q.push(q.front()->left);
            if(q.front()->right)
                q.push(q.front()->right);
            q.pop();
        }
    }
    return d;
}

int main()
{
    insertNode(root,3);
    insertNode(root,9);
    insertNode(root,20);
    insertNode(root,NULL);
    insertNode(root,NULL);
    insertNode(root,15);
    insertNode(root,7);
    iterativeInorder(root);

    cout<<" "<<max_depth(root);
    cout<<" "<<bfs(root);
    return 0;
}

/** To find max depth of a tree , there can be mainly 2 approaches:
  1.DFS : this can be done simply by recursion
  2.BFS :this can be done by using queue data structure.

  Result Analysis: DFS takes more time as compared to BFS.  **/


