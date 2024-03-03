
#define led 13  // Declare Pin  for led
#define sensor A0  //Declare Pin for Sensor input
void setup() {
  // put your setup code here, to run once:
  Serial.begin(1000);  //1second = 1000milisecond = 1bit
  pinMode(led, OUTPUT); 
}

void loop() {
  // put your main code here, to run repeatedly:
  int value;
  int temp = analogRead(sensor);   //Reading sensor value
  Serial.println(temp);   //Printing sensor analog value
  int tempC = temp * (5.0 / 1023.0) * 100;   //Conversion of sensor analog value to celcius
  //int tempC=temp/9.31;
  Serial.println(tempC);   //Printing temperature value
  if(tempC<30)
  {
    value=250;  //blinking of led at temp<30
  }
  else if(tempC>30)
  {
    value=500;  //blinking of led at temp>30
  }
    digitalWrite(led, HIGH);     //Toggle Led
  for(int i=value;i>0;i--)
  {
    Serial.print(value);
  }
  digitalWrite(led, LOW);      //Toggle Led
    for(int i=value;i>0;i--)
  {
    Serial.print("/");
  }

}
