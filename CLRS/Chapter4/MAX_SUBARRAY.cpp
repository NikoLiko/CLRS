#include <iostream>
#include <fstream>
#include <vector>
#include <float.h>
using namespace std;
vector <int> FIND_MAX_CROSS_SUBARRAY(vector <int> &a,int low, int mid, int high)
{
    int left_sum = INT32_MIN;
    int right_sum= INT32_MIN;
    int max_left_index,max_right_index;
    for (int i = mid, sum = 0;i >= 0;i--){
        sum += a[i];
        if (sum >= left_sum){
            left_sum = sum;
            max_left_index = i;
        }
    }
    for (int j = mid + 1, sum = 0;j <= high;j++){
        sum += a[j];
        if (sum >= right_sum){
            right_sum = sum;
            max_right_index = j;
        }
    }  
    vector <int> cross;
    cross.push_back(max_left_index);
    cross.push_back(max_right_index);
    cross.push_back(left_sum + right_sum);
    return cross;
}
vector <int> FIND_MAX_SUBARRAY(vector <int> &a,int low,int high)
{
    vector <int> vec_int; 
    int mid;
    if (low == high){
        vec_int.push_back(low);
        vec_int.push_back(high);
        vec_int.push_back(a[low]);
        return vec_int;
    }else{
        mid = (low + high) / 2;
        vector <int> left = FIND_MAX_SUBARRAY(a, low, mid);
        vector <int> right = FIND_MAX_SUBARRAY(a, mid + 1,high);
        vector <int> cross = FIND_MAX_CROSS_SUBARRAY(a, low, mid, high);
        vector <int> last;
        if (left[2] >= right[2] && left[2] >= cross[2]){
            return left;
        }else if(right[2] >= left[2] && right[2] >= cross[2]){
            return right;
        }else{
            return cross;
        }
    }
}
int main(void)
{
    ifstream in("E:\\testdata\\sample.txt");
    if (!in){
        cout << "打开文件失败";
        exit(1);
    }
    vector <int> list_double;
    int num;
    while(in >> num){
        list_double.push_back(num);
    }
    vector <int> ans = FIND_MAX_SUBARRAY(list_double, 0, list_double.size() - 1);
    for (auto list_iter_i = ans.begin();list_iter_i != ans.end();list_iter_i++){
        cout << *list_iter_i << endl;
    }
    system("pause");
    return 0;
}
