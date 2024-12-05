#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

// Estructura para una tripleta (x, y, z)
struct Tripleta {
    int x, y, z;
    Tripleta(int x_, int y_, int z_) : x(x_), y(y_), z(z_) {}
};

// Conjunto de tripletas
using Tripletas = vector<Tripleta>;



bool partition3DM(const Tripletas& T, int n) {
    // `n` es el tamaño de los conjuntos X, Y, Z.
    unordered_set<int> usedX, usedY, usedZ;

    for (const auto& tripleta : T) {
        // Verifica si los elementos de la tripleta ya están usados
        if (usedX.count(tripleta.x) || usedY.count(tripleta.y) || usedZ.count(tripleta.z)) {
            continue; // Tripleta inválida
        }
        
        // Marca los elementos como usados
        usedX.insert(tripleta.x);
        usedY.insert(tripleta.y);
        usedZ.insert(tripleta.z);
        
        // Si hemos cubierto todos los elementos, terminamos
        if (usedX.size() == n && usedY.size() == n && usedZ.size() == n) {
            return true; // Encontramos una partición válida
        }
    }
    
    return false; // No hay partición válida
}


int main() {
    // Ejemplo: Conjunto de tripletas
    Tripletas T = {
        {1, 1, 1},
        {2, 2, 2},
        {3, 3, 3}
    };
    
    int n = 3; // Tamaño de los conjuntos X, Y, Z
    
    if (partition3DM(T, n)) {
        cout << "Se encontró una partición válida." << endl;
    } else {
        cout << "No se encontró una partición válida." << endl;
    }
    
    return 0;
}
