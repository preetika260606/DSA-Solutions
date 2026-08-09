#include<iostream>
#include<algorithm>

using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x){
        val=x;
        left=NULL;
        right=NULL;
    }
};

TreeNode * buildTree(){
    int x;
    cin>>x;

    if(x==-1) return NULL;

    TreeNode* root=new TreeNode(x);
    root->left=buildTree();
    root->right=buildTree();

    return root;
}
int solve(TreeNode *root){
    if(!root) return 0;

    if(root->left==NULL && root->right==NULL )
    return 1;

    if(root->left==NULL){
        return 1+solve(root->right);
    }

    if(root->right==NULL) {
        return 1+solve(root->left);
    }


    return 1+min(solve(root->left),solve(root->right));
}

int minDepth(TreeNode *root){
    return solve(root);
}

int main(){
    TreeNode * root=buildTree();
    cout<<minDepth(root)<<endl;
    return 0;
}