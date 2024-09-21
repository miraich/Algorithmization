#include <iostream>
#include "CalcProblemParams.cpp"
#include "FileWorker.cpp"

using namespace std;


int main(int argc, char** argv)
{

    // for (int i = 1; i <= argc; i++) {
    //     cout << argv[i];
    // }

    CalcProblemParams P;
    P.filePath1 = argv[2];
    P.filePath2 = argv[4];
    P.filepaths.push_back(P.filePath1);
    P.filepaths.push_back(P.filePath2);  

    FileWorker W;
    std::vector<double> v1 = W.readFromFile(P.filePath1);
    std::vector<double> v2 = W.readFromFile(P.filePath2);

    switch (P.op) {
        case Operations::vv_sum:
            cout << "sum";

    }

    // CalcProblem Cp;
    // Cp.VectorSum();

    // for (double i: v) {
    //     cout << i << ' ';
    // }

	
}