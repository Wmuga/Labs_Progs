program Lab11;

{$APPTYPE CONSOLE}

uses
  UT in 'UT.pas';

var
  in_data,out_data:TextFile;
  n,P,E,matrixValid:Integer;
  A:matrix;
  av_value:intarr;
  isValid:Boolean;
  errType:Byte;
begin
  AssignFile(in_data,ParamStr(1));
  try
    Reset(in_data);
    try
      errType:=get_data(n,A,in_data,P,E);
    finally CloseFile(in_data); end;
    if errType=0 then errType:=checkData(n,P,E);
    if errType=1 then  Writeln('�������� n(<1)')
    else if errType=2 then Writeln('�������� n(>',ar_length,')')
    else if errType=3 then Writeln('�������� P(<0)')
    else if errType=4 then Writeln('�������� P(>',max_P,')')
    else if errType=5 then Writeln('�������� E(<-9)')
    else if errType=6 then Writeln('�������� E(>',max_E,')')
    else
    begin
      matrixValid:=checkMatrix(n,A);
      if matrixValid=-1 then
      begin
        isValid:=TestValid(n,A,P,E);
        av_value[0]:=-1;
        if (isValid) then
        begin
          av_value:=calc_av(n,A);
        end;

        AssignFile(out_data,ParamStr(2));
        try
          Rewrite(out_data);
          try
            data_out(n,A,P,E,av_value,out_data);
          finally CloseFile(out_data); end;
        except Writeln('���������� ������� ���� � ��������� �������'); end;
      end
      else writeln('������� �[',matrixValid div 10,',',matrixValid mod 10,'] �������');
    end;
  except Writeln('���������� ������� ������� ����.');  end;
  write('End');
  Readln;
end.
