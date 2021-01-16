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

void reverse(int*a,int n){
  int l=0;
  int r=n-1;
  while(l<r){
    swap(a[l],a[r]);
    l+=1;
    r-=1;
  }
}

int next_permutation(int*p,int n){
  int ret=0;

  int r=n-1;
  int l=r-1;
  for(;l>=-1;l-=1){
    if(p[l]<p[l+1])break;
  }
  if(l>=0){
    ret=1;
    for(;r>l;r-=1){
      if(p[l]<p[r])break;
    }
    swap(p[l],p[r]);
  }
  reverse(p+(l+1),n-(l+1));
  return ret;
}

int main() {
  // input
  int n,k;
  scanf("%d%d",&n,&k);
  int t[n][n];
  rep(i,n)rep(j,n)scanf("%d",t[i]+j);

  // init
  int a[n];
  rep(i,n)a[i]=i;

  int c=0;
  do{
    int tot=0;
    rep(i,n){
      int x=a[i];
      int y=a[(i+1)%n];
      tot+=t[x][y];
    }
    if(tot==k)c+=1;
  }while(next_permutation(a+1,n-1));

  printf("%d\n",c);
  return 0;
}
