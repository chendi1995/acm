/*************************************************************************
    > File Name: hdu1024.cpp
    > Author: chendi
    > Mail: chendi1995@sohu.com 
    > The compiler environment:vim + gcc
    > Created Time: 2015年04月10日 星期五 21时00分57秒
 ************************************************************************/
#include<iostream>
#include<stdio.h>
#include<string.h>
#define MAX 0x3f3f3f3f

int dp[2][1000010];
int a[1000010];
using namespace std;

int max(int a,int b)
{
	return a>b?a:b;
}
int main()
{
	int i,j,m,n;
	int now,pre;
	int maxn;
	while(~scanf("%d%d",&m,&n))
	{
		for(i=1;i<=n;i++)
			scanf("%d",&a[i]);
		memset(dp,0,sizeof(dp));
		now=1,pre=0;
		for(i=1;i<=m;i++)
		{
			maxn=-MAX;
			for(j=i;j<=n;j++)
			{
				dp[now][j]=max(dp[now][j-1]+a[j],dp[pre][j-1]+a[j]);
				dp[pre][j-1]=maxn;
				maxn=max(dp[now][j],maxn);
			}
		}
		printf("%d\n",maxn);
	}
	return 0;
}

