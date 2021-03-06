/* Обстоятельства часто требуют от программ выполнения повторяющихся задач, таких как сложение элементов массивов один за другим или 20-кратная распечатка похвалы за продуктивность. 
Цикл for облегчает выполнение задач подобного рода. Давайте взглянем на цикл в листинге 5.1, посмотрим, что он делает, а затем разберемся, как он работает. 
Листинг 5.1. forloop.cpp */
// forloop.cpp -- представление цикла for 
#include <iostream>
int main(void)
{
    using namespace std;
    int i; // создание счетчика 
    // инициализация; проверка; обновление 
    for(i = 0; i < 5; i++)
    cout << "C++ know loops.\n";
    cout << "C++ knows when to stop.\n";
    return 0;
}