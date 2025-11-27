// Déclaration des broches utilisées
const int capteur_pin = 9;    // Pin où est connecté la sortie digitale du capteur de flamme
const int buzzer_pin = 13;    // Pin du buzzer (supporte tone sur Arduino Uno)

// Fonction setup exécutée une seule fois au démarrage
void setup() {
  pinMode(capteur_pin, INPUT);     // Définition du capteur comme entrée
  pinMode(buzzer_pin, OUTPUT);     // Définition du buzzer comme sortie
  Serial.begin(9600);              // Ouverture du moniteur série à 9600 bauds
}

// Boucle principale qui s'exécute en continu
void loop() {

  // Lecture de la valeur envoyée par le capteur (HIGH ou LOW)
  int valeur = digitalRead(capteur_pin);

  // Affichage de la valeur lue dans le moniteur série
  Serial.print("Valeur lue : ");
  Serial.println(valeur);

  delay(100); // Petite pause pour stabiliser l’affichage

  // Le capteur renvoie généralement LOW quand une flamme est détectée
  if (valeur == LOW) {
    // Si une flamme est détectée, le buzzer sonnera 5 fois
    for (int i = 0; i < 5; i++) {
      tone(buzzer_pin, 300);   // Envoi d'un son de 300 Hz au buzzer
      delay(1000);             // Le buzzer sonne pendant 1 seconde
      noTone(buzzer_pin);      // Arrêt du son
      delay(1000);             // Pause d’une seconde avant de recommencer
    }
    delay(3000);   // Temps d’attente avant de revérifier le capteur
  } else {
    // Si aucune flamme détectée, on s’assure que le buzzer est éteint
    noTone(buzzer_pin);
  }

}
