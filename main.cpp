#include <iostream>
#include "array.h"
#define line cout<<endl<<"___________________________________________________________"<<endl;

int main()
{
  //1. Создайте объект Array mas1. Занесите в него 5 чисел: 1,2,3,4,5
  // (элементы вводятся с клавиатуры, для заполнения член-данных используйте функцию Scan).
   // Выведите mas1 на экран, используя функцию Print.
  cout <<"1) Create an Array object mas1. Enter 5 numbers into it: 1,2,3,4,5 (elements are entered from the keyboard, use the Scan function to fill in the data member). Print mas1 to the screen using the Print function."<<endl;
  Array mas1;
  mas1.Scan();
  mas1.Print();
  line;

  //2)	Создайте объект Array mas2, инициализировав его при создании объектом mas 1. Выведите mas2 на экран, используя потоковый вывод.
  cout<<"2) Create an Array object mas2, initializing it when created with object mas 1. Display mas2 to the screen using streaming output."<<endl;
  Array mas2 = mas1;
  mas2.Print();
  line;

  // 3)	Сравните массивы mas1 и mas2.
  cout <<"3) Compare the arrays mas1 and mas2."<<endl;
  (mas2 == mas1 )?cout << "mas1 equals to mas2":cout<<"mas1 does NOT equal to mas2";
  line;

  // 4)	Измените mas1 добавив в него число 6. Выведите измененный mas1 на экран. Сравните массивы mas1 и mas2.
  cout <<"4). Change mas1 by adding the number 6. Display the changed mas1 on the screen.Compare the arrays mas1 and mas2."<<endl;
  mas1 += 6;
  mas1.Print();
  (mas2 == mas1 )?cout << "mas1 equals to mas2":cout<<"mas1 does NOT equal to mas2";
  line;

  // 5)	Создайте объект Array mas3 , который получается добавлением к mas1  числа 7. Выведите mas3 на экран.
  cout << "5) Create an Array mas3 object, which is obtained by adding the number 7 to mas1. Print mas3 to the screen."<<endl;
  Array mas3 = mas1 + 7;
  mas3.Print();
  line;

  // 6)	Удалите первый элемент из mas3. Выведите получившийся mas3 на экран.
  cout<<" 6) Remove the first item from mas3. Print the resulting mas3 to the screen."<<endl;
  mas3 -= mas3[0];
  cout<<"mas3: ";
  mas3.Print();
  line;

  // 7)	Создайте массив mas4, который получается из mas3 удалением последнего элемента. Выведите получившийся mas4 на экран.
  cout<< "7) Create an array mas4 which is obtained from mas3 by removing the last element. Print the resulting mas4 to the screen."<<endl;
  Array mas4  = mas3;
  mas4.DelPosEq(mas4.getN() - 1);
  cout<<"mas4: ";
  mas4.Print();
  line;

  // 8)	Удалите из mas1 элемент key=1. Проверьте, равны ли mas1 и mas4
  cout<<"8) Remove element (the key = 1) from mas1. Check if mas1 and mas4 are equal"<<endl;
  mas1 -= 1;
  (mas4 == mas1 )?cout << "mas1 equals to mas4":cout<<"mas1 does NOT equal to mas4";
  line;

  // 9)	Введите число n  и сформируйте массив b из n случайных чисел.  Создайте объект Array mas5, используя конструктор с аргументом-массив.
  cout<<"9) Enter the number n and form an array b of n random numbers. Create an Array mas5 using the constructor with an array argument."<<endl;
  int n;
  cout<<"enter n";
  cin>>n;
  int *b=new int[n];
  for(int i=0; i<n; i++)b[i]=rand()%50;
  Array mas5(b, n);
  cout<<"array mas5:"<<mas5<<endl;
  delete []b;


  // 10)  Найдите максимальный и минимальный элемент в mas5. Выведите на экран эти элементы и их индексы.
  cout<<"10) Find the maximum and minimum element in mas5. Display these elements and their indices."<<endl;
   cout << "mas5 max: "<< mas5[mas5.Max()] <<", at index: "<< mas5.Max()<<endl;
   cout << "mas5 min: "<< mas5[mas5.Min()] <<", at index: "<< mas5.Min()<<endl;
   line;

  // 11)	Сортируйте mas5 и выведите результат на экран.
  cout<<" 11) Sort mas5 and display the result."<<endl;
    mas5.Sort();
    mas5.Print();
   line;

  // 12)	Создайте  объект Array mas6, объединив mas1 и mas5. Выведите результат на экран
  cout << "12) Create Array object mas6 by concatenating mas1 and mas5. Display the result on the screen"<<endl;
  Array mas6 = mas3 + mas5;
  mas6.Print();
  line;

  // 13)  Создайте  объект Array mas7 – массив из 4-х элементов. Заполните член-данные (10, 11, 12, 13), используя потоковый ввод.
  cout << "13) Create object Array mas7 - an array of 4 elements. Fill in the data member (10, 11, 12, 13) using streaming input."<<endl;
  Array mas7;
  mas7.Scan(4);
  line;

   // 14)  Проверьте, входят ли в mas7 элементы 1 и 10. Создайте mas8, который получается из mas7 удалением элемента 10.
  cout << "14) Check if mas7 contains items 1 and 10. Create mas8, which is obtained from mas7 by deleting item 10."<<endl;
  (mas7.FindKey(1) != -1)?cout <<"mas7 contains 1"<<endl:cout<<"mas7 does NOT contain 1"<<endl;
  (mas7.FindKey(10 != -1))?cout <<"mas7 contains 10"<<endl:cout<<"mas7 does NOT contain 10"<<endl;
  Array mas8;
  mas8 = mas7;
  mas8.DelPosEq(0);


 // mas7.Print();
  cout <<"mas8: ";
  mas8.Print();
  line;

  // 15)	Измените mas4, добавив к нему mas7. Выведите результат на экран. Сравните mas6 и mas4.
  cout <<" 15) Modify mas4 by adding mas7 to it. Display the result on the screen. Compare mas6 and mas4."<<endl;
  mas4 += mas7;
  mas4.Print();
  (mas6 == mas4)?cout<<"mas6 equals to mas4"<<endl:cout<<"mas6 does NOT equal to mas4"<<endl;
  line;

  // 16) Осуществите присвоение mas4=mas6. Выведите результат на экран
    cout << "16) Make the assignment mas4 = mas6. Display the result on the screen"<<endl;
    mas4 = mas6;
    mas4.Print();
  line;
  /*

*/

}
