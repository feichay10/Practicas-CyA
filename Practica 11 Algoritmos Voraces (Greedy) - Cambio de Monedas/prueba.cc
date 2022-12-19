#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<double> devolver_cambio(double n) {
  vector<double> monedas {2.0, 1.0, 0.50, 0.20, 0.10, 0.05, 0.02, 0.01};
  vector<double> solucion;
  double suma = 0;
  for (auto v : monedas) {
    int c = floor(n / v);
    if (c > 0) {
      solucion.insert(solucion.end(), c, v);
      suma += c * v;
      n -= c * v;
    }
  }
  return solucion;
}

int main() {
  vector<double> solucion = devolver_cambio(234.56);
  for (auto m : solucion) {
    cout << m << " ";
  }
  cout << endl;
  return 0;
}
