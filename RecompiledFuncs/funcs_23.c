#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void func_8008ACB4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008ACB4: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8008ACB8: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x8008ACBC: sw          $fp, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r30;
    // 0x8008ACC0: sw          $s7, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r23;
    // 0x8008ACC4: sw          $s6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r22;
    // 0x8008ACC8: sw          $s5, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r21;
    // 0x8008ACCC: sw          $s4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r20;
    // 0x8008ACD0: sw          $s3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r19;
    // 0x8008ACD4: sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // 0x8008ACD8: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x8008ACDC: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x8008ACE0: lbu         $v0, 0x6($a1)
    ctx->r2 = MEM_BU(ctx->r5, 0X6);
    // 0x8008ACE4: bne         $v0, $zero, L_8008ACFC
    if (ctx->r2 != 0) {
        // 0x8008ACE8: addu        $s5, $a0, $zero
        ctx->r21 = ADD32(ctx->r4, 0);
            goto L_8008ACFC;
    }
    // 0x8008ACE8: addu        $s5, $a0, $zero
    ctx->r21 = ADD32(ctx->r4, 0);
    // 0x8008ACEC: lbu         $v1, 0x2($a1)
    ctx->r3 = MEM_BU(ctx->r5, 0X2);
    // 0x8008ACF0: lw          $v0, 0x30($s5)
    ctx->r2 = MEM_W(ctx->r21, 0X30);
    // 0x8008ACF4: j           L_8008AD04
    // 0x8008ACF8: nop

        goto L_8008AD04;
    // 0x8008ACF8: nop

L_8008ACFC:
    // 0x8008ACFC: lbu         $v1, 0x2($a1)
    ctx->r3 = MEM_BU(ctx->r5, 0X2);
    // 0x8008AD00: lw          $v0, 0x34($s5)
    ctx->r2 = MEM_W(ctx->r21, 0X34);
L_8008AD04:
    // 0x8008AD04: mult        $v0, $v1
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8008AD08: mflo        $v0
    ctx->r2 = lo;
    // 0x8008AD0C: srl         $v0, $v0, 7
    ctx->r2 = S32(U32(ctx->r2) >> 7);
    // 0x8008AD10: sw          $v0, 0x30($s5)
    MEM_W(0X30, ctx->r21) = ctx->r2;
    // 0x8008AD14: lbu         $v0, 0x1($a1)
    ctx->r2 = MEM_BU(ctx->r5, 0X1);
    // 0x8008AD18: lw          $v1, 0x30($s5)
    ctx->r3 = MEM_W(ctx->r21, 0X30);
    // 0x8008AD1C: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x8008AD20: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x8008AD24: lui         $v0, 0x7F
    ctx->r2 = S32(0X7F << 16);
    // 0x8008AD28: sw          $v1, 0x30($s5)
    MEM_W(0X30, ctx->r21) = ctx->r3;
    // 0x8008AD2C: sltu        $v1, $v0, $v1
    ctx->r3 = ctx->r2 < ctx->r3 ? 1 : 0;
    // 0x8008AD30: bnel        $v1, $zero, L_8008AD38
    if (ctx->r3 != 0) {
        // 0x8008AD34: sw          $v0, 0x30($s5)
        MEM_W(0X30, ctx->r21) = ctx->r2;
            goto L_8008AD38;
    }
    goto skip_0;
    // 0x8008AD34: sw          $v0, 0x30($s5)
    MEM_W(0X30, ctx->r21) = ctx->r2;
    skip_0:
L_8008AD38:
    // 0x8008AD38: lbu         $a1, 0x0($a1)
    ctx->r5 = MEM_BU(ctx->r5, 0X0);
    // 0x8008AD3C: lw          $s6, 0x30($s5)
    ctx->r22 = MEM_W(ctx->r21, 0X30);
    // 0x8008AD40: beql        $a1, $zero, L_8008AE18
    if (ctx->r5 == 0) {
        // 0x8008AD44: sw          $s6, 0x30($s5)
        MEM_W(0X30, ctx->r21) = ctx->r22;
            goto L_8008AE18;
    }
    goto skip_1;
    // 0x8008AD44: sw          $s6, 0x30($s5)
    MEM_W(0X30, ctx->r21) = ctx->r22;
    skip_1:
    // 0x8008AD48: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x8008AD4C: lw          $v0, -0x50F4($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X50F4);
    // 0x8008AD50: lui         $fp, 0x8015
    ctx->r30 = S32(0X8015 << 16);
    // 0x8008AD54: addiu       $fp, $fp, -0x7398
    ctx->r30 = ADD32(ctx->r30, -0X7398);
    // 0x8008AD58: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x8008AD5C: sh          $a1, -0x53A4($at)
    MEM_H(-0X53A4, ctx->r1) = ctx->r5;
    // 0x8008AD60: beq         $v0, $zero, L_8008ADB8
    if (ctx->r2 == 0) {
        // 0x8008AD64: addiu       $s7, $zero, 0x8
        ctx->r23 = ADD32(0, 0X8);
            goto L_8008ADB8;
    }
    // 0x8008AD64: addiu       $s7, $zero, 0x8
    ctx->r23 = ADD32(0, 0X8);
    // 0x8008AD68: addiu       $s4, $zero, 0x1
    ctx->r20 = ADD32(0, 0X1);
    // 0x8008AD6C: addu        $s3, $v0, $zero
    ctx->r19 = ADD32(ctx->r2, 0);
    // 0x8008AD70: addu        $v0, $s4, $s3
    ctx->r2 = ADD32(ctx->r20, ctx->r19);
L_8008AD74:
    // 0x8008AD74: sra         $s2, $v0, 1
    ctx->r18 = S32(SIGNED(ctx->r2) >> 1);
    // 0x8008AD78: addiu       $s1, $s2, -0x1
    ctx->r17 = ADD32(ctx->r18, -0X1);
    // 0x8008AD7C: mult        $s7, $s1
    result = S64(S32(ctx->r23)) * S64(S32(ctx->r17)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8008AD80: mflo        $v0
    ctx->r2 = lo;
    // 0x8008AD84: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8008AD88: addiu       $a0, $a0, -0x53A8
    ctx->r4 = ADD32(ctx->r4, -0X53A8);
    // 0x8008AD8C: addu        $s0, $fp, $v0
    ctx->r16 = ADD32(ctx->r30, ctx->r2);
    // 0x8008AD90: jal         0x80085F54
    // 0x8008AD94: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    func_80085F54(rdram, ctx);
        goto after_0;
    // 0x8008AD94: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    after_0:
    // 0x8008AD98: beql        $v0, $zero, L_8008ADBC
    if (ctx->r2 == 0) {
        // 0x8008AD9C: addu        $a1, $s0, $zero
        ctx->r5 = ADD32(ctx->r16, 0);
            goto L_8008ADBC;
    }
    goto skip_2;
    // 0x8008AD9C: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    skip_2:
    // 0x8008ADA0: bgezl       $v0, L_8008ADAC
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8008ADA4: addiu       $s4, $s2, 0x1
        ctx->r20 = ADD32(ctx->r18, 0X1);
            goto L_8008ADAC;
    }
    goto skip_3;
    // 0x8008ADA4: addiu       $s4, $s2, 0x1
    ctx->r20 = ADD32(ctx->r18, 0X1);
    skip_3:
    // 0x8008ADA8: addu        $s3, $s1, $zero
    ctx->r19 = ADD32(ctx->r17, 0);
L_8008ADAC:
    // 0x8008ADAC: slt         $v0, $s3, $s4
    ctx->r2 = SIGNED(ctx->r19) < SIGNED(ctx->r20) ? 1 : 0;
    // 0x8008ADB0: beq         $v0, $zero, L_8008AD74
    if (ctx->r2 == 0) {
        // 0x8008ADB4: addu        $v0, $s4, $s3
        ctx->r2 = ADD32(ctx->r20, ctx->r19);
            goto L_8008AD74;
    }
    // 0x8008ADB4: addu        $v0, $s4, $s3
    ctx->r2 = ADD32(ctx->r20, ctx->r19);
L_8008ADB8:
    // 0x8008ADB8: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
L_8008ADBC:
    // 0x8008ADBC: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x8008ADC0: sw          $a1, -0x53A0($at)
    MEM_W(-0X53A0, ctx->r1) = ctx->r5;
    // 0x8008ADC4: beq         $a1, $zero, L_8008ADD0
    if (ctx->r5 == 0) {
        // 0x8008ADC8: addu        $a0, $zero, $zero
        ctx->r4 = ADD32(0, 0);
            goto L_8008ADD0;
    }
    // 0x8008ADC8: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x8008ADCC: lw          $a0, 0x0($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X0);
L_8008ADD0:
    // 0x8008ADD0: beq         $a0, $zero, L_8008AE14
    if (ctx->r4 == 0) {
        // 0x8008ADD4: srl         $v1, $s6, 16
        ctx->r3 = S32(U32(ctx->r22) >> 16);
            goto L_8008AE14;
    }
    // 0x8008ADD4: srl         $v1, $s6, 16
    ctx->r3 = S32(U32(ctx->r22) >> 16);
    // 0x8008ADD8: sltiu       $v0, $v1, 0x7F
    ctx->r2 = ctx->r3 < 0X7F ? 1 : 0;
    // 0x8008ADDC: beq         $v0, $zero, L_8008AE08
    if (ctx->r2 == 0) {
        // 0x8008ADE0: andi        $a1, $s6, 0xFFFF
        ctx->r5 = ctx->r22 & 0XFFFF;
            goto L_8008AE08;
    }
    // 0x8008ADE0: andi        $a1, $s6, 0xFFFF
    ctx->r5 = ctx->r22 & 0XFFFF;
    // 0x8008ADE4: addu        $v0, $v1, $a0
    ctx->r2 = ADD32(ctx->r3, ctx->r4);
    // 0x8008ADE8: lbu         $v1, 0x1($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X1);
    // 0x8008ADEC: lbu         $v0, 0x0($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X0);
    // 0x8008ADF0: subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // 0x8008ADF4: mult        $v1, $a1
    result = S64(S32(ctx->r3)) * S64(S32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8008ADF8: mflo        $v1
    ctx->r3 = lo;
    // 0x8008ADFC: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x8008AE00: j           L_8008AE14
    // 0x8008AE04: addu        $s6, $v0, $v1
    ctx->r22 = ADD32(ctx->r2, ctx->r3);
        goto L_8008AE14;
    // 0x8008AE04: addu        $s6, $v0, $v1
    ctx->r22 = ADD32(ctx->r2, ctx->r3);
L_8008AE08:
    // 0x8008AE08: addu        $v0, $a0, $v1
    ctx->r2 = ADD32(ctx->r4, ctx->r3);
    // 0x8008AE0C: lbu         $v0, 0x0($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X0);
    // 0x8008AE10: sll         $s6, $v0, 16
    ctx->r22 = S32(ctx->r2 << 16);
L_8008AE14:
    // 0x8008AE14: sw          $s6, 0x30($s5)
    MEM_W(0X30, ctx->r21) = ctx->r22;
L_8008AE18:
    // 0x8008AE18: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // 0x8008AE1C: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x8008AE20: lw          $fp, 0x30($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X30);
    // 0x8008AE24: lw          $s7, 0x2C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X2C);
    // 0x8008AE28: lw          $s6, 0x28($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X28);
    // 0x8008AE2C: lw          $s5, 0x24($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X24);
    // 0x8008AE30: lw          $s4, 0x20($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X20);
    // 0x8008AE34: lw          $s3, 0x1C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X1C);
    // 0x8008AE38: lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X18);
    // 0x8008AE3C: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x8008AE40: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x8008AE44: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x8008AE48: jr          $ra
    // 0x8008AE4C: nop

    return;
    // 0x8008AE4C: nop

;}
RECOMP_FUNC void func_8008AE50(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008AE50: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x8008AE54: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x8008AE58: sw          $fp, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r30;
    // 0x8008AE5C: sw          $s7, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r23;
    // 0x8008AE60: sw          $s6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r22;
    // 0x8008AE64: sw          $s5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r21;
    // 0x8008AE68: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x8008AE6C: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x8008AE70: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x8008AE74: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x8008AE78: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8008AE7C: lhu         $v1, 0x4($a1)
    ctx->r3 = MEM_HU(ctx->r5, 0X4);
    // 0x8008AE80: addu        $s5, $a0, $zero
    ctx->r21 = ADD32(ctx->r4, 0);
    // 0x8008AE84: sw          $v1, 0xB0($s5)
    MEM_W(0XB0, ctx->r21) = ctx->r3;
    // 0x8008AE88: lw          $v0, 0x4($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X4);
    // 0x8008AE8C: srl         $v0, $v0, 8
    ctx->r2 = S32(U32(ctx->r2) >> 8);
    // 0x8008AE90: andi        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 & 0X1;
    // 0x8008AE94: beq         $v0, $zero, L_8008AEA4
    if (ctx->r2 == 0) {
        // 0x8008AE98: sll         $v0, $v1, 8
        ctx->r2 = S32(ctx->r3 << 8);
            goto L_8008AEA4;
    }
    // 0x8008AE98: sll         $v0, $v1, 8
    ctx->r2 = S32(ctx->r3 << 8);
    // 0x8008AE9C: j           L_8008AF04
    // 0x8008AEA0: sw          $v0, 0xB0($s5)
    MEM_W(0XB0, ctx->r21) = ctx->r2;
        goto L_8008AF04;
    // 0x8008AEA0: sw          $v0, 0xB0($s5)
    MEM_W(0XB0, ctx->r21) = ctx->r2;
L_8008AEA4:
    // 0x8008AEA4: lbu         $v1, 0x4F($s5)
    ctx->r3 = MEM_BU(ctx->r21, 0X4F);
    // 0x8008AEA8: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8008AEAC: addiu       $a0, $a0, -0x5330
    ctx->r4 = ADD32(ctx->r4, -0X5330);
    // 0x8008AEB0: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // 0x8008AEB4: beq         $v1, $v0, L_8008AEC8
    if (ctx->r3 == ctx->r2) {
        // 0x8008AEB8: addiu       $a2, $s5, 0xB0
        ctx->r6 = ADD32(ctx->r21, 0XB0);
            goto L_8008AEC8;
    }
    // 0x8008AEB8: addiu       $a2, $s5, 0xB0
    ctx->r6 = ADD32(ctx->r21, 0XB0);
    // 0x8008AEBC: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x8008AEC0: j           L_8008AECC
    // 0x8008AEC4: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
        goto L_8008AECC;
    // 0x8008AEC4: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
L_8008AEC8:
    // 0x8008AEC8: addiu       $v0, $a0, 0x20
    ctx->r2 = ADD32(ctx->r4, 0X20);
L_8008AECC:
    // 0x8008AECC: lw          $v1, 0x0($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X0);
    // 0x8008AED0: lw          $a0, 0x0($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X0);
    // 0x8008AED4: sll         $v0, $v1, 5
    ctx->r2 = S32(ctx->r3 << 5);
    // 0x8008AED8: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x8008AEDC: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8008AEE0: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8008AEE4: sll         $v0, $v0, 8
    ctx->r2 = S32(ctx->r2 << 8);
    // 0x8008AEE8: divu        $zero, $v0, $a0
    if (U32(ctx->r4) != 0) { lo = S32(U32(ctx->r2) / U32(ctx->r4)); hi = S32(U32(ctx->r2) % U32(ctx->r4)); } else { lo = 0; hi = S32(ctx->r2); }
    // 0x8008AEEC: bne         $a0, $zero, L_8008AEF8
    if (ctx->r4 != 0) {
        // 0x8008AEF0: nop
    
            goto L_8008AEF8;
    }
    // 0x8008AEF0: nop

    // 0x8008AEF4: break       7
    do_break(2148052724);
L_8008AEF8:
    // 0x8008AEF8: mflo        $v0
    ctx->r2 = lo;
    // 0x8008AEFC: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x8008AF00: sw          $v0, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r2;
L_8008AF04:
    // 0x8008AF04: lw          $v0, 0xB0($s5)
    ctx->r2 = MEM_W(ctx->r21, 0XB0);
    // 0x8008AF08: srl         $s7, $v0, 8
    ctx->r23 = S32(U32(ctx->r2) >> 8);
    // 0x8008AF0C: beql        $s7, $zero, L_8008AF14
    if (ctx->r23 == 0) {
        // 0x8008AF10: addiu       $s7, $zero, 0x1
        ctx->r23 = ADD32(0, 0X1);
            goto L_8008AF14;
    }
    goto skip_0;
    // 0x8008AF10: addiu       $s7, $zero, 0x1
    ctx->r23 = ADD32(0, 0X1);
    skip_0:
L_8008AF14:
    // 0x8008AF14: lbu         $v0, 0x2($a1)
    ctx->r2 = MEM_BU(ctx->r5, 0X2);
    // 0x8008AF18: lw          $v1, 0x30($s5)
    ctx->r3 = MEM_W(ctx->r21, 0X30);
    // 0x8008AF1C: mult        $v1, $v0
    result = S64(S32(ctx->r3)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8008AF20: mflo        $v1
    ctx->r3 = lo;
    // 0x8008AF24: lbu         $v0, 0x1($a1)
    ctx->r2 = MEM_BU(ctx->r5, 0X1);
    // 0x8008AF28: lw          $a1, 0x0($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X0);
    // 0x8008AF2C: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x8008AF30: srl         $v1, $v1, 7
    ctx->r3 = S32(U32(ctx->r3) >> 7);
    // 0x8008AF34: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x8008AF38: lui         $v0, 0x7F
    ctx->r2 = S32(0X7F << 16);
    // 0x8008AF3C: sltu        $v0, $v0, $v1
    ctx->r2 = ctx->r2 < ctx->r3 ? 1 : 0;
    // 0x8008AF40: bnel        $v0, $zero, L_8008AF48
    if (ctx->r2 != 0) {
        // 0x8008AF44: lui         $v1, 0x7F
        ctx->r3 = S32(0X7F << 16);
            goto L_8008AF48;
    }
    goto skip_1;
    // 0x8008AF44: lui         $v1, 0x7F
    ctx->r3 = S32(0X7F << 16);
    skip_1:
L_8008AF48:
    // 0x8008AF48: srl         $v0, $a1, 24
    ctx->r2 = S32(U32(ctx->r5) >> 24);
    // 0x8008AF4C: beq         $v0, $zero, L_8008B020
    if (ctx->r2 == 0) {
        // 0x8008AF50: addu        $s6, $v1, $zero
        ctx->r22 = ADD32(ctx->r3, 0);
            goto L_8008B020;
    }
    // 0x8008AF50: addu        $s6, $v1, $zero
    ctx->r22 = ADD32(ctx->r3, 0);
    // 0x8008AF54: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x8008AF58: sh          $v0, -0x53A4($at)
    MEM_H(-0X53A4, ctx->r1) = ctx->r2;
    // 0x8008AF5C: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x8008AF60: lw          $v0, -0x50F4($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X50F4);
    // 0x8008AF64: beq         $v0, $zero, L_8008AFC4
    if (ctx->r2 == 0) {
        // 0x8008AF68: addiu       $fp, $zero, 0x8
        ctx->r30 = ADD32(0, 0X8);
            goto L_8008AFC4;
    }
    // 0x8008AF68: addiu       $fp, $zero, 0x8
    ctx->r30 = ADD32(0, 0X8);
    // 0x8008AF6C: addiu       $s4, $zero, 0x1
    ctx->r20 = ADD32(0, 0X1);
    // 0x8008AF70: addu        $s3, $v0, $zero
    ctx->r19 = ADD32(ctx->r2, 0);
    // 0x8008AF74: addu        $v0, $s4, $s3
    ctx->r2 = ADD32(ctx->r20, ctx->r19);
L_8008AF78:
    // 0x8008AF78: sra         $s2, $v0, 1
    ctx->r18 = S32(SIGNED(ctx->r2) >> 1);
    // 0x8008AF7C: addiu       $s1, $s2, -0x1
    ctx->r17 = ADD32(ctx->r18, -0X1);
    // 0x8008AF80: mult        $fp, $s1
    result = S64(S32(ctx->r30)) * S64(S32(ctx->r17)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8008AF84: mflo        $v0
    ctx->r2 = lo;
    // 0x8008AF88: lui         $a3, 0x8015
    ctx->r7 = S32(0X8015 << 16);
    // 0x8008AF8C: addiu       $a3, $a3, -0x7398
    ctx->r7 = ADD32(ctx->r7, -0X7398);
    // 0x8008AF90: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8008AF94: addiu       $a0, $a0, -0x53A8
    ctx->r4 = ADD32(ctx->r4, -0X53A8);
    // 0x8008AF98: addu        $s0, $a3, $v0
    ctx->r16 = ADD32(ctx->r7, ctx->r2);
    // 0x8008AF9C: jal         0x80085F54
    // 0x8008AFA0: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    func_80085F54(rdram, ctx);
        goto after_0;
    // 0x8008AFA0: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    after_0:
    // 0x8008AFA4: beql        $v0, $zero, L_8008AFC8
    if (ctx->r2 == 0) {
        // 0x8008AFA8: addu        $a1, $s0, $zero
        ctx->r5 = ADD32(ctx->r16, 0);
            goto L_8008AFC8;
    }
    goto skip_2;
    // 0x8008AFA8: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    skip_2:
    // 0x8008AFAC: bgezl       $v0, L_8008AFB8
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8008AFB0: addiu       $s4, $s2, 0x1
        ctx->r20 = ADD32(ctx->r18, 0X1);
            goto L_8008AFB8;
    }
    goto skip_3;
    // 0x8008AFB0: addiu       $s4, $s2, 0x1
    ctx->r20 = ADD32(ctx->r18, 0X1);
    skip_3:
    // 0x8008AFB4: addu        $s3, $s1, $zero
    ctx->r19 = ADD32(ctx->r17, 0);
L_8008AFB8:
    // 0x8008AFB8: slt         $v0, $s3, $s4
    ctx->r2 = SIGNED(ctx->r19) < SIGNED(ctx->r20) ? 1 : 0;
    // 0x8008AFBC: beq         $v0, $zero, L_8008AF78
    if (ctx->r2 == 0) {
        // 0x8008AFC0: addu        $v0, $s4, $s3
        ctx->r2 = ADD32(ctx->r20, ctx->r19);
            goto L_8008AF78;
    }
    // 0x8008AFC0: addu        $v0, $s4, $s3
    ctx->r2 = ADD32(ctx->r20, ctx->r19);
L_8008AFC4:
    // 0x8008AFC4: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
L_8008AFC8:
    // 0x8008AFC8: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x8008AFCC: sw          $a1, -0x53A0($at)
    MEM_W(-0X53A0, ctx->r1) = ctx->r5;
    // 0x8008AFD0: beq         $a1, $zero, L_8008AFDC
    if (ctx->r5 == 0) {
        // 0x8008AFD4: addu        $a0, $zero, $zero
        ctx->r4 = ADD32(0, 0);
            goto L_8008AFDC;
    }
    // 0x8008AFD4: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x8008AFD8: lw          $a0, 0x0($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X0);
L_8008AFDC:
    // 0x8008AFDC: beq         $a0, $zero, L_8008B020
    if (ctx->r4 == 0) {
        // 0x8008AFE0: srl         $v1, $s6, 16
        ctx->r3 = S32(U32(ctx->r22) >> 16);
            goto L_8008B020;
    }
    // 0x8008AFE0: srl         $v1, $s6, 16
    ctx->r3 = S32(U32(ctx->r22) >> 16);
    // 0x8008AFE4: sltiu       $v0, $v1, 0x7F
    ctx->r2 = ctx->r3 < 0X7F ? 1 : 0;
    // 0x8008AFE8: beq         $v0, $zero, L_8008B014
    if (ctx->r2 == 0) {
        // 0x8008AFEC: andi        $a1, $s6, 0xFFFF
        ctx->r5 = ctx->r22 & 0XFFFF;
            goto L_8008B014;
    }
    // 0x8008AFEC: andi        $a1, $s6, 0xFFFF
    ctx->r5 = ctx->r22 & 0XFFFF;
    // 0x8008AFF0: addu        $v0, $v1, $a0
    ctx->r2 = ADD32(ctx->r3, ctx->r4);
    // 0x8008AFF4: lbu         $v1, 0x1($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X1);
    // 0x8008AFF8: lbu         $v0, 0x0($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X0);
    // 0x8008AFFC: subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // 0x8008B000: mult        $v1, $a1
    result = S64(S32(ctx->r3)) * S64(S32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8008B004: mflo        $v1
    ctx->r3 = lo;
    // 0x8008B008: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x8008B00C: j           L_8008B020
    // 0x8008B010: addu        $s6, $v0, $v1
    ctx->r22 = ADD32(ctx->r2, ctx->r3);
        goto L_8008B020;
    // 0x8008B010: addu        $s6, $v0, $v1
    ctx->r22 = ADD32(ctx->r2, ctx->r3);
L_8008B014:
    // 0x8008B014: addu        $v0, $a0, $v1
    ctx->r2 = ADD32(ctx->r4, ctx->r3);
    // 0x8008B018: lbu         $v0, 0x0($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X0);
    // 0x8008B01C: sll         $s6, $v0, 16
    ctx->r22 = S32(ctx->r2 << 16);
L_8008B020:
    // 0x8008B020: lw          $a1, 0x30($s5)
    ctx->r5 = MEM_W(ctx->r21, 0X30);
    // 0x8008B024: addu        $v1, $s6, $zero
    ctx->r3 = ADD32(ctx->r22, 0);
    // 0x8008B028: subu        $a1, $v1, $a1
    ctx->r5 = SUB32(ctx->r3, ctx->r5);
    // 0x8008B02C: div         $zero, $a1, $s7
    if (S32(ctx->r23) != 0) { lo = S32(S64(S32(ctx->r5)) / S64(S32(ctx->r23))); hi = S32(S64(S32(ctx->r5)) % S64(S32(ctx->r23))); } else { lo = 0; hi = S32(ctx->r5); }
    // 0x8008B030: bne         $s7, $zero, L_8008B03C
    if (ctx->r23 != 0) {
        // 0x8008B034: nop
    
            goto L_8008B03C;
    }
    // 0x8008B034: nop

    // 0x8008B038: break       7
    do_break(2148053048);
L_8008B03C:
    // 0x8008B03C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8008B040: bne         $s7, $at, L_8008B054
    if (ctx->r23 != ctx->r1) {
        // 0x8008B044: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8008B054;
    }
    // 0x8008B044: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8008B048: bne         $a1, $at, L_8008B054
    if (ctx->r5 != ctx->r1) {
        // 0x8008B04C: nop
    
            goto L_8008B054;
    }
    // 0x8008B04C: nop

    // 0x8008B050: break       6
    do_break(2148053072);
L_8008B054:
    // 0x8008B054: mflo        $a1
    ctx->r5 = lo;
    // 0x8008B058: lw          $a0, 0x24($s5)
    ctx->r4 = MEM_W(ctx->r21, 0X24);
    // 0x8008B05C: sw          $v1, 0x90($s5)
    MEM_W(0X90, ctx->r21) = ctx->r3;
    // 0x8008B060: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // 0x8008B064: lui         $v1, 0x1
    ctx->r3 = S32(0X1 << 16);
    // 0x8008B068: or          $a0, $a0, $v1
    ctx->r4 = ctx->r4 | ctx->r3;
    // 0x8008B06C: sw          $a0, 0x24($s5)
    MEM_W(0X24, ctx->r21) = ctx->r4;
    // 0x8008B070: sw          $a1, 0x8C($s5)
    MEM_W(0X8C, ctx->r21) = ctx->r5;
    // 0x8008B074: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x8008B078: lw          $fp, 0x40($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X40);
    // 0x8008B07C: lw          $s7, 0x3C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X3C);
    // 0x8008B080: lw          $s6, 0x38($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X38);
    // 0x8008B084: lw          $s5, 0x34($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X34);
    // 0x8008B088: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x8008B08C: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x8008B090: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x8008B094: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x8008B098: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8008B09C: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x8008B0A0: jr          $ra
    // 0x8008B0A4: nop

    return;
    // 0x8008B0A4: nop

;}
RECOMP_FUNC void func_8008B0A8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008B0A8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8008B0AC: addu        $t0, $a1, $zero
    ctx->r8 = ADD32(ctx->r5, 0);
    // 0x8008B0B0: sw          $ra, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r31;
    // 0x8008B0B4: lbu         $v0, 0x6($t0)
    ctx->r2 = MEM_BU(ctx->r8, 0X6);
    // 0x8008B0B8: bne         $v0, $zero, L_8008B0E8
    if (ctx->r2 != 0) {
        // 0x8008B0BC: addu        $t2, $a0, $zero
        ctx->r10 = ADD32(ctx->r4, 0);
            goto L_8008B0E8;
    }
    // 0x8008B0BC: addu        $t2, $a0, $zero
    ctx->r10 = ADD32(ctx->r4, 0);
    // 0x8008B0C0: lw          $v0, 0x0($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X0);
    // 0x8008B0C4: srl         $a3, $v0, 8
    ctx->r7 = S32(U32(ctx->r2) >> 8);
    // 0x8008B0C8: srl         $a2, $v0, 24
    ctx->r6 = S32(U32(ctx->r2) >> 24);
    // 0x8008B0CC: andi        $v0, $a3, 0xFF
    ctx->r2 = ctx->r7 & 0XFF;
    // 0x8008B0D0: sltu        $v0, $a2, $v0
    ctx->r2 = ctx->r6 < ctx->r2 ? 1 : 0;
    // 0x8008B0D4: beq         $v0, $zero, L_8008B148
    if (ctx->r2 == 0) {
        // 0x8008B0D8: addu        $v0, $a3, $zero
        ctx->r2 = ADD32(ctx->r7, 0);
            goto L_8008B148;
    }
    // 0x8008B0D8: addu        $v0, $a3, $zero
    ctx->r2 = ADD32(ctx->r7, 0);
    // 0x8008B0DC: addu        $a3, $a2, $zero
    ctx->r7 = ADD32(ctx->r6, 0);
    // 0x8008B0E0: j           L_8008B148
    // 0x8008B0E4: addu        $a2, $v0, $zero
    ctx->r6 = ADD32(ctx->r2, 0);
        goto L_8008B148;
    // 0x8008B0E4: addu        $a2, $v0, $zero
    ctx->r6 = ADD32(ctx->r2, 0);
L_8008B0E8:
    // 0x8008B0E8: lhu         $v0, 0x54($t2)
    ctx->r2 = MEM_HU(ctx->r10, 0X54);
    // 0x8008B0EC: lbu         $v1, 0x0($t0)
    ctx->r3 = MEM_BU(ctx->r8, 0X0);
    // 0x8008B0F0: lbu         $a0, 0x2($t0)
    ctx->r4 = MEM_BU(ctx->r8, 0X2);
    // 0x8008B0F4: addu        $a1, $v0, $v1
    ctx->r5 = ADD32(ctx->r2, ctx->r3);
    // 0x8008B0F8: subu        $v0, $v0, $a0
    ctx->r2 = SUB32(ctx->r2, ctx->r4);
    // 0x8008B0FC: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // 0x8008B100: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x8008B104: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x8008B108: bltz        $v0, L_8008B120
    if (SIGNED(ctx->r2) < 0) {
        // 0x8008B10C: slti        $v0, $v0, 0x80
        ctx->r2 = SIGNED(ctx->r2) < 0X80 ? 1 : 0;
            goto L_8008B120;
    }
    // 0x8008B10C: slti        $v0, $v0, 0x80
    ctx->r2 = SIGNED(ctx->r2) < 0X80 ? 1 : 0;
    // 0x8008B110: beq         $v0, $zero, L_8008B124
    if (ctx->r2 == 0) {
        // 0x8008B114: addiu       $a3, $zero, 0x7F
        ctx->r7 = ADD32(0, 0X7F);
            goto L_8008B124;
    }
    // 0x8008B114: addiu       $a3, $zero, 0x7F
    ctx->r7 = ADD32(0, 0X7F);
    // 0x8008B118: j           L_8008B124
    // 0x8008B11C: addu        $a3, $v1, $zero
    ctx->r7 = ADD32(ctx->r3, 0);
        goto L_8008B124;
    // 0x8008B11C: addu        $a3, $v1, $zero
    ctx->r7 = ADD32(ctx->r3, 0);
L_8008B120:
    // 0x8008B120: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
L_8008B124:
    // 0x8008B124: sll         $v0, $a1, 16
    ctx->r2 = S32(ctx->r5 << 16);
    // 0x8008B128: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x8008B12C: bltz        $v0, L_8008B144
    if (SIGNED(ctx->r2) < 0) {
        // 0x8008B130: slti        $v0, $v0, 0x80
        ctx->r2 = SIGNED(ctx->r2) < 0X80 ? 1 : 0;
            goto L_8008B144;
    }
    // 0x8008B130: slti        $v0, $v0, 0x80
    ctx->r2 = SIGNED(ctx->r2) < 0X80 ? 1 : 0;
    // 0x8008B134: beq         $v0, $zero, L_8008B148
    if (ctx->r2 == 0) {
        // 0x8008B138: addiu       $a2, $zero, 0x7F
        ctx->r6 = ADD32(0, 0X7F);
            goto L_8008B148;
    }
    // 0x8008B138: addiu       $a2, $zero, 0x7F
    ctx->r6 = ADD32(0, 0X7F);
    // 0x8008B13C: j           L_8008B148
    // 0x8008B140: addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
        goto L_8008B148;
    // 0x8008B140: addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
L_8008B144:
    // 0x8008B144: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
L_8008B148:
    // 0x8008B148: lbu         $v0, 0x7($t0)
    ctx->r2 = MEM_BU(ctx->r8, 0X7);
    // 0x8008B14C: beq         $v0, $zero, L_8008B1B0
    if (ctx->r2 == 0) {
        // 0x8008B150: lui         $v1, 0xA835
        ctx->r3 = S32(0XA835 << 16);
            goto L_8008B1B0;
    }
    // 0x8008B150: lui         $v1, 0xA835
    ctx->r3 = S32(0XA835 << 16);
    // 0x8008B154: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x8008B158: lw          $v0, 0xF54($v0)
    ctx->r2 = MEM_W(ctx->r2, 0XF54);
    // 0x8008B15C: ori         $v1, $v1, 0x1D63
    ctx->r3 = ctx->r3 | 0X1D63;
    // 0x8008B160: mult        $v0, $v1
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8008B164: mflo        $v0
    ctx->r2 = lo;
    // 0x8008B168: lui         $v1, 0x28C
    ctx->r3 = S32(0X28C << 16);
    // 0x8008B16C: ori         $v1, $v1, 0x1979
    ctx->r3 = ctx->r3 | 0X1979;
    // 0x8008B170: srl         $a0, $v0, 6
    ctx->r4 = S32(U32(ctx->r2) >> 6);
    // 0x8008B174: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    // 0x8008B178: multu       $a0, $v1
    result = U64(U32(ctx->r4)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8008B17C: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x8008B180: sw          $v0, 0xF54($at)
    MEM_W(0XF54, ctx->r1) = ctx->r2;
    // 0x8008B184: mfhi        $t3
    ctx->r11 = hi;
    // 0x8008B188: srl         $v1, $t3, 1
    ctx->r3 = S32(U32(ctx->r11) >> 1);
    // 0x8008B18C: sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3 << 1);
    // 0x8008B190: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8008B194: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x8008B198: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8008B19C: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x8008B1A0: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8008B1A4: subu        $a0, $a0, $v0
    ctx->r4 = SUB32(ctx->r4, ctx->r2);
    // 0x8008B1A8: j           L_8008B1B4
    // 0x8008B1AC: addiu       $t1, $a0, -0x64
    ctx->r9 = ADD32(ctx->r4, -0X64);
        goto L_8008B1B4;
    // 0x8008B1AC: addiu       $t1, $a0, -0x64
    ctx->r9 = ADD32(ctx->r4, -0X64);
L_8008B1B0:
    // 0x8008B1B0: lbu         $t1, 0x1($t0)
    ctx->r9 = MEM_BU(ctx->r8, 0X1);
L_8008B1B4:
    // 0x8008B1B4: lui         $a1, 0x800A
    ctx->r5 = S32(0X800A << 16);
    // 0x8008B1B8: lw          $a1, 0xF54($a1)
    ctx->r5 = MEM_W(ctx->r5, 0XF54);
    // 0x8008B1BC: lui         $v0, 0xA835
    ctx->r2 = S32(0XA835 << 16);
    // 0x8008B1C0: ori         $v0, $v0, 0x1D63
    ctx->r2 = ctx->r2 | 0X1D63;
    // 0x8008B1C4: mult        $a1, $v0
    result = S64(S32(ctx->r5)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8008B1C8: mflo        $a1
    ctx->r5 = lo;
    // 0x8008B1CC: andi        $v1, $a3, 0xFF
    ctx->r3 = ctx->r7 & 0XFF;
    // 0x8008B1D0: andi        $v0, $a2, 0xFF
    ctx->r2 = ctx->r6 & 0XFF;
    // 0x8008B1D4: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x8008B1D8: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8008B1DC: srl         $a0, $a1, 6
    ctx->r4 = S32(U32(ctx->r5) >> 6);
    // 0x8008B1E0: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    // 0x8008B1E4: div         $zero, $a0, $v0
    if (S32(ctx->r2) != 0) { lo = S32(S64(S32(ctx->r4)) / S64(S32(ctx->r2))); hi = S32(S64(S32(ctx->r4)) % S64(S32(ctx->r2))); } else { lo = 0; hi = S32(ctx->r4); }
    // 0x8008B1E8: bne         $v0, $zero, L_8008B1F4
    if (ctx->r2 != 0) {
        // 0x8008B1EC: nop
    
            goto L_8008B1F4;
    }
    // 0x8008B1EC: nop

    // 0x8008B1F0: break       7
    do_break(2148053488);
L_8008B1F4:
    // 0x8008B1F4: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8008B1F8: bne         $v0, $at, L_8008B20C
    if (ctx->r2 != ctx->r1) {
        // 0x8008B1FC: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8008B20C;
    }
    // 0x8008B1FC: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8008B200: bne         $a0, $at, L_8008B20C
    if (ctx->r4 != ctx->r1) {
        // 0x8008B204: nop
    
            goto L_8008B20C;
    }
    // 0x8008B204: nop

    // 0x8008B208: break       6
    do_break(2148053512);
L_8008B20C:
    // 0x8008B20C: mfhi        $a2
    ctx->r6 = hi;
    // 0x8008B210: sw          $zero, 0x4($t0)
    MEM_W(0X4, ctx->r8) = 0;
    // 0x8008B214: andi        $v0, $t1, 0xFF
    ctx->r2 = ctx->r9 & 0XFF;
    // 0x8008B218: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x8008B21C: addu        $a0, $t2, $zero
    ctx->r4 = ADD32(ctx->r10, 0);
    // 0x8008B220: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x8008B224: sw          $a1, 0xF54($at)
    MEM_W(0XF54, ctx->r1) = ctx->r5;
    // 0x8008B228: addu        $a1, $t0, $zero
    ctx->r5 = ADD32(ctx->r8, 0);
    // 0x8008B22C: addu        $v1, $v1, $a2
    ctx->r3 = ADD32(ctx->r3, ctx->r6);
    // 0x8008B230: sll         $v1, $v1, 8
    ctx->r3 = S32(ctx->r3 << 8);
    // 0x8008B234: ori         $v1, $v1, 0x19
    ctx->r3 = ctx->r3 | 0X19;
    // 0x8008B238: or          $v0, $v0, $v1
    ctx->r2 = ctx->r2 | ctx->r3;
    // 0x8008B23C: jal         0x8008A014
    // 0x8008B240: sw          $v0, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r2;
    func_8008A014(rdram, ctx);
        goto after_0;
    // 0x8008B240: sw          $v0, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r2;
    after_0:
    // 0x8008B244: lw          $ra, 0x18($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X18);
    // 0x8008B248: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // 0x8008B24C: jr          $ra
    // 0x8008B250: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x8008B250: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_8008B254(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008B254: lw          $v0, 0x24($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X24);
    // 0x8008B258: lui         $v1, 0x2
    ctx->r3 = S32(0X2 << 16);
    // 0x8008B25C: or          $v0, $v0, $v1
    ctx->r2 = ctx->r2 | ctx->r3;
    // 0x8008B260: sw          $v0, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->r2;
    // 0x8008B264: jr          $ra
    // 0x8008B268: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    return;
    // 0x8008B268: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
;}
RECOMP_FUNC void func_8008B26C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008B26C: lw          $v0, 0x24($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X24);
    // 0x8008B270: lui         $v1, 0x4
    ctx->r3 = S32(0X4 << 16);
    // 0x8008B274: or          $v0, $v0, $v1
    ctx->r2 = ctx->r2 | ctx->r3;
    // 0x8008B278: sw          $v0, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->r2;
    // 0x8008B27C: jr          $ra
    // 0x8008B280: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    return;
    // 0x8008B280: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
;}
RECOMP_FUNC void func_8008B284(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008B284: addu        $a3, $a0, $zero
    ctx->r7 = ADD32(ctx->r4, 0);
    // 0x8008B288: lbu         $a0, 0x10($a3)
    ctx->r4 = MEM_BU(ctx->r7, 0X10);
    // 0x8008B28C: sltiu       $v0, $a0, 0x4
    ctx->r2 = ctx->r4 < 0X4 ? 1 : 0;
    // 0x8008B290: beq         $v0, $zero, L_8008B334
    if (ctx->r2 == 0) {
        // 0x8008B294: addiu       $v0, $a0, 0x1
        ctx->r2 = ADD32(ctx->r4, 0X1);
            goto L_8008B334;
    }
    // 0x8008B294: addiu       $v0, $a0, 0x1
    ctx->r2 = ADD32(ctx->r4, 0X1);
    // 0x8008B298: sb          $v0, 0x10($a3)
    MEM_B(0X10, ctx->r7) = ctx->r2;
    // 0x8008B29C: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x8008B2A0: srl         $v1, $v0, 8
    ctx->r3 = S32(U32(ctx->r2) >> 8);
    // 0x8008B2A4: andi        $v0, $v1, 0xFF
    ctx->r2 = ctx->r3 & 0XFF;
    // 0x8008B2A8: addiu       $a2, $v0, -0x80
    ctx->r6 = ADD32(ctx->r2, -0X80);
    // 0x8008B2AC: sltiu       $v0, $a2, 0x6
    ctx->r2 = ctx->r6 < 0X6 ? 1 : 0;
    // 0x8008B2B0: beq         $v0, $zero, L_8008B2F8
    if (ctx->r2 == 0) {
        // 0x8008B2B4: sll         $v0, $a2, 2
        ctx->r2 = S32(ctx->r6 << 2);
            goto L_8008B2F8;
    }
    // 0x8008B2B4: sll         $v0, $a2, 2
    ctx->r2 = S32(ctx->r6 << 2);
    // 0x8008B2B8: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8008B2BC: addu        $at, $at, $v0
    gpr jr_addend_8008B2C4 = ctx->r2;
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x8008B2C0: lw          $v0, -0x24D0($at)
    ctx->r2 = ADD32(ctx->r1, -0X24D0);
    // 0x8008B2C4: jr          $v0
    // 0x8008B2C8: nop

    switch (jr_addend_8008B2C4 >> 2) {
        case 0: goto L_8008B2CC; break;
        case 1: goto L_8008B2D4; break;
        case 2: goto L_8008B2DC; break;
        case 3: goto L_8008B2E4; break;
        case 4: goto L_8008B2EC; break;
        case 5: goto L_8008B2F4; break;
        default: switch_error(__func__, 0x8008B2C4, 0x8003DB30);
    }
    // 0x8008B2C8: nop

L_8008B2CC:
    // 0x8008B2CC: j           L_8008B2F8
    // 0x8008B2D0: addiu       $v1, $zero, 0x80
    ctx->r3 = ADD32(0, 0X80);
        goto L_8008B2F8;
    // 0x8008B2D0: addiu       $v1, $zero, 0x80
    ctx->r3 = ADD32(0, 0X80);
L_8008B2D4:
    // 0x8008B2D4: j           L_8008B2F8
    // 0x8008B2D8: addiu       $v1, $zero, 0x82
    ctx->r3 = ADD32(0, 0X82);
        goto L_8008B2F8;
    // 0x8008B2D8: addiu       $v1, $zero, 0x82
    ctx->r3 = ADD32(0, 0X82);
L_8008B2DC:
    // 0x8008B2DC: j           L_8008B2F8
    // 0x8008B2E0: addiu       $v1, $zero, 0xA0
    ctx->r3 = ADD32(0, 0XA0);
        goto L_8008B2F8;
    // 0x8008B2E0: addiu       $v1, $zero, 0xA0
    ctx->r3 = ADD32(0, 0XA0);
L_8008B2E4:
    // 0x8008B2E4: j           L_8008B2F8
    // 0x8008B2E8: addiu       $v1, $zero, 0xA1
    ctx->r3 = ADD32(0, 0XA1);
        goto L_8008B2F8;
    // 0x8008B2E8: addiu       $v1, $zero, 0xA1
    ctx->r3 = ADD32(0, 0XA1);
L_8008B2EC:
    // 0x8008B2EC: j           L_8008B2F8
    // 0x8008B2F0: addiu       $v1, $zero, 0x83
    ctx->r3 = ADD32(0, 0X83);
        goto L_8008B2F8;
    // 0x8008B2F0: addiu       $v1, $zero, 0x83
    ctx->r3 = ADD32(0, 0X83);
L_8008B2F4:
    // 0x8008B2F4: addiu       $v1, $zero, 0x84
    ctx->r3 = ADD32(0, 0X84);
L_8008B2F8:
    // 0x8008B2F8: sll         $a0, $a0, 2
    ctx->r4 = S32(ctx->r4 << 2);
    // 0x8008B2FC: addu        $a0, $a3, $a0
    ctx->r4 = ADD32(ctx->r7, ctx->r4);
    // 0x8008B300: sb          $v1, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r3;
    // 0x8008B304: lw          $v0, 0x4($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X4);
    // 0x8008B308: sb          $v0, 0x1($a0)
    MEM_B(0X1, ctx->r4) = ctx->r2;
    // 0x8008B30C: lh          $v1, 0x0($a1)
    ctx->r3 = MEM_H(ctx->r5, 0X0);
    // 0x8008B310: lui         $v0, 0x51EB
    ctx->r2 = S32(0X51EB << 16);
    // 0x8008B314: ori         $v0, $v0, 0x851F
    ctx->r2 = ctx->r2 | 0X851F;
    // 0x8008B318: sll         $v1, $v1, 8
    ctx->r3 = S32(ctx->r3 << 8);
    // 0x8008B31C: mult        $v1, $v0
    result = S64(S32(ctx->r3)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8008B320: sra         $v1, $v1, 31
    ctx->r3 = S32(SIGNED(ctx->r3) >> 31);
    // 0x8008B324: mfhi        $t0
    ctx->r8 = hi;
    // 0x8008B328: sra         $v0, $t0, 5
    ctx->r2 = S32(SIGNED(ctx->r8) >> 5);
    // 0x8008B32C: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x8008B330: sh          $v0, 0x2($a0)
    MEM_H(0X2, ctx->r4) = ctx->r2;
L_8008B334:
    // 0x8008B334: jr          $ra
    // 0x8008B338: nop

    return;
    // 0x8008B338: nop

;}
RECOMP_FUNC void func_8008B33C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008B33C: addu        $a2, $a0, $zero
    ctx->r6 = ADD32(ctx->r4, 0);
    // 0x8008B340: lw          $a0, 0x24($a2)
    ctx->r4 = MEM_W(ctx->r6, 0X24);
    // 0x8008B344: lbu         $v1, 0x7($a1)
    ctx->r3 = MEM_BU(ctx->r5, 0X7);
    // 0x8008B348: srl         $v0, $a0, 20
    ctx->r2 = S32(U32(ctx->r4) >> 20);
    // 0x8008B34C: xori        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 ^ 0X1;
    // 0x8008B350: andi        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 & 0X1;
    // 0x8008B354: sltiu       $v1, $v1, 0x1
    ctx->r3 = ctx->r3 < 0X1 ? 1 : 0;
    // 0x8008B358: or          $v0, $v0, $v1
    ctx->r2 = ctx->r2 | ctx->r3;
    // 0x8008B35C: beq         $v0, $zero, L_8008B370
    if (ctx->r2 == 0) {
        // 0x8008B360: lui         $v0, 0x10
        ctx->r2 = S32(0X10 << 16);
            goto L_8008B370;
    }
    // 0x8008B360: lui         $v0, 0x10
    ctx->r2 = S32(0X10 << 16);
    // 0x8008B364: or          $v0, $a0, $v0
    ctx->r2 = ctx->r4 | ctx->r2;
    // 0x8008B368: sw          $v0, 0x24($a2)
    MEM_W(0X24, ctx->r6) = ctx->r2;
    // 0x8008B36C: sb          $zero, 0xD0($a2)
    MEM_B(0XD0, ctx->r6) = 0;
L_8008B370:
    // 0x8008B370: lbu         $a0, 0xD0($a2)
    ctx->r4 = MEM_BU(ctx->r6, 0XD0);
    // 0x8008B374: sltiu       $v0, $a0, 0x4
    ctx->r2 = ctx->r4 < 0X4 ? 1 : 0;
    // 0x8008B378: beq         $v0, $zero, L_8008B424
    if (ctx->r2 == 0) {
        // 0x8008B37C: addiu       $a3, $a2, 0xC0
        ctx->r7 = ADD32(ctx->r6, 0XC0);
            goto L_8008B424;
    }
    // 0x8008B37C: addiu       $a3, $a2, 0xC0
    ctx->r7 = ADD32(ctx->r6, 0XC0);
    // 0x8008B380: addiu       $v0, $a0, 0x1
    ctx->r2 = ADD32(ctx->r4, 0X1);
    // 0x8008B384: sb          $v0, 0xD0($a2)
    MEM_B(0XD0, ctx->r6) = ctx->r2;
    // 0x8008B388: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x8008B38C: srl         $v1, $v0, 8
    ctx->r3 = S32(U32(ctx->r2) >> 8);
    // 0x8008B390: andi        $v0, $v1, 0xFF
    ctx->r2 = ctx->r3 & 0XFF;
    // 0x8008B394: addiu       $a2, $v0, -0x80
    ctx->r6 = ADD32(ctx->r2, -0X80);
    // 0x8008B398: sltiu       $v0, $a2, 0x6
    ctx->r2 = ctx->r6 < 0X6 ? 1 : 0;
    // 0x8008B39C: beql        $v0, $zero, L_8008B3EC
    if (ctx->r2 == 0) {
        // 0x8008B3A0: sll         $a0, $a0, 2
        ctx->r4 = S32(ctx->r4 << 2);
            goto L_8008B3EC;
    }
    goto skip_0;
    // 0x8008B3A0: sll         $a0, $a0, 2
    ctx->r4 = S32(ctx->r4 << 2);
    skip_0:
    // 0x8008B3A4: sll         $v0, $a2, 2
    ctx->r2 = S32(ctx->r6 << 2);
    // 0x8008B3A8: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8008B3AC: addu        $at, $at, $v0
    gpr jr_addend_8008B3B4 = ctx->r2;
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x8008B3B0: lw          $v0, -0x24B8($at)
    ctx->r2 = ADD32(ctx->r1, -0X24B8);
    // 0x8008B3B4: jr          $v0
    // 0x8008B3B8: nop

    switch (jr_addend_8008B3B4 >> 2) {
        case 0: goto L_8008B3BC; break;
        case 1: goto L_8008B3C4; break;
        case 2: goto L_8008B3CC; break;
        case 3: goto L_8008B3D4; break;
        case 4: goto L_8008B3DC; break;
        case 5: goto L_8008B3E4; break;
        default: switch_error(__func__, 0x8008B3B4, 0x8003DB48);
    }
    // 0x8008B3B8: nop

L_8008B3BC:
    // 0x8008B3BC: j           L_8008B3E8
    // 0x8008B3C0: addiu       $v1, $zero, 0x80
    ctx->r3 = ADD32(0, 0X80);
        goto L_8008B3E8;
    // 0x8008B3C0: addiu       $v1, $zero, 0x80
    ctx->r3 = ADD32(0, 0X80);
L_8008B3C4:
    // 0x8008B3C4: j           L_8008B3E8
    // 0x8008B3C8: addiu       $v1, $zero, 0x82
    ctx->r3 = ADD32(0, 0X82);
        goto L_8008B3E8;
    // 0x8008B3C8: addiu       $v1, $zero, 0x82
    ctx->r3 = ADD32(0, 0X82);
L_8008B3CC:
    // 0x8008B3CC: j           L_8008B3E8
    // 0x8008B3D0: addiu       $v1, $zero, 0xA0
    ctx->r3 = ADD32(0, 0XA0);
        goto L_8008B3E8;
    // 0x8008B3D0: addiu       $v1, $zero, 0xA0
    ctx->r3 = ADD32(0, 0XA0);
L_8008B3D4:
    // 0x8008B3D4: j           L_8008B3E8
    // 0x8008B3D8: addiu       $v1, $zero, 0xA1
    ctx->r3 = ADD32(0, 0XA1);
        goto L_8008B3E8;
    // 0x8008B3D8: addiu       $v1, $zero, 0xA1
    ctx->r3 = ADD32(0, 0XA1);
L_8008B3DC:
    // 0x8008B3DC: j           L_8008B3E8
    // 0x8008B3E0: addiu       $v1, $zero, 0x83
    ctx->r3 = ADD32(0, 0X83);
        goto L_8008B3E8;
    // 0x8008B3E0: addiu       $v1, $zero, 0x83
    ctx->r3 = ADD32(0, 0X83);
L_8008B3E4:
    // 0x8008B3E4: addiu       $v1, $zero, 0x84
    ctx->r3 = ADD32(0, 0X84);
L_8008B3E8:
    // 0x8008B3E8: sll         $a0, $a0, 2
    ctx->r4 = S32(ctx->r4 << 2);
L_8008B3EC:
    // 0x8008B3EC: addu        $a0, $a3, $a0
    ctx->r4 = ADD32(ctx->r7, ctx->r4);
    // 0x8008B3F0: sb          $v1, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r3;
    // 0x8008B3F4: lw          $v0, 0x4($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X4);
    // 0x8008B3F8: sb          $v0, 0x1($a0)
    MEM_B(0X1, ctx->r4) = ctx->r2;
    // 0x8008B3FC: lh          $v1, 0x0($a1)
    ctx->r3 = MEM_H(ctx->r5, 0X0);
    // 0x8008B400: lui         $v0, 0x51EB
    ctx->r2 = S32(0X51EB << 16);
    // 0x8008B404: ori         $v0, $v0, 0x851F
    ctx->r2 = ctx->r2 | 0X851F;
    // 0x8008B408: sll         $v1, $v1, 8
    ctx->r3 = S32(ctx->r3 << 8);
    // 0x8008B40C: mult        $v1, $v0
    result = S64(S32(ctx->r3)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8008B410: sra         $v1, $v1, 31
    ctx->r3 = S32(SIGNED(ctx->r3) >> 31);
    // 0x8008B414: mfhi        $t0
    ctx->r8 = hi;
    // 0x8008B418: sra         $v0, $t0, 5
    ctx->r2 = S32(SIGNED(ctx->r8) >> 5);
    // 0x8008B41C: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x8008B420: sh          $v0, 0x2($a0)
    MEM_H(0X2, ctx->r4) = ctx->r2;
L_8008B424:
    // 0x8008B424: jr          $ra
    // 0x8008B428: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    return;
    // 0x8008B428: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
;}
RECOMP_FUNC void func_8008B42C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008B42C: addu        $a2, $a0, $zero
    ctx->r6 = ADD32(ctx->r4, 0);
    // 0x8008B430: lw          $a0, 0x24($a2)
    ctx->r4 = MEM_W(ctx->r6, 0X24);
    // 0x8008B434: lbu         $v1, 0x7($a1)
    ctx->r3 = MEM_BU(ctx->r5, 0X7);
    // 0x8008B438: srl         $v0, $a0, 21
    ctx->r2 = S32(U32(ctx->r4) >> 21);
    // 0x8008B43C: xori        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 ^ 0X1;
    // 0x8008B440: andi        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 & 0X1;
    // 0x8008B444: sltiu       $v1, $v1, 0x1
    ctx->r3 = ctx->r3 < 0X1 ? 1 : 0;
    // 0x8008B448: or          $v0, $v0, $v1
    ctx->r2 = ctx->r2 | ctx->r3;
    // 0x8008B44C: beq         $v0, $zero, L_8008B460
    if (ctx->r2 == 0) {
        // 0x8008B450: lui         $v0, 0x20
        ctx->r2 = S32(0X20 << 16);
            goto L_8008B460;
    }
    // 0x8008B450: lui         $v0, 0x20
    ctx->r2 = S32(0X20 << 16);
    // 0x8008B454: or          $v0, $a0, $v0
    ctx->r2 = ctx->r4 | ctx->r2;
    // 0x8008B458: sw          $v0, 0x24($a2)
    MEM_W(0X24, ctx->r6) = ctx->r2;
    // 0x8008B45C: sb          $zero, 0xE2($a2)
    MEM_B(0XE2, ctx->r6) = 0;
L_8008B460:
    // 0x8008B460: lbu         $a0, 0xE2($a2)
    ctx->r4 = MEM_BU(ctx->r6, 0XE2);
    // 0x8008B464: sltiu       $v0, $a0, 0x4
    ctx->r2 = ctx->r4 < 0X4 ? 1 : 0;
    // 0x8008B468: beq         $v0, $zero, L_8008B514
    if (ctx->r2 == 0) {
        // 0x8008B46C: addiu       $a3, $a2, 0xD2
        ctx->r7 = ADD32(ctx->r6, 0XD2);
            goto L_8008B514;
    }
    // 0x8008B46C: addiu       $a3, $a2, 0xD2
    ctx->r7 = ADD32(ctx->r6, 0XD2);
    // 0x8008B470: addiu       $v0, $a0, 0x1
    ctx->r2 = ADD32(ctx->r4, 0X1);
    // 0x8008B474: sb          $v0, 0xE2($a2)
    MEM_B(0XE2, ctx->r6) = ctx->r2;
    // 0x8008B478: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x8008B47C: srl         $v1, $v0, 8
    ctx->r3 = S32(U32(ctx->r2) >> 8);
    // 0x8008B480: andi        $v0, $v1, 0xFF
    ctx->r2 = ctx->r3 & 0XFF;
    // 0x8008B484: addiu       $a2, $v0, -0x80
    ctx->r6 = ADD32(ctx->r2, -0X80);
    // 0x8008B488: sltiu       $v0, $a2, 0x6
    ctx->r2 = ctx->r6 < 0X6 ? 1 : 0;
    // 0x8008B48C: beql        $v0, $zero, L_8008B4DC
    if (ctx->r2 == 0) {
        // 0x8008B490: sll         $a0, $a0, 2
        ctx->r4 = S32(ctx->r4 << 2);
            goto L_8008B4DC;
    }
    goto skip_0;
    // 0x8008B490: sll         $a0, $a0, 2
    ctx->r4 = S32(ctx->r4 << 2);
    skip_0:
    // 0x8008B494: sll         $v0, $a2, 2
    ctx->r2 = S32(ctx->r6 << 2);
    // 0x8008B498: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8008B49C: addu        $at, $at, $v0
    gpr jr_addend_8008B4A4 = ctx->r2;
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x8008B4A0: lw          $v0, -0x24A0($at)
    ctx->r2 = ADD32(ctx->r1, -0X24A0);
    // 0x8008B4A4: jr          $v0
    // 0x8008B4A8: nop

    switch (jr_addend_8008B4A4 >> 2) {
        case 0: goto L_8008B4AC; break;
        case 1: goto L_8008B4B4; break;
        case 2: goto L_8008B4BC; break;
        case 3: goto L_8008B4C4; break;
        case 4: goto L_8008B4CC; break;
        case 5: goto L_8008B4D4; break;
        default: switch_error(__func__, 0x8008B4A4, 0x8003DB60);
    }
    // 0x8008B4A8: nop

L_8008B4AC:
    // 0x8008B4AC: j           L_8008B4D8
    // 0x8008B4B0: addiu       $v1, $zero, 0x80
    ctx->r3 = ADD32(0, 0X80);
        goto L_8008B4D8;
    // 0x8008B4B0: addiu       $v1, $zero, 0x80
    ctx->r3 = ADD32(0, 0X80);
L_8008B4B4:
    // 0x8008B4B4: j           L_8008B4D8
    // 0x8008B4B8: addiu       $v1, $zero, 0x82
    ctx->r3 = ADD32(0, 0X82);
        goto L_8008B4D8;
    // 0x8008B4B8: addiu       $v1, $zero, 0x82
    ctx->r3 = ADD32(0, 0X82);
L_8008B4BC:
    // 0x8008B4BC: j           L_8008B4D8
    // 0x8008B4C0: addiu       $v1, $zero, 0xA0
    ctx->r3 = ADD32(0, 0XA0);
        goto L_8008B4D8;
    // 0x8008B4C0: addiu       $v1, $zero, 0xA0
    ctx->r3 = ADD32(0, 0XA0);
L_8008B4C4:
    // 0x8008B4C4: j           L_8008B4D8
    // 0x8008B4C8: addiu       $v1, $zero, 0xA1
    ctx->r3 = ADD32(0, 0XA1);
        goto L_8008B4D8;
    // 0x8008B4C8: addiu       $v1, $zero, 0xA1
    ctx->r3 = ADD32(0, 0XA1);
L_8008B4CC:
    // 0x8008B4CC: j           L_8008B4D8
    // 0x8008B4D0: addiu       $v1, $zero, 0x83
    ctx->r3 = ADD32(0, 0X83);
        goto L_8008B4D8;
    // 0x8008B4D0: addiu       $v1, $zero, 0x83
    ctx->r3 = ADD32(0, 0X83);
L_8008B4D4:
    // 0x8008B4D4: addiu       $v1, $zero, 0x84
    ctx->r3 = ADD32(0, 0X84);
L_8008B4D8:
    // 0x8008B4D8: sll         $a0, $a0, 2
    ctx->r4 = S32(ctx->r4 << 2);
L_8008B4DC:
    // 0x8008B4DC: addu        $a0, $a3, $a0
    ctx->r4 = ADD32(ctx->r7, ctx->r4);
    // 0x8008B4E0: sb          $v1, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r3;
    // 0x8008B4E4: lw          $v0, 0x4($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X4);
    // 0x8008B4E8: sb          $v0, 0x1($a0)
    MEM_B(0X1, ctx->r4) = ctx->r2;
    // 0x8008B4EC: lh          $v1, 0x0($a1)
    ctx->r3 = MEM_H(ctx->r5, 0X0);
    // 0x8008B4F0: lui         $v0, 0x51EB
    ctx->r2 = S32(0X51EB << 16);
    // 0x8008B4F4: ori         $v0, $v0, 0x851F
    ctx->r2 = ctx->r2 | 0X851F;
    // 0x8008B4F8: sll         $v1, $v1, 8
    ctx->r3 = S32(ctx->r3 << 8);
    // 0x8008B4FC: mult        $v1, $v0
    result = S64(S32(ctx->r3)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8008B500: sra         $v1, $v1, 31
    ctx->r3 = S32(SIGNED(ctx->r3) >> 31);
    // 0x8008B504: mfhi        $t0
    ctx->r8 = hi;
    // 0x8008B508: sra         $v0, $t0, 5
    ctx->r2 = S32(SIGNED(ctx->r8) >> 5);
    // 0x8008B50C: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x8008B510: sh          $v0, 0x2($a0)
    MEM_H(0X2, ctx->r4) = ctx->r2;
L_8008B514:
    // 0x8008B514: jr          $ra
    // 0x8008B518: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    return;
    // 0x8008B518: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
;}
RECOMP_FUNC void func_8008B51C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008B51C: addu        $a2, $a0, $zero
    ctx->r6 = ADD32(ctx->r4, 0);
    // 0x8008B520: lw          $a0, 0x24($a2)
    ctx->r4 = MEM_W(ctx->r6, 0X24);
    // 0x8008B524: lbu         $v1, 0x7($a1)
    ctx->r3 = MEM_BU(ctx->r5, 0X7);
    // 0x8008B528: srl         $v0, $a0, 22
    ctx->r2 = S32(U32(ctx->r4) >> 22);
    // 0x8008B52C: xori        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 ^ 0X1;
    // 0x8008B530: andi        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 & 0X1;
    // 0x8008B534: sltiu       $v1, $v1, 0x1
    ctx->r3 = ctx->r3 < 0X1 ? 1 : 0;
    // 0x8008B538: or          $v0, $v0, $v1
    ctx->r2 = ctx->r2 | ctx->r3;
    // 0x8008B53C: beq         $v0, $zero, L_8008B550
    if (ctx->r2 == 0) {
        // 0x8008B540: lui         $v0, 0x40
        ctx->r2 = S32(0X40 << 16);
            goto L_8008B550;
    }
    // 0x8008B540: lui         $v0, 0x40
    ctx->r2 = S32(0X40 << 16);
    // 0x8008B544: or          $v0, $a0, $v0
    ctx->r2 = ctx->r4 | ctx->r2;
    // 0x8008B548: sw          $v0, 0x24($a2)
    MEM_W(0X24, ctx->r6) = ctx->r2;
    // 0x8008B54C: sb          $zero, 0x106($a2)
    MEM_B(0X106, ctx->r6) = 0;
L_8008B550:
    // 0x8008B550: lbu         $a0, 0x106($a2)
    ctx->r4 = MEM_BU(ctx->r6, 0X106);
    // 0x8008B554: sltiu       $v0, $a0, 0x4
    ctx->r2 = ctx->r4 < 0X4 ? 1 : 0;
    // 0x8008B558: beq         $v0, $zero, L_8008B604
    if (ctx->r2 == 0) {
        // 0x8008B55C: addiu       $a3, $a2, 0xF6
        ctx->r7 = ADD32(ctx->r6, 0XF6);
            goto L_8008B604;
    }
    // 0x8008B55C: addiu       $a3, $a2, 0xF6
    ctx->r7 = ADD32(ctx->r6, 0XF6);
    // 0x8008B560: addiu       $v0, $a0, 0x1
    ctx->r2 = ADD32(ctx->r4, 0X1);
    // 0x8008B564: sb          $v0, 0x106($a2)
    MEM_B(0X106, ctx->r6) = ctx->r2;
    // 0x8008B568: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x8008B56C: srl         $v1, $v0, 8
    ctx->r3 = S32(U32(ctx->r2) >> 8);
    // 0x8008B570: andi        $v0, $v1, 0xFF
    ctx->r2 = ctx->r3 & 0XFF;
    // 0x8008B574: addiu       $a2, $v0, -0x80
    ctx->r6 = ADD32(ctx->r2, -0X80);
    // 0x8008B578: sltiu       $v0, $a2, 0x6
    ctx->r2 = ctx->r6 < 0X6 ? 1 : 0;
    // 0x8008B57C: beql        $v0, $zero, L_8008B5CC
    if (ctx->r2 == 0) {
        // 0x8008B580: sll         $a0, $a0, 2
        ctx->r4 = S32(ctx->r4 << 2);
            goto L_8008B5CC;
    }
    goto skip_0;
    // 0x8008B580: sll         $a0, $a0, 2
    ctx->r4 = S32(ctx->r4 << 2);
    skip_0:
    // 0x8008B584: sll         $v0, $a2, 2
    ctx->r2 = S32(ctx->r6 << 2);
    // 0x8008B588: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8008B58C: addu        $at, $at, $v0
    gpr jr_addend_8008B594 = ctx->r2;
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x8008B590: lw          $v0, -0x2488($at)
    ctx->r2 = ADD32(ctx->r1, -0X2488);
    // 0x8008B594: jr          $v0
    // 0x8008B598: nop

    switch (jr_addend_8008B594 >> 2) {
        case 0: goto L_8008B59C; break;
        case 1: goto L_8008B5A4; break;
        case 2: goto L_8008B5AC; break;
        case 3: goto L_8008B5B4; break;
        case 4: goto L_8008B5BC; break;
        case 5: goto L_8008B5C4; break;
        default: switch_error(__func__, 0x8008B594, 0x8003DB78);
    }
    // 0x8008B598: nop

L_8008B59C:
    // 0x8008B59C: j           L_8008B5C8
    // 0x8008B5A0: addiu       $v1, $zero, 0x80
    ctx->r3 = ADD32(0, 0X80);
        goto L_8008B5C8;
    // 0x8008B5A0: addiu       $v1, $zero, 0x80
    ctx->r3 = ADD32(0, 0X80);
L_8008B5A4:
    // 0x8008B5A4: j           L_8008B5C8
    // 0x8008B5A8: addiu       $v1, $zero, 0x82
    ctx->r3 = ADD32(0, 0X82);
        goto L_8008B5C8;
    // 0x8008B5A8: addiu       $v1, $zero, 0x82
    ctx->r3 = ADD32(0, 0X82);
L_8008B5AC:
    // 0x8008B5AC: j           L_8008B5C8
    // 0x8008B5B0: addiu       $v1, $zero, 0xA0
    ctx->r3 = ADD32(0, 0XA0);
        goto L_8008B5C8;
    // 0x8008B5B0: addiu       $v1, $zero, 0xA0
    ctx->r3 = ADD32(0, 0XA0);
L_8008B5B4:
    // 0x8008B5B4: j           L_8008B5C8
    // 0x8008B5B8: addiu       $v1, $zero, 0xA1
    ctx->r3 = ADD32(0, 0XA1);
        goto L_8008B5C8;
    // 0x8008B5B8: addiu       $v1, $zero, 0xA1
    ctx->r3 = ADD32(0, 0XA1);
L_8008B5BC:
    // 0x8008B5BC: j           L_8008B5C8
    // 0x8008B5C0: addiu       $v1, $zero, 0x83
    ctx->r3 = ADD32(0, 0X83);
        goto L_8008B5C8;
    // 0x8008B5C0: addiu       $v1, $zero, 0x83
    ctx->r3 = ADD32(0, 0X83);
L_8008B5C4:
    // 0x8008B5C4: addiu       $v1, $zero, 0x84
    ctx->r3 = ADD32(0, 0X84);
L_8008B5C8:
    // 0x8008B5C8: sll         $a0, $a0, 2
    ctx->r4 = S32(ctx->r4 << 2);
L_8008B5CC:
    // 0x8008B5CC: addu        $a0, $a3, $a0
    ctx->r4 = ADD32(ctx->r7, ctx->r4);
    // 0x8008B5D0: sb          $v1, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r3;
    // 0x8008B5D4: lw          $v0, 0x4($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X4);
    // 0x8008B5D8: sb          $v0, 0x1($a0)
    MEM_B(0X1, ctx->r4) = ctx->r2;
    // 0x8008B5DC: lh          $v1, 0x0($a1)
    ctx->r3 = MEM_H(ctx->r5, 0X0);
    // 0x8008B5E0: lui         $v0, 0x51EB
    ctx->r2 = S32(0X51EB << 16);
    // 0x8008B5E4: ori         $v0, $v0, 0x851F
    ctx->r2 = ctx->r2 | 0X851F;
    // 0x8008B5E8: sll         $v1, $v1, 8
    ctx->r3 = S32(ctx->r3 << 8);
    // 0x8008B5EC: mult        $v1, $v0
    result = S64(S32(ctx->r3)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8008B5F0: sra         $v1, $v1, 31
    ctx->r3 = S32(SIGNED(ctx->r3) >> 31);
    // 0x8008B5F4: mfhi        $t0
    ctx->r8 = hi;
    // 0x8008B5F8: sra         $v0, $t0, 5
    ctx->r2 = S32(SIGNED(ctx->r8) >> 5);
    // 0x8008B5FC: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x8008B600: sh          $v0, 0x2($a0)
    MEM_H(0X2, ctx->r4) = ctx->r2;
L_8008B604:
    // 0x8008B604: jr          $ra
    // 0x8008B608: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    return;
    // 0x8008B608: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
;}
RECOMP_FUNC void func_8008B60C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008B60C: addu        $a2, $a0, $zero
    ctx->r6 = ADD32(ctx->r4, 0);
    // 0x8008B610: lw          $a0, 0x24($a2)
    ctx->r4 = MEM_W(ctx->r6, 0X24);
    // 0x8008B614: lbu         $v1, 0x7($a1)
    ctx->r3 = MEM_BU(ctx->r5, 0X7);
    // 0x8008B618: srl         $v0, $a0, 23
    ctx->r2 = S32(U32(ctx->r4) >> 23);
    // 0x8008B61C: xori        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 ^ 0X1;
    // 0x8008B620: andi        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 & 0X1;
    // 0x8008B624: sltiu       $v1, $v1, 0x1
    ctx->r3 = ctx->r3 < 0X1 ? 1 : 0;
    // 0x8008B628: or          $v0, $v0, $v1
    ctx->r2 = ctx->r2 | ctx->r3;
    // 0x8008B62C: beq         $v0, $zero, L_8008B640
    if (ctx->r2 == 0) {
        // 0x8008B630: lui         $v0, 0x80
        ctx->r2 = S32(0X80 << 16);
            goto L_8008B640;
    }
    // 0x8008B630: lui         $v0, 0x80
    ctx->r2 = S32(0X80 << 16);
    // 0x8008B634: or          $v0, $a0, $v0
    ctx->r2 = ctx->r4 | ctx->r2;
    // 0x8008B638: sw          $v0, 0x24($a2)
    MEM_W(0X24, ctx->r6) = ctx->r2;
    // 0x8008B63C: sb          $zero, 0x12A($a2)
    MEM_B(0X12A, ctx->r6) = 0;
L_8008B640:
    // 0x8008B640: lbu         $a0, 0x12A($a2)
    ctx->r4 = MEM_BU(ctx->r6, 0X12A);
    // 0x8008B644: sltiu       $v0, $a0, 0x4
    ctx->r2 = ctx->r4 < 0X4 ? 1 : 0;
    // 0x8008B648: beq         $v0, $zero, L_8008B6F4
    if (ctx->r2 == 0) {
        // 0x8008B64C: addiu       $a3, $a2, 0x11A
        ctx->r7 = ADD32(ctx->r6, 0X11A);
            goto L_8008B6F4;
    }
    // 0x8008B64C: addiu       $a3, $a2, 0x11A
    ctx->r7 = ADD32(ctx->r6, 0X11A);
    // 0x8008B650: addiu       $v0, $a0, 0x1
    ctx->r2 = ADD32(ctx->r4, 0X1);
    // 0x8008B654: sb          $v0, 0x12A($a2)
    MEM_B(0X12A, ctx->r6) = ctx->r2;
    // 0x8008B658: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x8008B65C: srl         $v1, $v0, 8
    ctx->r3 = S32(U32(ctx->r2) >> 8);
    // 0x8008B660: andi        $v0, $v1, 0xFF
    ctx->r2 = ctx->r3 & 0XFF;
    // 0x8008B664: addiu       $a2, $v0, -0x80
    ctx->r6 = ADD32(ctx->r2, -0X80);
    // 0x8008B668: sltiu       $v0, $a2, 0x6
    ctx->r2 = ctx->r6 < 0X6 ? 1 : 0;
    // 0x8008B66C: beql        $v0, $zero, L_8008B6BC
    if (ctx->r2 == 0) {
        // 0x8008B670: sll         $a0, $a0, 2
        ctx->r4 = S32(ctx->r4 << 2);
            goto L_8008B6BC;
    }
    goto skip_0;
    // 0x8008B670: sll         $a0, $a0, 2
    ctx->r4 = S32(ctx->r4 << 2);
    skip_0:
    // 0x8008B674: sll         $v0, $a2, 2
    ctx->r2 = S32(ctx->r6 << 2);
    // 0x8008B678: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8008B67C: addu        $at, $at, $v0
    gpr jr_addend_8008B684 = ctx->r2;
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x8008B680: lw          $v0, -0x2470($at)
    ctx->r2 = ADD32(ctx->r1, -0X2470);
    // 0x8008B684: jr          $v0
    // 0x8008B688: nop

    switch (jr_addend_8008B684 >> 2) {
        case 0: goto L_8008B68C; break;
        case 1: goto L_8008B694; break;
        case 2: goto L_8008B69C; break;
        case 3: goto L_8008B6A4; break;
        case 4: goto L_8008B6AC; break;
        case 5: goto L_8008B6B4; break;
        default: switch_error(__func__, 0x8008B684, 0x8003DB90);
    }
    // 0x8008B688: nop

L_8008B68C:
    // 0x8008B68C: j           L_8008B6B8
    // 0x8008B690: addiu       $v1, $zero, 0x80
    ctx->r3 = ADD32(0, 0X80);
        goto L_8008B6B8;
    // 0x8008B690: addiu       $v1, $zero, 0x80
    ctx->r3 = ADD32(0, 0X80);
L_8008B694:
    // 0x8008B694: j           L_8008B6B8
    // 0x8008B698: addiu       $v1, $zero, 0x82
    ctx->r3 = ADD32(0, 0X82);
        goto L_8008B6B8;
    // 0x8008B698: addiu       $v1, $zero, 0x82
    ctx->r3 = ADD32(0, 0X82);
L_8008B69C:
    // 0x8008B69C: j           L_8008B6B8
    // 0x8008B6A0: addiu       $v1, $zero, 0xA0
    ctx->r3 = ADD32(0, 0XA0);
        goto L_8008B6B8;
    // 0x8008B6A0: addiu       $v1, $zero, 0xA0
    ctx->r3 = ADD32(0, 0XA0);
L_8008B6A4:
    // 0x8008B6A4: j           L_8008B6B8
    // 0x8008B6A8: addiu       $v1, $zero, 0xA1
    ctx->r3 = ADD32(0, 0XA1);
        goto L_8008B6B8;
    // 0x8008B6A8: addiu       $v1, $zero, 0xA1
    ctx->r3 = ADD32(0, 0XA1);
L_8008B6AC:
    // 0x8008B6AC: j           L_8008B6B8
    // 0x8008B6B0: addiu       $v1, $zero, 0x83
    ctx->r3 = ADD32(0, 0X83);
        goto L_8008B6B8;
    // 0x8008B6B0: addiu       $v1, $zero, 0x83
    ctx->r3 = ADD32(0, 0X83);
L_8008B6B4:
    // 0x8008B6B4: addiu       $v1, $zero, 0x84
    ctx->r3 = ADD32(0, 0X84);
L_8008B6B8:
    // 0x8008B6B8: sll         $a0, $a0, 2
    ctx->r4 = S32(ctx->r4 << 2);
L_8008B6BC:
    // 0x8008B6BC: addu        $a0, $a3, $a0
    ctx->r4 = ADD32(ctx->r7, ctx->r4);
    // 0x8008B6C0: sb          $v1, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r3;
    // 0x8008B6C4: lw          $v0, 0x4($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X4);
    // 0x8008B6C8: sb          $v0, 0x1($a0)
    MEM_B(0X1, ctx->r4) = ctx->r2;
    // 0x8008B6CC: lh          $v1, 0x0($a1)
    ctx->r3 = MEM_H(ctx->r5, 0X0);
    // 0x8008B6D0: lui         $v0, 0x51EB
    ctx->r2 = S32(0X51EB << 16);
    // 0x8008B6D4: ori         $v0, $v0, 0x851F
    ctx->r2 = ctx->r2 | 0X851F;
    // 0x8008B6D8: sll         $v1, $v1, 8
    ctx->r3 = S32(ctx->r3 << 8);
    // 0x8008B6DC: mult        $v1, $v0
    result = S64(S32(ctx->r3)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8008B6E0: sra         $v1, $v1, 31
    ctx->r3 = S32(SIGNED(ctx->r3) >> 31);
    // 0x8008B6E4: mfhi        $t0
    ctx->r8 = hi;
    // 0x8008B6E8: sra         $v0, $t0, 5
    ctx->r2 = S32(SIGNED(ctx->r8) >> 5);
    // 0x8008B6EC: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x8008B6F0: sh          $v0, 0x2($a0)
    MEM_H(0X2, ctx->r4) = ctx->r2;
L_8008B6F4:
    // 0x8008B6F4: jr          $ra
    // 0x8008B6F8: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    return;
    // 0x8008B6F8: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
;}
RECOMP_FUNC void func_8008B6FC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008B6FC: addu        $a2, $a0, $zero
    ctx->r6 = ADD32(ctx->r4, 0);
    // 0x8008B700: lw          $a0, 0x24($a2)
    ctx->r4 = MEM_W(ctx->r6, 0X24);
    // 0x8008B704: lbu         $v1, 0x7($a1)
    ctx->r3 = MEM_BU(ctx->r5, 0X7);
    // 0x8008B708: srl         $v0, $a0, 25
    ctx->r2 = S32(U32(ctx->r4) >> 25);
    // 0x8008B70C: xori        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 ^ 0X1;
    // 0x8008B710: andi        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 & 0X1;
    // 0x8008B714: sltiu       $v1, $v1, 0x1
    ctx->r3 = ctx->r3 < 0X1 ? 1 : 0;
    // 0x8008B718: or          $v0, $v0, $v1
    ctx->r2 = ctx->r2 | ctx->r3;
    // 0x8008B71C: beq         $v0, $zero, L_8008B730
    if (ctx->r2 == 0) {
        // 0x8008B720: lui         $v0, 0x200
        ctx->r2 = S32(0X200 << 16);
            goto L_8008B730;
    }
    // 0x8008B720: lui         $v0, 0x200
    ctx->r2 = S32(0X200 << 16);
    // 0x8008B724: or          $v0, $a0, $v0
    ctx->r2 = ctx->r4 | ctx->r2;
    // 0x8008B728: sw          $v0, 0x24($a2)
    MEM_W(0X24, ctx->r6) = ctx->r2;
    // 0x8008B72C: sb          $zero, 0x13C($a2)
    MEM_B(0X13C, ctx->r6) = 0;
L_8008B730:
    // 0x8008B730: lbu         $a0, 0x13C($a2)
    ctx->r4 = MEM_BU(ctx->r6, 0X13C);
    // 0x8008B734: sltiu       $v0, $a0, 0x4
    ctx->r2 = ctx->r4 < 0X4 ? 1 : 0;
    // 0x8008B738: beq         $v0, $zero, L_8008B7E4
    if (ctx->r2 == 0) {
        // 0x8008B73C: addiu       $a3, $a2, 0x12C
        ctx->r7 = ADD32(ctx->r6, 0X12C);
            goto L_8008B7E4;
    }
    // 0x8008B73C: addiu       $a3, $a2, 0x12C
    ctx->r7 = ADD32(ctx->r6, 0X12C);
    // 0x8008B740: addiu       $v0, $a0, 0x1
    ctx->r2 = ADD32(ctx->r4, 0X1);
    // 0x8008B744: sb          $v0, 0x13C($a2)
    MEM_B(0X13C, ctx->r6) = ctx->r2;
    // 0x8008B748: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x8008B74C: srl         $v1, $v0, 8
    ctx->r3 = S32(U32(ctx->r2) >> 8);
    // 0x8008B750: andi        $v0, $v1, 0xFF
    ctx->r2 = ctx->r3 & 0XFF;
    // 0x8008B754: addiu       $a2, $v0, -0x80
    ctx->r6 = ADD32(ctx->r2, -0X80);
    // 0x8008B758: sltiu       $v0, $a2, 0x6
    ctx->r2 = ctx->r6 < 0X6 ? 1 : 0;
    // 0x8008B75C: beql        $v0, $zero, L_8008B7AC
    if (ctx->r2 == 0) {
        // 0x8008B760: sll         $a0, $a0, 2
        ctx->r4 = S32(ctx->r4 << 2);
            goto L_8008B7AC;
    }
    goto skip_0;
    // 0x8008B760: sll         $a0, $a0, 2
    ctx->r4 = S32(ctx->r4 << 2);
    skip_0:
    // 0x8008B764: sll         $v0, $a2, 2
    ctx->r2 = S32(ctx->r6 << 2);
    // 0x8008B768: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8008B76C: addu        $at, $at, $v0
    gpr jr_addend_8008B774 = ctx->r2;
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x8008B770: lw          $v0, -0x2458($at)
    ctx->r2 = ADD32(ctx->r1, -0X2458);
    // 0x8008B774: jr          $v0
    // 0x8008B778: nop

    switch (jr_addend_8008B774 >> 2) {
        case 0: goto L_8008B77C; break;
        case 1: goto L_8008B784; break;
        case 2: goto L_8008B78C; break;
        case 3: goto L_8008B794; break;
        case 4: goto L_8008B79C; break;
        case 5: goto L_8008B7A4; break;
        default: switch_error(__func__, 0x8008B774, 0x8003DBA8);
    }
    // 0x8008B778: nop

L_8008B77C:
    // 0x8008B77C: j           L_8008B7A8
    // 0x8008B780: addiu       $v1, $zero, 0x80
    ctx->r3 = ADD32(0, 0X80);
        goto L_8008B7A8;
    // 0x8008B780: addiu       $v1, $zero, 0x80
    ctx->r3 = ADD32(0, 0X80);
L_8008B784:
    // 0x8008B784: j           L_8008B7A8
    // 0x8008B788: addiu       $v1, $zero, 0x82
    ctx->r3 = ADD32(0, 0X82);
        goto L_8008B7A8;
    // 0x8008B788: addiu       $v1, $zero, 0x82
    ctx->r3 = ADD32(0, 0X82);
L_8008B78C:
    // 0x8008B78C: j           L_8008B7A8
    // 0x8008B790: addiu       $v1, $zero, 0xA0
    ctx->r3 = ADD32(0, 0XA0);
        goto L_8008B7A8;
    // 0x8008B790: addiu       $v1, $zero, 0xA0
    ctx->r3 = ADD32(0, 0XA0);
L_8008B794:
    // 0x8008B794: j           L_8008B7A8
    // 0x8008B798: addiu       $v1, $zero, 0xA1
    ctx->r3 = ADD32(0, 0XA1);
        goto L_8008B7A8;
    // 0x8008B798: addiu       $v1, $zero, 0xA1
    ctx->r3 = ADD32(0, 0XA1);
L_8008B79C:
    // 0x8008B79C: j           L_8008B7A8
    // 0x8008B7A0: addiu       $v1, $zero, 0x83
    ctx->r3 = ADD32(0, 0X83);
        goto L_8008B7A8;
    // 0x8008B7A0: addiu       $v1, $zero, 0x83
    ctx->r3 = ADD32(0, 0X83);
L_8008B7A4:
    // 0x8008B7A4: addiu       $v1, $zero, 0x84
    ctx->r3 = ADD32(0, 0X84);
L_8008B7A8:
    // 0x8008B7A8: sll         $a0, $a0, 2
    ctx->r4 = S32(ctx->r4 << 2);
L_8008B7AC:
    // 0x8008B7AC: addu        $a0, $a3, $a0
    ctx->r4 = ADD32(ctx->r7, ctx->r4);
    // 0x8008B7B0: sb          $v1, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r3;
    // 0x8008B7B4: lw          $v0, 0x4($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X4);
    // 0x8008B7B8: sb          $v0, 0x1($a0)
    MEM_B(0X1, ctx->r4) = ctx->r2;
    // 0x8008B7BC: lh          $v1, 0x0($a1)
    ctx->r3 = MEM_H(ctx->r5, 0X0);
    // 0x8008B7C0: lui         $v0, 0x51EB
    ctx->r2 = S32(0X51EB << 16);
    // 0x8008B7C4: ori         $v0, $v0, 0x851F
    ctx->r2 = ctx->r2 | 0X851F;
    // 0x8008B7C8: sll         $v1, $v1, 8
    ctx->r3 = S32(ctx->r3 << 8);
    // 0x8008B7CC: mult        $v1, $v0
    result = S64(S32(ctx->r3)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8008B7D0: sra         $v1, $v1, 31
    ctx->r3 = S32(SIGNED(ctx->r3) >> 31);
    // 0x8008B7D4: mfhi        $t0
    ctx->r8 = hi;
    // 0x8008B7D8: sra         $v0, $t0, 5
    ctx->r2 = S32(SIGNED(ctx->r8) >> 5);
    // 0x8008B7DC: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x8008B7E0: sh          $v0, 0x2($a0)
    MEM_H(0X2, ctx->r4) = ctx->r2;
L_8008B7E4:
    // 0x8008B7E4: jr          $ra
    // 0x8008B7E8: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    return;
    // 0x8008B7E8: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
;}
RECOMP_FUNC void func_8008B7EC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008B7EC: addu        $a2, $a0, $zero
    ctx->r6 = ADD32(ctx->r4, 0);
    // 0x8008B7F0: lw          $a0, 0x24($a2)
    ctx->r4 = MEM_W(ctx->r6, 0X24);
    // 0x8008B7F4: lbu         $v1, 0x7($a1)
    ctx->r3 = MEM_BU(ctx->r5, 0X7);
    // 0x8008B7F8: srl         $v0, $a0, 25
    ctx->r2 = S32(U32(ctx->r4) >> 25);
    // 0x8008B7FC: xori        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 ^ 0X1;
    // 0x8008B800: andi        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 & 0X1;
    // 0x8008B804: sltiu       $v1, $v1, 0x1
    ctx->r3 = ctx->r3 < 0X1 ? 1 : 0;
    // 0x8008B808: or          $v0, $v0, $v1
    ctx->r2 = ctx->r2 | ctx->r3;
    // 0x8008B80C: beq         $v0, $zero, L_8008B820
    if (ctx->r2 == 0) {
        // 0x8008B810: lui         $v0, 0x200
        ctx->r2 = S32(0X200 << 16);
            goto L_8008B820;
    }
    // 0x8008B810: lui         $v0, 0x200
    ctx->r2 = S32(0X200 << 16);
    // 0x8008B814: or          $v0, $a0, $v0
    ctx->r2 = ctx->r4 | ctx->r2;
    // 0x8008B818: sw          $v0, 0x24($a2)
    MEM_W(0X24, ctx->r6) = ctx->r2;
    // 0x8008B81C: sb          $zero, 0x14E($a2)
    MEM_B(0X14E, ctx->r6) = 0;
L_8008B820:
    // 0x8008B820: lbu         $a0, 0x14E($a2)
    ctx->r4 = MEM_BU(ctx->r6, 0X14E);
    // 0x8008B824: sltiu       $v0, $a0, 0x4
    ctx->r2 = ctx->r4 < 0X4 ? 1 : 0;
    // 0x8008B828: beq         $v0, $zero, L_8008B8D4
    if (ctx->r2 == 0) {
        // 0x8008B82C: addiu       $a3, $a2, 0x13E
        ctx->r7 = ADD32(ctx->r6, 0X13E);
            goto L_8008B8D4;
    }
    // 0x8008B82C: addiu       $a3, $a2, 0x13E
    ctx->r7 = ADD32(ctx->r6, 0X13E);
    // 0x8008B830: addiu       $v0, $a0, 0x1
    ctx->r2 = ADD32(ctx->r4, 0X1);
    // 0x8008B834: sb          $v0, 0x14E($a2)
    MEM_B(0X14E, ctx->r6) = ctx->r2;
    // 0x8008B838: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x8008B83C: srl         $v1, $v0, 8
    ctx->r3 = S32(U32(ctx->r2) >> 8);
    // 0x8008B840: andi        $v0, $v1, 0xFF
    ctx->r2 = ctx->r3 & 0XFF;
    // 0x8008B844: addiu       $a2, $v0, -0x80
    ctx->r6 = ADD32(ctx->r2, -0X80);
    // 0x8008B848: sltiu       $v0, $a2, 0x6
    ctx->r2 = ctx->r6 < 0X6 ? 1 : 0;
    // 0x8008B84C: beql        $v0, $zero, L_8008B89C
    if (ctx->r2 == 0) {
        // 0x8008B850: sll         $a0, $a0, 2
        ctx->r4 = S32(ctx->r4 << 2);
            goto L_8008B89C;
    }
    goto skip_0;
    // 0x8008B850: sll         $a0, $a0, 2
    ctx->r4 = S32(ctx->r4 << 2);
    skip_0:
    // 0x8008B854: sll         $v0, $a2, 2
    ctx->r2 = S32(ctx->r6 << 2);
    // 0x8008B858: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8008B85C: addu        $at, $at, $v0
    gpr jr_addend_8008B864 = ctx->r2;
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x8008B860: lw          $v0, -0x2440($at)
    ctx->r2 = ADD32(ctx->r1, -0X2440);
    // 0x8008B864: jr          $v0
    // 0x8008B868: nop

    switch (jr_addend_8008B864 >> 2) {
        case 0: goto L_8008B86C; break;
        case 1: goto L_8008B874; break;
        case 2: goto L_8008B87C; break;
        case 3: goto L_8008B884; break;
        case 4: goto L_8008B88C; break;
        case 5: goto L_8008B894; break;
        default: switch_error(__func__, 0x8008B864, 0x8003DBC0);
    }
    // 0x8008B868: nop

L_8008B86C:
    // 0x8008B86C: j           L_8008B898
    // 0x8008B870: addiu       $v1, $zero, 0x80
    ctx->r3 = ADD32(0, 0X80);
        goto L_8008B898;
    // 0x8008B870: addiu       $v1, $zero, 0x80
    ctx->r3 = ADD32(0, 0X80);
L_8008B874:
    // 0x8008B874: j           L_8008B898
    // 0x8008B878: addiu       $v1, $zero, 0x82
    ctx->r3 = ADD32(0, 0X82);
        goto L_8008B898;
    // 0x8008B878: addiu       $v1, $zero, 0x82
    ctx->r3 = ADD32(0, 0X82);
L_8008B87C:
    // 0x8008B87C: j           L_8008B898
    // 0x8008B880: addiu       $v1, $zero, 0xA0
    ctx->r3 = ADD32(0, 0XA0);
        goto L_8008B898;
    // 0x8008B880: addiu       $v1, $zero, 0xA0
    ctx->r3 = ADD32(0, 0XA0);
L_8008B884:
    // 0x8008B884: j           L_8008B898
    // 0x8008B888: addiu       $v1, $zero, 0xA1
    ctx->r3 = ADD32(0, 0XA1);
        goto L_8008B898;
    // 0x8008B888: addiu       $v1, $zero, 0xA1
    ctx->r3 = ADD32(0, 0XA1);
L_8008B88C:
    // 0x8008B88C: j           L_8008B898
    // 0x8008B890: addiu       $v1, $zero, 0x83
    ctx->r3 = ADD32(0, 0X83);
        goto L_8008B898;
    // 0x8008B890: addiu       $v1, $zero, 0x83
    ctx->r3 = ADD32(0, 0X83);
L_8008B894:
    // 0x8008B894: addiu       $v1, $zero, 0x84
    ctx->r3 = ADD32(0, 0X84);
L_8008B898:
    // 0x8008B898: sll         $a0, $a0, 2
    ctx->r4 = S32(ctx->r4 << 2);
L_8008B89C:
    // 0x8008B89C: addu        $a0, $a3, $a0
    ctx->r4 = ADD32(ctx->r7, ctx->r4);
    // 0x8008B8A0: sb          $v1, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r3;
    // 0x8008B8A4: lw          $v0, 0x4($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X4);
    // 0x8008B8A8: sb          $v0, 0x1($a0)
    MEM_B(0X1, ctx->r4) = ctx->r2;
    // 0x8008B8AC: lh          $v1, 0x0($a1)
    ctx->r3 = MEM_H(ctx->r5, 0X0);
    // 0x8008B8B0: lui         $v0, 0x51EB
    ctx->r2 = S32(0X51EB << 16);
    // 0x8008B8B4: ori         $v0, $v0, 0x851F
    ctx->r2 = ctx->r2 | 0X851F;
    // 0x8008B8B8: sll         $v1, $v1, 8
    ctx->r3 = S32(ctx->r3 << 8);
    // 0x8008B8BC: mult        $v1, $v0
    result = S64(S32(ctx->r3)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8008B8C0: sra         $v1, $v1, 31
    ctx->r3 = S32(SIGNED(ctx->r3) >> 31);
    // 0x8008B8C4: mfhi        $t0
    ctx->r8 = hi;
    // 0x8008B8C8: sra         $v0, $t0, 5
    ctx->r2 = S32(SIGNED(ctx->r8) >> 5);
    // 0x8008B8CC: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x8008B8D0: sh          $v0, 0x2($a0)
    MEM_H(0X2, ctx->r4) = ctx->r2;
L_8008B8D4:
    // 0x8008B8D4: jr          $ra
    // 0x8008B8D8: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    return;
    // 0x8008B8D8: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
;}
RECOMP_FUNC void func_8008B8DC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008B8DC: addu        $a2, $a0, $zero
    ctx->r6 = ADD32(ctx->r4, 0);
    // 0x8008B8E0: lw          $a0, 0x24($a2)
    ctx->r4 = MEM_W(ctx->r6, 0X24);
    // 0x8008B8E4: lbu         $v1, 0x7($a1)
    ctx->r3 = MEM_BU(ctx->r5, 0X7);
    // 0x8008B8E8: srl         $v0, $a0, 24
    ctx->r2 = S32(U32(ctx->r4) >> 24);
    // 0x8008B8EC: xori        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 ^ 0X1;
    // 0x8008B8F0: andi        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 & 0X1;
    // 0x8008B8F4: sltiu       $v1, $v1, 0x1
    ctx->r3 = ctx->r3 < 0X1 ? 1 : 0;
    // 0x8008B8F8: or          $v0, $v0, $v1
    ctx->r2 = ctx->r2 | ctx->r3;
    // 0x8008B8FC: beq         $v0, $zero, L_8008B910
    if (ctx->r2 == 0) {
        // 0x8008B900: lui         $v0, 0x100
        ctx->r2 = S32(0X100 << 16);
            goto L_8008B910;
    }
    // 0x8008B900: lui         $v0, 0x100
    ctx->r2 = S32(0X100 << 16);
    // 0x8008B904: or          $v0, $a0, $v0
    ctx->r2 = ctx->r4 | ctx->r2;
    // 0x8008B908: sw          $v0, 0x24($a2)
    MEM_W(0X24, ctx->r6) = ctx->r2;
    // 0x8008B90C: sb          $zero, 0x160($a2)
    MEM_B(0X160, ctx->r6) = 0;
L_8008B910:
    // 0x8008B910: lbu         $a0, 0x160($a2)
    ctx->r4 = MEM_BU(ctx->r6, 0X160);
    // 0x8008B914: sltiu       $v0, $a0, 0x4
    ctx->r2 = ctx->r4 < 0X4 ? 1 : 0;
    // 0x8008B918: beq         $v0, $zero, L_8008B9C4
    if (ctx->r2 == 0) {
        // 0x8008B91C: addiu       $a3, $a2, 0x150
        ctx->r7 = ADD32(ctx->r6, 0X150);
            goto L_8008B9C4;
    }
    // 0x8008B91C: addiu       $a3, $a2, 0x150
    ctx->r7 = ADD32(ctx->r6, 0X150);
    // 0x8008B920: addiu       $v0, $a0, 0x1
    ctx->r2 = ADD32(ctx->r4, 0X1);
    // 0x8008B924: sb          $v0, 0x160($a2)
    MEM_B(0X160, ctx->r6) = ctx->r2;
    // 0x8008B928: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x8008B92C: srl         $v1, $v0, 8
    ctx->r3 = S32(U32(ctx->r2) >> 8);
    // 0x8008B930: andi        $v0, $v1, 0xFF
    ctx->r2 = ctx->r3 & 0XFF;
    // 0x8008B934: addiu       $a2, $v0, -0x80
    ctx->r6 = ADD32(ctx->r2, -0X80);
    // 0x8008B938: sltiu       $v0, $a2, 0x6
    ctx->r2 = ctx->r6 < 0X6 ? 1 : 0;
    // 0x8008B93C: beql        $v0, $zero, L_8008B98C
    if (ctx->r2 == 0) {
        // 0x8008B940: sll         $a0, $a0, 2
        ctx->r4 = S32(ctx->r4 << 2);
            goto L_8008B98C;
    }
    goto skip_0;
    // 0x8008B940: sll         $a0, $a0, 2
    ctx->r4 = S32(ctx->r4 << 2);
    skip_0:
    // 0x8008B944: sll         $v0, $a2, 2
    ctx->r2 = S32(ctx->r6 << 2);
    // 0x8008B948: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8008B94C: addu        $at, $at, $v0
    gpr jr_addend_8008B954 = ctx->r2;
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x8008B950: lw          $v0, -0x2428($at)
    ctx->r2 = ADD32(ctx->r1, -0X2428);
    // 0x8008B954: jr          $v0
    // 0x8008B958: nop

    switch (jr_addend_8008B954 >> 2) {
        case 0: goto L_8008B95C; break;
        case 1: goto L_8008B964; break;
        case 2: goto L_8008B96C; break;
        case 3: goto L_8008B974; break;
        case 4: goto L_8008B97C; break;
        case 5: goto L_8008B984; break;
        default: switch_error(__func__, 0x8008B954, 0x8003DBD8);
    }
    // 0x8008B958: nop

L_8008B95C:
    // 0x8008B95C: j           L_8008B988
    // 0x8008B960: addiu       $v1, $zero, 0x80
    ctx->r3 = ADD32(0, 0X80);
        goto L_8008B988;
    // 0x8008B960: addiu       $v1, $zero, 0x80
    ctx->r3 = ADD32(0, 0X80);
L_8008B964:
    // 0x8008B964: j           L_8008B988
    // 0x8008B968: addiu       $v1, $zero, 0x82
    ctx->r3 = ADD32(0, 0X82);
        goto L_8008B988;
    // 0x8008B968: addiu       $v1, $zero, 0x82
    ctx->r3 = ADD32(0, 0X82);
L_8008B96C:
    // 0x8008B96C: j           L_8008B988
    // 0x8008B970: addiu       $v1, $zero, 0xA0
    ctx->r3 = ADD32(0, 0XA0);
        goto L_8008B988;
    // 0x8008B970: addiu       $v1, $zero, 0xA0
    ctx->r3 = ADD32(0, 0XA0);
L_8008B974:
    // 0x8008B974: j           L_8008B988
    // 0x8008B978: addiu       $v1, $zero, 0xA1
    ctx->r3 = ADD32(0, 0XA1);
        goto L_8008B988;
    // 0x8008B978: addiu       $v1, $zero, 0xA1
    ctx->r3 = ADD32(0, 0XA1);
L_8008B97C:
    // 0x8008B97C: j           L_8008B988
    // 0x8008B980: addiu       $v1, $zero, 0x83
    ctx->r3 = ADD32(0, 0X83);
        goto L_8008B988;
    // 0x8008B980: addiu       $v1, $zero, 0x83
    ctx->r3 = ADD32(0, 0X83);
L_8008B984:
    // 0x8008B984: addiu       $v1, $zero, 0x84
    ctx->r3 = ADD32(0, 0X84);
L_8008B988:
    // 0x8008B988: sll         $a0, $a0, 2
    ctx->r4 = S32(ctx->r4 << 2);
L_8008B98C:
    // 0x8008B98C: addu        $a0, $a3, $a0
    ctx->r4 = ADD32(ctx->r7, ctx->r4);
    // 0x8008B990: sb          $v1, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r3;
    // 0x8008B994: lw          $v0, 0x4($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X4);
    // 0x8008B998: sb          $v0, 0x1($a0)
    MEM_B(0X1, ctx->r4) = ctx->r2;
    // 0x8008B99C: lh          $v1, 0x0($a1)
    ctx->r3 = MEM_H(ctx->r5, 0X0);
    // 0x8008B9A0: lui         $v0, 0x51EB
    ctx->r2 = S32(0X51EB << 16);
    // 0x8008B9A4: ori         $v0, $v0, 0x851F
    ctx->r2 = ctx->r2 | 0X851F;
    // 0x8008B9A8: sll         $v1, $v1, 8
    ctx->r3 = S32(ctx->r3 << 8);
    // 0x8008B9AC: mult        $v1, $v0
    result = S64(S32(ctx->r3)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8008B9B0: sra         $v1, $v1, 31
    ctx->r3 = S32(SIGNED(ctx->r3) >> 31);
    // 0x8008B9B4: mfhi        $t0
    ctx->r8 = hi;
    // 0x8008B9B8: sra         $v0, $t0, 5
    ctx->r2 = S32(SIGNED(ctx->r8) >> 5);
    // 0x8008B9BC: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x8008B9C0: sh          $v0, 0x2($a0)
    MEM_H(0X2, ctx->r4) = ctx->r2;
L_8008B9C4:
    // 0x8008B9C4: jr          $ra
    // 0x8008B9C8: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    return;
    // 0x8008B9C8: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
;}
RECOMP_FUNC void func_8008B9CC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008B9CC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8008B9D0: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x8008B9D4: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x8008B9D8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8008B9DC: lbu         $v1, 0xA0($s0)
    ctx->r3 = MEM_BU(ctx->r16, 0XA0);
    // 0x8008B9E0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8008B9E4: beql        $v1, $v0, L_8008B9F4
    if (ctx->r3 == ctx->r2) {
        // 0x8008B9E8: sw          $zero, 0x94($s0)
        MEM_W(0X94, ctx->r16) = 0;
            goto L_8008B9F4;
    }
    goto skip_0;
    // 0x8008B9E8: sw          $zero, 0x94($s0)
    MEM_W(0X94, ctx->r16) = 0;
    skip_0:
    // 0x8008B9EC: lw          $v0, 0x98($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X98);
    // 0x8008B9F0: sw          $v0, 0x94($s0)
    MEM_W(0X94, ctx->r16) = ctx->r2;
L_8008B9F4:
    // 0x8008B9F4: lbu         $a0, 0xBD($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0XBD);
    // 0x8008B9F8: lw          $a1, 0x60($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X60);
    // 0x8008B9FC: jal         0x80093E80
    // 0x8008BA00: nop

    func_80093E80(rdram, ctx);
        goto after_0;
    // 0x8008BA00: nop

    after_0:
    // 0x8008BA04: lbu         $a1, 0x4E($s0)
    ctx->r5 = MEM_BU(ctx->r16, 0X4E);
    // 0x8008BA08: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x8008BA0C: addiu       $v1, $zero, 0xFF
    ctx->r3 = ADD32(0, 0XFF);
    // 0x8008BA10: beq         $a1, $v1, L_8008BA4C
    if (ctx->r5 == ctx->r3) {
        // 0x8008BA14: sw          $v0, 0x9C($s0)
        MEM_W(0X9C, ctx->r16) = ctx->r2;
            goto L_8008BA4C;
    }
    // 0x8008BA14: sw          $v0, 0x9C($s0)
    MEM_W(0X9C, ctx->r16) = ctx->r2;
    // 0x8008BA18: lbu         $v0, 0x4F($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X4F);
    // 0x8008BA1C: beq         $v0, $v1, L_8008BA40
    if (ctx->r2 == ctx->r3) {
        // 0x8008BA20: addiu       $a0, $zero, 0x1
        ctx->r4 = ADD32(0, 0X1);
            goto L_8008BA40;
    }
    // 0x8008BA20: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8008BA24: lui         $v1, 0x8015
    ctx->r3 = S32(0X8015 << 16);
    // 0x8008BA28: addiu       $v1, $v1, -0x7C30
    ctx->r3 = ADD32(ctx->r3, -0X7C30);
    // 0x8008BA2C: sll         $v0, $v0, 4
    ctx->r2 = S32(ctx->r2 << 4);
    // 0x8008BA30: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8008BA34: addu        $v0, $v0, $a1
    ctx->r2 = ADD32(ctx->r2, ctx->r5);
    // 0x8008BA38: j           L_8008BA4C
    // 0x8008BA3C: sb          $a0, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r4;
        goto L_8008BA4C;
    // 0x8008BA3C: sb          $a0, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r4;
L_8008BA40:
    // 0x8008BA40: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x8008BA44: addu        $at, $at, $a1
    ctx->r1 = ADD32(ctx->r1, ctx->r5);
    // 0x8008BA48: sb          $a0, 0x2018($at)
    MEM_B(0X2018, ctx->r1) = ctx->r4;
L_8008BA4C:
    // 0x8008BA4C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8008BA50: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x8008BA54: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8008BA58: jr          $ra
    // 0x8008BA5C: nop

    return;
    // 0x8008BA5C: nop

;}
RECOMP_FUNC void func_8008BA60(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008BA60: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8008BA64: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8008BA68: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8008BA6C: lhu         $v0, 0x0($a1)
    ctx->r2 = MEM_HU(ctx->r5, 0X0);
    // 0x8008BA70: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x8008BA74: sb          $v0, 0xA0($s0)
    MEM_B(0XA0, ctx->r16) = ctx->r2;
    // 0x8008BA78: lw          $v0, 0x4($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X4);
    // 0x8008BA7C: lhu         $v1, 0x4($a1)
    ctx->r3 = MEM_HU(ctx->r5, 0X4);
    // 0x8008BA80: srl         $v0, $v0, 8
    ctx->r2 = S32(U32(ctx->r2) >> 8);
    // 0x8008BA84: andi        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 & 0X1;
    // 0x8008BA88: beq         $v0, $zero, L_8008BA9C
    if (ctx->r2 == 0) {
        // 0x8008BA8C: sw          $v1, 0x10($sp)
        MEM_W(0X10, ctx->r29) = ctx->r3;
            goto L_8008BA9C;
    }
    // 0x8008BA8C: sw          $v1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r3;
    // 0x8008BA90: sll         $v0, $v1, 8
    ctx->r2 = S32(ctx->r3 << 8);
    // 0x8008BA94: j           L_8008BAFC
    // 0x8008BA98: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
        goto L_8008BAFC;
    // 0x8008BA98: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
L_8008BA9C:
    // 0x8008BA9C: lbu         $v1, 0x4F($s0)
    ctx->r3 = MEM_BU(ctx->r16, 0X4F);
    // 0x8008BAA0: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8008BAA4: addiu       $a0, $a0, -0x5330
    ctx->r4 = ADD32(ctx->r4, -0X5330);
    // 0x8008BAA8: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // 0x8008BAAC: beq         $v1, $v0, L_8008BAC0
    if (ctx->r3 == ctx->r2) {
        // 0x8008BAB0: addiu       $a2, $sp, 0x10
        ctx->r6 = ADD32(ctx->r29, 0X10);
            goto L_8008BAC0;
    }
    // 0x8008BAB0: addiu       $a2, $sp, 0x10
    ctx->r6 = ADD32(ctx->r29, 0X10);
    // 0x8008BAB4: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x8008BAB8: j           L_8008BAC4
    // 0x8008BABC: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
        goto L_8008BAC4;
    // 0x8008BABC: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
L_8008BAC0:
    // 0x8008BAC0: addiu       $v0, $a0, 0x20
    ctx->r2 = ADD32(ctx->r4, 0X20);
L_8008BAC4:
    // 0x8008BAC4: lw          $v1, 0x0($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X0);
    // 0x8008BAC8: lw          $a0, 0x0($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X0);
    // 0x8008BACC: sll         $v0, $v1, 5
    ctx->r2 = S32(ctx->r3 << 5);
    // 0x8008BAD0: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x8008BAD4: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8008BAD8: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8008BADC: sll         $v0, $v0, 8
    ctx->r2 = S32(ctx->r2 << 8);
    // 0x8008BAE0: divu        $zero, $v0, $a0
    if (U32(ctx->r4) != 0) { lo = S32(U32(ctx->r2) / U32(ctx->r4)); hi = S32(U32(ctx->r2) % U32(ctx->r4)); } else { lo = 0; hi = S32(ctx->r2); }
    // 0x8008BAE4: bne         $a0, $zero, L_8008BAF0
    if (ctx->r4 != 0) {
        // 0x8008BAE8: nop
    
            goto L_8008BAF0;
    }
    // 0x8008BAE8: nop

    // 0x8008BAEC: break       7
    do_break(2148055788);
L_8008BAF0:
    // 0x8008BAF0: mflo        $v0
    ctx->r2 = lo;
    // 0x8008BAF4: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x8008BAF8: sw          $v0, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r2;
L_8008BAFC:
    // 0x8008BAFC: lw          $v1, 0x10($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X10);
    // 0x8008BB00: sw          $v1, 0x98($s0)
    MEM_W(0X98, ctx->r16) = ctx->r3;
    // 0x8008BB04: lbu         $a1, 0x2($a1)
    ctx->r5 = MEM_BU(ctx->r5, 0X2);
    // 0x8008BB08: beq         $a1, $zero, L_8008BB20
    if (ctx->r5 == 0) {
        // 0x8008BB0C: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_8008BB20;
    }
    // 0x8008BB0C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8008BB10: beq         $a1, $v0, L_8008BB78
    if (ctx->r5 == ctx->r2) {
        // 0x8008BB14: addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
            goto L_8008BB78;
    }
    // 0x8008BB14: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // 0x8008BB18: j           L_8008BBFC
    // 0x8008BB1C: nop

        goto L_8008BBFC;
    // 0x8008BB1C: nop

L_8008BB20:
    // 0x8008BB20: lw          $v0, 0x24($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X24);
    // 0x8008BB24: addiu       $v1, $zero, -0x801
    ctx->r3 = ADD32(0, -0X801);
    // 0x8008BB28: lbu         $a0, 0x4E($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X4E);
    // 0x8008BB2C: and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // 0x8008BB30: ori         $v0, $v0, 0x1000
    ctx->r2 = ctx->r2 | 0X1000;
    // 0x8008BB34: addiu       $v1, $zero, 0xFF
    ctx->r3 = ADD32(0, 0XFF);
    // 0x8008BB38: beq         $a0, $v1, L_8008BBF8
    if (ctx->r4 == ctx->r3) {
        // 0x8008BB3C: sw          $v0, 0x24($s0)
        MEM_W(0X24, ctx->r16) = ctx->r2;
            goto L_8008BBF8;
    }
    // 0x8008BB3C: sw          $v0, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->r2;
    // 0x8008BB40: lbu         $v0, 0x4F($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X4F);
    // 0x8008BB44: beq         $v0, $v1, L_8008BB64
    if (ctx->r2 == ctx->r3) {
        // 0x8008BB48: sll         $v0, $v0, 4
        ctx->r2 = S32(ctx->r2 << 4);
            goto L_8008BB64;
    }
    // 0x8008BB48: sll         $v0, $v0, 4
    ctx->r2 = S32(ctx->r2 << 4);
    // 0x8008BB4C: lui         $v1, 0x8015
    ctx->r3 = S32(0X8015 << 16);
    // 0x8008BB50: addiu       $v1, $v1, -0x7C30
    ctx->r3 = ADD32(ctx->r3, -0X7C30);
    // 0x8008BB54: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8008BB58: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x8008BB5C: j           L_8008BBF8
    // 0x8008BB60: sb          $zero, 0x0($v0)
    MEM_B(0X0, ctx->r2) = 0;
        goto L_8008BBF8;
    // 0x8008BB60: sb          $zero, 0x0($v0)
    MEM_B(0X0, ctx->r2) = 0;
L_8008BB64:
    // 0x8008BB64: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x8008BB68: addu        $at, $at, $a0
    ctx->r1 = ADD32(ctx->r1, ctx->r4);
    // 0x8008BB6C: sb          $zero, 0x2018($at)
    MEM_B(0X2018, ctx->r1) = 0;
    // 0x8008BB70: j           L_8008BBFC
    // 0x8008BB74: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
        goto L_8008BBFC;
    // 0x8008BB74: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_8008BB78:
    // 0x8008BB78: lw          $v0, 0x24($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X24);
    // 0x8008BB7C: andi        $v0, $v0, 0x800
    ctx->r2 = ctx->r2 & 0X800;
    // 0x8008BB80: bne         $v0, $zero, L_8008BBF4
    if (ctx->r2 != 0) {
        // 0x8008BB84: addiu       $v0, $zero, 0x1800
        ctx->r2 = ADD32(0, 0X1800);
            goto L_8008BBF4;
    }
    // 0x8008BB84: addiu       $v0, $zero, 0x1800
    ctx->r2 = ADD32(0, 0X1800);
    // 0x8008BB88: lbu         $v0, 0xA0($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0XA0);
    // 0x8008BB8C: beql        $v0, $a1, L_8008BB98
    if (ctx->r2 == ctx->r5) {
        // 0x8008BB90: sw          $zero, 0x94($s0)
        MEM_W(0X94, ctx->r16) = 0;
            goto L_8008BB98;
    }
    goto skip_0;
    // 0x8008BB90: sw          $zero, 0x94($s0)
    MEM_W(0X94, ctx->r16) = 0;
    skip_0:
    // 0x8008BB94: sw          $v1, 0x94($s0)
    MEM_W(0X94, ctx->r16) = ctx->r3;
L_8008BB98:
    // 0x8008BB98: lbu         $a0, 0xBD($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0XBD);
    // 0x8008BB9C: lw          $a1, 0x60($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X60);
    // 0x8008BBA0: jal         0x80093E80
    // 0x8008BBA4: nop

    func_80093E80(rdram, ctx);
        goto after_0;
    // 0x8008BBA4: nop

    after_0:
    // 0x8008BBA8: lbu         $a0, 0x4E($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X4E);
    // 0x8008BBAC: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x8008BBB0: addiu       $v1, $zero, 0xFF
    ctx->r3 = ADD32(0, 0XFF);
    // 0x8008BBB4: beq         $a0, $v1, L_8008BBF0
    if (ctx->r4 == ctx->r3) {
        // 0x8008BBB8: sw          $v0, 0x9C($s0)
        MEM_W(0X9C, ctx->r16) = ctx->r2;
            goto L_8008BBF0;
    }
    // 0x8008BBB8: sw          $v0, 0x9C($s0)
    MEM_W(0X9C, ctx->r16) = ctx->r2;
    // 0x8008BBBC: lbu         $v0, 0x4F($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X4F);
    // 0x8008BBC0: beq         $v0, $v1, L_8008BBE4
    if (ctx->r2 == ctx->r3) {
        // 0x8008BBC4: addiu       $a1, $zero, 0x1
        ctx->r5 = ADD32(0, 0X1);
            goto L_8008BBE4;
    }
    // 0x8008BBC4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8008BBC8: lui         $v1, 0x8015
    ctx->r3 = S32(0X8015 << 16);
    // 0x8008BBCC: addiu       $v1, $v1, -0x7C30
    ctx->r3 = ADD32(ctx->r3, -0X7C30);
    // 0x8008BBD0: sll         $v0, $v0, 4
    ctx->r2 = S32(ctx->r2 << 4);
    // 0x8008BBD4: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8008BBD8: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x8008BBDC: j           L_8008BBF0
    // 0x8008BBE0: sb          $a1, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r5;
        goto L_8008BBF0;
    // 0x8008BBE0: sb          $a1, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r5;
L_8008BBE4:
    // 0x8008BBE4: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x8008BBE8: addu        $at, $at, $a0
    ctx->r1 = ADD32(ctx->r1, ctx->r4);
    // 0x8008BBEC: sb          $a1, 0x2018($at)
    MEM_B(0X2018, ctx->r1) = ctx->r5;
L_8008BBF0:
    // 0x8008BBF0: addiu       $v0, $zero, 0x1800
    ctx->r2 = ADD32(0, 0X1800);
L_8008BBF4:
    // 0x8008BBF4: sw          $v0, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->r2;
L_8008BBF8:
    // 0x8008BBF8: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_8008BBFC:
    // 0x8008BBFC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8008BC00: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8008BC04: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8008BC08: jr          $ra
    // 0x8008BC0C: nop

    return;
    // 0x8008BC0C: nop

;}
RECOMP_FUNC void func_8008BC10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008BC10: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x8008BC14: lw          $v0, -0x3BA8($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X3BA8);
    // 0x8008BC18: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x8008BC1C: sw          $s0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r16;
    // 0x8008BC20: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x8008BC24: sw          $ra, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r31;
    // 0x8008BC28: sw          $s1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r17;
    // 0x8008BC2C: lw          $v1, 0x24($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X24);
    // 0x8008BC30: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8008BC34: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x8008BC38: sw          $v0, -0x3BA8($at)
    MEM_W(-0X3BA8, ctx->r1) = ctx->r2;
    // 0x8008BC3C: andi        $v0, $v1, 0x3
    ctx->r2 = ctx->r3 & 0X3;
    // 0x8008BC40: beq         $v0, $zero, L_8008BED8
    if (ctx->r2 == 0) {
        // 0x8008BC44: andi        $v0, $v1, 0x1
        ctx->r2 = ctx->r3 & 0X1;
            goto L_8008BED8;
    }
    // 0x8008BC44: andi        $v0, $v1, 0x1
    ctx->r2 = ctx->r3 & 0X1;
    // 0x8008BC48: beq         $v0, $zero, L_8008BC60
    if (ctx->r2 == 0) {
        // 0x8008BC4C: addiu       $v0, $zero, -0x2
        ctx->r2 = ADD32(0, -0X2);
            goto L_8008BC60;
    }
    // 0x8008BC4C: addiu       $v0, $zero, -0x2
    ctx->r2 = ADD32(0, -0X2);
    // 0x8008BC50: lbu         $a0, 0x67($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X67);
    // 0x8008BC54: and         $v0, $v1, $v0
    ctx->r2 = ctx->r3 & ctx->r2;
    // 0x8008BC58: jal         0x8009244C
    // 0x8008BC5C: sw          $v0, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->r2;
    func_8009244C(rdram, ctx);
        goto after_0;
    // 0x8008BC5C: sw          $v0, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->r2;
    after_0:
L_8008BC60:
    // 0x8008BC60: lw          $v0, 0x40($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X40);
    // 0x8008BC64: lui         $v1, 0x8014
    ctx->r3 = S32(0X8014 << 16);
    // 0x8008BC68: lw          $v1, -0x5338($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X5338);
    // 0x8008BC6C: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x8008BC70: bgtz        $v0, L_8008C994
    if (SIGNED(ctx->r2) > 0) {
        // 0x8008BC74: sw          $v0, 0x40($s0)
        MEM_W(0X40, ctx->r16) = ctx->r2;
            goto L_8008C994;
    }
    // 0x8008BC74: sw          $v0, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->r2;
    // 0x8008BC78: lw          $v0, 0x24($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X24);
    // 0x8008BC7C: andi        $v0, $v0, 0x40
    ctx->r2 = ctx->r2 & 0X40;
    // 0x8008BC80: bne         $v0, $zero, L_8008BEC8
    if (ctx->r2 != 0) {
        // 0x8008BC84: sw          $zero, 0x40($s0)
        MEM_W(0X40, ctx->r16) = 0;
            goto L_8008BEC8;
    }
    // 0x8008BC84: sw          $zero, 0x40($s0)
    MEM_W(0X40, ctx->r16) = 0;
    // 0x8008BC88: addiu       $v0, $zero, 0x7
    ctx->r2 = ADD32(0, 0X7);
    // 0x8008BC8C: addiu       $a1, $zero, 0x100
    ctx->r5 = ADD32(0, 0X100);
    // 0x8008BC90: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8008BC94: sb          $v0, 0xC0($s0)
    MEM_B(0XC0, ctx->r16) = ctx->r2;
    // 0x8008BC98: addiu       $v0, $zero, 0xA
    ctx->r2 = ADD32(0, 0XA);
    // 0x8008BC9C: sb          $v0, 0xD2($s0)
    MEM_B(0XD2, ctx->r16) = ctx->r2;
    // 0x8008BCA0: addiu       $v0, $zero, 0x83
    ctx->r2 = ADD32(0, 0X83);
    // 0x8008BCA4: sb          $v0, 0xE4($s0)
    MEM_B(0XE4, ctx->r16) = ctx->r2;
    // 0x8008BCA8: addiu       $v0, $zero, 0x80
    ctx->r2 = ADD32(0, 0X80);
    // 0x8008BCAC: sb          $v0, 0xF6($s0)
    MEM_B(0XF6, ctx->r16) = ctx->r2;
    // 0x8008BCB0: addiu       $v0, $zero, 0x40
    ctx->r2 = ADD32(0, 0X40);
    // 0x8008BCB4: sb          $v0, 0x12C($s0)
    MEM_B(0X12C, ctx->r16) = ctx->r2;
    // 0x8008BCB8: addiu       $v0, $zero, 0x41
    ctx->r2 = ADD32(0, 0X41);
    // 0x8008BCBC: sb          $v0, 0x13E($s0)
    MEM_B(0X13E, ctx->r16) = ctx->r2;
    // 0x8008BCC0: addiu       $v0, $zero, 0x5B
    ctx->r2 = ADD32(0, 0X5B);
    // 0x8008BCC4: sb          $v0, 0x150($s0)
    MEM_B(0X150, ctx->r16) = ctx->r2;
    // 0x8008BCC8: addiu       $v0, $zero, 0x84
    ctx->r2 = ADD32(0, 0X84);
    // 0x8008BCCC: sb          $zero, 0xC1($s0)
    MEM_B(0XC1, ctx->r16) = 0;
    // 0x8008BCD0: sh          $a1, 0xC2($s0)
    MEM_H(0XC2, ctx->r16) = ctx->r5;
    // 0x8008BCD4: sb          $a0, 0xD0($s0)
    MEM_B(0XD0, ctx->r16) = ctx->r4;
    // 0x8008BCD8: sb          $zero, 0xD3($s0)
    MEM_B(0XD3, ctx->r16) = 0;
    // 0x8008BCDC: sh          $a1, 0xD4($s0)
    MEM_H(0XD4, ctx->r16) = ctx->r5;
    // 0x8008BCE0: sb          $a0, 0xE2($s0)
    MEM_B(0XE2, ctx->r16) = ctx->r4;
    // 0x8008BCE4: sb          $zero, 0xE5($s0)
    MEM_B(0XE5, ctx->r16) = 0;
    // 0x8008BCE8: sh          $a1, 0xE6($s0)
    MEM_H(0XE6, ctx->r16) = ctx->r5;
    // 0x8008BCEC: sb          $a0, 0xF4($s0)
    MEM_B(0XF4, ctx->r16) = ctx->r4;
    // 0x8008BCF0: sb          $zero, 0xF7($s0)
    MEM_B(0XF7, ctx->r16) = 0;
    // 0x8008BCF4: sh          $a1, 0xF8($s0)
    MEM_H(0XF8, ctx->r16) = ctx->r5;
    // 0x8008BCF8: sb          $a0, 0x106($s0)
    MEM_B(0X106, ctx->r16) = ctx->r4;
    // 0x8008BCFC: sb          $a0, 0x11A($s0)
    MEM_B(0X11A, ctx->r16) = ctx->r4;
    // 0x8008BD00: sb          $zero, 0x11B($s0)
    MEM_B(0X11B, ctx->r16) = 0;
    // 0x8008BD04: sh          $a1, 0x11C($s0)
    MEM_H(0X11C, ctx->r16) = ctx->r5;
    // 0x8008BD08: sb          $a0, 0x12A($s0)
    MEM_B(0X12A, ctx->r16) = ctx->r4;
    // 0x8008BD0C: sb          $zero, 0x12D($s0)
    MEM_B(0X12D, ctx->r16) = 0;
    // 0x8008BD10: sh          $a1, 0x12E($s0)
    MEM_H(0X12E, ctx->r16) = ctx->r5;
    // 0x8008BD14: sb          $a0, 0x13C($s0)
    MEM_B(0X13C, ctx->r16) = ctx->r4;
    // 0x8008BD18: sb          $zero, 0x13F($s0)
    MEM_B(0X13F, ctx->r16) = 0;
    // 0x8008BD1C: sh          $a1, 0x140($s0)
    MEM_H(0X140, ctx->r16) = ctx->r5;
    // 0x8008BD20: sb          $a0, 0x14E($s0)
    MEM_B(0X14E, ctx->r16) = ctx->r4;
    // 0x8008BD24: sb          $zero, 0x151($s0)
    MEM_B(0X151, ctx->r16) = 0;
    // 0x8008BD28: sh          $a1, 0x152($s0)
    MEM_H(0X152, ctx->r16) = ctx->r5;
    // 0x8008BD2C: sb          $a0, 0x160($s0)
    MEM_B(0X160, ctx->r16) = ctx->r4;
    // 0x8008BD30: sb          $v0, 0x108($s0)
    MEM_B(0X108, ctx->r16) = ctx->r2;
    // 0x8008BD34: sb          $zero, 0x109($s0)
    MEM_B(0X109, ctx->r16) = 0;
    // 0x8008BD38: lbu         $v0, 0x57($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X57);
    // 0x8008BD3C: lbu         $v1, 0x56($s0)
    ctx->r3 = MEM_BU(ctx->r16, 0X56);
    // 0x8008BD40: lbu         $a2, 0x58($s0)
    ctx->r6 = MEM_BU(ctx->r16, 0X58);
    // 0x8008BD44: lbu         $a3, 0x59($s0)
    ctx->r7 = MEM_BU(ctx->r16, 0X59);
    // 0x8008BD48: lbu         $t0, 0x5A($s0)
    ctx->r8 = MEM_BU(ctx->r16, 0X5A);
    // 0x8008BD4C: sb          $a0, 0x118($s0)
    MEM_B(0X118, ctx->r16) = ctx->r4;
    // 0x8008BD50: sb          $a3, 0x4F($s0)
    MEM_B(0X4F, ctx->r16) = ctx->r7;
    // 0x8008BD54: lbu         $a0, 0x4F($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X4F);
    // 0x8008BD58: sh          $a1, 0x10A($s0)
    MEM_H(0X10A, ctx->r16) = ctx->r5;
    // 0x8008BD5C: sb          $a2, 0x4E($s0)
    MEM_B(0X4E, ctx->r16) = ctx->r6;
    // 0x8008BD60: lbu         $a1, 0x4E($s0)
    ctx->r5 = MEM_BU(ctx->r16, 0X4E);
    // 0x8008BD64: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x8008BD68: sll         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3 << 16);
    // 0x8008BD6C: sw          $v0, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->r2;
    // 0x8008BD70: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // 0x8008BD74: sw          $v1, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->r3;
    // 0x8008BD78: sw          $v1, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->r3;
    // 0x8008BD7C: beq         $a0, $v0, L_8008BDA4
    if (ctx->r4 == ctx->r2) {
        // 0x8008BD80: sb          $t0, 0x2F($s0)
        MEM_B(0X2F, ctx->r16) = ctx->r8;
            goto L_8008BDA4;
    }
    // 0x8008BD80: sb          $t0, 0x2F($s0)
    MEM_B(0X2F, ctx->r16) = ctx->r8;
    // 0x8008BD84: lui         $v1, 0x8014
    ctx->r3 = S32(0X8014 << 16);
    // 0x8008BD88: addiu       $v1, $v1, 0x2040
    ctx->r3 = ADD32(ctx->r3, 0X2040);
    // 0x8008BD8C: sll         $v0, $a0, 4
    ctx->r2 = S32(ctx->r4 << 4);
    // 0x8008BD90: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8008BD94: addu        $v0, $a1, $v0
    ctx->r2 = ADD32(ctx->r5, ctx->r2);
    // 0x8008BD98: lbu         $v0, 0x0($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X0);
    // 0x8008BD9C: j           L_8008BDB8
    // 0x8008BDA0: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
        goto L_8008BDB8;
    // 0x8008BDA0: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
L_8008BDA4:
    // 0x8008BDA4: andi        $v0, $a1, 0xFF
    ctx->r2 = ctx->r5 & 0XFF;
    // 0x8008BDA8: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x8008BDAC: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x8008BDB0: lbu         $v0, -0x3BA0($at)
    ctx->r2 = MEM_BU(ctx->r1, -0X3BA0);
    // 0x8008BDB4: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
L_8008BDB8:
    // 0x8008BDB8: addiu       $v1, $zero, 0xFF
    ctx->r3 = ADD32(0, 0XFF);
    // 0x8008BDBC: beq         $v0, $v1, L_8008BE08
    if (ctx->r2 == ctx->r3) {
        // 0x8008BDC0: nop
    
            goto L_8008BE08;
    }
    // 0x8008BDC0: nop

    // 0x8008BDC4: lbu         $v0, 0x4F($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X4F);
    // 0x8008BDC8: lbu         $a0, 0x4E($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X4E);
    // 0x8008BDCC: beq         $v0, $v1, L_8008BDF0
    if (ctx->r2 == ctx->r3) {
        // 0x8008BDD0: sll         $v0, $v0, 4
        ctx->r2 = S32(ctx->r2 << 4);
            goto L_8008BDF0;
    }
    // 0x8008BDD0: sll         $v0, $v0, 4
    ctx->r2 = S32(ctx->r2 << 4);
    // 0x8008BDD4: lui         $v1, 0x8014
    ctx->r3 = S32(0X8014 << 16);
    // 0x8008BDD8: addiu       $v1, $v1, 0x2040
    ctx->r3 = ADD32(ctx->r3, 0X2040);
    // 0x8008BDDC: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8008BDE0: addu        $v0, $a0, $v0
    ctx->r2 = ADD32(ctx->r4, ctx->r2);
    // 0x8008BDE4: lbu         $v0, 0x0($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X0);
    // 0x8008BDE8: j           L_8008BE10
    // 0x8008BDEC: sb          $v0, 0xBD($s0)
    MEM_B(0XBD, ctx->r16) = ctx->r2;
        goto L_8008BE10;
    // 0x8008BDEC: sb          $v0, 0xBD($s0)
    MEM_B(0XBD, ctx->r16) = ctx->r2;
L_8008BDF0:
    // 0x8008BDF0: andi        $v0, $a0, 0xFF
    ctx->r2 = ctx->r4 & 0XFF;
    // 0x8008BDF4: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x8008BDF8: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x8008BDFC: lbu         $v0, -0x3BA0($at)
    ctx->r2 = MEM_BU(ctx->r1, -0X3BA0);
    // 0x8008BE00: j           L_8008BE10
    // 0x8008BE04: sb          $v0, 0xBD($s0)
    MEM_B(0XBD, ctx->r16) = ctx->r2;
        goto L_8008BE10;
    // 0x8008BE04: sb          $v0, 0xBD($s0)
    MEM_B(0XBD, ctx->r16) = ctx->r2;
L_8008BE08:
    // 0x8008BE08: lhu         $v0, 0x52($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X52);
    // 0x8008BE0C: sb          $v0, 0xBD($s0)
    MEM_B(0XBD, ctx->r16) = ctx->r2;
L_8008BE10:
    // 0x8008BE10: lbu         $a2, 0x53($s0)
    ctx->r6 = MEM_BU(ctx->r16, 0X53);
    // 0x8008BE14: lbu         $a0, 0x4F($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X4F);
    // 0x8008BE18: lbu         $a1, 0x4E($s0)
    ctx->r5 = MEM_BU(ctx->r16, 0X4E);
    // 0x8008BE1C: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // 0x8008BE20: beq         $a0, $v0, L_8008BE40
    if (ctx->r4 == ctx->r2) {
        // 0x8008BE24: sll         $v0, $a0, 4
        ctx->r2 = S32(ctx->r4 << 4);
            goto L_8008BE40;
    }
    // 0x8008BE24: sll         $v0, $a0, 4
    ctx->r2 = S32(ctx->r4 << 4);
    // 0x8008BE28: lui         $v1, 0x8014
    ctx->r3 = S32(0X8014 << 16);
    // 0x8008BE2C: addiu       $v1, $v1, 0x2040
    ctx->r3 = ADD32(ctx->r3, 0X2040);
    // 0x8008BE30: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8008BE34: addu        $v0, $a1, $v0
    ctx->r2 = ADD32(ctx->r5, ctx->r2);
    // 0x8008BE38: j           L_8008BE50
    // 0x8008BE3C: sb          $a2, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r6;
        goto L_8008BE50;
    // 0x8008BE3C: sb          $a2, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r6;
L_8008BE40:
    // 0x8008BE40: andi        $v0, $a1, 0xFF
    ctx->r2 = ctx->r5 & 0XFF;
    // 0x8008BE44: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x8008BE48: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x8008BE4C: sb          $a2, -0x3BA0($at)
    MEM_B(-0X3BA0, ctx->r1) = ctx->r6;
L_8008BE50:
    // 0x8008BE50: lbu         $a1, 0xBB($s0)
    ctx->r5 = MEM_BU(ctx->r16, 0XBB);
    // 0x8008BE54: lw          $v1, 0x24($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X24);
    // 0x8008BE58: lui         $a0, 0x4000
    ctx->r4 = S32(0X4000 << 16);
    // 0x8008BE5C: ori         $a0, $a0, 0xAC44
    ctx->r4 = ctx->r4 | 0XAC44;
    // 0x8008BE60: addiu       $v0, $zero, 0x1F4
    ctx->r2 = ADD32(0, 0X1F4);
    // 0x8008BE64: sw          $v0, 0x98($s0)
    MEM_W(0X98, ctx->r16) = ctx->r2;
    // 0x8008BE68: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x8008BE6C: sb          $v0, 0x6E($s0)
    MEM_B(0X6E, ctx->r16) = ctx->r2;
    // 0x8008BE70: sb          $v0, 0x6F($s0)
    MEM_B(0X6F, ctx->r16) = ctx->r2;
    // 0x8008BE74: addiu       $v0, $zero, 0x2000
    ctx->r2 = ADD32(0, 0X2000);
    // 0x8008BE78: sw          $zero, 0x94($s0)
    MEM_W(0X94, ctx->r16) = 0;
    // 0x8008BE7C: sb          $zero, 0xA0($s0)
    MEM_B(0XA0, ctx->r16) = 0;
    // 0x8008BE80: sh          $zero, 0x6C($s0)
    MEM_H(0X6C, ctx->r16) = 0;
    // 0x8008BE84: sb          $zero, 0x4C($s0)
    MEM_B(0X4C, ctx->r16) = 0;
    // 0x8008BE88: sb          $zero, 0x4D($s0)
    MEM_B(0X4D, ctx->r16) = 0;
    // 0x8008BE8C: sw          $zero, 0x44($s0)
    MEM_W(0X44, ctx->r16) = 0;
    // 0x8008BE90: sw          $zero, 0x48($s0)
    MEM_W(0X48, ctx->r16) = 0;
    // 0x8008BE94: sw          $zero, 0x168($s0)
    MEM_W(0X168, ctx->r16) = 0;
    // 0x8008BE98: sh          $zero, 0x16C($s0)
    MEM_H(0X16C, ctx->r16) = 0;
    // 0x8008BE9C: sw          $zero, 0x174($s0)
    MEM_W(0X174, ctx->r16) = 0;
    // 0x8008BEA0: sh          $zero, 0x178($s0)
    MEM_H(0X178, ctx->r16) = 0;
    // 0x8008BEA4: sw          $zero, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = 0;
    // 0x8008BEA8: sw          $zero, 0x20($s0)
    MEM_W(0X20, ctx->r16) = 0;
    // 0x8008BEAC: sw          $a0, 0x60($s0)
    MEM_W(0X60, ctx->r16) = ctx->r4;
    // 0x8008BEB0: sh          $v0, 0xB4($s0)
    MEM_H(0XB4, ctx->r16) = ctx->r2;
    // 0x8008BEB4: sh          $zero, 0xBE($s0)
    MEM_H(0XBE, ctx->r16) = 0;
    // 0x8008BEB8: andi        $v1, $v1, 0x8
    ctx->r3 = ctx->r3 & 0X8;
    // 0x8008BEBC: sb          $a1, 0xBA($s0)
    MEM_B(0XBA, ctx->r16) = ctx->r5;
    // 0x8008BEC0: j           L_8008BED8
    // 0x8008BEC4: sw          $v1, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->r3;
        goto L_8008BED8;
    // 0x8008BEC4: sw          $v1, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->r3;
L_8008BEC8:
    // 0x8008BEC8: sb          $zero, 0x2E($s0)
    MEM_B(0X2E, ctx->r16) = 0;
    // 0x8008BECC: sw          $zero, 0x0($s0)
    MEM_W(0X0, ctx->r16) = 0;
    // 0x8008BED0: j           L_8008C994
    // 0x8008BED4: sw          $zero, 0x24($s0)
    MEM_W(0X24, ctx->r16) = 0;
        goto L_8008C994;
    // 0x8008BED4: sw          $zero, 0x24($s0)
    MEM_W(0X24, ctx->r16) = 0;
L_8008BED8:
    // 0x8008BED8: lw          $a0, 0x20($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X20);
    // 0x8008BEDC: beq         $a0, $zero, L_8008BF14
    if (ctx->r4 == 0) {
        // 0x8008BEE0: lui         $v0, 0x400
        ctx->r2 = S32(0X400 << 16);
            goto L_8008BF14;
    }
    // 0x8008BEE0: lui         $v0, 0x400
    ctx->r2 = S32(0X400 << 16);
    // 0x8008BEE4: lw          $v1, 0x24($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X24);
    // 0x8008BEE8: and         $v0, $v1, $v0
    ctx->r2 = ctx->r3 & ctx->r2;
    // 0x8008BEEC: bne         $v0, $zero, L_8008BF14
    if (ctx->r2 != 0) {
        // 0x8008BEF0: andi        $v0, $v1, 0x8
        ctx->r2 = ctx->r3 & 0X8;
            goto L_8008BF14;
    }
    // 0x8008BEF0: andi        $v0, $v1, 0x8
    ctx->r2 = ctx->r3 & 0X8;
    // 0x8008BEF4: beq         $v0, $zero, L_8008BF14
    if (ctx->r2 == 0) {
        // 0x8008BEF8: nop
    
            goto L_8008BF14;
    }
    // 0x8008BEF8: nop

    // 0x8008BEFC: lw          $v0, 0x1C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1C);
    // 0x8008BF00: sw          $a0, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r4;
    // 0x8008BF04: sw          $zero, 0x40($s0)
    MEM_W(0X40, ctx->r16) = 0;
    // 0x8008BF08: sw          $zero, 0x20($s0)
    MEM_W(0X20, ctx->r16) = 0;
    // 0x8008BF0C: sw          $zero, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = 0;
    // 0x8008BF10: sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
L_8008BF14:
    // 0x8008BF14: lw          $v0, 0x40($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X40);
    // 0x8008BF18: bne         $v0, $zero, L_8008C8FC
    if (ctx->r2 != 0) {
        // 0x8008BF1C: addiu       $s1, $zero, -0x1
        ctx->r17 = ADD32(0, -0X1);
            goto L_8008C8FC;
    }
    // 0x8008BF1C: addiu       $s1, $zero, -0x1
    ctx->r17 = ADD32(0, -0X1);
L_8008BF20:
    // 0x8008BF20: lw          $v0, 0x4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X4);
    // 0x8008BF24: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x8008BF28: lui         $v1, 0x8014
    ctx->r3 = S32(0X8014 << 16);
    // 0x8008BF2C: addiu       $v1, $v1, -0x5340
    ctx->r3 = ADD32(ctx->r3, -0X5340);
    // 0x8008BF30: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x8008BF34: lw          $v0, 0x4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X4);
    // 0x8008BF38: lw          $v0, 0x4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X4);
    // 0x8008BF3C: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x8008BF40: sw          $v0, -0x533C($at)
    MEM_W(-0X533C, ctx->r1) = ctx->r2;
    // 0x8008BF44: lw          $v0, 0x4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X4);
    // 0x8008BF48: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x8008BF4C: sw          $v0, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r2;
    // 0x8008BF50: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x8008BF54: lw          $v0, -0x3BB8($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X3BB8);
    // 0x8008BF58: lw          $v1, 0x0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X0);
    // 0x8008BF5C: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8008BF60: andi        $v1, $v1, 0x7F
    ctx->r3 = ctx->r3 & 0X7F;
    // 0x8008BF64: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x8008BF68: sw          $v0, -0x3BB8($at)
    MEM_W(-0X3BB8, ctx->r1) = ctx->r2;
    // 0x8008BF6C: sltiu       $v0, $v1, 0x51
    ctx->r2 = ctx->r3 < 0X51 ? 1 : 0;
    // 0x8008BF70: beq         $v0, $zero, L_8008C8E4
    if (ctx->r2 == 0) {
        // 0x8008BF74: sll         $v0, $v1, 2
        ctx->r2 = S32(ctx->r3 << 2);
            goto L_8008C8E4;
    }
    // 0x8008BF74: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x8008BF78: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8008BF7C: addu        $at, $at, $v0
    gpr jr_addend_8008BF84 = ctx->r2;
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x8008BF80: lw          $v0, -0x2410($at)
    ctx->r2 = ADD32(ctx->r1, -0X2410);
    // 0x8008BF84: jr          $v0
    // 0x8008BF88: nop

    switch (jr_addend_8008BF84 >> 2) {
        case 0: goto L_8008C1AC; break;
        case 1: goto L_8008BF8C; break;
        case 2: goto L_8008BFB8; break;
        case 3: goto L_8008C008; break;
        case 4: goto L_8008C058; break;
        case 5: goto L_8008C068; break;
        case 6: goto L_8008C164; break;
        case 7: goto L_8008C1C8; break;
        case 8: goto L_8008C1E4; break;
        case 9: goto L_8008C1FC; break;
        case 10: goto L_8008C2C4; break;
        case 11: goto L_8008C330; break;
        case 12: goto L_8008C398; break;
        case 13: goto L_8008C3B0; break;
        case 14: goto L_8008C3C8; break;
        case 15: goto L_8008C434; break;
        case 16: goto L_8008C44C; break;
        case 17: goto L_8008C464; break;
        case 18: goto L_8008C478; break;
        case 19: goto L_8008C48C; break;
        case 20: goto L_8008C8E4; break;
        case 21: goto L_8008C8E4; break;
        case 22: goto L_8008C8E4; break;
        case 23: goto L_8008C50C; break;
        case 24: goto L_8008C524; break;
        case 25: goto L_8008C53C; break;
        case 26: goto L_8008C554; break;
        case 27: goto L_8008C56C; break;
        case 28: goto L_8008C584; break;
        case 29: goto L_8008C59C; break;
        case 30: goto L_8008C5DC; break;
        case 31: goto L_8008C630; break;
        case 32: goto L_8008C8E4; break;
        case 33: goto L_8008C8E4; break;
        case 34: goto L_8008C8E4; break;
        case 35: goto L_8008C8E4; break;
        case 36: goto L_8008C8E4; break;
        case 37: goto L_8008C8E4; break;
        case 38: goto L_8008C8E4; break;
        case 39: goto L_8008C8E4; break;
        case 40: goto L_8008C660; break;
        case 41: goto L_8008C698; break;
        case 42: goto L_8008C8E4; break;
        case 43: goto L_8008C8E4; break;
        case 44: goto L_8008C8E4; break;
        case 45: goto L_8008C8E4; break;
        case 46: goto L_8008C8E4; break;
        case 47: goto L_8008C8E4; break;
        case 48: goto L_8008C6A8; break;
        case 49: goto L_8008C6E0; break;
        case 50: goto L_8008C6F8; break;
        case 51: goto L_8008C71C; break;
        case 52: goto L_8008C740; break;
        case 53: goto L_8008C750; break;
        case 54: goto L_8008C768; break;
        case 55: goto L_8008C780; break;
        case 56: goto L_8008C7C0; break;
        case 57: goto L_8008C8E4; break;
        case 58: goto L_8008C8E4; break;
        case 59: goto L_8008C8E4; break;
        case 60: goto L_8008C8E4; break;
        case 61: goto L_8008C8E4; break;
        case 62: goto L_8008C8E4; break;
        case 63: goto L_8008C8E4; break;
        case 64: goto L_8008C7F4; break;
        case 65: goto L_8008C80C; break;
        case 66: goto L_8008C824; break;
        case 67: goto L_8008C83C; break;
        case 68: goto L_8008C854; break;
        case 69: goto L_8008C86C; break;
        case 70: goto L_8008C884; break;
        case 71: goto L_8008C8E4; break;
        case 72: goto L_8008C8E4; break;
        case 73: goto L_8008C8E4; break;
        case 74: goto L_8008C8E4; break;
        case 75: goto L_8008C8E4; break;
        case 76: goto L_8008C8E4; break;
        case 77: goto L_8008C8E4; break;
        case 78: goto L_8008C8E4; break;
        case 79: goto L_8008C8E4; break;
        case 80: goto L_8008C89C; break;
        default: switch_error(__func__, 0x8008BF84, 0x8003DBF0);
    }
    // 0x8008BF88: nop

L_8008BF8C:
    // 0x8008BF8C: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x8008BF90: lbu         $v0, -0x533E($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X533E);
    // 0x8008BF94: beq         $v0, $zero, L_8008C1B0
    if (ctx->r2 == 0) {
        // 0x8008BF98: addu        $a0, $s0, $zero
        ctx->r4 = ADD32(ctx->r16, 0);
            goto L_8008C1B0;
    }
    // 0x8008BF98: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x8008BF9C: lw          $v1, 0x8($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X8);
    // 0x8008BFA0: beq         $v1, $zero, L_8008C1AC
    if (ctx->r3 == 0) {
        // 0x8008BFA4: addu        $a0, $zero, $zero
        ctx->r4 = ADD32(0, 0);
            goto L_8008C1AC;
    }
    // 0x8008BFA4: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x8008BFA8: lw          $v0, 0xC($s0)
    ctx->r2 = MEM_W(ctx->r16, 0XC);
    // 0x8008BFAC: sw          $v1, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r3;
    // 0x8008BFB0: j           L_8008C8E8
    // 0x8008BFB4: sw          $v0, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r2;
        goto L_8008C8E8;
    // 0x8008BFB4: sw          $v0, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r2;
L_8008BFB8:
    // 0x8008BFB8: lhu         $v0, 0x54($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X54);
    // 0x8008BFBC: lui         $v1, 0x8014
    ctx->r3 = S32(0X8014 << 16);
    // 0x8008BFC0: lbu         $v1, -0x533E($v1)
    ctx->r3 = MEM_BU(ctx->r3, -0X533E);
    // 0x8008BFC4: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8008BFC8: lw          $a0, -0x5340($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X5340);
    // 0x8008BFCC: sltu        $v0, $v0, $v1
    ctx->r2 = ctx->r2 < ctx->r3 ? 1 : 0;
    // 0x8008BFD0: bnel        $v0, $zero, L_8008C8E8
    if (ctx->r2 != 0) {
        // 0x8008BFD4: addu        $a0, $zero, $zero
        ctx->r4 = ADD32(0, 0);
            goto L_8008C8E8;
    }
    goto skip_0;
    // 0x8008BFD4: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    skip_0:
    // 0x8008BFD8: jal         0x80085CE8
    // 0x8008BFDC: srl         $a0, $a0, 16
    ctx->r4 = S32(U32(ctx->r4) >> 16);
    func_80085CE8(rdram, ctx);
        goto after_1;
    // 0x8008BFDC: srl         $a0, $a0, 16
    ctx->r4 = S32(U32(ctx->r4) >> 16);
    after_1:
    // 0x8008BFE0: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // 0x8008BFE4: beq         $v1, $zero, L_8008C8E8
    if (ctx->r3 == 0) {
        // 0x8008BFE8: addu        $a0, $zero, $zero
        ctx->r4 = ADD32(0, 0);
            goto L_8008C8E8;
    }
    // 0x8008BFE8: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x8008BFEC: sw          $v1, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r3;
    // 0x8008BFF0: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x8008BFF4: lhu         $v0, -0x533A($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X533A);
    // 0x8008BFF8: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x8008BFFC: addu        $v0, $v1, $v0
    ctx->r2 = ADD32(ctx->r3, ctx->r2);
    // 0x8008C000: j           L_8008C8E8
    // 0x8008C004: sw          $v0, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r2;
        goto L_8008C8E8;
    // 0x8008C004: sw          $v0, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r2;
L_8008C008:
    // 0x8008C008: lhu         $v0, 0x30($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X30);
    // 0x8008C00C: lui         $v1, 0x8014
    ctx->r3 = S32(0X8014 << 16);
    // 0x8008C010: lbu         $v1, -0x533E($v1)
    ctx->r3 = MEM_BU(ctx->r3, -0X533E);
    // 0x8008C014: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8008C018: lw          $a0, -0x5340($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X5340);
    // 0x8008C01C: sltu        $v0, $v0, $v1
    ctx->r2 = ctx->r2 < ctx->r3 ? 1 : 0;
    // 0x8008C020: bnel        $v0, $zero, L_8008C8E8
    if (ctx->r2 != 0) {
        // 0x8008C024: addu        $a0, $zero, $zero
        ctx->r4 = ADD32(0, 0);
            goto L_8008C8E8;
    }
    goto skip_1;
    // 0x8008C024: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    skip_1:
    // 0x8008C028: jal         0x80085CE8
    // 0x8008C02C: srl         $a0, $a0, 16
    ctx->r4 = S32(U32(ctx->r4) >> 16);
    func_80085CE8(rdram, ctx);
        goto after_2;
    // 0x8008C02C: srl         $a0, $a0, 16
    ctx->r4 = S32(U32(ctx->r4) >> 16);
    after_2:
    // 0x8008C030: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // 0x8008C034: beq         $v1, $zero, L_8008C8E8
    if (ctx->r3 == 0) {
        // 0x8008C038: addu        $a0, $zero, $zero
        ctx->r4 = ADD32(0, 0);
            goto L_8008C8E8;
    }
    // 0x8008C038: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x8008C03C: sw          $v1, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r3;
    // 0x8008C040: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x8008C044: lhu         $v0, -0x533A($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X533A);
    // 0x8008C048: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x8008C04C: addu        $v0, $v1, $v0
    ctx->r2 = ADD32(ctx->r3, ctx->r2);
    // 0x8008C050: j           L_8008C8E8
    // 0x8008C054: sw          $v0, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r2;
        goto L_8008C8E8;
    // 0x8008C054: sw          $v0, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r2;
L_8008C058:
    // 0x8008C058: lui         $a1, 0x8014
    ctx->r5 = S32(0X8014 << 16);
    // 0x8008C05C: addiu       $a1, $a1, -0x5340
    ctx->r5 = ADD32(ctx->r5, -0X5340);
    // 0x8008C060: j           L_8008C620
    // 0x8008C064: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
        goto L_8008C620;
    // 0x8008C064: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
L_8008C068:
    // 0x8008C068: lhu         $v0, 0x6C($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X6C);
    // 0x8008C06C: bne         $v0, $zero, L_8008C0F4
    if (ctx->r2 != 0) {
        // 0x8008C070: nop
    
            goto L_8008C0F4;
    }
    // 0x8008C070: nop

    // 0x8008C074: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x8008C078: lhu         $v0, -0x5340($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X5340);
    // 0x8008C07C: andi        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 & 0X1;
    // 0x8008C080: beq         $v0, $zero, L_8008C0D0
    if (ctx->r2 == 0) {
        // 0x8008C084: lui         $v0, 0xA835
        ctx->r2 = S32(0XA835 << 16);
            goto L_8008C0D0;
    }
    // 0x8008C084: lui         $v0, 0xA835
    ctx->r2 = S32(0XA835 << 16);
    // 0x8008C088: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x8008C08C: lw          $a0, 0xF54($a0)
    ctx->r4 = MEM_W(ctx->r4, 0XF54);
    // 0x8008C090: ori         $v0, $v0, 0x1D63
    ctx->r2 = ctx->r2 | 0X1D63;
    // 0x8008C094: mult        $a0, $v0
    result = S64(S32(ctx->r4)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8008C098: mflo        $a0
    ctx->r4 = lo;
    // 0x8008C09C: lui         $v1, 0x8014
    ctx->r3 = S32(0X8014 << 16);
    // 0x8008C0A0: lhu         $v1, -0x533C($v1)
    ctx->r3 = MEM_HU(ctx->r3, -0X533C);
    // 0x8008C0A4: srl         $v0, $a0, 6
    ctx->r2 = S32(U32(ctx->r4) >> 6);
    // 0x8008C0A8: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x8008C0AC: divu        $zero, $v0, $v1
    if (U32(ctx->r3) != 0) { lo = S32(U32(ctx->r2) / U32(ctx->r3)); hi = S32(U32(ctx->r2) % U32(ctx->r3)); } else { lo = 0; hi = S32(ctx->r2); }
    // 0x8008C0B0: bne         $v1, $zero, L_8008C0BC
    if (ctx->r3 != 0) {
        // 0x8008C0B4: nop
    
            goto L_8008C0BC;
    }
    // 0x8008C0B4: nop

    // 0x8008C0B8: break       7
    do_break(2148057272);
L_8008C0BC:
    // 0x8008C0BC: mfhi        $v1
    ctx->r3 = hi;
    // 0x8008C0C0: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x8008C0C4: sw          $a0, 0xF54($at)
    MEM_W(0XF54, ctx->r1) = ctx->r4;
    // 0x8008C0C8: j           L_8008C0DC
    // 0x8008C0CC: sh          $v1, 0x6C($s0)
    MEM_H(0X6C, ctx->r16) = ctx->r3;
        goto L_8008C0DC;
    // 0x8008C0CC: sh          $v1, 0x6C($s0)
    MEM_H(0X6C, ctx->r16) = ctx->r3;
L_8008C0D0:
    // 0x8008C0D0: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x8008C0D4: lhu         $v0, -0x533C($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X533C);
    // 0x8008C0D8: sh          $v0, 0x6C($s0)
    MEM_H(0X6C, ctx->r16) = ctx->r2;
L_8008C0DC:
    // 0x8008C0DC: lhu         $a0, 0x6C($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X6C);
    // 0x8008C0E0: ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
    // 0x8008C0E4: andi        $v1, $a0, 0xFFFF
    ctx->r3 = ctx->r4 & 0XFFFF;
    // 0x8008C0E8: beq         $v1, $v0, L_8008C10C
    if (ctx->r3 == ctx->r2) {
        // 0x8008C0EC: addiu       $v0, $a0, 0x1
        ctx->r2 = ADD32(ctx->r4, 0X1);
            goto L_8008C10C;
    }
    // 0x8008C0EC: addiu       $v0, $a0, 0x1
    ctx->r2 = ADD32(ctx->r4, 0X1);
    // 0x8008C0F0: sh          $v0, 0x6C($s0)
    MEM_H(0X6C, ctx->r16) = ctx->r2;
L_8008C0F4:
    // 0x8008C0F4: lhu         $v0, 0x6C($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X6C);
    // 0x8008C0F8: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x8008C0FC: sh          $v0, 0x6C($s0)
    MEM_H(0X6C, ctx->r16) = ctx->r2;
    // 0x8008C100: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x8008C104: beql        $v0, $zero, L_8008C8E8
    if (ctx->r2 == 0) {
        // 0x8008C108: addu        $a0, $zero, $zero
        ctx->r4 = ADD32(0, 0);
            goto L_8008C8E8;
    }
    goto skip_2;
    // 0x8008C108: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    skip_2:
L_8008C10C:
    // 0x8008C10C: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x8008C110: lw          $v0, -0x5340($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X5340);
    // 0x8008C114: srl         $v0, $v0, 8
    ctx->r2 = S32(U32(ctx->r2) >> 8);
    // 0x8008C118: andi        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 & 0X1;
    // 0x8008C11C: beq         $v0, $zero, L_8008C148
    if (ctx->r2 == 0) {
        // 0x8008C120: lui         $v0, 0x400
        ctx->r2 = S32(0X400 << 16);
            goto L_8008C148;
    }
    // 0x8008C120: lui         $v0, 0x400
    ctx->r2 = S32(0X400 << 16);
    // 0x8008C124: lw          $v1, 0x24($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X24);
    // 0x8008C128: and         $v0, $v1, $v0
    ctx->r2 = ctx->r3 & ctx->r2;
    // 0x8008C12C: bne         $v0, $zero, L_8008C148
    if (ctx->r2 != 0) {
        // 0x8008C130: andi        $v0, $v1, 0x8
        ctx->r2 = ctx->r3 & 0X8;
            goto L_8008C148;
    }
    // 0x8008C130: andi        $v0, $v1, 0x8
    ctx->r2 = ctx->r3 & 0X8;
    // 0x8008C134: beq         $v0, $zero, L_8008C148
    if (ctx->r2 == 0) {
        // 0x8008C138: nop
    
            goto L_8008C148;
    }
    // 0x8008C138: nop

    // 0x8008C13C: sh          $zero, 0x6C($s0)
    MEM_H(0X6C, ctx->r16) = 0;
L_8008C140:
    // 0x8008C140: j           L_8008C8E8
    // 0x8008C144: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
        goto L_8008C8E8;
    // 0x8008C144: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
L_8008C148:
    // 0x8008C148: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x8008C14C: lhu         $v0, -0x533A($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X533A);
    // 0x8008C150: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x8008C154: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x8008C158: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x8008C15C: j           L_8008C140
    // 0x8008C160: sw          $v1, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r3;
        goto L_8008C140;
    // 0x8008C160: sw          $v1, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r3;
L_8008C164:
    // 0x8008C164: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8008C168: lhu         $a0, -0x5340($a0)
    ctx->r4 = MEM_HU(ctx->r4, -0X5340);
    // 0x8008C16C: jal         0x80085CE8
    // 0x8008C170: nop

    func_80085CE8(rdram, ctx);
        goto after_3;
    // 0x8008C170: nop

    after_3:
    // 0x8008C174: addu        $a1, $v0, $zero
    ctx->r5 = ADD32(ctx->r2, 0);
    // 0x8008C178: beq         $a1, $zero, L_8008C1AC
    if (ctx->r5 == 0) {
        // 0x8008C17C: addu        $a0, $zero, $zero
        ctx->r4 = ADD32(0, 0);
            goto L_8008C1AC;
    }
    // 0x8008C17C: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x8008C180: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8008C184: lw          $v1, 0x4($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X4);
    // 0x8008C188: sw          $a1, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r5;
    // 0x8008C18C: sw          $v0, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r2;
    // 0x8008C190: sw          $v1, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r3;
    // 0x8008C194: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x8008C198: lhu         $v0, -0x533A($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X533A);
    // 0x8008C19C: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x8008C1A0: addu        $v0, $a1, $v0
    ctx->r2 = ADD32(ctx->r5, ctx->r2);
    // 0x8008C1A4: j           L_8008C8E8
    // 0x8008C1A8: sw          $v0, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r2;
        goto L_8008C8E8;
    // 0x8008C1A8: sw          $v0, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r2;
L_8008C1AC:
    // 0x8008C1AC: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
L_8008C1B0:
    // 0x8008C1B0: sw          $zero, 0x0($s0)
    MEM_W(0X0, ctx->r16) = 0;
    // 0x8008C1B4: jal         0x800862F4
    // 0x8008C1B8: sb          $zero, 0x2E($s0)
    MEM_B(0X2E, ctx->r16) = 0;
    func_800862F4(rdram, ctx);
        goto after_4;
    // 0x8008C1B8: sb          $zero, 0x2E($s0)
    MEM_B(0X2E, ctx->r16) = 0;
    after_4:
    // 0x8008C1BC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8008C1C0: j           L_8008C8E8
    // 0x8008C1C4: sw          $s1, 0x64($s0)
    MEM_W(0X64, ctx->r16) = ctx->r17;
        goto L_8008C8E8;
    // 0x8008C1C4: sw          $s1, 0x64($s0)
    MEM_W(0X64, ctx->r16) = ctx->r17;
L_8008C1C8:
    // 0x8008C1C8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8008C1CC: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x8008C1D0: sb          $v0, -0x533B($at)
    MEM_B(-0X533B, ctx->r1) = ctx->r2;
    // 0x8008C1D4: lui         $a1, 0x8014
    ctx->r5 = S32(0X8014 << 16);
    // 0x8008C1D8: addiu       $a1, $a1, -0x5340
    ctx->r5 = ADD32(ctx->r5, -0X5340);
    // 0x8008C1DC: j           L_8008C620
    // 0x8008C1E0: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
        goto L_8008C620;
    // 0x8008C1E0: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
L_8008C1E4:
    // 0x8008C1E4: lui         $a1, 0x8014
    ctx->r5 = S32(0X8014 << 16);
    // 0x8008C1E8: addiu       $a1, $a1, -0x5340
    ctx->r5 = ADD32(ctx->r5, -0X5340);
    // 0x8008C1EC: jal         0x80089C44
    // 0x8008C1F0: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_80089C44(rdram, ctx);
        goto after_5;
    // 0x8008C1F0: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_5:
    // 0x8008C1F4: j           L_8008C8E8
    // 0x8008C1F8: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
        goto L_8008C8E8;
    // 0x8008C1F8: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
L_8008C1FC:
    // 0x8008C1FC: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x8008C200: lbu         $v0, -0x533E($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X533E);
    // 0x8008C204: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // 0x8008C208: lhu         $a0, 0x52($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X52);
    // 0x8008C20C: lui         $v1, 0x8014
    ctx->r3 = S32(0X8014 << 16);
    // 0x8008C210: lhu         $v1, -0x5340($v1)
    ctx->r3 = MEM_HU(ctx->r3, -0X5340);
    // 0x8008C214: sll         $v0, $v0, 8
    ctx->r2 = S32(ctx->r2 << 8);
    // 0x8008C218: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // 0x8008C21C: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x8008C220: lbu         $v0, 0x1AD0($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X1AD0);
    // 0x8008C224: sll         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3 << 16);
    // 0x8008C228: beq         $v0, $zero, L_8008C140
    if (ctx->r2 == 0) {
        // 0x8008C22C: or          $a0, $a0, $v1
        ctx->r4 = ctx->r4 | ctx->r3;
            goto L_8008C140;
    }
    // 0x8008C22C: or          $a0, $a0, $v1
    ctx->r4 = ctx->r4 | ctx->r3;
    // 0x8008C230: lui         $t1, 0x800A
    ctx->r9 = S32(0X800A << 16);
    // 0x8008C234: lbu         $t1, 0xF50($t1)
    ctx->r9 = MEM_BU(ctx->r9, 0XF50);
    // 0x8008C238: addu        $t0, $v0, $zero
    ctx->r8 = ADD32(ctx->r2, 0);
    // 0x8008C23C: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
L_8008C240:
    // 0x8008C240: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x8008C244: addu        $at, $at, $a3
    ctx->r1 = ADD32(ctx->r1, ctx->r7);
    // 0x8008C248: lw          $a1, -0x271C($at)
    ctx->r5 = MEM_W(ctx->r1, -0X271C);
    // 0x8008C24C: or          $v0, $a0, $a2
    ctx->r2 = ctx->r4 | ctx->r6;
    // 0x8008C250: bnel        $a1, $v0, L_8008C2B0
    if (ctx->r5 != ctx->r2) {
        // 0x8008C254: addiu       $a2, $a2, 0x1
        ctx->r6 = ADD32(ctx->r6, 0X1);
            goto L_8008C2B0;
    }
    goto skip_3;
    // 0x8008C254: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    skip_3:
    // 0x8008C258: beql        $t1, $zero, L_8008C2B0
    if (ctx->r9 == 0) {
        // 0x8008C25C: addiu       $a2, $a2, 0x1
        ctx->r6 = ADD32(ctx->r6, 0X1);
            goto L_8008C2B0;
    }
    goto skip_4;
    // 0x8008C25C: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    skip_4:
    // 0x8008C260: beq         $a1, $s1, L_8008C2AC
    if (ctx->r5 == ctx->r17) {
        // 0x8008C264: andi        $v0, $a1, 0xFF
        ctx->r2 = ctx->r5 & 0XFF;
            goto L_8008C2AC;
    }
    // 0x8008C264: andi        $v0, $a1, 0xFF
    ctx->r2 = ctx->r5 & 0XFF;
    // 0x8008C268: sll         $v1, $v0, 1
    ctx->r3 = S32(ctx->r2 << 1);
    // 0x8008C26C: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x8008C270: sll         $v1, $v1, 5
    ctx->r3 = S32(ctx->r3 << 5);
    // 0x8008C274: subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // 0x8008C278: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x8008C27C: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x8008C280: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x8008C284: lw          $v0, -0x271C($at)
    ctx->r2 = MEM_W(ctx->r1, -0X271C);
    // 0x8008C288: bnel        $v0, $a1, L_8008C2B0
    if (ctx->r2 != ctx->r5) {
        // 0x8008C28C: addiu       $a2, $a2, 0x1
        ctx->r6 = ADD32(ctx->r6, 0X1);
            goto L_8008C2B0;
    }
    goto skip_5;
    // 0x8008C28C: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    skip_5:
    // 0x8008C290: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x8008C294: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x8008C298: lw          $v0, -0x275C($at)
    ctx->r2 = MEM_W(ctx->r1, -0X275C);
    // 0x8008C29C: ori         $v0, $v0, 0x8
    ctx->r2 = ctx->r2 | 0X8;
    // 0x8008C2A0: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x8008C2A4: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x8008C2A8: sw          $v0, -0x275C($at)
    MEM_W(-0X275C, ctx->r1) = ctx->r2;
L_8008C2AC:
    // 0x8008C2AC: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
L_8008C2B0:
    // 0x8008C2B0: sltu        $v0, $a2, $t0
    ctx->r2 = ctx->r6 < ctx->r8 ? 1 : 0;
    // 0x8008C2B4: bne         $v0, $zero, L_8008C240
    if (ctx->r2 != 0) {
        // 0x8008C2B8: addiu       $a3, $a3, 0x17C
        ctx->r7 = ADD32(ctx->r7, 0X17C);
            goto L_8008C240;
    }
    // 0x8008C2B8: addiu       $a3, $a3, 0x17C
    ctx->r7 = ADD32(ctx->r7, 0X17C);
    // 0x8008C2BC: j           L_8008C8E8
    // 0x8008C2C0: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
        goto L_8008C8E8;
    // 0x8008C2C0: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
L_8008C2C4:
    // 0x8008C2C4: lbu         $v1, 0x4E($s0)
    ctx->r3 = MEM_BU(ctx->r16, 0X4E);
    // 0x8008C2C8: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // 0x8008C2CC: beq         $v1, $v0, L_8008C140
    if (ctx->r3 == ctx->r2) {
        // 0x8008C2D0: addu        $a0, $s0, $zero
        ctx->r4 = ADD32(ctx->r16, 0);
            goto L_8008C140;
    }
    // 0x8008C2D0: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x8008C2D4: jal         0x80084860
    // 0x8008C2D8: addiu       $a1, $s0, 0x11A
    ctx->r5 = ADD32(ctx->r16, 0X11A);
    func_80084860(rdram, ctx);
        goto after_6;
    // 0x8008C2D8: addiu       $a1, $s0, 0x11A
    ctx->r5 = ADD32(ctx->r16, 0X11A);
    after_6:
    // 0x8008C2DC: srl         $v0, $v0, 7
    ctx->r2 = S32(U32(ctx->r2) >> 7);
    // 0x8008C2E0: lui         $v1, 0x8014
    ctx->r3 = S32(0X8014 << 16);
    // 0x8008C2E4: lbu         $v1, -0x533E($v1)
    ctx->r3 = MEM_BU(ctx->r3, -0X533E);
    // 0x8008C2E8: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8008C2EC: lw          $a0, -0x5340($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X5340);
    // 0x8008C2F0: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x8008C2F4: sltu        $v0, $v0, $v1
    ctx->r2 = ctx->r2 < ctx->r3 ? 1 : 0;
    // 0x8008C2F8: bnel        $v0, $zero, L_8008C8E8
    if (ctx->r2 != 0) {
        // 0x8008C2FC: addu        $a0, $zero, $zero
        ctx->r4 = ADD32(0, 0);
            goto L_8008C8E8;
    }
    goto skip_6;
    // 0x8008C2FC: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    skip_6:
    // 0x8008C300: jal         0x80085CE8
    // 0x8008C304: srl         $a0, $a0, 16
    ctx->r4 = S32(U32(ctx->r4) >> 16);
    func_80085CE8(rdram, ctx);
        goto after_7;
    // 0x8008C304: srl         $a0, $a0, 16
    ctx->r4 = S32(U32(ctx->r4) >> 16);
    after_7:
    // 0x8008C308: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // 0x8008C30C: beq         $v1, $zero, L_8008C8E8
    if (ctx->r3 == 0) {
        // 0x8008C310: addu        $a0, $zero, $zero
        ctx->r4 = ADD32(0, 0);
            goto L_8008C8E8;
    }
    // 0x8008C310: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x8008C314: sw          $v1, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r3;
    // 0x8008C318: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x8008C31C: lhu         $v0, -0x533A($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X533A);
    // 0x8008C320: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x8008C324: addu        $v0, $v1, $v0
    ctx->r2 = ADD32(ctx->r3, ctx->r2);
    // 0x8008C328: j           L_8008C8E8
    // 0x8008C32C: sw          $v0, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r2;
        goto L_8008C8E8;
    // 0x8008C32C: sw          $v0, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r2;
L_8008C330:
    // 0x8008C330: lhu         $v0, 0x54($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X54);
    // 0x8008C334: lui         $v1, 0x8014
    ctx->r3 = S32(0X8014 << 16);
    // 0x8008C338: lbu         $v1, -0x533F($v1)
    ctx->r3 = MEM_BU(ctx->r3, -0X533F);
    // 0x8008C33C: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8008C340: lw          $a0, -0x5340($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X5340);
    // 0x8008C344: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x8008C348: sll         $v1, $v0, 16
    ctx->r3 = S32(ctx->r2 << 16);
    // 0x8008C34C: sll         $v0, $a0, 16
    ctx->r2 = S32(ctx->r4 << 16);
    // 0x8008C350: sra         $v0, $v0, 24
    ctx->r2 = S32(SIGNED(ctx->r2) >> 24);
    // 0x8008C354: mult        $v1, $v0
    result = S64(S32(ctx->r3)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8008C358: mflo        $v0
    ctx->r2 = lo;
    // 0x8008C35C: bltzl       $v0, L_8008C364
    if (SIGNED(ctx->r2) < 0) {
        // 0x8008C360: addiu       $v0, $v0, 0x7F
        ctx->r2 = ADD32(ctx->r2, 0X7F);
            goto L_8008C364;
    }
    goto skip_7;
    // 0x8008C360: addiu       $v0, $v0, 0x7F
    ctx->r2 = ADD32(ctx->r2, 0X7F);
    skip_7:
L_8008C364:
    // 0x8008C364: sra         $v1, $v0, 7
    ctx->r3 = S32(SIGNED(ctx->r2) >> 7);
    // 0x8008C368: srl         $v0, $a0, 24
    ctx->r2 = S32(U32(ctx->r4) >> 24);
    // 0x8008C36C: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x8008C370: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x8008C374: bgez        $v1, L_8008C384
    if (SIGNED(ctx->r3) >= 0) {
        // 0x8008C378: lui         $v0, 0x7F
        ctx->r2 = S32(0X7F << 16);
            goto L_8008C384;
    }
    // 0x8008C378: lui         $v0, 0x7F
    ctx->r2 = S32(0X7F << 16);
    // 0x8008C37C: j           L_8008C390
    // 0x8008C380: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
        goto L_8008C390;
    // 0x8008C380: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
L_8008C384:
    // 0x8008C384: slt         $v0, $v0, $v1
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8008C388: bnel        $v0, $zero, L_8008C390
    if (ctx->r2 != 0) {
        // 0x8008C38C: lui         $v1, 0x7F
        ctx->r3 = S32(0X7F << 16);
            goto L_8008C390;
    }
    goto skip_8;
    // 0x8008C38C: lui         $v1, 0x7F
    ctx->r3 = S32(0X7F << 16);
    skip_8:
L_8008C390:
    // 0x8008C390: j           L_8008C140
    // 0x8008C394: sw          $v1, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->r3;
        goto L_8008C140;
    // 0x8008C394: sw          $v1, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->r3;
L_8008C398:
    // 0x8008C398: lui         $a1, 0x8014
    ctx->r5 = S32(0X8014 << 16);
    // 0x8008C39C: addiu       $a1, $a1, -0x5340
    ctx->r5 = ADD32(ctx->r5, -0X5340);
    // 0x8008C3A0: jal         0x8008A8C4
    // 0x8008C3A4: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_8008A8C4(rdram, ctx);
        goto after_8;
    // 0x8008C3A4: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_8:
    // 0x8008C3A8: j           L_8008C8E8
    // 0x8008C3AC: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
        goto L_8008C8E8;
    // 0x8008C3AC: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
L_8008C3B0:
    // 0x8008C3B0: lui         $a1, 0x8014
    ctx->r5 = S32(0X8014 << 16);
    // 0x8008C3B4: addiu       $a1, $a1, -0x5340
    ctx->r5 = ADD32(ctx->r5, -0X5340);
    // 0x8008C3B8: jal         0x8008ACB4
    // 0x8008C3BC: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_8008ACB4(rdram, ctx);
        goto after_9;
    // 0x8008C3BC: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_9:
    // 0x8008C3C0: j           L_8008C8E8
    // 0x8008C3C4: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
        goto L_8008C8E8;
    // 0x8008C3C4: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
L_8008C3C8:
    // 0x8008C3C8: lw          $v0, 0x24($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X24);
    // 0x8008C3CC: ori         $v0, $v0, 0x8000
    ctx->r2 = ctx->r2 | 0X8000;
    // 0x8008C3D0: sw          $v0, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->r2;
    // 0x8008C3D4: lui         $a1, 0x8014
    ctx->r5 = S32(0X8014 << 16);
    // 0x8008C3D8: lhu         $a1, -0x5340($a1)
    ctx->r5 = MEM_HU(ctx->r5, -0X5340);
    // 0x8008C3DC: sll         $v0, $a1, 8
    ctx->r2 = S32(ctx->r5 << 8);
    // 0x8008C3E0: sw          $v0, 0xA4($s0)
    MEM_W(0XA4, ctx->r16) = ctx->r2;
    // 0x8008C3E4: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x8008C3E8: lbu         $v0, -0x533E($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X533E);
    // 0x8008C3EC: lui         $v1, 0x8014
    ctx->r3 = S32(0X8014 << 16);
    // 0x8008C3F0: lb          $v1, -0x5339($v1)
    ctx->r3 = MEM_B(ctx->r3, -0X5339);
    // 0x8008C3F4: lw          $a0, 0xA4($s0)
    ctx->r4 = MEM_W(ctx->r16, 0XA4);
    // 0x8008C3F8: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x8008C3FC: sll         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3 << 16);
    // 0x8008C400: sw          $v0, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->r2;
    // 0x8008C404: addu        $v0, $v1, $v0
    ctx->r2 = ADD32(ctx->r3, ctx->r2);
    // 0x8008C408: beq         $a0, $zero, L_8008C42C
    if (ctx->r4 == 0) {
        // 0x8008C40C: sw          $v0, 0xA8($s0)
        MEM_W(0XA8, ctx->r16) = ctx->r2;
            goto L_8008C42C;
    }
    // 0x8008C40C: sw          $v0, 0xA8($s0)
    MEM_W(0XA8, ctx->r16) = ctx->r2;
    // 0x8008C410: divu        $zero, $v1, $a1
    if (U32(ctx->r5) != 0) { lo = S32(U32(ctx->r3) / U32(ctx->r5)); hi = S32(U32(ctx->r3) % U32(ctx->r5)); } else { lo = 0; hi = S32(ctx->r3); }
    // 0x8008C414: bne         $a1, $zero, L_8008C420
    if (ctx->r5 != 0) {
        // 0x8008C418: nop
    
            goto L_8008C420;
    }
    // 0x8008C418: nop

    // 0x8008C41C: break       7
    do_break(2148058140);
L_8008C420:
    // 0x8008C420: mflo        $v0
    ctx->r2 = lo;
    // 0x8008C424: j           L_8008C140
    // 0x8008C428: sw          $v0, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = ctx->r2;
        goto L_8008C140;
    // 0x8008C428: sw          $v0, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = ctx->r2;
L_8008C42C:
    // 0x8008C42C: j           L_8008C140
    // 0x8008C430: sw          $v1, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = ctx->r3;
        goto L_8008C140;
    // 0x8008C430: sw          $v1, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = ctx->r3;
L_8008C434:
    // 0x8008C434: lui         $a1, 0x8014
    ctx->r5 = S32(0X8014 << 16);
    // 0x8008C438: addiu       $a1, $a1, -0x5340
    ctx->r5 = ADD32(ctx->r5, -0X5340);
    // 0x8008C43C: jal         0x8008AE50
    // 0x8008C440: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_8008AE50(rdram, ctx);
        goto after_10;
    // 0x8008C440: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_10:
    // 0x8008C444: j           L_8008C8E8
    // 0x8008C448: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
        goto L_8008C8E8;
    // 0x8008C448: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
L_8008C44C:
    // 0x8008C44C: lui         $a1, 0x8014
    ctx->r5 = S32(0X8014 << 16);
    // 0x8008C450: addiu       $a1, $a1, -0x5340
    ctx->r5 = ADD32(ctx->r5, -0X5340);
    // 0x8008C454: jal         0x8008A38C
    // 0x8008C458: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_8008A38C(rdram, ctx);
        goto after_11;
    // 0x8008C458: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_11:
    // 0x8008C45C: j           L_8008C8E8
    // 0x8008C460: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
        goto L_8008C8E8;
    // 0x8008C460: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
L_8008C464:
    // 0x8008C464: lbu         $a0, 0x67($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X67);
    // 0x8008C468: jal         0x80092274
    // 0x8008C46C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80092274(rdram, ctx);
        goto after_12;
    // 0x8008C46C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_12:
    // 0x8008C470: j           L_8008C8E8
    // 0x8008C474: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
        goto L_8008C8E8;
    // 0x8008C474: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
L_8008C478:
    // 0x8008C478: lw          $v0, 0x24($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X24);
    // 0x8008C47C: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x8008C480: ori         $v0, $v0, 0x80
    ctx->r2 = ctx->r2 | 0X80;
    // 0x8008C484: j           L_8008C8E8
    // 0x8008C488: sw          $v0, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->r2;
        goto L_8008C8E8;
    // 0x8008C488: sw          $v0, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->r2;
L_8008C48C:
    // 0x8008C48C: lbu         $v1, 0x4E($s0)
    ctx->r3 = MEM_BU(ctx->r16, 0X4E);
    // 0x8008C490: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // 0x8008C494: beq         $v1, $v0, L_8008C140
    if (ctx->r3 == ctx->r2) {
        // 0x8008C498: lui         $v1, 0xA835
        ctx->r3 = S32(0XA835 << 16);
            goto L_8008C140;
    }
    // 0x8008C498: lui         $v1, 0xA835
    ctx->r3 = S32(0XA835 << 16);
    // 0x8008C49C: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x8008C4A0: lw          $v0, 0xF54($v0)
    ctx->r2 = MEM_W(ctx->r2, 0XF54);
    // 0x8008C4A4: ori         $v1, $v1, 0x1D63
    ctx->r3 = ctx->r3 | 0X1D63;
    // 0x8008C4A8: mult        $v0, $v1
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8008C4AC: mflo        $v0
    ctx->r2 = lo;
    // 0x8008C4B0: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8008C4B4: lw          $a0, -0x5340($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X5340);
    // 0x8008C4B8: lui         $v1, 0x8014
    ctx->r3 = S32(0X8014 << 16);
    // 0x8008C4BC: lbu         $v1, -0x533E($v1)
    ctx->r3 = MEM_BU(ctx->r3, -0X533E);
    // 0x8008C4C0: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x8008C4C4: sw          $v0, 0xF54($at)
    MEM_W(0XF54, ctx->r1) = ctx->r2;
    // 0x8008C4C8: srl         $v0, $v0, 6
    ctx->r2 = S32(U32(ctx->r2) >> 6);
    // 0x8008C4CC: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x8008C4D0: sltu        $v0, $v0, $v1
    ctx->r2 = ctx->r2 < ctx->r3 ? 1 : 0;
    // 0x8008C4D4: bnel        $v0, $zero, L_8008C8E8
    if (ctx->r2 != 0) {
        // 0x8008C4D8: addu        $a0, $zero, $zero
        ctx->r4 = ADD32(0, 0);
            goto L_8008C8E8;
    }
    goto skip_9;
    // 0x8008C4D8: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    skip_9:
    // 0x8008C4DC: jal         0x80085CE8
    // 0x8008C4E0: srl         $a0, $a0, 16
    ctx->r4 = S32(U32(ctx->r4) >> 16);
    func_80085CE8(rdram, ctx);
        goto after_13;
    // 0x8008C4E0: srl         $a0, $a0, 16
    ctx->r4 = S32(U32(ctx->r4) >> 16);
    after_13:
    // 0x8008C4E4: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // 0x8008C4E8: beq         $v1, $zero, L_8008C8E8
    if (ctx->r3 == 0) {
        // 0x8008C4EC: addu        $a0, $zero, $zero
        ctx->r4 = ADD32(0, 0);
            goto L_8008C8E8;
    }
    // 0x8008C4EC: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x8008C4F0: sw          $v1, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r3;
    // 0x8008C4F4: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x8008C4F8: lhu         $v0, -0x533A($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X533A);
    // 0x8008C4FC: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x8008C500: addu        $v0, $v1, $v0
    ctx->r2 = ADD32(ctx->r3, ctx->r2);
    // 0x8008C504: j           L_8008C8E8
    // 0x8008C508: sw          $v0, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r2;
        goto L_8008C8E8;
    // 0x8008C508: sw          $v0, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r2;
L_8008C50C:
    // 0x8008C50C: lui         $a1, 0x8014
    ctx->r5 = S32(0X8014 << 16);
    // 0x8008C510: addiu       $a1, $a1, -0x5340
    ctx->r5 = ADD32(ctx->r5, -0X5340);
    // 0x8008C514: jal         0x8008B0A8
    // 0x8008C518: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_8008B0A8(rdram, ctx);
        goto after_14;
    // 0x8008C518: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_14:
    // 0x8008C51C: j           L_8008C8E8
    // 0x8008C520: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
        goto L_8008C8E8;
    // 0x8008C520: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
L_8008C524:
    // 0x8008C524: lui         $a1, 0x8014
    ctx->r5 = S32(0X8014 << 16);
    // 0x8008C528: addiu       $a1, $a1, -0x5340
    ctx->r5 = ADD32(ctx->r5, -0X5340);
    // 0x8008C52C: jal         0x8008A12C
    // 0x8008C530: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_8008A12C(rdram, ctx);
        goto after_15;
    // 0x8008C530: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_15:
    // 0x8008C534: j           L_8008C8E8
    // 0x8008C538: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
        goto L_8008C8E8;
    // 0x8008C538: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
L_8008C53C:
    // 0x8008C53C: lui         $a1, 0x8014
    ctx->r5 = S32(0X8014 << 16);
    // 0x8008C540: addiu       $a1, $a1, -0x5340
    ctx->r5 = ADD32(ctx->r5, -0X5340);
    // 0x8008C544: jal         0x8008A014
    // 0x8008C548: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_8008A014(rdram, ctx);
        goto after_16;
    // 0x8008C548: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_16:
    // 0x8008C54C: j           L_8008C8E8
    // 0x8008C550: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
        goto L_8008C8E8;
    // 0x8008C550: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
L_8008C554:
    // 0x8008C554: lui         $a1, 0x8014
    ctx->r5 = S32(0X8014 << 16);
    // 0x8008C558: addiu       $a1, $a1, -0x5340
    ctx->r5 = ADD32(ctx->r5, -0X5340);
    // 0x8008C55C: jal         0x8008A26C
    // 0x8008C560: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_8008A26C(rdram, ctx);
        goto after_17;
    // 0x8008C560: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_17:
    // 0x8008C564: j           L_8008C8E8
    // 0x8008C568: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
        goto L_8008C8E8;
    // 0x8008C568: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
L_8008C56C:
    // 0x8008C56C: lui         $a1, 0x8014
    ctx->r5 = S32(0X8014 << 16);
    // 0x8008C570: addiu       $a1, $a1, -0x5340
    ctx->r5 = ADD32(ctx->r5, -0X5340);
    // 0x8008C574: jal         0x8008BA60
    // 0x8008C578: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_8008BA60(rdram, ctx);
        goto after_18;
    // 0x8008C578: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_18:
    // 0x8008C57C: j           L_8008C8E8
    // 0x8008C580: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
        goto L_8008C8E8;
    // 0x8008C580: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
L_8008C584:
    // 0x8008C584: lui         $a1, 0x8014
    ctx->r5 = S32(0X8014 << 16);
    // 0x8008C588: addiu       $a1, $a1, -0x5340
    ctx->r5 = ADD32(ctx->r5, -0X5340);
    // 0x8008C58C: jal         0x8008A6FC
    // 0x8008C590: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_8008A6FC(rdram, ctx);
        goto after_19;
    // 0x8008C590: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_19:
    // 0x8008C594: j           L_8008C8E8
    // 0x8008C598: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
        goto L_8008C8E8;
    // 0x8008C598: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
L_8008C59C:
    // 0x8008C59C: sw          $zero, 0x44($s0)
    MEM_W(0X44, ctx->r16) = 0;
    // 0x8008C5A0: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x8008C5A4: lw          $v0, -0x5340($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X5340);
    // 0x8008C5A8: srl         $v0, $v0, 8
    ctx->r2 = S32(U32(ctx->r2) >> 8);
    // 0x8008C5AC: sb          $v0, 0x4C($s0)
    MEM_B(0X4C, ctx->r16) = ctx->r2;
    // 0x8008C5B0: sb          $v0, 0xAC($s0)
    MEM_B(0XAC, ctx->r16) = ctx->r2;
    // 0x8008C5B4: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8008C5B8: lhu         $a0, -0x5340($a0)
    ctx->r4 = MEM_HU(ctx->r4, -0X5340);
    // 0x8008C5BC: jal         0x80093F18
    // 0x8008C5C0: nop

    func_80093F18(rdram, ctx);
        goto after_20;
    // 0x8008C5C0: nop

    after_20:
    // 0x8008C5C4: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x8008C5C8: lui         $a1, 0x8014
    ctx->r5 = S32(0X8014 << 16);
    // 0x8008C5CC: addiu       $a1, $a1, -0x5340
    ctx->r5 = ADD32(ctx->r5, -0X5340);
    // 0x8008C5D0: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x8008C5D4: j           L_8008C618
    // 0x8008C5D8: sw          $v0, 0x84($s0)
    MEM_W(0X84, ctx->r16) = ctx->r2;
        goto L_8008C618;
    // 0x8008C5D8: sw          $v0, 0x84($s0)
    MEM_W(0X84, ctx->r16) = ctx->r2;
L_8008C5DC:
    // 0x8008C5DC: sw          $zero, 0x48($s0)
    MEM_W(0X48, ctx->r16) = 0;
    // 0x8008C5E0: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x8008C5E4: lw          $v0, -0x5340($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X5340);
    // 0x8008C5E8: srl         $v0, $v0, 8
    ctx->r2 = S32(U32(ctx->r2) >> 8);
    // 0x8008C5EC: sb          $v0, 0x4D($s0)
    MEM_B(0X4D, ctx->r16) = ctx->r2;
    // 0x8008C5F0: sb          $v0, 0xAD($s0)
    MEM_B(0XAD, ctx->r16) = ctx->r2;
    // 0x8008C5F4: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8008C5F8: lhu         $a0, -0x5340($a0)
    ctx->r4 = MEM_HU(ctx->r4, -0X5340);
    // 0x8008C5FC: jal         0x80093F18
    // 0x8008C600: nop

    func_80093F18(rdram, ctx);
        goto after_21;
    // 0x8008C600: nop

    after_21:
    // 0x8008C604: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x8008C608: lui         $a1, 0x8014
    ctx->r5 = S32(0X8014 << 16);
    // 0x8008C60C: addiu       $a1, $a1, -0x5340
    ctx->r5 = ADD32(ctx->r5, -0X5340);
    // 0x8008C610: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x8008C614: sw          $v0, 0x88($s0)
    MEM_W(0X88, ctx->r16) = ctx->r2;
L_8008C618:
    // 0x8008C618: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x8008C61C: sw          $zero, -0x5340($at)
    MEM_W(-0X5340, ctx->r1) = 0;
L_8008C620:
    // 0x8008C620: jal         0x800895BC
    // 0x8008C624: nop

    func_800895BC(rdram, ctx);
        goto after_22;
    // 0x8008C624: nop

    after_22:
    // 0x8008C628: j           L_8008C8E8
    // 0x8008C62C: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
        goto L_8008C8E8;
    // 0x8008C62C: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
L_8008C630:
    // 0x8008C630: lw          $v0, 0x24($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X24);
    // 0x8008C634: ori         $v0, $v0, 0x100
    ctx->r2 = ctx->r2 | 0X100;
    // 0x8008C638: sw          $v0, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->r2;
    // 0x8008C63C: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8008C640: lw          $a0, -0x5340($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X5340);
    // 0x8008C644: srl         $a0, $a0, 8
    ctx->r4 = S32(U32(ctx->r4) >> 8);
    // 0x8008C648: jal         0x80093F18
    // 0x8008C64C: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    func_80093F18(rdram, ctx);
        goto after_23;
    // 0x8008C64C: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    after_23:
    // 0x8008C650: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x8008C654: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x8008C658: j           L_8008C8E8
    // 0x8008C65C: sw          $v0, 0x70($s0)
    MEM_W(0X70, ctx->r16) = ctx->r2;
        goto L_8008C8E8;
    // 0x8008C65C: sw          $v0, 0x70($s0)
    MEM_W(0X70, ctx->r16) = ctx->r2;
L_8008C660:
    // 0x8008C660: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8008C664: lhu         $a0, -0x5340($a0)
    ctx->r4 = MEM_HU(ctx->r4, -0X5340);
    // 0x8008C668: jal         0x80085CE8
    // 0x8008C66C: nop

    func_80085CE8(rdram, ctx);
        goto after_24;
    // 0x8008C66C: nop

    after_24:
    // 0x8008C670: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // 0x8008C674: beq         $v1, $zero, L_8008C8E8
    if (ctx->r3 == 0) {
        // 0x8008C678: addu        $a0, $zero, $zero
        ctx->r4 = ADD32(0, 0);
            goto L_8008C8E8;
    }
    // 0x8008C678: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x8008C67C: sw          $v1, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->r3;
    // 0x8008C680: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x8008C684: lhu         $v0, -0x533A($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X533A);
    // 0x8008C688: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x8008C68C: addu        $v0, $v1, $v0
    ctx->r2 = ADD32(ctx->r3, ctx->r2);
    // 0x8008C690: j           L_8008C8E8
    // 0x8008C694: sw          $v0, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->r2;
        goto L_8008C8E8;
    // 0x8008C694: sw          $v0, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->r2;
L_8008C698:
    // 0x8008C698: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x8008C69C: sw          $zero, 0x20($s0)
    MEM_W(0X20, ctx->r16) = 0;
    // 0x8008C6A0: j           L_8008C8E8
    // 0x8008C6A4: sw          $zero, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = 0;
        goto L_8008C8E8;
    // 0x8008C6A4: sw          $zero, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = 0;
L_8008C6A8:
    // 0x8008C6A8: lhu         $v1, 0x28($s0)
    ctx->r3 = MEM_HU(ctx->r16, 0X28);
    // 0x8008C6AC: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x8008C6B0: lh          $v0, -0x5340($v0)
    ctx->r2 = MEM_H(ctx->r2, -0X5340);
    // 0x8008C6B4: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x8008C6B8: bgez        $v1, L_8008C6C8
    if (SIGNED(ctx->r3) >= 0) {
        // 0x8008C6BC: ori         $v0, $zero, 0xFFFF
        ctx->r2 = 0 | 0XFFFF;
            goto L_8008C6C8;
    }
    // 0x8008C6BC: ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
    // 0x8008C6C0: j           L_8008C140
    // 0x8008C6C4: sw          $zero, 0x28($s0)
    MEM_W(0X28, ctx->r16) = 0;
        goto L_8008C140;
    // 0x8008C6C4: sw          $zero, 0x28($s0)
    MEM_W(0X28, ctx->r16) = 0;
L_8008C6C8:
    // 0x8008C6C8: slt         $v0, $v0, $v1
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8008C6CC: bne         $v0, $zero, L_8008C6D8
    if (ctx->r2 != 0) {
        // 0x8008C6D0: lui         $v0, 0xFFFF
        ctx->r2 = S32(0XFFFF << 16);
            goto L_8008C6D8;
    }
    // 0x8008C6D0: lui         $v0, 0xFFFF
    ctx->r2 = S32(0XFFFF << 16);
    // 0x8008C6D4: sll         $v0, $v1, 16
    ctx->r2 = S32(ctx->r3 << 16);
L_8008C6D8:
    // 0x8008C6D8: j           L_8008C140
    // 0x8008C6DC: sw          $v0, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->r2;
        goto L_8008C140;
    // 0x8008C6DC: sw          $v0, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->r2;
L_8008C6E0:
    // 0x8008C6E0: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x8008C6E4: lhu         $v0, -0x5340($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X5340);
    // 0x8008C6E8: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x8008C6EC: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x8008C6F0: j           L_8008C8E8
    // 0x8008C6F4: sw          $v0, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->r2;
        goto L_8008C8E8;
    // 0x8008C6F4: sw          $v0, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->r2;
L_8008C6F8:
    // 0x8008C6F8: lui         $v1, 0x8014
    ctx->r3 = S32(0X8014 << 16);
    // 0x8008C6FC: lbu         $v1, -0x533E($v1)
    ctx->r3 = MEM_BU(ctx->r3, -0X533E);
    // 0x8008C700: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x8008C704: lhu         $v0, -0x5340($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X5340);
    // 0x8008C708: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8008C70C: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x8008C710: sb          $v0, -0x73A8($at)
    MEM_B(-0X73A8, ctx->r1) = ctx->r2;
    // 0x8008C714: j           L_8008C8E8
    // 0x8008C718: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
        goto L_8008C8E8;
    // 0x8008C718: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
L_8008C71C:
    // 0x8008C71C: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x8008C720: lhu         $v0, -0x5340($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X5340);
    // 0x8008C724: sb          $v0, 0x6E($s0)
    MEM_B(0X6E, ctx->r16) = ctx->r2;
    // 0x8008C728: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x8008C72C: lw          $v0, -0x5340($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X5340);
    // 0x8008C730: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x8008C734: srl         $v0, $v0, 8
    ctx->r2 = S32(U32(ctx->r2) >> 8);
    // 0x8008C738: j           L_8008C8E8
    // 0x8008C73C: sb          $v0, 0x6F($s0)
    MEM_B(0X6F, ctx->r16) = ctx->r2;
        goto L_8008C8E8;
    // 0x8008C73C: sb          $v0, 0x6F($s0)
    MEM_B(0X6F, ctx->r16) = ctx->r2;
L_8008C740:
    // 0x8008C740: lw          $v1, 0x24($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X24);
    // 0x8008C744: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x8008C748: j           L_8008C75C
    // 0x8008C74C: lui         $v0, 0x4
    ctx->r2 = S32(0X4 << 16);
        goto L_8008C75C;
    // 0x8008C74C: lui         $v0, 0x4
    ctx->r2 = S32(0X4 << 16);
L_8008C750:
    // 0x8008C750: lw          $v1, 0x24($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X24);
    // 0x8008C754: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x8008C758: lui         $v0, 0x2
    ctx->r2 = S32(0X2 << 16);
L_8008C75C:
    // 0x8008C75C: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x8008C760: j           L_8008C8E8
    // 0x8008C764: sw          $v1, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->r3;
        goto L_8008C8E8;
    // 0x8008C764: sw          $v1, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->r3;
L_8008C768:
    // 0x8008C768: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x8008C76C: lw          $v0, -0x5340($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X5340);
    // 0x8008C770: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x8008C774: srl         $v0, $v0, 8
    ctx->r2 = S32(U32(ctx->r2) >> 8);
    // 0x8008C778: j           L_8008C8E8
    // 0x8008C77C: sb          $v0, 0x2E($s0)
    MEM_B(0X2E, ctx->r16) = ctx->r2;
        goto L_8008C8E8;
    // 0x8008C77C: sb          $v0, 0x2E($s0)
    MEM_B(0X2E, ctx->r16) = ctx->r2;
L_8008C780:
    // 0x8008C780: lui         $v1, 0x8014
    ctx->r3 = S32(0X8014 << 16);
    // 0x8008C784: lhu         $v1, -0x5340($v1)
    ctx->r3 = MEM_HU(ctx->r3, -0X5340);
    // 0x8008C788: lbu         $v0, 0x2E($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X2E);
    // 0x8008C78C: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8008C790: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // 0x8008C794: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x8008C798: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x8008C79C: bgez        $v0, L_8008C7AC
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8008C7A0: slti        $v0, $v0, 0x100
        ctx->r2 = SIGNED(ctx->r2) < 0X100 ? 1 : 0;
            goto L_8008C7AC;
    }
    // 0x8008C7A0: slti        $v0, $v0, 0x100
    ctx->r2 = SIGNED(ctx->r2) < 0X100 ? 1 : 0;
    // 0x8008C7A4: j           L_8008C140
    // 0x8008C7A8: sb          $zero, 0x2E($s0)
    MEM_B(0X2E, ctx->r16) = 0;
        goto L_8008C140;
    // 0x8008C7A8: sb          $zero, 0x2E($s0)
    MEM_B(0X2E, ctx->r16) = 0;
L_8008C7AC:
    // 0x8008C7AC: bnel        $v0, $zero, L_8008C140
    if (ctx->r2 != 0) {
        // 0x8008C7B0: sb          $v1, 0x2E($s0)
        MEM_B(0X2E, ctx->r16) = ctx->r3;
            goto L_8008C140;
    }
    goto skip_10;
    // 0x8008C7B0: sb          $v1, 0x2E($s0)
    MEM_B(0X2E, ctx->r16) = ctx->r3;
    skip_10:
    // 0x8008C7B4: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // 0x8008C7B8: j           L_8008C140
    // 0x8008C7BC: sb          $v0, 0x2E($s0)
    MEM_B(0X2E, ctx->r16) = ctx->r2;
        goto L_8008C140;
    // 0x8008C7BC: sb          $v0, 0x2E($s0)
    MEM_B(0X2E, ctx->r16) = ctx->r2;
L_8008C7C0:
    // 0x8008C7C0: lui         $v1, 0x8014
    ctx->r3 = S32(0X8014 << 16);
    // 0x8008C7C4: lw          $v1, -0x533C($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X533C);
    // 0x8008C7C8: beql        $v1, $zero, L_8008C140
    if (ctx->r3 == 0) {
        // 0x8008C7CC: sh          $zero, 0x2C($s0)
        MEM_H(0X2C, ctx->r16) = 0;
            goto L_8008C140;
    }
    goto skip_11;
    // 0x8008C7CC: sh          $zero, 0x2C($s0)
    MEM_H(0X2C, ctx->r16) = 0;
    skip_11:
    // 0x8008C7D0: lw          $v0, 0x28($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X28);
    // 0x8008C7D4: srl         $v0, $v0, 8
    ctx->r2 = S32(U32(ctx->r2) >> 8);
    // 0x8008C7D8: divu        $zero, $v0, $v1
    if (U32(ctx->r3) != 0) { lo = S32(U32(ctx->r2) / U32(ctx->r3)); hi = S32(U32(ctx->r2) % U32(ctx->r3)); } else { lo = 0; hi = S32(ctx->r2); }
    // 0x8008C7DC: bne         $v1, $zero, L_8008C7E8
    if (ctx->r3 != 0) {
        // 0x8008C7E0: nop
    
            goto L_8008C7E8;
    }
    // 0x8008C7E0: nop

    // 0x8008C7E4: break       7
    do_break(2148059108);
L_8008C7E8:
    // 0x8008C7E8: mflo        $v0
    ctx->r2 = lo;
    // 0x8008C7EC: j           L_8008C140
    // 0x8008C7F0: sh          $v0, 0x2C($s0)
    MEM_H(0X2C, ctx->r16) = ctx->r2;
        goto L_8008C140;
    // 0x8008C7F0: sh          $v0, 0x2C($s0)
    MEM_H(0X2C, ctx->r16) = ctx->r2;
L_8008C7F4:
    // 0x8008C7F4: lui         $a1, 0x8014
    ctx->r5 = S32(0X8014 << 16);
    // 0x8008C7F8: addiu       $a1, $a1, -0x5340
    ctx->r5 = ADD32(ctx->r5, -0X5340);
    // 0x8008C7FC: jal         0x8008B33C
    // 0x8008C800: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_8008B33C(rdram, ctx);
        goto after_25;
    // 0x8008C800: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_25:
    // 0x8008C804: j           L_8008C8E8
    // 0x8008C808: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
        goto L_8008C8E8;
    // 0x8008C808: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
L_8008C80C:
    // 0x8008C80C: lui         $a1, 0x8014
    ctx->r5 = S32(0X8014 << 16);
    // 0x8008C810: addiu       $a1, $a1, -0x5340
    ctx->r5 = ADD32(ctx->r5, -0X5340);
    // 0x8008C814: jal         0x8008B42C
    // 0x8008C818: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_8008B42C(rdram, ctx);
        goto after_26;
    // 0x8008C818: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_26:
    // 0x8008C81C: j           L_8008C8E8
    // 0x8008C820: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
        goto L_8008C8E8;
    // 0x8008C820: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
L_8008C824:
    // 0x8008C824: lui         $a1, 0x8014
    ctx->r5 = S32(0X8014 << 16);
    // 0x8008C828: addiu       $a1, $a1, -0x5340
    ctx->r5 = ADD32(ctx->r5, -0X5340);
    // 0x8008C82C: jal         0x8008B51C
    // 0x8008C830: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_8008B51C(rdram, ctx);
        goto after_27;
    // 0x8008C830: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_27:
    // 0x8008C834: j           L_8008C8E8
    // 0x8008C838: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
        goto L_8008C8E8;
    // 0x8008C838: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
L_8008C83C:
    // 0x8008C83C: lui         $a1, 0x8014
    ctx->r5 = S32(0X8014 << 16);
    // 0x8008C840: addiu       $a1, $a1, -0x5340
    ctx->r5 = ADD32(ctx->r5, -0X5340);
    // 0x8008C844: jal         0x8008B60C
    // 0x8008C848: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_8008B60C(rdram, ctx);
        goto after_28;
    // 0x8008C848: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_28:
    // 0x8008C84C: j           L_8008C8E8
    // 0x8008C850: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
        goto L_8008C8E8;
    // 0x8008C850: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
L_8008C854:
    // 0x8008C854: lui         $a1, 0x8014
    ctx->r5 = S32(0X8014 << 16);
    // 0x8008C858: addiu       $a1, $a1, -0x5340
    ctx->r5 = ADD32(ctx->r5, -0X5340);
    // 0x8008C85C: jal         0x8008B6FC
    // 0x8008C860: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_8008B6FC(rdram, ctx);
        goto after_29;
    // 0x8008C860: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_29:
    // 0x8008C864: j           L_8008C8E8
    // 0x8008C868: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
        goto L_8008C8E8;
    // 0x8008C868: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
L_8008C86C:
    // 0x8008C86C: lui         $a1, 0x8014
    ctx->r5 = S32(0X8014 << 16);
    // 0x8008C870: addiu       $a1, $a1, -0x5340
    ctx->r5 = ADD32(ctx->r5, -0X5340);
    // 0x8008C874: jal         0x8008B7EC
    // 0x8008C878: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_8008B7EC(rdram, ctx);
        goto after_30;
    // 0x8008C878: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_30:
    // 0x8008C87C: j           L_8008C8E8
    // 0x8008C880: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
        goto L_8008C8E8;
    // 0x8008C880: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
L_8008C884:
    // 0x8008C884: lui         $a1, 0x8014
    ctx->r5 = S32(0X8014 << 16);
    // 0x8008C888: addiu       $a1, $a1, -0x5340
    ctx->r5 = ADD32(ctx->r5, -0X5340);
    // 0x8008C88C: jal         0x8008B8DC
    // 0x8008C890: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_8008B8DC(rdram, ctx);
        goto after_31;
    // 0x8008C890: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_31:
    // 0x8008C894: j           L_8008C8E8
    // 0x8008C898: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
        goto L_8008C8E8;
    // 0x8008C898: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
L_8008C89C:
    // 0x8008C89C: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8008C8A0: lw          $a0, -0x5340($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X5340);
    // 0x8008C8A4: srl         $v1, $a0, 8
    ctx->r3 = S32(U32(ctx->r4) >> 8);
    // 0x8008C8A8: andi        $v1, $v1, 0xFF
    ctx->r3 = ctx->r3 & 0XFF;
    // 0x8008C8AC: sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3 << 1);
    // 0x8008C8B0: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8008C8B4: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8008C8B8: addu        $v1, $s0, $v0
    ctx->r3 = ADD32(ctx->r16, ctx->r2);
    // 0x8008C8BC: lw          $v0, 0x168($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X168);
    // 0x8008C8C0: srl         $a0, $a0, 16
    ctx->r4 = S32(U32(ctx->r4) >> 16);
    // 0x8008C8C4: sll         $a0, $a0, 8
    ctx->r4 = S32(ctx->r4 << 8);
    // 0x8008C8C8: beq         $v0, $zero, L_8008C8D4
    if (ctx->r2 == 0) {
        // 0x8008C8CC: sw          $a0, 0x10($sp)
        MEM_W(0X10, ctx->r29) = ctx->r4;
            goto L_8008C8D4;
    }
    // 0x8008C8CC: sw          $a0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r4;
    // 0x8008C8D0: sw          $zero, 0x164($v1)
    MEM_W(0X164, ctx->r3) = 0;
L_8008C8D4:
    // 0x8008C8D4: lw          $v0, 0x10($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X10);
    // 0x8008C8D8: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x8008C8DC: j           L_8008C8E8
    // 0x8008C8E0: sw          $v0, 0x168($v1)
    MEM_W(0X168, ctx->r3) = ctx->r2;
        goto L_8008C8E8;
    // 0x8008C8E0: sw          $v0, 0x168($v1)
    MEM_W(0X168, ctx->r3) = ctx->r2;
L_8008C8E4:
    // 0x8008C8E4: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
L_8008C8E8:
    // 0x8008C8E8: andi        $v0, $a0, 0xFF
    ctx->r2 = ctx->r4 & 0XFF;
    // 0x8008C8EC: beq         $v0, $zero, L_8008BF20
    if (ctx->r2 == 0) {
        // 0x8008C8F0: nop
    
            goto L_8008BF20;
    }
    // 0x8008C8F0: nop

    // 0x8008C8F4: j           L_8008C994
    // 0x8008C8F8: nop

        goto L_8008C994;
    // 0x8008C8F8: nop

L_8008C8FC:
    // 0x8008C8FC: lw          $v1, 0x24($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X24);
    // 0x8008C900: andi        $v0, $v1, 0x4
    ctx->r2 = ctx->r3 & 0X4;
    // 0x8008C904: beq         $v0, $zero, L_8008C92C
    if (ctx->r2 == 0) {
        // 0x8008C908: lui         $v0, 0x400
        ctx->r2 = S32(0X400 << 16);
            goto L_8008C92C;
    }
    // 0x8008C908: lui         $v0, 0x400
    ctx->r2 = S32(0X400 << 16);
    // 0x8008C90C: and         $v0, $v1, $v0
    ctx->r2 = ctx->r3 & ctx->r2;
    // 0x8008C910: bne         $v0, $zero, L_8008C92C
    if (ctx->r2 != 0) {
        // 0x8008C914: andi        $v0, $v1, 0x8
        ctx->r2 = ctx->r3 & 0X8;
            goto L_8008C92C;
    }
    // 0x8008C914: andi        $v0, $v1, 0x8
    ctx->r2 = ctx->r3 & 0X8;
    // 0x8008C918: beq         $v0, $zero, L_8008C92C
    if (ctx->r2 == 0) {
        // 0x8008C91C: addiu       $v0, $zero, -0x5
        ctx->r2 = ADD32(0, -0X5);
            goto L_8008C92C;
    }
    // 0x8008C91C: addiu       $v0, $zero, -0x5
    ctx->r2 = ADD32(0, -0X5);
    // 0x8008C920: and         $v0, $v1, $v0
    ctx->r2 = ctx->r3 & ctx->r2;
    // 0x8008C924: sw          $v0, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->r2;
    // 0x8008C928: sw          $zero, 0x40($s0)
    MEM_W(0X40, ctx->r16) = 0;
L_8008C92C:
    // 0x8008C92C: lw          $v0, 0x24($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X24);
    // 0x8008C930: lui         $v1, 0x8
    ctx->r3 = S32(0X8 << 16);
    // 0x8008C934: and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // 0x8008C938: beq         $v0, $zero, L_8008C96C
    if (ctx->r2 == 0) {
        // 0x8008C93C: nop
    
            goto L_8008C96C;
    }
    // 0x8008C93C: nop

    // 0x8008C940: lbu         $a0, 0x67($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X67);
    // 0x8008C944: jal         0x800920FC
    // 0x8008C948: nop

    func_800920FC(rdram, ctx);
        goto after_32;
    // 0x8008C948: nop

    after_32:
    // 0x8008C94C: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x8008C950: bne         $v0, $zero, L_8008C96C
    if (ctx->r2 != 0) {
        // 0x8008C954: lui         $v1, 0xFFF7
        ctx->r3 = S32(0XFFF7 << 16);
            goto L_8008C96C;
    }
    // 0x8008C954: lui         $v1, 0xFFF7
    ctx->r3 = S32(0XFFF7 << 16);
    // 0x8008C958: lw          $v0, 0x24($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X24);
    // 0x8008C95C: ori         $v1, $v1, 0xFFFF
    ctx->r3 = ctx->r3 | 0XFFFF;
    // 0x8008C960: sw          $zero, 0x40($s0)
    MEM_W(0X40, ctx->r16) = 0;
    // 0x8008C964: and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // 0x8008C968: sw          $v0, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->r2;
L_8008C96C:
    // 0x8008C96C: lw          $v1, 0x40($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X40);
    // 0x8008C970: ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
    // 0x8008C974: beq         $v1, $v0, L_8008C994
    if (ctx->r3 == ctx->r2) {
        // 0x8008C978: nop
    
            goto L_8008C994;
    }
    // 0x8008C978: nop

    // 0x8008C97C: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x8008C980: lw          $v0, -0x5338($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X5338);
    // 0x8008C984: subu        $v0, $v1, $v0
    ctx->r2 = SUB32(ctx->r3, ctx->r2);
    // 0x8008C988: bgez        $v0, L_8008C994
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8008C98C: sw          $v0, 0x40($s0)
        MEM_W(0X40, ctx->r16) = ctx->r2;
            goto L_8008C994;
    }
    // 0x8008C98C: sw          $v0, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->r2;
    // 0x8008C990: sw          $zero, 0x40($s0)
    MEM_W(0X40, ctx->r16) = 0;
L_8008C994:
    // 0x8008C994: lw          $ra, 0x60($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X60);
    // 0x8008C998: lw          $s1, 0x5C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X5C);
    // 0x8008C99C: lw          $s0, 0x58($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X58);
    // 0x8008C9A0: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    // 0x8008C9A4: jr          $ra
    // 0x8008C9A8: nop

    return;
    // 0x8008C9A8: nop

;}
RECOMP_FUNC void func_8008C9AC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008C9AC: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x8008C9B0: lbu         $v0, 0x1AD0($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X1AD0);
    // 0x8008C9B4: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x8008C9B8: sw          $s6, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r22;
    // 0x8008C9BC: addu        $s6, $zero, $zero
    ctx->r22 = ADD32(0, 0);
    // 0x8008C9C0: sw          $ra, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r31;
    // 0x8008C9C4: sw          $fp, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r30;
    // 0x8008C9C8: sw          $s7, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r23;
    // 0x8008C9CC: sw          $s5, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r21;
    // 0x8008C9D0: sw          $s4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r20;
    // 0x8008C9D4: sw          $s3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r19;
    // 0x8008C9D8: sw          $s2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r18;
    // 0x8008C9DC: sw          $s1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r17;
    // 0x8008C9E0: blez        $v0, L_8008D738
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8008C9E4: sw          $s0, 0x28($sp)
        MEM_W(0X28, ctx->r29) = ctx->r16;
            goto L_8008D738;
    }
    // 0x8008C9E4: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x8008C9E8: lui         $s7, 0x800A
    ctx->r23 = S32(0X800A << 16);
    // 0x8008C9EC: addiu       $s7, $s7, 0xF58
    ctx->r23 = ADD32(ctx->r23, 0XF58);
    // 0x8008C9F0: addu        $s1, $zero, $zero
    ctx->r17 = ADD32(0, 0);
    // 0x8008C9F4: lui         $fp, 0x8014
    ctx->r30 = S32(0X8014 << 16);
    // 0x8008C9F8: addiu       $fp, $fp, -0x2780
    ctx->r30 = ADD32(ctx->r30, -0X2780);
    // 0x8008C9FC: addu        $s5, $fp, $zero
    ctx->r21 = ADD32(ctx->r30, 0);
L_8008CA00:
    // 0x8008CA00: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x8008CA04: addu        $at, $at, $s1
    ctx->r1 = ADD32(ctx->r1, ctx->r17);
    // 0x8008CA08: lw          $v0, -0x2780($at)
    ctx->r2 = MEM_W(ctx->r1, -0X2780);
    // 0x8008CA0C: beq         $v0, $zero, L_8008CA1C
    if (ctx->r2 == 0) {
        // 0x8008CA10: nop
    
            goto L_8008CA1C;
    }
    // 0x8008CA10: nop

    // 0x8008CA14: jal         0x8008BC10
    // 0x8008CA18: addu        $a0, $s5, $zero
    ctx->r4 = ADD32(ctx->r21, 0);
    func_8008BC10(rdram, ctx);
        goto after_0;
    // 0x8008CA18: addu        $a0, $s5, $zero
    ctx->r4 = ADD32(ctx->r21, 0);
    after_0:
L_8008CA1C:
    // 0x8008CA1C: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x8008CA20: addu        $at, $at, $s1
    ctx->r1 = ADD32(ctx->r1, ctx->r17);
    // 0x8008CA24: lbu         $v0, -0x26C7($at)
    ctx->r2 = MEM_BU(ctx->r1, -0X26C7);
    // 0x8008CA28: bnel        $v0, $zero, L_8008D71C
    if (ctx->r2 != 0) {
        // 0x8008CA2C: addiu       $s1, $s1, 0x17C
        ctx->r17 = ADD32(ctx->r17, 0X17C);
            goto L_8008D71C;
    }
    goto skip_0;
    // 0x8008CA2C: addiu       $s1, $s1, 0x17C
    ctx->r17 = ADD32(ctx->r17, 0X17C);
    skip_0:
    // 0x8008CA30: lui         $t0, 0x8014
    ctx->r8 = S32(0X8014 << 16);
    // 0x8008CA34: lw          $t0, -0x5338($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X5338);
    // 0x8008CA38: addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    // 0x8008CA3C: addiu       $a3, $s1, 0x18
    ctx->r7 = ADD32(ctx->r17, 0X18);
L_8008CA40:
    // 0x8008CA40: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x8008CA44: addu        $at, $at, $a2
    ctx->r1 = ADD32(ctx->r1, ctx->r6);
    // 0x8008CA48: lw          $v0, -0x2618($at)
    ctx->r2 = MEM_W(ctx->r1, -0X2618);
    // 0x8008CA4C: beql        $v0, $zero, L_8008CB0C
    if (ctx->r2 == 0) {
        // 0x8008CA50: addiu       $a2, $a2, 0xC
        ctx->r6 = ADD32(ctx->r6, 0XC);
            goto L_8008CB0C;
    }
    goto skip_1;
    // 0x8008CA50: addiu       $a2, $a2, 0xC
    ctx->r6 = ADD32(ctx->r6, 0XC);
    skip_1:
    // 0x8008CA54: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x8008CA58: addu        $at, $at, $a2
    ctx->r1 = ADD32(ctx->r1, ctx->r6);
    // 0x8008CA5C: lw          $a0, -0x261C($at)
    ctx->r4 = MEM_W(ctx->r1, -0X261C);
    // 0x8008CA60: addu        $a0, $a0, $t0
    ctx->r4 = ADD32(ctx->r4, ctx->r8);
    // 0x8008CA64: divu        $zero, $a0, $v0
    if (U32(ctx->r2) != 0) { lo = S32(U32(ctx->r4) / U32(ctx->r2)); hi = S32(U32(ctx->r4) % U32(ctx->r2)); } else { lo = 0; hi = S32(ctx->r4); }
    // 0x8008CA68: bne         $v0, $zero, L_8008CA74
    if (ctx->r2 != 0) {
        // 0x8008CA6C: nop
    
            goto L_8008CA74;
    }
    // 0x8008CA6C: nop

    // 0x8008CA70: break       7
    do_break(2148059760);
L_8008CA74:
    // 0x8008CA74: mfhi        $v1
    ctx->r3 = hi;
    // 0x8008CA78: srl         $v0, $v0, 8
    ctx->r2 = S32(U32(ctx->r2) >> 8);
    // 0x8008CA7C: sll         $v1, $v1, 4
    ctx->r3 = S32(ctx->r3 << 4);
    // 0x8008CA80: divu        $zero, $v1, $v0
    if (U32(ctx->r2) != 0) { lo = S32(U32(ctx->r3) / U32(ctx->r2)); hi = S32(U32(ctx->r3) % U32(ctx->r2)); } else { lo = 0; hi = S32(ctx->r3); }
    // 0x8008CA84: bne         $v0, $zero, L_8008CA90
    if (ctx->r2 != 0) {
        // 0x8008CA88: nop
    
            goto L_8008CA90;
    }
    // 0x8008CA88: nop

    // 0x8008CA8C: break       7
    do_break(2148059788);
L_8008CA90:
    // 0x8008CA90: mflo        $v1
    ctx->r3 = lo;
    // 0x8008CA94: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x8008CA98: addu        $at, $at, $a2
    ctx->r1 = ADD32(ctx->r1, ctx->r6);
    // 0x8008CA9C: sw          $a0, -0x261C($at)
    MEM_W(-0X261C, ctx->r1) = ctx->r4;
    // 0x8008CAA0: andi        $a0, $v1, 0xFFF
    ctx->r4 = ctx->r3 & 0XFFF;
    // 0x8008CAA4: sltiu       $v0, $a0, 0x400
    ctx->r2 = ctx->r4 < 0X400 ? 1 : 0;
    // 0x8008CAA8: bne         $v0, $zero, L_8008CAC8
    if (ctx->r2 != 0) {
        // 0x8008CAAC: sll         $v0, $a0, 1
        ctx->r2 = S32(ctx->r4 << 1);
            goto L_8008CAC8;
    }
    // 0x8008CAAC: sll         $v0, $a0, 1
    ctx->r2 = S32(ctx->r4 << 1);
    // 0x8008CAB0: sltiu       $v0, $a0, 0x800
    ctx->r2 = ctx->r4 < 0X800 ? 1 : 0;
    // 0x8008CAB4: beq         $v0, $zero, L_8008CAD8
    if (ctx->r2 == 0) {
        // 0x8008CAB8: andi        $v0, $v1, 0x3FF
        ctx->r2 = ctx->r3 & 0X3FF;
            goto L_8008CAD8;
    }
    // 0x8008CAB8: andi        $v0, $v1, 0x3FF
    ctx->r2 = ctx->r3 & 0X3FF;
    // 0x8008CABC: addiu       $t1, $zero, 0x3FF
    ctx->r9 = ADD32(0, 0X3FF);
    // 0x8008CAC0: subu        $v0, $t1, $v0
    ctx->r2 = SUB32(ctx->r9, ctx->r2);
    // 0x8008CAC4: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
L_8008CAC8:
    // 0x8008CAC8: addu        $v0, $v0, $s7
    ctx->r2 = ADD32(ctx->r2, ctx->r23);
    // 0x8008CACC: lhu         $v0, 0x0($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X0);
    // 0x8008CAD0: j           L_8008CAFC
    // 0x8008CAD4: nop

        goto L_8008CAFC;
    // 0x8008CAD4: nop

L_8008CAD8:
    // 0x8008CAD8: sltiu       $v0, $a0, 0xC00
    ctx->r2 = ctx->r4 < 0XC00 ? 1 : 0;
    // 0x8008CADC: bne         $v0, $zero, L_8008CAEC
    if (ctx->r2 != 0) {
        // 0x8008CAE0: andi        $v0, $v1, 0x3FF
        ctx->r2 = ctx->r3 & 0X3FF;
            goto L_8008CAEC;
    }
    // 0x8008CAE0: andi        $v0, $v1, 0x3FF
    ctx->r2 = ctx->r3 & 0X3FF;
    // 0x8008CAE4: addiu       $t1, $zero, 0x3FF
    ctx->r9 = ADD32(0, 0X3FF);
    // 0x8008CAE8: subu        $v0, $t1, $v0
    ctx->r2 = SUB32(ctx->r9, ctx->r2);
L_8008CAEC:
    // 0x8008CAEC: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x8008CAF0: addu        $v0, $v0, $s7
    ctx->r2 = ADD32(ctx->r2, ctx->r23);
    // 0x8008CAF4: lhu         $v0, 0x0($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X0);
    // 0x8008CAF8: negu        $v0, $v0
    ctx->r2 = SUB32(0, ctx->r2);
L_8008CAFC:
    // 0x8008CAFC: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x8008CB00: addu        $at, $at, $a2
    ctx->r1 = ADD32(ctx->r1, ctx->r6);
    // 0x8008CB04: sh          $v0, -0x2614($at)
    MEM_H(-0X2614, ctx->r1) = ctx->r2;
    // 0x8008CB08: addiu       $a2, $a2, 0xC
    ctx->r6 = ADD32(ctx->r6, 0XC);
L_8008CB0C:
    // 0x8008CB0C: slt         $v0, $a2, $a3
    ctx->r2 = SIGNED(ctx->r6) < SIGNED(ctx->r7) ? 1 : 0;
    // 0x8008CB10: bne         $v0, $zero, L_8008CA40
    if (ctx->r2 != 0) {
        // 0x8008CB14: nop
    
            goto L_8008CA40;
    }
    // 0x8008CB14: nop

    // 0x8008CB18: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x8008CB1C: addu        $at, $at, $s1
    ctx->r1 = ADD32(ctx->r1, ctx->r17);
    // 0x8008CB20: lw          $v0, -0x275C($at)
    ctx->r2 = MEM_W(ctx->r1, -0X275C);
    // 0x8008CB24: andi        $v0, $v0, 0x2000
    ctx->r2 = ctx->r2 & 0X2000;
    // 0x8008CB28: beq         $v0, $zero, L_8008CC00
    if (ctx->r2 == 0) {
        // 0x8008CB2C: nop
    
            goto L_8008CC00;
    }
    // 0x8008CB2C: nop

    // 0x8008CB30: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x8008CB34: addu        $at, $at, $s1
    ctx->r1 = ADD32(ctx->r1, ctx->r17);
    // 0x8008CB38: lw          $a0, -0x270C($at)
    ctx->r4 = MEM_W(ctx->r1, -0X270C);
    // 0x8008CB3C: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x8008CB40: lw          $v0, -0x5338($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X5338);
    // 0x8008CB44: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x8008CB48: addu        $at, $at, $s1
    ctx->r1 = ADD32(ctx->r1, ctx->r17);
    // 0x8008CB4C: lw          $v1, -0x2708($at)
    ctx->r3 = MEM_W(ctx->r1, -0X2708);
    // 0x8008CB50: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // 0x8008CB54: divu        $zero, $a0, $v1
    if (U32(ctx->r3) != 0) { lo = S32(U32(ctx->r4) / U32(ctx->r3)); hi = S32(U32(ctx->r4) % U32(ctx->r3)); } else { lo = 0; hi = S32(ctx->r4); }
    // 0x8008CB58: bne         $v1, $zero, L_8008CB64
    if (ctx->r3 != 0) {
        // 0x8008CB5C: nop
    
            goto L_8008CB64;
    }
    // 0x8008CB5C: nop

    // 0x8008CB60: break       7
    do_break(2148060000);
L_8008CB64:
    // 0x8008CB64: mfhi        $v0
    ctx->r2 = hi;
    // 0x8008CB68: srl         $v1, $v1, 8
    ctx->r3 = S32(U32(ctx->r3) >> 8);
    // 0x8008CB6C: sll         $v0, $v0, 4
    ctx->r2 = S32(ctx->r2 << 4);
    // 0x8008CB70: divu        $zero, $v0, $v1
    if (U32(ctx->r3) != 0) { lo = S32(U32(ctx->r2) / U32(ctx->r3)); hi = S32(U32(ctx->r2) % U32(ctx->r3)); } else { lo = 0; hi = S32(ctx->r2); }
    // 0x8008CB74: bne         $v1, $zero, L_8008CB80
    if (ctx->r3 != 0) {
        // 0x8008CB78: nop
    
            goto L_8008CB80;
    }
    // 0x8008CB78: nop

    // 0x8008CB7C: break       7
    do_break(2148060028);
L_8008CB80:
    // 0x8008CB80: mflo        $a1
    ctx->r5 = lo;
    // 0x8008CB84: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x8008CB88: addu        $at, $at, $s1
    ctx->r1 = ADD32(ctx->r1, ctx->r17);
    // 0x8008CB8C: sw          $a0, -0x270C($at)
    MEM_W(-0X270C, ctx->r1) = ctx->r4;
    // 0x8008CB90: andi        $v1, $a1, 0xFFF
    ctx->r3 = ctx->r5 & 0XFFF;
    // 0x8008CB94: sltiu       $v0, $v1, 0x400
    ctx->r2 = ctx->r3 < 0X400 ? 1 : 0;
    // 0x8008CB98: bne         $v0, $zero, L_8008CBB8
    if (ctx->r2 != 0) {
        // 0x8008CB9C: sll         $v0, $v1, 1
        ctx->r2 = S32(ctx->r3 << 1);
            goto L_8008CBB8;
    }
    // 0x8008CB9C: sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3 << 1);
    // 0x8008CBA0: sltiu       $v0, $v1, 0x800
    ctx->r2 = ctx->r3 < 0X800 ? 1 : 0;
    // 0x8008CBA4: beq         $v0, $zero, L_8008CBC8
    if (ctx->r2 == 0) {
        // 0x8008CBA8: andi        $v0, $a1, 0x3FF
        ctx->r2 = ctx->r5 & 0X3FF;
            goto L_8008CBC8;
    }
    // 0x8008CBA8: andi        $v0, $a1, 0x3FF
    ctx->r2 = ctx->r5 & 0X3FF;
    // 0x8008CBAC: addiu       $t1, $zero, 0x3FF
    ctx->r9 = ADD32(0, 0X3FF);
    // 0x8008CBB0: subu        $v0, $t1, $v0
    ctx->r2 = SUB32(ctx->r9, ctx->r2);
    // 0x8008CBB4: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
L_8008CBB8:
    // 0x8008CBB8: addu        $v0, $v0, $s7
    ctx->r2 = ADD32(ctx->r2, ctx->r23);
    // 0x8008CBBC: lhu         $v0, 0x0($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X0);
    // 0x8008CBC0: j           L_8008CBF0
    // 0x8008CBC4: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
        goto L_8008CBF0;
    // 0x8008CBC4: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
L_8008CBC8:
    // 0x8008CBC8: sltiu       $v0, $v1, 0xC00
    ctx->r2 = ctx->r3 < 0XC00 ? 1 : 0;
    // 0x8008CBCC: bne         $v0, $zero, L_8008CBDC
    if (ctx->r2 != 0) {
        // 0x8008CBD0: andi        $v0, $a1, 0x3FF
        ctx->r2 = ctx->r5 & 0X3FF;
            goto L_8008CBDC;
    }
    // 0x8008CBD0: andi        $v0, $a1, 0x3FF
    ctx->r2 = ctx->r5 & 0X3FF;
    // 0x8008CBD4: addiu       $t1, $zero, 0x3FF
    ctx->r9 = ADD32(0, 0X3FF);
    // 0x8008CBD8: subu        $v0, $t1, $v0
    ctx->r2 = SUB32(ctx->r9, ctx->r2);
L_8008CBDC:
    // 0x8008CBDC: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x8008CBE0: addu        $v0, $v0, $s7
    ctx->r2 = ADD32(ctx->r2, ctx->r23);
    // 0x8008CBE4: lhu         $v0, 0x0($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X0);
    // 0x8008CBE8: negu        $v0, $v0
    ctx->r2 = SUB32(0, ctx->r2);
    // 0x8008CBEC: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
L_8008CBF0:
    // 0x8008CBF0: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x8008CBF4: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x8008CBF8: addu        $at, $at, $s1
    ctx->r1 = ADD32(ctx->r1, ctx->r17);
    // 0x8008CBFC: sw          $v0, -0x2704($at)
    MEM_W(-0X2704, ctx->r1) = ctx->r2;
L_8008CC00:
    // 0x8008CC00: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x8008CC04: addiu       $v0, $v0, -0x2734
    ctx->r2 = ADD32(ctx->r2, -0X2734);
    // 0x8008CC08: addiu       $v1, $v0, -0x8
    ctx->r3 = ADD32(ctx->r2, -0X8);
    // 0x8008CC0C: addu        $a0, $s1, $v1
    ctx->r4 = ADD32(ctx->r17, ctx->r3);
    // 0x8008CC10: addiu       $v1, $v0, 0x38
    ctx->r3 = ADD32(ctx->r2, 0X38);
    // 0x8008CC14: addu        $a3, $s1, $v1
    ctx->r7 = ADD32(ctx->r17, ctx->r3);
    // 0x8008CC18: addu        $a2, $s1, $v0
    ctx->r6 = ADD32(ctx->r17, ctx->r2);
    // 0x8008CC1C: addiu       $v0, $v0, 0x60
    ctx->r2 = ADD32(ctx->r2, 0X60);
    // 0x8008CC20: addu        $a1, $s1, $v0
    ctx->r5 = ADD32(ctx->r17, ctx->r2);
    // 0x8008CC24: addiu       $t0, $a0, 0x8
    ctx->r8 = ADD32(ctx->r4, 0X8);
L_8008CC28:
    // 0x8008CC28: lbu         $v0, 0x0($a2)
    ctx->r2 = MEM_BU(ctx->r6, 0X0);
    // 0x8008CC2C: beql        $v0, $zero, L_8008CC70
    if (ctx->r2 == 0) {
        // 0x8008CC30: addiu       $a0, $a0, 0x4
        ctx->r4 = ADD32(ctx->r4, 0X4);
            goto L_8008CC70;
    }
    goto skip_2;
    // 0x8008CC30: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    skip_2:
    // 0x8008CC34: lbu         $v0, 0x0($a1)
    ctx->r2 = MEM_BU(ctx->r5, 0X0);
    // 0x8008CC38: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x8008CC3C: sb          $v0, 0x0($a1)
    MEM_B(0X0, ctx->r5) = ctx->r2;
    // 0x8008CC40: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x8008CC44: bne         $v0, $zero, L_8008CC5C
    if (ctx->r2 != 0) {
        // 0x8008CC48: nop
    
            goto L_8008CC5C;
    }
    // 0x8008CC48: nop

    // 0x8008CC4C: lbu         $v0, 0x0($a2)
    ctx->r2 = MEM_BU(ctx->r6, 0X0);
    // 0x8008CC50: sb          $v0, 0x0($a1)
    MEM_B(0X0, ctx->r5) = ctx->r2;
    // 0x8008CC54: j           L_8008CC6C
    // 0x8008CC58: sw          $zero, 0x0($a0)
    MEM_W(0X0, ctx->r4) = 0;
        goto L_8008CC6C;
    // 0x8008CC58: sw          $zero, 0x0($a0)
    MEM_W(0X0, ctx->r4) = 0;
L_8008CC5C:
    // 0x8008CC5C: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8008CC60: lw          $v1, 0x0($a3)
    ctx->r3 = MEM_W(ctx->r7, 0X0);
    // 0x8008CC64: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8008CC68: sw          $v0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r2;
L_8008CC6C:
    // 0x8008CC6C: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
L_8008CC70:
    // 0x8008CC70: addiu       $a3, $a3, 0x4
    ctx->r7 = ADD32(ctx->r7, 0X4);
    // 0x8008CC74: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x8008CC78: slt         $v0, $a0, $t0
    ctx->r2 = SIGNED(ctx->r4) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x8008CC7C: bne         $v0, $zero, L_8008CC28
    if (ctx->r2 != 0) {
        // 0x8008CC80: addiu       $a1, $a1, 0x1
        ctx->r5 = ADD32(ctx->r5, 0X1);
            goto L_8008CC28;
    }
    // 0x8008CC80: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x8008CC84: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x8008CC88: addu        $at, $at, $s1
    ctx->r1 = ADD32(ctx->r1, ctx->r17);
    // 0x8008CC8C: lbu         $v1, -0x2732($at)
    ctx->r3 = MEM_BU(ctx->r1, -0X2732);
    // 0x8008CC90: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // 0x8008CC94: beq         $v1, $v0, L_8008CCC8
    if (ctx->r3 == ctx->r2) {
        // 0x8008CC98: addu        $a0, $s1, $fp
        ctx->r4 = ADD32(ctx->r17, ctx->r30);
            goto L_8008CCC8;
    }
    // 0x8008CC98: addu        $a0, $s1, $fp
    ctx->r4 = ADD32(ctx->r17, ctx->r30);
    // 0x8008CC9C: jal         0x80084860
    // 0x8008CCA0: addiu       $a1, $a0, 0x12C
    ctx->r5 = ADD32(ctx->r4, 0X12C);
    func_80084860(rdram, ctx);
        goto after_1;
    // 0x8008CCA0: addiu       $a1, $a0, 0x12C
    ctx->r5 = ADD32(ctx->r4, 0X12C);
    after_1:
    // 0x8008CCA4: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x8008CCA8: sltiu       $v0, $v0, 0x1F81
    ctx->r2 = ctx->r2 < 0X1F81 ? 1 : 0;
    // 0x8008CCAC: bne         $v0, $zero, L_8008CCC8
    if (ctx->r2 != 0) {
        // 0x8008CCB0: lui         $v1, 0x400
        ctx->r3 = S32(0X400 << 16);
            goto L_8008CCC8;
    }
    // 0x8008CCB0: lui         $v1, 0x400
    ctx->r3 = S32(0X400 << 16);
    // 0x8008CCB4: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x8008CCB8: addu        $at, $at, $s1
    ctx->r1 = ADD32(ctx->r1, ctx->r17);
    // 0x8008CCBC: lw          $v0, -0x275C($at)
    ctx->r2 = MEM_W(ctx->r1, -0X275C);
    // 0x8008CCC0: j           L_8008CCE0
    // 0x8008CCC4: or          $v0, $v0, $v1
    ctx->r2 = ctx->r2 | ctx->r3;
        goto L_8008CCE0;
    // 0x8008CCC4: or          $v0, $v0, $v1
    ctx->r2 = ctx->r2 | ctx->r3;
L_8008CCC8:
    // 0x8008CCC8: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x8008CCCC: addu        $at, $at, $s1
    ctx->r1 = ADD32(ctx->r1, ctx->r17);
    // 0x8008CCD0: lw          $v0, -0x275C($at)
    ctx->r2 = MEM_W(ctx->r1, -0X275C);
    // 0x8008CCD4: lui         $v1, 0xFBFF
    ctx->r3 = S32(0XFBFF << 16);
    // 0x8008CCD8: ori         $v1, $v1, 0xFFFF
    ctx->r3 = ctx->r3 | 0XFFFF;
    // 0x8008CCDC: and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
L_8008CCE0:
    // 0x8008CCE0: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x8008CCE4: addu        $at, $at, $s1
    ctx->r1 = ADD32(ctx->r1, ctx->r17);
    // 0x8008CCE8: sw          $v0, -0x275C($at)
    MEM_W(-0X275C, ctx->r1) = ctx->r2;
    // 0x8008CCEC: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x8008CCF0: addu        $at, $at, $s1
    ctx->r1 = ADD32(ctx->r1, ctx->r17);
    // 0x8008CCF4: lw          $v1, -0x275C($at)
    ctx->r3 = MEM_W(ctx->r1, -0X275C);
    // 0x8008CCF8: andi        $v0, $v1, 0x1000
    ctx->r2 = ctx->r3 & 0X1000;
    // 0x8008CCFC: bne         $v0, $zero, L_8008CE60
    if (ctx->r2 != 0) {
        // 0x8008CD00: andi        $v0, $v1, 0x20
        ctx->r2 = ctx->r3 & 0X20;
            goto L_8008CE60;
    }
    // 0x8008CD00: andi        $v0, $v1, 0x20
    ctx->r2 = ctx->r3 & 0X20;
    // 0x8008CD04: andi        $v0, $v1, 0x10
    ctx->r2 = ctx->r3 & 0X10;
    // 0x8008CD08: bne         $v0, $zero, L_8008CE60
    if (ctx->r2 != 0) {
        // 0x8008CD0C: andi        $v0, $v1, 0x20
        ctx->r2 = ctx->r3 & 0X20;
            goto L_8008CE60;
    }
    // 0x8008CD0C: andi        $v0, $v1, 0x20
    ctx->r2 = ctx->r3 & 0X20;
    // 0x8008CD10: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x8008CD14: addu        $at, $at, $s1
    ctx->r1 = ADD32(ctx->r1, ctx->r17);
    // 0x8008CD18: lbu         $v0, -0x2732($at)
    ctx->r2 = MEM_BU(ctx->r1, -0X2732);
    // 0x8008CD1C: addiu       $s2, $zero, 0xFF
    ctx->r18 = ADD32(0, 0XFF);
    // 0x8008CD20: beq         $v0, $s2, L_8008CE5C
    if (ctx->r2 == ctx->r18) {
        // 0x8008CD24: addu        $s0, $s1, $fp
        ctx->r16 = ADD32(ctx->r17, ctx->r30);
            goto L_8008CE5C;
    }
    // 0x8008CD24: addu        $s0, $s1, $fp
    ctx->r16 = ADD32(ctx->r17, ctx->r30);
    // 0x8008CD28: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x8008CD2C: jal         0x80084860
    // 0x8008CD30: addiu       $a1, $s0, 0x13E
    ctx->r5 = ADD32(ctx->r16, 0X13E);
    func_80084860(rdram, ctx);
        goto after_2;
    // 0x8008CD30: addiu       $a1, $s0, 0x13E
    ctx->r5 = ADD32(ctx->r16, 0X13E);
    after_2:
    // 0x8008CD34: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x8008CD38: sltiu       $v0, $v0, 0x1F81
    ctx->r2 = ctx->r2 < 0X1F81 ? 1 : 0;
    // 0x8008CD3C: beq         $v0, $zero, L_8008CDB0
    if (ctx->r2 == 0) {
        // 0x8008CD40: addiu       $v0, $zero, -0x801
        ctx->r2 = ADD32(0, -0X801);
            goto L_8008CDB0;
    }
    // 0x8008CD40: addiu       $v0, $zero, -0x801
    ctx->r2 = ADD32(0, -0X801);
    // 0x8008CD44: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x8008CD48: addu        $at, $at, $s1
    ctx->r1 = ADD32(ctx->r1, ctx->r17);
    // 0x8008CD4C: lw          $v1, -0x275C($at)
    ctx->r3 = MEM_W(ctx->r1, -0X275C);
    // 0x8008CD50: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x8008CD54: addu        $at, $at, $s1
    ctx->r1 = ADD32(ctx->r1, ctx->r17);
    // 0x8008CD58: lbu         $a1, -0x2731($at)
    ctx->r5 = MEM_BU(ctx->r1, -0X2731);
    // 0x8008CD5C: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x8008CD60: addu        $at, $at, $s1
    ctx->r1 = ADD32(ctx->r1, ctx->r17);
    // 0x8008CD64: lbu         $a0, -0x2732($at)
    ctx->r4 = MEM_BU(ctx->r1, -0X2732);
    // 0x8008CD68: and         $v1, $v1, $v0
    ctx->r3 = ctx->r3 & ctx->r2;
    // 0x8008CD6C: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x8008CD70: addu        $at, $at, $s1
    ctx->r1 = ADD32(ctx->r1, ctx->r17);
    // 0x8008CD74: sw          $v1, -0x275C($at)
    MEM_W(-0X275C, ctx->r1) = ctx->r3;
    // 0x8008CD78: beq         $a1, $s2, L_8008CD98
    if (ctx->r5 == ctx->r18) {
        // 0x8008CD7C: sll         $v0, $a1, 4
        ctx->r2 = S32(ctx->r5 << 4);
            goto L_8008CD98;
    }
    // 0x8008CD7C: sll         $v0, $a1, 4
    ctx->r2 = S32(ctx->r5 << 4);
    // 0x8008CD80: lui         $v1, 0x8015
    ctx->r3 = S32(0X8015 << 16);
    // 0x8008CD84: addiu       $v1, $v1, -0x7C30
    ctx->r3 = ADD32(ctx->r3, -0X7C30);
    // 0x8008CD88: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8008CD8C: addu        $v0, $a0, $v0
    ctx->r2 = ADD32(ctx->r4, ctx->r2);
    // 0x8008CD90: j           L_8008CE50
    // 0x8008CD94: sb          $zero, 0x0($v0)
    MEM_B(0X0, ctx->r2) = 0;
        goto L_8008CE50;
    // 0x8008CD94: sb          $zero, 0x0($v0)
    MEM_B(0X0, ctx->r2) = 0;
L_8008CD98:
    // 0x8008CD98: andi        $v0, $a0, 0xFF
    ctx->r2 = ctx->r4 & 0XFF;
    // 0x8008CD9C: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x8008CDA0: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x8008CDA4: sb          $zero, 0x2018($at)
    MEM_B(0X2018, ctx->r1) = 0;
    // 0x8008CDA8: j           L_8008CE50
    // 0x8008CDAC: nop

        goto L_8008CE50;
    // 0x8008CDAC: nop

L_8008CDB0:
    // 0x8008CDB0: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x8008CDB4: addu        $at, $at, $s1
    ctx->r1 = ADD32(ctx->r1, ctx->r17);
    // 0x8008CDB8: lw          $v0, -0x275C($at)
    ctx->r2 = MEM_W(ctx->r1, -0X275C);
    // 0x8008CDBC: andi        $v0, $v0, 0x800
    ctx->r2 = ctx->r2 & 0X800;
    // 0x8008CDC0: bne         $v0, $zero, L_8008CE34
    if (ctx->r2 != 0) {
        // 0x8008CDC4: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_8008CE34;
    }
    // 0x8008CDC4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8008CDC8: lbu         $v1, 0xA0($s0)
    ctx->r3 = MEM_BU(ctx->r16, 0XA0);
    // 0x8008CDCC: beql        $v1, $v0, L_8008CDDC
    if (ctx->r3 == ctx->r2) {
        // 0x8008CDD0: sw          $zero, 0x94($s0)
        MEM_W(0X94, ctx->r16) = 0;
            goto L_8008CDDC;
    }
    goto skip_3;
    // 0x8008CDD0: sw          $zero, 0x94($s0)
    MEM_W(0X94, ctx->r16) = 0;
    skip_3:
    // 0x8008CDD4: lw          $v0, 0x98($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X98);
    // 0x8008CDD8: sw          $v0, 0x94($s0)
    MEM_W(0X94, ctx->r16) = ctx->r2;
L_8008CDDC:
    // 0x8008CDDC: lbu         $a0, 0xBD($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0XBD);
    // 0x8008CDE0: lw          $a1, 0x60($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X60);
    // 0x8008CDE4: jal         0x80093E80
    // 0x8008CDE8: nop

    func_80093E80(rdram, ctx);
        goto after_3;
    // 0x8008CDE8: nop

    after_3:
    // 0x8008CDEC: lbu         $a0, 0x4E($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X4E);
    // 0x8008CDF0: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x8008CDF4: addiu       $v1, $zero, 0xFF
    ctx->r3 = ADD32(0, 0XFF);
    // 0x8008CDF8: beq         $a0, $v1, L_8008CE34
    if (ctx->r4 == ctx->r3) {
        // 0x8008CDFC: sw          $v0, 0x9C($s0)
        MEM_W(0X9C, ctx->r16) = ctx->r2;
            goto L_8008CE34;
    }
    // 0x8008CDFC: sw          $v0, 0x9C($s0)
    MEM_W(0X9C, ctx->r16) = ctx->r2;
    // 0x8008CE00: lbu         $v0, 0x4F($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X4F);
    // 0x8008CE04: beq         $v0, $v1, L_8008CE28
    if (ctx->r2 == ctx->r3) {
        // 0x8008CE08: addiu       $a1, $zero, 0x1
        ctx->r5 = ADD32(0, 0X1);
            goto L_8008CE28;
    }
    // 0x8008CE08: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8008CE0C: lui         $v1, 0x8015
    ctx->r3 = S32(0X8015 << 16);
    // 0x8008CE10: addiu       $v1, $v1, -0x7C30
    ctx->r3 = ADD32(ctx->r3, -0X7C30);
    // 0x8008CE14: sll         $v0, $v0, 4
    ctx->r2 = S32(ctx->r2 << 4);
    // 0x8008CE18: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8008CE1C: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x8008CE20: j           L_8008CE34
    // 0x8008CE24: sb          $a1, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r5;
        goto L_8008CE34;
    // 0x8008CE24: sb          $a1, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r5;
L_8008CE28:
    // 0x8008CE28: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x8008CE2C: addu        $at, $at, $a0
    ctx->r1 = ADD32(ctx->r1, ctx->r4);
    // 0x8008CE30: sb          $a1, 0x2018($at)
    MEM_B(0X2018, ctx->r1) = ctx->r5;
L_8008CE34:
    // 0x8008CE34: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x8008CE38: addu        $at, $at, $s1
    ctx->r1 = ADD32(ctx->r1, ctx->r17);
    // 0x8008CE3C: lw          $v0, -0x275C($at)
    ctx->r2 = MEM_W(ctx->r1, -0X275C);
    // 0x8008CE40: ori         $v0, $v0, 0x800
    ctx->r2 = ctx->r2 | 0X800;
    // 0x8008CE44: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x8008CE48: addu        $at, $at, $s1
    ctx->r1 = ADD32(ctx->r1, ctx->r17);
    // 0x8008CE4C: sw          $v0, -0x275C($at)
    MEM_W(-0X275C, ctx->r1) = ctx->r2;
L_8008CE50:
    // 0x8008CE50: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x8008CE54: addu        $at, $at, $s1
    ctx->r1 = ADD32(ctx->r1, ctx->r17);
    // 0x8008CE58: lw          $v1, -0x275C($at)
    ctx->r3 = MEM_W(ctx->r1, -0X275C);
L_8008CE5C:
    // 0x8008CE5C: andi        $v0, $v1, 0x20
    ctx->r2 = ctx->r3 & 0X20;
L_8008CE60:
    // 0x8008CE60: beq         $v0, $zero, L_8008CE98
    if (ctx->r2 == 0) {
        // 0x8008CE64: addiu       $v0, $zero, -0x21
        ctx->r2 = ADD32(0, -0X21);
            goto L_8008CE98;
    }
    // 0x8008CE64: addiu       $v0, $zero, -0x21
    ctx->r2 = ADD32(0, -0X21);
    // 0x8008CE68: and         $v0, $v1, $v0
    ctx->r2 = ctx->r3 & ctx->r2;
    // 0x8008CE6C: ori         $v0, $v0, 0x10
    ctx->r2 = ctx->r2 | 0X10;
    // 0x8008CE70: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x8008CE74: addu        $at, $at, $s1
    ctx->r1 = ADD32(ctx->r1, ctx->r17);
    // 0x8008CE78: sw          $v0, -0x275C($at)
    MEM_W(-0X275C, ctx->r1) = ctx->r2;
    // 0x8008CE7C: jal         0x8009231C
    // 0x8008CE80: addu        $a0, $s6, $zero
    ctx->r4 = ADD32(ctx->r22, 0);
    func_8009231C(rdram, ctx);
        goto after_4;
    // 0x8008CE80: addu        $a0, $s6, $zero
    ctx->r4 = ADD32(ctx->r22, 0);
    after_4:
    // 0x8008CE84: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x8008CE88: lw          $v0, -0x4FC4($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X4FC4);
    // 0x8008CE8C: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8008CE90: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x8008CE94: sw          $v0, -0x4FC4($at)
    MEM_W(-0X4FC4, ctx->r1) = ctx->r2;
L_8008CE98:
    // 0x8008CE98: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x8008CE9C: addu        $at, $at, $s1
    ctx->r1 = ADD32(ctx->r1, ctx->r17);
    // 0x8008CEA0: lw          $v1, -0x275C($at)
    ctx->r3 = MEM_W(ctx->r1, -0X275C);
    // 0x8008CEA4: andi        $v0, $v1, 0x80
    ctx->r2 = ctx->r3 & 0X80;
    // 0x8008CEA8: beq         $v0, $zero, L_8008CEF8
    if (ctx->r2 == 0) {
        // 0x8008CEAC: lui         $v0, 0x400
        ctx->r2 = S32(0X400 << 16);
            goto L_8008CEF8;
    }
    // 0x8008CEAC: lui         $v0, 0x400
    ctx->r2 = S32(0X400 << 16);
    // 0x8008CEB0: and         $v0, $v1, $v0
    ctx->r2 = ctx->r3 & ctx->r2;
    // 0x8008CEB4: bne         $v0, $zero, L_8008CEFC
    if (ctx->r2 != 0) {
        // 0x8008CEB8: lui         $v0, 0x4
        ctx->r2 = S32(0X4 << 16);
            goto L_8008CEFC;
    }
    // 0x8008CEB8: lui         $v0, 0x4
    ctx->r2 = S32(0X4 << 16);
    // 0x8008CEBC: addiu       $v0, $zero, -0x91
    ctx->r2 = ADD32(0, -0X91);
    // 0x8008CEC0: and         $v0, $v1, $v0
    ctx->r2 = ctx->r3 & ctx->r2;
    // 0x8008CEC4: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x8008CEC8: addu        $at, $at, $s1
    ctx->r1 = ADD32(ctx->r1, ctx->r17);
    // 0x8008CECC: sw          $v0, -0x275C($at)
    MEM_W(-0X275C, ctx->r1) = ctx->r2;
    // 0x8008CED0: jal         0x80092368
    // 0x8008CED4: addu        $a0, $s6, $zero
    ctx->r4 = ADD32(ctx->r22, 0);
    func_80092368(rdram, ctx);
        goto after_5;
    // 0x8008CED4: addu        $a0, $s6, $zero
    ctx->r4 = ADD32(ctx->r22, 0);
    after_5:
    // 0x8008CED8: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x8008CEDC: lw          $v0, -0x3BAC($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X3BAC);
    // 0x8008CEE0: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8008CEE4: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x8008CEE8: sw          $v0, -0x3BAC($at)
    MEM_W(-0X3BAC, ctx->r1) = ctx->r2;
    // 0x8008CEEC: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x8008CEF0: addu        $at, $at, $s1
    ctx->r1 = ADD32(ctx->r1, ctx->r17);
    // 0x8008CEF4: lw          $v1, -0x275C($at)
    ctx->r3 = MEM_W(ctx->r1, -0X275C);
L_8008CEF8:
    // 0x8008CEF8: lui         $v0, 0x4
    ctx->r2 = S32(0X4 << 16);
L_8008CEFC:
    // 0x8008CEFC: and         $v0, $v1, $v0
    ctx->r2 = ctx->r3 & ctx->r2;
    // 0x8008CF00: beq         $v0, $zero, L_8008CF24
    if (ctx->r2 == 0) {
        // 0x8008CF04: lui         $v0, 0xFFFB
        ctx->r2 = S32(0XFFFB << 16);
            goto L_8008CF24;
    }
    // 0x8008CF04: lui         $v0, 0xFFFB
    ctx->r2 = S32(0XFFFB << 16);
    // 0x8008CF08: ori         $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 | 0XFFFF;
    // 0x8008CF0C: and         $v0, $v1, $v0
    ctx->r2 = ctx->r3 & ctx->r2;
    // 0x8008CF10: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x8008CF14: addu        $at, $at, $s1
    ctx->r1 = ADD32(ctx->r1, ctx->r17);
    // 0x8008CF18: sw          $v0, -0x275C($at)
    MEM_W(-0X275C, ctx->r1) = ctx->r2;
    // 0x8008CF1C: jal         0x80092388
    // 0x8008CF20: addu        $a0, $s6, $zero
    ctx->r4 = ADD32(ctx->r22, 0);
    func_80092388(rdram, ctx);
        goto after_6;
    // 0x8008CF20: addu        $a0, $s6, $zero
    ctx->r4 = ADD32(ctx->r22, 0);
    after_6:
L_8008CF24:
    // 0x8008CF24: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x8008CF28: addu        $at, $at, $s1
    ctx->r1 = ADD32(ctx->r1, ctx->r17);
    // 0x8008CF2C: lw          $a0, -0x2758($at)
    ctx->r4 = MEM_W(ctx->r1, -0X2758);
    // 0x8008CF30: beq         $a0, $zero, L_8008CF64
    if (ctx->r4 == 0) {
        // 0x8008CF34: nop
    
            goto L_8008CF64;
    }
    // 0x8008CF34: nop

    // 0x8008CF38: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x8008CF3C: addu        $at, $at, $s1
    ctx->r1 = ADD32(ctx->r1, ctx->r17);
    // 0x8008CF40: lhu         $v0, -0x2754($at)
    ctx->r2 = MEM_HU(ctx->r1, -0X2754);
    // 0x8008CF44: lui         $v1, 0x8014
    ctx->r3 = S32(0X8014 << 16);
    // 0x8008CF48: lw          $v1, -0x5338($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X5338);
    // 0x8008CF4C: mult        $v0, $v1
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8008CF50: mflo        $v0
    ctx->r2 = lo;
    // 0x8008CF54: subu        $v0, $a0, $v0
    ctx->r2 = SUB32(ctx->r4, ctx->r2);
    // 0x8008CF58: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x8008CF5C: addu        $at, $at, $s1
    ctx->r1 = ADD32(ctx->r1, ctx->r17);
    // 0x8008CF60: sw          $v0, -0x2758($at)
    MEM_W(-0X2758, ctx->r1) = ctx->r2;
L_8008CF64:
    // 0x8008CF64: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x8008CF68: addu        $at, $at, $s1
    ctx->r1 = ADD32(ctx->r1, ctx->r17);
    // 0x8008CF6C: lw          $v0, -0x275C($at)
    ctx->r2 = MEM_W(ctx->r1, -0X275C);
    // 0x8008CF70: andi        $v0, $v0, 0x8000
    ctx->r2 = ctx->r2 & 0X8000;
    // 0x8008CF74: beq         $v0, $zero, L_8008D05C
    if (ctx->r2 == 0) {
        // 0x8008CF78: nop
    
            goto L_8008D05C;
    }
    // 0x8008CF78: nop

    // 0x8008CF7C: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x8008CF80: addu        $at, $at, $s1
    ctx->r1 = ADD32(ctx->r1, ctx->r17);
    // 0x8008CF84: lw          $v1, -0x26DC($at)
    ctx->r3 = MEM_W(ctx->r1, -0X26DC);
    // 0x8008CF88: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x8008CF8C: addu        $at, $at, $s1
    ctx->r1 = ADD32(ctx->r1, ctx->r17);
    // 0x8008CF90: lw          $v0, -0x2744($at)
    ctx->r2 = MEM_W(ctx->r1, -0X2744);
    // 0x8008CF94: srl         $v1, $v1, 8
    ctx->r3 = S32(U32(ctx->r3) >> 8);
    // 0x8008CF98: mult        $v1, $v0
    result = S64(S32(ctx->r3)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8008CF9C: mflo        $v1
    ctx->r3 = lo;
    // 0x8008CFA0: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x8008CFA4: addu        $at, $at, $s1
    ctx->r1 = ADD32(ctx->r1, ctx->r17);
    // 0x8008CFA8: lw          $v0, -0x26D8($at)
    ctx->r2 = MEM_W(ctx->r1, -0X26D8);
    // 0x8008CFAC: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x8008CFB0: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x8008CFB4: addu        $at, $at, $s1
    ctx->r1 = ADD32(ctx->r1, ctx->r17);
    // 0x8008CFB8: sw          $v0, -0x2748($at)
    MEM_W(-0X2748, ctx->r1) = ctx->r2;
    // 0x8008CFBC: bgez        $v0, L_8008CFD0
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8008CFC0: nop
    
            goto L_8008CFD0;
    }
    // 0x8008CFC0: nop

    // 0x8008CFC4: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x8008CFC8: addu        $at, $at, $s1
    ctx->r1 = ADD32(ctx->r1, ctx->r17);
    // 0x8008CFCC: sw          $zero, -0x2748($at)
    MEM_W(-0X2748, ctx->r1) = 0;
L_8008CFD0:
    // 0x8008CFD0: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x8008CFD4: addu        $at, $at, $s1
    ctx->r1 = ADD32(ctx->r1, ctx->r17);
    // 0x8008CFD8: lw          $v0, -0x2748($at)
    ctx->r2 = MEM_W(ctx->r1, -0X2748);
    // 0x8008CFDC: lui         $v1, 0x7F
    ctx->r3 = S32(0X7F << 16);
    // 0x8008CFE0: sltu        $v0, $v1, $v0
    ctx->r2 = ctx->r3 < ctx->r2 ? 1 : 0;
    // 0x8008CFE4: beq         $v0, $zero, L_8008CFF8
    if (ctx->r2 == 0) {
        // 0x8008CFE8: nop
    
            goto L_8008CFF8;
    }
    // 0x8008CFE8: nop

    // 0x8008CFEC: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x8008CFF0: addu        $at, $at, $s1
    ctx->r1 = ADD32(ctx->r1, ctx->r17);
    // 0x8008CFF4: sw          $v1, -0x2748($at)
    MEM_W(-0X2748, ctx->r1) = ctx->r3;
L_8008CFF8:
    // 0x8008CFF8: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x8008CFFC: addu        $at, $at, $s1
    ctx->r1 = ADD32(ctx->r1, ctx->r17);
    // 0x8008D000: lw          $v1, -0x26DC($at)
    ctx->r3 = MEM_W(ctx->r1, -0X26DC);
    // 0x8008D004: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x8008D008: lw          $v0, -0x5338($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X5338);
    // 0x8008D00C: subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // 0x8008D010: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x8008D014: addu        $at, $at, $s1
    ctx->r1 = ADD32(ctx->r1, ctx->r17);
    // 0x8008D018: sw          $v1, -0x26DC($at)
    MEM_W(-0X26DC, ctx->r1) = ctx->r3;
    // 0x8008D01C: bne         $v1, $zero, L_8008D05C
    if (ctx->r3 != 0) {
        // 0x8008D020: lui         $v0, 0xFFFF
        ctx->r2 = S32(0XFFFF << 16);
            goto L_8008D05C;
    }
    // 0x8008D020: lui         $v0, 0xFFFF
    ctx->r2 = S32(0XFFFF << 16);
    // 0x8008D024: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x8008D028: addu        $at, $at, $s1
    ctx->r1 = ADD32(ctx->r1, ctx->r17);
    // 0x8008D02C: lw          $v1, -0x275C($at)
    ctx->r3 = MEM_W(ctx->r1, -0X275C);
    // 0x8008D030: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x8008D034: addu        $at, $at, $s1
    ctx->r1 = ADD32(ctx->r1, ctx->r17);
    // 0x8008D038: lw          $a0, -0x26D8($at)
    ctx->r4 = MEM_W(ctx->r1, -0X26D8);
    // 0x8008D03C: ori         $v0, $v0, 0x7FFF
    ctx->r2 = ctx->r2 | 0X7FFF;
    // 0x8008D040: and         $v1, $v1, $v0
    ctx->r3 = ctx->r3 & ctx->r2;
    // 0x8008D044: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x8008D048: addu        $at, $at, $s1
    ctx->r1 = ADD32(ctx->r1, ctx->r17);
    // 0x8008D04C: sw          $v1, -0x275C($at)
    MEM_W(-0X275C, ctx->r1) = ctx->r3;
    // 0x8008D050: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x8008D054: addu        $at, $at, $s1
    ctx->r1 = ADD32(ctx->r1, ctx->r17);
    // 0x8008D058: sw          $a0, -0x2748($at)
    MEM_W(-0X2748, ctx->r1) = ctx->r4;
L_8008D05C:
    // 0x8008D05C: lw          $v0, 0x24($s5)
    ctx->r2 = MEM_W(ctx->r21, 0X24);
    // 0x8008D060: andi        $v0, $v0, 0x800
    ctx->r2 = ctx->r2 & 0X800;
    // 0x8008D064: beq         $v0, $zero, L_8008D0D4
    if (ctx->r2 == 0) {
        // 0x8008D068: nop
    
            goto L_8008D0D4;
    }
    // 0x8008D068: nop

    // 0x8008D06C: lw          $a2, 0x94($s5)
    ctx->r6 = MEM_W(ctx->r21, 0X94);
    // 0x8008D070: lw          $v1, 0x98($s5)
    ctx->r3 = MEM_W(ctx->r21, 0X98);
    // 0x8008D074: sltu        $v0, $a2, $v1
    ctx->r2 = ctx->r6 < ctx->r3 ? 1 : 0;
    // 0x8008D078: beq         $v0, $zero, L_8008D0D4
    if (ctx->r2 == 0) {
        // 0x8008D07C: sll         $a0, $a2, 8
        ctx->r4 = S32(ctx->r6 << 8);
            goto L_8008D0D4;
    }
    // 0x8008D07C: sll         $a0, $a2, 8
    ctx->r4 = S32(ctx->r6 << 8);
    // 0x8008D080: srl         $v0, $v1, 8
    ctx->r2 = S32(U32(ctx->r3) >> 8);
    // 0x8008D084: divu        $zero, $a0, $v0
    if (U32(ctx->r2) != 0) { lo = S32(U32(ctx->r4) / U32(ctx->r2)); hi = S32(U32(ctx->r4) % U32(ctx->r2)); } else { lo = 0; hi = S32(ctx->r4); }
    // 0x8008D088: bne         $v0, $zero, L_8008D094
    if (ctx->r2 != 0) {
        // 0x8008D08C: nop
    
            goto L_8008D094;
    }
    // 0x8008D08C: nop

    // 0x8008D090: break       7
    do_break(2148061328);
L_8008D094:
    // 0x8008D094: mflo        $a0
    ctx->r4 = lo;
    // 0x8008D098: lhu         $a1, 0x70($s5)
    ctx->r5 = MEM_HU(ctx->r21, 0X70);
    // 0x8008D09C: nop

    // 0x8008D0A0: mult        $a0, $a1
    result = S64(S32(ctx->r4)) * S64(S32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8008D0A4: mflo        $a1
    ctx->r5 = lo;
    // 0x8008D0A8: lhu         $v0, 0x9C($s5)
    ctx->r2 = MEM_HU(ctx->r21, 0X9C);
    // 0x8008D0AC: lui         $v1, 0x1
    ctx->r3 = S32(0X1 << 16);
    // 0x8008D0B0: subu        $v1, $v1, $a0
    ctx->r3 = SUB32(ctx->r3, ctx->r4);
    // 0x8008D0B4: mult        $v1, $v0
    result = S64(S32(ctx->r3)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8008D0B8: mflo        $v1
    ctx->r3 = lo;
    // 0x8008D0BC: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x8008D0C0: lw          $v0, -0x5338($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X5338);
    // 0x8008D0C4: addu        $v0, $a2, $v0
    ctx->r2 = ADD32(ctx->r6, ctx->r2);
    // 0x8008D0C8: sw          $v0, 0x94($s5)
    MEM_W(0X94, ctx->r21) = ctx->r2;
    // 0x8008D0CC: j           L_8008D0D8
    // 0x8008D0D0: addu        $v1, $a1, $v1
    ctx->r3 = ADD32(ctx->r5, ctx->r3);
        goto L_8008D0D8;
    // 0x8008D0D0: addu        $v1, $a1, $v1
    ctx->r3 = ADD32(ctx->r5, ctx->r3);
L_8008D0D4:
    // 0x8008D0D4: lw          $v1, 0x70($s5)
    ctx->r3 = MEM_W(ctx->r21, 0X70);
L_8008D0D8:
    // 0x8008D0D8: addu        $s2, $v1, $zero
    ctx->r18 = ADD32(ctx->r3, 0);
    // 0x8008D0DC: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x8008D0E0: addu        $at, $at, $s1
    ctx->r1 = ADD32(ctx->r1, ctx->r17);
    // 0x8008D0E4: lw          $v0, -0x275C($at)
    ctx->r2 = MEM_W(ctx->r1, -0X275C);
    // 0x8008D0E8: lui         $v1, 0x2
    ctx->r3 = S32(0X2 << 16);
    // 0x8008D0EC: ori         $v1, $v1, 0x10
    ctx->r3 = ctx->r3 | 0X10;
    // 0x8008D0F0: and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // 0x8008D0F4: beq         $v0, $zero, L_8008D12C
    if (ctx->r2 == 0) {
        // 0x8008D0F8: addiu       $v0, $zero, 0xFF
        ctx->r2 = ADD32(0, 0XFF);
            goto L_8008D12C;
    }
    // 0x8008D0F8: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // 0x8008D0FC: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x8008D100: addu        $at, $at, $s1
    ctx->r1 = ADD32(ctx->r1, ctx->r17);
    // 0x8008D104: lbu         $v1, -0x2732($at)
    ctx->r3 = MEM_BU(ctx->r1, -0X2732);
    // 0x8008D108: beq         $v1, $v0, L_8008D204
    if (ctx->r3 == ctx->r2) {
        // 0x8008D10C: addu        $a0, $s1, $fp
        ctx->r4 = ADD32(ctx->r17, ctx->r30);
            goto L_8008D204;
    }
    // 0x8008D10C: addu        $a0, $s1, $fp
    ctx->r4 = ADD32(ctx->r17, ctx->r30);
    // 0x8008D110: jal         0x80084860
    // 0x8008D114: addiu       $a1, $a0, 0xF6
    ctx->r5 = ADD32(ctx->r4, 0XF6);
    func_80084860(rdram, ctx);
        goto after_7;
    // 0x8008D114: addiu       $a1, $a0, 0xF6
    ctx->r5 = ADD32(ctx->r4, 0XF6);
    after_7:
    // 0x8008D118: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x8008D11C: addu        $at, $at, $s1
    ctx->r1 = ADD32(ctx->r1, ctx->r17);
    // 0x8008D120: sh          $v0, -0x26CC($at)
    MEM_H(-0X26CC, ctx->r1) = ctx->r2;
    // 0x8008D124: j           L_8008D138
    // 0x8008D128: andi        $a0, $v0, 0xFFFF
    ctx->r4 = ctx->r2 & 0XFFFF;
        goto L_8008D138;
    // 0x8008D128: andi        $a0, $v0, 0xFFFF
    ctx->r4 = ctx->r2 & 0XFFFF;
L_8008D12C:
    // 0x8008D12C: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x8008D130: addu        $at, $at, $s1
    ctx->r1 = ADD32(ctx->r1, ctx->r17);
    // 0x8008D134: lhu         $a0, -0x26CC($at)
    ctx->r4 = MEM_HU(ctx->r1, -0X26CC);
L_8008D138:
    // 0x8008D138: addiu       $v0, $zero, 0x2000
    ctx->r2 = ADD32(0, 0X2000);
    // 0x8008D13C: beq         $a0, $v0, L_8008D204
    if (ctx->r4 == ctx->r2) {
        // 0x8008D140: addiu       $a0, $a0, -0x2000
        ctx->r4 = ADD32(ctx->r4, -0X2000);
            goto L_8008D204;
    }
    // 0x8008D140: addiu       $a0, $a0, -0x2000
    ctx->r4 = ADD32(ctx->r4, -0X2000);
    // 0x8008D144: bgez        $a0, L_8008D19C
    if (SIGNED(ctx->r4) >= 0) {
        // 0x8008D148: addiu       $a1, $sp, 0x18
        ctx->r5 = ADD32(ctx->r29, 0X18);
            goto L_8008D19C;
    }
    // 0x8008D148: addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    // 0x8008D14C: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x8008D150: addu        $at, $at, $s1
    ctx->r1 = ADD32(ctx->r1, ctx->r17);
    // 0x8008D154: lbu         $v1, -0x2712($at)
    ctx->r3 = MEM_BU(ctx->r1, -0X2712);
    // 0x8008D158: negu        $v0, $a0
    ctx->r2 = SUB32(0, ctx->r4);
    // 0x8008D15C: mult        $v0, $v1
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8008D160: mflo        $a0
    ctx->r4 = lo;
    // 0x8008D164: addiu       $a2, $sp, 0x1C
    ctx->r6 = ADD32(ctx->r29, 0X1C);
    // 0x8008D168: srl         $a3, $s2, 16
    ctx->r7 = S32(U32(ctx->r18) >> 16);
    // 0x8008D16C: andi        $s0, $a0, 0x7F
    ctx->r16 = ctx->r4 & 0X7F;
    // 0x8008D170: sra         $a0, $a0, 7
    ctx->r4 = S32(SIGNED(ctx->r4) >> 7);
    // 0x8008D174: jal         0x8009405C
    // 0x8008D178: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    func_8009405C(rdram, ctx);
        goto after_8;
    // 0x8008D178: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    after_8:
    // 0x8008D17C: lw          $v1, 0x18($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X18);
    // 0x8008D180: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x8008D184: subu        $v0, $v1, $v0
    ctx->r2 = SUB32(ctx->r3, ctx->r2);
    // 0x8008D188: mult        $v0, $s0
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r16)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8008D18C: mflo        $v0
    ctx->r2 = lo;
    // 0x8008D190: srl         $v0, $v0, 7
    ctx->r2 = S32(U32(ctx->r2) >> 7);
    // 0x8008D194: j           L_8008D1E4
    // 0x8008D198: subu        $s2, $v1, $v0
    ctx->r18 = SUB32(ctx->r3, ctx->r2);
        goto L_8008D1E4;
    // 0x8008D198: subu        $s2, $v1, $v0
    ctx->r18 = SUB32(ctx->r3, ctx->r2);
L_8008D19C:
    // 0x8008D19C: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x8008D1A0: addu        $at, $at, $s1
    ctx->r1 = ADD32(ctx->r1, ctx->r17);
    // 0x8008D1A4: lbu         $v0, -0x2711($at)
    ctx->r2 = MEM_BU(ctx->r1, -0X2711);
    // 0x8008D1A8: mult        $a0, $v0
    result = S64(S32(ctx->r4)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8008D1AC: mflo        $a0
    ctx->r4 = lo;
    // 0x8008D1B0: addiu       $a2, $sp, 0x1C
    ctx->r6 = ADD32(ctx->r29, 0X1C);
    // 0x8008D1B4: srl         $a3, $s2, 16
    ctx->r7 = S32(U32(ctx->r18) >> 16);
    // 0x8008D1B8: andi        $s0, $a0, 0x7F
    ctx->r16 = ctx->r4 & 0X7F;
    // 0x8008D1BC: sra         $a0, $a0, 7
    ctx->r4 = S32(SIGNED(ctx->r4) >> 7);
    // 0x8008D1C0: jal         0x80093FE4
    // 0x8008D1C4: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    func_80093FE4(rdram, ctx);
        goto after_9;
    // 0x8008D1C4: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    after_9:
    // 0x8008D1C8: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x8008D1CC: lw          $v1, 0x18($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X18);
    // 0x8008D1D0: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x8008D1D4: mult        $v0, $s0
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r16)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8008D1D8: mflo        $v0
    ctx->r2 = lo;
    // 0x8008D1DC: srl         $v0, $v0, 7
    ctx->r2 = S32(U32(ctx->r2) >> 7);
    // 0x8008D1E0: addu        $s2, $v1, $v0
    ctx->r18 = ADD32(ctx->r3, ctx->r2);
L_8008D1E4:
    // 0x8008D1E4: bgez        $s2, L_8008D1F4
    if (SIGNED(ctx->r18) >= 0) {
        // 0x8008D1E8: ori         $v0, $zero, 0xFFFF
        ctx->r2 = 0 | 0XFFFF;
            goto L_8008D1F4;
    }
    // 0x8008D1E8: ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
    // 0x8008D1EC: j           L_8008D204
    // 0x8008D1F0: addu        $s2, $zero, $zero
    ctx->r18 = ADD32(0, 0);
        goto L_8008D204;
    // 0x8008D1F0: addu        $s2, $zero, $zero
    ctx->r18 = ADD32(0, 0);
L_8008D1F4:
    // 0x8008D1F4: sltu        $v0, $v0, $s2
    ctx->r2 = ctx->r2 < ctx->r18 ? 1 : 0;
    // 0x8008D1F8: beq         $v0, $zero, L_8008D204
    if (ctx->r2 == 0) {
        // 0x8008D1FC: sll         $s2, $s2, 16
        ctx->r18 = S32(ctx->r18 << 16);
            goto L_8008D204;
    }
    // 0x8008D1FC: sll         $s2, $s2, 16
    ctx->r18 = S32(ctx->r18 << 16);
    // 0x8008D200: lui         $s2, 0xFFFF
    ctx->r18 = S32(0XFFFF << 16);
L_8008D204:
    // 0x8008D204: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x8008D208: addu        $at, $at, $s1
    ctx->r1 = ADD32(ctx->r1, ctx->r17);
    // 0x8008D20C: lw          $v0, -0x275C($at)
    ctx->r2 = MEM_W(ctx->r1, -0X275C);
    // 0x8008D210: andi        $v0, $v0, 0x2000
    ctx->r2 = ctx->r2 & 0X2000;
    // 0x8008D214: beq         $v0, $zero, L_8008D3C4
    if (ctx->r2 == 0) {
        // 0x8008D218: nop
    
            goto L_8008D3C4;
    }
    // 0x8008D218: nop

    // 0x8008D21C: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x8008D220: addu        $at, $at, $s1
    ctx->r1 = ADD32(ctx->r1, ctx->r17);
    // 0x8008D224: lw          $v0, -0x2704($at)
    ctx->r2 = MEM_W(ctx->r1, -0X2704);
    // 0x8008D228: bgez        $v0, L_8008D2B0
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8008D22C: srl         $s3, $s2, 16
        ctx->r19 = S32(U32(ctx->r18) >> 16);
            goto L_8008D2B0;
    }
    // 0x8008D22C: srl         $s3, $s2, 16
    ctx->r19 = S32(U32(ctx->r18) >> 16);
    // 0x8008D230: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x8008D234: addu        $at, $at, $s1
    ctx->r1 = ADD32(ctx->r1, ctx->r17);
    // 0x8008D238: lbu         $a1, -0x2700($at)
    ctx->r5 = MEM_BU(ctx->r1, -0X2700);
    // 0x8008D23C: jal         0x80093FB4
    // 0x8008D240: addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    func_80093FB4(rdram, ctx);
        goto after_10;
    // 0x8008D240: addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    after_10:
    // 0x8008D244: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x8008D248: addu        $at, $at, $s1
    ctx->r1 = ADD32(ctx->r1, ctx->r17);
    // 0x8008D24C: lbu         $v1, -0x26FF($at)
    ctx->r3 = MEM_BU(ctx->r1, -0X26FF);
    // 0x8008D250: beq         $v1, $zero, L_8008D29C
    if (ctx->r3 == 0) {
        // 0x8008D254: andi        $s0, $v0, 0xFFFF
        ctx->r16 = ctx->r2 & 0XFFFF;
            goto L_8008D29C;
    }
    // 0x8008D254: andi        $s0, $v0, 0xFFFF
    ctx->r16 = ctx->r2 & 0XFFFF;
    // 0x8008D258: jal         0x80093F60
    // 0x8008D25C: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_80093F60(rdram, ctx);
        goto after_11;
    // 0x8008D25C: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_11:
    // 0x8008D260: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x8008D264: addu        $at, $at, $s1
    ctx->r1 = ADD32(ctx->r1, ctx->r17);
    // 0x8008D268: lbu         $v1, -0x26FF($at)
    ctx->r3 = MEM_BU(ctx->r1, -0X26FF);
    // 0x8008D26C: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x8008D270: subu        $v0, $s0, $v0
    ctx->r2 = SUB32(ctx->r16, ctx->r2);
    // 0x8008D274: mult        $v0, $v1
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8008D278: mflo        $v0
    ctx->r2 = lo;
    // 0x8008D27C: lui         $v1, 0x51EB
    ctx->r3 = S32(0X51EB << 16);
    // 0x8008D280: ori         $v1, $v1, 0x851F
    ctx->r3 = ctx->r3 | 0X851F;
    // 0x8008D284: mult        $v0, $v1
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8008D288: sra         $v0, $v0, 31
    ctx->r2 = S32(SIGNED(ctx->r2) >> 31);
    // 0x8008D28C: mfhi        $t1
    ctx->r9 = hi;
    // 0x8008D290: sra         $v1, $t1, 5
    ctx->r3 = S32(SIGNED(ctx->r9) >> 5);
    // 0x8008D294: subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // 0x8008D298: subu        $s0, $s0, $v1
    ctx->r16 = SUB32(ctx->r16, ctx->r3);
L_8008D29C:
    // 0x8008D29C: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x8008D2A0: addu        $at, $at, $s1
    ctx->r1 = ADD32(ctx->r1, ctx->r17);
    // 0x8008D2A4: lw          $v0, -0x2704($at)
    ctx->r2 = MEM_W(ctx->r1, -0X2704);
    // 0x8008D2A8: j           L_8008D32C
    // 0x8008D2AC: subu        $v1, $s3, $s0
    ctx->r3 = SUB32(ctx->r19, ctx->r16);
        goto L_8008D32C;
    // 0x8008D2AC: subu        $v1, $s3, $s0
    ctx->r3 = SUB32(ctx->r19, ctx->r16);
L_8008D2B0:
    // 0x8008D2B0: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x8008D2B4: addu        $at, $at, $s1
    ctx->r1 = ADD32(ctx->r1, ctx->r17);
    // 0x8008D2B8: lbu         $a1, -0x2700($at)
    ctx->r5 = MEM_BU(ctx->r1, -0X2700);
    // 0x8008D2BC: jal         0x80093F84
    // 0x8008D2C0: addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    func_80093F84(rdram, ctx);
        goto after_12;
    // 0x8008D2C0: addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    after_12:
    // 0x8008D2C4: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x8008D2C8: addu        $at, $at, $s1
    ctx->r1 = ADD32(ctx->r1, ctx->r17);
    // 0x8008D2CC: lbu         $v1, -0x26FF($at)
    ctx->r3 = MEM_BU(ctx->r1, -0X26FF);
    // 0x8008D2D0: beq         $v1, $zero, L_8008D31C
    if (ctx->r3 == 0) {
        // 0x8008D2D4: andi        $s0, $v0, 0xFFFF
        ctx->r16 = ctx->r2 & 0XFFFF;
            goto L_8008D31C;
    }
    // 0x8008D2D4: andi        $s0, $v0, 0xFFFF
    ctx->r16 = ctx->r2 & 0XFFFF;
    // 0x8008D2D8: jal         0x80093F3C
    // 0x8008D2DC: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_80093F3C(rdram, ctx);
        goto after_13;
    // 0x8008D2DC: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_13:
    // 0x8008D2E0: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x8008D2E4: addu        $at, $at, $s1
    ctx->r1 = ADD32(ctx->r1, ctx->r17);
    // 0x8008D2E8: lbu         $v1, -0x26FF($at)
    ctx->r3 = MEM_BU(ctx->r1, -0X26FF);
    // 0x8008D2EC: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x8008D2F0: subu        $v0, $v0, $s0
    ctx->r2 = SUB32(ctx->r2, ctx->r16);
    // 0x8008D2F4: mult        $v0, $v1
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8008D2F8: mflo        $v0
    ctx->r2 = lo;
    // 0x8008D2FC: lui         $v1, 0x51EB
    ctx->r3 = S32(0X51EB << 16);
    // 0x8008D300: ori         $v1, $v1, 0x851F
    ctx->r3 = ctx->r3 | 0X851F;
    // 0x8008D304: mult        $v0, $v1
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8008D308: sra         $v0, $v0, 31
    ctx->r2 = S32(SIGNED(ctx->r2) >> 31);
    // 0x8008D30C: mfhi        $t1
    ctx->r9 = hi;
    // 0x8008D310: sra         $v1, $t1, 5
    ctx->r3 = S32(SIGNED(ctx->r9) >> 5);
    // 0x8008D314: subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // 0x8008D318: addu        $s0, $s0, $v1
    ctx->r16 = ADD32(ctx->r16, ctx->r3);
L_8008D31C:
    // 0x8008D31C: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x8008D320: addu        $at, $at, $s1
    ctx->r1 = ADD32(ctx->r1, ctx->r17);
    // 0x8008D324: lw          $v0, -0x2704($at)
    ctx->r2 = MEM_W(ctx->r1, -0X2704);
    // 0x8008D328: subu        $v1, $s0, $s3
    ctx->r3 = SUB32(ctx->r16, ctx->r19);
L_8008D32C:
    // 0x8008D32C: mult        $v0, $v1
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8008D330: mflo        $v0
    ctx->r2 = lo;
    // 0x8008D334: sra         $s0, $v0, 12
    ctx->r16 = S32(SIGNED(ctx->r2) >> 12);
    // 0x8008D338: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x8008D33C: addu        $at, $at, $s1
    ctx->r1 = ADD32(ctx->r1, ctx->r17);
    // 0x8008D340: lw          $v0, -0x275C($at)
    ctx->r2 = MEM_W(ctx->r1, -0X275C);
    // 0x8008D344: andi        $v0, $v0, 0x4000
    ctx->r2 = ctx->r2 & 0X4000;
    // 0x8008D348: beq         $v0, $zero, L_8008D378
    if (ctx->r2 == 0) {
        // 0x8008D34C: addiu       $v0, $zero, 0xFF
        ctx->r2 = ADD32(0, 0XFF);
            goto L_8008D378;
    }
    // 0x8008D34C: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // 0x8008D350: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x8008D354: addu        $at, $at, $s1
    ctx->r1 = ADD32(ctx->r1, ctx->r17);
    // 0x8008D358: lbu         $v1, -0x2732($at)
    ctx->r3 = MEM_BU(ctx->r1, -0X2732);
    // 0x8008D35C: beq         $v1, $v0, L_8008D378
    if (ctx->r3 == ctx->r2) {
        // 0x8008D360: addu        $a0, $s1, $fp
        ctx->r4 = ADD32(ctx->r17, ctx->r30);
            goto L_8008D378;
    }
    // 0x8008D360: addu        $a0, $s1, $fp
    ctx->r4 = ADD32(ctx->r17, ctx->r30);
    // 0x8008D364: jal         0x80084860
    // 0x8008D368: addiu       $a1, $a0, 0x11A
    ctx->r5 = ADD32(ctx->r4, 0X11A);
    func_80084860(rdram, ctx);
        goto after_14;
    // 0x8008D368: addiu       $a1, $a0, 0x11A
    ctx->r5 = ADD32(ctx->r4, 0X11A);
    after_14:
    // 0x8008D36C: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x8008D370: j           L_8008D37C
    // 0x8008D374: srl         $a0, $v0, 7
    ctx->r4 = S32(U32(ctx->r2) >> 7);
        goto L_8008D37C;
    // 0x8008D374: srl         $a0, $v0, 7
    ctx->r4 = S32(U32(ctx->r2) >> 7);
L_8008D378:
    // 0x8008D378: addiu       $a0, $zero, 0x40
    ctx->r4 = ADD32(0, 0X40);
L_8008D37C:
    // 0x8008D37C: sra         $v0, $s0, 6
    ctx->r2 = S32(SIGNED(ctx->r16) >> 6);
    // 0x8008D380: mult        $v0, $a0
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8008D384: mflo        $v0
    ctx->r2 = lo;
    // 0x8008D388: srl         $v1, $s2, 16
    ctx->r3 = S32(U32(ctx->r18) >> 16);
    // 0x8008D38C: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x8008D390: addiu       $v0, $zero, 0x7FFF
    ctx->r2 = ADD32(0, 0X7FFF);
    // 0x8008D394: slt         $v0, $v0, $v1
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8008D398: beq         $v0, $zero, L_8008D3A8
    if (ctx->r2 == 0) {
        // 0x8008D39C: nop
    
            goto L_8008D3A8;
    }
    // 0x8008D39C: nop

    // 0x8008D3A0: j           L_8008D3C4
    // 0x8008D3A4: lui         $s2, 0x7FFF
    ctx->r18 = S32(0X7FFF << 16);
        goto L_8008D3C4;
    // 0x8008D3A4: lui         $s2, 0x7FFF
    ctx->r18 = S32(0X7FFF << 16);
L_8008D3A8:
    // 0x8008D3A8: bltz        $v1, L_8008D3C0
    if (SIGNED(ctx->r3) < 0) {
        // 0x8008D3AC: sll         $v0, $s0, 10
        ctx->r2 = S32(ctx->r16 << 10);
            goto L_8008D3C0;
    }
    // 0x8008D3AC: sll         $v0, $s0, 10
    ctx->r2 = S32(ctx->r16 << 10);
    // 0x8008D3B0: mult        $v0, $a0
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8008D3B4: mflo        $v0
    ctx->r2 = lo;
    // 0x8008D3B8: j           L_8008D3C4
    // 0x8008D3BC: addu        $s2, $s2, $v0
    ctx->r18 = ADD32(ctx->r18, ctx->r2);
        goto L_8008D3C4;
    // 0x8008D3BC: addu        $s2, $s2, $v0
    ctx->r18 = ADD32(ctx->r18, ctx->r2);
L_8008D3C0:
    // 0x8008D3C0: addu        $s2, $zero, $zero
    ctx->r18 = ADD32(0, 0);
L_8008D3C4:
    // 0x8008D3C4: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x8008D3C8: addu        $at, $at, $s1
    ctx->r1 = ADD32(ctx->r1, ctx->r17);
    // 0x8008D3CC: lw          $v1, -0x273C($at)
    ctx->r3 = MEM_W(ctx->r1, -0X273C);
    // 0x8008D3D0: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x8008D3D4: addu        $at, $at, $s1
    ctx->r1 = ADD32(ctx->r1, ctx->r17);
    // 0x8008D3D8: lw          $v0, -0x2738($at)
    ctx->r2 = MEM_W(ctx->r1, -0X2738);
    // 0x8008D3DC: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x8008D3E0: addu        $at, $at, $s1
    ctx->r1 = ADD32(ctx->r1, ctx->r17);
    // 0x8008D3E4: lbu         $a0, -0x2732($at)
    ctx->r4 = MEM_BU(ctx->r1, -0X2732);
    // 0x8008D3E8: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x8008D3EC: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // 0x8008D3F0: beq         $a0, $v0, L_8008D41C
    if (ctx->r4 == ctx->r2) {
        // 0x8008D3F4: addu        $s2, $s2, $v1
        ctx->r18 = ADD32(ctx->r18, ctx->r3);
            goto L_8008D41C;
    }
    // 0x8008D3F4: addu        $s2, $s2, $v1
    ctx->r18 = ADD32(ctx->r18, ctx->r3);
    // 0x8008D3F8: addu        $a0, $s1, $fp
    ctx->r4 = ADD32(ctx->r17, ctx->r30);
    // 0x8008D3FC: jal         0x80084860
    // 0x8008D400: addiu       $a1, $a0, 0x108
    ctx->r5 = ADD32(ctx->r4, 0X108);
    func_80084860(rdram, ctx);
        goto after_15;
    // 0x8008D400: addiu       $a1, $a0, 0x108
    ctx->r5 = ADD32(ctx->r4, 0X108);
    after_15:
    // 0x8008D404: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x8008D408: srl         $v1, $s2, 16
    ctx->r3 = S32(U32(ctx->r18) >> 16);
    // 0x8008D40C: mult        $v1, $v0
    result = S64(S32(ctx->r3)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8008D410: mflo        $v1
    ctx->r3 = lo;
    // 0x8008D414: j           L_8008D420
    // 0x8008D418: srl         $s2, $v1, 13
    ctx->r18 = S32(U32(ctx->r3) >> 13);
        goto L_8008D420;
    // 0x8008D418: srl         $s2, $v1, 13
    ctx->r18 = S32(U32(ctx->r3) >> 13);
L_8008D41C:
    // 0x8008D41C: srl         $s2, $s2, 16
    ctx->r18 = S32(U32(ctx->r18) >> 16);
L_8008D420:
    // 0x8008D420: addu        $a0, $s6, $zero
    ctx->r4 = ADD32(ctx->r22, 0);
    // 0x8008D424: jal         0x80092390
    // 0x8008D428: andi        $a1, $s2, 0xFFFF
    ctx->r5 = ctx->r18 & 0XFFFF;
    func_80092390(rdram, ctx);
        goto after_16;
    // 0x8008D428: andi        $a1, $s2, 0xFFFF
    ctx->r5 = ctx->r18 & 0XFFFF;
    after_16:
    // 0x8008D42C: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x8008D430: addu        $at, $at, $s1
    ctx->r1 = ADD32(ctx->r1, ctx->r17);
    // 0x8008D434: lw          $v0, -0x275C($at)
    ctx->r2 = MEM_W(ctx->r1, -0X275C);
    // 0x8008D438: lui         $v1, 0x1
    ctx->r3 = S32(0X1 << 16);
    // 0x8008D43C: and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // 0x8008D440: beq         $v0, $zero, L_8008D528
    if (ctx->r2 == 0) {
        // 0x8008D444: nop
    
            goto L_8008D528;
    }
    // 0x8008D444: nop

    // 0x8008D448: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x8008D44C: addu        $at, $at, $s1
    ctx->r1 = ADD32(ctx->r1, ctx->r17);
    // 0x8008D450: lw          $v1, -0x26D0($at)
    ctx->r3 = MEM_W(ctx->r1, -0X26D0);
    // 0x8008D454: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x8008D458: addu        $at, $at, $s1
    ctx->r1 = ADD32(ctx->r1, ctx->r17);
    // 0x8008D45C: lw          $v0, -0x26F4($at)
    ctx->r2 = MEM_W(ctx->r1, -0X26F4);
    // 0x8008D460: srl         $v1, $v1, 8
    ctx->r3 = S32(U32(ctx->r3) >> 8);
    // 0x8008D464: mult        $v1, $v0
    result = S64(S32(ctx->r3)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8008D468: mflo        $v1
    ctx->r3 = lo;
    // 0x8008D46C: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x8008D470: addu        $at, $at, $s1
    ctx->r1 = ADD32(ctx->r1, ctx->r17);
    // 0x8008D474: lw          $v0, -0x26F0($at)
    ctx->r2 = MEM_W(ctx->r1, -0X26F0);
    // 0x8008D478: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x8008D47C: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x8008D480: addu        $at, $at, $s1
    ctx->r1 = ADD32(ctx->r1, ctx->r17);
    // 0x8008D484: sw          $v0, -0x2750($at)
    MEM_W(-0X2750, ctx->r1) = ctx->r2;
    // 0x8008D488: bgez        $v0, L_8008D49C
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8008D48C: nop
    
            goto L_8008D49C;
    }
    // 0x8008D48C: nop

    // 0x8008D490: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x8008D494: addu        $at, $at, $s1
    ctx->r1 = ADD32(ctx->r1, ctx->r17);
    // 0x8008D498: sw          $zero, -0x2750($at)
    MEM_W(-0X2750, ctx->r1) = 0;
L_8008D49C:
    // 0x8008D49C: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x8008D4A0: addu        $at, $at, $s1
    ctx->r1 = ADD32(ctx->r1, ctx->r17);
    // 0x8008D4A4: lw          $v0, -0x2750($at)
    ctx->r2 = MEM_W(ctx->r1, -0X2750);
    // 0x8008D4A8: lui         $v1, 0x7F
    ctx->r3 = S32(0X7F << 16);
    // 0x8008D4AC: slt         $v0, $v1, $v0
    ctx->r2 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8008D4B0: beq         $v0, $zero, L_8008D4C4
    if (ctx->r2 == 0) {
        // 0x8008D4B4: nop
    
            goto L_8008D4C4;
    }
    // 0x8008D4B4: nop

    // 0x8008D4B8: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x8008D4BC: addu        $at, $at, $s1
    ctx->r1 = ADD32(ctx->r1, ctx->r17);
    // 0x8008D4C0: sw          $v1, -0x2750($at)
    MEM_W(-0X2750, ctx->r1) = ctx->r3;
L_8008D4C4:
    // 0x8008D4C4: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x8008D4C8: addu        $at, $at, $s1
    ctx->r1 = ADD32(ctx->r1, ctx->r17);
    // 0x8008D4CC: lw          $v1, -0x26D0($at)
    ctx->r3 = MEM_W(ctx->r1, -0X26D0);
    // 0x8008D4D0: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x8008D4D4: lw          $v0, -0x5338($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X5338);
    // 0x8008D4D8: subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // 0x8008D4DC: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x8008D4E0: addu        $at, $at, $s1
    ctx->r1 = ADD32(ctx->r1, ctx->r17);
    // 0x8008D4E4: sw          $v1, -0x26D0($at)
    MEM_W(-0X26D0, ctx->r1) = ctx->r3;
    // 0x8008D4E8: bgtz        $v1, L_8008D528
    if (SIGNED(ctx->r3) > 0) {
        // 0x8008D4EC: lui         $v0, 0xFFFE
        ctx->r2 = S32(0XFFFE << 16);
            goto L_8008D528;
    }
    // 0x8008D4EC: lui         $v0, 0xFFFE
    ctx->r2 = S32(0XFFFE << 16);
    // 0x8008D4F0: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x8008D4F4: addu        $at, $at, $s1
    ctx->r1 = ADD32(ctx->r1, ctx->r17);
    // 0x8008D4F8: lw          $v1, -0x275C($at)
    ctx->r3 = MEM_W(ctx->r1, -0X275C);
    // 0x8008D4FC: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x8008D500: addu        $at, $at, $s1
    ctx->r1 = ADD32(ctx->r1, ctx->r17);
    // 0x8008D504: lw          $a0, -0x26F0($at)
    ctx->r4 = MEM_W(ctx->r1, -0X26F0);
    // 0x8008D508: ori         $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 | 0XFFFF;
    // 0x8008D50C: and         $v1, $v1, $v0
    ctx->r3 = ctx->r3 & ctx->r2;
    // 0x8008D510: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x8008D514: addu        $at, $at, $s1
    ctx->r1 = ADD32(ctx->r1, ctx->r17);
    // 0x8008D518: sw          $v1, -0x275C($at)
    MEM_W(-0X275C, ctx->r1) = ctx->r3;
    // 0x8008D51C: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x8008D520: addu        $at, $at, $s1
    ctx->r1 = ADD32(ctx->r1, ctx->r17);
    // 0x8008D524: sw          $a0, -0x2750($at)
    MEM_W(-0X2750, ctx->r1) = ctx->r4;
L_8008D528:
    // 0x8008D528: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x8008D52C: addu        $at, $at, $s1
    ctx->r1 = ADD32(ctx->r1, ctx->r17);
    // 0x8008D530: lbu         $v0, -0x26C6($at)
    ctx->r2 = MEM_BU(ctx->r1, -0X26C6);
    // 0x8008D534: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x8008D538: addu        $at, $at, $s1
    ctx->r1 = ADD32(ctx->r1, ctx->r17);
    // 0x8008D53C: lw          $s2, -0x2750($at)
    ctx->r18 = MEM_W(ctx->r1, -0X2750);
    // 0x8008D540: sll         $v1, $v0, 2
    ctx->r3 = S32(ctx->r2 << 2);
    // 0x8008D544: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x8008D548: sll         $v1, $v1, 3
    ctx->r3 = S32(ctx->r3 << 3);
    // 0x8008D54C: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x8008D550: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x8008D554: lh          $a0, 0x1B30($at)
    ctx->r4 = MEM_H(ctx->r1, 0X1B30);
    // 0x8008D558: sra         $v0, $s2, 7
    ctx->r2 = S32(SIGNED(ctx->r18) >> 7);
    // 0x8008D55C: mult        $v0, $a0
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8008D560: mflo        $s2
    ctx->r18 = lo;
    // 0x8008D564: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x8008D568: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x8008D56C: lh          $v1, 0x1B18($at)
    ctx->r3 = MEM_H(ctx->r1, 0X1B18);
    // 0x8008D570: sra         $v0, $s2, 7
    ctx->r2 = S32(SIGNED(ctx->r18) >> 7);
    // 0x8008D574: mult        $v0, $v1
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8008D578: mflo        $s2
    ctx->r18 = lo;
    // 0x8008D57C: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x8008D580: addu        $at, $at, $s1
    ctx->r1 = ADD32(ctx->r1, ctx->r17);
    // 0x8008D584: lw          $s3, -0x2748($at)
    ctx->r19 = MEM_W(ctx->r1, -0X2748);
    // 0x8008D588: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x8008D58C: addu        $at, $at, $s1
    ctx->r1 = ADD32(ctx->r1, ctx->r17);
    // 0x8008D590: lbu         $s4, -0x2732($at)
    ctx->r20 = MEM_BU(ctx->r1, -0X2732);
    // 0x8008D594: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x8008D598: addu        $at, $at, $s1
    ctx->r1 = ADD32(ctx->r1, ctx->r17);
    // 0x8008D59C: lbu         $v0, -0x2730($at)
    ctx->r2 = MEM_BU(ctx->r1, -0X2730);
    // 0x8008D5A0: addiu       $a0, $zero, 0x348
    ctx->r4 = ADD32(0, 0X348);
    // 0x8008D5A4: beq         $v0, $zero, L_8008D5B0
    if (ctx->r2 == 0) {
        // 0x8008D5A8: sra         $v1, $s2, 7
        ctx->r3 = S32(SIGNED(ctx->r18) >> 7);
            goto L_8008D5B0;
    }
    // 0x8008D5A8: sra         $v1, $s2, 7
    ctx->r3 = S32(SIGNED(ctx->r18) >> 7);
    // 0x8008D5AC: addiu       $a0, $zero, 0x370
    ctx->r4 = ADD32(0, 0X370);
L_8008D5B0:
    // 0x8008D5B0: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x8008D5B4: addu        $at, $at, $a0
    ctx->r1 = ADD32(ctx->r1, ctx->r4);
    // 0x8008D5B8: lh          $v0, 0x1B18($at)
    ctx->r2 = MEM_H(ctx->r1, 0X1B18);
    // 0x8008D5BC: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x8008D5C0: addu        $at, $at, $s1
    ctx->r1 = ADD32(ctx->r1, ctx->r17);
    // 0x8008D5C4: lbu         $a0, -0x2751($at)
    ctx->r4 = MEM_BU(ctx->r1, -0X2751);
    // 0x8008D5C8: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x8008D5CC: mult        $v1, $v0
    result = S64(S32(ctx->r3)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8008D5D0: mflo        $s2
    ctx->r18 = lo;
    // 0x8008D5D4: beq         $a0, $a1, L_8008D5F0
    if (ctx->r4 == ctx->r5) {
        // 0x8008D5D8: sra         $v0, $s2, 7
        ctx->r2 = S32(SIGNED(ctx->r18) >> 7);
            goto L_8008D5F0;
    }
    // 0x8008D5D8: sra         $v0, $s2, 7
    ctx->r2 = S32(SIGNED(ctx->r18) >> 7);
    // 0x8008D5DC: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x8008D5E0: addu        $at, $at, $a0
    ctx->r1 = ADD32(ctx->r1, ctx->r4);
    // 0x8008D5E4: lbu         $v1, 0x1AD8($at)
    ctx->r3 = MEM_BU(ctx->r1, 0X1AD8);
    // 0x8008D5E8: mult        $v0, $v1
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8008D5EC: mflo        $s2
    ctx->r18 = lo;
L_8008D5F0:
    // 0x8008D5F0: beq         $s4, $a1, L_8008D690
    if (ctx->r20 == ctx->r5) {
        // 0x8008D5F4: addu        $s0, $s1, $fp
        ctx->r16 = ADD32(ctx->r17, ctx->r30);
            goto L_8008D690;
    }
    // 0x8008D5F4: addu        $s0, $s1, $fp
    ctx->r16 = ADD32(ctx->r17, ctx->r30);
    // 0x8008D5F8: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x8008D5FC: jal         0x80084860
    // 0x8008D600: addiu       $a1, $s0, 0xC0
    ctx->r5 = ADD32(ctx->r16, 0XC0);
    func_80084860(rdram, ctx);
        goto after_17;
    // 0x8008D600: addiu       $a1, $s0, 0xC0
    ctx->r5 = ADD32(ctx->r16, 0XC0);
    after_17:
    // 0x8008D604: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x8008D608: sra         $v1, $s2, 7
    ctx->r3 = S32(SIGNED(ctx->r18) >> 7);
    // 0x8008D60C: srl         $v0, $v0, 7
    ctx->r2 = S32(U32(ctx->r2) >> 7);
    // 0x8008D610: mult        $v1, $v0
    result = S64(S32(ctx->r3)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8008D614: mflo        $s2
    ctx->r18 = lo;
    // 0x8008D618: lui         $v0, 0x80
    ctx->r2 = S32(0X80 << 16);
    // 0x8008D61C: beq         $s3, $v0, L_8008D664
    if (ctx->r19 == ctx->r2) {
        // 0x8008D620: addu        $a0, $s0, $zero
        ctx->r4 = ADD32(ctx->r16, 0);
            goto L_8008D664;
    }
    // 0x8008D620: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x8008D624: jal         0x80084860
    // 0x8008D628: addiu       $a1, $a0, 0xD2
    ctx->r5 = ADD32(ctx->r4, 0XD2);
    func_80084860(rdram, ctx);
        goto after_18;
    // 0x8008D628: addiu       $a1, $a0, 0xD2
    ctx->r5 = ADD32(ctx->r4, 0XD2);
    after_18:
    // 0x8008D62C: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x8008D630: srl         $v0, $v0, 7
    ctx->r2 = S32(U32(ctx->r2) >> 7);
    // 0x8008D634: addiu       $v0, $v0, -0x40
    ctx->r2 = ADD32(ctx->r2, -0X40);
    // 0x8008D638: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x8008D63C: addu        $s3, $s3, $v0
    ctx->r19 = ADD32(ctx->r19, ctx->r2);
    // 0x8008D640: bltz        $s3, L_8008D65C
    if (SIGNED(ctx->r19) < 0) {
        // 0x8008D644: lui         $v0, 0x7F
        ctx->r2 = S32(0X7F << 16);
            goto L_8008D65C;
    }
    // 0x8008D644: lui         $v0, 0x7F
    ctx->r2 = S32(0X7F << 16);
    // 0x8008D648: slt         $v0, $v0, $s3
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r19) ? 1 : 0;
    // 0x8008D64C: bne         $v0, $zero, L_8008D660
    if (ctx->r2 != 0) {
        // 0x8008D650: lui         $v1, 0x7F
        ctx->r3 = S32(0X7F << 16);
            goto L_8008D660;
    }
    // 0x8008D650: lui         $v1, 0x7F
    ctx->r3 = S32(0X7F << 16);
    // 0x8008D654: j           L_8008D660
    // 0x8008D658: addu        $v1, $s3, $zero
    ctx->r3 = ADD32(ctx->r19, 0);
        goto L_8008D660;
    // 0x8008D658: addu        $v1, $s3, $zero
    ctx->r3 = ADD32(ctx->r19, 0);
L_8008D65C:
    // 0x8008D65C: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
L_8008D660:
    // 0x8008D660: addu        $s3, $v1, $zero
    ctx->r19 = ADD32(ctx->r3, 0);
L_8008D664:
    // 0x8008D664: addu        $a0, $s5, $zero
    ctx->r4 = ADD32(ctx->r21, 0);
    // 0x8008D668: jal         0x80084860
    // 0x8008D66C: addiu       $a1, $s5, 0xE4
    ctx->r5 = ADD32(ctx->r21, 0XE4);
    func_80084860(rdram, ctx);
        goto after_19;
    // 0x8008D66C: addiu       $a1, $s5, 0xE4
    ctx->r5 = ADD32(ctx->r21, 0XE4);
    after_19:
    // 0x8008D670: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x8008D674: sll         $s0, $v0, 9
    ctx->r16 = S32(ctx->r2 << 9);
    // 0x8008D678: lui         $v0, 0x7F
    ctx->r2 = S32(0X7F << 16);
    // 0x8008D67C: slt         $v0, $v0, $s0
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r16) ? 1 : 0;
    // 0x8008D680: bnel        $v0, $zero, L_8008D694
    if (ctx->r2 != 0) {
        // 0x8008D684: lui         $s0, 0x7F
        ctx->r16 = S32(0X7F << 16);
            goto L_8008D694;
    }
    goto skip_4;
    // 0x8008D684: lui         $s0, 0x7F
    ctx->r16 = S32(0X7F << 16);
    skip_4:
    // 0x8008D688: j           L_8008D694
    // 0x8008D68C: nop

        goto L_8008D694;
    // 0x8008D68C: nop

L_8008D690:
    // 0x8008D690: addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
L_8008D694:
    // 0x8008D694: lui         $v0, 0x8015
    ctx->r2 = S32(0X8015 << 16);
    // 0x8008D698: lbu         $v0, -0x7C38($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X7C38);
    // 0x8008D69C: beq         $v0, $zero, L_8008D6AC
    if (ctx->r2 == 0) {
        // 0x8008D6A0: andi        $v1, $s4, 0xFF
        ctx->r3 = ctx->r20 & 0XFF;
            goto L_8008D6AC;
    }
    // 0x8008D6A0: andi        $v1, $s4, 0xFF
    ctx->r3 = ctx->r20 & 0XFF;
    // 0x8008D6A4: lui         $s3, 0x40
    ctx->r19 = S32(0X40 << 16);
    // 0x8008D6A8: addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
L_8008D6AC:
    // 0x8008D6AC: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // 0x8008D6B0: beq         $v1, $v0, L_8008D6EC
    if (ctx->r3 == ctx->r2) {
        // 0x8008D6B4: addu        $a0, $s5, $zero
        ctx->r4 = ADD32(ctx->r21, 0);
            goto L_8008D6EC;
    }
    // 0x8008D6B4: addu        $a0, $s5, $zero
    ctx->r4 = ADD32(ctx->r21, 0);
    // 0x8008D6B8: jal         0x80084860
    // 0x8008D6BC: addiu       $a1, $s5, 0x150
    ctx->r5 = ADD32(ctx->r21, 0X150);
    func_80084860(rdram, ctx);
        goto after_20;
    // 0x8008D6BC: addiu       $a1, $s5, 0x150
    ctx->r5 = ADD32(ctx->r21, 0X150);
    after_20:
    // 0x8008D6C0: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x8008D6C4: srl         $v0, $v0, 7
    ctx->r2 = S32(U32(ctx->r2) >> 7);
    // 0x8008D6C8: mult        $v0, $s2
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r18)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8008D6CC: mflo        $v0
    ctx->r2 = lo;
    // 0x8008D6D0: sra         $v1, $v0, 7
    ctx->r3 = S32(SIGNED(ctx->r2) >> 7);
    // 0x8008D6D4: lui         $v0, 0x7F
    ctx->r2 = S32(0X7F << 16);
    // 0x8008D6D8: slt         $v0, $v0, $v1
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8008D6DC: bnel        $v0, $zero, L_8008D6F0
    if (ctx->r2 != 0) {
        // 0x8008D6E0: lui         $v1, 0x7F
        ctx->r3 = S32(0X7F << 16);
            goto L_8008D6F0;
    }
    goto skip_5;
    // 0x8008D6E0: lui         $v1, 0x7F
    ctx->r3 = S32(0X7F << 16);
    skip_5:
    // 0x8008D6E4: j           L_8008D6F4
    // 0x8008D6E8: addu        $a0, $s6, $zero
    ctx->r4 = ADD32(ctx->r22, 0);
        goto L_8008D6F4;
    // 0x8008D6E8: addu        $a0, $s6, $zero
    ctx->r4 = ADD32(ctx->r22, 0);
L_8008D6EC:
    // 0x8008D6EC: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
L_8008D6F0:
    // 0x8008D6F0: addu        $a0, $s6, $zero
    ctx->r4 = ADD32(ctx->r22, 0);
L_8008D6F4:
    // 0x8008D6F4: addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    // 0x8008D6F8: addu        $a2, $s3, $zero
    ctx->r6 = ADD32(ctx->r19, 0);
    // 0x8008D6FC: addu        $a3, $s0, $zero
    ctx->r7 = ADD32(ctx->r16, 0);
    // 0x8008D700: sra         $v0, $a1, 8
    ctx->r2 = S32(SIGNED(ctx->r5) >> 8);
    // 0x8008D704: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x8008D708: addu        $at, $at, $s1
    ctx->r1 = ADD32(ctx->r1, ctx->r17);
    // 0x8008D70C: sh          $v0, -0x26C2($at)
    MEM_H(-0X26C2, ctx->r1) = ctx->r2;
    // 0x8008D710: jal         0x800923E4
    // 0x8008D714: sw          $v1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r3;
    func_800923E4(rdram, ctx);
        goto after_21;
    // 0x8008D714: sw          $v1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r3;
    after_21:
    // 0x8008D718: addiu       $s1, $s1, 0x17C
    ctx->r17 = ADD32(ctx->r17, 0X17C);
L_8008D71C:
    // 0x8008D71C: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x8008D720: lbu         $v0, 0x1AD0($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X1AD0);
    // 0x8008D724: addiu       $s6, $s6, 0x1
    ctx->r22 = ADD32(ctx->r22, 0X1);
    // 0x8008D728: slt         $v0, $s6, $v0
    ctx->r2 = SIGNED(ctx->r22) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8008D72C: bne         $v0, $zero, L_8008CA00
    if (ctx->r2 != 0) {
        // 0x8008D730: addiu       $s5, $s5, 0x17C
        ctx->r21 = ADD32(ctx->r21, 0X17C);
            goto L_8008CA00;
    }
    // 0x8008D730: addiu       $s5, $s5, 0x17C
    ctx->r21 = ADD32(ctx->r21, 0X17C);
    // 0x8008D734: addu        $s6, $zero, $zero
    ctx->r22 = ADD32(0, 0);
L_8008D738:
    // 0x8008D738: addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
L_8008D73C:
    // 0x8008D73C: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x8008D740: addu        $at, $at, $s0
    ctx->r1 = ADD32(ctx->r1, ctx->r16);
    // 0x8008D744: lw          $v1, 0x1B24($at)
    ctx->r3 = MEM_W(ctx->r1, 0X1B24);
    // 0x8008D748: beq         $v1, $zero, L_8008D874
    if (ctx->r3 == 0) {
        // 0x8008D74C: sra         $v1, $v1, 8
        ctx->r3 = S32(SIGNED(ctx->r3) >> 8);
            goto L_8008D874;
    }
    // 0x8008D74C: sra         $v1, $v1, 8
    ctx->r3 = S32(SIGNED(ctx->r3) >> 8);
    // 0x8008D750: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x8008D754: addu        $at, $at, $s0
    ctx->r1 = ADD32(ctx->r1, ctx->r16);
    // 0x8008D758: lw          $v0, 0x1B20($at)
    ctx->r2 = MEM_W(ctx->r1, 0X1B20);
    // 0x8008D75C: mult        $v1, $v0
    result = S64(S32(ctx->r3)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8008D760: mflo        $v1
    ctx->r3 = lo;
    // 0x8008D764: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x8008D768: addu        $at, $at, $s0
    ctx->r1 = ADD32(ctx->r1, ctx->r16);
    // 0x8008D76C: lw          $v0, 0x1B1C($at)
    ctx->r2 = MEM_W(ctx->r1, 0X1B1C);
    // 0x8008D770: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x8008D774: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x8008D778: addu        $at, $at, $s0
    ctx->r1 = ADD32(ctx->r1, ctx->r16);
    // 0x8008D77C: sw          $v0, 0x1B18($at)
    MEM_W(0X1B18, ctx->r1) = ctx->r2;
    // 0x8008D780: bgez        $v0, L_8008D794
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8008D784: nop
    
            goto L_8008D794;
    }
    // 0x8008D784: nop

    // 0x8008D788: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x8008D78C: addu        $at, $at, $s0
    ctx->r1 = ADD32(ctx->r1, ctx->r16);
    // 0x8008D790: sw          $zero, 0x1B18($at)
    MEM_W(0X1B18, ctx->r1) = 0;
L_8008D794:
    // 0x8008D794: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x8008D798: addu        $at, $at, $s0
    ctx->r1 = ADD32(ctx->r1, ctx->r16);
    // 0x8008D79C: lw          $v1, 0x1B24($at)
    ctx->r3 = MEM_W(ctx->r1, 0X1B24);
    // 0x8008D7A0: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x8008D7A4: lw          $v0, -0x5338($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X5338);
    // 0x8008D7A8: subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // 0x8008D7AC: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x8008D7B0: addu        $at, $at, $s0
    ctx->r1 = ADD32(ctx->r1, ctx->r16);
    // 0x8008D7B4: sw          $v1, 0x1B24($at)
    MEM_W(0X1B24, ctx->r1) = ctx->r3;
    // 0x8008D7B8: bgtz        $v1, L_8008D874
    if (SIGNED(ctx->r3) > 0) {
        // 0x8008D7BC: nop
    
            goto L_8008D874;
    }
    // 0x8008D7BC: nop

    // 0x8008D7C0: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x8008D7C4: addu        $at, $at, $s0
    ctx->r1 = ADD32(ctx->r1, ctx->r16);
    // 0x8008D7C8: lw          $v0, 0x1B1C($at)
    ctx->r2 = MEM_W(ctx->r1, 0X1B1C);
    // 0x8008D7CC: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x8008D7D0: addu        $at, $at, $s0
    ctx->r1 = ADD32(ctx->r1, ctx->r16);
    // 0x8008D7D4: lbu         $v1, 0x1B2D($at)
    ctx->r3 = MEM_BU(ctx->r1, 0X1B2D);
    // 0x8008D7D8: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x8008D7DC: addu        $at, $at, $s0
    ctx->r1 = ADD32(ctx->r1, ctx->r16);
    // 0x8008D7E0: sw          $zero, 0x1B24($at)
    MEM_W(0X1B24, ctx->r1) = 0;
    // 0x8008D7E4: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x8008D7E8: addu        $at, $at, $s0
    ctx->r1 = ADD32(ctx->r1, ctx->r16);
    // 0x8008D7EC: sw          $v0, 0x1B18($at)
    MEM_W(0X1B18, ctx->r1) = ctx->r2;
    // 0x8008D7F0: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x8008D7F4: beq         $v1, $v0, L_8008D844
    if (ctx->r3 == ctx->r2) {
        // 0x8008D7F8: slti        $v0, $v1, 0x3
        ctx->r2 = SIGNED(ctx->r3) < 0X3 ? 1 : 0;
            goto L_8008D844;
    }
    // 0x8008D7F8: slti        $v0, $v1, 0x3
    ctx->r2 = SIGNED(ctx->r3) < 0X3 ? 1 : 0;
    // 0x8008D7FC: beq         $v0, $zero, L_8008D814
    if (ctx->r2 == 0) {
        // 0x8008D800: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_8008D814;
    }
    // 0x8008D800: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8008D804: beq         $v1, $v0, L_8008D828
    if (ctx->r3 == ctx->r2) {
        // 0x8008D808: nop
    
            goto L_8008D828;
    }
    // 0x8008D808: nop

    // 0x8008D80C: j           L_8008D874
    // 0x8008D810: nop

        goto L_8008D874;
    // 0x8008D810: nop

L_8008D814:
    // 0x8008D814: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x8008D818: beq         $v1, $v0, L_8008D860
    if (ctx->r3 == ctx->r2) {
        // 0x8008D81C: addu        $a1, $zero, $zero
        ctx->r5 = ADD32(0, 0);
            goto L_8008D860;
    }
    // 0x8008D81C: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x8008D820: j           L_8008D874
    // 0x8008D824: nop

        goto L_8008D874;
    // 0x8008D824: nop

L_8008D828:
    // 0x8008D828: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x8008D82C: addu        $at, $at, $s0
    ctx->r1 = ADD32(ctx->r1, ctx->r16);
    // 0x8008D830: lw          $a0, 0x1B28($at)
    ctx->r4 = MEM_W(ctx->r1, 0X1B28);
    // 0x8008D834: jal         0x80095ADC
    // 0x8008D838: nop

    func_80095ADC(rdram, ctx);
        goto after_22;
    // 0x8008D838: nop

    after_22:
    // 0x8008D83C: j           L_8008D874
    // 0x8008D840: nop

        goto L_8008D874;
    // 0x8008D840: nop

L_8008D844:
    // 0x8008D844: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x8008D848: addu        $at, $at, $s0
    ctx->r1 = ADD32(ctx->r1, ctx->r16);
    // 0x8008D84C: lw          $a0, 0x1B28($at)
    ctx->r4 = MEM_W(ctx->r1, 0X1B28);
    // 0x8008D850: jal         0x8009582C
    // 0x8008D854: nop

    func_8009582C(rdram, ctx);
        goto after_23;
    // 0x8008D854: nop

    after_23:
    // 0x8008D858: j           L_8008D874
    // 0x8008D85C: nop

        goto L_8008D874;
    // 0x8008D85C: nop

L_8008D860:
    // 0x8008D860: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x8008D864: addu        $at, $at, $s0
    ctx->r1 = ADD32(ctx->r1, ctx->r16);
    // 0x8008D868: lw          $a0, 0x1B28($at)
    ctx->r4 = MEM_W(ctx->r1, 0X1B28);
    // 0x8008D86C: jal         0x80096118
    // 0x8008D870: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    func_80096118(rdram, ctx);
        goto after_24;
    // 0x8008D870: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    after_24:
L_8008D874:
    // 0x8008D874: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x8008D878: addu        $at, $at, $s0
    ctx->r1 = ADD32(ctx->r1, ctx->r16);
    // 0x8008D87C: lw          $v1, 0x1B3C($at)
    ctx->r3 = MEM_W(ctx->r1, 0X1B3C);
    // 0x8008D880: beq         $v1, $zero, L_8008D91C
    if (ctx->r3 == 0) {
        // 0x8008D884: sra         $v1, $v1, 8
        ctx->r3 = S32(SIGNED(ctx->r3) >> 8);
            goto L_8008D91C;
    }
    // 0x8008D884: sra         $v1, $v1, 8
    ctx->r3 = S32(SIGNED(ctx->r3) >> 8);
    // 0x8008D888: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x8008D88C: addu        $at, $at, $s0
    ctx->r1 = ADD32(ctx->r1, ctx->r16);
    // 0x8008D890: lw          $v0, 0x1B38($at)
    ctx->r2 = MEM_W(ctx->r1, 0X1B38);
    // 0x8008D894: mult        $v1, $v0
    result = S64(S32(ctx->r3)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8008D898: mflo        $v1
    ctx->r3 = lo;
    // 0x8008D89C: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x8008D8A0: addu        $at, $at, $s0
    ctx->r1 = ADD32(ctx->r1, ctx->r16);
    // 0x8008D8A4: lw          $v0, 0x1B34($at)
    ctx->r2 = MEM_W(ctx->r1, 0X1B34);
    // 0x8008D8A8: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x8008D8AC: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x8008D8B0: addu        $at, $at, $s0
    ctx->r1 = ADD32(ctx->r1, ctx->r16);
    // 0x8008D8B4: sw          $v0, 0x1B30($at)
    MEM_W(0X1B30, ctx->r1) = ctx->r2;
    // 0x8008D8B8: bgez        $v0, L_8008D8CC
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8008D8BC: nop
    
            goto L_8008D8CC;
    }
    // 0x8008D8BC: nop

    // 0x8008D8C0: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x8008D8C4: addu        $at, $at, $s0
    ctx->r1 = ADD32(ctx->r1, ctx->r16);
    // 0x8008D8C8: sw          $zero, 0x1B30($at)
    MEM_W(0X1B30, ctx->r1) = 0;
L_8008D8CC:
    // 0x8008D8CC: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x8008D8D0: addu        $at, $at, $s0
    ctx->r1 = ADD32(ctx->r1, ctx->r16);
    // 0x8008D8D4: lw          $v1, 0x1B3C($at)
    ctx->r3 = MEM_W(ctx->r1, 0X1B3C);
    // 0x8008D8D8: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x8008D8DC: lw          $v0, -0x5338($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X5338);
    // 0x8008D8E0: subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // 0x8008D8E4: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x8008D8E8: addu        $at, $at, $s0
    ctx->r1 = ADD32(ctx->r1, ctx->r16);
    // 0x8008D8EC: sw          $v1, 0x1B3C($at)
    MEM_W(0X1B3C, ctx->r1) = ctx->r3;
    // 0x8008D8F0: bgtzl       $v1, L_8008D920
    if (SIGNED(ctx->r3) > 0) {
        // 0x8008D8F4: addiu       $s6, $s6, 0x1
        ctx->r22 = ADD32(ctx->r22, 0X1);
            goto L_8008D920;
    }
    goto skip_6;
    // 0x8008D8F4: addiu       $s6, $s6, 0x1
    ctx->r22 = ADD32(ctx->r22, 0X1);
    skip_6:
    // 0x8008D8F8: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x8008D8FC: addu        $at, $at, $s0
    ctx->r1 = ADD32(ctx->r1, ctx->r16);
    // 0x8008D900: lw          $v0, 0x1B34($at)
    ctx->r2 = MEM_W(ctx->r1, 0X1B34);
    // 0x8008D904: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x8008D908: addu        $at, $at, $s0
    ctx->r1 = ADD32(ctx->r1, ctx->r16);
    // 0x8008D90C: sw          $zero, 0x1B3C($at)
    MEM_W(0X1B3C, ctx->r1) = 0;
    // 0x8008D910: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x8008D914: addu        $at, $at, $s0
    ctx->r1 = ADD32(ctx->r1, ctx->r16);
    // 0x8008D918: sw          $v0, 0x1B30($at)
    MEM_W(0X1B30, ctx->r1) = ctx->r2;
L_8008D91C:
    // 0x8008D91C: addiu       $s6, $s6, 0x1
    ctx->r22 = ADD32(ctx->r22, 0X1);
L_8008D920:
    // 0x8008D920: slti        $v0, $s6, 0x20
    ctx->r2 = SIGNED(ctx->r22) < 0X20 ? 1 : 0;
    // 0x8008D924: bne         $v0, $zero, L_8008D73C
    if (ctx->r2 != 0) {
        // 0x8008D928: addiu       $s0, $s0, 0x28
        ctx->r16 = ADD32(ctx->r16, 0X28);
            goto L_8008D73C;
    }
    // 0x8008D928: addiu       $s0, $s0, 0x28
    ctx->r16 = ADD32(ctx->r16, 0X28);
    // 0x8008D92C: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
    // 0x8008D930: lw          $fp, 0x48($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X48);
    // 0x8008D934: lw          $s7, 0x44($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X44);
    // 0x8008D938: lw          $s6, 0x40($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X40);
    // 0x8008D93C: lw          $s5, 0x3C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X3C);
    // 0x8008D940: lw          $s4, 0x38($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X38);
    // 0x8008D944: lw          $s3, 0x34($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X34);
    // 0x8008D948: lw          $s2, 0x30($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X30);
    // 0x8008D94C: lw          $s1, 0x2C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X2C);
    // 0x8008D950: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x8008D954: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // 0x8008D958: jr          $ra
    // 0x8008D95C: nop

    return;
    // 0x8008D95C: nop

;}
RECOMP_FUNC void func_8008D960(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008D960: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8008D964: lw          $a0, 0x2038($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X2038);
    // 0x8008D968: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8008D96C: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x8008D970: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x8008D974: sw          $zero, -0x3BB8($at)
    MEM_W(-0X3BB8, ctx->r1) = 0;
    // 0x8008D978: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x8008D97C: sw          $zero, -0x3BA8($at)
    MEM_W(-0X3BA8, ctx->r1) = 0;
    // 0x8008D980: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x8008D984: sw          $zero, -0x4FC4($at)
    MEM_W(-0X4FC4, ctx->r1) = 0;
    // 0x8008D988: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x8008D98C: sw          $zero, -0x3BAC($at)
    MEM_W(-0X3BAC, ctx->r1) = 0;
    // 0x8008D990: beq         $a0, $zero, L_8008D9F0
    if (ctx->r4 == 0) {
        // 0x8008D994: sll         $v0, $a0, 5
        ctx->r2 = S32(ctx->r4 << 5);
            goto L_8008D9F0;
    }
    // 0x8008D994: sll         $v0, $a0, 5
    ctx->r2 = S32(ctx->r4 << 5);
    // 0x8008D998: subu        $v0, $v0, $a0
    ctx->r2 = SUB32(ctx->r2, ctx->r4);
    // 0x8008D99C: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8008D9A0: lui         $v1, 0x8014
    ctx->r3 = S32(0X8014 << 16);
    // 0x8008D9A4: lw          $v1, 0x40C0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X40C0);
    // 0x8008D9A8: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x8008D9AC: sll         $v0, $v0, 8
    ctx->r2 = S32(ctx->r2 << 8);
    // 0x8008D9B0: div         $zero, $v0, $v1
    if (S32(ctx->r3) != 0) { lo = S32(S64(S32(ctx->r2)) / S64(S32(ctx->r3))); hi = S32(S64(S32(ctx->r2)) % S64(S32(ctx->r3))); } else { lo = 0; hi = S32(ctx->r2); }
    // 0x8008D9B4: bne         $v1, $zero, L_8008D9C0
    if (ctx->r3 != 0) {
        // 0x8008D9B8: nop
    
            goto L_8008D9C0;
    }
    // 0x8008D9B8: nop

    // 0x8008D9BC: break       7
    do_break(2148063676);
L_8008D9C0:
    // 0x8008D9C0: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8008D9C4: bne         $v1, $at, L_8008D9D8
    if (ctx->r3 != ctx->r1) {
        // 0x8008D9C8: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8008D9D8;
    }
    // 0x8008D9C8: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8008D9CC: bne         $v0, $at, L_8008D9D8
    if (ctx->r2 != ctx->r1) {
        // 0x8008D9D0: nop
    
            goto L_8008D9D8;
    }
    // 0x8008D9D0: nop

    // 0x8008D9D4: break       6
    do_break(2148063700);
L_8008D9D8:
    // 0x8008D9D8: mflo        $v0
    ctx->r2 = lo;
    // 0x8008D9DC: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x8008D9E0: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x8008D9E4: sw          $v0, -0x5338($at)
    MEM_W(-0X5338, ctx->r1) = ctx->r2;
    // 0x8008D9E8: jal         0x8008C9AC
    // 0x8008D9EC: nop

    func_8008C9AC(rdram, ctx);
        goto after_0;
    // 0x8008D9EC: nop

    after_0:
L_8008D9F0:
    // 0x8008D9F0: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x8008D9F4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8008D9F8: jr          $ra
    // 0x8008D9FC: nop

    return;
    // 0x8008D9FC: nop

;}
RECOMP_FUNC void func_8008DA00(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008DA00: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x8008DA04: lbu         $v0, 0xF50($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0XF50);
    // 0x8008DA08: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8008DA0C: beq         $v0, $zero, L_8008DA3C
    if (ctx->r2 == 0) {
        // 0x8008DA10: sw          $ra, 0x10($sp)
        MEM_W(0X10, ctx->r29) = ctx->r31;
            goto L_8008DA3C;
    }
    // 0x8008DA10: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x8008DA14: jal         0x80092010
    // 0x8008DA18: nop

    func_80092010(rdram, ctx);
        goto after_0;
    // 0x8008DA18: nop

    after_0:
    // 0x8008DA1C: jal         0x80095DA0
    // 0x8008DA20: nop

    func_80095DA0(rdram, ctx);
        goto after_1;
    // 0x8008DA20: nop

    after_1:
    // 0x8008DA24: jal         0x80098EEC
    // 0x8008DA28: nop

    func_80098EEC(rdram, ctx);
        goto after_2;
    // 0x8008DA28: nop

    after_2:
    // 0x8008DA2C: jal         0x8008DBF4
    // 0x8008DA30: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    func_8008DBF4(rdram, ctx);
        goto after_3;
    // 0x8008DA30: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    after_3:
    // 0x8008DA34: jal         0x8009205C
    // 0x8008DA38: nop

    func_8009205C(rdram, ctx);
        goto after_4;
    // 0x8008DA38: nop

    after_4:
L_8008DA3C:
    // 0x8008DA3C: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x8008DA40: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8008DA44: jr          $ra
    // 0x8008DA48: nop

    return;
    // 0x8008DA48: nop

;}
RECOMP_FUNC void func_8008DA4C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008DA4C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8008DA50: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x8008DA54: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8008DA58: jal         0x800862F4
    // 0x8008DA5C: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    func_800862F4(rdram, ctx);
        goto after_0;
    // 0x8008DA5C: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    after_0:
    // 0x8008DA60: lw          $v1, 0x24($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X24);
    // 0x8008DA64: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x8008DA68: sw          $v0, 0x64($s0)
    MEM_W(0X64, ctx->r16) = ctx->r2;
    // 0x8008DA6C: addiu       $v0, $zero, -0x4
    ctx->r2 = ADD32(0, -0X4);
    // 0x8008DA70: sw          $zero, 0x0($s0)
    MEM_W(0X0, ctx->r16) = 0;
    // 0x8008DA74: sb          $zero, 0x2E($s0)
    MEM_B(0X2E, ctx->r16) = 0;
    // 0x8008DA78: sw          $zero, 0x28($s0)
    MEM_W(0X28, ctx->r16) = 0;
    // 0x8008DA7C: and         $v1, $v1, $v0
    ctx->r3 = ctx->r3 & ctx->r2;
    // 0x8008DA80: sw          $v1, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->r3;
    // 0x8008DA84: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8008DA88: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x8008DA8C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8008DA90: jr          $ra
    // 0x8008DA94: nop

    return;
    // 0x8008DA94: nop

;}
RECOMP_FUNC void func_8008DA98(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008DA98: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x8008DA9C: lbu         $v0, 0xF50($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0XF50);
    // 0x8008DAA0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8008DAA4: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    // 0x8008DAA8: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8008DAAC: sw          $s4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r20;
    // 0x8008DAB0: sw          $s3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r19;
    // 0x8008DAB4: sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // 0x8008DAB8: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x8008DABC: beq         $v0, $zero, L_8008DBCC
    if (ctx->r2 == 0) {
        // 0x8008DAC0: sw          $s0, 0x10($sp)
        MEM_W(0X10, ctx->r29) = ctx->r16;
            goto L_8008DBCC;
    }
    // 0x8008DAC0: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x8008DAC4: beql        $a0, $a1, L_8008DB18
    if (ctx->r4 == ctx->r5) {
        // 0x8008DAC8: addiu       $a0, $zero, -0x1
        ctx->r4 = ADD32(0, -0X1);
            goto L_8008DB18;
    }
    goto skip_0;
    // 0x8008DAC8: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    skip_0:
    // 0x8008DACC: lui         $v1, 0x8014
    ctx->r3 = S32(0X8014 << 16);
    // 0x8008DAD0: lw          $v1, -0x5100($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X5100);
    // 0x8008DAD4: beq         $v1, $zero, L_8008DAFC
    if (ctx->r3 == 0) {
        // 0x8008DAD8: addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
            goto L_8008DAFC;
    }
    // 0x8008DAD8: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_8008DADC:
    // 0x8008DADC: lw          $v0, 0x8($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X8);
    // 0x8008DAE0: beq         $v0, $a0, L_8008DB10
    if (ctx->r2 == ctx->r4) {
        // 0x8008DAE4: sltu        $v0, $a0, $v0
        ctx->r2 = ctx->r4 < ctx->r2 ? 1 : 0;
            goto L_8008DB10;
    }
    // 0x8008DAE4: sltu        $v0, $a0, $v0
    ctx->r2 = ctx->r4 < ctx->r2 ? 1 : 0;
    // 0x8008DAE8: bne         $v0, $zero, L_8008DAFC
    if (ctx->r2 != 0) {
        // 0x8008DAEC: addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
            goto L_8008DAFC;
    }
    // 0x8008DAEC: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // 0x8008DAF0: lw          $v1, 0x0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X0);
    // 0x8008DAF4: bne         $v1, $zero, L_8008DADC
    if (ctx->r3 != 0) {
        // 0x8008DAF8: nop
    
            goto L_8008DADC;
    }
    // 0x8008DAF8: nop

L_8008DAFC:
    // 0x8008DAFC: beq         $v0, $zero, L_8008DB18
    if (ctx->r2 == 0) {
        // 0x8008DB00: addiu       $a0, $zero, -0x1
        ctx->r4 = ADD32(0, -0X1);
            goto L_8008DB18;
    }
    // 0x8008DB00: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    // 0x8008DB04: lw          $a0, 0xC($v0)
    ctx->r4 = MEM_W(ctx->r2, 0XC);
    // 0x8008DB08: j           L_8008DB1C
    // 0x8008DB0C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_8008DB1C;
    // 0x8008DB0C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_8008DB10:
    // 0x8008DB10: j           L_8008DAFC
    // 0x8008DB14: addu        $v0, $v1, $zero
    ctx->r2 = ADD32(ctx->r3, 0);
        goto L_8008DAFC;
    // 0x8008DB14: addu        $v0, $v1, $zero
    ctx->r2 = ADD32(ctx->r3, 0);
L_8008DB18:
    // 0x8008DB18: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_8008DB1C:
    // 0x8008DB1C: beq         $a0, $v0, L_8008DBD0
    if (ctx->r4 == ctx->r2) {
        // 0x8008DB20: addu        $v0, $a1, $zero
        ctx->r2 = ADD32(ctx->r5, 0);
            goto L_8008DBD0;
    }
    // 0x8008DB20: addu        $v0, $a1, $zero
    ctx->r2 = ADD32(ctx->r5, 0);
    // 0x8008DB24: lui         $s4, 0x8014
    ctx->r20 = S32(0X8014 << 16);
    // 0x8008DB28: addiu       $s4, $s4, -0x2780
    ctx->r20 = ADD32(ctx->r20, -0X2780);
    // 0x8008DB2C: addiu       $s2, $zero, -0x1
    ctx->r18 = ADD32(0, -0X1);
    // 0x8008DB30: addiu       $s3, $zero, -0x4
    ctx->r19 = ADD32(0, -0X4);
    // 0x8008DB34: andi        $s1, $a0, 0xFF
    ctx->r17 = ctx->r4 & 0XFF;
L_8008DB38:
    // 0x8008DB38: sll         $v0, $s1, 1
    ctx->r2 = S32(ctx->r17 << 1);
    // 0x8008DB3C: addu        $v0, $v0, $s1
    ctx->r2 = ADD32(ctx->r2, ctx->r17);
    // 0x8008DB40: sll         $v0, $v0, 5
    ctx->r2 = S32(ctx->r2 << 5);
    // 0x8008DB44: subu        $v0, $v0, $s1
    ctx->r2 = SUB32(ctx->r2, ctx->r17);
    // 0x8008DB48: sll         $s0, $v0, 2
    ctx->r16 = S32(ctx->r2 << 2);
    // 0x8008DB4C: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x8008DB50: addu        $at, $at, $s0
    ctx->r1 = ADD32(ctx->r1, ctx->r16);
    // 0x8008DB54: lw          $v0, -0x271C($at)
    ctx->r2 = MEM_W(ctx->r1, -0X271C);
    // 0x8008DB58: bne         $v0, $a0, L_8008DBA8
    if (ctx->r2 != ctx->r4) {
        // 0x8008DB5C: sll         $v0, $s1, 1
        ctx->r2 = S32(ctx->r17 << 1);
            goto L_8008DBA8;
    }
    // 0x8008DB5C: sll         $v0, $s1, 1
    ctx->r2 = S32(ctx->r17 << 1);
    // 0x8008DB60: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x8008DB64: addu        $at, $at, $s0
    ctx->r1 = ADD32(ctx->r1, ctx->r16);
    // 0x8008DB68: lw          $v0, -0x2780($at)
    ctx->r2 = MEM_W(ctx->r1, -0X2780);
    // 0x8008DB6C: beq         $v0, $zero, L_8008DB98
    if (ctx->r2 == 0) {
        // 0x8008DB70: addu        $s0, $s0, $s4
        ctx->r16 = ADD32(ctx->r16, ctx->r20);
            goto L_8008DB98;
    }
    // 0x8008DB70: addu        $s0, $s0, $s4
    ctx->r16 = ADD32(ctx->r16, ctx->r20);
    // 0x8008DB74: jal         0x800862F4
    // 0x8008DB78: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_800862F4(rdram, ctx);
        goto after_0;
    // 0x8008DB78: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_0:
    // 0x8008DB7C: lw          $v0, 0x24($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X24);
    // 0x8008DB80: sw          $s2, 0x64($s0)
    MEM_W(0X64, ctx->r16) = ctx->r18;
    // 0x8008DB84: sw          $zero, 0x0($s0)
    MEM_W(0X0, ctx->r16) = 0;
    // 0x8008DB88: sb          $zero, 0x2E($s0)
    MEM_B(0X2E, ctx->r16) = 0;
    // 0x8008DB8C: sw          $zero, 0x28($s0)
    MEM_W(0X28, ctx->r16) = 0;
    // 0x8008DB90: and         $v0, $v0, $s3
    ctx->r2 = ctx->r2 & ctx->r19;
    // 0x8008DB94: sw          $v0, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->r2;
L_8008DB98:
    // 0x8008DB98: jal         0x80092490
    // 0x8008DB9C: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    func_80092490(rdram, ctx);
        goto after_1;
    // 0x8008DB9C: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    after_1:
    // 0x8008DBA0: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x8008DBA4: sll         $v0, $s1, 1
    ctx->r2 = S32(ctx->r17 << 1);
L_8008DBA8:
    // 0x8008DBA8: addu        $v0, $v0, $s1
    ctx->r2 = ADD32(ctx->r2, ctx->r17);
    // 0x8008DBAC: sll         $v0, $v0, 5
    ctx->r2 = S32(ctx->r2 << 5);
    // 0x8008DBB0: subu        $v0, $v0, $s1
    ctx->r2 = SUB32(ctx->r2, ctx->r17);
    // 0x8008DBB4: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8008DBB8: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x8008DBBC: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x8008DBC0: lw          $a0, -0x2770($at)
    ctx->r4 = MEM_W(ctx->r1, -0X2770);
    // 0x8008DBC4: bne         $a0, $s2, L_8008DB38
    if (ctx->r4 != ctx->r18) {
        // 0x8008DBC8: andi        $s1, $a0, 0xFF
        ctx->r17 = ctx->r4 & 0XFF;
            goto L_8008DB38;
    }
    // 0x8008DBC8: andi        $s1, $a0, 0xFF
    ctx->r17 = ctx->r4 & 0XFF;
L_8008DBCC:
    // 0x8008DBCC: addu        $v0, $a1, $zero
    ctx->r2 = ADD32(ctx->r5, 0);
L_8008DBD0:
    // 0x8008DBD0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8008DBD4: lw          $s4, 0x20($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X20);
    // 0x8008DBD8: lw          $s3, 0x1C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X1C);
    // 0x8008DBDC: lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X18);
    // 0x8008DBE0: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x8008DBE4: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x8008DBE8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8008DBEC: jr          $ra
    // 0x8008DBF0: nop

    return;
    // 0x8008DBF0: nop

;}
RECOMP_FUNC void func_8008DBF4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008DBF4: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x8008DBF8: lbu         $v0, 0x1AD0($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X1AD0);
    // 0x8008DBFC: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8008DC00: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x8008DC04: addu        $s4, $zero, $zero
    ctx->r20 = ADD32(0, 0);
    // 0x8008DC08: sw          $ra, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r31;
    // 0x8008DC0C: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x8008DC10: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x8008DC14: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x8008DC18: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x8008DC1C: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8008DC20: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8008DC24: blez        $v0, L_8008DCF0
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8008DC28: sw          $s0, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r16;
            goto L_8008DCF0;
    }
    // 0x8008DC28: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8008DC2C: andi        $s6, $a0, 0xFF
    ctx->r22 = ctx->r4 & 0XFF;
    // 0x8008DC30: addiu       $s7, $zero, -0x1
    ctx->r23 = ADD32(0, -0X1);
    // 0x8008DC34: addiu       $s5, $zero, -0x4
    ctx->r21 = ADD32(0, -0X4);
    // 0x8008DC38: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x8008DC3C: addiu       $v0, $v0, -0x2780
    ctx->r2 = ADD32(ctx->r2, -0X2780);
    // 0x8008DC40: addiu       $s3, $v0, 0x24
    ctx->r19 = ADD32(ctx->r2, 0X24);
    // 0x8008DC44: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    // 0x8008DC48: addu        $s2, $s0, $zero
    ctx->r18 = ADD32(ctx->r16, 0);
    // 0x8008DC4C: addu        $s1, $zero, $zero
    ctx->r17 = ADD32(0, 0);
L_8008DC50:
    // 0x8008DC50: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x8008DC54: beq         $v0, $zero, L_8008DCC4
    if (ctx->r2 == 0) {
        // 0x8008DC58: nop
    
            goto L_8008DCC4;
    }
    // 0x8008DC58: nop

    // 0x8008DC5C: beq         $s6, $zero, L_8008DC78
    if (ctx->r22 == 0) {
        // 0x8008DC60: nop
    
            goto L_8008DC78;
    }
    // 0x8008DC60: nop

    // 0x8008DC64: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x8008DC68: addu        $at, $at, $s1
    ctx->r1 = ADD32(ctx->r1, ctx->r17);
    // 0x8008DC6C: lbu         $v0, -0x2730($at)
    ctx->r2 = MEM_BU(ctx->r1, -0X2730);
    // 0x8008DC70: bnel        $v0, $zero, L_8008DCD0
    if (ctx->r2 != 0) {
        // 0x8008DC74: addiu       $s3, $s3, 0x17C
        ctx->r19 = ADD32(ctx->r19, 0X17C);
            goto L_8008DCD0;
    }
    goto skip_0;
    // 0x8008DC74: addiu       $s3, $s3, 0x17C
    ctx->r19 = ADD32(ctx->r19, 0X17C);
    skip_0:
L_8008DC78:
    // 0x8008DC78: jal         0x800862F4
    // 0x8008DC7C: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_800862F4(rdram, ctx);
        goto after_0;
    // 0x8008DC7C: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_0:
    // 0x8008DC80: lw          $v0, 0x24($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X24);
    // 0x8008DC84: sw          $s7, 0x64($s0)
    MEM_W(0X64, ctx->r16) = ctx->r23;
    // 0x8008DC88: sw          $zero, 0x0($s0)
    MEM_W(0X0, ctx->r16) = 0;
    // 0x8008DC8C: sb          $zero, 0x2E($s0)
    MEM_B(0X2E, ctx->r16) = 0;
    // 0x8008DC90: sw          $zero, 0x28($s0)
    MEM_W(0X28, ctx->r16) = 0;
    // 0x8008DC94: and         $v0, $v0, $s5
    ctx->r2 = ctx->r2 & ctx->r21;
    // 0x8008DC98: sw          $v0, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->r2;
    // 0x8008DC9C: sw          $zero, 0x0($s2)
    MEM_W(0X0, ctx->r18) = 0;
    // 0x8008DCA0: lw          $v0, 0x0($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X0);
    // 0x8008DCA4: and         $v0, $v0, $s5
    ctx->r2 = ctx->r2 & ctx->r21;
    // 0x8008DCA8: sw          $v0, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r2;
    // 0x8008DCAC: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x8008DCB0: addu        $at, $at, $s1
    ctx->r1 = ADD32(ctx->r1, ctx->r17);
    // 0x8008DCB4: sb          $zero, -0x2752($at)
    MEM_B(-0X2752, ctx->r1) = 0;
    // 0x8008DCB8: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x8008DCBC: addu        $at, $at, $s1
    ctx->r1 = ADD32(ctx->r1, ctx->r17);
    // 0x8008DCC0: sw          $zero, -0x2758($at)
    MEM_W(-0X2758, ctx->r1) = 0;
L_8008DCC4:
    // 0x8008DCC4: jal         0x80092490
    // 0x8008DCC8: addu        $a0, $s4, $zero
    ctx->r4 = ADD32(ctx->r20, 0);
    func_80092490(rdram, ctx);
        goto after_1;
    // 0x8008DCC8: addu        $a0, $s4, $zero
    ctx->r4 = ADD32(ctx->r20, 0);
    after_1:
    // 0x8008DCCC: addiu       $s3, $s3, 0x17C
    ctx->r19 = ADD32(ctx->r19, 0X17C);
L_8008DCD0:
    // 0x8008DCD0: addiu       $s2, $s2, 0x17C
    ctx->r18 = ADD32(ctx->r18, 0X17C);
    // 0x8008DCD4: addiu       $s0, $s0, 0x17C
    ctx->r16 = ADD32(ctx->r16, 0X17C);
    // 0x8008DCD8: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x8008DCDC: lbu         $v0, 0x1AD0($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X1AD0);
    // 0x8008DCE0: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    // 0x8008DCE4: slt         $v0, $s4, $v0
    ctx->r2 = SIGNED(ctx->r20) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8008DCE8: bne         $v0, $zero, L_8008DC50
    if (ctx->r2 != 0) {
        // 0x8008DCEC: addiu       $s1, $s1, 0x17C
        ctx->r17 = ADD32(ctx->r17, 0X17C);
            goto L_8008DC50;
    }
    // 0x8008DCEC: addiu       $s1, $s1, 0x17C
    ctx->r17 = ADD32(ctx->r17, 0X17C);
L_8008DCF0:
    // 0x8008DCF0: lw          $ra, 0x38($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X38);
    // 0x8008DCF4: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x8008DCF8: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x8008DCFC: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x8008DD00: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x8008DD04: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x8008DD08: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8008DD0C: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8008DD10: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8008DD14: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x8008DD18: jr          $ra
    // 0x8008DD1C: nop

    return;
    // 0x8008DD1C: nop

;}
RECOMP_FUNC void func_8008DD20(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008DD20: andi        $a0, $a0, 0xF
    ctx->r4 = ctx->r4 & 0XF;
    // 0x8008DD24: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8008DD28: addu        $at, $at, $a0
    ctx->r1 = ADD32(ctx->r1, ctx->r4);
    // 0x8008DD2C: lbu         $v0, -0x73A8($at)
    ctx->r2 = MEM_BU(ctx->r1, -0X73A8);
    // 0x8008DD30: jr          $ra
    // 0x8008DD34: nop

    return;
    // 0x8008DD34: nop

;}
RECOMP_FUNC void func_8008DD38(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008DD38: andi        $a0, $a0, 0xF
    ctx->r4 = ctx->r4 & 0XF;
    // 0x8008DD3C: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8008DD40: addu        $at, $at, $a0
    ctx->r1 = ADD32(ctx->r1, ctx->r4);
    // 0x8008DD44: sb          $a1, -0x73A8($at)
    MEM_B(-0X73A8, ctx->r1) = ctx->r5;
    // 0x8008DD48: jr          $ra
    // 0x8008DD4C: nop

    return;
    // 0x8008DD4C: nop

;}
RECOMP_FUNC void func_8008DD50(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008DD50: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8008DD54: sb          $a0, -0x7C38($at)
    MEM_B(-0X7C38, ctx->r1) = ctx->r4;
    // 0x8008DD58: jr          $ra
    // 0x8008DD5C: nop

    return;
    // 0x8008DD5C: nop

;}
RECOMP_FUNC void func_8008DD60(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008DD60: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x8008DD64: addu        $t0, $a1, $zero
    ctx->r8 = ADD32(ctx->r5, 0);
    // 0x8008DD68: lw          $t2, 0x18($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X18);
    // 0x8008DD6C: andi        $v0, $t0, 0xFFFF
    ctx->r2 = ctx->r8 & 0XFFFF;
    // 0x8008DD70: beql        $v0, $zero, L_8008DD78
    if (ctx->r2 == 0) {
        // 0x8008DD74: addiu       $t0, $a1, 0x1
        ctx->r8 = ADD32(ctx->r5, 0X1);
            goto L_8008DD78;
    }
    goto skip_0;
    // 0x8008DD74: addiu       $t0, $a1, 0x1
    ctx->r8 = ADD32(ctx->r5, 0X1);
    skip_0:
L_8008DD78:
    // 0x8008DD78: andi        $a1, $t0, 0xFFFF
    ctx->r5 = ctx->r8 & 0XFFFF;
    // 0x8008DD7C: sll         $t1, $a1, 8
    ctx->r9 = S32(ctx->r5 << 8);
    // 0x8008DD80: andi        $a2, $a2, 0xFF
    ctx->r6 = ctx->r6 & 0XFF;
    // 0x8008DD84: addiu       $v1, $a2, -0xFA
    ctx->r3 = ADD32(ctx->r6, -0XFA);
    // 0x8008DD88: sltiu       $v0, $v1, 0x6
    ctx->r2 = ctx->r3 < 0X6 ? 1 : 0;
    // 0x8008DD8C: beq         $v0, $zero, L_8008E00C
    if (ctx->r2 == 0) {
        // 0x8008DD90: sw          $t1, 0x0($sp)
        MEM_W(0X0, ctx->r29) = ctx->r9;
            goto L_8008E00C;
    }
    // 0x8008DD90: sw          $t1, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r9;
    // 0x8008DD94: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x8008DD98: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8008DD9C: addu        $at, $at, $v0
    gpr jr_addend_8008DDA4 = ctx->r2;
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x8008DDA0: lw          $v0, -0x22C8($at)
    ctx->r2 = ADD32(ctx->r1, -0X22C8);
    // 0x8008DDA4: jr          $v0
    // 0x8008DDA8: nop

    switch (jr_addend_8008DDA4 >> 2) {
        case 0: goto L_8008DF30; break;
        case 1: goto L_8008DF38; break;
        case 2: goto L_8008DE6C; break;
        case 3: goto L_8008DF40; break;
        case 4: goto L_8008DF48; break;
        case 5: goto L_8008DDAC; break;
        default: switch_error(__func__, 0x8008DDA4, 0x8003DD38);
    }
    // 0x8008DDA8: nop

L_8008DDAC:
    // 0x8008DDAC: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // 0x8008DDB0: andi        $v0, $a0, 0xFF
    ctx->r2 = ctx->r4 & 0XFF;
    // 0x8008DDB4: sll         $t2, $v0, 16
    ctx->r10 = S32(ctx->r2 << 16);
    // 0x8008DDB8: lw          $t1, 0x0($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X0);
    // 0x8008DDBC: andi        $a3, $t0, 0xFFFF
    ctx->r7 = ctx->r8 & 0XFFFF;
    // 0x8008DDC0: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x8008DDC4: lui         $a1, 0x8014
    ctx->r5 = S32(0X8014 << 16);
    // 0x8008DDC8: addiu       $a1, $a1, 0x1B1C
    ctx->r5 = ADD32(ctx->r5, 0X1B1C);
    // 0x8008DDCC: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
L_8008DDD0:
    // 0x8008DDD0: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x8008DDD4: addu        $at, $at, $a0
    ctx->r1 = ADD32(ctx->r1, ctx->r4);
    // 0x8008DDD8: lbu         $v0, 0x1B2C($at)
    ctx->r2 = MEM_BU(ctx->r1, 0X1B2C);
    // 0x8008DDDC: sltiu       $v0, $v0, 0x2
    ctx->r2 = ctx->r2 < 0X2 ? 1 : 0;
    // 0x8008DDE0: beql        $v0, $zero, L_8008DE54
    if (ctx->r2 == 0) {
        // 0x8008DDE4: addiu       $a1, $a1, 0x28
        ctx->r5 = ADD32(ctx->r5, 0X28);
            goto L_8008DE54;
    }
    goto skip_1;
    // 0x8008DDE4: addiu       $a1, $a1, 0x28
    ctx->r5 = ADD32(ctx->r5, 0X28);
    skip_1:
    // 0x8008DDE8: sw          $t2, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r10;
    // 0x8008DDEC: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x8008DDF0: addu        $at, $at, $a0
    ctx->r1 = ADD32(ctx->r1, ctx->r4);
    // 0x8008DDF4: sw          $t1, 0x1B24($at)
    MEM_W(0X1B24, ctx->r1) = ctx->r9;
    // 0x8008DDF8: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x8008DDFC: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x8008DE00: addu        $at, $at, $a0
    ctx->r1 = ADD32(ctx->r1, ctx->r4);
    // 0x8008DE04: lw          $v1, 0x1B18($at)
    ctx->r3 = MEM_W(ctx->r1, 0X1B18);
    // 0x8008DE08: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x8008DE0C: div         $zero, $v0, $a3
    if (S32(ctx->r7) != 0) { lo = S32(S64(S32(ctx->r2)) / S64(S32(ctx->r7))); hi = S32(S64(S32(ctx->r2)) % S64(S32(ctx->r7))); } else { lo = 0; hi = S32(ctx->r2); }
    // 0x8008DE10: bne         $a3, $zero, L_8008DE1C
    if (ctx->r7 != 0) {
        // 0x8008DE14: nop
    
            goto L_8008DE1C;
    }
    // 0x8008DE14: nop

    // 0x8008DE18: break       7
    do_break(2148064792);
L_8008DE1C:
    // 0x8008DE1C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8008DE20: bne         $a3, $at, L_8008DE34
    if (ctx->r7 != ctx->r1) {
        // 0x8008DE24: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8008DE34;
    }
    // 0x8008DE24: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8008DE28: bne         $v0, $at, L_8008DE34
    if (ctx->r2 != ctx->r1) {
        // 0x8008DE2C: nop
    
            goto L_8008DE34;
    }
    // 0x8008DE2C: nop

    // 0x8008DE30: break       6
    do_break(2148064816);
L_8008DE34:
    // 0x8008DE34: mflo        $v0
    ctx->r2 = lo;
    // 0x8008DE38: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x8008DE3C: addu        $at, $at, $a0
    ctx->r1 = ADD32(ctx->r1, ctx->r4);
    // 0x8008DE40: sw          $t0, 0x1B28($at)
    MEM_W(0X1B28, ctx->r1) = ctx->r8;
    // 0x8008DE44: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x8008DE48: addu        $at, $at, $a0
    ctx->r1 = ADD32(ctx->r1, ctx->r4);
    // 0x8008DE4C: sw          $v0, 0x1B20($at)
    MEM_W(0X1B20, ctx->r1) = ctx->r2;
    // 0x8008DE50: addiu       $a1, $a1, 0x28
    ctx->r5 = ADD32(ctx->r5, 0X28);
L_8008DE54:
    // 0x8008DE54: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x8008DE58: sltiu       $v0, $a2, 0x20
    ctx->r2 = ctx->r6 < 0X20 ? 1 : 0;
    // 0x8008DE5C: bne         $v0, $zero, L_8008DDD0
    if (ctx->r2 != 0) {
        // 0x8008DE60: addiu       $a0, $a0, 0x28
        ctx->r4 = ADD32(ctx->r4, 0X28);
            goto L_8008DDD0;
    }
    // 0x8008DE60: addiu       $a0, $a0, 0x28
    ctx->r4 = ADD32(ctx->r4, 0X28);
    // 0x8008DE64: j           L_8008E0A4
    // 0x8008DE68: nop

        goto L_8008E0A4;
    // 0x8008DE68: nop

L_8008DE6C:
    // 0x8008DE6C: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // 0x8008DE70: andi        $v0, $a0, 0xFF
    ctx->r2 = ctx->r4 & 0XFF;
    // 0x8008DE74: sll         $t2, $v0, 16
    ctx->r10 = S32(ctx->r2 << 16);
    // 0x8008DE78: lw          $t1, 0x0($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X0);
    // 0x8008DE7C: andi        $a3, $t0, 0xFFFF
    ctx->r7 = ctx->r8 & 0XFFFF;
    // 0x8008DE80: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x8008DE84: lui         $a1, 0x8014
    ctx->r5 = S32(0X8014 << 16);
    // 0x8008DE88: addiu       $a1, $a1, 0x1B1C
    ctx->r5 = ADD32(ctx->r5, 0X1B1C);
    // 0x8008DE8C: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
L_8008DE90:
    // 0x8008DE90: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x8008DE94: addu        $at, $at, $a0
    ctx->r1 = ADD32(ctx->r1, ctx->r4);
    // 0x8008DE98: lbu         $v0, 0x1B2C($at)
    ctx->r2 = MEM_BU(ctx->r1, 0X1B2C);
    // 0x8008DE9C: addiu       $v0, $v0, -0x2
    ctx->r2 = ADD32(ctx->r2, -0X2);
    // 0x8008DEA0: sltiu       $v0, $v0, 0x2
    ctx->r2 = ctx->r2 < 0X2 ? 1 : 0;
    // 0x8008DEA4: beql        $v0, $zero, L_8008DF18
    if (ctx->r2 == 0) {
        // 0x8008DEA8: addiu       $a1, $a1, 0x28
        ctx->r5 = ADD32(ctx->r5, 0X28);
            goto L_8008DF18;
    }
    goto skip_2;
    // 0x8008DEA8: addiu       $a1, $a1, 0x28
    ctx->r5 = ADD32(ctx->r5, 0X28);
    skip_2:
    // 0x8008DEAC: sw          $t2, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r10;
    // 0x8008DEB0: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x8008DEB4: addu        $at, $at, $a0
    ctx->r1 = ADD32(ctx->r1, ctx->r4);
    // 0x8008DEB8: sw          $t1, 0x1B24($at)
    MEM_W(0X1B24, ctx->r1) = ctx->r9;
    // 0x8008DEBC: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x8008DEC0: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x8008DEC4: addu        $at, $at, $a0
    ctx->r1 = ADD32(ctx->r1, ctx->r4);
    // 0x8008DEC8: lw          $v1, 0x1B18($at)
    ctx->r3 = MEM_W(ctx->r1, 0X1B18);
    // 0x8008DECC: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x8008DED0: div         $zero, $v0, $a3
    if (S32(ctx->r7) != 0) { lo = S32(S64(S32(ctx->r2)) / S64(S32(ctx->r7))); hi = S32(S64(S32(ctx->r2)) % S64(S32(ctx->r7))); } else { lo = 0; hi = S32(ctx->r2); }
    // 0x8008DED4: bne         $a3, $zero, L_8008DEE0
    if (ctx->r7 != 0) {
        // 0x8008DED8: nop
    
            goto L_8008DEE0;
    }
    // 0x8008DED8: nop

    // 0x8008DEDC: break       7
    do_break(2148064988);
L_8008DEE0:
    // 0x8008DEE0: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8008DEE4: bne         $a3, $at, L_8008DEF8
    if (ctx->r7 != ctx->r1) {
        // 0x8008DEE8: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8008DEF8;
    }
    // 0x8008DEE8: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8008DEEC: bne         $v0, $at, L_8008DEF8
    if (ctx->r2 != ctx->r1) {
        // 0x8008DEF0: nop
    
            goto L_8008DEF8;
    }
    // 0x8008DEF0: nop

    // 0x8008DEF4: break       6
    do_break(2148065012);
L_8008DEF8:
    // 0x8008DEF8: mflo        $v0
    ctx->r2 = lo;
    // 0x8008DEFC: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x8008DF00: addu        $at, $at, $a0
    ctx->r1 = ADD32(ctx->r1, ctx->r4);
    // 0x8008DF04: sw          $t0, 0x1B28($at)
    MEM_W(0X1B28, ctx->r1) = ctx->r8;
    // 0x8008DF08: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x8008DF0C: addu        $at, $at, $a0
    ctx->r1 = ADD32(ctx->r1, ctx->r4);
    // 0x8008DF10: sw          $v0, 0x1B20($at)
    MEM_W(0X1B20, ctx->r1) = ctx->r2;
    // 0x8008DF14: addiu       $a1, $a1, 0x28
    ctx->r5 = ADD32(ctx->r5, 0X28);
L_8008DF18:
    // 0x8008DF18: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x8008DF1C: sltiu       $v0, $a2, 0x20
    ctx->r2 = ctx->r6 < 0X20 ? 1 : 0;
    // 0x8008DF20: bne         $v0, $zero, L_8008DE90
    if (ctx->r2 != 0) {
        // 0x8008DF24: addiu       $a0, $a0, 0x28
        ctx->r4 = ADD32(ctx->r4, 0X28);
            goto L_8008DE90;
    }
    // 0x8008DF24: addiu       $a0, $a0, 0x28
    ctx->r4 = ADD32(ctx->r4, 0X28);
    // 0x8008DF28: j           L_8008E0A4
    // 0x8008DF2C: nop

        goto L_8008E0A4;
    // 0x8008DF2C: nop

L_8008DF30:
    // 0x8008DF30: j           L_8008DF4C
    // 0x8008DF34: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
        goto L_8008DF4C;
    // 0x8008DF34: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
L_8008DF38:
    // 0x8008DF38: j           L_8008DF4C
    // 0x8008DF3C: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
        goto L_8008DF4C;
    // 0x8008DF3C: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
L_8008DF40:
    // 0x8008DF40: j           L_8008DF4C
    // 0x8008DF44: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
        goto L_8008DF4C;
    // 0x8008DF44: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_8008DF48:
    // 0x8008DF48: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8008DF4C:
    // 0x8008DF4C: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // 0x8008DF50: andi        $t3, $v0, 0xFF
    ctx->r11 = ctx->r2 & 0XFF;
    // 0x8008DF54: andi        $v0, $a0, 0xFF
    ctx->r2 = ctx->r4 & 0XFF;
    // 0x8008DF58: sll         $t2, $v0, 16
    ctx->r10 = S32(ctx->r2 << 16);
    // 0x8008DF5C: lw          $t1, 0x0($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X0);
    // 0x8008DF60: andi        $a3, $t0, 0xFFFF
    ctx->r7 = ctx->r8 & 0XFFFF;
    // 0x8008DF64: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x8008DF68: lui         $a1, 0x8014
    ctx->r5 = S32(0X8014 << 16);
    // 0x8008DF6C: addiu       $a1, $a1, 0x1B1C
    ctx->r5 = ADD32(ctx->r5, 0X1B1C);
    // 0x8008DF70: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
L_8008DF74:
    // 0x8008DF74: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x8008DF78: addu        $at, $at, $a0
    ctx->r1 = ADD32(ctx->r1, ctx->r4);
    // 0x8008DF7C: lbu         $v0, 0x1B2C($at)
    ctx->r2 = MEM_BU(ctx->r1, 0X1B2C);
    // 0x8008DF80: bnel        $v0, $t3, L_8008DFF4
    if (ctx->r2 != ctx->r11) {
        // 0x8008DF84: addiu       $a1, $a1, 0x28
        ctx->r5 = ADD32(ctx->r5, 0X28);
            goto L_8008DFF4;
    }
    goto skip_3;
    // 0x8008DF84: addiu       $a1, $a1, 0x28
    ctx->r5 = ADD32(ctx->r5, 0X28);
    skip_3:
    // 0x8008DF88: sw          $t2, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r10;
    // 0x8008DF8C: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x8008DF90: addu        $at, $at, $a0
    ctx->r1 = ADD32(ctx->r1, ctx->r4);
    // 0x8008DF94: sw          $t1, 0x1B24($at)
    MEM_W(0X1B24, ctx->r1) = ctx->r9;
    // 0x8008DF98: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x8008DF9C: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x8008DFA0: addu        $at, $at, $a0
    ctx->r1 = ADD32(ctx->r1, ctx->r4);
    // 0x8008DFA4: lw          $v1, 0x1B18($at)
    ctx->r3 = MEM_W(ctx->r1, 0X1B18);
    // 0x8008DFA8: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x8008DFAC: div         $zero, $v0, $a3
    if (S32(ctx->r7) != 0) { lo = S32(S64(S32(ctx->r2)) / S64(S32(ctx->r7))); hi = S32(S64(S32(ctx->r2)) % S64(S32(ctx->r7))); } else { lo = 0; hi = S32(ctx->r2); }
    // 0x8008DFB0: bne         $a3, $zero, L_8008DFBC
    if (ctx->r7 != 0) {
        // 0x8008DFB4: nop
    
            goto L_8008DFBC;
    }
    // 0x8008DFB4: nop

    // 0x8008DFB8: break       7
    do_break(2148065208);
L_8008DFBC:
    // 0x8008DFBC: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8008DFC0: bne         $a3, $at, L_8008DFD4
    if (ctx->r7 != ctx->r1) {
        // 0x8008DFC4: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8008DFD4;
    }
    // 0x8008DFC4: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8008DFC8: bne         $v0, $at, L_8008DFD4
    if (ctx->r2 != ctx->r1) {
        // 0x8008DFCC: nop
    
            goto L_8008DFD4;
    }
    // 0x8008DFCC: nop

    // 0x8008DFD0: break       6
    do_break(2148065232);
L_8008DFD4:
    // 0x8008DFD4: mflo        $v0
    ctx->r2 = lo;
    // 0x8008DFD8: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x8008DFDC: addu        $at, $at, $a0
    ctx->r1 = ADD32(ctx->r1, ctx->r4);
    // 0x8008DFE0: sw          $t0, 0x1B28($at)
    MEM_W(0X1B28, ctx->r1) = ctx->r8;
    // 0x8008DFE4: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x8008DFE8: addu        $at, $at, $a0
    ctx->r1 = ADD32(ctx->r1, ctx->r4);
    // 0x8008DFEC: sw          $v0, 0x1B20($at)
    MEM_W(0X1B20, ctx->r1) = ctx->r2;
    // 0x8008DFF0: addiu       $a1, $a1, 0x28
    ctx->r5 = ADD32(ctx->r5, 0X28);
L_8008DFF4:
    // 0x8008DFF4: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x8008DFF8: sltiu       $v0, $a2, 0x20
    ctx->r2 = ctx->r6 < 0X20 ? 1 : 0;
    // 0x8008DFFC: bne         $v0, $zero, L_8008DF74
    if (ctx->r2 != 0) {
        // 0x8008E000: addiu       $a0, $a0, 0x28
        ctx->r4 = ADD32(ctx->r4, 0X28);
            goto L_8008DF74;
    }
    // 0x8008E000: addiu       $a0, $a0, 0x28
    ctx->r4 = ADD32(ctx->r4, 0X28);
    // 0x8008E004: j           L_8008E0A4
    // 0x8008E008: nop

        goto L_8008E0A4;
    // 0x8008E008: nop

L_8008E00C:
    // 0x8008E00C: sll         $v1, $a2, 2
    ctx->r3 = S32(ctx->r6 << 2);
    // 0x8008E010: addu        $v1, $v1, $a2
    ctx->r3 = ADD32(ctx->r3, ctx->r6);
    // 0x8008E014: sll         $v1, $v1, 3
    ctx->r3 = S32(ctx->r3 << 3);
    // 0x8008E018: andi        $v0, $a0, 0xFF
    ctx->r2 = ctx->r4 & 0XFF;
    // 0x8008E01C: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x8008E020: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x8008E024: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x8008E028: sw          $v0, 0x1B1C($at)
    MEM_W(0X1B1C, ctx->r1) = ctx->r2;
    // 0x8008E02C: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x8008E030: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x8008E034: lw          $v0, 0x1B1C($at)
    ctx->r2 = MEM_W(ctx->r1, 0X1B1C);
    // 0x8008E038: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x8008E03C: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x8008E040: lw          $a0, 0x1B18($at)
    ctx->r4 = MEM_W(ctx->r1, 0X1B18);
    // 0x8008E044: subu        $v0, $v0, $a0
    ctx->r2 = SUB32(ctx->r2, ctx->r4);
    // 0x8008E048: div         $zero, $v0, $a1
    if (S32(ctx->r5) != 0) { lo = S32(S64(S32(ctx->r2)) / S64(S32(ctx->r5))); hi = S32(S64(S32(ctx->r2)) % S64(S32(ctx->r5))); } else { lo = 0; hi = S32(ctx->r2); }
    // 0x8008E04C: bne         $a1, $zero, L_8008E058
    if (ctx->r5 != 0) {
        // 0x8008E050: nop
    
            goto L_8008E058;
    }
    // 0x8008E050: nop

    // 0x8008E054: break       7
    do_break(2148065364);
L_8008E058:
    // 0x8008E058: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8008E05C: bne         $a1, $at, L_8008E070
    if (ctx->r5 != ctx->r1) {
        // 0x8008E060: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8008E070;
    }
    // 0x8008E060: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8008E064: bne         $v0, $at, L_8008E070
    if (ctx->r2 != ctx->r1) {
        // 0x8008E068: nop
    
            goto L_8008E070;
    }
    // 0x8008E068: nop

    // 0x8008E06C: break       6
    do_break(2148065388);
L_8008E070:
    // 0x8008E070: mflo        $v0
    ctx->r2 = lo;
    // 0x8008E074: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x8008E078: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x8008E07C: sw          $t1, 0x1B24($at)
    MEM_W(0X1B24, ctx->r1) = ctx->r9;
    // 0x8008E080: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x8008E084: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x8008E088: sb          $a3, 0x1B2D($at)
    MEM_B(0X1B2D, ctx->r1) = ctx->r7;
    // 0x8008E08C: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x8008E090: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x8008E094: sw          $t2, 0x1B28($at)
    MEM_W(0X1B28, ctx->r1) = ctx->r10;
    // 0x8008E098: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x8008E09C: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x8008E0A0: sw          $v0, 0x1B20($at)
    MEM_W(0X1B20, ctx->r1) = ctx->r2;
L_8008E0A4:
    // 0x8008E0A4: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    // 0x8008E0A8: jr          $ra
    // 0x8008E0AC: nop

    return;
    // 0x8008E0AC: nop

;}
RECOMP_FUNC void func_8008E0B0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008E0B0: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x8008E0B4: lbu         $v0, 0xF50($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0XF50);
    // 0x8008E0B8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8008E0BC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8008E0C0: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x8008E0C4: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8008E0C8: addu        $s1, $a1, $zero
    ctx->r17 = ADD32(ctx->r5, 0);
    // 0x8008E0CC: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8008E0D0: addu        $s2, $a2, $zero
    ctx->r18 = ADD32(ctx->r6, 0);
    // 0x8008E0D4: beq         $v0, $zero, L_8008E104
    if (ctx->r2 == 0) {
        // 0x8008E0D8: sw          $ra, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r31;
            goto L_8008E104;
    }
    // 0x8008E0D8: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8008E0DC: jal         0x80092010
    // 0x8008E0E0: nop

    func_80092010(rdram, ctx);
        goto after_0;
    // 0x8008E0E0: nop

    after_0:
    // 0x8008E0E4: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x8008E0E8: andi        $a0, $s0, 0xFF
    ctx->r4 = ctx->r16 & 0XFF;
    // 0x8008E0EC: andi        $a1, $s1, 0xFFFF
    ctx->r5 = ctx->r17 & 0XFFFF;
    // 0x8008E0F0: andi        $a2, $s2, 0xFF
    ctx->r6 = ctx->r18 & 0XFF;
    // 0x8008E0F4: jal         0x8008DD60
    // 0x8008E0F8: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    func_8008DD60(rdram, ctx);
        goto after_1;
    // 0x8008E0F8: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    after_1:
    // 0x8008E0FC: jal         0x8009205C
    // 0x8008E100: nop

    func_8009205C(rdram, ctx);
        goto after_2;
    // 0x8008E100: nop

    after_2:
L_8008E104:
    // 0x8008E104: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8008E108: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8008E10C: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8008E110: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8008E114: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8008E118: jr          $ra
    // 0x8008E11C: nop

    return;
    // 0x8008E11C: nop

;}
RECOMP_FUNC void func_8008E120(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008E120: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x8008E124: lbu         $v0, 0xF50($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0XF50);
    // 0x8008E128: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8008E12C: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8008E130: addu        $s1, $a0, $zero
    ctx->r17 = ADD32(ctx->r4, 0);
    // 0x8008E134: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8008E138: addu        $s2, $a1, $zero
    ctx->r18 = ADD32(ctx->r5, 0);
    // 0x8008E13C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8008E140: addu        $s0, $a2, $zero
    ctx->r16 = ADD32(ctx->r6, 0);
    // 0x8008E144: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x8008E148: addu        $s3, $a3, $zero
    ctx->r19 = ADD32(ctx->r7, 0);
    // 0x8008E14C: beq         $v0, $zero, L_8008E1A4
    if (ctx->r2 == 0) {
        // 0x8008E150: sw          $ra, 0x28($sp)
        MEM_W(0X28, ctx->r29) = ctx->r31;
            goto L_8008E1A4;
    }
    // 0x8008E150: sw          $ra, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r31;
    // 0x8008E154: jal         0x80092010
    // 0x8008E158: nop

    func_80092010(rdram, ctx);
        goto after_0;
    // 0x8008E158: nop

    after_0:
    // 0x8008E15C: andi        $v0, $s0, 0xFF
    ctx->r2 = ctx->r16 & 0XFF;
    // 0x8008E160: beq         $v0, $zero, L_8008E17C
    if (ctx->r2 == 0) {
        // 0x8008E164: andi        $a0, $s1, 0xFF
        ctx->r4 = ctx->r17 & 0XFF;
            goto L_8008E17C;
    }
    // 0x8008E164: andi        $a0, $s1, 0xFF
    ctx->r4 = ctx->r17 & 0XFF;
    // 0x8008E168: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x8008E16C: andi        $a1, $s2, 0xFFFF
    ctx->r5 = ctx->r18 & 0XFFFF;
    // 0x8008E170: addiu       $a2, $zero, 0x15
    ctx->r6 = ADD32(0, 0X15);
    // 0x8008E174: jal         0x8008DD60
    // 0x8008E178: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    func_8008DD60(rdram, ctx);
        goto after_1;
    // 0x8008E178: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    after_1:
L_8008E17C:
    // 0x8008E17C: andi        $v0, $s3, 0xFF
    ctx->r2 = ctx->r19 & 0XFF;
    // 0x8008E180: beq         $v0, $zero, L_8008E19C
    if (ctx->r2 == 0) {
        // 0x8008E184: andi        $a0, $s1, 0xFF
        ctx->r4 = ctx->r17 & 0XFF;
            goto L_8008E19C;
    }
    // 0x8008E184: andi        $a0, $s1, 0xFF
    ctx->r4 = ctx->r17 & 0XFF;
    // 0x8008E188: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x8008E18C: andi        $a1, $s2, 0xFFFF
    ctx->r5 = ctx->r18 & 0XFFFF;
    // 0x8008E190: addiu       $a2, $zero, 0x16
    ctx->r6 = ADD32(0, 0X16);
    // 0x8008E194: jal         0x8008DD60
    // 0x8008E198: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    func_8008DD60(rdram, ctx);
        goto after_2;
    // 0x8008E198: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    after_2:
L_8008E19C:
    // 0x8008E19C: jal         0x8009205C
    // 0x8008E1A0: nop

    func_8009205C(rdram, ctx);
        goto after_3;
    // 0x8008E1A0: nop

    after_3:
L_8008E1A4:
    // 0x8008E1A4: lw          $ra, 0x28($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X28);
    // 0x8008E1A8: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x8008E1AC: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8008E1B0: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8008E1B4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8008E1B8: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8008E1BC: jr          $ra
    // 0x8008E1C0: nop

    return;
    // 0x8008E1C0: nop

;}
RECOMP_FUNC void func_8008E1C4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008E1C4: andi        $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 & 0XFF;
    // 0x8008E1C8: sll         $v0, $a0, 2
    ctx->r2 = S32(ctx->r4 << 2);
    // 0x8008E1CC: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x8008E1D0: sll         $a1, $v0, 3
    ctx->r5 = S32(ctx->r2 << 3);
    // 0x8008E1D4: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x8008E1D8: addu        $at, $at, $a1
    ctx->r1 = ADD32(ctx->r1, ctx->r5);
    // 0x8008E1DC: lbu         $a0, 0x1B2C($at)
    ctx->r4 = MEM_BU(ctx->r1, 0X1B2C);
    // 0x8008E1E0: addiu       $v1, $zero, 0x4
    ctx->r3 = ADD32(0, 0X4);
    // 0x8008E1E4: beq         $a0, $v1, L_8008E210
    if (ctx->r4 == ctx->r3) {
        // 0x8008E1E8: addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
            goto L_8008E210;
    }
    // 0x8008E1E8: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // 0x8008E1EC: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x8008E1F0: addu        $at, $at, $a1
    ctx->r1 = ADD32(ctx->r1, ctx->r5);
    // 0x8008E1F4: lw          $v1, 0x1B24($at)
    ctx->r3 = MEM_W(ctx->r1, 0X1B24);
    // 0x8008E1F8: beq         $v1, $zero, L_8008E210
    if (ctx->r3 == 0) {
        // 0x8008E1FC: nop
    
            goto L_8008E210;
    }
    // 0x8008E1FC: nop

    // 0x8008E200: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x8008E204: addu        $at, $at, $a1
    ctx->r1 = ADD32(ctx->r1, ctx->r5);
    // 0x8008E208: lw          $v0, 0x1B20($at)
    ctx->r2 = MEM_W(ctx->r1, 0X1B20);
    // 0x8008E20C: srl         $v0, $v0, 31
    ctx->r2 = S32(U32(ctx->r2) >> 31);
L_8008E210:
    // 0x8008E210: jr          $ra
    // 0x8008E214: nop

    return;
    // 0x8008E214: nop

;}
RECOMP_FUNC void func_8008E218(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008E218: addu        $t0, $a1, $zero
    ctx->r8 = ADD32(ctx->r5, 0);
    // 0x8008E21C: andi        $v0, $t0, 0xFFFF
    ctx->r2 = ctx->r8 & 0XFFFF;
    // 0x8008E220: bne         $v0, $zero, L_8008E22C
    if (ctx->r2 != 0) {
        // 0x8008E224: addiu       $sp, $sp, -0x8
        ctx->r29 = ADD32(ctx->r29, -0X8);
            goto L_8008E22C;
    }
    // 0x8008E224: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x8008E228: addiu       $t0, $a1, 0x1
    ctx->r8 = ADD32(ctx->r5, 0X1);
L_8008E22C:
    // 0x8008E22C: andi        $a3, $t0, 0xFFFF
    ctx->r7 = ctx->r8 & 0XFFFF;
    // 0x8008E230: sll         $a1, $a3, 8
    ctx->r5 = S32(ctx->r7 << 8);
    // 0x8008E234: andi        $v1, $a2, 0xFF
    ctx->r3 = ctx->r6 & 0XFF;
    // 0x8008E238: addiu       $v0, $zero, 0xFE
    ctx->r2 = ADD32(0, 0XFE);
    // 0x8008E23C: beq         $v1, $v0, L_8008E3A4
    if (ctx->r3 == ctx->r2) {
        // 0x8008E240: sw          $a1, 0x0($sp)
        MEM_W(0X0, ctx->r29) = ctx->r5;
            goto L_8008E3A4;
    }
    // 0x8008E240: sw          $a1, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r5;
    // 0x8008E244: slti        $v0, $v1, 0xFF
    ctx->r2 = SIGNED(ctx->r3) < 0XFF ? 1 : 0;
    // 0x8008E248: beq         $v0, $zero, L_8008E260
    if (ctx->r2 == 0) {
        // 0x8008E24C: addiu       $v0, $zero, 0xFD
        ctx->r2 = ADD32(0, 0XFD);
            goto L_8008E260;
    }
    // 0x8008E24C: addiu       $v0, $zero, 0xFD
    ctx->r2 = ADD32(0, 0XFD);
    // 0x8008E250: beql        $v1, $v0, L_8008E300
    if (ctx->r3 == ctx->r2) {
        // 0x8008E254: addu        $a2, $zero, $zero
        ctx->r6 = ADD32(0, 0);
            goto L_8008E300;
    }
    goto skip_0;
    // 0x8008E254: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    skip_0:
    // 0x8008E258: j           L_8008E450
    // 0x8008E25C: andi        $v0, $a2, 0xFF
    ctx->r2 = ctx->r6 & 0XFF;
        goto L_8008E450;
    // 0x8008E25C: andi        $v0, $a2, 0xFF
    ctx->r2 = ctx->r6 & 0XFF;
L_8008E260:
    // 0x8008E260: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // 0x8008E264: bne         $v1, $v0, L_8008E450
    if (ctx->r3 != ctx->r2) {
        // 0x8008E268: andi        $v0, $a2, 0xFF
        ctx->r2 = ctx->r6 & 0XFF;
            goto L_8008E450;
    }
    // 0x8008E268: andi        $v0, $a2, 0xFF
    ctx->r2 = ctx->r6 & 0XFF;
    // 0x8008E26C: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // 0x8008E270: andi        $v0, $a0, 0xFF
    ctx->r2 = ctx->r4 & 0XFF;
    // 0x8008E274: sll         $t1, $v0, 16
    ctx->r9 = S32(ctx->r2 << 16);
    // 0x8008E278: addu        $t0, $a1, $zero
    ctx->r8 = ADD32(ctx->r5, 0);
    // 0x8008E27C: lui         $a1, 0x8014
    ctx->r5 = S32(0X8014 << 16);
    // 0x8008E280: addiu       $a1, $a1, 0x1B34
    ctx->r5 = ADD32(ctx->r5, 0X1B34);
    // 0x8008E284: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
L_8008E288:
    // 0x8008E288: sw          $t1, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r9;
    // 0x8008E28C: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x8008E290: addu        $at, $at, $a0
    ctx->r1 = ADD32(ctx->r1, ctx->r4);
    // 0x8008E294: sw          $t0, 0x1B3C($at)
    MEM_W(0X1B3C, ctx->r1) = ctx->r8;
    // 0x8008E298: lw          $v1, 0x0($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X0);
    // 0x8008E29C: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x8008E2A0: addu        $at, $at, $a0
    ctx->r1 = ADD32(ctx->r1, ctx->r4);
    // 0x8008E2A4: lw          $v0, 0x1B30($at)
    ctx->r2 = MEM_W(ctx->r1, 0X1B30);
    // 0x8008E2A8: subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // 0x8008E2AC: div         $zero, $v1, $a3
    if (S32(ctx->r7) != 0) { lo = S32(S64(S32(ctx->r3)) / S64(S32(ctx->r7))); hi = S32(S64(S32(ctx->r3)) % S64(S32(ctx->r7))); } else { lo = 0; hi = S32(ctx->r3); }
    // 0x8008E2B0: bne         $a3, $zero, L_8008E2BC
    if (ctx->r7 != 0) {
        // 0x8008E2B4: nop
    
            goto L_8008E2BC;
    }
    // 0x8008E2B4: nop

    // 0x8008E2B8: break       7
    do_break(2148065976);
L_8008E2BC:
    // 0x8008E2BC: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8008E2C0: bne         $a3, $at, L_8008E2D4
    if (ctx->r7 != ctx->r1) {
        // 0x8008E2C4: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8008E2D4;
    }
    // 0x8008E2C4: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8008E2C8: bne         $v1, $at, L_8008E2D4
    if (ctx->r3 != ctx->r1) {
        // 0x8008E2CC: nop
    
            goto L_8008E2D4;
    }
    // 0x8008E2CC: nop

    // 0x8008E2D0: break       6
    do_break(2148066000);
L_8008E2D4:
    // 0x8008E2D4: mflo        $v1
    ctx->r3 = lo;
    // 0x8008E2D8: addiu       $a1, $a1, 0x28
    ctx->r5 = ADD32(ctx->r5, 0X28);
    // 0x8008E2DC: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x8008E2E0: sltiu       $v0, $a2, 0x20
    ctx->r2 = ctx->r6 < 0X20 ? 1 : 0;
    // 0x8008E2E4: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x8008E2E8: addu        $at, $at, $a0
    ctx->r1 = ADD32(ctx->r1, ctx->r4);
    // 0x8008E2EC: sw          $v1, 0x1B38($at)
    MEM_W(0X1B38, ctx->r1) = ctx->r3;
    // 0x8008E2F0: bne         $v0, $zero, L_8008E288
    if (ctx->r2 != 0) {
        // 0x8008E2F4: addiu       $a0, $a0, 0x28
        ctx->r4 = ADD32(ctx->r4, 0X28);
            goto L_8008E288;
    }
    // 0x8008E2F4: addiu       $a0, $a0, 0x28
    ctx->r4 = ADD32(ctx->r4, 0X28);
    // 0x8008E2F8: j           L_8008E4D8
    // 0x8008E2FC: nop

        goto L_8008E4D8;
    // 0x8008E2FC: nop

L_8008E300:
    // 0x8008E300: andi        $v0, $a0, 0xFF
    ctx->r2 = ctx->r4 & 0XFF;
    // 0x8008E304: sll         $t1, $v0, 16
    ctx->r9 = S32(ctx->r2 << 16);
    // 0x8008E308: addu        $t0, $a1, $zero
    ctx->r8 = ADD32(ctx->r5, 0);
    // 0x8008E30C: lui         $a1, 0x8014
    ctx->r5 = S32(0X8014 << 16);
    // 0x8008E310: addiu       $a1, $a1, 0x1B34
    ctx->r5 = ADD32(ctx->r5, 0X1B34);
    // 0x8008E314: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
L_8008E318:
    // 0x8008E318: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x8008E31C: addu        $at, $at, $a0
    ctx->r1 = ADD32(ctx->r1, ctx->r4);
    // 0x8008E320: lbu         $v0, 0x1B2C($at)
    ctx->r2 = MEM_BU(ctx->r1, 0X1B2C);
    // 0x8008E324: bnel        $v0, $zero, L_8008E38C
    if (ctx->r2 != 0) {
        // 0x8008E328: addiu       $a1, $a1, 0x28
        ctx->r5 = ADD32(ctx->r5, 0X28);
            goto L_8008E38C;
    }
    goto skip_1;
    // 0x8008E328: addiu       $a1, $a1, 0x28
    ctx->r5 = ADD32(ctx->r5, 0X28);
    skip_1:
    // 0x8008E32C: sw          $t1, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r9;
    // 0x8008E330: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x8008E334: addu        $at, $at, $a0
    ctx->r1 = ADD32(ctx->r1, ctx->r4);
    // 0x8008E338: sw          $t0, 0x1B3C($at)
    MEM_W(0X1B3C, ctx->r1) = ctx->r8;
    // 0x8008E33C: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x8008E340: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x8008E344: addu        $at, $at, $a0
    ctx->r1 = ADD32(ctx->r1, ctx->r4);
    // 0x8008E348: lw          $v1, 0x1B30($at)
    ctx->r3 = MEM_W(ctx->r1, 0X1B30);
    // 0x8008E34C: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x8008E350: div         $zero, $v0, $a3
    if (S32(ctx->r7) != 0) { lo = S32(S64(S32(ctx->r2)) / S64(S32(ctx->r7))); hi = S32(S64(S32(ctx->r2)) % S64(S32(ctx->r7))); } else { lo = 0; hi = S32(ctx->r2); }
    // 0x8008E354: bne         $a3, $zero, L_8008E360
    if (ctx->r7 != 0) {
        // 0x8008E358: nop
    
            goto L_8008E360;
    }
    // 0x8008E358: nop

    // 0x8008E35C: break       7
    do_break(2148066140);
L_8008E360:
    // 0x8008E360: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8008E364: bne         $a3, $at, L_8008E378
    if (ctx->r7 != ctx->r1) {
        // 0x8008E368: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8008E378;
    }
    // 0x8008E368: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8008E36C: bne         $v0, $at, L_8008E378
    if (ctx->r2 != ctx->r1) {
        // 0x8008E370: nop
    
            goto L_8008E378;
    }
    // 0x8008E370: nop

    // 0x8008E374: break       6
    do_break(2148066164);
L_8008E378:
    // 0x8008E378: mflo        $v0
    ctx->r2 = lo;
    // 0x8008E37C: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x8008E380: addu        $at, $at, $a0
    ctx->r1 = ADD32(ctx->r1, ctx->r4);
    // 0x8008E384: sw          $v0, 0x1B38($at)
    MEM_W(0X1B38, ctx->r1) = ctx->r2;
    // 0x8008E388: addiu       $a1, $a1, 0x28
    ctx->r5 = ADD32(ctx->r5, 0X28);
L_8008E38C:
    // 0x8008E38C: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x8008E390: sltiu       $v0, $a2, 0x20
    ctx->r2 = ctx->r6 < 0X20 ? 1 : 0;
    // 0x8008E394: bne         $v0, $zero, L_8008E318
    if (ctx->r2 != 0) {
        // 0x8008E398: addiu       $a0, $a0, 0x28
        ctx->r4 = ADD32(ctx->r4, 0X28);
            goto L_8008E318;
    }
    // 0x8008E398: addiu       $a0, $a0, 0x28
    ctx->r4 = ADD32(ctx->r4, 0X28);
    // 0x8008E39C: j           L_8008E4D8
    // 0x8008E3A0: nop

        goto L_8008E4D8;
    // 0x8008E3A0: nop

L_8008E3A4:
    // 0x8008E3A4: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // 0x8008E3A8: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x8008E3AC: andi        $v0, $a0, 0xFF
    ctx->r2 = ctx->r4 & 0XFF;
    // 0x8008E3B0: sll         $t1, $v0, 16
    ctx->r9 = S32(ctx->r2 << 16);
    // 0x8008E3B4: addu        $t0, $a1, $zero
    ctx->r8 = ADD32(ctx->r5, 0);
    // 0x8008E3B8: lui         $a1, 0x8014
    ctx->r5 = S32(0X8014 << 16);
    // 0x8008E3BC: addiu       $a1, $a1, 0x1B34
    ctx->r5 = ADD32(ctx->r5, 0X1B34);
    // 0x8008E3C0: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
L_8008E3C4:
    // 0x8008E3C4: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x8008E3C8: addu        $at, $at, $a0
    ctx->r1 = ADD32(ctx->r1, ctx->r4);
    // 0x8008E3CC: lbu         $v0, 0x1B2C($at)
    ctx->r2 = MEM_BU(ctx->r1, 0X1B2C);
    // 0x8008E3D0: bnel        $v0, $t2, L_8008E438
    if (ctx->r2 != ctx->r10) {
        // 0x8008E3D4: addiu       $a1, $a1, 0x28
        ctx->r5 = ADD32(ctx->r5, 0X28);
            goto L_8008E438;
    }
    goto skip_2;
    // 0x8008E3D4: addiu       $a1, $a1, 0x28
    ctx->r5 = ADD32(ctx->r5, 0X28);
    skip_2:
    // 0x8008E3D8: sw          $t1, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r9;
    // 0x8008E3DC: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x8008E3E0: addu        $at, $at, $a0
    ctx->r1 = ADD32(ctx->r1, ctx->r4);
    // 0x8008E3E4: sw          $t0, 0x1B3C($at)
    MEM_W(0X1B3C, ctx->r1) = ctx->r8;
    // 0x8008E3E8: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x8008E3EC: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x8008E3F0: addu        $at, $at, $a0
    ctx->r1 = ADD32(ctx->r1, ctx->r4);
    // 0x8008E3F4: lw          $v1, 0x1B30($at)
    ctx->r3 = MEM_W(ctx->r1, 0X1B30);
    // 0x8008E3F8: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x8008E3FC: div         $zero, $v0, $a3
    if (S32(ctx->r7) != 0) { lo = S32(S64(S32(ctx->r2)) / S64(S32(ctx->r7))); hi = S32(S64(S32(ctx->r2)) % S64(S32(ctx->r7))); } else { lo = 0; hi = S32(ctx->r2); }
    // 0x8008E400: bne         $a3, $zero, L_8008E40C
    if (ctx->r7 != 0) {
        // 0x8008E404: nop
    
            goto L_8008E40C;
    }
    // 0x8008E404: nop

    // 0x8008E408: break       7
    do_break(2148066312);
L_8008E40C:
    // 0x8008E40C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8008E410: bne         $a3, $at, L_8008E424
    if (ctx->r7 != ctx->r1) {
        // 0x8008E414: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8008E424;
    }
    // 0x8008E414: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8008E418: bne         $v0, $at, L_8008E424
    if (ctx->r2 != ctx->r1) {
        // 0x8008E41C: nop
    
            goto L_8008E424;
    }
    // 0x8008E41C: nop

    // 0x8008E420: break       6
    do_break(2148066336);
L_8008E424:
    // 0x8008E424: mflo        $v0
    ctx->r2 = lo;
    // 0x8008E428: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x8008E42C: addu        $at, $at, $a0
    ctx->r1 = ADD32(ctx->r1, ctx->r4);
    // 0x8008E430: sw          $v0, 0x1B38($at)
    MEM_W(0X1B38, ctx->r1) = ctx->r2;
    // 0x8008E434: addiu       $a1, $a1, 0x28
    ctx->r5 = ADD32(ctx->r5, 0X28);
L_8008E438:
    // 0x8008E438: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x8008E43C: sltiu       $v0, $a2, 0x20
    ctx->r2 = ctx->r6 < 0X20 ? 1 : 0;
    // 0x8008E440: bne         $v0, $zero, L_8008E3C4
    if (ctx->r2 != 0) {
        // 0x8008E444: addiu       $a0, $a0, 0x28
        ctx->r4 = ADD32(ctx->r4, 0X28);
            goto L_8008E3C4;
    }
    // 0x8008E444: addiu       $a0, $a0, 0x28
    ctx->r4 = ADD32(ctx->r4, 0X28);
    // 0x8008E448: j           L_8008E4D8
    // 0x8008E44C: nop

        goto L_8008E4D8;
    // 0x8008E44C: nop

L_8008E450:
    // 0x8008E450: sll         $v1, $v0, 2
    ctx->r3 = S32(ctx->r2 << 2);
    // 0x8008E454: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x8008E458: sll         $v1, $v1, 3
    ctx->r3 = S32(ctx->r3 << 3);
    // 0x8008E45C: andi        $v0, $a0, 0xFF
    ctx->r2 = ctx->r4 & 0XFF;
    // 0x8008E460: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x8008E464: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x8008E468: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x8008E46C: sw          $v0, 0x1B34($at)
    MEM_W(0X1B34, ctx->r1) = ctx->r2;
    // 0x8008E470: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x8008E474: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x8008E478: lw          $a0, 0x1B34($at)
    ctx->r4 = MEM_W(ctx->r1, 0X1B34);
    // 0x8008E47C: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x8008E480: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x8008E484: lw          $v0, 0x1B30($at)
    ctx->r2 = MEM_W(ctx->r1, 0X1B30);
    // 0x8008E488: subu        $a0, $a0, $v0
    ctx->r4 = SUB32(ctx->r4, ctx->r2);
    // 0x8008E48C: andi        $v0, $t0, 0xFFFF
    ctx->r2 = ctx->r8 & 0XFFFF;
    // 0x8008E490: div         $zero, $a0, $v0
    if (S32(ctx->r2) != 0) { lo = S32(S64(S32(ctx->r4)) / S64(S32(ctx->r2))); hi = S32(S64(S32(ctx->r4)) % S64(S32(ctx->r2))); } else { lo = 0; hi = S32(ctx->r4); }
    // 0x8008E494: bne         $v0, $zero, L_8008E4A0
    if (ctx->r2 != 0) {
        // 0x8008E498: nop
    
            goto L_8008E4A0;
    }
    // 0x8008E498: nop

    // 0x8008E49C: break       7
    do_break(2148066460);
L_8008E4A0:
    // 0x8008E4A0: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8008E4A4: bne         $v0, $at, L_8008E4B8
    if (ctx->r2 != ctx->r1) {
        // 0x8008E4A8: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8008E4B8;
    }
    // 0x8008E4A8: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8008E4AC: bne         $a0, $at, L_8008E4B8
    if (ctx->r4 != ctx->r1) {
        // 0x8008E4B0: nop
    
            goto L_8008E4B8;
    }
    // 0x8008E4B0: nop

    // 0x8008E4B4: break       6
    do_break(2148066484);
L_8008E4B8:
    // 0x8008E4B8: mflo        $a0
    ctx->r4 = lo;
    // 0x8008E4BC: lw          $v0, 0x0($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X0);
    // 0x8008E4C0: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x8008E4C4: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x8008E4C8: sw          $v0, 0x1B3C($at)
    MEM_W(0X1B3C, ctx->r1) = ctx->r2;
    // 0x8008E4CC: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x8008E4D0: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x8008E4D4: sw          $a0, 0x1B38($at)
    MEM_W(0X1B38, ctx->r1) = ctx->r4;
L_8008E4D8:
    // 0x8008E4D8: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    // 0x8008E4DC: jr          $ra
    // 0x8008E4E0: nop

    return;
    // 0x8008E4E0: nop

;}
RECOMP_FUNC void func_8008E4E4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008E4E4: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x8008E4E8: lbu         $v0, 0xF50($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0XF50);
    // 0x8008E4EC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8008E4F0: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x8008E4F4: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x8008E4F8: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x8008E4FC: addu        $s1, $a1, $zero
    ctx->r17 = ADD32(ctx->r5, 0);
    // 0x8008E500: sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // 0x8008E504: addu        $s2, $a2, $zero
    ctx->r18 = ADD32(ctx->r6, 0);
    // 0x8008E508: beq         $v0, $zero, L_8008E530
    if (ctx->r2 == 0) {
        // 0x8008E50C: sw          $ra, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r31;
            goto L_8008E530;
    }
    // 0x8008E50C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8008E510: jal         0x80092010
    // 0x8008E514: nop

    func_80092010(rdram, ctx);
        goto after_0;
    // 0x8008E514: nop

    after_0:
    // 0x8008E518: andi        $a0, $s0, 0xFF
    ctx->r4 = ctx->r16 & 0XFF;
    // 0x8008E51C: andi        $a1, $s1, 0xFFFF
    ctx->r5 = ctx->r17 & 0XFFFF;
    // 0x8008E520: jal         0x8008E218
    // 0x8008E524: andi        $a2, $s2, 0xFF
    ctx->r6 = ctx->r18 & 0XFF;
    func_8008E218(rdram, ctx);
        goto after_1;
    // 0x8008E524: andi        $a2, $s2, 0xFF
    ctx->r6 = ctx->r18 & 0XFF;
    after_1:
    // 0x8008E528: jal         0x8009205C
    // 0x8008E52C: nop

    func_8009205C(rdram, ctx);
        goto after_2;
    // 0x8008E52C: nop

    after_2:
L_8008E530:
    // 0x8008E530: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8008E534: lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X18);
    // 0x8008E538: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x8008E53C: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x8008E540: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8008E544: jr          $ra
    // 0x8008E548: nop

    return;
    // 0x8008E548: nop

;}
RECOMP_FUNC void func_8008E54C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008E54C: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x8008E550: lbu         $v0, 0xF50($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0XF50);
    // 0x8008E554: beq         $v0, $zero, L_8008E574
    if (ctx->r2 == 0) {
        // 0x8008E558: andi        $v1, $a0, 0xFF
        ctx->r3 = ctx->r4 & 0XFF;
            goto L_8008E574;
    }
    // 0x8008E558: andi        $v1, $a0, 0xFF
    ctx->r3 = ctx->r4 & 0XFF;
    // 0x8008E55C: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x8008E560: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8008E564: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x8008E568: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x8008E56C: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x8008E570: sb          $a1, 0x1B2C($at)
    MEM_B(0X1B2C, ctx->r1) = ctx->r5;
L_8008E574:
    // 0x8008E574: jr          $ra
    // 0x8008E578: nop

    return;
    // 0x8008E578: nop

;}
RECOMP_FUNC void func_8008E57C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008E57C: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x8008E580: lbu         $v0, 0xF50($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0XF50);
    // 0x8008E584: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8008E588: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8008E58C: addu        $s1, $zero, $zero
    ctx->r17 = ADD32(0, 0);
    // 0x8008E590: sw          $ra, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r31;
    // 0x8008E594: beq         $v0, $zero, L_8008E5F4
    if (ctx->r2 == 0) {
        // 0x8008E598: sw          $s0, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r16;
            goto L_8008E5F4;
    }
    // 0x8008E598: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8008E59C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8008E5A0: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x8008E5A4: sb          $v0, -0x530C($at)
    MEM_B(-0X530C, ctx->r1) = ctx->r2;
    // 0x8008E5A8: jal         0x80092120
    // 0x8008E5AC: nop

    func_80092120(rdram, ctx);
        goto after_0;
    // 0x8008E5AC: nop

    after_0:
    // 0x8008E5B0: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x8008E5B4: bnel        $v0, $zero, L_8008E5EC
    if (ctx->r2 != 0) {
        // 0x8008E5B8: addiu       $s1, $zero, 0x1
        ctx->r17 = ADD32(0, 0X1);
            goto L_8008E5EC;
    }
    goto skip_0;
    // 0x8008E5B8: addiu       $s1, $zero, 0x1
    ctx->r17 = ADD32(0, 0X1);
    skip_0:
    // 0x8008E5BC: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x8008E5C0: lbu         $v0, 0x1AD0($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X1AD0);
    // 0x8008E5C4: blez        $v0, L_8008E5EC
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8008E5C8: addu        $s0, $zero, $zero
        ctx->r16 = ADD32(0, 0);
            goto L_8008E5EC;
    }
    // 0x8008E5C8: addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
L_8008E5CC:
    // 0x8008E5CC: jal         0x800920FC
    // 0x8008E5D0: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_800920FC(rdram, ctx);
        goto after_1;
    // 0x8008E5D0: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_1:
    // 0x8008E5D4: lui         $v1, 0x8014
    ctx->r3 = S32(0X8014 << 16);
    // 0x8008E5D8: lbu         $v1, 0x1AD0($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X1AD0);
    // 0x8008E5DC: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8008E5E0: slt         $v1, $s0, $v1
    ctx->r3 = SIGNED(ctx->r16) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8008E5E4: bne         $v1, $zero, L_8008E5CC
    if (ctx->r3 != 0) {
        // 0x8008E5E8: or          $s1, $s1, $v0
        ctx->r17 = ctx->r17 | ctx->r2;
            goto L_8008E5CC;
    }
    // 0x8008E5E8: or          $s1, $s1, $v0
    ctx->r17 = ctx->r17 | ctx->r2;
L_8008E5EC:
    // 0x8008E5EC: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x8008E5F0: sb          $zero, -0x530C($at)
    MEM_B(-0X530C, ctx->r1) = 0;
L_8008E5F4:
    // 0x8008E5F4: andi        $v0, $s1, 0xFF
    ctx->r2 = ctx->r17 & 0XFF;
    // 0x8008E5F8: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8008E5FC: lw          $ra, 0x20($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X20);
    // 0x8008E600: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8008E604: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8008E608: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8008E60C: jr          $ra
    // 0x8008E610: nop

    return;
    // 0x8008E610: nop

;}
RECOMP_FUNC void func_8008E614(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008E614: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x8008E618: addiu       $t2, $zero, -0x1
    ctx->r10 = ADD32(0, -0X1);
    // 0x8008E61C: addiu       $t1, $zero, 0xFF
    ctx->r9 = ADD32(0, 0XFF);
    // 0x8008E620: lui         $t0, 0x3F
    ctx->r8 = S32(0X3F << 16);
    // 0x8008E624: addiu       $a3, $zero, 0x17
    ctx->r7 = ADD32(0, 0X17);
    // 0x8008E628: addiu       $a2, $zero, 0x1F4
    ctx->r6 = ADD32(0, 0X1F4);
    // 0x8008E62C: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
    // 0x8008E630: addiu       $v0, $zero, 0x2800
    ctx->r2 = ADD32(0, 0X2800);
    // 0x8008E634: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x8008E638: sw          $v0, -0x4FC0($at)
    MEM_W(-0X4FC0, ctx->r1) = ctx->r2;
    // 0x8008E63C: addiu       $v0, $zero, 0x300
    ctx->r2 = ADD32(0, 0X300);
    // 0x8008E640: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x8008E644: sw          $a0, 0x40C0($at)
    MEM_W(0X40C0, ctx->r1) = ctx->r4;
    // 0x8008E648: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x8008E64C: sw          $v0, -0x5310($at)
    MEM_W(-0X5310, ctx->r1) = ctx->r2;
    // 0x8008E650: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8008E654: sb          $zero, -0x7C38($at)
    MEM_B(-0X7C38, ctx->r1) = 0;
L_8008E658:
    // 0x8008E658: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x8008E65C: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x8008E660: sw          $t2, -0x271C($at)
    MEM_W(-0X271C, ctx->r1) = ctx->r10;
    // 0x8008E664: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x8008E668: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x8008E66C: sw          $zero, -0x2780($at)
    MEM_W(-0X2780, ctx->r1) = 0;
    // 0x8008E670: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x8008E674: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x8008E678: sw          $zero, -0x275C($at)
    MEM_W(-0X275C, ctx->r1) = 0;
    // 0x8008E67C: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x8008E680: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x8008E684: sw          $zero, -0x2758($at)
    MEM_W(-0X2758, ctx->r1) = 0;
    // 0x8008E688: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x8008E68C: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x8008E690: sb          $zero, -0x2752($at)
    MEM_B(-0X2752, ctx->r1) = 0;
    // 0x8008E694: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x8008E698: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x8008E69C: sh          $zero, -0x2714($at)
    MEM_H(-0X2714, ctx->r1) = 0;
    // 0x8008E6A0: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x8008E6A4: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x8008E6A8: sb          $t1, -0x2732($at)
    MEM_B(-0X2732, ctx->r1) = ctx->r9;
    // 0x8008E6AC: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x8008E6B0: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x8008E6B4: sw          $zero, -0x2750($at)
    MEM_W(-0X2750, ctx->r1) = 0;
    // 0x8008E6B8: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x8008E6BC: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x8008E6C0: sw          $t0, -0x2748($at)
    MEM_W(-0X2748, ctx->r1) = ctx->r8;
    // 0x8008E6C4: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x8008E6C8: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x8008E6CC: sw          $zero, -0x273C($at)
    MEM_W(-0X273C, ctx->r1) = 0;
    // 0x8008E6D0: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x8008E6D4: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x8008E6D8: sw          $zero, -0x2738($at)
    MEM_W(-0X2738, ctx->r1) = 0;
    // 0x8008E6DC: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x8008E6E0: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x8008E6E4: sb          $zero, -0x2734($at)
    MEM_B(-0X2734, ctx->r1) = 0;
    // 0x8008E6E8: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x8008E6EC: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x8008E6F0: sb          $zero, -0x2733($at)
    MEM_B(-0X2733, ctx->r1) = 0;
    // 0x8008E6F4: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x8008E6F8: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x8008E6FC: sb          $zero, -0x26C7($at)
    MEM_B(-0X26C7, ctx->r1) = 0;
    // 0x8008E700: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x8008E704: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x8008E708: sb          $a3, -0x26C6($at)
    MEM_B(-0X26C6, ctx->r1) = ctx->r7;
    // 0x8008E70C: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x8008E710: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x8008E714: sw          $zero, -0x2618($at)
    MEM_W(-0X2618, ctx->r1) = 0;
    // 0x8008E718: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x8008E71C: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x8008E720: sh          $zero, -0x2614($at)
    MEM_H(-0X2614, ctx->r1) = 0;
    // 0x8008E724: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x8008E728: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x8008E72C: sw          $zero, -0x260C($at)
    MEM_W(-0X260C, ctx->r1) = 0;
    // 0x8008E730: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x8008E734: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x8008E738: sh          $zero, -0x2608($at)
    MEM_H(-0X2608, ctx->r1) = 0;
    // 0x8008E73C: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x8008E740: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x8008E744: sw          $a2, -0x26EC($at)
    MEM_W(-0X26EC, ctx->r1) = ctx->r6;
    // 0x8008E748: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x8008E74C: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x8008E750: sb          $zero, -0x26E0($at)
    MEM_B(-0X26E0, ctx->r1) = 0;
    // 0x8008E754: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x8008E758: slti        $v0, $a1, 0x20
    ctx->r2 = SIGNED(ctx->r5) < 0X20 ? 1 : 0;
    // 0x8008E75C: bne         $v0, $zero, L_8008E658
    if (ctx->r2 != 0) {
        // 0x8008E760: addiu       $v1, $v1, 0x17C
        ctx->r3 = ADD32(ctx->r3, 0X17C);
            goto L_8008E658;
    }
    // 0x8008E760: addiu       $v1, $v1, 0x17C
    ctx->r3 = ADD32(ctx->r3, 0X17C);
    // 0x8008E764: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x8008E768: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x8008E76C: lui         $a0, 0x7F
    ctx->r4 = S32(0X7F << 16);
    // 0x8008E770: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
L_8008E774:
    // 0x8008E774: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x8008E778: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x8008E77C: sw          $zero, 0x1B18($at)
    MEM_W(0X1B18, ctx->r1) = 0;
    // 0x8008E780: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x8008E784: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x8008E788: sw          $zero, 0x1B1C($at)
    MEM_W(0X1B1C, ctx->r1) = 0;
    // 0x8008E78C: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x8008E790: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x8008E794: sw          $zero, 0x1B24($at)
    MEM_W(0X1B24, ctx->r1) = 0;
    // 0x8008E798: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x8008E79C: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x8008E7A0: sb          $a2, 0x1B2C($at)
    MEM_B(0X1B2C, ctx->r1) = ctx->r6;
    // 0x8008E7A4: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x8008E7A8: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x8008E7AC: sw          $a0, 0x1B30($at)
    MEM_W(0X1B30, ctx->r1) = ctx->r4;
    // 0x8008E7B0: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x8008E7B4: slti        $v0, $a1, 0x20
    ctx->r2 = SIGNED(ctx->r5) < 0X20 ? 1 : 0;
    // 0x8008E7B8: bne         $v0, $zero, L_8008E774
    if (ctx->r2 != 0) {
        // 0x8008E7BC: addiu       $v1, $v1, 0x28
        ctx->r3 = ADD32(ctx->r3, 0X28);
            goto L_8008E774;
    }
    // 0x8008E7BC: addiu       $v1, $v1, 0x28
    ctx->r3 = ADD32(ctx->r3, 0X28);
    // 0x8008E7C0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8008E7C4: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x8008E7C8: sb          $v0, 0x2004($at)
    MEM_B(0X2004, ctx->r1) = ctx->r2;
    // 0x8008E7CC: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    // 0x8008E7D0: addiu       $v0, $zero, 0x4B0
    ctx->r2 = ADD32(0, 0X4B0);
L_8008E7D4:
    // 0x8008E7D4: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x8008E7D8: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x8008E7DC: sb          $zero, 0x1B2C($at)
    MEM_B(0X1B2C, ctx->r1) = 0;
    // 0x8008E7E0: addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
    // 0x8008E7E4: bgez        $a1, L_8008E7D4
    if (SIGNED(ctx->r5) >= 0) {
        // 0x8008E7E8: addiu       $v0, $v0, -0x28
        ctx->r2 = ADD32(ctx->r2, -0X28);
            goto L_8008E7D4;
    }
    // 0x8008E7E8: addiu       $v0, $v0, -0x28
    ctx->r2 = ADD32(ctx->r2, -0X28);
    // 0x8008E7EC: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
    // 0x8008E7F0: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x8008E7F4: addiu       $v0, $v0, -0x5300
    ctx->r2 = ADD32(ctx->r2, -0X5300);
    // 0x8008E7F8: addu        $a1, $v0, $zero
    ctx->r5 = ADD32(ctx->r2, 0);
    // 0x8008E7FC: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x8008E800: lui         $v0, 0x7F
    ctx->r2 = S32(0X7F << 16);
    // 0x8008E804: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x8008E808: sw          $v0, 0x1E60($at)
    MEM_W(0X1E60, ctx->r1) = ctx->r2;
    // 0x8008E80C: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x8008E810: sw          $v0, 0x1E88($at)
    MEM_W(0X1E88, ctx->r1) = ctx->r2;
    // 0x8008E814: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x8008E818: sw          $zero, -0x5308($at)
    MEM_W(-0X5308, ctx->r1) = 0;
    // 0x8008E81C: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x8008E820: sw          $zero, -0x5100($at)
    MEM_W(-0X5100, ctx->r1) = 0;
    // 0x8008E824: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x8008E828: sw          $a1, -0x50FC($at)
    MEM_W(-0X50FC, ctx->r1) = ctx->r5;
L_8008E82C:
    // 0x8008E82C: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x8008E830: addu        $at, $at, $a0
    ctx->r1 = ADD32(ctx->r1, ctx->r4);
    // 0x8008E834: sw          $v1, -0x52FC($at)
    MEM_W(-0X52FC, ctx->r1) = ctx->r3;
    // 0x8008E838: bnel        $v1, $zero, L_8008E840
    if (ctx->r3 != 0) {
        // 0x8008E83C: sw          $a1, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->r5;
            goto L_8008E840;
    }
    goto skip_0;
    // 0x8008E83C: sw          $a1, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r5;
    skip_0:
L_8008E840:
    // 0x8008E840: addu        $v1, $a1, $zero
    ctx->r3 = ADD32(ctx->r5, 0);
    // 0x8008E844: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    // 0x8008E848: slti        $v0, $a0, 0x200
    ctx->r2 = SIGNED(ctx->r4) < 0X200 ? 1 : 0;
    // 0x8008E84C: bne         $v0, $zero, L_8008E82C
    if (ctx->r2 != 0) {
        // 0x8008E850: addiu       $a1, $v1, 0x10
        ctx->r5 = ADD32(ctx->r3, 0X10);
            goto L_8008E82C;
    }
    // 0x8008E850: addiu       $a1, $v1, 0x10
    ctx->r5 = ADD32(ctx->r3, 0X10);
    // 0x8008E854: jr          $ra
    // 0x8008E858: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
    return;
    // 0x8008E858: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
;}
RECOMP_FUNC void func_8008E85C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008E85C: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
    // 0x8008E860: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x8008E864: sw          $zero, -0x3BB4($at)
    MEM_W(-0X3BB4, ctx->r1) = 0;
    // 0x8008E868: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x8008E86C: sw          $zero, -0x50F4($at)
    MEM_W(-0X50F4, ctx->r1) = 0;
    // 0x8008E870: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x8008E874: sw          $zero, -0x3BB0($at)
    MEM_W(-0X3BB0, ctx->r1) = 0;
    // 0x8008E878: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x8008E87C: sw          $zero, -0x50F8($at)
    MEM_W(-0X50F8, ctx->r1) = 0;
    // 0x8008E880: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8008E884: sw          $zero, -0x73B0($at)
    MEM_W(-0X73B0, ctx->r1) = 0;
L_8008E888:
    // 0x8008E888: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x8008E88C: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x8008E890: sh          $zero, -0x3B80($at)
    MEM_H(-0X3B80, ctx->r1) = 0;
    // 0x8008E894: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x8008E898: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x8008E89C: sh          $zero, -0x3B7E($at)
    MEM_H(-0X3B7E, ctx->r1) = 0;
    // 0x8008E8A0: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x8008E8A4: slti        $v0, $v1, 0x800
    ctx->r2 = SIGNED(ctx->r3) < 0X800 ? 1 : 0;
    // 0x8008E8A8: bne         $v0, $zero, L_8008E888
    if (ctx->r2 != 0) {
        // 0x8008E8AC: nop
    
            goto L_8008E888;
    }
    // 0x8008E8AC: nop

    // 0x8008E8B0: jr          $ra
    // 0x8008E8B4: nop

    return;
    // 0x8008E8B4: nop

;}
RECOMP_FUNC void func_8008E8B8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008E8B8: lui         $v1, 0x800A
    ctx->r3 = S32(0X800A << 16);
    // 0x8008E8BC: lbu         $v1, 0xF50($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0XF50);
    // 0x8008E8C0: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x8008E8C4: addiu       $v0, $v0, 0x808
    ctx->r2 = ADD32(ctx->r2, 0X808);
    // 0x8008E8C8: sltu        $v1, $zero, $v1
    ctx->r3 = 0 < ctx->r3 ? 1 : 0;
    // 0x8008E8CC: negu        $v1, $v1
    ctx->r3 = SUB32(0, ctx->r3);
    // 0x8008E8D0: jr          $ra
    // 0x8008E8D4: and         $v0, $v1, $v0
    ctx->r2 = ctx->r3 & ctx->r2;
    return;
    // 0x8008E8D4: and         $v0, $v1, $v0
    ctx->r2 = ctx->r3 & ctx->r2;
;}
RECOMP_FUNC void func_8008E8D8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008E8D8: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x8008E8DC: lbu         $v0, 0xF50($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0XF50);
    // 0x8008E8E0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8008E8E4: beq         $v0, $zero, L_8008E8F4
    if (ctx->r2 == 0) {
        // 0x8008E8E8: sw          $ra, 0x10($sp)
        MEM_W(0X10, ctx->r29) = ctx->r31;
            goto L_8008E8F4;
    }
    // 0x8008E8E8: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x8008E8EC: jal         0x80092510
    // 0x8008E8F0: nop

    func_80092510(rdram, ctx);
        goto after_0;
    // 0x8008E8F0: nop

    after_0:
L_8008E8F4:
    // 0x8008E8F4: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x8008E8F8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8008E8FC: jr          $ra
    // 0x8008E900: nop

    return;
    // 0x8008E900: nop

;}
RECOMP_FUNC void func_8008E904(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008E904: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x8008E908: lbu         $v0, 0xF50($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0XF50);
    // 0x8008E90C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8008E910: beq         $v0, $zero, L_8008E930
    if (ctx->r2 == 0) {
        // 0x8008E914: sw          $ra, 0x10($sp)
        MEM_W(0X10, ctx->r29) = ctx->r31;
            goto L_8008E930;
    }
    // 0x8008E914: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x8008E918: jal         0x80092010
    // 0x8008E91C: nop

    func_80092010(rdram, ctx);
        goto after_0;
    // 0x8008E91C: nop

    after_0:
    // 0x8008E920: jal         0x80092530
    // 0x8008E924: nop

    func_80092530(rdram, ctx);
        goto after_1;
    // 0x8008E924: nop

    after_1:
    // 0x8008E928: jal         0x8009205C
    // 0x8008E92C: nop

    func_8009205C(rdram, ctx);
        goto after_2;
    // 0x8008E92C: nop

    after_2:
L_8008E930:
    // 0x8008E930: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x8008E934: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8008E938: jr          $ra
    // 0x8008E93C: nop

    return;
    // 0x8008E93C: nop

;}
RECOMP_FUNC void func_8008E940(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008E940: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8008E944: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x8008E948: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8008E94C: jal         0x80097120
    // 0x8008E950: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    func_80097120(rdram, ctx);
        goto after_0;
    // 0x8008E950: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    after_0:
    // 0x8008E954: addiu       $v1, $zero, 0xF
    ctx->r3 = ADD32(0, 0XF);
    // 0x8008E958: lui         $v0, 0x8015
    ctx->r2 = S32(0X8015 << 16);
    // 0x8008E95C: addiu       $v0, $v0, -0x7399
    ctx->r2 = ADD32(ctx->r2, -0X7399);
L_8008E960:
    // 0x8008E960: sb          $zero, 0x0($v0)
    MEM_B(0X0, ctx->r2) = 0;
    // 0x8008E964: addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
    // 0x8008E968: bgez        $v1, L_8008E960
    if (SIGNED(ctx->r3) >= 0) {
        // 0x8008E96C: addiu       $v0, $v0, -0x1
        ctx->r2 = ADD32(ctx->r2, -0X1);
            goto L_8008E960;
    }
    // 0x8008E96C: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x8008E970: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
    // 0x8008E974: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x8008E978: sw          $zero, -0x3BB4($at)
    MEM_W(-0X3BB4, ctx->r1) = 0;
    // 0x8008E97C: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x8008E980: sw          $zero, -0x50F4($at)
    MEM_W(-0X50F4, ctx->r1) = 0;
    // 0x8008E984: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x8008E988: sw          $zero, -0x3BB0($at)
    MEM_W(-0X3BB0, ctx->r1) = 0;
    // 0x8008E98C: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x8008E990: sw          $zero, -0x50F8($at)
    MEM_W(-0X50F8, ctx->r1) = 0;
    // 0x8008E994: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8008E998: sw          $zero, -0x73B0($at)
    MEM_W(-0X73B0, ctx->r1) = 0;
L_8008E99C:
    // 0x8008E99C: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x8008E9A0: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x8008E9A4: sh          $zero, -0x3B80($at)
    MEM_H(-0X3B80, ctx->r1) = 0;
    // 0x8008E9A8: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x8008E9AC: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x8008E9B0: sh          $zero, -0x3B7E($at)
    MEM_H(-0X3B7E, ctx->r1) = 0;
    // 0x8008E9B4: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x8008E9B8: slti        $v0, $v1, 0x800
    ctx->r2 = SIGNED(ctx->r3) < 0X800 ? 1 : 0;
    // 0x8008E9BC: bne         $v0, $zero, L_8008E99C
    if (ctx->r2 != 0) {
        // 0x8008E9C0: nop
    
            goto L_8008E99C;
    }
    // 0x8008E9C0: nop

    // 0x8008E9C4: jal         0x80097088
    // 0x8008E9C8: nop

    func_80097088(rdram, ctx);
        goto after_1;
    // 0x8008E9C8: nop

    after_1:
    // 0x8008E9CC: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x8008E9D0: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x8008E9D4: sb          $zero, -0x530C($at)
    MEM_B(-0X530C, ctx->r1) = 0;
    // 0x8008E9D8: jal         0x8008E614
    // 0x8008E9DC: nop

    func_8008E614(rdram, ctx);
        goto after_2;
    // 0x8008E9DC: nop

    after_2:
    // 0x8008E9E0: jal         0x80097D60
    // 0x8008E9E4: nop

    func_80097D60(rdram, ctx);
        goto after_3;
    // 0x8008E9E4: nop

    after_3:
    // 0x8008E9E8: jal         0x80099C2C
    // 0x8008E9EC: nop

    func_80099C2C(rdram, ctx);
        goto after_4;
    // 0x8008E9EC: nop

    after_4:
    // 0x8008E9F0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8008E9F4: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x8008E9F8: sb          $v0, 0xF50($at)
    MEM_B(0XF50, ctx->r1) = ctx->r2;
    // 0x8008E9FC: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // 0x8008EA00: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8008EA04: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x8008EA08: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8008EA0C: jr          $ra
    // 0x8008EA10: nop

    return;
    // 0x8008EA10: nop

;}
RECOMP_FUNC void func_8008EA14(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008EA14: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8008EA18: lhu         $v1, 0x2A($sp)
    ctx->r3 = MEM_HU(ctx->r29, 0X2A);
    // 0x8008EA1C: andi        $v0, $a1, 0xFF
    ctx->r2 = ctx->r5 & 0XFF;
    // 0x8008EA20: sltiu       $v0, $v0, 0x21
    ctx->r2 = ctx->r2 < 0X21 ? 1 : 0;
    // 0x8008EA24: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8008EA28: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x8008EA2C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8008EA30: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x8008EA34: sb          $zero, 0xF50($at)
    MEM_B(0XF50, ctx->r1) = 0;
    // 0x8008EA38: beq         $v0, $zero, L_8008EA50
    if (ctx->r2 == 0) {
        // 0x8008EA3C: addiu       $v0, $zero, 0x20
        ctx->r2 = ADD32(0, 0X20);
            goto L_8008EA50;
    }
    // 0x8008EA3C: addiu       $v0, $zero, 0x20
    ctx->r2 = ADD32(0, 0X20);
    // 0x8008EA40: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x8008EA44: sb          $a1, 0x1AD0($at)
    MEM_B(0X1AD0, ctx->r1) = ctx->r5;
    // 0x8008EA48: j           L_8008EA58
    // 0x8008EA4C: nop

        goto L_8008EA58;
    // 0x8008EA4C: nop

L_8008EA50:
    // 0x8008EA50: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x8008EA54: sb          $v0, 0x1AD0($at)
    MEM_B(0X1AD0, ctx->r1) = ctx->r2;
L_8008EA58:
    // 0x8008EA58: lui         $a1, 0x8014
    ctx->r5 = S32(0X8014 << 16);
    // 0x8008EA5C: lbu         $a1, 0x1AD0($a1)
    ctx->r5 = MEM_BU(ctx->r5, 0X1AD0);
    // 0x8008EA60: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x8008EA64: sb          $a3, -0x4FC8($at)
    MEM_B(-0X4FC8, ctx->r1) = ctx->r7;
    // 0x8008EA68: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    // 0x8008EA6C: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    // 0x8008EA70: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x8008EA74: sb          $a2, 0x1AD1($at)
    MEM_B(0X1AD1, ctx->r1) = ctx->r6;
    // 0x8008EA78: jal         0x80091B3C
    // 0x8008EA7C: addu        $a2, $v1, $zero
    ctx->r6 = ADD32(ctx->r3, 0);
    func_80091B3C(rdram, ctx);
        goto after_0;
    // 0x8008EA7C: addu        $a2, $v1, $zero
    ctx->r6 = ADD32(ctx->r3, 0);
    after_0:
    // 0x8008EA80: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // 0x8008EA84: bnel        $v1, $zero, L_8008EB48
    if (ctx->r3 != 0) {
        // 0x8008EA88: addu        $v0, $v1, $zero
        ctx->r2 = ADD32(ctx->r3, 0);
            goto L_8008EB48;
    }
    goto skip_0;
    // 0x8008EA88: addu        $v0, $v1, $zero
    ctx->r2 = ADD32(ctx->r3, 0);
    skip_0:
    // 0x8008EA8C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8008EA90: jal         0x80097120
    // 0x8008EA94: nop

    func_80097120(rdram, ctx);
        goto after_1;
    // 0x8008EA94: nop

    after_1:
    // 0x8008EA98: addiu       $v1, $zero, 0xF
    ctx->r3 = ADD32(0, 0XF);
    // 0x8008EA9C: lui         $v0, 0x8015
    ctx->r2 = S32(0X8015 << 16);
    // 0x8008EAA0: addiu       $v0, $v0, -0x7399
    ctx->r2 = ADD32(ctx->r2, -0X7399);
L_8008EAA4:
    // 0x8008EAA4: sb          $zero, 0x0($v0)
    MEM_B(0X0, ctx->r2) = 0;
    // 0x8008EAA8: addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
    // 0x8008EAAC: bgez        $v1, L_8008EAA4
    if (SIGNED(ctx->r3) >= 0) {
        // 0x8008EAB0: addiu       $v0, $v0, -0x1
        ctx->r2 = ADD32(ctx->r2, -0X1);
            goto L_8008EAA4;
    }
    // 0x8008EAB0: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x8008EAB4: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
    // 0x8008EAB8: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x8008EABC: sw          $zero, -0x3BB4($at)
    MEM_W(-0X3BB4, ctx->r1) = 0;
    // 0x8008EAC0: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x8008EAC4: sw          $zero, -0x50F4($at)
    MEM_W(-0X50F4, ctx->r1) = 0;
    // 0x8008EAC8: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x8008EACC: sw          $zero, -0x3BB0($at)
    MEM_W(-0X3BB0, ctx->r1) = 0;
    // 0x8008EAD0: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x8008EAD4: sw          $zero, -0x50F8($at)
    MEM_W(-0X50F8, ctx->r1) = 0;
    // 0x8008EAD8: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8008EADC: sw          $zero, -0x73B0($at)
    MEM_W(-0X73B0, ctx->r1) = 0;
L_8008EAE0:
    // 0x8008EAE0: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x8008EAE4: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x8008EAE8: sh          $zero, -0x3B80($at)
    MEM_H(-0X3B80, ctx->r1) = 0;
    // 0x8008EAEC: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x8008EAF0: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x8008EAF4: sh          $zero, -0x3B7E($at)
    MEM_H(-0X3B7E, ctx->r1) = 0;
    // 0x8008EAF8: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x8008EAFC: slti        $v0, $v1, 0x800
    ctx->r2 = SIGNED(ctx->r3) < 0X800 ? 1 : 0;
    // 0x8008EB00: bne         $v0, $zero, L_8008EAE0
    if (ctx->r2 != 0) {
        // 0x8008EB04: nop
    
            goto L_8008EAE0;
    }
    // 0x8008EB04: nop

    // 0x8008EB08: jal         0x80097088
    // 0x8008EB0C: nop

    func_80097088(rdram, ctx);
        goto after_2;
    // 0x8008EB0C: nop

    after_2:
    // 0x8008EB10: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x8008EB14: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x8008EB18: sb          $zero, -0x530C($at)
    MEM_B(-0X530C, ctx->r1) = 0;
    // 0x8008EB1C: jal         0x8008E614
    // 0x8008EB20: nop

    func_8008E614(rdram, ctx);
        goto after_3;
    // 0x8008EB20: nop

    after_3:
    // 0x8008EB24: jal         0x80097D60
    // 0x8008EB28: nop

    func_80097D60(rdram, ctx);
        goto after_4;
    // 0x8008EB28: nop

    after_4:
    // 0x8008EB2C: jal         0x80099C2C
    // 0x8008EB30: nop

    func_80099C2C(rdram, ctx);
        goto after_5;
    // 0x8008EB30: nop

    after_5:
    // 0x8008EB34: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
    // 0x8008EB38: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8008EB3C: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x8008EB40: sb          $v0, 0xF50($at)
    MEM_B(0XF50, ctx->r1) = ctx->r2;
    // 0x8008EB44: addu        $v0, $v1, $zero
    ctx->r2 = ADD32(ctx->r3, 0);
L_8008EB48:
    // 0x8008EB48: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8008EB4C: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x8008EB50: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8008EB54: jr          $ra
    // 0x8008EB58: nop

    return;
    // 0x8008EB58: nop

;}
RECOMP_FUNC void func_8008EB5C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008EB5C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8008EB60: lhu         $v1, 0x2A($sp)
    ctx->r3 = MEM_HU(ctx->r29, 0X2A);
    // 0x8008EB64: andi        $v0, $a1, 0xFF
    ctx->r2 = ctx->r5 & 0XFF;
    // 0x8008EB68: sltiu       $v0, $v0, 0x21
    ctx->r2 = ctx->r2 < 0X21 ? 1 : 0;
    // 0x8008EB6C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8008EB70: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x8008EB74: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8008EB78: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x8008EB7C: sb          $zero, 0xF50($at)
    MEM_B(0XF50, ctx->r1) = 0;
    // 0x8008EB80: beq         $v0, $zero, L_8008EB98
    if (ctx->r2 == 0) {
        // 0x8008EB84: addiu       $v0, $zero, 0x20
        ctx->r2 = ADD32(0, 0X20);
            goto L_8008EB98;
    }
    // 0x8008EB84: addiu       $v0, $zero, 0x20
    ctx->r2 = ADD32(0, 0X20);
    // 0x8008EB88: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x8008EB8C: sb          $a1, 0x1AD0($at)
    MEM_B(0X1AD0, ctx->r1) = ctx->r5;
    // 0x8008EB90: j           L_8008EBA0
    // 0x8008EB94: nop

        goto L_8008EBA0;
    // 0x8008EB94: nop

L_8008EB98:
    // 0x8008EB98: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x8008EB9C: sb          $v0, 0x1AD0($at)
    MEM_B(0X1AD0, ctx->r1) = ctx->r2;
L_8008EBA0:
    // 0x8008EBA0: lui         $a1, 0x8014
    ctx->r5 = S32(0X8014 << 16);
    // 0x8008EBA4: lbu         $a1, 0x1AD0($a1)
    ctx->r5 = MEM_BU(ctx->r5, 0X1AD0);
    // 0x8008EBA8: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x8008EBAC: sb          $a3, -0x4FC8($at)
    MEM_B(-0X4FC8, ctx->r1) = ctx->r7;
    // 0x8008EBB0: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    // 0x8008EBB4: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    // 0x8008EBB8: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x8008EBBC: sb          $a2, 0x1AD1($at)
    MEM_B(0X1AD1, ctx->r1) = ctx->r6;
    // 0x8008EBC0: jal         0x80091C88
    // 0x8008EBC4: addu        $a2, $v1, $zero
    ctx->r6 = ADD32(ctx->r3, 0);
    func_80091C88(rdram, ctx);
        goto after_0;
    // 0x8008EBC4: addu        $a2, $v1, $zero
    ctx->r6 = ADD32(ctx->r3, 0);
    after_0:
    // 0x8008EBC8: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // 0x8008EBCC: bnel        $v1, $zero, L_8008EC90
    if (ctx->r3 != 0) {
        // 0x8008EBD0: addu        $v0, $v1, $zero
        ctx->r2 = ADD32(ctx->r3, 0);
            goto L_8008EC90;
    }
    goto skip_0;
    // 0x8008EBD0: addu        $v0, $v1, $zero
    ctx->r2 = ADD32(ctx->r3, 0);
    skip_0:
    // 0x8008EBD4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8008EBD8: jal         0x80097120
    // 0x8008EBDC: nop

    func_80097120(rdram, ctx);
        goto after_1;
    // 0x8008EBDC: nop

    after_1:
    // 0x8008EBE0: addiu       $v1, $zero, 0xF
    ctx->r3 = ADD32(0, 0XF);
    // 0x8008EBE4: lui         $v0, 0x8015
    ctx->r2 = S32(0X8015 << 16);
    // 0x8008EBE8: addiu       $v0, $v0, -0x7399
    ctx->r2 = ADD32(ctx->r2, -0X7399);
L_8008EBEC:
    // 0x8008EBEC: sb          $zero, 0x0($v0)
    MEM_B(0X0, ctx->r2) = 0;
    // 0x8008EBF0: addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
    // 0x8008EBF4: bgez        $v1, L_8008EBEC
    if (SIGNED(ctx->r3) >= 0) {
        // 0x8008EBF8: addiu       $v0, $v0, -0x1
        ctx->r2 = ADD32(ctx->r2, -0X1);
            goto L_8008EBEC;
    }
    // 0x8008EBF8: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x8008EBFC: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
    // 0x8008EC00: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x8008EC04: sw          $zero, -0x3BB4($at)
    MEM_W(-0X3BB4, ctx->r1) = 0;
    // 0x8008EC08: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x8008EC0C: sw          $zero, -0x50F4($at)
    MEM_W(-0X50F4, ctx->r1) = 0;
    // 0x8008EC10: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x8008EC14: sw          $zero, -0x3BB0($at)
    MEM_W(-0X3BB0, ctx->r1) = 0;
    // 0x8008EC18: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x8008EC1C: sw          $zero, -0x50F8($at)
    MEM_W(-0X50F8, ctx->r1) = 0;
    // 0x8008EC20: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8008EC24: sw          $zero, -0x73B0($at)
    MEM_W(-0X73B0, ctx->r1) = 0;
L_8008EC28:
    // 0x8008EC28: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x8008EC2C: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x8008EC30: sh          $zero, -0x3B80($at)
    MEM_H(-0X3B80, ctx->r1) = 0;
    // 0x8008EC34: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x8008EC38: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x8008EC3C: sh          $zero, -0x3B7E($at)
    MEM_H(-0X3B7E, ctx->r1) = 0;
    // 0x8008EC40: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x8008EC44: slti        $v0, $v1, 0x800
    ctx->r2 = SIGNED(ctx->r3) < 0X800 ? 1 : 0;
    // 0x8008EC48: bne         $v0, $zero, L_8008EC28
    if (ctx->r2 != 0) {
        // 0x8008EC4C: nop
    
            goto L_8008EC28;
    }
    // 0x8008EC4C: nop

    // 0x8008EC50: jal         0x80097088
    // 0x8008EC54: nop

    func_80097088(rdram, ctx);
        goto after_2;
    // 0x8008EC54: nop

    after_2:
    // 0x8008EC58: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x8008EC5C: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x8008EC60: sb          $zero, -0x530C($at)
    MEM_B(-0X530C, ctx->r1) = 0;
    // 0x8008EC64: jal         0x8008E614
    // 0x8008EC68: nop

    func_8008E614(rdram, ctx);
        goto after_3;
    // 0x8008EC68: nop

    after_3:
    // 0x8008EC6C: jal         0x80097D60
    // 0x8008EC70: nop

    func_80097D60(rdram, ctx);
        goto after_4;
    // 0x8008EC70: nop

    after_4:
    // 0x8008EC74: jal         0x80099C2C
    // 0x8008EC78: nop

    func_80099C2C(rdram, ctx);
        goto after_5;
    // 0x8008EC78: nop

    after_5:
    // 0x8008EC7C: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
    // 0x8008EC80: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8008EC84: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x8008EC88: sb          $v0, 0xF50($at)
    MEM_B(0XF50, ctx->r1) = ctx->r2;
    // 0x8008EC8C: addu        $v0, $v1, $zero
    ctx->r2 = ADD32(ctx->r3, 0);
L_8008EC90:
    // 0x8008EC90: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8008EC94: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x8008EC98: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8008EC9C: jr          $ra
    // 0x8008ECA0: nop

    return;
    // 0x8008ECA0: nop

;}
RECOMP_FUNC void func_8008ECA4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008ECA4: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x8008ECA8: lbu         $v0, 0xF50($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0XF50);
    // 0x8008ECAC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8008ECB0: beq         $v0, $zero, L_8008ECF0
    if (ctx->r2 == 0) {
        // 0x8008ECB4: sw          $ra, 0x10($sp)
        MEM_W(0X10, ctx->r29) = ctx->r31;
            goto L_8008ECF0;
    }
    // 0x8008ECB4: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x8008ECB8: jal         0x80091D40
    // 0x8008ECBC: nop

    func_80091D40(rdram, ctx);
        goto after_0;
    // 0x8008ECBC: nop

    after_0:
    // 0x8008ECC0: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x8008ECC4: lw          $v0, -0x50EC($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X50EC);
    // 0x8008ECC8: beq         $v0, $zero, L_8008ECE0
    if (ctx->r2 == 0) {
        // 0x8008ECCC: nop
    
            goto L_8008ECE0;
    }
    // 0x8008ECCC: nop

    // 0x8008ECD0: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8008ECD4: lw          $a0, -0x50EC($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X50EC);
    // 0x8008ECD8: jal         0x80001C98
    // 0x8008ECDC: nop

    rs_free(rdram, ctx);
        goto after_1;
    // 0x8008ECDC: nop

    after_1:
L_8008ECE0:
    // 0x8008ECE0: jal         0x80099C44
    // 0x8008ECE4: nop

    func_80099C44(rdram, ctx);
        goto after_2;
    // 0x8008ECE4: nop

    after_2:
    // 0x8008ECE8: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x8008ECEC: sb          $zero, 0xF50($at)
    MEM_B(0XF50, ctx->r1) = 0;
L_8008ECF0:
    // 0x8008ECF0: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x8008ECF4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8008ECF8: jr          $ra
    // 0x8008ECFC: nop

    return;
    // 0x8008ECFC: nop

;}
RECOMP_FUNC void func_8008ED00(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
;}
RECOMP_FUNC void func_8008ED5C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008ED5C: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x8008ED60: lbu         $v0, 0xF50($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0XF50);
    // 0x8008ED64: jr          $ra
    // 0x8008ED68: nop

    return;
    // 0x8008ED68: nop

;}
RECOMP_FUNC void func_8008ED6C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008ED6C: lwc1        $f2, 0x0($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X0);
    // 0x8008ED70: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8008ED74: addiu       $a0, $zero, 0x3000
    ctx->r4 = ADD32(0, 0X3000);
    // 0x8008ED78: addiu       $a1, $zero, 0x80
    ctx->r5 = ADD32(0, 0X80);
    // 0x8008ED7C: sw          $ra, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r31;
    // 0x8008ED80: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x8008ED84: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8008ED88: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8008ED8C: jal         0x80001ACC
    // 0x8008ED90: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    rs_malloc(rdram, ctx);
        goto after_0;
    // 0x8008ED90: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    after_0:
    // 0x8008ED94: lui         $v1, 0x8015
    ctx->r3 = S32(0X8015 << 16);
    // 0x8008ED98: addiu       $v1, $v1, -0x6950
    ctx->r3 = ADD32(ctx->r3, -0X6950);
    // 0x8008ED9C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8008EDA0: addiu       $a0, $v1, 0x4
    ctx->r4 = ADD32(ctx->r3, 0X4);
    // 0x8008EDA4: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
L_8008EDA8:
    // 0x8008EDA8: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8008EDAC: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x8008EDB0: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x8008EDB4: addiu       $v0, $v0, 0x300
    ctx->r2 = ADD32(ctx->r2, 0X300);
    // 0x8008EDB8: sw          $v0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r2;
    // 0x8008EDBC: slti        $v0, $a1, 0x10
    ctx->r2 = SIGNED(ctx->r5) < 0X10 ? 1 : 0;
    // 0x8008EDC0: bne         $v0, $zero, L_8008EDA8
    if (ctx->r2 != 0) {
        // 0x8008EDC4: addiu       $a0, $a0, 0x4
        ctx->r4 = ADD32(ctx->r4, 0X4);
            goto L_8008EDA8;
    }
    // 0x8008EDC4: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x8008EDC8: lui         $s0, 0x8015
    ctx->r16 = S32(0X8015 << 16);
    // 0x8008EDCC: addiu       $s0, $s0, -0x6950
    ctx->r16 = ADD32(ctx->r16, -0X6950);
    // 0x8008EDD0: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x8008EDD4: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x8008EDD8: addiu       $a2, $zero, 0x3000
    ctx->r6 = ADD32(0, 0X3000);
    // 0x8008EDDC: jal         0x800078E0
    // 0x8008EDE0: addu        $s1, $zero, $zero
    ctx->r17 = ADD32(0, 0);
    rs_memset(rdram, ctx);
        goto after_1;
    // 0x8008EDE0: addu        $s1, $zero, $zero
    ctx->r17 = ADD32(0, 0);
    after_1:
    // 0x8008EDE4: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x8008EDE8: addiu       $s3, $zero, 0x1
    ctx->r19 = ADD32(0, 0X1);
    // 0x8008EDEC: jal         0x800358B0
    // 0x8008EDF0: addiu       $a1, $zero, 0x3000
    ctx->r5 = ADD32(0, 0X3000);
    osWritebackDCache_recomp(rdram, ctx);
        goto after_2;
    // 0x8008EDF0: addiu       $a1, $zero, 0x3000
    ctx->r5 = ADD32(0, 0X3000);
    after_2:
    // 0x8008EDF4: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x8008EDF8: addiu       $s2, $zero, 0xFF
    ctx->r18 = ADD32(0, 0XFF);
    // 0x8008EDFC: addiu       $a1, $zero, 0x300
    ctx->r5 = ADD32(0, 0X300);
    // 0x8008EE00: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8008EE04: sb          $zero, -0x6910($at)
    MEM_B(-0X6910, ctx->r1) = 0;
    // 0x8008EE08: jal         0x80029E80
    // 0x8008EE0C: nop

    osAiSetNextBuffer_recomp(rdram, ctx);
        goto after_3;
    // 0x8008EE0C: nop

    after_3:
L_8008EE10:
    // 0x8008EE10: lui         $a0, 0x8015
    ctx->r4 = S32(0X8015 << 16);
    // 0x8008EE14: addiu       $a0, $a0, -0x6990
    ctx->r4 = ADD32(ctx->r4, -0X6990);
    // 0x8008EE18: addiu       $a1, $sp, 0x10
    ctx->r5 = ADD32(ctx->r29, 0X10);
    // 0x8008EE1C: jal         0x800331D0
    // 0x8008EE20: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osRecvMesg_recomp(rdram, ctx);
        goto after_4;
    // 0x8008EE20: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_4:
    // 0x8008EE24: lw          $v0, 0x10($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X10);
    // 0x8008EE28: lbu         $v0, 0x0($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X0);
    // 0x8008EE2C: beq         $v0, $s3, L_8008EE44
    if (ctx->r2 == ctx->r19) {
        // 0x8008EE30: nop
    
            goto L_8008EE44;
    }
    // 0x8008EE30: nop

    // 0x8008EE34: beql        $v0, $s2, L_8008EE94
    if (ctx->r2 == ctx->r18) {
        // 0x8008EE38: addiu       $s1, $zero, 0x1
        ctx->r17 = ADD32(0, 0X1);
            goto L_8008EE94;
    }
    goto skip_0;
    // 0x8008EE38: addiu       $s1, $zero, 0x1
    ctx->r17 = ADD32(0, 0X1);
    skip_0:
    // 0x8008EE3C: j           L_8008EE98
    // 0x8008EE40: andi        $v0, $s1, 0xFF
    ctx->r2 = ctx->r17 & 0XFF;
        goto L_8008EE98;
    // 0x8008EE40: andi        $v0, $s1, 0xFF
    ctx->r2 = ctx->r17 & 0XFF;
L_8008EE44:
    // 0x8008EE44: lui         $v0, 0x8015
    ctx->r2 = S32(0X8015 << 16);
    // 0x8008EE48: lbu         $v0, -0x6910($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X6910);
    // 0x8008EE4C: andi        $a0, $v0, 0xFF
    ctx->r4 = ctx->r2 & 0XFF;
    // 0x8008EE50: addiu       $v1, $a0, 0x1
    ctx->r3 = ADD32(ctx->r4, 0X1);
    // 0x8008EE54: bgez        $v1, L_8008EE60
    if (SIGNED(ctx->r3) >= 0) {
        // 0x8008EE58: addu        $v0, $v1, $zero
        ctx->r2 = ADD32(ctx->r3, 0);
            goto L_8008EE60;
    }
    // 0x8008EE58: addu        $v0, $v1, $zero
    ctx->r2 = ADD32(ctx->r3, 0);
    // 0x8008EE5C: addiu       $v0, $a0, 0x10
    ctx->r2 = ADD32(ctx->r4, 0X10);
L_8008EE60:
    // 0x8008EE60: andi        $v0, $v0, 0x1F0
    ctx->r2 = ctx->r2 & 0X1F0;
    // 0x8008EE64: subu        $v0, $v1, $v0
    ctx->r2 = SUB32(ctx->r3, ctx->r2);
    // 0x8008EE68: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8008EE6C: sb          $v0, -0x6910($at)
    MEM_B(-0X6910, ctx->r1) = ctx->r2;
    // 0x8008EE70: lui         $v0, 0x8015
    ctx->r2 = S32(0X8015 << 16);
    // 0x8008EE74: lbu         $v0, -0x6910($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X6910);
    // 0x8008EE78: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8008EE7C: addu        $v0, $v0, $s0
    ctx->r2 = ADD32(ctx->r2, ctx->r16);
    // 0x8008EE80: lw          $a0, 0x0($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X0);
    // 0x8008EE84: jal         0x80029E80
    // 0x8008EE88: addiu       $a1, $zero, 0x300
    ctx->r5 = ADD32(0, 0X300);
    osAiSetNextBuffer_recomp(rdram, ctx);
        goto after_5;
    // 0x8008EE88: addiu       $a1, $zero, 0x300
    ctx->r5 = ADD32(0, 0X300);
    after_5:
    // 0x8008EE8C: j           L_8008EE98
    // 0x8008EE90: andi        $v0, $s1, 0xFF
    ctx->r2 = ctx->r17 & 0XFF;
        goto L_8008EE98;
    // 0x8008EE90: andi        $v0, $s1, 0xFF
    ctx->r2 = ctx->r17 & 0XFF;
L_8008EE94:
    // 0x8008EE94: andi        $v0, $s1, 0xFF
    ctx->r2 = ctx->r17 & 0XFF;
L_8008EE98:
    // 0x8008EE98: beq         $v0, $zero, L_8008EE10
    if (ctx->r2 == 0) {
        // 0x8008EE9C: nop
    
            goto L_8008EE10;
    }
    // 0x8008EE9C: nop

    // 0x8008EEA0: lw          $ra, 0x28($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X28);
    // 0x8008EEA4: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x8008EEA8: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8008EEAC: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8008EEB0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8008EEB4: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8008EEB8: jr          $ra
    // 0x8008EEBC: nop

    return;
    // 0x8008EEBC: nop

;}
RECOMP_FUNC void func_8008EEC0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008EEC0: lui         $v0, 0x8015
    ctx->r2 = S32(0X8015 << 16);
    // 0x8008EEC4: lw          $v0, -0x6890($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X6890);
    // 0x8008EEC8: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8008EECC: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x8008EED0: addu        $s3, $a0, $zero
    ctx->r19 = ADD32(ctx->r4, 0);
    // 0x8008EED4: sw          $ra, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r31;
    // 0x8008EED8: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8008EEDC: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8008EEE0: beq         $v0, $zero, L_8008F080
    if (ctx->r2 == 0) {
        // 0x8008EEE4: sw          $s0, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r16;
            goto L_8008F080;
    }
    // 0x8008EEE4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8008EEE8: lhu         $v1, 0x0($s3)
    ctx->r3 = MEM_HU(ctx->r19, 0X0);
    // 0x8008EEEC: lui         $v0, 0x8015
    ctx->r2 = S32(0X8015 << 16);
    // 0x8008EEF0: lw          $v0, -0x690C($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X690C);
    // 0x8008EEF4: mult        $v1, $v0
    result = S64(S32(ctx->r3)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8008EEF8: mflo        $v1
    ctx->r3 = lo;
    // 0x8008EEFC: lui         $v0, 0x1062
    ctx->r2 = S32(0X1062 << 16);
    // 0x8008EF00: ori         $v0, $v0, 0x4DD3
    ctx->r2 = ctx->r2 | 0X4DD3;
    // 0x8008EF04: multu       $v1, $v0
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8008EF08: mfhi        $t1
    ctx->r9 = hi;
    // 0x8008EF0C: lui         $v0, 0xAAAA
    ctx->r2 = S32(0XAAAA << 16);
    // 0x8008EF10: ori         $v0, $v0, 0xAAAB
    ctx->r2 = ctx->r2 | 0XAAAB;
    // 0x8008EF14: srl         $s1, $t1, 6
    ctx->r17 = S32(U32(ctx->r9) >> 6);
    // 0x8008EF18: multu       $s1, $v0
    result = U64(U32(ctx->r17)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8008EF1C: addiu       $a0, $zero, 0x48
    ctx->r4 = ADD32(0, 0X48);
    // 0x8008EF20: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x8008EF24: mfhi        $t1
    ctx->r9 = hi;
    // 0x8008EF28: srl         $v1, $t1, 7
    ctx->r3 = S32(U32(ctx->r9) >> 7);
    // 0x8008EF2C: sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3 << 1);
    // 0x8008EF30: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8008EF34: sll         $v0, $v0, 6
    ctx->r2 = S32(ctx->r2 << 6);
    // 0x8008EF38: jal         0x80001ACC
    // 0x8008EF3C: addiu       $s1, $v0, 0xC0
    ctx->r17 = ADD32(ctx->r2, 0XC0);
    rs_malloc(rdram, ctx);
        goto after_0;
    // 0x8008EF3C: addiu       $s1, $v0, 0xC0
    ctx->r17 = ADD32(ctx->r2, 0XC0);
    after_0:
    // 0x8008EF40: lui         $a0, 0x8015
    ctx->r4 = S32(0X8015 << 16);
    // 0x8008EF44: lw          $a0, -0x6890($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X6890);
    // 0x8008EF48: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x8008EF4C: addu        $s2, $v0, $zero
    ctx->r18 = ADD32(ctx->r2, 0);
    // 0x8008EF50: sll         $s0, $s1, 1
    ctx->r16 = S32(ctx->r17 << 1);
    // 0x8008EF54: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    // 0x8008EF58: jal         0x800078E0
    // 0x8008EF5C: sw          $a0, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r4;
    rs_memset(rdram, ctx);
        goto after_1;
    // 0x8008EF5C: sw          $a0, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r4;
    after_1:
    // 0x8008EF60: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    // 0x8008EF64: jal         0x800358B0
    // 0x8008EF68: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    osWritebackDCache_recomp(rdram, ctx);
        goto after_2;
    // 0x8008EF68: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    after_2:
    // 0x8008EF6C: sw          $s1, 0x4($s2)
    MEM_W(0X4, ctx->r18) = ctx->r17;
    // 0x8008EF70: lbu         $v0, 0x1B($s3)
    ctx->r2 = MEM_BU(ctx->r19, 0X1B);
    // 0x8008EF74: sll         $v0, $v0, 8
    ctx->r2 = S32(ctx->r2 << 8);
    // 0x8008EF78: sh          $v0, 0xA($s2)
    MEM_H(0XA, ctx->r18) = ctx->r2;
    // 0x8008EF7C: lbu         $v0, 0x1A($s3)
    ctx->r2 = MEM_BU(ctx->r19, 0X1A);
    // 0x8008EF80: sh          $v0, 0x8($s2)
    MEM_H(0X8, ctx->r18) = ctx->r2;
    // 0x8008EF84: lbu         $v0, 0x1A($s3)
    ctx->r2 = MEM_BU(ctx->r19, 0X1A);
    // 0x8008EF88: beq         $v0, $zero, L_8008F004
    if (ctx->r2 == 0) {
        // 0x8008EF8C: addu        $v1, $zero, $zero
        ctx->r3 = ADD32(0, 0);
            goto L_8008F004;
    }
    // 0x8008EF8C: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
    // 0x8008EF90: lui         $t0, 0x8015
    ctx->r8 = S32(0X8015 << 16);
    // 0x8008EF94: lw          $t0, -0x690C($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X690C);
    // 0x8008EF98: lui         $a3, 0x1062
    ctx->r7 = S32(0X1062 << 16);
    // 0x8008EF9C: ori         $a3, $a3, 0x4DD3
    ctx->r7 = ctx->r7 | 0X4DD3;
    // 0x8008EFA0: addu        $a2, $s2, $zero
    ctx->r6 = ADD32(ctx->r18, 0);
    // 0x8008EFA4: addu        $a1, $s3, $zero
    ctx->r5 = ADD32(ctx->r19, 0);
    // 0x8008EFA8: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
L_8008EFAC:
    // 0x8008EFAC: lhu         $v0, 0x2($a1)
    ctx->r2 = MEM_HU(ctx->r5, 0X2);
    // 0x8008EFB0: mult        $t0, $v0
    result = S64(S32(ctx->r8)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8008EFB4: mflo        $v0
    ctx->r2 = lo;
    // 0x8008EFB8: nop

    // 0x8008EFBC: nop

    // 0x8008EFC0: multu       $v0, $a3
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r7)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8008EFC4: mfhi        $t1
    ctx->r9 = hi;
    // 0x8008EFC8: srl         $v0, $t1, 6
    ctx->r2 = S32(U32(ctx->r9) >> 6);
    // 0x8008EFCC: addiu       $v0, $v0, 0x3
    ctx->r2 = ADD32(ctx->r2, 0X3);
    // 0x8008EFD0: andi        $v0, $v0, 0xFFFC
    ctx->r2 = ctx->r2 & 0XFFFC;
    // 0x8008EFD4: sw          $v0, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r2;
    // 0x8008EFD8: addu        $v0, $s3, $v1
    ctx->r2 = ADD32(ctx->r19, ctx->r3);
    // 0x8008EFDC: lbu         $v0, 0x12($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X12);
    // 0x8008EFE0: addiu       $a1, $a1, 0x2
    ctx->r5 = ADD32(ctx->r5, 0X2);
    // 0x8008EFE4: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8008EFE8: sll         $v0, $v0, 8
    ctx->r2 = S32(ctx->r2 << 8);
    // 0x8008EFEC: sh          $v0, 0x2C($a2)
    MEM_H(0X2C, ctx->r6) = ctx->r2;
    // 0x8008EFF0: lbu         $v0, 0x1A($s3)
    ctx->r2 = MEM_BU(ctx->r19, 0X1A);
    // 0x8008EFF4: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x8008EFF8: sltu        $v0, $v1, $v0
    ctx->r2 = ctx->r3 < ctx->r2 ? 1 : 0;
    // 0x8008EFFC: bne         $v0, $zero, L_8008EFAC
    if (ctx->r2 != 0) {
        // 0x8008F000: addiu       $a2, $a2, 0x2
        ctx->r6 = ADD32(ctx->r6, 0X2);
            goto L_8008EFAC;
    }
    // 0x8008F000: addiu       $a2, $a2, 0x2
    ctx->r6 = ADD32(ctx->r6, 0X2);
L_8008F004:
    // 0x8008F004: lbu         $v1, 0x1C($s3)
    ctx->r3 = MEM_BU(ctx->r19, 0X1C);
    // 0x8008F008: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8008F00C: bne         $v1, $v0, L_8008F044
    if (ctx->r3 != ctx->r2) {
        // 0x8008F010: addiu       $v0, $zero, 0x7FFF
        ctx->r2 = ADD32(0, 0X7FFF);
            goto L_8008F044;
    }
    // 0x8008F010: addiu       $v0, $zero, 0x7FFF
    ctx->r2 = ADD32(0, 0X7FFF);
    // 0x8008F014: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
    // 0x8008F018: addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    // 0x8008F01C: addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
L_8008F020:
    // 0x8008F020: lhu         $v0, 0x1E($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X1E);
    // 0x8008F024: addiu       $a0, $a0, 0x2
    ctx->r4 = ADD32(ctx->r4, 0X2);
    // 0x8008F028: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8008F02C: sh          $v0, 0x40($a1)
    MEM_H(0X40, ctx->r5) = ctx->r2;
    // 0x8008F030: sltiu       $v0, $v1, 0x4
    ctx->r2 = ctx->r3 < 0X4 ? 1 : 0;
    // 0x8008F034: bne         $v0, $zero, L_8008F020
    if (ctx->r2 != 0) {
        // 0x8008F038: addiu       $a1, $a1, 0x2
        ctx->r5 = ADD32(ctx->r5, 0X2);
            goto L_8008F020;
    }
    // 0x8008F038: addiu       $a1, $a1, 0x2
    ctx->r5 = ADD32(ctx->r5, 0X2);
    // 0x8008F03C: j           L_8008F058
    // 0x8008F040: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
        goto L_8008F058;
    // 0x8008F040: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
L_8008F044:
    // 0x8008F044: sh          $zero, 0x40($s2)
    MEM_H(0X40, ctx->r18) = 0;
    // 0x8008F048: sh          $zero, 0x42($s2)
    MEM_H(0X42, ctx->r18) = 0;
    // 0x8008F04C: sh          $zero, 0x44($s2)
    MEM_H(0X44, ctx->r18) = 0;
    // 0x8008F050: sh          $v0, 0x46($s2)
    MEM_H(0X46, ctx->r18) = ctx->r2;
    // 0x8008F054: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
L_8008F058:
    // 0x8008F058: jal         0x800358B0
    // 0x8008F05C: addiu       $a1, $zero, 0x48
    ctx->r5 = ADD32(0, 0X48);
    osWritebackDCache_recomp(rdram, ctx);
        goto after_3;
    // 0x8008F05C: addiu       $a1, $zero, 0x48
    ctx->r5 = ADD32(0, 0X48);
    after_3:
    // 0x8008F060: jal         0x80092010
    // 0x8008F064: nop

    func_80092010(rdram, ctx);
        goto after_4;
    // 0x8008F064: nop

    after_4:
    // 0x8008F068: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8008F06C: sw          $zero, -0x6894($at)
    MEM_W(-0X6894, ctx->r1) = 0;
    // 0x8008F070: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8008F074: sw          $s2, -0x6898($at)
    MEM_W(-0X6898, ctx->r1) = ctx->r18;
    // 0x8008F078: jal         0x8009205C
    // 0x8008F07C: nop

    func_8009205C(rdram, ctx);
        goto after_5;
    // 0x8008F07C: nop

    after_5:
L_8008F080:
    // 0x8008F080: lw          $ra, 0x28($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X28);
    // 0x8008F084: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x8008F088: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8008F08C: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8008F090: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8008F094: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8008F098: jr          $ra
    // 0x8008F09C: nop

    return;
    // 0x8008F09C: nop

;}
RECOMP_FUNC void func_8008F0A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008F0A0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8008F0A4: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x8008F0A8: addu        $s1, $a1, $zero
    ctx->r17 = ADD32(ctx->r5, 0);
    // 0x8008F0AC: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x8008F0B0: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x8008F0B4: andi        $v0, $s0, 0xFFFF
    ctx->r2 = ctx->r16 & 0XFFFF;
    // 0x8008F0B8: sll         $a0, $v0, 4
    ctx->r4 = S32(ctx->r2 << 4);
    // 0x8008F0BC: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // 0x8008F0C0: sll         $a0, $a0, 3
    ctx->r4 = S32(ctx->r4 << 3);
    // 0x8008F0C4: sw          $ra, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r31;
    // 0x8008F0C8: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8008F0CC: sh          $s0, -0x6900($at)
    MEM_H(-0X6900, ctx->r1) = ctx->r16;
    // 0x8008F0D0: jal         0x80001ACC
    // 0x8008F0D4: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    rs_malloc(rdram, ctx);
        goto after_0;
    // 0x8008F0D4: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    after_0:
    // 0x8008F0D8: lui         $v1, 0x8015
    ctx->r3 = S32(0X8015 << 16);
    // 0x8008F0DC: lhu         $v1, -0x6900($v1)
    ctx->r3 = MEM_HU(ctx->r3, -0X6900);
    // 0x8008F0E0: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8008F0E4: sw          $v0, -0x6904($at)
    MEM_W(-0X6904, ctx->r1) = ctx->r2;
    // 0x8008F0E8: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8008F0EC: sw          $v0, -0x6908($at)
    MEM_W(-0X6908, ctx->r1) = ctx->r2;
    // 0x8008F0F0: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8008F0F4: sb          $zero, -0x68FE($at)
    MEM_B(-0X68FE, ctx->r1) = 0;
    // 0x8008F0F8: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8008F0FC: sh          $zero, -0x68F0($at)
    MEM_H(-0X68F0, ctx->r1) = 0;
    // 0x8008F100: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8008F104: sh          $zero, -0x68EE($at)
    MEM_H(-0X68EE, ctx->r1) = 0;
    // 0x8008F108: beq         $v1, $zero, L_8008F170
    if (ctx->r3 == 0) {
        // 0x8008F10C: addu        $a1, $zero, $zero
        ctx->r5 = ADD32(0, 0);
            goto L_8008F170;
    }
    // 0x8008F10C: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x8008F110: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    // 0x8008F114: andi        $a0, $a1, 0xFFFF
    ctx->r4 = ctx->r5 & 0XFFFF;
L_8008F118:
    // 0x8008F118: lui         $v0, 0x8015
    ctx->r2 = S32(0X8015 << 16);
    // 0x8008F11C: lw          $v0, -0x6904($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X6904);
    // 0x8008F120: sll         $v1, $a0, 4
    ctx->r3 = S32(ctx->r4 << 4);
    // 0x8008F124: addu        $v1, $v1, $a0
    ctx->r3 = ADD32(ctx->r3, ctx->r4);
    // 0x8008F128: sll         $v1, $v1, 3
    ctx->r3 = S32(ctx->r3 << 3);
    // 0x8008F12C: addu        $v0, $v1, $v0
    ctx->r2 = ADD32(ctx->r3, ctx->r2);
    // 0x8008F130: sb          $zero, 0x0($v0)
    MEM_B(0X0, ctx->r2) = 0;
    // 0x8008F134: lui         $v0, 0x8015
    ctx->r2 = S32(0X8015 << 16);
    // 0x8008F138: lw          $v0, -0x6904($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X6904);
    // 0x8008F13C: addu        $v0, $v1, $v0
    ctx->r2 = ADD32(ctx->r3, ctx->r2);
    // 0x8008F140: sb          $zero, 0x85($v0)
    MEM_B(0X85, ctx->r2) = 0;
    // 0x8008F144: lui         $v0, 0x8015
    ctx->r2 = S32(0X8015 << 16);
    // 0x8008F148: lw          $v0, -0x6904($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X6904);
    // 0x8008F14C: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x8008F150: sb          $a2, 0x84($v1)
    MEM_B(0X84, ctx->r3) = ctx->r6;
    // 0x8008F154: lui         $v1, 0x8015
    ctx->r3 = S32(0X8015 << 16);
    // 0x8008F158: lhu         $v1, -0x6900($v1)
    ctx->r3 = MEM_HU(ctx->r3, -0X6900);
    // 0x8008F15C: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x8008F160: andi        $v0, $a1, 0xFFFF
    ctx->r2 = ctx->r5 & 0XFFFF;
    // 0x8008F164: sltu        $v0, $v0, $v1
    ctx->r2 = ctx->r2 < ctx->r3 ? 1 : 0;
    // 0x8008F168: bne         $v0, $zero, L_8008F118
    if (ctx->r2 != 0) {
        // 0x8008F16C: andi        $a0, $a1, 0xFFFF
        ctx->r4 = ctx->r5 & 0XFFFF;
            goto L_8008F118;
    }
    // 0x8008F16C: andi        $a0, $a1, 0xFFFF
    ctx->r4 = ctx->r5 & 0XFFFF;
L_8008F170:
    // 0x8008F170: mtc1        $s1, $f4
    ctx->f4.u32l = ctx->r17;
    // 0x8008F174: cvt.d.w     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.d = CVT_D_W(ctx->f4.u32l);
    // 0x8008F178: bgez        $s1, L_8008F18C
    if (SIGNED(ctx->r17) >= 0) {
        // 0x8008F17C: nop
    
            goto L_8008F18C;
    }
    // 0x8008F17C: nop

    // 0x8008F180: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8008F184: ldc1        $f0, -0x22B0($at)
    CHECK_FR(ctx, 0);
    ctx->f0.u64 = LD(ctx->r1, -0X22B0);
    // 0x8008F188: add.d       $f4, $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f0.d); 
    ctx->f4.d = ctx->f4.d + ctx->f0.d;
L_8008F18C:
    // 0x8008F18C: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8008F190: lwc1        $f2, -0x22A8($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X22A8);
    // 0x8008F194: cvt.s.d     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f0.fl = CVT_S_D(ctx->f4.d);
    // 0x8008F198: div.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f2.fl);
    // 0x8008F19C: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8008F1A0: lwc1        $f2, -0x22A4($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X22A4);
    // 0x8008F1A4: div.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f2.fl);
    // 0x8008F1A8: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8008F1AC: lwc1        $f2, -0x22A0($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X22A0);
    // 0x8008F1B0: mul.s       $f2, $f0, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x8008F1B4: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8008F1B8: lwc1        $f0, -0x229C($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X229C);
    // 0x8008F1BC: c.le.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl <= ctx->f2.fl;
    // 0x8008F1C0: nop

    // 0x8008F1C4: bc1tl       L_8008F1DC
    if (c1cs) {
        // 0x8008F1C8: sub.s       $f0, $f2, $f0
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f2.fl - ctx->f0.fl;
            goto L_8008F1DC;
    }
    goto skip_0;
    // 0x8008F1C8: sub.s       $f0, $f2, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f2.fl - ctx->f0.fl;
    skip_0:
    // 0x8008F1CC: trunc.w.s   $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.u32l = TRUNC_W_S(ctx->f2.fl);
    // 0x8008F1D0: mfc1        $v1, $f0
    ctx->r3 = (int32_t)ctx->f0.u32l;
    // 0x8008F1D4: j           L_8008F1F0
    // 0x8008F1D8: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
        goto L_8008F1F0;
    // 0x8008F1D8: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
L_8008F1DC:
    // 0x8008F1DC: trunc.w.s   $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x8008F1E0: mfc1        $v1, $f2
    ctx->r3 = (int32_t)ctx->f2.u32l;
    // 0x8008F1E4: lui         $v0, 0x8000
    ctx->r2 = S32(0X8000 << 16);
    // 0x8008F1E8: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x8008F1EC: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
L_8008F1F0:
    // 0x8008F1F0: andi        $v0, $v1, 0xFFFF
    ctx->r2 = ctx->r3 & 0XFFFF;
    // 0x8008F1F4: sll         $a0, $v0, 2
    ctx->r4 = S32(ctx->r2 << 2);
    // 0x8008F1F8: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // 0x8008F1FC: sll         $a0, $a0, 5
    ctx->r4 = S32(ctx->r4 << 5);
    // 0x8008F200: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // 0x8008F204: sll         $a0, $a0, 4
    ctx->r4 = S32(ctx->r4 << 4);
    // 0x8008F208: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8008F20C: sh          $v1, -0x68B2($at)
    MEM_H(-0X68B2, ctx->r1) = ctx->r3;
    // 0x8008F210: jal         0x80001ACC
    // 0x8008F214: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    rs_malloc(rdram, ctx);
        goto after_1;
    // 0x8008F214: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    after_1:
    // 0x8008F218: lui         $v1, 0x8015
    ctx->r3 = S32(0X8015 << 16);
    // 0x8008F21C: lhu         $v1, -0x68B2($v1)
    ctx->r3 = MEM_HU(ctx->r3, -0X68B2);
    // 0x8008F220: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x8008F224: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8008F228: sw          $v0, -0x68A8($at)
    MEM_W(-0X68A8, ctx->r1) = ctx->r2;
    // 0x8008F22C: sll         $a0, $v1, 2
    ctx->r4 = S32(ctx->r3 << 2);
    // 0x8008F230: addu        $a0, $a0, $v1
    ctx->r4 = ADD32(ctx->r4, ctx->r3);
    // 0x8008F234: sll         $a0, $a0, 5
    ctx->r4 = S32(ctx->r4 << 5);
    // 0x8008F238: addu        $a0, $a0, $v1
    ctx->r4 = ADD32(ctx->r4, ctx->r3);
    // 0x8008F23C: jal         0x80001ACC
    // 0x8008F240: sll         $a0, $a0, 4
    ctx->r4 = S32(ctx->r4 << 4);
    rs_malloc(rdram, ctx);
        goto after_2;
    // 0x8008F240: sll         $a0, $a0, 4
    ctx->r4 = S32(ctx->r4 << 4);
    after_2:
    // 0x8008F244: lui         $a2, 0x8015
    ctx->r6 = S32(0X8015 << 16);
    // 0x8008F248: lhu         $a2, -0x68B2($a2)
    ctx->r6 = MEM_HU(ctx->r6, -0X68B2);
    // 0x8008F24C: andi        $v1, $s0, 0xFFFF
    ctx->r3 = ctx->r16 & 0XFFFF;
    // 0x8008F250: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8008F254: mult        $a2, $v1
    result = S64(S32(ctx->r6)) * S64(S32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8008F258: mflo        $a2
    ctx->r6 = lo;
    // 0x8008F25C: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x8008F260: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8008F264: sw          $v0, -0x68A4($at)
    MEM_W(-0X68A4, ctx->r1) = ctx->r2;
    // 0x8008F268: andi        $v0, $a2, 0xFFFF
    ctx->r2 = ctx->r6 & 0XFFFF;
    // 0x8008F26C: sll         $a0, $v0, 4
    ctx->r4 = S32(ctx->r2 << 4);
    // 0x8008F270: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // 0x8008F274: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8008F278: sh          $a2, -0x68FC($at)
    MEM_H(-0X68FC, ctx->r1) = ctx->r6;
    // 0x8008F27C: jal         0x80001ACC
    // 0x8008F280: sll         $a0, $a0, 3
    ctx->r4 = S32(ctx->r4 << 3);
    rs_malloc(rdram, ctx);
        goto after_3;
    // 0x8008F280: sll         $a0, $a0, 3
    ctx->r4 = S32(ctx->r4 << 3);
    after_3:
    // 0x8008F284: lui         $v1, 0x8015
    ctx->r3 = S32(0X8015 << 16);
    // 0x8008F288: lhu         $v1, -0x68FC($v1)
    ctx->r3 = MEM_HU(ctx->r3, -0X68FC);
    // 0x8008F28C: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x8008F290: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8008F294: sw          $v0, -0x68F8($at)
    MEM_W(-0X68F8, ctx->r1) = ctx->r2;
    // 0x8008F298: sll         $a0, $v1, 4
    ctx->r4 = S32(ctx->r3 << 4);
    // 0x8008F29C: addu        $a0, $a0, $v1
    ctx->r4 = ADD32(ctx->r4, ctx->r3);
    // 0x8008F2A0: jal         0x80001ACC
    // 0x8008F2A4: sll         $a0, $a0, 3
    ctx->r4 = S32(ctx->r4 << 3);
    rs_malloc(rdram, ctx);
        goto after_4;
    // 0x8008F2A4: sll         $a0, $a0, 3
    ctx->r4 = S32(ctx->r4 << 3);
    after_4:
    // 0x8008F2A8: addiu       $a0, $zero, 0x298
    ctx->r4 = ADD32(0, 0X298);
    // 0x8008F2AC: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8008F2B0: sw          $v0, -0x68F4($at)
    MEM_W(-0X68F4, ctx->r1) = ctx->r2;
    // 0x8008F2B4: jal         0x80001ACC
    // 0x8008F2B8: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    rs_malloc(rdram, ctx);
        goto after_5;
    // 0x8008F2B8: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    after_5:
    // 0x8008F2BC: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // 0x8008F2C0: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x8008F2C4: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8008F2C8: sw          $a0, -0x689C($at)
    MEM_W(-0X689C, ctx->r1) = ctx->r4;
    // 0x8008F2CC: jal         0x800078E0
    // 0x8008F2D0: addiu       $a2, $zero, 0x298
    ctx->r6 = ADD32(0, 0X298);
    rs_memset(rdram, ctx);
        goto after_6;
    // 0x8008F2D0: addiu       $a2, $zero, 0x298
    ctx->r6 = ADD32(0, 0X298);
    after_6:
    // 0x8008F2D4: lui         $a0, 0x8015
    ctx->r4 = S32(0X8015 << 16);
    // 0x8008F2D8: lw          $a0, -0x689C($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X689C);
    // 0x8008F2DC: jal         0x800358B0
    // 0x8008F2E0: addiu       $a1, $zero, 0x298
    ctx->r5 = ADD32(0, 0X298);
    osWritebackDCache_recomp(rdram, ctx);
        goto after_7;
    // 0x8008F2E0: addiu       $a1, $zero, 0x298
    ctx->r5 = ADD32(0, 0X298);
    after_7:
    // 0x8008F2E4: lw          $ra, 0x18($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X18);
    // 0x8008F2E8: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x8008F2EC: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x8008F2F0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8008F2F4: jr          $ra
    // 0x8008F2F8: nop

    return;
    // 0x8008F2F8: nop

;}
RECOMP_FUNC void func_8008F2FC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008F2FC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8008F300: mtc1        $a1, $f4
    ctx->f4.u32l = ctx->r5;
    // 0x8008F304: cvt.d.w     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.d = CVT_D_W(ctx->f4.u32l);
    // 0x8008F308: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x8008F30C: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x8008F310: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x8008F314: addu        $s1, $a2, $zero
    ctx->r17 = ADD32(ctx->r6, 0);
    // 0x8008F318: andi        $a0, $s0, 0xFFFF
    ctx->r4 = ctx->r16 & 0XFFFF;
    // 0x8008F31C: bgez        $a1, L_8008F330
    if (SIGNED(ctx->r5) >= 0) {
        // 0x8008F320: sw          $ra, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r31;
            goto L_8008F330;
    }
    // 0x8008F320: sw          $ra, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r31;
    // 0x8008F324: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8008F328: ldc1        $f0, -0x2298($at)
    CHECK_FR(ctx, 0);
    ctx->f0.u64 = LD(ctx->r1, -0X2298);
    // 0x8008F32C: add.d       $f4, $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f0.d); 
    ctx->f4.d = ctx->f4.d + ctx->f0.d;
L_8008F330:
    // 0x8008F330: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8008F334: lwc1        $f2, -0x2290($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X2290);
    // 0x8008F338: cvt.s.d     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f0.fl = CVT_S_D(ctx->f4.d);
    // 0x8008F33C: div.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f2.fl);
    // 0x8008F340: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8008F344: lwc1        $f2, -0x228C($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X228C);
    // 0x8008F348: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x8008F34C: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8008F350: lwc1        $f2, -0x2288($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X2288);
    // 0x8008F354: div.s       $f2, $f0, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = DIV_S(ctx->f0.fl, ctx->f2.fl);
    // 0x8008F358: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8008F35C: lwc1        $f0, -0x2284($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X2284);
    // 0x8008F360: c.le.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl <= ctx->f2.fl;
    // 0x8008F364: nop

    // 0x8008F368: bc1tl       L_8008F380
    if (c1cs) {
        // 0x8008F36C: sub.s       $f0, $f2, $f0
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f2.fl - ctx->f0.fl;
            goto L_8008F380;
    }
    goto skip_0;
    // 0x8008F36C: sub.s       $f0, $f2, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f2.fl - ctx->f0.fl;
    skip_0:
    // 0x8008F370: trunc.w.s   $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.u32l = TRUNC_W_S(ctx->f2.fl);
    // 0x8008F374: mfc1        $v1, $f0
    ctx->r3 = (int32_t)ctx->f0.u32l;
    // 0x8008F378: j           L_8008F394
    // 0x8008F37C: andi        $v0, $v1, 0xFFFF
    ctx->r2 = ctx->r3 & 0XFFFF;
        goto L_8008F394;
    // 0x8008F37C: andi        $v0, $v1, 0xFFFF
    ctx->r2 = ctx->r3 & 0XFFFF;
L_8008F380:
    // 0x8008F380: trunc.w.s   $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x8008F384: mfc1        $v1, $f2
    ctx->r3 = (int32_t)ctx->f2.u32l;
    // 0x8008F388: lui         $v0, 0x8000
    ctx->r2 = S32(0X8000 << 16);
    // 0x8008F38C: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x8008F390: andi        $v0, $v1, 0xFFFF
    ctx->r2 = ctx->r3 & 0XFFFF;
L_8008F394:
    // 0x8008F394: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8008F398: mult        $a0, $v0
    result = S64(S32(ctx->r4)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8008F39C: mflo        $v0
    ctx->r2 = lo;
    // 0x8008F3A0: addiu       $a0, $zero, 0x310
    ctx->r4 = ADD32(0, 0X310);
    // 0x8008F3A4: andi        $v1, $v0, 0xFFFF
    ctx->r3 = ctx->r2 & 0XFFFF;
    // 0x8008F3A8: mult        $v1, $a0
    result = S64(S32(ctx->r3)) * S64(S32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8008F3AC: mflo        $v1
    ctx->r3 = lo;
    // 0x8008F3B0: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8008F3B4: sw          $a0, -0x68E0($at)
    MEM_W(-0X68E0, ctx->r1) = ctx->r4;
    // 0x8008F3B8: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8008F3BC: sh          $v0, -0x68E4($at)
    MEM_H(-0X68E4, ctx->r1) = ctx->r2;
    // 0x8008F3C0: mtc1        $v1, $f4
    ctx->f4.u32l = ctx->r3;
    // 0x8008F3C4: cvt.d.w     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.d = CVT_D_W(ctx->f4.u32l);
    // 0x8008F3C8: bgez        $v1, L_8008F3DC
    if (SIGNED(ctx->r3) >= 0) {
        // 0x8008F3CC: nop
    
            goto L_8008F3DC;
    }
    // 0x8008F3CC: nop

    // 0x8008F3D0: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8008F3D4: ldc1        $f0, -0x2280($at)
    CHECK_FR(ctx, 0);
    ctx->f0.u64 = LD(ctx->r1, -0X2280);
    // 0x8008F3D8: add.d       $f4, $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f0.d); 
    ctx->f4.d = ctx->f4.d + ctx->f0.d;
L_8008F3DC:
    // 0x8008F3DC: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8008F3E0: lwc1        $f2, -0x2278($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X2278);
    // 0x8008F3E4: cvt.s.d     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f0.fl = CVT_S_D(ctx->f4.d);
    // 0x8008F3E8: mul.s       $f2, $f0, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x8008F3EC: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8008F3F0: lwc1        $f0, -0x2274($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X2274);
    // 0x8008F3F4: c.le.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl <= ctx->f2.fl;
    // 0x8008F3F8: nop

    // 0x8008F3FC: bc1tl       L_8008F414
    if (c1cs) {
        // 0x8008F400: sub.s       $f0, $f2, $f0
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f2.fl - ctx->f0.fl;
            goto L_8008F414;
    }
    goto skip_1;
    // 0x8008F400: sub.s       $f0, $f2, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f2.fl - ctx->f0.fl;
    skip_1:
    // 0x8008F404: trunc.w.s   $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.u32l = TRUNC_W_S(ctx->f2.fl);
    // 0x8008F408: mfc1        $v1, $f0
    ctx->r3 = (int32_t)ctx->f0.u32l;
    // 0x8008F40C: j           L_8008F428
    // 0x8008F410: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
        goto L_8008F428;
    // 0x8008F410: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
L_8008F414:
    // 0x8008F414: trunc.w.s   $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x8008F418: mfc1        $v1, $f2
    ctx->r3 = (int32_t)ctx->f2.u32l;
    // 0x8008F41C: lui         $v0, 0x8000
    ctx->r2 = S32(0X8000 << 16);
    // 0x8008F420: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x8008F424: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
L_8008F428:
    // 0x8008F428: addiu       $v1, $v1, 0x3F
    ctx->r3 = ADD32(ctx->r3, 0X3F);
    // 0x8008F42C: srl         $v1, $v1, 6
    ctx->r3 = S32(U32(ctx->r3) >> 6);
    // 0x8008F430: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x8008F434: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8008F438: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x8008F43C: lui         $v1, 0x8015
    ctx->r3 = S32(0X8015 << 16);
    // 0x8008F440: lhu         $v1, -0x68E4($v1)
    ctx->r3 = MEM_HU(ctx->r3, -0X68E4);
    // 0x8008F444: addiu       $v0, $v0, 0xF
    ctx->r2 = ADD32(ctx->r2, 0XF);
    // 0x8008F448: andi        $v0, $v0, 0xFFF0
    ctx->r2 = ctx->r2 & 0XFFF0;
    // 0x8008F44C: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8008F450: sw          $v0, -0x68E0($at)
    MEM_W(-0X68E0, ctx->r1) = ctx->r2;
    // 0x8008F454: sll         $a0, $v1, 1
    ctx->r4 = S32(ctx->r3 << 1);
    // 0x8008F458: addu        $a0, $a0, $v1
    ctx->r4 = ADD32(ctx->r4, ctx->r3);
    // 0x8008F45C: jal         0x80001ACC
    // 0x8008F460: sll         $a0, $a0, 3
    ctx->r4 = S32(ctx->r4 << 3);
    rs_malloc(rdram, ctx);
        goto after_0;
    // 0x8008F460: sll         $a0, $a0, 3
    ctx->r4 = S32(ctx->r4 << 3);
    after_0:
    // 0x8008F464: lui         $a0, 0x8015
    ctx->r4 = S32(0X8015 << 16);
    // 0x8008F468: addiu       $a0, $a0, -0x68D0
    ctx->r4 = ADD32(ctx->r4, -0X68D0);
    // 0x8008F46C: lui         $a1, 0x8015
    ctx->r5 = S32(0X8015 << 16);
    // 0x8008F470: addiu       $a1, $a1, -0x68B8
    ctx->r5 = ADD32(ctx->r5, -0X68B8);
    // 0x8008F474: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8008F478: sw          $v0, -0x68D8($at)
    MEM_W(-0X68D8, ctx->r1) = ctx->r2;
    // 0x8008F47C: jal         0x8002B300
    // 0x8008F480: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osCreateMesgQueue_recomp(rdram, ctx);
        goto after_1;
    // 0x8008F480: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_1:
    // 0x8008F484: lui         $a0, 0x8015
    ctx->r4 = S32(0X8015 << 16);
    // 0x8008F488: lhu         $a0, -0x68E4($a0)
    ctx->r4 = MEM_HU(ctx->r4, -0X68E4);
    // 0x8008F48C: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8008F490: sb          $zero, -0x68B4($at)
    MEM_B(-0X68B4, ctx->r1) = 0;
    // 0x8008F494: jal         0x8008F65C
    // 0x8008F498: nop

    func_8008F65C(rdram, ctx);
        goto after_2;
    // 0x8008F498: nop

    after_2:
    // 0x8008F49C: andi        $v0, $s1, 0xFF
    ctx->r2 = ctx->r17 & 0XFF;
    // 0x8008F4A0: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x8008F4A4: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x8008F4A8: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x8008F4AC: lhu         $a0, 0x1760($at)
    ctx->r4 = MEM_HU(ctx->r1, 0X1760);
    // 0x8008F4B0: mult        $a0, $s0
    result = S64(S32(ctx->r4)) * S64(S32(ctx->r16)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8008F4B4: mflo        $a0
    ctx->r4 = lo;
    // 0x8008F4B8: jal         0x8008F858
    // 0x8008F4BC: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    func_8008F858(rdram, ctx);
        goto after_3;
    // 0x8008F4BC: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    after_3:
    // 0x8008F4C0: lw          $ra, 0x18($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X18);
    // 0x8008F4C4: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x8008F4C8: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x8008F4CC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8008F4D0: jr          $ra
    // 0x8008F4D4: nop

    return;
    // 0x8008F4D4: nop

;}
RECOMP_FUNC void func_8008F4D8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008F4D8: andi        $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 & 0XFFFF;
    // 0x8008F4DC: sll         $v0, $a1, 5
    ctx->r2 = S32(ctx->r5 << 5);
    // 0x8008F4E0: subu        $v0, $v0, $a1
    ctx->r2 = SUB32(ctx->r2, ctx->r5);
    // 0x8008F4E4: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8008F4E8: lui         $v1, 0x8015
    ctx->r3 = S32(0X8015 << 16);
    // 0x8008F4EC: lw          $v1, -0x690C($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X690C);
    // 0x8008F4F0: addu        $v0, $v0, $a1
    ctx->r2 = ADD32(ctx->r2, ctx->r5);
    // 0x8008F4F4: sll         $v0, $v0, 8
    ctx->r2 = S32(ctx->r2 << 8);
    // 0x8008F4F8: divu        $zero, $v0, $v1
    if (U32(ctx->r3) != 0) { lo = S32(U32(ctx->r2) / U32(ctx->r3)); hi = S32(U32(ctx->r2) % U32(ctx->r3)); } else { lo = 0; hi = S32(ctx->r2); }
    // 0x8008F4FC: bne         $v1, $zero, L_8008F508
    if (ctx->r3 != 0) {
        // 0x8008F500: nop
    
            goto L_8008F508;
    }
    // 0x8008F500: nop

    // 0x8008F504: break       7
    do_break(2148070660);
L_8008F508:
    // 0x8008F508: mflo        $v0
    ctx->r2 = lo;
    // 0x8008F50C: lbu         $v1, 0x1($a0)
    ctx->r3 = MEM_BU(ctx->r4, 0X1);
    // 0x8008F510: bne         $v1, $zero, L_8008F548
    if (ctx->r3 != 0) {
        // 0x8008F514: sll         $a1, $v0, 11
        ctx->r5 = S32(ctx->r2 << 11);
            goto L_8008F548;
    }
    // 0x8008F514: sll         $a1, $v0, 11
    ctx->r5 = S32(ctx->r2 << 11);
    // 0x8008F518: lbu         $v1, 0x6C($a0)
    ctx->r3 = MEM_BU(ctx->r4, 0X6C);
    // 0x8008F51C: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x8008F520: beq         $v1, $v0, L_8008F548
    if (ctx->r3 == ctx->r2) {
        // 0x8008F524: addiu       $v0, $zero, 0x3
        ctx->r2 = ADD32(0, 0X3);
            goto L_8008F548;
    }
    // 0x8008F524: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x8008F528: lwc1        $f0, 0x5C($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X5C);
    // 0x8008F52C: lhu         $v1, 0x30($a0)
    ctx->r3 = MEM_HU(ctx->r4, 0X30);
    // 0x8008F530: sb          $v0, 0x6C($a0)
    MEM_B(0X6C, ctx->r4) = ctx->r2;
    // 0x8008F534: sw          $zero, 0x64($a0)
    MEM_W(0X64, ctx->r4) = 0;
    // 0x8008F538: sw          $zero, 0x60($a0)
    MEM_W(0X60, ctx->r4) = 0;
    // 0x8008F53C: swc1        $f0, 0x68($a0)
    MEM_W(0X68, ctx->r4) = ctx->f0.u32l;
    // 0x8008F540: j           L_8008F5E4
    // 0x8008F544: sh          $v1, 0x58($a0)
    MEM_H(0X58, ctx->r4) = ctx->r3;
        goto L_8008F5E4;
    // 0x8008F544: sh          $v1, 0x58($a0)
    MEM_H(0X58, ctx->r4) = ctx->r3;
L_8008F548:
    // 0x8008F548: lhu         $v0, 0x60($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X60);
    // 0x8008F54C: lhu         $v1, 0x58($a0)
    ctx->r3 = MEM_HU(ctx->r4, 0X58);
    // 0x8008F550: sltu        $v0, $v0, $v1
    ctx->r2 = ctx->r2 < ctx->r3 ? 1 : 0;
    // 0x8008F554: bne         $v0, $zero, L_8008F5E8
    if (ctx->r2 != 0) {
        // 0x8008F558: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_8008F5E8;
    }
    // 0x8008F558: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8008F55C: lbu         $v1, 0x6C($a0)
    ctx->r3 = MEM_BU(ctx->r4, 0X6C);
    // 0x8008F560: beq         $v1, $v0, L_8008F5B8
    if (ctx->r3 == ctx->r2) {
        // 0x8008F564: slti        $v0, $v1, 0x2
        ctx->r2 = SIGNED(ctx->r3) < 0X2 ? 1 : 0;
            goto L_8008F5B8;
    }
    // 0x8008F564: slti        $v0, $v1, 0x2
    ctx->r2 = SIGNED(ctx->r3) < 0X2 ? 1 : 0;
    // 0x8008F568: beql        $v0, $zero, L_8008F580
    if (ctx->r2 == 0) {
        // 0x8008F56C: addiu       $v0, $zero, 0x3
        ctx->r2 = ADD32(0, 0X3);
            goto L_8008F580;
    }
    goto skip_0;
    // 0x8008F56C: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    skip_0:
    // 0x8008F570: beq         $v1, $zero, L_8008F590
    if (ctx->r3 == 0) {
        // 0x8008F574: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_8008F590;
    }
    // 0x8008F574: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8008F578: j           L_8008F5E4
    // 0x8008F57C: nop

        goto L_8008F5E4;
    // 0x8008F57C: nop

L_8008F580:
    // 0x8008F580: beql        $v1, $v0, L_8008F5DC
    if (ctx->r3 == ctx->r2) {
        // 0x8008F584: sb          $zero, 0x0($a2)
        MEM_B(0X0, ctx->r6) = 0;
            goto L_8008F5DC;
    }
    goto skip_1;
    // 0x8008F584: sb          $zero, 0x0($a2)
    MEM_B(0X0, ctx->r6) = 0;
    skip_1:
    // 0x8008F588: j           L_8008F5E4
    // 0x8008F58C: nop

        goto L_8008F5E4;
    // 0x8008F58C: nop

L_8008F590:
    // 0x8008F590: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8008F594: lwc1        $f0, -0x2270($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X2270);
    // 0x8008F598: lwc1        $f2, 0x2C($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X2C);
    // 0x8008F59C: lhu         $v1, 0x2A($a0)
    ctx->r3 = MEM_HU(ctx->r4, 0X2A);
    // 0x8008F5A0: sb          $v0, 0x6C($a0)
    MEM_B(0X6C, ctx->r4) = ctx->r2;
    // 0x8008F5A4: sw          $zero, 0x60($a0)
    MEM_W(0X60, ctx->r4) = 0;
    // 0x8008F5A8: swc1        $f0, 0x68($a0)
    MEM_W(0X68, ctx->r4) = ctx->f0.u32l;
    // 0x8008F5AC: swc1        $f2, 0x64($a0)
    MEM_W(0X64, ctx->r4) = ctx->f2.u32l;
    // 0x8008F5B0: j           L_8008F5E4
    // 0x8008F5B4: sh          $v1, 0x58($a0)
    MEM_H(0X58, ctx->r4) = ctx->r3;
        goto L_8008F5E4;
    // 0x8008F5B4: sh          $v1, 0x58($a0)
    MEM_H(0X58, ctx->r4) = ctx->r3;
L_8008F5B8:
    // 0x8008F5B8: lwc1        $f0, 0x2C($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X2C);
    // 0x8008F5BC: lwc1        $f2, 0x2C($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X2C);
    // 0x8008F5C0: lwc1        $f4, 0x2C($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X2C);
    // 0x8008F5C4: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x8008F5C8: sb          $v0, 0x6C($a0)
    MEM_B(0X6C, ctx->r4) = ctx->r2;
    // 0x8008F5CC: swc1        $f0, 0x68($a0)
    MEM_W(0X68, ctx->r4) = ctx->f0.u32l;
    // 0x8008F5D0: swc1        $f2, 0x64($a0)
    MEM_W(0X64, ctx->r4) = ctx->f2.u32l;
    // 0x8008F5D4: j           L_8008F654
    // 0x8008F5D8: swc1        $f4, 0x5C($a0)
    MEM_W(0X5C, ctx->r4) = ctx->f4.u32l;
        goto L_8008F654;
    // 0x8008F5D8: swc1        $f4, 0x5C($a0)
    MEM_W(0X5C, ctx->r4) = ctx->f4.u32l;
L_8008F5DC:
    // 0x8008F5DC: j           L_8008F654
    // 0x8008F5E0: sw          $zero, 0x5C($a0)
    MEM_W(0X5C, ctx->r4) = 0;
        goto L_8008F654;
    // 0x8008F5E0: sw          $zero, 0x5C($a0)
    MEM_W(0X5C, ctx->r4) = 0;
L_8008F5E4:
    // 0x8008F5E4: lhu         $v1, 0x58($a0)
    ctx->r3 = MEM_HU(ctx->r4, 0X58);
L_8008F5E8:
    // 0x8008F5E8: beq         $v1, $zero, L_8008F628
    if (ctx->r3 == 0) {
        // 0x8008F5EC: nop
    
            goto L_8008F628;
    }
    // 0x8008F5EC: nop

    // 0x8008F5F0: lw          $v0, 0x60($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X60);
    // 0x8008F5F4: mtc1        $v0, $f2
    ctx->f2.u32l = ctx->r2;
    // 0x8008F5F8: cvt.d.w     $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    ctx->f2.d = CVT_D_W(ctx->f2.u32l);
    // 0x8008F5FC: bgezl       $v0, L_8008F614
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8008F600: cvt.s.d     $f0, $f2
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.d); 
    ctx->f0.fl = CVT_S_D(ctx->f2.d);
            goto L_8008F614;
    }
    goto skip_2;
    // 0x8008F600: cvt.s.d     $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.d); 
    ctx->f0.fl = CVT_S_D(ctx->f2.d);
    skip_2:
    // 0x8008F604: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8008F608: ldc1        $f0, -0x2268($at)
    CHECK_FR(ctx, 0);
    ctx->f0.u64 = LD(ctx->r1, -0X2268);
    // 0x8008F60C: add.d       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f0.d); 
    ctx->f2.d = ctx->f2.d + ctx->f0.d;
    // 0x8008F610: cvt.s.d     $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.d); 
    ctx->f0.fl = CVT_S_D(ctx->f2.d);
L_8008F614:
    // 0x8008F614: sll         $v0, $v1, 16
    ctx->r2 = S32(ctx->r3 << 16);
    // 0x8008F618: mtc1        $v0, $f2
    ctx->f2.u32l = ctx->r2;
    // 0x8008F61C: cvt.s.w     $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    ctx->f2.fl = CVT_S_W(ctx->f2.u32l);
    // 0x8008F620: j           L_8008F630
    // 0x8008F624: div.s       $f4, $f0, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = DIV_S(ctx->f0.fl, ctx->f2.fl);
        goto L_8008F630;
    // 0x8008F624: div.s       $f4, $f0, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = DIV_S(ctx->f0.fl, ctx->f2.fl);
L_8008F628:
    // 0x8008F628: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8008F62C: lwc1        $f4, -0x2260($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X2260);
L_8008F630:
    // 0x8008F630: lwc1        $f0, 0x64($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X64);
    // 0x8008F634: lwc1        $f2, 0x68($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X68);
    // 0x8008F638: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x8008F63C: mul.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x8008F640: lw          $v0, 0x60($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X60);
    // 0x8008F644: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x8008F648: addu        $v0, $v0, $a1
    ctx->r2 = ADD32(ctx->r2, ctx->r5);
    // 0x8008F64C: sw          $v0, 0x60($a0)
    MEM_W(0X60, ctx->r4) = ctx->r2;
    // 0x8008F650: swc1        $f0, 0x5C($a0)
    MEM_W(0X5C, ctx->r4) = ctx->f0.u32l;
L_8008F654:
    // 0x8008F654: jr          $ra
    // 0x8008F658: nop

    return;
    // 0x8008F658: nop

;}
RECOMP_FUNC void func_8008F65C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008F65C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8008F660: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x8008F664: addu        $s1, $a0, $zero
    ctx->r17 = ADD32(ctx->r4, 0);
    // 0x8008F668: sll         $a0, $s1, 2
    ctx->r4 = S32(ctx->r17 << 2);
    // 0x8008F66C: addu        $a0, $a0, $s1
    ctx->r4 = ADD32(ctx->r4, ctx->r17);
    // 0x8008F670: sll         $a0, $a0, 2
    ctx->r4 = S32(ctx->r4 << 2);
    // 0x8008F674: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x8008F678: sw          $ra, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r31;
    // 0x8008F67C: jal         0x80001ACC
    // 0x8008F680: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    rs_malloc(rdram, ctx);
        goto after_0;
    // 0x8008F680: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    after_0:
    // 0x8008F684: sll         $s0, $s1, 8
    ctx->r16 = S32(ctx->r17 << 8);
    // 0x8008F688: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x8008F68C: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8008F690: sw          $v0, -0x6640($at)
    MEM_W(-0X6640, ctx->r1) = ctx->r2;
    // 0x8008F694: jal         0x80001ACC
    // 0x8008F698: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    rs_malloc(rdram, ctx);
        goto after_1;
    // 0x8008F698: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    after_1:
    // 0x8008F69C: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // 0x8008F6A0: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8008F6A4: sw          $a0, -0x6644($at)
    MEM_W(-0X6644, ctx->r1) = ctx->r4;
    // 0x8008F6A8: jal         0x8002C280
    // 0x8008F6AC: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    osInvalDCache_recomp(rdram, ctx);
        goto after_2;
    // 0x8008F6AC: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    after_2:
    // 0x8008F6B0: lui         $v1, 0x8015
    ctx->r3 = S32(0X8015 << 16);
    // 0x8008F6B4: lw          $v1, -0x6640($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X6640);
    // 0x8008F6B8: lui         $a1, 0x8015
    ctx->r5 = S32(0X8015 << 16);
    // 0x8008F6BC: lw          $a1, -0x6644($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X6644);
    // 0x8008F6C0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8008F6C4: slt         $v0, $a0, $s1
    ctx->r2 = SIGNED(ctx->r4) < SIGNED(ctx->r17) ? 1 : 0;
    // 0x8008F6C8: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8008F6CC: sw          $zero, -0x6650($at)
    MEM_W(-0X6650, ctx->r1) = 0;
    // 0x8008F6D0: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8008F6D4: sw          $v1, -0x6654($at)
    MEM_W(-0X6654, ctx->r1) = ctx->r3;
    // 0x8008F6D8: sw          $a1, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r5;
    // 0x8008F6DC: beq         $v0, $zero, L_8008F71C
    if (ctx->r2 == 0) {
        // 0x8008F6E0: sw          $zero, 0x4($v1)
        MEM_W(0X4, ctx->r3) = 0;
            goto L_8008F71C;
    }
    // 0x8008F6E0: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x8008F6E4: addiu       $a2, $a1, 0x100
    ctx->r6 = ADD32(ctx->r5, 0X100);
    // 0x8008F6E8: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x8008F6EC: addu        $a3, $v1, $zero
    ctx->r7 = ADD32(ctx->r3, 0);
    // 0x8008F6F0: addiu       $v1, $a3, 0x14
    ctx->r3 = ADD32(ctx->r7, 0X14);
L_8008F6F4:
    // 0x8008F6F4: sw          $a2, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r6;
    // 0x8008F6F8: addiu       $a2, $a2, 0x100
    ctx->r6 = ADD32(ctx->r6, 0X100);
    // 0x8008F6FC: addu        $v0, $a3, $a1
    ctx->r2 = ADD32(ctx->r7, ctx->r5);
    // 0x8008F700: addiu       $a1, $a1, 0x14
    ctx->r5 = ADD32(ctx->r5, 0X14);
    // 0x8008F704: sw          $v0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r2;
    // 0x8008F708: sw          $v1, -0x14($v1)
    MEM_W(-0X14, ctx->r3) = ctx->r3;
    // 0x8008F70C: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x8008F710: slt         $v0, $a0, $s1
    ctx->r2 = SIGNED(ctx->r4) < SIGNED(ctx->r17) ? 1 : 0;
    // 0x8008F714: bne         $v0, $zero, L_8008F6F4
    if (ctx->r2 != 0) {
        // 0x8008F718: addiu       $v1, $v1, 0x14
        ctx->r3 = ADD32(ctx->r3, 0X14);
            goto L_8008F6F4;
    }
    // 0x8008F718: addiu       $v1, $v1, 0x14
    ctx->r3 = ADD32(ctx->r3, 0X14);
L_8008F71C:
    // 0x8008F71C: lui         $v1, 0x8015
    ctx->r3 = S32(0X8015 << 16);
    // 0x8008F720: lw          $v1, -0x6640($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X6640);
    // 0x8008F724: sll         $v0, $a0, 2
    ctx->r2 = S32(ctx->r4 << 2);
    // 0x8008F728: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x8008F72C: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8008F730: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8008F734: sw          $zero, -0x6648($at)
    MEM_W(-0X6648, ctx->r1) = 0;
    // 0x8008F738: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8008F73C: sw          $zero, -0x14($v0)
    MEM_W(-0X14, ctx->r2) = 0;
    // 0x8008F740: lw          $ra, 0x18($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X18);
    // 0x8008F744: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x8008F748: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x8008F74C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8008F750: jr          $ra
    // 0x8008F754: nop

    return;
    // 0x8008F754: nop

;}
