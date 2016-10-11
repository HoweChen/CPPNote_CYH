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

  /*
    4. test const char[]
   */
  const char test[] = "test";
  cout << test << endl;
  // test[0] = 'f'; //you cannot do that because the array is read-only due to the const

  return 0;
}
