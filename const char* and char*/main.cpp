#include <cstring>
#include <iostream>
#include <queue>
#include <stack>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::array;
using std::vector;

int main(int argc, char const *argv[]) {

  const char *test = "Test";
  // *test = "Fuck"; //cannot modify the read-only variable

  // char *testTwo = "TestTwo";
  // *testTwo = "Fuck"; //still cannot change the content, it was forbidden by
  // c++11

  cout << test << endl;
  // cout << *testTwo << endl;
}
