/*************************************************************************
    > File Name: hdu3038.cpp
    > Author: chendi
    > Mail: chendi1995@sohu.com 
    > The compiler environment:vim + gcc
    > Created Time: 2015年04月03日 星期五 19时11分43秒
 ************************************************************************/
#include<iostream>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
using namespace std;
#define MAXINT 200010

int pre[MAXINT];
int value[MAXINT];

int find(int x)
{
	if(pre[x]==x)
		return x;
	int tmp;
	tmp=pre[x];
	pre[x]=find(pre[x]);
	value[x]+=value[tmp];
	return pre[x];

}

int main()
{
	int i,n,m;
	int u,v,w;
	int r1,r2;
	int res;
	while(~scanf("%d%d",&n,&m))
	{
		res=0;
		memset(value,0,sizeof(value));
		for(i=0;i<=n;i++)
			pre[i]=i;
		for(i=1;i<=m;i++)
		{
			cin >> u >> v >>w;
			u=u-1;
			r1=find(u);
			r2=find(v);
			if(r1!=r2)
			{
				pre[r1]=r2;
				value[r1]=value[v]-value[u]+w;
			}
			if(r1==r2)
				if(value[u]!=w+value[v])
					res++;
		}
		printf("%d\n",res);
	}
	return 0;
}

