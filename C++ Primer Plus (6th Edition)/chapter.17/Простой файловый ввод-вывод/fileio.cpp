/* 
Закрытие такого соединения не уничтожает поток; оно просто отключает его от файла. 
Однако средства управления потоком никуда не деваются. Например, объект fin продолжает существовать, как и входной буфер, которым он управляет. 
Как будет показано позже, этот поток можно заново подключить к тому же или к другому файлу. 
Рассмотрим краткий пример. Программа в листинге 17.16 запрашивает имя файла. 
Она создает файл с этим именем, записывает в него некоторую информацию и закрывает файл. 
Закрытие файла очищает буфер, тем самым гарантируя обновление файла. 
Затем программа открывает тот же файл для чтения и отображает его содержимое. 
Обратите внимание, что программа использует fin и fout таким же образом, как если бы применялись сіп и cout. 
Кроме того, программа считывает имя файла в объект string, а затем использует метод c_str() для передачи конструкторам of stream и if stream аргументов — строк в стиле С. 
Листинг 17.16. fileio.cpp */
#include <iostream>         // для многих систем не требуется 
#include <fstream>
#include <string>

int main()
{
    using namespace std;
    string filename;
    cout << "Enter name for new file: ";        // запрос имени нового файла 
    cin >> filename;

    // Создание объекта выходного потока для нового файла и назначение ему имени fout 
    ofstream fout(filename.c_str());
    fout << "For your eyes only!\n";            // запись в файл  
    cout << "Enter your secret number: ";       // вывод на экран
    float secret;
    cin >> secret;
    fout << "Your secret number is " << secret << endl;
    fout.close();                               // закрытие файла 
    // Создание объекта входного потока для нового файла и назначение ему имени fin 
    ifstream fin(filename.c_str());
    cout << "Here are the contents of " << filename << ":\n";
    char ch;
    while(fin.get(ch))                          // чтение символа из файла 
        cout << ch;                             // и его вывод на экран 
    cout << "Done\n";
    fin.close();

    return 0;
}

// Если вы просмотрите каталог, содержащий программу, то найдете там файл pythag и, загрузив его в любом текстовом редакторе, увидите то же содержимое, что и выводе программы. 
