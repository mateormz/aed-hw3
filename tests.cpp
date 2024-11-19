#include <iostream>
#include <vector>
#include "hw3.h"

int main() {
  // Test 1
  std::cout << "Running Test 1...\n";
  BST<int> t1;

  std::cout << "Expected size: 0\n";
  std::cout << "Actual size: " << t1.size() << "\n";
  std::cout << (t1.size() == 0 ? "PASS\n" : "FAIL\n");

  // Test 2
  std::cout << "\nRunning Test 2...\n";
  BST<int> t2;

  t2.insert(4);
  t2.insert(2);
  t2.insert(5);
  t2.insert(3);

  std::cout << "Expected size: 4\n";
  std::cout << "Actual size: " << t2.size() << "\n";
  std::cout << (t2.size() == 4 ? "PASS\n" : "FAIL\n");

  std::cout << "Expected isEmpty: false\n";
  std::cout << "Actual isEmpty: " << (t2.isEmpty() ? "true" : "false") << "\n";
  std::cout << (t2.isEmpty() == false ? "PASS\n" : "FAIL\n");

  std::cout << "Expected findMin: 2\n";
  std::cout << "Actual findMin: " << t2.findMin() << "\n";
  std::cout << (t2.findMin() == 2 ? "PASS\n" : "FAIL\n");

  std::cout << "Expected findMax: 5\n";
  std::cout << "Actual findMax: " << t2.findMax() << "\n";
  std::cout << (t2.findMax() == 5 ? "PASS\n" : "FAIL\n");

  return 0;
}