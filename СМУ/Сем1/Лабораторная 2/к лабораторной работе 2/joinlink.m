function joinlink = joinlink (link1, link2)
%Присоединение двух звеньев
n1 = size(link1.vertices,1);
joinlink.vertices = [link1.vertices; link2.vertices];
joinlink.faces = [link1.faces; link2.faces + n1];