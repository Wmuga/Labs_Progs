program Gen;

{$APPTYPE CONSOLE}

uses
  SysUtils;

var
   outp:TextFile;
   i,i1:Integer;
begin
  AssignFile(outp,'in/input6.txt');
  Rewrite(outp);
  Writeln(outp,'10 10');   //размерность
  for i:=0 to 9 do  // проходимся по размеру для своего удобства можешь использовать (1 to 10)
  begin                     //цикл для строкки
    for i1:=0 to 8 do       //цикл для элементов строки (1-9)
    begin                   //на один меньше т.к. после 10 нужен переход на следующую строку
      Write(outp,Random(9),' '); //выводим случайное число random(граница) 0-граница
    end;
    Writeln(outp,Random(9)); //выводим 10й и переходим на следующую строку
  end;
  CloseFile(outp);
end.
