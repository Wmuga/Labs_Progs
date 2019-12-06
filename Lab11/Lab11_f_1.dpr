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

procedure data_out(const n:Integer; const M:matrix; const name:char; const product:int64; const X:intarr; var outputdata:TextFile);
var i,i1:Byte;
begin
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
end;

procedure search_min(const productA:Int64; const productB:Int64; const productC:Int64; var outputdata:TextFile);
begin
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
end;

const max_value = 5;
var
  M:matrix;
  X:intarr;
  n:Integer;
  product:array[0..ar_length] of int64;
  in_data,fout:TextFile;

begin
  setConsoleCP(1251);
  setConsoleOutputCP(1251);

  AssignFile(in_data,ParamStr(1));
  Reset(in_data);

  get_data(nA,A,in_data);
  get_data(nB,B,in_data);
  get_data(nC,C,in_data);

  CloseFile(in_data);

  productA:=processing(nA,A,XA);
  productB:=processing(nB,B,XB);
  productC:=processing(nC,C,XC);

  AssignFile(fout,ParamStr(2));
  Rewrite(fout);

  data_out(nA,A,'A',productA,XA,fout);
  data_out(nB,B,'B',productB,XB,fout);
  data_out(nC,C,'C',productC,XC,fout);

  search_min(productA,productB,productC,fout);
  CloseFile(fout);
end.
