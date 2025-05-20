# 2025 Stepper notes

Trying this one for Dawson:
https://www.adafruit.com/product/858?gQT=1

Wires:
Pink and Orange to one coil (a)
Yellow and blue to the other (b)




# Basic Stepper Motor control
Let's say we want more control over a motor...either exact speeds or exact number of revolutions (or both!).  This is where stepper motors come into play.


Parts needed:
* Redboard
* Stepper Motor
* Stepper driver board
* External battery - either 9v or a 6v pack will do
* Small slotted screwdriver

We'll be using sparkfun's "easy driver" board:  https://www.sparkfun.com/products/12779

I'll be pairing it with one of their small steppers:  https://www.sparkfun.com/products/10551

## Driver board connections
Solder on headers to the driver board and plug it into the breadboard.  Make the following connections to the UNO:
| Uno Pin | Driver Pin |
|---------|------------|
| 2 | STEP |
| 3 | DIR |
| 4 | MS1 |
| 5 | MS2 | 
| 6 | ENABLE |
| GND | PWR IN GND |

The stepper itself has two coils...on the stepper we're using, brown and black are for one coil, and orange and yellow are for the other.  Pick two to attach to the "A" connectors, and two to the "B".  Polarity doesn't matter.

Finally, you are going to want to connect your external batt to the two PWR IN pins...and note that GND here is also going to GND on the UNO.

## The sketch
Run the sketch...your motor should spin.  Adjust the small, white pot on the driver board with your screwdriver until you get a nice, smooth motion.  This is controlling the current that the stepper is using.

Here's a closer look at what's going on, and some suggestions for controlling the stepper.

### Step Size
We select a "step size" by using MS1 and MS2.  In our current sketch, we've got both "high"...here's the truth table for which values select which step sizes:
| MS1 | MS2 | Result |
|--|--|--|
| L | L | Full step (2 phase) |
| H | L | Half step |
| L | H | Quarter Step | 
| H | H | Eighth Step |

So, if we make both "LOW", we'll be doing full steps...meaning we'll spin eight times as fast.  Try it!

### Direction
The `DIR` pin controls which way our stepper is spinning...and this depends on the polarity of the coil connections.  If we want to reverse the direction, change this line (in setup):
```
  digitalWrite(DIR_PIN, HIGH);
```
to 
```
  digitalWrite(DIR_PIN, LOW);
```

### Individual Steps
The driver does one "step" every time we bring `STEP_PIN` High; if you look at "loop", you'll see we're continually doing this...1 ms high, 1 ms low  If you increase the delay here, you'll slow the motor down....and if you decrease it, you'll speed it up.  Note there *is* a low limit at which the motor can't keep up...and it'll just stop.  If you want a faster motor, (like for car wheels), your best bet is to do a traditional motor with a higher RPM.  Or use gears.

With this, you can play around with the step size and time to count how many steps make a full revolution.

## Next steps:
Figure out a way to make the motor do exactly one full rotation, then wait a second, then repeat...

Add control!  Use buttons, or a pot, or serial, or something else to control our motor.

