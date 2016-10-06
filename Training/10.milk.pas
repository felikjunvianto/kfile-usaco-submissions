{
	ID: felikju1
	PROG: milk
	LANG: PASCAL
}
type tawaran = record
	 harga, banyak:longint;
	 end;

var m,n,x,money:longint;
	offer:array[1..5000] of tawaran;
	fin,fout:text;
	
procedure quicksort(terkiri,terkanan:longint);
	var kiri,kanan,pivot:longint;
		temp:tawaran;
		
	begin
		if terkiri < terkanan then
		begin
			kiri:=terkiri;
			kanan:=terkanan;
			pivot:=offer[(kiri+kanan)div 2].harga;
			while kiri <= kanan do
			begin
				while offer[kiri].harga < pivot do inc(kiri);
				while offer[kanan].harga > pivot do dec(kanan);
				if kiri <= kanan then
				begin
					temp:=offer[kiri];
					offer[kiri]:=offer[kanan];
					offer[kanan]:=temp;
					inc(kiri);
					dec(kanan);
				end;
			end;
			quicksort(terkiri,kanan);
			quicksort(kiri,terkanan);
		end;
	end;
	
begin
	assign(fin,'milk.in');reset(fin);
	assign(fout,'milk.out');rewrite(fout);
	readln(fin,n,m);
	for x:=1 to m do readln(fin,offer[x].harga,offer[x].banyak);
	quicksort(1,m);
	x:=0;
	money:=0;
	while n <>0 do 
	begin
		inc(x);
		if n > offer[x].banyak then
		begin
			n:=n-offer[x].banyak;
			money:=money+offer[x].banyak*offer[x].harga;
		end
		else 
		begin
			money:=money+offer[x].harga*n;
			n:=0;
		end;
	end;
	writeln(fout,money);
	close(fin);
	close(fout);
end.