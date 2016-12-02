#include <iostream>
#include <cstring>
#include "sort.h"
using namespace std;

/* 퀵 정렬(Quick Sort)
   
   퀵 정렬은 말 그대로 엄청나게 빠른 정렬 기법이라고 함.
   
   다른 정렬과는 달리 기준값을 하나 택하고 순회를 돌면서 기존값보다 작은 데이터는
   좌측에 기준값보다 큰 데이터는 우측으로 분할하고 다시 퀵 정렬을 적용한다고 함. 
*/


/* 쉽게 설명하면 첫값을 중간치에 세우고 그 놈이 기준! 외치면 그보다 작은 수는 왼쪽 반대로 큰 수는 오른쪽으로
   보내면 좌우 영역이 생기는데 각 영역에서 분할할 수 없을때까지 기준값을 택하고 그 분할과정을 반복하는 알고리즘 */

int partition(int arr[], int left, int right){
    int first = left;
    int pivot = arr[first];
    int temp = 0;
    
    ++left;
    
    while(left <= right){
        while(arr[left] <= pivot && left < right) ++left;
        while(arr[right] > pivot && left <= right) --right;
        
        if(left < right){
            temp = arr[left];
            arr[left] = arr[right];
            arr[right] = temp;
        }else break;
    }
    
    temp = arr[first];
    arr[first] = arr[right];
    arr[right] = temp;
    
    return right;
}
  
void QuickSort(int DataArray[], int left, int right){
    if(left < right){
        int index = partition(DataArray, left, right);
         
        QuickSort(DataArray, left, index-1);
        QuickSort(DataArray, index +1, right);
    }
}

void Sort::quick(){
    
    int * DataArray;
    int i = 0;
    int Length;

    cout << "선언할 배열크기 : ";
    cin >> Length;
    DataArray = (int*) malloc (sizeof(int)*Length);

    cout << endl << Length << "개의 배열 정수를 입력 : ";
    for(i=0; i<Length; i++) cin >> DataArray[i];
    
    QuickSort(DataArray, 0, Length-1);
  
    for(i=0; i<Length; i++) cout << i << ". DataArray : " << DataArray[i] << endl;
}