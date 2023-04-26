#include "DHT.h"
#define dht_type DHT11 //define qual o tipo de sensor DHTxx que se está utilizando

int dht_pin = A2;
DHT dht_1 = DHT(dht_pin, dht_type);

float temperatura;

int switch_pin = 7;
void setup()
{
Serial.begin(9600);
dht_1.begin();
pinMode(switch_pin, INPUT);
}
void loop()
{


float umidade = (dht_1.readHumidity()+ 18.03)*1.11;
float temperatura = (dht_1.readTemperature()+ 6.07)*0.58;

//float umidadeConvertida =(umidade + 18.03)* 1.11;
//float temperaturaConvertida =  (temperatura + 6.07) *0.58 ;
if (isnan(temperatura) or isnan(umidade))
{
Serial.println("Erro ao ler o DHT");
}
else
{
Serial.print(umidade);
Serial.print(";");
Serial.print( temperatura);
Serial.print(";");
Serial.println();
}

delay(1000);
}