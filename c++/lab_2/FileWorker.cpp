#include <vector>
#include <fstream>
#include <type_traits>
#include <iostream>

class FileWorker
{
    std::ifstream file;
public:
    std::vector<double> ReadFromFile(std::string fileName)
    {
        std::vector<double> v;
        file.open(fileName);
        if (!file.is_open())
            throw std::exception();
        double number;

        while (file >> number)
        {
            v.push_back(number);
        }

        file.close();

        return v;
    }

    template <typename T>
    void WriteToFile(T res, std::string outfileName = "log.txt")
    {
        if (std::is_same<decltype(res), std::vector<double>>::value)
        {
        }

        if (std::is_same<decltype(res), double>::value)
        {
            std::ofstream outfile("out/"+outfileName);
            if (!outfile.is_open())
            throw std::exception();
            outfile << res;
            outfile.close();

        }
    }
};