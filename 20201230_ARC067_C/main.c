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
#define MOD 1000000007LL

typedef struct {
  int prime_number;
  ll exponent;
} Factor;

Factor factors[10010]={{0,0}};
int factors_count=0;

void increment_exponent(int i){
  factors[i].exponent+=1;
}

void add_prime_factor(int x){
  factors[factors_count].prime_number=x;
  increment_exponent(factors_count);
  factors_count+=1;
}

void add_or_increment(int x){
  for(int i=factors_count-1;i>=0;i-=1){
    if(factors[i].prime_number==x){
      return increment_exponent(i);
    }
  }
  add_prime_factor(x);
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

ll calculate_divisor_count(){
  ll ans=1;
  lrep(i,factors_count){
    ans*=(factors[i].exponent+1);
    ans%=MOD;
  }
  return ans;
}

ll solve(int n){
  // find_prime_factors(n);
  for(int i=2;i<=n;i+=1){
    find_prime_factors(i);
  }
  return calculate_divisor_count();
}

void debug(){
  rep(i,factors_count){
    printf("%d to the power %lld\n",factors[i].prime_number,factors[i].exponent);
  }
}

int main() {
  int n;
  scanf("%d",&n);
  printf("%lld\n",solve(n));
  // debug();
  return 0;
}
