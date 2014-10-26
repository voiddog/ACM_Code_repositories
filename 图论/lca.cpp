void dfs(int v, int p, int d){
    //Dfs
    /*parent[0][v] = p;
    depth[v] = d;
    for (int i = 0; i < G[v].size(); i++){
        if (G[v][i].v != p) dfs(G[v][i].v, v, d + 1);
    }*/
    //Bfs
    queue<edge> q;
    edge s;
    s.v = v;
    s.w = d;
    s.id = p;
    q.push(s);
    while (!q.empty()){
        s = q.front(); q.pop();
        parent[0][s.v] = s.id;
        depth[s.v] = s.w;
        for (int i = 0; i < G[s.v].size(); i++){
            if (G[s.v][i].v != s.id){
                edge t;
                t.v = G[s.v][i].v;
                t.w = s.w + 1;
                t.id = s.v;
                q.push(t);
            }
        }
    }
}

//parent[k][i] i 的 2^k 个父亲
void init(int V){
    dfs(root, -1, 0);
    for (int k = 0; k + 1 < MAX_LOG_V; k++){
        for (int v = 0; v <= V; v++){
            if (parent[k][v] < 0) parent[k + 1][v] = -1;
            else parent[k + 1][v] = parent[k][parent[k][v]];
        }
    }
}

int lca(int u, int v){
    if (depth[u] > depth[v]) swap(u, v);
    for (int k = 0; k < MAX_LOG_V; k++){
        if ((depth[v] - depth[u]) >> k & 1){
            v = parent[k][v];
        }
    }
    if (u == v) return u;

    for (int k = MAX_LOG_V - 1; k >= 0; k--){
        if (parent[k][u] != parent[k][v]){
            u = parent[k][u];
            v = parent[k][v];
        }
    }

    return parent[0][u];
}
