#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define N 1000005
#define MOD 10000019
int a[N],tmp[N];
int sol(int L,int R){
	if(L==R)return 0;
	int M = (R-L)/2+L;
	int ans = sol(L,M)%MOD + sol(M+1,R)%MOD;
	ans%=MOD;
	int add = 0 ;
	for(int i=L,j=M+1;i<=M;i++){
		while(j<=R&&a[j]<a[i])add+=a[j]%MOD,j++;
		ans+=( (j-M-1)*a[i]%MOD + add%MOD )%MOD;
	}
	int len=L,pos1=L,pos2=M+1;
	while(pos1<=M || pos2<=R){
		if(pos2>R||(pos1<=M&&a[pos1]<a[pos2]))
			tmp[len++] = a[pos1++];
		else 
			tmp[len++] = a[pos2++];
	}
	for(int i=L;i<=R;i++){
		a[i]=tmp[i];
	}
	return ans%MOD;
}
main(){
	int n;
	cin>>n;
	ios::sync_with_stdio(false);
	//cin.tie(0);
	for(int i=0;i<n;i++)cin>>a[i];
	cout<<sol(0,n-1)<<"\n";
}