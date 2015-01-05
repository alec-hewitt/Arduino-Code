int motor_1 = 8;
int button = 4;

void setup(){
 pinMode(motor_1, OUTPUT); 
 pinMode(button, INPUT);
}

void loop(){
  if(digitalRead(button) == HIGH){
   digitalWrite(motor_1, HIGH); 
  } else {
   digitalWrite(motor_1, LOW); 
  }
}
