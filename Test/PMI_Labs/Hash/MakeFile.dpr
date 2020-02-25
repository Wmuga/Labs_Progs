program MakeFile;

{$APPTYPE CONSOLE}

uses
  SysUtils;
type
  TSC = set of char;
var a:string[5];
    b:TSC;
    f:file of TSC;
    i:Integer;
begin
  a:='c';
  Assign(f,'in');
  ReWrite(f);
  while (True) do
  begin
  readln(a);
  if a='-1' then Exit;
  for i:=0 to 4 do
  begin
     if not (a[i] in b) then Include(b,a[i]);
  end;
  write(f,b);
  b:=[];
  a:='';
  end;
  CloseFile(f);
end.
 