#include <SoftwareSerial.h>
#include <AFMotor.h>
#define light_m1  14    //LED Motor 1   pin A0 for Arduino Uno
#define light_m2  16    //LED Motor 2   pin A2 for Arduino Uno
#define light_m3  18    //LED Motor 3   pin A4 for Arduino Uno

boolean lightFront = false;
int cont_aux = 0;
SoftwareSerial myBT(10, 11); // TX, RX

AF_DCMotor motor1(1, MOTOR12_8KHZ); // crear motor #1, 64KHz pwm
AF_DCMotor motor2(2, MOTOR12_8KHZ); // crear motor #2, 64KHz pwm
AF_DCMotor motor3(3, MOTOR12_8KHZ); // crear motor #3, 64KHz pwm
//AF_DCMotor motor4(4, MOTOR34_8KHZ); // crear motor #3, 64KHz pwm

void setup() {
  
  Serial.begin(9600); // Open serial communications and wait for port to open:
  myBT.begin(9600);
  

  pinMode(light_m1, OUTPUT);
  pinMode(light_m2, OUTPUT);
  pinMode(light_m3, OUTPUT);
  
  
  motor1.setSpeed(200); // Colocar la velocidad del motor 3 a 150
  motor2.setSpeed(200); // Colocar la velocidad del motor 3 a 150
  motor3.setSpeed(200); // Colocar la velocidad del motor 3 a 150
  //motor4.setSpeed(255); // Colocar la velocidad del motor 3 a 150
  
  
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }

  Serial.println("Iniciando BLUETOHT CON SEÑALES PARA EL MOTOR ...");

}

void loop() {
  
  while (myBT.available()) {

    int ch = myBT.read();

    //--- "MOTOR 1" ---
    if (ch == 'A' )
    {
      //Motor1();
    }
    
    //--- "MOTOR 2" ---
    if (ch == 'I' )
    {
      Motor4();
    }
    
    //--- "MOTOR 3" ---
    if (ch == 'D' )
    {
      patront();
      delay(400);
      patront();
      delay(200);
      
    }
    
    //--- "MOTOR 4" ---
    if (ch == 'C' )
    {
      //Motor4();
      patronbb();
      delay(500);
      patronbb();
      delay(500);
      patronbb();
      delay(200);
   
    }

    //--- "MOTOR 5" ---
    if (ch == 'S' )
    {
      
      //PATRON EMERGENCIA
      patron_eme();
      delay(500);
      patron_eme();
      delay(500);
      patron_eme();
      delay(200);
    }
    
  }

}


//*************************************************************************

void Motor4()
{
  
  if (cont_aux%2 == 0)
  {
    digitalWrite(light_m1, HIGH);
    digitalWrite(light_m2, HIGH);
    digitalWrite(light_m3, HIGH);
  }
  else
  {
    digitalWrite(light_m1, LOW);
    digitalWrite(light_m2, LOW);
    digitalWrite(light_m3, LOW);  
  }
  cont_aux = cont_aux + 1;
  
}

void patronbb()
{
      int delaypatron = 300;

      motor1.run(BACKWARD); // BACKWARD
      digitalWrite(light_m1, HIGH);
      motor2.run(BACKWARD); // BACKWARD
      digitalWrite(light_m2, HIGH);
      motor3.run(BACKWARD); // BACKWARD
      digitalWrite(light_m3, HIGH);
      delay(delaypatron);
      
      
      motor1.run(RELEASE); // STOP
      motor2.run(RELEASE); // STOP
      motor3.run(RELEASE); // STOP
      digitalWrite(light_m1, LOW);
      digitalWrite(light_m2, LOW);
      digitalWrite(light_m3, LOW);
      //delay(delaypatron);
      
      //***** Repite
      
      motor1.run(FORWARD); // BACKWARD
      digitalWrite(light_m1, HIGH);
      motor2.run(FORWARD); // BACKWARD
      digitalWrite(light_m2, HIGH);
      motor3.run(FORWARD); // BACKWARD
      digitalWrite(light_m3, HIGH);
      delay(delaypatron);
      
      
      motor1.run(RELEASE); // STOP
      motor2.run(RELEASE); // STOP
      motor3.run(RELEASE); // STOP
      digitalWrite(light_m1, LOW);
      digitalWrite(light_m2, LOW);
      digitalWrite(light_m3, LOW);

      //***** Repite
      
      motor1.run(BACKWARD); // BACKWARD
      digitalWrite(light_m1, HIGH);
      motor2.run(BACKWARD); // BACKWARD
      digitalWrite(light_m2, HIGH);
      motor3.run(BACKWARD); // BACKWARD
      digitalWrite(light_m3, HIGH);
      delay(delaypatron);
      
      
      motor1.run(RELEASE); // STOP
      motor2.run(RELEASE); // STOP
      motor3.run(RELEASE); // STOP
      digitalWrite(light_m1, LOW);
      digitalWrite(light_m2, LOW);
      digitalWrite(light_m3, LOW);
}

void patron_eme()
{
      int delaypatron = 300;

      motor2.run(BACKWARD); // BACKWARD
      digitalWrite(light_m1, HIGH);
      delay(delaypatron);
      motor2.run(RELEASE); // STOP
      digitalWrite(light_m1, LOW);
      
  
      
      motor1.run(FORWARD); // BACKWARD
      digitalWrite(light_m1, HIGH);
      motor2.run(FORWARD); // BACKWARD
      digitalWrite(light_m2, HIGH);
      motor3.run(FORWARD); // BACKWARD
      digitalWrite(light_m3, HIGH);
      delay(600);
      
      
      motor1.run(RELEASE); // STOP
      motor2.run(RELEASE); // STOP
      motor3.run(RELEASE); // STOP
      digitalWrite(light_m1, LOW);
      digitalWrite(light_m2, LOW);
      digitalWrite(light_m3, LOW);

      //*****

      motor2.run(BACKWARD); // BACKWARD
      digitalWrite(light_m1, HIGH);
      delay(delaypatron);
      motor2.run(RELEASE); // STOP
      digitalWrite(light_m1, LOW);
      
      
      motor1.run(FORWARD); // BACKWARD
      digitalWrite(light_m1, HIGH);
      motor2.run(FORWARD); // BACKWARD
      digitalWrite(light_m2, HIGH);
      motor3.run(FORWARD); // BACKWARD
      digitalWrite(light_m3, HIGH);
      delay(600);
      
      
      motor1.run(RELEASE); // STOP
      motor2.run(RELEASE); // STOP
      motor3.run(RELEASE); // STOP
      digitalWrite(light_m1, LOW);
      digitalWrite(light_m2, LOW);
      digitalWrite(light_m3, LOW);


     
}


void patront()
{

      
      motor1.run(BACKWARD); // BACKWARD
      digitalWrite(light_m1, HIGH);
      delay(600);
      motor1.run(RELEASE); // STOP
      digitalWrite(light_m1, LOW);
      
      motor3.run(BACKWARD); // BACKWARD
      digitalWrite(light_m3, HIGH);
      delay(600);
      motor3.run(RELEASE); // STOP
      digitalWrite(light_m3, LOW);



      motor1.run(FORWARD); // BACKWARD
      digitalWrite(light_m1, HIGH);
      delay(350);
      motor1.run(RELEASE); // STOP
      digitalWrite(light_m1, LOW);
      
      motor2.run(FORWARD); // BACKWARD
      digitalWrite(light_m2, HIGH);
      delay(420);
      motor2.run(RELEASE); // STOP
      digitalWrite(light_m2, LOW);



      
      
      motor1.run(BACKWARD); // BACKWARD
      digitalWrite(light_m1, HIGH);
      motor2.run(BACKWARD); // BACKWARD
      digitalWrite(light_m2, HIGH);
      motor3.run(BACKWARD); // BACKWARD
      digitalWrite(light_m3, HIGH);
      delay(300);
      
      
      motor1.run(RELEASE); // STOP
      motor2.run(RELEASE); // STOP
      motor3.run(RELEASE); // STOP
      digitalWrite(light_m1, LOW);
      digitalWrite(light_m2, LOW);
      digitalWrite(light_m3, LOW);

      motor1.run(FORWARD); // BACKWARD
      digitalWrite(light_m1, HIGH);
      motor2.run(FORWARD); // BACKWARD
      digitalWrite(light_m2, HIGH);
      motor3.run(FORWARD); // BACKWARD
      digitalWrite(light_m3, HIGH);
      delay(300);
      
      
      motor1.run(RELEASE); // STOP
      motor2.run(RELEASE); // STOP
      motor3.run(RELEASE); // STOP
      digitalWrite(light_m1, LOW);
      digitalWrite(light_m2, LOW);
      digitalWrite(light_m3, LOW);

}
