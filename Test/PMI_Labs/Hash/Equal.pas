unit Equal;

interface
 uses
   TypesConst,HashFunc;
 type TFunc = function (const s:TCharSet):byte;

function TestEqual(const ArS:PSetAr;len:Integer; SetToHash:Tfunc):Integer;
procedure ShowRes(len:Integer);

implementation

function TestEqual(const ArS:PSetAr;len:Integer; SetToHash:Tfunc):Integer;
var HashSet:THashSet; i:Integer; CurPos:PSetAr; buffer:Byte;
    collCount:Integer;
begin
  CurPos:=ArS;
  collCount:=0;
  for i:=0 to len-1 do
  begin
    buffer:=SetToHash(CurPos^.CharSet);
    if buffer in HashSet then Inc(collCount)
    else Include(HashSet, buffer);
    CurPos:=CurPos^.next;
  end;
  result:=collCount;
end;

procedure ShowRes(len:integer);
var col:Integer;
begin
  col:=TestEqual(ArStart,len,SetToHash1);
  Writeln('Collision Count by first  hash function is ', col);
  col:=TestEqual(ArStart,len,SetToHash2);
  Writeln('Collision Count by second hash function is ', col);
  col:=TestEqual(ArStart,len,SetToHash3);
  Writeln('Collision Count by third  hash function is ', col);
end;

end.
