#include <iostream>

using namespace std;

int main(int argc, char const *argv[]) {
  /* code */

  freopen("input.txt","r",stdin);
  int times;
  cin >> times;
  for (int i = 1; i <= times; ++i) {
    cout << i << " Abracadabra" << endl;
  }
  return 0;
}
