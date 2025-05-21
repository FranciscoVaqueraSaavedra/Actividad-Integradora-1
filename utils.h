
//
// Created by Franc on 20/05/2025.
//

#ifndef UTILS_H
#define UTILS_H

#include <string>
#include <fstream>
#include <iostream>

std::string read_file_content(const std::string &filename) {
    std::ifstream file(filename);
    if (!file) {
        std::cerr << "Error al abrir el archivo: " << filename << std::endl;
        exit(1);
    }
    std::string content((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
    return content;
}

std::pair<bool, size_t> contains_pattern(const std::string &text, const std::string &pattern) {
    size_t pos = text.find(pattern);
    return (pos != std::string::npos) ? std::make_pair(true, pos + 1) : std::make_pair(false, static_cast<size_t>(0));
}

#endif

