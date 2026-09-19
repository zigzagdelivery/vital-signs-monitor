---

# 📊 Présentation du Projet (Slide Deck)

### 📌 Slide 1 : Titre & Introduction
* **Projet :** Vital Signs Monitor with Real-Time Arrhythmia Detection and Cloud Connectivity
* **Contexte :** Projet de Stage / Système Embarqué Médical
* **Technologies :** STM32, DSP, IoT, CI/CD

---

### 📌 Slide 2 : Problématique & Objectifs
* **Problématique :** La nécessité d'un suivi cardiaque en temps réel, fiable et à faible coût.
* **Objectifs :**
  * Acquisition de signaux physiologiques (ECG / PPG) en temps réel.
  * Filtrage numérique (DSP) pour éliminer les bruits et interférences.
  * Détection d'arythmie via l'algorithme des pics QRS.
  * Transmission des données vers le Cloud et alerte locale en cas d'anomalie.

---

### 📌 Slide 3 : Architecture Matérielle & Périphériques
* **Microcontrôleur :** STM32 (Architecture ARM Cortex-M).
* **Capteurs :** Module Analog Front-End (AFE - AD8232 / MAX30102).
* **Périphériques STM32 Utilisés :**
  * **ADC + DMA :** Sampling continu à haute vitesse sans charger le CPU.
  * **Timers (TIM2) :** Contrôle précis du taux d'échantillonnage (Sampling Rate).
  * **USART/UART :** Communication série vers la passerelle Wi-Fi/Cloud.
  * **GPIO :** Signalisation et alertes locales (LED / Buzzer).

---

### 📌 Slide 4 : Traitement du Signal (DSP) & Algorithme
* **Étape 1 - Acquisition :** Lecture continue dans un buffer circulaire via DMA.
* **Étape 2 - Filtrage Numérique :** Application d'un filtre passe-bande (Bandpass) pour réduire la dérivée de ligne de base et le bruit haute fréquence.
* **Étape 3 - Détection QRS :** Calcul du rythme cardiaque (BPM) et comparaison avec un seuil pour détecter l'arythmie.

---

### 📌 Slide 5 : Validation & Pipeline CI/CD
* **Validation des Algorithmes :** Tests automatisés sur la base de données clinique publique **MIT-BIH Arrhythmia Database**.
* **Intégration Continue (CI/CD) :**
  * Compilation automatique du firmware à chaque commit.
  * Validation Hardware-In-The-Loop (HIL).

---

### 📌 Slide 6 : Conclusion & Perspectives
* **Résultats :** Système embarqué fonctionnel, réactif et à faible latence pour la surveillance à distance.
* **Perspectives :** Intégration d'un modèle de Machine Learning léger (TinyML) pour classifier d'autres types d'anomalies cardiaques.