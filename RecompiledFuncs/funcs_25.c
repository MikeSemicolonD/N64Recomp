#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void func_800934A4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800934A4: addu        $t0, $a0, $zero
    ctx->r8 = ADD32(ctx->r4, 0);
    // 0x800934A8: srl         $t1, $a1, 2
    ctx->r9 = S32(U32(ctx->r5) >> 2);
L_800934AC:
    // 0x800934AC: nop

    // 0x800934B0: sd          $zero, 0x0($t0)
    SD(0, 0X0, ctx->r8);
    // 0x800934B4: sd          $zero, 0x8($t0)
    SD(0, 0X8, ctx->r8);
    // 0x800934B8: addiu       $t1, $t1, -0x1
    ctx->r9 = ADD32(ctx->r9, -0X1);
    // 0x800934BC: nop

    // 0x800934C0: bne         $t1, $zero, L_800934AC
    if (ctx->r9 != 0) {
        // 0x800934C4: addiu       $t0, $t0, 0x10
        ctx->r8 = ADD32(ctx->r8, 0X10);
            goto L_800934AC;
    }
    // 0x800934C4: addiu       $t0, $t0, 0x10
    ctx->r8 = ADD32(ctx->r8, 0X10);
    // 0x800934C8: jr          $ra
    // 0x800934CC: nop

    return;
    // 0x800934CC: nop

;}
RECOMP_FUNC void func_800934D0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800934D0: addu        $t6, $a1, $zero
    ctx->r14 = ADD32(ctx->r5, 0);
    // 0x800934D4: ld          $t8, 0x0($a0)
    ctx->r24 = LD(ctx->r4, 0X0);
    // 0x800934D8: lui         $t5, 0x800A
    ctx->r13 = S32(0X800A << 16);
    // 0x800934DC: ori         $t5, $t5, 0x1990
    ctx->r13 = ctx->r13 | 0X1990;
    // 0x800934E0: dsra32      $t0, $t8, 16
    ctx->r8 = SIGNED(ctx->r24) >> (16 + 32);
    // 0x800934E4: dsrl32      $t1, $t8, 8
    ctx->r9 = ctx->r24 >> (8 + 32);
    // 0x800934E8: andi        $t1, $t1, 0xFF
    ctx->r9 = ctx->r9 & 0XFF;
    // 0x800934EC: ld          $t9, 0x8($a0)
    ctx->r25 = LD(ctx->r4, 0X8);
    // 0x800934F0: dsrl32      $t2, $t8, 0
    ctx->r10 = ctx->r24 >> (0 + 32);
    // 0x800934F4: andi        $t2, $t2, 0xF
    ctx->r10 = ctx->r10 & 0XF;
    // 0x800934F8: sll         $t3, $t1, 4
    ctx->r11 = S32(ctx->r9 << 4);
    // 0x800934FC: addu        $t3, $t3, $t2
    ctx->r11 = ADD32(ctx->r11, ctx->r10);
    // 0x80093500: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x80093504: addu        $t3, $t3, $t5
    ctx->r11 = ADD32(ctx->r11, ctx->r13);
    // 0x80093508: lw          $t4, 0x0($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X0);
    // 0x8009350C: addiu       $t6, $t6, 0x2
    ctx->r14 = ADD32(ctx->r14, 0X2);
    // 0x80093510: andi        $t1, $t4, 0xFF
    ctx->r9 = ctx->r12 & 0XFF;
    // 0x80093514: sra         $t4, $t4, 8
    ctx->r12 = S32(SIGNED(ctx->r12) >> 8);
    // 0x80093518: addu        $t0, $t0, $t4
    ctx->r8 = ADD32(ctx->r8, ctx->r12);
    // 0x8009351C: slti        $t3, $t0, 0x7FFF
    ctx->r11 = SIGNED(ctx->r8) < 0X7FFF ? 1 : 0;
    // 0x80093520: bne         $t3, $zero, L_80093530
    if (ctx->r11 != 0) {
        // 0x80093524: slti        $t3, $t0, -0x8000
        ctx->r11 = SIGNED(ctx->r8) < -0X8000 ? 1 : 0;
            goto L_80093530;
    }
    // 0x80093524: slti        $t3, $t0, -0x8000
    ctx->r11 = SIGNED(ctx->r8) < -0X8000 ? 1 : 0;
    // 0x80093528: j           L_8009353C
    // 0x8009352C: ori         $t0, $zero, 0x7FFF
    ctx->r8 = 0 | 0X7FFF;
        goto L_8009353C;
    // 0x8009352C: ori         $t0, $zero, 0x7FFF
    ctx->r8 = 0 | 0X7FFF;
L_80093530:
    // 0x80093530: beq         $t3, $zero, L_8009353C
    if (ctx->r11 == 0) {
        // 0x80093534: nop
    
            goto L_8009353C;
    }
    // 0x80093534: nop

    // 0x80093538: addiu       $t0, $zero, -0x7FFF
    ctx->r8 = ADD32(0, -0X7FFF);
L_8009353C:
    // 0x8009353C: sh          $t0, -0x2($t6)
    MEM_H(-0X2, ctx->r14) = ctx->r8;
    // 0x80093540: dsrl32      $t2, $t8, 4
    ctx->r10 = ctx->r24 >> (4 + 32);
    // 0x80093544: andi        $t2, $t2, 0xF
    ctx->r10 = ctx->r10 & 0XF;
    // 0x80093548: sll         $t3, $t1, 4
    ctx->r11 = S32(ctx->r9 << 4);
    // 0x8009354C: addu        $t3, $t3, $t2
    ctx->r11 = ADD32(ctx->r11, ctx->r10);
    // 0x80093550: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x80093554: addu        $t3, $t3, $t5
    ctx->r11 = ADD32(ctx->r11, ctx->r13);
    // 0x80093558: lw          $t4, 0x0($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X0);
    // 0x8009355C: addiu       $t6, $t6, 0x2
    ctx->r14 = ADD32(ctx->r14, 0X2);
    // 0x80093560: andi        $t1, $t4, 0xFF
    ctx->r9 = ctx->r12 & 0XFF;
    // 0x80093564: sra         $t4, $t4, 8
    ctx->r12 = S32(SIGNED(ctx->r12) >> 8);
    // 0x80093568: addu        $t0, $t0, $t4
    ctx->r8 = ADD32(ctx->r8, ctx->r12);
    // 0x8009356C: slti        $t3, $t0, 0x7FFF
    ctx->r11 = SIGNED(ctx->r8) < 0X7FFF ? 1 : 0;
    // 0x80093570: bne         $t3, $zero, L_80093580
    if (ctx->r11 != 0) {
        // 0x80093574: slti        $t3, $t0, -0x8000
        ctx->r11 = SIGNED(ctx->r8) < -0X8000 ? 1 : 0;
            goto L_80093580;
    }
    // 0x80093574: slti        $t3, $t0, -0x8000
    ctx->r11 = SIGNED(ctx->r8) < -0X8000 ? 1 : 0;
    // 0x80093578: j           L_8009358C
    // 0x8009357C: ori         $t0, $zero, 0x7FFF
    ctx->r8 = 0 | 0X7FFF;
        goto L_8009358C;
    // 0x8009357C: ori         $t0, $zero, 0x7FFF
    ctx->r8 = 0 | 0X7FFF;
L_80093580:
    // 0x80093580: beq         $t3, $zero, L_8009358C
    if (ctx->r11 == 0) {
        // 0x80093584: nop
    
            goto L_8009358C;
    }
    // 0x80093584: nop

    // 0x80093588: addiu       $t0, $zero, -0x7FFF
    ctx->r8 = ADD32(0, -0X7FFF);
L_8009358C:
    // 0x8009358C: sh          $t0, -0x2($t6)
    MEM_H(-0X2, ctx->r14) = ctx->r8;
    // 0x80093590: srl         $t2, $t8, 24
    ctx->r10 = S32(U32(ctx->r24) >> 24);
    // 0x80093594: andi        $t2, $t2, 0xF
    ctx->r10 = ctx->r10 & 0XF;
    // 0x80093598: sll         $t3, $t1, 4
    ctx->r11 = S32(ctx->r9 << 4);
    // 0x8009359C: addu        $t3, $t3, $t2
    ctx->r11 = ADD32(ctx->r11, ctx->r10);
    // 0x800935A0: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x800935A4: addu        $t3, $t3, $t5
    ctx->r11 = ADD32(ctx->r11, ctx->r13);
    // 0x800935A8: lw          $t4, 0x0($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X0);
    // 0x800935AC: addiu       $t6, $t6, 0x2
    ctx->r14 = ADD32(ctx->r14, 0X2);
    // 0x800935B0: andi        $t1, $t4, 0xFF
    ctx->r9 = ctx->r12 & 0XFF;
    // 0x800935B4: sra         $t4, $t4, 8
    ctx->r12 = S32(SIGNED(ctx->r12) >> 8);
    // 0x800935B8: addu        $t0, $t0, $t4
    ctx->r8 = ADD32(ctx->r8, ctx->r12);
    // 0x800935BC: slti        $t3, $t0, 0x7FFF
    ctx->r11 = SIGNED(ctx->r8) < 0X7FFF ? 1 : 0;
    // 0x800935C0: bne         $t3, $zero, L_800935D0
    if (ctx->r11 != 0) {
        // 0x800935C4: slti        $t3, $t0, -0x8000
        ctx->r11 = SIGNED(ctx->r8) < -0X8000 ? 1 : 0;
            goto L_800935D0;
    }
    // 0x800935C4: slti        $t3, $t0, -0x8000
    ctx->r11 = SIGNED(ctx->r8) < -0X8000 ? 1 : 0;
    // 0x800935C8: j           L_800935DC
    // 0x800935CC: ori         $t0, $zero, 0x7FFF
    ctx->r8 = 0 | 0X7FFF;
        goto L_800935DC;
    // 0x800935CC: ori         $t0, $zero, 0x7FFF
    ctx->r8 = 0 | 0X7FFF;
L_800935D0:
    // 0x800935D0: beq         $t3, $zero, L_800935DC
    if (ctx->r11 == 0) {
        // 0x800935D4: nop
    
            goto L_800935DC;
    }
    // 0x800935D4: nop

    // 0x800935D8: addiu       $t0, $zero, -0x7FFF
    ctx->r8 = ADD32(0, -0X7FFF);
L_800935DC:
    // 0x800935DC: sh          $t0, -0x2($t6)
    MEM_H(-0X2, ctx->r14) = ctx->r8;
    // 0x800935E0: srl         $t2, $t8, 28
    ctx->r10 = S32(U32(ctx->r24) >> 28);
    // 0x800935E4: andi        $t2, $t2, 0xF
    ctx->r10 = ctx->r10 & 0XF;
    // 0x800935E8: sll         $t3, $t1, 4
    ctx->r11 = S32(ctx->r9 << 4);
    // 0x800935EC: addu        $t3, $t3, $t2
    ctx->r11 = ADD32(ctx->r11, ctx->r10);
    // 0x800935F0: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x800935F4: addu        $t3, $t3, $t5
    ctx->r11 = ADD32(ctx->r11, ctx->r13);
    // 0x800935F8: lw          $t4, 0x0($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X0);
    // 0x800935FC: addiu       $t6, $t6, 0x2
    ctx->r14 = ADD32(ctx->r14, 0X2);
    // 0x80093600: andi        $t1, $t4, 0xFF
    ctx->r9 = ctx->r12 & 0XFF;
    // 0x80093604: sra         $t4, $t4, 8
    ctx->r12 = S32(SIGNED(ctx->r12) >> 8);
    // 0x80093608: addu        $t0, $t0, $t4
    ctx->r8 = ADD32(ctx->r8, ctx->r12);
    // 0x8009360C: slti        $t3, $t0, 0x7FFF
    ctx->r11 = SIGNED(ctx->r8) < 0X7FFF ? 1 : 0;
    // 0x80093610: bne         $t3, $zero, L_80093620
    if (ctx->r11 != 0) {
        // 0x80093614: slti        $t3, $t0, -0x8000
        ctx->r11 = SIGNED(ctx->r8) < -0X8000 ? 1 : 0;
            goto L_80093620;
    }
    // 0x80093614: slti        $t3, $t0, -0x8000
    ctx->r11 = SIGNED(ctx->r8) < -0X8000 ? 1 : 0;
    // 0x80093618: j           L_8009362C
    // 0x8009361C: ori         $t0, $zero, 0x7FFF
    ctx->r8 = 0 | 0X7FFF;
        goto L_8009362C;
    // 0x8009361C: ori         $t0, $zero, 0x7FFF
    ctx->r8 = 0 | 0X7FFF;
L_80093620:
    // 0x80093620: beq         $t3, $zero, L_8009362C
    if (ctx->r11 == 0) {
        // 0x80093624: nop
    
            goto L_8009362C;
    }
    // 0x80093624: nop

    // 0x80093628: addiu       $t0, $zero, -0x7FFF
    ctx->r8 = ADD32(0, -0X7FFF);
L_8009362C:
    // 0x8009362C: sh          $t0, -0x2($t6)
    MEM_H(-0X2, ctx->r14) = ctx->r8;
    // 0x80093630: srl         $t2, $t8, 16
    ctx->r10 = S32(U32(ctx->r24) >> 16);
    // 0x80093634: andi        $t2, $t2, 0xF
    ctx->r10 = ctx->r10 & 0XF;
    // 0x80093638: sll         $t3, $t1, 4
    ctx->r11 = S32(ctx->r9 << 4);
    // 0x8009363C: addu        $t3, $t3, $t2
    ctx->r11 = ADD32(ctx->r11, ctx->r10);
    // 0x80093640: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x80093644: addu        $t3, $t3, $t5
    ctx->r11 = ADD32(ctx->r11, ctx->r13);
    // 0x80093648: lw          $t4, 0x0($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X0);
    // 0x8009364C: addiu       $t6, $t6, 0x2
    ctx->r14 = ADD32(ctx->r14, 0X2);
    // 0x80093650: andi        $t1, $t4, 0xFF
    ctx->r9 = ctx->r12 & 0XFF;
    // 0x80093654: sra         $t4, $t4, 8
    ctx->r12 = S32(SIGNED(ctx->r12) >> 8);
    // 0x80093658: addu        $t0, $t0, $t4
    ctx->r8 = ADD32(ctx->r8, ctx->r12);
    // 0x8009365C: slti        $t3, $t0, 0x7FFF
    ctx->r11 = SIGNED(ctx->r8) < 0X7FFF ? 1 : 0;
    // 0x80093660: bne         $t3, $zero, L_80093670
    if (ctx->r11 != 0) {
        // 0x80093664: slti        $t3, $t0, -0x8000
        ctx->r11 = SIGNED(ctx->r8) < -0X8000 ? 1 : 0;
            goto L_80093670;
    }
    // 0x80093664: slti        $t3, $t0, -0x8000
    ctx->r11 = SIGNED(ctx->r8) < -0X8000 ? 1 : 0;
    // 0x80093668: j           L_8009367C
    // 0x8009366C: ori         $t0, $zero, 0x7FFF
    ctx->r8 = 0 | 0X7FFF;
        goto L_8009367C;
    // 0x8009366C: ori         $t0, $zero, 0x7FFF
    ctx->r8 = 0 | 0X7FFF;
L_80093670:
    // 0x80093670: beq         $t3, $zero, L_8009367C
    if (ctx->r11 == 0) {
        // 0x80093674: nop
    
            goto L_8009367C;
    }
    // 0x80093674: nop

    // 0x80093678: addiu       $t0, $zero, -0x7FFF
    ctx->r8 = ADD32(0, -0X7FFF);
L_8009367C:
    // 0x8009367C: sh          $t0, -0x2($t6)
    MEM_H(-0X2, ctx->r14) = ctx->r8;
    // 0x80093680: srl         $t2, $t8, 20
    ctx->r10 = S32(U32(ctx->r24) >> 20);
    // 0x80093684: andi        $t2, $t2, 0xF
    ctx->r10 = ctx->r10 & 0XF;
    // 0x80093688: sll         $t3, $t1, 4
    ctx->r11 = S32(ctx->r9 << 4);
    // 0x8009368C: addu        $t3, $t3, $t2
    ctx->r11 = ADD32(ctx->r11, ctx->r10);
    // 0x80093690: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x80093694: addu        $t3, $t3, $t5
    ctx->r11 = ADD32(ctx->r11, ctx->r13);
    // 0x80093698: lw          $t4, 0x0($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X0);
    // 0x8009369C: addiu       $t6, $t6, 0x2
    ctx->r14 = ADD32(ctx->r14, 0X2);
    // 0x800936A0: andi        $t1, $t4, 0xFF
    ctx->r9 = ctx->r12 & 0XFF;
    // 0x800936A4: sra         $t4, $t4, 8
    ctx->r12 = S32(SIGNED(ctx->r12) >> 8);
    // 0x800936A8: addu        $t0, $t0, $t4
    ctx->r8 = ADD32(ctx->r8, ctx->r12);
    // 0x800936AC: slti        $t3, $t0, 0x7FFF
    ctx->r11 = SIGNED(ctx->r8) < 0X7FFF ? 1 : 0;
    // 0x800936B0: bne         $t3, $zero, L_800936C0
    if (ctx->r11 != 0) {
        // 0x800936B4: slti        $t3, $t0, -0x8000
        ctx->r11 = SIGNED(ctx->r8) < -0X8000 ? 1 : 0;
            goto L_800936C0;
    }
    // 0x800936B4: slti        $t3, $t0, -0x8000
    ctx->r11 = SIGNED(ctx->r8) < -0X8000 ? 1 : 0;
    // 0x800936B8: j           L_800936CC
    // 0x800936BC: ori         $t0, $zero, 0x7FFF
    ctx->r8 = 0 | 0X7FFF;
        goto L_800936CC;
    // 0x800936BC: ori         $t0, $zero, 0x7FFF
    ctx->r8 = 0 | 0X7FFF;
L_800936C0:
    // 0x800936C0: beq         $t3, $zero, L_800936CC
    if (ctx->r11 == 0) {
        // 0x800936C4: nop
    
            goto L_800936CC;
    }
    // 0x800936C4: nop

    // 0x800936C8: addiu       $t0, $zero, -0x7FFF
    ctx->r8 = ADD32(0, -0X7FFF);
L_800936CC:
    // 0x800936CC: sh          $t0, -0x2($t6)
    MEM_H(-0X2, ctx->r14) = ctx->r8;
    // 0x800936D0: srl         $t2, $t8, 8
    ctx->r10 = S32(U32(ctx->r24) >> 8);
    // 0x800936D4: andi        $t2, $t2, 0xF
    ctx->r10 = ctx->r10 & 0XF;
    // 0x800936D8: sll         $t3, $t1, 4
    ctx->r11 = S32(ctx->r9 << 4);
    // 0x800936DC: addu        $t3, $t3, $t2
    ctx->r11 = ADD32(ctx->r11, ctx->r10);
    // 0x800936E0: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x800936E4: addu        $t3, $t3, $t5
    ctx->r11 = ADD32(ctx->r11, ctx->r13);
    // 0x800936E8: lw          $t4, 0x0($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X0);
    // 0x800936EC: addiu       $t6, $t6, 0x2
    ctx->r14 = ADD32(ctx->r14, 0X2);
    // 0x800936F0: andi        $t1, $t4, 0xFF
    ctx->r9 = ctx->r12 & 0XFF;
    // 0x800936F4: sra         $t4, $t4, 8
    ctx->r12 = S32(SIGNED(ctx->r12) >> 8);
    // 0x800936F8: addu        $t0, $t0, $t4
    ctx->r8 = ADD32(ctx->r8, ctx->r12);
    // 0x800936FC: slti        $t3, $t0, 0x7FFF
    ctx->r11 = SIGNED(ctx->r8) < 0X7FFF ? 1 : 0;
    // 0x80093700: bne         $t3, $zero, L_80093710
    if (ctx->r11 != 0) {
        // 0x80093704: slti        $t3, $t0, -0x8000
        ctx->r11 = SIGNED(ctx->r8) < -0X8000 ? 1 : 0;
            goto L_80093710;
    }
    // 0x80093704: slti        $t3, $t0, -0x8000
    ctx->r11 = SIGNED(ctx->r8) < -0X8000 ? 1 : 0;
    // 0x80093708: j           L_8009371C
    // 0x8009370C: ori         $t0, $zero, 0x7FFF
    ctx->r8 = 0 | 0X7FFF;
        goto L_8009371C;
    // 0x8009370C: ori         $t0, $zero, 0x7FFF
    ctx->r8 = 0 | 0X7FFF;
L_80093710:
    // 0x80093710: beq         $t3, $zero, L_8009371C
    if (ctx->r11 == 0) {
        // 0x80093714: nop
    
            goto L_8009371C;
    }
    // 0x80093714: nop

    // 0x80093718: addiu       $t0, $zero, -0x7FFF
    ctx->r8 = ADD32(0, -0X7FFF);
L_8009371C:
    // 0x8009371C: sh          $t0, -0x2($t6)
    MEM_H(-0X2, ctx->r14) = ctx->r8;
    // 0x80093720: srl         $t2, $t8, 12
    ctx->r10 = S32(U32(ctx->r24) >> 12);
    // 0x80093724: andi        $t2, $t2, 0xF
    ctx->r10 = ctx->r10 & 0XF;
    // 0x80093728: sll         $t3, $t1, 4
    ctx->r11 = S32(ctx->r9 << 4);
    // 0x8009372C: addu        $t3, $t3, $t2
    ctx->r11 = ADD32(ctx->r11, ctx->r10);
    // 0x80093730: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x80093734: addu        $t3, $t3, $t5
    ctx->r11 = ADD32(ctx->r11, ctx->r13);
    // 0x80093738: lw          $t4, 0x0($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X0);
    // 0x8009373C: addiu       $t6, $t6, 0x2
    ctx->r14 = ADD32(ctx->r14, 0X2);
    // 0x80093740: andi        $t1, $t4, 0xFF
    ctx->r9 = ctx->r12 & 0XFF;
    // 0x80093744: sra         $t4, $t4, 8
    ctx->r12 = S32(SIGNED(ctx->r12) >> 8);
    // 0x80093748: addu        $t0, $t0, $t4
    ctx->r8 = ADD32(ctx->r8, ctx->r12);
    // 0x8009374C: slti        $t3, $t0, 0x7FFF
    ctx->r11 = SIGNED(ctx->r8) < 0X7FFF ? 1 : 0;
    // 0x80093750: bne         $t3, $zero, L_80093760
    if (ctx->r11 != 0) {
        // 0x80093754: slti        $t3, $t0, -0x8000
        ctx->r11 = SIGNED(ctx->r8) < -0X8000 ? 1 : 0;
            goto L_80093760;
    }
    // 0x80093754: slti        $t3, $t0, -0x8000
    ctx->r11 = SIGNED(ctx->r8) < -0X8000 ? 1 : 0;
    // 0x80093758: j           L_8009376C
    // 0x8009375C: ori         $t0, $zero, 0x7FFF
    ctx->r8 = 0 | 0X7FFF;
        goto L_8009376C;
    // 0x8009375C: ori         $t0, $zero, 0x7FFF
    ctx->r8 = 0 | 0X7FFF;
L_80093760:
    // 0x80093760: beq         $t3, $zero, L_8009376C
    if (ctx->r11 == 0) {
        // 0x80093764: nop
    
            goto L_8009376C;
    }
    // 0x80093764: nop

    // 0x80093768: addiu       $t0, $zero, -0x7FFF
    ctx->r8 = ADD32(0, -0X7FFF);
L_8009376C:
    // 0x8009376C: sh          $t0, -0x2($t6)
    MEM_H(-0X2, ctx->r14) = ctx->r8;
    // 0x80093770: andi        $t2, $t8, 0xF
    ctx->r10 = ctx->r24 & 0XF;
    // 0x80093774: sll         $t3, $t1, 4
    ctx->r11 = S32(ctx->r9 << 4);
    // 0x80093778: addu        $t3, $t3, $t2
    ctx->r11 = ADD32(ctx->r11, ctx->r10);
    // 0x8009377C: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x80093780: addu        $t3, $t3, $t5
    ctx->r11 = ADD32(ctx->r11, ctx->r13);
    // 0x80093784: lw          $t4, 0x0($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X0);
    // 0x80093788: addiu       $t6, $t6, 0x2
    ctx->r14 = ADD32(ctx->r14, 0X2);
    // 0x8009378C: andi        $t1, $t4, 0xFF
    ctx->r9 = ctx->r12 & 0XFF;
    // 0x80093790: sra         $t4, $t4, 8
    ctx->r12 = S32(SIGNED(ctx->r12) >> 8);
    // 0x80093794: addu        $t0, $t0, $t4
    ctx->r8 = ADD32(ctx->r8, ctx->r12);
    // 0x80093798: slti        $t3, $t0, 0x7FFF
    ctx->r11 = SIGNED(ctx->r8) < 0X7FFF ? 1 : 0;
    // 0x8009379C: bne         $t3, $zero, L_800937AC
    if (ctx->r11 != 0) {
        // 0x800937A0: slti        $t3, $t0, -0x8000
        ctx->r11 = SIGNED(ctx->r8) < -0X8000 ? 1 : 0;
            goto L_800937AC;
    }
    // 0x800937A0: slti        $t3, $t0, -0x8000
    ctx->r11 = SIGNED(ctx->r8) < -0X8000 ? 1 : 0;
    // 0x800937A4: j           L_800937B8
    // 0x800937A8: ori         $t0, $zero, 0x7FFF
    ctx->r8 = 0 | 0X7FFF;
        goto L_800937B8;
    // 0x800937A8: ori         $t0, $zero, 0x7FFF
    ctx->r8 = 0 | 0X7FFF;
L_800937AC:
    // 0x800937AC: beq         $t3, $zero, L_800937B8
    if (ctx->r11 == 0) {
        // 0x800937B0: nop
    
            goto L_800937B8;
    }
    // 0x800937B0: nop

    // 0x800937B4: addiu       $t0, $zero, -0x7FFF
    ctx->r8 = ADD32(0, -0X7FFF);
L_800937B8:
    // 0x800937B8: sh          $t0, -0x2($t6)
    MEM_H(-0X2, ctx->r14) = ctx->r8;
    // 0x800937BC: srl         $t2, $t8, 4
    ctx->r10 = S32(U32(ctx->r24) >> 4);
    // 0x800937C0: andi        $t2, $t2, 0xF
    ctx->r10 = ctx->r10 & 0XF;
    // 0x800937C4: sll         $t3, $t1, 4
    ctx->r11 = S32(ctx->r9 << 4);
    // 0x800937C8: addu        $t3, $t3, $t2
    ctx->r11 = ADD32(ctx->r11, ctx->r10);
    // 0x800937CC: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x800937D0: addu        $t3, $t3, $t5
    ctx->r11 = ADD32(ctx->r11, ctx->r13);
    // 0x800937D4: lw          $t4, 0x0($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X0);
    // 0x800937D8: addiu       $t6, $t6, 0x2
    ctx->r14 = ADD32(ctx->r14, 0X2);
    // 0x800937DC: andi        $t1, $t4, 0xFF
    ctx->r9 = ctx->r12 & 0XFF;
    // 0x800937E0: sra         $t4, $t4, 8
    ctx->r12 = S32(SIGNED(ctx->r12) >> 8);
    // 0x800937E4: addu        $t0, $t0, $t4
    ctx->r8 = ADD32(ctx->r8, ctx->r12);
    // 0x800937E8: slti        $t3, $t0, 0x7FFF
    ctx->r11 = SIGNED(ctx->r8) < 0X7FFF ? 1 : 0;
    // 0x800937EC: bne         $t3, $zero, L_800937FC
    if (ctx->r11 != 0) {
        // 0x800937F0: slti        $t3, $t0, -0x8000
        ctx->r11 = SIGNED(ctx->r8) < -0X8000 ? 1 : 0;
            goto L_800937FC;
    }
    // 0x800937F0: slti        $t3, $t0, -0x8000
    ctx->r11 = SIGNED(ctx->r8) < -0X8000 ? 1 : 0;
    // 0x800937F4: j           L_80093808
    // 0x800937F8: ori         $t0, $zero, 0x7FFF
    ctx->r8 = 0 | 0X7FFF;
        goto L_80093808;
    // 0x800937F8: ori         $t0, $zero, 0x7FFF
    ctx->r8 = 0 | 0X7FFF;
L_800937FC:
    // 0x800937FC: beq         $t3, $zero, L_80093808
    if (ctx->r11 == 0) {
        // 0x80093800: nop
    
            goto L_80093808;
    }
    // 0x80093800: nop

    // 0x80093804: addiu       $t0, $zero, -0x7FFF
    ctx->r8 = ADD32(0, -0X7FFF);
L_80093808:
    // 0x80093808: sh          $t0, -0x2($t6)
    MEM_H(-0X2, ctx->r14) = ctx->r8;
    // 0x8009380C: dsrl32      $t2, $t9, 24
    ctx->r10 = ctx->r25 >> (24 + 32);
    // 0x80093810: andi        $t2, $t2, 0xF
    ctx->r10 = ctx->r10 & 0XF;
    // 0x80093814: sll         $t3, $t1, 4
    ctx->r11 = S32(ctx->r9 << 4);
    // 0x80093818: addu        $t3, $t3, $t2
    ctx->r11 = ADD32(ctx->r11, ctx->r10);
    // 0x8009381C: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x80093820: addu        $t3, $t3, $t5
    ctx->r11 = ADD32(ctx->r11, ctx->r13);
    // 0x80093824: lw          $t4, 0x0($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X0);
    // 0x80093828: addiu       $t6, $t6, 0x2
    ctx->r14 = ADD32(ctx->r14, 0X2);
    // 0x8009382C: andi        $t1, $t4, 0xFF
    ctx->r9 = ctx->r12 & 0XFF;
    // 0x80093830: sra         $t4, $t4, 8
    ctx->r12 = S32(SIGNED(ctx->r12) >> 8);
    // 0x80093834: addu        $t0, $t0, $t4
    ctx->r8 = ADD32(ctx->r8, ctx->r12);
    // 0x80093838: slti        $t3, $t0, 0x7FFF
    ctx->r11 = SIGNED(ctx->r8) < 0X7FFF ? 1 : 0;
    // 0x8009383C: bne         $t3, $zero, L_8009384C
    if (ctx->r11 != 0) {
        // 0x80093840: slti        $t3, $t0, -0x8000
        ctx->r11 = SIGNED(ctx->r8) < -0X8000 ? 1 : 0;
            goto L_8009384C;
    }
    // 0x80093840: slti        $t3, $t0, -0x8000
    ctx->r11 = SIGNED(ctx->r8) < -0X8000 ? 1 : 0;
    // 0x80093844: j           L_80093858
    // 0x80093848: ori         $t0, $zero, 0x7FFF
    ctx->r8 = 0 | 0X7FFF;
        goto L_80093858;
    // 0x80093848: ori         $t0, $zero, 0x7FFF
    ctx->r8 = 0 | 0X7FFF;
L_8009384C:
    // 0x8009384C: beq         $t3, $zero, L_80093858
    if (ctx->r11 == 0) {
        // 0x80093850: nop
    
            goto L_80093858;
    }
    // 0x80093850: nop

    // 0x80093854: addiu       $t0, $zero, -0x7FFF
    ctx->r8 = ADD32(0, -0X7FFF);
L_80093858:
    // 0x80093858: sh          $t0, -0x2($t6)
    MEM_H(-0X2, ctx->r14) = ctx->r8;
    // 0x8009385C: dsrl32      $t2, $t9, 28
    ctx->r10 = ctx->r25 >> (28 + 32);
    // 0x80093860: andi        $t2, $t2, 0xF
    ctx->r10 = ctx->r10 & 0XF;
    // 0x80093864: sll         $t3, $t1, 4
    ctx->r11 = S32(ctx->r9 << 4);
    // 0x80093868: addu        $t3, $t3, $t2
    ctx->r11 = ADD32(ctx->r11, ctx->r10);
    // 0x8009386C: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x80093870: addu        $t3, $t3, $t5
    ctx->r11 = ADD32(ctx->r11, ctx->r13);
    // 0x80093874: lw          $t4, 0x0($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X0);
    // 0x80093878: addiu       $t6, $t6, 0x2
    ctx->r14 = ADD32(ctx->r14, 0X2);
    // 0x8009387C: andi        $t1, $t4, 0xFF
    ctx->r9 = ctx->r12 & 0XFF;
    // 0x80093880: sra         $t4, $t4, 8
    ctx->r12 = S32(SIGNED(ctx->r12) >> 8);
    // 0x80093884: addu        $t0, $t0, $t4
    ctx->r8 = ADD32(ctx->r8, ctx->r12);
    // 0x80093888: slti        $t3, $t0, 0x7FFF
    ctx->r11 = SIGNED(ctx->r8) < 0X7FFF ? 1 : 0;
    // 0x8009388C: bne         $t3, $zero, L_8009389C
    if (ctx->r11 != 0) {
        // 0x80093890: slti        $t3, $t0, -0x8000
        ctx->r11 = SIGNED(ctx->r8) < -0X8000 ? 1 : 0;
            goto L_8009389C;
    }
    // 0x80093890: slti        $t3, $t0, -0x8000
    ctx->r11 = SIGNED(ctx->r8) < -0X8000 ? 1 : 0;
    // 0x80093894: j           L_800938A8
    // 0x80093898: ori         $t0, $zero, 0x7FFF
    ctx->r8 = 0 | 0X7FFF;
        goto L_800938A8;
    // 0x80093898: ori         $t0, $zero, 0x7FFF
    ctx->r8 = 0 | 0X7FFF;
L_8009389C:
    // 0x8009389C: beq         $t3, $zero, L_800938A8
    if (ctx->r11 == 0) {
        // 0x800938A0: nop
    
            goto L_800938A8;
    }
    // 0x800938A0: nop

    // 0x800938A4: addiu       $t0, $zero, -0x7FFF
    ctx->r8 = ADD32(0, -0X7FFF);
L_800938A8:
    // 0x800938A8: sh          $t0, -0x2($t6)
    MEM_H(-0X2, ctx->r14) = ctx->r8;
    // 0x800938AC: dsrl32      $t2, $t9, 16
    ctx->r10 = ctx->r25 >> (16 + 32);
    // 0x800938B0: andi        $t2, $t2, 0xF
    ctx->r10 = ctx->r10 & 0XF;
    // 0x800938B4: sll         $t3, $t1, 4
    ctx->r11 = S32(ctx->r9 << 4);
    // 0x800938B8: addu        $t3, $t3, $t2
    ctx->r11 = ADD32(ctx->r11, ctx->r10);
    // 0x800938BC: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x800938C0: addu        $t3, $t3, $t5
    ctx->r11 = ADD32(ctx->r11, ctx->r13);
    // 0x800938C4: lw          $t4, 0x0($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X0);
    // 0x800938C8: addiu       $t6, $t6, 0x2
    ctx->r14 = ADD32(ctx->r14, 0X2);
    // 0x800938CC: andi        $t1, $t4, 0xFF
    ctx->r9 = ctx->r12 & 0XFF;
    // 0x800938D0: sra         $t4, $t4, 8
    ctx->r12 = S32(SIGNED(ctx->r12) >> 8);
    // 0x800938D4: addu        $t0, $t0, $t4
    ctx->r8 = ADD32(ctx->r8, ctx->r12);
    // 0x800938D8: slti        $t3, $t0, 0x7FFF
    ctx->r11 = SIGNED(ctx->r8) < 0X7FFF ? 1 : 0;
    // 0x800938DC: bne         $t3, $zero, L_800938EC
    if (ctx->r11 != 0) {
        // 0x800938E0: slti        $t3, $t0, -0x8000
        ctx->r11 = SIGNED(ctx->r8) < -0X8000 ? 1 : 0;
            goto L_800938EC;
    }
    // 0x800938E0: slti        $t3, $t0, -0x8000
    ctx->r11 = SIGNED(ctx->r8) < -0X8000 ? 1 : 0;
    // 0x800938E4: j           L_800938F8
    // 0x800938E8: ori         $t0, $zero, 0x7FFF
    ctx->r8 = 0 | 0X7FFF;
        goto L_800938F8;
    // 0x800938E8: ori         $t0, $zero, 0x7FFF
    ctx->r8 = 0 | 0X7FFF;
L_800938EC:
    // 0x800938EC: beq         $t3, $zero, L_800938F8
    if (ctx->r11 == 0) {
        // 0x800938F0: nop
    
            goto L_800938F8;
    }
    // 0x800938F0: nop

    // 0x800938F4: addiu       $t0, $zero, -0x7FFF
    ctx->r8 = ADD32(0, -0X7FFF);
L_800938F8:
    // 0x800938F8: sh          $t0, -0x2($t6)
    MEM_H(-0X2, ctx->r14) = ctx->r8;
    // 0x800938FC: dsrl32      $t2, $t9, 20
    ctx->r10 = ctx->r25 >> (20 + 32);
    // 0x80093900: andi        $t2, $t2, 0xF
    ctx->r10 = ctx->r10 & 0XF;
    // 0x80093904: sll         $t3, $t1, 4
    ctx->r11 = S32(ctx->r9 << 4);
    // 0x80093908: addu        $t3, $t3, $t2
    ctx->r11 = ADD32(ctx->r11, ctx->r10);
    // 0x8009390C: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x80093910: addu        $t3, $t3, $t5
    ctx->r11 = ADD32(ctx->r11, ctx->r13);
    // 0x80093914: lw          $t4, 0x0($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X0);
    // 0x80093918: addiu       $t6, $t6, 0x2
    ctx->r14 = ADD32(ctx->r14, 0X2);
    // 0x8009391C: andi        $t1, $t4, 0xFF
    ctx->r9 = ctx->r12 & 0XFF;
    // 0x80093920: sra         $t4, $t4, 8
    ctx->r12 = S32(SIGNED(ctx->r12) >> 8);
    // 0x80093924: addu        $t0, $t0, $t4
    ctx->r8 = ADD32(ctx->r8, ctx->r12);
    // 0x80093928: slti        $t3, $t0, 0x7FFF
    ctx->r11 = SIGNED(ctx->r8) < 0X7FFF ? 1 : 0;
    // 0x8009392C: bne         $t3, $zero, L_8009393C
    if (ctx->r11 != 0) {
        // 0x80093930: slti        $t3, $t0, -0x8000
        ctx->r11 = SIGNED(ctx->r8) < -0X8000 ? 1 : 0;
            goto L_8009393C;
    }
    // 0x80093930: slti        $t3, $t0, -0x8000
    ctx->r11 = SIGNED(ctx->r8) < -0X8000 ? 1 : 0;
    // 0x80093934: j           L_80093948
    // 0x80093938: ori         $t0, $zero, 0x7FFF
    ctx->r8 = 0 | 0X7FFF;
        goto L_80093948;
    // 0x80093938: ori         $t0, $zero, 0x7FFF
    ctx->r8 = 0 | 0X7FFF;
L_8009393C:
    // 0x8009393C: beq         $t3, $zero, L_80093948
    if (ctx->r11 == 0) {
        // 0x80093940: nop
    
            goto L_80093948;
    }
    // 0x80093940: nop

    // 0x80093944: addiu       $t0, $zero, -0x7FFF
    ctx->r8 = ADD32(0, -0X7FFF);
L_80093948:
    // 0x80093948: sh          $t0, -0x2($t6)
    MEM_H(-0X2, ctx->r14) = ctx->r8;
    // 0x8009394C: dsrl32      $t2, $t9, 8
    ctx->r10 = ctx->r25 >> (8 + 32);
    // 0x80093950: andi        $t2, $t2, 0xF
    ctx->r10 = ctx->r10 & 0XF;
    // 0x80093954: sll         $t3, $t1, 4
    ctx->r11 = S32(ctx->r9 << 4);
    // 0x80093958: addu        $t3, $t3, $t2
    ctx->r11 = ADD32(ctx->r11, ctx->r10);
    // 0x8009395C: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x80093960: addu        $t3, $t3, $t5
    ctx->r11 = ADD32(ctx->r11, ctx->r13);
    // 0x80093964: lw          $t4, 0x0($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X0);
    // 0x80093968: addiu       $t6, $t6, 0x2
    ctx->r14 = ADD32(ctx->r14, 0X2);
    // 0x8009396C: andi        $t1, $t4, 0xFF
    ctx->r9 = ctx->r12 & 0XFF;
    // 0x80093970: sra         $t4, $t4, 8
    ctx->r12 = S32(SIGNED(ctx->r12) >> 8);
    // 0x80093974: addu        $t0, $t0, $t4
    ctx->r8 = ADD32(ctx->r8, ctx->r12);
    // 0x80093978: slti        $t3, $t0, 0x7FFF
    ctx->r11 = SIGNED(ctx->r8) < 0X7FFF ? 1 : 0;
    // 0x8009397C: bne         $t3, $zero, L_8009398C
    if (ctx->r11 != 0) {
        // 0x80093980: slti        $t3, $t0, -0x8000
        ctx->r11 = SIGNED(ctx->r8) < -0X8000 ? 1 : 0;
            goto L_8009398C;
    }
    // 0x80093980: slti        $t3, $t0, -0x8000
    ctx->r11 = SIGNED(ctx->r8) < -0X8000 ? 1 : 0;
    // 0x80093984: j           L_80093998
    // 0x80093988: ori         $t0, $zero, 0x7FFF
    ctx->r8 = 0 | 0X7FFF;
        goto L_80093998;
    // 0x80093988: ori         $t0, $zero, 0x7FFF
    ctx->r8 = 0 | 0X7FFF;
L_8009398C:
    // 0x8009398C: beq         $t3, $zero, L_80093998
    if (ctx->r11 == 0) {
        // 0x80093990: nop
    
            goto L_80093998;
    }
    // 0x80093990: nop

    // 0x80093994: addiu       $t0, $zero, -0x7FFF
    ctx->r8 = ADD32(0, -0X7FFF);
L_80093998:
    // 0x80093998: sh          $t0, -0x2($t6)
    MEM_H(-0X2, ctx->r14) = ctx->r8;
    // 0x8009399C: dsrl32      $t2, $t9, 12
    ctx->r10 = ctx->r25 >> (12 + 32);
    // 0x800939A0: andi        $t2, $t2, 0xF
    ctx->r10 = ctx->r10 & 0XF;
    // 0x800939A4: sll         $t3, $t1, 4
    ctx->r11 = S32(ctx->r9 << 4);
    // 0x800939A8: addu        $t3, $t3, $t2
    ctx->r11 = ADD32(ctx->r11, ctx->r10);
    // 0x800939AC: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x800939B0: addu        $t3, $t3, $t5
    ctx->r11 = ADD32(ctx->r11, ctx->r13);
    // 0x800939B4: lw          $t4, 0x0($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X0);
    // 0x800939B8: addiu       $t6, $t6, 0x2
    ctx->r14 = ADD32(ctx->r14, 0X2);
    // 0x800939BC: andi        $t1, $t4, 0xFF
    ctx->r9 = ctx->r12 & 0XFF;
    // 0x800939C0: sra         $t4, $t4, 8
    ctx->r12 = S32(SIGNED(ctx->r12) >> 8);
    // 0x800939C4: addu        $t0, $t0, $t4
    ctx->r8 = ADD32(ctx->r8, ctx->r12);
    // 0x800939C8: slti        $t3, $t0, 0x7FFF
    ctx->r11 = SIGNED(ctx->r8) < 0X7FFF ? 1 : 0;
    // 0x800939CC: bne         $t3, $zero, L_800939DC
    if (ctx->r11 != 0) {
        // 0x800939D0: slti        $t3, $t0, -0x8000
        ctx->r11 = SIGNED(ctx->r8) < -0X8000 ? 1 : 0;
            goto L_800939DC;
    }
    // 0x800939D0: slti        $t3, $t0, -0x8000
    ctx->r11 = SIGNED(ctx->r8) < -0X8000 ? 1 : 0;
    // 0x800939D4: j           L_800939E8
    // 0x800939D8: ori         $t0, $zero, 0x7FFF
    ctx->r8 = 0 | 0X7FFF;
        goto L_800939E8;
    // 0x800939D8: ori         $t0, $zero, 0x7FFF
    ctx->r8 = 0 | 0X7FFF;
L_800939DC:
    // 0x800939DC: beq         $t3, $zero, L_800939E8
    if (ctx->r11 == 0) {
        // 0x800939E0: nop
    
            goto L_800939E8;
    }
    // 0x800939E0: nop

    // 0x800939E4: addiu       $t0, $zero, -0x7FFF
    ctx->r8 = ADD32(0, -0X7FFF);
L_800939E8:
    // 0x800939E8: sh          $t0, -0x2($t6)
    MEM_H(-0X2, ctx->r14) = ctx->r8;
    // 0x800939EC: dsrl32      $t2, $t9, 0
    ctx->r10 = ctx->r25 >> (0 + 32);
    // 0x800939F0: andi        $t2, $t2, 0xF
    ctx->r10 = ctx->r10 & 0XF;
    // 0x800939F4: sll         $t3, $t1, 4
    ctx->r11 = S32(ctx->r9 << 4);
    // 0x800939F8: addu        $t3, $t3, $t2
    ctx->r11 = ADD32(ctx->r11, ctx->r10);
    // 0x800939FC: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x80093A00: addu        $t3, $t3, $t5
    ctx->r11 = ADD32(ctx->r11, ctx->r13);
    // 0x80093A04: lw          $t4, 0x0($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X0);
    // 0x80093A08: addiu       $t6, $t6, 0x2
    ctx->r14 = ADD32(ctx->r14, 0X2);
    // 0x80093A0C: andi        $t1, $t4, 0xFF
    ctx->r9 = ctx->r12 & 0XFF;
    // 0x80093A10: sra         $t4, $t4, 8
    ctx->r12 = S32(SIGNED(ctx->r12) >> 8);
    // 0x80093A14: addu        $t0, $t0, $t4
    ctx->r8 = ADD32(ctx->r8, ctx->r12);
    // 0x80093A18: slti        $t3, $t0, 0x7FFF
    ctx->r11 = SIGNED(ctx->r8) < 0X7FFF ? 1 : 0;
    // 0x80093A1C: bne         $t3, $zero, L_80093A2C
    if (ctx->r11 != 0) {
        // 0x80093A20: slti        $t3, $t0, -0x8000
        ctx->r11 = SIGNED(ctx->r8) < -0X8000 ? 1 : 0;
            goto L_80093A2C;
    }
    // 0x80093A20: slti        $t3, $t0, -0x8000
    ctx->r11 = SIGNED(ctx->r8) < -0X8000 ? 1 : 0;
    // 0x80093A24: j           L_80093A38
    // 0x80093A28: ori         $t0, $zero, 0x7FFF
    ctx->r8 = 0 | 0X7FFF;
        goto L_80093A38;
    // 0x80093A28: ori         $t0, $zero, 0x7FFF
    ctx->r8 = 0 | 0X7FFF;
L_80093A2C:
    // 0x80093A2C: beq         $t3, $zero, L_80093A38
    if (ctx->r11 == 0) {
        // 0x80093A30: nop
    
            goto L_80093A38;
    }
    // 0x80093A30: nop

    // 0x80093A34: addiu       $t0, $zero, -0x7FFF
    ctx->r8 = ADD32(0, -0X7FFF);
L_80093A38:
    // 0x80093A38: sh          $t0, -0x2($t6)
    MEM_H(-0X2, ctx->r14) = ctx->r8;
    // 0x80093A3C: dsrl32      $t2, $t9, 4
    ctx->r10 = ctx->r25 >> (4 + 32);
    // 0x80093A40: andi        $t2, $t2, 0xF
    ctx->r10 = ctx->r10 & 0XF;
    // 0x80093A44: sll         $t3, $t1, 4
    ctx->r11 = S32(ctx->r9 << 4);
    // 0x80093A48: addu        $t3, $t3, $t2
    ctx->r11 = ADD32(ctx->r11, ctx->r10);
    // 0x80093A4C: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x80093A50: addu        $t3, $t3, $t5
    ctx->r11 = ADD32(ctx->r11, ctx->r13);
    // 0x80093A54: lw          $t4, 0x0($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X0);
    // 0x80093A58: addiu       $t6, $t6, 0x2
    ctx->r14 = ADD32(ctx->r14, 0X2);
    // 0x80093A5C: andi        $t1, $t4, 0xFF
    ctx->r9 = ctx->r12 & 0XFF;
    // 0x80093A60: sra         $t4, $t4, 8
    ctx->r12 = S32(SIGNED(ctx->r12) >> 8);
    // 0x80093A64: addu        $t0, $t0, $t4
    ctx->r8 = ADD32(ctx->r8, ctx->r12);
    // 0x80093A68: slti        $t3, $t0, 0x7FFF
    ctx->r11 = SIGNED(ctx->r8) < 0X7FFF ? 1 : 0;
    // 0x80093A6C: bne         $t3, $zero, L_80093A7C
    if (ctx->r11 != 0) {
        // 0x80093A70: slti        $t3, $t0, -0x8000
        ctx->r11 = SIGNED(ctx->r8) < -0X8000 ? 1 : 0;
            goto L_80093A7C;
    }
    // 0x80093A70: slti        $t3, $t0, -0x8000
    ctx->r11 = SIGNED(ctx->r8) < -0X8000 ? 1 : 0;
    // 0x80093A74: j           L_80093A88
    // 0x80093A78: ori         $t0, $zero, 0x7FFF
    ctx->r8 = 0 | 0X7FFF;
        goto L_80093A88;
    // 0x80093A78: ori         $t0, $zero, 0x7FFF
    ctx->r8 = 0 | 0X7FFF;
L_80093A7C:
    // 0x80093A7C: beq         $t3, $zero, L_80093A88
    if (ctx->r11 == 0) {
        // 0x80093A80: nop
    
            goto L_80093A88;
    }
    // 0x80093A80: nop

    // 0x80093A84: addiu       $t0, $zero, -0x7FFF
    ctx->r8 = ADD32(0, -0X7FFF);
L_80093A88:
    // 0x80093A88: sh          $t0, -0x2($t6)
    MEM_H(-0X2, ctx->r14) = ctx->r8;
    // 0x80093A8C: srl         $t2, $t9, 24
    ctx->r10 = S32(U32(ctx->r25) >> 24);
    // 0x80093A90: andi        $t2, $t2, 0xF
    ctx->r10 = ctx->r10 & 0XF;
    // 0x80093A94: sll         $t3, $t1, 4
    ctx->r11 = S32(ctx->r9 << 4);
    // 0x80093A98: addu        $t3, $t3, $t2
    ctx->r11 = ADD32(ctx->r11, ctx->r10);
    // 0x80093A9C: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x80093AA0: addu        $t3, $t3, $t5
    ctx->r11 = ADD32(ctx->r11, ctx->r13);
    // 0x80093AA4: lw          $t4, 0x0($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X0);
    // 0x80093AA8: addiu       $t6, $t6, 0x2
    ctx->r14 = ADD32(ctx->r14, 0X2);
    // 0x80093AAC: andi        $t1, $t4, 0xFF
    ctx->r9 = ctx->r12 & 0XFF;
    // 0x80093AB0: sra         $t4, $t4, 8
    ctx->r12 = S32(SIGNED(ctx->r12) >> 8);
    // 0x80093AB4: addu        $t0, $t0, $t4
    ctx->r8 = ADD32(ctx->r8, ctx->r12);
    // 0x80093AB8: slti        $t3, $t0, 0x7FFF
    ctx->r11 = SIGNED(ctx->r8) < 0X7FFF ? 1 : 0;
    // 0x80093ABC: bne         $t3, $zero, L_80093ACC
    if (ctx->r11 != 0) {
        // 0x80093AC0: slti        $t3, $t0, -0x8000
        ctx->r11 = SIGNED(ctx->r8) < -0X8000 ? 1 : 0;
            goto L_80093ACC;
    }
    // 0x80093AC0: slti        $t3, $t0, -0x8000
    ctx->r11 = SIGNED(ctx->r8) < -0X8000 ? 1 : 0;
    // 0x80093AC4: j           L_80093AD8
    // 0x80093AC8: ori         $t0, $zero, 0x7FFF
    ctx->r8 = 0 | 0X7FFF;
        goto L_80093AD8;
    // 0x80093AC8: ori         $t0, $zero, 0x7FFF
    ctx->r8 = 0 | 0X7FFF;
L_80093ACC:
    // 0x80093ACC: beq         $t3, $zero, L_80093AD8
    if (ctx->r11 == 0) {
        // 0x80093AD0: nop
    
            goto L_80093AD8;
    }
    // 0x80093AD0: nop

    // 0x80093AD4: addiu       $t0, $zero, -0x7FFF
    ctx->r8 = ADD32(0, -0X7FFF);
L_80093AD8:
    // 0x80093AD8: sh          $t0, -0x2($t6)
    MEM_H(-0X2, ctx->r14) = ctx->r8;
    // 0x80093ADC: srl         $t2, $t9, 28
    ctx->r10 = S32(U32(ctx->r25) >> 28);
    // 0x80093AE0: andi        $t2, $t2, 0xF
    ctx->r10 = ctx->r10 & 0XF;
    // 0x80093AE4: sll         $t3, $t1, 4
    ctx->r11 = S32(ctx->r9 << 4);
    // 0x80093AE8: addu        $t3, $t3, $t2
    ctx->r11 = ADD32(ctx->r11, ctx->r10);
    // 0x80093AEC: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x80093AF0: addu        $t3, $t3, $t5
    ctx->r11 = ADD32(ctx->r11, ctx->r13);
    // 0x80093AF4: lw          $t4, 0x0($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X0);
    // 0x80093AF8: addiu       $t6, $t6, 0x2
    ctx->r14 = ADD32(ctx->r14, 0X2);
    // 0x80093AFC: andi        $t1, $t4, 0xFF
    ctx->r9 = ctx->r12 & 0XFF;
    // 0x80093B00: sra         $t4, $t4, 8
    ctx->r12 = S32(SIGNED(ctx->r12) >> 8);
    // 0x80093B04: addu        $t0, $t0, $t4
    ctx->r8 = ADD32(ctx->r8, ctx->r12);
    // 0x80093B08: slti        $t3, $t0, 0x7FFF
    ctx->r11 = SIGNED(ctx->r8) < 0X7FFF ? 1 : 0;
    // 0x80093B0C: bne         $t3, $zero, L_80093B1C
    if (ctx->r11 != 0) {
        // 0x80093B10: slti        $t3, $t0, -0x8000
        ctx->r11 = SIGNED(ctx->r8) < -0X8000 ? 1 : 0;
            goto L_80093B1C;
    }
    // 0x80093B10: slti        $t3, $t0, -0x8000
    ctx->r11 = SIGNED(ctx->r8) < -0X8000 ? 1 : 0;
    // 0x80093B14: j           L_80093B28
    // 0x80093B18: ori         $t0, $zero, 0x7FFF
    ctx->r8 = 0 | 0X7FFF;
        goto L_80093B28;
    // 0x80093B18: ori         $t0, $zero, 0x7FFF
    ctx->r8 = 0 | 0X7FFF;
L_80093B1C:
    // 0x80093B1C: beq         $t3, $zero, L_80093B28
    if (ctx->r11 == 0) {
        // 0x80093B20: nop
    
            goto L_80093B28;
    }
    // 0x80093B20: nop

    // 0x80093B24: addiu       $t0, $zero, -0x7FFF
    ctx->r8 = ADD32(0, -0X7FFF);
L_80093B28:
    // 0x80093B28: sh          $t0, -0x2($t6)
    MEM_H(-0X2, ctx->r14) = ctx->r8;
    // 0x80093B2C: srl         $t2, $t9, 16
    ctx->r10 = S32(U32(ctx->r25) >> 16);
    // 0x80093B30: andi        $t2, $t2, 0xF
    ctx->r10 = ctx->r10 & 0XF;
    // 0x80093B34: sll         $t3, $t1, 4
    ctx->r11 = S32(ctx->r9 << 4);
    // 0x80093B38: addu        $t3, $t3, $t2
    ctx->r11 = ADD32(ctx->r11, ctx->r10);
    // 0x80093B3C: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x80093B40: addu        $t3, $t3, $t5
    ctx->r11 = ADD32(ctx->r11, ctx->r13);
    // 0x80093B44: lw          $t4, 0x0($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X0);
    // 0x80093B48: addiu       $t6, $t6, 0x2
    ctx->r14 = ADD32(ctx->r14, 0X2);
    // 0x80093B4C: andi        $t1, $t4, 0xFF
    ctx->r9 = ctx->r12 & 0XFF;
    // 0x80093B50: sra         $t4, $t4, 8
    ctx->r12 = S32(SIGNED(ctx->r12) >> 8);
    // 0x80093B54: addu        $t0, $t0, $t4
    ctx->r8 = ADD32(ctx->r8, ctx->r12);
    // 0x80093B58: slti        $t3, $t0, 0x7FFF
    ctx->r11 = SIGNED(ctx->r8) < 0X7FFF ? 1 : 0;
    // 0x80093B5C: bne         $t3, $zero, L_80093B6C
    if (ctx->r11 != 0) {
        // 0x80093B60: slti        $t3, $t0, -0x8000
        ctx->r11 = SIGNED(ctx->r8) < -0X8000 ? 1 : 0;
            goto L_80093B6C;
    }
    // 0x80093B60: slti        $t3, $t0, -0x8000
    ctx->r11 = SIGNED(ctx->r8) < -0X8000 ? 1 : 0;
    // 0x80093B64: j           L_80093B78
    // 0x80093B68: ori         $t0, $zero, 0x7FFF
    ctx->r8 = 0 | 0X7FFF;
        goto L_80093B78;
    // 0x80093B68: ori         $t0, $zero, 0x7FFF
    ctx->r8 = 0 | 0X7FFF;
L_80093B6C:
    // 0x80093B6C: beq         $t3, $zero, L_80093B78
    if (ctx->r11 == 0) {
        // 0x80093B70: nop
    
            goto L_80093B78;
    }
    // 0x80093B70: nop

    // 0x80093B74: addiu       $t0, $zero, -0x7FFF
    ctx->r8 = ADD32(0, -0X7FFF);
L_80093B78:
    // 0x80093B78: sh          $t0, -0x2($t6)
    MEM_H(-0X2, ctx->r14) = ctx->r8;
    // 0x80093B7C: srl         $t2, $t9, 20
    ctx->r10 = S32(U32(ctx->r25) >> 20);
    // 0x80093B80: andi        $t2, $t2, 0xF
    ctx->r10 = ctx->r10 & 0XF;
    // 0x80093B84: sll         $t3, $t1, 4
    ctx->r11 = S32(ctx->r9 << 4);
    // 0x80093B88: addu        $t3, $t3, $t2
    ctx->r11 = ADD32(ctx->r11, ctx->r10);
    // 0x80093B8C: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x80093B90: addu        $t3, $t3, $t5
    ctx->r11 = ADD32(ctx->r11, ctx->r13);
    // 0x80093B94: lw          $t4, 0x0($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X0);
    // 0x80093B98: addiu       $t6, $t6, 0x2
    ctx->r14 = ADD32(ctx->r14, 0X2);
    // 0x80093B9C: andi        $t1, $t4, 0xFF
    ctx->r9 = ctx->r12 & 0XFF;
    // 0x80093BA0: sra         $t4, $t4, 8
    ctx->r12 = S32(SIGNED(ctx->r12) >> 8);
    // 0x80093BA4: addu        $t0, $t0, $t4
    ctx->r8 = ADD32(ctx->r8, ctx->r12);
    // 0x80093BA8: slti        $t3, $t0, 0x7FFF
    ctx->r11 = SIGNED(ctx->r8) < 0X7FFF ? 1 : 0;
    // 0x80093BAC: bne         $t3, $zero, L_80093BBC
    if (ctx->r11 != 0) {
        // 0x80093BB0: slti        $t3, $t0, -0x8000
        ctx->r11 = SIGNED(ctx->r8) < -0X8000 ? 1 : 0;
            goto L_80093BBC;
    }
    // 0x80093BB0: slti        $t3, $t0, -0x8000
    ctx->r11 = SIGNED(ctx->r8) < -0X8000 ? 1 : 0;
    // 0x80093BB4: j           L_80093BC8
    // 0x80093BB8: ori         $t0, $zero, 0x7FFF
    ctx->r8 = 0 | 0X7FFF;
        goto L_80093BC8;
    // 0x80093BB8: ori         $t0, $zero, 0x7FFF
    ctx->r8 = 0 | 0X7FFF;
L_80093BBC:
    // 0x80093BBC: beq         $t3, $zero, L_80093BC8
    if (ctx->r11 == 0) {
        // 0x80093BC0: nop
    
            goto L_80093BC8;
    }
    // 0x80093BC0: nop

    // 0x80093BC4: addiu       $t0, $zero, -0x7FFF
    ctx->r8 = ADD32(0, -0X7FFF);
L_80093BC8:
    // 0x80093BC8: sh          $t0, -0x2($t6)
    MEM_H(-0X2, ctx->r14) = ctx->r8;
    // 0x80093BCC: srl         $t2, $t9, 8
    ctx->r10 = S32(U32(ctx->r25) >> 8);
    // 0x80093BD0: andi        $t2, $t2, 0xF
    ctx->r10 = ctx->r10 & 0XF;
    // 0x80093BD4: sll         $t3, $t1, 4
    ctx->r11 = S32(ctx->r9 << 4);
    // 0x80093BD8: addu        $t3, $t3, $t2
    ctx->r11 = ADD32(ctx->r11, ctx->r10);
    // 0x80093BDC: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x80093BE0: addu        $t3, $t3, $t5
    ctx->r11 = ADD32(ctx->r11, ctx->r13);
    // 0x80093BE4: lw          $t4, 0x0($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X0);
    // 0x80093BE8: addiu       $t6, $t6, 0x2
    ctx->r14 = ADD32(ctx->r14, 0X2);
    // 0x80093BEC: andi        $t1, $t4, 0xFF
    ctx->r9 = ctx->r12 & 0XFF;
    // 0x80093BF0: sra         $t4, $t4, 8
    ctx->r12 = S32(SIGNED(ctx->r12) >> 8);
    // 0x80093BF4: addu        $t0, $t0, $t4
    ctx->r8 = ADD32(ctx->r8, ctx->r12);
    // 0x80093BF8: slti        $t3, $t0, 0x7FFF
    ctx->r11 = SIGNED(ctx->r8) < 0X7FFF ? 1 : 0;
    // 0x80093BFC: bne         $t3, $zero, L_80093C0C
    if (ctx->r11 != 0) {
        // 0x80093C00: slti        $t3, $t0, -0x8000
        ctx->r11 = SIGNED(ctx->r8) < -0X8000 ? 1 : 0;
            goto L_80093C0C;
    }
    // 0x80093C00: slti        $t3, $t0, -0x8000
    ctx->r11 = SIGNED(ctx->r8) < -0X8000 ? 1 : 0;
    // 0x80093C04: j           L_80093C18
    // 0x80093C08: ori         $t0, $zero, 0x7FFF
    ctx->r8 = 0 | 0X7FFF;
        goto L_80093C18;
    // 0x80093C08: ori         $t0, $zero, 0x7FFF
    ctx->r8 = 0 | 0X7FFF;
L_80093C0C:
    // 0x80093C0C: beq         $t3, $zero, L_80093C18
    if (ctx->r11 == 0) {
        // 0x80093C10: nop
    
            goto L_80093C18;
    }
    // 0x80093C10: nop

    // 0x80093C14: addiu       $t0, $zero, -0x7FFF
    ctx->r8 = ADD32(0, -0X7FFF);
L_80093C18:
    // 0x80093C18: sh          $t0, -0x2($t6)
    MEM_H(-0X2, ctx->r14) = ctx->r8;
    // 0x80093C1C: srl         $t2, $t9, 12
    ctx->r10 = S32(U32(ctx->r25) >> 12);
    // 0x80093C20: andi        $t2, $t2, 0xF
    ctx->r10 = ctx->r10 & 0XF;
    // 0x80093C24: sll         $t3, $t1, 4
    ctx->r11 = S32(ctx->r9 << 4);
    // 0x80093C28: addu        $t3, $t3, $t2
    ctx->r11 = ADD32(ctx->r11, ctx->r10);
    // 0x80093C2C: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x80093C30: addu        $t3, $t3, $t5
    ctx->r11 = ADD32(ctx->r11, ctx->r13);
    // 0x80093C34: lw          $t4, 0x0($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X0);
    // 0x80093C38: addiu       $t6, $t6, 0x2
    ctx->r14 = ADD32(ctx->r14, 0X2);
    // 0x80093C3C: andi        $t1, $t4, 0xFF
    ctx->r9 = ctx->r12 & 0XFF;
    // 0x80093C40: sra         $t4, $t4, 8
    ctx->r12 = S32(SIGNED(ctx->r12) >> 8);
    // 0x80093C44: addu        $t0, $t0, $t4
    ctx->r8 = ADD32(ctx->r8, ctx->r12);
    // 0x80093C48: slti        $t3, $t0, 0x7FFF
    ctx->r11 = SIGNED(ctx->r8) < 0X7FFF ? 1 : 0;
    // 0x80093C4C: bne         $t3, $zero, L_80093C5C
    if (ctx->r11 != 0) {
        // 0x80093C50: slti        $t3, $t0, -0x8000
        ctx->r11 = SIGNED(ctx->r8) < -0X8000 ? 1 : 0;
            goto L_80093C5C;
    }
    // 0x80093C50: slti        $t3, $t0, -0x8000
    ctx->r11 = SIGNED(ctx->r8) < -0X8000 ? 1 : 0;
    // 0x80093C54: j           L_80093C68
    // 0x80093C58: ori         $t0, $zero, 0x7FFF
    ctx->r8 = 0 | 0X7FFF;
        goto L_80093C68;
    // 0x80093C58: ori         $t0, $zero, 0x7FFF
    ctx->r8 = 0 | 0X7FFF;
L_80093C5C:
    // 0x80093C5C: beq         $t3, $zero, L_80093C68
    if (ctx->r11 == 0) {
        // 0x80093C60: nop
    
            goto L_80093C68;
    }
    // 0x80093C60: nop

    // 0x80093C64: addiu       $t0, $zero, -0x7FFF
    ctx->r8 = ADD32(0, -0X7FFF);
L_80093C68:
    // 0x80093C68: sh          $t0, -0x2($t6)
    MEM_H(-0X2, ctx->r14) = ctx->r8;
    // 0x80093C6C: andi        $t2, $t9, 0xF
    ctx->r10 = ctx->r25 & 0XF;
    // 0x80093C70: sll         $t3, $t1, 4
    ctx->r11 = S32(ctx->r9 << 4);
    // 0x80093C74: addu        $t3, $t3, $t2
    ctx->r11 = ADD32(ctx->r11, ctx->r10);
    // 0x80093C78: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x80093C7C: addu        $t3, $t3, $t5
    ctx->r11 = ADD32(ctx->r11, ctx->r13);
    // 0x80093C80: lw          $t4, 0x0($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X0);
    // 0x80093C84: addiu       $t6, $t6, 0x2
    ctx->r14 = ADD32(ctx->r14, 0X2);
    // 0x80093C88: andi        $t1, $t4, 0xFF
    ctx->r9 = ctx->r12 & 0XFF;
    // 0x80093C8C: sra         $t4, $t4, 8
    ctx->r12 = S32(SIGNED(ctx->r12) >> 8);
    // 0x80093C90: addu        $t0, $t0, $t4
    ctx->r8 = ADD32(ctx->r8, ctx->r12);
    // 0x80093C94: slti        $t3, $t0, 0x7FFF
    ctx->r11 = SIGNED(ctx->r8) < 0X7FFF ? 1 : 0;
    // 0x80093C98: bne         $t3, $zero, L_80093CA8
    if (ctx->r11 != 0) {
        // 0x80093C9C: slti        $t3, $t0, -0x8000
        ctx->r11 = SIGNED(ctx->r8) < -0X8000 ? 1 : 0;
            goto L_80093CA8;
    }
    // 0x80093C9C: slti        $t3, $t0, -0x8000
    ctx->r11 = SIGNED(ctx->r8) < -0X8000 ? 1 : 0;
    // 0x80093CA0: j           L_80093CB4
    // 0x80093CA4: ori         $t0, $zero, 0x7FFF
    ctx->r8 = 0 | 0X7FFF;
        goto L_80093CB4;
    // 0x80093CA4: ori         $t0, $zero, 0x7FFF
    ctx->r8 = 0 | 0X7FFF;
L_80093CA8:
    // 0x80093CA8: beq         $t3, $zero, L_80093CB4
    if (ctx->r11 == 0) {
        // 0x80093CAC: nop
    
            goto L_80093CB4;
    }
    // 0x80093CAC: nop

    // 0x80093CB0: addiu       $t0, $zero, -0x7FFF
    ctx->r8 = ADD32(0, -0X7FFF);
L_80093CB4:
    // 0x80093CB4: sh          $t0, -0x2($t6)
    MEM_H(-0X2, ctx->r14) = ctx->r8;
    // 0x80093CB8: srl         $t2, $t9, 4
    ctx->r10 = S32(U32(ctx->r25) >> 4);
    // 0x80093CBC: andi        $t2, $t2, 0xF
    ctx->r10 = ctx->r10 & 0XF;
    // 0x80093CC0: sll         $t3, $t1, 4
    ctx->r11 = S32(ctx->r9 << 4);
    // 0x80093CC4: addu        $t3, $t3, $t2
    ctx->r11 = ADD32(ctx->r11, ctx->r10);
    // 0x80093CC8: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x80093CCC: addu        $t3, $t3, $t5
    ctx->r11 = ADD32(ctx->r11, ctx->r13);
    // 0x80093CD0: lw          $t4, 0x0($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X0);
    // 0x80093CD4: addiu       $t6, $t6, 0x2
    ctx->r14 = ADD32(ctx->r14, 0X2);
    // 0x80093CD8: andi        $t1, $t4, 0xFF
    ctx->r9 = ctx->r12 & 0XFF;
    // 0x80093CDC: sra         $t4, $t4, 8
    ctx->r12 = S32(SIGNED(ctx->r12) >> 8);
    // 0x80093CE0: addu        $t0, $t0, $t4
    ctx->r8 = ADD32(ctx->r8, ctx->r12);
    // 0x80093CE4: slti        $t3, $t0, 0x7FFF
    ctx->r11 = SIGNED(ctx->r8) < 0X7FFF ? 1 : 0;
    // 0x80093CE8: bne         $t3, $zero, L_80093CF8
    if (ctx->r11 != 0) {
        // 0x80093CEC: slti        $t3, $t0, -0x8000
        ctx->r11 = SIGNED(ctx->r8) < -0X8000 ? 1 : 0;
            goto L_80093CF8;
    }
    // 0x80093CEC: slti        $t3, $t0, -0x8000
    ctx->r11 = SIGNED(ctx->r8) < -0X8000 ? 1 : 0;
    // 0x80093CF0: j           L_80093D04
    // 0x80093CF4: ori         $t0, $zero, 0x7FFF
    ctx->r8 = 0 | 0X7FFF;
        goto L_80093D04;
    // 0x80093CF4: ori         $t0, $zero, 0x7FFF
    ctx->r8 = 0 | 0X7FFF;
L_80093CF8:
    // 0x80093CF8: beq         $t3, $zero, L_80093D04
    if (ctx->r11 == 0) {
        // 0x80093CFC: nop
    
            goto L_80093D04;
    }
    // 0x80093CFC: nop

    // 0x80093D00: addiu       $t0, $zero, -0x7FFF
    ctx->r8 = ADD32(0, -0X7FFF);
L_80093D04:
    // 0x80093D04: sh          $t0, -0x2($t6)
    MEM_H(-0X2, ctx->r14) = ctx->r8;
    // 0x80093D08: jr          $ra
    // 0x80093D0C: nop

    return;
    // 0x80093D0C: nop

;}
RECOMP_FUNC void func_80093D10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80093D10: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80093D14: sw          $s0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r16;
    // 0x80093D18: sw          $s1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r17;
    // 0x80093D1C: sw          $s2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r18;
    // 0x80093D20: sw          $s3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r19;
    // 0x80093D24: sw          $s4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r20;
    // 0x80093D28: sw          $s5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r21;
    // 0x80093D2C: sw          $s6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r22;
    // 0x80093D30: sw          $s7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r23;
    // 0x80093D34: lui         $t3, 0x800A
    ctx->r11 = S32(0X800A << 16);
    // 0x80093D38: ori         $t3, $t3, 0x1790
    ctx->r11 = ctx->r11 | 0X1790;
    // 0x80093D3C: addu        $t2, $a1, $zero
    ctx->r10 = ADD32(ctx->r5, 0);
    // 0x80093D40: srl         $t0, $a2, 3
    ctx->r8 = S32(U32(ctx->r6) >> 3);
    // 0x80093D44: beq         $t0, $zero, L_80093DFC
    if (ctx->r8 == 0) {
        // 0x80093D48: addu        $t1, $a0, $zero
        ctx->r9 = ADD32(ctx->r4, 0);
            goto L_80093DFC;
    }
    // 0x80093D48: addu        $t1, $a0, $zero
    ctx->r9 = ADD32(ctx->r4, 0);
L_80093D4C:
    // 0x80093D4C: lbu         $s0, 0x0($t1)
    ctx->r16 = MEM_BU(ctx->r9, 0X0);
    // 0x80093D50: lbu         $s1, 0x1($t1)
    ctx->r17 = MEM_BU(ctx->r9, 0X1);
    // 0x80093D54: lbu         $s2, 0x2($t1)
    ctx->r18 = MEM_BU(ctx->r9, 0X2);
    // 0x80093D58: lbu         $s3, 0x3($t1)
    ctx->r19 = MEM_BU(ctx->r9, 0X3);
    // 0x80093D5C: lbu         $s4, 0x4($t1)
    ctx->r20 = MEM_BU(ctx->r9, 0X4);
    // 0x80093D60: lbu         $s5, 0x5($t1)
    ctx->r21 = MEM_BU(ctx->r9, 0X5);
    // 0x80093D64: lbu         $s6, 0x6($t1)
    ctx->r22 = MEM_BU(ctx->r9, 0X6);
    // 0x80093D68: lbu         $s7, 0x7($t1)
    ctx->r23 = MEM_BU(ctx->r9, 0X7);
    // 0x80093D6C: sll         $s0, $s0, 1
    ctx->r16 = S32(ctx->r16 << 1);
    // 0x80093D70: addu        $s0, $s0, $t3
    ctx->r16 = ADD32(ctx->r16, ctx->r11);
    // 0x80093D74: lhu         $s0, 0x0($s0)
    ctx->r16 = MEM_HU(ctx->r16, 0X0);
    // 0x80093D78: sll         $s1, $s1, 1
    ctx->r17 = S32(ctx->r17 << 1);
    // 0x80093D7C: addu        $s1, $s1, $t3
    ctx->r17 = ADD32(ctx->r17, ctx->r11);
    // 0x80093D80: lhu         $s1, 0x0($s1)
    ctx->r17 = MEM_HU(ctx->r17, 0X0);
    // 0x80093D84: sll         $s2, $s2, 1
    ctx->r18 = S32(ctx->r18 << 1);
    // 0x80093D88: addu        $s2, $s2, $t3
    ctx->r18 = ADD32(ctx->r18, ctx->r11);
    // 0x80093D8C: lhu         $s2, 0x0($s2)
    ctx->r18 = MEM_HU(ctx->r18, 0X0);
    // 0x80093D90: sll         $s3, $s3, 1
    ctx->r19 = S32(ctx->r19 << 1);
    // 0x80093D94: addu        $s3, $s3, $t3
    ctx->r19 = ADD32(ctx->r19, ctx->r11);
    // 0x80093D98: lhu         $s3, 0x0($s3)
    ctx->r19 = MEM_HU(ctx->r19, 0X0);
    // 0x80093D9C: sll         $s4, $s4, 1
    ctx->r20 = S32(ctx->r20 << 1);
    // 0x80093DA0: addu        $s4, $s4, $t3
    ctx->r20 = ADD32(ctx->r20, ctx->r11);
    // 0x80093DA4: lhu         $s4, 0x0($s4)
    ctx->r20 = MEM_HU(ctx->r20, 0X0);
    // 0x80093DA8: sll         $s5, $s5, 1
    ctx->r21 = S32(ctx->r21 << 1);
    // 0x80093DAC: addu        $s5, $s5, $t3
    ctx->r21 = ADD32(ctx->r21, ctx->r11);
    // 0x80093DB0: lhu         $s5, 0x0($s5)
    ctx->r21 = MEM_HU(ctx->r21, 0X0);
    // 0x80093DB4: sll         $s6, $s6, 1
    ctx->r22 = S32(ctx->r22 << 1);
    // 0x80093DB8: addu        $s6, $s6, $t3
    ctx->r22 = ADD32(ctx->r22, ctx->r11);
    // 0x80093DBC: lhu         $s6, 0x0($s6)
    ctx->r22 = MEM_HU(ctx->r22, 0X0);
    // 0x80093DC0: sll         $s7, $s7, 1
    ctx->r23 = S32(ctx->r23 << 1);
    // 0x80093DC4: addu        $s7, $s7, $t3
    ctx->r23 = ADD32(ctx->r23, ctx->r11);
    // 0x80093DC8: lhu         $s7, 0x0($s7)
    ctx->r23 = MEM_HU(ctx->r23, 0X0);
    // 0x80093DCC: addiu       $t1, $t1, 0x8
    ctx->r9 = ADD32(ctx->r9, 0X8);
    // 0x80093DD0: sh          $s0, 0x0($t2)
    MEM_H(0X0, ctx->r10) = ctx->r16;
    // 0x80093DD4: sh          $s1, 0x2($t2)
    MEM_H(0X2, ctx->r10) = ctx->r17;
    // 0x80093DD8: sh          $s2, 0x4($t2)
    MEM_H(0X4, ctx->r10) = ctx->r18;
    // 0x80093DDC: sh          $s3, 0x6($t2)
    MEM_H(0X6, ctx->r10) = ctx->r19;
    // 0x80093DE0: sh          $s4, 0x8($t2)
    MEM_H(0X8, ctx->r10) = ctx->r20;
    // 0x80093DE4: sh          $s5, 0xA($t2)
    MEM_H(0XA, ctx->r10) = ctx->r21;
    // 0x80093DE8: sh          $s6, 0xC($t2)
    MEM_H(0XC, ctx->r10) = ctx->r22;
    // 0x80093DEC: sh          $s7, 0xE($t2)
    MEM_H(0XE, ctx->r10) = ctx->r23;
    // 0x80093DF0: addiu       $t0, $t0, -0x1
    ctx->r8 = ADD32(ctx->r8, -0X1);
    // 0x80093DF4: bne         $t0, $zero, L_80093D4C
    if (ctx->r8 != 0) {
        // 0x80093DF8: addiu       $t2, $t2, 0x10
        ctx->r10 = ADD32(ctx->r10, 0X10);
            goto L_80093D4C;
    }
    // 0x80093DF8: addiu       $t2, $t2, 0x10
    ctx->r10 = ADD32(ctx->r10, 0X10);
L_80093DFC:
    // 0x80093DFC: andi        $t0, $a2, 0x7
    ctx->r8 = ctx->r6 & 0X7;
    // 0x80093E00: beq         $t0, $zero, L_80093E2C
    if (ctx->r8 == 0) {
        // 0x80093E04: nop
    
            goto L_80093E2C;
    }
    // 0x80093E04: nop

L_80093E08:
    // 0x80093E08: lbu         $s0, 0x0($t1)
    ctx->r16 = MEM_BU(ctx->r9, 0X0);
    // 0x80093E0C: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
    // 0x80093E10: sll         $s0, $s0, 1
    ctx->r16 = S32(ctx->r16 << 1);
    // 0x80093E14: addu        $s0, $s0, $t3
    ctx->r16 = ADD32(ctx->r16, ctx->r11);
    // 0x80093E18: lh          $s0, 0x0($s0)
    ctx->r16 = MEM_H(ctx->r16, 0X0);
    // 0x80093E1C: addiu       $t0, $t0, -0x1
    ctx->r8 = ADD32(ctx->r8, -0X1);
    // 0x80093E20: sh          $s0, 0x0($t2)
    MEM_H(0X0, ctx->r10) = ctx->r16;
    // 0x80093E24: bne         $t0, $zero, L_80093E08
    if (ctx->r8 != 0) {
        // 0x80093E28: addiu       $t2, $t2, 0x2
        ctx->r10 = ADD32(ctx->r10, 0X2);
            goto L_80093E08;
    }
    // 0x80093E28: addiu       $t2, $t2, 0x2
    ctx->r10 = ADD32(ctx->r10, 0X2);
L_80093E2C:
    // 0x80093E2C: lw          $s0, 0x0($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X0);
    // 0x80093E30: lw          $s1, 0x4($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X4);
    // 0x80093E34: lw          $s2, 0x8($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X8);
    // 0x80093E38: lw          $s3, 0xC($sp)
    ctx->r19 = MEM_W(ctx->r29, 0XC);
    // 0x80093E3C: lw          $s4, 0x10($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X10);
    // 0x80093E40: lw          $s5, 0x14($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X14);
    // 0x80093E44: lw          $s6, 0x18($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X18);
    // 0x80093E48: lw          $s7, 0x1C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X1C);
    // 0x80093E4C: jr          $ra
    // 0x80093E50: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80093E50: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void truncDouble(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80093E54: trunc.w.d   $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.u32l = TRUNC_W_D(ctx->f12.d);
    // 0x80093E58: jr          $ra
    // 0x80093E5C: cvt.d.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.d = CVT_D_W(ctx->f0.u32l);
    return;
    // 0x80093E5C: cvt.d.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.d = CVT_D_W(ctx->f0.u32l);
;}
RECOMP_FUNC void ceilDouble(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80093E60: ceil.w.d    $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.u32l = S32(ceil(ctx->f12.d));
    // 0x80093E64: jr          $ra
    // 0x80093E68: cvt.d.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.d = CVT_D_W(ctx->f0.u32l);
    return;
    // 0x80093E68: cvt.d.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.d = CVT_D_W(ctx->f0.u32l);
;}
RECOMP_FUNC void sqrtf_recomp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80093E6C: jr          $ra
    // 0x80093E70: sqrt.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = sqrtf(ctx->f12.fl);
    return;
    // 0x80093E70: sqrt.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = sqrtf(ctx->f12.fl);
;}
RECOMP_FUNC void fake_func_80093E74(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
;}
RECOMP_FUNC void musyxComputeNotePlaybackRate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80093E80: addiu       $sp, $sp, -0xC
    ctx->r29 = ADD32(ctx->r29, -0XC);
    // 0x80093E84: sw          $ra, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r31;
    // 0x80093E88: sw          $a0, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r4;
    // 0x80093E8C: sw          $a1, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r5;
    // 0x80093E90: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x80093E94: bne         $t0, $a1, L_80093EA0
    if (ctx->r8 != ctx->r5) {
        // 0x80093E98: lui         $t0, 0x4000
        ctx->r8 = S32(0X4000 << 16);
            goto L_80093EA0;
    }
    // 0x80093E98: lui         $t0, 0x4000
    ctx->r8 = S32(0X4000 << 16);
    // 0x80093E9C: ori         $a1, $t0, 0x5622
    ctx->r5 = ctx->r8 | 0X5622;
L_80093EA0:
    // 0x80093EA0: srl         $t0, $a1, 24
    ctx->r8 = S32(U32(ctx->r5) >> 24);
    // 0x80093EA4: sltu        $t1, $t0, $a0
    ctx->r9 = ctx->r8 < ctx->r4 ? 1 : 0;
    // 0x80093EA8: bne         $t1, $zero, L_80093EC8
    if (ctx->r9 != 0) {
        // 0x80093EAC: nop
    
            goto L_80093EC8;
    }
    // 0x80093EAC: nop

    // 0x80093EB0: subu        $t1, $t0, $a0
    ctx->r9 = SUB32(ctx->r8, ctx->r4);
    // 0x80093EB4: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x80093EB8: lui         $t2, 0x800A
    ctx->r10 = S32(0X800A << 16);
    // 0x80093EBC: ori         $t2, $t2, 0x31D0
    ctx->r10 = ctx->r10 | 0X31D0;
    // 0x80093EC0: j           L_80093EDC
    // 0x80093EC4: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
        goto L_80093EDC;
    // 0x80093EC4: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
L_80093EC8:
    // 0x80093EC8: subu        $t1, $a0, $t0
    ctx->r9 = SUB32(ctx->r4, ctx->r8);
    // 0x80093ECC: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x80093ED0: lui         $t2, 0x800A
    ctx->r10 = S32(0X800A << 16);
    // 0x80093ED4: ori         $t2, $t2, 0x2FD0
    ctx->r10 = ctx->r10 | 0X2FD0;
    // 0x80093ED8: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
L_80093EDC:
    // 0x80093EDC: lw          $t1, 0x0($t2)
    ctx->r9 = MEM_W(ctx->r10, 0X0);
    // 0x80093EE0: sll         $t0, $a1, 8
    ctx->r8 = S32(ctx->r5 << 8);
    // 0x80093EE4: srl         $t0, $t0, 8
    ctx->r8 = S32(U32(ctx->r8) >> 8);
    // 0x80093EE8: multu       $t0, $t1
    result = U64(U32(ctx->r8)) * U64(U32(ctx->r9)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80093EEC: mflo        $t0
    ctx->r8 = lo;
    // 0x80093EF0: mfhi        $t1
    ctx->r9 = hi;
    // 0x80093EF4: srl         $t0, $t0, 20
    ctx->r8 = S32(U32(ctx->r8) >> 20);
    // 0x80093EF8: sll         $t1, $t1, 12
    ctx->r9 = S32(ctx->r9 << 12);
    // 0x80093EFC: jal         0x80093F18
    // 0x80093F00: or          $a0, $t0, $t1
    ctx->r4 = ctx->r8 | ctx->r9;
    func_80093F18(rdram, ctx);
        goto after_0;
    // 0x80093F00: or          $a0, $t0, $t1
    ctx->r4 = ctx->r8 | ctx->r9;
    after_0:
    // 0x80093F04: lw          $ra, 0x0($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X0);
    // 0x80093F08: lw          $a0, 0x4($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X4);
    // 0x80093F0C: lw          $a1, 0x8($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X8);
    // 0x80093F10: jr          $ra
    // 0x80093F14: addiu       $sp, $sp, 0xC
    ctx->r29 = ADD32(ctx->r29, 0XC);
    return;
    // 0x80093F14: addiu       $sp, $sp, 0xC
    ctx->r29 = ADD32(ctx->r29, 0XC);
;}
RECOMP_FUNC void func_80093F18(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80093F18: lui         $t1, 0x8014
    ctx->r9 = S32(0X8014 << 16);
    // 0x80093F1C: ori         $t1, $t1, 0x40C0
    ctx->r9 = ctx->r9 | 0X40C0;
    // 0x80093F20: lw          $t1, 0x0($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X0);
    // 0x80093F24: dsll32      $t0, $a0, 0
    ctx->r8 = ctx->r4 << (0 + 32);
    // 0x80093F28: dsrl        $t0, $t0, 20
    ctx->r8 = ctx->r8 >> 20;
    // 0x80093F2C: ddivu       $zero, $t0, $t1
    DDIVU(U64(ctx->r8), U64(ctx->r9), &lo, &hi);
    // 0x80093F30: mflo        $v0
    ctx->r2 = lo;
    // 0x80093F34: jr          $ra
    // 0x80093F38: nop

    return;
    // 0x80093F38: nop

;}
RECOMP_FUNC void func_80093F3C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80093F3C: lui         $t0, 0x10
    ctx->r8 = S32(0X10 << 16);
    // 0x80093F40: ori         $t0, $t0, 0xD390
    ctx->r8 = ctx->r8 | 0XD390;
    // 0x80093F44: multu       $a0, $t0
    result = U64(U32(ctx->r4)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80093F48: mflo        $t0
    ctx->r8 = lo;
    // 0x80093F4C: mfhi        $t1
    ctx->r9 = hi;
    // 0x80093F50: srl         $t0, $t0, 20
    ctx->r8 = S32(U32(ctx->r8) >> 20);
    // 0x80093F54: sll         $t1, $t1, 12
    ctx->r9 = S32(ctx->r9 << 12);
    // 0x80093F58: jr          $ra
    // 0x80093F5C: or          $v0, $t0, $t1
    ctx->r2 = ctx->r8 | ctx->r9;
    return;
    // 0x80093F5C: or          $v0, $t0, $t1
    ctx->r2 = ctx->r8 | ctx->r9;
;}
RECOMP_FUNC void func_80093F60(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80093F60: lui         $t0, 0xF
    ctx->r8 = S32(0XF << 16);
    // 0x80093F64: ori         $t0, $t0, 0x1A1C
    ctx->r8 = ctx->r8 | 0X1A1C;
    // 0x80093F68: multu       $a0, $t0
    result = U64(U32(ctx->r4)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80093F6C: mflo        $t0
    ctx->r8 = lo;
    // 0x80093F70: mfhi        $t1
    ctx->r9 = hi;
    // 0x80093F74: srl         $t0, $t0, 20
    ctx->r8 = S32(U32(ctx->r8) >> 20);
    // 0x80093F78: sll         $t1, $t1, 12
    ctx->r9 = S32(ctx->r9 << 12);
    // 0x80093F7C: jr          $ra
    // 0x80093F80: or          $v0, $t0, $t1
    ctx->r2 = ctx->r8 | ctx->r9;
    return;
    // 0x80093F80: or          $v0, $t0, $t1
    ctx->r2 = ctx->r8 | ctx->r9;
;}
RECOMP_FUNC void func_80093F84(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80093F84: sll         $t1, $a1, 2
    ctx->r9 = S32(ctx->r5 << 2);
    // 0x80093F88: lui         $t0, 0x800A
    ctx->r8 = S32(0X800A << 16);
    // 0x80093F8C: ori         $t0, $t0, 0x2FD0
    ctx->r8 = ctx->r8 | 0X2FD0;
    // 0x80093F90: addu        $t0, $t0, $t1
    ctx->r8 = ADD32(ctx->r8, ctx->r9);
    // 0x80093F94: lw          $t0, 0x0($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X0);
    // 0x80093F98: multu       $a0, $t0
    result = U64(U32(ctx->r4)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80093F9C: mflo        $t0
    ctx->r8 = lo;
    // 0x80093FA0: mfhi        $t1
    ctx->r9 = hi;
    // 0x80093FA4: srl         $t0, $t0, 20
    ctx->r8 = S32(U32(ctx->r8) >> 20);
    // 0x80093FA8: sll         $t1, $t1, 12
    ctx->r9 = S32(ctx->r9 << 12);
    // 0x80093FAC: jr          $ra
    // 0x80093FB0: or          $v0, $t0, $t1
    ctx->r2 = ctx->r8 | ctx->r9;
    return;
    // 0x80093FB0: or          $v0, $t0, $t1
    ctx->r2 = ctx->r8 | ctx->r9;
;}
RECOMP_FUNC void func_80093FB4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80093FB4: sll         $t1, $a1, 2
    ctx->r9 = S32(ctx->r5 << 2);
    // 0x80093FB8: lui         $t0, 0x800A
    ctx->r8 = S32(0X800A << 16);
    // 0x80093FBC: ori         $t0, $t0, 0x31D0
    ctx->r8 = ctx->r8 | 0X31D0;
    // 0x80093FC0: addu        $t0, $t0, $t1
    ctx->r8 = ADD32(ctx->r8, ctx->r9);
    // 0x80093FC4: lw          $t0, 0x0($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X0);
    // 0x80093FC8: multu       $a0, $t0
    result = U64(U32(ctx->r4)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80093FCC: mflo        $t0
    ctx->r8 = lo;
    // 0x80093FD0: mfhi        $t1
    ctx->r9 = hi;
    // 0x80093FD4: srl         $t0, $t0, 20
    ctx->r8 = S32(U32(ctx->r8) >> 20);
    // 0x80093FD8: sll         $t1, $t1, 12
    ctx->r9 = S32(ctx->r9 << 12);
    // 0x80093FDC: jr          $ra
    // 0x80093FE0: or          $v0, $t0, $t1
    ctx->r2 = ctx->r8 | ctx->r9;
    return;
    // 0x80093FE0: or          $v0, $t0, $t1
    ctx->r2 = ctx->r8 | ctx->r9;
;}
RECOMP_FUNC void func_80093FE4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80093FE4: ori         $t0, $zero, 0x300
    ctx->r8 = 0 | 0X300;
    // 0x80093FE8: divu        $zero, $a0, $t0
    lo = S32(U32(ctx->r4) / U32(ctx->r8)); hi = S32(U32(ctx->r4) % U32(ctx->r8));
    // 0x80093FEC: mfhi        $t1
    ctx->r9 = hi;
    // 0x80093FF0: mflo        $t0
    ctx->r8 = lo;
    // 0x80093FF4: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x80093FF8: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x80093FFC: ori         $at, $at, 0x33D0
    ctx->r1 = ctx->r1 | 0X33D0;
    // 0x80094000: addu        $t1, $t1, $at
    ctx->r9 = ADD32(ctx->r9, ctx->r1);
    // 0x80094004: lw          $at, 0x0($t1)
    ctx->r1 = MEM_W(ctx->r9, 0X0);
    // 0x80094008: nop

    // 0x8009400C: multu       $a3, $at
    result = U64(U32(ctx->r7)) * U64(U32(ctx->r1)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80094010: mflo        $t2
    ctx->r10 = lo;
    // 0x80094014: mfhi        $t3
    ctx->r11 = hi;
    // 0x80094018: srl         $t2, $t2, 20
    ctx->r10 = S32(U32(ctx->r10) >> 20);
    // 0x8009401C: sll         $t3, $t3, 12
    ctx->r11 = S32(ctx->r11 << 12);
    // 0x80094020: or          $t2, $t2, $t3
    ctx->r10 = ctx->r10 | ctx->r11;
    // 0x80094024: sllv        $t2, $t2, $t0
    ctx->r10 = S32(ctx->r10 << (ctx->r8 & 31));
    // 0x80094028: sw          $t2, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r10;
    // 0x8009402C: lw          $at, 0x4($t1)
    ctx->r1 = MEM_W(ctx->r9, 0X4);
    // 0x80094030: nop

    // 0x80094034: multu       $a3, $at
    result = U64(U32(ctx->r7)) * U64(U32(ctx->r1)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80094038: mflo        $t2
    ctx->r10 = lo;
    // 0x8009403C: mfhi        $t3
    ctx->r11 = hi;
    // 0x80094040: srl         $t2, $t2, 20
    ctx->r10 = S32(U32(ctx->r10) >> 20);
    // 0x80094044: sll         $t3, $t3, 12
    ctx->r11 = S32(ctx->r11 << 12);
    // 0x80094048: or          $t2, $t2, $t3
    ctx->r10 = ctx->r10 | ctx->r11;
    // 0x8009404C: sllv        $t2, $t2, $t0
    ctx->r10 = S32(ctx->r10 << (ctx->r8 & 31));
    // 0x80094050: sw          $t2, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r10;
    // 0x80094054: jr          $ra
    // 0x80094058: nop

    return;
    // 0x80094058: nop

;}
RECOMP_FUNC void func_8009405C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009405C: ori         $t0, $zero, 0x300
    ctx->r8 = 0 | 0X300;
    // 0x80094060: divu        $zero, $a0, $t0
    lo = S32(U32(ctx->r4) / U32(ctx->r8)); hi = S32(U32(ctx->r4) % U32(ctx->r8));
    // 0x80094064: mfhi        $t1
    ctx->r9 = hi;
    // 0x80094068: mflo        $t0
    ctx->r8 = lo;
    // 0x8009406C: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x80094070: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x80094074: ori         $at, $at, 0x3FD4
    ctx->r1 = ctx->r1 | 0X3FD4;
    // 0x80094078: addu        $t1, $t1, $at
    ctx->r9 = ADD32(ctx->r9, ctx->r1);
    // 0x8009407C: lw          $at, 0x0($t1)
    ctx->r1 = MEM_W(ctx->r9, 0X0);
    // 0x80094080: nop

    // 0x80094084: multu       $a3, $at
    result = U64(U32(ctx->r7)) * U64(U32(ctx->r1)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80094088: mflo        $t2
    ctx->r10 = lo;
    // 0x8009408C: mfhi        $t3
    ctx->r11 = hi;
    // 0x80094090: srl         $t2, $t2, 20
    ctx->r10 = S32(U32(ctx->r10) >> 20);
    // 0x80094094: sll         $t3, $t3, 12
    ctx->r11 = S32(ctx->r11 << 12);
    // 0x80094098: or          $t2, $t2, $t3
    ctx->r10 = ctx->r10 | ctx->r11;
    // 0x8009409C: sllv        $t2, $t2, $t0
    ctx->r10 = S32(ctx->r10 << (ctx->r8 & 31));
    // 0x800940A0: sw          $t2, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r10;
    // 0x800940A4: lw          $at, 0x4($t1)
    ctx->r1 = MEM_W(ctx->r9, 0X4);
    // 0x800940A8: nop

    // 0x800940AC: multu       $a3, $at
    result = U64(U32(ctx->r7)) * U64(U32(ctx->r1)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800940B0: mflo        $t2
    ctx->r10 = lo;
    // 0x800940B4: mfhi        $t3
    ctx->r11 = hi;
    // 0x800940B8: srl         $t2, $t2, 20
    ctx->r10 = S32(U32(ctx->r10) >> 20);
    // 0x800940BC: sll         $t3, $t3, 12
    ctx->r11 = S32(ctx->r11 << 12);
    // 0x800940C0: or          $t2, $t2, $t3
    ctx->r10 = ctx->r10 | ctx->r11;
    // 0x800940C4: sllv        $t2, $t2, $t0
    ctx->r10 = S32(ctx->r10 << (ctx->r8 & 31));
    // 0x800940C8: sw          $t2, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r10;
    // 0x800940CC: jr          $ra
    // 0x800940D0: nop

    return;
    // 0x800940D0: nop

;}
RECOMP_FUNC void func_800940D4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800940D4: addiu       $sp, $sp, -0x4
    ctx->r29 = ADD32(ctx->r29, -0X4);
    // 0x800940D8: sw          $a2, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r6;
    // 0x800940DC: lui         $t0, 0x7F
    ctx->r8 = S32(0X7F << 16);
    // 0x800940E0: slt         $at, $a2, $t0
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x800940E4: bne         $at, $zero, L_800940F0
    if (ctx->r1 != 0) {
        // 0x800940E8: nop
    
            goto L_800940F0;
    }
    // 0x800940E8: nop

    // 0x800940EC: addu        $a2, $t0, $zero
    ctx->r6 = ADD32(ctx->r8, 0);
L_800940F0:
    // 0x800940F0: srl         $at, $a2, 16
    ctx->r1 = S32(U32(ctx->r6) >> 16);
    // 0x800940F4: sll         $at, $at, 2
    ctx->r1 = S32(ctx->r1 << 2);
    // 0x800940F8: lui         $t0, 0x800A
    ctx->r8 = S32(0X800A << 16);
    // 0x800940FC: ori         $t0, $t0, 0x4BD8
    ctx->r8 = ctx->r8 | 0X4BD8;
    // 0x80094100: addu        $t0, $t0, $at
    ctx->r8 = ADD32(ctx->r8, ctx->r1);
    // 0x80094104: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x80094108: ori         $at, $at, 0x4DD8
    ctx->r1 = ctx->r1 | 0X4DD8;
    // 0x8009410C: andi        $t1, $a2, 0xFFFF
    ctx->r9 = ctx->r6 & 0XFFFF;
    // 0x80094110: mtc1        $t1, $f6
    ctx->f6.u32l = ctx->r9;
    // 0x80094114: lwc1        $f8, 0x0($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X0);
    // 0x80094118: cvt.s.w     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8009411C: lwc1        $f4, 0x0($t0)
    ctx->f4.u32l = MEM_W(ctx->r8, 0X0);
    // 0x80094120: lwc1        $f10, 0x4($t0)
    ctx->f10.u32l = MEM_W(ctx->r8, 0X4);
    // 0x80094124: mul.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80094128: sub.s       $f10, $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f10.fl - ctx->f4.fl;
    // 0x8009412C: mul.s       $f10, $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f10.fl, ctx->f6.fl);
    // 0x80094130: add.s       $f4, $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x80094134: lw          $a2, 0x14($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X14);
    // 0x80094138: sll         $t0, $a2, 10
    ctx->r8 = S32(ctx->r6 << 10);
    // 0x8009413C: srl         $t0, $t0, 10
    ctx->r8 = S32(U32(ctx->r8) >> 10);
    // 0x80094140: mtc1        $t0, $f18
    ctx->f18.u32l = ctx->r8;
    // 0x80094144: srl         $t0, $a2, 22
    ctx->r8 = S32(U32(ctx->r6) >> 22);
    // 0x80094148: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x8009414C: lui         $t1, 0x800A
    ctx->r9 = S32(0X800A << 16);
    // 0x80094150: ori         $t1, $t1, 0x4DE8
    ctx->r9 = ctx->r9 | 0X4DE8;
    // 0x80094154: addu        $t0, $t0, $t1
    ctx->r8 = ADD32(ctx->r8, ctx->r9);
    // 0x80094158: cvt.s.w     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.fl = CVT_S_W(ctx->f18.u32l);
    // 0x8009415C: lwc1        $f16, 0xC($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0XC);
    // 0x80094160: lwc1        $f8, 0x0($t0)
    ctx->f8.u32l = MEM_W(ctx->r8, 0X0);
    // 0x80094164: lwc1        $f10, 0x4($t0)
    ctx->f10.u32l = MEM_W(ctx->r8, 0X4);
    // 0x80094168: mul.s       $f18, $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f18.fl, ctx->f16.fl);
    // 0x8009416C: sub.s       $f10, $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f10.fl - ctx->f8.fl;
    // 0x80094170: mul.s       $f10, $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = MUL_S(ctx->f10.fl, ctx->f18.fl);
    // 0x80094174: add.s       $f8, $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80094178: lwc1        $f16, 0x4($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X4);
    // 0x8009417C: mul.s       $f8, $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = MUL_S(ctx->f8.fl, ctx->f4.fl);
    // 0x80094180: lwc1        $f10, 0x8($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X8);
    // 0x80094184: mul.s       $f8, $f8, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = MUL_S(ctx->f8.fl, ctx->f16.fl);
    // 0x80094188: lw          $t1, 0x18($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X18);
    // 0x8009418C: mul.s       $f8, $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x80094190: cvt.w.s     $f8, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    ctx->f8.u32l = CVT_W_S(ctx->f8.fl);
    // 0x80094194: mfc1        $t0, $f8
    ctx->r8 = (int32_t)ctx->f8.u32l;
    // 0x80094198: sh          $t0, 0x0($t1)
    MEM_H(0X0, ctx->r9) = ctx->r8;
    // 0x8009419C: lui         $t1, 0x7F
    ctx->r9 = S32(0X7F << 16);
    // 0x800941A0: ori         $t1, $t1, 0xFFFF
    ctx->r9 = ctx->r9 | 0XFFFF;
    // 0x800941A4: subu        $t1, $t1, $a2
    ctx->r9 = SUB32(ctx->r9, ctx->r6);
    // 0x800941A8: sll         $t0, $t1, 10
    ctx->r8 = S32(ctx->r9 << 10);
    // 0x800941AC: srl         $t0, $t0, 10
    ctx->r8 = S32(U32(ctx->r8) >> 10);
    // 0x800941B0: mtc1        $t0, $f18
    ctx->f18.u32l = ctx->r8;
    // 0x800941B4: srl         $t0, $t1, 22
    ctx->r8 = S32(U32(ctx->r9) >> 22);
    // 0x800941B8: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x800941BC: lui         $t1, 0x800A
    ctx->r9 = S32(0X800A << 16);
    // 0x800941C0: ori         $t1, $t1, 0x4DE8
    ctx->r9 = ctx->r9 | 0X4DE8;
    // 0x800941C4: addu        $t0, $t0, $t1
    ctx->r8 = ADD32(ctx->r8, ctx->r9);
    // 0x800941C8: cvt.s.w     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.fl = CVT_S_W(ctx->f18.u32l);
    // 0x800941CC: lwc1        $f16, 0xC($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0XC);
    // 0x800941D0: lwc1        $f8, 0x0($t0)
    ctx->f8.u32l = MEM_W(ctx->r8, 0X0);
    // 0x800941D4: lwc1        $f10, 0x4($t0)
    ctx->f10.u32l = MEM_W(ctx->r8, 0X4);
    // 0x800941D8: mul.s       $f18, $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f18.fl, ctx->f16.fl);
    // 0x800941DC: sub.s       $f10, $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f10.fl - ctx->f8.fl;
    // 0x800941E0: mul.s       $f10, $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = MUL_S(ctx->f10.fl, ctx->f18.fl);
    // 0x800941E4: add.s       $f8, $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x800941E8: mul.s       $f4, $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = MUL_S(ctx->f4.fl, ctx->f8.fl);
    // 0x800941EC: lui         $t0, 0x80
    ctx->r8 = S32(0X80 << 16);
    // 0x800941F0: bne         $a3, $t0, L_80094208
    if (ctx->r7 != ctx->r8) {
        // 0x800941F4: nop
    
            goto L_80094208;
    }
    // 0x800941F4: nop

    // 0x800941F8: lwc1        $f6, 0x4($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X4);
    // 0x800941FC: mul.s       $f4, $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80094200: j           L_8009429C
    // 0x80094204: neg.s       $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = -ctx->f4.fl;
        goto L_8009429C;
    // 0x80094204: neg.s       $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = -ctx->f4.fl;
L_80094208:
    // 0x80094208: lui         $t1, 0x7F
    ctx->r9 = S32(0X7F << 16);
    // 0x8009420C: ori         $t1, $t1, 0xFFFF
    ctx->r9 = ctx->r9 | 0XFFFF;
    // 0x80094210: subu        $t1, $t1, $a3
    ctx->r9 = SUB32(ctx->r9, ctx->r7);
    // 0x80094214: sll         $t0, $t1, 10
    ctx->r8 = S32(ctx->r9 << 10);
    // 0x80094218: srl         $t0, $t0, 10
    ctx->r8 = S32(U32(ctx->r8) >> 10);
    // 0x8009421C: mtc1        $t0, $f18
    ctx->f18.u32l = ctx->r8;
    // 0x80094220: srl         $t0, $t1, 22
    ctx->r8 = S32(U32(ctx->r9) >> 22);
    // 0x80094224: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x80094228: lui         $t1, 0x800A
    ctx->r9 = S32(0X800A << 16);
    // 0x8009422C: ori         $t1, $t1, 0x4DE8
    ctx->r9 = ctx->r9 | 0X4DE8;
    // 0x80094230: addu        $t0, $t0, $t1
    ctx->r8 = ADD32(ctx->r8, ctx->r9);
    // 0x80094234: cvt.s.w     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80094238: lwc1        $f16, 0xC($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0XC);
    // 0x8009423C: lwc1        $f8, 0x0($t0)
    ctx->f8.u32l = MEM_W(ctx->r8, 0X0);
    // 0x80094240: lwc1        $f10, 0x4($t0)
    ctx->f10.u32l = MEM_W(ctx->r8, 0X4);
    // 0x80094244: mul.s       $f18, $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f18.fl, ctx->f16.fl);
    // 0x80094248: sub.s       $f10, $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f10.fl - ctx->f8.fl;
    // 0x8009424C: mul.s       $f10, $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = MUL_S(ctx->f10.fl, ctx->f18.fl);
    // 0x80094250: add.s       $f8, $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80094254: mul.s       $f6, $f4, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f8.fl);
    // 0x80094258: sll         $t0, $a3, 10
    ctx->r8 = S32(ctx->r7 << 10);
    // 0x8009425C: srl         $t0, $t0, 10
    ctx->r8 = S32(U32(ctx->r8) >> 10);
    // 0x80094260: mtc1        $t0, $f18
    ctx->f18.u32l = ctx->r8;
    // 0x80094264: srl         $t0, $a3, 22
    ctx->r8 = S32(U32(ctx->r7) >> 22);
    // 0x80094268: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x8009426C: lui         $t1, 0x800A
    ctx->r9 = S32(0X800A << 16);
    // 0x80094270: ori         $t1, $t1, 0x4DE8
    ctx->r9 = ctx->r9 | 0X4DE8;
    // 0x80094274: addu        $t0, $t0, $t1
    ctx->r8 = ADD32(ctx->r8, ctx->r9);
    // 0x80094278: cvt.s.w     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.fl = CVT_S_W(ctx->f18.u32l);
    // 0x8009427C: lwc1        $f16, 0xC($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0XC);
    // 0x80094280: lwc1        $f8, 0x0($t0)
    ctx->f8.u32l = MEM_W(ctx->r8, 0X0);
    // 0x80094284: lwc1        $f10, 0x4($t0)
    ctx->f10.u32l = MEM_W(ctx->r8, 0X4);
    // 0x80094288: mul.s       $f18, $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f18.fl, ctx->f16.fl);
    // 0x8009428C: sub.s       $f10, $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f10.fl - ctx->f8.fl;
    // 0x80094290: mul.s       $f10, $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = MUL_S(ctx->f10.fl, ctx->f18.fl);
    // 0x80094294: add.s       $f8, $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80094298: mul.s       $f4, $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = MUL_S(ctx->f4.fl, ctx->f8.fl);
L_8009429C:
    // 0x8009429C: lwc1        $f8, 0x8($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X8);
    // 0x800942A0: mul.s       $f4, $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = MUL_S(ctx->f4.fl, ctx->f8.fl);
    // 0x800942A4: nop

    // 0x800942A8: mul.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x800942AC: cvt.w.s     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.u32l = CVT_W_S(ctx->f4.fl);
    // 0x800942B0: cvt.w.s     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.u32l = CVT_W_S(ctx->f6.fl);
    // 0x800942B4: mfc1        $t0, $f4
    ctx->r8 = (int32_t)ctx->f4.u32l;
    // 0x800942B8: mfc1        $t1, $f6
    ctx->r9 = (int32_t)ctx->f6.u32l;
    // 0x800942BC: sh          $t0, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r8;
    // 0x800942C0: sh          $t1, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r9;
    // 0x800942C4: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    // 0x800942C8: lui         $t0, 0x7F
    ctx->r8 = S32(0X7F << 16);
    // 0x800942CC: slt         $t1, $a2, $t0
    ctx->r9 = SIGNED(ctx->r6) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x800942D0: bne         $t1, $zero, L_800942DC
    if (ctx->r9 != 0) {
        // 0x800942D4: nop
    
            goto L_800942DC;
    }
    // 0x800942D4: nop

    // 0x800942D8: addu        $a2, $t0, $zero
    ctx->r6 = ADD32(ctx->r8, 0);
L_800942DC:
    // 0x800942DC: srl         $t1, $a2, 16
    ctx->r9 = S32(U32(ctx->r6) >> 16);
    // 0x800942E0: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x800942E4: lui         $t0, 0x800A
    ctx->r8 = S32(0X800A << 16);
    // 0x800942E8: ori         $t0, $t0, 0x4BD8
    ctx->r8 = ctx->r8 | 0X4BD8;
    // 0x800942EC: addu        $t0, $t0, $t1
    ctx->r8 = ADD32(ctx->r8, ctx->r9);
    // 0x800942F0: andi        $t1, $a2, 0xFFFF
    ctx->r9 = ctx->r6 & 0XFFFF;
    // 0x800942F4: mtc1        $t1, $f6
    ctx->f6.u32l = ctx->r9;
    // 0x800942F8: lwc1        $f8, 0x0($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X0);
    // 0x800942FC: cvt.s.w     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80094300: lwc1        $f4, 0x0($t0)
    ctx->f4.u32l = MEM_W(ctx->r8, 0X0);
    // 0x80094304: lwc1        $f10, 0x4($t0)
    ctx->f10.u32l = MEM_W(ctx->r8, 0X4);
    // 0x80094308: mul.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x8009430C: sub.s       $f10, $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f10.fl - ctx->f4.fl;
    // 0x80094310: mul.s       $f10, $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f10.fl, ctx->f6.fl);
    // 0x80094314: add.s       $f4, $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x80094318: lwc1        $f6, 0x4($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X4);
    // 0x8009431C: lwc1        $f8, 0x8($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X8);
    // 0x80094320: lw          $t1, 0x20($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X20);
    // 0x80094324: mul.s       $f4, $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80094328: nop

    // 0x8009432C: mul.s       $f4, $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = MUL_S(ctx->f4.fl, ctx->f8.fl);
    // 0x80094330: cvt.w.s     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.u32l = CVT_W_S(ctx->f4.fl);
    // 0x80094334: mfc1        $t0, $f4
    ctx->r8 = (int32_t)ctx->f4.u32l;
    // 0x80094338: sh          $t0, 0x0($t1)
    MEM_H(0X0, ctx->r9) = ctx->r8;
    // 0x8009433C: lw          $a2, 0x0($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X0);
    // 0x80094340: jr          $ra
    // 0x80094344: addiu       $sp, $sp, 0x4
    ctx->r29 = ADD32(ctx->r29, 0X4);
    return;
    // 0x80094344: addiu       $sp, $sp, 0x4
    ctx->r29 = ADD32(ctx->r29, 0X4);
;}
RECOMP_FUNC void fake_func_80094348(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
;}
RECOMP_FUNC void func_80094350(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80094350: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x80094354: sw          $s6, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r22;
    // 0x80094358: lw          $s6, 0x60($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X60);
    // 0x8009435C: sw          $s3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r19;
    // 0x80094360: addu        $s3, $a2, $zero
    ctx->r19 = ADD32(ctx->r6, 0);
    // 0x80094364: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x80094368: addu        $s0, $a3, $zero
    ctx->r16 = ADD32(ctx->r7, 0);
    // 0x8009436C: sw          $s5, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r21;
    // 0x80094370: addu        $s5, $zero, $zero
    ctx->r21 = ADD32(0, 0);
    // 0x80094374: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
    // 0x80094378: sw          $ra, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r31;
    // 0x8009437C: sw          $s7, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r23;
    // 0x80094380: sw          $s4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r20;
    // 0x80094384: sw          $s2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r18;
    // 0x80094388: sw          $s1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r17;
L_8009438C:
    // 0x8009438C: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80094390: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x80094394: lbu         $v0, -0x573F($at)
    ctx->r2 = MEM_BU(ctx->r1, -0X573F);
    // 0x80094398: bne         $v0, $zero, L_800943B4
    if (ctx->r2 != 0) {
        // 0x8009439C: addiu       $v0, $zero, 0x8
        ctx->r2 = ADD32(0, 0X8);
            goto L_800943B4;
    }
    // 0x8009439C: addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
    // 0x800943A0: addiu       $s5, $s5, 0x1
    ctx->r21 = ADD32(ctx->r21, 0X1);
    // 0x800943A4: sltiu       $v0, $s5, 0x8
    ctx->r2 = ctx->r21 < 0X8 ? 1 : 0;
    // 0x800943A8: bne         $v0, $zero, L_8009438C
    if (ctx->r2 != 0) {
        // 0x800943AC: addiu       $v1, $v1, 0xEF8
        ctx->r3 = ADD32(ctx->r3, 0XEF8);
            goto L_8009438C;
    }
    // 0x800943AC: addiu       $v1, $v1, 0xEF8
    ctx->r3 = ADD32(ctx->r3, 0XEF8);
    // 0x800943B0: addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
L_800943B4:
    // 0x800943B4: beq         $s5, $v0, L_80094924
    if (ctx->r21 == ctx->r2) {
        // 0x800943B8: sll         $v0, $s5, 4
        ctx->r2 = S32(ctx->r21 << 4);
            goto L_80094924;
    }
    // 0x800943B8: sll         $v0, $s5, 4
    ctx->r2 = S32(ctx->r21 << 4);
    // 0x800943BC: subu        $v0, $v0, $s5
    ctx->r2 = SUB32(ctx->r2, ctx->r21);
    // 0x800943C0: sll         $v0, $v0, 5
    ctx->r2 = S32(ctx->r2 << 5);
    // 0x800943C4: subu        $v0, $v0, $s5
    ctx->r2 = SUB32(ctx->r2, ctx->r21);
    // 0x800943C8: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x800943CC: lui         $v1, 0x8015
    ctx->r3 = S32(0X8015 << 16);
    // 0x800943D0: addiu       $v1, $v1, -0x6600
    ctx->r3 = ADD32(ctx->r3, -0X6600);
    // 0x800943D4: addu        $s2, $v0, $v1
    ctx->r18 = ADD32(ctx->r2, ctx->r3);
    // 0x800943D8: addiu       $a3, $s2, 0x8
    ctx->r7 = ADD32(ctx->r18, 0X8);
    // 0x800943DC: sw          $a0, 0x4($s2)
    MEM_W(0X4, ctx->r18) = ctx->r4;
    // 0x800943E0: lw          $a2, 0x4($s2)
    ctx->r6 = MEM_W(ctx->r18, 0X4);
    // 0x800943E4: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x800943E8: addiu       $v1, $zero, 0xFF
    ctx->r3 = ADD32(0, 0XFF);
    // 0x800943EC: sb          $zero, 0xEF4($s2)
    MEM_B(0XEF4, ctx->r18) = 0;
    // 0x800943F0: sw          $a1, 0x88($s2)
    MEM_W(0X88, ctx->r18) = ctx->r5;
    // 0x800943F4: sw          $s0, 0x10C($s2)
    MEM_W(0X10C, ctx->r18) = ctx->r16;
    // 0x800943F8: andi        $v0, $a0, 0xFF
    ctx->r2 = ctx->r4 & 0XFF;
L_800943FC:
    // 0x800943FC: addu        $v0, $a3, $v0
    ctx->r2 = ADD32(ctx->r7, ctx->r2);
    // 0x80094400: sb          $v1, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r3;
    // 0x80094404: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x80094408: andi        $v0, $a0, 0xFF
    ctx->r2 = ctx->r4 & 0XFF;
    // 0x8009440C: sltiu       $v0, $v0, 0x80
    ctx->r2 = ctx->r2 < 0X80 ? 1 : 0;
    // 0x80094410: bne         $v0, $zero, L_800943FC
    if (ctx->r2 != 0) {
        // 0x80094414: andi        $v0, $a0, 0xFF
        ctx->r2 = ctx->r4 & 0XFF;
            goto L_800943FC;
    }
    // 0x80094414: andi        $v0, $a0, 0xFF
    ctx->r2 = ctx->r4 & 0XFF;
    // 0x80094418: lbu         $a1, 0x5($a2)
    ctx->r5 = MEM_BU(ctx->r6, 0X5);
    // 0x8009441C: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // 0x80094420: andi        $v1, $a1, 0xFF
    ctx->r3 = ctx->r5 & 0XFF;
    // 0x80094424: beq         $v1, $v0, L_80094448
    if (ctx->r3 == ctx->r2) {
        // 0x80094428: addu        $a0, $zero, $zero
        ctx->r4 = ADD32(0, 0);
            goto L_80094448;
    }
    // 0x80094428: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x8009442C: addiu       $v1, $zero, 0xFF
    ctx->r3 = ADD32(0, 0XFF);
L_80094430:
    // 0x80094430: addiu       $a2, $a2, 0x8
    ctx->r6 = ADD32(ctx->r6, 0X8);
    // 0x80094434: addu        $v0, $a1, $a3
    ctx->r2 = ADD32(ctx->r5, ctx->r7);
    // 0x80094438: sb          $a0, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r4;
    // 0x8009443C: lbu         $a1, 0x5($a2)
    ctx->r5 = MEM_BU(ctx->r6, 0X5);
    // 0x80094440: bne         $a1, $v1, L_80094430
    if (ctx->r5 != ctx->r3) {
        // 0x80094444: addiu       $a0, $a0, 0x1
        ctx->r4 = ADD32(ctx->r4, 0X1);
            goto L_80094430;
    }
    // 0x80094444: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
L_80094448:
    // 0x80094448: addiu       $a3, $s2, 0x8C
    ctx->r7 = ADD32(ctx->r18, 0X8C);
    // 0x8009444C: lw          $a2, 0x88($s2)
    ctx->r6 = MEM_W(ctx->r18, 0X88);
    // 0x80094450: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x80094454: addiu       $v1, $zero, 0xFF
    ctx->r3 = ADD32(0, 0XFF);
    // 0x80094458: andi        $v0, $a0, 0xFF
    ctx->r2 = ctx->r4 & 0XFF;
L_8009445C:
    // 0x8009445C: addu        $v0, $a3, $v0
    ctx->r2 = ADD32(ctx->r7, ctx->r2);
    // 0x80094460: sb          $v1, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r3;
    // 0x80094464: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x80094468: andi        $v0, $a0, 0xFF
    ctx->r2 = ctx->r4 & 0XFF;
    // 0x8009446C: sltiu       $v0, $v0, 0x80
    ctx->r2 = ctx->r2 < 0X80 ? 1 : 0;
    // 0x80094470: bne         $v0, $zero, L_8009445C
    if (ctx->r2 != 0) {
        // 0x80094474: andi        $v0, $a0, 0xFF
        ctx->r2 = ctx->r4 & 0XFF;
            goto L_8009445C;
    }
    // 0x80094474: andi        $v0, $a0, 0xFF
    ctx->r2 = ctx->r4 & 0XFF;
    // 0x80094478: lbu         $a1, 0x5($a2)
    ctx->r5 = MEM_BU(ctx->r6, 0X5);
    // 0x8009447C: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // 0x80094480: andi        $v1, $a1, 0xFF
    ctx->r3 = ctx->r5 & 0XFF;
    // 0x80094484: beq         $v1, $v0, L_800944A8
    if (ctx->r3 == ctx->r2) {
        // 0x80094488: addu        $a0, $zero, $zero
        ctx->r4 = ADD32(0, 0);
            goto L_800944A8;
    }
    // 0x80094488: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x8009448C: addiu       $v1, $zero, 0xFF
    ctx->r3 = ADD32(0, 0XFF);
L_80094490:
    // 0x80094490: addiu       $a2, $a2, 0x8
    ctx->r6 = ADD32(ctx->r6, 0X8);
    // 0x80094494: addu        $v0, $a1, $a3
    ctx->r2 = ADD32(ctx->r5, ctx->r7);
    // 0x80094498: sb          $a0, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r4;
    // 0x8009449C: lbu         $a1, 0x5($a2)
    ctx->r5 = MEM_BU(ctx->r6, 0X5);
    // 0x800944A0: bne         $a1, $v1, L_80094490
    if (ctx->r5 != ctx->r3) {
        // 0x800944A4: addiu       $a0, $a0, 0x1
        ctx->r4 = ADD32(ctx->r4, 0X1);
            goto L_80094490;
    }
    // 0x800944A4: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
L_800944A8:
    // 0x800944A8: addiu       $v0, $s5, 0x17
    ctx->r2 = ADD32(ctx->r21, 0X17);
    // 0x800944AC: sb          $v0, 0xEC4($s2)
    MEM_B(0XEC4, ctx->r18) = ctx->r2;
    // 0x800944B0: addu        $s1, $zero, $zero
    ctx->r17 = ADD32(0, 0);
L_800944B4:
    // 0x800944B4: lbu         $v1, 0xEC4($s2)
    ctx->r3 = MEM_BU(ctx->r18, 0XEC4);
    // 0x800944B8: addu        $v0, $s2, $s1
    ctx->r2 = ADD32(ctx->r18, ctx->r17);
    // 0x800944BC: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x800944C0: sb          $v1, 0x528($v0)
    MEM_B(0X528, ctx->r2) = ctx->r3;
    // 0x800944C4: slti        $v0, $s1, 0x40
    ctx->r2 = SIGNED(ctx->r17) < 0X40 ? 1 : 0;
    // 0x800944C8: bne         $v0, $zero, L_800944B4
    if (ctx->r2 != 0) {
        // 0x800944CC: nop
    
            goto L_800944B4;
    }
    // 0x800944CC: nop

    // 0x800944D0: bne         $s6, $zero, L_800944EC
    if (ctx->r22 != 0) {
        // 0x800944D4: addiu       $v0, $zero, -0x1
        ctx->r2 = ADD32(0, -0X1);
            goto L_800944EC;
    }
    // 0x800944D4: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x800944D8: sw          $v0, 0x110($s2)
    MEM_W(0X110, ctx->r18) = ctx->r2;
    // 0x800944DC: sw          $v0, 0x114($s2)
    MEM_W(0X114, ctx->r18) = ctx->r2;
    // 0x800944E0: addiu       $v0, $zero, 0x100
    ctx->r2 = ADD32(0, 0X100);
    // 0x800944E4: j           L_800945FC
    // 0x800944E8: sh          $v0, 0xEC2($s2)
    MEM_H(0XEC2, ctx->r18) = ctx->r2;
        goto L_800945FC;
    // 0x800944E8: sh          $v0, 0xEC2($s2)
    MEM_H(0XEC2, ctx->r18) = ctx->r2;
L_800944EC:
    // 0x800944EC: lw          $v0, 0x0($s6)
    ctx->r2 = MEM_W(ctx->r22, 0X0);
    // 0x800944F0: andi        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 & 0X1;
    // 0x800944F4: beq         $v0, $zero, L_80094510
    if (ctx->r2 == 0) {
        // 0x800944F8: addiu       $v0, $zero, -0x1
        ctx->r2 = ADD32(0, -0X1);
            goto L_80094510;
    }
    // 0x800944F8: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x800944FC: lw          $v0, 0x4($s6)
    ctx->r2 = MEM_W(ctx->r22, 0X4);
    // 0x80094500: sw          $v0, 0x110($s2)
    MEM_W(0X110, ctx->r18) = ctx->r2;
    // 0x80094504: lw          $v0, 0x8($s6)
    ctx->r2 = MEM_W(ctx->r22, 0X8);
    // 0x80094508: j           L_80094518
    // 0x8009450C: sw          $v0, 0x114($s2)
    MEM_W(0X114, ctx->r18) = ctx->r2;
        goto L_80094518;
    // 0x8009450C: sw          $v0, 0x114($s2)
    MEM_W(0X114, ctx->r18) = ctx->r2;
L_80094510:
    // 0x80094510: sw          $v0, 0x110($s2)
    MEM_W(0X110, ctx->r18) = ctx->r2;
    // 0x80094514: sw          $v0, 0x114($s2)
    MEM_W(0X114, ctx->r18) = ctx->r2;
L_80094518:
    // 0x80094518: lw          $v0, 0x0($s6)
    ctx->r2 = MEM_W(ctx->r22, 0X0);
    // 0x8009451C: andi        $v0, $v0, 0x2
    ctx->r2 = ctx->r2 & 0X2;
    // 0x80094520: beq         $v0, $zero, L_80094534
    if (ctx->r2 == 0) {
        // 0x80094524: addiu       $v0, $zero, 0x100
        ctx->r2 = ADD32(0, 0X100);
            goto L_80094534;
    }
    // 0x80094524: addiu       $v0, $zero, 0x100
    ctx->r2 = ADD32(0, 0X100);
    // 0x80094528: lhu         $v0, 0xC($s6)
    ctx->r2 = MEM_HU(ctx->r22, 0XC);
    // 0x8009452C: j           L_80094538
    // 0x80094530: sh          $v0, 0xEC2($s2)
    MEM_H(0XEC2, ctx->r18) = ctx->r2;
        goto L_80094538;
    // 0x80094530: sh          $v0, 0xEC2($s2)
    MEM_H(0XEC2, ctx->r18) = ctx->r2;
L_80094534:
    // 0x80094534: sh          $v0, 0xEC2($s2)
    MEM_H(0XEC2, ctx->r18) = ctx->r2;
L_80094538:
    // 0x80094538: lw          $v0, 0x0($s6)
    ctx->r2 = MEM_W(ctx->r22, 0X0);
    // 0x8009453C: andi        $v0, $v0, 0x8
    ctx->r2 = ctx->r2 & 0X8;
    // 0x80094540: beq         $v0, $zero, L_80094598
    if (ctx->r2 == 0) {
        // 0x80094544: nop
    
            goto L_80094598;
    }
    // 0x80094544: nop

    // 0x80094548: lbu         $v0, 0x12($s6)
    ctx->r2 = MEM_BU(ctx->r22, 0X12);
    // 0x8009454C: blez        $v0, L_80094598
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80094550: addu        $s1, $zero, $zero
        ctx->r17 = ADD32(0, 0);
            goto L_80094598;
    }
    // 0x80094550: addu        $s1, $zero, $zero
    ctx->r17 = ADD32(0, 0);
L_80094554:
    // 0x80094554: lw          $v1, 0x14($s6)
    ctx->r3 = MEM_W(ctx->r22, 0X14);
    // 0x80094558: sll         $a0, $s1, 1
    ctx->r4 = S32(ctx->r17 << 1);
    // 0x8009455C: addu        $v1, $a0, $v1
    ctx->r3 = ADD32(ctx->r4, ctx->r3);
    // 0x80094560: lbu         $v0, 0x0($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X0);
    // 0x80094564: lbu         $v1, 0x1($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X1);
    // 0x80094568: addu        $v0, $s2, $v0
    ctx->r2 = ADD32(ctx->r18, ctx->r2);
    // 0x8009456C: sb          $v1, 0x528($v0)
    MEM_B(0X528, ctx->r2) = ctx->r3;
    // 0x80094570: lw          $v0, 0x14($s6)
    ctx->r2 = MEM_W(ctx->r22, 0X14);
    // 0x80094574: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // 0x80094578: lbu         $a0, 0x1($a0)
    ctx->r4 = MEM_BU(ctx->r4, 0X1);
    // 0x8009457C: jal         0x8008E54C
    // 0x80094580: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    func_8008E54C(rdram, ctx);
        goto after_0;
    // 0x80094580: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    after_0:
    // 0x80094584: lbu         $v0, 0x12($s6)
    ctx->r2 = MEM_BU(ctx->r22, 0X12);
    // 0x80094588: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x8009458C: slt         $v0, $s1, $v0
    ctx->r2 = SIGNED(ctx->r17) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80094590: bne         $v0, $zero, L_80094554
    if (ctx->r2 != 0) {
        // 0x80094594: nop
    
            goto L_80094554;
    }
    // 0x80094594: nop

L_80094598:
    // 0x80094598: lw          $v0, 0x0($s6)
    ctx->r2 = MEM_W(ctx->r22, 0X0);
    // 0x8009459C: andi        $v0, $v0, 0x4
    ctx->r2 = ctx->r2 & 0X4;
    // 0x800945A0: beq         $v0, $zero, L_800945FC
    if (ctx->r2 == 0) {
        // 0x800945A4: addu        $a3, $zero, $zero
        ctx->r7 = ADD32(0, 0);
            goto L_800945FC;
    }
    // 0x800945A4: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    // 0x800945A8: lbu         $a0, 0x10($s6)
    ctx->r4 = MEM_BU(ctx->r22, 0X10);
    // 0x800945AC: lhu         $a1, 0xE($s6)
    ctx->r5 = MEM_HU(ctx->r22, 0XE);
    // 0x800945B0: lbu         $a2, 0xEC4($s2)
    ctx->r6 = MEM_BU(ctx->r18, 0XEC4);
    // 0x800945B4: jal         0x8008DD60
    // 0x800945B8: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    func_8008DD60(rdram, ctx);
        goto after_1;
    // 0x800945B8: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_1:
    // 0x800945BC: lbu         $v0, 0x18($s6)
    ctx->r2 = MEM_BU(ctx->r22, 0X18);
    // 0x800945C0: blez        $v0, L_800945FC
    if (SIGNED(ctx->r2) <= 0) {
        // 0x800945C4: addu        $s1, $zero, $zero
        ctx->r17 = ADD32(0, 0);
            goto L_800945FC;
    }
    // 0x800945C4: addu        $s1, $zero, $zero
    ctx->r17 = ADD32(0, 0);
L_800945C8:
    // 0x800945C8: lw          $v0, 0x1C($s6)
    ctx->r2 = MEM_W(ctx->r22, 0X1C);
    // 0x800945CC: lbu         $a0, 0x10($s6)
    ctx->r4 = MEM_BU(ctx->r22, 0X10);
    // 0x800945D0: lhu         $a1, 0xE($s6)
    ctx->r5 = MEM_HU(ctx->r22, 0XE);
    // 0x800945D4: addu        $v0, $v0, $s1
    ctx->r2 = ADD32(ctx->r2, ctx->r17);
    // 0x800945D8: lbu         $a2, 0x0($v0)
    ctx->r6 = MEM_BU(ctx->r2, 0X0);
    // 0x800945DC: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    // 0x800945E0: jal         0x8008DD60
    // 0x800945E4: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    func_8008DD60(rdram, ctx);
        goto after_2;
    // 0x800945E4: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_2:
    // 0x800945E8: lbu         $v0, 0x18($s6)
    ctx->r2 = MEM_BU(ctx->r22, 0X18);
    // 0x800945EC: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x800945F0: slt         $v0, $s1, $v0
    ctx->r2 = SIGNED(ctx->r17) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800945F4: bne         $v0, $zero, L_800945C8
    if (ctx->r2 != 0) {
        // 0x800945F8: nop
    
            goto L_800945C8;
    }
    // 0x800945F8: nop

L_800945FC:
    // 0x800945FC: lw          $a0, 0x10($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X10);
    // 0x80094600: andi        $a1, $s5, 0xFF
    ctx->r5 = ctx->r21 & 0XFF;
    // 0x80094604: jal         0x80083D20
    // 0x80094608: sw          $a0, 0x124($s2)
    MEM_W(0X124, ctx->r18) = ctx->r4;
    func_80083D20(rdram, ctx);
        goto after_3;
    // 0x80094608: sw          $a0, 0x124($s2)
    MEM_W(0X124, ctx->r18) = ctx->r4;
    after_3:
    // 0x8009460C: lw          $v0, 0xC($s0)
    ctx->r2 = MEM_W(ctx->r16, 0XC);
    // 0x80094610: addu        $s1, $zero, $zero
    ctx->r17 = ADD32(0, 0);
    // 0x80094614: addiu       $a2, $zero, 0x7F
    ctx->r6 = ADD32(0, 0X7F);
    // 0x80094618: sw          $zero, 0xE70($s2)
    MEM_W(0XE70, ctx->r18) = 0;
    // 0x8009461C: sw          $zero, 0xE74($s2)
    MEM_W(0XE74, ctx->r18) = 0;
    // 0x80094620: sb          $zero, 0xEC5($s2)
    MEM_B(0XEC5, ctx->r18) = 0;
    // 0x80094624: addu        $v0, $v0, $s0
    ctx->r2 = ADD32(ctx->r2, ctx->r16);
    // 0x80094628: sw          $v0, 0xE68($s2)
    MEM_W(0XE68, ctx->r18) = ctx->r2;
    // 0x8009462C: sw          $v0, 0xE6C($s2)
    MEM_W(0XE6C, ctx->r18) = ctx->r2;
    // 0x80094630: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80094634: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // 0x80094638: addu        $v1, $s2, $zero
    ctx->r3 = ADD32(ctx->r18, 0);
    // 0x8009463C: addu        $a1, $v0, $s0
    ctx->r5 = ADD32(ctx->r2, ctx->r16);
L_80094640:
    // 0x80094640: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x80094644: addu        $at, $at, $s1
    ctx->r1 = ADD32(ctx->r1, ctx->r17);
    // 0x80094648: sb          $a2, 0x1AD8($at)
    MEM_B(0X1AD8, ctx->r1) = ctx->r6;
    // 0x8009464C: sw          $zero, 0x130($v1)
    MEM_W(0X130, ctx->r3) = 0;
    // 0x80094650: sw          $zero, 0x134($v1)
    MEM_W(0X134, ctx->r3) = 0;
    // 0x80094654: sw          $zero, 0x570($a0)
    MEM_W(0X570, ctx->r4) = 0;
    // 0x80094658: sw          $zero, 0x574($a0)
    MEM_W(0X574, ctx->r4) = 0;
    // 0x8009465C: sw          $zero, 0x578($a0)
    MEM_W(0X578, ctx->r4) = 0;
    // 0x80094660: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x80094664: beq         $v0, $zero, L_80094678
    if (ctx->r2 == 0) {
        // 0x80094668: addu        $v0, $v0, $s0
        ctx->r2 = ADD32(ctx->r2, ctx->r16);
            goto L_80094678;
    }
    // 0x80094668: addu        $v0, $v0, $s0
    ctx->r2 = ADD32(ctx->r2, ctx->r16);
    // 0x8009466C: sw          $v0, 0x128($v1)
    MEM_W(0X128, ctx->r3) = ctx->r2;
    // 0x80094670: j           L_80094680
    // 0x80094674: sw          $v0, 0x12C($v1)
    MEM_W(0X12C, ctx->r3) = ctx->r2;
        goto L_80094680;
    // 0x80094674: sw          $v0, 0x12C($v1)
    MEM_W(0X12C, ctx->r3) = ctx->r2;
L_80094678:
    // 0x80094678: sw          $zero, 0x128($v1)
    MEM_W(0X128, ctx->r3) = 0;
    // 0x8009467C: sw          $zero, 0x12C($v1)
    MEM_W(0X12C, ctx->r3) = 0;
L_80094680:
    // 0x80094680: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x80094684: addiu       $a0, $a0, 0x24
    ctx->r4 = ADD32(ctx->r4, 0X24);
    // 0x80094688: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x8009468C: slti        $v0, $s1, 0x40
    ctx->r2 = SIGNED(ctx->r17) < 0X40 ? 1 : 0;
    // 0x80094690: bne         $v0, $zero, L_80094640
    if (ctx->r2 != 0) {
        // 0x80094694: addiu       $v1, $v1, 0x10
        ctx->r3 = ADD32(ctx->r3, 0X10);
            goto L_80094640;
    }
    // 0x80094694: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
    // 0x80094698: addu        $s1, $zero, $zero
    ctx->r17 = ADD32(0, 0);
    // 0x8009469C: sw          $zero, 0xE78($s2)
    MEM_W(0XE78, ctx->r18) = 0;
    // 0x800946A0: sw          $zero, 0xE7C($s2)
    MEM_W(0XE7C, ctx->r18) = 0;
    // 0x800946A4: andi        $a0, $s1, 0xFF
    ctx->r4 = ctx->r17 & 0XFF;
L_800946A8:
    // 0x800946A8: jal         0x80083F3C
    // 0x800946AC: andi        $a1, $s5, 0xFF
    ctx->r5 = ctx->r21 & 0XFF;
    func_80083F3C(rdram, ctx);
        goto after_4;
    // 0x800946AC: andi        $a1, $s5, 0xFF
    ctx->r5 = ctx->r21 & 0XFF;
    after_4:
    // 0x800946B0: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x800946B4: slti        $v0, $s1, 0x10
    ctx->r2 = SIGNED(ctx->r17) < 0X10 ? 1 : 0;
    // 0x800946B8: bne         $v0, $zero, L_800946A8
    if (ctx->r2 != 0) {
        // 0x800946BC: andi        $a0, $s1, 0xFF
        ctx->r4 = ctx->r17 & 0XFF;
            goto L_800946A8;
    }
    // 0x800946BC: andi        $a0, $s1, 0xFF
    ctx->r4 = ctx->r17 & 0XFF;
    // 0x800946C0: addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
    // 0x800946C4: addiu       $s1, $zero, 0xF
    ctx->r17 = ADD32(0, 0XF);
    // 0x800946C8: addiu       $v0, $s2, 0x3C
    ctx->r2 = ADD32(ctx->r18, 0X3C);
L_800946CC:
    // 0x800946CC: sw          $v1, 0xE80($v0)
    MEM_W(0XE80, ctx->r2) = ctx->r3;
    // 0x800946D0: addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
    // 0x800946D4: bgez        $s1, L_800946CC
    if (SIGNED(ctx->r17) >= 0) {
        // 0x800946D8: addiu       $v0, $v0, -0x4
        ctx->r2 = ADD32(ctx->r2, -0X4);
            goto L_800946CC;
    }
    // 0x800946D8: addiu       $v0, $v0, -0x4
    ctx->r2 = ADD32(ctx->r2, -0X4);
    // 0x800946DC: lw          $t1, 0x4($s2)
    ctx->r9 = MEM_W(ctx->r18, 0X4);
    // 0x800946E0: addiu       $v1, $s2, 0x8
    ctx->r3 = ADD32(ctx->r18, 0X8);
    // 0x800946E4: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    // 0x800946E8: addiu       $t2, $zero, 0xFF
    ctx->r10 = ADD32(0, 0XFF);
L_800946EC:
    // 0x800946EC: addu        $a2, $v1, $zero
    ctx->r6 = ADD32(ctx->r3, 0);
    // 0x800946F0: addiu       $t0, $a2, 0x80
    ctx->r8 = ADD32(ctx->r6, 0X80);
L_800946F4:
    // 0x800946F4: lbu         $v0, 0x0($a2)
    ctx->r2 = MEM_BU(ctx->r6, 0X0);
    // 0x800946F8: beq         $v0, $t2, L_80094734
    if (ctx->r2 == ctx->r10) {
        // 0x800946FC: sll         $v0, $v0, 3
        ctx->r2 = S32(ctx->r2 << 3);
            goto L_80094734;
    }
    // 0x800946FC: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x80094700: addu        $a1, $v0, $t1
    ctx->r5 = ADD32(ctx->r2, ctx->r9);
    // 0x80094704: lbu         $a0, 0x4($a1)
    ctx->r4 = MEM_BU(ctx->r5, 0X4);
    // 0x80094708: beq         $a0, $t2, L_80094734
    if (ctx->r4 == ctx->r10) {
        // 0x8009470C: sll         $a0, $a0, 2
        ctx->r4 = S32(ctx->r4 << 2);
            goto L_80094734;
    }
    // 0x8009470C: sll         $a0, $a0, 2
    ctx->r4 = S32(ctx->r4 << 2);
    // 0x80094710: lhu         $v0, 0x0($a1)
    ctx->r2 = MEM_HU(ctx->r5, 0X0);
    // 0x80094714: addu        $a0, $a0, $s2
    ctx->r4 = ADD32(ctx->r4, ctx->r18);
    // 0x80094718: lbu         $v1, 0x2($a1)
    ctx->r3 = MEM_BU(ctx->r5, 0X2);
    // 0x8009471C: lbu         $a1, 0x3($a1)
    ctx->r5 = MEM_BU(ctx->r5, 0X3);
    // 0x80094720: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x80094724: sll         $v1, $v1, 8
    ctx->r3 = S32(ctx->r3 << 8);
    // 0x80094728: or          $v0, $v0, $v1
    ctx->r2 = ctx->r2 | ctx->r3;
    // 0x8009472C: or          $v0, $v0, $a1
    ctx->r2 = ctx->r2 | ctx->r5;
    // 0x80094730: sw          $v0, 0xE80($a0)
    MEM_W(0XE80, ctx->r4) = ctx->r2;
L_80094734:
    // 0x80094734: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x80094738: slt         $v0, $a2, $t0
    ctx->r2 = SIGNED(ctx->r6) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x8009473C: bne         $v0, $zero, L_800946F4
    if (ctx->r2 != 0) {
        // 0x80094740: nop
    
            goto L_800946F4;
    }
    // 0x80094740: nop

    // 0x80094744: lw          $t1, 0x88($s2)
    ctx->r9 = MEM_W(ctx->r18, 0X88);
    // 0x80094748: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x8009474C: slti        $v0, $a3, 0x2
    ctx->r2 = SIGNED(ctx->r7) < 0X2 ? 1 : 0;
    // 0x80094750: bne         $v0, $zero, L_800946EC
    if (ctx->r2 != 0) {
        // 0x80094754: addiu       $v1, $s2, 0x8C
        ctx->r3 = ADD32(ctx->r18, 0X8C);
            goto L_800946EC;
    }
    // 0x80094754: addiu       $v1, $s2, 0x8C
    ctx->r3 = ADD32(ctx->r18, 0X8C);
    // 0x80094758: beq         $s3, $zero, L_80094864
    if (ctx->r19 == 0) {
        // 0x8009475C: nop
    
            goto L_80094864;
    }
    // 0x8009475C: nop

    // 0x80094760: addu        $s1, $zero, $zero
    ctx->r17 = ADD32(0, 0);
    // 0x80094764: addiu       $s7, $zero, 0xFF
    ctx->r23 = ADD32(0, 0XFF);
    // 0x80094768: andi        $s4, $s5, 0xFF
    ctx->r20 = ctx->r21 & 0XFF;
L_8009476C:
    // 0x8009476C: lbu         $a0, 0x4($s3)
    ctx->r4 = MEM_BU(ctx->r19, 0X4);
    // 0x80094770: andi        $a1, $s1, 0xFF
    ctx->r5 = ctx->r17 & 0XFF;
    // 0x80094774: addiu       $v0, $zero, 0x9
    ctx->r2 = ADD32(0, 0X9);
    // 0x80094778: beq         $a1, $v0, L_800947C4
    if (ctx->r5 == ctx->r2) {
        // 0x8009477C: addu        $v1, $a0, $zero
        ctx->r3 = ADD32(ctx->r4, 0);
            goto L_800947C4;
    }
    // 0x8009477C: addu        $v1, $a0, $zero
    ctx->r3 = ADD32(ctx->r4, 0);
    // 0x80094780: addu        $v0, $v1, $s2
    ctx->r2 = ADD32(ctx->r3, ctx->r18);
    // 0x80094784: lbu         $v1, 0x8($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X8);
    // 0x80094788: beq         $v1, $s7, L_800947FC
    if (ctx->r3 == ctx->r23) {
        // 0x8009478C: sll         $a1, $a1, 2
        ctx->r5 = S32(ctx->r5 << 2);
            goto L_800947FC;
    }
    // 0x8009478C: sll         $a1, $a1, 2
    ctx->r5 = S32(ctx->r5 << 2);
    // 0x80094790: lw          $v0, 0x4($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X4);
    // 0x80094794: sll         $v1, $v1, 3
    ctx->r3 = S32(ctx->r3 << 3);
    // 0x80094798: addu        $a1, $a1, $s2
    ctx->r5 = ADD32(ctx->r5, ctx->r18);
    // 0x8009479C: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x800947A0: lhu         $v0, 0x0($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X0);
    // 0x800947A4: lbu         $a0, 0x2($v1)
    ctx->r4 = MEM_BU(ctx->r3, 0X2);
    // 0x800947A8: lbu         $v1, 0x3($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X3);
    // 0x800947AC: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x800947B0: sll         $a0, $a0, 8
    ctx->r4 = S32(ctx->r4 << 8);
    // 0x800947B4: or          $v0, $v0, $a0
    ctx->r2 = ctx->r2 | ctx->r4;
    // 0x800947B8: or          $v0, $v0, $v1
    ctx->r2 = ctx->r2 | ctx->r3;
    // 0x800947BC: j           L_800947FC
    // 0x800947C0: sw          $v0, 0xE80($a1)
    MEM_W(0XE80, ctx->r5) = ctx->r2;
        goto L_800947FC;
    // 0x800947C0: sw          $v0, 0xE80($a1)
    MEM_W(0XE80, ctx->r5) = ctx->r2;
L_800947C4:
    // 0x800947C4: addu        $v0, $a0, $s2
    ctx->r2 = ADD32(ctx->r4, ctx->r18);
    // 0x800947C8: lbu         $v1, 0x8C($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X8C);
    // 0x800947CC: beq         $v1, $s7, L_800947FC
    if (ctx->r3 == ctx->r23) {
        // 0x800947D0: sll         $v1, $v1, 3
        ctx->r3 = S32(ctx->r3 << 3);
            goto L_800947FC;
    }
    // 0x800947D0: sll         $v1, $v1, 3
    ctx->r3 = S32(ctx->r3 << 3);
    // 0x800947D4: lw          $v0, 0x88($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X88);
    // 0x800947D8: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x800947DC: lhu         $v0, 0x0($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X0);
    // 0x800947E0: lbu         $a0, 0x2($v1)
    ctx->r4 = MEM_BU(ctx->r3, 0X2);
    // 0x800947E4: lbu         $v1, 0x3($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X3);
    // 0x800947E8: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x800947EC: sll         $a0, $a0, 8
    ctx->r4 = S32(ctx->r4 << 8);
    // 0x800947F0: or          $v0, $v0, $a0
    ctx->r2 = ctx->r2 | ctx->r4;
    // 0x800947F4: or          $v0, $v0, $v1
    ctx->r2 = ctx->r2 | ctx->r3;
    // 0x800947F8: sw          $v0, 0xEA4($s2)
    MEM_W(0XEA4, ctx->r18) = ctx->r2;
L_800947FC:
    // 0x800947FC: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    // 0x80094800: andi        $s0, $s1, 0xFF
    ctx->r16 = ctx->r17 & 0XFF;
    // 0x80094804: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x80094808: lbu         $a3, 0x5($s3)
    ctx->r7 = MEM_BU(ctx->r19, 0X5);
    // 0x8009480C: addu        $a2, $s4, $zero
    ctx->r6 = ADD32(ctx->r20, 0);
    // 0x80094810: jal         0x80083D9C
    // 0x80094814: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    func_80083D9C(rdram, ctx);
        goto after_5;
    // 0x80094814: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    after_5:
    // 0x80094818: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    // 0x8009481C: lbu         $a3, 0x6($s3)
    ctx->r7 = MEM_BU(ctx->r19, 0X6);
    // 0x80094820: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x80094824: jal         0x80083D9C
    // 0x80094828: addu        $a2, $s4, $zero
    ctx->r6 = ADD32(ctx->r20, 0);
    func_80083D9C(rdram, ctx);
        goto after_6;
    // 0x80094828: addu        $a2, $s4, $zero
    ctx->r6 = ADD32(ctx->r20, 0);
    after_6:
    // 0x8009482C: addiu       $a0, $zero, 0x5B
    ctx->r4 = ADD32(0, 0X5B);
    // 0x80094830: lbu         $a3, 0x7($s3)
    ctx->r7 = MEM_BU(ctx->r19, 0X7);
    // 0x80094834: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x80094838: jal         0x80083D9C
    // 0x8009483C: addu        $a2, $s4, $zero
    ctx->r6 = ADD32(ctx->r20, 0);
    func_80083D9C(rdram, ctx);
        goto after_7;
    // 0x8009483C: addu        $a2, $s4, $zero
    ctx->r6 = ADD32(ctx->r20, 0);
    after_7:
    // 0x80094840: addiu       $a0, $zero, 0x5D
    ctx->r4 = ADD32(0, 0X5D);
    // 0x80094844: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x80094848: lbu         $a3, 0x8($s3)
    ctx->r7 = MEM_BU(ctx->r19, 0X8);
    // 0x8009484C: addu        $a2, $s4, $zero
    ctx->r6 = ADD32(ctx->r20, 0);
    // 0x80094850: jal         0x80083D9C
    // 0x80094854: addiu       $s3, $s3, 0x8
    ctx->r19 = ADD32(ctx->r19, 0X8);
    func_80083D9C(rdram, ctx);
        goto after_8;
    // 0x80094854: addiu       $s3, $s3, 0x8
    ctx->r19 = ADD32(ctx->r19, 0X8);
    after_8:
    // 0x80094858: slti        $v0, $s1, 0x10
    ctx->r2 = SIGNED(ctx->r17) < 0X10 ? 1 : 0;
    // 0x8009485C: bne         $v0, $zero, L_8009476C
    if (ctx->r2 != 0) {
        // 0x80094860: nop
    
            goto L_8009476C;
    }
    // 0x80094860: nop

L_80094864:
    // 0x80094864: beq         $s6, $zero, L_8009487C
    if (ctx->r22 == 0) {
        // 0x80094868: sh          $zero, 0xEC6($s2)
        MEM_H(0XEC6, ctx->r18) = 0;
            goto L_8009487C;
    }
    // 0x80094868: sh          $zero, 0xEC6($s2)
    MEM_H(0XEC6, ctx->r18) = 0;
    // 0x8009486C: lw          $v0, 0x0($s6)
    ctx->r2 = MEM_W(ctx->r22, 0X0);
    // 0x80094870: andi        $v0, $v0, 0x10
    ctx->r2 = ctx->r2 & 0X10;
    // 0x80094874: bne         $v0, $zero, L_80094888
    if (ctx->r2 != 0) {
        // 0x80094878: addu        $a1, $s5, $zero
        ctx->r5 = ADD32(ctx->r21, 0);
            goto L_80094888;
    }
    // 0x80094878: addu        $a1, $s5, $zero
    ctx->r5 = ADD32(ctx->r21, 0);
L_8009487C:
    // 0x8009487C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80094880: sb          $v0, 0xEC0($s2)
    MEM_B(0XEC0, ctx->r18) = ctx->r2;
    // 0x80094884: addu        $a1, $s5, $zero
    ctx->r5 = ADD32(ctx->r21, 0);
L_80094888:
    // 0x80094888: lui         $a3, 0x7FFF
    ctx->r7 = S32(0X7FFF << 16);
    // 0x8009488C: ori         $a3, $a3, 0xFFFF
    ctx->r7 = ctx->r7 | 0XFFFF;
    // 0x80094890: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
L_80094894:
    // 0x80094894: lui         $v0, 0x8015
    ctx->r2 = S32(0X8015 << 16);
    // 0x80094898: lw          $v0, -0x6610($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X6610);
    // 0x8009489C: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // 0x800948A0: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
    // 0x800948A4: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // 0x800948A8: addiu       $v0, $a0, 0x1
    ctx->r2 = ADD32(ctx->r4, 0X1);
    // 0x800948AC: and         $v0, $v0, $a3
    ctx->r2 = ctx->r2 & ctx->r7;
    // 0x800948B0: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x800948B4: sw          $v0, -0x6610($at)
    MEM_W(-0X6610, ctx->r1) = ctx->r2;
L_800948B8:
    // 0x800948B8: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x800948BC: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x800948C0: lbu         $v0, -0x573F($at)
    ctx->r2 = MEM_BU(ctx->r1, -0X573F);
    // 0x800948C4: bnel        $v0, $zero, L_800948E8
    if (ctx->r2 != 0) {
        // 0x800948C8: addiu       $a2, $a2, 0x1
        ctx->r6 = ADD32(ctx->r6, 0X1);
            goto L_800948E8;
    }
    goto skip_0;
    // 0x800948C8: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    skip_0:
    // 0x800948CC: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x800948D0: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x800948D4: lw          $v0, -0x6600($at)
    ctx->r2 = MEM_W(ctx->r1, -0X6600);
    // 0x800948D8: bnel        $v0, $a0, L_800948E8
    if (ctx->r2 != ctx->r4) {
        // 0x800948DC: addiu       $a2, $a2, 0x1
        ctx->r6 = ADD32(ctx->r6, 0X1);
            goto L_800948E8;
    }
    goto skip_1;
    // 0x800948DC: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    skip_1:
    // 0x800948E0: j           L_800948F4
    // 0x800948E4: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
        goto L_800948F4;
    // 0x800948E4: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
L_800948E8:
    // 0x800948E8: sltiu       $v0, $a2, 0x8
    ctx->r2 = ctx->r6 < 0X8 ? 1 : 0;
    // 0x800948EC: bne         $v0, $zero, L_800948B8
    if (ctx->r2 != 0) {
        // 0x800948F0: addiu       $v1, $v1, 0xEF8
        ctx->r3 = ADD32(ctx->r3, 0XEF8);
            goto L_800948B8;
    }
    // 0x800948F0: addiu       $v1, $v1, 0xEF8
    ctx->r3 = ADD32(ctx->r3, 0XEF8);
L_800948F4:
    // 0x800948F4: beq         $a0, $t0, L_80094894
    if (ctx->r4 == ctx->r8) {
        // 0x800948F8: addu        $v0, $a0, $zero
        ctx->r2 = ADD32(ctx->r4, 0);
            goto L_80094894;
    }
    // 0x800948F8: addu        $v0, $a0, $zero
    ctx->r2 = ADD32(ctx->r4, 0);
    // 0x800948FC: sll         $v1, $a1, 4
    ctx->r3 = S32(ctx->r5 << 4);
    // 0x80094900: subu        $v1, $v1, $a1
    ctx->r3 = SUB32(ctx->r3, ctx->r5);
    // 0x80094904: sll         $v1, $v1, 5
    ctx->r3 = S32(ctx->r3 << 5);
    // 0x80094908: subu        $v1, $v1, $a1
    ctx->r3 = SUB32(ctx->r3, ctx->r5);
    // 0x8009490C: sll         $v1, $v1, 3
    ctx->r3 = S32(ctx->r3 << 3);
    // 0x80094910: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80094914: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x80094918: sw          $v0, -0x6600($at)
    MEM_W(-0X6600, ctx->r1) = ctx->r2;
    // 0x8009491C: j           L_80094928
    // 0x80094920: sb          $zero, 0xEC1($s2)
    MEM_B(0XEC1, ctx->r18) = 0;
        goto L_80094928;
    // 0x80094920: sb          $zero, 0xEC1($s2)
    MEM_B(0XEC1, ctx->r18) = 0;
L_80094924:
    // 0x80094924: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_80094928:
    // 0x80094928: lw          $ra, 0x48($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X48);
    // 0x8009492C: lw          $s7, 0x44($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X44);
    // 0x80094930: lw          $s6, 0x40($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X40);
    // 0x80094934: lw          $s5, 0x3C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X3C);
    // 0x80094938: lw          $s4, 0x38($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X38);
    // 0x8009493C: lw          $s3, 0x34($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X34);
    // 0x80094940: lw          $s2, 0x30($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X30);
    // 0x80094944: lw          $s1, 0x2C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X2C);
    // 0x80094948: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x8009494C: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // 0x80094950: jr          $ra
    // 0x80094954: nop

    return;
    // 0x80094954: nop

;}
RECOMP_FUNC void func_80094958(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80094958: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x8009495C: sw          $s5, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r21;
    // 0x80094960: addu        $s5, $zero, $zero
    ctx->r21 = ADD32(0, 0);
    // 0x80094964: sw          $s4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r20;
    // 0x80094968: addu        $s4, $zero, $zero
    ctx->r20 = ADD32(0, 0);
    // 0x8009496C: sw          $s3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r19;
    // 0x80094970: addiu       $s3, $zero, -0x1
    ctx->r19 = ADD32(0, -0X1);
    // 0x80094974: sw          $s1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r17;
    // 0x80094978: addu        $s1, $zero, $zero
    ctx->r17 = ADD32(0, 0);
    // 0x8009497C: sw          $ra, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r31;
    // 0x80094980: sw          $s2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r18;
    // 0x80094984: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
L_80094988:
    // 0x80094988: lui         $v0, 0x8015
    ctx->r2 = S32(0X8015 << 16);
    // 0x8009498C: lw          $v0, 0x29C0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X29C0);
    // 0x80094990: addu        $v1, $v0, $s1
    ctx->r3 = ADD32(ctx->r2, ctx->r17);
    // 0x80094994: lw          $v0, 0x570($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X570);
    // 0x80094998: beql        $v0, $zero, L_80094D7C
    if (ctx->r2 == 0) {
        // 0x8009499C: addiu       $s4, $s4, 0x1
        ctx->r20 = ADD32(ctx->r20, 0X1);
            goto L_80094D7C;
    }
    goto skip_0;
    // 0x8009499C: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    skip_0:
    // 0x800949A0: lui         $v0, 0x8015
    ctx->r2 = S32(0X8015 << 16);
    // 0x800949A4: lw          $v0, -0x660C($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X660C);
    // 0x800949A8: lw          $v1, 0x570($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X570);
    // 0x800949AC: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800949B0: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x800949B4: sw          $v0, -0x660C($at)
    MEM_W(-0X660C, ctx->r1) = ctx->r2;
    // 0x800949B8: beq         $v1, $zero, L_80094D78
    if (ctx->r3 == 0) {
        // 0x800949BC: addiu       $s5, $zero, 0x1
        ctx->r21 = ADD32(0, 0X1);
            goto L_80094D78;
    }
    // 0x800949BC: addiu       $s5, $zero, 0x1
    ctx->r21 = ADD32(0, 0X1);
    // 0x800949C0: addu        $s2, $s1, $zero
    ctx->r18 = ADD32(ctx->r17, 0);
L_800949C4:
    // 0x800949C4: lui         $t0, 0x8015
    ctx->r8 = S32(0X8015 << 16);
    // 0x800949C8: lw          $t0, 0x29C0($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X29C0);
    // 0x800949CC: addu        $a2, $t0, $s1
    ctx->r6 = ADD32(ctx->r8, ctx->r17);
    // 0x800949D0: lw          $a1, 0x570($a2)
    ctx->r5 = MEM_W(ctx->r6, 0X570);
    // 0x800949D4: lw          $v0, 0x56C($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X56C);
    // 0x800949D8: lw          $v1, 0x120($t0)
    ctx->r3 = MEM_W(ctx->r8, 0X120);
    // 0x800949DC: lw          $a0, 0x0($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X0);
    // 0x800949E0: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800949E4: sltu        $v0, $v0, $a0
    ctx->r2 = ctx->r2 < ctx->r4 ? 1 : 0;
    // 0x800949E8: bnel        $v0, $zero, L_80094D7C
    if (ctx->r2 != 0) {
        // 0x800949EC: addiu       $s4, $s4, 0x1
        ctx->r20 = ADD32(ctx->r20, 0X1);
            goto L_80094D7C;
    }
    goto skip_1;
    // 0x800949EC: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    skip_1:
    // 0x800949F0: lbu         $a3, 0x6($a1)
    ctx->r7 = MEM_BU(ctx->r5, 0X6);
    // 0x800949F4: lbu         $t1, 0x7($a1)
    ctx->r9 = MEM_BU(ctx->r5, 0X7);
    // 0x800949F8: lbu         $a1, 0x588($a2)
    ctx->r5 = MEM_BU(ctx->r6, 0X588);
    // 0x800949FC: xori        $v1, $a3, 0xFF
    ctx->r3 = ctx->r7 ^ 0XFF;
    // 0x80094A00: sltiu       $v1, $v1, 0x1
    ctx->r3 = ctx->r3 < 0X1 ? 1 : 0;
    // 0x80094A04: xori        $v0, $t1, 0xFF
    ctx->r2 = ctx->r9 ^ 0XFF;
    // 0x80094A08: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80094A0C: and         $v1, $v1, $v0
    ctx->r3 = ctx->r3 & ctx->r2;
    // 0x80094A10: beq         $v1, $zero, L_80094A20
    if (ctx->r3 == 0) {
        // 0x80094A14: srl         $v0, $a3, 7
        ctx->r2 = S32(U32(ctx->r7) >> 7);
            goto L_80094A20;
    }
    // 0x80094A14: srl         $v0, $a3, 7
    ctx->r2 = S32(U32(ctx->r7) >> 7);
    // 0x80094A18: j           L_80094D60
    // 0x80094A1C: sw          $zero, 0x570($a2)
    MEM_W(0X570, ctx->r6) = 0;
        goto L_80094D60;
    // 0x80094A1C: sw          $zero, 0x570($a2)
    MEM_W(0X570, ctx->r6) = 0;
L_80094A20:
    // 0x80094A20: andi        $v1, $v0, 0x1
    ctx->r3 = ctx->r2 & 0X1;
    // 0x80094A24: sltiu       $v0, $t1, 0x1
    ctx->r2 = ctx->r9 < 0X1 ? 1 : 0;
    // 0x80094A28: and         $v0, $v1, $v0
    ctx->r2 = ctx->r3 & ctx->r2;
    // 0x80094A2C: beq         $v0, $zero, L_80094ACC
    if (ctx->r2 == 0) {
        // 0x80094A30: andi        $a0, $a3, 0x7F
        ctx->r4 = ctx->r7 & 0X7F;
            goto L_80094ACC;
    }
    // 0x80094A30: andi        $a0, $a3, 0x7F
    ctx->r4 = ctx->r7 & 0X7F;
    // 0x80094A34: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    // 0x80094A38: addiu       $v0, $zero, 0x9
    ctx->r2 = ADD32(0, 0X9);
    // 0x80094A3C: beq         $a1, $v0, L_80094A8C
    if (ctx->r5 == ctx->r2) {
        // 0x80094A40: addu        $v1, $a0, $zero
        ctx->r3 = ADD32(ctx->r4, 0);
            goto L_80094A8C;
    }
    // 0x80094A40: addu        $v1, $a0, $zero
    ctx->r3 = ADD32(ctx->r4, 0);
    // 0x80094A44: addu        $v0, $v1, $t0
    ctx->r2 = ADD32(ctx->r3, ctx->r8);
    // 0x80094A48: lbu         $a0, 0x8($v0)
    ctx->r4 = MEM_BU(ctx->r2, 0X8);
    // 0x80094A4C: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // 0x80094A50: beq         $a0, $v0, L_80094D48
    if (ctx->r4 == ctx->r2) {
        // 0x80094A54: sll         $a1, $a1, 2
        ctx->r5 = S32(ctx->r5 << 2);
            goto L_80094D48;
    }
    // 0x80094A54: sll         $a1, $a1, 2
    ctx->r5 = S32(ctx->r5 << 2);
    // 0x80094A58: lw          $v1, 0x4($t0)
    ctx->r3 = MEM_W(ctx->r8, 0X4);
    // 0x80094A5C: sll         $v0, $a0, 3
    ctx->r2 = S32(ctx->r4 << 3);
    // 0x80094A60: addu        $a1, $a1, $t0
    ctx->r5 = ADD32(ctx->r5, ctx->r8);
    // 0x80094A64: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80094A68: lhu         $v1, 0x0($v0)
    ctx->r3 = MEM_HU(ctx->r2, 0X0);
    // 0x80094A6C: lbu         $a0, 0x2($v0)
    ctx->r4 = MEM_BU(ctx->r2, 0X2);
    // 0x80094A70: lbu         $v0, 0x3($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X3);
    // 0x80094A74: sll         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3 << 16);
    // 0x80094A78: sll         $a0, $a0, 8
    ctx->r4 = S32(ctx->r4 << 8);
    // 0x80094A7C: or          $v1, $v1, $a0
    ctx->r3 = ctx->r3 | ctx->r4;
    // 0x80094A80: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x80094A84: j           L_80094D48
    // 0x80094A88: sw          $v1, 0xE80($a1)
    MEM_W(0XE80, ctx->r5) = ctx->r3;
        goto L_80094D48;
    // 0x80094A88: sw          $v1, 0xE80($a1)
    MEM_W(0XE80, ctx->r5) = ctx->r3;
L_80094A8C:
    // 0x80094A8C: addu        $v0, $a0, $t0
    ctx->r2 = ADD32(ctx->r4, ctx->r8);
    // 0x80094A90: lbu         $a0, 0x8C($v0)
    ctx->r4 = MEM_BU(ctx->r2, 0X8C);
    // 0x80094A94: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // 0x80094A98: beq         $a0, $v0, L_80094D48
    if (ctx->r4 == ctx->r2) {
        // 0x80094A9C: sll         $v0, $a0, 3
        ctx->r2 = S32(ctx->r4 << 3);
            goto L_80094D48;
    }
    // 0x80094A9C: sll         $v0, $a0, 3
    ctx->r2 = S32(ctx->r4 << 3);
    // 0x80094AA0: lw          $v1, 0x88($t0)
    ctx->r3 = MEM_W(ctx->r8, 0X88);
    // 0x80094AA4: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80094AA8: lhu         $v1, 0x0($v0)
    ctx->r3 = MEM_HU(ctx->r2, 0X0);
    // 0x80094AAC: lbu         $a0, 0x2($v0)
    ctx->r4 = MEM_BU(ctx->r2, 0X2);
    // 0x80094AB0: lbu         $v0, 0x3($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X3);
    // 0x80094AB4: sll         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3 << 16);
    // 0x80094AB8: sll         $a0, $a0, 8
    ctx->r4 = S32(ctx->r4 << 8);
    // 0x80094ABC: or          $v1, $v1, $a0
    ctx->r3 = ctx->r3 | ctx->r4;
    // 0x80094AC0: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x80094AC4: j           L_80094D48
    // 0x80094AC8: sw          $v1, 0xEA4($t0)
    MEM_W(0XEA4, ctx->r8) = ctx->r3;
        goto L_80094D48;
    // 0x80094AC8: sw          $v1, 0xEA4($t0)
    MEM_W(0XEA4, ctx->r8) = ctx->r3;
L_80094ACC:
    // 0x80094ACC: xori        $v0, $t1, 0x1
    ctx->r2 = ctx->r9 ^ 0X1;
    // 0x80094AD0: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80094AD4: and         $v0, $v1, $v0
    ctx->r2 = ctx->r3 & ctx->r2;
    // 0x80094AD8: bne         $v0, $zero, L_80094B2C
    if (ctx->r2 != 0) {
        // 0x80094ADC: addiu       $a0, $zero, 0x82
        ctx->r4 = ADD32(0, 0X82);
            goto L_80094B2C;
    }
    // 0x80094ADC: addiu       $a0, $zero, 0x82
    ctx->r4 = ADD32(0, 0X82);
    // 0x80094AE0: andi        $v0, $a3, 0x80
    ctx->r2 = ctx->r7 & 0X80;
    // 0x80094AE4: beq         $v0, $zero, L_80094B44
    if (ctx->r2 == 0) {
        // 0x80094AE8: nop
    
            goto L_80094B44;
    }
    // 0x80094AE8: nop

    // 0x80094AEC: andi        $v0, $t1, 0x80
    ctx->r2 = ctx->r9 & 0X80;
    // 0x80094AF0: beq         $v0, $zero, L_80094B44
    if (ctx->r2 == 0) {
        // 0x80094AF4: andi        $a0, $t1, 0x7F
        ctx->r4 = ctx->r9 & 0X7F;
            goto L_80094B44;
    }
    // 0x80094AF4: andi        $a0, $t1, 0x7F
    ctx->r4 = ctx->r9 & 0X7F;
    // 0x80094AF8: addiu       $v0, $zero, 0x68
    ctx->r2 = ADD32(0, 0X68);
    // 0x80094AFC: bne         $a0, $v0, L_80094B2C
    if (ctx->r4 != ctx->r2) {
        // 0x80094B00: nop
    
            goto L_80094B2C;
    }
    // 0x80094B00: nop

    // 0x80094B04: lbu         $v0, 0xEF4($t0)
    ctx->r2 = MEM_BU(ctx->r8, 0XEF4);
    // 0x80094B08: beq         $v0, $zero, L_80094D48
    if (ctx->r2 == 0) {
        // 0x80094B0C: addiu       $a0, $t0, 0xEC8
        ctx->r4 = ADD32(ctx->r8, 0XEC8);
            goto L_80094D48;
    }
    // 0x80094B0C: addiu       $a0, $t0, 0xEC8
    ctx->r4 = ADD32(ctx->r8, 0XEC8);
    // 0x80094B10: lw          $a1, 0xEF0($t0)
    ctx->r5 = MEM_W(ctx->r8, 0XEF0);
    // 0x80094B14: jal         0x800966A4
    // 0x80094B18: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_800966A4(rdram, ctx);
        goto after_0;
    // 0x80094B18: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_0:
    // 0x80094B1C: lui         $v0, 0x8015
    ctx->r2 = S32(0X8015 << 16);
    // 0x80094B20: lw          $v0, 0x29C0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X29C0);
    // 0x80094B24: j           L_80094D48
    // 0x80094B28: sb          $zero, 0xEF4($v0)
    MEM_B(0XEF4, ctx->r2) = 0;
        goto L_80094D48;
    // 0x80094B28: sb          $zero, 0xEF4($v0)
    MEM_B(0XEF4, ctx->r2) = 0;
L_80094B2C:
    // 0x80094B2C: lui         $a2, 0x8015
    ctx->r6 = S32(0X8015 << 16);
    // 0x80094B30: lbu         $a2, 0x29CB($a2)
    ctx->r6 = MEM_BU(ctx->r6, 0X29CB);
    // 0x80094B34: jal         0x80083D9C
    // 0x80094B38: andi        $a3, $a3, 0x7F
    ctx->r7 = ctx->r7 & 0X7F;
    func_80083D9C(rdram, ctx);
        goto after_1;
    // 0x80094B38: andi        $a3, $a3, 0x7F
    ctx->r7 = ctx->r7 & 0X7F;
    after_1:
    // 0x80094B3C: j           L_80094D48
    // 0x80094B40: nop

        goto L_80094D48;
    // 0x80094B40: nop

L_80094B44:
    // 0x80094B44: lui         $a2, 0x8015
    ctx->r6 = S32(0X8015 << 16);
    // 0x80094B48: lw          $a2, 0x29C0($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X29C0);
    // 0x80094B4C: addu        $t0, $a2, $s2
    ctx->r8 = ADD32(ctx->r6, ctx->r18);
    // 0x80094B50: lbu         $t2, 0x58B($t0)
    ctx->r10 = MEM_BU(ctx->r8, 0X58B);
    // 0x80094B54: bgez        $t2, L_80094B60
    if (SIGNED(ctx->r10) >= 0) {
        // 0x80094B58: addu        $v0, $t2, $zero
        ctx->r2 = ADD32(ctx->r10, 0);
            goto L_80094B60;
    }
    // 0x80094B58: addu        $v0, $t2, $zero
    ctx->r2 = ADD32(ctx->r10, 0);
    // 0x80094B5C: addiu       $v0, $t2, 0x1F
    ctx->r2 = ADD32(ctx->r10, 0X1F);
L_80094B60:
    // 0x80094B60: sra         $v0, $v0, 5
    ctx->r2 = S32(SIGNED(ctx->r2) >> 5);
    // 0x80094B64: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80094B68: addu        $v0, $v0, $a2
    ctx->r2 = ADD32(ctx->r2, ctx->r6);
    // 0x80094B6C: andi        $a0, $t2, 0x1F
    ctx->r4 = ctx->r10 & 0X1F;
    // 0x80094B70: lw          $v1, 0x110($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X110);
    // 0x80094B74: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80094B78: sllv        $v0, $v0, $a0
    ctx->r2 = S32(ctx->r2 << (ctx->r4 & 31));
    // 0x80094B7C: and         $v1, $v1, $v0
    ctx->r3 = ctx->r3 & ctx->r2;
    // 0x80094B80: beq         $v1, $zero, L_80094D48
    if (ctx->r3 == 0) {
        // 0x80094B84: sll         $v0, $a1, 2
        ctx->r2 = S32(ctx->r5 << 2);
            goto L_80094D48;
    }
    // 0x80094B84: sll         $v0, $a1, 2
    ctx->r2 = S32(ctx->r5 << 2);
    // 0x80094B88: addu        $v0, $v0, $a2
    ctx->r2 = ADD32(ctx->r2, ctx->r6);
    // 0x80094B8C: lw          $t3, 0xE80($v0)
    ctx->r11 = MEM_W(ctx->r2, 0XE80);
    // 0x80094B90: beq         $t3, $s3, L_80094D48
    if (ctx->r11 == ctx->r19) {
        // 0x80094B94: nop
    
            goto L_80094D48;
    }
    // 0x80094B94: nop

    // 0x80094B98: lb          $v0, 0x58A($t0)
    ctx->r2 = MEM_B(ctx->r8, 0X58A);
    // 0x80094B9C: addu        $a3, $a3, $v0
    ctx->r7 = ADD32(ctx->r7, ctx->r2);
    // 0x80094BA0: slti        $v0, $a3, 0x80
    ctx->r2 = SIGNED(ctx->r7) < 0X80 ? 1 : 0;
    // 0x80094BA4: beq         $v0, $zero, L_80094BB8
    if (ctx->r2 == 0) {
        // 0x80094BA8: nor         $v0, $zero, $a3
        ctx->r2 = ~(0 | ctx->r7);
            goto L_80094BB8;
    }
    // 0x80094BA8: nor         $v0, $zero, $a3
    ctx->r2 = ~(0 | ctx->r7);
    // 0x80094BAC: sra         $v0, $v0, 31
    ctx->r2 = S32(SIGNED(ctx->r2) >> 31);
    // 0x80094BB0: j           L_80094BBC
    // 0x80094BB4: and         $v1, $a3, $v0
    ctx->r3 = ctx->r7 & ctx->r2;
        goto L_80094BBC;
    // 0x80094BB4: and         $v1, $a3, $v0
    ctx->r3 = ctx->r7 & ctx->r2;
L_80094BB8:
    // 0x80094BB8: addiu       $v1, $zero, 0x7F
    ctx->r3 = ADD32(0, 0X7F);
L_80094BBC:
    // 0x80094BBC: lui         $v0, 0x8015
    ctx->r2 = S32(0X8015 << 16);
    // 0x80094BC0: lw          $v0, 0x29C0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X29C0);
    // 0x80094BC4: addu        $v0, $v0, $s2
    ctx->r2 = ADD32(ctx->r2, ctx->r18);
    // 0x80094BC8: lb          $v0, 0x589($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X589);
    // 0x80094BCC: addu        $t1, $t1, $v0
    ctx->r9 = ADD32(ctx->r9, ctx->r2);
    // 0x80094BD0: slti        $v0, $t1, 0x80
    ctx->r2 = SIGNED(ctx->r9) < 0X80 ? 1 : 0;
    // 0x80094BD4: beq         $v0, $zero, L_80094BEC
    if (ctx->r2 == 0) {
        // 0x80094BD8: addu        $a3, $v1, $zero
        ctx->r7 = ADD32(ctx->r3, 0);
            goto L_80094BEC;
    }
    // 0x80094BD8: addu        $a3, $v1, $zero
    ctx->r7 = ADD32(ctx->r3, 0);
    // 0x80094BDC: nor         $v0, $zero, $t1
    ctx->r2 = ~(0 | ctx->r9);
    // 0x80094BE0: sra         $v0, $v0, 31
    ctx->r2 = S32(SIGNED(ctx->r2) >> 31);
    // 0x80094BE4: j           L_80094BF0
    // 0x80094BE8: and         $v0, $t1, $v0
    ctx->r2 = ctx->r9 & ctx->r2;
        goto L_80094BF0;
    // 0x80094BE8: and         $v0, $t1, $v0
    ctx->r2 = ctx->r9 & ctx->r2;
L_80094BEC:
    // 0x80094BEC: addiu       $v0, $zero, 0x7F
    ctx->r2 = ADD32(0, 0X7F);
L_80094BF0:
    // 0x80094BF0: lui         $v1, 0x8015
    ctx->r3 = S32(0X8015 << 16);
    // 0x80094BF4: lw          $v1, 0x29C4($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X29C4);
    // 0x80094BF8: beq         $v1, $zero, L_80094C40
    if (ctx->r3 == 0) {
        // 0x80094BFC: addu        $t1, $v0, $zero
        ctx->r9 = ADD32(ctx->r2, 0);
            goto L_80094C40;
    }
    // 0x80094BFC: addu        $t1, $v0, $zero
    ctx->r9 = ADD32(ctx->r2, 0);
    // 0x80094C00: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80094C04: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80094C08: sw          $v0, 0x29C4($at)
    MEM_W(0X29C4, ctx->r1) = ctx->r2;
    // 0x80094C0C: bnel        $v0, $zero, L_80094C14
    if (ctx->r2 != 0) {
        // 0x80094C10: sw          $zero, 0x4($v0)
        MEM_W(0X4, ctx->r2) = 0;
            goto L_80094C14;
    }
    goto skip_2;
    // 0x80094C10: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    skip_2:
L_80094C14:
    // 0x80094C14: lui         $a0, 0x8015
    ctx->r4 = S32(0X8015 << 16);
    // 0x80094C18: lw          $a0, 0x29C0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X29C0);
    // 0x80094C1C: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x80094C20: lw          $v0, 0xE78($a0)
    ctx->r2 = MEM_W(ctx->r4, 0XE78);
    // 0x80094C24: beq         $v0, $zero, L_80094C34
    if (ctx->r2 == 0) {
        // 0x80094C28: sw          $v0, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->r2;
            goto L_80094C34;
    }
    // 0x80094C28: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x80094C2C: lw          $v0, 0xE78($a0)
    ctx->r2 = MEM_W(ctx->r4, 0XE78);
    // 0x80094C30: sw          $v1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r3;
L_80094C34:
    // 0x80094C34: lui         $v0, 0x8015
    ctx->r2 = S32(0X8015 << 16);
    // 0x80094C38: lw          $v0, 0x29C0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X29C0);
    // 0x80094C3C: sw          $v1, 0xE78($v0)
    MEM_W(0XE78, ctx->r2) = ctx->r3;
L_80094C40:
    // 0x80094C40: addu        $s0, $v1, $zero
    ctx->r16 = ADD32(ctx->r3, 0);
    // 0x80094C44: beq         $s0, $zero, L_80094D48
    if (ctx->r16 == 0) {
        // 0x80094C48: nop
    
            goto L_80094D48;
    }
    // 0x80094C48: nop

    // 0x80094C4C: lui         $v1, 0x8015
    ctx->r3 = S32(0X8015 << 16);
    // 0x80094C50: lbu         $v1, 0x29CB($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X29CB);
    // 0x80094C54: lui         $v0, 0x8015
    ctx->r2 = S32(0X8015 << 16);
    // 0x80094C58: lw          $v0, 0x29C0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X29C0);
    // 0x80094C5C: sw          $a1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r5;
    // 0x80094C60: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x80094C64: sw          $t2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r10;
    // 0x80094C68: addu        $v0, $v0, $t2
    ctx->r2 = ADD32(ctx->r2, ctx->r10);
    // 0x80094C6C: sw          $v1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r3;
    // 0x80094C70: lbu         $v0, 0x528($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X528);
    // 0x80094C74: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x80094C78: lui         $v0, 0x8015
    ctx->r2 = S32(0X8015 << 16);
    // 0x80094C7C: lbu         $v0, -0x6608($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X6608);
    // 0x80094C80: andi        $a1, $a3, 0xFF
    ctx->r5 = ctx->r7 & 0XFF;
    // 0x80094C84: beq         $v0, $zero, L_80094C94
    if (ctx->r2 == 0) {
        // 0x80094C88: andi        $a2, $t1, 0xFF
        ctx->r6 = ctx->r9 & 0XFF;
            goto L_80094C94;
    }
    // 0x80094C88: andi        $a2, $t1, 0xFF
    ctx->r6 = ctx->r9 & 0XFF;
    // 0x80094C8C: j           L_80094C98
    // 0x80094C90: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
        goto L_80094C98;
    // 0x80094C90: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
L_80094C94:
    // 0x80094C94: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
L_80094C98:
    // 0x80094C98: addu        $a0, $t3, $zero
    ctx->r4 = ADD32(ctx->r11, 0);
    // 0x80094C9C: jal         0x800878D0
    // 0x80094CA0: addiu       $a3, $zero, 0x40
    ctx->r7 = ADD32(0, 0X40);
    func_800878D0(rdram, ctx);
        goto after_2;
    // 0x80094CA0: addiu       $a3, $zero, 0x40
    ctx->r7 = ADD32(0, 0X40);
    after_2:
    // 0x80094CA4: addu        $t3, $v0, $zero
    ctx->r11 = ADD32(ctx->r2, 0);
    // 0x80094CA8: beq         $t3, $s3, L_80094CEC
    if (ctx->r11 == ctx->r19) {
        // 0x80094CAC: nop
    
            goto L_80094CEC;
    }
    // 0x80094CAC: nop

    // 0x80094CB0: lui         $a0, 0x8015
    ctx->r4 = S32(0X8015 << 16);
    // 0x80094CB4: lw          $a0, 0x29C0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X29C0);
    // 0x80094CB8: sw          $t3, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r11;
    // 0x80094CBC: addu        $a0, $a0, $s2
    ctx->r4 = ADD32(ctx->r4, ctx->r18);
    // 0x80094CC0: lw          $v0, 0x570($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X570);
    // 0x80094CC4: lhu         $v1, 0x4($v0)
    ctx->r3 = MEM_HU(ctx->r2, 0X4);
    // 0x80094CC8: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x80094CCC: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80094CD0: sw          $v0, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r2;
    // 0x80094CD4: lw          $v0, 0x568($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X568);
    // 0x80094CD8: lw          $v1, 0x56C($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X56C);
    // 0x80094CDC: sw          $v0, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->r2;
    // 0x80094CE0: sw          $v1, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->r3;
    // 0x80094CE4: j           L_80094D48
    // 0x80094CE8: nop

        goto L_80094D48;
    // 0x80094CE8: nop

L_80094CEC:
    // 0x80094CEC: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x80094CF0: beq         $v1, $zero, L_80094D00
    if (ctx->r3 == 0) {
        // 0x80094CF4: nop
    
            goto L_80094D00;
    }
    // 0x80094CF4: nop

    // 0x80094CF8: lw          $v0, 0x4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X4);
    // 0x80094CFC: sw          $v0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r2;
L_80094D00:
    // 0x80094D00: lw          $v1, 0x4($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X4);
    // 0x80094D04: beq         $v1, $zero, L_80094D18
    if (ctx->r3 == 0) {
        // 0x80094D08: nop
    
            goto L_80094D18;
    }
    // 0x80094D08: nop

    // 0x80094D0C: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80094D10: j           L_80094D28
    // 0x80094D14: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
        goto L_80094D28;
    // 0x80094D14: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
L_80094D18:
    // 0x80094D18: lui         $v1, 0x8015
    ctx->r3 = S32(0X8015 << 16);
    // 0x80094D1C: lw          $v1, 0x29C0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X29C0);
    // 0x80094D20: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80094D24: sw          $v0, 0xE78($v1)
    MEM_W(0XE78, ctx->r3) = ctx->r2;
L_80094D28:
    // 0x80094D28: lui         $v0, 0x8015
    ctx->r2 = S32(0X8015 << 16);
    // 0x80094D2C: lw          $v0, 0x29C4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X29C4);
    // 0x80094D30: beq         $v0, $zero, L_80094D3C
    if (ctx->r2 == 0) {
        // 0x80094D34: sw          $v0, 0x0($s0)
        MEM_W(0X0, ctx->r16) = ctx->r2;
            goto L_80094D3C;
    }
    // 0x80094D34: sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
    // 0x80094D38: sw          $s0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r16;
L_80094D3C:
    // 0x80094D3C: sw          $zero, 0x4($s0)
    MEM_W(0X4, ctx->r16) = 0;
    // 0x80094D40: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80094D44: sw          $s0, 0x29C4($at)
    MEM_W(0X29C4, ctx->r1) = ctx->r16;
L_80094D48:
    // 0x80094D48: lui         $v1, 0x8015
    ctx->r3 = S32(0X8015 << 16);
    // 0x80094D4C: lw          $v1, 0x29C0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X29C0);
    // 0x80094D50: addu        $v1, $v1, $s2
    ctx->r3 = ADD32(ctx->r3, ctx->r18);
    // 0x80094D54: lw          $v0, 0x570($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X570);
    // 0x80094D58: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x80094D5C: sw          $v0, 0x570($v1)
    MEM_W(0X570, ctx->r3) = ctx->r2;
L_80094D60:
    // 0x80094D60: lui         $v0, 0x8015
    ctx->r2 = S32(0X8015 << 16);
    // 0x80094D64: lw          $v0, 0x29C0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X29C0);
    // 0x80094D68: addu        $v0, $v0, $s1
    ctx->r2 = ADD32(ctx->r2, ctx->r17);
    // 0x80094D6C: lw          $v0, 0x570($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X570);
    // 0x80094D70: bne         $v0, $zero, L_800949C4
    if (ctx->r2 != 0) {
        // 0x80094D74: nop
    
            goto L_800949C4;
    }
    // 0x80094D74: nop

L_80094D78:
    // 0x80094D78: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
L_80094D7C:
    // 0x80094D7C: slti        $v0, $s4, 0x40
    ctx->r2 = SIGNED(ctx->r20) < 0X40 ? 1 : 0;
    // 0x80094D80: bne         $v0, $zero, L_80094988
    if (ctx->r2 != 0) {
        // 0x80094D84: addiu       $s1, $s1, 0x24
        ctx->r17 = ADD32(ctx->r17, 0X24);
            goto L_80094988;
    }
    // 0x80094D84: addiu       $s1, $s1, 0x24
    ctx->r17 = ADD32(ctx->r17, 0X24);
    // 0x80094D88: addu        $v0, $s5, $zero
    ctx->r2 = ADD32(ctx->r21, 0);
    // 0x80094D8C: lw          $ra, 0x40($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X40);
    // 0x80094D90: lw          $s5, 0x3C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X3C);
    // 0x80094D94: lw          $s4, 0x38($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X38);
    // 0x80094D98: lw          $s3, 0x34($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X34);
    // 0x80094D9C: lw          $s2, 0x30($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X30);
    // 0x80094DA0: lw          $s1, 0x2C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X2C);
    // 0x80094DA4: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x80094DA8: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x80094DAC: jr          $ra
    // 0x80094DB0: nop

    return;
    // 0x80094DB0: nop

;}
RECOMP_FUNC void func_80094DB4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80094DB4: lui         $v0, 0x8015
    ctx->r2 = S32(0X8015 << 16);
    // 0x80094DB8: lw          $v0, 0x29C0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X29C0);
    // 0x80094DBC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80094DC0: sw          $ra, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r31;
    // 0x80094DC4: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x80094DC8: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x80094DCC: lw          $v0, 0xE78($v0)
    ctx->r2 = MEM_W(ctx->r2, 0XE78);
    // 0x80094DD0: bne         $v0, $zero, L_80094DE0
    if (ctx->r2 != 0) {
        // 0x80094DD4: addu        $s0, $v0, $zero
        ctx->r16 = ADD32(ctx->r2, 0);
            goto L_80094DE0;
    }
    // 0x80094DD4: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    // 0x80094DD8: j           L_80094ECC
    // 0x80094DDC: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
        goto L_80094ECC;
    // 0x80094DDC: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_80094DE0:
    // 0x80094DE0: lui         $v0, 0x8015
    ctx->r2 = S32(0X8015 << 16);
    // 0x80094DE4: lw          $v0, -0x6604($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X6604);
    // 0x80094DE8: lui         $a1, 0x8015
    ctx->r5 = S32(0X8015 << 16);
    // 0x80094DEC: lw          $a1, 0x29C0($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X29C0);
    // 0x80094DF0: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80094DF4: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80094DF8: sw          $v0, -0x6604($at)
    MEM_W(-0X6604, ctx->r1) = ctx->r2;
    // 0x80094DFC: lw          $v0, 0x14($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X14);
    // 0x80094E00: lw          $v1, 0x120($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X120);
    // 0x80094E04: lw          $a0, 0xC($s0)
    ctx->r4 = MEM_W(ctx->r16, 0XC);
    // 0x80094E08: lw          $s1, 0x0($s0)
    ctx->r17 = MEM_W(ctx->r16, 0X0);
    // 0x80094E0C: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80094E10: slt         $v0, $v0, $a0
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x80094E14: bne         $v0, $zero, L_80094E94
    if (ctx->r2 != 0) {
        // 0x80094E18: nop
    
            goto L_80094E94;
    }
    // 0x80094E18: nop

    // 0x80094E1C: lw          $a0, 0x8($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X8);
    // 0x80094E20: jal         0x80089414
    // 0x80094E24: nop

    func_80089414(rdram, ctx);
        goto after_0;
    // 0x80094E24: nop

    after_0:
    // 0x80094E28: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x80094E2C: beq         $v1, $zero, L_80094E3C
    if (ctx->r3 == 0) {
        // 0x80094E30: nop
    
            goto L_80094E3C;
    }
    // 0x80094E30: nop

    // 0x80094E34: lw          $v0, 0x4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X4);
    // 0x80094E38: sw          $v0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r2;
L_80094E3C:
    // 0x80094E3C: lw          $v1, 0x4($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X4);
    // 0x80094E40: beq         $v1, $zero, L_80094E54
    if (ctx->r3 == 0) {
        // 0x80094E44: nop
    
            goto L_80094E54;
    }
    // 0x80094E44: nop

    // 0x80094E48: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80094E4C: j           L_80094E64
    // 0x80094E50: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
        goto L_80094E64;
    // 0x80094E50: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
L_80094E54:
    // 0x80094E54: lui         $v1, 0x8015
    ctx->r3 = S32(0X8015 << 16);
    // 0x80094E58: lw          $v1, 0x29C0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X29C0);
    // 0x80094E5C: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80094E60: sw          $v0, 0xE78($v1)
    MEM_W(0XE78, ctx->r3) = ctx->r2;
L_80094E64:
    // 0x80094E64: lui         $v1, 0x8015
    ctx->r3 = S32(0X8015 << 16);
    // 0x80094E68: lw          $v1, 0x29C0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X29C0);
    // 0x80094E6C: lw          $v0, 0xE7C($v1)
    ctx->r2 = MEM_W(ctx->r3, 0XE7C);
    // 0x80094E70: beq         $v0, $zero, L_80094E80
    if (ctx->r2 == 0) {
        // 0x80094E74: sw          $v0, 0x0($s0)
        MEM_W(0X0, ctx->r16) = ctx->r2;
            goto L_80094E80;
    }
    // 0x80094E74: sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
    // 0x80094E78: lw          $v0, 0xE7C($v1)
    ctx->r2 = MEM_W(ctx->r3, 0XE7C);
    // 0x80094E7C: sw          $s0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r16;
L_80094E80:
    // 0x80094E80: lui         $v0, 0x8015
    ctx->r2 = S32(0X8015 << 16);
    // 0x80094E84: lw          $v0, 0x29C0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X29C0);
    // 0x80094E88: sw          $zero, 0x4($s0)
    MEM_W(0X4, ctx->r16) = 0;
    // 0x80094E8C: j           L_80094EC0
    // 0x80094E90: sw          $s0, 0xE7C($v0)
    MEM_W(0XE7C, ctx->r2) = ctx->r16;
        goto L_80094EC0;
    // 0x80094E90: sw          $s0, 0xE7C($v0)
    MEM_W(0XE7C, ctx->r2) = ctx->r16;
L_80094E94:
    // 0x80094E94: lw          $v0, 0x10($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X10);
    // 0x80094E98: lw          $v1, 0x118($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X118);
    // 0x80094E9C: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80094EA0: andi        $v1, $v0, 0xFFFF
    ctx->r3 = ctx->r2 & 0XFFFF;
    // 0x80094EA4: sw          $v1, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->r3;
    // 0x80094EA8: lw          $a0, 0x11C($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X11C);
    // 0x80094EAC: lw          $v1, 0x14($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X14);
    // 0x80094EB0: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x80094EB4: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x80094EB8: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x80094EBC: sw          $v1, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->r3;
L_80094EC0:
    // 0x80094EC0: addu        $s0, $s1, $zero
    ctx->r16 = ADD32(ctx->r17, 0);
    // 0x80094EC4: bne         $s0, $zero, L_80094DE0
    if (ctx->r16 != 0) {
        // 0x80094EC8: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80094DE0;
    }
    // 0x80094EC8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80094ECC:
    // 0x80094ECC: lw          $ra, 0x18($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X18);
    // 0x80094ED0: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x80094ED4: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x80094ED8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80094EDC: jr          $ra
    // 0x80094EE0: nop

    return;
    // 0x80094EE0: nop

;}
RECOMP_FUNC void func_80094EE4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80094EE4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80094EE8: sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // 0x80094EEC: addu        $s2, $zero, $zero
    ctx->r18 = ADD32(0, 0);
    // 0x80094EF0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80094EF4: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x80094EF8: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
L_80094EFC:
    // 0x80094EFC: lui         $v0, 0x8015
    ctx->r2 = S32(0X8015 << 16);
    // 0x80094F00: lw          $v0, 0x29C0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X29C0);
    // 0x80094F04: addu        $v0, $v0, $s2
    ctx->r2 = ADD32(ctx->r2, ctx->r18);
    // 0x80094F08: lw          $v0, 0x574($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X574);
    // 0x80094F0C: beql        $v0, $zero, L_80095068
    if (ctx->r2 == 0) {
        // 0x80094F10: addiu       $s2, $s2, 0x24
        ctx->r18 = ADD32(ctx->r18, 0X24);
            goto L_80095068;
    }
    goto skip_0;
    // 0x80094F10: addiu       $s2, $s2, 0x24
    ctx->r18 = ADD32(ctx->r18, 0X24);
    skip_0:
    // 0x80094F14: addu        $s1, $zero, $zero
    ctx->r17 = ADD32(0, 0);
    // 0x80094F18: addu        $s0, $s2, $zero
    ctx->r16 = ADD32(ctx->r18, 0);
L_80094F1C:
    // 0x80094F1C: lui         $v0, 0x8015
    ctx->r2 = S32(0X8015 << 16);
    // 0x80094F20: lw          $v0, 0x29C0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X29C0);
    // 0x80094F24: addu        $a1, $v0, $s0
    ctx->r5 = ADD32(ctx->r2, ctx->r16);
    // 0x80094F28: lw          $v0, 0x574($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X574);
    // 0x80094F2C: lbu         $a0, 0x0($v0)
    ctx->r4 = MEM_BU(ctx->r2, 0X0);
    // 0x80094F30: lbu         $a2, 0x1($v0)
    ctx->r6 = MEM_BU(ctx->r2, 0X1);
    // 0x80094F34: xori        $v0, $a0, 0x80
    ctx->r2 = ctx->r4 ^ 0X80;
    // 0x80094F38: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80094F3C: sltiu       $v1, $a2, 0x1
    ctx->r3 = ctx->r6 < 0X1 ? 1 : 0;
    // 0x80094F40: and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // 0x80094F44: beq         $v0, $zero, L_80094F54
    if (ctx->r2 == 0) {
        // 0x80094F48: andi        $v0, $a0, 0x80
        ctx->r2 = ctx->r4 & 0X80;
            goto L_80094F54;
    }
    // 0x80094F48: andi        $v0, $a0, 0x80
    ctx->r2 = ctx->r4 & 0X80;
    // 0x80094F4C: j           L_80095054
    // 0x80094F50: sw          $zero, 0x574($a1)
    MEM_W(0X574, ctx->r5) = 0;
        goto L_80095054;
    // 0x80094F50: sw          $zero, 0x574($a1)
    MEM_W(0X574, ctx->r5) = 0;
L_80094F54:
    // 0x80094F54: beq         $v0, $zero, L_80094F6C
    if (ctx->r2 == 0) {
        // 0x80094F58: andi        $v0, $a0, 0x7F
        ctx->r2 = ctx->r4 & 0X7F;
            goto L_80094F6C;
    }
    // 0x80094F58: andi        $v0, $a0, 0x7F
    ctx->r2 = ctx->r4 & 0X7F;
    // 0x80094F5C: sll         $v0, $v0, 8
    ctx->r2 = S32(ctx->r2 << 8);
    // 0x80094F60: or          $a2, $a2, $v0
    ctx->r6 = ctx->r6 | ctx->r2;
    // 0x80094F64: j           L_80094F74
    // 0x80094F68: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
        goto L_80094F74;
    // 0x80094F68: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
L_80094F6C:
    // 0x80094F6C: andi        $a2, $a0, 0xFF
    ctx->r6 = ctx->r4 & 0XFF;
    // 0x80094F70: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
L_80094F74:
    // 0x80094F74: lui         $v1, 0x8015
    ctx->r3 = S32(0X8015 << 16);
    // 0x80094F78: lw          $v1, 0x29C0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X29C0);
    // 0x80094F7C: addu        $a1, $v1, $s0
    ctx->r5 = ADD32(ctx->r3, ctx->r16);
    // 0x80094F80: lw          $a0, 0x580($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X580);
    // 0x80094F84: lw          $v0, 0x56C($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X56C);
    // 0x80094F88: lw          $v1, 0x120($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X120);
    // 0x80094F8C: addu        $a0, $a2, $a0
    ctx->r4 = ADD32(ctx->r6, ctx->r4);
    // 0x80094F90: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80094F94: sltu        $v0, $v0, $a0
    ctx->r2 = ctx->r2 < ctx->r4 ? 1 : 0;
    // 0x80094F98: bnel        $v0, $zero, L_80095058
    if (ctx->r2 != 0) {
        // 0x80094F9C: addiu       $s1, $zero, 0x1
        ctx->r17 = ADD32(0, 0X1);
            goto L_80095058;
    }
    goto skip_1;
    // 0x80094F9C: addiu       $s1, $zero, 0x1
    ctx->r17 = ADD32(0, 0X1);
    skip_1:
    // 0x80094FA0: lw          $v0, 0x574($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X574);
    // 0x80094FA4: addu        $v0, $v0, $a3
    ctx->r2 = ADD32(ctx->r2, ctx->r7);
    // 0x80094FA8: sw          $v0, 0x574($a1)
    MEM_W(0X574, ctx->r5) = ctx->r2;
    // 0x80094FAC: lw          $v1, 0x574($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X574);
    // 0x80094FB0: sw          $a0, 0x580($a1)
    MEM_W(0X580, ctx->r5) = ctx->r4;
    // 0x80094FB4: lbu         $a0, 0x0($v1)
    ctx->r4 = MEM_BU(ctx->r3, 0X0);
    // 0x80094FB8: lbu         $a2, 0x1($v1)
    ctx->r6 = MEM_BU(ctx->r3, 0X1);
    // 0x80094FBC: andi        $v0, $a0, 0x80
    ctx->r2 = ctx->r4 & 0X80;
    // 0x80094FC0: beq         $v0, $zero, L_80094FE0
    if (ctx->r2 == 0) {
        // 0x80094FC4: andi        $v0, $a0, 0x7F
        ctx->r2 = ctx->r4 & 0X7F;
            goto L_80094FE0;
    }
    // 0x80094FC4: andi        $v0, $a0, 0x7F
    ctx->r2 = ctx->r4 & 0X7F;
    // 0x80094FC8: sll         $v0, $v0, 8
    ctx->r2 = S32(ctx->r2 << 8);
    // 0x80094FCC: or          $v0, $a2, $v0
    ctx->r2 = ctx->r6 | ctx->r2;
    // 0x80094FD0: sll         $v0, $v0, 17
    ctx->r2 = S32(ctx->r2 << 17);
    // 0x80094FD4: sra         $a3, $v0, 17
    ctx->r7 = S32(SIGNED(ctx->r2) >> 17);
    // 0x80094FD8: j           L_80094FEC
    // 0x80094FDC: addiu       $v0, $v1, 0x2
    ctx->r2 = ADD32(ctx->r3, 0X2);
        goto L_80094FEC;
    // 0x80094FDC: addiu       $v0, $v1, 0x2
    ctx->r2 = ADD32(ctx->r3, 0X2);
L_80094FE0:
    // 0x80094FE0: sll         $v0, $a0, 25
    ctx->r2 = S32(ctx->r4 << 25);
    // 0x80094FE4: sra         $a3, $v0, 25
    ctx->r7 = S32(SIGNED(ctx->r2) >> 25);
    // 0x80094FE8: addiu       $v0, $v1, 0x1
    ctx->r2 = ADD32(ctx->r3, 0X1);
L_80094FEC:
    // 0x80094FEC: sw          $v0, 0x574($a1)
    MEM_W(0X574, ctx->r5) = ctx->r2;
    // 0x80094FF0: lui         $v0, 0x8015
    ctx->r2 = S32(0X8015 << 16);
    // 0x80094FF4: lw          $v0, 0x29C0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X29C0);
    // 0x80094FF8: addiu       $a0, $zero, 0x80
    ctx->r4 = ADD32(0, 0X80);
    // 0x80094FFC: addu        $v0, $v0, $s0
    ctx->r2 = ADD32(ctx->r2, ctx->r16);
    // 0x80095000: lhu         $v1, 0x57C($v0)
    ctx->r3 = MEM_HU(ctx->r2, 0X57C);
    // 0x80095004: lui         $a2, 0x8015
    ctx->r6 = S32(0X8015 << 16);
    // 0x80095008: lbu         $a2, 0x29CB($a2)
    ctx->r6 = MEM_BU(ctx->r6, 0X29CB);
    // 0x8009500C: lbu         $a1, 0x588($v0)
    ctx->r5 = MEM_BU(ctx->r2, 0X588);
    // 0x80095010: addu        $v1, $v1, $a3
    ctx->r3 = ADD32(ctx->r3, ctx->r7);
    // 0x80095014: srl         $a3, $v1, 7
    ctx->r7 = S32(U32(ctx->r3) >> 7);
    // 0x80095018: andi        $a3, $a3, 0xFF
    ctx->r7 = ctx->r7 & 0XFF;
    // 0x8009501C: jal         0x80083D9C
    // 0x80095020: sh          $v1, 0x57C($v0)
    MEM_H(0X57C, ctx->r2) = ctx->r3;
    func_80083D9C(rdram, ctx);
        goto after_0;
    // 0x80095020: sh          $v1, 0x57C($v0)
    MEM_H(0X57C, ctx->r2) = ctx->r3;
    after_0:
    // 0x80095024: lui         $v0, 0x8015
    ctx->r2 = S32(0X8015 << 16);
    // 0x80095028: lw          $v0, 0x29C0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X29C0);
    // 0x8009502C: lui         $a2, 0x8015
    ctx->r6 = S32(0X8015 << 16);
    // 0x80095030: lbu         $a2, 0x29CB($a2)
    ctx->r6 = MEM_BU(ctx->r6, 0X29CB);
    // 0x80095034: addu        $v0, $v0, $s0
    ctx->r2 = ADD32(ctx->r2, ctx->r16);
    // 0x80095038: lbu         $a3, 0x57D($v0)
    ctx->r7 = MEM_BU(ctx->r2, 0X57D);
    // 0x8009503C: lbu         $a1, 0x588($v0)
    ctx->r5 = MEM_BU(ctx->r2, 0X588);
    // 0x80095040: addiu       $a0, $zero, 0x81
    ctx->r4 = ADD32(0, 0X81);
    // 0x80095044: jal         0x80083D9C
    // 0x80095048: andi        $a3, $a3, 0x7F
    ctx->r7 = ctx->r7 & 0X7F;
    func_80083D9C(rdram, ctx);
        goto after_1;
    // 0x80095048: andi        $a3, $a3, 0x7F
    ctx->r7 = ctx->r7 & 0X7F;
    after_1:
    // 0x8009504C: j           L_8009505C
    // 0x80095050: andi        $v0, $s1, 0xFF
    ctx->r2 = ctx->r17 & 0XFF;
        goto L_8009505C;
    // 0x80095050: andi        $v0, $s1, 0xFF
    ctx->r2 = ctx->r17 & 0XFF;
L_80095054:
    // 0x80095054: addiu       $s1, $zero, 0x1
    ctx->r17 = ADD32(0, 0X1);
L_80095058:
    // 0x80095058: andi        $v0, $s1, 0xFF
    ctx->r2 = ctx->r17 & 0XFF;
L_8009505C:
    // 0x8009505C: beq         $v0, $zero, L_80094F1C
    if (ctx->r2 == 0) {
        // 0x80095060: nop
    
            goto L_80094F1C;
    }
    // 0x80095060: nop

    // 0x80095064: addiu       $s2, $s2, 0x24
    ctx->r18 = ADD32(ctx->r18, 0X24);
L_80095068:
    // 0x80095068: slti        $v0, $s2, 0x900
    ctx->r2 = SIGNED(ctx->r18) < 0X900 ? 1 : 0;
    // 0x8009506C: bne         $v0, $zero, L_80094EFC
    if (ctx->r2 != 0) {
        // 0x80095070: nop
    
            goto L_80094EFC;
    }
    // 0x80095070: nop

    // 0x80095074: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80095078: lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X18);
    // 0x8009507C: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x80095080: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x80095084: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80095088: jr          $ra
    // 0x8009508C: nop

    return;
    // 0x8009508C: nop

;}
RECOMP_FUNC void func_80095090(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80095090: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80095094: sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // 0x80095098: addu        $s2, $zero, $zero
    ctx->r18 = ADD32(0, 0);
    // 0x8009509C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800950A0: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x800950A4: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
L_800950A8:
    // 0x800950A8: lui         $v0, 0x8015
    ctx->r2 = S32(0X8015 << 16);
    // 0x800950AC: lw          $v0, 0x29C0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X29C0);
    // 0x800950B0: addu        $v0, $v0, $s2
    ctx->r2 = ADD32(ctx->r2, ctx->r18);
    // 0x800950B4: lw          $v0, 0x578($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X578);
    // 0x800950B8: beql        $v0, $zero, L_8009521C
    if (ctx->r2 == 0) {
        // 0x800950BC: addiu       $s2, $s2, 0x24
        ctx->r18 = ADD32(ctx->r18, 0X24);
            goto L_8009521C;
    }
    goto skip_0;
    // 0x800950BC: addiu       $s2, $s2, 0x24
    ctx->r18 = ADD32(ctx->r18, 0X24);
    skip_0:
    // 0x800950C0: addu        $s1, $zero, $zero
    ctx->r17 = ADD32(0, 0);
    // 0x800950C4: addu        $s0, $s2, $zero
    ctx->r16 = ADD32(ctx->r18, 0);
L_800950C8:
    // 0x800950C8: lui         $v0, 0x8015
    ctx->r2 = S32(0X8015 << 16);
    // 0x800950CC: lw          $v0, 0x29C0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X29C0);
    // 0x800950D0: addu        $a1, $v0, $s0
    ctx->r5 = ADD32(ctx->r2, ctx->r16);
    // 0x800950D4: lw          $v0, 0x578($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X578);
    // 0x800950D8: lbu         $a0, 0x0($v0)
    ctx->r4 = MEM_BU(ctx->r2, 0X0);
    // 0x800950DC: lbu         $a3, 0x1($v0)
    ctx->r7 = MEM_BU(ctx->r2, 0X1);
    // 0x800950E0: xori        $v0, $a0, 0x80
    ctx->r2 = ctx->r4 ^ 0X80;
    // 0x800950E4: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x800950E8: sltiu       $v1, $a3, 0x1
    ctx->r3 = ctx->r7 < 0X1 ? 1 : 0;
    // 0x800950EC: and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // 0x800950F0: beq         $v0, $zero, L_80095100
    if (ctx->r2 == 0) {
        // 0x800950F4: andi        $v0, $a0, 0x80
        ctx->r2 = ctx->r4 & 0X80;
            goto L_80095100;
    }
    // 0x800950F4: andi        $v0, $a0, 0x80
    ctx->r2 = ctx->r4 & 0X80;
    // 0x800950F8: j           L_80095208
    // 0x800950FC: sw          $zero, 0x578($a1)
    MEM_W(0X578, ctx->r5) = 0;
        goto L_80095208;
    // 0x800950FC: sw          $zero, 0x578($a1)
    MEM_W(0X578, ctx->r5) = 0;
L_80095100:
    // 0x80095100: beq         $v0, $zero, L_80095118
    if (ctx->r2 == 0) {
        // 0x80095104: andi        $v0, $a0, 0x7F
        ctx->r2 = ctx->r4 & 0X7F;
            goto L_80095118;
    }
    // 0x80095104: andi        $v0, $a0, 0x7F
    ctx->r2 = ctx->r4 & 0X7F;
    // 0x80095108: sll         $v0, $v0, 8
    ctx->r2 = S32(ctx->r2 << 8);
    // 0x8009510C: or          $a3, $a3, $v0
    ctx->r7 = ctx->r7 | ctx->r2;
    // 0x80095110: j           L_80095120
    // 0x80095114: addiu       $t0, $zero, 0x2
    ctx->r8 = ADD32(0, 0X2);
        goto L_80095120;
    // 0x80095114: addiu       $t0, $zero, 0x2
    ctx->r8 = ADD32(0, 0X2);
L_80095118:
    // 0x80095118: andi        $a3, $a0, 0xFF
    ctx->r7 = ctx->r4 & 0XFF;
    // 0x8009511C: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
L_80095120:
    // 0x80095120: lui         $a0, 0x8015
    ctx->r4 = S32(0X8015 << 16);
    // 0x80095124: lw          $a0, 0x29C0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X29C0);
    // 0x80095128: sll         $v1, $a3, 16
    ctx->r3 = S32(ctx->r7 << 16);
    // 0x8009512C: addu        $a2, $a0, $s0
    ctx->r6 = ADD32(ctx->r4, ctx->r16);
    // 0x80095130: lw          $a1, 0x584($a2)
    ctx->r5 = MEM_W(ctx->r6, 0X584);
    // 0x80095134: lw          $v0, 0x56C($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X56C);
    // 0x80095138: lw          $a0, 0x120($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X120);
    // 0x8009513C: sra         $v1, $v1, 16
    ctx->r3 = S32(SIGNED(ctx->r3) >> 16);
    // 0x80095140: addu        $a1, $a1, $v1
    ctx->r5 = ADD32(ctx->r5, ctx->r3);
    // 0x80095144: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x80095148: sltu        $v0, $v0, $a1
    ctx->r2 = ctx->r2 < ctx->r5 ? 1 : 0;
    // 0x8009514C: bnel        $v0, $zero, L_8009520C
    if (ctx->r2 != 0) {
        // 0x80095150: addiu       $s1, $zero, 0x1
        ctx->r17 = ADD32(0, 0X1);
            goto L_8009520C;
    }
    goto skip_1;
    // 0x80095150: addiu       $s1, $zero, 0x1
    ctx->r17 = ADD32(0, 0X1);
    skip_1:
    // 0x80095154: lw          $v0, 0x578($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X578);
    // 0x80095158: addu        $v0, $v0, $t0
    ctx->r2 = ADD32(ctx->r2, ctx->r8);
    // 0x8009515C: sw          $v0, 0x578($a2)
    MEM_W(0X578, ctx->r6) = ctx->r2;
    // 0x80095160: lw          $v1, 0x578($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X578);
    // 0x80095164: sw          $a1, 0x584($a2)
    MEM_W(0X584, ctx->r6) = ctx->r5;
    // 0x80095168: lbu         $a0, 0x0($v1)
    ctx->r4 = MEM_BU(ctx->r3, 0X0);
    // 0x8009516C: lbu         $a3, 0x1($v1)
    ctx->r7 = MEM_BU(ctx->r3, 0X1);
    // 0x80095170: andi        $v0, $a0, 0x80
    ctx->r2 = ctx->r4 & 0X80;
    // 0x80095174: beq         $v0, $zero, L_80095194
    if (ctx->r2 == 0) {
        // 0x80095178: andi        $v0, $a0, 0x7F
        ctx->r2 = ctx->r4 & 0X7F;
            goto L_80095194;
    }
    // 0x80095178: andi        $v0, $a0, 0x7F
    ctx->r2 = ctx->r4 & 0X7F;
    // 0x8009517C: sll         $v0, $v0, 8
    ctx->r2 = S32(ctx->r2 << 8);
    // 0x80095180: or          $v0, $a3, $v0
    ctx->r2 = ctx->r7 | ctx->r2;
    // 0x80095184: sll         $v0, $v0, 17
    ctx->r2 = S32(ctx->r2 << 17);
    // 0x80095188: sra         $a3, $v0, 17
    ctx->r7 = S32(SIGNED(ctx->r2) >> 17);
    // 0x8009518C: j           L_800951A0
    // 0x80095190: addiu       $v0, $v1, 0x2
    ctx->r2 = ADD32(ctx->r3, 0X2);
        goto L_800951A0;
    // 0x80095190: addiu       $v0, $v1, 0x2
    ctx->r2 = ADD32(ctx->r3, 0X2);
L_80095194:
    // 0x80095194: sll         $v0, $a0, 24
    ctx->r2 = S32(ctx->r4 << 24);
    // 0x80095198: sra         $a3, $v0, 24
    ctx->r7 = S32(SIGNED(ctx->r2) >> 24);
    // 0x8009519C: addiu       $v0, $v1, 0x1
    ctx->r2 = ADD32(ctx->r3, 0X1);
L_800951A0:
    // 0x800951A0: sw          $v0, 0x578($a2)
    MEM_W(0X578, ctx->r6) = ctx->r2;
    // 0x800951A4: lui         $v0, 0x8015
    ctx->r2 = S32(0X8015 << 16);
    // 0x800951A8: lw          $v0, 0x29C0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X29C0);
    // 0x800951AC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x800951B0: addu        $v0, $v0, $s0
    ctx->r2 = ADD32(ctx->r2, ctx->r16);
    // 0x800951B4: lhu         $v1, 0x57E($v0)
    ctx->r3 = MEM_HU(ctx->r2, 0X57E);
    // 0x800951B8: lui         $a2, 0x8015
    ctx->r6 = S32(0X8015 << 16);
    // 0x800951BC: lbu         $a2, 0x29CB($a2)
    ctx->r6 = MEM_BU(ctx->r6, 0X29CB);
    // 0x800951C0: lbu         $a1, 0x588($v0)
    ctx->r5 = MEM_BU(ctx->r2, 0X588);
    // 0x800951C4: addu        $v1, $v1, $a3
    ctx->r3 = ADD32(ctx->r3, ctx->r7);
    // 0x800951C8: srl         $a3, $v1, 7
    ctx->r7 = S32(U32(ctx->r3) >> 7);
    // 0x800951CC: andi        $a3, $a3, 0xFF
    ctx->r7 = ctx->r7 & 0XFF;
    // 0x800951D0: jal         0x80083D9C
    // 0x800951D4: sh          $v1, 0x57E($v0)
    MEM_H(0X57E, ctx->r2) = ctx->r3;
    func_80083D9C(rdram, ctx);
        goto after_0;
    // 0x800951D4: sh          $v1, 0x57E($v0)
    MEM_H(0X57E, ctx->r2) = ctx->r3;
    after_0:
    // 0x800951D8: lui         $v0, 0x8015
    ctx->r2 = S32(0X8015 << 16);
    // 0x800951DC: lw          $v0, 0x29C0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X29C0);
    // 0x800951E0: lui         $a2, 0x8015
    ctx->r6 = S32(0X8015 << 16);
    // 0x800951E4: lbu         $a2, 0x29CB($a2)
    ctx->r6 = MEM_BU(ctx->r6, 0X29CB);
    // 0x800951E8: addu        $v0, $v0, $s0
    ctx->r2 = ADD32(ctx->r2, ctx->r16);
    // 0x800951EC: lbu         $a3, 0x57F($v0)
    ctx->r7 = MEM_BU(ctx->r2, 0X57F);
    // 0x800951F0: lbu         $a1, 0x588($v0)
    ctx->r5 = MEM_BU(ctx->r2, 0X588);
    // 0x800951F4: addiu       $a0, $zero, 0x21
    ctx->r4 = ADD32(0, 0X21);
    // 0x800951F8: jal         0x80083D9C
    // 0x800951FC: andi        $a3, $a3, 0x7F
    ctx->r7 = ctx->r7 & 0X7F;
    func_80083D9C(rdram, ctx);
        goto after_1;
    // 0x800951FC: andi        $a3, $a3, 0x7F
    ctx->r7 = ctx->r7 & 0X7F;
    after_1:
    // 0x80095200: j           L_80095210
    // 0x80095204: andi        $v0, $s1, 0xFF
    ctx->r2 = ctx->r17 & 0XFF;
        goto L_80095210;
    // 0x80095204: andi        $v0, $s1, 0xFF
    ctx->r2 = ctx->r17 & 0XFF;
L_80095208:
    // 0x80095208: addiu       $s1, $zero, 0x1
    ctx->r17 = ADD32(0, 0X1);
L_8009520C:
    // 0x8009520C: andi        $v0, $s1, 0xFF
    ctx->r2 = ctx->r17 & 0XFF;
L_80095210:
    // 0x80095210: beq         $v0, $zero, L_800950C8
    if (ctx->r2 == 0) {
        // 0x80095214: nop
    
            goto L_800950C8;
    }
    // 0x80095214: nop

    // 0x80095218: addiu       $s2, $s2, 0x24
    ctx->r18 = ADD32(ctx->r18, 0X24);
L_8009521C:
    // 0x8009521C: slti        $v0, $s2, 0x900
    ctx->r2 = SIGNED(ctx->r18) < 0X900 ? 1 : 0;
    // 0x80095220: bne         $v0, $zero, L_800950A8
    if (ctx->r2 != 0) {
        // 0x80095224: nop
    
            goto L_800950A8;
    }
    // 0x80095224: nop

    // 0x80095228: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8009522C: lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X18);
    // 0x80095230: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x80095234: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x80095238: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8009523C: jr          $ra
    // 0x80095240: nop

    return;
    // 0x80095240: nop

;}
RECOMP_FUNC void func_80095244(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80095244: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80095248: sw          $s4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r20;
    // 0x8009524C: addiu       $s4, $zero, 0x1
    ctx->r20 = ADD32(0, 0X1);
    // 0x80095250: sw          $s6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r22;
    // 0x80095254: addu        $s6, $zero, $zero
    ctx->r22 = ADD32(0, 0);
    // 0x80095258: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x8009525C: addu        $s1, $zero, $zero
    ctx->r17 = ADD32(0, 0);
    // 0x80095260: sw          $s3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r19;
    // 0x80095264: addiu       $s3, $zero, 0xFF
    ctx->r19 = ADD32(0, 0XFF);
    // 0x80095268: sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // 0x8009526C: addu        $s2, $zero, $zero
    ctx->r18 = ADD32(0, 0);
    // 0x80095270: sw          $s5, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r21;
    // 0x80095274: addu        $s5, $zero, $zero
    ctx->r21 = ADD32(0, 0);
    // 0x80095278: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8009527C: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
L_80095280:
    // 0x80095280: lui         $t0, 0x8015
    ctx->r8 = S32(0X8015 << 16);
    // 0x80095284: lw          $t0, 0x29C0($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X29C0);
    // 0x80095288: addu        $v0, $t0, $s2
    ctx->r2 = ADD32(ctx->r8, ctx->r18);
    // 0x8009528C: lw          $a0, 0x12C($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X12C);
    // 0x80095290: beql        $a0, $zero, L_80095570
    if (ctx->r4 == 0) {
        // 0x80095294: addiu       $s2, $s2, 0x10
        ctx->r18 = ADD32(ctx->r18, 0X10);
            goto L_80095570;
    }
    goto skip_0;
    // 0x80095294: addiu       $s2, $s2, 0x10
    ctx->r18 = ADD32(ctx->r18, 0X10);
    skip_0:
    // 0x80095298: lw          $v0, 0x134($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X134);
    // 0x8009529C: lw          $v1, 0x120($t0)
    ctx->r3 = MEM_W(ctx->r8, 0X120);
    // 0x800952A0: lw          $a0, 0x0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X0);
    // 0x800952A4: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800952A8: sltu        $v0, $v0, $a0
    ctx->r2 = ctx->r2 < ctx->r4 ? 1 : 0;
    // 0x800952AC: bne         $v0, $zero, L_80095534
    if (ctx->r2 != 0) {
        // 0x800952B0: addiu       $s6, $zero, 0x1
        ctx->r22 = ADD32(0, 0X1);
            goto L_80095534;
    }
    // 0x800952B0: addiu       $s6, $zero, 0x1
    ctx->r22 = ADD32(0, 0X1);
    // 0x800952B4: addu        $s0, $s5, $zero
    ctx->r16 = ADD32(ctx->r21, 0);
    // 0x800952B8: addu        $a0, $t0, $s2
    ctx->r4 = ADD32(ctx->r8, ctx->r18);
L_800952BC:
    // 0x800952BC: lw          $a3, 0x12C($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X12C);
    // 0x800952C0: lhu         $a1, 0x8($a3)
    ctx->r5 = MEM_HU(ctx->r7, 0X8);
    // 0x800952C4: ori         $v0, $zero, 0xFFFE
    ctx->r2 = 0 | 0XFFFE;
    // 0x800952C8: beq         $a1, $v0, L_800952E0
    if (ctx->r5 == ctx->r2) {
        // 0x800952CC: ori         $v0, $zero, 0xFFFF
        ctx->r2 = 0 | 0XFFFF;
            goto L_800952E0;
    }
    // 0x800952CC: ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
    // 0x800952D0: bne         $a1, $v0, L_8009534C
    if (ctx->r5 != ctx->r2) {
        // 0x800952D4: sll         $v0, $a1, 2
        ctx->r2 = S32(ctx->r5 << 2);
            goto L_8009534C;
    }
    // 0x800952D4: sll         $v0, $a1, 2
    ctx->r2 = S32(ctx->r5 << 2);
    // 0x800952D8: j           L_8009556C
    // 0x800952DC: sw          $zero, 0x12C($a0)
    MEM_W(0X12C, ctx->r4) = 0;
        goto L_8009556C;
    // 0x800952DC: sw          $zero, 0x12C($a0)
    MEM_W(0X12C, ctx->r4) = 0;
L_800952E0:
    // 0x800952E0: lbu         $v0, 0xEC5($t0)
    ctx->r2 = MEM_BU(ctx->r8, 0XEC5);
    // 0x800952E4: bnel        $v0, $zero, L_8009556C
    if (ctx->r2 != 0) {
        // 0x800952E8: sw          $zero, 0x12C($a0)
        MEM_W(0X12C, ctx->r4) = 0;
            goto L_8009556C;
    }
    goto skip_1;
    // 0x800952E8: sw          $zero, 0x12C($a0)
    MEM_W(0X12C, ctx->r4) = 0;
    skip_1:
    // 0x800952EC: lhu         $a2, 0xA($a3)
    ctx->r6 = MEM_HU(ctx->r7, 0XA);
    // 0x800952F0: lw          $v1, 0x128($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X128);
    // 0x800952F4: sll         $v0, $a2, 1
    ctx->r2 = S32(ctx->r6 << 1);
    // 0x800952F8: addu        $v0, $v0, $a2
    ctx->r2 = ADD32(ctx->r2, ctx->r6);
    // 0x800952FC: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80095300: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x80095304: sw          $v1, 0x12C($a0)
    MEM_W(0X12C, ctx->r4) = ctx->r3;
    // 0x80095308: lw          $v0, 0x10C($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X10C);
    // 0x8009530C: lw          $v0, 0x14($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X14);
    // 0x80095310: sw          $zero, 0x130($a0)
    MEM_W(0X130, ctx->r4) = 0;
    // 0x80095314: sw          $v0, 0x134($a0)
    MEM_W(0X134, ctx->r4) = ctx->r2;
    // 0x80095318: andi        $v0, $s4, 0xFF
    ctx->r2 = ctx->r20 & 0XFF;
    // 0x8009531C: beq         $v0, $zero, L_80095504
    if (ctx->r2 == 0) {
        // 0x80095320: nop
    
            goto L_80095504;
    }
    // 0x80095320: nop

    // 0x80095324: lw          $v0, 0x10C($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X10C);
    // 0x80095328: lw          $a0, 0x14($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X14);
    // 0x8009532C: jal         0x800955B0
    // 0x80095330: addu        $s4, $zero, $zero
    ctx->r20 = ADD32(0, 0);
    func_800955B0(rdram, ctx);
        goto after_0;
    // 0x80095330: addu        $s4, $zero, $zero
    ctx->r20 = ADD32(0, 0);
    after_0:
    // 0x80095334: lui         $v1, 0x8015
    ctx->r3 = S32(0X8015 << 16);
    // 0x80095338: lw          $v1, 0x29C0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X29C0);
    // 0x8009533C: lhu         $v0, 0xEC6($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0XEC6);
    // 0x80095340: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80095344: j           L_80095504
    // 0x80095348: sh          $v0, 0xEC6($v1)
    MEM_H(0XEC6, ctx->r3) = ctx->r2;
        goto L_80095504;
    // 0x80095348: sh          $v0, 0xEC6($v1)
    MEM_H(0XEC6, ctx->r3) = ctx->r2;
L_8009534C:
    // 0x8009534C: lw          $a0, 0x10C($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X10C);
    // 0x80095350: lw          $v1, 0x4($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X4);
    // 0x80095354: addu        $v1, $v1, $a0
    ctx->r3 = ADD32(ctx->r3, ctx->r4);
    // 0x80095358: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8009535C: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x80095360: addu        $a1, $t0, $s0
    ctx->r5 = ADD32(ctx->r8, ctx->r16);
    // 0x80095364: sw          $zero, 0x56C($a1)
    MEM_W(0X56C, ctx->r5) = 0;
    // 0x80095368: sw          $zero, 0x568($a1)
    MEM_W(0X568, ctx->r5) = 0;
    // 0x8009536C: addu        $a2, $v0, $a0
    ctx->r6 = ADD32(ctx->r2, ctx->r4);
    // 0x80095370: addiu       $v0, $a2, 0xC
    ctx->r2 = ADD32(ctx->r6, 0XC);
    // 0x80095374: sw          $v0, 0x570($a1)
    MEM_W(0X570, ctx->r5) = ctx->r2;
    // 0x80095378: lw          $v1, 0x4($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X4);
    // 0x8009537C: beql        $v1, $zero, L_80095390
    if (ctx->r3 == 0) {
        // 0x80095380: sw          $zero, 0x574($a1)
        MEM_W(0X574, ctx->r5) = 0;
            goto L_80095390;
    }
    goto skip_2;
    // 0x80095380: sw          $zero, 0x574($a1)
    MEM_W(0X574, ctx->r5) = 0;
    skip_2:
    // 0x80095384: lw          $v0, 0x10C($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X10C);
    // 0x80095388: addu        $v0, $v1, $v0
    ctx->r2 = ADD32(ctx->r3, ctx->r2);
    // 0x8009538C: sw          $v0, 0x574($a1)
    MEM_W(0X574, ctx->r5) = ctx->r2;
L_80095390:
    // 0x80095390: lui         $a1, 0x8015
    ctx->r5 = S32(0X8015 << 16);
    // 0x80095394: lw          $a1, 0x29C0($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X29C0);
    // 0x80095398: addiu       $v0, $zero, 0x2000
    ctx->r2 = ADD32(0, 0X2000);
    // 0x8009539C: addu        $a0, $a1, $s0
    ctx->r4 = ADD32(ctx->r5, ctx->r16);
    // 0x800953A0: sw          $zero, 0x580($a0)
    MEM_W(0X580, ctx->r4) = 0;
    // 0x800953A4: sh          $v0, 0x57C($a0)
    MEM_H(0X57C, ctx->r4) = ctx->r2;
    // 0x800953A8: lw          $v1, 0x8($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X8);
    // 0x800953AC: beql        $v1, $zero, L_800953C0
    if (ctx->r3 == 0) {
        // 0x800953B0: sw          $zero, 0x578($a0)
        MEM_W(0X578, ctx->r4) = 0;
            goto L_800953C0;
    }
    goto skip_3;
    // 0x800953B0: sw          $zero, 0x578($a0)
    MEM_W(0X578, ctx->r4) = 0;
    skip_3:
    // 0x800953B4: lw          $v0, 0x10C($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X10C);
    // 0x800953B8: addu        $v0, $v1, $v0
    ctx->r2 = ADD32(ctx->r3, ctx->r2);
    // 0x800953BC: sw          $v0, 0x578($a0)
    MEM_W(0X578, ctx->r4) = ctx->r2;
L_800953C0:
    // 0x800953C0: lui         $v0, 0x8015
    ctx->r2 = S32(0X8015 << 16);
    // 0x800953C4: lw          $v0, 0x29C0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X29C0);
    // 0x800953C8: addu        $a0, $v0, $s0
    ctx->r4 = ADD32(ctx->r2, ctx->r16);
    // 0x800953CC: sw          $zero, 0x584($a0)
    MEM_W(0X584, ctx->r4) = 0;
    // 0x800953D0: sh          $zero, 0x57E($a0)
    MEM_H(0X57E, ctx->r4) = 0;
    // 0x800953D4: lw          $v1, 0x10C($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X10C);
    // 0x800953D8: lw          $v0, 0x8($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X8);
    // 0x800953DC: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800953E0: addu        $v0, $v0, $s1
    ctx->r2 = ADD32(ctx->r2, ctx->r17);
    // 0x800953E4: lbu         $v0, 0x0($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X0);
    // 0x800953E8: sb          $v0, 0x588($a0)
    MEM_B(0X588, ctx->r4) = ctx->r2;
    // 0x800953EC: lui         $v0, 0x8015
    ctx->r2 = S32(0X8015 << 16);
    // 0x800953F0: lw          $v0, 0x29C0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X29C0);
    // 0x800953F4: lbu         $v1, 0xB($a3)
    ctx->r3 = MEM_BU(ctx->r7, 0XB);
    // 0x800953F8: addu        $v0, $v0, $s0
    ctx->r2 = ADD32(ctx->r2, ctx->r16);
    // 0x800953FC: sb          $v1, 0x589($v0)
    MEM_B(0X589, ctx->r2) = ctx->r3;
    // 0x80095400: lui         $v0, 0x8015
    ctx->r2 = S32(0X8015 << 16);
    // 0x80095404: lw          $v0, 0x29C0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X29C0);
    // 0x80095408: lbu         $v1, 0xA($a3)
    ctx->r3 = MEM_BU(ctx->r7, 0XA);
    // 0x8009540C: addu        $v0, $v0, $s0
    ctx->r2 = ADD32(ctx->r2, ctx->r16);
    // 0x80095410: sb          $v1, 0x58A($v0)
    MEM_B(0X58A, ctx->r2) = ctx->r3;
    // 0x80095414: lui         $v0, 0x8015
    ctx->r2 = S32(0X8015 << 16);
    // 0x80095418: lw          $v0, 0x29C0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X29C0);
    // 0x8009541C: addu        $v0, $v0, $s0
    ctx->r2 = ADD32(ctx->r2, ctx->r16);
    // 0x80095420: sb          $s1, 0x58B($v0)
    MEM_B(0X58B, ctx->r2) = ctx->r17;
    // 0x80095424: lbu         $v1, 0x4($a3)
    ctx->r3 = MEM_BU(ctx->r7, 0X4);
    // 0x80095428: beq         $v1, $s3, L_800954C0
    if (ctx->r3 == ctx->r19) {
        // 0x8009542C: nop
    
            goto L_800954C0;
    }
    // 0x8009542C: nop

    // 0x80095430: lui         $a2, 0x8015
    ctx->r6 = S32(0X8015 << 16);
    // 0x80095434: lw          $a2, 0x29C0($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X29C0);
    // 0x80095438: addu        $v0, $a2, $s0
    ctx->r2 = ADD32(ctx->r6, ctx->r16);
    // 0x8009543C: lbu         $a1, 0x588($v0)
    ctx->r5 = MEM_BU(ctx->r2, 0X588);
    // 0x80095440: addiu       $v0, $zero, 0x9
    ctx->r2 = ADD32(0, 0X9);
    // 0x80095444: beq         $a1, $v0, L_8009548C
    if (ctx->r5 == ctx->r2) {
        // 0x80095448: addu        $v0, $a2, $v1
        ctx->r2 = ADD32(ctx->r6, ctx->r3);
            goto L_8009548C;
    }
    // 0x80095448: addu        $v0, $a2, $v1
    ctx->r2 = ADD32(ctx->r6, ctx->r3);
    // 0x8009544C: lbu         $v0, 0x8($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X8);
    // 0x80095450: beq         $v0, $s3, L_800954C0
    if (ctx->r2 == ctx->r19) {
        // 0x80095454: sll         $a1, $a1, 2
        ctx->r5 = S32(ctx->r5 << 2);
            goto L_800954C0;
    }
    // 0x80095454: sll         $a1, $a1, 2
    ctx->r5 = S32(ctx->r5 << 2);
    // 0x80095458: lw          $v1, 0x4($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X4);
    // 0x8009545C: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x80095460: addu        $a1, $a1, $a2
    ctx->r5 = ADD32(ctx->r5, ctx->r6);
    // 0x80095464: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80095468: lhu         $v1, 0x0($v0)
    ctx->r3 = MEM_HU(ctx->r2, 0X0);
    // 0x8009546C: lbu         $a0, 0x2($v0)
    ctx->r4 = MEM_BU(ctx->r2, 0X2);
    // 0x80095470: lbu         $v0, 0x3($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X3);
    // 0x80095474: sll         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3 << 16);
    // 0x80095478: sll         $a0, $a0, 8
    ctx->r4 = S32(ctx->r4 << 8);
    // 0x8009547C: or          $v1, $v1, $a0
    ctx->r3 = ctx->r3 | ctx->r4;
    // 0x80095480: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x80095484: j           L_800954C0
    // 0x80095488: sw          $v1, 0xE80($a1)
    MEM_W(0XE80, ctx->r5) = ctx->r3;
        goto L_800954C0;
    // 0x80095488: sw          $v1, 0xE80($a1)
    MEM_W(0XE80, ctx->r5) = ctx->r3;
L_8009548C:
    // 0x8009548C: lbu         $v0, 0x8C($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X8C);
    // 0x80095490: beq         $v0, $s3, L_800954C0
    if (ctx->r2 == ctx->r19) {
        // 0x80095494: sll         $v0, $v0, 3
        ctx->r2 = S32(ctx->r2 << 3);
            goto L_800954C0;
    }
    // 0x80095494: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x80095498: lw          $v1, 0x88($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X88);
    // 0x8009549C: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800954A0: lhu         $v1, 0x0($v0)
    ctx->r3 = MEM_HU(ctx->r2, 0X0);
    // 0x800954A4: lbu         $a0, 0x2($v0)
    ctx->r4 = MEM_BU(ctx->r2, 0X2);
    // 0x800954A8: lbu         $v0, 0x3($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X3);
    // 0x800954AC: sll         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3 << 16);
    // 0x800954B0: sll         $a0, $a0, 8
    ctx->r4 = S32(ctx->r4 << 8);
    // 0x800954B4: or          $v1, $v1, $a0
    ctx->r3 = ctx->r3 | ctx->r4;
    // 0x800954B8: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x800954BC: sw          $v1, 0xEA4($a2)
    MEM_W(0XEA4, ctx->r6) = ctx->r3;
L_800954C0:
    // 0x800954C0: lbu         $a3, 0x5($a3)
    ctx->r7 = MEM_BU(ctx->r7, 0X5);
    // 0x800954C4: beq         $a3, $s3, L_800954EC
    if (ctx->r7 == ctx->r19) {
        // 0x800954C8: nop
    
            goto L_800954EC;
    }
    // 0x800954C8: nop

    // 0x800954CC: lui         $v0, 0x8015
    ctx->r2 = S32(0X8015 << 16);
    // 0x800954D0: lw          $v0, 0x29C0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X29C0);
    // 0x800954D4: lui         $a2, 0x8015
    ctx->r6 = S32(0X8015 << 16);
    // 0x800954D8: lbu         $a2, 0x29CB($a2)
    ctx->r6 = MEM_BU(ctx->r6, 0X29CB);
    // 0x800954DC: addu        $v0, $v0, $s0
    ctx->r2 = ADD32(ctx->r2, ctx->r16);
    // 0x800954E0: lbu         $a1, 0x588($v0)
    ctx->r5 = MEM_BU(ctx->r2, 0X588);
    // 0x800954E4: jal         0x80083D9C
    // 0x800954E8: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    func_80083D9C(rdram, ctx);
        goto after_1;
    // 0x800954E8: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    after_1:
L_800954EC:
    // 0x800954EC: lui         $v1, 0x8015
    ctx->r3 = S32(0X8015 << 16);
    // 0x800954F0: lw          $v1, 0x29C0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X29C0);
    // 0x800954F4: addu        $v1, $v1, $s2
    ctx->r3 = ADD32(ctx->r3, ctx->r18);
    // 0x800954F8: lw          $v0, 0x12C($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X12C);
    // 0x800954FC: addiu       $v0, $v0, 0xC
    ctx->r2 = ADD32(ctx->r2, 0XC);
    // 0x80095500: sw          $v0, 0x12C($v1)
    MEM_W(0X12C, ctx->r3) = ctx->r2;
L_80095504:
    // 0x80095504: lui         $t0, 0x8015
    ctx->r8 = S32(0X8015 << 16);
    // 0x80095508: lw          $t0, 0x29C0($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X29C0);
    // 0x8009550C: sll         $v0, $s1, 4
    ctx->r2 = S32(ctx->r17 << 4);
    // 0x80095510: addu        $v0, $t0, $v0
    ctx->r2 = ADD32(ctx->r8, ctx->r2);
    // 0x80095514: lw          $a0, 0x12C($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X12C);
    // 0x80095518: lw          $v0, 0x134($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X134);
    // 0x8009551C: lw          $v1, 0x120($t0)
    ctx->r3 = MEM_W(ctx->r8, 0X120);
    // 0x80095520: lw          $a0, 0x0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X0);
    // 0x80095524: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80095528: sltu        $v0, $v0, $a0
    ctx->r2 = ctx->r2 < ctx->r4 ? 1 : 0;
    // 0x8009552C: beq         $v0, $zero, L_800952BC
    if (ctx->r2 == 0) {
        // 0x80095530: addu        $a0, $t0, $s2
        ctx->r4 = ADD32(ctx->r8, ctx->r18);
            goto L_800952BC;
    }
    // 0x80095530: addu        $a0, $t0, $s2
    ctx->r4 = ADD32(ctx->r8, ctx->r18);
L_80095534:
    // 0x80095534: lui         $a0, 0x8015
    ctx->r4 = S32(0X8015 << 16);
    // 0x80095538: lw          $a0, 0x29C0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X29C0);
    // 0x8009553C: addu        $a1, $a0, $s2
    ctx->r5 = ADD32(ctx->r4, ctx->r18);
    // 0x80095540: lw          $v1, 0x130($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X130);
    // 0x80095544: lw          $v0, 0x118($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X118);
    // 0x80095548: addu        $a2, $v1, $v0
    ctx->r6 = ADD32(ctx->r3, ctx->r2);
    // 0x8009554C: andi        $v0, $a2, 0xFFFF
    ctx->r2 = ctx->r6 & 0XFFFF;
    // 0x80095550: sw          $v0, 0x130($a1)
    MEM_W(0X130, ctx->r5) = ctx->r2;
    // 0x80095554: lw          $v0, 0x11C($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X11C);
    // 0x80095558: lw          $v1, 0x134($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X134);
    // 0x8009555C: srl         $a2, $a2, 16
    ctx->r6 = S32(U32(ctx->r6) >> 16);
    // 0x80095560: addu        $v0, $a2, $v0
    ctx->r2 = ADD32(ctx->r6, ctx->r2);
    // 0x80095564: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x80095568: sw          $v1, 0x134($a1)
    MEM_W(0X134, ctx->r5) = ctx->r3;
L_8009556C:
    // 0x8009556C: addiu       $s2, $s2, 0x10
    ctx->r18 = ADD32(ctx->r18, 0X10);
L_80095570:
    // 0x80095570: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80095574: slti        $v0, $s1, 0x40
    ctx->r2 = SIGNED(ctx->r17) < 0X40 ? 1 : 0;
    // 0x80095578: bne         $v0, $zero, L_80095280
    if (ctx->r2 != 0) {
        // 0x8009557C: addiu       $s5, $s5, 0x24
        ctx->r21 = ADD32(ctx->r21, 0X24);
            goto L_80095280;
    }
    // 0x8009557C: addiu       $s5, $s5, 0x24
    ctx->r21 = ADD32(ctx->r21, 0X24);
    // 0x80095580: addu        $v0, $s6, $zero
    ctx->r2 = ADD32(ctx->r22, 0);
    // 0x80095584: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80095588: lw          $s6, 0x28($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X28);
    // 0x8009558C: lw          $s5, 0x24($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X24);
    // 0x80095590: lw          $s4, 0x20($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X20);
    // 0x80095594: lw          $s3, 0x1C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X1C);
    // 0x80095598: lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X18);
    // 0x8009559C: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x800955A0: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x800955A4: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x800955A8: jr          $ra
    // 0x800955AC: nop

    return;
    // 0x800955AC: nop

;}
RECOMP_FUNC void func_800955B0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800955B0: lui         $v0, 0x8015
    ctx->r2 = S32(0X8015 << 16);
    // 0x800955B4: lw          $v0, 0x29C0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X29C0);
    // 0x800955B8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800955BC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800955C0: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x800955C4: lw          $v1, 0xE68($v0)
    ctx->r3 = MEM_W(ctx->r2, 0XE68);
    // 0x800955C8: sw          $v1, 0xE6C($v0)
    MEM_W(0XE6C, ctx->r2) = ctx->r3;
    // 0x800955CC: lw          $v1, 0xE6C($v0)
    ctx->r3 = MEM_W(ctx->r2, 0XE6C);
    // 0x800955D0: sw          $a0, 0xE74($v0)
    MEM_W(0XE74, ctx->r2) = ctx->r4;
    // 0x800955D4: sw          $zero, 0xE70($v0)
    MEM_W(0XE70, ctx->r2) = 0;
    // 0x800955D8: lw          $v1, 0x0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X0);
    // 0x800955DC: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x800955E0: beq         $v1, $v0, L_80095648
    if (ctx->r3 == ctx->r2) {
        // 0x800955E4: nop
    
            goto L_80095648;
    }
    // 0x800955E4: nop

    // 0x800955E8: addiu       $s0, $zero, -0x1
    ctx->r16 = ADD32(0, -0X1);
L_800955EC:
    // 0x800955EC: lui         $a2, 0x8015
    ctx->r6 = S32(0X8015 << 16);
    // 0x800955F0: lw          $a2, 0x29C0($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X29C0);
    // 0x800955F4: lw          $a1, 0xE6C($a2)
    ctx->r5 = MEM_W(ctx->r6, 0XE6C);
    // 0x800955F8: lw          $v0, 0xE74($a2)
    ctx->r2 = MEM_W(ctx->r6, 0XE74);
    // 0x800955FC: lw          $v1, 0x120($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X120);
    // 0x80095600: lw          $a0, 0x0($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X0);
    // 0x80095604: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80095608: sltu        $v0, $v0, $a0
    ctx->r2 = ctx->r2 < ctx->r4 ? 1 : 0;
    // 0x8009560C: bne         $v0, $zero, L_80095648
    if (ctx->r2 != 0) {
        // 0x80095610: nop
    
            goto L_80095648;
    }
    // 0x80095610: nop

    // 0x80095614: lw          $a0, 0x4($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X4);
    // 0x80095618: lui         $a1, 0x8015
    ctx->r5 = S32(0X8015 << 16);
    // 0x8009561C: lbu         $a1, 0x29CB($a1)
    ctx->r5 = MEM_BU(ctx->r5, 0X29CB);
    // 0x80095620: jal         0x80083D20
    // 0x80095624: sw          $a0, 0x124($a2)
    MEM_W(0X124, ctx->r6) = ctx->r4;
    func_80083D20(rdram, ctx);
        goto after_0;
    // 0x80095624: sw          $a0, 0x124($a2)
    MEM_W(0X124, ctx->r6) = ctx->r4;
    after_0:
    // 0x80095628: lui         $v1, 0x8015
    ctx->r3 = S32(0X8015 << 16);
    // 0x8009562C: lw          $v1, 0x29C0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X29C0);
    // 0x80095630: lw          $a0, 0xE6C($v1)
    ctx->r4 = MEM_W(ctx->r3, 0XE6C);
    // 0x80095634: addiu       $v0, $a0, 0x8
    ctx->r2 = ADD32(ctx->r4, 0X8);
    // 0x80095638: sw          $v0, 0xE6C($v1)
    MEM_W(0XE6C, ctx->r3) = ctx->r2;
    // 0x8009563C: lw          $v0, 0x8($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X8);
    // 0x80095640: bne         $v0, $s0, L_800955EC
    if (ctx->r2 != ctx->r16) {
        // 0x80095644: nop
    
            goto L_800955EC;
    }
    // 0x80095644: nop

L_80095648:
    // 0x80095648: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8009564C: lw          $a0, 0x2038($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X2038);
    // 0x80095650: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x80095654: lw          $v0, 0x40C0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X40C0);
    // 0x80095658: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x8009565C: div         $zero, $a0, $v0
    lo = S32(S64(S32(ctx->r4)) / S64(S32(ctx->r2))); hi = S32(S64(S32(ctx->r4)) % S64(S32(ctx->r2)));
    // 0x80095660: bne         $v0, $zero, L_8009566C
    if (ctx->r2 != 0) {
        // 0x80095664: nop
    
            goto L_8009566C;
    }
    // 0x80095664: nop

    // 0x80095668: break       7
    do_break(2148095592);
L_8009566C:
    // 0x8009566C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80095670: bne         $v0, $at, L_80095684
    if (ctx->r2 != ctx->r1) {
        // 0x80095674: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80095684;
    }
    // 0x80095674: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80095678: bne         $a0, $at, L_80095684
    if (ctx->r4 != ctx->r1) {
        // 0x8009567C: nop
    
            goto L_80095684;
    }
    // 0x8009567C: nop

    // 0x80095680: break       6
    do_break(2148095616);
L_80095684:
    // 0x80095684: mflo        $a0
    ctx->r4 = lo;
    // 0x80095688: lui         $a1, 0x8015
    ctx->r5 = S32(0X8015 << 16);
    // 0x8009568C: lw          $a1, 0x29C0($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X29C0);
    // 0x80095690: lw          $v1, 0x124($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X124);
    // 0x80095694: sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3 << 1);
    // 0x80095698: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8009569C: sll         $v0, $v0, 9
    ctx->r2 = S32(ctx->r2 << 9);
    // 0x800956A0: lui         $v1, 0x8888
    ctx->r3 = S32(0X8888 << 16);
    // 0x800956A4: ori         $v1, $v1, 0x8889
    ctx->r3 = ctx->r3 | 0X8889;
    // 0x800956A8: multu       $v0, $v1
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800956AC: mfhi        $a3
    ctx->r7 = hi;
    // 0x800956B0: srl         $v0, $a3, 7
    ctx->r2 = S32(U32(ctx->r7) >> 7);
    // 0x800956B4: nop

    // 0x800956B8: mult        $v0, $a0
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800956BC: mflo        $v1
    ctx->r3 = lo;
    // 0x800956C0: lhu         $v0, 0xEC2($a1)
    ctx->r2 = MEM_HU(ctx->r5, 0XEC2);
    // 0x800956C4: nop

    // 0x800956C8: mult        $v1, $v0
    result = S64(S32(ctx->r3)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800956CC: mflo        $v0
    ctx->r2 = lo;
    // 0x800956D0: srl         $v1, $v0, 8
    ctx->r3 = S32(U32(ctx->r2) >> 8);
    // 0x800956D4: andi        $v1, $v1, 0xFFFF
    ctx->r3 = ctx->r3 & 0XFFFF;
    // 0x800956D8: srl         $v0, $v0, 24
    ctx->r2 = S32(U32(ctx->r2) >> 24);
    // 0x800956DC: sw          $v0, 0x11C($a1)
    MEM_W(0X11C, ctx->r5) = ctx->r2;
    // 0x800956E0: sra         $v0, $v0, 1
    ctx->r2 = S32(SIGNED(ctx->r2) >> 1);
    // 0x800956E4: sw          $v1, 0x118($a1)
    MEM_W(0X118, ctx->r5) = ctx->r3;
    // 0x800956E8: sw          $v0, 0x120($a1)
    MEM_W(0X120, ctx->r5) = ctx->r2;
    // 0x800956EC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800956F0: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x800956F4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800956F8: jr          $ra
    // 0x800956FC: nop

    return;
    // 0x800956FC: nop

;}
RECOMP_FUNC void func_80095700(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80095700: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x80095704: lbu         $v0, 0xF50($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0XF50);
    // 0x80095708: beq         $v0, $zero, L_800957A0
    if (ctx->r2 == 0) {
        // 0x8009570C: addu        $a1, $zero, $zero
        ctx->r5 = ADD32(0, 0);
            goto L_800957A0;
    }
    // 0x8009570C: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x80095710: lui         $v0, 0x7FFF
    ctx->r2 = S32(0X7FFF << 16);
    // 0x80095714: ori         $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 | 0XFFFF;
    // 0x80095718: and         $a2, $a0, $v0
    ctx->r6 = ctx->r4 & ctx->r2;
    // 0x8009571C: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
L_80095720:
    // 0x80095720: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80095724: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x80095728: lbu         $v0, -0x573F($at)
    ctx->r2 = MEM_BU(ctx->r1, -0X573F);
    // 0x8009572C: bnel        $v0, $zero, L_8009574C
    if (ctx->r2 != 0) {
        // 0x80095730: addiu       $a1, $a1, 0x1
        ctx->r5 = ADD32(ctx->r5, 0X1);
            goto L_8009574C;
    }
    goto skip_0;
    // 0x80095730: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    skip_0:
    // 0x80095734: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80095738: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x8009573C: lw          $v0, -0x6600($at)
    ctx->r2 = MEM_W(ctx->r1, -0X6600);
    // 0x80095740: beq         $v0, $a2, L_80095794
    if (ctx->r2 == ctx->r6) {
        // 0x80095744: lui         $v0, 0x8000
        ctx->r2 = S32(0X8000 << 16);
            goto L_80095794;
    }
    // 0x80095744: lui         $v0, 0x8000
    ctx->r2 = S32(0X8000 << 16);
    // 0x80095748: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
L_8009574C:
    // 0x8009574C: sltiu       $v0, $a1, 0x8
    ctx->r2 = ctx->r5 < 0X8 ? 1 : 0;
    // 0x80095750: bne         $v0, $zero, L_80095720
    if (ctx->r2 != 0) {
        // 0x80095754: addiu       $v1, $v1, 0xEF8
        ctx->r3 = ADD32(ctx->r3, 0XEF8);
            goto L_80095720;
    }
    // 0x80095754: addiu       $v1, $v1, 0xEF8
    ctx->r3 = ADD32(ctx->r3, 0XEF8);
    // 0x80095758: addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
L_8009575C:
    // 0x8009575C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x80095760: beql        $v1, $v0, L_800957A4
    if (ctx->r3 == ctx->r2) {
        // 0x80095764: addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
            goto L_800957A4;
    }
    goto skip_1;
    // 0x80095764: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    skip_1:
    // 0x80095768: bltz        $v1, L_800957A0
    if (SIGNED(ctx->r3) < 0) {
        // 0x8009576C: sll         $v0, $v1, 4
        ctx->r2 = S32(ctx->r3 << 4);
            goto L_800957A0;
    }
    // 0x8009576C: sll         $v0, $v1, 4
    ctx->r2 = S32(ctx->r3 << 4);
    // 0x80095770: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x80095774: sll         $v0, $v0, 5
    ctx->r2 = S32(ctx->r2 << 5);
    // 0x80095778: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x8009577C: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x80095780: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80095784: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80095788: lhu         $v0, -0x573A($at)
    ctx->r2 = MEM_HU(ctx->r1, -0X573A);
    // 0x8009578C: j           L_800957A4
    // 0x80095790: nop

        goto L_800957A4;
    // 0x80095790: nop

L_80095794:
    // 0x80095794: and         $v0, $a0, $v0
    ctx->r2 = ctx->r4 & ctx->r2;
    // 0x80095798: j           L_8009575C
    // 0x8009579C: or          $v1, $a1, $v0
    ctx->r3 = ctx->r5 | ctx->r2;
        goto L_8009575C;
    // 0x8009579C: or          $v1, $a1, $v0
    ctx->r3 = ctx->r5 | ctx->r2;
L_800957A0:
    // 0x800957A0: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_800957A4:
    // 0x800957A4: jr          $ra
    // 0x800957A8: nop

    return;
    // 0x800957A8: nop

;}
RECOMP_FUNC void func_800957AC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800957AC: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x800957B0: lbu         $v0, 0xF50($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0XF50);
    // 0x800957B4: beq         $v0, $zero, L_80095820
    if (ctx->r2 == 0) {
        // 0x800957B8: addu        $a1, $zero, $zero
        ctx->r5 = ADD32(0, 0);
            goto L_80095820;
    }
    // 0x800957B8: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x800957BC: lui         $v0, 0x7FFF
    ctx->r2 = S32(0X7FFF << 16);
    // 0x800957C0: ori         $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 | 0XFFFF;
    // 0x800957C4: and         $a2, $a0, $v0
    ctx->r6 = ctx->r4 & ctx->r2;
    // 0x800957C8: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
L_800957CC:
    // 0x800957CC: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x800957D0: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x800957D4: lbu         $v0, -0x573F($at)
    ctx->r2 = MEM_BU(ctx->r1, -0X573F);
    // 0x800957D8: bnel        $v0, $zero, L_800957F8
    if (ctx->r2 != 0) {
        // 0x800957DC: addiu       $a1, $a1, 0x1
        ctx->r5 = ADD32(ctx->r5, 0X1);
            goto L_800957F8;
    }
    goto skip_0;
    // 0x800957DC: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    skip_0:
    // 0x800957E0: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x800957E4: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x800957E8: lw          $v0, -0x6600($at)
    ctx->r2 = MEM_W(ctx->r1, -0X6600);
    // 0x800957EC: beq         $v0, $a2, L_80095814
    if (ctx->r2 == ctx->r6) {
        // 0x800957F0: lui         $v0, 0x8000
        ctx->r2 = S32(0X8000 << 16);
            goto L_80095814;
    }
    // 0x800957F0: lui         $v0, 0x8000
    ctx->r2 = S32(0X8000 << 16);
    // 0x800957F4: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
L_800957F8:
    // 0x800957F8: sltiu       $v0, $a1, 0x8
    ctx->r2 = ctx->r5 < 0X8 ? 1 : 0;
    // 0x800957FC: bne         $v0, $zero, L_800957CC
    if (ctx->r2 != 0) {
        // 0x80095800: addiu       $v1, $v1, 0xEF8
        ctx->r3 = ADD32(ctx->r3, 0XEF8);
            goto L_800957CC;
    }
    // 0x80095800: addiu       $v1, $v1, 0xEF8
    ctx->r3 = ADD32(ctx->r3, 0XEF8);
    // 0x80095804: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_80095808:
    // 0x80095808: nor         $v0, $zero, $v0
    ctx->r2 = ~(0 | ctx->r2);
    // 0x8009580C: j           L_80095824
    // 0x80095810: sltu        $v0, $zero, $v0
    ctx->r2 = 0 < ctx->r2 ? 1 : 0;
        goto L_80095824;
    // 0x80095810: sltu        $v0, $zero, $v0
    ctx->r2 = 0 < ctx->r2 ? 1 : 0;
L_80095814:
    // 0x80095814: and         $v0, $a0, $v0
    ctx->r2 = ctx->r4 & ctx->r2;
    // 0x80095818: j           L_80095808
    // 0x8009581C: or          $v0, $a1, $v0
    ctx->r2 = ctx->r5 | ctx->r2;
        goto L_80095808;
    // 0x8009581C: or          $v0, $a1, $v0
    ctx->r2 = ctx->r5 | ctx->r2;
L_80095820:
    // 0x80095820: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_80095824:
    // 0x80095824: jr          $ra
    // 0x80095828: nop

    return;
    // 0x80095828: nop

;}
RECOMP_FUNC void func_8009582C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009582C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80095830: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x80095834: addu        $s1, $a0, $zero
    ctx->r17 = ADD32(ctx->r4, 0);
    // 0x80095838: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x8009583C: lui         $v0, 0x7FFF
    ctx->r2 = S32(0X7FFF << 16);
    // 0x80095840: ori         $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 | 0XFFFF;
    // 0x80095844: and         $a1, $s1, $v0
    ctx->r5 = ctx->r17 & ctx->r2;
    // 0x80095848: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
    // 0x8009584C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80095850: sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // 0x80095854: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
L_80095858:
    // 0x80095858: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8009585C: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x80095860: lbu         $v0, -0x573F($at)
    ctx->r2 = MEM_BU(ctx->r1, -0X573F);
    // 0x80095864: bnel        $v0, $zero, L_80095884
    if (ctx->r2 != 0) {
        // 0x80095868: addiu       $a0, $a0, 0x1
        ctx->r4 = ADD32(ctx->r4, 0X1);
            goto L_80095884;
    }
    goto skip_0;
    // 0x80095868: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    skip_0:
    // 0x8009586C: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80095870: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x80095874: lw          $v0, -0x6600($at)
    ctx->r2 = MEM_W(ctx->r1, -0X6600);
    // 0x80095878: beq         $v0, $a1, L_80095A08
    if (ctx->r2 == ctx->r5) {
        // 0x8009587C: lui         $v0, 0x8000
        ctx->r2 = S32(0X8000 << 16);
            goto L_80095A08;
    }
    // 0x8009587C: lui         $v0, 0x8000
    ctx->r2 = S32(0X8000 << 16);
    // 0x80095880: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
L_80095884:
    // 0x80095884: sltiu       $v0, $a0, 0x8
    ctx->r2 = ctx->r4 < 0X8 ? 1 : 0;
    // 0x80095888: bne         $v0, $zero, L_80095858
    if (ctx->r2 != 0) {
        // 0x8009588C: addiu       $v1, $v1, 0xEF8
        ctx->r3 = ADD32(ctx->r3, 0XEF8);
            goto L_80095858;
    }
    // 0x8009588C: addiu       $v1, $v1, 0xEF8
    ctx->r3 = ADD32(ctx->r3, 0XEF8);
    // 0x80095890: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
L_80095894:
    // 0x80095894: addu        $s1, $a0, $zero
    ctx->r17 = ADD32(ctx->r4, 0);
    // 0x80095898: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x8009589C: beq         $s1, $v0, L_80095A78
    if (ctx->r17 == ctx->r2) {
        // 0x800958A0: nop
    
            goto L_80095A78;
    }
    // 0x800958A0: nop

    // 0x800958A4: bltz        $s1, L_80095A14
    if (SIGNED(ctx->r17) < 0) {
        // 0x800958A8: sll         $v0, $s1, 4
        ctx->r2 = S32(ctx->r17 << 4);
            goto L_80095A14;
    }
    // 0x800958A8: sll         $v0, $s1, 4
    ctx->r2 = S32(ctx->r17 << 4);
    // 0x800958AC: subu        $v0, $v0, $s1
    ctx->r2 = SUB32(ctx->r2, ctx->r17);
    // 0x800958B0: sll         $v0, $v0, 5
    ctx->r2 = S32(ctx->r2 << 5);
    // 0x800958B4: subu        $v0, $v0, $s1
    ctx->r2 = SUB32(ctx->r2, ctx->r17);
    // 0x800958B8: sll         $v1, $v0, 3
    ctx->r3 = S32(ctx->r2 << 3);
    // 0x800958BC: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x800958C0: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x800958C4: lbu         $v0, -0x5740($at)
    ctx->r2 = MEM_BU(ctx->r1, -0X5740);
    // 0x800958C8: beq         $v0, $zero, L_80095A78
    if (ctx->r2 == 0) {
        // 0x800958CC: nop
    
            goto L_80095A78;
    }
    // 0x800958CC: nop

    // 0x800958D0: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x800958D4: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x800958D8: lbu         $v0, -0x573F($at)
    ctx->r2 = MEM_BU(ctx->r1, -0X573F);
    // 0x800958DC: bne         $v0, $zero, L_80095A78
    if (ctx->r2 != 0) {
        // 0x800958E0: nop
    
            goto L_80095A78;
    }
    // 0x800958E0: nop

    // 0x800958E4: lui         $v0, 0x8015
    ctx->r2 = S32(0X8015 << 16);
    // 0x800958E8: addiu       $v0, $v0, -0x6600
    ctx->r2 = ADD32(ctx->r2, -0X6600);
    // 0x800958EC: addu        $s2, $v1, $v0
    ctx->r18 = ADD32(ctx->r3, ctx->r2);
    // 0x800958F0: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x800958F4: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x800958F8: sb          $zero, -0x5740($at)
    MEM_B(-0X5740, ctx->r1) = 0;
    // 0x800958FC: lw          $s0, 0xE78($s2)
    ctx->r16 = MEM_W(ctx->r18, 0XE78);
    // 0x80095900: beq         $s0, $zero, L_80095920
    if (ctx->r16 == 0) {
        // 0x80095904: nop
    
            goto L_80095920;
    }
    // 0x80095904: nop

L_80095908:
    // 0x80095908: lw          $a0, 0x8($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X8);
    // 0x8009590C: jal         0x8008DA98
    // 0x80095910: nop

    func_8008DA98(rdram, ctx);
        goto after_0;
    // 0x80095910: nop

    after_0:
    // 0x80095914: lw          $s0, 0x0($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X0);
    // 0x80095918: bne         $s0, $zero, L_80095908
    if (ctx->r16 != 0) {
        // 0x8009591C: nop
    
            goto L_80095908;
    }
    // 0x8009591C: nop

L_80095920:
    // 0x80095920: lw          $s0, 0xE7C($s2)
    ctx->r16 = MEM_W(ctx->r18, 0XE7C);
    // 0x80095924: beq         $s0, $zero, L_80095944
    if (ctx->r16 == 0) {
        // 0x80095928: sll         $v0, $s1, 4
        ctx->r2 = S32(ctx->r17 << 4);
            goto L_80095944;
    }
    // 0x80095928: sll         $v0, $s1, 4
    ctx->r2 = S32(ctx->r17 << 4);
L_8009592C:
    // 0x8009592C: lw          $a0, 0x8($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X8);
    // 0x80095930: jal         0x8008DA98
    // 0x80095934: nop

    func_8008DA98(rdram, ctx);
        goto after_1;
    // 0x80095934: nop

    after_1:
    // 0x80095938: lw          $s0, 0x0($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X0);
    // 0x8009593C: bne         $s0, $zero, L_8009592C
    if (ctx->r16 != 0) {
        // 0x80095940: sll         $v0, $s1, 4
        ctx->r2 = S32(ctx->r17 << 4);
            goto L_8009592C;
    }
    // 0x80095940: sll         $v0, $s1, 4
    ctx->r2 = S32(ctx->r17 << 4);
L_80095944:
    // 0x80095944: subu        $v0, $v0, $s1
    ctx->r2 = SUB32(ctx->r2, ctx->r17);
    // 0x80095948: sll         $v0, $v0, 5
    ctx->r2 = S32(ctx->r2 << 5);
    // 0x8009594C: subu        $v0, $v0, $s1
    ctx->r2 = SUB32(ctx->r2, ctx->r17);
    // 0x80095950: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x80095954: lui         $v1, 0x8015
    ctx->r3 = S32(0X8015 << 16);
    // 0x80095958: addiu       $v1, $v1, -0x6600
    ctx->r3 = ADD32(ctx->r3, -0X6600);
    // 0x8009595C: addu        $a0, $v0, $v1
    ctx->r4 = ADD32(ctx->r2, ctx->r3);
    // 0x80095960: lw          $v1, 0xE78($a0)
    ctx->r3 = MEM_W(ctx->r4, 0XE78);
    // 0x80095964: beq         $v1, $zero, L_800959B0
    if (ctx->r3 == 0) {
        // 0x80095968: nop
    
            goto L_800959B0;
    }
    // 0x80095968: nop

    // 0x8009596C: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80095970: beq         $v0, $zero, L_80095988
    if (ctx->r2 == 0) {
        // 0x80095974: nop
    
            goto L_80095988;
    }
    // 0x80095974: nop

L_80095978:
    // 0x80095978: lw          $v1, 0x0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X0);
    // 0x8009597C: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80095980: bne         $v0, $zero, L_80095978
    if (ctx->r2 != 0) {
        // 0x80095984: nop
    
            goto L_80095978;
    }
    // 0x80095984: nop

L_80095988:
    // 0x80095988: lui         $v0, 0x8015
    ctx->r2 = S32(0X8015 << 16);
    // 0x8009598C: lw          $v0, 0x29C4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X29C4);
    // 0x80095990: beq         $v0, $zero, L_800959A0
    if (ctx->r2 == 0) {
        // 0x80095994: nop
    
            goto L_800959A0;
    }
    // 0x80095994: nop

    // 0x80095998: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x8009599C: sw          $v1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r3;
L_800959A0:
    // 0x800959A0: lw          $v0, 0xE78($a0)
    ctx->r2 = MEM_W(ctx->r4, 0XE78);
    // 0x800959A4: sw          $zero, 0xE78($a0)
    MEM_W(0XE78, ctx->r4) = 0;
    // 0x800959A8: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x800959AC: sw          $v0, 0x29C4($at)
    MEM_W(0X29C4, ctx->r1) = ctx->r2;
L_800959B0:
    // 0x800959B0: lw          $v1, 0xE7C($a0)
    ctx->r3 = MEM_W(ctx->r4, 0XE7C);
    // 0x800959B4: beq         $v1, $zero, L_80095A78
    if (ctx->r3 == 0) {
        // 0x800959B8: nop
    
            goto L_80095A78;
    }
    // 0x800959B8: nop

    // 0x800959BC: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x800959C0: beq         $v0, $zero, L_800959D8
    if (ctx->r2 == 0) {
        // 0x800959C4: nop
    
            goto L_800959D8;
    }
    // 0x800959C4: nop

L_800959C8:
    // 0x800959C8: lw          $v1, 0x0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X0);
    // 0x800959CC: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x800959D0: bne         $v0, $zero, L_800959C8
    if (ctx->r2 != 0) {
        // 0x800959D4: nop
    
            goto L_800959C8;
    }
    // 0x800959D4: nop

L_800959D8:
    // 0x800959D8: lui         $v0, 0x8015
    ctx->r2 = S32(0X8015 << 16);
    // 0x800959DC: lw          $v0, 0x29C4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X29C4);
    // 0x800959E0: beq         $v0, $zero, L_800959F0
    if (ctx->r2 == 0) {
        // 0x800959E4: nop
    
            goto L_800959F0;
    }
    // 0x800959E4: nop

    // 0x800959E8: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x800959EC: sw          $v1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r3;
L_800959F0:
    // 0x800959F0: lw          $v0, 0xE7C($a0)
    ctx->r2 = MEM_W(ctx->r4, 0XE7C);
    // 0x800959F4: sw          $zero, 0xE7C($a0)
    MEM_W(0XE7C, ctx->r4) = 0;
    // 0x800959F8: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x800959FC: sw          $v0, 0x29C4($at)
    MEM_W(0X29C4, ctx->r1) = ctx->r2;
    // 0x80095A00: j           L_80095A78
    // 0x80095A04: nop

        goto L_80095A78;
    // 0x80095A04: nop

L_80095A08:
    // 0x80095A08: and         $v0, $s1, $v0
    ctx->r2 = ctx->r17 & ctx->r2;
    // 0x80095A0C: j           L_80095894
    // 0x80095A10: or          $a0, $a0, $v0
    ctx->r4 = ctx->r4 | ctx->r2;
        goto L_80095894;
    // 0x80095A10: or          $a0, $a0, $v0
    ctx->r4 = ctx->r4 | ctx->r2;
L_80095A14:
    // 0x80095A14: lui         $v0, 0x7FFF
    ctx->r2 = S32(0X7FFF << 16);
    // 0x80095A18: ori         $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 | 0XFFFF;
    // 0x80095A1C: and         $s1, $s1, $v0
    ctx->r17 = ctx->r17 & ctx->r2;
    // 0x80095A20: sll         $v0, $s1, 4
    ctx->r2 = S32(ctx->r17 << 4);
    // 0x80095A24: subu        $v0, $v0, $s1
    ctx->r2 = SUB32(ctx->r2, ctx->r17);
    // 0x80095A28: sll         $v0, $v0, 5
    ctx->r2 = S32(ctx->r2 << 5);
    // 0x80095A2C: subu        $v0, $v0, $s1
    ctx->r2 = SUB32(ctx->r2, ctx->r17);
    // 0x80095A30: sll         $v1, $v0, 3
    ctx->r3 = S32(ctx->r2 << 3);
    // 0x80095A34: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80095A38: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x80095A3C: lbu         $v0, -0x5740($at)
    ctx->r2 = MEM_BU(ctx->r1, -0X5740);
    // 0x80095A40: beq         $v0, $zero, L_80095A78
    if (ctx->r2 == 0) {
        // 0x80095A44: nop
    
            goto L_80095A78;
    }
    // 0x80095A44: nop

    // 0x80095A48: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80095A4C: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x80095A50: lbu         $v0, -0x573F($at)
    ctx->r2 = MEM_BU(ctx->r1, -0X573F);
    // 0x80095A54: bne         $v0, $zero, L_80095A78
    if (ctx->r2 != 0) {
        // 0x80095A58: nop
    
            goto L_80095A78;
    }
    // 0x80095A58: nop

    // 0x80095A5C: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80095A60: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x80095A64: lbu         $v0, -0x5712($at)
    ctx->r2 = MEM_BU(ctx->r1, -0X5712);
    // 0x80095A68: ori         $v0, $v0, 0x8
    ctx->r2 = ctx->r2 | 0X8;
    // 0x80095A6C: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80095A70: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x80095A74: sb          $v0, -0x5712($at)
    MEM_B(-0X5712, ctx->r1) = ctx->r2;
L_80095A78:
    // 0x80095A78: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80095A7C: lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X18);
    // 0x80095A80: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x80095A84: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x80095A88: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80095A8C: jr          $ra
    // 0x80095A90: nop

    return;
    // 0x80095A90: nop

;}
RECOMP_FUNC void func_80095A94(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80095A94: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x80095A98: lbu         $v0, 0xF50($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0XF50);
    // 0x80095A9C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80095AA0: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x80095AA4: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x80095AA8: beq         $v0, $zero, L_80095AC8
    if (ctx->r2 == 0) {
        // 0x80095AAC: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_80095AC8;
    }
    // 0x80095AAC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80095AB0: jal         0x80092010
    // 0x80095AB4: nop

    factor5MutexAcquire(rdram, ctx);
        goto after_0;
    // 0x80095AB4: nop

    after_0:
    // 0x80095AB8: jal         0x8009582C
    // 0x80095ABC: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_8009582C(rdram, ctx);
        goto after_1;
    // 0x80095ABC: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_1:
    // 0x80095AC0: jal         0x8009205C
    // 0x80095AC4: nop

    factor5MutexRelease(rdram, ctx);
        goto after_2;
    // 0x80095AC4: nop

    after_2:
L_80095AC8:
    // 0x80095AC8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80095ACC: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x80095AD0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80095AD4: jr          $ra
    // 0x80095AD8: nop

    return;
    // 0x80095AD8: nop

;}
RECOMP_FUNC void func_80095ADC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80095ADC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80095AE0: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x80095AE4: addu        $s1, $a0, $zero
    ctx->r17 = ADD32(ctx->r4, 0);
    // 0x80095AE8: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x80095AEC: lui         $v0, 0x7FFF
    ctx->r2 = S32(0X7FFF << 16);
    // 0x80095AF0: ori         $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 | 0XFFFF;
    // 0x80095AF4: and         $a1, $s1, $v0
    ctx->r5 = ctx->r17 & ctx->r2;
    // 0x80095AF8: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
    // 0x80095AFC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80095B00: sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // 0x80095B04: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
L_80095B08:
    // 0x80095B08: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80095B0C: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x80095B10: lbu         $v0, -0x573F($at)
    ctx->r2 = MEM_BU(ctx->r1, -0X573F);
    // 0x80095B14: bnel        $v0, $zero, L_80095B34
    if (ctx->r2 != 0) {
        // 0x80095B18: addiu       $a0, $a0, 0x1
        ctx->r4 = ADD32(ctx->r4, 0X1);
            goto L_80095B34;
    }
    goto skip_0;
    // 0x80095B18: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    skip_0:
    // 0x80095B1C: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80095B20: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x80095B24: lw          $v0, -0x6600($at)
    ctx->r2 = MEM_W(ctx->r1, -0X6600);
    // 0x80095B28: beq         $v0, $a1, L_80095CDC
    if (ctx->r2 == ctx->r5) {
        // 0x80095B2C: lui         $v0, 0x8000
        ctx->r2 = S32(0X8000 << 16);
            goto L_80095CDC;
    }
    // 0x80095B2C: lui         $v0, 0x8000
    ctx->r2 = S32(0X8000 << 16);
    // 0x80095B30: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
L_80095B34:
    // 0x80095B34: sltiu       $v0, $a0, 0x8
    ctx->r2 = ctx->r4 < 0X8 ? 1 : 0;
    // 0x80095B38: bne         $v0, $zero, L_80095B08
    if (ctx->r2 != 0) {
        // 0x80095B3C: addiu       $v1, $v1, 0xEF8
        ctx->r3 = ADD32(ctx->r3, 0XEF8);
            goto L_80095B08;
    }
    // 0x80095B3C: addiu       $v1, $v1, 0xEF8
    ctx->r3 = ADD32(ctx->r3, 0XEF8);
    // 0x80095B40: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
L_80095B44:
    // 0x80095B44: addu        $s1, $a0, $zero
    ctx->r17 = ADD32(ctx->r4, 0);
    // 0x80095B48: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x80095B4C: beq         $s1, $v0, L_80095D3C
    if (ctx->r17 == ctx->r2) {
        // 0x80095B50: nop
    
            goto L_80095D3C;
    }
    // 0x80095B50: nop

    // 0x80095B54: bltz        $s1, L_80095CE8
    if (SIGNED(ctx->r17) < 0) {
        // 0x80095B58: sll         $v0, $s1, 4
        ctx->r2 = S32(ctx->r17 << 4);
            goto L_80095CE8;
    }
    // 0x80095B58: sll         $v0, $s1, 4
    ctx->r2 = S32(ctx->r17 << 4);
    // 0x80095B5C: subu        $v0, $v0, $s1
    ctx->r2 = SUB32(ctx->r2, ctx->r17);
    // 0x80095B60: sll         $v0, $v0, 5
    ctx->r2 = S32(ctx->r2 << 5);
    // 0x80095B64: subu        $v0, $v0, $s1
    ctx->r2 = SUB32(ctx->r2, ctx->r17);
    // 0x80095B68: sll         $v1, $v0, 3
    ctx->r3 = S32(ctx->r2 << 3);
    // 0x80095B6C: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80095B70: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x80095B74: lbu         $v0, -0x5740($at)
    ctx->r2 = MEM_BU(ctx->r1, -0X5740);
    // 0x80095B78: beq         $v0, $zero, L_80095CB4
    if (ctx->r2 == 0) {
        // 0x80095B7C: sll         $v0, $s1, 4
        ctx->r2 = S32(ctx->r17 << 4);
            goto L_80095CB4;
    }
    // 0x80095B7C: sll         $v0, $s1, 4
    ctx->r2 = S32(ctx->r17 << 4);
    // 0x80095B80: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80095B84: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x80095B88: lbu         $v0, -0x573F($at)
    ctx->r2 = MEM_BU(ctx->r1, -0X573F);
    // 0x80095B8C: bne         $v0, $zero, L_80095CB4
    if (ctx->r2 != 0) {
        // 0x80095B90: sll         $v0, $s1, 4
        ctx->r2 = S32(ctx->r17 << 4);
            goto L_80095CB4;
    }
    // 0x80095B90: sll         $v0, $s1, 4
    ctx->r2 = S32(ctx->r17 << 4);
    // 0x80095B94: lui         $v0, 0x8015
    ctx->r2 = S32(0X8015 << 16);
    // 0x80095B98: addiu       $v0, $v0, -0x6600
    ctx->r2 = ADD32(ctx->r2, -0X6600);
    // 0x80095B9C: addu        $s2, $v1, $v0
    ctx->r18 = ADD32(ctx->r3, ctx->r2);
    // 0x80095BA0: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80095BA4: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x80095BA8: sb          $zero, -0x5740($at)
    MEM_B(-0X5740, ctx->r1) = 0;
    // 0x80095BAC: lw          $s0, 0xE78($s2)
    ctx->r16 = MEM_W(ctx->r18, 0XE78);
    // 0x80095BB0: beq         $s0, $zero, L_80095BD0
    if (ctx->r16 == 0) {
        // 0x80095BB4: nop
    
            goto L_80095BD0;
    }
    // 0x80095BB4: nop

L_80095BB8:
    // 0x80095BB8: lw          $a0, 0x8($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X8);
    // 0x80095BBC: jal         0x8008DA98
    // 0x80095BC0: nop

    func_8008DA98(rdram, ctx);
        goto after_0;
    // 0x80095BC0: nop

    after_0:
    // 0x80095BC4: lw          $s0, 0x0($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X0);
    // 0x80095BC8: bne         $s0, $zero, L_80095BB8
    if (ctx->r16 != 0) {
        // 0x80095BCC: nop
    
            goto L_80095BB8;
    }
    // 0x80095BCC: nop

L_80095BD0:
    // 0x80095BD0: lw          $s0, 0xE7C($s2)
    ctx->r16 = MEM_W(ctx->r18, 0XE7C);
    // 0x80095BD4: beq         $s0, $zero, L_80095BF4
    if (ctx->r16 == 0) {
        // 0x80095BD8: sll         $v0, $s1, 4
        ctx->r2 = S32(ctx->r17 << 4);
            goto L_80095BF4;
    }
    // 0x80095BD8: sll         $v0, $s1, 4
    ctx->r2 = S32(ctx->r17 << 4);
L_80095BDC:
    // 0x80095BDC: lw          $a0, 0x8($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X8);
    // 0x80095BE0: jal         0x8008DA98
    // 0x80095BE4: nop

    func_8008DA98(rdram, ctx);
        goto after_1;
    // 0x80095BE4: nop

    after_1:
    // 0x80095BE8: lw          $s0, 0x0($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X0);
    // 0x80095BEC: bne         $s0, $zero, L_80095BDC
    if (ctx->r16 != 0) {
        // 0x80095BF0: sll         $v0, $s1, 4
        ctx->r2 = S32(ctx->r17 << 4);
            goto L_80095BDC;
    }
    // 0x80095BF0: sll         $v0, $s1, 4
    ctx->r2 = S32(ctx->r17 << 4);
L_80095BF4:
    // 0x80095BF4: subu        $v0, $v0, $s1
    ctx->r2 = SUB32(ctx->r2, ctx->r17);
    // 0x80095BF8: sll         $v0, $v0, 5
    ctx->r2 = S32(ctx->r2 << 5);
    // 0x80095BFC: subu        $v0, $v0, $s1
    ctx->r2 = SUB32(ctx->r2, ctx->r17);
    // 0x80095C00: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x80095C04: lui         $v1, 0x8015
    ctx->r3 = S32(0X8015 << 16);
    // 0x80095C08: addiu       $v1, $v1, -0x6600
    ctx->r3 = ADD32(ctx->r3, -0X6600);
    // 0x80095C0C: addu        $a0, $v0, $v1
    ctx->r4 = ADD32(ctx->r2, ctx->r3);
    // 0x80095C10: lw          $v1, 0xE78($a0)
    ctx->r3 = MEM_W(ctx->r4, 0XE78);
    // 0x80095C14: beq         $v1, $zero, L_80095C60
    if (ctx->r3 == 0) {
        // 0x80095C18: nop
    
            goto L_80095C60;
    }
    // 0x80095C18: nop

    // 0x80095C1C: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80095C20: beq         $v0, $zero, L_80095C38
    if (ctx->r2 == 0) {
        // 0x80095C24: nop
    
            goto L_80095C38;
    }
    // 0x80095C24: nop

L_80095C28:
    // 0x80095C28: lw          $v1, 0x0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X0);
    // 0x80095C2C: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80095C30: bne         $v0, $zero, L_80095C28
    if (ctx->r2 != 0) {
        // 0x80095C34: nop
    
            goto L_80095C28;
    }
    // 0x80095C34: nop

L_80095C38:
    // 0x80095C38: lui         $v0, 0x8015
    ctx->r2 = S32(0X8015 << 16);
    // 0x80095C3C: lw          $v0, 0x29C4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X29C4);
    // 0x80095C40: beq         $v0, $zero, L_80095C50
    if (ctx->r2 == 0) {
        // 0x80095C44: nop
    
            goto L_80095C50;
    }
    // 0x80095C44: nop

    // 0x80095C48: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x80095C4C: sw          $v1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r3;
L_80095C50:
    // 0x80095C50: lw          $v0, 0xE78($a0)
    ctx->r2 = MEM_W(ctx->r4, 0XE78);
    // 0x80095C54: sw          $zero, 0xE78($a0)
    MEM_W(0XE78, ctx->r4) = 0;
    // 0x80095C58: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80095C5C: sw          $v0, 0x29C4($at)
    MEM_W(0X29C4, ctx->r1) = ctx->r2;
L_80095C60:
    // 0x80095C60: lw          $v1, 0xE7C($a0)
    ctx->r3 = MEM_W(ctx->r4, 0XE7C);
    // 0x80095C64: beq         $v1, $zero, L_80095CB4
    if (ctx->r3 == 0) {
        // 0x80095C68: sll         $v0, $s1, 4
        ctx->r2 = S32(ctx->r17 << 4);
            goto L_80095CB4;
    }
    // 0x80095C68: sll         $v0, $s1, 4
    ctx->r2 = S32(ctx->r17 << 4);
    // 0x80095C6C: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80095C70: beq         $v0, $zero, L_80095C88
    if (ctx->r2 == 0) {
        // 0x80095C74: nop
    
            goto L_80095C88;
    }
    // 0x80095C74: nop

L_80095C78:
    // 0x80095C78: lw          $v1, 0x0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X0);
    // 0x80095C7C: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80095C80: bne         $v0, $zero, L_80095C78
    if (ctx->r2 != 0) {
        // 0x80095C84: nop
    
            goto L_80095C78;
    }
    // 0x80095C84: nop

L_80095C88:
    // 0x80095C88: lui         $v0, 0x8015
    ctx->r2 = S32(0X8015 << 16);
    // 0x80095C8C: lw          $v0, 0x29C4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X29C4);
    // 0x80095C90: beq         $v0, $zero, L_80095CA0
    if (ctx->r2 == 0) {
        // 0x80095C94: nop
    
            goto L_80095CA0;
    }
    // 0x80095C94: nop

    // 0x80095C98: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x80095C9C: sw          $v1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r3;
L_80095CA0:
    // 0x80095CA0: lw          $v0, 0xE7C($a0)
    ctx->r2 = MEM_W(ctx->r4, 0XE7C);
    // 0x80095CA4: sw          $zero, 0xE7C($a0)
    MEM_W(0XE7C, ctx->r4) = 0;
    // 0x80095CA8: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80095CAC: sw          $v0, 0x29C4($at)
    MEM_W(0X29C4, ctx->r1) = ctx->r2;
    // 0x80095CB0: sll         $v0, $s1, 4
    ctx->r2 = S32(ctx->r17 << 4);
L_80095CB4:
    // 0x80095CB4: subu        $v0, $v0, $s1
    ctx->r2 = SUB32(ctx->r2, ctx->r17);
    // 0x80095CB8: sll         $v0, $v0, 5
    ctx->r2 = S32(ctx->r2 << 5);
    // 0x80095CBC: subu        $v0, $v0, $s1
    ctx->r2 = SUB32(ctx->r2, ctx->r17);
    // 0x80095CC0: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x80095CC4: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x80095CC8: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80095CCC: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80095CD0: sb          $v1, -0x573F($at)
    MEM_B(-0X573F, ctx->r1) = ctx->r3;
    // 0x80095CD4: j           L_80095D3C
    // 0x80095CD8: nop

        goto L_80095D3C;
    // 0x80095CD8: nop

L_80095CDC:
    // 0x80095CDC: and         $v0, $s1, $v0
    ctx->r2 = ctx->r17 & ctx->r2;
    // 0x80095CE0: j           L_80095B44
    // 0x80095CE4: or          $a0, $a0, $v0
    ctx->r4 = ctx->r4 | ctx->r2;
        goto L_80095B44;
    // 0x80095CE4: or          $a0, $a0, $v0
    ctx->r4 = ctx->r4 | ctx->r2;
L_80095CE8:
    // 0x80095CE8: lui         $v0, 0x7FFF
    ctx->r2 = S32(0X7FFF << 16);
    // 0x80095CEC: ori         $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 | 0XFFFF;
    // 0x80095CF0: and         $s1, $s1, $v0
    ctx->r17 = ctx->r17 & ctx->r2;
    // 0x80095CF4: sll         $v0, $s1, 4
    ctx->r2 = S32(ctx->r17 << 4);
    // 0x80095CF8: subu        $v0, $v0, $s1
    ctx->r2 = SUB32(ctx->r2, ctx->r17);
    // 0x80095CFC: sll         $v0, $v0, 5
    ctx->r2 = S32(ctx->r2 << 5);
    // 0x80095D00: subu        $v0, $v0, $s1
    ctx->r2 = SUB32(ctx->r2, ctx->r17);
    // 0x80095D04: sll         $v1, $v0, 3
    ctx->r3 = S32(ctx->r2 << 3);
    // 0x80095D08: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80095D0C: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x80095D10: lbu         $v0, -0x5740($at)
    ctx->r2 = MEM_BU(ctx->r1, -0X5740);
    // 0x80095D14: beq         $v0, $zero, L_80095D3C
    if (ctx->r2 == 0) {
        // 0x80095D18: nop
    
            goto L_80095D3C;
    }
    // 0x80095D18: nop

    // 0x80095D1C: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80095D20: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x80095D24: lbu         $v0, -0x573F($at)
    ctx->r2 = MEM_BU(ctx->r1, -0X573F);
    // 0x80095D28: bne         $v0, $zero, L_80095D3C
    if (ctx->r2 != 0) {
        // 0x80095D2C: nop
    
            goto L_80095D3C;
    }
    // 0x80095D2C: nop

    // 0x80095D30: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80095D34: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x80095D38: sw          $zero, -0x5710($at)
    MEM_W(-0X5710, ctx->r1) = 0;
L_80095D3C:
    // 0x80095D3C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80095D40: lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X18);
    // 0x80095D44: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x80095D48: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x80095D4C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80095D50: jr          $ra
    // 0x80095D54: nop

    return;
    // 0x80095D54: nop

;}
RECOMP_FUNC void func_80095D58(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80095D58: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x80095D5C: lbu         $v0, 0xF50($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0XF50);
    // 0x80095D60: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80095D64: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x80095D68: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x80095D6C: beq         $v0, $zero, L_80095D8C
    if (ctx->r2 == 0) {
        // 0x80095D70: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_80095D8C;
    }
    // 0x80095D70: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80095D74: jal         0x80092010
    // 0x80095D78: nop

    factor5MutexAcquire(rdram, ctx);
        goto after_0;
    // 0x80095D78: nop

    after_0:
    // 0x80095D7C: jal         0x80095ADC
    // 0x80095D80: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_80095ADC(rdram, ctx);
        goto after_1;
    // 0x80095D80: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_1:
    // 0x80095D84: jal         0x8009205C
    // 0x80095D88: nop

    factor5MutexRelease(rdram, ctx);
        goto after_2;
    // 0x80095D88: nop

    after_2:
L_80095D8C:
    // 0x80095D8C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80095D90: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x80095D94: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80095D98: jr          $ra
    // 0x80095D9C: nop

    return;
    // 0x80095D9C: nop

;}
RECOMP_FUNC void func_80095DA0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80095DA0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80095DA4: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x80095DA8: addu        $s1, $zero, $zero
    ctx->r17 = ADD32(0, 0);
    // 0x80095DAC: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x80095DB0: addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
    // 0x80095DB4: sw          $ra, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r31;
L_80095DB8:
    // 0x80095DB8: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80095DBC: addu        $at, $at, $s0
    ctx->r1 = ADD32(ctx->r1, ctx->r16);
    // 0x80095DC0: lw          $a0, -0x6600($at)
    ctx->r4 = MEM_W(ctx->r1, -0X6600);
    // 0x80095DC4: addiu       $s0, $s0, 0xEF8
    ctx->r16 = ADD32(ctx->r16, 0XEF8);
    // 0x80095DC8: jal         0x80095ADC
    // 0x80095DCC: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    func_80095ADC(rdram, ctx);
        goto after_0;
    // 0x80095DCC: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    after_0:
    // 0x80095DD0: sltiu       $v0, $s1, 0x8
    ctx->r2 = ctx->r17 < 0X8 ? 1 : 0;
    // 0x80095DD4: bne         $v0, $zero, L_80095DB8
    if (ctx->r2 != 0) {
        // 0x80095DD8: nop
    
            goto L_80095DB8;
    }
    // 0x80095DD8: nop

    // 0x80095DDC: lw          $ra, 0x18($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X18);
    // 0x80095DE0: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x80095DE4: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x80095DE8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80095DEC: jr          $ra
    // 0x80095DF0: nop

    return;
    // 0x80095DF0: nop

;}
RECOMP_FUNC void func_80095DF4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80095DF4: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x80095DF8: lbu         $v0, 0xF50($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0XF50);
    // 0x80095DFC: beq         $v0, $zero, L_80095E9C
    if (ctx->r2 == 0) {
        // 0x80095E00: addu        $a3, $zero, $zero
        ctx->r7 = ADD32(0, 0);
            goto L_80095E9C;
    }
    // 0x80095E00: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    // 0x80095E04: lui         $v0, 0x7FFF
    ctx->r2 = S32(0X7FFF << 16);
    // 0x80095E08: ori         $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 | 0XFFFF;
    // 0x80095E0C: and         $t0, $a0, $v0
    ctx->r8 = ctx->r4 & ctx->r2;
    // 0x80095E10: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
L_80095E14:
    // 0x80095E14: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80095E18: addu        $at, $at, $a2
    ctx->r1 = ADD32(ctx->r1, ctx->r6);
    // 0x80095E1C: lbu         $v0, -0x573F($at)
    ctx->r2 = MEM_BU(ctx->r1, -0X573F);
    // 0x80095E20: bnel        $v0, $zero, L_80095E40
    if (ctx->r2 != 0) {
        // 0x80095E24: addiu       $a3, $a3, 0x1
        ctx->r7 = ADD32(ctx->r7, 0X1);
            goto L_80095E40;
    }
    goto skip_0;
    // 0x80095E24: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    skip_0:
    // 0x80095E28: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80095E2C: addu        $at, $at, $a2
    ctx->r1 = ADD32(ctx->r1, ctx->r6);
    // 0x80095E30: lw          $v0, -0x6600($at)
    ctx->r2 = MEM_W(ctx->r1, -0X6600);
    // 0x80095E34: beq         $v0, $t0, L_80095E90
    if (ctx->r2 == ctx->r8) {
        // 0x80095E38: lui         $v0, 0x8000
        ctx->r2 = S32(0X8000 << 16);
            goto L_80095E90;
    }
    // 0x80095E38: lui         $v0, 0x8000
    ctx->r2 = S32(0X8000 << 16);
    // 0x80095E3C: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
L_80095E40:
    // 0x80095E40: sltiu       $v0, $a3, 0x8
    ctx->r2 = ctx->r7 < 0X8 ? 1 : 0;
    // 0x80095E44: bne         $v0, $zero, L_80095E14
    if (ctx->r2 != 0) {
        // 0x80095E48: addiu       $a2, $a2, 0xEF8
        ctx->r6 = ADD32(ctx->r6, 0XEF8);
            goto L_80095E14;
    }
    // 0x80095E48: addiu       $a2, $a2, 0xEF8
    ctx->r6 = ADD32(ctx->r6, 0XEF8);
    // 0x80095E4C: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
L_80095E50:
    // 0x80095E50: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x80095E54: beql        $a0, $v0, L_80095EA0
    if (ctx->r4 == ctx->r2) {
        // 0x80095E58: addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
            goto L_80095EA0;
    }
    goto skip_1;
    // 0x80095E58: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    skip_1:
    // 0x80095E5C: bltz        $a0, L_80095E9C
    if (SIGNED(ctx->r4) < 0) {
        // 0x80095E60: sll         $v0, $a0, 4
        ctx->r2 = S32(ctx->r4 << 4);
            goto L_80095E9C;
    }
    // 0x80095E60: sll         $v0, $a0, 4
    ctx->r2 = S32(ctx->r4 << 4);
    // 0x80095E64: subu        $v0, $v0, $a0
    ctx->r2 = SUB32(ctx->r2, ctx->r4);
    // 0x80095E68: sll         $v0, $v0, 5
    ctx->r2 = S32(ctx->r2 << 5);
    // 0x80095E6C: subu        $v0, $v0, $a0
    ctx->r2 = SUB32(ctx->r2, ctx->r4);
    // 0x80095E70: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x80095E74: andi        $v1, $a1, 0xFF
    ctx->r3 = ctx->r5 & 0XFF;
    // 0x80095E78: sltiu       $v1, $v1, 0x1
    ctx->r3 = ctx->r3 < 0X1 ? 1 : 0;
    // 0x80095E7C: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80095E80: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80095E84: sb          $v1, -0x573B($at)
    MEM_B(-0X573B, ctx->r1) = ctx->r3;
    // 0x80095E88: j           L_80095EA0
    // 0x80095E8C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80095EA0;
    // 0x80095E8C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80095E90:
    // 0x80095E90: and         $v0, $a0, $v0
    ctx->r2 = ctx->r4 & ctx->r2;
    // 0x80095E94: j           L_80095E50
    // 0x80095E98: or          $a0, $a3, $v0
    ctx->r4 = ctx->r7 | ctx->r2;
        goto L_80095E50;
    // 0x80095E98: or          $a0, $a3, $v0
    ctx->r4 = ctx->r7 | ctx->r2;
L_80095E9C:
    // 0x80095E9C: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_80095EA0:
    // 0x80095EA0: jr          $ra
    // 0x80095EA4: nop

    return;
    // 0x80095EA4: nop

;}
RECOMP_FUNC void func_80095EA8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80095EA8: addu        $a2, $a0, $zero
    ctx->r6 = ADD32(ctx->r4, 0);
    // 0x80095EAC: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x80095EB0: lui         $v0, 0x7FFF
    ctx->r2 = S32(0X7FFF << 16);
    // 0x80095EB4: ori         $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 | 0XFFFF;
    // 0x80095EB8: and         $a3, $a2, $v0
    ctx->r7 = ctx->r6 & ctx->r2;
    // 0x80095EBC: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
L_80095EC0:
    // 0x80095EC0: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80095EC4: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x80095EC8: lbu         $v0, -0x573F($at)
    ctx->r2 = MEM_BU(ctx->r1, -0X573F);
    // 0x80095ECC: bnel        $v0, $zero, L_80095EEC
    if (ctx->r2 != 0) {
        // 0x80095ED0: addiu       $a0, $a0, 0x1
        ctx->r4 = ADD32(ctx->r4, 0X1);
            goto L_80095EEC;
    }
    goto skip_0;
    // 0x80095ED0: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    skip_0:
    // 0x80095ED4: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80095ED8: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x80095EDC: lw          $v0, -0x6600($at)
    ctx->r2 = MEM_W(ctx->r1, -0X6600);
    // 0x80095EE0: beq         $v0, $a3, L_80095F38
    if (ctx->r2 == ctx->r7) {
        // 0x80095EE4: lui         $v0, 0x8000
        ctx->r2 = S32(0X8000 << 16);
            goto L_80095F38;
    }
    // 0x80095EE4: lui         $v0, 0x8000
    ctx->r2 = S32(0X8000 << 16);
    // 0x80095EE8: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
L_80095EEC:
    // 0x80095EEC: sltiu       $v0, $a0, 0x8
    ctx->r2 = ctx->r4 < 0X8 ? 1 : 0;
    // 0x80095EF0: bne         $v0, $zero, L_80095EC0
    if (ctx->r2 != 0) {
        // 0x80095EF4: addiu       $v1, $v1, 0xEF8
        ctx->r3 = ADD32(ctx->r3, 0XEF8);
            goto L_80095EC0;
    }
    // 0x80095EF4: addiu       $v1, $v1, 0xEF8
    ctx->r3 = ADD32(ctx->r3, 0XEF8);
    // 0x80095EF8: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
L_80095EFC:
    // 0x80095EFC: addu        $a2, $a0, $zero
    ctx->r6 = ADD32(ctx->r4, 0);
    // 0x80095F00: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x80095F04: beq         $a2, $v0, L_80095F8C
    if (ctx->r6 == ctx->r2) {
        // 0x80095F08: nop
    
            goto L_80095F8C;
    }
    // 0x80095F08: nop

    // 0x80095F0C: bltz        $a2, L_80095F44
    if (SIGNED(ctx->r6) < 0) {
        // 0x80095F10: sll         $v0, $a2, 4
        ctx->r2 = S32(ctx->r6 << 4);
            goto L_80095F44;
    }
    // 0x80095F10: sll         $v0, $a2, 4
    ctx->r2 = S32(ctx->r6 << 4);
    // 0x80095F14: subu        $v0, $v0, $a2
    ctx->r2 = SUB32(ctx->r2, ctx->r6);
    // 0x80095F18: sll         $v0, $v0, 5
    ctx->r2 = S32(ctx->r2 << 5);
    // 0x80095F1C: subu        $v0, $v0, $a2
    ctx->r2 = SUB32(ctx->r2, ctx->r6);
    // 0x80095F20: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x80095F24: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80095F28: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80095F2C: sh          $a1, -0x573E($at)
    MEM_H(-0X573E, ctx->r1) = ctx->r5;
    // 0x80095F30: j           L_80095F8C
    // 0x80095F34: nop

        goto L_80095F8C;
    // 0x80095F34: nop

L_80095F38:
    // 0x80095F38: and         $v0, $a2, $v0
    ctx->r2 = ctx->r6 & ctx->r2;
    // 0x80095F3C: j           L_80095EFC
    // 0x80095F40: or          $a0, $a0, $v0
    ctx->r4 = ctx->r4 | ctx->r2;
        goto L_80095EFC;
    // 0x80095F40: or          $a0, $a0, $v0
    ctx->r4 = ctx->r4 | ctx->r2;
L_80095F44:
    // 0x80095F44: lui         $v0, 0x7FFF
    ctx->r2 = S32(0X7FFF << 16);
    // 0x80095F48: ori         $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 | 0XFFFF;
    // 0x80095F4C: and         $a2, $a2, $v0
    ctx->r6 = ctx->r6 & ctx->r2;
    // 0x80095F50: sll         $v0, $a2, 4
    ctx->r2 = S32(ctx->r6 << 4);
    // 0x80095F54: subu        $v0, $v0, $a2
    ctx->r2 = SUB32(ctx->r2, ctx->r6);
    // 0x80095F58: sll         $v0, $v0, 5
    ctx->r2 = S32(ctx->r2 << 5);
    // 0x80095F5C: subu        $v0, $v0, $a2
    ctx->r2 = SUB32(ctx->r2, ctx->r6);
    // 0x80095F60: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x80095F64: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80095F68: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80095F6C: lbu         $v1, -0x5712($at)
    ctx->r3 = MEM_BU(ctx->r1, -0X5712);
    // 0x80095F70: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80095F74: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80095F78: sh          $a1, -0x5714($at)
    MEM_H(-0X5714, ctx->r1) = ctx->r5;
    // 0x80095F7C: ori         $v1, $v1, 0x20
    ctx->r3 = ctx->r3 | 0X20;
    // 0x80095F80: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80095F84: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80095F88: sb          $v1, -0x5712($at)
    MEM_B(-0X5712, ctx->r1) = ctx->r3;
L_80095F8C:
    // 0x80095F8C: jr          $ra
    // 0x80095F90: nop

    return;
    // 0x80095F90: nop

;}
RECOMP_FUNC void func_80095F94(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80095F94: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x80095F98: lbu         $v0, 0xF50($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0XF50);
    // 0x80095F9C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80095FA0: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x80095FA4: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x80095FA8: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x80095FAC: addu        $s1, $a1, $zero
    ctx->r17 = ADD32(ctx->r5, 0);
    // 0x80095FB0: beq         $v0, $zero, L_80095FD4
    if (ctx->r2 == 0) {
        // 0x80095FB4: sw          $ra, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r31;
            goto L_80095FD4;
    }
    // 0x80095FB4: sw          $ra, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r31;
    // 0x80095FB8: jal         0x80092010
    // 0x80095FBC: nop

    factor5MutexAcquire(rdram, ctx);
        goto after_0;
    // 0x80095FBC: nop

    after_0:
    // 0x80095FC0: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x80095FC4: jal         0x80095EA8
    // 0x80095FC8: andi        $a1, $s1, 0xFFFF
    ctx->r5 = ctx->r17 & 0XFFFF;
    func_80095EA8(rdram, ctx);
        goto after_1;
    // 0x80095FC8: andi        $a1, $s1, 0xFFFF
    ctx->r5 = ctx->r17 & 0XFFFF;
    after_1:
    // 0x80095FCC: jal         0x8009205C
    // 0x80095FD0: nop

    factor5MutexRelease(rdram, ctx);
        goto after_2;
    // 0x80095FD0: nop

    after_2:
L_80095FD4:
    // 0x80095FD4: lw          $ra, 0x18($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X18);
    // 0x80095FD8: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x80095FDC: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x80095FE0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80095FE4: jr          $ra
    // 0x80095FE8: nop

    return;
    // 0x80095FE8: nop

;}
RECOMP_FUNC void func_80095FEC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80095FEC: addu        $a1, $a0, $zero
    ctx->r5 = ADD32(ctx->r4, 0);
    // 0x80095FF0: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x80095FF4: lui         $v0, 0x7FFF
    ctx->r2 = S32(0X7FFF << 16);
    // 0x80095FF8: ori         $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 | 0XFFFF;
    // 0x80095FFC: and         $a2, $a1, $v0
    ctx->r6 = ctx->r5 & ctx->r2;
    // 0x80096000: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
L_80096004:
    // 0x80096004: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80096008: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x8009600C: lbu         $v0, -0x573F($at)
    ctx->r2 = MEM_BU(ctx->r1, -0X573F);
    // 0x80096010: bnel        $v0, $zero, L_80096030
    if (ctx->r2 != 0) {
        // 0x80096014: addiu       $a0, $a0, 0x1
        ctx->r4 = ADD32(ctx->r4, 0X1);
            goto L_80096030;
    }
    goto skip_0;
    // 0x80096014: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    skip_0:
    // 0x80096018: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8009601C: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x80096020: lw          $v0, -0x6600($at)
    ctx->r2 = MEM_W(ctx->r1, -0X6600);
    // 0x80096024: beq         $v0, $a2, L_80096080
    if (ctx->r2 == ctx->r6) {
        // 0x80096028: lui         $v0, 0x8000
        ctx->r2 = S32(0X8000 << 16);
            goto L_80096080;
    }
    // 0x80096028: lui         $v0, 0x8000
    ctx->r2 = S32(0X8000 << 16);
    // 0x8009602C: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
L_80096030:
    // 0x80096030: sltiu       $v0, $a0, 0x8
    ctx->r2 = ctx->r4 < 0X8 ? 1 : 0;
    // 0x80096034: bne         $v0, $zero, L_80096004
    if (ctx->r2 != 0) {
        // 0x80096038: addiu       $v1, $v1, 0xEF8
        ctx->r3 = ADD32(ctx->r3, 0XEF8);
            goto L_80096004;
    }
    // 0x80096038: addiu       $v1, $v1, 0xEF8
    ctx->r3 = ADD32(ctx->r3, 0XEF8);
    // 0x8009603C: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
L_80096040:
    // 0x80096040: addu        $a1, $a0, $zero
    ctx->r5 = ADD32(ctx->r4, 0);
    // 0x80096044: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x80096048: beq         $a1, $v0, L_800960C8
    if (ctx->r5 == ctx->r2) {
        // 0x8009604C: nop
    
            goto L_800960C8;
    }
    // 0x8009604C: nop

    // 0x80096050: bltz        $a1, L_8009608C
    if (SIGNED(ctx->r5) < 0) {
        // 0x80096054: sll         $v0, $a1, 4
        ctx->r2 = S32(ctx->r5 << 4);
            goto L_8009608C;
    }
    // 0x80096054: sll         $v0, $a1, 4
    ctx->r2 = S32(ctx->r5 << 4);
    // 0x80096058: subu        $v0, $v0, $a1
    ctx->r2 = SUB32(ctx->r2, ctx->r5);
    // 0x8009605C: sll         $v0, $v0, 5
    ctx->r2 = S32(ctx->r2 << 5);
    // 0x80096060: subu        $v0, $v0, $a1
    ctx->r2 = SUB32(ctx->r2, ctx->r5);
    // 0x80096064: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x80096068: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x8009606C: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80096070: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80096074: sb          $v1, -0x5740($at)
    MEM_B(-0X5740, ctx->r1) = ctx->r3;
    // 0x80096078: j           L_800960C8
    // 0x8009607C: nop

        goto L_800960C8;
    // 0x8009607C: nop

L_80096080:
    // 0x80096080: and         $v0, $a1, $v0
    ctx->r2 = ctx->r5 & ctx->r2;
    // 0x80096084: j           L_80096040
    // 0x80096088: or          $a0, $a0, $v0
    ctx->r4 = ctx->r4 | ctx->r2;
        goto L_80096040;
    // 0x80096088: or          $a0, $a0, $v0
    ctx->r4 = ctx->r4 | ctx->r2;
L_8009608C:
    // 0x8009608C: lui         $v0, 0x7FFF
    ctx->r2 = S32(0X7FFF << 16);
    // 0x80096090: ori         $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 | 0XFFFF;
    // 0x80096094: and         $v0, $a1, $v0
    ctx->r2 = ctx->r5 & ctx->r2;
    // 0x80096098: sll         $v1, $v0, 4
    ctx->r3 = S32(ctx->r2 << 4);
    // 0x8009609C: subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // 0x800960A0: sll         $v1, $v1, 5
    ctx->r3 = S32(ctx->r3 << 5);
    // 0x800960A4: subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // 0x800960A8: sll         $v1, $v1, 3
    ctx->r3 = S32(ctx->r3 << 3);
    // 0x800960AC: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x800960B0: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x800960B4: lbu         $v0, -0x5712($at)
    ctx->r2 = MEM_BU(ctx->r1, -0X5712);
    // 0x800960B8: andi        $v0, $v0, 0xF7
    ctx->r2 = ctx->r2 & 0XF7;
    // 0x800960BC: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x800960C0: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x800960C4: sb          $v0, -0x5712($at)
    MEM_B(-0X5712, ctx->r1) = ctx->r2;
L_800960C8:
    // 0x800960C8: jr          $ra
    // 0x800960CC: nop

    return;
    // 0x800960CC: nop

;}
RECOMP_FUNC void func_800960D0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800960D0: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x800960D4: lbu         $v0, 0xF50($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0XF50);
    // 0x800960D8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800960DC: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x800960E0: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x800960E4: beq         $v0, $zero, L_80096104
    if (ctx->r2 == 0) {
        // 0x800960E8: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_80096104;
    }
    // 0x800960E8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800960EC: jal         0x80092010
    // 0x800960F0: nop

    factor5MutexAcquire(rdram, ctx);
        goto after_0;
    // 0x800960F0: nop

    after_0:
    // 0x800960F4: jal         0x80095FEC
    // 0x800960F8: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_80095FEC(rdram, ctx);
        goto after_1;
    // 0x800960F8: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_1:
    // 0x800960FC: jal         0x8009205C
    // 0x80096100: nop

    factor5MutexRelease(rdram, ctx);
        goto after_2;
    // 0x80096100: nop

    after_2:
L_80096104:
    // 0x80096104: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80096108: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x8009610C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80096110: jr          $ra
    // 0x80096114: nop

    return;
    // 0x80096114: nop

;}
RECOMP_FUNC void func_80096118(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80096118: addu        $a3, $a0, $zero
    ctx->r7 = ADD32(ctx->r4, 0);
    // 0x8009611C: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x80096120: lui         $v0, 0x7FFF
    ctx->r2 = S32(0X7FFF << 16);
    // 0x80096124: ori         $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 | 0XFFFF;
    // 0x80096128: and         $t0, $a3, $v0
    ctx->r8 = ctx->r7 & ctx->r2;
    // 0x8009612C: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
L_80096130:
    // 0x80096130: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80096134: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x80096138: lbu         $v0, -0x573F($at)
    ctx->r2 = MEM_BU(ctx->r1, -0X573F);
    // 0x8009613C: bnel        $v0, $zero, L_8009615C
    if (ctx->r2 != 0) {
        // 0x80096140: addiu       $a0, $a0, 0x1
        ctx->r4 = ADD32(ctx->r4, 0X1);
            goto L_8009615C;
    }
    goto skip_0;
    // 0x80096140: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    skip_0:
    // 0x80096144: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80096148: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x8009614C: lw          $v0, -0x6600($at)
    ctx->r2 = MEM_W(ctx->r1, -0X6600);
    // 0x80096150: beq         $v0, $t0, L_800961B4
    if (ctx->r2 == ctx->r8) {
        // 0x80096154: lui         $v0, 0x8000
        ctx->r2 = S32(0X8000 << 16);
            goto L_800961B4;
    }
    // 0x80096154: lui         $v0, 0x8000
    ctx->r2 = S32(0X8000 << 16);
    // 0x80096158: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
L_8009615C:
    // 0x8009615C: sltiu       $v0, $a0, 0x8
    ctx->r2 = ctx->r4 < 0X8 ? 1 : 0;
    // 0x80096160: bne         $v0, $zero, L_80096130
    if (ctx->r2 != 0) {
        // 0x80096164: addiu       $v1, $v1, 0xEF8
        ctx->r3 = ADD32(ctx->r3, 0XEF8);
            goto L_80096130;
    }
    // 0x80096164: addiu       $v1, $v1, 0xEF8
    ctx->r3 = ADD32(ctx->r3, 0XEF8);
    // 0x80096168: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
L_8009616C:
    // 0x8009616C: addu        $a3, $a0, $zero
    ctx->r7 = ADD32(ctx->r4, 0);
    // 0x80096170: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x80096174: beq         $a3, $v0, L_80096214
    if (ctx->r7 == ctx->r2) {
        // 0x80096178: nop
    
            goto L_80096214;
    }
    // 0x80096178: nop

    // 0x8009617C: bltz        $a3, L_800961C0
    if (SIGNED(ctx->r7) < 0) {
        // 0x80096180: sll         $v0, $a3, 4
        ctx->r2 = S32(ctx->r7 << 4);
            goto L_800961C0;
    }
    // 0x80096180: sll         $v0, $a3, 4
    ctx->r2 = S32(ctx->r7 << 4);
    // 0x80096184: subu        $v0, $v0, $a3
    ctx->r2 = SUB32(ctx->r2, ctx->r7);
    // 0x80096188: sll         $v0, $v0, 5
    ctx->r2 = S32(ctx->r2 << 5);
    // 0x8009618C: subu        $v0, $v0, $a3
    ctx->r2 = SUB32(ctx->r2, ctx->r7);
    // 0x80096190: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x80096194: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80096198: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x8009619C: sw          $a1, -0x64F0($at)
    MEM_W(-0X64F0, ctx->r1) = ctx->r5;
    // 0x800961A0: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x800961A4: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x800961A8: sw          $a2, -0x64EC($at)
    MEM_W(-0X64EC, ctx->r1) = ctx->r6;
    // 0x800961AC: j           L_80096214
    // 0x800961B0: nop

        goto L_80096214;
    // 0x800961B0: nop

L_800961B4:
    // 0x800961B4: and         $v0, $a3, $v0
    ctx->r2 = ctx->r7 & ctx->r2;
    // 0x800961B8: j           L_8009616C
    // 0x800961BC: or          $a0, $a0, $v0
    ctx->r4 = ctx->r4 | ctx->r2;
        goto L_8009616C;
    // 0x800961BC: or          $a0, $a0, $v0
    ctx->r4 = ctx->r4 | ctx->r2;
L_800961C0:
    // 0x800961C0: lui         $v0, 0x7FFF
    ctx->r2 = S32(0X7FFF << 16);
    // 0x800961C4: ori         $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 | 0XFFFF;
    // 0x800961C8: and         $a3, $a3, $v0
    ctx->r7 = ctx->r7 & ctx->r2;
    // 0x800961CC: sll         $v0, $a3, 4
    ctx->r2 = S32(ctx->r7 << 4);
    // 0x800961D0: subu        $v0, $v0, $a3
    ctx->r2 = SUB32(ctx->r2, ctx->r7);
    // 0x800961D4: sll         $v0, $v0, 5
    ctx->r2 = S32(ctx->r2 << 5);
    // 0x800961D8: subu        $v0, $v0, $a3
    ctx->r2 = SUB32(ctx->r2, ctx->r7);
    // 0x800961DC: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x800961E0: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x800961E4: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x800961E8: lbu         $v1, -0x5712($at)
    ctx->r3 = MEM_BU(ctx->r1, -0X5712);
    // 0x800961EC: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x800961F0: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x800961F4: sw          $a1, -0x571C($at)
    MEM_W(-0X571C, ctx->r1) = ctx->r5;
    // 0x800961F8: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x800961FC: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80096200: sw          $a2, -0x5718($at)
    MEM_W(-0X5718, ctx->r1) = ctx->r6;
    // 0x80096204: ori         $v1, $v1, 0x10
    ctx->r3 = ctx->r3 | 0X10;
    // 0x80096208: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8009620C: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80096210: sb          $v1, -0x5712($at)
    MEM_B(-0X5712, ctx->r1) = ctx->r3;
L_80096214:
    // 0x80096214: jr          $ra
    // 0x80096218: nop

    return;
    // 0x80096218: nop

;}
RECOMP_FUNC void func_8009621C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009621C: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x80096220: lbu         $v0, 0xF50($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0XF50);
    // 0x80096224: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80096228: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x8009622C: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x80096230: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x80096234: addu        $s1, $a1, $zero
    ctx->r17 = ADD32(ctx->r5, 0);
    // 0x80096238: sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // 0x8009623C: addu        $s2, $a2, $zero
    ctx->r18 = ADD32(ctx->r6, 0);
    // 0x80096240: beq         $v0, $zero, L_80096268
    if (ctx->r2 == 0) {
        // 0x80096244: sw          $ra, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r31;
            goto L_80096268;
    }
    // 0x80096244: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80096248: jal         0x80092010
    // 0x8009624C: nop

    factor5MutexAcquire(rdram, ctx);
        goto after_0;
    // 0x8009624C: nop

    after_0:
    // 0x80096250: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x80096254: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    // 0x80096258: jal         0x80096118
    // 0x8009625C: addu        $a2, $s2, $zero
    ctx->r6 = ADD32(ctx->r18, 0);
    func_80096118(rdram, ctx);
        goto after_1;
    // 0x8009625C: addu        $a2, $s2, $zero
    ctx->r6 = ADD32(ctx->r18, 0);
    after_1:
    // 0x80096260: jal         0x8009205C
    // 0x80096264: nop

    factor5MutexRelease(rdram, ctx);
        goto after_2;
    // 0x80096264: nop

    after_2:
L_80096268:
    // 0x80096268: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8009626C: lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X18);
    // 0x80096270: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x80096274: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x80096278: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8009627C: jr          $ra
    // 0x80096280: nop

    return;
    // 0x80096280: nop

;}
RECOMP_FUNC void func_80096284(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80096284: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80096288: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x8009628C: addu        $s3, $a0, $zero
    ctx->r19 = ADD32(ctx->r4, 0);
    // 0x80096290: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x80096294: addu        $s4, $a1, $zero
    ctx->r20 = ADD32(ctx->r5, 0);
    // 0x80096298: addu        $t0, $a2, $zero
    ctx->r8 = ADD32(ctx->r6, 0);
    // 0x8009629C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800962A0: addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
    // 0x800962A4: lui         $v0, 0x7FFF
    ctx->r2 = S32(0X7FFF << 16);
    // 0x800962A8: ori         $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 | 0XFFFF;
    // 0x800962AC: and         $a0, $a2, $v0
    ctx->r4 = ctx->r6 & ctx->r2;
    // 0x800962B0: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
    // 0x800962B4: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x800962B8: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x800962BC: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
L_800962C0:
    // 0x800962C0: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x800962C4: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x800962C8: lbu         $v0, -0x573F($at)
    ctx->r2 = MEM_BU(ctx->r1, -0X573F);
    // 0x800962CC: bnel        $v0, $zero, L_800962EC
    if (ctx->r2 != 0) {
        // 0x800962D0: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_800962EC;
    }
    goto skip_0;
    // 0x800962D0: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    skip_0:
    // 0x800962D4: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x800962D8: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x800962DC: lw          $v0, -0x6600($at)
    ctx->r2 = MEM_W(ctx->r1, -0X6600);
    // 0x800962E0: beq         $v0, $a0, L_80096394
    if (ctx->r2 == ctx->r4) {
        // 0x800962E4: lui         $v0, 0x8000
        ctx->r2 = S32(0X8000 << 16);
            goto L_80096394;
    }
    // 0x800962E4: lui         $v0, 0x8000
    ctx->r2 = S32(0X8000 << 16);
    // 0x800962E8: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_800962EC:
    // 0x800962EC: sltiu       $v0, $s0, 0x8
    ctx->r2 = ctx->r16 < 0X8 ? 1 : 0;
    // 0x800962F0: bne         $v0, $zero, L_800962C0
    if (ctx->r2 != 0) {
        // 0x800962F4: addiu       $v1, $v1, 0xEF8
        ctx->r3 = ADD32(ctx->r3, 0XEF8);
            goto L_800962C0;
    }
    // 0x800962F4: addiu       $v1, $v1, 0xEF8
    ctx->r3 = ADD32(ctx->r3, 0XEF8);
    // 0x800962F8: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
L_800962FC:
    // 0x800962FC: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x80096300: beq         $a2, $v0, L_800964A4
    if (ctx->r6 == ctx->r2) {
        // 0x80096304: nop
    
            goto L_800964A4;
    }
    // 0x80096304: nop

    // 0x80096308: bltz        $a2, L_800963A0
    if (SIGNED(ctx->r6) < 0) {
        // 0x8009630C: andi        $a0, $s3, 0xFF
        ctx->r4 = ctx->r19 & 0XFF;
            goto L_800963A0;
    }
    // 0x8009630C: andi        $a0, $s3, 0xFF
    ctx->r4 = ctx->r19 & 0XFF;
    // 0x80096310: sll         $s0, $a2, 4
    ctx->r16 = S32(ctx->r6 << 4);
    // 0x80096314: subu        $s0, $s0, $a2
    ctx->r16 = SUB32(ctx->r16, ctx->r6);
    // 0x80096318: sll         $s0, $s0, 5
    ctx->r16 = S32(ctx->r16 << 5);
    // 0x8009631C: subu        $s0, $s0, $a2
    ctx->r16 = SUB32(ctx->r16, ctx->r6);
    // 0x80096320: sll         $s0, $s0, 3
    ctx->r16 = S32(ctx->r16 << 3);
    // 0x80096324: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80096328: addu        $at, $at, $s0
    ctx->r1 = ADD32(ctx->r1, ctx->r16);
    // 0x8009632C: lbu         $a2, -0x573C($at)
    ctx->r6 = MEM_BU(ctx->r1, -0X573C);
    // 0x80096330: andi        $a1, $s4, 0xFFFF
    ctx->r5 = ctx->r20 & 0XFFFF;
    // 0x80096334: andi        $a3, $a3, 0xFF
    ctx->r7 = ctx->r7 & 0XFF;
    // 0x80096338: jal         0x8008DD60
    // 0x8009633C: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    func_8008DD60(rdram, ctx);
        goto after_0;
    // 0x8009633C: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    after_0:
    // 0x80096340: addu        $s1, $s0, $zero
    ctx->r17 = ADD32(ctx->r16, 0);
    // 0x80096344: lui         $v0, 0x8015
    ctx->r2 = S32(0X8015 << 16);
    // 0x80096348: addiu       $v0, $v0, -0x60D8
    ctx->r2 = ADD32(ctx->r2, -0X60D8);
    // 0x8009634C: addu        $s0, $s1, $v0
    ctx->r16 = ADD32(ctx->r17, ctx->r2);
    // 0x80096350: addiu       $s2, $s0, 0x40
    ctx->r18 = ADD32(ctx->r16, 0X40);
L_80096354:
    // 0x80096354: lbu         $a2, 0x0($s0)
    ctx->r6 = MEM_BU(ctx->r16, 0X0);
    // 0x80096358: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8009635C: addu        $at, $at, $s1
    ctx->r1 = ADD32(ctx->r1, ctx->r17);
    // 0x80096360: lbu         $v0, -0x573C($at)
    ctx->r2 = MEM_BU(ctx->r1, -0X573C);
    // 0x80096364: beq         $a2, $v0, L_8009637C
    if (ctx->r6 == ctx->r2) {
        // 0x80096368: andi        $a0, $s3, 0xFF
        ctx->r4 = ctx->r19 & 0XFF;
            goto L_8009637C;
    }
    // 0x80096368: andi        $a0, $s3, 0xFF
    ctx->r4 = ctx->r19 & 0XFF;
    // 0x8009636C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80096370: andi        $a1, $s4, 0xFFFF
    ctx->r5 = ctx->r20 & 0XFFFF;
    // 0x80096374: jal         0x8008DD60
    // 0x80096378: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    func_8008DD60(rdram, ctx);
        goto after_1;
    // 0x80096378: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    after_1:
L_8009637C:
    // 0x8009637C: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80096380: sltu        $v0, $s0, $s2
    ctx->r2 = ctx->r16 < ctx->r18 ? 1 : 0;
    // 0x80096384: beq         $v0, $zero, L_800964A4
    if (ctx->r2 == 0) {
        // 0x80096388: nop
    
            goto L_800964A4;
    }
    // 0x80096388: nop

    // 0x8009638C: j           L_80096354
    // 0x80096390: nop

        goto L_80096354;
    // 0x80096390: nop

L_80096394:
    // 0x80096394: and         $v0, $a2, $v0
    ctx->r2 = ctx->r6 & ctx->r2;
    // 0x80096398: j           L_800962FC
    // 0x8009639C: or          $a2, $s0, $v0
    ctx->r6 = ctx->r16 | ctx->r2;
        goto L_800962FC;
    // 0x8009639C: or          $a2, $s0, $v0
    ctx->r6 = ctx->r16 | ctx->r2;
L_800963A0:
    // 0x800963A0: lui         $v0, 0x7FFF
    ctx->r2 = S32(0X7FFF << 16);
    // 0x800963A4: ori         $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 | 0XFFFF;
    // 0x800963A8: and         $a2, $a2, $v0
    ctx->r6 = ctx->r6 & ctx->r2;
    // 0x800963AC: andi        $a3, $a3, 0xF
    ctx->r7 = ctx->r7 & 0XF;
    // 0x800963B0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800963B4: beq         $a3, $v0, L_80096410
    if (ctx->r7 == ctx->r2) {
        // 0x800963B8: slti        $v0, $a3, 0x2
        ctx->r2 = SIGNED(ctx->r7) < 0X2 ? 1 : 0;
            goto L_80096410;
    }
    // 0x800963B8: slti        $v0, $a3, 0x2
    ctx->r2 = SIGNED(ctx->r7) < 0X2 ? 1 : 0;
    // 0x800963BC: beql        $v0, $zero, L_800963D4
    if (ctx->r2 == 0) {
        // 0x800963C0: addiu       $v0, $zero, 0x2
        ctx->r2 = ADD32(0, 0X2);
            goto L_800963D4;
    }
    goto skip_1;
    // 0x800963C0: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    skip_1:
    // 0x800963C4: beq         $a3, $zero, L_800963EC
    if (ctx->r7 == 0) {
        // 0x800963C8: sll         $v0, $a2, 4
        ctx->r2 = S32(ctx->r6 << 4);
            goto L_800963EC;
    }
    // 0x800963C8: sll         $v0, $a2, 4
    ctx->r2 = S32(ctx->r6 << 4);
    // 0x800963CC: j           L_800964A4
    // 0x800963D0: nop

        goto L_800964A4;
    // 0x800963D0: nop

L_800963D4:
    // 0x800963D4: beq         $a3, $v0, L_80096438
    if (ctx->r7 == ctx->r2) {
        // 0x800963D8: addiu       $v0, $zero, 0x3
        ctx->r2 = ADD32(0, 0X3);
            goto L_80096438;
    }
    // 0x800963D8: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x800963DC: beq         $a3, $v0, L_8009646C
    if (ctx->r7 == ctx->r2) {
        // 0x800963E0: sll         $v0, $a2, 4
        ctx->r2 = S32(ctx->r6 << 4);
            goto L_8009646C;
    }
    // 0x800963E0: sll         $v0, $a2, 4
    ctx->r2 = S32(ctx->r6 << 4);
    // 0x800963E4: j           L_800964A4
    // 0x800963E8: nop

        goto L_800964A4;
    // 0x800963E8: nop

L_800963EC:
    // 0x800963EC: subu        $v0, $v0, $a2
    ctx->r2 = SUB32(ctx->r2, ctx->r6);
    // 0x800963F0: sll         $v0, $v0, 5
    ctx->r2 = S32(ctx->r2 << 5);
    // 0x800963F4: subu        $v0, $v0, $a2
    ctx->r2 = SUB32(ctx->r2, ctx->r6);
    // 0x800963F8: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x800963FC: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80096400: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80096404: sb          $s3, -0x5720($at)
    MEM_B(-0X5720, ctx->r1) = ctx->r19;
    // 0x80096408: j           L_800964A4
    // 0x8009640C: nop

        goto L_800964A4;
    // 0x8009640C: nop

L_80096410:
    // 0x80096410: sll         $v0, $a2, 4
    ctx->r2 = S32(ctx->r6 << 4);
    // 0x80096414: subu        $v0, $v0, $a2
    ctx->r2 = SUB32(ctx->r2, ctx->r6);
    // 0x80096418: sll         $v0, $v0, 5
    ctx->r2 = S32(ctx->r2 << 5);
    // 0x8009641C: subu        $v0, $v0, $a2
    ctx->r2 = SUB32(ctx->r2, ctx->r6);
    // 0x80096420: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x80096424: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80096428: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x8009642C: sw          $zero, -0x5710($at)
    MEM_W(-0X5710, ctx->r1) = 0;
    // 0x80096430: j           L_800964A4
    // 0x80096434: nop

        goto L_800964A4;
    // 0x80096434: nop

L_80096438:
    // 0x80096438: sll         $v0, $a2, 4
    ctx->r2 = S32(ctx->r6 << 4);
    // 0x8009643C: subu        $v0, $v0, $a2
    ctx->r2 = SUB32(ctx->r2, ctx->r6);
    // 0x80096440: sll         $v0, $v0, 5
    ctx->r2 = S32(ctx->r2 << 5);
    // 0x80096444: subu        $v0, $v0, $a2
    ctx->r2 = SUB32(ctx->r2, ctx->r6);
    // 0x80096448: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x8009644C: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80096450: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80096454: lbu         $v1, -0x5712($at)
    ctx->r3 = MEM_BU(ctx->r1, -0X5712);
    // 0x80096458: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8009645C: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80096460: sb          $s3, -0x5720($at)
    MEM_B(-0X5720, ctx->r1) = ctx->r19;
    // 0x80096464: j           L_80096498
    // 0x80096468: ori         $v1, $v1, 0x8
    ctx->r3 = ctx->r3 | 0X8;
        goto L_80096498;
    // 0x80096468: ori         $v1, $v1, 0x8
    ctx->r3 = ctx->r3 | 0X8;
L_8009646C:
    // 0x8009646C: subu        $v0, $v0, $a2
    ctx->r2 = SUB32(ctx->r2, ctx->r6);
    // 0x80096470: sll         $v0, $v0, 5
    ctx->r2 = S32(ctx->r2 << 5);
    // 0x80096474: subu        $v0, $v0, $a2
    ctx->r2 = SUB32(ctx->r2, ctx->r6);
    // 0x80096478: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x8009647C: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80096480: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80096484: lbu         $v1, -0x5712($at)
    ctx->r3 = MEM_BU(ctx->r1, -0X5712);
    // 0x80096488: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8009648C: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80096490: sb          $s3, -0x5720($at)
    MEM_B(-0X5720, ctx->r1) = ctx->r19;
    // 0x80096494: ori         $v1, $v1, 0x80
    ctx->r3 = ctx->r3 | 0X80;
L_80096498:
    // 0x80096498: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8009649C: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x800964A0: sb          $v1, -0x5712($at)
    MEM_B(-0X5712, ctx->r1) = ctx->r3;
L_800964A4:
    // 0x800964A4: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x800964A8: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x800964AC: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x800964B0: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x800964B4: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x800964B8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800964BC: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x800964C0: jr          $ra
    // 0x800964C4: nop

    return;
    // 0x800964C4: nop

;}
RECOMP_FUNC void queueAudioVoiceCmd(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800964C8: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x800964CC: lbu         $v0, 0xF50($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0XF50);
    // 0x800964D0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800964D4: sw          $s3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r19;
    // 0x800964D8: addu        $s3, $a2, $zero
    ctx->r19 = ADD32(ctx->r6, 0);
    // 0x800964DC: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x800964E0: addu        $s1, $a0, $zero
    ctx->r17 = ADD32(ctx->r4, 0);
    // 0x800964E4: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x800964E8: addu        $s0, $a1, $zero
    ctx->r16 = ADD32(ctx->r5, 0);
    // 0x800964EC: sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // 0x800964F0: addu        $s2, $a3, $zero
    ctx->r18 = ADD32(ctx->r7, 0);
    // 0x800964F4: beq         $v0, $zero, L_80096520
    if (ctx->r2 == 0) {
        // 0x800964F8: sw          $ra, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r31;
            goto L_80096520;
    }
    // 0x800964F8: sw          $ra, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r31;
    // 0x800964FC: jal         0x80092010
    // 0x80096500: nop

    factor5MutexAcquire(rdram, ctx);
        goto after_0;
    // 0x80096500: nop

    after_0:
    // 0x80096504: andi        $a0, $s1, 0xFF
    ctx->r4 = ctx->r17 & 0XFF;
    // 0x80096508: andi        $a1, $s0, 0xFFFF
    ctx->r5 = ctx->r16 & 0XFFFF;
    // 0x8009650C: addu        $a2, $s3, $zero
    ctx->r6 = ADD32(ctx->r19, 0);
    // 0x80096510: jal         0x80096284
    // 0x80096514: andi        $a3, $s2, 0xFF
    ctx->r7 = ctx->r18 & 0XFF;
    func_80096284(rdram, ctx);
        goto after_1;
    // 0x80096514: andi        $a3, $s2, 0xFF
    ctx->r7 = ctx->r18 & 0XFF;
    after_1:
    // 0x80096518: jal         0x8009205C
    // 0x8009651C: nop

    factor5MutexRelease(rdram, ctx);
        goto after_2;
    // 0x8009651C: nop

    after_2:
L_80096520:
    // 0x80096520: lw          $ra, 0x20($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X20);
    // 0x80096524: lw          $s3, 0x1C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X1C);
    // 0x80096528: lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X18);
    // 0x8009652C: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x80096530: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x80096534: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80096538: jr          $ra
    // 0x8009653C: nop

    return;
    // 0x8009653C: nop

;}
RECOMP_FUNC void func_80096540(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80096540: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x80096544: lbu         $v0, 0xF50($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0XF50);
    // 0x80096548: beq         $v0, $zero, L_800965D8
    if (ctx->r2 == 0) {
        // 0x8009654C: addu        $a1, $zero, $zero
        ctx->r5 = ADD32(0, 0);
            goto L_800965D8;
    }
    // 0x8009654C: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x80096550: lui         $v0, 0x7FFF
    ctx->r2 = S32(0X7FFF << 16);
    // 0x80096554: ori         $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 | 0XFFFF;
    // 0x80096558: and         $a2, $a0, $v0
    ctx->r6 = ctx->r4 & ctx->r2;
    // 0x8009655C: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
L_80096560:
    // 0x80096560: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80096564: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x80096568: lbu         $v0, -0x573F($at)
    ctx->r2 = MEM_BU(ctx->r1, -0X573F);
    // 0x8009656C: bnel        $v0, $zero, L_8009658C
    if (ctx->r2 != 0) {
        // 0x80096570: addiu       $a1, $a1, 0x1
        ctx->r5 = ADD32(ctx->r5, 0X1);
            goto L_8009658C;
    }
    goto skip_0;
    // 0x80096570: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    skip_0:
    // 0x80096574: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80096578: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x8009657C: lw          $v0, -0x6600($at)
    ctx->r2 = MEM_W(ctx->r1, -0X6600);
    // 0x80096580: beq         $v0, $a2, L_800965CC
    if (ctx->r2 == ctx->r6) {
        // 0x80096584: lui         $v0, 0x8000
        ctx->r2 = S32(0X8000 << 16);
            goto L_800965CC;
    }
    // 0x80096584: lui         $v0, 0x8000
    ctx->r2 = S32(0X8000 << 16);
    // 0x80096588: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
L_8009658C:
    // 0x8009658C: sltiu       $v0, $a1, 0x8
    ctx->r2 = ctx->r5 < 0X8 ? 1 : 0;
    // 0x80096590: bne         $v0, $zero, L_80096560
    if (ctx->r2 != 0) {
        // 0x80096594: addiu       $v1, $v1, 0xEF8
        ctx->r3 = ADD32(ctx->r3, 0XEF8);
            goto L_80096560;
    }
    // 0x80096594: addiu       $v1, $v1, 0xEF8
    ctx->r3 = ADD32(ctx->r3, 0XEF8);
    // 0x80096598: addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
L_8009659C:
    // 0x8009659C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x800965A0: beq         $v1, $v0, L_800965D8
    if (ctx->r3 == ctx->r2) {
        // 0x800965A4: sll         $v0, $v1, 4
        ctx->r2 = S32(ctx->r3 << 4);
            goto L_800965D8;
    }
    // 0x800965A4: sll         $v0, $v1, 4
    ctx->r2 = S32(ctx->r3 << 4);
    // 0x800965A8: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x800965AC: sll         $v0, $v0, 5
    ctx->r2 = S32(ctx->r2 << 5);
    // 0x800965B0: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x800965B4: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x800965B8: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x800965BC: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x800965C0: lbu         $v0, -0x573C($at)
    ctx->r2 = MEM_BU(ctx->r1, -0X573C);
    // 0x800965C4: j           L_800965DC
    // 0x800965C8: nop

        goto L_800965DC;
    // 0x800965C8: nop

L_800965CC:
    // 0x800965CC: and         $v0, $a0, $v0
    ctx->r2 = ctx->r4 & ctx->r2;
    // 0x800965D0: j           L_8009659C
    // 0x800965D4: or          $v1, $a1, $v0
    ctx->r3 = ctx->r5 | ctx->r2;
        goto L_8009659C;
    // 0x800965D4: or          $v1, $a1, $v0
    ctx->r3 = ctx->r5 | ctx->r2;
L_800965D8:
    // 0x800965D8: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_800965DC:
    // 0x800965DC: jr          $ra
    // 0x800965E0: nop

    return;
    // 0x800965E0: nop

;}
RECOMP_FUNC void func_800965E4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800965E4: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x800965E8: lbu         $v0, 0xF50($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0XF50);
    // 0x800965EC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800965F0: beq         $v0, $zero, L_80096694
    if (ctx->r2 == 0) {
        // 0x800965F4: sw          $ra, 0x10($sp)
        MEM_W(0X10, ctx->r29) = ctx->r31;
            goto L_80096694;
    }
    // 0x800965F4: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x800965F8: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    // 0x800965FC: lui         $v0, 0x7FFF
    ctx->r2 = S32(0X7FFF << 16);
    // 0x80096600: ori         $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 | 0XFFFF;
    // 0x80096604: and         $t0, $a0, $v0
    ctx->r8 = ctx->r4 & ctx->r2;
    // 0x80096608: lui         $v0, 0x8000
    ctx->r2 = S32(0X8000 << 16);
    // 0x8009660C: and         $a0, $a0, $v0
    ctx->r4 = ctx->r4 & ctx->r2;
    // 0x80096610: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
L_80096614:
    // 0x80096614: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80096618: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x8009661C: lbu         $v0, -0x573F($at)
    ctx->r2 = MEM_BU(ctx->r1, -0X573F);
    // 0x80096620: bnel        $v0, $zero, L_80096644
    if (ctx->r2 != 0) {
        // 0x80096624: addiu       $a3, $a3, 0x1
        ctx->r7 = ADD32(ctx->r7, 0X1);
            goto L_80096644;
    }
    goto skip_0;
    // 0x80096624: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    skip_0:
    // 0x80096628: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8009662C: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x80096630: lw          $v0, -0x6600($at)
    ctx->r2 = MEM_W(ctx->r1, -0X6600);
    // 0x80096634: bnel        $v0, $t0, L_80096644
    if (ctx->r2 != ctx->r8) {
        // 0x80096638: addiu       $a3, $a3, 0x1
        ctx->r7 = ADD32(ctx->r7, 0X1);
            goto L_80096644;
    }
    goto skip_1;
    // 0x80096638: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    skip_1:
    // 0x8009663C: j           L_80096654
    // 0x80096640: or          $a0, $a3, $a0
    ctx->r4 = ctx->r7 | ctx->r4;
        goto L_80096654;
    // 0x80096640: or          $a0, $a3, $a0
    ctx->r4 = ctx->r7 | ctx->r4;
L_80096644:
    // 0x80096644: sltiu       $v0, $a3, 0x8
    ctx->r2 = ctx->r7 < 0X8 ? 1 : 0;
    // 0x80096648: bne         $v0, $zero, L_80096614
    if (ctx->r2 != 0) {
        // 0x8009664C: addiu       $v1, $v1, 0xEF8
        ctx->r3 = ADD32(ctx->r3, 0XEF8);
            goto L_80096614;
    }
    // 0x8009664C: addiu       $v1, $v1, 0xEF8
    ctx->r3 = ADD32(ctx->r3, 0XEF8);
    // 0x80096650: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
L_80096654:
    // 0x80096654: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x80096658: beq         $a0, $v0, L_80096694
    if (ctx->r4 == ctx->r2) {
        // 0x8009665C: sll         $v0, $a0, 4
        ctx->r2 = S32(ctx->r4 << 4);
            goto L_80096694;
    }
    // 0x8009665C: sll         $v0, $a0, 4
    ctx->r2 = S32(ctx->r4 << 4);
    // 0x80096660: subu        $v0, $v0, $a0
    ctx->r2 = SUB32(ctx->r2, ctx->r4);
    // 0x80096664: sll         $v0, $v0, 5
    ctx->r2 = S32(ctx->r2 << 5);
    // 0x80096668: subu        $v0, $v0, $a0
    ctx->r2 = SUB32(ctx->r2, ctx->r4);
    // 0x8009666C: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x80096670: andi        $a0, $a1, 0xFF
    ctx->r4 = ctx->r5 & 0XFF;
    // 0x80096674: lui         $v1, 0x8015
    ctx->r3 = S32(0X8015 << 16);
    // 0x80096678: addiu       $v1, $v1, -0x60D8
    ctx->r3 = ADD32(ctx->r3, -0X60D8);
    // 0x8009667C: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80096680: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x80096684: sb          $a2, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r6;
    // 0x80096688: andi        $a0, $a2, 0xFF
    ctx->r4 = ctx->r6 & 0XFF;
    // 0x8009668C: jal         0x8008E54C
    // 0x80096690: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_8008E54C(rdram, ctx);
        goto after_0;
    // 0x80096690: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_0:
L_80096694:
    // 0x80096694: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x80096698: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8009669C: jr          $ra
    // 0x800966A0: nop

    return;
    // 0x800966A0: nop

;}
RECOMP_FUNC void func_800966A4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800966A4: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x800966A8: sw          $s0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r16;
    // 0x800966AC: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x800966B0: sw          $s4, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r20;
    // 0x800966B4: addu        $s4, $a1, $zero
    ctx->r20 = ADD32(ctx->r5, 0);
    // 0x800966B8: sw          $s3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r19;
    // 0x800966BC: addu        $s3, $a2, $zero
    ctx->r19 = ADD32(ctx->r6, 0);
    // 0x800966C0: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x800966C4: lui         $v0, 0x7FFF
    ctx->r2 = S32(0X7FFF << 16);
    // 0x800966C8: sw          $ra, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r31;
    // 0x800966CC: sw          $s2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r18;
    // 0x800966D0: sw          $s1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r17;
    // 0x800966D4: lw          $a2, 0x0($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X0);
    // 0x800966D8: ori         $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 | 0XFFFF;
    // 0x800966DC: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
    // 0x800966E0: and         $a1, $a2, $v0
    ctx->r5 = ctx->r6 & ctx->r2;
L_800966E4:
    // 0x800966E4: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x800966E8: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x800966EC: lbu         $v0, -0x573F($at)
    ctx->r2 = MEM_BU(ctx->r1, -0X573F);
    // 0x800966F0: bnel        $v0, $zero, L_80096710
    if (ctx->r2 != 0) {
        // 0x800966F4: addiu       $a0, $a0, 0x1
        ctx->r4 = ADD32(ctx->r4, 0X1);
            goto L_80096710;
    }
    goto skip_0;
    // 0x800966F4: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    skip_0:
    // 0x800966F8: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x800966FC: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x80096700: lw          $v0, -0x6600($at)
    ctx->r2 = MEM_W(ctx->r1, -0X6600);
    // 0x80096704: beq         $v0, $a1, L_800967FC
    if (ctx->r2 == ctx->r5) {
        // 0x80096708: lui         $v0, 0x8000
        ctx->r2 = S32(0X8000 << 16);
            goto L_800967FC;
    }
    // 0x80096708: lui         $v0, 0x8000
    ctx->r2 = S32(0X8000 << 16);
    // 0x8009670C: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
L_80096710:
    // 0x80096710: sltiu       $v0, $a0, 0x8
    ctx->r2 = ctx->r4 < 0X8 ? 1 : 0;
    // 0x80096714: bne         $v0, $zero, L_800966E4
    if (ctx->r2 != 0) {
        // 0x80096718: addiu       $v1, $v1, 0xEF8
        ctx->r3 = ADD32(ctx->r3, 0XEF8);
            goto L_800966E4;
    }
    // 0x80096718: addiu       $v1, $v1, 0xEF8
    ctx->r3 = ADD32(ctx->r3, 0XEF8);
    // 0x8009671C: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
L_80096720:
    // 0x80096720: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x80096724: beq         $t0, $v0, L_80096C64
    if (ctx->r8 == ctx->r2) {
        // 0x80096728: nop
    
            goto L_80096C64;
    }
    // 0x80096728: nop

    // 0x8009672C: lbu         $v1, 0x26($s0)
    ctx->r3 = MEM_BU(ctx->r16, 0X26);
    // 0x80096730: andi        $v0, $v1, 0x4
    ctx->r2 = ctx->r3 & 0X4;
    // 0x80096734: beq         $v0, $zero, L_80096808
    if (ctx->r2 == 0) {
        // 0x80096738: sll         $v0, $t0, 4
        ctx->r2 = S32(ctx->r8 << 4);
            goto L_80096808;
    }
    // 0x80096738: sll         $v0, $t0, 4
    ctx->r2 = S32(ctx->r8 << 4);
    // 0x8009673C: subu        $v0, $v0, $t0
    ctx->r2 = SUB32(ctx->r2, ctx->r8);
    // 0x80096740: sll         $v0, $v0, 5
    ctx->r2 = S32(ctx->r2 << 5);
    // 0x80096744: subu        $v0, $v0, $t0
    ctx->r2 = SUB32(ctx->r2, ctx->r8);
    // 0x80096748: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x8009674C: lui         $v1, 0x8015
    ctx->r3 = S32(0X8015 << 16);
    // 0x80096750: addiu       $v1, $v1, -0x5738
    ctx->r3 = ADD32(ctx->r3, -0X5738);
    // 0x80096754: addu        $a3, $v0, $v1
    ctx->r7 = ADD32(ctx->r2, ctx->r3);
    // 0x80096758: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    // 0x8009675C: addiu       $t1, $s0, 0x20
    ctx->r9 = ADD32(ctx->r16, 0X20);
L_80096760:
    // 0x80096760: lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X0);
    // 0x80096764: lw          $v1, 0x4($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X4);
    // 0x80096768: lw          $a0, 0x8($a2)
    ctx->r4 = MEM_W(ctx->r6, 0X8);
    // 0x8009676C: lw          $a1, 0xC($a2)
    ctx->r5 = MEM_W(ctx->r6, 0XC);
    // 0x80096770: sw          $v0, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r2;
    // 0x80096774: sw          $v1, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r3;
    // 0x80096778: sw          $a0, 0x8($a3)
    MEM_W(0X8, ctx->r7) = ctx->r4;
    // 0x8009677C: sw          $a1, 0xC($a3)
    MEM_W(0XC, ctx->r7) = ctx->r5;
    // 0x80096780: addiu       $a2, $a2, 0x10
    ctx->r6 = ADD32(ctx->r6, 0X10);
    // 0x80096784: bne         $a2, $t1, L_80096760
    if (ctx->r6 != ctx->r9) {
        // 0x80096788: addiu       $a3, $a3, 0x10
        ctx->r7 = ADD32(ctx->r7, 0X10);
            goto L_80096760;
    }
    // 0x80096788: addiu       $a3, $a3, 0x10
    ctx->r7 = ADD32(ctx->r7, 0X10);
    // 0x8009678C: lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X0);
    // 0x80096790: lw          $v1, 0x4($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X4);
    // 0x80096794: sw          $v0, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r2;
    // 0x80096798: sw          $v1, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r3;
    // 0x8009679C: sll         $v0, $t0, 4
    ctx->r2 = S32(ctx->r8 << 4);
    // 0x800967A0: subu        $v0, $v0, $t0
    ctx->r2 = SUB32(ctx->r2, ctx->r8);
    // 0x800967A4: sll         $v0, $v0, 5
    ctx->r2 = S32(ctx->r2 << 5);
    // 0x800967A8: subu        $v0, $v0, $t0
    ctx->r2 = SUB32(ctx->r2, ctx->r8);
    // 0x800967AC: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x800967B0: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x800967B4: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x800967B8: lbu         $a0, -0x5712($at)
    ctx->r4 = MEM_BU(ctx->r1, -0X5712);
    // 0x800967BC: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x800967C0: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x800967C4: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x800967C8: sb          $v1, -0x570C($at)
    MEM_B(-0X570C, ctx->r1) = ctx->r3;
    // 0x800967CC: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x800967D0: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x800967D4: sw          $s4, -0x5710($at)
    MEM_W(-0X5710, ctx->r1) = ctx->r20;
    // 0x800967D8: andi        $a0, $a0, 0xFB
    ctx->r4 = ctx->r4 & 0XFB;
    // 0x800967DC: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x800967E0: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x800967E4: sb          $a0, -0x5712($at)
    MEM_B(-0X5712, ctx->r1) = ctx->r4;
    // 0x800967E8: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x800967EC: lui         $v1, 0x8000
    ctx->r3 = S32(0X8000 << 16);
    // 0x800967F0: or          $v0, $v0, $v1
    ctx->r2 = ctx->r2 | ctx->r3;
    // 0x800967F4: j           L_80096C64
    // 0x800967F8: sw          $v0, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->r2;
        goto L_80096C64;
    // 0x800967F8: sw          $v0, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->r2;
L_800967FC:
    // 0x800967FC: and         $v0, $a2, $v0
    ctx->r2 = ctx->r6 & ctx->r2;
    // 0x80096800: j           L_80096720
    // 0x80096804: or          $t0, $a0, $v0
    ctx->r8 = ctx->r4 | ctx->r2;
        goto L_80096720;
    // 0x80096804: or          $t0, $a0, $v0
    ctx->r8 = ctx->r4 | ctx->r2;
L_80096808:
    // 0x80096808: andi        $v0, $s3, 0xFF
    ctx->r2 = ctx->r19 & 0XFF;
    // 0x8009680C: beq         $v0, $zero, L_80096870
    if (ctx->r2 == 0) {
        // 0x80096810: andi        $v0, $v1, 0x1
        ctx->r2 = ctx->r3 & 0X1;
            goto L_80096870;
    }
    // 0x80096810: andi        $v0, $v1, 0x1
    ctx->r2 = ctx->r3 & 0X1;
    // 0x80096814: beq         $v0, $zero, L_80096834
    if (ctx->r2 == 0) {
        // 0x80096818: addu        $a0, $zero, $zero
        ctx->r4 = ADD32(0, 0);
            goto L_80096834;
    }
    // 0x80096818: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x8009681C: lhu         $a1, 0x4($s0)
    ctx->r5 = MEM_HU(ctx->r16, 0X4);
    // 0x80096820: lw          $a2, 0x0($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X0);
    // 0x80096824: jal         0x80096284
    // 0x80096828: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    func_80096284(rdram, ctx);
        goto after_0;
    // 0x80096828: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    after_0:
    // 0x8009682C: j           L_80096934
    // 0x80096830: nop

        goto L_80096934;
    // 0x80096830: nop

L_80096834:
    // 0x80096834: andi        $v0, $v1, 0x40
    ctx->r2 = ctx->r3 & 0X40;
    // 0x80096838: beql        $v0, $zero, L_80096858
    if (ctx->r2 == 0) {
        // 0x8009683C: addu        $a0, $zero, $zero
        ctx->r4 = ADD32(0, 0);
            goto L_80096858;
    }
    goto skip_1;
    // 0x8009683C: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    skip_1:
    // 0x80096840: lhu         $a1, 0x4($s0)
    ctx->r5 = MEM_HU(ctx->r16, 0X4);
    // 0x80096844: lw          $a2, 0x0($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X0);
    // 0x80096848: jal         0x80096284
    // 0x8009684C: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    func_80096284(rdram, ctx);
        goto after_1;
    // 0x8009684C: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    after_1:
    // 0x80096850: j           L_80096934
    // 0x80096854: nop

        goto L_80096934;
    // 0x80096854: nop

L_80096858:
    // 0x80096858: lhu         $a1, 0x4($s0)
    ctx->r5 = MEM_HU(ctx->r16, 0X4);
    // 0x8009685C: lw          $a2, 0x0($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X0);
    // 0x80096860: jal         0x80096284
    // 0x80096864: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    func_80096284(rdram, ctx);
        goto after_2;
    // 0x80096864: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_2:
    // 0x80096868: j           L_80096934
    // 0x8009686C: nop

        goto L_80096934;
    // 0x8009686C: nop

L_80096870:
    // 0x80096870: beq         $v0, $zero, L_800968AC
    if (ctx->r2 == 0) {
        // 0x80096874: andi        $v0, $v1, 0x40
        ctx->r2 = ctx->r3 & 0X40;
            goto L_800968AC;
    }
    // 0x80096874: andi        $v0, $v1, 0x40
    ctx->r2 = ctx->r3 & 0X40;
    // 0x80096878: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x8009687C: lbu         $v0, 0xF50($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0XF50);
    // 0x80096880: lhu         $s1, 0x4($s0)
    ctx->r17 = MEM_HU(ctx->r16, 0X4);
    // 0x80096884: lw          $s2, 0x0($s0)
    ctx->r18 = MEM_W(ctx->r16, 0X0);
    // 0x80096888: beq         $v0, $zero, L_80096934
    if (ctx->r2 == 0) {
        // 0x8009688C: nop
    
            goto L_80096934;
    }
    // 0x8009688C: nop

    // 0x80096890: jal         0x80092010
    // 0x80096894: nop

    factor5MutexAcquire(rdram, ctx);
        goto after_3;
    // 0x80096894: nop

    after_3:
    // 0x80096898: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x8009689C: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    // 0x800968A0: addu        $a2, $s2, $zero
    ctx->r6 = ADD32(ctx->r18, 0);
    // 0x800968A4: j           L_80096924
    // 0x800968A8: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
        goto L_80096924;
    // 0x800968A8: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
L_800968AC:
    // 0x800968AC: beq         $v0, $zero, L_800968F4
    if (ctx->r2 == 0) {
        // 0x800968B0: nop
    
            goto L_800968F4;
    }
    // 0x800968B0: nop

    // 0x800968B4: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x800968B8: lbu         $v0, 0xF50($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0XF50);
    // 0x800968BC: lhu         $s1, 0x4($s0)
    ctx->r17 = MEM_HU(ctx->r16, 0X4);
    // 0x800968C0: lw          $s2, 0x0($s0)
    ctx->r18 = MEM_W(ctx->r16, 0X0);
    // 0x800968C4: beq         $v0, $zero, L_80096934
    if (ctx->r2 == 0) {
        // 0x800968C8: nop
    
            goto L_80096934;
    }
    // 0x800968C8: nop

    // 0x800968CC: jal         0x80092010
    // 0x800968D0: nop

    factor5MutexAcquire(rdram, ctx);
        goto after_4;
    // 0x800968D0: nop

    after_4:
    // 0x800968D4: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x800968D8: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    // 0x800968DC: addu        $a2, $s2, $zero
    ctx->r6 = ADD32(ctx->r18, 0);
    // 0x800968E0: j           L_80096924
    // 0x800968E4: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
        goto L_80096924;
    // 0x800968E4: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
L_800968E8:
    // 0x800968E8: and         $v0, $a2, $v0
    ctx->r2 = ctx->r6 & ctx->r2;
    // 0x800968EC: j           L_8009699C
    // 0x800968F0: or          $v1, $a0, $v0
    ctx->r3 = ctx->r4 | ctx->r2;
        goto L_8009699C;
    // 0x800968F0: or          $v1, $a0, $v0
    ctx->r3 = ctx->r4 | ctx->r2;
L_800968F4:
    // 0x800968F4: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x800968F8: lbu         $v0, 0xF50($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0XF50);
    // 0x800968FC: lhu         $s1, 0x4($s0)
    ctx->r17 = MEM_HU(ctx->r16, 0X4);
    // 0x80096900: lw          $s2, 0x0($s0)
    ctx->r18 = MEM_W(ctx->r16, 0X0);
    // 0x80096904: beq         $v0, $zero, L_80096934
    if (ctx->r2 == 0) {
        // 0x80096908: nop
    
            goto L_80096934;
    }
    // 0x80096908: nop

    // 0x8009690C: jal         0x80092010
    // 0x80096910: nop

    factor5MutexAcquire(rdram, ctx);
        goto after_5;
    // 0x80096910: nop

    after_5:
    // 0x80096914: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x80096918: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    // 0x8009691C: addu        $a2, $s2, $zero
    ctx->r6 = ADD32(ctx->r18, 0);
    // 0x80096920: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
L_80096924:
    // 0x80096924: jal         0x80096284
    // 0x80096928: nop

    func_80096284(rdram, ctx);
        goto after_6;
    // 0x80096928: nop

    after_6:
    // 0x8009692C: jal         0x8009205C
    // 0x80096930: nop

    factor5MutexRelease(rdram, ctx);
        goto after_7;
    // 0x80096930: nop

    after_7:
L_80096934:
    // 0x80096934: beq         $s4, $zero, L_80096C64
    if (ctx->r20 == 0) {
        // 0x80096938: nop
    
            goto L_80096C64;
    }
    // 0x80096938: nop

    // 0x8009693C: lbu         $v0, 0x26($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X26);
    // 0x80096940: andi        $v0, $v0, 0x2
    ctx->r2 = ctx->r2 & 0X2;
    // 0x80096944: beq         $v0, $zero, L_80096B2C
    if (ctx->r2 == 0) {
        // 0x80096948: addu        $a0, $zero, $zero
        ctx->r4 = ADD32(0, 0);
            goto L_80096B2C;
    }
    // 0x80096948: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x8009694C: lui         $v0, 0x7FFF
    ctx->r2 = S32(0X7FFF << 16);
    // 0x80096950: lw          $a2, 0x8($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X8);
    // 0x80096954: ori         $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 | 0XFFFF;
    // 0x80096958: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
    // 0x8009695C: and         $a1, $a2, $v0
    ctx->r5 = ctx->r6 & ctx->r2;
L_80096960:
    // 0x80096960: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80096964: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x80096968: lbu         $v0, -0x573F($at)
    ctx->r2 = MEM_BU(ctx->r1, -0X573F);
    // 0x8009696C: bnel        $v0, $zero, L_8009698C
    if (ctx->r2 != 0) {
        // 0x80096970: addiu       $a0, $a0, 0x1
        ctx->r4 = ADD32(ctx->r4, 0X1);
            goto L_8009698C;
    }
    goto skip_2;
    // 0x80096970: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    skip_2:
    // 0x80096974: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80096978: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x8009697C: lw          $v0, -0x6600($at)
    ctx->r2 = MEM_W(ctx->r1, -0X6600);
    // 0x80096980: beq         $v0, $a1, L_800968E8
    if (ctx->r2 == ctx->r5) {
        // 0x80096984: lui         $v0, 0x8000
        ctx->r2 = S32(0X8000 << 16);
            goto L_800968E8;
    }
    // 0x80096984: lui         $v0, 0x8000
    ctx->r2 = S32(0X8000 << 16);
    // 0x80096988: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
L_8009698C:
    // 0x8009698C: sltiu       $v0, $a0, 0x8
    ctx->r2 = ctx->r4 < 0X8 ? 1 : 0;
    // 0x80096990: bne         $v0, $zero, L_80096960
    if (ctx->r2 != 0) {
        // 0x80096994: addiu       $v1, $v1, 0xEF8
        ctx->r3 = ADD32(ctx->r3, 0XEF8);
            goto L_80096960;
    }
    // 0x80096994: addiu       $v1, $v1, 0xEF8
    ctx->r3 = ADD32(ctx->r3, 0XEF8);
    // 0x80096998: addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
L_8009699C:
    // 0x8009699C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x800969A0: beq         $v1, $v0, L_80096B24
    if (ctx->r3 == ctx->r2) {
        // 0x800969A4: andi        $v0, $s3, 0xFF
        ctx->r2 = ctx->r19 & 0XFF;
            goto L_80096B24;
    }
    // 0x800969A4: andi        $v0, $s3, 0xFF
    ctx->r2 = ctx->r19 & 0XFF;
    // 0x800969A8: beq         $v0, $zero, L_80096A1C
    if (ctx->r2 == 0) {
        // 0x800969AC: nop
    
            goto L_80096A1C;
    }
    // 0x800969AC: nop

    // 0x800969B0: lw          $a0, 0x8($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X8);
    // 0x800969B4: jal         0x80095FEC
    // 0x800969B8: nop

    func_80095FEC(rdram, ctx);
        goto after_8;
    // 0x800969B8: nop

    after_8:
    // 0x800969BC: lbu         $a0, 0x18($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X18);
    // 0x800969C0: lhu         $a1, 0xC($s0)
    ctx->r5 = MEM_HU(ctx->r16, 0XC);
    // 0x800969C4: lw          $a2, 0x8($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X8);
    // 0x800969C8: jal         0x80096284
    // 0x800969CC: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    func_80096284(rdram, ctx);
        goto after_9;
    // 0x800969CC: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    after_9:
    // 0x800969D0: lbu         $v0, 0x26($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X26);
    // 0x800969D4: andi        $v0, $v0, 0x10
    ctx->r2 = ctx->r2 & 0X10;
    // 0x800969D8: beq         $v0, $zero, L_800969F4
    if (ctx->r2 == 0) {
        // 0x800969DC: nop
    
            goto L_800969F4;
    }
    // 0x800969DC: nop

    // 0x800969E0: lw          $a0, 0x8($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X8);
    // 0x800969E4: lw          $a1, 0x1C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X1C);
    // 0x800969E8: lw          $a2, 0x20($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X20);
    // 0x800969EC: jal         0x80096118
    // 0x800969F0: nop

    func_80096118(rdram, ctx);
        goto after_10;
    // 0x800969F0: nop

    after_10:
L_800969F4:
    // 0x800969F4: lbu         $v0, 0x26($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X26);
    // 0x800969F8: andi        $v0, $v0, 0x20
    ctx->r2 = ctx->r2 & 0X20;
    // 0x800969FC: beq         $v0, $zero, L_80096B18
    if (ctx->r2 == 0) {
        // 0x80096A00: nop
    
            goto L_80096B18;
    }
    // 0x80096A00: nop

    // 0x80096A04: lw          $a0, 0x8($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X8);
    // 0x80096A08: lhu         $a1, 0x24($s0)
    ctx->r5 = MEM_HU(ctx->r16, 0X24);
    // 0x80096A0C: jal         0x80095EA8
    // 0x80096A10: nop

    func_80095EA8(rdram, ctx);
        goto after_11;
    // 0x80096A10: nop

    after_11:
    // 0x80096A14: j           L_80096B18
    // 0x80096A18: nop

        goto L_80096B18;
    // 0x80096A18: nop

L_80096A1C:
    // 0x80096A1C: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x80096A20: lbu         $v0, 0xF50($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0XF50);
    // 0x80096A24: lw          $s1, 0x8($s0)
    ctx->r17 = MEM_W(ctx->r16, 0X8);
    // 0x80096A28: beq         $v0, $zero, L_80096A48
    if (ctx->r2 == 0) {
        // 0x80096A2C: nop
    
            goto L_80096A48;
    }
    // 0x80096A2C: nop

    // 0x80096A30: jal         0x80092010
    // 0x80096A34: nop

    factor5MutexAcquire(rdram, ctx);
        goto after_12;
    // 0x80096A34: nop

    after_12:
    // 0x80096A38: jal         0x80095FEC
    // 0x80096A3C: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    func_80095FEC(rdram, ctx);
        goto after_13;
    // 0x80096A3C: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    after_13:
    // 0x80096A40: jal         0x8009205C
    // 0x80096A44: nop

    factor5MutexRelease(rdram, ctx);
        goto after_14;
    // 0x80096A44: nop

    after_14:
L_80096A48:
    // 0x80096A48: lbu         $s3, 0x18($s0)
    ctx->r19 = MEM_BU(ctx->r16, 0X18);
    // 0x80096A4C: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x80096A50: lbu         $v0, 0xF50($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0XF50);
    // 0x80096A54: lhu         $s1, 0xC($s0)
    ctx->r17 = MEM_HU(ctx->r16, 0XC);
    // 0x80096A58: lw          $s2, 0x8($s0)
    ctx->r18 = MEM_W(ctx->r16, 0X8);
    // 0x80096A5C: beq         $v0, $zero, L_80096A88
    if (ctx->r2 == 0) {
        // 0x80096A60: nop
    
            goto L_80096A88;
    }
    // 0x80096A60: nop

    // 0x80096A64: jal         0x80092010
    // 0x80096A68: nop

    factor5MutexAcquire(rdram, ctx);
        goto after_15;
    // 0x80096A68: nop

    after_15:
    // 0x80096A6C: addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    // 0x80096A70: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    // 0x80096A74: addu        $a2, $s2, $zero
    ctx->r6 = ADD32(ctx->r18, 0);
    // 0x80096A78: jal         0x80096284
    // 0x80096A7C: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    func_80096284(rdram, ctx);
        goto after_16;
    // 0x80096A7C: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    after_16:
    // 0x80096A80: jal         0x8009205C
    // 0x80096A84: nop

    factor5MutexRelease(rdram, ctx);
        goto after_17;
    // 0x80096A84: nop

    after_17:
L_80096A88:
    // 0x80096A88: lbu         $v0, 0x26($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X26);
    // 0x80096A8C: andi        $v0, $v0, 0x10
    ctx->r2 = ctx->r2 & 0X10;
    // 0x80096A90: beq         $v0, $zero, L_80096AD4
    if (ctx->r2 == 0) {
        // 0x80096A94: nop
    
            goto L_80096AD4;
    }
    // 0x80096A94: nop

    // 0x80096A98: lw          $s3, 0x8($s0)
    ctx->r19 = MEM_W(ctx->r16, 0X8);
    // 0x80096A9C: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x80096AA0: lbu         $v0, 0xF50($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0XF50);
    // 0x80096AA4: lw          $s1, 0x1C($s0)
    ctx->r17 = MEM_W(ctx->r16, 0X1C);
    // 0x80096AA8: lw          $s2, 0x20($s0)
    ctx->r18 = MEM_W(ctx->r16, 0X20);
    // 0x80096AAC: beq         $v0, $zero, L_80096AD4
    if (ctx->r2 == 0) {
        // 0x80096AB0: nop
    
            goto L_80096AD4;
    }
    // 0x80096AB0: nop

    // 0x80096AB4: jal         0x80092010
    // 0x80096AB8: nop

    factor5MutexAcquire(rdram, ctx);
        goto after_18;
    // 0x80096AB8: nop

    after_18:
    // 0x80096ABC: addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    // 0x80096AC0: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    // 0x80096AC4: jal         0x80096118
    // 0x80096AC8: addu        $a2, $s2, $zero
    ctx->r6 = ADD32(ctx->r18, 0);
    func_80096118(rdram, ctx);
        goto after_19;
    // 0x80096AC8: addu        $a2, $s2, $zero
    ctx->r6 = ADD32(ctx->r18, 0);
    after_19:
    // 0x80096ACC: jal         0x8009205C
    // 0x80096AD0: nop

    factor5MutexRelease(rdram, ctx);
        goto after_20;
    // 0x80096AD0: nop

    after_20:
L_80096AD4:
    // 0x80096AD4: lbu         $v0, 0x26($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X26);
    // 0x80096AD8: andi        $v0, $v0, 0x20
    ctx->r2 = ctx->r2 & 0X20;
    // 0x80096ADC: beq         $v0, $zero, L_80096B18
    if (ctx->r2 == 0) {
        // 0x80096AE0: nop
    
            goto L_80096B18;
    }
    // 0x80096AE0: nop

    // 0x80096AE4: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x80096AE8: lbu         $v0, 0xF50($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0XF50);
    // 0x80096AEC: lw          $s1, 0x8($s0)
    ctx->r17 = MEM_W(ctx->r16, 0X8);
    // 0x80096AF0: lhu         $s2, 0x24($s0)
    ctx->r18 = MEM_HU(ctx->r16, 0X24);
    // 0x80096AF4: beq         $v0, $zero, L_80096B18
    if (ctx->r2 == 0) {
        // 0x80096AF8: nop
    
            goto L_80096B18;
    }
    // 0x80096AF8: nop

    // 0x80096AFC: jal         0x80092010
    // 0x80096B00: nop

    factor5MutexAcquire(rdram, ctx);
        goto after_21;
    // 0x80096B00: nop

    after_21:
    // 0x80096B04: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x80096B08: jal         0x80095EA8
    // 0x80096B0C: addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    func_80095EA8(rdram, ctx);
        goto after_22;
    // 0x80096B0C: addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    after_22:
    // 0x80096B10: jal         0x8009205C
    // 0x80096B14: nop

    factor5MutexRelease(rdram, ctx);
        goto after_23;
    // 0x80096B14: nop

    after_23:
L_80096B18:
    // 0x80096B18: lw          $v0, 0x8($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X8);
    // 0x80096B1C: j           L_80096C64
    // 0x80096B20: sw          $v0, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->r2;
        goto L_80096C64;
    // 0x80096B20: sw          $v0, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->r2;
L_80096B24:
    // 0x80096B24: j           L_80096C64
    // 0x80096B28: sw          $v1, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->r3;
        goto L_80096C64;
    // 0x80096B28: sw          $v1, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->r3;
L_80096B2C:
    // 0x80096B2C: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // 0x80096B30: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // 0x80096B34: lbu         $v0, 0x26($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X26);
    // 0x80096B38: andi        $v0, $v0, 0x8
    ctx->r2 = ctx->r2 & 0X8;
    // 0x80096B3C: beq         $v0, $zero, L_80096B48
    if (ctx->r2 == 0) {
        // 0x80096B40: addiu       $v0, $zero, 0x14
        ctx->r2 = ADD32(0, 0X14);
            goto L_80096B48;
    }
    // 0x80096B40: addiu       $v0, $zero, 0x14
    ctx->r2 = ADD32(0, 0X14);
    // 0x80096B44: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
L_80096B48:
    // 0x80096B48: lbu         $v0, 0x26($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X26);
    // 0x80096B4C: andi        $v0, $v0, 0x20
    ctx->r2 = ctx->r2 & 0X20;
    // 0x80096B50: beq         $v0, $zero, L_80096B6C
    if (ctx->r2 == 0) {
        // 0x80096B54: nop
    
            goto L_80096B6C;
    }
    // 0x80096B54: nop

    // 0x80096B58: lw          $v0, 0x18($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X18);
    // 0x80096B5C: ori         $v0, $v0, 0x2
    ctx->r2 = ctx->r2 | 0X2;
    // 0x80096B60: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // 0x80096B64: lhu         $v0, 0x24($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X24);
    // 0x80096B68: sh          $v0, 0x24($sp)
    MEM_H(0X24, ctx->r29) = ctx->r2;
L_80096B6C:
    // 0x80096B6C: lbu         $v0, 0x26($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X26);
    // 0x80096B70: andi        $v0, $v0, 0x10
    ctx->r2 = ctx->r2 & 0X10;
    // 0x80096B74: beq         $v0, $zero, L_80096B98
    if (ctx->r2 == 0) {
        // 0x80096B78: nop
    
            goto L_80096B98;
    }
    // 0x80096B78: nop

    // 0x80096B7C: lw          $v0, 0x18($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X18);
    // 0x80096B80: ori         $v0, $v0, 0x1
    ctx->r2 = ctx->r2 | 0X1;
    // 0x80096B84: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // 0x80096B88: lw          $v0, 0x1C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1C);
    // 0x80096B8C: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x80096B90: lw          $v0, 0x20($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X20);
    // 0x80096B94: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
L_80096B98:
    // 0x80096B98: lhu         $v0, 0xC($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0XC);
    // 0x80096B9C: sh          $v0, 0x26($sp)
    MEM_H(0X26, ctx->r29) = ctx->r2;
    // 0x80096BA0: lbu         $v0, 0x18($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X18);
    // 0x80096BA4: sb          $zero, 0x30($sp)
    MEM_B(0X30, ctx->r29) = 0;
    // 0x80096BA8: sb          $v0, 0x28($sp)
    MEM_B(0X28, ctx->r29) = ctx->r2;
    // 0x80096BAC: andi        $v0, $s3, 0xFF
    ctx->r2 = ctx->r19 & 0XFF;
    // 0x80096BB0: beq         $v0, $zero, L_80096C00
    if (ctx->r2 == 0) {
        // 0x80096BB4: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80096C00;
    }
    // 0x80096BB4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80096BB8: lhu         $a0, 0x14($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X14);
    // 0x80096BBC: lhu         $a1, 0x16($s0)
    ctx->r5 = MEM_HU(ctx->r16, 0X16);
    // 0x80096BC0: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // 0x80096BC4: lw          $a2, 0x10($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X10);
    // 0x80096BC8: jal         0x80097AD0
    // 0x80096BCC: addiu       $a3, $sp, 0x18
    ctx->r7 = ADD32(ctx->r29, 0X18);
    func_80097AD0(rdram, ctx);
        goto after_24;
    // 0x80096BCC: addiu       $a3, $sp, 0x18
    ctx->r7 = ADD32(ctx->r29, 0X18);
    after_24:
    // 0x80096BD0: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // 0x80096BD4: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x80096BD8: beq         $a0, $v0, L_80096C64
    if (ctx->r4 == ctx->r2) {
        // 0x80096BDC: sw          $a0, 0x0($s4)
        MEM_W(0X0, ctx->r20) = ctx->r4;
            goto L_80096C64;
    }
    // 0x80096BDC: sw          $a0, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->r4;
    // 0x80096BE0: lbu         $v0, 0x26($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X26);
    // 0x80096BE4: andi        $v0, $v0, 0x80
    ctx->r2 = ctx->r2 & 0X80;
    // 0x80096BE8: beq         $v0, $zero, L_80096C64
    if (ctx->r2 == 0) {
        // 0x80096BEC: addu        $a1, $zero, $zero
        ctx->r5 = ADD32(0, 0);
            goto L_80096C64;
    }
    // 0x80096BEC: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x80096BF0: jal         0x80096118
    // 0x80096BF4: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    func_80096118(rdram, ctx);
        goto after_25;
    // 0x80096BF4: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    after_25:
    // 0x80096BF8: j           L_80096C64
    // 0x80096BFC: nop

        goto L_80096C64;
    // 0x80096BFC: nop

L_80096C00:
    // 0x80096C00: lhu         $a0, 0x14($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X14);
    // 0x80096C04: lhu         $a1, 0x16($s0)
    ctx->r5 = MEM_HU(ctx->r16, 0X16);
    // 0x80096C08: lw          $a2, 0x10($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X10);
    // 0x80096C0C: jal         0x80097C2C
    // 0x80096C10: addiu       $a3, $sp, 0x18
    ctx->r7 = ADD32(ctx->r29, 0X18);
    func_80097C2C(rdram, ctx);
        goto after_26;
    // 0x80096C10: addiu       $a3, $sp, 0x18
    ctx->r7 = ADD32(ctx->r29, 0X18);
    after_26:
    // 0x80096C14: addu        $s1, $v0, $zero
    ctx->r17 = ADD32(ctx->r2, 0);
    // 0x80096C18: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x80096C1C: beq         $s1, $v0, L_80096C64
    if (ctx->r17 == ctx->r2) {
        // 0x80096C20: sw          $s1, 0x0($s4)
        MEM_W(0X0, ctx->r20) = ctx->r17;
            goto L_80096C64;
    }
    // 0x80096C20: sw          $s1, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->r17;
    // 0x80096C24: lbu         $v0, 0x26($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X26);
    // 0x80096C28: andi        $v0, $v0, 0x80
    ctx->r2 = ctx->r2 & 0X80;
    // 0x80096C2C: beq         $v0, $zero, L_80096C64
    if (ctx->r2 == 0) {
        // 0x80096C30: nop
    
            goto L_80096C64;
    }
    // 0x80096C30: nop

    // 0x80096C34: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x80096C38: lbu         $v0, 0xF50($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0XF50);
    // 0x80096C3C: beq         $v0, $zero, L_80096C64
    if (ctx->r2 == 0) {
        // 0x80096C40: nop
    
            goto L_80096C64;
    }
    // 0x80096C40: nop

    // 0x80096C44: jal         0x80092010
    // 0x80096C48: nop

    factor5MutexAcquire(rdram, ctx);
        goto after_27;
    // 0x80096C48: nop

    after_27:
    // 0x80096C4C: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x80096C50: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x80096C54: jal         0x80096118
    // 0x80096C58: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    func_80096118(rdram, ctx);
        goto after_28;
    // 0x80096C58: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    after_28:
    // 0x80096C5C: jal         0x8009205C
    // 0x80096C60: nop

    factor5MutexRelease(rdram, ctx);
        goto after_29;
    // 0x80096C60: nop

    after_29:
L_80096C64:
    // 0x80096C64: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
    // 0x80096C68: lw          $s4, 0x48($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X48);
    // 0x80096C6C: lw          $s3, 0x44($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X44);
    // 0x80096C70: lw          $s2, 0x40($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X40);
    // 0x80096C74: lw          $s1, 0x3C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X3C);
    // 0x80096C78: lw          $s0, 0x38($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X38);
    // 0x80096C7C: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // 0x80096C80: jr          $ra
    // 0x80096C84: nop

    return;
    // 0x80096C84: nop

;}
RECOMP_FUNC void func_80096C88(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80096C88: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x80096C8C: lbu         $v0, 0xF50($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0XF50);
    // 0x80096C90: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80096C94: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x80096C98: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x80096C9C: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x80096CA0: addu        $s1, $a1, $zero
    ctx->r17 = ADD32(ctx->r5, 0);
    // 0x80096CA4: beq         $v0, $zero, L_80096CCC
    if (ctx->r2 == 0) {
        // 0x80096CA8: sw          $ra, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r31;
            goto L_80096CCC;
    }
    // 0x80096CA8: sw          $ra, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r31;
    // 0x80096CAC: jal         0x80092010
    // 0x80096CB0: nop

    factor5MutexAcquire(rdram, ctx);
        goto after_0;
    // 0x80096CB0: nop

    after_0:
    // 0x80096CB4: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x80096CB8: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    // 0x80096CBC: jal         0x800966A4
    // 0x80096CC0: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    func_800966A4(rdram, ctx);
        goto after_1;
    // 0x80096CC0: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    after_1:
    // 0x80096CC4: jal         0x8009205C
    // 0x80096CC8: nop

    factor5MutexRelease(rdram, ctx);
        goto after_2;
    // 0x80096CC8: nop

    after_2:
L_80096CCC:
    // 0x80096CCC: lw          $ra, 0x18($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X18);
    // 0x80096CD0: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x80096CD4: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x80096CD8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80096CDC: jr          $ra
    // 0x80096CE0: nop

    return;
    // 0x80096CE0: nop

;}
RECOMP_FUNC void func_80096CE4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80096CE4: lw          $a0, 0x0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X0);
    // 0x80096CE8: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x80096CEC: bne         $a0, $v0, L_80096CFC
    if (ctx->r4 != ctx->r2) {
        // 0x80096CF0: srl         $v0, $a0, 31
        ctx->r2 = S32(U32(ctx->r4) >> 31);
            goto L_80096CFC;
    }
    // 0x80096CF0: srl         $v0, $a0, 31
    ctx->r2 = S32(U32(ctx->r4) >> 31);
    // 0x80096CF4: j           L_80096D00
    // 0x80096CF8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80096D00;
    // 0x80096CF8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80096CFC:
    // 0x80096CFC: xori        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 ^ 0X1;
L_80096D00:
    // 0x80096D00: jr          $ra
    // 0x80096D04: nop

    return;
    // 0x80096D04: nop

;}
RECOMP_FUNC void func_80096D08(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80096D08: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x80096D0C: lw          $v0, 0x2038($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X2038);
    // 0x80096D10: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80096D14: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x80096D18: sw          $fp, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r30;
    // 0x80096D1C: sw          $s7, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r23;
    // 0x80096D20: sw          $s6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r22;
    // 0x80096D24: sw          $s5, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r21;
    // 0x80096D28: sw          $s4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r20;
    // 0x80096D2C: sw          $s3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r19;
    // 0x80096D30: sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // 0x80096D34: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x80096D38: beq         $v0, $zero, L_80097054
    if (ctx->r2 == 0) {
        // 0x80096D3C: sw          $s0, 0x10($sp)
        MEM_W(0X10, ctx->r29) = ctx->r16;
            goto L_80097054;
    }
    // 0x80096D3C: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x80096D40: addu        $s5, $zero, $zero
    ctx->r21 = ADD32(0, 0);
    // 0x80096D44: addiu       $fp, $zero, -0x1
    ctx->r30 = ADD32(0, -0X1);
    // 0x80096D48: lui         $s4, 0x8015
    ctx->r20 = S32(0X8015 << 16);
    // 0x80096D4C: addiu       $s4, $s4, -0x5740
    ctx->r20 = ADD32(ctx->r20, -0X5740);
    // 0x80096D50: addu        $s2, $zero, $zero
    ctx->r18 = ADD32(0, 0);
    // 0x80096D54: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80096D58: sw          $zero, -0x660C($at)
    MEM_W(-0X660C, ctx->r1) = 0;
    // 0x80096D5C: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80096D60: sw          $zero, -0x6604($at)
    MEM_W(-0X6604, ctx->r1) = 0;
    // 0x80096D64: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80096D68: sw          $zero, 0x29CC($at)
    MEM_W(0X29CC, ctx->r1) = 0;
L_80096D6C:
    // 0x80096D6C: lbu         $v0, 0x0($s4)
    ctx->r2 = MEM_BU(ctx->r20, 0X0);
    // 0x80096D70: beql        $v0, $zero, L_80097044
    if (ctx->r2 == 0) {
        // 0x80096D74: addiu       $s4, $s4, 0xEF8
        ctx->r20 = ADD32(ctx->r20, 0XEF8);
            goto L_80097044;
    }
    goto skip_0;
    // 0x80096D74: addiu       $s4, $s4, 0xEF8
    ctx->r20 = ADD32(ctx->r20, 0XEF8);
    skip_0:
    // 0x80096D78: lui         $v0, 0x8015
    ctx->r2 = S32(0X8015 << 16);
    // 0x80096D7C: addiu       $v0, $v0, -0x6600
    ctx->r2 = ADD32(ctx->r2, -0X6600);
    // 0x80096D80: addu        $v0, $s2, $v0
    ctx->r2 = ADD32(ctx->r18, ctx->r2);
    // 0x80096D84: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80096D88: sw          $v0, 0x29C0($at)
    MEM_W(0X29C0, ctx->r1) = ctx->r2;
    // 0x80096D8C: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80096D90: sw          $s5, 0x29C8($at)
    MEM_W(0X29C8, ctx->r1) = ctx->r21;
    // 0x80096D94: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80096D98: addu        $at, $at, $s2
    ctx->r1 = ADD32(ctx->r1, ctx->r18);
    // 0x80096D9C: lbu         $a0, -0x573C($at)
    ctx->r4 = MEM_BU(ctx->r1, -0X573C);
    // 0x80096DA0: jal         0x8008E1C4
    // 0x80096DA4: nop

    func_8008E1C4(rdram, ctx);
        goto after_0;
    // 0x80096DA4: nop

    after_0:
    // 0x80096DA8: lui         $a2, 0x8015
    ctx->r6 = S32(0X8015 << 16);
    // 0x80096DAC: lw          $a2, 0x29C0($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X29C0);
    // 0x80096DB0: lw          $v1, 0xE6C($a2)
    ctx->r3 = MEM_W(ctx->r6, 0XE6C);
    // 0x80096DB4: lw          $v1, 0x0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X0);
    // 0x80096DB8: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80096DBC: sb          $v0, -0x6608($at)
    MEM_B(-0X6608, ctx->r1) = ctx->r2;
    // 0x80096DC0: beq         $v1, $fp, L_80096E20
    if (ctx->r3 == ctx->r30) {
        // 0x80096DC4: nop
    
            goto L_80096E20;
    }
    // 0x80096DC4: nop

    // 0x80096DC8: addiu       $s0, $zero, -0x1
    ctx->r16 = ADD32(0, -0X1);
L_80096DCC:
    // 0x80096DCC: lw          $a1, 0xE6C($a2)
    ctx->r5 = MEM_W(ctx->r6, 0XE6C);
    // 0x80096DD0: lw          $v0, 0xE74($a2)
    ctx->r2 = MEM_W(ctx->r6, 0XE74);
    // 0x80096DD4: lw          $v1, 0x120($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X120);
    // 0x80096DD8: lw          $a0, 0x0($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X0);
    // 0x80096DDC: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80096DE0: sltu        $v0, $v0, $a0
    ctx->r2 = ctx->r2 < ctx->r4 ? 1 : 0;
    // 0x80096DE4: bne         $v0, $zero, L_80096E20
    if (ctx->r2 != 0) {
        // 0x80096DE8: nop
    
            goto L_80096E20;
    }
    // 0x80096DE8: nop

    // 0x80096DEC: lw          $a0, 0x4($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X4);
    // 0x80096DF0: lui         $a1, 0x8015
    ctx->r5 = S32(0X8015 << 16);
    // 0x80096DF4: lbu         $a1, 0x29CB($a1)
    ctx->r5 = MEM_BU(ctx->r5, 0X29CB);
    // 0x80096DF8: jal         0x80083D20
    // 0x80096DFC: sw          $a0, 0x124($a2)
    MEM_W(0X124, ctx->r6) = ctx->r4;
    func_80083D20(rdram, ctx);
        goto after_1;
    // 0x80096DFC: sw          $a0, 0x124($a2)
    MEM_W(0X124, ctx->r6) = ctx->r4;
    after_1:
    // 0x80096E00: lui         $a0, 0x8015
    ctx->r4 = S32(0X8015 << 16);
    // 0x80096E04: lw          $a0, 0x29C0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X29C0);
    // 0x80096E08: lw          $v1, 0xE6C($a0)
    ctx->r3 = MEM_W(ctx->r4, 0XE6C);
    // 0x80096E0C: addiu       $v0, $v1, 0x8
    ctx->r2 = ADD32(ctx->r3, 0X8);
    // 0x80096E10: sw          $v0, 0xE6C($a0)
    MEM_W(0XE6C, ctx->r4) = ctx->r2;
    // 0x80096E14: lw          $v0, 0x8($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X8);
    // 0x80096E18: bne         $v0, $s0, L_80096DCC
    if (ctx->r2 != ctx->r16) {
        // 0x80096E1C: addu        $a2, $a0, $zero
        ctx->r6 = ADD32(ctx->r4, 0);
            goto L_80096DCC;
    }
    // 0x80096E1C: addu        $a2, $a0, $zero
    ctx->r6 = ADD32(ctx->r4, 0);
L_80096E20:
    // 0x80096E20: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80096E24: lw          $a0, 0x2038($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X2038);
    // 0x80096E28: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x80096E2C: lw          $v0, 0x40C0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X40C0);
    // 0x80096E30: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x80096E34: div         $zero, $a0, $v0
    lo = S32(S64(S32(ctx->r4)) / S64(S32(ctx->r2))); hi = S32(S64(S32(ctx->r4)) % S64(S32(ctx->r2)));
    // 0x80096E38: bne         $v0, $zero, L_80096E44
    if (ctx->r2 != 0) {
        // 0x80096E3C: nop
    
            goto L_80096E44;
    }
    // 0x80096E3C: nop

    // 0x80096E40: break       7
    do_break(2148101696);
L_80096E44:
    // 0x80096E44: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80096E48: bne         $v0, $at, L_80096E5C
    if (ctx->r2 != ctx->r1) {
        // 0x80096E4C: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80096E5C;
    }
    // 0x80096E4C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80096E50: bne         $a0, $at, L_80096E5C
    if (ctx->r4 != ctx->r1) {
        // 0x80096E54: nop
    
            goto L_80096E5C;
    }
    // 0x80096E54: nop

    // 0x80096E58: break       6
    do_break(2148101720);
L_80096E5C:
    // 0x80096E5C: mflo        $a0
    ctx->r4 = lo;
    // 0x80096E60: lui         $a1, 0x8015
    ctx->r5 = S32(0X8015 << 16);
    // 0x80096E64: lw          $a1, 0x29C0($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X29C0);
    // 0x80096E68: lw          $v1, 0x124($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X124);
    // 0x80096E6C: sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3 << 1);
    // 0x80096E70: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80096E74: sll         $v0, $v0, 9
    ctx->r2 = S32(ctx->r2 << 9);
    // 0x80096E78: lui         $v1, 0x8888
    ctx->r3 = S32(0X8888 << 16);
    // 0x80096E7C: ori         $v1, $v1, 0x8889
    ctx->r3 = ctx->r3 | 0X8889;
    // 0x80096E80: multu       $v0, $v1
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80096E84: mfhi        $t0
    ctx->r8 = hi;
    // 0x80096E88: srl         $v0, $t0, 7
    ctx->r2 = S32(U32(ctx->r8) >> 7);
    // 0x80096E8C: nop

    // 0x80096E90: mult        $v0, $a0
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80096E94: mflo        $v1
    ctx->r3 = lo;
    // 0x80096E98: lhu         $v0, 0xEC2($a1)
    ctx->r2 = MEM_HU(ctx->r5, 0XEC2);
    // 0x80096E9C: nop

    // 0x80096EA0: mult        $v1, $v0
    result = S64(S32(ctx->r3)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80096EA4: mflo        $v0
    ctx->r2 = lo;
    // 0x80096EA8: srl         $v1, $v0, 8
    ctx->r3 = S32(U32(ctx->r2) >> 8);
    // 0x80096EAC: andi        $v1, $v1, 0xFFFF
    ctx->r3 = ctx->r3 & 0XFFFF;
    // 0x80096EB0: sw          $v1, 0x118($a1)
    MEM_W(0X118, ctx->r5) = ctx->r3;
    // 0x80096EB4: lw          $v1, 0xE70($a1)
    ctx->r3 = MEM_W(ctx->r5, 0XE70);
    // 0x80096EB8: lw          $a0, 0x118($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X118);
    // 0x80096EBC: srl         $v0, $v0, 24
    ctx->r2 = S32(U32(ctx->r2) >> 24);
    // 0x80096EC0: sw          $v0, 0x11C($a1)
    MEM_W(0X11C, ctx->r5) = ctx->r2;
    // 0x80096EC4: lw          $a2, 0x11C($a1)
    ctx->r6 = MEM_W(ctx->r5, 0X11C);
    // 0x80096EC8: sra         $v0, $v0, 1
    ctx->r2 = S32(SIGNED(ctx->r2) >> 1);
    // 0x80096ECC: sw          $v0, 0x120($a1)
    MEM_W(0X120, ctx->r5) = ctx->r2;
    // 0x80096ED0: lw          $v0, 0xE74($a1)
    ctx->r2 = MEM_W(ctx->r5, 0XE74);
    // 0x80096ED4: addu        $v1, $v1, $a0
    ctx->r3 = ADD32(ctx->r3, ctx->r4);
    // 0x80096ED8: andi        $a0, $v1, 0xFFFF
    ctx->r4 = ctx->r3 & 0XFFFF;
    // 0x80096EDC: srl         $v1, $v1, 16
    ctx->r3 = S32(U32(ctx->r3) >> 16);
    // 0x80096EE0: addu        $v1, $v1, $a2
    ctx->r3 = ADD32(ctx->r3, ctx->r6);
    // 0x80096EE4: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80096EE8: sw          $a0, 0xE70($a1)
    MEM_W(0XE70, ctx->r5) = ctx->r4;
    // 0x80096EEC: jal         0x80095244
    // 0x80096EF0: sw          $v0, 0xE74($a1)
    MEM_W(0XE74, ctx->r5) = ctx->r2;
    func_80095244(rdram, ctx);
        goto after_2;
    // 0x80096EF0: sw          $v0, 0xE74($a1)
    MEM_W(0XE74, ctx->r5) = ctx->r2;
    after_2:
    // 0x80096EF4: jal         0x80094958
    // 0x80096EF8: addu        $s7, $v0, $zero
    ctx->r23 = ADD32(ctx->r2, 0);
    func_80094958(rdram, ctx);
        goto after_3;
    // 0x80096EF8: addu        $s7, $v0, $zero
    ctx->r23 = ADD32(ctx->r2, 0);
    after_3:
    // 0x80096EFC: jal         0x80094EE4
    // 0x80096F00: addu        $s6, $v0, $zero
    ctx->r22 = ADD32(ctx->r2, 0);
    func_80094EE4(rdram, ctx);
        goto after_4;
    // 0x80096F00: addu        $s6, $v0, $zero
    ctx->r22 = ADD32(ctx->r2, 0);
    after_4:
    // 0x80096F04: jal         0x80095090
    // 0x80096F08: nop

    func_80095090(rdram, ctx);
        goto after_5;
    // 0x80096F08: nop

    after_5:
    // 0x80096F0C: lui         $a1, 0x8015
    ctx->r5 = S32(0X8015 << 16);
    // 0x80096F10: lw          $a1, 0x29C0($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X29C0);
    // 0x80096F14: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // 0x80096F18: addu        $a3, $a1, $zero
    ctx->r7 = ADD32(ctx->r5, 0);
L_80096F1C:
    // 0x80096F1C: lw          $v1, 0x568($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X568);
    // 0x80096F20: lw          $v0, 0x118($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X118);
    // 0x80096F24: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x80096F28: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x80096F2C: andi        $v0, $v1, 0xFFFF
    ctx->r2 = ctx->r3 & 0XFFFF;
    // 0x80096F30: sw          $v0, 0x568($a1)
    MEM_W(0X568, ctx->r5) = ctx->r2;
    // 0x80096F34: lw          $a0, 0x11C($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X11C);
    // 0x80096F38: lw          $v0, 0x56C($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X56C);
    // 0x80096F3C: sra         $v1, $v1, 16
    ctx->r3 = S32(SIGNED(ctx->r3) >> 16);
    // 0x80096F40: addu        $v1, $v1, $a0
    ctx->r3 = ADD32(ctx->r3, ctx->r4);
    // 0x80096F44: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80096F48: sw          $v0, 0x56C($a1)
    MEM_W(0X56C, ctx->r5) = ctx->r2;
    // 0x80096F4C: slti        $v0, $a2, 0x40
    ctx->r2 = SIGNED(ctx->r6) < 0X40 ? 1 : 0;
    // 0x80096F50: bne         $v0, $zero, L_80096F1C
    if (ctx->r2 != 0) {
        // 0x80096F54: addiu       $a1, $a1, 0x24
        ctx->r5 = ADD32(ctx->r5, 0X24);
            goto L_80096F1C;
    }
    // 0x80096F54: addiu       $a1, $a1, 0x24
    ctx->r5 = ADD32(ctx->r5, 0X24);
    // 0x80096F58: jal         0x80094DB4
    // 0x80096F5C: nop

    func_80094DB4(rdram, ctx);
        goto after_6;
    // 0x80096F5C: nop

    after_6:
    // 0x80096F60: lui         $v1, 0x8015
    ctx->r3 = S32(0X8015 << 16);
    // 0x80096F64: lw          $v1, 0x29C0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X29C0);
    // 0x80096F68: lw          $s0, 0xE7C($v1)
    ctx->r16 = MEM_W(ctx->r3, 0XE7C);
    // 0x80096F6C: beq         $s0, $zero, L_80097008
    if (ctx->r16 == 0) {
        // 0x80096F70: addu        $s3, $v0, $zero
        ctx->r19 = ADD32(ctx->r2, 0);
            goto L_80097008;
    }
    // 0x80096F70: addu        $s3, $v0, $zero
    ctx->r19 = ADD32(ctx->r2, 0);
L_80096F74:
    // 0x80096F74: lui         $v0, 0x8015
    ctx->r2 = S32(0X8015 << 16);
    // 0x80096F78: lw          $v0, 0x29CC($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X29CC);
    // 0x80096F7C: lw          $a0, 0x8($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X8);
    // 0x80096F80: lw          $s1, 0x0($s0)
    ctx->r17 = MEM_W(ctx->r16, 0X0);
    // 0x80096F84: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80096F88: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80096F8C: sw          $v0, 0x29CC($at)
    MEM_W(0X29CC, ctx->r1) = ctx->r2;
    // 0x80096F90: jal         0x80088068
    // 0x80096F94: nop

    func_80088068(rdram, ctx);
        goto after_7;
    // 0x80096F94: nop

    after_7:
    // 0x80096F98: bnel        $v0, $fp, L_80097000
    if (ctx->r2 != ctx->r30) {
        // 0x80096F9C: addu        $s0, $s1, $zero
        ctx->r16 = ADD32(ctx->r17, 0);
            goto L_80097000;
    }
    goto skip_1;
    // 0x80096F9C: addu        $s0, $s1, $zero
    ctx->r16 = ADD32(ctx->r17, 0);
    skip_1:
    // 0x80096FA0: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x80096FA4: beq         $v1, $zero, L_80096FB4
    if (ctx->r3 == 0) {
        // 0x80096FA8: nop
    
            goto L_80096FB4;
    }
    // 0x80096FA8: nop

    // 0x80096FAC: lw          $v0, 0x4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X4);
    // 0x80096FB0: sw          $v0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r2;
L_80096FB4:
    // 0x80096FB4: lw          $v1, 0x4($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X4);
    // 0x80096FB8: beq         $v1, $zero, L_80096FCC
    if (ctx->r3 == 0) {
        // 0x80096FBC: nop
    
            goto L_80096FCC;
    }
    // 0x80096FBC: nop

    // 0x80096FC0: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80096FC4: j           L_80096FDC
    // 0x80096FC8: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
        goto L_80096FDC;
    // 0x80096FC8: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
L_80096FCC:
    // 0x80096FCC: lui         $v1, 0x8015
    ctx->r3 = S32(0X8015 << 16);
    // 0x80096FD0: lw          $v1, 0x29C0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X29C0);
    // 0x80096FD4: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80096FD8: sw          $v0, 0xE7C($v1)
    MEM_W(0XE7C, ctx->r3) = ctx->r2;
L_80096FDC:
    // 0x80096FDC: lui         $v0, 0x8015
    ctx->r2 = S32(0X8015 << 16);
    // 0x80096FE0: lw          $v0, 0x29C4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X29C4);
    // 0x80096FE4: beq         $v0, $zero, L_80096FF0
    if (ctx->r2 == 0) {
        // 0x80096FE8: sw          $v0, 0x0($s0)
        MEM_W(0X0, ctx->r16) = ctx->r2;
            goto L_80096FF0;
    }
    // 0x80096FE8: sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
    // 0x80096FEC: sw          $s0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r16;
L_80096FF0:
    // 0x80096FF0: sw          $zero, 0x4($s0)
    MEM_W(0X4, ctx->r16) = 0;
    // 0x80096FF4: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80096FF8: sw          $s0, 0x29C4($at)
    MEM_W(0X29C4, ctx->r1) = ctx->r16;
    // 0x80096FFC: addu        $s0, $s1, $zero
    ctx->r16 = ADD32(ctx->r17, 0);
L_80097000:
    // 0x80097000: bne         $s0, $zero, L_80096F74
    if (ctx->r16 != 0) {
        // 0x80097004: nop
    
            goto L_80096F74;
    }
    // 0x80097004: nop

L_80097008:
    // 0x80097008: andi        $v1, $s7, 0xFF
    ctx->r3 = ctx->r23 & 0XFF;
    // 0x8009700C: sltiu       $v1, $v1, 0x1
    ctx->r3 = ctx->r3 < 0X1 ? 1 : 0;
    // 0x80097010: andi        $v0, $s6, 0xFF
    ctx->r2 = ctx->r22 & 0XFF;
    // 0x80097014: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80097018: and         $v1, $v1, $v0
    ctx->r3 = ctx->r3 & ctx->r2;
    // 0x8009701C: beq         $v1, $zero, L_80097040
    if (ctx->r3 == 0) {
        // 0x80097020: andi        $v0, $s3, 0xFF
        ctx->r2 = ctx->r19 & 0XFF;
            goto L_80097040;
    }
    // 0x80097020: andi        $v0, $s3, 0xFF
    ctx->r2 = ctx->r19 & 0XFF;
    // 0x80097024: bnel        $v0, $zero, L_80097044
    if (ctx->r2 != 0) {
        // 0x80097028: addiu       $s4, $s4, 0xEF8
        ctx->r20 = ADD32(ctx->r20, 0XEF8);
            goto L_80097044;
    }
    goto skip_2;
    // 0x80097028: addiu       $s4, $s4, 0xEF8
    ctx->r20 = ADD32(ctx->r20, 0XEF8);
    skip_2:
    // 0x8009702C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80097030: sb          $zero, 0x0($s4)
    MEM_B(0X0, ctx->r20) = 0;
    // 0x80097034: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80097038: addu        $at, $at, $s2
    ctx->r1 = ADD32(ctx->r1, ctx->r18);
    // 0x8009703C: sb          $v0, -0x573F($at)
    MEM_B(-0X573F, ctx->r1) = ctx->r2;
L_80097040:
    // 0x80097040: addiu       $s4, $s4, 0xEF8
    ctx->r20 = ADD32(ctx->r20, 0XEF8);
L_80097044:
    // 0x80097044: addiu       $s5, $s5, 0x1
    ctx->r21 = ADD32(ctx->r21, 0X1);
    // 0x80097048: sltiu       $v0, $s5, 0x8
    ctx->r2 = ctx->r21 < 0X8 ? 1 : 0;
    // 0x8009704C: bne         $v0, $zero, L_80096D6C
    if (ctx->r2 != 0) {
        // 0x80097050: addiu       $s2, $s2, 0xEF8
        ctx->r18 = ADD32(ctx->r18, 0XEF8);
            goto L_80096D6C;
    }
    // 0x80097050: addiu       $s2, $s2, 0xEF8
    ctx->r18 = ADD32(ctx->r18, 0XEF8);
L_80097054:
    // 0x80097054: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x80097058: lw          $fp, 0x30($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X30);
    // 0x8009705C: lw          $s7, 0x2C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X2C);
    // 0x80097060: lw          $s6, 0x28($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X28);
    // 0x80097064: lw          $s5, 0x24($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X24);
    // 0x80097068: lw          $s4, 0x20($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X20);
    // 0x8009706C: lw          $s3, 0x1C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X1C);
    // 0x80097070: lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X18);
    // 0x80097074: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x80097078: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x8009707C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80097080: jr          $ra
    // 0x80097084: nop

    return;
    // 0x80097084: nop

;}
RECOMP_FUNC void func_80097088(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80097088: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x8009708C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80097090: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
L_80097094:
    // 0x80097094: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80097098: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x8009709C: sb          $zero, -0x5740($at)
    MEM_B(-0X5740, ctx->r1) = 0;
    // 0x800970A0: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x800970A4: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x800970A8: sb          $a1, -0x573F($at)
    MEM_B(-0X573F, ctx->r1) = ctx->r5;
    // 0x800970AC: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x800970B0: sltiu       $v0, $a0, 0x8
    ctx->r2 = ctx->r4 < 0X8 ? 1 : 0;
    // 0x800970B4: bne         $v0, $zero, L_80097094
    if (ctx->r2 != 0) {
        // 0x800970B8: addiu       $v1, $v1, 0xEF8
        ctx->r3 = ADD32(ctx->r3, 0XEF8);
            goto L_80097094;
    }
    // 0x800970B8: addiu       $v1, $v1, 0xEF8
    ctx->r3 = ADD32(ctx->r3, 0XEF8);
    // 0x800970BC: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
    // 0x800970C0: lui         $v0, 0x8015
    ctx->r2 = S32(0X8015 << 16);
    // 0x800970C4: addiu       $v0, $v0, 0x11C0
    ctx->r2 = ADD32(ctx->r2, 0X11C0);
    // 0x800970C8: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x800970CC: sw          $v0, 0x29C4($at)
    MEM_W(0X29C4, ctx->r1) = ctx->r2;
    // 0x800970D0: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // 0x800970D4: addu        $a1, $v0, $zero
    ctx->r5 = ADD32(ctx->r2, 0);
    // 0x800970D8: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
L_800970DC:
    // 0x800970DC: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x800970E0: addu        $at, $at, $a0
    ctx->r1 = ADD32(ctx->r1, ctx->r4);
    // 0x800970E4: sw          $v1, 0x11C4($at)
    MEM_W(0X11C4, ctx->r1) = ctx->r3;
    // 0x800970E8: bnel        $v1, $zero, L_800970F0
    if (ctx->r3 != 0) {
        // 0x800970EC: sw          $a1, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->r5;
            goto L_800970F0;
    }
    goto skip_0;
    // 0x800970EC: sw          $a1, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r5;
    skip_0:
L_800970F0:
    // 0x800970F0: addu        $v1, $a1, $zero
    ctx->r3 = ADD32(ctx->r5, 0);
    // 0x800970F4: addiu       $a1, $v1, 0x18
    ctx->r5 = ADD32(ctx->r3, 0X18);
    // 0x800970F8: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x800970FC: slti        $v0, $a2, 0x100
    ctx->r2 = SIGNED(ctx->r6) < 0X100 ? 1 : 0;
    // 0x80097100: bne         $v0, $zero, L_800970DC
    if (ctx->r2 != 0) {
        // 0x80097104: addiu       $a0, $a0, 0x18
        ctx->r4 = ADD32(ctx->r4, 0X18);
            goto L_800970DC;
    }
    // 0x80097104: addiu       $a0, $a0, 0x18
    ctx->r4 = ADD32(ctx->r4, 0X18);
    // 0x80097108: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
    // 0x8009710C: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80097110: sw          $zero, -0x6610($at)
    MEM_W(-0X6610, ctx->r1) = 0;
    // 0x80097114: jr          $ra
    // 0x80097118: nop

    return;
    // 0x80097118: nop

;}
RECOMP_FUNC void fake_func_8009711C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
;}
RECOMP_FUNC void func_80097120(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80097120: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80097124: sh          $zero, 0x2A10($at)
    MEM_H(0X2A10, ctx->r1) = 0;
    // 0x80097128: jr          $ra
    // 0x8009712C: nop

    return;
    // 0x8009712C: nop

;}
RECOMP_FUNC void func_80097130(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80097130: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80097134: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x80097138: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x8009713C: sw          $ra, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r31;
    // 0x80097140: sw          $s3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r19;
    // 0x80097144: sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // 0x80097148: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x8009714C: lhu         $a0, 0x0($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X0);
    // 0x80097150: ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
    // 0x80097154: andi        $v1, $a0, 0xFFFF
    ctx->r3 = ctx->r4 & 0XFFFF;
    // 0x80097158: beq         $v1, $v0, L_800971C8
    if (ctx->r3 == ctx->r2) {
        // 0x8009715C: addu        $s1, $a1, $zero
        ctx->r17 = ADD32(ctx->r5, 0);
            goto L_800971C8;
    }
    // 0x8009715C: addu        $s1, $a1, $zero
    ctx->r17 = ADD32(ctx->r5, 0);
    // 0x80097160: addiu       $s3, $zero, -0x1
    ctx->r19 = ADD32(0, -0X1);
    // 0x80097164: ori         $s2, $zero, 0xFFFF
    ctx->r18 = 0 | 0XFFFF;
L_80097168:
    // 0x80097168: lw          $v0, 0x4($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X4);
    // 0x8009716C: addu        $a1, $s1, $v0
    ctx->r5 = ADD32(ctx->r17, ctx->r2);
    // 0x80097170: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x80097174: beq         $v0, $s3, L_800971A4
    if (ctx->r2 == ctx->r19) {
        // 0x80097178: addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
            goto L_800971A4;
    }
    // 0x80097178: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // 0x8009717C: andi        $v1, $a0, 0xFFFF
    ctx->r3 = ctx->r4 & 0XFFFF;
    // 0x80097180: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
L_80097184:
    // 0x80097184: lhu         $v0, 0x4($a1)
    ctx->r2 = MEM_HU(ctx->r5, 0X4);
    // 0x80097188: beq         $v0, $v1, L_800971A4
    if (ctx->r2 == ctx->r3) {
        // 0x8009718C: addu        $v0, $a1, $zero
        ctx->r2 = ADD32(ctx->r5, 0);
            goto L_800971A4;
    }
    // 0x8009718C: addu        $v0, $a1, $zero
    ctx->r2 = ADD32(ctx->r5, 0);
    // 0x80097190: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x80097194: addu        $a1, $a1, $v0
    ctx->r5 = ADD32(ctx->r5, ctx->r2);
    // 0x80097198: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x8009719C: bne         $v0, $a0, L_80097184
    if (ctx->r2 != ctx->r4) {
        // 0x800971A0: addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
            goto L_80097184;
    }
    // 0x800971A0: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_800971A4:
    // 0x800971A4: beql        $v0, $zero, L_800971BC
    if (ctx->r2 == 0) {
        // 0x800971A8: addiu       $s0, $s0, 0x2
        ctx->r16 = ADD32(ctx->r16, 0X2);
            goto L_800971BC;
    }
    goto skip_0;
    // 0x800971A8: addiu       $s0, $s0, 0x2
    ctx->r16 = ADD32(ctx->r16, 0X2);
    skip_0:
    // 0x800971AC: lhu         $a0, 0x0($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X0);
    // 0x800971B0: jal         0x80085098
    // 0x800971B4: addiu       $a1, $v0, 0x8
    ctx->r5 = ADD32(ctx->r2, 0X8);
    func_80085098(rdram, ctx);
        goto after_0;
    // 0x800971B4: addiu       $a1, $v0, 0x8
    ctx->r5 = ADD32(ctx->r2, 0X8);
    after_0:
    // 0x800971B8: addiu       $s0, $s0, 0x2
    ctx->r16 = ADD32(ctx->r16, 0X2);
L_800971BC:
    // 0x800971BC: lhu         $a0, 0x0($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X0);
    // 0x800971C0: bne         $a0, $s2, L_80097168
    if (ctx->r4 != ctx->r18) {
        // 0x800971C4: nop
    
            goto L_80097168;
    }
    // 0x800971C4: nop

L_800971C8:
    // 0x800971C8: lw          $ra, 0x20($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X20);
    // 0x800971CC: lw          $s3, 0x1C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X1C);
    // 0x800971D0: lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X18);
    // 0x800971D4: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x800971D8: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x800971DC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800971E0: jr          $ra
    // 0x800971E4: nop

    return;
    // 0x800971E4: nop

;}
