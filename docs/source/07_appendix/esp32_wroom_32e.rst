.. note:: 

    ¡Hola, bienvenido a la Comunidad de Entusiastas de SunFounder Raspberry Pi, Arduino y ESP32 en Facebook! Profundiza más en Raspberry Pi, Arduino y ESP32 junto con otros entusiastas.

    **¿Por qué unirte?**

    - **Soporte experto**: Resuelve problemas postventa y desafíos técnicos con la ayuda de nuestra comunidad y equipo.
    - **Aprender y compartir**: Intercambia consejos y tutoriales para mejorar tus habilidades.
    - **Preestrenos exclusivos**: Obtén acceso anticipado a nuevos anuncios de productos y adelantos.
    - **Descuentos especiales**: Disfruta de descuentos exclusivos en nuestros productos más recientes.
    - **Promociones festivas y sorteos**: Participa en sorteos y promociones de temporada.

    👉 ¿Listo para explorar y crear con nosotros? Haz clic en [|link_sf_facebook|] y únete hoy mismo!

.. _cpn_esp32_wroom_32e:

Placa ESP32
=================

El ESP32 es un microcontrolador potente y versátil que cuenta con procesamiento de doble núcleo, Wi-Fi y Bluetooth integrados, y un amplio soporte de periféricos. Su diseño de bajo consumo lo hace ideal para aplicaciones IoT compactas y de alto rendimiento.

.. image:: img/esp32_board.png
    :align: center


Las características principales incluyen:

* **Potencia de Procesamiento**: Está equipado con un microprocesador Xtensa® LX6 de 32 bits y doble núcleo, que ofrece escalabilidad y flexibilidad.
* **Capacidades Inalámbricas**: Con Wi-Fi integrado de 2.4 GHz y Bluetooth de modo dual, es ideal para aplicaciones que requieren comunicación inalámbrica estable.
* **Memoria y Almacenamiento**: Incluye abundante SRAM y almacenamiento flash de alto rendimiento para programas de usuario y almacenamiento de datos.
* **GPIO**: Ofrece hasta 38 pines GPIO, compatibles con una gran variedad de dispositivos y sensores externos.
* **Bajo Consumo de Energía**: Dispone de múltiples modos de ahorro de energía, ideales para aplicaciones alimentadas por batería o de alta eficiencia energética.
* **Seguridad**: Las funciones integradas de cifrado y seguridad garantizan la protección de los datos y la privacidad del usuario.
* **Versatilidad**: Desde simples electrodomésticos hasta maquinaria industrial compleja, la placa ofrece un rendimiento constante y eficiente.

En resumen, la placa ESP32 no solo ofrece potentes capacidades de procesamiento y diversas opciones de conectividad, sino también una amplia variedad de funciones que la convierten en una opción preferida en los sectores de IoT y dispositivos inteligentes.

.. * |link_esp32_datasheet|

.. _esp32_pinout:

Diagrama de Pines
-------------------------

El ESP32 tiene algunas limitaciones en el uso de pines debido a que varias funciones comparten ciertos pines. Al diseñar un proyecto, es recomendable planificar cuidadosamente el uso de los pines y verificar posibles conflictos para asegurar un funcionamiento correcto y evitar problemas.


.. image:: img/esp32_pinout.jpg
    :width: 800
    :align: center

Estas son algunas de las principales restricciones y consideraciones:

* **ADC1 y ADC2**: ADC2 no puede utilizarse cuando WiFi o Bluetooth están activos. Sin embargo, ADC1 puede utilizarse sin restricciones.
* **Pines de Arranque (Bootstrapping)**: GPIO0, GPIO2, GPIO5, GPIO12 y GPIO15 se utilizan durante el proceso de arranque. Debe evitarse conectar componentes externos que puedan interferir con el proceso de arranque en estos pines.
* **Pines JTAG**: GPIO12, GPIO13, GPIO14 y GPIO15 pueden utilizarse como pines JTAG para depuración. Si no se requiere depuración JTAG, estos pines pueden utilizarse como GPIO normales.
* **Pines Táctiles**: Algunos pines admiten funciones táctiles. Estos deben utilizarse cuidadosamente si se pretende usarlos para detección táctil.
* **Pines de Alimentación**: Algunos pines están reservados para funciones relacionadas con la alimentación y deben utilizarse adecuadamente. Por ejemplo, evite extraer corriente excesiva de pines como 3V3 y GND.
* **Pines Solo de Entrada**: Algunos pines son solo de entrada y no deben utilizarse como salidas.

.. _esp32_strapping:

**Pines de Configuración de Arranque**
--------------------------------------------------

El ESP32 tiene cinco pines de configuración de arranque:

.. list-table::
    :widths: 5 15
    :header-rows: 1

    *   - Pines de Configuración
        - Descripción
    *   - IO5
        - Tiene pull-up por defecto; el nivel de voltaje de IO5 e IO15 afecta la sincronización del esclavo SDIO.
    *   - IO0
        - Tiene pull-up por defecto; si se mantiene en nivel bajo, entra en modo de descarga.
    *   - IO2
        - Tiene pull-down por defecto; IO0 e IO2 harán que el ESP32 entre en modo de descarga.
    *   - IO12(MTDI)
        - Tiene pull-down por defecto; si se mantiene en nivel alto, el ESP32 no arrancará normalmente.
    *   - IO15(MTDO)
        - Tiene pull-up por defecto; si se mantiene en nivel bajo, el registro de depuración no será visible. Además, el nivel de voltaje de IO5 e IO15 afecta la sincronización del esclavo SDIO.


El software puede leer los valores de estos cinco bits desde el registro "GPIO_STRAPPING".
Durante la liberación del reinicio del sistema del chip (encendido, reinicio por watchdog RTC y reinicio por caída de voltaje), los pines de configuración muestrean el nivel de voltaje como bits de configuración "0" o "1", y mantienen estos bits hasta que el chip se apaga o se desconecta de la alimentación. Estos bits configuran el modo de arranque del dispositivo, el voltaje de funcionamiento de VDD_SDIO y otros ajustes iniciales del sistema.

Cada pin de configuración está conectado internamente a una resistencia pull-up o pull-down durante el reinicio del chip. Por lo tanto, si un pin de configuración está desconectado o el circuito externo conectado tiene alta impedancia, la resistencia interna determinará el nivel lógico predeterminado del pin.

Para cambiar los valores de estos bits de configuración, los usuarios pueden aplicar resistencias externas pull-up/pull-down o utilizar los GPIO del MCU anfitrión para controlar el nivel de voltaje de estos pines al encender el ESP32.

Después de la liberación del reinicio, los pines de configuración funcionan como pines normales.
Consulte la siguiente tabla para ver la configuración detallada del modo de arranque mediante estos pines.

.. image:: img/esp32_strapping.png

* FE: flanco descendente, RE: flanco ascendente
* El firmware puede configurar bits de registro para cambiar los ajustes de "Voltaje del LDO Interno (VDD_SDIO)" y la "Sincronización del Esclavo SDIO" después del arranque.
* El módulo integra una memoria flash SPI de 3.3 V, por lo que el pin MTDI no puede configurarse en 1 cuando el módulo se enciende.