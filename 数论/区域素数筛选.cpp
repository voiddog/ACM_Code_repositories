bool h[M];      //const int M = 区间长度，使用前调用gp
void gp(LL x, LL y, int &l, LL a[]){
    l=0;
    if(y<x) return;
    LL d = y-x;
    memset(h, 0, sizeof(h));
    for(int i=0; p[i]*p[i] <= y; i++){
        int j = max((LL)p[i]*p[i], x-x%p[i]);
        if(j<x) j+=p[i];
        for(j-=x; j<=d; j+=p[i]){
            h[j] = 1;
        }
        for(LL i = max(x, 2LL); i<=y; i++){
            if(!h[i-x]) a[l++] = i;
        }
    }
}
