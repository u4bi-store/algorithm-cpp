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

/* 예를 들어 84 69 76 86 94 91 수가 있음.

   첫번째 일어날 일은 :
                   84가 끝자리(91)이랑 비교해서 91이 더 크니 그냥 들어감 
   첫번째 일어날 일은 :
                   84가 94랑 비교해서 비교해서 94가 더 크니 그냥 들어감
   첫번째 일어날 일은 :
                   84가 86이랑 비교해서 86이 더 크니 그냥 들어감
   첫번째 일어날 일은 :
                   84가 76이랑 비교해서 76이 더 작으니 왼쪽으로 빠짐
                   
   현재까지 배열 원소들 중간점검 : 76 84 69 86 94 91
   
   다섯번째 일어날 일은 :
                    84가 69랑 비교해서 69가 더 작으니 왼쪽으로 감
                    
   현재 배열 내 원소들 점검 : 69 76 84 86 94 91
   
   더이상 분할할 수 없으니 자! 이제 첫자리 84가 중간 기준이 되었다.
   
   A그룹 : 69 76             B그룹 : 86 94 91
   
   첫번째 일어날 일은 :
                   69가 76이랑 비교해서 76이 더 크니 그냥 들어감 A그룹 끝
   두번째 일어날 일은 :
                   86이 91이랑 비교해서 91이 더 크니 그냥 들어감
                   86이 94랑 비교해서 94가 더 크니 그냥 들어감 B그룹 끝
    
   현재까지 배열 원소들 중간점검 : 69 76 84 86 94 91
    
   이제 86이 기준이 되었다!
   
   A그룹 : 없음               B그룹 : 94 91
   
   첫번째 일어날 일은 :
                   94가 91이랑 비교해서 91이 더 작으니 왼쪽으로 감 B그룹 끝
   
   현재까지 배열 내 원소들 점검 : 69 76 84 86 91 94
   
   
   QuickSort함수는 QuickSort내에서 다시 QuickSort함수를 재귀 호출하는데
   이때 첫자리가 끝자리보다 크거나 같으면 더이상 호출되지 않음
   
   그리고 partition 함수가 호출되면 정렬된 데이터의 첫번째 요소를 기준값으로 정함.
   그후 while문으로 인해서 분할이 되고 분할이 끝나면 right의 값을 반환하게 됨
   
   반환값은 좌우 그릅 인덱스로 재귀
*/
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