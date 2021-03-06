/* Вспомните, что операция new с размещением позволяет задавать ячейки в памяти, используемые для распределения памяти. 
Операция new с размещением в контексте встроенных типов обсуждалась в главе 9. 
Использование new с размещением для объектов добавляет новые тонкости. 
В листинге 12.8 new с размещением используется наряду с обычной операцией new для выделения памяти под объекты. 
При этом определяется класс с интерактивным конструктором и деструктором, чтобы отслеживать хронологию создания и уничтожения объектов. 
Листинг 12.8. placenewl.срр */
// placenewl. срр -- операции new, new с размещением, но без delete 
#include <iostream>
#include <string>
#include <new>
using namespace std;
const int BUF = 512;
class JustTesting
{
    private:
        string words;
        int number;
    public:
        JustTesting(const string & s = "Just Testing", int n = 0)
        {
            words = s;
            number = n;
            cout << words << " constructed\n";
        }
        ~JustTesting()
        {
            cout << words << " destroyed\n";
        }
        void Show() const
        {
            cout << words << ", " << number << endl;
        }
};
int main()
{
    char *buffer = new char[BUF];       // получение блока памяти 
    JustTesting *pc1, *pc2;
    pc1 = new(buffer) JustTesting;      // размещение объекта в buffer 
    pc2 = new JustTesting("Heap1", 20); // размещение объекта в куче 
    cout << "Memory block addresses:\n" << "buffer:" << (void *) buffer << " heap: " << pc2 << endl; // вывод адресов памяти 
    cout << "Memory contents:\n";       // вывод содержимого памяти 
    cout << pc1 << ": ";
    pc1->Show();
    cout << pc2 << ": ";
    pc2->Show();
    JustTesting *pc3, *pc4;
    pc3 = new (buffer) JustTesting("Bad Idea", 6);
    pc4 = new JustTesting("Heap2", 10);
    cout << "Memory contents:\n";       // вывод содержимого памяти 
    cout << pc3 << ": ";
    pc3->Show();
    cout << pc4 << ": ";
    pc4->Show();
    delete pc2;                         // освобождение Heapl 
    delete pc4;                         // освобождение Неар2 
    delete [] buffer;                   // освобождение buffer 
    cout << "Done\n";
    return 0;
}
/*
В программе 12.8 используется операция new для создания буфера памяти объемом 512 байт. 
Затем с помощью new в куче создаются два объекта типа JustTesting, и операция new с размещением пытается создать в буфере памяти два объекта типа JustTesting. 
В завершение программа использует операцию delete для освобождения памяти, выделенной операцией new. 
Как обычно, форматирование и точные значения адресов памяти могут  
варьироваться от системы к системе. 
В листинге 12.8 имеется пара проблем с операцией new с размещением. 
Во-первых, при создании второго объекта new с размещением просто перезаписывает новый объект в то же место, которое уже использовано для первого объекта. 
Это не просто грубая ошибка, это также означает, что для первого объекта деструктор не вызывается. 
Конечно, такая ошибка выльется в реальные проблемы, если, например, класс использует динамическое распределение памяти для своих членов. 
Во-вторых, применение операции delete для указателей рс2 и рс4 автоматически вызывает деструкторы для двух объектов, на которые указывают рс2 и рс4. 
Но использование операции delete[] для buffer не приводит к вызову деструкторов для объектов, созданных с помощью new с размещением. 
Первый урок, который следует из этого примера — тот же, что и в главе 9. 
От вас зависит управление позициями памяти в буфере, который заполняется операцией new с размещением. 
*/