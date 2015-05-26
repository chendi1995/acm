/*************************************************************************
    > File Name: FZU2150.cpp
    > Author: chendi
    > Mail: chendi1995@sohu.com 
    > The compiler environment:vim + gcc
    > Created Time: 2015年03月14日 星期六 16时02分49秒
 ************************************************************************/
#include<iostream>
#include<string.h>
#include<stdlib.h>
#define MAXSIZE 1000000
using namespace std;
typedef struct 
{
	char grid;
	int type;//0代表空地，1代表草; 
}grass;

typedef struct
{
	int i;
	int j;
	int step;
}point;

typedef struct
{
	point data[MAXSIZE];
	int front;
	int rear;
}Queue;

int m;
int T;
int MIN[110];
int M,N;
grass g[15][15];
int visited[15][15];

Queue* InitQueue(void)
{
	Queue *q;
	q=(Queue *)malloc(sizeof(Queue));
	q->front=q->rear=0;
	return q;
}

int Enter(Queue *q, point x)
{
	if((q->rear+1)%MAXSIZE==q->front)
	{
		cout << "队满" << endl;
		return -1;
	}
	else
	{
		q->rear=(q->rear+1)%MAXSIZE;
		q->data[q->rear]=x;
		return 0;
	}
}

point Delete(Queue *q)
{
	q->front=(q->front+1)%MAXSIZE;
	return q->data[q->front];
}

int EmptyQueue(Queue *q)
{
	if(q->front==q->rear)
		return 0;
	else 
		return -1;
}

void BFS(point x,point y,Queue *qa,Queue *qb)
{
	point a,b,temp1,temp2;
	int i,j;
	int num=0;
	int count=0;
	memset(visited,0,sizeof(visited));
	for(i=1;i<=M;i++)
		for(j=1;j<=N;j++)
			if(g[i][j].type>0)
				num++;
	visited[x.i][x.j]=1;
	visited[y.i][y.j]=1;
	x.step=0;
	y.step=0;
	Enter(qa,x);
	Enter(qb,y);
	if(x.i==y.i && x.j==y.j)
		count++;
	if(!(x.i==y.i && x.j==y.j))
		count=count +2;
	if(count == num)
	{
		MIN[m]=x.step;
		return;

	}
	while(1)
	{
		if(EmptyQueue(qa)!=0)
		{
			a=Delete(qa);
			temp1=a;
			a=temp1;
			a.step++;
			a.i=a.i-1;
			if(a.i>0 && g[a.i][a.j].type>0 && !visited[a.i][a.j])
			{
				Enter(qa,a);
				visited[a.i][a.j]=1;
				count++;
				if(count == num)
				{
					if(a.step < MIN[m])
						MIN[m] =a.step;
					break;
				}
			}
			a=temp1;
			a.step++;
			a.i=a.i+1;
			if(a.i<=M && g[a.i][a.j].type>0 && !visited[a.i][a.j])
			{
				Enter(qa,a);
				visited[a.i][a.j]=1;
				count++;
				if(count == num)
				{
					if(a.step < MIN[m])
						MIN[m] =a.step;
					break;
				}
			}
			a=temp1;
			a.step++;
			a.j=a.j-1;
			if(a.j>0 && g[a.i][a.j].type>0 && !visited[a.i][a.j])
			{
				Enter(qa,a);
				visited[a.i][a.j]=1;
				count++;
				if(count == num)
				{
					if(a.step < MIN[m])
						MIN[m] =a.step;
					break;
				}
			}
			a=temp1;
			a.step++;
			a.j=a.j+1;
			if(a.j<=N && g[a.i][a.j].type>0 && !visited[a.i][a.j])
			{
				Enter(qa,a);
				visited[a.i][a.j]=1;
				count++;
				if(count == num)
				{
					if(a.step < MIN[m])
						MIN[m] =a.step;
					break;
				}
			}
		}
		if(EmptyQueue(qb)!=0)
		{
			b=Delete(qb);
			temp2=b;
			b=temp2;
			b.step++;
			b.i=b.i-1;
			if(b.i>0 && g[b.i][b.j].type>0 && !visited[b.i][b.j])
			{
				Enter(qb,b);
				visited[b.i][b.j]=1;
				count++;
				if(count == num)
				{
					if(b.step < MIN[m])
						MIN[m] =b.step;
					break;
				}
			}
			b=temp2;
			b.step++;
			b.i=b.i+1;
			if(b.i<=M && g[b.i][b.j].type>0 && !visited[b.i][b.j])
			{
				Enter(qb,b);
				visited[b.i][b.j]=1;
				count++;
				if(count == num)
				{
					if(b.step < MIN[m])
						MIN[m] =b.step;
					break;
				}
			}
			b=temp2;
			b.step++;
			b.j=b.j-1;
			if(b.j>0 && g[b.i][b.j].type>0 && !visited[b.i][b.j])
			{
				Enter(qb,b);
				visited[b.i][b.j]=1;
				count++;
				if(count == num)
				{
					if(b.step < MIN[m])
						MIN[m] =b.step;
					break;
				}
			}
			b=temp2;
			b.step++;
			b.j=b.j+1;
			if(b.j<=N && g[b.i][b.j].type>0 && !visited[b.i][b.j])
			{
				Enter(qb,b);
				visited[b.i][b.j]=1;
				count++;
				if(count == num)
				{
					if(b.step < MIN[m])
						MIN[m] =b.step;
					break;
				}
			}
		}
		if(EmptyQueue(qa)==0 && EmptyQueue(qb)==0)
			break;
	}
}

void create(void)
{
	int i,j;
	cin >> M >> N;
	for(i=1;i<=M;i++)
		for(j=1;j<=N;j++)
		{
			cin >> g[i][j].grid;
			if(g[i][j].grid=='.')
				g[i][j].type=0;
			if(g[i][j].grid=='#')
				g[i][j].type=1;
		}
}


int main()
{
	int i,j,k,l;
	point A,B;
	cin >> T;
	Queue *qa,*qb;
	qa=InitQueue();
	qb=InitQueue();
	for(m=1;m<=T;m++)
	{
		MIN[m]=32767;
		create();
		for(i=1;i<=M;i++)
			for(j=1;j<=N;j++)
				for(k=1;k<=M;k++)
					for(l=1;l<=N;l++)
						if(g[i][j].type>0 && g[k][l].type>0)
						{
							qa->front=qa->rear=0;
							qb->front=qb->rear=0;
							A.i=i;
							A.j=j;
							B.i=k;
							B.j=l;
							cout <<i<<j<<k<<l<<endl;
							BFS(A,B,qa,qb);
							cout << MIN[m]<<endl;
						}
	}
	for(m=1;m<=T;m++)
	{
		if(MIN[m]!=32767)
			cout<<"Case "<<m<<": "<< MIN[m] <<endl;
		else
			cout<<"Case "<<m<<": "<< -1 <<endl;
	}
	return 0;
}
