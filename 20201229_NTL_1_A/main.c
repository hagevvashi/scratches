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

int ans[100010]={0};
int cnt=0;

void f(int x){
  for(int i=2;i*i<=x;i+=1){
    if(x%i==0){
      ans[cnt]=i;
      cnt+=1;
      return f(x/i);
    }
  }
  ans[cnt]=x;
  cnt+=1;
}

int main() {
  int n;
  scanf("%d",&n);
  f(n);
  printf("%d:",n);
  rep(i,cnt)printf(" %d",ans[i]);
  puts("");
  return 0;
}
