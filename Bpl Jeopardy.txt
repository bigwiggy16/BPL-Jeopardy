
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
  //Buzzers not Active Mode.
  while (state = HIGH) { 
    digitalWrite(hostled, LOW);
    buzz1_state = digitalRead(p1buzz);
    buzz2_state = digitalRead(p2buzz);
    buzz3_state = digitalRead(p3buzz);

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
    buzz1_state = digitalRead(p1buzz);
    buzz2_state = digitalRead(p2buzz);
    buzz3_state = digitalRead(p3buzz);

    if (buzz1_state = LOW and p1penalty + 250 <= millis() ) {  //this is the time penalty check. 
      while (state = LOW) {
        digitalWrite(p1led, HIGH);
        state = digitalRead(hostbuzz);
      }
    }
    if (buzz2_state = LOW and p2penalty + 250 <= millis() ) {
      while (state = LOW) {
        digitalWrite(p2led, HIGH);
        state = digitalRead(hostbuzz);
      }
    }
    if (buzz3_state = LOW and p3penalty + 250 <= millis() ) {
      while (state = LOW) {
        digitalWrite(p3led, HIGH);
        state = digitalRead(hostbuzz);
      }
    }
  }


  

}