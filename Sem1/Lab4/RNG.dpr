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
  Writeln(outp,Random(21));
  for i:=0 to n-1 do
  begin
     Writeln(outp,Random(21)-10, ' ', Random(21)-10);
  end;
  CloseFile(outp);         //��������� ����
end.