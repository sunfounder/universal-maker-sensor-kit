.. note::

    こんにちは、SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts Communityへようこそ！Facebook上で、仲間と一緒にRaspberry Pi、Arduino、ESP32をさらに深く探求しましょう。

    **なぜ参加するのか？**

    - **専門的なサポート**：購入後の問題や技術的な課題をコミュニティやチームの助けを借りて解決。
    - **学びと共有**：スキルを向上させるためのヒントやチュートリアルを交換。
    - **限定プレビュー**：新製品発表や予告編に早期アクセス。
    - **特別割引**：最新製品の特別割引を楽しむ。
    - **フェスティブプロモーションとプレゼント**：プレゼントやホリデープロモーションに参加。

    👉 私たちと一緒に探索と創造を始める準備はできましたか？[|link_sf_facebook|]をクリックして、今すぐ参加しましょう！

Data Types
===========

Built-in Data Types
---------------------
MicroPython has the following data types:

* Text Type: str
* Numeric Types: int, float, complex
* Sequence Types: list, tuple, range
* Mapping Type: dict
* Set Types: set, frozenset
* Boolean Type: bool
* Binary Types: bytes, bytearray, memoryview

Getting the Data Type
-----------------------------
You can get the data type of any object by using the ``type()`` function:



.. code-block:: python

    a = 6.8
    print(type(a))

>>> %Run -c $EDITOR_CONTENT
<class 'float'>

Setting the Data Type
----------------------
MicroPython does not need to set the data type specifically, it has been determined when you assign a value to the variable.



.. code-block:: python

    x = "welcome"
    y = 45
    z = ["apple", "banana", "cherry"]

    print(type(x))
    print(type(y))
    print(type(z))

>>> %Run -c $EDITOR_CONTENT
<class 'str'>
<class 'int'>
<class 'list'>
>>> 

Setting the Specific Data Type
----------------------------------

If you want to specify the data type, you can use the following constructor functions:

.. list-table:: 
    :widths: 25 10
    :header-rows: 1

    *   - Example
        - Date Type
    *   - x = int(20)
        - int
    *   - x = float(20.5)
        - float
    *   - x = complex(1j)
        - complex
    *   - x = str("Hello World")
        - str
    *   - x = list(("apple", "banana", "cherry"))
        - list
    *   - x = tuple(("apple", "banana", "cherry"))
        - tuple
    *   - x = range(6)
        - range
    *   - x = dict(name="John", age=36)
        - dict
    *   - x = set(("apple", "banana", "cherry"))
        - set
    *   - x = frozenset(("apple", "banana", "cherry"))
        - frozenset
    *   - x = bool(5)
        - bool
    *   - x = bytes(5)
        - bytes
    *   - x = bytearray(5)
        - bytearray
    *   - x = memoryview(bytes(5))
        - memoryview

You can print some of them to see the result.



.. code-block:: python

    a = float(20.5)
    b = list(("apple", "banana", "cherry"))
    c = bool(5)

    print(a)
    print(b)
    print(c)

>>> %Run -c $EDITOR_CONTENT
20.5
['apple', 'banana', 'cherry']
True
>>> 

Type Conversion
----------------
You can convert from one type to another with the int(), float(), and complex() methods:
Casting in python is therefore done using constructor functions:

* int() - constructs an integer number from an integer literal, a float literal (by removing all decimals), or a string literal (providing the string represents a whole number)
* float() - constructs a float number from an integer literal, a float literal or a string literal (providing the string represents a float or an integer)
* str() - constructs a string from a wide variety of data types, including strings, integer literals and float literals



.. code-block:: python

    a = float("5")
    b = int(3.7)
    c = str(6.0)

    print(a)
    print(b)
    print(c)

Note: You cannot convert complex numbers into another number type.