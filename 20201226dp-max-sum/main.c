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

int dp[10010]={0};

int main() {
  int n;
  scanf("%d",&n);
  int a[n];
  rep(i,n)scanf("%d",a+i);
  rep(i,n){
    dp[i+1]=max(dp[i],dp[i]+a[i]);
  }
  printf("%d\n",dp[n]);
  return 0;
}
