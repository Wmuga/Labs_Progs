program Lab2;// ��� ��������� - 1) ��� �������. �����, 2) ��� ���������� �����
{$APPTYPE CONSOLE}

{
��� ��� ���������� (�������, ������� � �.�.)
��� ����� �������� (��������, 10, 10�, �)
��� ���� ����������� ��������
}

uses
  SysUtils,     // ANSIUpperCase � ��. -  ����� ��������
  Windows,   // SetConsoleCP - ����� ���������
  UnLab2;   // ���� ������ � ����� � ����������� ��� ������� ������

//--------------------������� ��������� - ���� -------------------------
var
  ch: char;
begin
  SetConsoleCP(1251);      // �� ������ Windows
  SetConsoleOutputCP(1251);

  repeat
    writeln('--------------------------------------');
    writeln('D - ������� ����� ���.���� � �������; ');
    writeln('N - ������� �� ���������� �����; ');
    writeln('F - ����� � ���������; ');
    writeln('V - ��������;');
    writeln('E - �����.');
    write('��� �����?'); readln(ch);
    writeln('--------------------------------------');

    ch:= UpCase(ch);  // ������ � ������� ������� (��������)
    case ch of
//--------------------------------------------------------------
//----------������ �����: �������� ��������������� � ������� ---
    'D': CreateTypedFile1;  // ����� ��������������� ��������� ��� ������ D
//----------������ �����: �������� ��������������� ����� �� ����������
    'N': CreateTypedFile2;
//----------������ �����: ����� � �������������� ---------------
    'F': SearchChange;
//-----------��������----------------------------------------------
    'V': ViewFile;
//-----------�����----------------------------------------------
    'E': exit;
//--------------------------------------------------------------
      else
        begin
          writeln('��� ����� �������');
          write('Press ENTER'); readln;
        end;
    end;

  until ch='E';
end.
