#include <algorithm>
#include <vector>
#include <iostream>
#include <limits>


void reconstruccion(std::vector<int>&M){
  int n = M.size();
  for( int i = n ; i>=0 ; i-- ){
    if(i>=n){
      continue;
    }else {
      
    }

  }



}
int MCS_BU(std::vector<int>&E){
 int n = E.size();
  std::vector<int>M( n+1 , std::numeric_limits<int>::min() );
  for(int i = n+1 ;i>=0;i--){
    if(i>=n){
      M[i]=0;
    }else if (i==n-1) {
      M[i]=E[i];
    }else {
      M[i]= std::max(E[i] + M[i+2] , M[i+1]);
    }

  } 
  for (auto elem :M){
    std::cout << elem << " ";
  }
  std::cout <<"\n";

  return M[0];
}

int main (int argc, char *argv[]) {
  std::vector<int> input = {22,5,7,21,3,6};
  std::cout<<  "respuesta:  " << MCS_BU(input)<<"\n";
  return 0;
}
