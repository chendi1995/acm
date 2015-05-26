/*************************************************************************
    > File Name: hdu1754.cpp
    > Author: chendi
    > Mail: chendi1995@sohu.com 
    > The compiler environment:vim + gcc
    > Created Time: 2015年05月03日 星期日 19时15分19秒
 ************************************************************************/
#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
#define MAXN 200010
typedef long long ll;
using namespace std;
typedef struct
{
	ll v;
	ll left;
	ll right;
}Node;
Node node[4*MAXN];
ll a[MAXN];

void build(ll i,ll left,ll right)
{
	ll mid;
	node[i].left=left;
	node[i].right=right;
	if(node[i].left==node[i].right)
	{
		node[i].v=a[left];
		return ;
	}
	mid=(left+right)/2;
	build(i*2,left,mid);
	build(i*2+1,mid+1,right);
	node[i].v=max(node[i*2].v,node[i*2+1].v);
}

ll Query(ll i,ll left,ll right)
{
	ll mid;
	ll a,b;
	if(node[i].left==left&&node[i].right==right)
		return node[i].v;
	mid=(node[i].left+node[i].right)/2;
	if(right<=mid)
		return Query(i*2,left,right);
	else if(left>mid)
		return Query(i*2+1,left,right);
	else 
	{
		a=Query(i*2,left,mid);
		b=Query(i*2+1,mid+1,right);
		return max(a,b);
	}
}

void updata(ll k,ll d,ll n)
{
	int mid;
	if(node[k].left==node[k].right && node[k].left==d)
	{
		node[k].v=n;
		return ;
	}
	mid=(node[k].left+node[k].right)/2;
	if(d<=mid)
		updata(2*k,d,n);
	else
		updata(2*k+1,d,n);
	node[k].v=max(node[2*k].v,node[2*k+1].v);
}

int main()
{
	ll N,M;
	ll i;
	char ch;
	ll m,n;
	while(scanf("%lld%lld",&N,&M)!=EOF)
	{
		for(i=1;i<=N;i++)
		{
			scanf("%lld",&a[i]);
		}
		build(1,1,N);
		for(i=1;i<=M;i++)
		{
			scanf("%c",&ch);
			scanf("%lld%lld",&m,&n);
			if(ch=='Q')
			{
				printf("%lld\n",Query(1,m,n));
			}
			if(ch=='U')
			{
				updata(1,m,n);
			}
		}
	}
	return 0;
}
