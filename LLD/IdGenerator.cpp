#include<bits/stdc++.h>
using namespace std;


long long getCurrTime(){

     static  long long Faketime=100000;
      return Faketime++;
}

class UniqueIdGenerator{

private:
    long long lastTime;
    long long Counter;

public:

     UniqueIdGenerator(){ 

      lastTime= -1;
      Counter= 0;

     }

     long long GenerateId(){

      long long currTime =  getCurrTime();
      if(currTime == lastTime){
           Counter++;
      }else{
           Counter=0;
           lastTime=currTime;
      }
      currTime * 1000 + Counter;
      }

};
