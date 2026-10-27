GenHC.sys key functions (capstone, VA base 0x10000)

===== GetDataFromTDI_response_parser @ 0x204e0 =====
204e0: mov       qword ptr [rsp + 8], rbx
204e5: mov       qword ptr [rsp + 0x18], rbp
204ea: mov       qword ptr [rsp + 0x20], rsi
204ef: push      rdi
204f0: push      r12
204f2: push      r13
204f4: push      r14
204f6: push      r15
204f8: sub       rsp, 0x30
204fc: mov       rbp, qword ptr [rcx]
204ff: movzx     edi, dl
20502: mov       r14, rcx
20505: mov       r12d, 0x5b4
2050b: mov       r8d, 0x35747345
20511: xor       ecx, ecx
20513: mov       rdx, r12
20516: xor       ebx, ebx
20518: call      qword ptr [rip + 0x14b8a]
2051e: lea       r8, [rip + 0xc1bb]
20525: lea       ecx, [rbx + 2]
20528: mov       r9d, edi
2052b: mov       rdx, rbp
2052e: mov       r13d, edi
20531: mov       rsi, rax
20534: call      0x121dc
20539: test      rax, rax
2053c: je        0x2078a
20542: mov       r8, r12
20545: xor       edx, edx
20547: mov       rcx, rax
2054a: call      0x251f0
2054f: movzx     r11d, dil
20553: lea       r15, [r11 + r11*2]
20557: add       r15, r15
2055a: xor       edi, edi
2055c: lea       r8, [rip + 0xc19d]
20563: mov       r9d, r13d
20566: and       dword ptr [rsp + 0x68], edi
2056a: lea       ecx, [rdi + 3]
2056d: mov       rdx, rbp
20570: call      0x121dc
20575: mov       rdx, qword ptr [r14 + r15*8 + 0x1e70]
2057d: lea       rcx, [rsp + 0x68]
20582: mov       eax, 0x20
20587: mov       qword ptr [rsp + 0x28], rcx
2058c: sub       eax, edi
2058e: mov       r9d, edi
20591: mov       rcx, rbp
20594: add       r9, rsi
20597: mov       r8w, 0x20
2059c: mov       dword ptr [rsp + 0x20], eax
205a0: call      0x24990
205a5: test      eax, eax
205a7: mov       ebx, eax
205a9: jne       0x20746
205af: add       edi, dword ptr [rsp + 0x68]
205b3: cmp       edi, 0x20
205b6: jb        0x20575
205b8: movzx     eax, word ptr [rsi + 8]
205bc: lea       r8, [rip + 0xc1ad]
205c3: lea       ecx, [rbx + 3]
205c6: mov       r9d, r13d
205c9: mov       rdx, rbp
205cc: mov       dword ptr [rsp + 0x20], eax
205d0: call      0x121dc
205d5: movzx     eax, word ptr [rsi + 4]
205d9: lea       r8, [rip + 0xc1d0]
205e0: ror       ax, 8
205e4: movzx     ecx, ax
205e7: mov       dword ptr [rsp + 0x68], ecx
205eb: mov       dword ptr [rsp + 0x20], ecx
205ef: lea       r12d, [rcx + 0x20]
205f3: lea       ecx, [rbx + 3]
205f6: call      0x121dc
205fb: jmp       0x20639
205fd: mov       rdx, qword ptr [r14 + r15*8 + 0x1e70]
20605: lea       rcx, [rsp + 0x68]
2060a: mov       eax, r12d
2060d: mov       qword ptr [rsp + 0x28], rcx
20612: sub       eax, edi
20614: mov       r9d, edi
20617: mov       rcx, rbp
2061a: add       r9, rsi
2061d: mov       r8w, 0x20
20622: mov       dword ptr [rsp + 0x20], eax
20626: call      0x24990
2062b: test      eax, eax
2062d: mov       ebx, eax
2062f: jne       0x20728
20635: add       edi, dword ptr [rsp + 0x68]
20639: cmp       edi, r12d
2063c: jb        0x205fd
2063e: mov       al, byte ptr [rsi + 7]
20641: cmp       al, 5
20643: je        0x20705
20649: cmp       al, 3
2064b: je        0x20705
20651: cmp       al, 9
20653: je        0x20705
20659: cmp       al, 0x29
2065b: je        0x20705
20661: cmp       al, 0xf
20663: je        0x20705
20669: cmp       al, 0x17
2066b: je        0x20705
20671: cmp       al, 1
20673: je        0x20705
20679: cmp       al, 0xb
2067b: je        0x20689
2067d: cmp       al, 0x1f
2067f: je        0x20689
20681: cmp       al, 0x1d
20683: jne       0x2055a
20689: movzx     eax, word ptr [rsi + 0x12]
2068d: movzx     r10d, byte ptr [rsi + 0x10]
20692: mov       rdx, qword ptr [r14]
20695: ror       ax, 8
20699: lea       r8, [rip + 0xa2c0]
206a0: mov       r9d, r10d
206a3: movzx     ecx, ax
206a6: movzx     eax, byte ptr [rsi + 6]
206aa: mov       dword ptr [rsp + 0x28], ecx
206ae: mov       ecx, 2
206b3: mov       dword ptr [rsp + 0x20], eax
206b7: call      0x121dc
206bc: mov       al, byte ptr [rsi + 7]
206bf: cmp       al, 0xa
206c1: je        0x206c7
206c3: cmp       al, 0x1c
206c5: jne       0x206d7
206c7: movzx     eax, word ptr [rsi + 0x12]
206cb: ror       ax, 8
206cf: mov       word ptr [r14 + 0x2000], ax
206d7: mov       al, byte ptr [rsi + 6]
206da: movzx     ecx, r10b
206de: xor       r8d, r8d
206e1: xor       edx, edx
206e3: imul      rcx, rcx, 0x268
206ea: mov       byte ptr [rcx + r14 + 0x1010], al
206f2: lea       rcx, [rcx + r14 + 0xff8]
206fa: call      qword ptr [rip + 0x14ab0]
20700: jmp       0x2055a
20705: test      byte ptr [rsi + 0xa], 0x80
20709: mov       rdx, rsi
2070c: mov       rcx, rbp
2070f: je        0x2071b
20711: call      0x1e658
20716: jmp       0x2055a
2071b: mov       r8d, edi
2071e: call      0x1ca80
20723: jmp       0x2055a
20728: cmp       eax, 0xc000020c
2072d: je        0x20736
2072f: cmp       eax, 0xc00000b5
20734: jne       0x2077c
20736: mov       ecx, eax
20738: call      0x21370
2073d: lea       r8, [rip + 0xc0ac]
20744: jmp       0x20762
20746: cmp       eax, 0xc000020c
2074b: je        0x20754
2074d: cmp       eax, 0xc00000b5
20752: jne       0x2077c
20754: mov       ecx, eax
20756: call      0x21370
2075b: lea       r8, [rip + 0xbfce]
20762: mov       ecx, dword ptr [rsp + 0x68]
20766: mov       r9d, r13d
20769: mov       rdx, rbp
2076c: mov       dword ptr [rsp + 0x28], ecx
20770: xor       ecx, ecx
20772: mov       qword ptr [rsp + 0x20], rax
20777: call      0x121dc
2077c: mov       edx, 0x35747345
20781: mov       rcx, rsi
20784: call      qword ptr [rip + 0x14956]
2078a: lea       r8, [rip + 0xc0af]
20791: mov       r9d, r13d
20794: mov       rdx, rbp
20797: mov       ecx, 2
2079c: call      0x121dc
207a1: mov       rbp, qword ptr [rsp + 0x70]
207a6: mov       rsi, qword ptr [rsp + 0x78]
207ab: mov       eax, ebx
207ad: mov       rbx, qword ptr [rsp + 0x60]
207b2: add       rsp, 0x30
207b6: pop       r15
207b8: pop       r14
207ba: pop       r13
207bc: pop       r12
207be: pop       rdi
207bf: ret       

===== UrbFunctions_request_dispatcher @ 0x1fa8c =====
1fa8c: mov       rax, rsp
1fa8f: mov       qword ptr [rax + 0x20], rbx
1fa93: mov       byte ptr [rax + 0x10], dl
1fa96: push      rbp
1fa97: push      rsi
1fa98: push      rdi
1fa99: push      r12
1fa9b: push      r13
1fa9d: push      r14
1fa9f: push      r15
1faa1: sub       rsp, 0xa0
1faa8: xor       r12d, r12d
1faab: mov       r13, r9
1faae: mov       rdi, r8
1fab1: mov       byte ptr [rax + 8], r12b
1fab5: mov       byte ptr [rax + 0x18], r12b
1fab9: mov       rax, qword ptr [rcx + 0x40]
1fabd: mov       r10b, dl
1fac0: mov       rsi, rcx
1fac3: mov       ebx, 0xc00000bb
1fac8: mov       r14d, 1
1face: lock xadd dword ptr [rax + 0x210], r14d
1fad7: add       r14d, 1
1fadb: test      r14w, r14w
1fadf: je        0x1fac8
1fae1: mov       r9, r8
1fae4: movzx     eax, r14w
1fae8: mov       rdx, rcx
1faeb: lea       r8, [rip + 0xc78e]
1faf2: mov       ecx, 3
1faf7: mov       dword ptr [rsp + 0x50], eax
1fafb: mov       dword ptr [rsp + 0x20], eax
1faff: call      0x121dc
1fb04: mov       rax, qword ptr [rdi + 0xb8]
1fb0b: mov       rbp, qword ptr [rax + 8]
1fb0f: mov       rax, qword ptr [rdi + 0x78]
1fb13: cmp       rax, -0x100
1fb19: movzx     r15d, word ptr [rbp + 2]
1fb1e: jae       0x1fb4e
1fb20: cmp       byte ptr [rax + 0x69], r12b
1fb24: je        0x1fb2c
1fb26: cmp       byte ptr [rax + 0x6d], r12b
1fb2a: jne       0x1fb4e
1fb2c: lea       r8, [rip + 0xc77d]
1fb33: mov       ecx, 1
1fb38: call      0x121dc
1fb3d: mov       dword ptr [rbp + 4], 0xc0007000
1fb44: mov       ebx, 0xc000009d
1fb49: jmp       0x1fdbe
1fb4e: mov       rax, qword ptr [rsi + 0x40]
1fb52: mov       edx, 0x38
1fb57: xor       ecx, ecx
1fb59: mov       r8d, 0x53747345
1fb5f: mov       qword ptr [rsp + 0x60], rax
1fb64: call      qword ptr [rip + 0x1553e]
1fb6a: test      rax, rax
1fb6d: mov       r12, rax
1fb70: jne       0x1fb7c
1fb72: mov       ebx, 0xc000009a
1fb77: jmp       0x1fdb6
1fb7c: mov       word ptr [rax + 0x10], r14w
1fb81: movzx     ecx, word ptr [rbp + 2]
1fb85: mov       edx, 0x103
1fb8a: cmp       ecx, 0x17
1fb8d: jg        0x1fd2b
1fb93: je        0x1fcf2
1fb99: cmp       ecx, 0xb
1fb9c: jg        0x1fcab
1fba2: je        0x1fc98
1fba8: test      ecx, ecx
1fbaa: je        0x1fc85
1fbb0: sub       ecx, 1
1fbb3: je        0x1fc04
1fbb5: sub       ecx, 7
1fbb8: je        0x1fd63
1fbbe: cmp       ecx, 1
1fbc1: jne       0x1fda2
1fbc7: lea       rax, [rsp + 0xf0]
1fbcf: mov       r9, r13
1fbd2: mov       r8, r12
1fbd5: mov       qword ptr [rsp + 0x30], rax
1fbda: lea       rax, [rsp + 0xe0]
1fbe2: mov       rdx, rdi
1fbe5: mov       qword ptr [rsp + 0x28], rax
1fbea: mov       rax, qword ptr [rsp + 0x100]
1fbf2: mov       rcx, rsi
1fbf5: mov       qword ptr [rsp + 0x20], rax
1fbfa: call      0x170c8
1fbff: jmp       0x1fd9b
1fc04: mov       rax, qword ptr [rdi + 0xb8]
1fc0b: lea       r8, [rip + 0x8c2e]
1fc12: mov       rdx, rsi
1fc15: mov       r13, qword ptr [rax + 8]
1fc19: mov       ecx, 2
1fc1e: mov       ebx, 0xc0000001
1fc23: movzx     eax, byte ptr [r13 + 0x23]
1fc28: movzx     r9d, byte ptr [r13 + 0x22]
1fc2d: mov       dword ptr [rsp + 0x20], eax
1fc31: call      0x121dc
1fc36: movzx     ecx, word ptr [r13 + 2]
1fc3b: lea       rdx, [rsp + 0x58]
1fc40: call      0x175e4
1fc45: test      al, al
1fc47: je        0x1fd9d
1fc4d: movzx     eax, byte ptr [r13 + 0x23]
1fc52: lea       r8, [rsp + 0x58]
1fc57: mov       r9, r12
1fc5a: mov       word ptr [rsp + 0x5a], ax
1fc5f: movzx     eax, byte ptr [r13 + 0x22]
1fc64: mov       rdx, rdi
1fc67: mov       rcx, rsi
1fc6a: mov       word ptr [rsp + 0x5c], ax
1fc6f: call      0x18f58
1fc74: mov       edx, 0x103
1fc79: mov       ebx, eax
1fc7b: test      eax, eax
1fc7d: cmove     ebx, edx
1fc80: jmp       0x1fda2
1fc85: mov       r8, rax
1fc88: mov       rdx, rdi
1fc8b: mov       rcx, rsi
1fc8e: call      0x16c48
1fc93: jmp       0x1fd9b
1fc98: mov       r8, rax
1fc9b: mov       rdx, rdi
1fc9e: mov       rcx, rsi
1fca1: call      0x1728c
1fca6: jmp       0x1fd9b
1fcab: cmp       ecx, 0x10
1fcae: je        0x1fcdc
1fcb0: cmp       ecx, 0x11
1fcb3: je        0x1fcdc
1fcb5: cmp       ecx, 0x12
1fcb8: je        0x1fcdc
1fcba: lea       eax, [rcx - 0x13]
1fcbd: cmp       eax, 2
1fcc0: ja        0x1fda2
1fcc6: mov       r9, r12
1fcc9: mov       r8, rbp
1fccc: mov       rdx, rdi
1fccf: mov       rcx, rsi
1fcd2: call      0x17454
1fcd7: jmp       0x1fd9b
1fcdc: mov       r9, rax
1fcdf: mov       r8, rbp
1fce2: mov       rdx, rdi
1fce5: mov       rcx, rsi
1fce8: call      0x17378
1fced: jmp       0x1fd9b
1fcf2: lea       r8, [rip + 0x8e27]
1fcf9: mov       rdx, rsi
1fcfc: mov       ecx, 3
1fd01: call      0x121dc
1fd06: mov       r9, rax
1fd09: mov       r8, rbp
1fd0c: mov       rdx, rdi
1fd0f: mov       rcx, rsi
1fd12: call      0x1762c
1fd17: cmp       eax, 0xc000009a
1fd1c: mov       ebx, eax
1fd1e: jne       0x1fd9d
1fd20: mov       dword ptr [rbp + 4], 0xc0001000
1fd27: xor       ebx, ebx
1fd29: jmp       0x1fd9d
1fd2b: sub       ecx, 0x18
1fd2e: je        0x1fd8a
1fd30: sub       ecx, 3
1fd33: je        0x1fecb
1fd39: sub       ecx, 1
1fd3c: je        0x1fd8a
1fd3e: sub       ecx, 2
1fd41: je        0x1feb8
1fd47: sub       ecx, 1
1fd4a: je        0x1fe87
1fd50: sub       ecx, 1
1fd53: je        0x1fd73
1fd55: sub       ecx, 8
1fd58: je        0x1fc98
1fd5e: cmp       ecx, 0xa
1fd61: jne       0x1fda2
1fd63: mov       r8, rax
1fd66: mov       rdx, rdi
1fd69: mov       rcx, rsi
1fd6c: call      0x1b34c
1fd71: jmp       0x1fd9b
1fd73: lea       r8, [rip + 0x8dc6]
1fd7a: mov       r9, rdi
1fd7d: mov       rdx, rsi
1fd80: mov       ecx, 2
1fd85: call      0x121dc
1fd8a: mov       r9, rax
1fd8d: mov       r8, rbp
1fd90: mov       rdx, rdi
1fd93: mov       rcx, rsi
1fd96: call      0x1762c
1fd9b: mov       ebx, eax
1fd9d: mov       edx, 0x103
1fda2: cmp       r15w, 0x1e
1fda7: je        0x1fdae
1fda9: xor       r12d, r12d
1fdac: xor       edi, edi
1fdae: cmp       ebx, edx
1fdb0: je        0x200bd
1fdb6: mov       r10b, byte ptr [rsp + 0xe8]
1fdbe: mov       ecx, ebx
1fdc0: movzx     r13d, r10b
1fdc4: call      0x21370
1fdc9: mov       qword ptr [rsp + 0x38], rdi
1fdce: mov       qword ptr [rsp + 0x30], r12
1fdd3: lea       r8, [rip + 0xc526]
1fdda: mov       r9d, r13d
1fddd: mov       rdx, rsi
1fde0: mov       ecx, 3
1fde5: mov       qword ptr [rsp + 0x28], rax
1fdea: and       qword ptr [rsp + 0x20], 0
1fdf0: call      0x121dc
1fdf5: cmp       ebx, 0xc00000b5
1fdfb: je        0x1fe11
1fdfd: cmp       ebx, 0xc000020c
1fe03: je        0x1fe11
1fe05: cmp       ebx, 0xc0000001
1fe0b: jne       0x1ffe5
1fe11: cmp       r15w, 0x1e
1fe16: je        0x1ffe5
1fe1c: mov       rax, qword ptr [rsi + 0x40]
1fe20: mov       r15b, byte ptr [rsp + 0xf0]
1fe28: mov       word ptr [rsp + 0x78], r14w
1fe2e: mov       r14b, byte ptr [rsp + 0xe0]
1fe36: xor       r13d, r13d
1fe39: add       rax, 0x218
1fe3f: mov       byte ptr [rsp + 0x7a], r10b
1fe44: mov       byte ptr [rsp + 0x7c], r15b
1fe49: mov       qword ptr [rsp + 0xe0], rax
1fe51: mov       byte ptr [rsp + 0x7b], r14b
1fe56: lea       rdx, [rsp + 0x68]
1fe5b: mov       rcx, rax
1fe5e: call      qword ptr [rip + 0x152f4]
1fe64: test      rax, rax
1fe67: mov       rdi, rax
1fe6a: jne       0x1ff43
1fe70: mov       rax, qword ptr [rsp + 0xe0]
1fe78: add       r13d, 1
1fe7c: cmp       r13d, 0xa
1fe80: jb        0x1fe56
1fe82: jmp       0x1ff71
1fe87: mov       r9, rax
1fe8a: mov       r8, rbp
1fe8d: mov       rdx, rdi
1fe90: mov       rcx, rsi
1fe93: call      0x1762c
1fe98: mov       edx, 0x103
1fe9d: cmp       eax, 0xc000009a
1fea2: mov       ebx, eax
1fea4: jne       0x1fda2
1feaa: mov       dword ptr [rbp + 4], 0xc0001000
1feb1: xor       ebx, ebx
1feb3: jmp       0x1fda2
1feb8: mov       r8, rax
1febb: mov       rdx, rdi
1febe: mov       rcx, rsi
1fec1: call      0x171b0
1fec6: jmp       0x1fd9b
1fecb: lea       r8, [rip + 0x8c8e]
1fed2: mov       r9, rdi
1fed5: mov       rdx, rsi
1fed8: mov       ecx, 2
1fedd: call      0x121dc
1fee2: test      byte ptr [rbp + 0x20], 1
1fee6: jne       0x1ff02
1fee8: cmp       byte ptr [rbp + 0x81], cl
1feee: jne       0x1ff02
1fef0: movzx     eax, word ptr [rbp + 0x84]
1fef7: ror       ax, 8
1fefb: mov       word ptr [rbp + 0x84], ax
1ff02: mov       r9, r12
1ff05: mov       r8, rbp
1ff08: mov       rdx, rdi
1ff0b: mov       rcx, rsi
1ff0e: call      0x1762c
1ff13: test      eax, eax
1ff15: mov       ebx, eax
1ff17: jne       0x1ff21
1ff19: and       dword ptr [rbp + 4], eax
1ff1c: jmp       0x1fd9d
1ff21: cmp       eax, 0xc000009a
1ff26: je        0x1fd20
1ff2c: cmp       eax, 0xc000009d
1ff31: jne       0x1fd9d
1ff37: mov       dword ptr [rbp + 4], 0xc0007000
1ff3e: jmp       0x1fd9d
1ff43: lea       r8, [rip + 0xabf6]
1ff4a: mov       r9, rax
1ff4d: mov       rdx, rsi
1ff50: mov       ecx, 3
1ff55: call      0x121dc
1ff5a: mov       rcx, qword ptr [rax + 0x88]
1ff61: test      rcx, rcx
1ff64: je        0x1ff71
1ff66: mov       edx, 0x53747345
1ff6b: call      qword ptr [rip + 0x1516f]
1ff71: test      rdi, rdi
1ff74: movzx     eax, r15b
1ff78: movzx     ecx, r14b
1ff7c: mov       r9, rdi
1ff7f: mov       rdx, rsi
1ff82: je        0x20041
1ff88: movzx     r10d, byte ptr [rsp + 0xe8]
1ff91: mov       r12, qword ptr [rdi + 0x88]
1ff98: mov       dword ptr [rsp + 0x40], eax
1ff9c: mov       eax, dword ptr [rsp + 0x50]
1ffa0: mov       dword ptr [rsp + 0x38], ecx
1ffa4: mov       dword ptr [rsp + 0x30], r10d
1ffa9: lea       r8, [rip + 0xc3a0]
1ffb0: mov       ecx, 1
1ffb5: mov       dword ptr [rsp + 0x28], eax
1ffb9: mov       qword ptr [rsp + 0x20], r12
1ffbe: mov       r13d, r10d
1ffc1: call      0x121dc
1ffc6: cmp       word ptr [rbp + 2], 9
1ffcb: jne       0x1ffe5
1ffcd: mov       r9, qword ptr [rbp + 0x18]
1ffd1: mov       rdx, qword ptr [rsp + 0x60]
1ffd6: and       dword ptr [rbp + 0x24], 0
1ffda: mov       r8b, r10b
1ffdd: mov       rcx, rsi
1ffe0: call      0x1e010
1ffe5: mov       r14b, byte ptr [rsp + 0xe8]
1ffed: test      r12, r12
1fff0: je        0x20015
1fff2: cmp       ebx, 0xc00000b5
1fff8: je        0x20015
1fffa: cmp       ebx, 0xc000020c
20000: je        0x20015
20002: cmp       ebx, 0xc0000001
20008: je        0x20015
2000a: xor       edx, edx
2000c: mov       rcx, r12
2000f: call      qword ptr [rip + 0x150cb]
20015: test      rdi, rdi
20018: je        0x200c5
2001e: cmp       ebx, 0xc000009d
20024: je        0x20078
20026: cmp       ebx, 0xc00000b5
2002c: je        0x20078
2002e: cmp       ebx, 0xc000020c
20034: je        0x20078
20036: test      ebx, ebx
20038: je        0x20089
2003a: mov       ebx, 0xc0000001
2003f: jmp       0x20089
20041: movzx     r14d, byte ptr [rsp + 0xe8]
2004a: mov       dword ptr [rsp + 0x38], eax
2004e: mov       eax, dword ptr [rsp + 0x50]
20052: mov       dword ptr [rsp + 0x30], ecx
20056: lea       r8, [rip + 0xc373]
2005d: mov       ecx, 1
20062: mov       dword ptr [rsp + 0x28], r14d
20067: mov       r13d, r14d
2006a: mov       dword ptr [rsp + 0x20], eax
2006e: call      0x121dc
20073: jmp       0x1ffed
20078: and       qword ptr [rdi + 0x38], 0
2007d: mov       ebx, 0xc0000120
20082: mov       dword ptr [rbp + 4], 0xc0010000
20089: mov       ecx, ebx
2008b: call      0x21370
20090: lea       r8, [rip + 0xc3a9]
20097: mov       r9d, r13d
2009a: mov       rdx, rsi
2009d: mov       ecx, 1
200a2: mov       qword ptr [rsp + 0x28], rax
200a7: mov       qword ptr [rsp + 0x20], rdi
200ac: call      0x121dc
200b1: mov       edx, ebx
200b3: mov       rcx, rdi
200b6: call      0x17594
200bb: jmp       0x200c5
200bd: mov       r14b, byte ptr [rsp + 0xe8]
200c5: mov       ecx, ebx
200c7: call      0x21370
200cc: lea       r8, [rip + 0xc3ad]
200d3: movzx     r9d, r14b
200d7: mov       rdx, rsi
200da: mov       ecx, 3
200df: mov       qword ptr [rsp + 0x20], rax
200e4: call      0x121dc
200e9: mov       eax, ebx
200eb: mov       rbx, qword ptr [rsp + 0xf8]
200f3: add       rsp, 0xa0
200fa: pop       r15
200fc: pop       r14
200fe: pop       r13
20100: pop       r12
20102: pop       rdi
20103: pop       rsi
20104: pop       rbp
20105: ret       

===== SendUsbSetupPacketToDevice_2 @ 0x18f58 =====
18f58: mov       qword ptr [rsp + 0x18], rbx
18f5d: mov       qword ptr [rsp + 0x10], rdx
18f62: push      rbp
18f63: push      rsi
18f64: push      rdi
18f65: push      r12
18f67: push      r13
18f69: push      r14
18f6b: push      r15
18f6d: sub       rsp, 0x40
18f71: mov       rax, qword ptr [rdx + 0xb8]
18f78: mov       r12, qword ptr [rcx + 0x40]
18f7c: mov       rsi, qword ptr [rdx + 0x78]
18f80: mov       r15, qword ptr [rax + 8]
18f84: movzx     r14d, word ptr [r12 + 0x2000]
18f8d: mov       rdi, r8
18f90: movzx     eax, word ptr [r15 + 2]
18f95: mov       r8, rsi
18f98: mov       rdx, r12
18f9b: mov       rbp, r9
18f9e: mov       r13, rcx
18fa1: mov       word ptr [rsp + 0x80], ax
18fa9: call      0x1bd38
18fae: test      rax, rax
18fb1: mov       rbx, rax
18fb4: jne       0x18ffd
18fb6: cmp       byte ptr [rsi + 0x69], al
18fb9: je        0x18fc5
18fbb: cmp       byte ptr [rsi + 0x6d], al
18fbe: mov       edi, 0xc000009a
18fc3: jne       0x18fca
18fc5: mov       edi, 0xc000009d
18fca: mov       ecx, edi
18fcc: call      0x21370
18fd1: lea       r8, [rip + 0x10508]
18fd8: mov       rdx, r13
18fdb: mov       r9, rax
18fde: mov       ecx, 1
18fe3: call      0x121dc
18fe8: mov       r8d, dword ptr [rsp + 0x88]
18ff0: mov       rbp, qword ptr [rsp + 0x88]
18ff8: jmp       0x19271
18ffd: mov       r8, r14
19000: xor       edx, edx
19002: mov       rcx, rax
19005: call      0x251f0
1900a: cmp       rsi, -0x100
19011: movdqu    xmm5, xmmword ptr [rip + 0x1cc67]
19019: movdqu    xmmword ptr [rbx], xmm5
1901d: mov       dword ptr [rbx + 0x10], 0x24544e55
19024: mov       byte ptr [rbx + 0x17], 0
19028: jbe       0x19030
1902a: mov       byte ptr [rbx + 0x16], sil
1902e: jmp       0x19036
19030: mov       al, byte ptr [rsi + 0x24]
19033: mov       byte ptr [rbx + 0x16], al
19036: test      rbp, rbp
19039: jne       0x19041
1903b: and       word ptr [rbx + 0x18], bp
1903f: jmp       0x19049
19041: movzx     eax, word ptr [rbp + 0x10]
19045: mov       word ptr [rbx + 0x18], ax
19049: mov       al, byte ptr [rdi]
1904b: shr       al, 7
1904e: cmp       al, 1
19050: jne       0x19058
19052: mov       byte ptr [rbx + 0x1c], 0x33
19056: jmp       0x1906f
19058: test      al, al
1905a: jne       0x1906f
1905c: movzx     eax, word ptr [rdi + 6]
19060: test      ax, ax
19063: jne       0x1906b
19065: mov       byte ptr [rbx + 0x1c], 0x25
19069: jmp       0x1906f
1906b: mov       byte ptr [rbx + 0x1c], 0x2d
1906f: mov       byte ptr [rbx + 0x20], 1
19073: mov       al, byte ptr [rdi + 2]
19076: mov       cl, 0x80
19078: mov       byte ptr [rbx + 0x21], al
1907b: mov       al, byte ptr [rdi + 3]
1907e: mov       r14d, 0xf
19084: mov       byte ptr [rbx + 0x22], al
19087: mov       al, byte ptr [rdi + 4]
1908a: mov       byte ptr [rbx + 0x23], al
1908d: mov       al, byte ptr [rdi + 5]
19090: mov       byte ptr [rbx + 0x24], 8
19094: mov       byte ptr [rbx + 0x2a], al
19097: test      byte ptr [rdi], cl
19099: jne       0x190b4
1909b: movzx     eax, word ptr [rdi + 6]
1909f: and       byte ptr [rbx + 0x25], 0xf0
190a3: add       ax, 8
190a7: mov       byte ptr [rbx + 0x24], al
190aa: shr       ax, 8
190ae: and       al, r14b
190b1: or        byte ptr [rbx + 0x25], al
190b4: mov       al, byte ptr [rbx + 0x24]
190b7: mov       byte ptr [rbx + 0x15], al
190ba: mov       al, byte ptr [rbx + 0x25]
190bd: and       al, r14b
190c0: mov       byte ptr [rbx + 0x14], al
190c3: test      byte ptr [rdi], cl
190c5: je        0x190da
190c7: movzx     eax, word ptr [r12 + 0x2000]
190d0: cmp       word ptr [rdi + 6], ax
190d4: jbe       0x190da
190d6: mov       word ptr [rdi + 6], ax
190da: mov       al, byte ptr [rdi + 6]
190dd: mov       byte ptr [rbx + 0x26], al
190e0: mov       al, byte ptr [rdi + 7]
190e3: mov       byte ptr [rbx + 0x27], al
190e6: mov       al, byte ptr [rdi]
190e8: mov       byte ptr [rbx + 0x28], al
190eb: mov       al, byte ptr [rdi + 1]
190ee: and       byte ptr [rbx + 0x2a], 0x7f
190f2: mov       byte ptr [rbx + 0x29], al
190f5: mov       al, byte ptr [rbx + 0x16]
190f8: and       byte ptr [rbx + 0x2d], r14b
190fc: and       al, r14b
190ff: mov       byte ptr [rbx + 0x2e], al
19102: sub       al, 1
19104: shl       al, 4
19107: or        byte ptr [rbx + 0x2d], al
1910a: mov       al, byte ptr [rbx + 0x2f]
1910d: and       al, 0xcb
1910f: or        al, 8
19111: mov       byte ptr [rbx + 0x2f], al
19114: cmp       word ptr [r15 + 2], 8
1911a: je        0x1913e
1911c: cmp       word ptr [r15 + 2], 0x32
19122: je        0x1913e
19124: mov       cl, byte ptr [rbx + 0x25]
19127: movzx     r8d, byte ptr [rbx + 0x24]
1912c: mov       rdx, rdi
1912f: and       ecx, r14d
19132: shl       ecx, 8
19135: add       r8d, ecx
19138: lea       rcx, [rbx + 0x30]
1913c: jmp       0x1915d
1913e: mov       rax, qword ptr [rdi]
19141: mov       qword ptr [rbx + 0x30], rax
19145: cmp       word ptr [rdi + 6], 0
1914a: jbe       0x19162
1914c: test      byte ptr [rdi], cl
1914e: jne       0x19162
19150: movzx     r8d, word ptr [rdi + 6]
19155: mov       rdx, qword ptr [r15 + 0x28]
19159: lea       rcx, [rbx + 0x38]
1915d: call      0x252f0
19162: test      rbp, rbp
19165: je        0x191a3
19167: cmp       word ptr [r15 + 2], 0x1e
1916d: je        0x191a3
1916f: mov       al, byte ptr [rbx + 0x2e]
19172: lea       r9, [rbp + 0x10]
19176: mov       r8, rbp
19179: and       al, r14b
1917c: mov       rcx, r13
1917f: mov       byte ptr [rbp + 0x12], al
19182: mov       al, byte ptr [rbx + 0x2e]
19185: shr       al, 4
19188: mov       byte ptr [rbp + 0x13], al
1918b: mov       al, byte ptr [rbx + 0x17]
1918e: mov       byte ptr [rbp + 0x14], al
19191: mov       rbp, qword ptr [rsp + 0x88]
19199: mov       rdx, rbp
1919c: call      0x17da0
191a1: jmp       0x191ab
191a3: mov       rbp, qword ptr [rsp + 0x88]
191ab: movzx     ecx, byte ptr [rsi + 0x24]
191af: movzx     eax, word ptr [r12 + 0x2000]
191b8: lea       rdx, [rsp + 0x88]
191c0: lea       r8, [rcx + rcx*2]
191c4: mov       qword ptr [rsp + 0x28], rdx
191c9: mov       dl, cl
191cb: add       r8, r8
191ce: mov       r9, rbx
191d1: mov       rcx, r13
191d4: mov       r8, qword ptr [r12 + r8*8 + 0x1e70]
191dc: mov       dword ptr [rsp + 0x20], eax
191e0: call      0x3d284
191e5: add       dword ptr [r12 + 0x1f9c], 1
191ee: lea       rcx, [r12 + 0x1f80]
191f6: mov       edi, eax
191f8: call      qword ptr [rip + 0x1c062]
191fe: cmp       ax, word ptr [r12 + 0x1f90]
19207: jb        0x1921f
19209: add       dword ptr [r12 + 0x1fa0], 1
19212: mov       rcx, rbx
19215: call      qword ptr [r12 + 0x1fb8]
1921d: jmp       0x19230
1921f: lea       rcx, [r12 + 0x1f80]
19227: mov       rdx, rbx
1922a: call      qword ptr [rip + 0x1c018]
19230: test      edi, edi
19232: mov       r8d, dword ptr [rsp + 0x88]
1923a: jne       0x1925c
1923c: movzx     eax, word ptr [r12 + 0x2000]
19245: cmp       r8d, eax
19248: jne       0x1926c
1924a: cmp       word ptr [rsp + 0x80], 0x1e
19253: je        0x19271
19255: mov       edi, 0x103
1925a: jmp       0x19271
1925c: cmp       edi, 0xc00000b5
19262: je        0x19271
19264: cmp       edi, 0xc000020c
1926a: je        0x19271
1926c: mov       edi, 0xc0000001
19271: mov       ecx, edi
19273: call      0x21370
19278: mov       dword ptr [rsp + 0x30], r8d
1927d: lea       r8, [rip + 0x1029c]
19284: mov       r9, rbp
19287: mov       rdx, r13
1928a: mov       ecx, 3
1928f: mov       qword ptr [rsp + 0x28], rax
19294: and       dword ptr [rsp + 0x20], 0
19299: call      0x121dc
1929e: mov       rbx, qword ptr [rsp + 0x90]
192a6: mov       eax, edi
192a8: add       rsp, 0x40
192ac: pop       r15
192ae: pop       r14
192b0: pop       r13
192b2: pop       r12
192b4: pop       rdi
192b5: pop       rsi
192b6: pop       rbp
192b7: ret       

===== serializer_TDI_SEND @ 0x3d284 =====
3d284: mov       rax, rsp
3d287: mov       qword ptr [rax + 0x20], r9
3d28b: mov       qword ptr [rax + 0x18], r8
3d28f: mov       byte ptr [rax + 0x10], dl
3d292: mov       qword ptr [rax + 8], rcx
3d296: push      rsi
3d297: push      rdi
3d298: push      r12
3d29a: push      r13
3d29c: push      r14
3d29e: push      r15
3d2a0: sub       rsp, 0xa8
3d2a7: mov       r15, r9
3d2aa: mov       r14, r8
3d2ad: mov       r12, rcx
3d2b0: mov       edi, 0xc000009a
3d2b5: mov       dword ptr [rsp + 0x50], edi
3d2b9: mov       rax, qword ptr [rcx + 0x40]
3d2bd: mov       qword ptr [rsp + 0x60], rax
3d2c2: and       dword ptr [rsp + 0x70], 0
3d2c7: xor       eax, eax
3d2c9: mov       dword ptr [rsp + 0x74], eax
3d2cd: mov       qword ptr [rsp + 0x78], rax
3d2d2: movzx     r9d, word ptr [r9 + 0x18]
3d2d7: lea       r8, [rip + 0x38d2]
3d2de: mov       rdx, rcx
3d2e1: lea       ecx, [rax + 3]
3d2e4: call      0x121dc
3d2e9: mov       r13d, dword ptr [rsp + 0x100]
3d2f1: test      r13d, r13d
3d2f4: jne       0x3d305
3d2f6: xor       edi, edi
3d2f8: mov       rsi, qword ptr [rsp + 0x108]
3d300: jmp       0x3d4a8
3d305: mov       rsi, qword ptr [rsp + 0x108]
3d30d: and       dword ptr [rsi], eax
3d30f: test      r14, r14
3d312: jne       0x3d32c
3d314: mov       edi, 0xc000020c
3d319: lea       r8, [rip + 0x38b0]
3d320: xor       ecx, ecx
3d322: call      0x121dc
3d327: jmp       0x3d4a8
3d32c: xor       r8d, r8d
3d32f: xor       edx, edx
3d331: lea       rcx, [rsp + 0x80]
3d339: call      qword ptr [rip - 0x82d7]
3d33f: mov       rcx, r14
3d342: call      qword ptr [rip - 0x8080]
3d348: mov       qword ptr [rsp + 0x58], rax
3d34d: and       qword ptr [rsp + 0x20], 0
3d353: xor       r9d, r9d
3d356: xor       r8d, r8d
3d359: mov       edx, r13d
3d35c: mov       rcx, r15
3d35f: call      qword ptr [rip - 0x807d]
3d365: mov       r13, rax
3d368: mov       qword ptr [rsp + 0x68], rax
3d36d: test      rax, rax
3d370: je        0x3d4a8
3d376: xor       edx, edx
3d378: lea       r8d, [rdx + 2]
3d37c: mov       rcx, rax
3d37f: call      qword ptr [rip - 0x80a5]
3d385: jmp       0x3d3b9
3d387: mov       rcx, qword ptr [rsp + 0x68]
3d38c: call      qword ptr [rip - 0x80c2]
3d392: xor       r13d, r13d
3d395: mov       rsi, qword ptr [rsp + 0x108]
3d39d: mov       r15, qword ptr [rsp + 0xf8]
3d3a5: mov       r14, qword ptr [rsp + 0xf0]
3d3ad: mov       r12, qword ptr [rsp + 0xe0]
3d3b5: mov       edi, dword ptr [rsp + 0x50]
3d3b9: test      r13, r13
3d3bc: je        0x3d4a8
3d3c2: lea       rax, [rsp + 0x70]
3d3c7: mov       qword ptr [rsp + 0x40], rax
3d3cc: lea       rax, [rsp + 0x80]
3d3d4: mov       qword ptr [rsp + 0x38], rax
3d3d9: mov       byte ptr [rsp + 0x30], 1
3d3de: and       dword ptr [rsp + 0x28], 0
3d3e3: and       qword ptr [rsp + 0x20], 0
3d3e9: xor       r9d, r9d
3d3ec: xor       r8d, r8d
3d3ef: mov       rdx, qword ptr [rsp + 0x58]
3d3f4: lea       ecx, [r9 + 3]
3d3f8: call      qword ptr [rip - 0x818e]
3d3fe: mov       rdx, rax
3d401: test      rax, rax
3d404: je        0x3d4a8
3d40a: mov       rax, qword ptr [rax + 0xb8]
3d411: and       qword ptr [rax - 0x10], 0
3d416: and       qword ptr [rax - 8], 0
3d41b: mov       byte ptr [rax - 0x45], 0
3d41f: mov       rax, qword ptr [rdx + 0xb8]
3d426: mov       byte ptr [rax - 0x48], 0xf
3d42a: mov       byte ptr [rax - 0x47], 7
3d42e: mov       r8, qword ptr [rsp + 0x58]
3d433: mov       qword ptr [rax - 0x20], r8
3d437: mov       qword ptr [rax - 0x18], r14
3d43b: mov       dword ptr [rax - 0x3c], 0x180
3d442: mov       ecx, dword ptr [rsp + 0x100]
3d449: mov       dword ptr [rax - 0x40], ecx
3d44c: mov       qword ptr [rdx + 8], r13
3d450: mov       rcx, r8
3d453: call      qword ptr [rip - 0x8381]
3d459: mov       r11d, eax
3d45c: movzx     ecx, byte ptr [rsp + 0xe8]
3d464: imul      rcx, rcx, 0x268
3d46b: xor       eax, eax
3d46d: mov       rdx, qword ptr [rsp + 0x60]
3d472: xchg      dword ptr [rcx + rdx + 0x1018], eax
3d479: cmp       r11d, 0x103
3d480: jne       0x3d49e
3d482: and       qword ptr [rsp + 0x20], 0
3d488: xor       r9d, r9d
3d48b: xor       r8d, r8d
3d48e: xor       edx, edx
3d490: lea       rcx, [rsp + 0x80]
3d498: call      qword ptr [rip - 0x83de]
3d49e: mov       edi, dword ptr [rsp + 0x70]
3d4a2: mov       edx, dword ptr [rsp + 0x78]
3d4a6: mov       dword ptr [rsi], edx
3d4a8: movzx     r8d, word ptr [r15 + 0x18]
3d4ad: mov       ecx, edi
3d4af: call      0x21370
3d4b4: mov       r9, rax
3d4b7: mov       dword ptr [rsp + 0x28], r8d
3d4bc: mov       edx, dword ptr [rsi]
3d4be: mov       dword ptr [rsp + 0x20], edx
3d4c2: lea       r8, [rip + 0x3737]
3d4c9: mov       rdx, r12
3d4cc: mov       ecx, 3
3d4d1: call      0x121dc
3d4d6: mov       eax, edi
3d4d8: add       rsp, 0xa8
3d4df: pop       r15
3d4e1: pop       r14
3d4e3: pop       r13
3d4e5: pop       r12
3d4e7: pop       rdi
3d4e8: pop       rsi
3d4e9: ret       

===== NetworkConnectionOpen @ 0x14adc =====
14adc: mov       rax, rsp
14adf: mov       qword ptr [rax + 8], rbx
14ae3: mov       qword ptr [rax + 0x10], rbp
14ae7: mov       qword ptr [rax + 0x18], rsi
14aeb: mov       qword ptr [rax + 0x20], rdi
14aef: push      r12
14af1: sub       rsp, 0x30
14af5: movzx     ebp, r8w
14af9: mov       r12d, edx
14afc: mov       rdx, rcx
14aff: lea       r8, [rip + 0x12f5a]
14b06: mov       rsi, rcx
14b09: mov       ecx, 2
14b0e: mov       rbx, r9
14b11: call      0x121dc
14b16: mov       rcx, r9
14b19: call      0x3cbb8
14b1e: mov       ecx, eax
14b20: mov       edi, eax
14b22: call      0x21370
14b27: lea       r8, [rip + 0x12f52]
14b2e: mov       rdx, rsi
14b31: mov       r9, rax
14b34: mov       ecx, 2
14b39: call      0x121dc
14b3e: test      edi, edi
14b40: jne       0x14bc9
14b46: mov       rdx, qword ptr [rbx + 0x20]
14b4a: lea       r8d, [rcx - 1]
14b4e: lea       r9, [rip + 0x100bb]
14b55: mov       rcx, rsi
14b58: mov       qword ptr [rsp + 0x20], rbx
14b5d: call      0x3d4f0
14b62: mov       ecx, eax
14b64: mov       edi, eax
14b66: call      0x21370
14b6b: lea       r8, [rip + 0x12f5e]
14b72: mov       rdx, rsi
14b75: mov       r9, rax
14b78: mov       ecx, 2
14b7d: call      0x121dc
14b82: test      edi, edi
14b84: jne       0x14bc1
14b86: mov       rcx, qword ptr [rbx + 0x28]
14b8a: ror       bp, 8
14b8e: bswap     r12d
14b91: movzx     r8d, bp
14b95: mov       edx, r12d
14b98: call      0x3d080
14b9d: mov       ecx, eax
14b9f: mov       edi, eax
14ba1: call      0x21370
14ba6: lea       r8, [rip + 0x12f73]
14bad: mov       rdx, rsi
14bb0: mov       r9, rax
14bb3: mov       ecx, 2
14bb8: call      0x121dc
14bbd: test      edi, edi
14bbf: je        0x14bc9
14bc1: mov       rcx, rbx
14bc4: call      0x3ce20
14bc9: mov       rbx, qword ptr [rsp + 0x40]
14bce: mov       rbp, qword ptr [rsp + 0x48]
14bd3: mov       rsi, qword ptr [rsp + 0x50]
14bd8: mov       eax, edi
14bda: mov       rdi, qword ptr [rsp + 0x58]
14bdf: add       rsp, 0x30
14be3: pop       r12
14be5: ret       

===== SendKeepAlivePacketCallback @ 0x17e54 =====
17e54: mov       qword ptr [rsp + 0x10], rbx
17e59: mov       qword ptr [rsp + 0x18], rbp
17e5e: mov       qword ptr [rsp + 0x20], rsi
17e63: push      rdi
17e64: push      r12
17e66: push      r13
17e68: push      r14
17e6a: push      r15
17e6c: sub       rsp, 0x30
17e70: movzx     r9d, byte ptr [rdx + 0x12]
17e75: mov       r12, qword ptr [rcx + 0x40]
17e79: mov       rbp, rdx
17e7c: mov       rdx, rcx
17e7f: lea       r8, [rip + 0x10f4a]
17e86: mov       rsi, rcx
17e89: mov       ecx, 3
17e8e: call      0x121dc
17e93: cmp       dword ptr [r12 + 0xb0], 0
17e9c: jne       0x17eb9
17e9e: movzx     r9d, byte ptr [rbp + 0x12]
17ea3: lea       r8, [rip + 0x10f66]
17eaa: mov       ecx, 1
17eaf: call      0x121dc
17eb4: jmp       0x181a7
17eb9: lea       r14, [r12 + 0xa0]
17ec1: mov       edi, 1
17ec6: mov       rbx, qword ptr [r14]
17ec9: cmp       rbx, r14
17ecc: je        0x18085
17ed2: movzx     eax, byte ptr [rbx + 0x199]
17ed9: movzx     r9d, byte ptr [rbx - 0x34]
17ede: lea       r8, [rip + 0x10f7b]
17ee5: mov       rdx, rsi
17ee8: mov       ecx, edi
17eea: mov       dword ptr [rsp + 0x20], eax
17eee: call      0x121dc
17ef3: mov       al, byte ptr [rbp + 0x12]
17ef6: cmp       byte ptr [rbx - 0x34], al
17ef9: jne       0x18022
17eff: cmp       byte ptr [rbx + 0x11], dil
17f03: jne       0x18022
17f09: cmp       byte ptr [rbx + 0x199], 8
17f10: jne       0x18022
17f16: and       qword ptr [rsp + 0x60], 0
17f1c: movzx     eax, byte ptr [rbx - 0x34]
17f20: xor       r9d, r9d
17f23: xor       r8d, r8d
17f26: xor       edx, edx
17f28: imul      rax, rax, 0x268
17f2f: lea       rcx, [rax + r12 + 0x10c0]
17f37: lea       rax, [rsp + 0x60]
17f3c: mov       qword ptr [rsp + 0x20], rax
17f41: call      qword ptr [rip + 0x1d179]
17f47: cmp       eax, 0x102
17f4c: jne       0x18000
17f52: movzx     eax, byte ptr [rbp + 0x12]
17f56: lea       rcx, [rax + rax*2]
17f5a: add       rcx, rcx
17f5d: lea       rdx, [r12 + rcx*8 + 0x1e48]
17f65: mov       rcx, rsi
17f68: call      0x14bec
17f6d: mov       ecx, eax
17f6f: call      0x21370
17f74: movzx     r9d, byte ptr [rbp + 0x12]
17f79: lea       r8, [rip + 0x10f40]
17f80: mov       rdx, rsi
17f83: mov       ecx, edi
17f85: mov       qword ptr [rsp + 0x20], rax
17f8a: call      0x121dc
17f8f: mov       ecx, 0x1f4
17f94: call      0x120dc
17f99: mov       r8b, byte ptr [rbp + 0x12]
17f9d: mov       r9b, 0xff
17fa0: xor       edx, edx
17fa2: mov       rcx, rsi
17fa5: call      0x145ec
17faa: mov       ecx, 0x1f4
17faf: call      0x120dc
17fb4: mov       byte ptr [rbx + 0x15], 0
17fb8: xor       r15b, r15b
17fbb: lea       rax, [r12 + 0x3a0]
17fc3: lea       rcx, [r12 + 0x218]
17fcb: mov       rdx, rax
17fce: call      qword ptr [rip + 0x1d07c]
17fd4: test      rax, rax
17fd7: mov       r13, rax
17fda: jne       0x1802a
17fdc: add       r15b, dil
17fdf: lea       rax, [r12 + 0x3a0]
17fe7: lea       rcx, [r12 + 0x218]
17fef: cmp       r15b, 0x17
17ff3: jb        0x17fcb
17ff5: lea       ecx, [r13 + 0x64]
17ff9: call      0x120dc
17ffe: jmp       0x18022
18000: mov       ecx, eax
18002: call      0x21370
18007: movzx     r9d, byte ptr [rbp + 0x12]
1800c: lea       r8, [rip + 0x10f4d]
18013: mov       rdx, rsi
18016: mov       ecx, edi
18018: mov       qword ptr [rsp + 0x20], rax
1801d: call      0x121dc
18022: mov       rbx, qword ptr [rbx]
18025: jmp       0x17ec9
1802a: mov       rcx, qword ptr [rax + 0x18]
1802e: lea       r8, [rip + 0x10edb]
18035: mov       rdx, rsi
18038: mov       dword ptr [rcx + 4], 0x24544e55
1803f: mov       word ptr [rcx + 2], 0x200
18045: mov       al, byte ptr [rbx - 0x34]
18048: mov       byte ptr [rcx + 8], al
1804b: mov       dword ptr [rcx + 9], 0xc000020c
18052: and       dword ptr [r13 + 0x30], 0
18057: mov       qword ptr [r13 + 0x38], 0x40d
1805f: movzx     r9d, byte ptr [rcx + 8]
18064: mov       ecx, edi
18066: call      0x121dc
1806b: mov       ecx, 0x7d0
18070: call      0x120dc
18075: xor       edx, edx
18077: mov       rcx, r13
1807a: call      qword ptr [rip + 0x1d020]
18080: jmp       0x181a7
18085: xor       r8d, r8d
18088: mov       rdx, r12
1808b: mov       rcx, rsi
1808e: call      0x1bd38
18093: test      rax, rax
18096: mov       rbx, rax
18099: je        0x181a7
1809f: xor       edx, edx
180a1: mov       rcx, rax
180a4: lea       r8d, [rdx + 0x20]
180a8: call      0x251f0
180ad: lea       r8, [rip + 0x10efc]
180b4: mov       ecx, 3
180b9: movdqu    xmm5, xmmword ptr [rip + 0x1dbff]
180c1: mov       dword ptr [rbx + 0x10], 0x24544e55
180c8: mov       byte ptr [rbx + 0x17], 0x12
180cc: movdqu    xmmword ptr [rbx], xmm5
180d0: mov       dl, byte ptr [rbp + 0x12]
180d3: mov       byte ptr [rbx + 0x16], dl
180d6: movzx     eax, word ptr [rbp + 0x10]
180da: mov       rdx, rsi
180dd: mov       word ptr [rbx + 0x18], ax
180e1: movzx     r9d, byte ptr [rbp + 0x12]
180e6: mov       dword ptr [rsp + 0x20], eax
180ea: call      0x121dc
180ef: movzx     eax, byte ptr [rbp + 0x12]
180f3: imul      rax, rax, 0x268
180fa: lea       rcx, [rax + r12 + 0x10c0]
18102: call      qword ptr [rip + 0x1cfa8]
18108: movzx     r11d, byte ptr [rbp + 0x12]
1810d: movzx     eax, word ptr [r12 + 0x2000]
18116: lea       r8, [r11 + r11*2]
1811a: lea       rcx, [rsp + 0x60]
1811f: mov       r9, rbx
18122: mov       qword ptr [rsp + 0x28], rcx
18127: add       r8, r8
1812a: mov       dl, r11b
1812d: mov       r8, qword ptr [r12 + r8*8 + 0x1e70]
18135: mov       rcx, rsi
18138: mov       dword ptr [rsp + 0x20], eax
1813c: call      0x3d284
18141: movzx     r11d, byte ptr [rbp + 0x12]
18146: xor       r8d, r8d
18149: xor       edx, edx
1814b: imul      r11, r11, 0x268
18152: lea       rcx, [r11 + r12 + 0x10c0]
1815a: call      qword ptr [rip + 0x1d050]
18160: add       dword ptr [r12 + 0x1f9c], edi
18168: lea       rcx, [r12 + 0x1f80]
18170: call      qword ptr [rip + 0x1d0ea]
18176: cmp       ax, word ptr [r12 + 0x1f90]
1817f: jb        0x18196
18181: add       dword ptr [r12 + 0x1fa0], edi
18189: mov       rcx, rbx
1818c: call      qword ptr [r12 + 0x1fb8]
18194: jmp       0x181a7
18196: lea       rcx, [r12 + 0x1f80]
1819e: mov       rdx, rbx
181a1: call      qword ptr [rip + 0x1d0a1]
181a7: mov       rcx, qword ptr [rbp + 0x18]
181ab: test      rcx, rcx
181ae: je        0x181b6
181b0: call      qword ptr [rip + 0x1d052]
181b6: mov       edx, 0x53747345
181bb: mov       rcx, rbp
181be: mov       rbx, qword ptr [rsp + 0x68]
181c3: mov       rbp, qword ptr [rsp + 0x70]
181c8: mov       rsi, qword ptr [rsp + 0x78]
181cd: add       rsp, 0x30
181d1: pop       r15
181d3: pop       r14
181d5: pop       r13
181d7: pop       r12
181d9: pop       rdi
181da: jmp       qword ptr [rip + 0x1ceff]
