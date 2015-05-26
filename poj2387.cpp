/*************************************************************************
    > File Name: poj2387.cpp
    > Author: chendi
    > Mail: chendi1995@sohu.com 
    > The compiler environment:vim + gcc
    > Created Time: 2015年03月23日 星期一 19时42分11秒
 ************************************************************************/
#include<iostream>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define INFINITY 100000
#define MAXVEX 1010
int map[MAXVEX][MAXVEX];
int T,N;
int visited[MAXVEX];
using namespace std;

void Dijkstra(int start,int end,int dist[])
{
	int mindist,i,j,k;
	for(i=1;i<=N;i++)
		dist[i]=map[start][i];
	visited[start]=1;
	dist[start]=0;
	for(i=1;i<=N;i++)
	{
		mindist=INFINITY;
		k=start;
		for(j=1;j<=N;j++)
			if(!visited[j] && dist[j]<mindist)
			{
				k=j;
				mindist=dist[j];
			}
		visited[k]=1;
		for(j=1;j<=N;j++)
		{
			if(!visited[j] && map[k][j]<INFINITY && dist[k]+map[k][j]<dist[j])
				dist[j]=dist[k]+map[k][j];
		}
	}
	cout << dist[end] << endl;
}

int main()
{
	int i,j;
	int a,b;
	int l;
	int dist[MAXVEX];
	cin >> T >> N ;
	for(i=1;i<=N;i++)
		for(j=1;j<=N;j++)
			map[i][j]=INFINITY;
	for(i=1;i<=T;i++)
	{
		cin >> a >>b >>l;
		if(map[a][b]>l)
		{
			map[a][b]=l;	
			map[b][a]=l;
		}
	}
	Dijkstra(1,N,dist);
	return 0;
}

