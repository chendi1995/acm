/*************************************************************************
    > File Name: poj1797.cpp
    > Author: chendi
    > Mail: chendi1995@sohu.com 
    > The compiler environment:vim + gcc
    > Created Time: 2015年03月25日 星期三 17时52分23秒
 ************************************************************************/
#include<iostream>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAXVEX 1010
#define INF 10000000
using namespace std;
int map[MAXVEX][MAXVEX];
int visited[MAXVEX];
int dist[MAXVEX];

int vex,street;
int min(int a,int b)
{
	if(a>=b)
		return b;
	else
		return a;
}

int max(int a,int b)
{
	if(a>=b)
		return a;
	else 
		return b;
}

void dijstra(int start,int end)
{
	int i,j,k,mindist;
	for(i=1;i<=vex;i++)
		dist[i]=map[start][i];
	visited[start]=1;
	dist[start]=INF;
	for(i=1;i<=vex;i++)
	{
		mindist=0;
		k=start;
		for(j=1;j<=vex;j++)
			if(!visited[j] && dist[j]>mindist)
			{
				k=j;
				mindist=dist[j];
			}
		visited[k]=1;
		for(j=1;j<=vex;j++)
			if(!visited[j])
				dist[j]=max(dist[j],min(map[k][j],dist[k]));
	}
	cout << dist[end] ;
	printf("\n\n");
}

int main()
{
	int k,city;
	int i,j;
	int a,b,w;
	cin >> city;
	for(k=1;k<=city;k++)
	{
		memset(visited,0,sizeof(visited));
		memset(dist,0,sizeof(dist));
		memset(map,0,sizeof(map));
		cin >> vex >> street;
		for(i=1;i<=street;i++)
		{
			cin >> a >> b>>w;
			map[a][b]=w;
			map[b][a]=w;
		}
		printf("Scenario #%d:\n",k);
		dijstra(1,vex);
	}
	return 0;
}
