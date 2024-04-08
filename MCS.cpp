#include <algorithm>
#include <vector>
#include <iostream>
#include <limits>

int MCS_MEM( std::vector<int>&E,int i,int n,std::vector<int>&M){
  if(M[i] == std::numeric_limits<int>::min()){
    if(i>=n){
      M[n+1]=0;
    }
    else if (i==n-1) {
      M[i]=E[i]; 
    }
    else {
      M[i] = std::max(E[i]+MCS_MEM(E, i+2, n, M),  MCS_MEM(E, i+1, n, M));
    }

  }
  return M[i];
}

int MCS( std::vector<int>&E){
 
  std::vector<int>M(E.size()+1,std::numeric_limits<int>::min());
  return MCS_MEM(E, 0, E.size(), M);

}

// int main (int argc, char *argv[]) {
//   std::vector<int> input = {22,5,7,21,3,6};
//   std::cout<<  "respuesta:  " << MCS(input)<<"\n";
//   return 0;
// }
