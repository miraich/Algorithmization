#include <vector>
#include <string>

#include"Operations.cpp"

struct CalcProblemParams {
    std::string filePath1;
    std::string filePath2;
    std::vector<std::string> filepaths;
    Operations op;
};