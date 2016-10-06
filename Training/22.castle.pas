{
	ID: felikju1
	PROG: castle
	LANG: PASCAL
}
const ver:array[1..4] of longint=(1,0,-1,0);
	  hor:array[1..4] of longint=(0,1,0,-1);
	  arah:array[1..4] of longint=(8,4,2,1);
	  
	  din_up:array[1..2] of longint=(-1,0);
	  din_es:array[1..2] of longint=(0,1);
	  dir:array[1..2] of char=('N','E');
	  
var bawah,samping,x,y,z,coba:longint;
	banyak_ruang,ruang_max,ruang_jebol,temp:longint;
	dinding_x,dinding_y:longint;
	direction,flag,sama:char;
	map,awal:array[1..101,1..101] of char;
	fin,fout:text;
	
procedure floodfill(x,y:longint);
	var ver,hor:longint;
	
	begin
		inc(temp);
		map[x,y]:=flag;
		for ver:=-2 to 2 do
			for hor:=-2 to 2 do
				if(((abs(ver)=2)xor(abs(hor)=2))and((ver=0)xor(hor=0))) then
					if((x+hor>1)and(x+hor<2*samping+1)and(y+ver>1)and(y+ver<2*bawah+1)) then
						if((map[x+hor,y+ver]=sama)and(map[(2*x+hor) div 2,(2*y+ver) div 2]<>'#')) then floodfill(x+hor,y+ver);
	end;
	
begin
	assign(fin,'castle.in');reset(fin);
	assign(fout,'castle.out');rewrite(fout);
	readln(fin,samping,bawah);
	fillchar(map,sizeof(map),' ');
	
	for y:=1 to 2*bawah+1 do//inisialisasi dinding luar
		for x:=1 to 2*samping+1 do 
			if((x=1)or(x=2*samping+1)or(y=1)or(y=2*bawah+1)) then map[x,y]:='#';
	
	for y:=1 to 2*bawah+1 do if not(odd(y)) then//inisialisasi dinding dalam
	begin
		for x:=1 to 2*samping+1 do if not(odd(x)) then
		begin
			map[x,y]:='.';
			read(fin,coba);
			z:=0;
			repeat
				inc(z);
				if coba-arah[z]>=0 then
				begin
					dec(coba,arah[z]);
					map[x+hor[z],y+ver[z]]:='#';
				end;
			until z=4;
		end;
		readln(fin);
	end;
	
	ruang_max:=0;
	banyak_ruang:=0;
	flag:='@';
	sama:='.';
	for y:=2 to 2*bawah do if not(odd(y)) then//floodfill jumlah ruang dan banyak ruang
		for x:=2 to 2*samping do if not(odd(x)) then
			if map[x,y]='.' then
			begin
				inc(banyak_ruang);
				temp:=0;
				floodfill(x,y);
				if temp>ruang_max then ruang_max:=temp;
			end;
	
	awal:=map;
	ruang_jebol:=0;
	flag:='$';
	sama:='@';
	dinding_x:=samping;
	dinding_y:=1;
	
	for y:=2 to 2*bawah do if not(odd(y)) then//cari lokasi dinding jebol + ruang max
		for x:=2 to 2*samping do if not(odd(x)) then
			for z:=1 to 2 do if((x+din_es[z]>1)and(x+din_es[z]<2*samping+1)and(y+din_up[z]>1)and(y+din_up[z]<2*bawah+1)) then
			if(awal[x+din_es[z],y+din_up[z]]='#') then
			begin
				awal[x+din_es[z],y+din_up[z]]:=' ';
				temp:=0;
				map:=awal;
				floodfill(x,y);
				awal[x+din_es[z],y+din_up[z]]:='#';
		
				if ((temp>ruang_jebol)or((temp=ruang_jebol)and((x div 2) <= dinding_x)and((y div 2) >= dinding_y)
					and not(((x div 2)=dinding_x)and((y div 2)=dinding_y)))) then//kalau ruang sama, selalu ambil yg N
				begin
					ruang_jebol:=temp;
					dinding_x:=(x div 2);
					dinding_y:=(y div 2);
					direction:=dir[z];
				end;
			end;
	
	writeln(fout,banyak_ruang);
	writeln(fout,ruang_max);
	writeln(fout,ruang_jebol);
	writeln(fout,dinding_y,' ',dinding_x,' ',direction);
	close(fin);
	close(fout);
end.