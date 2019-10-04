program RNG;

{$APPTYPE CONSOLE}

uses
  SysUtils;

var
  outp:TextFile;
  n,i:Integer;

const outpf = 'input.txt';

begin
  AssignFile(outp, outpf); //Добавление файла AssignFile(перменная, файл)
  Rewrite(outp);           //Открытие файла на перезапись (замена файла)
  Randomize;
  n:=Random(19)+1;
  Writeln(outp,n);         //Вывод в файл
  for i:=0 to n-1 do
  begin
     Writeln(outp,Random(40)-20);
  end;
  CloseFile(outp);         //Закрываем файл
end.
