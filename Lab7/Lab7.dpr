program Lab7;

{$APPTYPE CONSOLE}

uses
  SysUtils,Windows;

const ar_length = 40;
const inp_filename = 'inputs\input';
const out_filename = 'outputs\output';
const max_value = 20;
var
  A:array[0..ar_length] of char;
  n,i,k,t,z,bubblesort,num:Integer;
  buf,min_char:Char;
  inputdata,outputdata: TextFile;
  inp_file, out_file: string;
  //bubblesort: Boolean;

begin
  setConsoleCP(1251);
  setConsoleOutputCP(1251);

  Writeln('Введите количество тестов');
  read(t);
  for z:=1 to t do
  begin
  inp_file:=inp_filename+IntToStr(z)+'.txt';
  out_file:=out_filename+IntToStr(z)+'.txt';

  AssignFile(inputdata,inp_file);
  Reset(inputdata);
  AssignFile(outputdata,out_file);
  rewrite(outputdata);
  Readln(inputdata,n);

  if (n>ar_length+1) then
  begin
    Writeln(outputdata,'Неверное n. n>', ar_length+1);
    CloseFile(inputdata);
    CloseFile(outputdata);
    Exit;
  end;
  if (n<0) then
  begin
    Writeln(outputdata,'Неверное n. n<0');
    CloseFile(inputdata);
    CloseFile(outputdata);
    Exit;
  end;

  Readln(inputdata,bubblesort);

  for i:=0 to n-1 do
  begin
    readln(inputdata,A[i]);
  end;


  CloseFile(inputdata);


  writeln(outputdata,'Лабораторная работа №7':50);   //Вывод данных write/writeln(переменная,текст)
  writeln(outputdata,'');

  writeln(outputdata,'Количество элементов массивов n = ':55, n);
  writeln(outputdata,'');
  write(outputdata,'Использованный метод сортировки: ':50);
  if (bubblesort=1) then writeln(outputdata,'пузырьковый')
  else writeln(outputdata,'метод выбора');
  writeln(outputdata,'');

  writeln(outputdata,'Элементы массива А:':50);
  for i:=0 to n-1 do
  begin
    write(outputdata,A[i],' ');
  end;
  Writeln(outputdata,'');

  if bubblesort=1 then
  begin
    for i:=0 to n-2 do
    begin
      for k:=n-2 downto i do
      begin
        if A[k]>A[k+1] then
        begin
          buf:=A[k];
          A[k]:=A[k+1];
          A[k+1]:=buf;
        end;
      end;
      write(outputdata,i+1,':');
      for k:=0 to n-1 do
     begin
        write(outputdata,A[k], ' ');
     end;
     Writeln(outputdata);
    end;
  end
  else
  begin
    for i:=0 to n-2 do
    begin
      min_char:='z';
      num:=0;
      for k:=i to n-1 do
      begin
        if A[k]<min_char then
        begin
          num:=k;
          min_char:=A[k];
        end;
      end;
      A[num]:=A[i];
      A[i]:=min_char;
      write(outputdata,i+1,':');
      for k:=0 to n-1 do
     begin
        write(outputdata,A[k], ' ');
     end;
     Writeln(outputdata);
    end;
  end;

  writeln(outputdata);
  Writeln(outputdata,'--------------------------------------------------------------------------------');
  writeln(outputdata);
  writeln(outputdata,'Отсортированный массив A:':50);
  for i:=0 to n-1 do
     begin
        write(outputdata,A[i], ' ');
     end;
  writeln(outputdata);
  CloseFile(outputdata);
  end;
  Writeln('END');
  readln;
end.
