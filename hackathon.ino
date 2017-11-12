/*Code for moisture sensor*/
#include<LiquidCrystal.h>
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  Serial.begin(9600);
  lcd.begin(16,2);
  lcd.print("WELCOME");
  pinMode(A0,INPUT); //Moisture sensor reading pin A0
  pinMode(1,OUTPUT); // Motor output
  

}
int val;
void loop() {
  val= analogRead(A0);
  Serial.println(val);
  if(val>800&& val<1024){
  motorOn();
  }
  else{
    digitalWrite(1,LOW);
  }

}
motorOn()
{
  digitalWrite(1,HIGH);
  if(val<850){
    delay(3000);
  }
  else if(val<820){
    delay(2000);
  }
  else{
  delay(5000);
  }
  digitalWrite(1,LOW);
  delay(1000000000);
}

