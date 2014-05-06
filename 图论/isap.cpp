#include<iostream>
#include<cstdlib>
#include<cstring>
using namespace std;
const int MAX_N = 40010;
const int MAX_M = 999999;
struct eage{
    int v, w, next;
}road[MAX_M];
int NE, NV; //sap，init中的memset用到了NV，如果不能事先确定大小，最好改成初始化整个数组
int head[MAX_N], lp;
int gap[MAX_N], dis[MAX_N], pre[MAX_N], cur[MAX_N];
void Init(){
    memset(head, -1, sizeof(int)*(NV+1));
    lp = 0;
}
void Add_Road(int s,int e,int len){
    road[lp].v = e;
    road[lp].w = len;
    road[lp].next = head[s];
    head[s] = lp++;
    road[lp].v = s;
    road[lp].w = 0;
    road[lp].next = head[e];
    head[e] = lp++;
}
int sap(int s,int t){
    memset(dis, 0, sizeof(int)*(NV + 1));
    memset(gap, 0, sizeof(int)*(NV + 1));
    for(int i=0; i<=NV; i++) cur[i] = head[i];
    int u = pre[s] = s, maxflow = 0, aug = -1;
    gap[0] = NV;
    while(dis[s] < NV){
loop:   for(int &i = cur[u]; ~i; i = road[i].next){
            eage &e = road[i];
            int v = e.v;
            if(e.w && dis[u] == dis[v] + 1){
                if(aug==-1) aug = e.w;
                else aug = min(aug, e.w);
                pre[v] = u;
                u = v;
                if(v == t){
                    maxflow += aug;
                    for(u = pre[u]; v != s; v = u, u = pre[u]){
                        road[cur[u]].w -= aug;
                        road[cur[u]^1].w += aug;
                    }
                    aug = -1;
                }
                goto loop;
            }
        }
        int mindis = NV;
        for(int i = head[u]; ~i; i = road[i].next){
            int v = road[i].v;
            eage &e = road[i];
            if(e.w && mindis > dis[v]){
                cur[u] = i;
                mindis = dis[v];
            }
        }
        if((--gap[dis[u]])==0) break;
        gap[dis[u] = mindis + 1]++;
        u = pre[u];
    }
    return maxflow;
}
int main(){
    cout<<"hehe"<< endl;
    return 0;
}
