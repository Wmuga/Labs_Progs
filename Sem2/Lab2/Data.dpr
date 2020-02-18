program Data;

{$APPTYPE CONSOLE}

uses
  SysUtils;

type
TTransport = (Trolley, Bus, Mini, Tram); //0 - 3
    TRun = record
    tr_name : TTransport;   //"Тип" транспорта, выраженный значеникм перечисляемого типа.
    num     : string[4];    //Номер маршрута
    Date    : record        //Дата утверждения маршрута, выраженная (под)записью
      day   : Integer;      //День, месяц и год соответственно
      month : Integer;
      year  : Integer;
    end;
  end;

  const TransportName:array[0..3] of string = ('Троллейбус','Автобус','Маршрутка','Трамвай');
var
  ftype:file of TRun;
  fout:TextFile;
  transp:TRun;
  kol:Integer;
  FileName:string;
begin
  FileName := ParamStr(1);

  AssignFile(ftype, FileName);
  Try  Reset(ftype);
  Except
    writeln('Error: не удалось открыть типизированный файл ',FileName);
    write('Press ENTER'); readln;  exit
  end;

  AssignFile(fout,ParamStr(2));
  Rewrite(fout);

  kol:=0;
  while not eof(ftype) do
  begin
    read(ftype, transp); // считывание
    with transp do writeln(fout,'Транспорт:',TransportName[Ord(tr_name)],', Маршрут:',num,', Дата утверждения:',date.day,'.',date.month,'.',date.year);
      inc(kol);
  end;

  if kol=0 then
    writeln(fout,'Данные не найдены')
  else
  CloseFile(ftype);
  CloseFile(fout);
end.
