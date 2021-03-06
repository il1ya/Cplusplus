/* После этих изменений функция, использующая объект autoptr, приобретает следующий вид: 
#include <memory> 
void remodel(std::string & str) 
{ 
    std::auto_ptr<std::string> ps (new std::string(str)); 
    if(weird_thing()) 
    throw exception ; 
    str = *ps;
    // delete ps; ЭТОТ ОПЕРАТОР БОЛЬШЕ НЕ НУЖЕН 
    return; 
} 
Обратите внимание, что интеллектуальные указатели принадлежат пространству имен std. 
В листинге 16.5 приведена простая программа, в которой используются все три описанных выше интеллектуальных указателя. 
(Чтобы ее можно было выполнить, компилятор должен поддерживать классы shared_ptr и unique_ptr из С++11.) 
Каждый случай использования помещается внутрь блока, чтобы указатель удалялся, когда процесс выполнения программы покидает блок. 
Класс Report применяет многословные методы для сообщения о создании или уничтожении объекта. 
Листинг 16.5. smrtptrs.cpp */
// smrtptrs.cpp — использование трех видов интеллектуальных указателей 
// требуется поддержка shared_ptr и unique_ptr из С++11 
#include <iostream>
#include <string>
#include <memory>

class Report
{
    private:
        std::string str;
    public:
        Report(const std::string s) : str(s)
        {
            std::cout << "Object deleted!\n";
        }
        ~Report()
        {
            std::cout << "Object deleted!\n";
        }
        void comment() const
        {
            std::cout << str << "\n";
        }
};
int main()
{
    {
        std::auto_ptr<Report> ps(new Report("using auto_ptr"));
        ps->comment(); // использование операции -> для вызова функции-члена 
    }
    {
        std::shared_ptr<Report> ps(new Report("using shared_ptr"));
        ps->comment();
    }
    {
        std::unique_ptr<Report> ps(new Report("using unique_ptr"));
        ps->comment();
    }
    return 0;
}
/*
Каждый из этих классов имеет конструктор explicit, который принимает указатель в качестве аргумента. 
Поэтому автоматическое преобразование типов из указателя в объект интеллектуального указателя не выполняется: 

    shared_ptr<doukle> pd; 
    double *p_reg = new double; 
    pd = p_reg;                         // недопустимо (неявное преобразование) 
    pd = shared_ptr<double>(p_reg);     // допустимо (явное преобразование) 
    shared_ptr<double> pshared = p_reg; // недопустимо (неявное преобразование) 
    shared_ptr<double> pshared(p_reg);  // допустимо (явное преобразование) 

Классы интеллектуальных указателей определены таким образом, что в большинстве случаев объект интеллектуального указателя работает подобно обычному указателю. 
Например, если ps — объект интеллектуального указателя, его можно разыменовывать (*ps), использовать для получения доступа к членам структуры (ps->puffIndex) 
и присваивать регулярному указателю, который указывает на тот же тип. Один объект интеллектуального указателя можно также присвоить другому того же типа, но при 
этом возникают проблемы, которые рассмотрены в следующем разделе. 
Но вначале давайте остановимся на ситуации,которой следует избегать при использовании всех трех названных интеллектуальных указателей: 

    string vacation("I wandered lonely as a cloud."); 
    shared_ptr<string> pvac(Svacation);     // ТАК ДЕЛАТЬ НЕЛЬЗЯ!
     
При удалении объекта рѵас программа применила бы операцию delete к памяти не из кучи, что совершенно неприемлемо. 
Если код в листинге 16.5 представляет собой венец программных устремлений, любой из этих трех интеллектуальных указателей может быть использован с равным успехом. 
Однако их возможности не ограничиваются уже описанными. 
*/