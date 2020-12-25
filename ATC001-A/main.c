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

char c[510][510];
int reached[510][510];
int H,W;

void search(int h, int w) {
  /* printf("h: %d,",h); */
  /* printf("w: %d\n",w); */
  if(h<0)return;
  if(w<0)return;
  if(h>=H)return;
  if(w>=W)return;
  if(c[h][w]=='#')return;

  if(reached[h][w]==1)return;

  reached[h][w]=1;
  search(h-1,w);
  search(h,w+1);
  search(h+1,w);
  search(h,w-1);
  return;
}

int main() {
  scanf("%d%d",&H,&W);
  int sh,sw,gh,gw;
  rep(h,H){
    scanf("%s",c[h]);
    rep(w,W){
      reached[h][w]=0;
      if(c[h][w]=='s'){
        sh=h;
        sw=w;
      }
      if(c[h][w]=='g'){
        gh=h;
        gw=w;
      }
    }
  }
  search(sh,sw);
  if(reached[gh][gw]==1)puts("Yes");
  else puts("No");
  return 0;
}
