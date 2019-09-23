program lab4;

{$APPTYPE CONSOLE}

uses
  SysUtils,
  Windows;

const ar_length = 20;
const inp_file = 'input.txt';
const out_file = 'output.txt';
var
  x,y:array[0..ar_length] of real;
  i,n,E,ChangedCount: integer;
  inputdata,outputdata: TextFile;

begin
  setConsoleCP(1251);
  setConsoleOutputCP(1251);

  AssignFile(inputdata,inp_file);
  Reset(inputdata);
  AssignFile(outputdata,out_file);
  Rewrite(outputdata);

  Readln(inputdata,n);
  Readln(inputdata,E);
  for i:=0 to n-1 do
  begin
    read(inputdata,x[i]); readln(inputdata,y[i]);
  end;

  CloseFile(inputdata);

  Writeln('--------------------------------------------------------------------------------');
  
  writeln('Лабораторная работа №4':50);
  writeln;

  writeln('Количество элементов массивов n = ':55, n);
  writeln;

  writeln('Критическое значение E = ':50, E);
  writeln;

  writeln('Элементы массивов X, Y:':50);
  Writeln;

  ChangedCount:= 0;
  
  for i:=0 to n-1 do
     begin
        writeln(x[i]:37:1,' ',y[i]:5:1);
        if (Abs(x[i]-y[i])<=E) then    //Обработка чисел
           begin
                 x[i]:=y[i];
                 ChangedCount:=ChangedCount + 1;
           end;
     end;
  writeln;

  rewrite(outputdata);
  writeln(outputdata,'Лабораторная работа №4':50);
  writeln(outputdata);

  writeln(outputdata,'Элементы массивов X, Y:':50);
  Writeln;
  for i:=0 to n-1 do
     begin
        writeln(outputdata,x[i]:37:1,' ',y[i]:5:1);
           end;
  Writeln;

  if (ChangedCount=0) then Writeln(outputdata,'Ничего не было изменено. ChangedCount = 0':60)
  else if (ChangedCount=n) then Writeln(outputdata,'Все ':20,n,' элементов были изменены. ChangedCount = ', n)
  else Writeln(outputdata,'Количество измененных элементов ChangedCount = ':60, ChangedCount);
  CloseFile(outputdata);         

  readln;
end.
