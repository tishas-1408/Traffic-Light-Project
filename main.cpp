#include "mbed.h"

DigitalOut r1(p29);
DigitalOut y1(p28);
DigitalOut g1(p15);
DigitalOut r2(p27);
DigitalOut y2(p25);
DigitalOut g2(p24);
DigitalIn walk_in(p14);
DigitalOut redwalkman(p11);
DigitalOut greenwalkman(p12);

bool cross(float wait_time, bool request){
    for(int i=0; i<wait_time*10; i++){
        if( walk_in.read()==1)
            request=1;
        wait(0.100);
    }
    return request;

     }

int main() {
    bool request=0;
    r1=1;
    r2=1;
    redwalkman=1;
    greenwalkman=0;

  while(1) {
      y1=1;
      request= cross(2.0,request);

      y1=0;
      r1=0;
      g1=1;
      request= cross(10.0,request);

      g1=0;
      y1=1;
      request= cross(2.0,request);
      y1=0;
      r1=1;
    
      request= cross(2.0,request);

      if(request==1){
        redwalkman=0;
        greenwalkman=1;
        r2=1;
        wait(5.0);
        r2=0;
        redwalkman=1;
        greenwalkman=0;
        request=0;}

        y2=1;
        
      request= cross(2.0,request);
      y2=0;
      r2=0;
      g2=1;
      request= cross(10.0,request);

      g2=0;
      y2=1;
      request= cross(2.0,request);
       y2=0;
       r2=1;
      request= cross(0.25,request);

      if(request==1){
        redwalkman=0;
        greenwalkman=1;
        r1=1;
        wait(5.0);
        r1=0;
        redwalkman=1;
        greenwalkman=0;
        request=0;}
      

  }
}
