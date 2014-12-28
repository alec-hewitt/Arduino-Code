int LED = 12;

void setup(){
 pinMode(LED,OUTPUT); 
}

void loop(){
  //increment value of fade
   for(int fadeValue = 0; fadeValue <= 255; fadeValue += 5){
     //pass fade value to LED
     analogWrite(LED, fadeValue);
     //delay 20ms to see dimming effect
     delay(30);
   }
   
   //decrement value of fade
   for(int fadeValue = 255; fadeValue >= 0; fadeValue -= 5){
     //pass fade value to LED
     analogWrite(LED, fadeValue);
     //delay 20ms to see dimming effect
     delay(30);
   }
}
