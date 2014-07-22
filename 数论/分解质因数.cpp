void gn(ll n,int &l,int b[],int f[]){
    // l 质因子个数,b[]质因子,f[]对应指数
    int i=0,t;
    l=0;
    while(n>1){
	if(n<N) t=pr[n];
	else{
	    t=n;
	    for(;i<lp && n/p[i]>=p[i];i++)
		if(n%p[i]==0){
		    t=p[i];
		    break;
		}
	}
	f[l]=0;
	while(n%t==0)
	    n/=t,f[l]++;
	b[l++]=t;
    }
}
