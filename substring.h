
//
// Created by Franc on 21/05/2025.
//

#ifndef SUBSTRING_H
#define SUBSTRING_H



#include <string>
#include <utility>

/**
 * @brief Encuentra la subcadena común más larga entre dos textos.
 *
 * Esta función calcula el inicio y la longitud de la subcadena más larga
 * que aparece en ambos textos proporcionados.
 *
 * @param text1 Primer texto.
 * @param text2 Segundo texto.
 * @return std::pair<int, int> Un par con:
 *         - first: índice inicial en text1 donde comienza la subcadena.
 *         - second: longitud de la subcadena común más larga.
 */

std::pair<int, int> longest_common_substring(const std::string &text1, const std::string &text2);

#endif // SUBSTRING_H
