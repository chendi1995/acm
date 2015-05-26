/*************************************************************************
    > File Name: poj2533.cpp
    > Author: chendi
    > Mail: chendi1995@sohu.com 
    > The compiler environment:vim + gcc
    > Created Time: 2015年04月23日 星期四 20时42分24秒
 ************************************************************************/
#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
#define MAXN 1010
using namespace std;
int dp[MAXN];

int main()
{
	int i,j;
	int n;
	int maxx;
	int a[MAXN];
	while(~scanf("%d",&n))
	{
		memset(dp,0,sizeof(dp));
		for(i=0;i<n;i++)
			scanf("%d",&a[i]);
		maxx=0;
		for(i=0;i<n;i++)
		{
			dp[i]=1;
			for(j=0;j<i;j++)
			{
				if(a[i]>a[j])
					dp[i]=max(dp[j]+1,dp[i]);
			}
			maxx=max(maxx,dp[i]);
		}
		printf("%d\n",maxx);
	}
	return 0;
}
