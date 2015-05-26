/*************************************************************************
    > File Name: poj1417.cpp
    > Author: chendi
    > Mail: chendi1995@sohu.com 
    > The compiler environment:vim + gcc
    > Created Time: 2015年04月07日 星期二 17时17分25秒
 ************************************************************************/
#include<iostream>
#include<stdio.h>
#include<string.h>
#define MAX 3000
using namespace std;
int father[MAX];
int dp[MAX][MAX];
int visited[MAX]=0;
typedef struct
{
	int a;
	int b;
}type;

type vector[MAX];

int find(int x)
{
	if(x==father[x])
		return x;
	int t;
	father[x]=find(father[x]);
	return father[x];
}

int main()
{
	int n,p1,p2,root;
	int i;
	int xi,yi;
	int r1,r2;
	int p;
	int k,cnt;
	int qp=0;
	char ai[5];
	while(scanf("%d%d%d",&n,&p1,&p2)&&(n+p1+p2))
	{
		cnt=0;
		p=p1+p2;
		for(i=1;i<=p;i++)
		{
			father[i]=i;
			rank[i]=0;
		}
		for(i=1;i<=n;i++)
		{
			scanf("%d%d",&xi,&yi);
			scanf("%s",ai);
			r1=find(xi);
			r2=find(yi);
			k=(ai[0]=='n');
			if(k==1)
			{
				father[r1]=r2+p;
				father[r1+p]=r2;
			}
			else
			{
				father[r1]=r2;
				father[r1+p]=r2+p;
			}	
		}
		for(i=1;i<=p;i++)
		{
			root=find(i);
			if(!visited[root])
				cnt++;
		
			
		}
	}
}

