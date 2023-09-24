#include <LiquidCrystal.h>
#include <Servo.h>

LiquidCrystal lcd(13, 12, 11, 10, 9, 8);
Servo servo;
int temp = 0;
int kadar_gas = 0;
int n = 0;
  
void setup()
{
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  pinMode(6, OUTPUT);
  
  Serial.begin(9600);
  lcd.begin(16, 2);
  servo.attach(7);
}

void loop()
{
  lcd.setCursor(0, 0);
  lcd.clear();
  
  temp = map(((analogRead(A0) - 20) * 3.04), 0, 1023, -40, 125);
  
  if(temp >= 30 && temp <= 90){
    lcd.print("Heating...");
    servo.write(0);
  }
  else if(temp > 90) {
    lcd.print("Food Ready");
    servo.write(90);
	//exit(1);
  }
  else {
    lcd.print("Still Cold");
    servo.write(0);
  }
 
  kadar_gas = map(analogRead(A1), 0, 80, 0, 100);

  if(kadar_gas >= 40){
    digitalWrite(6, HIGH);
  } else {
    digitalWrite(6, LOW);
  }
  
  delay(500); 
 
}
