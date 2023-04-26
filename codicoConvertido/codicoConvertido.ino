#include "DHT.h"
#define dht_type DHT11  //define qual o tipo de sensor DHTxx que se está utilizando

int dht_pin = A2;
DHT dht_1 = DHT(dht_pin, dht_type);

int switch_pin = 7;
void setup() {
  Serial.begin(9600);
  dht_1.begin();
  pinMode(switch_pin, INPUT);
}
void loop() {

  //valores reais capturados em loco
  float umidadeReal = dht_1.readHumidity();
  float temperaturaReal = dht_1.readTemperature();

  // //valores com a aplicação da formula linear
  float umidade = (umidadeReal)*1.41;
  float temperatura = (temperaturaReal + 6.07) * 0.58;

  // //variação 1
  float umidade1 = (umidade * 0.1) + umidade;
  float temperatura1 = (temperatura * 0.20) + temperatura;

  // //variação 2
  float umidade2 = (umidade * 0.6) + umidade;
  float temperatura2 = (temperatura * 0.6) + temperatura;

  // //variação 3
  float umidade3 = (umidade * 0.35) + umidade;
  float temperatura3 = (temperatura * 0.35) + temperatura;

  // //variação 4
  float umidade4 = (umidade * 0.9) + umidade;
  float temperatura4 = (temperatura * 0.9) + temperatura;

  int erro = 0;

  //float umidadeConvertida =(umidade + 18.03)* 1.11;
  //float temperaturaConvertida =  (temperatura + 6.07) *0.58 ;
  if (isnan(temperaturaReal) or isnan(umidadeReal)) {
    Serial.println(erro);
  } else {
    Serial.print(umidadeReal);
    Serial.print(";");
    Serial.print(temperaturaReal);
    Serial.print(";");
   
    Serial.print(umidade);
    Serial.print(";");
    Serial.print(temperatura);
    Serial.print(";");
   
    Serial.print(umidade1);
    Serial.print(";");
    Serial.print(temperatura1);
    Serial.print(";");
    
    Serial.print(umidade2);
    Serial.print(";");
    Serial.print(temperatura2);
    Serial.print(";");
    

    Serial.print(umidade3);
    Serial.print(";");
    Serial.print(temperatura3);
    Serial.print(";");
    Serial.print(umidade4);
    Serial.print(";");
    Serial.println(temperatura4);
    
   

    delay(2000);
  }
}