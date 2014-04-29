const int MAX_N = 10005;
int Set[MAX_N];
void Init(int N){
    memset(Set, -1, sizeof(int)*(N+1));
}
int Find(int x){
    if(Set[x] < 0) return x;
    int r = x;
    while(Set[r] > 0) r = Set[r];
    int tmp;
    while(x!=r){
        tmp = Set[x];
        Set[x] = r;
        x = tmp;
    }
    return r;
}
bool Union(int a,int b){
    a = Find(a);
    b = Find(b);
    if(a == b){
        return false;
    }
    if(Set[a] == Set[b]){
        Set[b] = a;
        Set[a]--;
    }
    else if(Set[a] < Set[b]){
        Set[b] = a;
    }
    else{
        Set[a] = b;
    }
    return true;
}
