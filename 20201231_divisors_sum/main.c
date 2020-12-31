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

Factor factors[10010]={{0,0}};
int factors_count=0;

void increment_exponent(int i){
  factors[i].exponent+=1;
}

void add_factor(int x){
  factors[factors_count].prime_number=x;
  increment_exponent(factors_count);
  factors_count+=1;
}

void add_or_increment(int x){
  rep(i,factors_count){
    if(factors[i].prime_number==x){
      return increment_exponent(i);
    }
  }
  add_factor(x);
}

void find_smallest_prime_factor(int x){
  for(int i=2;i*i<=x;i+=1){
    if(x%i==0){
      add_or_increment(i);
      return find_smallest_prime_factor(x/i);
    }
  }
  add_or_increment(x);
}

void find_prime_factors(int x){
  find_smallest_prime_factor(x);
}

ll mypow(int base, int exponent){
  if(exponent==0)return 1;
  ll r=1;
  rep(i,exponent)r*=base;
  return r;
}

ll calculate_sum_of_divisor(int i){
  ll r=0;
  rep(j,factors[i].exponent+1)r+=mypow(factors[i].prime_number,j);
  return r;
}

ll find_sum_of_divisors(){
  ll r=1;
  rep(i,factors_count)r*=calculate_sum_of_divisor(i);
  return r;
}

void debug(){
  rep(i,factors_count){
    printf("%d to the power %lld\n",factors[i].prime_number,factors[i].exponent);
  }
}

/**
 * Find the sum of divisors
 *
 * INPUT: n(n>=1,n<1000000000)
 * OUTPUT: sum of divisors of n
 *
 * e.g.
 * * INPUT
 * ```
 * 12
 * ```
 * * OUTPUT
 * ```
 * 28
 * ```
 */
int main() {
  int n;
  scanf("%d",&n);
  find_prime_factors(n);
  // debug();
  printf("%lld\n",find_sum_of_divisors());
  return 0;
}
