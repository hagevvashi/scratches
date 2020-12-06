#include <iostream>
#include <algorithm>

int main() {
  int n;
  std::cin>>n;
  int array[n];
  for(int i=0;i<n;i+=1){
    std::cin>>array[i];
  }
  std::cout<<"n: "<<n<<std::endl;
  std::cout<<"start: ";
  do {
    for (int i = 0; i < n; i++) {
      std::cout<<array[i];
      if (i != n - 1) std::cout<<" ";
    }
    std::cout<<std::endl;
  } while(std::next_permutation(array, array + n));
  std::cout<<std::endl;
  return 0;
}
