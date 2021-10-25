//defining multiple sensors
int LED_Pin = 13;
int vibr_Pin1 = 4;
int vibr_Pin2 = 5;
int vibr_Pin3 = 6;
int vibr_Pin4 = 7;

void setup(){
  //set the on-board LED as output
  pinMode(LED_Pin, OUTPUT);
  //set vibr_Pin input for measurement
  pinMode(vibr_Pin1, INPUT); 
  pinMode(vibr_Pin2, INPUT); 
  pinMode(vibr_Pin3, INPUT); 
  pinMode(vibr_Pin4, INPUT); 

  Serial.begin(9600); //init serial 9600
 // Serial.println("----------------------Vibration demo------------------------");
}

//this prints the measurement of all the vibration pins, can easily adjust if needed by deleting lines
void loop(){
  long measurement1 =TP_init1();
  long measurement2 =TP_init2();
  long measurement3 =TP_init3();
  long measurement4 =TP_init4();
  delay(50);
  Serial.print("measurement = ");
  
  //for this if-statement, it prints all measurements if at least one measurement is above 10000.
  if (measurement1 > 10000 || measurement2 > 10000 || measurement3 > 10000 || measurement4 > 10000){
    Serial.print("measurement 1: ");
    Serial.println(measurement1);
    Serial.print("measurement 2: ");
    Serial.println(measurement2);
    Serial.print("measurement 3: ");
    Serial.println(measurement3);
    Serial.print("measurement 4: ");
    Serial.println(measurement4);

  }
}

//measurement returns the length of the pulse in microseconds or gives up and returns 0 if no complete pulse was received within the timeout. Not important for our design goal, but shows that sensors work
long TP_init1(){
  delay(10);
  long measurement1=pulseIn (vibr_Pin1, HIGH);  //wait for the pin to get HIGH and returns measurement
  return measurement1;
}

//four different function that output vibration measurements
long TP_init2(){
  delay(10);
  long measurement2=pulseIn (vibr_Pin2, HIGH);  //wait for the pin to get HIGH and returns measurement
  return measurement2;
}

long TP_init3(){
  delay(10);
  long measurement3=pulseIn (vibr_Pin2, HIGH);  //wait for the pin to get HIGH and returns measurement
  return measurement3;
}

long TP_init4(){
  delay(10);
  long measurement4=pulseIn (vibr_Pin4, HIGH);  //wait for the pin to get HIGH and returns measurement
  return measurement4;
}
