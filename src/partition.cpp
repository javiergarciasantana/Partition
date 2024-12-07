#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cassert>
#include "bitset.hpp" // Include the provided bitset class.

using namespace std;
using namespace GOMA;

// Function to parse a binary string into a bitset.
GOMA::bitset parse_binary_string(const string& binary, int n) {
    assert(binary.length() == 3 * n); // Each binary string must be of length 3 * n.
    GOMA::bitset b(3 * n); // Create a bitset of size 3n.

    for (size_t i = 0; i < binary.length(); ++i) {
        if (binary[i] == '1') {
            b.insert(i + 1); // Insert position into the bitset.
        }
    }
    return b;
}

// Function to check if the 3DM partition is valid.
bool is_valid_3dm(const vector<GOMA::bitset>& triples, int n) {
    GOMA::bitset universe(3 * n); // Full universe set.
    for (int i = 1; i <= 3 * n; ++i) {
        universe.insert(i);
    }

    GOMA::bitset matched(3 * n); // Tracks covered elements.
    for (const auto& triple : triples) {
        matched.insert(triple); // Add elements of the triple to the matched set.
    }

    return matched.contains(universe); // Ensure all elements are covered.
}

int main() {
    string filename;
    cout << "Enter the filename: ";
    cin >> filename;

    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Error opening file." << endl;
        return 1;
    }

    int n;
    file >> n; // Read the size of the universe.

    vector<GOMA::bitset> triples;
    string binary;
    while (file >> binary) {
        triples.push_back(parse_binary_string(binary, n)); // Parse each binary triple.
    }
    file.close();

    cout << "Parsed triples:" << endl;
    for (size_t i = 0; i < triples.size(); ++i) {
        cout << "Triple " << (i + 1) << ": ";
        triples[i].write(cout);
        cout << endl;
    }

    // Check if the partition is valid.
    bool valid = is_valid_3dm(triples, n);
    if (valid) {
        cout << "The partition is valid!" << endl;
    } else {
        cout << "The partition is NOT valid." << endl;
    }

    return 0;
}
