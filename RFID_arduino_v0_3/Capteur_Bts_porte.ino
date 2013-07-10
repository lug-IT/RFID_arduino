/************************************************************************/
/*                                                                      */
/*          Capteur de detection de l'etat de la porte( Ouvert, Fermer) */
/*            materiel : - capteur TOR a contact                        */
/*                                                                      */
/*          Boutons sonnette exterieur                                  */
/*            materiel : - Bouton poussoir                              */
/*                                                                      */
/*          Bouton d'ouverture et de fermeture pour l'interieur         */
/*            materiel : - Bouton pourssoir                             */
/************************************************************************/

// declaration de la broche du capteur de l'etat porte


const int captPorte = A4;
const int btsExt = A2;
const int btsInter = A3;
const int CaptTemp = A4;


// Capteur fin de cource verrou
const int StopF = A0;
const int StopO = A1;

boolean memoirePorte;
boolean memoireCaptBtsInter;
boolean memoireCaptBtsExt;



boolean memoireStopF; // memoire de l'etat du capteur Fermer
boolean memoireStopO;  // memoire de l'etat du capteur Ouvert

void IniCapteurBts()
  {
  char memTemp;
 
   // configuration des capteurs et des boutons
    pinMode(captPorte, INPUT);
    pinMode(btsExt, INPUT);
    pinMode(btsInter, INPUT);
    pinMode(CaptTemp, INPUT);
    
    //configuration des capteurs fin de course
    pinMode(StopF, INPUT);
    pinMode(StopO, INPUT);
    
    // initialisation des memeoires
    TestCapt();
    tempExt();
  }

int TestCapt()
  {
    memoirePorte = digitalRead(captPorte); 
    memoireStopF = digitalRead(StopF);
    memoireStopO = digitalRead(StopO);
  }
  
char tempExt()
  {
   memoireTemp = analogRead(CaptTemp);
   return(memoireTemp);
  } 
  
void BtsExt()
  {
    memoireCaptBtsExt = digitalRead(btsExt);
    
    TestCapt();
    
      if((memoirePorte == 1) && (memoireStopF == 1))
        {
          buzz1();
        }
       else
        {
         buzzEchec();
        }
        
      
      if((memoireStopO == 1) && (memoirePorte == 1))
        {
          buzz1(); // signaller la porte non verrouiller
        }
        else
          {
            buzzEchec(); // operation impossible
          }
  }
      

