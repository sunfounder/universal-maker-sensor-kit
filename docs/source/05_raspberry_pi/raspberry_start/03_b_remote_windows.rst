 
 .. note::

    Hallo und willkommen in der SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasten-Gemeinschaft auf Facebook! Tauchen Sie tiefer ein in die Welt von Raspberry Pi, Arduino und ESP32 mit anderen Enthusiasten.

    **Warum beitreten?**

    - **Expertenunterstützung**: Lösen Sie Nachverkaufsprobleme und technische Herausforderungen mit Hilfe unserer Gemeinschaft und unseres Teams.
    - **Lernen & Teilen**: Tauschen Sie Tipps und Anleitungen aus, um Ihre Fähigkeiten zu verbessern.
    - **Exklusive Vorschauen**: Erhalten Sie frühzeitigen Zugang zu neuen Produktankündigungen und exklusiven Einblicken.
    - **Spezialrabatte**: Genießen Sie exklusive Rabatte auf unsere neuesten Produkte.
    - **Festliche Aktionen und Gewinnspiele**: Nehmen Sie an Gewinnspielen und Feiertagsaktionen teil.

    👉 Sind Sie bereit, mit uns zu erkunden und zu erschaffen? Klicken Sie auf [|link_sf_facebook|] und treten Sie heute bei!

.. _remote_windows:

Windows-Benutzer
=======================

Als Windows-Benutzer können Sie Windows PowerShell verwenden, um sich remote beim Raspberry Pi anzumelden.

#. Drücken Sie die Tastenkombination ``windows`` + ``R`` auf Ihrer Tastatur, um das **Ausführen**-Programm zu öffnen. Geben Sie dann **powershell** in das Eingabefeld ein. 

   .. image:: img/windows_01.png
       :align: center

#. Überprüfen Sie, ob Ihr Raspberry Pi im selben Netzwerk ist, indem Sie ``ping <hostname>.local`` eingeben. 

   .. code-block:: shell

       ping raspberrypi.local

   .. image:: img/windows_02.png
       :width: 550
       :align: center

   * Wenn das Terminal die Meldung ``Ping request could not find host <hostname>.local`` anzeigt, besteht die Möglichkeit, dass der Raspberry Pi keine Verbindung zum Netzwerk herstellen konnte. Bitte überprüfen Sie das Netzwerk.
   * Wenn Sie wirklich nicht ``<hostname>.local`` pingen können, versuchen Sie stattdessen :ref:`die IP-Adresse zu erhalten <get_ip>` und ``ping <IP address>`` (z.B. ``ping 192.168.6.116``).
   * Wenn mehrere Meldungen wie "Antwort von <IP-Adresse>: Bytes=32 Zeit<1ms TTL=64" angezeigt werden, bedeutet dies, dass Ihr Computer auf den Raspberry Pi zugreifen kann.

   .. raw:: html

      <br/>

#. Geben Sie ``ssh <username>@<hostname>.local`` ein (oder ``ssh <username>@<IP address>``).

   .. code-block:: shell

       ssh pi@raspberrypi.local


#. Es kann folgende Meldung erscheinen.

   .. code-block::

       The authenticity of host 'raspberrypi.local (192.168.6.116)' can't be established.
       ECDSA key fingerprint is SHA256:7ggckKZ2EEgS76a557cddfxFNDOBBuzcJsgaqA/igz4.
       Are you sure you want to continue connecting (yes/no/[fingerprint])? 

   Geben Sie "Ja" ein.

#. Geben Sie das zuvor festgelegte Passwort ein. (Mine is ``raspberry``.)

   .. note::
       Wenn Sie das Passwort eingeben, werden die Zeichen im Fenster nicht angezeigt, was normal ist. Geben Sie einfach das korrekte Passwort ein.

#. Wir haben jetzt eine Verbindung zum Raspberry Pi hergestellt und sind bereit für den nächsten Schritt.

   .. image:: img/windows_03.png
       :width: 550
       :align: center

.. _windows_remote_desktop:

Remote Desktop
------------------

Wenn Sie mit der Verwendung des Befehlsfensters zum Zugriff auf Ihren Raspberry Pi nicht zufrieden sind, können Sie auch die Remote-Desktop-Funktion verwenden, um Dateien auf Ihrem Raspberry Pi einfach über eine grafische Benutzeroberfläche zu verwalten.

Hier verwenden wir `VNC® Viewer <https://www.realvnc.com/en/connect/download/viewer/>`_.

**VNC-Dienst aktivieren**

Der VNC-Dienst wurde im System installiert. Standardmäßig ist VNC deaktiviert. Sie müssen es in der Konfiguration aktivieren.

#. Geben Sie den folgenden Befehl ein:

   .. raw:: html

       <run></run>

   .. code-block:: shell 

       sudo raspi-config


#. Wählen Sie durch Drücken der Pfeiltaste nach unten auf Ihrer Tastatur **3 Interfacing-Optionen** aus und drücken Sie dann die **Eingabetaste**.

   .. image:: img/windows_04.png
       :align: center

#. Wählen Sie dann **VNC** aus.

   .. image:: img/windows_05.png
       :align: center

#. Verwenden Sie die Pfeiltasten auf der Tastatur, um **<Yes>** -> **<OK>** -> **<Finish>** auszuwählen, um die Einrichtung abzuschließen.

   .. image:: img/windows_06.png
       :align: center

**Anmeldung bei VNC**

#. Sie müssen den `VNC Viewer <https://www.realvnc.com/en/connect/download/viewer/>`_ auf Ihrem Personalcomputer herunterladen und installieren.

#. Öffnen Sie ihn, sobald die Installation abgeschlossen ist. Geben Sie dann den Hostnamen oder die IP-Adresse ein und drücken Sie die Eingabetaste.

   .. image:: img/windows_07.png
       :align: center

#. Geben Sie nach Eingabe des Namens und des Passworts Ihres Raspberry Pi auf **OK**.

   .. image:: img/windows_08.png
       :align: center

#. Jetzt können Sie den Desktop des Raspberry Pi sehen.

   .. image:: img/windows_09.png
       :align: center
