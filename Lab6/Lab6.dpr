program Lab6;

{$APPTYPE CONSOLE}

uses
  SysUtils;

const inp_file='input.txt';
const out_file='output.txt';
const max_value = 20;
const ar_len = 30;


var
  in_data,out_data:TextFile;
  i,n,num,min_value:Integer;
  A:array[0..ar_len] of Integer;
  cont:Boolean;


begin
  AssignFile(in_data,inp_file);
  Reset(in_data);
  AssignFile(out_data,out_file);
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

  num:=-1;

  for i:=0 to n-1 do
  begin
    read(in_data,A[i]);
    if (A[i] mod 5 = 0) and (num=-1) then num:=i;
    if (Abs(A[i])>max_value) then
    begin
      Writeln(out_data,'Неверное |A[',i+1,']|>',max_value);
      cont:=False;
    end;
  end;

  if num=-1 then num:=0;

  if (cont=False) then
  begin
      CloseFile(in_data);
      CloseFile(out_data);
      exit;
  end;

  writeln(out_data,'Лабораторная работа №6':50);
  writeln(out_data,'');

  writeln(out_data,'Количество элементов массива n = ':55, n);
  writeln(out_data,'');


  writeln(out_data,'Элементы массива A:':50);
  for i:=0 to n-1 do
  begin
    writeln(out_data,A[i]:37);
  end;
  Writeln(out_data,'');

  min_value:=max_value;

  for i:=num to n-1 do
  begin
    if (A[i]>=0) and (A[i]<min_value) then min_value:=A[i];
  end;


  writeln(out_data,'---------------------------------------------------------------');
  writeln(out_data,'Минимальный элемент массива А, удовлетворяющий условие равен ',min_value);
  CloseFile(in_data);
  CloseFile(out_data);
  Writeln('Succesfull end');
  Readln;
end.
