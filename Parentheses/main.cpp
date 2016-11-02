#include <iostream>
#include <cstdlib>
#include <deque>
#include <cstring>
#include <vector>

using namespace std;

int main() {
  /* code */

  int number;
  cin >> number;
  if (number <= 0) {
    exit(0);
  } else {
    vector<int> result_vector;
    for (int i = 0; i < number; ++i) {
      int str_length = 0;
      cin >> str_length;
      string str;
      cin >> str;
      if (str.length() != str_length) {
        exit(0);
      } else {
        deque<char> str_deque;
        for (int j = 0; j < str.length(); ++j) {
          if (str_deque.empty()) {
            str_deque.push_back(str[j]);
          } else {
            // not empty
            if (str[j] == ')' && str_deque.back() == '(') {
              str_deque.pop_back();
            } else {
              str_deque.push_back(str[j]);
            }
          }
        }
        vector<char> str_vector;
        while (!str_deque.empty()) {
          str_vector.push_back(str_deque.front());
          str_deque.pop_front();
        }

//        for (int l = 0; l < str_vector.size(); ++l) {
//          cout << str_vector[l] << endl;
//        }

        //calculate count
        int count = 0;
        if (str_vector.empty()) { ;
        } else {
          for (int k = 0; k < str_vector.size(); ++k) {
            if (k % 2 == 0) {
              if (str_vector[k] != '(') {
                count += 1;
              }
            } else {
              if (str_vector[k] != ')') {
                count += 1;
              }
            }
          }
        }
        result_vector.push_back(count);
      }
    }
    for (int l = 0; l < result_vector.size(); ++l) {
      cout << result_vector[l] << endl;
    }
  }
  return 0;
}
