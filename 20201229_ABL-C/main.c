#include <stdio.h>
#include <stdlib.h>

#define ll long long
#define INF ((1LL << 62) - (1LL << 31))
#define rep(i, n) for (int i = 0; i < n; i = i + 1)
#define lrep(i, n) for (ll i = 0; i < n; i = i + 1)
#define array(N, t) (t*)calloc(N, sizeof(t))
#define max(p, q)((p) > (q) ? (p) : (q))
#define min(p, q)((p) < (q) ? (p) : (q))
#define swap(a, b) { int temp = a; a = b; b = temp; }
#define lswap(a, b) { ll temp = a; a = b; b = temp; }

int n;
int * data;

void init() {
  // child: parent's index
  // root: -size
  data = array(n, int);

  rep(i, n) {
    // at first, all data is root and size is -1
    data[i] = -1;
  }
}

int find(int x) {
  if (data[x] < 0) {
    return x;
  }

  return data[x] = find(data[x]);
}

int same(int x, int y) {
  return find(x) == find(y);
}

int unite(int x, int y) {
  x = find(x);
  y = find(y);
  if (x == y) {
    return 0;
  }
  // becasue data has minus size, reverse the inequality sign
  if (data[x] > data[y]) {
    swap(x, y);
  }
  data[x] += data[y];
  data[y] = x;
  return 1;
}

int size(int x) {
  return -data[find(x)];
}

int count() {
  int cnt = 0;
  rep(i, n) {
    if (find(i) == i) {
      cnt += 1;
    }
  }
  return cnt;
}

int main() {
  int m;
  scanf("%d%d",&n,&m);

  init();

  rep(i,m){
    int a,b;
    scanf("%d%d",&a,&b);
    a-=1;
    b-=1;
    unite(a,b);
  }

  printf("%d\n",count()-1);
  free(data);
  return 0;
}
