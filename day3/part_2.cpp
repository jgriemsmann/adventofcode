#include <iostream>
#include <fstream>

int rideDownSlopes(const int stepsRight, const int stepsDown) {
  std::ifstream inputFile("input.txt");
  std::string line;

  int amountOfTrees = 0;

  int lineSize = 0;
  int counterLine = 0;
  int counter = 0;

  if (inputFile.is_open()) {
    while(getline(inputFile, line)) {
      if (counterLine == 0) {
        lineSize = line.size();
      } else if (counterLine % stepsDown == 0) {
        int pos;
        if (stepsDown > stepsRight) {
          pos = (counter + stepsRight) % lineSize;
        } else {
          pos = (counterLine * stepsRight) % lineSize;
        }
        // std::cout << "counterLine: " << counterLine << " pos: " << pos << "\t" << line[pos] << std::endl;
        if (line[pos] == '#') {
          amountOfTrees++;
        }
        counter++;
      }
      counterLine++;
    }
  }
  return amountOfTrees;
}

int main() {
  int trees = 1;
  
  // std::cout << rideDownSlopes(1, 1) << std::endl;
  // std::cout << rideDownSlopes(3, 1) << std::endl;
  // std::cout << rideDownSlopes(5, 1) << std::endl;
  // std::cout << rideDownSlopes(7, 1) << std::endl;
  // std::cout << rideDownSlopes(1, 2) << std::endl;

  trees *= rideDownSlopes(1, 1);
  trees *= rideDownSlopes(3, 1);
  trees *= rideDownSlopes(5, 1);
  trees *= rideDownSlopes(7, 1);
  trees *= rideDownSlopes(1, 2);
  
  std::cout << "amount of Trees: " << trees << std::endl;
}
