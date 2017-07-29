1.  Что такое класс? 
1.  Класс - это определяемый пользователем тип. Класс — это двигатель C++, предназначенный для трансляции абстракций в пользовательские типы. 
    Он комбинирует представление данных и методов для манипулирования этими данными в пределах одного аккуратного пакета. 
      
      class MyClass: public ParentClass // ParentClass — класс-предок, если таковой имеется
  {
      public: // модификатор доступа
             // элементы в этой секции доступны из любой части программы
          MyClass(); // конструктор
         ~MyClass(); // деструктор
      protected:
             // элементы в этой секции доступны из класса и его потомков
      private:
             // элементы в этой секции доступны только из класса; это область доступа по умолчанию
  };

  После своего создания класс считается полноценным типом данных и, следовательно экземпляры класса создаются следующим образом:
  MyClass myinstance;

  Обращение к членам класса:
  myinstance.classmember

  Уничтожается экземпляр класса, как и любая переменная, только в случае, если функция, в которой он был создан, завершила работу или если была принудительно освобождена динамическая память, 
  выделенная под класс.

2.  Каким образом класс обеспечивает абстракцию, инкапсуляцию и сокрытие данных? 
2.  
//..
    Aбстракция - в компьютерных вычислениях абстракция — это ключевой шаг в представлении информации в терминах ее интерфейса с пользователем. 
    Aбстракция - это придание объекту характеристик, которые чётко определяют его концептуальные границы, отличая от всех других объектов. 
Основная идея состоит в том, чтобы отделить способ использования составных объектов данных от деталей их реализации в виде более простых объектов, подобно тому, 
    как функциональная абстракция разделяет способ использования функции и деталей её реализации в терминах более примитивных функций, таким образом, 
    данные обрабатываются функцией высокого уровня с помощью вызова функций низкого уровня.
//..
//..
    Инкапсуляция - механизм языка, позволяющий ограничить доступ одних компонентов программы к другим
    языковая конструкция, позволяющая связать данные с методами, предназначенными для обработки этих данных.

    class A 
{
    public:
        int a, b;               // данные открытого интерфейса
        int ReturnSomething();  // метод открытого интерфейса
    private:
        int Aa, Ab;             // скрытые данные
        void Do_Something();    // скрытый метод
};
//..
2. Класс представляет операции, которые можно выполнять над объектом класса посредством открытого интерфейса методов класса; это абстракция. 
Класс может использовать закрытую видимость (по умолчанию) для данных-членов, а это означает, что доступ к данным может быть осуществлен только через функции члены; -это сокрытие данных. 
Детали реализации, такие как представление данных и код методов, скрыты; это инкапсуляция. 

3. Каково отношение между объектом и классом? 
Объект = экземпляр класса = объект, типом которого является какой-то класс = класс после инициализации = сущность в памяти, обладающая поведением, способная изменять своё состояние.
3.  Класс определяет тип, включая информацию о том, как он может быть использован. 
    Объект представляет собой переменную или другой объект данных, вроде созданного с помощью new, который создается и используется в соответствии с определением класса. 
Между классом и объектом существует такое же отношение, как и между стандартным типом и переменной этого типа. 

4. Чем отличаются функции-члены класса от данных-членов класса помимо того, что они — функции? 
4. Если вы создаете несколько объектов заданного класса, то каждый объект будет обладать пространством памяти для хранения собственного набора данных. 
Но все объекты используют один набор функций-членов. (Обычно методы являются открытыми public:, а данные-члены — закрытыми private:, однако это вопрос политики, а не требований к классам.) 

5. Определите класс для представления банковского счета. 
Данные-члены должны включать имя вкладчика, номер счета (используйте строку) и баланс. 
Функции члены должны позволять следующее: 
• создание объекта и его инициализация; 
• отображение имени вкладчика, номера счета и баланса; 
• добавление на счет суммы денег, переданной в аргументе; 
• снятие суммы денег, переданной в аргументе. 
Просто приведите объявление класса без реализации методов. 
(Возможность написать реализацию будет представлена в упражнении 1.) 

// класс для представления банковского счета
class Bank
{
    private:
        std::string name_contributor;   // имя вкладчика
        std::string account_number;     // номер счета (используйте строку)
        double balance;                 // баланс
    public:
        Bank(const std::string &client, const std::string &num, double bal = 0.0);  // создание объекта и его инициализация
        void show(void);                                                            // отображение имени вкладчика, номера счета и баланса
        void amount_adding(double cash);                                            // добавление на счет суммы денег, переданной в аргументе
        void amount_withdrawals(double cash);                                       // снятие суммы денег, переданной в аргументе
};

6. Когда вызываются конструкторы класса? Когда вызываются деструкторы? 
6. 
конструктор специальный блок инструкций, вызываемый при создании объекта.
Одна из ключевых особенностей ООП — инкапсуляция: внутренние поля объекта напрямую недоступны, и пользователь может работать с объектом только как с единым целым, через открытые (public) методы. 
Каждый метод, в идеале, должен быть устроен так, чтобы объект, находящийся в «допустимом» состоянии (то есть когда выполняется инвариант класса), после вызова метода также оказался в допустимом состоянии. 
И первая задача конструктора — перевести поля объекта в такое состояние.
Вторая задача — упростить пользование объектом. 
Объект — не «вещь в себе», ему часто приходится требовать какую-то информацию от других объектов: например, объект File, создаваясь, должен получить имя файла. 
Это можно сделать и через метод:
    File file;
    file.open("in.txt", File::omRead);
Но удобнее открытие файла сделать в конструкторе:
    File file("in.txt", File::omRead);

class Complex
{
 public:
  // Конструктор по умолчанию 
  // (в данном случае является также и конструктором преобразования)
  Complex(double i_re = 0, double i_im = 0)
      : re(i_re), im(i_im)
  {}

  // Конструктор копирования
  Complex(const Complex &obj)
  {
   re = obj.re;
   im = obj.im;
  }
  private:
    double re, im;
};
Дестру́ктор — специальный метод класса, служащий для деинициализации объекта (например освобождения памяти).
6. Конструктор класса вызывается при создании объекта этого класса или в случае явного обращения к конструктору. 
Деструктор класса вызывается после завершения работы с объектом. 

7. Напишите код конструктора для класса банковского счета, описанного в вопросе 5. 
//..
конструктор и деструктор, мы всегда объявляем в разделе public;
при объявлении конструктора, тип данных возвращаемого значения не указывается, в том числе — void!!!;
у деструктора также нет типа данных для возвращаемого значения, к тому же деструктору нельзя передавать никаких параметров;
имя класса и конструктора должно быть идентично;
имя деструктора идентично имени конструктора, но с приставкой ~;
В классе допустимо создавать несколько конструкторов, если это необходимо. 
Имена, согласно пункту 2 нашего списка, будут одинаковыми. Компилятор будет их различать по передаваемым параметрам (как при перегрузке функций). 
Если мы не передаем в конструктор параметры, он считается конструктором по умолчанию;
//..

// класс для представления банковского счета
class Bank
{
    private:
        std::string name_contributor;   // имя вкладчика
        std::string account_number;     // номер счета (используйте строку)
        double balance;                 // баланс
    public:
        Bank(const std::string &client, const std::string &num, double bal = 0.0);      // создание объекта и его инициализация
        Bank::Bank(const std::string &client, const std::string &num, double bal)       // конструктора для класса банковского счета
        {
            name_contributor = client;
            account_number = num;
            balance = bal;
        }
        void show(void);                                                                // отображение имени вкладчика, номера счета и баланса
        void amount_adding(double cash);                                                // добавление на счет суммы денег, переданной в аргументе
        void amount_withdrawals(double cash);                                           // снятие суммы денег, переданной в аргументе
};

8. Что такое конструктор по умолчанию? Каковы выгоды его применения? 
8. конструктор, который может быть вызван без аргументов.
В C++, стандарт описывает конструктор по умолчанию как конструктор, который может быть вызван без передачи аргументов 
(включая конструктор с параметрами, имеющими значение по умолчанию).
class MyClass
{
    public:
        MyClass();  // конструктор описан

    private:
        int x;
};

MyClass::MyClass() : x(100)  // конструктор определён
{}

int main()
{
    MyClass m;  // во время работы программы создаётся объект m И вызывается конструктор по умолчанию
}
8. Конструктор по умолчанию либо не имеет аргументов, либо имеет значения по умолчанию для всех аргументов. 
Наличие конструктора по умолчанию позволяет объявлять объекты без их инициализации, даже если уже определен инициализирующий конструктор. 
Он также позволяет объявлять массивы. 

10. Что такое this и *this? 
 this-> это указатель который указывает на адрес класса в котором он записан. после использования this не нужно создовать ссылку на класс.
#include <iostream>
using namespace std;
class Test
{
    private:
        int a,b,c;
    public:
        void set(int a, int b, int c)
        {
            this->a = a;
            this->b = b;
            this->c = c;
        }
        void get()
        {
            cout << "A = " << a << ", B = " << b << ", C = " << c << endl;
        }
};
int main()
{
    Test test;
    test.set(12, 23, 1);
    test.get();
    return 0;
}
10. Указатель this доступен методам класса. Он указывает на объект, который был использован для вызова метода. 
Таким образом, this является адресом объекта, a *this представляет сам объект. 

