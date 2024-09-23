#include <iostream>
#include "CalcProblemParams.cpp"
#include "FileWorker.cpp"
#include "CalcProblem.cpp"

using namespace std;

int main(int argc, char **argv)
{
    if (argc == 1)
    {
        cout << "Enter command line arguments" << '\n';
        return -1;
    }

    CalcProblemParams P(argv);
    FileWorker FW;
    std::vector<double> v1;
    std::vector<double> v2;

    try
    {
        v1 = FW.ReadFromFile(P.filePath1);
        v2 = FW.ReadFromFile(P.filePath2);
    }

    catch (const std::exception &)
    {
        std::cerr << "err reading file" << '\n';
    }

    CalcProblem CP;

    switch (*argv[6])
    {
    case char(Operations::vv_sum):
        FW.WriteToFile(CP.VectorSum(v1, v2));
        break;

    case char(Operations::vv_subtr):
        FW.WriteToFile(CP.VectorSubtr(v1, v2));
        break;

    case char(Operations::vv_scmult):
        FW.WriteToFile(CP.VectorScalarMult(v1, v2));
        break;

    default:
        std::cerr << "Unknown operation!" << '\n';
        return -1;
    }
}