// declaration des broches de sortie suplementaire

#include <SoftwareSerial.h>  // delclaration de la communication serial

// link between the computer and the SoftSerial Shield
//at 9600 bps 8-N-1
//Computer is connected to Hardware UART
//SoftSerial Shield is connected to the Software UART:D2&D3 


SoftwareSerial SoftSerial(3, 2);
unsigned char buffer[64]; // buffer array for data recieve over serial port
int count=0;     // counter for buffer array 

//initialisation des broche pour l'ecran lcd

 #include <ShiftLCD.h>

const int Horloge = 10;  // PWD obligatoire
const int Data = 11;    // PWD obligatoire
const int Verrou = 12; 

ShiftLCD LCD(Data,Horloge,Verrou);


// declaration des variable temps
long tempsouvert;
char memoireTemp;
//decalratio du Tableau RFID pour la verification des carte 
unsigned long memoireRFID;  // memoire des info envoyer par la RFID 
boolean verifPass;  //variable d'autorisation

//------------------------------------------------------------------------------------------------------------//

void setup()
{
  // Initialisation liaision serie
  SoftSerial.begin(9600);               // the SoftSerial baud rate   
  Serial.begin(9600);   // the Serial port of Arduino baud rate.
  
  // Initialisation du Buzzer
  IniBuzzer();

  // initialisation des commande moteur
  IniComMoteur();
  
  // Initialisation des capteur et des bouton de la portes
  IniCapteurBts();
  
  // initialisation de l'affichage
  IniAffichage();
  
  // Initialisation du temps Hrologe0
  genTemps();
  
}

//------------------------------------------------------------------------------------------------------------//

void loop()
{
  affichage();
  tempExt();
  
  if (SoftSerial.available())              // if date is comming from softwareserial port ==> data is comming from SoftSerial shield
  {
     //memoireRFID = SoftSerial.read();
      while(SoftSerial.available())          // reading data into char array 
      {
        buffer[count++]=SoftSerial.read();     // writing data into array
        if(count == 64)break;
      }

      Serial.write(buffer,count);            // if no data transmission ends, write buffer to hardware serial port
      clearBufferArray();              // call clearBufferArray function to clear the storaged data from the array
      count = 0; 
    
       // set counter of while loop to zer
  }
  
  if (Serial.available())      // if data is available on hardwareserial port ==> data is comming from PC or notebook
  {
    SoftSerial.write(Serial.read());       // write it to the SoftSerial shield
    ouvert();
  }
  
 
}

//------------------------------------------------------------------------------------------------------------//

void clearBufferArray()              // function to clear buffer array
{
    for (int i=0; i<count;i++)
    {
    buffer[i]=NULL;
    }                  // clear all index of array with command NULL
}

  /////////////////////////////////////////////
 //      Fonction echec 
/////////////////////////////////////////////

void echec()
{
 for(int e; e<3; e++)
  { 
  buzzEchec();
  }
} 
  /////////////////////////////////////////
 //      Fonction d'ouverture
/////////////////////////////////////////

void ouvert()
{
 
 int stopM = 1;
 tempsouvert = millis(); 
  
 // affOuvert();  // Affichage sur l'ecran LCD de "Ouverture en cour ... " et OUVERT.
 
  if(stopM = 1)
    {

      buzz1; // buzz sur pin 9 à 2500Hz 
    }
    
    if((millis()-tempsouvert) == 500)
    {

    }
}
   ////////////////////////////////////////
  //fonction vermeture
 /////////////////////////////////////////
 
 void fermer()
 {
 
 }
 
