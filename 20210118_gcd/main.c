#include <stdio.h>

long long gcd(long long a, long long b){
  if(b==0)return a;
  return gcd(b,a%b);
}

int main(){
  int n;
  scanf("%d",&n);

  long long x[n];
  for(int i=0;i<n;i+=1){
    scanf("%lld",x+i);
  }

  long long ans=0;
  for(int i=0;i<n;i+=1){
    ans=gcd(ans,x[i]);
  }

  printf("%lld\n",ans);

  return 0;
}
