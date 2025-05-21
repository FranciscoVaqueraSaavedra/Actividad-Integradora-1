
/* This source file must have a .cpp extension so that all C++ compilers
   recognize the extension without flags.  Borland does not know .cxx for
   example.  */

#include <iostream>
#include <vector>
#include "utils.h"
#include "palindrome.h"
#include "substring.h"


using std::cout;
using std::string;
using std::vector;

int main() {
    // Leer archivos de transmisión
    string transmission1 = read_file_content("C:/Users/Franc/CLionProjects/Actividad Integradora 1/transmission1.txt");
    string transmission2 = read_file_content("C:/Users/Franc/CLionProjects/Actividad Integradora 1/transmission2.txt");

    // Leer códigos
    vector<string> mcodes = {
        read_file_content("C:/Users/Franc/CLionProjects/Actividad Integradora 1/mcode1.txt"),
        read_file_content("C:/Users/Franc/CLionProjects/Actividad Integradora 1/mcode2.txt"),
        read_file_content("C:/Users/Franc/CLionProjects/Actividad Integradora 1/mcode3.txt")
    };

    // Parte 1: Verificar patrones
    cout << "Parte 1:\n";
    for (const auto& mcode : mcodes) {
        auto [found1, pos1] = contains_pattern(transmission1, mcode);
        cout << (found1 ? "true " + std::to_string(pos1) : "false") << '\n';
    }
    for (const auto& mcode : mcodes) {
        auto [found2, pos2] = contains_pattern(transmission2, mcode);
        cout << (found2 ? "true " + std::to_string(pos2) : "false") << '\n';
    }

    // Parte 2: Palíndromo más largo
    cout << "Parte 2:\n";
    auto [start1, end1] = longest_palindrome(transmission1);
    auto [start2, end2] = longest_palindrome(transmission2);

    cout << start1 << " " << end1 << " "
         << transmission1.substr(start1 - 1, end1 - start1 + 1) << '\n';

    cout << start2 << " " << end2 << " "
         << transmission2.substr(start2 - 1, end2 - start2 + 1) << '\n';

    // Parte 3: Subcadena común más larga
    cout << "Parte 3:\n";
    auto [start_common, end_common] = longest_common_substring(transmission1, transmission2);
    cout << start_common << " " << end_common << " "
         << transmission1.substr(start_common - 1, end_common - start_common + 1) << '\n';

    return 0;
}

