/*************************************************************************
    > File Name: poj2253.cpp
    > Author: chendi
    > Mail: chendi1995@sohu.com 
    > The compiler environment:vim + gcc
    > Created Time: 2015年03月24日 星期二 21时03分08秒
 ************************************************************************/
#include<iostream>
#include<math.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define INF 1000000
using namespace std;
double x[1010],y[1010];
double map[1010][1010];
double dist[1010];
int visited[1010];
int n;

double max(double a,double b)
{
	if(a>=b)
		return a;
	else 
		return b;
}

void Dijkstra(int start,int end)
{
	int mindist,i,j,k;
	for(i=1;i<=n;i++)
		dist[i]=map[start][i];
	visited[start]=1;
	dist[start]=0;
	for(i=1;i<=n;i++)
	{
		mindist=INF;
		k=start;
		for(j=1;j<=n;j++)
			if(!visited[j] && dist[j]<mindist)
			{
				k=j;
				mindist=dist[j];
			}
		visited[k]=1;
		for(j=1;j<=n;j++)
			if(!visited[j] && dist[j]>max(dist[k],map[k][j]))
				dist[j]=max(dist[k],map[k][j]);
	}
	printf("Frog Distance = ");
	printf("%.3f\n",dist[end]);
	printf("\n");
}

int main()
{
	int i,j;
	int k=1;
	while(cin >> n && n)
	{
		memset(visited,0,sizeof(visited));
		memset(dist,0,sizeof(dist));
		memset(map,0,sizeof(map));
		for(i=1;i<=n;i++)
			cin >> x[i] >> y[i];
		for(i=1;i<=n;i++)
			for(j=1;j<=n;j++)
				map[i][j]=sqrt((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]));
		printf("Scenario #%d\n",k);
		Dijkstra(1,2);
		k++;
	}
	return 0;
}
