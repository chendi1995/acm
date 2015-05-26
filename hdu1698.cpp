/*************************************************************************
    > File Name: hdu1698.cpp
    > Author: chendi
    > Mail: chendi1995@sohu.com 
    > The compiler environment:vim + gcc
    > Created Time: 2015年05月06日 星期三 17时40分43秒
 ************************************************************************/
#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
#define MAXN 100010
using namespace std;
int add[MAXN<<2];
typedef struct
{
	int v;
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
	{
		node[rt].v=1;
		return;
	}
	mid=(left+right)>>1;
	build(rt<<1,left,mid);
	build(rt<<1|1,mid+1,right);
	node[rt].v=node[rt<<1].v+node[rt<<1|1].v;
}

void pushdown(int rt,int m)
{
	if(add[rt])
	{
		add[rt<<1]=add[rt];
		add[rt<<1|1]=add[rt];
		node[rt<<1].v=add[rt]*(m-(m>>1));
		node[rt<<1|1].v=add[rt]*(m>>1);
		add[rt]=0;
	}
}

void updata(int rt,int left,int right,int value)
{
	int mid;
	if(node[rt].left==left && node[rt].right==right)
	{
		add[rt]=value;
		node[rt].v=(right-left+1)*value;
		return ;
	}
	pushdown(rt,node[rt].right-node[rt].left+1);
	mid=(node[rt].left+node[rt].right)>>1;
	if(right<=mid)
		updata(rt<<1,left,right,value);
	else if(left>mid)
		updata(rt<<1|1,left,right,value);
	else
	{
		updata(rt<<1,left,mid,value);
		updata(rt<<1|1,mid+1,right,value);
	}
	node[rt].v=node[rt<<1].v+node[rt<<1|1].v;	
}


int main()
{
	int T;
	int N;
	int Q;
	int i;
	int m,n,v;
	int kase=1;
	scanf("%d",&T);
	while(T--)
	{
		memset(add,0,sizeof(add));
		scanf("%d",&N);
		build(1,1,N);
		scanf("%d",&Q);
		for(i=1;i<=Q;i++)
		{
			scanf("%d%d%d",&m,&n,&v);
			//cout << m << n << v;
			updata(1,m,n,v);
		}
		printf("Case %d: The total value of the hook is %d.\n",kase++,node[1].v);
	}
	return 0;
}
