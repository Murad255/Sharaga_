function outlink = transferlink (link, theta, t)
% �������� � ������� ����� ������������
%��� ���������� ������ ������� patch (��� ����������� ������) ���������� ������� ���������
% � ������ .vertices - ������ � ������������ ������, .faces - ������ � �������� ������, ����������
% ������� (�����)
outlink.faces=link.faces;
c = cos(theta);
s = sin(theta);
outlink.vertices = bsxfun(@plus, link.vertices*[c s; -s c], t);
