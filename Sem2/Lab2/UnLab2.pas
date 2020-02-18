unit UnLab2;

Interface

Uses
  SysUtils;     // ANSIUpperCase � ��. -  ����� �������� � ��������� ����������

Type
  TTransport = (Trolley, Bus, Mini, Tram); // � 0 �� 3 �� ���������
  TRun = record
    tr_name : TTransport;   //"���" ����������, ���������� ��������� �������������� ����.
    num     : string[4];    //����� ��������
    Date    : record        //���� ����������� ��������, ���������� (���)�������
      day   : Integer;      //����, ����� � ��� �������������
      month : Integer;
      year  : Integer;
    end;
  end;

const TransportName:array[0..3] of string = ('����������','�������','���������','�������');

//----------������ �����: �������� ��������������� ����� � �������
Procedure CreateTypedFile1();

//----------������ �����: �������� ��������������� ����� �� ����������
Procedure CreateTypedFile2();

//-------------- ������ �����: ����� � �������������� ����� ----
Procedure SearchChange();

//-------------- �������� ��������������� ����� ----
Procedure ViewFile();

Implementation // -----------�������������� �����-----------------

//----------������ �����: �������� ��������������� ����� � �������
Procedure CreateTypedFile1();
var
  transp  : TRun;
  fout     : file of TRun; //�������������� ���� - ���� �������
  buffer  : Integer;       //����� ���� ���������
  kol     : Integer;       //���������� �������
  ch      : Char;          //�������� �� �����
  FileName: string[80];

begin

  if ParamCount<1 then
  begin
    writeln('���� ���������� '#13#10'Press enter');
    readln;  exit
  end;
  FileName := ParamStr(1);

  AssignFile(fout, FileName);
  Try  ReWrite(fout);
  Except
    writeln('Error: �� ������� ������� �������������� ���� ',FileName);
    write('Press ENTER'); readln;  exit;
  end;

  kol:=0;

  repeat
  with transp do
  begin
    write('��������� = '); Readln(buffer);
    tr_name:= TTransport(buffer-1);

    write('������� = '); Readln(num);

    writeln('���� �����������: ');
    write('���� = ');  Readln(date.day);
    write('����� = '); Readln(date.month);
    write('��� = ');   Readln(date.year);

    write(fout, transp);   // ������ ������ ������� � ����
    inc(kol);

    write('���? (y/n)');
    readln(ch)
  end;
  until UpCase(ch)='N';

  CloseFile(fout);

  writeln('������ �������������� ���� �� ',kol,' �������');
  write('Press ENTER');
  readln;
end;

//---------------------------------------------------------------------------------------
//----------������ �����: �������� ��������������� ����� �� ����������
Procedure CreateTypedFile2();
var
  transp  : TRun;
  fin     : TextFile;     //�������  �������� ����
  buffer  : string[4];    //��������� ������, ������������� � int
  ftype    : file of TRun; //�������������� ���� - ���� �������
  kol     : Integer;      //���������� �������
  FileName:string[80];
begin
  if ParamCount<2 then
  begin
    writeln('���� ���������� '#13#10'Press enter');
    readln;  exit
  end;

FileName:= Paramstr(2);

 AssignFile(fin, FileName);                  //����������� �������� ���������� �����
  Try  Reset(fin);
  Except
    writeln('Error: �� ������� ������� ��������� ���� ',Paramstr(2));
    write('Press ENTER'); readln;  exit
  end;

  AssignFile(ftype, ParamStr(1));              //����������� ��������������� �����
  Try  Rewrite(ftype);
  Except
    writeln('Error: �� ������� ������� �������������� ���� ',Paramstr(2));
    write('Press ENTER'); readln;  exit
  end;

  kol:=0;

  while not eof(fin) do                       //������ �� �������� �����
  begin
  with transp do
    begin
      readln(fin,buffer);
      tr_name:=TTransport(strtoint(buffer)-1);
      readln(fin, num);
      readln(fin,buffer);
      Date.day:=strtoint(buffer);
      readln(fin,buffer);
      Date.month:=strtoint(buffer);
      readln(fin,buffer);
      Date.year:=strtoint(buffer);
    end;
    write(ftype,transp);
    Inc(kol);
  end;

  if Kol=0 then writeln('������ ����')
  else writeln('������� ',kol, ' ������� �� �������� �����'#13#10'������ �������������� ����');

  CloseFile(ftype);
  CloseFile(fin);

  write('Press ENTER');
  readln;
end;

//--------------------------------------------------------------
//-------------- ������ �����: ����� � �������������� ����� ----
Procedure SearchChange();
var
  transp  : TRun;
  ftype     : file of TRun;            //�������������� ���� - ���� �������
  i       : Integer;                 //������� �������
  k       : Integer;                 //�����, ���� ������ ��������� ��������� ������
  num     : Integer;                 //����� ������ � ����� ������ �������� ������������
  MTransp : TRun;                    //������ � ����� ������ �������� ������������
  flag    : boolean;                 //������������ ��� ���������� k
  FileName:string[80];
begin
  if ParamCount<1 then
  begin
    writeln('���� ���������� '#13#10'Press enter');
    readln;  exit
  end;

  FileName := ParamStr(1);

  AssignFile(ftype, FileName);
  Try  ReSet(ftype);
  Except
    writeln('Error: �� ������� ������� �������������� ���� ',FileName);
    write('Press ENTER'); readln;  exit
  end;

  Mtransp.Date.day:=-1;  Mtransp.Date.month:=-1;  Mtransp.Date.year:=-1; i:=0;

  while not eof(ftype) do
  begin
    read(ftype, transp); // ����������
      if (transp.Date.year>MTransp.Date.year) or
      (transp.Date.year=MTransp.Date.year) and (transp.Date.month>MTransp.Date.month) or
      (transp.Date.year=MTransp.Date.year) and (transp.Date.month=MTransp.Date.month) and (transp.Date.day>=MTransp.Date.day) then
      begin
        MTransp:=transp;
        num:=i;
      end;
      Inc(i);
  end;

  if i=0 then Writeln ('������ ����')
  else if i=1 then Writeln('��-�� ����, ��� ������ ����, ����������� ������ � ���������� ������� ������')
  else if (i=2) and (num=0) then Writeln('��� ��������� �����, ������� �������� �� ������� �������')
  else
  begin
  Writeln('������ �',num+1, ' �������� ����� ������ �������� ������������'#13#10'����� ',i,' �������');

  Writeln('--------------------------------------');
  Writeln('����� ����� ������� ��������� (�� �������) ��������� ������?');
  flag:=False;


  repeat
    Readln(k);  Dec(k);
    if (k>i) or (k<1) then Writeln('������� �� ���������� �������')
    else flag:=True;
  until (flag);

  if k=num then Writeln('��������� � ������� ��������� ������');

  if (k<num) then              //������ �� �������  ��� k<num
  begin
  for i:=num-1 downto k do     //���� "������"
  begin
    Seek(ftype,i);               //������ �������� ���������� �� ���������� ������� (������� � num)
    read(ftype,transp);          //��������� ���������� ������
    write(ftype,transp);         //������ �� �������� �������
  end;
  Seek(ftype,k);                 //������ �� ������� k
  end;

  if (k>num) then              //������ �� �������  ��� k<num
  begin
  for i:=num to k-2 do         //���� "����"
  begin
    Seek(ftype,i+1);             //������ �� ��������� �������
    read(ftype,transp);          //��������� ��
    Seek(ftype,i);               //������������
    write(ftype,transp);         //����������
  end;
  Seek(ftype,k-1);               //������ �� ������� k-1
  end;
  write(ftype,Mtransp);          //����������
  end;
  CloseFile(ftype);

  write('Press ENTER');  readln;
end;
//--------------------------------------------------------------
//-------------- �������� ��������������� ����� ----
Procedure ViewFile();
var
  transp  : TRun;
  ftype     : file of TRun; //�������������� ���� - ���� �������
  kol     : Integer;      //���������� �������
  FileName:string[80];
begin
  if ParamCount<1 then
  begin
    writeln('���� ���������� '#13#10'Press enter');
    readln;  exit
  end;

  FileName := ParamStr(1);


  AssignFile(ftype, FileName);
  Try  Reset(ftype);
  Except
    writeln('Error: �� ������� ������� �������������� ���� ',FileName);
    write('Press ENTER'); readln;  exit
  end;

  kol:=0;
  while not eof(ftype) do
  begin
    read(ftype, transp); // ����������
    with transp do writeln('������ ', kol+1, ':'#13#10'���������:',TransportName[Ord(tr_name)],#13#10'�������:',num,#13#10'���� �����������:',date.day,'.',date.month,'.',date.year,#13#10);
      inc(kol);
  end;

  if kol=0 then
    writeln('������ �� �������')
  else
    writeln('������� ',kol, ' �������');
  CloseFile(ftype);

  write('Press ENTER');  readln;
end;

End.

