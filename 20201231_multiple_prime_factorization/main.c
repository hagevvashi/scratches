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
  ll prime_number;
  ll exponent;
} Factor;

typedef struct {
  Factor * factors;
  int factors_count;
} Factors;

void increment_exponent(int i,Factors* factors_list){
  factors_list->factors[i].exponent+=1;
}

void add_factor(ll x,Factors* factors_list){
  factors_list->factors[factors_list->factors_count].prime_number=x;
  increment_exponent(factors_list->factors_count,factors_list);
  factors_list->factors_count+=1;
}

void add_or_increment(ll x,Factors * factors_list){
  rep(i,factors_list->factors_count){
    if(factors_list->factors[i].prime_number==x){
      return increment_exponent(i,factors_list);
    }
  }
  add_factor(x,factors_list);
}

void find_smallest_prime_factor(ll x,Factors* factors_list){
  if(x==1)return;
  for(ll i=2;i*i<=x;i+=1){
    if(x%i==0){
      add_or_increment(i,factors_list);
      return find_smallest_prime_factor(x/i,factors_list);
    }
  }
  add_or_increment(x,factors_list);
}

Factors* find_prime_factors(ll x){
  Factors*factors_list=(Factors*)malloc(sizeof(Factors));
  factors_list->factors=(Factor*)malloc(10010*sizeof(Factor));
  factors_list->factors_count=0;
  find_smallest_prime_factor(x,factors_list);
  return factors_list;
}

void debug(Factors* factors_list){
  rep(i,factors_list->factors_count){
    printf("%lld to the power %lld\n",factors_list->factors[i].prime_number,factors_list->factors[i].exponent);
  }
}

ll mypow(ll base,int exponent){
  ll r=1;
  if(exponent==0)return r;
  rep(i,exponent)r*=base;
  return r;
}

int main() {
  ll n,m;
  scanf("%lld%lld",&n,&m);
  Factors*factors_list_n=find_prime_factors(n);
  Factors*factors_list_m=find_prime_factors(m);
  // debug(factors_list_n);
  // debug(factors_list_m);

  free(factors_list_n);
  free(factors_list_m);
  return 0;
}
