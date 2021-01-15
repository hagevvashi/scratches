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

void reverse(int*p,int cnt){
  for(int i=0;(i+1)*2<=cnt;i+=1){
    swap(p[i],p[cnt-i]);
  }
}

int next_permutation(int*p,int cnt){
  int ret=0;
  int r=cnt-1;
  int l=r-1;
  for(;l>=0;l-=1){
    if(p[l]<p[l+1]){
      ret=1;
      break;
    }
  }
  for(;r>l;r-=1){
    if(p[r]>p[l]){
      break;
    }
  }
  swap(p[l],p[r]);
  reverse(p+l,cnt-l);
  return ret;
}

int main() {
  int n,k;
  scanf("%d%d",&n,&k);
  int t[n][n];
  rep(i,n)rep(j,n){
    scanf("%d",t[i]+j);
  }

  int a[n-1];
  rep(i,n-1)a[i]=i+1;

  int count=0;

  do{
    int tot=0;
    tot+=t[0][a[0]];
    rep(i,n-2)tot+=t[a[i]][a[i+1]];
    tot+=t[a[n-2]][0];
    if(tot==k)count+=1;
  }while(next_permutation(a,n-1));

  printf("%d\n",count);
  return 0;
}
