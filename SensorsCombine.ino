/*=========LIBRARIES==============================*/
#include <DHT.h>
/*========END LIBRARIES===========================*/


/*========CONSTANTS==================================*/
//FOR TEMPERATURE SENSOR
#define DHTPIN 7     // what pin we're connected to
#define DHTTYPE DHT22   // DHT 22  (AM2302)
DHT dht(DHTPIN, DHTTYPE);

//FOR RAIN SENSOR
const int sensorRainMin = 0;     // sensor minimum
const int sensorRainMax = 1024;  // sensor maximum
#define RAIN_SENSOR A0
/*============END CONSTANTS===========================*/

/*============VARIABLES=============================*/
float humidity;  //Stores humidity value
float temperature; //Stores temperature value
int rainRange;
/*============END VARIABLES=============================*/


void setup() {
  Serial.begin(9600);
  dht.begin();
}

void ReadSensor_Temperature()
{
  humidity = dht.readHumidity();
  temperature = dht.readTemperature();
}

void ReadSensor_Rain()
{
  int rainSensorReading = analogRead(RAIN_SENSOR);

  //Map sensor rain for easier values handling
  rainRange = map(rainSensorReading,sensorRainMin, sensorRainMax,0,4) + 1;

}
void loop() {

//Read temperature and humidity
ReadSensor_Temperature();

//Read rain sensor
ReadSensor_Rain();


Serial.print(rainRange);
Serial.print("|");
Serial.print((int)temperature);
Serial.print("|");
Serial.print((int)humidity);
Serial.print("|");


delay(2000);
}
