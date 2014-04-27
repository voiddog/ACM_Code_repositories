#include<iostream>
#include<cstdlib>
#include<cstring>
#include<queue>
using namespace std;
const int INF = 1<<30;
const int MAX_N = 10005;
const int MAX_M = 1000005;
struct eage{
    int v, next, w;
};
eage road[MAX_M];
int head[MAX_N], lp;
int level[MAX_N];//顶点到源点的距离标号
int iter[MAX_N];//当前的弧
void Init(){
    memset(head, -1, sizeof(head));
    lp = 0;
}
void Add_Road(int s, int e, int len){
    road[lp].v = e;
    road[lp].next = head[s];
    road[lp].w = len;
    head[s] = lp++;
    road[lp].v = s;
    road[lp].next = head[e];
    road[lp].w = 0;
    head[e] = lp++;
}
void Bfs(int s){//Bfs计算距离标号
    memset(level, -1, sizeof(level));
    queue<int> que;
    level[s] = 0;
    que.push(s);
    while(!que.empty()){
        int u = que.front(); que.pop();
        for(int i=head[u]; ~i; i=road[i].next){
            eage &e = road[i];
            if(e.w > 0 && level[e.v] < 0){
                level[e.v] = level[u] + 1;
                que.push(e.v);
            }
        }
    }
}
int dfs(int u, int t, int f){//从dfs寻找增广路
    if(u == t) return f;
    for(int &i = ((iter[u] == -1)?(iter[u] = head[u]):iter[u]); ~i; i = road[i].next){
        eage &e = road[i];
        if(e.w > 0 && level[u] < level[e.v]){
            int d = dfs(e.v, t, min(f, e.w));
            if(d>0){
                e.w -= d;
                road[i^1].w += d;//反向边
                return d;
            }
        }
    }
    return 0;
}
int max_flow(int s,int t){
    int flow = 0;
    while(true){
        Bfs(s);
        if(level[t] < 0) return flow;
        memset(iter, -1, sizeof(iter));
        int f;
        while((f = dfs(s, t, INF)) > 0){
            flow += f;
        }
    }
}
int main(){
    cout<<"hehe"<<endl;
    return 0;
}
