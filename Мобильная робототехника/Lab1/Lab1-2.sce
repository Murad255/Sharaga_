clear; xdel(winsid());

mn = 100; //количество измерений
b_size = mn+1;
dt = 1; //период измерения

data = read('goo1.txt', 3*b_size, 1);

//показания 1 датчика высоты 
x(1,:) = data(1:b_size);
//показания 2 датчика скорости
x(2,:) = data(b_size+1:2*b_size);
//вектор измерений
z = data(2*b_size+1:$);

//начальный вектор состояния
x_0 = [0; 
       4];
//начальная матрица ковариации
P_0 = [10 0;
       0  1];
//матрица динамики     
A = [1 dt;
     0  1];
     
R = [0  0;
     0  3];
// матрица управления   
B = [0; 0];
//вектор управляющих воздействий
u = 0;
//матрица измерений
C = [1 0];
//матрица ковариации шумов измерений
Q =  2;

x_est = zeros(2, b_size);
P_est = zeros(2,2, b_size);

x_est(:,1) = x_0;
P_est(:,:,1) = P_0;

for i = 2:b_size

    x_pr = A*x_est(:,i-1) + B*u;   // матожидание
    P_pr = A*P_est(:,:,i-1)*A' + R;//матрица ковариации 

    // коррекция
    K = P_pr*C'*(C*P_pr*C'+Q)^-1; // коэффициент усиления Калмана
    x_est(:,i) = x_pr + K*(z(i) - C*x_pr); // матожидание 
    P_est(:,:,i) = (eye() - K*C)*P_pr; //матрица ковариации 

end

x_est_err = x_est(1,:) - x(1,:);//ошибка оценивания
V_est_err = x_est(2,:) - x(2,:);


//графики
figure(1); clf;
title('Истинное значение высоты, измерения и оценки высоты');
set(gca(),"auto_clear", "off"); xgrid(1,0.1,10);
plot(0:mn, x(1,:),'b');
plot(0:mn, z, 'r*');
plot(0:mn, x_est(1,:), 'g');
xlabel('Время, с');
ylabel('Высота, м');
legend('Истинное значение высоты', 'Измерение', 'Оценка');

figure(2);clf;
subplot(1,2,1); set(gca(),"auto_clear", "off"); xgrid(1,0.1,10);
title('СКО вертикальной скорости')
plot(0:mn, 3*sqrt(squeeze(P_est(2,2,:)))','r');
plot(0:mn, V_est_err, 'g');
plot(0:mn, -3*sqrt(squeeze(P_est(2,2,:)))','r');
xlabel('Время, с');
ylabel('СКО, м/c');
legend('3 sigma оценки','Действительная ошибка');

subplot(1,2,2); set(gca(),"auto_clear", "off"); xgrid(1,0.1,10);
title('СКО высоты')
plot(0:mn, 3*sqrt(squeeze(P_est(1,1,:)))','r');
plot(0:mn, 3*sqrt(Q)*ones(1,b_size),'b');
plot(0:mn, x_est_err, 'g');
plot(0:mn, -3*sqrt(squeeze(P_est(1,1,:)))','r');
plot(0:mn, -3*sqrt(Q)*ones(1,b_size),'b');
xlabel('Время, с');
ylabel('СКО, м');
legend('3 sigma оценки', '3 sigma измерений','Действительная ошибка');

figure(3); clf;
title('Истинное значение высоты, измерения и оценки высоты');
set(gca(),"auto_clear", "off"); xgrid(1,0.1,10);
plot(0:mn, x(2,:),'b');
plot(0:mn, x_est(2,:), 'g');
xlabel('Время, с');
ylabel('Высота, м');
legend('Истинное значение скорости', 'Оценка скорости по измерениям');


