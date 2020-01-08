type lab1-11.m

 Рассмотрим следующий файл-сценарий:
    %M-file approk
            for j=2:15
                 x=0:.03*pi:pi;
                 p=polyfit(x, y, j)
                 f=polyval(p, x);
                 plot(x, y, 'ob', x, f, '-g')
                 pause
                 end
                 clf, close;
 Этот сценарий для изначально заданной функции "y(x)" ,  изменяющейся
 с шагом 0.03pi,  вычисляет аппроксимирующий полином с возможным
 порядком от 2 до 15, а затем выводит графики функции и полинома для
 сравнения. Коэффициенты  аппроксимирующего  полинома  заданного 
 порядка j  вычисляются  функцией  polyfit, а само значение полинома в
 точке х вычисляет функция polyval. Ответьте на вопрос: каков минимальный
 порядок полинома,  на ваш взгляд,  удовлетворительно аппроксимирующего 
                                          sinx   
                   функцию y= e      ?
 Для ответа задайте в командной строке следующее:
    >> approk      нажмите Enter и не обращайте внимание на вы-
                   данные после этого сообщения
    >> y=[];
    >> y=exp(sin(x));
    >> approk
 (Не забывайте, что каждая строка вводится с помощью Enter.)
 Для получения графика,  следующего за текущим (при этом порядок ап-
 роксимирующего полинома увеличивается на 1),  нажмите любую кла-
 вишу. После этого выполните аналогичную работу для функций:
                      2                                      3
                  sin  x                               sin  x
           y= e                      ,          y= e
 Как изменяется порядок полинома и почему? Выводы по данному пункту лабора-
 торной работы проиллюстрируйте графиками в отчете. Запишите также выражения
 выбранных полиномов минимального порядка для каждой функции.
 После этого задайте команду type lab1-12.m 
approk
??? Error using ==> polyfit at 48
X and Y vectors must be the same size.

Error in ==> approk at 4
    p=polyfit(x,y,j)
 
 y=[];
 y=exp(sin(x));
approk

p =

   -0.0003    0.0472   -0.8321


p =

    0.0000   -0.0014    0.1484   -3.7277

Warning: Polynomial is badly conditioned. Add points with distinct X
         values, reduce the degree of the polynomial, or try centering
         and scaling as described in HELP POLYFIT. 
> In polyfit at 80
  In approk at 4

p =

   -0.0000    0.0005   -0.0636    3.7547  -80.8342

Warning: Polynomial is badly conditioned. Add points with distinct X
         values, reduce the degree of the polynomial, or try centering
         and scaling as described in HELP POLYFIT. 
> In polyfit at 80
  In approk at 4

p =

    0.0000   -0.0000    0.0034   -0.3242   15.0331 -273.3686

Warning: Polynomial is badly conditioned. Add points with distinct X
         values, reduce the degree of the polynomial, or try centering
         and scaling as described in HELP POLYFIT. 
> In polyfit at 80
  In approk at 4

p =

  1.0e+003 *

   -0.0000    0.0000   -0.0000    0.0001   -0.0045    0.1593   -2.3227

Warning: Polynomial is badly conditioned. Add points with distinct X
         values, reduce the degree of the polynomial, or try centering
         and scaling as described in HELP POLYFIT. 
> In polyfit at 80
  In approk at 4

p =

  1.0e+004 *

    0.0000   -0.0000    0.0000   -0.0000    0.0001   -0.0034    0.1001   -1.2570

Warning: Polynomial is badly conditioned. Add points with distinct X
         values, reduce the degree of the polynomial, or try centering
         and scaling as described in HELP POLYFIT. 
> In polyfit at 80
  In approk at 4

p =

  1.0e+004 *

  Columns 1 through 8

   -0.0000    0.0000   -0.0000    0.0000   -0.0000    0.0002   -0.0075    0.2000

  Column 9

   -2.3198

Warning: Polynomial is badly conditioned. Add points with distinct X
         values, reduce the degree of the polynomial, or try centering
         and scaling as described in HELP POLYFIT. 
> In polyfit at 80
  In approk at 4

p =

  1.0e+005 *

  Columns 1 through 8

    0.0000   -0.0000    0.0000   -0.0000    0.0000   -0.0000    0.0006   -0.0209

  Columns 9 through 10

    0.4519   -4.3149

Warning: Polynomial is badly conditioned. Add points with distinct X
         values, reduce the degree of the polynomial, or try centering
         and scaling as described in HELP POLYFIT. 
> In polyfit at 80
  In approk at 4

p =

  1.0e+006 *

  Columns 1 through 8

    0.0000   -0.0000    0.0000   -0.0000    0.0000   -0.0000    0.0000   -0.0005

  Columns 9 through 11

    0.0153   -0.2857    2.3828

Warning: Polynomial is badly conditioned. Add points with distinct X
         values, reduce the degree of the polynomial, or try centering
         and scaling as described in HELP POLYFIT. 
> In polyfit at 80
  In approk at 4

p =

  1.0e+006 *

  Columns 1 through 8

    0.0000   -0.0000    0.0000   -0.0000    0.0000   -0.0000    0.0000   -0.0000

  Columns 9 through 12

    0.0020   -0.0564    0.9401   -7.0923

Warning: Polynomial is badly conditioned. Add points with distinct X
         values, reduce the degree of the polynomial, or try centering
         and scaling as described in HELP POLYFIT. 
> In polyfit at 80
  In approk at 4

p =

  1.0e+008 *

  Columns 1 through 8

    0.0000   -0.0000    0.0000   -0.0000    0.0000   -0.0000    0.0000   -0.0000

  Columns 9 through 13

    0.0000   -0.0006    0.0164   -0.2544    1.7981

Warning: Polynomial is badly conditioned. Add points with distinct X
         values, reduce the degree of the polynomial, or try centering
         and scaling as described in HELP POLYFIT. 
> In polyfit at 80
  In approk at 4

p =

  1.0e+008 *

  Columns 1 through 8

   -0.0000    0.0000   -0.0000    0.0000   -0.0000    0.0000   -0.0000    0.0000

  Columns 9 through 14

   -0.0000    0.0000   -0.0011    0.0275   -0.4127    2.8327

Warning: Polynomial is badly conditioned. Add points with distinct X
         values, reduce the degree of the polynomial, or try centering
         and scaling as described in HELP POLYFIT. 
> In polyfit at 80
  In approk at 4

p =

  1.0e+009 *

  Columns 1 through 8

    0.0000   -0.0000    0.0000   -0.0000    0.0000   -0.0000    0.0000   -0.0000

  Columns 9 through 15

    0.0000   -0.0000    0.0001   -0.0033    0.0718   -0.9482    5.7896

Warning: Polynomial is badly conditioned. Add points with distinct X
         values, reduce the degree of the polynomial, or try centering
         and scaling as described in HELP POLYFIT. 
> In polyfit at 80
  In approk at 4

p =

  1.0e+010 *

  Columns 1 through 8

   -0.0000    0.0000   -0.0000    0.0000   -0.0000    0.0000   -0.0000    0.0000

  Columns 9 through 16

   -0.0000    0.0000   -0.0000    0.0001   -0.0016    0.0323   -0.4028    2.3373

type lab1-11.m

 Рассмотрим следующий файл-сценарий:
    %M-file approk
            for j=2:15
                 x=0:.03*pi:pi;
                 p=polyfit(x, y, j)
                 f=polyval(p, x);
                 plot(x, y, 'ob', x, f, '-g')
                 pause
                 end
                 clf, close;
 Этот сценарий для изначально заданной функции "y(x)" ,  изменяющейся
 с шагом 0.03pi,  вычисляет аппроксимирующий полином с возможным
 порядком от 2 до 15, а затем выводит графики функции и полинома для
 сравнения. Коэффициенты  аппроксимирующего  полинома  заданного 
 порядка j  вычисляются  функцией  polyfit, а само значение полинома в
 точке х вычисляет функция polyval. Ответьте на вопрос: каков минимальный
 порядок полинома,  на ваш взгляд,  удовлетворительно аппроксимирующего 
                                          sinx   
                   функцию y= e      ?
 Для ответа задайте в командной строке следующее:
    >> approk      нажмите Enter и не обращайте внимание на вы-
                   данные после этого сообщения
    >> y=[];
    >> y=exp(sin(x));
    >> approk
 (Не забывайте, что каждая строка вводится с помощью Enter.)
 Для получения графика,  следующего за текущим (при этом порядок ап-
 роксимирующего полинома увеличивается на 1),  нажмите любую кла-
 вишу. После этого выполните аналогичную работу для функций:
                      2                                      3
                  sin  x                               sin  x
           y= e                      ,          y= e
 Как изменяется порядок полинома и почему? Выводы по данному пункту лабора-
 торной работы проиллюстрируйте графиками в отчете. Запишите также выражения
 выбранных полиномов минимального порядка для каждой функции.
 После этого задайте команду type lab1-12.m 
y=exp((sin(x))^2);
??? Error using ==> mpower
Inputs must be a scalar and a square matrix.
 
y=exp((sin(x).)^2);
??? y=exp((sin(x).)^2);
                  |
Error: Unbalanced or unexpected parenthesis or bracket.
 
y=exp((sin(x)).^2);
approk

p =

   -0.0001    0.0093    1.3791


p =

   -0.0000    0.0012   -0.1012    4.5430

Warning: Polynomial is badly conditioned. Add points with distinct X
         values, reduce the degree of the polynomial, or try centering
         and scaling as described in HELP POLYFIT. 
> In polyfit at 80
  In approk at 4

p =

   -0.0000    0.0001   -0.0156    0.8720  -16.2652

Warning: Polynomial is badly conditioned. Add points with distinct X
         values, reduce the degree of the polynomial, or try centering
         and scaling as described in HELP POLYFIT. 
> In polyfit at 80
  In approk at 4

p =

   -0.0000    0.0000   -0.0015    0.1310   -5.4680   91.9640

Warning: Polynomial is badly conditioned. Add points with distinct X
         values, reduce the degree of the polynomial, or try centering
         and scaling as described in HELP POLYFIT. 
> In polyfit at 80
  In approk at 4

p =

   -0.0000    0.0000   -0.0002    0.0269   -1.7300   58.7078 -819.8454

Warning: Polynomial is badly conditioned. Add points with distinct X
         values, reduce the degree of the polynomial, or try centering
         and scaling as described in HELP POLYFIT. 
> In polyfit at 80
  In approk at 4

p =

  1.0e+003 *

   -0.0000    0.0000   -0.0000    0.0000   -0.0001    0.0063   -0.1719    1.9861

Warning: Polynomial is badly conditioned. Add points with distinct X
         values, reduce the degree of the polynomial, or try centering
         and scaling as described in HELP POLYFIT. 
> In polyfit at 80
  In approk at 4

p =

  1.0e+004 *

  Columns 1 through 8

   -0.0000    0.0000   -0.0000    0.0000   -0.0000    0.0003   -0.0138    0.3360

  Column 9

   -3.5596

Warning: Polynomial is badly conditioned. Add points with distinct X
         values, reduce the degree of the polynomial, or try centering
         and scaling as described in HELP POLYFIT. 
> In polyfit at 80
  In approk at 4

p =

  1.0e+003 *

  Columns 1 through 8

   -0.0000    0.0000   -0.0000    0.0000   -0.0000    0.0000   -0.0009    0.0139

  Columns 9 through 10

    0.1125   -4.8939

Warning: Polynomial is badly conditioned. Add points with distinct X
         values, reduce the degree of the polynomial, or try centering
         and scaling as described in HELP POLYFIT. 
> In polyfit at 80
  In approk at 4

p =

  1.0e+006 *

  Columns 1 through 8

   -0.0000    0.0000   -0.0000    0.0000   -0.0000    0.0000   -0.0000    0.0003

  Columns 9 through 11

   -0.0088    0.1683   -1.4351

Warning: Polynomial is badly conditioned. Add points with distinct X
         values, reduce the degree of the polynomial, or try centering
         and scaling as described in HELP POLYFIT. 
> In polyfit at 80
  In approk at 4

p =

  1.0e+006 *

  Columns 1 through 8

    0.0000   -0.0000    0.0000   -0.0000    0.0000   -0.0000    0.0000   -0.0000

  Columns 9 through 12

    0.0009   -0.0268    0.4754   -3.8093

Warning: Polynomial is badly conditioned. Add points with distinct X
         values, reduce the degree of the polynomial, or try centering
         and scaling as described in HELP POLYFIT. 
> In polyfit at 80
  In approk at 4

p =

  1.0e+007 *

  Columns 1 through 8

   -0.0000    0.0000   -0.0000    0.0000   -0.0000    0.0000   -0.0000    0.0000

  Columns 9 through 13

   -0.0000    0.0018   -0.0464    0.7271   -5.1947

Warning: Polynomial is badly conditioned. Add points with distinct X
         values, reduce the degree of the polynomial, or try centering
         and scaling as described in HELP POLYFIT. 
> In polyfit at 80
  In approk at 4

p =

  1.0e+008 *

  Columns 1 through 8

    0.0000   -0.0000    0.0000   -0.0000    0.0000   -0.0000    0.0000   -0.0000

  Columns 9 through 14

    0.0000   -0.0000    0.0012   -0.0290    0.4198   -2.7889

Warning: Polynomial is badly conditioned. Add points with distinct X
         values, reduce the degree of the polynomial, or try centering
         and scaling as described in HELP POLYFIT. 
> In polyfit at 80
  In approk at 4

p =

  1.0e+009 *

  Columns 1 through 8

   -0.0000    0.0000   -0.0000    0.0000   -0.0000    0.0000   -0.0000    0.0000

  Columns 9 through 15

   -0.0000    0.0000   -0.0000    0.0009   -0.0196    0.2614   -1.6113

Warning: Polynomial is badly conditioned. Add points with distinct X
         values, reduce the degree of the polynomial, or try centering
         and scaling as described in HELP POLYFIT. 
> In polyfit at 80
  In approk at 4

p =

  1.0e+009 *

  Columns 1 through 8

    0.0000   -0.0000    0.0000   -0.0000    0.0000   -0.0000    0.0000   -0.0000

  Columns 9 through 16

    0.0000   -0.0000    0.0000   -0.0001    0.0034   -0.0701    0.8806   -5.1408

y=exp((sin(x)).^3);
approk

p =

   -0.0002    0.0352   -0.3799


p =

    0.0000   -0.0005    0.0582   -1.0397

Warning: Polynomial is badly conditioned. Add points with distinct X
         values, reduce the degree of the polynomial, or try centering
         and scaling as described in HELP POLYFIT. 
> In polyfit at 80
  In approk at 4

p =

   -0.0000    0.0004   -0.0474    2.7844  -59.3299

Warning: Polynomial is badly conditioned. Add points with distinct X
         values, reduce the degree of the polynomial, or try centering
         and scaling as described in HELP POLYFIT. 
> In polyfit at 80
  In approk at 4

p =

    0.0000   -0.0000    0.0016   -0.1564    7.4978 -139.7913

Warning: Polynomial is badly conditioned. Add points with distinct X
         values, reduce the degree of the polynomial, or try centering
         and scaling as described in HELP POLYFIT. 
> In polyfit at 80
  In approk at 4

p =

  1.0e+003 *

   -0.0000    0.0000   -0.0000    0.0001   -0.0034    0.1186   -1.7178

Warning: Polynomial is badly conditioned. Add points with distinct X
         values, reduce the degree of the polynomial, or try centering
         and scaling as described in HELP POLYFIT. 
> In polyfit at 80
  In approk at 4

p =

  1.0e+003 *

    0.0000   -0.0000    0.0000   -0.0000    0.0003   -0.0182    0.5431   -6.8836

Warning: Polynomial is badly conditioned. Add points with distinct X
         values, reduce the degree of the polynomial, or try centering
         and scaling as described in HELP POLYFIT. 
> In polyfit at 80
  In approk at 4

p =

  1.0e+004 *

  Columns 1 through 8

   -0.0000    0.0000   -0.0000    0.0000   -0.0000    0.0001   -0.0060    0.1556

  Column 9

   -1.7666

Warning: Polynomial is badly conditioned. Add points with distinct X
         values, reduce the degree of the polynomial, or try centering
         and scaling as described in HELP POLYFIT. 
> In polyfit at 80
  In approk at 4

p =

  1.0e+005 *

  Columns 1 through 8

    0.0000   -0.0000    0.0000   -0.0000    0.0000   -0.0000    0.0003   -0.0111

  Columns 9 through 10

    0.2408   -2.3062

Warning: Polynomial is badly conditioned. Add points with distinct X
         values, reduce the degree of the polynomial, or try centering
         and scaling as described in HELP POLYFIT. 
> In polyfit at 80
  In approk at 4

p =

  1.0e+006 *

  Columns 1 through 8

    0.0000   -0.0000    0.0000   -0.0000    0.0000   -0.0000    0.0000   -0.0003

  Columns 9 through 11

    0.0110   -0.2056    1.7226

Warning: Polynomial is badly conditioned. Add points with distinct X
         values, reduce the degree of the polynomial, or try centering
         and scaling as described in HELP POLYFIT. 
> In polyfit at 80
  In approk at 4

p =

  1.0e+006 *

  Columns 1 through 8

    0.0000   -0.0000    0.0000   -0.0000    0.0000   -0.0000    0.0000   -0.0000

  Columns 9 through 12

    0.0007   -0.0186    0.3003   -2.1880

Warning: Polynomial is badly conditioned. Add points with distinct X
         values, reduce the degree of the polynomial, or try centering
         and scaling as described in HELP POLYFIT. 
> In polyfit at 80
  In approk at 4

p =

  1.0e+008 *

  Columns 1 through 8

    0.0000   -0.0000    0.0000   -0.0000    0.0000   -0.0000    0.0000   -0.0000

  Columns 9 through 13

    0.0000   -0.0005    0.0119   -0.1849    1.3089

Warning: Polynomial is badly conditioned. Add points with distinct X
         values, reduce the degree of the polynomial, or try centering
         and scaling as described in HELP POLYFIT. 
> In polyfit at 80
  In approk at 4

p =

  1.0e+008 *

  Columns 1 through 8

   -0.0000    0.0000   -0.0000    0.0000   -0.0000    0.0000   -0.0000    0.0000

  Columns 9 through 14

   -0.0000    0.0000   -0.0013    0.0309   -0.4547    3.0734

Warning: Polynomial is badly conditioned. Add points with distinct X
         values, reduce the degree of the polynomial, or try centering
         and scaling as described in HELP POLYFIT. 
> In polyfit at 80
  In approk at 4

p =

  1.0e+009 *

  Columns 1 through 8

    0.0000   -0.0000    0.0000   -0.0000    0.0000   -0.0000    0.0000   -0.0000

  Columns 9 through 15

    0.0000   -0.0000    0.0001   -0.0024    0.0520   -0.6876    4.2063

Warning: Polynomial is badly conditioned. Add points with distinct X
         values, reduce the degree of the polynomial, or try centering
         and scaling as described in HELP POLYFIT. 
> In polyfit at 80
  In approk at 4

p =

  1.0e+010 *

  Columns 1 through 8

   -0.0000    0.0000   -0.0000    0.0000   -0.0000    0.0000   -0.0000    0.0000

  Columns 9 through 16

   -0.0000    0.0000   -0.0000    0.0000   -0.0012    0.0240   -0.2995    1.7372

type lab1-12.m

 Теперь рассмотрим простейший пример М-файла,  оформленного в виде
 функции,  т.е. М-функции. Ее состав следующий:
   
 Строка определения функции          function y=prim(x)
 Первая строка комментария           % Prim - графики
 Возможно,  самого комментария       % Подготовка функций для графиков                           
 Самого задания одной или              y(:, 1)=200*sin(x)./x;
 нескольких функций                         y(:, 2)=x.^2*sin(x);

 Для последующего обращения к зтим функциям используется имя prim.
 Ответьте на вопрос: где в диапазоне  -7<x<0 достигается  min[y(1)] и
 max[y(2)] ?
 Для этого используйте команду построения графиков одной или нес-
 кольких функций fplot. Сначала познакомьтесь со структурой команды.
 Вы уже знаете,  что это можно сделать с помощью "справочной" коман-
 ды help.Поэтому в командной строке задайте  help fplot. После ознаком-
 ления введите type lab1-13.m

prim
??? Input argument "x" is undefined.

Error in ==> prim at 4
y(:,1)=200*sin(x)./x;
 
prim(x)

ans =

  1.0e+004 *

   -0.0001   -0.1097
   -0.0002   -0.2650
   -0.0003   -0.3595
   -0.0003   -0.3675
   -0.0002   -0.2841
   -0.0001   -0.1273
    0.0001    0.0664
    0.0002    0.2498
    0.0003    0.3768
    0.0003    0.4141
    0.0003    0.3493
    0.0001    0.1956
   -0.0000   -0.0116
   -0.0002   -0.2222
   -0.0003   -0.3840
   -0.0003   -0.4552
   -0.0003   -0.4152
   -0.0002   -0.2707
   -0.0000   -0.0546
    0.0001    0.1814
    0.0002    0.3792
    0.0003    0.4885
    0.0003    0.4794
    0.0002    0.3509
    0.0001    0.1316
   -0.0001   -0.1267
   -0.0002   -0.3607
   -0.0003   -0.5115
   -0.0003   -0.5395
   -0.0002   -0.4342
   -0.0001   -0.2181
    0.0000    0.0579
    0.0001    0.3270
    0.0002    0.5220
    0.0003    0.5926
    0.0002    0.5179
    0.0001    0.3127
    0.0000    0.0245
   -0.0001   -0.2772
   -0.0002   -0.5178
   -0.0002   -0.6361
   -0.0002   -0.5995
   -0.0002   -0.4133
   -0.0000   -0.1198
    0.0001    0.2106
    0.0002    0.4970
    0.0002    0.6671
    0.0002    0.6759
    0.0002    0.5173
    0.0001    0.2266
   -0.0000   -0.1272
   -0.0001   -0.4580
   -0.0002   -0.6830
   -0.0002   -0.7440
   -0.0002   -0.6220
   -0.0001   -0.3430
    0.0000    0.0274
    0.0001    0.3996
    0.0002    0.6813
    0.0002    0.8005
    0.0002    0.7241
    0.0001    0.4666
    0.0000    0.0878
   -0.0001   -0.3213
   -0.0002   -0.6597
   -0.0002   -0.8423
   -0.0002   -0.8202
   -0.0001   -0.5945
   -0.0001   -0.2167
    0.0001    0.2229
    0.0001    0.6166
    0.0002    0.8661
    0.0002    0.9065
    0.0002    0.7233
    0.0001    0.3572
   -0.0000   -0.1050
   -0.0001   -0.5507
   -0.0002   -0.8693
   -0.0002   -0.9793
   -0.0002   -0.8492
   -0.0001   -0.5064
   -0.0000   -0.0313
    0.0001    0.4611
    0.0002    0.8493
    0.0002    1.0350
    0.0002    0.9684
    0.0001    0.6609
    0.0000    0.1839
   -0.0001   -0.3479
   -0.0001   -0.8040
   -0.0002   -1.0700
   -0.0002   -1.0766
   -0.0001   -0.8170
   -0.0001   -0.3505
    0.0000    0.2116
    0.0001    0.7319
    0.0002    1.0810
    0.0002    1.1694
    0.0001    0.9704
    0.0001    0.5277
   -0.0000   -0.0535
   -0.0001   -0.6322
   -0.0002   -1.0652
   -0.0002   -1.2428
   -0.0002   -1.1164
   -0.0001   -0.7118
   -0.0000   -0.1241
    0.0001    0.5048
    0.0001    1.0202
    0.0002    1.2925
    0.0002    1.2503
    0.0001    0.8985
    0.0000    0.3185
   -0.0000   -0.3503
   -0.0001   -0.9441
   -0.0002   -1.3149
   -0.0002   -1.3673
   -0.0001   -1.0828
   -0.0001   -0.5259
    0.0000    0.1702
    0.0001    0.8361

type lab1-13.m

 Получите графики обозначенных функций в диапазоне -30<x<30 с раз-
 бивкой на 500 участков. Для зтого задайте команду :
   >> fplot ('prim',  [-30 30], 500)
 Выйдите из окна демонстрации. Рассмотрите графики более детально
 в интересующем диапазоне -7<x<0,  для чего вместо диапазона [-30 30]
 используйте диапазон [-6 -3]. Количество участков разбивки задайте
 равным 100. Запишите ответ на поставленный вопрос по экстремумам
 функций.
 На этом лабораторная работа №1 закончена. Убедитесь, что у вас есть
 все необходимые материалы для оформления отчета.

fplot ('prim',  [-30 30], 500)
