unit HashFunc;

interface
  uses
    TypesConst;

function SetToHash1(const s:TCharSet):byte;
function SetToHash2(const s:TCharSet):byte;
function SetToHash3(const s:TCharSet):byte;

procedure GetData(var ArS,ArE:PSetAr;var len:Integer);

implementation

function SetToHash1(const s:TCharSet):byte;
var i:char;
begin
  result:=1;
  for i:='0' to 'ÿ' do
  begin
    if i in s then
    begin
      result:=result+ord(i);
      result:=(result or (ord(i) + CHash1)) and 255;
    end;
  end;
end;

function SetToHash2(const s:TCharSet):byte;
var i:char;
begin
  result:=1;
  for i:='0' to 'ÿ' do
  begin
    if i in s then result:=(((result+ord(i)-1)*(CHash2 + ord(i))) and 255) or CHash2;
  end;
end;

function SetToHash3(const s:TCharSet):byte;
var i:char;
begin
  result:=0;
  for i:='0' to 'ÿ' do
  begin
    if i in s then result:=((result+1)+(Ord(i) and CHash3)) and 255;
  end;
end;

procedure GetData(var ArS,ArE:PSetAr;var len:Integer);
var Indata:file of TCharSet;
    CurSet:PSetAr;
begin
  len:=0;
  New(ArS);
  ArE:=ArS;
  CurSet:=ArS;
  Assign(Indata,ParamStr(1));
  ReSet(Indata);
  while (not Eof(Indata)) do
  begin
     read(Indata, CurSet^.CharSet);
     New(CurSet^.next);
     CurSet:=CurSet^.next;
     CurSet^.next:=nil;
     Inc(Len);
  end;
  ArE:=CurSet;
end;

end.
