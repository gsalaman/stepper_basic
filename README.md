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




