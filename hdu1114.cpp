/*************************************************************************
    > File Name: hdu1114.cpp
    > Author: chendi
    > Mail: chendi1995@sohu.com 
    > The compiler environment:vim + gcc
    > Created Time: 2015年04月15日 星期三 16时51分36秒
 ************************************************************************/
#include<iostream>
#include<string.h>
#include<stdio.h>
#define INF 0x3f3f3f3f
using namespace std;

int v[5050],w[5050];

int dp[501000];

int Min(int x,int y)
{
	return x<y?x:y;
}

int main()
{
	int T;
	int E,F;
	int i,j,n;
	cin >> T;
	int weight;
	while(T--)
	{
		memset(dp,INF,sizeof(dp));
		cin >> E >> F;
		weight=F-E;
		cin >> n;
		for(i=0;i<n;i++)
			cin >> v[i] >> w[i];
		dp[0]=0;
		for(i=0;i<n;i++)
			for(j=w[i];j<=weight;j++)
				dp[j]=Min(dp[j],dp[j-w[i]]+v[i]);
		if(dp[weight]<INF)
			printf("The minimum amount of money in the piggy-bank is %d.\n",dp[weight]);
		else
			printf("This is impossible.\n");
	}
	return 0;
}

