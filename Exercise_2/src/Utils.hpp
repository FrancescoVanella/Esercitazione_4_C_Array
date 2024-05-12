#pragma once
#include <iostream>
using namespace std;


bool ImportData(string& inputFileName,
                 int& n,
                double& S,
                double*& r,
                double*& w);

void RateofReturn_FinalValue( int& n,
                             double& S,
                             double*& r,
                             double*& w,
                             double& V,
                             double& rate);

bool ExportData( string& outputFileName,
                int& n,
                double& S,
                double*& r,
                double*& w,
                double& V,
                double& rate);
