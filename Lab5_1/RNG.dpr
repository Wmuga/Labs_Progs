program RNG;

{$APPTYPE CONSOLE}

uses
  SysUtils;

var
  outp:TextFile;
  n,i,k,z:Integer;
  out_filename:string;

const outpf = 'input_files\input';

begin
  read(k);
  for z:=1 to k do
  begin
  out_filename:=outpf+IntToStr(z)+'.txt';
  AssignFile(outp, out_filename); //���������� ����� AssignFile(���������, ����)
  Rewrite(outp);           //�������� ����� �� ���������� (������ �����)
  Randomize;
  n:=Random(19)+1;
  Writeln(outp,n);         //����� � ����
  for i:=0 to n-1 do
  begin
     Writeln(outp,Random(40)-20);
  end;
  CloseFile(outp);         //��������� ����
  end;
end.
