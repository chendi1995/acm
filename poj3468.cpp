/*************************************************************************
    > File Name: poj3468.cpp
    > Author: chendi
    > Mail: chendi1995@sohu.com 
    > The compiler environment:vim + gcc
    > Created Time: 2015年05月04日 星期一 18时27分15秒
 ************************************************************************/
#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
#define MAXN 100010
using namespace std;
typedef long long ll;
ll a[MAXN];
ll  add[MAXN<<2];
typedef struct
{
	ll v;
	int  left;
	int  right;
}NODE;
NODE node[MAXN<<2];

void build(int  i,int  left,int right)
{
	int mid;
	node[i].left=left;
	node[i].right=right;
	if(left==right)
	{
		node[i].v=a[left];
		return ;
	}
	mid=(left+right)>>1;
	build(i<<1,left,mid);
	build(i<<1|1,mid+1,right);
	node[i].v=node[i<<1].v+node[i<<1|1].v;
}
void pushdown(int rt,int m)
{
	if(add[rt])
	{
		add[rt<<1]+=add[rt];
		add[rt<<1|1]+=add[rt];
		node[rt<<1].v+=add[rt]*(m-(m>>1));
		node[rt<<1|1].v+=add[rt]*(m>>1);
		add[rt]=0;
	}
}

ll Query(int i,int left,int right)
{
	ll mid;
	if(node[i].left==left && node[i].right==right)
	{
		return node[i].v;
	}
	pushdown(i,node[i].right-node[i].left+1);
	mid=(node[i].left+node[i].right)/2;
	if(right<=mid)
		return Query(i<<1,left,right);
	else if(left>mid)
		return Query(i<<1|1,left,right);
	else
		return Query(i<<1,left,mid)+Query(i<<1|1,mid+1,right);
}


void updata(int rt,int left,int right,int value)
{
	int mid;
	if(node[rt].left==left && node[rt].right==right)
	{
		add[rt]+=value;
		node[rt].v+=(right-left+1)*value;
		return ;
	}
	if(node[rt].left==node[rt].right)
		return ;
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
	int  M,N;
	int i,j;
	char ch[2];
	int m,n,l;
	scanf("%d%d",&M,&N);
	for(i=1;i<=M;i++)
		scanf("%lld",&a[i]);
	build(1,1,M);
	for(i=1;i<=N;i++)
	{
		scanf("%s",ch);
		if(ch[0]=='Q')
		{
			scanf("%d%d",&m,&n);
			printf("%lld\n",Query(1,m,n));
		}
		else if(ch[0]=='C')
		{
			scanf("%d%d%d",&m,&n,&l);
			updata(1,m,n,l);
		}
	}
	return 0;
}
