#include <stdio.h>

#define rep(i, n) for (int i = 0; i < n; i = i + 1)
#define swap(a, b, type) { type temp = a; a = b; b = temp; }

void reverse(int * a, int n) {
  int l = 0;
  int r = n - 1;
  while(l < r) {
    swap(a[l], a[r], int);
    l += 1;
    r -= 1;
  }
}

int next_permutation(int * p, int n) {
  int l = n - 2;
  int r = n - 1;
  int ret = 0;
  // while (--l >= 0 && a[l] >= a[l + 1]);
  while(l >= 0) {
    if (p[l] < p[l + 1]) {
      break;
    }
    l -= 1;
  }
  if (l >= 0) {
    ret = 1;
    while (l < r) {
      if (p[l] < p[r]) {
        break;
      }
      r -= 1;
    }
    swap(p[l], p[r], int);
  }
  reverse(p + (l + 1), n - (l + 1));
  return ret;
}

int main() {
  int n;
  scanf("%d", &n);
  int array[n];
  rep(i, n) {
    scanf("%d", array + i);
  }
  printf("n: %d\n", n);
  printf("start: ");
  rep(i, n) {
    printf("%d ", array[i]);
  }
  puts("");
  do {
    rep(i, n) {
      printf("%d ", array[i]);
    }
    puts("");
  } while(next_permutation(array, n));
  return 0;
}
