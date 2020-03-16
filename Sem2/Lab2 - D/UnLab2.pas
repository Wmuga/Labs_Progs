Unit  UnLab2;   // ����  UnLab2.pas
Interface

Uses
  SysUtils;     // ANSIUpperCase � ��. -  ����� �������� � ��������� ����������

Type
  TCreat = (Werewolf, mermaid, vampire, fairy, human, angel); // � 0 �� 5 �� ���������      //----������ ���� ������� �����? �� ������� ���� � ���� DELPHY ��������
  TRec = record
    Creat: TCreat;
    Name: string[30]; // ������ ����������� ������ ����� ��������� � ����
    Place: string[30];
  end;

//----------������ �����: �������� ��������������� ����� � �������
Procedure CreateTypedFile1();

//----------������ �����: �������� ��������������� ����� �� ����������
Procedure CreateTypedFile2();

//-------------- ������ �����: ����� � �������������� ����� ----
Procedure FindA();

//-------------- �������� ��������������� ����� ----
Procedure ViewFile();

Implementation



Procedure CreateTypedFile1();
var
  Rec: TRec;
  F1: file of TRec; // �������������� ���� - ���� �������
  num, kol: integer;
  ch: char;
  FileName: string[80];
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

  AssignFile(F1, FileName);
  Try  ReWrite(F1); 
  Except
    writeln('Error: �� ������� ������� �������������� ���� ', FileName);
    write('Press ENTER'); readln;  exit
  end;

  kol:=0;
  repeat
    write('��������(1-6) =?');   readln(num); Rec.Creat := TCreat(num-1);
    write('��� =?');       readln(Rec.Name);
    write('����� �������� =?');  readln(Rec.Place);
    write(F1, Rec);   // ������ ������ ������� � ����
    inc(kol);

    write('���? (y/n)');
    readln(ch)
  until UpCase(ch)='N';

  CloseFile(F1);

  writeln('������ �������������� ���� �� ', kol, ' �������');
  write('Press ENTER');
  readln;
end;



Procedure ViewFile();
var
  Rec: TRec;
  F1: file of TRec;
  num, kol: integer;
  FileName: string[80];
begin
  if ParamCount<1 then
  begin
    writeln('���� ���������� '#13#10'Press enter');
    readln;  exit
  end;

  FileName := ParamStr(1);
  AssignFile(F1, FileName);
  Try  ReSet(F1); 
  Except
    writeln('Error: �� ������� ������� �������������� ���� ', FileName);
    write('Press ENTER'); readln;  exit
  end;

  kol:=0;
  while not eof(F1) do
  begin
    read(F1, Rec); // ����������

    write('������: ');
    num := Ord(Rec.Creat)+1;
    case num of
      1: writeln('���������');
      2: writeln('�������');
      3: writeln('������');
      4: writeln('�����');
      5: writeln('�������');
      6: writeln('�����')
    end;
    writeln ('���: ', Rec.Name);
    writeln ('����� ��������: ', Rec.Place);
    writeln;
    inc(kol);
  end;

  if kol=0 then
    writeln('������ �� �������')
  else
    writeln('������� ', kol, ' �������');

  CloseFile(F1);

  write('Press ENTER');  readln;
end;



Procedure CreateTypedFile2();
var
  Rec: TRec;
  Ftext: TextFile; // ��������� ����
  F1: file of TRec; // �������������� ���� - ���� �������
  kol, num: integer;
  FileName: string[80];
begin
  if ParamCount<2 then
  begin
    writeln('���� ���������� '#13#10'Press enter');
    readln;  exit
  end;

  FileName := ParamStr(1);
  AssignFile(F1, FileName);
  Try  ReWrite(F1)
  Except
    writeln('Error: �� ������� ������� �������������� ���� ', FileName);
    write('Press ENTER'); readln;  exit
  end;

 FileName:= Paramstr(2);
 AssignFile(Ftext, FileName);
  Try  Reset(Ftext);
  Except
    writeln('Error: �� ������� ������� ��������� ���� ', Paramstr(2));
    write('Press ENTER'); readln;  exit
  end;

  // readln(Ftext, kol);  ------- � ����� ��� ���?
  kol := 0;
  while not eof(FText) do
  begin //-----��� �������� begin
    readln(Ftext, num); Rec.Creat := TCreat(num-1);
    readln(Ftext, Rec.Name);
    readln(Ftext, Rec.Place);
    write(F1, Rec);   // ������ ������ ������� � ����
   // readln(FText); ----������
    inc(kol);            //---���� i, �� ����� �� ��������������. ����� � ���� kol? 
  end;
  CloseFile(F1);
  CloseFile(Ftext);

  writeln('������ �������������� ���� �� ', kol, ' �������');
  write('Press ENTER');
  readln;
end;



Procedure FindA();
var
  Rec, M1, M2: TRec;
  F1: file of TRec;
  n, kolBukv, i: integer;
  flag: boolean;
  FileName: string[80];
begin
  if ParamCount<1 then
  begin
    writeln('���� ���������� '#13#10'Press enter');
    readln;  exit
  end;

  FileName := ParamStr(1);
  AssignFile(F1, FileName);
  Try  ReSet(F1);
  Except
    writeln('Error: �� ������� ������� �������������� ���� ', FileName);
    write('Press ENTER'); readln;  exit
  end;

  n:=FileSize(F1)-1;
  Flag:=False;
  while (not n<0) and (Flag=false) do
  begin
    seek(F1, n);
    read(F1, Rec); // ����������
       // ���� � ����� �������� ������ ����� ����� �   
    KolBukv:= 0;
    For i:= 1 to length(Rec.Name) do
     if (ANSIUpperCase(Rec.Name[i]) = 'A') then  // ��������� � ������� ��������   ------���� ������ ������
      inc(KolBukv);
    if KolBukv>1 then Flag:=True;
    dec(n);
  end;
  if flag=false then writeln ('������, ��������������� �������, �� �������')
  else begin
    n := FilePos(F1)-1;  // ������� ��������� ������ � ����� �������
    if not n=0 then begin
  // ������ ������� ��������� ������ � ������
      seek (F1, n);  // �������� ���.������� � �����
      read (F1, M1);  //  ����������
      seek (F1, 0);
      read (F1, M2);
      seek (F1, n);
      write (F1, M2);  // ������ ������ � ����� ��������
      seek (F1, 0);
      write (F1, M1);
    end;
  writeln ('������� ������ ��� �������', n+1, '� ���������� �� ������ �����');
  end;
  CloseFile(F1);

  write('Press ENTER');  readln;
end;
end.
