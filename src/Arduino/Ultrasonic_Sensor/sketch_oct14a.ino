int trig = 2;
int echo = 3;
float duration;
float distance;

void setup() {
  Serial.begin(9600);
  pinMode(trig,OUTPUT);
  pinMode(echo,INPUT);

}

void loop() {
  digitalWrite(trig,HIGH);
  delay(10);
  digitalWrite(trig,LOW);
  duration = pulseIn(echo,HIGH); 
  distance = ((34000 * duration) / 1000000) / 2;  
  Serial.print(distance);
  Serial.println("cm");
  delay(990);
}
