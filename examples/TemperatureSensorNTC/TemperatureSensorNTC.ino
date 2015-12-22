/**************************************************************************
*                   LEITURA DO SENSOR DE TEMPERATURA NTC                             
***************************************************************************
AUTOR: LUCAS MAZIERO - Eletric engineer                                                   
E-MAIL: lucas.mazie.ro@hotmail.com 									  
CIDADE: Santa Maria - Rio Grande do Sul - Brasil                                      
***************************************************************************
Versão: 1.0                                                             
Data: 09/03/2015                                                        
Modificado: --/--/2015                                                  
                                                                         
TAMANHO: 4,932 BYTES    MÁXIMO: 32,256 BYTES                           
***************************************************************************
PROGRAMA BASEADO DO CHIP ATMEGA 328                                      
KIT DE DESENVOLVIMENTO ARDUINO UNO RV3                                  
**************************************************************************/

#include <ThermistorNTC.h>
//ThermistorNTC temp(Pino, Resistencia NTC 25°C, beta NTC, R serie, tensao referencia);
ThermistorNTC temp(A0, 5000, 3950, 10000, 5.0);

void setup() 
{
  Serial.begin(9600); // Configura velocidade da serial
}

void loop() 
{
  int tempNTC = temp.getTemp(); //recebe o valor da temperatura em Celsius
  Serial.print("Temperatura no NTC: "); //Imprime no serial
  Serial.print(tempNTC); //Imprime no serial o valor da varialvel
  Serial.print((char)176); //imprime o simbolo de graus °
  Serial.println("C"); //Imprime no serial
  delay(500); // delay no programa
}