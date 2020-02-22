unit UT;

interface

uses
SysUtils,
  Windows;

const ar_length = 9;
const max_value = 9;
const max_E = 18;
const max_P = 9;

type matrix = array[0..ar_length-1,0..ar_length-1] of Integer;
type realarr = array[0..ar_length] of real;

function  get_data(var n:Integer; var M:matrix; var in_data:TextFile; var P:Integer; var E:Integer):Boolean;
function  checkData(const P:Integer; const E:Integer):Boolean;
function  checkMatrix(const n:Integer; const A:matrix):Boolean;
function  testValid(const n:Integer; const A:matrix; const P:Integer; const E:Integer):Boolean;
function  calc_av(const n:Integer; const A:Matrix):realarr;
procedure data_out(const n:Integer; const M:matrix; const P:Integer; const E:Integer; const x:realarr; var outputdata:TextFile);

implementation

function  get_data(var n:Integer; var M:matrix; var in_data:TextFile; var P:Integer; var E:Integer):boolean;
var i,i1:Integer; flag:Boolean;
begin
  flag:=True;
  Readln(in_data,n);
  if (n<1) then
  begin
    Writeln('Неверное n(<1)');
    flag:=False;
  end
  else if (n>ar_length) then
  begin
    Writeln('Неверное n(>',ar_length,')');
    flag:=False;
  end
  else
  begin
  Readln(in_data,P);
  Readln(in_data,E);
  for i:=0 to n-1 do
  begin
    for i1:=0 to n-1 do
    begin
      read(in_data,M[i][i1]);
    end;
    readln(in_data);
  end;
  end;
  get_data:=flag;
end;

function  checkData(const P:Integer; const E:Integer):boolean;
var flag:Boolean;
begin
  flag := True;
  if (E<0) then
  begin
    Writeln('Неверное E(<0)');
    flag := False;
  end
  else if (E>max_E) then
  begin
    Writeln('Неверное E(>',max_E,')');
    flag := False;
  end
  else if (P<-(max_P)) then
  begin
    Writeln('Неверное P(<',-(max_P),')');
    flag := False;
  end
  else if (P>max_P) then
  begin
    Writeln('Неверное P(>',max_P,')');
    flag := False;
  end;
  checkData:=flag;
end;

function  checkMatrix(const n:Integer; const A:matrix):Boolean;
var i,i1:Byte; err:Boolean;
begin
  i:=0;
  err:=False;
  while (i<n) and (not err) do
  begin
    i1:=0;
    while (i1<n) and (not err) do
    begin
      if Abs(A[i][i1])>max_value then
      begin
      err:=True;
      writeln('Элемент А[',i+1,',',i1+1,'] неверен');
      end;
      Inc(i1);
    end;
    Inc(i);
  end;
  checkMatrix:=not err;
end;

function  testValid(const n:Integer; const A:matrix; const P:Integer; const E:Integer):Boolean;
var i,i1:Byte; isValid:Boolean;
begin
  i:=0;
  isValid:=True;
  while (i<n) and (isValid) do
  begin
    i1:=0;
    while (i1<n) and (isValid) do
    begin
      if Abs((A[i][i1])-P)<E then isValid:=False;
      Inc(i1);
    end;
    Inc(i);
  end;
  testValid:=isValid;
end;

function  calc_av(const n:Integer; const A:matrix):realarr;
var x:realarr; i,i1,p_count:byte;
begin
  for i:=0 to n-1 do
  begin
    x[i]:=0;
    p_count:=0;
    for i1:=0 to n-1 do
    begin
      if (A[i][i1]>0) then
    begin
      x[i]:=x[i]+A[i][i1];
      Inc(p_count);
    end;
    end;
    if (p_count<>0) then x[i]:=x[i]/p_count;
  end;
  calc_av:=x; 
end;

procedure data_out(const n:Integer; const M:matrix; const P:Integer; const E:Integer; const x:realarr; var outputdata:TextFile);
var i,i1:Byte;
begin
  writeln(outputdata,'Лабораторная работа №12':55);
  writeln(outputdata);

  writeln(outputdata,'Размерность матрицы  = ', n, '*',n);
  writeln(outputdata);

  writeln(outputdata,'Величина P = ',P,' Величина E = ',E);
  writeln(outputdata);

  writeln(outputdata,'Матрица A:');
  for i:=0 to n-1 do
  begin
    write(outputdata,' ':10);
    for i1:=0 to n-1 do
    begin
      write(outputdata,M[i][i1]:3);
    end;
    Writeln(outputdata);
  end;
  Writeln(outputdata);
  if x[0]=-1 then Writeln(outputdata,'Есть элементы, абсолютная величина которых отличается от P = ',P,' на E = ', E)
  else
  begin
    for i:=0 to n-1 do
    begin
      Writeln(outputdata,'Среднее значение положительных элементов строки ',i+1,' = ', x[i]:4:2);
    end;
    end;
end;
end.
