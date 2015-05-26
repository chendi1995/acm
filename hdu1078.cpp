/*************************************************************************
    > File Name: hdu1078.cpp
    > Author: chendi
    > Mail: chendi1995@sohu.com 
    > The compiler environment:vim + gcc
    > Created Time: 2015年04月25日 星期六 15时22分44秒
 ************************************************************************/
#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
#define MAXN 105
using namespace std;
int a[MAXN][MAXN];
int dp[MAXN][MAXN];
int to[4][2]={1,0,-1,0,0,1,0,-1};
int n,k;

int check(int x,int y)
{
	if(x>=0 && x<n && y>=0 && y<n)
		return 1;
	else
		return 0;
}

int dfs(int x,int y)
{
	int i,j;
	int xx,yy;
	int maxx=0;
	if(dp[x][y]==0)
	{	
		for(i=1;i<=k;i++)
			for(j=0;j<4;j++)
			{
				xx=x+to[j][0]*i;
				yy=y+to[j][1]*i;
				if(check(xx,yy) && a[xx][yy]>a[x][y])
				{
					maxx=max(maxx,dfs(xx,yy));
				}
			}
		dp[x][y]=maxx+a[x][y];
	}
	return dp[x][y];
}

int main()
{
	int i,j;
	while(scanf("%d%d",&n,&k) && !(n==-1&&k==-1))
	{
		memset(dp,0,sizeof(dp));
		for(i=0;i<n;i++)
			for(j=0;j<n;j++)
			{
				scanf("%d",&a[i][j]);
			}
		printf("%d\n",dfs(0,0));
	}
	return 0;
}
