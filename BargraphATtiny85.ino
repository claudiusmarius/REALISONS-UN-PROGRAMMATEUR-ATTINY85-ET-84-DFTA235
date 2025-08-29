  /*
  ATtiny85 Bargraph simple avec potentiomètre
  - Potentiomètre 10K curseur sur A1 (PB2) et une extémité sur +5V et l'autre sur GND
  - LEDs sur PB0, PB1, PB3, PB4 puis une résistance chacune de 680 ohms vers le GND
  - Selon la tension sur A1, de 0 à 4 LEDs s'allument
  https://www.youtube.com/c/ClaudeDufourmont
  https://github.com/claudiusmarius
  */

  const int potPin = 1; // A1
  const int led0 = 0;   // PB0  Blue
  const int led1 = 1;   // PB1  Yellow
  const int led2 = 3;   // PB3  Red
  const int led3 = 4;   // PB4  Green

  void setup() 
  {
  // Configurer toutes les LEDs comme sorties
  pinMode(led0, OUTPUT);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);

  // Éteindre toutes les LEDs au départ
  digitalWrite(led0, LOW);
  digitalWrite(led1, LOW);
  digitalWrite(led2, LOW);
  digitalWrite(led3, LOW);
  }

  void loop() 
  {
  // Lire la tension du potentiomètre (0 à 1023)
  int val = analogRead(potPin);

  // Déterminer quelles LEDs allumer
  if (val > 800) // tension très haute
  {            
  digitalWrite(led0, HIGH);
  digitalWrite(led1, HIGH);
  digitalWrite(led2, HIGH);
  digitalWrite(led3, HIGH);
  } 
  
  else if (val > 600) // tension haute
  {       
  digitalWrite(led0, HIGH);
  digitalWrite(led1, HIGH);
  digitalWrite(led2, HIGH);
  digitalWrite(led3, LOW);
  } 
  
  else if (val > 400) // tension moyenne
  {       
  digitalWrite(led0, HIGH);
  digitalWrite(led1, HIGH);
  digitalWrite(led2, LOW);
  digitalWrite(led3, LOW);
  } 
  
  else if (val > 200) // tension faible
  {       
  digitalWrite(led0, HIGH);
  digitalWrite(led1, LOW);
  digitalWrite(led2, LOW);
  digitalWrite(led3, LOW);
  } 
  
  else // tension très faible
  {                       
  digitalWrite(led0, LOW);
  digitalWrite(led1, LOW);
  digitalWrite(led2, LOW);
  digitalWrite(led3, LOW);
  }

  delay(50); // petite pause pour stabilité
  }

