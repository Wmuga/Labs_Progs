program Lab3;

{$APPTYPE CONSOLE}

uses
  SysUtils,
  HashFunc in 'HashFunc.pas',
  Equal in 'Equal.pas',
  TypesConst in 'TypesConst.pas';

  const HashTest = ['a','c','e','p'];
var len:Integer;
begin
  len:=0;
  GetData(ArStart,ArEnd,len);
  ShowRes(len); 
  Readln;
end.
