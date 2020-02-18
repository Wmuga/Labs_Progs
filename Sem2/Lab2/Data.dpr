program Data;

{$APPTYPE CONSOLE}

uses
  SysUtils;

type
TTransport = (Trolley, Bus, Mini, Tram); //0 - 3
    TRun = record
    tr_name : TTransport;   //"���" ����������, ���������� ��������� �������������� ����.
    num     : string[4];    //����� ��������
    Date    : record        //���� ����������� ��������, ���������� (���)�������
      day   : Integer;      //����, ����� � ��� ��������������
      month : Integer;
      year  : Integer;
    end;
  end;

  const TransportName:array[0..3] of string = ('����������','�������','���������','�������');
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
    writeln('Error: �� ������� ������� �������������� ���� ',FileName);
    write('Press ENTER'); readln;  exit
  end;

  AssignFile(fout,ParamStr(2));
  Rewrite(fout);

  kol:=0;
  while not eof(ftype) do
  begin
    read(ftype, transp); // ����������
    with transp do writeln(fout,'���������:',TransportName[Ord(tr_name)],', �������:',num,', ���� �����������:',date.day,'.',date.month,'.',date.year);
      inc(kol);
  end;

  if kol=0 then
    writeln(fout,'������ �� �������')
  else
  CloseFile(ftype);
  CloseFile(fout);
end.
