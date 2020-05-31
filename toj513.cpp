#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define N 200000
int data[N];
main(){
	int ans=0;
	stack<pair<int,int> >s;
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin>>n;
	for(int i=0;i<n;i++)cin>>data[i];
	s.push({data[0],0});
	for(int i=1;i<n;i++){
		int current=i;
		while(!s.empty()&&s.top().first>data[i]){
			ans=max(ans,(i-s.top().second)*s.top().first);
			current=s.top().second;
			s.pop();
		}
		s.push({data[i],current});
	}
	while(!s.empty()){
		ans=max(ans,(n-s.top().second)*s.top().first);
		s.pop();
	}
	cout<<ans<<"\n";
}