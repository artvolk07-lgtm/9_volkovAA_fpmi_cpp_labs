#include "pch.h" 
#include <iostream>
#include <cmath>
#include <vector>
#include <tuple>
#include <limits>
#include <sstream>

bool ReadNatural(int& n, std::istream& in = std::cin, std::ostream& out = std::cout) {
    n = 0;
    bool ok = false;
    while (!ok) {
        out << "Natural n: ";
        in >> n;
        if (in.fail() || n <= 0) {
            in.clear();
            in.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            out << "Enter positive natural number." << std::endl;
            if (in.eof()) return false;
        }
        else {
            ok = true;
        }
    }
    return true;
}

std::vector<std::tuple<int, int, int>> GetPythagoreanTriples(int n) {
    std::vector<std::tuple<int, int, int>> res;
    if (n <= 0) return res;
    for (int a = 1; a <= n; ++a) {
        for (int b = a; b <= n; ++b) {
            int sqc = a * a + b * b;
            int c = static_cast<int>(std::sqrt(static_cast<double>(sqc)));
            if (c * c == sqc && c <= n) {
                res.push_back(std::make_tuple(a, b, c));
            }
        }
    }
    return res;
}

void PrintPythagoreanTriples(int n, std::ostream& out = std::cout) {
    std::vector<std::tuple<int, int, int>> triples = GetPythagoreanTriples(n);
    for (size_t i = 0; i < triples.size(); ++i) {
        int a = std::get<0>(triples[i]);
        int b = std::get<1>(triples[i]);
        int c = std::get<2>(triples[i]);
        out << "(" << a << ", " << b << ", " << c << ")" << std::endl;
    }
}