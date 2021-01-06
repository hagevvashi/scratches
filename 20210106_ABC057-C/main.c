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
  ll y=x;
  int r=1;
  while(1){
    if(y/10<1){
      break;
    }else{
      r+=1;
      y-=(y%10);
      y/=10;
    }
  }
  return r;
}

int f(ll a,ll b){
  return max(digits(a),digits(b));
}

int solve(ll x){
  int r=1000000000;
  r=min(f(1,x),r);
  for(ll i=2;i*i<=x;i+=1){
    if(x%i==0){
      r=min(f(i,x/i),r);
    }
  }
  return r;
}

int main() {
  ll n;
  scanf("%lld",&n);
  printf("%d\n",solve(n));
  return 0;
}
