class Solution {
public:
    int mx=0;
    int solve(TreeNode* root)
    {
        if(root==nullptr) return 0;
        int lh = solve(root->left);
        int rh = solve(root->right);
        mx=max(mx,lh+rh);
        return 1+max(lh,rh);
    }
    int diameterOfBinaryTree(TreeNode* root)
    {
       int x = solve(root);
       return mx;
    }
};