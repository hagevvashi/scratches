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

int is_prime(int x){
  int r=1;
  if(x==1){
    r=0;
    return r;
  }
  for(int i=2;i*i<=x;i+=1){
    if(x%i==0){
      r=0;
      return r;
    }
  }
  return r;
}

int main() {
  int n;
  scanf("%d",&n);
  if(is_prime(n)==1){
    puts("Yes");
  } else {
    puts("No");
  }
  return 0;
}
