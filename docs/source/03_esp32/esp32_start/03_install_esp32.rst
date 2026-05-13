.. note::

    Bonjour, bienvenue dans la communauté des passionnés de SunFounder Raspberry Pi, Arduino et ESP32 sur Facebook ! Plongez plus profondément dans l'univers de Raspberry Pi, Arduino et ESP32 aux côtés d'autres passionnés.

    **Pourquoi rejoindre ?**

    - **Support d'experts** : Obtenez de l'aide pour résoudre les problèmes post-vente et les défis techniques grâce à notre communauté et notre équipe.
    - **Apprendre & Partager** : Échangez des astuces et des tutoriels pour enrichir vos compétences.
    - **Aperçus exclusifs** : Accédez en avant-première aux annonces de nouveaux produits et aux coulisses de leur développement.
    - **Réductions spéciales** : Profitez de promotions exclusives sur nos dernières nouveautés.
    - **Promotions festives et cadeaux** : Participez à des jeux concours et à des offres spéciales pour les fêtes.

    👉 Prêt à explorer et à créer avec nous ? Cliquez sur [|link_sf_facebook|] et rejoignez-nous dès aujourd'hui !

Installer la carte ESP32 (Important)
===========================================

Pour programmer le microcontrôleur ESP32, nous devons installer le package de la carte ESP32 dans l'Arduino IDE. Suivez les étapes détaillées ci-dessous :

**Installation de la carte ESP32**

#. Ouvrez l'Arduino IDE. Accédez à **Fichier** et sélectionnez **Préférences** dans le menu déroulant.

   .. image:: img/install_esp32_1.png

#. Dans la fenêtre des Préférences, trouvez le champ **URLs supplémentaires pour le gestionnaire de cartes** et cliquez dessus pour activer la zone de saisie.

   .. image:: img/install_esp32_2.png

#. Ajoutez l'URL suivante dans le champ **URLs supplémentaires pour le gestionnaire de cartes** :  https://espressif.github.io/arduino-esp32/package_esp32_index.json  Cette URL pointe vers le fichier d'index des packages pour les cartes ESP32. Cliquez sur **OK** pour enregistrer les modifications.

   .. image:: img/install_esp32_3.png

#. Dans la fenêtre **Gestionnaire de cartes**, saisissez **ESP32** dans la barre de recherche. Cliquez sur **Installer** pour lancer le processus. Cette action téléchargera et installera le package de la carte ESP32.

   .. image:: img/install_esp32_4.png

#. Félicitations ! L'installation du package de la carte ESP32 dans l'Arduino IDE est terminée.

**Téléverser le code**

#. Maintenant, connectez la carte ESP32 à votre ordinateur.


#. Sélectionnez ensuite la carte appropriée, **ESP32 Dev Module**, en allant dans **Outils** -> **Carte** -> **esp32**.

   .. image:: img/install_esp32_5.png
      :width: 100%

#. Si votre ESP32 est bien connecté, choisissez le port correct via **Outils** -> **Port**.

   .. image:: img/install_esp32_6.png
      :width: 100%

#. De plus, Arduino 2.0 propose une nouvelle méthode pour sélectionner rapidement la carte et le port. Pour l'ESP32, la reconnaissance automatique peut ne pas fonctionner, vous devrez donc cliquer sur **Sélectionner une autre carte et port**.

   .. image:: img/install_esp32_7.png
      :width: 80%

#. Dans la barre de recherche, tapez **ESP32 Dev Module**, sélectionnez-le lorsqu'il apparaît, puis choisissez le port adéquat et cliquez sur **OK**.

   .. image:: img/install_esp32_8.png
      :width: 90%

#. Ensuite, vous pourrez le sélectionner directement via cette fenêtre d'accès rapide. Notez que lors des utilisations suivantes, l'ESP32 peut ne pas apparaître dans cet accès rapide, et vous devrez alors répéter les deux étapes précédentes.

   .. image:: img/install_esp32_9.png
      :width: 80%

#. Les deux méthodes permettent de configurer la carte et le port correctement. Choisissez celle qui vous convient le mieux. Tout est désormais prêt pour téléverser le code sur l'ESP32.
