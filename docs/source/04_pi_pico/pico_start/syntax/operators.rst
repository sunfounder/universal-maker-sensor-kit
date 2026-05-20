.. note:: 

    ¡Hola, bienvenido a la Comunidad de Entusiastas de SunFounder Raspberry Pi, Arduino y ESP32 en Facebook! Profundiza en Raspberry Pi, Arduino y ESP32 junto con otros entusiastas.

    **¿Por qué unirse?**

    - **Soporte Experto**: Resuelve problemas postventa y desafíos técnicos con la ayuda de nuestra comunidad y equipo.
    - **Aprender y Compartir**: Intercambia consejos y tutoriales para mejorar tus habilidades.
    - **Vistazos Exclusivos**: Accede de forma anticipada a los anuncios de nuevos productos y adelantos.
    - **Descuentos Especiales**: Disfruta de descuentos exclusivos en nuestros productos más recientes.
    - **Promociones Festivas y Sorteos**: Participa en sorteos y promociones especiales.

    👉 ¿Listo para explorar y crear con nosotros? Haz clic en [|link_sf_facebook|] y únete hoy mismo!

Operadores
============

Los operadores se utilizan para realizar operaciones sobre variables y valores.


Operadores Aritméticos
--------------------------

Puedes usar operadores aritméticos para realizar algunas operaciones matemáticas comunes.

.. list-table:: 
    :widths: 10 30
    :header-rows: 1

    *   - Operador
        - Nombre
    *   - ``+``
        - Suma
    *   - ``-``
        - Resta
    *   - ``*``
        - Multiplicación
    *   - ``/``
        - División
    *   - ``%``
        - Módulo
    *   - ``**``
        - Exponenciación
    *   - ``//``
        - División entera



.. code-block:: python

    x = 5
    y = 3

    a = x + y
    b = x - y
    c = x * y
    d = x / y
    e = x % y
    f = x ** y
    g = x // y

    print(a)
    print(b)
    print(c)
    print(d)
    print(e)
    print(f)
    print(g)

>>> %Run -c $EDITOR_CONTENT
8
2
15
1.666667
2
125
1
8
2
15
>>> 

Operadores de Asignación
----------------------------

Los operadores de asignación se utilizan para asignar valores a las variables.

.. list-table:: 
    :widths: 10 30 30
    :header-rows: 1

    *   - Operador
        - Ejemplo
        - Equivalente
    *   - ``=``
        - a = 6
        - a =6
    *   - ``+=``
        - a += 6
        - a = a + 6
    *   - ``-=``
        - a -= 6
        - a = a - 6
    *   - ``*=``
        - a \*= 6
        - a = a * 6
    *   - ``/=``
        - a /= 6
        - a = a / 6
    *   - ``%=``
        - a %= 6
        - a = a % 6
    *   - ``**=``
        - a \*\*= 6
        - a = a ** 6
    *   - ``//=``
        - a //= 6
        - a = a // 6
    *   - ``&=``
        - a &= 6
        - a = a & 6
    *   - ``|=``
        - a \|= 6
        - a = a | 6
    *   - ``^=``
        - a ^= 6
        - a = a ^ 6
    *   - ``>>=``
        - a >>= 6
        - a = a \>\> 6
    *   - ``<<=``
        - a <<= 6
        - a = a << 6



.. code-block:: python

    a = 6

    a *= 6
    print(a)

>>> %Run test.py
36
>>> 


Operadores de Comparación
--------------------------

Los operadores de comparación se utilizan para comparar dos valores.

.. list-table:: 
    :widths: 10 30
    :header-rows: 1

    *   - Operador
        - Nombre
    *   - ``==``
        - Igual
    *   - ``!=``
        - Diferente
    *   - ``<``
        - Menor que
    *   - ``>``
        - Mayor que
    *   - ``>=``
        - Mayor o igual que
    *   - ``<=``
        - Menor o igual que




.. code-block:: python

    a = 6
    b = 8

    print(a>b)

>>> %Run test.py
False
>>> 

Devuelve **False**, porque **a** es menor que **b**.

Operadores Lógicos
---------------------

Los operadores lógicos se utilizan para combinar sentencias condicionales.

.. list-table:: 
    :widths: 10 30
    :header-rows: 1

    *   - Operador
        - Descripción
    *   - ``and``
        - Devuelve True si ambas sentencias son verdaderas
    *   - ``or``
        - Devuelve True si una de las sentencias es verdadera
    *   - ``not``
        - Invierte el resultado, devuelve False si el resultado es verdadero

.. code-block:: python

    a = 6
    print(a > 2 and a < 8)

>>> %Run -c $EDITOR_CONTENT
True
>>>

Operadores de Identidad
-------------------------

Los operadores de identidad se utilizan para comparar los objetos, no si son iguales, sino si son realmente el mismo objeto, con la misma ubicación en memoria.

.. list-table:: 
    :widths: 10 30
    :header-rows: 1

    *   - Operador
        - Descripción
    *   - ``is``
        - Devuelve True si ambas variables son el mismo objeto
    *   - ``is not``
        - Devuelve True si ambas variables no son el mismo objeto

.. code-block:: python

    a = ["hello", "welcome"]
    b = ["hello", "welcome"]
    c = a

    print(a is c)
    # devuelve True porque c es el mismo objeto que a

    print(a is b)
    # devuelve False porque a no es el mismo objeto que b, aunque tengan el mismo contenido

    print(a == b)
    # devuelve True porque a es igual a b

>>> %Run -c $EDITOR_CONTENT
True
False
True
>>> 


Operadores de Membresía
-------------------------

Los operadores de membresía se utilizan para probar si una secuencia está presente en un objeto.

.. list-table:: 
    :widths: 10 30
    :header-rows: 1

    *   - Operador
        - Descripción
    *   - ``in``
        - Devuelve True si una secuencia con el valor especificado está presente en el objeto
    *   - ``not in``
        - Devuelve True si una secuencia con el valor especificado no está presente en el objeto

.. code-block:: python

    a = ["hello", "welcome", "Goodmorning"]

    print("welcome" in a)

>>> %Run -c $EDITOR_CONTENT
True
>>> 

Operadores a Nivel de Bits
-----------------------------

Los operadores a nivel de bits se utilizan para comparar números (binarios).

.. list-table:: 
    :widths: 10 20 50
    :header-rows: 1

    *   - Operador
        - Nombre
        - Descripción
    *   - ``&``
        - AND
        - Establece cada bit en 1 si ambos bits son 1
    *   - ``|``
        - OR
        - Establece cada bit en 1 si uno de los dos bits es 1
    *   - ``^``
        - XOR
        - Establece cada bit en 1 si solo uno de los dos bits es 1
    *   - ``~``
        - NOT
        - Invierte todos los bits
    *   - ``<<``
        - Desplazamiento a la izquierda con relleno de ceros
        - Desplaza hacia la izquierda introduciendo ceros desde la derecha y dejando que los bits más a la izquierda caigan
    *   - ``>>``
        - Desplazamiento a la derecha con signo
        - Desplaza hacia la derecha copiando los bits más a la izquierda desde la izquierda, y dejando que los bits más a la derecha caigan

.. code-block:: python

    num = 2

    print(num & 1)
    print(num | 1)
    print(num << 1)

>>> %Run -c $EDITOR_CONTENT
0
3
4
>>>