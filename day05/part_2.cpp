#include <iostream>
#include <math.h>
#include <set>

unsigned calcRow(const char letter, unsigned& row) {
  return letter == 'F' ? row : 2;
}

int main() {
  std::string line;
  
  unsigned highestSeat = 0;
  std::set<int> seatIds;

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
    seatIds.insert(seatId);
    if (highestSeat < seatId) {
      highestSeat = seatId;
    }
  }
  unsigned lowestSeatId = *seatIds.begin();
  for (auto it = seatIds.begin(); it != seatIds.end(); ++it) {
    std::cout << "ID:\t" << *it << std::endl;
  }
  std::cout << highestSeat << std::endl;
  std::cout << "lowestId: " << *seatIds.begin() << std::endl;
  std::cout << "amount of IDs: " << highestSeat-lowestSeatId << std::endl;
  std::cout << "actual amount of IDs: " << seatIds.size()-lowestSeatId << std::endl;

  return 0;
}