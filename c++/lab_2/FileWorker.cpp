#include<vector>
#include<fstream>
#include <iostream>

class FileWorker {
    std::ifstream file;
    public:
    FileWorker(){
    }

    std::vector<double> readFromFile(std::string fileName) {
        std::vector<double> v;
        file.open(fileName);
        if (!file.is_open()) std::cout << "not opened";
        double number;

        while (file >> number) {
            v.push_back(number);
        }

        file.close();

        return v;

    }
};