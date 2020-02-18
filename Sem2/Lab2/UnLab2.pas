unit UnLab2;

Interface

Uses
  SysUtils;     // ANSIUpperCase и др. -  смена регистра и обработка исключений

Type
  TTransport = (Trolley, Bus, Mini, Tram); // с 0 до 3 по умолчанию
  TRun = record
    tr_name : TTransport;   //"Тип" транспорта, выраженный значеникм перечисляемого типа.
    num     : string[4];    //Номер маршрута
    Date    : record        //Дата утверждения маршрута, выраженная (под)записью
      day   : Integer;      //День, месяц и год соответсвенно
      month : Integer;
      year  : Integer;
    end;
  end;

const TransportName:array[0..3] of string = ('Троллейбус','Автобус','Маршрутка','Трамвай');

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
  fout     : file of TRun; //типизированный файл - файл записей
  buffer  : Integer;       //Номер типа траспорта
  kol     : Integer;       //количество записей
  ch      : Char;          //проверка на выход
  FileName: string[80];

begin

  if ParamCount<1 then
  begin
    writeln('Мало параметров '#13#10'Press enter');
    readln;  exit
  end;
  FileName := ParamStr(1);

  AssignFile(fout, FileName);
  Try  ReWrite(fout);
  Except
    writeln('Error: не удалось создать типизированный файл ',FileName);
    write('Press ENTER'); readln;  exit;
  end;

  kol:=0;

  repeat
  with transp do
  begin
    write('Транспорт = '); Readln(buffer);
    tr_name:= TTransport(buffer-1);

    write('Маршрут = '); Readln(num);

    writeln('Дата утверждения: ');
    write('День = ');  Readln(date.day);
    write('Месяц = '); Readln(date.month);
    write('Год = ');   Readln(date.year);

    write(fout, transp);   // запись записи целиком в файл
    inc(kol);

    write('Ещё? (y/n)');
    readln(ch)
  end;
  until UpCase(ch)='N';

  CloseFile(fout);

  writeln('Создан типизированный файл из ',kol,' записей');
  write('Press ENTER');
  readln;
end;

//---------------------------------------------------------------------------------------
//----------вторая часть: создание типизированного файла из текстового
Procedure CreateTypedFile2();
var
  transp  : TRun;
  fin     : TextFile;     //Входной  тестовый файл
  buffer  : string[4];    //Временные данные, преобразуемые в int
  ftype    : file of TRun; //типизированный файл - файл записей
  kol     : Integer;      //количество записей
  FileName:string[80];
begin
  if ParamCount<2 then
  begin
    writeln('Мало параметров '#13#10'Press enter');
    readln;  exit
  end;

FileName:= Paramstr(2);

 AssignFile(fin, FileName);                  //Подключение входного текстового файла
  Try  Reset(fin);
  Except
    writeln('Error: не удалось открыть текстовый файл ',Paramstr(2));
    write('Press ENTER'); readln;  exit
  end;

  AssignFile(ftype, ParamStr(1));              //Подключение типизированного файла
  Try  Rewrite(ftype);
  Except
    writeln('Error: не удалось открыть типизированный файл ',Paramstr(2));
    write('Press ENTER'); readln;  exit
  end;

  kol:=0;

  while not eof(fin) do                       //Чтение из входного файла
  begin
  with transp do
    begin
      readln(fin,buffer);
      tr_name:=TTransport(strtoint(buffer)-1);
      readln(fin, num);
      readln(fin,buffer);
      Date.day:=strtoint(buffer);
      readln(fin,buffer);
      Date.month:=strtoint(buffer);
      readln(fin,buffer);
      Date.year:=strtoint(buffer);
    end;
    write(ftype,transp);
    Inc(kol);
  end;

  if Kol=0 then writeln('Пустой файл')
  else writeln('Считано ',kol, ' записей из входного файла'#13#10'Создан типизированный файл');

  CloseFile(ftype);
  CloseFile(fin);

  write('Press ENTER');
  readln;
end;

//--------------------------------------------------------------
//-------------- третья часть: поиск в типизированном файле ----
Procedure SearchChange();
var
  transp  : TRun;
  ftype     : file of TRun;            //типизированный файл - файл записей
  i       : Integer;                 //счетчик записей
  k       : Integer;                 //Номер, куда нуджно поставить найденную запись
  num     : Integer;                 //номер записи с самым давним временем утрверждения
  MTransp : TRun;                    //Запись с самым давним временем утрверждения
  flag    : boolean;                 //Используется при считывании k
  FileName:string[80];
begin
  if ParamCount<1 then
  begin
    writeln('Мало параметров '#13#10'Press enter');
    readln;  exit
  end;

  FileName := ParamStr(1);

  AssignFile(ftype, FileName);
  Try  ReSet(ftype);
  Except
    writeln('Error: не удалось открыть типизированный файл ',FileName);
    write('Press ENTER'); readln;  exit
  end;

  Mtransp.Date.day:=-1;  Mtransp.Date.month:=-1;  Mtransp.Date.year:=-1; i:=0;

  while not eof(ftype) do
  begin
    read(ftype, transp); // считывание
      if (transp.Date.year>MTransp.Date.year) or
      (transp.Date.year=MTransp.Date.year) and (transp.Date.month>MTransp.Date.month) or
      (transp.Date.year=MTransp.Date.year) and (transp.Date.month=MTransp.Date.month) and (transp.Date.day>=MTransp.Date.day) then
      begin
        MTransp:=transp;
        num:=i;
      end;
      Inc(i);
  end;

  if i=0 then Writeln ('Пустой файл')
  else if i=1 then Writeln('Из-за того, что запись одна, невозможная замена с изменением порядка записи')
  else if (i=2) and (num=0) then Writeln('Нет возможных замен, которые изменили бы порядок записей')
  else
  begin
  Writeln('Запись №',num+1, ' обладает самым давним временем утрверждения'#13#10'Всего ',i,' записей');

  Writeln('--------------------------------------');
  Writeln('Перед каким номером поставить (со сдвигом) найденную запись?');
  flag:=False;


  repeat
    Readln(k);  Dec(k);
    if (k>i) or (k<1) then Writeln('Выходит за допустимые пределы')
    else flag:=True;
  until (flag);

  if k=num then Writeln('Совпадает с номером найденной записи');

  if (k<num) then              //Запись со сдвигом  при k<num
  begin
  for i:=num-1 downto k do     //Идем "Наверх"
  begin
    Seek(ftype,i);               //Ставим файловый дескриптор на предыдущую позицию (начиная с num)
    read(ftype,transp);          //Считываем предыдущую запись
    write(ftype,transp);         //Запись на нынешнюю позицию
  end;
  Seek(ftype,k);                 //Встаем на позицию k
  end;

  if (k>num) then              //Запись со сдвигом  при k<num
  begin
  for i:=num to k-2 do         //Идем "Вниз"
  begin
    Seek(ftype,i+1);             //Встаем на следующую позицию
    read(ftype,transp);          //Считываем ёё
    Seek(ftype,i);               //Возвращаемся
    write(ftype,transp);         //Записываем
  end;
  Seek(ftype,k-1);               //Встаем на позицию k-1
  end;
  write(ftype,Mtransp);          //Записываем
  end;
  CloseFile(ftype);

  write('Press ENTER');  readln;
end;
//--------------------------------------------------------------
//-------------- просмотр типизированного файла ----
Procedure ViewFile();
var
  transp  : TRun;
  ftype     : file of TRun; //типизированный файл - файл записей
  kol     : Integer;      //количество записей
  FileName:string[80];
begin
  if ParamCount<1 then
  begin
    writeln('Мало параметров '#13#10'Press enter');
    readln;  exit
  end;

  FileName := ParamStr(1);


  AssignFile(ftype, FileName);
  Try  Reset(ftype);
  Except
    writeln('Error: не удалось открыть типизированный файл ',FileName);
    write('Press ENTER'); readln;  exit
  end;

  kol:=0;
  while not eof(ftype) do
  begin
    read(ftype, transp); // считывание
    with transp do writeln('Запись ', kol+1, ':'#13#10'Транспорт:',TransportName[Ord(tr_name)],#13#10'Маршрут:',num,#13#10'Дата утверждения:',date.day,'.',date.month,'.',date.year,#13#10);
      inc(kol);
  end;

  if kol=0 then
    writeln('Данные не найдены')
  else
    writeln('Найдено ',kol, ' записей');
  CloseFile(ftype);

  write('Press ENTER');  readln;
end;

End.

