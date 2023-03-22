clear; xdel(winsid());

/*
1 вар

если уже в открытом списке, проверяем текущую Ф бол
*/
function s=f(h,g)
    s = (h(1))
    
endfunction


size_ = 32;
map = zeros(size_,size_);
map(1,:) = 1;
map(size_,:) = 1;
map(:,1) = 1;
map(:,size_) = 1;



// отображение

figure(1); clf;
hist3d(map);
