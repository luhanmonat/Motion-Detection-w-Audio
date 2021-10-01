/* Motion Sensor audible alarm
 * 9/21 Luhan Monat
 * for ATtiny85 1Mhz clock
 * Uses analog output from modified RCWL-0516
 * to create proportional sound level on speaker
 */


#define MIN 50

long  average;

void setup() {

  pinMode(PB3,OUTPUT);
}

void  loop() {
int data,freq,i;

    data=analogRead(A2);            //RCWL analog data
    average=(19*average+data)/20;  // running average (baseline)
    freq=abs(data-average);         // deviation from baseline
    if(freq>MIN)                    // only make sound if over minimum
      Squawk(freq);                 // make a sound
    delayMicroseconds(1000);
}

// Make sound proportional to input variable

void  Squawk(int f) {
int i,k;

  digitalWrite(PB3,HIGH);            // raise data line
  delayMicroseconds(1000);
  digitalWrite(PB3,LOW);         // always reset the line
  for(i=0;i<10000;i+=f)
    delayMicroseconds(50);       // variable pulse width

}
