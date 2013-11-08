//1.一个单独的顶点是一条路径；
//2．如果存在一路径p1,p2,......pk，其中p1 为起点，pk为终点，那么在覆盖图中，顶点p1,p2,......pk不再与其它的顶点之间存在有向边．
//最小路径覆盖就是找出最小的路径条数，使之成为P的一个路径覆盖．
//路径覆盖与二分图匹配的关系（必须是没有圈的有向图）：
//最小路径覆盖=|P|－最大匹配数
//其中最大匹配数的求法是把P中的每个顶点pi分成两个顶点pi'与pj''，如果在p中存在一条pi到pj的边，那么在二分图P'中就有一条连接pi'与pj''的无向边；这里pi' 就是p中pi的出边，pj''就是p中pj 的一条入边；
/*bool 寻找从k出发的对应项出的可增广路
{
    while (从邻接表中列举k能关联到顶点j)
    {
        if (j不在增广路上)
        {
            把j加入增广路;
            if (j是未盖点 或者 从j的对应项出发有可增广路)
            {
                修改j的对应项为k;
                则从k的对应项出有可增广路,返回true;
            }
        }
    }
    则从k的对应项出没有可增广路,返回false;
}
void 匈牙利hungary()
{
    for i->1 to n
    {
        if (则从i的对应项出有可增广路)
            匹配数++;
    }
    输出 匹配数;
}*/
#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
const int maxn=5050;
struct List
{
	int h[maxn];
	int u[3*maxn];
	int v[3*maxn];
	int next[3*maxn];
	int len;
	void Build(int s,int e)
	{
		u[len]=s;
		v[len]=e;
		next[len]=h[s];
		h[s]=len;
		len++;
	}
	void init(int n)
	{
		len=0;
		memset(h,-1,sizeof(int)*(n+1));
	}
};
List road;
bool used[maxn];
int mat[maxn];
void init(int n)
{
	road.init(n);
	memset(mat,0,sizeof(int)*(n+1));
}
bool CrossPath(int k)
{
	for(int i=road.h[k];~i;i=road.next[i])
	{
		int v=road.v[i];
		if (!used[v])
		{
			used[v]=1;
			if(!mat[v]||CrossPath(mat[v]))
			{
				mat[v]=k;
				return true;
			}
		}
	}
	return false;
}
int hungary(int n)
{
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		if(CrossPath(i))
		{
			ans++;
		}
		memset(used,0,sizeof(int)*(n+1));
	}
	return ans;
}
void Solve()
{
	int n,s,e;
	scanf("%d",&n);
	init(n);
	for (int i = 0; i < 3*n/2; i++)
	{
		scanf("%d%d",&s,&e);
		road.Build(s,e);
		road.Build(e,s);
	}
	printf("%d\n",hungary(n)/2);
}
int main()
{
	int test;
	scanf("%d",&test);
	while (test--)
	{
		Solve();
	}
	return 0;

}
