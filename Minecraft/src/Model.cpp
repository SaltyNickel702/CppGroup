#include "Model.h"

#include <iostream>
using namespace std;

Model::Model (float v[], int i[], float attr[]) {
    vertices = v;
    indices = i;

    totalIndices = sizeof(i)/sizeof(int);

    

    cout << totalIndices << endl;
}