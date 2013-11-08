//文艺素数筛选
const int maxn=3000005;
int pr[maxn],p[maxn/10],lp;
void gp()
{
	for(int i=2;i<maxn;i++)
	{
		if(!pr[i])
		{
			p[lp++]=pr[i]=i;
		}
		for(int j=0;j<lp&&i*p[j]<maxn;j++)
		{
			pr[i*p[j]]=p[j];
			if(i%p[j]==0)
			{
				break;
			}
		}
	}
}
