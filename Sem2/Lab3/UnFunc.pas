unit UnFunc;

interface
uses
  UnVar,
  SysUtils,
  UnLab3;

procedure AddR(var ListN, ListK: PElem; r: TInfo);   // добавить элемент со значением R в соответствии с заданным порядком в список
procedure AddN;                                      //  "Добавить псевдослучайные N элементов" в текущий список
procedure AddFromTextFile;                           // Добавление всех данных из текстового файла в текущий список
procedure Add1;                                      // Добавить один элемент  в текущий список
procedure SearchIt;                                  // "Найти в списке"
procedure ViewList;                                  //  "Что сейчас в списке?" - вывод на экран консоли

implementation

// добавить элемент со значением R в соответствии с заданным порядком в список
procedure AddR(var ListN, ListK: PElem; r: TInfo); // адреса начала и конца списка и R
var ListC: PElem;  // текущий элемент списка
begin
  if not inDict(Dict,DictLen,r) then
  begin
    Dict[DictLen]:=r;
    Inc(DictLen);
  end;
  if ListN = nil then CreateList(ListN, ListK, r)  // если список пуст
  else
    if Length(r) >= Length(ListN^.info) then AddFirst(ListN, ListK, r)  // добавить в начало
    else
       if Length(r) <= Length(ListK^.info) then AddLast(ListN, ListK, r)  // добавить в конец
       else
         begin // найти после какого
           ListC:=ListN; // с начала списка
           while Length(ListC^.next^.info) >= Length(r) do
             ListC := ListC^.next;
           AddMedium(ListN, ListC, ListK, r)  // добавить после текущего
         end;
end;

//  "Добавить псевдослучайные N элементов" в текущий список
procedure AddN;
var n,i: integer; r: Integer;
begin
  write('Сколько N=?'); readln(n);
  for i:=0 to n-1 do
  begin
    if i mod 5 = 0 then Randomize;
    r:=Random(DictLen-1);
    AddR(NachaloSpiska, KonecSpiska, Dict[r]);
  end;
end;

// Добавление всех данных из текстового файла в текущий список
procedure AddFromTextFile;
var
  f: TextFile;
  r: TInfo;
begin
  AssignFile(f, ParamStr(1));
  try
    Reset(f);
    try
      try
          while not eof(f) do
          begin
            readln(f, r);
            AddR(NachaloSpiska, KonecSpiska,r);
          end;
          writeln('Список создан');
      except
       writeln('Некорректные данные в текстовом файле '+ ParamStr(1));
      end;
    finally
      CloseFile(f);
    end;
  except
    writeln('Не удалось открыть текстовый файл '+ ParamStr(1));
  end;
end;

// Добавить один элемент  в текущий список
procedure Add1;
var
  r: TInfo;
begin
 try
  write('введите название цветка R:'); readln(r);
  AddR(NachaloSpiska, KonecSpiska, r);
 except
    writeln('Некорректное число или ошибка добавления');
 end;
end;

// "Найти в списке"
procedure SearchIt;
var
  ListC: PElem;
  isFound:Boolean;
  i:Integer;

const letters:set of char = ['Б','В','Г'];

begin
  ListC:=NachaloSpiska;
  isFound:=false;
  i:=1;
  while (ListC<>nil) and (not isFound) do
  begin
    if ((AnsiUpperCase(ListC^.info))[1] in letters) then
    begin
      Writeln('Найдена строка, удовлетворяющая заданным условием.Её номер:',i);
      isFound:=True;
    end
    else ListC:=ListC^.next;
    Inc(i);
  end;
  if not isFound then writeln('Нет таких элементов списка');
end;

//  "Что сейчас в списке?" - вывод на экран консоли
procedure ViewList;
var
  ListC: PElem;
begin
  writeln('Список:');
  ListC:=NachaloSpiska;
  if ListC=nil then writeln('Пустой')
  else
  begin
  Writeln('Прямой порядок:');
  while ListC<>nil do
  begin
    writeln(ListC^.info);
    ListC:=ListC^.next;
  end;
  Writeln('Обратный порядок:');
  ListC:=KonecSpiska;
  while ListC<>nil do
  begin
    writeln(ListC^.info);
    ListC:=ListC^.prev;
  end;
  end;
end;


end.
