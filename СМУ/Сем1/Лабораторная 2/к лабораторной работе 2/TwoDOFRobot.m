function TwoDOFRobot = TwoDOFRobot (current_coords, l1, l2)
% Отображение робота с координатами current_coords (Tetta2 Tetta1)
h = 0.01;
l=[l2 l1];
link2 = rectanglelink(0,l(1),-h,h); % прямоугольник, равный длине 2-го звена
link1 = rectanglelink(0,l(2),-h,h); % прямоугольник, равный длине 1-го звена
TwoDOFRobot = joinlink (link1, transferlink(link2, current_coords(2), [l(2) 0]));
TwoDOFRobot = transferlink(TwoDOFRobot, current_coords(1), [0 0]);


