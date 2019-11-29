program Lab10;

{$APPTYPE CONSOLE}

uses
  SysUtils;

const ar_len = 10;

type intarr = array[0..ar_len] of Integer;

procedure get_data(var n:Integer; var A:intarr);
var i:Byte; in_data:TextFile;
begin
  AssignFile(in_data,ParamStr(1));
  Reset(in_data);
  Readln(in_data,n);
  for i:=0 to n-1 do
  begin
    read(in_data,A[i]);
  end;
  CloseFile(in_data);
end;

procedure find_elem(const n:Integer; const A:intarr; var num:Integer);
var i:Byte;
begin
  for i:=0 to n-1 do
  begin
    if (A[i] mod 5 = 0) and (num=-1) then num:=i;
  end;
  if num=-1 then num:=0;
end;

procedure search_value(const n:Integer; const A:intarr; const num:Integer; var min_value:Integer);
var i:Byte;
begin
  for i:=num+1 to n-1 do
  begin
    if (A[i]>=0) and (A[i]<min_value) then min_value:=A[i];
  end;
end;

procedure data_out(const n:Integer; const A:intarr; const min_value:Integer);
var i:Byte; out_data:TextFile;
begin
  AssignFile(out_data,ParamStr(2));
  rewrite(out_data);
  writeln(out_data,'Ëàáîğàòîğíàÿ ğàáîòà ¹10':50);
  writeln(out_data,'');

  writeln(out_data,'Êîëè÷åñòâî ıëåìåíòîâ ìàññèâà n = ':55, n);
  writeln(out_data,'');

  write(out_data,'İëåìåíòû ìàññèâà A: ':40);
  for i:=0 to n-1 do
  begin
    write(out_data,A[i]:3);
  end;
  Writeln(out_data,'');

  writeln(out_data,'---------------------------------------------------------------');
  writeln(out_data,'Ìèíèìàëüíûé ıëåìåíò ìàññèâà À, óäîâëåòâîğÿşùèé óñëîâèå ğàâåí ',min_value);
  CloseFile(out_data);
end;

var
  n,num,min_value:Integer;
  A:intarr;


begin
  n:=-1;
  get_data(n, A);

  num:=-1;

  find_elem(n, A, num);

  min_value:=Abs(a[num]);

  search_value(n, A, num, min_value);

  data_out(n,A, min_value);
end.
