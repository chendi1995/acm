/*************************************************************************
    > File Name: hdu1257.cpp
    > Author: chendi
    > Mail: chendi1995@sohu.com 
    > The compiler environment:vim + gcc
    > Created Time: 2015年04月17日 星期五 12时22分38秒
 ************************************************************************/
#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
#define MAXN 30010
#define INF 0x3f3f3f3f
using namespace std;
int dp[MAXN];
int h[MAXN];
int main()
{
	int n;
	int i,j;
	int maxx;
	while(~scanf("%d",&n))
	{
		maxx=0;
		memset(dp,0,sizeof(dp));
		for(i=0;i<n;i++)
		{
			scanf("%d",&h[i]);
		}
		for(i=1;i<n;i++)
		{
			for(j=0;j<i;j++)
			{
				if(h[i]>h[j])
					dp[i]=max(dp[i],dp[j]+1);
			}
			maxx=max(maxx,dp[i]);
		}
		printf("%d\n",maxx+1);
	}
}
