unit UnFunc;

interface
uses
  UnVar,
  SysUtils,
  UnLab3;

procedure AddR(var ListN, ListK: PElem; r: TInfo);   // �������� ������� �� ��������� R � ������������ � �������� �������� � ������
procedure AddN;                                      //  "�������� ��������������� N ���������" � ������� ������
procedure AddFromTextFile;                           // ���������� ���� ������ �� ���������� ����� � ������� ������
procedure Add1;                                      // �������� ���� �������  � ������� ������
procedure SearchIt;                                  // "����� � ������"
procedure ViewList;                                  //  "��� ������ � ������?" - ����� �� ����� �������

implementation

// �������� ������� �� ��������� R � ������������ � �������� �������� � ������
procedure AddR(var ListN, ListK: PElem; r: TInfo); // ������ ������ � ����� ������ � R
var ListC: PElem;  // ������� ������� ������
begin
  if not inDict(Dict,DictLen,r) then
  begin
    Dict[DictLen]:=r;
    Inc(DictLen);
  end;
  if ListN = nil then CreateList(ListN, ListK, r)  // ���� ������ ����
  else
    if Length(r) >= Length(ListN^.info) then AddFirst(ListN, ListK, r)  // �������� � ������
    else
       if Length(r) <= Length(ListK^.info) then AddLast(ListN, ListK, r)  // �������� � �����
       else
         begin // ����� ����� ������
           ListC:=ListN; // � ������ ������
           while Length(ListC^.next^.info) >= Length(r) do
             ListC := ListC^.next;
           AddMedium(ListN, ListC, ListK, r)  // �������� ����� ��������
         end;
end;

//  "�������� ��������������� N ���������" � ������� ������
procedure AddN;
var n,i: integer; r: Integer;
begin
  write('������� N=?'); readln(n);
  for i:=0 to n-1 do
  begin
    if i mod 5 = 0 then Randomize;
    r:=Random(DictLen-1);
    AddR(NachaloSpiska, KonecSpiska, Dict[r]);
  end;
end;

// ���������� ���� ������ �� ���������� ����� � ������� ������
procedure AddFromTextFile;
var
  f: TextFile;
  r: TInfo;
begin
  AssignFile(f, ParamStr(1));
  try
    Reset(f);
    try
      try
          while not eof(f) do
          begin
            readln(f, r);
            AddR(NachaloSpiska, KonecSpiska,r);
          end;
          writeln('������ ������');
      except
       writeln('������������ ������ � ��������� ����� '+ ParamStr(1));
      end;
    finally
      CloseFile(f);
    end;
  except
    writeln('�� ������� ������� ��������� ���� '+ ParamStr(1));
  end;
end;

// �������� ���� �������  � ������� ������
procedure Add1;
var
  r: TInfo;
begin
 try
  write('������� �������� ������ R:'); readln(r);
  AddR(NachaloSpiska, KonecSpiska, r);
 except
    writeln('������������ ����� ��� ������ ����������');
 end;
end;

// "����� � ������"
procedure SearchIt;
var
  ListC: PElem;
  isFound:Boolean;
  i:Integer;

const letters:set of char = ['�','�','�'];

begin
  ListC:=NachaloSpiska;
  isFound:=false;
  i:=1;
  while (ListC<>nil) and (not isFound) do
  begin
    if ((AnsiUpperCase(ListC^.info))[1] in letters) then
    begin
      Writeln('������� ������, ��������������� �������� ��������.Ÿ �����:',i);
      isFound:=True;
    end
    else ListC:=ListC^.next;
    Inc(i);
  end;
  if not isFound then writeln('��� ����� ��������� ������');
end;

//  "��� ������ � ������?" - ����� �� ����� �������
procedure ViewList;
var
  ListC: PElem;
begin
  writeln('������:');
  ListC:=NachaloSpiska;
  if ListC=nil then writeln('������')
  else
  begin
  Writeln('������ �������:');
  while ListC<>nil do
  begin
    writeln(ListC^.info);
    ListC:=ListC^.next;
  end;
  Writeln('�������� �������:');
  ListC:=KonecSpiska;
  while ListC<>nil do
  begin
    writeln(ListC^.info);
    ListC:=ListC^.prev;
  end;
  end;
end;


end.
