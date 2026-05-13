.. note:: 

   Ciao, benvenuti nella Comunità degli Appassionati di SunFounder Raspberry Pi & Arduino & ESP32 su Facebook! Esplorate più a fondo Raspberry Pi, Arduino e ESP32 insieme ad altri appassionati.

   **Perché unirsi?**

   - **Supporto Esperto**: Risolvi problemi post-vendita e sfide tecniche con l'aiuto della nostra comunità e del nostro team.
   - **Impara & Condividi**: Scambia consigli e tutorial per migliorare le tue competenze.
   - **Anteprime Esclusive**: Ottieni accesso anticipato agli annunci di nuovi prodotti e anteprime.
   - **Sconti Speciali**: Goditi sconti esclusivi sui nostri prodotti più recenti.
   - **Promozioni Festive e Regali**: Partecipa a regali e promozioni festive.

   👉 Pronto a esplorare e creare con noi? Clicca [|link_sf_facebook|] e unisciti oggi!

Installare la Scheda ESP32 (Importante)
===========================================

Per programmare il microcontrollore ESP32, dobbiamo installare il pacchetto della scheda ESP32 nell'Arduino IDE. Segui la guida passo dopo passo qui sotto:

**Installare la Scheda ESP32**

#. Apri l'Arduino IDE. Vai su **File** e seleziona **Preferenze** dal menu a tendina.

   .. image:: img/install_esp32_1.png

#. Nella finestra Preferenze, trova il campo **URL aggiuntivi per il Gestore Schede**. Clicca su di esso per attivare la casella di testo.

   .. image:: img/install_esp32_2.png

#. Aggiungi il seguente URL al campo **URL aggiuntivi per il Gestore Schede**: https://espressif.github.io/arduino-esp32/package_esp32_index.json. Questo URL punta al file indice del pacchetto per le schede ESP32. Clicca il pulsante **OK** per salvare le modifiche.

   .. image:: img/install_esp32_3.png

#. Nella finestra **Gestore Schede**, digita **ESP32** nella barra di ricerca. Clicca il pulsante **Installa** per avviare il processo di installazione. Questo scaricherà e installerà il pacchetto della scheda ESP32.

   .. image:: img/install_esp32_4.png

#. Complimenti! Hai installato con successo il pacchetto della scheda ESP32 nell'Arduino IDE.

**Caricare il Codice**

#. Ora, collega l'ESP32 al tuo computer tramite un cavo Micro USB.

#. Quindi seleziona la scheda corretta, **ESP32 Dev Module**, cliccando su **Strumenti** -> **Scheda** -> **esp32**.

   .. image:: img/install_esp32_5.png
      :width: 100%

#. Se il tuo ESP32 è collegato al computer, puoi scegliere la porta corretta cliccando su **Strumenti** -> **Porta**.

   .. image:: img/install_esp32_6.png
      :width: 100%

#. Inoltre, Arduino 2.0 ha introdotto un nuovo modo per selezionare rapidamente la scheda e la porta. Per l'ESP32, di solito non viene riconosciuto automaticamente, quindi è necessario cliccare su **Seleziona altra scheda e porta**.

   .. image:: img/install_esp32_7.png
      :width: 80%

#. Nella casella di ricerca, digita **ESP32 Dev Module** e selezionalo quando appare. Poi, scegli la porta corretta e clicca **OK**.

   .. image:: img/install_esp32_8.png
      :width: 90%

#. Successivamente, puoi selezionarlo tramite questa finestra di accesso rapido. Nota che durante l'uso successivo, potrebbero esserci momenti in cui l'ESP32 non è disponibile nella finestra di accesso rapido, e sarà necessario ripetere i due passaggi sopra.

   .. image:: img/install_esp32_9.png
      :width: 80%

#. Entrambi i metodi permettono di selezionare la scheda e la porta corrette, quindi scegli quello che ti si addice meglio. Ora, tutto è pronto per caricare il codice sull'ESP32.




