//普通版，模数不互质
LL modx(LL a[], LL b[], int len){
    LL a1, a2, b1, b2, x, y, d;
    bool flag = false;
    a1 = a[0], b1 = b[0];
    for (int i = 1; i < len; i++){
	a2 = a[i], b2 = b[i];
	exgcd(a1, a2, d, x, y);
	LL c = b2 - b1;
	if (c%d){
	    flag = true;
	    break;
	}
	LL t = a2 / d;
	x = (x*c) / d;
	x = (x%t + t) % t;
	b1 = a1*x + b1;
	a1 = a1*a2 / d;
	b1 = (b1%a1 + a1) % a1;
    }
    if (flag) return -1;
    else return b1;
}

LL modx(LL a[], LL b[],int len){
    // x = bi (mod ai),注意这里 a[]两两互质
    LL d, x, y, m, n=1, ret=0;
    for(int i=0;i<len;i++) n*=a[i];
    for(int i=0;i<len;i++){
	m=n/a[i];
	exgcd(a[i],m,d,x,y);
	ret=(ret+y*m*b[i])%n;
    }
    return (n+ret%n)%n;
}
