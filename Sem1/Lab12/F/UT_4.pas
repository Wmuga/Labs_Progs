unit UT; //Unit Task (UselessTrash)

interface
const ar_length = 9;
const max_value = 9;
const max_E = 18;
const max_P = 9;

SysUtils,
  Windows,

type matrix = array[0..ar_length-1,0..ar_length-1] of Integer;
type intarr = array[0..ar_length] of Integer;

procedure get_data(var n:Integer; var M:matrix; var in_data:TextFile);
function  checkData(const n:Integer,const P:Integer, const E:Integer):byte;
function  checkMatrix(const n:Integer, const A:matrix):Integer;
function  testValid(const n:Integer, const A:matrix, const P:Integer, const E:Integer):Boolean;
function  calc_av(const n:Integer,const A:Intger):intarr;
procedure data_out(const n:Integer; const M:matrix; var outputdata:TextFile);

implementation

procedure get_data(var n:Integer; var M:matrix; var in_data:TextFile; var P:Integer; var E:Integer);
var i,i1:Integer;
begin
  Readln(in_data,n);
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

function  checkData(const n:Integer,const P:Integer, const E:Integer):byte;
begin
  if (n<1) then checkData:=1
  else if (n>ar_length) then checkData:=2
  else if (P<0) then checkData:=3
  else if (P>max_P) then checkData:=4
  else if (E<1) then checkData:=5
  else if (E>max_E) then checkData:=6;
end;

function  checkMatrix(const n:Integer, const A:matrix):Integer;
var i,i1,:Byte; err:Boolean;
begin
  i:=0;
  err:=False;
  while (i<n-1) and (not err) do
  begin
    i1:=0;
    while (i1<n-1) and (not err) do
    begin
      if Abs(A[i][i1])>max_value then err:=True;
    end;
  end;
  if (err) then checkMatrix:=i*10+i1;
  else checkMatrix:=-1;
end;

function  testValid(const n:Integer, const A:matrix, const P:Integer, const E:Integer):Boolean;
var i,i1,:Byte; isValid:Boolean;
begin
  i:=0;
  isValid:=True;
  while (i<n-1) and (isValid) do
  begin
    i1:=0;
    while (i1<n-1) and (isValid) do
    begin
      if Abs((A[i][i1])-P)<E then isValid:=False;
    end;
  end;
  checkMatrix:=isValid;
end;

function  calc_av(const n:Integer,const A:Intger):intarr;
var x:intarr; i,i1:byte;
begin
  for i:=0 to n-1 do
  begin
    x[i]:=0;
    for i1:=0 to n-1 do
    begin
      x[i]:=x[i]+A[i][i1];
    end;
  end;
  calc_av:=x; 
end;

procedure data_out(const n:Integer; const M:matrix; const P:Integer; const E:Integer; const av_value:Integer; var outputdata:TextFile);
var i,i1:Byte; outputdata:TextFile;
begin
  writeln(outputdata,'Лабораторная работа №12':55);
  writeln(outputdata,'');

  writeln(outputdata,'Размерность матрицы ' = ', n, '*',n);
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
    if av_value=-1 then Writeln('Есть элементы, абсолютная величина которых отличается от P = ',P,' на E = ', E)
    else
    begin
       for i:=0 to n-1 do
       begin
         Writeln('Среднее значение элементов строки ',i+1,' = ', x[i]);
       end;
    end;
  end;

end;
end.
