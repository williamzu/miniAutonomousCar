/ * Created by William Lima * /

 #include <Servo.h> // includes servo motor manipulation library.
 #include <Ultrasonic.h> // includes library for manipulating the ultrasonic sensor.

 #define echoPin 8 // Pin 8 will be the blue sensor Echo
 #define echoPin2 4
 #define trigPin2 3
 #define trigPin 12 // Pin 12 will be the green sensor TRig
 Servo servo_ultra_sonico, motorRight, motorLeft; // naming the servo motors
 Ultrasonic ultrasonic (12.8); // naming the sensor
 Ultrasonic ultrasonic2 (3,4);
 float distance = 0, distance2 = 0;


 // run on Arduino startup
 void setup () {
  Serial.begin (9600); // initializes serial communication to show data on an LCD display
  
  // servo motor configurations
  servo_ultra_sonico.attach (13); // attach the logical servo motor to the physical on pin 13.
  pinMode (trigPin, OUTPUT); // define the triger pin as an output.
  pinMode (trigPin2, OUTPUT); // define the triger pin as an output.
  pinMode (echoPin, INPUT); // define the echo pin as an input.
  pinMode (echoPin2, INPUT); // define the echo pin as an input.
  servo_ultra_sonico.write (90); // initially sensor servo at 90 degrees
  start_Motor;
  rotacao_Parado;
 
 }
 // main function of Arduino
 void loop () {
  walk();
  Serial.println (lerSonar2 ());
 }

 // function to join other functions to be able to walk with the robot
 void floor () {
  repositionServoSonar ();
  int distancia = lerSonar ();
  int distancia2 = lerSonar2 ();
  if ((distance> 20) && (distance2> 10)) {
   rotacao_Frente ();
  } else {
   positionCarCarBetterPath ();
   walk();
  }
 }
 // function to read the ultrasonic sensor
 int lerSonar () {
   return ultrasonic.Ranging (CM);
      
 }
 
 int lerSonar2 () {
   return ultrasonic2.Ranging (CM);
      
 }
 // function to calculate the distance from the center
 int calculateDistanceCenter () {
   servo_ultra_sonico.write (90);
   delay (250);
   int sonarRead = sonarRead ();
   return SonarRead;
 }
 // function to calculate the distance from the right
 int calculateDistanceRight () {
   servo_ultra_sonico.write (10);
   delay (250);
   int sonarRead = sonarRead ();
   return SonarRead;
 }
 // function to calculate the distance from the left
 int calculateDistanceLeft () {
   servo_ultra_sonico.write (180);
   delay (250);
   int sonarRead = sonarRead ();
   return SonarRead;
 }
 // function to take the distance read and calculate the best distance
 char calculatesBetterDistancia () {
  int left = calculateDistanceLeft ();
  int centro = calculateDistanciaCentro ();
  int right = calculateDistanceRight ();
  int sensor2 = readSonar2 ();
  
  repositionServoSonar ();
  int majorDistancia = 0;
  char MelhorDistancia = '0';
  if (center> right && center> left) {
   bestDistancia = 'c';
   maiorDistancia = center;
  } else if (right> center && right> left) {
   bestDistancia = 'd';
   greaterDistance = right;
  } else if (left> center && left> right) {
   bestDistancia = 'e';
   greaterDistance = left;
  }
  if (greaterDistance <= 20 || sensor2 <= 10) {
   rotacao_Re ();
   rotacao_Re ();
   positionCarCarBetterPath ();
  }
  repositionServoSonar ();
  return bestDistancia;
Serial.println (bestDistancia);
 }
 // function to place the cart at the best distance, that is, rotate it to the best distance
 void positionsCarCarBetterPath () {
  char MelhorDist = calculaMorhorDistancia ();
  if (MelhorDist == 'c') {
   walk();
  } else if (MelhorDist == 'd') {
   rotacao_Right ();
   rotacao_Right ();
   rotacao_Right ();
  } else if (MelhorDist == 'e') {
   left_rotation ();
   left_rotation ();
   left_rotation ();
  } else {
   rotacao_Re ();
  }
  repositionServoSonar ();
 }
 // function to leave the robot's "eye" sensor in the center
 void repositionesServoSonar () {
  servo_ultra_sonico.write (90);
   
 }
 
 // function that makes the car (servo motor) stop
 void rotacao_Parado ()
 {
   motorRight.detach (); // for engines
   left engine.detach ();
 }
 // function that makes the car (servo motor) move forward
 void rotacao_Frente ()
 {
    
   start_Motor (); // use the engine start function
   motorRight.write (0); // engine on the right rotates forward
   left.write (180); // engine on the left rotates forward
   delay (400);
   rotacao_Parado ();
   distance = distance + 1;
 }
 // function that makes the car (servo motor) move backwards
 void rotacao_Re ()
 {
   tone (10,300,300);
   tone (10,300,300);
   start_Motor (); // pretty much the same as the function above
   tone (10,300,300);
   motorRight.write (180);
   motorEsquerda.write (0);
   delay (800);
   tone (10,300,300);
   rotacao_Parado ();
   distance = distance + 1;
 }
