#include <vector>
#include <iostream>
#include <limits>

int MCS_MEM(std::vector<int>E,int i,int n,std::vector<int>M){

  return M[i];
}

int MCS(std::vector<int>E){
  std::cout << E.size()<<"\n";
  std::vector<int>M(E.size()+1,std::numeric_limits<int>::min());
  return MCS_MEM(E, 1, E.size(), M);

}

int main (int argc, char *argv[]) {
  MCS({22,5,7,21,3,6});
  return 0;
}
