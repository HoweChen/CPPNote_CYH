
#include <iostream>
#include <vector>

#define F(i, a) for (int i = (0); i < (a); i++)
#define Max(a, b) (a < b ? b : a)
using namespace std;

int main() {
  int number;
  cin >> number;
  F(i, number) {
    int size = 0;
    int number_of_block = 0;
    cin >> size;
    vector<vector<int> > chessboard(size, vector<int>(size));
    cin >> number_of_block;
    F(block_iterator, number_of_block) {
      int r1, c1, r2, c2 = 0;
      cin >> r1 >> c1 >> r2 >> c2;
//      if (r1 <= 0 || c1 <= 0 || r2 <= 0 || c2 <= 0) {
//        exit(0);
//      }
      r1 = r1 - 1;
      c1 = c1 - 1;
      r2 = r2 - 1;
      c2 = c2 - 1;
      for (int row = r1; row <= r2; ++row) {
        for (int column = c1; column <= c2; ++column) {
          chessboard[row][column] = -1;
        }
      }
      int to_right = size - 1 - c2;
      int to_left = c1;
      int to_up = r1;
      int to_bot = size - 1 - r2;
      int max_column = Max(to_left, to_right);
      int max_row = Max(to_up, to_bot);
      if (max_row >= max_column) {
        if (to_up >= to_bot) {
          for (int row = 0; row < r1; ++row) {
            for (int column = 0; column < size; ++column) {
              if (chessboard[row][column] == -1)continue;
              chessboard[row][column] += 1;
            }
          }
        } else {
          for (int row = r2 + 1; row < size; ++row) {
            for (int column = 0; column < size; ++column) {
              if (chessboard[row][column] == -1)continue;
              chessboard[row][column] += 1;
            }
          }
        }
      } else {
        if (to_left >= to_right) {
          for (int row = 0; row < size; ++row) {
            for (int column = 0; column < c1; ++column) {
              if (chessboard[row][column] == -1)continue;
              chessboard[row][column] += 1;
            }
          }
        } else {
          for (int row = 0; row < size; ++row) {
            for (int column = c2 + 1; column < size; ++column) {
              if (chessboard[row][column] == -1)continue;
              chessboard[row][column] += 1;
            }
          }
        }
      }
    }
    int count = 0;
    F(row, size) {
      F(column, size) {
        if (chessboard[row][column] == number_of_block) {
          count += 1;
        }
      }
    }
    cout << count << endl;
  }
  return 0;
}
