 .. note::

    Hallo und willkommen in der SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasten-Gemeinschaft auf Facebook! Tauchen Sie tiefer ein in die Welt von Raspberry Pi, Arduino und ESP32 mit anderen Enthusiasten.

    **Warum beitreten?**

    - **Expertenunterstützung**: Lösen Sie Nachverkaufsprobleme und technische Herausforderungen mit Hilfe unserer Gemeinschaft und unseres Teams.
    - **Lernen & Teilen**: Tauschen Sie Tipps und Anleitungen aus, um Ihre Fähigkeiten zu verbessern.
    - **Exklusive Vorschauen**: Erhalten Sie frühzeitigen Zugang zu neuen Produktankündigungen und exklusiven Einblicken.
    - **Spezialrabatte**: Genießen Sie exklusive Rabatte auf unsere neuesten Produkte.
    - **Festliche Aktionen und Gewinnspiele**: Nehmen Sie an Gewinnspielen und Feiertagsaktionen teil.

    👉 Sind Sie bereit, mit uns zu erkunden und zu erschaffen? Klicken Sie auf [|link_sf_facebook|] und treten Sie heute bei!


Kurzanleitung zu Thonny
==================================

.. _open_run_code_py:

Code öffnen und direkt ausführen
---------------------------------------------

In jedem von uns bereitgestellten Projekt ist der spezifische verwendete Code klar identifiziert. Sie finden den entsprechenden Code für jedes Projekt im Verzeichnis ``universal-maker-sensor-kit-main/pico/``.

Bevor Sie jedoch fortfahren, müssen Sie das Paket herunterladen und die Bibliothek hochladen, wie in :ref:`add_libraries_py` beschrieben.

#. Öffnen Sie den Code.

   Zum Beispiel ``Lesson_01_Button_Module\01_button_module.py``.

   Wenn Sie darauf doppelklicken, wird ein neues Fenster auf der rechten Seite geöffnet. Sie können mehr als einen Code gleichzeitig öffnen.

   .. image:: img/05_open_code.png

#. Wählen Sie den richtigen Interpreter aus.

   Verwenden Sie ein Micro-USB-Kabel, um den Pico W mit Ihrem Computer zu verbinden, und wählen Sie den Interpreter "MicroPython (Raspberry Pi Pico)" aus.

   .. image:: img/05_sec_inter.png

#. Führen Sie den Code aus.

   Um das Skript auszuführen, klicken Sie auf die Schaltfläche **Aktuelles Skript ausführen** oder drücken Sie F5.

   .. image:: img/05_run_it.png

   Wenn der Code Informationen enthält, die gedruckt werden müssen, erscheinen diese im Shell; andernfalls erscheint nur die folgende Information.

   .. code-block:: shell

      >>> %Run -c $EDITOR_CONTENT

   Click **View** -> **Shell** to open the Shell window if it doesn't appear on your Thonny.

   * ``%Run -c $EDITOR_CONTENT`` ist ein Befehl von Thonny, der dem MicroPython-Interpreter auf Ihrem Pico W sagt, den Inhalt des Skriptbereichs - "EDITOR_CONTENT" - auszuführen.
   * Wenn danach eine Nachricht steht, handelt es sich normalerweise um die Nachricht, die Sie MicroPython zum Drucken mitgeteilt haben, oder um eine Fehlermeldung für den Code.

   .. raw:: html

      <br/>

#. Beenden Sie die Ausführung.

   .. image:: img/05_stop_it.png

   Um die Ausführung des Codes zu stoppen, klicken Sie auf die Schaltfläche **Halt/Neustart des Backends**. Der Befehl **%RUN -c $EDITOR_CONTENT** verschwindet nach dem Stoppen.

#. Speichern oder Speichern unter

   Änderungen am geöffneten Beispiel können Sie durch Drücken von **Strg+S** oder durch Klicken auf die Schaltfläche **Speichern** in Thonny speichern.

   Der Code kann als separate Datei auf dem Raspberry Pi Pico W gespeichert werden, indem Sie auf **Datei** -> **Speichern unter** klicken.

   .. image:: img/05_save_as.png

   Wählen Sie **Raspberry Pi Pico** aus.

   .. image:: img/05_sec_pico.png

   Klicken Sie dann nach Eingabe des Dateinamens und der Erweiterung **.py** auf **OK**. Auf dem Laufwerk des Raspberry Pi Pico W sehen Sie Ihre gespeicherte Datei.

   .. image:: img/05_sec_name.png

   .. note::
       Unabhängig davon, welchen Namen Sie Ihrem Code geben, ist es am besten, zu beschreiben, um welche Art von Code es sich handelt, und ihm keinen bedeutungslosen Namen wie ``abc.py`` zu geben.
       Wenn Sie den Code als ``main.py`` speichern, wird er automatisch ausgeführt, wenn die Stromversorgung eingeschaltet wird.


Datei erstellen und ausführen
-------------------------------------

Der Code wird direkt im Codeabschnitt angezeigt. Sie können ihn in Thonny kopieren und wie folgt ausführen.

#. Eine neue Datei erstellen

   Öffnen Sie die Thonny IDE, klicken Sie auf die Schaltfläche **Neu**, um eine neue leere Datei zu erstellen.

   .. image:: img/new_file.png

#. Code kopieren

   Kopieren Sie den Code aus dem Projekt in die Thonny IDE.

   Zum Beispiel:

   .. code:: python

      import machine
      import utime
      
      led = machine.Pin("LED", machine.Pin.OUT)
      while True:
          led.value(1)
          utime.sleep(2)
          led.value(0)
          utime.sleep(2)

   .. image:: img/05_2_copy_file.png

#. Richtigen Interpreter auswählen

   Schließen Sie den Pico W mit einem Micro-USB-Kabel an Ihren Computer an und wählen Sie den Interpreter "MicroPython (Raspberry Pi Pico)" in der unteren rechten Ecke aus.

   .. image:: img/05_2_sec_inter.png

#. Code ausführen

   Sie können auf **Aktuelles Skript ausführen** klicken oder einfach F5 drücken, um ihn auszuführen. 

   Dieser Code ist darauf ausgelegt, die onboard LED des Pico alle zwei Sekunden ein- und auszuschalten, um einen Blink-Effekt zu erzeugen. Sobald der Code ausgeführt wird, beobachten Sie das entsprechende Blink-Phänomen.

   .. image:: img/05_2_run_it.png

#. Ausführung stoppen

   Um den Code zu stoppen, klicken Sie auf die Schaltfläche **Stoppen/Neustart des Backends**. 
   
   .. image:: img/05_2_stop_it.png

#. Code speichern

   Sie können auf die Schaltfläche **Speichern** klicken, um den Code zu speichern.

   .. image:: img/05_2_save_code.png

   Anschließend fragt Thonny Sie, wohin der Code gespeichert werden soll. Sie können wählen, den Code direkt auf dem Pico zu speichern.

   .. image:: img/05_sec_pico.png

   Klicken Sie dann nach Eingabe des Dateinamens und der Erweiterung .py auf **OK**. 

   .. image:: img/05_2_save_code_2.png

   .. note::
       Unabhängig davon, welchen Namen Sie Ihrem Code geben, ist es am besten, zu beschreiben, um welche Art von Code es sich handelt, und ihm keinen bedeutungslosen Namen wie ``abc.py`` zu geben.
       Wenn Sie den Code als ``main.py`` speichern, wird er automatisch ausgeführt, wenn die Stromversorgung eingeschaltet wird.

#. Datei öffnen

   Hier sind zwei Möglichkeiten, eine gespeicherte Code-Datei zu öffnen.

   * Die erste Methode besteht darin, auf das Öffnungssymbol in der Thonny-Symbolleiste zu klicken. Genau wie beim Speichern eines Programms werden Sie gefragt, ob Sie es von **diesem Computer** oder **Raspberry Pi Pico** öffnen möchten. Klicken Sie zum Beispiel auf **Raspberry Pi Pico**, und Sie sehen eine Liste aller Programme, die Sie auf dem Pico W gespeichert haben.

     .. image:: img/05_2_open_file.png

   * Die zweite Möglichkeit besteht darin, die Dateivorschau direkt zu öffnen, indem Sie auf **Ansicht** -> **Datei** -> und dann doppelklicken auf die entsprechende ``.py``-Datei klicken, um sie zu öffnen.

     .. image:: img/05_2_file_view.png

