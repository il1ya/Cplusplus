/*
Поскольку каждое значение отображается в поле, ширина которого равна его размеру, необходимо побеспокоиться о явном указании пробелов между значениями. 
В противном случае соседние значения сольются. 
Установки вывода по умолчанию иллюстрируются в листинге 17.2. Приведенный в нем код отображает двоеточие (:) после каждого значения, чтобы можно было видеть ширину поля, используемую в каждом случае. 
В программе применяется выражение 1.0 / 9.0 для генерации бесконечной дроби, чтобы продемонстрировать количество выводимых разрядов. 
Листинг 17.2. defaults.срр 
*/
// defaults.срр -- форматы по умолчанию cout 
#include <iostream>
int main()
{
    using std::cout;
    cout << "12345678901234567890\n";
    char ch = 'K';
    int t = 273;
    cout << ch << ":\n";
    cout << t << ":\n";
    cout << -t << ":\n";

    double f1 = 1.200;
    cout << f1 << ":\n";
    cout << (f1 + 1.0 / 9.0) << ":\n";
    double f2 = 1.67E2;
    cout << f2 << ":\n";

    f2 += 1.0 / 9.0;
    cout << f2 << ":\n";
    cout << (f2 * 1.0e4) << ":\n";
    double f3 = 2.3e-4;
    cout << f3 << ":\n";
    cout << f3 / 10 << ":\n";
    
    return 0;
}
/*
Каждое значение заполняет свое поле. Обратите внимание, что завершающие нули в значении 1.200 не отображаются, но значения с плавающей точкой без завершающих нулей отображаются с шестью знаками. 
Кроме того, данная конкретная реализация отображает три разряда в экспоненте; другие могут использовать только два. 
*/