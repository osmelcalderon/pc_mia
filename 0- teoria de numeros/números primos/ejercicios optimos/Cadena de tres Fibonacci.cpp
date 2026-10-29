{$A+,B-,D+,E-,F-,G-,I+,L+,N-,O-,P-,Q+,R+,S+,T-,V+,X+,Y+}
{$M 16384,0,0}

var
  f : array[0..33] of longint;
  s : array[0..30] of string;
  i,j : byte;
  inp : string;

begin {program}
  read(inp);
  s[0]:='0'; s[1]:='1';
  f[0]:=0; f[1]:=1;
  i:=1;
  repeat
    inc(i);
    f[i]:=f[i-1]+f[i-2];
    str(f[i],s[i]);
  until (s[i-2]+s[i-1]+s[i]=inp) or (length(inp) < length(s[i-2]+s[i-1]+s[i]));
  if s[i-2]+s[i-1]+s[i]<>inp then writeln('Error') else
   begin
     for j:= 1 to 3 do
      begin
        inc(i);
        f[i]:=f[i-1]+f[i-2];
      end;
     writeln(f[i-2],f[i-1],f[i]);
   end;
end. {DnlR}