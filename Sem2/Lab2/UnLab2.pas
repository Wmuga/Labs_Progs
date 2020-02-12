unit UnLab2;

Interface

Uses
  SysUtils;     // ANSIUpperCase и др. -  смена регистра и обработка исключений

Type
  TTransport = (Trolley, Bus, Mini, Tram); // с 0 до 3 по умолчанию
  TRun = record
    tr_name : TTransport;
    num     : string[4];
    Date    : string[10];
  end;

//----------первая часть: создание типизированного файла в диалоге
Procedure CreateTypedFile1();

//----------вторая часть: создание типизированного файла из текстового
Procedure CreateTypedFile2();

//-------------- третья часть: поиск в типизированном файле ----
Procedure SearchChange();

//-------------- просмотр типизированного файла ----
Procedure ViewFile();

Implementation // -----------реализационная часть-----------------

//----------первая часть: создание типизированного файла в диалоге
Procedure CreateTypedFile1();
var
  transp  : TRun;
  fin     : file of TRun; //типизированный файл - файл записей
  kol     : Integer;      //количество записей
  buffer  : string;       //временные данные (имя,дата)
  flag    : Boolean;      //проверка данных
  ch      : Char;         //проверка на выход
  FileName: string[80];

begin

  if ParamCount<1 then
  begin
    writeln('Мало параметров '#13#10'Press enter');
    readln;  exit
  end;
  FileName := ParamStr(1);

  AssignFile(fin, FileName);
  Try  ReWrite(fin);
  Except
    writeln('Error: не удалось создать типизированный файл ',FileName);
    write('Press ENTER'); readln;  exit
  end;

  kol:=0;

  repeat
  with transp do
  begin
    repeat
    flag:=true;
    write('Транспорт = '); Readln(buffer);
    if      (AnsiLowerCase(buffer) = 'троллейбус') then tr_name:=Trolley
    else if (AnsiLowerCase(buffer) = 'автобус')    then tr_name:=Bus
    else if (AnsiLowerCase(buffer) = 'маршрутка')  then tr_name:=Mini
    else if (AnsiLowerCase(buffer) = 'трамвай')    then tr_name:=Tram
    else
    begin
      writeln('Неизвестное "', buffer, '" введите данные снова');
      flag:=False;
    end;
    until (flag);
    write('Маршрут = '); Readln(num);
    write('Дата утверждения = '); Readln(date);

    write(fin, transp);   // запись записи целиком в файл
    inc(kol);

    write('Ещё? (y/n)');
    readln(ch)
  end;
  until UpCase(ch)='N';

  CloseFile(fin);

  writeln('Создан типизированный файл из ',kol,' записей');
  write('Press ENTER');
  readln;
end;

//---------------------------------------------------------------------------------------
//----------вторая часть: создание типизированного файла из текстового
Procedure CreateTypedFile2();
var
  transp  : TRun;
  fin     : file of TRun; //типизированный файл - файл записей
  kol     : Integer;      //количество записей
  FileName:string[80];
begin
  if ParamCount<2 then
  begin
    writeln('Мало параметров '#13#10'Press enter');
    readln;  exit
  end;

FileName:= Paramstr(2);
 // или простой диалог или через параметры программы при её вызове ParamStr(2)
// writeln('Введите имя текстового файла');
// readln(FileName); 

 AssignFile(fin, FileName);
  Try  Reset(fin);
  Except
    writeln('Error: не удалось открыть текстовый файл ',Paramstr(2));
    write('Press ENTER'); readln;  exit
  end;


  //----------------- ЗАГЛУШКА --------------------
  //------------ Напишите код сами, а пока в диалоге: ----------------
              CreateTypedFile1; // заглушка - создание в диалоге -  заменить на свой код

  CloseFile(fin);

  write('Press ENTER');
  readln;
end;

//--------------------------------------------------------------
//-------------- третья часть: поиск в типизированном файле ----
Procedure SearchChange();
var
  transp  : TRun;
  fin     : file of TRun; //типизированный файл - файл записей
  kol     : Integer;      //количество записей
  FileName:string[80];
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

  AssignFile(fin, FileName);
  Try  ReSet(fin);    //  или  {$I-} ReSet(fr); {$I+} if IOResult<>0 then
  Except
    writeln('Error: не удалось открыть типизированный файл ',FileName);
    write('Press ENTER'); readln;  exit
  end;

  kol:=0;
  {
  while not eof(fin) and (kol=0) do
  begin
    read(fin, transp); // считывание
       // Если Иван c первого курса бакалавриата с хотя бы одной пятеркой
    if ((Stud.o1=5) or (Stud.o2=5) or (Stud.o3=5)) and
      (Stud.Kurs = Bacalavr1) and
      (ANSIUpperCase(Stud.FIO.I) = 'ИВАН') then  // сравнение в верхнем регистре
    begin
      writeln('Найден ', Stud.FIO.I,' ',Stud.FIO.O,' ',Stud.FIO.F,
      ' оценки ', Stud.o1, ' ', Stud.o2,' ', Stud.o3 );
      inc(kol);
      // Изменение считанного
      Stud.o1:=3; Stud.o2:=3; Stud.o3:=3;
      n:=FilePos(fr)-1; // позиция найденной записи - перед текущей
      // запись изменений "поверх" предыдущей версии
      seek(fr, n); // изменить тек.позицию в файле
      write(fr, Stud);       // запись в файле изменена
      writeln('В файле изменена запись номер ', n+1)
    end;
  end;
  }
  if kol=0 then
    writeln('Данные, соответствующие запросу, не найдены');

  CloseFile(fin);

  write('Press ENTER');  readln;
end;
//--------------------------------------------------------------
//-------------- просмотр типизированного файла ----
Procedure ViewFile();
var
  transp  : TRun;
  fin     : file of TRun; //типизированный файл - файл записей
  kol     : Integer;      //количество записей
  FileName:string[80];
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

  AssignFile(fin, FileName);
  Try  ReSet(fin);    //  или  {$I-} ReSet(fr); {$I+} if IOResult<>0 then
  Except
    writeln('Error: не удалось открыть типизированный файл ',FileName);
    write('Press ENTER'); readln;  exit
  end;
  {
  kol:=0;
  while not eof(fin) do
  begin
    read(fin, transp); // считывание

      writeln('Найден ', Stud.FIO.I,' ',Stud.FIO.O,' ',Stud.FIO.F,
      ' курс ', Ord(Stud.Kurs)+1,
      ' оценки ', Stud.o1, ' ', Stud.o2,' ', Stud.o3 );
      inc(kol);
  end;
  }
  if kol=0 then
    writeln('Данные не найдены')
  else
    writeln('Найдено ',kol, ' записей');
  CloseFile(fin);

  write('Press ENTER');  readln;
end;

End.

