#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "MyAlgorithm.hpp"
#include <vector>
using namespace std;

int main()
{
    //vector<int> vec = { 1,6,4,3,2 };
    string vec = "1858246278985532133";
    quickSort2(vec, 0, vec.size() - 1);
    for (auto i : vec) cout << i << endl;
    system("Pause");
    return 0;
}
