//Really cool question, try to implement multiplication in its most trivial manner, much like you do on pen and paper. Store the result in an array

#include<iostream>
using namespace std;
main(){
	int t,n,dig[201],i,temp,carry,index=0;
	cin>>t;
	while(t--){
		temp=index=0;
		for(i=0;i<201;i++)
		dig[i]=0;
		cin>>n;
		dig[0]=1;
		for(n;n>1;n--){
			for(i=0;i<=index;i++)
			{
				temp=dig[i]*n+temp;
				dig[i]=temp%10;
				temp/=10; 
			}
			while(temp>0)
			{
				dig[++index]=temp%10;
				temp/=10;
			}
		}
		for(i=index;i>=0;i--)
		cout<<dig[i];
		cout<<endl;
	}
}
