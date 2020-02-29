program Lab3;
{$APPTYPE CONSOLE}

uses
  SysUtils,
  Windows,
  UnLab3 in 'UnLab3.pas',
  UnVar in 'UnVar.pas',
  UnFunc in 'UnFunc.pas';

var
  ch: char;

begin
  SetConsoleCP(1251);      // �� ������ Windows
  SetConsoleOutputCP(1251);

  Randomize;   //PseudoRandom seed

  repeat
    writeln('--------------------------------------');
    writeln('Q - �������� � ������ �� ���������� �����; ');
    writeln('W - ������������� � �������� � ������; ');
    writeln('E - �������� � ������; ');
    writeln('R - ����� � ������;');
    writeln('T - �������(��������) ������;');
    writeln('Y - ��������;');
    writeln('U - �����.');
    write('��� �����?'); readln(ch);
    writeln('--------------------------------------');

    ch:= UpCase(ch);
    case ch of
//----------������� ������ �� ���������� �����------------------
    'Q': AddFromTextFile;
//----------������������� ������ -------------------------------
    'W': AddN;
//----------�������� � ������ ----------------------------------
    'E': Add1;
//-----------�����----------------------------------------------
    'R': SearchIt;
//-----------������������ ������--------------------------------
    'T': FreeList(NachaloSpiska, KonecSpiska);
//-----------��������----------------------------------------------
    'Y': ViewList;
//-----------�����----------------------------------------------
    'U': exit;
//--------------------------------------------------------------
      else
        begin
          writeln('��� ����� �������');
          write('Press ENTER'); readln;
        end;
    end;

  until ch='U';
end.

