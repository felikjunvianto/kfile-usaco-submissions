{
	ID: felikju1
	PROG: packrec
	LANG: PASCAL
}

type uku=record
	 p,l:longint;
	 end;
	 
var kotak:array[1..4] of uku;
	used:array[1..4] of boolean;
	ord:array[1..4] of longint;
	list:array[1..2400] of uku;
	x,count:longint;
	fin,fout:text;
	
function max2(a,b:longint):longint;
	begin
		max2:=a;
		if max2<b then max2:=b;
	end;
	
function max3(a,b,c:longint):longint;
	begin
		max3:=a;
		if max3<b then max3:=b;
		if max3<c then max3:=c;
	end;
	
function max4(a,b,c,d:longint):longint;
	begin
		max4:=a;
		if max4<b then max4:=b;
		if max4<c then max4:=c;
		if max4<d then max4:=d;
	end;
	
function biner(n:longint):string;
	var x,y:longint;
		masuk:string;
	begin
		biner:='';
		y:=0;
		while n>0 do
		begin
			str(n mod 2,masuk);
			biner:=masuk+biner;
			inc(y);
			n:=n div 2;
		end;
		if y<4 then for x:=1 to 4-y do biner:='0'+biner;
	end;
	
procedure tes(kardus:uku);
	var m:longint;

	begin
		if kardus.p<kardus.l then
		begin
			m:=kardus.p;
			kardus.p:=kardus.l;
			kardus.l:=m;
		end;
	
		if ((count=0) or ((list[1].p*list[1].l) = (kardus.p*kardus.l))) then
		begin
			inc(count);
			list[count]:=kardus;
		end else
		
		if (list[1].p*list[1].l) > (kardus.p*kardus.l) then
		begin
			count:=1;
			list[count]:=kardus;
		end;
	end;
	
procedure ukur;
	var coba:array[1..4] of uku;
		temp:uku;
		x,y:longint;
		balik:string;
		
	begin
		for x:=0 to 15 do
		begin
			balik:=biner(x);
			for y:=1 to 4 do if balik[y]='0' then
			begin
				coba[y].p:=kotak[ord[y]].p;
				coba[y].l:=kotak[ord[y]].l;
			end else
			
			begin
				coba[y].p:=kotak[ord[y]].l;
				coba[y].l:=kotak[ord[y]].p;
			end;
			
			//1
			temp.p:=coba[1].l+coba[2].l+coba[3].l+coba[4].l;
			temp.l:=max4(coba[1].p,coba[2].p,coba[3].p,coba[4].p);
			tes(temp);
			
			//2
			temp.p:=max2(coba[1].l+coba[2].l+coba[3].l,coba[4].p);
			temp.l:=max3(coba[1].p,coba[2].p,coba[3].p)+coba[4].l;
			tes(temp);
			
			//3
			temp.p:=max2(coba[4].p,coba[1].l+coba[2].l)+coba[3].l;
			temp.l:=max3(coba[1].p+coba[4].l,coba[2].p+coba[4].l,coba[3].p);
			tes(temp);

			//4
			temp.p:=max2(coba[2].l,coba[3].l)+coba[1].l+coba[4].l;
			temp.l:=max3(coba[1].p,coba[4].p,coba[2].p+coba[3].p);
			tes(temp);
			
			//5
			temp.p:=max2(coba[1].l,coba[2].l)+coba[3].l+coba[4].l;
			temp.l:=max3(coba[3].p,coba[4].p,(coba[1].p+coba[2].p));
			tes(temp);
			
			//6
			if (coba[1].p+coba[2].p<=coba[3].p) then
			begin
			if ((coba[4].p>coba[1].l+coba[3].l)and(coba[4].p>coba[2].l+coba[3].l)) then temp.p:=coba[4].p else
				temp.p:=max3(coba[1].l+coba[3].l,coba[2].l+coba[3].l,coba[4].p);
			end else
				temp.p:=max2(coba[2].l+coba[3].l,coba[1].l+coba[4].p);
					
			if (coba[1].l<=coba[2].l) then
			begin
			if (coba[4].p<=coba[3].l) then temp.l:=max2(coba[1].p+coba[2].p,coba[3].p+coba[4].l) else
				temp.l:=max2(coba[1].p+coba[2].p,max2(coba[3].p,coba[2].p)+coba[4].l);
			end else
			begin
				if (coba[4].p<=coba[3].l) then temp.l:=max2(coba[1].p+max2(coba[2].p,coba[3].p),coba[3].p+coba[4].l) else
					temp.l:=max2(coba[1].p+max2(coba[2].p,coba[3].p),max2(coba[3].p,coba[2].p)+coba[4].l);	
			end;
			tes(temp);
		end;
	end;
	
	
procedure permut(n:longint);
	var y:longint;
	
	begin
		if n=5 then ukur else
		
		for y:=1 to 4 do if used[y] then
		begin
			ord[n]:=y;
			used[y]:=FALSE;
			permut(n+1);
			used[y]:=TRUE;
		end;
	end;
	
procedure sort(terkiri,terkanan:longint);
	var kiri,kanan,pivot:longint;
		temp:uku;
		
	begin
		if terkiri<terkanan then
		begin
			kiri:=terkiri;
			kanan:=terkanan;
			pivot:=list[(kiri+kanan) div 2].l;
			
			while kiri<=kanan do
			begin
				while list[kiri].l<pivot do inc(kiri);
				while list[kanan].l>pivot do dec(kanan);
				if kiri<=kanan then
				begin
					temp:=list[kiri];
					list[kiri]:=list[kanan];
					list[kanan]:=temp;
					inc(kiri);
					dec(kanan);
				end;
			end;
			sort(terkiri,kanan);
			sort(kiri,terkanan);
		end;
	end;
	
begin
	assign(fin,'packrec.in');reset(fin);
	assign(fout,'packrec.out');rewrite(fout);
	
	for x:=1 to 4 do 
	begin
		readln(fin,kotak[x].p,kotak[x].l);
		used[x]:=TRUE;
	end;
	
	
	begin
		count:=0;
		permut(1);
	
		sort(1,count);
		writeln(fout,list[1].p*list[1].l);
		for x:=1 to count do 
			if((x=1)or not((list[x].p=list[x-1].p)and(list[x].l=list[x-1].l))) then writeln(fout,list[x].l,' ',list[x].p);
	end;
	close(fin);
	close(fout);
end.