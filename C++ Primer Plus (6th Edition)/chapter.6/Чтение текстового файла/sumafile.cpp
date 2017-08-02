/* Программа в листинге 6.16 открывает файл, указанный пользователем, читает из файла числа, после чего сообщает количество прочитанных значений, их сумму и среднюю величину. 
Здесь важно правильно спроектировать входной цикл, что обсуждается подробно в разделе "Замечания по программе". Обратите внимание на интенсивное использование в программе операторов if. 
Листинг 6.16. sumafile.cpp */
// sumfile.cpp -- чтение файла 
#include <iostream>
#include <fstream> // поддержка файлового ввода-вывода
#include <cstdlib> // поддержка exit()
const int SIZE = 60;
int main(void)
{
    using namespace std;
    char filename[SIZE];
    ifstream inFile;                     // объект для обработки файлового ввода 
    cout << "Enter name of data file: "; // запрос имени файла данных 
    cin.getline(filename, SIZE);
    inFile.open(filename);              // ассоциирование inFile с файлом 
    if(!inFile.is_open())               // не удалось открыть файл 
    {
        cout << "Could not open the file " << filename << endl;
        cout << "Program terminating.\n";
        exit(EXIT_FAILURE);
    }
    double value;
    double sum = 0.0;
    int count = 0;                      // количество прочитанных элементов 
    inFile >> value;                    // ввод первого значения 
    while(inFile.good())                // пока ввод успешен и не достигнут EOF 
    {
        ++count;                        // еще один элемент прочитан 
        sum += value;                   // вычисление текущей суммы 
        inFile >> value;                // ввод следующего значения 
    }
    if(inFile.eof())
        // достигнут конец файла 
    cout << "End of file reached.\n";
    else if(inFile.fail())
        // ввод прекращен из-за несоответствия типа данных 
    cout << "Input terminated by data mismatch.\n";
    else
         // ввод прекращен по неизвестной причине 
    cout << "Input terminated for unknown reason.\n";
    if(count == 0)
        // данные для обработки отсутствуют 
    cout << "No data processed.\n";
    else
    {
        cout << "Items read: " << count << endl;    // прочитано элементов 
        cout << "Sum: " << sum << endl;             // сумма 
        cout << "Average: " << sum / count << endl; // среднее значение 
    }
    inFile.close();                                 // завершение работы с файлом 
    return 0;
}
/* 
Чтобы использовать программу из листинга 6.16, сначала понадобится создать текстовый файл, содержащий числа. 
Для этого можно воспользоваться текстовым редактором, который обычно применяется для подготовки исходных текстов программ. 
Предположим, что файл называется scores.txt и содержит следующие данные: 
18 19 18.5 13.5 14- 
16 19.5 20 18 12 18.5 
17.5 
Программа должна иметь возможность найти этот файл. 
Обычно, если только при вводе имени файла не указывается также и путь, программа будет искать файл в том же каталоге, где хранится исполняемый файл. 

Замечания по программе 
Вместо жесткого кодирования имени файла программа из листинга 6.16 сохраняет введенное пользователем имя в символьном массиве filename. 
Затем этот массив передается в качестве аргумента open(): 
inFile.open(filename); 
Как говорилось ранее в настоящей главе, весьма желательно проверять, удалась ли попытка открытия файла. 
Вот несколько причин возможных неудач: файл может не существовать, он может находиться в другом каталоге, к нему может быть  
запрещен доступ, либо пользователь может допустить опечатку при вводе его имени или не указать расширение. 
Многие начинающие программисты тратят массу времени, пытаясь разобраться, почему неправильно работает цикл чтения из файла, тогда как 
реальная проблема заключается в том, что программе просто не удалось его открыть. 
Проверка успешности открытия файла может сэкономить немало времени и усилий. 
Правильному проектированию цикла чтения файла должно уделяться особое внимание. Есть несколько вещей, которые нужно проверять при чтении файла. Во- 
первых, программа не должна пытаться читать после достижения EOF. Метод eof() возвращает true, когда последняя попытка чтения данных столкнулась с EOF. 
Во-вторых, программа может столкнуться с несоответствием типа. 
Например, программа из листинга 6.16 ожидает файла, содержащего только числа. 
Метод fail() возвращает true, когда последняя попытка чтения сталкивается с несоответствием типа. (Этот метод также возвращает true при достижении EOF) 
*/
/*
И, наконец, что-то другое может пойти не так — например, файл окажется поврежденным или произойдет сбой оборудования. Метод bad() вернет true, если самая 
последняя попытка чтения столкнется с такой проблемой. Вместо того чтобы проверять все эти условия индивидуально, проще применить метод good(), который возвращает true, если все идет хорошо: 
while (inFile.good()) // пока ввод успешен и не достигнут EOF 
{ 
} 
Затем при желании можно воспользоваться другими методами для определения точной причины прекращения цикла: 
if (inFile.eof()) 
// Достигнут конец файла 
cout « "End of file reached. \n"; 
else if (inFile.fail ()) 
// Ввод прекращен из-за несоответствия типа данных 
cout « "Input terminated by data mismatch.\n"; N 
else 
// Ввод прекращен по неизвестной причине 
cout « "Input terminated for unknown reason.\n"; 
Этот код находится сразу после цикла, поэтому он исследует, почему цикл был прерван. Поскольку eof() проверяет только EOF, a fail() проверяет как EOF, так и 
несоответствие типа, здесь вначале проверятся именно EOF. 
Таким образом, если выполнение дойдет до else if, то достижение конца файла (EOF) как причина выхода из цикла будет исключена, и значение true, полученное от fail(), недвусмысленно 
укажет на несоответствие типа. 
Важно также понимать, что good() сообщает лишь о самой последней попытке чтения ввода. Это значит, что попытка чтения должна непосредственно предшествовать вызову good (). 
Стандартный способ обеспечения этого — иметь один оператор ввода непосредственно перед началом цикла, перед первой проверкой условия  
цикла, а второй — в конце цикла, непосредственно перед следующей проверкой условия цикла: 
// Стандартная структура цикла чтения 
inFile » value; // ввод первого значения 
while (inFile.good()) // пока ввод успешен и не достигнут EOF 
{ 
// Тело цикла 
inFile » value; // ввод следующего значения 
} 
Код можно несколько сократить, использул тот факт, что показанное ниже выражение возвращает собственно inFile, а этот inFile, помещенный в контекст, в 
котором ожидается значение bool, вычисляется как inFile.good() — т.е. как true или false: 
inFile >> value 
Поэтому два оператора ввода можно заменить одним, используя его в качестве условия цикла. Это значит, что предыдущую структуру цикла можно заменить следующей:
// Сокращенная структура цикла чтения 
// Ввод перед циклом опущен 
while (inFile » value) // чтение и проверка успешности 
{ 
// Тело цикла 
// Ввод в конце цикла опущен 
} 
Эта структура по-прежнему следует принципу попытки чтения перед проверкой, поскольку для оценки выражения inFile » value программа сначала пытается выполнить его, читая число в переменную value. 
Теперь вы знакомы с основами файлового ввода-вывода. 
*/