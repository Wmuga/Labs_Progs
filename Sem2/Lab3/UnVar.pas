unit UnVar;

interface

uses UnLab3;  // �������� ���� � ��� ���������
var NachaloSpiska, KonecSpiska: PElem; // ������ � ����� ������

implementation
  // �����

initialization
  NachaloSpiska:=nil;  // ������������� ����������
  KonecSpiska:=nil;
finalization
  FreeList(NachaloSpiska, KonecSpiska);  // ������������ ������
end.

