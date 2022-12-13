#include <iostream>

using namespace std;

// poner aqui los ejemplos como funciones con el siguiente formato,
// donde 'X' es el numero de ejemplo
int ejemplo1(const int n) {
  // codigo fuente de cada bloque
  int a = 1, b = 2, c = 3;
  // asignacion
  a = b;  // Θ(1)
  // operaciones aritmeticas
  a = b + c;  // Θ(1)
  return a;
}

int ejemplo2(const int n) {
  // codigo fuente de cada bloque

  int suma = 0;  // Θ(1)
  for (int i = 1; i <= n; i++)  // Θ(n)
    suma++;  // Θ(1)

  return suma;
}

int ejemplo3(const int n) {
  // codigo fuente de cada bloque

  int suma = 0;  // Θ(1)
  for (int i = 1; i <= n; i++)  // Θ(n)
    for (int j = 1; j <= n; j++)  // Θ(n)
      suma++;  // Θ(1)

  return suma;
}

int ejemplo4(const int n) {
  // codigo fuente de cada bloque

  int suma = 0;  // Θ(1)
  for (int i = 1; i <= n; i++)  // Θ(n)
    for (int j = 1; j <= i; j++)  // Θ(i)
      suma++;  // Θ(1)

  return suma;
}

int ejemplo5(const int n) {
  // codigo fuente de cada bloque

  int suma = 0;  // Θ(1)
  for (int i = 1; i <= n; i *= 2)  // Θ(log n)
    for (int j = 1; j <= n; j++)  // Θ(n)
      suma++;  // Θ(1)

  return suma;
}

int ejemplo6(const int n) {
  // codigo fuente de cada bloque

  int suma = 0;  // (1)
  for (int i = 1; i <= n; i *= 2)  // Θ(log n)
    for (int j = 1; j <= i; j++)  // Θ(i)
      suma++;  // (1)

  return suma;
}

int main() {  // pedir el valor de n
  int n;
  cout << "Introducir n: ";
  cin >> n;

  // invocar a cada ejemplo
  cout << "Ejemplo 1: " << ejemplo1(n) << endl;
  cout << "Ejemplo 2: " << ejemplo2(n) << endl;
  cout << "Ejemplo 3: " << ejemplo3(n) << endl;
  cout << "Ejemplo 4: " << ejemplo4(n) << endl;
  cout << "Ejemplo 5: " << ejemplo5(n) << endl;
  cout << "Ejemplo 6: " << ejemplo6(n) << endl;
  return 0;
}