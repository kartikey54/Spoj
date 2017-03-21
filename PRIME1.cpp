//I present two solutions here, the first one being a little more simple to understand as well as implement than the second one.

// 1st  

#include<iostream>
#include<stdio.h>
#include<math.h>
using namespace std;
main(){
	int t;
	cin>>t;
	while(t--){
		long long int j,i,a,b,c,coun=0;
		cin>>a>>b;
		c= sqrt(b);
		bool arr1[c+1];//arr2[c+1];
		for(i=0;i<=c;i++)
		arr1[i]=1;
		arr1[0]=arr1[1]=0;
		for(i=2;i<=c;i++)
		{
			if(arr1[i]==1)
			for(j=2;i*j<=c;j++)
			{
				arr1[i*j]=0;
			}
		}
		long long int temp;
		for(i=a;i<=c;i++)
		if(arr1[i]==1)
		printf("%lld\n", i);
		temp=i;
		bool flag=0;
		for(i=temp;i<=b;i++)
		{
			flag=0;
			for(j=2;j<=c;j++)
			{
				if(arr1[j]==1)
				if(i%j==0)
				{flag=1;
				break;}
			}
			if(flag==0){
			//	coun++;
			//cout<<i<<endl;
			printf("%lld\n", i);}
		}
		//cout<<endl<<coun<<endl;
	}
}

// 2nd

#include<bits/stdc++.h>
using namespace std;
vector <int> primes;
#define uplim 100005
bool base[uplim];
void sieve()
{
	int i,j,k;
	for(i = 2; i < uplim ; i ++)
		for(j = 2; i*j < uplim ;j ++)
			base[i*j] = 1;
	primes.push_back(2);
	for(i = 3; i<uplim;i++)
		if(base[i] == 0)
			primes.push_back(i);
}
main(){
	sieve();
	int test,start,k,end,flag,prsz = (int)primes.size(),i,j;
	cin>>test;
	while(test--)
	{
		cin>>start>>end;
		for(i = start; i<= end;i++)
		{
			flag = 0;
			for(j = 0 ; primes[j] * primes[j] <= i ; j++)
				if(i % primes[j] == 0)
				{
					flag = 1;
					break;
				}
			if(flag == 0 && i != 1)
				cout<<i<<endl;
		}
		cout<<endl;
	}
}
