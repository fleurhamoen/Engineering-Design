//I just put them in random pins now, but this is how you could define multiple 
int LED_Pin = 13;
int vibr_Pin1 = 3;
int vibr_Pin2 = 4;
int vibr_Pin3 = 5;
int vibr_Pin4 = 6;


void setup(){
  pinMode(LED_Pin, OUTPUT);
  pinMode(vibr_Pin1, INPUT); //set vibr_Pin input for measurment
  //I don't know if what I did here is possible, but they all need to be an INPUT right? 
  pinMode(vibr_Pin2, INPUT); //set vibr_Pin input for measurment
  pinMode(vibr_Pin3, INPUT); //set vibr_Pin input for measurment
  pinMode(vibr_Pin4, INPUT); //set vibr_Pin input for measurment

  Serial.begin(9600); //init serial 9600
 // Serial.println("----------------------Vibration demo------------------------");
}

//now it only prints the measurement of the first vibration pin, can easily print all if needed by copy-pasting this section
void loop(){
  long measurement1 =TP_init1();
  delay(50);
 // Serial.print("measurement = ");
  
  //for this if-statement, I now made it so that it only prints the first measurement if all measurements are above 10000. Needs to be tested.
  if (measurement1 > 10000 && measurement2 > 10000 && measurement3 > 10000 && measurement4 > 10000){
    Serial.println(measurement1);
  }
}

//measurement returns the length of the pulse, so the interval between two vibrations. I don't think this is too important but it shows that it works. Needs to be tested
long TP_init1(){
  delay(10);
  long measurement1=pulseIn (vibr_Pin1, HIGH);  //wait for the pin to get HIGH and returns measurement
  return measurement1;
}

//made four different functions now, needs to be tested
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
