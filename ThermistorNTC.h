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

#ifndef ThermistorNTC_h
#define ThermistorNTC_h

#include "Arduino.h"
#include "math.h"


class ThermistorNTC {
	public:
		ThermistorNTC(int _pin, float R0, float _beta, float _Raux, float _Vin);
		float getTemp();
	private:
		int pin;
		float beta;
		float Rinf;
		float Raux;
		float Vin;
};

#endif