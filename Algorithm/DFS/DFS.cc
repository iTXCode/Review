#include<iostream>
#include<vector>

using namespace std; 

void DFS(int index,int n,vector<int>& book,vector<int>& box){

  //终止条件
  if(index==n+1){
    for(int i=1;i<=n;i++){
      cout<<box[i]<<" ";
    }

    cout<<endl;
    return;
  }

  for(int i=1;i<=n;i++){
    if(book[i] == 0){
      box[index]=i;
      book[i]=1;
      DFS(index+1,n,book,box);
      book[i]=0;
    }
  }
}

int main(){
  int n;
  cin>>n;
  vector<int> book(n+1,0);
  vector<int> box(n+1,0);
  DFS(1,n,book,box);
  return 0;
}


