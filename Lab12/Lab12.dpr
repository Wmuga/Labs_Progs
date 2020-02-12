program Lab12;

{$APPTYPE CONSOLE}

uses
  UT in 'UT.pas',
  Windows;

var
  in_data,out_data:TextFile;
  n,P,E:Integer;
  A:matrix;
  av_value:realarr;
  isValid:Boolean;
begin
  setConsoleCP(1251);
  setConsoleOutputCP(1251);
  AssignFile(in_data,ParamStr(1));
  try
    Reset(in_data);
    try
    AssignFile(out_data,ParamStr(2));
    try
    Rewrite(out_data);
    try
    try
      if get_data(n,A,in_data,P,E) then
    begin
    if checkData(P,E) then
    begin
      if checkMatrix(n,A) then
      begin
        isValid:=TestValid(n,A,P,E);
        av_value[0]:=-1;
        if (isValid) then
        begin
          av_value:=calc_av(n,A);
        end;
        data_out(n,A,P,E,av_value,out_data);
      end
    end;
    end;
    except writeln('Ошибка при чтении'); end;
    finally CloseFile(out_data); end;
    except Writeln('Невозможно создать файл с выходными данными'); end;
    finally CloseFile(in_data); end;
    except Writeln('Невозможно открыть входной файл.');  end;
  write('End');
  Readln;
end.
