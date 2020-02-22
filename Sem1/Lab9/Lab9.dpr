program Lab9;

{$APPTYPE CONSOLE}

uses
  SysUtils,
  Windows;

const ar_length = 10;
const max_value = 9;
var
  B:array[0..ar_length,0..ar_length] of real;
  i,i1,num,n1,n2:Integer;
  inputdata,outputdata: TextFile;
  cont,isZero,br:Boolean;

begin
  setConsoleCP(1251);
  setConsoleOutputCP(1251);

  AssignFile(inputdata,ParamStr(1));
  try
  Reset(inputdata);
  try
  AssignFile(outputdata,ParamStr(2));
  try
  rewrite(outputdata);
  try
  try

  read(inputdata,n1);
  readln(inputdata,n2);

  if (n1<1) then
  begin
    Writeln(outputdata,'Неверное n1(<1)');
    Exit;
  end;
  if (n1>ar_length) then
  begin
    Writeln(outputdata,'Неверное n1(>',ar_length,')');
    Exit;
  end;
  if (n2<1) then
  begin
    Writeln(outputdata,'Неверное n2(<1)');
    Exit;
  end;
  if (n2>ar_length) then
  begin
    Writeln(outputdata,'Неверное n2(>',ar_length,')');
    Exit;
  end;

  br:=False;

  for i:=0 to n1-1 do
  begin
    for i1:=0 to n2-2 do
    begin
      read(inputdata,B[i][i1]);
      if Abs(b[i][i1])>max_value then
      begin
        Writeln(outputdata,'Неверное B[',i,'][',i1,']');
        br:=True;
      end;
    end;
    readln(inputdata,B[i][n2-1]);
    if Abs(b[i][n2-1])>max_value then
      begin
        Writeln(outputdata,'Неверное B[',i,'][',n2-1,']');
        br:=True;
      end;
  end;

  if (br) then Exit;

  writeln(outputdata,'Лабораторная работа №9':55);   //Вывод данных write/writeln(переменная,текст)
  writeln(outputdata,'');

  writeln(outputdata,'Размерность матрицы n1*n2 = ':55, n1, '*',n2);
  writeln(outputdata,'');

  writeln(outputdata,'Матрица B:':50);
  for i:=0 to n1-1 do
  begin
    write(outputdata,' ':33);
    for i1:=0 to n2-1 do
    begin
      write(outputdata,B[i][i1]:4:1);
    end;
    Writeln(outputdata,'');
  end;
  Writeln(outputdata,'');

  cont:=True;
  i:=0;
  num:=-1;
  while ((cont) and (i<n1)) do
  begin
    i1:=0;
    isZero:=True;
    while ((isZero) and (i1<n2)) do
    begin
      if (B[i][i1]<>0) then isZero:=False;
      Inc(i1);
    end;
    Inc(i);
    if (isZero) then
    begin
      num:=i;
      cont:=False;
    end;
  end;

  writeln(outputdata);
  Writeln(outputdata,'--------------------------------------------------------------------------------');
  writeln(outputdata);
  if (num<>-1) then writeln(outputdata,'Номер первой нулевой строки: ', num)
  else writeln(outputdata,'Нет нулевых строк');
  except Writeln('Ошибка при чтении файла'); Readln;
  end;
  finally CloseFile(outputdata);
  end;
  except writeln('Ошибка при подключении выходного файла'); Readln;
  end;
  finally CloseFile(inputdata)
  end;
  except writeln('Ошибка при подключении входного файла');  readln;
  end;
end.
