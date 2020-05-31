#include<bits/stdc++.h>
using namespace std;
#define N 2005
int p[N],m[N],root;
void sol(int l,int r){
	int i;
	if(l>r)return;
	for(i = l;i<=r;i++)if(m[i]==p[root])break;
	root++;
	sol(l,i-1);
	sol(i+1,r);
	cout<<m[i]<<"\n";
}
main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int input,i=0;
	while(cin>>input){
		p[i]=input;
		m[i]=input;
		i++;
	}
	sort(m,m+i);
	sol(0,i-1);
}