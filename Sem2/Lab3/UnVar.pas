unit UnVar;

interface

uses UnLab3;  // �������� ���� � ��� ���������
var NachaloSpiska, KonecSpiska: PElem; // ������ � ����� ������
    Dict : TStrSet;
    DictLen : Byte;

implementation
  // �����

initialization
  NachaloSpiska:=nil;  // ������������� ����������
  KonecSpiska:=nil;
  GetDict(Dict,DictLen);
finalization
  WriteDict(Dict,DictLen); 
  FreeList(NachaloSpiska, KonecSpiska);  // ������������ ������
end.

