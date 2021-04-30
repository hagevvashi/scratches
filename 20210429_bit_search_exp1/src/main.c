#include <stdio.h>
#include <stdlib.h>

#define ll long long
#define INF 2147483647
#define LINF ((1LL << 62) - (1LL << 31))
#define rep(i, n) for (int i = 0; i < n; i = i + 1)
#define lrep(i, n) for (ll i = 0; i < n; i = i + 1)
#define array(N, t) (t*)calloc(N, sizeof(t))
#define max(p, q)((p) > (q) ? (p) : (q))
#define min(p, q)((p) < (q) ? (p) : (q))
#define swap(a, b) { int temp = a; a = b; b = temp; }
#define lswap(a, b) { ll temp = a; a = b; b = temp; }

typedef struct {
  int list[10010];
  int length;
} Set;

void insert(int v,Set*s){
  int d=0;
  // printf("s.length: %d\n",s->length);

  rep(i,s->length){
    // printf("i: %d\n",i);
    // printf("s.list[i]: %d\n",s->list[i]);
    if(s->list[i]==v){
      d=1;
      break;
    }
  }
  // printf("v: %d\n",v);
  // printf("d: %d\n",d);
  // puts("");
  if(d==0){
    // puts("d==0");
    s->list[s->length]=v;
    s->length+=1;
  }
}

/**
 * $N$個の整数$A_i$が与えられます。$N$個の整数から、$0$個以上を選び和をとった値は、何通り存在するでしょうか？
 */
int main() {
  int n;
  scanf("%d",&n);
  int a[n];
  rep(i,n)scanf("%d",a+i);
  Set s;
  s.length=0;
  rep(j,1<<n){
    int sum=0;
    rep(i,n){
      if((j>>i)&1)sum+=a[i];
    }
    insert(sum,&s);
    // printf("s.length: %d\n",s.length);
  }
  printf("%d\n",s.length);
  return 0;
}
