
#include <math.h>

#include <algorithm>
#include <cstdint>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

using std::cout;
using std::endl;
using std::string;

using var_t = float;
using data_t = uint32_t;

std::vector<var_t> args;
std::vector<data_t> stack;

const string operators = "+-*/^!sc";

enum OPERATOR : data_t {
    ADD,
    SUB,
    MUL,
    DIV,
    POW,
    NOT,
    SIN,
    COS,
    NA
};

var_t e_add(var_t a, var_t b) { return a + b; }
var_t e_sub(var_t a, var_t b) { return a - b; }
var_t e_mul(var_t a, var_t b) { return a * b; }
var_t e_div(var_t a, var_t b) { return a / b; }
var_t e_pow(var_t a, var_t b) { return powf(a, b); }
var_t e_not(var_t a, var_t b) { return !a; }
var_t e_sin(var_t a, var_t b) { return std::sin(a); }
var_t e_cos(var_t a, var_t b) { return std::cos(a); }

typedef var_t (*operation_t)(var_t, var_t);
operation_t operations[] = {e_add, e_sub, e_mul, e_div, e_pow, e_not, e_sin, e_cos};

size_t findCharSameLevel(const string& expr, const char* match) {
    size_t cnt{};

    for (auto c = expr.begin(); c != expr.end(); ++c) {
        if (*c == '(') {
            cnt++;
        }
        if (*c == ')') {
            cnt--;
        }
        if (*c == *match) {
            if (cnt == 0) {
                return c - expr.begin();
            }
        }
    }

    return expr.end() - expr.begin();
}

OPERATOR getOperator(const char op) {
    auto it = std::find(operators.begin(), operators.end(), op);
    return (OPERATOR)((data_t)(it - operators.begin()));
}

void pushToStack(const data_t val) {
    stack.push_back(val);
}

data_t pushArg(const var_t arg) {
    args.push_back(arg);
    return args.size() - 1;
}

data_t parse(const string& expr, int level) {
    OPERATOR op = getOperator(expr[0]);

    data_t pos;
    if (op != OPERATOR::NA) {
        if (expr[1] != '(') {
            cout << "oops. op = " << op << "; expr = " << expr << endl;
            throw std::runtime_error("token ( must follow operator");
        }
        auto end = findCharSameLevel(expr.substr(1, expr.size() - 1), ")");
        auto subexpr = expr.substr(2, end - 1);
        auto commaIdx = findCharSameLevel(subexpr, ",");
        data_t arg1Pos = parse(subexpr.substr(0, commaIdx), level + 1);
        data_t arg2Pos = parse(subexpr.substr(commaIdx + 1), level + 1);
        pushToStack((data_t)op);
        pushToStack(arg1Pos);
        pushToStack(arg2Pos);
        pos = pushArg((var_t)0);
        pushToStack(pos);

    } else {
        if (level == 0) {
            cout << "oops. op = " << op << "; expr = " << expr << endl;
            throw std::runtime_error("at top level first token must be an operator");
        }
        var_t arg = std::stof(expr);
        pos = pushArg(arg);
    }

    return pos;
}

var_t eval() {
    var_t res;
    auto stackPtr = stack.begin();
    while (stackPtr < stack.end()) {
        OPERATOR op = (OPERATOR)*stackPtr++;
        uint32_t arg1Pos = *stackPtr++;
        uint32_t arg2Pos = *stackPtr++;
        uint32_t outPos = *stackPtr++;

        auto func = operations[(data_t)op];
        args[outPos] = func(args[arg1Pos], args[arg2Pos]);
    }

    return args.back();
}

int main(int argc, char* argv[]) {
    std::string expr;
    if (argc < 2) {
        throw std::runtime_error("no expressio given");
    } else {
        expr.assign(argv[1]);
    }
    cout << "expression = " << expr << endl;

    parse(expr, 0);
    auto res = eval();
    cout << "result = " << res << endl;
    return 0;
}