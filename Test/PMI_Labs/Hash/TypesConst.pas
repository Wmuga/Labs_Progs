unit TypesConst;

interface

    type TCharSet = set of char;
         PSetAr = ^TSetAr;
         TSetAr = record
           CharSet : TCharSet;
           next    : PSetAr;
         end;
         THashSet = set of byte;

    const CHash1 = 5;
          CHash2 = 9;
          CHash3 = 157;

    var ArStart,ArEnd:PSetAr;

    procedure FreeM(var st,ed:PSetAr);

implementation

procedure FreeM(var st,ed:PSetAr);
var CurPos:PSetAr;
begin
  while(st<>nil) do
  begin
    CurPos:=st;
    st:=st^.next;
    Dispose(CurPos);
  end;
  ed:=nil;
end;

initialization
ArStart:=nil;
ArEnd:=nil; 

finalization
  FreeM(ArStart, ArEnd);
end.
