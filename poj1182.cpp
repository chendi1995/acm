/*************************************************************************
    > File Name: poj1182.cpp
    > Author: chendi
    > Mail: chendi1995@sohu.com 
    > The compiler environment:vim + gcc
    > Created Time: 2015年04月06日 星期一 16时09分55秒
 ************************************************************************/
#include<iostream>
#include<stdio.h>
using namespace std;
int father[50010],rank[50010];

int find(int x)
{
	if(father[x]==x)
		return x;
	int tmp;
	tmp=father[x];
	father[x]=find(father[x]);
	rank[x]=(rank[x]+rank[tmp])%3;
	return father[x];

}
void Union(int r1,int r2,int d,int x,int y)
{
	father[r1]=r2;
	rank[r1]=(rank[y]-rank[x]+3+d)%3;
}

int main()
{
	int N,K;
	int i;
	int d,x,y;
	int sum=0;
	int r1,r2;
	scanf("%d%d",&N,&K);
	for(i=1;i<=N;i++)
	{
		father[i]=i;
		rank[i]=0;
	}
	for(i=1;i<=K;i++)
	{
		scanf("%d%d%d",&d,&x,&y);
		cout << i <<endl;
		if(x>N ||y>N ||(d==2 && x==y))
		{
			sum++;
		}
		else
		{
			r1=find(x);
			r2=find(y);
			if(r1==r2)
			{
				/*
				if(d==1 && rank[x]!=rank[y])
				{
					sum++;
				}
				else if(d==2&&rank[x]==rank[y]) 
				{
					sum++;
				}
				else if(d==2 && (rank[x]==((rank[y]+1)%3)))
				{
					sum++;
				}
				*/
				if((rank[x]-rank[y]+3)%3!=d-1)
				{
					sum++;
				}
			}
			else
			{
				Union(r1,r2,d-1,x,y);
			}

		}
	}
	printf("%d\n",sum);
	return 0;
}
