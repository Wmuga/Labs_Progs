program Lab11;

{$APPTYPE CONSOLE}

uses
  SysUtils,
  Windows;

const ar_length = 5;

type matrix = array[0..ar_length-1,0..ar_length-1] of Integer;
type intarr = array[0..ar_length] of Integer;

procedure get_data(var nA:Integer; var nB:Integer; var nC:Integer; var A:matrix; var B:matrix; var C:matrix);
var i,i1:Byte; in_data:TextFile;
begin
  AssignFile(in_data,ParamStr(1));
  Reset(in_data);
  Readln(in_data,nA);
  for i:=0 to nA-1 do
  begin
    for i1:=0 to nA-2 do
    begin
      read(in_data,A[i][i1]);
    end;
    readln(in_data,A[i][nA-1]);
  end;
  Readln(in_data,nB);
  for i:=0 to nB-1 do
  begin
    for i1:=0 to nB-2 do
    begin
      read(in_data,B[i][i1]);
    end;
    readln(in_data,B[i][nB-1]);
  end;
  Readln(in_data,nC);
  for i:=0 to nC-1 do
  begin
    for i1:=0 to nC-2 do
    begin
      read(in_data,C[i][i1]);
    end;
    readln(in_data,C[i][nC-1]);
  end;
  CloseFile(in_data);
end;

procedure processing(const n:Integer; const M:matrix; var product:Int64; var x:intarr);
var i,i1:Byte; cont:Boolean;
begin
  cont:=False;
  for i:=0 to n-1 do
  begin
    for i1:=0 to n-1 do
    begin
      if ((M[i][i1]>=1) or (M[i1][i]>=1)) then cont:=True;
      product:=product*M[i][i1];
    end;
    if (cont) then x[i]:=1
    else x[i]:=0;
    cont:=False;
  end;
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
      write(outputdata,M[i][i1]:2);
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

begin
  setConsoleCP(1251);
  setConsoleOutputCP(1251);

  get_data(nA,nB,nC,A,B,C);

  productA:=1;
  productB:=1;
  productC:=1;

  processing(nA,A,productA,XA);
  processing(nB,B,productB,XB);
  processing(nC,C,productC,XC);

  data_out(nA,A,'A',productA,XA);
  data_out(nB,B,'B',productB,XB);
  data_out(nC,C,'C',productC,XC);

  search_min(productA,productB,productC);
end.
