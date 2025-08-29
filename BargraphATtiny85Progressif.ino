  /*
  ATtiny85 Bargraph simple avec potentiomètre
  - Potentiomètre 10K curseur sur A1 (PB2) et une extémité sur +5V et l'autre sur GND
  - LEDs sur PB0, PB1, PB3, PB4 puis une résistance chacune de 680 ohms vers le GND
  - Selon la tension sur A1, une seule LED allumée à la fois selon la tension
  https://www.youtube.com/c/ClaudeDufourmont
  https://github.com/claudiusmarius
  */

  const int potPin = 1; // A1
  const int leds[] = {0, 1, 3, 4}; // PB0, PB1, PB3, PB4

  void setup() // Configurer toutes les LEDs comme sorties
  {
  
  for (int i = 0; i < 4; i++) 
  {
    pinMode(leds[i], OUTPUT);
    digitalWrite(leds[i], LOW);
  }
  }

  void loop() 
  {
  int val = analogRead(potPin); // lecture potar 0-1023
  int index = -1;               // LED à allumer

  // Déterminer quelle LED allumer
  if (val > 800) index = 3;
  else if (val > 600) index = 2;
  else if (val > 400) index = 1;
  else if (val > 200) index = 0;
  else index = -1; // aucune LED

  // Éteindre toutes les LEDs
  for (int i = 0; i < 4; i++) 
  {
    digitalWrite(leds[i], LOW);
  }

  // Allumer seulement celle correspondant au seuil
  if (index >= 0) digitalWrite(leds[index], HIGH);

  delay(50);
  }
