program Main;
uses crt;

var
  a: int64;
begin
  clrscr;
  read(a);
  a := a * a;
  a := a mod 1000000;
  a := a div 100;
  writeln(a);
end.