#include<bits/stdc++.h>
using namespace std;
#define int long long
#define N 500
int a[N+10];
main(){
	int n,tmp,cnt=0;
	cin>>n;
	string s;
	for(int i=0;i<n;i++){
		cin>>s;
		tmp=0;
		for(int j=0;j<9;j++){
			tmp+=(s[10-j]-'0')*pow(10,j);
		}
		a[i]=tmp;
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			for(int k=0;k<n;k++){
				if(a[i]+a[j]==a[k])cnt++;
			}
		}
	}
	cout<<cnt<<"\n";
}