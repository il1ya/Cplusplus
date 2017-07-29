1. Что производный класс наследует от базового класса? 
1. Открытые члены базового класса становятся открытыми членами производного класса. Защищенные члены базового класса становятся защищенными членами производного класса. 
Закрытые члены базового класса наследуются, но к ним невозможен доступ напрямую. В ответе на вопрос 2 рассматриваются исключения из этих общих правил* 


2. Что производный класс не наследует от базового класса? 
2. Не наследуются методы конструктора, деструктор, операция присваивания и дружественные функции. 


3. Предположим, что возвращаемый тип для функции baseDMA::operator= () определен как void, а не baseDMA&. 
Как это повлияет на программу? Что случится, если возвращаемым типом будет baseDMA, а не baseDMA&? 
3. Если бы возвращаемым типом был void, по-прежнему можно было бы использовать одиночное присваивание, но не цепочку присваиваний: 
baseDMA magazine("Pandering to Glitz", 1); 
baseDMA giftl, gift2, gift3; 
giftl = magazine;       // нормально 
gift 2 = gift3 = giftl; // больше не допускается 
Если метод возвращает вместо ссылки объект, то выполнение метода может несколько замедлиться, поскольку оператор возврата будет включать копирование объекта. 


4. В каком порядке вызываются конструкторы и деструкторы класса при создании и удалении объекта производного класса? 
4. конструктор с сверху вниз. деструктор с низу вверх.
4. Конструкторы вызываются в порядке порождения, и первым вызывается наиболее вложенный в плане наследования конструктор. 
Деструкторы вызываются в обратном порядке. 


5. Если производный класс не добавляет члены данных в базовый класс, то нужны ли конструкторы для производного класса? 
5. Да, каждый класс требует собственных конструкторов. 
Если производный класс не добавляет новых членов, то конструктор может иметь пустое тело, но обязательно должен существовать. 

6. Предположим, что и в базовом, и в производном классе определен метод с одним и тем же именем, и производный класс вызывает этот метод. 
Который метод будет вызван?
6. Вызывается только метод производного класса. Он заменяет определение базового класса. 
Метод базового класса вызывается только тогда, когда производный класс не переопределяет метод или когда используется операция разрешения контекста. 
Однако в действительности необходимо объявлять виртуальной любую функцию, которая будет переопределена. 


7. В каких случаях производный класс должен определять операцию присваивания? 
7. Производный класс должен определять операцию присваивания, если конструкторы производного класса используют операцию new или new[] для  
инициализации указателей, которые являются членами данного класса. 
В общем случае производный класс должен определять операцию присваивания, если присваивание, предлагаемое по умолчанию, не подходит для членов производного класса. 


8. Можно ли присвоить адрес объекта производного класса указателю на базовый класс? 
Можно ли присвоить адрес объекта базового класса указателю на производный класс? 
8. Да, адрес объекта производного класса может быть присвоен указателю на базовый класс. 
Адрес объекта базового класса может быть присвоен указателю на производный класс (нисходящее преобразование) только путем явного приведения типа; использование такого указателя не всегда безопасно. 


9. Можно ли присвоить объект производного класса объекту базового класса? 
Можно ли присвоить объект базового класса объекту производного класса? 
9. Да, объект производного класса может быть присвоен объекту базового класса. 
Однако любые члены данных, которые являются новыми по отношению к производному типу, базовому типу не передаются. 
Программа использует операцию присваивания базового класса. 
Присваивание в обратном направлении (объекта базового класса объекту производного класса) возможно, только если производный класс определяет операцию преобразования, которая является  
конструктором, имеющим ссылку на базовый тип в виде своего единственного аргумента, или если он определяет операцию присваивания с параметром базового класса. 


10. Предположим, что определена функция, которая принимает в качестве аргумента ссылку на объект базового класса. 
Почему эта функция может также использовать в качестве аргумента объект производного класса? 
10. Она может делать это, потому что C++ позволяет ссылке на базовый тип ссылаться на любой тип, который является производным от этого базового типа. 


11. Предположим, что определена функция, которая принимает в качестве аргумента объект базового класса (т.е. функция передает объект базового класса по значению). 
Почему эта функция может также использовать в качестве аргумента объект производного класса? 
11. Передача объекта по значению активизирует конструктор копирования. 
Так как формальный аргумент является объектом базового класса, то вызывается конструктор копирования базового класса. 
Конструктор копирования получает в качестве своего аргумента ссылку на базовый класс, и эта ссылка может указывать на производный объект, передаваемый как аргумент. 
Совокупный результат состоит в том, что таким образом создается новый объект базового класса, члены которого соответствуют части базового класса в производном объекте. 


12. Почему обычно лучше передавать объекты по ссылке, а не по значению? 
12. Передача объекта по ссылке вместо передачи по значению позволяет использовать виртуальные функции. 
Кроме того, передача объекта по ссылке вместо передачи по значению может расходовать меньше памяти и занимать меньше времени, особенно для крупных объектов. 
Главное преимущество передачи по значению заключается в том, что при этом защищаются исходные данные, однако того же самого можно добиться и с помощью передачи ссылки как типа const. 



13. Предположим, что Corporation — базовый класс, a PublicCorporation — производный. 
Допустим также, что в каждом из этих классов определен метод head(), ph является указателем на тип Corporation, а переменной ph присвоен адрес объекта PublicCorporation. 
Как интерпретируется ph->head(), если в базовом классе метод head() определен как: 
а. обычный не виртуальный метод; 
б. виртуальный метод.
13. Если head() является обычным методом, то ph->head() вызывает Corporation::head(). Если head() является виртуальной функцией, то ph->head() вызывает 
PublicCorporation::head(). 


14. Есть ли ошибки в следующем коде, и если есть, то какие? 

class Kitchen 
{ 
    private: 
        double kit_sq_ft; 
    public: 
        Kitchen() 
        { 
            kit_sq_ft = 0.0;
        } 
        virtual double area() const 
        { 
            return kit_sq_ft * kit_sq_ft; 
        } 
};

class House : public Kitchen 
{ 
    private: 
        double all_sq_ft; 
    public: 
        House() 
        { 
            all_sq_ft + = kit_sq_ft; 
        } 
        double area (const char *s) const 
        { 
            cout << s; 
            return all_sq_ft;
        } 
}; 

14.
Во-первых, ситуация не соответствует модели является, поэтому открытое наследование не подходит. 
Во-вторых, определение area() в House скрывает версию area() в Kitchen, поскольку оба метода имеют разные сигнатуры. 