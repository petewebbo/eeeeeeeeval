
#include <iostream>
#include <stdexcept>
#include <string>

#include "eeeeeeeeval.hpp"

int main(int argc, char* argv[]) {
    std::string expr;
    if (argc < 2) {
        throw std::runtime_error("no expressio given");
    } else {
        expr.assign(argv[1]);
    }
    cout << "expression = " << expr << endl;

    eeeeeeeeval e;
    e.parse(expr, 0);

    auto res = e.eval();
    cout << "result = " << res << endl;
    return 0;
}