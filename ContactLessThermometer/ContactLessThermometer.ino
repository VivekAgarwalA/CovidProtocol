#include <LiquidCrystal_I2C.h>
#include <Adafruit_MLX90614.h>

Adafruit_MLX90614 mlx = Adafruit_MLX90614();

LiquidCrystal_I2C lcd(0x27, 16, 2); // I2C address 0x27, 16 column and 2 rows
const int trigPin = 3;
const int echoPin = 2;
long time;
int distance;
double x;
void setup()
{
  lcd.init(); // initialize the lcd
  lcd.backlight();
pinMode (IRSensor, INPUT); // sensor pin INPUT
  lcd.setCursor(0, 0);         // move cursor to   (0, 0)
  lcd.print("Arduino");        // print message at (0, 0)
  lcd.setCursor(2, 1);         // move cursor to   (2, 1)
  lcd.print("GetStarted.com"); // print message at (2, 1)
  delay(2000);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);
  while (!Serial);

  Serial.println("Adafruit MLX90614 test");

  if (!mlx.begin()) {
    Serial.println("Error connecting to MLX sensor. Check wiring.");
    while (1);
  };
  Serial.begin(9600);
}

void loop(){
  lcd.clear();
  
 digitalWrite(trigPin,LOW);
 delayMicroseconds(2);
 digitalWrite(trigPin,HIGH);
 delayMicroseconds(10);
 digitalWrite(trigPin,LOW);
 delayMicroseconds(2);
 time=pulseIn(echoPin,HIGH);
 distance=time*340/20000;

 Serial.print("Ambient = "); Serial.print(mlx.readAmbientTempC());
  Serial.print("*C\tObject = "); Serial.print(mlx.readObjectTempC()); Serial.println("*C");
  Serial.print("Ambient = "); Serial.print(mlx.readAmbientTempF());
  Serial.print("*F\tObject = "); Serial.print(mlx.readObjectTempF()); Serial.println("*F");
x=mlx.readObjectTempF();

 
 lcd.print(" Distance:");
 lcd.print(distance);
 lcd.print("cm");
 if(distance>15 || distance < 8)
 {
  lcd.setCursor(0,1);
  lcd.print(" Target 10-12 CM");
  lcd.scrollDisplayLeft();
  delay(3500);
 }
 else
 {
  lcd.clear();
 
 lcd.setCursor(0,0);
 lcd.print("Room:");
 lcd.print(mlx.readAmbientTempF());
 lcd.print("F");
lcd.setCursor(0,1);

 lcd.print("Obj:");
 lcd.print(x);
 lcd.print("F");
 delay(3000);
 if(x>107)
 {
 lcd.clear();
 lcd.setCursor(0,0);
 lcd.print("Danger High Temp");
 delay(5000);
 }
 
 delay(1000);
}delay(1000);

}
