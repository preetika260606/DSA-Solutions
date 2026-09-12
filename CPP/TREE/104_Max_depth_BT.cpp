#include<iostream>
#include<algorithm>

using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x):val(x),left(nullptr),right(nullptr){}
};

int solve(TreeNode *root){
    if(root==nullptr) return 0;

    int left=solve(root->left);
    int right=solve(root->right);

    return 1+max(left,right);
}

int maxDepth(TreeNode *root){
    return solve(root);
}

int main(){
    // Create a simple binary tree for testing
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    int depth = maxDepth(root);
    cout << "Maximum depth of the binary tree: " << depth << endl;
}