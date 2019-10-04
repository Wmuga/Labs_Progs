program lab4;

{$APPTYPE CONSOLE}

uses
  SysUtils,
  Windows;

const ar_length = 20;
const inp_file = 'input_files/input.txt';
const out_file = 'output.txt';
var
  x,y:array[0..ar_length] of real;
  i,n,E,ChangedCount: integer;
  inputdata,outputdata: TextFile;
  cont: Boolean;

begin
  setConsoleCP(1251);
  setConsoleOutputCP(1251);

  AssignFile(inputdata,inp_file);  //Подключаем входного файла  AssignFile(перменная, название файла)
  Reset(inputdata);                //Открытие файла на чтение Reset(переменная)
  AssignFile(outputdata,out_file); //Подключаем файл на вывод
  rewrite(outputdata);             //Открытие файла на перезапись  Rewrite(переменная)
  Readln(inputdata,n);             //Чтение из файла Read/Readln(переменная,куда)
  if (n>21) then
  begin
    Writeln(outputdata,'Неверное n. n>20');
    CloseFile(inputdata);
    CloseFile(outputdata);              //Закрытие файла  CloseFile(перменная)
    Exit;
  end;
  if (n<0) then
  begin
    Writeln(outputdata,'Неверное n. n<0');
    CloseFile(inputdata);
    CloseFile(outputdata);
    Exit;
  end;
  Readln(inputdata,E);
  if (E>14) then
  begin
    Writeln(outputdata,'Неверное E. E>14');
    CloseFile(inputdata);
    CloseFile(outputdata);
    Exit;
  end;
  if (E<0) then
  begin
    Writeln(outputdata,'Неверное E. E<0');
    CloseFile(inputdata);
    CloseFile(outputdata);
    Exit;
  end;
  cont:=True;
  for i:=0 to n-1 do
  begin
    read(inputdata,x[i]); readln(inputdata,y[i]);
    if (Abs(x[i])>10) then
    begin
      Writeln(outputdata,'Неверное X[',i+1,']>10');
      cont:=False;
    end;
    if (Abs(y[i])>10) then
    begin
      Writeln(outputdata,'Неверное Y[',i+1,']>10');
      cont:=False;
    end;
  end;

  if (cont=False) then
  begin
      CloseFile(inputdata);
      CloseFile(outputdata);
      exit;
  end;

  CloseFile(inputdata);


  writeln(outputdata,'Лабораторная работа №4':50);   //Вывод данных write/writeln(переменная,текст)
  writeln(outputdata,'');

  writeln(outputdata,'Количество элементов массивов n = ':55, n);
  writeln(outputdata,'');

  writeln(outputdata,'Критическое значение E = ':50, E);
  writeln(outputdata,'');

  writeln(outputdata,'Элементы массивов X, Y:':50);
  for i:=0 to n-1 do
  begin
    writeln(outputdata,x[i]:37:1,' ',y[i]:5:1);
  end;
  Writeln(outputdata,'');

  ChangedCount:= 0;


  for i:=0 to n-1 do
     begin
        if (Abs(x[i]-y[i])<=E) then    //Обработка чисел
           begin
                 x[i]:=y[i];
                 ChangedCount:=ChangedCount + 1;
           end;
     end;

  writeln(outputdata);
  Writeln(outputdata,'--------------------------------------------------------------------------------');
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
  Writeln('END');
  readln;
end.
