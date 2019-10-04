program lab3;

{$APPTYPE CONSOLE}

uses
  SysUtils,
  Windows;

const ar_length = 20;
var
  x,y:array[0..ar_length] of real;
  i,n,E,ChangedCount: integer;
  cont:Boolean;

begin
  setConsoleCP(1251);
  setConsoleOutputCP(1251);
  n:=-1;
  E:=-1;

  writeln('������� ���������� ��������� ��������');

  readln(n);
  if n<1 then Writeln('������������ n: n<1');
  if n>20 then Writeln('������������ n: n>20');
  if (n<1) or (n>20) then
  begin
    readln;
    exit;
  end;



  writeln('������� ����������� �������� E');
  readln(E);
  if E<0 then Writeln('������������ E: E<0');
  if E>20 then Writeln('������������ E: E>20');
  if (E<0) or (E>20) then
  begin
    readln;
    exit;
  end;

  cont:=True;
  writeln('������� �������� ��������'); //�������� ����� �������
  for i:=0 to n-1 do
     begin
        Readln(x[i],y[i]);
        if Abs(x[i])>10 then  //�������� x[i]
        begin
          writeln('�������� x[',i+1,']. |x[',i+1,'|>10.');
          cont:=False;
        end;

        if Abs(y[i])>10 then //�������� y[i]
        begin
          writeln('�������� y[',i+1,']. |y[',i+1,']|>10.');
          cont:=False;
        end;
           end;

  if cont=False then
  begin
        writeln('END');
         readln;
          exit;
  end.


  Writeln('--------------------------------------------------------------------------------');
  
  writeln('������������ ������ �3':50);
  writeln;

  writeln('���������� ��������� �������� n = ':55, n);
  writeln;

  writeln('����������� �������� E = ':50, E);
  writeln;

  writeln('�������� �������� X, Y:':50);
  Writeln;

  for i:=0 to n-1 do
     begin
        writeln(x[i]:37:1,' ',y[i]:5:1);
     end;
  writeln;

  ChangedCount:= 0; 
  for i:=0 to n-1 do
  begin
        if (Abs(x[i]-y[i])<=E) then    //��������� �����
           begin
                 x[i]:=y[i];
                 ChangedCount:=ChangedCount + 1;
           end;
  end;

  writeln('--------------------------------------------------------------------------------');
  writeln('�������� ������:':47);
  writeln;

  writeln('�������� �������� X, Y:':50);
  Writeln;
  for i:=0 to n-1 do
     begin
        writeln(x[i]:37:1,' ',y[i]:5:1);
           end;
  Writeln;

  if (ChangedCount=0) then Writeln('������ �� ���� ��������. ChangedCount = 0':60)
  else if (ChangedCount=n) then Writeln('��� ':20,n,' ��������� ���� ��������. ChangedCount = ', n)
  else Writeln('���������� ���������� ��������� ChangedCount = ':60, ChangedCount);
  writeln;         
  Writeln('END');
  readln;
end.
