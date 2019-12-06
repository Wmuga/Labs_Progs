program Lab10;

{$APPTYPE CONSOLE}

uses
  SysUtils;

const ar_len = 10;

type intarr = array[0..ar_len] of Integer;

procedure get_data(var n:Integer; var A:intarr);
var i:Byte; in_data:TextFile;
begin
  AssignFile(in_data,ParamStr(1));
  Reset(in_data);
  Readln(in_data,n);
  for i:=0 to n-1 do
  begin
    readln(in_data,A[i]);
  end;
  CloseFile(in_data);
end;

procedure find_elem(const n:Integer; const A:intarr; var num:Integer);
var i:Byte;
begin
  i:=0;
  while (i<n) and (num=-1) do
  begin
    if (A[i] mod 5 = 0) then num:=i+1;
    Inc(i);
  end;
  if num=-1 then num:=0;
end;

procedure search_value(const n:Integer; const A:intarr; const num:Integer; var min_value:Integer);
var i,min_v:Byte;
begin
  min_value:=A[num];
  for i:=num+1 to n-1 do
  begin
    min_v:=min_value;
    if (A[i]>0) and (A[i]<min_v) then min_value:=A[i];
  end;
end;

procedure data_out(const n:Integer; const A:intarr; const min_value:Integer; const num:Integer);
var i:Byte; out_data:TextFile;
begin
  AssignFile(out_data,ParamStr(2));
  rewrite(out_data);
  writeln(out_data,'Лабораторная работа №10':50);
  writeln(out_data,'');

  writeln(out_data,'Количество элементов массива n = ':55, n);
  writeln(out_data,'');

  write(out_data,'Элементы массива A: ':40);
  for i:=0 to n-1 do
  begin
    write(out_data,A[i],' ');
  end;
  Writeln(out_data,'');

  writeln(out_data,'---------------------------------------------------------------');
  if (min_value<0) then if (num>0) then Writeln(out_data,'Нет положительных элементов массива А, расположенного после ', num,' элемента массива')
  else Writeln(out_data,'Нет положительных элементов массива А')
  else if (num>0) then writeln(out_data,'Минимальный положительный элемент массива А, расположенный после ', num,' элемента массива равен ',min_value)
  else writeln(out_data,'Минимальный положитльный элемент массива А, расположенный после начала массива (нет кратных 5) равен ',min_value);
  CloseFile(out_data);
end;

var
  n,num,min_value:Integer;
  A:intarr;


begin
  get_data(n, A);

  num:=-1;

  find_elem(n, A, num);

  if (num=n) then min_value:=-1
  else
  search_value(n, A, num, min_value);

  data_out(n,A, min_value, num);
end.
