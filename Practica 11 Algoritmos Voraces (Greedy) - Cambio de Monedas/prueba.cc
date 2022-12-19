#include <iostream>
#include <vector>

std::vector<double> devolver_cambio(double n) {
  std::vector<double> M = {2.0, 1.0, 0.50, 0.20, 0.10, 0.05, 0.02, 0.01};
  std::vector<double> S; // conjunto de la solución
  double suma = 0; // suma de los elementos de S
  for (double v : M) {
    int c = (n - suma) / v; // división entera
    if (c > 0) {
      for (int i = 0; i < c; i++) {
        S.push_back(v);
      }
      suma += c * v;
    }
  }
  return S;
}

int main() {
  std::vector<double> resultado = devolver_cambio(3.67);
  for (double m : resultado) {
    std::cout << m << " ";
  }
  std::cout << std::endl;
  return 0;
}
