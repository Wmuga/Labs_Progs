Unit  UnLab2;   // файл  UnLab2.pas
Interface

Uses
  SysUtils;     // ANSIUpperCase и др. -  смена регистра и обработка исключений

Type
  TCreat = (Werewolf, mermaid, vampire, fairy, human, angel); // с 0 до 5 по умолчанию      //----Почему были русские буквы? По крайней мере у меня DELPHY Жалуется
  TRec = record
    Creat: TCreat;
    Name: string[30]; // Только статические строки можно сохранить в файл
    Place: string[30];
  end;

//----------первая часть: создание типизированного файла в диалоге
Procedure CreateTypedFile1();

//----------вторая часть: создание типизированного файла из текстового
Procedure CreateTypedFile2();

//-------------- третья часть: поиск в типизированном файле ----
Procedure FindA();

//-------------- просмотр типизированного файла ----
Procedure ViewFile();

Implementation



Procedure CreateTypedFile1();
var
  Rec: TRec;
  F1: file of TRec; // типизированный файл - файл записей
  num, kol: integer;
  ch: char;
  FileName: string[80];
begin
  if ParamCount<1 then
  begin
    writeln('Мало параметров '#13#10'Press enter');
    readln;  exit
  end;
  FileName := ParamStr(1);
// или простой диалог или через параметры программы при её вызове ParamStr(1)
// writeln('Введите имя типизированного файла');
// readln(FileName);

  AssignFile(F1, FileName);
  Try  ReWrite(F1); 
  Except
    writeln('Error: не удалось создать типизированный файл ', FileName);
    write('Press ENTER'); readln;  exit
  end;

  kol:=0;
  repeat
    write('Существо(1-6) =?');   readln(num); Rec.Creat := TCreat(num-1);
    write('Имя =?');       readln(Rec.Name);
    write('Место рождения =?');  readln(Rec.Place);
    write(F1, Rec);   // запись записи целиком в файл
    inc(kol);

    write('Ещё? (y/n)');
    readln(ch)
  until UpCase(ch)='N';

  CloseFile(F1);

  writeln('Создан типизированный файл из ', kol, ' записей');
  write('Press ENTER');
  readln;
end;



Procedure ViewFile();
var
  Rec: TRec;
  F1: file of TRec;
  num, kol: integer;
  FileName: string[80];
begin
  if ParamCount<1 then
  begin
    writeln('Мало параметров '#13#10'Press enter');
    readln;  exit
  end;

  FileName := ParamStr(1);
  AssignFile(F1, FileName);
  Try  ReSet(F1); 
  Except
    writeln('Error: не удалось открыть типизированный файл ', FileName);
    write('Press ENTER'); readln;  exit
  end;

  kol:=0;
  while not eof(F1) do
  begin
    read(F1, Rec); // считывание

    write('Найден: ');
    num := Ord(Rec.Creat)+1;
    case num of
      1: writeln('оборотень');
      2: writeln('русалка');
      3: writeln('вампир');
      4: writeln('фейри');
      5: writeln('человек');
      6: writeln('ангел')
    end;
    writeln ('имя: ', Rec.Name);
    writeln ('место рождения: ', Rec.Place);
    writeln;
    inc(kol);
  end;

  if kol=0 then
    writeln('Данные не найдены')
  else
    writeln('Найдено ', kol, ' записей');

  CloseFile(F1);

  write('Press ENTER');  readln;
end;



Procedure CreateTypedFile2();
var
  Rec: TRec;
  Ftext: TextFile; // текстовый файл
  F1: file of TRec; // типизированный файл - файл записей
  kol, num: integer;
  FileName: string[80];
begin
  if ParamCount<2 then
  begin
    writeln('Мало параметров '#13#10'Press enter');
    readln;  exit
  end;

  FileName := ParamStr(1);
  AssignFile(F1, FileName);
  Try  ReWrite(F1)
  Except
    writeln('Error: не удалось создать типизированный файл ', FileName);
    write('Press ENTER'); readln;  exit
  end;

 FileName:= Paramstr(2);
 AssignFile(Ftext, FileName);
  Try  Reset(Ftext);
  Except
    writeln('Error: не удалось открыть текстовый файл ', Paramstr(2));
    write('Press ENTER'); readln;  exit
  end;

  // readln(Ftext, kol);  ------- А Зачем это тут?
  kol := 0;
  while not eof(FText) do
  begin //-----Был пропущен begin
    readln(Ftext, num); Rec.Creat := TCreat(num-1);
    readln(Ftext, Rec.Name);
    readln(Ftext, Rec.Place);
    write(F1, Rec);   // запись записи целиком в файл
   // readln(FText); ----Лишний
    inc(kol);            //---Было i, но нигде не использовалось. Имела в виду kol? 
  end;
  CloseFile(F1);
  CloseFile(Ftext);

  writeln('Создан типизированный файл из ', kol, ' записей');
  write('Press ENTER');
  readln;
end;



Procedure FindA();
var
  Rec, M1, M2: TRec;
  F1: file of TRec;
  n, kolBukv, i: integer;
  flag: boolean;
  FileName: string[80];
begin
  if ParamCount<1 then
  begin
    writeln('Мало параметров '#13#10'Press enter');
    readln;  exit
  end;

  FileName := ParamStr(1);
  AssignFile(F1, FileName);
  Try  ReSet(F1);
  Except
    writeln('Error: не удалось открыть типизированный файл ', FileName);
    write('Press ENTER'); readln;  exit
  end;

  n:=FileSize(F1)-1;
  Flag:=False;
  while (not n<0) and (Flag=false) do
  begin
    seek(F1, n);
    read(F1, Rec); // считывание
       // Если в имени существа больше одной буквы А   
    KolBukv:= 0;
    For i:= 1 to length(Rec.Name) do
     if (ANSIUpperCase(Rec.Name[i]) = 'A') then  // сравнение в верхнем регистре   ------Была забыта скобка
      inc(KolBukv);
    if KolBukv>1 then Flag:=True;
    dec(n);
  end;
  if flag=false then writeln ('данные, соответствующие запросу, не найдены')
  else begin
    n := FilePos(F1)-1;  // позиция найденной записи – перед текущей
    if not n=0 then begin
  // меняем местами найденную запись с первой
      seek (F1, n);  // изменить тек.позицию в файле
      read (F1, M1);  //  считывание
      seek (F1, 0);
      read (F1, M2);
      seek (F1, n);
      write (F1, M2);  // запись запись в файле изменена
      seek (F1, 0);
      write (F1, M1);
    end;
  writeln ('найдена запись под номером', n+1, 'и поставлена на первое место');
  end;
  CloseFile(F1);

  write('Press ENTER');  readln;
end;
end.
