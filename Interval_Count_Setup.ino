/*
 * Project Interval_Count_Setup
 * Description:  Setup File with Timed interval with counter subinterval
 * Author:  Patrick Bolton 
 * Date:  05/14/21 start
 */

#include "Particle.h"
#include "math.h"

SYSTEM_THREAD(ENABLED);

#define dbSerial Serial

SerialLogHandler logHandler;

#define UPDATE_INTERVAL 5000  //1 sec = 1000 millis
#define UPDATE_COUNTMAX 10

unsigned long UpdateInterval;
int updatecount;

void setup() 
{
  dbSerial.begin(9600);

  UpdateInterval = millis();
  updatecount=0;
}

void loop()
{
  if ((millis() - UpdateInterval) > UPDATE_INTERVAL)
  {
   
    if(updatecount==UPDATE_COUNTMAX){updatecount=0;}
    
    else{updatecount++;}
    
    UpdateInterval = millis();
  }
}