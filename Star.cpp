#include <iostream>
#include <cstring>
#include "star.h"
using namespace std;

void triangleA(){
    int c, l; /*c = column l = low*/
    
    for(c=0; c < 5; c++){ /* 첫 포문의 시작점은 0부터 시작되며 5까지 c++됨 */
        for(l=0; l<=c; l++) cout << c; /* 즉 첫 포문이 돌때 내부 포문의 랭쓰는 0 같거나 더높을때까지니 별이 하나만 찍힘 */ 
        cout << endl; /* 한 포문 끝내고 endl 먹힘*/
      
      /* 그 후 도입 포문의 두번째번이 도는데 내부 포문의 랭쓰(c)는 당연히 1다.
         따라서 별이 두개가 찍힘. */
    }
  
  /* 
     이 과정을 반복. 도입 포문의 랭쓰만큼 진행 됨.
     
     0루프 : *
     1루프 : **
     2루프 : ***
     3루프 : ****
     4루프 : *****
  */
}

void triangleB(){
    int c, l; /*c = column l = low*/
    
    for(c=4; c>=0; c--){ /* 첫 포문의 시작점은 4부터 시작되며 0일때까지 c--됨 */
        for(l=0; l<=c; l++) cout << c; /* 첫 포문이 돌때 내부 포문의 랭쓰는 4 같거나 더높을때까지니 별이 다섯개가 찍힘*/
        cout << endl; /* 한 포문 끝내고 endl 먹힘*/
      
      /* 그 후 도입 포문의 두번째번이 도는데 내부 포문의 랭쓰(c)는 당연히 3이다.
         따라서 별이 4개가 찍힘. */
    }
  
  /*
     이 과정을 반복. 도입 포문의 랭쓰만큼 진행됨
     
     4루프 : *****
     3루프 : ****
     2루프 : ***
     1루프 : **
     0루프 : *
  */
}

void triangleC(){
    int c, l; /*c = column l = low*/
    
    for(c=0; c<5; c++){ /* 첫 포문의 시작점은 0부터 시작되며 5까지 c++됨 */
        for(l=0; l<4-c; l++) cout << " "; /* 즉 첫 포문이 돌때 내부 포문의 랭쓰는 4까지니 (4-현재루프c값) 즉 공백이 네번 찍힘 */
        for(l=0; l<=c; l++) cout << c;    /* 그 후 포문의 랭쓰는 0 같거나 더높을때까지니 즉 별이 하나만 찍힘 */
        cout << endl; /* 한 포문 끝내고 endl 먹힘*/
      
      /* 그 후 도입 포문의 두번째번이 도는데 내부 포문의 랭쓰(c)는 당연히 1이다.
         따라서 공백이 3개가 찍히고 별이 2개가 찍힌다. */
    }

  /*
     이 과정을 반복. 도입 포문의 랭쓰만큼 진행됨
     
     4루프 :     *
     3루프 :    **
     2루프 :   ***
     1루프 :  ****
     0루프 : *****
  */
}

void triangleD(){
    int c, l; /*c = column l = low*/
    
    for(c=4; c>=0; c--){ /* 첫 포문의 시작점은 4부터 시작되며 0일때까지 c--됨 */
        for(l=0; l<4-c; l++) cout << " "; /* 즉 첫 포문이 돌때 내부 포문의 랭쓰는 0까지니 (4-현재루프c값) 즉 공백이 0번 찍힘 */
        for(l=0; l<=c; l++) cout << c;    /* 그 후 포문의 랭쓰는 4 같거나 더높을때까지니 즉 별이 다섯개가 찍힘 */
        cout << endl; /* 한 포문 끝내고 endl 먹힘*/
      
      /* 그 후 도입 포문의 두번째번이 도는데 내부 포문의 랭쓰(c)는 당연히 1이다.
         따라서 공백이 3개가 찍히고 별이 2개가 찍힌다. */
    }
  
  /*
     이 과정을 반복. 도입 포문의 랭쓰만큼 진행됨
     
     4루프 : *****
     3루프 :  ****
     2루프 :   ***
     1루프 :    **
     0루프 :     *
  */
}

void Star::triangle(int type){
    switch(type){
        case 0: triangleA(); break;
        case 1: triangleB(); break;
        case 2: triangleC(); break;
        case 3: triangleD(); break;
        default:break;
    }
}

void Star::pyramid(){
    
}

void Star::diamond(){
    
}