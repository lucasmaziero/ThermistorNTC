/**************************************************************************
			  LIBRARY FOR SENSOR DE TEMPERATURA TIPO NTC                 
***************************************************************************
AUTOR: LUCAS MAZIERO - Eletric engineer                                                   
E-MAIL: lucas.mazie.ro@hotmail.com 									  
CIDADE: Santa Maria - Rio Grande do Sul - Brasil 
***************************************************************************
code based from code on Arduino playground found here:				  
http://www.arduino.cc/playground/ComponentLib/Thermistor2 
max mayfield									
mm systems										
max.mayfield@hotmail.com                                     
***************************************************************************
Versão: 1.0                                                             
Data: 09/03/2015                                                        
Modificado: --/--/---- 
***************************************************************************
(+5v) ---- (10k-Resisistor) -------|------- (Thermistor NTC) ---- (Ground)	 
                                   |									
                                Analog Pin	                                                                                                                               
**************************************************************************/
#include "Arduino.h"
#include "ThermistorNTC.h"

ThermistorNTC::ThermistorNTC(int _pin, float R0, float _beta, float _Raux, float _Vin)
 {
  pin = _pin;
  beta = _beta;
  Raux = _Raux;
  Vin = _Vin;
  
  Rinf=R0*exp(-beta/298.15);
}

float ThermistorNTC::getTemp() 
{

  float Vout;
  float Rout;
  float TempC;
  float TempK;
  
  //Calculo da resistência do NTC
  Vout=Vin*((float)(analogRead(pin))/1024.0);
  Rout=(Raux*Vout/(Vin-Vout));

  //Calculo da temperatura
  TempK=(beta/log(Rout/Rinf));
  TempC=TempK-273.15;
  
  return TempC;  // Return the Temperature Celsius
}
