//Задание начальных условий
clear; xdel(winsid());

//функция проверки списка
function x=check_list(a, b)
	x=0;
	for i=1:length(a)
		if a(i)(1) == b(1) & a(i)(2) == b(2) then
			x = i;
		end
	end
endfunction

//выбор минимального значения из списка
function x=min_list(a)
	y = zeros(length(a));
	for i = 1:length(a)
		y(i) = a(i)(3);
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
open_list = list([s_pos(1) s_pos(2) 0 0 0 0]);
close_list = list();
//Весовые коэффициенты
kc=1;
kh=1;
//Начало цикла проверки. Осматриваем каждую соседнюю клетки относительно текущей
while check_list(open_list,[e_pos(1) e_pos(2)]) == 0
	a = min_list(open_list)
	c = open_list(a)(4)+1;
	//1
	if map(open_list(a)(1)+1, open_list(a)(2)) ~= 1 & check_list(close_list,[open_list(a)(1)+1 open_list(a)(2)]) == 0 then
		h=abs(e_pos(1)-open_list(a)(1)+1) + abs(e_pos(2)-open_list(a)(2));
		f=kc*c+kh*h;
		index=check_list(open_list, [open_list(a)(1)+1 open_list(a)(2)])
		if index== 0 then
			open_list($+1)=[open_list(a)(1)+1 open_list(a)(2) f c open_list(a)(1) open_list(a)(2)]
		elseif open_list(index)(3)>f then
			open_list(index)(3)=f;
			open_list(index)(4)=c;
			open_list(index)(5)=open_list(a)(1);
			open_list(index)(6)=open_list(a)(2);
		end
	end
	//2
	if map(open_list(a)(1)-1, open_list(a)(2)) ~= 1 & check_list(close_list,[open_list(a)(1)-1 open_list(a)(2)]) == 0 then
		h=abs(e_pos(1)-open_list(a)(1)) + abs(e_pos(2)-open_list(a)(2)+1);
		f=kc*c+kh*h;
		index=check_list(open_list, [open_list(a)(1)-1 open_list(a)(2)])
		if index== 0 then
			open_list($+1)=[open_list(a)(1)-1 open_list(a)(2) f c open_list(a)(1) open_list(a)(2)]
		elseif open_list(index)(3)>f then
			open_list(index)(3)=f;
			open_list(index)(4)=c;
			open_list(index)(5)=open_list(a)(1);
			open_list(index)(6)=open_list(a)(2);
		end
	end
	//3
	if map(open_list(a)(1), open_list(a)(2)+1) ~= 1 & check_list(close_list,[open_list(a)(1) open_list(a)(2)+1]) == 0 then
		h=abs(e_pos(1)-open_list(a)(1)) + abs(e_pos(2)-open_list(a)(2)+1);
		f=kc*c+kh*h;
		index=check_list(open_list, [open_list(a)(1) open_list(a)(2)+1])
		if index== 0 then
			open_list($+1)=[open_list(a)(1) open_list(a)(2)+1 f c open_list(a)(1) open_list(a)(2)]
		elseif open_list(index)(3)>f then
			open_list(index)(3)=f;
			open_list(index)(4)=c;
			open_list(index)(5)=open_list(a)(1);
			open_list(index)(6)=open_list(a)(2);
		end
	end
	//4
	if map(open_list(a)(1), open_list(a)(2)-1) ~= 1 & check_list(close_list,[open_list(a)(1) open_list(a)(2)-1]) == 0 then
		h=abs(e_pos(1)-open_list(a)(1)) + abs(e_pos(2)-open_list(a)(2)-1);
		f=kc*c+kh*h;
		index=check_list(open_list, [open_list(a)(1) open_list(a)(2)-1])
		if index== 0 then
			open_list($+1)=[open_list(a)(1) open_list(a)(2)-1 f c open_list(a)(1) open_list(a)(2)]
		elseif open_list(index)(3)>f then
			open_list(index)(3)=f;
			open_list(index)(4)=c;
			open_list(index)(5)=open_list(a)(1);
			open_list(index)(6)=open_list(a)(2);
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
map = map/ (max(map)*1);
figure(1);clf;
hist3d(map);
figure(2);clf;
hist3d(map1);
