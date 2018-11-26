String voice;

int relay1 = 6;
int relay2 = 7;
int relay3 = 10;
int relay4 = 11;



void setup() {
  Serial.begin(9600);
  pinMode(relay1, OUTPUT);
  pinMode(relay2, OUTPUT);
  pinMode(relay3, OUTPUT);
  pinMode(relay4, OUTPUT);
  digitalWrite(relay1,HIGH);
  digitalWrite(relay2,HIGH);
  digitalWrite(relay3,HIGH);
  digitalWrite(relay4,HIGH);
  
}

void loop() {
 
  while(Serial.available()) {
    delay(10);
    char c=Serial.read();
    if(c=='#')
    {break; }
    voice += c;
}

if (voice.length() > 0) {
  Serial.println(voice);
  if (voice == "light on")
  {digitalWrite(relay1,LOW);
  Serial.println("LIGHT IS ON");
  }
  else if (voice == "fan on")
  { digitalWrite(relay2,LOW);
    Serial.println("FAN IS ON");}
  else if (voice == "mobile charger on"){
    digitalWrite(relay3,LOW);
    Serial.println("YOUR MOBILE IS CHARGING");}
  else if (voice == "laptop charger on"){
    digitalWrite(relay4,LOW);
    Serial.println("YOUR LAPPY IS CHARGING");}
  else if (voice == "light off" || voice == "light of"){
    digitalWrite(relay1,HIGH);
    Serial.println("YOUR LIGHT IS SWITCHED OFF");}
  else if (voice == "fan off" || voice == "fan of"){
    digitalWrite(relay2,HIGH);
    Serial.println("YOUR FAN IS SWITCHED OFF");}
  else if (voice == "mobile charger off" || voice == "mobile charger of"){
    digitalWrite(relay3,HIGH);
    Serial.println("YOUR MOBIEL CHARGER IS SWITCHED OFF");}
  else if (voice == "laptop charger off" || voice == "laptop charger of"){
    digitalWrite(relay4,HIGH);
    Serial.println("YOUR LAPPY CHARGER IS SWITCHED OFF");}
  else if (voice == "all on"){
    digitalWrite(relay1,LOW);
    digitalWrite(relay2,LOW);
    digitalWrite(relay3,LOW);
    digitalWrite(relay4,LOW);
    Serial.println("ALL APPLICANCES ARE SWITCHED ON");}
  else if (voice == "all of" ||voice == "all off" ){
    digitalWrite(relay1,HIGH);
    digitalWrite(relay2,HIGH);
    digitalWrite(relay3,HIGH);
    digitalWrite(relay4,HIGH);
    Serial.println("ALL APPLICANCES ARE SWITCHED OFF");}
  
  }
  
voice="";

}





