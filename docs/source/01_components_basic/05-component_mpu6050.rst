 .. note::

    Hallo und willkommen in der SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasten-Gemeinschaft auf Facebook! Tauchen Sie tiefer ein in die Welt von Raspberry Pi, Arduino und ESP32 mit anderen Enthusiasten.

    **Warum beitreten?**

    - **Expertenunterstützung**: Lösen Sie Nachverkaufsprobleme und technische Herausforderungen mit Hilfe unserer Gemeinschaft und unseres Teams.
    - **Lernen & Teilen**: Tauschen Sie Tipps und Anleitungen aus, um Ihre Fähigkeiten zu verbessern.
    - **Exklusive Vorschauen**: Erhalten Sie frühzeitigen Zugang zu neuen Produktankündigungen und exklusiven Einblicken.
    - **Spezialrabatte**: Genießen Sie exklusive Rabatte auf unsere neuesten Produkte.
    - **Festliche Aktionen und Gewinnspiele**: Nehmen Sie an Gewinnspielen und Feiertagsaktionen teil.

    👉 Sind Sie bereit, mit uns zu erkunden und zu erschaffen? Klicken Sie auf [|link_sf_facebook|] und treten Sie heute bei!

.. _cpn_mpu6050:

Gyroskop- und Beschleunigungssensormodul (MPU6050)
===============================================================

.. image:: img/05_mpu6050_1.png
    :width: 300
    :align: center

.. raw:: html

   <br/>

Der MPU-6050 ist ein 6-Achsen-Bewegungssensor (kombiniert ein 3-Achsen-Gyroskop und einen 3-Achsen-Beschleunigungssensor). Änderungen in Bewegung, Beschleunigung und Rotation können erkannt werden. Er wird häufig in Robotik, Gaming-Controllern und anderen elektronischen Geräten verwendet, die eine Bewegungserkennung erfordern. Seine hohe Genauigkeit und die niedrigen Kosten machen ihn in der DIY-Community sehr beliebt.

Funktionsprinzip
---------------------------
Ein MPU-6050-Sensormodul besteht aus einem 3-Achsen-Beschleunigungssensor und einem 3-Achsen-Gyroskop.

Seine drei Koordinatensysteme sind wie folgt definiert:

Legen Sie den MPU6050 flach auf den Tisch, stellen Sie sicher, dass die Seite mit dem Etikett nach oben zeigt und ein Punkt in der oberen linken Ecke dieser Oberfläche ist. Die aufrechte Richtung nach oben ist die Z-Achse des Chips. Die Richtung von links nach rechts wird als X-Achse betrachtet. Dementsprechend ist die Richtung von hinten nach vorne als Y-Achse definiert.

.. image:: img/05_mpu_2.png
    :width: 300
    :align: center

3-Achsen-Beschleunigungssensor
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
Der Beschleunigungssensor arbeitet nach dem Piezo-Effekt, der Fähigkeit bestimmter Materialien, eine elektrische Ladung als Reaktion auf mechanischen Stress zu erzeugen.

Stellen Sie sich hier einen quaderförmigen Kasten vor, der eine kleine Kugel darin enthält, wie im obigen Bild. Die Wände dieses Kastens bestehen aus piezoelektrischen Kristallen. Wann immer Sie den Kasten neigen, wird die Kugel aufgrund der Schwerkraft gezwungen, sich in Richtung der Neigung zu bewegen. Die Wand, mit der die Kugel kollidiert, erzeugt winzige piezoelektrische Ströme. Insgesamt gibt es drei Paare gegenüberliegender Wände in einem Quader. Jedes Paar entspricht einer Achse im 3D-Raum: X-, Y- und Z-Achsen. Abhängig vom erzeugten Strom der piezoelektrischen Wände können wir die Richtung der Neigung und deren Stärke bestimmen.

.. image:: img/05_mpu_3.png
    :width: 800
    :align: center

Wir können den MPU6050 verwenden, um seine Beschleunigung auf jeder Koordinatenachse zu erkennen (im stationären Zustand auf dem Schreibtisch beträgt die Z-Achsen-Beschleunigung 1 Gravitationskraft, und die X- und Y-Achsen sind 0). Wenn er geneigt ist oder sich in einem schwerelosen/übergewichtigen Zustand befindet, ändert sich die entsprechende Anzeige.

Es gibt vier wählbare Messbereiche, die programmgesteuert ausgewählt werden können: +/-2g, +/-4g, +/-8g und +/-16g (standardmäßig 2g) entsprechend jeder Genauigkeit. Die Werte reichen von -32768 bis 32767.

Die Anzeige des Beschleunigungssensors wird in einen Beschleunigungswert umgewandelt, indem die Anzeige vom Anzeigebereich auf den Messbereich abgebildet wird.

Beschleunigung = (Beschleunigungssensor-Rohdaten / 65536 * Vollbereich-Beschleunigungsbereich) g

Nehmen wir die X-Achse als Beispiel, wenn die Rohdaten der Beschleunigungssensor-X-Achse 16384 und der Bereich auf +/-2g eingestellt sind:

Beschleunigung entlang der X-Achse = (16384 / 65536 * 4) g = 1g

3-Achsen-Gyroskop
^^^^^^^^^^^^^^^^^^^^
Gyroskope arbeiten nach dem Prinzip der Coriolis-Beschleunigung. Stellen Sie sich vor, dass es eine gabelartige Struktur gibt, die sich ständig vor- und zurückbewegt. Diese wird durch piezoelektrische Kristalle in Position gehalten. Wann immer Sie versuchen, diese Anordnung zu neigen, erfahren die Kristalle eine Kraft in Richtung der Neigung. Dies wird durch die Trägheit der sich bewegenden Gabel verursacht. Die Kristalle erzeugen dann einen Strom im Einklang mit dem piezoelektrischen Effekt, und dieser Strom wird verstärkt.

.. image:: img/05_mpu_4.png
    :width: 800
    :align: center

Das Gyroskop hat ebenfalls vier Messbereiche: +/- 250, +/- 500, +/- 1000, +/- 2000. Die Berechnungsmethode und die Beschleunigung sind im Wesentlichen gleich.

Die Formel zur Umrechnung der Anzeige in die Winkelgeschwindigkeit lautet wie folgt:

Winkelgeschwindigkeit = (Gyroskop-Achsen-Rohdaten / 65536 * Vollbereich-Gyroskopbereich) °/s

Die X-Achse zum Beispiel, die Rohdaten der Beschleunigungssensor-X-Achse sind 16384 und der Bereich beträgt +/- 250°/s:

Winkelgeschwindigkeit entlang der X-Achse = (16384 / 65536 * 500)°/s = 125°/s

Beispiel
---------------------------
* :ref:`uno_lesson05_mpu6050` (Arduino UNO)
* :ref:`esp32_lesson05_mpu6050` (ESP32)
* :ref:`pico_lesson05_mpu6050` (Raspberry Pi Pico)
* :ref:`pi_lesson05_mpu6050` (Raspberry Pi Pi)





