#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define pii pair<int,int>
#define X first
#define Y second
pii operator+(const pii&p1, const pii&p2){
	return {p1.X+p2.X,p1.Y+p2.Y};
}
pii operator-(const pii&p1, const pii&p2){
	return {p1.X-p2.X,p1.Y-p2.Y};
}
int operator*(const pii&p1, const pii&p2){
	return p1.X * p2.X + p1.Y * p2.Y;
}
int operator^(const pii&p1, const pii&p2){
	return p1.X * p2.Y - p1.Y * p2.X;
}

main(){
	ios::sync_with_stdio(false);
	//cin.tie(0);
	pii a[2],tmp[2];
	int t,L=0,R=0,B=0;//left / right / back
	cin>>t;
	cin>>a[0].X>>a[0].Y;
	if(t==1)goto output;
	cin>>a[1].X>>a[1].Y;
	tmp[1] = a[1]-a[0] ;
	for(int i=2;i<t;i++){
		cin>>a[i&1].X>>a[i&1].Y;
		tmp[i&1] = a[i&1] - a[!(i&1)];
		if((tmp[i&1]^tmp[!(i&1)])==0 && (tmp[i&1]*tmp[!(i&1)])<0) B++ ;
		else if ((tmp[i&1]^tmp[!(i&1)])==0 && (tmp[i&1]*tmp[!(i&1)])>0);
		else if((tmp[!(i&1)]^tmp[i&1])>0)L++;
		else R++; 
	}
	output:
		cout<<L<<" "<<R<<" "<<B<<"\n";
}