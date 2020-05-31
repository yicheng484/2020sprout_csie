#include<bits/stdc++.h>
using namespace std;
#define N 1005
char maze[N][N];
int visited[N][N];
void dfs(int x,int y,int h,int w){
	const int dx[4]={0,-1,1,0},dy[4]={-1,0,0,1};
	visited[x][y]=1;
	for(int i=0;i<4;i++){
		if(x+dx[i]<h&&x+dx[i]>=0&&y+dy[i]>=0&&y+dy[i]<w&&visited[x+dx[i]][y+dy[i]]==0&&maze[x+dx[i]][y+dy[i]]=='.'){
			dfs(x+dx[i],y+dy[i],h,w);
		}
	}
}
main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t,h,w,cnt;
	cin>>t;
	while(t--){
		cin>>h>>w;
		memset(visited,0,sizeof(visited));
		for(int i=0;i<h;i++){
			for(int j=0;j<w;j++){
				cin>>maze[i][j];
			}
		}
		cnt=0;
		for(int i=0;i<h;i++){
			for(int j=0;j<w;j++){
				if(maze[i][j]=='.'&&visited[i][j]==0){
					dfs(i,j,h,w);
					cnt++;
				}
			}
		}
		cout<<cnt<<"\n";
	}
}