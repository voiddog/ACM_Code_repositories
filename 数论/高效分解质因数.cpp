//Ps: 这里选取伪随机数方程为 F(x)= x*x+c 并默认 c = 12323。注意最大只能分解 2^62-1。
//分解失败(返回 n)就尝试变换 c,c 不得取 0 或-2。若还失败,尝试变换 X0
//PB 函数调用前先 MR 判素数,每次可以分解出一个因数(不一定是素数),需配合 MR 算法。
ll PB(ll n,int c=12323,int x0=2){
    if(~n&1) return 2;
    ll x,y,d=1,k=0,i=1;
    x=y=x0;
    while(1){
	x=(mulmod(x,x,n)+c)%n;
	//f(x)=x*x+c,c 可换 24251 或其他素数
	d=gcd(n+x-y,n);
	if(d!=1 && d<n) return d; //如莫名其妙一直 TLE 可尝试 d<n 改成 d<=n,目前没碰到过
	if(y==x) return n;
	if(++k == i) y=x,i<<=1;
    }
}
//分解质因数部分
ll s[110];int l=0;
void gn(ll n,int op=12323){
    if(isp(n)) {s[l++]=n;return;}
    ll x=PB(n);
    while(x==n) x=PB(n,--op);
    gn(x);
    gn(n/x);
}
//调用 gn(n);分解,调用前 s 和 l 初始化,调用后 sort(s,s+l);这里得到所有质因子,出现次数即指数
//op 一般不需要改
