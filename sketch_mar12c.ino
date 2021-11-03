#define TRIG 2
#define ECHO 3
#define BUZZER 13
int once = 0;

void setup ()
{
  pinMode(TRIG,OUTPUT);
  pinMode(ECHO,INPUT);
  Serial.begin(9600);
  Serial.println("Start");
  
  pinMode(BUZZER,OUTPUT);
  Serial.begin(9600);
  Serial.println("Start");
}

void loop ()
{
  Serial.println("Initiating Reading");
  digitalWrite(TRIG,HIGH);
  delay(10);
  digitalWrite(TRIG,LOW);
  int distance = pulseIn(ECHO,HIGH)/2;

  distance = distance/29;
  Serial.print("Distance in cm is ");
  Serial.println(distance);
  
  if (distance >= 300)
  {
    int p = 5;
    int i;
    Serial.println("Starting buzzer");
    for(i = 0; i<500; i++)
      {
        digitalWrite(BUZZER,HIGH);
        delay(p);
        digitalWrite(BUZZER,LOW);
        delay(p);
      }
  
     Serial.println("Stopping buzzer");
    }
  
  
  else if(distance <= 10)
  {
    int p = 1;
    int i;
    Serial.println("Starting buzzer");
    for(i = 0; i<500; i++)
      {
        digitalWrite(BUZZER,HIGH);
        delay(p);
        digitalWrite(BUZZER,LOW);
        delay(p);
      }
     
     Serial.println("Stopping buzzer");
    }
}
