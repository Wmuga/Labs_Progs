program Lab5_1;

{$APPTYPE CONSOLE}

uses
  SysUtils;

const inp_file='input_files\input';
const out_file='output_files\output';
const max_value = 20;
const ar_len = 30;


var
  in_data,out_data:TextFile;
  i,z,n,k,num:Integer;
  minAbs:Real;
  A:array[0..ar_len] of real;
  cont:Boolean;
  inp_filename,out_filename:string;


begin
  read(k);
  for z:=1 to k do
  begin
  inp_filename:=inp_file+IntToStr(z)+'.txt';
  out_filename:=out_file+IntToStr(z)+'.txt';
  AssignFile(in_data,inp_filename);
  Reset(in_data);
  AssignFile(out_data,out_filename);
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
  end;
end.
