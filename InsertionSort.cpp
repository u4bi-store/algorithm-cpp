#include <iostream>
#include <cstring>
#include "sort.h"
using namespace std;

/* 삽입 정렬(Insertion Sort)
   
   삽입 정렬은 간단히 말하면 정렬할 새로운 데이터를 뽑아 적당한 새 위치에 삽입하는 알고리즘이라고 할 수 있음.
   삽입 정렬도 버블 정렬과 마찬가지로 구현이 간단하여 많이 사용된다고 함.
*/

/* 쉽게 설명하면 앞놈 잡아서 앞놈보다 내가 더 크면 내가 앞줄서고 그애는 맨 뒤로 보내는 알고리즘*/
/* 삽입 정렬의 비교횟수는 버블 정렬보다 조금 더 나은면을 보인다고 함. 버블이 더 빠름*/

void InsertionSort(int DataArray[], int Length){
    
    int value = 0;
    
    for(int i=0; i< Length; i++){
        if(DataArray[i -1] <= DataArray[i]) continue;
        value = DataArray[i];
        
        for(int j=0; j< i; j++){
            if(DataArray[j]>value){
                /* memmove는 메모리 블럭을 옮기는 함수*/
                memmove(&DataArray[j+1], &DataArray[j], sizeof(DataArray[0]) * (i-j));
                DataArray[j] = value;
                break;
            }
        }
        
    }
  
}

void Sort::insertion(){

    int * DataArray;
    int i = 0;
    int Length;

    cout << "선언할 배열크기 : ";
    cin >> Length;
    DataArray = (int*) malloc (sizeof(int)*Length);

    cout << endl << Length << "개의 배열 정수를 입력 : ";
    for(i=0; i<Length; i++) cin >> DataArray[i];
    
    InsertionSort(DataArray, Length);
    for(i=0; i<Length; i++) cout << i << ". DataArray : " << DataArray[i] << endl;
}