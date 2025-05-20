/* Big Easy Driver version.  More current, 16th step control */

#define STEP_PIN   2
#define DIR_PIN    3
#define MS1_PIN    4
#define MS2_PIN    5  
#define ENABLE_PIN 6
#define MS3_PIN    7  // should really put this next to MS1 and MS2, but I want to make it just
                      // an addition to the previous "easy driver".

void setup() 
{
  Serial.begin(9600);

  pinMode(STEP_PIN, OUTPUT);
  pinMode(DIR_PIN, OUTPUT);
  pinMode(MS1_PIN, OUTPUT);
  pinMode(MS2_PIN, OUTPUT);
  pinMode(MS3_PIN, OUTPUT);
  pinMode(ENABLE_PIN, OUTPUT);

  digitalWrite(STEP_PIN, LOW);
  digitalWrite(ENABLE_PIN, LOW);

  digitalWrite(DIR_PIN, HIGH);

  /* Truth table for MS selects:
   *  MS1  MS2  MS3   Step 
   *  L    L    L     Full
   *  H    L    L     Half
   *  L    H    L     Quarter
   *  H    H    L     Eighth
   *  H    H    H     Sixteenth
   */
  digitalWrite(MS1_PIN, LOW);
  digitalWrite(MS2_PIN, LOW);
  digitalWrite(MS3_PIN, LOW);

  Serial.println("inited");
}

void loop() 
{
  int i;

  for (i=0; i<10180; i++)
  {

    digitalWrite(STEP_PIN, HIGH);
    delayMicroseconds(500);
    digitalWrite(STEP_PIN,LOW);
    delayMicroseconds(500);
  }

  delay(3000);

}
