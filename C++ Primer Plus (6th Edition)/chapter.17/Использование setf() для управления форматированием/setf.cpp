/*
Тип bitmask (битовая маска) предназначен для хранения значений индивидуальных битов. 
Он может быть целочисленным, перечислением епшп или контейнером bitset из STL Главная идея в том, что каждый бит доступен индивидуально и имеет собственный смысл. 
Пакет iostream использует типы битовых масок для хранения информации о состоянии потока. 
Поскольку эти константы форматирования определены в классе iosbase, с ними должна применяться операция разрешения контекста. 
То есть нужно использовать ios_base::uppercase, а не просто uppercase. В отсутствие директивы using или объявления using потребуется применять операцию разрешения контекста, указывая, что 
эти имена принадлежат пространству имен std, т.е. std: :ios_base::showpos и т.д. 
Изменения остаются в силе до тех пор, пока не будут переопределены. Применение некоторых из этих констант демонстрируется в листинге 17.8. 
Листинг 17.8. setf.срр */
// setf.срр — использование setf() для управления форматированием 

#include <iostream>

int main()
{
    using std::cout;
    using std::endl;
    using std::ios_base;

    int temperature = 63;

    cout << "Today's water temperature: ";
    cout.setf(ios_base::showpos);               // показывать знак плюс 
    cout << temperature << endl;

    cout << "For out programming friends, that's\n"; 
    cout << std::hex << temperature << endl;    // использование шестнадцатеричного представления 
    cout.setf(ios_base::uppercase);             // применение прописных символов в шестнадцатеричном представлении 

    cout.setf(ios_base::showbase);              // использование префикса ОХ для шестнадцатеричных значений 

    cout << "or\n";
    cout << temperature << endl;
    cout << "How " << true << "! oops -- How ";
    cout.setf(ios_base::boolalpha);
    cout << true << "!\n";

    return 0;
}
/*
Обратите внимание, что знак "плюс" используется только с версией десятичного представления. C++ обрабатывает шестнадцатеричные и восьмеричные значения как значения без знака; 
поэтому для них никакой знак не требуется. (Однако некоторые реализации C++ могут все же отображать знак плюса.) 
Второй прототип setf() принимает два аргумента и возвращает предыдущие установки: 
fmtflags setf(fmtflags , fmtflags); 
Эта перегруженная форма функции используется для форматирования нюансов отображения, которые управляются более чем одним битом. 
Первый аргумент, как и ранее — значение fmtflags, которое содержит требуемые установки. Второй аргумент — это значение, которое очищает соответствующие биты. 
Например, предположим, что установка третьего бита в 1 означает использование основания 10, установка четвертого бита — в 1 означает основание 8, а установка пятого бита — основание 16. 
Предположим, что вывод выполняется с основанием 10, и его требуется переключить к основанию 16. 
Для этого нужно не только установить 5-й бит в 1, но и 3-й — в 0 (эту операцию называют очисткой бита). Интеллектуальный манипулятор hex решает обе проблемы автоматически. 
Применение функции setf() требует несколько больших усилий, поскольку нужно использовать второй аргумент для указания очищаемых 
битов, а затем первый аргумент — для указания устанавливаемых битов. 
Эта проблема не настолько сложна, как может показаться, поскольку для этой цели в классе ios_base определены специальные константы (перечисленные в табл. 17.2). 
В частности, изменяя основание системы счисления, нужно применять константу ios_base::basefield в качестве второго аргумента, и ios_base::hex — в качестве первого аргумента. 
*/