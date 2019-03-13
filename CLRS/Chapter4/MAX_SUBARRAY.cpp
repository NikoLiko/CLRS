#include <iostream>
#include <fstream>
#include <vector>
#include <float.h>
using namespace std;
void FIND_MAX_CROSS_SUBARRAY(vector <int> &a,int low, int mid, int high)
{
    int left_sum = INT32_MIN;
    int right_sum= INT32_MIN;
    int max_left_index,max_right_index;
    int sum = 0;
    for (int i = mid;i >= 0;i--){
        sum += a[i];
        if (sum >= left_sum){
            left_sum = sum;
            max_left_index = i;
        }
    }
    for (int j = mid + 1;j <= high;j++){
        sum += a[j];
        if (sum >= left_sum){
            right_sum = sum;
            max_right_index = j;
        }
    }
    
}
