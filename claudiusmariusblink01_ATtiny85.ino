  //****************************************************************************************************************************************************
  //+++++++++++++++++ Programme de test ATtiny85 permettant de vérifier le bon fonctionnement du Programmateurr ATtiny Claudiusmarius ++++++++++++++++++
  //+++++++++++++++++++++ Ce code peut être testé sur le programmateur (position basse du support à insertion nulle de gauche ++++++++++++++++++++++++++
  //=========================================================            Claude DUFOURMONT             =================================================
  //----------------------------------   YouTube :      https://www.youtube.com/channel/UCvr9eb05lJow6N7m3SKqvNw    ------------------------------------
  //--------------------------------------------------------------- claude.dufourmont@laposte.net ------------------------------------------------------  
  
  int LED = 3;
  
  void setup ()
  {
  pinMode (LED, OUTPUT);
  }
  
  void loop ()
  {
  for (int i = 0 ; i < 10 ; i++)
  {
  digitalWrite (LED, HIGH);
  delay (1000);
  digitalWrite (LED, LOW);
  delay (1000);
  }
  
  delay(50);
  
  for (int i = 0; i< 50; i++)
  {
  digitalWrite (LED, HIGH);
  delay (100);
  digitalWrite (LED, LOW);
  delay (100);
  }
  }
