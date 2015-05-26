/*************************************************************************
    > File Name: poj1661.cpp
    > Author: chendi
    > Mail: chendi1995@sohu.com 
    > The compiler environment:vim + gcc
    > Created Time: 2015年04月22日 星期三 17时40分39秒
 ************************************************************************/
#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
#define MAXN 1005
#define INF 0x3f3f3f3f
using namespace std;
typedef struct
{
	int x1;
	int x2;
	int h;
}B;
B board[MAXN];
int n,x,y,maxh;
int dp[MAXN][2];

int cmp(B x,B y)
{
	return y.h>x.h;
}

void lefttime(int i)
{
	int h;
	int j=i-1;
	while(j>0 && board[i].h-board[j].h<=maxh)
	{
		h=board[i].h-board[j].h;
		if(board[i].x1>=board[j].x1 &&board[i].x1<=board[j].x2)
		{
			dp[i][0]=min(dp[j][0]+board[i].x1-board[j].x1+h,dp[j][1]+board[j].x2-board[i].x1+h);
			return;
		}
		else
		{
			j--;
		}
	}
	if(board[i].h-board[j].h>maxh)
	{
		dp[i][0]=INF;
	}
	else
	{
		dp[i][0]=board[i].h;
	}
}

void righttime(int i)
{
	int h;
	int j=i-1;
	while(j>0 && board[i].h-board[j].h<=maxh)
	{
		h=board[i].h-board[j].h;
		if(board[i].x2>=board[j].x1 &&board[i].x2<=board[j].x2)																			
		{
			dp[i][1]=min(dp[j][0]+board[i].x2-board[j].x1+h,dp[j][1]+board[j].x2-board[i].x2+h);
			return ;
		}
		else
		{
			j--;
		}
	}
	if(board[i].h-board[j].h>maxh)
	{
		dp[i][1]=INF;
	}
	else
	{
		dp[i][1]=board[i].h;
	}
}


int main()
{
	int T;
	int i,j,k;
	int a,b,c;
	scanf("%d",&T);
	while(T--)
	{
		memset(dp,INF,sizeof(dp));
		scanf("%d%d%d%d",&n,&x,&y,&maxh);
		board[0].h=0;
		board[0].x1=-20000;
		board[0].x2=20000;
		for(i=1;i<=n;i++)
		{
			scanf("%d%d%d",&a,&b,&c);
			board[i].x1=a;
			board[i].x2=b;
			board[i].h=c;
		}
		board[n+1].x1=x;
		board[n+1].x2=x;
		board[n+1].h=y;
		dp[0][1]=dp[0][1]=0;
		sort(board,board+n+1,cmp);
		for(i=1;i<=n+1;i++)
		{
			lefttime(i);
			righttime(i);
		}
		printf("%d\n",min(dp[n+1][0],dp[n+1][1]));
	}
	return 0;
}
