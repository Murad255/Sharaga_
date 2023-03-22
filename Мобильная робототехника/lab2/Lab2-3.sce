clear; xdel(winsid());

size_ = 32;
map = zeros(size_,size_);
data = read('goo1.txt', size_*size_, 1);

for i = 1:size_
    map(i,:) = data((i-1)*size_ +1:i*size_ )
end

s_pos = [3 3];
e_pos = [30 30];

open_list = list ([s_pos(1) s_pos(2) 0 0 0 0])
close_list =  list ()



function cost=f_cost(h,g)
    s = abs(h(1) - g(1))+ abs(h(1) - g(1));   
endfunction

function flag=in_list(point)
    if (open_list(point(1),point(2))>0 ) return true;
        else return false;
endfunction


current_point = s_pos ;
min_point_pos = zeros(2);
min_point_cost = 999999999
while true:
    side_p =[
        [current_point(1) current_point(2)+1] 
        [current_point(1) current_point(2)-1]
        [current_point(1)+1 current_point(2)]
        [current_point(1)-1 current_point(2)]
    ];
    for i = 1:4 
        if in_list(side_p(i)) then
           cost = f_cost(side_p(i));
           open_list(side_p(i)(1),side_p(i)(2))=cost;
           
           if min_point_cost>cost then
               min_point_cost = cost
           end
        end
    end  
end

// отображение

figure(1); clf;
hist3d(map);
