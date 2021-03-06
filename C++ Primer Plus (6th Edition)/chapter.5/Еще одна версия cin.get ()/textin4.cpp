/* Существует один тонкий, но важный момент, касающийся применения cin.get (), о котором еще не было сказано. 
Поскольку EOF представляет значение, находящееся вне допустимых кодов символов, может случиться, что оно будет не совместимо с типом char. 
Например, в некоторых системах тип char является беззнаковым, поэтому переменная типа char никогда не получит обычного значения EOF, равного -1. 
По этой причине, если вы используете cin.getO (без аргументов) и проверяете возврат на EOF, то должны присваивать возвращенное значение int, а не char. 
Кроме того, если вы объявите ch типа int вместо char, то, возможно, вам придется выполнить приведение к типу char при его отображении. 
В листинге 5.19 представлен подход cin.get() в новой версии программы из листинга 5.18. 
Он также сокращает код за счет комбинации символьного ввода с проверочным условием цикла while. 
Листинг 5.19. textin4.срр */
// textin4.cpp -- чтение символов с помощью cin.getO 
#include <iostream>
int main(void)
{
    using namespace std;
    int ch; // должно быть типа int, а не char 
    int count = 0;
    while((ch = cin.get()) != false)  // проверка конца файла 
    {
        cout.put(char(ch));
        ++count;
    }
    cout << endl << count << " characters read\n";
    return 0;
}