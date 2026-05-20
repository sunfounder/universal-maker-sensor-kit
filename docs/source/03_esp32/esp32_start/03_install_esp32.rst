.. note:: 

    ¡Hola, bienvenido a la comunidad de entusiastas de SunFounder en Facebook sobre Raspberry Pi, Arduino y ESP32! Sumérgete más a fondo en Raspberry Pi, Arduino y ESP32 con otros aficionados.

    **¿Por qué unirse?**

    - **Soporte de Expertos**: Resuelve problemas posventa y desafíos técnicos con ayuda de nuestra comunidad y equipo.
    - **Aprender y Compartir**: Intercambia consejos y tutoriales para mejorar tus habilidades.
    - **Previsualizaciones Exclusivas**: Obtén acceso anticipado a anuncios de nuevos productos y avances exclusivos.
    - **Descuentos Especiales**: Disfruta de descuentos exclusivos en nuestros productos más nuevos.
    - **Promociones Festivas y Sorteos**: Participa en sorteos y promociones festivas.

    👉 ¿Listo para explorar y crear con nosotros? Haz clic en [|link_sf_facebook|] ¡y únete hoy!

Instalación de la Placa ESP32 (Importante)
==============================================

Para programar el microcontrolador ESP32, necesitamos instalar el paquete de la placa ESP32 en el IDE de Arduino. Sigue la guía paso a paso a continuación:

**Instalar la Placa ESP32**

#. Abre el IDE de Arduino. Ve a **Archivo** y selecciona **Preferencias** en el menú desplegable.

   .. image:: img/install_esp32_1.png

#. En la ventana de Preferencias, localiza el campo **URLs Adicionales para Gestores de Placas**. Haz clic en él para activar el cuadro de texto.

   .. image:: img/install_esp32_2.png

#. Añade la siguiente URL al campo **URLs Adicionales para Gestores de Placas**: https://espressif.github.io/arduino-esp32/package_esp32_index.json. Esta URL apunta al archivo de índice del paquete para las placas ESP32. Haz clic en el botón **OK** para guardar los cambios.

   .. image:: img/install_esp32_3.png

#. En la ventana **Gestor de Placas**, escribe **ESP32** en la barra de búsqueda. Haz clic en el botón **Instalar** para comenzar el proceso de instalación. Esto descargará e instalará el paquete de la placa ESP32.

   .. image:: img/install_esp32_4.png

#. ¡Felicidades! Has instalado con éxito el paquete de la placa ESP32 en el IDE de Arduino. 

**Subir el Código**

#. Ahora, conecta la placa ESP32 a tu computadora.

#. Luego selecciona la placa correcta, **ESP32 Dev Module**, haciendo clic en **Herramientas** -> **Placa** -> **esp32**.

   .. image:: img/install_esp32_5.png
      :width: 100%

#. Si tu ESP32 está conectado a la computadora, puedes elegir el puerto correcto haciendo clic en **Herramientas** -> **Puerto**.

   .. image:: img/install_esp32_6.png
      :width: 100%

#. Además, Arduino 2.0 introdujo una nueva forma de seleccionar rápidamente la placa y el puerto. Para el ESP32, generalmente no se reconoce automáticamente, por lo que necesitas hacer clic en **Seleccionar otra placa y puerto**.

   .. image:: img/install_esp32_7.png
      :width: 80%

#. En el cuadro de búsqueda, escribe **ESP32 Dev Module** y selecciónalo cuando aparezca. Luego, elige el puerto correcto y haz clic en **OK**.

   .. image:: img/install_esp32_8.png
      :width: 90%

#. Posteriormente, puedes seleccionarlo a través de esta ventana de acceso rápido. Ten en cuenta que durante el uso posterior, puede haber ocasiones en las que el ESP32 no esté disponible en la ventana de acceso rápido, y necesitarás repetir los dos pasos anteriores.

   .. image:: img/install_esp32_9.png
      :width: 80%

#. Ambos métodos te permiten seleccionar la placa y el puerto correctos, así que elige el que más te convenga. Ahora, todo está listo para subir el código al ESP32.




