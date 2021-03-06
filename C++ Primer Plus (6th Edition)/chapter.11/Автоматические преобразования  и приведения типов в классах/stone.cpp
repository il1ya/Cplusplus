/* Однако это двухшаговое преобразование работает только в том случае, когда выбор однозначен. 
То есть, если у класса также определен конструктор Stonewt (long), то компилятор отклонит эти выражения, возможно, указав, что int может быть  
преобразован и в double, и в long, поэтому такой вызов неоднозначен. 
Код в листинге 11.18 использует два конструктора для инициализации объектов Stonewt и управления преобразованием типов. 
Обеспечьте совместную компиляцию кода в листингах 11.17 и 11.18. 
Листинг 11.18. stone.срр */
// stone.срр — определенные пользователем преобразования 
// Компилировать вместе с stonewt.срр 
#include <iostream>
using std::cout;
#include "stonewt.h"
void display(const Stonewt & st, int n);
int main()
{
    Stonewt incognito = 275;    // использование конструктора для инициализации 
    Stonewt wolfe(285.7);       // то же, что и Stonewt wolfe = 285.7; 
    Stonewt taft(21, 8);
    
    cout << "The celebrity weighed ";
    incognito.show_stn();
    cout << "The detective weighed ";
    wolfe.show_stn();
    cout << "The President weighed ";
    taft.show_lbs();
    incognito = 276.8;          // использование конструктора для преобразования 
    taft = 325;                 // то же, что и taft = Stonewt (325);
    cout << "After dinner, the celebrity weighed ";
    incognito.show_stn();
    cout << "After dinner, the President weighed ";
    taft.show_lbs();
    display(taft, 2);
    cout << "The wrestler weighed evem more.\n";
    display(422, 2);
    cout << "No stone left unearned\n";
    return 0; 
}
void display(const Stonewt & st, int n)
{
    for(int i = 0; i < n; i++)
    {
        cout << "Wow! ";
        st.show_stn();
    }
}
/*
Замечания по программе 
Обратите внимание, что когда конструктор принимает единственный аргумент, можно использовать следующую форму инициализации объекта класса: 
// Синтаксис для инициализации объекта класса 
// при использовании конструктора с одним аргументом 
    Stonewt incognito = 275; 
Это эквивалентно следующим двум формам, которые были показаны ранее: 
// Стандартные формы синтаксиса для инициализации объектов 
Stonewt incognito (275); 
Stonewt incognito = Stonewt(275); 
Однако последние две формы могут применяться с конструкторами, принимающими несколько аргументов. 
Далее отметим следующие два присваивания из листинга 11.18: 
    incognito = 276.8; 
    taft = 325; 
Первое из двух присваиваний использует конструктор с аргументом типа double для преобразования 276.8 в значение типа Stonewt. 
При этом члену pounds объекта incognito присваивается значение 276.8. 
Поскольку здесь применяется конструктор, такое присваивание также устанавливает значение членов stone и pds_lef t класса. 
Аналогично, второе присваивание преобразует значение типа int в тип double и затем использует Stonewt (double) для установки значений всех трех членов класса. 
И, наконец, обратим внимание на следующий вызов функции: 
    display (422, 2); // преобразует 422 в double, затем в Stonewt 
Прототип функции display() указывает на то, что первый аргумент должен быть объектом типа Stonewt. 
(Аргументу Stonewt соответствует формальный параметр Stonewt или Stonewt &.) 
Обнаружив аргумент типа int, компилятор ищет конструктор Stonewt(int) для преобразования аргумента int в тип Stonewt. 
He найдя его, компилятор ищет конструктор с аргументом другого встроенного типа, который можно преобразовать в int. Конструктор Stonewt (double) подходит. 
Поэтому компилятор преобразует int в double и затем использует Stonewt (double) для преобразования результата в объект Stonewt. 
*/