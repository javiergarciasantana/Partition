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
GOMA::bitset parse_binary_string(const string& input, int n) {
  int p = log2(n) + 1;
  GOMA::bitset b(3*p*n); // Crear un bitset de tamaño 3n.

  for (size_t i = 0; i < input.length(); ++i) {
    

    b.insert((p * 4 * (3 - i - 1)) + ((input[i] - 48 - 1) * 4) + 1); // Insertar posición en el bitset.

   
  }
  return b;
}

// Función para verificar si la partición 3DM es válida.
bool is_valid_3dm(const vector<GOMA::bitset>& triples, int n) {
  GOMA::bitset universe(3 * n); // Conjunto universo completo.
  for (int i = 1; i <= 3 * n; ++i) {
    universe.insert(i);
  }

  GOMA::bitset matched(3 * n); // Rastrea los elementos cubiertos.
  for (const auto& triple : triples) {
    matched.insert(triple); // Agregar elementos del triple al conjunto matched.
  }

  return matched.contains(universe); // Asegurarse de que todos los elementos estén cubiertos.
}

int main() {
  string filename;
  cout << "Ingrese el nombre del archivo: ";
  cin >> filename;

  ifstream file(filename);
  if (!file.is_open()) {
    cerr << "Error al abrir el archivo." << endl;
    return 1;
  }

  int n;
  file >> n; // Leer el tamaño del universo.

  vector<GOMA::bitset> triples;
  string input;
  while (file >> input) {
    triples.push_back(parse_binary_string(input, n)); // Analizar cada triple binario.
  }
  file.close();

  cout << "Triples analizados:" << endl;
  for (size_t i = 0; i < triples.size(); ++i) {
    cout << "Triple " << (i + 1) << ": ";
    triples[i].write(cout);
    cout << endl;
  }

  // // Verificar si la partición es válida.
  // bool valid = is_valid_3dm(triples, n);
  // if (valid) {
  //   cout << "¡La partición es válida!" << endl;
  // } else {
  //   cout << "La partición NO es válida." << endl;
  // }

  return 0;
}
