unit UnVar;

interface

uses UnLab3;  // описание типа и все процедуры
var NachaloSpiska, KonecSpiska: PElem; // начало и конец списка
    Dict : TStrSet;
    DictLen : Byte;

implementation
  // пусто

initialization
  NachaloSpiska:=nil;  // инициализация переменных
  KonecSpiska:=nil;
  GetDict(Dict,DictLen);
finalization
  WriteDict(Dict,DictLen); 
  FreeList(NachaloSpiska, KonecSpiska);  // освобождение памяти
end.

