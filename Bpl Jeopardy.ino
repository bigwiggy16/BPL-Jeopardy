const int PENALTY = 250;

//pin variables
int p1buzz = 8;
int p2buzz = 9;
int p3buzz = 10;
int hostbuzz = 12;

int p1led = 3;
int p2led = 4;
int p3led = 5;
int hostled = 7;

//player buzz in variables
int buzz1_state = 0;
int buzz2_state = 0;
int buzz3_state = 0;

int state = 0; //Active buzzers variable

//time penalty variables
int p1penalty = 0;
int p2penalty = 0;
int p3penalty = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(p1buzz, INPUT);
  pinMode(p2buzz, INPUT);
  pinMode(p3buzz, INPUT);
  pinMode(hostbuzz, INPUT);
  pinMode(p1led, OUTPUT);
  pinMode(p2led, OUTPUT);
  pinMode(p3led, OUTPUT);
  pinMode(hostled, OUTPUT);

  digitalWrite(p1led, LOW);
  digitalWrite(p2led, LOW);
  digitalWrite(p3led, LOW);
  digitalWrite(hostled, LOW);
  int state = digitalRead(hostbuzz);

}

void loop() {
  // Read buzzer states
  buzz1_state = digitalRead(p1buzz);
  buzz2_state = digitalRead(p2buzz);
  buzz3_state = digitalRead(p3buzz);
  
  //Buzzers not Active Mode.
  while (state = HIGH) { 
    digitalWrite(hostled, LOW);

    if (buzz1_state = LOW) {
      p1penalty = millis();
    }
    if (buzz2_state = LOW) {
      p2penalty = millis();
    }
    if (buzz3_state = LOW) {
      p3penalty = millis();
    }
    state = digitalRead(hostbuzz);
  }

  //Active Buzzers
  while (state = LOW) {
    digitalWrite(hostled, HIGH);

    if (buzz1_state = LOW and p1penalty + PENALTY <= millis() ) {  //this is the time penalty check. 
      digitalWrite(p1led, HIGH);
    }
    if (buzz2_state = LOW and p2penalty + PENALTY <= millis() ) {
      digitalWrite(p2led, HIGH);
    }
    if (buzz3_state = LOW and p3penalty + PENALTY <= millis() ) {
      digitalWrite(p3led, HIGH);
    }
    state = digitalRead(hostbuzz);
  }
  state = digitalRead(hostbuzz);
}
