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

int digits(ll x){
  int r=1;
  ll y=x/10;
  while(y>=1){
    r+=1;
    y/=10;
  }
  return r;
}

int f(ll a,ll b){
  return max(digits(a),digits(b));
}

int main() {
  ll n;
  scanf("%lld",&n);
  ll ans=INF;
  ans=min(ans,f(1,n));
  for(ll i=2;i*i<=n;i+=1){
    if(n%i==0){
      ans=min(ans,f(i,n/i));
    }
  }
  printf("%lld\n",ans);
  return 0;
}
