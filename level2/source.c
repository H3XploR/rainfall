/*
 * 0x080484d4 <+0>:	push   ebp
   0x080484d5 <+1>:	mov    ebp,esp 				(changement de stack)
   0x080484d7 <+3>:	sub    esp,0x68 			(espace de 104 octects)
   0x080484da <+6>:	mov    eax,ds:0x8049860 	dans eax -> (0xb7fd1a20 <_IO_2_1_stdout_>: "\204 \255", <incomplete sequence \373>)
   0x080484df <+11>:	mov    DWORD PTR [esp],eax	pointeur vers $eax = 0xb7fd1a20 <_IO_2_1_stdout_> -> premier arg ???
   0x080484e2 <+14>:	call   0x80483b0 <fflush@plt>   dump de -> (0xb7fd1a20 <_IO_2_1_stdout_>) -> 1er arg dans esp
   0x080484e7 <+19>:	lea    eax,[ebp-0x4c]		$eax = 1
   0x080484ea <+22>:	mov    DWORD PTR [esp],eax      premier arguments = $esp = 1
   0x080484ed <+25>:	call   0x80483c0 <gets@plt>	prise de user input -> j'ai mis ABCDEFGHIJKLMNOPQRSTUVWXYZ
   
   				*0xbffff6c0 = ABCDEFGHIJKLMNOPQRSTUVWXYZ

   0x080484f2 <+30>:	mov    eax,DWORD PTR [ebp+0x4]  	pointeur (void *) 0xbffff72c dans eax -> instruction leave dans $eax

   				*0xbffff72c = *0x804854a = <main+11>: =	(0xc9 = instruction leave)

   0x080484f5 <+33>:	mov    DWORD PTR [ebp-0xc],eax		mettre instruction leave dans pointeur [$ebp-0xc] = *0xbffff71c: = *0x804854a

 					*0xbffff71c = *0x804854a = <main+11>: =	(0xc9 = instruction leave)

   0x080484f8 <+36>:	mov    eax,DWORD PTR [ebp-0xc]


