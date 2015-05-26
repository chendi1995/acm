/*************************************************************************
    > File Name: hdu1160.cpp
    > Author: chendi
    > Mail: chendi1995@sohu.com 
    > The compiler environment:vim + gcc
    > Created Time: 2015年04月17日 星期五 16时54分21秒
 ************************************************************************/
#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
#include<stack>
#include<queue>
#define MAXN 1010
using namespace std;
typedef struct
{
	int wei;
	int spe;
	int dp;
	int pre;
	int order;
}Mo;

Mo mou[MAXN];


int compare(Mo a,Mo b)
{
	if(a.wei!=b.wei)
		return a.wei<b.wei;
	else
		return a.spe>=b.spe;
}

int main()
{
	int n=0;
	int i,j;
	int ww,ss;
	int maxx=0;
	int k;
	while(~scanf("%d%d",&ww,&ss))
	{
		mou[n].wei=ww;
		mou[n].spe=ss;
		mou[n].dp=1;
		mou[n].order=n+1;
		mou[n].pre=-1;
		n++;
	}
	sort(mou,mou+n,compare);
	for(i=1;i<n;i++)
	{
		for(j=0;j<i;j++)
		{
			if(mou[i].wei>mou[j].wei&&mou[i].spe<mou[j].spe&&mou[i].dp<mou[j].dp+1)
			{
				mou[i].dp=max(mou[i].dp,mou[j].dp+1);
				mou[i].pre=j;
			}
		}
		if(mou[i].dp>=maxx) 
		{
			maxx=mou[i].dp;
			k=i;
		}
	}
	cout << maxx << endl;
	int order;
	
	stack<int>S;
	while(k!=-1)
	{
		order=mou[k].order;
		S.push(order);
		k=mou[k].pre;
	}
	while(!S.empty())
	{
		cout << S.top() << endl;
		S.pop();
	}

	return 0;
}
