unit UnLab2;

Interface

Uses
  SysUtils;     // ANSIUpperCase � ��. -  ����� �������� � ��������� ����������

Type
  TTransport = (Trolley, Bus, Mini, Tram); // � 0 �� 3 �� ���������
  TRun = record
    tr_name : TTransport;
    num     : string[4];
    Date    : string[10];
  end;

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
  fin     : file of TRun; //�������������� ���� - ���� �������
  kol     : Integer;      //���������� �������
  buffer  : string;       //��������� ������ (���,����)
  flag    : Boolean;      //�������� ������
  ch      : Char;         //�������� �� �����
  FileName: string[80];

begin

  if ParamCount<1 then
  begin
    writeln('���� ���������� '#13#10'Press enter');
    readln;  exit
  end;
  FileName := ParamStr(1);

  AssignFile(fin, FileName);
  Try  ReWrite(fin);
  Except
    writeln('Error: �� ������� ������� �������������� ���� ',FileName);
    write('Press ENTER'); readln;  exit
  end;

  kol:=0;

  repeat
  with transp do
  begin
    repeat
    flag:=true;
    write('��������� = '); Readln(buffer);
    if      (AnsiLowerCase(buffer) = '����������') then tr_name:=Trolley
    else if (AnsiLowerCase(buffer) = '�������')    then tr_name:=Bus
    else if (AnsiLowerCase(buffer) = '���������')  then tr_name:=Mini
    else if (AnsiLowerCase(buffer) = '�������')    then tr_name:=Tram
    else
    begin
      writeln('����������� "', buffer, '" ������� ������ �����');
      flag:=False;
    end;
    until (flag);
    write('������� = '); Readln(num);
    write('���� ����������� = '); Readln(date);

    write(fin, transp);   // ������ ������ ������� � ����
    inc(kol);

    write('���? (y/n)');
    readln(ch)
  end;
  until UpCase(ch)='N';

  CloseFile(fin);

  writeln('������ �������������� ���� �� ',kol,' �������');
  write('Press ENTER');
  readln;
end;

//---------------------------------------------------------------------------------------
//----------������ �����: �������� ��������������� ����� �� ����������
Procedure CreateTypedFile2();
var
  transp  : TRun;
  fin     : file of TRun; //�������������� ���� - ���� �������
  kol     : Integer;      //���������� �������
  FileName:string[80];
begin
  if ParamCount<2 then
  begin
    writeln('���� ���������� '#13#10'Press enter');
    readln;  exit
  end;

FileName:= Paramstr(2);
 // ��� ������� ������ ��� ����� ��������� ��������� ��� � ������ ParamStr(2)
// writeln('������� ��� ���������� �����');
// readln(FileName); 

 AssignFile(fin, FileName);
  Try  Reset(fin);
  Except
    writeln('Error: �� ������� ������� ��������� ���� ',Paramstr(2));
    write('Press ENTER'); readln;  exit
  end;


  //----------------- �������� --------------------
  //------------ �������� ��� ����, � ���� � �������: ----------------
              CreateTypedFile1; // �������� - �������� � ������� -  �������� �� ���� ���

  CloseFile(fin);

  write('Press ENTER');
  readln;
end;

//--------------------------------------------------------------
//-------------- ������ �����: ����� � �������������� ����� ----
Procedure SearchChange();
var
  transp  : TRun;
  fin     : file of TRun; //�������������� ���� - ���� �������
  kol     : Integer;      //���������� �������
  FileName:string[80];
begin
  if ParamCount<1 then
  begin
    writeln('���� ���������� '#13#10'Press enter');
    readln;  exit
  end;

  FileName := ParamStr(1);
// ��� ������� ������ ��� ����� ��������� ��������� ��� � ������ ParamStr(1)
// writeln('������� ��� ��������������� �����');
// readln(FileName); 

  AssignFile(fin, FileName);
  Try  ReSet(fin);    //  ���  {$I-} ReSet(fr); {$I+} if IOResult<>0 then
  Except
    writeln('Error: �� ������� ������� �������������� ���� ',FileName);
    write('Press ENTER'); readln;  exit
  end;

  kol:=0;
  {
  while not eof(fin) and (kol=0) do
  begin
    read(fin, transp); // ����������
       // ���� ���� c ������� ����� ������������ � ���� �� ����� ��������
    if ((Stud.o1=5) or (Stud.o2=5) or (Stud.o3=5)) and
      (Stud.Kurs = Bacalavr1) and
      (ANSIUpperCase(Stud.FIO.I) = '����') then  // ��������� � ������� ��������
    begin
      writeln('������ ', Stud.FIO.I,' ',Stud.FIO.O,' ',Stud.FIO.F,
      ' ������ ', Stud.o1, ' ', Stud.o2,' ', Stud.o3 );
      inc(kol);
      // ��������� ����������
      Stud.o1:=3; Stud.o2:=3; Stud.o3:=3;
      n:=FilePos(fr)-1; // ������� ��������� ������ - ����� �������
      // ������ ��������� "������" ���������� ������
      seek(fr, n); // �������� ���.������� � �����
      write(fr, Stud);       // ������ � ����� ��������
      writeln('� ����� �������� ������ ����� ', n+1)
    end;
  end;
  }
  if kol=0 then
    writeln('������, ��������������� �������, �� �������');

  CloseFile(fin);

  write('Press ENTER');  readln;
end;
//--------------------------------------------------------------
//-------------- �������� ��������������� ����� ----
Procedure ViewFile();
var
  transp  : TRun;
  fin     : file of TRun; //�������������� ���� - ���� �������
  kol     : Integer;      //���������� �������
  FileName:string[80];
begin
  if ParamCount<1 then
  begin
    writeln('���� ���������� '#13#10'Press enter');
    readln;  exit
  end;

  FileName := ParamStr(1);
// ��� ������� ������ ��� ����� ��������� ��������� ��� � ������ ParamStr(1)
// writeln('������� ��� ��������������� �����');
// readln(FileName); 

  AssignFile(fin, FileName);
  Try  ReSet(fin);    //  ���  {$I-} ReSet(fr); {$I+} if IOResult<>0 then
  Except
    writeln('Error: �� ������� ������� �������������� ���� ',FileName);
    write('Press ENTER'); readln;  exit
  end;
  {
  kol:=0;
  while not eof(fin) do
  begin
    read(fin, transp); // ����������

      writeln('������ ', Stud.FIO.I,' ',Stud.FIO.O,' ',Stud.FIO.F,
      ' ���� ', Ord(Stud.Kurs)+1,
      ' ������ ', Stud.o1, ' ', Stud.o2,' ', Stud.o3 );
      inc(kol);
  end;
  }
  if kol=0 then
    writeln('������ �� �������')
  else
    writeln('������� ',kol, ' �������');
  CloseFile(fin);

  write('Press ENTER');  readln;
end;

End.

