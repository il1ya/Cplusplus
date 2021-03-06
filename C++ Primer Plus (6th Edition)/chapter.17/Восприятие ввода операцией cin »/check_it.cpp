/*
Может случиться, что ввод не оправдает ожиданий программы. Например, предположим, что вы ввели Zcar вместо -123Z. 
В этом случае операция извлечения оставит значение переменной elevation без изменений и возвратит значение 0. 
(Точнее, оператор if или while оценивает объект if stream как false, если установлено состояние ошибки; подробнее мы рассмотрим это позднее в этой главе.) 
Возвращаемое значение false позволит программе проверить, отвечает ли ввод требованиям программы, как показано в листинге 17.11. 
Листинг 17.11. check_it.cpp 
*/
// check_it.cpp -- проверка допустимости ввода 
#include <iostream>

int main()
{
    using namespace std;
    cout << "Enter numbers: ";  // запрос на ввод чисел 
    int sum = 0;
    int input;
    while(cin >> input)
    {
        sum += input;
    }
    cout << "Last value entered = " << input << endl;   // вывод последнего введенного значения 
    cout << "Sum = " << sum << endl;                    // вывод суммы введенных чисел 
    return 0;
}
/*
Поскольку ввод буферизуется, вторая строка значений, введенных с клавиатуры, не посылается программе до тех пор, пока не будет нажата клавиша <Enter> в конце строки. 
Но цикл прекращает обработку на символе Z, потому что он не соответствует формату чисел с плавающей точкой. 
Несоответствие ввода ожидаемому формату, в свою очередь, приводит к тому, что выражение cin >> input оценивается как false, что прекращает выполнение цикла while. 
*/