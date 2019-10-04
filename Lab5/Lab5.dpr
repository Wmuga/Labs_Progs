program Lab5;

{$APPTYPE CONSOLE}

uses
  SysUtils;

const inp_file='input.txt';
const out_file='output.txt';
const max_value = 20;
const ar_len = 20;


var
  in_data,out_data:TextFile;
  i,n,num:Integer;
  minAbs:Real;
  A:array[0..ar_len] of real;
  cont:Boolean;


begin
  AssignFile(in_data,inp_file);
  Reset(in_data);
  AssignFile(out_data,out_file);
  rewrite(out_data);

  Readln(in_data,n);
  if (n>21) then
  begin
    Writeln(out_data,'�������� n. n>20');
    CloseFile(in_data);
    CloseFile(out_data);
    Exit;
  end;
  if (n<0) then
  begin
    Writeln(out_data,'�������� n. n<0');
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
      Writeln(out_data,'�������� |A[',i+1,']|>',max_value);
      cont:=False;
    end;
  end;

  if (cont=False) then
  begin
      CloseFile(in_data);
      CloseFile(out_data);
      exit;
  end;

  writeln(out_data,'������������ ������ �5':50);
  writeln(out_data,'');

  writeln(out_data,'���������� ��������� ������� n = ':55, n);
  writeln(out_data,'');


  writeln(out_data,'�������� ������� A:':50);
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
      minAbs:=A[i];
      num:=i+1;
    end;
  end;
  writeln(out_data,'---------------------------------------------------------------');
  writeln(out_data,'����������� ���������� �������� �������� ������� ��������� ��� ������� ', num);
end.
