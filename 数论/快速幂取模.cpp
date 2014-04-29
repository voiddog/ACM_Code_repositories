LL PowMod(LL a, LL n, LL m){    //a^n mod m
    LL y = 1;
    while(n){
        if(n&1) y = y*a%m;
        if(n>>=1) a = a*a%m;
    }
    return y;
}
