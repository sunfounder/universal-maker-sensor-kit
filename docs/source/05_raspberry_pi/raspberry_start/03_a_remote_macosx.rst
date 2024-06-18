 
.. note::

   Hallo und willkommen in der SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasten-Gemeinschaft auf Facebook! Tauchen Sie tiefer ein in die Welt von Raspberry Pi, Arduino und ESP32 mit anderen Enthusiasten.

   **Warum beitreten?**

   - **Expertenunterstützung**: Lösen Sie Nachverkaufsprobleme und technische Herausforderungen mit Hilfe unserer Gemeinschaft und unseres Teams.
   - **Lernen & Teilen**: Tauschen Sie Tipps und Anleitungen aus, um Ihre Fähigkeiten zu verbessern.
   - **Exklusive Vorschauen**: Erhalten Sie frühzeitigen Zugang zu neuen Produktankündigungen und exklusiven Einblicken.
   - **Spezialrabatte**: Genießen Sie exklusive Rabatte auf unsere neuesten Produkte.
   - **Festliche Aktionen und Gewinnspiele**: Nehmen Sie an Gewinnspielen und Feiertagsaktionen teil.

   👉 Sind Sie bereit, mit uns zu erkunden und zu erschaffen? Klicken Sie auf [|link_sf_facebook|] und treten Sie heute bei!

.. _remote_macosx:

Mac OS X Benutzer
==========================

Für Mac-Benutzer ist der direkte Zugriff auf den Raspberry Pi-Desktop über VNC bequemer als über die Befehlszeile. Sie können darauf über den Finder zugreifen, indem Sie das festgelegte Kontokennwort eingeben, nachdem Sie VNC auf der Seite des Raspberry Pi aktiviert haben.

Beachten Sie, dass diese Methode die Kommunikation zwischen dem Mac und dem Raspberry Pi nicht verschlüsselt. 
Die Kommunikation findet innerhalb Ihres Heim- oder Unternehmensnetzwerks statt, sodass selbst wenn sie ungeschützt ist, dies kein Problem darstellt. 
Wenn Sie jedoch Bedenken haben, können Sie eine VNC-Anwendung wie `VNC® Viewer <https://www.realvnc.com/en/connect/download/viewer/>`_ installieren.

Alternativ wäre es praktisch, wenn Sie einen vorübergehenden Monitor (TV), eine Maus und eine Tastatur verwenden könnten, um den Raspberry Pi-Desktop direkt zu öffnen und VNC einzurichten. 
Wenn nicht, ist das auch nicht schlimm, Sie können auch das SSH-Kommando verwenden, um die Bash-Shell des Raspberry Pi zu öffnen und dann das Kommando zur Einrichtung des VNC zu verwenden.


* :ref:`have_temp_monitor`
* :ref:`no_temp_monitor`


.. _have_temp_monitor:

Vorübergehend einen Monitor (oder TV) haben?
---------------------------------------------------------------------

#. Schließen Sie einen Monitor (oder TV), eine Maus und eine Tastatur an den Raspberry Pi an und schalten Sie ihn ein. Wählen Sie das Menü entsprechend den Zahlen in der Abbildung aus.


   .. image:: img/mac_01.png
       :align: center

#. Der folgende Bildschirm wird angezeigt. Setzen Sie **VNC** auf **Aktiviert** auf der Registerkarte **Schnittstellen** und klicken Sie auf **OK**.

   .. image:: img/mac_02.png
       :align: center


#. Ein VNC-Symbol erscheint oben rechts auf dem Bildschirm und der VNC-Server startet.

   .. image:: img/mac_03.png
       :align: center


#. Öffnen Sie das VNC-Serverfenster, indem Sie auf das **VNC**-Symbol klicken, und klicken Sie dann auf die Schaltfläche **Menü** oben rechts und wählen Sie **Optionen** aus.

   .. image:: img/mac_04.png
       :align: center

#. Sie werden mit dem folgenden Bildschirm präsentiert, auf dem Sie die Optionen ändern können.

   .. image:: img/mac_05.png
       :align: center

   Setzen Sie **Verschlüsselung** auf **Bevorzugen Sie aus** und **Authentifizierung** auf **VNC-Passwort**. 
    
#. Wenn Sie auf die Schaltfläche **OK** klicken, wird der Bildschirm zur Passworteingabe angezeigt. Sie können dasselbe Passwort wie das Raspberry-Pi-Passwort oder ein anderes Passwort verwenden, also geben Sie es ein und klicken Sie auf **OK**. 

   .. image:: img/mac_06.png
       :align: center

   Sie sind nun bereit, eine Verbindung von Ihrem Mac herzustellen. Sie können den Monitor abkoppeln.

**Von hier aus erfolgt die Bedienung auf der Mac-Seite.**

#. Wählen Sie nun **Mit Server verbinden** im Menü des Finders aus, das Sie durch Rechtsklicken öffnen können.

   .. image:: img/mac_07.png
       :align: center

#. Geben Sie ``vnc://<Benutzername>@<Hostname>.local`` (oder ``vnc://<Benutzername>@<IP-Adresse>``) ein. Nach der Eingabe klicken Sie auf **Verbinden**.

   .. image:: img/mac_08.png
       :align: center


#. Sie werden nach einem Passwort gefragt, also geben Sie es bitte ein.

   .. image:: img/mac_09.png
       :align: center

#. Der Desktop des Raspberry Pi wird angezeigt, und Sie können ihn vom Mac aus bedienen, wie er ist.

   .. image:: img/mac_10.png
       :align: center

.. _no_temp_monitor:

Keinen vorübergehenden Monitor (oder TV) zur Verfügung?
---------------------------------------------------------------------------

* Sie können das SSH-Kommando verwenden, um die Bash-Shell des Raspberry Pi zu öffnen.
* Bash ist die Standard-Shell für Linux.
* Die Shell selbst ist ein Befehl (Anweisung), wenn der Benutzer Unix/Linux verwendet.
* Die meisten Aufgaben können über die Shell erledigt werden.
* Nachdem Sie die Seite des Raspberry Pi eingerichtet haben, können Sie auf den Desktop des Raspberry Pi zugreifen, indem Sie den **Finder** auf dem Mac verwenden.


#. Geben Sie ``ssh <username>@<hostname>.local`` ein, um eine Verbindung zum Raspberry Pi herzustellen.


   .. code-block:: shell

       ssh pi@raspberrypi.local


   .. image:: img/mac_11.png


#. Die folgende Meldung wird nur beim ersten Anmelden angezeigt, geben Sie also **yes** ein.

   .. code-block::

       The authenticity of host 'raspberrypi.local (2400:2410:2101:5800:635b:f0b6:2662:8cba)' can't be established.
       ED25519 key fingerprint is SHA256:oo7x3ZSgAo032wD1tE8eW0fFM/kmewIvRwkBys6XRwg.
       This key is not known by any other names
       Are you sure you want to continue connecting (yes/no/[fingerprint])?


#. Geben Sie das Passwort für den Raspberry Pi ein. Das eingegebene Passwort wird nicht angezeigt, achten Sie also darauf, keinen Fehler zu machen.

   .. code-block::

       pi@raspberrypi.local's password: 
       Linux raspberrypi 5.15.61-v8+ #1579 SMP PREEMPT Fri Aug 26 11:16:44 BST 2022 aarch64

       The programs included with the Debian GNU/Linux system are free software;
       the exact distribution terms for each program are described in the
       individual files in /usr/share/doc/*/copyright.

       Debian GNU/Linux comes with ABSOLUTELY NO WARRANTY, to the extent
       permitted by applicable law.
       Last login: Thu Sep 22 12:18:22 2022
       pi@raspberrypi:~ $ 


    

#. Richten Sie Ihren Raspberry Pi so ein, dass Sie sich von Ihrem Mac aus erfolgreich anmelden können. Der erste Schritt besteht darin, Ihr Betriebssystem zu aktualisieren, indem Sie die folgenden Befehle ausführen.

   .. code-block:: shell

       sudo apt update
       sudo apt upgrade


   ``Do you want to continue? [Y/n]``, geben Sie ``Y`` ein, wenn Sie dazu aufgefordert werden.

   Es kann einige Zeit dauern, bis das Update abgeschlossen ist. (Es hängt von der Anzahl der Updates zu diesem Zeitpunkt ab.)


#. Geben Sie den folgenden Befehl ein, um den **VNC-Server** zu aktivieren.

   .. code-block:: shell

       sudo raspi-config

#. Es wird der folgende Bildschirm angezeigt. Wählen Sie **3 Interface Options** mit den Pfeiltasten auf der Tastatur aus und drücken Sie die **Eingabetaste**.

   .. image:: img/mac_12.png
       :align: center

#. Wählen Sie dann **VNC** aus.

   .. image:: img/mac_13.png
       :align: center

#. Verwenden Sie die Pfeiltasten auf der Tastatur, um **<Ja>** -> **<OK>** -> **<Fertigstellen>** auszuwählen, um die Einrichtung abzuschließen.

   .. image:: img/mac_14.png
       :align: center


#. Nachdem der VNC-Server gestartet wurde, ändern wir die Einstellungen für die Verbindung von einem Mac aus.

   Um Parameter für alle Programme für alle Benutzerkonten auf dem Computer festzulegen, erstellen Sie ``/etc/vnc/config.d/common.custom``.

   .. code-block:: shell

       sudo nano /etc/vnc/config.d/common.custom

   Geben Sie nach Eingabe von ``Authentication=VncAuthenter`` ``Ctrl+X`` ein -> ``Y`` -> ``Enter``, um zu speichern und zu verlassen.

   .. image:: img/mac_15.png
       :align: center

#. Legen Sie außerdem ein Passwort fest, um sich über VNC von einem Mac aus anzumelden. Sie können dasselbe Passwort wie das Raspberry Pi-Passwort oder ein anderes Passwort verwenden. 


   .. code-block:: shell

       sudo vncpasswd -service


#. Nach Abschluss der Einrichtung starten Sie den Raspberry Pi neu, um die Änderungen zu übernehmen.

   .. code-block:: shell

       sudo sudo reboot

#. Wählen Sie nun **Mit Server verbinden** im Menü des **Finders**, das Sie durch Rechtsklick öffnen können.

   .. image:: img/mac_16.png
       :align: center

#. Geben Sie ``vnc://<username>@<hostname>.local`` ein (oder ``vnc://<username>@<IP address>``). Nach der Eingabe klicken Sie auf **Verbinden**.

   .. image:: img/mac_17.png
       :align: center


#. Sie werden nach einem Passwort gefragt, also geben Sie es bitte ein.

   .. image:: img/mac_18.png
       :align: center

#. Der Desktop des Raspberry Pi wird angezeigt, und Sie können ihn vom Mac aus bedienen, wie er ist.

   .. image:: img/mac_19.png
       :align: center
