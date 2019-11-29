program Lab11;

{$APPTYPE CONSOLE}

uses
  SysUtils,
  Windows;

const ar_length = 5;

type matrix = array[0..ar_length-1,0..ar_length-1] of Integer;
type intarr = array[0..ar_length] of Integer;

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

function processing(const n:Integer; const M:matrix):intarr;
var i,i1:Byte; cont:Boolean; x:intarr;
begin
  cont:=False;
  for i:=0 to n-1 do
  begin
    i1:=0;
    while (not cont) and (i1<n-1) do
    begin
      if ((M[i][i1]>=1) or (M[i1][i]>=1)) then cont:=True;
      Inc(i1);
    end;
    if (cont) then x[i]:=1
    else x[i]:=0;
    cont:=False;
  end;
  processing:=x;
end;

function product_calc(const n:Integer; const M:matrix):int64;
var i,i1:Byte;product:int64;
begin
  product:=1;
  for i:=0 to n-1 do
  begin
    for i1:=0 to n-1 do
    begin
      product:=product*M[i][i1];
    end;
  end;
  product_calc:=product;
end;

procedure data_out(const n:Integer; const M:matrix; const name:char; const product:int64; const X:intarr);
var i,i1:Byte; outputdata:TextFile;
begin
  AssignFile(outputdata,ParamStr(2));
  if name='A' then Rewrite(outputdata)
  else Append(outputdata);
  if (name='A') then writeln(outputdata,'Лабораторная работа №11':55);
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
  CloseFile(outputdata);
end;

procedure search_min(const productA:Int64; const productB:Int64; const productC:Int64);
var outputdata:TextFile;
begin
   AssignFile(outputdata, ParamStr(2));
   Append(outputdata);
   Writeln(outputdata);
   if productA>productB then
   begin
     if productB>productC  then Writeln(outputdata,'Минимальное произведение всех элементов массива у матрицы C (',productC,')')
      else Writeln(outputdata,'Минимальное произведение всех элементов массива у матрицы B (',productB,')');
   end
   else
   begin
     if productA<productC then Writeln(outputdata,'Минимальное произведение всех элементов массива у матрицы A (',productA,')')
     else Writeln(outputdata,'Минимальное произведение всех элементов массива у матрицы C (',productC,')');
   end;
   CloseFile(outputdata);
end;

const max_value = 5;
var
  A,B,C:matrix;
  XA,XB,XC:intarr;
  nA,nB,nC:Integer;
  productA,productB,productC:int64;
  in_data:TextFile;

begin
  setConsoleCP(1251);
  setConsoleOutputCP(1251);

  AssignFile(in_data,ParamStr(1));
  Reset(in_data);

  get_data(nA,A,in_data);
  get_data(nB,B,in_data);
  get_data(nC,C,in_data);

  CloseFile(in_data);

  productA:=product_calc(nA, A);
  productB:=product_calc(nB, B);
  productC:=product_calc(nC, C);

  XA:=processing(nA,A);
  XB:=processing(nB,B);
  XC:=processing(nC,C);

  data_out(nA,A,'A',productA,XA);
  data_out(nB,B,'B',productB,XB);
  data_out(nC,C,'C',productC,XC);

  search_min(productA,productB,productC);
end.
