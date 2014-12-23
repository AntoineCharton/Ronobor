#include <Chrono.h>

Chrono envoiMessage;

int Pin0D = 8; 
int Pin1D = 9; 
int Pin2D = 10; 
int Pin3D = 11; 
int _stepD = 1; 
int positionBrasD = 0;
boolean dirD = true;
boolean etatCalibrationD = true;
boolean  droiteFinitD= false;
boolean cycleCompletD = false;
int compterDroite = 0;

int Pin0G = 2; 
int Pin1G = 3; 
int Pin2G = 5; 
int Pin3G = 6; 
int _stepG = 1; 
int positionBrasG = 0;
boolean dirG = true;
boolean etatCalibrationG = true;
boolean  droiteFinitG= false;
boolean cycleCompletG = false;
int compterGauche = 0;
int marge = 125;
int seuil = 0;



void setup() 
{ 
 seuil = analogRead(1);
 pinMode(Pin0D, OUTPUT);  
 pinMode(Pin1D, OUTPUT);  
 pinMode(Pin2D, OUTPUT);  
 pinMode(Pin3D, OUTPUT);  
 
 pinMode(Pin0G, OUTPUT);  
 pinMode(Pin1G, OUTPUT);  
 pinMode(Pin2G, OUTPUT);  
 pinMode(Pin3G
 , OUTPUT);  
 
 Serial.begin(57600);
} 
 void loop() 
{ 
  if( etatCalibrationD == false){
  moteurDroite();
  moteurGauche();
  delay(1); 
  } else{
  calibrationDroite();
  calibrationGauche();
    if ( envoiMessage.metro(2000) ) {
                
        }
  delay(1); 
  }
  //Serial.println(analogRead(1));
}

void moteurDroite(){
  if( analogRead(1) < seuil - marge || cycleCompletD == true){
  
 switch(_stepD){ 
   case 0:
       if( dirD == true){
       compterDroite = 0;
     cycleCompletD = true;
        positionBrasD ++;
    if( positionBrasD > 220){// tape la tete
      dirD = false;
      //positionBrasD = 178;
    }
       } else{
    positionBrasD --;  
  if( positionBrasD < 80){
      //positionBrasD = 102;
      cycleCompletD = false;
      dirD = true;
    }   
       }
  //  Serial.println(positionBrasD); 
     digitalWrite(Pin0D, LOW);  
     digitalWrite(Pin1D, LOW); 
     digitalWrite(Pin2D, LOW); 
     digitalWrite(Pin3D, HIGH); 
   break;  
   case 1: 
     digitalWrite(Pin0D, LOW);  
     digitalWrite(Pin1D, LOW); 
     digitalWrite(Pin2D, HIGH); 
     digitalWrite(Pin3D, HIGH); 
   break;  
   case 2: 
     digitalWrite(Pin0D, LOW);  
     digitalWrite(Pin1D, LOW); 
     digitalWrite(Pin2D, HIGH); 
     digitalWrite(Pin3D, LOW); 
   break;  
   case 3: 
     digitalWrite(Pin0D, LOW);  
     digitalWrite(Pin1D, HIGH); 
     digitalWrite(Pin2D, HIGH); 
     digitalWrite(Pin3D, LOW); 
   break;  
   case 4: 
     digitalWrite(Pin0D, LOW);  
     digitalWrite(Pin1D, HIGH); 
     digitalWrite(Pin2D, LOW); 
     digitalWrite(Pin3D, LOW); 
   break;  
   case 5: 
     digitalWrite(Pin0D, HIGH);  
     digitalWrite(Pin1D, HIGH); 
     digitalWrite(Pin2D, LOW); 
     digitalWrite(Pin3D, LOW); 
   break;  
     case 6: 
     digitalWrite(Pin0D, HIGH);  
     digitalWrite(Pin1D, LOW); 
     digitalWrite(Pin2D, LOW); 
     digitalWrite(Pin3D, LOW); 
   break;  
   case 7: 
     if( dirD == true ){
       cycleCompletD = false;
     } else{
       cycleCompletD = true;
     }
     digitalWrite(Pin0D, HIGH);  
     digitalWrite(Pin1D, LOW); 
     digitalWrite(Pin2D, LOW); 
     digitalWrite(Pin3D, HIGH); 
   break;  
   default: 
     
     digitalWrite(Pin0D, LOW);  
     digitalWrite(Pin1D, LOW); 
     digitalWrite(Pin2D, LOW); 
     digitalWrite(Pin3D, LOW); 
   break;  
 } 
  }else{
    compterDroite ++;
    if( compterDroite > 2000 && positionBrasD > -90){
      
      dirD = false;
      switch(_stepD){ 
       case 0:
 
      positionBrasD --; 
      Serial.println(positionBrasD);
    
  //  Serial.println(positionBrasD); 
     digitalWrite(Pin0D, LOW);  
     digitalWrite(Pin1D, LOW); 
     digitalWrite(Pin2D, LOW); 
     digitalWrite(Pin3D, HIGH); 
   break;  
   case 1: 
     digitalWrite(Pin0D, LOW);  
     digitalWrite(Pin1D, LOW); 
     digitalWrite(Pin2D, HIGH); 
     digitalWrite(Pin3D, HIGH); 
   break;  
   case 2: 
     digitalWrite(Pin0D, LOW);  
     digitalWrite(Pin1D, LOW); 
     digitalWrite(Pin2D, HIGH); 
     digitalWrite(Pin3D, LOW); 
   break;  
   case 3: 
     digitalWrite(Pin0D, LOW);  
     digitalWrite(Pin1D, HIGH); 
     digitalWrite(Pin2D, HIGH); 
     digitalWrite(Pin3D, LOW); 
   break;  
   case 4: 
     digitalWrite(Pin0D, LOW);  
     digitalWrite(Pin1D, HIGH); 
     digitalWrite(Pin2D, LOW); 
     digitalWrite(Pin3D, LOW); 
   break;  
   case 5: 
     digitalWrite(Pin0D, HIGH);  
     digitalWrite(Pin1D, HIGH); 
     digitalWrite(Pin2D, LOW); 
     digitalWrite(Pin3D, LOW); 
   break;  
     case 6: 
     digitalWrite(Pin0D, HIGH);  
     digitalWrite(Pin1D, LOW); 
     digitalWrite(Pin2D, LOW); 
     digitalWrite(Pin3D, LOW); 
   break;  
   case 7: 
     if( dirD == true ){
       cycleCompletD = false;
     } else{
       cycleCompletD = true;
     }
     digitalWrite(Pin0D, HIGH);  
     digitalWrite(Pin1D, LOW); 
     digitalWrite(Pin2D, LOW); 
     digitalWrite(Pin3D, HIGH); 
   break;  
   default: 
     
     digitalWrite(Pin0D, LOW);  
     digitalWrite(Pin1D, LOW); 
     digitalWrite(Pin2D, LOW); 
     digitalWrite(Pin3D, LOW); 
   break;  
 } 
      
      
    }
    
  }
 if(dirD){ 
   _stepD++; 
     
 }else{ 
   _stepD--;
  
 
 } 
 if(_stepD>7){ 
   _stepD=0;
   
 
 } 
 if(_stepD<0){ 
   _stepD=7; 
    

   // Serial.println(positionBrasD);
 } 


}

void moteurGauche(){
  if( analogRead(1) < seuil - marge || cycleCompletG == true ){
 
 switch(_stepG){ 
   case 0:
       if( dirG == true){
       cycleCompletG = true;
    positionBrasG ++;
    if( positionBrasG > 140){
      dirG = false;
      compterGauche = 0;
       //positionBrasG = 98;
    }
       } else{
    positionBrasG --;  
    
  if( positionBrasG < 0){//tape la tete
   positionBrasG = 2;
     //positionBrasG = 3;
      dirG = true;
       cycleCompletG = false;
    }   
       }
  //  Serial.println(positionBrasD); 
     digitalWrite(Pin0G, LOW);  
     digitalWrite(Pin1G, LOW); 
     digitalWrite(Pin2G, LOW); 
     digitalWrite(Pin3G, HIGH); 
   break;  
   case 1: 
     digitalWrite(Pin0G, LOW);  
     digitalWrite(Pin1G, LOW); 
     digitalWrite(Pin2G, HIGH); 
     digitalWrite(Pin3G, HIGH); 
   break;  
   case 2: 
     digitalWrite(Pin0G, LOW);  
     digitalWrite(Pin1G, LOW); 
     digitalWrite(Pin2G, HIGH); 
     digitalWrite(Pin3G, LOW); 
   break;  
   case 3: 
     digitalWrite(Pin0G, LOW);  
     digitalWrite(Pin1G, HIGH); 
     digitalWrite(Pin2G, HIGH); 
     digitalWrite(Pin3G, LOW); 
   break;  
   case 4: 
     digitalWrite(Pin0G, LOW);  
     digitalWrite(Pin1G, HIGH); 
     digitalWrite(Pin2G, LOW); 
     digitalWrite(Pin3G, LOW); 
   break;  
   case 5: 
     digitalWrite(Pin0G, HIGH);  
     digitalWrite(Pin1G, HIGH); 
     digitalWrite(Pin2G, LOW); 
     digitalWrite(Pin3G, LOW); 
   break;  
     case 6: 
     digitalWrite(Pin0G, HIGH);  
     digitalWrite(Pin1G, LOW); 
     digitalWrite(Pin2G, LOW); 
     digitalWrite(Pin3G, LOW); 
   break;  
   case 7: 
     digitalWrite(Pin0G, HIGH);  
     digitalWrite(Pin1G, LOW); 
     digitalWrite(Pin2G, LOW); 
     digitalWrite(Pin3G, HIGH); 
        if( dirG == true ){
       cycleCompletG = false;
     } else{
       cycleCompletG = true;
     }
   break;  
   default: 
     digitalWrite(Pin0G, LOW);  
     digitalWrite(Pin1G, LOW); 
     digitalWrite(Pin2G, LOW); 
     digitalWrite(Pin3G, LOW); 
   break;  
 } 
  }else{
    compterGauche ++;
    if( compterGauche > 2000 && positionBrasG < 270){
      
      dirG = true;
      switch(_stepG){ 
       case 0:
 
      positionBrasG ++; 
      Serial.println(positionBrasG);
    
  //  Serial.println(positionBrasD); 
     digitalWrite(Pin0G, LOW);  
     digitalWrite(Pin1G, LOW); 
     digitalWrite(Pin2G, LOW); 
     digitalWrite(Pin3G, HIGH); 
   break;  
   case 1: 
     digitalWrite(Pin0G, LOW);  
     digitalWrite(Pin1G, LOW); 
     digitalWrite(Pin2G, HIGH); 
     digitalWrite(Pin3G, HIGH); 
   break;  
   case 2: 
     digitalWrite(Pin0G, LOW);  
     digitalWrite(Pin1G, LOW); 
     digitalWrite(Pin2G, HIGH); 
     digitalWrite(Pin3G, LOW); 
   break;  
   case 3: 
     digitalWrite(Pin0G, LOW);  
     digitalWrite(Pin1G, HIGH); 
     digitalWrite(Pin2G, HIGH); 
     digitalWrite(Pin3G, LOW); 
   break;  
   case 4: 
     digitalWrite(Pin0G, LOW);  
     digitalWrite(Pin1G, HIGH); 
     digitalWrite(Pin2G, LOW); 
     digitalWrite(Pin3G, LOW); 
   break;  
   case 5: 
     digitalWrite(Pin0G, HIGH);  
     digitalWrite(Pin1G, HIGH); 
     digitalWrite(Pin2G, LOW); 
     digitalWrite(Pin3G, LOW); 
   break;  
     case 6: 
     digitalWrite(Pin0G, HIGH);  
     digitalWrite(Pin1G, LOW); 
     digitalWrite(Pin2G, LOW); 
     digitalWrite(Pin3G, LOW); 
   break;  
   case 7: 
     if( dirG == true ){
       cycleCompletG = false;
     } else{
       cycleCompletG = true;
     }
     digitalWrite(Pin0G, HIGH);  
     digitalWrite(Pin1G, LOW); 
     digitalWrite(Pin2G, LOW); 
     digitalWrite(Pin3G, HIGH); 
   break;  
   default: 
     
     digitalWrite(Pin0G, LOW);  
     digitalWrite(Pin1G, LOW); 
     digitalWrite(Pin2G, LOW); 
     digitalWrite(Pin3G, LOW); 
   break;  
 } 
      
      
    }
    
  }
 if(dirG){ 
   _stepG++; 
     
 }else{ 
   _stepG--;
  
 
 } 
 if(_stepG>7){ 
   _stepG=0;
   
 
 } 
 if(_stepG<0){ 
   _stepG=7; 
    

   // Serial.println(positionBrasD);
 } 


}

void calibrationDroite(){
   
 
 switch(_stepD){ 
   case 0:
       if( dirD == true){
    positionBrasD ++;
    if( positionBrasD > 210){
      dirD = false;
      
    }
       } else{
    positionBrasD --;  
  if( positionBrasD < 0){
      dirD = true;
      etatCalibrationD = false;
    }   
       }
  //  Serial.println(positionBrasD); 
     digitalWrite(Pin0D, LOW);  
     digitalWrite(Pin1D, LOW); 
     digitalWrite(Pin2D, LOW); 
     digitalWrite(Pin3D, HIGH); 
   break;  
   case 1: 
     digitalWrite(Pin0D, LOW);  
     digitalWrite(Pin1D, LOW); 
     digitalWrite(Pin2D, HIGH); 
     digitalWrite(Pin3D, HIGH); 
   break;  
   case 2: 
     digitalWrite(Pin0D, LOW);  
     digitalWrite(Pin1D, LOW); 
     digitalWrite(Pin2D, HIGH); 
     digitalWrite(Pin3D, LOW); 
   break;  
   case 3: 
     digitalWrite(Pin0D, LOW);  
     digitalWrite(Pin1D, HIGH); 
     digitalWrite(Pin2D, HIGH); 
     digitalWrite(Pin3D, LOW); 
   break;  
   case 4: 
     digitalWrite(Pin0D, LOW);  
     digitalWrite(Pin1D, HIGH); 
     digitalWrite(Pin2D, LOW); 
     digitalWrite(Pin3D, LOW); 
   break;  
   case 5: 
     digitalWrite(Pin0D, HIGH);  
     digitalWrite(Pin1D, HIGH); 
     digitalWrite(Pin2D, LOW); 
     digitalWrite(Pin3D, LOW); 
   break;  
     case 6: 
     digitalWrite(Pin0D, HIGH);  
     digitalWrite(Pin1D, LOW); 
     digitalWrite(Pin2D, LOW); 
     digitalWrite(Pin3D, LOW); 
   break;  
   case 7: 
     digitalWrite(Pin0D, HIGH);  
     digitalWrite(Pin1D, LOW); 
     digitalWrite(Pin2D, LOW); 
     digitalWrite(Pin3D, HIGH); 
   break;  
   default: 
     digitalWrite(Pin0D, LOW);  
     digitalWrite(Pin1D, LOW); 
     digitalWrite(Pin2D, LOW); 
     digitalWrite(Pin3D, LOW); 
   break;  
 } 
  
 if(dirD){ 
   _stepD++; 
     
 }else{ 
   _stepD--;
  
 
 } 
 if(_stepD>7){ 
   _stepD=0;
   
 
 } 
 if(_stepD<0){ 
   _stepD=7; 
    

   // Serial.println(positionBrasD);
 }
 
}

void calibrationGauche(){
   
 
 switch(_stepG){ 
   case 0:
       if( dirG == true){
    positionBrasG ++;
    if( positionBrasG > 200){
      dirG = false;
      
    }
       } else{
    positionBrasG --;  
  if( positionBrasG < 0){
      dirG = true;
      etatCalibrationG = false;
    }   
       }
  //  Serial.println(positionBrasD); 
     digitalWrite(Pin0G, LOW);  
     digitalWrite(Pin1G, LOW); 
     digitalWrite(Pin2G, LOW); 
     digitalWrite(Pin3G, HIGH); 
   break;  
   case 1: 
     digitalWrite(Pin0G, LOW);  
     digitalWrite(Pin1G, LOW); 
     digitalWrite(Pin2G, HIGH); 
     digitalWrite(Pin3G, HIGH); 
   break;  
   case 2: 
     digitalWrite(Pin0G, LOW);  
     digitalWrite(Pin1G, LOW); 
     digitalWrite(Pin2G, HIGH); 
     digitalWrite(Pin3G, LOW); 
   break;  
   case 3: 
     digitalWrite(Pin0G, LOW);  
     digitalWrite(Pin1G, HIGH); 
     digitalWrite(Pin2G, HIGH); 
     digitalWrite(Pin3G, LOW); 
   break;  
   case 4: 
     digitalWrite(Pin0G, LOW);  
     digitalWrite(Pin1G, HIGH); 
     digitalWrite(Pin2G, LOW); 
     digitalWrite(Pin3G, LOW); 
   break;  
   case 5: 
     digitalWrite(Pin0G, HIGH);  
     digitalWrite(Pin1G, HIGH); 
     digitalWrite(Pin2G, LOW); 
     digitalWrite(Pin3G, LOW); 
   break;  
     case 6: 
     digitalWrite(Pin0G, HIGH);  
     digitalWrite(Pin1G, LOW); 
     digitalWrite(Pin2G, LOW); 
     digitalWrite(Pin3G, LOW); 
   break;  
   case 7: 
     digitalWrite(Pin0G, HIGH);  
     digitalWrite(Pin1G, LOW); 
     digitalWrite(Pin2G, LOW); 
     digitalWrite(Pin3G, HIGH); 
   break;  
   default: 
     digitalWrite(Pin0G, LOW);  
     digitalWrite(Pin1G, LOW); 
     digitalWrite(Pin2G, LOW); 
     digitalWrite(Pin3G, LOW); 
   break;  
 } 
  
 if(dirG){ 
   _stepG++; 
     
 }else{ 
   _stepG--;
  
 
 } 
 if(_stepG>7){ 
   _stepG=0;
   
 
 } 
 if(_stepG<0){ 
   _stepG=7; 
    

   // Serial.println(positionBrasD);
 }
 
}

void retourNormal(){
}
  
