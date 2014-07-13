const int MAX_LEN = 200010;
int len, k;
int rank[MAX_LEN], tmp[MAX_LEN];

//比较(i, i+k) 和 (j, j+k)的大小
bool cmp(int i, int j){
    if(rank[i] != rank[j]) return rank[i] < rank[j];
    else{
	int ri = i + k <= len ? rank[i+k] : -1;
	int rj = j + k <= len ? rank[j+k] : -1;
	return ri < rj;
    }
}

//建立sa后缀数组
void Construct_sa(char *s, int *sa){
    len = strlen(s);
    for(int i=0; i<=len; i++){
	sa[i] = i;
	rank[i] = i < len ? s[i] : -1;
    }
    for(k=1; k<=len; k<<=1){
	sort(sa, sa+len+1, cmp);
	tmp[sa[0]] = 0;
	for(int i=1; i<=len; i++){
	    tmp[sa[i]] = tmp[sa[i-1]] + (cmp(sa[i-1], sa[i]) ? 1 : 0);
	}
	for(int i=0; i<=len; i++) rank[i] = tmp[i];
    }
}

//建立高度数组lcp
void Construct_lcp(char *s, int *sa, int *lcp){
    int h = 0;
    lcp[0] = 0;
    for(int i=0; i<len; i++){
	int j = sa[rank[i]-1];
	if(h>0) h--;
	for(; j+h<len && i+h<len; h++){
	    if(s[j+h] != s[i+h]) break;
	}
	lcp[rank[i]-1] = h;
    }
}
