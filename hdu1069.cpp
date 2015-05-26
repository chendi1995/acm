/*************************************************************************
    > File Name: hdu1069.cpp
    > Author: chendi
    > Mail: chendi1995@sohu.com 
    > The compiler environment:vim + gcc
    > Created Time: 2015年04月12日 星期日 15时17分08秒
 ************************************************************************/
#include<iostream>
#include<stdio.h>
#include<string.h>
#define MAXTYPE 300
using namespace std;

typedef struct
{
	int x;
	int y;
	int z;
}jx;

jx dm[MAXTYPE];

void sort(int n)
{
	int i,j;
	jx temp;
	for(i=1;i<=n-1;i++)
		for(j=1;j<=n-i-1;j++)
			if(dm[j].x<dm[j+1].x || (dm[j].x==dm[j+1].x && dm[j].y<dm[j+1].y))
			{
				temp=dm[j];
				dm[j]=dm[j+1];
				dm[j+1]=temp;
			}
}

int main()
{
	int n,kase=1;
	int i,j;
	int a,b,c;
	int cnt;
	int dp[MAXTYPE];
	int max;
	int ans;
	while(cin>>n && n!=0)
	{
		cnt=1;
		memset(dm,0,sizeof(dm));
		memset(dp,0,sizeof(dp));
		for(i=1;i<=n;i++)
		{
			cin>>a>>b>>c;
			dm[cnt].x=a;
			dm[cnt].y=b;
			dm[cnt++].z=c;
			dm[cnt].x=b;
			dm[cnt].y=a;
			dm[cnt++].z=c;
			dm[cnt].x=c;
			dm[cnt].y=b;
			dm[cnt++].z=a;
			dm[cnt].x=a;
			dm[cnt].y=c;
			dm[cnt++].z=b;
			dm[cnt].x=c;
			dm[cnt].y=a;
			dm[cnt++].z=b;
			dm[cnt].x=b;
			dm[cnt].y=c;
			dm[cnt++].z=a;
		}
		sort(cnt);
		ans=0;
		for(i=1;i<=cnt;i++)
		{
			max=0;
			for(j=1;j<i;j++)
			{
				if(dm[i].x<dm[j].x&&dm[i].y<dm[j].y && max<dp[j])
					max=dp[j];
			}
			dp[i]=max+dm[i].z;
			if(dp[i]>ans)
				ans=dp[i];
		}
		printf("Case %d: maximum height = %d\n",kase++,ans);
	}
	return 0;
}
