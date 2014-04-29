bool MR(LL n, LL a){
    if(n==2) return true;
    LL d = n - 1, t;
    if(d&1) return false;
    while(~d&1) d >>= 1;
    t = PowMod(a, d, n);
    while(d!=n-1 && t!=1 && t!=n-1){
        d <<= 1;
        t = MulMod(t, t, n);
    }
    return (t == n-1) || (d&1);
}
//下面的isp函数返回true就是素数，注意传入大小限制
bool isp(int n){    //整数范围
    if(n == 1) return false;
    if(n == 2|| n == 7 || n == 61) return true;
    return MR(N, 2) && MR(n, 7) && MR(n, 61);
}
bool isp(LL, n){    //(2^54)范围
    if(n==1 || n==46856248255981LL) return false;
    if(n==2 || n==3 || n==7 || n==61 || n==24251) return true;
    return MR(n, 2) && MR(n, 3) && MR(n, 7) && (n, 61) && (n, 24251);
}
//如果要测试long long 范围，测试2,3,5,7,11,13,17,19,23
//推荐加if语句和2^54混合使用
