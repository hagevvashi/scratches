#include <stdio.h>

typedef struct {
  int s;
  int c;
} response_half_adder;

response_half_adder half_adder(int a,int b){
  response_half_adder r;
  r.s=a^b;
  r.c=a&b;
  return r;
}

int main(){
  int a,b,x;
  scanf("%d%d%d",&a,&b,&x);

  response_half_adder r1=half_adder(a,b);
  response_half_adder r2=half_adder(r1.s,x);

  int s=r2.s;
  int c=r1.c|r2.c;

  printf("%d %d\n",s,c);

  return 0;
}
