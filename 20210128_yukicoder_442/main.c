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
  // [1]if gcd(12,25)==1 then gcd(12+25,12*25)==1
  // why gcd(12+25,12*25)==1
  // why gcd(37,300)==1
  // gcd(12+25,12)==gcd(25,12)==gcd(13,12)==gcd(1,12)==1
  // gcd(12+25,25)==gcd(12,25)==gcd(12,13)==gcd(12,1)==1
  // if gcd(37,12)==1 && gcd(37,25)==1 then gcd(37,12*25)==1
  // if gcd(37,2*2*3)==1 && gcd(37,5*5)==1 then gcd(37,2*2*3*5*5)==1
  // [2]if gcd(12,25)==1 then gcd(12,25*3)==gcd(12*3)==3
  // if gcd(12,25)==1 then gcd(12,25*24)==gcd(12*24)==12
  // gcd(a+b,a*b)==gcd(g*(x+y),g*g*(x*y))==g*gcd(x+y,g*(x*y))==g*gcd(x+y,g)
  ll ans=g*gcd(x+y,g);
  printf("%lld\n",ans);
  return 0;
}
