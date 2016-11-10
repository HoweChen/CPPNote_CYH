#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <unordered_map>

using namespace std;

int main(int argc, char const *argv[]) {
  /* code */
  map<int, std::string> test = {{6, "f"},
                                {5, "e"},
                                {4, "d"},
                                {3, "c"},
                                {2, "b"},
                                {1, "a"}
  };

  for (auto itr:test) {
    cout << itr.first << endl;
    itr.second = "Fuck";
  }

  for (auto itr:test) {
    cout << itr.second << endl;
  }

  for (auto &itr:test) {
    cout << itr.first << endl;
    itr.second = "Fuck";
  }

  for (auto itr:test) {
    cout << itr.second << endl;
  }
  return 0;
}

//change the content of what iterator point to, add &
