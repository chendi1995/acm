/*************************************************************************
    > File Name: poj3666.cpp
    > Author: chendi
    > Mail: chendi1995@sohu.com 
    > The compiler environment:vim + gcc
    > Created Time: 2015年04月27日 星期一 14时39分32秒
 ************************************************************************/
#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
#define MAXN 2010;
using namespace std;
int a[MAXN];
int b[MAXN];
int dp[MAXN][MAXN];

int main()
{
	int N;
	int i,j;
	while(~scanf("%d",&N))
	{
		for(i=0;i<N;i++)
		{
			scanf("%d",&a[i]);
			b[i]=a[i];
		}
		sort(b,b+n);
		for(i=0;i<N;i++)
			for(j=0;j<i;j++)
				dp[i][j]=
	}
}
