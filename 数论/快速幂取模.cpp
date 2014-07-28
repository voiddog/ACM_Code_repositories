ll powmod(ll a,ll n,ll m){
    // a^n mod m
    ll y=1;
    while(n){
	if(n&1) y=y*a%m; //m 大于 int 范围则 y=mulmod(y,a,m);
	if(n>>=1)a=a*a%m; //m 大于 int 范围则 a=mulmod(a,a,m);
    }
    return y;
}
