#include <iostream>
#include <vector>
#include <fstream>
#include <float.h>
using namespace std;
void merge(vector <double> &a, int p, int q, int r)
{
    int n1 = q - p + 1;
    int n2 = r - q;
    vector <double> vec_a;
    int index_p = p;
    int index_q = q;
    for (int i = 0;i < n1;i++){
        vec_a.push_back(a[index_p]);
        index_p++;
    }
    vector <double> vec_b;
    for (int i = 0;i < n2;i++){
        vec_b.push_back(a[index_q + 1]);
        index_q++;
    }
    vec_a.push_back(DBL_MAX);
    vec_b.push_back(DBL_MAX);
    int i = 0;
    int j = 0;
    for (int index = p;index <= r;index++){
        if(vec_a[i] < vec_b[j]){
            a[index] = vec_a[i];
            i++;
        }else{
            a[index] = vec_b[j];
            j++;
        }
    }
}
void merge_sort(vector <double> &a, int p, int r)
{
    if (p < r){
        int q = (p + r) / 2;
        merge_sort(a, p, q);
        merge_sort(a, q + 1, r);
        merge(a, p, q, r);
    }
}
int main(void)
{
    vector <double> vec_dou;
    ifstream in("E:\\testdata\\sort.txt");
    if (!in){
        cout << "打开文件失败";
        exit(1);
    }
    double num;
    while (in >> num){
        vec_dou.push_back(num);
    }
    merge_sort(vec_dou, 0, vec_dou.size() - 1);
    for (auto list_iter_i = vec_dou.begin();list_iter_i != vec_dou.end();list_iter_i++){
        cout << *list_iter_i << endl;
    }
    system("pause");
    return 0;
}
