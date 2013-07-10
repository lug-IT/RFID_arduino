/*********************************************************************************************/
/*    Commande Moteur pas à pas                                                              */
/*                                                                                           */ 
/*    materiel : Moteur type NEMA 17, 2.8V, 200 Pas, bipolaire                               */
/*                                                                                           */
/*    Source : http://arduino103.blogspot.fr/2012/10/l293d-commander-des-moteurs-depuis.html */
/*             http://mchobby.be/wiki/index.php?title=Pont-H_L293D                           */
/*********************************************************************************************/ 

//inclusion des librairies
  
#include <Stepper.h>

  //librairie des moteur pas à pas pour Arduino

// declaration des broches

const int Pas1 = 5; 
const int Pas2 = 6;
const int Pas3 = 7;
const int Pas4 = 8;

// Declaretion des varibles

    // Variable moteur

int nombresPas;  // Nombre de Pas dans une rotation
int vitesseRot;  // vitesse de rotation en tour par minutes

long PasMax;  // nombre maximum


Stepper moteur(nombresPas,Pas1,Pas2,Pas3,Pas4);


  /////////////////////////////////////////////////////////////////////////////////
 //      Initialisation de la commande moteur
////////////////////////////////////////////////////////////////////////////////

void IniComMoteur()
  {  
    // initialisation des broches de sorties
    
    pinMode(Pas1, OUTPUT);
    pinMode(Pas2, OUTPUT);
    pinMode(Pas3, OUTPUT);
    pinMode(Pas4, OUTPUT);
    
    // Mise a zero des broches 
    
    digitalWrite(Pas1, LOW);
    digitalWrite(Pas2, LOW);
    digitalWrite(Pas3, LOW);
    digitalWrite(Pas4, LOW); 
    
    // Initialisation des variables moteur
    
    nombresPas = 200; // les type Nema on 200 Pas
    vitesseRot = 30;   // 30 tr/min
    PasMax = 205;
    
  }
  
  //////////////////////////////////////////////////////////////////////////
 // Fonction controle moteur Ouverture
/////////////////////////////////////////////////////////////////////////
    
void ouverture()
  {
    
   TestCapt();
   
    if(memoirePorte == 1)
      {
        if((memoireStopF == 1) && (memoireStopO == 0))
          {
            //  actionneer le moteur pour l'ouverture
            for(int i; i < PasMax; i++)
              {
                moteur.step(nombresPas);
                attachInterrupt(StopO, StopMoteur, FALLING);
                
              }
          }
          
      }
      else
        {
          if(memoireStopO == 0)
           {
            moteur.step(nombresPas);
            attachInterrupt(StopO,StopMoteur,FALLING);
           } 
        }
  }
  
   /////////////////////////////////////////////////////////////////////////
  //  fonction vermeture
 /////////////////////////////////////////////////////////////////////////
 
 void fermeture()
 {
    
    TestCapt();
    
    if(memoirePorte == 1)
      {
        if((memoireStopF == 0) && (memoireStopO == 1))
          {
            //  actionneer le moteur pour l'ouverture
            for(int i; i < PasMax; i++)
              {
                moteur.step(nombresPas);
                attachInterrupt(StopO, StopMoteur, FALLING);
                
              }
          }
          
      }
      else
        {
          if(memoireStopO == 0)
           {
            moteur.step(nombresPas);
            attachInterrupt(StopO,StopMoteur,FALLING);
           }
        } 
 }
 
 void StopMoteur()
   {
     moteur.step(0); //sopt moteur
     

 delay(500);
       
   }
   
