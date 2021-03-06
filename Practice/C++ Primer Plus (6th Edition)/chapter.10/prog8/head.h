/* 8. 
Простой список можно описать следующим образом: 
• простой список может содержать ноль или более элементов определенного типа; 
• можно создавать пустой список; 
• можно добавлять элемент в список; 
• можно определять, пуст ли список; 
• можно определять, полон ли список. 
• можно посетить каждый элемент списка и выполнить над ним определенное действие. 
Как видите, список действительно прост; так, например, он не позволяет осуществлять вставку или удаление элементов. 
Спроектируйте класс List для представления этого абстрактного типа. 
Вы должны подготовить заголовочный файл list.h с объявлением класса и файл list.cpp с реализацией его методов. 
Вы должны также написать короткую программу, которая будет использовать полученный класс. 
Главная причина того, что спецификация списка проста, связана с попыткой упростить это упражнение. 
Вы можете реализовать список в виде массива или же в виде связного списка, если знакомы с этим типом данных. 
Однако открытый интерфейс не должен зависеть от вашего выбора. 
То есть открытый интерфейс не должен иметь индексов массива, указателей на узлы и т.п. 
Он должен быть выражен в виде общих концепций создания списка, добавления элемента в список и т.д. 
*/
#include <iostream>
#include <string>
using std::cout;
using std::cin;
using std::endl;
struct customer
{
    std::string fullname;
    double payment;
};

typedef struct customer Item;

class List
{
    private:
        enum {MAX = 10};   // константа, специфичная для класса 
        Item stack_[MAX];  // хранит элементы стека 
        int top_;          // индекс вершины стека 
    public:
        List();
        bool isempty() const;
        bool isfull() const;
        void showList() const;
        bool add(const Item &item);
        void changeName(const int id);
        void changeVol(const int id);
        void showItem(const int id);

};