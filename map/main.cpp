#include <algorithm>
#include <bitset>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>
#include <memory>

#define Inf 2147483647
#define Pi acos(-1.0)
#define N 1000000
#define LL long long

inline LL Power(int b, int p) {
  LL ret = 1;
  for (int i = 1; i <= p; i++)
    ret *= b;
  return ret;
}

const int dr[] = {-1, -1, 0, 1, 1, 1, 0, -1};
const int dc[] = {0, 1, 1, 1, 0, -1, -1, -1};

#define F(i, a) for (int i = (0); i < (a); i++)
#define Fs(i, sz) for (size_t i = 0; i < sz.size(); i++)
#define Fe(i, x) for (typeof(x.begin()) i = x.begin(); i != x.end(); i++)
#define Set(a, s) memset(a, s, sizeof(a))
#define Max(a, b) (a < b ? b : a)
#define Min(a, b) (a > b ? b : a)

using namespace std;

int find_occurence_character(string s, char c);

int find_occurence_substring(string s, string substr);

string replace_substring_to_another_substring(string s, string substr_original, string substr_target);

int main(int argc, const char* argv[]) {

  //time to code
  //
  map<string, int> cheatsheet;
  int M;
  cin >> M;
  if (M<2 || M>1000) {
    exit(0);
  }
  F(i, M) {
    string input;
    cin >> input;
    if (input.length()>60) {
      exit(0);
    }
    cheatsheet.insert(map<string, int>::value_type(input, i + 1));
  }
  string one_line_code;
  if (one_line_code.length()>1000000) {
    exit(0);
  }
  cin >> one_line_code;

  size_t current_flag = 0;
  size_t temp_flag = current_flag+1;

  while (true) {
    string sub_str =one_line_code.substr(current_flag,temp_flag);
    map<string,int>::iterator search = cheatsheet.find(sub_str);
    if (search == cheatsheet.end() && temp_flag == one_line_code.length()-1) {
      break;
    }

    if (search!=cheatsheet.end()) {
      //found
      cout<<search->second<<" ";
      current_flag += temp_flag;
      temp_flag = 1;
      continue;
    }
    ++temp_flag;

  }
  cout<<endl;

  // okay to use
  //  auto search = cheatsheet.find("-.-");
  //  cout<<search->second<<endl;
  cout << endl;

  return 0;
}

int find_occurence_substring(string s, string substr) {
  int count = 0;
  size_t nPos = s.find(substr, 0); // fist occurrence
  while (nPos != string::npos) {
    count++;
    nPos = s.find(substr, nPos + 1);
  }

  return count;
}

int find_occurence_character(string s, char c) {
  int count = 0;
  Fs(i, s) {
    if (s[i] == c) ++count;
    else continue;
  }
  return count;
}

string replace_substring_to_another_substring(string s, string substr_original, string substr_target) {
  size_t index = 0;
  while (true) {
    /* Locate the substring to replace. */
    index = s.find(substr_original, index);
    if (index == std::string::npos) break;

    /* Make the replacement. */
    s.replace(index, substr_original.length(), substr_target);

    /* Advance index forward so the next iteration doesn't pick it up as well. */
    index += substr_original.length();
  }
  return s;

}

// @END_OF_SOURCE_CODE

/*

Problem 4. Dash and Dot

The year is 1942, and you are a spy nicknamed Sparrow. You are working undercover in Nanjing. Your job is to gather intelligent send it to your headquarter. The message you need to send consists of a sequence of N positive integers in the range from 1 to M (inclusive), and the message will be sent using a radio telegram machine in which each integer is sent as a sequence of dashes and dots. The traditional telegram message includes a “break” (a short silence) between letters/numbers. However, you ﬁnd out that if the breaks are eliminated, the message can be sent in much shorted time and thus reduce the chances of being caught by your enemy.

As a result, a new telegram coding system is created. In this coding system, each number is represented by a code which is still made up by dashes and dots. However, the message is sent out as a continuous stream of dashed and dots without any break in between. In order to make this system work, the coding system also ensures that no one telegram code is a preﬁx of the any other code. For example, if the code for 1 is ‘.-’, then there will not be any other code in the system that starts with ‘.-’.

What is needed now is to program a machine that can translate the continuous stream of dashed and dots received back to a sequence of integers.

Input

The input contains three parts:

• The ﬁrst part consists of one positive integer on a line. The integer is M. (2 ≤ M ≤ 1, 000)

• The second part consist of M lines, each line consist of a combination of dots ‘.’ and dashes ‘-’. They sequentially represent the telegram code for the integer from 1 to M with respectively. The length of each code is less than or equal to 60.

• The last part consists of one line of dashed and dots, which representing the contents of the message. The line ends with a end-of-line. The length of the message (total number of dashes and dots) is at most 1,000,000.

Output

The output should consist of N integers on a single line. These integers represent the sequence of the numbers in the message. There should be one space between each integer and should not have any leading or trailing spaces. The line should end with end-of-line.

Example

Input:

Output:

4 . -- -.. -.- ..-.----..--

1 1 4 2 3 2

 */
