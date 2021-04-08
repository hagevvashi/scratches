#include <stdio.h>

typedef struct {
  int s;
  int c;
} R;

R half_adder(int a,int b){
  R r;
  r.s=a^b;
  r.c=a&b;
  return r;
}

R full_adder(int a,int b,int x){
  R r1=half_adder(a,b);
  R r2=half_adder(r1.s,x);

  R r;
  r.s=r2.s;
  r.c=r1.c|r2.c;

  return r;
}

char*solve(int n,char*a,char*b,char*s){
  R r[n];

  int ia[n];
  int ib[n];
  for(int i=0;i<n;i+=1){
    ia[i]=a[i]-'0';
    ib[i]=b[i]-'0';
  }

  for(int i=1;i<=n;i+=1){
    int j=i-1;
    if(i==1){
      r[n-i]=half_adder(ia[n-i],ib[n-i]);
    }else{
      r[n-i]=full_adder(ia[n-i],ib[n-i],r[n-j].c);
    }
    s[n-j]=r[n-i].s+'0';
  }
  s[0]=r[0].c+'0';
  s[n+1]='\0';

  return s;
}

int main(){
  int n;
  scanf("%d",&n);

  char a[n+1],b[n+1],s[n+2];
  scanf("%s%s",a,b);

  puts(solve(n,a,b,s));

  return 0;
}
