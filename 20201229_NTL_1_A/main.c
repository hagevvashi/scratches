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

typedef struct {
  int prime_number;
  ll exponent;
} Factor;

Factor factors[1010]={{0,0}};
int factor_count=0;

void increment_exponent(i){
  factors[i].exponent+=1;
}

void add_factor(x){
  factors[factor_count].prime_number=x;
  increment_exponent(factor_count);
  factor_count+=1;
}

void add_or_increment(int x){
  for(int i=factor_count-1;i>=0;i-=1){
    if(factors[i].prime_number==x){
      increment_exponent(i);
      return;
    }
  }
  add_factor(x);
}

void find_smallest_prime_number(int x){
  for(int i=2;i*i<=x;i+=1){
    if(x%i==0){
      add_or_increment(i);
      return find_smallest_prime_number(x/i);
    }
  }
  add_or_increment(x);
}

void find_prime_factors(int x){
  find_smallest_prime_number(x);
}

void print(int n){
  printf("%d:",n);
  rep(i,factor_count)lrep(j,factors[i].exponent){
    printf(" %d",factors[i].prime_number);
  }
  puts("");
}

int main() {
  int n;
  scanf("%d",&n);
  find_prime_factors(n);
  print(n);
  return 0;
}
