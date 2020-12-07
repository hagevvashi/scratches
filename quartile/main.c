#include <stdio.h>
#include <stdlib.h>

int c(const void*a,const void*b){
  return (*(double*)a-*(double*)b);
}

int main(){
  int n;
  scanf("%d",&n);
  double a[n];
  for(int i=0;i<n;i+=1){
    scanf("%lf",a+i);
  }
  qsort(a,n,sizeof(double),c);
  /** start */
  /* for(int i=0;i<n;i+=1){ */
  /*   printf("%d ",a[i]); */
  /* } */
  /* puts(""); */
  /** end */
  double q1=0;
  double q2=0;
  double q3=0;
  if(n%2==0){
    // 偶数
    int y=(n/2);
    int x=y-1;
    q2=(double)(a[x]+a[y])/2;
    if(y%2==0){
      // 偶数
      int t=(y/2);
      int s=t-1;
      /* printf("s: %d\n",s); */
      /* printf("t: %d\n",t); */
      q1=(double)(a[s]+a[t])/2;
      int q=y+t;
      int p=q-1;
      /* printf("p: %d\n",p); */
      /* printf("q: %d\n",q); */
      q3=(double)(a[p]+a[q])/2;
    }else{
      // 奇数
      int p=(y-1)/2;
      int q=y+p;
      /* printf("p: %d\n",p); */
      /* printf("q: %d\n",q); */
      q1=a[p];
      q3=a[q];
    }
  }else{
    // 奇数
    int y=(n-1)/2;
    q2=a[y];
    if(y%2==0){
      // 偶数
      int t=(y/2);
      int s=t-1;
      /* printf("s: %d\n",s); */
      /* printf("t: %d\n",t); */
      q1=(double)(a[s]+a[t])/2;
      int p=y+t;
      int q=p+1;
      /* printf("p: %d\n",p); */
      /* printf("q: %d\n",q); */
      q3=(double)(a[p]+a[q])/2;
    }else{
      // 奇数
      int p=(y-1)/2;
      int q=y+1+p;
      /* printf("p: %d\n",p); */
      /* printf("q: %d\n",q); */
      q1=a[p];
      q3=a[q];
    }
  }
  printf("Q1: %lf\n",q1);
  printf("Q2: %lf\n",q2);
  printf("Q3: %lf\n",q3);
  return 0;
}
