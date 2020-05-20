//#include<iostream>
//#include<vector>
//#include<deque>
//
//using namespace std; 
//
//void Test(){
//  vector<vector<int>> v(10,vector<int>(10,1));
//
//  for( const auto& e: v[9]){
//    cout<<e ;
//  }
//
//  deque<int> q;
//  
//  cout<<endl;
//}
//
//int main(){
//  Test();
//  return 0;
//}

#include<iostream>
#include<vector>

using namespace std;
int pos[4][2]={{0,1},{0,-1},{-1,0},{1,0}};

class Solution {
  public:
    int islandPerimeter(vector<vector<int>>& grid) {
      if(grid.empty()){
        return 0;

      }

      int row=grid.size();
      int col= grid[0].size();
      vector<vector<int>> box(row,vector<int>(col,4));

      for(int i=0;i<row;i++){
        if(grid[i][0]==1){
          DFS(grid,row,col,i,0,box);

        }
        if(grid[col-1][i]==1){
          DFS(grid,row,col,col-1,i,box);
        }

      }
      for(int i= 0;i<col;i++ ){
        if(grid[0][i]==1){
          DFS(grid,row,col,0,i,box);

        }
        if(grid[row-1][i]==1){
          DFS(grid,row,col,row-1,i,box);

        }

      }

      int ret=0;
      for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
          cout<<box[i][j]<<endl;
          if(box[i][j]!=4){
            ret+=box[i][j];
          }

        }

      }
      return ret;

    }

    void DFS(vector<vector<int>>& grid,int row,int col,int x,int y,vector<vector<int>>& box){
    
        box[x][y]--;
        grid[x][y]=0;

      for(int i=0;i<4;i++){
        int new_x=x+pos[i][0];
        int new_y=y+pos[i][1];

        if(new_x >= row || new_x< 0
            || new_y >= col || new_y<0){
          continue;
        }

        if( grid[new_x][new_y]==1 &&  box[new_x][new_y]>0){
          box[x][y]--;
          DFS(grid,row,col,new_x,new_y,box);
        }

      }

    }

};

/*
 *[0,1,0,0],
  [1,1,1,0],
   [0,1,0,0],
    [1,1,0,0]]

 * */

int main(){
  vector<vector<int>> map={{0,1,0,0},{1,1,1,0},{0,1,0,0},{1,1,0,0}};
  Solution s;
  int ret=s.islandPerimeter(map);
  cout<<ret<<endl;
  return 0;
}
