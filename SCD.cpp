#include <iostream>
#include <string>
#include <cctype>
#include <stdexcept>
#include <sstream>

using namespace std;

class Parser {
public:
    double parse(const string& expression) {
        input = expression;
        pos = 0;
        return parseExpression();
    }

private:
    string input;
    size_t pos;

    void skipWhitespace() {
        while (pos < input.size() && isspace(input[pos])) {
            pos++;
        }
    }

    char peek() {
        skipWhitespace();
        return pos < input.size() ? input[pos] : '\0';
    }

    char consume() {
        skipWhitespace();
        return pos < input.size() ? input[pos++] : '\0';
    }

    double parseNumber() {
        skipWhitespace();
        size_t start = pos;
        while (pos < input.size() && (isdigit(input[pos]) || input[pos] == '.')) {
            pos++;
        }
        string numStr = input.substr(start, pos - start);
        try {
            return stod(numStr);
        } catch (const invalid_argument&) {
            throw runtime_error("Invalid number: " + numStr);
        }
    }

    double parseFactor() {
        char next = peek();
        if (next == '(') {
            consume(); // eat '('
            double result = parseExpression();
            if (peek() != ')') {
                throw runtime_error("Expected ')'");
            }
            consume(); // eat ')'
            return result;
        } else if (next == '+' || next == '-') {
            consume(); // eat unary operator
            double operand = parseFactor();
            return next == '+' ? operand : -operand;
        } else if (isdigit(next) || next == '.') {
            return parseNumber();
        } else {
            throw runtime_error("Unexpected character: " + string(1, next));
        }
    }

    double parseTerm() {
        double result = parseFactor();
        while (true) {
            char op = peek();
            if (op == '*' || op == '/') {
                consume();
                double rhs = parseFactor();
                if (op == '*') {
                    result *= rhs;
                } else {
                    if (rhs == 0) {
                        throw runtime_error("Division by zero");
                    }
                    result /= rhs;
                }
            } else {
                break;
            }
        }
        return result;
    }

    double parseExpression() {
        double result = parseTerm();
        while (true) {
            char op = peek();
            if (op == '+' || op == '-') {
                consume();
                double rhs = parseTerm();
                if (op == '+') {
                    result += rhs;
                } else {
                    result -= rhs;
                }
            } else {
                break;
            }
        }
        return result;
    }
};

int main() {
    Parser parser;
    string line;

    cout << "Simple Arithmetic Expression Compiler" << endl;
    cout << "Enter expressions to evaluate (or 'exit' to quit)" << endl;

    while (true) {
        cout << "> ";
        getline(cin, line);
        if (line == "exit") break;

        try {
            double result = parser.parse(line);
            cout << "Result: " << result << endl;
        } catch (const exception& e) {
            cerr << "Error: " << e.what() << endl;
        }
    }

    return 0;
}
