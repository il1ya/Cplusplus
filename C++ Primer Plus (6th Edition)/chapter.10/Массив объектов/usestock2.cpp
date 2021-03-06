/*
В листинге 10.9 эти принципы применяются в короткой программе, которая  инициализирует четыре элемента массива, отображает их содержимое и проверяет элементы в поисках того, который имеет наибольшее значение totalval. 
Поскольку total() сравнивает только два объекта за раз, для просмотра всего массива в программе используется цикл for. 
Для отслеживания элемента с наибольшим значением totalval применяется указатель на Stock. 
Код в этом листинге использует заголовочный файл из листинга 10.7 и файл методов из листинга 10.8. 
Листинг 10.9. usestock2.срр */
// usestok2.срр — использование класса Stock 
// Компилировать вместе с stock20.cpp 
#include <iostream>
#include "stock20.h"
const int STKS = 4;
int main()
{
    // Создание массива инициализированных объектов 
    Stock stocks[STKS] = 
    {
        Stock("Kate", 1112, 20.0),
        Stock("joe", 200, 2.0),
        Stock("Tim", 130, 3.25),
        Stock("illya", 130, 6.5),
    };
    std::cout << "Stock holdings:\n";
    int st;
    for(st = 0; st < STKS; st++)
        stocks[st].show();

    // Установка указателя н первый элемент 
    const Stock *top = &stocks[0];
    for(st = 1; st < STKS; st++)
        top = &top->topval(stocks[st]);

    // Теперь top указывает на самый ценный пакет акций 
    std::cout << "\nMost valuable holding:\n";
    top->show();
    return 0;
}