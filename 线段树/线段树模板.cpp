//定义左右儿子宏定义
#define lson l,mid,id<<1
#define rson mid+1,r,id<<1|1
const int MAXN=100000;//最大个数
int tree[MAXN<<2];//储存线段树的数据
//向上更新
void PushUp(int id)
{
	tree[id]=tree[id<<1]+tree[id<<1|1];//更具需要写更新操作
}
//建立线段树
void Build(int l,int r,int id)
{
	if(l==r)
	{
		cin>>tree[id];
		return;
	}
	int mid=(l+r)>>1;
	Build(lson),Build(rson);
	PushUp(id);
}
//单点更新
void Update(int x,int c,int l,int r,int id)
{
	if(l==r&&x==l)
	{
		tree[id]+=c;
		return;
	}
	int mid=(l+r)>>1;
	if(x<=mid)
	{
		Update(x,c,lson);
	}
	else
	{
		Update(x,c,rson);
	}
	PushUp(id);
}
//区间更新
void Update(int L,int R,int c,int l,int r,int id)
{
	if(L<=l&&r<=R)
	{
		tree[id]+=c*(r-l+1);
		return;
	}
	int mid=(l+r)>>1;
	if(L<=mid)
	{
		Update(L,R,c,lson);
	}
	if(R>mid)
	{
		Update(L,R,c,rson);
	}
	PushUp(id);
}
//单点查询
int Query(int x,int l,int r,int id)
{
	if(l==r&&r==x)
	{
		return tree[id];
	}
	int mid=(l+r)>>1;
	if(x<=mid)
	{
		return Query(x,lson);
	}
	else
	{
		return Query(x,rson);
	}
}
//区间查询
int Query(int L,int R,int l,int r,int id)
{
	if(L<=l&&r<=R)
	{
		return tree[id];
	}
	int mid=(l+r)>>1;
	if(R<=mid)
	{
		return Query(L,R,lson);
	}
	else if(L>mid)
	{
		return Query(L,R,rson);
	}
	else
	{
		return Query(L,R,lson)+Query(L,R,rson);
	}
}