
.. note::

    Bonjour, bienvenue dans la communauté des passionnés de SunFounder Raspberry Pi & Arduino & ESP32 sur Facebook ! Plongez plus profondément dans l'univers du Raspberry Pi, Arduino et ESP32 avec d'autres passionnés.

    **Pourquoi rejoindre ?**

    - **Support d'experts** : Résolvez les problèmes après-vente et les défis techniques avec l'aide de notre communauté et de notre équipe.
    - **Apprendre & Partager** : Échangez des conseils et des tutoriels pour améliorer vos compétences.
    - **Aperçus exclusifs** : Bénéficiez d'un accès anticipé aux annonces de nouveaux produits et aux avant-premières.
    - **Réductions spéciales** : Profitez de réductions exclusives sur nos produits les plus récents.
    - **Promotions festives et cadeaux** : Participez à des tirages au sort et à des promotions pendant les fêtes.

    👉 Prêts à explorer et à créer avec nous ? Cliquez sur [|link_sf_facebook|] et rejoignez-nous aujourd'hui !

.. _uno_iot_vib_alert_system:

Leçon 49 : Système d'alerte par vibration avec IFTTT
=====================================================

Ce projet met en place un système de détection de vibrations utilisant une carte Arduino (Uno R4 ou R3) avec un module ESP8266 et un capteur de vibration (SW-420). Lorsqu'une vibration est détectée, le système envoie une requête HTTP à un serveur IFTTT, déclenchant potentiellement diverses actions telles que l'envoi d'une notification ou d'un courriel.

Pour éviter des alertes excessives sur une courte période, le système est programmé pour envoyer ces requêtes HTTP à un intervalle minimum de 2 minutes (120 000 millisecondes). Cet intervalle peut être ajusté selon les besoins de l'utilisateur.


Composants requis
--------------------------

Pour ce projet, nous avons besoin des composants suivants.

Il est définitivement pratique d'acheter un kit complet, voici le lien :

.. list-table::
    :widths: 20 20 20
    :header-rows: 1

    *   - Nom	
        - ARTICLES DANS CE KIT
        - LIEN
    *   - Kit de capteurs universel pour créateurs
        - 94
        - |link_umsk|

Vous pouvez également les acheter séparément via les liens ci-dessous.

.. list-table::
    :widths: 30 20
    :header-rows: 1

    *   - Introduction du composant
        - Lien d'achat

    *   - Arduino UNO R3 ou R4
        - |link_Uno_R3_buy|
    *   - :ref:`cpn_breadboard`
        - |link_breadboard_buy|
    *   - :ref:`cpn_esp8266`
        - \-
    *   - :ref:`cpn_vibration`
        - \-


Câblage
---------------------------

.. image:: img/Lesson_49_Iot_vibration_alert_system_uno_bb.png
    :width: 100%



Configurer IFTTT
-----------------------------

|link_ifttt| est une entreprise privée fondée en 2011 qui gère des plateformes d'automatisation numérique en ligne qu'elle propose comme un service. Leurs plateformes offrent une interface visuelle permettant de réaliser des instructions conditionnelles inter-plateformes à ses utilisateurs, qui, en 2020, étaient au nombre de 18 millions.

.. image:: img/04-ifttt_intro.png
    :width: 100%

IFTTT signifie "If This Then That" (Si Ceci Alors Cela). En gros, si certaines conditions sont remplies, alors quelque chose d'autre se produira. La partie "si ceci" est appelée un déclencheur, et la partie "alors cela" est appelée une action. Elle relie les appareils domestiques intelligents, les réseaux sociaux, les applications de livraison, et plus encore afin qu'elle puisse exécuter des tâches automatisées.

.. image:: img/04-ifttt_intro_2A.png
    :width: 100% 

**1) Inscription à IFTTT**
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Tapez "https://ifttt.com" dans votre navigateur et cliquez sur le bouton "Get started" situé au centre de la page. Remplissez le formulaire avec vos informations pour créer un compte.

.. image:: img/04-ifttt_signup.png
    :width: 90%
    :align: center

Cliquez sur "Back" pour quitter le démarrage rapide, retournez à la page d'accueil d'IFTTT, rafraîchissez la page et connectez-vous à nouveau.

.. image:: img/04-ifttt_signup_2.png
    :width: 90%
    :align: center


**2) Création de l'applet**
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Cliquez sur "Create" pour commencer la création de l'applet.

.. image:: img/04-ifttt_create_applet_1_shadow.png
    :width: 80%
    :align: center

.. raw:: html
    
    <br/>  

Déclencheur Si Ceci
---------------------------

Cliquez sur "Ajouter" à côté de "Si Ceci" pour ajouter un déclencheur.

.. image:: img/04-ifttt_create_applet_2_shadow.png
    :width: 80%
    :align: center

Recherchez "webhook" et cliquez sur "Webhooks".

.. image:: img/04-ifttt_create_applet_3_shadow.png
    :width: 80%
    :align: center

Cliquez sur "Recevoir une requête web" sur la page affichée dans l'image suivante.

.. image:: img/04-ifttt_create_applet_4_shadow.png
    :width: 80%
    :align: center

Définissez le "Nom de l'événement" à "vibration_detected".

.. image:: img/04-ifttt_create_applet_5_shadow.png
    :width: 80%
    :align: center

.. raw:: html
    
    <br/>  

**Action Alors Cela**
---------------------------

Cliquez sur "Ajouter" à côté de "Alors Cela" pour ajouter une action.

.. image:: img/04-ifttt_create_applet_6_shadow.png
    :width: 80%
    :align: center

Recherchez "email" et cliquez sur "Email".

.. image:: img/04-ifttt_create_applet_7_shadow.png
    :width: 80%
    :align: center

Cliquez sur "Envoyez-moi un email" sur la page montrée dans l'image suivante.

.. image:: img/04-ifttt_create_applet_8_shadow.png
    :width: 80%
    :align: center

Définissez le sujet et le contenu de l'email à envoyer lorsqu'une vibration est détectée.

À titre de référence, le sujet est défini à "[ESP-01] Vibration détectée !!!", et le contenu est défini à "Vibration détectée, veuillez vérifier la situation promptement ! {{OccurredAt}}". Lors de l'envoi d'un email, ``{{OccurredAt}}`` sera automatiquement remplacé par l'heure à laquelle l'événement s'est produit.

.. image:: img/04-ifttt_create_applet_9_shadow.png
    :width: 80%
    :align: center

Suivez les étapes suivantes pour compléter la création de l'applet.

.. image:: img/04-ifttt_create_applet_10_shadow.png
    :width: 80%
    :align: center

.. image:: img/04-ifttt_create_applet_11_shadow.png
    :width: 80%
    :align: center

.. image:: img/04-ifttt_create_applet_12_shadow.png
    :width: 50%
    :align: center

.. raw:: html
    
    <br/>  



Code
-----------------------

#. Ouvrez le fichier ``Lesson_49_Vibration_alert_system.ino`` situé sous le chemin ``universal-maker-sensor-kit\arduino_uno\Lesson_49_Vibration_alert_system``, ou copiez ce code dans **Arduino IDE**.

   .. raw:: html
       
        <iframe src=https://create.arduino.cc/editor/sunfounder01/35a75e1c-6b2a-407d-9724-f83ad50a4a41/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>


#. Vous devez entrer le ``mySSID`` et ``myPWD`` du WiFi que vous utilisez. 

   .. code-block:: arduino

    String mySSID = "votre_ssid";     // SSID WiFi
    String myPWD = "votre_mot_de_passe";  // Mot de passe WiFi

#. Vous devez également modifier l'``URL`` avec le nom de l'événement que vous avez défini et votre clé API.

   .. code-block:: arduino
    
      String URL = "/trigger/vibration_detected/with/key/xxxxxxxxxxxxxxxxxx";

   .. image:: img/04-ifttt_apikey_1_shadow.png
       :width: 80%
       :align: center
   
   .. image:: img/04-ifttt_apikey_2_shadow.png
       :width: 80%
       :align: center

   Vous trouverez ici **votre clé API unique que vous devez garder privée**. Entrez le nom de l'événement comme ``vibration_detected``. Votre URL finale apparaîtra au bas de la page web. Copiez cette URL.

   .. image:: img/04-ifttt_apikey_3_shadow.png
       :width: 80%
       :align: center

   .. image:: img/04-ifttt_apikey_4_shadow.png
       :width: 80%
       :align: center

#. Après avoir sélectionné la bonne carte et le bon port, cliquez sur le bouton **Télécharger**.

#. Ouvrez le moniteur série (réglez le baudrate sur **9600**) et attendez une invite telle qu'une connexion réussie apparaît.

   .. image:: img/04-ready_shadow.png
          :width: 95%

Analyse du code
---------------------------

Le module ESP8266 fourni avec le kit est déjà préprogrammé avec le firmware AT. Par conséquent, le module ESP8266 peut être contrôlé via des commandes AT. Dans ce projet, nous utilisons la communication série logicielle pour permettre la communication entre la carte Arduino Uno et le module ESP8266. La carte Arduino Uno envoie des commandes AT au module ESP8266 pour se connecter au réseau et envoyer des requêtes. Vous pouvez vous référer à |link_esp8266_at|.

La carte Uno lit les valeurs des capteurs et envoie des commandes AT au module ESP8266. Le module ESP8266 se connecte à un réseau et envoie des requêtes aux serveurs IFTTT.

#. Inclure la bibliothèque SoftwareSerial pour la communication série entre Arduino et ESP8266

   .. code-block:: arduino
   
     #include <SoftwareSerial.h>      
     SoftwareSerial espSerial(2, 3);  

#. Configurer les identifiants WiFi et les détails du serveur IFTTT

   .. code-block:: arduino
   
     String mySSID = "votre_ssid";     
     String myPWD = "votre_mot_de_passe";  
     String myHOST = "maker.ifttt.com";
     String myPORT = "80";
     String URL = "/trigger/xxx/with/key/xxxx";  

#. Définir les variables pour le capteur de vibration et le contrôle de la fréquence des alertes

   .. code-block:: arduino
   
     unsigned long lastAlertTime = 0;                
     const unsigned long postingInterval = 120000L;
     const int sensorPin = 7;

#. Dans ``setup()``, initialiser la communication série, le module ESP8266 et se connecter au WiFi

   .. code-block:: arduino
   
      void setup() {
        Serial.begin(9600);
        espSerial.begin(115200);
      
        // Initialiser le module ESP8266
        sendATCommand("AT+RST", 1000, DEBUG);   // Réinitialiser le module ESP8266
        sendATCommand("AT+CWMODE=1", 1000, DEBUG);  // Configurer le mode ESP comme mode station
        sendATCommand("AT+CWJAP=\"" + mySSID + "\",\"" + myPWD + "\"", 3000, DEBUG);  // Se connecter au réseau WiFi
      
        while (!espSerial.find("OK")) {
          // Attendre la connexion
        }
      }

#. Dans ``loop()``, détecter la vibration et envoyer une alerte si l'intervalle de temps est passé

   .. code-block:: arduino
   
      void loop() {
      
        if (digitalRead(sensorPin)) {
          if (lastAlertTime == 0 || millis() - lastAlertTime > postingInterval) {
            Serial.println("Detected vibration!!!");
            sendAlert();  // Envoyer une requête HTTP au serveur IFTTT
          } else {
            Serial.print("Detected vibration!!! ");
            Serial.println("Since an email has been sent recently, no warning email will be sent this time to avoid bombarding your inbox.");
          }
        } else {
          if (DEBUG) {
            Serial.println("Detecting...");
          }
        }
        delay(500);
      }

#. sendAlert() construit la requête HTTP et l'envoie via ESP8266

   .. code-block:: arduino
   
     void sendAlert() {
   
       String sendData = "GET " + URL + " HTTP/1.1" + "\r\n";
       sendData += "Host: maker.ifttt.com\r\n";
       
       sendATCommand("AT+CIPMUX=0",1000,DEBUG);                           
       sendATCommand("AT+CIPSTART=...",3000,DEBUG);  
       sendATCommand("AT+CIPSEND=" + String(sendData.length()),1000,DEBUG);   
       espSerial.println(sendData);
      
     }  

#. Gestion des commandes AT sendATCommand()

   Cette fonction envoie des commandes AT au module ESP8266 et collecte les réponses.
   
   .. code-block:: arduino
   
      void sendATCommand(String command, const int timeout, boolean debug) {
        // Imprimer et envoyer la commande
        Serial.print("AT Command ==> ");
        Serial.print(command);
        Serial.println();
        espSerial.println(command);  // Envoyer la commande AT
      
        // Obtenir la réponse du module ESP8266
        String response = "";
        long int time = millis();
        while ((time + timeout) > millis()) {  // Attendre la réponse jusqu'à l'expiration du délai
          while (espSerial.available()) {
            char c = espSerial.read();
            response += c;
          }
        }
      
        // Imprimer la réponse si le mode débogage est activé
        if (debug) {
          Serial.println(response);
          Serial.println("--------------------------------------");
        }



**Référence**

* |link_esp8266_at|
* |link_ifttt_welcome|
* |link_ifttt_webhook_faq|