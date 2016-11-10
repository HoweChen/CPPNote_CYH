#include <iostream>
#include <map>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

int main(int argc, char const *argv[]) {
  /* code */
  map<int, std::string> test = {{6, "f"}, {5, "e"}, {4, "d"},
                                {3, "c"}, {2, "b"}, {1, "a"}};

  for (auto itr : test) {
    // itr is not map<int, std::string>iterator, should change to i
    // if the arugment of test is a class, then auto would let itr(will be
    // changed to i)
    // be the specific class of that argument, so it would show the exact value
    // of that
    // class i
    cout << itr.first << endl;
    itr.second = "Fuck";
  }

  for (auto i : test) {
    cout << i.second << endl;
  }

  for (auto &i : test) {
    cout << i.first << endl;
    i.second = "Fuck";
  }

  for (auto i : test) {
    cout << i.second << endl;
  }

  // we define an iterator of a STL
  vector<int> test2(5, 0);
  vector<int>::iterator itr_temp = test2.begin();
  //  itr_temp = 3;
  // illegal

  *itr_temp = 3; // legal

  return 0;
}

// change the content of what iterator point to, add &
