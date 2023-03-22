function outlink = transferlink (link, theta, t)
% Вращение и перенос звена манипулятора
%Для правильной работы команды patch (для отображения робота) необходимо создать структуру
% с полями .vertices - массив с координатами вершин, .faces - массив с номерами вершин, образующих
% стороны (звена)
outlink.faces=link.faces;
c = cos(theta);
s = sin(theta);
outlink.vertices = bsxfun(@plus, link.vertices*[c s; -s c], t);
