/*Давайте рассмотрим еще пару примеров операторов. Программа, представленная в листинге 2.3, продолжает предыдущий пример, позволяя вводить значение во время выполнения. 
Для этого в ней используется объект сіп — аналог cout, но предназначенный для ввода. 
Кроме того, в программе продемонстрирован еще один способ использования универсального объекта cout.*/
// Листинг 2.3. getinfо.срр 
// getinfо.срр — ввод и вывод 
#include <iostream>
int main(void)
{
    using namespace std;
    int carrots;
    cout << "How many carrots do uoy have?" << endl;
    cin >> carrots;             // ввод C++
    cout << "Here are two more. ";
    carrots = carrots + 2;
    // следующая строка выполняет конкатенацию вывода 
    cout << "Now you have " << carrots << " carrots." << endl;
    return 0;
}

