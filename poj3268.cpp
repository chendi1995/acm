/*************************************************************************
    > File Name: poj3268.cpp
    > Author: chendi
    > Mail: chendi1995@sohu.com 
    > The compiler environment:vim + gcc
    > Created Time: 2015年03月26日 星期四 17时33分26秒
 ************************************************************************/
#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#define MAXVEX 1010
#define INF 0x3f3f3f3f

using namespace std;
int map[MAXVEX][MAXVEX];
int visited[MAXVEX];
int N,M,X;
int dist[MAXVEX];
int redist[MAXVEX];

void  dijkstra1(int start)
{
	int i,j,k,mindist;
	memset(visited,0,sizeof(visited));
	for(i=1;i<=N;i++)
		dist[i]=map[start][i];
	visited[start]=1;
	dist[start]=0;
	for(i=1;i<=N;i++)
	{
		mindist=INF;
		k=start;
		for(j=1;j<=N;j++)
			if(!visited[j] && dist[j]<mindist)
			{
				k=j;
				mindist=dist[j];
			}
		visited[k]=1;
		for(j=1;j<=N;j++)
			if(!visited[j] && map[k][j]<INF &&map[k][j]+dist[k]<dist[j])
				dist[j]=map[k][j]+dist[k];
	}

}

void  dijkstra2(int start)
{
	int i,j,k,mindist;
	memset(visited,0,sizeof(visited));
	for(i=1;i<=N;i++)
		redist[i]=map[start][i];
	visited[start]=1;
	redist[start]=0;
	for(i=1;i<=N;i++)
	{
		mindist=INF;
		k=start;
		for(j=1;j<=N;j++)
			if(!visited[j] && redist[j]<mindist)
			{
				k=j;
				mindist=redist[j];
			}
		visited[k]=1;
		for(j=1;j<=N;j++)
			if(!visited[j] && map[k][j]<INF &&map[k][j]+redist[k]<redist[j])
				redist[j]=map[k][j]+redist[k];
	}

}


int main()
{
	int i,j;
	int max=0;
	int sum;
	int temp;
	int a,b,c;
	cin >> N >> M >> X;
	memset(map,INF,sizeof(map));
	for(i=1;i<=M;i++)
	{
		cin >> a >> b >>c;
		map[a][b]=c;
	}
	dijkstra1(X);
	for(i=1;i<=N;i++)
		for(j=1;j<=i;j++)
		{
			temp=map[i][j];
			map[i][j]=map[j][i];
			map[j][i]=temp;
		}
	dijkstra2(X);
	for(i=1;i<=N;i++)
		if(dist[i]+redist[i]>max)
			max=dist[i]+redist[i];
	cout << max <<endl;
	return 0;
}
