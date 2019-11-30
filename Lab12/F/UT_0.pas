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
function  calc_av(const n:Integer,const A:Integer):intarr;
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
  {��������}
  checkData:=0;
end;

function  checkMatrix(const n:Integer, const A:matrix):Integer;
begin
  {��������}
  checkMatrix:=0;
end;

function  testValid(const n:Integer, const A:matrix, const P:Integer, const E:Integer):Boolean;
begin
  {�������� ������}
  testValid:=True;
end;

function  calc_av(const n:Integer,const A:Intger):intarr;
var X:intarr;
begin
  {�������� ������}
  x[0]:=1;
  x[1]:=2;
  x[2]:=3;
  calc_av:=x;
end;

procedure data_out(const n:Integer; const M:matrix; const P:Integer; const E:Integer; const av_value:Integer; var outputdata:TextFile);
var i,i1:Byte; outputdata:TextFile;
begin
  writeln(outputdata,'������������ ������ �12':55);
  writeln(outputdata,'');

  writeln(outputdata,'����������� ������� ' = ', n, '*',n);
  writeln(outputdata,'');

  writeln(outputdata,'������� ',name,':');
  for i:=0 to n-1 do
  begin
    write(outputdata,' ':10);
    for i1:=0 to n-1 do
    begin
      write(outputdata,M[i][i1]:3);
    end;
    Writeln(outputdata);
    if av_value=-1 then Writeln('���� ��������, ���������� �������� ������� ���������� �� P = ',P,' �� E = ', E)
    else
    begin
       for i:=0 to n-1 do
       begin
         Writeln('������� �������� �������� ������ ',i+1,' = ', x[i]);
       end;
    end;
  end;

end;
end.
