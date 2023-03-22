function rect = rectanglelink (x1, x2, y1, y2)
%Создание прямоугольника для отображения звена манипулятора
rect.vertices=[x1 y1; x2 y1; x2 y2; x1 y2];
rect.faces = [1 2 3 4];