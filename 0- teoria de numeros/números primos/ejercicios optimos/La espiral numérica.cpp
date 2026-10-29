program Espiral;
uses crt;
var n,d,r,s,ans:Int64;
begin
  readln(n);
  d:=n div 2;
  r:=d+1;
  s:=(4*d*d*d + 6*d*d + 5*d ) + (4*r*r*r - r);
  ans:=s div 3;
  writeln(ans);
end.