
  //  +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
  //  ATtiny85 - ""Effet Knight Rider" avec potentiomètre
  //  - LEDs : PB0, PB1, PB3, PB4
  //  - Potentiomètre sur A1 (PB2) pour régler la vitesse
  //  https://www.youtube.com/c/ClaudeDufourmont
  //  https://github.com/claudiusmarius
  //  +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

  const int leds[] = {0, 1, 3, 4}; // PB0, PB1, PB3, PB4
  const int potPin = 1;            // A1

  void setup() 
  {
  // Configuration de toutes les LEDs comme sorties
  for (int i = 0; i < 4; i++) 
  {
    pinMode(leds[i], OUTPUT);
    digitalWrite(leds[i], LOW);
  }
  }

  void loop() 
  {
  // Lecture dela valeur du potentiomètre pour ajuster la vitesse
  int potValue = analogRead(potPin); // 0-1023
  
  // Convertion en délai entre LEDs (50 à 500 ms)
  int delayTime = map(potValue, 0, 1023, 50, 500);  

  // Allumage de la première à la dernière LED
  for (int i = 0; i < 4; i++) 
  {
    allumeLED(i);
    delay(delayTime);
  }

  // Retour de la dernière à la première LED
  for (int i = 2; i >= 1; i--) // on évite la première et dernière répétées
  { 
    allumeLED(i);
    delay(delayTime);
  }
  }
  
  void allumeLED(int index) 
  {
  // Fonction pour n'allumer qu'une seule LED à la fois
  for (int i = 0; i < 4; i++) 
  {
    digitalWrite(leds[i], i == index ? HIGH : LOW);
  }
  }
