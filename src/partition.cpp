#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cassert>
#include <cmath>
#include "bitset.hpp" // Incluir la clase bitset proporcionada.

using namespace std;
using namespace GOMA;

// Función para analizar una cadena binaria en un bitset.
GOMA::bitset parse_binary_string(const string& input, int n, int q, int p) {
  
  GOMA::bitset b(3 * p * q); // Crear un bitset de tamaño 3*p*q.
  for (size_t i = 0; i < input.length(); ++i) {

    b.insert((p * 4 * (3 - i - 1)) + (std::atoi(string(1, input[i]).c_str()) - 1) * q + 1); // Insertar posición en el bitset.

  }
  return b;
}

GOMA::bitset create_bitsetB(int n, int q, int p) {
  GOMA::bitset b(3 * p * q);
  for (int i = 0; i < 3 * q; ++i) {
    b.insert(i * p + 1);
  }
  return b;
}


int main(int argc, char* argv[]) {
  string filename = argv[1]; 

  ifstream file(filename);
  if (!file.is_open()) {
    cerr << "Error al abrir el archivo." << endl;
    return 1;
  }

  int n;
  int q = 0;
  file >> n; // Leer el tamaño del universo.

  vector<GOMA::bitset> triples;
  string input;
  while (file >> input) {
    for (size_t i = 0; i < input.length(); ++i) {
      q = (atoi(string(1, input[i]).c_str()) > q) ? atoi(string(1, input[i]).c_str()) : q;
    }
  }
  cout << "q: " << q << endl;
  file.clear(); // Limpiar los flags del archivo.
  file.seekg(0); // Volver al inicio del archivo.
  file >> n; // Leer el tamaño del universo nuevamente.

  int p = log2(n) + 1;
  std::cout << "p: " << p << std::endl;

  while (file >> input) {
    triples.push_back(parse_binary_string(input, n, q, p)); // Analizar cada triple binario.
  }
  file.close();

  cout << "Tripletas analizadas:" << endl;
  for (size_t i = 0; i < triples.size(); ++i) {
    cout << "Tripleta " << (i + 1) << ":       ";
    triples[i].write(cout);
    cout << endl;
  }

  GOMA::bitset B = create_bitsetB(n, q, p);
  cout << "\nBitset B:         ";
  B.write(cout);
  cout << endl;

  GOMA::bitset sum(3 * p * q);
  GOMA::bitset C2_B(3 * p * q);

  for (const auto& triple : triples) {
    sum = sum + triple; 
  }
  cout << "Suma 1 vez:       ";
  sum.write(cout);
  cout << endl;

  cout << "Suma 2 veces:     ";
  (sum + sum).write(cout);
  cout << endl;

  cout << "C2                ";
  C2_B = B.ComplementA2();
  (C2_B).write(cout);
  cout << endl;

  cout << "Suma 2 veces - B: ";
  sum = sum - B;
  (sum).write(cout);
  return 0;
}
 