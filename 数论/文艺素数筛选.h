//文艺素数筛选
const int maxn=3000005;
int pr[maxn],p[maxn/10],lp;
void gp(){
	for(int i=2;i<maxn;i++){
		if(!pr[i]){
			p[lp++]=pr[i]=i;
		}
		for(int j=0;j<lp&&i*p[j]<maxn;j++){
			pr[i*p[j]]=p[j];
			if(i%p[j]==0){
				break;
			}
		}
	}
}
//常用素数
//Hash：4567,10007,10009,20011,49999，50111,100003,204047,582821,1280519
//大素数：1004535809,211812353,4179340454199820289
