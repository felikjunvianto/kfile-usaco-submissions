{
	ID: felikju1
	PROG: clocks
	LANG: PASCAL
}

var x,y,z,t:longint;
	clock,cek:array[1..9] of longint;
	move:array[1..27] of longint;
	benar:boolean;
	temp:string;
	fin,fout:text;
	
function ubah(n:longint):string;
	var tambah:string;
	
	begin
		ubah:='';
		while n>0 do
		begin
			str((n mod 4),tambah);
			ubah:=tambah+ubah;
			n:=n div 4;
		end;
	end;
	
begin
	assign(fin,'clocks.in');reset(fin);
	assign(fout,'clocks.out');rewrite(fout);
	for x:=1 to 9 do 
	begin
		read(fin,clock[x]);
		clock[x]:=clock[x] mod 12;
	end;
	
	for t:=0 to 262143 do
	begin
		temp:=ubah(t);
		x:=length(temp);
		if x<9 then for z:=1 to 9-x do temp:='0'+temp;
		
		cek:=clock;
		for z:=1 to 9 do
		begin
			x:=ord(temp[z])-ord('0');
			case z of
				1 : begin
						cek[1]:=(cek[1]+(x*3)) mod 12;
						cek[2]:=(cek[2]+(x*3)) mod 12;
						cek[4]:=(cek[4]+(x*3)) mod 12;
						cek[5]:=(cek[5]+(x*3)) mod 12;
					end;
						
				2 : begin
						cek[1]:=(cek[1]+(x*3)) mod 12;
						cek[2]:=(cek[2]+(x*3)) mod 12;
						cek[3]:=(cek[3]+(x*3)) mod 12;
					end;
					
				3 : begin
						cek[2]:=(cek[2]+(x*3)) mod 12;
						cek[3]:=(cek[3]+(x*3)) mod 12;
						cek[5]:=(cek[5]+(x*3)) mod 12;
						cek[6]:=(cek[6]+(x*3)) mod 12;
					end;
						
				4 : begin
						cek[1]:=(cek[1]+(x*3)) mod 12;
						cek[4]:=(cek[4]+(x*3)) mod 12;
						cek[7]:=(cek[7]+(x*3)) mod 12;
					end;						
					
				5 : begin
						cek[2]:=(cek[2]+(x*3)) mod 12;
						cek[4]:=(cek[4]+(x*3)) mod 12;
						cek[5]:=(cek[5]+(x*3)) mod 12;
						cek[6]:=(cek[6]+(x*3)) mod 12;
						cek[8]:=(cek[8]+(x*3)) mod 12;
					end;
					
				6 : begin
						cek[3]:=(cek[3]+(x*3)) mod 12;
						cek[6]:=(cek[6]+(x*3)) mod 12;
						cek[9]:=(cek[9]+(x*3)) mod 12;
					end;
					
				7 : begin
						cek[4]:=(cek[4]+(x*3)) mod 12;
						cek[5]:=(cek[5]+(x*3)) mod 12;
						cek[7]:=(cek[7]+(x*3)) mod 12;
						cek[8]:=(cek[8]+(x*3)) mod 12;
					end;
						
				8 : begin
						cek[7]:=(cek[7]+(x*3)) mod 12;
						cek[8]:=(cek[8]+(x*3)) mod 12;
						cek[9]:=(cek[9]+(x*3)) mod 12;
					end;
						
				9 : begin
						cek[5]:=(cek[5]+(x*3)) mod 12;
						cek[6]:=(cek[6]+(x*3)) mod 12;
						cek[8]:=(cek[8]+(x*3)) mod 12;
						cek[9]:=(cek[9]+(x*3)) mod 12;
					end;
				end;
		end;
		
		benar:=TRUE;
		for z:=1 to 9 do if cek[z]<>0 then
		begin
			benar:=FALSE;
			break;
		end;
		
		if benar then
		begin
			y:=0;
			for z:=1 to 9 do
				for x:=1 to (ord(temp[z])-ord('0')) do
				begin
					inc(y);
					move[y]:=z;
				end;
			
			for x:=1 to y do 
			begin
				write(fout,move[x]);
				if x<y then write(fout,' ');
			end;
			writeln(fout);
			break;
		end;
	end;
	close(fin);
	close(fout);
end.