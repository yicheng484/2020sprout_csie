#include<bits/stdc++.h>
using namespace std;
main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int a[7],ans;
	while(1){
		for(int i=1;i<=6;i++)cin>>a[i];
		if(accumulate(a+1,a+7,0)==0)return 0;
		ans=0;
		ans+=a[4]+a[5]+a[6];
		//case 5
		a[1]-=a[5]*11;
		//case 4
		if(a[4]*5>a[2]){
			a[1]-=(a[4]*5-a[2])*4;
			a[2]=0;
		}else{
			a[2]-=a[4]*5;
		}
		//case 3
		ans+= a[3]/4 ;
		a[3]%=4;
		if(a[3]!=0)ans++,a[3]=4-a[3];
		//case 3 special case
		if (a[3]==3){
			if(a[2]<5){
				a[1]-= (5-a[2])*4+7;
				a[2]=0;
			}else{
				a[2]-=5;
				a[1]-=7;
			}
		}else if(a[3]==2){
			if(a[2]<3){
				a[1]-= (3-a[2])*4+6;
				a[2]=0;
			}else{
				a[2]-=3;
				a[1]-=6;
			}
		}else if(a[3]==1){
			if(a[2]>0)a[2]--,a[1]-=5;
			else a[1]-=9;
		}else{
			;
		}
		//case 2;
		if(a[2]>0){
			ans+= a[2]/9;
			a[2]%=9;
			if(a[2]!=0)ans++;
			a[1]-=(9-a[2])*4;
		}
		if(a[1]>0){
			ans+= a[1]/36;
			if(a[1]%36!=0)ans++;
		}
		cout<<ans<<"\n";
	}
}