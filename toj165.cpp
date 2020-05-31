#include<bits/stdc++.h>
using namespace std;
#define N 100000
int g[N];
main(){
	ios::sync_with_stdio(false);
	//cin.tie(0);
	int t,n,m,a,b;
	cin>>t;
	while(t--){
		cin>>n>>m;
		vector<vector<int>>v(n);
		vector<int>ans;
		priority_queue<int,vector<int>,greater<int> >pq;
		memset(g,0,sizeof(g));
		for(int i=0;i<m;i++){
			cin>>a>>b;
			v[a].push_back(b);
			g[b]++;
		}
		for(int i=0;i<n;i++){
			if(g[i]==0)pq.push(i);
		}
		for(int i=0;i<n;i++){
			sort(v[i].begin(),v[i].end());
		}
		for(int i=0;i<n&&!pq.empty();i++){
			int k=pq.top();
			pq.pop();
			ans.push_back(k);
			for(int j:v[k]){
				g[j]--;	
				if(g[j]==0)pq.push(j);
			}			
		}
		if((int)ans.size()!=n)cout<<"QAQ\n";
		else{			
			int t = ans.size();
			for(int i=0;i<t;i++){
				cout<<ans[i];
				if(i!=t-1)cout<<" ";
				else cout<<"\n";
			}
		} 

		v.clear();
		ans.clear();
		while(!pq.empty())pq.pop();
	}
}