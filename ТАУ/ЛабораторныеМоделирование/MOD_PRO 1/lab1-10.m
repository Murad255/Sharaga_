����� � ������� ������ ���������� �-�������.  ����������  ���
���� ������: �-�������� � �-�������.
�������� �������� ���������� ����� �-�����. �  ���  �����������
��� �������,  ��� � �������� ���������. ��� �������� ��������� ��-
�������������  ����������  ������������������  ������-������.
���� �� �� ���� �-���������,  �� ������ ����� ������� ��������
�� ������� ���� �� ������ �� ���������  ������.  ��������  ������
�-��������.

������ �����������          %�-file peetals - ������� �������
                                           x=-pi:.01:pi;
���� ����������             y(1, : )=2*sin(5*x).^2;
������� �������              y(2, : )=cos(10*x).^3;
�(1), �(2),�(3), �(4)               y(3, : )=sin(x).^2;
������ �(4)=�(1)+�(3)        y(4, : )=y(1, : )+y(3, : );

                                                 for i=1:4
������ ������������                 plot(x, y(i, : ))
������ � ������������               pause
�������� � ���������                   end
������                                      clf, close;

� �����-�������� ����������� ������ ���� ������ �����������.
����� ��������� ��� ����������,  � ��������� ������  �������
������� peetals � ������� Enter. ����� ������ ������� ��������
��������� ������������� �����. ��� ������������� ������ ��-
�������� ������� ����� �������.��������� ��������� ��� �������
������� � �������� �������, � ������� �� ���������.
����� ����� ������� ������� type lab1-11.m