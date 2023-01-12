/**
 *
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Computabilidad y Algoritmia
 * Curso: 2º
 * Práctica 12: Algoritmos Divide y Vencerás (Divide & Conquer) - Multiplicación
 * de enteros grandes
 * @file bigint.cc
 * @author Cheuk Kelly Ng Pante (alu0101364544@ull.edu.es)
 * @brief Definición de la clase BigInt y sus metodos
 * @version 0.1
 * @date 2023-01-10
 *
 * @copyright Copyright (c) 2022
 *
 */

#include "bigint.h"

BigInt::BigInt(std::string &s) {
  digits = "";
  int n = s.size();
  for (int i = n - 1; i >= 0; i--) {
    if (!isdigit(s[i])) throw("ERROR");
    digits.push_back(s[i] - '0');
  }
  count = 0;
}

BigInt::BigInt(unsigned long long nr) {
  do {
    digits.push_back(nr % 10);
    nr /= 10;
  } while (nr);
  count = 0;
}

BigInt::BigInt(const char *s) {
  digits = "";
  for (int i = strlen(s) - 1; i >= 0; i--) {
    if (!isdigit(s[i])) throw("ERROR");
    digits.push_back(s[i] - '0');
  }
  count = 0;
}

BigInt::BigInt(const BigInt &a) { 
  digits = a.digits; 
  count = 0;
  count = a.count;
}

bool Null(const BigInt &a) {
  if (a.digits.size() == 1 && a.digits[0] == 0) return true;
  return false;
}
int Length(const BigInt &a) { return a.digits.size(); }
int BigInt::operator[](const int index) const {
  if (digits.size() <= index || index < 0) throw("ERROR");
  return digits[index];
}
bool operator==(const BigInt &a, const BigInt &b) {
  return a.digits == b.digits;
}
bool operator!=(const BigInt &a, const BigInt &b) { return !(a == b); }
bool operator<(const BigInt &a, const BigInt &b) {
  int n = Length(a), m = Length(b);
  if (n != m) return n < m;
  while (n--)
    if (a.digits[n] != b.digits[n]) return a.digits[n] < b.digits[n];
  return false;
}
bool operator>(const BigInt &a, const BigInt &b) { return b < a; }
bool operator>=(const BigInt &a, const BigInt &b) { return !(a < b); }
bool operator<=(const BigInt &a, const BigInt &b) { return !(a > b); }

BigInt &BigInt::operator=(const BigInt &a) {
  digits = a.digits;
  count += a.count;
  return *this;
}

BigInt &BigInt::operator++() {
  int i, n = digits.size();
  for (i = 0; i < n && digits[i] == 9; i++) digits[i] = 0;
  if (i == n)
    digits.push_back(1);
  else
    digits[i]++;
  return *this;
}
BigInt BigInt::operator++(int temp) {
  BigInt aux;
  aux = *this;
  ++(*this);
  return aux;
}

BigInt &BigInt::operator--() {
  if (digits[0] == 0 && digits.size() == 1) throw("UNDERFLOW");
  int i, n = digits.size();
  for (i = 0; digits[i] == 0 && i < n; i++) digits[i] = 9;
  digits[i]--;
  if (n > 1 && digits[n - 1] == 0) digits.pop_back();
  return *this;
}

BigInt BigInt::operator--(int temp) {
  BigInt aux;
  aux = *this;
  --(*this);
  return aux;
}

BigInt &operator+=(BigInt &a, const BigInt &b) {
  int t = 0, s, i;
  int n = Length(a), m = Length(b);
  if (m > n) a.digits.append(m - n, 0);
  n = Length(a);
  for (i = 0; i < n; i++) {
    if (i < m)
      s = (a.digits[i] + b.digits[i]) + t;
    else
      s = a.digits[i] + t;
    t = s / 10;
    a.digits[i] = (s % 10);
  }
  if (t) a.digits.push_back(t);
  a.count = a.count + b.count;
  return a;
}

BigInt operator+(const BigInt &a, const BigInt &b) {
  BigInt temp;
  temp = a;
  temp += b;

  temp.count = a.count + b.count;

  return temp;
}

BigInt &operator-=(BigInt &a, const BigInt &b) {
  if (a < b) throw("UNDERFLOW");
  int n = Length(a), m = Length(b);
  int i, t = 0, s;
  for (i = 0; i < n; i++) {
    if (i < m)
      s = a.digits[i] - b.digits[i] + t;
    else
      s = a.digits[i] + t;
    if (s < 0)
      s += 10, t = -1;
    else
      t = 0;
    a.digits[i] = s;
  }
  while (n > 1 && a.digits[n - 1] == 0) a.digits.pop_back(), n--;
  a.count = a.count + b.count;
  return a;
}
BigInt operator-(const BigInt &a, const BigInt &b) {
  BigInt temp;
  temp = a;
  temp -= b;

  temp.count = a.count + b.count;

  return temp;
}

BigInt &operator*=(BigInt &a, const BigInt &b) {
  if (Null(a) || Null(b)) {
    a = BigInt();
    return a;
  }
  int n = a.digits.size(), m = b.digits.size();
  std::vector<int> v(n + m, 0);
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) {
      v[i + j] += (a.digits[i]) * (b.digits[j]);
    }
  n += m;
  a.digits.resize(v.size());
  for (int s, i = 0, t = 0; i < n; i++) {
    s = t + v[i];
    v[i] = s % 10;
    t = s / 10;
    a.digits[i] = v[i];
  }
  for (int i = n - 1; i >= 1 && !v[i]; i--) a.digits.pop_back();
  return a;
}

BigInt operator*(const BigInt &a, const BigInt &b) {
  BigInt temp;
  temp = a;
  temp *= b;

  temp.count = a.count + b.count + 1;
  // std::cout << temp.count << std::endl;

  return temp;
}

BigInt &operator/=(BigInt &a, const BigInt &b) {
  if (Null(b)) throw("Arithmetic Error: Division By 0");
  if (a < b) {
    a = BigInt();
    return a;
  }
  if (a == b) {
    int times = a.count;
    a = BigInt(1);
    a.count = times + b.count;
    return a;
  }
  int i, lgcat = 0, cc;
  int n = Length(a), m = Length(b);
  std::vector<int> cat(n, 0);
  BigInt t;
  for (i = n - 1; t * 10 + a.digits[i] < b; i--) {
    t *= 10;
    t += a.digits[i];
  }
  for (; i >= 0; i--) {
    t = t * 10 + a.digits[i];
    for (cc = 9; cc * b > t; cc--)
      ;
    t -= cc * b;
    cat[lgcat++] = cc;
  }
  a.digits.resize(cat.size());
  for (i = 0; i < lgcat; i++) a.digits[i] = cat[lgcat - i - 1];
  a.digits.resize(lgcat);
  a.count = a.count + b.count;
  return a;
}

BigInt operator/(const BigInt &a, const BigInt &b) {
  BigInt temp;
  temp = a;
  temp /= b;
  temp.count = a.count + b.count;	
  return temp;
}

BigInt &operator%=(BigInt &a, const BigInt &b) {
  if (Null(b)) throw("Arithmetic Error: Division By 0");
  if (a < b) {
    return a;
  }
  if (a == b) {
    int times = a.count;
    a = BigInt();
    a.count = times;
    return a;
  }
  int i, lgcat = 0, cc;
  int n = Length(a), m = Length(b);
  std::vector<int> cat(n, 0);
  BigInt t;
  for (i = n - 1; t * 10 + a.digits[i] < b; i--) {
    t *= 10;
    t += a.digits[i];
  }
  for (; i >= 0; i--) {
    t = t * 10 + a.digits[i];
    for (cc = 9; cc * b > t; cc--)
      ;
    t -= cc * b;
    cat[lgcat++] = cc;
  }
  a = t;
  return a;
}

BigInt operator%(const BigInt &a, const BigInt &b) {
  BigInt temp;
  temp = a;
  temp %= b;
  temp.count = a.count + b.count;
  return temp;
}

BigInt &operator^=(BigInt &a, const BigInt &b) {
  BigInt Exponent, Base(a);
  Exponent = b;
  a = 1;
  while (!Null(Exponent)) {
    if (Exponent[0] & 1) a *= Base;
    Base *= Base;
    divide_by_2(Exponent);
  }
  a.count = a.count + b.count;
  return a;
}

BigInt operator^(BigInt &a, BigInt &b) {
  BigInt temp(a);
  temp ^= b;
  temp.count = a.count + b.count;
  return temp;
}

void divide_by_2(BigInt &a) {
  int add = 0;
  for (int i = a.digits.size() - 1; i >= 0; i--) {
    int digit = (a.digits[i] >> 1) + add;
    add = ((a.digits[i] & 1) * 5);
    a.digits[i] = digit;
  }
  while (a.digits.size() > 1 && !a.digits.back()) a.digits.pop_back();
}

BigInt sqrt(BigInt &a) {
  BigInt left(1), right(a), v(1), mid, prod;
  divide_by_2(right);
  while (left <= right) {
    mid += left;
    mid += right;
    divide_by_2(mid);
    prod = (mid * mid);
    if (prod <= a) {
      v = mid;
      ++mid;
      left = mid;
    } else {
      --mid;
      right = mid;
    }
    mid = BigInt();
  }
  v.count = a.count;
  return v;
}

BigInt NthCatalan(int n) {
  BigInt a(1), b;
  for (int i = 2; i <= n; i++) a *= i;
  b = a;
  for (int i = n + 1; i <= 2 * n; i++) b *= i;
  a *= a;
  a *= (n + 1);
  b /= a;
  return b;
}

BigInt NthFibonacci(int n) {
  BigInt a(1), b(1), c;
  if (!n) return c;
  n--;
  while (n--) {
    c = a + b;
    b = a;
    a = c;
  }
  return b;
}

BigInt Factorial(int n) {
  BigInt f(1);
  for (int i = 2; i <= n; i++) f *= i;
  return f;
}

std::istream &operator>>(std::istream &in, BigInt &a) {
  std::string s;
  in >> s;
  int n = s.size();
  for (int i = n - 1; i >= 0; i--) {
    if (!isdigit(s[i])) throw("INVALID NUMBER");
    a.digits[n - i - 1] = s[i];
  }
  return in;
}

std::ostream &operator<<(std::ostream &out, const BigInt &a) {
  for (int i = a.digits.size() - 1; i >= 0; i--)
    std::cout << (short)a.digits[i];
  return std::cout;
}

BigInt BigInt::Karatsuba(BigInt num1, BigInt num2, int cota) {
  // Calcular el tamaño de cada número
  BigInt size1 = BigInt(Length(num1));
  BigInt size2 = BigInt(Length(num2));

  // Elige el número mayor
  BigInt N = std::max(size1, size2);
  
  // Si N es menor que la cota o 10, se retorna el resultado de multiplicar num1 * num2.
  if (cota == 0) {
    if (N < 10) return BigInt(num1 * num2);
  } else {
    if (N < cota) return num1 * num2;
  }

  // Contador de llamadas al operador * de la clase BigInt:
  
  // Dividir N entre 2 y redondea hacia arriba
  N = (N / 2) + (N % 2);
  
  // Calcular el valor "m"
  BigInt base(10);
  BigInt m = base ^ N; // Tarda mas porque la implementacion del operador ^ de la clase bigint que hace una multiplicacion 
  
  // Dividir num1 y num2 en bloques "a", "b", "c", y "d"
  BigInt b = num1 / m;
  BigInt a = num1 - (b * m); // Aqui hay otra multiplicacion
  BigInt d = num2 / m;
  BigInt c = num2 - (d * m); // Aqui hay otra multiplicacion
  
  // Realizar 3 llamadas recursivas a la función Karatsuba para calcular z0, z1 y z2
  BigInt z0 = Karatsuba(a, c, cota);
  BigInt z1 = Karatsuba(a + b, c + d, cota);
  BigInt z2 = Karatsuba(b, d, cota);

  BigInt result = z0 + ((z1 - z0 - z2) * m) + (z2 * m * m);
  // Retorna el resultado final utilizando la fórmula
  return result; 
}

int BigInt::getCount() const {
  return count;
}