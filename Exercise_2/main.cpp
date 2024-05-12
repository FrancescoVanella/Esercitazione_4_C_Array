#include "Utils.hpp"

#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;



int main()
{
    string inputFileName = "./data.csv";
    string outputFileName = "./result.txt";
    int n;
    double S, V = 0, rate = 0;
    double *r = nullptr;
    double *w = nullptr;
    if (!ImportData(inputFileName, n, S, r, w))
    {
        cerr << "Something goes wrong with import" << endl;
        return -1;
    }
    else
        cout << "Import successfull" << endl;
    RateofReturn_FinalValue(n, S, r, w, V, rate);


    if (!ExportData(outputFileName, n, S, r, w, V, rate))
    {
        cerr << "Something goes wrong with import" << endl;
        return -1;
    }
    else
        cout << "Export successfull" << endl;

    delete[] r;
    delete[] w;

    cout << "Value = " << V << endl;
    cout << "Rate = " << rate << endl;

    return 0;
}

