#include<iostream>
#include<vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode():val(0),left(nullptr),right(nullptr){}
};
void preorder(TreeNode *root,vector<int>&ans){
    if(root==nullptr) return;
    ans.push_back(root->val);
    preorder(root->left,ans);
    preorder(root->right,ans);
}
vector<int>preorderTraversal(TreeNode* root){
    vector<int>ans;
    preorder(root,ans);
    return ans;
}
int main(){
    int n;
    cin>>n;
    vector<int>ans(n);
    for(int i=0;i<n;i++){
        cin>>ans[i];
    }
    for(int i=0;i<n;i++){
        cout<<ans[i]<<" ";
    }
    return 0;

}