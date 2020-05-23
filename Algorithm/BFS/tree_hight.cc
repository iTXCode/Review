#include<iostream>
#include<queue>

using namespace std;

struct TreeNode{
  
  TreeNode(int _val){
    val=_val;
    left=nullptr;
    right=nullptr;
  }
  int val;
  TreeNode* left;
  TreeNode* right;
};
class Solution {
  public:
    int maxDepth(TreeNode* root) {
      if(root==nullptr){
        return 0;

      }

      int Depth=0;

      queue<TreeNode*> q;
      q.push(root);
      while(!q.empty()){
        int n=q.size();
        while(n--){
          TreeNode* head=q.front();
          q.pop();

          if(head->left || head->right){
            if(head->left)
              q.push(head->left);
            if(head->right)
              q.push(head->right);

          }

        }
        ++Depth;

      }
      return Depth;

    }

};


class Tree_High{
public:
  int max_Depth(TreeNode* root){
    if(root ==nullptr){
      return 0;
    }

    int left=max_Depth(root->left);
    int right=max_Depth(root->right);

    return 1+(left>right?left:right);
  }
};
