struct point
{
	double x,y;
	point(){}
	point(double xx,double yy):x(xx),y(yy){}
	point operator + (point p)
	{
		return point(x+p.x,y+p.y);
	}
	point operator - (point p)
	{
		return point(x-p.x,y-p.y);
	}
	point operator * (double d)
	{
		return point(x*d,y*d);
	}
	double dot(point p)
	{
		return x*p.x+y*p.y;
	}
	double det(point p)
	{
		return x*p.y-y*p.x;
	}
};
//字典序比较
bool Cmp_x(const point &p,const point &q)
{
	if(p.x!=q.x)
	{
		return p.x<q.x;
	}
	return p.y<q.y;
}
//求凸包
vector<point> Convex_hull(point *ps,int n)
{
	sort(ps,ps+n,Cmp_x);
	int k=0;//凸包的顶点数
	vector<point> qs(n*2);
	//构造凸包下侧
	for(int i=0;i<n;i++)
	{
		while(k>1&&(qs[k-1]-qs[k-1]).det([ps[i]-qs[k-1])<=0)
		{
			k--;
		}
		qs[k++]=ps[i];
	}
	//构造凸包上侧
	for(int i=n-2,t=k;i>=0;i--)
	{
		while(k>t&&(qs[k-1]-qs[k-2]).det(ps[i]-qs[k-1])<=0)
		{
			k--;
		}
		qs[k++]=ps[i];
	}
	qs.resize(k-1);
	return qs;
}