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
  SetConsoleCP(1251);      // из модуля Windows
  SetConsoleOutputCP(1251);

  Randomize;   //PseudoRandom seed

  repeat
    writeln('--------------------------------------');
    writeln('Q - добавить в список из текстового файла; ');
    writeln('W - сгенерировать и добавить в список; ');
    writeln('E - добавить в список; ');
    writeln('R - найти в списке;');
    writeln('T - удалить(очистить) список;');
    writeln('Y - просмотр;');
    writeln('U - конец.');
    write('Ваш выбор?'); readln(ch);
    writeln('--------------------------------------');

    ch:= UpCase(ch);
    case ch of
//----------создать список из текстового файла------------------
    'Q': AddFromTextFile;
//----------сгенерировать список -------------------------------
    'W': AddN;
//----------добавить в список ----------------------------------
    'E': Add1;
//-----------поиск----------------------------------------------
    'R': SearchIt;
//-----------освобождение памяти--------------------------------
    'T': FreeList(NachaloSpiska, KonecSpiska);
//-----------просмотр----------------------------------------------
    'Y': ViewList;
//-----------выход----------------------------------------------
    'U': exit;
//--------------------------------------------------------------
      else
        begin
          writeln('Нет такой команды');
          write('Press ENTER'); readln;
        end;
    end;

  until ch='U';
end.

