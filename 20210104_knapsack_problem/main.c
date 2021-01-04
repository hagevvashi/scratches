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

int dp[110][10010];

int main() {
  int n,max_w;
  scanf("%d%d",&n,&max_w);
  int value[n],weight[n];
  rep(i,n){
    scanf("%d%d",value+i,weight+i);
  }
  rep(w,max_w+1){
    dp[0][w]=0;
  }
  rep(i,n)rep(w,max_w+1){
    int total_weight=w-weight[i];
    dp[i+1][w]=total_weight>=0?max(dp[i][total_weight]+value[i],dp[i][w]):dp[i][w];
  }
  printf("%d\n",dp[n][max_w]);
  return 0;
}
