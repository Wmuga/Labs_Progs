program RNG;

{$APPTYPE CONSOLE}

uses
  SysUtils;

var
  outp:TextFile;
  n,i:Integer;

const outpf = 'input.txt';

begin
  AssignFile(outp, outpf); //���������� ����� AssignFile(���������, ����)
  Rewrite(outp);           //�������� ����� �� ���������� (������ �����)
  Randomize;
  n:=Random(19)+1;
  Writeln(outp,n);         //����� � ����
  for i:=0 to n-1 do
  begin
     Writeln(outp,Random(40)-20);
  end;
  CloseFile(outp);         //��������� ����
end.
