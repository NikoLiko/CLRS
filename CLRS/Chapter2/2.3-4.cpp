#include <iostream>
#include <vector>
#include <fstream>
using namespace std;
void INSERTION(vector <double> &a, int n)
{
    int index = n - 1;
    int key = a[n];
    while(a[index] > key && index >=0){
         a[index + 1] = a[index];
         index--;
    }
    a[index + 1] = key;
}
void INSERTION_SORT(vector <double> &a, int n)
{
    if (n > 0){
        n--;
        INSERTION_SORT(a,n);
        INSERTION(a,n);
    }
}

int main(void)
{
    ifstream in("E:\\testdata\\sample.txt");
    if (!in){
        cout << "打开文件失败！";
    }
    vector <double> vec_double;
    double num;
    while(in >> num){
        vec_double.push_back(num);
    }
    INSERTION_SORT(vec_double, vec_double.size() - 1);
    for (auto list_iter_i = vec_double.begin();list_iter_i != vec_double.end();list_iter_i++){
        cout << *list_iter_i << endl;
    }
    system("pause");
    return 0;
}