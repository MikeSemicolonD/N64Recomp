#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void func_800595A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800595A0: lw          $a3, 0x20($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X20);
    // 0x800595A4: beq         $a3, $zero, L_8005960C
    if (ctx->r7 == 0) {
        // 0x800595A8: andi        $a1, $a1, 0xFFFF
        ctx->r5 = ctx->r5 & 0XFFFF;
            goto L_8005960C;
    }
    // 0x800595A8: andi        $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 & 0XFFFF;
    // 0x800595AC: ori         $t1, $zero, 0xFFFF
    ctx->r9 = 0 | 0XFFFF;
    // 0x800595B0: sll         $a2, $a2, 16
    ctx->r6 = S32(ctx->r6 << 16);
    // 0x800595B4: lui         $t0, 0x3F00
    ctx->r8 = S32(0X3F00 << 16);
L_800595B8:
    // 0x800595B8: lw          $a0, 0xC($a3)
    ctx->r4 = MEM_W(ctx->r7, 0XC);
    // 0x800595BC: lw          $v1, 0x8($a3)
    ctx->r3 = MEM_W(ctx->r7, 0X8);
    // 0x800595C0: blez        $a0, L_80059600
    if (SIGNED(ctx->r4) <= 0) {
        // 0x800595C4: nop
    
            goto L_80059600;
    }
    // 0x800595C4: nop

L_800595C8:
    // 0x800595C8: beq         $a1, $t1, L_800595DC
    if (ctx->r5 == ctx->r9) {
        // 0x800595CC: nop
    
            goto L_800595DC;
    }
    // 0x800595CC: nop

    // 0x800595D0: lhu         $v0, 0x8($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X8);
    // 0x800595D4: bne         $v0, $a1, L_800595E8
    if (ctx->r2 != ctx->r5) {
        // 0x800595D8: nop
    
            goto L_800595E8;
    }
    // 0x800595D8: nop

L_800595DC:
    // 0x800595DC: lhu         $v0, 0xA($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0XA);
    // 0x800595E0: or          $v0, $v0, $a2
    ctx->r2 = ctx->r2 | ctx->r6;
    // 0x800595E4: sw          $v0, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r2;
L_800595E8:
    // 0x800595E8: lw          $v0, 0x4($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X4);
    // 0x800595EC: addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
    // 0x800595F0: and         $v0, $v0, $t0
    ctx->r2 = ctx->r2 & ctx->r8;
    // 0x800595F4: srl         $v0, $v0, 22
    ctx->r2 = S32(U32(ctx->r2) >> 22);
    // 0x800595F8: bgtz        $a0, L_800595C8
    if (SIGNED(ctx->r4) > 0) {
        // 0x800595FC: addu        $v1, $v1, $v0
        ctx->r3 = ADD32(ctx->r3, ctx->r2);
            goto L_800595C8;
    }
    // 0x800595FC: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
L_80059600:
    // 0x80059600: lw          $a3, 0x0($a3)
    ctx->r7 = MEM_W(ctx->r7, 0X0);
    // 0x80059604: bne         $a3, $zero, L_800595B8
    if (ctx->r7 != 0) {
        // 0x80059608: nop
    
            goto L_800595B8;
    }
    // 0x80059608: nop

L_8005960C:
    // 0x8005960C: jr          $ra
    // 0x80059610: nop

    return;
    // 0x80059610: nop

;}
RECOMP_FUNC void func_80059614(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80059614: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80059618: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x8005961C: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x80059620: lw          $a0, 0x10($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X10);
    // 0x80059624: jal         0x80059638
    // 0x80059628: nop

    func_80059638(rdram, ctx);
        goto after_0;
    // 0x80059628: nop

    after_0:
    // 0x8005962C: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x80059630: jr          $ra
    // 0x80059634: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80059634: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_80059638(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80059638: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8005963C: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x80059640: addu        $s1, $a0, $zero
    ctx->r17 = ADD32(ctx->r4, 0);
    // 0x80059644: sw          $ra, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r31;
    // 0x80059648: beq         $s1, $zero, L_800596B0
    if (ctx->r17 == 0) {
        // 0x8005964C: sw          $s0, 0x10($sp)
        MEM_W(0X10, ctx->r29) = ctx->r16;
            goto L_800596B0;
    }
    // 0x8005964C: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
L_80059650:
    // 0x80059650: lw          $a0, 0x10($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X10);
    // 0x80059654: beq         $a0, $zero, L_80059690
    if (ctx->r4 == 0) {
        // 0x80059658: nop
    
            goto L_80059690;
    }
    // 0x80059658: nop

    // 0x8005965C: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
L_80059660:
    // 0x80059660: lw          $v0, 0xC($s0)
    ctx->r2 = MEM_W(ctx->r16, 0XC);
    // 0x80059664: andi        $v0, $v0, 0x10
    ctx->r2 = ctx->r2 & 0X10;
    // 0x80059668: beq         $v0, $zero, L_80059684
    if (ctx->r2 == 0) {
        // 0x8005966C: nop
    
            goto L_80059684;
    }
    // 0x8005966C: nop

    // 0x80059670: jal         0x80008350
    // 0x80059674: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_80008350(rdram, ctx);
        goto after_0;
    // 0x80059674: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_0:
    // 0x80059678: lw          $v0, 0xC($s0)
    ctx->r2 = MEM_W(ctx->r16, 0XC);
    // 0x8005967C: ori         $v0, $v0, 0x8
    ctx->r2 = ctx->r2 | 0X8;
    // 0x80059680: sw          $v0, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r2;
L_80059684:
    // 0x80059684: lw          $s0, 0x0($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X0);
    // 0x80059688: bne         $s0, $zero, L_80059660
    if (ctx->r16 != 0) {
        // 0x8005968C: nop
    
            goto L_80059660;
    }
    // 0x8005968C: nop

L_80059690:
    // 0x80059690: lw          $a0, 0xC($s1)
    ctx->r4 = MEM_W(ctx->r17, 0XC);
    // 0x80059694: beq         $a0, $zero, L_800596A4
    if (ctx->r4 == 0) {
        // 0x80059698: nop
    
            goto L_800596A4;
    }
    // 0x80059698: nop

    // 0x8005969C: jal         0x80059638
    // 0x800596A0: nop

    func_80059638(rdram, ctx);
        goto after_1;
    // 0x800596A0: nop

    after_1:
L_800596A4:
    // 0x800596A4: lw          $s1, 0x0($s1)
    ctx->r17 = MEM_W(ctx->r17, 0X0);
    // 0x800596A8: bne         $s1, $zero, L_80059650
    if (ctx->r17 != 0) {
        // 0x800596AC: nop
    
            goto L_80059650;
    }
    // 0x800596AC: nop

L_800596B0:
    // 0x800596B0: lw          $ra, 0x18($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X18);
    // 0x800596B4: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x800596B8: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x800596BC: jr          $ra
    // 0x800596C0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x800596C0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_800596C4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800596C4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800596C8: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x800596CC: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x800596D0: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x800596D4: addu        $s1, $a1, $zero
    ctx->r17 = ADD32(ctx->r5, 0);
    // 0x800596D8: beq         $s0, $zero, L_80059714
    if (ctx->r16 == 0) {
        // 0x800596DC: sw          $ra, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r31;
            goto L_80059714;
    }
    // 0x800596DC: sw          $ra, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r31;
L_800596E0:
    // 0x800596E0: lw          $a0, 0x10($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X10);
    // 0x800596E4: beq         $a0, $zero, L_800596F4
    if (ctx->r4 == 0) {
        // 0x800596E8: nop
    
            goto L_800596F4;
    }
    // 0x800596E8: nop

    // 0x800596EC: jal         0x80058B40
    // 0x800596F0: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    func_80058B40(rdram, ctx);
        goto after_0;
    // 0x800596F0: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    after_0:
L_800596F4:
    // 0x800596F4: lw          $a0, 0xC($s0)
    ctx->r4 = MEM_W(ctx->r16, 0XC);
    // 0x800596F8: beq         $a0, $zero, L_80059708
    if (ctx->r4 == 0) {
        // 0x800596FC: nop
    
            goto L_80059708;
    }
    // 0x800596FC: nop

    // 0x80059700: jal         0x800596C4
    // 0x80059704: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    func_800596C4(rdram, ctx);
        goto after_1;
    // 0x80059704: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    after_1:
L_80059708:
    // 0x80059708: lw          $s0, 0x0($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X0);
    // 0x8005970C: bne         $s0, $zero, L_800596E0
    if (ctx->r16 != 0) {
        // 0x80059710: nop
    
            goto L_800596E0;
    }
    // 0x80059710: nop

L_80059714:
    // 0x80059714: lw          $ra, 0x18($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X18);
    // 0x80059718: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x8005971C: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x80059720: jr          $ra
    // 0x80059724: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80059724: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_80059728(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80059728: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8005972C: lw          $t0, 0x30($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X30);
    // 0x80059730: lbu         $v0, 0x0($t0)
    ctx->r2 = MEM_BU(ctx->r8, 0X0);
    // 0x80059734: beq         $v0, $zero, L_800597C4
    if (ctx->r2 == 0) {
        // 0x80059738: addu        $t1, $zero, $zero
        ctx->r9 = ADD32(0, 0);
            goto L_800597C4;
    }
    // 0x80059738: addu        $t1, $zero, $zero
    ctx->r9 = ADD32(0, 0);
L_8005973C:
    // 0x8005973C: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x80059740: addu        $v0, $t0, $a0
    ctx->r2 = ADD32(ctx->r8, ctx->r4);
L_80059744:
    // 0x80059744: addu        $v1, $a1, $a0
    ctx->r3 = ADD32(ctx->r5, ctx->r4);
    // 0x80059748: lbu         $a3, 0x0($v0)
    ctx->r7 = MEM_BU(ctx->r2, 0X0);
    // 0x8005974C: lbu         $v0, 0x0($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X0);
    // 0x80059750: bne         $a3, $v0, L_800597A0
    if (ctx->r7 != ctx->r2) {
        // 0x80059754: nop
    
            goto L_800597A0;
    }
    // 0x80059754: nop

    // 0x80059758: beq         $a3, $zero, L_80059774
    if (ctx->r7 == 0) {
        // 0x8005975C: addu        $v0, $t0, $a0
        ctx->r2 = ADD32(ctx->r8, ctx->r4);
            goto L_80059774;
    }
    // 0x8005975C: addu        $v0, $t0, $a0
    ctx->r2 = ADD32(ctx->r8, ctx->r4);
    // 0x80059760: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x80059764: slti        $v0, $a0, 0x6
    ctx->r2 = SIGNED(ctx->r4) < 0X6 ? 1 : 0;
    // 0x80059768: bne         $v0, $zero, L_80059744
    if (ctx->r2 != 0) {
        // 0x8005976C: addu        $v0, $t0, $a0
        ctx->r2 = ADD32(ctx->r8, ctx->r4);
            goto L_80059744;
    }
    // 0x8005976C: addu        $v0, $t0, $a0
    ctx->r2 = ADD32(ctx->r8, ctx->r4);
    // 0x80059770: addu        $v1, $a1, $a0
    ctx->r3 = ADD32(ctx->r5, ctx->r4);
L_80059774:
    // 0x80059774: lbu         $a0, 0x0($v0)
    ctx->r4 = MEM_BU(ctx->r2, 0X0);
    // 0x80059778: lbu         $v0, 0x0($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X0);
    // 0x8005977C: bne         $a0, $v0, L_800597A0
    if (ctx->r4 != ctx->r2) {
        // 0x80059780: nop
    
            goto L_800597A0;
    }
    // 0x80059780: nop

    // 0x80059784: bne         $a0, $zero, L_800597A0
    if (ctx->r4 != 0) {
        // 0x80059788: nop
    
            goto L_800597A0;
    }
    // 0x80059788: nop

    // 0x8005978C: bnel        $a2, $zero, L_80059794
    if (ctx->r6 != 0) {
        // 0x80059790: sw          $t1, 0x0($a2)
        MEM_W(0X0, ctx->r6) = ctx->r9;
            goto L_80059794;
    }
    goto skip_0;
    // 0x80059790: sw          $t1, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r9;
    skip_0:
L_80059794:
    // 0x80059794: lbu         $v0, 0x7($t0)
    ctx->r2 = MEM_BU(ctx->r8, 0X7);
    // 0x80059798: jr          $ra
    // 0x8005979C: nop

    return;
    // 0x8005979C: nop

L_800597A0:
    // 0x800597A0: lbu         $v0, 0x7($t0)
    ctx->r2 = MEM_BU(ctx->r8, 0X7);
    // 0x800597A4: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
    // 0x800597A8: sll         $v1, $v0, 3
    ctx->r3 = S32(ctx->r2 << 3);
    // 0x800597AC: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x800597B0: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x800597B4: addu        $v1, $t0, $v1
    ctx->r3 = ADD32(ctx->r8, ctx->r3);
    // 0x800597B8: lbu         $v0, 0x8($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X8);
    // 0x800597BC: bne         $v0, $zero, L_8005973C
    if (ctx->r2 != 0) {
        // 0x800597C0: addiu       $t0, $v1, 0x8
        ctx->r8 = ADD32(ctx->r3, 0X8);
            goto L_8005973C;
    }
    // 0x800597C0: addiu       $t0, $v1, 0x8
    ctx->r8 = ADD32(ctx->r3, 0X8);
L_800597C4:
    // 0x800597C4: jr          $ra
    // 0x800597C8: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    return;
    // 0x800597C8: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
;}
RECOMP_FUNC void func_800597CC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800597CC: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x800597D0: lw          $a3, 0x30($v0)
    ctx->r7 = MEM_W(ctx->r2, 0X30);
    // 0x800597D4: lbu         $v0, 0x0($a3)
    ctx->r2 = MEM_BU(ctx->r7, 0X0);
    // 0x800597D8: beq         $v0, $zero, L_80059860
    if (ctx->r2 == 0) {
        // 0x800597DC: sll         $v0, $a2, 3
        ctx->r2 = S32(ctx->r6 << 3);
            goto L_80059860;
    }
    // 0x800597DC: sll         $v0, $a2, 3
    ctx->r2 = S32(ctx->r6 << 3);
    // 0x800597E0: addu        $v0, $v0, $a2
    ctx->r2 = ADD32(ctx->r2, ctx->r6);
    // 0x800597E4: sll         $t0, $v0, 2
    ctx->r8 = S32(ctx->r2 << 2);
L_800597E8:
    // 0x800597E8: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x800597EC: addu        $v0, $a3, $a0
    ctx->r2 = ADD32(ctx->r7, ctx->r4);
L_800597F0:
    // 0x800597F0: addu        $v1, $a1, $a0
    ctx->r3 = ADD32(ctx->r5, ctx->r4);
    // 0x800597F4: lbu         $a2, 0x0($v0)
    ctx->r6 = MEM_BU(ctx->r2, 0X0);
    // 0x800597F8: lbu         $v0, 0x0($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X0);
    // 0x800597FC: bne         $a2, $v0, L_80059840
    if (ctx->r6 != ctx->r2) {
        // 0x80059800: nop
    
            goto L_80059840;
    }
    // 0x80059800: nop

    // 0x80059804: beq         $a2, $zero, L_80059820
    if (ctx->r6 == 0) {
        // 0x80059808: addu        $v0, $a3, $a0
        ctx->r2 = ADD32(ctx->r7, ctx->r4);
            goto L_80059820;
    }
    // 0x80059808: addu        $v0, $a3, $a0
    ctx->r2 = ADD32(ctx->r7, ctx->r4);
    // 0x8005980C: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x80059810: slti        $v0, $a0, 0x6
    ctx->r2 = SIGNED(ctx->r4) < 0X6 ? 1 : 0;
    // 0x80059814: bne         $v0, $zero, L_800597F0
    if (ctx->r2 != 0) {
        // 0x80059818: addu        $v0, $a3, $a0
        ctx->r2 = ADD32(ctx->r7, ctx->r4);
            goto L_800597F0;
    }
    // 0x80059818: addu        $v0, $a3, $a0
    ctx->r2 = ADD32(ctx->r7, ctx->r4);
    // 0x8005981C: addu        $v1, $a1, $a0
    ctx->r3 = ADD32(ctx->r5, ctx->r4);
L_80059820:
    // 0x80059820: lbu         $a0, 0x0($v0)
    ctx->r4 = MEM_BU(ctx->r2, 0X0);
    // 0x80059824: lbu         $v0, 0x0($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X0);
    // 0x80059828: bne         $a0, $v0, L_80059840
    if (ctx->r4 != ctx->r2) {
        // 0x8005982C: nop
    
            goto L_80059840;
    }
    // 0x8005982C: nop

    // 0x80059830: bne         $a0, $zero, L_80059840
    if (ctx->r4 != 0) {
        // 0x80059834: addu        $v0, $a3, $t0
        ctx->r2 = ADD32(ctx->r7, ctx->r8);
            goto L_80059840;
    }
    // 0x80059834: addu        $v0, $a3, $t0
    ctx->r2 = ADD32(ctx->r7, ctx->r8);
    // 0x80059838: jr          $ra
    // 0x8005983C: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    return;
    // 0x8005983C: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
L_80059840:
    // 0x80059840: lbu         $v0, 0x7($a3)
    ctx->r2 = MEM_BU(ctx->r7, 0X7);
    // 0x80059844: sll         $v1, $v0, 3
    ctx->r3 = S32(ctx->r2 << 3);
    // 0x80059848: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x8005984C: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x80059850: addu        $v1, $a3, $v1
    ctx->r3 = ADD32(ctx->r7, ctx->r3);
    // 0x80059854: lbu         $v0, 0x8($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X8);
    // 0x80059858: bne         $v0, $zero, L_800597E8
    if (ctx->r2 != 0) {
        // 0x8005985C: addiu       $a3, $v1, 0x8
        ctx->r7 = ADD32(ctx->r3, 0X8);
            goto L_800597E8;
    }
    // 0x8005985C: addiu       $a3, $v1, 0x8
    ctx->r7 = ADD32(ctx->r3, 0X8);
L_80059860:
    // 0x80059860: jr          $ra
    // 0x80059864: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    return;
    // 0x80059864: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
;}
RECOMP_FUNC void func_80059868(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80059868: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8005986C: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x80059870: addu        $s1, $a1, $zero
    ctx->r17 = ADD32(ctx->r5, 0);
    // 0x80059874: sw          $ra, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r31;
    // 0x80059878: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x8005987C: sw          $zero, 0x8($s1)
    MEM_W(0X8, ctx->r17) = 0;
    // 0x80059880: sb          $zero, 0x0($s1)
    MEM_B(0X0, ctx->r17) = 0;
    // 0x80059884: sh          $zero, 0x6($s1)
    MEM_H(0X6, ctx->r17) = 0;
    // 0x80059888: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8005988C: lw          $s0, 0x30($v0)
    ctx->r16 = MEM_W(ctx->r2, 0X30);
    // 0x80059890: beq         $s0, $zero, L_800598DC
    if (ctx->r16 == 0) {
        // 0x80059894: addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
            goto L_800598DC;
    }
    // 0x80059894: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // 0x80059898: lbu         $v0, 0x0($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X0);
    // 0x8005989C: beq         $v0, $zero, L_800598D8
    if (ctx->r2 == 0) {
        // 0x800598A0: addu        $a0, $s1, $zero
        ctx->r4 = ADD32(ctx->r17, 0);
            goto L_800598D8;
    }
    // 0x800598A0: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x800598A4: jal         0x8000761C
    // 0x800598A8: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    rs_strcpy(rdram, ctx);
        goto after_0;
    // 0x800598A8: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    after_0:
    // 0x800598AC: lbu         $v0, 0x7($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X7);
    // 0x800598B0: sh          $v0, 0x6($s1)
    MEM_H(0X6, ctx->r17) = ctx->r2;
    // 0x800598B4: lbu         $a0, 0x7($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X7);
    // 0x800598B8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800598BC: sll         $v1, $a0, 3
    ctx->r3 = S32(ctx->r4 << 3);
    // 0x800598C0: addu        $v1, $v1, $a0
    ctx->r3 = ADD32(ctx->r3, ctx->r4);
    // 0x800598C4: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x800598C8: addu        $v1, $s0, $v1
    ctx->r3 = ADD32(ctx->r16, ctx->r3);
    // 0x800598CC: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x800598D0: j           L_800598DC
    // 0x800598D4: sw          $v1, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->r3;
        goto L_800598DC;
    // 0x800598D4: sw          $v1, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->r3;
L_800598D8:
    // 0x800598D8: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_800598DC:
    // 0x800598DC: lw          $ra, 0x18($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X18);
    // 0x800598E0: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x800598E4: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x800598E8: jr          $ra
    // 0x800598EC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x800598EC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_800598F0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800598F0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800598F4: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x800598F8: addu        $s1, $a0, $zero
    ctx->r17 = ADD32(ctx->r4, 0);
    // 0x800598FC: sw          $ra, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r31;
    // 0x80059900: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x80059904: lw          $s0, 0x8($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X8);
    // 0x80059908: beq         $s0, $zero, L_80059950
    if (ctx->r16 == 0) {
        // 0x8005990C: addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
            goto L_80059950;
    }
    // 0x8005990C: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // 0x80059910: lbu         $v0, 0x0($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X0);
    // 0x80059914: beq         $v0, $zero, L_80059950
    if (ctx->r2 == 0) {
        // 0x80059918: addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
            goto L_80059950;
    }
    // 0x80059918: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // 0x8005991C: jal         0x8000761C
    // 0x80059920: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    rs_strcpy(rdram, ctx);
        goto after_0;
    // 0x80059920: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    after_0:
    // 0x80059924: lbu         $v0, 0x7($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X7);
    // 0x80059928: sh          $v0, 0x6($s1)
    MEM_H(0X6, ctx->r17) = ctx->r2;
    // 0x8005992C: lbu         $a0, 0x7($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X7);
    // 0x80059930: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80059934: sll         $v1, $a0, 3
    ctx->r3 = S32(ctx->r4 << 3);
    // 0x80059938: addu        $v1, $v1, $a0
    ctx->r3 = ADD32(ctx->r3, ctx->r4);
    // 0x8005993C: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x80059940: addu        $v1, $s0, $v1
    ctx->r3 = ADD32(ctx->r16, ctx->r3);
    // 0x80059944: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x80059948: j           L_8005995C
    // 0x8005994C: sw          $v1, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->r3;
        goto L_8005995C;
    // 0x8005994C: sw          $v1, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->r3;
L_80059950:
    // 0x80059950: sw          $zero, 0x8($s1)
    MEM_W(0X8, ctx->r17) = 0;
    // 0x80059954: sb          $zero, 0x0($s1)
    MEM_B(0X0, ctx->r17) = 0;
    // 0x80059958: sh          $zero, 0x6($s1)
    MEM_H(0X6, ctx->r17) = 0;
L_8005995C:
    // 0x8005995C: lw          $ra, 0x18($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X18);
    // 0x80059960: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x80059964: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x80059968: jr          $ra
    // 0x8005996C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x8005996C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_80059970(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80059970: addu        $a1, $a0, $zero
    ctx->r5 = ADD32(ctx->r4, 0);
    // 0x80059974: lbu         $v0, 0xB($a1)
    ctx->r2 = MEM_BU(ctx->r5, 0XB);
    // 0x80059978: beq         $v0, $zero, L_800599B8
    if (ctx->r2 == 0) {
        // 0x8005997C: nop
    
            goto L_800599B8;
    }
    // 0x8005997C: nop

    // 0x80059980: lhu         $v0, 0x8($a1)
    ctx->r2 = MEM_HU(ctx->r5, 0X8);
    // 0x80059984: andi        $v0, $v0, 0x20
    ctx->r2 = ctx->r2 & 0X20;
    // 0x80059988: bne         $v0, $zero, L_800599B8
    if (ctx->r2 != 0) {
        // 0x8005998C: lui         $v1, 0x8014
        ctx->r3 = S32(0X8014 << 16);
            goto L_800599B8;
    }
    // 0x8005998C: lui         $v1, 0x8014
    ctx->r3 = S32(0X8014 << 16);
    // 0x80059990: lhu         $v0, -0x5B70($v1)
    ctx->r2 = MEM_HU(ctx->r3, -0X5B70);
    // 0x80059994: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80059998: sh          $v0, -0x5B70($v1)
    MEM_H(-0X5B70, ctx->r3) = ctx->r2;
    // 0x8005999C: lui         $v1, 0x8014
    ctx->r3 = S32(0X8014 << 16);
    // 0x800599A0: addiu       $v1, $v1, -0x5B68
    ctx->r3 = ADD32(ctx->r3, -0X5B68);
    // 0x800599A4: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x800599A8: lbu         $a0, 0xB($a1)
    ctx->r4 = MEM_BU(ctx->r5, 0XB);
    // 0x800599AC: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800599B0: sb          $a0, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r4;
    // 0x800599B4: sb          $zero, 0xB($a1)
    MEM_B(0XB, ctx->r5) = 0;
L_800599B8:
    // 0x800599B8: jr          $ra
    // 0x800599BC: nop

    return;
    // 0x800599BC: nop

;}
RECOMP_FUNC void func_800599C0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800599C0: beq         $a0, $zero, L_800599E4
    if (ctx->r4 == 0) {
        // 0x800599C4: nor         $a2, $zero, $a2
        ctx->r6 = ~(0 | ctx->r6);
            goto L_800599E4;
    }
    // 0x800599C4: nor         $a2, $zero, $a2
    ctx->r6 = ~(0 | ctx->r6);
L_800599C8:
    // 0x800599C8: lw          $v0, 0xC($a0)
    ctx->r2 = MEM_W(ctx->r4, 0XC);
    // 0x800599CC: and         $v0, $v0, $a2
    ctx->r2 = ctx->r2 & ctx->r6;
    // 0x800599D0: or          $v0, $v0, $a1
    ctx->r2 = ctx->r2 | ctx->r5;
    // 0x800599D4: sw          $v0, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r2;
    // 0x800599D8: lw          $a0, 0x0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X0);
    // 0x800599DC: bne         $a0, $zero, L_800599C8
    if (ctx->r4 != 0) {
        // 0x800599E0: nop
    
            goto L_800599C8;
    }
    // 0x800599E0: nop

L_800599E4:
    // 0x800599E4: jr          $ra
    // 0x800599E8: nop

    return;
    // 0x800599E8: nop

;}
RECOMP_FUNC void func_800599EC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800599EC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800599F0: sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // 0x800599F4: addu        $s2, $a1, $zero
    ctx->r18 = ADD32(ctx->r5, 0);
    // 0x800599F8: sw          $s3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r19;
    // 0x800599FC: addu        $s3, $a2, $zero
    ctx->r19 = ADD32(ctx->r6, 0);
    // 0x80059A00: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x80059A04: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x80059A08: sw          $ra, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r31;
    // 0x80059A0C: beq         $s0, $zero, L_80059A64
    if (ctx->r16 == 0) {
        // 0x80059A10: sw          $s1, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r17;
            goto L_80059A64;
    }
    // 0x80059A10: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x80059A14: nor         $s1, $zero, $s3
    ctx->r17 = ~(0 | ctx->r19);
L_80059A18:
    // 0x80059A18: lw          $v0, 0x10($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X10);
    // 0x80059A1C: beq         $v0, $zero, L_80059A44
    if (ctx->r2 == 0) {
        // 0x80059A20: nop
    
            goto L_80059A44;
    }
    // 0x80059A20: nop

    // 0x80059A24: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
L_80059A28:
    // 0x80059A28: lw          $v0, 0xC($v1)
    ctx->r2 = MEM_W(ctx->r3, 0XC);
    // 0x80059A2C: and         $v0, $v0, $s1
    ctx->r2 = ctx->r2 & ctx->r17;
    // 0x80059A30: or          $v0, $v0, $s2
    ctx->r2 = ctx->r2 | ctx->r18;
    // 0x80059A34: sw          $v0, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r2;
    // 0x80059A38: lw          $v1, 0x0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X0);
    // 0x80059A3C: bne         $v1, $zero, L_80059A28
    if (ctx->r3 != 0) {
        // 0x80059A40: nop
    
            goto L_80059A28;
    }
    // 0x80059A40: nop

L_80059A44:
    // 0x80059A44: lw          $a0, 0xC($s0)
    ctx->r4 = MEM_W(ctx->r16, 0XC);
    // 0x80059A48: beq         $a0, $zero, L_80059A58
    if (ctx->r4 == 0) {
        // 0x80059A4C: addu        $a1, $s2, $zero
        ctx->r5 = ADD32(ctx->r18, 0);
            goto L_80059A58;
    }
    // 0x80059A4C: addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    // 0x80059A50: jal         0x800599EC
    // 0x80059A54: addu        $a2, $s3, $zero
    ctx->r6 = ADD32(ctx->r19, 0);
    func_800599EC(rdram, ctx);
        goto after_0;
    // 0x80059A54: addu        $a2, $s3, $zero
    ctx->r6 = ADD32(ctx->r19, 0);
    after_0:
L_80059A58:
    // 0x80059A58: lw          $s0, 0x0($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X0);
    // 0x80059A5C: bne         $s0, $zero, L_80059A18
    if (ctx->r16 != 0) {
        // 0x80059A60: nop
    
            goto L_80059A18;
    }
    // 0x80059A60: nop

L_80059A64:
    // 0x80059A64: lw          $ra, 0x20($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X20);
    // 0x80059A68: lw          $s3, 0x1C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X1C);
    // 0x80059A6C: lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X18);
    // 0x80059A70: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x80059A74: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x80059A78: jr          $ra
    // 0x80059A7C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80059A7C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_80059A80(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80059A80: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80059A84: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x80059A88: addu        $s1, $a0, $zero
    ctx->r17 = ADD32(ctx->r4, 0);
    // 0x80059A8C: sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // 0x80059A90: addu        $s2, $a1, $zero
    ctx->r18 = ADD32(ctx->r5, 0);
    // 0x80059A94: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80059A98: beq         $s1, $zero, L_80059B34
    if (ctx->r17 == 0) {
        // 0x80059A9C: sw          $s0, 0x10($sp)
        MEM_W(0X10, ctx->r29) = ctx->r16;
            goto L_80059B34;
    }
    // 0x80059A9C: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
L_80059AA0:
    // 0x80059AA0: lw          $a0, 0x10($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X10);
    // 0x80059AA4: beq         $a0, $zero, L_80059B14
    if (ctx->r4 == 0) {
        // 0x80059AA8: nop
    
            goto L_80059B14;
    }
    // 0x80059AA8: nop

    // 0x80059AAC: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
L_80059AB0:
    // 0x80059AB0: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x80059AB4: beq         $v0, $zero, L_80059AF8
    if (ctx->r2 == 0) {
        // 0x80059AB8: addu        $a0, $zero, $zero
        ctx->r4 = ADD32(0, 0);
            goto L_80059AF8;
    }
    // 0x80059AB8: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x80059ABC: addu        $v1, $s2, $zero
    ctx->r3 = ADD32(ctx->r18, 0);
    // 0x80059AC0: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
L_80059AC4:
    // 0x80059AC4: beq         $s0, $v0, L_80059AE0
    if (ctx->r16 == ctx->r2) {
        // 0x80059AC8: sll         $v0, $a0, 1
        ctx->r2 = S32(ctx->r4 << 1);
            goto L_80059AE0;
    }
    // 0x80059AC8: sll         $v0, $a0, 1
    ctx->r2 = S32(ctx->r4 << 1);
    // 0x80059ACC: addiu       $v1, $v1, 0xC
    ctx->r3 = ADD32(ctx->r3, 0XC);
    // 0x80059AD0: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80059AD4: bne         $v0, $zero, L_80059AC4
    if (ctx->r2 != 0) {
        // 0x80059AD8: addiu       $a0, $a0, 0x1
        ctx->r4 = ADD32(ctx->r4, 0X1);
            goto L_80059AC4;
    }
    // 0x80059AD8: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x80059ADC: sll         $v0, $a0, 1
    ctx->r2 = S32(ctx->r4 << 1);
L_80059AE0:
    // 0x80059AE0: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x80059AE4: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80059AE8: addu        $v0, $v0, $s2
    ctx->r2 = ADD32(ctx->r2, ctx->r18);
    // 0x80059AEC: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x80059AF0: bne         $v0, $zero, L_80059B08
    if (ctx->r2 != 0) {
        // 0x80059AF4: nop
    
            goto L_80059B08;
    }
    // 0x80059AF4: nop

L_80059AF8:
    // 0x80059AF8: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x80059AFC: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x80059B00: jal         0x80014DE0
    // 0x80059B04: addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    func_80014DE0(rdram, ctx);
        goto after_0;
    // 0x80059B04: addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    after_0:
L_80059B08:
    // 0x80059B08: lw          $s0, 0x0($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X0);
    // 0x80059B0C: bne         $s0, $zero, L_80059AB0
    if (ctx->r16 != 0) {
        // 0x80059B10: nop
    
            goto L_80059AB0;
    }
    // 0x80059B10: nop

L_80059B14:
    // 0x80059B14: lw          $a0, 0xC($s1)
    ctx->r4 = MEM_W(ctx->r17, 0XC);
    // 0x80059B18: beq         $a0, $zero, L_80059B28
    if (ctx->r4 == 0) {
        // 0x80059B1C: nop
    
            goto L_80059B28;
    }
    // 0x80059B1C: nop

    // 0x80059B20: jal         0x80059A80
    // 0x80059B24: addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    func_80059A80(rdram, ctx);
        goto after_1;
    // 0x80059B24: addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    after_1:
L_80059B28:
    // 0x80059B28: lw          $s1, 0x0($s1)
    ctx->r17 = MEM_W(ctx->r17, 0X0);
    // 0x80059B2C: bne         $s1, $zero, L_80059AA0
    if (ctx->r17 != 0) {
        // 0x80059B30: nop
    
            goto L_80059AA0;
    }
    // 0x80059B30: nop

L_80059B34:
    // 0x80059B34: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80059B38: lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X18);
    // 0x80059B3C: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x80059B40: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x80059B44: jr          $ra
    // 0x80059B48: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80059B48: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void fake_func_80059B4C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
;}
RECOMP_FUNC void func_80059B50(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80059B50: lwc1        $f0, 0x1C($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0X1C);
    // 0x80059B54: lwc1        $f2, 0x14($a1)
    ctx->f2.u32l = MEM_W(ctx->r5, 0X14);
    // 0x80059B58: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x80059B5C: lwc1        $f4, 0x10($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X10);
    // 0x80059B60: lwc1        $f2, 0x20($a1)
    ctx->f2.u32l = MEM_W(ctx->r5, 0X20);
    // 0x80059B64: mul.s       $f2, $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f4.fl);
    // 0x80059B68: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x80059B6C: mtc1        $a2, $f6
    ctx->f6.u32l = ctx->r6;
    // 0x80059B70: mul.s       $f0, $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x80059B74: swc1        $f0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f0.u32l;
    // 0x80059B78: lwc1        $f0, 0x20($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0X20);
    // 0x80059B7C: lwc1        $f2, 0xC($a1)
    ctx->f2.u32l = MEM_W(ctx->r5, 0XC);
    // 0x80059B80: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x80059B84: lwc1        $f4, 0x14($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X14);
    // 0x80059B88: lwc1        $f2, 0x18($a1)
    ctx->f2.u32l = MEM_W(ctx->r5, 0X18);
    // 0x80059B8C: mul.s       $f2, $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f4.fl);
    // 0x80059B90: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x80059B94: mul.s       $f0, $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x80059B98: swc1        $f0, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->f0.u32l;
    // 0x80059B9C: lwc1        $f0, 0x18($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0X18);
    // 0x80059BA0: lwc1        $f2, 0x10($a1)
    ctx->f2.u32l = MEM_W(ctx->r5, 0X10);
    // 0x80059BA4: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x80059BA8: lwc1        $f4, 0xC($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0XC);
    // 0x80059BAC: lwc1        $f2, 0x1C($a1)
    ctx->f2.u32l = MEM_W(ctx->r5, 0X1C);
    // 0x80059BB0: mul.s       $f2, $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f4.fl);
    // 0x80059BB4: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x80059BB8: mul.s       $f0, $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x80059BBC: swc1        $f0, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->f0.u32l;
    // 0x80059BC0: lwc1        $f0, 0x18($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0X18);
    // 0x80059BC4: mul.s       $f0, $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x80059BC8: swc1        $f0, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f0.u32l;
    // 0x80059BCC: lwc1        $f0, 0x1C($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0X1C);
    // 0x80059BD0: mul.s       $f0, $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x80059BD4: swc1        $f0, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->f0.u32l;
    // 0x80059BD8: lwc1        $f0, 0x20($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0X20);
    // 0x80059BDC: mul.s       $f0, $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x80059BE0: swc1        $f0, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = ctx->f0.u32l;
    // 0x80059BE4: lwc1        $f0, 0xC($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0XC);
    // 0x80059BE8: mul.s       $f0, $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x80059BEC: swc1        $f0, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f0.u32l;
    // 0x80059BF0: lwc1        $f0, 0x10($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0X10);
    // 0x80059BF4: mul.s       $f0, $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x80059BF8: swc1        $f0, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->f0.u32l;
    // 0x80059BFC: lwc1        $f0, 0x14($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0X14);
    // 0x80059C00: mul.s       $f0, $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x80059C04: swc1        $f0, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->f0.u32l;
    // 0x80059C08: lwc1        $f0, 0x0($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0X0);
    // 0x80059C0C: swc1        $f0, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->f0.u32l;
    // 0x80059C10: lwc1        $f0, 0x4($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0X4);
    // 0x80059C14: swc1        $f0, 0x28($a0)
    MEM_W(0X28, ctx->r4) = ctx->f0.u32l;
    // 0x80059C18: lwc1        $f0, 0x8($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0X8);
    // 0x80059C1C: jr          $ra
    // 0x80059C20: swc1        $f0, 0x2C($a0)
    MEM_W(0X2C, ctx->r4) = ctx->f0.u32l;
    return;
    // 0x80059C20: swc1        $f0, 0x2C($a0)
    MEM_W(0X2C, ctx->r4) = ctx->f0.u32l;
;}
RECOMP_FUNC void func_80059C24(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80059C24: lwc1        $f0, 0x1C($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0X1C);
    // 0x80059C28: lwc1        $f2, 0x14($a1)
    ctx->f2.u32l = MEM_W(ctx->r5, 0X14);
    // 0x80059C2C: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x80059C30: lwc1        $f4, 0x10($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X10);
    // 0x80059C34: lwc1        $f2, 0x20($a1)
    ctx->f2.u32l = MEM_W(ctx->r5, 0X20);
    // 0x80059C38: mul.s       $f2, $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f4.fl);
    // 0x80059C3C: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x80059C40: lwc1        $f2, 0x0($a2)
    ctx->f2.u32l = MEM_W(ctx->r6, 0X0);
    // 0x80059C44: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x80059C48: swc1        $f0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f0.u32l;
    // 0x80059C4C: lwc1        $f0, 0x20($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0X20);
    // 0x80059C50: lwc1        $f2, 0xC($a1)
    ctx->f2.u32l = MEM_W(ctx->r5, 0XC);
    // 0x80059C54: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x80059C58: lwc1        $f4, 0x14($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X14);
    // 0x80059C5C: lwc1        $f2, 0x18($a1)
    ctx->f2.u32l = MEM_W(ctx->r5, 0X18);
    // 0x80059C60: mul.s       $f2, $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f4.fl);
    // 0x80059C64: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x80059C68: lwc1        $f2, 0x0($a2)
    ctx->f2.u32l = MEM_W(ctx->r6, 0X0);
    // 0x80059C6C: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x80059C70: swc1        $f0, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->f0.u32l;
    // 0x80059C74: lwc1        $f0, 0x18($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0X18);
    // 0x80059C78: lwc1        $f2, 0x10($a1)
    ctx->f2.u32l = MEM_W(ctx->r5, 0X10);
    // 0x80059C7C: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x80059C80: lwc1        $f4, 0xC($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0XC);
    // 0x80059C84: lwc1        $f2, 0x1C($a1)
    ctx->f2.u32l = MEM_W(ctx->r5, 0X1C);
    // 0x80059C88: mul.s       $f2, $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f4.fl);
    // 0x80059C8C: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x80059C90: lwc1        $f2, 0x0($a2)
    ctx->f2.u32l = MEM_W(ctx->r6, 0X0);
    // 0x80059C94: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x80059C98: swc1        $f0, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->f0.u32l;
    // 0x80059C9C: lwc1        $f0, 0x18($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0X18);
    // 0x80059CA0: lwc1        $f2, 0x4($a2)
    ctx->f2.u32l = MEM_W(ctx->r6, 0X4);
    // 0x80059CA4: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x80059CA8: swc1        $f0, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f0.u32l;
    // 0x80059CAC: lwc1        $f0, 0x1C($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0X1C);
    // 0x80059CB0: lwc1        $f2, 0x4($a2)
    ctx->f2.u32l = MEM_W(ctx->r6, 0X4);
    // 0x80059CB4: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x80059CB8: swc1        $f0, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->f0.u32l;
    // 0x80059CBC: lwc1        $f0, 0x20($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0X20);
    // 0x80059CC0: lwc1        $f2, 0x4($a2)
    ctx->f2.u32l = MEM_W(ctx->r6, 0X4);
    // 0x80059CC4: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x80059CC8: swc1        $f0, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = ctx->f0.u32l;
    // 0x80059CCC: lwc1        $f0, 0xC($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0XC);
    // 0x80059CD0: lwc1        $f2, 0x8($a2)
    ctx->f2.u32l = MEM_W(ctx->r6, 0X8);
    // 0x80059CD4: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x80059CD8: swc1        $f0, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f0.u32l;
    // 0x80059CDC: lwc1        $f0, 0x10($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0X10);
    // 0x80059CE0: lwc1        $f2, 0x8($a2)
    ctx->f2.u32l = MEM_W(ctx->r6, 0X8);
    // 0x80059CE4: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x80059CE8: swc1        $f0, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->f0.u32l;
    // 0x80059CEC: lwc1        $f0, 0x14($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0X14);
    // 0x80059CF0: lwc1        $f2, 0x8($a2)
    ctx->f2.u32l = MEM_W(ctx->r6, 0X8);
    // 0x80059CF4: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x80059CF8: swc1        $f0, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->f0.u32l;
    // 0x80059CFC: lwc1        $f0, 0x0($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0X0);
    // 0x80059D00: swc1        $f0, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->f0.u32l;
    // 0x80059D04: lwc1        $f0, 0x4($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0X4);
    // 0x80059D08: swc1        $f0, 0x28($a0)
    MEM_W(0X28, ctx->r4) = ctx->f0.u32l;
    // 0x80059D0C: lwc1        $f0, 0x8($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0X8);
    // 0x80059D10: jr          $ra
    // 0x80059D14: swc1        $f0, 0x2C($a0)
    MEM_W(0X2C, ctx->r4) = ctx->f0.u32l;
    return;
    // 0x80059D14: swc1        $f0, 0x2C($a0)
    MEM_W(0X2C, ctx->r4) = ctx->f0.u32l;
;}
RECOMP_FUNC void func_80059D18(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80059D18: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80059D1C: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x80059D20: lwc1        $f0, 0x24($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0X24);
    // 0x80059D24: swc1        $f0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f0.u32l;
    // 0x80059D28: lwc1        $f0, 0x28($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0X28);
    // 0x80059D2C: swc1        $f0, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f0.u32l;
    // 0x80059D30: lwc1        $f0, 0x2C($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0X2C);
    // 0x80059D34: swc1        $f0, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f0.u32l;
    // 0x80059D38: lwc1        $f0, 0x8($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0X8);
    // 0x80059D3C: swc1        $f0, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->f0.u32l;
    // 0x80059D40: lwc1        $f0, 0x14($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0X14);
    // 0x80059D44: swc1        $f0, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->f0.u32l;
    // 0x80059D48: lwc1        $f0, 0x20($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0X20);
    // 0x80059D4C: swc1        $f0, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->f0.u32l;
    // 0x80059D50: lwc1        $f0, 0x4($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0X4);
    // 0x80059D54: swc1        $f0, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->f0.u32l;
    // 0x80059D58: lwc1        $f0, 0x10($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0X10);
    // 0x80059D5C: swc1        $f0, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = ctx->f0.u32l;
    // 0x80059D60: lwc1        $f0, 0x1C($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0X1C);
    // 0x80059D64: jal         0x80059F10
    // 0x80059D68: swc1        $f0, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->f0.u32l;
    func_80059F10(rdram, ctx);
        goto after_0;
    // 0x80059D68: swc1        $f0, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->f0.u32l;
    after_0:
    // 0x80059D6C: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x80059D70: jr          $ra
    // 0x80059D74: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80059D74: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_80059D78(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80059D78: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x80059D7C: sdc1        $f20, 0x48($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X48, ctx->r29);
    // 0x80059D80: mtc1        $a2, $f20
    ctx->f20.u32l = ctx->r6;
    // 0x80059D84: sw          $s0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r16;
    // 0x80059D88: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x80059D8C: sdc1        $f22, 0x50($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X50, ctx->r29);
    // 0x80059D90: mtc1        $a3, $f22
    ctx->f22.u32l = ctx->r7;
    // 0x80059D94: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x80059D98: jal         0x8001CC3C
    // 0x80059D9C: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    func_8001CC3C(rdram, ctx);
        goto after_0;
    // 0x80059D9C: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    after_0:
    // 0x80059DA0: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80059DA4: jal         0x8001CCCC
    // 0x80059DA8: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    func_8001CCCC(rdram, ctx);
        goto after_1;
    // 0x80059DA8: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    after_1:
    // 0x80059DAC: mfc1        $a1, $f22
    ctx->r5 = (int32_t)ctx->f22.u32l;
    // 0x80059DB0: jal         0x8001CDFC
    // 0x80059DB4: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    func_8001CDFC(rdram, ctx);
        goto after_2;
    // 0x80059DB4: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    after_2:
    // 0x80059DB8: lwc1        $f0, 0x18($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X18);
    // 0x80059DBC: swc1        $f0, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f0.u32l;
    // 0x80059DC0: lwc1        $f0, 0x24($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X24);
    // 0x80059DC4: swc1        $f0, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f0.u32l;
    // 0x80059DC8: lwc1        $f0, 0x30($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X30);
    // 0x80059DCC: swc1        $f0, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f0.u32l;
    // 0x80059DD0: lwc1        $f0, 0x14($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X14);
    // 0x80059DD4: swc1        $f0, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f0.u32l;
    // 0x80059DD8: lwc1        $f0, 0x20($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X20);
    // 0x80059DDC: swc1        $f0, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f0.u32l;
    // 0x80059DE0: lwc1        $f0, 0x2C($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80059DE4: swc1        $f0, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->f0.u32l;
    // 0x80059DE8: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x80059DEC: lw          $s0, 0x40($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X40);
    // 0x80059DF0: ldc1        $f22, 0x50($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X50);
    // 0x80059DF4: ldc1        $f20, 0x48($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X48);
    // 0x80059DF8: jr          $ra
    // 0x80059DFC: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    return;
    // 0x80059DFC: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
;}
RECOMP_FUNC void func_80059E00(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80059E00: addiu       $sp, $sp, -0x78
    ctx->r29 = ADD32(ctx->r29, -0X78);
    // 0x80059E04: sw          $s0, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r16;
    // 0x80059E08: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x80059E0C: sw          $s2, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r18;
    // 0x80059E10: sw          $ra, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r31;
    // 0x80059E14: sw          $s1, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r17;
    // 0x80059E18: sdc1        $f20, 0x70($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X70, ctx->r29);
    // 0x80059E1C: lwc1        $f12, 0xC($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0XC);
    // 0x80059E20: lwc1        $f14, 0x14($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X14);
    // 0x80059E24: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80059E28: lwc1        $f20, -0x5250($at)
    ctx->f20.u32l = MEM_W(ctx->r1, -0X5250);
    // 0x80059E2C: jal         0x8001C5F4
    // 0x80059E30: addu        $s2, $a1, $zero
    ctx->r18 = ADD32(ctx->r5, 0);
    func_8001C5F4(rdram, ctx);
        goto after_0;
    // 0x80059E30: addu        $s2, $a1, $zero
    ctx->r18 = ADD32(ctx->r5, 0);
    after_0:
    // 0x80059E34: mul.s       $f0, $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f20.fl);
    // 0x80059E38: addiu       $s1, $sp, 0x30
    ctx->r17 = ADD32(ctx->r29, 0X30);
    // 0x80059E3C: swc1        $f0, 0x4($s2)
    MEM_W(0X4, ctx->r18) = ctx->f0.u32l;
    // 0x80059E40: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
    // 0x80059E44: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80059E48: jal         0x8001CD6C
    // 0x80059E4C: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    func_8001CD6C(rdram, ctx);
        goto after_1;
    // 0x80059E4C: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    after_1:
    // 0x80059E50: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x80059E54: addiu       $a1, $s0, 0xC
    ctx->r5 = ADD32(ctx->r16, 0XC);
    // 0x80059E58: jal         0x800193E8
    // 0x80059E5C: addiu       $a2, $sp, 0x10
    ctx->r6 = ADD32(ctx->r29, 0X10);
    func_800193E8(rdram, ctx);
        goto after_2;
    // 0x80059E5C: addiu       $a2, $sp, 0x10
    ctx->r6 = ADD32(ctx->r29, 0X10);
    after_2:
    // 0x80059E60: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x80059E64: addiu       $a1, $s0, 0x18
    ctx->r5 = ADD32(ctx->r16, 0X18);
    // 0x80059E68: addiu       $s0, $sp, 0x20
    ctx->r16 = ADD32(ctx->r29, 0X20);
    // 0x80059E6C: jal         0x800193E8
    // 0x80059E70: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    func_800193E8(rdram, ctx);
        goto after_3;
    // 0x80059E70: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    after_3:
    // 0x80059E74: lwc1        $f12, 0x14($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X14);
    // 0x80059E78: lwc1        $f14, 0x18($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X18);
    // 0x80059E7C: jal         0x8001C5F4
    // 0x80059E80: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    func_8001C5F4(rdram, ctx);
        goto after_4;
    // 0x80059E80: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_4:
    // 0x80059E84: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
    // 0x80059E88: mul.s       $f0, $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f20.fl);
    // 0x80059E8C: swc1        $f0, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->f0.u32l;
    // 0x80059E90: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
    // 0x80059E94: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80059E98: jal         0x8001CC3C
    // 0x80059E9C: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    func_8001CC3C(rdram, ctx);
        goto after_5;
    // 0x80059E9C: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    after_5:
    // 0x80059EA0: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x80059EA4: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x80059EA8: jal         0x800193E8
    // 0x80059EAC: addiu       $a2, $sp, 0x10
    ctx->r6 = ADD32(ctx->r29, 0X10);
    func_800193E8(rdram, ctx);
        goto after_6;
    // 0x80059EAC: addiu       $a2, $sp, 0x10
    ctx->r6 = ADD32(ctx->r29, 0X10);
    after_6:
    // 0x80059EB0: lwc1        $f0, 0x14($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X14);
    // 0x80059EB4: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x80059EB8: c.le.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl <= ctx->f0.fl;
    // 0x80059EBC: nop

    // 0x80059EC0: bc1f        L_80059ED0
    if (!c1cs) {
        // 0x80059EC4: nop
    
            goto L_80059ED0;
    }
    // 0x80059EC4: nop

    // 0x80059EC8: j           L_80059EF4
    // 0x80059ECC: swc1        $f2, 0x8($s2)
    MEM_W(0X8, ctx->r18) = ctx->f2.u32l;
        goto L_80059EF4;
    // 0x80059ECC: swc1        $f2, 0x8($s2)
    MEM_W(0X8, ctx->r18) = ctx->f2.u32l;
L_80059ED0:
    // 0x80059ED0: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80059ED4: lwc1        $f0, -0x524C($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X524C);
    // 0x80059ED8: lwc1        $f2, 0x4($s2)
    ctx->f2.u32l = MEM_W(ctx->r18, 0X4);
    // 0x80059EDC: swc1        $f0, 0x8($s2)
    MEM_W(0X8, ctx->r18) = ctx->f0.u32l;
    // 0x80059EE0: lwc1        $f0, 0x0($s2)
    ctx->f0.u32l = MEM_W(ctx->r18, 0X0);
    // 0x80059EE4: neg.s       $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = -ctx->f2.fl;
    // 0x80059EE8: swc1        $f2, 0x4($s2)
    MEM_W(0X4, ctx->r18) = ctx->f2.u32l;
    // 0x80059EEC: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
    // 0x80059EF0: swc1        $f0, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->f0.u32l;
L_80059EF4:
    // 0x80059EF4: lw          $ra, 0x6C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X6C);
    // 0x80059EF8: lw          $s2, 0x68($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X68);
    // 0x80059EFC: lw          $s1, 0x64($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X64);
    // 0x80059F00: lw          $s0, 0x60($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X60);
    // 0x80059F04: ldc1        $f20, 0x70($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X70);
    // 0x80059F08: jr          $ra
    // 0x80059F0C: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
    return;
    // 0x80059F0C: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
;}
RECOMP_FUNC void func_80059F10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80059F10: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80059F14: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80059F18: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x80059F1C: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x80059F20: addiu       $s1, $s0, 0xC
    ctx->r17 = ADD32(ctx->r16, 0XC);
    // 0x80059F24: sw          $ra, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r31;
    // 0x80059F28: jal         0x8001CF58
    // 0x80059F2C: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    normalize_vector(rdram, ctx);
        goto after_0;
    // 0x80059F2C: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    after_0:
    // 0x80059F30: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    // 0x80059F34: addiu       $s0, $s0, 0x18
    ctx->r16 = ADD32(ctx->r16, 0X18);
    // 0x80059F38: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x80059F3C: jal         0x80019548
    // 0x80059F40: addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    func_80019548(rdram, ctx);
        goto after_1;
    // 0x80059F40: addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    after_1:
    // 0x80059F44: jal         0x8001CF58
    // 0x80059F48: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    normalize_vector(rdram, ctx);
        goto after_2;
    // 0x80059F48: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    after_2:
    // 0x80059F4C: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x80059F50: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    // 0x80059F54: jal         0x80019548
    // 0x80059F58: addiu       $a2, $sp, 0x10
    ctx->r6 = ADD32(ctx->r29, 0X10);
    func_80019548(rdram, ctx);
        goto after_3;
    // 0x80059F58: addiu       $a2, $sp, 0x10
    ctx->r6 = ADD32(ctx->r29, 0X10);
    after_3:
    // 0x80059F5C: lw          $ra, 0x28($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X28);
    // 0x80059F60: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x80059F64: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80059F68: jr          $ra
    // 0x80059F6C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x80059F6C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_80059F70(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80059F70: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80059F74: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x80059F78: addu        $s2, $a0, $zero
    ctx->r18 = ADD32(ctx->r4, 0);
    // 0x80059F7C: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80059F80: addiu       $s0, $s2, 0xC
    ctx->r16 = ADD32(ctx->r18, 0XC);
    // 0x80059F84: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x80059F88: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80059F8C: jal         0x8001CF58
    // 0x80059F90: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    normalize_vector(rdram, ctx);
        goto after_0;
    // 0x80059F90: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    after_0:
    // 0x80059F94: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    // 0x80059F98: addiu       $s1, $s2, 0x18
    ctx->r17 = ADD32(ctx->r18, 0X18);
    // 0x80059F9C: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    // 0x80059FA0: jal         0x80019548
    // 0x80059FA4: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    func_80019548(rdram, ctx);
        goto after_1;
    // 0x80059FA4: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    after_1:
    // 0x80059FA8: jal         0x8001CF58
    // 0x80059FAC: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    normalize_vector(rdram, ctx);
        goto after_2;
    // 0x80059FAC: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    after_2:
    // 0x80059FB0: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x80059FB4: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x80059FB8: jal         0x80019548
    // 0x80059FBC: addiu       $a2, $sp, 0x10
    ctx->r6 = ADD32(ctx->r29, 0X10);
    func_80019548(rdram, ctx);
        goto after_3;
    // 0x80059FBC: addiu       $a2, $sp, 0x10
    ctx->r6 = ADD32(ctx->r29, 0X10);
    after_3:
    // 0x80059FC0: lwc1        $f4, 0xC($s2)
    ctx->f4.u32l = MEM_W(ctx->r18, 0XC);
    // 0x80059FC4: abs.s       $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = fabsf(ctx->f4.fl);
    // 0x80059FC8: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80059FCC: lwc1        $f2, -0x5248($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X5248);
    // 0x80059FD0: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x80059FD4: nop

    // 0x80059FD8: bc1tl       L_80059FE0
    if (c1cs) {
        // 0x80059FDC: sw          $zero, 0xC($s2)
        MEM_W(0XC, ctx->r18) = 0;
            goto L_80059FE0;
    }
    goto skip_0;
    // 0x80059FDC: sw          $zero, 0xC($s2)
    MEM_W(0XC, ctx->r18) = 0;
    skip_0:
L_80059FE0:
    // 0x80059FE0: lwc1        $f4, 0x10($s2)
    ctx->f4.u32l = MEM_W(ctx->r18, 0X10);
    // 0x80059FE4: abs.s       $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = fabsf(ctx->f4.fl);
    // 0x80059FE8: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x80059FEC: nop

    // 0x80059FF0: bc1tl       L_80059FF8
    if (c1cs) {
        // 0x80059FF4: sw          $zero, 0x10($s2)
        MEM_W(0X10, ctx->r18) = 0;
            goto L_80059FF8;
    }
    goto skip_1;
    // 0x80059FF4: sw          $zero, 0x10($s2)
    MEM_W(0X10, ctx->r18) = 0;
    skip_1:
L_80059FF8:
    // 0x80059FF8: lwc1        $f4, 0x14($s2)
    ctx->f4.u32l = MEM_W(ctx->r18, 0X14);
    // 0x80059FFC: abs.s       $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = fabsf(ctx->f4.fl);
    // 0x8005A000: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x8005A004: nop

    // 0x8005A008: bc1tl       L_8005A010
    if (c1cs) {
        // 0x8005A00C: sw          $zero, 0x14($s2)
        MEM_W(0X14, ctx->r18) = 0;
            goto L_8005A010;
    }
    goto skip_2;
    // 0x8005A00C: sw          $zero, 0x14($s2)
    MEM_W(0X14, ctx->r18) = 0;
    skip_2:
L_8005A010:
    // 0x8005A010: lwc1        $f4, 0x18($s2)
    ctx->f4.u32l = MEM_W(ctx->r18, 0X18);
    // 0x8005A014: abs.s       $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = fabsf(ctx->f4.fl);
    // 0x8005A018: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x8005A01C: nop

    // 0x8005A020: bc1tl       L_8005A028
    if (c1cs) {
        // 0x8005A024: sw          $zero, 0x18($s2)
        MEM_W(0X18, ctx->r18) = 0;
            goto L_8005A028;
    }
    goto skip_3;
    // 0x8005A024: sw          $zero, 0x18($s2)
    MEM_W(0X18, ctx->r18) = 0;
    skip_3:
L_8005A028:
    // 0x8005A028: lwc1        $f4, 0x1C($s2)
    ctx->f4.u32l = MEM_W(ctx->r18, 0X1C);
    // 0x8005A02C: abs.s       $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = fabsf(ctx->f4.fl);
    // 0x8005A030: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x8005A034: nop

    // 0x8005A038: bc1tl       L_8005A040
    if (c1cs) {
        // 0x8005A03C: sw          $zero, 0x1C($s2)
        MEM_W(0X1C, ctx->r18) = 0;
            goto L_8005A040;
    }
    goto skip_4;
    // 0x8005A03C: sw          $zero, 0x1C($s2)
    MEM_W(0X1C, ctx->r18) = 0;
    skip_4:
L_8005A040:
    // 0x8005A040: lwc1        $f4, 0x20($s2)
    ctx->f4.u32l = MEM_W(ctx->r18, 0X20);
    // 0x8005A044: abs.s       $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = fabsf(ctx->f4.fl);
    // 0x8005A048: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x8005A04C: nop

    // 0x8005A050: bc1tl       L_8005A058
    if (c1cs) {
        // 0x8005A054: sw          $zero, 0x20($s2)
        MEM_W(0X20, ctx->r18) = 0;
            goto L_8005A058;
    }
    goto skip_5;
    // 0x8005A054: sw          $zero, 0x20($s2)
    MEM_W(0X20, ctx->r18) = 0;
    skip_5:
L_8005A058:
    // 0x8005A058: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x8005A05C: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x8005A060: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x8005A064: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8005A068: jr          $ra
    // 0x8005A06C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x8005A06C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_8005A070(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005A070: lwc1        $f4, 0x0($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X0);
    // 0x8005A074: lwc1        $f2, 0x10($a1)
    ctx->f2.u32l = MEM_W(ctx->r5, 0X10);
    // 0x8005A078: c.lt.s      $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f4.fl < ctx->f2.fl;
    // 0x8005A07C: nop

    // 0x8005A080: bc1f        L_8005A090
    if (!c1cs) {
        // 0x8005A084: nop
    
            goto L_8005A090;
    }
    // 0x8005A084: nop

L_8005A088:
    // 0x8005A088: jr          $ra
    // 0x8005A08C: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    return;
    // 0x8005A08C: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_8005A090:
    // 0x8005A090: lwc1        $f0, 0x28($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0X28);
    // 0x8005A094: add.s       $f0, $f2, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x8005A098: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x8005A09C: nop

    // 0x8005A0A0: bc1t        L_8005A088
    if (c1cs) {
        // 0x8005A0A4: nop
    
            goto L_8005A088;
    }
    // 0x8005A0A4: nop

    // 0x8005A0A8: lwc1        $f4, 0x8($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X8);
    // 0x8005A0AC: lwc1        $f2, 0x18($a1)
    ctx->f2.u32l = MEM_W(ctx->r5, 0X18);
    // 0x8005A0B0: c.lt.s      $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f4.fl < ctx->f2.fl;
    // 0x8005A0B4: nop

    // 0x8005A0B8: bc1t        L_8005A088
    if (c1cs) {
        // 0x8005A0BC: nop
    
            goto L_8005A088;
    }
    // 0x8005A0BC: nop

    // 0x8005A0C0: lwc1        $f0, 0x30($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0X30);
    // 0x8005A0C4: add.s       $f0, $f2, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x8005A0C8: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x8005A0CC: nop

    // 0x8005A0D0: bc1t        L_8005A088
    if (c1cs) {
        // 0x8005A0D4: nop
    
            goto L_8005A088;
    }
    // 0x8005A0D4: nop

    // 0x8005A0D8: bne         $a2, $zero, L_8005A114
    if (ctx->r6 != 0) {
        // 0x8005A0DC: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_8005A114;
    }
    // 0x8005A0DC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8005A0E0: lwc1        $f4, 0x4($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X4);
    // 0x8005A0E4: lwc1        $f2, 0x14($a1)
    ctx->f2.u32l = MEM_W(ctx->r5, 0X14);
    // 0x8005A0E8: c.lt.s      $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f4.fl < ctx->f2.fl;
    // 0x8005A0EC: nop

    // 0x8005A0F0: bc1t        L_8005A088
    if (c1cs) {
        // 0x8005A0F4: nop
    
            goto L_8005A088;
    }
    // 0x8005A0F4: nop

    // 0x8005A0F8: lwc1        $f0, 0x2C($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0X2C);
    // 0x8005A0FC: add.s       $f0, $f2, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x8005A100: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x8005A104: nop

    // 0x8005A108: bc1t        L_8005A114
    if (c1cs) {
        // 0x8005A10C: addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
            goto L_8005A114;
    }
    // 0x8005A10C: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // 0x8005A110: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8005A114:
    // 0x8005A114: jr          $ra
    // 0x8005A118: nop

    return;
    // 0x8005A118: nop

;}
RECOMP_FUNC void fake_func_8005A11C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
;}
RECOMP_FUNC void func_8005A120(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005A120: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x8005A124: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x8005A128: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x8005A12C: addiu       $a0, $zero, 0x2C90
    ctx->r4 = ADD32(0, 0X2C90);
    // 0x8005A130: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x8005A134: sw          $ra, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r31;
    // 0x8005A138: sw          $fp, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r30;
    // 0x8005A13C: sw          $s7, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r23;
    // 0x8005A140: sw          $s6, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r22;
    // 0x8005A144: sw          $s5, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r21;
    // 0x8005A148: sw          $s4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r20;
    // 0x8005A14C: sw          $s3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r19;
    // 0x8005A150: sw          $s2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r18;
    // 0x8005A154: jal         0x80001ACC
    // 0x8005A158: sw          $s1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r17;
    rs_malloc(rdram, ctx);
        goto after_0;
    // 0x8005A158: sw          $s1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r17;
    after_0:
    // 0x8005A15C: lui         $a0, 0x8004
    ctx->r4 = S32(0X8004 << 16);
    // 0x8005A160: addiu       $a0, $a0, -0x5240
    ctx->r4 = ADD32(ctx->r4, -0X5240);
    // 0x8005A164: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x8005A168: addu        $s3, $v0, $zero
    ctx->r19 = ADD32(ctx->r2, 0);
    // 0x8005A16C: addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    // 0x8005A170: addu        $a3, $a1, $zero
    ctx->r7 = ADD32(ctx->r5, 0);
    // 0x8005A174: sw          $s3, 0xF00($s0)
    MEM_W(0XF00, ctx->r16) = ctx->r19;
    // 0x8005A178: jal         0x80054EF0
    // 0x8005A17C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    func_80054EF0(rdram, ctx);
        goto after_1;
    // 0x8005A17C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_1:
    // 0x8005A180: addu        $s2, $zero, $zero
    ctx->r18 = ADD32(0, 0);
    // 0x8005A184: addiu       $s5, $zero, 0x4
    ctx->r21 = ADD32(0, 0X4);
    // 0x8005A188: lui         $v1, 0x800A
    ctx->r3 = S32(0X800A << 16);
    // 0x8005A18C: addiu       $s7, $v1, -0x1340
    ctx->r23 = ADD32(ctx->r3, -0X1340);
    // 0x8005A190: addiu       $s6, $zero, 0xFF
    ctx->r22 = ADD32(0, 0XFF);
    // 0x8005A194: addu        $s0, $s3, $zero
    ctx->r16 = ADD32(ctx->r19, 0);
    // 0x8005A198: addiu       $s4, $zero, 0xED8
    ctx->r20 = ADD32(0, 0XED8);
    // 0x8005A19C: addu        $s1, $s3, $zero
    ctx->r17 = ADD32(ctx->r19, 0);
    // 0x8005A1A0: sw          $v0, 0x2B44($s3)
    MEM_W(0X2B44, ctx->r19) = ctx->r2;
L_8005A1A4:
    // 0x8005A1A4: addu        $a0, $s3, $s4
    ctx->r4 = ADD32(ctx->r19, ctx->r20);
    // 0x8005A1A8: sw          $zero, 0xC($s1)
    MEM_W(0XC, ctx->r17) = 0;
    // 0x8005A1AC: sw          $zero, 0x8($s1)
    MEM_W(0X8, ctx->r17) = 0;
    // 0x8005A1B0: sw          $zero, 0x4($s1)
    MEM_W(0X4, ctx->r17) = 0;
    // 0x8005A1B4: sw          $zero, 0x0($s1)
    MEM_W(0X0, ctx->r17) = 0;
    // 0x8005A1B8: sw          $a0, 0x10($s1)
    MEM_W(0X10, ctx->r17) = ctx->r4;
    // 0x8005A1BC: sw          $zero, 0x14($s1)
    MEM_W(0X14, ctx->r17) = 0;
    // 0x8005A1C0: sw          $zero, 0xEDC($s0)
    MEM_W(0XEDC, ctx->r16) = 0;
    // 0x8005A1C4: sw          $zero, 0xED8($s0)
    MEM_W(0XED8, ctx->r16) = 0;
    // 0x8005A1C8: sw          $zero, 0xEE0($s0)
    MEM_W(0XEE0, ctx->r16) = 0;
    // 0x8005A1CC: sw          $s5, 0xEE4($s0)
    MEM_W(0XEE4, ctx->r16) = ctx->r21;
    // 0x8005A1D0: sw          $zero, 0xEF4($s0)
    MEM_W(0XEF4, ctx->r16) = 0;
    // 0x8005A1D4: sw          $zero, 0xEE8($s0)
    MEM_W(0XEE8, ctx->r16) = 0;
    // 0x8005A1D8: sw          $s5, 0xEEC($s0)
    MEM_W(0XEEC, ctx->r16) = ctx->r21;
    // 0x8005A1DC: sw          $zero, 0xEF0($s0)
    MEM_W(0XEF0, ctx->r16) = 0;
    // 0x8005A1E0: sw          $zero, 0xEF8($s0)
    MEM_W(0XEF8, ctx->r16) = 0;
    // 0x8005A1E4: sw          $s7, 0xEFC($s0)
    MEM_W(0XEFC, ctx->r16) = ctx->r23;
    // 0x8005A1E8: jal         0x8000A85C
    // 0x8005A1EC: sw          $zero, 0xF00($s0)
    MEM_W(0XF00, ctx->r16) = 0;
    func_8000A85C(rdram, ctx);
        goto after_2;
    // 0x8005A1EC: sw          $zero, 0xF00($s0)
    MEM_W(0XF00, ctx->r16) = 0;
    after_2:
    // 0x8005A1F0: addiu       $s0, $s0, 0x5C
    ctx->r16 = ADD32(ctx->r16, 0X5C);
    // 0x8005A1F4: addiu       $s4, $s4, 0x5C
    ctx->r20 = ADD32(ctx->r20, 0X5C);
    // 0x8005A1F8: addu        $v0, $s3, $s2
    ctx->r2 = ADD32(ctx->r19, ctx->r18);
    // 0x8005A1FC: sb          $s2, 0x2B7A($v0)
    MEM_B(0X2B7A, ctx->r2) = ctx->r18;
    // 0x8005A200: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x8005A204: sb          $s6, 0x2B48($v0)
    MEM_B(0X2B48, ctx->r2) = ctx->r22;
    // 0x8005A208: slti        $v0, $s2, 0x32
    ctx->r2 = SIGNED(ctx->r18) < 0X32 ? 1 : 0;
    // 0x8005A20C: bne         $v0, $zero, L_8005A1A4
    if (ctx->r2 != 0) {
        // 0x8005A210: addiu       $s1, $s1, 0x4C
        ctx->r17 = ADD32(ctx->r17, 0X4C);
            goto L_8005A1A4;
    }
    // 0x8005A210: addiu       $s1, $s1, 0x4C
    ctx->r17 = ADD32(ctx->r17, 0X4C);
    // 0x8005A214: addu        $s2, $zero, $zero
    ctx->r18 = ADD32(0, 0);
    // 0x8005A218: addiu       $s6, $s3, 0x26B8
    ctx->r22 = ADD32(ctx->r19, 0X26B8);
    // 0x8005A21C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x8005A220: addiu       $a2, $zero, 0x1000
    ctx->r6 = ADD32(0, 0X1000);
    // 0x8005A224: addiu       $s0, $s3, 0x26DF
    ctx->r16 = ADD32(ctx->r19, 0X26DF);
    // 0x8005A228: addu        $s5, $s3, $zero
    ctx->r21 = ADD32(ctx->r19, 0);
    // 0x8005A22C: addiu       $a1, $zero, 0x26B8
    ctx->r5 = ADD32(0, 0X26B8);
    // 0x8005A230: addu        $s4, $s3, $zero
    ctx->r20 = ADD32(ctx->r19, 0);
    // 0x8005A234: addiu       $fp, $zero, 0x20D0
    ctx->r30 = ADD32(0, 0X20D0);
    // 0x8005A238: addiu       $s7, $zero, 0x25D8
    ctx->r23 = ADD32(0, 0X25D8);
    // 0x8005A23C: addu        $s1, $s3, $zero
    ctx->r17 = ADD32(ctx->r19, 0);
L_8005A240:
    // 0x8005A240: lui         $v0, 0x297
    ctx->r2 = S32(0X297 << 16);
    // 0x8005A244: ori         $v0, $v0, 0x8
    ctx->r2 = ctx->r2 | 0X8;
    // 0x8005A248: addu        $a0, $s3, $fp
    ctx->r4 = ADD32(ctx->r19, ctx->r30);
    // 0x8005A24C: sw          $v0, 0x20DC($s1)
    MEM_W(0X20DC, ctx->r17) = ctx->r2;
    // 0x8005A250: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // 0x8005A254: sw          $v0, 0x20E4($s1)
    MEM_W(0X20E4, ctx->r17) = ctx->r2;
    // 0x8005A258: addu        $v0, $s3, $s7
    ctx->r2 = ADD32(ctx->r19, ctx->r23);
    // 0x8005A25C: lui         $t1, 0x800A
    ctx->r9 = S32(0X800A << 16);
    // 0x8005A260: addiu       $t1, $t1, -0x1340
    ctx->r9 = ADD32(ctx->r9, -0X1340);
    // 0x8005A264: sw          $zero, 0xEDC($s1)
    MEM_W(0XEDC, ctx->r17) = 0;
    // 0x8005A268: sw          $zero, 0x20D0($s1)
    MEM_W(0X20D0, ctx->r17) = 0;
    // 0x8005A26C: sw          $zero, 0x20D8($s1)
    MEM_W(0X20D8, ctx->r17) = 0;
    // 0x8005A270: sw          $zero, 0x20EC($s1)
    MEM_W(0X20EC, ctx->r17) = 0;
    // 0x8005A274: sw          $zero, 0x20E0($s1)
    MEM_W(0X20E0, ctx->r17) = 0;
    // 0x8005A278: sw          $zero, 0x20E8($s1)
    MEM_W(0X20E8, ctx->r17) = 0;
    // 0x8005A27C: sw          $v0, 0x20F0($s1)
    MEM_W(0X20F0, ctx->r17) = ctx->r2;
    // 0x8005A280: sw          $t1, 0x20F4($s1)
    MEM_W(0X20F4, ctx->r17) = ctx->r9;
    // 0x8005A284: sw          $zero, 0x20F8($s1)
    MEM_W(0X20F8, ctx->r17) = 0;
    // 0x8005A288: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    // 0x8005A28C: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    // 0x8005A290: jal         0x8000A85C
    // 0x8005A294: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    func_8000A85C(rdram, ctx);
        goto after_3;
    // 0x8005A294: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    after_3:
    // 0x8005A298: lui         $v1, 0xA0C
    ctx->r3 = S32(0XA0C << 16);
    // 0x8005A29C: ori         $v1, $v1, 0x9005
    ctx->r3 = ctx->r3 | 0X9005;
    // 0x8005A2A0: lui         $a0, 0x9249
    ctx->r4 = S32(0X9249 << 16);
    // 0x8005A2A4: ori         $a0, $a0, 0x2493
    ctx->r4 = ctx->r4 | 0X2493;
    // 0x8005A2A8: sw          $zero, 0x25DC($s4)
    MEM_W(0X25DC, ctx->r20) = 0;
    // 0x8005A2AC: sw          $zero, 0x25D8($s4)
    MEM_W(0X25D8, ctx->r20) = 0;
    // 0x8005A2B0: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x8005A2B4: mult        $s2, $a0
    result = S64(S32(ctx->r18)) * S64(S32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8005A2B8: addu        $v0, $s3, $a1
    ctx->r2 = ADD32(ctx->r19, ctx->r5);
    // 0x8005A2BC: sw          $v0, 0x25E0($s4)
    MEM_W(0X25E0, ctx->r20) = ctx->r2;
    // 0x8005A2C0: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x8005A2C4: addiu       $v0, $zero, 0xC
    ctx->r2 = ADD32(0, 0XC);
    // 0x8005A2C8: sw          $a3, 0x25E4($s4)
    MEM_W(0X25E4, ctx->r20) = ctx->r7;
    // 0x8005A2CC: sw          $v0, 0x26B8($s5)
    MEM_W(0X26B8, ctx->r21) = ctx->r2;
    // 0x8005A2D0: addiu       $v0, $s5, 0x26B8
    ctx->r2 = ADD32(ctx->r21, 0X26B8);
    // 0x8005A2D4: sw          $v1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r3;
    // 0x8005A2D8: sw          $zero, 0x8($v0)
    MEM_W(0X8, ctx->r2) = 0;
    // 0x8005A2DC: lw          $v0, 0x0($s6)
    ctx->r2 = MEM_W(ctx->r22, 0X0);
    // 0x8005A2E0: ori         $v0, $v0, 0x82
    ctx->r2 = ctx->r2 | 0X82;
    // 0x8005A2E4: sw          $v0, 0x0($s6)
    MEM_W(0X0, ctx->r22) = ctx->r2;
    // 0x8005A2E8: sra         $v0, $s2, 31
    ctx->r2 = S32(SIGNED(ctx->r18) >> 31);
    // 0x8005A2EC: mfhi        $t1
    ctx->r9 = hi;
    // 0x8005A2F0: addu        $v1, $t1, $s2
    ctx->r3 = ADD32(ctx->r9, ctx->r18);
    // 0x8005A2F4: sra         $v1, $v1, 2
    ctx->r3 = S32(SIGNED(ctx->r3) >> 2);
    // 0x8005A2F8: subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // 0x8005A2FC: sll         $v0, $v1, 3
    ctx->r2 = S32(ctx->r3 << 3);
    // 0x8005A300: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x8005A304: subu        $v0, $s2, $v0
    ctx->r2 = SUB32(ctx->r18, ctx->r2);
    // 0x8005A308: lw          $v1, 0x2B44($s3)
    ctx->r3 = MEM_W(ctx->r19, 0X2B44);
    // 0x8005A30C: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x8005A310: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8005A314: lhu         $v1, 0x0($v0)
    ctx->r3 = MEM_HU(ctx->r2, 0X0);
    // 0x8005A318: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x8005A31C: sh          $v0, -0x17($s0)
    MEM_H(-0X17, ctx->r16) = ctx->r2;
    // 0x8005A320: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x8005A324: sh          $zero, -0x1B($s0)
    MEM_H(-0X1B, ctx->r16) = 0;
    // 0x8005A328: sh          $a3, -0x15($s0)
    MEM_H(-0X15, ctx->r16) = ctx->r7;
    // 0x8005A32C: sh          $v0, -0x19($s0)
    MEM_H(-0X19, ctx->r16) = ctx->r2;
    // 0x8005A330: sh          $zero, -0x13($s0)
    MEM_H(-0X13, ctx->r16) = 0;
    // 0x8005A334: sh          $zero, -0x11($s0)
    MEM_H(-0X11, ctx->r16) = 0;
    // 0x8005A338: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    // 0x8005A33C: slti        $v0, $s2, 0x7
    ctx->r2 = SIGNED(ctx->r18) < 0X7 ? 1 : 0;
    // 0x8005A340: sh          $zero, -0x5($s0)
    MEM_H(-0X5, ctx->r16) = 0;
    // 0x8005A344: sh          $zero, -0xF($s0)
    MEM_H(-0XF, ctx->r16) = 0;
    // 0x8005A348: sll         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3 << 16);
    // 0x8005A34C: sh          $a2, -0x7($s0)
    MEM_H(-0X7, ctx->r16) = ctx->r6;
    // 0x8005A350: sh          $a2, -0xB($s0)
    MEM_H(-0XB, ctx->r16) = ctx->r6;
    // 0x8005A354: sh          $a2, -0x9($s0)
    MEM_H(-0X9, ctx->r16) = ctx->r6;
    // 0x8005A358: sh          $a2, -0xD($s0)
    MEM_H(-0XD, ctx->r16) = ctx->r6;
    // 0x8005A35C: beq         $v0, $zero, L_8005A37C
    if (ctx->r2 == 0) {
        // 0x8005A360: sw          $v1, -0x1F($s0)
        MEM_W(-0X1F, ctx->r16) = ctx->r3;
            goto L_8005A37C;
    }
    // 0x8005A360: sw          $v1, -0x1F($s0)
    MEM_W(-0X1F, ctx->r16) = ctx->r3;
    // 0x8005A364: addiu       $v0, $zero, 0xC3
    ctx->r2 = ADD32(0, 0XC3);
    // 0x8005A368: sb          $v0, -0x3($s0)
    MEM_B(-0X3, ctx->r16) = ctx->r2;
    // 0x8005A36C: addiu       $v0, $zero, 0xA3
    ctx->r2 = ADD32(0, 0XA3);
    // 0x8005A370: sb          $v0, -0x2($s0)
    MEM_B(-0X2, ctx->r16) = ctx->r2;
    // 0x8005A374: j           L_8005A390
    // 0x8005A378: addiu       $v0, $zero, 0x77
    ctx->r2 = ADD32(0, 0X77);
        goto L_8005A390;
    // 0x8005A378: addiu       $v0, $zero, 0x77
    ctx->r2 = ADD32(0, 0X77);
L_8005A37C:
    // 0x8005A37C: addiu       $v0, $zero, 0xB6
    ctx->r2 = ADD32(0, 0XB6);
    // 0x8005A380: sb          $v0, -0x3($s0)
    MEM_B(-0X3, ctx->r16) = ctx->r2;
    // 0x8005A384: addiu       $v0, $zero, 0x8C
    ctx->r2 = ADD32(0, 0X8C);
    // 0x8005A388: sb          $v0, -0x2($s0)
    MEM_B(-0X2, ctx->r16) = ctx->r2;
    // 0x8005A38C: addiu       $v0, $zero, 0x57
    ctx->r2 = ADD32(0, 0X57);
L_8005A390:
    // 0x8005A390: sb          $v0, -0x1($s0)
    MEM_B(-0X1, ctx->r16) = ctx->r2;
    // 0x8005A394: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // 0x8005A398: sb          $v0, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r2;
    // 0x8005A39C: addiu       $s5, $s5, 0x28
    ctx->r21 = ADD32(ctx->r21, 0X28);
    // 0x8005A3A0: addiu       $a1, $a1, 0x28
    ctx->r5 = ADD32(ctx->r5, 0X28);
    // 0x8005A3A4: addiu       $s4, $s4, 0x10
    ctx->r20 = ADD32(ctx->r20, 0X10);
    // 0x8005A3A8: addiu       $fp, $fp, 0x5C
    ctx->r30 = ADD32(ctx->r30, 0X5C);
    // 0x8005A3AC: addiu       $s7, $s7, 0x10
    ctx->r23 = ADD32(ctx->r23, 0X10);
    // 0x8005A3B0: addiu       $s1, $s1, 0x5C
    ctx->r17 = ADD32(ctx->r17, 0X5C);
    // 0x8005A3B4: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x8005A3B8: addiu       $s0, $s0, 0x28
    ctx->r16 = ADD32(ctx->r16, 0X28);
    // 0x8005A3BC: slti        $v0, $s2, 0xE
    ctx->r2 = SIGNED(ctx->r18) < 0XE ? 1 : 0;
    // 0x8005A3C0: bne         $v0, $zero, L_8005A240
    if (ctx->r2 != 0) {
        // 0x8005A3C4: addiu       $s6, $s6, 0x28
        ctx->r22 = ADD32(ctx->r22, 0X28);
            goto L_8005A240;
    }
    // 0x8005A3C4: addiu       $s6, $s6, 0x28
    ctx->r22 = ADD32(ctx->r22, 0X28);
    // 0x8005A3C8: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x8005A3CC: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x8005A3D0: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    // 0x8005A3D4: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    // 0x8005A3D8: addiu       $a1, $zero, 0x2BB0
    ctx->r5 = ADD32(0, 0X2BB0);
    // 0x8005A3DC: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8005A3E0: lwc1        $f12, -0x5228($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X5228);
    // 0x8005A3E4: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8005A3E8: lwc1        $f10, -0x5224($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X5224);
    // 0x8005A3EC: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8005A3F0: lwc1        $f8, -0x5220($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X5220);
    // 0x8005A3F4: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8005A3F8: lwc1        $f6, -0x521C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X521C);
    // 0x8005A3FC: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8005A400: lwc1        $f4, -0x5218($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X5218);
    // 0x8005A404: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8005A408: lwc1        $f2, -0x5214($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X5214);
    // 0x8005A40C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
L_8005A410:
    // 0x8005A410: beq         $a0, $zero, L_8005A430
    if (ctx->r4 == 0) {
        // 0x8005A414: addu        $v1, $s3, $a1
        ctx->r3 = ADD32(ctx->r19, ctx->r5);
            goto L_8005A430;
    }
    // 0x8005A414: addu        $v1, $s3, $a1
    ctx->r3 = ADD32(ctx->r19, ctx->r5);
    // 0x8005A418: beql        $a0, $t0, L_8005A434
    if (ctx->r4 == ctx->r8) {
        // 0x8005A41C: swc1        $f8, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->f8.u32l;
            goto L_8005A434;
    }
    goto skip_0;
    // 0x8005A41C: swc1        $f8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f8.u32l;
    skip_0:
    // 0x8005A420: bnel        $a0, $a3, L_8005A434
    if (ctx->r4 != ctx->r7) {
        // 0x8005A424: swc1        $f10, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->f10.u32l;
            goto L_8005A434;
    }
    goto skip_1;
    // 0x8005A424: swc1        $f10, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f10.u32l;
    skip_1:
    // 0x8005A428: j           L_8005A434
    // 0x8005A42C: swc1        $f12, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f12.u32l;
        goto L_8005A434;
    // 0x8005A42C: swc1        $f12, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f12.u32l;
L_8005A430:
    // 0x8005A430: swc1        $f6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f6.u32l;
L_8005A434:
    // 0x8005A434: sltiu       $v0, $a0, 0x2
    ctx->r2 = ctx->r4 < 0X2 ? 1 : 0;
    // 0x8005A438: beql        $v0, $zero, L_8005A444
    if (ctx->r2 == 0) {
        // 0x8005A43C: swc1        $f2, 0x4($v1)
        MEM_W(0X4, ctx->r3) = ctx->f2.u32l;
            goto L_8005A444;
    }
    goto skip_2;
    // 0x8005A43C: swc1        $f2, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->f2.u32l;
    skip_2:
    // 0x8005A440: swc1        $f4, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->f4.u32l;
L_8005A444:
    // 0x8005A444: addiu       $s2, $zero, 0xF
    ctx->r18 = ADD32(0, 0XF);
    // 0x8005A448: addu        $v0, $v1, $s2
    ctx->r2 = ADD32(ctx->r3, ctx->r18);
    // 0x8005A44C: swc1        $f0, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->f0.u32l;
    // 0x8005A450: swc1        $f0, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->f0.u32l;
    // 0x8005A454: swc1        $f0, 0x14($v1)
    MEM_W(0X14, ctx->r3) = ctx->f0.u32l;
    // 0x8005A458: swc1        $f0, 0x10($v1)
    MEM_W(0X10, ctx->r3) = ctx->f0.u32l;
L_8005A45C:
    // 0x8005A45C: sb          $a2, 0x18($v0)
    MEM_B(0X18, ctx->r2) = ctx->r6;
    // 0x8005A460: addiu       $s2, $s2, -0x1
    ctx->r18 = ADD32(ctx->r18, -0X1);
    // 0x8005A464: bgez        $s2, L_8005A45C
    if (SIGNED(ctx->r18) >= 0) {
        // 0x8005A468: addiu       $v0, $v0, -0x1
        ctx->r2 = ADD32(ctx->r2, -0X1);
            goto L_8005A45C;
    }
    // 0x8005A468: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x8005A46C: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x8005A470: slti        $v0, $a0, 0x4
    ctx->r2 = SIGNED(ctx->r4) < 0X4 ? 1 : 0;
    // 0x8005A474: bne         $v0, $zero, L_8005A410
    if (ctx->r2 != 0) {
        // 0x8005A478: addiu       $a1, $a1, 0x38
        ctx->r5 = ADD32(ctx->r5, 0X38);
            goto L_8005A410;
    }
    // 0x8005A478: addiu       $a1, $a1, 0x38
    ctx->r5 = ADD32(ctx->r5, 0X38);
    // 0x8005A47C: addiu       $v0, $zero, 0x31
    ctx->r2 = ADD32(0, 0X31);
    // 0x8005A480: sb          $v0, 0x2BAC($s3)
    MEM_B(0X2BAC, ctx->r19) = ctx->r2;
    // 0x8005A484: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
    // 0x8005A488: lw          $fp, 0x48($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X48);
    // 0x8005A48C: lw          $s7, 0x44($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X44);
    // 0x8005A490: lw          $s6, 0x40($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X40);
    // 0x8005A494: lw          $s5, 0x3C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X3C);
    // 0x8005A498: lw          $s4, 0x38($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X38);
    // 0x8005A49C: lw          $s3, 0x34($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X34);
    // 0x8005A4A0: lw          $s2, 0x30($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X30);
    // 0x8005A4A4: lw          $s1, 0x2C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X2C);
    // 0x8005A4A8: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x8005A4AC: jr          $ra
    // 0x8005A4B0: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x8005A4B0: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}
RECOMP_FUNC void func_8005A4B4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005A4B4: addiu       $sp, $sp, -0x120
    ctx->r29 = ADD32(ctx->r29, -0X120);
    // 0x8005A4B8: sdc1        $f28, 0x118($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0X118, ctx->r29);
    // 0x8005A4BC: mtc1        $zero, $f28
    ctx->f28.u32l = 0;
    // 0x8005A4C0: sw          $s5, 0xE4($sp)
    MEM_W(0XE4, ctx->r29) = ctx->r21;
    // 0x8005A4C4: addu        $s5, $zero, $zero
    ctx->r21 = ADD32(0, 0);
    // 0x8005A4C8: sw          $fp, 0xF0($sp)
    MEM_W(0XF0, ctx->r29) = ctx->r30;
    // 0x8005A4CC: addu        $fp, $s5, $zero
    ctx->r30 = ADD32(ctx->r21, 0);
    // 0x8005A4D0: sw          $ra, 0xF4($sp)
    MEM_W(0XF4, ctx->r29) = ctx->r31;
    // 0x8005A4D4: sw          $s7, 0xEC($sp)
    MEM_W(0XEC, ctx->r29) = ctx->r23;
    // 0x8005A4D8: sw          $s6, 0xE8($sp)
    MEM_W(0XE8, ctx->r29) = ctx->r22;
    // 0x8005A4DC: sw          $s4, 0xE0($sp)
    MEM_W(0XE0, ctx->r29) = ctx->r20;
    // 0x8005A4E0: sw          $s3, 0xDC($sp)
    MEM_W(0XDC, ctx->r29) = ctx->r19;
    // 0x8005A4E4: sw          $s2, 0xD8($sp)
    MEM_W(0XD8, ctx->r29) = ctx->r18;
    // 0x8005A4E8: sw          $s1, 0xD4($sp)
    MEM_W(0XD4, ctx->r29) = ctx->r17;
    // 0x8005A4EC: sw          $s0, 0xD0($sp)
    MEM_W(0XD0, ctx->r29) = ctx->r16;
    // 0x8005A4F0: sdc1        $f26, 0x110($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X110, ctx->r29);
    // 0x8005A4F4: sdc1        $f24, 0x108($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X108, ctx->r29);
    // 0x8005A4F8: sdc1        $f22, 0x100($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X100, ctx->r29);
    // 0x8005A4FC: sdc1        $f20, 0xF8($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0XF8, ctx->r29);
    // 0x8005A500: sw          $a0, 0x120($sp)
    MEM_W(0X120, ctx->r29) = ctx->r4;
    // 0x8005A504: sw          $a1, 0x124($sp)
    MEM_W(0X124, ctx->r29) = ctx->r5;
    // 0x8005A508: sw          $a3, 0x12C($sp)
    MEM_W(0X12C, ctx->r29) = ctx->r7;
    // 0x8005A50C: lw          $a2, 0xF00($a2)
    ctx->r6 = MEM_W(ctx->r6, 0XF00);
    // 0x8005A510: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8005A514: lwc1        $f26, -0x5210($at)
    ctx->f26.u32l = MEM_W(ctx->r1, -0X5210);
    // 0x8005A518: addiu       $t1, $a2, 0x20D0
    ctx->r9 = ADD32(ctx->r6, 0X20D0);
    // 0x8005A51C: sw          $a2, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->r6;
    // 0x8005A520: sw          $t1, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->r9;
    // 0x8005A524: sll         $v0, $fp, 3
    ctx->r2 = S32(ctx->r30 << 3);
L_8005A528:
    // 0x8005A528: subu        $v0, $v0, $fp
    ctx->r2 = SUB32(ctx->r2, ctx->r30);
    // 0x8005A52C: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x8005A530: lw          $t1, 0xC8($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XC8);
    // 0x8005A534: addiu       $v0, $v0, 0x2BB0
    ctx->r2 = ADD32(ctx->r2, 0X2BB0);
    // 0x8005A538: addu        $s4, $t1, $v0
    ctx->r20 = ADD32(ctx->r9, ctx->r2);
    // 0x8005A53C: lw          $t1, 0x130($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X130);
    // 0x8005A540: lwc1        $f2, 0x0($s4)
    ctx->f2.u32l = MEM_W(ctx->r20, 0X0);
    // 0x8005A544: lwc1        $f0, 0x4($t1)
    ctx->f0.u32l = MEM_W(ctx->r9, 0X4);
    // 0x8005A548: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x8005A54C: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    // 0x8005A550: lwc1        $f2, 0x0($t1)
    ctx->f2.u32l = MEM_W(ctx->r9, 0X0);
    // 0x8005A554: lwc1        $f0, 0x4($s4)
    ctx->f0.u32l = MEM_W(ctx->r20, 0X4);
    // 0x8005A558: mul.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x8005A55C: lwc1        $f0, 0x10($s4)
    ctx->f0.u32l = MEM_W(ctx->r20, 0X10);
    // 0x8005A560: sub.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl - ctx->f0.fl;
    // 0x8005A564: lwc1        $f0, 0x8($s4)
    ctx->f0.u32l = MEM_W(ctx->r20, 0X8);
    // 0x8005A568: add.s       $f12, $f0, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f12.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x8005A56C: c.lt.s      $f12, $f28
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 28);
    c1cs = ctx->f12.fl < ctx->f28.fl;
    // 0x8005A570: nop

    // 0x8005A574: bc1f        L_8005A5F4
    if (!c1cs) {
        // 0x8005A578: swc1        $f12, 0x8($s4)
        MEM_W(0X8, ctx->r20) = ctx->f12.u32l;
            goto L_8005A5F4;
    }
    // 0x8005A578: swc1        $f12, 0x8($s4)
    MEM_W(0X8, ctx->r20) = ctx->f12.u32l;
    // 0x8005A57C: mov.s       $f14, $f26
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 26);
    ctx->f14.fl = ctx->f26.fl;
    // 0x8005A580: jal         0x8001E20C
    // 0x8005A584: neg.s       $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = -ctx->f12.fl;
    func_8001E20C(rdram, ctx);
        goto after_0;
    // 0x8005A584: neg.s       $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = -ctx->f12.fl;
    after_0:
    // 0x8005A588: addu        $s2, $zero, $zero
    ctx->r18 = ADD32(0, 0);
    // 0x8005A58C: addu        $a3, $s4, $zero
    ctx->r7 = ADD32(ctx->r20, 0);
    // 0x8005A590: sub.s       $f0, $f26, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f26.fl - ctx->f0.fl;
    // 0x8005A594: addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    // 0x8005A598: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    // 0x8005A59C: swc1        $f0, 0x8($s4)
    MEM_W(0X8, ctx->r20) = ctx->f0.u32l;
L_8005A5A0:
    // 0x8005A5A0: addiu       $s0, $zero, 0x3
    ctx->r16 = ADD32(0, 0X3);
    // 0x8005A5A4: addu        $t0, $a1, $zero
    ctx->r8 = ADD32(ctx->r5, 0);
    // 0x8005A5A8: addu        $a2, $a0, $zero
    ctx->r6 = ADD32(ctx->r4, 0);
L_8005A5AC:
    // 0x8005A5AC: addu        $v0, $s0, $t0
    ctx->r2 = ADD32(ctx->r16, ctx->r8);
    // 0x8005A5B0: addu        $v1, $s0, $a2
    ctx->r3 = ADD32(ctx->r16, ctx->r6);
    // 0x8005A5B4: addiu       $s0, $s0, -0x1
    ctx->r16 = ADD32(ctx->r16, -0X1);
    // 0x8005A5B8: addu        $v1, $s4, $v1
    ctx->r3 = ADD32(ctx->r20, ctx->r3);
    // 0x8005A5BC: lbu         $v1, 0x18($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X18);
    // 0x8005A5C0: addu        $v0, $s4, $v0
    ctx->r2 = ADD32(ctx->r20, ctx->r2);
    // 0x8005A5C4: bgtz        $s0, L_8005A5AC
    if (SIGNED(ctx->r16) > 0) {
        // 0x8005A5C8: sb          $v1, 0x18($v0)
        MEM_B(0X18, ctx->r2) = ctx->r3;
            goto L_8005A5AC;
    }
    // 0x8005A5C8: sb          $v1, 0x18($v0)
    MEM_B(0X18, ctx->r2) = ctx->r3;
    // 0x8005A5CC: addiu       $t1, $zero, 0xFF
    ctx->r9 = ADD32(0, 0XFF);
    // 0x8005A5D0: sb          $t1, 0x18($a3)
    MEM_B(0X18, ctx->r7) = ctx->r9;
    // 0x8005A5D4: addiu       $a3, $a3, 0x4
    ctx->r7 = ADD32(ctx->r7, 0X4);
    // 0x8005A5D8: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x8005A5DC: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x8005A5E0: slti        $v0, $s2, 0x4
    ctx->r2 = SIGNED(ctx->r18) < 0X4 ? 1 : 0;
    // 0x8005A5E4: bne         $v0, $zero, L_8005A5A0
    if (ctx->r2 != 0) {
        // 0x8005A5E8: addiu       $a0, $a0, 0x4
        ctx->r4 = ADD32(ctx->r4, 0X4);
            goto L_8005A5A0;
    }
    // 0x8005A5E8: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x8005A5EC: j           L_8005A674
    // 0x8005A5F0: nop

        goto L_8005A674;
    // 0x8005A5F0: nop

L_8005A5F4:
    // 0x8005A5F4: c.lt.s      $f26, $f12
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f26.fl < ctx->f12.fl;
    // 0x8005A5F8: nop

    // 0x8005A5FC: bc1f        L_8005A674
    if (!c1cs) {
        // 0x8005A600: nop
    
            goto L_8005A674;
    }
    // 0x8005A600: nop

    // 0x8005A604: jal         0x8001E20C
    // 0x8005A608: mov.s       $f14, $f26
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 26);
    ctx->f14.fl = ctx->f26.fl;
    func_8001E20C(rdram, ctx);
        goto after_1;
    // 0x8005A608: mov.s       $f14, $f26
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 26);
    ctx->f14.fl = ctx->f26.fl;
    after_1:
    // 0x8005A60C: swc1        $f0, 0x8($s4)
    MEM_W(0X8, ctx->r20) = ctx->f0.u32l;
    // 0x8005A610: addu        $s2, $zero, $zero
    ctx->r18 = ADD32(0, 0);
    // 0x8005A614: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    // 0x8005A618: addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
L_8005A61C:
    // 0x8005A61C: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
    // 0x8005A620: addu        $a3, $a1, $zero
    ctx->r7 = ADD32(ctx->r5, 0);
    // 0x8005A624: addu        $a2, $a0, $zero
    ctx->r6 = ADD32(ctx->r4, 0);
    // 0x8005A628: addu        $v1, $s0, $a2
    ctx->r3 = ADD32(ctx->r16, ctx->r6);
L_8005A62C:
    // 0x8005A62C: addu        $v0, $s0, $a3
    ctx->r2 = ADD32(ctx->r16, ctx->r7);
    // 0x8005A630: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8005A634: addu        $v0, $s4, $v0
    ctx->r2 = ADD32(ctx->r20, ctx->r2);
    // 0x8005A638: lbu         $v0, 0x18($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X18);
    // 0x8005A63C: addu        $v1, $s4, $v1
    ctx->r3 = ADD32(ctx->r20, ctx->r3);
    // 0x8005A640: sb          $v0, 0x18($v1)
    MEM_B(0X18, ctx->r3) = ctx->r2;
    // 0x8005A644: slti        $v0, $s0, 0x4
    ctx->r2 = SIGNED(ctx->r16) < 0X4 ? 1 : 0;
    // 0x8005A648: bnel        $v0, $zero, L_8005A62C
    if (ctx->r2 != 0) {
        // 0x8005A64C: addu        $v1, $s0, $a2
        ctx->r3 = ADD32(ctx->r16, ctx->r6);
            goto L_8005A62C;
    }
    goto skip_0;
    // 0x8005A64C: addu        $v1, $s0, $a2
    ctx->r3 = ADD32(ctx->r16, ctx->r6);
    skip_0:
    // 0x8005A650: addu        $v0, $s0, $a0
    ctx->r2 = ADD32(ctx->r16, ctx->r4);
    // 0x8005A654: addu        $v0, $s4, $v0
    ctx->r2 = ADD32(ctx->r20, ctx->r2);
    // 0x8005A658: addiu       $t1, $zero, 0xFF
    ctx->r9 = ADD32(0, 0XFF);
    // 0x8005A65C: sb          $t1, 0x18($v0)
    MEM_B(0X18, ctx->r2) = ctx->r9;
    // 0x8005A660: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x8005A664: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x8005A668: slti        $v0, $s2, 0x4
    ctx->r2 = SIGNED(ctx->r18) < 0X4 ? 1 : 0;
    // 0x8005A66C: bne         $v0, $zero, L_8005A61C
    if (ctx->r2 != 0) {
        // 0x8005A670: addiu       $a1, $a1, 0x4
        ctx->r5 = ADD32(ctx->r5, 0X4);
            goto L_8005A61C;
    }
    // 0x8005A670: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
L_8005A674:
    // 0x8005A674: lw          $t1, 0x130($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X130);
    // 0x8005A678: lwc1        $f2, 0x4($s4)
    ctx->f2.u32l = MEM_W(ctx->r20, 0X4);
    // 0x8005A67C: lwc1        $f0, 0x0($t1)
    ctx->f0.u32l = MEM_W(ctx->r9, 0X0);
    // 0x8005A680: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x8005A684: swc1        $f0, 0x10($s4)
    MEM_W(0X10, ctx->r20) = ctx->f0.u32l;
    // 0x8005A688: lwc1        $f2, 0x8($t1)
    ctx->f2.u32l = MEM_W(ctx->r9, 0X8);
    // 0x8005A68C: lwc1        $f0, 0x4($s4)
    ctx->f0.u32l = MEM_W(ctx->r20, 0X4);
    // 0x8005A690: mul.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x8005A694: lwc1        $f0, 0x14($s4)
    ctx->f0.u32l = MEM_W(ctx->r20, 0X14);
    // 0x8005A698: sub.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl - ctx->f0.fl;
    // 0x8005A69C: lwc1        $f0, 0xC($s4)
    ctx->f0.u32l = MEM_W(ctx->r20, 0XC);
    // 0x8005A6A0: add.s       $f12, $f0, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f12.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x8005A6A4: c.lt.s      $f12, $f28
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 28);
    c1cs = ctx->f12.fl < ctx->f28.fl;
    // 0x8005A6A8: nop

    // 0x8005A6AC: bc1f        L_8005A734
    if (!c1cs) {
        // 0x8005A6B0: swc1        $f12, 0xC($s4)
        MEM_W(0XC, ctx->r20) = ctx->f12.u32l;
            goto L_8005A734;
    }
    // 0x8005A6B0: swc1        $f12, 0xC($s4)
    MEM_W(0XC, ctx->r20) = ctx->f12.u32l;
    // 0x8005A6B4: mov.s       $f14, $f26
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 26);
    ctx->f14.fl = ctx->f26.fl;
    // 0x8005A6B8: jal         0x8001E20C
    // 0x8005A6BC: neg.s       $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = -ctx->f12.fl;
    func_8001E20C(rdram, ctx);
        goto after_2;
    // 0x8005A6BC: neg.s       $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = -ctx->f12.fl;
    after_2:
    // 0x8005A6C0: sub.s       $f0, $f26, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f26.fl - ctx->f0.fl;
    // 0x8005A6C4: addiu       $s2, $zero, 0x3
    ctx->r18 = ADD32(0, 0X3);
    // 0x8005A6C8: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    // 0x8005A6CC: swc1        $f0, 0xC($s4)
    MEM_W(0XC, ctx->r20) = ctx->f0.u32l;
L_8005A6D0:
    // 0x8005A6D0: addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
    // 0x8005A6D4: sll         $a2, $s2, 2
    ctx->r6 = S32(ctx->r18 << 2);
    // 0x8005A6D8: addu        $a1, $a0, $zero
    ctx->r5 = ADD32(ctx->r4, 0);
    // 0x8005A6DC: addu        $v1, $s0, $a2
    ctx->r3 = ADD32(ctx->r16, ctx->r6);
L_8005A6E0:
    // 0x8005A6E0: addu        $v0, $s0, $a1
    ctx->r2 = ADD32(ctx->r16, ctx->r5);
    // 0x8005A6E4: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8005A6E8: addu        $v0, $s4, $v0
    ctx->r2 = ADD32(ctx->r20, ctx->r2);
    // 0x8005A6EC: lbu         $v0, 0x18($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X18);
    // 0x8005A6F0: addu        $v1, $s4, $v1
    ctx->r3 = ADD32(ctx->r20, ctx->r3);
    // 0x8005A6F4: sb          $v0, 0x18($v1)
    MEM_B(0X18, ctx->r3) = ctx->r2;
    // 0x8005A6F8: slti        $v0, $s0, 0x4
    ctx->r2 = SIGNED(ctx->r16) < 0X4 ? 1 : 0;
    // 0x8005A6FC: bnel        $v0, $zero, L_8005A6E0
    if (ctx->r2 != 0) {
        // 0x8005A700: addu        $v1, $s0, $a2
        ctx->r3 = ADD32(ctx->r16, ctx->r6);
            goto L_8005A6E0;
    }
    goto skip_1;
    // 0x8005A700: addu        $v1, $s0, $a2
    ctx->r3 = ADD32(ctx->r16, ctx->r6);
    skip_1:
    // 0x8005A704: addiu       $s2, $s2, -0x1
    ctx->r18 = ADD32(ctx->r18, -0X1);
    // 0x8005A708: bgtz        $s2, L_8005A6D0
    if (SIGNED(ctx->r18) > 0) {
        // 0x8005A70C: addiu       $a0, $a0, -0x4
        ctx->r4 = ADD32(ctx->r4, -0X4);
            goto L_8005A6D0;
    }
    // 0x8005A70C: addiu       $a0, $a0, -0x4
    ctx->r4 = ADD32(ctx->r4, -0X4);
    // 0x8005A710: addiu       $s0, $zero, 0x3
    ctx->r16 = ADD32(0, 0X3);
    // 0x8005A714: addu        $v0, $s4, $s0
    ctx->r2 = ADD32(ctx->r20, ctx->r16);
    // 0x8005A718: addiu       $t1, $zero, 0xFF
    ctx->r9 = ADD32(0, 0XFF);
L_8005A71C:
    // 0x8005A71C: sb          $t1, 0x18($v0)
    MEM_B(0X18, ctx->r2) = ctx->r9;
    // 0x8005A720: addiu       $s0, $s0, -0x1
    ctx->r16 = ADD32(ctx->r16, -0X1);
    // 0x8005A724: bgez        $s0, L_8005A71C
    if (SIGNED(ctx->r16) >= 0) {
        // 0x8005A728: addiu       $v0, $v0, -0x1
        ctx->r2 = ADD32(ctx->r2, -0X1);
            goto L_8005A71C;
    }
    // 0x8005A728: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x8005A72C: j           L_8005A7BC
    // 0x8005A730: nop

        goto L_8005A7BC;
    // 0x8005A730: nop

L_8005A734:
    // 0x8005A734: c.lt.s      $f26, $f12
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f26.fl < ctx->f12.fl;
    // 0x8005A738: nop

    // 0x8005A73C: bc1f        L_8005A7BC
    if (!c1cs) {
        // 0x8005A740: nop
    
            goto L_8005A7BC;
    }
    // 0x8005A740: nop

    // 0x8005A744: jal         0x8001E20C
    // 0x8005A748: mov.s       $f14, $f26
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 26);
    ctx->f14.fl = ctx->f26.fl;
    func_8001E20C(rdram, ctx);
        goto after_3;
    // 0x8005A748: mov.s       $f14, $f26
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 26);
    ctx->f14.fl = ctx->f26.fl;
    after_3:
    // 0x8005A74C: swc1        $f0, 0xC($s4)
    MEM_W(0XC, ctx->r20) = ctx->f0.u32l;
    // 0x8005A750: addiu       $s2, $zero, 0x1
    ctx->r18 = ADD32(0, 0X1);
    // 0x8005A754: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
L_8005A758:
    // 0x8005A758: addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
    // 0x8005A75C: addu        $a2, $a0, $zero
    ctx->r6 = ADD32(ctx->r4, 0);
    // 0x8005A760: sll         $a1, $s2, 2
    ctx->r5 = S32(ctx->r18 << 2);
    // 0x8005A764: addu        $v1, $s0, $a2
    ctx->r3 = ADD32(ctx->r16, ctx->r6);
L_8005A768:
    // 0x8005A768: addu        $v0, $s0, $a1
    ctx->r2 = ADD32(ctx->r16, ctx->r5);
    // 0x8005A76C: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8005A770: addu        $v0, $s4, $v0
    ctx->r2 = ADD32(ctx->r20, ctx->r2);
    // 0x8005A774: lbu         $v0, 0x18($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X18);
    // 0x8005A778: addu        $v1, $s4, $v1
    ctx->r3 = ADD32(ctx->r20, ctx->r3);
    // 0x8005A77C: sb          $v0, 0x18($v1)
    MEM_B(0X18, ctx->r3) = ctx->r2;
    // 0x8005A780: slti        $v0, $s0, 0x4
    ctx->r2 = SIGNED(ctx->r16) < 0X4 ? 1 : 0;
    // 0x8005A784: bnel        $v0, $zero, L_8005A768
    if (ctx->r2 != 0) {
        // 0x8005A788: addu        $v1, $s0, $a2
        ctx->r3 = ADD32(ctx->r16, ctx->r6);
            goto L_8005A768;
    }
    goto skip_2;
    // 0x8005A788: addu        $v1, $s0, $a2
    ctx->r3 = ADD32(ctx->r16, ctx->r6);
    skip_2:
    // 0x8005A78C: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x8005A790: slti        $v0, $s2, 0x4
    ctx->r2 = SIGNED(ctx->r18) < 0X4 ? 1 : 0;
    // 0x8005A794: bne         $v0, $zero, L_8005A758
    if (ctx->r2 != 0) {
        // 0x8005A798: addiu       $a0, $a0, 0x4
        ctx->r4 = ADD32(ctx->r4, 0X4);
            goto L_8005A758;
    }
    // 0x8005A798: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x8005A79C: addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
    // 0x8005A7A0: addu        $v0, $s0, $s4
    ctx->r2 = ADD32(ctx->r16, ctx->r20);
    // 0x8005A7A4: addiu       $t1, $zero, 0xFF
    ctx->r9 = ADD32(0, 0XFF);
L_8005A7A8:
    // 0x8005A7A8: sb          $t1, 0x24($v0)
    MEM_B(0X24, ctx->r2) = ctx->r9;
    // 0x8005A7AC: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8005A7B0: slti        $v0, $s0, 0x4
    ctx->r2 = SIGNED(ctx->r16) < 0X4 ? 1 : 0;
    // 0x8005A7B4: bne         $v0, $zero, L_8005A7A8
    if (ctx->r2 != 0) {
        // 0x8005A7B8: addu        $v0, $s0, $s4
        ctx->r2 = ADD32(ctx->r16, ctx->r20);
            goto L_8005A7A8;
    }
    // 0x8005A7B8: addu        $v0, $s0, $s4
    ctx->r2 = ADD32(ctx->r16, ctx->r20);
L_8005A7BC:
    // 0x8005A7BC: lw          $t1, 0x130($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X130);
    // 0x8005A7C0: lwc1        $f2, 0x4($s4)
    ctx->f2.u32l = MEM_W(ctx->r20, 0X4);
    // 0x8005A7C4: lwc1        $f0, 0x8($t1)
    ctx->f0.u32l = MEM_W(ctx->r9, 0X8);
    // 0x8005A7C8: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x8005A7CC: swc1        $f0, 0x14($s4)
    MEM_W(0X14, ctx->r20) = ctx->f0.u32l;
    // 0x8005A7D0: lw          $t1, 0x12C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X12C);
    // 0x8005A7D4: lwc1        $f4, 0x10($t1)
    ctx->f4.u32l = MEM_W(ctx->r9, 0X10);
    // 0x8005A7D8: abs.s       $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = fabsf(ctx->f4.fl);
    // 0x8005A7DC: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8005A7E0: lwc1        $f0, -0x520C($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X520C);
    // 0x8005A7E4: c.lt.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl < ctx->f0.fl;
    // 0x8005A7E8: nop

    // 0x8005A7EC: bc1f        L_8005A8D0
    if (!c1cs) {
        // 0x8005A7F0: nop
    
            goto L_8005A8D0;
    }
    // 0x8005A7F0: nop

    // 0x8005A7F4: jal         0x8001C400
    // 0x8005A7F8: nop

    func_8001C400(rdram, ctx);
        goto after_4;
    // 0x8005A7F8: nop

    after_4:
    // 0x8005A7FC: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8005A800: lwc1        $f2, -0x5208($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X5208);
    // 0x8005A804: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x8005A808: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8005A80C: lwc1        $f20, -0x5204($at)
    ctx->f20.u32l = MEM_W(ctx->r1, -0X5204);
    // 0x8005A810: sub.s       $f24, $f20, $f0
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f24.fl = ctx->f20.fl - ctx->f0.fl;
    // 0x8005A814: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8005A818: lwc1        $f22, -0x5200($at)
    ctx->f22.u32l = MEM_W(ctx->r1, -0X5200);
    // 0x8005A81C: sub.s       $f0, $f22, $f24
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f0.fl = ctx->f22.fl - ctx->f24.fl;
    // 0x8005A820: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8005A824: lwc1        $f12, -0x51FC($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X51FC);
    // 0x8005A828: mul.s       $f12, $f0, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = MUL_S(ctx->f0.fl, ctx->f12.fl);
    // 0x8005A82C: jal         0x80033960
    // 0x8005A830: nop

    sinf_recomp(rdram, ctx);
        goto after_5;
    // 0x8005A830: nop

    after_5:
    // 0x8005A834: lw          $t1, 0x12C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X12C);
    // 0x8005A838: addiu       $a0, $sp, 0x98
    ctx->r4 = ADD32(ctx->r29, 0X98);
    // 0x8005A83C: lwc1        $f2, 0xC($t1)
    ctx->f2.u32l = MEM_W(ctx->r9, 0XC);
    // 0x8005A840: sub.s       $f20, $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f20.fl = ctx->f20.fl - ctx->f0.fl;
    // 0x8005A844: sw          $zero, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = 0;
    // 0x8005A848: swc1        $f2, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->f2.u32l;
    // 0x8005A84C: lwc1        $f0, 0x14($t1)
    ctx->f0.u32l = MEM_W(ctx->r9, 0X14);
    // 0x8005A850: mul.s       $f24, $f20, $f22
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f24.fl = MUL_S(ctx->f20.fl, ctx->f22.fl);
    // 0x8005A854: jal         0x8001CF58
    // 0x8005A858: swc1        $f0, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->f0.u32l;
    normalize_vector(rdram, ctx);
        goto after_6;
    // 0x8005A858: swc1        $f0, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->f0.u32l;
    after_6:
    // 0x8005A85C: lui         $v1, 0x800A
    ctx->r3 = S32(0X800A << 16);
    // 0x8005A860: addiu       $v1, $v1, -0x1320
    ctx->r3 = ADD32(ctx->r3, -0X1320);
    // 0x8005A864: sll         $v0, $fp, 2
    ctx->r2 = S32(ctx->r30 << 2);
    // 0x8005A868: lwc1        $f2, 0xA0($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0XA0);
    // 0x8005A86C: lwc1        $f0, 0x98($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X98);
    // 0x8005A870: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8005A874: sw          $zero, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = 0;
    // 0x8005A878: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
    // 0x8005A87C: swc1        $f2, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->f2.u32l;
    // 0x8005A880: swc1        $f0, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->f0.u32l;
    // 0x8005A884: lwc1        $f0, 0x0($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8005A888: mul.s       $f0, $f0, $f24
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f24.fl);
    // 0x8005A88C: addiu       $s0, $sp, 0xB8
    ctx->r16 = ADD32(ctx->r29, 0XB8);
    // 0x8005A890: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x8005A894: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8005A898: jal         0x8001D240
    // 0x8005A89C: addiu       $a1, $sp, 0x88
    ctx->r5 = ADD32(ctx->r29, 0X88);
    func_8001D240(rdram, ctx);
        goto after_7;
    // 0x8005A89C: addiu       $a1, $sp, 0x88
    ctx->r5 = ADD32(ctx->r29, 0X88);
    after_7:
    // 0x8005A8A0: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x8005A8A4: addiu       $s0, $sp, 0x28
    ctx->r16 = ADD32(ctx->r29, 0X28);
    // 0x8005A8A8: jal         0x8001D548
    // 0x8005A8AC: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    func_8001D548(rdram, ctx);
        goto after_8;
    // 0x8005A8AC: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    after_8:
    // 0x8005A8B0: lw          $t1, 0x12C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X12C);
    // 0x8005A8B4: lw          $a1, 0x0($t1)
    ctx->r5 = MEM_W(ctx->r9, 0X0);
    // 0x8005A8B8: lw          $a2, 0x4($t1)
    ctx->r6 = MEM_W(ctx->r9, 0X4);
    // 0x8005A8BC: lw          $a3, 0x8($t1)
    ctx->r7 = MEM_W(ctx->r9, 0X8);
    // 0x8005A8C0: jal         0x8001CA90
    // 0x8005A8C4: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_8001CA90(rdram, ctx);
        goto after_9;
    // 0x8005A8C4: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_9:
    // 0x8005A8C8: j           L_8005A8D4
    // 0x8005A8CC: nop

        goto L_8005A8D4;
    // 0x8005A8CC: nop

L_8005A8D0:
    // 0x8005A8D0: mtc1        $zero, $f24
    ctx->f24.u32l = 0;
L_8005A8D4:
    // 0x8005A8D4: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8005A8D8: lwc1        $f22, -0x51F8($at)
    ctx->f22.u32l = MEM_W(ctx->r1, -0X51F8);
    // 0x8005A8DC: addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
L_8005A8E0:
    // 0x8005A8E0: slti        $v0, $s5, 0x32
    ctx->r2 = SIGNED(ctx->r21) < 0X32 ? 1 : 0;
    // 0x8005A8E4: beq         $v0, $zero, L_8005AAE0
    if (ctx->r2 == 0) {
        // 0x8005A8E8: sll         $v0, $s5, 1
        ctx->r2 = S32(ctx->r21 << 1);
            goto L_8005AAE0;
    }
    // 0x8005A8E8: sll         $v0, $s5, 1
    ctx->r2 = S32(ctx->r21 << 1);
    // 0x8005A8EC: addu        $s2, $zero, $zero
    ctx->r18 = ADD32(0, 0);
    // 0x8005A8F0: addu        $v0, $v0, $s5
    ctx->r2 = ADD32(ctx->r2, ctx->r21);
    // 0x8005A8F4: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x8005A8F8: subu        $v0, $v0, $s5
    ctx->r2 = SUB32(ctx->r2, ctx->r21);
    // 0x8005A8FC: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8005A900: lw          $t1, 0xC8($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XC8);
    // 0x8005A904: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8005A908: lwc1        $f20, -0x51F4($at)
    ctx->f20.u32l = MEM_W(ctx->r1, -0X51F4);
    // 0x8005A90C: addu        $s7, $v0, $t1
    ctx->r23 = ADD32(ctx->r2, ctx->r9);
    // 0x8005A910: sll         $v0, $s5, 2
    ctx->r2 = S32(ctx->r21 << 2);
    // 0x8005A914: addu        $v0, $v0, $s5
    ctx->r2 = ADD32(ctx->r2, ctx->r21);
    // 0x8005A918: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8005A91C: subu        $v0, $v0, $s5
    ctx->r2 = SUB32(ctx->r2, ctx->r21);
    // 0x8005A920: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8005A924: addu        $s6, $v0, $t1
    ctx->r22 = ADD32(ctx->r2, ctx->r9);
L_8005A928:
    // 0x8005A928: addu        $s1, $s4, $s0
    ctx->r17 = ADD32(ctx->r20, ctx->r16);
    // 0x8005A92C: lbu         $v1, 0x18($s1)
    ctx->r3 = MEM_BU(ctx->r17, 0X18);
    // 0x8005A930: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // 0x8005A934: bne         $v1, $v0, L_8005A97C
    if (ctx->r3 != ctx->r2) {
        // 0x8005A938: nop
    
            goto L_8005A97C;
    }
    // 0x8005A938: nop

    // 0x8005A93C: jal         0x80003430
    // 0x8005A940: nop

    rand_recomp(rdram, ctx);
        goto after_10;
    // 0x8005A940: nop

    after_10:
    // 0x8005A944: lui         $v1, 0x9249
    ctx->r3 = S32(0X9249 << 16);
    // 0x8005A948: ori         $v1, $v1, 0x2493
    ctx->r3 = ctx->r3 | 0X2493;
    // 0x8005A94C: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x8005A950: sra         $a0, $v0, 16
    ctx->r4 = S32(SIGNED(ctx->r2) >> 16);
    // 0x8005A954: mult        $a0, $v1
    result = S64(S32(ctx->r4)) * S64(S32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8005A958: sra         $v0, $v0, 31
    ctx->r2 = S32(SIGNED(ctx->r2) >> 31);
    // 0x8005A95C: mfhi        $t1
    ctx->r9 = hi;
    // 0x8005A960: addu        $v1, $t1, $a0
    ctx->r3 = ADD32(ctx->r9, ctx->r4);
    // 0x8005A964: sra         $v1, $v1, 2
    ctx->r3 = S32(SIGNED(ctx->r3) >> 2);
    // 0x8005A968: subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // 0x8005A96C: sll         $v0, $v1, 3
    ctx->r2 = S32(ctx->r3 << 3);
    // 0x8005A970: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x8005A974: subu        $a0, $a0, $v0
    ctx->r4 = SUB32(ctx->r4, ctx->r2);
    // 0x8005A978: sb          $a0, 0x18($s1)
    MEM_B(0X18, ctx->r17) = ctx->r4;
L_8005A97C:
    // 0x8005A97C: lw          $t1, 0x130($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X130);
    // 0x8005A980: lwc1        $f2, 0x8($s4)
    ctx->f2.u32l = MEM_W(ctx->r20, 0X8);
    // 0x8005A984: lwc1        $f0, 0x0($t1)
    ctx->f0.u32l = MEM_W(ctx->r9, 0X0);
    // 0x8005A988: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x8005A98C: add.s       $f0, $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f20.fl;
    // 0x8005A990: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    // 0x8005A994: lwc1        $f2, 0x8($t1)
    ctx->f2.u32l = MEM_W(ctx->r9, 0X8);
    // 0x8005A998: lwc1        $f0, 0xC($s4)
    ctx->f0.u32l = MEM_W(ctx->r20, 0XC);
    // 0x8005A99C: sub.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl - ctx->f0.fl;
    // 0x8005A9A0: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x8005A9A4: lw          $a0, 0x124($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X124);
    // 0x8005A9A8: add.s       $f2, $f2, $f22
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f22.fl;
    // 0x8005A9AC: lui         $a3, 0x41F0
    ctx->r7 = S32(0X41F0 << 16);
    // 0x8005A9B0: addiu       $a2, $sp, 0x18
    ctx->r6 = ADD32(ctx->r29, 0X18);
    // 0x8005A9B4: swc1        $f2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f2.u32l;
    // 0x8005A9B8: jal         0x8001DC34
    // 0x8005A9BC: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    func_8001DC34(rdram, ctx);
        goto after_11;
    // 0x8005A9BC: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_11:
    // 0x8005A9C0: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x8005A9C4: beql        $v0, $zero, L_8005AAC4
    if (ctx->r2 == 0) {
        // 0x8005A9C8: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_8005AAC4;
    }
    goto skip_3;
    // 0x8005A9C8: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    skip_3:
    // 0x8005A9CC: addu        $s3, $s6, $zero
    ctx->r19 = ADD32(ctx->r22, 0);
    // 0x8005A9D0: slti        $v0, $fp, 0x3
    ctx->r2 = SIGNED(ctx->r30) < 0X3 ? 1 : 0;
    // 0x8005A9D4: bne         $v0, $zero, L_8005A9EC
    if (ctx->r2 != 0) {
        // 0x8005A9D8: addu        $t0, $s7, $zero
        ctx->r8 = ADD32(ctx->r23, 0);
            goto L_8005A9EC;
    }
    // 0x8005A9D8: addu        $t0, $s7, $zero
    ctx->r8 = ADD32(ctx->r23, 0);
    // 0x8005A9DC: lbu         $v1, 0x18($s1)
    ctx->r3 = MEM_BU(ctx->r17, 0X18);
    // 0x8005A9E0: lw          $t1, 0xCC($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XCC);
    // 0x8005A9E4: j           L_8005A9F4
    // 0x8005A9E8: addiu       $v1, $v1, 0x7
    ctx->r3 = ADD32(ctx->r3, 0X7);
        goto L_8005A9F4;
    // 0x8005A9E8: addiu       $v1, $v1, 0x7
    ctx->r3 = ADD32(ctx->r3, 0X7);
L_8005A9EC:
    // 0x8005A9EC: lbu         $v1, 0x18($s1)
    ctx->r3 = MEM_BU(ctx->r17, 0X18);
    // 0x8005A9F0: lw          $t1, 0xCC($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XCC);
L_8005A9F4:
    // 0x8005A9F4: sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3 << 1);
    // 0x8005A9F8: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8005A9FC: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x8005AA00: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x8005AA04: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8005AA08: addu        $v0, $t1, $v0
    ctx->r2 = ADD32(ctx->r9, ctx->r2);
    // 0x8005AA0C: addiu       $s1, $s3, 0x1C
    ctx->r17 = ADD32(ctx->r19, 0X1C);
    // 0x8005AA10: mfc1        $a1, $f26
    ctx->r5 = (int32_t)ctx->f26.u32l;
    // 0x8005AA14: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x8005AA18: mfc1        $a3, $f26
    ctx->r7 = (int32_t)ctx->f26.u32l;
    // 0x8005AA1C: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x8005AA20: jal         0x8001CB64
    // 0x8005AA24: sw          $v0, 0xEE0($t0)
    MEM_W(0XEE0, ctx->r8) = ctx->r2;
    func_8001CB64(rdram, ctx);
        goto after_12;
    // 0x8005AA24: sw          $v0, 0xEE0($t0)
    MEM_W(0XEE0, ctx->r8) = ctx->r2;
    after_12:
    // 0x8005AA28: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x8005AA2C: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    // 0x8005AA30: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x8005AA34: jal         0x8001CA90
    // 0x8005AA38: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    func_8001CA90(rdram, ctx);
        goto after_13;
    // 0x8005AA38: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    after_13:
    // 0x8005AA3C: c.eq.s      $f24, $f28
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 28);
    c1cs = ctx->f24.fl == ctx->f28.fl;
    // 0x8005AA40: nop

    // 0x8005AA44: bc1t        L_8005AA8C
    if (c1cs) {
        // 0x8005AA48: nop
    
            goto L_8005AA8C;
    }
    // 0x8005AA48: nop

    // 0x8005AA4C: lw          $t1, 0x12C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X12C);
    // 0x8005AA50: lwc1        $f0, 0x0($t1)
    ctx->f0.u32l = MEM_W(ctx->r9, 0X0);
    // 0x8005AA54: lwc1        $f2, 0x8($t1)
    ctx->f2.u32l = MEM_W(ctx->r9, 0X8);
    // 0x8005AA58: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
    // 0x8005AA5C: neg.s       $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = -ctx->f2.fl;
    // 0x8005AA60: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8005AA64: lwc1        $f0, 0x4($t1)
    ctx->f0.u32l = MEM_W(ctx->r9, 0X4);
    // 0x8005AA68: mfc1        $a3, $f2
    ctx->r7 = (int32_t)ctx->f2.u32l;
    // 0x8005AA6C: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
    // 0x8005AA70: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8005AA74: jal         0x8001CA90
    // 0x8005AA78: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    func_8001CA90(rdram, ctx);
        goto after_14;
    // 0x8005AA78: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    after_14:
    // 0x8005AA7C: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    // 0x8005AA80: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    // 0x8005AA84: jal         0x800191C4
    // 0x8005AA88: addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    func_800191C4(rdram, ctx);
        goto after_15;
    // 0x8005AA88: addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    after_15:
L_8005AA8C:
    // 0x8005AA8C: lw          $t1, 0x120($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X120);
    // 0x8005AA90: lw          $v0, 0x0($t1)
    ctx->r2 = MEM_W(ctx->r9, 0X0);
    // 0x8005AA94: beq         $v0, $zero, L_8005AAA0
    if (ctx->r2 == 0) {
        // 0x8005AA98: sw          $v0, 0x0($s3)
        MEM_W(0X0, ctx->r19) = ctx->r2;
            goto L_8005AAA0;
    }
    // 0x8005AA98: sw          $v0, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r2;
    // 0x8005AA9C: sw          $s3, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r19;
L_8005AAA0:
    // 0x8005AAA0: addiu       $s7, $s7, 0x5C
    ctx->r23 = ADD32(ctx->r23, 0X5C);
    // 0x8005AAA4: addiu       $s6, $s6, 0x4C
    ctx->r22 = ADD32(ctx->r22, 0X4C);
    // 0x8005AAA8: addiu       $s5, $s5, 0x1
    ctx->r21 = ADD32(ctx->r21, 0X1);
    // 0x8005AAAC: sw          $zero, 0x4($s3)
    MEM_W(0X4, ctx->r19) = 0;
    // 0x8005AAB0: lw          $t1, 0x120($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X120);
    // 0x8005AAB4: slti        $v0, $s5, 0x32
    ctx->r2 = SIGNED(ctx->r21) < 0X32 ? 1 : 0;
    // 0x8005AAB8: beq         $v0, $zero, L_8005AAD4
    if (ctx->r2 == 0) {
        // 0x8005AABC: sw          $s3, 0x0($t1)
        MEM_W(0X0, ctx->r9) = ctx->r19;
            goto L_8005AAD4;
    }
    // 0x8005AABC: sw          $s3, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r19;
    // 0x8005AAC0: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_8005AAC4:
    // 0x8005AAC4: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x8005AAC8: slti        $v0, $s2, 0x4
    ctx->r2 = SIGNED(ctx->r18) < 0X4 ? 1 : 0;
    // 0x8005AACC: bne         $v0, $zero, L_8005A928
    if (ctx->r2 != 0) {
        // 0x8005AAD0: add.s       $f20, $f20, $f26
        CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f20.fl = ctx->f20.fl + ctx->f26.fl;
            goto L_8005A928;
    }
    // 0x8005AAD0: add.s       $f20, $f20, $f26
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f20.fl = ctx->f20.fl + ctx->f26.fl;
L_8005AAD4:
    // 0x8005AAD4: slti        $v0, $s0, 0x10
    ctx->r2 = SIGNED(ctx->r16) < 0X10 ? 1 : 0;
    // 0x8005AAD8: bne         $v0, $zero, L_8005A8E0
    if (ctx->r2 != 0) {
        // 0x8005AADC: add.s       $f22, $f22, $f26
        CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f22.fl = ctx->f22.fl + ctx->f26.fl;
            goto L_8005A8E0;
    }
    // 0x8005AADC: add.s       $f22, $f22, $f26
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f22.fl = ctx->f22.fl + ctx->f26.fl;
L_8005AAE0:
    // 0x8005AAE0: addiu       $fp, $fp, 0x1
    ctx->r30 = ADD32(ctx->r30, 0X1);
    // 0x8005AAE4: slti        $v0, $fp, 0x4
    ctx->r2 = SIGNED(ctx->r30) < 0X4 ? 1 : 0;
    // 0x8005AAE8: bnel        $v0, $zero, L_8005A528
    if (ctx->r2 != 0) {
        // 0x8005AAEC: sll         $v0, $fp, 3
        ctx->r2 = S32(ctx->r30 << 3);
            goto L_8005A528;
    }
    goto skip_4;
    // 0x8005AAEC: sll         $v0, $fp, 3
    ctx->r2 = S32(ctx->r30 << 3);
    skip_4:
    // 0x8005AAF0: lw          $ra, 0xF4($sp)
    ctx->r31 = MEM_W(ctx->r29, 0XF4);
    // 0x8005AAF4: lw          $fp, 0xF0($sp)
    ctx->r30 = MEM_W(ctx->r29, 0XF0);
    // 0x8005AAF8: lw          $s7, 0xEC($sp)
    ctx->r23 = MEM_W(ctx->r29, 0XEC);
    // 0x8005AAFC: lw          $s6, 0xE8($sp)
    ctx->r22 = MEM_W(ctx->r29, 0XE8);
    // 0x8005AB00: lw          $s5, 0xE4($sp)
    ctx->r21 = MEM_W(ctx->r29, 0XE4);
    // 0x8005AB04: lw          $s4, 0xE0($sp)
    ctx->r20 = MEM_W(ctx->r29, 0XE0);
    // 0x8005AB08: lw          $s3, 0xDC($sp)
    ctx->r19 = MEM_W(ctx->r29, 0XDC);
    // 0x8005AB0C: lw          $s2, 0xD8($sp)
    ctx->r18 = MEM_W(ctx->r29, 0XD8);
    // 0x8005AB10: lw          $s1, 0xD4($sp)
    ctx->r17 = MEM_W(ctx->r29, 0XD4);
    // 0x8005AB14: lw          $s0, 0xD0($sp)
    ctx->r16 = MEM_W(ctx->r29, 0XD0);
    // 0x8005AB18: ldc1        $f28, 0x118($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0X118);
    // 0x8005AB1C: ldc1        $f26, 0x110($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X110);
    // 0x8005AB20: ldc1        $f24, 0x108($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X108);
    // 0x8005AB24: ldc1        $f22, 0x100($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X100);
    // 0x8005AB28: ldc1        $f20, 0xF8($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0XF8);
    // 0x8005AB2C: jr          $ra
    // 0x8005AB30: addiu       $sp, $sp, 0x120
    ctx->r29 = ADD32(ctx->r29, 0X120);
    return;
    // 0x8005AB30: addiu       $sp, $sp, 0x120
    ctx->r29 = ADD32(ctx->r29, 0X120);
;}
RECOMP_FUNC void func_8005AB34(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005AB34: addiu       $sp, $sp, -0xE0
    ctx->r29 = ADD32(ctx->r29, -0XE0);
    // 0x8005AB38: addiu       $t5, $zero, -0x4E20
    ctx->r13 = ADD32(0, -0X4E20);
    // 0x8005AB3C: sw          $fp, 0xD8($sp)
    MEM_W(0XD8, ctx->r29) = ctx->r30;
    // 0x8005AB40: addu        $fp, $t5, $zero
    ctx->r30 = ADD32(ctx->r13, 0);
    // 0x8005AB44: sw          $ra, 0xDC($sp)
    MEM_W(0XDC, ctx->r29) = ctx->r31;
    // 0x8005AB48: sw          $s7, 0xD4($sp)
    MEM_W(0XD4, ctx->r29) = ctx->r23;
    // 0x8005AB4C: sw          $s6, 0xD0($sp)
    MEM_W(0XD0, ctx->r29) = ctx->r22;
    // 0x8005AB50: sw          $s5, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->r21;
    // 0x8005AB54: sw          $s4, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->r20;
    // 0x8005AB58: sw          $s3, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->r19;
    // 0x8005AB5C: sw          $s2, 0xC0($sp)
    MEM_W(0XC0, ctx->r29) = ctx->r18;
    // 0x8005AB60: sw          $s1, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->r17;
    // 0x8005AB64: sw          $s0, 0xB8($sp)
    MEM_W(0XB8, ctx->r29) = ctx->r16;
    // 0x8005AB68: sw          $a0, 0xE0($sp)
    MEM_W(0XE0, ctx->r29) = ctx->r4;
    // 0x8005AB6C: jal         0x8006B4B8
    // 0x8005AB70: sw          $t5, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->r13;
    func_8006B4B8(rdram, ctx);
        goto after_0;
    // 0x8005AB70: sw          $t5, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->r13;
    after_0:
    // 0x8005AB74: lui         $s0, 0x3D
    ctx->r16 = S32(0X3D << 16);
    // 0x8005AB78: ori         $s0, $s0, 0x8
    ctx->r16 = ctx->r16 | 0X8;
    // 0x8005AB7C: or          $v0, $v0, $s0
    ctx->r2 = ctx->r2 | ctx->r16;
    // 0x8005AB80: jal         0x8006B4E4
    // 0x8005AB84: sw          $v0, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r2;
    func_8006B4E4(rdram, ctx);
        goto after_1;
    // 0x8005AB84: sw          $v0, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r2;
    after_1:
    // 0x8005AB88: addiu       $a0, $sp, 0x78
    ctx->r4 = ADD32(ctx->r29, 0X78);
    // 0x8005AB8C: or          $v0, $v0, $s0
    ctx->r2 = ctx->r2 | ctx->r16;
    // 0x8005AB90: jal         0x8006B5CC
    // 0x8005AB94: sw          $v0, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->r2;
    func_8006B5CC(rdram, ctx);
        goto after_2;
    // 0x8005AB94: sw          $v0, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->r2;
    after_2:
    // 0x8005AB98: lui         $a0, 0x8004
    ctx->r4 = S32(0X8004 << 16);
    // 0x8005AB9C: jal         0x80057B4C
    // 0x8005ABA0: addiu       $a0, $a0, -0x51F0
    ctx->r4 = ADD32(ctx->r4, -0X51F0);
    getHobObjectByName(rdram, ctx);
        goto after_3;
    // 0x8005ABA0: addiu       $a0, $a0, -0x51F0
    ctx->r4 = ADD32(ctx->r4, -0X51F0);
    after_3:
    // 0x8005ABA4: lui         $a0, 0x8004
    ctx->r4 = S32(0X8004 << 16);
    // 0x8005ABA8: addiu       $a0, $a0, -0x51EC
    ctx->r4 = ADD32(ctx->r4, -0X51EC);
    // 0x8005ABAC: addu        $s3, $zero, $zero
    ctx->r19 = ADD32(0, 0);
    // 0x8005ABB0: sw          $v0, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r2;
    // 0x8005ABB4: lw          $v0, 0x10($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X10);
    // 0x8005ABB8: addiu       $s1, $sp, 0x50
    ctx->r17 = ADD32(ctx->r29, 0X50);
    // 0x8005ABBC: lw          $v0, 0x10($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X10);
    // 0x8005ABC0: lw          $s6, 0x20($v0)
    ctx->r22 = MEM_W(ctx->r2, 0X20);
    // 0x8005ABC4: lw          $s7, 0x24($v0)
    ctx->r23 = MEM_W(ctx->r2, 0X24);
    // 0x8005ABC8: jal         0x80022D68
    // 0x8005ABCC: addiu       $s0, $sp, 0x10
    ctx->r16 = ADD32(ctx->r29, 0X10);
    func_80022D68(rdram, ctx);
        goto after_4;
    // 0x8005ABCC: addiu       $s0, $sp, 0x10
    ctx->r16 = ADD32(ctx->r29, 0X10);
    after_4:
L_8005ABD0:
    // 0x8005ABD0: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x8005ABD4: lw          $a0, 0xC($s6)
    ctx->r4 = MEM_W(ctx->r22, 0XC);
    // 0x8005ABD8: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x8005ABDC: jal         0x80001ACC
    // 0x8005ABE0: sll         $a0, $a0, 1
    ctx->r4 = S32(ctx->r4 << 1);
    rs_malloc(rdram, ctx);
        goto after_5;
    // 0x8005ABE0: sll         $a0, $a0, 1
    ctx->r4 = S32(ctx->r4 << 1);
    after_5:
    // 0x8005ABE4: sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
    // 0x8005ABE8: sh          $zero, 0x0($s1)
    MEM_H(0X0, ctx->r17) = 0;
    // 0x8005ABEC: addiu       $s1, $s1, 0x2
    ctx->r17 = ADD32(ctx->r17, 0X2);
    // 0x8005ABF0: slti        $v0, $s3, 0x10
    ctx->r2 = SIGNED(ctx->r19) < 0X10 ? 1 : 0;
    // 0x8005ABF4: bne         $v0, $zero, L_8005ABD0
    if (ctx->r2 != 0) {
        // 0x8005ABF8: addiu       $s0, $s0, 0x4
        ctx->r16 = ADD32(ctx->r16, 0X4);
            goto L_8005ABD0;
    }
    // 0x8005ABF8: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x8005ABFC: lw          $s1, 0x8($s6)
    ctx->r17 = MEM_W(ctx->r22, 0X8);
    // 0x8005AC00: lw          $v0, 0xC($s6)
    ctx->r2 = MEM_W(ctx->r22, 0XC);
    // 0x8005AC04: beq         $v0, $zero, L_8005AC9C
    if (ctx->r2 == 0) {
        // 0x8005AC08: addu        $s3, $zero, $zero
        ctx->r19 = ADD32(0, 0);
            goto L_8005AC9C;
    }
    // 0x8005AC08: addu        $s3, $zero, $zero
    ctx->r19 = ADD32(0, 0);
    // 0x8005AC0C: lui         $t0, 0xFC
    ctx->r8 = S32(0XFC << 16);
    // 0x8005AC10: lui         $a3, 0x3F00
    ctx->r7 = S32(0X3F00 << 16);
    // 0x8005AC14: addu        $a2, $v0, $zero
    ctx->r6 = ADD32(ctx->r2, 0);
L_8005AC18:
    // 0x8005AC18: lw          $v0, 0x4($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X4);
    // 0x8005AC1C: lw          $v1, 0x0($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X0);
    // 0x8005AC20: and         $v0, $v0, $t0
    ctx->r2 = ctx->r2 & ctx->r8;
    // 0x8005AC24: srl         $v0, $v0, 16
    ctx->r2 = S32(U32(ctx->r2) >> 16);
    // 0x8005AC28: andi        $v1, $v1, 0x8
    ctx->r3 = ctx->r3 & 0X8;
    // 0x8005AC2C: beq         $v1, $zero, L_8005AC7C
    if (ctx->r3 == 0) {
        // 0x8005AC30: addu        $s2, $s1, $v0
        ctx->r18 = ADD32(ctx->r17, ctx->r2);
            goto L_8005AC7C;
    }
    // 0x8005AC30: addu        $s2, $s1, $v0
    ctx->r18 = ADD32(ctx->r17, ctx->r2);
    // 0x8005AC34: addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
    // 0x8005AC38: addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
L_8005AC3C:
    // 0x8005AC3C: lhu         $v0, 0x0($a1)
    ctx->r2 = MEM_HU(ctx->r5, 0X0);
    // 0x8005AC40: lw          $t6, 0x90($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X90);
    // 0x8005AC44: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x8005AC48: addu        $a0, $v0, $s7
    ctx->r4 = ADD32(ctx->r2, ctx->r23);
    // 0x8005AC4C: lh          $v1, 0x2($a0)
    ctx->r3 = MEM_H(ctx->r4, 0X2);
    // 0x8005AC50: slt         $v0, $t6, $v1
    ctx->r2 = SIGNED(ctx->r14) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8005AC54: bnel        $v0, $zero, L_8005AC5C
    if (ctx->r2 != 0) {
        // 0x8005AC58: sw          $v1, 0x90($sp)
        MEM_W(0X90, ctx->r29) = ctx->r3;
            goto L_8005AC5C;
    }
    goto skip_0;
    // 0x8005AC58: sw          $v1, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->r3;
    skip_0:
L_8005AC5C:
    // 0x8005AC5C: lh          $v1, 0x0($a0)
    ctx->r3 = MEM_H(ctx->r4, 0X0);
    // 0x8005AC60: slt         $v0, $fp, $v1
    ctx->r2 = SIGNED(ctx->r30) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8005AC64: bnel        $v0, $zero, L_8005AC6C
    if (ctx->r2 != 0) {
        // 0x8005AC68: addu        $fp, $v1, $zero
        ctx->r30 = ADD32(ctx->r3, 0);
            goto L_8005AC6C;
    }
    goto skip_1;
    // 0x8005AC68: addu        $fp, $v1, $zero
    ctx->r30 = ADD32(ctx->r3, 0);
    skip_1:
L_8005AC6C:
    // 0x8005AC6C: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8005AC70: slti        $v0, $s0, 0x4
    ctx->r2 = SIGNED(ctx->r16) < 0X4 ? 1 : 0;
    // 0x8005AC74: bne         $v0, $zero, L_8005AC3C
    if (ctx->r2 != 0) {
        // 0x8005AC78: addiu       $a1, $a1, 0x2
        ctx->r5 = ADD32(ctx->r5, 0X2);
            goto L_8005AC3C;
    }
    // 0x8005AC78: addiu       $a1, $a1, 0x2
    ctx->r5 = ADD32(ctx->r5, 0X2);
L_8005AC7C:
    // 0x8005AC7C: lw          $v0, 0x4($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X4);
    // 0x8005AC80: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x8005AC84: and         $v0, $v0, $a3
    ctx->r2 = ctx->r2 & ctx->r7;
    // 0x8005AC88: srl         $v0, $v0, 22
    ctx->r2 = S32(U32(ctx->r2) >> 22);
    // 0x8005AC8C: addu        $s1, $s1, $v0
    ctx->r17 = ADD32(ctx->r17, ctx->r2);
    // 0x8005AC90: sltu        $v0, $s3, $a2
    ctx->r2 = ctx->r19 < ctx->r6 ? 1 : 0;
    // 0x8005AC94: bne         $v0, $zero, L_8005AC18
    if (ctx->r2 != 0) {
        // 0x8005AC98: nop
    
            goto L_8005AC18;
    }
    // 0x8005AC98: nop

L_8005AC9C:
    // 0x8005AC9C: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8005ACA0: lwc1        $f4, -0x51E0($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X51E0);
    // 0x8005ACA4: lwc1        $f2, 0x90($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X90);
    // 0x8005ACA8: cvt.s.w     $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    ctx->f2.fl = CVT_S_W(ctx->f2.u32l);
    // 0x8005ACAC: mul.s       $f2, $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f4.fl);
    // 0x8005ACB0: mtc1        $fp, $f0
    ctx->f0.u32l = ctx->r30;
    // 0x8005ACB4: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x8005ACB8: addu        $s4, $zero, $zero
    ctx->r20 = ADD32(0, 0);
    // 0x8005ACBC: mul.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x8005ACC0: lw          $t8, 0xE0($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XE0);
    // 0x8005ACC4: sw          $zero, 0x94($sp)
    MEM_W(0X94, ctx->r29) = 0;
    // 0x8005ACC8: swc1        $f2, 0x10($t8)
    MEM_W(0X10, ctx->r24) = ctx->f2.u32l;
    // 0x8005ACCC: swc1        $f0, 0x14($t8)
    MEM_W(0X14, ctx->r24) = ctx->f0.u32l;
    // 0x8005ACD0: lw          $v0, 0xC($s6)
    ctx->r2 = MEM_W(ctx->r22, 0XC);
    // 0x8005ACD4: lw          $s1, 0x8($s6)
    ctx->r17 = MEM_W(ctx->r22, 0X8);
    // 0x8005ACD8: beq         $v0, $zero, L_8005AEEC
    if (ctx->r2 == 0) {
        // 0x8005ACDC: addu        $s3, $zero, $zero
        ctx->r19 = ADD32(0, 0);
            goto L_8005AEEC;
    }
    // 0x8005ACDC: addu        $s3, $zero, $zero
    ctx->r19 = ADD32(0, 0);
    // 0x8005ACE0: addiu       $fp, $sp, 0x10
    ctx->r30 = ADD32(ctx->r29, 0X10);
    // 0x8005ACE4: addiu       $s5, $sp, 0x50
    ctx->r21 = ADD32(ctx->r29, 0X50);
L_8005ACE8:
    // 0x8005ACE8: lhu         $v0, 0x4($s1)
    ctx->r2 = MEM_HU(ctx->r17, 0X4);
    // 0x8005ACEC: andi        $v0, $v0, 0xFC
    ctx->r2 = ctx->r2 & 0XFC;
    // 0x8005ACF0: addu        $s2, $s1, $v0
    ctx->r18 = ADD32(ctx->r17, ctx->r2);
    // 0x8005ACF4: lhu         $a1, 0x0($s2)
    ctx->r5 = MEM_HU(ctx->r18, 0X0);
    // 0x8005ACF8: lhu         $v0, 0x2($s2)
    ctx->r2 = MEM_HU(ctx->r18, 0X2);
    // 0x8005ACFC: lhu         $v1, 0x4($s2)
    ctx->r3 = MEM_HU(ctx->r18, 0X4);
    // 0x8005AD00: sll         $a1, $a1, 3
    ctx->r5 = S32(ctx->r5 << 3);
    // 0x8005AD04: addu        $a1, $a1, $s7
    ctx->r5 = ADD32(ctx->r5, ctx->r23);
    // 0x8005AD08: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x8005AD0C: addu        $v0, $v0, $s7
    ctx->r2 = ADD32(ctx->r2, ctx->r23);
    // 0x8005AD10: sll         $v1, $v1, 3
    ctx->r3 = S32(ctx->r3 << 3);
    // 0x8005AD14: addu        $v1, $v1, $s7
    ctx->r3 = ADD32(ctx->r3, ctx->r23);
    // 0x8005AD18: lh          $v0, 0x0($v0)
    ctx->r2 = MEM_H(ctx->r2, 0X0);
    // 0x8005AD1C: lh          $a0, 0x0($v1)
    ctx->r4 = MEM_H(ctx->r3, 0X0);
    // 0x8005AD20: lh          $v1, 0x0($a1)
    ctx->r3 = MEM_H(ctx->r5, 0X0);
    // 0x8005AD24: lhu         $a1, 0x0($a1)
    ctx->r5 = MEM_HU(ctx->r5, 0X0);
    // 0x8005AD28: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x8005AD2C: sll         $v1, $v1, 1
    ctx->r3 = S32(ctx->r3 << 1);
    // 0x8005AD30: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x8005AD34: srl         $v1, $v0, 31
    ctx->r3 = S32(U32(ctx->r2) >> 31);
    // 0x8005AD38: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8005AD3C: sra         $v0, $v0, 1
    ctx->r2 = S32(SIGNED(ctx->r2) >> 1);
    // 0x8005AD40: addu        $a1, $a1, $v0
    ctx->r5 = ADD32(ctx->r5, ctx->r2);
    // 0x8005AD44: sh          $a1, 0x70($sp)
    MEM_H(0X70, ctx->r29) = ctx->r5;
    // 0x8005AD48: sll         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5 << 16);
    // 0x8005AD4C: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
    // 0x8005AD50: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x8005AD54: cvt.s.w     $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    ctx->f12.fl = CVT_S_W(ctx->f12.u32l);
    // 0x8005AD58: lhu         $a2, 0x0($s2)
    ctx->r6 = MEM_HU(ctx->r18, 0X0);
    // 0x8005AD5C: lhu         $v1, 0x2($s2)
    ctx->r3 = MEM_HU(ctx->r18, 0X2);
    // 0x8005AD60: lhu         $v0, 0x4($s2)
    ctx->r2 = MEM_HU(ctx->r18, 0X4);
    // 0x8005AD64: sll         $a2, $a2, 3
    ctx->r6 = S32(ctx->r6 << 3);
    // 0x8005AD68: addu        $a2, $a2, $s7
    ctx->r6 = ADD32(ctx->r6, ctx->r23);
    // 0x8005AD6C: sll         $v1, $v1, 3
    ctx->r3 = S32(ctx->r3 << 3);
    // 0x8005AD70: addu        $v1, $v1, $s7
    ctx->r3 = ADD32(ctx->r3, ctx->r23);
    // 0x8005AD74: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x8005AD78: addu        $v0, $v0, $s7
    ctx->r2 = ADD32(ctx->r2, ctx->r23);
    // 0x8005AD7C: lh          $v1, 0x4($v1)
    ctx->r3 = MEM_H(ctx->r3, 0X4);
    // 0x8005AD80: lh          $a0, 0x4($v0)
    ctx->r4 = MEM_H(ctx->r2, 0X4);
    // 0x8005AD84: lh          $v0, 0x4($a2)
    ctx->r2 = MEM_H(ctx->r6, 0X4);
    // 0x8005AD88: addu        $v1, $v1, $a0
    ctx->r3 = ADD32(ctx->r3, ctx->r4);
    // 0x8005AD8C: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x8005AD90: subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // 0x8005AD94: srl         $v0, $v1, 31
    ctx->r2 = S32(U32(ctx->r3) >> 31);
    // 0x8005AD98: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x8005AD9C: lhu         $v0, 0x4($a2)
    ctx->r2 = MEM_HU(ctx->r6, 0X4);
    // 0x8005ADA0: sra         $v1, $v1, 1
    ctx->r3 = S32(SIGNED(ctx->r3) >> 1);
    // 0x8005ADA4: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8005ADA8: sh          $v0, 0x74($sp)
    MEM_H(0X74, ctx->r29) = ctx->r2;
    // 0x8005ADAC: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x8005ADB0: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x8005ADB4: mtc1        $v0, $f14
    ctx->f14.u32l = ctx->r2;
    // 0x8005ADB8: cvt.s.w     $f14, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    ctx->f14.fl = CVT_S_W(ctx->f14.u32l);
    // 0x8005ADBC: jal         0x8001C5F4
    // 0x8005ADC0: nop

    func_8001C5F4(rdram, ctx);
        goto after_6;
    // 0x8005ADC0: nop

    after_6:
    // 0x8005ADC4: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8005ADC8: lwc1        $f2, -0x51DC($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X51DC);
    // 0x8005ADCC: div.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f2.fl);
    // 0x8005ADD0: trunc.w.s   $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    ctx->f6.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x8005ADD4: mfc1        $v0, $f6
    ctx->r2 = (int32_t)ctx->f6.u32l;
    // 0x8005ADD8: andi        $s0, $v0, 0x7
    ctx->r16 = ctx->r2 & 0X7;
    // 0x8005ADDC: sll         $v1, $s0, 2
    ctx->r3 = S32(ctx->r16 << 2);
    // 0x8005ADE0: addu        $v1, $fp, $v1
    ctx->r3 = ADD32(ctx->r30, ctx->r3);
    // 0x8005ADE4: sll         $a0, $s0, 1
    ctx->r4 = S32(ctx->r16 << 1);
    // 0x8005ADE8: addu        $a0, $s5, $a0
    ctx->r4 = ADD32(ctx->r21, ctx->r4);
    // 0x8005ADEC: lhu         $v0, 0x0($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X0);
    // 0x8005ADF0: lw          $v1, 0x0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X0);
    // 0x8005ADF4: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x8005ADF8: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8005ADFC: sh          $s4, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r20;
    // 0x8005AE00: lhu         $v0, 0x0($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X0);
    // 0x8005AE04: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8005AE08: sh          $v0, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r2;
    // 0x8005AE0C: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x8005AE10: andi        $v0, $v0, 0x8
    ctx->r2 = ctx->r2 & 0X8;
    // 0x8005AE14: beql        $v0, $zero, L_8005AECC
    if (ctx->r2 == 0) {
        // 0x8005AE18: addiu       $s3, $s3, 0x1
        ctx->r19 = ADD32(ctx->r19, 0X1);
            goto L_8005AECC;
    }
    goto skip_2;
    // 0x8005AE18: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    skip_2:
    // 0x8005AE1C: lw          $t6, 0x94($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X94);
    // 0x8005AE20: slti        $v0, $t6, 0x1E
    ctx->r2 = SIGNED(ctx->r14) < 0X1E ? 1 : 0;
    // 0x8005AE24: beq         $v0, $zero, L_8005AEC8
    if (ctx->r2 == 0) {
        // 0x8005AE28: addu        $a2, $zero, $zero
        ctx->r6 = ADD32(0, 0);
            goto L_8005AEC8;
    }
    // 0x8005AE28: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // 0x8005AE2C: addiu       $v1, $s0, 0x8
    ctx->r3 = ADD32(ctx->r16, 0X8);
    // 0x8005AE30: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x8005AE34: addu        $a3, $fp, $v0
    ctx->r7 = ADD32(ctx->r30, ctx->r2);
    // 0x8005AE38: sll         $v1, $v1, 1
    ctx->r3 = S32(ctx->r3 << 1);
    // 0x8005AE3C: addu        $a1, $s5, $v1
    ctx->r5 = ADD32(ctx->r21, ctx->r3);
    // 0x8005AE40: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
L_8005AE44:
    // 0x8005AE44: lhu         $v0, 0x0($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X0);
    // 0x8005AE48: lw          $t8, 0x90($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X90);
    // 0x8005AE4C: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x8005AE50: addu        $v0, $v0, $s7
    ctx->r2 = ADD32(ctx->r2, ctx->r23);
    // 0x8005AE54: lh          $v1, 0x2($v0)
    ctx->r3 = MEM_H(ctx->r2, 0X2);
    // 0x8005AE58: subu        $v0, $t8, $v1
    ctx->r2 = SUB32(ctx->r24, ctx->r3);
    // 0x8005AE5C: bltz        $v0, L_8005AE74
    if (SIGNED(ctx->r2) < 0) {
        // 0x8005AE60: slti        $v0, $v0, 0xA
        ctx->r2 = SIGNED(ctx->r2) < 0XA ? 1 : 0;
            goto L_8005AE74;
    }
    // 0x8005AE60: slti        $v0, $v0, 0xA
    ctx->r2 = SIGNED(ctx->r2) < 0XA ? 1 : 0;
    // 0x8005AE64: bne         $v0, $zero, L_8005AE88
    if (ctx->r2 != 0) {
        // 0x8005AE68: nop
    
            goto L_8005AE88;
    }
    // 0x8005AE68: nop

    // 0x8005AE6C: j           L_8005AEB8
    // 0x8005AE70: addiu       $a0, $a0, 0x2
    ctx->r4 = ADD32(ctx->r4, 0X2);
        goto L_8005AEB8;
    // 0x8005AE70: addiu       $a0, $a0, 0x2
    ctx->r4 = ADD32(ctx->r4, 0X2);
L_8005AE74:
    // 0x8005AE74: lw          $t9, 0x90($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X90);
    // 0x8005AE78: subu        $v0, $v1, $t9
    ctx->r2 = SUB32(ctx->r3, ctx->r25);
    // 0x8005AE7C: slti        $v0, $v0, 0xA
    ctx->r2 = SIGNED(ctx->r2) < 0XA ? 1 : 0;
    // 0x8005AE80: beql        $v0, $zero, L_8005AEB8
    if (ctx->r2 == 0) {
        // 0x8005AE84: addiu       $a0, $a0, 0x2
        ctx->r4 = ADD32(ctx->r4, 0X2);
            goto L_8005AEB8;
    }
    goto skip_3;
    // 0x8005AE84: addiu       $a0, $a0, 0x2
    ctx->r4 = ADD32(ctx->r4, 0X2);
    skip_3:
L_8005AE88:
    // 0x8005AE88: lhu         $v0, 0x0($a1)
    ctx->r2 = MEM_HU(ctx->r5, 0X0);
    // 0x8005AE8C: lw          $v1, 0x0($a3)
    ctx->r3 = MEM_W(ctx->r7, 0X0);
    // 0x8005AE90: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x8005AE94: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8005AE98: sh          $s4, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r20;
    // 0x8005AE9C: lw          $t5, 0x94($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X94);
    // 0x8005AEA0: lhu         $v0, 0x0($a1)
    ctx->r2 = MEM_HU(ctx->r5, 0X0);
    // 0x8005AEA4: addiu       $t5, $t5, 0x1
    ctx->r13 = ADD32(ctx->r13, 0X1);
    // 0x8005AEA8: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8005AEAC: sw          $t5, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->r13;
    // 0x8005AEB0: j           L_8005AEC8
    // 0x8005AEB4: sh          $v0, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r2;
        goto L_8005AEC8;
    // 0x8005AEB4: sh          $v0, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r2;
L_8005AEB8:
    // 0x8005AEB8: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x8005AEBC: slti        $v0, $a2, 0x4
    ctx->r2 = SIGNED(ctx->r6) < 0X4 ? 1 : 0;
    // 0x8005AEC0: bne         $v0, $zero, L_8005AE44
    if (ctx->r2 != 0) {
        // 0x8005AEC4: nop
    
            goto L_8005AE44;
    }
    // 0x8005AEC4: nop

L_8005AEC8:
    // 0x8005AEC8: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
L_8005AECC:
    // 0x8005AECC: lw          $v1, 0x4($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X4);
    // 0x8005AED0: lw          $v0, 0xC($s6)
    ctx->r2 = MEM_W(ctx->r22, 0XC);
    // 0x8005AED4: srl         $v1, $v1, 22
    ctx->r3 = S32(U32(ctx->r3) >> 22);
    // 0x8005AED8: andi        $v1, $v1, 0xFC
    ctx->r3 = ctx->r3 & 0XFC;
    // 0x8005AEDC: addu        $s4, $s4, $v1
    ctx->r20 = ADD32(ctx->r20, ctx->r3);
    // 0x8005AEE0: sltu        $v0, $s3, $v0
    ctx->r2 = ctx->r19 < ctx->r2 ? 1 : 0;
    // 0x8005AEE4: bne         $v0, $zero, L_8005ACE8
    if (ctx->r2 != 0) {
        // 0x8005AEE8: addu        $s1, $s1, $v1
        ctx->r17 = ADD32(ctx->r17, ctx->r3);
            goto L_8005ACE8;
    }
    // 0x8005AEE8: addu        $s1, $s1, $v1
    ctx->r17 = ADD32(ctx->r17, ctx->r3);
L_8005AEEC:
    // 0x8005AEEC: andi        $s0, $s4, 0xFFFF
    ctx->r16 = ctx->r20 & 0XFFFF;
    // 0x8005AEF0: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x8005AEF4: jal         0x80001ACC
    // 0x8005AEF8: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    rs_malloc(rdram, ctx);
        goto after_7;
    // 0x8005AEF8: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    after_7:
    // 0x8005AEFC: sw          $v0, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r2;
    // 0x8005AF00: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // 0x8005AF04: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    // 0x8005AF08: addu        $s3, $zero, $zero
    ctx->r19 = ADD32(0, 0);
    // 0x8005AF0C: addiu       $t6, $sp, 0x10
    ctx->r14 = ADD32(ctx->r29, 0X10);
    // 0x8005AF10: addiu       $t8, $zero, 0x1C
    ctx->r24 = ADD32(0, 0X1C);
    // 0x8005AF14: addiu       $t9, $zero, 0xB14
    ctx->r25 = ADD32(0, 0XB14);
    // 0x8005AF18: sw          $zero, 0x94($sp)
    MEM_W(0X94, ctx->r29) = 0;
    // 0x8005AF1C: sw          $zero, 0x98($sp)
    MEM_W(0X98, ctx->r29) = 0;
    // 0x8005AF20: sw          $t6, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->r14;
    // 0x8005AF24: sw          $t8, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->r24;
    // 0x8005AF28: sw          $t9, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->r25;
    // 0x8005AF2C: lw          $a1, 0x8($s6)
    ctx->r5 = MEM_W(ctx->r22, 0X8);
    // 0x8005AF30: addiu       $t5, $zero, 0x6DC
    ctx->r13 = ADD32(0, 0X6DC);
    // 0x8005AF34: jal         0x80018EF4
    // 0x8005AF38: sw          $t5, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->r13;
    zmemcpy(rdram, ctx);
        goto after_8;
    // 0x8005AF38: sw          $t5, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->r13;
    after_8:
    // 0x8005AF3C: jal         0x8006B604
    // 0x8005AF40: nop

    func_8006B604(rdram, ctx);
        goto after_9;
    // 0x8005AF40: nop

    after_9:
    // 0x8005AF44: addu        $fp, $v0, $zero
    ctx->r30 = ADD32(ctx->r2, 0);
    // 0x8005AF48: lw          $s4, 0xE0($sp)
    ctx->r20 = MEM_W(ctx->r29, 0XE0);
    // 0x8005AF4C: lw          $s1, 0x8($s6)
    ctx->r17 = MEM_W(ctx->r22, 0X8);
    // 0x8005AF50: addu        $s5, $s4, $zero
    ctx->r21 = ADD32(ctx->r20, 0);
L_8005AF54:
    // 0x8005AF54: addiu       $a2, $zero, 0x5C
    ctx->r6 = ADD32(0, 0X5C);
    // 0x8005AF58: lw          $t6, 0x80($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X80);
    // 0x8005AF5C: lw          $t8, 0xE0($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XE0);
    // 0x8005AF60: lw          $v0, 0x10($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X10);
    // 0x8005AF64: lw          $t9, 0xA0($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XA0);
    // 0x8005AF68: lw          $a1, 0x10($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X10);
    // 0x8005AF6C: jal         0x80018EF4
    // 0x8005AF70: addu        $a0, $t8, $t9
    ctx->r4 = ADD32(ctx->r24, ctx->r25);
    zmemcpy(rdram, ctx);
        goto after_10;
    // 0x8005AF70: addu        $a0, $t8, $t9
    ctx->r4 = ADD32(ctx->r24, ctx->r25);
    after_10:
    // 0x8005AF74: slti        $v0, $s3, 0x8
    ctx->r2 = SIGNED(ctx->r19) < 0X8 ? 1 : 0;
    // 0x8005AF78: sw          $zero, 0x1C($s4)
    MEM_W(0X1C, ctx->r20) = 0;
    // 0x8005AF7C: beq         $v0, $zero, L_8005AF90
    if (ctx->r2 == 0) {
        // 0x8005AF80: sw          $zero, 0x20($s4)
        MEM_W(0X20, ctx->r20) = 0;
            goto L_8005AF90;
    }
    // 0x8005AF80: sw          $zero, 0x20($s4)
    MEM_W(0X20, ctx->r20) = 0;
    // 0x8005AF84: lw          $t5, 0x88($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X88);
    // 0x8005AF88: j           L_8005AF98
    // 0x8005AF8C: sw          $t5, 0x28($s4)
    MEM_W(0X28, ctx->r20) = ctx->r13;
        goto L_8005AF98;
    // 0x8005AF8C: sw          $t5, 0x28($s4)
    MEM_W(0X28, ctx->r20) = ctx->r13;
L_8005AF90:
    // 0x8005AF90: lw          $t6, 0x8C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X8C);
    // 0x8005AF94: sw          $t6, 0x28($s4)
    MEM_W(0X28, ctx->r20) = ctx->r14;
L_8005AF98:
    // 0x8005AF98: sll         $v0, $s3, 4
    ctx->r2 = S32(ctx->r19 << 4);
    // 0x8005AF9C: addiu       $v0, $v0, 0x5DC
    ctx->r2 = ADD32(ctx->r2, 0X5DC);
    // 0x8005AFA0: lw          $t8, 0xE0($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XE0);
    // 0x8005AFA4: lw          $t9, 0xA0($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XA0);
    // 0x8005AFA8: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8005AFAC: lwc1        $f0, -0x51D8($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X51D8);
    // 0x8005AFB0: addu        $a0, $t8, $t9
    ctx->r4 = ADD32(ctx->r24, ctx->r25);
    // 0x8005AFB4: addu        $v0, $t8, $v0
    ctx->r2 = ADD32(ctx->r24, ctx->r2);
    // 0x8005AFB8: sw          $v0, 0x3C($s4)
    MEM_W(0X3C, ctx->r20) = ctx->r2;
    // 0x8005AFBC: jal         0x8000A85C
    // 0x8005AFC0: swc1        $f0, 0x38($s4)
    MEM_W(0X38, ctx->r20) = ctx->f0.u32l;
    func_8000A85C(rdram, ctx);
        goto after_11;
    // 0x8005AFC0: swc1        $f0, 0x38($s4)
    MEM_W(0X38, ctx->r20) = ctx->f0.u32l;
    after_11:
    // 0x8005AFC4: sw          $zero, 0x5DC($s5)
    MEM_W(0X5DC, ctx->r21) = 0;
    // 0x8005AFC8: sw          $zero, 0x5E0($s5)
    MEM_W(0X5E0, ctx->r21) = 0;
    // 0x8005AFCC: sw          $s1, 0x5E4($s5)
    MEM_W(0X5E4, ctx->r21) = ctx->r17;
    // 0x8005AFD0: lw          $t5, 0x98($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X98);
    // 0x8005AFD4: addiu       $v0, $sp, 0x50
    ctx->r2 = ADD32(ctx->r29, 0X50);
    // 0x8005AFD8: addu        $a0, $v0, $t5
    ctx->r4 = ADD32(ctx->r2, ctx->r13);
    // 0x8005AFDC: lhu         $v0, 0x0($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X0);
    // 0x8005AFE0: sw          $v0, 0x5E8($s5)
    MEM_W(0X5E8, ctx->r21) = ctx->r2;
    // 0x8005AFE4: slti        $v0, $s3, 0x8
    ctx->r2 = SIGNED(ctx->r19) < 0X8 ? 1 : 0;
    // 0x8005AFE8: beq         $v0, $zero, L_8005B060
    if (ctx->r2 == 0) {
        // 0x8005AFEC: lui         $v0, 0x8013
        ctx->r2 = S32(0X8013 << 16);
            goto L_8005B060;
    }
    // 0x8005AFEC: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8005AFF0: lhu         $v0, 0x0($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X0);
    // 0x8005AFF4: beq         $v0, $zero, L_8005B314
    if (ctx->r2 == 0) {
        // 0x8005AFF8: addu        $s0, $zero, $zero
        ctx->r16 = ADD32(0, 0);
            goto L_8005B314;
    }
    // 0x8005AFF8: addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
    // 0x8005AFFC: lw          $s6, 0x9C($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X9C);
    // 0x8005B000: addu        $s2, $a0, $zero
    ctx->r18 = ADD32(ctx->r4, 0);
L_8005B004:
    // 0x8005B004: sll         $v0, $s0, 1
    ctx->r2 = S32(ctx->r16 << 1);
    // 0x8005B008: lw          $v1, 0x0($s6)
    ctx->r3 = MEM_W(ctx->r22, 0X0);
    // 0x8005B00C: lw          $t6, 0x84($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X84);
    // 0x8005B010: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8005B014: lhu         $a1, 0x0($v0)
    ctx->r5 = MEM_HU(ctx->r2, 0X0);
    // 0x8005B018: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x8005B01C: addu        $a1, $t6, $a1
    ctx->r5 = ADD32(ctx->r14, ctx->r5);
    // 0x8005B020: lw          $a2, 0x4($a1)
    ctx->r6 = MEM_W(ctx->r5, 0X4);
    // 0x8005B024: lui         $t8, 0x3F00
    ctx->r24 = S32(0X3F00 << 16);
    // 0x8005B028: and         $a2, $a2, $t8
    ctx->r6 = ctx->r6 & ctx->r24;
    // 0x8005B02C: jal         0x80018EF4
    // 0x8005B030: srl         $a2, $a2, 22
    ctx->r6 = S32(U32(ctx->r6) >> 22);
    zmemcpy(rdram, ctx);
        goto after_12;
    // 0x8005B030: srl         $a2, $a2, 22
    ctx->r6 = S32(U32(ctx->r6) >> 22);
    after_12:
    // 0x8005B034: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8005B038: lui         $t9, 0x3F00
    ctx->r25 = S32(0X3F00 << 16);
    // 0x8005B03C: lw          $v0, 0x4($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X4);
    // 0x8005B040: lhu         $v1, 0x0($s2)
    ctx->r3 = MEM_HU(ctx->r18, 0X0);
    // 0x8005B044: and         $v0, $v0, $t9
    ctx->r2 = ctx->r2 & ctx->r25;
    // 0x8005B048: srl         $v0, $v0, 22
    ctx->r2 = S32(U32(ctx->r2) >> 22);
    // 0x8005B04C: slt         $v1, $s0, $v1
    ctx->r3 = SIGNED(ctx->r16) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8005B050: bne         $v1, $zero, L_8005B004
    if (ctx->r3 != 0) {
        // 0x8005B054: addu        $s1, $s1, $v0
        ctx->r17 = ADD32(ctx->r17, ctx->r2);
            goto L_8005B004;
    }
    // 0x8005B054: addu        $s1, $s1, $v0
    ctx->r17 = ADD32(ctx->r17, ctx->r2);
    // 0x8005B058: j           L_8005B318
    // 0x8005B05C: addiu       $s4, $s4, 0x5C
    ctx->r20 = ADD32(ctx->r20, 0X5C);
        goto L_8005B318;
    // 0x8005B05C: addiu       $s4, $s4, 0x5C
    ctx->r20 = ADD32(ctx->r20, 0X5C);
L_8005B060:
    // 0x8005B060: lw          $v1, 0xB70($v0)
    ctx->r3 = MEM_W(ctx->r2, 0XB70);
    // 0x8005B064: addiu       $v0, $zero, 0xA
    ctx->r2 = ADD32(0, 0XA);
    // 0x8005B068: beq         $v1, $v0, L_8005B2F4
    if (ctx->r3 == ctx->r2) {
        // 0x8005B06C: nop
    
            goto L_8005B2F4;
    }
    // 0x8005B06C: nop

    // 0x8005B070: lw          $t5, 0xE0($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XE0);
    // 0x8005B074: lw          $t6, 0xA8($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XA8);
    // 0x8005B078: addu        $v0, $t5, $t6
    ctx->r2 = ADD32(ctx->r13, ctx->r14);
    // 0x8005B07C: sw          $v0, 0x5E4($s5)
    MEM_W(0X5E4, ctx->r21) = ctx->r2;
    // 0x8005B080: lw          $t8, 0xA4($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XA4);
    // 0x8005B084: lhu         $v0, 0x0($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X0);
    // 0x8005B088: addu        $a3, $t5, $t8
    ctx->r7 = ADD32(ctx->r13, ctx->r24);
    // 0x8005B08C: sw          $v0, 0x5E8($s5)
    MEM_W(0X5E8, ctx->r21) = ctx->r2;
    // 0x8005B090: sw          $a3, 0x40($s4)
    MEM_W(0X40, ctx->r20) = ctx->r7;
    // 0x8005B094: lhu         $v0, 0x0($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X0);
    // 0x8005B098: beq         $v0, $zero, L_8005B2E8
    if (ctx->r2 == 0) {
        // 0x8005B09C: addu        $s0, $zero, $zero
        ctx->r16 = ADD32(0, 0);
            goto L_8005B2E8;
    }
    // 0x8005B09C: addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
    // 0x8005B0A0: lui         $t9, 0x90C
    ctx->r25 = S32(0X90C << 16);
    // 0x8005B0A4: ori         $t9, $t9, 0x5000
    ctx->r25 = ctx->r25 | 0X5000;
    // 0x8005B0A8: lui         $t4, 0x8013
    ctx->r12 = S32(0X8013 << 16);
    // 0x8005B0AC: addu        $s6, $a0, $zero
    ctx->r22 = ADD32(ctx->r4, 0);
    // 0x8005B0B0: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x8005B0B4: addiu       $t1, $zero, 0x2
    ctx->r9 = ADD32(0, 0X2);
    // 0x8005B0B8: addiu       $t0, $zero, 0x3
    ctx->r8 = ADD32(0, 0X3);
    // 0x8005B0BC: lw          $t7, 0x9C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X9C);
    // 0x8005B0C0: lw          $t5, 0x94($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X94);
    // 0x8005B0C4: addiu       $a0, $a3, 0x1A
    ctx->r4 = ADD32(ctx->r7, 0X1A);
    // 0x8005B0C8: sw          $t9, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->r25;
    // 0x8005B0CC: sll         $v0, $t5, 3
    ctx->r2 = S32(ctx->r13 << 3);
    // 0x8005B0D0: addu        $v0, $v0, $t5
    ctx->r2 = ADD32(ctx->r2, ctx->r13);
    // 0x8005B0D4: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8005B0D8: addiu       $t3, $v0, 0x6DC
    ctx->r11 = ADD32(ctx->r2, 0X6DC);
L_8005B0DC:
    // 0x8005B0DC: sll         $v0, $s0, 1
    ctx->r2 = S32(ctx->r16 << 1);
    // 0x8005B0E0: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // 0x8005B0E4: lw          $v1, 0x0($t7)
    ctx->r3 = MEM_W(ctx->r15, 0X0);
    // 0x8005B0E8: lw          $t6, 0x84($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X84);
    // 0x8005B0EC: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8005B0F0: lhu         $v0, 0x0($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X0);
    // 0x8005B0F4: lui         $t8, 0xFC
    ctx->r24 = S32(0XFC << 16);
    // 0x8005B0F8: addu        $s1, $t6, $v0
    ctx->r17 = ADD32(ctx->r14, ctx->r2);
    // 0x8005B0FC: lw          $v0, 0x4($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X4);
    // 0x8005B100: lw          $t9, 0xE0($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XE0);
    // 0x8005B104: and         $v0, $v0, $t8
    ctx->r2 = ctx->r2 & ctx->r24;
    // 0x8005B108: srl         $v0, $v0, 16
    ctx->r2 = S32(U32(ctx->r2) >> 16);
    // 0x8005B10C: addu        $s2, $s1, $v0
    ctx->r18 = ADD32(ctx->r17, ctx->r2);
    // 0x8005B110: addu        $s1, $t9, $t3
    ctx->r17 = ADD32(ctx->r25, ctx->r11);
    // 0x8005B114: addiu       $t5, $zero, 0x18
    ctx->r13 = ADD32(0, 0X18);
    // 0x8005B118: addu        $v0, $t5, $zero
    ctx->r2 = ADD32(ctx->r13, 0);
    // 0x8005B11C: addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    // 0x8005B120: sw          $t5, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r13;
    // 0x8005B124: lw          $t6, 0xB0($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XB0);
    // 0x8005B128: ori         $v0, $v0, 0x80
    ctx->r2 = ctx->r2 | 0X80;
    // 0x8005B12C: sw          $v0, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r2;
    // 0x8005B130: sll         $v0, $s0, 2
    ctx->r2 = S32(ctx->r16 << 2);
    // 0x8005B134: sw          $zero, 0x8($s1)
    MEM_W(0X8, ctx->r17) = 0;
    // 0x8005B138: sw          $t6, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->r14;
    // 0x8005B13C: addiu       $t6, $t4, 0x6E18
    ctx->r14 = ADD32(ctx->r12, 0X6E18);
    // 0x8005B140: lwl         $t8, 0x0($t6)
    ctx->r24 = do_lwl(rdram, ctx->r24, ctx->r14, 0X0);
    // 0x8005B144: lwr         $t8, 0x3($t6)
    ctx->r24 = do_lwr(rdram, ctx->r24, ctx->r14, 0X3);
    // 0x8005B148: swl         $t8, 0x14($s1)
    do_swl(rdram, 0X14, ctx->r17, ctx->r24);
    // 0x8005B14C: swr         $t8, 0x17($s1)
    do_swr(rdram, 0X17, ctx->r17, ctx->r24);
    // 0x8005B150: addiu       $t6, $t4, 0x6E18
    ctx->r14 = ADD32(ctx->r12, 0X6E18);
    // 0x8005B154: lwl         $t8, 0x0($t6)
    ctx->r24 = do_lwl(rdram, ctx->r24, ctx->r14, 0X0);
    // 0x8005B158: lwr         $t8, 0x3($t6)
    ctx->r24 = do_lwr(rdram, ctx->r24, ctx->r14, 0X3);
    // 0x8005B15C: swl         $t8, 0x18($s1)
    do_swl(rdram, 0X18, ctx->r17, ctx->r24);
    // 0x8005B160: swr         $t8, 0x1B($s1)
    do_swr(rdram, 0X1B, ctx->r17, ctx->r24);
    // 0x8005B164: lwl         $t8, 0x78($sp)
    ctx->r24 = do_lwl(rdram, ctx->r24, ctx->r29, 0X78);
    // 0x8005B168: lwr         $t8, 0x7B($sp)
    ctx->r24 = do_lwr(rdram, ctx->r24, ctx->r29, 0X7B);
    // 0x8005B16C: swl         $t8, 0x1C($s1)
    do_swl(rdram, 0X1C, ctx->r17, ctx->r24);
    // 0x8005B170: swr         $t8, 0x1F($s1)
    do_swr(rdram, 0X1F, ctx->r17, ctx->r24);
    // 0x8005B174: lwl         $t8, 0x78($sp)
    ctx->r24 = do_lwl(rdram, ctx->r24, ctx->r29, 0X78);
    // 0x8005B178: lwr         $t8, 0x7B($sp)
    ctx->r24 = do_lwr(rdram, ctx->r24, ctx->r29, 0X7B);
    // 0x8005B17C: swl         $t8, 0x20($s1)
    do_swl(rdram, 0X20, ctx->r17, ctx->r24);
    // 0x8005B180: swr         $t8, 0x23($s1)
    do_swr(rdram, 0X23, ctx->r17, ctx->r24);
    // 0x8005B184: sh          $t0, 0xC($s1)
    MEM_H(0XC, ctx->r17) = ctx->r8;
    // 0x8005B188: sh          $t1, 0xE($s1)
    MEM_H(0XE, ctx->r17) = ctx->r9;
    // 0x8005B18C: sh          $t2, 0x10($s1)
    MEM_H(0X10, ctx->r17) = ctx->r10;
    // 0x8005B190: sh          $v0, 0x12($s1)
    MEM_H(0X12, ctx->r17) = ctx->r2;
L_8005B194:
    // 0x8005B194: lhu         $v0, 0x0($a1)
    ctx->r2 = MEM_HU(ctx->r5, 0X0);
    // 0x8005B198: lw          $t8, 0x90($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X90);
    // 0x8005B19C: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x8005B1A0: addu        $v0, $v0, $s7
    ctx->r2 = ADD32(ctx->r2, ctx->r23);
    // 0x8005B1A4: lh          $v1, 0x2($v0)
    ctx->r3 = MEM_H(ctx->r2, 0X2);
    // 0x8005B1A8: subu        $v0, $t8, $v1
    ctx->r2 = SUB32(ctx->r24, ctx->r3);
    // 0x8005B1AC: bltz        $v0, L_8005B1C4
    if (SIGNED(ctx->r2) < 0) {
        // 0x8005B1B0: slti        $v0, $v0, 0xA
        ctx->r2 = SIGNED(ctx->r2) < 0XA ? 1 : 0;
            goto L_8005B1C4;
    }
    // 0x8005B1B0: slti        $v0, $v0, 0xA
    ctx->r2 = SIGNED(ctx->r2) < 0XA ? 1 : 0;
    // 0x8005B1B4: bne         $v0, $zero, L_8005B1D8
    if (ctx->r2 != 0) {
        // 0x8005B1B8: nop
    
            goto L_8005B1D8;
    }
    // 0x8005B1B8: nop

    // 0x8005B1BC: j           L_8005B28C
    // 0x8005B1C0: addiu       $a1, $a1, 0x2
    ctx->r5 = ADD32(ctx->r5, 0X2);
        goto L_8005B28C;
    // 0x8005B1C0: addiu       $a1, $a1, 0x2
    ctx->r5 = ADD32(ctx->r5, 0X2);
L_8005B1C4:
    // 0x8005B1C4: lw          $t9, 0x90($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X90);
    // 0x8005B1C8: subu        $v0, $v1, $t9
    ctx->r2 = SUB32(ctx->r3, ctx->r25);
    // 0x8005B1CC: slti        $v0, $v0, 0xA
    ctx->r2 = SIGNED(ctx->r2) < 0XA ? 1 : 0;
    // 0x8005B1D0: beql        $v0, $zero, L_8005B28C
    if (ctx->r2 == 0) {
        // 0x8005B1D4: addiu       $a1, $a1, 0x2
        ctx->r5 = ADD32(ctx->r5, 0X2);
            goto L_8005B28C;
    }
    goto skip_4;
    // 0x8005B1D4: addiu       $a1, $a1, 0x2
    ctx->r5 = ADD32(ctx->r5, 0X2);
    skip_4:
L_8005B1D8:
    // 0x8005B1D8: lhu         $v0, 0x0($a1)
    ctx->r2 = MEM_HU(ctx->r5, 0X0);
    // 0x8005B1DC: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x8005B1E0: addu        $v0, $v0, $s7
    ctx->r2 = ADD32(ctx->r2, ctx->r23);
    // 0x8005B1E4: lwl         $t5, 0x0($v0)
    ctx->r13 = do_lwl(rdram, ctx->r13, ctx->r2, 0X0);
    // 0x8005B1E8: lwr         $t5, 0x3($v0)
    ctx->r13 = do_lwr(rdram, ctx->r13, ctx->r2, 0X3);
    // 0x8005B1EC: lwl         $t6, 0x4($v0)
    ctx->r14 = do_lwl(rdram, ctx->r14, ctx->r2, 0X4);
    // 0x8005B1F0: lwr         $t6, 0x7($v0)
    ctx->r14 = do_lwr(rdram, ctx->r14, ctx->r2, 0X7);
    // 0x8005B1F4: swl         $t5, -0x2($a0)
    do_swl(rdram, -0X2, ctx->r4, ctx->r13);
    // 0x8005B1F8: swr         $t5, 0x1($a0)
    do_swr(rdram, 0X1, ctx->r4, ctx->r13);
    // 0x8005B1FC: swl         $t6, 0x2($a0)
    do_swl(rdram, 0X2, ctx->r4, ctx->r14);
    // 0x8005B200: swr         $t6, 0x5($a0)
    do_swr(rdram, 0X5, ctx->r4, ctx->r14);
    // 0x8005B204: lwl         $t5, -0x2($a0)
    ctx->r13 = do_lwl(rdram, ctx->r13, ctx->r4, -0X2);
    // 0x8005B208: lwr         $t5, 0x1($a0)
    ctx->r13 = do_lwr(rdram, ctx->r13, ctx->r4, 0X1);
    // 0x8005B20C: lwl         $t6, 0x2($a0)
    ctx->r14 = do_lwl(rdram, ctx->r14, ctx->r4, 0X2);
    // 0x8005B210: lwr         $t6, 0x5($a0)
    ctx->r14 = do_lwr(rdram, ctx->r14, ctx->r4, 0X5);
    // 0x8005B214: swl         $t5, 0x0($a3)
    do_swl(rdram, 0X0, ctx->r7, ctx->r13);
    // 0x8005B218: swr         $t5, 0x3($a3)
    do_swr(rdram, 0X3, ctx->r7, ctx->r13);
    // 0x8005B21C: swl         $t6, 0x4($a3)
    do_swl(rdram, 0X4, ctx->r7, ctx->r14);
    // 0x8005B220: swr         $t6, 0x7($a3)
    do_swr(rdram, 0X7, ctx->r7, ctx->r14);
    // 0x8005B224: lhu         $v0, 0x2($a1)
    ctx->r2 = MEM_HU(ctx->r5, 0X2);
    // 0x8005B228: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x8005B22C: addu        $v0, $v0, $s7
    ctx->r2 = ADD32(ctx->r2, ctx->r23);
    // 0x8005B230: lwl         $t5, 0x0($v0)
    ctx->r13 = do_lwl(rdram, ctx->r13, ctx->r2, 0X0);
    // 0x8005B234: lwr         $t5, 0x3($v0)
    ctx->r13 = do_lwr(rdram, ctx->r13, ctx->r2, 0X3);
    // 0x8005B238: lwl         $t6, 0x4($v0)
    ctx->r14 = do_lwl(rdram, ctx->r14, ctx->r2, 0X4);
    // 0x8005B23C: lwr         $t6, 0x7($v0)
    ctx->r14 = do_lwr(rdram, ctx->r14, ctx->r2, 0X7);
    // 0x8005B240: swl         $t5, -0xA($a0)
    do_swl(rdram, -0XA, ctx->r4, ctx->r13);
    // 0x8005B244: swr         $t5, -0x7($a0)
    do_swr(rdram, -0X7, ctx->r4, ctx->r13);
    // 0x8005B248: swl         $t6, -0x6($a0)
    do_swl(rdram, -0X6, ctx->r4, ctx->r14);
    // 0x8005B24C: swr         $t6, -0x3($a0)
    do_swr(rdram, -0X3, ctx->r4, ctx->r14);
    // 0x8005B250: lwl         $t5, -0xA($a0)
    ctx->r13 = do_lwl(rdram, ctx->r13, ctx->r4, -0XA);
    // 0x8005B254: lwr         $t5, -0x7($a0)
    ctx->r13 = do_lwr(rdram, ctx->r13, ctx->r4, -0X7);
    // 0x8005B258: lwl         $t6, -0x6($a0)
    ctx->r14 = do_lwl(rdram, ctx->r14, ctx->r4, -0X6);
    // 0x8005B25C: lwr         $t6, -0x3($a0)
    ctx->r14 = do_lwr(rdram, ctx->r14, ctx->r4, -0X3);
    // 0x8005B260: swl         $t5, -0x12($a0)
    do_swl(rdram, -0X12, ctx->r4, ctx->r13);
    // 0x8005B264: swr         $t5, -0xF($a0)
    do_swr(rdram, -0XF, ctx->r4, ctx->r13);
    // 0x8005B268: swl         $t6, -0xE($a0)
    do_swl(rdram, -0XE, ctx->r4, ctx->r14);
    // 0x8005B26C: swr         $t6, -0xB($a0)
    do_swr(rdram, -0XB, ctx->r4, ctx->r14);
    // 0x8005B270: lhu         $v0, -0x8($a0)
    ctx->r2 = MEM_HU(ctx->r4, -0X8);
    // 0x8005B274: lhu         $v1, 0x0($a0)
    ctx->r3 = MEM_HU(ctx->r4, 0X0);
    // 0x8005B278: addu        $v0, $v0, $fp
    ctx->r2 = ADD32(ctx->r2, ctx->r30);
    // 0x8005B27C: addu        $v1, $v1, $fp
    ctx->r3 = ADD32(ctx->r3, ctx->r30);
    // 0x8005B280: sh          $v0, -0x8($a0)
    MEM_H(-0X8, ctx->r4) = ctx->r2;
    // 0x8005B284: j           L_8005B29C
    // 0x8005B288: sh          $v1, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r3;
        goto L_8005B29C;
    // 0x8005B288: sh          $v1, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r3;
L_8005B28C:
    // 0x8005B28C: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x8005B290: slti        $v0, $a2, 0x4
    ctx->r2 = SIGNED(ctx->r6) < 0X4 ? 1 : 0;
    // 0x8005B294: bne         $v0, $zero, L_8005B194
    if (ctx->r2 != 0) {
        // 0x8005B298: nop
    
            goto L_8005B194;
    }
    // 0x8005B298: nop

L_8005B29C:
    // 0x8005B29C: addiu       $a0, $a0, 0x20
    ctx->r4 = ADD32(ctx->r4, 0X20);
    // 0x8005B2A0: addiu       $a3, $a3, 0x20
    ctx->r7 = ADD32(ctx->r7, 0X20);
    // 0x8005B2A4: addiu       $t2, $t2, 0x4
    ctx->r10 = ADD32(ctx->r10, 0X4);
    // 0x8005B2A8: addiu       $t1, $t1, 0x4
    ctx->r9 = ADD32(ctx->r9, 0X4);
    // 0x8005B2AC: addiu       $t0, $t0, 0x4
    ctx->r8 = ADD32(ctx->r8, 0X4);
    // 0x8005B2B0: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8005B2B4: addiu       $t3, $t3, 0x24
    ctx->r11 = ADD32(ctx->r11, 0X24);
    // 0x8005B2B8: lw          $t5, 0xA4($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XA4);
    // 0x8005B2BC: lw          $t6, 0xA8($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XA8);
    // 0x8005B2C0: lw          $t8, 0x94($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X94);
    // 0x8005B2C4: addiu       $t5, $t5, 0x20
    ctx->r13 = ADD32(ctx->r13, 0X20);
    // 0x8005B2C8: addiu       $t6, $t6, 0x24
    ctx->r14 = ADD32(ctx->r14, 0X24);
    // 0x8005B2CC: sw          $t5, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->r13;
    // 0x8005B2D0: sw          $t6, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->r14;
    // 0x8005B2D4: lhu         $v0, 0x0($s6)
    ctx->r2 = MEM_HU(ctx->r22, 0X0);
    // 0x8005B2D8: addiu       $t8, $t8, 0x1
    ctx->r24 = ADD32(ctx->r24, 0X1);
    // 0x8005B2DC: slt         $v0, $s0, $v0
    ctx->r2 = SIGNED(ctx->r16) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8005B2E0: bne         $v0, $zero, L_8005B0DC
    if (ctx->r2 != 0) {
        // 0x8005B2E4: sw          $t8, 0x94($sp)
        MEM_W(0X94, ctx->r29) = ctx->r24;
            goto L_8005B0DC;
    }
    // 0x8005B2E4: sw          $t8, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->r24;
L_8005B2E8:
    // 0x8005B2E8: sll         $v0, $s0, 2
    ctx->r2 = S32(ctx->r16 << 2);
    // 0x8005B2EC: j           L_8005B314
    // 0x8005B2F0: sw          $v0, 0x30($s4)
    MEM_W(0X30, ctx->r20) = ctx->r2;
        goto L_8005B314;
    // 0x8005B2F0: sw          $v0, 0x30($s4)
    MEM_W(0X30, ctx->r20) = ctx->r2;
L_8005B2F4:
    // 0x8005B2F4: lw          $t9, 0xE0($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XE0);
    // 0x8005B2F8: lw          $t5, 0xA4($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XA4);
    // 0x8005B2FC: lw          $t6, 0xA8($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XA8);
    // 0x8005B300: sw          $zero, 0x5E8($s5)
    MEM_W(0X5E8, ctx->r21) = 0;
    // 0x8005B304: addu        $a3, $t9, $t5
    ctx->r7 = ADD32(ctx->r25, ctx->r13);
    // 0x8005B308: addu        $v0, $t9, $t6
    ctx->r2 = ADD32(ctx->r25, ctx->r14);
    // 0x8005B30C: sw          $v0, 0x5E4($s5)
    MEM_W(0X5E4, ctx->r21) = ctx->r2;
    // 0x8005B310: sw          $a3, 0x40($s4)
    MEM_W(0X40, ctx->r20) = ctx->r7;
L_8005B314:
    // 0x8005B314: addiu       $s4, $s4, 0x5C
    ctx->r20 = ADD32(ctx->r20, 0X5C);
L_8005B318:
    // 0x8005B318: addiu       $s5, $s5, 0x10
    ctx->r21 = ADD32(ctx->r21, 0X10);
    // 0x8005B31C: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x8005B320: slti        $v0, $s3, 0x10
    ctx->r2 = SIGNED(ctx->r19) < 0X10 ? 1 : 0;
    // 0x8005B324: lw          $t8, 0x98($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X98);
    // 0x8005B328: lw          $t9, 0x9C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X9C);
    // 0x8005B32C: lw          $t5, 0xA0($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XA0);
    // 0x8005B330: addiu       $t8, $t8, 0x2
    ctx->r24 = ADD32(ctx->r24, 0X2);
    // 0x8005B334: addiu       $t9, $t9, 0x4
    ctx->r25 = ADD32(ctx->r25, 0X4);
    // 0x8005B338: addiu       $t5, $t5, 0x5C
    ctx->r13 = ADD32(ctx->r13, 0X5C);
    // 0x8005B33C: sw          $t8, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->r24;
    // 0x8005B340: sw          $t9, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->r25;
    // 0x8005B344: bne         $v0, $zero, L_8005AF54
    if (ctx->r2 != 0) {
        // 0x8005B348: sw          $t5, 0xA0($sp)
        MEM_W(0XA0, ctx->r29) = ctx->r13;
            goto L_8005AF54;
    }
    // 0x8005B348: sw          $t5, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->r13;
    // 0x8005B34C: lw          $a0, 0x84($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X84);
    // 0x8005B350: jal         0x80001C98
    // 0x8005B354: addu        $s3, $zero, $zero
    ctx->r19 = ADD32(0, 0);
    rs_free(rdram, ctx);
        goto after_13;
    // 0x8005B354: addu        $s3, $zero, $zero
    ctx->r19 = ADD32(0, 0);
    after_13:
    // 0x8005B358: addiu       $s0, $sp, 0x10
    ctx->r16 = ADD32(ctx->r29, 0X10);
L_8005B35C:
    // 0x8005B35C: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x8005B360: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x8005B364: jal         0x80001C98
    // 0x8005B368: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    rs_free(rdram, ctx);
        goto after_14;
    // 0x8005B368: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    after_14:
    // 0x8005B36C: slti        $v0, $s3, 0x10
    ctx->r2 = SIGNED(ctx->r19) < 0X10 ? 1 : 0;
    // 0x8005B370: bne         $v0, $zero, L_8005B35C
    if (ctx->r2 != 0) {
        // 0x8005B374: nop
    
            goto L_8005B35C;
    }
    // 0x8005B374: nop

    // 0x8005B378: lw          $ra, 0xDC($sp)
    ctx->r31 = MEM_W(ctx->r29, 0XDC);
    // 0x8005B37C: lw          $fp, 0xD8($sp)
    ctx->r30 = MEM_W(ctx->r29, 0XD8);
    // 0x8005B380: lw          $s7, 0xD4($sp)
    ctx->r23 = MEM_W(ctx->r29, 0XD4);
    // 0x8005B384: lw          $s6, 0xD0($sp)
    ctx->r22 = MEM_W(ctx->r29, 0XD0);
    // 0x8005B388: lw          $s5, 0xCC($sp)
    ctx->r21 = MEM_W(ctx->r29, 0XCC);
    // 0x8005B38C: lw          $s4, 0xC8($sp)
    ctx->r20 = MEM_W(ctx->r29, 0XC8);
    // 0x8005B390: lw          $s3, 0xC4($sp)
    ctx->r19 = MEM_W(ctx->r29, 0XC4);
    // 0x8005B394: lw          $s2, 0xC0($sp)
    ctx->r18 = MEM_W(ctx->r29, 0XC0);
    // 0x8005B398: lw          $s1, 0xBC($sp)
    ctx->r17 = MEM_W(ctx->r29, 0XBC);
    // 0x8005B39C: lw          $s0, 0xB8($sp)
    ctx->r16 = MEM_W(ctx->r29, 0XB8);
    // 0x8005B3A0: jr          $ra
    // 0x8005B3A4: addiu       $sp, $sp, 0xE0
    ctx->r29 = ADD32(ctx->r29, 0XE0);
    return;
    // 0x8005B3A4: addiu       $sp, $sp, 0xE0
    ctx->r29 = ADD32(ctx->r29, 0XE0);
;}
RECOMP_FUNC void func_8005B3A8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005B3A8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8005B3AC: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x8005B3B0: addu        $s1, $a1, $zero
    ctx->r17 = ADD32(ctx->r5, 0);
    // 0x8005B3B4: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x8005B3B8: addiu       $s0, $s1, 0x1C
    ctx->r16 = ADD32(ctx->r17, 0X1C);
    // 0x8005B3BC: sw          $ra, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r31;
    // 0x8005B3C0: lwc1        $f4, 0x10($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X10);
    // 0x8005B3C4: abs.s       $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = fabsf(ctx->f4.fl);
    // 0x8005B3C8: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8005B3CC: lwc1        $f0, -0x51D4($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X51D4);
    // 0x8005B3D0: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x8005B3D4: nop

    // 0x8005B3D8: bc1f        L_8005B3E8
    if (!c1cs) {
        // 0x8005B3DC: addu        $a3, $zero, $zero
        ctx->r7 = ADD32(0, 0);
            goto L_8005B3E8;
    }
    // 0x8005B3DC: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    // 0x8005B3E0: j           L_8005B418
    // 0x8005B3E4: addiu       $a2, $zero, 0x7
    ctx->r6 = ADD32(0, 0X7);
        goto L_8005B418;
    // 0x8005B3E4: addiu       $a2, $zero, 0x7
    ctx->r6 = ADD32(0, 0X7);
L_8005B3E8:
    // 0x8005B3E8: lwc1        $f12, 0xC($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0XC);
    // 0x8005B3EC: lwc1        $f14, 0x14($a0)
    ctx->f14.u32l = MEM_W(ctx->r4, 0X14);
    // 0x8005B3F0: jal         0x8001C5F4
    // 0x8005B3F4: nop

    func_8001C5F4(rdram, ctx);
        goto after_0;
    // 0x8005B3F4: nop

    after_0:
    // 0x8005B3F8: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8005B3FC: lwc1        $f2, -0x51D0($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X51D0);
    // 0x8005B400: div.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f2.fl);
    // 0x8005B404: trunc.w.s   $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    ctx->f4.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x8005B408: mfc1        $v0, $f4
    ctx->r2 = (int32_t)ctx->f4.u32l;
    // 0x8005B40C: andi        $v0, $v0, 0x7
    ctx->r2 = ctx->r2 & 0X7;
    // 0x8005B410: addiu       $a3, $v0, -0x2
    ctx->r7 = ADD32(ctx->r2, -0X2);
    // 0x8005B414: addiu       $a2, $v0, 0x2
    ctx->r6 = ADD32(ctx->r2, 0X2);
L_8005B418:
    // 0x8005B418: slt         $v0, $a2, $a3
    ctx->r2 = SIGNED(ctx->r6) < SIGNED(ctx->r7) ? 1 : 0;
    // 0x8005B41C: bne         $v0, $zero, L_8005B4E0
    if (ctx->r2 != 0) {
        // 0x8005B420: addu        $a1, $a3, $zero
        ctx->r5 = ADD32(ctx->r7, 0);
            goto L_8005B4E0;
    }
    // 0x8005B420: addu        $a1, $a3, $zero
    ctx->r5 = ADD32(ctx->r7, 0);
    // 0x8005B424: andi        $v1, $a1, 0x7
    ctx->r3 = ctx->r5 & 0X7;
L_8005B428:
    // 0x8005B428: sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3 << 1);
    // 0x8005B42C: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8005B430: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x8005B434: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x8005B438: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8005B43C: beq         $a1, $a3, L_8005B470
    if (ctx->r5 == ctx->r7) {
        // 0x8005B440: addu        $a0, $v0, $s0
        ctx->r4 = ADD32(ctx->r2, ctx->r16);
            goto L_8005B470;
    }
    // 0x8005B440: addu        $a0, $v0, $s0
    ctx->r4 = ADD32(ctx->r2, ctx->r16);
    // 0x8005B444: addiu       $v1, $a1, -0x1
    ctx->r3 = ADD32(ctx->r5, -0X1);
    // 0x8005B448: andi        $v1, $v1, 0x7
    ctx->r3 = ctx->r3 & 0X7;
    // 0x8005B44C: sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3 << 1);
    // 0x8005B450: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8005B454: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x8005B458: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x8005B45C: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8005B460: addiu       $v0, $v0, 0x2E0
    ctx->r2 = ADD32(ctx->r2, 0X2E0);
    // 0x8005B464: addu        $v0, $s0, $v0
    ctx->r2 = ADD32(ctx->r16, ctx->r2);
    // 0x8005B468: j           L_8005B474
    // 0x8005B46C: sw          $v0, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r2;
        goto L_8005B474;
    // 0x8005B46C: sw          $v0, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r2;
L_8005B470:
    // 0x8005B470: sw          $zero, 0x4($a0)
    MEM_W(0X4, ctx->r4) = 0;
L_8005B474:
    // 0x8005B474: andi        $v1, $a1, 0x7
    ctx->r3 = ctx->r5 & 0X7;
    // 0x8005B478: sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3 << 1);
    // 0x8005B47C: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8005B480: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x8005B484: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x8005B488: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8005B48C: addu        $a0, $v0, $s0
    ctx->r4 = ADD32(ctx->r2, ctx->r16);
    // 0x8005B490: addiu       $v0, $v0, 0x2E0
    ctx->r2 = ADD32(ctx->r2, 0X2E0);
    // 0x8005B494: addu        $v0, $s0, $v0
    ctx->r2 = ADD32(ctx->r16, ctx->r2);
    // 0x8005B498: sw          $v0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r2;
    // 0x8005B49C: beq         $a1, $a2, L_8005B4CC
    if (ctx->r5 == ctx->r6) {
        // 0x8005B4A0: sw          $a0, 0x2E4($a0)
        MEM_W(0X2E4, ctx->r4) = ctx->r4;
            goto L_8005B4CC;
    }
    // 0x8005B4A0: sw          $a0, 0x2E4($a0)
    MEM_W(0X2E4, ctx->r4) = ctx->r4;
    // 0x8005B4A4: addiu       $v1, $a1, 0x1
    ctx->r3 = ADD32(ctx->r5, 0X1);
    // 0x8005B4A8: andi        $v1, $v1, 0x7
    ctx->r3 = ctx->r3 & 0X7;
    // 0x8005B4AC: sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3 << 1);
    // 0x8005B4B0: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8005B4B4: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x8005B4B8: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x8005B4BC: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8005B4C0: addu        $v0, $s0, $v0
    ctx->r2 = ADD32(ctx->r16, ctx->r2);
    // 0x8005B4C4: j           L_8005B4D0
    // 0x8005B4C8: sw          $v0, 0x2E0($a0)
    MEM_W(0X2E0, ctx->r4) = ctx->r2;
        goto L_8005B4D0;
    // 0x8005B4C8: sw          $v0, 0x2E0($a0)
    MEM_W(0X2E0, ctx->r4) = ctx->r2;
L_8005B4CC:
    // 0x8005B4CC: sw          $zero, 0x2E0($a0)
    MEM_W(0X2E0, ctx->r4) = 0;
L_8005B4D0:
    // 0x8005B4D0: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x8005B4D4: slt         $v0, $a2, $a1
    ctx->r2 = SIGNED(ctx->r6) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x8005B4D8: beq         $v0, $zero, L_8005B428
    if (ctx->r2 == 0) {
        // 0x8005B4DC: andi        $v1, $a1, 0x7
        ctx->r3 = ctx->r5 & 0X7;
            goto L_8005B428;
    }
    // 0x8005B4DC: andi        $v1, $a1, 0x7
    ctx->r3 = ctx->r5 & 0X7;
L_8005B4E0:
    // 0x8005B4E0: andi        $v0, $a3, 0x7
    ctx->r2 = ctx->r7 & 0X7;
    // 0x8005B4E4: sll         $v1, $v0, 1
    ctx->r3 = S32(ctx->r2 << 1);
    // 0x8005B4E8: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x8005B4EC: sll         $v1, $v1, 3
    ctx->r3 = S32(ctx->r3 << 3);
    // 0x8005B4F0: subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // 0x8005B4F4: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x8005B4F8: addiu       $v1, $v1, 0x1C
    ctx->r3 = ADD32(ctx->r3, 0X1C);
    // 0x8005B4FC: lw          $v0, 0x18($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X18);
    // 0x8005B500: addu        $v1, $s1, $v1
    ctx->r3 = ADD32(ctx->r17, ctx->r3);
    // 0x8005B504: sw          $v1, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->r3;
    // 0x8005B508: lw          $ra, 0x18($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X18);
    // 0x8005B50C: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x8005B510: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x8005B514: jr          $ra
    // 0x8005B518: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x8005B518: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_8005B51C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005B51C: addiu       $sp, $sp, -0xD0
    ctx->r29 = ADD32(ctx->r29, -0XD0);
    // 0x8005B520: sw          $s6, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->r22;
    // 0x8005B524: addu        $s6, $a0, $zero
    ctx->r22 = ADD32(ctx->r4, 0);
    // 0x8005B528: sw          $s5, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->r21;
    // 0x8005B52C: addu        $s5, $a1, $zero
    ctx->r21 = ADD32(ctx->r5, 0);
    // 0x8005B530: sw          $s0, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->r16;
    // 0x8005B534: sw          $ra, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->r31;
    // 0x8005B538: sw          $fp, 0xB8($sp)
    MEM_W(0XB8, ctx->r29) = ctx->r30;
    // 0x8005B53C: sw          $s7, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->r23;
    // 0x8005B540: sw          $s4, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->r20;
    // 0x8005B544: sw          $s3, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->r19;
    // 0x8005B548: sw          $s2, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->r18;
    // 0x8005B54C: sw          $s1, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->r17;
    // 0x8005B550: sdc1        $f22, 0xC8($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0XC8, ctx->r29);
    // 0x8005B554: sdc1        $f20, 0xC0($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0XC0, ctx->r29);
    // 0x8005B558: jal         0x8006B3E0
    // 0x8005B55C: addu        $s0, $a2, $zero
    ctx->r16 = ADD32(ctx->r6, 0);
    func_8006B3E0(rdram, ctx);
        goto after_0;
    // 0x8005B55C: addu        $s0, $a2, $zero
    ctx->r16 = ADD32(ctx->r6, 0);
    after_0:
    // 0x8005B560: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x8005B564: lui         $v1, 0x8888
    ctx->r3 = S32(0X8888 << 16);
    // 0x8005B568: ori         $v1, $v1, 0x8889
    ctx->r3 = ctx->r3 | 0X8889;
    // 0x8005B56C: multu       $v0, $v1
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8005B570: mfhi        $t4
    ctx->r12 = hi;
    // 0x8005B574: srl         $v0, $t4, 4
    ctx->r2 = S32(U32(ctx->r12) >> 4);
    // 0x8005B578: jal         0x8006B3D0
    // 0x8005B57C: andi        $s2, $v0, 0xFFFF
    ctx->r18 = ctx->r2 & 0XFFFF;
    func_8006B3D0(rdram, ctx);
        goto after_1;
    // 0x8005B57C: andi        $s2, $v0, 0xFFFF
    ctx->r18 = ctx->r2 & 0XFFFF;
    after_1:
    // 0x8005B580: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x8005B584: lui         $v1, 0xCCCC
    ctx->r3 = S32(0XCCCC << 16);
    // 0x8005B588: ori         $v1, $v1, 0xCCCD
    ctx->r3 = ctx->r3 | 0XCCCD;
    // 0x8005B58C: multu       $v0, $v1
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8005B590: lwc1        $f2, 0x14($s5)
    ctx->f2.u32l = MEM_W(ctx->r21, 0X14);
    // 0x8005B594: mul.s       $f2, $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x8005B598: lwc1        $f0, 0x10($s5)
    ctx->f0.u32l = MEM_W(ctx->r21, 0X10);
    // 0x8005B59C: mul.s       $f0, $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x8005B5A0: mfhi        $t4
    ctx->r12 = hi;
    // 0x8005B5A4: srl         $v0, $t4, 4
    ctx->r2 = S32(U32(ctx->r12) >> 4);
    // 0x8005B5A8: andi        $s7, $v0, 0xFFFF
    ctx->r23 = ctx->r2 & 0XFFFF;
    // 0x8005B5AC: add.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x8005B5B0: sqrt.s      $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = sqrtf(ctx->f2.fl);
    // 0x8005B5B4: lwc1        $f0, 0x4($s5)
    ctx->f0.u32l = MEM_W(ctx->r21, 0X4);
    // 0x8005B5B8: mul.s       $f22, $f2, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f22.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x8005B5BC: lwc1        $f4, 0xC($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8005B5C0: mul.s       $f0, $f4, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = MUL_S(ctx->f4.fl, ctx->f4.fl);
    // 0x8005B5C4: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x8005B5C8: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x8005B5CC: lwc1        $f6, 0x14($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X14);
    // 0x8005B5D0: mul.s       $f2, $f6, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = MUL_S(ctx->f6.fl, ctx->f6.fl);
    // 0x8005B5D4: swc1        $f6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f6.u32l;
    // 0x8005B5D8: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x8005B5DC: sqrt.s      $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f20.fl = sqrtf(ctx->f0.fl);
    // 0x8005B5E0: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8005B5E4: lwc1        $f0, -0x51CC($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X51CC);
    // 0x8005B5E8: c.lt.s      $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f20.fl < ctx->f0.fl;
    // 0x8005B5EC: nop

    // 0x8005B5F0: bc1t        L_8005BC8C
    if (c1cs) {
        // 0x8005B5F4: nop
    
            goto L_8005BC8C;
    }
    // 0x8005B5F4: nop

    // 0x8005B5F8: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    // 0x8005B5FC: div.s       $f0, $f4, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = DIV_S(ctx->f4.fl, ctx->f20.fl);
    // 0x8005B600: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    // 0x8005B604: lwc1        $f0, 0x10($s5)
    ctx->f0.u32l = MEM_W(ctx->r21, 0X10);
    // 0x8005B608: lwc1        $f4, 0x14($s5)
    ctx->f4.u32l = MEM_W(ctx->r21, 0X14);
    // 0x8005B60C: div.s       $f2, $f6, $f20
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f2.fl = DIV_S(ctx->f6.fl, ctx->f20.fl);
    // 0x8005B610: swc1        $f2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f2.u32l;
    // 0x8005B614: div.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f4.fl);
    // 0x8005B618: div.s       $f0, $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f20.fl);
    // 0x8005B61C: jal         0x8001CF58
    // 0x8005B620: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    normalize_vector(rdram, ctx);
        goto after_2;
    // 0x8005B620: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    after_2:
    // 0x8005B624: lwc1        $f4, 0x10($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X10);
    // 0x8005B628: mul.s       $f4, $f4, $f22
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f4.fl = MUL_S(ctx->f4.fl, ctx->f22.fl);
    // 0x8005B62C: lwc1        $f2, 0x14($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X14);
    // 0x8005B630: mul.s       $f2, $f2, $f22
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f22.fl);
    // 0x8005B634: lwc1        $f0, 0x18($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X18);
    // 0x8005B638: mul.s       $f0, $f0, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f22.fl);
    // 0x8005B63C: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x8005B640: swc1        $f2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f2.u32l;
    // 0x8005B644: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    // 0x8005B648: lw          $v0, 0x0($s6)
    ctx->r2 = MEM_W(ctx->r22, 0X0);
    // 0x8005B64C: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8005B650: lwc1        $f0, -0x51C8($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X51C8);
    // 0x8005B654: lwc1        $f2, 0x20($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X20);
    // 0x8005B658: addu        $s1, $zero, $zero
    ctx->r17 = ADD32(0, 0);
    // 0x8005B65C: mul.s       $f22, $f2, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f22.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x8005B660: addiu       $s3, $sp, 0x40
    ctx->r19 = ADD32(ctx->r29, 0X40);
    // 0x8005B664: addiu       $fp, $zero, 0x2
    ctx->r30 = ADD32(0, 0X2);
    // 0x8005B668: addiu       $s4, $sp, 0x20
    ctx->r20 = ADD32(ctx->r29, 0X20);
    // 0x8005B66C: addiu       $s0, $sp, 0x70
    ctx->r16 = ADD32(ctx->r29, 0X70);
    // 0x8005B670: jal         0x8002B190
    // 0x8005B674: mov.s       $f12, $f22
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 22);
    ctx->f12.fl = ctx->f22.fl;
    cosf_recomp(rdram, ctx);
        goto after_3;
    // 0x8005B674: mov.s       $f12, $f22
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 22);
    ctx->f12.fl = ctx->f22.fl;
    after_3:
    // 0x8005B678: mov.s       $f12, $f22
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 22);
    ctx->f12.fl = ctx->f22.fl;
    // 0x8005B67C: jal         0x80033960
    // 0x8005B680: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    sinf_recomp(rdram, ctx);
        goto after_4;
    // 0x8005B680: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    after_4:
    // 0x8005B684: div.s       $f20, $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f20.fl = DIV_S(ctx->f20.fl, ctx->f0.fl);
L_8005B688:
    // 0x8005B688: beq         $s1, $zero, L_8005B6AC
    if (ctx->r17 == 0) {
        // 0x8005B68C: nop
    
            goto L_8005B6AC;
    }
    // 0x8005B68C: nop

    // 0x8005B690: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8005B694: bne         $s1, $fp, L_8005B6B4
    if (ctx->r17 != ctx->r30) {
        // 0x8005B698: nop
    
            goto L_8005B6B4;
    }
    // 0x8005B698: nop

    // 0x8005B69C: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8005B6A0: lwc1        $f0, -0x51C4($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X51C4);
    // 0x8005B6A4: j           L_8005B6B4
    // 0x8005B6A8: nop

        goto L_8005B6B4;
    // 0x8005B6A8: nop

L_8005B6AC:
    // 0x8005B6AC: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8005B6B0: lwc1        $f0, -0x51C0($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X51C0);
L_8005B6B4:
    // 0x8005B6B4: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8005B6B8: jal         0x8001CD6C
    // 0x8005B6BC: addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    func_8001CD6C(rdram, ctx);
        goto after_5;
    // 0x8005B6BC: addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    after_5:
    // 0x8005B6C0: lw          $v0, 0x18($s5)
    ctx->r2 = MEM_W(ctx->r21, 0X18);
    // 0x8005B6C4: lw          $a1, 0x4C($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X4C);
    // 0x8005B6C8: lw          $a2, 0x50($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X50);
    // 0x8005B6CC: lw          $a3, 0x54($v0)
    ctx->r7 = MEM_W(ctx->r2, 0X54);
    // 0x8005B6D0: jal         0x8001CA90
    // 0x8005B6D4: addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    func_8001CA90(rdram, ctx);
        goto after_6;
    // 0x8005B6D4: addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    after_6:
    // 0x8005B6D8: addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    // 0x8005B6DC: addiu       $a1, $sp, 0x10
    ctx->r5 = ADD32(ctx->r29, 0X10);
    // 0x8005B6E0: jal         0x800193E8
    // 0x8005B6E4: addu        $a2, $s4, $zero
    ctx->r6 = ADD32(ctx->r20, 0);
    func_800193E8(rdram, ctx);
        goto after_7;
    // 0x8005B6E4: addu        $a2, $s4, $zero
    ctx->r6 = ADD32(ctx->r20, 0);
    after_7:
    // 0x8005B6E8: addu        $a1, $s4, $zero
    ctx->r5 = ADD32(ctx->r20, 0);
    // 0x8005B6EC: lw          $a0, 0x0($s6)
    ctx->r4 = MEM_W(ctx->r22, 0X0);
    // 0x8005B6F0: addiu       $a2, $sp, 0x30
    ctx->r6 = ADD32(ctx->r29, 0X30);
    // 0x8005B6F4: jal         0x800193E8
    // 0x8005B6F8: addiu       $a0, $a0, 0x2C
    ctx->r4 = ADD32(ctx->r4, 0X2C);
    func_800193E8(rdram, ctx);
        goto after_8;
    // 0x8005B6F8: addiu       $a0, $a0, 0x2C
    ctx->r4 = ADD32(ctx->r4, 0X2C);
    after_8:
    // 0x8005B6FC: lwc1        $f0, 0x30($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X30);
    // 0x8005B700: mul.s       $f0, $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f20.fl);
    // 0x8005B704: lwc1        $f2, 0x38($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X38);
    // 0x8005B708: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8005B70C: lwc1        $f4, -0x51BC($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X51BC);
    // 0x8005B710: div.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f2.fl);
    // 0x8005B714: mul.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x8005B718: swc1        $f0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f0.u32l;
    // 0x8005B71C: lwc1        $f0, 0x34($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X34);
    // 0x8005B720: mul.s       $f0, $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f20.fl);
    // 0x8005B724: lwc1        $f2, 0x38($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X38);
    // 0x8005B728: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x8005B72C: div.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f2.fl);
    // 0x8005B730: swc1        $f0, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f0.u32l;
    // 0x8005B734: lwc1        $f0, 0x38($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X38);
    // 0x8005B738: slti        $v0, $s1, 0x3
    ctx->r2 = SIGNED(ctx->r17) < 0X3 ? 1 : 0;
    // 0x8005B73C: swc1        $f0, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f0.u32l;
    // 0x8005B740: bne         $v0, $zero, L_8005B688
    if (ctx->r2 != 0) {
        // 0x8005B744: addiu       $s0, $s0, 0xC
        ctx->r16 = ADD32(ctx->r16, 0XC);
            goto L_8005B688;
    }
    // 0x8005B744: addiu       $s0, $s0, 0xC
    ctx->r16 = ADD32(ctx->r16, 0XC);
    // 0x8005B748: lw          $a2, 0x0($s6)
    ctx->r6 = MEM_W(ctx->r22, 0X0);
    // 0x8005B74C: lwc1        $f14, 0x7C($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X7C);
    // 0x8005B750: lwc1        $f12, 0x80($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X80);
    // 0x8005B754: lw          $a1, 0x10($a2)
    ctx->r5 = MEM_W(ctx->r6, 0X10);
    // 0x8005B758: lw          $a0, 0x14($a2)
    ctx->r4 = MEM_W(ctx->r6, 0X14);
    // 0x8005B75C: srl         $v0, $a1, 31
    ctx->r2 = S32(U32(ctx->r5) >> 31);
    // 0x8005B760: addu        $v0, $a1, $v0
    ctx->r2 = ADD32(ctx->r5, ctx->r2);
    // 0x8005B764: sra         $v0, $v0, 1
    ctx->r2 = S32(SIGNED(ctx->r2) >> 1);
    // 0x8005B768: mtc1        $v0, $f4
    ctx->f4.u32l = ctx->r2;
    // 0x8005B76C: cvt.s.w     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8005B770: mul.s       $f6, $f4, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f14.fl);
    // 0x8005B774: srl         $v0, $a0, 31
    ctx->r2 = S32(U32(ctx->r4) >> 31);
    // 0x8005B778: addu        $v0, $a0, $v0
    ctx->r2 = ADD32(ctx->r4, ctx->r2);
    // 0x8005B77C: sra         $t1, $v0, 1
    ctx->r9 = S32(SIGNED(ctx->r2) >> 1);
    // 0x8005B780: mtc1        $t1, $f0
    ctx->f0.u32l = ctx->r9;
    // 0x8005B784: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x8005B788: mul.s       $f2, $f0, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f2.fl = MUL_S(ctx->f0.fl, ctx->f12.fl);
    // 0x8005B78C: lw          $v1, 0x14($s6)
    ctx->r3 = MEM_W(ctx->r22, 0X14);
    // 0x8005B790: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8005B794: add.s       $f4, $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8005B798: lw          $v1, 0x4($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X4);
    // 0x8005B79C: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x8005B7A0: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x8005B7A4: addu        $t2, $v1, $v0
    ctx->r10 = ADD32(ctx->r3, ctx->r2);
    // 0x8005B7A8: trunc.w.s   $f16, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    ctx->f16.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x8005B7AC: mfc1        $t0, $f16
    ctx->r8 = (int32_t)ctx->f16.u32l;
    // 0x8005B7B0: trunc.w.s   $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    ctx->f16.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x8005B7B4: mfc1        $t3, $f16
    ctx->r11 = (int32_t)ctx->f16.u32l;
    // 0x8005B7B8: lwc1        $f16, 0x3C($a2)
    ctx->f16.u32l = MEM_W(ctx->r6, 0X3C);
    // 0x8005B7BC: abs.s       $f2, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f2.fl = fabsf(ctx->f16.fl);
    // 0x8005B7C0: lwc1        $f16, 0x38($a2)
    ctx->f16.u32l = MEM_W(ctx->r6, 0X38);
    // 0x8005B7C4: abs.s       $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f0.fl = fabsf(ctx->f16.fl);
    // 0x8005B7C8: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x8005B7CC: nop

    // 0x8005B7D0: bc1f        L_8005BA48
    if (!c1cs) {
        // 0x8005B7D4: andi        $v0, $t0, 0x3
        ctx->r2 = ctx->r8 & 0X3;
            goto L_8005BA48;
    }
    // 0x8005B7D4: andi        $v0, $t0, 0x3
    ctx->r2 = ctx->r8 & 0X3;
    // 0x8005B7D8: beq         $v0, $zero, L_8005B7E4
    if (ctx->r2 == 0) {
        // 0x8005B7DC: addiu       $v0, $t0, 0x4
        ctx->r2 = ADD32(ctx->r8, 0X4);
            goto L_8005B7E4;
    }
    // 0x8005B7DC: addiu       $v0, $t0, 0x4
    ctx->r2 = ADD32(ctx->r8, 0X4);
    // 0x8005B7E0: andi        $t0, $v0, 0xFFFC
    ctx->r8 = ctx->r2 & 0XFFFC;
L_8005B7E4:
    // 0x8005B7E4: lwc1        $f0, 0x74($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X74);
    // 0x8005B7E8: sub.s       $f0, $f12, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f12.fl - ctx->f0.fl;
    // 0x8005B7EC: lwc1        $f10, 0x70($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X70);
    // 0x8005B7F0: sub.s       $f2, $f14, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = ctx->f14.fl - ctx->f10.fl;
    // 0x8005B7F4: mtc1        $t0, $f4
    ctx->f4.u32l = ctx->r8;
    // 0x8005B7F8: cvt.s.w     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8005B7FC: div.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f2.fl);
    // 0x8005B800: mul.s       $f4, $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x8005B804: lwc1        $f8, 0x88($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X88);
    // 0x8005B808: sub.s       $f6, $f8, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = ctx->f8.fl - ctx->f14.fl;
    // 0x8005B80C: lwc1        $f0, 0x8C($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X8C);
    // 0x8005B810: sub.s       $f0, $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f12.fl;
    // 0x8005B814: subu        $v0, $a1, $t0
    ctx->r2 = SUB32(ctx->r5, ctx->r8);
    // 0x8005B818: mtc1        $v0, $f2
    ctx->f2.u32l = ctx->r2;
    // 0x8005B81C: cvt.s.w     $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    ctx->f2.fl = CVT_S_W(ctx->f2.u32l);
    // 0x8005B820: div.s       $f0, $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f6.fl);
    // 0x8005B824: mul.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x8005B828: mtc1        $t3, $f0
    ctx->f0.u32l = ctx->r11;
    // 0x8005B82C: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x8005B830: sub.s       $f4, $f0, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f4.fl = ctx->f0.fl - ctx->f4.fl;
    // 0x8005B834: lw          $v0, 0x1C($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X1C);
    // 0x8005B838: c.lt.s      $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f10.fl < ctx->f8.fl;
    // 0x8005B83C: subu        $a2, $v0, $t1
    ctx->r6 = SUB32(ctx->r2, ctx->r9);
    // 0x8005B840: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x8005B844: trunc.w.s   $f16, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    ctx->f16.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x8005B848: mfc1        $a3, $f16
    ctx->r7 = (int32_t)ctx->f16.u32l;
    // 0x8005B84C: trunc.w.s   $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    ctx->f16.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x8005B850: mfc1        $a1, $f16
    ctx->r5 = (int32_t)ctx->f16.u32l;
    // 0x8005B854: bc1f        L_8005B954
    if (!c1cs) {
        // 0x8005B858: addu        $t1, $v0, $t1
        ctx->r9 = ADD32(ctx->r2, ctx->r9);
            goto L_8005B954;
    }
    // 0x8005B858: addu        $t1, $v0, $t1
    ctx->r9 = ADD32(ctx->r2, ctx->r9);
    // 0x8005B85C: subu        $t3, $t3, $s2
    ctx->r11 = SUB32(ctx->r11, ctx->r18);
    // 0x8005B860: slt         $v0, $t3, $a2
    ctx->r2 = SIGNED(ctx->r11) < SIGNED(ctx->r6) ? 1 : 0;
    // 0x8005B864: beq         $v0, $zero, L_8005B874
    if (ctx->r2 == 0) {
        // 0x8005B868: slt         $v0, $t3, $t1
        ctx->r2 = SIGNED(ctx->r11) < SIGNED(ctx->r9) ? 1 : 0;
            goto L_8005B874;
    }
    // 0x8005B868: slt         $v0, $t3, $t1
    ctx->r2 = SIGNED(ctx->r11) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x8005B86C: j           L_8005B87C
    // 0x8005B870: addu        $t3, $a2, $zero
    ctx->r11 = ADD32(ctx->r6, 0);
        goto L_8005B87C;
    // 0x8005B870: addu        $t3, $a2, $zero
    ctx->r11 = ADD32(ctx->r6, 0);
L_8005B874:
    // 0x8005B874: beql        $v0, $zero, L_8005B87C
    if (ctx->r2 == 0) {
        // 0x8005B878: addiu       $t3, $t1, -0x1
        ctx->r11 = ADD32(ctx->r9, -0X1);
            goto L_8005B87C;
    }
    goto skip_0;
    // 0x8005B878: addiu       $t3, $t1, -0x1
    ctx->r11 = ADD32(ctx->r9, -0X1);
    skip_0:
L_8005B87C:
    // 0x8005B87C: subu        $a1, $a1, $s2
    ctx->r5 = SUB32(ctx->r5, ctx->r18);
    // 0x8005B880: slt         $v0, $a1, $a2
    ctx->r2 = SIGNED(ctx->r5) < SIGNED(ctx->r6) ? 1 : 0;
    // 0x8005B884: beq         $v0, $zero, L_8005B894
    if (ctx->r2 == 0) {
        // 0x8005B888: slt         $v0, $a1, $t1
        ctx->r2 = SIGNED(ctx->r5) < SIGNED(ctx->r9) ? 1 : 0;
            goto L_8005B894;
    }
    // 0x8005B888: slt         $v0, $a1, $t1
    ctx->r2 = SIGNED(ctx->r5) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x8005B88C: j           L_8005B89C
    // 0x8005B890: addu        $a1, $a2, $zero
    ctx->r5 = ADD32(ctx->r6, 0);
        goto L_8005B89C;
    // 0x8005B890: addu        $a1, $a2, $zero
    ctx->r5 = ADD32(ctx->r6, 0);
L_8005B894:
    // 0x8005B894: beql        $v0, $zero, L_8005B89C
    if (ctx->r2 == 0) {
        // 0x8005B898: addiu       $a1, $t1, -0x1
        ctx->r5 = ADD32(ctx->r9, -0X1);
            goto L_8005B89C;
    }
    goto skip_1;
    // 0x8005B898: addiu       $a1, $t1, -0x1
    ctx->r5 = ADD32(ctx->r9, -0X1);
    skip_1:
L_8005B89C:
    // 0x8005B89C: subu        $a3, $a3, $s2
    ctx->r7 = SUB32(ctx->r7, ctx->r18);
    // 0x8005B8A0: slt         $v0, $a3, $a2
    ctx->r2 = SIGNED(ctx->r7) < SIGNED(ctx->r6) ? 1 : 0;
    // 0x8005B8A4: beq         $v0, $zero, L_8005B8B4
    if (ctx->r2 == 0) {
        // 0x8005B8A8: slt         $v0, $a3, $t1
        ctx->r2 = SIGNED(ctx->r7) < SIGNED(ctx->r9) ? 1 : 0;
            goto L_8005B8B4;
    }
    // 0x8005B8A8: slt         $v0, $a3, $t1
    ctx->r2 = SIGNED(ctx->r7) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x8005B8AC: j           L_8005B8BC
    // 0x8005B8B0: addu        $a3, $a2, $zero
    ctx->r7 = ADD32(ctx->r6, 0);
        goto L_8005B8BC;
    // 0x8005B8B0: addu        $a3, $a2, $zero
    ctx->r7 = ADD32(ctx->r6, 0);
L_8005B8B4:
    // 0x8005B8B4: beql        $v0, $zero, L_8005B8BC
    if (ctx->r2 == 0) {
        // 0x8005B8B8: addiu       $a3, $t1, -0x1
        ctx->r7 = ADD32(ctx->r9, -0X1);
            goto L_8005B8BC;
    }
    goto skip_2;
    // 0x8005B8B8: addiu       $a3, $t1, -0x1
    ctx->r7 = ADD32(ctx->r9, -0X1);
    skip_2:
L_8005B8BC:
    // 0x8005B8BC: lw          $v0, 0x0($s6)
    ctx->r2 = MEM_W(ctx->r22, 0X0);
    // 0x8005B8C0: lui         $a0, 0x6666
    ctx->r4 = S32(0X6666 << 16);
    // 0x8005B8C4: lw          $v1, 0x14($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X14);
    // 0x8005B8C8: ori         $a0, $a0, 0x6667
    ctx->r4 = ctx->r4 | 0X6667;
    // 0x8005B8CC: mult        $v1, $a0
    result = S64(S32(ctx->r3)) * S64(S32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8005B8D0: sra         $v1, $v1, 31
    ctx->r3 = S32(SIGNED(ctx->r3) >> 31);
    // 0x8005B8D4: mfhi        $t4
    ctx->r12 = hi;
    // 0x8005B8D8: sra         $v0, $t4, 2
    ctx->r2 = S32(SIGNED(ctx->r12) >> 2);
    // 0x8005B8DC: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x8005B8E0: subu        $s2, $t1, $v0
    ctx->r18 = SUB32(ctx->r9, ctx->r2);
    // 0x8005B8E4: slt         $v0, $s2, $a3
    ctx->r2 = SIGNED(ctx->r18) < SIGNED(ctx->r7) ? 1 : 0;
    // 0x8005B8E8: bnel        $v0, $zero, L_8005B8F0
    if (ctx->r2 != 0) {
        // 0x8005B8EC: addu        $a3, $s2, $zero
        ctx->r7 = ADD32(ctx->r18, 0);
            goto L_8005B8F0;
    }
    goto skip_3;
    // 0x8005B8EC: addu        $a3, $s2, $zero
    ctx->r7 = ADD32(ctx->r18, 0);
    skip_3:
L_8005B8F0:
    // 0x8005B8F0: slt         $v0, $s2, $a1
    ctx->r2 = SIGNED(ctx->r18) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x8005B8F4: bnel        $v0, $zero, L_8005B8FC
    if (ctx->r2 != 0) {
        // 0x8005B8F8: addu        $a1, $s2, $zero
        ctx->r5 = ADD32(ctx->r18, 0);
            goto L_8005B8FC;
    }
    goto skip_4;
    // 0x8005B8F8: addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    skip_4:
L_8005B8FC:
    // 0x8005B8FC: sh          $t0, 0x0($t2)
    MEM_H(0X0, ctx->r10) = ctx->r8;
    // 0x8005B900: lw          $v0, 0x0($s6)
    ctx->r2 = MEM_W(ctx->r22, 0X0);
    // 0x8005B904: lhu         $v0, 0x12($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X12);
    // 0x8005B908: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x8005B90C: sh          $v0, 0x4($t2)
    MEM_H(0X4, ctx->r10) = ctx->r2;
    // 0x8005B910: slt         $v0, $a1, $t3
    ctx->r2 = SIGNED(ctx->r5) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x8005B914: beq         $v0, $zero, L_8005B920
    if (ctx->r2 == 0) {
        // 0x8005B918: addu        $a0, $t3, $zero
        ctx->r4 = ADD32(ctx->r11, 0);
            goto L_8005B920;
    }
    // 0x8005B918: addu        $a0, $t3, $zero
    ctx->r4 = ADD32(ctx->r11, 0);
    // 0x8005B91C: addu        $a0, $a1, $zero
    ctx->r4 = ADD32(ctx->r5, 0);
L_8005B920:
    // 0x8005B920: addu        $v1, $t3, $zero
    ctx->r3 = ADD32(ctx->r11, 0);
    // 0x8005B924: sh          $a0, 0x2($t2)
    MEM_H(0X2, ctx->r10) = ctx->r4;
    // 0x8005B928: addiu       $a0, $t1, -0x1
    ctx->r4 = ADD32(ctx->r9, -0X1);
    // 0x8005B92C: addiu       $v0, $t0, -0x1
    ctx->r2 = ADD32(ctx->r8, -0X1);
    // 0x8005B930: sh          $v0, 0xC($t2)
    MEM_H(0XC, ctx->r10) = ctx->r2;
    // 0x8005B934: slt         $v0, $a3, $v1
    ctx->r2 = SIGNED(ctx->r7) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8005B938: sh          $a0, 0x6($t2)
    MEM_H(0X6, ctx->r10) = ctx->r4;
    // 0x8005B93C: beq         $v0, $zero, L_8005B948
    if (ctx->r2 == 0) {
        // 0x8005B940: sh          $zero, 0x8($t2)
        MEM_H(0X8, ctx->r10) = 0;
            goto L_8005B948;
    }
    // 0x8005B940: sh          $zero, 0x8($t2)
    MEM_H(0X8, ctx->r10) = 0;
    // 0x8005B944: addu        $v1, $a3, $zero
    ctx->r3 = ADD32(ctx->r7, 0);
L_8005B948:
    // 0x8005B948: sh          $v1, 0xA($t2)
    MEM_H(0XA, ctx->r10) = ctx->r3;
    // 0x8005B94C: j           L_8005BC7C
    // 0x8005B950: sh          $a0, 0xE($t2)
    MEM_H(0XE, ctx->r10) = ctx->r4;
        goto L_8005BC7C;
    // 0x8005B950: sh          $a0, 0xE($t2)
    MEM_H(0XE, ctx->r10) = ctx->r4;
L_8005B954:
    // 0x8005B954: addu        $t3, $t3, $s2
    ctx->r11 = ADD32(ctx->r11, ctx->r18);
    // 0x8005B958: slt         $v0, $t3, $a2
    ctx->r2 = SIGNED(ctx->r11) < SIGNED(ctx->r6) ? 1 : 0;
    // 0x8005B95C: beq         $v0, $zero, L_8005B96C
    if (ctx->r2 == 0) {
        // 0x8005B960: slt         $v0, $t3, $t1
        ctx->r2 = SIGNED(ctx->r11) < SIGNED(ctx->r9) ? 1 : 0;
            goto L_8005B96C;
    }
    // 0x8005B960: slt         $v0, $t3, $t1
    ctx->r2 = SIGNED(ctx->r11) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x8005B964: j           L_8005B974
    // 0x8005B968: addu        $t3, $a2, $zero
    ctx->r11 = ADD32(ctx->r6, 0);
        goto L_8005B974;
    // 0x8005B968: addu        $t3, $a2, $zero
    ctx->r11 = ADD32(ctx->r6, 0);
L_8005B96C:
    // 0x8005B96C: beql        $v0, $zero, L_8005B974
    if (ctx->r2 == 0) {
        // 0x8005B970: addiu       $t3, $t1, -0x1
        ctx->r11 = ADD32(ctx->r9, -0X1);
            goto L_8005B974;
    }
    goto skip_5;
    // 0x8005B970: addiu       $t3, $t1, -0x1
    ctx->r11 = ADD32(ctx->r9, -0X1);
    skip_5:
L_8005B974:
    // 0x8005B974: addu        $a1, $a1, $s2
    ctx->r5 = ADD32(ctx->r5, ctx->r18);
    // 0x8005B978: slt         $v0, $a1, $a2
    ctx->r2 = SIGNED(ctx->r5) < SIGNED(ctx->r6) ? 1 : 0;
    // 0x8005B97C: beq         $v0, $zero, L_8005B98C
    if (ctx->r2 == 0) {
        // 0x8005B980: slt         $v0, $a1, $t1
        ctx->r2 = SIGNED(ctx->r5) < SIGNED(ctx->r9) ? 1 : 0;
            goto L_8005B98C;
    }
    // 0x8005B980: slt         $v0, $a1, $t1
    ctx->r2 = SIGNED(ctx->r5) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x8005B984: j           L_8005B994
    // 0x8005B988: addu        $a1, $a2, $zero
    ctx->r5 = ADD32(ctx->r6, 0);
        goto L_8005B994;
    // 0x8005B988: addu        $a1, $a2, $zero
    ctx->r5 = ADD32(ctx->r6, 0);
L_8005B98C:
    // 0x8005B98C: beql        $v0, $zero, L_8005B994
    if (ctx->r2 == 0) {
        // 0x8005B990: addiu       $a1, $t1, -0x1
        ctx->r5 = ADD32(ctx->r9, -0X1);
            goto L_8005B994;
    }
    goto skip_6;
    // 0x8005B990: addiu       $a1, $t1, -0x1
    ctx->r5 = ADD32(ctx->r9, -0X1);
    skip_6:
L_8005B994:
    // 0x8005B994: addu        $a3, $a3, $s2
    ctx->r7 = ADD32(ctx->r7, ctx->r18);
    // 0x8005B998: slt         $v0, $a3, $a2
    ctx->r2 = SIGNED(ctx->r7) < SIGNED(ctx->r6) ? 1 : 0;
    // 0x8005B99C: beq         $v0, $zero, L_8005B9AC
    if (ctx->r2 == 0) {
        // 0x8005B9A0: slt         $v0, $a3, $t1
        ctx->r2 = SIGNED(ctx->r7) < SIGNED(ctx->r9) ? 1 : 0;
            goto L_8005B9AC;
    }
    // 0x8005B9A0: slt         $v0, $a3, $t1
    ctx->r2 = SIGNED(ctx->r7) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x8005B9A4: j           L_8005B9B4
    // 0x8005B9A8: addu        $a3, $a2, $zero
    ctx->r7 = ADD32(ctx->r6, 0);
        goto L_8005B9B4;
    // 0x8005B9A8: addu        $a3, $a2, $zero
    ctx->r7 = ADD32(ctx->r6, 0);
L_8005B9AC:
    // 0x8005B9AC: beql        $v0, $zero, L_8005B9B4
    if (ctx->r2 == 0) {
        // 0x8005B9B0: addiu       $a3, $t1, -0x1
        ctx->r7 = ADD32(ctx->r9, -0X1);
            goto L_8005B9B4;
    }
    goto skip_7;
    // 0x8005B9B0: addiu       $a3, $t1, -0x1
    ctx->r7 = ADD32(ctx->r9, -0X1);
    skip_7:
L_8005B9B4:
    // 0x8005B9B4: lw          $v0, 0x0($s6)
    ctx->r2 = MEM_W(ctx->r22, 0X0);
    // 0x8005B9B8: lui         $a0, 0x6666
    ctx->r4 = S32(0X6666 << 16);
    // 0x8005B9BC: lw          $v1, 0x14($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X14);
    // 0x8005B9C0: ori         $a0, $a0, 0x6667
    ctx->r4 = ctx->r4 | 0X6667;
    // 0x8005B9C4: mult        $v1, $a0
    result = S64(S32(ctx->r3)) * S64(S32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8005B9C8: sra         $v1, $v1, 31
    ctx->r3 = S32(SIGNED(ctx->r3) >> 31);
    // 0x8005B9CC: mfhi        $t4
    ctx->r12 = hi;
    // 0x8005B9D0: sra         $v0, $t4, 2
    ctx->r2 = S32(SIGNED(ctx->r12) >> 2);
    // 0x8005B9D4: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x8005B9D8: addu        $s2, $a2, $v0
    ctx->r18 = ADD32(ctx->r6, ctx->r2);
    // 0x8005B9DC: slt         $v0, $a3, $s2
    ctx->r2 = SIGNED(ctx->r7) < SIGNED(ctx->r18) ? 1 : 0;
    // 0x8005B9E0: bnel        $v0, $zero, L_8005B9E8
    if (ctx->r2 != 0) {
        // 0x8005B9E4: addu        $a3, $s2, $zero
        ctx->r7 = ADD32(ctx->r18, 0);
            goto L_8005B9E8;
    }
    goto skip_8;
    // 0x8005B9E4: addu        $a3, $s2, $zero
    ctx->r7 = ADD32(ctx->r18, 0);
    skip_8:
L_8005B9E8:
    // 0x8005B9E8: slt         $v0, $a1, $s2
    ctx->r2 = SIGNED(ctx->r5) < SIGNED(ctx->r18) ? 1 : 0;
    // 0x8005B9EC: bnel        $v0, $zero, L_8005B9F4
    if (ctx->r2 != 0) {
        // 0x8005B9F0: addu        $a1, $s2, $zero
        ctx->r5 = ADD32(ctx->r18, 0);
            goto L_8005B9F4;
    }
    goto skip_9;
    // 0x8005B9F0: addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    skip_9:
L_8005B9F4:
    // 0x8005B9F4: sh          $t0, 0x0($t2)
    MEM_H(0X0, ctx->r10) = ctx->r8;
    // 0x8005B9F8: lw          $v0, 0x0($s6)
    ctx->r2 = MEM_W(ctx->r22, 0X0);
    // 0x8005B9FC: lhu         $v0, 0x12($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X12);
    // 0x8005BA00: sh          $a2, 0x2($t2)
    MEM_H(0X2, ctx->r10) = ctx->r6;
    // 0x8005BA04: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x8005BA08: sh          $v0, 0x4($t2)
    MEM_H(0X4, ctx->r10) = ctx->r2;
    // 0x8005BA0C: slt         $v0, $t3, $a1
    ctx->r2 = SIGNED(ctx->r11) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x8005BA10: beq         $v0, $zero, L_8005BA1C
    if (ctx->r2 == 0) {
        // 0x8005BA14: addu        $a0, $t3, $zero
        ctx->r4 = ADD32(ctx->r11, 0);
            goto L_8005BA1C;
    }
    // 0x8005BA14: addu        $a0, $t3, $zero
    ctx->r4 = ADD32(ctx->r11, 0);
    // 0x8005BA18: addu        $a0, $a1, $zero
    ctx->r4 = ADD32(ctx->r5, 0);
L_8005BA1C:
    // 0x8005BA1C: addu        $v1, $t3, $zero
    ctx->r3 = ADD32(ctx->r11, 0);
    // 0x8005BA20: addiu       $v0, $t0, -0x1
    ctx->r2 = ADD32(ctx->r8, -0X1);
    // 0x8005BA24: sh          $v0, 0xC($t2)
    MEM_H(0XC, ctx->r10) = ctx->r2;
    // 0x8005BA28: slt         $v0, $v1, $a3
    ctx->r2 = SIGNED(ctx->r3) < SIGNED(ctx->r7) ? 1 : 0;
    // 0x8005BA2C: sh          $a0, 0x6($t2)
    MEM_H(0X6, ctx->r10) = ctx->r4;
    // 0x8005BA30: sh          $zero, 0x8($t2)
    MEM_H(0X8, ctx->r10) = 0;
    // 0x8005BA34: beq         $v0, $zero, L_8005BA40
    if (ctx->r2 == 0) {
        // 0x8005BA38: sh          $a2, 0xA($t2)
        MEM_H(0XA, ctx->r10) = ctx->r6;
            goto L_8005BA40;
    }
    // 0x8005BA38: sh          $a2, 0xA($t2)
    MEM_H(0XA, ctx->r10) = ctx->r6;
    // 0x8005BA3C: addu        $v1, $a3, $zero
    ctx->r3 = ADD32(ctx->r7, 0);
L_8005BA40:
    // 0x8005BA40: j           L_8005BC7C
    // 0x8005BA44: sh          $v1, 0xE($t2)
    MEM_H(0XE, ctx->r10) = ctx->r3;
        goto L_8005BC7C;
    // 0x8005BA44: sh          $v1, 0xE($t2)
    MEM_H(0XE, ctx->r10) = ctx->r3;
L_8005BA48:
    // 0x8005BA48: lwc1        $f0, 0x70($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X70);
    // 0x8005BA4C: sub.s       $f0, $f14, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f14.fl - ctx->f0.fl;
    // 0x8005BA50: lwc1        $f10, 0x74($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X74);
    // 0x8005BA54: sub.s       $f2, $f12, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = ctx->f12.fl - ctx->f10.fl;
    // 0x8005BA58: mtc1        $t3, $f4
    ctx->f4.u32l = ctx->r11;
    // 0x8005BA5C: cvt.s.w     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8005BA60: div.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f2.fl);
    // 0x8005BA64: mul.s       $f4, $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x8005BA68: lwc1        $f8, 0x8C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X8C);
    // 0x8005BA6C: sub.s       $f6, $f8, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = ctx->f8.fl - ctx->f12.fl;
    // 0x8005BA70: lwc1        $f0, 0x88($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X88);
    // 0x8005BA74: sub.s       $f0, $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f14.fl;
    // 0x8005BA78: subu        $v0, $a0, $t3
    ctx->r2 = SUB32(ctx->r4, ctx->r11);
    // 0x8005BA7C: mtc1        $v0, $f2
    ctx->f2.u32l = ctx->r2;
    // 0x8005BA80: cvt.s.w     $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    ctx->f2.fl = CVT_S_W(ctx->f2.u32l);
    // 0x8005BA84: div.s       $f0, $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f6.fl);
    // 0x8005BA88: mul.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x8005BA8C: mtc1        $t0, $f0
    ctx->f0.u32l = ctx->r8;
    // 0x8005BA90: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x8005BA94: sub.s       $f4, $f0, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f4.fl = ctx->f0.fl - ctx->f4.fl;
    // 0x8005BA98: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x8005BA9C: c.lt.s      $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f10.fl < ctx->f8.fl;
    // 0x8005BAA0: trunc.w.s   $f16, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    ctx->f16.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x8005BAA4: mfc1        $v1, $f16
    ctx->r3 = (int32_t)ctx->f16.u32l;
    // 0x8005BAA8: trunc.w.s   $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    ctx->f16.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x8005BAAC: mfc1        $a0, $f16
    ctx->r4 = (int32_t)ctx->f16.u32l;
    // 0x8005BAB0: bc1fl       L_8005BBA0
    if (!c1cs) {
        // 0x8005BAB4: subu        $t0, $t0, $s2
        ctx->r8 = SUB32(ctx->r8, ctx->r18);
            goto L_8005BBA0;
    }
    goto skip_10;
    // 0x8005BAB4: subu        $t0, $t0, $s2
    ctx->r8 = SUB32(ctx->r8, ctx->r18);
    skip_10:
    // 0x8005BAB8: addu        $t0, $t0, $s2
    ctx->r8 = ADD32(ctx->r8, ctx->r18);
    // 0x8005BABC: bgez        $t0, L_8005BACC
    if (SIGNED(ctx->r8) >= 0) {
        // 0x8005BAC0: slt         $v0, $t0, $a1
        ctx->r2 = SIGNED(ctx->r8) < SIGNED(ctx->r5) ? 1 : 0;
            goto L_8005BACC;
    }
    // 0x8005BAC0: slt         $v0, $t0, $a1
    ctx->r2 = SIGNED(ctx->r8) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x8005BAC4: j           L_8005BAD4
    // 0x8005BAC8: addu        $t0, $zero, $zero
    ctx->r8 = ADD32(0, 0);
        goto L_8005BAD4;
    // 0x8005BAC8: addu        $t0, $zero, $zero
    ctx->r8 = ADD32(0, 0);
L_8005BACC:
    // 0x8005BACC: beql        $v0, $zero, L_8005BAD4
    if (ctx->r2 == 0) {
        // 0x8005BAD0: addiu       $t0, $a1, -0x1
        ctx->r8 = ADD32(ctx->r5, -0X1);
            goto L_8005BAD4;
    }
    goto skip_11;
    // 0x8005BAD0: addiu       $t0, $a1, -0x1
    ctx->r8 = ADD32(ctx->r5, -0X1);
    skip_11:
L_8005BAD4:
    // 0x8005BAD4: addu        $v1, $v1, $s7
    ctx->r3 = ADD32(ctx->r3, ctx->r23);
    // 0x8005BAD8: bgez        $v1, L_8005BAE8
    if (SIGNED(ctx->r3) >= 0) {
        // 0x8005BADC: nop
    
            goto L_8005BAE8;
    }
    // 0x8005BADC: nop

    // 0x8005BAE0: j           L_8005BAFC
    // 0x8005BAE4: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
        goto L_8005BAFC;
    // 0x8005BAE4: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
L_8005BAE8:
    // 0x8005BAE8: lw          $v0, 0x0($s6)
    ctx->r2 = MEM_W(ctx->r22, 0X0);
    // 0x8005BAEC: lw          $a1, 0x10($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X10);
    // 0x8005BAF0: slt         $v0, $v1, $a1
    ctx->r2 = SIGNED(ctx->r3) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x8005BAF4: beql        $v0, $zero, L_8005BAFC
    if (ctx->r2 == 0) {
        // 0x8005BAF8: addiu       $v1, $a1, -0x1
        ctx->r3 = ADD32(ctx->r5, -0X1);
            goto L_8005BAFC;
    }
    goto skip_12;
    // 0x8005BAF8: addiu       $v1, $a1, -0x1
    ctx->r3 = ADD32(ctx->r5, -0X1);
    skip_12:
L_8005BAFC:
    // 0x8005BAFC: addu        $a0, $a0, $s7
    ctx->r4 = ADD32(ctx->r4, ctx->r23);
    // 0x8005BB00: bgez        $a0, L_8005BB10
    if (SIGNED(ctx->r4) >= 0) {
        // 0x8005BB04: nop
    
            goto L_8005BB10;
    }
    // 0x8005BB04: nop

    // 0x8005BB08: j           L_8005BB24
    // 0x8005BB0C: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
        goto L_8005BB24;
    // 0x8005BB0C: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
L_8005BB10:
    // 0x8005BB10: lw          $v0, 0x0($s6)
    ctx->r2 = MEM_W(ctx->r22, 0X0);
    // 0x8005BB14: lw          $a1, 0x10($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X10);
    // 0x8005BB18: slt         $v0, $a0, $a1
    ctx->r2 = SIGNED(ctx->r4) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x8005BB1C: beql        $v0, $zero, L_8005BB24
    if (ctx->r2 == 0) {
        // 0x8005BB20: addiu       $a0, $a1, -0x1
        ctx->r4 = ADD32(ctx->r5, -0X1);
            goto L_8005BB24;
    }
    goto skip_13;
    // 0x8005BB20: addiu       $a0, $a1, -0x1
    ctx->r4 = ADD32(ctx->r5, -0X1);
    skip_13:
L_8005BB24:
    // 0x8005BB24: andi        $v0, $t0, 0x3
    ctx->r2 = ctx->r8 & 0X3;
    // 0x8005BB28: beq         $v0, $zero, L_8005BB34
    if (ctx->r2 == 0) {
        // 0x8005BB2C: addiu       $v0, $t0, 0x4
        ctx->r2 = ADD32(ctx->r8, 0X4);
            goto L_8005BB34;
    }
    // 0x8005BB2C: addiu       $v0, $t0, 0x4
    ctx->r2 = ADD32(ctx->r8, 0X4);
    // 0x8005BB30: andi        $t0, $v0, 0xFFFC
    ctx->r8 = ctx->r2 & 0XFFFC;
L_8005BB34:
    // 0x8005BB34: andi        $v0, $v1, 0x3
    ctx->r2 = ctx->r3 & 0X3;
    // 0x8005BB38: beq         $v0, $zero, L_8005BB44
    if (ctx->r2 == 0) {
        // 0x8005BB3C: addiu       $v0, $v1, 0x4
        ctx->r2 = ADD32(ctx->r3, 0X4);
            goto L_8005BB44;
    }
    // 0x8005BB3C: addiu       $v0, $v1, 0x4
    ctx->r2 = ADD32(ctx->r3, 0X4);
    // 0x8005BB40: andi        $v1, $v0, 0xFFFC
    ctx->r3 = ctx->r2 & 0XFFFC;
L_8005BB44:
    // 0x8005BB44: andi        $v0, $a0, 0x3
    ctx->r2 = ctx->r4 & 0X3;
    // 0x8005BB48: beq         $v0, $zero, L_8005BB54
    if (ctx->r2 == 0) {
        // 0x8005BB4C: addiu       $v0, $a0, 0x4
        ctx->r2 = ADD32(ctx->r4, 0X4);
            goto L_8005BB54;
    }
    // 0x8005BB4C: addiu       $v0, $a0, 0x4
    ctx->r2 = ADD32(ctx->r4, 0X4);
    // 0x8005BB50: andi        $a0, $v0, 0xFFFC
    ctx->r4 = ctx->r2 & 0XFFFC;
L_8005BB54:
    // 0x8005BB54: sh          $zero, 0x0($t2)
    MEM_H(0X0, ctx->r10) = 0;
    // 0x8005BB58: slt         $v0, $t0, $v1
    ctx->r2 = SIGNED(ctx->r8) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8005BB5C: beq         $v0, $zero, L_8005BB68
    if (ctx->r2 == 0) {
        // 0x8005BB60: addu        $a1, $t0, $zero
        ctx->r5 = ADD32(ctx->r8, 0);
            goto L_8005BB68;
    }
    // 0x8005BB60: addu        $a1, $t0, $zero
    ctx->r5 = ADD32(ctx->r8, 0);
    // 0x8005BB64: addu        $a1, $v1, $zero
    ctx->r5 = ADD32(ctx->r3, 0);
L_8005BB68:
    // 0x8005BB68: addu        $v1, $t0, $zero
    ctx->r3 = ADD32(ctx->r8, 0);
    // 0x8005BB6C: addiu       $v0, $a1, -0x1
    ctx->r2 = ADD32(ctx->r5, -0X1);
    // 0x8005BB70: sh          $v0, 0x4($t2)
    MEM_H(0X4, ctx->r10) = ctx->r2;
    // 0x8005BB74: slt         $v0, $v1, $a0
    ctx->r2 = SIGNED(ctx->r3) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x8005BB78: sh          $zero, 0x2($t2)
    MEM_H(0X2, ctx->r10) = 0;
    // 0x8005BB7C: sh          $t3, 0x6($t2)
    MEM_H(0X6, ctx->r10) = ctx->r11;
    // 0x8005BB80: beq         $v0, $zero, L_8005BB8C
    if (ctx->r2 == 0) {
        // 0x8005BB84: sh          $zero, 0x8($t2)
        MEM_H(0X8, ctx->r10) = 0;
            goto L_8005BB8C;
    }
    // 0x8005BB84: sh          $zero, 0x8($t2)
    MEM_H(0X8, ctx->r10) = 0;
    // 0x8005BB88: addu        $v1, $a0, $zero
    ctx->r3 = ADD32(ctx->r4, 0);
L_8005BB8C:
    // 0x8005BB8C: addiu       $v0, $v1, -0x1
    ctx->r2 = ADD32(ctx->r3, -0X1);
    // 0x8005BB90: sh          $v0, 0xC($t2)
    MEM_H(0XC, ctx->r10) = ctx->r2;
    // 0x8005BB94: addiu       $v0, $t3, 0x1
    ctx->r2 = ADD32(ctx->r11, 0X1);
    // 0x8005BB98: j           L_8005BC6C
    // 0x8005BB9C: sh          $v0, 0xA($t2)
    MEM_H(0XA, ctx->r10) = ctx->r2;
        goto L_8005BC6C;
    // 0x8005BB9C: sh          $v0, 0xA($t2)
    MEM_H(0XA, ctx->r10) = ctx->r2;
L_8005BBA0:
    // 0x8005BBA0: bgez        $t0, L_8005BBB0
    if (SIGNED(ctx->r8) >= 0) {
        // 0x8005BBA4: slt         $v0, $t0, $a1
        ctx->r2 = SIGNED(ctx->r8) < SIGNED(ctx->r5) ? 1 : 0;
            goto L_8005BBB0;
    }
    // 0x8005BBA4: slt         $v0, $t0, $a1
    ctx->r2 = SIGNED(ctx->r8) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x8005BBA8: j           L_8005BBB8
    // 0x8005BBAC: addu        $t0, $zero, $zero
    ctx->r8 = ADD32(0, 0);
        goto L_8005BBB8;
    // 0x8005BBAC: addu        $t0, $zero, $zero
    ctx->r8 = ADD32(0, 0);
L_8005BBB0:
    // 0x8005BBB0: beql        $v0, $zero, L_8005BBB8
    if (ctx->r2 == 0) {
        // 0x8005BBB4: addiu       $t0, $a1, -0x1
        ctx->r8 = ADD32(ctx->r5, -0X1);
            goto L_8005BBB8;
    }
    goto skip_14;
    // 0x8005BBB4: addiu       $t0, $a1, -0x1
    ctx->r8 = ADD32(ctx->r5, -0X1);
    skip_14:
L_8005BBB8:
    // 0x8005BBB8: subu        $v1, $v1, $s7
    ctx->r3 = SUB32(ctx->r3, ctx->r23);
    // 0x8005BBBC: bgez        $v1, L_8005BBCC
    if (SIGNED(ctx->r3) >= 0) {
        // 0x8005BBC0: nop
    
            goto L_8005BBCC;
    }
    // 0x8005BBC0: nop

    // 0x8005BBC4: j           L_8005BBE0
    // 0x8005BBC8: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
        goto L_8005BBE0;
    // 0x8005BBC8: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
L_8005BBCC:
    // 0x8005BBCC: lw          $v0, 0x0($s6)
    ctx->r2 = MEM_W(ctx->r22, 0X0);
    // 0x8005BBD0: lw          $a1, 0x10($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X10);
    // 0x8005BBD4: slt         $v0, $v1, $a1
    ctx->r2 = SIGNED(ctx->r3) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x8005BBD8: beql        $v0, $zero, L_8005BBE0
    if (ctx->r2 == 0) {
        // 0x8005BBDC: addiu       $v1, $a1, -0x1
        ctx->r3 = ADD32(ctx->r5, -0X1);
            goto L_8005BBE0;
    }
    goto skip_15;
    // 0x8005BBDC: addiu       $v1, $a1, -0x1
    ctx->r3 = ADD32(ctx->r5, -0X1);
    skip_15:
L_8005BBE0:
    // 0x8005BBE0: subu        $a0, $a0, $s7
    ctx->r4 = SUB32(ctx->r4, ctx->r23);
    // 0x8005BBE4: bgez        $a0, L_8005BBF4
    if (SIGNED(ctx->r4) >= 0) {
        // 0x8005BBE8: nop
    
            goto L_8005BBF4;
    }
    // 0x8005BBE8: nop

    // 0x8005BBEC: j           L_8005BC08
    // 0x8005BBF0: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
        goto L_8005BC08;
    // 0x8005BBF0: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
L_8005BBF4:
    // 0x8005BBF4: lw          $v0, 0x0($s6)
    ctx->r2 = MEM_W(ctx->r22, 0X0);
    // 0x8005BBF8: lw          $a1, 0x10($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X10);
    // 0x8005BBFC: slt         $v0, $a0, $a1
    ctx->r2 = SIGNED(ctx->r4) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x8005BC00: beql        $v0, $zero, L_8005BC08
    if (ctx->r2 == 0) {
        // 0x8005BC04: addiu       $a0, $a1, -0x1
        ctx->r4 = ADD32(ctx->r5, -0X1);
            goto L_8005BC08;
    }
    goto skip_16;
    // 0x8005BC04: addiu       $a0, $a1, -0x1
    ctx->r4 = ADD32(ctx->r5, -0X1);
    skip_16:
L_8005BC08:
    // 0x8005BC08: andi        $t0, $t0, 0xFFFC
    ctx->r8 = ctx->r8 & 0XFFFC;
    // 0x8005BC0C: andi        $v1, $v1, 0xFFFC
    ctx->r3 = ctx->r3 & 0XFFFC;
    // 0x8005BC10: andi        $a0, $a0, 0xFFFC
    ctx->r4 = ctx->r4 & 0XFFFC;
    // 0x8005BC14: slt         $v0, $v1, $t0
    ctx->r2 = SIGNED(ctx->r3) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x8005BC18: beq         $v0, $zero, L_8005BC24
    if (ctx->r2 == 0) {
        // 0x8005BC1C: addu        $a1, $t0, $zero
        ctx->r5 = ADD32(ctx->r8, 0);
            goto L_8005BC24;
    }
    // 0x8005BC1C: addu        $a1, $t0, $zero
    ctx->r5 = ADD32(ctx->r8, 0);
    // 0x8005BC20: addu        $a1, $v1, $zero
    ctx->r5 = ADD32(ctx->r3, 0);
L_8005BC24:
    // 0x8005BC24: sh          $a1, 0x0($t2)
    MEM_H(0X0, ctx->r10) = ctx->r5;
    // 0x8005BC28: lw          $v0, 0x0($s6)
    ctx->r2 = MEM_W(ctx->r22, 0X0);
    // 0x8005BC2C: lhu         $v0, 0x12($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X12);
    // 0x8005BC30: addu        $v1, $t0, $zero
    ctx->r3 = ADD32(ctx->r8, 0);
    // 0x8005BC34: sh          $zero, 0x2($t2)
    MEM_H(0X2, ctx->r10) = 0;
    // 0x8005BC38: sh          $t3, 0x6($t2)
    MEM_H(0X6, ctx->r10) = ctx->r11;
    // 0x8005BC3C: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x8005BC40: sh          $v0, 0x4($t2)
    MEM_H(0X4, ctx->r10) = ctx->r2;
    // 0x8005BC44: slt         $v0, $a0, $v1
    ctx->r2 = SIGNED(ctx->r4) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8005BC48: bnel        $v0, $zero, L_8005BC50
    if (ctx->r2 != 0) {
        // 0x8005BC4C: addu        $v1, $a0, $zero
        ctx->r3 = ADD32(ctx->r4, 0);
            goto L_8005BC50;
    }
    goto skip_17;
    // 0x8005BC4C: addu        $v1, $a0, $zero
    ctx->r3 = ADD32(ctx->r4, 0);
    skip_17:
L_8005BC50:
    // 0x8005BC50: sh          $v1, 0x8($t2)
    MEM_H(0X8, ctx->r10) = ctx->r3;
    // 0x8005BC54: lw          $v0, 0x0($s6)
    ctx->r2 = MEM_W(ctx->r22, 0X0);
    // 0x8005BC58: lhu         $v0, 0x12($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X12);
    // 0x8005BC5C: addiu       $v1, $t3, 0x1
    ctx->r3 = ADD32(ctx->r11, 0X1);
    // 0x8005BC60: sh          $v1, 0xA($t2)
    MEM_H(0XA, ctx->r10) = ctx->r3;
    // 0x8005BC64: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x8005BC68: sh          $v0, 0xC($t2)
    MEM_H(0XC, ctx->r10) = ctx->r2;
L_8005BC6C:
    // 0x8005BC6C: lw          $v0, 0x0($s6)
    ctx->r2 = MEM_W(ctx->r22, 0X0);
    // 0x8005BC70: lhu         $v0, 0x16($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X16);
    // 0x8005BC74: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x8005BC78: sh          $v0, 0xE($t2)
    MEM_H(0XE, ctx->r10) = ctx->r2;
L_8005BC7C:
    // 0x8005BC7C: lw          $v1, 0x14($s6)
    ctx->r3 = MEM_W(ctx->r22, 0X14);
    // 0x8005BC80: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8005BC84: addiu       $v0, $v0, 0x2
    ctx->r2 = ADD32(ctx->r2, 0X2);
    // 0x8005BC88: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
L_8005BC8C:
    // 0x8005BC8C: lw          $ra, 0xBC($sp)
    ctx->r31 = MEM_W(ctx->r29, 0XBC);
    // 0x8005BC90: lw          $fp, 0xB8($sp)
    ctx->r30 = MEM_W(ctx->r29, 0XB8);
    // 0x8005BC94: lw          $s7, 0xB4($sp)
    ctx->r23 = MEM_W(ctx->r29, 0XB4);
    // 0x8005BC98: lw          $s6, 0xB0($sp)
    ctx->r22 = MEM_W(ctx->r29, 0XB0);
    // 0x8005BC9C: lw          $s5, 0xAC($sp)
    ctx->r21 = MEM_W(ctx->r29, 0XAC);
    // 0x8005BCA0: lw          $s4, 0xA8($sp)
    ctx->r20 = MEM_W(ctx->r29, 0XA8);
    // 0x8005BCA4: lw          $s3, 0xA4($sp)
    ctx->r19 = MEM_W(ctx->r29, 0XA4);
    // 0x8005BCA8: lw          $s2, 0xA0($sp)
    ctx->r18 = MEM_W(ctx->r29, 0XA0);
    // 0x8005BCAC: lw          $s1, 0x9C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X9C);
    // 0x8005BCB0: lw          $s0, 0x98($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X98);
    // 0x8005BCB4: ldc1        $f22, 0xC8($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0XC8);
    // 0x8005BCB8: ldc1        $f20, 0xC0($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0XC0);
    // 0x8005BCBC: jr          $ra
    // 0x8005BCC0: addiu       $sp, $sp, 0xD0
    ctx->r29 = ADD32(ctx->r29, 0XD0);
    return;
    // 0x8005BCC0: addiu       $sp, $sp, 0xD0
    ctx->r29 = ADD32(ctx->r29, 0XD0);
;}
RECOMP_FUNC void func_8005BCC4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005BCC4: addiu       $sp, $sp, -0xE0
    ctx->r29 = ADD32(ctx->r29, -0XE0);
    // 0x8005BCC8: sw          $s0, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->r16;
    // 0x8005BCCC: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x8005BCD0: andi        $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 & 0XFFFF;
    // 0x8005BCD4: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x8005BCD8: sw          $ra, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->r31;
    // 0x8005BCDC: sw          $s6, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->r22;
    // 0x8005BCE0: sw          $s5, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->r21;
    // 0x8005BCE4: sw          $s4, 0xC0($sp)
    MEM_W(0XC0, ctx->r29) = ctx->r20;
    // 0x8005BCE8: sw          $s3, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->r19;
    // 0x8005BCEC: sw          $s2, 0xB8($sp)
    MEM_W(0XB8, ctx->r29) = ctx->r18;
    // 0x8005BCF0: sw          $s1, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->r17;
    // 0x8005BCF4: sdc1        $f22, 0xD8($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0XD8, ctx->r29);
    // 0x8005BCF8: sdc1        $f20, 0xD0($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0XD0, ctx->r29);
    // 0x8005BCFC: lw          $s2, 0x4($s0)
    ctx->r18 = MEM_W(ctx->r16, 0X4);
    // 0x8005BD00: beq         $a1, $v0, L_8005C310
    if (ctx->r5 == ctx->r2) {
        // 0x8005BD04: slti        $v0, $a1, 0x3
        ctx->r2 = SIGNED(ctx->r5) < 0X3 ? 1 : 0;
            goto L_8005C310;
    }
    // 0x8005BD04: slti        $v0, $a1, 0x3
    ctx->r2 = SIGNED(ctx->r5) < 0X3 ? 1 : 0;
    // 0x8005BD08: beq         $v0, $zero, L_8005BD20
    if (ctx->r2 == 0) {
        // 0x8005BD0C: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_8005BD20;
    }
    // 0x8005BD0C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8005BD10: beq         $a1, $v0, L_8005BD3C
    if (ctx->r5 == ctx->r2) {
        // 0x8005BD14: addiu       $a0, $zero, 0xF14
        ctx->r4 = ADD32(0, 0XF14);
            goto L_8005BD3C;
    }
    // 0x8005BD14: addiu       $a0, $zero, 0xF14
    ctx->r4 = ADD32(0, 0XF14);
    // 0x8005BD18: j           L_8005C59C
    // 0x8005BD1C: nop

        goto L_8005C59C;
    // 0x8005BD1C: nop

L_8005BD20:
    // 0x8005BD20: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x8005BD24: beq         $a1, $v0, L_8005C59C
    if (ctx->r5 == ctx->r2) {
        // 0x8005BD28: addiu       $v0, $zero, 0x4
        ctx->r2 = ADD32(0, 0X4);
            goto L_8005C59C;
    }
    // 0x8005BD28: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // 0x8005BD2C: beq         $a1, $v0, L_8005C378
    if (ctx->r5 == ctx->r2) {
        // 0x8005BD30: lui         $v0, 0x8014
        ctx->r2 = S32(0X8014 << 16);
            goto L_8005C378;
    }
    // 0x8005BD30: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x8005BD34: j           L_8005C59C
    // 0x8005BD38: nop

        goto L_8005C59C;
    // 0x8005BD38: nop

L_8005BD3C:
    // 0x8005BD3C: jal         0x80001ACC
    // 0x8005BD40: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    rs_malloc(rdram, ctx);
        goto after_0;
    // 0x8005BD40: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    after_0:
    // 0x8005BD44: addu        $s2, $v0, $zero
    ctx->r18 = ADD32(ctx->r2, 0);
    // 0x8005BD48: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x8005BD4C: lbu         $v1, 0xB39($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0XB39);
    // 0x8005BD50: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8005BD54: sw          $s2, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r18;
    // 0x8005BD58: lbu         $s1, 0xB40($v0)
    ctx->r17 = MEM_BU(ctx->r2, 0XB40);
    // 0x8005BD5C: beq         $v1, $zero, L_8005BD7C
    if (ctx->r3 == 0) {
        // 0x8005BD60: addiu       $v0, $zero, 0x13
        ctx->r2 = ADD32(0, 0X13);
            goto L_8005BD7C;
    }
    // 0x8005BD60: addiu       $v0, $zero, 0x13
    ctx->r2 = ADD32(0, 0X13);
    // 0x8005BD64: beql        $s1, $v0, L_8005BD6C
    if (ctx->r17 == ctx->r2) {
        // 0x8005BD68: addu        $s1, $zero, $zero
        ctx->r17 = ADD32(0, 0);
            goto L_8005BD6C;
    }
    goto skip_0;
    // 0x8005BD68: addu        $s1, $zero, $zero
    ctx->r17 = ADD32(0, 0);
    skip_0:
L_8005BD6C:
    // 0x8005BD6C: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8005BD70: lbu         $v0, 0xB38($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0XB38);
    // 0x8005BD74: bnel        $v0, $zero, L_8005BD7C
    if (ctx->r2 != 0) {
        // 0x8005BD78: addiu       $s1, $zero, 0x11
        ctx->r17 = ADD32(0, 0X11);
            goto L_8005BD7C;
    }
    goto skip_1;
    // 0x8005BD78: addiu       $s1, $zero, 0x11
    ctx->r17 = ADD32(0, 0X11);
    skip_1:
L_8005BD7C:
    // 0x8005BD7C: addiu       $v0, $zero, 0x10
    ctx->r2 = ADD32(0, 0X10);
    // 0x8005BD80: beq         $s1, $v0, L_8005BDC4
    if (ctx->r17 == ctx->r2) {
        // 0x8005BD84: slti        $v0, $s1, 0x11
        ctx->r2 = SIGNED(ctx->r17) < 0X11 ? 1 : 0;
            goto L_8005BDC4;
    }
    // 0x8005BD84: slti        $v0, $s1, 0x11
    ctx->r2 = SIGNED(ctx->r17) < 0X11 ? 1 : 0;
    // 0x8005BD88: beq         $v0, $zero, L_8005BDA0
    if (ctx->r2 == 0) {
        // 0x8005BD8C: addiu       $v0, $zero, 0x9
        ctx->r2 = ADD32(0, 0X9);
            goto L_8005BDA0;
    }
    // 0x8005BD8C: addiu       $v0, $zero, 0x9
    ctx->r2 = ADD32(0, 0X9);
    // 0x8005BD90: beq         $s1, $v0, L_8005BDBC
    if (ctx->r17 == ctx->r2) {
        // 0x8005BD94: lui         $v0, 0x8004
        ctx->r2 = S32(0X8004 << 16);
            goto L_8005BDBC;
    }
    // 0x8005BD94: lui         $v0, 0x8004
    ctx->r2 = S32(0X8004 << 16);
    // 0x8005BD98: j           L_8005BDE0
    // 0x8005BD9C: addiu       $a1, $v0, -0x51B8
    ctx->r5 = ADD32(ctx->r2, -0X51B8);
        goto L_8005BDE0;
    // 0x8005BD9C: addiu       $a1, $v0, -0x51B8
    ctx->r5 = ADD32(ctx->r2, -0X51B8);
L_8005BDA0:
    // 0x8005BDA0: addiu       $v0, $zero, 0x11
    ctx->r2 = ADD32(0, 0X11);
    // 0x8005BDA4: beq         $s1, $v0, L_8005BDCC
    if (ctx->r17 == ctx->r2) {
        // 0x8005BDA8: addiu       $v0, $zero, 0x14
        ctx->r2 = ADD32(0, 0X14);
            goto L_8005BDCC;
    }
    // 0x8005BDA8: addiu       $v0, $zero, 0x14
    ctx->r2 = ADD32(0, 0X14);
    // 0x8005BDAC: beq         $s1, $v0, L_8005BDD4
    if (ctx->r17 == ctx->r2) {
        // 0x8005BDB0: lui         $v0, 0x8004
        ctx->r2 = S32(0X8004 << 16);
            goto L_8005BDD4;
    }
    // 0x8005BDB0: lui         $v0, 0x8004
    ctx->r2 = S32(0X8004 << 16);
    // 0x8005BDB4: j           L_8005BDE0
    // 0x8005BDB8: addiu       $a1, $v0, -0x51B8
    ctx->r5 = ADD32(ctx->r2, -0X51B8);
        goto L_8005BDE0;
    // 0x8005BDB8: addiu       $a1, $v0, -0x51B8
    ctx->r5 = ADD32(ctx->r2, -0X51B8);
L_8005BDBC:
    // 0x8005BDBC: j           L_8005BDD8
    // 0x8005BDC0: addiu       $s1, $zero, 0x8
    ctx->r17 = ADD32(0, 0X8);
        goto L_8005BDD8;
    // 0x8005BDC0: addiu       $s1, $zero, 0x8
    ctx->r17 = ADD32(0, 0X8);
L_8005BDC4:
    // 0x8005BDC4: j           L_8005BDD8
    // 0x8005BDC8: addu        $s1, $zero, $zero
    ctx->r17 = ADD32(0, 0);
        goto L_8005BDD8;
    // 0x8005BDC8: addu        $s1, $zero, $zero
    ctx->r17 = ADD32(0, 0);
L_8005BDCC:
    // 0x8005BDCC: j           L_8005BDD8
    // 0x8005BDD0: addiu       $s1, $zero, 0x5
    ctx->r17 = ADD32(0, 0X5);
        goto L_8005BDD8;
    // 0x8005BDD0: addiu       $s1, $zero, 0x5
    ctx->r17 = ADD32(0, 0X5);
L_8005BDD4:
    // 0x8005BDD4: addiu       $s1, $zero, 0x1
    ctx->r17 = ADD32(0, 0X1);
L_8005BDD8:
    // 0x8005BDD8: lui         $v0, 0x8004
    ctx->r2 = S32(0X8004 << 16);
    // 0x8005BDDC: addiu       $a1, $v0, -0x51B8
    ctx->r5 = ADD32(ctx->r2, -0X51B8);
L_8005BDE0:
    // 0x8005BDE0: slti        $v0, $s1, 0xA
    ctx->r2 = SIGNED(ctx->r17) < 0XA ? 1 : 0;
    // 0x8005BDE4: bne         $v0, $zero, L_8005BDF0
    if (ctx->r2 != 0) {
        // 0x8005BDE8: addiu       $a2, $s1, 0x30
        ctx->r6 = ADD32(ctx->r17, 0X30);
            goto L_8005BDF0;
    }
    // 0x8005BDE8: addiu       $a2, $s1, 0x30
    ctx->r6 = ADD32(ctx->r17, 0X30);
    // 0x8005BDEC: addiu       $a2, $s1, 0x57
    ctx->r6 = ADD32(ctx->r17, 0X57);
L_8005BDF0:
    // 0x8005BDF0: jal         0x80033CC4
    // 0x8005BDF4: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    sprintf_recomp(rdram, ctx);
        goto after_1;
    // 0x8005BDF4: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    after_1:
    // 0x8005BDF8: jal         0x8006B180
    // 0x8005BDFC: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    func_8006B180(rdram, ctx);
        goto after_2;
    // 0x8005BDFC: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    after_2:
    // 0x8005BE00: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    // 0x8005BE04: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x8005BE08: sltu        $v0, $zero, $v0
    ctx->r2 = 0 < ctx->r2 ? 1 : 0;
    // 0x8005BE0C: sll         $a2, $v0, 1
    ctx->r6 = S32(ctx->r2 << 1);
    // 0x8005BE10: jal         0x8005645C
    // 0x8005BE14: addu        $a3, $a1, $zero
    ctx->r7 = ADD32(ctx->r5, 0);
    load_hmt_and_hob(rdram, ctx);
        goto after_3;
    // 0x8005BE14: addu        $a3, $a1, $zero
    ctx->r7 = ADD32(ctx->r5, 0);
    after_3:
    // 0x8005BE18: lui         $a0, 0x8004
    ctx->r4 = S32(0X8004 << 16);
    // 0x8005BE1C: jal         0x80056EB0
    // 0x8005BE20: addiu       $a0, $a0, -0x51F0
    ctx->r4 = ADD32(ctx->r4, -0X51F0);
    func_80056EB0(rdram, ctx);
        goto after_4;
    // 0x8005BE20: addiu       $a0, $a0, -0x51F0
    ctx->r4 = ADD32(ctx->r4, -0X51F0);
    after_4:
    // 0x8005BE24: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // 0x8005BE28: jal         0x8005AB34
    // 0x8005BE2C: sw          $v0, 0x18($s2)
    MEM_W(0X18, ctx->r18) = ctx->r2;
    func_8005AB34(rdram, ctx);
        goto after_5;
    // 0x8005BE2C: sw          $v0, 0x18($s2)
    MEM_W(0X18, ctx->r18) = ctx->r2;
    after_5:
    // 0x8005BE30: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8005BE34: lbu         $v0, 0xB39($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0XB39);
    // 0x8005BE38: beq         $v0, $zero, L_8005BE68
    if (ctx->r2 == 0) {
        // 0x8005BE3C: lui         $v0, 0x8013
        ctx->r2 = S32(0X8013 << 16);
            goto L_8005BE68;
    }
    // 0x8005BE3C: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8005BE40: lbu         $v0, 0xB38($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0XB38);
    // 0x8005BE44: beq         $v0, $zero, L_8005BE68
    if (ctx->r2 == 0) {
        // 0x8005BE48: nop
    
            goto L_8005BE68;
    }
    // 0x8005BE48: nop

    // 0x8005BE4C: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8005BE50: lwc1        $f0, -0x5124($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X5124);
    // 0x8005BE54: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8005BE58: lwc1        $f2, -0x5120($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X5120);
    // 0x8005BE5C: swc1        $f0, 0x8($s2)
    MEM_W(0X8, ctx->r18) = ctx->f0.u32l;
    // 0x8005BE60: j           L_8005BE94
    // 0x8005BE64: swc1        $f2, 0xC($s2)
    MEM_W(0XC, ctx->r18) = ctx->f2.u32l;
        goto L_8005BE94;
    // 0x8005BE64: swc1        $f2, 0xC($s2)
    MEM_W(0XC, ctx->r18) = ctx->f2.u32l;
L_8005BE68:
    // 0x8005BE68: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8005BE6C: lwc1        $f20, -0x511C($at)
    ctx->f20.u32l = MEM_W(ctx->r1, -0X511C);
    // 0x8005BE70: jal         0x8006B510
    // 0x8005BE74: nop

    func_8006B510(rdram, ctx);
        goto after_6;
    // 0x8005BE74: nop

    after_6:
    // 0x8005BE78: mul.s       $f0, $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f20.fl);
    // 0x8005BE7C: div.s       $f0, $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f20.fl);
    // 0x8005BE80: jal         0x8006B53C
    // 0x8005BE84: swc1        $f0, 0x8($s2)
    MEM_W(0X8, ctx->r18) = ctx->f0.u32l;
    func_8006B53C(rdram, ctx);
        goto after_7;
    // 0x8005BE84: swc1        $f0, 0x8($s2)
    MEM_W(0X8, ctx->r18) = ctx->f0.u32l;
    after_7:
    // 0x8005BE88: mul.s       $f0, $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f20.fl);
    // 0x8005BE8C: div.s       $f0, $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f20.fl);
    // 0x8005BE90: swc1        $f0, 0xC($s2)
    MEM_W(0XC, ctx->r18) = ctx->f0.u32l;
L_8005BE94:
    // 0x8005BE94: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8005BE98: lw          $v1, 0xB70($v0)
    ctx->r3 = MEM_W(ctx->r2, 0XB70);
    // 0x8005BE9C: sw          $zero, 0x0($s2)
    MEM_W(0X0, ctx->r18) = 0;
    // 0x8005BEA0: sw          $zero, 0xEDC($s2)
    MEM_W(0XEDC, ctx->r18) = 0;
    // 0x8005BEA4: sltiu       $v0, $v1, 0x11
    ctx->r2 = ctx->r3 < 0X11 ? 1 : 0;
    // 0x8005BEA8: beq         $v0, $zero, L_8005C2E8
    if (ctx->r2 == 0) {
        // 0x8005BEAC: sw          $zero, 0xF00($s2)
        MEM_W(0XF00, ctx->r18) = 0;
            goto L_8005C2E8;
    }
    // 0x8005BEAC: sw          $zero, 0xF00($s2)
    MEM_W(0XF00, ctx->r18) = 0;
    // 0x8005BEB0: lui         $v0, 0x8004
    ctx->r2 = S32(0X8004 << 16);
    // 0x8005BEB4: addiu       $v0, $v0, -0x5118
    ctx->r2 = ADD32(ctx->r2, -0X5118);
    // 0x8005BEB8: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x8005BEBC: addu        $v1, $v1, $v0
    gpr jr_addend_8005BEC4 = ctx->r3;
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x8005BEC0: lw          $v0, 0x0($v1)
    ctx->r2 = ADD32(ctx->r3, 0X0);
    // 0x8005BEC4: jr          $v0
    // 0x8005BEC8: nop

    switch (jr_addend_8005BEC4 >> 2) {
        case 0: goto L_8005BFFC; break;
        case 1: goto L_8005C1DC; break;
        case 2: goto L_8005C2E8; break;
        case 3: goto L_8005C2E8; break;
        case 4: goto L_8005C2E8; break;
        case 5: goto L_8005BEDC; break;
        case 6: goto L_8005C2E8; break;
        case 7: goto L_8005C2E8; break;
        case 8: goto L_8005C2E8; break;
        case 9: goto L_8005C2E8; break;
        case 10: goto L_8005BECC; break;
        case 11: goto L_8005C2E8; break;
        case 12: goto L_8005C2E8; break;
        case 13: goto L_8005C2E8; break;
        case 14: goto L_8005C2E8; break;
        case 15: goto L_8005C2E8; break;
        case 16: goto L_8005BFFC; break;
        default: switch_error(__func__, 0x8005BEC4, 0x8003AEE8);
    }
    // 0x8005BEC8: nop

L_8005BECC:
    // 0x8005BECC: jal         0x8005A120
    // 0x8005BED0: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    func_8005A120(rdram, ctx);
        goto after_8;
    // 0x8005BED0: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    after_8:
    // 0x8005BED4: j           L_8005C2EC
    // 0x8005BED8: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
        goto L_8005C2EC;
    // 0x8005BED8: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
L_8005BEDC:
    // 0x8005BEDC: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8005BEE0: lbu         $v0, 0xB63($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0XB63);
    // 0x8005BEE4: bne         $v0, $zero, L_8005BEFC
    if (ctx->r2 != 0) {
        // 0x8005BEE8: lui         $v0, 0x8004
        ctx->r2 = S32(0X8004 << 16);
            goto L_8005BEFC;
    }
    // 0x8005BEE8: lui         $v0, 0x8004
    ctx->r2 = S32(0X8004 << 16);
    // 0x8005BEEC: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8005BEF0: lbu         $v0, 0xB39($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0XB39);
    // 0x8005BEF4: beq         $v0, $zero, L_8005BF04
    if (ctx->r2 == 0) {
        // 0x8005BEF8: lui         $v0, 0x8004
        ctx->r2 = S32(0X8004 << 16);
            goto L_8005BF04;
    }
    // 0x8005BEF8: lui         $v0, 0x8004
    ctx->r2 = S32(0X8004 << 16);
L_8005BEFC:
    // 0x8005BEFC: j           L_8005BF0C
    // 0x8005BF00: addiu       $a0, $v0, -0x51A8
    ctx->r4 = ADD32(ctx->r2, -0X51A8);
        goto L_8005BF0C;
    // 0x8005BF00: addiu       $a0, $v0, -0x51A8
    ctx->r4 = ADD32(ctx->r2, -0X51A8);
L_8005BF04:
    // 0x8005BF04: lui         $v0, 0x8004
    ctx->r2 = S32(0X8004 << 16);
    // 0x8005BF08: addiu       $a0, $v0, -0x5190
    ctx->r4 = ADD32(ctx->r2, -0X5190);
L_8005BF0C:
    // 0x8005BF0C: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x8005BF10: addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    // 0x8005BF14: jal         0x8005645C
    // 0x8005BF18: addu        $a3, $a1, $zero
    ctx->r7 = ADD32(ctx->r5, 0);
    load_hmt_and_hob(rdram, ctx);
        goto after_9;
    // 0x8005BF18: addu        $a3, $a1, $zero
    ctx->r7 = ADD32(ctx->r5, 0);
    after_9:
    // 0x8005BF1C: lui         $a0, 0x8004
    ctx->r4 = S32(0X8004 << 16);
    // 0x8005BF20: jal         0x80056EB0
    // 0x8005BF24: addiu       $a0, $a0, -0x5178
    ctx->r4 = ADD32(ctx->r4, -0X5178);
    func_80056EB0(rdram, ctx);
        goto after_10;
    // 0x8005BF24: addiu       $a0, $a0, -0x5178
    ctx->r4 = ADD32(ctx->r4, -0X5178);
    after_10:
    // 0x8005BF28: sw          $v0, 0xED4($s2)
    MEM_W(0XED4, ctx->r18) = ctx->r2;
    // 0x8005BF2C: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8005BF30: addiu       $s0, $sp, 0x40
    ctx->r16 = ADD32(ctx->r29, 0X40);
    // 0x8005BF34: addiu       $s1, $s2, 0xEE0
    ctx->r17 = ADD32(ctx->r18, 0XEE0);
    // 0x8005BF38: lw          $v0, 0x6E08($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X6E08);
    // 0x8005BF3C: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x8005BF40: lwc1        $f0, 0x10($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X10);
    // 0x8005BF44: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8005BF48: lwc1        $f22, -0x50D4($at)
    ctx->f22.u32l = MEM_W(ctx->r1, -0X50D4);
    // 0x8005BF4C: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
    // 0x8005BF50: swc1        $f0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f0.u32l;
    // 0x8005BF54: lwc1        $f2, 0x18($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X18);
    // 0x8005BF58: c.eq.s      $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f0.fl == ctx->f20.fl;
    // 0x8005BF5C: neg.s       $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = -ctx->f2.fl;
    // 0x8005BF60: bc1f        L_8005BF74
    if (!c1cs) {
        // 0x8005BF64: swc1        $f2, 0x48($sp)
        MEM_W(0X48, ctx->r29) = ctx->f2.u32l;
            goto L_8005BF74;
    }
    // 0x8005BF64: swc1        $f2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f2.u32l;
    // 0x8005BF68: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8005BF6C: lwc1        $f0, -0x50D0($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X50D0);
    // 0x8005BF70: swc1        $f0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f0.u32l;
L_8005BF74:
    // 0x8005BF74: mul.s       $f2, $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x8005BF78: lwc1        $f0, 0x40($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X40);
    // 0x8005BF7C: mul.s       $f0, $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x8005BF80: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x8005BF84: sqrt.s      $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = sqrtf(ctx->f0.fl);
    // 0x8005BF88: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x8005BF8C: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
    // 0x8005BF90: div.s       $f0, $f0, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f22.fl);
    // 0x8005BF94: jal         0x8001CF58
    // 0x8005BF98: swc1        $f0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f0.u32l;
    normalize_vector(rdram, ctx);
        goto after_11;
    // 0x8005BF98: swc1        $f0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f0.u32l;
    after_11:
    // 0x8005BF9C: lui         $a1, 0x4190
    ctx->r5 = S32(0X4190 << 16);
    // 0x8005BFA0: addiu       $a0, $sp, 0x50
    ctx->r4 = ADD32(ctx->r29, 0X50);
    // 0x8005BFA4: addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    // 0x8005BFA8: jal         0x8001CB64
    // 0x8005BFAC: addu        $a3, $a1, $zero
    ctx->r7 = ADD32(ctx->r5, 0);
    func_8001CB64(rdram, ctx);
        goto after_12;
    // 0x8005BFAC: addu        $a3, $a1, $zero
    ctx->r7 = ADD32(ctx->r5, 0);
    after_12:
    // 0x8005BFB0: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x8005BFB4: jal         0x8001CB9C
    // 0x8005BFB8: addiu       $a0, $sp, 0x50
    ctx->r4 = ADD32(ctx->r29, 0X50);
    func_8001CB9C(rdram, ctx);
        goto after_13;
    // 0x8005BFB8: addiu       $a0, $sp, 0x50
    ctx->r4 = ADD32(ctx->r29, 0X50);
    after_13:
    // 0x8005BFBC: lui         $a1, 0x4150
    ctx->r5 = S32(0X4150 << 16);
    // 0x8005BFC0: jal         0x8001CDFC
    // 0x8005BFC4: addiu       $a0, $sp, 0x50
    ctx->r4 = ADD32(ctx->r29, 0X50);
    func_8001CDFC(rdram, ctx);
        goto after_14;
    // 0x8005BFC4: addiu       $a0, $sp, 0x50
    ctx->r4 = ADD32(ctx->r29, 0X50);
    after_14:
    // 0x8005BFC8: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x8005BFCC: jal         0x8001CCCC
    // 0x8005BFD0: addiu       $a0, $sp, 0x50
    ctx->r4 = ADD32(ctx->r29, 0X50);
    func_8001CCCC(rdram, ctx);
        goto after_15;
    // 0x8005BFD0: addiu       $a0, $sp, 0x50
    ctx->r4 = ADD32(ctx->r29, 0X50);
    after_15:
    // 0x8005BFD4: addiu       $a0, $sp, 0x50
    ctx->r4 = ADD32(ctx->r29, 0X50);
    // 0x8005BFD8: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x8005BFDC: jal         0x800194A4
    // 0x8005BFE0: addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    func_800194A4(rdram, ctx);
        goto after_16;
    // 0x8005BFE0: addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    after_16:
    // 0x8005BFE4: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x8005BFE8: lui         $a2, 0x47
    ctx->r6 = S32(0X47 << 16);
    // 0x8005BFEC: lw          $a0, 0xED4($s2)
    ctx->r4 = MEM_W(ctx->r18, 0XED4);
    // 0x8005BFF0: addu        $a3, $a1, $zero
    ctx->r7 = ADD32(ctx->r5, 0);
    // 0x8005BFF4: j           L_8005C2D8
    // 0x8005BFF8: swc1        $f22, 0xEF8($s2)
    MEM_W(0XEF8, ctx->r18) = ctx->f22.u32l;
        goto L_8005C2D8;
    // 0x8005BFF8: swc1        $f22, 0xEF8($s2)
    MEM_W(0XEF8, ctx->r18) = ctx->f22.u32l;
L_8005BFFC:
    // 0x8005BFFC: lui         $a0, 0x8004
    ctx->r4 = S32(0X8004 << 16);
    // 0x8005C000: addiu       $a0, $a0, -0x516C
    ctx->r4 = ADD32(ctx->r4, -0X516C);
    // 0x8005C004: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x8005C008: addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    // 0x8005C00C: jal         0x8005645C
    // 0x8005C010: addu        $a3, $a1, $zero
    ctx->r7 = ADD32(ctx->r5, 0);
    load_hmt_and_hob(rdram, ctx);
        goto after_17;
    // 0x8005C010: addu        $a3, $a1, $zero
    ctx->r7 = ADD32(ctx->r5, 0);
    after_17:
    // 0x8005C014: lui         $a0, 0x8004
    ctx->r4 = S32(0X8004 << 16);
    // 0x8005C018: jal         0x80056EB0
    // 0x8005C01C: addiu       $a0, $a0, -0x5158
    ctx->r4 = ADD32(ctx->r4, -0X5158);
    func_80056EB0(rdram, ctx);
        goto after_18;
    // 0x8005C01C: addiu       $a0, $a0, -0x5158
    ctx->r4 = ADD32(ctx->r4, -0X5158);
    after_18:
    // 0x8005C020: sw          $v0, 0xED4($s2)
    MEM_W(0XED4, ctx->r18) = ctx->r2;
    // 0x8005C024: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8005C028: addiu       $s3, $v0, 0x6DC0
    ctx->r19 = ADD32(ctx->r2, 0X6DC0);
    // 0x8005C02C: addiu       $s0, $sp, 0x40
    ctx->r16 = ADD32(ctx->r29, 0X40);
    // 0x8005C030: addiu       $s1, $s2, 0xEE0
    ctx->r17 = ADD32(ctx->r18, 0XEE0);
    // 0x8005C034: lw          $v0, 0x48($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X48);
    // 0x8005C038: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x8005C03C: lwc1        $f0, 0x10($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X10);
    // 0x8005C040: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8005C044: lwc1        $f22, -0x50CC($at)
    ctx->f22.u32l = MEM_W(ctx->r1, -0X50CC);
    // 0x8005C048: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
    // 0x8005C04C: swc1        $f0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f0.u32l;
    // 0x8005C050: lwc1        $f2, 0x18($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X18);
    // 0x8005C054: c.eq.s      $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f0.fl == ctx->f20.fl;
    // 0x8005C058: neg.s       $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = -ctx->f2.fl;
    // 0x8005C05C: bc1f        L_8005C070
    if (!c1cs) {
        // 0x8005C060: swc1        $f2, 0x48($sp)
        MEM_W(0X48, ctx->r29) = ctx->f2.u32l;
            goto L_8005C070;
    }
    // 0x8005C060: swc1        $f2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f2.u32l;
    // 0x8005C064: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8005C068: lwc1        $f0, -0x50C8($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X50C8);
    // 0x8005C06C: swc1        $f0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f0.u32l;
L_8005C070:
    // 0x8005C070: mul.s       $f2, $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x8005C074: lwc1        $f0, 0x40($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X40);
    // 0x8005C078: mul.s       $f0, $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x8005C07C: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x8005C080: sqrt.s      $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = sqrtf(ctx->f0.fl);
    // 0x8005C084: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x8005C088: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
    // 0x8005C08C: div.s       $f0, $f0, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f22.fl);
    // 0x8005C090: jal         0x8001CF58
    // 0x8005C094: swc1        $f0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f0.u32l;
    normalize_vector(rdram, ctx);
        goto after_19;
    // 0x8005C094: swc1        $f0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f0.u32l;
    after_19:
    // 0x8005C098: lui         $a1, 0x4190
    ctx->r5 = S32(0X4190 << 16);
    // 0x8005C09C: addiu       $a0, $sp, 0x50
    ctx->r4 = ADD32(ctx->r29, 0X50);
    // 0x8005C0A0: addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    // 0x8005C0A4: jal         0x8001CB64
    // 0x8005C0A8: addu        $a3, $a1, $zero
    ctx->r7 = ADD32(ctx->r5, 0);
    func_8001CB64(rdram, ctx);
        goto after_20;
    // 0x8005C0A8: addu        $a3, $a1, $zero
    ctx->r7 = ADD32(ctx->r5, 0);
    after_20:
    // 0x8005C0AC: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x8005C0B0: jal         0x8001CB9C
    // 0x8005C0B4: addiu       $a0, $sp, 0x50
    ctx->r4 = ADD32(ctx->r29, 0X50);
    func_8001CB9C(rdram, ctx);
        goto after_21;
    // 0x8005C0B4: addiu       $a0, $sp, 0x50
    ctx->r4 = ADD32(ctx->r29, 0X50);
    after_21:
    // 0x8005C0B8: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x8005C0BC: jal         0x8001CDFC
    // 0x8005C0C0: addiu       $a0, $sp, 0x50
    ctx->r4 = ADD32(ctx->r29, 0X50);
    func_8001CDFC(rdram, ctx);
        goto after_22;
    // 0x8005C0C0: addiu       $a0, $sp, 0x50
    ctx->r4 = ADD32(ctx->r29, 0X50);
    after_22:
    // 0x8005C0C4: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x8005C0C8: jal         0x8001CCCC
    // 0x8005C0CC: addiu       $a0, $sp, 0x50
    ctx->r4 = ADD32(ctx->r29, 0X50);
    func_8001CCCC(rdram, ctx);
        goto after_23;
    // 0x8005C0CC: addiu       $a0, $sp, 0x50
    ctx->r4 = ADD32(ctx->r29, 0X50);
    after_23:
    // 0x8005C0D0: addiu       $a0, $sp, 0x50
    ctx->r4 = ADD32(ctx->r29, 0X50);
    // 0x8005C0D4: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x8005C0D8: jal         0x800194A4
    // 0x8005C0DC: addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    func_800194A4(rdram, ctx);
        goto after_24;
    // 0x8005C0DC: addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    after_24:
    // 0x8005C0E0: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x8005C0E4: lui         $a2, 0x907
    ctx->r6 = S32(0X907 << 16);
    // 0x8005C0E8: lw          $a0, 0xED4($s2)
    ctx->r4 = MEM_W(ctx->r18, 0XED4);
    // 0x8005C0EC: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8005C0F0: lwc1        $f0, -0x50C4($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X50C4);
    // 0x8005C0F4: addu        $a3, $a1, $zero
    ctx->r7 = ADD32(ctx->r5, 0);
    // 0x8005C0F8: jal         0x8005955C
    // 0x8005C0FC: swc1        $f0, 0xEF8($s2)
    MEM_W(0XEF8, ctx->r18) = ctx->f0.u32l;
    func_8005955C(rdram, ctx);
        goto after_25;
    // 0x8005C0FC: swc1        $f0, 0xEF8($s2)
    MEM_W(0XEF8, ctx->r18) = ctx->f0.u32l;
    after_25:
    // 0x8005C100: lui         $a0, 0x8004
    ctx->r4 = S32(0X8004 << 16);
    // 0x8005C104: jal         0x80056EB0
    // 0x8005C108: addiu       $a0, $a0, -0x5150
    ctx->r4 = ADD32(ctx->r4, -0X5150);
    func_80056EB0(rdram, ctx);
        goto after_26;
    // 0x8005C108: addiu       $a0, $a0, -0x5150
    ctx->r4 = ADD32(ctx->r4, -0X5150);
    after_26:
    // 0x8005C10C: sw          $v0, 0xED8($s2)
    MEM_W(0XED8, ctx->r18) = ctx->r2;
    // 0x8005C110: lw          $v0, 0x48($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X48);
    // 0x8005C114: lwc1        $f0, 0x10($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X10);
    // 0x8005C118: addiu       $s1, $s2, 0xEEC
    ctx->r17 = ADD32(ctx->r18, 0XEEC);
    // 0x8005C11C: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
    // 0x8005C120: swc1        $f0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f0.u32l;
    // 0x8005C124: lwc1        $f2, 0x18($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X18);
    // 0x8005C128: c.eq.s      $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f0.fl == ctx->f20.fl;
    // 0x8005C12C: neg.s       $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = -ctx->f2.fl;
    // 0x8005C130: bc1f        L_8005C144
    if (!c1cs) {
        // 0x8005C134: swc1        $f2, 0x48($sp)
        MEM_W(0X48, ctx->r29) = ctx->f2.u32l;
            goto L_8005C144;
    }
    // 0x8005C134: swc1        $f2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f2.u32l;
    // 0x8005C138: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8005C13C: lwc1        $f0, -0x50C0($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X50C0);
    // 0x8005C140: swc1        $f0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f0.u32l;
L_8005C144:
    // 0x8005C144: mul.s       $f2, $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x8005C148: lwc1        $f0, 0x40($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X40);
    // 0x8005C14C: mul.s       $f0, $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x8005C150: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x8005C154: sqrt.s      $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = sqrtf(ctx->f0.fl);
    // 0x8005C158: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x8005C15C: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
    // 0x8005C160: div.s       $f0, $f0, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f22.fl);
    // 0x8005C164: jal         0x8001CF58
    // 0x8005C168: swc1        $f0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f0.u32l;
    normalize_vector(rdram, ctx);
        goto after_27;
    // 0x8005C168: swc1        $f0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f0.u32l;
    after_27:
    // 0x8005C16C: lui         $a1, 0x4190
    ctx->r5 = S32(0X4190 << 16);
    // 0x8005C170: addiu       $a0, $sp, 0x50
    ctx->r4 = ADD32(ctx->r29, 0X50);
    // 0x8005C174: addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    // 0x8005C178: jal         0x8001CB64
    // 0x8005C17C: addu        $a3, $a1, $zero
    ctx->r7 = ADD32(ctx->r5, 0);
    func_8001CB64(rdram, ctx);
        goto after_28;
    // 0x8005C17C: addu        $a3, $a1, $zero
    ctx->r7 = ADD32(ctx->r5, 0);
    after_28:
    // 0x8005C180: lui         $a1, 0xC120
    ctx->r5 = S32(0XC120 << 16);
    // 0x8005C184: jal         0x8001CB9C
    // 0x8005C188: addiu       $a0, $sp, 0x50
    ctx->r4 = ADD32(ctx->r29, 0X50);
    func_8001CB9C(rdram, ctx);
        goto after_29;
    // 0x8005C188: addiu       $a0, $sp, 0x50
    ctx->r4 = ADD32(ctx->r29, 0X50);
    after_29:
    // 0x8005C18C: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x8005C190: jal         0x8001CDFC
    // 0x8005C194: addiu       $a0, $sp, 0x50
    ctx->r4 = ADD32(ctx->r29, 0X50);
    func_8001CDFC(rdram, ctx);
        goto after_30;
    // 0x8005C194: addiu       $a0, $sp, 0x50
    ctx->r4 = ADD32(ctx->r29, 0X50);
    after_30:
    // 0x8005C198: lui         $a1, 0x4170
    ctx->r5 = S32(0X4170 << 16);
    // 0x8005C19C: jal         0x8001CCCC
    // 0x8005C1A0: addiu       $a0, $sp, 0x50
    ctx->r4 = ADD32(ctx->r29, 0X50);
    func_8001CCCC(rdram, ctx);
        goto after_31;
    // 0x8005C1A0: addiu       $a0, $sp, 0x50
    ctx->r4 = ADD32(ctx->r29, 0X50);
    after_31:
    // 0x8005C1A4: addiu       $a0, $sp, 0x50
    ctx->r4 = ADD32(ctx->r29, 0X50);
    // 0x8005C1A8: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x8005C1AC: jal         0x800194A4
    // 0x8005C1B0: addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    func_800194A4(rdram, ctx);
        goto after_32;
    // 0x8005C1B0: addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    after_32:
    // 0x8005C1B4: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x8005C1B8: lui         $a2, 0x907
    ctx->r6 = S32(0X907 << 16);
    // 0x8005C1BC: lw          $a0, 0xED8($s2)
    ctx->r4 = MEM_W(ctx->r18, 0XED8);
    // 0x8005C1C0: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8005C1C4: lwc1        $f0, -0x50BC($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X50BC);
    // 0x8005C1C8: addu        $a3, $a1, $zero
    ctx->r7 = ADD32(ctx->r5, 0);
    // 0x8005C1CC: jal         0x8005955C
    // 0x8005C1D0: swc1        $f0, 0xEFC($s2)
    MEM_W(0XEFC, ctx->r18) = ctx->f0.u32l;
    func_8005955C(rdram, ctx);
        goto after_33;
    // 0x8005C1D0: swc1        $f0, 0xEFC($s2)
    MEM_W(0XEFC, ctx->r18) = ctx->f0.u32l;
    after_33:
    // 0x8005C1D4: j           L_8005C2E4
    // 0x8005C1D8: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
        goto L_8005C2E4;
    // 0x8005C1D8: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
L_8005C1DC:
    // 0x8005C1DC: lui         $a0, 0x8004
    ctx->r4 = S32(0X8004 << 16);
    // 0x8005C1E0: addiu       $a0, $a0, -0x5144
    ctx->r4 = ADD32(ctx->r4, -0X5144);
    // 0x8005C1E4: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x8005C1E8: addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    // 0x8005C1EC: jal         0x8005645C
    // 0x8005C1F0: addu        $a3, $a1, $zero
    ctx->r7 = ADD32(ctx->r5, 0);
    load_hmt_and_hob(rdram, ctx);
        goto after_34;
    // 0x8005C1F0: addu        $a3, $a1, $zero
    ctx->r7 = ADD32(ctx->r5, 0);
    after_34:
    // 0x8005C1F4: lui         $a0, 0x8004
    ctx->r4 = S32(0X8004 << 16);
    // 0x8005C1F8: jal         0x80056EB0
    // 0x8005C1FC: addiu       $a0, $a0, -0x512C
    ctx->r4 = ADD32(ctx->r4, -0X512C);
    func_80056EB0(rdram, ctx);
        goto after_35;
    // 0x8005C1FC: addiu       $a0, $a0, -0x512C
    ctx->r4 = ADD32(ctx->r4, -0X512C);
    after_35:
    // 0x8005C200: sw          $v0, 0xED4($s2)
    MEM_W(0XED4, ctx->r18) = ctx->r2;
    // 0x8005C204: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8005C208: addiu       $s0, $sp, 0x40
    ctx->r16 = ADD32(ctx->r29, 0X40);
    // 0x8005C20C: lw          $v0, 0x6E08($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X6E08);
    // 0x8005C210: addiu       $s1, $s2, 0xEE0
    ctx->r17 = ADD32(ctx->r18, 0XEE0);
    // 0x8005C214: lwc1        $f0, 0x10($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X10);
    // 0x8005C218: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x8005C21C: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
    // 0x8005C220: swc1        $f0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f0.u32l;
    // 0x8005C224: lwc1        $f2, 0x18($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X18);
    // 0x8005C228: c.eq.s      $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f0.fl == ctx->f20.fl;
    // 0x8005C22C: neg.s       $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = -ctx->f2.fl;
    // 0x8005C230: bc1f        L_8005C244
    if (!c1cs) {
        // 0x8005C234: swc1        $f2, 0x48($sp)
        MEM_W(0X48, ctx->r29) = ctx->f2.u32l;
            goto L_8005C244;
    }
    // 0x8005C234: swc1        $f2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f2.u32l;
    // 0x8005C238: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8005C23C: lwc1        $f0, -0x50B8($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X50B8);
    // 0x8005C240: swc1        $f0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f0.u32l;
L_8005C244:
    // 0x8005C244: mul.s       $f2, $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x8005C248: lwc1        $f0, 0x40($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X40);
    // 0x8005C24C: mul.s       $f0, $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x8005C250: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x8005C254: sqrt.s      $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = sqrtf(ctx->f0.fl);
    // 0x8005C258: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x8005C25C: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8005C260: lwc1        $f2, -0x50B4($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X50B4);
    // 0x8005C264: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
    // 0x8005C268: div.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f2.fl);
    // 0x8005C26C: jal         0x8001CF58
    // 0x8005C270: swc1        $f0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f0.u32l;
    normalize_vector(rdram, ctx);
        goto after_36;
    // 0x8005C270: swc1        $f0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f0.u32l;
    after_36:
    // 0x8005C274: lui         $a1, 0x4190
    ctx->r5 = S32(0X4190 << 16);
    // 0x8005C278: addiu       $a0, $sp, 0x50
    ctx->r4 = ADD32(ctx->r29, 0X50);
    // 0x8005C27C: addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    // 0x8005C280: jal         0x8001CB64
    // 0x8005C284: addu        $a3, $a1, $zero
    ctx->r7 = ADD32(ctx->r5, 0);
    func_8001CB64(rdram, ctx);
        goto after_37;
    // 0x8005C284: addu        $a3, $a1, $zero
    ctx->r7 = ADD32(ctx->r5, 0);
    after_37:
    // 0x8005C288: lui         $a1, 0x40A0
    ctx->r5 = S32(0X40A0 << 16);
    // 0x8005C28C: jal         0x8001CB9C
    // 0x8005C290: addiu       $a0, $sp, 0x50
    ctx->r4 = ADD32(ctx->r29, 0X50);
    func_8001CB9C(rdram, ctx);
        goto after_38;
    // 0x8005C290: addiu       $a0, $sp, 0x50
    ctx->r4 = ADD32(ctx->r29, 0X50);
    after_38:
    // 0x8005C294: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x8005C298: jal         0x8001CDFC
    // 0x8005C29C: addiu       $a0, $sp, 0x50
    ctx->r4 = ADD32(ctx->r29, 0X50);
    func_8001CDFC(rdram, ctx);
        goto after_39;
    // 0x8005C29C: addiu       $a0, $sp, 0x50
    ctx->r4 = ADD32(ctx->r29, 0X50);
    after_39:
    // 0x8005C2A0: lui         $a1, 0x41F0
    ctx->r5 = S32(0X41F0 << 16);
    // 0x8005C2A4: jal         0x8001CCCC
    // 0x8005C2A8: addiu       $a0, $sp, 0x50
    ctx->r4 = ADD32(ctx->r29, 0X50);
    func_8001CCCC(rdram, ctx);
        goto after_40;
    // 0x8005C2A8: addiu       $a0, $sp, 0x50
    ctx->r4 = ADD32(ctx->r29, 0X50);
    after_40:
    // 0x8005C2AC: addiu       $a0, $sp, 0x50
    ctx->r4 = ADD32(ctx->r29, 0X50);
    // 0x8005C2B0: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x8005C2B4: jal         0x800194A4
    // 0x8005C2B8: addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    func_800194A4(rdram, ctx);
        goto after_41;
    // 0x8005C2B8: addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    after_41:
    // 0x8005C2BC: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x8005C2C0: lui         $a2, 0x7
    ctx->r6 = S32(0X7 << 16);
    // 0x8005C2C4: lw          $a0, 0xED4($s2)
    ctx->r4 = MEM_W(ctx->r18, 0XED4);
    // 0x8005C2C8: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8005C2CC: lwc1        $f0, -0x50B0($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X50B0);
    // 0x8005C2D0: addu        $a3, $a1, $zero
    ctx->r7 = ADD32(ctx->r5, 0);
    // 0x8005C2D4: swc1        $f0, 0xEF8($s2)
    MEM_W(0XEF8, ctx->r18) = ctx->f0.u32l;
L_8005C2D8:
    // 0x8005C2D8: jal         0x8005955C
    // 0x8005C2DC: nop

    func_8005955C(rdram, ctx);
        goto after_42;
    // 0x8005C2DC: nop

    after_42:
    // 0x8005C2E0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8005C2E4:
    // 0x8005C2E4: sw          $v0, 0xEDC($s2)
    MEM_W(0XEDC, ctx->r18) = ctx->r2;
L_8005C2E8:
    // 0x8005C2E8: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
L_8005C2EC:
    // 0x8005C2EC: lw          $v0, 0x6E08($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X6E08);
    // 0x8005C2F0: lw          $t0, 0x10($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X10);
    // 0x8005C2F4: lw          $t1, 0x14($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X14);
    // 0x8005C2F8: lw          $t2, 0x18($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X18);
    // 0x8005C2FC: sw          $t0, 0xF04($s2)
    MEM_W(0XF04, ctx->r18) = ctx->r8;
    // 0x8005C300: sw          $t1, 0xF08($s2)
    MEM_W(0XF08, ctx->r18) = ctx->r9;
    // 0x8005C304: sw          $t2, 0xF0C($s2)
    MEM_W(0XF0C, ctx->r18) = ctx->r10;
    // 0x8005C308: j           L_8005C59C
    // 0x8005C30C: sw          $zero, 0xF10($s2)
    MEM_W(0XF10, ctx->r18) = 0;
        goto L_8005C59C;
    // 0x8005C30C: sw          $zero, 0xF10($s2)
    MEM_W(0XF10, ctx->r18) = 0;
L_8005C310:
    // 0x8005C310: lw          $v0, 0xEDC($s2)
    ctx->r2 = MEM_W(ctx->r18, 0XEDC);
    // 0x8005C314: blez        $v0, L_8005C340
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8005C318: addu        $s1, $zero, $zero
        ctx->r17 = ADD32(0, 0);
            goto L_8005C340;
    }
    // 0x8005C318: addu        $s1, $zero, $zero
    ctx->r17 = ADD32(0, 0);
    // 0x8005C31C: addu        $s0, $s2, $zero
    ctx->r16 = ADD32(ctx->r18, 0);
L_8005C320:
    // 0x8005C320: lw          $a0, 0xED4($s0)
    ctx->r4 = MEM_W(ctx->r16, 0XED4);
    // 0x8005C324: jal         0x8005779C
    // 0x8005C328: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    func_8005779C(rdram, ctx);
        goto after_43;
    // 0x8005C328: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    after_43:
    // 0x8005C32C: lw          $v0, 0xEDC($s2)
    ctx->r2 = MEM_W(ctx->r18, 0XEDC);
    // 0x8005C330: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x8005C334: slt         $v0, $s1, $v0
    ctx->r2 = SIGNED(ctx->r17) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8005C338: bne         $v0, $zero, L_8005C320
    if (ctx->r2 != 0) {
        // 0x8005C33C: nop
    
            goto L_8005C320;
    }
    // 0x8005C33C: nop

L_8005C340:
    // 0x8005C340: lw          $a0, 0x18($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X18);
    // 0x8005C344: jal         0x8005779C
    // 0x8005C348: nop

    func_8005779C(rdram, ctx);
        goto after_44;
    // 0x8005C348: nop

    after_44:
    // 0x8005C34C: lw          $v0, 0xF00($s2)
    ctx->r2 = MEM_W(ctx->r18, 0XF00);
    // 0x8005C350: beq         $v0, $zero, L_8005C59C
    if (ctx->r2 == 0) {
        // 0x8005C354: nop
    
            goto L_8005C59C;
    }
    // 0x8005C354: nop

    // 0x8005C358: lw          $a0, 0x2B44($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X2B44);
    // 0x8005C35C: jal         0x80001C98
    // 0x8005C360: nop

    rs_free(rdram, ctx);
        goto after_45;
    // 0x8005C360: nop

    after_45:
    // 0x8005C364: lw          $a0, 0xF00($s2)
    ctx->r4 = MEM_W(ctx->r18, 0XF00);
    // 0x8005C368: jal         0x80001C98
    // 0x8005C36C: nop

    rs_free(rdram, ctx);
        goto after_46;
    // 0x8005C36C: nop

    after_46:
    // 0x8005C370: j           L_8005C59C
    // 0x8005C374: nop

        goto L_8005C59C;
    // 0x8005C374: nop

L_8005C378:
    // 0x8005C378: addiu       $a0, $sp, 0x50
    ctx->r4 = ADD32(ctx->r29, 0X50);
    // 0x8005C37C: lw          $a1, -0x72E4($v0)
    ctx->r5 = MEM_W(ctx->r2, -0X72E4);
    // 0x8005C380: addu        $s5, $a2, $zero
    ctx->r21 = ADD32(ctx->r6, 0);
    // 0x8005C384: jal         0x80059D18
    // 0x8005C388: addiu       $a1, $a1, 0x28
    ctx->r5 = ADD32(ctx->r5, 0X28);
    func_80059D18(rdram, ctx);
        goto after_47;
    // 0x8005C388: addiu       $a1, $a1, 0x28
    ctx->r5 = ADD32(ctx->r5, 0X28);
    after_47:
    // 0x8005C38C: lw          $v0, 0x18($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X18);
    // 0x8005C390: beq         $v0, $zero, L_8005C59C
    if (ctx->r2 == 0) {
        // 0x8005C394: addu        $s1, $zero, $zero
        ctx->r17 = ADD32(0, 0);
            goto L_8005C59C;
    }
    // 0x8005C394: addu        $s1, $zero, $zero
    ctx->r17 = ADD32(0, 0);
    // 0x8005C398: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8005C39C: lwc1        $f2, -0x50AC($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X50AC);
    // 0x8005C3A0: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8005C3A4: lwc1        $f0, -0x50A8($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X50A8);
    // 0x8005C3A8: addu        $v1, $s2, $zero
    ctx->r3 = ADD32(ctx->r18, 0);
    // 0x8005C3AC: swc1        $f0, 0x4($s2)
    MEM_W(0X4, ctx->r18) = ctx->f0.u32l;
L_8005C3B0:
    // 0x8005C3B0: lw          $v0, 0x0($s5)
    ctx->r2 = MEM_W(ctx->r21, 0X0);
    // 0x8005C3B4: lwc1        $f0, 0x28($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X28);
    // 0x8005C3B8: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x8005C3BC: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x8005C3C0: slti        $v0, $s1, 0x10
    ctx->r2 = SIGNED(ctx->r17) < 0X10 ? 1 : 0;
    // 0x8005C3C4: swc1        $f0, 0x38($v1)
    MEM_W(0X38, ctx->r3) = ctx->f0.u32l;
    // 0x8005C3C8: bne         $v0, $zero, L_8005C3B0
    if (ctx->r2 != 0) {
        // 0x8005C3CC: addiu       $v1, $v1, 0x5C
        ctx->r3 = ADD32(ctx->r3, 0X5C);
            goto L_8005C3B0;
    }
    // 0x8005C3CC: addiu       $v1, $v1, 0x5C
    ctx->r3 = ADD32(ctx->r3, 0X5C);
    // 0x8005C3D0: lwc1        $f0, 0x50($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X50);
    // 0x8005C3D4: lwc1        $f2, 0x54($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X54);
    // 0x8005C3D8: swc1        $f0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f0.u32l;
    // 0x8005C3DC: lwc1        $f0, 0xC($s2)
    ctx->f0.u32l = MEM_W(ctx->r18, 0XC);
    // 0x8005C3E0: lwc1        $f4, 0x8($s2)
    ctx->f4.u32l = MEM_W(ctx->r18, 0X8);
    // 0x8005C3E4: div.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = DIV_S(ctx->f2.fl, ctx->f0.fl);
    // 0x8005C3E8: add.s       $f2, $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f4.fl;
    // 0x8005C3EC: lwc1        $f0, 0x58($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X58);
    // 0x8005C3F0: swc1        $f0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f0.u32l;
    // 0x8005C3F4: swc1        $f2, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f2.u32l;
    // 0x8005C3F8: lw          $v0, 0xEDC($s2)
    ctx->r2 = MEM_W(ctx->r18, 0XEDC);
    // 0x8005C3FC: blez        $v0, L_8005C504
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8005C400: addu        $s1, $zero, $zero
        ctx->r17 = ADD32(0, 0);
            goto L_8005C504;
    }
    // 0x8005C400: addu        $s1, $zero, $zero
    ctx->r17 = ADD32(0, 0);
    // 0x8005C404: addiu       $s6, $sp, 0x80
    ctx->r22 = ADD32(ctx->r29, 0X80);
    // 0x8005C408: addu        $s4, $s2, $zero
    ctx->r20 = ADD32(ctx->r18, 0);
    // 0x8005C40C: addu        $s3, $s2, $zero
    ctx->r19 = ADD32(ctx->r18, 0);
L_8005C410:
    // 0x8005C410: lwc1        $f4, 0x40($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X40);
    // 0x8005C414: lwc1        $f0, 0xEE0($s3)
    ctx->f0.u32l = MEM_W(ctx->r19, 0XEE0);
    // 0x8005C418: lw          $v0, 0xED4($s4)
    ctx->r2 = MEM_W(ctx->r20, 0XED4);
    // 0x8005C41C: add.s       $f4, $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f0.fl;
    // 0x8005C420: lwc1        $f2, 0x44($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X44);
    // 0x8005C424: swc1        $f4, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->f4.u32l;
    // 0x8005C428: lwc1        $f0, 0xEE4($s3)
    ctx->f0.u32l = MEM_W(ctx->r19, 0XEE4);
    // 0x8005C42C: add.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x8005C430: lwc1        $f6, 0x48($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X48);
    // 0x8005C434: swc1        $f2, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->f2.u32l;
    // 0x8005C438: lwc1        $f0, 0xEE8($s3)
    ctx->f0.u32l = MEM_W(ctx->r19, 0XEE8);
    // 0x8005C43C: add.s       $f6, $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f0.fl;
    // 0x8005C440: lwc1        $f0, 0x50($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X50);
    // 0x8005C444: sub.s       $f4, $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f4.fl - ctx->f0.fl;
    // 0x8005C448: lwc1        $f0, 0x54($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X54);
    // 0x8005C44C: sub.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl - ctx->f0.fl;
    // 0x8005C450: lwc1        $f0, 0x58($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X58);
    // 0x8005C454: addiu       $s0, $v0, 0xC
    ctx->r16 = ADD32(ctx->r2, 0XC);
    // 0x8005C458: swc1        $f6, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->f6.u32l;
    // 0x8005C45C: sub.s       $f6, $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f6.fl - ctx->f0.fl;
    // 0x8005C460: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8005C464: lw          $v0, 0xB70($v0)
    ctx->r2 = MEM_W(ctx->r2, 0XB70);
    // 0x8005C468: neg.s       $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f4.fl = -ctx->f4.fl;
    // 0x8005C46C: swc1        $f4, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->f4.u32l;
    // 0x8005C470: neg.s       $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = -ctx->f2.fl;
    // 0x8005C474: swc1        $f2, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->f2.u32l;
    // 0x8005C478: neg.s       $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f6.fl = -ctx->f6.fl;
    // 0x8005C47C: bne         $v0, $zero, L_8005C4A0
    if (ctx->r2 != 0) {
        // 0x8005C480: swc1        $f6, 0x94($sp)
        MEM_W(0X94, ctx->r29) = ctx->f6.u32l;
            goto L_8005C4A0;
    }
    // 0x8005C480: swc1        $f6, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->f6.u32l;
    // 0x8005C484: lwc1        $f0, 0x68($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X68);
    // 0x8005C488: lwc1        $f2, 0x6C($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x8005C48C: lwc1        $f4, 0x70($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X70);
    // 0x8005C490: swc1        $f0, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->f0.u32l;
    // 0x8005C494: swc1        $f2, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->f2.u32l;
    // 0x8005C498: j           L_8005C4B4
    // 0x8005C49C: swc1        $f4, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->f4.u32l;
        goto L_8005C4B4;
    // 0x8005C49C: swc1        $f4, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->f4.u32l;
L_8005C4A0:
    // 0x8005C4A0: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8005C4A4: lwc1        $f0, -0x50A4($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X50A4);
    // 0x8005C4A8: sw          $zero, 0x98($sp)
    MEM_W(0X98, ctx->r29) = 0;
    // 0x8005C4AC: sw          $zero, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = 0;
    // 0x8005C4B0: swc1        $f0, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->f0.u32l;
L_8005C4B4:
    // 0x8005C4B4: jal         0x80059F10
    // 0x8005C4B8: addu        $a0, $s6, $zero
    ctx->r4 = ADD32(ctx->r22, 0);
    func_80059F10(rdram, ctx);
        goto after_48;
    // 0x8005C4B8: addu        $a0, $s6, $zero
    ctx->r4 = ADD32(ctx->r22, 0);
    after_48:
    // 0x8005C4BC: addiu       $a0, $s0, 0x1C
    ctx->r4 = ADD32(ctx->r16, 0X1C);
    // 0x8005C4C0: lw          $a2, 0xEF8($s4)
    ctx->r6 = MEM_W(ctx->r20, 0XEF8);
    // 0x8005C4C4: jal         0x80059B50
    // 0x8005C4C8: addu        $a1, $s6, $zero
    ctx->r5 = ADD32(ctx->r22, 0);
    func_80059B50(rdram, ctx);
        goto after_49;
    // 0x8005C4C8: addu        $a1, $s6, $zero
    ctx->r5 = ADD32(ctx->r22, 0);
    after_49:
    // 0x8005C4CC: lw          $v0, 0x4($s5)
    ctx->r2 = MEM_W(ctx->r21, 0X4);
    // 0x8005C4D0: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x8005C4D4: beq         $v0, $zero, L_8005C4E0
    if (ctx->r2 == 0) {
        // 0x8005C4D8: sw          $v0, 0x0($s0)
        MEM_W(0X0, ctx->r16) = ctx->r2;
            goto L_8005C4E0;
    }
    // 0x8005C4D8: sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
    // 0x8005C4DC: sw          $s0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r16;
L_8005C4E0:
    // 0x8005C4E0: addiu       $s4, $s4, 0x4
    ctx->r20 = ADD32(ctx->r20, 0X4);
    // 0x8005C4E4: lw          $v0, 0x4($s5)
    ctx->r2 = MEM_W(ctx->r21, 0X4);
    // 0x8005C4E8: sw          $s0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r16;
    // 0x8005C4EC: sw          $zero, 0x4($s0)
    MEM_W(0X4, ctx->r16) = 0;
    // 0x8005C4F0: lw          $v0, 0xEDC($s2)
    ctx->r2 = MEM_W(ctx->r18, 0XEDC);
    // 0x8005C4F4: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x8005C4F8: slt         $v0, $s1, $v0
    ctx->r2 = SIGNED(ctx->r17) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8005C4FC: bne         $v0, $zero, L_8005C410
    if (ctx->r2 != 0) {
        // 0x8005C500: addiu       $s3, $s3, 0xC
        ctx->r19 = ADD32(ctx->r19, 0XC);
            goto L_8005C410;
    }
    // 0x8005C500: addiu       $s3, $s3, 0xC
    ctx->r19 = ADD32(ctx->r19, 0XC);
L_8005C504:
    // 0x8005C504: lw          $v0, 0xF00($s2)
    ctx->r2 = MEM_W(ctx->r18, 0XF00);
    // 0x8005C508: beq         $v0, $zero, L_8005C528
    if (ctx->r2 == 0) {
        // 0x8005C50C: addiu       $v0, $sp, 0x40
        ctx->r2 = ADD32(ctx->r29, 0X40);
            goto L_8005C528;
    }
    // 0x8005C50C: addiu       $v0, $sp, 0x40
    ctx->r2 = ADD32(ctx->r29, 0X40);
    // 0x8005C510: addu        $a2, $s2, $zero
    ctx->r6 = ADD32(ctx->r18, 0);
    // 0x8005C514: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // 0x8005C518: lw          $a0, 0x4($s5)
    ctx->r4 = MEM_W(ctx->r21, 0X4);
    // 0x8005C51C: lw          $a1, 0x0($s5)
    ctx->r5 = MEM_W(ctx->r21, 0X0);
    // 0x8005C520: jal         0x8005A4B4
    // 0x8005C524: addiu       $a3, $sp, 0x50
    ctx->r7 = ADD32(ctx->r29, 0X50);
    func_8005A4B4(rdram, ctx);
        goto after_50;
    // 0x8005C524: addiu       $a3, $sp, 0x50
    ctx->r7 = ADD32(ctx->r29, 0X50);
    after_50:
L_8005C528:
    // 0x8005C528: lw          $s1, 0x18($s2)
    ctx->r17 = MEM_W(ctx->r18, 0X18);
    // 0x8005C52C: lw          $a1, 0x4($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X4);
    // 0x8005C530: addiu       $s0, $s1, 0x28
    ctx->r16 = ADD32(ctx->r17, 0X28);
    // 0x8005C534: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x8005C538: addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    // 0x8005C53C: jal         0x8001CB64
    // 0x8005C540: addu        $a3, $a1, $zero
    ctx->r7 = ADD32(ctx->r5, 0);
    func_8001CB64(rdram, ctx);
        goto after_51;
    // 0x8005C540: addu        $a3, $a1, $zero
    ctx->r7 = ADD32(ctx->r5, 0);
    after_51:
    // 0x8005C544: lw          $a1, 0x40($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X40);
    // 0x8005C548: lw          $a2, 0x44($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X44);
    // 0x8005C54C: lw          $a3, 0x48($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X48);
    // 0x8005C550: jal         0x8001CA90
    // 0x8005C554: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_8001CA90(rdram, ctx);
        goto after_52;
    // 0x8005C554: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_52:
    // 0x8005C558: addiu       $s0, $sp, 0x50
    ctx->r16 = ADD32(ctx->r29, 0X50);
    // 0x8005C55C: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x8005C560: jal         0x8005B3A8
    // 0x8005C564: addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    func_8005B3A8(rdram, ctx);
        goto after_53;
    // 0x8005C564: addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    after_53:
    // 0x8005C568: addu        $a0, $s5, $zero
    ctx->r4 = ADD32(ctx->r21, 0);
    // 0x8005C56C: addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    // 0x8005C570: jal         0x8005B51C
    // 0x8005C574: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    func_8005B51C(rdram, ctx);
        goto after_54;
    // 0x8005C574: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    after_54:
    // 0x8005C578: lw          $v0, 0x4($s5)
    ctx->r2 = MEM_W(ctx->r21, 0X4);
    // 0x8005C57C: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x8005C580: addiu       $s0, $s1, 0xC
    ctx->r16 = ADD32(ctx->r17, 0XC);
    // 0x8005C584: beq         $v0, $zero, L_8005C590
    if (ctx->r2 == 0) {
        // 0x8005C588: sw          $v0, 0xC($s1)
        MEM_W(0XC, ctx->r17) = ctx->r2;
            goto L_8005C590;
    }
    // 0x8005C588: sw          $v0, 0xC($s1)
    MEM_W(0XC, ctx->r17) = ctx->r2;
    // 0x8005C58C: sw          $s0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r16;
L_8005C590:
    // 0x8005C590: lw          $v0, 0x4($s5)
    ctx->r2 = MEM_W(ctx->r21, 0X4);
    // 0x8005C594: sw          $s0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r16;
    // 0x8005C598: sw          $zero, 0x4($s0)
    MEM_W(0X4, ctx->r16) = 0;
L_8005C59C:
    // 0x8005C59C: lw          $ra, 0xCC($sp)
    ctx->r31 = MEM_W(ctx->r29, 0XCC);
    // 0x8005C5A0: lw          $s6, 0xC8($sp)
    ctx->r22 = MEM_W(ctx->r29, 0XC8);
    // 0x8005C5A4: lw          $s5, 0xC4($sp)
    ctx->r21 = MEM_W(ctx->r29, 0XC4);
    // 0x8005C5A8: lw          $s4, 0xC0($sp)
    ctx->r20 = MEM_W(ctx->r29, 0XC0);
    // 0x8005C5AC: lw          $s3, 0xBC($sp)
    ctx->r19 = MEM_W(ctx->r29, 0XBC);
    // 0x8005C5B0: lw          $s2, 0xB8($sp)
    ctx->r18 = MEM_W(ctx->r29, 0XB8);
    // 0x8005C5B4: lw          $s1, 0xB4($sp)
    ctx->r17 = MEM_W(ctx->r29, 0XB4);
    // 0x8005C5B8: lw          $s0, 0xB0($sp)
    ctx->r16 = MEM_W(ctx->r29, 0XB0);
    // 0x8005C5BC: ldc1        $f22, 0xD8($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0XD8);
    // 0x8005C5C0: ldc1        $f20, 0xD0($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0XD0);
    // 0x8005C5C4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8005C5C8: jr          $ra
    // 0x8005C5CC: addiu       $sp, $sp, 0xE0
    ctx->r29 = ADD32(ctx->r29, 0XE0);
    return;
    // 0x8005C5CC: addiu       $sp, $sp, 0xE0
    ctx->r29 = ADD32(ctx->r29, 0XE0);
;}
RECOMP_FUNC void func_8005C5D0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005C5D0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8005C5D4: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x8005C5D8: addu        $s1, $zero, $zero
    ctx->r17 = ADD32(0, 0);
    // 0x8005C5DC: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x8005C5E0: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x8005C5E4: addiu       $s0, $v0, -0x6AA0
    ctx->r16 = ADD32(ctx->r2, -0X6AA0);
    // 0x8005C5E8: sw          $ra, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r31;
L_8005C5EC:
    // 0x8005C5EC: jal         0x8003E5F8
    // 0x8005C5F0: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    func_8003E5F8(rdram, ctx);
        goto after_0;
    // 0x8005C5F0: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    after_0:
    // 0x8005C5F4: sh          $v0, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r2;
    // 0x8005C5F8: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x8005C5FC: slti        $v0, $s1, 0x20
    ctx->r2 = SIGNED(ctx->r17) < 0X20 ? 1 : 0;
    // 0x8005C600: bne         $v0, $zero, L_8005C5EC
    if (ctx->r2 != 0) {
        // 0x8005C604: addiu       $s0, $s0, 0x2
        ctx->r16 = ADD32(ctx->r16, 0X2);
            goto L_8005C5EC;
    }
    // 0x8005C604: addiu       $s0, $s0, 0x2
    ctx->r16 = ADD32(ctx->r16, 0X2);
    // 0x8005C608: lw          $ra, 0x18($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X18);
    // 0x8005C60C: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x8005C610: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x8005C614: jr          $ra
    // 0x8005C618: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x8005C618: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void fake_func_8005C61C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
;}
RECOMP_FUNC void func_8005C620(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005C620: addiu       $sp, $sp, -0x90
    ctx->r29 = ADD32(ctx->r29, -0X90);
    // 0x8005C624: sw          $s3, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r19;
    // 0x8005C628: addu        $s3, $a0, $zero
    ctx->r19 = ADD32(ctx->r4, 0);
    // 0x8005C62C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8005C630: sw          $ra, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r31;
    // 0x8005C634: sw          $s2, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r18;
    // 0x8005C638: sw          $s1, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r17;
    // 0x8005C63C: sw          $s0, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r16;
    // 0x8005C640: sdc1        $f20, 0x88($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X88, ctx->r29);
    // 0x8005C644: lbu         $v1, 0x11C($s3)
    ctx->r3 = MEM_BU(ctx->r19, 0X11C);
    // 0x8005C648: mtc1        $a1, $f20
    ctx->f20.u32l = ctx->r5;
    // 0x8005C64C: bne         $v1, $v0, L_8005C854
    if (ctx->r3 != ctx->r2) {
        // 0x8005C650: nop
    
            goto L_8005C854;
    }
    // 0x8005C650: nop

    // 0x8005C654: lhu         $a0, 0x118($s3)
    ctx->r4 = MEM_HU(ctx->r19, 0X118);
    // 0x8005C658: jal         0x8003FC28
    // 0x8005C65C: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    func_8003FC28(rdram, ctx);
        goto after_0;
    // 0x8005C65C: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    after_0:
    // 0x8005C660: andi        $a0, $v0, 0xFFFF
    ctx->r4 = ctx->r2 & 0XFFFF;
    // 0x8005C664: ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
    // 0x8005C668: beql        $a0, $v0, L_8005C854
    if (ctx->r4 == ctx->r2) {
        // 0x8005C66C: sb          $zero, 0x11C($s3)
        MEM_B(0X11C, ctx->r19) = 0;
            goto L_8005C854;
    }
    goto skip_0;
    // 0x8005C66C: sb          $zero, 0x11C($s3)
    MEM_B(0X11C, ctx->r19) = 0;
    skip_0:
    // 0x8005C670: jal         0x8004013C
    // 0x8005C674: nop

    func_8004013C(rdram, ctx);
        goto after_1;
    // 0x8005C674: nop

    after_1:
    // 0x8005C678: lw          $v1, 0x8($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X8);
    // 0x8005C67C: addiu       $a1, $sp, 0x10
    ctx->r5 = ADD32(ctx->r29, 0X10);
    // 0x8005C680: addiu       $a2, $v1, 0x30
    ctx->r6 = ADD32(ctx->r3, 0X30);
L_8005C684:
    // 0x8005C684: lw          $a3, 0x0($v1)
    ctx->r7 = MEM_W(ctx->r3, 0X0);
    // 0x8005C688: lw          $t0, 0x4($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X4);
    // 0x8005C68C: lw          $t1, 0x8($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X8);
    // 0x8005C690: lw          $t2, 0xC($v1)
    ctx->r10 = MEM_W(ctx->r3, 0XC);
    // 0x8005C694: sw          $a3, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r7;
    // 0x8005C698: sw          $t0, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r8;
    // 0x8005C69C: sw          $t1, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->r9;
    // 0x8005C6A0: sw          $t2, 0xC($a1)
    MEM_W(0XC, ctx->r5) = ctx->r10;
    // 0x8005C6A4: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
    // 0x8005C6A8: bne         $v1, $a2, L_8005C684
    if (ctx->r3 != ctx->r6) {
        // 0x8005C6AC: addiu       $a1, $a1, 0x10
        ctx->r5 = ADD32(ctx->r5, 0X10);
            goto L_8005C684;
    }
    // 0x8005C6AC: addiu       $a1, $a1, 0x10
    ctx->r5 = ADD32(ctx->r5, 0X10);
    // 0x8005C6B0: lw          $a0, 0xC($v0)
    ctx->r4 = MEM_W(ctx->r2, 0XC);
    // 0x8005C6B4: beq         $a0, $zero, L_8005C6C4
    if (ctx->r4 == 0) {
        // 0x8005C6B8: nop
    
            goto L_8005C6C4;
    }
    // 0x8005C6B8: nop

    // 0x8005C6BC: jal         0x8006AC7C
    // 0x8005C6C0: addiu       $a1, $sp, 0x10
    ctx->r5 = ADD32(ctx->r29, 0X10);
    func_8006AC7C(rdram, ctx);
        goto after_2;
    // 0x8005C6C0: addiu       $a1, $sp, 0x10
    ctx->r5 = ADD32(ctx->r29, 0X10);
    after_2:
L_8005C6C4:
    // 0x8005C6C4: lwc1        $f0, 0x10($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X10);
    // 0x8005C6C8: lwc1        $f2, 0xB4($s3)
    ctx->f2.u32l = MEM_W(ctx->r19, 0XB4);
    // 0x8005C6CC: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x8005C6D0: lwc1        $f2, 0x14($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X14);
    // 0x8005C6D4: addiu       $s0, $sp, 0x50
    ctx->r16 = ADD32(ctx->r29, 0X50);
    // 0x8005C6D8: swc1        $f0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f0.u32l;
    // 0x8005C6DC: lwc1        $f0, 0xB8($s3)
    ctx->f0.u32l = MEM_W(ctx->r19, 0XB8);
    // 0x8005C6E0: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x8005C6E4: sub.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl - ctx->f0.fl;
    // 0x8005C6E8: lwc1        $f0, 0x18($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X18);
    // 0x8005C6EC: addiu       $s2, $s3, 0xC0
    ctx->r18 = ADD32(ctx->r19, 0XC0);
    // 0x8005C6F0: swc1        $f2, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f2.u32l;
    // 0x8005C6F4: lwc1        $f2, 0xBC($s3)
    ctx->f2.u32l = MEM_W(ctx->r19, 0XBC);
    // 0x8005C6F8: addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    // 0x8005C6FC: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x8005C700: addiu       $s1, $sp, 0x40
    ctx->r17 = ADD32(ctx->r29, 0X40);
    // 0x8005C704: addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    // 0x8005C708: jal         0x80019548
    // 0x8005C70C: swc1        $f0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f0.u32l;
    func_80019548(rdram, ctx);
        goto after_3;
    // 0x8005C70C: swc1        $f0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f0.u32l;
    after_3:
    // 0x8005C710: jal         0x8001CF2C
    // 0x8005C714: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_8001CF2C(rdram, ctx);
        goto after_4;
    // 0x8005C714: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_4:
    // 0x8005C718: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8005C71C: lwc1        $f2, -0x5068($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X5068);
    // 0x8005C720: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x8005C724: nop

    // 0x8005C728: bc1f        L_8005C82C
    if (!c1cs) {
        // 0x8005C72C: nop
    
            goto L_8005C82C;
    }
    // 0x8005C72C: nop

    // 0x8005C730: lwc1        $f0, 0x114($s3)
    ctx->f0.u32l = MEM_W(ctx->r19, 0X114);
    // 0x8005C734: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8005C738: lwc1        $f2, -0x5064($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X5064);
    // 0x8005C73C: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x8005C740: nop

    // 0x8005C744: mul.s       $f20, $f0, $f20
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f20.fl = MUL_S(ctx->f0.fl, ctx->f20.fl);
    // 0x8005C748: jal         0x8001CF58
    // 0x8005C74C: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    normalize_vector(rdram, ctx);
        goto after_5;
    // 0x8005C74C: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    after_5:
    // 0x8005C750: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x8005C754: jal         0x8001CFE8
    // 0x8005C758: addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    func_8001CFE8(rdram, ctx);
        goto after_6;
    // 0x8005C758: addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    after_6:
    // 0x8005C75C: jal         0x8001C5CC
    // 0x8005C760: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    func_8001C5CC(rdram, ctx);
        goto after_7;
    // 0x8005C760: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    after_7:
    // 0x8005C764: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8005C768: lwc1        $f2, -0x5060($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X5060);
    // 0x8005C76C: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x8005C770: c.lt.s      $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f20.fl < ctx->f0.fl;
    // 0x8005C774: nop

    // 0x8005C778: bc1fl       L_8005C788
    if (!c1cs) {
        // 0x8005C77C: neg.s       $f2, $f20
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); 
    ctx->f2.fl = -ctx->f20.fl;
            goto L_8005C788;
    }
    goto skip_1;
    // 0x8005C77C: neg.s       $f2, $f20
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); 
    ctx->f2.fl = -ctx->f20.fl;
    skip_1:
    // 0x8005C780: j           L_8005C798
    // 0x8005C784: mov.s       $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    ctx->f0.fl = ctx->f20.fl;
        goto L_8005C798;
    // 0x8005C784: mov.s       $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    ctx->f0.fl = ctx->f20.fl;
L_8005C788:
    // 0x8005C788: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x8005C78C: nop

    // 0x8005C790: bc1tl       L_8005C798
    if (c1cs) {
        // 0x8005C794: mov.s       $f0, $f2
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
            goto L_8005C798;
    }
    goto skip_2;
    // 0x8005C794: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    skip_2:
L_8005C798:
    // 0x8005C798: addiu       $s0, $sp, 0x60
    ctx->r16 = ADD32(ctx->r29, 0X60);
    // 0x8005C79C: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x8005C7A0: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8005C7A4: jal         0x8001D144
    // 0x8005C7A8: addiu       $a1, $sp, 0x50
    ctx->r5 = ADD32(ctx->r29, 0X50);
    func_8001D144(rdram, ctx);
        goto after_8;
    // 0x8005C7A8: addiu       $a1, $sp, 0x50
    ctx->r5 = ADD32(ctx->r29, 0X50);
    after_8:
    // 0x8005C7AC: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x8005C7B0: addiu       $s2, $s3, 0xC0
    ctx->r18 = ADD32(ctx->r19, 0XC0);
    // 0x8005C7B4: addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    // 0x8005C7B8: addiu       $s1, $sp, 0x40
    ctx->r17 = ADD32(ctx->r29, 0X40);
    // 0x8005C7BC: jal         0x8001D3C4
    // 0x8005C7C0: addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    func_8001D3C4(rdram, ctx);
        goto after_9;
    // 0x8005C7C0: addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    after_9:
    // 0x8005C7C4: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x8005C7C8: addiu       $a1, $s3, 0xCC
    ctx->r5 = ADD32(ctx->r19, 0XCC);
    // 0x8005C7CC: lw          $a3, 0x40($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X40);
    // 0x8005C7D0: lw          $t0, 0x44($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X44);
    // 0x8005C7D4: lw          $t1, 0x48($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X48);
    // 0x8005C7D8: sw          $a3, 0xC0($s3)
    MEM_W(0XC0, ctx->r19) = ctx->r7;
    // 0x8005C7DC: sw          $t0, 0xC4($s3)
    MEM_W(0XC4, ctx->r19) = ctx->r8;
    // 0x8005C7E0: sw          $t1, 0xC8($s3)
    MEM_W(0XC8, ctx->r19) = ctx->r9;
    // 0x8005C7E4: jal         0x8001D3C4
    // 0x8005C7E8: addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    func_8001D3C4(rdram, ctx);
        goto after_10;
    // 0x8005C7E8: addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    after_10:
    // 0x8005C7EC: lw          $a3, 0x40($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X40);
    // 0x8005C7F0: lw          $t0, 0x44($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X44);
    // 0x8005C7F4: lw          $t1, 0x48($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X48);
    // 0x8005C7F8: sw          $a3, 0xCC($s3)
    MEM_W(0XCC, ctx->r19) = ctx->r7;
    // 0x8005C7FC: sw          $t0, 0xD0($s3)
    MEM_W(0XD0, ctx->r19) = ctx->r8;
    // 0x8005C800: sw          $t1, 0xD4($s3)
    MEM_W(0XD4, ctx->r19) = ctx->r9;
    // 0x8005C804: jal         0x80059F10
    // 0x8005C808: addiu       $a0, $s3, 0xB4
    ctx->r4 = ADD32(ctx->r19, 0XB4);
    func_80059F10(rdram, ctx);
        goto after_11;
    // 0x8005C808: addiu       $a0, $s3, 0xB4
    ctx->r4 = ADD32(ctx->r19, 0XB4);
    after_11:
    // 0x8005C80C: addiu       $a0, $s3, 0x100
    ctx->r4 = ADD32(ctx->r19, 0X100);
    // 0x8005C810: jal         0x8001CFE8
    // 0x8005C814: addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    func_8001CFE8(rdram, ctx);
        goto after_12;
    // 0x8005C814: addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    after_12:
    // 0x8005C818: lwc1        $f2, 0x110($s3)
    ctx->f2.u32l = MEM_W(ctx->r19, 0X110);
    // 0x8005C81C: c.le.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl <= ctx->f2.fl;
    // 0x8005C820: nop

    // 0x8005C824: bc1tl       L_8005C82C
    if (c1cs) {
        // 0x8005C828: sb          $zero, 0x11C($s3)
        MEM_B(0X11C, ctx->r19) = 0;
            goto L_8005C82C;
    }
    goto skip_3;
    // 0x8005C828: sb          $zero, 0x11C($s3)
    MEM_B(0X11C, ctx->r19) = 0;
    skip_3:
L_8005C82C:
    // 0x8005C82C: lwc1        $f6, 0xC0($s3)
    ctx->f6.u32l = MEM_W(ctx->r19, 0XC0);
    // 0x8005C830: lwc1        $f0, 0x10C($s3)
    ctx->f0.u32l = MEM_W(ctx->r19, 0X10C);
    // 0x8005C834: mul.s       $f6, $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x8005C838: lwc1        $f4, 0xC4($s3)
    ctx->f4.u32l = MEM_W(ctx->r19, 0XC4);
    // 0x8005C83C: mul.s       $f4, $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x8005C840: lwc1        $f2, 0xC8($s3)
    ctx->f2.u32l = MEM_W(ctx->r19, 0XC8);
    // 0x8005C844: mul.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x8005C848: swc1        $f6, 0xD8($s3)
    MEM_W(0XD8, ctx->r19) = ctx->f6.u32l;
    // 0x8005C84C: swc1        $f4, 0xDC($s3)
    MEM_W(0XDC, ctx->r19) = ctx->f4.u32l;
    // 0x8005C850: swc1        $f2, 0xE0($s3)
    MEM_W(0XE0, ctx->r19) = ctx->f2.u32l;
L_8005C854:
    // 0x8005C854: lw          $ra, 0x80($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X80);
    // 0x8005C858: lw          $s3, 0x7C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X7C);
    // 0x8005C85C: lw          $s2, 0x78($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X78);
    // 0x8005C860: lw          $s1, 0x74($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X74);
    // 0x8005C864: lw          $s0, 0x70($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X70);
    // 0x8005C868: ldc1        $f20, 0x88($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X88);
    // 0x8005C86C: jr          $ra
    // 0x8005C870: addiu       $sp, $sp, 0x90
    ctx->r29 = ADD32(ctx->r29, 0X90);
    return;
    // 0x8005C870: addiu       $sp, $sp, 0x90
    ctx->r29 = ADD32(ctx->r29, 0X90);
;}
RECOMP_FUNC void func_8005C874(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005C874: addiu       $sp, $sp, -0xD8
    ctx->r29 = ADD32(ctx->r29, -0XD8);
    // 0x8005C878: sw          $s6, 0xC0($sp)
    MEM_W(0XC0, ctx->r29) = ctx->r22;
    // 0x8005C87C: addu        $s6, $a0, $zero
    ctx->r22 = ADD32(ctx->r4, 0);
    // 0x8005C880: sw          $s2, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->r18;
    // 0x8005C884: andi        $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 & 0XFFFF;
    // 0x8005C888: addiu       $v1, $a1, -0x1
    ctx->r3 = ADD32(ctx->r5, -0X1);
    // 0x8005C88C: sltiu       $v0, $v1, 0xB
    ctx->r2 = ctx->r3 < 0XB ? 1 : 0;
    // 0x8005C890: sw          $ra, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->r31;
    // 0x8005C894: sw          $fp, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->r30;
    // 0x8005C898: sw          $s7, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->r23;
    // 0x8005C89C: sw          $s5, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->r21;
    // 0x8005C8A0: sw          $s4, 0xB8($sp)
    MEM_W(0XB8, ctx->r29) = ctx->r20;
    // 0x8005C8A4: sw          $s3, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->r19;
    // 0x8005C8A8: sw          $s1, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->r17;
    // 0x8005C8AC: sw          $s0, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->r16;
    // 0x8005C8B0: sdc1        $f20, 0xD0($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0XD0, ctx->r29);
    // 0x8005C8B4: lw          $s1, 0x4($s6)
    ctx->r17 = MEM_W(ctx->r22, 0X4);
    // 0x8005C8B8: beq         $v0, $zero, L_8005D914
    if (ctx->r2 == 0) {
        // 0x8005C8BC: addu        $s2, $a2, $zero
        ctx->r18 = ADD32(ctx->r6, 0);
            goto L_8005D914;
    }
    // 0x8005C8BC: addu        $s2, $a2, $zero
    ctx->r18 = ADD32(ctx->r6, 0);
    // 0x8005C8C0: lui         $v0, 0x8004
    ctx->r2 = S32(0X8004 << 16);
    // 0x8005C8C4: addiu       $v0, $v0, -0x5058
    ctx->r2 = ADD32(ctx->r2, -0X5058);
    // 0x8005C8C8: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x8005C8CC: addu        $v1, $v1, $v0
    gpr jr_addend_8005C8D4 = ctx->r3;
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x8005C8D0: lw          $v0, 0x0($v1)
    ctx->r2 = ADD32(ctx->r3, 0X0);
    // 0x8005C8D4: jr          $v0
    // 0x8005C8D8: nop

    switch (jr_addend_8005C8D4 >> 2) {
        case 0: goto L_8005C8DC; break;
        case 1: goto L_8005CCD0; break;
        case 2: goto L_8005CDA4; break;
        case 3: goto L_8005D6EC; break;
        case 4: goto L_8005D914; break;
        case 5: goto L_8005D914; break;
        case 6: goto L_8005D914; break;
        case 7: goto L_8005D914; break;
        case 8: goto L_8005D914; break;
        case 9: goto L_8005D71C; break;
        case 10: goto L_8005D8F8; break;
        default: switch_error(__func__, 0x8005C8D4, 0x8003AFA8);
    }
    // 0x8005C8D8: nop

L_8005C8DC:
    // 0x8005C8DC: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x8005C8E0: jal         0x8006C994
    // 0x8005C8E4: addu        $s0, $s2, $zero
    ctx->r16 = ADD32(ctx->r18, 0);
    func_8006C994(rdram, ctx);
        goto after_0;
    // 0x8005C8E4: addu        $s0, $s2, $zero
    ctx->r16 = ADD32(ctx->r18, 0);
    after_0:
    // 0x8005C8E8: addu        $s2, $v0, $zero
    ctx->r18 = ADD32(ctx->r2, 0);
    // 0x8005C8EC: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x8005C8F0: lbu         $v1, -0x68C6($v0)
    ctx->r3 = MEM_BU(ctx->r2, -0X68C6);
    // 0x8005C8F4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8005C8F8: beq         $v1, $v0, L_8005C914
    if (ctx->r3 == ctx->r2) {
        // 0x8005C8FC: nop
    
            goto L_8005C914;
    }
    // 0x8005C8FC: nop

    // 0x8005C900: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x8005C904: beq         $v1, $v0, L_8005C920
    if (ctx->r3 == ctx->r2) {
        // 0x8005C908: lui         $v0, 0x5555
        ctx->r2 = S32(0X5555 << 16);
            goto L_8005C920;
    }
    // 0x8005C908: lui         $v0, 0x5555
    ctx->r2 = S32(0X5555 << 16);
    // 0x8005C90C: j           L_8005C934
    // 0x8005C910: lui         $a1, 0x8014
    ctx->r5 = S32(0X8014 << 16);
        goto L_8005C934;
    // 0x8005C910: lui         $a1, 0x8014
    ctx->r5 = S32(0X8014 << 16);
L_8005C914:
    // 0x8005C914: lhu         $v0, 0x14($s6)
    ctx->r2 = MEM_HU(ctx->r22, 0X14);
    // 0x8005C918: j           L_8005C928
    // 0x8005C91C: ori         $v0, $v0, 0x200
    ctx->r2 = ctx->r2 | 0X200;
        goto L_8005C928;
    // 0x8005C91C: ori         $v0, $v0, 0x200
    ctx->r2 = ctx->r2 | 0X200;
L_8005C920:
    // 0x8005C920: lhu         $v0, 0x14($s6)
    ctx->r2 = MEM_HU(ctx->r22, 0X14);
    // 0x8005C924: ori         $v0, $v0, 0x400
    ctx->r2 = ctx->r2 | 0X400;
L_8005C928:
    // 0x8005C928: sh          $v0, 0x14($s6)
    MEM_H(0X14, ctx->r22) = ctx->r2;
    // 0x8005C92C: lui         $v0, 0x5555
    ctx->r2 = S32(0X5555 << 16);
    // 0x8005C930: lui         $a1, 0x8014
    ctx->r5 = S32(0X8014 << 16);
L_8005C934:
    // 0x8005C934: lbu         $a0, -0x68C6($a1)
    ctx->r4 = MEM_BU(ctx->r5, -0X68C6);
    // 0x8005C938: ori         $v0, $v0, 0x5556
    ctx->r2 = ctx->r2 | 0X5556;
    // 0x8005C93C: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x8005C940: mult        $a0, $v0
    result = S64(S32(ctx->r4)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8005C944: lw          $v0, 0x14($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X14);
    // 0x8005C948: sra         $v1, $a0, 31
    ctx->r3 = S32(SIGNED(ctx->r4) >> 31);
    // 0x8005C94C: andi        $a2, $v0, 0x1F
    ctx->r6 = ctx->r2 & 0X1F;
    // 0x8005C950: sw          $a2, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->r6;
    // 0x8005C954: mfhi        $t0
    ctx->r8 = hi;
    // 0x8005C958: subu        $v1, $t0, $v1
    ctx->r3 = SUB32(ctx->r8, ctx->r3);
    // 0x8005C95C: sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3 << 1);
    // 0x8005C960: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8005C964: subu        $a0, $a0, $v0
    ctx->r4 = SUB32(ctx->r4, ctx->r2);
    // 0x8005C968: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8005C96C: beq         $a2, $v0, L_8005C98C
    if (ctx->r6 == ctx->r2) {
        // 0x8005C970: sb          $a0, -0x68C6($a1)
        MEM_B(-0X68C6, ctx->r5) = ctx->r4;
            goto L_8005C98C;
    }
    // 0x8005C970: sb          $a0, -0x68C6($a1)
    MEM_B(-0X68C6, ctx->r5) = ctx->r4;
    // 0x8005C974: beq         $a2, $zero, L_8005C9A0
    if (ctx->r6 == 0) {
        // 0x8005C978: slti        $v0, $a2, 0x6
        ctx->r2 = SIGNED(ctx->r6) < 0X6 ? 1 : 0;
            goto L_8005C9A0;
    }
    // 0x8005C978: slti        $v0, $a2, 0x6
    ctx->r2 = SIGNED(ctx->r6) < 0X6 ? 1 : 0;
    // 0x8005C97C: beq         $v0, $zero, L_8005C9A0
    if (ctx->r2 == 0) {
        // 0x8005C980: slti        $v0, $a2, 0x4
        ctx->r2 = SIGNED(ctx->r6) < 0X4 ? 1 : 0;
            goto L_8005C9A0;
    }
    // 0x8005C980: slti        $v0, $a2, 0x4
    ctx->r2 = SIGNED(ctx->r6) < 0X4 ? 1 : 0;
    // 0x8005C984: bne         $v0, $zero, L_8005C9A4
    if (ctx->r2 != 0) {
        // 0x8005C988: lui         $v1, 0x8014
        ctx->r3 = S32(0X8014 << 16);
            goto L_8005C9A4;
    }
    // 0x8005C988: lui         $v1, 0x8014
    ctx->r3 = S32(0X8014 << 16);
L_8005C98C:
    // 0x8005C98C: addiu       $a0, $zero, 0x120
    ctx->r4 = ADD32(0, 0X120);
    // 0x8005C990: jal         0x80001ACC
    // 0x8005C994: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    rs_malloc(rdram, ctx);
        goto after_1;
    // 0x8005C994: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    after_1:
    // 0x8005C998: sw          $v0, 0x4($s6)
    MEM_W(0X4, ctx->r22) = ctx->r2;
    // 0x8005C99C: addu        $s1, $v0, $zero
    ctx->r17 = ADD32(ctx->r2, 0);
L_8005C9A0:
    // 0x8005C9A0: lui         $v1, 0x8014
    ctx->r3 = S32(0X8014 << 16);
L_8005C9A4:
    // 0x8005C9A4: lw          $v0, 0x14($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X14);
    // 0x8005C9A8: addiu       $v1, $v1, -0x6A20
    ctx->r3 = ADD32(ctx->r3, -0X6A20);
    // 0x8005C9AC: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8005C9B0: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8005C9B4: lw          $a0, 0x0($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X0);
    // 0x8005C9B8: jal         0x80059294
    // 0x8005C9BC: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    func_80059294(rdram, ctx);
        goto after_2;
    // 0x8005C9BC: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    after_2:
    // 0x8005C9C0: lhu         $v1, 0x18($s0)
    ctx->r3 = MEM_HU(ctx->r16, 0X18);
    // 0x8005C9C4: andi        $v0, $s2, 0xFFFF
    ctx->r2 = ctx->r18 & 0XFFFF;
    // 0x8005C9C8: bnel        $v1, $v0, L_8005C9DC
    if (ctx->r3 != ctx->r2) {
        // 0x8005C9CC: lui         $v0, 0x800A
        ctx->r2 = S32(0X800A << 16);
            goto L_8005C9DC;
    }
    goto skip_0;
    // 0x8005C9CC: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    skip_0:
    // 0x8005C9D0: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x8005C9D4: j           L_8005C9E0
    // 0x8005C9D8: addiu       $v0, $v0, -0x12BC
    ctx->r2 = ADD32(ctx->r2, -0X12BC);
        goto L_8005C9E0;
    // 0x8005C9D8: addiu       $v0, $v0, -0x12BC
    ctx->r2 = ADD32(ctx->r2, -0X12BC);
L_8005C9DC:
    // 0x8005C9DC: addiu       $v0, $v0, -0x12C4
    ctx->r2 = ADD32(ctx->r2, -0X12C4);
L_8005C9E0:
    // 0x8005C9E0: sw          $v0, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->r2;
    // 0x8005C9E4: lw          $v0, 0xC($s0)
    ctx->r2 = MEM_W(ctx->r16, 0XC);
    // 0x8005C9E8: addiu       $v1, $s1, 0xB4
    ctx->r3 = ADD32(ctx->r17, 0XB4);
    // 0x8005C9EC: addiu       $a0, $v0, 0x30
    ctx->r4 = ADD32(ctx->r2, 0X30);
L_8005C9F0:
    // 0x8005C9F0: lw          $t1, 0x0($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X0);
    // 0x8005C9F4: lw          $t2, 0x4($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X4);
    // 0x8005C9F8: lw          $t3, 0x8($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X8);
    // 0x8005C9FC: lw          $t0, 0xC($v0)
    ctx->r8 = MEM_W(ctx->r2, 0XC);
    // 0x8005CA00: sw          $t1, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r9;
    // 0x8005CA04: sw          $t2, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r10;
    // 0x8005CA08: sw          $t3, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r11;
    // 0x8005CA0C: sw          $t0, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r8;
    // 0x8005CA10: addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
    // 0x8005CA14: bne         $v0, $a0, L_8005C9F0
    if (ctx->r2 != ctx->r4) {
        // 0x8005CA18: addiu       $v1, $v1, 0x10
        ctx->r3 = ADD32(ctx->r3, 0X10);
            goto L_8005C9F0;
    }
    // 0x8005CA18: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
    // 0x8005CA1C: lwc1        $f0, 0xC0($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0XC0);
    // 0x8005CA20: lwc1        $f2, 0x10($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X10);
    // 0x8005CA24: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x8005CA28: swc1        $f0, 0xD8($s1)
    MEM_W(0XD8, ctx->r17) = ctx->f0.u32l;
    // 0x8005CA2C: lwc1        $f0, 0xC4($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0XC4);
    // 0x8005CA30: lwc1        $f2, 0x10($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X10);
    // 0x8005CA34: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x8005CA38: swc1        $f0, 0xDC($s1)
    MEM_W(0XDC, ctx->r17) = ctx->f0.u32l;
    // 0x8005CA3C: lwc1        $f0, 0xC8($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0XC8);
    // 0x8005CA40: lwc1        $f2, 0x10($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X10);
    // 0x8005CA44: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x8005CA48: swc1        $f0, 0xE0($s1)
    MEM_W(0XE0, ctx->r17) = ctx->f0.u32l;
    // 0x8005CA4C: lwc1        $f0, 0x0($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X0);
    // 0x8005CA50: swc1        $f0, 0xE4($s1)
    MEM_W(0XE4, ctx->r17) = ctx->f0.u32l;
    // 0x8005CA54: lwc1        $f0, 0x4($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X4);
    // 0x8005CA58: swc1        $f0, 0xE8($s1)
    MEM_W(0XE8, ctx->r17) = ctx->f0.u32l;
    // 0x8005CA5C: lwc1        $f0, 0x8($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8005CA60: addiu       $v0, $s1, 0xB4
    ctx->r2 = ADD32(ctx->r17, 0XB4);
    // 0x8005CA64: swc1        $f0, 0xEC($s1)
    MEM_W(0XEC, ctx->r17) = ctx->f0.u32l;
    // 0x8005CA68: sw          $v0, 0x8($s6)
    MEM_W(0X8, ctx->r22) = ctx->r2;
    // 0x8005CA6C: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x8005CA70: lwc1        $f8, 0x48($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X48);
    // 0x8005CA74: sqrt.s      $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = sqrtf(ctx->f8.fl);
    // 0x8005CA78: lwc1        $f0, 0xEC($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0XEC);
    // 0x8005CA7C: mul.s       $f4, $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x8005CA80: lwc1        $f0, 0xC0($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0XC0);
    // 0x8005CA84: mul.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x8005CA88: lw          $v0, 0xC($s0)
    ctx->r2 = MEM_W(ctx->r16, 0XC);
    // 0x8005CA8C: lwc1        $f2, 0x0($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8005CA90: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8005CA94: lwc1        $f6, -0x502C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X502C);
    // 0x8005CA98: add.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x8005CA9C: lwc1        $f0, 0xD8($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0XD8);
    // 0x8005CAA0: div.s       $f0, $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f6.fl);
    // 0x8005CAA4: add.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x8005CAA8: lwc1        $f0, 0xC4($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0XC4);
    // 0x8005CAAC: mul.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x8005CAB0: swc1        $f2, 0xB4($s1)
    MEM_W(0XB4, ctx->r17) = ctx->f2.u32l;
    // 0x8005CAB4: lw          $v0, 0xC($s0)
    ctx->r2 = MEM_W(ctx->r16, 0XC);
    // 0x8005CAB8: lwc1        $f2, 0x4($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X4);
    // 0x8005CABC: add.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x8005CAC0: lwc1        $f0, 0xDC($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0XDC);
    // 0x8005CAC4: div.s       $f0, $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f6.fl);
    // 0x8005CAC8: add.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x8005CACC: lwc1        $f0, 0xC8($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0XC8);
    // 0x8005CAD0: mul.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x8005CAD4: swc1        $f2, 0xB8($s1)
    MEM_W(0XB8, ctx->r17) = ctx->f2.u32l;
    // 0x8005CAD8: lw          $v0, 0xC($s0)
    ctx->r2 = MEM_W(ctx->r16, 0XC);
    // 0x8005CADC: lwc1        $f2, 0x8($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X8);
    // 0x8005CAE0: add.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x8005CAE4: lwc1        $f0, 0xE0($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0XE0);
    // 0x8005CAE8: div.s       $f0, $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f6.fl);
    // 0x8005CAEC: add.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x8005CAF0: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8005CAF4: lwc1        $f0, -0x5028($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X5028);
    // 0x8005CAF8: swc1        $f2, 0xBC($s1)
    MEM_W(0XBC, ctx->r17) = ctx->f2.u32l;
    // 0x8005CAFC: lhu         $v0, 0x1C($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X1C);
    // 0x8005CB00: sh          $v0, 0xFC($s1)
    MEM_H(0XFC, ctx->r17) = ctx->r2;
    // 0x8005CB04: lhu         $v0, 0x18($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X18);
    // 0x8005CB08: sw          $zero, 0xF0($s1)
    MEM_W(0XF0, ctx->r17) = 0;
    // 0x8005CB0C: swc1        $f0, 0xF4($s1)
    MEM_W(0XF4, ctx->r17) = ctx->f0.u32l;
    // 0x8005CB10: sh          $v0, 0xF8($s1)
    MEM_H(0XF8, ctx->r17) = ctx->r2;
    // 0x8005CB14: andi        $v1, $v0, 0xFFFF
    ctx->r3 = ctx->r2 & 0XFFFF;
    // 0x8005CB18: andi        $v0, $s2, 0xFFFF
    ctx->r2 = ctx->r18 & 0XFFFF;
    // 0x8005CB1C: bne         $v1, $v0, L_8005CB30
    if (ctx->r3 != ctx->r2) {
        // 0x8005CB20: addiu       $v0, $zero, 0xFF
        ctx->r2 = ADD32(0, 0XFF);
            goto L_8005CB30;
    }
    // 0x8005CB20: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // 0x8005CB24: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8005CB28: lwc1        $f0, -0x5024($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X5024);
    // 0x8005CB2C: swc1        $f0, 0xF4($s1)
    MEM_W(0XF4, ctx->r17) = ctx->f0.u32l;
L_8005CB30:
    // 0x8005CB30: sb          $v0, 0xFF($s1)
    MEM_B(0XFF, ctx->r17) = ctx->r2;
    // 0x8005CB34: lbu         $v0, 0x17($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X17);
    // 0x8005CB38: sb          $v0, 0xFE($s1)
    MEM_B(0XFE, ctx->r17) = ctx->r2;
    // 0x8005CB3C: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x8005CB40: addiu       $v1, $v0, -0x1
    ctx->r3 = ADD32(ctx->r2, -0X1);
    // 0x8005CB44: sltiu       $v0, $v1, 0x6
    ctx->r2 = ctx->r3 < 0X6 ? 1 : 0;
    // 0x8005CB48: beq         $v0, $zero, L_8005CB8C
    if (ctx->r2 == 0) {
        // 0x8005CB4C: lui         $v0, 0x8004
        ctx->r2 = S32(0X8004 << 16);
            goto L_8005CB8C;
    }
    // 0x8005CB4C: lui         $v0, 0x8004
    ctx->r2 = S32(0X8004 << 16);
    // 0x8005CB50: addiu       $v0, $v0, -0x5020
    ctx->r2 = ADD32(ctx->r2, -0X5020);
    // 0x8005CB54: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x8005CB58: addu        $v1, $v1, $v0
    gpr jr_addend_8005CB60 = ctx->r3;
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x8005CB5C: lw          $v0, 0x0($v1)
    ctx->r2 = ADD32(ctx->r3, 0X0);
    // 0x8005CB60: jr          $v0
    // 0x8005CB64: nop

    switch (jr_addend_8005CB60 >> 2) {
        case 0: goto L_8005CB68; break;
        case 1: goto L_8005CB7C; break;
        case 2: goto L_8005CB7C; break;
        case 3: goto L_8005CB68; break;
        case 4: goto L_8005CB68; break;
        case 5: goto L_8005CB7C; break;
        default: switch_error(__func__, 0x8005CB60, 0x8003AFE0);
    }
    // 0x8005CB64: nop

L_8005CB68:
    // 0x8005CB68: ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
    // 0x8005CB6C: sh          $v0, 0x118($s1)
    MEM_H(0X118, ctx->r17) = ctx->r2;
    // 0x8005CB70: sb          $zero, 0x11C($s1)
    MEM_B(0X11C, ctx->r17) = 0;
    // 0x8005CB74: lwc1        $f0, 0x10($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X10);
    // 0x8005CB78: swc1        $f0, 0x10C($s1)
    MEM_W(0X10C, ctx->r17) = ctx->f0.u32l;
L_8005CB7C:
    // 0x8005CB7C: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x8005CB80: lhu         $a0, -0x6A98($v0)
    ctx->r4 = MEM_HU(ctx->r2, -0X6A98);
    // 0x8005CB84: j           L_8005CB94
    // 0x8005CB88: nop

        goto L_8005CB94;
    // 0x8005CB88: nop

L_8005CB8C:
    // 0x8005CB8C: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x8005CB90: lhu         $a0, -0x6A9A($v0)
    ctx->r4 = MEM_HU(ctx->r2, -0X6A9A);
L_8005CB94:
    // 0x8005CB94: jal         0x8003E684
    // 0x8005CB98: addu        $a1, $s6, $zero
    ctx->r5 = ADD32(ctx->r22, 0);
    func_8003E684(rdram, ctx);
        goto after_3;
    // 0x8005CB98: addu        $a1, $s6, $zero
    ctx->r5 = ADD32(ctx->r22, 0);
    after_3:
    // 0x8005CB9C: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8005CBA0: lw          $v1, 0xB70($v0)
    ctx->r3 = MEM_W(ctx->r2, 0XB70);
    // 0x8005CBA4: addiu       $v0, $zero, 0xA
    ctx->r2 = ADD32(0, 0XA);
    // 0x8005CBA8: beql        $v1, $v0, L_8005CBB0
    if (ctx->r3 == ctx->r2) {
        // 0x8005CBAC: sh          $zero, 0x1A($s0)
        MEM_H(0X1A, ctx->r16) = 0;
            goto L_8005CBB0;
    }
    goto skip_1;
    // 0x8005CBAC: sh          $zero, 0x1A($s0)
    MEM_H(0X1A, ctx->r16) = 0;
    skip_1:
L_8005CBB0:
    // 0x8005CBB0: lh          $v0, 0x1A($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X1A);
    // 0x8005CBB4: beq         $v0, $zero, L_8005CCC4
    if (ctx->r2 == 0) {
        // 0x8005CBB8: andi        $v0, $s2, 0xFFFF
        ctx->r2 = ctx->r18 & 0XFFFF;
            goto L_8005CCC4;
    }
    // 0x8005CBB8: andi        $v0, $s2, 0xFFFF
    ctx->r2 = ctx->r18 & 0XFFFF;
    // 0x8005CBBC: lhu         $v1, 0xF8($s1)
    ctx->r3 = MEM_HU(ctx->r17, 0XF8);
    // 0x8005CBC0: beq         $v1, $v0, L_8005CC2C
    if (ctx->r3 == ctx->r2) {
        // 0x8005CBC4: lui         $a0, 0x800A
        ctx->r4 = S32(0X800A << 16);
            goto L_8005CC2C;
    }
    // 0x8005CBC4: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x8005CBC8: addiu       $a0, $a0, -0x12B4
    ctx->r4 = ADD32(ctx->r4, -0X12B4);
    // 0x8005CBCC: jal         0x8001CFE8
    // 0x8005CBD0: addiu       $a1, $s1, 0xC0
    ctx->r5 = ADD32(ctx->r17, 0XC0);
    func_8001CFE8(rdram, ctx);
        goto after_4;
    // 0x8005CBD0: addiu       $a1, $s1, 0xC0
    ctx->r5 = ADD32(ctx->r17, 0XC0);
    after_4:
    // 0x8005CBD4: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8005CBD8: lwc1        $f2, -0x5008($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X5008);
    // 0x8005CBDC: c.le.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl <= ctx->f2.fl;
    // 0x8005CBE0: nop

    // 0x8005CBE4: bc1f        L_8005CC2C
    if (!c1cs) {
        // 0x8005CBE8: addiu       $a1, $zero, 0xB
        ctx->r5 = ADD32(0, 0XB);
            goto L_8005CC2C;
    }
    // 0x8005CBE8: addiu       $a1, $zero, 0xB
    ctx->r5 = ADD32(0, 0XB);
    // 0x8005CBEC: ori         $s0, $zero, 0xFFFF
    ctx->r16 = 0 | 0XFFFF;
    // 0x8005CBF0: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x8005CBF4: sh          $s0, 0x80($sp)
    MEM_H(0X80, ctx->r29) = ctx->r16;
    // 0x8005CBF8: sh          $v0, 0x82($sp)
    MEM_H(0X82, ctx->r29) = ctx->r2;
    // 0x8005CBFC: lhu         $a0, 0xF8($s1)
    ctx->r4 = MEM_HU(ctx->r17, 0XF8);
    // 0x8005CC00: jal         0x8003E8DC
    // 0x8005CC04: addiu       $a2, $sp, 0x80
    ctx->r6 = ADD32(ctx->r29, 0X80);
    func_8003E8DC(rdram, ctx);
        goto after_5;
    // 0x8005CC04: addiu       $a2, $sp, 0x80
    ctx->r6 = ADD32(ctx->r29, 0X80);
    after_5:
    // 0x8005CC08: lh          $v1, 0x82($sp)
    ctx->r3 = MEM_H(ctx->r29, 0X82);
    // 0x8005CC0C: addiu       $v0, $zero, 0xD
    ctx->r2 = ADD32(0, 0XD);
    // 0x8005CC10: bnel        $v1, $v0, L_8005D914
    if (ctx->r3 != ctx->r2) {
        // 0x8005CC14: sh          $s0, 0xFA($s1)
        MEM_H(0XFA, ctx->r17) = ctx->r16;
            goto L_8005D914;
    }
    goto skip_2;
    // 0x8005CC14: sh          $s0, 0xFA($s1)
    MEM_H(0XFA, ctx->r17) = ctx->r16;
    skip_2:
    // 0x8005CC18: addiu       $a0, $s1, 0xB4
    ctx->r4 = ADD32(ctx->r17, 0XB4);
    // 0x8005CC1C: jal         0x8005EC60
    // 0x8005CC20: addiu       $a1, $zero, 0xB0
    ctx->r5 = ADD32(0, 0XB0);
    func_8005EC60(rdram, ctx);
        goto after_6;
    // 0x8005CC20: addiu       $a1, $zero, 0xB0
    ctx->r5 = ADD32(0, 0XB0);
    after_6:
    // 0x8005CC24: j           L_8005D914
    // 0x8005CC28: sh          $s0, 0xFA($s1)
    MEM_H(0XFA, ctx->r17) = ctx->r16;
        goto L_8005D914;
    // 0x8005CC28: sh          $s0, 0xFA($s1)
    MEM_H(0XFA, ctx->r17) = ctx->r16;
L_8005CC2C:
    // 0x8005CC2C: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x8005CC30: lwc1        $f0, 0xB4($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0XB4);
    // 0x8005CC34: lw          $v0, -0x68C0($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X68C0);
    // 0x8005CC38: lui         $v1, 0x800A
    ctx->r3 = S32(0X800A << 16);
    // 0x8005CC3C: swc1        $f0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f0.u32l;
    // 0x8005CC40: lwc1        $f0, 0xB8($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0XB8);
    // 0x8005CC44: addiu       $v1, $v1, -0x1310
    ctx->r3 = ADD32(ctx->r3, -0X1310);
    // 0x8005CC48: swc1        $f0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f0.u32l;
    // 0x8005CC4C: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8005CC50: lwc1        $f0, -0x5004($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X5004);
    // 0x8005CC54: lwc1        $f2, 0xBC($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0XBC);
    // 0x8005CC58: lui         $a0, 0x8005
    ctx->r4 = S32(0X8005 << 16);
    // 0x8005CC5C: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
    // 0x8005CC60: swc1        $f0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f0.u32l;
    // 0x8005CC64: swc1        $f2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f2.u32l;
    // 0x8005CC68: lbu         $v0, 0xFE($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0XFE);
    // 0x8005CC6C: addiu       $a0, $a0, -0x3938
    ctx->r4 = ADD32(ctx->r4, -0X3938);
    // 0x8005CC70: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8005CC74: lbu         $v0, 0x0($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X0);
    // 0x8005CC78: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    // 0x8005CC7C: sb          $v0, 0x40($sp)
    MEM_B(0X40, ctx->r29) = ctx->r2;
    // 0x8005CC80: lbu         $v0, 0xFE($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0XFE);
    // 0x8005CC84: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8005CC88: lwc1        $f0, -0x5000($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X5000);
    // 0x8005CC8C: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8005CC90: lbu         $v1, 0x0($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X0);
    // 0x8005CC94: addiu       $v0, $zero, 0x100
    ctx->r2 = ADD32(0, 0X100);
    // 0x8005CC98: swc1        $f0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f0.u32l;
    // 0x8005CC9C: sh          $v0, 0x38($sp)
    MEM_H(0X38, ctx->r29) = ctx->r2;
    // 0x8005CCA0: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
    // 0x8005CCA4: sb          $v1, 0x41($sp)
    MEM_B(0X41, ctx->r29) = ctx->r3;
    // 0x8005CCA8: lbu         $a3, 0x19($s6)
    ctx->r7 = MEM_BU(ctx->r22, 0X19);
    // 0x8005CCAC: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x8005CCB0: addiu       $a3, $a3, 0xA
    ctx->r7 = ADD32(ctx->r7, 0XA);
    // 0x8005CCB4: jal         0x8003FFEC
    // 0x8005CCB8: andi        $a3, $a3, 0xFF
    ctx->r7 = ctx->r7 & 0XFF;
    func_8003FFEC(rdram, ctx);
        goto after_7;
    // 0x8005CCB8: andi        $a3, $a3, 0xFF
    ctx->r7 = ctx->r7 & 0XFF;
    after_7:
    // 0x8005CCBC: j           L_8005D914
    // 0x8005CCC0: sh          $v0, 0xFA($s1)
    MEM_H(0XFA, ctx->r17) = ctx->r2;
        goto L_8005D914;
    // 0x8005CCC0: sh          $v0, 0xFA($s1)
    MEM_H(0XFA, ctx->r17) = ctx->r2;
L_8005CCC4:
    // 0x8005CCC4: ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
    // 0x8005CCC8: j           L_8005D914
    // 0x8005CCCC: sh          $v0, 0xFA($s1)
    MEM_H(0XFA, ctx->r17) = ctx->r2;
        goto L_8005D914;
    // 0x8005CCCC: sh          $v0, 0xFA($s1)
    MEM_H(0XFA, ctx->r17) = ctx->r2;
L_8005CCD0:
    // 0x8005CCD0: lbu         $v0, 0xFE($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0XFE);
    // 0x8005CCD4: andi        $v1, $v0, 0x1F
    ctx->r3 = ctx->r2 & 0X1F;
    // 0x8005CCD8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8005CCDC: beq         $v1, $v0, L_8005CCFC
    if (ctx->r3 == ctx->r2) {
        // 0x8005CCE0: nop
    
            goto L_8005CCFC;
    }
    // 0x8005CCE0: nop

    // 0x8005CCE4: beq         $v1, $zero, L_8005CD38
    if (ctx->r3 == 0) {
        // 0x8005CCE8: slti        $v0, $v1, 0x6
        ctx->r2 = SIGNED(ctx->r3) < 0X6 ? 1 : 0;
            goto L_8005CD38;
    }
    // 0x8005CCE8: slti        $v0, $v1, 0x6
    ctx->r2 = SIGNED(ctx->r3) < 0X6 ? 1 : 0;
    // 0x8005CCEC: beq         $v0, $zero, L_8005CD38
    if (ctx->r2 == 0) {
        // 0x8005CCF0: slti        $v0, $v1, 0x4
        ctx->r2 = SIGNED(ctx->r3) < 0X4 ? 1 : 0;
            goto L_8005CD38;
    }
    // 0x8005CCF0: slti        $v0, $v1, 0x4
    ctx->r2 = SIGNED(ctx->r3) < 0X4 ? 1 : 0;
    // 0x8005CCF4: bne         $v0, $zero, L_8005CD38
    if (ctx->r2 != 0) {
        // 0x8005CCF8: nop
    
            goto L_8005CD38;
    }
    // 0x8005CCF8: nop

L_8005CCFC:
    // 0x8005CCFC: lhu         $v0, 0x118($s1)
    ctx->r2 = MEM_HU(ctx->r17, 0X118);
    // 0x8005CD00: ori         $s0, $zero, 0xFFFF
    ctx->r16 = 0 | 0XFFFF;
    // 0x8005CD04: beq         $v0, $s0, L_8005CD38
    if (ctx->r2 == ctx->r16) {
        // 0x8005CD08: addu        $a0, $v0, $zero
        ctx->r4 = ADD32(ctx->r2, 0);
            goto L_8005CD38;
    }
    // 0x8005CD08: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // 0x8005CD0C: jal         0x8003FC28
    // 0x8005CD10: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    func_8003FC28(rdram, ctx);
        goto after_8;
    // 0x8005CD10: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    after_8:
    // 0x8005CD14: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x8005CD18: beq         $v0, $s0, L_8005CD38
    if (ctx->r2 == ctx->r16) {
        // 0x8005CD1C: nop
    
            goto L_8005CD38;
    }
    // 0x8005CD1C: nop

    // 0x8005CD20: lhu         $a0, 0x11A($s1)
    ctx->r4 = MEM_HU(ctx->r17, 0X11A);
    // 0x8005CD24: jal         0x8004013C
    // 0x8005CD28: nop

    func_8004013C(rdram, ctx);
        goto after_9;
    // 0x8005CD28: nop

    after_9:
    // 0x8005CD2C: lhu         $a0, 0x11A($s1)
    ctx->r4 = MEM_HU(ctx->r17, 0X11A);
    // 0x8005CD30: jal         0x8003E7D0
    // 0x8005CD34: addu        $a1, $v0, $zero
    ctx->r5 = ADD32(ctx->r2, 0);
    func_8003E7D0(rdram, ctx);
        goto after_10;
    // 0x8005CD34: addu        $a1, $v0, $zero
    ctx->r5 = ADD32(ctx->r2, 0);
    after_10:
L_8005CD38:
    // 0x8005CD38: lhu         $v1, 0xFA($s1)
    ctx->r3 = MEM_HU(ctx->r17, 0XFA);
    // 0x8005CD3C: ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
    // 0x8005CD40: beq         $v1, $v0, L_8005CD50
    if (ctx->r3 == ctx->r2) {
        // 0x8005CD44: nop
    
            goto L_8005CD50;
    }
    // 0x8005CD44: nop

    // 0x8005CD48: jal         0x8003ED74
    // 0x8005CD4C: addu        $a0, $v1, $zero
    ctx->r4 = ADD32(ctx->r3, 0);
    func_8003ED74(rdram, ctx);
        goto after_11;
    // 0x8005CD4C: addu        $a0, $v1, $zero
    ctx->r4 = ADD32(ctx->r3, 0);
    after_11:
L_8005CD50:
    // 0x8005CD50: lbu         $v1, 0xFF($s1)
    ctx->r3 = MEM_BU(ctx->r17, 0XFF);
    // 0x8005CD54: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // 0x8005CD58: beq         $v1, $v0, L_8005D914
    if (ctx->r3 == ctx->r2) {
        // 0x8005CD5C: sll         $v0, $v1, 4
        ctx->r2 = S32(ctx->r3 << 4);
            goto L_8005D914;
    }
    // 0x8005CD5C: sll         $v0, $v1, 4
    ctx->r2 = S32(ctx->r3 << 4);
    // 0x8005CD60: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8005CD64: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8005CD68: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8005CD6C: addiu       $a0, $a0, -0x69E0
    ctx->r4 = ADD32(ctx->r4, -0X69E0);
    // 0x8005CD70: jal         0x80098DE0
    // 0x8005CD74: addu        $a0, $v0, $a0
    ctx->r4 = ADD32(ctx->r2, ctx->r4);
    func_80098DE0(rdram, ctx);
        goto after_12;
    // 0x8005CD74: addu        $a0, $v0, $a0
    ctx->r4 = ADD32(ctx->r2, ctx->r4);
    after_12:
    // 0x8005CD78: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8005CD7C: lbu         $v1, -0x68D0($a0)
    ctx->r3 = MEM_BU(ctx->r4, -0X68D0);
    // 0x8005CD80: addiu       $v0, $v1, 0x1
    ctx->r2 = ADD32(ctx->r3, 0X1);
    // 0x8005CD84: sb          $v0, -0x68D0($a0)
    MEM_B(-0X68D0, ctx->r4) = ctx->r2;
    // 0x8005CD88: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x8005CD8C: addiu       $v0, $v0, -0x68CC
    ctx->r2 = ADD32(ctx->r2, -0X68CC);
    // 0x8005CD90: andi        $v1, $v1, 0xFF
    ctx->r3 = ctx->r3 & 0XFF;
    // 0x8005CD94: lbu         $a0, 0xFF($s1)
    ctx->r4 = MEM_BU(ctx->r17, 0XFF);
    // 0x8005CD98: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x8005CD9C: j           L_8005D914
    // 0x8005CDA0: sb          $a0, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r4;
        goto L_8005D914;
    // 0x8005CDA0: sb          $a0, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r4;
L_8005CDA4:
    // 0x8005CDA4: lwc1        $f0, 0xF0($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0XF0);
    // 0x8005CDA8: lwc1        $f2, 0x0($s2)
    ctx->f2.u32l = MEM_W(ctx->r18, 0X0);
    // 0x8005CDAC: addu        $fp, $zero, $zero
    ctx->r30 = ADD32(0, 0);
    // 0x8005CDB0: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x8005CDB4: lwc1        $f2, 0xF4($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0XF4);
    // 0x8005CDB8: addu        $s7, $s2, $zero
    ctx->r23 = ADD32(ctx->r18, 0);
    // 0x8005CDBC: sb          $zero, 0xA0($sp)
    MEM_B(0XA0, ctx->r29) = 0;
    // 0x8005CDC0: c.le.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl <= ctx->f0.fl;
    // 0x8005CDC4: nop

    // 0x8005CDC8: bc1f        L_8005CE58
    if (!c1cs) {
        // 0x8005CDCC: swc1        $f0, 0xF0($s1)
        MEM_W(0XF0, ctx->r17) = ctx->f0.u32l;
            goto L_8005CE58;
    }
    // 0x8005CDCC: swc1        $f0, 0xF0($s1)
    MEM_W(0XF0, ctx->r17) = ctx->f0.u32l;
    // 0x8005CDD0: lbu         $v1, 0xFE($s1)
    ctx->r3 = MEM_BU(ctx->r17, 0XFE);
    // 0x8005CDD4: andi        $v0, $v1, 0x40
    ctx->r2 = ctx->r3 & 0X40;
    // 0x8005CDD8: bnel        $v0, $zero, L_8005D3C0
    if (ctx->r2 != 0) {
        // 0x8005CDDC: addiu       $fp, $zero, 0x1
        ctx->r30 = ADD32(0, 0X1);
            goto L_8005D3C0;
    }
    goto skip_3;
    // 0x8005CDDC: addiu       $fp, $zero, 0x1
    ctx->r30 = ADD32(0, 0X1);
    skip_3:
    // 0x8005CDE0: andi        $v0, $v1, 0x1F
    ctx->r2 = ctx->r3 & 0X1F;
    // 0x8005CDE4: sb          $v0, 0xFE($s1)
    MEM_B(0XFE, ctx->r17) = ctx->r2;
    // 0x8005CDE8: lhu         $v0, 0xFA($s1)
    ctx->r2 = MEM_HU(ctx->r17, 0XFA);
    // 0x8005CDEC: ori         $s0, $zero, 0xFFFF
    ctx->r16 = 0 | 0XFFFF;
    // 0x8005CDF0: beq         $v0, $s0, L_8005CE04
    if (ctx->r2 == ctx->r16) {
        // 0x8005CDF4: nop
    
            goto L_8005CE04;
    }
    // 0x8005CDF4: nop

    // 0x8005CDF8: jal         0x8003ED74
    // 0x8005CDFC: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    func_8003ED74(rdram, ctx);
        goto after_13;
    // 0x8005CDFC: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    after_13:
    // 0x8005CE00: sh          $s0, 0xFA($s1)
    MEM_H(0XFA, ctx->r17) = ctx->r16;
L_8005CE04:
    // 0x8005CE04: lwc1        $f0, 0xEC($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0XEC);
    // 0x8005CE08: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8005CE0C: lwc1        $f2, -0x4FFC($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X4FFC);
    // 0x8005CE10: lhu         $v1, 0xFC($s1)
    ctx->r3 = MEM_HU(ctx->r17, 0XFC);
    // 0x8005CE14: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x8005CE18: sltiu       $v0, $v1, 0x2
    ctx->r2 = ctx->r3 < 0X2 ? 1 : 0;
    // 0x8005CE1C: bne         $v0, $zero, L_8005CE2C
    if (ctx->r2 != 0) {
        // 0x8005CE20: swc1        $f0, 0xEC($s1)
        MEM_W(0XEC, ctx->r17) = ctx->f0.u32l;
            goto L_8005CE2C;
    }
    // 0x8005CE20: swc1        $f0, 0xEC($s1)
    MEM_W(0XEC, ctx->r17) = ctx->f0.u32l;
    // 0x8005CE24: addiu       $v0, $v1, -0x1
    ctx->r2 = ADD32(ctx->r3, -0X1);
    // 0x8005CE28: sh          $v0, 0xFC($s1)
    MEM_H(0XFC, ctx->r17) = ctx->r2;
L_8005CE2C:
    // 0x8005CE2C: lwc1        $f2, 0xEC($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0XEC);
    // 0x8005CE30: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8005CE34: c.le.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl <= ctx->f0.fl;
    // 0x8005CE38: nop

    // 0x8005CE3C: bc1f        L_8005CE5C
    if (!c1cs) {
        // 0x8005CE40: lui         $v0, 0x8014
        ctx->r2 = S32(0X8014 << 16);
            goto L_8005CE5C;
    }
    // 0x8005CE40: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
L_8005CE44:
    // 0x8005CE44: lhu         $a0, 0x16($s6)
    ctx->r4 = MEM_HU(ctx->r22, 0X16);
    // 0x8005CE48: jal         0x8003ED74
    // 0x8005CE4C: nop

    func_8003ED74(rdram, ctx);
        goto after_14;
    // 0x8005CE4C: nop

    after_14:
    // 0x8005CE50: j           L_8005D918
    // 0x8005CE54: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8005D918;
    // 0x8005CE54: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8005CE58:
    // 0x8005CE58: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
L_8005CE5C:
    // 0x8005CE5C: lw          $v1, -0x7764($v0)
    ctx->r3 = MEM_W(ctx->r2, -0X7764);
    // 0x8005CE60: lui         $v0, 0xAAAA
    ctx->r2 = S32(0XAAAA << 16);
    // 0x8005CE64: ori         $v0, $v0, 0xAAAB
    ctx->r2 = ctx->r2 | 0XAAAB;
    // 0x8005CE68: multu       $v1, $v0
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8005CE6C: mfhi        $t0
    ctx->r8 = hi;
    // 0x8005CE70: srl         $a0, $t0, 1
    ctx->r4 = S32(U32(ctx->r8) >> 1);
    // 0x8005CE74: sll         $v0, $a0, 1
    ctx->r2 = S32(ctx->r4 << 1);
    // 0x8005CE78: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x8005CE7C: subu        $a0, $v1, $v0
    ctx->r4 = SUB32(ctx->r3, ctx->r2);
    // 0x8005CE80: bne         $a0, $zero, L_8005CFF8
    if (ctx->r4 != 0) {
        // 0x8005CE84: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_8005CFF8;
    }
    // 0x8005CE84: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8005CE88: lhu         $v0, 0x14($s6)
    ctx->r2 = MEM_HU(ctx->r22, 0X14);
    // 0x8005CE8C: andi        $v0, $v0, 0x600
    ctx->r2 = ctx->r2 & 0X600;
    // 0x8005CE90: bne         $v0, $zero, L_8005CFF8
    if (ctx->r2 != 0) {
        // 0x8005CE94: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_8005CFF8;
    }
    // 0x8005CE94: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8005CE98: lwc1        $f2, 0x0($s7)
    ctx->f2.u32l = MEM_W(ctx->r23, 0X0);
    // 0x8005CE9C: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8005CEA0: lwc1        $f0, -0x4FF8($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X4FF8);
    // 0x8005CEA4: mul.s       $f4, $f2, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x8005CEA8: lwc1        $f2, 0xF0($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0XF0);
    // 0x8005CEAC: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8005CEB0: lwc1        $f0, -0x4FF4($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X4FF4);
    // 0x8005CEB4: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x8005CEB8: nop

    // 0x8005CEBC: bc1f        L_8005CEC8
    if (!c1cs) {
        // 0x8005CEC0: addiu       $s2, $zero, -0x1
        ctx->r18 = ADD32(0, -0X1);
            goto L_8005CEC8;
    }
    // 0x8005CEC0: addiu       $s2, $zero, -0x1
    ctx->r18 = ADD32(0, -0X1);
    // 0x8005CEC4: lhu         $s2, 0xF8($s1)
    ctx->r18 = MEM_HU(ctx->r17, 0XF8);
L_8005CEC8:
    // 0x8005CEC8: addiu       $s3, $s1, 0xB4
    ctx->r19 = ADD32(ctx->r17, 0XB4);
    // 0x8005CECC: lwc1        $f0, 0x24($s3)
    ctx->f0.u32l = MEM_W(ctx->r19, 0X24);
    // 0x8005CED0: mul.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x8005CED4: swc1        $f0, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->f0.u32l;
    // 0x8005CED8: lwc1        $f0, 0x28($s3)
    ctx->f0.u32l = MEM_W(ctx->r19, 0X28);
    // 0x8005CEDC: mul.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x8005CEE0: ori         $s5, $zero, 0xFFFF
    ctx->r21 = 0 | 0XFFFF;
    // 0x8005CEE4: swc1        $f0, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->f0.u32l;
    // 0x8005CEE8: lwc1        $f0, 0x2C($s3)
    ctx->f0.u32l = MEM_W(ctx->r19, 0X2C);
    // 0x8005CEEC: addiu       $a1, $sp, 0x88
    ctx->r5 = ADD32(ctx->r29, 0X88);
    // 0x8005CEF0: mul.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x8005CEF4: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x8005CEF8: lhu         $a0, -0x6A84($v0)
    ctx->r4 = MEM_HU(ctx->r2, -0X6A84);
    // 0x8005CEFC: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8005CF00: lwc1        $f20, -0x4FF0($at)
    ctx->f20.u32l = MEM_W(ctx->r1, -0X4FF0);
    // 0x8005CF04: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    // 0x8005CF08: jal         0x8003FC28
    // 0x8005CF0C: swc1        $f0, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->f0.u32l;
    func_8003FC28(rdram, ctx);
        goto after_15;
    // 0x8005CF0C: swc1        $f0, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->f0.u32l;
    after_15:
    // 0x8005CF10: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    // 0x8005CF14: andi        $v1, $s0, 0xFFFF
    ctx->r3 = ctx->r16 & 0XFFFF;
    // 0x8005CF18: ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
    // 0x8005CF1C: beq         $v1, $v0, L_8005CF98
    if (ctx->r3 == ctx->r2) {
        // 0x8005CF20: addu        $a0, $s5, $zero
        ctx->r4 = ADD32(ctx->r21, 0);
            goto L_8005CF98;
    }
    // 0x8005CF20: addu        $a0, $s5, $zero
    ctx->r4 = ADD32(ctx->r21, 0);
    // 0x8005CF24: andi        $s2, $s2, 0xFFFF
    ctx->r18 = ctx->r18 & 0XFFFF;
    // 0x8005CF28: addu        $s4, $v0, $zero
    ctx->r20 = ADD32(ctx->r2, 0);
L_8005CF2C:
    // 0x8005CF2C: beq         $s2, $s4, L_8005CF3C
    if (ctx->r18 == ctx->r20) {
        // 0x8005CF30: andi        $v0, $s0, 0xFFFF
        ctx->r2 = ctx->r16 & 0XFFFF;
            goto L_8005CF3C;
    }
    // 0x8005CF30: andi        $v0, $s0, 0xFFFF
    ctx->r2 = ctx->r16 & 0XFFFF;
    // 0x8005CF34: beq         $s2, $v0, L_8005CF80
    if (ctx->r18 == ctx->r2) {
        // 0x8005CF38: nop
    
            goto L_8005CF80;
    }
    // 0x8005CF38: nop

L_8005CF3C:
    // 0x8005CF3C: jal         0x8004013C
    // 0x8005CF40: andi        $a0, $s0, 0xFFFF
    ctx->r4 = ctx->r16 & 0XFFFF;
    func_8004013C(rdram, ctx);
        goto after_16;
    // 0x8005CF40: andi        $a0, $s0, 0xFFFF
    ctx->r4 = ctx->r16 & 0XFFFF;
    after_16:
    // 0x8005CF44: lw          $a0, 0xC($v0)
    ctx->r4 = MEM_W(ctx->r2, 0XC);
    // 0x8005CF48: beq         $a0, $zero, L_8005CF80
    if (ctx->r4 == 0) {
        // 0x8005CF4C: addu        $a1, $s3, $zero
        ctx->r5 = ADD32(ctx->r19, 0);
            goto L_8005CF80;
    }
    // 0x8005CF4C: addu        $a1, $s3, $zero
    ctx->r5 = ADD32(ctx->r19, 0);
    // 0x8005CF50: addiu       $a2, $sp, 0x90
    ctx->r6 = ADD32(ctx->r29, 0X90);
    // 0x8005CF54: jal         0x8006A944
    // 0x8005CF58: addiu       $a3, $sp, 0x58
    ctx->r7 = ADD32(ctx->r29, 0X58);
    func_8006A944(rdram, ctx);
        goto after_17;
    // 0x8005CF58: addiu       $a3, $sp, 0x58
    ctx->r7 = ADD32(ctx->r29, 0X58);
    after_17:
    // 0x8005CF5C: beq         $v0, $zero, L_8005CF80
    if (ctx->r2 == 0) {
        // 0x8005CF60: nop
    
            goto L_8005CF80;
    }
    // 0x8005CF60: nop

    // 0x8005CF64: lwc1        $f0, 0x70($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X70);
    // 0x8005CF68: c.lt.s      $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f0.fl < ctx->f20.fl;
    // 0x8005CF6C: nop

    // 0x8005CF70: bc1f        L_8005CF80
    if (!c1cs) {
        // 0x8005CF74: nop
    
            goto L_8005CF80;
    }
    // 0x8005CF74: nop

    // 0x8005CF78: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x8005CF7C: addu        $s5, $s0, $zero
    ctx->r21 = ADD32(ctx->r16, 0);
L_8005CF80:
    // 0x8005CF80: jal         0x8003EEF4
    // 0x8005CF84: addiu       $a0, $sp, 0x88
    ctx->r4 = ADD32(ctx->r29, 0X88);
    func_8003EEF4(rdram, ctx);
        goto after_18;
    // 0x8005CF84: addiu       $a0, $sp, 0x88
    ctx->r4 = ADD32(ctx->r29, 0X88);
    after_18:
    // 0x8005CF88: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    // 0x8005CF8C: andi        $v0, $s0, 0xFFFF
    ctx->r2 = ctx->r16 & 0XFFFF;
    // 0x8005CF90: bne         $v0, $s4, L_8005CF2C
    if (ctx->r2 != ctx->r20) {
        // 0x8005CF94: addu        $a0, $s5, $zero
        ctx->r4 = ADD32(ctx->r21, 0);
            goto L_8005CF2C;
    }
    // 0x8005CF94: addu        $a0, $s5, $zero
    ctx->r4 = ADD32(ctx->r21, 0);
L_8005CF98:
    // 0x8005CF98: andi        $v1, $a0, 0xFFFF
    ctx->r3 = ctx->r4 & 0XFFFF;
    // 0x8005CF9C: ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
    // 0x8005CFA0: beq         $v1, $v0, L_8005D380
    if (ctx->r3 == ctx->r2) {
        // 0x8005CFA4: nop
    
            goto L_8005D380;
    }
    // 0x8005CFA4: nop

    // 0x8005CFA8: lwc1        $f2, 0x70($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X70);
    // 0x8005CFAC: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8005CFB0: lwc1        $f0, -0x4FEC($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X4FEC);
    // 0x8005CFB4: c.le.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl <= ctx->f0.fl;
    // 0x8005CFB8: nop

    // 0x8005CFBC: bc1t        L_8005D2F4
    if (c1cs) {
        // 0x8005CFC0: andi        $s0, $a0, 0xFFFF
        ctx->r16 = ctx->r4 & 0XFFFF;
            goto L_8005D2F4;
    }
    // 0x8005CFC0: andi        $s0, $a0, 0xFFFF
    ctx->r16 = ctx->r4 & 0XFFFF;
    // 0x8005CFC4: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8005CFC8: lwc1        $f0, -0x4FE8($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X4FE8);
    // 0x8005CFCC: c.le.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl <= ctx->f0.fl;
    // 0x8005CFD0: nop

    // 0x8005CFD4: bc1f        L_8005CFEC
    if (!c1cs) {
        // 0x8005CFD8: ori         $a0, $zero, 0xFFFF
        ctx->r4 = 0 | 0XFFFF;
            goto L_8005CFEC;
    }
    // 0x8005CFD8: ori         $a0, $zero, 0xFFFF
    ctx->r4 = 0 | 0XFFFF;
    // 0x8005CFDC: lhu         $v0, 0x14($s6)
    ctx->r2 = MEM_HU(ctx->r22, 0X14);
    // 0x8005CFE0: ori         $v0, $v0, 0x200
    ctx->r2 = ctx->r2 | 0X200;
    // 0x8005CFE4: j           L_8005D2F0
    // 0x8005CFE8: sh          $v0, 0x14($s6)
    MEM_H(0X14, ctx->r22) = ctx->r2;
        goto L_8005D2F0;
    // 0x8005CFE8: sh          $v0, 0x14($s6)
    MEM_H(0X14, ctx->r22) = ctx->r2;
L_8005CFEC:
    // 0x8005CFEC: lhu         $v0, 0x14($s6)
    ctx->r2 = MEM_HU(ctx->r22, 0X14);
    // 0x8005CFF0: j           L_8005D164
    // 0x8005CFF4: ori         $v0, $v0, 0x400
    ctx->r2 = ctx->r2 | 0X400;
        goto L_8005D164;
    // 0x8005CFF4: ori         $v0, $v0, 0x400
    ctx->r2 = ctx->r2 | 0X400;
L_8005CFF8:
    // 0x8005CFF8: bne         $a0, $v0, L_8005D16C
    if (ctx->r4 != ctx->r2) {
        // 0x8005CFFC: addiu       $v0, $zero, 0x2
        ctx->r2 = ADD32(0, 0X2);
            goto L_8005D16C;
    }
    // 0x8005CFFC: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x8005D000: lhu         $v0, 0x14($s6)
    ctx->r2 = MEM_HU(ctx->r22, 0X14);
    // 0x8005D004: addiu       $v1, $zero, 0x200
    ctx->r3 = ADD32(0, 0X200);
    // 0x8005D008: andi        $v0, $v0, 0x600
    ctx->r2 = ctx->r2 & 0X600;
    // 0x8005D00C: bne         $v0, $v1, L_8005D16C
    if (ctx->r2 != ctx->r3) {
        // 0x8005D010: addiu       $v0, $zero, 0x2
        ctx->r2 = ADD32(0, 0X2);
            goto L_8005D16C;
    }
    // 0x8005D010: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x8005D014: lwc1        $f2, 0x0($s7)
    ctx->f2.u32l = MEM_W(ctx->r23, 0X0);
    // 0x8005D018: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8005D01C: lwc1        $f0, -0x4FE4($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X4FE4);
    // 0x8005D020: mul.s       $f4, $f2, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x8005D024: lwc1        $f2, 0xF0($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0XF0);
    // 0x8005D028: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8005D02C: lwc1        $f0, -0x4FE0($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X4FE0);
    // 0x8005D030: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x8005D034: nop

    // 0x8005D038: bc1f        L_8005D044
    if (!c1cs) {
        // 0x8005D03C: addiu       $s2, $zero, -0x1
        ctx->r18 = ADD32(0, -0X1);
            goto L_8005D044;
    }
    // 0x8005D03C: addiu       $s2, $zero, -0x1
    ctx->r18 = ADD32(0, -0X1);
    // 0x8005D040: lhu         $s2, 0xF8($s1)
    ctx->r18 = MEM_HU(ctx->r17, 0XF8);
L_8005D044:
    // 0x8005D044: addiu       $s3, $s1, 0xB4
    ctx->r19 = ADD32(ctx->r17, 0XB4);
    // 0x8005D048: lwc1        $f0, 0x24($s3)
    ctx->f0.u32l = MEM_W(ctx->r19, 0X24);
    // 0x8005D04C: mul.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x8005D050: swc1        $f0, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->f0.u32l;
    // 0x8005D054: lwc1        $f0, 0x28($s3)
    ctx->f0.u32l = MEM_W(ctx->r19, 0X28);
    // 0x8005D058: mul.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x8005D05C: ori         $s5, $zero, 0xFFFF
    ctx->r21 = 0 | 0XFFFF;
    // 0x8005D060: swc1        $f0, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->f0.u32l;
    // 0x8005D064: lwc1        $f0, 0x2C($s3)
    ctx->f0.u32l = MEM_W(ctx->r19, 0X2C);
    // 0x8005D068: addiu       $a1, $sp, 0x80
    ctx->r5 = ADD32(ctx->r29, 0X80);
    // 0x8005D06C: mul.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x8005D070: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x8005D074: lhu         $a0, -0x6A84($v0)
    ctx->r4 = MEM_HU(ctx->r2, -0X6A84);
    // 0x8005D078: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8005D07C: lwc1        $f20, -0x4FDC($at)
    ctx->f20.u32l = MEM_W(ctx->r1, -0X4FDC);
    // 0x8005D080: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    // 0x8005D084: jal         0x8003FC28
    // 0x8005D088: swc1        $f0, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->f0.u32l;
    func_8003FC28(rdram, ctx);
        goto after_19;
    // 0x8005D088: swc1        $f0, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->f0.u32l;
    after_19:
    // 0x8005D08C: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    // 0x8005D090: andi        $v1, $s0, 0xFFFF
    ctx->r3 = ctx->r16 & 0XFFFF;
    // 0x8005D094: ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
    // 0x8005D098: beq         $v1, $v0, L_8005D114
    if (ctx->r3 == ctx->r2) {
        // 0x8005D09C: addu        $a0, $s5, $zero
        ctx->r4 = ADD32(ctx->r21, 0);
            goto L_8005D114;
    }
    // 0x8005D09C: addu        $a0, $s5, $zero
    ctx->r4 = ADD32(ctx->r21, 0);
    // 0x8005D0A0: andi        $s2, $s2, 0xFFFF
    ctx->r18 = ctx->r18 & 0XFFFF;
    // 0x8005D0A4: addu        $s4, $v0, $zero
    ctx->r20 = ADD32(ctx->r2, 0);
L_8005D0A8:
    // 0x8005D0A8: beq         $s2, $s4, L_8005D0B8
    if (ctx->r18 == ctx->r20) {
        // 0x8005D0AC: andi        $v0, $s0, 0xFFFF
        ctx->r2 = ctx->r16 & 0XFFFF;
            goto L_8005D0B8;
    }
    // 0x8005D0AC: andi        $v0, $s0, 0xFFFF
    ctx->r2 = ctx->r16 & 0XFFFF;
    // 0x8005D0B0: beq         $s2, $v0, L_8005D0FC
    if (ctx->r18 == ctx->r2) {
        // 0x8005D0B4: nop
    
            goto L_8005D0FC;
    }
    // 0x8005D0B4: nop

L_8005D0B8:
    // 0x8005D0B8: jal         0x8004013C
    // 0x8005D0BC: andi        $a0, $s0, 0xFFFF
    ctx->r4 = ctx->r16 & 0XFFFF;
    func_8004013C(rdram, ctx);
        goto after_20;
    // 0x8005D0BC: andi        $a0, $s0, 0xFFFF
    ctx->r4 = ctx->r16 & 0XFFFF;
    after_20:
    // 0x8005D0C0: lw          $a0, 0xC($v0)
    ctx->r4 = MEM_W(ctx->r2, 0XC);
    // 0x8005D0C4: beq         $a0, $zero, L_8005D0FC
    if (ctx->r4 == 0) {
        // 0x8005D0C8: addu        $a1, $s3, $zero
        ctx->r5 = ADD32(ctx->r19, 0);
            goto L_8005D0FC;
    }
    // 0x8005D0C8: addu        $a1, $s3, $zero
    ctx->r5 = ADD32(ctx->r19, 0);
    // 0x8005D0CC: addiu       $a2, $sp, 0x88
    ctx->r6 = ADD32(ctx->r29, 0X88);
    // 0x8005D0D0: jal         0x8006A944
    // 0x8005D0D4: addiu       $a3, $sp, 0x58
    ctx->r7 = ADD32(ctx->r29, 0X58);
    func_8006A944(rdram, ctx);
        goto after_21;
    // 0x8005D0D4: addiu       $a3, $sp, 0x58
    ctx->r7 = ADD32(ctx->r29, 0X58);
    after_21:
    // 0x8005D0D8: beq         $v0, $zero, L_8005D0FC
    if (ctx->r2 == 0) {
        // 0x8005D0DC: nop
    
            goto L_8005D0FC;
    }
    // 0x8005D0DC: nop

    // 0x8005D0E0: lwc1        $f0, 0x70($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X70);
    // 0x8005D0E4: c.lt.s      $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f0.fl < ctx->f20.fl;
    // 0x8005D0E8: nop

    // 0x8005D0EC: bc1f        L_8005D0FC
    if (!c1cs) {
        // 0x8005D0F0: nop
    
            goto L_8005D0FC;
    }
    // 0x8005D0F0: nop

    // 0x8005D0F4: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x8005D0F8: addu        $s5, $s0, $zero
    ctx->r21 = ADD32(ctx->r16, 0);
L_8005D0FC:
    // 0x8005D0FC: jal         0x8003EEF4
    // 0x8005D100: addiu       $a0, $sp, 0x80
    ctx->r4 = ADD32(ctx->r29, 0X80);
    func_8003EEF4(rdram, ctx);
        goto after_22;
    // 0x8005D100: addiu       $a0, $sp, 0x80
    ctx->r4 = ADD32(ctx->r29, 0X80);
    after_22:
    // 0x8005D104: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    // 0x8005D108: andi        $v0, $s0, 0xFFFF
    ctx->r2 = ctx->r16 & 0XFFFF;
    // 0x8005D10C: bne         $v0, $s4, L_8005D0A8
    if (ctx->r2 != ctx->r20) {
        // 0x8005D110: addu        $a0, $s5, $zero
        ctx->r4 = ADD32(ctx->r21, 0);
            goto L_8005D0A8;
    }
    // 0x8005D110: addu        $a0, $s5, $zero
    ctx->r4 = ADD32(ctx->r21, 0);
L_8005D114:
    // 0x8005D114: andi        $v1, $a0, 0xFFFF
    ctx->r3 = ctx->r4 & 0XFFFF;
    // 0x8005D118: ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
    // 0x8005D11C: beq         $v1, $v0, L_8005D380
    if (ctx->r3 == ctx->r2) {
        // 0x8005D120: nop
    
            goto L_8005D380;
    }
    // 0x8005D120: nop

    // 0x8005D124: lwc1        $f2, 0x70($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X70);
    // 0x8005D128: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8005D12C: lwc1        $f0, -0x4FD8($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X4FD8);
    // 0x8005D130: c.le.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl <= ctx->f0.fl;
    // 0x8005D134: nop

    // 0x8005D138: bc1t        L_8005D2F4
    if (c1cs) {
        // 0x8005D13C: andi        $s0, $a0, 0xFFFF
        ctx->r16 = ctx->r4 & 0XFFFF;
            goto L_8005D2F4;
    }
    // 0x8005D13C: andi        $s0, $a0, 0xFFFF
    ctx->r16 = ctx->r4 & 0XFFFF;
    // 0x8005D140: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8005D144: lwc1        $f0, -0x4FD4($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X4FD4);
    // 0x8005D148: c.le.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl <= ctx->f0.fl;
    // 0x8005D14C: nop

    // 0x8005D150: bc1f        L_8005D2CC
    if (!c1cs) {
        // 0x8005D154: ori         $a0, $zero, 0xFFFF
        ctx->r4 = 0 | 0XFFFF;
            goto L_8005D2CC;
    }
    // 0x8005D154: ori         $a0, $zero, 0xFFFF
    ctx->r4 = 0 | 0XFFFF;
    // 0x8005D158: lhu         $v0, 0x14($s6)
    ctx->r2 = MEM_HU(ctx->r22, 0X14);
    // 0x8005D15C: andi        $v0, $v0, 0xFDFF
    ctx->r2 = ctx->r2 & 0XFDFF;
    // 0x8005D160: ori         $v0, $v0, 0x400
    ctx->r2 = ctx->r2 | 0X400;
L_8005D164:
    // 0x8005D164: j           L_8005D2F0
    // 0x8005D168: sh          $v0, 0x14($s6)
    MEM_H(0X14, ctx->r22) = ctx->r2;
        goto L_8005D2F0;
    // 0x8005D168: sh          $v0, 0x14($s6)
    MEM_H(0X14, ctx->r22) = ctx->r2;
L_8005D16C:
    // 0x8005D16C: bne         $a0, $v0, L_8005D2F0
    if (ctx->r4 != ctx->r2) {
        // 0x8005D170: ori         $a0, $zero, 0xFFFF
        ctx->r4 = 0 | 0XFFFF;
            goto L_8005D2F0;
    }
    // 0x8005D170: ori         $a0, $zero, 0xFFFF
    ctx->r4 = 0 | 0XFFFF;
    // 0x8005D174: lhu         $v0, 0x14($s6)
    ctx->r2 = MEM_HU(ctx->r22, 0X14);
    // 0x8005D178: addiu       $v1, $zero, 0x400
    ctx->r3 = ADD32(0, 0X400);
    // 0x8005D17C: andi        $v0, $v0, 0x600
    ctx->r2 = ctx->r2 & 0X600;
    // 0x8005D180: bne         $v0, $v1, L_8005D2F4
    if (ctx->r2 != ctx->r3) {
        // 0x8005D184: andi        $s0, $a0, 0xFFFF
        ctx->r16 = ctx->r4 & 0XFFFF;
            goto L_8005D2F4;
    }
    // 0x8005D184: andi        $s0, $a0, 0xFFFF
    ctx->r16 = ctx->r4 & 0XFFFF;
    // 0x8005D188: lwc1        $f2, 0x0($s7)
    ctx->f2.u32l = MEM_W(ctx->r23, 0X0);
    // 0x8005D18C: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8005D190: lwc1        $f0, -0x4FD0($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X4FD0);
    // 0x8005D194: mul.s       $f4, $f2, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x8005D198: lwc1        $f2, 0xF0($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0XF0);
    // 0x8005D19C: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8005D1A0: lwc1        $f0, -0x4FCC($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X4FCC);
    // 0x8005D1A4: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x8005D1A8: nop

    // 0x8005D1AC: bc1f        L_8005D1B8
    if (!c1cs) {
        // 0x8005D1B0: addiu       $s2, $zero, -0x1
        ctx->r18 = ADD32(0, -0X1);
            goto L_8005D1B8;
    }
    // 0x8005D1B0: addiu       $s2, $zero, -0x1
    ctx->r18 = ADD32(0, -0X1);
    // 0x8005D1B4: lhu         $s2, 0xF8($s1)
    ctx->r18 = MEM_HU(ctx->r17, 0XF8);
L_8005D1B8:
    // 0x8005D1B8: addiu       $s3, $s1, 0xB4
    ctx->r19 = ADD32(ctx->r17, 0XB4);
    // 0x8005D1BC: lwc1        $f0, 0x24($s3)
    ctx->f0.u32l = MEM_W(ctx->r19, 0X24);
    // 0x8005D1C0: mul.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x8005D1C4: swc1        $f0, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->f0.u32l;
    // 0x8005D1C8: lwc1        $f0, 0x28($s3)
    ctx->f0.u32l = MEM_W(ctx->r19, 0X28);
    // 0x8005D1CC: mul.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x8005D1D0: ori         $s5, $zero, 0xFFFF
    ctx->r21 = 0 | 0XFFFF;
    // 0x8005D1D4: swc1        $f0, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->f0.u32l;
    // 0x8005D1D8: lwc1        $f0, 0x2C($s3)
    ctx->f0.u32l = MEM_W(ctx->r19, 0X2C);
    // 0x8005D1DC: addiu       $a1, $sp, 0x80
    ctx->r5 = ADD32(ctx->r29, 0X80);
    // 0x8005D1E0: mul.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x8005D1E4: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x8005D1E8: lhu         $a0, -0x6A84($v0)
    ctx->r4 = MEM_HU(ctx->r2, -0X6A84);
    // 0x8005D1EC: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8005D1F0: lwc1        $f20, -0x4FC8($at)
    ctx->f20.u32l = MEM_W(ctx->r1, -0X4FC8);
    // 0x8005D1F4: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    // 0x8005D1F8: jal         0x8003FC28
    // 0x8005D1FC: swc1        $f0, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->f0.u32l;
    func_8003FC28(rdram, ctx);
        goto after_23;
    // 0x8005D1FC: swc1        $f0, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->f0.u32l;
    after_23:
    // 0x8005D200: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    // 0x8005D204: andi        $v1, $s0, 0xFFFF
    ctx->r3 = ctx->r16 & 0XFFFF;
    // 0x8005D208: ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
    // 0x8005D20C: beq         $v1, $v0, L_8005D288
    if (ctx->r3 == ctx->r2) {
        // 0x8005D210: addu        $a0, $s5, $zero
        ctx->r4 = ADD32(ctx->r21, 0);
            goto L_8005D288;
    }
    // 0x8005D210: addu        $a0, $s5, $zero
    ctx->r4 = ADD32(ctx->r21, 0);
    // 0x8005D214: andi        $s2, $s2, 0xFFFF
    ctx->r18 = ctx->r18 & 0XFFFF;
    // 0x8005D218: addu        $s4, $v0, $zero
    ctx->r20 = ADD32(ctx->r2, 0);
L_8005D21C:
    // 0x8005D21C: beq         $s2, $s4, L_8005D22C
    if (ctx->r18 == ctx->r20) {
        // 0x8005D220: andi        $v0, $s0, 0xFFFF
        ctx->r2 = ctx->r16 & 0XFFFF;
            goto L_8005D22C;
    }
    // 0x8005D220: andi        $v0, $s0, 0xFFFF
    ctx->r2 = ctx->r16 & 0XFFFF;
    // 0x8005D224: beq         $s2, $v0, L_8005D270
    if (ctx->r18 == ctx->r2) {
        // 0x8005D228: nop
    
            goto L_8005D270;
    }
    // 0x8005D228: nop

L_8005D22C:
    // 0x8005D22C: jal         0x8004013C
    // 0x8005D230: andi        $a0, $s0, 0xFFFF
    ctx->r4 = ctx->r16 & 0XFFFF;
    func_8004013C(rdram, ctx);
        goto after_24;
    // 0x8005D230: andi        $a0, $s0, 0xFFFF
    ctx->r4 = ctx->r16 & 0XFFFF;
    after_24:
    // 0x8005D234: lw          $a0, 0xC($v0)
    ctx->r4 = MEM_W(ctx->r2, 0XC);
    // 0x8005D238: beq         $a0, $zero, L_8005D270
    if (ctx->r4 == 0) {
        // 0x8005D23C: addu        $a1, $s3, $zero
        ctx->r5 = ADD32(ctx->r19, 0);
            goto L_8005D270;
    }
    // 0x8005D23C: addu        $a1, $s3, $zero
    ctx->r5 = ADD32(ctx->r19, 0);
    // 0x8005D240: addiu       $a2, $sp, 0x88
    ctx->r6 = ADD32(ctx->r29, 0X88);
    // 0x8005D244: jal         0x8006A944
    // 0x8005D248: addiu       $a3, $sp, 0x58
    ctx->r7 = ADD32(ctx->r29, 0X58);
    func_8006A944(rdram, ctx);
        goto after_25;
    // 0x8005D248: addiu       $a3, $sp, 0x58
    ctx->r7 = ADD32(ctx->r29, 0X58);
    after_25:
    // 0x8005D24C: beq         $v0, $zero, L_8005D270
    if (ctx->r2 == 0) {
        // 0x8005D250: nop
    
            goto L_8005D270;
    }
    // 0x8005D250: nop

    // 0x8005D254: lwc1        $f0, 0x70($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X70);
    // 0x8005D258: c.lt.s      $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f0.fl < ctx->f20.fl;
    // 0x8005D25C: nop

    // 0x8005D260: bc1f        L_8005D270
    if (!c1cs) {
        // 0x8005D264: nop
    
            goto L_8005D270;
    }
    // 0x8005D264: nop

    // 0x8005D268: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x8005D26C: addu        $s5, $s0, $zero
    ctx->r21 = ADD32(ctx->r16, 0);
L_8005D270:
    // 0x8005D270: jal         0x8003EEF4
    // 0x8005D274: addiu       $a0, $sp, 0x80
    ctx->r4 = ADD32(ctx->r29, 0X80);
    func_8003EEF4(rdram, ctx);
        goto after_26;
    // 0x8005D274: addiu       $a0, $sp, 0x80
    ctx->r4 = ADD32(ctx->r29, 0X80);
    after_26:
    // 0x8005D278: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    // 0x8005D27C: andi        $v0, $s0, 0xFFFF
    ctx->r2 = ctx->r16 & 0XFFFF;
    // 0x8005D280: bne         $v0, $s4, L_8005D21C
    if (ctx->r2 != ctx->r20) {
        // 0x8005D284: addu        $a0, $s5, $zero
        ctx->r4 = ADD32(ctx->r21, 0);
            goto L_8005D21C;
    }
    // 0x8005D284: addu        $a0, $s5, $zero
    ctx->r4 = ADD32(ctx->r21, 0);
L_8005D288:
    // 0x8005D288: andi        $v1, $a0, 0xFFFF
    ctx->r3 = ctx->r4 & 0XFFFF;
    // 0x8005D28C: ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
    // 0x8005D290: beq         $v1, $v0, L_8005D380
    if (ctx->r3 == ctx->r2) {
        // 0x8005D294: nop
    
            goto L_8005D380;
    }
    // 0x8005D294: nop

    // 0x8005D298: lwc1        $f2, 0x70($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X70);
    // 0x8005D29C: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8005D2A0: lwc1        $f0, -0x4FC4($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X4FC4);
    // 0x8005D2A4: c.le.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl <= ctx->f0.fl;
    // 0x8005D2A8: nop

    // 0x8005D2AC: bc1t        L_8005D2F4
    if (c1cs) {
        // 0x8005D2B0: andi        $s0, $a0, 0xFFFF
        ctx->r16 = ctx->r4 & 0XFFFF;
            goto L_8005D2F4;
    }
    // 0x8005D2B0: andi        $s0, $a0, 0xFFFF
    ctx->r16 = ctx->r4 & 0XFFFF;
    // 0x8005D2B4: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8005D2B8: lwc1        $f0, -0x4FC0($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X4FC0);
    // 0x8005D2BC: c.le.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl <= ctx->f0.fl;
    // 0x8005D2C0: nop

    // 0x8005D2C4: bc1f        L_8005D2E0
    if (!c1cs) {
        // 0x8005D2C8: ori         $a0, $zero, 0xFFFF
        ctx->r4 = 0 | 0XFFFF;
            goto L_8005D2E0;
    }
    // 0x8005D2C8: ori         $a0, $zero, 0xFFFF
    ctx->r4 = 0 | 0XFFFF;
L_8005D2CC:
    // 0x8005D2CC: lhu         $v0, 0x14($s6)
    ctx->r2 = MEM_HU(ctx->r22, 0X14);
    // 0x8005D2D0: ori         $a0, $zero, 0xFFFF
    ctx->r4 = 0 | 0XFFFF;
    // 0x8005D2D4: andi        $v0, $v0, 0xF9FF
    ctx->r2 = ctx->r2 & 0XF9FF;
    // 0x8005D2D8: j           L_8005D2F0
    // 0x8005D2DC: sh          $v0, 0x14($s6)
    MEM_H(0X14, ctx->r22) = ctx->r2;
        goto L_8005D2F0;
    // 0x8005D2DC: sh          $v0, 0x14($s6)
    MEM_H(0X14, ctx->r22) = ctx->r2;
L_8005D2E0:
    // 0x8005D2E0: lhu         $v0, 0x14($s6)
    ctx->r2 = MEM_HU(ctx->r22, 0X14);
    // 0x8005D2E4: ori         $v0, $v0, 0x200
    ctx->r2 = ctx->r2 | 0X200;
    // 0x8005D2E8: andi        $v0, $v0, 0xFBFF
    ctx->r2 = ctx->r2 & 0XFBFF;
    // 0x8005D2EC: sh          $v0, 0x14($s6)
    MEM_H(0X14, ctx->r22) = ctx->r2;
L_8005D2F0:
    // 0x8005D2F0: andi        $s0, $a0, 0xFFFF
    ctx->r16 = ctx->r4 & 0XFFFF;
L_8005D2F4:
    // 0x8005D2F4: ori         $s2, $zero, 0xFFFF
    ctx->r18 = 0 | 0XFFFF;
    // 0x8005D2F8: beq         $s0, $s2, L_8005D380
    if (ctx->r16 == ctx->r18) {
        // 0x8005D2FC: nop
    
            goto L_8005D380;
    }
    // 0x8005D2FC: nop

    // 0x8005D300: jal         0x8006C994
    // 0x8005D304: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    func_8006C994(rdram, ctx);
        goto after_27;
    // 0x8005D304: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    after_27:
    // 0x8005D308: lhu         $v1, 0xF8($s1)
    ctx->r3 = MEM_HU(ctx->r17, 0XF8);
    // 0x8005D30C: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x8005D310: bne         $v1, $v0, L_8005D328
    if (ctx->r3 != ctx->r2) {
        // 0x8005D314: lui         $v1, 0x8013
        ctx->r3 = S32(0X8013 << 16);
            goto L_8005D328;
    }
    // 0x8005D314: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x8005D318: addiu       $v1, $v1, 0xB78
    ctx->r3 = ADD32(ctx->r3, 0XB78);
    // 0x8005D31C: lw          $v0, 0x8($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X8);
    // 0x8005D320: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8005D324: sw          $v0, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r2;
L_8005D328:
    // 0x8005D328: lhu         $v0, 0x16($s6)
    ctx->r2 = MEM_HU(ctx->r22, 0X16);
    // 0x8005D32C: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x8005D330: sh          $v0, 0x48($sp)
    MEM_H(0X48, ctx->r29) = ctx->r2;
    // 0x8005D334: lhu         $v0, 0xF8($s1)
    ctx->r2 = MEM_HU(ctx->r17, 0XF8);
    // 0x8005D338: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    // 0x8005D33C: sh          $v0, 0x4A($sp)
    MEM_H(0X4A, ctx->r29) = ctx->r2;
    // 0x8005D340: lbu         $v0, 0xFE($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0XFE);
    // 0x8005D344: addiu       $a2, $sp, 0x48
    ctx->r6 = ADD32(ctx->r29, 0X48);
    // 0x8005D348: andi        $v0, $v0, 0x1F
    ctx->r2 = ctx->r2 & 0X1F;
    // 0x8005D34C: sh          $v0, 0x4C($sp)
    MEM_H(0X4C, ctx->r29) = ctx->r2;
    // 0x8005D350: lhu         $v0, 0xFC($s1)
    ctx->r2 = MEM_HU(ctx->r17, 0XFC);
    // 0x8005D354: addiu       $s0, $sp, 0x58
    ctx->r16 = ADD32(ctx->r29, 0X58);
    // 0x8005D358: sw          $s0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r16;
    // 0x8005D35C: jal         0x8003E8DC
    // 0x8005D360: sh          $v0, 0x4E($sp)
    MEM_H(0X4E, ctx->r29) = ctx->r2;
    func_8003E8DC(rdram, ctx);
        goto after_28;
    // 0x8005D360: sh          $v0, 0x4E($sp)
    MEM_H(0X4E, ctx->r29) = ctx->r2;
    after_28:
    // 0x8005D364: lhu         $v0, 0x48($sp)
    ctx->r2 = MEM_HU(ctx->r29, 0X48);
    // 0x8005D368: bne         $v0, $s2, L_8005D380
    if (ctx->r2 != ctx->r18) {
        // 0x8005D36C: nop
    
            goto L_8005D380;
    }
    // 0x8005D36C: nop

    // 0x8005D370: jal         0x80061268
    // 0x8005D374: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_80061268(rdram, ctx);
        goto after_29;
    // 0x8005D374: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_29:
    // 0x8005D378: j           L_8005D428
    // 0x8005D37C: nop

        goto L_8005D428;
    // 0x8005D37C: nop

L_8005D380:
    // 0x8005D380: lbu         $v0, 0xFE($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0XFE);
    // 0x8005D384: andi        $v0, $v0, 0x80
    ctx->r2 = ctx->r2 & 0X80;
    // 0x8005D388: bne         $v0, $zero, L_8005D3C4
    if (ctx->r2 != 0) {
        // 0x8005D38C: andi        $v0, $fp, 0xFF
        ctx->r2 = ctx->r30 & 0XFF;
            goto L_8005D3C4;
    }
    // 0x8005D38C: andi        $v0, $fp, 0xFF
    ctx->r2 = ctx->r30 & 0XFF;
    // 0x8005D390: lui         $a2, 0x8014
    ctx->r6 = S32(0X8014 << 16);
    // 0x8005D394: addiu       $a2, $a2, -0x7FA8
    ctx->r6 = ADD32(ctx->r6, -0X7FA8);
    // 0x8005D398: lwc1        $f12, 0xB4($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0XB4);
    // 0x8005D39C: lwc1        $f14, 0xBC($s1)
    ctx->f14.u32l = MEM_W(ctx->r17, 0XBC);
    // 0x8005D3A0: jal         0x80067D90
    // 0x8005D3A4: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    func_80067D90(rdram, ctx);
        goto after_30;
    // 0x8005D3A4: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    after_30:
    // 0x8005D3A8: lwc1        $f2, 0xB8($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0XB8);
    // 0x8005D3AC: c.le.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl <= ctx->f2.fl;
    // 0x8005D3B0: nop

    // 0x8005D3B4: bc1t        L_8005D3C0
    if (c1cs) {
        // 0x8005D3B8: addiu       $fp, $zero, 0x1
        ctx->r30 = ADD32(0, 0X1);
            goto L_8005D3C0;
    }
    // 0x8005D3B8: addiu       $fp, $zero, 0x1
    ctx->r30 = ADD32(0, 0X1);
    // 0x8005D3BC: addu        $fp, $zero, $zero
    ctx->r30 = ADD32(0, 0);
L_8005D3C0:
    // 0x8005D3C0: andi        $v0, $fp, 0xFF
    ctx->r2 = ctx->r30 & 0XFF;
L_8005D3C4:
    // 0x8005D3C4: beq         $v0, $zero, L_8005D4A0
    if (ctx->r2 == 0) {
        // 0x8005D3C8: addiu       $a0, $sp, 0x80
        ctx->r4 = ADD32(ctx->r29, 0X80);
            goto L_8005D4A0;
    }
    // 0x8005D3C8: addiu       $a0, $sp, 0x80
    ctx->r4 = ADD32(ctx->r29, 0X80);
    // 0x8005D3CC: lwc1        $f2, 0xD8($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0XD8);
    // 0x8005D3D0: lwc1        $f0, 0x0($s7)
    ctx->f0.u32l = MEM_W(ctx->r23, 0X0);
    // 0x8005D3D4: mul.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x8005D3D8: lwc1        $f0, 0xB4($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0XB4);
    // 0x8005D3DC: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x8005D3E0: swc1        $f0, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->f0.u32l;
    // 0x8005D3E4: lwc1        $f2, 0xDC($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0XDC);
    // 0x8005D3E8: lwc1        $f0, 0x0($s7)
    ctx->f0.u32l = MEM_W(ctx->r23, 0X0);
    // 0x8005D3EC: mul.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x8005D3F0: lwc1        $f0, 0xB8($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0XB8);
    // 0x8005D3F4: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x8005D3F8: swc1        $f0, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->f0.u32l;
    // 0x8005D3FC: lwc1        $f0, 0xE0($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0XE0);
    // 0x8005D400: lwc1        $f2, 0x0($s7)
    ctx->f2.u32l = MEM_W(ctx->r23, 0X0);
    // 0x8005D404: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x8005D408: lwc1        $f2, 0xBC($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0XBC);
    // 0x8005D40C: sub.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl - ctx->f0.fl;
    // 0x8005D410: addiu       $a1, $s1, 0xC0
    ctx->r5 = ADD32(ctx->r17, 0XC0);
    // 0x8005D414: swc1        $f2, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->f2.u32l;
    // 0x8005D418: lhu         $a2, 0xF8($s1)
    ctx->r6 = MEM_HU(ctx->r17, 0XF8);
    // 0x8005D41C: jal         0x8007483C
    // 0x8005D420: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    func_8007483C(rdram, ctx);
        goto after_31;
    // 0x8005D420: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    after_31:
    // 0x8005D424: sb          $v0, 0xA0($sp)
    MEM_B(0XA0, ctx->r29) = ctx->r2;
L_8005D428:
    // 0x8005D428: lbu         $v0, 0xA0($sp)
    ctx->r2 = MEM_BU(ctx->r29, 0XA0);
    // 0x8005D42C: sw          $zero, 0x80($sp)
    MEM_W(0X80, ctx->r29) = 0;
    // 0x8005D430: sw          $zero, 0x84($sp)
    MEM_W(0X84, ctx->r29) = 0;
    // 0x8005D434: bne         $v0, $zero, L_8005D45C
    if (ctx->r2 != 0) {
        // 0x8005D438: sw          $zero, 0x88($sp)
        MEM_W(0X88, ctx->r29) = 0;
            goto L_8005D45C;
    }
    // 0x8005D438: sw          $zero, 0x88($sp)
    MEM_W(0X88, ctx->r29) = 0;
    // 0x8005D43C: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x8005D440: addiu       $a1, $s1, 0xB4
    ctx->r5 = ADD32(ctx->r17, 0XB4);
    // 0x8005D444: addiu       $a2, $sp, 0x80
    ctx->r6 = ADD32(ctx->r29, 0X80);
    // 0x8005D448: lui         $a3, 0x41C0
    ctx->r7 = S32(0X41C0 << 16);
    // 0x8005D44C: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8005D450: lwc1        $f0, -0x4FBC($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X4FBC);
    // 0x8005D454: j           L_8005D478
    // 0x8005D458: addiu       $v0, $zero, 0xC
    ctx->r2 = ADD32(0, 0XC);
        goto L_8005D478;
    // 0x8005D458: addiu       $v0, $zero, 0xC
    ctx->r2 = ADD32(0, 0XC);
L_8005D45C:
    // 0x8005D45C: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x8005D460: addiu       $a1, $s1, 0xB4
    ctx->r5 = ADD32(ctx->r17, 0XB4);
    // 0x8005D464: addiu       $a2, $sp, 0x80
    ctx->r6 = ADD32(ctx->r29, 0X80);
    // 0x8005D468: lui         $a3, 0x4190
    ctx->r7 = S32(0X4190 << 16);
    // 0x8005D46C: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8005D470: lwc1        $f0, -0x4FB8($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X4FB8);
    // 0x8005D474: addiu       $v0, $zero, 0x74
    ctx->r2 = ADD32(0, 0X74);
L_8005D478:
    // 0x8005D478: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // 0x8005D47C: addiu       $v0, $zero, 0x78
    ctx->r2 = ADD32(0, 0X78);
    // 0x8005D480: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x8005D484: addiu       $v0, $zero, 0x1E
    ctx->r2 = ADD32(0, 0X1E);
    // 0x8005D488: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x8005D48C: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x8005D490: jal         0x800989D8
    // 0x8005D494: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    func_800989D8(rdram, ctx);
        goto after_32;
    // 0x8005D494: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    after_32:
    // 0x8005D498: j           L_8005CE44
    // 0x8005D49C: nop

        goto L_8005CE44;
    // 0x8005D49C: nop

L_8005D4A0:
    // 0x8005D4A0: lbu         $v0, 0xFE($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0XFE);
    // 0x8005D4A4: andi        $v1, $v0, 0x1F
    ctx->r3 = ctx->r2 & 0X1F;
    // 0x8005D4A8: addiu       $v0, $v1, -0x4
    ctx->r2 = ADD32(ctx->r3, -0X4);
    // 0x8005D4AC: sltiu       $v0, $v0, 0x2
    ctx->r2 = ctx->r2 < 0X2 ? 1 : 0;
    // 0x8005D4B0: bne         $v0, $zero, L_8005D4C0
    if (ctx->r2 != 0) {
        // 0x8005D4B4: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_8005D4C0;
    }
    // 0x8005D4B4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8005D4B8: bne         $v1, $v0, L_8005D4CC
    if (ctx->r3 != ctx->r2) {
        // 0x8005D4BC: nop
    
            goto L_8005D4CC;
    }
    // 0x8005D4BC: nop

L_8005D4C0:
    // 0x8005D4C0: lw          $a1, 0x0($s7)
    ctx->r5 = MEM_W(ctx->r23, 0X0);
    // 0x8005D4C4: jal         0x8005C620
    // 0x8005D4C8: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    func_8005C620(rdram, ctx);
        goto after_33;
    // 0x8005D4C8: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    after_33:
L_8005D4CC:
    // 0x8005D4CC: lwc1        $f2, 0xD8($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0XD8);
    // 0x8005D4D0: lwc1        $f0, 0x0($s7)
    ctx->f0.u32l = MEM_W(ctx->r23, 0X0);
    // 0x8005D4D4: mul.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x8005D4D8: lwc1        $f0, 0xB4($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0XB4);
    // 0x8005D4DC: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x8005D4E0: lwc1        $f2, 0xDC($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0XDC);
    // 0x8005D4E4: swc1        $f0, 0xB4($s1)
    MEM_W(0XB4, ctx->r17) = ctx->f0.u32l;
    // 0x8005D4E8: lwc1        $f0, 0x0($s7)
    ctx->f0.u32l = MEM_W(ctx->r23, 0X0);
    // 0x8005D4EC: mul.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x8005D4F0: lwc1        $f0, 0xB8($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0XB8);
    // 0x8005D4F4: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x8005D4F8: lwc1        $f2, 0xE0($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0XE0);
    // 0x8005D4FC: swc1        $f0, 0xB8($s1)
    MEM_W(0XB8, ctx->r17) = ctx->f0.u32l;
    // 0x8005D500: lwc1        $f0, 0x0($s7)
    ctx->f0.u32l = MEM_W(ctx->r23, 0X0);
    // 0x8005D504: mul.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x8005D508: lwc1        $f0, 0xBC($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0XBC);
    // 0x8005D50C: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x8005D510: lhu         $v1, 0xFA($s1)
    ctx->r3 = MEM_HU(ctx->r17, 0XFA);
    // 0x8005D514: ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
    // 0x8005D518: beq         $v1, $v0, L_8005D55C
    if (ctx->r3 == ctx->r2) {
        // 0x8005D51C: swc1        $f0, 0xBC($s1)
        MEM_W(0XBC, ctx->r17) = ctx->f0.u32l;
            goto L_8005D55C;
    }
    // 0x8005D51C: swc1        $f0, 0xBC($s1)
    MEM_W(0XBC, ctx->r17) = ctx->f0.u32l;
    // 0x8005D520: lwc1        $f0, 0xB4($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0XB4);
    // 0x8005D524: swc1        $f0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f0.u32l;
    // 0x8005D528: lwc1        $f0, 0xB8($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0XB8);
    // 0x8005D52C: addiu       $a1, $zero, 0x1000
    ctx->r5 = ADD32(0, 0X1000);
    // 0x8005D530: swc1        $f0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f0.u32l;
    // 0x8005D534: lwc1        $f2, 0xBC($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0XBC);
    // 0x8005D538: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8005D53C: lwc1        $f0, -0x4FB4($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X4FB4);
    // 0x8005D540: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8005D544: sh          $v0, 0x38($sp)
    MEM_H(0X38, ctx->r29) = ctx->r2;
    // 0x8005D548: swc1        $f0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f0.u32l;
    // 0x8005D54C: swc1        $f2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f2.u32l;
    // 0x8005D550: lhu         $a0, 0xFA($s1)
    ctx->r4 = MEM_HU(ctx->r17, 0XFA);
    // 0x8005D554: jal         0x8003E8DC
    // 0x8005D558: addiu       $a2, $sp, 0x28
    ctx->r6 = ADD32(ctx->r29, 0X28);
    func_8003E8DC(rdram, ctx);
        goto after_34;
    // 0x8005D558: addiu       $a2, $sp, 0x28
    ctx->r6 = ADD32(ctx->r29, 0X28);
    after_34:
L_8005D55C:
    // 0x8005D55C: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x8005D560: lwc1        $f2, 0xB4($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0XB4);
    // 0x8005D564: lwc1        $f0, -0x64A8($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, -0X64A8);
    // 0x8005D568: sub.s       $f0, $f2, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f2.fl - ctx->f0.fl;
    // 0x8005D56C: mul.s       $f6, $f0, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x8005D570: addiu       $v0, $v0, -0x64A8
    ctx->r2 = ADD32(ctx->r2, -0X64A8);
    // 0x8005D574: lwc1        $f2, 0xB8($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0XB8);
    // 0x8005D578: lwc1        $f0, 0x4($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X4);
    // 0x8005D57C: sub.s       $f0, $f2, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f2.fl - ctx->f0.fl;
    // 0x8005D580: mul.s       $f4, $f0, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x8005D584: lwc1        $f2, 0xBC($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0XBC);
    // 0x8005D588: lwc1        $f0, 0x8($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X8);
    // 0x8005D58C: sub.s       $f0, $f2, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f2.fl - ctx->f0.fl;
    // 0x8005D590: mul.s       $f0, $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x8005D594: add.s       $f6, $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f4.fl;
    // 0x8005D598: addiu       $s0, $zero, 0xFF
    ctx->r16 = ADD32(0, 0XFF);
    // 0x8005D59C: lbu         $v0, 0xFF($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0XFF);
    // 0x8005D5A0: beq         $v0, $s0, L_8005D640
    if (ctx->r2 == ctx->r16) {
        // 0x8005D5A4: add.s       $f6, $f6, $f0
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f0.fl;
            goto L_8005D640;
    }
    // 0x8005D5A4: add.s       $f6, $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f0.fl;
    // 0x8005D5A8: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8005D5AC: lwc1        $f0, -0x4FB0($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X4FB0);
    // 0x8005D5B0: c.lt.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl < ctx->f6.fl;
    // 0x8005D5B4: nop

    // 0x8005D5B8: bc1f        L_8005D60C
    if (!c1cs) {
        // 0x8005D5BC: addu        $v1, $v0, $zero
        ctx->r3 = ADD32(ctx->r2, 0);
            goto L_8005D60C;
    }
    // 0x8005D5BC: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // 0x8005D5C0: sll         $v0, $v1, 4
    ctx->r2 = S32(ctx->r3 << 4);
    // 0x8005D5C4: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8005D5C8: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8005D5CC: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8005D5D0: addiu       $a0, $a0, -0x69E0
    ctx->r4 = ADD32(ctx->r4, -0X69E0);
    // 0x8005D5D4: jal         0x80098DE0
    // 0x8005D5D8: addu        $a0, $v0, $a0
    ctx->r4 = ADD32(ctx->r2, ctx->r4);
    func_80098DE0(rdram, ctx);
        goto after_35;
    // 0x8005D5D8: addu        $a0, $v0, $a0
    ctx->r4 = ADD32(ctx->r2, ctx->r4);
    after_35:
    // 0x8005D5DC: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8005D5E0: lbu         $v1, -0x68D0($a0)
    ctx->r3 = MEM_BU(ctx->r4, -0X68D0);
    // 0x8005D5E4: addiu       $v0, $v1, 0x1
    ctx->r2 = ADD32(ctx->r3, 0X1);
    // 0x8005D5E8: sb          $v0, -0x68D0($a0)
    MEM_B(-0X68D0, ctx->r4) = ctx->r2;
    // 0x8005D5EC: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x8005D5F0: addiu       $v0, $v0, -0x68CC
    ctx->r2 = ADD32(ctx->r2, -0X68CC);
    // 0x8005D5F4: andi        $v1, $v1, 0xFF
    ctx->r3 = ctx->r3 & 0XFF;
    // 0x8005D5F8: lbu         $a0, 0xFF($s1)
    ctx->r4 = MEM_BU(ctx->r17, 0XFF);
    // 0x8005D5FC: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x8005D600: sb          $a0, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r4;
    // 0x8005D604: j           L_8005D914
    // 0x8005D608: sb          $s0, 0xFF($s1)
    MEM_B(0XFF, ctx->r17) = ctx->r16;
        goto L_8005D914;
    // 0x8005D608: sb          $s0, 0xFF($s1)
    MEM_B(0XFF, ctx->r17) = ctx->r16;
L_8005D60C:
    // 0x8005D60C: addiu       $a1, $s1, 0xB4
    ctx->r5 = ADD32(ctx->r17, 0XB4);
    // 0x8005D610: addiu       $a2, $s1, 0xD8
    ctx->r6 = ADD32(ctx->r17, 0XD8);
    // 0x8005D614: lbu         $v1, 0xFF($s1)
    ctx->r3 = MEM_BU(ctx->r17, 0XFF);
    // 0x8005D618: addiu       $a3, $zero, 0x50
    ctx->r7 = ADD32(0, 0X50);
    // 0x8005D61C: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8005D620: addiu       $a0, $a0, -0x69E0
    ctx->r4 = ADD32(ctx->r4, -0X69E0);
    // 0x8005D624: sll         $v0, $v1, 4
    ctx->r2 = S32(ctx->r3 << 4);
    // 0x8005D628: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8005D62C: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8005D630: jal         0x800988E8
    // 0x8005D634: addu        $a0, $v0, $a0
    ctx->r4 = ADD32(ctx->r2, ctx->r4);
    func_800988E8(rdram, ctx);
        goto after_36;
    // 0x8005D634: addu        $a0, $v0, $a0
    ctx->r4 = ADD32(ctx->r2, ctx->r4);
    after_36:
    // 0x8005D638: j           L_8005D918
    // 0x8005D63C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8005D918;
    // 0x8005D63C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8005D640:
    // 0x8005D640: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x8005D644: lbu         $v1, -0x68D0($v0)
    ctx->r3 = MEM_BU(ctx->r2, -0X68D0);
    // 0x8005D648: beql        $v1, $zero, L_8005D918
    if (ctx->r3 == 0) {
        // 0x8005D64C: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_8005D918;
    }
    goto skip_4;
    // 0x8005D64C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_4:
    // 0x8005D650: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8005D654: lwc1        $f0, -0x4FAC($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X4FAC);
    // 0x8005D658: c.lt.s      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.fl < ctx->f0.fl;
    // 0x8005D65C: nop

    // 0x8005D660: bc1f        L_8005D914
    if (!c1cs) {
        // 0x8005D664: addiu       $v1, $v1, -0x1
        ctx->r3 = ADD32(ctx->r3, -0X1);
            goto L_8005D914;
    }
    // 0x8005D664: addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
    // 0x8005D668: sb          $v1, -0x68D0($v0)
    MEM_B(-0X68D0, ctx->r2) = ctx->r3;
    // 0x8005D66C: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x8005D670: addiu       $v0, $v0, -0x68CC
    ctx->r2 = ADD32(ctx->r2, -0X68CC);
    // 0x8005D674: andi        $v1, $v1, 0xFF
    ctx->r3 = ctx->r3 & 0XFF;
    // 0x8005D678: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x8005D67C: addiu       $a1, $s1, 0xB4
    ctx->r5 = ADD32(ctx->r17, 0XB4);
    // 0x8005D680: addiu       $a2, $s1, 0xD8
    ctx->r6 = ADD32(ctx->r17, 0XD8);
    // 0x8005D684: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8005D688: lui         $a3, 0x3FC0
    ctx->r7 = S32(0X3FC0 << 16);
    // 0x8005D68C: lbu         $v0, 0x0($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X0);
    // 0x8005D690: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8005D694: lwc1        $f0, -0x4FA8($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X4FA8);
    // 0x8005D698: addiu       $a0, $a0, -0x69E0
    ctx->r4 = ADD32(ctx->r4, -0X69E0);
    // 0x8005D69C: sb          $v0, 0xFF($s1)
    MEM_B(0XFF, ctx->r17) = ctx->r2;
    // 0x8005D6A0: andi        $v1, $v0, 0xFF
    ctx->r3 = ctx->r2 & 0XFF;
    // 0x8005D6A4: addiu       $v0, $zero, 0xF
    ctx->r2 = ADD32(0, 0XF);
    // 0x8005D6A8: sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    // 0x8005D6AC: addiu       $v0, $zero, 0x29
    ctx->r2 = ADD32(0, 0X29);
    // 0x8005D6B0: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // 0x8005D6B4: addiu       $v0, $zero, 0xA
    ctx->r2 = ADD32(0, 0XA);
    // 0x8005D6B8: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x8005D6BC: addiu       $v0, $zero, 0x50
    ctx->r2 = ADD32(0, 0X50);
    // 0x8005D6C0: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x8005D6C4: addiu       $v0, $zero, 0x14
    ctx->r2 = ADD32(0, 0X14);
    // 0x8005D6C8: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x8005D6CC: sll         $v0, $v1, 4
    ctx->r2 = S32(ctx->r3 << 4);
    // 0x8005D6D0: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8005D6D4: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8005D6D8: addu        $a0, $v0, $a0
    ctx->r4 = ADD32(ctx->r2, ctx->r4);
    // 0x8005D6DC: jal         0x80098BDC
    // 0x8005D6E0: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    func_80098BDC(rdram, ctx);
        goto after_37;
    // 0x8005D6E0: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    after_37:
    // 0x8005D6E4: j           L_8005D918
    // 0x8005D6E8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8005D918;
    // 0x8005D6E8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8005D6EC:
    // 0x8005D6EC: addiu       $a0, $s1, 0x28
    ctx->r4 = ADD32(ctx->r17, 0X28);
    // 0x8005D6F0: addiu       $s0, $s1, 0xB4
    ctx->r16 = ADD32(ctx->r17, 0XB4);
    // 0x8005D6F4: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x8005D6F8: jal         0x80059C24
    // 0x8005D6FC: addiu       $a2, $s1, 0xE4
    ctx->r6 = ADD32(ctx->r17, 0XE4);
    func_80059C24(rdram, ctx);
        goto after_38;
    // 0x8005D6FC: addiu       $a2, $s1, 0xE4
    ctx->r6 = ADD32(ctx->r17, 0XE4);
    after_38:
    // 0x8005D700: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    // 0x8005D704: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    // 0x8005D708: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x8005D70C: jal         0x80057C8C
    // 0x8005D710: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    func_80057C8C(rdram, ctx);
        goto after_39;
    // 0x8005D710: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    after_39:
    // 0x8005D714: j           L_8005D918
    // 0x8005D718: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8005D918;
    // 0x8005D718: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8005D71C:
    // 0x8005D71C: lh          $v1, 0x0($s2)
    ctx->r3 = MEM_H(ctx->r18, 0X0);
    // 0x8005D720: addiu       $s3, $zero, 0x1
    ctx->r19 = ADD32(0, 0X1);
    // 0x8005D724: beq         $v1, $s3, L_8005D754
    if (ctx->r3 == ctx->r19) {
        // 0x8005D728: slti        $v0, $v1, 0x2
        ctx->r2 = SIGNED(ctx->r3) < 0X2 ? 1 : 0;
            goto L_8005D754;
    }
    // 0x8005D728: slti        $v0, $v1, 0x2
    ctx->r2 = SIGNED(ctx->r3) < 0X2 ? 1 : 0;
    // 0x8005D72C: beq         $v0, $zero, L_8005D744
    if (ctx->r2 == 0) {
        // 0x8005D730: addiu       $v0, $zero, 0x2
        ctx->r2 = ADD32(0, 0X2);
            goto L_8005D744;
    }
    // 0x8005D730: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x8005D734: beq         $v1, $zero, L_8005D81C
    if (ctx->r3 == 0) {
        // 0x8005D738: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_8005D81C;
    }
    // 0x8005D738: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8005D73C: j           L_8005D918
    // 0x8005D740: nop

        goto L_8005D918;
    // 0x8005D740: nop

L_8005D744:
    // 0x8005D744: beq         $v1, $v0, L_8005D7C0
    if (ctx->r3 == ctx->r2) {
        // 0x8005D748: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_8005D7C0;
    }
    // 0x8005D748: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8005D74C: j           L_8005D918
    // 0x8005D750: nop

        goto L_8005D918;
    // 0x8005D750: nop

L_8005D754:
    // 0x8005D754: lhu         $v0, 0xFC($s1)
    ctx->r2 = MEM_HU(ctx->r17, 0XFC);
    // 0x8005D758: lwc1        $f2, 0x18($s2)
    ctx->f2.u32l = MEM_W(ctx->r18, 0X18);
    // 0x8005D75C: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x8005D760: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x8005D764: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x8005D768: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8005D76C: lwc1        $f2, -0x4FA4($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X4FA4);
    // 0x8005D770: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x8005D774: nop

    // 0x8005D778: bc1tl       L_8005D780
    if (c1cs) {
        // 0x8005D77C: mov.s       $f0, $f2
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
            goto L_8005D780;
    }
    goto skip_5;
    // 0x8005D77C: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    skip_5:
L_8005D780:
    // 0x8005D780: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8005D784: lwc1        $f2, -0x4FA0($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X4FA0);
    // 0x8005D788: c.le.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl <= ctx->f0.fl;
    // 0x8005D78C: nop

    // 0x8005D790: bc1tl       L_8005D7A8
    if (c1cs) {
        // 0x8005D794: sub.s       $f0, $f0, $f2
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
            goto L_8005D7A8;
    }
    goto skip_6;
    // 0x8005D794: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    skip_6:
    // 0x8005D798: trunc.w.s   $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    ctx->f8.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x8005D79C: mfc1        $v1, $f8
    ctx->r3 = (int32_t)ctx->f8.u32l;
    // 0x8005D7A0: j           L_8005D914
    // 0x8005D7A4: sh          $v1, 0xFC($s1)
    MEM_H(0XFC, ctx->r17) = ctx->r3;
        goto L_8005D914;
    // 0x8005D7A4: sh          $v1, 0xFC($s1)
    MEM_H(0XFC, ctx->r17) = ctx->r3;
L_8005D7A8:
    // 0x8005D7A8: lui         $v0, 0x8000
    ctx->r2 = S32(0X8000 << 16);
    // 0x8005D7AC: trunc.w.s   $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    ctx->f8.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x8005D7B0: mfc1        $v1, $f8
    ctx->r3 = (int32_t)ctx->f8.u32l;
    // 0x8005D7B4: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x8005D7B8: j           L_8005D914
    // 0x8005D7BC: sh          $v1, 0xFC($s1)
    MEM_H(0XFC, ctx->r17) = ctx->r3;
        goto L_8005D914;
    // 0x8005D7BC: sh          $v1, 0xFC($s1)
    MEM_H(0XFC, ctx->r17) = ctx->r3;
L_8005D7C0:
    // 0x8005D7C0: lwc1        $f2, 0x18($s2)
    ctx->f2.u32l = MEM_W(ctx->r18, 0X18);
    // 0x8005D7C4: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8005D7C8: c.eq.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl == ctx->f0.fl;
    // 0x8005D7CC: nop

    // 0x8005D7D0: bc1t        L_8005D7EC
    if (c1cs) {
        // 0x8005D7D4: nop
    
            goto L_8005D7EC;
    }
    // 0x8005D7D4: nop

    // 0x8005D7D8: jal         0x8001CF2C
    // 0x8005D7DC: addiu       $a0, $s1, 0xD8
    ctx->r4 = ADD32(ctx->r17, 0XD8);
    func_8001CF2C(rdram, ctx);
        goto after_40;
    // 0x8005D7DC: addiu       $a0, $s1, 0xD8
    ctx->r4 = ADD32(ctx->r17, 0XD8);
    after_40:
    // 0x8005D7E0: lwc1        $f2, 0x18($s2)
    ctx->f2.u32l = MEM_W(ctx->r18, 0X18);
    // 0x8005D7E4: div.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = DIV_S(ctx->f2.fl, ctx->f0.fl);
    // 0x8005D7E8: swc1        $f2, 0xF4($s1)
    MEM_W(0XF4, ctx->r17) = ctx->f2.u32l;
L_8005D7EC:
    // 0x8005D7EC: lbu         $v0, 0x1C($s2)
    ctx->r2 = MEM_BU(ctx->r18, 0X1C);
    // 0x8005D7F0: beq         $v0, $zero, L_8005D918
    if (ctx->r2 == 0) {
        // 0x8005D7F4: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_8005D918;
    }
    // 0x8005D7F4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8005D7F8: lbu         $v1, 0xFE($s1)
    ctx->r3 = MEM_BU(ctx->r17, 0XFE);
    // 0x8005D7FC: ori         $v0, $v1, 0x80
    ctx->r2 = ctx->r3 | 0X80;
    // 0x8005D800: sb          $v0, 0xFE($s1)
    MEM_B(0XFE, ctx->r17) = ctx->r2;
    // 0x8005D804: lbu         $v0, 0x1C($s2)
    ctx->r2 = MEM_BU(ctx->r18, 0X1C);
    // 0x8005D808: bne         $v0, $s3, L_8005D918
    if (ctx->r2 != ctx->r19) {
        // 0x8005D80C: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_8005D918;
    }
    // 0x8005D80C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8005D810: ori         $v0, $v1, 0xC0
    ctx->r2 = ctx->r3 | 0XC0;
    // 0x8005D814: j           L_8005D914
    // 0x8005D818: sb          $v0, 0xFE($s1)
    MEM_B(0XFE, ctx->r17) = ctx->r2;
        goto L_8005D914;
    // 0x8005D818: sb          $v0, 0xFE($s1)
    MEM_B(0XFE, ctx->r17) = ctx->r2;
L_8005D81C:
    // 0x8005D81C: lbu         $v0, 0xFE($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0XFE);
    // 0x8005D820: andi        $v1, $v0, 0x1F
    ctx->r3 = ctx->r2 & 0X1F;
    // 0x8005D824: addiu       $v0, $v1, -0x4
    ctx->r2 = ADD32(ctx->r3, -0X4);
    // 0x8005D828: sltiu       $v0, $v0, 0x2
    ctx->r2 = ctx->r2 < 0X2 ? 1 : 0;
    // 0x8005D82C: bnel        $v0, $zero, L_8005D840
    if (ctx->r2 != 0) {
        // 0x8005D830: sb          $zero, 0x11C($s1)
        MEM_B(0X11C, ctx->r17) = 0;
            goto L_8005D840;
    }
    goto skip_7;
    // 0x8005D830: sb          $zero, 0x11C($s1)
    MEM_B(0X11C, ctx->r17) = 0;
    skip_7:
    // 0x8005D834: bne         $v1, $s3, L_8005D918
    if (ctx->r3 != ctx->r19) {
        // 0x8005D838: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_8005D918;
    }
    // 0x8005D838: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8005D83C: sb          $zero, 0x11C($s1)
    MEM_B(0X11C, ctx->r17) = 0;
L_8005D840:
    // 0x8005D840: lhu         $v0, 0x2($s2)
    ctx->r2 = MEM_HU(ctx->r18, 0X2);
    // 0x8005D844: ori         $s0, $zero, 0xFFFF
    ctx->r16 = 0 | 0XFFFF;
    // 0x8005D848: beq         $v0, $s0, L_8005D918
    if (ctx->r2 == ctx->r16) {
        // 0x8005D84C: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_8005D918;
    }
    // 0x8005D84C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8005D850: lwc1        $f2, 0x10($s2)
    ctx->f2.u32l = MEM_W(ctx->r18, 0X10);
    // 0x8005D854: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8005D858: c.eq.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl == ctx->f0.fl;
    // 0x8005D85C: nop

    // 0x8005D860: bc1t        L_8005D918
    if (c1cs) {
        // 0x8005D864: nop
    
            goto L_8005D918;
    }
    // 0x8005D864: nop

    // 0x8005D868: lhu         $v0, 0x118($s1)
    ctx->r2 = MEM_HU(ctx->r17, 0X118);
    // 0x8005D86C: bne         $v0, $s0, L_8005D88C
    if (ctx->r2 != ctx->r16) {
        // 0x8005D870: nop
    
            goto L_8005D88C;
    }
    // 0x8005D870: nop

    // 0x8005D874: jal         0x8003E5F8
    // 0x8005D878: addu        $a0, $s6, $zero
    ctx->r4 = ADD32(ctx->r22, 0);
    func_8003E5F8(rdram, ctx);
        goto after_41;
    // 0x8005D878: addu        $a0, $s6, $zero
    ctx->r4 = ADD32(ctx->r22, 0);
    after_41:
    // 0x8005D87C: sh          $v0, 0x118($s1)
    MEM_H(0X118, ctx->r17) = ctx->r2;
    // 0x8005D880: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x8005D884: beq         $v0, $s0, L_8005D918
    if (ctx->r2 == ctx->r16) {
        // 0x8005D888: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_8005D918;
    }
    // 0x8005D888: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8005D88C:
    // 0x8005D88C: lhu         $a0, 0x2($s2)
    ctx->r4 = MEM_HU(ctx->r18, 0X2);
    // 0x8005D890: jal         0x8004013C
    // 0x8005D894: nop

    func_8004013C(rdram, ctx);
        goto after_42;
    // 0x8005D894: nop

    after_42:
    // 0x8005D898: lhu         $a0, 0x118($s1)
    ctx->r4 = MEM_HU(ctx->r17, 0X118);
    // 0x8005D89C: jal         0x8003E684
    // 0x8005D8A0: addu        $a1, $v0, $zero
    ctx->r5 = ADD32(ctx->r2, 0);
    func_8003E684(rdram, ctx);
        goto after_43;
    // 0x8005D8A0: addu        $a1, $v0, $zero
    ctx->r5 = ADD32(ctx->r2, 0);
    after_43:
    // 0x8005D8A4: sh          $v0, 0x11A($s1)
    MEM_H(0X11A, ctx->r17) = ctx->r2;
    // 0x8005D8A8: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x8005D8AC: beq         $v0, $s0, L_8005D918
    if (ctx->r2 == ctx->r16) {
        // 0x8005D8B0: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_8005D918;
    }
    // 0x8005D8B0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8005D8B4: sb          $s3, 0x11C($s1)
    MEM_B(0X11C, ctx->r17) = ctx->r19;
    // 0x8005D8B8: lw          $t1, 0xC0($s1)
    ctx->r9 = MEM_W(ctx->r17, 0XC0);
    // 0x8005D8BC: lw          $t2, 0xC4($s1)
    ctx->r10 = MEM_W(ctx->r17, 0XC4);
    // 0x8005D8C0: lw          $t3, 0xC8($s1)
    ctx->r11 = MEM_W(ctx->r17, 0XC8);
    // 0x8005D8C4: sw          $t1, 0x100($s1)
    MEM_W(0X100, ctx->r17) = ctx->r9;
    // 0x8005D8C8: sw          $t2, 0x104($s1)
    MEM_W(0X104, ctx->r17) = ctx->r10;
    // 0x8005D8CC: sw          $t3, 0x108($s1)
    MEM_W(0X108, ctx->r17) = ctx->r11;
    // 0x8005D8D0: lwc1        $f0, 0x10($s2)
    ctx->f0.u32l = MEM_W(ctx->r18, 0X10);
    // 0x8005D8D4: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8005D8D8: lwc1        $f12, -0x4F9C($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X4F9C);
    // 0x8005D8DC: mul.s       $f12, $f0, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = MUL_S(ctx->f0.fl, ctx->f12.fl);
    // 0x8005D8E0: jal         0x8002B190
    // 0x8005D8E4: nop

    cosf_recomp(rdram, ctx);
        goto after_44;
    // 0x8005D8E4: nop

    after_44:
    // 0x8005D8E8: swc1        $f0, 0x110($s1)
    MEM_W(0X110, ctx->r17) = ctx->f0.u32l;
    // 0x8005D8EC: lwc1        $f0, 0xC($s2)
    ctx->f0.u32l = MEM_W(ctx->r18, 0XC);
    // 0x8005D8F0: j           L_8005D914
    // 0x8005D8F4: swc1        $f0, 0x114($s1)
    MEM_W(0X114, ctx->r17) = ctx->f0.u32l;
        goto L_8005D914;
    // 0x8005D8F4: swc1        $f0, 0x114($s1)
    MEM_W(0X114, ctx->r17) = ctx->f0.u32l;
L_8005D8F8:
    // 0x8005D8F8: lbu         $v0, 0xFE($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0XFE);
    // 0x8005D8FC: addiu       $v1, $zero, 0xC
    ctx->r3 = ADD32(0, 0XC);
    // 0x8005D900: andi        $v0, $v0, 0x1F
    ctx->r2 = ctx->r2 & 0X1F;
    // 0x8005D904: bne         $v0, $v1, L_8005D910
    if (ctx->r2 != ctx->r3) {
        // 0x8005D908: addiu       $v0, $zero, 0x1000
        ctx->r2 = ADD32(0, 0X1000);
            goto L_8005D910;
    }
    // 0x8005D908: addiu       $v0, $zero, 0x1000
    ctx->r2 = ADD32(0, 0X1000);
    // 0x8005D90C: addiu       $v0, $zero, 0x1001
    ctx->r2 = ADD32(0, 0X1001);
L_8005D910:
    // 0x8005D910: sh          $v0, 0x2($s2)
    MEM_H(0X2, ctx->r18) = ctx->r2;
L_8005D914:
    // 0x8005D914: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8005D918:
    // 0x8005D918: lw          $ra, 0xCC($sp)
    ctx->r31 = MEM_W(ctx->r29, 0XCC);
    // 0x8005D91C: lw          $fp, 0xC8($sp)
    ctx->r30 = MEM_W(ctx->r29, 0XC8);
    // 0x8005D920: lw          $s7, 0xC4($sp)
    ctx->r23 = MEM_W(ctx->r29, 0XC4);
    // 0x8005D924: lw          $s6, 0xC0($sp)
    ctx->r22 = MEM_W(ctx->r29, 0XC0);
    // 0x8005D928: lw          $s5, 0xBC($sp)
    ctx->r21 = MEM_W(ctx->r29, 0XBC);
    // 0x8005D92C: lw          $s4, 0xB8($sp)
    ctx->r20 = MEM_W(ctx->r29, 0XB8);
    // 0x8005D930: lw          $s3, 0xB4($sp)
    ctx->r19 = MEM_W(ctx->r29, 0XB4);
    // 0x8005D934: lw          $s2, 0xB0($sp)
    ctx->r18 = MEM_W(ctx->r29, 0XB0);
    // 0x8005D938: lw          $s1, 0xAC($sp)
    ctx->r17 = MEM_W(ctx->r29, 0XAC);
    // 0x8005D93C: lw          $s0, 0xA8($sp)
    ctx->r16 = MEM_W(ctx->r29, 0XA8);
    // 0x8005D940: ldc1        $f20, 0xD0($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0XD0);
    // 0x8005D944: jr          $ra
    // 0x8005D948: addiu       $sp, $sp, 0xD8
    ctx->r29 = ADD32(ctx->r29, 0XD8);
    return;
    // 0x8005D948: addiu       $sp, $sp, 0xD8
    ctx->r29 = ADD32(ctx->r29, 0XD8);
;}
RECOMP_FUNC void func_8005D94C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005D94C: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x8005D950: sw          $s1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r17;
    // 0x8005D954: addu        $s1, $a0, $zero
    ctx->r17 = ADD32(ctx->r4, 0);
    // 0x8005D958: sw          $s2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r18;
    // 0x8005D95C: addu        $s2, $a1, $zero
    ctx->r18 = ADD32(ctx->r5, 0);
    // 0x8005D960: addiu       $a1, $sp, 0x10
    ctx->r5 = ADD32(ctx->r29, 0X10);
    // 0x8005D964: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x8005D968: lhu         $a0, -0x6A84($v0)
    ctx->r4 = MEM_HU(ctx->r2, -0X6A84);
    // 0x8005D96C: ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
    // 0x8005D970: sh          $v0, 0x18($sp)
    MEM_H(0X18, ctx->r29) = ctx->r2;
    // 0x8005D974: sh          $v0, 0x1A($sp)
    MEM_H(0X1A, ctx->r29) = ctx->r2;
    // 0x8005D978: addiu       $v0, $zero, 0x9
    ctx->r2 = ADD32(0, 0X9);
    // 0x8005D97C: sw          $ra, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r31;
    // 0x8005D980: sw          $s3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r19;
    // 0x8005D984: sw          $s0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r16;
    // 0x8005D988: sdc1        $f20, 0x50($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X50, ctx->r29);
    // 0x8005D98C: sh          $v0, 0x1C($sp)
    MEM_H(0X1C, ctx->r29) = ctx->r2;
    // 0x8005D990: jal         0x8003FC28
    // 0x8005D994: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    func_8003FC28(rdram, ctx);
        goto after_0;
    // 0x8005D994: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    after_0:
    // 0x8005D998: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    // 0x8005D99C: andi        $v1, $s0, 0xFFFF
    ctx->r3 = ctx->r16 & 0XFFFF;
    // 0x8005D9A0: ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
    // 0x8005D9A4: beq         $v1, $v0, L_8005DAB8
    if (ctx->r3 == ctx->r2) {
        // 0x8005D9A8: lui         $s3, 0x8000
        ctx->r19 = S32(0X8000 << 16);
            goto L_8005DAB8;
    }
    // 0x8005D9A8: lui         $s3, 0x8000
    ctx->r19 = S32(0X8000 << 16);
    // 0x8005D9AC: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8005D9B0: lwc1        $f20, -0x4F98($at)
    ctx->f20.u32l = MEM_W(ctx->r1, -0X4F98);
    // 0x8005D9B4: andi        $a0, $s0, 0xFFFF
    ctx->r4 = ctx->r16 & 0XFFFF;
L_8005D9B8:
    // 0x8005D9B8: andi        $v0, $s2, 0xFFFF
    ctx->r2 = ctx->r18 & 0XFFFF;
    // 0x8005D9BC: beq         $a0, $v0, L_8005DA9C
    if (ctx->r4 == ctx->r2) {
        // 0x8005D9C0: nop
    
            goto L_8005DA9C;
    }
    // 0x8005D9C0: nop

    // 0x8005D9C4: jal         0x8004013C
    // 0x8005D9C8: nop

    func_8004013C(rdram, ctx);
        goto after_1;
    // 0x8005D9C8: nop

    after_1:
    // 0x8005D9CC: lw          $a0, 0xC($v0)
    ctx->r4 = MEM_W(ctx->r2, 0XC);
    // 0x8005D9D0: beq         $a0, $zero, L_8005DA9C
    if (ctx->r4 == 0) {
        // 0x8005D9D4: nop
    
            goto L_8005DA9C;
    }
    // 0x8005D9D4: nop

    // 0x8005D9D8: jal         0x8006AC7C
    // 0x8005D9DC: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    func_8006AC7C(rdram, ctx);
        goto after_2;
    // 0x8005D9DC: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    after_2:
    // 0x8005D9E0: lwc1        $f0, 0x28($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X28);
    // 0x8005D9E4: lwc1        $f2, 0x90($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0X90);
    // 0x8005D9E8: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x8005D9EC: mul.s       $f4, $f0, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x8005D9F0: swc1        $f0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f0.u32l;
    // 0x8005D9F4: lwc1        $f0, 0x2C($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x8005D9F8: lwc1        $f2, 0x94($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0X94);
    // 0x8005D9FC: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x8005DA00: mul.s       $f6, $f0, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x8005DA04: swc1        $f0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f0.u32l;
    // 0x8005DA08: lwc1        $f0, 0x30($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X30);
    // 0x8005DA0C: lwc1        $f2, 0x98($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0X98);
    // 0x8005DA10: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x8005DA14: mul.s       $f2, $f0, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x8005DA18: swc1        $f0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f0.u32l;
    // 0x8005DA1C: lwc1        $f8, 0xD0($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0XD0);
    // 0x8005DA20: mul.s       $f0, $f8, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = MUL_S(ctx->f8.fl, ctx->f8.fl);
    // 0x8005DA24: add.s       $f4, $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8005DA28: add.s       $f4, $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f2.fl;
    // 0x8005DA2C: c.le.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl <= ctx->f0.fl;
    // 0x8005DA30: nop

    // 0x8005DA34: bc1f        L_8005DA9C
    if (!c1cs) {
        // 0x8005DA38: nop
    
            goto L_8005DA9C;
    }
    // 0x8005DA38: nop

    // 0x8005DA3C: sqrt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = sqrtf(ctx->f4.fl);
    // 0x8005DA40: sub.s       $f0, $f8, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f8.fl - ctx->f0.fl;
    // 0x8005DA44: div.s       $f0, $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f8.fl);
    // 0x8005DA48: sqrt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = sqrtf(ctx->f0.fl);
    // 0x8005DA4C: lhu         $v0, 0xD6($s1)
    ctx->r2 = MEM_HU(ctx->r17, 0XD6);
    // 0x8005DA50: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x8005DA54: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x8005DA58: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x8005DA5C: c.le.s      $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f20.fl <= ctx->f0.fl;
    // 0x8005DA60: nop

    // 0x8005DA64: bc1tl       L_8005DA7C
    if (c1cs) {
        // 0x8005DA68: sub.s       $f0, $f0, $f20
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f20.fl;
            goto L_8005DA7C;
    }
    goto skip_0;
    // 0x8005DA68: sub.s       $f0, $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f20.fl;
    skip_0:
    // 0x8005DA6C: trunc.w.s   $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    ctx->f10.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x8005DA70: mfc1        $v0, $f10
    ctx->r2 = (int32_t)ctx->f10.u32l;
    // 0x8005DA74: j           L_8005DA8C
    // 0x8005DA78: sh          $v0, 0x1E($sp)
    MEM_H(0X1E, ctx->r29) = ctx->r2;
        goto L_8005DA8C;
    // 0x8005DA78: sh          $v0, 0x1E($sp)
    MEM_H(0X1E, ctx->r29) = ctx->r2;
L_8005DA7C:
    // 0x8005DA7C: trunc.w.s   $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    ctx->f10.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x8005DA80: mfc1        $v0, $f10
    ctx->r2 = (int32_t)ctx->f10.u32l;
    // 0x8005DA84: or          $v0, $v0, $s3
    ctx->r2 = ctx->r2 | ctx->r19;
    // 0x8005DA88: sh          $v0, 0x1E($sp)
    MEM_H(0X1E, ctx->r29) = ctx->r2;
L_8005DA8C:
    // 0x8005DA8C: andi        $a0, $s0, 0xFFFF
    ctx->r4 = ctx->r16 & 0XFFFF;
    // 0x8005DA90: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    // 0x8005DA94: jal         0x8003E8DC
    // 0x8005DA98: addiu       $a2, $sp, 0x18
    ctx->r6 = ADD32(ctx->r29, 0X18);
    func_8003E8DC(rdram, ctx);
        goto after_3;
    // 0x8005DA98: addiu       $a2, $sp, 0x18
    ctx->r6 = ADD32(ctx->r29, 0X18);
    after_3:
L_8005DA9C:
    // 0x8005DA9C: jal         0x8003EEF4
    // 0x8005DAA0: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    func_8003EEF4(rdram, ctx);
        goto after_4;
    // 0x8005DAA0: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    after_4:
    // 0x8005DAA4: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    // 0x8005DAA8: andi        $v1, $s0, 0xFFFF
    ctx->r3 = ctx->r16 & 0XFFFF;
    // 0x8005DAAC: ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
    // 0x8005DAB0: bnel        $v1, $v0, L_8005D9B8
    if (ctx->r3 != ctx->r2) {
        // 0x8005DAB4: andi        $a0, $s0, 0xFFFF
        ctx->r4 = ctx->r16 & 0XFFFF;
            goto L_8005D9B8;
    }
    goto skip_1;
    // 0x8005DAB4: andi        $a0, $s0, 0xFFFF
    ctx->r4 = ctx->r16 & 0XFFFF;
    skip_1:
L_8005DAB8:
    // 0x8005DAB8: lw          $ra, 0x48($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X48);
    // 0x8005DABC: lw          $s3, 0x44($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X44);
    // 0x8005DAC0: lw          $s2, 0x40($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X40);
    // 0x8005DAC4: lw          $s1, 0x3C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X3C);
    // 0x8005DAC8: lw          $s0, 0x38($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X38);
    // 0x8005DACC: ldc1        $f20, 0x50($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X50);
    // 0x8005DAD0: jr          $ra
    // 0x8005DAD4: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    return;
    // 0x8005DAD4: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
;}
RECOMP_FUNC void func_8005DAD8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005DAD8: addiu       $sp, $sp, -0xD0
    ctx->r29 = ADD32(ctx->r29, -0XD0);
    // 0x8005DADC: sw          $s6, 0xC0($sp)
    MEM_W(0XC0, ctx->r29) = ctx->r22;
    // 0x8005DAE0: addu        $s6, $a0, $zero
    ctx->r22 = ADD32(ctx->r4, 0);
    // 0x8005DAE4: sw          $s2, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->r18;
    // 0x8005DAE8: andi        $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 & 0XFFFF;
    // 0x8005DAEC: addiu       $v1, $a1, -0x1
    ctx->r3 = ADD32(ctx->r5, -0X1);
    // 0x8005DAF0: sltiu       $v0, $v1, 0xB
    ctx->r2 = ctx->r3 < 0XB ? 1 : 0;
    // 0x8005DAF4: sw          $ra, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->r31;
    // 0x8005DAF8: sw          $s5, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->r21;
    // 0x8005DAFC: sw          $s4, 0xB8($sp)
    MEM_W(0XB8, ctx->r29) = ctx->r20;
    // 0x8005DB00: sw          $s3, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->r19;
    // 0x8005DB04: sw          $s1, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->r17;
    // 0x8005DB08: sw          $s0, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->r16;
    // 0x8005DB0C: sdc1        $f20, 0xC8($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0XC8, ctx->r29);
    // 0x8005DB10: lw          $s0, 0x4($s6)
    ctx->r16 = MEM_W(ctx->r22, 0X4);
    // 0x8005DB14: beq         $v0, $zero, L_8005E380
    if (ctx->r2 == 0) {
        // 0x8005DB18: addu        $s2, $a2, $zero
        ctx->r18 = ADD32(ctx->r6, 0);
            goto L_8005E380;
    }
    // 0x8005DB18: addu        $s2, $a2, $zero
    ctx->r18 = ADD32(ctx->r6, 0);
    // 0x8005DB1C: lui         $v0, 0x8004
    ctx->r2 = S32(0X8004 << 16);
    // 0x8005DB20: addiu       $v0, $v0, -0x4F90
    ctx->r2 = ADD32(ctx->r2, -0X4F90);
    // 0x8005DB24: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x8005DB28: addu        $v1, $v1, $v0
    gpr jr_addend_8005DB30 = ctx->r3;
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x8005DB2C: lw          $v0, 0x0($v1)
    ctx->r2 = ADD32(ctx->r3, 0X0);
    // 0x8005DB30: jr          $v0
    // 0x8005DB34: nop

    switch (jr_addend_8005DB30 >> 2) {
        case 0: goto L_8005DB38; break;
        case 1: goto L_8005DD50; break;
        case 2: goto L_8005DDE8; break;
        case 3: goto L_8005E190; break;
        case 4: goto L_8005E380; break;
        case 5: goto L_8005E380; break;
        case 6: goto L_8005E380; break;
        case 7: goto L_8005E380; break;
        case 8: goto L_8005E380; break;
        case 9: goto L_8005E2E0; break;
        case 10: goto L_8005E378; break;
        default: switch_error(__func__, 0x8005DB30, 0x8003B070);
    }
    // 0x8005DB34: nop

L_8005DB38:
    // 0x8005DB38: addiu       $a0, $zero, 0xDC
    ctx->r4 = ADD32(0, 0XDC);
    // 0x8005DB3C: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x8005DB40: jal         0x80001ACC
    // 0x8005DB44: addu        $s1, $s2, $zero
    ctx->r17 = ADD32(ctx->r18, 0);
    rs_malloc(rdram, ctx);
        goto after_0;
    // 0x8005DB44: addu        $s1, $s2, $zero
    ctx->r17 = ADD32(ctx->r18, 0);
    after_0:
    // 0x8005DB48: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    // 0x8005DB4C: addiu       $v0, $zero, 0x300
    ctx->r2 = ADD32(0, 0X300);
    // 0x8005DB50: sw          $s0, 0x4($s6)
    MEM_W(0X4, ctx->r22) = ctx->r16;
    // 0x8005DB54: sh          $v0, 0x10($s0)
    MEM_H(0X10, ctx->r16) = ctx->r2;
    // 0x8005DB58: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // 0x8005DB5C: sb          $v0, 0x2C($s0)
    MEM_B(0X2C, ctx->r16) = ctx->r2;
    // 0x8005DB60: sb          $v0, 0x2D($s0)
    MEM_B(0X2D, ctx->r16) = ctx->r2;
    // 0x8005DB64: sb          $v0, 0x2E($s0)
    MEM_B(0X2E, ctx->r16) = ctx->r2;
    // 0x8005DB68: sb          $v0, 0x2F($s0)
    MEM_B(0X2F, ctx->r16) = ctx->r2;
    // 0x8005DB6C: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x8005DB70: sh          $zero, 0xC($s0)
    MEM_H(0XC, ctx->r16) = 0;
    // 0x8005DB74: sh          $zero, 0xA($s0)
    MEM_H(0XA, ctx->r16) = 0;
    // 0x8005DB78: sh          $zero, 0x8($s0)
    MEM_H(0X8, ctx->r16) = 0;
    // 0x8005DB7C: sh          $zero, 0x2A($s0)
    MEM_H(0X2A, ctx->r16) = 0;
    // 0x8005DB80: sh          $zero, 0x28($s0)
    MEM_H(0X28, ctx->r16) = 0;
    // 0x8005DB84: lhu         $v0, -0x68C8($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X68C8);
    // 0x8005DB88: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8005DB8C: lwc1        $f4, -0x4F64($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X4F64);
    // 0x8005DB90: sh          $v0, 0x12($s0)
    MEM_H(0X12, ctx->r16) = ctx->r2;
    // 0x8005DB94: lwc1        $f0, 0x0($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X0);
    // 0x8005DB98: swc1        $f0, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f0.u32l;
    // 0x8005DB9C: swc1        $f0, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->f0.u32l;
    // 0x8005DBA0: lw          $v0, 0xC($s1)
    ctx->r2 = MEM_W(ctx->r17, 0XC);
    // 0x8005DBA4: lw          $t0, 0x24($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X24);
    // 0x8005DBA8: lw          $t1, 0x28($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X28);
    // 0x8005DBAC: lw          $t2, 0x2C($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X2C);
    // 0x8005DBB0: sw          $t0, 0xB4($s0)
    MEM_W(0XB4, ctx->r16) = ctx->r8;
    // 0x8005DBB4: sw          $t1, 0xB8($s0)
    MEM_W(0XB8, ctx->r16) = ctx->r9;
    // 0x8005DBB8: sw          $t2, 0xBC($s0)
    MEM_W(0XBC, ctx->r16) = ctx->r10;
    // 0x8005DBBC: lwc1        $f0, 0x0($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X0);
    // 0x8005DBC0: swc1        $f0, 0xC0($s0)
    MEM_W(0XC0, ctx->r16) = ctx->f0.u32l;
    // 0x8005DBC4: lw          $v0, 0xC($s1)
    ctx->r2 = MEM_W(ctx->r17, 0XC);
    // 0x8005DBC8: lwc1        $f2, 0xB4($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0XB4);
    // 0x8005DBCC: lwc1        $f0, 0x0($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8005DBD0: div.s       $f2, $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = DIV_S(ctx->f2.fl, ctx->f4.fl);
    // 0x8005DBD4: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x8005DBD8: swc1        $f0, 0x90($s0)
    MEM_W(0X90, ctx->r16) = ctx->f0.u32l;
    // 0x8005DBDC: lw          $v0, 0xC($s1)
    ctx->r2 = MEM_W(ctx->r17, 0XC);
    // 0x8005DBE0: lwc1        $f0, 0xB8($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0XB8);
    // 0x8005DBE4: lwc1        $f2, 0x4($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X4);
    // 0x8005DBE8: div.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f4.fl);
    // 0x8005DBEC: add.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x8005DBF0: addiu       $v1, $s0, 0x30
    ctx->r3 = ADD32(ctx->r16, 0X30);
    // 0x8005DBF4: swc1        $f2, 0x94($s0)
    MEM_W(0X94, ctx->r16) = ctx->f2.u32l;
    // 0x8005DBF8: lw          $v0, 0xC($s1)
    ctx->r2 = MEM_W(ctx->r17, 0XC);
    // 0x8005DBFC: lwc1        $f0, 0xBC($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0XBC);
    // 0x8005DC00: lwc1        $f2, 0x8($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X8);
    // 0x8005DC04: div.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f4.fl);
    // 0x8005DC08: add.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x8005DC0C: addu        $a0, $v1, $zero
    ctx->r4 = ADD32(ctx->r3, 0);
    // 0x8005DC10: addu        $v0, $s0, $zero
    ctx->r2 = ADD32(ctx->r16, 0);
    // 0x8005DC14: swc1        $f2, 0x98($s0)
    MEM_W(0X98, ctx->r16) = ctx->f2.u32l;
L_8005DC18:
    // 0x8005DC18: lw          $t0, 0x0($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X0);
    // 0x8005DC1C: lw          $t1, 0x4($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X4);
    // 0x8005DC20: lw          $t2, 0x8($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X8);
    // 0x8005DC24: lw          $t3, 0xC($v0)
    ctx->r11 = MEM_W(ctx->r2, 0XC);
    // 0x8005DC28: sw          $t0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r8;
    // 0x8005DC2C: sw          $t1, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r9;
    // 0x8005DC30: sw          $t2, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r10;
    // 0x8005DC34: sw          $t3, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r11;
    // 0x8005DC38: addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
    // 0x8005DC3C: bne         $v0, $a0, L_8005DC18
    if (ctx->r2 != ctx->r4) {
        // 0x8005DC40: addiu       $v1, $v1, 0x10
        ctx->r3 = ADD32(ctx->r3, 0X10);
            goto L_8005DC18;
    }
    // 0x8005DC40: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
    // 0x8005DC44: addiu       $v1, $s0, 0x60
    ctx->r3 = ADD32(ctx->r16, 0X60);
    // 0x8005DC48: addu        $v0, $s0, $zero
    ctx->r2 = ADD32(ctx->r16, 0);
    // 0x8005DC4C: addiu       $a0, $s0, 0x30
    ctx->r4 = ADD32(ctx->r16, 0X30);
L_8005DC50:
    // 0x8005DC50: lw          $t0, 0x0($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X0);
    // 0x8005DC54: lw          $t1, 0x4($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X4);
    // 0x8005DC58: lw          $t2, 0x8($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X8);
    // 0x8005DC5C: lw          $t3, 0xC($v0)
    ctx->r11 = MEM_W(ctx->r2, 0XC);
    // 0x8005DC60: sw          $t0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r8;
    // 0x8005DC64: sw          $t1, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r9;
    // 0x8005DC68: sw          $t2, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r10;
    // 0x8005DC6C: sw          $t3, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r11;
    // 0x8005DC70: addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
    // 0x8005DC74: bne         $v0, $a0, L_8005DC50
    if (ctx->r2 != ctx->r4) {
        // 0x8005DC78: addiu       $v1, $v1, 0x10
        ctx->r3 = ADD32(ctx->r3, 0X10);
            goto L_8005DC50;
    }
    // 0x8005DC78: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
    // 0x8005DC7C: lw          $t0, 0x90($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X90);
    // 0x8005DC80: lw          $t1, 0x94($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X94);
    // 0x8005DC84: lw          $t2, 0x98($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X98);
    // 0x8005DC88: sw          $t0, 0x9C($s0)
    MEM_W(0X9C, ctx->r16) = ctx->r8;
    // 0x8005DC8C: sw          $t1, 0xA0($s0)
    MEM_W(0XA0, ctx->r16) = ctx->r9;
    // 0x8005DC90: sw          $t2, 0xA4($s0)
    MEM_W(0XA4, ctx->r16) = ctx->r10;
    // 0x8005DC94: lw          $t0, 0x90($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X90);
    // 0x8005DC98: lw          $t1, 0x94($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X94);
    // 0x8005DC9C: lw          $t2, 0x98($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X98);
    // 0x8005DCA0: sw          $t0, 0xA8($s0)
    MEM_W(0XA8, ctx->r16) = ctx->r8;
    // 0x8005DCA4: sw          $t1, 0xAC($s0)
    MEM_W(0XAC, ctx->r16) = ctx->r9;
    // 0x8005DCA8: sw          $t2, 0xB0($s0)
    MEM_W(0XB0, ctx->r16) = ctx->r10;
    // 0x8005DCAC: lwc1        $f8, 0x20($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X20);
    // 0x8005DCB0: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8005DCB4: lwc1        $f0, -0x4F60($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X4F60);
    // 0x8005DCB8: mul.s       $f8, $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x8005DCBC: lwc1        $f6, 0x24($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X24);
    // 0x8005DCC0: lwc1        $f4, 0x20($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X20);
    // 0x8005DCC4: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8005DCC8: lwc1        $f10, -0x4F5C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X4F5C);
    // 0x8005DCCC: mul.s       $f6, $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x8005DCD0: lwc1        $f2, 0xC0($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0XC0);
    // 0x8005DCD4: addiu       $v0, $zero, 0xC0
    ctx->r2 = ADD32(0, 0XC0);
    // 0x8005DCD8: sb          $v0, 0x5F($s0)
    MEM_B(0X5F, ctx->r16) = ctx->r2;
    // 0x8005DCDC: lwc1        $f0, 0xC0($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0XC0);
    // 0x8005DCE0: mul.s       $f4, $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f4.fl, ctx->f10.fl);
    // 0x8005DCE4: swc1        $f0, 0xC4($s0)
    MEM_W(0XC4, ctx->r16) = ctx->f0.u32l;
    // 0x8005DCE8: lwc1        $f0, 0x24($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X24);
    // 0x8005DCEC: addiu       $v0, $zero, 0x60
    ctx->r2 = ADD32(0, 0X60);
    // 0x8005DCF0: sb          $v0, 0x8F($s0)
    MEM_B(0X8F, ctx->r16) = ctx->r2;
    // 0x8005DCF4: mul.s       $f0, $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x8005DCF8: swc1        $f2, 0xC8($s0)
    MEM_W(0XC8, ctx->r16) = ctx->f2.u32l;
    // 0x8005DCFC: swc1        $f8, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->f8.u32l;
    // 0x8005DD00: swc1        $f6, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f6.u32l;
    // 0x8005DD04: swc1        $f4, 0x80($s0)
    MEM_W(0X80, ctx->r16) = ctx->f4.u32l;
    // 0x8005DD08: swc1        $f0, 0x84($s0)
    MEM_W(0X84, ctx->r16) = ctx->f0.u32l;
    // 0x8005DD0C: lhu         $v0, 0x1C($s1)
    ctx->r2 = MEM_HU(ctx->r17, 0X1C);
    // 0x8005DD10: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8005DD14: lwc1        $f0, -0x4F58($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X4F58);
    // 0x8005DD18: sh          $v0, 0xD6($s0)
    MEM_H(0XD6, ctx->r16) = ctx->r2;
    // 0x8005DD1C: lhu         $v0, 0x18($s1)
    ctx->r2 = MEM_HU(ctx->r17, 0X18);
    // 0x8005DD20: sw          $zero, 0xCC($s0)
    MEM_W(0XCC, ctx->r16) = 0;
    // 0x8005DD24: sh          $v0, 0xD4($s0)
    MEM_H(0XD4, ctx->r16) = ctx->r2;
    // 0x8005DD28: lbu         $v0, 0x17($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X17);
    // 0x8005DD2C: swc1        $f0, 0xD0($s0)
    MEM_W(0XD0, ctx->r16) = ctx->f0.u32l;
    // 0x8005DD30: sb          $zero, 0xD9($s0)
    MEM_B(0XD9, ctx->r16) = 0;
    // 0x8005DD34: sb          $v0, 0xD8($s0)
    MEM_B(0XD8, ctx->r16) = ctx->r2;
    // 0x8005DD38: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x8005DD3C: lhu         $a0, -0x6A98($v0)
    ctx->r4 = MEM_HU(ctx->r2, -0X6A98);
    // 0x8005DD40: jal         0x8003E684
    // 0x8005DD44: addu        $a1, $s6, $zero
    ctx->r5 = ADD32(ctx->r22, 0);
    func_8003E684(rdram, ctx);
        goto after_1;
    // 0x8005DD44: addu        $a1, $s6, $zero
    ctx->r5 = ADD32(ctx->r22, 0);
    after_1:
    // 0x8005DD48: j           L_8005E384
    // 0x8005DD4C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8005E384;
    // 0x8005DD4C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8005DD50:
    // 0x8005DD50: lbu         $v0, 0xD9($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0XD9);
    // 0x8005DD54: beq         $v0, $zero, L_8005E380
    if (ctx->r2 == 0) {
        // 0x8005DD58: addiu       $s2, $sp, 0x50
        ctx->r18 = ADD32(ctx->r29, 0X50);
            goto L_8005E380;
    }
    // 0x8005DD58: addiu       $s2, $sp, 0x50
    ctx->r18 = ADD32(ctx->r29, 0X50);
    // 0x8005DD5C: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // 0x8005DD60: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x8005DD64: jal         0x800078E0
    // 0x8005DD68: addiu       $a2, $zero, 0xC
    ctx->r6 = ADD32(0, 0XC);
    rs_memset(rdram, ctx);
        goto after_2;
    // 0x8005DD68: addiu       $a2, $zero, 0xC
    ctx->r6 = ADD32(0, 0XC);
    after_2:
    // 0x8005DD6C: addiu       $s1, $s0, 0x90
    ctx->r17 = ADD32(ctx->r16, 0X90);
    // 0x8005DD70: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    // 0x8005DD74: jal         0x8007559C
    // 0x8005DD78: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    func_8007559C(rdram, ctx);
        goto after_3;
    // 0x8005DD78: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    after_3:
    // 0x8005DD7C: lbu         $v1, 0xD8($s0)
    ctx->r3 = MEM_BU(ctx->r16, 0XD8);
    // 0x8005DD80: addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
    // 0x8005DD84: bne         $v1, $v0, L_8005DDA8
    if (ctx->r3 != ctx->r2) {
        // 0x8005DD88: addu        $a0, $zero, $zero
        ctx->r4 = ADD32(0, 0);
            goto L_8005DDA8;
    }
    // 0x8005DD88: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x8005DD8C: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    // 0x8005DD90: addu        $a2, $s2, $zero
    ctx->r6 = ADD32(ctx->r18, 0);
    // 0x8005DD94: lui         $a3, 0x41C0
    ctx->r7 = S32(0X41C0 << 16);
    // 0x8005DD98: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8005DD9C: lwc1        $f0, -0x4F54($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X4F54);
    // 0x8005DDA0: j           L_8005DDC0
    // 0x8005DDA4: addiu       $v0, $zero, 0x21
    ctx->r2 = ADD32(0, 0X21);
        goto L_8005DDC0;
    // 0x8005DDA4: addiu       $v0, $zero, 0x21
    ctx->r2 = ADD32(0, 0X21);
L_8005DDA8:
    // 0x8005DDA8: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    // 0x8005DDAC: addu        $a2, $s2, $zero
    ctx->r6 = ADD32(ctx->r18, 0);
    // 0x8005DDB0: lui         $a3, 0x41C0
    ctx->r7 = S32(0X41C0 << 16);
    // 0x8005DDB4: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8005DDB8: lwc1        $f0, -0x4F50($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X4F50);
    // 0x8005DDBC: addiu       $v0, $zero, 0x6E
    ctx->r2 = ADD32(0, 0X6E);
L_8005DDC0:
    // 0x8005DDC0: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // 0x8005DDC4: addiu       $v0, $zero, 0x78
    ctx->r2 = ADD32(0, 0X78);
    // 0x8005DDC8: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x8005DDCC: addiu       $v0, $zero, 0x50
    ctx->r2 = ADD32(0, 0X50);
    // 0x8005DDD0: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x8005DDD4: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x8005DDD8: jal         0x800989D8
    // 0x8005DDDC: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    func_800989D8(rdram, ctx);
        goto after_4;
    // 0x8005DDDC: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    after_4:
    // 0x8005DDE0: j           L_8005E384
    // 0x8005DDE4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8005E384;
    // 0x8005DDE4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8005DDE8:
    // 0x8005DDE8: lwc1        $f10, 0x0($s2)
    ctx->f10.u32l = MEM_W(ctx->r18, 0X0);
    // 0x8005DDEC: lwc1        $f2, 0xB4($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0XB4);
    // 0x8005DDF0: mul.s       $f2, $f2, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f10.fl);
    // 0x8005DDF4: lwc1        $f4, 0xB8($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XB8);
    // 0x8005DDF8: mul.s       $f4, $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f4.fl, ctx->f10.fl);
    // 0x8005DDFC: lwc1        $f6, 0xBC($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XBC);
    // 0x8005DE00: mul.s       $f6, $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x8005DE04: lwc1        $f0, 0x90($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X90);
    // 0x8005DE08: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x8005DE0C: lwc1        $f8, 0x94($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X94);
    // 0x8005DE10: add.s       $f8, $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f8.fl + ctx->f4.fl;
    // 0x8005DE14: lwc1        $f2, 0x98($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X98);
    // 0x8005DE18: add.s       $f2, $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f6.fl;
    // 0x8005DE1C: lwc1        $f4, 0x9C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X9C);
    // 0x8005DE20: sub.s       $f4, $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f4.fl - ctx->f0.fl;
    // 0x8005DE24: swc1        $f0, 0x90($s0)
    MEM_W(0X90, ctx->r16) = ctx->f0.u32l;
    // 0x8005DE28: swc1        $f8, 0x94($s0)
    MEM_W(0X94, ctx->r16) = ctx->f8.u32l;
    // 0x8005DE2C: swc1        $f2, 0x98($s0)
    MEM_W(0X98, ctx->r16) = ctx->f2.u32l;
    // 0x8005DE30: swc1        $f4, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f4.u32l;
    // 0x8005DE34: lwc1        $f0, 0xA0($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0XA0);
    // 0x8005DE38: lwc1        $f2, 0x94($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X94);
    // 0x8005DE3C: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x8005DE40: swc1        $f0, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f0.u32l;
    // 0x8005DE44: lwc1        $f2, 0xA4($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0XA4);
    // 0x8005DE48: lwc1        $f0, 0x98($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X98);
    // 0x8005DE4C: sub.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl - ctx->f0.fl;
    // 0x8005DE50: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8005DE54: lwc1        $f6, -0x4F4C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X4F4C);
    // 0x8005DE58: mul.s       $f4, $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8005DE5C: swc1        $f2, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f2.u32l;
    // 0x8005DE60: lwc1        $f0, 0x90($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X90);
    // 0x8005DE64: add.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f4.fl;
    // 0x8005DE68: swc1        $f0, 0x9C($s0)
    MEM_W(0X9C, ctx->r16) = ctx->f0.u32l;
    // 0x8005DE6C: lwc1        $f2, 0x54($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X54);
    // 0x8005DE70: mul.s       $f2, $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f6.fl);
    // 0x8005DE74: lwc1        $f0, 0x94($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X94);
    // 0x8005DE78: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x8005DE7C: swc1        $f0, 0xA0($s0)
    MEM_W(0XA0, ctx->r16) = ctx->f0.u32l;
    // 0x8005DE80: lwc1        $f0, 0x58($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X58);
    // 0x8005DE84: mul.s       $f0, $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x8005DE88: lwc1        $f2, 0x98($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X98);
    // 0x8005DE8C: lwc1        $f4, 0xA8($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XA8);
    // 0x8005DE90: add.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x8005DE94: lwc1        $f0, 0x9C($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X9C);
    // 0x8005DE98: sub.s       $f4, $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f4.fl - ctx->f0.fl;
    // 0x8005DE9C: swc1        $f2, 0xA4($s0)
    MEM_W(0XA4, ctx->r16) = ctx->f2.u32l;
    // 0x8005DEA0: swc1        $f4, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f4.u32l;
    // 0x8005DEA4: lwc1        $f0, 0xAC($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0XAC);
    // 0x8005DEA8: lwc1        $f2, 0xA0($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0XA0);
    // 0x8005DEAC: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x8005DEB0: swc1        $f0, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f0.u32l;
    // 0x8005DEB4: lwc1        $f0, 0xB0($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0XB0);
    // 0x8005DEB8: lwc1        $f2, 0xA4($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0XA4);
    // 0x8005DEBC: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x8005DEC0: mul.s       $f4, $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8005DEC4: swc1        $f0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f0.u32l;
    // 0x8005DEC8: lwc1        $f0, 0x9C($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X9C);
    // 0x8005DECC: add.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f4.fl;
    // 0x8005DED0: swc1        $f0, 0xA8($s0)
    MEM_W(0XA8, ctx->r16) = ctx->f0.u32l;
    // 0x8005DED4: lwc1        $f2, 0x54($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X54);
    // 0x8005DED8: mul.s       $f2, $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f6.fl);
    // 0x8005DEDC: lwc1        $f0, 0xA0($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0XA0);
    // 0x8005DEE0: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x8005DEE4: swc1        $f0, 0xAC($s0)
    MEM_W(0XAC, ctx->r16) = ctx->f0.u32l;
    // 0x8005DEE8: lwc1        $f2, 0x58($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X58);
    // 0x8005DEEC: mul.s       $f2, $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f6.fl);
    // 0x8005DEF0: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8005DEF4: lwc1        $f0, -0x4F48($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X4F48);
    // 0x8005DEF8: mul.s       $f10, $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x8005DEFC: lwc1        $f4, 0xA4($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XA4);
    // 0x8005DF00: add.s       $f4, $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f2.fl;
    // 0x8005DF04: lwc1        $f0, 0xB8($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0XB8);
    // 0x8005DF08: add.s       $f0, $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f10.fl;
    // 0x8005DF0C: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8005DF10: lwc1        $f2, -0x4F44($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X4F44);
    // 0x8005DF14: swc1        $f0, 0xB8($s0)
    MEM_W(0XB8, ctx->r16) = ctx->f0.u32l;
    // 0x8005DF18: swc1        $f4, 0xB0($s0)
    MEM_W(0XB0, ctx->r16) = ctx->f4.u32l;
    // 0x8005DF1C: lw          $t0, 0x90($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X90);
    // 0x8005DF20: lw          $t1, 0x94($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X94);
    // 0x8005DF24: lw          $t2, 0x98($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X98);
    // 0x8005DF28: sw          $t0, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r8;
    // 0x8005DF2C: sw          $t1, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r9;
    // 0x8005DF30: sw          $t2, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r10;
    // 0x8005DF34: lw          $t0, 0xB4($s0)
    ctx->r8 = MEM_W(ctx->r16, 0XB4);
    // 0x8005DF38: lw          $t1, 0xB8($s0)
    ctx->r9 = MEM_W(ctx->r16, 0XB8);
    // 0x8005DF3C: lw          $t2, 0xBC($s0)
    ctx->r10 = MEM_W(ctx->r16, 0XBC);
    // 0x8005DF40: sw          $t0, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r8;
    // 0x8005DF44: sw          $t1, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r9;
    // 0x8005DF48: sw          $t2, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->r10;
    // 0x8005DF4C: sw          $zero, 0x78($sp)
    MEM_W(0X78, ctx->r29) = 0;
    // 0x8005DF50: sw          $zero, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = 0;
    // 0x8005DF54: sw          $zero, 0x80($sp)
    MEM_W(0X80, ctx->r29) = 0;
    // 0x8005DF58: sw          $zero, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = 0;
    // 0x8005DF5C: sw          $zero, 0x70($sp)
    MEM_W(0X70, ctx->r29) = 0;
    // 0x8005DF60: swc1        $f2, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->f2.u32l;
    // 0x8005DF64: lwc1        $f0, 0xCC($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0XCC);
    // 0x8005DF68: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x8005DF6C: nop

    // 0x8005DF70: bc1f        L_8005DF7C
    if (!c1cs) {
        // 0x8005DF74: addiu       $s4, $zero, -0x1
        ctx->r20 = ADD32(0, -0X1);
            goto L_8005DF7C;
    }
    // 0x8005DF74: addiu       $s4, $zero, -0x1
    ctx->r20 = ADD32(0, -0X1);
    // 0x8005DF78: lhu         $s4, 0xD4($s0)
    ctx->r20 = MEM_HU(ctx->r16, 0XD4);
L_8005DF7C:
    // 0x8005DF7C: lwc1        $f2, 0x0($s2)
    ctx->f2.u32l = MEM_W(ctx->r18, 0X0);
    // 0x8005DF80: lwc1        $f6, 0x84($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X84);
    // 0x8005DF84: mul.s       $f6, $f6, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f6.fl, ctx->f2.fl);
    // 0x8005DF88: lwc1        $f4, 0x88($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X88);
    // 0x8005DF8C: ori         $s5, $zero, 0xFFFF
    ctx->r21 = 0 | 0XFFFF;
    // 0x8005DF90: mul.s       $f4, $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f4.fl, ctx->f2.fl);
    // 0x8005DF94: addiu       $a1, $sp, 0x90
    ctx->r5 = ADD32(ctx->r29, 0X90);
    // 0x8005DF98: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x8005DF9C: lwc1        $f0, 0x8C($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X8C);
    // 0x8005DFA0: lhu         $a0, -0x6A84($v0)
    ctx->r4 = MEM_HU(ctx->r2, -0X6A84);
    // 0x8005DFA4: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x8005DFA8: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8005DFAC: lwc1        $f20, -0x4F40($at)
    ctx->f20.u32l = MEM_W(ctx->r1, -0X4F40);
    // 0x8005DFB0: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    // 0x8005DFB4: swc1        $f6, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->f6.u32l;
    // 0x8005DFB8: swc1        $f4, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->f4.u32l;
    // 0x8005DFBC: jal         0x8003FC28
    // 0x8005DFC0: swc1        $f0, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->f0.u32l;
    func_8003FC28(rdram, ctx);
        goto after_5;
    // 0x8005DFC0: swc1        $f0, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->f0.u32l;
    after_5:
    // 0x8005DFC4: addu        $s1, $v0, $zero
    ctx->r17 = ADD32(ctx->r2, 0);
    // 0x8005DFC8: andi        $v1, $s1, 0xFFFF
    ctx->r3 = ctx->r17 & 0XFFFF;
    // 0x8005DFCC: ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
    // 0x8005DFD0: beq         $v1, $v0, L_8005E04C
    if (ctx->r3 == ctx->r2) {
        // 0x8005DFD4: addiu       $s3, $sp, 0x28
        ctx->r19 = ADD32(ctx->r29, 0X28);
            goto L_8005E04C;
    }
    // 0x8005DFD4: addiu       $s3, $sp, 0x28
    ctx->r19 = ADD32(ctx->r29, 0X28);
    // 0x8005DFD8: andi        $s2, $s4, 0xFFFF
    ctx->r18 = ctx->r20 & 0XFFFF;
    // 0x8005DFDC: addu        $s4, $v0, $zero
    ctx->r20 = ADD32(ctx->r2, 0);
L_8005DFE0:
    // 0x8005DFE0: beq         $s2, $s4, L_8005DFF0
    if (ctx->r18 == ctx->r20) {
        // 0x8005DFE4: andi        $v0, $s1, 0xFFFF
        ctx->r2 = ctx->r17 & 0XFFFF;
            goto L_8005DFF0;
    }
    // 0x8005DFE4: andi        $v0, $s1, 0xFFFF
    ctx->r2 = ctx->r17 & 0XFFFF;
    // 0x8005DFE8: beq         $s2, $v0, L_8005E034
    if (ctx->r18 == ctx->r2) {
        // 0x8005DFEC: nop
    
            goto L_8005E034;
    }
    // 0x8005DFEC: nop

L_8005DFF0:
    // 0x8005DFF0: jal         0x8004013C
    // 0x8005DFF4: andi        $a0, $s1, 0xFFFF
    ctx->r4 = ctx->r17 & 0XFFFF;
    func_8004013C(rdram, ctx);
        goto after_6;
    // 0x8005DFF4: andi        $a0, $s1, 0xFFFF
    ctx->r4 = ctx->r17 & 0XFFFF;
    after_6:
    // 0x8005DFF8: lw          $a0, 0xC($v0)
    ctx->r4 = MEM_W(ctx->r2, 0XC);
    // 0x8005DFFC: beq         $a0, $zero, L_8005E034
    if (ctx->r4 == 0) {
        // 0x8005E000: addiu       $a1, $sp, 0x60
        ctx->r5 = ADD32(ctx->r29, 0X60);
            goto L_8005E034;
    }
    // 0x8005E000: addiu       $a1, $sp, 0x60
    ctx->r5 = ADD32(ctx->r29, 0X60);
    // 0x8005E004: addiu       $a2, $sp, 0x98
    ctx->r6 = ADD32(ctx->r29, 0X98);
    // 0x8005E008: jal         0x8006A944
    // 0x8005E00C: addu        $a3, $s3, $zero
    ctx->r7 = ADD32(ctx->r19, 0);
    func_8006A944(rdram, ctx);
        goto after_7;
    // 0x8005E00C: addu        $a3, $s3, $zero
    ctx->r7 = ADD32(ctx->r19, 0);
    after_7:
    // 0x8005E010: beq         $v0, $zero, L_8005E034
    if (ctx->r2 == 0) {
        // 0x8005E014: nop
    
            goto L_8005E034;
    }
    // 0x8005E014: nop

    // 0x8005E018: lwc1        $f0, 0x18($s3)
    ctx->f0.u32l = MEM_W(ctx->r19, 0X18);
    // 0x8005E01C: c.lt.s      $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f0.fl < ctx->f20.fl;
    // 0x8005E020: nop

    // 0x8005E024: bc1f        L_8005E034
    if (!c1cs) {
        // 0x8005E028: nop
    
            goto L_8005E034;
    }
    // 0x8005E028: nop

    // 0x8005E02C: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x8005E030: addu        $s5, $s1, $zero
    ctx->r21 = ADD32(ctx->r17, 0);
L_8005E034:
    // 0x8005E034: jal         0x8003EEF4
    // 0x8005E038: addiu       $a0, $sp, 0x90
    ctx->r4 = ADD32(ctx->r29, 0X90);
    func_8003EEF4(rdram, ctx);
        goto after_8;
    // 0x8005E038: addiu       $a0, $sp, 0x90
    ctx->r4 = ADD32(ctx->r29, 0X90);
    after_8:
    // 0x8005E03C: addu        $s1, $v0, $zero
    ctx->r17 = ADD32(ctx->r2, 0);
    // 0x8005E040: andi        $v0, $s1, 0xFFFF
    ctx->r2 = ctx->r17 & 0XFFFF;
    // 0x8005E044: bne         $v0, $s4, L_8005DFE0
    if (ctx->r2 != ctx->r20) {
        // 0x8005E048: nop
    
            goto L_8005DFE0;
    }
    // 0x8005E048: nop

L_8005E04C:
    // 0x8005E04C: addu        $s1, $s5, $zero
    ctx->r17 = ADD32(ctx->r21, 0);
    // 0x8005E050: andi        $v1, $s1, 0xFFFF
    ctx->r3 = ctx->r17 & 0XFFFF;
    // 0x8005E054: ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
    // 0x8005E058: beq         $v1, $v0, L_8005E0D8
    if (ctx->r3 == ctx->r2) {
        // 0x8005E05C: lui         $v0, 0x8013
        ctx->r2 = S32(0X8013 << 16);
            goto L_8005E0D8;
    }
    // 0x8005E05C: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8005E060: lbu         $v0, 0xB39($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0XB39);
    // 0x8005E064: bne         $v0, $zero, L_8005E094
    if (ctx->r2 != 0) {
        // 0x8005E068: nop
    
            goto L_8005E094;
    }
    // 0x8005E068: nop

    // 0x8005E06C: jal         0x8006C994
    // 0x8005E070: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    func_8006C994(rdram, ctx);
        goto after_9;
    // 0x8005E070: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    after_9:
    // 0x8005E074: lhu         $v1, 0xD4($s0)
    ctx->r3 = MEM_HU(ctx->r16, 0XD4);
    // 0x8005E078: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x8005E07C: bne         $v1, $v0, L_8005E094
    if (ctx->r3 != ctx->r2) {
        // 0x8005E080: lui         $v1, 0x8013
        ctx->r3 = S32(0X8013 << 16);
            goto L_8005E094;
    }
    // 0x8005E080: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x8005E084: addiu       $v1, $v1, 0xB78
    ctx->r3 = ADD32(ctx->r3, 0XB78);
    // 0x8005E088: lw          $v0, 0x8($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X8);
    // 0x8005E08C: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8005E090: sw          $v0, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r2;
L_8005E094:
    // 0x8005E094: lhu         $v0, 0x16($s6)
    ctx->r2 = MEM_HU(ctx->r22, 0X16);
    // 0x8005E098: andi        $a0, $s1, 0xFFFF
    ctx->r4 = ctx->r17 & 0XFFFF;
    // 0x8005E09C: sh          $v0, 0x90($sp)
    MEM_H(0X90, ctx->r29) = ctx->r2;
    // 0x8005E0A0: lhu         $v0, 0xD4($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0XD4);
    // 0x8005E0A4: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    // 0x8005E0A8: sh          $v0, 0x92($sp)
    MEM_H(0X92, ctx->r29) = ctx->r2;
    // 0x8005E0AC: lbu         $v0, 0xD8($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0XD8);
    // 0x8005E0B0: addiu       $a2, $sp, 0x90
    ctx->r6 = ADD32(ctx->r29, 0X90);
    // 0x8005E0B4: sh          $v0, 0x94($sp)
    MEM_H(0X94, ctx->r29) = ctx->r2;
    // 0x8005E0B8: lhu         $v1, 0xD6($s0)
    ctx->r3 = MEM_HU(ctx->r16, 0XD6);
    // 0x8005E0BC: addiu       $v0, $sp, 0x28
    ctx->r2 = ADD32(ctx->r29, 0X28);
    // 0x8005E0C0: sw          $v0, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->r2;
    // 0x8005E0C4: jal         0x8003E8DC
    // 0x8005E0C8: sh          $v1, 0x96($sp)
    MEM_H(0X96, ctx->r29) = ctx->r3;
    func_8003E8DC(rdram, ctx);
        goto after_10;
    // 0x8005E0C8: sh          $v1, 0x96($sp)
    MEM_H(0X96, ctx->r29) = ctx->r3;
    after_10:
    // 0x8005E0CC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8005E0D0: j           L_8005E154
    // 0x8005E0D4: sb          $v0, 0xD9($s0)
    MEM_B(0XD9, ctx->r16) = ctx->r2;
        goto L_8005E154;
    // 0x8005E0D4: sb          $v0, 0xD9($s0)
    MEM_B(0XD9, ctx->r16) = ctx->r2;
L_8005E0D8:
    // 0x8005E0D8: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x8005E0DC: addiu       $s2, $v0, -0x7FA8
    ctx->r18 = ADD32(ctx->r2, -0X7FA8);
    // 0x8005E0E0: addu        $a2, $s2, $zero
    ctx->r6 = ADD32(ctx->r18, 0);
    // 0x8005E0E4: lwc1        $f12, 0x90($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X90);
    // 0x8005E0E8: lwc1        $f14, 0x98($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X98);
    // 0x8005E0EC: jal         0x80067D90
    // 0x8005E0F0: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    func_80067D90(rdram, ctx);
        goto after_11;
    // 0x8005E0F0: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    after_11:
    // 0x8005E0F4: lwc1        $f2, 0x94($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X94);
    // 0x8005E0F8: c.le.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl <= ctx->f2.fl;
    // 0x8005E0FC: nop

    // 0x8005E100: bc1f        L_8005E380
    if (!c1cs) {
        // 0x8005E104: addu        $a2, $s2, $zero
        ctx->r6 = ADD32(ctx->r18, 0);
            goto L_8005E380;
    }
    // 0x8005E104: addu        $a2, $s2, $zero
    ctx->r6 = ADD32(ctx->r18, 0);
    // 0x8005E108: lwc1        $f12, 0x90($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X90);
    // 0x8005E10C: lwc1        $f14, 0x98($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X98);
    // 0x8005E110: jal         0x800698F4
    // 0x8005E114: swc1        $f0, 0x94($s0)
    MEM_W(0X94, ctx->r16) = ctx->f0.u32l;
    func_800698F4(rdram, ctx);
        goto after_12;
    // 0x8005E114: swc1        $f0, 0x94($s0)
    MEM_W(0X94, ctx->r16) = ctx->f0.u32l;
    after_12:
    // 0x8005E118: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x8005E11C: bne         $v0, $v1, L_8005E154
    if (ctx->r2 != ctx->r3) {
        // 0x8005E120: addiu       $a0, $s0, 0x90
        ctx->r4 = ADD32(ctx->r16, 0X90);
            goto L_8005E154;
    }
    // 0x8005E120: addiu       $a0, $s0, 0x90
    ctx->r4 = ADD32(ctx->r16, 0X90);
    // 0x8005E124: lui         $a1, 0x3F19
    ctx->r5 = S32(0X3F19 << 16);
    // 0x8005E128: ori         $a1, $a1, 0x999A
    ctx->r5 = ctx->r5 | 0X999A;
    // 0x8005E12C: lui         $a2, 0x3F99
    ctx->r6 = S32(0X3F99 << 16);
    // 0x8005E130: ori         $a2, $a2, 0x999A
    ctx->r6 = ctx->r6 | 0X999A;
    // 0x8005E134: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x8005E138: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8005E13C: lwc1        $f0, -0x4F3C($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X4F3C);
    // 0x8005E140: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8005E144: lwc1        $f2, -0x4F38($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X4F38);
    // 0x8005E148: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    // 0x8005E14C: jal         0x80077858
    // 0x8005E150: swc1        $f2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f2.u32l;
    func_80077858(rdram, ctx);
        goto after_13;
    // 0x8005E150: swc1        $f2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f2.u32l;
    after_13:
L_8005E154:
    // 0x8005E154: lwc1        $f2, 0xD0($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0XD0);
    // 0x8005E158: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8005E15C: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x8005E160: nop

    // 0x8005E164: bc1f        L_8005E174
    if (!c1cs) {
        // 0x8005E168: addu        $a0, $s0, $zero
        ctx->r4 = ADD32(ctx->r16, 0);
            goto L_8005E174;
    }
    // 0x8005E168: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x8005E16C: jal         0x8005D94C
    // 0x8005E170: andi        $a1, $s1, 0xFFFF
    ctx->r5 = ctx->r17 & 0XFFFF;
    func_8005D94C(rdram, ctx);
        goto after_14;
    // 0x8005E170: andi        $a1, $s1, 0xFFFF
    ctx->r5 = ctx->r17 & 0XFFFF;
    after_14:
L_8005E174:
    // 0x8005E174: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8005E178: sb          $v0, 0xD9($s0)
    MEM_B(0XD9, ctx->r16) = ctx->r2;
    // 0x8005E17C: lhu         $a0, 0x16($s6)
    ctx->r4 = MEM_HU(ctx->r22, 0X16);
    // 0x8005E180: jal         0x8003ED74
    // 0x8005E184: nop

    func_8003ED74(rdram, ctx);
        goto after_15;
    // 0x8005E184: nop

    after_15:
    // 0x8005E188: j           L_8005E384
    // 0x8005E18C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8005E384;
    // 0x8005E18C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8005E190:
    // 0x8005E190: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x8005E194: addiu       $a2, $s0, 0x90
    ctx->r6 = ADD32(ctx->r16, 0X90);
    // 0x8005E198: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x8005E19C: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    // 0x8005E1A0: lui         $a3, 0x3F00
    ctx->r7 = S32(0X3F00 << 16);
    // 0x8005E1A4: jal         0x8001DC34
    // 0x8005E1A8: addu        $s1, $s2, $zero
    ctx->r17 = ADD32(ctx->r18, 0);
    func_8001DC34(rdram, ctx);
        goto after_16;
    // 0x8005E1A8: addu        $s1, $s2, $zero
    ctx->r17 = ADD32(ctx->r18, 0);
    after_16:
    // 0x8005E1AC: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x8005E1B0: beq         $v0, $zero, L_8005E384
    if (ctx->r2 == 0) {
        // 0x8005E1B4: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_8005E384;
    }
    // 0x8005E1B4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8005E1B8: lwc1        $f0, 0x90($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X90);
    // 0x8005E1BC: lwc1        $f2, 0x18($s2)
    ctx->f2.u32l = MEM_W(ctx->r18, 0X18);
    // 0x8005E1C0: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x8005E1C4: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8005E1C8: lwc1        $f4, -0x4F34($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X4F34);
    // 0x8005E1CC: mul.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x8005E1D0: trunc.w.s   $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    ctx->f16.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x8005E1D4: mfc1        $v0, $f16
    ctx->r2 = (int32_t)ctx->f16.u32l;
    // 0x8005E1D8: lwc1        $f0, 0x94($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X94);
    // 0x8005E1DC: sh          $v0, 0x8($s0)
    MEM_H(0X8, ctx->r16) = ctx->r2;
    // 0x8005E1E0: lwc1        $f2, 0x1C($s2)
    ctx->f2.u32l = MEM_W(ctx->r18, 0X1C);
    // 0x8005E1E4: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x8005E1E8: mul.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x8005E1EC: trunc.w.s   $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    ctx->f16.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x8005E1F0: mfc1        $v0, $f16
    ctx->r2 = (int32_t)ctx->f16.u32l;
    // 0x8005E1F4: lwc1        $f0, 0x98($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X98);
    // 0x8005E1F8: sh          $v0, 0xA($s0)
    MEM_H(0XA, ctx->r16) = ctx->r2;
    // 0x8005E1FC: lwc1        $f2, 0x20($s2)
    ctx->f2.u32l = MEM_W(ctx->r18, 0X20);
    // 0x8005E200: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x8005E204: mul.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x8005E208: trunc.w.s   $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    ctx->f16.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x8005E20C: mfc1        $v0, $f16
    ctx->r2 = (int32_t)ctx->f16.u32l;
    // 0x8005E210: sh          $v0, 0xC($s0)
    MEM_H(0XC, ctx->r16) = ctx->r2;
    // 0x8005E214: lw          $v0, 0x48($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X48);
    // 0x8005E218: lw          $v0, 0x20($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X20);
    // 0x8005E21C: beq         $v0, $zero, L_8005E228
    if (ctx->r2 == 0) {
        // 0x8005E220: sw          $v0, 0x0($s0)
        MEM_W(0X0, ctx->r16) = ctx->r2;
            goto L_8005E228;
    }
    // 0x8005E220: sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
    // 0x8005E224: sw          $s0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r16;
L_8005E228:
    // 0x8005E228: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    // 0x8005E22C: addiu       $a2, $zero, 0x30
    ctx->r6 = ADD32(0, 0X30);
    // 0x8005E230: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x8005E234: sw          $zero, 0x4($s0)
    MEM_W(0X4, ctx->r16) = 0;
    // 0x8005E238: lw          $v0, 0x48($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X48);
    // 0x8005E23C: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x8005E240: sw          $s0, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->r16;
L_8005E244:
    // 0x8005E244: lwc1        $f0, 0x9C($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0X9C);
    // 0x8005E248: lwc1        $f2, 0x18($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0X18);
    // 0x8005E24C: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x8005E250: mul.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x8005E254: trunc.w.s   $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    ctx->f16.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x8005E258: mfc1        $v0, $f16
    ctx->r2 = (int32_t)ctx->f16.u32l;
    // 0x8005E25C: sh          $v0, 0x38($a0)
    MEM_H(0X38, ctx->r4) = ctx->r2;
    // 0x8005E260: lwc1        $f0, 0xA0($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0XA0);
    // 0x8005E264: lwc1        $f2, 0x1C($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0X1C);
    // 0x8005E268: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x8005E26C: mul.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x8005E270: trunc.w.s   $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    ctx->f16.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x8005E274: mfc1        $v0, $f16
    ctx->r2 = (int32_t)ctx->f16.u32l;
    // 0x8005E278: sh          $v0, 0x3A($a0)
    MEM_H(0X3A, ctx->r4) = ctx->r2;
    // 0x8005E27C: lwc1        $f0, 0xA4($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0XA4);
    // 0x8005E280: lwc1        $f2, 0x20($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0X20);
    // 0x8005E284: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x8005E288: mul.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x8005E28C: trunc.w.s   $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    ctx->f16.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x8005E290: mfc1        $v0, $f16
    ctx->r2 = (int32_t)ctx->f16.u32l;
    // 0x8005E294: sh          $v0, 0x3C($a0)
    MEM_H(0X3C, ctx->r4) = ctx->r2;
    // 0x8005E298: lw          $v0, 0x48($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X48);
    // 0x8005E29C: lw          $v1, 0x20($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X20);
    // 0x8005E2A0: beq         $v1, $zero, L_8005E2B0
    if (ctx->r3 == 0) {
        // 0x8005E2A4: sw          $v1, 0x30($a0)
        MEM_W(0X30, ctx->r4) = ctx->r3;
            goto L_8005E2B0;
    }
    // 0x8005E2A4: sw          $v1, 0x30($a0)
    MEM_W(0X30, ctx->r4) = ctx->r3;
    // 0x8005E2A8: addu        $v0, $s0, $a2
    ctx->r2 = ADD32(ctx->r16, ctx->r6);
    // 0x8005E2AC: sw          $v0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r2;
L_8005E2B0:
    // 0x8005E2B0: addu        $v1, $s0, $a2
    ctx->r3 = ADD32(ctx->r16, ctx->r6);
    // 0x8005E2B4: addiu       $a2, $a2, 0x30
    ctx->r6 = ADD32(ctx->r6, 0X30);
    // 0x8005E2B8: addiu       $a1, $a1, 0xC
    ctx->r5 = ADD32(ctx->r5, 0XC);
    // 0x8005E2BC: sw          $zero, 0x34($a0)
    MEM_W(0X34, ctx->r4) = 0;
    // 0x8005E2C0: lw          $v0, 0x48($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X48);
    // 0x8005E2C4: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x8005E2C8: sw          $v1, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->r3;
    // 0x8005E2CC: slti        $v0, $a3, 0x2
    ctx->r2 = SIGNED(ctx->r7) < 0X2 ? 1 : 0;
    // 0x8005E2D0: bne         $v0, $zero, L_8005E244
    if (ctx->r2 != 0) {
        // 0x8005E2D4: addiu       $a0, $a0, 0x30
        ctx->r4 = ADD32(ctx->r4, 0X30);
            goto L_8005E244;
    }
    // 0x8005E2D4: addiu       $a0, $a0, 0x30
    ctx->r4 = ADD32(ctx->r4, 0X30);
    // 0x8005E2D8: j           L_8005E384
    // 0x8005E2DC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8005E384;
    // 0x8005E2DC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8005E2E0:
    // 0x8005E2E0: lh          $v1, 0x0($s2)
    ctx->r3 = MEM_H(ctx->r18, 0X0);
    // 0x8005E2E4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8005E2E8: beq         $v1, $v0, L_8005E300
    if (ctx->r3 == ctx->r2) {
        // 0x8005E2EC: addiu       $v0, $zero, 0x6
        ctx->r2 = ADD32(0, 0X6);
            goto L_8005E300;
    }
    // 0x8005E2EC: addiu       $v0, $zero, 0x6
    ctx->r2 = ADD32(0, 0X6);
    // 0x8005E2F0: beq         $v1, $v0, L_8005E36C
    if (ctx->r3 == ctx->r2) {
        // 0x8005E2F4: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_8005E36C;
    }
    // 0x8005E2F4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8005E2F8: j           L_8005E384
    // 0x8005E2FC: nop

        goto L_8005E384;
    // 0x8005E2FC: nop

L_8005E300:
    // 0x8005E300: lhu         $v0, 0xD6($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0XD6);
    // 0x8005E304: lwc1        $f2, 0x18($s2)
    ctx->f2.u32l = MEM_W(ctx->r18, 0X18);
    // 0x8005E308: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x8005E30C: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x8005E310: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x8005E314: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8005E318: lwc1        $f2, -0x4F30($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X4F30);
    // 0x8005E31C: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x8005E320: nop

    // 0x8005E324: bc1tl       L_8005E32C
    if (c1cs) {
        // 0x8005E328: mov.s       $f0, $f2
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
            goto L_8005E32C;
    }
    goto skip_0;
    // 0x8005E328: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    skip_0:
L_8005E32C:
    // 0x8005E32C: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8005E330: lwc1        $f2, -0x4F2C($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X4F2C);
    // 0x8005E334: c.le.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl <= ctx->f0.fl;
    // 0x8005E338: nop

    // 0x8005E33C: bc1tl       L_8005E354
    if (c1cs) {
        // 0x8005E340: sub.s       $f0, $f0, $f2
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
            goto L_8005E354;
    }
    goto skip_1;
    // 0x8005E340: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    skip_1:
    // 0x8005E344: trunc.w.s   $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    ctx->f16.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x8005E348: mfc1        $v1, $f16
    ctx->r3 = (int32_t)ctx->f16.u32l;
    // 0x8005E34C: j           L_8005E380
    // 0x8005E350: sh          $v1, 0xD6($s0)
    MEM_H(0XD6, ctx->r16) = ctx->r3;
        goto L_8005E380;
    // 0x8005E350: sh          $v1, 0xD6($s0)
    MEM_H(0XD6, ctx->r16) = ctx->r3;
L_8005E354:
    // 0x8005E354: lui         $v0, 0x8000
    ctx->r2 = S32(0X8000 << 16);
    // 0x8005E358: trunc.w.s   $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    ctx->f16.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x8005E35C: mfc1        $v1, $f16
    ctx->r3 = (int32_t)ctx->f16.u32l;
    // 0x8005E360: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x8005E364: j           L_8005E380
    // 0x8005E368: sh          $v1, 0xD6($s0)
    MEM_H(0XD6, ctx->r16) = ctx->r3;
        goto L_8005E380;
    // 0x8005E368: sh          $v1, 0xD6($s0)
    MEM_H(0XD6, ctx->r16) = ctx->r3;
L_8005E36C:
    // 0x8005E36C: lwc1        $f0, 0x18($s2)
    ctx->f0.u32l = MEM_W(ctx->r18, 0X18);
    // 0x8005E370: j           L_8005E380
    // 0x8005E374: swc1        $f0, 0xD0($s0)
    MEM_W(0XD0, ctx->r16) = ctx->f0.u32l;
        goto L_8005E380;
    // 0x8005E374: swc1        $f0, 0xD0($s0)
    MEM_W(0XD0, ctx->r16) = ctx->f0.u32l;
L_8005E378:
    // 0x8005E378: addiu       $v0, $zero, 0x1005
    ctx->r2 = ADD32(0, 0X1005);
    // 0x8005E37C: sh          $v0, 0x2($s2)
    MEM_H(0X2, ctx->r18) = ctx->r2;
L_8005E380:
    // 0x8005E380: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8005E384:
    // 0x8005E384: lw          $ra, 0xC4($sp)
    ctx->r31 = MEM_W(ctx->r29, 0XC4);
    // 0x8005E388: lw          $s6, 0xC0($sp)
    ctx->r22 = MEM_W(ctx->r29, 0XC0);
    // 0x8005E38C: lw          $s5, 0xBC($sp)
    ctx->r21 = MEM_W(ctx->r29, 0XBC);
    // 0x8005E390: lw          $s4, 0xB8($sp)
    ctx->r20 = MEM_W(ctx->r29, 0XB8);
    // 0x8005E394: lw          $s3, 0xB4($sp)
    ctx->r19 = MEM_W(ctx->r29, 0XB4);
    // 0x8005E398: lw          $s2, 0xB0($sp)
    ctx->r18 = MEM_W(ctx->r29, 0XB0);
    // 0x8005E39C: lw          $s1, 0xAC($sp)
    ctx->r17 = MEM_W(ctx->r29, 0XAC);
    // 0x8005E3A0: lw          $s0, 0xA8($sp)
    ctx->r16 = MEM_W(ctx->r29, 0XA8);
    // 0x8005E3A4: ldc1        $f20, 0xC8($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0XC8);
    // 0x8005E3A8: jr          $ra
    // 0x8005E3AC: addiu       $sp, $sp, 0xD0
    ctx->r29 = ADD32(ctx->r29, 0XD0);
    return;
    // 0x8005E3AC: addiu       $sp, $sp, 0xD0
    ctx->r29 = ADD32(ctx->r29, 0XD0);
;}
RECOMP_FUNC void func_8005E3B0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005E3B0: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8005E3B4: lbu         $v0, 0xB39($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0XB39);
    // 0x8005E3B8: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x8005E3BC: sw          $s3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r19;
    // 0x8005E3C0: addu        $s3, $a0, $zero
    ctx->r19 = ADD32(ctx->r4, 0);
    // 0x8005E3C4: sw          $s2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r18;
    // 0x8005E3C8: addu        $s2, $a2, $zero
    ctx->r18 = ADD32(ctx->r6, 0);
    // 0x8005E3CC: sw          $s1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r17;
    // 0x8005E3D0: addu        $s1, $a3, $zero
    ctx->r17 = ADD32(ctx->r7, 0);
    // 0x8005E3D4: sw          $s0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r16;
    // 0x8005E3D8: addu        $s0, $a1, $zero
    ctx->r16 = ADD32(ctx->r5, 0);
    // 0x8005E3DC: bne         $v0, $zero, L_8005E40C
    if (ctx->r2 != 0) {
        // 0x8005E3E0: sw          $ra, 0x40($sp)
        MEM_W(0X40, ctx->r29) = ctx->r31;
            goto L_8005E40C;
    }
    // 0x8005E3E0: sw          $ra, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r31;
    // 0x8005E3E4: jal         0x8006C994
    // 0x8005E3E8: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    func_8006C994(rdram, ctx);
        goto after_0;
    // 0x8005E3E8: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    after_0:
    // 0x8005E3EC: andi        $v1, $s0, 0xFFFF
    ctx->r3 = ctx->r16 & 0XFFFF;
    // 0x8005E3F0: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x8005E3F4: bne         $v1, $v0, L_8005E40C
    if (ctx->r3 != ctx->r2) {
        // 0x8005E3F8: lui         $v1, 0x8013
        ctx->r3 = S32(0X8013 << 16);
            goto L_8005E40C;
    }
    // 0x8005E3F8: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x8005E3FC: addiu       $v1, $v1, 0xB78
    ctx->r3 = ADD32(ctx->r3, 0XB78);
    // 0x8005E400: lw          $v0, 0x4($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X4);
    // 0x8005E404: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8005E408: sw          $v0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r2;
L_8005E40C:
    // 0x8005E40C: lwc1        $f0, 0x5C($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x8005E410: lw          $v0, 0x58($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X58);
    // 0x8005E414: addiu       $v1, $s3, -0x2
    ctx->r3 = ADD32(ctx->r19, -0X2);
    // 0x8005E418: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x8005E41C: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x8005E420: sh          $s0, 0x28($sp)
    MEM_H(0X28, ctx->r29) = ctx->r16;
    // 0x8005E424: sh          $v0, 0x2A($sp)
    MEM_H(0X2A, ctx->r29) = ctx->r2;
    // 0x8005E428: sltiu       $v0, $v1, 0xD
    ctx->r2 = ctx->r3 < 0XD ? 1 : 0;
    // 0x8005E42C: beq         $v0, $zero, L_8005E5E8
    if (ctx->r2 == 0) {
        // 0x8005E430: swc1        $f0, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->f0.u32l;
            goto L_8005E5E8;
    }
    // 0x8005E430: swc1        $f0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f0.u32l;
    // 0x8005E434: lui         $v0, 0x8004
    ctx->r2 = S32(0X8004 << 16);
    // 0x8005E438: addiu       $v0, $v0, -0x4F28
    ctx->r2 = ADD32(ctx->r2, -0X4F28);
    // 0x8005E43C: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x8005E440: addu        $v1, $v1, $v0
    gpr jr_addend_8005E448 = ctx->r3;
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x8005E444: lw          $v0, 0x0($v1)
    ctx->r2 = ADD32(ctx->r3, 0X0);
    // 0x8005E448: jr          $v0
    // 0x8005E44C: nop

    switch (jr_addend_8005E448 >> 2) {
        case 0: goto L_8005E5D0; break;
        case 1: goto L_8005E5D0; break;
        case 2: goto L_8005E5D0; break;
        case 3: goto L_8005E5D0; break;
        case 4: goto L_8005E494; break;
        case 5: goto L_8005E5E8; break;
        case 6: goto L_8005E468; break;
        case 7: goto L_8005E450; break;
        case 8: goto L_8005E514; break;
        case 9: goto L_8005E4FC; break;
        case 10: goto L_8005E5AC; break;
        case 11: goto L_8005E574; break;
        case 12: goto L_8005E540; break;
        default: switch_error(__func__, 0x8005E448, 0x8003B0D8);
    }
    // 0x8005E44C: nop

L_8005E450:
    // 0x8005E450: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8005E454: lbu         $v0, 0xB39($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0XB39);
    // 0x8005E458: bne         $v0, $zero, L_8005E46C
    if (ctx->r2 != 0) {
        // 0x8005E45C: lui         $v0, 0x8013
        ctx->r2 = S32(0X8013 << 16);
            goto L_8005E46C;
    }
    // 0x8005E45C: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8005E460: jal         0x800EFD6C
    // 0x8005E464: addiu       $a0, $zero, 0xFA
    ctx->r4 = ADD32(0, 0XFA);
    func_800EFD6C(rdram, ctx);
        goto after_1;
    // 0x8005E464: addiu       $a0, $zero, 0xFA
    ctx->r4 = ADD32(0, 0XFA);
    after_1:
L_8005E468:
    // 0x8005E468: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
L_8005E46C:
    // 0x8005E46C: lui         $v1, 0x8014
    ctx->r3 = S32(0X8014 << 16);
    // 0x8005E470: lw          $v0, 0x7CE4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X7CE4);
    // 0x8005E474: lw          $v1, -0x69E4($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X69E4);
    // 0x8005E478: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8005E47C: lwc1        $f0, -0x4EF4($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X4EF4);
    // 0x8005E480: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x8005E484: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8005E488: lhu         $v0, 0x10($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X10);
    // 0x8005E48C: j           L_8005E59C
    // 0x8005E490: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
        goto L_8005E59C;
    // 0x8005E490: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
L_8005E494:
    // 0x8005E494: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8005E498: lbu         $v0, 0xB39($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0XB39);
    // 0x8005E49C: bne         $v0, $zero, L_8005E4AC
    if (ctx->r2 != 0) {
        // 0x8005E4A0: nop
    
            goto L_8005E4AC;
    }
    // 0x8005E4A0: nop

    // 0x8005E4A4: jal         0x800EFD6C
    // 0x8005E4A8: addiu       $a0, $zero, 0xFA
    ctx->r4 = ADD32(0, 0XFA);
    func_800EFD6C(rdram, ctx);
        goto after_2;
    // 0x8005E4A8: addiu       $a0, $zero, 0xFA
    ctx->r4 = ADD32(0, 0XFA);
    after_2:
L_8005E4AC:
    // 0x8005E4AC: lwc1        $f0, 0x0($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X0);
    // 0x8005E4B0: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8005E4B4: lwc1        $f2, -0x4EF0($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X4EF0);
    // 0x8005E4B8: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x8005E4BC: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    // 0x8005E4C0: lwc1        $f0, 0x4($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X4);
    // 0x8005E4C4: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x8005E4C8: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8005E4CC: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    // 0x8005E4D0: lwc1        $f0, 0x8($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X8);
    // 0x8005E4D4: lui         $v1, 0x8014
    ctx->r3 = S32(0X8014 << 16);
    // 0x8005E4D8: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x8005E4DC: lw          $v0, 0x7CE4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X7CE4);
    // 0x8005E4E0: lw          $v1, -0x69E4($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X69E4);
    // 0x8005E4E4: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x8005E4E8: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8005E4EC: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    // 0x8005E4F0: lhu         $v0, 0x8($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X8);
    // 0x8005E4F4: j           L_8005E688
    // 0x8005E4F8: sh          $v0, 0x2C($sp)
    MEM_H(0X2C, ctx->r29) = ctx->r2;
        goto L_8005E688;
    // 0x8005E4F8: sh          $v0, 0x2C($sp)
    MEM_H(0X2C, ctx->r29) = ctx->r2;
L_8005E4FC:
    // 0x8005E4FC: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8005E500: lbu         $v0, 0xB39($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0XB39);
    // 0x8005E504: bne         $v0, $zero, L_8005E518
    if (ctx->r2 != 0) {
        // 0x8005E508: lui         $v0, 0x8013
        ctx->r2 = S32(0X8013 << 16);
            goto L_8005E518;
    }
    // 0x8005E508: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8005E50C: jal         0x800EFD6C
    // 0x8005E510: addiu       $a0, $zero, 0xFA
    ctx->r4 = ADD32(0, 0XFA);
    func_800EFD6C(rdram, ctx);
        goto after_3;
    // 0x8005E510: addiu       $a0, $zero, 0xFA
    ctx->r4 = ADD32(0, 0XFA);
    after_3:
L_8005E514:
    // 0x8005E514: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
L_8005E518:
    // 0x8005E518: lui         $v1, 0x8014
    ctx->r3 = S32(0X8014 << 16);
    // 0x8005E51C: lw          $v0, 0x7CE4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X7CE4);
    // 0x8005E520: lw          $v1, -0x69E4($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X69E4);
    // 0x8005E524: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8005E528: lwc1        $f0, -0x4EEC($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X4EEC);
    // 0x8005E52C: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x8005E530: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8005E534: lhu         $v0, 0x18($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X18);
    // 0x8005E538: j           L_8005E59C
    // 0x8005E53C: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
        goto L_8005E59C;
    // 0x8005E53C: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
L_8005E540:
    // 0x8005E540: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8005E544: lui         $v1, 0x8014
    ctx->r3 = S32(0X8014 << 16);
    // 0x8005E548: lw          $v0, 0x7CE4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X7CE4);
    // 0x8005E54C: lw          $v1, -0x69E4($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X69E4);
    // 0x8005E550: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8005E554: lwc1        $f2, -0x4EE8($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X4EE8);
    // 0x8005E558: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x8005E55C: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8005E560: lhu         $v0, 0x18($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X18);
    // 0x8005E564: sh          $v0, 0x2C($sp)
    MEM_H(0X2C, ctx->r29) = ctx->r2;
    // 0x8005E568: lwc1        $f0, 0x0($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X0);
    // 0x8005E56C: j           L_8005E650
    // 0x8005E570: nop

        goto L_8005E650;
    // 0x8005E570: nop

L_8005E574:
    // 0x8005E574: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8005E578: lui         $v1, 0x8014
    ctx->r3 = S32(0X8014 << 16);
    // 0x8005E57C: lw          $v0, 0x7CE4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X7CE4);
    // 0x8005E580: lw          $v1, -0x69E4($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X69E4);
    // 0x8005E584: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8005E588: lwc1        $f0, -0x4EE4($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X4EE4);
    // 0x8005E58C: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x8005E590: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8005E594: lhu         $v0, 0x28($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X28);
    // 0x8005E598: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
L_8005E59C:
    // 0x8005E59C: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    // 0x8005E5A0: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    // 0x8005E5A4: j           L_8005E688
    // 0x8005E5A8: sh          $v0, 0x2C($sp)
    MEM_H(0X2C, ctx->r29) = ctx->r2;
        goto L_8005E688;
    // 0x8005E5A8: sh          $v0, 0x2C($sp)
    MEM_H(0X2C, ctx->r29) = ctx->r2;
L_8005E5AC:
    // 0x8005E5AC: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8005E5B0: lui         $v1, 0x8014
    ctx->r3 = S32(0X8014 << 16);
    // 0x8005E5B4: lw          $v0, 0x7CE4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X7CE4);
    // 0x8005E5B8: lw          $v1, -0x69E4($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X69E4);
    // 0x8005E5BC: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x8005E5C0: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8005E5C4: lhu         $v0, 0x20($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X20);
    // 0x8005E5C8: j           L_8005E63C
    // 0x8005E5CC: sh          $v0, 0x2C($sp)
    MEM_H(0X2C, ctx->r29) = ctx->r2;
        goto L_8005E63C;
    // 0x8005E5CC: sh          $v0, 0x2C($sp)
    MEM_H(0X2C, ctx->r29) = ctx->r2;
L_8005E5D0:
    // 0x8005E5D0: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8005E5D4: lbu         $v0, 0xB39($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0XB39);
    // 0x8005E5D8: bne         $v0, $zero, L_8005E5E8
    if (ctx->r2 != 0) {
        // 0x8005E5DC: nop
    
            goto L_8005E5E8;
    }
    // 0x8005E5DC: nop

    // 0x8005E5E0: jal         0x800EFD6C
    // 0x8005E5E4: addiu       $a0, $zero, 0xFA
    ctx->r4 = ADD32(0, 0XFA);
    func_800EFD6C(rdram, ctx);
        goto after_4;
    // 0x8005E5E4: addiu       $a0, $zero, 0xFA
    ctx->r4 = ADD32(0, 0XFA);
    after_4:
L_8005E5E8:
    // 0x8005E5E8: jal         0x8006C994
    // 0x8005E5EC: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    func_8006C994(rdram, ctx);
        goto after_5;
    // 0x8005E5EC: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    after_5:
    // 0x8005E5F0: andi        $v1, $s0, 0xFFFF
    ctx->r3 = ctx->r16 & 0XFFFF;
    // 0x8005E5F4: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x8005E5F8: bne         $v1, $v0, L_8005E620
    if (ctx->r3 != ctx->r2) {
        // 0x8005E5FC: lui         $v0, 0x8013
        ctx->r2 = S32(0X8013 << 16);
            goto L_8005E620;
    }
    // 0x8005E5FC: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8005E600: lui         $v1, 0x8014
    ctx->r3 = S32(0X8014 << 16);
    // 0x8005E604: lw          $v0, 0x7CE4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X7CE4);
    // 0x8005E608: lw          $v1, -0x69E4($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X69E4);
    // 0x8005E60C: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x8005E610: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8005E614: lhu         $v0, 0x38($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X38);
    // 0x8005E618: j           L_8005E63C
    // 0x8005E61C: sh          $v0, 0x2C($sp)
    MEM_H(0X2C, ctx->r29) = ctx->r2;
        goto L_8005E63C;
    // 0x8005E61C: sh          $v0, 0x2C($sp)
    MEM_H(0X2C, ctx->r29) = ctx->r2;
L_8005E620:
    // 0x8005E620: lui         $v1, 0x8014
    ctx->r3 = S32(0X8014 << 16);
    // 0x8005E624: lw          $v0, 0x7CE4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X7CE4);
    // 0x8005E628: lw          $v1, -0x69E4($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X69E4);
    // 0x8005E62C: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x8005E630: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8005E634: lhu         $v0, 0x0($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X0);
    // 0x8005E638: sh          $v0, 0x2C($sp)
    MEM_H(0X2C, ctx->r29) = ctx->r2;
L_8005E63C:
    // 0x8005E63C: beq         $s1, $zero, L_8005E674
    if (ctx->r17 == 0) {
        // 0x8005E640: nop
    
            goto L_8005E674;
    }
    // 0x8005E640: nop

    // 0x8005E644: lwc1        $f0, 0x0($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X0);
    // 0x8005E648: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8005E64C: lwc1        $f2, -0x4EE0($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X4EE0);
L_8005E650:
    // 0x8005E650: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x8005E654: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    // 0x8005E658: lwc1        $f0, 0x4($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X4);
    // 0x8005E65C: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x8005E660: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    // 0x8005E664: lwc1        $f0, 0x8($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X8);
    // 0x8005E668: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x8005E66C: j           L_8005E688
    // 0x8005E670: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
        goto L_8005E688;
    // 0x8005E670: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
L_8005E674:
    // 0x8005E674: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8005E678: lwc1        $f0, -0x4EDC($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X4EDC);
    // 0x8005E67C: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    // 0x8005E680: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    // 0x8005E684: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
L_8005E688:
    // 0x8005E688: lhu         $v0, 0x2C($sp)
    ctx->r2 = MEM_HU(ctx->r29, 0X2C);
    // 0x8005E68C: lwc1        $f0, 0x60($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X60);
    // 0x8005E690: mtc1        $v0, $f2
    ctx->f2.u32l = ctx->r2;
    // 0x8005E694: cvt.s.w     $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    ctx->f2.fl = CVT_S_W(ctx->f2.u32l);
    // 0x8005E698: mul.s       $f0, $f2, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x8005E69C: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8005E6A0: lwc1        $f2, -0x4ED8($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X4ED8);
    // 0x8005E6A4: c.le.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl <= ctx->f0.fl;
    // 0x8005E6A8: nop

    // 0x8005E6AC: bc1tl       L_8005E6C4
    if (c1cs) {
        // 0x8005E6B0: sub.s       $f0, $f0, $f2
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
            goto L_8005E6C4;
    }
    goto skip_0;
    // 0x8005E6B0: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    skip_0:
    // 0x8005E6B4: trunc.w.s   $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    ctx->f4.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x8005E6B8: mfc1        $v1, $f4
    ctx->r3 = (int32_t)ctx->f4.u32l;
    // 0x8005E6BC: j           L_8005E6D8
    // 0x8005E6C0: sh          $v1, 0x2C($sp)
    MEM_H(0X2C, ctx->r29) = ctx->r3;
        goto L_8005E6D8;
    // 0x8005E6C0: sh          $v1, 0x2C($sp)
    MEM_H(0X2C, ctx->r29) = ctx->r3;
L_8005E6C4:
    // 0x8005E6C4: lui         $v0, 0x8000
    ctx->r2 = S32(0X8000 << 16);
    // 0x8005E6C8: trunc.w.s   $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    ctx->f4.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x8005E6CC: mfc1        $v1, $f4
    ctx->r3 = (int32_t)ctx->f4.u32l;
    // 0x8005E6D0: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x8005E6D4: sh          $v1, 0x2C($sp)
    MEM_H(0X2C, ctx->r29) = ctx->r3;
L_8005E6D8:
    // 0x8005E6D8: addiu       $v1, $s3, -0x1
    ctx->r3 = ADD32(ctx->r19, -0X1);
    // 0x8005E6DC: sltiu       $v0, $v1, 0xE
    ctx->r2 = ctx->r3 < 0XE ? 1 : 0;
    // 0x8005E6E0: beq         $v0, $zero, L_8005E7A8
    if (ctx->r2 == 0) {
        // 0x8005E6E4: lui         $v0, 0x8004
        ctx->r2 = S32(0X8004 << 16);
            goto L_8005E7A8;
    }
    // 0x8005E6E4: lui         $v0, 0x8004
    ctx->r2 = S32(0X8004 << 16);
    // 0x8005E6E8: addiu       $v0, $v0, -0x4ED0
    ctx->r2 = ADD32(ctx->r2, -0X4ED0);
    // 0x8005E6EC: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x8005E6F0: addu        $v1, $v1, $v0
    gpr jr_addend_8005E6F8 = ctx->r3;
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x8005E6F4: lw          $v0, 0x0($v1)
    ctx->r2 = ADD32(ctx->r3, 0X0);
    // 0x8005E6F8: jr          $v0
    // 0x8005E6FC: nop

    switch (jr_addend_8005E6F8 >> 2) {
        case 0: goto L_8005E790; break;
        case 1: goto L_8005E7A8; break;
        case 2: goto L_8005E7A8; break;
        case 3: goto L_8005E778; break;
        case 4: goto L_8005E778; break;
        case 5: goto L_8005E7A8; break;
        case 6: goto L_8005E7A8; break;
        case 7: goto L_8005E748; break;
        case 8: goto L_8005E730; break;
        case 9: goto L_8005E718; break;
        case 10: goto L_8005E700; break;
        case 11: goto L_8005E760; break;
        case 12: goto L_8005E718; break;
        case 13: goto L_8005E718; break;
        default: switch_error(__func__, 0x8005E6F8, 0x8003B130);
    }
    // 0x8005E6FC: nop

L_8005E700:
    // 0x8005E700: lui         $a0, 0x8006
    ctx->r4 = S32(0X8006 << 16);
    // 0x8005E704: addiu       $a0, $a0, -0x65C
    ctx->r4 = ADD32(ctx->r4, -0X65C);
    // 0x8005E708: addiu       $a1, $sp, 0x10
    ctx->r5 = ADD32(ctx->r29, 0X10);
    // 0x8005E70C: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x8005E710: j           L_8005E7C4
    // 0x8005E714: addiu       $a3, $zero, 0xC
    ctx->r7 = ADD32(0, 0XC);
        goto L_8005E7C4;
    // 0x8005E714: addiu       $a3, $zero, 0xC
    ctx->r7 = ADD32(0, 0XC);
L_8005E718:
    // 0x8005E718: lui         $a0, 0x8006
    ctx->r4 = S32(0X8006 << 16);
    // 0x8005E71C: addiu       $a0, $a0, -0x65C
    ctx->r4 = ADD32(ctx->r4, -0X65C);
    // 0x8005E720: addiu       $a1, $sp, 0x10
    ctx->r5 = ADD32(ctx->r29, 0X10);
    // 0x8005E724: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x8005E728: j           L_8005E7C4
    // 0x8005E72C: addiu       $a3, $zero, 0x23
    ctx->r7 = ADD32(0, 0X23);
        goto L_8005E7C4;
    // 0x8005E72C: addiu       $a3, $zero, 0x23
    ctx->r7 = ADD32(0, 0X23);
L_8005E730:
    // 0x8005E730: lui         $a0, 0x8006
    ctx->r4 = S32(0X8006 << 16);
    // 0x8005E734: addiu       $a0, $a0, -0x2528
    ctx->r4 = ADD32(ctx->r4, -0X2528);
    // 0x8005E738: addiu       $a1, $sp, 0x10
    ctx->r5 = ADD32(ctx->r29, 0X10);
    // 0x8005E73C: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x8005E740: j           L_8005E7C4
    // 0x8005E744: addiu       $a3, $zero, 0xC
    ctx->r7 = ADD32(0, 0XC);
        goto L_8005E7C4;
    // 0x8005E744: addiu       $a3, $zero, 0xC
    ctx->r7 = ADD32(0, 0XC);
L_8005E748:
    // 0x8005E748: lui         $a0, 0x8006
    ctx->r4 = S32(0X8006 << 16);
    // 0x8005E74C: addiu       $a0, $a0, -0x2528
    ctx->r4 = ADD32(ctx->r4, -0X2528);
    // 0x8005E750: addiu       $a1, $sp, 0x10
    ctx->r5 = ADD32(ctx->r29, 0X10);
    // 0x8005E754: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x8005E758: j           L_8005E7C4
    // 0x8005E75C: addiu       $a3, $zero, 0x23
    ctx->r7 = ADD32(0, 0X23);
        goto L_8005E7C4;
    // 0x8005E75C: addiu       $a3, $zero, 0x23
    ctx->r7 = ADD32(0, 0X23);
L_8005E760:
    // 0x8005E760: lui         $a0, 0x8006
    ctx->r4 = S32(0X8006 << 16);
    // 0x8005E764: addiu       $a0, $a0, -0x378C
    ctx->r4 = ADD32(ctx->r4, -0X378C);
    // 0x8005E768: addiu       $a1, $sp, 0x10
    ctx->r5 = ADD32(ctx->r29, 0X10);
    // 0x8005E76C: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x8005E770: j           L_8005E7C4
    // 0x8005E774: addiu       $a3, $zero, 0x23
    ctx->r7 = ADD32(0, 0X23);
        goto L_8005E7C4;
    // 0x8005E774: addiu       $a3, $zero, 0x23
    ctx->r7 = ADD32(0, 0X23);
L_8005E778:
    // 0x8005E778: lui         $a0, 0x8006
    ctx->r4 = S32(0X8006 << 16);
    // 0x8005E77C: addiu       $a0, $a0, -0x378C
    ctx->r4 = ADD32(ctx->r4, -0X378C);
    // 0x8005E780: addiu       $a1, $sp, 0x10
    ctx->r5 = ADD32(ctx->r29, 0X10);
    // 0x8005E784: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x8005E788: j           L_8005E7C4
    // 0x8005E78C: addiu       $a3, $zero, 0xC
    ctx->r7 = ADD32(0, 0XC);
        goto L_8005E7C4;
    // 0x8005E78C: addiu       $a3, $zero, 0xC
    ctx->r7 = ADD32(0, 0XC);
L_8005E790:
    // 0x8005E790: lui         $a0, 0x8006
    ctx->r4 = S32(0X8006 << 16);
    // 0x8005E794: addiu       $a0, $a0, -0x378C
    ctx->r4 = ADD32(ctx->r4, -0X378C);
    // 0x8005E798: addiu       $a1, $sp, 0x10
    ctx->r5 = ADD32(ctx->r29, 0X10);
    // 0x8005E79C: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x8005E7A0: j           L_8005E7C4
    // 0x8005E7A4: addiu       $a3, $zero, 0x23
    ctx->r7 = ADD32(0, 0X23);
        goto L_8005E7C4;
    // 0x8005E7A4: addiu       $a3, $zero, 0x23
    ctx->r7 = ADD32(0, 0X23);
L_8005E7A8:
    // 0x8005E7A8: addiu       $a3, $zero, 0xC
    ctx->r7 = ADD32(0, 0XC);
    // 0x8005E7AC: lui         $v0, 0x8006
    ctx->r2 = S32(0X8006 << 16);
    // 0x8005E7B0: bne         $s3, $zero, L_8005E7BC
    if (ctx->r19 != 0) {
        // 0x8005E7B4: addiu       $a0, $v0, -0x378C
        ctx->r4 = ADD32(ctx->r2, -0X378C);
            goto L_8005E7BC;
    }
    // 0x8005E7B4: addiu       $a0, $v0, -0x378C
    ctx->r4 = ADD32(ctx->r2, -0X378C);
    // 0x8005E7B8: addiu       $a3, $zero, 0x23
    ctx->r7 = ADD32(0, 0X23);
L_8005E7BC:
    // 0x8005E7BC: addiu       $a1, $sp, 0x10
    ctx->r5 = ADD32(ctx->r29, 0X10);
    // 0x8005E7C0: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
L_8005E7C4:
    // 0x8005E7C4: jal         0x8003FFEC
    // 0x8005E7C8: nop

    func_8003FFEC(rdram, ctx);
        goto after_6;
    // 0x8005E7C8: nop

    after_6:
    // 0x8005E7CC: lw          $ra, 0x40($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X40);
    // 0x8005E7D0: lw          $s3, 0x3C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X3C);
    // 0x8005E7D4: lw          $s2, 0x38($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X38);
    // 0x8005E7D8: lw          $s1, 0x34($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X34);
    // 0x8005E7DC: lw          $s0, 0x30($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X30);
    // 0x8005E7E0: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x8005E7E4: jr          $ra
    // 0x8005E7E8: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x8005E7E8: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void func_8005E7EC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005E7EC: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8005E7F0: lui         $a0, 0x8004
    ctx->r4 = S32(0X8004 << 16);
    // 0x8005E7F4: addiu       $a0, $a0, -0x4E84
    ctx->r4 = ADD32(ctx->r4, -0X4E84);
    // 0x8005E7F8: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x8005E7FC: addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    // 0x8005E800: addu        $a3, $a1, $zero
    ctx->r7 = ADD32(ctx->r5, 0);
    // 0x8005E804: sw          $ra, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r31;
    // 0x8005E808: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x8005E80C: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8005E810: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8005E814: jal         0x8005645C
    // 0x8005E818: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    load_hmt_and_hob(rdram, ctx);
        goto after_0;
    // 0x8005E818: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    after_0:
    // 0x8005E81C: addu        $s3, $zero, $zero
    ctx->r19 = ADD32(0, 0);
    // 0x8005E820: lui         $s2, 0x1
    ctx->r18 = S32(0X1 << 16);
    // 0x8005E824: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x8005E828: addiu       $s0, $v0, -0x6A20
    ctx->r16 = ADD32(ctx->r2, -0X6A20);
    // 0x8005E82C: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x8005E830: addiu       $s1, $v0, -0x1300
    ctx->r17 = ADD32(ctx->r2, -0X1300);
L_8005E834:
    // 0x8005E834: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x8005E838: beql        $a0, $zero, L_8005E860
    if (ctx->r4 == 0) {
        // 0x8005E83C: sw          $zero, 0x0($s0)
        MEM_W(0X0, ctx->r16) = 0;
            goto L_8005E860;
    }
    goto skip_0;
    // 0x8005E83C: sw          $zero, 0x0($s0)
    MEM_W(0X0, ctx->r16) = 0;
    skip_0:
    // 0x8005E840: jal         0x80057B4C
    // 0x8005E844: nop

    getHobObjectByName(rdram, ctx);
        goto after_1;
    // 0x8005E844: nop

    after_1:
    // 0x8005E848: sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
    // 0x8005E84C: lw          $v0, 0x10($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X10);
    // 0x8005E850: lw          $v1, 0x10($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X10);
    // 0x8005E854: lw          $v0, 0xC($v1)
    ctx->r2 = MEM_W(ctx->r3, 0XC);
    // 0x8005E858: or          $v0, $v0, $s2
    ctx->r2 = ctx->r2 | ctx->r18;
    // 0x8005E85C: sw          $v0, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r2;
L_8005E860:
    // 0x8005E860: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x8005E864: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x8005E868: slti        $v0, $s3, 0xF
    ctx->r2 = SIGNED(ctx->r19) < 0XF ? 1 : 0;
    // 0x8005E86C: bne         $v0, $zero, L_8005E834
    if (ctx->r2 != 0) {
        // 0x8005E870: addiu       $s1, $s1, 0x4
        ctx->r17 = ADD32(ctx->r17, 0X4);
            goto L_8005E834;
    }
    // 0x8005E870: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x8005E874: lui         $a0, 0x8004
    ctx->r4 = S32(0X8004 << 16);
    // 0x8005E878: addiu       $a0, $a0, -0x4E98
    ctx->r4 = ADD32(ctx->r4, -0X4E98);
    // 0x8005E87C: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x8005E880: jal         0x800554D8
    // 0x8005E884: addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    func_800554D8(rdram, ctx);
        goto after_2;
    // 0x8005E884: addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    after_2:
    // 0x8005E888: lui         $v1, 0x8014
    ctx->r3 = S32(0X8014 << 16);
    // 0x8005E88C: jal         0x8006108C
    // 0x8005E890: sh          $v0, -0x68C8($v1)
    MEM_H(-0X68C8, ctx->r3) = ctx->r2;
    func_8006108C(rdram, ctx);
        goto after_3;
    // 0x8005E890: sh          $v0, -0x68C8($v1)
    MEM_H(-0X68C8, ctx->r3) = ctx->r2;
    after_3:
    // 0x8005E894: addiu       $a0, $zero, 0x400
    ctx->r4 = ADD32(0, 0X400);
    // 0x8005E898: jal         0x80001ACC
    // 0x8005E89C: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    rs_malloc(rdram, ctx);
        goto after_4;
    // 0x8005E89C: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    after_4:
    // 0x8005E8A0: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x8005E8A4: lui         $a3, 0x8004
    ctx->r7 = S32(0X8004 << 16);
    // 0x8005E8A8: addiu       $a3, $a3, -0x4E7C
    ctx->r7 = ADD32(ctx->r7, -0X4E7C);
    // 0x8005E8AC: addiu       $s3, $zero, 0x3
    ctx->r19 = ADD32(0, 0X3);
    // 0x8005E8B0: lui         $s0, 0x8014
    ctx->r16 = S32(0X8014 << 16);
    // 0x8005E8B4: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x8005E8B8: lw          $a0, -0x76E0($s0)
    ctx->r4 = MEM_W(ctx->r16, -0X76E0);
    // 0x8005E8BC: lw          $a2, 0x7CFC($v1)
    ctx->r6 = MEM_W(ctx->r3, 0X7CFC);
    // 0x8005E8C0: lui         $s1, 0x8014
    ctx->r17 = S32(0X8014 << 16);
    // 0x8005E8C4: sw          $v0, -0x68C0($s1)
    MEM_W(-0X68C0, ctx->r17) = ctx->r2;
    // 0x8005E8C8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8005E8CC: jal         0x80004AAC
    // 0x8005E8D0: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    func_80004AAC(rdram, ctx);
        goto after_5;
    // 0x8005E8D0: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    after_5:
    // 0x8005E8D4: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x8005E8D8: addu        $s2, $v0, $zero
    ctx->r18 = ADD32(ctx->r2, 0);
    // 0x8005E8DC: addu        $a2, $s2, $zero
    ctx->r6 = ADD32(ctx->r18, 0);
    // 0x8005E8E0: addu        $a3, $a1, $zero
    ctx->r7 = ADD32(ctx->r5, 0);
    // 0x8005E8E4: lw          $a0, -0x76E0($s0)
    ctx->r4 = MEM_W(ctx->r16, -0X76E0);
    // 0x8005E8E8: lw          $v1, -0x68C0($s1)
    ctx->r3 = MEM_W(ctx->r17, -0X68C0);
    // 0x8005E8EC: addiu       $v0, $zero, 0x400
    ctx->r2 = ADD32(0, 0X400);
    // 0x8005E8F0: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // 0x8005E8F4: jal         0x80004E70
    // 0x8005E8F8: sw          $v1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r3;
    func_80004E70(rdram, ctx);
        goto after_6;
    // 0x8005E8F8: sw          $v1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r3;
    after_6:
    // 0x8005E8FC: lw          $a0, -0x76E0($s0)
    ctx->r4 = MEM_W(ctx->r16, -0X76E0);
    // 0x8005E900: jal         0x80004C70
    // 0x8005E904: addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    func_80004C70(rdram, ctx);
        goto after_7;
    // 0x8005E904: addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    after_7:
    // 0x8005E908: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x8005E90C: addiu       $v0, $v0, -0x68CC
    ctx->r2 = ADD32(ctx->r2, -0X68CC);
    // 0x8005E910: addu        $v0, $v0, $s3
    ctx->r2 = ADD32(ctx->r2, ctx->r19);
L_8005E914:
    // 0x8005E914: sb          $s3, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r19;
    // 0x8005E918: addiu       $s3, $s3, -0x1
    ctx->r19 = ADD32(ctx->r19, -0X1);
    // 0x8005E91C: bgez        $s3, L_8005E914
    if (SIGNED(ctx->r19) >= 0) {
        // 0x8005E920: addiu       $v0, $v0, -0x1
        ctx->r2 = ADD32(ctx->r2, -0X1);
            goto L_8005E914;
    }
    // 0x8005E920: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x8005E924: addiu       $s3, $zero, 0x4
    ctx->r19 = ADD32(0, 0X4);
    // 0x8005E928: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x8005E92C: jal         0x80060660
    // 0x8005E930: sb          $s3, -0x68D0($v0)
    MEM_B(-0X68D0, ctx->r2) = ctx->r19;
    func_80060660(rdram, ctx);
        goto after_8;
    // 0x8005E930: sb          $s3, -0x68D0($v0)
    MEM_B(-0X68D0, ctx->r2) = ctx->r19;
    after_8:
    // 0x8005E934: lui         $a0, 0x8004
    ctx->r4 = S32(0X8004 << 16);
    // 0x8005E938: jal         0x8006488C
    // 0x8005E93C: addiu       $a0, $a0, -0x4E70
    ctx->r4 = ADD32(ctx->r4, -0X4E70);
    load_asset(rdram, ctx);
        goto after_9;
    // 0x8005E93C: addiu       $a0, $a0, -0x4E70
    ctx->r4 = ADD32(ctx->r4, -0X4E70);
    after_9:
    // 0x8005E940: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8005E944: lwc1        $f0, -0x4E64($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X4E64);
    // 0x8005E948: lw          $ra, 0x28($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X28);
    // 0x8005E94C: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x8005E950: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8005E954: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8005E958: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8005E95C: lui         $v1, 0x8014
    ctx->r3 = S32(0X8014 << 16);
    // 0x8005E960: sw          $v0, -0x69E4($v1)
    MEM_W(-0X69E4, ctx->r3) = ctx->r2;
    // 0x8005E964: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x8005E968: sb          $zero, -0x68C6($v0)
    MEM_B(-0X68C6, ctx->r2) = 0;
    // 0x8005E96C: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x8005E970: swc1        $f0, -0x68C4($v0)
    MEM_W(-0X68C4, ctx->r2) = ctx->f0.u32l;
    // 0x8005E974: jr          $ra
    // 0x8005E978: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x8005E978: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_8005E97C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005E97C: mtc1        $a1, $f2
    ctx->f2.u32l = ctx->r5;
    // 0x8005E980: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x8005E984: sw          $s4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r20;
    // 0x8005E988: addu        $s4, $a0, $zero
    ctx->r20 = ADD32(ctx->r4, 0);
    // 0x8005E98C: sw          $ra, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r31;
    // 0x8005E990: sw          $s5, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r21;
    // 0x8005E994: sw          $s3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r19;
    // 0x8005E998: sw          $s2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r18;
    // 0x8005E99C: sw          $s1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r17;
    // 0x8005E9A0: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x8005E9A4: sdc1        $f20, 0x48($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X48, ctx->r29);
    // 0x8005E9A8: lwc1        $f0, 0x24($s4)
    ctx->f0.u32l = MEM_W(ctx->r20, 0X24);
    // 0x8005E9AC: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x8005E9B0: lw          $s5, 0x60($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X60);
    // 0x8005E9B4: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    // 0x8005E9B8: lwc1        $f0, 0x28($s4)
    ctx->f0.u32l = MEM_W(ctx->r20, 0X28);
    // 0x8005E9BC: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x8005E9C0: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    // 0x8005E9C4: lwc1        $f0, 0x2C($s4)
    ctx->f0.u32l = MEM_W(ctx->r20, 0X2C);
    // 0x8005E9C8: ori         $s2, $zero, 0xFFFF
    ctx->r18 = 0 | 0XFFFF;
    // 0x8005E9CC: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x8005E9D0: andi        $a0, $a3, 0xFFFF
    ctx->r4 = ctx->r7 & 0XFFFF;
    // 0x8005E9D4: addiu       $a1, $sp, 0x10
    ctx->r5 = ADD32(ctx->r29, 0X10);
    // 0x8005E9D8: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8005E9DC: lwc1        $f20, -0x4E60($at)
    ctx->f20.u32l = MEM_W(ctx->r1, -0X4E60);
    // 0x8005E9E0: addu        $s1, $a2, $zero
    ctx->r17 = ADD32(ctx->r6, 0);
    // 0x8005E9E4: jal         0x8003FC28
    // 0x8005E9E8: swc1        $f0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f0.u32l;
    func_8003FC28(rdram, ctx);
        goto after_0;
    // 0x8005E9E8: swc1        $f0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f0.u32l;
    after_0:
    // 0x8005E9EC: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    // 0x8005E9F0: andi        $v1, $s0, 0xFFFF
    ctx->r3 = ctx->r16 & 0XFFFF;
    // 0x8005E9F4: ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
    // 0x8005E9F8: beq         $v1, $v0, L_8005EA70
    if (ctx->r3 == ctx->r2) {
        // 0x8005E9FC: andi        $s1, $s1, 0xFFFF
        ctx->r17 = ctx->r17 & 0XFFFF;
            goto L_8005EA70;
    }
    // 0x8005E9FC: andi        $s1, $s1, 0xFFFF
    ctx->r17 = ctx->r17 & 0XFFFF;
    // 0x8005EA00: addu        $s3, $v0, $zero
    ctx->r19 = ADD32(ctx->r2, 0);
L_8005EA04:
    // 0x8005EA04: beq         $s1, $s3, L_8005EA14
    if (ctx->r17 == ctx->r19) {
        // 0x8005EA08: andi        $v0, $s0, 0xFFFF
        ctx->r2 = ctx->r16 & 0XFFFF;
            goto L_8005EA14;
    }
    // 0x8005EA08: andi        $v0, $s0, 0xFFFF
    ctx->r2 = ctx->r16 & 0XFFFF;
    // 0x8005EA0C: beq         $s1, $v0, L_8005EA58
    if (ctx->r17 == ctx->r2) {
        // 0x8005EA10: nop
    
            goto L_8005EA58;
    }
    // 0x8005EA10: nop

L_8005EA14:
    // 0x8005EA14: jal         0x8004013C
    // 0x8005EA18: andi        $a0, $s0, 0xFFFF
    ctx->r4 = ctx->r16 & 0XFFFF;
    func_8004013C(rdram, ctx);
        goto after_1;
    // 0x8005EA18: andi        $a0, $s0, 0xFFFF
    ctx->r4 = ctx->r16 & 0XFFFF;
    after_1:
    // 0x8005EA1C: lw          $a0, 0xC($v0)
    ctx->r4 = MEM_W(ctx->r2, 0XC);
    // 0x8005EA20: beq         $a0, $zero, L_8005EA58
    if (ctx->r4 == 0) {
        // 0x8005EA24: addu        $a1, $s4, $zero
        ctx->r5 = ADD32(ctx->r20, 0);
            goto L_8005EA58;
    }
    // 0x8005EA24: addu        $a1, $s4, $zero
    ctx->r5 = ADD32(ctx->r20, 0);
    // 0x8005EA28: addiu       $a2, $sp, 0x18
    ctx->r6 = ADD32(ctx->r29, 0X18);
    // 0x8005EA2C: jal         0x8006A944
    // 0x8005EA30: addu        $a3, $s5, $zero
    ctx->r7 = ADD32(ctx->r21, 0);
    func_8006A944(rdram, ctx);
        goto after_2;
    // 0x8005EA30: addu        $a3, $s5, $zero
    ctx->r7 = ADD32(ctx->r21, 0);
    after_2:
    // 0x8005EA34: beq         $v0, $zero, L_8005EA58
    if (ctx->r2 == 0) {
        // 0x8005EA38: nop
    
            goto L_8005EA58;
    }
    // 0x8005EA38: nop

    // 0x8005EA3C: lwc1        $f0, 0x18($s5)
    ctx->f0.u32l = MEM_W(ctx->r21, 0X18);
    // 0x8005EA40: c.lt.s      $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f0.fl < ctx->f20.fl;
    // 0x8005EA44: nop

    // 0x8005EA48: bc1f        L_8005EA58
    if (!c1cs) {
        // 0x8005EA4C: nop
    
            goto L_8005EA58;
    }
    // 0x8005EA4C: nop

    // 0x8005EA50: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x8005EA54: addu        $s2, $s0, $zero
    ctx->r18 = ADD32(ctx->r16, 0);
L_8005EA58:
    // 0x8005EA58: jal         0x8003EEF4
    // 0x8005EA5C: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    func_8003EEF4(rdram, ctx);
        goto after_3;
    // 0x8005EA5C: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    after_3:
    // 0x8005EA60: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    // 0x8005EA64: andi        $v0, $s0, 0xFFFF
    ctx->r2 = ctx->r16 & 0XFFFF;
    // 0x8005EA68: bne         $v0, $s3, L_8005EA04
    if (ctx->r2 != ctx->r19) {
        // 0x8005EA6C: nop
    
            goto L_8005EA04;
    }
    // 0x8005EA6C: nop

L_8005EA70:
    // 0x8005EA70: andi        $v0, $s2, 0xFFFF
    ctx->r2 = ctx->r18 & 0XFFFF;
    // 0x8005EA74: lw          $ra, 0x40($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X40);
    // 0x8005EA78: lw          $s5, 0x3C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X3C);
    // 0x8005EA7C: lw          $s4, 0x38($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X38);
    // 0x8005EA80: lw          $s3, 0x34($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X34);
    // 0x8005EA84: lw          $s2, 0x30($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X30);
    // 0x8005EA88: lw          $s1, 0x2C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X2C);
    // 0x8005EA8C: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x8005EA90: ldc1        $f20, 0x48($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X48);
    // 0x8005EA94: jr          $ra
    // 0x8005EA98: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x8005EA98: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}
RECOMP_FUNC void func_8005EA9C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005EA9C: mtc1        $a2, $f2
    ctx->f2.u32l = ctx->r6;
    // 0x8005EAA0: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x8005EAA4: sw          $s3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r19;
    // 0x8005EAA8: addu        $s3, $a0, $zero
    ctx->r19 = ADD32(ctx->r4, 0);
    // 0x8005EAAC: sw          $ra, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r31;
    // 0x8005EAB0: sw          $s5, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r21;
    // 0x8005EAB4: sw          $s4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r20;
    // 0x8005EAB8: sw          $s2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r18;
    // 0x8005EABC: sw          $s1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r17;
    // 0x8005EAC0: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x8005EAC4: lwc1        $f0, 0x24($s3)
    ctx->f0.u32l = MEM_W(ctx->r19, 0X24);
    // 0x8005EAC8: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x8005EACC: lw          $s5, 0x5C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X5C);
    // 0x8005EAD0: lhu         $a0, 0x5A($sp)
    ctx->r4 = MEM_HU(ctx->r29, 0X5A);
    // 0x8005EAD4: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    // 0x8005EAD8: lwc1        $f0, 0x28($s3)
    ctx->f0.u32l = MEM_W(ctx->r19, 0X28);
    // 0x8005EADC: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x8005EAE0: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    // 0x8005EAE4: lwc1        $f0, 0x2C($s3)
    ctx->f0.u32l = MEM_W(ctx->r19, 0X2C);
    // 0x8005EAE8: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x8005EAEC: addu        $s1, $a1, $zero
    ctx->r17 = ADD32(ctx->r5, 0);
    // 0x8005EAF0: addiu       $a1, $sp, 0x10
    ctx->r5 = ADD32(ctx->r29, 0X10);
    // 0x8005EAF4: addu        $s0, $a3, $zero
    ctx->r16 = ADD32(ctx->r7, 0);
    // 0x8005EAF8: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    // 0x8005EAFC: jal         0x8003FC28
    // 0x8005EB00: swc1        $f0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f0.u32l;
    func_8003FC28(rdram, ctx);
        goto after_0;
    // 0x8005EB00: swc1        $f0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f0.u32l;
    after_0:
    // 0x8005EB04: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // 0x8005EB08: andi        $v1, $a0, 0xFFFF
    ctx->r3 = ctx->r4 & 0XFFFF;
    // 0x8005EB0C: ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
    // 0x8005EB10: beq         $v1, $v0, L_8005EB80
    if (ctx->r3 == ctx->r2) {
        // 0x8005EB14: andi        $s4, $s1, 0xFFFF
        ctx->r20 = ctx->r17 & 0XFFFF;
            goto L_8005EB80;
    }
    // 0x8005EB14: andi        $s4, $s1, 0xFFFF
    ctx->r20 = ctx->r17 & 0XFFFF;
    // 0x8005EB18: andi        $s1, $s0, 0xFFFF
    ctx->r17 = ctx->r16 & 0XFFFF;
    // 0x8005EB1C: addu        $s2, $v0, $zero
    ctx->r18 = ADD32(ctx->r2, 0);
    // 0x8005EB20: andi        $s0, $a0, 0xFFFF
    ctx->r16 = ctx->r4 & 0XFFFF;
L_8005EB24:
    // 0x8005EB24: beq         $s0, $s4, L_8005EB64
    if (ctx->r16 == ctx->r20) {
        // 0x8005EB28: nop
    
            goto L_8005EB64;
    }
    // 0x8005EB28: nop

    // 0x8005EB2C: beq         $s1, $s2, L_8005EB3C
    if (ctx->r17 == ctx->r18) {
        // 0x8005EB30: nop
    
            goto L_8005EB3C;
    }
    // 0x8005EB30: nop

    // 0x8005EB34: beq         $s1, $s0, L_8005EB64
    if (ctx->r17 == ctx->r16) {
        // 0x8005EB38: nop
    
            goto L_8005EB64;
    }
    // 0x8005EB38: nop

L_8005EB3C:
    // 0x8005EB3C: jal         0x8004013C
    // 0x8005EB40: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_8004013C(rdram, ctx);
        goto after_1;
    // 0x8005EB40: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_1:
    // 0x8005EB44: lw          $a0, 0xC($v0)
    ctx->r4 = MEM_W(ctx->r2, 0XC);
    // 0x8005EB48: beq         $a0, $zero, L_8005EB64
    if (ctx->r4 == 0) {
        // 0x8005EB4C: addu        $a1, $s3, $zero
        ctx->r5 = ADD32(ctx->r19, 0);
            goto L_8005EB64;
    }
    // 0x8005EB4C: addu        $a1, $s3, $zero
    ctx->r5 = ADD32(ctx->r19, 0);
    // 0x8005EB50: addiu       $a2, $sp, 0x18
    ctx->r6 = ADD32(ctx->r29, 0X18);
    // 0x8005EB54: jal         0x8006A944
    // 0x8005EB58: addu        $a3, $s5, $zero
    ctx->r7 = ADD32(ctx->r21, 0);
    func_8006A944(rdram, ctx);
        goto after_2;
    // 0x8005EB58: addu        $a3, $s5, $zero
    ctx->r7 = ADD32(ctx->r21, 0);
    after_2:
    // 0x8005EB5C: bne         $v0, $zero, L_8005EB80
    if (ctx->r2 != 0) {
        // 0x8005EB60: addu        $v0, $s0, $zero
        ctx->r2 = ADD32(ctx->r16, 0);
            goto L_8005EB80;
    }
    // 0x8005EB60: addu        $v0, $s0, $zero
    ctx->r2 = ADD32(ctx->r16, 0);
L_8005EB64:
    // 0x8005EB64: jal         0x8003EEF4
    // 0x8005EB68: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    func_8003EEF4(rdram, ctx);
        goto after_3;
    // 0x8005EB68: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    after_3:
    // 0x8005EB6C: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // 0x8005EB70: andi        $v0, $a0, 0xFFFF
    ctx->r2 = ctx->r4 & 0XFFFF;
    // 0x8005EB74: bne         $v0, $s2, L_8005EB24
    if (ctx->r2 != ctx->r18) {
        // 0x8005EB78: andi        $s0, $a0, 0xFFFF
        ctx->r16 = ctx->r4 & 0XFFFF;
            goto L_8005EB24;
    }
    // 0x8005EB78: andi        $s0, $a0, 0xFFFF
    ctx->r16 = ctx->r4 & 0XFFFF;
    // 0x8005EB7C: ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
L_8005EB80:
    // 0x8005EB80: lw          $ra, 0x40($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X40);
    // 0x8005EB84: lw          $s5, 0x3C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X3C);
    // 0x8005EB88: lw          $s4, 0x38($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X38);
    // 0x8005EB8C: lw          $s3, 0x34($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X34);
    // 0x8005EB90: lw          $s2, 0x30($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X30);
    // 0x8005EB94: lw          $s1, 0x2C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X2C);
    // 0x8005EB98: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x8005EB9C: jr          $ra
    // 0x8005EBA0: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x8005EBA0: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void func_8005EBA4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005EBA4: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x8005EBA8: lw          $a0, -0x69E4($v0)
    ctx->r4 = MEM_W(ctx->r2, -0X69E4);
    // 0x8005EBAC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8005EBB0: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x8005EBB4: jal         0x80001C98
    // 0x8005EBB8: nop

    rs_free(rdram, ctx);
        goto after_0;
    // 0x8005EBB8: nop

    after_0:
    // 0x8005EBBC: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x8005EBC0: lw          $a0, -0x68C0($v0)
    ctx->r4 = MEM_W(ctx->r2, -0X68C0);
    // 0x8005EBC4: jal         0x80001C98
    // 0x8005EBC8: nop

    rs_free(rdram, ctx);
        goto after_1;
    // 0x8005EBC8: nop

    after_1:
    // 0x8005EBCC: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x8005EBD0: jr          $ra
    // 0x8005EBD4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8005EBD4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_8005EBD8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005EBD8: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8005EBDC: sw          $ra, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r31;
    // 0x8005EBE0: lwc1        $f0, 0x0($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X0);
    // 0x8005EBE4: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8005EBE8: lwc1        $f2, -0x4E5C($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X4E5C);
    // 0x8005EBEC: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x8005EBF0: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    // 0x8005EBF4: lwc1        $f0, 0x4($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X4);
    // 0x8005EBF8: addiu       $a1, $sp, 0x10
    ctx->r5 = ADD32(ctx->r29, 0X10);
    // 0x8005EBFC: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x8005EC00: lw          $v0, -0x68C0($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X68C0);
    // 0x8005EC04: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x8005EC08: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    // 0x8005EC0C: lwc1        $f2, 0x8($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X8);
    // 0x8005EC10: addiu       $a3, $zero, 0xF
    ctx->r7 = ADD32(0, 0XF);
    // 0x8005EC14: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x8005EC18: addiu       $v0, $zero, 0x10
    ctx->r2 = ADD32(0, 0X10);
    // 0x8005EC1C: sb          $v0, 0x29($sp)
    MEM_B(0X29, ctx->r29) = ctx->r2;
    // 0x8005EC20: addiu       $v0, $zero, 0x300
    ctx->r2 = ADD32(0, 0X300);
    // 0x8005EC24: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8005EC28: lwc1        $f0, -0x4E58($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X4E58);
    // 0x8005EC2C: lui         $a0, 0x8005
    ctx->r4 = S32(0X8005 << 16);
    // 0x8005EC30: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    // 0x8005EC34: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8005EC38: lwc1        $f0, -0x4E54($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X4E54);
    // 0x8005EC3C: addiu       $a0, $a0, -0x3938
    ctx->r4 = ADD32(ctx->r4, -0X3938);
    // 0x8005EC40: sb          $zero, 0x28($sp)
    MEM_B(0X28, ctx->r29) = 0;
    // 0x8005EC44: sh          $v0, 0x20($sp)
    MEM_H(0X20, ctx->r29) = ctx->r2;
    // 0x8005EC48: swc1        $f2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f2.u32l;
    // 0x8005EC4C: jal         0x8003FFEC
    // 0x8005EC50: swc1        $f0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f0.u32l;
    func_8003FFEC(rdram, ctx);
        goto after_0;
    // 0x8005EC50: swc1        $f0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f0.u32l;
    after_0:
    // 0x8005EC54: lw          $ra, 0x30($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X30);
    // 0x8005EC58: jr          $ra
    // 0x8005EC5C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x8005EC5C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_8005EC60(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005EC60: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8005EC64: sw          $ra, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r31;
    // 0x8005EC68: lwc1        $f0, 0x0($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X0);
    // 0x8005EC6C: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8005EC70: lwc1        $f2, -0x4E50($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X4E50);
    // 0x8005EC74: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    // 0x8005EC78: lwc1        $f0, 0x4($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X4);
    // 0x8005EC7C: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x8005EC80: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x8005EC84: lw          $v0, -0x68C0($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X68C0);
    // 0x8005EC88: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x8005EC8C: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    // 0x8005EC90: lwc1        $f2, 0x8($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X8);
    // 0x8005EC94: addiu       $a3, $zero, 0xF
    ctx->r7 = ADD32(0, 0XF);
    // 0x8005EC98: sb          $a1, 0x28($sp)
    MEM_B(0X28, ctx->r29) = ctx->r5;
    // 0x8005EC9C: addiu       $a1, $a1, 0x10
    ctx->r5 = ADD32(ctx->r5, 0X10);
    // 0x8005ECA0: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x8005ECA4: addiu       $v0, $zero, 0x300
    ctx->r2 = ADD32(0, 0X300);
    // 0x8005ECA8: lui         $a0, 0x8005
    ctx->r4 = S32(0X8005 << 16);
    // 0x8005ECAC: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8005ECB0: lwc1        $f0, -0x4E4C($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X4E4C);
    // 0x8005ECB4: addiu       $a0, $a0, -0x3938
    ctx->r4 = ADD32(ctx->r4, -0X3938);
    // 0x8005ECB8: sb          $a1, 0x29($sp)
    MEM_B(0X29, ctx->r29) = ctx->r5;
    // 0x8005ECBC: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    // 0x8005ECC0: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8005ECC4: lwc1        $f0, -0x4E48($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X4E48);
    // 0x8005ECC8: addiu       $a1, $sp, 0x10
    ctx->r5 = ADD32(ctx->r29, 0X10);
    // 0x8005ECCC: sh          $v0, 0x20($sp)
    MEM_H(0X20, ctx->r29) = ctx->r2;
    // 0x8005ECD0: swc1        $f2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f2.u32l;
    // 0x8005ECD4: jal         0x8003FFEC
    // 0x8005ECD8: swc1        $f0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f0.u32l;
    func_8003FFEC(rdram, ctx);
        goto after_0;
    // 0x8005ECD8: swc1        $f0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f0.u32l;
    after_0:
    // 0x8005ECDC: lw          $ra, 0x30($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X30);
    // 0x8005ECE0: jr          $ra
    // 0x8005ECE4: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x8005ECE4: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_8005ECE8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005ECE8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8005ECEC: lui         $a0, 0x8004
    ctx->r4 = S32(0X8004 << 16);
    // 0x8005ECF0: addiu       $a0, $a0, -0x4E98
    ctx->r4 = ADD32(ctx->r4, -0X4E98);
    // 0x8005ECF4: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x8005ECF8: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x8005ECFC: jal         0x800554D8
    // 0x8005ED00: addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    func_800554D8(rdram, ctx);
        goto after_0;
    // 0x8005ED00: addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    after_0:
    // 0x8005ED04: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x8005ED08: lui         $v1, 0x8014
    ctx->r3 = S32(0X8014 << 16);
    // 0x8005ED0C: sh          $v0, -0x68C8($v1)
    MEM_H(-0X68C8, ctx->r3) = ctx->r2;
    // 0x8005ED10: jr          $ra
    // 0x8005ED14: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8005ED14: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_8005ED18(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005ED18: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8005ED1C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8005ED20: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x8005ED24: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8005ED28: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x8005ED2C: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x8005ED30: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8005ED34: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8005ED38: lwc1        $f4, 0x10($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X10);
    // 0x8005ED3C: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8005ED40: lwc1        $f2, -0x4E44($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X4E44);
    // 0x8005ED44: mul.s       $f4, $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f4.fl, ctx->f2.fl);
    // 0x8005ED48: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x8005ED4C: swc1        $f4, -0x6A60($v0)
    MEM_W(-0X6A60, ctx->r2) = ctx->f4.u32l;
    // 0x8005ED50: lwc1        $f0, 0x14($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X14);
    // 0x8005ED54: mul.s       $f6, $f0, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x8005ED58: addiu       $v0, $v0, -0x6A60
    ctx->r2 = ADD32(ctx->r2, -0X6A60);
    // 0x8005ED5C: swc1        $f6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f6.u32l;
    // 0x8005ED60: lwc1        $f0, 0x18($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X18);
    // 0x8005ED64: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x8005ED68: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x8005ED6C: addu        $s3, $a2, $zero
    ctx->r19 = ADD32(ctx->r6, 0);
    // 0x8005ED70: c.eq.s      $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f4.fl == ctx->f2.fl;
    // 0x8005ED74: nop

    // 0x8005ED78: bc1f        L_8005EDC4
    if (!c1cs) {
        // 0x8005ED7C: swc1        $f0, 0x8($v0)
        MEM_W(0X8, ctx->r2) = ctx->f0.u32l;
            goto L_8005EDC4;
    }
    // 0x8005ED7C: swc1        $f0, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f0.u32l;
    // 0x8005ED80: c.eq.s      $f6, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f6.fl == ctx->f2.fl;
    // 0x8005ED84: nop

    // 0x8005ED88: bc1fl       L_8005EDC8
    if (!c1cs) {
        // 0x8005ED8C: andi        $a0, $a3, 0xFFFF
        ctx->r4 = ctx->r7 & 0XFFFF;
            goto L_8005EDC8;
    }
    goto skip_0;
    // 0x8005ED8C: andi        $a0, $a3, 0xFFFF
    ctx->r4 = ctx->r7 & 0XFFFF;
    skip_0:
    // 0x8005ED90: c.eq.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl == ctx->f2.fl;
    // 0x8005ED94: nop

    // 0x8005ED98: bc1f        L_8005EDC4
    if (!c1cs) {
        // 0x8005ED9C: addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
            goto L_8005EDC4;
    }
    // 0x8005ED9C: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // 0x8005EDA0: j           L_8005EE44
    // 0x8005EDA4: nop

        goto L_8005EE44;
    // 0x8005EDA4: nop

L_8005EDA8:
    // 0x8005EDA8: lwc1        $f0, 0xC($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0XC);
    // 0x8005EDAC: swc1        $f0, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->f0.u32l;
    // 0x8005EDB0: lwc1        $f0, 0x10($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X10);
    // 0x8005EDB4: swc1        $f0, 0x4($s3)
    MEM_W(0X4, ctx->r19) = ctx->f0.u32l;
    // 0x8005EDB8: lwc1        $f0, 0x14($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X14);
    // 0x8005EDBC: j           L_8005EE44
    // 0x8005EDC0: swc1        $f0, 0x8($s3)
    MEM_W(0X8, ctx->r19) = ctx->f0.u32l;
        goto L_8005EE44;
    // 0x8005EDC0: swc1        $f0, 0x8($s3)
    MEM_W(0X8, ctx->r19) = ctx->f0.u32l;
L_8005EDC4:
    // 0x8005EDC4: andi        $a0, $a3, 0xFFFF
    ctx->r4 = ctx->r7 & 0XFFFF;
L_8005EDC8:
    // 0x8005EDC8: jal         0x8003FC28
    // 0x8005EDCC: addiu       $a1, $sp, 0x10
    ctx->r5 = ADD32(ctx->r29, 0X10);
    func_8003FC28(rdram, ctx);
        goto after_0;
    // 0x8005EDCC: addiu       $a1, $sp, 0x10
    ctx->r5 = ADD32(ctx->r29, 0X10);
    after_0:
    // 0x8005EDD0: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // 0x8005EDD4: andi        $v1, $a0, 0xFFFF
    ctx->r3 = ctx->r4 & 0XFFFF;
    // 0x8005EDD8: ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
    // 0x8005EDDC: beq         $v1, $v0, L_8005EE40
    if (ctx->r3 == ctx->r2) {
        // 0x8005EDE0: lui         $s4, 0x8014
        ctx->r20 = S32(0X8014 << 16);
            goto L_8005EE40;
    }
    // 0x8005EDE0: lui         $s4, 0x8014
    ctx->r20 = S32(0X8014 << 16);
    // 0x8005EDE4: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x8005EDE8: addiu       $s1, $v0, -0x6A50
    ctx->r17 = ADD32(ctx->r2, -0X6A50);
    // 0x8005EDEC: ori         $s2, $zero, 0xFFFF
    ctx->r18 = 0 | 0XFFFF;
L_8005EDF0:
    // 0x8005EDF0: lhu         $v0, 0xB6($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0XB6);
    // 0x8005EDF4: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    // 0x8005EDF8: beq         $v0, $a0, L_8005EE28
    if (ctx->r2 == ctx->r4) {
        // 0x8005EDFC: nop
    
            goto L_8005EE28;
    }
    // 0x8005EDFC: nop

    // 0x8005EE00: jal         0x8004013C
    // 0x8005EE04: nop

    func_8004013C(rdram, ctx);
        goto after_1;
    // 0x8005EE04: nop

    after_1:
    // 0x8005EE08: lw          $a0, 0xC($v0)
    ctx->r4 = MEM_W(ctx->r2, 0XC);
    // 0x8005EE0C: beq         $a0, $zero, L_8005EE28
    if (ctx->r4 == 0) {
        // 0x8005EE10: addiu       $a1, $s0, 0x4
        ctx->r5 = ADD32(ctx->r16, 0X4);
            goto L_8005EE28;
    }
    // 0x8005EE10: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x8005EE14: addiu       $a2, $s4, -0x6A60
    ctx->r6 = ADD32(ctx->r20, -0X6A60);
    // 0x8005EE18: jal         0x8006A944
    // 0x8005EE1C: addu        $a3, $s1, $zero
    ctx->r7 = ADD32(ctx->r17, 0);
    func_8006A944(rdram, ctx);
        goto after_2;
    // 0x8005EE1C: addu        $a3, $s1, $zero
    ctx->r7 = ADD32(ctx->r17, 0);
    after_2:
    // 0x8005EE20: bne         $v0, $zero, L_8005EDA8
    if (ctx->r2 != 0) {
        // 0x8005EE24: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_8005EDA8;
    }
    // 0x8005EE24: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8005EE28:
    // 0x8005EE28: jal         0x8003EEF4
    // 0x8005EE2C: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    func_8003EEF4(rdram, ctx);
        goto after_3;
    // 0x8005EE2C: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    after_3:
    // 0x8005EE30: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // 0x8005EE34: andi        $v0, $a0, 0xFFFF
    ctx->r2 = ctx->r4 & 0XFFFF;
    // 0x8005EE38: bne         $v0, $s2, L_8005EDF0
    if (ctx->r2 != ctx->r18) {
        // 0x8005EE3C: nop
    
            goto L_8005EDF0;
    }
    // 0x8005EE3C: nop

L_8005EE40:
    // 0x8005EE40: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_8005EE44:
    // 0x8005EE44: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x8005EE48: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x8005EE4C: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x8005EE50: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8005EE54: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8005EE58: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8005EE5C: jr          $ra
    // 0x8005EE60: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x8005EE60: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void fake_func_8005EE64(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
;}
RECOMP_FUNC void func_8005EE70(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005EE70: addiu       $sp, $sp, -0xE8
    ctx->r29 = ADD32(ctx->r29, -0XE8);
    // 0x8005EE74: sdc1        $f24, 0xE0($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0XE0, ctx->r29);
    // 0x8005EE78: mtc1        $a2, $f24
    ctx->f24.u32l = ctx->r6;
    // 0x8005EE7C: sw          $s2, 0xC0($sp)
    MEM_W(0XC0, ctx->r29) = ctx->r18;
    // 0x8005EE80: addu        $s2, $a0, $zero
    ctx->r18 = ADD32(ctx->r4, 0);
    // 0x8005EE84: sw          $ra, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->r31;
    // 0x8005EE88: sw          $s3, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->r19;
    // 0x8005EE8C: sw          $s1, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->r17;
    // 0x8005EE90: sw          $s0, 0xB8($sp)
    MEM_W(0XB8, ctx->r29) = ctx->r16;
    // 0x8005EE94: sdc1        $f22, 0xD8($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0XD8, ctx->r29);
    // 0x8005EE98: sdc1        $f20, 0xD0($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0XD0, ctx->r29);
    // 0x8005EE9C: lwc1        $f0, 0x60($s2)
    ctx->f0.u32l = MEM_W(ctx->r18, 0X60);
    // 0x8005EEA0: sub.s       $f0, $f0, $f24
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f24.fl;
    // 0x8005EEA4: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x8005EEA8: c.le.s      $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f0.fl <= ctx->f20.fl;
    // 0x8005EEAC: nop

    // 0x8005EEB0: bc1f        L_8005F3C8
    if (!c1cs) {
        // 0x8005EEB4: swc1        $f0, 0x60($s2)
        MEM_W(0X60, ctx->r18) = ctx->f0.u32l;
            goto L_8005F3C8;
    }
    // 0x8005EEB4: swc1        $f0, 0x60($s2)
    MEM_W(0X60, ctx->r18) = ctx->f0.u32l;
    // 0x8005EEB8: lwc1        $f0, 0x64($s2)
    ctx->f0.u32l = MEM_W(ctx->r18, 0X64);
    // 0x8005EEBC: lwc1        $f2, 0x4($s2)
    ctx->f2.u32l = MEM_W(ctx->r18, 0X4);
    // 0x8005EEC0: swc1        $f0, 0x60($s2)
    MEM_W(0X60, ctx->r18) = ctx->f0.u32l;
    // 0x8005EEC4: lwc1        $f0, 0x0($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0X0);
    // 0x8005EEC8: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x8005EECC: swc1        $f0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f0.u32l;
    // 0x8005EED0: lwc1        $f0, 0x4($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0X4);
    // 0x8005EED4: lwc1        $f2, 0x8($s2)
    ctx->f2.u32l = MEM_W(ctx->r18, 0X8);
    // 0x8005EED8: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x8005EEDC: swc1        $f0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f0.u32l;
    // 0x8005EEE0: lwc1        $f0, 0x8($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0X8);
    // 0x8005EEE4: lwc1        $f2, 0xC($s2)
    ctx->f2.u32l = MEM_W(ctx->r18, 0XC);
    // 0x8005EEE8: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x8005EEEC: swc1        $f0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f0.u32l;
    // 0x8005EEF0: lbu         $v0, 0x7A($s2)
    ctx->r2 = MEM_BU(ctx->r18, 0X7A);
    // 0x8005EEF4: beq         $v0, $zero, L_8005F000
    if (ctx->r2 == 0) {
        // 0x8005EEF8: nop
    
            goto L_8005F000;
    }
    // 0x8005EEF8: nop

    // 0x8005EEFC: jal         0x8001CF2C
    // 0x8005EF00: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    func_8001CF2C(rdram, ctx);
        goto after_0;
    // 0x8005EF00: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    after_0:
    // 0x8005EF04: lwc1        $f2, 0x74($s2)
    ctx->f2.u32l = MEM_W(ctx->r18, 0X74);
    // 0x8005EF08: sub.s       $f4, $f2, $f24
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f4.fl = ctx->f2.fl - ctx->f24.fl;
    // 0x8005EF0C: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8005EF10: lwc1        $f2, -0x4E40($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X4E40);
    // 0x8005EF14: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
    // 0x8005EF18: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x8005EF1C: nop

    // 0x8005EF20: bc1f        L_8005EFA4
    if (!c1cs) {
        // 0x8005EF24: swc1        $f4, 0x74($s2)
        MEM_W(0X74, ctx->r18) = ctx->f4.u32l;
            goto L_8005EFA4;
    }
    // 0x8005EF24: swc1        $f4, 0x74($s2)
    MEM_W(0X74, ctx->r18) = ctx->f4.u32l;
    // 0x8005EF28: c.le.s      $f4, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f4.fl <= ctx->f20.fl;
    // 0x8005EF2C: nop

    // 0x8005EF30: bc1f        L_8005F000
    if (!c1cs) {
        // 0x8005EF34: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_8005F000;
    }
    // 0x8005EF34: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8005EF38: lbu         $v1, 0x7B($s2)
    ctx->r3 = MEM_BU(ctx->r18, 0X7B);
    // 0x8005EF3C: bne         $v1, $v0, L_8005EF54
    if (ctx->r3 != ctx->r2) {
        // 0x8005EF40: addu        $a0, $zero, $zero
        ctx->r4 = ADD32(0, 0);
            goto L_8005EF54;
    }
    // 0x8005EF40: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x8005EF44: sb          $zero, 0x7B($s2)
    MEM_B(0X7B, ctx->r18) = 0;
    // 0x8005EF48: jal         0x80098DE0
    // 0x8005EF4C: addiu       $a0, $s2, 0x7C
    ctx->r4 = ADD32(ctx->r18, 0X7C);
    func_80098DE0(rdram, ctx);
        goto after_1;
    // 0x8005EF4C: addiu       $a0, $s2, 0x7C
    ctx->r4 = ADD32(ctx->r18, 0X7C);
    after_1:
    // 0x8005EF50: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
L_8005EF54:
    // 0x8005EF54: addiu       $a1, $s2, 0x4
    ctx->r5 = ADD32(ctx->r18, 0X4);
    // 0x8005EF58: addiu       $a2, $s2, 0x28
    ctx->r6 = ADD32(ctx->r18, 0X28);
    // 0x8005EF5C: addiu       $v0, $zero, 0x40
    ctx->r2 = ADD32(0, 0X40);
    // 0x8005EF60: lui         $a3, 0x41C0
    ctx->r7 = S32(0X41C0 << 16);
    // 0x8005EF64: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8005EF68: lwc1        $f0, -0x4E3C($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X4E3C);
    // 0x8005EF6C: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8005EF70: lwc1        $f2, -0x4E38($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X4E38);
    // 0x8005EF74: div.s       $f0, $f22, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = DIV_S(ctx->f22.fl, ctx->f0.fl);
    // 0x8005EF78: swc1        $f0, 0x74($s2)
    MEM_W(0X74, ctx->r18) = ctx->f0.u32l;
    // 0x8005EF7C: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // 0x8005EF80: addiu       $v0, $zero, 0x7F
    ctx->r2 = ADD32(0, 0X7F);
    // 0x8005EF84: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x8005EF88: addiu       $v0, $zero, 0x28
    ctx->r2 = ADD32(0, 0X28);
    // 0x8005EF8C: swc1        $f2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f2.u32l;
    // 0x8005EF90: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x8005EF94: jal         0x800989D8
    // 0x8005EF98: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    func_800989D8(rdram, ctx);
        goto after_2;
    // 0x8005EF98: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    after_2:
    // 0x8005EF9C: j           L_8005F000
    // 0x8005EFA0: nop

        goto L_8005F000;
    // 0x8005EFA0: nop

L_8005EFA4:
    // 0x8005EFA4: lbu         $v0, 0x7B($s2)
    ctx->r2 = MEM_BU(ctx->r18, 0X7B);
    // 0x8005EFA8: bne         $v0, $zero, L_8005F000
    if (ctx->r2 != 0) {
        // 0x8005EFAC: swc1        $f20, 0x74($s2)
        MEM_W(0X74, ctx->r18) = ctx->f20.u32l;
            goto L_8005F000;
    }
    // 0x8005EFAC: swc1        $f20, 0x74($s2)
    MEM_W(0X74, ctx->r18) = ctx->f20.u32l;
    // 0x8005EFB0: addiu       $a0, $s2, 0x7C
    ctx->r4 = ADD32(ctx->r18, 0X7C);
    // 0x8005EFB4: addiu       $a1, $s2, 0x4
    ctx->r5 = ADD32(ctx->r18, 0X4);
    // 0x8005EFB8: addiu       $a2, $s2, 0x28
    ctx->r6 = ADD32(ctx->r18, 0X28);
    // 0x8005EFBC: lui         $a3, 0x41C0
    ctx->r7 = S32(0X41C0 << 16);
    // 0x8005EFC0: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8005EFC4: lwc1        $f0, -0x4E34($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X4E34);
    // 0x8005EFC8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8005EFCC: sb          $v0, 0x7B($s2)
    MEM_B(0X7B, ctx->r18) = ctx->r2;
    // 0x8005EFD0: addiu       $v0, $zero, 0x7
    ctx->r2 = ADD32(0, 0X7);
    // 0x8005EFD4: sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    // 0x8005EFD8: addiu       $v0, $zero, 0x41
    ctx->r2 = ADD32(0, 0X41);
    // 0x8005EFDC: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // 0x8005EFE0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8005EFE4: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x8005EFE8: addiu       $v0, $zero, 0x7F
    ctx->r2 = ADD32(0, 0X7F);
    // 0x8005EFEC: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x8005EFF0: addiu       $v0, $zero, 0x28
    ctx->r2 = ADD32(0, 0X28);
    // 0x8005EFF4: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x8005EFF8: jal         0x80098BDC
    // 0x8005EFFC: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    func_80098BDC(rdram, ctx);
        goto after_3;
    // 0x8005EFFC: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    after_3:
L_8005F000:
    // 0x8005F000: jal         0x8001CF2C
    // 0x8005F004: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    func_8001CF2C(rdram, ctx);
        goto after_4;
    // 0x8005F004: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    after_4:
    // 0x8005F008: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8005F00C: lwc1        $f2, -0x4E30($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X4E30);
    // 0x8005F010: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x8005F014: nop

    // 0x8005F018: bc1tl       L_8005F020
    if (c1cs) {
        // 0x8005F01C: sb          $zero, 0x53($s2)
        MEM_B(0X53, ctx->r18) = 0;
            goto L_8005F020;
    }
    goto skip_0;
    // 0x8005F01C: sb          $zero, 0x53($s2)
    MEM_B(0X53, ctx->r18) = 0;
    skip_0:
L_8005F020:
    // 0x8005F020: addiu       $s1, $sp, 0x38
    ctx->r17 = ADD32(ctx->r29, 0X38);
    // 0x8005F024: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x8005F028: jal         0x8001CFA0
    // 0x8005F02C: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    func_8001CFA0(rdram, ctx);
        goto after_5;
    // 0x8005F02C: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    after_5:
    // 0x8005F030: addiu       $s0, $sp, 0x48
    ctx->r16 = ADD32(ctx->r29, 0X48);
    // 0x8005F034: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x8005F038: addiu       $s3, $s2, 0x10
    ctx->r19 = ADD32(ctx->r18, 0X10);
    // 0x8005F03C: addu        $a1, $s3, $zero
    ctx->r5 = ADD32(ctx->r19, 0);
    // 0x8005F040: jal         0x80019548
    // 0x8005F044: addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    func_80019548(rdram, ctx);
        goto after_6;
    // 0x8005F044: addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    after_6:
    // 0x8005F048: jal         0x8001CF2C
    // 0x8005F04C: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_8001CF2C(rdram, ctx);
        goto after_7;
    // 0x8005F04C: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_7:
    // 0x8005F050: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8005F054: lwc1        $f2, -0x4E2C($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X4E2C);
    // 0x8005F058: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x8005F05C: nop

    // 0x8005F060: bc1f        L_8005F134
    if (!c1cs) {
        // 0x8005F064: nop
    
            goto L_8005F134;
    }
    // 0x8005F064: nop

    // 0x8005F068: lwc1        $f0, 0x68($s2)
    ctx->f0.u32l = MEM_W(ctx->r18, 0X68);
    // 0x8005F06C: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8005F070: lwc1        $f2, -0x4E28($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X4E28);
    // 0x8005F074: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x8005F078: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x8005F07C: mul.s       $f20, $f0, $f24
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f20.fl = MUL_S(ctx->f0.fl, ctx->f24.fl);
    // 0x8005F080: jal         0x8001CFE8
    // 0x8005F084: addu        $a1, $s3, $zero
    ctx->r5 = ADD32(ctx->r19, 0);
    func_8001CFE8(rdram, ctx);
        goto after_8;
    // 0x8005F084: addu        $a1, $s3, $zero
    ctx->r5 = ADD32(ctx->r19, 0);
    after_8:
    // 0x8005F088: jal         0x8001C5CC
    // 0x8005F08C: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    func_8001C5CC(rdram, ctx);
        goto after_9;
    // 0x8005F08C: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    after_9:
    // 0x8005F090: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8005F094: lwc1        $f2, -0x4E24($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X4E24);
    // 0x8005F098: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x8005F09C: c.lt.s      $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f20.fl < ctx->f0.fl;
    // 0x8005F0A0: nop

    // 0x8005F0A4: bc1fl       L_8005F0B4
    if (!c1cs) {
        // 0x8005F0A8: neg.s       $f2, $f20
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); 
    ctx->f2.fl = -ctx->f20.fl;
            goto L_8005F0B4;
    }
    goto skip_1;
    // 0x8005F0A8: neg.s       $f2, $f20
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); 
    ctx->f2.fl = -ctx->f20.fl;
    skip_1:
    // 0x8005F0AC: j           L_8005F0C4
    // 0x8005F0B0: mov.s       $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    ctx->f0.fl = ctx->f20.fl;
        goto L_8005F0C4;
    // 0x8005F0B0: mov.s       $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    ctx->f0.fl = ctx->f20.fl;
L_8005F0B4:
    // 0x8005F0B4: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x8005F0B8: nop

    // 0x8005F0BC: bc1tl       L_8005F0C4
    if (c1cs) {
        // 0x8005F0C0: mov.s       $f0, $f2
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
            goto L_8005F0C4;
    }
    goto skip_2;
    // 0x8005F0C0: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    skip_2:
L_8005F0C4:
    // 0x8005F0C4: addiu       $s0, $sp, 0x58
    ctx->r16 = ADD32(ctx->r29, 0X58);
    // 0x8005F0C8: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x8005F0CC: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8005F0D0: jal         0x8001D144
    // 0x8005F0D4: addiu       $a1, $sp, 0x48
    ctx->r5 = ADD32(ctx->r29, 0X48);
    func_8001D144(rdram, ctx);
        goto after_10;
    // 0x8005F0D4: addiu       $a1, $sp, 0x48
    ctx->r5 = ADD32(ctx->r29, 0X48);
    after_10:
    // 0x8005F0D8: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x8005F0DC: addiu       $a1, $s2, 0x10
    ctx->r5 = ADD32(ctx->r18, 0X10);
    // 0x8005F0E0: addiu       $s1, $sp, 0x38
    ctx->r17 = ADD32(ctx->r29, 0X38);
    // 0x8005F0E4: jal         0x8001D3C4
    // 0x8005F0E8: addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    func_8001D3C4(rdram, ctx);
        goto after_11;
    // 0x8005F0E8: addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    after_11:
    // 0x8005F0EC: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x8005F0F0: addiu       $a1, $s2, 0x1C
    ctx->r5 = ADD32(ctx->r18, 0X1C);
    // 0x8005F0F4: lw          $t0, 0x38($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X38);
    // 0x8005F0F8: lw          $t1, 0x3C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X3C);
    // 0x8005F0FC: lw          $t2, 0x40($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X40);
    // 0x8005F100: sw          $t0, 0x10($s2)
    MEM_W(0X10, ctx->r18) = ctx->r8;
    // 0x8005F104: sw          $t1, 0x14($s2)
    MEM_W(0X14, ctx->r18) = ctx->r9;
    // 0x8005F108: sw          $t2, 0x18($s2)
    MEM_W(0X18, ctx->r18) = ctx->r10;
    // 0x8005F10C: jal         0x8001D3C4
    // 0x8005F110: addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    func_8001D3C4(rdram, ctx);
        goto after_12;
    // 0x8005F110: addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    after_12:
    // 0x8005F114: lw          $t0, 0x38($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X38);
    // 0x8005F118: lw          $t1, 0x3C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X3C);
    // 0x8005F11C: lw          $t2, 0x40($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X40);
    // 0x8005F120: sw          $t0, 0x1C($s2)
    MEM_W(0X1C, ctx->r18) = ctx->r8;
    // 0x8005F124: sw          $t1, 0x20($s2)
    MEM_W(0X20, ctx->r18) = ctx->r9;
    // 0x8005F128: sw          $t2, 0x24($s2)
    MEM_W(0X24, ctx->r18) = ctx->r10;
    // 0x8005F12C: jal         0x80059F10
    // 0x8005F130: addiu       $a0, $s2, 0x4
    ctx->r4 = ADD32(ctx->r18, 0X4);
    func_80059F10(rdram, ctx);
        goto after_13;
    // 0x8005F130: addiu       $a0, $s2, 0x4
    ctx->r4 = ADD32(ctx->r18, 0X4);
    after_13:
L_8005F134:
    // 0x8005F134: lbu         $v1, 0x53($s2)
    ctx->r3 = MEM_BU(ctx->r18, 0X53);
    // 0x8005F138: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8005F13C: bne         $v1, $v0, L_8005F3C8
    if (ctx->r3 != ctx->r2) {
        // 0x8005F140: nop
    
            goto L_8005F3C8;
    }
    // 0x8005F140: nop

    // 0x8005F144: lwc1        $f8, 0x28($s2)
    ctx->f8.u32l = MEM_W(ctx->r18, 0X28);
    // 0x8005F148: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x8005F14C: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8005F150: lwc1        $f0, -0x4E20($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X4E20);
    // 0x8005F154: lwc1        $f6, 0x4($s2)
    ctx->f6.u32l = MEM_W(ctx->r18, 0X4);
    // 0x8005F158: c.eq.s      $f8, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f8.fl == ctx->f2.fl;
    // 0x8005F15C: mul.s       $f4, $f24, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f24.fl, ctx->f0.fl);
    // 0x8005F160: bc1t        L_8005F190
    if (c1cs) {
        // 0x8005F164: nop
    
            goto L_8005F190;
    }
    // 0x8005F164: nop

    // 0x8005F168: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8005F16C: lwc1        $f0, -0x4E1C($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X4E1C);
    // 0x8005F170: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8005F174: lwc1        $f2, -0x4E18($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X4E18);
    // 0x8005F178: div.s       $f0, $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f8.fl);
    // 0x8005F17C: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x8005F180: nop

    // 0x8005F184: mul.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x8005F188: j           L_8005F198
    // 0x8005F18C: add.s       $f0, $f6, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f6.fl + ctx->f0.fl;
        goto L_8005F198;
    // 0x8005F18C: add.s       $f0, $f6, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f6.fl + ctx->f0.fl;
L_8005F190:
    // 0x8005F190: mul.s       $f0, $f4, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f4.fl, ctx->f2.fl);
    // 0x8005F194: add.s       $f0, $f6, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f6.fl + ctx->f0.fl;
L_8005F198:
    // 0x8005F198: swc1        $f0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f0.u32l;
    // 0x8005F19C: lwc1        $f8, 0x2C($s2)
    ctx->f8.u32l = MEM_W(ctx->r18, 0X2C);
    // 0x8005F1A0: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x8005F1A4: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8005F1A8: lwc1        $f0, -0x4E14($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X4E14);
    // 0x8005F1AC: lwc1        $f6, 0x8($s2)
    ctx->f6.u32l = MEM_W(ctx->r18, 0X8);
    // 0x8005F1B0: c.eq.s      $f8, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f8.fl == ctx->f2.fl;
    // 0x8005F1B4: mul.s       $f4, $f24, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f24.fl, ctx->f0.fl);
    // 0x8005F1B8: bc1t        L_8005F1E8
    if (c1cs) {
        // 0x8005F1BC: nop
    
            goto L_8005F1E8;
    }
    // 0x8005F1BC: nop

    // 0x8005F1C0: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8005F1C4: lwc1        $f0, -0x4E10($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X4E10);
    // 0x8005F1C8: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8005F1CC: lwc1        $f2, -0x4E0C($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X4E0C);
    // 0x8005F1D0: div.s       $f0, $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f8.fl);
    // 0x8005F1D4: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x8005F1D8: nop

    // 0x8005F1DC: mul.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x8005F1E0: j           L_8005F1F0
    // 0x8005F1E4: add.s       $f0, $f6, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f6.fl + ctx->f0.fl;
        goto L_8005F1F0;
    // 0x8005F1E4: add.s       $f0, $f6, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f6.fl + ctx->f0.fl;
L_8005F1E8:
    // 0x8005F1E8: mul.s       $f0, $f4, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f4.fl, ctx->f2.fl);
    // 0x8005F1EC: add.s       $f0, $f6, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f6.fl + ctx->f0.fl;
L_8005F1F0:
    // 0x8005F1F0: swc1        $f0, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->f0.u32l;
    // 0x8005F1F4: lwc1        $f6, 0x30($s2)
    ctx->f6.u32l = MEM_W(ctx->r18, 0X30);
    // 0x8005F1F8: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x8005F1FC: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8005F200: lwc1        $f0, -0x4E08($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X4E08);
    // 0x8005F204: lwc1        $f14, 0xC($s2)
    ctx->f14.u32l = MEM_W(ctx->r18, 0XC);
    // 0x8005F208: c.eq.s      $f6, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f6.fl == ctx->f2.fl;
    // 0x8005F20C: mul.s       $f4, $f24, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f24.fl, ctx->f0.fl);
    // 0x8005F210: bc1t        L_8005F240
    if (c1cs) {
        // 0x8005F214: nop
    
            goto L_8005F240;
    }
    // 0x8005F214: nop

    // 0x8005F218: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8005F21C: lwc1        $f0, -0x4E04($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X4E04);
    // 0x8005F220: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8005F224: lwc1        $f2, -0x4E00($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X4E00);
    // 0x8005F228: div.s       $f0, $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f6.fl);
    // 0x8005F22C: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x8005F230: nop

    // 0x8005F234: mul.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x8005F238: j           L_8005F248
    // 0x8005F23C: add.s       $f14, $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = ctx->f14.fl + ctx->f0.fl;
        goto L_8005F248;
    // 0x8005F23C: add.s       $f14, $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = ctx->f14.fl + ctx->f0.fl;
L_8005F240:
    // 0x8005F240: mul.s       $f0, $f4, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f4.fl, ctx->f2.fl);
    // 0x8005F244: add.s       $f14, $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = ctx->f14.fl + ctx->f0.fl;
L_8005F248:
    // 0x8005F248: lui         $a2, 0x8014
    ctx->r6 = S32(0X8014 << 16);
    // 0x8005F24C: addiu       $a2, $a2, -0x7FA8
    ctx->r6 = ADD32(ctx->r6, -0X7FA8);
    // 0x8005F250: lwc1        $f12, 0x68($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X68);
    // 0x8005F254: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    // 0x8005F258: jal         0x80067D90
    // 0x8005F25C: swc1        $f14, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->f14.u32l;
    func_80067D90(rdram, ctx);
        goto after_14;
    // 0x8005F25C: swc1        $f14, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->f14.u32l;
    after_14:
    // 0x8005F260: lwc1        $f2, 0x8($s2)
    ctx->f2.u32l = MEM_W(ctx->r18, 0X8);
    // 0x8005F264: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x8005F268: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8005F26C: lwc1        $f2, -0x4DFC($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X4DFC);
    // 0x8005F270: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x8005F274: nop

    // 0x8005F278: bc1f        L_8005F3C8
    if (!c1cs) {
        // 0x8005F27C: addiu       $s0, $sp, 0x88
        ctx->r16 = ADD32(ctx->r29, 0X88);
            goto L_8005F3C8;
    }
    // 0x8005F27C: addiu       $s0, $sp, 0x88
    ctx->r16 = ADD32(ctx->r29, 0X88);
    // 0x8005F280: lwc1        $f2, 0x68($s2)
    ctx->f2.u32l = MEM_W(ctx->r18, 0X68);
    // 0x8005F284: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8005F288: lwc1        $f0, -0x4DF8($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X4DF8);
    // 0x8005F28C: lwc1        $f4, 0x10($s2)
    ctx->f4.u32l = MEM_W(ctx->r18, 0X10);
    // 0x8005F290: add.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x8005F294: lwc1        $f0, 0x58($s2)
    ctx->f0.u32l = MEM_W(ctx->r18, 0X58);
    // 0x8005F298: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x8005F29C: sw          $zero, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = 0;
    // 0x8005F2A0: mul.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x8005F2A4: swc1        $f4, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->f4.u32l;
    // 0x8005F2A8: lwc1        $f6, 0x18($s2)
    ctx->f6.u32l = MEM_W(ctx->r18, 0X18);
    // 0x8005F2AC: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8005F2B0: lwc1        $f0, -0x4DF4($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X4DF4);
    // 0x8005F2B4: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8005F2B8: lwc1        $f4, -0x4DF0($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X4DF0);
    // 0x8005F2BC: mul.s       $f0, $f24, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = MUL_S(ctx->f24.fl, ctx->f0.fl);
    // 0x8005F2C0: sw          $zero, 0x98($sp)
    MEM_W(0X98, ctx->r29) = 0;
    // 0x8005F2C4: sw          $zero, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = 0;
    // 0x8005F2C8: swc1        $f4, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->f4.u32l;
    // 0x8005F2CC: mul.s       $f20, $f2, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f20.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x8005F2D0: jal         0x8001CF58
    // 0x8005F2D4: swc1        $f6, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->f6.u32l;
    normalize_vector(rdram, ctx);
        goto after_15;
    // 0x8005F2D4: swc1        $f6, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->f6.u32l;
    after_15:
    // 0x8005F2D8: addiu       $s3, $sp, 0xA8
    ctx->r19 = ADD32(ctx->r29, 0XA8);
    // 0x8005F2DC: addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    // 0x8005F2E0: addiu       $a1, $sp, 0x98
    ctx->r5 = ADD32(ctx->r29, 0X98);
    // 0x8005F2E4: jal         0x80019548
    // 0x8005F2E8: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    func_80019548(rdram, ctx);
        goto after_16;
    // 0x8005F2E8: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    after_16:
    // 0x8005F2EC: jal         0x8001CF2C
    // 0x8005F2F0: addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    func_8001CF2C(rdram, ctx);
        goto after_17;
    // 0x8005F2F0: addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    after_17:
    // 0x8005F2F4: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8005F2F8: lwc1        $f2, -0x4DEC($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X4DEC);
    // 0x8005F2FC: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x8005F300: nop

    // 0x8005F304: bc1f        L_8005F3C8
    if (!c1cs) {
        // 0x8005F308: nop
    
            goto L_8005F3C8;
    }
    // 0x8005F308: nop

    // 0x8005F30C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8005F310: c.lt.s      $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f20.fl < ctx->f0.fl;
    // 0x8005F314: nop

    // 0x8005F318: bc1f        L_8005F334
    if (!c1cs) {
        // 0x8005F31C: mov.s       $f2, $f20
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    ctx->f2.fl = ctx->f20.fl;
            goto L_8005F334;
    }
    // 0x8005F31C: mov.s       $f2, $f20
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    ctx->f2.fl = ctx->f20.fl;
    // 0x8005F320: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8005F324: lwc1        $f0, -0x4DE8($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X4DE8);
    // 0x8005F328: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x8005F32C: j           L_8005F350
    // 0x8005F330: addiu       $s1, $sp, 0x78
    ctx->r17 = ADD32(ctx->r29, 0X78);
        goto L_8005F350;
    // 0x8005F330: addiu       $s1, $sp, 0x78
    ctx->r17 = ADD32(ctx->r29, 0X78);
L_8005F334:
    // 0x8005F334: c.lt.s      $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f0.fl < ctx->f20.fl;
    // 0x8005F338: nop

    // 0x8005F33C: bc1f        L_8005F3C8
    if (!c1cs) {
        // 0x8005F340: addiu       $s1, $sp, 0x78
        ctx->r17 = ADD32(ctx->r29, 0X78);
            goto L_8005F3C8;
    }
    // 0x8005F340: addiu       $s1, $sp, 0x78
    ctx->r17 = ADD32(ctx->r29, 0X78);
    // 0x8005F344: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8005F348: lwc1        $f0, -0x4DE4($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X4DE4);
    // 0x8005F34C: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
L_8005F350:
    // 0x8005F350: nop

    // 0x8005F354: bc1tl       L_8005F35C
    if (c1cs) {
        // 0x8005F358: mov.s       $f2, $f0
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
            goto L_8005F35C;
    }
    goto skip_3;
    // 0x8005F358: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
    skip_3:
L_8005F35C:
    // 0x8005F35C: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x8005F360: mfc1        $a2, $f2
    ctx->r6 = (int32_t)ctx->f2.u32l;
    // 0x8005F364: jal         0x8001D144
    // 0x8005F368: addu        $a1, $s3, $zero
    ctx->r5 = ADD32(ctx->r19, 0);
    func_8001D144(rdram, ctx);
        goto after_18;
    // 0x8005F368: addu        $a1, $s3, $zero
    ctx->r5 = ADD32(ctx->r19, 0);
    after_18:
    // 0x8005F36C: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x8005F370: addiu       $a1, $s2, 0x10
    ctx->r5 = ADD32(ctx->r18, 0X10);
    // 0x8005F374: addiu       $s0, $sp, 0x38
    ctx->r16 = ADD32(ctx->r29, 0X38);
    // 0x8005F378: jal         0x8001D3C4
    // 0x8005F37C: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    func_8001D3C4(rdram, ctx);
        goto after_19;
    // 0x8005F37C: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    after_19:
    // 0x8005F380: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x8005F384: addiu       $a1, $s2, 0x1C
    ctx->r5 = ADD32(ctx->r18, 0X1C);
    // 0x8005F388: lw          $t0, 0x38($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X38);
    // 0x8005F38C: lw          $t1, 0x3C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X3C);
    // 0x8005F390: lw          $t2, 0x40($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X40);
    // 0x8005F394: sw          $t0, 0x10($s2)
    MEM_W(0X10, ctx->r18) = ctx->r8;
    // 0x8005F398: sw          $t1, 0x14($s2)
    MEM_W(0X14, ctx->r18) = ctx->r9;
    // 0x8005F39C: sw          $t2, 0x18($s2)
    MEM_W(0X18, ctx->r18) = ctx->r10;
    // 0x8005F3A0: jal         0x8001D3C4
    // 0x8005F3A4: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    func_8001D3C4(rdram, ctx);
        goto after_20;
    // 0x8005F3A4: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    after_20:
    // 0x8005F3A8: lw          $t0, 0x38($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X38);
    // 0x8005F3AC: lw          $t1, 0x3C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X3C);
    // 0x8005F3B0: lw          $t2, 0x40($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X40);
    // 0x8005F3B4: sw          $t0, 0x1C($s2)
    MEM_W(0X1C, ctx->r18) = ctx->r8;
    // 0x8005F3B8: sw          $t1, 0x20($s2)
    MEM_W(0X20, ctx->r18) = ctx->r9;
    // 0x8005F3BC: sw          $t2, 0x24($s2)
    MEM_W(0X24, ctx->r18) = ctx->r10;
    // 0x8005F3C0: jal         0x80059F10
    // 0x8005F3C4: addiu       $a0, $s2, 0x4
    ctx->r4 = ADD32(ctx->r18, 0X4);
    func_80059F10(rdram, ctx);
        goto after_21;
    // 0x8005F3C4: addiu       $a0, $s2, 0x4
    ctx->r4 = ADD32(ctx->r18, 0X4);
    after_21:
L_8005F3C8:
    // 0x8005F3C8: lwc1        $f0, 0x5C($s2)
    ctx->f0.u32l = MEM_W(ctx->r18, 0X5C);
    // 0x8005F3CC: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8005F3D0: lwc1        $f2, -0x4DE0($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X4DE0);
    // 0x8005F3D4: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x8005F3D8: lwc1        $f2, 0x58($s2)
    ctx->f2.u32l = MEM_W(ctx->r18, 0X58);
    // 0x8005F3DC: lwc1        $f4, 0x6C($s2)
    ctx->f4.u32l = MEM_W(ctx->r18, 0X6C);
    // 0x8005F3E0: add.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x8005F3E4: swc1        $f0, 0x5C($s2)
    MEM_W(0X5C, ctx->r18) = ctx->f0.u32l;
    // 0x8005F3E8: c.lt.s      $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f4.fl < ctx->f2.fl;
    // 0x8005F3EC: nop

    // 0x8005F3F0: bc1f        L_8005F3FC
    if (!c1cs) {
        // 0x8005F3F4: swc1        $f2, 0x58($s2)
        MEM_W(0X58, ctx->r18) = ctx->f2.u32l;
            goto L_8005F3FC;
    }
    // 0x8005F3F4: swc1        $f2, 0x58($s2)
    MEM_W(0X58, ctx->r18) = ctx->f2.u32l;
    // 0x8005F3F8: swc1        $f4, 0x58($s2)
    MEM_W(0X58, ctx->r18) = ctx->f4.u32l;
L_8005F3FC:
    // 0x8005F3FC: lwc1        $f2, 0x10($s2)
    ctx->f2.u32l = MEM_W(ctx->r18, 0X10);
    // 0x8005F400: lwc1        $f0, 0x58($s2)
    ctx->f0.u32l = MEM_W(ctx->r18, 0X58);
    // 0x8005F404: mul.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x8005F408: lwc1        $f4, 0x14($s2)
    ctx->f4.u32l = MEM_W(ctx->r18, 0X14);
    // 0x8005F40C: mul.s       $f4, $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x8005F410: lwc1        $f6, 0x18($s2)
    ctx->f6.u32l = MEM_W(ctx->r18, 0X18);
    // 0x8005F414: mul.s       $f6, $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x8005F418: swc1        $f2, 0x28($s2)
    MEM_W(0X28, ctx->r18) = ctx->f2.u32l;
    // 0x8005F41C: mul.s       $f2, $f2, $f24
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f24.fl);
    // 0x8005F420: swc1        $f4, 0x2C($s2)
    MEM_W(0X2C, ctx->r18) = ctx->f4.u32l;
    // 0x8005F424: mov.s       $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.fl = ctx->f4.fl;
    // 0x8005F428: mul.s       $f0, $f0, $f24
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f24.fl);
    // 0x8005F42C: swc1        $f6, 0x30($s2)
    MEM_W(0X30, ctx->r18) = ctx->f6.u32l;
    // 0x8005F430: mul.s       $f6, $f6, $f24
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f6.fl = MUL_S(ctx->f6.fl, ctx->f24.fl);
    // 0x8005F434: lwc1        $f4, 0x4($s2)
    ctx->f4.u32l = MEM_W(ctx->r18, 0X4);
    // 0x8005F438: add.s       $f4, $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f2.fl;
    // 0x8005F43C: lwc1        $f2, 0x8($s2)
    ctx->f2.u32l = MEM_W(ctx->r18, 0X8);
    // 0x8005F440: add.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x8005F444: lwc1        $f0, 0xC($s2)
    ctx->f0.u32l = MEM_W(ctx->r18, 0XC);
    // 0x8005F448: add.s       $f0, $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f6.fl;
    // 0x8005F44C: swc1        $f4, 0x4($s2)
    MEM_W(0X4, ctx->r18) = ctx->f4.u32l;
    // 0x8005F450: swc1        $f2, 0x8($s2)
    MEM_W(0X8, ctx->r18) = ctx->f2.u32l;
    // 0x8005F454: swc1        $f0, 0xC($s2)
    MEM_W(0XC, ctx->r18) = ctx->f0.u32l;
    // 0x8005F458: lw          $ra, 0xC8($sp)
    ctx->r31 = MEM_W(ctx->r29, 0XC8);
    // 0x8005F45C: lw          $s3, 0xC4($sp)
    ctx->r19 = MEM_W(ctx->r29, 0XC4);
    // 0x8005F460: lw          $s2, 0xC0($sp)
    ctx->r18 = MEM_W(ctx->r29, 0XC0);
    // 0x8005F464: lw          $s1, 0xBC($sp)
    ctx->r17 = MEM_W(ctx->r29, 0XBC);
    // 0x8005F468: lw          $s0, 0xB8($sp)
    ctx->r16 = MEM_W(ctx->r29, 0XB8);
    // 0x8005F46C: ldc1        $f24, 0xE0($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0XE0);
    // 0x8005F470: ldc1        $f22, 0xD8($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0XD8);
    // 0x8005F474: ldc1        $f20, 0xD0($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0XD0);
    // 0x8005F478: jr          $ra
    // 0x8005F47C: addiu       $sp, $sp, 0xE8
    ctx->r29 = ADD32(ctx->r29, 0XE8);
    return;
    // 0x8005F47C: addiu       $sp, $sp, 0xE8
    ctx->r29 = ADD32(ctx->r29, 0XE8);
;}
RECOMP_FUNC void func_8005F480(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005F480: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x8005F484: sw          $s2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r18;
    // 0x8005F488: addu        $s2, $a0, $zero
    ctx->r18 = ADD32(ctx->r4, 0);
    // 0x8005F48C: sw          $s3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r19;
    // 0x8005F490: addiu       $s3, $sp, 0x10
    ctx->r19 = ADD32(ctx->r29, 0X10);
    // 0x8005F494: addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    // 0x8005F498: sw          $s1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r17;
    // 0x8005F49C: addiu       $s1, $s2, 0x10
    ctx->r17 = ADD32(ctx->r18, 0X10);
    // 0x8005F4A0: sdc1        $f22, 0x60($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X60, ctx->r29);
    // 0x8005F4A4: mtc1        $a1, $f22
    ctx->f22.u32l = ctx->r5;
    // 0x8005F4A8: lui         $v0, 0x8004
    ctx->r2 = S32(0X8004 << 16);
    // 0x8005F4AC: sw          $ra, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r31;
    // 0x8005F4B0: sw          $s0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r16;
    // 0x8005F4B4: sdc1        $f20, 0x58($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X58, ctx->r29);
    // 0x8005F4B8: addiu       $t1, $v0, -0x4DDC
    ctx->r9 = ADD32(ctx->r2, -0X4DDC);
    // 0x8005F4BC: lw          $v1, 0x0($t1)
    ctx->r3 = MEM_W(ctx->r9, 0X0);
    // 0x8005F4C0: lw          $a3, 0x4($t1)
    ctx->r7 = MEM_W(ctx->r9, 0X4);
    // 0x8005F4C4: lw          $t0, 0x8($t1)
    ctx->r8 = MEM_W(ctx->r9, 0X8);
    // 0x8005F4C8: sw          $v1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r3;
    // 0x8005F4CC: sw          $a3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r7;
    // 0x8005F4D0: sw          $t0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r8;
    // 0x8005F4D4: jal         0x8001CFE8
    // 0x8005F4D8: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    func_8001CFE8(rdram, ctx);
        goto after_0;
    // 0x8005F4D8: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    after_0:
    // 0x8005F4DC: jal         0x8001C5CC
    // 0x8005F4E0: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    func_8001C5CC(rdram, ctx);
        goto after_1;
    // 0x8005F4E0: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    after_1:
    // 0x8005F4E4: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8005F4E8: lwc1        $f2, -0x4DD0($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X4DD0);
    // 0x8005F4EC: mul.s       $f20, $f0, $f2
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f20.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x8005F4F0: abs.s       $f2, $f20
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); 
    ctx->f2.fl = fabsf(ctx->f20.fl);
    // 0x8005F4F4: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8005F4F8: lwc1        $f0, -0x4DCC($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X4DCC);
    // 0x8005F4FC: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x8005F500: nop

    // 0x8005F504: bc1f        L_8005F600
    if (!c1cs) {
        // 0x8005F508: addiu       $s0, $sp, 0x30
        ctx->r16 = ADD32(ctx->r29, 0X30);
            goto L_8005F600;
    }
    // 0x8005F508: addiu       $s0, $sp, 0x30
    ctx->r16 = ADD32(ctx->r29, 0X30);
    // 0x8005F50C: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x8005F510: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    // 0x8005F514: jal         0x80019548
    // 0x8005F518: addu        $a2, $s3, $zero
    ctx->r6 = ADD32(ctx->r19, 0);
    func_80019548(rdram, ctx);
        goto after_2;
    // 0x8005F518: addu        $a2, $s3, $zero
    ctx->r6 = ADD32(ctx->r19, 0);
    after_2:
    // 0x8005F51C: jal         0x8001CF2C
    // 0x8005F520: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_8001CF2C(rdram, ctx);
        goto after_3;
    // 0x8005F520: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_3:
    // 0x8005F524: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8005F528: lwc1        $f2, -0x4DC8($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X4DC8);
    // 0x8005F52C: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x8005F530: nop

    // 0x8005F534: bc1f        L_8005F600
    if (!c1cs) {
        // 0x8005F538: nop
    
            goto L_8005F600;
    }
    // 0x8005F538: nop

    // 0x8005F53C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8005F540: c.lt.s      $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f20.fl < ctx->f0.fl;
    // 0x8005F544: nop

    // 0x8005F548: bc1f        L_8005F568
    if (!c1cs) {
        // 0x8005F54C: addiu       $a0, $sp, 0x20
        ctx->r4 = ADD32(ctx->r29, 0X20);
            goto L_8005F568;
    }
    // 0x8005F54C: addiu       $a0, $sp, 0x20
    ctx->r4 = ADD32(ctx->r29, 0X20);
    // 0x8005F550: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8005F554: lwc1        $f2, -0x4DC4($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X4DC4);
    // 0x8005F558: mov.s       $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    ctx->f0.fl = ctx->f20.fl;
    // 0x8005F55C: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x8005F560: j           L_8005F588
    // 0x8005F564: nop

        goto L_8005F588;
    // 0x8005F564: nop

L_8005F568:
    // 0x8005F568: c.lt.s      $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f0.fl < ctx->f20.fl;
    // 0x8005F56C: nop

    // 0x8005F570: bc1f        L_8005F5A0
    if (!c1cs) {
        // 0x8005F574: mov.s       $f0, $f20
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    ctx->f0.fl = ctx->f20.fl;
            goto L_8005F5A0;
    }
    // 0x8005F574: mov.s       $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    ctx->f0.fl = ctx->f20.fl;
    // 0x8005F578: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8005F57C: lwc1        $f2, -0x4DC0($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X4DC0);
    // 0x8005F580: addiu       $a0, $sp, 0x20
    ctx->r4 = ADD32(ctx->r29, 0X20);
    // 0x8005F584: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
L_8005F588:
    // 0x8005F588: nop

    // 0x8005F58C: bc1tl       L_8005F594
    if (c1cs) {
        // 0x8005F590: mov.s       $f0, $f2
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
            goto L_8005F594;
    }
    goto skip_0;
    // 0x8005F590: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    skip_0:
L_8005F594:
    // 0x8005F594: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8005F598: jal         0x8001D240
    // 0x8005F59C: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    func_8001D240(rdram, ctx);
        goto after_4;
    // 0x8005F59C: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    after_4:
L_8005F5A0:
    // 0x8005F5A0: addiu       $s1, $sp, 0x20
    ctx->r17 = ADD32(ctx->r29, 0X20);
    // 0x8005F5A4: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x8005F5A8: addiu       $a1, $s2, 0x10
    ctx->r5 = ADD32(ctx->r18, 0X10);
    // 0x8005F5AC: addiu       $s0, $sp, 0x30
    ctx->r16 = ADD32(ctx->r29, 0X30);
    // 0x8005F5B0: jal         0x8001D3C4
    // 0x8005F5B4: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    func_8001D3C4(rdram, ctx);
        goto after_5;
    // 0x8005F5B4: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    after_5:
    // 0x8005F5B8: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x8005F5BC: addiu       $a1, $s2, 0x1C
    ctx->r5 = ADD32(ctx->r18, 0X1C);
    // 0x8005F5C0: lw          $v1, 0x30($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X30);
    // 0x8005F5C4: lw          $a3, 0x34($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X34);
    // 0x8005F5C8: lw          $t0, 0x38($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X38);
    // 0x8005F5CC: sw          $v1, 0x10($s2)
    MEM_W(0X10, ctx->r18) = ctx->r3;
    // 0x8005F5D0: sw          $a3, 0x14($s2)
    MEM_W(0X14, ctx->r18) = ctx->r7;
    // 0x8005F5D4: sw          $t0, 0x18($s2)
    MEM_W(0X18, ctx->r18) = ctx->r8;
    // 0x8005F5D8: jal         0x8001D3C4
    // 0x8005F5DC: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    func_8001D3C4(rdram, ctx);
        goto after_6;
    // 0x8005F5DC: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    after_6:
    // 0x8005F5E0: lw          $v1, 0x30($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X30);
    // 0x8005F5E4: lw          $a3, 0x34($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X34);
    // 0x8005F5E8: lw          $t0, 0x38($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X38);
    // 0x8005F5EC: sw          $v1, 0x1C($s2)
    MEM_W(0X1C, ctx->r18) = ctx->r3;
    // 0x8005F5F0: sw          $a3, 0x20($s2)
    MEM_W(0X20, ctx->r18) = ctx->r7;
    // 0x8005F5F4: sw          $t0, 0x24($s2)
    MEM_W(0X24, ctx->r18) = ctx->r8;
    // 0x8005F5F8: jal         0x80059F10
    // 0x8005F5FC: addiu       $a0, $s2, 0x4
    ctx->r4 = ADD32(ctx->r18, 0X4);
    func_80059F10(rdram, ctx);
        goto after_7;
    // 0x8005F5FC: addiu       $a0, $s2, 0x4
    ctx->r4 = ADD32(ctx->r18, 0X4);
    after_7:
L_8005F600:
    // 0x8005F600: lwc1        $f6, 0x10($s2)
    ctx->f6.u32l = MEM_W(ctx->r18, 0X10);
    // 0x8005F604: lwc1        $f0, 0x58($s2)
    ctx->f0.u32l = MEM_W(ctx->r18, 0X58);
    // 0x8005F608: mul.s       $f6, $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x8005F60C: lwc1        $f4, 0x14($s2)
    ctx->f4.u32l = MEM_W(ctx->r18, 0X14);
    // 0x8005F610: mul.s       $f4, $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x8005F614: lwc1        $f2, 0x5C($s2)
    ctx->f2.u32l = MEM_W(ctx->r18, 0X5C);
    // 0x8005F618: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8005F61C: lwc1        $f0, -0x4DBC($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X4DBC);
    // 0x8005F620: lwc1        $f8, 0x18($s2)
    ctx->f8.u32l = MEM_W(ctx->r18, 0X18);
    // 0x8005F624: add.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x8005F628: lwc1        $f0, 0x58($s2)
    ctx->f0.u32l = MEM_W(ctx->r18, 0X58);
    // 0x8005F62C: mul.s       $f8, $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x8005F630: swc1        $f2, 0x5C($s2)
    MEM_W(0X5C, ctx->r18) = ctx->f2.u32l;
    // 0x8005F634: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    // 0x8005F638: add.s       $f4, $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f0.fl;
    // 0x8005F63C: swc1        $f6, 0x28($s2)
    MEM_W(0X28, ctx->r18) = ctx->f6.u32l;
    // 0x8005F640: mov.s       $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    ctx->f2.fl = ctx->f6.fl;
    // 0x8005F644: mul.s       $f2, $f2, $f22
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f22.fl);
    // 0x8005F648: swc1        $f4, 0x2C($s2)
    MEM_W(0X2C, ctx->r18) = ctx->f4.u32l;
    // 0x8005F64C: mov.s       $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = ctx->f4.fl;
    // 0x8005F650: mul.s       $f6, $f6, $f22
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f6.fl = MUL_S(ctx->f6.fl, ctx->f22.fl);
    // 0x8005F654: swc1        $f8, 0x30($s2)
    MEM_W(0X30, ctx->r18) = ctx->f8.u32l;
    // 0x8005F658: mov.s       $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    ctx->f0.fl = ctx->f8.fl;
    // 0x8005F65C: mul.s       $f0, $f0, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f22.fl);
    // 0x8005F660: lwc1        $f4, 0x4($s2)
    ctx->f4.u32l = MEM_W(ctx->r18, 0X4);
    // 0x8005F664: add.s       $f4, $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f2.fl;
    // 0x8005F668: lwc1        $f2, 0xC($s2)
    ctx->f2.u32l = MEM_W(ctx->r18, 0XC);
    // 0x8005F66C: add.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x8005F670: lwc1        $f0, 0x8($s2)
    ctx->f0.u32l = MEM_W(ctx->r18, 0X8);
    // 0x8005F674: add.s       $f0, $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f6.fl;
    // 0x8005F678: swc1        $f4, 0x4($s2)
    MEM_W(0X4, ctx->r18) = ctx->f4.u32l;
    // 0x8005F67C: swc1        $f2, 0xC($s2)
    MEM_W(0XC, ctx->r18) = ctx->f2.u32l;
    // 0x8005F680: swc1        $f0, 0x8($s2)
    MEM_W(0X8, ctx->r18) = ctx->f0.u32l;
    // 0x8005F684: lw          $ra, 0x50($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X50);
    // 0x8005F688: lw          $s3, 0x4C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X4C);
    // 0x8005F68C: lw          $s2, 0x48($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X48);
    // 0x8005F690: lw          $s1, 0x44($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X44);
    // 0x8005F694: lw          $s0, 0x40($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X40);
    // 0x8005F698: ldc1        $f22, 0x60($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X60);
    // 0x8005F69C: ldc1        $f20, 0x58($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X58);
    // 0x8005F6A0: jr          $ra
    // 0x8005F6A4: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    return;
    // 0x8005F6A4: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
;}
RECOMP_FUNC void func_8005F6A8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005F6A8: addiu       $sp, $sp, -0xF8
    ctx->r29 = ADD32(ctx->r29, -0XF8);
    // 0x8005F6AC: sw          $s2, 0xE0($sp)
    MEM_W(0XE0, ctx->r29) = ctx->r18;
    // 0x8005F6B0: addu        $s2, $a0, $zero
    ctx->r18 = ADD32(ctx->r4, 0);
    // 0x8005F6B4: sw          $ra, 0xF4($sp)
    MEM_W(0XF4, ctx->r29) = ctx->r31;
    // 0x8005F6B8: sw          $s6, 0xF0($sp)
    MEM_W(0XF0, ctx->r29) = ctx->r22;
    // 0x8005F6BC: sw          $s5, 0xEC($sp)
    MEM_W(0XEC, ctx->r29) = ctx->r21;
    // 0x8005F6C0: sw          $s4, 0xE8($sp)
    MEM_W(0XE8, ctx->r29) = ctx->r20;
    // 0x8005F6C4: sw          $s3, 0xE4($sp)
    MEM_W(0XE4, ctx->r29) = ctx->r19;
    // 0x8005F6C8: sw          $s1, 0xDC($sp)
    MEM_W(0XDC, ctx->r29) = ctx->r17;
    // 0x8005F6CC: sw          $s0, 0xD8($sp)
    MEM_W(0XD8, ctx->r29) = ctx->r16;
    // 0x8005F6D0: lbu         $v0, 0xC3($s2)
    ctx->r2 = MEM_BU(ctx->r18, 0XC3);
    // 0x8005F6D4: beq         $v0, $zero, L_8005F7B4
    if (ctx->r2 == 0) {
        // 0x8005F6D8: lui         $v0, 0x8004
        ctx->r2 = S32(0X8004 << 16);
            goto L_8005F7B4;
    }
    // 0x8005F6D8: lui         $v0, 0x8004
    ctx->r2 = S32(0X8004 << 16);
    // 0x8005F6DC: addiu       $t3, $v0, -0x4DB8
    ctx->r11 = ADD32(ctx->r2, -0X4DB8);
    // 0x8005F6E0: lwl         $t0, 0x0($t3)
    ctx->r8 = do_lwl(rdram, ctx->r8, ctx->r11, 0X0);
    // 0x8005F6E4: lwr         $t0, 0x3($t3)
    ctx->r8 = do_lwr(rdram, ctx->r8, ctx->r11, 0X3);
    // 0x8005F6E8: lb          $t1, 0x4($t3)
    ctx->r9 = MEM_B(ctx->r11, 0X4);
    // 0x8005F6EC: swl         $t0, 0x30($sp)
    do_swl(rdram, 0X30, ctx->r29, ctx->r8);
    // 0x8005F6F0: swr         $t0, 0x33($sp)
    do_swr(rdram, 0X33, ctx->r29, ctx->r8);
    // 0x8005F6F4: sb          $t1, 0x34($sp)
    MEM_B(0X34, ctx->r29) = ctx->r9;
    // 0x8005F6F8: lwc1        $f0, 0x4($s2)
    ctx->f0.u32l = MEM_W(ctx->r18, 0X4);
    // 0x8005F6FC: addiu       $v0, $s2, 0x4
    ctx->r2 = ADD32(ctx->r18, 0X4);
    // 0x8005F700: swc1        $f0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f0.u32l;
    // 0x8005F704: lwc1        $f0, 0x4($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X4);
    // 0x8005F708: addiu       $a0, $sp, 0x38
    ctx->r4 = ADD32(ctx->r29, 0X38);
    // 0x8005F70C: swc1        $f0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f0.u32l;
    // 0x8005F710: lwc1        $f0, 0x8($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X8);
    // 0x8005F714: addiu       $v1, $sp, 0x30
    ctx->r3 = ADD32(ctx->r29, 0X30);
    // 0x8005F718: swc1        $f0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f0.u32l;
    // 0x8005F71C: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8005F720: lwc1        $f0, -0x4DB0($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X4DB0);
    // 0x8005F724: ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
    // 0x8005F728: lw          $t0, 0x10($s2)
    ctx->r8 = MEM_W(ctx->r18, 0X10);
    // 0x8005F72C: lw          $t1, 0x14($s2)
    ctx->r9 = MEM_W(ctx->r18, 0X14);
    // 0x8005F730: lw          $t2, 0x18($s2)
    ctx->r10 = MEM_W(ctx->r18, 0X18);
    // 0x8005F734: sw          $t0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r8;
    // 0x8005F738: sw          $t1, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r9;
    // 0x8005F73C: sw          $t2, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r10;
    // 0x8005F740: swc1        $f0, 0x20($v1)
    MEM_W(0X20, ctx->r3) = ctx->f0.u32l;
    // 0x8005F744: swc1        $f0, 0x24($v1)
    MEM_W(0X24, ctx->r3) = ctx->f0.u32l;
    // 0x8005F748: sw          $zero, 0x58($sp)
    MEM_W(0X58, ctx->r29) = 0;
    // 0x8005F74C: sh          $v0, 0x30($v1)
    MEM_H(0X30, ctx->r3) = ctx->r2;
    // 0x8005F750: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8005F754: sw          $v1, 0x2C($v1)
    MEM_W(0X2C, ctx->r3) = ctx->r3;
    // 0x8005F758: jal         0x800F15B8
    // 0x8005F75C: sb          $v0, 0x32($v1)
    MEM_B(0X32, ctx->r3) = ctx->r2;
    func_800F15B8(rdram, ctx);
        goto after_0;
    // 0x8005F75C: sb          $v0, 0x32($v1)
    MEM_B(0X32, ctx->r3) = ctx->r2;
    after_0:
    // 0x8005F760: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    // 0x8005F764: blez        $s0, L_8005F79C
    if (SIGNED(ctx->r16) <= 0) {
        // 0x8005F768: addiu       $s1, $sp, 0x20
        ctx->r17 = ADD32(ctx->r29, 0X20);
            goto L_8005F79C;
    }
    // 0x8005F768: addiu       $s1, $sp, 0x20
    ctx->r17 = ADD32(ctx->r29, 0X20);
    // 0x8005F76C: slti        $v0, $s0, 0x7
    ctx->r2 = SIGNED(ctx->r16) < 0X7 ? 1 : 0;
    // 0x8005F770: beq         $v0, $zero, L_8005F79C
    if (ctx->r2 == 0) {
        // 0x8005F774: addiu       $v1, $sp, 0x38
        ctx->r3 = ADD32(ctx->r29, 0X38);
            goto L_8005F79C;
    }
    // 0x8005F774: addiu       $v1, $sp, 0x38
    ctx->r3 = ADD32(ctx->r29, 0X38);
    // 0x8005F778: sll         $v0, $s0, 1
    ctx->r2 = S32(ctx->r16 << 1);
    // 0x8005F77C: addu        $a0, $v0, $v1
    ctx->r4 = ADD32(ctx->r2, ctx->r3);
L_8005F780:
    // 0x8005F780: lhu         $v0, 0x2C($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X2C);
    // 0x8005F784: addiu       $v1, $v1, 0x2
    ctx->r3 = ADD32(ctx->r3, 0X2);
    // 0x8005F788: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8005F78C: sh          $v0, 0x2C($a0)
    MEM_H(0X2C, ctx->r4) = ctx->r2;
    // 0x8005F790: slti        $v0, $s0, 0x7
    ctx->r2 = SIGNED(ctx->r16) < 0X7 ? 1 : 0;
    // 0x8005F794: bne         $v0, $zero, L_8005F780
    if (ctx->r2 != 0) {
        // 0x8005F798: addiu       $a0, $a0, 0x2
        ctx->r4 = ADD32(ctx->r4, 0X2);
            goto L_8005F780;
    }
    // 0x8005F798: addiu       $a0, $a0, 0x2
    ctx->r4 = ADD32(ctx->r4, 0X2);
L_8005F79C:
    // 0x8005F79C: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x8005F7A0: addiu       $a1, $sp, 0x64
    ctx->r5 = ADD32(ctx->r29, 0X64);
    // 0x8005F7A4: jal         0x80018EF4
    // 0x8005F7A8: addiu       $a2, $zero, 0xE
    ctx->r6 = ADD32(0, 0XE);
    zmemcpy(rdram, ctx);
        goto after_1;
    // 0x8005F7A8: addiu       $a2, $zero, 0xE
    ctx->r6 = ADD32(0, 0XE);
    after_1:
    // 0x8005F7AC: bne         $s0, $zero, L_8005F7BC
    if (ctx->r16 != 0) {
        // 0x8005F7B0: addu        $s1, $zero, $zero
        ctx->r17 = ADD32(0, 0);
            goto L_8005F7BC;
    }
    // 0x8005F7B0: addu        $s1, $zero, $zero
    ctx->r17 = ADD32(0, 0);
L_8005F7B4:
    // 0x8005F7B4: sb          $zero, 0xC3($s2)
    MEM_B(0XC3, ctx->r18) = 0;
    // 0x8005F7B8: addu        $s1, $zero, $zero
    ctx->r17 = ADD32(0, 0);
L_8005F7BC:
    // 0x8005F7BC: addiu       $s6, $sp, 0x80
    ctx->r22 = ADD32(ctx->r29, 0X80);
    // 0x8005F7C0: addiu       $s5, $sp, 0x60
    ctx->r21 = ADD32(ctx->r29, 0X60);
    // 0x8005F7C4: addiu       $s4, $s2, 0x10
    ctx->r20 = ADD32(ctx->r18, 0X10);
    // 0x8005F7C8: addiu       $s3, $sp, 0x70
    ctx->r19 = ADD32(ctx->r29, 0X70);
    // 0x8005F7CC: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8005F7D0: lwc1        $f0, -0x4DAC($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X4DAC);
    // 0x8005F7D4: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8005F7D8: lwc1        $f2, -0x4DA8($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X4DA8);
    // 0x8005F7DC: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8005F7E0: lwc1        $f4, -0x4DA4($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X4DA4);
    // 0x8005F7E4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8005F7E8: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    // 0x8005F7EC: sb          $v0, 0x44($sp)
    MEM_B(0X44, ctx->r29) = ctx->r2;
    // 0x8005F7F0: swc1        $f0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f0.u32l;
    // 0x8005F7F4: swc1        $f2, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f2.u32l;
    // 0x8005F7F8: swc1        $f4, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f4.u32l;
    // 0x8005F7FC: lw          $t0, 0x4($s2)
    ctx->r8 = MEM_W(ctx->r18, 0X4);
    // 0x8005F800: lw          $t1, 0x8($s2)
    ctx->r9 = MEM_W(ctx->r18, 0X8);
    // 0x8005F804: lw          $t2, 0xC($s2)
    ctx->r10 = MEM_W(ctx->r18, 0XC);
    // 0x8005F808: sw          $t0, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->r8;
    // 0x8005F80C: sw          $t1, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->r9;
    // 0x8005F810: sw          $t2, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->r10;
L_8005F814:
    // 0x8005F814: bne         $s1, $zero, L_8005F88C
    if (ctx->r17 != 0) {
        // 0x8005F818: addu        $a0, $s5, $zero
        ctx->r4 = ADD32(ctx->r21, 0);
            goto L_8005F88C;
    }
    // 0x8005F818: addu        $a0, $s5, $zero
    ctx->r4 = ADD32(ctx->r21, 0);
    // 0x8005F81C: addu        $a0, $s6, $zero
    ctx->r4 = ADD32(ctx->r22, 0);
    // 0x8005F820: addiu       $a1, $s2, 0x1C
    ctx->r5 = ADD32(ctx->r18, 0X1C);
    // 0x8005F824: lw          $t0, 0x10($s2)
    ctx->r8 = MEM_W(ctx->r18, 0X10);
    // 0x8005F828: lw          $t1, 0x14($s2)
    ctx->r9 = MEM_W(ctx->r18, 0X14);
    // 0x8005F82C: lw          $t2, 0x18($s2)
    ctx->r10 = MEM_W(ctx->r18, 0X18);
    // 0x8005F830: sw          $t0, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->r8;
    // 0x8005F834: sw          $t1, 0xB8($sp)
    MEM_W(0XB8, ctx->r29) = ctx->r9;
    // 0x8005F838: sw          $t2, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->r10;
    // 0x8005F83C: lw          $t0, 0x1C($s2)
    ctx->r8 = MEM_W(ctx->r18, 0X1C);
    // 0x8005F840: lw          $t1, 0x20($s2)
    ctx->r9 = MEM_W(ctx->r18, 0X20);
    // 0x8005F844: lw          $t2, 0x24($s2)
    ctx->r10 = MEM_W(ctx->r18, 0X24);
    // 0x8005F848: sw          $t0, 0xC0($sp)
    MEM_W(0XC0, ctx->r29) = ctx->r8;
    // 0x8005F84C: sw          $t1, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->r9;
    // 0x8005F850: sw          $t2, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->r10;
    // 0x8005F854: lw          $t0, 0xB4($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XB4);
    // 0x8005F858: lw          $t1, 0xB8($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XB8);
    // 0x8005F85C: lw          $t2, 0xBC($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XBC);
    // 0x8005F860: sw          $t0, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->r8;
    // 0x8005F864: sw          $t1, 0xD0($sp)
    MEM_W(0XD0, ctx->r29) = ctx->r9;
    // 0x8005F868: sw          $t2, 0xD4($sp)
    MEM_W(0XD4, ctx->r29) = ctx->r10;
    // 0x8005F86C: jal         0x80019548
    // 0x8005F870: addiu       $a2, $s2, 0x10
    ctx->r6 = ADD32(ctx->r18, 0X10);
    func_80019548(rdram, ctx);
        goto after_2;
    // 0x8005F870: addiu       $a2, $s2, 0x10
    ctx->r6 = ADD32(ctx->r18, 0X10);
    after_2:
    // 0x8005F874: addiu       $a0, $sp, 0x50
    ctx->r4 = ADD32(ctx->r29, 0X50);
    // 0x8005F878: lui         $a2, 0x40C8
    ctx->r6 = S32(0X40C8 << 16);
    // 0x8005F87C: jal         0x8001D240
    // 0x8005F880: addu        $a1, $s6, $zero
    ctx->r5 = ADD32(ctx->r22, 0);
    func_8001D240(rdram, ctx);
        goto after_3;
    // 0x8005F880: addu        $a1, $s6, $zero
    ctx->r5 = ADD32(ctx->r22, 0);
    after_3:
    // 0x8005F884: j           L_8005F8F8
    // 0x8005F888: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
        goto L_8005F8F8;
    // 0x8005F888: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
L_8005F88C:
    // 0x8005F88C: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8005F890: lwc1        $f2, -0x4DA0($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X4DA0);
    // 0x8005F894: mtc1        $s1, $f0
    ctx->f0.u32l = ctx->r17;
    // 0x8005F898: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x8005F89C: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x8005F8A0: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8005F8A4: jal         0x8001D240
    // 0x8005F8A8: addu        $a1, $s4, $zero
    ctx->r5 = ADD32(ctx->r20, 0);
    func_8001D240(rdram, ctx);
        goto after_4;
    // 0x8005F8A8: addu        $a1, $s4, $zero
    ctx->r5 = ADD32(ctx->r20, 0);
    after_4:
    // 0x8005F8AC: addu        $a0, $s5, $zero
    ctx->r4 = ADD32(ctx->r21, 0);
    // 0x8005F8B0: addiu       $a1, $sp, 0x50
    ctx->r5 = ADD32(ctx->r29, 0X50);
    // 0x8005F8B4: jal         0x8001D2C0
    // 0x8005F8B8: addu        $a2, $s3, $zero
    ctx->r6 = ADD32(ctx->r19, 0);
    func_8001D2C0(rdram, ctx);
        goto after_5;
    // 0x8005F8B8: addu        $a2, $s3, $zero
    ctx->r6 = ADD32(ctx->r19, 0);
    after_5:
    // 0x8005F8BC: addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    // 0x8005F8C0: addu        $a1, $s4, $zero
    ctx->r5 = ADD32(ctx->r20, 0);
    // 0x8005F8C4: jal         0x8001D3C4
    // 0x8005F8C8: addiu       $a2, $sp, 0xB4
    ctx->r6 = ADD32(ctx->r29, 0XB4);
    func_8001D3C4(rdram, ctx);
        goto after_6;
    // 0x8005F8C8: addiu       $a2, $sp, 0xB4
    ctx->r6 = ADD32(ctx->r29, 0XB4);
    after_6:
    // 0x8005F8CC: addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    // 0x8005F8D0: addiu       $a1, $s2, 0x1C
    ctx->r5 = ADD32(ctx->r18, 0X1C);
    // 0x8005F8D4: jal         0x8001D3C4
    // 0x8005F8D8: addiu       $a2, $sp, 0xC0
    ctx->r6 = ADD32(ctx->r29, 0XC0);
    func_8001D3C4(rdram, ctx);
        goto after_7;
    // 0x8005F8D8: addiu       $a2, $sp, 0xC0
    ctx->r6 = ADD32(ctx->r29, 0XC0);
    after_7:
    // 0x8005F8DC: lw          $t0, 0xB4($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XB4);
    // 0x8005F8E0: lw          $t1, 0xB8($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XB8);
    // 0x8005F8E4: lw          $t2, 0xBC($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XBC);
    // 0x8005F8E8: sw          $t0, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->r8;
    // 0x8005F8EC: sw          $t1, 0xD0($sp)
    MEM_W(0XD0, ctx->r29) = ctx->r9;
    // 0x8005F8F0: sw          $t2, 0xD4($sp)
    MEM_W(0XD4, ctx->r29) = ctx->r10;
    // 0x8005F8F4: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
L_8005F8F8:
    // 0x8005F8F8: addiu       $a2, $sp, 0xA8
    ctx->r6 = ADD32(ctx->r29, 0XA8);
    // 0x8005F8FC: lhu         $a1, 0x44($s2)
    ctx->r5 = MEM_HU(ctx->r18, 0X44);
    // 0x8005F900: lui         $a3, 0x800A
    ctx->r7 = S32(0X800A << 16);
    // 0x8005F904: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x8005F908: lwc1        $f0, 0x58($s2)
    ctx->f0.u32l = MEM_W(ctx->r18, 0X58);
    // 0x8005F90C: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8005F910: lwc1        $f2, -0x4D9C($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X4D9C);
    // 0x8005F914: addiu       $a3, $a3, -0x129C
    ctx->r7 = ADD32(ctx->r7, -0X129C);
    // 0x8005F918: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    // 0x8005F91C: jal         0x8005E3B0
    // 0x8005F920: swc1        $f2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f2.u32l;
    func_8005E3B0(rdram, ctx);
        goto after_8;
    // 0x8005F920: swc1        $f2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f2.u32l;
    after_8:
    // 0x8005F924: lbu         $v1, 0xC3($s2)
    ctx->r3 = MEM_BU(ctx->r18, 0XC3);
    // 0x8005F928: beq         $v1, $zero, L_8005F954
    if (ctx->r3 == 0) {
        // 0x8005F92C: addu        $s0, $v0, $zero
        ctx->r16 = ADD32(ctx->r2, 0);
            goto L_8005F954;
    }
    // 0x8005F92C: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    // 0x8005F930: andi        $a0, $s0, 0xFFFF
    ctx->r4 = ctx->r16 & 0XFFFF;
    // 0x8005F934: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    // 0x8005F938: sll         $v0, $s1, 1
    ctx->r2 = S32(ctx->r17 << 1);
    // 0x8005F93C: addu        $v0, $sp, $v0
    ctx->r2 = ADD32(ctx->r29, ctx->r2);
    // 0x8005F940: sh          $zero, 0x30($sp)
    MEM_H(0X30, ctx->r29) = 0;
    // 0x8005F944: lhu         $v0, 0x20($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X20);
    // 0x8005F948: addiu       $a2, $sp, 0x30
    ctx->r6 = ADD32(ctx->r29, 0X30);
    // 0x8005F94C: jal         0x8003E8DC
    // 0x8005F950: sh          $v0, 0x32($sp)
    MEM_H(0X32, ctx->r29) = ctx->r2;
    func_8003E8DC(rdram, ctx);
        goto after_9;
    // 0x8005F950: sh          $v0, 0x32($sp)
    MEM_H(0X32, ctx->r29) = ctx->r2;
    after_9:
L_8005F954:
    // 0x8005F954: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
    // 0x8005F958: sh          $v0, 0x30($sp)
    MEM_H(0X30, ctx->r29) = ctx->r2;
    // 0x8005F95C: andi        $a0, $s0, 0xFFFF
    ctx->r4 = ctx->r16 & 0XFFFF;
    // 0x8005F960: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    // 0x8005F964: jal         0x8003E8DC
    // 0x8005F968: addiu       $a2, $sp, 0x30
    ctx->r6 = ADD32(ctx->r29, 0X30);
    func_8003E8DC(rdram, ctx);
        goto after_10;
    // 0x8005F968: addiu       $a2, $sp, 0x30
    ctx->r6 = ADD32(ctx->r29, 0X30);
    after_10:
    // 0x8005F96C: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x8005F970: slti        $v0, $s1, 0x7
    ctx->r2 = SIGNED(ctx->r17) < 0X7 ? 1 : 0;
    // 0x8005F974: bne         $v0, $zero, L_8005F814
    if (ctx->r2 != 0) {
        // 0x8005F978: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_8005F814;
    }
    // 0x8005F978: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8005F97C: lw          $ra, 0xF4($sp)
    ctx->r31 = MEM_W(ctx->r29, 0XF4);
    // 0x8005F980: lw          $s6, 0xF0($sp)
    ctx->r22 = MEM_W(ctx->r29, 0XF0);
    // 0x8005F984: lw          $s5, 0xEC($sp)
    ctx->r21 = MEM_W(ctx->r29, 0XEC);
    // 0x8005F988: lw          $s4, 0xE8($sp)
    ctx->r20 = MEM_W(ctx->r29, 0XE8);
    // 0x8005F98C: lw          $s3, 0xE4($sp)
    ctx->r19 = MEM_W(ctx->r29, 0XE4);
    // 0x8005F990: lw          $s2, 0xE0($sp)
    ctx->r18 = MEM_W(ctx->r29, 0XE0);
    // 0x8005F994: lw          $s1, 0xDC($sp)
    ctx->r17 = MEM_W(ctx->r29, 0XDC);
    // 0x8005F998: lw          $s0, 0xD8($sp)
    ctx->r16 = MEM_W(ctx->r29, 0XD8);
    // 0x8005F99C: jr          $ra
    // 0x8005F9A0: addiu       $sp, $sp, 0xF8
    ctx->r29 = ADD32(ctx->r29, 0XF8);
    return;
    // 0x8005F9A0: addiu       $sp, $sp, 0xF8
    ctx->r29 = ADD32(ctx->r29, 0XF8);
;}
RECOMP_FUNC void func_8005F9A4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005F9A4: addiu       $sp, $sp, -0xE0
    ctx->r29 = ADD32(ctx->r29, -0XE0);
    // 0x8005F9A8: sw          $s3, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->r19;
    // 0x8005F9AC: addu        $s3, $a0, $zero
    ctx->r19 = ADD32(ctx->r4, 0);
    // 0x8005F9B0: sw          $s2, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->r18;
    // 0x8005F9B4: andi        $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 & 0XFFFF;
    // 0x8005F9B8: addiu       $v1, $a1, -0x1
    ctx->r3 = ADD32(ctx->r5, -0X1);
    // 0x8005F9BC: sltiu       $v0, $v1, 0xB
    ctx->r2 = ctx->r3 < 0XB ? 1 : 0;
    // 0x8005F9C0: sw          $ra, 0xD4($sp)
    MEM_W(0XD4, ctx->r29) = ctx->r31;
    // 0x8005F9C4: sw          $s4, 0xD0($sp)
    MEM_W(0XD0, ctx->r29) = ctx->r20;
    // 0x8005F9C8: sw          $s1, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->r17;
    // 0x8005F9CC: sw          $s0, 0xC0($sp)
    MEM_W(0XC0, ctx->r29) = ctx->r16;
    // 0x8005F9D0: sdc1        $f20, 0xD8($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0XD8, ctx->r29);
    // 0x8005F9D4: lw          $s1, 0x4($s3)
    ctx->r17 = MEM_W(ctx->r19, 0X4);
    // 0x8005F9D8: beq         $v0, $zero, L_80060638
    if (ctx->r2 == 0) {
        // 0x8005F9DC: addu        $s2, $a2, $zero
        ctx->r18 = ADD32(ctx->r6, 0);
            goto L_80060638;
    }
    // 0x8005F9DC: addu        $s2, $a2, $zero
    ctx->r18 = ADD32(ctx->r6, 0);
    // 0x8005F9E0: lui         $v0, 0x8004
    ctx->r2 = S32(0X8004 << 16);
    // 0x8005F9E4: addiu       $v0, $v0, -0x4D98
    ctx->r2 = ADD32(ctx->r2, -0X4D98);
    // 0x8005F9E8: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x8005F9EC: addu        $v1, $v1, $v0
    gpr jr_addend_8005F9F4 = ctx->r3;
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x8005F9F0: lw          $v0, 0x0($v1)
    ctx->r2 = ADD32(ctx->r3, 0X0);
    // 0x8005F9F4: jr          $v0
    // 0x8005F9F8: nop

    switch (jr_addend_8005F9F4 >> 2) {
        case 0: goto L_8005F9FC; break;
        case 1: goto L_8005FD74; break;
        case 2: goto L_8005FE50; break;
        case 3: goto L_80060330; break;
        case 4: goto L_80060550; break;
        case 5: goto L_80060638; break;
        case 6: goto L_80060638; break;
        case 7: goto L_80060638; break;
        case 8: goto L_80060638; break;
        case 9: goto L_80060380; break;
        case 10: goto L_800605E4; break;
        default: switch_error(__func__, 0x8005F9F4, 0x8003B268);
    }
    // 0x8005F9F8: nop

L_8005F9FC:
    // 0x8005F9FC: lui         $v1, 0x800A
    ctx->r3 = S32(0X800A << 16);
    // 0x8005FA00: lw          $v0, 0x14($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X14);
    // 0x8005FA04: addiu       $v1, $v1, -0x1300
    ctx->r3 = ADD32(ctx->r3, -0X1300);
    // 0x8005FA08: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8005FA0C: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8005FA10: lw          $a0, 0x0($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X0);
    // 0x8005FA14: jal         0x80056EB0
    // 0x8005FA18: nop

    func_80056EB0(rdram, ctx);
        goto after_0;
    // 0x8005FA18: nop

    after_0:
    // 0x8005FA1C: lui         $v1, 0x800A
    ctx->r3 = S32(0X800A << 16);
    // 0x8005FA20: addiu       $v1, $v1, -0x12A0
    ctx->r3 = ADD32(ctx->r3, -0X12A0);
    // 0x8005FA24: sw          $v0, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r2;
    // 0x8005FA28: sw          $v1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r3;
    // 0x8005FA2C: addiu       $v0, $s1, 0x4
    ctx->r2 = ADD32(ctx->r17, 0X4);
    // 0x8005FA30: sw          $v0, 0x8($s3)
    MEM_W(0X8, ctx->r19) = ctx->r2;
    // 0x8005FA34: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x8005FA38: sw          $v0, 0xC($s3)
    MEM_W(0XC, ctx->r19) = ctx->r2;
    // 0x8005FA3C: lw          $v1, 0xC($s2)
    ctx->r3 = MEM_W(ctx->r18, 0XC);
    // 0x8005FA40: lw          $t0, 0x0($s2)
    ctx->r8 = MEM_W(ctx->r18, 0X0);
    // 0x8005FA44: lw          $t1, 0x4($s2)
    ctx->r9 = MEM_W(ctx->r18, 0X4);
    // 0x8005FA48: lw          $t2, 0x8($s2)
    ctx->r10 = MEM_W(ctx->r18, 0X8);
    // 0x8005FA4C: sw          $t0, 0x34($s1)
    MEM_W(0X34, ctx->r17) = ctx->r8;
    // 0x8005FA50: sw          $t1, 0x38($s1)
    MEM_W(0X38, ctx->r17) = ctx->r9;
    // 0x8005FA54: sw          $t2, 0x3C($s1)
    MEM_W(0X3C, ctx->r17) = ctx->r10;
    // 0x8005FA58: lw          $t0, 0xC($v1)
    ctx->r8 = MEM_W(ctx->r3, 0XC);
    // 0x8005FA5C: lw          $t1, 0x10($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X10);
    // 0x8005FA60: lw          $t2, 0x14($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X14);
    // 0x8005FA64: sw          $t0, 0x10($s1)
    MEM_W(0X10, ctx->r17) = ctx->r8;
    // 0x8005FA68: sw          $t1, 0x14($s1)
    MEM_W(0X14, ctx->r17) = ctx->r9;
    // 0x8005FA6C: sw          $t2, 0x18($s1)
    MEM_W(0X18, ctx->r17) = ctx->r10;
    // 0x8005FA70: lw          $t0, 0x18($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X18);
    // 0x8005FA74: lw          $t1, 0x1C($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X1C);
    // 0x8005FA78: lw          $t2, 0x20($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X20);
    // 0x8005FA7C: sw          $t0, 0x1C($s1)
    MEM_W(0X1C, ctx->r17) = ctx->r8;
    // 0x8005FA80: sw          $t1, 0x20($s1)
    MEM_W(0X20, ctx->r17) = ctx->r9;
    // 0x8005FA84: sw          $t2, 0x24($s1)
    MEM_W(0X24, ctx->r17) = ctx->r10;
    // 0x8005FA88: lwc1        $f0, 0xC($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0XC);
    // 0x8005FA8C: lwc1        $f2, 0x10($s2)
    ctx->f2.u32l = MEM_W(ctx->r18, 0X10);
    // 0x8005FA90: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x8005FA94: swc1        $f0, 0x28($s1)
    MEM_W(0X28, ctx->r17) = ctx->f0.u32l;
    // 0x8005FA98: lwc1        $f0, 0x10($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X10);
    // 0x8005FA9C: lwc1        $f2, 0x10($s2)
    ctx->f2.u32l = MEM_W(ctx->r18, 0X10);
    // 0x8005FAA0: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x8005FAA4: swc1        $f0, 0x2C($s1)
    MEM_W(0X2C, ctx->r17) = ctx->f0.u32l;
    // 0x8005FAA8: lwc1        $f0, 0x14($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X14);
    // 0x8005FAAC: lwc1        $f2, 0x10($s2)
    ctx->f2.u32l = MEM_W(ctx->r18, 0X10);
    // 0x8005FAB0: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x8005FAB4: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x8005FAB8: swc1        $f0, 0x30($s1)
    MEM_W(0X30, ctx->r17) = ctx->f0.u32l;
    // 0x8005FABC: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x8005FAC0: lwc1        $f10, 0x48($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X48);
    // 0x8005FAC4: sqrt.s      $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = sqrtf(ctx->f10.fl);
    // 0x8005FAC8: lwc1        $f0, 0x3C($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X3C);
    // 0x8005FACC: mul.s       $f4, $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x8005FAD0: lwc1        $f0, 0xC($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0XC);
    // 0x8005FAD4: mul.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x8005FAD8: lwc1        $f2, 0x0($v1)
    ctx->f2.u32l = MEM_W(ctx->r3, 0X0);
    // 0x8005FADC: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8005FAE0: lwc1        $f6, -0x4D6C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X4D6C);
    // 0x8005FAE4: add.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x8005FAE8: lwc1        $f0, 0x28($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X28);
    // 0x8005FAEC: div.s       $f0, $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f6.fl);
    // 0x8005FAF0: add.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x8005FAF4: swc1        $f2, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->f2.u32l;
    // 0x8005FAF8: lwc1        $f0, 0x10($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X10);
    // 0x8005FAFC: mul.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x8005FB00: lwc1        $f2, 0x4($v1)
    ctx->f2.u32l = MEM_W(ctx->r3, 0X4);
    // 0x8005FB04: add.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x8005FB08: lwc1        $f0, 0x2C($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X2C);
    // 0x8005FB0C: div.s       $f0, $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f6.fl);
    // 0x8005FB10: add.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x8005FB14: swc1        $f2, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->f2.u32l;
    // 0x8005FB18: lwc1        $f0, 0x14($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X14);
    // 0x8005FB1C: mul.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x8005FB20: lwc1        $f2, 0x8($v1)
    ctx->f2.u32l = MEM_W(ctx->r3, 0X8);
    // 0x8005FB24: add.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x8005FB28: lwc1        $f0, 0x30($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X30);
    // 0x8005FB2C: div.s       $f0, $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f6.fl);
    // 0x8005FB30: add.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x8005FB34: addiu       $a0, $s1, 0x28
    ctx->r4 = ADD32(ctx->r17, 0X28);
    // 0x8005FB38: jal         0x8001CF2C
    // 0x8005FB3C: swc1        $f2, 0xC($s1)
    MEM_W(0XC, ctx->r17) = ctx->f2.u32l;
    func_8001CF2C(rdram, ctx);
        goto after_1;
    // 0x8005FB3C: swc1        $f2, 0xC($s1)
    MEM_W(0XC, ctx->r17) = ctx->f2.u32l;
    after_1:
    // 0x8005FB40: swc1        $f0, 0x58($s1)
    MEM_W(0X58, ctx->r17) = ctx->f0.u32l;
    // 0x8005FB44: sw          $zero, 0x5C($s1)
    MEM_W(0X5C, ctx->r17) = 0;
    // 0x8005FB48: lhu         $v0, 0x1C($s2)
    ctx->r2 = MEM_HU(ctx->r18, 0X1C);
    // 0x8005FB4C: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8005FB50: lwc1        $f0, -0x4D68($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X4D68);
    // 0x8005FB54: sh          $v0, 0x48($s1)
    MEM_H(0X48, ctx->r17) = ctx->r2;
    // 0x8005FB58: lhu         $v0, 0x18($s2)
    ctx->r2 = MEM_HU(ctx->r18, 0X18);
    // 0x8005FB5C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8005FB60: sw          $zero, 0x40($s1)
    MEM_W(0X40, ctx->r17) = 0;
    // 0x8005FB64: swc1        $f0, 0x70($s1)
    MEM_W(0X70, ctx->r17) = ctx->f0.u32l;
    // 0x8005FB68: sh          $v0, 0x44($s1)
    MEM_H(0X44, ctx->r17) = ctx->r2;
    // 0x8005FB6C: lhu         $v1, 0x16($s2)
    ctx->r3 = MEM_HU(ctx->r18, 0X16);
    // 0x8005FB70: ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
    // 0x8005FB74: sh          $v0, 0x4C($s1)
    MEM_H(0X4C, ctx->r17) = ctx->r2;
    // 0x8005FB78: sh          $v1, 0x4A($s1)
    MEM_H(0X4A, ctx->r17) = ctx->r3;
    // 0x8005FB7C: lh          $v1, 0x4A($s1)
    ctx->r3 = MEM_H(ctx->r17, 0X4A);
    // 0x8005FB80: addiu       $v0, $zero, 0xE
    ctx->r2 = ADD32(0, 0XE);
    // 0x8005FB84: sb          $zero, 0x51($s1)
    MEM_B(0X51, ctx->r17) = 0;
    // 0x8005FB88: sb          $zero, 0x50($s1)
    MEM_B(0X50, ctx->r17) = 0;
    // 0x8005FB8C: sb          $zero, 0x52($s1)
    MEM_B(0X52, ctx->r17) = 0;
    // 0x8005FB90: sw          $zero, 0x60($s1)
    MEM_W(0X60, ctx->r17) = 0;
    // 0x8005FB94: sw          $zero, 0x64($s1)
    MEM_W(0X64, ctx->r17) = 0;
    // 0x8005FB98: bne         $v1, $v0, L_8005FBAC
    if (ctx->r3 != ctx->r2) {
        // 0x8005FB9C: sb          $a0, 0x53($s1)
        MEM_B(0X53, ctx->r17) = ctx->r4;
            goto L_8005FBAC;
    }
    // 0x8005FB9C: sb          $a0, 0x53($s1)
    MEM_B(0X53, ctx->r17) = ctx->r4;
    // 0x8005FBA0: swc1        $f0, 0x54($s1)
    MEM_W(0X54, ctx->r17) = ctx->f0.u32l;
    // 0x8005FBA4: j           L_8005FBBC
    // 0x8005FBA8: sb          $a0, 0xC1($s1)
    MEM_B(0XC1, ctx->r17) = ctx->r4;
        goto L_8005FBBC;
    // 0x8005FBA8: sb          $a0, 0xC1($s1)
    MEM_B(0XC1, ctx->r17) = ctx->r4;
L_8005FBAC:
    // 0x8005FBAC: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8005FBB0: lwc1        $f0, -0x4D64($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X4D64);
    // 0x8005FBB4: sb          $zero, 0xC1($s1)
    MEM_B(0XC1, ctx->r17) = 0;
    // 0x8005FBB8: swc1        $f0, 0x54($s1)
    MEM_W(0X54, ctx->r17) = ctx->f0.u32l;
L_8005FBBC:
    // 0x8005FBBC: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8005FBC0: lbu         $v0, 0xB39($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0XB39);
    // 0x8005FBC4: beq         $v0, $zero, L_8005FBD8
    if (ctx->r2 == 0) {
        // 0x8005FBC8: nop
    
            goto L_8005FBD8;
    }
    // 0x8005FBC8: nop

    // 0x8005FBCC: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8005FBD0: lwc1        $f0, -0x4D60($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X4D60);
    // 0x8005FBD4: swc1        $f0, 0x54($s1)
    MEM_W(0X54, ctx->r17) = ctx->f0.u32l;
L_8005FBD8:
    // 0x8005FBD8: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8005FBDC: lwc1        $f0, -0x4D5C($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X4D5C);
    // 0x8005FBE0: lwc1        $f2, 0x4($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0X4);
    // 0x8005FBE4: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // 0x8005FBE8: sb          $v0, 0xC0($s1)
    MEM_B(0XC0, ctx->r17) = ctx->r2;
    // 0x8005FBEC: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x8005FBF0: sb          $zero, 0xC2($s1)
    MEM_B(0XC2, ctx->r17) = 0;
    // 0x8005FBF4: sb          $zero, 0xC3($s1)
    MEM_B(0XC3, ctx->r17) = 0;
    // 0x8005FBF8: sb          $zero, 0x7A($s1)
    MEM_B(0X7A, ctx->r17) = 0;
    // 0x8005FBFC: sb          $zero, 0x7B($s1)
    MEM_B(0X7B, ctx->r17) = 0;
    // 0x8005FC00: lw          $v0, -0x68C0($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X68C0);
    // 0x8005FC04: lui         $v1, 0x800A
    ctx->r3 = S32(0X800A << 16);
    // 0x8005FC08: sw          $zero, 0x74($s1)
    MEM_W(0X74, ctx->r17) = 0;
    // 0x8005FC0C: swc1        $f0, 0x68($s1)
    MEM_W(0X68, ctx->r17) = ctx->f0.u32l;
    // 0x8005FC10: swc1        $f0, 0x6C($s1)
    MEM_W(0X6C, ctx->r17) = ctx->f0.u32l;
    // 0x8005FC14: swc1        $f2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f2.u32l;
    // 0x8005FC18: lwc1        $f0, 0x8($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X8);
    // 0x8005FC1C: addiu       $v1, $v1, -0x1310
    ctx->r3 = ADD32(ctx->r3, -0X1310);
    // 0x8005FC20: swc1        $f0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f0.u32l;
    // 0x8005FC24: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8005FC28: lwc1        $f0, -0x4D58($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X4D58);
    // 0x8005FC2C: lwc1        $f2, 0xC($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0XC);
    // 0x8005FC30: lui         $a0, 0x8005
    ctx->r4 = S32(0X8005 << 16);
    // 0x8005FC34: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
    // 0x8005FC38: swc1        $f0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f0.u32l;
    // 0x8005FC3C: swc1        $f2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f2.u32l;
    // 0x8005FC40: lh          $v0, 0x4A($s1)
    ctx->r2 = MEM_H(ctx->r17, 0X4A);
    // 0x8005FC44: addiu       $a0, $a0, -0x3938
    ctx->r4 = ADD32(ctx->r4, -0X3938);
    // 0x8005FC48: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8005FC4C: lbu         $v0, 0x0($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X0);
    // 0x8005FC50: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    // 0x8005FC54: sb          $v0, 0x40($sp)
    MEM_B(0X40, ctx->r29) = ctx->r2;
    // 0x8005FC58: lh          $v0, 0x4A($s1)
    ctx->r2 = MEM_H(ctx->r17, 0X4A);
    // 0x8005FC5C: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8005FC60: lwc1        $f0, -0x4D54($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X4D54);
    // 0x8005FC64: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8005FC68: lbu         $v1, 0x0($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X0);
    // 0x8005FC6C: addiu       $v0, $zero, 0x100
    ctx->r2 = ADD32(0, 0X100);
    // 0x8005FC70: swc1        $f0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f0.u32l;
    // 0x8005FC74: sh          $v0, 0x38($sp)
    MEM_H(0X38, ctx->r29) = ctx->r2;
    // 0x8005FC78: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
    // 0x8005FC7C: sb          $v1, 0x41($sp)
    MEM_B(0X41, ctx->r29) = ctx->r3;
    // 0x8005FC80: lbu         $a3, 0x19($s3)
    ctx->r7 = MEM_BU(ctx->r19, 0X19);
    // 0x8005FC84: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x8005FC88: addiu       $a3, $a3, 0xA
    ctx->r7 = ADD32(ctx->r7, 0XA);
    // 0x8005FC8C: jal         0x8003FFEC
    // 0x8005FC90: andi        $a3, $a3, 0xFF
    ctx->r7 = ctx->r7 & 0XFF;
    func_8003FFEC(rdram, ctx);
        goto after_2;
    // 0x8005FC90: andi        $a3, $a3, 0xFF
    ctx->r7 = ctx->r7 & 0XFF;
    after_2:
    // 0x8005FC94: lh          $v1, 0x4A($s1)
    ctx->r3 = MEM_H(ctx->r17, 0X4A);
    // 0x8005FC98: sh          $v0, 0x46($s1)
    MEM_H(0X46, ctx->r17) = ctx->r2;
    // 0x8005FC9C: addiu       $v0, $zero, 0xD
    ctx->r2 = ADD32(0, 0XD);
    // 0x8005FCA0: beq         $v1, $v0, L_8005FCE4
    if (ctx->r3 == ctx->r2) {
        // 0x8005FCA4: slti        $v0, $v1, 0xE
        ctx->r2 = SIGNED(ctx->r3) < 0XE ? 1 : 0;
            goto L_8005FCE4;
    }
    // 0x8005FCA4: slti        $v0, $v1, 0xE
    ctx->r2 = SIGNED(ctx->r3) < 0XE ? 1 : 0;
    // 0x8005FCA8: beq         $v0, $zero, L_8005FCC0
    if (ctx->r2 == 0) {
        // 0x8005FCAC: addiu       $v0, $zero, 0xA
        ctx->r2 = ADD32(0, 0XA);
            goto L_8005FCC0;
    }
    // 0x8005FCAC: addiu       $v0, $zero, 0xA
    ctx->r2 = ADD32(0, 0XA);
    // 0x8005FCB0: beq         $v1, $v0, L_8005FCCC
    if (ctx->r3 == ctx->r2) {
        // 0x8005FCB4: addu        $a1, $s3, $zero
        ctx->r5 = ADD32(ctx->r19, 0);
            goto L_8005FCCC;
    }
    // 0x8005FCB4: addu        $a1, $s3, $zero
    ctx->r5 = ADD32(ctx->r19, 0);
    // 0x8005FCB8: j           L_8005FD04
    // 0x8005FCBC: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
        goto L_8005FD04;
    // 0x8005FCBC: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
L_8005FCC0:
    // 0x8005FCC0: addiu       $v0, $zero, 0xE
    ctx->r2 = ADD32(0, 0XE);
    // 0x8005FCC4: bne         $v1, $v0, L_8005FD00
    if (ctx->r3 != ctx->r2) {
        // 0x8005FCC8: addu        $a1, $s3, $zero
        ctx->r5 = ADD32(ctx->r19, 0);
            goto L_8005FD00;
    }
    // 0x8005FCC8: addu        $a1, $s3, $zero
    ctx->r5 = ADD32(ctx->r19, 0);
L_8005FCCC:
    // 0x8005FCCC: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8005FCD0: lui         $v1, 0x8014
    ctx->r3 = S32(0X8014 << 16);
    // 0x8005FCD4: lw          $v0, 0xC04($v0)
    ctx->r2 = MEM_W(ctx->r2, 0XC04);
    // 0x8005FCD8: lhu         $a0, -0x6A9A($v1)
    ctx->r4 = MEM_HU(ctx->r3, -0X6A9A);
    // 0x8005FCDC: j           L_8005FD14
    // 0x8005FCE0: addiu       $s0, $v0, 0x140
    ctx->r16 = ADD32(ctx->r2, 0X140);
        goto L_8005FD14;
    // 0x8005FCE0: addiu       $s0, $v0, 0x140
    ctx->r16 = ADD32(ctx->r2, 0X140);
L_8005FCE4:
    // 0x8005FCE4: addu        $a1, $s3, $zero
    ctx->r5 = ADD32(ctx->r19, 0);
    // 0x8005FCE8: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8005FCEC: lui         $v1, 0x8014
    ctx->r3 = S32(0X8014 << 16);
    // 0x8005FCF0: lw          $v0, 0xC04($v0)
    ctx->r2 = MEM_W(ctx->r2, 0XC04);
    // 0x8005FCF4: lhu         $a0, -0x6A9A($v1)
    ctx->r4 = MEM_HU(ctx->r3, -0X6A9A);
    // 0x8005FCF8: j           L_8005FD14
    // 0x8005FCFC: addiu       $s0, $v0, 0x180
    ctx->r16 = ADD32(ctx->r2, 0X180);
        goto L_8005FD14;
    // 0x8005FCFC: addiu       $s0, $v0, 0x180
    ctx->r16 = ADD32(ctx->r2, 0X180);
L_8005FD00:
    // 0x8005FD00: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
L_8005FD04:
    // 0x8005FD04: lui         $v1, 0x8014
    ctx->r3 = S32(0X8014 << 16);
    // 0x8005FD08: lw          $v0, 0xC04($v0)
    ctx->r2 = MEM_W(ctx->r2, 0XC04);
    // 0x8005FD0C: lhu         $a0, -0x6A98($v1)
    ctx->r4 = MEM_HU(ctx->r3, -0X6A98);
    // 0x8005FD10: addiu       $s0, $v0, 0x160
    ctx->r16 = ADD32(ctx->r2, 0X160);
L_8005FD14:
    // 0x8005FD14: jal         0x8003E684
    // 0x8005FD18: nop

    func_8003E684(rdram, ctx);
        goto after_3;
    // 0x8005FD18: nop

    after_3:
    // 0x8005FD1C: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x8005FD20: lhu         $a0, -0x6A84($v0)
    ctx->r4 = MEM_HU(ctx->r2, -0X6A84);
    // 0x8005FD24: jal         0x8003E684
    // 0x8005FD28: addu        $a1, $s3, $zero
    ctx->r5 = ADD32(ctx->r19, 0);
    func_8003E684(rdram, ctx);
        goto after_4;
    // 0x8005FD28: addu        $a1, $s3, $zero
    ctx->r5 = ADD32(ctx->r19, 0);
    after_4:
    // 0x8005FD2C: addiu       $a2, $zero, 0xC
    ctx->r6 = ADD32(0, 0XC);
    // 0x8005FD30: lui         $a1, 0x3CF5
    ctx->r5 = S32(0X3CF5 << 16);
    // 0x8005FD34: ori         $a1, $a1, 0xC28F
    ctx->r5 = ctx->r5 | 0XC28F;
    // 0x8005FD38: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8005FD3C: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8005FD40: lwc1        $f2, -0x4D50($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X4D50);
    // 0x8005FD44: addiu       $a3, $sp, 0x48
    ctx->r7 = ADD32(ctx->r29, 0X48);
    // 0x8005FD48: swc1        $f0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f0.u32l;
    // 0x8005FD4C: swc1        $f0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f0.u32l;
    // 0x8005FD50: swc1        $f2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f2.u32l;
    // 0x8005FD54: lhu         $a0, 0x16($s3)
    ctx->r4 = MEM_HU(ctx->r19, 0X16);
    // 0x8005FD58: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8005FD5C: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x8005FD60: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x8005FD64: jal         0x80072870
    // 0x8005FD68: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    func_80072870(rdram, ctx);
        goto after_5;
    // 0x8005FD68: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    after_5:
    // 0x8005FD6C: j           L_80060638
    // 0x8005FD70: sh          $v0, 0x78($s1)
    MEM_H(0X78, ctx->r17) = ctx->r2;
        goto L_80060638;
    // 0x8005FD70: sh          $v0, 0x78($s1)
    MEM_H(0X78, ctx->r17) = ctx->r2;
L_8005FD74:
    // 0x8005FD74: lhu         $v0, 0x46($s1)
    ctx->r2 = MEM_HU(ctx->r17, 0X46);
    // 0x8005FD78: ori         $s0, $zero, 0xFFFF
    ctx->r16 = 0 | 0XFFFF;
    // 0x8005FD7C: beq         $v0, $s0, L_8005FD8C
    if (ctx->r2 == ctx->r16) {
        // 0x8005FD80: nop
    
            goto L_8005FD8C;
    }
    // 0x8005FD80: nop

    // 0x8005FD84: jal         0x8003ED74
    // 0x8005FD88: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    func_8003ED74(rdram, ctx);
        goto after_6;
    // 0x8005FD88: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    after_6:
L_8005FD8C:
    // 0x8005FD8C: lbu         $v0, 0x7B($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X7B);
    // 0x8005FD90: addiu       $s2, $zero, 0x1
    ctx->r18 = ADD32(0, 0X1);
    // 0x8005FD94: bne         $v0, $s2, L_8005FDA8
    if (ctx->r2 != ctx->r18) {
        // 0x8005FD98: nop
    
            goto L_8005FDA8;
    }
    // 0x8005FD98: nop

    // 0x8005FD9C: sb          $zero, 0x7B($s1)
    MEM_B(0X7B, ctx->r17) = 0;
    // 0x8005FDA0: jal         0x80098DE0
    // 0x8005FDA4: addiu       $a0, $s1, 0x7C
    ctx->r4 = ADD32(ctx->r17, 0X7C);
    func_80098DE0(rdram, ctx);
        goto after_7;
    // 0x8005FDA4: addiu       $a0, $s1, 0x7C
    ctx->r4 = ADD32(ctx->r17, 0X7C);
    after_7:
L_8005FDA8:
    // 0x8005FDA8: lbu         $v1, 0xC0($s1)
    ctx->r3 = MEM_BU(ctx->r17, 0XC0);
    // 0x8005FDAC: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // 0x8005FDB0: beq         $v1, $v0, L_8005FDF8
    if (ctx->r3 == ctx->r2) {
        // 0x8005FDB4: sll         $v0, $v1, 4
        ctx->r2 = S32(ctx->r3 << 4);
            goto L_8005FDF8;
    }
    // 0x8005FDB4: sll         $v0, $v1, 4
    ctx->r2 = S32(ctx->r3 << 4);
    // 0x8005FDB8: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8005FDBC: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8005FDC0: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8005FDC4: addiu       $a0, $a0, -0x68B0
    ctx->r4 = ADD32(ctx->r4, -0X68B0);
    // 0x8005FDC8: jal         0x80098DE0
    // 0x8005FDCC: addu        $a0, $v0, $a0
    ctx->r4 = ADD32(ctx->r2, ctx->r4);
    func_80098DE0(rdram, ctx);
        goto after_8;
    // 0x8005FDCC: addu        $a0, $v0, $a0
    ctx->r4 = ADD32(ctx->r2, ctx->r4);
    after_8:
    // 0x8005FDD0: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8005FDD4: lbu         $v1, -0x67A0($a0)
    ctx->r3 = MEM_BU(ctx->r4, -0X67A0);
    // 0x8005FDD8: addiu       $v0, $v1, 0x1
    ctx->r2 = ADD32(ctx->r3, 0X1);
    // 0x8005FDDC: sb          $v0, -0x67A0($a0)
    MEM_B(-0X67A0, ctx->r4) = ctx->r2;
    // 0x8005FDE0: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x8005FDE4: addiu       $v0, $v0, -0x679C
    ctx->r2 = ADD32(ctx->r2, -0X679C);
    // 0x8005FDE8: andi        $v1, $v1, 0xFF
    ctx->r3 = ctx->r3 & 0XFF;
    // 0x8005FDEC: lbu         $a0, 0xC0($s1)
    ctx->r4 = MEM_BU(ctx->r17, 0XC0);
    // 0x8005FDF0: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x8005FDF4: sb          $a0, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r4;
L_8005FDF8:
    // 0x8005FDF8: lbu         $v0, 0x50($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X50);
    // 0x8005FDFC: bne         $v0, $s2, L_8005FE3C
    if (ctx->r2 != ctx->r18) {
        // 0x8005FE00: nop
    
            goto L_8005FE3C;
    }
    // 0x8005FE00: nop

    // 0x8005FE04: lhu         $v0, 0x4C($s1)
    ctx->r2 = MEM_HU(ctx->r17, 0X4C);
    // 0x8005FE08: beq         $v0, $s0, L_8005FE3C
    if (ctx->r2 == ctx->r16) {
        // 0x8005FE0C: addu        $a0, $v0, $zero
        ctx->r4 = ADD32(ctx->r2, 0);
            goto L_8005FE3C;
    }
    // 0x8005FE0C: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // 0x8005FE10: jal         0x8003FC28
    // 0x8005FE14: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    func_8003FC28(rdram, ctx);
        goto after_9;
    // 0x8005FE14: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    after_9:
    // 0x8005FE18: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x8005FE1C: beq         $v0, $s0, L_8005FE3C
    if (ctx->r2 == ctx->r16) {
        // 0x8005FE20: nop
    
            goto L_8005FE3C;
    }
    // 0x8005FE20: nop

    // 0x8005FE24: lhu         $a0, 0x4E($s1)
    ctx->r4 = MEM_HU(ctx->r17, 0X4E);
    // 0x8005FE28: jal         0x8004013C
    // 0x8005FE2C: nop

    func_8004013C(rdram, ctx);
        goto after_10;
    // 0x8005FE2C: nop

    after_10:
    // 0x8005FE30: lhu         $a0, 0x4E($s1)
    ctx->r4 = MEM_HU(ctx->r17, 0X4E);
    // 0x8005FE34: jal         0x8003E7D0
    // 0x8005FE38: addu        $a1, $v0, $zero
    ctx->r5 = ADD32(ctx->r2, 0);
    func_8003E7D0(rdram, ctx);
        goto after_11;
    // 0x8005FE38: addu        $a1, $v0, $zero
    ctx->r5 = ADD32(ctx->r2, 0);
    after_11:
L_8005FE3C:
    // 0x8005FE3C: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x8005FE40: jal         0x8005779C
    // 0x8005FE44: nop

    func_8005779C(rdram, ctx);
        goto after_12;
    // 0x8005FE44: nop

    after_12:
    // 0x8005FE48: j           L_8006063C
    // 0x8005FE4C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8006063C;
    // 0x8005FE4C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8005FE50:
    // 0x8005FE50: lwc1        $f20, 0x0($s2)
    ctx->f20.u32l = MEM_W(ctx->r18, 0X0);
    // 0x8005FE54: lwc1        $f0, 0x40($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X40);
    // 0x8005FE58: add.s       $f0, $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f20.fl;
    // 0x8005FE5C: lwc1        $f2, 0x70($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0X70);
    // 0x8005FE60: c.le.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl <= ctx->f0.fl;
    // 0x8005FE64: nop

    // 0x8005FE68: bc1f        L_8005FE80
    if (!c1cs) {
        // 0x8005FE6C: swc1        $f0, 0x40($s1)
        MEM_W(0X40, ctx->r17) = ctx->f0.u32l;
            goto L_8005FE80;
    }
    // 0x8005FE6C: swc1        $f0, 0x40($s1)
    MEM_W(0X40, ctx->r17) = ctx->f0.u32l;
    // 0x8005FE70: lbu         $v1, 0x51($s1)
    ctx->r3 = MEM_BU(ctx->r17, 0X51);
    // 0x8005FE74: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8005FE78: beql        $v1, $v0, L_8005FE80
    if (ctx->r3 == ctx->r2) {
        // 0x8005FE7C: sb          $v1, 0x50($s1)
        MEM_B(0X50, ctx->r17) = ctx->r3;
            goto L_8005FE80;
    }
    goto skip_0;
    // 0x8005FE7C: sb          $v1, 0x50($s1)
    MEM_B(0X50, ctx->r17) = ctx->r3;
    skip_0:
L_8005FE80:
    // 0x8005FE80: lbu         $v0, 0x52($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X52);
    // 0x8005FE84: bne         $v0, $zero, L_800600BC
    if (ctx->r2 != 0) {
        // 0x8005FE88: nop
    
            goto L_800600BC;
    }
    // 0x8005FE88: nop

    // 0x8005FE8C: lwc1        $f2, 0x40($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0X40);
    // 0x8005FE90: lwc1        $f0, 0x54($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X54);
    // 0x8005FE94: c.le.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl <= ctx->f2.fl;
    // 0x8005FE98: nop

    // 0x8005FE9C: bc1f        L_8005FEFC
    if (!c1cs) {
        // 0x8005FEA0: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_8005FEFC;
    }
    // 0x8005FEA0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8005FEA4: lbu         $v1, 0x7B($s1)
    ctx->r3 = MEM_BU(ctx->r17, 0X7B);
    // 0x8005FEA8: sb          $v0, 0x52($s1)
    MEM_B(0X52, ctx->r17) = ctx->r2;
    // 0x8005FEAC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8005FEB0: bne         $v1, $v0, L_8005FEC4
    if (ctx->r3 != ctx->r2) {
        // 0x8005FEB4: sw          $zero, 0x5C($s1)
        MEM_W(0X5C, ctx->r17) = 0;
            goto L_8005FEC4;
    }
    // 0x8005FEB4: sw          $zero, 0x5C($s1)
    MEM_W(0X5C, ctx->r17) = 0;
    // 0x8005FEB8: sb          $zero, 0x7B($s1)
    MEM_B(0X7B, ctx->r17) = 0;
    // 0x8005FEBC: jal         0x80098DE0
    // 0x8005FEC0: addiu       $a0, $s1, 0x7C
    ctx->r4 = ADD32(ctx->r17, 0X7C);
    func_80098DE0(rdram, ctx);
        goto after_13;
    // 0x8005FEC0: addiu       $a0, $s1, 0x7C
    ctx->r4 = ADD32(ctx->r17, 0X7C);
    after_13:
L_8005FEC4:
    // 0x8005FEC4: lhu         $v1, 0x78($s1)
    ctx->r3 = MEM_HU(ctx->r17, 0X78);
    // 0x8005FEC8: ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
    // 0x8005FECC: beq         $v1, $v0, L_8005FEDC
    if (ctx->r3 == ctx->r2) {
        // 0x8005FED0: nop
    
            goto L_8005FEDC;
    }
    // 0x8005FED0: nop

    // 0x8005FED4: jal         0x80072ACC
    // 0x8005FED8: addu        $a0, $v1, $zero
    ctx->r4 = ADD32(ctx->r3, 0);
    func_80072ACC(rdram, ctx);
        goto after_14;
    // 0x8005FED8: addu        $a0, $v1, $zero
    ctx->r4 = ADD32(ctx->r3, 0);
    after_14:
L_8005FEDC:
    // 0x8005FEDC: lbu         $v0, 0xC1($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0XC1);
    // 0x8005FEE0: beq         $v0, $zero, L_8005FEFC
    if (ctx->r2 == 0) {
        // 0x8005FEE4: nop
    
            goto L_8005FEFC;
    }
    // 0x8005FEE4: nop

    // 0x8005FEE8: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x8005FEEC: jal         0x8005F6A8
    // 0x8005FEF0: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    func_8005F6A8(rdram, ctx);
        goto after_15;
    // 0x8005FEF0: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    after_15:
    // 0x8005FEF4: j           L_800605D0
    // 0x8005FEF8: nop

        goto L_800605D0;
    // 0x8005FEF8: nop

L_8005FEFC:
    // 0x8005FEFC: lbu         $v0, 0x50($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X50);
    // 0x8005FF00: beq         $v0, $zero, L_8005FF14
    if (ctx->r2 == 0) {
        // 0x8005FF04: ori         $s0, $zero, 0xFFFF
        ctx->r16 = 0 | 0XFFFF;
            goto L_8005FF14;
    }
    // 0x8005FF04: ori         $s0, $zero, 0xFFFF
    ctx->r16 = 0 | 0XFFFF;
    // 0x8005FF08: lhu         $v0, 0x4C($s1)
    ctx->r2 = MEM_HU(ctx->r17, 0X4C);
    // 0x8005FF0C: bne         $v0, $s0, L_8005FF54
    if (ctx->r2 != ctx->r16) {
        // 0x8005FF10: nop
    
            goto L_8005FF54;
    }
    // 0x8005FF10: nop

L_8005FF14:
    // 0x8005FF14: lwc1        $f0, 0x28($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X28);
    // 0x8005FF18: mul.s       $f0, $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f20.fl);
    // 0x8005FF1C: lwc1        $f6, 0x2C($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X2C);
    // 0x8005FF20: mul.s       $f6, $f6, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = MUL_S(ctx->f6.fl, ctx->f20.fl);
    // 0x8005FF24: lwc1        $f8, 0x30($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X30);
    // 0x8005FF28: mul.s       $f8, $f8, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = MUL_S(ctx->f8.fl, ctx->f20.fl);
    // 0x8005FF2C: lwc1        $f4, 0x4($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X4);
    // 0x8005FF30: add.s       $f4, $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f0.fl;
    // 0x8005FF34: lwc1        $f2, 0x8($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0X8);
    // 0x8005FF38: add.s       $f2, $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f6.fl;
    // 0x8005FF3C: lwc1        $f0, 0xC($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0XC);
    // 0x8005FF40: add.s       $f0, $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f8.fl;
    // 0x8005FF44: swc1        $f4, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->f4.u32l;
    // 0x8005FF48: swc1        $f2, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->f2.u32l;
    // 0x8005FF4C: j           L_8005FFF8
    // 0x8005FF50: swc1        $f0, 0xC($s1)
    MEM_W(0XC, ctx->r17) = ctx->f0.u32l;
        goto L_8005FFF8;
    // 0x8005FF50: swc1        $f0, 0xC($s1)
    MEM_W(0XC, ctx->r17) = ctx->f0.u32l;
L_8005FF54:
    // 0x8005FF54: lhu         $a0, 0x4C($s1)
    ctx->r4 = MEM_HU(ctx->r17, 0X4C);
    // 0x8005FF58: jal         0x8003FC28
    // 0x8005FF5C: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    func_8003FC28(rdram, ctx);
        goto after_16;
    // 0x8005FF5C: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    after_16:
    // 0x8005FF60: andi        $a0, $v0, 0xFFFF
    ctx->r4 = ctx->r2 & 0XFFFF;
    // 0x8005FF64: beql        $a0, $s0, L_8005FF14
    if (ctx->r4 == ctx->r16) {
        // 0x8005FF68: sb          $zero, 0x50($s1)
        MEM_B(0X50, ctx->r17) = 0;
            goto L_8005FF14;
    }
    goto skip_1;
    // 0x8005FF68: sb          $zero, 0x50($s1)
    MEM_B(0X50, ctx->r17) = 0;
    skip_1:
    // 0x8005FF6C: jal         0x8004013C
    // 0x8005FF70: nop

    func_8004013C(rdram, ctx);
        goto after_17;
    // 0x8005FF70: nop

    after_17:
    // 0x8005FF74: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // 0x8005FF78: lw          $v0, 0xC($a0)
    ctx->r2 = MEM_W(ctx->r4, 0XC);
    // 0x8005FF7C: beq         $v0, $zero, L_8005FFE0
    if (ctx->r2 == 0) {
        // 0x8005FF80: addiu       $v1, $sp, 0x90
        ctx->r3 = ADD32(ctx->r29, 0X90);
            goto L_8005FFE0;
    }
    // 0x8005FF80: addiu       $v1, $sp, 0x90
    ctx->r3 = ADD32(ctx->r29, 0X90);
    // 0x8005FF84: lw          $v0, 0x8($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X8);
    // 0x8005FF88: addiu       $a1, $v0, 0x30
    ctx->r5 = ADD32(ctx->r2, 0X30);
L_8005FF8C:
    // 0x8005FF8C: lw          $t0, 0x0($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X0);
    // 0x8005FF90: lw          $t1, 0x4($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X4);
    // 0x8005FF94: lw          $t2, 0x8($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X8);
    // 0x8005FF98: lw          $t3, 0xC($v0)
    ctx->r11 = MEM_W(ctx->r2, 0XC);
    // 0x8005FF9C: sw          $t0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r8;
    // 0x8005FFA0: sw          $t1, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r9;
    // 0x8005FFA4: sw          $t2, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r10;
    // 0x8005FFA8: sw          $t3, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r11;
    // 0x8005FFAC: addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
    // 0x8005FFB0: bne         $v0, $a1, L_8005FF8C
    if (ctx->r2 != ctx->r5) {
        // 0x8005FFB4: addiu       $v1, $v1, 0x10
        ctx->r3 = ADD32(ctx->r3, 0X10);
            goto L_8005FF8C;
    }
    // 0x8005FFB4: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
    // 0x8005FFB8: addiu       $s0, $sp, 0x90
    ctx->r16 = ADD32(ctx->r29, 0X90);
    // 0x8005FFBC: lw          $a0, 0xC($a0)
    ctx->r4 = MEM_W(ctx->r4, 0XC);
    // 0x8005FFC0: jal         0x8006AC7C
    // 0x8005FFC4: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    func_8006AC7C(rdram, ctx);
        goto after_18;
    // 0x8005FFC4: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    after_18:
    // 0x8005FFC8: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x8005FFCC: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x8005FFD0: jal         0x8005EE70
    // 0x8005FFD4: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    func_8005EE70(rdram, ctx);
        goto after_19;
    // 0x8005FFD4: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    after_19:
    // 0x8005FFD8: j           L_8005FFFC
    // 0x8005FFDC: addiu       $a3, $zero, -0x1
    ctx->r7 = ADD32(0, -0X1);
        goto L_8005FFFC;
    // 0x8005FFDC: addiu       $a3, $zero, -0x1
    ctx->r7 = ADD32(0, -0X1);
L_8005FFE0:
    // 0x8005FFE0: lw          $a1, 0x8($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X8);
    // 0x8005FFE4: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x8005FFE8: jal         0x8005EE70
    // 0x8005FFEC: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    func_8005EE70(rdram, ctx);
        goto after_20;
    // 0x8005FFEC: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    after_20:
    // 0x8005FFF0: j           L_8005FFFC
    // 0x8005FFF4: addiu       $a3, $zero, -0x1
    ctx->r7 = ADD32(0, -0X1);
        goto L_8005FFFC;
    // 0x8005FFF4: addiu       $a3, $zero, -0x1
    ctx->r7 = ADD32(0, -0X1);
L_8005FFF8:
    // 0x8005FFF8: addiu       $a3, $zero, -0x1
    ctx->r7 = ADD32(0, -0X1);
L_8005FFFC:
    // 0x8005FFFC: lwc1        $f2, 0x40($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0X40);
    // 0x80060000: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80060004: lwc1        $f0, -0x4D4C($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X4D4C);
    // 0x80060008: lhu         $a1, 0x16($s3)
    ctx->r5 = MEM_HU(ctx->r19, 0X16);
    // 0x8006000C: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x80060010: nop

    // 0x80060014: bc1f        L_80060020
    if (!c1cs) {
        // 0x80060018: addiu       $a0, $s1, 0x4
        ctx->r4 = ADD32(ctx->r17, 0X4);
            goto L_80060020;
    }
    // 0x80060018: addiu       $a0, $s1, 0x4
    ctx->r4 = ADD32(ctx->r17, 0X4);
    // 0x8006001C: lhu         $a3, 0x44($s1)
    ctx->r7 = MEM_HU(ctx->r17, 0X44);
L_80060020:
    // 0x80060020: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x80060024: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x80060028: lhu         $v0, -0x6A84($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X6A84);
    // 0x8006002C: addiu       $s2, $sp, 0x58
    ctx->r18 = ADD32(ctx->r29, 0X58);
    // 0x80060030: sw          $s2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r18;
    // 0x80060034: jal         0x8005EA9C
    // 0x80060038: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    func_8005EA9C(rdram, ctx);
        goto after_21;
    // 0x80060038: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    after_21:
    // 0x8006003C: andi        $s0, $v0, 0xFFFF
    ctx->r16 = ctx->r2 & 0XFFFF;
    // 0x80060040: ori         $s4, $zero, 0xFFFF
    ctx->r20 = 0 | 0XFFFF;
    // 0x80060044: beq         $s0, $s4, L_800600CC
    if (ctx->r16 == ctx->r20) {
        // 0x80060048: lui         $a2, 0x8014
        ctx->r6 = S32(0X8014 << 16);
            goto L_800600CC;
    }
    // 0x80060048: lui         $a2, 0x8014
    ctx->r6 = S32(0X8014 << 16);
    // 0x8006004C: jal         0x8006C994
    // 0x80060050: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    func_8006C994(rdram, ctx);
        goto after_22;
    // 0x80060050: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    after_22:
    // 0x80060054: lhu         $v1, 0x44($s1)
    ctx->r3 = MEM_HU(ctx->r17, 0X44);
    // 0x80060058: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x8006005C: bne         $v1, $v0, L_80060074
    if (ctx->r3 != ctx->r2) {
        // 0x80060060: lui         $v1, 0x8013
        ctx->r3 = S32(0X8013 << 16);
            goto L_80060074;
    }
    // 0x80060060: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x80060064: addiu       $v1, $v1, 0xB78
    ctx->r3 = ADD32(ctx->r3, 0XB78);
    // 0x80060068: lw          $v0, 0x8($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X8);
    // 0x8006006C: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80060070: sw          $v0, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r2;
L_80060074:
    // 0x80060074: lhu         $v0, 0x16($s3)
    ctx->r2 = MEM_HU(ctx->r19, 0X16);
    // 0x80060078: sh          $v0, 0x80($sp)
    MEM_H(0X80, ctx->r29) = ctx->r2;
    // 0x8006007C: lhu         $v0, 0x44($s1)
    ctx->r2 = MEM_HU(ctx->r17, 0X44);
    // 0x80060080: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x80060084: sh          $v0, 0x82($sp)
    MEM_H(0X82, ctx->r29) = ctx->r2;
    // 0x80060088: lhu         $v0, 0x4A($s1)
    ctx->r2 = MEM_HU(ctx->r17, 0X4A);
    // 0x8006008C: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    // 0x80060090: sh          $v0, 0x84($sp)
    MEM_H(0X84, ctx->r29) = ctx->r2;
    // 0x80060094: lhu         $v0, 0x48($s1)
    ctx->r2 = MEM_HU(ctx->r17, 0X48);
    // 0x80060098: addiu       $a2, $sp, 0x80
    ctx->r6 = ADD32(ctx->r29, 0X80);
    // 0x8006009C: sw          $s2, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r18;
    // 0x800600A0: jal         0x8003E8DC
    // 0x800600A4: sh          $v0, 0x86($sp)
    MEM_H(0X86, ctx->r29) = ctx->r2;
    func_8003E8DC(rdram, ctx);
        goto after_23;
    // 0x800600A4: sh          $v0, 0x86($sp)
    MEM_H(0X86, ctx->r29) = ctx->r2;
    after_23:
    // 0x800600A8: lhu         $v0, 0x80($sp)
    ctx->r2 = MEM_HU(ctx->r29, 0X80);
    // 0x800600AC: beq         $v0, $s4, L_800600F8
    if (ctx->r2 == ctx->r20) {
        // 0x800600B0: lui         $a2, 0x8014
        ctx->r6 = S32(0X8014 << 16);
            goto L_800600F8;
    }
    // 0x800600B0: lui         $a2, 0x8014
    ctx->r6 = S32(0X8014 << 16);
    // 0x800600B4: j           L_800600D0
    // 0x800600B8: addiu       $a2, $a2, -0x7FA8
    ctx->r6 = ADD32(ctx->r6, -0X7FA8);
        goto L_800600D0;
    // 0x800600B8: addiu       $a2, $a2, -0x7FA8
    ctx->r6 = ADD32(ctx->r6, -0X7FA8);
L_800600BC:
    // 0x800600BC: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x800600C0: jal         0x8005F480
    // 0x800600C4: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    func_8005F480(rdram, ctx);
        goto after_24;
    // 0x800600C4: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    after_24:
    // 0x800600C8: lui         $a2, 0x8014
    ctx->r6 = S32(0X8014 << 16);
L_800600CC:
    // 0x800600CC: addiu       $a2, $a2, -0x7FA8
    ctx->r6 = ADD32(ctx->r6, -0X7FA8);
L_800600D0:
    // 0x800600D0: lwc1        $f12, 0x4($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X4);
    // 0x800600D4: lwc1        $f14, 0xC($s1)
    ctx->f14.u32l = MEM_W(ctx->r17, 0XC);
    // 0x800600D8: jal         0x80067D90
    // 0x800600DC: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    func_80067D90(rdram, ctx);
        goto after_25;
    // 0x800600DC: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    after_25:
    // 0x800600E0: lwc1        $f2, 0x8($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0X8);
    // 0x800600E4: c.le.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl <= ctx->f2.fl;
    // 0x800600E8: nop

    // 0x800600EC: bc1f        L_8006015C
    if (!c1cs) {
        // 0x800600F0: ori         $v0, $zero, 0xFFFF
        ctx->r2 = 0 | 0XFFFF;
            goto L_8006015C;
    }
    // 0x800600F0: ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
    // 0x800600F4: swc1        $f0, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->f0.u32l;
L_800600F8:
    // 0x800600F8: addiu       $s0, $s1, 0x4
    ctx->r16 = ADD32(ctx->r17, 0X4);
    // 0x800600FC: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x80060100: sw          $zero, 0x90($sp)
    MEM_W(0X90, ctx->r29) = 0;
    // 0x80060104: sw          $zero, 0x94($sp)
    MEM_W(0X94, ctx->r29) = 0;
    // 0x80060108: jal         0x80061268
    // 0x8006010C: sw          $zero, 0x98($sp)
    MEM_W(0X98, ctx->r29) = 0;
    func_80061268(rdram, ctx);
        goto after_26;
    // 0x8006010C: sw          $zero, 0x98($sp)
    MEM_W(0X98, ctx->r29) = 0;
    after_26:
    // 0x80060110: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x80060114: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x80060118: addiu       $a2, $sp, 0x90
    ctx->r6 = ADD32(ctx->r29, 0X90);
    // 0x8006011C: lui         $a3, 0x41C0
    ctx->r7 = S32(0X41C0 << 16);
    // 0x80060120: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80060124: lwc1        $f0, -0x4D48($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X4D48);
    // 0x80060128: addiu       $v0, $zero, 0x21
    ctx->r2 = ADD32(0, 0X21);
    // 0x8006012C: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // 0x80060130: addiu       $v0, $zero, 0x7D
    ctx->r2 = ADD32(0, 0X7D);
    // 0x80060134: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x80060138: addiu       $v0, $zero, 0x50
    ctx->r2 = ADD32(0, 0X50);
    // 0x8006013C: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x80060140: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x80060144: jal         0x800989D8
    // 0x80060148: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    func_800989D8(rdram, ctx);
        goto after_27;
    // 0x80060148: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    after_27:
    // 0x8006014C: jal         0x8005EBD8
    // 0x80060150: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_8005EBD8(rdram, ctx);
        goto after_28;
    // 0x80060150: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_28:
    // 0x80060154: j           L_800605D0
    // 0x80060158: nop

        goto L_800605D0;
    // 0x80060158: nop

L_8006015C:
    // 0x8006015C: lhu         $v1, 0x46($s1)
    ctx->r3 = MEM_HU(ctx->r17, 0X46);
    // 0x80060160: beq         $v1, $v0, L_800601A0
    if (ctx->r3 == ctx->r2) {
        // 0x80060164: addiu       $a1, $zero, 0x1000
        ctx->r5 = ADD32(0, 0X1000);
            goto L_800601A0;
    }
    // 0x80060164: addiu       $a1, $zero, 0x1000
    ctx->r5 = ADD32(0, 0X1000);
    // 0x80060168: lwc1        $f0, 0x4($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X4);
    // 0x8006016C: swc1        $f0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f0.u32l;
    // 0x80060170: lwc1        $f0, 0x8($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X8);
    // 0x80060174: swc1        $f0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f0.u32l;
    // 0x80060178: lwc1        $f2, 0xC($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0XC);
    // 0x8006017C: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80060180: lwc1        $f0, -0x4D44($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X4D44);
    // 0x80060184: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80060188: sh          $v0, 0x38($sp)
    MEM_H(0X38, ctx->r29) = ctx->r2;
    // 0x8006018C: swc1        $f0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f0.u32l;
    // 0x80060190: swc1        $f2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f2.u32l;
    // 0x80060194: lhu         $a0, 0x46($s1)
    ctx->r4 = MEM_HU(ctx->r17, 0X46);
    // 0x80060198: jal         0x8003E8DC
    // 0x8006019C: addiu       $a2, $sp, 0x28
    ctx->r6 = ADD32(ctx->r29, 0X28);
    func_8003E8DC(rdram, ctx);
        goto after_29;
    // 0x8006019C: addiu       $a2, $sp, 0x28
    ctx->r6 = ADD32(ctx->r29, 0X28);
    after_29:
L_800601A0:
    // 0x800601A0: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x800601A4: lwc1        $f2, 0x4($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0X4);
    // 0x800601A8: lwc1        $f0, -0x64A8($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, -0X64A8);
    // 0x800601AC: sub.s       $f0, $f2, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f2.fl - ctx->f0.fl;
    // 0x800601B0: mul.s       $f6, $f0, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x800601B4: addiu       $v0, $v0, -0x64A8
    ctx->r2 = ADD32(ctx->r2, -0X64A8);
    // 0x800601B8: lwc1        $f2, 0x8($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0X8);
    // 0x800601BC: lwc1        $f0, 0x4($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X4);
    // 0x800601C0: sub.s       $f0, $f2, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f2.fl - ctx->f0.fl;
    // 0x800601C4: mul.s       $f4, $f0, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x800601C8: lwc1        $f2, 0xC($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0XC);
    // 0x800601CC: lwc1        $f0, 0x8($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X8);
    // 0x800601D0: sub.s       $f0, $f2, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f2.fl - ctx->f0.fl;
    // 0x800601D4: mul.s       $f0, $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x800601D8: add.s       $f6, $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f4.fl;
    // 0x800601DC: addiu       $s0, $zero, 0xFF
    ctx->r16 = ADD32(0, 0XFF);
    // 0x800601E0: lbu         $v0, 0xC0($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0XC0);
    // 0x800601E4: beq         $v0, $s0, L_80060284
    if (ctx->r2 == ctx->r16) {
        // 0x800601E8: add.s       $f6, $f6, $f0
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f0.fl;
            goto L_80060284;
    }
    // 0x800601E8: add.s       $f6, $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f0.fl;
    // 0x800601EC: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x800601F0: lwc1        $f0, -0x4D40($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X4D40);
    // 0x800601F4: c.lt.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl < ctx->f6.fl;
    // 0x800601F8: nop

    // 0x800601FC: bc1f        L_80060250
    if (!c1cs) {
        // 0x80060200: addu        $v1, $v0, $zero
        ctx->r3 = ADD32(ctx->r2, 0);
            goto L_80060250;
    }
    // 0x80060200: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // 0x80060204: sll         $v0, $v1, 4
    ctx->r2 = S32(ctx->r3 << 4);
    // 0x80060208: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8006020C: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80060210: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80060214: addiu       $a0, $a0, -0x68B0
    ctx->r4 = ADD32(ctx->r4, -0X68B0);
    // 0x80060218: jal         0x80098DE0
    // 0x8006021C: addu        $a0, $v0, $a0
    ctx->r4 = ADD32(ctx->r2, ctx->r4);
    func_80098DE0(rdram, ctx);
        goto after_30;
    // 0x8006021C: addu        $a0, $v0, $a0
    ctx->r4 = ADD32(ctx->r2, ctx->r4);
    after_30:
    // 0x80060220: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80060224: lbu         $v1, -0x67A0($a0)
    ctx->r3 = MEM_BU(ctx->r4, -0X67A0);
    // 0x80060228: addiu       $v0, $v1, 0x1
    ctx->r2 = ADD32(ctx->r3, 0X1);
    // 0x8006022C: sb          $v0, -0x67A0($a0)
    MEM_B(-0X67A0, ctx->r4) = ctx->r2;
    // 0x80060230: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x80060234: addiu       $v0, $v0, -0x679C
    ctx->r2 = ADD32(ctx->r2, -0X679C);
    // 0x80060238: andi        $v1, $v1, 0xFF
    ctx->r3 = ctx->r3 & 0XFF;
    // 0x8006023C: lbu         $a0, 0xC0($s1)
    ctx->r4 = MEM_BU(ctx->r17, 0XC0);
    // 0x80060240: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x80060244: sb          $a0, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r4;
    // 0x80060248: j           L_80060638
    // 0x8006024C: sb          $s0, 0xC0($s1)
    MEM_B(0XC0, ctx->r17) = ctx->r16;
        goto L_80060638;
    // 0x8006024C: sb          $s0, 0xC0($s1)
    MEM_B(0XC0, ctx->r17) = ctx->r16;
L_80060250:
    // 0x80060250: addiu       $a1, $s1, 0x4
    ctx->r5 = ADD32(ctx->r17, 0X4);
    // 0x80060254: addiu       $a2, $s1, 0x28
    ctx->r6 = ADD32(ctx->r17, 0X28);
    // 0x80060258: lbu         $v1, 0xC0($s1)
    ctx->r3 = MEM_BU(ctx->r17, 0XC0);
    // 0x8006025C: addiu       $a3, $zero, 0x50
    ctx->r7 = ADD32(0, 0X50);
    // 0x80060260: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80060264: addiu       $a0, $a0, -0x68B0
    ctx->r4 = ADD32(ctx->r4, -0X68B0);
    // 0x80060268: sll         $v0, $v1, 4
    ctx->r2 = S32(ctx->r3 << 4);
    // 0x8006026C: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80060270: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80060274: jal         0x800988E8
    // 0x80060278: addu        $a0, $v0, $a0
    ctx->r4 = ADD32(ctx->r2, ctx->r4);
    func_800988E8(rdram, ctx);
        goto after_31;
    // 0x80060278: addu        $a0, $v0, $a0
    ctx->r4 = ADD32(ctx->r2, ctx->r4);
    after_31:
    // 0x8006027C: j           L_8006063C
    // 0x80060280: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8006063C;
    // 0x80060280: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80060284:
    // 0x80060284: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x80060288: lbu         $v1, -0x67A0($v0)
    ctx->r3 = MEM_BU(ctx->r2, -0X67A0);
    // 0x8006028C: beql        $v1, $zero, L_8006063C
    if (ctx->r3 == 0) {
        // 0x80060290: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_8006063C;
    }
    goto skip_2;
    // 0x80060290: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_2:
    // 0x80060294: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80060298: lwc1        $f0, -0x4D3C($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X4D3C);
    // 0x8006029C: c.lt.s      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.fl < ctx->f0.fl;
    // 0x800602A0: nop

    // 0x800602A4: bc1f        L_80060638
    if (!c1cs) {
        // 0x800602A8: addiu       $v1, $v1, -0x1
        ctx->r3 = ADD32(ctx->r3, -0X1);
            goto L_80060638;
    }
    // 0x800602A8: addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
    // 0x800602AC: sb          $v1, -0x67A0($v0)
    MEM_B(-0X67A0, ctx->r2) = ctx->r3;
    // 0x800602B0: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x800602B4: addiu       $v0, $v0, -0x679C
    ctx->r2 = ADD32(ctx->r2, -0X679C);
    // 0x800602B8: andi        $v1, $v1, 0xFF
    ctx->r3 = ctx->r3 & 0XFF;
    // 0x800602BC: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x800602C0: addiu       $a1, $s1, 0x4
    ctx->r5 = ADD32(ctx->r17, 0X4);
    // 0x800602C4: addiu       $a2, $s1, 0x28
    ctx->r6 = ADD32(ctx->r17, 0X28);
    // 0x800602C8: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x800602CC: lui         $a3, 0x3FC0
    ctx->r7 = S32(0X3FC0 << 16);
    // 0x800602D0: lbu         $v0, 0x0($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X0);
    // 0x800602D4: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x800602D8: lwc1        $f0, -0x4D38($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X4D38);
    // 0x800602DC: addiu       $a0, $a0, -0x68B0
    ctx->r4 = ADD32(ctx->r4, -0X68B0);
    // 0x800602E0: sb          $v0, 0xC0($s1)
    MEM_B(0XC0, ctx->r17) = ctx->r2;
    // 0x800602E4: andi        $v1, $v0, 0xFF
    ctx->r3 = ctx->r2 & 0XFF;
    // 0x800602E8: addiu       $v0, $zero, 0xF
    ctx->r2 = ADD32(0, 0XF);
    // 0x800602EC: sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    // 0x800602F0: addiu       $v0, $zero, 0x33
    ctx->r2 = ADD32(0, 0X33);
    // 0x800602F4: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // 0x800602F8: addiu       $v0, $zero, 0xA
    ctx->r2 = ADD32(0, 0XA);
    // 0x800602FC: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x80060300: addiu       $v0, $zero, 0x50
    ctx->r2 = ADD32(0, 0X50);
    // 0x80060304: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x80060308: addiu       $v0, $zero, 0x14
    ctx->r2 = ADD32(0, 0X14);
    // 0x8006030C: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x80060310: sll         $v0, $v1, 4
    ctx->r2 = S32(ctx->r3 << 4);
    // 0x80060314: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80060318: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8006031C: addu        $a0, $v0, $a0
    ctx->r4 = ADD32(ctx->r2, ctx->r4);
    // 0x80060320: jal         0x80098BDC
    // 0x80060324: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    func_80098BDC(rdram, ctx);
        goto after_32;
    // 0x80060324: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    after_32:
    // 0x80060328: j           L_8006063C
    // 0x8006032C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8006063C;
    // 0x8006032C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80060330:
    // 0x80060330: addiu       $s0, $s1, 0x4
    ctx->r16 = ADD32(ctx->r17, 0X4);
    // 0x80060334: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x80060338: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x8006033C: addiu       $a2, $s1, 0x34
    ctx->r6 = ADD32(ctx->r17, 0X34);
    // 0x80060340: jal         0x80059C24
    // 0x80060344: addiu       $a0, $a0, 0x28
    ctx->r4 = ADD32(ctx->r4, 0X28);
    func_80059C24(rdram, ctx);
        goto after_33;
    // 0x80060344: addiu       $a0, $a0, 0x28
    ctx->r4 = ADD32(ctx->r4, 0X28);
    after_33:
    // 0x80060348: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    // 0x8006034C: lw          $a1, 0x0($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X0);
    // 0x80060350: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x80060354: jal         0x80057C8C
    // 0x80060358: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    func_80057C8C(rdram, ctx);
        goto after_34;
    // 0x80060358: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    after_34:
    // 0x8006035C: lbu         $v0, 0x7B($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X7B);
    // 0x80060360: beq         $v0, $zero, L_80060638
    if (ctx->r2 == 0) {
        // 0x80060364: addiu       $a0, $s1, 0x7C
        ctx->r4 = ADD32(ctx->r17, 0X7C);
            goto L_80060638;
    }
    // 0x80060364: addiu       $a0, $s1, 0x7C
    ctx->r4 = ADD32(ctx->r17, 0X7C);
    // 0x80060368: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x8006036C: addiu       $a2, $s1, 0x28
    ctx->r6 = ADD32(ctx->r17, 0X28);
    // 0x80060370: jal         0x800988E8
    // 0x80060374: addiu       $a3, $zero, 0x28
    ctx->r7 = ADD32(0, 0X28);
    func_800988E8(rdram, ctx);
        goto after_35;
    // 0x80060374: addiu       $a3, $zero, 0x28
    ctx->r7 = ADD32(0, 0X28);
    after_35:
    // 0x80060378: j           L_8006063C
    // 0x8006037C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8006063C;
    // 0x8006037C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80060380:
    // 0x80060380: lh          $v1, 0x0($s2)
    ctx->r3 = MEM_H(ctx->r18, 0X0);
    // 0x80060384: sltiu       $v0, $v1, 0x6
    ctx->r2 = ctx->r3 < 0X6 ? 1 : 0;
    // 0x80060388: beq         $v0, $zero, L_80060638
    if (ctx->r2 == 0) {
        // 0x8006038C: addu        $s0, $s2, $zero
        ctx->r16 = ADD32(ctx->r18, 0);
            goto L_80060638;
    }
    // 0x8006038C: addu        $s0, $s2, $zero
    ctx->r16 = ADD32(ctx->r18, 0);
    // 0x80060390: lui         $v0, 0x8004
    ctx->r2 = S32(0X8004 << 16);
    // 0x80060394: addiu       $v0, $v0, -0x4D30
    ctx->r2 = ADD32(ctx->r2, -0X4D30);
    // 0x80060398: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x8006039C: addu        $v1, $v1, $v0
    gpr jr_addend_800603A4 = ctx->r3;
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x800603A0: lw          $v0, 0x0($v1)
    ctx->r2 = ADD32(ctx->r3, 0X0);
    // 0x800603A4: jr          $v0
    // 0x800603A8: nop

    switch (jr_addend_800603A4 >> 2) {
        case 0: goto L_800603AC; break;
        case 1: goto L_800604CC; break;
        case 2: goto L_80060638; break;
        case 3: goto L_800604C4; break;
        case 4: goto L_80060538; break;
        case 5: goto L_80060544; break;
        default: switch_error(__func__, 0x800603A4, 0x8003B2D0);
    }
    // 0x800603A8: nop

L_800603AC:
    // 0x800603AC: lh          $v1, 0x4A($s1)
    ctx->r3 = MEM_H(ctx->r17, 0X4A);
    // 0x800603B0: addiu       $v0, $zero, 0xE
    ctx->r2 = ADD32(0, 0XE);
    // 0x800603B4: bne         $v1, $v0, L_800603C8
    if (ctx->r3 != ctx->r2) {
        // 0x800603B8: ori         $s2, $zero, 0xFFFF
        ctx->r18 = 0 | 0XFFFF;
            goto L_800603C8;
    }
    // 0x800603B8: ori         $s2, $zero, 0xFFFF
    ctx->r18 = 0 | 0XFFFF;
    // 0x800603BC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800603C0: j           L_80060638
    // 0x800603C4: sb          $v0, 0xC3($s1)
    MEM_B(0XC3, ctx->r17) = ctx->r2;
        goto L_80060638;
    // 0x800603C4: sb          $v0, 0xC3($s1)
    MEM_B(0XC3, ctx->r17) = ctx->r2;
L_800603C8:
    // 0x800603C8: lhu         $v0, 0x2($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X2);
    // 0x800603CC: beq         $v0, $s2, L_8006063C
    if (ctx->r2 == ctx->r18) {
        // 0x800603D0: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_8006063C;
    }
    // 0x800603D0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800603D4: lhu         $v0, 0x4C($s1)
    ctx->r2 = MEM_HU(ctx->r17, 0X4C);
    // 0x800603D8: bne         $v0, $s2, L_800603F8
    if (ctx->r2 != ctx->r18) {
        // 0x800603DC: nop
    
            goto L_800603F8;
    }
    // 0x800603DC: nop

    // 0x800603E0: jal         0x8003E5F8
    // 0x800603E4: addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    func_8003E5F8(rdram, ctx);
        goto after_36;
    // 0x800603E4: addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    after_36:
    // 0x800603E8: sh          $v0, 0x4C($s1)
    MEM_H(0X4C, ctx->r17) = ctx->r2;
    // 0x800603EC: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x800603F0: beq         $v0, $s2, L_8006063C
    if (ctx->r2 == ctx->r18) {
        // 0x800603F4: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_8006063C;
    }
    // 0x800603F4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800603F8:
    // 0x800603F8: lhu         $a0, 0x2($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X2);
    // 0x800603FC: jal         0x8004013C
    // 0x80060400: nop

    func_8004013C(rdram, ctx);
        goto after_37;
    // 0x80060400: nop

    after_37:
    // 0x80060404: lhu         $a0, 0x4C($s1)
    ctx->r4 = MEM_HU(ctx->r17, 0X4C);
    // 0x80060408: jal         0x8003E684
    // 0x8006040C: addu        $a1, $v0, $zero
    ctx->r5 = ADD32(ctx->r2, 0);
    func_8003E684(rdram, ctx);
        goto after_38;
    // 0x8006040C: addu        $a1, $v0, $zero
    ctx->r5 = ADD32(ctx->r2, 0);
    after_38:
    // 0x80060410: sh          $v0, 0x4E($s1)
    MEM_H(0X4E, ctx->r17) = ctx->r2;
    // 0x80060414: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x80060418: beq         $v0, $s2, L_80060638
    if (ctx->r2 == ctx->r18) {
        // 0x8006041C: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80060638;
    }
    // 0x8006041C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80060420: sb          $v0, 0x51($s1)
    MEM_B(0X51, ctx->r17) = ctx->r2;
    // 0x80060424: lwc1        $f0, 0x4($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X4);
    // 0x80060428: swc1        $f0, 0x64($s1)
    MEM_W(0X64, ctx->r17) = ctx->f0.u32l;
    // 0x8006042C: lwc1        $f2, 0x8($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X8);
    // 0x80060430: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80060434: c.eq.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl == ctx->f0.fl;
    // 0x80060438: nop

    // 0x8006043C: bc1t        L_8006044C
    if (c1cs) {
        // 0x80060440: nop
    
            goto L_8006044C;
    }
    // 0x80060440: nop

    // 0x80060444: j           L_80060458
    // 0x80060448: swc1        $f2, 0x54($s1)
    MEM_W(0X54, ctx->r17) = ctx->f2.u32l;
        goto L_80060458;
    // 0x80060448: swc1        $f2, 0x54($s1)
    MEM_W(0X54, ctx->r17) = ctx->f2.u32l;
L_8006044C:
    // 0x8006044C: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80060450: lwc1        $f0, -0x4D18($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X4D18);
    // 0x80060454: swc1        $f0, 0x54($s1)
    MEM_W(0X54, ctx->r17) = ctx->f0.u32l;
L_80060458:
    // 0x80060458: lbu         $v1, 0x14($s0)
    ctx->r3 = MEM_BU(ctx->r16, 0X14);
    // 0x8006045C: sltiu       $v0, $v1, 0x2
    ctx->r2 = ctx->r3 < 0X2 ? 1 : 0;
    // 0x80060460: beq         $v0, $zero, L_80060470
    if (ctx->r2 == 0) {
        // 0x80060464: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80060470;
    }
    // 0x80060464: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80060468: j           L_80060474
    // 0x8006046C: sb          $v1, 0x53($s1)
    MEM_B(0X53, ctx->r17) = ctx->r3;
        goto L_80060474;
    // 0x8006046C: sb          $v1, 0x53($s1)
    MEM_B(0X53, ctx->r17) = ctx->r3;
L_80060470:
    // 0x80060470: sb          $v0, 0x53($s1)
    MEM_B(0X53, ctx->r17) = ctx->r2;
L_80060474:
    // 0x80060474: lwc1        $f0, 0xC($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0XC);
    // 0x80060478: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x8006047C: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x80060480: nop

    // 0x80060484: bc1tl       L_8006048C
    if (c1cs) {
        // 0x80060488: swc1        $f0, 0x6C($s1)
        MEM_W(0X6C, ctx->r17) = ctx->f0.u32l;
            goto L_8006048C;
    }
    goto skip_3;
    // 0x80060488: swc1        $f0, 0x6C($s1)
    MEM_W(0X6C, ctx->r17) = ctx->f0.u32l;
    skip_3:
L_8006048C:
    // 0x8006048C: lwc1        $f0, 0x10($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X10);
    // 0x80060490: c.le.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl <= ctx->f0.fl;
    // 0x80060494: nop

    // 0x80060498: bc1tl       L_800604A0
    if (c1cs) {
        // 0x8006049C: swc1        $f0, 0x68($s1)
        MEM_W(0X68, ctx->r17) = ctx->f0.u32l;
            goto L_800604A0;
    }
    goto skip_4;
    // 0x8006049C: swc1        $f0, 0x68($s1)
    MEM_W(0X68, ctx->r17) = ctx->f0.u32l;
    skip_4:
L_800604A0:
    // 0x800604A0: jal         0x8006C994
    // 0x800604A4: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    func_8006C994(rdram, ctx);
        goto after_39;
    // 0x800604A4: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    after_39:
    // 0x800604A8: lhu         $v1, 0x2($s0)
    ctx->r3 = MEM_HU(ctx->r16, 0X2);
    // 0x800604AC: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x800604B0: bne         $v1, $v0, L_8006063C
    if (ctx->r3 != ctx->r2) {
        // 0x800604B4: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_8006063C;
    }
    // 0x800604B4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800604B8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800604BC: j           L_80060638
    // 0x800604C0: sb          $v0, 0x7A($s1)
    MEM_B(0X7A, ctx->r17) = ctx->r2;
        goto L_80060638;
    // 0x800604C0: sb          $v0, 0x7A($s1)
    MEM_B(0X7A, ctx->r17) = ctx->r2;
L_800604C4:
    // 0x800604C4: lwc1        $f0, 0x18($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X18);
    // 0x800604C8: swc1        $f0, 0x6C($s1)
    MEM_W(0X6C, ctx->r17) = ctx->f0.u32l;
L_800604CC:
    // 0x800604CC: lhu         $v0, 0x48($s1)
    ctx->r2 = MEM_HU(ctx->r17, 0X48);
    // 0x800604D0: lwc1        $f2, 0x18($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X18);
    // 0x800604D4: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x800604D8: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x800604DC: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x800604E0: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x800604E4: lwc1        $f2, -0x4D14($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X4D14);
    // 0x800604E8: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x800604EC: nop

    // 0x800604F0: bc1tl       L_800604F8
    if (c1cs) {
        // 0x800604F4: mov.s       $f0, $f2
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
            goto L_800604F8;
    }
    goto skip_5;
    // 0x800604F4: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    skip_5:
L_800604F8:
    // 0x800604F8: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x800604FC: lwc1        $f2, -0x4D10($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X4D10);
    // 0x80060500: c.le.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl <= ctx->f0.fl;
    // 0x80060504: nop

    // 0x80060508: bc1tl       L_80060520
    if (c1cs) {
        // 0x8006050C: sub.s       $f0, $f0, $f2
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
            goto L_80060520;
    }
    goto skip_6;
    // 0x8006050C: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    skip_6:
    // 0x80060510: trunc.w.s   $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    ctx->f10.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x80060514: mfc1        $v1, $f10
    ctx->r3 = (int32_t)ctx->f10.u32l;
    // 0x80060518: j           L_80060638
    // 0x8006051C: sh          $v1, 0x48($s1)
    MEM_H(0X48, ctx->r17) = ctx->r3;
        goto L_80060638;
    // 0x8006051C: sh          $v1, 0x48($s1)
    MEM_H(0X48, ctx->r17) = ctx->r3;
L_80060520:
    // 0x80060520: lui         $v0, 0x8000
    ctx->r2 = S32(0X8000 << 16);
    // 0x80060524: trunc.w.s   $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    ctx->f10.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x80060528: mfc1        $v1, $f10
    ctx->r3 = (int32_t)ctx->f10.u32l;
    // 0x8006052C: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x80060530: j           L_80060638
    // 0x80060534: sh          $v1, 0x48($s1)
    MEM_H(0X48, ctx->r17) = ctx->r3;
        goto L_80060638;
    // 0x80060534: sh          $v1, 0x48($s1)
    MEM_H(0X48, ctx->r17) = ctx->r3;
L_80060538:
    // 0x80060538: lwc1        $f0, 0x18($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X18);
    // 0x8006053C: j           L_80060638
    // 0x80060540: swc1        $f0, 0x70($s1)
    MEM_W(0X70, ctx->r17) = ctx->f0.u32l;
        goto L_80060638;
    // 0x80060540: swc1        $f0, 0x70($s1)
    MEM_W(0X70, ctx->r17) = ctx->f0.u32l;
L_80060544:
    // 0x80060544: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80060548: j           L_80060638
    // 0x8006054C: sb          $v0, 0xC2($s1)
    MEM_B(0XC2, ctx->r17) = ctx->r2;
        goto L_80060638;
    // 0x8006054C: sb          $v0, 0xC2($s1)
    MEM_B(0XC2, ctx->r17) = ctx->r2;
L_80060550:
    // 0x80060550: lh          $v1, 0x4A($s1)
    ctx->r3 = MEM_H(ctx->r17, 0X4A);
    // 0x80060554: addiu       $v0, $zero, 0xB
    ctx->r2 = ADD32(0, 0XB);
    // 0x80060558: bne         $v1, $v0, L_8006063C
    if (ctx->r3 != ctx->r2) {
        // 0x8006055C: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_8006063C;
    }
    // 0x8006055C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80060560: lw          $a0, 0x8($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X8);
    // 0x80060564: beql        $a0, $zero, L_80060580
    if (ctx->r4 == 0) {
        // 0x80060568: addu        $a0, $zero, $zero
        ctx->r4 = ADD32(0, 0);
            goto L_80060580;
    }
    goto skip_7;
    // 0x80060568: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    skip_7:
    // 0x8006056C: lui         $a1, 0x3ECC
    ctx->r5 = S32(0X3ECC << 16);
    // 0x80060570: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    // 0x80060574: jal         0x800612A4
    // 0x80060578: nop

    func_800612A4(rdram, ctx);
        goto after_40;
    // 0x80060578: nop

    after_40:
    // 0x8006057C: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
L_80060580:
    // 0x80060580: addiu       $a1, $s1, 0x4
    ctx->r5 = ADD32(ctx->r17, 0X4);
    // 0x80060584: addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    // 0x80060588: lui         $a3, 0x41A0
    ctx->r7 = S32(0X41A0 << 16);
    // 0x8006058C: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80060590: lwc1        $f0, -0x4D0C($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X4D0C);
    // 0x80060594: addiu       $v0, $zero, 0x22
    ctx->r2 = ADD32(0, 0X22);
    // 0x80060598: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // 0x8006059C: addiu       $v0, $zero, 0x78
    ctx->r2 = ADD32(0, 0X78);
    // 0x800605A0: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x800605A4: addiu       $v0, $zero, 0x50
    ctx->r2 = ADD32(0, 0X50);
    // 0x800605A8: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x800605AC: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x800605B0: jal         0x800989D8
    // 0x800605B4: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    func_800989D8(rdram, ctx);
        goto after_41;
    // 0x800605B4: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    after_41:
    // 0x800605B8: lhu         $v1, 0x0($s2)
    ctx->r3 = MEM_HU(ctx->r18, 0X0);
    // 0x800605BC: ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
    // 0x800605C0: beq         $v1, $v0, L_800605D0
    if (ctx->r3 == ctx->r2) {
        // 0x800605C4: nop
    
            goto L_800605D0;
    }
    // 0x800605C4: nop

    // 0x800605C8: jal         0x8003ED74
    // 0x800605CC: addu        $a0, $v1, $zero
    ctx->r4 = ADD32(ctx->r3, 0);
    func_8003ED74(rdram, ctx);
        goto after_42;
    // 0x800605CC: addu        $a0, $v1, $zero
    ctx->r4 = ADD32(ctx->r3, 0);
    after_42:
L_800605D0:
    // 0x800605D0: lhu         $a0, 0x16($s3)
    ctx->r4 = MEM_HU(ctx->r19, 0X16);
    // 0x800605D4: jal         0x8003ED74
    // 0x800605D8: nop

    func_8003ED74(rdram, ctx);
        goto after_43;
    // 0x800605D8: nop

    after_43:
    // 0x800605DC: j           L_8006063C
    // 0x800605E0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8006063C;
    // 0x800605E0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800605E4:
    // 0x800605E4: lh          $a0, 0x4A($s1)
    ctx->r4 = MEM_H(ctx->r17, 0X4A);
    // 0x800605E8: addiu       $v0, $zero, 0xD
    ctx->r2 = ADD32(0, 0XD);
    // 0x800605EC: beq         $a0, $v0, L_80060628
    if (ctx->r4 == ctx->r2) {
        // 0x800605F0: slti        $v0, $a0, 0xE
        ctx->r2 = SIGNED(ctx->r4) < 0XE ? 1 : 0;
            goto L_80060628;
    }
    // 0x800605F0: slti        $v0, $a0, 0xE
    ctx->r2 = SIGNED(ctx->r4) < 0XE ? 1 : 0;
    // 0x800605F4: bne         $v0, $zero, L_80060610
    if (ctx->r2 != 0) {
        // 0x800605F8: slti        $v0, $a0, 0xC
        ctx->r2 = SIGNED(ctx->r4) < 0XC ? 1 : 0;
            goto L_80060610;
    }
    // 0x800605F8: slti        $v0, $a0, 0xC
    ctx->r2 = SIGNED(ctx->r4) < 0XC ? 1 : 0;
    // 0x800605FC: addiu       $v0, $zero, 0xE
    ctx->r2 = ADD32(0, 0XE);
    // 0x80060600: beq         $a0, $v0, L_80060630
    if (ctx->r4 == ctx->r2) {
        // 0x80060604: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80060630;
    }
    // 0x80060604: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80060608: j           L_8006063C
    // 0x8006060C: nop

        goto L_8006063C;
    // 0x8006060C: nop

L_80060610:
    // 0x80060610: beq         $v0, $zero, L_80060638
    if (ctx->r2 == 0) {
        // 0x80060614: slti        $v0, $a0, 0xA
        ctx->r2 = SIGNED(ctx->r4) < 0XA ? 1 : 0;
            goto L_80060638;
    }
    // 0x80060614: slti        $v0, $a0, 0xA
    ctx->r2 = SIGNED(ctx->r4) < 0XA ? 1 : 0;
    // 0x80060618: bne         $v0, $zero, L_8006063C
    if (ctx->r2 != 0) {
        // 0x8006061C: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_8006063C;
    }
    // 0x8006061C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80060620: j           L_80060634
    // 0x80060624: addiu       $v0, $zero, 0x1002
    ctx->r2 = ADD32(0, 0X1002);
        goto L_80060634;
    // 0x80060624: addiu       $v0, $zero, 0x1002
    ctx->r2 = ADD32(0, 0X1002);
L_80060628:
    // 0x80060628: j           L_80060634
    // 0x8006062C: addiu       $v0, $zero, 0x1003
    ctx->r2 = ADD32(0, 0X1003);
        goto L_80060634;
    // 0x8006062C: addiu       $v0, $zero, 0x1003
    ctx->r2 = ADD32(0, 0X1003);
L_80060630:
    // 0x80060630: addiu       $v0, $zero, 0x1004
    ctx->r2 = ADD32(0, 0X1004);
L_80060634:
    // 0x80060634: sh          $v0, 0x2($s2)
    MEM_H(0X2, ctx->r18) = ctx->r2;
L_80060638:
    // 0x80060638: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8006063C:
    // 0x8006063C: lw          $ra, 0xD4($sp)
    ctx->r31 = MEM_W(ctx->r29, 0XD4);
    // 0x80060640: lw          $s4, 0xD0($sp)
    ctx->r20 = MEM_W(ctx->r29, 0XD0);
    // 0x80060644: lw          $s3, 0xCC($sp)
    ctx->r19 = MEM_W(ctx->r29, 0XCC);
    // 0x80060648: lw          $s2, 0xC8($sp)
    ctx->r18 = MEM_W(ctx->r29, 0XC8);
    // 0x8006064C: lw          $s1, 0xC4($sp)
    ctx->r17 = MEM_W(ctx->r29, 0XC4);
    // 0x80060650: lw          $s0, 0xC0($sp)
    ctx->r16 = MEM_W(ctx->r29, 0XC0);
    // 0x80060654: ldc1        $f20, 0xD8($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0XD8);
    // 0x80060658: jr          $ra
    // 0x8006065C: addiu       $sp, $sp, 0xE0
    ctx->r29 = ADD32(ctx->r29, 0XE0);
    return;
    // 0x8006065C: addiu       $sp, $sp, 0xE0
    ctx->r29 = ADD32(ctx->r29, 0XE0);
;}
RECOMP_FUNC void func_80060660(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80060660: addiu       $v1, $zero, 0x3
    ctx->r3 = ADD32(0, 0X3);
    // 0x80060664: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x80060668: addiu       $v0, $v0, -0x679C
    ctx->r2 = ADD32(ctx->r2, -0X679C);
    // 0x8006066C: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
L_80060670:
    // 0x80060670: sb          $v1, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r3;
    // 0x80060674: addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
    // 0x80060678: bgez        $v1, L_80060670
    if (SIGNED(ctx->r3) >= 0) {
        // 0x8006067C: addiu       $v0, $v0, -0x1
        ctx->r2 = ADD32(ctx->r2, -0X1);
            goto L_80060670;
    }
    // 0x8006067C: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x80060680: lui         $v1, 0x8014
    ctx->r3 = S32(0X8014 << 16);
    // 0x80060684: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // 0x80060688: jr          $ra
    // 0x8006068C: sb          $v0, -0x67A0($v1)
    MEM_B(-0X67A0, ctx->r3) = ctx->r2;
    return;
    // 0x8006068C: sb          $v0, -0x67A0($v1)
    MEM_B(-0X67A0, ctx->r3) = ctx->r2;
;}
RECOMP_FUNC void func_80060690(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80060690: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80060694: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80060698: addu        $s2, $a0, $zero
    ctx->r18 = ADD32(ctx->r4, 0);
    // 0x8006069C: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x800606A0: andi        $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 & 0XFFFF;
    // 0x800606A4: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x800606A8: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800606AC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800606B0: lw          $s0, 0x4($s2)
    ctx->r16 = MEM_W(ctx->r18, 0X4);
    // 0x800606B4: beq         $a1, $v0, L_800608E4
    if (ctx->r5 == ctx->r2) {
        // 0x800606B8: addu        $s1, $a2, $zero
        ctx->r17 = ADD32(ctx->r6, 0);
            goto L_800608E4;
    }
    // 0x800606B8: addu        $s1, $a2, $zero
    ctx->r17 = ADD32(ctx->r6, 0);
    // 0x800606BC: slti        $v0, $a1, 0x3
    ctx->r2 = SIGNED(ctx->r5) < 0X3 ? 1 : 0;
    // 0x800606C0: beq         $v0, $zero, L_800606D8
    if (ctx->r2 == 0) {
        // 0x800606C4: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_800606D8;
    }
    // 0x800606C4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800606C8: beq         $a1, $v0, L_800606F4
    if (ctx->r5 == ctx->r2) {
        // 0x800606CC: addiu       $v0, $zero, 0x100
        ctx->r2 = ADD32(0, 0X100);
            goto L_800606F4;
    }
    // 0x800606CC: addiu       $v0, $zero, 0x100
    ctx->r2 = ADD32(0, 0X100);
    // 0x800606D0: j           L_800608E8
    // 0x800606D4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_800608E8;
    // 0x800606D4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800606D8:
    // 0x800606D8: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x800606DC: beq         $a1, $v0, L_80060788
    if (ctx->r5 == ctx->r2) {
        // 0x800606E0: addiu       $v0, $zero, 0x4
        ctx->r2 = ADD32(0, 0X4);
            goto L_80060788;
    }
    // 0x800606E0: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // 0x800606E4: beq         $a1, $v0, L_800607C8
    if (ctx->r5 == ctx->r2) {
        // 0x800606E8: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_800607C8;
    }
    // 0x800606E8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800606EC: j           L_800608E8
    // 0x800606F0: nop

        goto L_800608E8;
    // 0x800606F0: nop

L_800606F4:
    // 0x800606F4: jal         0x80003430
    // 0x800606F8: sh          $v0, 0x10($s0)
    MEM_H(0X10, ctx->r16) = ctx->r2;
    rand_recomp(rdram, ctx);
        goto after_0;
    // 0x800606F8: sh          $v0, 0x10($s0)
    MEM_H(0X10, ctx->r16) = ctx->r2;
    after_0:
    // 0x800606FC: lhu         $v1, 0x10($s0)
    ctx->r3 = MEM_HU(ctx->r16, 0X10);
    // 0x80060700: andi        $v0, $v0, 0x1C00
    ctx->r2 = ctx->r2 & 0X1C00;
    // 0x80060704: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x80060708: jal         0x80003430
    // 0x8006070C: sh          $v1, 0x10($s0)
    MEM_H(0X10, ctx->r16) = ctx->r3;
    rand_recomp(rdram, ctx);
        goto after_1;
    // 0x8006070C: sh          $v1, 0x10($s0)
    MEM_H(0X10, ctx->r16) = ctx->r3;
    after_1:
    // 0x80060710: lwc1        $f6, 0x8($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X8);
    // 0x80060714: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80060718: lwc1        $f0, -0x4D00($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X4D00);
    // 0x8006071C: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x80060720: mul.s       $f6, $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x80060724: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80060728: lwc1        $f2, -0x4CFC($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X4CFC);
    // 0x8006072C: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80060730: lwc1        $f4, -0x4CF8($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X4CF8);
    // 0x80060734: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x80060738: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x8006073C: div.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f2.fl);
    // 0x80060740: add.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f4.fl;
    // 0x80060744: mul.s       $f0, $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x80060748: swc1        $f0, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f0.u32l;
    // 0x8006074C: swc1        $f0, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->f0.u32l;
    // 0x80060750: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x80060754: lw          $t0, 0x0($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X0);
    // 0x80060758: lw          $t1, 0x4($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X4);
    // 0x8006075C: lw          $t2, 0x8($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X8);
    // 0x80060760: sw          $t0, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->r8;
    // 0x80060764: sw          $t1, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->r9;
    // 0x80060768: sw          $t2, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->r10;
    // 0x8006076C: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x80060770: sw          $zero, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = 0;
    // 0x80060774: lhu         $a0, -0x6A8C($v0)
    ctx->r4 = MEM_HU(ctx->r2, -0X6A8C);
    // 0x80060778: jal         0x8003E684
    // 0x8006077C: addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    func_8003E684(rdram, ctx);
        goto after_2;
    // 0x8006077C: addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    after_2:
    // 0x80060780: j           L_800608E8
    // 0x80060784: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_800608E8;
    // 0x80060784: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80060788:
    // 0x80060788: lwc1        $f2, 0x0($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0X0);
    // 0x8006078C: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80060790: lwc1        $f0, -0x4CF4($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X4CF4);
    // 0x80060794: mul.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x80060798: lwc1        $f0, 0x3C($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X3C);
    // 0x8006079C: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x800607A0: trunc.w.s   $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    ctx->f8.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800607A4: mfc1        $v0, $f8
    ctx->r2 = (int32_t)ctx->f8.u32l;
    // 0x800607A8: slti        $v0, $v0, 0x14
    ctx->r2 = SIGNED(ctx->r2) < 0X14 ? 1 : 0;
    // 0x800607AC: bne         $v0, $zero, L_800608E4
    if (ctx->r2 != 0) {
        // 0x800607B0: swc1        $f0, 0x3C($s0)
        MEM_W(0X3C, ctx->r16) = ctx->f0.u32l;
            goto L_800608E4;
    }
    // 0x800607B0: swc1        $f0, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = ctx->f0.u32l;
    // 0x800607B4: lhu         $a0, 0x16($s2)
    ctx->r4 = MEM_HU(ctx->r18, 0X16);
    // 0x800607B8: jal         0x8003ED74
    // 0x800607BC: nop

    func_8003ED74(rdram, ctx);
        goto after_3;
    // 0x800607BC: nop

    after_3:
    // 0x800607C0: j           L_800608E8
    // 0x800607C4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_800608E8;
    // 0x800607C4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800607C8:
    // 0x800607C8: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x800607CC: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x800607D0: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x800607D4: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x800607D8: jal         0x8001DC34
    // 0x800607DC: addiu       $a2, $s0, 0x30
    ctx->r6 = ADD32(ctx->r16, 0X30);
    func_8001DC34(rdram, ctx);
        goto after_4;
    // 0x800607DC: addiu       $a2, $s0, 0x30
    ctx->r6 = ADD32(ctx->r16, 0X30);
    after_4:
    // 0x800607E0: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x800607E4: beq         $v0, $zero, L_800608E4
    if (ctx->r2 == 0) {
        // 0x800607E8: lui         $v1, 0x8014
        ctx->r3 = S32(0X8014 << 16);
            goto L_800608E4;
    }
    // 0x800607E8: lui         $v1, 0x8014
    ctx->r3 = S32(0X8014 << 16);
    // 0x800607EC: lwc1        $f0, 0x3C($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X3C);
    // 0x800607F0: addiu       $v1, $v1, -0x6790
    ctx->r3 = ADD32(ctx->r3, -0X6790);
    // 0x800607F4: trunc.w.s   $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    ctx->f8.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800607F8: mfc1        $v0, $f8
    ctx->r2 = (int32_t)ctx->f8.u32l;
    // 0x800607FC: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x80060800: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80060804: lhu         $v0, 0x0($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X0);
    // 0x80060808: sh          $v0, 0x12($s0)
    MEM_H(0X12, ctx->r16) = ctx->r2;
    // 0x8006080C: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80060810: lbu         $v0, 0xB63($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0XB63);
    // 0x80060814: beq         $v0, $zero, L_80060868
    if (ctx->r2 == 0) {
        // 0x80060818: mov.s       $f2, $f0
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
            goto L_80060868;
    }
    // 0x80060818: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
    // 0x8006081C: trunc.w.s   $f8, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    ctx->f8.u32l = TRUNC_W_S(ctx->f2.fl);
    // 0x80060820: mfc1        $v1, $f8
    ctx->r3 = (int32_t)ctx->f8.u32l;
    // 0x80060824: slti        $v0, $v1, 0x13
    ctx->r2 = SIGNED(ctx->r3) < 0X13 ? 1 : 0;
    // 0x80060828: beq         $v0, $zero, L_80060868
    if (ctx->r2 == 0) {
        // 0x8006082C: nop
    
            goto L_80060868;
    }
    // 0x8006082C: nop

    // 0x80060830: mtc1        $v1, $f0
    ctx->f0.u32l = ctx->r3;
    // 0x80060834: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x80060838: sub.s       $f0, $f2, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f2.fl - ctx->f0.fl;
    // 0x8006083C: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80060840: lwc1        $f2, -0x4CF0($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X4CF0);
    // 0x80060844: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x80060848: nop

    // 0x8006084C: bc1f        L_80060868
    if (!c1cs) {
        // 0x80060850: lui         $v0, 0x8014
        ctx->r2 = S32(0X8014 << 16);
            goto L_80060868;
    }
    // 0x80060850: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x80060854: addiu       $v0, $v0, -0x6768
    ctx->r2 = ADD32(ctx->r2, -0X6768);
    // 0x80060858: sll         $v1, $v1, 1
    ctx->r3 = S32(ctx->r3 << 1);
    // 0x8006085C: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x80060860: lhu         $v0, 0x0($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X0);
    // 0x80060864: sh          $v0, 0x12($s0)
    MEM_H(0X12, ctx->r16) = ctx->r2;
L_80060868:
    // 0x80060868: lwc1        $f0, 0x30($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X30);
    // 0x8006086C: lwc1        $f2, 0x18($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0X18);
    // 0x80060870: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x80060874: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80060878: lwc1        $f4, -0x4CEC($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X4CEC);
    // 0x8006087C: mul.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x80060880: trunc.w.s   $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    ctx->f8.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x80060884: mfc1        $v0, $f8
    ctx->r2 = (int32_t)ctx->f8.u32l;
    // 0x80060888: lwc1        $f0, 0x34($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X34);
    // 0x8006088C: sh          $v0, 0x8($s0)
    MEM_H(0X8, ctx->r16) = ctx->r2;
    // 0x80060890: lwc1        $f2, 0x1C($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0X1C);
    // 0x80060894: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x80060898: mul.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x8006089C: trunc.w.s   $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    ctx->f8.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800608A0: mfc1        $v0, $f8
    ctx->r2 = (int32_t)ctx->f8.u32l;
    // 0x800608A4: lwc1        $f0, 0x38($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X38);
    // 0x800608A8: sh          $v0, 0xA($s0)
    MEM_H(0XA, ctx->r16) = ctx->r2;
    // 0x800608AC: lwc1        $f2, 0x20($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0X20);
    // 0x800608B0: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x800608B4: mul.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x800608B8: trunc.w.s   $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    ctx->f8.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800608BC: mfc1        $v0, $f8
    ctx->r2 = (int32_t)ctx->f8.u32l;
    // 0x800608C0: sh          $v0, 0xC($s0)
    MEM_H(0XC, ctx->r16) = ctx->r2;
    // 0x800608C4: lw          $v0, 0x48($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X48);
    // 0x800608C8: lw          $v0, 0x20($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X20);
    // 0x800608CC: beq         $v0, $zero, L_800608D8
    if (ctx->r2 == 0) {
        // 0x800608D0: sw          $v0, 0x0($s0)
        MEM_W(0X0, ctx->r16) = ctx->r2;
            goto L_800608D8;
    }
    // 0x800608D0: sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
    // 0x800608D4: sw          $s0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r16;
L_800608D8:
    // 0x800608D8: sw          $zero, 0x4($s0)
    MEM_W(0X4, ctx->r16) = 0;
    // 0x800608DC: lw          $v0, 0x48($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X48);
    // 0x800608E0: sw          $s0, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->r16;
L_800608E4:
    // 0x800608E4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800608E8:
    // 0x800608E8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800608EC: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x800608F0: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x800608F4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800608F8: jr          $ra
    // 0x800608FC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x800608FC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
