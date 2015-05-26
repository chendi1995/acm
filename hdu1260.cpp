/*************************************************************************
    > File Name: hdu1260.cpp
    > Author: chendi
    > Mail: chendi1995@sohu.com 
    > The compiler environment:vim + gcc
    > Created Time: 2015年04月16日 星期四 16时10分47秒
 ************************************************************************/
#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
#define INF 0x3f3f3f3f
#define MAXK 2010
using namespace std;

int dp[MAXK];
int ts[MAXK];
int td[MAXK][MAXK];

int main()
{
	int T;
	int k;
	int i,j;
	int flag,hour,minute,sec;
	cin >> T;
	while(T--)
	{
		memset(dp,INF,sizeof(dp));
		cin >> k;
		for(i=0;i<k;i++)
			cin >> ts[i];
		for(i=0;i<k-1;i++)
			cin >> td[i][i+1];
		dp[0]=ts[0];
		for(i=1;i<k;i++)
		{
			if(i==1)
				dp[i]=min(dp[i-1]+ts[i],td[i-1][i]);
			else
				dp[i]=min(dp[i-1]+ts[i],dp[i-2]+td[i-1][i]);
		}
		flag=0;
		if(dp[k-1]>=14400)
		{
			flag=1;
			dp[k-1]=dp[k-1]-14400;
		}
		sec=dp[k-1]%60;
		minute=dp[k-1]/60%60;
		hour=dp[k-1]/3600;
		if(flag==1)
			printf("%02d:%02d:%02d pm\n",hour,minute,sec);
		else if(flag==0)
			printf("%02d:%02d:%02d am\n",hour+8,minute,sec);
	}
	return 0;
}
