/*************************************************************************
    > File Name: zoj1610.cpp
    > Author: chendi
    > Mail: chendi1995@sohu.com 
    > The compiler environment:vim + gcc
    > Created Time: 2015年05月07日 星期四 18时57分11秒
 ************************************************************************/
#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
#define MAXN 8005
using namespace std;
int add[MAXN<<2];
int color[MAXN<<2];
int cnt[MAXN];
int ans[MAXN];
typedef struct
{
	int left;
	int right;
}NODE;
NODE node[MAXN<<2];

void build(int rt,int left,int right)
{
	int mid;
	node[rt].left=left;
	node[rt].right=right;
	if(left==right)
		return;
	mid=(left+right)>>1;
	build(rt<<1,left,mid);
	build(rt<<1|1,mid+1,right);
}

void pushdown(int rt)
{
	if(add[rt]!=-1)
	{
		color[rt<<1]=add[rt];
		color[rt<<1|1]=add[rt];
		add[rt]=-1;
	}
}

void update(int rt,int left,int right,int col)
{
	if(node[rt].left==left && node[rt].right==right)
	{
		color[rt]=col;
		add[rt]=col;
		return ;
	}
	pushdown(rt);
	int mid;
	mid=(node[rt].left+node[rt].right)>>1;
	if(right < mid)
		update(rt<<1,left,right,col);
	else if(left >=mid)
		update(rt<<1|1,left,right,col);
	else
	{
		update(rt<<1,left,mid,col);
		update(rt<<1|1,mid+1,right,col);
	}
}

void query(int rt,int left,int right)
{
	if(node[rt].left==node[rt].right)
	{
		ans[left]=color[rt];
		return ;
	}

	int mid;
	mid=(node[rt].left+node[rt].right)>>1;
	pushdown(rt);
	query(rt<<1,left,mid);
	query(rt<<1|1,mid+1,right);
}

int main()
{
	int n;
	int i;
	int x1,x2,c;
	while(scanf("%d",&n)!=EOF)
	{
		memset(add,0,sizeof(add));
		memset(color,-1,sizeof(color));
		memset(cnt,0,sizeof(cnt));
		build(1,1,MAXN);
		for(i=1;i<=n;i++)
		{
			scanf("%d%d%d",&x1,&x2,&c);
			update(1,x1+1,x2,c);
		}
		query(1,1,MAXN);
		for(i=1;i<=MAXN;i++)
			if(color[i]>=0 && color[i]!=color[i-1])
				cnt[color[i]]++;
		for(i=0;i<=MAXN;i++)
			if(cnt[i]>0)
			{
				printf("%d%d\n",i,cnt[i]);
			}
	}
	return 0;
}
