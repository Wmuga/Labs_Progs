program lab3;

{$APPTYPE CONSOLE}

uses
  SysUtils,
  Windows;

const ar_length = 20;
var
  x,y:array[0..ar_length] of real;
  i,n,E,ChangedCount: integer;
  cont:Boolean;

begin
  setConsoleCP(1251);
  setConsoleOutputCP(1251);
  n:=-1;
  E:=-1;

  writeln('Введите количество элементов массивов');

  readln(n);
  if n<1 then Writeln('Некорректное n: n<1');
  if n>20 then Writeln('Некорректное n: n>20');
  if (n<1) or (n>20) then
  begin
    readln;
    exit;
  end;



  writeln('Введите критическое значение E');
  readln(E);
  if E<0 then Writeln('Некорректное E: E<0');
  if E>20 then Writeln('Некорректное E: E>20');
  if (E<0) or (E>20) then
  begin
    readln;
    exit;
  end;

  cont:=True;
  writeln('Введите элементы массивов'); //введение чисел массива
  for i:=0 to n-1 do
     begin
        Readln(x[i],y[i]);
        if Abs(x[i])>10 then  //проверка x[i]
        begin
          writeln('Неверное x[',i+1,']. |x[',i+1,'|>10.');
          cont:=False;
        end;

        if Abs(y[i])>10 then //проверка y[i]
        begin
          writeln('Неверное y[',i+1,']. |y[',i+1,']|>10.');
          cont:=False;
        end;
           end;

  if cont=False then
  begin
        writeln('END');
         readln;
          exit;
  end.


  Writeln('--------------------------------------------------------------------------------');
  
  writeln('Лабораторная работа №3':50);
  writeln;

  writeln('Количество элементов массивов n = ':55, n);
  writeln;

  writeln('Критическое значение E = ':50, E);
  writeln;

  writeln('Элементы массивов X, Y:':50);
  Writeln;

  for i:=0 to n-1 do
     begin
        writeln(x[i]:37:1,' ',y[i]:5:1);
     end;
  writeln;

  ChangedCount:= 0; 
  for i:=0 to n-1 do
  begin
        if (Abs(x[i]-y[i])<=E) then    //Обработка чисел
           begin
                 x[i]:=y[i];
                 ChangedCount:=ChangedCount + 1;
           end;
  end;

  writeln('--------------------------------------------------------------------------------');
  writeln('Выходные данные:':47);
  writeln;

  writeln('Элементы массивов X, Y:':50);
  Writeln;
  for i:=0 to n-1 do
     begin
        writeln(x[i]:37:1,' ',y[i]:5:1);
           end;
  Writeln;

  if (ChangedCount=0) then Writeln('Ничего не было изменено. ChangedCount = 0':60)
  else if (ChangedCount=n) then Writeln('Все ':20,n,' элементов были изменены. ChangedCount = ', n)
  else Writeln('Количество измененных элементов ChangedCount = ':60, ChangedCount);
  writeln;         
  Writeln('END');
  readln;
end.
