#include<bits/stdc++.h>
using namespace std;
#define N 100000
int a[N];
void solve(int n){
	if(n==1){
		a[0]=1;
		return;
	}
	if(n==2){
		a[0]=1,a[1]=2;
		return;
	}
	if(n==3){
		a[0]=3,a[1]=1,a[2]=2;
		return;
	}
	if(n==4){
		a[0]=1,a[1]=3,a[2]=2,a[3]=4;
		return;
	}
	if(n%2){//odd
		solve(n/2 + 1);
		for(int i=0;i<n/2 + 1;i++)a[i]=2*a[i]-1;
		int t=n/2 + 1;
		for(int i=0;i<n/2 + 1;i++){
			if(a[i]+1>n)continue;
			a[t++]=a[i]+1;
		}		
	}else{//even
		solve(n/2);
		for(int i=0;i<n/2;i++)a[i+n/2]=2*a[i],a[i]=2*a[i]-1;
	}
} 
main(){
	int n;
	memset(a,0,sizeof(a));
	cin>>n;
	solve(n);
	for(int i=0;i<n;i++)cout<<a[i]<<" \n"[i==n-1];		
}