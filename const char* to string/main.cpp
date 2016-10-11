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
    3. convert const char* to string
   */
  string temp = "Hello Fucker";
  //cannot delete the const because it's limited due to the c++11 standard
  const char *test = temp.c_str();

  string result = test;
  // test[0] = 'f'; //cannot modify the value because it's read-only due to the const keyword;
  test = "new";
  cout << result << endl;
  cout << test << endl;
  std::cout << strlen(test) << std::endl;

  return 0;
  
}
