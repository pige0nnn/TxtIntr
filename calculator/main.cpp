#include <iostream>
#include <string>
#include <vector>
#include <numeric>

void printHelp(const char* name) {
    std::cout << "Usage: " << name << " -o <operation> <num1> <num2> ... <numN>\n"
              << "Operations: summa|sum, subtract|sub\n"
              << "Operands: 3 to 5 numbers\n";
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printHelp(argv[0]);
        return 1;
    }

    std::string op;
    std::vector<double> nums;

    for (int i = 1; i < argc; ++i) {
        std::string arg = argv[i];
        if (arg == "-h" || arg == "--help") {
            printHelp(argv[0]);
            return 0;
        }
        else if (arg == "-o" || arg == "--operation") {
            if (i + 1 < argc) op = argv[++i];
        }
        else {
            try {
                nums.push_back(std::stod(arg));
            } catch (...) {
                std::cerr << "Error: '" << arg << "' is not a number\n";
                return 1;
            }
        }
    }

    if (op.empty()) {
        std::cerr << "Error: operation not specified (-o)\n";
        return 1;
    }

    // Вариант 2: от 3 до 5 операндов
    if (nums.size() < 3 || nums.size() > 5) {
        std::cerr << "Error: expected 3 to 5 operands, got " << nums.size() << "\n";
        return 1;
    }

    double result;
    if (op == "summa" || op == "sum") {
        result = std::accumulate(nums.begin(), nums.end(), 0.0);
    }
    else if (op == "subtract" || op == "sub") {
        result = nums[0];
        for (size_t i = 1; i < nums.size(); ++i) result -= nums[i];
    }
    else {
        std::cerr << "Error: unknown operation '" << op << "'\n";
        return 1;
    }

    std::cout << "Result: " << result << "\n";
    return 0;
}
