LL MulMod(LL a,LL n, LL m){     //a*n mod m
    LL y = 0;
    a %= m;
    while(n){
        if(n&1) y+=a;
        if(y>=m) y-=m;
        n>>=1;
        a<<=1;
        if(a >= m) a -= m;
    }
    return y;
}
