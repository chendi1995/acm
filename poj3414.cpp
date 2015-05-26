/*************************************************************************
    > File Name: poj3414.cpp
    > Author: chendi
    > Mail: chendi1995@sohu.com 
    > The compiler environment:vim + gcc
    > Created Time: 2015年03月11日 星期三 20时13分18秒
 ************************************************************************/
#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAXSIZE 100000
using namespace std;
int dq[3];
int zg[3];
int C;
int visited[101][101];
typedef struct s
{
	int A;
	int B;
	int step;
	int  parent;
	char msg[20];
}AB;

AB X[1000000];
typedef struct
{
	AB data[MAXSIZE];
	int front;
	int rear;
}Queue;

Queue* InitQueue(void)
{
	Queue *q;
	q=(Queue *)malloc(sizeof(Queue));
	q->front=q->rear=MAXSIZE-1;
	return q;
}

int Enter(Queue *q, AB x)
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

AB Delete(Queue *q)
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
void fill(int i)
{	
	if(dq[i]<zg[i])
		dq[i]=zg[i];
}

void drop(int i)
{
	if(dq[i]>0)
		dq[i]=0;
}

void pour(int i, int j)
{
	if(dq[i]<zg[j]-dq[j])
	{
		dq[j]=dq[j]+dq[i];
		dq[i]=0;
		
	}
	else
	{
		dq[i]=dq[i]-(zg[j]-dq[j]);
		dq[j]=zg[j];
	}
}
int  main()
{
	AB x;
	AB temp;
	char m[100][20];
	int n=0;
	int i=1;
	int j;
	int step;
	int p;
	Queue *Q;
	cin >> zg[1] >> zg[2] >> C;
	Q=InitQueue();
	temp.A=0;
	temp.B=0;
	temp.step=1;
	temp.parent=0;
	visited[temp.A][temp.B]=1;
	Enter(Q,temp);
	while(1)
	{
		if(EmptyQueue(Q)==0)
		{
			cout << "impossible" <<endl;
			break;
		}
		x=Delete(Q);
		X[i]=x;
		temp=x;
		dq[1]=temp.A;
		dq[2]=temp.B;
		x=temp;
		x.step++;
		fill(1);
		x.A=dq[1];
		x.B=dq[2];
		strcpy(x.msg,"FILL(1)");
		if(!visited[x.A][x.B])
		{
			x.parent=i;
			if(x.A==C || x.B==C)
			{
				X[++i]=x;
				cout << --x.step << endl;
				break;
			}
			visited[x.A][x.B]=1;
			if(Enter(Q,x)<0)
				cout <<"队满！\n" << endl;
		}
		x=temp;
		x.step++;
		dq[1]=temp.A;
		dq[2]=temp.B;
		fill(2);
		x.A=dq[1];
		x.B=dq[2];
		strcpy(x.msg,"FILL(2)");
		if(!visited[x.A][x.B])
		{
			x.parent=i;	
			if(x.A==C || x.B==C)
			{
				X[++i]=x;
				cout << --x.step << endl;
				break;
			}
			visited[x.A][x.B]=1;
			if(Enter(Q,x)<0)
				cout <<"队满！\n" << endl;
		}
		x=temp;
		x.step++;
		dq[1]=temp.A;
		dq[2]=temp.B;
		drop(1);
		x.A=dq[1];
		x.B=dq[2];
		strcpy(x.msg,"DROP(1)");
		if(!visited[x.A][x.B])
		{
			x.parent=i;
			if(x.A==C || x.B==C)
			{
				X[++i]=x;
				cout << --x.step << endl;
				break;
			}
			visited[x.A][x.B]=1;
			if(Enter(Q,x)<0)
				cout <<"队满！\n" << endl;
		}
		x=temp;
		x.step++;
		dq[1]=temp.A;
		dq[2]=temp.B;
		drop(2);
		x.A=dq[1];
		x.B=dq[2];
		strcpy(x.msg,"DROP(2)");
		if(!visited[x.A][x.B])
		{
			x.parent=i;	
			if(x.A==C || x.B==C)
			{
				X[++i]=x;
				cout << --x.step << endl;
				break;
			}
			visited[x.A][x.B]=1;
			if(Enter(Q,x)<0)
				cout <<"队满！\n" << endl;
		}
		x=temp;
		x.step++;
		dq[1]=temp.A;
		dq[2]=temp.B;
		pour(1,2);
		x.A=dq[1];
		x.B=dq[2];
		strcpy(x.msg,"POUR(1,2)");
		if(!visited[x.A][x.B])
		{
			x.parent=i;	
			if(x.A==C || x.B==C)
			{
				X[++i]=x;
				cout << --x.step << endl;
				break;
			}
			visited[x.A][x.B]=1;
			if(Enter(Q,x)<0)
				cout <<"队满！\n" << endl;
		}
		x=temp;
		x.step++;
		dq[1]=temp.A;
		dq[2]=temp.B;
		pour(2,1);
		x.A=dq[1];
		x.B=dq[2];
		strcpy(x.msg,"POUR(2,1)");
		if(!visited[x.A][x.B])
		{
			x.parent=i;
			if(x.A==C || x.B==C)
			{
				X[++i]=x;
				cout << --x.step << endl;
				break;
			}
			visited[x.A][x.B]=1;
			if(Enter(Q,x)<0)
				cout <<"队满！\n" << endl;
		}
		i++;
	}
	p=i;
	for(j=1;j<=x.step;j++)
	{
		strcpy(m[j],X[p].msg);
		p=X[p].parent;
	}
	for(j=x.step ;j>=1;j--)
	{
		cout << m[j] <<endl;
	}
	return 0;
}
