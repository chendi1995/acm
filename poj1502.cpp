/*************************************************************************
    > File Name: poj1502.cpp
    > Author: chendi
    > Mail: chendi1995@sohu.com 
    > The compiler environment:vim + gcc
    > Created Time: 2015年03月30日 星期一 16时44分49秒
 ************************************************************************/
#include<iostream>
#include<stdlib.h>
#include<string.h>
#define MAXNODE 110
#define INF 1000000
using namespace std;
int n;
int map[MAXNODE][MAXNODE];
int dist[MAXNODE];
int visited[MAXNODE];

void dijkstra(int start)
{
	int mindist;
	int max=0;
	int i,j,k;
	for(i=1;i<=n;i++)
		dist[i]=map[start][i];
	visited[start]=1;
	dist[start]=0;
	for(i=1;i<=n;i++)
	{
		mindist=INF;
		for(j=1;j<=n;j++)
			if(!visited[j] && dist[j]<mindist)
			{
				k=j;
				mindist=dist[j];
			}
		visited[k]=1;
		for(j=1;j<=n;j++)
			if(!visited[j] && map[k][j]<INF && dist[k]+map[k][j]<dist[j])
				dist[j]=dist[k]+map[k][j];
	}
	for(i=1;i<=n;i++)
		if(dist[i]>max)
			max=dist[i];
	cout << max << endl;
}

int main()
{
	int i,j;
	char c[20];
	memset(map,INF,sizeof(map));
	cin >> n;
	for(i=1;i<=n;i++)
		map[i][i]=0;
	for(i=2;i<=n;i++)
		for(j=1;j<=i-1;j++)
		{
			cin >> c;
			if(c[0]=='x')
				map[i][j]=map[j][i]=INF;
			if(c[0]!='x')
				map[i][j]=map[j][i]=atol(c);
		}
	dijkstra(1);
	return 0;

}
