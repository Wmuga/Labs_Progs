unit UnLab3;

interface

type
  TInfo = string;
  TStrSet = array[0..60] of string;
  PElem = ^TElem;
  TElem = record
      info: TInfo;
      next: PElem;
      prev: PElem;
  end;

// ������� ������ �� ������ ��������
procedure CreateList(var ListN, ListK: PElem; r: TInfo);
// �������� ����� ������� ����� ������
procedure AddFirst(var ListN: PElem; ListK: PElem; r: TInfo);
// �������� ����� ������� � ����� ������
procedure AddLast(ListN: PElem; var ListK: PElem; r: TInfo);
// �������� ����� ������� � �������� ����� ListC (�� � �����)
procedure AddMedium(ListN,ListC,ListK: PElem; r: TInfo);
// �������� ������
procedure FreeList(var ListN, ListK: PElem);
//�������� �����
procedure GetDict(var Dict:TStrSet; var DictLen:byte);
//�������� �� ������� ����� � �������
function inDict(var Dict:TStrSet; var DictLen:byte;const r:TInfo):boolean;
//�������� ������������ �������
procedure WriteDict(const Dict:TstrSet; const DictLen:byte);

implementation

// ������� ������ �� ������ ��������
procedure CreateList(var ListN, ListK: PElem; r: TInfo);
begin
  New(ListN);
  ListK:=ListN; // ����� � ������ ���������
  ListN^.info:=r;
  ListN^.next:=nil;
  ListN^.prev:=nil;
end;

// �������� ����� ������� ����� ������
procedure AddFirst(var ListN: PElem; ListK: PElem; r: TInfo);
var Elem: PElem;
begin
  new(Elem);
  Elem^.info:=r;
  Elem^.next:=ListN;
  ELem^.next^.prev:=Elem;
  Elem^.prev:=nil;
  ListN:=Elem; // ������ �� 1-��
end;


 

// �������� ����� ������� � �����
procedure AddLast(ListN: PElem; var ListK: PElem; r: TInfo);
begin
  new(ListK^.next);
  ListK^.next^.info:=r;
  ListK^.next^.next:=nil;
  ListK^.next^.prev:=ListK;
  ListK:= ListK^.next;
end;


// �������� ����� ������� � �������� ����� ListC (�� � �����)
procedure AddMedium(ListN,ListC,ListK: PElem; r: TInfo);
var Elem: PElem;
begin
  new(Elem);
  Elem^.info:=r;
  Elem^.next:=ListC^.next; // ����� ���� ��, ��� ���� ����� ListC
  Elem^.next^.prev:=Elem;
  Elem^.prev:=ListC;
  ListC^.next:=Elem; // � �� ��� ����� ListC
end;

// �������� ������
procedure FreeList(var ListN, ListK: PElem);
var Elem: PElem;
begin
  Elem:=ListN;
  while Elem<>nil do
  begin
    ListN:=ListN^.next;
    Dispose(Elem);
    Elem:=ListN;
  end;
  ListK:=nil;
end;

procedure GetDict;
var inp:TextFile; i:Integer; buff:string;
begin
  AssignFile(inp,'in/dict.txt');
  Reset(inp);
  try
  i:=0;
  while not(eof(inp)) do
  begin
    Readln(inp,buff);
    Dict[i]:=buff;
    Inc(i);
  end;
  DictLen:=i;
  finally CloseFile(inp); end;
end;

function inDict;
var i:Byte;
begin
  result:=False;
  for i:=0 to DictLen-1 do
    if Dict[i]=r then
    begin
    result:=True;
    exit;
    end;
end;

procedure WriteDict;
var outp:TextFile; i:Integer;
begin
  AssignFile(outp,'in/dict.txt');
  Rewrite(outp);
  for i:=0 to DictLen-1 do
  begin
    Writeln(outp,Dict[i]);
  end;
  CLoseFile(outp);
end;

end.

