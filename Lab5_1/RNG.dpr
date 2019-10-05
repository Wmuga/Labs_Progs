program RNG;

{$APPTYPE CONSOLE}

uses
  SysUtils;

var
  outp:TextFile;
  n,i,k,z:Integer;
  out_filename:string;

const outpf = 'input_files\input';

begin
  read(k);
  for z:=1 to k do
  begin
  out_filename:=outpf+IntToStr(z)+'.txt';
  AssignFile(outp, out_filename); //Добавление файла AssignFile(перменная, файл)
  Rewrite(outp);           //Открытие файла на перезапись (замена файла)
  Randomize;
  n:=Random(19)+1;
  Writeln(outp,n);         //Вывод в файл
  for i:=0 to n-1 do
  begin
     Writeln(outp,Random(40)-20);
  end;
  CloseFile(outp);         //Закрываем файл
  end;
end.
