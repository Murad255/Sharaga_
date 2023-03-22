//Задание начальных условий
clear; xdel(winsid());

// возвращает индекс точки в списке 
// 0 - точки нет в списке
function iPoint=in_list(pointList, Point)
	iPoint=0;
	for i=1:length(pointList)
		if pointList(i)(1) == Point(1) & pointList(i)(2) == Point(2) then
			iPoint = i; // записываем индекс точки
			break
		end
	end
endfunction

//выбор минимального значения из списка
function x = search_min(pointList)
	y = zeros(length(pointList));
	for i = 1:length(pointList)
		y(i) = pointList(i)(3);
	end
	[z x] = min(y);
endfunction

function  f = path_cost(g,h)
	//Весовые коэффициенты
	kg=0.1; kh=1;
	f=kg*g+kh*h; // стоимость пути 
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
map(e_pos(1), e_pos(2)) = -15;
map1 = map;
//Определение открытого и закрытого списка
//[	1,2- родительская точка; 3-стоимость пути ; 4 - расстояние от начала до текущей точки ;5,6- координаты точки ]
open_list = list([s_pos(1) s_pos(2) 0 0 0 0]);
close_list = list();

//Начало цикла проверки. Осматриваем каждую соседнюю клетки относительно текущей
while in_list(open_list,[e_pos(1) e_pos(2)]) == 0
	t = search_min(open_list) // интекс минимальной (текущей) точки
	side_p =[
        open_list(t)(1)+1 open_list(t)(2);
        open_list(t)(1)-1 open_list(t)(2);
        open_list(t)(1) open_list(t)(2)+1;
        open_list(t)(1) open_list(t)(2)-1;
	];

    for i = 1:4
		// проверка на препядствие и эта точка не в закрытом листе
		if map(side_p(i,1), side_p(i,2)) ~= 1 & in_list(close_list,side_p(i,:)) == 0 then
			g = open_list(t)(4)+1;//+map(side_p(i,1), side_p(i,2)); 	// путь от начала (Дейкстра) 
			h=abs(e_pos(1)-side_p(i,1)) + abs(e_pos(2)-side_p(i,2)); 	// расстояние до конца
			f=path_cost(g,h); // стоимость пути 
			i_point=in_list(open_list,side_p(i,:));
			// если точка не находится в открытом списке
			if i_point== 0 then 
				open_list($+1)=[side_p(i,1) side_p(i,2) f g open_list(t)(1) open_list(t)(2)]
			// если она в списке, но рассчитан более выгодный маршрут
			elseif open_list(iPoint)(3)>f then 
				open_list(i_point)(3)=f;
				open_list(i_point)(4)=g;
				open_list(i_point)(5)=open_list(t)(1);
				open_list(i_point)(6)=open_list(t)(2);
			end

		end	  
    end  

	close_list($+1)=open_list(t);
	map(open_list(t)(1),open_list(t)(2))=open_list(t)(3);
	open_list(t)=null();
end

//Построение пути от начальной до конечной точки
path=list(close_list($));
map1(path($)(1), path($)(2))=10;

while in_list(path, [s_pos(1),s_pos(2)]) == 0
	path($+1)=close_list(in_list(close_list,[path($)(5) path($)(6)]));
	map1(path($)(1), path($)(2))=10; 
end

map = map/ (max(map)*1);
figure(3);//clf;
subplot(1,2,1);
title('проверенные точки')
hist3d(map);
subplot(1,2,2); 
title('итоговый маршрут')
hist3d(map1);
