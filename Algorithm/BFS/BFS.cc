#include<iostream>
#include<queue>
#include<vector>

using namespace std;

struct position{
  position(int x,int y)
  :_x(x)
   ,_y(y)
  {

  }
  int _x;
  int _y;
};

int pos[4][2]={{-1,0},{1,0},{0,-1},{0,1}};

bool BFS(vector<vector<int>>& grid,int start_x,int start_y
    ,int end_x,int end_y){

  if(grid.empty()){
    return true;
  }
  //用于保存新的路径
  queue<position> q;
  q.push(position(start_x,start_y));

  int row=grid.size();
  int col=grid[0].size();

  vector<vector<int>> box(row,vector<int>(col,0));

  //标记被访问过的路径
  box[start_x][start_y]=1;

  while(!q.empty()){
    //获取队首元素
    position curPos=q.front();
    q.pop();

    for(int i=0;i<4;i++){
      int new_x=curPos._x+pos[i][0];
      int new_y=curPos._y+pos[i][1];

      if(new_x >= row || new_x <0
          || new_y >= col || new_y <0 )
        continue;

      //新的路径入队
      if(grid[new_x][new_y]==0 &&  box[new_x][new_y]==0){
        box[new_x][new_y]=1;
        q.push(position(new_x,new_y));
      }
      if(new_x==end_x && new_y == end_y)
        return true;
    }
  }
  return false;
}

int main(){
  vector<vector<int>> map{{0,1,0,1},{0,0,0,0},{0,1,0,0},{0,0,1,0}};
  int s_x,s_y;
  cin>>s_x>>s_y;
  int e_x,e_y;
  cin>>e_x>>e_y;

  cout<<BFS(map,s_x,s_y,e_x,e_y)<<endl;
}
