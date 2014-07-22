int phi[N],p[N/10],lp;
//1-n 所有数的欧拉函数
void gphi(){
    for(int i=2;i<N;i++){
	if(!phi[i])
	    p[lp++]=i,phi[i]=i-1;
	for(int j=0;j<lp && i*p[j]<N;j++){
	    if(i%p[j]==0){
		phi[i*p[j]]=phi[i]*p[j];
		break;
	    }
	    phi[i*p[j]]=phi[i]*(p[j]-1);
	}
    }
}
ll phi(ll n){
    ll ans=n,t;
    int i=0;
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
	ans -= ans/t;
	while(n%t==0) n/=t;
    }
    return ans;
    //1..n 与 n 互质的数字之和 = n*ph(n)/2
}
