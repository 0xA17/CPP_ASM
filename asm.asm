.386
.MODEL FLAT
.CODE

_CheckValueASM proc
	MOV eax, [ESP+4]
	MOV ebx, [ESP+8]
	XOR edx, edx
	IDIV ebx

	MOV eax, edx
	RETN
_CheckValueASM endp

END