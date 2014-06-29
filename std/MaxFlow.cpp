class MaxFlowAlgorithm {
	public:
	int g[MAX_M], nxt[MAX_M], c[MAX_N], h[MAX_N], flow[MAX_M], nm;
	int d[MAX_N], q[MAX_N];
	int S, T;
	
	void addedge(int x, int y, int w){
		g[nm] = y; nxt[nm] = c[x]; c[x] = nm; flow[nm] = w; nm++;
	}
	
	void add(int x, int y, int w){
		//printf("%d %d %d\n", x, y, w);
		addedge(x, y, w);
		addedge(y, x, 0);
	}
	
	bool bfs(){
		memset(d, -1, sizeof d);
		d[S] = 0;
		q[1] = S;
		for (int l = 1, r = 1; l <= r; ++l){
			int i = q[l];
			for (int k = c[i]; ~k; k = nxt[k]){
				int j = g[k];
				if (d[j] == -1 && flow[k]) d[q[++r] = j] = d[i] + 1;
			}
		}
		return d[T] != -1;
	}
	
	int dfs(int i, int now){
		int w = 0;
		if (i == T) return now;
		if (!now) return 0;
		for (int &k = c[i]; ~k; k = nxt[k]){
			int j = g[k];
			if (d[j] == d[i] + 1){
				int res;
				if (flow[k] && ((res = dfs(j, min(now - w, flow[k]))) > 0)){
					flow[k] -= res;
					flow[k ^ 1] += res;
					w += res;
					if (w == now) return w;
				}
			}
		}
		return w;
	}
	
	void init(int _S, int _T){
		memset(c, -1, sizeof c);
		nm = 0;
		S = _S; T = _T;
	}
	
	int MaxFlow(){
		int ans = 0;
		memcpy(h, c, sizeof h);
		while (bfs()){
			ans += dfs(S, INF);
			//printf("%d\n", ans);
			memcpy(c, h, sizeof c);
		}
		return ans;
	}
};