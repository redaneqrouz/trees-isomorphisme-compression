/*
 * Matrix.h
 *
 *  Created on: 18/03/2018
 *      Author: reda 
 */
#include "Matrix.h"  

    Matrix::Matrix(const string & filename) {
  
    ifstream inFile(filename.c_str());
    string inLine;
    while(getline(inFile, inLine)) {
      istringstream inLineStream(inLine);
      vector<int> inLineData(
        (istream_iterator<int>(inLineStream)),istream_iterator<int>());
      data.push_back(inLineData);       
    }
}


void Matrix::show()
{
 vector <vector <int>> vect = myMatrix();
 for(const auto & a:vect)
        {
            for(const auto & b: a)
                cout << " " << b;
        cout << "\n";
        }
}
