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
  int N,W;
  scanf("%d%d",&N,&W);
  int weight[N],value[N];
  rep(i,N)scanf("%d%d",value+i,weight+i);
  rep(w,W+1)dp[0][w]=0;
  rep(i,N)rep(w,W+1){
    int total_weight_up_to_the_last_time = w-weight[i];
    if(total_weight_up_to_the_last_time>=0)dp[i+1][w]=max(dp[i][total_weight_up_to_the_last_time]+value[i],dp[i][w]);
    else dp[i+1][w]=dp[i][w];
  }
  printf("%d\n",dp[N][W]);
  return 0;
}
