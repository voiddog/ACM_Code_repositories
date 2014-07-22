bool MR(ll n,ll a){
    if (n==2) return true;
    ll d=n-1, t;
    if(d&1) return false;
    while (~d&1) d>>=1;
    t = powmod(a,d,n);
    while(d!=n-1 && t!=1 && t!=n-1){
	d<<=1;
	t=mulmod(t,t,n);
    }
    return (t==n-1) || (d&1);
}
//上为模板,调用下面的 isp 函数返回为 true 则为素数,注意传入大小限制
bool isp(int n){
    //int 范围
    if(n==1) return false;
    if(n==2 || n== 7 || n==61) return true;
    return MR(n,2) && MR(n,7) && MR(n,61);
}
2// 1E16 (2^54) 范围
bool isp(ll n){
    if(n==1 || n==46856248255981LL) return false;
    //唯一强伪素数
    if(n==2 || n== 3 || n==7 || n==61 || n==24251) return true;
    return MR(n,2) && MR(n,3) && MR(n,7) && MR(n,61) && MR(n,24251);
}
//Ps:如需要测 long long 范围,测试 2,3,5,7,11,13,17,19,23。
//推荐增加 if 语句与 1e16 版混合使用
