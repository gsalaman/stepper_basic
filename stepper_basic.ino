

#define STEP_PIN  2
#define DIR_PIN   3
#define MS1_PIN   4
#define MS2_PIN   5  
#define ENABLE_PIN 6

void setup() 
{
  Serial.begin(9600);

  pinMode(STEP_PIN, OUTPUT);
  pinMode(DIR_PIN, OUTPUT);
  pinMode(MS1_PIN, OUTPUT);
  pinMode(MS2_PIN, OUTPUT);
  pinMode(ENABLE_PIN, OUTPUT);

  //set step size.
  digitalWrite(ENABLE_PIN, LOW);

  digitalWrite(DIR_PIN, HIGH);

  // LOW/LOW = full step.
  // HIGH/HIGH = 1/8 step
  digitalWrite(MS1_PIN, HIGH);
  digitalWrite(MS2_PIN, HIGH);

  Serial.println("inited");
}

void loop() 
{

    digitalWrite(STEP_PIN, HIGH);
    delay(1);
    digitalWrite(STEP_PIN,LOW);
    delay(1);


}
