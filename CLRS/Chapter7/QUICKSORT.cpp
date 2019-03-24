#include <iostream>
#include <vector>
#include <fstream>
using namespace std;
int PARTITION(vector <double> &a,int p, int r)
{
    double key = a[r];
    int i = p - 1;
    for (int j = p;j <= r - 1; j++){
        if (a[j] <= key){
            i = i + 1;
            double temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    }
    double temp1 = a[i + 1];
    a[i + 1] = a[r];
    a[r] = temp1;
    return i + 1;
}
void QUICK_SORT(vector <double> &a,int p, int r)
{
    if (p < r){
        int q = PARTITION(a, p, r);
        QUICK_SORT(a, p, q - 1);
        QUICK_SORT(a, q + 1,r);
    }
}
int main(void)
{
    ifstream in("E:\\testdata\\sort.txt");
    vector<double> vec_double;
    double num;
    while (in >> num){
        vec_double.push_back(num);
    }
    QUICK_SORT(vec_double,0,vec_double.size() - 1);
    for (auto list_iter_i = vec_double.begin();list_iter_i != vec_double.end();list_iter_i++){
        cout << *list_iter_i << endl;
    }
    system("pause");
    return 0;
}