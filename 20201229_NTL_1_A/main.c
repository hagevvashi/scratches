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

int n;

typedef struct _Prime {
  int body;
  int shisu;
} Prime;

Prime prime_list[1010]={{0,0}};
int cnt=0;

void g(int x){
  if(cnt==0){
    prime_list[cnt].body=x;
    prime_list[cnt].shisu+=1;
    cnt+=1;
  }else{
    if(prime_list[cnt-1].body==x){
      prime_list[cnt-1].shisu+=1;
    }else{
      prime_list[cnt].body=x;
      prime_list[cnt].shisu+=1;
      cnt+=1;
    }
  }
}

void f(int x){
  for(int i=2;i*i<=x;i+=1){
    if(x%i==0){
      g(i);
      return f(x/i);
    }
  }
  g(x);
}

void print(){
  printf("%d:",n);
  rep(i,cnt){
    rep(j,prime_list[i].shisu){
      printf(" %d",prime_list[i].body);
    }
  }
  puts("");
}

int main() {
  scanf("%d",&n);
  f(n);

  /* printf("cnt: %d\n",cnt); */
  /* rep(i,cnt){ */
  /*   printf("prime_list[i].body: %d\n",prime_list[i].body); */
  /*   printf("prime_list[i].shisu: %d\n",prime_list[i].shisu); */
  /* } */

  print();
  return 0;
}
