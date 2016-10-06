{
	ID: felikju1
	PROG: crypt1
	LANG: PASCAL
}

var n,x,counter,satu,dua,tiga,empat,lima,y:longint;
	numb:array[1..10] of longint;
	bil1,hasil:longint;
	fin,fout:text;
	
function truth(panjang:longint):boolean;
	var benar:boolean;
		temp:string;
		
	begin
		str(hasil,temp);
		if length(temp) <> panjang then benar:= FALSE else 
			for x:=1 to length(temp) do 
				begin
					benar:=FALSE;
					for y:=1 to n do if ord(temp[x])-48 = numb[y] then 
					begin
						benar:=TRUE;
						break;
					end;
					if not(benar) then break;
				end;		
				
		truth:=benar;
	end;
	
begin
	assign(fin,'crypt1.in');reset(fin);
	assign(fout,'crypt1.out');rewrite(fout);
	readln(fin,n);
	for x:=1 to n do read(fin,numb[x]);
	counter:=0;
	for satu:=1 to n do
		for dua:=1 to n do
			for tiga:=1 to n do 
			begin
				bil1:=numb[satu]*100+numb[dua]*10+numb[tiga];

				for empat:=1 to n do
					for lima:=1 to n do 
					begin
						hasil:=bil1*numb[lima];
						if truth(3) then
						begin
							hasil:=bil1*numb[empat];
							if truth(3) then
							begin
								hasil:=bil1*numb[lima]+bil1*numb[empat]*10;
								if truth(4) then inc(counter);
							end;
						end;
					end;
			end;
	writeln(fout,counter);
	close(fin);
	close(fout);
end.