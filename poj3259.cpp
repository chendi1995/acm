/*************************************************************************
    > File Name: poj3259.cpp
    > Author: chendi
    > Mail: chendi1995@sohu.com 
    > The compiler environment:vim + gcc
    > Created Time: 2015年03月29日 星期日 21时49分41秒
 ************************************************************************/
#include<iostream>
#include<stdlib.h>
#include<string.h>
#define INF 100000
using namespace std;

int N,M,W;
int all;
typedef struct 
{
	int a;
	int b;
	int time;
}weight;

int dist[1000];
weight edge[10000];

int bellmanford(void)
{
	int i,j;
	memset(dist,INF,sizeof(dist));
	for(i=1;i<=N-1;i++)
		for(j=1;j<=all;j++)
			if(dist[edge[j].b]>(dist[edge[j].a]+edge[j].time))
				dist[edge[j].b]=dist[edge[j].a]+edge[j].time;
	for(j=1;j<=all;j++)
		if(dist[edge[j].b]>(dist[edge[j].a]+edge[j].time))
			return -1;
	return 0;
		
}

int main()
{
	int i,j,k;
	int F;
	int a,b,c;
	int result;
	cin >> F;
	for(k=1;k<=F;k++)
	{
		cin >> N >> M >> W;
		all=0;
		for(i=1;i<=M;i++)
		{
			all++;
			cin >> a >> b >> c;
			edge[all].a=a;
			edge[all].b=b;
			edge[all].time=c;
			all++;
			edge[all].b=a;
			edge[all].a=b;
			edge[all].time=c;
		}
		for(i=M+1;i<=W+M;i++)
		{
			all++;
			cin >> a >> b >> c;
			edge[all].a=a;
			edge[all].b=b;
			edge[all].time=-c;
		}
		result=bellmanford();
		if(result==-1)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
}
