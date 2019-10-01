program lab4;

{$APPTYPE CONSOLE}

uses
  SysUtils,
  Windows;

const ar_length = 20;
const inp_file = 'input_files/input_anomaly6.txt';
const out_file = 'output.txt';
var
  x,y:array[0..ar_length] of real;
  i,n,E,ChangedCount: integer;
  inputdata,outputdata: TextFile;

begin
  setConsoleCP(1251);
  setConsoleOutputCP(1251);

  AssignFile(inputdata,inp_file);  //���������� ���� �� ����
  Reset(inputdata);                //�������� ����� �� ������
  AssignFile(outputdata,out_file); //���������� ���� �� �����
  rewrite(outputdata);             //�������� ����� �� ����������
  Readln(inputdata,n);             //������ �� �����
  if (n>20) then
  begin
    Writeln('outputdata,�������� n. n>20');
    CloseFile(outputdata);
    Exit;
  end;
  if (n<0) then
  begin
    Writeln('outputdata,�������� n. n<0');
    CloseFile(outputdata);
    Exit;
  end;
  Readln(inputdata,E);
  if (E>14) then
  begin
    Writeln('outputdata,�������� E. E>14');
    CloseFile(outputdata);
    Exit;
  end;
  if (E<0) then
  begin
    Writeln('outputdata,�������� E. E<0');
    CloseFile(outputdata); 
    Exit;
  end;
  for i:=0 to n-1 do
  begin
    read(inputdata,x[i]); readln(inputdata,y[i]);
    if (Abs(x[i])>10) then
    begin
      Writeln(outputdata,'�������� X[',i+1,']>10');
      CloseFile(outputdata); 
      Exit;
    end;
    if (Abs(y[i])>10) then
    begin
      Writeln(outputdata,'�������� Y[',i+1,']>10');
      CloseFile(outputdata); 
      Exit;
    end;
  end;

  CloseFile(inputdata);


  writeln(outputdata,'������������ ������ �4':50);   //����� ������
  writeln;

  writeln('���������� ��������� �������� n = ':55, n);
  writeln;

  writeln('����������� �������� E = ':50, E);
  writeln;

  writeln('�������� �������� X, Y:':50);
  Writeln;

  ChangedCount:= 0;
  
  for i:=0 to n-1 do
     begin
        writeln(x[i]:37:1,' ',y[i]:5:1);
        if (Abs(x[i]-y[i])<=E) then    //��������� �����
           begin
                 x[i]:=y[i];
                 ChangedCount:=ChangedCount + 1;
           end;
     end;

  writeln(outputdata);
  Writeln(outputdata,'--------------------------------------------------------------------------------');
  writeln(outputdata);
  writeln(outputdata,'�������� �������� X, Y:':50);
  Writeln;
  for i:=0 to n-1 do
     begin
        writeln(outputdata,x[i]:37:1,' ',y[i]:5:1);
           end;
  Writeln;

  if (ChangedCount=0) then Writeln(outputdata,'������ �� ���� ��������. ChangedCount = 0':60)
  else if (ChangedCount=n) then Writeln(outputdata,'��� ':20,n,' ��������� ���� ��������. ChangedCount = ', n)
  else Writeln(outputdata,'���������� ���������� ��������� ChangedCount = ':60, ChangedCount);
  CloseFile(outputdata);         

  readln;
end.
