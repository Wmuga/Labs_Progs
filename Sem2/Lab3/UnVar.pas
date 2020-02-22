unit UnVar;

interface

uses UnLab3;  // описание типа и все процедуры
var NachaloSpiska, KonecSpiska: PElem; // начало и конец списка

implementation
  // пусто

initialization
  NachaloSpiska:=nil;  // инициализация переменных
  KonecSpiska:=nil;
finalization
  FreeList(NachaloSpiska, KonecSpiska);  // освобождение памяти
end.

