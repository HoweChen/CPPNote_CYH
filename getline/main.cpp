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
    1. usage of getline;
   */
  string item;
  int count = 0;
  getline(std::cin, item, ':');
  while (cin) {
    /* code */

    ++count;
    cout << count << ":" << item << endl;
    getline(cin, item, ':');

  }
  return 0;
}
