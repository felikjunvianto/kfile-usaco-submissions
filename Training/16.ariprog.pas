{
	ID: felikju1
	PROG: ariprog
	LANG: PASCAL
}

var n,m,batas,count:longint;
	catat:array[0..125000] of boolean;
	bil,temp:array[1..21050] of longint;
	x,y,z:longint;
	ada,dapat:boolean;
	fin,fout:text;
	
procedure merge	(a1,b1,a2,b2:longint);
	var i,awal:longint;
	
	begin
		i:=a1;
		awal:=a1;
		
		while((a1<=b1)and(a2<=b2)) do
			if bil[a1]<=bil[a2] then
			begin
				temp[i]:=bil[a1];
				inc(i);
				inc(a1);
			end else
			
			begin
				temp[i]:=bil[a2];
				inc(i);
				inc(a2);
			end;
			
		while(a1<=b1) do
		begin
			temp[i]:=bil[a1];
			inc(i);
			inc(a1);
		end;
		
		while(a2<=b2) do
		begin
			temp[i]:=bil[a2];
			inc(i);
			inc(a2);
		end;
		
		for i:=awal to b2 do bil[i]:=temp[i];
	end;
	
procedure sort(terkiri,terkanan:longint);
	begin
		if(terkiri<terkanan) then
		begin
			sort(terkiri,(terkiri+terkanan) div 2);
			sort(((terkiri+terkanan) div 2)+1,terkanan);
			merge(terkiri,(terkiri+terkanan) div 2,((terkiri+terkanan) div 2)+1,terkanan);
		end;
	end;

begin
	assign(fin,'ariprog.in');reset(fin);
	assign(fout,'ariprog.out');rewrite(fout);
	readln(fin,n);
	readln(fin,m);
	fillchar(catat,sizeof(catat),FALSE);

	count:=0;
	for x:=0 to m do
		for y:=x to m do if catat[(x*x)+(y*y)]=FALSE then
		begin
			catat[(x*x)+(y*y)]:=TRUE;
			inc(count);
			bil[count]:=x*x+y*y;
		end;
		
	sort(1,count);
	batas:=2*m*m;
	ada:=FALSE;
	for y:=1 to batas div (n-1) do 
		for x:=1 to count do if bil[x]>(batas-(n-1)*y) then break else
		begin
			dapat:=TRUE;
			for z:=2 to n do if not(catat[bil[x]+(z-1)*y]) then
			begin
				dapat:=FALSE;
				break;
			end;
			if dapat then
			begin
				ada:=TRUE;
				writeln(fout,bil[x],' ',y);
			end;
		end;
		
	if not(ada) then writeln(fout,'NONE');
	close(fin);
	close(fout);
end.