/****************************************************************************/
/*    Affichae exterieur                                                    */
/*                                                                          */
/*    Materiel :   - leds (rouge vert et jaune)                             */
/*                 - affichage LCD                                          */
/*                 - 2x  75hc595    16 sortie                               */
/****************************************************************************/


boolean memSelect;
long tps;
long tpsAffTemp;
int Select;
byte Menu;

int secondes;
int minutes;
int heures;




void IniAffichage()
{
  // Initialisation des differentes variables
  memSelect = 0;
  tps = millis();
  tpsAffTemp = millis();
  Select = 0;
  Menu = 0;
  
  //initialisation des sortie affichage
  pinMode(Horloge, OUTPUT);
  pinMode(Data, OUTPUT);
  pinMode(Verrou, OUTPUT);

  LCD.begin(16,2); // initialisation de la taille de l'ecran, en bloc de 8 trame de 5bits
  LCD.home();  //on met le curseur en haut à gauche
  LCD.print("Initialisation");  // on affiche a l'ecran "initialisation en cours" sur 2 line
  LCD.setCursor(0,1);
  LCD.print("En Cours");
  
}

///////////////////////////////////////////////////////////
//  Affichage LCD
////////////////////////////////////////////////////////////

void affichage()
{ 
  LogoPH();  //affichage du Logo Phenix IT
  genTemps(); //fonction generant le temps de l'Horloge
 // detectBts();  // Dectection des bouton de reglage
 
   
 // selection des menu d'affichage normal/reglage
  if(memSelect == 1)
  {
    affReglage();
   
    // Bts();
      if(Menu == 1)
      { affRegleHeur();
        Select = heures;
        if(Select >=24)
            { Select =0; }
          }
          
      if(Menu == 2)
      { affRegleMin();
        Select = minutes; 
         if(Select >= 60)
            {  Select = 0;}
          }
          
      if(Menu == 3)
      { 
        memSelect =! memSelect;
        affClear();
      }
      
      
  }
  else
  {
    affTemp();
    affTemps();

  }
  
}




///////////////////////////////////////
//  fonction Clear de l'ecran

void affClear()
{
    // on enleve se qui etait afficher
   LCD.clear();
}

//////////////////////////////////////
// Affichage de l'horloge

void affTemps()
{
  char message[16] = "";
   LCD.home();
   sprintf(message,"%2d:%2d:%2d", heures,minutes,secondes);
   LCD.print(message);
}

////////////////////////////////////////
// affichage reglage

void affReglage()
{

  LCD.home();
  LCD.print("Reglage");
  LCD.setCursor(0,1);
}

void affRegleHeur()
{
  char message[16] = "";
  heures = Select;
  LCD.setCursor(0,1);
  sprintf(message,"%2d Heures",heures);
  LCD.print(message);
}  

void affRegleMin()
{
  char message[16] = "";
  minutes = Select;
  LCD.setCursor(0,1);
  sprintf(message,"%2d Minutes",minutes);
  LCD.print(message);
}


/////////////////////////////////////////
// Affichage temperature

void affTemp()
{ 
  char memTemp = memoireTemp;
  char message[16] = "";
  LCD.setCursor(0,1);
  sprintf(message,"T:%2d C",memTemp);
   if(( millis() - tpsAffTemp)  > 1500)
  {
   LCD.print(message);
   tpsAffTemp=millis();
  }
}

///////////////////////////////////////////////////
//    Creation du Logo Phenix it 

void IniLogo()      
{
  byte IA[8] = {
    B00000,
    B00001,
    B00011,
    B00110,
    B01100,
    B11100,
    B11000,
    B11100,  };
    
  byte IB[8] = {
    B01010,
    B10001,
    B00000,
    B00000,
    B00000,
    B00100,
    B01110,
    B11111,  };
    
    byte IC[8] = {
      B00000,
      B10000,
      B11000,
      B01100,
      B00110,
      B00111,
      B00011,
      B00111,  };
      
    byte IIA[8] = {
      B11110,
      B11111,
      B01111,
      B00111,
      B00011,
      B00001,
      B00000,
      B00000,  };
    
    byte IIB[8] = {
      B11111,
      B01110,
      B00000,
      B11011,
      B11111,
      B11111,
      B11111,
      B01110,  };
    
  byte IIC[8] = {
      B01111,
      B11111,
      B11110,
      B11100,
      B11000,
      B10000,
      B00000,
      B00000,  };
 
// creation de charactere sur l'ecran LCD
  LCD.createChar(0, IA);
  LCD.createChar(1, IB);  
  LCD.createChar(2, IC);  
  LCD.createChar(3, IIA);  
  LCD.createChar(4, IIB);
  LCD.createChar(5, IIC);

  
}

// Affichage du logo

void LogoPH()
{
 LCD.setCursor(13,0);
 LCD.write((uint8_t) 0);
 
 LCD.setCursor(14,0);
 LCD.write((uint8_t) 1);
 
 LCD.setCursor(15,0);
 LCD.write((uint8_t) 2);
 
 LCD.setCursor(13,1);
 LCD.write((uint8_t) 3);
 
 LCD.setCursor(14,1);
 LCD.write((uint8_t) 4);
 
 LCD.setCursor(15,1);
 LCD.write((uint8_t) 5);
}  
/*
void affOuvert()
{
  
  LCD.setCursor(0,1);
  LCD.autoscroll();
  LCD.print("Ouverture en cours ...);
  LCD.clear();
  affLogoPH();
  affTemps();
  
  if(StopO == 1);
    {
      LCD.setCursor(0,1);
      LCD.print("Ouvert");
    }
  
}
*/
