const int MAX_NODE = 10005*50, CHILD_NUM = 26;
const int MAX_LEN = 1000005;

int ch[MAX_NODE][CHILD_NUM], sz;// Tire
int val[MAX_NODE], fail[MAX_NODE];//节点的val和失败指针

int idx(char c){
    return c-'a';
}

void Init(){
    memset(ch[0], 0, sizeof(ch[0]));
    sz = 1;
}

//插入
void Insert(char *s, int key){
    int u = 0;
    for(; *s; s++){
	int c = idx(*s);
	if(!ch[u][c]){
	    memset(ch[sz], 0, sizeof(ch[sz]));
	    val[sz] = 0;
	    ch[u][c] = sz++;
	}
	u = ch[u][c];
    }
    val[u] += key;
}

//Build AC_auto
void AC_Construct(){
    queue<int> q;
    for(int i=0; i<CHILD_NUM; i++){
	if(ch[0][i]){
	    fail[ch[0][i]] = 0;
	    q.push(ch[0][i]);
	}
    }
    while(!q.empty()){
	int u = q.front(); q.pop();
	for(int i=0; i<CHILD_NUM; i++){
	    int &v = ch[u][i];
	    if(v){
		fail[v] = ch[fail[u]][i];
		q.push(v);
		//下列代码根据实际情况写
		//
	    }
	    else{
		v = ch[fail[u]][i];
	    }
	}
    } 
}
