/*************************************************************************
    > File Name: hdu1166.cpp
    > Author: chendi
    > Mail: chendi1995@sohu.com 
    > The compiler environment:vim + gcc
    > Created Time: 2015年05月02日 星期六 21时22分09秒
 ************************************************************************/
#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
#define MAXN 50010
using namespace std;
int a[MAXN];
char str[10];
int father[MAXN];
int ans;

typedef struct
{
	int v;
	int left;
	int right;
}NODE;

NODE node[4*MAXN];
void build(int i,int l,int r)
{
	node[i].left=l;
	node[i].right=r;
	if(l==r)
	{
		node[i].v=a[l];
		father[l]=i;
		return ;
	}
	build(i*2,l,(l+r)/2);
	build(i*2+1,(l+r)/2+1,r);
	node[i].v=node[i*2].v+node[i*2+1].v;
}

void updata(int u, int j)
{
	node[u].v=node[u].v+j;
	if(u==1)
		return ;
	updata(u/2,j);
}

int  Query(int i,int l,int r)
{
	int mid;
	if(node[i].left==l && node[i].right==r)
	{
		return node[i].v;
	}
	mid=(node[i].left+node[i].right)/2;
	if(r<=mid)
		return Query(2*i,l,r);
	else if(l>mid)
		return Query(2*i+1,l,r);
	else return Query(2*i,l,mid)+Query(2*i+1,mid+1,r);
	
}

int main()
{
	int T;
	int n;
	int i,j;
	int kase=1;
	scanf("%d",&T);
	while(T--)
	{
		memset(father,0,sizeof(father));
		printf("Case %d:\n",kase++);
		scanf("%d",&n);
		for(i=1;i<=n;i++)
			scanf("%d",&a[i]);
		build(1,1,n);
		while(scanf("%s",str) && str[0]!='E')
		{
			scanf("%d%d",&i,&j);
			if(str[0]=='Q')
			{
				printf("%d\n",Query(1,i,j));
			}
			if(str[0]=='A')
			{
				updata(father[i],j);
			}
			if(str[0]=='S')
			{
				updata(father[i],-j);
			}
		}
	}
	return 0;
}
