/*
В некоторых обстоятельствах можно заставить компилятор сделать необходимый вам выбор, правильно написав вызов функции. 
Взгляните на листинг 8.15, в котором, кстати, устранен прототип шаблона, а определение шаблонной функции помещено в начало файла. 
Как и в случае обычных функций, определение шаблонной функции может действовать в качестве своего прототипа, если оно находится перед использованием функции. 
Листинг 8.15. choices.cрр */
// choices.cрр — выбор шаблона 
#include <iostream>
template<class T> // или template <typename T> 
T lesser(T a, T b) // #1
{
    return a < b ? a : b;
}
int lesser(int a, int b) // #2
{
    a = a < 0 ? -a : a;
    b = b < 0 ? -b : b;
    return a < b ? a : b;
}

int main(void)
{
    using namespace std;
    int m = 20;
    int n = -30;
    double x = 15.5;
    double y = 25.9;

    cout << lesser(m, n) << endl;   // используется #2 
    cout << lesser(x, y) << endl;   // используется #1 с double 
    cout << lesser<>(m, n) << endl; // используется #1 с int 
    cout << lesser<int>(x, y) << endl; // используется #1 с int 
    return 0;
}
/*
(В последнем вызове функции выполняется преобразование double в int, и некоторые компиляторы выдают предупреждение об этом.) 
Ниже показан вывод программы из листинга 8.15: 
20 
15.5 
-30 
15 
В листинге 8.15 предоставлен шаблон, который возвращает меньшее из двух значений, и стандартная функция, возвращающая меньший модуль из двух значений. 
Если определение функции находится перед ее первым использованием, оно действует как прототип, так что в этом примере прототипы опущены. 
Рассмотрим следующий оператор: 
cout « lesser(m, n) << endl; // используется #2 
Аргументы в этом вызове соответствуют как шаблонной функции, так и нешаблонной функции, поэтому выбирается нешаблонная функция, которая возвращает значение 20. 
Следующий вызов функции соответствует шаблону, при этом т становится double: 
cout « lesser(x, у) << endl; // используется #1 с double 
Теперь взгляните на такой оператор: 
cout << lessero (m, n) << endl; // используется #1 с int 
Наличие угловых скобок в lessero(m, n) указывает, что компилятор должен выбрать шаблонную функцию вместо нешаблонной, и компилятор, отметив, что  
фактические аргументы имеют тип int, создает экземпляр шаблона с использованием int для т. 
Наконец, рассмотрим следующий оператор: 
cout << lesser<int>(x, у) « endl; // используется #1 с int 
Здесь мы имеем запрос на явное создание экземпляра с применением int для Т, и эта функция будет использоваться. Значения х и у приводятся к типу int, и функция 
возвращает значение int, из-за чего программа отображает 15 вместо 15.5. 
*/