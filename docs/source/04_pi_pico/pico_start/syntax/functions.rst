.. note::

    こんにちは、SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts Communityへようこそ！Facebook上で、仲間と一緒にRaspberry Pi、Arduino、ESP32をさらに深く探求しましょう。

    **なぜ参加するのか？**

    - **専門的なサポート**：購入後の問題や技術的な課題をコミュニティやチームの助けを借りて解決。
    - **学びと共有**：スキルを向上させるためのヒントやチュートリアルを交換。
    - **限定プレビュー**：新製品発表や予告編に早期アクセス。
    - **特別割引**：最新製品の特別割引を楽しむ。
    - **フェスティブプロモーションとプレゼント**：プレゼントやホリデープロモーションに参加。

    👉 私たちと一緒に探索と創造を始める準備はできましたか？[|link_sf_facebook|]をクリックして、今すぐ参加しましょう！

関数
========

MicroPythonでは、関数は特定のタスクを実行する関連ステートメントのグループです。

関数はプログラムを小さなモジュール化されたブロックに分割するのに役立ちます。プログラムが大きくなるにつれて、関数を使用することでより整理され、管理しやすくなります。

さらに、コードの重複を避け、再利用可能にします。

関数の作成
------------

.. code-block:: python

    def function_name(parameters): 
        """docstring"""
        statement(s)

* 関数は``def``キーワードを使用して定義されます。

* 関数名は関数を一意に識別します。関数名の命名規則は変数名の命名規則と同じで、次のルールに従います。
    
   * 数字、文字、アンダースコアのみを含むことができます。
   * 最初の文字は文字またはアンダースコアでなければなりません。
   * 大文字と小文字を区別します。

* パラメータ（引数）は、関数に値を渡すために使用されます。これらはオプションです。

* コロン（:）は関数ヘッダーの終わりを示します。

* 関数の機能を説明するためのオプションのdocstring。通常、docstringを複数行に拡張できるようにトリプルクォートを使用します。

* 関数本体を構成する1つ以上の有効なMicroPythonステートメント。ステートメントは同じインデントレベル（通常は4つのスペース）でなければなりません。

* 各関数には少なくとも1つのステートメントが必要ですが、何らかの理由でステートメントを含まない関数がある場合は、エラーを避けるためにpassステートメントを入れてください。

* 関数から値を返すためのオプションの``return``ステートメント。


関数の呼び出し
----------------

関数を呼び出すには、関数名の後に括弧を追加します。

.. code-block:: python

    def my_function():
        print("Your first function")

    my_function()

>>> %Run -c $EDITOR_CONTENT
Your first function

returnステートメント
----------------------

returnステートメントは、関数を終了し、呼び出された場所に戻るために使用されます。

**returnの構文**

.. code-block:: python

    return [expression_list]

ステートメントには、評価されて値を返す式を含めることができます。ステートメントに式がない場合、または関数内に ``return`` ステートメント自体が存在しない場合、関数は ``None`` オブジェクトを返します。

.. code-block:: python

    def my_function():
        print("Your first function")

    print(my_function())

>>> %Run -c $EDITOR_CONTENT
Your first function
None

ここでは、 ``None`` が返される値です。これは ``return`` ステートメントが使用されていないためです。

引数
--------

情報は引数として関数に渡すことができます。

関数名の後に括弧で引数を指定します。必要なだけ多くの引数を追加でき、それらをコンマで区切ります。

.. code-block:: python

    def welcome(name, msg):
        """This is a welcome function for
        the person with the provided message"""
        print("Hello", name + ', ' + msg)

    welcome("Lily", "Welcome to China!")

>>> %Run -c $EDITOR_CONTENT
Hello Lily, Welcome to China!

引数の数
----------

デフォルトでは、関数は正しい数の引数で呼び出されなければなりません。つまり、関数が2つのパラメータを期待する場合、その関数を2つの引数で呼び出す必要があり、それ以上でも以下でもありません。

.. code-block:: python

    def welcome(name, msg):
        """This is a welcome function for
        the person with the provided message"""
        print("Hello", name + ', ' + msg)

    welcome("Lily", "Welcome to China!")

ここでは、関数welcome()には2つのパラメータがあります。

この関数を2つの引数で呼び出したため、関数はエラーなしにスムーズに実行されます。

異なる数の引数で呼び出されると、インタプリタはエラーメッセージを表示します。

以下は、この関数の呼び出しで、1つの引数と引数なしの例およびそれぞれのエラーメッセージです。

.. code-block:: 

    welcome("Lily")＃Only one argument

>>> %Run -c $EDITOR_CONTENT
Traceback (most recent call last):
  File "<stdin>", line 6, in <module>
TypeError: function takes 2 positional arguments but 1 were given

.. code-block::

    welcome()＃No arguments

>>> %Run -c $EDITOR_CONTENT
Traceback (most recent call last):
  File "<stdin>", line 6, in <module>
TypeError: function takes 2 positional arguments but 0 were given


デフォルト引数
*************************

MicroPythonでは、代入演算子（=）を使用して、パラメータにデフォルト値を提供することができます。

引数なしで関数を呼び出すと、デフォルト値が使用されます。



.. code-block:: python

    def welcome(name, msg = "Welcome to China!"):
        """This is a welcome function for
        the person with the provided message"""
        print("Hello", name + ', ' + msg)
    welcome("Lily")

>>> %Run -c $EDITOR_CONTENT
Hello Lily, Welcome to China!

この関数では、パラメータ ``name`` にはデフォルト値がなく、呼び出し時に必須（必須）です。

一方、パラメータ ``msg`` のデフォルト値は「Welcome to China!」です。したがって、呼び出し時に省略可能です。値が提供されると、デフォルト値が上書きされます。

関数内の任意の数の引数にデフォルト値を設定できます。ただし、一度デフォルト引数がある場合、その右側のすべての引数にもデフォルト値が必要です。

これは、非デフォルト引数がデフォルト引数の後に続くことはできないことを意味します。

たとえば、上記の関数ヘッダーを次のように定義すると：

.. code-block:: python

    def welcome(name = "Lily", msg):

次のエラーメッセージが表示されます：

>>> %Run -c $EDITOR_CONTENT
Traceback (most recent call last):
  File "<stdin>", line 1, in <module>
SyntaxError: non-default argument follows default argument


キーワード引数
**************************

特定の値で関数を呼び出すと、これらの値は位置に基づいて引数に割り当てられます。

たとえば、上記の関数welcome()では、welcome("Lily", "Welcome to China")と呼び出した場合、値「Lily」は ``name`` に割り当てられ、同様に「Welcome to China」はパラメータ ``msg`` に割り当てられます。

MicroPythonでは、キーワード引数を使用して関数を呼び出すことができます。この方法で関数を呼び出すと、引数の順序（位置）を変更できます。

.. code-block:: python

    # keyword arguments
    welcome(name = "Lily",msg = "Welcome to China!")

    # keyword arguments (out of order)
    welcome(msg = "Welcome to China！",name = "Lily") 

    #1 positional, 1 keyword argument
    welcome("Lily", msg = "Welcome to China!")

ご覧のとおり、関数呼び出し中に位置引数とキーワード引数を混在させることができます。ただし、キーワード引数は位置引数の後に来なければならないことを覚えておく必要があります。

キーワード引数の後に位置引数を置くとエラーが発生します。

たとえば、次のように関数を呼び出すと：

.. code-block:: python

    welcome(name="Lily","Welcome to China!")

エラーが発生します：

>>> %Run -c $EDITOR_CONTENT
Traceback (most recent call last):
  File "<stdin>", line 5, in <module>
SyntaxError: non-keyword arg after keyword arg


任意の引数
********************

場合によっては、関数に渡される引数の数が事前にわからないことがあります。

関数定義では、パラメータ名の前にアスタリスク（*）を追加することができます。

.. code-block:: python

    def welcome(*names):
        """This function welcomes all the person
        in the name tuple"""
        #names is a tuple with arguments
        for name in names:
            print("Welcome to China!", name)
            
    welcome("Lily","John","Wendy")

>>> %Run -c $EDITOR_CONTENT
Welcome to China! Lily
Welcome to China! John
Welcome to China! Wendy

ここでは、複数の引数を使用して関数を呼び出しました。これらの引数は関数に渡される前にタプルにまとめられます。

関数内では、forループを使用して全ての引数を取得します。

再帰
----------------
Pythonでは、関数が他の関数を呼び出すことができます。関数が自分自身を呼び出すことさえ可能です。このような構造は再帰関数と呼ばれます。

これにより、データをループして結果に到達することができます。

開発者は再帰を使用する際には非常に注意する必要があります。関数が終了しないものを書いたり、過剰なメモリやプロセッサーを消費するものを書いてしまうことが容易に起こり得ます。しかし、正しく書かれた場合、再帰は非常に効率的で数学的にエレガントなプログラミングアプローチとなります。

.. code-block:: python

    def rec_func(i):
        if(i > 0):
            result = i + rec_func(i - 1)
            print(result)
        else:
            result = 0
        return result

    rec_func(6)

>>> %Run -c $EDITOR_CONTENT
1
3
6
10
15
21

この例では、rec_func()は自分自身を呼び出す関数です（「再帰」）。データとして変数 ``i`` を使用し、再帰ごとに減少（-1）します。条件が0より大きくない場合（つまり、0）、再帰は終了します。

新しい開発者にとっては、どのように機能するかを理解するのに時間がかかるかもしれません。最良の方法はテストと修正です。

**再帰の利点**

* 再帰関数はコードをクリーンでエレガントに見せます。
* 複雑なタスクを再帰を使用して単純なサブ問題に分解できます。
* シーケンス生成は、いくつかのネストされた反復を使用するよりも再帰を使用する方が簡単です。

**再帰の欠点**

* 再帰の背後にあるロジックは理解しにくい場合があります。
* 再帰呼び出しはメモリと時間を多く消費するため、コストがかかります（非効率的）。
* 再帰関数はデバッグが難しいです。

