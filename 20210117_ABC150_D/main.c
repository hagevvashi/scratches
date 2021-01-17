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

ll gcd(x,y){
  // if(y==0)return y;
  // return gcd(y,x%y);
  ll r=x%y;
  while(r>0){
    x=y;
    y=r;
    r=x%y;
  }
  return y;
}

ll lcm(x,y){
  return x/gcd(x,y)*y;
}

ll solve(int n,ll m,ll*a){
  ll l=a[0];
  rep(i,n)l=lcm(l,a[i]);
  rep(i,n){
    if(l/a[i]%2==0)return 0;
  }
  return (m/l+1)/2;
}

int main() {
  int n;
  ll m;
  scanf("%d%lld",&n,&m);
  ll a[n];
  rep(i,n){
    scanf("%lld",a+i);
    a[i]/=2;
  }
  printf("%lld\n",solve(n,m,a));
  return 0;
}
