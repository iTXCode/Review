//最近公共祖先,二叉搜索数版本
class Solution {
  public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
      if(p->val< root->val && q->val <root->val){
        return lowestCommonAncestor(root->left,p,q);

      }

      if(p->val > root->val && q->val > root->val){
        return lowestCommonAncestor(root->right,p,q);

      }

      return root;

    }

};


//递归版本,二叉树的版本
class Solution {
  public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
      if(root == nullptr || p==root || q == root){
        return root;

      }

      TreeNode* left=lowestCommonAncestor(root->left,p,q);
      TreeNode* right=lowestCommonAncestor(root->right,p,q);

      if(left == nullptr){
        return right;

      }

      if(right==nullptr){
        return left;

      }
      return root;

    }

};
