#include <iostream>
#include <fstream>

int main() {
  std::ifstream inputFile("input.txt");
  std::string line;

  int stepsRight = 3;
  int stepsDown = 1;

  int lineSize = 0;
  int counterLine = 0;

  int amountOfTrees = 0;

  if (inputFile.is_open()) {
    while(getline(inputFile, line)) {
      if (counterLine == 0) {
        lineSize = line.size();
      } else if (counterLine % stepsDown == 0) {
        int pos = (counterLine * stepsRight) % lineSize;
        // std::cout << "counterLine: " << counterLine << " pos: " << pos << "\t" << line[pos] << std::endl;
        if (line[pos] == '#') {
          amountOfTrees++;
        }
      }
      counterLine++;
    }
  }
  std::cout << "amount of Trees: " << amountOfTrees << std::endl;
}
