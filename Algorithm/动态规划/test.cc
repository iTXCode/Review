#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
  public:

    int backPackII(int m, vector<int> &A, vector<int> &V) {
      // write your code here

      if (A.empty() || V.empty() || m < 0){
        return 0;
      }

      //所�的数据是合理可用的
      int row = A.size();
      vector<vector<int>> map(row + 1, vector<int>(m + 1, 0));
      //两种状态
      //F(0,j)=0:没有物品可以装入包中
      //F(i,0)=0:包中没有多余空间可供使用

      for (int i = 1; i <= row; i++){
        for (int j = 1; j <= m; j++){
          if (A[i - 1] > j){
            map[i][j] = map[i - 1][j];
          }
          else{
            map[i][j] = max(map[i - 1][j - A[i - 1]] + V[i - 1], map[i - 1][j]);
          }
        }
      }
      for (int i = 0; i < row + 1; i++){
        for (int j = 0; j < m + 1; j++){
          printf("%2d  |",map[i][j]);
        }
        cout << endl;
      }
      return map[row][m];
    }
};

int main(){
  vector<int> A{ 2, 3,5,7  };
  vector<int> V{ 1, 5, 2, 4 };
  Solution s;
  int ret=s.backPackII(10,A, V);
  cout << ret << endl;
  return 0;
}

