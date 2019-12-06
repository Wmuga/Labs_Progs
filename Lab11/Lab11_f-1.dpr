program Lab11;

{$APPTYPE CONSOLE}

uses
  SysUtils,
  Windows;

const ar_length = 5;
const max_m_count = 5;

type matrix = array[0..ar_length-1,0..ar_length-1] of Integer;
type intarr = array[0..ar_length] of Integer;
type int64arr = array[0..max_m_count] of int64;

procedure get_data(var n:Integer; var M:matrix; var in_data:TextFile);
var i,i1:Integer;
begin
  Readln(in_data,n);
  for i:=0 to n-1 do
  begin
    for i1:=0 to n-1 do
    begin
      read(in_data,M[i][i1]);
    end;
    readln(in_data);
  end;
end;

function processing(const n:Integer; const M:matrix;var x:intarr):int64;
var i,i1:Byte;product:int64;cont:Boolean;
begin
  product:=1;
  for i:=0 to n-1 do
  begin
    cont:=False;
    for i1:=0 to n-1 do
    begin
      product:=product*M[i][i1];
      if ((M[i][i1]>=1) or (M[i1][i]>=1)) then cont:=True;
    end;
    if (cont) then x[i]:=1
    else x[i]:=0;
  end;
  processing:=product;
end;

procedure data_out(const n:Integer; const M:matrix; const name:byte; const product:int64; const X:intarr; var outputdata:TextFile);
var i,i1:Byte;
begin
  if (name=0) then writeln(outputdata,'Лабораторная работа №11':55);
  writeln(outputdata,'');

  writeln(outputdata,'Размерность матрицы ',name,' = ', n, '*',n);
  writeln(outputdata,'');

  writeln(outputdata,'Матрица ',name,':');
  for i:=0 to n-1 do
  begin
    write(outputdata,' ':10);
    for i1:=0 to n-1 do
    begin
      write(outputdata,M[i][i1]:3);
    end;
    Writeln(outputdata);
  end;
  writeln(outputdata);
  writeln(outputdata);
  writeln(outputdata,'Произведение всех элементов матрицы = ', product);
  writeln(outputdata);
  writeln(outputdata,'Полученный массив X-',name,':');
  for i:=0 to n-1 do
     begin
        write(outputdata,X[i], ' ');
     end;
  writeln(outputdata);
  Writeln(outputdata,'--------------------------------------------------------------------------------');
end;

procedure search_min(const product:int64arr; const n:Integer; var outputdata:TextFile);
var min_prod:Int64; i,num:Integer;
begin
   Writeln(outputdata);
   num:=0;
   min_prod:=product[i];
   for i:=1 to n-1 do
   begin
     if product[i]<min_prod then
     begin
       num:=i;
       min_prod:=product[i];
     end;
   end;
   Writeln(outputdata,'Наименьшее произведение элементов у матрицы ',num,'(',product[num],')');
end;

const max_value = 5;
var
  M:matrix;
  X:intarr;
  i,n,m_count:Integer;
  product:int64arr;
  in_data,fout:TextFile;

begin
  setConsoleCP(1251);
  setConsoleOutputCP(1251);

  AssignFile(in_data,ParamStr(1));
  Reset(in_data);
  AssignFile(fout,ParamStr(2));
  Rewrite(fout);

  Readln(in_data,m_count);

  for i:=0 to m_count-1 do
  begin
    get_data(n,M,in_data);
    product[i]:=processing(n,M,X);
    data_out(n,M,i,product[i],X,fout);
  end;

  search_min(product,m_count,fout);

  CloseFile(in_data);
  CloseFile(fout);
end.
