//PB函数调用前线MR判素数，每次可以分解出一个因数(不一定是素数)，需要配合MR
LL PB(LL n, int c=12323, int x0=2){
    if(~n & 1) return 2;
    LL x, y, d = 1, k = 0, i = 1;
    x = y = x0;
    while(true){
        x = (MulMod(x, x+n) + c)%n;     //f(x) = x*x+c, c可以换成其他素数
        d = gcd(n+x-y, n);
        if(d!=1 && d<n) return d;       //如果一直TLE，尝试d<=n
        if(y==x) return n;
        if(++k == i) y = x, i<<=1;
    }
}

//分解质因数部分
LL s[110]; int l=0;
void gn(LL n, int op = 12323){
    if(isp(n)){
        s[l++] = n;
        return;
    }
    LL x = PB(n);
    while(x==n) x = PB(n, --op);
    gn(x);
    gn(n/x);
}
//调用gn(n);分解，调用s和l初始化，调用后sort(s, s+l);这里得到所有的因子
//op一般不需要改
