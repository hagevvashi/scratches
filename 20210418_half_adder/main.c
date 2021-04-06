#include <stdio.h>

/**
 * a,b -> s,c
 * 0,0 -> 0,0
 * 0,1 -> 1,0
 * 1,0 -> 1,0
 * 1,1 -> 0,1
 */
int main(){
  int a,b;
  scanf("%d%d",&a,&b);

  int s=a^b;
  int c=a&b;

  printf("%d %d\n",s,c);

  return 0;
}
