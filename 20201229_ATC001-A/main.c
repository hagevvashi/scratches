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

int height,width;
char c[510][510];
int visited[510][510];

void search(int h,int w){
  if(h<0)return;
  if(w<0)return;
  if(h>=height)return;
  if(w>=width)return;
  if(c[h][w]=='#')return;
  if(visited[h][w]==1)return;
  visited[h][w]=1;
  if(c[h][w]=='g')return;
  search(h-1,w);
  search(h,w+1);
  search(h+1,w);
  search(h,w-1);
}

int main() {
  int start_h,start_w,goal_h,goal_w;
  scanf("%d%d",&height,&width);
  rep(h,height){
    scanf("%s",c[h]);
    rep(w,width){
      visited[h][w]=0;
      if(c[h][w]=='s'){
        start_h=h;
        start_w=w;
      }
      if(c[h][w]=='g'){
        goal_h=h;
        goal_w=w;
      }
    }
  }
  search(start_h,start_w);
  if(visited[goal_h][goal_w]==1){
    puts("Yes");
  }else{
    puts("No");
  }
  return 0;
}
