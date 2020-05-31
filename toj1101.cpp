#include<bits/stdc++.h>
using namespace std;
#define N 100000
bool flag;
int color[N];
vector<int>v[N];
void bfs(int f){
	queue<int>q;
	color[0]=0;
	q.push(f);
	int x;
	while(!q.empty()){
		x=q.front(),q.pop();
		for(int k:v[x]){
			if(color[k]==-1){
				if(color[x]==0)color[k]=1;
				else color[k]=0;
				q.push(k);
			}else{
				if(color[k]==color[x]){
					flag=false;
					return;
				}
			}
		}
	}

}
main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n,m,a,b;
	while(cin>>n&&n){
		flag=true;
		memset(color,-1,sizeof(color));
		cin>>m;
		while(m--){
			cin>>a>>b;			
			v[a].push_back(b);
			v[b].push_back(a);
		}
		bfs(0);
		if(flag)cout<<"NORMAL.\n";
		else cout<<"RAINBOW.\n";
		for(int i=0;i<n;i++)v[i].clear();
	}
}