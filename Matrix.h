/*
 * Matrix.h
 *
 *  Created on: 18/03/2018
 *      Author: reda 
 */

#include "libs.h"
class Matrix {
private:
  vector<vector<int>> data;
public:
  Matrix(const string & filename);
  void show();

inline vector<vector<int>> myMatrix()
{
return data;
}

};


