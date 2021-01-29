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
  ll a,b;
  scanf("%lld%lld",&a,&b);
  ll g=gcd(a,b);
  ll x=a/g;
  ll y=b/g;
  // if gcd(x,y)==1 then gcd(x+y,y)==1 && gcd(x+y,x)
  // m=x+y
  // if gcd(m,y)==1 && gcd(m,x)==1 then gcd(m,x*y)==1
  // gcd(x+y,x*y)==1
  // if gcd(x,y)==1 then gcd(x,y*n)==gcd(x,n)
  // gcd(a+b,a*b)==gcd(g*(x+y),g*g*(x*y))==g*gcd(x+y,g*(x*y))==g*gcd(x+y,g)
  ll ans=g*gcd(x+y,g);
  printf("%lld\n",ans);
  return 0;
}
