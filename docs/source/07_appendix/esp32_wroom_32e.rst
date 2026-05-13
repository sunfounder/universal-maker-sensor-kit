.. note::
    Bonjour et bienvenue dans la communauté Facebook des passionnés de SunFounder Raspberry Pi, Arduino, et ESP32 ! Plongez plus profondément dans l'univers des Raspberry Pi, Arduino, et ESP32 avec d'autres passionnés.

    **Pourquoi rejoindre ?**

    - **Support d'experts** : Résolvez les problèmes post-vente et les défis techniques avec l'aide de notre communauté et de notre équipe.
    - **Apprendre et partager** : Échangez des astuces et des tutoriels pour améliorer vos compétences.
    - **Aperçus exclusifs** : Accédez en avant-première aux nouvelles annonces de produits et aux aperçus.
    - **Réductions spéciales** : Profitez de réductions exclusives sur nos nouveaux produits.
    - **Promotions festives et cadeaux** : Participez à des cadeaux et promotions de vacances.

    👉 Prêts à explorer et créer avec nous ? Cliquez sur [|link_sf_facebook|] et rejoignez-nous aujourd'hui !

.. _cpn_esp32_wroom_32e:

ESP32
=================

L’ESP32 est un microcontrôleur puissant et polyvalent, doté d’un processeur double cœur, du Wi-Fi et du Bluetooth intégrés, ainsi que d’une large prise en charge des périphériques. Sa conception à faible consommation d’énergie le rend particulièrement adapté aux applications IoT compactes et performantes.

.. image:: img/esp32_board.png
    :align: center


Caractéristiques principales :

* **Puissance de traitement** : équipé d’un microprocesseur Xtensa® LX6 32 bits double cœur, offrant à la fois flexibilité et évolutivité.
* **Connectivité sans fil** : grâce au Wi-Fi 2,4 GHz intégré et au Bluetooth double mode, il convient parfaitement aux applications nécessitant une communication sans fil stable.
* **Mémoire et stockage** : dispose d’une SRAM généreuse et d’une mémoire flash haute performance pour répondre aux besoins des programmes et du stockage de données.
* **GPIO** : jusqu’à 38 broches GPIO permettant la connexion de nombreux capteurs et périphériques externes.
* **Faible consommation énergétique** : plusieurs modes d’économie d’énergie sont disponibles, idéaux pour les applications alimentées par batterie.
* **Sécurité** : des fonctions de chiffrement et de sécurité intégrées assurent une bonne protection des données et de la confidentialité des utilisateurs.
* **Polyvalence** : des appareils domestiques simples aux équipements industriels complexes, la carte garantit des performances fiables et efficaces.

En résumé, la carte ESP32 offre non seulement de solides capacités de traitement et de nombreuses options de connectivité, mais également un large éventail de fonctionnalités qui en font un choix privilégié pour les projets IoT et les appareils intelligents.

.. * |link_esp32_datasheet|

.. _esp32_pinout:

Schéma des broches
-------------------------

L’ESP32 présente certaines limitations d’utilisation des broches, car plusieurs fonctions partagent les mêmes GPIO. Lors de la conception d’un projet, il est recommandé de planifier soigneusement l’utilisation des broches et de vérifier les éventuels conflits afin d’assurer un fonctionnement correct et d’éviter les problèmes.


.. image:: img/esp32_pinout.jpg
    :width: 800
    :align: center

Voici quelques restrictions et points importants à prendre en compte :

* **ADC1 et ADC2** : ADC2 ne peut pas être utilisé lorsque le Wi-Fi ou le Bluetooth est actif. ADC1, en revanche, peut être utilisé sans restriction.
* **Broches de démarrage (Bootstrapping Pins)** : GPIO0, GPIO2, GPIO5, GPIO12 et GPIO15 sont utilisées pendant le processus de démarrage. Évitez d’y connecter des composants externes susceptibles d’interférer avec le boot.
* **Broches JTAG** : GPIO12, GPIO13, GPIO14 et GPIO15 peuvent être utilisées pour le débogage JTAG. Si le débogage JTAG n’est pas nécessaire, elles peuvent servir de GPIO classiques.
* **Broches tactiles** : certaines broches prennent en charge les fonctions tactiles. Elles doivent être utilisées avec précaution si vous souhaitez exploiter cette fonctionnalité.
* **Broches d’alimentation** : certaines broches sont réservées à l’alimentation. Par exemple, évitez de tirer un courant excessif des broches 3V3 et GND.
* **Broches en entrée uniquement** : certaines broches ne prennent en charge que les signaux d’entrée et ne doivent pas être utilisées comme sorties.

.. _esp32_strapping:

**Broches de configuration de démarrage**
-----------------------------------------------------

L’ESP32 possède cinq broches de configuration de démarrage :

.. list-table::
    :widths: 5 15
    :header-rows: 1

    *   - Broche
        - Description
    *   - IO5
        - Tirage interne vers le haut par défaut. Le niveau de tension de IO5 et IO15 influence le timing du SDIO Slave.
    *   - IO0
        - Tirage interne vers le haut par défaut. Si la broche est forcée à l’état bas, l’ESP32 entre en mode téléchargement.
    *   - IO2
        - Tirage interne vers le bas par défaut. IO0 et IO2 ensemble peuvent faire entrer l’ESP32 en mode téléchargement.
    *   - IO12(MTDI)
        - Tirage interne vers le bas par défaut. Si cette broche est à l’état haut au démarrage, l’ESP32 ne démarrera pas correctement.
    *   - IO15(MTDO)
        - Tirage interne vers le haut par défaut. Si cette broche est à l’état bas, les journaux de débogage ne seront pas affichés. De plus, le niveau de tension de IO5 et IO15 influence le timing du SDIO Slave.


Le logiciel peut lire les valeurs de ces cinq bits via le registre « GPIO_STRAPPING ».

Lors de la sortie de réinitialisation du système (mise sous tension, réinitialisation par watchdog RTC ou brownout reset), les broches de configuration échantillonnent leur niveau logique afin de déterminer les bits de configuration « 0 » ou « 1 ». Ces valeurs restent mémorisées jusqu’à l’arrêt ou la mise hors tension de la puce. Elles définissent notamment le mode de démarrage, la tension de fonctionnement de VDD_SDIO et d’autres paramètres système initiaux.

Chaque broche de configuration est reliée à une résistance interne de pull-up ou pull-down pendant la phase de réinitialisation. Ainsi, si une broche n’est pas connectée ou si le circuit externe présente une haute impédance, le niveau logique par défaut sera déterminé par cette résistance interne.

Pour modifier les valeurs des bits de configuration, il est possible d’utiliser des résistances externes de pull-up/pull-down ou de contrôler le niveau logique de ces broches via les GPIO du microcontrôleur hôte lors de la mise sous tension de l’ESP32.

Une fois la réinitialisation terminée, ces broches redeviennent des GPIO classiques.
Reportez-vous au tableau suivant pour plus de détails concernant la configuration des modes de démarrage via les broches de configuration.

.. image:: img/esp32_strapping.png

* FE : front descendant, RE : front montant
* Le firmware peut modifier certains registres après le démarrage afin de changer les paramètres de « Voltage of Internal LDO (VDD_SDIO) » et de « Timing of SDIO Slave ».
* Le module intègre une mémoire flash SPI 3,3 V ; par conséquent, la broche MTDI ne doit pas être à l’état haut lors de la mise sous tension.