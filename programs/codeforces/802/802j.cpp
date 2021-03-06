#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

 #define rep(i, a, b) for (int i = a; i <= b; i++)
 #define dep(i, a, b) for (int i = a; i >= b; i--)
 #define fill(a, x) memset(a, x, sizeof(a))

 const int N = 100 + 5;

 int n, u, v, w, es;
 int pre[N];

 struct Edge { int to, pre, w; } e[N << 1];
 inline void ine(int u, int v, int w) {
 	int &i = ++es;
 	e[i].to = v; e[i].pre = pre[u]; e[i].w = w;
 	pre[u] = i;
 }
 inline void add_edge() {
 	scanf("%d%d%d", &u, &v, &w);
 	u++; v++;
 	ine(u, v, w); ine(v, u, w);
 }
 inline void init_graph() { es = 0; fill(pre, 0); }
 #define reg(i, x) for (int i = pre[x]; i; i = e[i].pre)

 inline int max(int x, int y) { return x >= y ? x : y; }
 inline int dfs(int x, int dad) {
 	int ret = 0;
 	reg(i, x) {
 		int y = e[i].to;
 		if (y == dad) continue;
 		ret = max(ret, dfs(y, x) + e[i].w);
 	}
 	return ret;
 }

int main()
{
	scanf("%d", &n);
	init_graph();
	rep(i, 1, n - 1) add_edge();

	printf("%d\n", dfs(1, 0));

	return 0;
}