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

ll gcd(ll a,ll b){
  if(b==0)return a;
  return gcd(b,a%b);
}

int main() {
  int n;
  ll X;
  scanf("%d%lld",&n,&X);
  ll x[n];
  rep(i,n)scanf("%lld",x+i);
  ll d=0;
  rep(i,n){
    d=gcd(d,labs(X-x[i]));
  }
  printf("%lld\n",d);
  return 0;
}
