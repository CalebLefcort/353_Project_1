#include <iostream>
#include <string>
#include <unordered_map>

const char ALPHA[27] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', ' '};

int find_index(char ch)
{
  for (int i = 0; i < sizeof(ALPHA) - 1; i++)
  {
    if (ch == ALPHA[i])
    {
      return i;
    }
  }
  throw std::invalid_argument("Recived an invalid character");
  return -1;
}