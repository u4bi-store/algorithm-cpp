#include <iostream>
#include <cstring>
#include "sort.h"
using namespace std;

/* 삽입 정렬(Insertion Sort)
   
   삽입 정렬은 간단히 말하면 정렬할 새로운 데이터를 뽑아 적당한 새 위치에 삽입하는 알고리즘이라고 할 수 있음.
   삽입 정렬도 버블 정렬과 마찬가지로 구현이 간단하여 많이 사용된다고 함.*/


/* 쉽게 설명하면 앞놈 잡아서 앞놈보다 내가 더 크면 내가 앞줄서고 그애는 맨 뒤로 보내는 알고리즘*/
/* 삽입 정렬의 비교횟수는 버블 정렬보다 조금 더 나은면을 보인다고 함. 버블이 더 빠름*/

/* 예를 들어 84 89 42 2 54 21 수가 있음.

   첫번째 일어날 일은 : 
                   84가 89랑 비교해서 84가 더 작으니 자리 못 바꾸고 바톤 터치
   두번째 일어날 일은 :
                   89가 42랑 비교해서 89가 더 크니 42를 맨 앞으로 보냄
   세번째 일어날 일은 : 
                   89가 2랑 비교해서 89가 더 크니 2를 맨 앞으로 보냄
   네번째 일어날 일은 : 
                   89가 54 비교해서 89가 더 크니 54를 맨 앞으로 보냄
                   맨 앞으로 보내려는데
                   54가 맨앞(2)보다 큼
                   그럼 둘째 둘째(42)보다 큼
                   그럼 셋째 셋째(84) 알맞음 그럼 거기서 셋째(84) 앞에 섬
                   
                   
   현재까지 중간 배열 원소들 중간점검 : 2 42 54 84 89 21
   
   다섯번째 일어날 일은 : 89가 21이랑 비교해서 89가 더 크니 21을 맨 앞으로 보냄
        맨 앞으로 보내려는데
        21이 맨앞(2)보다 큼
        그럼 둘째 둘째(42) 알맞음 그럼 거기서 둘째(42) 앞에 섬
        
        컨티뉴문으로 적당 자리 찾아감 
   
   현재 배열 내 원소들 점검 : 2 21 42 54 84 89
        여기서 버블이랑 달라짐. 수에 따라 버블과 삽입 둘다 각기 장점이 있음
*/
void InsertionSort(int DataArray[], int Length){
    
    int value = 0;
    
    for(int i=0; i< Length; i++){
        /* 첫포문으로 들어간 후 조건을 봄*/
        if(DataArray[i -1] <= DataArray[i]) continue;
        /* 전자가 후자보다 작거나 같을 때 컨티뉴*/
        value = DataArray[i]; /* 만약 아니라면 후자값을 value에 주입함*/
        
        for(int j=0; j< i; j++){
            /* 그 후 내부 포문 첫포문 수까지*/
            if(DataArray[j]>value){ /* value보다 큰 원소를 찾아냄*/
                /* memmove는 메모리 블럭을 옮기는 함수*/
                memmove(&DataArray[j+1], &DataArray[j], sizeof(DataArray[0]) * (i-j));
                /* 위 문장을 해석하면
                   
                   김아무개 = sizeof(DataArray[0]) 곱하기 (i-j)
                   
                   &DataArray[j+1] 부터 (김아무개)만큼 &DataArray[j+1]로 이동한다는 말임
                */
                DataArray[j] = value; /*value에 주입된 값은 DataArray[j]에 주입됨 */
                break;
            }
        }
        /* 그 후 첫 포문으로 돌아가서 반복*/
        
    }
    /* 반복할게 없으면 루프 빠져나감*/
  
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