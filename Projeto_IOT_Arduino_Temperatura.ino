// C++ code
//
  // Define o pino analógico A0 como entrada do Sensor
int SensorTemp=0;
  // Define o pino digital 8 como saída do Led
int led=8;
  // Define o pino digital 7 como saída do Motor
int motor=7;

  // Define o pino digital 7 como saída do Motor
int buzina=12;

void setup()
{
 
 pinMode(led, OUTPUT);
 pinMode(motor, OUTPUT);
 pinMode(buzina, OUTPUT);
 Serial.begin(9600);
}

void loop()
{
  
// Leitura da tensão no Sensor de Temperatura
	int SensorTempTensao=analogRead(SensorTemp);

// Converte a tensão lida
	float Tensao=SensorTempTensao*5;
	Tensao/=1024;

// Converte a tensão lida em Graus Celsius
	float TemperaturaC=(Tensao-0.5)*100;

// Controle de temperatura
	if (TemperaturaC > 50){
  		digitalWrite(led, HIGH);
        digitalWrite(motor, HIGH);
        digitalWrite(buzina, HIGH);
    }
    else if (TemperaturaC >= 30){
  		digitalWrite(motor, HIGH);
        digitalWrite(led, LOW);
        digitalWrite(buzina, LOW);
    }
  	else {
    	digitalWrite(led, LOW);
    	digitalWrite(motor, LOW);
        digitalWrite(buzina, LOW);
    }
          
Serial.println(TemperaturaC);
  
}
