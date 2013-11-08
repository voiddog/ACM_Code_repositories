M pow(M a,int k){
    M c;
    for(int i=0;i<=n;i++)
        for(int j=0;j<=n;j++)
            c.s[i][j]=(i==j);
    for(;k;k>>=1){
        if(k&1)
            c=mul(c,a);
        a=mul(a,a);
    }
    return c;
}
