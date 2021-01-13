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
  int exponent;
} Factor;

typedef struct {
  Factor list[10010];
  int count;
} Factors;

void increment_exponent(int i,Factors*factors){
  factors->list[i].exponent+=1;
}

void add_factor(ll x,Factors*factors){
  factors->list[factors->count].prime_number=x;
  factors->list[factors->count].exponent=0;
  increment_exponent(factors->count,factors);
  factors->count+=1;
}

void add_or_increment(ll x,Factors*factors){
  rep(i,factors->count){
    if(factors->list[i].prime_number==x){
      return increment_exponent(i,factors);
    }
  }
  add_factor(x,factors);
}

void find_smallest_prime_factor(ll x,Factors*factors){
  if(x<=1){
    return;
  }
  for(ll i=2;i*i<=x;i+=1){
    if(x%i==0){
      add_or_increment(i,factors);
      return find_smallest_prime_factor(x/i,factors);
    }
  }
  add_or_increment(x,factors);
}

Factors*find_prime_factors(ll x){
  Factors*factors=malloc(sizeof(Factors));
  factors->count=0;
  find_smallest_prime_factor(x,factors);
  return factors;
}

void debug(Factors*factors){
  rep(i,factors->count){
    Factor factor=factors->list[i];
    printf("%lld to the power %d\n",factor.prime_number,factor.exponent);
  }
}

ll mypow(ll base,int exponent){
  ll r=1;
  if(exponent==0)return r;
  rep(i,exponent)r*=base;
  return r;
}

ll gcd(ll a,ll b){
  Factors*factors_a=find_prime_factors(a);
  Factors*factors_b=find_prime_factors(b);
  // debug(factors_a);
  // debug(factors_b);

  ll r=1;
  rep(i,factors_a->count){
    Factor factor_a=factors_a->list[i];
    rep(j,factors_b->count){
      Factor factor_b=factors_b->list[j];
      if(factor_a.prime_number!=factor_b.prime_number){
        continue;
      }else{
        ll p=factor_a.prime_number;
        r*=mypow(p,min(factor_a.exponent,factor_b.exponent));
      }
    }
  }

  free(factors_a);
  free(factors_b);
  return r;
}

int main() {
  ll a,b;
  scanf("%lld%lld",&a,&b);

  ll g=gcd(a,b);
  Factors*factors=find_prime_factors(g);
  // debug(factors);

  printf("%d\n",factors->count+1);

  free(factors);
  return 0;
}
