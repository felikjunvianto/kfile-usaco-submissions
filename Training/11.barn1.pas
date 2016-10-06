{
	ID: felikju1
	PROG: barn1
	LANG: PASCAL
}
var m,s,c,x,y,z,counter,awal,akhir,terpanjang:longint;
	kandang:array[1..200] of char;
	fin,fout:text;
	//note kandang : v = baik, x = rusak, f = diperbaiki
begin
	assign(fin,'barn1.in');reset(fin);
	assign(fout,'barn1.out');rewrite(fout);
	readln(fin,m,s,c);
	fillchar(kandang,sizeof(kandang),'v');
	for x:=1 to c do 
	begin
		readln(fin,y);
		kandang[y]:='x';
	end;
	
	for x:=1 to s do if kandang[x]='x' then break;
	for y:=s downto 1 do if kandang[y]='x' then break;
	counter:=y-x+1;

	for c:=1 to m-1 do
	begin
		terpanjang:=0;
		for z:=x to y do if(kandang[z]='v') then
		begin
			s:=z;
			while kandang[s]='v' do inc(s);
			dec(s);
			if s-z+1>terpanjang then 
			begin
				terpanjang:=s-z+1;
				awal:=z;
				akhir:=s;
			end;
		end;
		for z:= awal to akhir do kandang[z]:='f';
		counter:=counter-terpanjang;
	end;
	writeln(fout,counter);
	close(fin);
	close(fout);
end.