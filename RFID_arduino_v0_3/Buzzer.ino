
  // declaration de la broche du buzzer

const int pinBuzz = 4;
  
  // initialisation du buzz
  
void IniBuzzer()
  {
    pinMode(pinBuzz, OUTPUT);
    
    digitalWrite(pinBuzz, LOW);
    
  }
  
  /////////////////////////////////////////////////////////////////////
 //        definittion des notes
///////////////////////////////////////////////////////////////////

#define DO1    262
#define DOd1   277
#define RE1    294
#define REd1   311
#define MI1    330
#define FA1    349
#define FAd1   370
#define SOL1   392
#define SOLd1  415
#define LA1    440
#define LAd1   466
#define SI1    494

#define DO2    523
#define DOd2   554
#define RE2    587
#define REd2   622
#define MI2    659
#define FA2    698.5
#define FAd2   740
#define SOL2   784
#define SOLd2  831
#define LA2    880
#define LAd2   932
#define SI2    988

#define DO3    1046.5
#define DOd3   1109
#define RE3    1175
#define REd3   1244.5
#define MI3    1318.5
#define FA3    1397
#define FAd3   1480
#define SOL3   1568
#define SOLd3  1661
#define LA3    1760
#define LAd3   1865
#define SI3    1975

#define DO4    2033

#define Ro    500
#define Bl    250
#define No    175
#define Cr    64
#define Dc    32
#define Tc    16


  ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
 //          buzz ouverture
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// 
void buzz1() 
{
  long frequency = 1000;
  long length = 100;
  
  long delayValue = 1000000/frequency/2;
  long numCycles = frequency * length/ 1000;
  
  for (long i=0; i < numCycles; i++)
  {
    digitalWrite(pinBuzz, HIGH);
    delayMicroseconds(delayValue);
    digitalWrite(pinBuzz, LOW);
    delayMicroseconds(delayValue);
  }
}

  ///////////////////////////////////////////////////////////////////////////////////
 //        Buzz en cas d'echec d'authentification
////////////////////////////////////////////////////////////////////////////////////

void buzzEchec() 
{
  long frequency = 200;
  long length = 100;
  
  long delayValue = 1000000/frequency/2;
  long numCycles = frequency * length/ 1000;
  
  for (long i=0; i < numCycles; i++)
  {
    digitalWrite(pinBuzz, HIGH);
    delayMicroseconds(delayValue);
    digitalWrite(pinBuzz, LOW);
    delayMicroseconds(delayValue);
  }
}

  //////////////////////////////////////////////////////////////////////////////////////
 //          Buzz gamme montante
////////////////////////////////////////////////////////////////////////////////////
void buzzGamme() 
{
  long frequency = DO3;
  long length = 100;
  
  for(int trs=0; trs<=7 ; trs++)
  { 
    switch(trs)
    {
      case 0:
        frequency = DO2;
        break;
      case 1:
        frequency = RE2;
        break;
      case 2:
        frequency = MI2;
        break;
      case 3:
        frequency = FA2;
        break;
      case 4:
        frequency = SOL2;
        break;
      case 5:
        frequency = LA2;
        break;
      case 6:
        frequency = SI2;
        break;
      case 7:
        frequency = DO3;
        break;
    }
    
    long delayValue = 1000000/frequency/2;
    long numCycles = frequency * length/ 1000;
    
      for (long i=0; i < numCycles; i++)
      {
        digitalWrite(pinBuzz, HIGH);
        delayMicroseconds(delayValue);
        digitalWrite(pinBuzz, LOW);
        delayMicroseconds(delayValue);
      }   
        delay(50);
  }
}
  /////////////////////////////////////////////////////////////////////
 //      Buzz avec le theme de mario
////////////////////////////////////////////////////////////////////// 
void buzzMario() 
{
  long frequency = DO3;
  long length = 100;
  
  for(int trs=0; trs<=79 ; trs++)
  { 
    switch(trs)
    { //1
      case 0: frequency = MI3; delay(Dc); break;
      case 1: frequency = MI3; delay(Cr); break;
      case 2: frequency = MI3; delay(Cr);break;
      case 3: frequency = DO3; break;
      //2
      case 4: frequency = MI3; break;
      case 5: frequency = SOL3; break;
      case 6: frequency = SOL2; break;
      case 7: frequency = DO2; break;
      //3
      case 8: frequency = SOL2; break;
      case 9: frequency = MI2; break;
      case 10: frequency = LA2; break;
      case 11: frequency = SI2; break;
      //4
      case 12: frequency = LAd2; break;
      case 13: frequency = LA2; break;
      case 14: frequency = MI3; break;
      case 15: frequency = SOL3; break;
      //5
      case 16: frequency = LA3; break;
      case 17: frequency = FA3; break;
      case 18: frequency = SOL3; break;
      case 19: frequency = MI3; break;
      //6
      case 20: frequency = DO3; break;
      case 21: frequency = RE3; break;
      case 22: frequency = SI2; break;
      case 23: frequency = DO3; break;
      //
      case 24: frequency = SOL2; break;
      case 25: frequency = MI2; break;
      case 26: frequency = LA2; break;
      case 27: frequency = SI2; break;
      //8
      case 28: frequency = LAd2; break;
      case 29: frequency = LA2; break;
      case 30: frequency = MI3; break;
      case 31: frequency = SOL3; break;
      //9
      case 32: frequency = LA3; break;
      case 33: frequency = FA3; break;
      case 34: frequency = SOL3; break;
      case 35: frequency = MI3; break;
      //10
      case 36: frequency = DO3; break;
      case 37: frequency = RE3; break;
      case 38: frequency = SI2; break;
      case 39: frequency = DO3; break;
      //11
      case 40: frequency = SOL3; break;
      case 41: frequency = FAd3; break;
      case 42: frequency = FA3; break;
      case 43: frequency = REd3; break;
      //12
      case 44: frequency = MI3; break;
      case 45: frequency = SOLd2; break;
      case 46: frequency = LA2; break;
      case 47: frequency = DO3; break;
      //13
      case 48: frequency = LA2; break;
      case 49: frequency = DO3; break;
      case 50: frequency = RE3; break;
      case 51: ; break;
      //14
      case 52: frequency = SOL3; break;
      case 53: frequency = FAd3; break;
      case 54: frequency = FA3; break;
      case 55: frequency = REd3; break;
      //15
      case 56: frequency = MI3; break;
      case 57: frequency = DO4; break;
      case 58: frequency = DO4; break;
      case 59: frequency = DO4; break;
      //16
      case 60: frequency = SOL3; break;
      case 61: frequency = FAd2; break;
      case 62: frequency = FA3; break;
      case 63: frequency = REd3; break;
      //17
      case 64: frequency = MI3; break;
      case 65: frequency = SOLd2; break;
      case 66: frequency = LA2; break;
      case 67: frequency = DO3; break;
      //18
      case 68: frequency = LA2; break;
      case 69: frequency = DO3; break;
      case 70: frequency = RE2; break;
      case 71: frequency = REd3; break;
      //19
      case 72: frequency = RE3; break;
      case 73: frequency = DO3; break;
      case 74: ; break;
      case 75: ; break;
      //20
      case 76: ; break;
      case 77: ; break;
      case 78: ; break;
      case 79: ; break;
      
    }
       long delayValue = 1000000/frequency/2;
    long numCycles = frequency * length/ 1000;
    
      for (long i=0; i < numCycles; i++)
      {
        digitalWrite(pinBuzz, HIGH);
        delayMicroseconds(delayValue);
        digitalWrite(pinBuzz, LOW);
        delayMicroseconds(delayValue);
      }   
        delay(50);
  }
}


