//Задание начальных условий
clear; xdel(winsid());

//функция проверки списка
function x=check_list(pointList, Point)
	x=0;
	for i=1:length(pointList)
		if pointList(i)(1) == Point(1) & pointList(i)(2) == Point(2) then
			x = i; // записываем индекс точки
		end
	end
endfunction

//выбор минимального значения из списка
function x=min_list(pointList)
	y = zeros(length(pointList));
	for i = 1:length(pointList)
		y(i) = pointList(i)(3);
	end
	[z x] = min(y);
endfunction

//Создание карты
size_ = 32;
data = read ('goo1.txt', size_*size_, 1);
map = zeros(size_,size_);
i = 1;
j = 1;
k = 0;
for i =1:size_
	for j=1:size_
		map(i,j)=data(k*size_+j);
	end
	k=k+1;
end

//Начальная и конечная точка
s_pos = [3 3];
e_pos = [30 30];
map(s_pos(1), s_pos(2)) = -10;
map(e_pos(1), e_pos(2)) = -20;
map1 = map;
//Определение открытого и закрытого списка
//[	1,2- родительская точка; 3-стоимость пути ; 4 - расстояние от начала до текущей точки ;5,6- координаты текущей точки ]
open_list = list([s_pos(1) s_pos(2) 0 0 0 0]);
close_list = list();
//Весовые коэффициенты
kg=0.6;
kh=0.4;
//Начало цикла проверки. Осматриваем каждую соседнюю клетки относительно текущей
while check_list(open_list,[e_pos(1) e_pos(2)]) == 0
	a = min_list(open_list) // интекс минимальной (текущей) точки
	g = open_list(a)(4)+1;

	side_p_Xm =[
        open_list(a)(1)+1 	 
        open_list(a)(1)-1
        open_list(a)(1)	
        open_list(a)(1)	
    ];

	side_p_Ym =[
        open_list(a)(2)
        open_list(a)(2)
       	open_list(a)(2)+1
        open_list(a)(2)-1
    ];

    for i = 1:4
       // side_p(i)
		side_p_x = side_p_Xm(i);
		side_p_y = side_p_Ym(i);
		// проверка на препядствие и эта точка не в закрытом листе
		if map(side_p_x, side_p_y) ~= 1 & check_list(close_list,[side_p_x side_p_y]) == 0 then
			h=abs(e_pos(1)-side_p_x) + abs(e_pos(2)-side_p_y);
			f=kg*g+kh*h; // стоимость пути
			index=check_list(open_list, [side_p_x side_p_y])
			if index== 0 then // если точка не находится в открытом списке
				open_list($+1)=[side_p_x side_p_y f g open_list(a)(1) open_list(a)(2)]
			elseif open_list(index)(3)>f then
				open_list(index)(3)=f;
				open_list(index)(4)=g;
				open_list(index)(5)=open_list(a)(1);
				open_list(index)(6)=open_list(a)(2);
			end
		end

			  
    end  

	close_list($+1)=open_list(a);
	map(open_list(a)(1),open_list(a)(2))=open_list(a)(3);
	open_list(a)=null();
end

//Построение пути от начальной до конечной точки
path=list(close_list($));
while check_list(path, [s_pos(1),s_pos(2)]) == 0
	path($+1)=close_list(check_list(close_list,[path($)(5) path($)(6)]));
	map1(path($)(1), path($)(2))=10;
end
figure(1);clf;
hist3d(map);
figure(2);clf;
hist3d(map1);
