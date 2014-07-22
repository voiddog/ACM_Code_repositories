bool h[M]; //const int M=区间长度,注意使用前调用 gp()
void gp(ll x,ll y,int &l,ll a[]){ //a[]筛选结果,l 为数量
    l=0;
    if(y<x) return;
    ll d=y-x;
    memset(h,0,sizeof h);
    for(int i=0;p[i]*p[i]<=y;i++){
	int j=max((ll)p[i]*p[i],x-x%p[i]);
	if(j<x) j+=p[i];
	for(j-=x;j<=d;j+=p[i])
	    h[j]=1;
    }
    for(ll i=max(x,2ll);i<=y;i++)if(!h[i-x]) a[l++]=i;
}
