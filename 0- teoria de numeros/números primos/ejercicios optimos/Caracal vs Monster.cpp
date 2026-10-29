Program CVM;
//Problem dmoj.uclv.edu.cu/problem/caracalvsmonster
//User Hd(Derek Naharai Herrera Domínguez)
var
    num,sum :Int64;
begin
    Readln(num);
    sum:=0;
    while num>0 do
    begin
        sum:= sum*2 +1;
        num:= num div 2;
    end;
    write(sum);
end.