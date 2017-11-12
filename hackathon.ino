/*Code for moisture sensor*/

void setup() {
  Serial.begin(9600);
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

