.686
.model flat, c
option casemap:none

.code

DllMain proc, hInstDLL:DWORD, reason:DWORD, reserved1:DWORD
      mov eax, -1
      ret
DllMain endp

SumOfMultiples proc
      push  ebp
      mov   ebp, esp
      mov   ecx, [ebp + 12]
      cmp   ecx, 0
      jle   E1

      push  esi
      push  edi
      mov   esi, [ebp + 8]
      mov   ebx, [ebp + 16]
      xor   edi, edi
  L0: mov   eax, [esi]
      cdq
      idiv  ebx
      test  edx, edx
      jnz   M1

      mov   eax, [esi]
      add   edi, eax
  M1: add   esi, 4
      dec   ecx
      ja    L0

      mov   eax, edi
      pop   edi
      pop   esi
      mov   esp, ebp
      pop   ebp
      ret

  E1: xor eax, eax
      mov   esp, ebp
      pop   ebp
      ret
SumOfMultiples endp
End DllMain