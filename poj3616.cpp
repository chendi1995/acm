/*************************************************************************
    > File Name: poj3616.cpp
    > Author: chendi
    > Mail: chendi1995@sohu.com 
    > The compiler environment:vim + gcc
    > Created Time: 2015年04月27日 星期一 13时32分35秒
 ************************************************************************/
#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
#define MAXM 1010
using namespace std;

typedef struct 
{
	int start;
	int end;
	int eff;
}tim;

tim t[MAXM];
int dp[MAXM];

int cmp(tim x,tim y)
{
	return x.end <= y.end;
}

int main()
{
	int N,M,R;
	int i,j;
	int maxx=0;
	scanf("%d%d%d",&N,&M,&R);
	for(i=0;i<M;i++)
	{
		scanf("%d%d%d",&t[i].start,&t[i].end,&t[i].eff);	
	}
	sort(t,t+M,cmp);
	for(i=0;i<M;i++)
	{
		dp[i]=t[i].eff;
		for(j=0;j<i;j++)
		{
			if(t[i].start-t[j].end>=R)
				dp[i]=max(dp[i],dp[j]+t[i].eff);
		}
		maxx=max(maxx,dp[i]);
	}
	printf("%d\n",maxx);
	return 0;
}
