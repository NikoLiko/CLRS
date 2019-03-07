#include <iostream>
#include <vector>
#include <list>
#include <fstream>
using namespace std;
int main(void)
{
    ifstream in("E:\\testdata\\sort.txt");
    if (!in){
        cout << "打开文件失败";
        exit(1);
    }
    vector <double> list_double;
    double num;
    while(in >> num){
        list_double.push_back(num);
    }
    for (auto list_iter_j = list_double.begin()++;list_iter_j != list_double.end(); list_iter_j++){
        auto list_iter_i = list_iter_j - 1;
        double key = (*list_iter_j);
        while (list_iter_i > list_double.begin() && *(list_iter_i) > *(list_iter_j)){
            *(list_iter_i++) = *(list_iter_i);
            list_iter_i--;
        }
        *(list_iter_i) = key;
    }
    for (auto list_iter_i = list_double.begin();list_iter_i != list_double.end();list_iter_i++){
        cout << *list_iter_i << endl;
    }
    return 0;
}
