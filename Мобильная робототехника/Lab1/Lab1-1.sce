clear; xdel(winsid());

mn = 100;
b_size = mn+1;
data = read("goo1.txt",3*b_size,1);

x(1,:) =data(1:b_size)';
x(2,:) = data(b_size+1: 2*b_size)';
z = data(2*b_size+1:$)';

x_0 =  [0;
        4];

p_0 = [ 10 0;
        0  1 ];
dt = 1;
A = [1 dt;
    0 1];
    
R = [ 0 0;
      0 3 ];

B = [0; 0];

u = 0;

C = [1 0];

Q = 2; // 0.1  10 попробовать с этим


x_est = zeros(2,b_size);
p_est = zeros(2,2,b_size);

x_est(:,1) = x_0;
p_est(:,:,1) = p_0;

for i = 2:b_size
    
    x_pr = A*x_est(:,i-1) + B*u;
    p_pr = A* p_est(:,:,i-1)*A'+R;
    
    K = p_pr*C'*(C*p_pr*C'+Q)^-1;
    x_est(:,i) = x_pr+K*(z(i-1)-C*x_pr);
    p_est(:,:,i)= (eye()-K*C)*p_pr;
end
x_est_err = x_est(1,:)-x(1,:);
V_est_err = x_est(2,:)- x(2,:);

figure(1); clf;
title('истинное значение высоты, измерения и оценки высоты');
set(gca(),"auto_clear","off");
xgrid(1,0.1,10);
plot(0:mn,x(1,:),'b' );
plot(0:mn,z,'r*' );
plot(0:mn,x_est(1,:),'g' );
xlabel('Время, с');
ylabel('Высота, с');
legend('Истинное значение высоты','измерение','оценка');




