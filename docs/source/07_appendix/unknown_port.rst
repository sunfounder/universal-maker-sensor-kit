 
 .. note::

    Hallo und willkommen in der SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasten-Gemeinschaft auf Facebook! Tauchen Sie tiefer ein in die Welt von Raspberry Pi, Arduino und ESP32 mit anderen Enthusiasten.

    **Warum beitreten?**

    - **Expertenunterstützung**: Lösen Sie Nachverkaufsprobleme und technische Herausforderungen mit Hilfe unserer Gemeinschaft und unseres Teams.
    - **Lernen & Teilen**: Tauschen Sie Tipps und Anleitungen aus, um Ihre Fähigkeiten zu verbessern.
    - **Exklusive Vorschauen**: Erhalten Sie frühzeitigen Zugang zu neuen Produktankündigungen und exklusiven Einblicken.
    - **Spezialrabatte**: Genießen Sie exklusive Rabatte auf unsere neuesten Produkte.
    - **Festliche Aktionen und Gewinnspiele**: Nehmen Sie an Gewinnspielen und Feiertagsaktionen teil.

    👉 Sind Sie bereit, mit uns zu erkunden und zu erschaffen? Klicken Sie auf [|link_sf_facebook|] und treten Sie heute bei!

.. _unknown_com_port:

"Unknown COMxx" wird immer angezeigt?
=======================================

Wenn das ESP32-Board an den Computer angeschlossen wird, zeigt die Arduino-IDE oft ``Unknown COMxx`` an. Warum passiert das?

.. image:: img/unknown_device.png

Das liegt daran, dass der USB-Treiber für ESP32 sich von den regulären Arduino-Boards unterscheidet. Die Arduino-IDE kann dieses Board nicht automatisch erkennen.

In einem solchen Fall müssen Sie das richtige Board manuell auswählen, indem Sie folgende Schritte befolgen:

#. Klicken Sie auf **"Select the other board and port"**.

    .. image:: img/unknown_select.png

#. Geben Sie im Suchfeld **"esp32 dev module"** ein und wählen Sie das angezeigte Board aus. Wählen Sie anschließend den richtigen Port und klicken Sie auf **OK**.

    .. image:: img/unknown_board.png

#. Nun sollten Sie Ihr Board und den Port in diesem Schnellansichtsfenster sehen können.

    .. image:: img/unknown_correct.png