// Листинг 3.2. exceed.срр 
// exceed.срр - выход за пределы для некоторых целочисленных типов 
#include <iostream>
#define ZERO 0                 // создает символ ZERO для значения 0 
#include <climits>             // определяет INT_MAX как наибольшее значение int 
int main()
{
    using namespace std;
    short sam = SHRT_MAX;     // инициализирует переменную максимальным значением 
    unsigned short sue = sam; // нормально, поскольку переменная sam уже определена 

    cout << "Sam has " << sam << " dollars and Sue has " << sue;
    cout << " dollars deposited." << endl
         << "Add $1 to each account." << endl << "Now ";
         sam = sam + 1;
         sue = sue + 1;
    cout << "Sam has " << sam << " dollars and Sue has " << sue;
    cout << " doolars deposited.\nPoor Sam!" << endl;
    sam = ZERO;
    sue = ZERO;
    cout << "Sam has " << sam << " dollars and Sue has " << sue;
    cout << " dollars deposited." << endl;
    cout << "Take $1 from each account." << endl << "Now";
    sam = sam - 1;
    sue = sue - 1;
    cout << "Sam has " << sam << " dollars and Sue has " << sue;
    cout << " dollars deposited." << endl << "Lucky Sue!" << endl;
    return 0;
}

/* В этой программе переменным типа short (sam) и unsigned short (sue) присваивается максимальное значение short, которое в нашей системе составляет 32 767. 
Затем к значению каждой переменной прибавляется 1. С переменной sue все проходит гладко, поскольку новое значение меньше максимального значения для целочисленного беззнакового типа. 
А переменная sam вместо 32 767 получает значение -32 768! Аналогично и при вычитании единицы от нуля для переменной sam все пройдет гладко, а вот беззнаковая переменная sue получит значение 65 535. 
Как видите, эти целые числа ведут себя почти так же, как и счетчик пробега. После достижения предельного значения отсчет начнется с другого конца диапазона (рис. 3.1). 
Язык C++ гарантирует, что беззнаковые типы ведут себя именно таким образом. 
Однако C++ не гарантирует, что для целочисленных типов со знаком можно выходить за пределы (переполнение и потеря значимости) без сообщения об ошибке; с другой 
стороны, это самое распространенное поведение в современных реализациях. */
