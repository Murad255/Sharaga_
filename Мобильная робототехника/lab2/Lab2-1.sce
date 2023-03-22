clear; close(winsid())//xdel(winsid());


size_= 32;
map = zeros(size_,size_);
data = read('goo1.txt', size_*size_, 1);

for i = 1:size_
    map(i,:) = data((i-1)*size_ +1:i*size_ )
end




// отображение

figure(1); clf;
hist3d(map);
