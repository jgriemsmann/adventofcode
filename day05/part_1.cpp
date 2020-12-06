#include <iostream>
#include <math.h>

unsigned calcRow(const char letter, unsigned& row) {
  return letter == 'F' ? row : 2;
}

int main() {
  std::string line;
  
  unsigned highestSeat = 0;

  while(getline(std::cin, line)) {
    float rowLower = 0;
    float rowUpper = 127;
    float columnLower = 0;
    float columnUpper = 7;
    unsigned seatId = 0;
    for (auto it = line.begin(); it != line.end(); ++it) {
      if (*it == 'F') {
        rowUpper = floor(rowUpper - (rowUpper-rowLower)/2);
      } else if (*it == 'B') {
        rowLower = round(rowLower + (rowUpper-rowLower)/2);
      } else if (*it == 'R') {
        columnLower = round(columnLower + (columnUpper-columnLower)/2);
      } else if (*it == 'L') {
        columnUpper = floor(columnUpper - (columnUpper-columnLower)/2);
      }
    }
    seatId = rowLower * 8 + columnLower;
    if (highestSeat < seatId) {
      highestSeat = seatId;
    }
  }
  std::cout << highestSeat << std::endl;
}