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

class Report {
private:
  std::string str;
public:
  Report(const std::string s) : str(s) {
    std::cout << "Object Created" << endl;
  }

  ~Report() {
    cout << "Object Deleted" << endl;
  }

  void comment() const {
    cout << str << endl;
  }
};

int main(int argc, const char *argv[]) {

  //time to code
  {
    auto_ptr<Report> ps(new Report("Using auto_ptr"));
    ps->comment();
  }
  {
    shared_ptr<Report> ps(new Report("Using shared_ptr"));
    ps->comment();
  }
  {
    unique_ptr<Report> ps(new Report("Using unique_ptr"));
    ps->comment();
  }
  return 0;
}

// @END_OF_SOURCE_CODE
