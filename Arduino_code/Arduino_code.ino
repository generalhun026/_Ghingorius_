#include <ArduinoSTL.h>
#include <Servo.h>
#include <map>
Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;
Servo servo5;
std::map<String, void (*)(void)> commandMap;
int out = 0;
  int in = 180;
  int mid = 90;
void setup() {
  Serial.begin(115200);

  // Populate the command map with commands and corresponding functions
  commandMap["up"] = command1;
  commandMap["down"] = command2;
  commandMap["grab"] = command3;
  commandMap["release"] = command4;
  commandMap["pinch"] = command5;
  commandMap["rock"] = command6;
  commandMap["point"] = command7;
  commandMap["okay"] = command8;
  commandMap["hand"] = command9;
  commandMap["phone"] = command10;
  commandMap["pinky"] = command11;
  commandMap["bump"] = command12;
  commandMap["gun"] = command13;
  commandMap["spoon"] = command14;
  commandMap["peace"] = command15;
  // Add more commands as needed
  servo1.attach(3);
  servo2.attach(5);
  servo3.attach(6);
  servo4.attach(9);
  servo5.attach(10);

    servo1.write(out);             
    servo2.write(out);    
    servo3.write(out);
    servo4.write(out); 
    servo5.write(out);
}

void loop() {
  
  // Read or receive the string (e.g., from Serial)
  if (Serial.available() > 0) {
    String command = Serial.readStringUntil('\n');

    // Process the command using the map
    processCommand(command);
  }

  // Add other code as needed
}

void processCommand(String cmd) {
  if (commandMap.find(cmd) != commandMap.end()) {
    commandMap[cmd]();
  } else {
    Serial.println("Unknown command");
  }
}

void command1() {

  // Code for command1
    servo1.write(in);             
    servo2.write(in);    
    servo3.write(in);
    servo4.write(in); 
    servo5.write(out);
  Serial.println("Executing command1");
}

void command2() {

  // Code for command2
  servo1.write(in);             
    servo2.write(in);    
    servo3.write(in);
    servo4.write(in); 
    servo5.write(out);
  Serial.println("Executing command2");
}

void command3() {
  // Code for command3
  servo1.write(in);             
    servo2.write(in);    
    servo3.write(in);
    servo4.write(in); 
    servo5.write(in);
  Serial.println("Executing command3");
}
void command4() {
  // Code for command1
  servo1.write(out);             
    servo2.write(out);    
    servo3.write(out);
    servo4.write(out); 
    servo5.write(out);
  Serial.println("Executing command4");
}

void command5() {
  // Code for command2
  servo1.write(out);             
    servo2.write(out);    
    servo3.write(out);
    servo4.write(mid); 
    servo5.write(135);
  
  Serial.println("Executing command5");
}
void command6() {
  // Code for command6
  servo1.write(out);             
    servo2.write(in);    
    servo3.write(in);
    servo4.write(out); 
    servo5.write(out);
  Serial.println("Executing command6");
}

void command7() {
  // Code for command7
   servo1.write(in);             
    servo2.write(in);    
    servo3.write(in);
    servo4.write(out); 
    delay(200);
    servo5.write(in);
  Serial.println("Executing command7");
}
void command8() {
  // Code for command8
  servo1.write(out);             
    servo2.write(out);    
    servo3.write(out);
    servo4.write(in); 
    servo5.write(in);
  Serial.println("Executing command8");
}

void command9() {
  // Code for command9
  servo1.write(out);             
    servo2.write(out);    
    servo3.write(out);
    servo4.write(out); 
    servo5.write(mid);
  Serial.println("Executing command9");
}
void command10() {
  // Code for command10
  servo1.write(out);             
    servo2.write(in);    
    servo3.write(in);
    servo4.write(in); 
    servo5.write(out);
  Serial.println("Executing command10");
}

void command11() {
  // Code for command11
  servo1.write(90);             
    servo2.write(in);    
    servo3.write(in);
    servo4.write(in); 
    delay(200);
    servo5.write(in);
  Serial.println("Executing command11");
}
void command12() {
  // Code for command12
    servo1.write(out);             
    servo2.write(out);    
    servo3.write(out);
    servo4.write(out); 
    servo5.write(out);
    delay(1000);
  servo1.write(in);             
    servo2.write(in);    
    servo3.write(in);
    servo4.write(in); 
    delay(200);
    servo5.write(in);
  Serial.println("Executing command12");
}

void command13() {
  // Code for command13
  servo1.write(in);             
    servo2.write(in);    
    servo3.write(out);
    servo4.write(out); 
    servo5.write(out);
  Serial.println("Executing command13");
}
void command14() {
  // Code for command14
  servo1.write(in);             
    servo2.write(130);    
    servo3.write(90);
    servo4.write(in); 
    delay(200);
    servo5.write(in);
  Serial.println("Executing command14");
}

void command15() {
  servo1.write(out);             
    servo2.write(out);    
    servo3.write(out);
    servo4.write(out); 
    servo5.write(out);
    delay(1000);
  servo1.write(in);             
    servo2.write(in);    
    servo3.write(out);
    servo4.write(out); 
    servo5.write(in);
  // Code for command15
  Serial.println("Executing command15");

}