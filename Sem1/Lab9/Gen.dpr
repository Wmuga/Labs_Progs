program Gen;

{$APPTYPE CONSOLE}

uses
  SysUtils;

var
   outp:TextFile;
   i,i1:Integer;
begin
  AssignFile(outp,'in/input6.txt');
  Rewrite(outp);
  Writeln(outp,'10 10');   //�����������
  for i:=0 to 9 do  // ���������� �� ������� ��� ������ �������� ������ ������������ (1 to 10)
  begin                     //���� ��� �������
    for i1:=0 to 8 do       //���� ��� ��������� ������ (1-9)
    begin                   //�� ���� ������ �.�. ����� 10 ����� ������� �� ��������� ������
      Write(outp,Random(9),' '); //������� ��������� ����� random(�������) 0-�������
    end;
    Writeln(outp,Random(9)); //������� 10� � ��������� �� ��������� ������
  end;
  CloseFile(outp);
end.
