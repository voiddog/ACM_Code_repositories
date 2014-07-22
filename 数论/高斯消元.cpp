//vector
const double EPS = 1e-10;
typedef vector<double> vec;
typedef vector<vec> mat;

//求解Ax=b，其中A是方阵
//当方程无解或者有无穷多解的时候，返回一个长度为0的数组
vec gauss_jordan(const mat& A, const vec& b){
    int n = A.size();
    mat B(n, vec(n + 1));
    for(int i=0; i<n; i++)
	for(int j=0; j<n; j++)
	    B[i][j] = A[i][j];
    //b 放在A的右边方便一起处理
    for(int i=0; i<n; i++) B[i][n] = b[i];

    for(int i=0; i<n; i++){
	// 把正在处理的未知系数的绝对值最大的式子换到第i行
	int pivot = i;
	for(int j = i; j < n; j++){
	    if(abs(B[j][i]) > abs(B[pivot][i])) pivot = j;
	}
	swap(B[i], B[pivot]);

	//if无解或者有无穷多的解
	if(abs(B[i][i]) < EPS) return vec();

	//把正在处理的未知数的系数变成1
	for(int j = i + 1; j <= n; j++) B[i][j] /= B[i][i];
	for(int j = 0; j < n; j++){
	    if(i != j){
		//从第j个式子中消去第i个未知数
		for(int k = i + 1; k <= n; k++) B[j][k] -= B[j][i] * B[i][k];
	    }
	}
    }
    vec x(n);
    for(int i=0; i<n; i++) x[i] = B[i][n];
    return x;
}

//by hundun DM
typedef double rnum; //实数版,可重载高精度分数
rnum mt[M][M],res[M]; //n*m 增广矩阵,res 为一组可行解
const rnum eps=1e-10;
inline int sgn(rnum x){return x<-eps?-1:x>eps;}
int gauss(int n,int m){
    //返回值-1 无解,否则返回自由变元个数
    int r,i,c=0,ans=0;
    --m;
    memset(res,0,sizeof res);
    for(int k=0;k<m;k++){
	for(r=i=c;i<n;i++)if(abs(mt[i][k])>abs(mt[r][k])) r=i;
	if(!sgn(mt[r][k])){ans++; res[k]=1; continue;}
	if(r!=c){
	    memcpy(mt[n],mt[r],sizeof res);
	    memcpy(mt[r],mt[c],sizeof res);
	    memcpy(mt[c],mt[n],sizeof res);
	}
	for(int i=c+1;i<n;i++)if(sgn(mt[i][k])){
	    rnum tmp=mt[i][k]/mt[c][k];
	    for(int j=k;j<=m;j++)
		mt[i][j]-=mt[c][j]*tmp;
	}
	c++;
    }
    for(int i=c;i<n;i++)if(sgn(mt[i][m]))return -1;
    for(r=m-1;res[r];r--){
	res[r]=0;
	//自由变元的取值默认值
	//for(int i=0;i<=c;i++)mt[i][m]-=res[r]*mt[i][r];
    }
    for(c--;c>=0;c--){
	res[r]=mt[c][m]/mt[c][r];
	for(int i=0;i<c;i++) mt[i][m]-=res[r]*mt[i][r];
	for(r--;res[r];r--) res[r]=0;
    }
    return ans;
}
16//二进制
bool mt[M][M],res[M]; //n*m 增广矩阵,res 为一组可行解
int gauss(int n,int m){ //返回-1 表示无解,否则返回自由变元个数
    int r,c=0,ans=0;
    --m;
    memset(res,0,sizeof res);
    for(int k=0;k<m;k++){
	for(r=c;r<n;r++)if(mt[r][k])break;
	if(r==n){ans++; res[k]=1; continue; }
	if(r!=c){
	    memcpy(mt[n],mt[r],sizeof res);
	    memcpy(mt[r],mt[c],sizeof res);
	    memcpy(mt[c],mt[n],sizeof res);
	}
	for(int i=c+1;i<n;i++)if(mt[i][k]){
	    for(int j=k;j<=m;j++)
		mt[i][j]^=mt[c][j];
	}
	c++;
    }
    for(int i=c;i<n;i++)if(mt[i][m])return -1;
    //一组可行解
    for(r=m-1;res[r];r--){
	res[r]=0;
	//自由变元的取值默认值
	//for(int i=0;i<=c;i++)if(mt[i][r])mt[i][m]^=res[r];
    }
    for(c--;c>=0;c--){
	res[r]=mt[c][m];
	if(res[r]) for(int i=0;i<c;i++)if(mt[i][r])mt[i][m]^=res[r];
	for(r--;res[r];r--) res[r]=0;
    }
    //遍历所有解
    cnt=-1;
    dfs(c-1,m-1,0,m);
    memcpy(res,dres,sizeof res);
    return ans;
}
