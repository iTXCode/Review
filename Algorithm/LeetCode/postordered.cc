#include<iostream>
#include<stack>
#include<vector>

using namespace std;

class Solution {
  public:
    bool verifyPostorder(vector<int>& postorder) {
      stack<int> s;
      int root=INT_MAX;
      //假设所给的二叉搜索数是某个大根树的左子树(并不影响其二叉树的性质)
      for(int i=postorder.size()-1;i>=0;--i){
        if(root<postorder[i])
          return false;
        while(!s.empty() && s.top()>postorder[i]){
          root=s.top();
          s.pop();
        }
        s.push(postorder[i]);
      }
      return true;
    }
};

//方法二
class Solution1 {
  public:
    bool verifyPostorder(vector<int>& postorder){
      return DFS(postorder,0,postorder.size()-1);

    }

    bool DFS(vector<int>& postorder,int left,int right){
      if(left>=right){
        return true;

      }
      int index=left;
      while(postorder[index]<postorder[right])
        index++;

      int flag=index;
      while(postorder[flag]>postorder[right]){
        flag++;

      }
      return flag==right&&DFS(postorder,left,index-1) && DFS(postorder,index,right-1);

    }

};


