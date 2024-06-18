.. note::

   Hallo und willkommen in der SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasten-Gemeinschaft auf Facebook! Tauchen Sie tiefer ein in die Welt von Raspberry Pi, Arduino und ESP32 mit anderen Enthusiasten.

   **Warum beitreten?**

   - **Expertenunterstützung**: Lösen Sie Nachverkaufsprobleme und technische Herausforderungen mit Hilfe unserer Gemeinschaft und unseres Teams.
   - **Lernen & Teilen**: Tauschen Sie Tipps und Anleitungen aus, um Ihre Fähigkeiten zu verbessern.
   - **Exklusive Vorschauen**: Erhalten Sie frühzeitigen Zugang zu neuen Produktankündigungen und exklusiven Einblicken.
   - **Spezialrabatte**: Genießen Sie exklusive Rabatte auf unsere neuesten Produkte.
   - **Festliche Aktionen und Gewinnspiele**: Nehmen Sie an Gewinnspielen und Feiertagsaktionen teil.

   👉 Sind Sie bereit, mit uns zu erkunden und zu erschaffen? Klicken Sie auf [|link_sf_facebook|] und treten Sie heute bei!

.. _esp32_iot_bluetooth_app:

Lektion 50: Android-Anwendung – RGB-LED-Betrieb über Arduino und Bluetooth
==================================================================================

Ziel dieses Projekts ist es, eine Android-Anwendung zu entwickeln, mit der die Farbe einer RGB-LED über ein Smartphone mithilfe der Bluetooth-Technologie gesteuert werden kann.

Diese Android-Anwendung wird mithilfe einer kostenlosen webbasierten Plattform namens MIT App Inventor 2 erstellt. Das Projekt bietet eine hervorragende Gelegenheit, sich mit der Schnittstelle eines Arduino und einem Smartphone vertraut zu machen.

**Erforderliche Komponenten**

Für dieses Projekt benötigen wir die folgenden Komponenten.

Es ist definitiv praktisch, ein komplettes Kit zu kaufen, hier ist der Link:

.. list-table::
    :widths: 20 20 20
    :header-rows: 1

    *   - Name	
        - ITEMS IN THIS KIT
        - LINK
    *   - Universal Maker Sensor Kit
        - 94
        - |link_umsk|

Sie können sie auch separat über die untenstehenden Links kaufen.

.. list-table::
    :widths: 30 20
    :header-rows: 1

    *   - COMPONENT INTRODUCTION
        - PURCHASE LINK

    *   - ESP32 & Development Board
        - |link_esp32_camera_pro_kit_buy|
    *   - :ref:`cpn_breadboard`
        - |link_breadboard_buy|
    *   - :ref:`cpn_rgb`
        - \-

**1. Erstellung der Android-Anwendung**

Die Android-Anwendung wird mithilfe einer kostenlosen Webanwendung namens |link_appinventor| erstellt. MIT App Inventor ist ein hervorragender Ausgangspunkt für die Android-Entwicklung, da seine intuitive Drag-and-Drop-Funktionalität die Erstellung einfacher Anwendungen ermöglicht.

Lassen Sie uns beginnen.

#. Hier ist die Login-Seite: http://ai2.appinventor.mit.edu. Sie benötigen ein Google-Konto, um sich bei MIT App Inventor zu registrieren.

#. Nach dem Einloggen navigieren Sie zu **Projects** -> **Import project (.aia) from my computer**. Laden Sie anschließend die Datei ``control_rgb_led.aia`` hoch, die sich im Pfad ``esp32-starter-kit-main\c\codes\iot_10_bluetooth_app_inventor`` befindet.

   .. image:: img/10_ble_app_inventor1.png

#. Nach dem Hochladen der ``.aia``-Datei sehen Sie die Anwendung in der **MIT App Inventor**-Software. Dies ist eine vorgefertigte Vorlage. Sie können diese Vorlage nach Belieben ändern, sobald Sie sich mit **MIT App Inventor** vertraut gemacht haben.

   .. image:: img/10_ble_app_inventor2.png

#. In **MIT App Inventor** gibt es zwei Hauptbereiche: den **Designer** und die **Blocks**.

   .. image:: img/10_ble_app_inventor3.png

#. Der **Designer** ermöglicht es Ihnen, Schaltflächen, Texte, Bildschirme hinzuzufügen und das gesamte Erscheinungsbild Ihrer Anwendung zu ändern.

   .. image:: img/10_ble_app_inventor2.png
   

#. Anschließend gibt es den Bereich **Blocks**. Der Bereich **Blocks** ermöglicht die Erstellung benutzerdefinierter Funktionen für Ihre Anwendung.

   .. image:: img/10_ble_app_inventor5.png

#. Um die Anwendung auf einem Smartphone zu installieren, navigieren Sie zum **Build**-Tab.

   .. image:: img/10_ble_app_inventor6.png

   * Sie können eine ``.apk``-Datei generieren. Nach Auswahl dieser Option erscheint eine Seite, auf der Sie zwischen dem Herunterladen einer ``.apk``-Datei oder dem Scannen eines QR-Codes zur Installation wählen können. Befolgen Sie die Installationsanleitung, um die Installation der Anwendung abzuschließen.
   * Wenn Sie diese App auf **Google Play** oder einem anderen App-Marktplatz hochladen möchten, können Sie eine ``.aab``-Datei generieren.

**2. Hochladen des Codes**

#. Bauen Sie die Schaltung auf.

   .. image:: img/Lesson_28_RGB_LED_Module_esp32_bb.png

#. Anschließend verbinden Sie das ESP32 mit Ihrem Computer über ein USB-Kabel.

#. Öffnen Sie die Datei ``Lesson_50_Bluetooth_app_inventor.ino``, die sich im Verzeichnis ``universal-maker-sensor-kit\esp32\Lesson_50_Bluetooth_app_inventor`` befindet, oder kopieren Sie den Code in die Arduino IDE.

   .. raw:: html

      <iframe src=https://create.arduino.cc/editor/sunfounder01/07622bb5-31eb-4a89-b6f2-085f3332051f/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>



#. Sobald Sie die entsprechende Platine (**ESP32 Dev Module**) und den Port ausgewählt haben, klicken Sie auf die Schaltfläche **Upload**.

**3. Verbindung zwischen App und ESP32**

Stellen Sie sicher, dass die zuvor erstellte Anwendung auf Ihrem Smartphone installiert ist.

#. Aktivieren Sie zunächst **Bluetooth** auf Ihrem Smartphone.

   .. image:: img/10_ble_mobile1.png
      :width: 500
      :align: center

#. Gehen Sie zu den **Bluetooth-Einstellungen** auf Ihrem Smartphone und suchen Sie nach **ESP32RGB**.

   .. image:: img/10_ble_mobile2.png
      :width: 500
      :align: center

#. Klicken Sie darauf und stimmen Sie der **Pairing**-Anfrage im Pop-up-Fenster zu.

   .. image:: img/10_ble_mobile3.png
      :width: 500
      :align: center

#. Öffnen Sie nun die kürzlich installierte **Control_RGB_LED**-App.

   .. image:: img/10_ble_mobile4.png
      :align: center

#. Klicken Sie in der App auf **Connect Bluetooth**, um eine Verbindung zwischen der App und dem ESP32 herzustellen.

   .. image:: img/10_ble_mobile5.png
      :width: 500
      :align: center

#. Wählen Sie das angezeigte ``xx.xx.xx.xx.xx.xx ESP32RGB`` aus. Wenn Sie ``SerialBT.begin("ESP32RGB");`` im Code geändert haben, wählen Sie den von Ihnen eingestellten Namen aus.

   .. image:: img/10_ble_mobile6.png
      :width: 500
      :align: center

#. Wenn Sie eine Weile gewartet haben und keinen Gerätenamen sehen können, kann es sein, dass diese App nicht berechtigt ist, nach umliegenden Geräten zu suchen. In diesem Fall müssen Sie die Einstellungen manuell anpassen.

   * Drücken Sie lange auf das App-Symbol und klicken Sie auf die erscheinende **App-Info**. Wenn Sie eine andere Methode haben, um diese Seite zu erreichen, folgen Sie dieser.

      .. image:: img/10_ble_mobile8.png
         :width: 500
         :align: center

   * Gehen Sie zur Seite **Berechtigungen**.

      .. image:: img/10_ble_mobile9.png
         :width: 500
         :align: center

   * Suchen Sie **Nahegelegene Geräte** und wählen Sie **Immer zulassen**, damit diese App nach nahegelegenen Geräten suchen kann.

      .. image:: img/10_ble_mobile10.png
         :width: 500
         :align: center

   * Starten Sie nun die App neu und wiederholen Sie die Schritte 5 und 6, um erfolgreich eine Bluetooth-Verbindung herzustellen.

#. Nach erfolgreicher Verbindung kehren Sie automatisch zur Hauptseite zurück, wo die Verbindung angezeigt wird. Jetzt können Sie die RGB-Werte anpassen und die Farbe der RGB-Anzeige durch Drücken der Schaltfläche **Change Color** ändern.

   .. image:: img/10_ble_mobile7.png
      :width: 500
      :align: center
