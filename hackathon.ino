/*Code for moisture sensor*/
#include<LiquidCrystal.h>
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  Serial.begin(9600);
  lcd.begin(16,2);
  lcd.clear();
  lcd.print("WELCOME");
  pinMode(A0,INPUT); //Moisture sensor reading pin A0
  pinMode(1,OUTPUT); // Motor output
  pinMode(A1,INPUT);
  

}
int val;

void loop() 
{
//int t=digitalRead(1);
//int ir=digitalRead(2); 
  int wl=analogRead(A1);
  void water_level()// taking input from water level sensor and controlling the motor
  {
    if(wl>=900 && wl<1024){
    digitalWrite(1,LOW);
    lcd.setCursor(0,0); // Sets the cursor to col 0 and row 0
    lcd.print("Water Level:LOW"); // Prints Sensor Val: to LCD
    }
    else 
    {
        if(wl>=600 && wl<900)        
        { 
          moisture_control(0)//call the function for checking the moisture level;
            lcd.setCursor(0,0); // Sets the cursor to col 0 and row 0
            lcd.print("Water Level:MED"); // Prints Sensor Val: to LCD
        }
        else
        {
          moisture_control(1)//call the funtion for checking moisture level;
            lcd.setCursor(0,0); // Sets the cursor to col 0 and row 0
            lcd.print("Water Level:HIGH"); // Prints Sensor Val: to LCD
        }
    }
  }
}
void moisture_control(int wll) {
  val= analogRead(A0);
  Serial.println(val);
  if(val>800&& val<1024){
    lcd.setCursor(0,1); // Sets the cursor to col 1 and row 0
    lcd.print("MOTOR ON"); // Prints Sensor Val: to LCD
  motorOn(wll);
  }
  else{
    digitalWrite(1,LOW);
    lcd.setCursor(0,1); // Sets the cursor to col 1 and row 0
    lcd.print("MOTOR OFF"); // Prints Sensor Val: to LCD
  }

}
motorOn(int wll)
{
  digitalWrite(1,HIGH);
  if(wll==1){
  if(val<850){
    delay(3000);
  }
  else if(val<820){
    delay(2000);
  }
  else{
  delay(5000);
  }
  }
  if(wll==0){
  if(val<850){
    delay(2000);
  }
  else if(val<820){
    delay(1000);
  }
  else{
  delay(3000);
  }
  }
  digitalWrite(1,LOW);
  delay(600000);
}

