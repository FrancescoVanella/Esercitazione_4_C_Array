#include "Utils.hpp"
#include <fstream>
#include <sstream>

using namespace std;


bool ImportData( string& inputFileName,
                int& n,
                double& S,
                double*& r,
                double*& w)
{
    ifstream file;
    file.open(inputFileName);

    if (file.fail())
    {
        cerr<< "file open failed"<< endl;
        return false;
    }

    string line;
    char jump;

    file.get(jump);
    file.get(jump);

    getline(file, line);
    istringstream convert;
    convert.str(line);
    convert >> S;

    file.get(jump);
    file.get(jump);

    getline(file, line);
    istringstream convert1;
    convert1.str(line);
    convert1 >> n;

    getline(file, line);


    r = new double[n];
    w = new double[n];


    for (int i = 0; i < n; i++)
    {
        getline(file, line);
        istringstream convert2;
        convert2.str(line);
        convert2 >> *(w+i) >> jump >> r[i];
    }

    file.close();

    return true;
}

void RateofReturn_FinalValue(int& n,
                             double& S,
                             double*& r,
                             double*& w,
                             double& V,
                             double& rate)
    {
    V = S;
    for (int i = 0; i < n; i++)
        {
        V += w[i]*r[i]*S;
        }

    rate = (V - S)/S;

}

bool ExportData(string& outputFileName,
                    int& n,
                    double& S,
                    double*& r,
                    double*& w,
                    double& V,
                    double& rate)
{
        ofstream file;
        file.open(outputFileName);
        if (file.fail())
        {
            cerr<< "file open failed"<< endl;
            return false;
        }

        file << "S = " << S << ", n = " << n << endl;
        file << "w = [ ";
        for (int i = 0; i < n; i++)
        {
            file << w[i] << " ";
        }
        file << "]" << endl;

        file << "r = [ ";
        for (int i = 0; i < n; i++)
        {
            file << r[i] << " ";
        }
        file << "]" << endl;
        file << "Rate of return of the portfolio: " << rate << endl;
        file << "V: " << V << endl;

        file.close();
        return true;


}
