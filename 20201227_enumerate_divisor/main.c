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

int cnt=0;
ll divisor[10010];

int c(const void * a, const void * b) {
  if(*(ll*)a-*(ll*)b > 0){
    return 1;
  }else{
    if(*(ll*)a-*(ll*)b == 0){
      return 0;
    } else {
      return -1;
    }
  }
}

int main() {
  ll n;
  scanf("%lld",&n);

  divisor[cnt]=1;
  cnt+=1;
  divisor[cnt]=n;
  cnt+=1;
  for(int i=2;i*i<=n;i+=1){
    if(n%i==0){
      divisor[cnt]=i;
      cnt+=1;
      if(n/i!=i){
        divisor[cnt]=n/i;
        cnt+=1;
      }
    }
  }
  qsort(divisor,cnt,sizeof(ll),c);
  rep(i,cnt){
    printf("%lld ",divisor[i]);
  }
  puts("");
  return 0;
}
