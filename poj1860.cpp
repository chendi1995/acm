/*************************************************************************
    > File Name: poj1860.cpp
    > Author: chendi
    > Mail: chendi1995@sohu.com 
    > The compiler environment:vim + gcc
    > Created Time: 2015年03月29日 星期日 15时26分06秒
 ************************************************************************/
#include<iostream>
#define MAXNODE 105
#define MAXEDGE 220

using namespace std;
double dist[MAXNODE];
int all;

int N,M,S;
double V;

typedef struct
{
	int a;
	int b;
	double r;
	double c;
}weight;

weight edge[MAXEDGE];


int bellmanford(void)
{
	int i,j;
	dist[S]=V;
	for(i=1;i<=N-1;i++)
	{
		for(j=1;j<=all;j++)
			if(dist[edge[j].b]<(dist[edge[j].a]-edge[j].c)*edge[j].r)
				dist[edge[j].b]=(dist[edge[j].a]-edge[j].c)*edge[j].r;
	}
	for(i=1;i<=all;i++)
		if(dist[edge[i].b]<(dist[edge[i].a]-edge[i].c)*edge[i].r)
			return -1;
	return 0;
		
}

int main()
{
	int i;
	int a,b;
	double c,d,e,f;
	int result;
	cin >> N >> M >> S >> V;
	for(i=1;i<=M;i++)
	{
		all++;
		cin >> a >> b >> c >> d >> e >> f;
		edge[all].a=a;
		edge[all].b=b;
		edge[all].r=c;
		edge[all].c=d;
		all++;
		edge[all].a=b;
		edge[all].b=a;
		edge[all].r=e;
		edge[all].c=f;
	}
	result = bellmanford();
	if(result==-1)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
}
