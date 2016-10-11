#include <cstring>
#include <iostream>
#include <cstdlib>
#include <queue>
#include <stack>
#include <vector>
#include <cerrno>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::array;
using std::vector;

int main(int argc, char const *argv[]) {

  //atol
  int res_help = atol("help");
  int res_zero = atol("0");

  printf("Got from help: %d, from zero: %d\n", res_help, res_zero);

  //strtol
  const char* p = "10 200000000000000000000000000000 30 -40";
    char *end;
    std::cout << "Parsing '" << p << "':\n";
    for (long i = std::strtol(p, &end, 10);
         p != end;
         i = std::strtol(p, &end, 10))
    {
        std::cout << "'" << std::string(p, end-p) << "' -> ";
        p = end;
        if (errno == ERANGE){
            std::cout << "range error, got ";
            errno = 0;
        }
        std::cout << i << '\n';
    }

  /*
  sample output:
  Parsing '10 200000000000000000000000000000 30 -40':
'10' -> 10
' 200000000000000000000000000000' -> range error, got 9223372036854775807
' 30' -> 30
' -40' -> -40
   */

  //  char* end;
  //  int res_help = strtol("help", &end, 10);
  std::cout << "Converting Help to long" << std::endl;
  res_help = strtol("help", &end, 10);

   if (!*end)
     printf("Converted successfully\n");
   else
     printf("Conversion error, non-convertible part: %s", end);

   return 0;
  return 0;
}
