#include <iostream>
#include <vector>
#include <fstream>
using namespace std;
int main(void)
{
    ifstream in("E:\\testdata\\sort.txt");
    vector<double> vec_double;
    double num;
    double temp;
    while (in >> num){
        vec_double.push_back(num);
    }
    double min;
    for (int i = 0;i <= vec_double.size() - 2;i++){
        min = vec_double[i];
        for(int j = i + 1;j <= vec_double.size() - 1;j++){
            if (vec_double[j] < min){
                min = vec_double[j];
                temp = vec_double[i];
                vec_double[i] = vec_double[j];
                vec_double[j] = temp;
            }
        }
    }
    for (auto list_iter_i = vec_double.begin();list_iter_i != vec_double.end();list_iter_i++){
        cout << *list_iter_i << endl;
    }
    system("pause");
    return 0;
}