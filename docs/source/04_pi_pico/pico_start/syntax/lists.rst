.. note::

    こんにちは、SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts Communityへようこそ！Facebook上で、仲間と一緒にRaspberry Pi、Arduino、ESP32をさらに深く探求しましょう。

    **なぜ参加するのか？**

    - **専門的なサポート**：購入後の問題や技術的な課題をコミュニティやチームの助けを借りて解決。
    - **学びと共有**：スキルを向上させるためのヒントやチュートリアルを交換。
    - **限定プレビュー**：新製品発表や予告編に早期アクセス。
    - **特別割引**：最新製品の特別割引を楽しむ。
    - **フェスティブプロモーションとプレゼント**：プレゼントやホリデープロモーションに参加。

    👉 私たちと一緒に探索と創造を始める準備はできましたか？[|link_sf_facebook|]をクリックして、今すぐ参加しましょう！

.. _syntax_list:

Lists
===================

Lists are used to store multiple items in a single variable, and are created using square brackets:

.. code-block:: python

    B_list = ["Blossom", "Bubbles","Buttercup"]
    print(B_list)


List items are changeable, ordered, and allow duplicate values.
The list items are indexed, with the first item having index [0], the second item having index [1], and so on.

.. code-block:: python

    C_list = ["Red", "Blue", "Green", "Blue"]
    print(C_list)            # duplicate
    print(C_list[0]) 
    print(C_list[1])         # ordered
    C_list[2] = "Purple"     # changeable
    print(C_list)

>>> %Run -c $EDITOR_CONTENT
['Red', 'Blue', 'Green', 'Blue']
Red
Blue
['Red', 'Blue', 'Purple', 'Blue']


A list can contain different data types:

.. code-block:: python

    A_list = ["Banana", 255, False, 3.14]
    print(A_list)

>>> %Run -c $EDITOR_CONTENT
['Banana', 255, False, 3.14]


List Length
------------------
To determine how many items are in the list, use the len() function.

.. code-block:: python

    A_list = ["Banana", 255, False, 3.14]
    print(len(A_list))

>>> %Run -c $EDITOR_CONTENT
4

Check List items
-----------------------

Print the second item of the list:

.. code-block:: python

    A_list = ["Banana", 255, False, 3.14]
    print(A_list[1])

>>> %Run -c $EDITOR_CONTENT
[255]

Print the last one item of the list:

.. code-block:: python

    A_list = ["Banana", 255, False, 3.14]
    print(A_list[-1])

>>> %Run -c $EDITOR_CONTENT
[3.14]

Print the second, third item:

.. code-block:: python

    A_list = ["Banana", 255, False, 3.14]
    print(A_list[1:3])

>>> %Run -c $EDITOR_CONTENT
[255, False]


Change List Items
----------------------
Change the second, third item:

.. code-block:: python

    A_list = ["Banana", 255, False, 3.14]
    A_list[1:3] = [True,"Orange"] 
    print(A_list)

>>> %Run -c $EDITOR_CONTENT
['Banana', True, 'Orange', 3.14]

Change the second value by replacing it with two values:

.. code-block:: python

    A_list = ["Banana", 255, False, 3.14]
    A_list[1:2] = [True,"Orange"] 
    print(A_list)

>>> %Run -c $EDITOR_CONTENT
['Banana', True, 'Orange', False, 3.14]


Add List Items
-------------------

Using the append() method to add an item:

.. code-block:: python

    C_list = ["Red", "Blue", "Green"]
    C_list.append("Orange")
    print(C_list)

>>> %Run -c $EDITOR_CONTENT
['Red', 'Blue', 'Green', 'Orange']

Insert an item as the second position:

.. code-block:: python

    C_list = ["Red", "Blue", "Green"]
    C_list.insert(1, "Orange")
    print(C_list)

>>> %Run -c $EDITOR_CONTENT
['Red', 'Orange', 'Blue', 'Green']



Remove List Items
-----------------------

The remove() method removes the specified item.

.. code-block:: python

    C_list = ["Red", "Blue", "Green"]
    C_list.remove("Blue")
    print(C_list)

>>> %Run -c $EDITOR_CONTENT
['Red', 'Green']

The pop() method removes the specified index. If you do not specify the index, the pop() method removes the last item.

.. code-block:: python

    A_list = ["Banana", 255, False, 3.14, True,"Orange"]
    A_list.pop(1)
    print(A_list)
    A_list.pop()
    print(A_list)

>>> %Run -c $EDITOR_CONTENT
255
['Banana', False, 3.14, True, 'Orange']
'Orange'
['Banana', False, 3.14, True]

The ``del`` keyword also removes the specified index:

.. code-block:: python

    C_list = ["Red", "Blue", "Green"]
    del C_list[1]
    print(C_list)

>>> %Run -c $EDITOR_CONTENT
['Red', 'Green']

The clear() method empties the list. The list still remains, but it has no content.

.. code-block:: python

    C_list = ["Red", "Blue", "Green"]
    C_list.clear()
    print(C_list)

>>> %Run -c $EDITOR_CONTENT
[]