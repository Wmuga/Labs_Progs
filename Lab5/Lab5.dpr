program Lab5;

{$APPTYPE CONSOLE}

uses
  SysUtils;

const max_value = 20;
const ar_len = 30;


var
  in_data,out_data:TextFile;
  i,n,num:Integer;
  minAbs:Real;
  A:array[0..ar_len] of real;
  cont:Boolean;


begin
  AssignFile(in_data,ParamStr(1));
  Reset(in_data);
  AssignFile(out_data,ParamStr(2));
  rewrite(out_data);

  Readln(in_data,n);
  if (n>31) then
  begin
    Writeln(out_data,'Неверное n. n>20');
    CloseFile(in_data);
    CloseFile(out_data);
    Exit;
  end;
  if (n<0) then
  begin
    Writeln(out_data,'Неверное n. n<0');
    CloseFile(in_data);
    CloseFile(out_data);
    Exit;
  end;


  cont:=True;

  for i:=0 to n-1 do
  begin
    read(in_data,A[i]);
    if (Abs(A[i])>max_value) then
    begin
      Writeln(out_data,'Неверное |A[',i+1,']|>',max_value);
      cont:=False;
    end;
  end;

  if (cont=False) then
  begin
      CloseFile(in_data);
      CloseFile(out_data);
      exit;
  end;

  writeln(out_data,'Лабораторная работа №5':50);
  writeln(out_data,'');

  writeln(out_data,'Количество элементов массива n = ':55, n);
  writeln(out_data,'');


  writeln(out_data,'Элементы массива A:':50);
  for i:=0 to n-1 do
  begin
    writeln(out_data,A[i]:37:1);
  end;
  Writeln(out_data,'');

  minAbs:=max_value ;
  num:=1;
  for i:=0 to n-1 do
  begin
    if minAbs>Abs(A[i]) then
    begin
      minAbs:=Abs(A[i]);
      num:=i+1;
    end;
  end;
  writeln(out_data,'---------------------------------------------------------------');
  writeln(out_data,'Минимальное абсолютное значение элемнтов массива находится под номером ', num);
  CloseFile(in_data);
  CloseFile(out_data);
  end.
