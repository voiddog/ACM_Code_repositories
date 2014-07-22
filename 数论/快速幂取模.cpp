ll mulmod(ll a,ll n,ll m){
    // a*n mod m
    ll y=0;
    a%=m;
    while(n){
	if(n&1) y+=a;
	if(y>=m) y-=m;
	n>>=1;
	a<<=1;
	if(a>=m) a-=m;
    }
    return y;
}
