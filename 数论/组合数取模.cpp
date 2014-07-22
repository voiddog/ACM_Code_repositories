//组合数取素数mod
ll f[MAXP];
void initp(int p){
    f[0]=f[1]=1;
    for(int i=2;i<p;i++)f[i]=(f[i-1]*i)%p;
}
ll comb(int n,int m,int p){
    if(m>n) return 0;
    ll ans=f[n];
    int g,x,y;
    exgcd(f[m],p,g,x,y);
    ans=(ans*(x%p)%p+p)%p;
    exgcd(f[n-m],p,g,x,y);
    ans=(ans*(x%p)%p+p)%p;
    return ans;
}
//n 取 m,如果可能 m>n 请特判 return 0;
ll lucas(ll n,ll m,int p){
    ll ans=1;
    //initp(p);
    // 调用前初始化
    while(n && m && ans){
	ans=comb(n%p,m%p,p)*ans%p;
	n/=p;
	m/=p;
    }
    return ans;
}
ll comb(int n,int m,ll p){
    //版本二:要求 m < 10^6,p 为素数,时间 O(m)
    if(m>n) return 0;
    if(m>n-m) m=n-m;
    ll ans=1,tmp=1,g,x,y;
    for(int i=0;i<m;i++){
	ans=ans*(n-i)%p;
	tmp=tmp*(i+1)%p;
    }
    exgcd(tmp,p,g,x,y);
    return (ans*(x%p)%p+p)%p;
}
ll lucas(ll n,ll m,ll p);
//同版本一 lucas()

//去合数mod
int l,b[20],f[20];
//版本三:时间 O(m*log(n))
ll ad(ll n,int op){
    for(int i=0;i<l;i++)
	while(n%b[i]==0){
	    f[i]+=op;
	    n/=b[i];
	}
    return n;
}
ll comb(ll n,int m,ll p){
    gn(p,l,b,f);
    //见本模板第一页
    memset(f,0,sizeof(f));
    ll ans=1,tmp=1,g,x,y;
    for(int i=0;i<m;i++){
	ans=ans*ad(n-i,1)%p;
	tmp=tmp*ad(i+1,-1)%p;
    }
    exgcd(tmp,p,g,x,y);
    ans=(ans*(x%p)%p+p)%p;
    for(int i=0;i<l;i++) ans=ans*powmod(b[i],f[i],p)%p;
    return ans;
}
ll fn(int n,int p){
    //版本四:要求 n,m<10^6,时间 O(n*log(n))
    ll ans=0;
    while(n>=p) ans+=(n/=p);
    return ans;
}
ll comb(int n,int m,int mod){
    //gp();
    //使用前预处理素数,N 要取到最大的素数 > n
    ll ans=1;
    for(int i=0;p[i]<=n;i++)
	ans=ans*powmod(p[i],fn(n,p[i])-fn(m,p[i])-fn(n-m,p[i]),mod)%mod;
    return ans;
}
//版本五:要求 m=p^c < 10^5,时间 O(m)
ll gfn(int n,int p,int mod){
    //n!中与 p 互质的部分对 mod 取模的结果
    if(n<=p) return f[n];
    ll ans=f[n%mod]*powmod(f[mod],n/mod,mod)%mod;
    ans=ans*gfn(n/p,p,mod)%mod;
    return ans;
}
14ll comb_c(ll n,ll m,ll p,ll mod){
    f[0]=f[1]=1;
    for(int i=2;i<=mod;i++)
	if(i%p) f[i]=(f[i-1]*i)%mod;
	else f[i]=f[i-1];
    ll ans=gfn(n,p,mod);
    ll g,x,y;
    exgcd(gfn(m,p,mod),mod,g,x,y);
    ans=(ans*(x%mod)%mod+mod)%mod;
    exgcd(gfn(n-m,p,mod),mod,g,x,y);
    ans=(ans*(x%mod)%mod+mod)%mod;
    return ans*powmod(p,fn(n,p)-fn(m,p)-fn(n-m,p),mod)%mod;
    //fn()来自版本四
}
//究极版
ll excomb(ll n,ll m,int mod){
    int a[20],b[20],f[20],l;
    gn(mod,l,a,f);
    for(int i=0;i<l;i++)
	if(f[i]==1) b[i]=lucas(n,m,a[i]);
	else b[i]=comb_c(n,m,a[i],powmod(a[i],f[i],mod));
    return modx(a,b,l);
    //国剩余定理
}
//下一个组合
bool next_comb(int a[],int n,int m){
    //m 取 n 个数,下一个组合,从 1 开始,数组递增
    int i,j;
    for (i=--n;i>=0 && a[i]==m-n+i;i--); //注意分号,需要从 0 开始则 i=n-1;
    if(i==-1) return false; //已经是最大组合,下一个组合生成失败
    for(a[i]++,j=i+1;j<=n;j++) a[j]=a[j-1]+1;
    return true;
}
