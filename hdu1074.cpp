/*************************************************************************
    > File Name: hdu1074.cpp
    > Author: chendi
    > Mail: chendi1995@sohu.com 
    > The compiler environment:vim + gcc
    > Created Time: 2015年04月12日 星期日 20时53分14秒
 ************************************************************************/
#include<iostream>
#include<string.h>
#define MAX (1<<15)+10
#define INF 0x3f3f3f3f
using namespace std;

int dp[MAX],parent[MAX];
int t[MAX];
int dead[20],fin[20];
char s[20][105];

void output(int n)
{
	int tmp;
	if(n==0)
		return;
	tmp=n-(1<<parent[n]);
	output(tmp);
	cout << s[parent[n]] << endl;

}

int main()
{
	int T;
	int n;
	int bit;
	int score;
	int tmp;
	int i,j;
	cin >> T;
	while(T--)
	{
		memset(dp,0,sizeof(dp));
		memset(parent,0,sizeof(parent));
		memset(t,0,sizeof(t));
		memset(dead,0,sizeof(dead));
		cin >> n;
		for(i=0;i<=n-1;i++)
			cin >>s[i] >>dead[i]>>fin[i];
		bit=1<<n;
		for(i=1;i<bit;i++)
		{
			dp[i]=INF;
			for(j=n-1;j>=0;j--)
			{
				tmp=1<<j;
				if(!(i&tmp))
					continue;
				score=t[i-tmp]+fin[j]-dead[j];
				if(score<0)
					score=0;
				if(dp[i-tmp]+score<dp[i])
				{
					dp[i]=score+dp[i-tmp];
					t[i]=t[i-tmp]+fin[j];
					parent[i]=j;
				}
			}
		}
		cout << dp[bit-1] << endl;
		output(bit-1);
	}
	return 0;
}

