

#define STEP_PIN  2
#define DIR_PIN   3
#define MS1_PIN   4
#define MS2_PIN   5  
#define ENABLE_PIN 6

#define STEPS_PER_ROTATION 540
int step_count = 0;
int dir=LOW;

void setup() 
{
  Serial.begin(9600);

  pinMode(STEP_PIN, OUTPUT);
  pinMode(DIR_PIN, OUTPUT);
  pinMode(MS1_PIN, OUTPUT);
  pinMode(MS2_PIN, OUTPUT);
  pinMode(ENABLE_PIN, OUTPUT);
  
  digitalWrite(ENABLE_PIN, LOW);

  digitalWrite(DIR_PIN, dir);

  // LOW/LOW = full step.
  // HIGH/HIGH = 1/8 step
  digitalWrite(MS1_PIN, LOW);
  digitalWrite(MS2_PIN, LOW);

  Serial.println("inited");
}

void loop() 
{

  // According to the data sheet, we've got 516.096 steps per revolution.
  // We're gonna start by trying one full rotation fwd, then one back (then repeat)

  // Start by taking a step.
  digitalWrite(STEP_PIN, HIGH);
  delay(1);
  digitalWrite(STEP_PIN,LOW);
  delay(2);
  step_count++;

  if (step_count >= STEPS_PER_ROTATION)
  {
    // set the new direction
    if (dir == HIGH)
    {
      dir = LOW;
    }
    else
    {
      dir = HIGH;
    }
    digitalWrite(DIR_PIN, dir);

    // reset our count
    step_count = 0;
  }

}
