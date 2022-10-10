#include <iostream>

int main(int argc, char *argv[]) {
  for (unsigned i = 0; i < 10; i++) {
    if (i == 3) {
      continue;
    }
    if (i == 5) {
      break;
    }
    std::cout << i << std::endl;
  }

  std::cout << "Salida for" << std::endl;
}
