#include <iostream>
#include <cstring>
#include "sort.h"
using namespace std;

/* 버블 정렬(Bubble Sort)
   
   버블 정렬은 정렬 알고리즘 중 활용도가 높은 알고리즘임.
   구현도 쉽게 가능하고 많은 개발자가 즐겨쓰는 알고리즘이라고 함.
   
   버블 정렬은 데이터를 차례대로 정렬하는 과정이 수중 거품의 움직임과 유사해 거품 정렬이라고 한다고함.
*/


/* 쉽게 설명하면 앞놈 잡아서 앞놈보다 내가 더 크면 내가 앞에 서는 알고리즘 이 과정을 되새김질 */

/* 예를 들어 84 69 76 86 94 91 수가 있음.
  
  첫번째 일어날 일은 :
                  84가 69랑 비교해서 84가 더 크면 자리 바꿈
  두번째 일어날 일은 :
                  84가 76이랑 비교해서 84가 더 크니 자리 바꿈
  세번째 일어날 일은 :
                  84가 86이랑 비교해서 84가 더 작으니 자리 못바꾸고 바톤 터치
  네번째 일어날 일은 :
                  86이 94랑 비교해서 86이 더 작으니 자리 못바꾸고 바톤 터치
  
  현재까지 중간 배열 원소들 중간점검: 69 76 84 86 94 91
  
  다섯번째 일어날 일은 :
                   94가 91이랑 비교해서 94가 더 크니 바톤 터치
  
  현재 배열 내 원소들 점검 :  69 76 84 86 91 94
*/

void BubbleSort(int DataArray[], int Length){
    int i = 0, j = 0, temp =0;
    for (i=0; i<Length-1; i++){
        for (j=0; j<Length-(i+1); j++){
            if (DataArray[j]>DataArray[j+1]) {
                temp = DataArray[j+1];
                DataArray[j+1] = DataArray[j];
                DataArray[j] = temp;    
            }
        }
    }
}

void Sort::bubble(){
    int * DataArray;
    int i = 0;
    int Length;
    
    cout << "선언할 배열크기 : ";
    cin >> Length;
    DataArray = (int*) malloc (sizeof(int)*Length);
  
    cout << endl << Length << "개의 배열 정수를 입력 : ";
    for(i=0; i<Length; i++) cin >> DataArray[i];
      
    BubbleSort(DataArray, Length);
    
    for(i=0; i<Length; i++) cout << i << ". DataArray : " << DataArray[i] << endl;
}