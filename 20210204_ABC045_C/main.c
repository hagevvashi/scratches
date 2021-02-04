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

int to_int(const char c){
  return c-'0';
}

int stl(const char*s){
  int l=0;
  while(s[l]!='\0')l+=1;
  return l;
}

int main() {
  char s[11];
  scanf("%s",s);
  int l=stl(s);
  ll ans=0;
  rep(bit,1<<(l-1)){
    ll t=to_int(s[0]);
    rep(i,l-1){
      int j=to_int(s[i+1]);
      if((bit>>i)&1){
        ans+=t;
        t=j;
      }else{
        t*=10;
        t+=j;
      }
    }
    ans+=t;
  }
  printf("%lld\n",ans);
  return 0;
}
