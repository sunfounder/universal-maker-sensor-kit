.. note::

   Hallo und willkommen in der SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasten-Gemeinschaft auf Facebook! Tauchen Sie tiefer ein in die Welt von Raspberry Pi, Arduino und ESP32 mit anderen Enthusiasten.

   **Warum beitreten?**

   - **Expertenunterstützung**: Lösen Sie Nachverkaufsprobleme und technische Herausforderungen mit Hilfe unserer Gemeinschaft und unseres Teams.
   - **Lernen & Teilen**: Tauschen Sie Tipps und Anleitungen aus, um Ihre Fähigkeiten zu verbessern.
   - **Exklusive Vorschauen**: Erhalten Sie frühzeitigen Zugang zu neuen Produktankündigungen und exklusiven Einblicken.
   - **Spezialrabatte**: Genießen Sie exklusive Rabatte auf unsere neuesten Produkte.
   - **Festliche Aktionen und Gewinnspiele**: Nehmen Sie an Gewinnspielen und Feiertagsaktionen teil.

   👉 Sind Sie bereit, mit uns zu erkunden und zu erschaffen? Klicken Sie auf [|link_sf_facebook|] und treten Sie heute bei!

Wie erstellt, öffnet oder speichert man ein Sketch?
=====================================================

#. Wenn Sie die Arduino IDE zum ersten Mal öffnen oder ein neues Sketch erstellen, sehen Sie eine Seite wie diese, auf der die Arduino IDE eine neue Datei für Sie erstellt, die "Sketch" genannt wird.

   .. image:: img/sp221014_173458.png

   Diese Sketch-Dateien haben einen temporären Namen, aus dem Sie das Erstellungsdatum der Datei erkennen können. ``sketch_oct14a.ino`` bedeutet das erste Sketch vom 14. Oktober, ``.ino`` ist das Dateiformat dieses Sketches.

#. Lassen Sie uns nun versuchen, ein neues Sketch zu erstellen. Kopieren Sie den folgenden Code in die Arduino IDE, um den ursprünglichen Code zu ersetzen.

   .. image:: img/create1.png

   .. code-block:: Arduino

       void setup() {
           // put your setup code here, to run once:
           pinMode(13,OUTPUT); 
       }

       void loop() {
           // put your main code here, to run repeatedly:
           digitalWrite(13,HIGH);
           delay(500);
           digitalWrite(13,LOW);
           delay(500);
       }

#. Drücken Sie ``Ctrl+S`` oder klicken Sie auf **Datei** -> **Speichern**. Das Sketch wird standardmäßig in ``C:\Users\{Ihr_Benutzer}\Documents\Arduino`` gespeichert. Sie können es umbenennen oder einen neuen Pfad zum Speichern wählen.

   .. image:: img/create2.png

#. Nach erfolgreichem Speichern sehen Sie, dass der Name in der Arduino IDE aktualisiert wurde.

   .. image:: img/create3.png

Bitte fahren Sie mit dem nächsten Abschnitt fort, um zu erfahren, wie Sie dieses erstellte Sketch auf Ihr Arduino-Board hochladen können.
