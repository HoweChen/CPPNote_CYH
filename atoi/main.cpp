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
    2. change string to int by using atoi
       convert std::string to const char* by using string.c_str();
   */
  string test = "000";
  int intTest = std::atoi(test.c_str());
  int result = intTest + 1;
  std::cout << result << std::endl;


}
