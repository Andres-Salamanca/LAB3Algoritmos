#include <iostream>
#include <vector>

// Prototipos de las funciones definidas en MCS.cpp
int MCS_MEM(std::vector<int>& E, int i, int n, std::vector<int>& M);
int MCS(std::vector<int>& E);

// Prototipos de las funciones definidas en MCS_BU.cpp
void reconstruccion(std::vector<int>& M, std::vector<int>& E);
int MCS_BU(std::vector<int>& E);

void test_MCS_BU() {
  std::vector<int> input = {22, 5, 7, 21, 3, 6};
  int expected_output = 49;
  int result = MCS_BU(input);
  if (result == expected_output) {
    std::cout << "MCS_BU Test Passed" << std::endl;
  } else {
    std::cout << "MCS_BU Test Failed. Expected: " << expected_output << ", Got: " << result << std::endl;
  }
}

void test_MCS() {
  std::vector<int> input = {22, 5, 7, 21, 3, 6};
  int expected_output = 49;
  int result = MCS(input);
  if (result == expected_output) {
    std::cout << "MCS Test Passed" << std::endl;
  } else {
    std::cout << "MCS Test Failed. Expected: " << expected_output << ", Got: " << result << std::endl;
  }
}

int main() {
  std::cout << "Running Tests..." << std::endl;
  test_MCS_BU();
  test_MCS();
  return 0;
}
