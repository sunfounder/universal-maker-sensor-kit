 .. note::

    Hallo und willkommen in der SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasten-Gemeinschaft auf Facebook! Tauchen Sie tiefer ein in die Welt von Raspberry Pi, Arduino und ESP32 mit anderen Enthusiasten.

    **Warum beitreten?**

    - **Expertenunterstützung**: Lösen Sie Nachverkaufsprobleme und technische Herausforderungen mit Hilfe unserer Gemeinschaft und unseres Teams.
    - **Lernen & Teilen**: Tauschen Sie Tipps und Anleitungen aus, um Ihre Fähigkeiten zu verbessern.
    - **Exklusive Vorschauen**: Erhalten Sie frühzeitigen Zugang zu neuen Produktankündigungen und exklusiven Einblicken.
    - **Spezialrabatte**: Genießen Sie exklusive Rabatte auf unsere neuesten Produkte.
    - **Festliche Aktionen und Gewinnspiele**: Nehmen Sie an Gewinnspielen und Feiertagsaktionen teil.

    👉 Sind Sie bereit, mit uns zu erkunden und zu erschaffen? Klicken Sie auf [|link_sf_facebook|] und treten Sie heute bei!

 
Konfiguration Ihres Raspberry Pi
====================================

.. _pi_enable_i2c:

I2C-Konfiguration
------------------------

Um den I2C-Port auf Ihrem Raspberry Pi zu aktivieren, befolgen Sie diese Schritte (überspringen Sie diesen Schritt, wenn er bereits aktiviert ist; wenn Sie sich unsicher sind, folgen Sie den Anweisungen).

1. Melden Sie sich bei Ihrem Raspberry Pi an, öffnen Sie das Terminal und geben Sie den folgenden Befehl ein, um das Raspberry Pi Software-Konfigurationstool zu starten. (Sie können das Terminal auch über SSH aufrufen.)

   .. code-block::

       sudo raspi-config

   .. image:: img/configuration_01.png
       :width: 100%

   .. raw:: html

       <br/><br/>

2. Gehen Sie zu **Interfacing options**.

   .. note::
      Verwenden Sie die Pfeiltasten ``up`` und ``down``, um die Auswahl zwischen den verfügbaren Optionen zu bewegen. Mit der rechten Pfeiltaste gelangen Sie aus dem Optionsmenü zu den Tasten ``<Select>`` und ``<Finish>``. Mit der linken Pfeiltaste kehren Sie zu den Optionen zurück. Alternativ können Sie die ``Tab``-Taste verwenden, um zwischen den Optionen zu wechseln.

   .. image:: img/configuration_02.png
       :width: 100%

   .. raw:: html

       <br/><br/>

3. Wählen Sie **I2C**.

   .. image:: img/configuration_03.png
       :width: 100%

   .. raw:: html

       <br/><br/>

4. Wählen Sie **<Yes>**, um die I2C-Schnittstelle zu aktivieren, und dann **<Ok>**.

   .. image:: img/configuration_04.png
       :width: 100%

   .. raw:: html

       <br/><br/>

5. Wählen Sie **<Finish>**, um das Raspberry Pi Software-Konfigurationstool zu verlassen.

   .. image:: img/configuration_05.png
       :width: 100%

   .. raw:: html

       <br/><br/>

6. Überprüfen Sie die Adresse des angeschlossenen I2C-Geräts mit dem folgenden Befehl.

   .. code-block::

       i2cdetect -y 1      

   .. image:: img/configuration_06.png
       :width: 100%

   Die Adressen aller angeschlossenen I2C-Geräte werden angezeigt.

   .. image:: img/configuration_07.png
       :width: 100%

   .. raw:: html

       <br/><br/>



.. _pi_enable_1wire:

1-Wire-Konfiguration
-----------------------

Um den 1-Wire-Port auf Ihrem Raspberry Pi zu aktivieren, befolgen Sie diese Schritte (überspringen Sie diesen Schritt, wenn er bereits aktiviert ist; wenn Sie sich unsicher sind, folgen Sie den Anweisungen).


1. Melden Sie sich bei Ihrem Raspberry Pi an, öffnen Sie das Terminal und geben Sie diesen Befehl ein, um das Raspberry Pi Software-Konfigurationstool zu starten. (Sie können das Terminal auch über SSH aufrufen.)

   .. code-block::

       sudo raspi-config

   .. image:: img/configuration_08.png
       :width: 100%

   .. raw:: html

       <br/><br/>

2. Gehen Sie zu **Interfacing options**.

   .. note::
      Verwenden Sie die Pfeiltasten ``up`` und ``down``, um die Auswahl zwischen den verfügbaren Optionen zu bewegen. Mit der rechten Pfeiltaste gelangen Sie aus dem Optionsmenü zu den Tasten ``<Select>`` und ``<Finish>``. Mit der linken Pfeiltaste kehren Sie zu den Optionen zurück. Alternativ können Sie die ``Tab``-Taste verwenden, um zwischen den Optionen zu wechseln.

   .. image:: img/configuration_09.png
       :width: 100%

   .. raw:: html

       <br/><br/>

3. Wählen Sie **1-Wire**.

   .. image:: img/configuration_10.png
       :width: 100%

   .. raw:: html

       <br/><br/>

4. Wählen Sie **<Yes>**, um die 1-Wire-Schnittstelle zu aktivieren, und dann **<Ok>**.

   .. image:: img/configuration_11.png
       :width: 100%

   .. raw:: html

       <br/><br/>

5. Wählen Sie **<Finish>**, um das Raspberry Pi Software-Konfigurationstool zu verlassen.

   .. image:: img/configuration_12.png
       :width: 100%

   .. raw:: html

       <br/><br/>

6. Wählen Sie **<Yes>**, um den Raspberry Pi neu zu starten.

   .. image:: img/configuration_13.png
       :width: 100%

   .. raw:: html

       <br/><br/>

