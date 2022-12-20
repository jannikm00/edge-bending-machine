int S1 = 2;       //Schalter Anlage An/Aus
int S2 = 3;       //Taster Wange senken NO
int S3 = 4;       //Taster Wange heben NO
int S4 = A2;      //Taster Hoch
int S5 = A3;      //Taster Runter
int SENSB11 = 5;  //Sensor Spannwange geschlossen NC
int SENSB12 = 6;  //Sensor Spannwange geöffnet NC
int SENSB13 = A0; //Sensor Anschlag unten
int SENSB14 = A1; //Sensor Anschlag oben
int F3 = 7;       //Motorschutz
int P1 = 8;       //Leuchte Anlage An
int P2 = 9;       //Leuchte Spannwange geschlossen
int P3 = 10;      //Leuchte Störung
int Q1 = 11;      //Motor Spannwange schließen
int Q2 = 12;      //Motor Spannwange öffnen
int Q3 = A3;      //Motor runter
int Q4 = A4;      //Motr
void setup() {
  Serial.begin(9600);
  pinMode(S1, INPUT);
  pinMode(S2, INPUT);
  pinMode(S3, INPUT);
  pinMode(SENSB11, INPUT);
  pinMode(SENSB12, INPUT);
  pinMode(F3, INPUT);
  pinMode(P1, OUTPUT);
  pinMode(P2, OUTPUT);
  pinMode(P3, OUTPUT);
  pinMode(Q1, OUTPUT);
  pinMode(Q2, OUTPUT);
  for (int x = 0; x < 2; x++) {  //LED test
    int del = 30;
    digitalWrite(Q1, HIGH);
    delay(del);
    digitalWrite(Q1, LOW);
    digitalWrite(Q2, HIGH);
    delay(del);
    digitalWrite(Q2, LOW);
    digitalWrite(P2, HIGH);
    delay(del);
    digitalWrite(P2, LOW);
    digitalWrite(P1, HIGH);
    delay(del);
    digitalWrite(P1, LOW);
    digitalWrite(P3, HIGH);
    delay(del);
    digitalWrite(P3, LOW);
    digitalWrite(P3, HIGH);
    delay(del);
    digitalWrite(P3, LOW);
    digitalWrite(P1, HIGH);
    delay(del);
    digitalWrite(P1, LOW);
    digitalWrite(P2, HIGH);
    delay(del);
    digitalWrite(P2, LOW);
    digitalWrite(Q1, HIGH);
    delay(del);
    digitalWrite(Q1, LOW);
    digitalWrite(Q2, HIGH);
    delay(del);
    digitalWrite(Q2, LOW);
  }
}
void loop() {
  if (digitalRead(F3) == HIGH) {  //Störung LED
    digitalWrite(P3, LOW);
  } else {
    digitalWrite(P3, HIGH);
  }
  if (digitalRead(S1) && (digitalRead(F3)) == HIGH) {  //Anlage An aus Check
    digitalWrite(P1, HIGH);



    if ((digitalRead(SENSB11) == LOW && digitalRead(S2) == HIGH) && digitalRead(SENSB12) == HIGH) {  //Steuerung zufahren
      while (digitalRead(SENSB11) == LOW && digitalRead(F3) && digitalRead(S1) == HIGH) {            //Sensorcheck geschlossen Anschlag
        digitalWrite(Q1, HIGH);
      }
      digitalWrite(Q1, LOW);
    }



    if ((digitalRead(SENSB12) == LOW && digitalRead(S3) == HIGH) && digitalRead(SENSB11) == HIGH) {  //Steuerung auffahren
      while (digitalRead(SENSB12) == LOW && digitalRead(F3) && digitalRead(S1) == HIGH) {            //Sensorcheck geöffnet Anschlag
        digitalWrite(Q2, HIGH);
      }
      digitalWrite(Q2, LOW);

}

      if ((digitalRead(SENSB13) == LOW && digitalRead(S4) == HIGH) && digitalRead(SENSB14) == HIGH) {
        while (digitalRead(SENSB13) == LOW && digitalRead(F3) && digitalRead(S1) == HIGH) {
          digitalWrite(Q3, HIGH);
        }
        digitalWrite(Q3, LOW);


      }

      else {
        digitalWrite(P1, LOW); //Anlage Aus Lampe Aus
      }

      if (digitalRead(SENSB11) == HIGH) {  //Anschlag LED
        digitalWrite(P2, HIGH);
      }
      digitalWrite(P2, LOW);
    }
  }
}
