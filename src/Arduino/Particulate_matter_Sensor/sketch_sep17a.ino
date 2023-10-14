int VO = A0;
int V_LED = 12;
float VO_value = 0;
float Voltage = 0;
float dustDensity = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(V_LED, OUTPUT);
  pinMode(VO, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(V_LED, LOW);
  delayMicroseconds(280);
  VO_value = analogRead(VO);
  delayMicroseconds(40);
  digitalWrite(V_LED, HIGH);
  delayMicroseconds(9600);

  Voltage = VO_value * 5.0 / 1023.0;
  dustDensity = (Voltage - 0.3) / 0.005;

  Serial.print("Voltage: ");
  Serial.println(Voltage);
  Serial.print("Dust Density: ");
  Serial.println(dustDensity);

  delay(1000);
}
