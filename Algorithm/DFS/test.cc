#include<iostream>
#include<vector>
#include<string>

using namespace std;

int pos[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
class Solution {
  public:

    bool DFS(vector<vector<char>>& board,int row,int col,int x,int y,vector<vector<int>>& box,int index,string word){


      if(index==word.size())
        return true;

      box[x][y]=1;
      bool ret=false;

      for(int i=0;i<4;i++){
        int new_x=x+pos[i][0];
        int new_y=y+pos[i][1];

        //判断下标的合理性
        if(new_x >= row || new_x<0
            || new_y>=col || new_y<0){
          continue;
        }

        if(board[new_x][new_y]==word[index+1] && box[new_x][new_y]==0){
          ret=DFS(board,row,col,new_x,new_y,box,index+1,word);
        }

      }
      return ret;
    }
    bool exist(vector<vector<char>>& board, string word) {

      int row=board.size();
      int col=board[0].size();

      vector<vector<int>> box(row,vector<int>(col,0));

      bool ret;
      for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
          if(board[i][j]==word[0])
            ret= DFS(board,row,col,i,j,box,0,word);
        }
      }
      return ret;
    }
};









int main(){
  vector<vector<char>> board={{'a','b','c','e'},{'s','f','c','s'},{'a','d','e','e'}};
  string word="abcced";
  Solution s;
  bool ret=s.exist(board,word);
  cout<<ret<<endl;
  return 0;
}
