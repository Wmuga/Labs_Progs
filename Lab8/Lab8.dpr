program Lab8;

{$APPTYPE CONSOLE}

uses
  SysUtils,
  Windows;

const ar_length = 20;
const inp_file = 'in\input.txt';
const out_file = 'out\output.txt';
const max_value = 9;
var
  B:array[0..ar_length*ar_length] of real;
  X:array[0..ar_length] of Integer;
  i,i1,n:Integer;
  inputdata,outputdata: TextFile;
  cont:Boolean;

begin
  setConsoleCP(1251);
  setConsoleOutputCP(1251);

  AssignFile(inputdata,inp_file);
  Reset(inputdata);
  AssignFile(outputdata,out_file);
  rewrite(outputdata);
  Readln(inputdata,n);

  if (n>ar_length+1) then
  begin
    Writeln(outputdata,'Неверное n. n>', ar_length+1);
    CloseFile(inputdata);
    CloseFile(outputdata);
    Exit;
  end;
  if (n<0) then
  begin
    Writeln(outputdata,'Неверное n. n<0');
    CloseFile(inputdata);
    CloseFile(outputdata);
    Exit;
  end;

  for i:=0 to n-1 do
  begin
    for i1:=0 to n-2 do
    begin
      read(inputdata,B[i*n+i1]);
    end;
    readln(inputdata,B[i*n+n-1]);
  end;


  CloseFile(inputdata);


  writeln(outputdata,'Лабораторная работа №8':55);   //Вывод данных write/writeln(переменная,текст)
  writeln(outputdata,'');

  writeln(outputdata,'Размерность матрицы n*n = ':55, n, '*',n);
  writeln(outputdata,'');

  writeln(outputdata,'Матрица B:':50);
  for i:=0 to n-1 do
  begin
    write(outputdata,' ':38);
    for i1:=0 to n-1 do
    begin
      write(outputdata,B[i*n+i1]:4:1);
    end;
    Writeln(outputdata,'');
  end;
  Writeln(outputdata,'');

  cont:=True;
  for i:=0 to n-1 do
  begin
    i1:=0;
    while ((cont) and (i1<n)) do
    begin
      if ((B[i*n+i1]<1) or (B[i+i1*n]<1)) then cont:=False;
      Inc(i1);
    end;
    if (cont) then x[i]:=1
    else x[i]:=0;
    cont:=True;
  end;

  writeln(outputdata);
  Writeln(outputdata,'--------------------------------------------------------------------------------');
  writeln(outputdata);
  writeln(outputdata,'Полученный массив X:':50);
  for i:=0 to n-1 do
     begin
        write(outputdata,X[i], ' ');
     end;
  writeln(outputdata);

  CloseFile(outputdata);
  Writeln('END');
  readln;
end.
