#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void func_8003EC10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003EC10: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8003EC14: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x8003EC18: lhu         $v1, 0x14($a0)
    ctx->r3 = MEM_HU(ctx->r4, 0X14);
    // 0x8003EC1C: andi        $v0, $v1, 0x4
    ctx->r2 = ctx->r3 & 0X4;
    // 0x8003EC20: beq         $v0, $zero, L_8003EC44
    if (ctx->r2 == 0) {
        // 0x8003EC24: andi        $v0, $v1, 0x1
        ctx->r2 = ctx->r3 & 0X1;
            goto L_8003EC44;
    }
    // 0x8003EC24: andi        $v0, $v1, 0x1
    ctx->r2 = ctx->r3 & 0X1;
    // 0x8003EC28: lw          $a0, 0x4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X4);
    // 0x8003EC2C: beq         $a0, $zero, L_8003ED68
    if (ctx->r4 == 0) {
        // 0x8003EC30: nop
    
            goto L_8003ED68;
    }
    // 0x8003EC30: nop

    // 0x8003EC34: jal         0x80001C98
    // 0x8003EC38: nop

    rs_free(rdram, ctx);
        goto after_0;
    // 0x8003EC38: nop

    after_0:
    // 0x8003EC3C: j           L_8003ED68
    // 0x8003EC40: nop

        goto L_8003ED68;
    // 0x8003EC40: nop

L_8003EC44:
    // 0x8003EC44: beq         $v0, $zero, L_8003EC54
    if (ctx->r2 == 0) {
        // 0x8003EC48: lui         $v0, 0x8013
        ctx->r2 = S32(0X8013 << 16);
            goto L_8003EC54;
    }
    // 0x8003EC48: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8003EC4C: j           L_8003EC5C
    // 0x8003EC50: addiu       $a3, $v0, 0xBC0
    ctx->r7 = ADD32(ctx->r2, 0XBC0);
        goto L_8003EC5C;
    // 0x8003EC50: addiu       $a3, $v0, 0xBC0
    ctx->r7 = ADD32(ctx->r2, 0XBC0);
L_8003EC54:
    // 0x8003EC54: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8003EC58: addiu       $a3, $v0, 0xBC4
    ctx->r7 = ADD32(ctx->r2, 0XBC4);
L_8003EC5C:
    // 0x8003EC5C: lhu         $v0, 0x14($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X14);
    // 0x8003EC60: andi        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 & 0X1;
    // 0x8003EC64: beq         $v0, $zero, L_8003EC80
    if (ctx->r2 == 0) {
        // 0x8003EC68: nop
    
            goto L_8003EC80;
    }
    // 0x8003EC68: nop

    // 0x8003EC6C: lw          $v1, 0x4($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X4);
    // 0x8003EC70: lbu         $v0, 0x18($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X18);
    // 0x8003EC74: addiu       $v1, $v1, -0x4C
    ctx->r3 = ADD32(ctx->r3, -0X4C);
    // 0x8003EC78: j           L_8003EC90
    // 0x8003EC7C: sll         $v0, $v0, 7
    ctx->r2 = S32(ctx->r2 << 7);
        goto L_8003EC90;
    // 0x8003EC7C: sll         $v0, $v0, 7
    ctx->r2 = S32(ctx->r2 << 7);
L_8003EC80:
    // 0x8003EC80: lw          $v1, 0x4($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X4);
    // 0x8003EC84: lbu         $v0, 0x18($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X18);
    // 0x8003EC88: addiu       $v1, $v1, -0x4C
    ctx->r3 = ADD32(ctx->r3, -0X4C);
    // 0x8003EC8C: sll         $v0, $v0, 8
    ctx->r2 = S32(ctx->r2 << 8);
L_8003EC90:
    // 0x8003EC90: subu        $a1, $v1, $v0
    ctx->r5 = SUB32(ctx->r3, ctx->r2);
    // 0x8003EC94: lbu         $v0, 0x0($a1)
    ctx->r2 = MEM_BU(ctx->r5, 0X0);
    // 0x8003EC98: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8003EC9C: sb          $v0, 0x0($a1)
    MEM_B(0X0, ctx->r5) = ctx->r2;
    // 0x8003ECA0: sll         $v0, $v0, 24
    ctx->r2 = S32(ctx->r2 << 24);
    // 0x8003ECA4: sra         $v0, $v0, 24
    ctx->r2 = S32(SIGNED(ctx->r2) >> 24);
    // 0x8003ECA8: lbu         $v1, 0x18($a0)
    ctx->r3 = MEM_BU(ctx->r4, 0X18);
    // 0x8003ECAC: addu        $v0, $a1, $v0
    ctx->r2 = ADD32(ctx->r5, ctx->r2);
    // 0x8003ECB0: sb          $v1, 0x1($v0)
    MEM_B(0X1, ctx->r2) = ctx->r3;
    // 0x8003ECB4: lw          $v0, 0x48($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X48);
    // 0x8003ECB8: bne         $v0, $zero, L_8003ECFC
    if (ctx->r2 != 0) {
        // 0x8003ECBC: nop
    
            goto L_8003ECFC;
    }
    // 0x8003ECBC: nop

    // 0x8003ECC0: lw          $v0, 0x44($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X44);
    // 0x8003ECC4: bne         $v0, $zero, L_8003ECF0
    if (ctx->r2 != 0) {
        // 0x8003ECC8: nop
    
            goto L_8003ECF0;
    }
    // 0x8003ECC8: nop

    // 0x8003ECCC: lb          $v0, 0x0($a1)
    ctx->r2 = MEM_B(ctx->r5, 0X0);
    // 0x8003ECD0: bne         $v0, $zero, L_8003ECF0
    if (ctx->r2 != 0) {
        // 0x8003ECD4: nop
    
            goto L_8003ECF0;
    }
    // 0x8003ECD4: nop

    // 0x8003ECD8: lw          $v0, 0x0($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X0);
    // 0x8003ECDC: beq         $v0, $zero, L_8003ECE8
    if (ctx->r2 == 0) {
        // 0x8003ECE0: sw          $v0, 0x48($a1)
        MEM_W(0X48, ctx->r5) = ctx->r2;
            goto L_8003ECE8;
    }
    // 0x8003ECE0: sw          $v0, 0x48($a1)
    MEM_W(0X48, ctx->r5) = ctx->r2;
    // 0x8003ECE4: sw          $a1, 0x44($v0)
    MEM_W(0X44, ctx->r2) = ctx->r5;
L_8003ECE8:
    // 0x8003ECE8: j           L_8003ED58
    // 0x8003ECEC: sw          $a1, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r5;
        goto L_8003ED58;
    // 0x8003ECEC: sw          $a1, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r5;
L_8003ECF0:
    // 0x8003ECF0: lw          $v0, 0x48($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X48);
    // 0x8003ECF4: beq         $v0, $zero, L_8003ED58
    if (ctx->r2 == 0) {
        // 0x8003ECF8: nop
    
            goto L_8003ED58;
    }
    // 0x8003ECF8: nop

L_8003ECFC:
    // 0x8003ECFC: lw          $a2, 0x48($a1)
    ctx->r6 = MEM_W(ctx->r5, 0X48);
    // 0x8003ED00: lb          $v1, 0x0($a1)
    ctx->r3 = MEM_B(ctx->r5, 0X0);
    // 0x8003ED04: lb          $v0, 0x0($a2)
    ctx->r2 = MEM_B(ctx->r6, 0X0);
    // 0x8003ED08: slt         $v0, $v0, $v1
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8003ED0C: beq         $v0, $zero, L_8003ED58
    if (ctx->r2 == 0) {
        // 0x8003ED10: nop
    
            goto L_8003ED58;
    }
    // 0x8003ED10: nop

    // 0x8003ED14: lw          $v0, 0x44($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X44);
    // 0x8003ED18: beql        $v0, $zero, L_8003ED24
    if (ctx->r2 == 0) {
        // 0x8003ED1C: sw          $a2, 0x0($a3)
        MEM_W(0X0, ctx->r7) = ctx->r6;
            goto L_8003ED24;
    }
    goto skip_0;
    // 0x8003ED1C: sw          $a2, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r6;
    skip_0:
    // 0x8003ED20: sw          $a2, 0x48($v0)
    MEM_W(0X48, ctx->r2) = ctx->r6;
L_8003ED24:
    // 0x8003ED24: lw          $v0, 0x48($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X48);
    // 0x8003ED28: lw          $v1, 0x44($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X44);
    // 0x8003ED2C: sw          $v1, 0x44($v0)
    MEM_W(0X44, ctx->r2) = ctx->r3;
    // 0x8003ED30: lw          $v0, 0x48($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X48);
    // 0x8003ED34: lw          $v0, 0x48($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X48);
    // 0x8003ED38: bnel        $v0, $zero, L_8003ED40
    if (ctx->r2 != 0) {
        // 0x8003ED3C: sw          $a1, 0x44($v0)
        MEM_W(0X44, ctx->r2) = ctx->r5;
            goto L_8003ED40;
    }
    goto skip_1;
    // 0x8003ED3C: sw          $a1, 0x44($v0)
    MEM_W(0X44, ctx->r2) = ctx->r5;
    skip_1:
L_8003ED40:
    // 0x8003ED40: lw          $v0, 0x48($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X48);
    // 0x8003ED44: sw          $v0, 0x44($a1)
    MEM_W(0X44, ctx->r5) = ctx->r2;
    // 0x8003ED48: lw          $v0, 0x48($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X48);
    // 0x8003ED4C: lw          $v1, 0x44($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X44);
    // 0x8003ED50: sw          $v0, 0x48($a1)
    MEM_W(0X48, ctx->r5) = ctx->r2;
    // 0x8003ED54: sw          $a1, 0x48($v1)
    MEM_W(0X48, ctx->r3) = ctx->r5;
L_8003ED58:
    // 0x8003ED58: lhu         $v0, 0x14($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X14);
    // 0x8003ED5C: sw          $zero, 0x4($a0)
    MEM_W(0X4, ctx->r4) = 0;
    // 0x8003ED60: andi        $v0, $v0, 0xFFFC
    ctx->r2 = ctx->r2 & 0XFFFC;
    // 0x8003ED64: sh          $v0, 0x14($a0)
    MEM_H(0X14, ctx->r4) = ctx->r2;
L_8003ED68:
    // 0x8003ED68: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x8003ED6C: jr          $ra
    // 0x8003ED70: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8003ED70: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_8003ED74(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003ED74: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8003ED78: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    // 0x8003ED7C: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x8003ED80: lui         $s1, 0x8013
    ctx->r17 = S32(0X8013 << 16);
    // 0x8003ED84: lw          $v0, 0xBB0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0XBB0);
    // 0x8003ED88: sll         $a0, $a0, 3
    ctx->r4 = S32(ctx->r4 << 3);
    // 0x8003ED8C: sw          $ra, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r31;
    // 0x8003ED90: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x8003ED94: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // 0x8003ED98: lw          $s0, 0x0($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X0);
    // 0x8003ED9C: beq         $s0, $zero, L_8003EEE0
    if (ctx->r16 == 0) {
        // 0x8003EDA0: nop
    
            goto L_8003EEE0;
    }
    // 0x8003EDA0: nop

    // 0x8003EDA4: lbu         $v0, 0x1A($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X1A);
    // 0x8003EDA8: beq         $v0, $zero, L_8003EDC0
    if (ctx->r2 == 0) {
        // 0x8003EDAC: nop
    
            goto L_8003EDC0;
    }
    // 0x8003EDAC: nop

    // 0x8003EDB0: lhu         $v0, 0x14($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X14);
    // 0x8003EDB4: ori         $v0, $v0, 0x8
    ctx->r2 = ctx->r2 | 0X8;
    // 0x8003EDB8: j           L_8003EEE0
    // 0x8003EDBC: sh          $v0, 0x14($s0)
    MEM_H(0X14, ctx->r16) = ctx->r2;
        goto L_8003EEE0;
    // 0x8003EDBC: sh          $v0, 0x14($s0)
    MEM_H(0X14, ctx->r16) = ctx->r2;
L_8003EDC0:
    // 0x8003EDC0: lbu         $v0, 0x1A($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X1A);
    // 0x8003EDC4: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x8003EDC8: sw          $zero, 0x8($s0)
    MEM_W(0X8, ctx->r16) = 0;
    // 0x8003EDCC: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8003EDD0: beq         $v1, $zero, L_8003EDE8
    if (ctx->r3 == 0) {
        // 0x8003EDD4: sb          $v0, 0x1A($s0)
        MEM_B(0X1A, ctx->r16) = ctx->r2;
            goto L_8003EDE8;
    }
    // 0x8003EDD4: sb          $v0, 0x1A($s0)
    MEM_B(0X1A, ctx->r16) = ctx->r2;
    // 0x8003EDD8: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x8003EDDC: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x8003EDE0: jalr        $v1
    // 0x8003EDE4: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    LOOKUP_FUNC(ctx->r3)(rdram, ctx);
        goto after_0;
    // 0x8003EDE4: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    after_0:
L_8003EDE8:
    // 0x8003EDE8: lbu         $v0, 0x1A($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X1A);
    // 0x8003EDEC: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x8003EDF0: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x8003EDF4: jal         0x8003EC10
    // 0x8003EDF8: sb          $v0, 0x1A($s0)
    MEM_B(0X1A, ctx->r16) = ctx->r2;
    func_8003EC10(rdram, ctx);
        goto after_1;
    // 0x8003EDF8: sb          $v0, 0x1A($s0)
    MEM_B(0X1A, ctx->r16) = ctx->r2;
    after_1:
    // 0x8003EDFC: lbu         $v0, 0x1B($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X1B);
    // 0x8003EE00: addiu       $a2, $v0, -0x1
    ctx->r6 = ADD32(ctx->r2, -0X1);
    // 0x8003EE04: bltz        $a2, L_8003EEBC
    if (SIGNED(ctx->r6) < 0) {
        // 0x8003EE08: sll         $v0, $a2, 1
        ctx->r2 = S32(ctx->r6 << 1);
            goto L_8003EEBC;
    }
    // 0x8003EE08: sll         $v0, $a2, 1
    ctx->r2 = S32(ctx->r6 << 1);
    // 0x8003EE0C: lw          $a1, 0xBB0($s1)
    ctx->r5 = MEM_W(ctx->r17, 0XBB0);
    // 0x8003EE10: ori         $a3, $zero, 0xFFFF
    ctx->r7 = 0 | 0XFFFF;
    // 0x8003EE14: lui         $t0, 0x8013
    ctx->r8 = S32(0X8013 << 16);
    // 0x8003EE18: addu        $a0, $v0, $s0
    ctx->r4 = ADD32(ctx->r2, ctx->r16);
L_8003EE1C:
    // 0x8003EE1C: lhu         $v0, 0x1C($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X1C);
    // 0x8003EE20: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x8003EE24: addu        $v1, $v0, $a1
    ctx->r3 = ADD32(ctx->r2, ctx->r5);
    // 0x8003EE28: lhu         $v0, 0x4($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X4);
    // 0x8003EE2C: beq         $v0, $a3, L_8003EE40
    if (ctx->r2 == ctx->r7) {
        // 0x8003EE30: sll         $v0, $v0, 3
        ctx->r2 = S32(ctx->r2 << 3);
            goto L_8003EE40;
    }
    // 0x8003EE30: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x8003EE34: lhu         $v1, 0x6($v1)
    ctx->r3 = MEM_HU(ctx->r3, 0X6);
    // 0x8003EE38: addu        $v0, $v0, $a1
    ctx->r2 = ADD32(ctx->r2, ctx->r5);
    // 0x8003EE3C: sh          $v1, 0x6($v0)
    MEM_H(0X6, ctx->r2) = ctx->r3;
L_8003EE40:
    // 0x8003EE40: lhu         $v0, 0x1C($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X1C);
    // 0x8003EE44: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x8003EE48: addu        $v1, $v0, $a1
    ctx->r3 = ADD32(ctx->r2, ctx->r5);
    // 0x8003EE4C: lhu         $v0, 0x6($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X6);
    // 0x8003EE50: beq         $v0, $a3, L_8003EE64
    if (ctx->r2 == ctx->r7) {
        // 0x8003EE54: sll         $v0, $v0, 3
        ctx->r2 = S32(ctx->r2 << 3);
            goto L_8003EE64;
    }
    // 0x8003EE54: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x8003EE58: lhu         $v1, 0x4($v1)
    ctx->r3 = MEM_HU(ctx->r3, 0X4);
    // 0x8003EE5C: addu        $v0, $v0, $a1
    ctx->r2 = ADD32(ctx->r2, ctx->r5);
    // 0x8003EE60: sh          $v1, 0x4($v0)
    MEM_H(0X4, ctx->r2) = ctx->r3;
L_8003EE64:
    // 0x8003EE64: lhu         $v0, 0x1C($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X1C);
    // 0x8003EE68: lhu         $v1, 0xBB4($t0)
    ctx->r3 = MEM_HU(ctx->r8, 0XBB4);
    // 0x8003EE6C: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x8003EE70: addu        $v0, $v0, $a1
    ctx->r2 = ADD32(ctx->r2, ctx->r5);
    // 0x8003EE74: sh          $v1, 0x4($v0)
    MEM_H(0X4, ctx->r2) = ctx->r3;
    // 0x8003EE78: andi        $v1, $v1, 0xFFFF
    ctx->r3 = ctx->r3 & 0XFFFF;
    // 0x8003EE7C: beq         $v1, $a3, L_8003EE98
    if (ctx->r3 == ctx->r7) {
        // 0x8003EE80: nop
    
            goto L_8003EE98;
    }
    // 0x8003EE80: nop

    // 0x8003EE84: lhu         $v0, 0xBB4($t0)
    ctx->r2 = MEM_HU(ctx->r8, 0XBB4);
    // 0x8003EE88: lhu         $v1, 0x1C($a0)
    ctx->r3 = MEM_HU(ctx->r4, 0X1C);
    // 0x8003EE8C: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x8003EE90: addu        $v0, $v0, $a1
    ctx->r2 = ADD32(ctx->r2, ctx->r5);
    // 0x8003EE94: sh          $v1, 0x6($v0)
    MEM_H(0X6, ctx->r2) = ctx->r3;
L_8003EE98:
    // 0x8003EE98: lhu         $v0, 0x1C($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X1C);
    // 0x8003EE9C: addiu       $a2, $a2, -0x1
    ctx->r6 = ADD32(ctx->r6, -0X1);
    // 0x8003EEA0: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x8003EEA4: addu        $v0, $v0, $a1
    ctx->r2 = ADD32(ctx->r2, ctx->r5);
    // 0x8003EEA8: sh          $a3, 0x6($v0)
    MEM_H(0X6, ctx->r2) = ctx->r7;
    // 0x8003EEAC: lhu         $v0, 0x1C($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X1C);
    // 0x8003EEB0: addiu       $a0, $a0, -0x2
    ctx->r4 = ADD32(ctx->r4, -0X2);
    // 0x8003EEB4: bgez        $a2, L_8003EE1C
    if (SIGNED(ctx->r6) >= 0) {
        // 0x8003EEB8: sh          $v0, 0xBB4($t0)
        MEM_H(0XBB4, ctx->r8) = ctx->r2;
            goto L_8003EE1C;
    }
    // 0x8003EEB8: sh          $v0, 0xBB4($t0)
    MEM_H(0XBB4, ctx->r8) = ctx->r2;
L_8003EEBC:
    // 0x8003EEBC: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x8003EEC0: lw          $v0, 0xBC8($v1)
    ctx->r2 = MEM_W(ctx->r3, 0XBC8);
    // 0x8003EEC4: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8003EEC8: sw          $v0, 0xBC8($v1)
    MEM_W(0XBC8, ctx->r3) = ctx->r2;
    // 0x8003EECC: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x8003EED0: lw          $v1, 0xBBC($v1)
    ctx->r3 = MEM_W(ctx->r3, 0XBBC);
    // 0x8003EED4: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8003EED8: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8003EEDC: sw          $s0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r16;
L_8003EEE0:
    // 0x8003EEE0: lw          $ra, 0x18($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X18);
    // 0x8003EEE4: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x8003EEE8: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x8003EEEC: jr          $ra
    // 0x8003EEF0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x8003EEF0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_8003EEF4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003EEF4: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8003EEF8: lhu         $a1, 0x2($a0)
    ctx->r5 = MEM_HU(ctx->r4, 0X2);
    // 0x8003EEFC: lhu         $v1, 0x0($a0)
    ctx->r3 = MEM_HU(ctx->r4, 0X0);
    // 0x8003EF00: lw          $a3, 0xBB0($v0)
    ctx->r7 = MEM_W(ctx->r2, 0XBB0);
    // 0x8003EF04: sll         $v1, $v1, 3
    ctx->r3 = S32(ctx->r3 << 3);
    // 0x8003EF08: addu        $v1, $v1, $a3
    ctx->r3 = ADD32(ctx->r3, ctx->r7);
    // 0x8003EF0C: lhu         $v0, 0x4($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X4);
    // 0x8003EF10: andi        $a2, $a1, 0xFFFF
    ctx->r6 = ctx->r5 & 0XFFFF;
    // 0x8003EF14: beq         $a2, $v0, L_8003EF5C
    if (ctx->r6 == ctx->r2) {
        // 0x8003EF18: ori         $t0, $zero, 0xFFFF
        ctx->r8 = 0 | 0XFFFF;
            goto L_8003EF5C;
    }
    // 0x8003EF18: ori         $t0, $zero, 0xFFFF
    ctx->r8 = 0 | 0XFFFF;
    // 0x8003EF1C: beq         $a2, $t0, L_8003EF54
    if (ctx->r6 == ctx->r8) {
        // 0x8003EF20: sll         $v0, $a2, 3
        ctx->r2 = S32(ctx->r6 << 3);
            goto L_8003EF54;
    }
    // 0x8003EF20: sll         $v0, $a2, 3
    ctx->r2 = S32(ctx->r6 << 3);
    // 0x8003EF24: addu        $v0, $v0, $a3
    ctx->r2 = ADD32(ctx->r2, ctx->r7);
    // 0x8003EF28: lhu         $v1, 0x4($a0)
    ctx->r3 = MEM_HU(ctx->r4, 0X4);
    // 0x8003EF2C: lhu         $v0, 0x4($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X4);
    // 0x8003EF30: bne         $v1, $v0, L_8003EF54
    if (ctx->r3 != ctx->r2) {
        // 0x8003EF34: nop
    
            goto L_8003EF54;
    }
    // 0x8003EF34: nop

    // 0x8003EF38: beq         $v1, $t0, L_8003EF5C
    if (ctx->r3 == ctx->r8) {
        // 0x8003EF3C: addu        $v0, $v1, $zero
        ctx->r2 = ADD32(ctx->r3, 0);
            goto L_8003EF5C;
    }
    // 0x8003EF3C: addu        $v0, $v1, $zero
    ctx->r2 = ADD32(ctx->r3, 0);
    // 0x8003EF40: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x8003EF44: addu        $v0, $v0, $a3
    ctx->r2 = ADD32(ctx->r2, ctx->r7);
    // 0x8003EF48: lhu         $v0, 0x6($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X6);
    // 0x8003EF4C: beq         $a2, $v0, L_8003EF60
    if (ctx->r6 == ctx->r2) {
        // 0x8003EF50: ori         $v0, $zero, 0xFFFF
        ctx->r2 = 0 | 0XFFFF;
            goto L_8003EF60;
    }
    // 0x8003EF50: ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
L_8003EF54:
    // 0x8003EF54: jr          $ra
    // 0x8003EF58: ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
    return;
    // 0x8003EF58: ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
L_8003EF5C:
    // 0x8003EF5C: ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
L_8003EF60:
    // 0x8003EF60: beq         $a1, $v0, L_8003EFD4
    if (ctx->r5 == ctx->r2) {
        // 0x8003EF64: lui         $v0, 0x8013
        ctx->r2 = S32(0X8013 << 16);
            goto L_8003EFD4;
    }
    // 0x8003EF64: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8003EF68: lw          $a2, 0xBB0($v0)
    ctx->r6 = MEM_W(ctx->r2, 0XBB0);
    // 0x8003EF6C: ori         $a3, $zero, 0xFFFF
    ctx->r7 = 0 | 0XFFFF;
    // 0x8003EF70: sll         $v0, $a1, 3
    ctx->r2 = S32(ctx->r5 << 3);
L_8003EF74:
    // 0x8003EF74: addu        $v1, $v0, $a2
    ctx->r3 = ADD32(ctx->r2, ctx->r6);
    // 0x8003EF78: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8003EF7C: beq         $v0, $zero, L_8003EFC8
    if (ctx->r2 == 0) {
        // 0x8003EF80: nop
    
            goto L_8003EFC8;
    }
    // 0x8003EF80: nop

    // 0x8003EF84: sh          $a1, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r5;
    // 0x8003EF88: lhu         $v0, 0x4($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X4);
    // 0x8003EF8C: sh          $v0, 0x2($a0)
    MEM_H(0X2, ctx->r4) = ctx->r2;
    // 0x8003EF90: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x8003EF94: beql        $v0, $a3, L_8003EFB0
    if (ctx->r2 == ctx->r7) {
        // 0x8003EF98: sh          $a3, 0x4($a0)
        MEM_H(0X4, ctx->r4) = ctx->r7;
            goto L_8003EFB0;
    }
    goto skip_0;
    // 0x8003EF98: sh          $a3, 0x4($a0)
    MEM_H(0X4, ctx->r4) = ctx->r7;
    skip_0:
    // 0x8003EF9C: lhu         $v0, 0x2($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X2);
    // 0x8003EFA0: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x8003EFA4: addu        $v0, $v0, $a2
    ctx->r2 = ADD32(ctx->r2, ctx->r6);
    // 0x8003EFA8: lhu         $v0, 0x4($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X4);
    // 0x8003EFAC: sh          $v0, 0x4($a0)
    MEM_H(0X4, ctx->r4) = ctx->r2;
L_8003EFB0:
    // 0x8003EFB0: sll         $v0, $a1, 3
    ctx->r2 = S32(ctx->r5 << 3);
    // 0x8003EFB4: addu        $v0, $v0, $a2
    ctx->r2 = ADD32(ctx->r2, ctx->r6);
    // 0x8003EFB8: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x8003EFBC: lhu         $v0, 0x16($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X16);
    // 0x8003EFC0: jr          $ra
    // 0x8003EFC4: nop

    return;
    // 0x8003EFC4: nop

L_8003EFC8:
    // 0x8003EFC8: lhu         $a1, 0x4($v1)
    ctx->r5 = MEM_HU(ctx->r3, 0X4);
    // 0x8003EFCC: bne         $a1, $a3, L_8003EF74
    if (ctx->r5 != ctx->r7) {
        // 0x8003EFD0: sll         $v0, $a1, 3
        ctx->r2 = S32(ctx->r5 << 3);
            goto L_8003EF74;
    }
    // 0x8003EFD0: sll         $v0, $a1, 3
    ctx->r2 = S32(ctx->r5 << 3);
L_8003EFD4:
    // 0x8003EFD4: jr          $ra
    // 0x8003EFD8: ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
    return;
    // 0x8003EFD8: ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
;}
RECOMP_FUNC void func_8003EFDC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003EFDC: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8003EFE0: lhu         $a2, 0x2($a0)
    ctx->r6 = MEM_HU(ctx->r4, 0X2);
    // 0x8003EFE4: lhu         $v1, 0x0($a0)
    ctx->r3 = MEM_HU(ctx->r4, 0X0);
    // 0x8003EFE8: lw          $a3, 0xBB0($v0)
    ctx->r7 = MEM_W(ctx->r2, 0XBB0);
    // 0x8003EFEC: sll         $v1, $v1, 3
    ctx->r3 = S32(ctx->r3 << 3);
    // 0x8003EFF0: addu        $v1, $v1, $a3
    ctx->r3 = ADD32(ctx->r3, ctx->r7);
    // 0x8003EFF4: lhu         $v0, 0x4($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X4);
    // 0x8003EFF8: andi        $a1, $a2, 0xFFFF
    ctx->r5 = ctx->r6 & 0XFFFF;
    // 0x8003EFFC: beq         $a1, $v0, L_8003F044
    if (ctx->r5 == ctx->r2) {
        // 0x8003F000: ori         $t0, $zero, 0xFFFF
        ctx->r8 = 0 | 0XFFFF;
            goto L_8003F044;
    }
    // 0x8003F000: ori         $t0, $zero, 0xFFFF
    ctx->r8 = 0 | 0XFFFF;
    // 0x8003F004: beq         $a1, $t0, L_8003F03C
    if (ctx->r5 == ctx->r8) {
        // 0x8003F008: sll         $v0, $a1, 3
        ctx->r2 = S32(ctx->r5 << 3);
            goto L_8003F03C;
    }
    // 0x8003F008: sll         $v0, $a1, 3
    ctx->r2 = S32(ctx->r5 << 3);
    // 0x8003F00C: addu        $v0, $v0, $a3
    ctx->r2 = ADD32(ctx->r2, ctx->r7);
    // 0x8003F010: lhu         $v1, 0x4($a0)
    ctx->r3 = MEM_HU(ctx->r4, 0X4);
    // 0x8003F014: lhu         $v0, 0x4($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X4);
    // 0x8003F018: bne         $v1, $v0, L_8003F03C
    if (ctx->r3 != ctx->r2) {
        // 0x8003F01C: nop
    
            goto L_8003F03C;
    }
    // 0x8003F01C: nop

    // 0x8003F020: beq         $v1, $t0, L_8003F044
    if (ctx->r3 == ctx->r8) {
        // 0x8003F024: addu        $v0, $v1, $zero
        ctx->r2 = ADD32(ctx->r3, 0);
            goto L_8003F044;
    }
    // 0x8003F024: addu        $v0, $v1, $zero
    ctx->r2 = ADD32(ctx->r3, 0);
    // 0x8003F028: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x8003F02C: addu        $v0, $v0, $a3
    ctx->r2 = ADD32(ctx->r2, ctx->r7);
    // 0x8003F030: lhu         $v0, 0x6($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X6);
    // 0x8003F034: beq         $a1, $v0, L_8003F048
    if (ctx->r5 == ctx->r2) {
        // 0x8003F038: ori         $v0, $zero, 0xFFFF
        ctx->r2 = 0 | 0XFFFF;
            goto L_8003F048;
    }
    // 0x8003F038: ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
L_8003F03C:
    // 0x8003F03C: jr          $ra
    // 0x8003F040: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    return;
    // 0x8003F040: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_8003F044:
    // 0x8003F044: ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
L_8003F048:
    // 0x8003F048: beq         $a2, $v0, L_8003F0C0
    if (ctx->r6 == ctx->r2) {
        // 0x8003F04C: lui         $v0, 0x8013
        ctx->r2 = S32(0X8013 << 16);
            goto L_8003F0C0;
    }
    // 0x8003F04C: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8003F050: lw          $a3, 0xBB0($v0)
    ctx->r7 = MEM_W(ctx->r2, 0XBB0);
    // 0x8003F054: ori         $t0, $zero, 0xFFFF
    ctx->r8 = 0 | 0XFFFF;
    // 0x8003F058: sll         $v0, $a2, 3
    ctx->r2 = S32(ctx->r6 << 3);
L_8003F05C:
    // 0x8003F05C: addu        $v1, $v0, $a3
    ctx->r3 = ADD32(ctx->r2, ctx->r7);
    // 0x8003F060: lw          $a1, 0x0($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X0);
    // 0x8003F064: beq         $a1, $zero, L_8003F0B4
    if (ctx->r5 == 0) {
        // 0x8003F068: addu        $v0, $v0, $a3
        ctx->r2 = ADD32(ctx->r2, ctx->r7);
            goto L_8003F0B4;
    }
    // 0x8003F068: addu        $v0, $v0, $a3
    ctx->r2 = ADD32(ctx->r2, ctx->r7);
    // 0x8003F06C: lw          $v0, 0x8($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X8);
    // 0x8003F070: beq         $v0, $zero, L_8003F0B0
    if (ctx->r2 == 0) {
        // 0x8003F074: sll         $v0, $a2, 3
        ctx->r2 = S32(ctx->r6 << 3);
            goto L_8003F0B0;
    }
    // 0x8003F074: sll         $v0, $a2, 3
    ctx->r2 = S32(ctx->r6 << 3);
    // 0x8003F078: sh          $a2, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r6;
    // 0x8003F07C: lhu         $v0, 0x4($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X4);
    // 0x8003F080: sh          $v0, 0x2($a0)
    MEM_H(0X2, ctx->r4) = ctx->r2;
    // 0x8003F084: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x8003F088: beql        $v0, $t0, L_8003F0A4
    if (ctx->r2 == ctx->r8) {
        // 0x8003F08C: sh          $t0, 0x4($a0)
        MEM_H(0X4, ctx->r4) = ctx->r8;
            goto L_8003F0A4;
    }
    goto skip_0;
    // 0x8003F08C: sh          $t0, 0x4($a0)
    MEM_H(0X4, ctx->r4) = ctx->r8;
    skip_0:
    // 0x8003F090: lhu         $v0, 0x2($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X2);
    // 0x8003F094: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x8003F098: addu        $v0, $v0, $a3
    ctx->r2 = ADD32(ctx->r2, ctx->r7);
    // 0x8003F09C: lhu         $v0, 0x4($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X4);
    // 0x8003F0A0: sh          $v0, 0x4($a0)
    MEM_H(0X4, ctx->r4) = ctx->r2;
L_8003F0A4:
    // 0x8003F0A4: lw          $v0, 0x8($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X8);
    // 0x8003F0A8: jr          $ra
    // 0x8003F0AC: nop

    return;
    // 0x8003F0AC: nop

L_8003F0B0:
    // 0x8003F0B0: addu        $v0, $v0, $a3
    ctx->r2 = ADD32(ctx->r2, ctx->r7);
L_8003F0B4:
    // 0x8003F0B4: lhu         $a2, 0x4($v0)
    ctx->r6 = MEM_HU(ctx->r2, 0X4);
    // 0x8003F0B8: bne         $a2, $t0, L_8003F05C
    if (ctx->r6 != ctx->r8) {
        // 0x8003F0BC: sll         $v0, $a2, 3
        ctx->r2 = S32(ctx->r6 << 3);
            goto L_8003F05C;
    }
    // 0x8003F0BC: sll         $v0, $a2, 3
    ctx->r2 = S32(ctx->r6 << 3);
L_8003F0C0:
    // 0x8003F0C0: jr          $ra
    // 0x8003F0C4: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    return;
    // 0x8003F0C4: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
;}
RECOMP_FUNC void func_8003F0C8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003F0C8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8003F0CC: addu        $t0, $a0, $zero
    ctx->r8 = ADD32(ctx->r4, 0);
    // 0x8003F0D0: andi        $v1, $t0, 0xFFFF
    ctx->r3 = ctx->r8 & 0XFFFF;
    // 0x8003F0D4: ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
    // 0x8003F0D8: sw          $ra, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r31;
    // 0x8003F0DC: sw          $s3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r19;
    // 0x8003F0E0: sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // 0x8003F0E4: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x8003F0E8: beq         $v1, $v0, L_8003F1B4
    if (ctx->r3 == ctx->r2) {
        // 0x8003F0EC: sw          $s0, 0x10($sp)
        MEM_W(0X10, ctx->r29) = ctx->r16;
            goto L_8003F1B4;
    }
    // 0x8003F0EC: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x8003F0F0: lui         $s2, 0x8013
    ctx->r18 = S32(0X8013 << 16);
    // 0x8003F0F4: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    // 0x8003F0F8: lui         $s3, 0x8013
    ctx->r19 = S32(0X8013 << 16);
    // 0x8003F0FC: andi        $a0, $t0, 0xFFFF
    ctx->r4 = ctx->r8 & 0XFFFF;
L_8003F100:
    // 0x8003F100: lw          $a2, 0xBB0($s2)
    ctx->r6 = MEM_W(ctx->r18, 0XBB0);
    // 0x8003F104: sll         $a3, $a0, 3
    ctx->r7 = S32(ctx->r4 << 3);
    // 0x8003F108: addu        $v1, $a3, $a2
    ctx->r3 = ADD32(ctx->r7, ctx->r6);
    // 0x8003F10C: lw          $a1, 0x0($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X0);
    // 0x8003F110: lhu         $s1, 0x4($v1)
    ctx->r17 = MEM_HU(ctx->r3, 0X4);
    // 0x8003F114: beq         $a1, $zero, L_8003F12C
    if (ctx->r5 == 0) {
        // 0x8003F118: andi        $v0, $s1, 0xFFFF
        ctx->r2 = ctx->r17 & 0XFFFF;
            goto L_8003F12C;
    }
    // 0x8003F118: andi        $v0, $s1, 0xFFFF
    ctx->r2 = ctx->r17 & 0XFFFF;
    // 0x8003F11C: jal         0x8003E7D0
    // 0x8003F120: nop

    func_8003E7D0(rdram, ctx);
        goto after_0;
    // 0x8003F120: nop

    after_0:
    // 0x8003F124: j           L_8003F1A8
    // 0x8003F128: addu        $t0, $s1, $zero
    ctx->r8 = ADD32(ctx->r17, 0);
        goto L_8003F1A8;
    // 0x8003F128: addu        $t0, $s1, $zero
    ctx->r8 = ADD32(ctx->r17, 0);
L_8003F12C:
    // 0x8003F12C: beq         $v0, $s0, L_8003F148
    if (ctx->r2 == ctx->r16) {
        // 0x8003F130: nop
    
            goto L_8003F148;
    }
    // 0x8003F130: nop

    // 0x8003F134: lhu         $v0, 0x4($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X4);
    // 0x8003F138: lhu         $v1, 0x6($v1)
    ctx->r3 = MEM_HU(ctx->r3, 0X6);
    // 0x8003F13C: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x8003F140: addu        $v0, $v0, $a2
    ctx->r2 = ADD32(ctx->r2, ctx->r6);
    // 0x8003F144: sh          $v1, 0x6($v0)
    MEM_H(0X6, ctx->r2) = ctx->r3;
L_8003F148:
    // 0x8003F148: lw          $a1, 0xBB0($s2)
    ctx->r5 = MEM_W(ctx->r18, 0XBB0);
    // 0x8003F14C: addu        $v1, $a3, $a1
    ctx->r3 = ADD32(ctx->r7, ctx->r5);
    // 0x8003F150: lhu         $v0, 0x6($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X6);
    // 0x8003F154: beq         $v0, $s0, L_8003F16C
    if (ctx->r2 == ctx->r16) {
        // 0x8003F158: sll         $v0, $v0, 3
        ctx->r2 = S32(ctx->r2 << 3);
            goto L_8003F16C;
    }
    // 0x8003F158: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x8003F15C: lhu         $v1, 0x4($v1)
    ctx->r3 = MEM_HU(ctx->r3, 0X4);
    // 0x8003F160: addu        $v0, $v0, $a1
    ctx->r2 = ADD32(ctx->r2, ctx->r5);
    // 0x8003F164: sh          $v1, 0x4($v0)
    MEM_H(0X4, ctx->r2) = ctx->r3;
    // 0x8003F168: lw          $a1, 0xBB0($s2)
    ctx->r5 = MEM_W(ctx->r18, 0XBB0);
L_8003F16C:
    // 0x8003F16C: lhu         $v1, 0xBB4($s3)
    ctx->r3 = MEM_HU(ctx->r19, 0XBB4);
    // 0x8003F170: addu        $v0, $a3, $a1
    ctx->r2 = ADD32(ctx->r7, ctx->r5);
    // 0x8003F174: sh          $v1, 0x4($v0)
    MEM_H(0X4, ctx->r2) = ctx->r3;
    // 0x8003F178: andi        $v1, $v1, 0xFFFF
    ctx->r3 = ctx->r3 & 0XFFFF;
    // 0x8003F17C: beq         $v1, $s0, L_8003F194
    if (ctx->r3 == ctx->r16) {
        // 0x8003F180: nop
    
            goto L_8003F194;
    }
    // 0x8003F180: nop

    // 0x8003F184: lhu         $v0, 0xBB4($s3)
    ctx->r2 = MEM_HU(ctx->r19, 0XBB4);
    // 0x8003F188: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x8003F18C: addu        $v0, $v0, $a1
    ctx->r2 = ADD32(ctx->r2, ctx->r5);
    // 0x8003F190: sh          $t0, 0x6($v0)
    MEM_H(0X6, ctx->r2) = ctx->r8;
L_8003F194:
    // 0x8003F194: lw          $v0, 0xBB0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0XBB0);
    // 0x8003F198: sh          $t0, 0xBB4($s3)
    MEM_H(0XBB4, ctx->r19) = ctx->r8;
    // 0x8003F19C: addu        $v0, $a3, $v0
    ctx->r2 = ADD32(ctx->r7, ctx->r2);
    // 0x8003F1A0: sh          $s0, 0x6($v0)
    MEM_H(0X6, ctx->r2) = ctx->r16;
    // 0x8003F1A4: addu        $t0, $s1, $zero
    ctx->r8 = ADD32(ctx->r17, 0);
L_8003F1A8:
    // 0x8003F1A8: andi        $v0, $t0, 0xFFFF
    ctx->r2 = ctx->r8 & 0XFFFF;
    // 0x8003F1AC: bne         $v0, $s0, L_8003F100
    if (ctx->r2 != ctx->r16) {
        // 0x8003F1B0: andi        $a0, $t0, 0xFFFF
        ctx->r4 = ctx->r8 & 0XFFFF;
            goto L_8003F100;
    }
    // 0x8003F1B0: andi        $a0, $t0, 0xFFFF
    ctx->r4 = ctx->r8 & 0XFFFF;
L_8003F1B4:
    // 0x8003F1B4: lw          $ra, 0x20($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X20);
    // 0x8003F1B8: lw          $s3, 0x1C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X1C);
    // 0x8003F1BC: lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X18);
    // 0x8003F1C0: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x8003F1C4: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x8003F1C8: jr          $ra
    // 0x8003F1CC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x8003F1CC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_8003F1D0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003F1D0: addiu       $sp, $sp, -0x158
    ctx->r29 = ADD32(ctx->r29, -0X158);
    // 0x8003F1D4: sw          $s3, 0x134($sp)
    MEM_W(0X134, ctx->r29) = ctx->r19;
    // 0x8003F1D8: addu        $s3, $a0, $zero
    ctx->r19 = ADD32(ctx->r4, 0);
    // 0x8003F1DC: sw          $s5, 0x13C($sp)
    MEM_W(0X13C, ctx->r29) = ctx->r21;
    // 0x8003F1E0: sw          $s1, 0x12C($sp)
    MEM_W(0X12C, ctx->r29) = ctx->r17;
    // 0x8003F1E4: andi        $s1, $a1, 0xFFFF
    ctx->r17 = ctx->r5 & 0XFFFF;
    // 0x8003F1E8: sw          $s4, 0x138($sp)
    MEM_W(0X138, ctx->r29) = ctx->r20;
    // 0x8003F1EC: addiu       $s4, $zero, 0x2
    ctx->r20 = ADD32(0, 0X2);
    // 0x8003F1F0: sw          $ra, 0x140($sp)
    MEM_W(0X140, ctx->r29) = ctx->r31;
    // 0x8003F1F4: sw          $s2, 0x130($sp)
    MEM_W(0X130, ctx->r29) = ctx->r18;
    // 0x8003F1F8: sw          $s0, 0x128($sp)
    MEM_W(0X128, ctx->r29) = ctx->r16;
    // 0x8003F1FC: sdc1        $f22, 0x150($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X150, ctx->r29);
    // 0x8003F200: sdc1        $f20, 0x148($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X148, ctx->r29);
    // 0x8003F204: lw          $s2, 0x4($s3)
    ctx->r18 = MEM_W(ctx->r19, 0X4);
    // 0x8003F208: beq         $s1, $s4, L_8003F470
    if (ctx->r17 == ctx->r20) {
        // 0x8003F20C: addu        $s5, $a2, $zero
        ctx->r21 = ADD32(ctx->r6, 0);
            goto L_8003F470;
    }
    // 0x8003F20C: addu        $s5, $a2, $zero
    ctx->r21 = ADD32(ctx->r6, 0);
    // 0x8003F210: slti        $v0, $s1, 0x3
    ctx->r2 = SIGNED(ctx->r17) < 0X3 ? 1 : 0;
    // 0x8003F214: beq         $v0, $zero, L_8003F22C
    if (ctx->r2 == 0) {
        // 0x8003F218: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_8003F22C;
    }
    // 0x8003F218: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8003F21C: beq         $s1, $v0, L_8003F240
    if (ctx->r17 == ctx->r2) {
        // 0x8003F220: addu        $s0, $s5, $zero
        ctx->r16 = ADD32(ctx->r21, 0);
            goto L_8003F240;
    }
    // 0x8003F220: addu        $s0, $s5, $zero
    ctx->r16 = ADD32(ctx->r21, 0);
    // 0x8003F224: j           L_8003F6B4
    // 0x8003F228: nop

        goto L_8003F6B4;
    // 0x8003F228: nop

L_8003F22C:
    // 0x8003F22C: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x8003F230: beq         $s1, $v0, L_8003F490
    if (ctx->r17 == ctx->r2) {
        // 0x8003F234: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_8003F490;
    }
    // 0x8003F234: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8003F238: j           L_8003F6B8
    // 0x8003F23C: nop

        goto L_8003F6B8;
    // 0x8003F23C: nop

L_8003F240:
    // 0x8003F240: lw          $a1, 0x4($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X4);
    // 0x8003F244: beq         $a1, $zero, L_8003F254
    if (ctx->r5 == 0) {
        // 0x8003F248: addu        $a0, $s2, $zero
        ctx->r4 = ADD32(ctx->r18, 0);
            goto L_8003F254;
    }
    // 0x8003F248: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // 0x8003F24C: jal         0x80018EF4
    // 0x8003F250: addiu       $a2, $zero, 0x30
    ctx->r6 = ADD32(0, 0X30);
    zmemcpy(rdram, ctx);
        goto after_0;
    // 0x8003F250: addiu       $a2, $zero, 0x30
    ctx->r6 = ADD32(0, 0X30);
    after_0:
L_8003F254:
    // 0x8003F254: mtc1        $zero, $f22
    ctx->f22.u32l = 0;
    // 0x8003F258: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x8003F25C: swc1        $f22, 0x2C($s2)
    MEM_W(0X2C, ctx->r18) = ctx->f22.u32l;
    // 0x8003F260: swc1        $f22, 0x28($s2)
    MEM_W(0X28, ctx->r18) = ctx->f22.u32l;
    // 0x8003F264: swc1        $f22, 0x24($s2)
    MEM_W(0X24, ctx->r18) = ctx->f22.u32l;
    // 0x8003F268: sw          $s2, 0x8($s3)
    MEM_W(0X8, ctx->r19) = ctx->r18;
    // 0x8003F26C: sw          $zero, 0xC($s3)
    MEM_W(0XC, ctx->r19) = 0;
    // 0x8003F270: lhu         $a0, -0x6A62($v0)
    ctx->r4 = MEM_HU(ctx->r2, -0X6A62);
    // 0x8003F274: jal         0x8003E684
    // 0x8003F278: addu        $a1, $s3, $zero
    ctx->r5 = ADD32(ctx->r19, 0);
    func_8003E684(rdram, ctx);
        goto after_1;
    // 0x8003F278: addu        $a1, $s3, $zero
    ctx->r5 = ADD32(ctx->r19, 0);
    after_1:
    // 0x8003F27C: lhu         $v0, 0x14($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X14);
    // 0x8003F280: sh          $v0, 0x78($s2)
    MEM_H(0X78, ctx->r18) = ctx->r2;
    // 0x8003F284: lhu         $v0, 0x0($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X0);
    // 0x8003F288: sh          $v0, 0x76($s2)
    MEM_H(0X76, ctx->r18) = ctx->r2;
    // 0x8003F28C: lw          $v0, 0xC($s0)
    ctx->r2 = MEM_W(ctx->r16, 0XC);
    // 0x8003F290: lh          $v1, 0x76($s2)
    ctx->r3 = MEM_H(ctx->r18, 0X76);
    // 0x8003F294: sw          $v0, 0x70($s2)
    MEM_W(0X70, ctx->r18) = ctx->r2;
    // 0x8003F298: lhu         $v0, 0x12($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X12);
    // 0x8003F29C: sh          $v0, 0x74($s2)
    MEM_H(0X74, ctx->r18) = ctx->r2;
    // 0x8003F2A0: lhu         $v0, 0x2($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X2);
    // 0x8003F2A4: beq         $v1, $s1, L_8003F3A8
    if (ctx->r3 == ctx->r17) {
        // 0x8003F2A8: sh          $v0, 0x6C($s2)
        MEM_H(0X6C, ctx->r18) = ctx->r2;
            goto L_8003F3A8;
    }
    // 0x8003F2A8: sh          $v0, 0x6C($s2)
    MEM_H(0X6C, ctx->r18) = ctx->r2;
    // 0x8003F2AC: slti        $v0, $v1, 0x2
    ctx->r2 = SIGNED(ctx->r3) < 0X2 ? 1 : 0;
    // 0x8003F2B0: beq         $v0, $zero, L_8003F2C8
    if (ctx->r2 == 0) {
        // 0x8003F2B4: nop
    
            goto L_8003F2C8;
    }
    // 0x8003F2B4: nop

    // 0x8003F2B8: beq         $v1, $zero, L_8003F2D8
    if (ctx->r3 == 0) {
        // 0x8003F2BC: lui         $v0, 0x8013
        ctx->r2 = S32(0X8013 << 16);
            goto L_8003F2D8;
    }
    // 0x8003F2BC: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8003F2C0: j           L_8003F414
    // 0x8003F2C4: ori         $s0, $zero, 0xFFFF
    ctx->r16 = 0 | 0XFFFF;
        goto L_8003F414;
    // 0x8003F2C4: ori         $s0, $zero, 0xFFFF
    ctx->r16 = 0 | 0XFFFF;
L_8003F2C8:
    // 0x8003F2C8: beq         $v1, $s4, L_8003F3C4
    if (ctx->r3 == ctx->r20) {
        // 0x8003F2CC: lui         $v0, 0x8013
        ctx->r2 = S32(0X8013 << 16);
            goto L_8003F3C4;
    }
    // 0x8003F2CC: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8003F2D0: j           L_8003F414
    // 0x8003F2D4: ori         $s0, $zero, 0xFFFF
    ctx->r16 = 0 | 0XFFFF;
        goto L_8003F414;
    // 0x8003F2D4: ori         $s0, $zero, 0xFFFF
    ctx->r16 = 0 | 0XFFFF;
L_8003F2D8:
    // 0x8003F2D8: lhu         $v1, 0x2($s0)
    ctx->r3 = MEM_HU(ctx->r16, 0X2);
    // 0x8003F2DC: lw          $v0, 0xBB0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0XBB0);
    // 0x8003F2E0: sll         $v1, $v1, 3
    ctx->r3 = S32(ctx->r3 << 3);
    // 0x8003F2E4: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x8003F2E8: lw          $v1, 0x0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X0);
    // 0x8003F2EC: beq         $v1, $zero, L_8003F2F8
    if (ctx->r3 == 0) {
        // 0x8003F2F0: addu        $s1, $zero, $zero
        ctx->r17 = ADD32(0, 0);
            goto L_8003F2F8;
    }
    // 0x8003F2F0: addu        $s1, $zero, $zero
    ctx->r17 = ADD32(0, 0);
    // 0x8003F2F4: lw          $s1, 0x8($v1)
    ctx->r17 = MEM_W(ctx->r3, 0X8);
L_8003F2F8:
    // 0x8003F2F8: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8003F2FC: lwc1        $f20, -0x5C00($at)
    ctx->f20.u32l = MEM_W(ctx->r1, -0X5C00);
    // 0x8003F300: addiu       $a0, $sp, 0x20
    ctx->r4 = ADD32(ctx->r29, 0X20);
    // 0x8003F304: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x8003F308: jal         0x80059B50
    // 0x8003F30C: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    func_80059B50(rdram, ctx);
        goto after_2;
    // 0x8003F30C: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    after_2:
    // 0x8003F310: addiu       $s0, $sp, 0x50
    ctx->r16 = ADD32(ctx->r29, 0X50);
    // 0x8003F314: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x8003F318: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    // 0x8003F31C: swc1        $f22, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f22.u32l;
    // 0x8003F320: swc1        $f22, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f22.u32l;
    // 0x8003F324: jal         0x8001C774
    // 0x8003F328: swc1        $f22, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f22.u32l;
    func_8001C774(rdram, ctx);
        goto after_3;
    // 0x8003F328: swc1        $f22, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f22.u32l;
    after_3:
    // 0x8003F32C: lwc1        $f0, 0x0($s2)
    ctx->f0.u32l = MEM_W(ctx->r18, 0X0);
    // 0x8003F330: lwc1        $f2, 0x0($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0X0);
    // 0x8003F334: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x8003F338: swc1        $f0, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->f0.u32l;
    // 0x8003F33C: lwc1        $f0, 0x4($s2)
    ctx->f0.u32l = MEM_W(ctx->r18, 0X4);
    // 0x8003F340: lwc1        $f2, 0x4($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0X4);
    // 0x8003F344: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x8003F348: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x8003F34C: swc1        $f0, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->f0.u32l;
    // 0x8003F350: lwc1        $f0, 0x8($s2)
    ctx->f0.u32l = MEM_W(ctx->r18, 0X8);
    // 0x8003F354: lwc1        $f2, 0x8($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0X8);
    // 0x8003F358: addiu       $a1, $sp, 0x80
    ctx->r5 = ADD32(ctx->r29, 0X80);
    // 0x8003F35C: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x8003F360: addiu       $s1, $sp, 0x90
    ctx->r17 = ADD32(ctx->r29, 0X90);
    // 0x8003F364: addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    // 0x8003F368: jal         0x800193E8
    // 0x8003F36C: swc1        $f0, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->f0.u32l;
    func_800193E8(rdram, ctx);
        goto after_4;
    // 0x8003F36C: swc1        $f0, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->f0.u32l;
    after_4:
    // 0x8003F370: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x8003F374: addiu       $a1, $s2, 0xC
    ctx->r5 = ADD32(ctx->r18, 0XC);
    // 0x8003F378: jal         0x800193E8
    // 0x8003F37C: addiu       $a2, $sp, 0x9C
    ctx->r6 = ADD32(ctx->r29, 0X9C);
    func_800193E8(rdram, ctx);
        goto after_5;
    // 0x8003F37C: addiu       $a2, $sp, 0x9C
    ctx->r6 = ADD32(ctx->r29, 0X9C);
    after_5:
    // 0x8003F380: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x8003F384: addiu       $a1, $s2, 0x18
    ctx->r5 = ADD32(ctx->r18, 0X18);
    // 0x8003F388: jal         0x800193E8
    // 0x8003F38C: addiu       $a2, $sp, 0xA8
    ctx->r6 = ADD32(ctx->r29, 0XA8);
    func_800193E8(rdram, ctx);
        goto after_6;
    // 0x8003F38C: addiu       $a2, $sp, 0xA8
    ctx->r6 = ADD32(ctx->r29, 0XA8);
    after_6:
    // 0x8003F390: addiu       $a0, $s2, 0x30
    ctx->r4 = ADD32(ctx->r18, 0X30);
    // 0x8003F394: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x8003F398: jal         0x80059B50
    // 0x8003F39C: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    func_80059B50(rdram, ctx);
        goto after_7;
    // 0x8003F39C: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    after_7:
    // 0x8003F3A0: j           L_8003F414
    // 0x8003F3A4: ori         $s0, $zero, 0xFFFF
    ctx->r16 = 0 | 0XFFFF;
        goto L_8003F414;
    // 0x8003F3A4: ori         $s0, $zero, 0xFFFF
    ctx->r16 = 0 | 0XFFFF;
L_8003F3A8:
    // 0x8003F3A8: lhu         $v0, 0x78($s2)
    ctx->r2 = MEM_HU(ctx->r18, 0X78);
    // 0x8003F3AC: andi        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 & 0X1;
    // 0x8003F3B0: beql        $v0, $zero, L_8003F414
    if (ctx->r2 == 0) {
        // 0x8003F3B4: ori         $s0, $zero, 0xFFFF
        ctx->r16 = 0 | 0XFFFF;
            goto L_8003F414;
    }
    goto skip_0;
    // 0x8003F3B4: ori         $s0, $zero, 0xFFFF
    ctx->r16 = 0 | 0XFFFF;
    skip_0:
    // 0x8003F3B8: lw          $v0, 0x8($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X8);
    // 0x8003F3BC: j           L_8003F3F8
    // 0x8003F3C0: nop

        goto L_8003F3F8;
    // 0x8003F3C0: nop

L_8003F3C4:
    // 0x8003F3C4: lhu         $v1, 0x2($s0)
    ctx->r3 = MEM_HU(ctx->r16, 0X2);
    // 0x8003F3C8: lw          $v0, 0xBB0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0XBB0);
    // 0x8003F3CC: sll         $v1, $v1, 3
    ctx->r3 = S32(ctx->r3 << 3);
    // 0x8003F3D0: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x8003F3D4: lw          $v1, 0x0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X0);
    // 0x8003F3D8: beq         $v1, $zero, L_8003F3E4
    if (ctx->r3 == 0) {
        // 0x8003F3DC: addu        $s1, $zero, $zero
        ctx->r17 = ADD32(0, 0);
            goto L_8003F3E4;
    }
    // 0x8003F3DC: addu        $s1, $zero, $zero
    ctx->r17 = ADD32(0, 0);
    // 0x8003F3E0: lw          $s1, 0x8($v1)
    ctx->r17 = MEM_W(ctx->r3, 0X8);
L_8003F3E4:
    // 0x8003F3E4: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // 0x8003F3E8: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    // 0x8003F3EC: jal         0x80018EF4
    // 0x8003F3F0: addiu       $a2, $zero, 0x30
    ctx->r6 = ADD32(0, 0X30);
    zmemcpy(rdram, ctx);
        goto after_8;
    // 0x8003F3F0: addiu       $a2, $zero, 0x30
    ctx->r6 = ADD32(0, 0X30);
    after_8:
    // 0x8003F3F4: lw          $v0, 0x8($s5)
    ctx->r2 = MEM_W(ctx->r21, 0X8);
L_8003F3F8:
    // 0x8003F3F8: lw          $t0, 0x0($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X0);
    // 0x8003F3FC: lw          $t1, 0x4($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X4);
    // 0x8003F400: lw          $t2, 0x8($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X8);
    // 0x8003F404: sw          $t0, 0x60($s2)
    MEM_W(0X60, ctx->r18) = ctx->r8;
    // 0x8003F408: sw          $t1, 0x64($s2)
    MEM_W(0X64, ctx->r18) = ctx->r9;
    // 0x8003F40C: sw          $t2, 0x68($s2)
    MEM_W(0X68, ctx->r18) = ctx->r10;
    // 0x8003F410: ori         $s0, $zero, 0xFFFF
    ctx->r16 = 0 | 0XFFFF;
L_8003F414:
    // 0x8003F414: lhu         $v1, 0x6C($s2)
    ctx->r3 = MEM_HU(ctx->r18, 0X6C);
    // 0x8003F418: ori         $s4, $zero, 0xFFFF
    ctx->r20 = 0 | 0XFFFF;
    // 0x8003F41C: beq         $v1, $s4, L_8003F468
    if (ctx->r3 == ctx->r20) {
        // 0x8003F420: lui         $s3, 0x8013
        ctx->r19 = S32(0X8013 << 16);
            goto L_8003F468;
    }
    // 0x8003F420: lui         $s3, 0x8013
    ctx->r19 = S32(0X8013 << 16);
    // 0x8003F424: lw          $v0, 0xBB0($s3)
    ctx->r2 = MEM_W(ctx->r19, 0XBB0);
    // 0x8003F428: sll         $s1, $v1, 3
    ctx->r17 = S32(ctx->r3 << 3);
    // 0x8003F42C: addu        $v0, $s1, $v0
    ctx->r2 = ADD32(ctx->r17, ctx->r2);
    // 0x8003F430: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x8003F434: beql        $v0, $zero, L_8003F6B4
    if (ctx->r2 == 0) {
        // 0x8003F438: sh          $s0, 0x6E($s2)
        MEM_H(0X6E, ctx->r18) = ctx->r16;
            goto L_8003F6B4;
    }
    goto skip_1;
    // 0x8003F438: sh          $s0, 0x6E($s2)
    MEM_H(0X6E, ctx->r18) = ctx->r16;
    skip_1:
    // 0x8003F43C: jal         0x8003E5F8
    // 0x8003F440: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    func_8003E5F8(rdram, ctx);
        goto after_9;
    // 0x8003F440: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    after_9:
    // 0x8003F444: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    // 0x8003F448: andi        $a0, $s0, 0xFFFF
    ctx->r4 = ctx->r16 & 0XFFFF;
    // 0x8003F44C: beql        $a0, $s4, L_8003F6B4
    if (ctx->r4 == ctx->r20) {
        // 0x8003F450: sh          $s0, 0x6E($s2)
        MEM_H(0X6E, ctx->r18) = ctx->r16;
            goto L_8003F6B4;
    }
    goto skip_2;
    // 0x8003F450: sh          $s0, 0x6E($s2)
    MEM_H(0X6E, ctx->r18) = ctx->r16;
    skip_2:
    // 0x8003F454: lw          $v0, 0xBB0($s3)
    ctx->r2 = MEM_W(ctx->r19, 0XBB0);
    // 0x8003F458: addu        $v0, $s1, $v0
    ctx->r2 = ADD32(ctx->r17, ctx->r2);
    // 0x8003F45C: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    // 0x8003F460: jal         0x8003E684
    // 0x8003F464: nop

    func_8003E684(rdram, ctx);
        goto after_10;
    // 0x8003F464: nop

    after_10:
L_8003F468:
    // 0x8003F468: j           L_8003F6B4
    // 0x8003F46C: sh          $s0, 0x6E($s2)
    MEM_H(0X6E, ctx->r18) = ctx->r16;
        goto L_8003F6B4;
    // 0x8003F46C: sh          $s0, 0x6E($s2)
    MEM_H(0X6E, ctx->r18) = ctx->r16;
L_8003F470:
    // 0x8003F470: lhu         $v1, 0x6E($s2)
    ctx->r3 = MEM_HU(ctx->r18, 0X6E);
    // 0x8003F474: ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
    // 0x8003F478: beq         $v1, $v0, L_8003F6B8
    if (ctx->r3 == ctx->r2) {
        // 0x8003F47C: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_8003F6B8;
    }
    // 0x8003F47C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8003F480: jal         0x8003F0C8
    // 0x8003F484: addu        $a0, $v1, $zero
    ctx->r4 = ADD32(ctx->r3, 0);
    func_8003F0C8(rdram, ctx);
        goto after_11;
    // 0x8003F484: addu        $a0, $v1, $zero
    ctx->r4 = ADD32(ctx->r3, 0);
    after_11:
    // 0x8003F488: j           L_8003F6B8
    // 0x8003F48C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8003F6B8;
    // 0x8003F48C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8003F490:
    // 0x8003F490: lhu         $v1, 0x6E($s2)
    ctx->r3 = MEM_HU(ctx->r18, 0X6E);
    // 0x8003F494: ori         $a1, $zero, 0xFFFF
    ctx->r5 = 0 | 0XFFFF;
    // 0x8003F498: beq         $v1, $a1, L_8003F6A8
    if (ctx->r3 == ctx->r5) {
        // 0x8003F49C: lui         $v0, 0x8013
        ctx->r2 = S32(0X8013 << 16);
            goto L_8003F6A8;
    }
    // 0x8003F49C: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8003F4A0: lw          $a0, 0xBB0($v0)
    ctx->r4 = MEM_W(ctx->r2, 0XBB0);
    // 0x8003F4A4: sll         $v0, $v1, 3
    ctx->r2 = S32(ctx->r3 << 3);
    // 0x8003F4A8: addu        $v1, $v0, $a0
    ctx->r3 = ADD32(ctx->r2, ctx->r4);
    // 0x8003F4AC: lhu         $v0, 0x4($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X4);
    // 0x8003F4B0: bne         $v0, $a1, L_8003F4C0
    if (ctx->r2 != ctx->r5) {
        // 0x8003F4B4: sll         $v0, $v0, 3
        ctx->r2 = S32(ctx->r2 << 3);
            goto L_8003F4C0;
    }
    // 0x8003F4B4: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x8003F4B8: j           L_8003F4CC
    // 0x8003F4BC: addu        $v1, $a1, $zero
    ctx->r3 = ADD32(ctx->r5, 0);
        goto L_8003F4CC;
    // 0x8003F4BC: addu        $v1, $a1, $zero
    ctx->r3 = ADD32(ctx->r5, 0);
L_8003F4C0:
    // 0x8003F4C0: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x8003F4C4: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x8003F4C8: lhu         $v1, 0x16($v0)
    ctx->r3 = MEM_HU(ctx->r2, 0X16);
L_8003F4CC:
    // 0x8003F4CC: lhu         $v0, 0x6C($s2)
    ctx->r2 = MEM_HU(ctx->r18, 0X6C);
    // 0x8003F4D0: andi        $a0, $v1, 0xFFFF
    ctx->r4 = ctx->r3 & 0XFFFF;
    // 0x8003F4D4: bne         $a0, $v0, L_8003F6A8
    if (ctx->r4 != ctx->r2) {
        // 0x8003F4D8: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_8003F6A8;
    }
    // 0x8003F4D8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8003F4DC: lh          $v1, 0x76($s2)
    ctx->r3 = MEM_H(ctx->r18, 0X76);
    // 0x8003F4E0: beq         $v1, $v0, L_8003F584
    if (ctx->r3 == ctx->r2) {
        // 0x8003F4E4: slti        $v0, $v1, 0x2
        ctx->r2 = SIGNED(ctx->r3) < 0X2 ? 1 : 0;
            goto L_8003F584;
    }
    // 0x8003F4E4: slti        $v0, $v1, 0x2
    ctx->r2 = SIGNED(ctx->r3) < 0X2 ? 1 : 0;
    // 0x8003F4E8: beq         $v0, $zero, L_8003F500
    if (ctx->r2 == 0) {
        // 0x8003F4EC: addiu       $v0, $zero, 0x2
        ctx->r2 = ADD32(0, 0X2);
            goto L_8003F500;
    }
    // 0x8003F4EC: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x8003F4F0: beq         $v1, $zero, L_8003F510
    if (ctx->r3 == 0) {
        // 0x8003F4F4: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_8003F510;
    }
    // 0x8003F4F4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8003F4F8: j           L_8003F6B8
    // 0x8003F4FC: nop

        goto L_8003F6B8;
    // 0x8003F4FC: nop

L_8003F500:
    // 0x8003F500: beq         $v1, $v0, L_8003F62C
    if (ctx->r3 == ctx->r2) {
        // 0x8003F504: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_8003F62C;
    }
    // 0x8003F504: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8003F508: j           L_8003F6B8
    // 0x8003F50C: nop

        goto L_8003F6B8;
    // 0x8003F50C: nop

L_8003F510:
    // 0x8003F510: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8003F514: lw          $v1, 0xBB0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0XBB0);
    // 0x8003F518: sll         $v0, $a0, 3
    ctx->r2 = S32(ctx->r4 << 3);
    // 0x8003F51C: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8003F520: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x8003F524: beq         $v0, $zero, L_8003F530
    if (ctx->r2 == 0) {
        // 0x8003F528: addu        $s1, $zero, $zero
        ctx->r17 = ADD32(0, 0);
            goto L_8003F530;
    }
    // 0x8003F528: addu        $s1, $zero, $zero
    ctx->r17 = ADD32(0, 0);
    // 0x8003F52C: lw          $s1, 0x8($v0)
    ctx->r17 = MEM_W(ctx->r2, 0X8);
L_8003F530:
    // 0x8003F530: addiu       $s0, $sp, 0xC0
    ctx->r16 = ADD32(ctx->r29, 0XC0);
    // 0x8003F534: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x8003F538: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x8003F53C: jal         0x80059B50
    // 0x8003F540: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    func_80059B50(rdram, ctx);
        goto after_12;
    // 0x8003F540: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    after_12:
    // 0x8003F544: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x8003F548: addiu       $a1, $s2, 0x30
    ctx->r5 = ADD32(ctx->r18, 0X30);
    // 0x8003F54C: addiu       $s0, $sp, 0xF0
    ctx->r16 = ADD32(ctx->r29, 0XF0);
    // 0x8003F550: jal         0x800191C4
    // 0x8003F554: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    func_800191C4(rdram, ctx);
        goto after_13;
    // 0x8003F554: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    after_13:
    // 0x8003F558: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // 0x8003F55C: jal         0x80059D18
    // 0x8003F560: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    func_80059D18(rdram, ctx);
        goto after_14;
    // 0x8003F560: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    after_14:
L_8003F564:
    // 0x8003F564: lw          $t0, 0x24($s1)
    ctx->r8 = MEM_W(ctx->r17, 0X24);
    // 0x8003F568: lw          $t1, 0x28($s1)
    ctx->r9 = MEM_W(ctx->r17, 0X28);
    // 0x8003F56C: lw          $t2, 0x2C($s1)
    ctx->r10 = MEM_W(ctx->r17, 0X2C);
    // 0x8003F570: sw          $t0, 0x24($s2)
    MEM_W(0X24, ctx->r18) = ctx->r8;
    // 0x8003F574: sw          $t1, 0x28($s2)
    MEM_W(0X28, ctx->r18) = ctx->r9;
    // 0x8003F578: sw          $t2, 0x2C($s2)
    MEM_W(0X2C, ctx->r18) = ctx->r10;
    // 0x8003F57C: j           L_8003F6B8
    // 0x8003F580: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8003F6B8;
    // 0x8003F580: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8003F584:
    // 0x8003F584: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x8003F588: lh          $v0, 0x74($s2)
    ctx->r2 = MEM_H(ctx->r18, 0X74);
    // 0x8003F58C: addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    // 0x8003F590: sw          $v0, 0x120($sp)
    MEM_W(0X120, ctx->r29) = ctx->r2;
    // 0x8003F594: sw          $s2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r18;
    // 0x8003F598: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x8003F59C: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x8003F5A0: lw          $a0, 0x70($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X70);
    // 0x8003F5A4: jal         0x8005857C
    // 0x8003F5A8: addiu       $a3, $sp, 0x120
    ctx->r7 = ADD32(ctx->r29, 0X120);
    func_8005857C(rdram, ctx);
        goto after_15;
    // 0x8003F5A8: addiu       $a3, $sp, 0x120
    ctx->r7 = ADD32(ctx->r29, 0X120);
    after_15:
    // 0x8003F5AC: lhu         $v0, 0x78($s2)
    ctx->r2 = MEM_HU(ctx->r18, 0X78);
    // 0x8003F5B0: andi        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 & 0X1;
    // 0x8003F5B4: beq         $v0, $zero, L_8003F604
    if (ctx->r2 == 0) {
        // 0x8003F5B8: lui         $v0, 0x8013
        ctx->r2 = S32(0X8013 << 16);
            goto L_8003F604;
    }
    // 0x8003F5B8: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8003F5BC: lwc1        $f2, 0xC($s2)
    ctx->f2.u32l = MEM_W(ctx->r18, 0XC);
    // 0x8003F5C0: lwc1        $f0, 0x60($s2)
    ctx->f0.u32l = MEM_W(ctx->r18, 0X60);
    // 0x8003F5C4: mul.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x8003F5C8: lwc1        $f8, 0x10($s2)
    ctx->f8.u32l = MEM_W(ctx->r18, 0X10);
    // 0x8003F5CC: lwc1        $f0, 0x64($s2)
    ctx->f0.u32l = MEM_W(ctx->r18, 0X64);
    // 0x8003F5D0: mul.s       $f8, $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x8003F5D4: lwc1        $f6, 0x14($s2)
    ctx->f6.u32l = MEM_W(ctx->r18, 0X14);
    // 0x8003F5D8: lwc1        $f0, 0x68($s2)
    ctx->f0.u32l = MEM_W(ctx->r18, 0X68);
    // 0x8003F5DC: mul.s       $f6, $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x8003F5E0: lwc1        $f4, 0x0($s2)
    ctx->f4.u32l = MEM_W(ctx->r18, 0X0);
    // 0x8003F5E4: add.s       $f4, $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f2.fl;
    // 0x8003F5E8: lwc1        $f2, 0x4($s2)
    ctx->f2.u32l = MEM_W(ctx->r18, 0X4);
    // 0x8003F5EC: add.s       $f2, $f2, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f8.fl;
    // 0x8003F5F0: lwc1        $f0, 0x8($s2)
    ctx->f0.u32l = MEM_W(ctx->r18, 0X8);
    // 0x8003F5F4: add.s       $f0, $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f6.fl;
    // 0x8003F5F8: swc1        $f4, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->f4.u32l;
    // 0x8003F5FC: swc1        $f2, 0x4($s2)
    MEM_W(0X4, ctx->r18) = ctx->f2.u32l;
    // 0x8003F600: swc1        $f0, 0x8($s2)
    MEM_W(0X8, ctx->r18) = ctx->f0.u32l;
L_8003F604:
    // 0x8003F604: lhu         $v1, 0x6C($s2)
    ctx->r3 = MEM_HU(ctx->r18, 0X6C);
    // 0x8003F608: lw          $v0, 0xBB0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0XBB0);
    // 0x8003F60C: sll         $v1, $v1, 3
    ctx->r3 = S32(ctx->r3 << 3);
    // 0x8003F610: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x8003F614: lw          $v1, 0x0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X0);
    // 0x8003F618: beq         $v1, $zero, L_8003F564
    if (ctx->r3 == 0) {
        // 0x8003F61C: addu        $s1, $zero, $zero
        ctx->r17 = ADD32(0, 0);
            goto L_8003F564;
    }
    // 0x8003F61C: addu        $s1, $zero, $zero
    ctx->r17 = ADD32(0, 0);
    // 0x8003F620: lw          $s1, 0x8($v1)
    ctx->r17 = MEM_W(ctx->r3, 0X8);
    // 0x8003F624: j           L_8003F564
    // 0x8003F628: nop

        goto L_8003F564;
    // 0x8003F628: nop

L_8003F62C:
    // 0x8003F62C: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8003F630: lw          $v1, 0xBB0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0XBB0);
    // 0x8003F634: sll         $v0, $a0, 3
    ctx->r2 = S32(ctx->r4 << 3);
    // 0x8003F638: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8003F63C: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x8003F640: beq         $v0, $zero, L_8003F64C
    if (ctx->r2 == 0) {
        // 0x8003F644: addu        $s1, $zero, $zero
        ctx->r17 = ADD32(0, 0);
            goto L_8003F64C;
    }
    // 0x8003F644: addu        $s1, $zero, $zero
    ctx->r17 = ADD32(0, 0);
    // 0x8003F648: lw          $s1, 0x8($v0)
    ctx->r17 = MEM_W(ctx->r2, 0X8);
L_8003F64C:
    // 0x8003F64C: addiu       $s0, $sp, 0xC0
    ctx->r16 = ADD32(ctx->r29, 0XC0);
    // 0x8003F650: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x8003F654: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x8003F658: jal         0x80059B50
    // 0x8003F65C: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    func_80059B50(rdram, ctx);
        goto after_16;
    // 0x8003F65C: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    after_16:
    // 0x8003F660: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x8003F664: addiu       $a1, $s2, 0x60
    ctx->r5 = ADD32(ctx->r18, 0X60);
    // 0x8003F668: jal         0x800193E8
    // 0x8003F66C: addu        $a2, $s2, $zero
    ctx->r6 = ADD32(ctx->r18, 0);
    func_800193E8(rdram, ctx);
        goto after_17;
    // 0x8003F66C: addu        $a2, $s2, $zero
    ctx->r6 = ADD32(ctx->r18, 0);
    after_17:
    // 0x8003F670: lw          $t0, 0xC($s1)
    ctx->r8 = MEM_W(ctx->r17, 0XC);
    // 0x8003F674: lw          $t1, 0x10($s1)
    ctx->r9 = MEM_W(ctx->r17, 0X10);
    // 0x8003F678: lw          $t2, 0x14($s1)
    ctx->r10 = MEM_W(ctx->r17, 0X14);
    // 0x8003F67C: sw          $t0, 0xC($s2)
    MEM_W(0XC, ctx->r18) = ctx->r8;
    // 0x8003F680: sw          $t1, 0x10($s2)
    MEM_W(0X10, ctx->r18) = ctx->r9;
    // 0x8003F684: sw          $t2, 0x14($s2)
    MEM_W(0X14, ctx->r18) = ctx->r10;
    // 0x8003F688: lw          $t0, 0x18($s1)
    ctx->r8 = MEM_W(ctx->r17, 0X18);
    // 0x8003F68C: lw          $t1, 0x1C($s1)
    ctx->r9 = MEM_W(ctx->r17, 0X1C);
    // 0x8003F690: lw          $t2, 0x20($s1)
    ctx->r10 = MEM_W(ctx->r17, 0X20);
    // 0x8003F694: sw          $t0, 0x18($s2)
    MEM_W(0X18, ctx->r18) = ctx->r8;
    // 0x8003F698: sw          $t1, 0x1C($s2)
    MEM_W(0X1C, ctx->r18) = ctx->r9;
    // 0x8003F69C: sw          $t2, 0x20($s2)
    MEM_W(0X20, ctx->r18) = ctx->r10;
    // 0x8003F6A0: j           L_8003F564
    // 0x8003F6A4: nop

        goto L_8003F564;
    // 0x8003F6A4: nop

L_8003F6A8:
    // 0x8003F6A8: lhu         $a0, 0x16($s3)
    ctx->r4 = MEM_HU(ctx->r19, 0X16);
    // 0x8003F6AC: jal         0x8003ED74
    // 0x8003F6B0: nop

    func_8003ED74(rdram, ctx);
        goto after_18;
    // 0x8003F6B0: nop

    after_18:
L_8003F6B4:
    // 0x8003F6B4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8003F6B8:
    // 0x8003F6B8: lw          $ra, 0x140($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X140);
    // 0x8003F6BC: lw          $s5, 0x13C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X13C);
    // 0x8003F6C0: lw          $s4, 0x138($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X138);
    // 0x8003F6C4: lw          $s3, 0x134($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X134);
    // 0x8003F6C8: lw          $s2, 0x130($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X130);
    // 0x8003F6CC: lw          $s1, 0x12C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X12C);
    // 0x8003F6D0: lw          $s0, 0x128($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X128);
    // 0x8003F6D4: ldc1        $f22, 0x150($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X150);
    // 0x8003F6D8: ldc1        $f20, 0x148($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X148);
    // 0x8003F6DC: jr          $ra
    // 0x8003F6E0: addiu       $sp, $sp, 0x158
    ctx->r29 = ADD32(ctx->r29, 0X158);
    return;
    // 0x8003F6E0: addiu       $sp, $sp, 0x158
    ctx->r29 = ADD32(ctx->r29, 0X158);
;}
RECOMP_FUNC void func_8003F6E4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003F6E4: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x8003F6E8: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x8003F6EC: sh          $a0, 0x12($sp)
    MEM_H(0X12, ctx->r29) = ctx->r4;
    // 0x8003F6F0: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    // 0x8003F6F4: lui         $a2, 0x8013
    ctx->r6 = S32(0X8013 << 16);
    // 0x8003F6F8: lw          $v1, 0xBB0($a2)
    ctx->r3 = MEM_W(ctx->r6, 0XBB0);
    // 0x8003F6FC: sll         $a0, $a0, 3
    ctx->r4 = S32(ctx->r4 << 3);
    // 0x8003F700: sw          $ra, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r31;
    // 0x8003F704: sw          $s3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r19;
    // 0x8003F708: sw          $s2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r18;
    // 0x8003F70C: sw          $s1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r17;
    // 0x8003F710: sw          $s0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r16;
    // 0x8003F714: sh          $v0, 0x10($sp)
    MEM_H(0X10, ctx->r29) = ctx->r2;
    // 0x8003F718: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    // 0x8003F71C: sh          $zero, 0x24($sp)
    MEM_H(0X24, ctx->r29) = 0;
    // 0x8003F720: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x8003F724: addu        $a0, $a0, $v1
    ctx->r4 = ADD32(ctx->r4, ctx->r3);
    // 0x8003F728: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8003F72C: lbu         $v0, 0x19($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X19);
    // 0x8003F730: addiu       $s1, $v0, 0x1
    ctx->r17 = ADD32(ctx->r2, 0X1);
    // 0x8003F734: lui         $v0, 0x8004
    ctx->r2 = S32(0X8004 << 16);
    // 0x8003F738: addiu       $s3, $v0, -0xE30
    ctx->r19 = ADD32(ctx->r2, -0XE30);
    // 0x8003F73C: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8003F740: lw          $v0, 0xBC8($v0)
    ctx->r2 = MEM_W(ctx->r2, 0XBC8);
    // 0x8003F744: bgez        $v0, L_8003F7A4
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8003F748: addiu       $s2, $sp, 0x10
        ctx->r18 = ADD32(ctx->r29, 0X10);
            goto L_8003F7A4;
    }
    // 0x8003F748: addiu       $s2, $sp, 0x10
    ctx->r18 = ADD32(ctx->r29, 0X10);
    // 0x8003F74C: lhu         $a1, 0xE($v1)
    ctx->r5 = MEM_HU(ctx->r3, 0XE);
    // 0x8003F750: ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
    // 0x8003F754: beq         $a1, $v0, L_8003F7A4
    if (ctx->r5 == ctx->r2) {
        // 0x8003F758: addu        $a3, $v0, $zero
        ctx->r7 = ADD32(ctx->r2, 0);
            goto L_8003F7A4;
    }
    // 0x8003F758: addu        $a3, $v0, $zero
    ctx->r7 = ADD32(ctx->r2, 0);
    // 0x8003F75C: andi        $a0, $a1, 0xFFFF
    ctx->r4 = ctx->r5 & 0XFFFF;
L_8003F760:
    // 0x8003F760: lw          $v1, 0xBB0($a2)
    ctx->r3 = MEM_W(ctx->r6, 0XBB0);
    // 0x8003F764: sll         $v0, $a0, 3
    ctx->r2 = S32(ctx->r4 << 3);
    // 0x8003F768: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8003F76C: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x8003F770: beql        $v0, $zero, L_8003F794
    if (ctx->r2 == 0) {
        // 0x8003F774: sll         $v0, $a1, 3
        ctx->r2 = S32(ctx->r5 << 3);
            goto L_8003F794;
    }
    goto skip_0;
    // 0x8003F774: sll         $v0, $a1, 3
    ctx->r2 = S32(ctx->r5 << 3);
    skip_0:
    // 0x8003F778: lbu         $v0, 0x1A($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X1A);
    // 0x8003F77C: bne         $v0, $zero, L_8003F794
    if (ctx->r2 != 0) {
        // 0x8003F780: sll         $v0, $a1, 3
        ctx->r2 = S32(ctx->r5 << 3);
            goto L_8003F794;
    }
    // 0x8003F780: sll         $v0, $a1, 3
    ctx->r2 = S32(ctx->r5 << 3);
    // 0x8003F784: jal         0x8003ED74
    // 0x8003F788: nop

    func_8003ED74(rdram, ctx);
        goto after_0;
    // 0x8003F788: nop

    after_0:
    // 0x8003F78C: j           L_8003F7A8
    // 0x8003F790: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
        goto L_8003F7A8;
    // 0x8003F790: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
L_8003F794:
    // 0x8003F794: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8003F798: lhu         $a1, 0x6($v0)
    ctx->r5 = MEM_HU(ctx->r2, 0X6);
    // 0x8003F79C: bnel        $a1, $a3, L_8003F760
    if (ctx->r5 != ctx->r7) {
        // 0x8003F7A0: andi        $a0, $a1, 0xFFFF
        ctx->r4 = ctx->r5 & 0XFFFF;
            goto L_8003F760;
    }
    goto skip_1;
    // 0x8003F7A0: andi        $a0, $a1, 0xFFFF
    ctx->r4 = ctx->r5 & 0XFFFF;
    skip_1:
L_8003F7A4:
    // 0x8003F7A4: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
L_8003F7A8:
    // 0x8003F7A8: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8003F7AC: lw          $v1, 0xBC8($a1)
    ctx->r3 = MEM_W(ctx->r5, 0XBC8);
    // 0x8003F7B0: lw          $a0, 0xBBC($v0)
    ctx->r4 = MEM_W(ctx->r2, 0XBBC);
    // 0x8003F7B4: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x8003F7B8: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x8003F7BC: addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
    // 0x8003F7C0: lw          $s0, 0x0($v0)
    ctx->r16 = MEM_W(ctx->r2, 0X0);
    // 0x8003F7C4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8003F7C8: sw          $v1, 0xBC8($a1)
    MEM_W(0XBC8, ctx->r5) = ctx->r3;
    // 0x8003F7CC: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x8003F7D0: sw          $zero, 0x4($s0)
    MEM_W(0X4, ctx->r16) = 0;
    // 0x8003F7D4: sw          $zero, 0x8($s0)
    MEM_W(0X8, ctx->r16) = 0;
    // 0x8003F7D8: sw          $zero, 0xC($s0)
    MEM_W(0XC, ctx->r16) = 0;
    // 0x8003F7DC: sw          $s3, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r19;
    // 0x8003F7E0: sw          $zero, 0x10($s0)
    MEM_W(0X10, ctx->r16) = 0;
    // 0x8003F7E4: sh          $v0, 0x14($s0)
    MEM_H(0X14, ctx->r16) = ctx->r2;
    // 0x8003F7E8: sb          $zero, 0x1B($s0)
    MEM_B(0X1B, ctx->r16) = 0;
    // 0x8003F7EC: sb          $zero, 0x1A($s0)
    MEM_B(0X1A, ctx->r16) = 0;
    // 0x8003F7F0: jal         0x8003E5F8
    // 0x8003F7F4: sb          $s1, 0x19($s0)
    MEM_B(0X19, ctx->r16) = ctx->r17;
    func_8003E5F8(rdram, ctx);
        goto after_1;
    // 0x8003F7F4: sb          $s1, 0x19($s0)
    MEM_B(0X19, ctx->r16) = ctx->r17;
    after_1:
    // 0x8003F7F8: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x8003F7FC: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x8003F800: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x8003F804: sh          $v0, 0x16($s0)
    MEM_H(0X16, ctx->r16) = ctx->r2;
    // 0x8003F808: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x8003F80C: lw          $v1, 0xBB0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0XBB0);
    // 0x8003F810: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x8003F814: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8003F818: jal         0x8003E684
    // 0x8003F81C: sw          $s0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r16;
    func_8003E684(rdram, ctx);
        goto after_2;
    // 0x8003F81C: sw          $s0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r16;
    after_2:
    // 0x8003F820: jal         0x8003EA4C
    // 0x8003F824: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_8003EA4C(rdram, ctx);
        goto after_3;
    // 0x8003F824: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_3:
    // 0x8003F828: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8003F82C: lhu         $a0, 0x16($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X16);
    // 0x8003F830: jal         0x8003E8DC
    // 0x8003F834: addu        $a2, $s2, $zero
    ctx->r6 = ADD32(ctx->r18, 0);
    func_8003E8DC(rdram, ctx);
        goto after_4;
    // 0x8003F834: addu        $a2, $s2, $zero
    ctx->r6 = ADD32(ctx->r18, 0);
    after_4:
    // 0x8003F838: lhu         $s0, 0x16($s0)
    ctx->r16 = MEM_HU(ctx->r16, 0X16);
    // 0x8003F83C: ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
    // 0x8003F840: beq         $s0, $v0, L_8003F860
    if (ctx->r16 == ctx->r2) {
        // 0x8003F844: addu        $a0, $s0, $zero
        ctx->r4 = ADD32(ctx->r16, 0);
            goto L_8003F860;
    }
    // 0x8003F844: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x8003F848: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x8003F84C: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8003F850: lwc1        $f0, -0x5BFC($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X5BFC);
    // 0x8003F854: addiu       $a2, $sp, 0x28
    ctx->r6 = ADD32(ctx->r29, 0X28);
    // 0x8003F858: jal         0x8003E8DC
    // 0x8003F85C: swc1        $f0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f0.u32l;
    func_8003E8DC(rdram, ctx);
        goto after_5;
    // 0x8003F85C: swc1        $f0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f0.u32l;
    after_5:
L_8003F860:
    // 0x8003F860: addu        $v0, $s0, $zero
    ctx->r2 = ADD32(ctx->r16, 0);
    // 0x8003F864: lw          $ra, 0x40($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X40);
    // 0x8003F868: lw          $s3, 0x3C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X3C);
    // 0x8003F86C: lw          $s2, 0x38($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X38);
    // 0x8003F870: lw          $s1, 0x34($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X34);
    // 0x8003F874: lw          $s0, 0x30($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X30);
    // 0x8003F878: jr          $ra
    // 0x8003F87C: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x8003F87C: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void func_8003F880(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003F880: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x8003F884: sh          $a0, 0x12($sp)
    MEM_H(0X12, ctx->r29) = ctx->r4;
    // 0x8003F888: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    // 0x8003F88C: lui         $a2, 0x8013
    ctx->r6 = S32(0X8013 << 16);
    // 0x8003F890: lw          $v1, 0xBB0($a2)
    ctx->r3 = MEM_W(ctx->r6, 0XBB0);
    // 0x8003F894: sll         $a0, $a0, 3
    ctx->r4 = S32(ctx->r4 << 3);
    // 0x8003F898: sw          $ra, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r31;
    // 0x8003F89C: sw          $s3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r19;
    // 0x8003F8A0: sw          $s2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r18;
    // 0x8003F8A4: sw          $s1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r17;
    // 0x8003F8A8: sw          $s0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r16;
    // 0x8003F8AC: sh          $zero, 0x10($sp)
    MEM_H(0X10, ctx->r29) = 0;
    // 0x8003F8B0: sw          $a1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r5;
    // 0x8003F8B4: sh          $zero, 0x24($sp)
    MEM_H(0X24, ctx->r29) = 0;
    // 0x8003F8B8: addu        $a0, $a0, $v1
    ctx->r4 = ADD32(ctx->r4, ctx->r3);
    // 0x8003F8BC: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8003F8C0: lbu         $v0, 0x19($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X19);
    // 0x8003F8C4: addiu       $s1, $v0, 0x1
    ctx->r17 = ADD32(ctx->r2, 0X1);
    // 0x8003F8C8: lui         $v0, 0x8004
    ctx->r2 = S32(0X8004 << 16);
    // 0x8003F8CC: addiu       $s3, $v0, -0xE30
    ctx->r19 = ADD32(ctx->r2, -0XE30);
    // 0x8003F8D0: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8003F8D4: lw          $v0, 0xBC8($v0)
    ctx->r2 = MEM_W(ctx->r2, 0XBC8);
    // 0x8003F8D8: bgez        $v0, L_8003F938
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8003F8DC: addiu       $s2, $sp, 0x10
        ctx->r18 = ADD32(ctx->r29, 0X10);
            goto L_8003F938;
    }
    // 0x8003F8DC: addiu       $s2, $sp, 0x10
    ctx->r18 = ADD32(ctx->r29, 0X10);
    // 0x8003F8E0: lhu         $a1, 0xE($v1)
    ctx->r5 = MEM_HU(ctx->r3, 0XE);
    // 0x8003F8E4: ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
    // 0x8003F8E8: beq         $a1, $v0, L_8003F938
    if (ctx->r5 == ctx->r2) {
        // 0x8003F8EC: addu        $a3, $v0, $zero
        ctx->r7 = ADD32(ctx->r2, 0);
            goto L_8003F938;
    }
    // 0x8003F8EC: addu        $a3, $v0, $zero
    ctx->r7 = ADD32(ctx->r2, 0);
    // 0x8003F8F0: andi        $a0, $a1, 0xFFFF
    ctx->r4 = ctx->r5 & 0XFFFF;
L_8003F8F4:
    // 0x8003F8F4: lw          $v1, 0xBB0($a2)
    ctx->r3 = MEM_W(ctx->r6, 0XBB0);
    // 0x8003F8F8: sll         $v0, $a0, 3
    ctx->r2 = S32(ctx->r4 << 3);
    // 0x8003F8FC: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8003F900: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x8003F904: beql        $v0, $zero, L_8003F928
    if (ctx->r2 == 0) {
        // 0x8003F908: sll         $v0, $a1, 3
        ctx->r2 = S32(ctx->r5 << 3);
            goto L_8003F928;
    }
    goto skip_0;
    // 0x8003F908: sll         $v0, $a1, 3
    ctx->r2 = S32(ctx->r5 << 3);
    skip_0:
    // 0x8003F90C: lbu         $v0, 0x1A($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X1A);
    // 0x8003F910: bne         $v0, $zero, L_8003F928
    if (ctx->r2 != 0) {
        // 0x8003F914: sll         $v0, $a1, 3
        ctx->r2 = S32(ctx->r5 << 3);
            goto L_8003F928;
    }
    // 0x8003F914: sll         $v0, $a1, 3
    ctx->r2 = S32(ctx->r5 << 3);
    // 0x8003F918: jal         0x8003ED74
    // 0x8003F91C: nop

    func_8003ED74(rdram, ctx);
        goto after_0;
    // 0x8003F91C: nop

    after_0:
    // 0x8003F920: j           L_8003F93C
    // 0x8003F924: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
        goto L_8003F93C;
    // 0x8003F924: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
L_8003F928:
    // 0x8003F928: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8003F92C: lhu         $a1, 0x6($v0)
    ctx->r5 = MEM_HU(ctx->r2, 0X6);
    // 0x8003F930: bnel        $a1, $a3, L_8003F8F4
    if (ctx->r5 != ctx->r7) {
        // 0x8003F934: andi        $a0, $a1, 0xFFFF
        ctx->r4 = ctx->r5 & 0XFFFF;
            goto L_8003F8F4;
    }
    goto skip_1;
    // 0x8003F934: andi        $a0, $a1, 0xFFFF
    ctx->r4 = ctx->r5 & 0XFFFF;
    skip_1:
L_8003F938:
    // 0x8003F938: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
L_8003F93C:
    // 0x8003F93C: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8003F940: lw          $v1, 0xBC8($a1)
    ctx->r3 = MEM_W(ctx->r5, 0XBC8);
    // 0x8003F944: lw          $a0, 0xBBC($v0)
    ctx->r4 = MEM_W(ctx->r2, 0XBBC);
    // 0x8003F948: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x8003F94C: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x8003F950: addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
    // 0x8003F954: lw          $s0, 0x0($v0)
    ctx->r16 = MEM_W(ctx->r2, 0X0);
    // 0x8003F958: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8003F95C: sw          $v1, 0xBC8($a1)
    MEM_W(0XBC8, ctx->r5) = ctx->r3;
    // 0x8003F960: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x8003F964: sw          $zero, 0x4($s0)
    MEM_W(0X4, ctx->r16) = 0;
    // 0x8003F968: sw          $zero, 0x8($s0)
    MEM_W(0X8, ctx->r16) = 0;
    // 0x8003F96C: sw          $zero, 0xC($s0)
    MEM_W(0XC, ctx->r16) = 0;
    // 0x8003F970: sw          $s3, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r19;
    // 0x8003F974: sw          $zero, 0x10($s0)
    MEM_W(0X10, ctx->r16) = 0;
    // 0x8003F978: sh          $v0, 0x14($s0)
    MEM_H(0X14, ctx->r16) = ctx->r2;
    // 0x8003F97C: sb          $zero, 0x1B($s0)
    MEM_B(0X1B, ctx->r16) = 0;
    // 0x8003F980: sb          $zero, 0x1A($s0)
    MEM_B(0X1A, ctx->r16) = 0;
    // 0x8003F984: jal         0x8003E5F8
    // 0x8003F988: sb          $s1, 0x19($s0)
    MEM_B(0X19, ctx->r16) = ctx->r17;
    func_8003E5F8(rdram, ctx);
        goto after_1;
    // 0x8003F988: sb          $s1, 0x19($s0)
    MEM_B(0X19, ctx->r16) = ctx->r17;
    after_1:
    // 0x8003F98C: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x8003F990: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x8003F994: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x8003F998: sh          $v0, 0x16($s0)
    MEM_H(0X16, ctx->r16) = ctx->r2;
    // 0x8003F99C: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x8003F9A0: lw          $v1, 0xBB0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0XBB0);
    // 0x8003F9A4: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x8003F9A8: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8003F9AC: jal         0x8003E684
    // 0x8003F9B0: sw          $s0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r16;
    func_8003E684(rdram, ctx);
        goto after_2;
    // 0x8003F9B0: sw          $s0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r16;
    after_2:
    // 0x8003F9B4: jal         0x8003EA4C
    // 0x8003F9B8: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_8003EA4C(rdram, ctx);
        goto after_3;
    // 0x8003F9B8: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_3:
    // 0x8003F9BC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8003F9C0: lhu         $a0, 0x16($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X16);
    // 0x8003F9C4: jal         0x8003E8DC
    // 0x8003F9C8: addu        $a2, $s2, $zero
    ctx->r6 = ADD32(ctx->r18, 0);
    func_8003E8DC(rdram, ctx);
        goto after_4;
    // 0x8003F9C8: addu        $a2, $s2, $zero
    ctx->r6 = ADD32(ctx->r18, 0);
    after_4:
    // 0x8003F9CC: lhu         $s0, 0x16($s0)
    ctx->r16 = MEM_HU(ctx->r16, 0X16);
    // 0x8003F9D0: ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
    // 0x8003F9D4: beq         $s0, $v0, L_8003F9F4
    if (ctx->r16 == ctx->r2) {
        // 0x8003F9D8: addu        $a0, $s0, $zero
        ctx->r4 = ADD32(ctx->r16, 0);
            goto L_8003F9F4;
    }
    // 0x8003F9D8: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x8003F9DC: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x8003F9E0: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8003F9E4: lwc1        $f0, -0x5BF8($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X5BF8);
    // 0x8003F9E8: addiu       $a2, $sp, 0x28
    ctx->r6 = ADD32(ctx->r29, 0X28);
    // 0x8003F9EC: jal         0x8003E8DC
    // 0x8003F9F0: swc1        $f0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f0.u32l;
    func_8003E8DC(rdram, ctx);
        goto after_5;
    // 0x8003F9F0: swc1        $f0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f0.u32l;
    after_5:
L_8003F9F4:
    // 0x8003F9F4: addu        $v0, $s0, $zero
    ctx->r2 = ADD32(ctx->r16, 0);
    // 0x8003F9F8: lw          $ra, 0x40($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X40);
    // 0x8003F9FC: lw          $s3, 0x3C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X3C);
    // 0x8003FA00: lw          $s2, 0x38($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X38);
    // 0x8003FA04: lw          $s1, 0x34($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X34);
    // 0x8003FA08: lw          $s0, 0x30($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X30);
    // 0x8003FA0C: jr          $ra
    // 0x8003FA10: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x8003FA10: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void func_8003FA14(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003FA14: addiu       $sp, $sp, -0x88
    ctx->r29 = ADD32(ctx->r29, -0X88);
    // 0x8003FA18: sw          $s1, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r17;
    // 0x8003FA1C: addu        $s1, $a0, $zero
    ctx->r17 = ADD32(ctx->r4, 0);
    // 0x8003FA20: sw          $s3, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r19;
    // 0x8003FA24: addu        $s3, $a2, $zero
    ctx->r19 = ADD32(ctx->r6, 0);
    // 0x8003FA28: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // 0x8003FA2C: andi        $v0, $s1, 0xFFFF
    ctx->r2 = ctx->r17 & 0XFFFF;
    // 0x8003FA30: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x8003FA34: lw          $v1, 0xBB0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0XBB0);
    // 0x8003FA38: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x8003FA3C: sw          $ra, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r31;
    // 0x8003FA40: sw          $s2, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r18;
    // 0x8003FA44: sw          $s0, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r16;
    // 0x8003FA48: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8003FA4C: lw          $s2, 0x0($v0)
    ctx->r18 = MEM_W(ctx->r2, 0X0);
    // 0x8003FA50: addiu       $s0, $sp, 0x38
    ctx->r16 = ADD32(ctx->r29, 0X38);
    // 0x8003FA54: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x8003FA58: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x8003FA5C: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x8003FA60: lw          $a0, 0xC($s2)
    ctx->r4 = MEM_W(ctx->r18, 0XC);
    // 0x8003FA64: jal         0x8005857C
    // 0x8003FA68: addiu       $a3, $sp, 0x68
    ctx->r7 = ADD32(ctx->r29, 0X68);
    func_8005857C(rdram, ctx);
        goto after_0;
    // 0x8003FA68: addiu       $a3, $sp, 0x68
    ctx->r7 = ADD32(ctx->r29, 0X68);
    after_0:
    // 0x8003FA6C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8003FA70: sh          $a0, 0x20($sp)
    MEM_H(0X20, ctx->r29) = ctx->r4;
    // 0x8003FA74: sh          $s1, 0x22($sp)
    MEM_H(0X22, ctx->r29) = ctx->r17;
    // 0x8003FA78: lw          $v0, 0xC($s2)
    ctx->r2 = MEM_W(ctx->r18, 0XC);
    // 0x8003FA7C: lw          $v1, 0x68($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X68);
    // 0x8003FA80: sw          $s0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r16;
    // 0x8003FA84: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x8003FA88: beq         $s3, $zero, L_8003FAAC
    if (ctx->r19 == 0) {
        // 0x8003FA8C: sw          $v1, 0x30($sp)
        MEM_W(0X30, ctx->r29) = ctx->r3;
            goto L_8003FAAC;
    }
    // 0x8003FA8C: sw          $v1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r3;
    // 0x8003FA90: sh          $a0, 0x34($sp)
    MEM_H(0X34, ctx->r29) = ctx->r4;
    // 0x8003FA94: j           L_8003FAB0
    // 0x8003FA98: sw          $s3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r19;
        goto L_8003FAB0;
    // 0x8003FA98: sw          $s3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r19;
L_8003FA9C:
    // 0x8003FA9C: jal         0x8003ED74
    // 0x8003FAA0: addu        $a0, $v1, $zero
    ctx->r4 = ADD32(ctx->r3, 0);
    func_8003ED74(rdram, ctx);
        goto after_1;
    // 0x8003FAA0: addu        $a0, $v1, $zero
    ctx->r4 = ADD32(ctx->r3, 0);
    after_1:
    // 0x8003FAA4: j           L_8003FB20
    // 0x8003FAA8: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
        goto L_8003FB20;
    // 0x8003FAA8: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
L_8003FAAC:
    // 0x8003FAAC: sh          $zero, 0x34($sp)
    MEM_H(0X34, ctx->r29) = 0;
L_8003FAB0:
    // 0x8003FAB0: lbu         $v0, 0x19($s2)
    ctx->r2 = MEM_BU(ctx->r18, 0X19);
    // 0x8003FAB4: addiu       $s1, $v0, 0x1
    ctx->r17 = ADD32(ctx->r2, 0X1);
    // 0x8003FAB8: lui         $v0, 0x8004
    ctx->r2 = S32(0X8004 << 16);
    // 0x8003FABC: addiu       $s3, $v0, -0xE30
    ctx->r19 = ADD32(ctx->r2, -0XE30);
    // 0x8003FAC0: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8003FAC4: lw          $v0, 0xBC8($v0)
    ctx->r2 = MEM_W(ctx->r2, 0XBC8);
    // 0x8003FAC8: bgez        $v0, L_8003FB1C
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8003FACC: addiu       $s2, $sp, 0x20
        ctx->r18 = ADD32(ctx->r29, 0X20);
            goto L_8003FB1C;
    }
    // 0x8003FACC: addiu       $s2, $sp, 0x20
    ctx->r18 = ADD32(ctx->r29, 0X20);
    // 0x8003FAD0: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8003FAD4: lw          $v1, 0xBB0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0XBB0);
    // 0x8003FAD8: lhu         $a0, 0xE($v1)
    ctx->r4 = MEM_HU(ctx->r3, 0XE);
    // 0x8003FADC: ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
    // 0x8003FAE0: beq         $a0, $v0, L_8003FB1C
    if (ctx->r4 == ctx->r2) {
        // 0x8003FAE4: addu        $a1, $v1, $zero
        ctx->r5 = ADD32(ctx->r3, 0);
            goto L_8003FB1C;
    }
    // 0x8003FAE4: addu        $a1, $v1, $zero
    ctx->r5 = ADD32(ctx->r3, 0);
    // 0x8003FAE8: addu        $a2, $v0, $zero
    ctx->r6 = ADD32(ctx->r2, 0);
    // 0x8003FAEC: andi        $v1, $a0, 0xFFFF
    ctx->r3 = ctx->r4 & 0XFFFF;
L_8003FAF0:
    // 0x8003FAF0: sll         $v0, $v1, 3
    ctx->r2 = S32(ctx->r3 << 3);
    // 0x8003FAF4: addu        $a0, $v0, $a1
    ctx->r4 = ADD32(ctx->r2, ctx->r5);
    // 0x8003FAF8: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8003FAFC: beq         $v0, $zero, L_8003FB10
    if (ctx->r2 == 0) {
        // 0x8003FB00: nop
    
            goto L_8003FB10;
    }
    // 0x8003FB00: nop

    // 0x8003FB04: lbu         $v0, 0x1A($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X1A);
    // 0x8003FB08: beq         $v0, $zero, L_8003FA9C
    if (ctx->r2 == 0) {
        // 0x8003FB0C: nop
    
            goto L_8003FA9C;
    }
    // 0x8003FB0C: nop

L_8003FB10:
    // 0x8003FB10: lhu         $a0, 0x6($a0)
    ctx->r4 = MEM_HU(ctx->r4, 0X6);
    // 0x8003FB14: bne         $a0, $a2, L_8003FAF0
    if (ctx->r4 != ctx->r6) {
        // 0x8003FB18: andi        $v1, $a0, 0xFFFF
        ctx->r3 = ctx->r4 & 0XFFFF;
            goto L_8003FAF0;
    }
    // 0x8003FB18: andi        $v1, $a0, 0xFFFF
    ctx->r3 = ctx->r4 & 0XFFFF;
L_8003FB1C:
    // 0x8003FB1C: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
L_8003FB20:
    // 0x8003FB20: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8003FB24: lw          $v1, 0xBC8($a1)
    ctx->r3 = MEM_W(ctx->r5, 0XBC8);
    // 0x8003FB28: lw          $a0, 0xBBC($v0)
    ctx->r4 = MEM_W(ctx->r2, 0XBBC);
    // 0x8003FB2C: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x8003FB30: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x8003FB34: addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
    // 0x8003FB38: lw          $s0, 0x0($v0)
    ctx->r16 = MEM_W(ctx->r2, 0X0);
    // 0x8003FB3C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8003FB40: sw          $v1, 0xBC8($a1)
    MEM_W(0XBC8, ctx->r5) = ctx->r3;
    // 0x8003FB44: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x8003FB48: sw          $zero, 0x4($s0)
    MEM_W(0X4, ctx->r16) = 0;
    // 0x8003FB4C: sw          $zero, 0x8($s0)
    MEM_W(0X8, ctx->r16) = 0;
    // 0x8003FB50: sw          $zero, 0xC($s0)
    MEM_W(0XC, ctx->r16) = 0;
    // 0x8003FB54: sw          $s3, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r19;
    // 0x8003FB58: sw          $zero, 0x10($s0)
    MEM_W(0X10, ctx->r16) = 0;
    // 0x8003FB5C: sh          $v0, 0x14($s0)
    MEM_H(0X14, ctx->r16) = ctx->r2;
    // 0x8003FB60: sb          $zero, 0x1B($s0)
    MEM_B(0X1B, ctx->r16) = 0;
    // 0x8003FB64: sb          $zero, 0x1A($s0)
    MEM_B(0X1A, ctx->r16) = 0;
    // 0x8003FB68: jal         0x8003E5F8
    // 0x8003FB6C: sb          $s1, 0x19($s0)
    MEM_B(0X19, ctx->r16) = ctx->r17;
    func_8003E5F8(rdram, ctx);
        goto after_2;
    // 0x8003FB6C: sb          $s1, 0x19($s0)
    MEM_B(0X19, ctx->r16) = ctx->r17;
    after_2:
    // 0x8003FB70: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x8003FB74: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x8003FB78: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x8003FB7C: sh          $v0, 0x16($s0)
    MEM_H(0X16, ctx->r16) = ctx->r2;
    // 0x8003FB80: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x8003FB84: lw          $v1, 0xBB0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0XBB0);
    // 0x8003FB88: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x8003FB8C: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8003FB90: jal         0x8003E684
    // 0x8003FB94: sw          $s0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r16;
    func_8003E684(rdram, ctx);
        goto after_3;
    // 0x8003FB94: sw          $s0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r16;
    after_3:
    // 0x8003FB98: jal         0x8003EA4C
    // 0x8003FB9C: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_8003EA4C(rdram, ctx);
        goto after_4;
    // 0x8003FB9C: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_4:
    // 0x8003FBA0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8003FBA4: lhu         $a0, 0x16($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X16);
    // 0x8003FBA8: jal         0x8003E8DC
    // 0x8003FBAC: addu        $a2, $s2, $zero
    ctx->r6 = ADD32(ctx->r18, 0);
    func_8003E8DC(rdram, ctx);
        goto after_5;
    // 0x8003FBAC: addu        $a2, $s2, $zero
    ctx->r6 = ADD32(ctx->r18, 0);
    after_5:
    // 0x8003FBB0: lhu         $s0, 0x16($s0)
    ctx->r16 = MEM_HU(ctx->r16, 0X16);
    // 0x8003FBB4: ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
    // 0x8003FBB8: beq         $s0, $v0, L_8003FBD8
    if (ctx->r16 == ctx->r2) {
        // 0x8003FBBC: addu        $a0, $s0, $zero
        ctx->r4 = ADD32(ctx->r16, 0);
            goto L_8003FBD8;
    }
    // 0x8003FBBC: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x8003FBC0: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x8003FBC4: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8003FBC8: lwc1        $f0, -0x5BF4($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X5BF4);
    // 0x8003FBCC: addiu       $a2, $sp, 0x6C
    ctx->r6 = ADD32(ctx->r29, 0X6C);
    // 0x8003FBD0: jal         0x8003E8DC
    // 0x8003FBD4: swc1        $f0, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->f0.u32l;
    func_8003E8DC(rdram, ctx);
        goto after_6;
    // 0x8003FBD4: swc1        $f0, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->f0.u32l;
    after_6:
L_8003FBD8:
    // 0x8003FBD8: addu        $v0, $s0, $zero
    ctx->r2 = ADD32(ctx->r16, 0);
    // 0x8003FBDC: lw          $ra, 0x80($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X80);
    // 0x8003FBE0: lw          $s3, 0x7C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X7C);
    // 0x8003FBE4: lw          $s2, 0x78($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X78);
    // 0x8003FBE8: lw          $s1, 0x74($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X74);
    // 0x8003FBEC: lw          $s0, 0x70($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X70);
    // 0x8003FBF0: jr          $ra
    // 0x8003FBF4: addiu       $sp, $sp, 0x88
    ctx->r29 = ADD32(ctx->r29, 0X88);
    return;
    // 0x8003FBF4: addiu       $sp, $sp, 0x88
    ctx->r29 = ADD32(ctx->r29, 0X88);
;}
RECOMP_FUNC void func_8003FBF8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003FBF8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8003FBFC: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x8003FC00: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x8003FC04: lw          $a0, 0xBB0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0XBB0);
    // 0x8003FC08: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8003FC0C: jal         0x80001C98
    // 0x8003FC10: nop

    rs_free(rdram, ctx);
        goto after_0;
    // 0x8003FC10: nop

    after_0:
    // 0x8003FC14: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8003FC18: sw          $zero, 0xBB0($s0)
    MEM_W(0XBB0, ctx->r16) = 0;
    // 0x8003FC1C: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x8003FC20: jr          $ra
    // 0x8003FC24: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8003FC24: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_8003FC28(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003FC28: andi        $v1, $a0, 0xFFFF
    ctx->r3 = ctx->r4 & 0XFFFF;
    // 0x8003FC2C: ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
    // 0x8003FC30: beq         $v1, $v0, L_8003FCB4
    if (ctx->r3 == ctx->r2) {
        // 0x8003FC34: lui         $v0, 0x8013
        ctx->r2 = S32(0X8013 << 16);
            goto L_8003FCB4;
    }
    // 0x8003FC34: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8003FC38: lw          $a2, 0xBB0($v0)
    ctx->r6 = MEM_W(ctx->r2, 0XBB0);
    // 0x8003FC3C: ori         $a3, $zero, 0xFFFF
    ctx->r7 = 0 | 0XFFFF;
    // 0x8003FC40: andi        $v0, $a0, 0xFFFF
    ctx->r2 = ctx->r4 & 0XFFFF;
L_8003FC44:
    // 0x8003FC44: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x8003FC48: addu        $v1, $v0, $a2
    ctx->r3 = ADD32(ctx->r2, ctx->r6);
    // 0x8003FC4C: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8003FC50: beq         $v0, $zero, L_8003FCA8
    if (ctx->r2 == 0) {
        // 0x8003FC54: nop
    
            goto L_8003FCA8;
    }
    // 0x8003FC54: nop

    // 0x8003FC58: beq         $a1, $zero, L_8003FC90
    if (ctx->r5 == 0) {
        // 0x8003FC5C: andi        $v0, $a0, 0xFFFF
        ctx->r2 = ctx->r4 & 0XFFFF;
            goto L_8003FC90;
    }
    // 0x8003FC5C: andi        $v0, $a0, 0xFFFF
    ctx->r2 = ctx->r4 & 0XFFFF;
    // 0x8003FC60: sh          $a0, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r4;
    // 0x8003FC64: lhu         $v0, 0x4($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X4);
    // 0x8003FC68: sh          $v0, 0x2($a1)
    MEM_H(0X2, ctx->r5) = ctx->r2;
    // 0x8003FC6C: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x8003FC70: beql        $v0, $a3, L_8003FC8C
    if (ctx->r2 == ctx->r7) {
        // 0x8003FC74: sh          $a3, 0x4($a1)
        MEM_H(0X4, ctx->r5) = ctx->r7;
            goto L_8003FC8C;
    }
    goto skip_0;
    // 0x8003FC74: sh          $a3, 0x4($a1)
    MEM_H(0X4, ctx->r5) = ctx->r7;
    skip_0:
    // 0x8003FC78: lhu         $v0, 0x2($a1)
    ctx->r2 = MEM_HU(ctx->r5, 0X2);
    // 0x8003FC7C: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x8003FC80: addu        $v0, $v0, $a2
    ctx->r2 = ADD32(ctx->r2, ctx->r6);
    // 0x8003FC84: lhu         $v0, 0x4($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X4);
    // 0x8003FC88: sh          $v0, 0x4($a1)
    MEM_H(0X4, ctx->r5) = ctx->r2;
L_8003FC8C:
    // 0x8003FC8C: andi        $v0, $a0, 0xFFFF
    ctx->r2 = ctx->r4 & 0XFFFF;
L_8003FC90:
    // 0x8003FC90: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x8003FC94: addu        $v0, $v0, $a2
    ctx->r2 = ADD32(ctx->r2, ctx->r6);
    // 0x8003FC98: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x8003FC9C: lhu         $v0, 0x16($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X16);
    // 0x8003FCA0: jr          $ra
    // 0x8003FCA4: nop

    return;
    // 0x8003FCA4: nop

L_8003FCA8:
    // 0x8003FCA8: lhu         $a0, 0x4($v1)
    ctx->r4 = MEM_HU(ctx->r3, 0X4);
    // 0x8003FCAC: bne         $a0, $a3, L_8003FC44
    if (ctx->r4 != ctx->r7) {
        // 0x8003FCB0: andi        $v0, $a0, 0xFFFF
        ctx->r2 = ctx->r4 & 0XFFFF;
            goto L_8003FC44;
    }
    // 0x8003FCB0: andi        $v0, $a0, 0xFFFF
    ctx->r2 = ctx->r4 & 0XFFFF;
L_8003FCB4:
    // 0x8003FCB4: jr          $ra
    // 0x8003FCB8: ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
    return;
    // 0x8003FCB8: ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
;}
RECOMP_FUNC void func_8003FCBC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003FCBC: andi        $v1, $a0, 0xFFFF
    ctx->r3 = ctx->r4 & 0XFFFF;
    // 0x8003FCC0: ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
    // 0x8003FCC4: beq         $v1, $v0, L_8003FD4C
    if (ctx->r3 == ctx->r2) {
        // 0x8003FCC8: lui         $v0, 0x8013
        ctx->r2 = S32(0X8013 << 16);
            goto L_8003FD4C;
    }
    // 0x8003FCC8: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8003FCCC: lw          $a3, 0xBB0($v0)
    ctx->r7 = MEM_W(ctx->r2, 0XBB0);
    // 0x8003FCD0: ori         $t0, $zero, 0xFFFF
    ctx->r8 = 0 | 0XFFFF;
    // 0x8003FCD4: andi        $v0, $a0, 0xFFFF
    ctx->r2 = ctx->r4 & 0XFFFF;
L_8003FCD8:
    // 0x8003FCD8: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x8003FCDC: addu        $v1, $v0, $a3
    ctx->r3 = ADD32(ctx->r2, ctx->r7);
    // 0x8003FCE0: lw          $a2, 0x0($v1)
    ctx->r6 = MEM_W(ctx->r3, 0X0);
    // 0x8003FCE4: beq         $a2, $zero, L_8003FD38
    if (ctx->r6 == 0) {
        // 0x8003FCE8: andi        $v0, $a0, 0xFFFF
        ctx->r2 = ctx->r4 & 0XFFFF;
            goto L_8003FD38;
    }
    // 0x8003FCE8: andi        $v0, $a0, 0xFFFF
    ctx->r2 = ctx->r4 & 0XFFFF;
    // 0x8003FCEC: lw          $v0, 0x8($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X8);
    // 0x8003FCF0: beq         $v0, $zero, L_8003FD38
    if (ctx->r2 == 0) {
        // 0x8003FCF4: andi        $v0, $a0, 0xFFFF
        ctx->r2 = ctx->r4 & 0XFFFF;
            goto L_8003FD38;
    }
    // 0x8003FCF4: andi        $v0, $a0, 0xFFFF
    ctx->r2 = ctx->r4 & 0XFFFF;
    // 0x8003FCF8: beq         $a1, $zero, L_8003FD2C
    if (ctx->r5 == 0) {
        // 0x8003FCFC: nop
    
            goto L_8003FD2C;
    }
    // 0x8003FCFC: nop

    // 0x8003FD00: sh          $a0, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r4;
    // 0x8003FD04: lhu         $v0, 0x4($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X4);
    // 0x8003FD08: sh          $v0, 0x2($a1)
    MEM_H(0X2, ctx->r5) = ctx->r2;
    // 0x8003FD0C: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x8003FD10: beql        $v0, $t0, L_8003FD2C
    if (ctx->r2 == ctx->r8) {
        // 0x8003FD14: sh          $t0, 0x4($a1)
        MEM_H(0X4, ctx->r5) = ctx->r8;
            goto L_8003FD2C;
    }
    goto skip_0;
    // 0x8003FD14: sh          $t0, 0x4($a1)
    MEM_H(0X4, ctx->r5) = ctx->r8;
    skip_0:
    // 0x8003FD18: lhu         $v0, 0x2($a1)
    ctx->r2 = MEM_HU(ctx->r5, 0X2);
    // 0x8003FD1C: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x8003FD20: addu        $v0, $v0, $a3
    ctx->r2 = ADD32(ctx->r2, ctx->r7);
    // 0x8003FD24: lhu         $v0, 0x4($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X4);
    // 0x8003FD28: sh          $v0, 0x4($a1)
    MEM_H(0X4, ctx->r5) = ctx->r2;
L_8003FD2C:
    // 0x8003FD2C: lw          $v0, 0x8($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X8);
    // 0x8003FD30: jr          $ra
    // 0x8003FD34: nop

    return;
    // 0x8003FD34: nop

L_8003FD38:
    // 0x8003FD38: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x8003FD3C: addu        $v0, $v0, $a3
    ctx->r2 = ADD32(ctx->r2, ctx->r7);
    // 0x8003FD40: lhu         $a0, 0x4($v0)
    ctx->r4 = MEM_HU(ctx->r2, 0X4);
    // 0x8003FD44: bne         $a0, $t0, L_8003FCD8
    if (ctx->r4 != ctx->r8) {
        // 0x8003FD48: andi        $v0, $a0, 0xFFFF
        ctx->r2 = ctx->r4 & 0XFFFF;
            goto L_8003FCD8;
    }
    // 0x8003FD48: andi        $v0, $a0, 0xFFFF
    ctx->r2 = ctx->r4 & 0XFFFF;
L_8003FD4C:
    // 0x8003FD4C: jr          $ra
    // 0x8003FD50: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    return;
    // 0x8003FD50: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
;}
RECOMP_FUNC void func_8003FD54(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003FD54: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8003FD58: addiu       $a0, $zero, 0x2D00
    ctx->r4 = ADD32(0, 0X2D00);
    // 0x8003FD5C: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x8003FD60: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8003FD64: jal         0x80001ACC
    // 0x8003FD68: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    rs_malloc(rdram, ctx);
        goto after_0;
    // 0x8003FD68: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    after_0:
    // 0x8003FD6C: addiu       $a0, $zero, 0x300
    ctx->r4 = ADD32(0, 0X300);
    // 0x8003FD70: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x8003FD74: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x8003FD78: jal         0x80001ACC
    // 0x8003FD7C: sw          $v0, 0xBB8($s0)
    MEM_W(0XBB8, ctx->r16) = ctx->r2;
    rs_malloc(rdram, ctx);
        goto after_1;
    // 0x8003FD7C: sw          $v0, 0xBB8($s0)
    MEM_W(0XBB8, ctx->r16) = ctx->r2;
    after_1:
    // 0x8003FD80: addiu       $a2, $zero, 0xBF
    ctx->r6 = ADD32(0, 0XBF);
    // 0x8003FD84: addiu       $a1, $v0, 0x2FC
    ctx->r5 = ADD32(ctx->r2, 0X2FC);
    // 0x8003FD88: lw          $a0, 0xBB8($s0)
    ctx->r4 = MEM_W(ctx->r16, 0XBB8);
    // 0x8003FD8C: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x8003FD90: sw          $v0, 0xBBC($v1)
    MEM_W(0XBBC, ctx->r3) = ctx->r2;
    // 0x8003FD94: addiu       $a0, $a0, 0x2CC4
    ctx->r4 = ADD32(ctx->r4, 0X2CC4);
L_8003FD98:
    // 0x8003FD98: sw          $a0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r4;
    // 0x8003FD9C: addiu       $a1, $a1, -0x4
    ctx->r5 = ADD32(ctx->r5, -0X4);
    // 0x8003FDA0: addiu       $a2, $a2, -0x1
    ctx->r6 = ADD32(ctx->r6, -0X1);
    // 0x8003FDA4: bgez        $a2, L_8003FD98
    if (SIGNED(ctx->r6) >= 0) {
        // 0x8003FDA8: addiu       $a0, $a0, -0x3C
        ctx->r4 = ADD32(ctx->r4, -0X3C);
            goto L_8003FD98;
    }
    // 0x8003FDA8: addiu       $a0, $a0, -0x3C
    ctx->r4 = ADD32(ctx->r4, -0X3C);
    // 0x8003FDAC: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x8003FDB0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8003FDB4: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x8003FDB8: addiu       $v0, $zero, 0xBF
    ctx->r2 = ADD32(0, 0XBF);
    // 0x8003FDBC: sw          $v0, 0xBC8($v1)
    MEM_W(0XBC8, ctx->r3) = ctx->r2;
    // 0x8003FDC0: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8003FDC4: sw          $zero, 0xBC4($v0)
    MEM_W(0XBC4, ctx->r2) = 0;
    // 0x8003FDC8: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8003FDCC: sw          $zero, 0xBC0($v0)
    MEM_W(0XBC0, ctx->r2) = 0;
    // 0x8003FDD0: jr          $ra
    // 0x8003FDD4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8003FDD4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_8003FDD8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003FDD8: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x8003FDDC: lw          $v0, 0xBC8($v1)
    ctx->r2 = MEM_W(ctx->r3, 0XBC8);
    // 0x8003FDE0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8003FDE4: sw          $ra, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r31;
    // 0x8003FDE8: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x8003FDEC: slti        $v0, $v0, 0xBF
    ctx->r2 = SIGNED(ctx->r2) < 0XBF ? 1 : 0;
    // 0x8003FDF0: beq         $v0, $zero, L_8003FE14
    if (ctx->r2 == 0) {
        // 0x8003FDF4: sw          $s0, 0x10($sp)
        MEM_W(0X10, ctx->r29) = ctx->r16;
            goto L_8003FE14;
    }
    // 0x8003FDF4: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x8003FDF8: addu        $s0, $v1, $zero
    ctx->r16 = ADD32(ctx->r3, 0);
L_8003FDFC:
    // 0x8003FDFC: jal         0x8004028C
    // 0x8003FE00: nop

    func_8004028C(rdram, ctx);
        goto after_0;
    // 0x8003FE00: nop

    after_0:
    // 0x8003FE04: lw          $v0, 0xBC8($s0)
    ctx->r2 = MEM_W(ctx->r16, 0XBC8);
    // 0x8003FE08: slti        $v0, $v0, 0xBF
    ctx->r2 = SIGNED(ctx->r2) < 0XBF ? 1 : 0;
    // 0x8003FE0C: bne         $v0, $zero, L_8003FDFC
    if (ctx->r2 != 0) {
        // 0x8003FE10: nop
    
            goto L_8003FDFC;
    }
    // 0x8003FE10: nop

L_8003FE14:
    // 0x8003FE14: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8003FE18: lw          $a0, 0xBC0($v0)
    ctx->r4 = MEM_W(ctx->r2, 0XBC0);
    // 0x8003FE1C: beq         $a0, $zero, L_8003FE3C
    if (ctx->r4 == 0) {
        // 0x8003FE20: addu        $s0, $v0, $zero
        ctx->r16 = ADD32(ctx->r2, 0);
            goto L_8003FE3C;
    }
    // 0x8003FE20: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
L_8003FE24:
    // 0x8003FE24: lw          $v0, 0x48($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X48);
    // 0x8003FE28: jal         0x80001C98
    // 0x8003FE2C: sw          $v0, 0xBC0($s0)
    MEM_W(0XBC0, ctx->r16) = ctx->r2;
    rs_free(rdram, ctx);
        goto after_1;
    // 0x8003FE2C: sw          $v0, 0xBC0($s0)
    MEM_W(0XBC0, ctx->r16) = ctx->r2;
    after_1:
    // 0x8003FE30: lw          $a0, 0xBC0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0XBC0);
    // 0x8003FE34: bne         $a0, $zero, L_8003FE24
    if (ctx->r4 != 0) {
        // 0x8003FE38: nop
    
            goto L_8003FE24;
    }
    // 0x8003FE38: nop

L_8003FE3C:
    // 0x8003FE3C: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8003FE40: lw          $a0, 0xBC4($v0)
    ctx->r4 = MEM_W(ctx->r2, 0XBC4);
    // 0x8003FE44: beq         $a0, $zero, L_8003FE64
    if (ctx->r4 == 0) {
        // 0x8003FE48: addu        $s0, $v0, $zero
        ctx->r16 = ADD32(ctx->r2, 0);
            goto L_8003FE64;
    }
    // 0x8003FE48: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
L_8003FE4C:
    // 0x8003FE4C: lw          $v0, 0x48($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X48);
    // 0x8003FE50: jal         0x80001C98
    // 0x8003FE54: sw          $v0, 0xBC4($s0)
    MEM_W(0XBC4, ctx->r16) = ctx->r2;
    rs_free(rdram, ctx);
        goto after_2;
    // 0x8003FE54: sw          $v0, 0xBC4($s0)
    MEM_W(0XBC4, ctx->r16) = ctx->r2;
    after_2:
    // 0x8003FE58: lw          $a0, 0xBC4($s0)
    ctx->r4 = MEM_W(ctx->r16, 0XBC4);
    // 0x8003FE5C: bne         $a0, $zero, L_8003FE4C
    if (ctx->r4 != 0) {
        // 0x8003FE60: nop
    
            goto L_8003FE4C;
    }
    // 0x8003FE60: nop

L_8003FE64:
    // 0x8003FE64: lui         $s1, 0x8013
    ctx->r17 = S32(0X8013 << 16);
    // 0x8003FE68: lw          $a0, 0xBBC($s1)
    ctx->r4 = MEM_W(ctx->r17, 0XBBC);
    // 0x8003FE6C: jal         0x80001C98
    // 0x8003FE70: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    rs_free(rdram, ctx);
        goto after_3;
    // 0x8003FE70: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    after_3:
    // 0x8003FE74: lw          $a0, 0xBB8($s0)
    ctx->r4 = MEM_W(ctx->r16, 0XBB8);
    // 0x8003FE78: jal         0x80001C98
    // 0x8003FE7C: nop

    rs_free(rdram, ctx);
        goto after_4;
    // 0x8003FE7C: nop

    after_4:
    // 0x8003FE80: lw          $ra, 0x18($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X18);
    // 0x8003FE84: sw          $zero, 0xBBC($s1)
    MEM_W(0XBBC, ctx->r17) = 0;
    // 0x8003FE88: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x8003FE8C: sw          $zero, 0xBB8($s0)
    MEM_W(0XBB8, ctx->r16) = 0;
    // 0x8003FE90: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x8003FE94: jr          $ra
    // 0x8003FE98: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x8003FE98: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_8003FE9C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003FE9C: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8003FEA0: lw          $v0, 0xBC8($v0)
    ctx->r2 = MEM_W(ctx->r2, 0XBC8);
    // 0x8003FEA4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8003FEA8: sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // 0x8003FEAC: addu        $s2, $a0, $zero
    ctx->r18 = ADD32(ctx->r4, 0);
    // 0x8003FEB0: sw          $s4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r20;
    // 0x8003FEB4: addu        $s4, $a1, $zero
    ctx->r20 = ADD32(ctx->r5, 0);
    // 0x8003FEB8: sw          $s3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r19;
    // 0x8003FEBC: addu        $s3, $a2, $zero
    ctx->r19 = ADD32(ctx->r6, 0);
    // 0x8003FEC0: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x8003FEC4: addu        $s1, $a3, $zero
    ctx->r17 = ADD32(ctx->r7, 0);
    // 0x8003FEC8: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8003FECC: bgez        $v0, L_8003FF38
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8003FED0: sw          $s0, 0x10($sp)
        MEM_W(0X10, ctx->r29) = ctx->r16;
            goto L_8003FF38;
    }
    // 0x8003FED0: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x8003FED4: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x8003FED8: lw          $v0, 0xBB0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0XBB0);
    // 0x8003FEDC: lhu         $a1, 0xE($v0)
    ctx->r5 = MEM_HU(ctx->r2, 0XE);
    // 0x8003FEE0: ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
    // 0x8003FEE4: beq         $a1, $v0, L_8003FF38
    if (ctx->r5 == ctx->r2) {
        // 0x8003FEE8: addu        $a2, $v1, $zero
        ctx->r6 = ADD32(ctx->r3, 0);
            goto L_8003FF38;
    }
    // 0x8003FEE8: addu        $a2, $v1, $zero
    ctx->r6 = ADD32(ctx->r3, 0);
    // 0x8003FEEC: addu        $a3, $v0, $zero
    ctx->r7 = ADD32(ctx->r2, 0);
    // 0x8003FEF0: andi        $a0, $a1, 0xFFFF
    ctx->r4 = ctx->r5 & 0XFFFF;
L_8003FEF4:
    // 0x8003FEF4: lw          $v1, 0xBB0($a2)
    ctx->r3 = MEM_W(ctx->r6, 0XBB0);
    // 0x8003FEF8: sll         $v0, $a0, 3
    ctx->r2 = S32(ctx->r4 << 3);
    // 0x8003FEFC: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8003FF00: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x8003FF04: beql        $v0, $zero, L_8003FF28
    if (ctx->r2 == 0) {
        // 0x8003FF08: sll         $v0, $a1, 3
        ctx->r2 = S32(ctx->r5 << 3);
            goto L_8003FF28;
    }
    goto skip_0;
    // 0x8003FF08: sll         $v0, $a1, 3
    ctx->r2 = S32(ctx->r5 << 3);
    skip_0:
    // 0x8003FF0C: lbu         $v0, 0x1A($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X1A);
    // 0x8003FF10: bne         $v0, $zero, L_8003FF28
    if (ctx->r2 != 0) {
        // 0x8003FF14: sll         $v0, $a1, 3
        ctx->r2 = S32(ctx->r5 << 3);
            goto L_8003FF28;
    }
    // 0x8003FF14: sll         $v0, $a1, 3
    ctx->r2 = S32(ctx->r5 << 3);
    // 0x8003FF18: jal         0x8003ED74
    // 0x8003FF1C: nop

    func_8003ED74(rdram, ctx);
        goto after_0;
    // 0x8003FF1C: nop

    after_0:
    // 0x8003FF20: j           L_8003FF3C
    // 0x8003FF24: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
        goto L_8003FF3C;
    // 0x8003FF24: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
L_8003FF28:
    // 0x8003FF28: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8003FF2C: lhu         $a1, 0x6($v0)
    ctx->r5 = MEM_HU(ctx->r2, 0X6);
    // 0x8003FF30: bnel        $a1, $a3, L_8003FEF4
    if (ctx->r5 != ctx->r7) {
        // 0x8003FF34: andi        $a0, $a1, 0xFFFF
        ctx->r4 = ctx->r5 & 0XFFFF;
            goto L_8003FEF4;
    }
    goto skip_1;
    // 0x8003FF34: andi        $a0, $a1, 0xFFFF
    ctx->r4 = ctx->r5 & 0XFFFF;
    skip_1:
L_8003FF38:
    // 0x8003FF38: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
L_8003FF3C:
    // 0x8003FF3C: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8003FF40: lw          $v1, 0xBC8($a1)
    ctx->r3 = MEM_W(ctx->r5, 0XBC8);
    // 0x8003FF44: lw          $a0, 0xBBC($v0)
    ctx->r4 = MEM_W(ctx->r2, 0XBBC);
    // 0x8003FF48: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x8003FF4C: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x8003FF50: lw          $s0, 0x0($v0)
    ctx->r16 = MEM_W(ctx->r2, 0X0);
    // 0x8003FF54: addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
    // 0x8003FF58: sw          $v1, 0xBC8($a1)
    MEM_W(0XBC8, ctx->r5) = ctx->r3;
    // 0x8003FF5C: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x8003FF60: sw          $zero, 0x4($s0)
    MEM_W(0X4, ctx->r16) = 0;
    // 0x8003FF64: sw          $zero, 0x8($s0)
    MEM_W(0X8, ctx->r16) = 0;
    // 0x8003FF68: sw          $zero, 0xC($s0)
    MEM_W(0XC, ctx->r16) = 0;
    // 0x8003FF6C: sw          $s2, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r18;
    // 0x8003FF70: sw          $zero, 0x10($s0)
    MEM_W(0X10, ctx->r16) = 0;
    // 0x8003FF74: sh          $s3, 0x14($s0)
    MEM_H(0X14, ctx->r16) = ctx->r19;
    // 0x8003FF78: sb          $zero, 0x1B($s0)
    MEM_B(0X1B, ctx->r16) = 0;
    // 0x8003FF7C: sb          $zero, 0x1A($s0)
    MEM_B(0X1A, ctx->r16) = 0;
    // 0x8003FF80: jal         0x8003E5F8
    // 0x8003FF84: sb          $s1, 0x19($s0)
    MEM_B(0X19, ctx->r16) = ctx->r17;
    func_8003E5F8(rdram, ctx);
        goto after_1;
    // 0x8003FF84: sb          $s1, 0x19($s0)
    MEM_B(0X19, ctx->r16) = ctx->r17;
    after_1:
    // 0x8003FF88: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x8003FF8C: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x8003FF90: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x8003FF94: sh          $v0, 0x16($s0)
    MEM_H(0X16, ctx->r16) = ctx->r2;
    // 0x8003FF98: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x8003FF9C: lw          $v1, 0xBB0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0XBB0);
    // 0x8003FFA0: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x8003FFA4: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8003FFA8: jal         0x8003E684
    // 0x8003FFAC: sw          $s0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r16;
    func_8003E684(rdram, ctx);
        goto after_2;
    // 0x8003FFAC: sw          $s0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r16;
    after_2:
    // 0x8003FFB0: jal         0x8003EA4C
    // 0x8003FFB4: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_8003EA4C(rdram, ctx);
        goto after_3;
    // 0x8003FFB4: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_3:
    // 0x8003FFB8: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    // 0x8003FFBC: lhu         $a0, 0x16($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X16);
    // 0x8003FFC0: jal         0x8003E8DC
    // 0x8003FFC4: addu        $a2, $s4, $zero
    ctx->r6 = ADD32(ctx->r20, 0);
    func_8003E8DC(rdram, ctx);
        goto after_4;
    // 0x8003FFC4: addu        $a2, $s4, $zero
    ctx->r6 = ADD32(ctx->r20, 0);
    after_4:
    // 0x8003FFC8: lhu         $v0, 0x16($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X16);
    // 0x8003FFCC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8003FFD0: lw          $s4, 0x20($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X20);
    // 0x8003FFD4: lw          $s3, 0x1C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X1C);
    // 0x8003FFD8: lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X18);
    // 0x8003FFDC: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x8003FFE0: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x8003FFE4: jr          $ra
    // 0x8003FFE8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x8003FFE8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_8003FFEC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003FFEC: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8003FFF0: lw          $v0, 0xBC8($v0)
    ctx->r2 = MEM_W(ctx->r2, 0XBC8);
    // 0x8003FFF4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8003FFF8: sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // 0x8003FFFC: addu        $s2, $a0, $zero
    ctx->r18 = ADD32(ctx->r4, 0);
    // 0x80040000: sw          $s4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r20;
    // 0x80040004: addu        $s4, $a1, $zero
    ctx->r20 = ADD32(ctx->r5, 0);
    // 0x80040008: sw          $s3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r19;
    // 0x8004000C: addu        $s3, $a2, $zero
    ctx->r19 = ADD32(ctx->r6, 0);
    // 0x80040010: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x80040014: addu        $s1, $a3, $zero
    ctx->r17 = ADD32(ctx->r7, 0);
    // 0x80040018: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8004001C: bgez        $v0, L_80040088
    if (SIGNED(ctx->r2) >= 0) {
        // 0x80040020: sw          $s0, 0x10($sp)
        MEM_W(0X10, ctx->r29) = ctx->r16;
            goto L_80040088;
    }
    // 0x80040020: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x80040024: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x80040028: lw          $v0, 0xBB0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0XBB0);
    // 0x8004002C: lhu         $a1, 0xE($v0)
    ctx->r5 = MEM_HU(ctx->r2, 0XE);
    // 0x80040030: ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
    // 0x80040034: beq         $a1, $v0, L_80040088
    if (ctx->r5 == ctx->r2) {
        // 0x80040038: addu        $a2, $v1, $zero
        ctx->r6 = ADD32(ctx->r3, 0);
            goto L_80040088;
    }
    // 0x80040038: addu        $a2, $v1, $zero
    ctx->r6 = ADD32(ctx->r3, 0);
    // 0x8004003C: addu        $a3, $v0, $zero
    ctx->r7 = ADD32(ctx->r2, 0);
    // 0x80040040: andi        $a0, $a1, 0xFFFF
    ctx->r4 = ctx->r5 & 0XFFFF;
L_80040044:
    // 0x80040044: lw          $v1, 0xBB0($a2)
    ctx->r3 = MEM_W(ctx->r6, 0XBB0);
    // 0x80040048: sll         $v0, $a0, 3
    ctx->r2 = S32(ctx->r4 << 3);
    // 0x8004004C: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80040050: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x80040054: beql        $v0, $zero, L_80040078
    if (ctx->r2 == 0) {
        // 0x80040058: sll         $v0, $a1, 3
        ctx->r2 = S32(ctx->r5 << 3);
            goto L_80040078;
    }
    goto skip_0;
    // 0x80040058: sll         $v0, $a1, 3
    ctx->r2 = S32(ctx->r5 << 3);
    skip_0:
    // 0x8004005C: lbu         $v0, 0x1A($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X1A);
    // 0x80040060: bne         $v0, $zero, L_80040078
    if (ctx->r2 != 0) {
        // 0x80040064: sll         $v0, $a1, 3
        ctx->r2 = S32(ctx->r5 << 3);
            goto L_80040078;
    }
    // 0x80040064: sll         $v0, $a1, 3
    ctx->r2 = S32(ctx->r5 << 3);
    // 0x80040068: jal         0x8003ED74
    // 0x8004006C: nop

    func_8003ED74(rdram, ctx);
        goto after_0;
    // 0x8004006C: nop

    after_0:
    // 0x80040070: j           L_8004008C
    // 0x80040074: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
        goto L_8004008C;
    // 0x80040074: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
L_80040078:
    // 0x80040078: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8004007C: lhu         $a1, 0x6($v0)
    ctx->r5 = MEM_HU(ctx->r2, 0X6);
    // 0x80040080: bnel        $a1, $a3, L_80040044
    if (ctx->r5 != ctx->r7) {
        // 0x80040084: andi        $a0, $a1, 0xFFFF
        ctx->r4 = ctx->r5 & 0XFFFF;
            goto L_80040044;
    }
    goto skip_1;
    // 0x80040084: andi        $a0, $a1, 0xFFFF
    ctx->r4 = ctx->r5 & 0XFFFF;
    skip_1:
L_80040088:
    // 0x80040088: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
L_8004008C:
    // 0x8004008C: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80040090: lw          $v1, 0xBC8($a1)
    ctx->r3 = MEM_W(ctx->r5, 0XBC8);
    // 0x80040094: lw          $a0, 0xBBC($v0)
    ctx->r4 = MEM_W(ctx->r2, 0XBBC);
    // 0x80040098: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x8004009C: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x800400A0: lw          $s0, 0x0($v0)
    ctx->r16 = MEM_W(ctx->r2, 0X0);
    // 0x800400A4: addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
    // 0x800400A8: sw          $v1, 0xBC8($a1)
    MEM_W(0XBC8, ctx->r5) = ctx->r3;
    // 0x800400AC: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x800400B0: sw          $zero, 0x4($s0)
    MEM_W(0X4, ctx->r16) = 0;
    // 0x800400B4: sw          $zero, 0x8($s0)
    MEM_W(0X8, ctx->r16) = 0;
    // 0x800400B8: sw          $zero, 0xC($s0)
    MEM_W(0XC, ctx->r16) = 0;
    // 0x800400BC: sw          $s2, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r18;
    // 0x800400C0: sw          $zero, 0x10($s0)
    MEM_W(0X10, ctx->r16) = 0;
    // 0x800400C4: sh          $s3, 0x14($s0)
    MEM_H(0X14, ctx->r16) = ctx->r19;
    // 0x800400C8: sb          $zero, 0x1B($s0)
    MEM_B(0X1B, ctx->r16) = 0;
    // 0x800400CC: sb          $zero, 0x1A($s0)
    MEM_B(0X1A, ctx->r16) = 0;
    // 0x800400D0: jal         0x8003E5F8
    // 0x800400D4: sb          $s1, 0x19($s0)
    MEM_B(0X19, ctx->r16) = ctx->r17;
    func_8003E5F8(rdram, ctx);
        goto after_1;
    // 0x800400D4: sb          $s1, 0x19($s0)
    MEM_B(0X19, ctx->r16) = ctx->r17;
    after_1:
    // 0x800400D8: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x800400DC: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x800400E0: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x800400E4: sh          $v0, 0x16($s0)
    MEM_H(0X16, ctx->r16) = ctx->r2;
    // 0x800400E8: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x800400EC: lw          $v1, 0xBB0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0XBB0);
    // 0x800400F0: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x800400F4: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800400F8: jal         0x8003E684
    // 0x800400FC: sw          $s0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r16;
    func_8003E684(rdram, ctx);
        goto after_2;
    // 0x800400FC: sw          $s0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r16;
    after_2:
    // 0x80040100: jal         0x8003EA4C
    // 0x80040104: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_8003EA4C(rdram, ctx);
        goto after_3;
    // 0x80040104: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_3:
    // 0x80040108: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8004010C: lhu         $a0, 0x16($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X16);
    // 0x80040110: jal         0x8003E8DC
    // 0x80040114: addu        $a2, $s4, $zero
    ctx->r6 = ADD32(ctx->r20, 0);
    func_8003E8DC(rdram, ctx);
        goto after_4;
    // 0x80040114: addu        $a2, $s4, $zero
    ctx->r6 = ADD32(ctx->r20, 0);
    after_4:
    // 0x80040118: lhu         $v0, 0x16($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X16);
    // 0x8004011C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80040120: lw          $s4, 0x20($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X20);
    // 0x80040124: lw          $s3, 0x1C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X1C);
    // 0x80040128: lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X18);
    // 0x8004012C: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x80040130: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x80040134: jr          $ra
    // 0x80040138: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80040138: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_8004013C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8004013C: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    // 0x80040140: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80040144: lw          $v0, 0xBB0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0XBB0);
    // 0x80040148: sll         $a0, $a0, 3
    ctx->r4 = S32(ctx->r4 << 3);
    // 0x8004014C: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // 0x80040150: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x80040154: jr          $ra
    // 0x80040158: nop

    return;
    // 0x80040158: nop

;}
RECOMP_FUNC void func_8004015C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8004015C: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    // 0x80040160: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80040164: lw          $v0, 0xBB0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0XBB0);
    // 0x80040168: sll         $a0, $a0, 3
    ctx->r4 = S32(ctx->r4 << 3);
    // 0x8004016C: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // 0x80040170: lw          $a0, 0x0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X0);
    // 0x80040174: beq         $a0, $zero, L_80040180
    if (ctx->r4 == 0) {
        // 0x80040178: addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
            goto L_80040180;
    }
    // 0x80040178: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // 0x8004017C: lw          $v0, 0x8($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X8);
L_80040180:
    // 0x80040180: jr          $ra
    // 0x80040184: nop

    return;
    // 0x80040184: nop

;}
RECOMP_FUNC void func_80040188(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80040188: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8004018C: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x80040190: ori         $s0, $zero, 0xFFFF
    ctx->r16 = 0 | 0XFFFF;
    // 0x80040194: andi        $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 & 0XFFFF;
    // 0x80040198: sw          $s3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r19;
    // 0x8004019C: ori         $s3, $zero, 0xFFFF
    ctx->r19 = 0 | 0XFFFF;
    // 0x800401A0: sw          $ra, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r31;
    // 0x800401A4: sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // 0x800401A8: beq         $a1, $s3, L_800401F8
    if (ctx->r5 == ctx->r19) {
        // 0x800401AC: sw          $s1, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r17;
            goto L_800401F8;
    }
    // 0x800401AC: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x800401B0: lui         $s2, 0x8013
    ctx->r18 = S32(0X8013 << 16);
    // 0x800401B4: lw          $v0, 0xBB0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0XBB0);
    // 0x800401B8: sll         $s1, $a1, 3
    ctx->r17 = S32(ctx->r5 << 3);
    // 0x800401BC: addu        $v0, $s1, $v0
    ctx->r2 = ADD32(ctx->r17, ctx->r2);
    // 0x800401C0: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x800401C4: beq         $v0, $zero, L_800401FC
    if (ctx->r2 == 0) {
        // 0x800401C8: andi        $v0, $s0, 0xFFFF
        ctx->r2 = ctx->r16 & 0XFFFF;
            goto L_800401FC;
    }
    // 0x800401C8: andi        $v0, $s0, 0xFFFF
    ctx->r2 = ctx->r16 & 0XFFFF;
    // 0x800401CC: jal         0x8003E5F8
    // 0x800401D0: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    func_8003E5F8(rdram, ctx);
        goto after_0;
    // 0x800401D0: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    after_0:
    // 0x800401D4: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    // 0x800401D8: andi        $a0, $s0, 0xFFFF
    ctx->r4 = ctx->r16 & 0XFFFF;
    // 0x800401DC: beq         $a0, $s3, L_800401FC
    if (ctx->r4 == ctx->r19) {
        // 0x800401E0: andi        $v0, $s0, 0xFFFF
        ctx->r2 = ctx->r16 & 0XFFFF;
            goto L_800401FC;
    }
    // 0x800401E0: andi        $v0, $s0, 0xFFFF
    ctx->r2 = ctx->r16 & 0XFFFF;
    // 0x800401E4: lw          $v0, 0xBB0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0XBB0);
    // 0x800401E8: addu        $v0, $s1, $v0
    ctx->r2 = ADD32(ctx->r17, ctx->r2);
    // 0x800401EC: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    // 0x800401F0: jal         0x8003E684
    // 0x800401F4: nop

    func_8003E684(rdram, ctx);
        goto after_1;
    // 0x800401F4: nop

    after_1:
L_800401F8:
    // 0x800401F8: andi        $v0, $s0, 0xFFFF
    ctx->r2 = ctx->r16 & 0XFFFF;
L_800401FC:
    // 0x800401FC: lw          $ra, 0x20($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X20);
    // 0x80040200: lw          $s3, 0x1C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X1C);
    // 0x80040204: lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X18);
    // 0x80040208: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x8004020C: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x80040210: jr          $ra
    // 0x80040214: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80040214: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_80040218(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80040218: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    // 0x8004021C: ori         $a2, $zero, 0xFFFF
    ctx->r6 = 0 | 0XFFFF;
    // 0x80040220: beq         $a0, $a2, L_80040240
    if (ctx->r4 == ctx->r6) {
        // 0x80040224: lui         $v0, 0x8013
        ctx->r2 = S32(0X8013 << 16);
            goto L_80040240;
    }
    // 0x80040224: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80040228: lw          $a1, 0xBB0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0XBB0);
    // 0x8004022C: sll         $v0, $a0, 3
    ctx->r2 = S32(ctx->r4 << 3);
    // 0x80040230: addu        $v1, $v0, $a1
    ctx->r3 = ADD32(ctx->r2, ctx->r5);
    // 0x80040234: lhu         $v0, 0x4($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X4);
    // 0x80040238: bne         $v0, $a2, L_80040248
    if (ctx->r2 != ctx->r6) {
        // 0x8004023C: sll         $v0, $v0, 3
        ctx->r2 = S32(ctx->r2 << 3);
            goto L_80040248;
    }
    // 0x8004023C: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
L_80040240:
    // 0x80040240: jr          $ra
    // 0x80040244: ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
    return;
    // 0x80040244: ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
L_80040248:
    // 0x80040248: addu        $v0, $v0, $a1
    ctx->r2 = ADD32(ctx->r2, ctx->r5);
    // 0x8004024C: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x80040250: lhu         $v0, 0x16($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X16);
    // 0x80040254: jr          $ra
    // 0x80040258: nop

    return;
    // 0x80040258: nop

;}
RECOMP_FUNC void func_8004025C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8004025C: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    // 0x80040260: ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
    // 0x80040264: beq         $a0, $v0, L_80040284
    if (ctx->r4 == ctx->r2) {
        // 0x80040268: lui         $v0, 0x8013
        ctx->r2 = S32(0X8013 << 16);
            goto L_80040284;
    }
    // 0x80040268: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8004026C: lw          $v1, 0xBB0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0XBB0);
    // 0x80040270: sll         $v0, $a0, 3
    ctx->r2 = S32(ctx->r4 << 3);
    // 0x80040274: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80040278: lhu         $v0, 0x4($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X4);
    // 0x8004027C: jr          $ra
    // 0x80040280: nop

    return;
    // 0x80040280: nop

L_80040284:
    // 0x80040284: jr          $ra
    // 0x80040288: ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
    return;
    // 0x80040288: ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
;}
RECOMP_FUNC void func_8004028C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8004028C: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x80040290: lw          $v0, 0xBB0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0XBB0);
    // 0x80040294: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80040298: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x8004029C: lhu         $a1, 0xE($v0)
    ctx->r5 = MEM_HU(ctx->r2, 0XE);
    // 0x800402A0: ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
    // 0x800402A4: beq         $a1, $v0, L_800402F8
    if (ctx->r5 == ctx->r2) {
        // 0x800402A8: andi        $a0, $a1, 0xFFFF
        ctx->r4 = ctx->r5 & 0XFFFF;
            goto L_800402F8;
    }
    // 0x800402A8: andi        $a0, $a1, 0xFFFF
    ctx->r4 = ctx->r5 & 0XFFFF;
    // 0x800402AC: addu        $a2, $v1, $zero
    ctx->r6 = ADD32(ctx->r3, 0);
    // 0x800402B0: addu        $a3, $v0, $zero
    ctx->r7 = ADD32(ctx->r2, 0);
L_800402B4:
    // 0x800402B4: lw          $v1, 0xBB0($a2)
    ctx->r3 = MEM_W(ctx->r6, 0XBB0);
    // 0x800402B8: sll         $v0, $a0, 3
    ctx->r2 = S32(ctx->r4 << 3);
    // 0x800402BC: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800402C0: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x800402C4: beql        $v0, $zero, L_800402E8
    if (ctx->r2 == 0) {
        // 0x800402C8: sll         $v0, $a1, 3
        ctx->r2 = S32(ctx->r5 << 3);
            goto L_800402E8;
    }
    goto skip_0;
    // 0x800402C8: sll         $v0, $a1, 3
    ctx->r2 = S32(ctx->r5 << 3);
    skip_0:
    // 0x800402CC: lbu         $v0, 0x1A($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X1A);
    // 0x800402D0: bne         $v0, $zero, L_800402E8
    if (ctx->r2 != 0) {
        // 0x800402D4: sll         $v0, $a1, 3
        ctx->r2 = S32(ctx->r5 << 3);
            goto L_800402E8;
    }
    // 0x800402D4: sll         $v0, $a1, 3
    ctx->r2 = S32(ctx->r5 << 3);
    // 0x800402D8: jal         0x8003ED74
    // 0x800402DC: nop

    func_8003ED74(rdram, ctx);
        goto after_0;
    // 0x800402DC: nop

    after_0:
    // 0x800402E0: j           L_800402F8
    // 0x800402E4: nop

        goto L_800402F8;
    // 0x800402E4: nop

L_800402E8:
    // 0x800402E8: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800402EC: lhu         $a1, 0x6($v0)
    ctx->r5 = MEM_HU(ctx->r2, 0X6);
    // 0x800402F0: bne         $a1, $a3, L_800402B4
    if (ctx->r5 != ctx->r7) {
        // 0x800402F4: andi        $a0, $a1, 0xFFFF
        ctx->r4 = ctx->r5 & 0XFFFF;
            goto L_800402B4;
    }
    // 0x800402F4: andi        $a0, $a1, 0xFFFF
    ctx->r4 = ctx->r5 & 0XFFFF;
L_800402F8:
    // 0x800402F8: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x800402FC: jr          $ra
    // 0x80040300: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80040300: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void fake_func_80040304(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
;}
RECOMP_FUNC void func_80040310(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80040310: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80040314: addiu       $a0, $zero, 0x3600
    ctx->r4 = ADD32(0, 0X3600);
    // 0x80040318: sw          $ra, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r31;
    // 0x8004031C: jal         0x80001ACC
    // 0x80040320: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    rs_malloc(rdram, ctx);
        goto after_0;
    // 0x80040320: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    after_0:
    // 0x80040324: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x80040328: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x8004032C: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    // 0x80040330: addiu       $a2, $zero, 0x7F
    ctx->r6 = ADD32(0, 0X7F);
    // 0x80040334: sw          $v0, 0xBD0($v1)
    MEM_W(0XBD0, ctx->r3) = ctx->r2;
    // 0x80040338: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
L_8004033C:
    // 0x8004033C: beq         $a0, $zero, L_8004034C
    if (ctx->r4 == 0) {
        // 0x80040340: addiu       $v0, $a0, -0x1
        ctx->r2 = ADD32(ctx->r4, -0X1);
            goto L_8004034C;
    }
    // 0x80040340: addiu       $v0, $a0, -0x1
    ctx->r2 = ADD32(ctx->r4, -0X1);
    // 0x80040344: j           L_80040350
    // 0x80040348: sh          $v0, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r2;
        goto L_80040350;
    // 0x80040348: sh          $v0, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r2;
L_8004034C:
    // 0x8004034C: sh          $a1, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r5;
L_80040350:
    // 0x80040350: beq         $a0, $a2, L_80040360
    if (ctx->r4 == ctx->r6) {
        // 0x80040354: addiu       $v0, $a0, 0x1
        ctx->r2 = ADD32(ctx->r4, 0X1);
            goto L_80040360;
    }
    // 0x80040354: addiu       $v0, $a0, 0x1
    ctx->r2 = ADD32(ctx->r4, 0X1);
    // 0x80040358: j           L_80040364
    // 0x8004035C: sh          $v0, 0x2($v1)
    MEM_H(0X2, ctx->r3) = ctx->r2;
        goto L_80040364;
    // 0x8004035C: sh          $v0, 0x2($v1)
    MEM_H(0X2, ctx->r3) = ctx->r2;
L_80040360:
    // 0x80040360: sh          $a1, 0x2($v1)
    MEM_H(0X2, ctx->r3) = ctx->r5;
L_80040364:
    // 0x80040364: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x80040368: slti        $v0, $a0, 0x80
    ctx->r2 = SIGNED(ctx->r4) < 0X80 ? 1 : 0;
    // 0x8004036C: bne         $v0, $zero, L_8004033C
    if (ctx->r2 != 0) {
        // 0x80040370: addiu       $v1, $v1, 0x6C
        ctx->r3 = ADD32(ctx->r3, 0X6C);
            goto L_8004033C;
    }
    // 0x80040370: addiu       $v1, $v1, 0x6C
    ctx->r3 = ADD32(ctx->r3, 0X6C);
    // 0x80040374: lui         $a0, 0x8004
    ctx->r4 = S32(0X8004 << 16);
    // 0x80040378: addiu       $a0, $a0, -0x5BF0
    ctx->r4 = ADD32(ctx->r4, -0X5BF0);
    // 0x8004037C: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x80040380: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80040384: addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    // 0x80040388: addu        $a3, $a1, $zero
    ctx->r7 = ADD32(ctx->r5, 0);
    // 0x8004038C: sh          $zero, 0xBD4($v0)
    MEM_H(0XBD4, ctx->r2) = 0;
    // 0x80040390: jal         0x80054EF0
    // 0x80040394: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    func_80054EF0(rdram, ctx);
        goto after_1;
    // 0x80040394: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_1:
    // 0x80040398: lui         $a0, 0x8004
    ctx->r4 = S32(0X8004 << 16);
    // 0x8004039C: addiu       $a0, $a0, -0x5BE4
    ctx->r4 = ADD32(ctx->r4, -0X5BE4);
    // 0x800403A0: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x800403A4: jal         0x8006488C
    // 0x800403A8: sw          $v0, 0xC08($v1)
    MEM_W(0XC08, ctx->r3) = ctx->r2;
    load_asset(rdram, ctx);
        goto after_2;
    // 0x800403A8: sw          $v0, 0xC08($v1)
    MEM_W(0XC08, ctx->r3) = ctx->r2;
    after_2:
    // 0x800403AC: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x800403B0: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x800403B4: addu        $a1, $v1, $zero
    ctx->r5 = ADD32(ctx->r3, 0);
    // 0x800403B8: sw          $v0, 0xC04($a1)
    MEM_W(0XC04, ctx->r5) = ctx->r2;
L_800403BC:
    // 0x800403BC: lw          $v1, 0xC04($a1)
    ctx->r3 = MEM_W(ctx->r5, 0XC04);
    // 0x800403C0: sll         $v0, $a0, 2
    ctx->r2 = S32(ctx->r4 << 2);
    // 0x800403C4: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800403C8: lbu         $v1, 0x200($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X200);
    // 0x800403CC: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x800403D0: sb          $v1, 0x3($v0)
    MEM_B(0X3, ctx->r2) = ctx->r3;
    // 0x800403D4: slti        $v0, $a0, 0x80
    ctx->r2 = SIGNED(ctx->r4) < 0X80 ? 1 : 0;
    // 0x800403D8: bne         $v0, $zero, L_800403BC
    if (ctx->r2 != 0) {
        // 0x800403DC: nop
    
            goto L_800403BC;
    }
    // 0x800403DC: nop

    // 0x800403E0: lw          $ra, 0x18($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X18);
    // 0x800403E4: jr          $ra
    // 0x800403E8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x800403E8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_800403EC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800403EC: addiu       $sp, $sp, -0x98
    ctx->r29 = ADD32(ctx->r29, -0X98);
    // 0x800403F0: sw          $s2, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r18;
    // 0x800403F4: addu        $s2, $a0, $zero
    ctx->r18 = ADD32(ctx->r4, 0);
    // 0x800403F8: sw          $s0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r16;
    // 0x800403FC: andi        $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 & 0XFFFF;
    // 0x80040400: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x80040404: sw          $ra, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r31;
    // 0x80040408: sw          $s3, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r19;
    // 0x8004040C: sw          $s1, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r17;
    // 0x80040410: sdc1        $f24, 0x90($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X90, ctx->r29);
    // 0x80040414: sdc1        $f22, 0x88($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X88, ctx->r29);
    // 0x80040418: sdc1        $f20, 0x80($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X80, ctx->r29);
    // 0x8004041C: lw          $s1, 0x4($s2)
    ctx->r17 = MEM_W(ctx->r18, 0X4);
    // 0x80040420: beq         $a1, $v0, L_80040574
    if (ctx->r5 == ctx->r2) {
        // 0x80040424: addu        $s0, $a2, $zero
        ctx->r16 = ADD32(ctx->r6, 0);
            goto L_80040574;
    }
    // 0x80040424: addu        $s0, $a2, $zero
    ctx->r16 = ADD32(ctx->r6, 0);
    // 0x80040428: slti        $v0, $a1, 0x4
    ctx->r2 = SIGNED(ctx->r5) < 0X4 ? 1 : 0;
    // 0x8004042C: beq         $v0, $zero, L_8004044C
    if (ctx->r2 == 0) {
        // 0x80040430: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_8004044C;
    }
    // 0x80040430: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80040434: beq         $a1, $v0, L_80040468
    if (ctx->r5 == ctx->r2) {
        // 0x80040438: addiu       $v0, $zero, 0x2
        ctx->r2 = ADD32(0, 0X2);
            goto L_80040468;
    }
    // 0x80040438: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x8004043C: beq         $a1, $v0, L_80040528
    if (ctx->r5 == ctx->r2) {
        // 0x80040440: nop
    
            goto L_80040528;
    }
    // 0x80040440: nop

    // 0x80040444: j           L_80040978
    // 0x80040448: nop

        goto L_80040978;
    // 0x80040448: nop

L_8004044C:
    // 0x8004044C: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // 0x80040450: beq         $a1, $v0, L_80040638
    if (ctx->r5 == ctx->r2) {
        // 0x80040454: addiu       $v0, $zero, 0x1000
        ctx->r2 = ADD32(0, 0X1000);
            goto L_80040638;
    }
    // 0x80040454: addiu       $v0, $zero, 0x1000
    ctx->r2 = ADD32(0, 0X1000);
    // 0x80040458: beql        $a1, $v0, L_80040978
    if (ctx->r5 == ctx->r2) {
        // 0x8004045C: sw          $s1, 0x0($s0)
        MEM_W(0X0, ctx->r16) = ctx->r17;
            goto L_80040978;
    }
    goto skip_0;
    // 0x8004045C: sw          $s1, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r17;
    skip_0:
    // 0x80040460: j           L_80040978
    // 0x80040464: nop

        goto L_80040978;
    // 0x80040464: nop

L_80040468:
    // 0x80040468: addiu       $a0, $zero, 0x164
    ctx->r4 = ADD32(0, 0X164);
    // 0x8004046C: jal         0x80001ACC
    // 0x80040470: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    rs_malloc(rdram, ctx);
        goto after_0;
    // 0x80040470: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    after_0:
    // 0x80040474: addu        $s1, $v0, $zero
    ctx->r17 = ADD32(ctx->r2, 0);
    // 0x80040478: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x8004047C: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x80040480: addiu       $a2, $zero, 0x80
    ctx->r6 = ADD32(0, 0X80);
    // 0x80040484: jal         0x80018EF4
    // 0x80040488: sw          $s1, 0x4($s2)
    MEM_W(0X4, ctx->r18) = ctx->r17;
    zmemcpy(rdram, ctx);
        goto after_1;
    // 0x80040488: sw          $s1, 0x4($s2)
    MEM_W(0X4, ctx->r18) = ctx->r17;
    after_1:
    // 0x8004048C: addiu       $a0, $s1, 0xCC
    ctx->r4 = ADD32(ctx->r17, 0XCC);
    // 0x80040490: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80040494: ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
    // 0x80040498: sh          $v0, 0x130($s1)
    MEM_H(0X130, ctx->r17) = ctx->r2;
    // 0x8004049C: sh          $v0, 0x140($s1)
    MEM_H(0X140, ctx->r17) = ctx->r2;
    // 0x800404A0: lw          $v0, 0x78($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X78);
    // 0x800404A4: lui         $v1, 0x4000
    ctx->r3 = S32(0X4000 << 16);
    // 0x800404A8: sw          $zero, 0x128($s1)
    MEM_W(0X128, ctx->r17) = 0;
    // 0x800404AC: sw          $zero, 0x12C($s1)
    MEM_W(0X12C, ctx->r17) = 0;
    // 0x800404B0: sw          $zero, 0x134($s1)
    MEM_W(0X134, ctx->r17) = 0;
    // 0x800404B4: sb          $zero, 0x160($s1)
    MEM_B(0X160, ctx->r17) = 0;
    // 0x800404B8: sw          $zero, 0x8C($s1)
    MEM_W(0X8C, ctx->r17) = 0;
    // 0x800404BC: sw          $zero, 0x88($s1)
    MEM_W(0X88, ctx->r17) = 0;
    // 0x800404C0: sw          $zero, 0x84($s1)
    MEM_W(0X84, ctx->r17) = 0;
    // 0x800404C4: sw          $zero, 0x80($s1)
    MEM_W(0X80, ctx->r17) = 0;
    // 0x800404C8: sw          $a0, 0x90($s1)
    MEM_W(0X90, ctx->r17) = ctx->r4;
    // 0x800404CC: sw          $zero, 0x94($s1)
    MEM_W(0X94, ctx->r17) = 0;
    // 0x800404D0: sw          $zero, 0xD4($s1)
    MEM_W(0XD4, ctx->r17) = 0;
    // 0x800404D4: sw          $zero, 0xD0($s1)
    MEM_W(0XD0, ctx->r17) = 0;
    // 0x800404D8: sw          $zero, 0xCC($s1)
    MEM_W(0XCC, ctx->r17) = 0;
    // 0x800404DC: sw          $zero, 0xDC($s1)
    MEM_W(0XDC, ctx->r17) = 0;
    // 0x800404E0: sw          $zero, 0xE4($s1)
    MEM_W(0XE4, ctx->r17) = 0;
    // 0x800404E4: sw          $zero, 0xE0($s1)
    MEM_W(0XE0, ctx->r17) = 0;
    // 0x800404E8: sw          $zero, 0xEC($s1)
    MEM_W(0XEC, ctx->r17) = 0;
    // 0x800404EC: or          $v0, $v0, $v1
    ctx->r2 = ctx->r2 | ctx->r3;
    // 0x800404F0: swc1        $f0, 0x14C($s1)
    MEM_W(0X14C, ctx->r17) = ctx->f0.u32l;
    // 0x800404F4: swc1        $f0, 0x148($s1)
    MEM_W(0X148, ctx->r17) = ctx->f0.u32l;
    // 0x800404F8: swc1        $f0, 0x144($s1)
    MEM_W(0X144, ctx->r17) = ctx->f0.u32l;
    // 0x800404FC: swc1        $f0, 0x158($s1)
    MEM_W(0X158, ctx->r17) = ctx->f0.u32l;
    // 0x80040500: swc1        $f0, 0x154($s1)
    MEM_W(0X154, ctx->r17) = ctx->f0.u32l;
    // 0x80040504: swc1        $f0, 0x150($s1)
    MEM_W(0X150, ctx->r17) = ctx->f0.u32l;
    // 0x80040508: jal         0x8000A85C
    // 0x8004050C: sw          $v0, 0xD8($s1)
    MEM_W(0XD8, ctx->r17) = ctx->r2;
    func_8000A85C(rdram, ctx);
        goto after_2;
    // 0x8004050C: sw          $v0, 0xD8($s1)
    MEM_W(0XD8, ctx->r17) = ctx->r2;
    after_2:
    // 0x80040510: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x80040514: lhu         $a0, -0x6A8C($v0)
    ctx->r4 = MEM_HU(ctx->r2, -0X6A8C);
    // 0x80040518: jal         0x8003E684
    // 0x8004051C: addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    func_8003E684(rdram, ctx);
        goto after_3;
    // 0x8004051C: addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    after_3:
    // 0x80040520: j           L_80040978
    // 0x80040524: nop

        goto L_80040978;
    // 0x80040524: nop

L_80040528:
    // 0x80040528: lhu         $a0, 0x140($s1)
    ctx->r4 = MEM_HU(ctx->r17, 0X140);
    // 0x8004052C: jal         0x8003F0C8
    // 0x80040530: nop

    func_8003F0C8(rdram, ctx);
        goto after_4;
    // 0x80040530: nop

    after_4:
    // 0x80040534: lhu         $v1, 0x130($s1)
    ctx->r3 = MEM_HU(ctx->r17, 0X130);
    // 0x80040538: ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
    // 0x8004053C: beq         $v1, $v0, L_80040978
    if (ctx->r3 == ctx->r2) {
        // 0x80040540: addu        $a0, $s1, $zero
        ctx->r4 = ADD32(ctx->r17, 0);
            goto L_80040978;
    }
    // 0x80040540: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x80040544: addiu       $a2, $sp, 0x18
    ctx->r6 = ADD32(ctx->r29, 0X18);
    // 0x80040548: lui         $a1, 0x461C
    ctx->r5 = S32(0X461C << 16);
    // 0x8004054C: ori         $a1, $a1, 0x4000
    ctx->r5 = ctx->r5 | 0X4000;
    // 0x80040550: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80040554: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    // 0x80040558: swc1        $f0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f0.u32l;
    // 0x8004055C: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    // 0x80040560: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    // 0x80040564: jal         0x8004118C
    // 0x80040568: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    func_8004118C(rdram, ctx);
        goto after_5;
    // 0x80040568: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_5:
    // 0x8004056C: j           L_80040978
    // 0x80040570: nop

        goto L_80040978;
    // 0x80040570: nop

L_80040574:
    // 0x80040574: lbu         $v0, 0x160($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X160);
    // 0x80040578: beq         $v0, $zero, L_800405A0
    if (ctx->r2 == 0) {
        // 0x8004057C: ori         $v0, $zero, 0xFFFF
        ctx->r2 = 0 | 0XFFFF;
            goto L_800405A0;
    }
    // 0x8004057C: ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
    // 0x80040580: lhu         $v1, 0x130($s1)
    ctx->r3 = MEM_HU(ctx->r17, 0X130);
    // 0x80040584: bne         $v1, $v0, L_80040624
    if (ctx->r3 != ctx->r2) {
        // 0x80040588: sw          $zero, 0x128($s1)
        MEM_W(0X128, ctx->r17) = 0;
            goto L_80040624;
    }
    // 0x80040588: sw          $zero, 0x128($s1)
    MEM_W(0X128, ctx->r17) = 0;
    // 0x8004058C: lhu         $a0, 0x16($s2)
    ctx->r4 = MEM_HU(ctx->r18, 0X16);
    // 0x80040590: jal         0x8003ED74
    // 0x80040594: nop

    func_8003ED74(rdram, ctx);
        goto after_6;
    // 0x80040594: nop

    after_6:
    // 0x80040598: j           L_80040624
    // 0x8004059C: nop

        goto L_80040624;
    // 0x8004059C: nop

L_800405A0:
    // 0x800405A0: jal         0x80003430
    // 0x800405A4: nop

    rand_recomp(rdram, ctx);
        goto after_7;
    // 0x800405A4: nop

    after_7:
    // 0x800405A8: lui         $v1, 0x51EB
    ctx->r3 = S32(0X51EB << 16);
    // 0x800405AC: ori         $v1, $v1, 0x851F
    ctx->r3 = ctx->r3 | 0X851F;
    // 0x800405B0: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x800405B4: sra         $a0, $v0, 16
    ctx->r4 = S32(SIGNED(ctx->r2) >> 16);
    // 0x800405B8: mult        $a0, $v1
    result = S64(S32(ctx->r4)) * S64(S32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800405BC: sra         $v0, $v0, 31
    ctx->r2 = S32(SIGNED(ctx->r2) >> 31);
    // 0x800405C0: lwc1        $f0, 0x44($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X44);
    // 0x800405C4: mfhi        $t0
    ctx->r8 = hi;
    // 0x800405C8: sra         $v1, $t0, 5
    ctx->r3 = S32(SIGNED(ctx->r8) >> 5);
    // 0x800405CC: subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // 0x800405D0: sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3 << 1);
    // 0x800405D4: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800405D8: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x800405DC: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800405E0: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800405E4: subu        $a0, $a0, $v0
    ctx->r4 = SUB32(ctx->r4, ctx->r2);
    // 0x800405E8: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x800405EC: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    // 0x800405F0: mtc1        $a0, $f2
    ctx->f2.u32l = ctx->r4;
    // 0x800405F4: cvt.s.w     $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    ctx->f2.fl = CVT_S_W(ctx->f2.u32l);
    // 0x800405F8: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x800405FC: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80040600: lwc1        $f2, -0x5BD8($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X5BD8);
    // 0x80040604: lwc1        $f4, 0x40($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X40);
    // 0x80040608: div.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f2.fl);
    // 0x8004060C: add.s       $f4, $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f0.fl;
    // 0x80040610: lwc1        $f2, 0x0($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X0);
    // 0x80040614: mul.s       $f2, $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f4.fl);
    // 0x80040618: lwc1        $f0, 0x128($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X128);
    // 0x8004061C: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x80040620: swc1        $f0, 0x128($s1)
    MEM_W(0X128, ctx->r17) = ctx->f0.u32l;
L_80040624:
    // 0x80040624: lwc1        $f0, 0x12C($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X12C);
    // 0x80040628: lwc1        $f2, 0x0($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X0);
    // 0x8004062C: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x80040630: j           L_80040978
    // 0x80040634: swc1        $f0, 0x12C($s1)
    MEM_W(0X12C, ctx->r17) = ctx->f0.u32l;
        goto L_80040978;
    // 0x80040634: swc1        $f0, 0x12C($s1)
    MEM_W(0X12C, ctx->r17) = ctx->f0.u32l;
L_80040638:
    // 0x80040638: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x8004063C: addu        $s3, $s0, $zero
    ctx->r19 = ADD32(ctx->r16, 0);
    // 0x80040640: swc1        $f2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f2.u32l;
    // 0x80040644: swc1        $f2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f2.u32l;
    // 0x80040648: swc1        $f2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f2.u32l;
    // 0x8004064C: lhu         $v0, 0x140($s1)
    ctx->r2 = MEM_HU(ctx->r17, 0X140);
    // 0x80040650: ori         $s0, $zero, 0xFFFF
    ctx->r16 = 0 | 0XFFFF;
    // 0x80040654: beq         $v0, $s0, L_800407A0
    if (ctx->r2 == ctx->r16) {
        // 0x80040658: nop
    
            goto L_800407A0;
    }
    // 0x80040658: nop

    // 0x8004065C: lwc1        $f0, 0x12C($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X12C);
    // 0x80040660: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x80040664: nop

    // 0x80040668: bc1f        L_800407A0
    if (!c1cs) {
        // 0x8004066C: nop
    
            goto L_800407A0;
    }
    // 0x8004066C: nop

    // 0x80040670: jal         0x80040218
    // 0x80040674: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    func_80040218(rdram, ctx);
        goto after_8;
    // 0x80040674: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    after_8:
    // 0x80040678: andi        $a0, $v0, 0xFFFF
    ctx->r4 = ctx->r2 & 0XFFFF;
    // 0x8004067C: beq         $a0, $s0, L_8004079C
    if (ctx->r4 == ctx->r16) {
        // 0x80040680: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_8004079C;
    }
    // 0x80040680: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80040684: jal         0x8004015C
    // 0x80040688: nop

    func_8004015C(rdram, ctx);
        goto after_9;
    // 0x80040688: nop

    after_9:
    // 0x8004068C: addiu       $s0, $sp, 0x38
    ctx->r16 = ADD32(ctx->r29, 0X38);
    // 0x80040690: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x80040694: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80040698: lwc1        $f20, -0x5BD4($at)
    ctx->f20.u32l = MEM_W(ctx->r1, -0X5BD4);
    // 0x8004069C: addu        $s2, $v0, $zero
    ctx->r18 = ADD32(ctx->r2, 0);
    // 0x800406A0: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x800406A4: jal         0x80059B50
    // 0x800406A8: addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    func_80059B50(rdram, ctx);
        goto after_10;
    // 0x800406A8: addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    after_10:
    // 0x800406AC: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x800406B0: addiu       $a1, $s1, 0x144
    ctx->r5 = ADD32(ctx->r17, 0X144);
    // 0x800406B4: jal         0x800193E8
    // 0x800406B8: addiu       $a2, $sp, 0x18
    ctx->r6 = ADD32(ctx->r29, 0X18);
    func_800193E8(rdram, ctx);
        goto after_11;
    // 0x800406B8: addiu       $a2, $sp, 0x18
    ctx->r6 = ADD32(ctx->r29, 0X18);
    after_11:
    // 0x800406BC: lwc1        $f2, 0x18($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X18);
    // 0x800406C0: lwc1        $f0, 0x4($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X4);
    // 0x800406C4: sub.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl - ctx->f0.fl;
    // 0x800406C8: swc1        $f2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f2.u32l;
    // 0x800406CC: lwc1        $f0, 0x4($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X4);
    // 0x800406D0: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x800406D4: swc1        $f0, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->f0.u32l;
    // 0x800406D8: lwc1        $f2, 0x1C($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x800406DC: lwc1        $f0, 0x8($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X8);
    // 0x800406E0: sub.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl - ctx->f0.fl;
    // 0x800406E4: swc1        $f2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f2.u32l;
    // 0x800406E8: lwc1        $f0, 0x8($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X8);
    // 0x800406EC: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x800406F0: swc1        $f0, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->f0.u32l;
    // 0x800406F4: lwc1        $f2, 0x20($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X20);
    // 0x800406F8: lwc1        $f0, 0xC($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0XC);
    // 0x800406FC: sub.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl - ctx->f0.fl;
    // 0x80040700: swc1        $f2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f2.u32l;
    // 0x80040704: lwc1        $f0, 0xC($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0XC);
    // 0x80040708: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x8004070C: lwc1        $f2, 0x12C($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0X12C);
    // 0x80040710: swc1        $f0, 0xC($s1)
    MEM_W(0XC, ctx->r17) = ctx->f0.u32l;
    // 0x80040714: lwc1        $f0, 0x18($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X18);
    // 0x80040718: lwc1        $f4, 0x15C($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X15C);
    // 0x8004071C: div.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f2.fl);
    // 0x80040720: mul.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x80040724: swc1        $f0, 0x150($s1)
    MEM_W(0X150, ctx->r17) = ctx->f0.u32l;
    // 0x80040728: lwc1        $f0, 0x1C($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x8004072C: div.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f2.fl);
    // 0x80040730: mul.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x80040734: swc1        $f0, 0x154($s1)
    MEM_W(0X154, ctx->r17) = ctx->f0.u32l;
    // 0x80040738: lwc1        $f0, 0x20($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X20);
    // 0x8004073C: div.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f2.fl);
    // 0x80040740: mul.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x80040744: lhu         $v0, 0x7C($s1)
    ctx->r2 = MEM_HU(ctx->r17, 0X7C);
    // 0x80040748: andi        $v0, $v0, 0x2
    ctx->r2 = ctx->r2 & 0X2;
    // 0x8004074C: beq         $v0, $zero, L_800407A0
    if (ctx->r2 == 0) {
        // 0x80040750: swc1        $f0, 0x158($s1)
        MEM_W(0X158, ctx->r17) = ctx->f0.u32l;
            goto L_800407A0;
    }
    // 0x80040750: swc1        $f0, 0x158($s1)
    MEM_W(0X158, ctx->r17) = ctx->f0.u32l;
    // 0x80040754: lwc1        $f0, 0x128($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X128);
    // 0x80040758: c.lt.s      $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f20.fl < ctx->f0.fl;
    // 0x8004075C: nop

    // 0x80040760: bc1f        L_800407A0
    if (!c1cs) {
        // 0x80040764: addiu       $a0, $s1, 0x2C
        ctx->r4 = ADD32(ctx->r17, 0X2C);
            goto L_800407A0;
    }
    // 0x80040764: addiu       $a0, $s1, 0x2C
    ctx->r4 = ADD32(ctx->r17, 0X2C);
    // 0x80040768: lw          $t1, 0xC($s2)
    ctx->r9 = MEM_W(ctx->r18, 0XC);
    // 0x8004076C: lw          $t2, 0x10($s2)
    ctx->r10 = MEM_W(ctx->r18, 0X10);
    // 0x80040770: lw          $t3, 0x14($s2)
    ctx->r11 = MEM_W(ctx->r18, 0X14);
    // 0x80040774: sw          $t1, 0x20($s1)
    MEM_W(0X20, ctx->r17) = ctx->r9;
    // 0x80040778: sw          $t2, 0x24($s1)
    MEM_W(0X24, ctx->r17) = ctx->r10;
    // 0x8004077C: sw          $t3, 0x28($s1)
    MEM_W(0X28, ctx->r17) = ctx->r11;
    // 0x80040780: addiu       $a1, $s2, 0xC
    ctx->r5 = ADD32(ctx->r18, 0XC);
    // 0x80040784: jal         0x80019548
    // 0x80040788: addiu       $a2, $s2, 0x18
    ctx->r6 = ADD32(ctx->r18, 0X18);
    func_80019548(rdram, ctx);
        goto after_12;
    // 0x80040788: addiu       $a2, $s2, 0x18
    ctx->r6 = ADD32(ctx->r18, 0X18);
    after_12:
    // 0x8004078C: j           L_800407A0
    // 0x80040790: nop

        goto L_800407A0;
    // 0x80040790: nop

L_80040794:
    // 0x80040794: j           L_80040888
    // 0x80040798: sb          $v0, 0x160($s1)
    MEM_B(0X160, ctx->r17) = ctx->r2;
        goto L_80040888;
    // 0x80040798: sb          $v0, 0x160($s1)
    MEM_B(0X160, ctx->r17) = ctx->r2;
L_8004079C:
    // 0x8004079C: sb          $v0, 0x160($s1)
    MEM_B(0X160, ctx->r17) = ctx->r2;
L_800407A0:
    // 0x800407A0: lwc1        $f4, 0x18($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X18);
    // 0x800407A4: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x800407A8: lwc1        $f6, -0x5BD0($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X5BD0);
    // 0x800407AC: neg.s       $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f4.fl = -ctx->f4.fl;
    // 0x800407B0: mul.s       $f4, $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x800407B4: lwc1        $f2, 0x1C($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x800407B8: neg.s       $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = -ctx->f2.fl;
    // 0x800407BC: mul.s       $f2, $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f6.fl);
    // 0x800407C0: lwc1        $f0, 0x20($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X20);
    // 0x800407C4: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
    // 0x800407C8: mul.s       $f0, $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x800407CC: swc1        $f4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f4.u32l;
    // 0x800407D0: swc1        $f2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f2.u32l;
    // 0x800407D4: swc1        $f0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f0.u32l;
    // 0x800407D8: lwc1        $f4, 0x128($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X128);
    // 0x800407DC: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x800407E0: lwc1        $f0, -0x5BCC($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X5BCC);
    // 0x800407E4: c.le.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl <= ctx->f4.fl;
    // 0x800407E8: nop

    // 0x800407EC: bc1f        L_800408A0
    if (!c1cs) {
        // 0x800407F0: mov.s       $f20, $f0
        CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
            goto L_800408A0;
    }
    // 0x800407F0: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x800407F4: c.le.s      $f20, $f4
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f20.fl <= ctx->f4.fl;
    // 0x800407F8: nop

    // 0x800407FC: bc1f        L_80040888
    if (!c1cs) {
        // 0x80040800: nop
    
            goto L_80040888;
    }
    // 0x80040800: nop

    // 0x80040804: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80040808: lwc1        $f24, -0x5BC8($at)
    ctx->f24.u32l = MEM_W(ctx->r1, -0X5BC8);
    // 0x8004080C: mov.s       $f22, $f20
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 20);
    ctx->f22.fl = ctx->f20.fl;
    // 0x80040810: div.s       $f0, $f20, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = DIV_S(ctx->f20.fl, ctx->f4.fl);
L_80040814:
    // 0x80040814: add.s       $f0, $f0, $f24
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f24.fl;
    // 0x80040818: lwc1        $f6, 0x18($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X18);
    // 0x8004081C: mul.s       $f6, $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x80040820: lwc1        $f4, 0x1C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x80040824: mul.s       $f4, $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x80040828: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x8004082C: lwc1        $f2, 0x20($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X20);
    // 0x80040830: addiu       $a1, $s1, 0x150
    ctx->r5 = ADD32(ctx->r17, 0X150);
    // 0x80040834: mul.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x80040838: addiu       $a2, $s1, 0x130
    ctx->r6 = ADD32(ctx->r17, 0X130);
    // 0x8004083C: addiu       $a3, $sp, 0x28
    ctx->r7 = ADD32(ctx->r29, 0X28);
    // 0x80040840: swc1        $f6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f6.u32l;
    // 0x80040844: swc1        $f4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f4.u32l;
    // 0x80040848: jal         0x800409A4
    // 0x8004084C: swc1        $f2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f2.u32l;
    func_800409A4(rdram, ctx);
        goto after_13;
    // 0x8004084C: swc1        $f2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f2.u32l;
    after_13:
    // 0x80040850: lhu         $v0, 0x74($s1)
    ctx->r2 = MEM_HU(ctx->r17, 0X74);
    // 0x80040854: beql        $v0, $zero, L_80040874
    if (ctx->r2 == 0) {
        // 0x80040858: add.s       $f20, $f20, $f22
        CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f20.fl = ctx->f20.fl + ctx->f22.fl;
            goto L_80040874;
    }
    goto skip_1;
    // 0x80040858: add.s       $f20, $f20, $f22
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f20.fl = ctx->f20.fl + ctx->f22.fl;
    skip_1:
    // 0x8004085C: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x80040860: sh          $v0, 0x74($s1)
    MEM_H(0X74, ctx->r17) = ctx->r2;
    // 0x80040864: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x80040868: beq         $v0, $zero, L_80040794
    if (ctx->r2 == 0) {
        // 0x8004086C: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80040794;
    }
    // 0x8004086C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80040870: add.s       $f20, $f20, $f22
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f20.fl = ctx->f20.fl + ctx->f22.fl;
L_80040874:
    // 0x80040874: lwc1        $f4, 0x128($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X128);
    // 0x80040878: c.le.s      $f20, $f4
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f20.fl <= ctx->f4.fl;
    // 0x8004087C: nop

    // 0x80040880: bc1tl       L_80040814
    if (c1cs) {
        // 0x80040884: div.s       $f0, $f20, $f4
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = DIV_S(ctx->f20.fl, ctx->f4.fl);
            goto L_80040814;
    }
    goto skip_2;
    // 0x80040884: div.s       $f0, $f20, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = DIV_S(ctx->f20.fl, ctx->f4.fl);
    skip_2:
L_80040888:
    // 0x80040888: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8004088C: lwc1        $f2, -0x5BC4($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X5BC4);
    // 0x80040890: sub.s       $f2, $f20, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = ctx->f20.fl - ctx->f2.fl;
    // 0x80040894: lwc1        $f0, 0x128($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X128);
    // 0x80040898: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x8004089C: swc1        $f0, 0x128($s1)
    MEM_W(0X128, ctx->r17) = ctx->f0.u32l;
L_800408A0:
    // 0x800408A0: lwc1        $f0, 0x48($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X48);
    // 0x800408A4: lwc1        $f2, 0x12C($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0X12C);
    // 0x800408A8: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x800408AC: lwc1        $f2, 0x40($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0X40);
    // 0x800408B0: sub.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl - ctx->f0.fl;
    // 0x800408B4: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x800408B8: c.lt.s      $f2, $f20
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f2.fl < ctx->f20.fl;
    // 0x800408BC: nop

    // 0x800408C0: bc1f        L_800408D0
    if (!c1cs) {
        // 0x800408C4: swc1        $f2, 0x40($s1)
        MEM_W(0X40, ctx->r17) = ctx->f2.u32l;
            goto L_800408D0;
    }
    // 0x800408C4: swc1        $f2, 0x40($s1)
    MEM_W(0X40, ctx->r17) = ctx->f2.u32l;
    // 0x800408C8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800408CC: sb          $v0, 0x160($s1)
    MEM_B(0X160, ctx->r17) = ctx->r2;
L_800408D0:
    // 0x800408D0: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x800408D4: addiu       $a2, $sp, 0x18
    ctx->r6 = ADD32(ctx->r29, 0X18);
    // 0x800408D8: sw          $zero, 0xEC($s1)
    MEM_W(0XEC, ctx->r17) = 0;
    // 0x800408DC: sw          $s3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r19;
    // 0x800408E0: lw          $a1, 0x12C($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X12C);
    // 0x800408E4: jal         0x8004118C
    // 0x800408E8: addiu       $a3, $s1, 0xEC
    ctx->r7 = ADD32(ctx->r17, 0XEC);
    func_8004118C(rdram, ctx);
        goto after_14;
    // 0x800408E8: addiu       $a3, $s1, 0xEC
    ctx->r7 = ADD32(ctx->r17, 0XEC);
    after_14:
    // 0x800408EC: lw          $v0, 0xEC($s1)
    ctx->r2 = MEM_W(ctx->r17, 0XEC);
    // 0x800408F0: beq         $v0, $zero, L_80040978
    if (ctx->r2 == 0) {
        // 0x800408F4: swc1        $f20, 0x12C($s1)
        MEM_W(0X12C, ctx->r17) = ctx->f20.u32l;
            goto L_80040978;
    }
    // 0x800408F4: swc1        $f20, 0x12C($s1)
    MEM_W(0X12C, ctx->r17) = ctx->f20.u32l;
    // 0x800408F8: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x800408FC: lwc1        $f0, -0x5BC0($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X5BC0);
    // 0x80040900: addiu       $s0, $s1, 0x9C
    ctx->r16 = ADD32(ctx->r17, 0X9C);
    // 0x80040904: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80040908: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x8004090C: addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    // 0x80040910: jal         0x8001CB64
    // 0x80040914: addu        $a3, $a1, $zero
    ctx->r7 = ADD32(ctx->r5, 0);
    func_8001CB64(rdram, ctx);
        goto after_15;
    // 0x80040914: addu        $a3, $a1, $zero
    ctx->r7 = ADD32(ctx->r5, 0);
    after_15:
    // 0x80040918: lw          $a1, 0x4($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X4);
    // 0x8004091C: lw          $a2, 0x8($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X8);
    // 0x80040920: lw          $a3, 0xC($s1)
    ctx->r7 = MEM_W(ctx->r17, 0XC);
    // 0x80040924: jal         0x8001CAC4
    // 0x80040928: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_8001CAC4(rdram, ctx);
        goto after_16;
    // 0x80040928: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_16:
    // 0x8004092C: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x80040930: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80040934: lw          $a0, 0x0($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X0);
    // 0x80040938: lw          $a3, 0x0($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X0);
    // 0x8004093C: jal         0x8001DC34
    // 0x80040940: addiu       $a2, $s1, 0x4
    ctx->r6 = ADD32(ctx->r17, 0X4);
    func_8001DC34(rdram, ctx);
        goto after_17;
    // 0x80040940: addiu       $a2, $s1, 0x4
    ctx->r6 = ADD32(ctx->r17, 0X4);
    after_17:
    // 0x80040944: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x80040948: beq         $v0, $zero, L_80040978
    if (ctx->r2 == 0) {
        // 0x8004094C: nop
    
            goto L_80040978;
    }
    // 0x8004094C: nop

    // 0x80040950: lw          $v0, 0x0($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X0);
    // 0x80040954: lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X0);
    // 0x80040958: beq         $v1, $zero, L_80040968
    if (ctx->r3 == 0) {
        // 0x8004095C: sw          $v1, 0x80($s1)
        MEM_W(0X80, ctx->r17) = ctx->r3;
            goto L_80040968;
    }
    // 0x8004095C: sw          $v1, 0x80($s1)
    MEM_W(0X80, ctx->r17) = ctx->r3;
    // 0x80040960: addiu       $v0, $s1, 0x80
    ctx->r2 = ADD32(ctx->r17, 0X80);
    // 0x80040964: sw          $v0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r2;
L_80040968:
    // 0x80040968: sw          $zero, 0x84($s1)
    MEM_W(0X84, ctx->r17) = 0;
    // 0x8004096C: lw          $v1, 0x0($s3)
    ctx->r3 = MEM_W(ctx->r19, 0X0);
    // 0x80040970: addiu       $v0, $s1, 0x80
    ctx->r2 = ADD32(ctx->r17, 0X80);
    // 0x80040974: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
L_80040978:
    // 0x80040978: lw          $ra, 0x78($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X78);
    // 0x8004097C: lw          $s3, 0x74($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X74);
    // 0x80040980: lw          $s2, 0x70($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X70);
    // 0x80040984: lw          $s1, 0x6C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X6C);
    // 0x80040988: lw          $s0, 0x68($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X68);
    // 0x8004098C: ldc1        $f24, 0x90($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X90);
    // 0x80040990: ldc1        $f22, 0x88($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X88);
    // 0x80040994: ldc1        $f20, 0x80($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X80);
    // 0x80040998: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8004099C: jr          $ra
    // 0x800409A0: addiu       $sp, $sp, 0x98
    ctx->r29 = ADD32(ctx->r29, 0X98);
    return;
    // 0x800409A0: addiu       $sp, $sp, 0x98
    ctx->r29 = ADD32(ctx->r29, 0X98);
;}
RECOMP_FUNC void func_800409A4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800409A4: addiu       $sp, $sp, -0x88
    ctx->r29 = ADD32(ctx->r29, -0X88);
    // 0x800409A8: sw          $s3, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r19;
    // 0x800409AC: addu        $s3, $a0, $zero
    ctx->r19 = ADD32(ctx->r4, 0);
    // 0x800409B0: sw          $s6, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r22;
    // 0x800409B4: addu        $s6, $a1, $zero
    ctx->r22 = ADD32(ctx->r5, 0);
    // 0x800409B8: sw          $s4, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r20;
    // 0x800409BC: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800409C0: sw          $s5, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r21;
    // 0x800409C4: lhu         $s5, 0xBD4($v0)
    ctx->r21 = MEM_HU(ctx->r2, 0XBD4);
    // 0x800409C8: ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
    // 0x800409CC: sw          $ra, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r31;
    // 0x800409D0: sw          $s2, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r18;
    // 0x800409D4: sw          $s1, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r17;
    // 0x800409D8: sw          $s0, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r16;
    // 0x800409DC: sdc1        $f20, 0x80($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X80, ctx->r29);
    // 0x800409E0: beq         $s5, $v0, L_80041160
    if (ctx->r21 == ctx->r2) {
        // 0x800409E4: addu        $s4, $a3, $zero
        ctx->r20 = ADD32(ctx->r7, 0);
            goto L_80041160;
    }
    // 0x800409E4: addu        $s4, $a3, $zero
    ctx->r20 = ADD32(ctx->r7, 0);
    // 0x800409E8: lhu         $v0, 0x7C($s3)
    ctx->r2 = MEM_HU(ctx->r19, 0X7C);
    // 0x800409EC: andi        $v0, $v0, 0x40
    ctx->r2 = ctx->r2 & 0X40;
    // 0x800409F0: beq         $v0, $zero, L_80040A08
    if (ctx->r2 == 0) {
        // 0x800409F4: lui         $v0, 0x8013
        ctx->r2 = S32(0X8013 << 16);
            goto L_80040A08;
    }
    // 0x800409F4: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800409F8: lw          $v0, 0xBC8($v0)
    ctx->r2 = MEM_W(ctx->r2, 0XBC8);
    // 0x800409FC: slti        $v0, $v0, 0x4
    ctx->r2 = SIGNED(ctx->r2) < 0X4 ? 1 : 0;
    // 0x80040A00: bne         $v0, $zero, L_80041160
    if (ctx->r2 != 0) {
        // 0x80040A04: ori         $v0, $zero, 0xFFFF
        ctx->r2 = 0 | 0XFFFF;
            goto L_80041160;
    }
    // 0x80040A04: ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
L_80040A08:
    // 0x80040A08: lui         $a3, 0x8013
    ctx->r7 = S32(0X8013 << 16);
    // 0x80040A0C: andi        $v0, $s5, 0xFFFF
    ctx->r2 = ctx->r21 & 0XFFFF;
    // 0x80040A10: sll         $v1, $v0, 3
    ctx->r3 = S32(ctx->r2 << 3);
    // 0x80040A14: subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // 0x80040A18: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x80040A1C: subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // 0x80040A20: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x80040A24: lw          $a1, 0xBD0($a3)
    ctx->r5 = MEM_W(ctx->r7, 0XBD0);
    // 0x80040A28: ori         $a0, $zero, 0xFFFF
    ctx->r4 = 0 | 0XFFFF;
    // 0x80040A2C: addu        $s2, $a1, $v1
    ctx->r18 = ADD32(ctx->r5, ctx->r3);
    // 0x80040A30: lhu         $v0, 0x2($s2)
    ctx->r2 = MEM_HU(ctx->r18, 0X2);
    // 0x80040A34: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x80040A38: sh          $v0, 0xBD4($v1)
    MEM_H(0XBD4, ctx->r3) = ctx->r2;
    // 0x80040A3C: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x80040A40: beq         $v0, $a0, L_80040A68
    if (ctx->r2 == ctx->r4) {
        // 0x80040A44: nop
    
            goto L_80040A68;
    }
    // 0x80040A44: nop

    // 0x80040A48: lhu         $v1, 0xBD4($v1)
    ctx->r3 = MEM_HU(ctx->r3, 0XBD4);
    // 0x80040A4C: sll         $v0, $v1, 3
    ctx->r2 = S32(ctx->r3 << 3);
    // 0x80040A50: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x80040A54: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80040A58: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x80040A5C: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80040A60: addu        $v0, $v0, $a1
    ctx->r2 = ADD32(ctx->r2, ctx->r5);
    // 0x80040A64: sh          $a0, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r4;
L_80040A68:
    // 0x80040A68: beq         $a2, $zero, L_80040AB0
    if (ctx->r6 == 0) {
        // 0x80040A6C: nop
    
            goto L_80040AB0;
    }
    // 0x80040A6C: nop

    // 0x80040A70: lhu         $v0, 0x0($a2)
    ctx->r2 = MEM_HU(ctx->r6, 0X0);
    // 0x80040A74: sh          $v0, 0x2($s2)
    MEM_H(0X2, ctx->r18) = ctx->r2;
    // 0x80040A78: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x80040A7C: beql        $v0, $a0, L_80040AAC
    if (ctx->r2 == ctx->r4) {
        // 0x80040A80: sh          $a0, 0x0($s2)
        MEM_H(0X0, ctx->r18) = ctx->r4;
            goto L_80040AAC;
    }
    goto skip_0;
    // 0x80040A80: sh          $a0, 0x0($s2)
    MEM_H(0X0, ctx->r18) = ctx->r4;
    skip_0:
    // 0x80040A84: lhu         $v0, 0x2($s2)
    ctx->r2 = MEM_HU(ctx->r18, 0X2);
    // 0x80040A88: sll         $v1, $v0, 3
    ctx->r3 = S32(ctx->r2 << 3);
    // 0x80040A8C: subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // 0x80040A90: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x80040A94: subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // 0x80040A98: lw          $v0, 0xBD0($a3)
    ctx->r2 = MEM_W(ctx->r7, 0XBD0);
    // 0x80040A9C: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x80040AA0: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x80040AA4: sh          $s5, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r21;
    // 0x80040AA8: sh          $a0, 0x0($s2)
    MEM_H(0X0, ctx->r18) = ctx->r4;
L_80040AAC:
    // 0x80040AAC: sh          $s5, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r21;
L_80040AB0:
    // 0x80040AB0: lhu         $v0, 0x7C($s3)
    ctx->r2 = MEM_HU(ctx->r19, 0X7C);
    // 0x80040AB4: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80040AB8: sh          $v0, 0x20($s2)
    MEM_H(0X20, ctx->r18) = ctx->r2;
    // 0x80040ABC: lwc1        $f2, 0x38($s3)
    ctx->f2.u32l = MEM_W(ctx->r19, 0X38);
    // 0x80040AC0: c.eq.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl == ctx->f0.fl;
    // 0x80040AC4: nop

    // 0x80040AC8: bc1t        L_80040C04
    if (c1cs) {
        // 0x80040ACC: addiu       $a0, $sp, 0x10
        ctx->r4 = ADD32(ctx->r29, 0X10);
            goto L_80040C04;
    }
    // 0x80040ACC: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    // 0x80040AD0: addiu       $s1, $s3, 0x20
    ctx->r17 = ADD32(ctx->r19, 0X20);
    // 0x80040AD4: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    // 0x80040AD8: jal         0x80019548
    // 0x80040ADC: addiu       $a2, $s3, 0x2C
    ctx->r6 = ADD32(ctx->r19, 0X2C);
    func_80019548(rdram, ctx);
        goto after_0;
    // 0x80040ADC: addiu       $a2, $s3, 0x2C
    ctx->r6 = ADD32(ctx->r19, 0X2C);
    after_0:
    // 0x80040AE0: jal         0x80003430
    // 0x80040AE4: nop

    rand_recomp(rdram, ctx);
        goto after_1;
    // 0x80040AE4: nop

    after_1:
    // 0x80040AE8: lui         $v1, 0xB60B
    ctx->r3 = S32(0XB60B << 16);
    // 0x80040AEC: ori         $v1, $v1, 0x60B7
    ctx->r3 = ctx->r3 | 0X60B7;
    // 0x80040AF0: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x80040AF4: sra         $a3, $v0, 16
    ctx->r7 = S32(SIGNED(ctx->r2) >> 16);
    // 0x80040AF8: mult        $a3, $v1
    result = S64(S32(ctx->r7)) * S64(S32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80040AFC: addiu       $s0, $sp, 0x20
    ctx->r16 = ADD32(ctx->r29, 0X20);
    // 0x80040B00: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x80040B04: sra         $v0, $v0, 31
    ctx->r2 = S32(SIGNED(ctx->r2) >> 31);
    // 0x80040B08: mfhi        $t0
    ctx->r8 = hi;
    // 0x80040B0C: addu        $a2, $t0, $a3
    ctx->r6 = ADD32(ctx->r8, ctx->r7);
    // 0x80040B10: sra         $a2, $a2, 8
    ctx->r6 = S32(SIGNED(ctx->r6) >> 8);
    // 0x80040B14: subu        $a2, $a2, $v0
    ctx->r6 = SUB32(ctx->r6, ctx->r2);
    // 0x80040B18: sll         $v1, $a2, 1
    ctx->r3 = S32(ctx->r6 << 1);
    // 0x80040B1C: addu        $v1, $v1, $a2
    ctx->r3 = ADD32(ctx->r3, ctx->r6);
    // 0x80040B20: sll         $v0, $v1, 4
    ctx->r2 = S32(ctx->r3 << 4);
    // 0x80040B24: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x80040B28: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x80040B2C: subu        $a3, $a3, $v0
    ctx->r7 = SUB32(ctx->r7, ctx->r2);
    // 0x80040B30: sll         $a3, $a3, 16
    ctx->r7 = S32(ctx->r7 << 16);
    // 0x80040B34: sra         $a3, $a3, 16
    ctx->r7 = S32(SIGNED(ctx->r7) >> 16);
    // 0x80040B38: mtc1        $a3, $f6
    ctx->f6.u32l = ctx->r7;
    // 0x80040B3C: cvt.s.w     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80040B40: mfc1        $a2, $f6
    ctx->r6 = (int32_t)ctx->f6.u32l;
    // 0x80040B44: jal         0x8001D144
    // 0x80040B48: addiu       $a1, $sp, 0x10
    ctx->r5 = ADD32(ctx->r29, 0X10);
    func_8001D144(rdram, ctx);
        goto after_2;
    // 0x80040B48: addiu       $a1, $sp, 0x10
    ctx->r5 = ADD32(ctx->r29, 0X10);
    after_2:
    // 0x80040B4C: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x80040B50: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    // 0x80040B54: jal         0x8001D3C4
    // 0x80040B58: addiu       $a2, $sp, 0x10
    ctx->r6 = ADD32(ctx->r29, 0X10);
    func_8001D3C4(rdram, ctx);
        goto after_3;
    // 0x80040B58: addiu       $a2, $sp, 0x10
    ctx->r6 = ADD32(ctx->r29, 0X10);
    after_3:
    // 0x80040B5C: jal         0x80003430
    // 0x80040B60: nop

    rand_recomp(rdram, ctx);
        goto after_4;
    // 0x80040B60: nop

    after_4:
    // 0x80040B64: lui         $v1, 0x51EB
    ctx->r3 = S32(0X51EB << 16);
    // 0x80040B68: ori         $v1, $v1, 0x851F
    ctx->r3 = ctx->r3 | 0X851F;
    // 0x80040B6C: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x80040B70: sra         $a0, $v0, 16
    ctx->r4 = S32(SIGNED(ctx->r2) >> 16);
    // 0x80040B74: mult        $a0, $v1
    result = S64(S32(ctx->r4)) * S64(S32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80040B78: sra         $v0, $v0, 31
    ctx->r2 = S32(SIGNED(ctx->r2) >> 31);
    // 0x80040B7C: lwc1        $f4, 0x38($s3)
    ctx->f4.u32l = MEM_W(ctx->r19, 0X38);
    // 0x80040B80: mfhi        $t0
    ctx->r8 = hi;
    // 0x80040B84: sra         $v1, $t0, 5
    ctx->r3 = S32(SIGNED(ctx->r8) >> 5);
    // 0x80040B88: subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // 0x80040B8C: sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3 << 1);
    // 0x80040B90: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80040B94: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x80040B98: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80040B9C: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80040BA0: subu        $a0, $a0, $v0
    ctx->r4 = SUB32(ctx->r4, ctx->r2);
    // 0x80040BA4: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x80040BA8: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    // 0x80040BAC: mtc1        $a0, $f0
    ctx->f0.u32l = ctx->r4;
    // 0x80040BB0: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x80040BB4: mul.s       $f4, $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x80040BB8: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80040BBC: lwc1        $f2, -0x5BBC($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X5BBC);
    // 0x80040BC0: lwc1        $f0, 0x10($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X10);
    // 0x80040BC4: div.s       $f4, $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = DIV_S(ctx->f4.fl, ctx->f2.fl);
    // 0x80040BC8: mul.s       $f0, $f4, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x80040BCC: lwc1        $f2, 0x0($s4)
    ctx->f2.u32l = MEM_W(ctx->r20, 0X0);
    // 0x80040BD0: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x80040BD4: swc1        $f0, 0x4($s2)
    MEM_W(0X4, ctx->r18) = ctx->f0.u32l;
    // 0x80040BD8: lwc1        $f0, 0x14($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X14);
    // 0x80040BDC: mul.s       $f0, $f4, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x80040BE0: lwc1        $f2, 0x4($s4)
    ctx->f2.u32l = MEM_W(ctx->r20, 0X4);
    // 0x80040BE4: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x80040BE8: swc1        $f0, 0x8($s2)
    MEM_W(0X8, ctx->r18) = ctx->f0.u32l;
    // 0x80040BEC: lwc1        $f0, 0x18($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X18);
    // 0x80040BF0: mul.s       $f4, $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x80040BF4: lwc1        $f0, 0x8($s4)
    ctx->f0.u32l = MEM_W(ctx->r20, 0X8);
    // 0x80040BF8: add.s       $f4, $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f0.fl;
    // 0x80040BFC: j           L_80040C1C
    // 0x80040C00: swc1        $f4, 0xC($s2)
    MEM_W(0XC, ctx->r18) = ctx->f4.u32l;
        goto L_80040C1C;
    // 0x80040C00: swc1        $f4, 0xC($s2)
    MEM_W(0XC, ctx->r18) = ctx->f4.u32l;
L_80040C04:
    // 0x80040C04: lw          $t1, 0x0($s4)
    ctx->r9 = MEM_W(ctx->r20, 0X0);
    // 0x80040C08: lw          $t2, 0x4($s4)
    ctx->r10 = MEM_W(ctx->r20, 0X4);
    // 0x80040C0C: lw          $t3, 0x8($s4)
    ctx->r11 = MEM_W(ctx->r20, 0X8);
    // 0x80040C10: sw          $t1, 0x4($s2)
    MEM_W(0X4, ctx->r18) = ctx->r9;
    // 0x80040C14: sw          $t2, 0x8($s2)
    MEM_W(0X8, ctx->r18) = ctx->r10;
    // 0x80040C18: sw          $t3, 0xC($s2)
    MEM_W(0XC, ctx->r18) = ctx->r11;
L_80040C1C:
    // 0x80040C1C: lh          $v0, 0x3C($s3)
    ctx->r2 = MEM_H(ctx->r19, 0X3C);
    // 0x80040C20: beq         $v0, $zero, L_80040CA4
    if (ctx->r2 == 0) {
        // 0x80040C24: addiu       $a0, $sp, 0x20
        ctx->r4 = ADD32(ctx->r29, 0X20);
            goto L_80040CA4;
    }
    // 0x80040C24: addiu       $a0, $sp, 0x20
    ctx->r4 = ADD32(ctx->r29, 0X20);
    // 0x80040C28: jal         0x80003430
    // 0x80040C2C: nop

    rand_recomp(rdram, ctx);
        goto after_5;
    // 0x80040C2C: nop

    after_5:
    // 0x80040C30: lhu         $a3, 0x3C($s3)
    ctx->r7 = MEM_HU(ctx->r19, 0X3C);
    // 0x80040C34: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x80040C38: sll         $a3, $a3, 16
    ctx->r7 = S32(ctx->r7 << 16);
    // 0x80040C3C: sra         $v1, $a3, 16
    ctx->r3 = S32(SIGNED(ctx->r7) >> 16);
    // 0x80040C40: div         $zero, $v0, $v1
    lo = S32(S64(S32(ctx->r2)) / S64(S32(ctx->r3))); hi = S32(S64(S32(ctx->r2)) % S64(S32(ctx->r3)));
    // 0x80040C44: bne         $v1, $zero, L_80040C50
    if (ctx->r3 != 0) {
        // 0x80040C48: nop
    
            goto L_80040C50;
    }
    // 0x80040C48: nop

    // 0x80040C4C: break       7
    do_break(2147748940);
L_80040C50:
    // 0x80040C50: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80040C54: bne         $v1, $at, L_80040C68
    if (ctx->r3 != ctx->r1) {
        // 0x80040C58: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80040C68;
    }
    // 0x80040C58: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80040C5C: bne         $v0, $at, L_80040C68
    if (ctx->r2 != ctx->r1) {
        // 0x80040C60: nop
    
            goto L_80040C68;
    }
    // 0x80040C60: nop

    // 0x80040C64: break       6
    do_break(2147748964);
L_80040C68:
    // 0x80040C68: mfhi        $a2
    ctx->r6 = hi;
    // 0x80040C6C: addiu       $a0, $sp, 0x20
    ctx->r4 = ADD32(ctx->r29, 0X20);
    // 0x80040C70: srl         $a3, $a3, 31
    ctx->r7 = S32(U32(ctx->r7) >> 31);
    // 0x80040C74: addu        $v1, $v1, $a3
    ctx->r3 = ADD32(ctx->r3, ctx->r7);
    // 0x80040C78: sra         $v1, $v1, 1
    ctx->r3 = S32(SIGNED(ctx->r3) >> 1);
    // 0x80040C7C: sll         $a2, $a2, 16
    ctx->r6 = S32(ctx->r6 << 16);
    // 0x80040C80: sra         $a2, $a2, 16
    ctx->r6 = S32(SIGNED(ctx->r6) >> 16);
    // 0x80040C84: subu        $a2, $a2, $v1
    ctx->r6 = SUB32(ctx->r6, ctx->r3);
    // 0x80040C88: mtc1        $a2, $f6
    ctx->f6.u32l = ctx->r6;
    // 0x80040C8C: cvt.s.w     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80040C90: mfc1        $a2, $f6
    ctx->r6 = (int32_t)ctx->f6.u32l;
    // 0x80040C94: jal         0x8001D240
    // 0x80040C98: addiu       $a1, $s3, 0x20
    ctx->r5 = ADD32(ctx->r19, 0X20);
    func_8001D240(rdram, ctx);
        goto after_6;
    // 0x80040C98: addiu       $a1, $s3, 0x20
    ctx->r5 = ADD32(ctx->r19, 0X20);
    after_6:
    // 0x80040C9C: j           L_80040CB0
    // 0x80040CA0: nop

        goto L_80040CB0;
    // 0x80040CA0: nop

L_80040CA4:
    // 0x80040CA4: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x80040CA8: jal         0x8001D038
    // 0x80040CAC: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    func_8001D038(rdram, ctx);
        goto after_7;
    // 0x80040CAC: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    after_7:
L_80040CB0:
    // 0x80040CB0: lh          $v0, 0x3E($s3)
    ctx->r2 = MEM_H(ctx->r19, 0X3E);
    // 0x80040CB4: beq         $v0, $zero, L_80040D38
    if (ctx->r2 == 0) {
        // 0x80040CB8: addiu       $a0, $sp, 0x30
        ctx->r4 = ADD32(ctx->r29, 0X30);
            goto L_80040D38;
    }
    // 0x80040CB8: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    // 0x80040CBC: jal         0x80003430
    // 0x80040CC0: nop

    rand_recomp(rdram, ctx);
        goto after_8;
    // 0x80040CC0: nop

    after_8:
    // 0x80040CC4: lhu         $a3, 0x3E($s3)
    ctx->r7 = MEM_HU(ctx->r19, 0X3E);
    // 0x80040CC8: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x80040CCC: sll         $a3, $a3, 16
    ctx->r7 = S32(ctx->r7 << 16);
    // 0x80040CD0: sra         $v1, $a3, 16
    ctx->r3 = S32(SIGNED(ctx->r7) >> 16);
    // 0x80040CD4: div         $zero, $v0, $v1
    lo = S32(S64(S32(ctx->r2)) / S64(S32(ctx->r3))); hi = S32(S64(S32(ctx->r2)) % S64(S32(ctx->r3)));
    // 0x80040CD8: bne         $v1, $zero, L_80040CE4
    if (ctx->r3 != 0) {
        // 0x80040CDC: nop
    
            goto L_80040CE4;
    }
    // 0x80040CDC: nop

    // 0x80040CE0: break       7
    do_break(2147749088);
L_80040CE4:
    // 0x80040CE4: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80040CE8: bne         $v1, $at, L_80040CFC
    if (ctx->r3 != ctx->r1) {
        // 0x80040CEC: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80040CFC;
    }
    // 0x80040CEC: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80040CF0: bne         $v0, $at, L_80040CFC
    if (ctx->r2 != ctx->r1) {
        // 0x80040CF4: nop
    
            goto L_80040CFC;
    }
    // 0x80040CF4: nop

    // 0x80040CF8: break       6
    do_break(2147749112);
L_80040CFC:
    // 0x80040CFC: mfhi        $a2
    ctx->r6 = hi;
    // 0x80040D00: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    // 0x80040D04: srl         $a3, $a3, 31
    ctx->r7 = S32(U32(ctx->r7) >> 31);
    // 0x80040D08: addu        $v1, $v1, $a3
    ctx->r3 = ADD32(ctx->r3, ctx->r7);
    // 0x80040D0C: sra         $v1, $v1, 1
    ctx->r3 = S32(SIGNED(ctx->r3) >> 1);
    // 0x80040D10: sll         $a2, $a2, 16
    ctx->r6 = S32(ctx->r6 << 16);
    // 0x80040D14: sra         $a2, $a2, 16
    ctx->r6 = S32(SIGNED(ctx->r6) >> 16);
    // 0x80040D18: subu        $a2, $a2, $v1
    ctx->r6 = SUB32(ctx->r6, ctx->r3);
    // 0x80040D1C: mtc1        $a2, $f6
    ctx->f6.u32l = ctx->r6;
    // 0x80040D20: cvt.s.w     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80040D24: mfc1        $a2, $f6
    ctx->r6 = (int32_t)ctx->f6.u32l;
    // 0x80040D28: jal         0x8001D240
    // 0x80040D2C: addiu       $a1, $s3, 0x2C
    ctx->r5 = ADD32(ctx->r19, 0X2C);
    func_8001D240(rdram, ctx);
        goto after_9;
    // 0x80040D2C: addiu       $a1, $s3, 0x2C
    ctx->r5 = ADD32(ctx->r19, 0X2C);
    after_9:
    // 0x80040D30: j           L_80040D48
    // 0x80040D34: addiu       $a0, $sp, 0x20
    ctx->r4 = ADD32(ctx->r29, 0X20);
        goto L_80040D48;
    // 0x80040D34: addiu       $a0, $sp, 0x20
    ctx->r4 = ADD32(ctx->r29, 0X20);
L_80040D38:
    // 0x80040D38: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x80040D3C: jal         0x8001D038
    // 0x80040D40: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    func_8001D038(rdram, ctx);
        goto after_10;
    // 0x80040D40: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    after_10:
    // 0x80040D44: addiu       $a0, $sp, 0x20
    ctx->r4 = ADD32(ctx->r29, 0X20);
L_80040D48:
    // 0x80040D48: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    // 0x80040D4C: addiu       $s0, $sp, 0x40
    ctx->r16 = ADD32(ctx->r29, 0X40);
    // 0x80040D50: jal         0x8001D2C0
    // 0x80040D54: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    func_8001D2C0(rdram, ctx);
        goto after_11;
    // 0x80040D54: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    after_11:
    // 0x80040D58: lwc1        $f2, 0x1C($s3)
    ctx->f2.u32l = MEM_W(ctx->r19, 0X1C);
    // 0x80040D5C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80040D60: c.eq.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl == ctx->f0.fl;
    // 0x80040D64: nop

    // 0x80040D68: bc1t        L_80040E2C
    if (c1cs) {
        // 0x80040D6C: addu        $a0, $s0, $zero
        ctx->r4 = ADD32(ctx->r16, 0);
            goto L_80040E2C;
    }
    // 0x80040D6C: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x80040D70: jal         0x80003430
    // 0x80040D74: nop

    rand_recomp(rdram, ctx);
        goto after_12;
    // 0x80040D74: nop

    after_12:
    // 0x80040D78: lui         $v1, 0x51EB
    ctx->r3 = S32(0X51EB << 16);
    // 0x80040D7C: ori         $v1, $v1, 0x851F
    ctx->r3 = ctx->r3 | 0X851F;
    // 0x80040D80: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x80040D84: sra         $a0, $v0, 16
    ctx->r4 = S32(SIGNED(ctx->r2) >> 16);
    // 0x80040D88: mult        $a0, $v1
    result = S64(S32(ctx->r4)) * S64(S32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80040D8C: sra         $v0, $v0, 31
    ctx->r2 = S32(SIGNED(ctx->r2) >> 31);
    // 0x80040D90: lwc1        $f4, 0x1C($s3)
    ctx->f4.u32l = MEM_W(ctx->r19, 0X1C);
    // 0x80040D94: mfhi        $t0
    ctx->r8 = hi;
    // 0x80040D98: sra         $v1, $t0, 5
    ctx->r3 = S32(SIGNED(ctx->r8) >> 5);
    // 0x80040D9C: subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // 0x80040DA0: sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3 << 1);
    // 0x80040DA4: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80040DA8: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x80040DAC: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80040DB0: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80040DB4: subu        $a0, $a0, $v0
    ctx->r4 = SUB32(ctx->r4, ctx->r2);
    // 0x80040DB8: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x80040DBC: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    // 0x80040DC0: mtc1        $a0, $f20
    ctx->f20.u32l = ctx->r4;
    // 0x80040DC4: cvt.s.w     $f20, $f20
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    ctx->f20.fl = CVT_S_W(ctx->f20.u32l);
    // 0x80040DC8: mul.s       $f20, $f4, $f20
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f20.fl = MUL_S(ctx->f4.fl, ctx->f20.fl);
    // 0x80040DCC: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80040DD0: lwc1        $f0, -0x5BB8($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X5BB8);
    // 0x80040DD4: mul.s       $f4, $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x80040DD8: addiu       $a1, $s3, 0x10
    ctx->r5 = ADD32(ctx->r19, 0X10);
    // 0x80040DDC: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80040DE0: lwc1        $f0, -0x5BB4($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X5BB4);
    // 0x80040DE4: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80040DE8: lwc1        $f2, -0x5BB0($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X5BB0);
    // 0x80040DEC: div.s       $f20, $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f20.fl = DIV_S(ctx->f20.fl, ctx->f0.fl);
    // 0x80040DF0: add.s       $f20, $f20, $f2
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f20.fl = ctx->f20.fl + ctx->f2.fl;
    // 0x80040DF4: addiu       $a2, $sp, 0x10
    ctx->r6 = ADD32(ctx->r29, 0X10);
    // 0x80040DF8: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x80040DFC: jal         0x8001D3C4
    // 0x80040E00: sub.s       $f20, $f20, $f4
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f20.fl = ctx->f20.fl - ctx->f4.fl;
    func_8001D3C4(rdram, ctx);
        goto after_13;
    // 0x80040E00: sub.s       $f20, $f20, $f4
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f20.fl = ctx->f20.fl - ctx->f4.fl;
    after_13:
    // 0x80040E04: lwc1        $f0, 0x10($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X10);
    // 0x80040E08: mul.s       $f0, $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f20.fl);
    // 0x80040E0C: swc1        $f0, 0x10($s2)
    MEM_W(0X10, ctx->r18) = ctx->f0.u32l;
    // 0x80040E10: lwc1        $f0, 0x14($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X14);
    // 0x80040E14: mul.s       $f0, $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f20.fl);
    // 0x80040E18: swc1        $f0, 0x14($s2)
    MEM_W(0X14, ctx->r18) = ctx->f0.u32l;
    // 0x80040E1C: lwc1        $f0, 0x18($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X18);
    // 0x80040E20: mul.s       $f0, $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f20.fl);
    // 0x80040E24: j           L_80040E38
    // 0x80040E28: swc1        $f0, 0x18($s2)
    MEM_W(0X18, ctx->r18) = ctx->f0.u32l;
        goto L_80040E38;
    // 0x80040E28: swc1        $f0, 0x18($s2)
    MEM_W(0X18, ctx->r18) = ctx->f0.u32l;
L_80040E2C:
    // 0x80040E2C: addiu       $a1, $s3, 0x10
    ctx->r5 = ADD32(ctx->r19, 0X10);
    // 0x80040E30: jal         0x8001D3C4
    // 0x80040E34: addiu       $a2, $s2, 0x10
    ctx->r6 = ADD32(ctx->r18, 0X10);
    func_8001D3C4(rdram, ctx);
        goto after_14;
    // 0x80040E34: addiu       $a2, $s2, 0x10
    ctx->r6 = ADD32(ctx->r18, 0X10);
    after_14:
L_80040E38:
    // 0x80040E38: beq         $s6, $zero, L_80040E50
    if (ctx->r22 == 0) {
        // 0x80040E3C: nop
    
            goto L_80040E50;
    }
    // 0x80040E3C: nop

    // 0x80040E40: lwc1        $f0, 0x10($s2)
    ctx->f0.u32l = MEM_W(ctx->r18, 0X10);
    // 0x80040E44: lwc1        $f2, 0x0($s6)
    ctx->f2.u32l = MEM_W(ctx->r22, 0X0);
    // 0x80040E48: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x80040E4C: swc1        $f0, 0x10($s2)
    MEM_W(0X10, ctx->r18) = ctx->f0.u32l;
L_80040E50:
    // 0x80040E50: lwc1        $f0, 0x14($s2)
    ctx->f0.u32l = MEM_W(ctx->r18, 0X14);
    // 0x80040E54: lwc1        $f2, 0x4($s6)
    ctx->f2.u32l = MEM_W(ctx->r22, 0X4);
    // 0x80040E58: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x80040E5C: swc1        $f0, 0x14($s2)
    MEM_W(0X14, ctx->r18) = ctx->f0.u32l;
    // 0x80040E60: lwc1        $f0, 0x18($s2)
    ctx->f0.u32l = MEM_W(ctx->r18, 0X18);
    // 0x80040E64: lwc1        $f2, 0x8($s6)
    ctx->f2.u32l = MEM_W(ctx->r22, 0X8);
    // 0x80040E68: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x80040E6C: jal         0x80003430
    // 0x80040E70: swc1        $f0, 0x18($s2)
    MEM_W(0X18, ctx->r18) = ctx->f0.u32l;
    rand_recomp(rdram, ctx);
        goto after_15;
    // 0x80040E70: swc1        $f0, 0x18($s2)
    MEM_W(0X18, ctx->r18) = ctx->f0.u32l;
    after_15:
    // 0x80040E74: lui         $v1, 0x51EB
    ctx->r3 = S32(0X51EB << 16);
    // 0x80040E78: ori         $v1, $v1, 0x851F
    ctx->r3 = ctx->r3 | 0X851F;
    // 0x80040E7C: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x80040E80: sra         $a0, $v0, 16
    ctx->r4 = S32(SIGNED(ctx->r2) >> 16);
    // 0x80040E84: mult        $a0, $v1
    result = S64(S32(ctx->r4)) * S64(S32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80040E88: sra         $v0, $v0, 31
    ctx->r2 = S32(SIGNED(ctx->r2) >> 31);
    // 0x80040E8C: lwc1        $f0, 0x50($s3)
    ctx->f0.u32l = MEM_W(ctx->r19, 0X50);
    // 0x80040E90: mfhi        $t0
    ctx->r8 = hi;
    // 0x80040E94: sra         $v1, $t0, 5
    ctx->r3 = S32(SIGNED(ctx->r8) >> 5);
    // 0x80040E98: subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // 0x80040E9C: sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3 << 1);
    // 0x80040EA0: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80040EA4: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x80040EA8: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80040EAC: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80040EB0: subu        $a0, $a0, $v0
    ctx->r4 = SUB32(ctx->r4, ctx->r2);
    // 0x80040EB4: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x80040EB8: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    // 0x80040EBC: mtc1        $a0, $f2
    ctx->f2.u32l = ctx->r4;
    // 0x80040EC0: cvt.s.w     $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    ctx->f2.fl = CVT_S_W(ctx->f2.u32l);
    // 0x80040EC4: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x80040EC8: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80040ECC: lwc1        $f2, -0x5BAC($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X5BAC);
    // 0x80040ED0: lwc1        $f4, 0x4C($s3)
    ctx->f4.u32l = MEM_W(ctx->r19, 0X4C);
    // 0x80040ED4: div.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f2.fl);
    // 0x80040ED8: add.s       $f4, $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f0.fl;
    // 0x80040EDC: swc1        $f4, 0x1C($s2)
    MEM_W(0X1C, ctx->r18) = ctx->f4.u32l;
    // 0x80040EE0: lhu         $v0, 0x7C($s3)
    ctx->r2 = MEM_HU(ctx->r19, 0X7C);
    // 0x80040EE4: andi        $v0, $v0, 0x40
    ctx->r2 = ctx->r2 & 0X40;
    // 0x80040EE8: beq         $v0, $zero, L_80040F3C
    if (ctx->r2 == 0) {
        // 0x80040EEC: addiu       $a2, $zero, 0x1
        ctx->r6 = ADD32(0, 0X1);
            goto L_80040F3C;
    }
    // 0x80040EEC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80040EF0: swc1        $f4, 0x28($s2)
    MEM_W(0X28, ctx->r18) = ctx->f4.u32l;
    // 0x80040EF4: sw          $s3, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r19;
    // 0x80040EF8: sw          $s2, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r18;
    // 0x80040EFC: sw          $zero, 0x58($sp)
    MEM_W(0X58, ctx->r29) = 0;
    // 0x80040F00: sw          $zero, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = 0;
    // 0x80040F04: lhu         $v0, 0x7C($s3)
    ctx->r2 = MEM_HU(ctx->r19, 0X7C);
    // 0x80040F08: andi        $v0, $v0, 0x80
    ctx->r2 = ctx->r2 & 0X80;
    // 0x80040F0C: beq         $v0, $zero, L_80040F18
    if (ctx->r2 == 0) {
        // 0x80040F10: addiu       $a1, $sp, 0x50
        ctx->r5 = ADD32(ctx->r29, 0X50);
            goto L_80040F18;
    }
    // 0x80040F10: addiu       $a1, $sp, 0x50
    ctx->r5 = ADD32(ctx->r29, 0X50);
    // 0x80040F14: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
L_80040F18:
    // 0x80040F18: lw          $a0, 0x60($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X60);
    // 0x80040F1C: jal         0x8003FFEC
    // 0x80040F20: addiu       $a3, $zero, 0xF
    ctx->r7 = ADD32(0, 0XF);
    func_8003FFEC(rdram, ctx);
        goto after_16;
    // 0x80040F20: addiu       $a3, $zero, 0xF
    ctx->r7 = ADD32(0, 0XF);
    after_16:
    // 0x80040F24: sh          $v0, 0x24($s2)
    MEM_H(0X24, ctx->r18) = ctx->r2;
    // 0x80040F28: andi        $a1, $v0, 0xFFFF
    ctx->r5 = ctx->r2 & 0XFFFF;
    // 0x80040F2C: jal         0x80040188
    // 0x80040F30: ori         $a0, $zero, 0xFFFF
    ctx->r4 = 0 | 0XFFFF;
    func_80040188(rdram, ctx);
        goto after_17;
    // 0x80040F30: ori         $a0, $zero, 0xFFFF
    ctx->r4 = 0 | 0XFFFF;
    after_17:
    // 0x80040F34: j           L_8004115C
    // 0x80040F38: sh          $v0, 0x26($s2)
    MEM_H(0X26, ctx->r18) = ctx->r2;
        goto L_8004115C;
    // 0x80040F38: sh          $v0, 0x26($s2)
    MEM_H(0X26, ctx->r18) = ctx->r2;
L_80040F3C:
    // 0x80040F3C: sh          $zero, 0x44($s2)
    MEM_H(0X44, ctx->r18) = 0;
    // 0x80040F40: lhu         $v0, 0x7C($s3)
    ctx->r2 = MEM_HU(ctx->r19, 0X7C);
    // 0x80040F44: andi        $v0, $v0, 0x8
    ctx->r2 = ctx->r2 & 0X8;
    // 0x80040F48: beq         $v0, $zero, L_80040F68
    if (ctx->r2 == 0) {
        // 0x80040F4C: nop
    
            goto L_80040F68;
    }
    // 0x80040F4C: nop

    // 0x80040F50: jal         0x80003430
    // 0x80040F54: nop

    rand_recomp(rdram, ctx);
        goto after_18;
    // 0x80040F54: nop

    after_18:
    // 0x80040F58: lhu         $v1, 0x44($s2)
    ctx->r3 = MEM_HU(ctx->r18, 0X44);
    // 0x80040F5C: andi        $v0, $v0, 0x1C00
    ctx->r2 = ctx->r2 & 0X1C00;
    // 0x80040F60: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x80040F64: sh          $v1, 0x44($s2)
    MEM_H(0X44, ctx->r18) = ctx->r3;
L_80040F68:
    // 0x80040F68: lw          $v0, 0x64($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X64);
    // 0x80040F6C: sw          $v0, 0x64($s2)
    MEM_W(0X64, ctx->r18) = ctx->r2;
    // 0x80040F70: lbu         $v0, 0x6C($s3)
    ctx->r2 = MEM_BU(ctx->r19, 0X6C);
    // 0x80040F74: sltiu       $v0, $v0, 0x2
    ctx->r2 = ctx->r2 < 0X2 ? 1 : 0;
    // 0x80040F78: bne         $v0, $zero, L_80041020
    if (ctx->r2 != 0) {
        // 0x80040F7C: addiu       $v0, $zero, 0x100
        ctx->r2 = ADD32(0, 0X100);
            goto L_80041020;
    }
    // 0x80040F7C: addiu       $v0, $zero, 0x100
    ctx->r2 = ADD32(0, 0X100);
    // 0x80040F80: lbu         $v0, 0x6C($s3)
    ctx->r2 = MEM_BU(ctx->r19, 0X6C);
    // 0x80040F84: sll         $v0, $v0, 8
    ctx->r2 = S32(ctx->r2 << 8);
    // 0x80040F88: sh          $v0, 0x24($s2)
    MEM_H(0X24, ctx->r18) = ctx->r2;
    // 0x80040F8C: lhu         $v0, 0x7C($s3)
    ctx->r2 = MEM_HU(ctx->r19, 0X7C);
    // 0x80040F90: andi        $v0, $v0, 0x30
    ctx->r2 = ctx->r2 & 0X30;
    // 0x80040F94: beq         $v0, $zero, L_80040FC8
    if (ctx->r2 == 0) {
        // 0x80040F98: nop
    
            goto L_80040FC8;
    }
    // 0x80040F98: nop

    // 0x80040F9C: lhu         $v0, 0x6E($s3)
    ctx->r2 = MEM_HU(ctx->r19, 0X6E);
    // 0x80040FA0: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80040FA4: lwc1        $f2, -0x5BA8($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X5BA8);
    // 0x80040FA8: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x80040FAC: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x80040FB0: c.le.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl <= ctx->f0.fl;
    // 0x80040FB4: nop

    // 0x80040FB8: bc1f        L_80040FF4
    if (!c1cs) {
        // 0x80040FBC: nop
    
            goto L_80040FF4;
    }
    // 0x80040FBC: nop

    // 0x80040FC0: j           L_80041004
    // 0x80040FC4: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
        goto L_80041004;
    // 0x80040FC4: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
L_80040FC8:
    // 0x80040FC8: lhu         $v0, 0x24($s2)
    ctx->r2 = MEM_HU(ctx->r18, 0X24);
    // 0x80040FCC: lwc1        $f0, 0x1C($s2)
    ctx->f0.u32l = MEM_W(ctx->r18, 0X1C);
    // 0x80040FD0: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80040FD4: lwc1        $f4, -0x5BA4($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X5BA4);
    // 0x80040FD8: mtc1        $v0, $f2
    ctx->f2.u32l = ctx->r2;
    // 0x80040FDC: cvt.s.w     $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    ctx->f2.fl = CVT_S_W(ctx->f2.u32l);
    // 0x80040FE0: div.s       $f0, $f2, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = DIV_S(ctx->f2.fl, ctx->f0.fl);
    // 0x80040FE4: c.le.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl <= ctx->f0.fl;
    // 0x80040FE8: nop

    // 0x80040FEC: bc1tl       L_80041004
    if (c1cs) {
        // 0x80040FF0: sub.s       $f0, $f0, $f4
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f4.fl;
            goto L_80041004;
    }
    goto skip_1;
    // 0x80040FF0: sub.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f4.fl;
    skip_1:
L_80040FF4:
    // 0x80040FF4: trunc.w.s   $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    ctx->f6.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x80040FF8: mfc1        $v1, $f6
    ctx->r3 = (int32_t)ctx->f6.u32l;
    // 0x80040FFC: j           L_80041018
    // 0x80041000: addu        $v0, $v1, $zero
    ctx->r2 = ADD32(ctx->r3, 0);
        goto L_80041018;
    // 0x80041000: addu        $v0, $v1, $zero
    ctx->r2 = ADD32(ctx->r3, 0);
L_80041004:
    // 0x80041004: lui         $v0, 0x8000
    ctx->r2 = S32(0X8000 << 16);
    // 0x80041008: trunc.w.s   $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    ctx->f6.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x8004100C: mfc1        $v1, $f6
    ctx->r3 = (int32_t)ctx->f6.u32l;
    // 0x80041010: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x80041014: addu        $v0, $v1, $zero
    ctx->r2 = ADD32(ctx->r3, 0);
L_80041018:
    // 0x80041018: j           L_80041028
    // 0x8004101C: sh          $v0, 0x28($s2)
    MEM_H(0X28, ctx->r18) = ctx->r2;
        goto L_80041028;
    // 0x8004101C: sh          $v0, 0x28($s2)
    MEM_H(0X28, ctx->r18) = ctx->r2;
L_80041020:
    // 0x80041020: sh          $v0, 0x24($s2)
    MEM_H(0X24, ctx->r18) = ctx->r2;
    // 0x80041024: sh          $zero, 0x28($s2)
    MEM_H(0X28, ctx->r18) = 0;
L_80041028:
    // 0x80041028: lw          $v0, 0x64($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X64);
    // 0x8004102C: sh          $zero, 0x26($s2)
    MEM_H(0X26, ctx->r18) = 0;
    // 0x80041030: lhu         $v0, 0x0($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X0);
    // 0x80041034: sh          $v0, 0x46($s2)
    MEM_H(0X46, ctx->r18) = ctx->r2;
    // 0x80041038: lw          $v0, 0x68($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X68);
    // 0x8004103C: sw          $v0, 0x68($s2)
    MEM_W(0X68, ctx->r18) = ctx->r2;
    // 0x80041040: lbu         $v0, 0x6D($s3)
    ctx->r2 = MEM_BU(ctx->r19, 0X6D);
    // 0x80041044: beq         $v0, $zero, L_800410D0
    if (ctx->r2 == 0) {
        // 0x80041048: addiu       $v0, $zero, 0x100
        ctx->r2 = ADD32(0, 0X100);
            goto L_800410D0;
    }
    // 0x80041048: addiu       $v0, $zero, 0x100
    ctx->r2 = ADD32(0, 0X100);
    // 0x8004104C: lbu         $v0, 0x6D($s3)
    ctx->r2 = MEM_BU(ctx->r19, 0X6D);
    // 0x80041050: lwc1        $f0, 0x1C($s2)
    ctx->f0.u32l = MEM_W(ctx->r18, 0X1C);
    // 0x80041054: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80041058: lwc1        $f4, -0x5BA0($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X5BA0);
    // 0x8004105C: sll         $v0, $v0, 8
    ctx->r2 = S32(ctx->r2 << 8);
    // 0x80041060: sh          $v0, 0x2A($s2)
    MEM_H(0X2A, ctx->r18) = ctx->r2;
    // 0x80041064: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x80041068: mtc1        $v0, $f2
    ctx->f2.u32l = ctx->r2;
    // 0x8004106C: cvt.s.w     $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    ctx->f2.fl = CVT_S_W(ctx->f2.u32l);
    // 0x80041070: div.s       $f0, $f2, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = DIV_S(ctx->f2.fl, ctx->f0.fl);
    // 0x80041074: c.le.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl <= ctx->f0.fl;
    // 0x80041078: nop

    // 0x8004107C: bc1tl       L_80041094
    if (c1cs) {
        // 0x80041080: sub.s       $f0, $f0, $f4
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f4.fl;
            goto L_80041094;
    }
    goto skip_2;
    // 0x80041080: sub.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f4.fl;
    skip_2:
    // 0x80041084: trunc.w.s   $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    ctx->f6.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x80041088: mfc1        $v1, $f6
    ctx->r3 = (int32_t)ctx->f6.u32l;
    // 0x8004108C: j           L_800410A4
    // 0x80041090: nop

        goto L_800410A4;
    // 0x80041090: nop

L_80041094:
    // 0x80041094: lui         $v0, 0x8000
    ctx->r2 = S32(0X8000 << 16);
    // 0x80041098: trunc.w.s   $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    ctx->f6.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x8004109C: mfc1        $v1, $f6
    ctx->r3 = (int32_t)ctx->f6.u32l;
    // 0x800410A0: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
L_800410A4:
    // 0x800410A4: lhu         $v0, 0x44($s2)
    ctx->r2 = MEM_HU(ctx->r18, 0X44);
    // 0x800410A8: sh          $v1, 0x2E($s2)
    MEM_H(0X2E, ctx->r18) = ctx->r3;
    // 0x800410AC: lw          $v1, 0x68($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X68);
    // 0x800410B0: ori         $v0, $v0, 0x200
    ctx->r2 = ctx->r2 | 0X200;
    // 0x800410B4: sh          $v0, 0x44($s2)
    MEM_H(0X44, ctx->r18) = ctx->r2;
    // 0x800410B8: lwl         $t1, 0x0($v1)
    ctx->r9 = do_lwl(rdram, ctx->r9, ctx->r3, 0X0);
    // 0x800410BC: lwr         $t1, 0x3($v1)
    ctx->r9 = do_lwr(rdram, ctx->r9, ctx->r3, 0X3);
    // 0x800410C0: swl         $t1, 0x60($s2)
    do_swl(rdram, 0X60, ctx->r18, ctx->r9);
    // 0x800410C4: swr         $t1, 0x63($s2)
    do_swr(rdram, 0X63, ctx->r18, ctx->r9);
    // 0x800410C8: j           L_800410DC
    // 0x800410CC: sh          $zero, 0x2C($s2)
    MEM_H(0X2C, ctx->r18) = 0;
        goto L_800410DC;
    // 0x800410CC: sh          $zero, 0x2C($s2)
    MEM_H(0X2C, ctx->r18) = 0;
L_800410D0:
    // 0x800410D0: sh          $v0, 0x2A($s2)
    MEM_H(0X2A, ctx->r18) = ctx->r2;
    // 0x800410D4: sh          $zero, 0x2E($s2)
    MEM_H(0X2E, ctx->r18) = 0;
    // 0x800410D8: sh          $zero, 0x2C($s2)
    MEM_H(0X2C, ctx->r18) = 0;
L_800410DC:
    // 0x800410DC: lhu         $v0, 0x70($s3)
    ctx->r2 = MEM_HU(ctx->r19, 0X70);
    // 0x800410E0: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x800410E4: lwc1        $f2, -0x5B9C($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X5B9C);
    // 0x800410E8: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x800410EC: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x800410F0: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x800410F4: swc1        $f0, 0x58($s2)
    MEM_W(0X58, ctx->r18) = ctx->f0.u32l;
    // 0x800410F8: swc1        $f0, 0x54($s2)
    MEM_W(0X54, ctx->r18) = ctx->f0.u32l;
    // 0x800410FC: lhu         $v1, 0x72($s3)
    ctx->r3 = MEM_HU(ctx->r19, 0X72);
    // 0x80041100: beql        $v1, $zero, L_80041140
    if (ctx->r3 == 0) {
        // 0x80041104: sh          $zero, 0x30($s2)
        MEM_H(0X30, ctx->r18) = 0;
            goto L_80041140;
    }
    goto skip_3;
    // 0x80041104: sh          $zero, 0x30($s2)
    MEM_H(0X30, ctx->r18) = 0;
    skip_3:
    // 0x80041108: lhu         $v0, 0x70($s3)
    ctx->r2 = MEM_HU(ctx->r19, 0X70);
    // 0x8004110C: beq         $v1, $v0, L_8004113C
    if (ctx->r3 == ctx->r2) {
        // 0x80041110: addu        $v0, $v1, $zero
        ctx->r2 = ADD32(ctx->r3, 0);
            goto L_8004113C;
    }
    // 0x80041110: addu        $v0, $v1, $zero
    ctx->r2 = ADD32(ctx->r3, 0);
    // 0x80041114: lhu         $v1, 0x70($s3)
    ctx->r3 = MEM_HU(ctx->r19, 0X70);
    // 0x80041118: lwc1        $f2, 0x1C($s2)
    ctx->f2.u32l = MEM_W(ctx->r18, 0X1C);
    // 0x8004111C: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x80041120: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x80041124: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x80041128: div.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f2.fl);
    // 0x8004112C: trunc.w.s   $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    ctx->f6.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x80041130: mfc1        $v0, $f6
    ctx->r2 = (int32_t)ctx->f6.u32l;
    // 0x80041134: j           L_80041140
    // 0x80041138: sh          $v0, 0x30($s2)
    MEM_H(0X30, ctx->r18) = ctx->r2;
        goto L_80041140;
    // 0x80041138: sh          $v0, 0x30($s2)
    MEM_H(0X30, ctx->r18) = ctx->r2;
L_8004113C:
    // 0x8004113C: sh          $zero, 0x30($s2)
    MEM_H(0X30, ctx->r18) = 0;
L_80041140:
    // 0x80041140: lhu         $v0, 0x7C($s3)
    ctx->r2 = MEM_HU(ctx->r19, 0X7C);
    // 0x80041144: andi        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 & 0X1;
    // 0x80041148: beq         $v0, $zero, L_80041160
    if (ctx->r2 == 0) {
        // 0x8004114C: andi        $v0, $s5, 0xFFFF
        ctx->r2 = ctx->r21 & 0XFFFF;
            goto L_80041160;
    }
    // 0x8004114C: andi        $v0, $s5, 0xFFFF
    ctx->r2 = ctx->r21 & 0XFFFF;
    // 0x80041150: lhu         $v0, 0x44($s2)
    ctx->r2 = MEM_HU(ctx->r18, 0X44);
    // 0x80041154: ori         $v0, $v0, 0x100
    ctx->r2 = ctx->r2 | 0X100;
    // 0x80041158: sh          $v0, 0x44($s2)
    MEM_H(0X44, ctx->r18) = ctx->r2;
L_8004115C:
    // 0x8004115C: andi        $v0, $s5, 0xFFFF
    ctx->r2 = ctx->r21 & 0XFFFF;
L_80041160:
    // 0x80041160: lw          $ra, 0x7C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X7C);
    // 0x80041164: lw          $s6, 0x78($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X78);
    // 0x80041168: lw          $s5, 0x74($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X74);
    // 0x8004116C: lw          $s4, 0x70($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X70);
    // 0x80041170: lw          $s3, 0x6C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X6C);
    // 0x80041174: lw          $s2, 0x68($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X68);
    // 0x80041178: lw          $s1, 0x64($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X64);
    // 0x8004117C: lw          $s0, 0x60($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X60);
    // 0x80041180: ldc1        $f20, 0x80($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X80);
    // 0x80041184: jr          $ra
    // 0x80041188: addiu       $sp, $sp, 0x88
    ctx->r29 = ADD32(ctx->r29, 0X88);
    return;
    // 0x80041188: addiu       $sp, $sp, 0x88
    ctx->r29 = ADD32(ctx->r29, 0X88);
;}
RECOMP_FUNC void func_8004118C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8004118C: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x80041190: addiu       $sp, $sp, -0x98
    ctx->r29 = ADD32(ctx->r29, -0X98);
    // 0x80041194: sw          $s5, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r21;
    // 0x80041198: addu        $s5, $a0, $zero
    ctx->r21 = ADD32(ctx->r4, 0);
    // 0x8004119C: sw          $fp, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r30;
    // 0x800411A0: addu        $fp, $a2, $zero
    ctx->r30 = ADD32(ctx->r6, 0);
    // 0x800411A4: sw          $s3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r19;
    // 0x800411A8: addiu       $s3, $s5, 0x134
    ctx->r19 = ADD32(ctx->r21, 0X134);
    // 0x800411AC: sw          $s2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r18;
    // 0x800411B0: addu        $s2, $zero, $zero
    ctx->r18 = ADD32(0, 0);
    // 0x800411B4: sw          $s1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r17;
    // 0x800411B8: addu        $s1, $s2, $zero
    ctx->r17 = ADD32(ctx->r18, 0);
    // 0x800411BC: sw          $ra, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r31;
    // 0x800411C0: sw          $s7, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r23;
    // 0x800411C4: sw          $s6, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r22;
    // 0x800411C8: sw          $s4, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r20;
    // 0x800411CC: sw          $s0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r16;
    // 0x800411D0: sdc1        $f30, 0x90($sp)
    CHECK_FR(ctx, 30);
    SD(ctx->f30.u64, 0X90, ctx->r29);
    // 0x800411D4: sdc1        $f28, 0x88($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0X88, ctx->r29);
    // 0x800411D8: sdc1        $f26, 0x80($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X80, ctx->r29);
    // 0x800411DC: sdc1        $f24, 0x78($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X78, ctx->r29);
    // 0x800411E0: sdc1        $f22, 0x70($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X70, ctx->r29);
    // 0x800411E4: sdc1        $f20, 0x68($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X68, ctx->r29);
    // 0x800411E8: sw          $a1, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->r5;
    // 0x800411EC: sw          $a3, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->r7;
    // 0x800411F0: lw          $v0, 0x134($s5)
    ctx->r2 = MEM_W(ctx->r21, 0X134);
    // 0x800411F4: lwc1        $f16, 0x54($s5)
    ctx->f16.u32l = MEM_W(ctx->r21, 0X54);
    // 0x800411F8: mov.s       $f14, $f12
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    ctx->f14.fl = ctx->f12.fl;
    // 0x800411FC: mov.s       $f10, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    ctx->f10.fl = ctx->f12.fl;
    // 0x80041200: beq         $v0, $zero, L_80041258
    if (ctx->r2 == 0) {
        // 0x80041204: swc1        $f16, 0x30($sp)
        MEM_W(0X30, ctx->r29) = ctx->f16.u32l;
            goto L_80041258;
    }
    // 0x80041204: swc1        $f16, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f16.u32l;
    // 0x80041208: andi        $v0, $s1, 0xFFFF
    ctx->r2 = ctx->r17 & 0XFFFF;
L_8004120C:
    // 0x8004120C: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80041210: addu        $v0, $v0, $s3
    ctx->r2 = ADD32(ctx->r2, ctx->r19);
    // 0x80041214: lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X0);
    // 0x80041218: lbu         $v0, 0x20($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X20);
    // 0x8004121C: bnel        $v0, $zero, L_8004123C
    if (ctx->r2 != 0) {
        // 0x80041220: addiu       $s2, $s2, 0x1
        ctx->r18 = ADD32(ctx->r18, 0X1);
            goto L_8004123C;
    }
    goto skip_0;
    // 0x80041220: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    skip_0:
    // 0x80041224: lwc1        $f0, 0xC($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0XC);
    // 0x80041228: add.s       $f10, $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f10.fl + ctx->f0.fl;
    // 0x8004122C: lwc1        $f0, 0x10($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X10);
    // 0x80041230: add.s       $f14, $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = ctx->f14.fl + ctx->f0.fl;
    // 0x80041234: lwc1        $f0, 0x14($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X14);
    // 0x80041238: add.s       $f12, $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = ctx->f12.fl + ctx->f0.fl;
L_8004123C:
    // 0x8004123C: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80041240: andi        $v0, $s1, 0xFFFF
    ctx->r2 = ctx->r17 & 0XFFFF;
    // 0x80041244: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80041248: addu        $v0, $v0, $s3
    ctx->r2 = ADD32(ctx->r2, ctx->r19);
    // 0x8004124C: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x80041250: bne         $v0, $zero, L_8004120C
    if (ctx->r2 != 0) {
        // 0x80041254: andi        $v0, $s1, 0xFFFF
        ctx->r2 = ctx->r17 & 0XFFFF;
            goto L_8004120C;
    }
    // 0x80041254: andi        $v0, $s1, 0xFFFF
    ctx->r2 = ctx->r17 & 0XFFFF;
L_80041258:
    // 0x80041258: lwc1        $f18, 0x9C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X9C);
    // 0x8004125C: mul.s       $f0, $f10, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f0.fl = MUL_S(ctx->f10.fl, ctx->f18.fl);
    // 0x80041260: nop

    // 0x80041264: mul.s       $f2, $f14, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f2.fl = MUL_S(ctx->f14.fl, ctx->f18.fl);
    // 0x80041268: nop

    // 0x8004126C: mul.s       $f4, $f12, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f12.fl, ctx->f18.fl);
    // 0x80041270: andi        $v0, $s2, 0xFFFF
    ctx->r2 = ctx->r18 & 0XFFFF;
    // 0x80041274: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    // 0x80041278: swc1        $f2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f2.u32l;
    // 0x8004127C: bne         $v0, $zero, L_80041288
    if (ctx->r2 != 0) {
        // 0x80041280: swc1        $f4, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->f4.u32l;
            goto L_80041288;
    }
    // 0x80041280: swc1        $f4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f4.u32l;
    // 0x80041284: addu        $s3, $zero, $zero
    ctx->r19 = ADD32(0, 0);
L_80041288:
    // 0x80041288: lhu         $s1, 0x130($s5)
    ctx->r17 = MEM_HU(ctx->r21, 0X130);
    // 0x8004128C: ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
    // 0x80041290: beq         $s1, $v0, L_800418D4
    if (ctx->r17 == ctx->r2) {
        // 0x80041294: lui         $s6, 0x8013
        ctx->r22 = S32(0X8013 << 16);
            goto L_800418D4;
    }
    // 0x80041294: lui         $s6, 0x8013
    ctx->r22 = S32(0X8013 << 16);
    // 0x80041298: addu        $s4, $v0, $zero
    ctx->r20 = ADD32(ctx->r2, 0);
    // 0x8004129C: lui         $s7, 0x8013
    ctx->r23 = S32(0X8013 << 16);
    // 0x800412A0: andi        $v1, $s1, 0xFFFF
    ctx->r3 = ctx->r17 & 0XFFFF;
L_800412A4:
    // 0x800412A4: sll         $v0, $v1, 3
    ctx->r2 = S32(ctx->r3 << 3);
    // 0x800412A8: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x800412AC: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800412B0: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x800412B4: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800412B8: lw          $v1, 0xBD0($s6)
    ctx->r3 = MEM_W(ctx->r22, 0XBD0);
    // 0x800412BC: lwc1        $f16, 0x9C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X9C);
    // 0x800412C0: addu        $s0, $v1, $v0
    ctx->r16 = ADD32(ctx->r3, ctx->r2);
    // 0x800412C4: lwc1        $f0, 0x1C($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X1C);
    // 0x800412C8: sub.s       $f0, $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f16.fl;
    // 0x800412CC: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x800412D0: lhu         $s2, 0x2($s0)
    ctx->r18 = MEM_HU(ctx->r16, 0X2);
    // 0x800412D4: c.lt.s      $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f0.fl < ctx->f18.fl;
    // 0x800412D8: nop

    // 0x800412DC: bc1t        L_8004130C
    if (c1cs) {
        // 0x800412E0: swc1        $f0, 0x1C($s0)
        MEM_W(0X1C, ctx->r16) = ctx->f0.u32l;
            goto L_8004130C;
    }
    // 0x800412E0: swc1        $f0, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f0.u32l;
    // 0x800412E4: lhu         $v0, 0x20($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X20);
    // 0x800412E8: andi        $v0, $v0, 0x40
    ctx->r2 = ctx->r2 & 0X40;
    // 0x800412EC: beq         $v0, $zero, L_80041414
    if (ctx->r2 == 0) {
        // 0x800412F0: nop
    
            goto L_80041414;
    }
    // 0x800412F0: nop

    // 0x800412F4: lhu         $a0, 0x26($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X26);
    // 0x800412F8: jal         0x80040218
    // 0x800412FC: nop

    func_80040218(rdram, ctx);
        goto after_0;
    // 0x800412FC: nop

    after_0:
    // 0x80041300: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x80041304: bne         $v0, $s4, L_80041414
    if (ctx->r2 != ctx->r20) {
        // 0x80041308: nop
    
            goto L_80041414;
    }
    // 0x80041308: nop

L_8004130C:
    // 0x8004130C: lhu         $v0, 0x20($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X20);
    // 0x80041310: andi        $v0, $v0, 0x40
    ctx->r2 = ctx->r2 & 0X40;
    // 0x80041314: beq         $v0, $zero, L_8004134C
    if (ctx->r2 == 0) {
        // 0x80041318: nop
    
            goto L_8004134C;
    }
    // 0x80041318: nop

    // 0x8004131C: lhu         $a0, 0x26($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X26);
    // 0x80041320: jal         0x80040218
    // 0x80041324: nop

    func_80040218(rdram, ctx);
        goto after_1;
    // 0x80041324: nop

    after_1:
    // 0x80041328: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x8004132C: beq         $v0, $s4, L_80041340
    if (ctx->r2 == ctx->r20) {
        // 0x80041330: nop
    
            goto L_80041340;
    }
    // 0x80041330: nop

    // 0x80041334: lhu         $a0, 0x24($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X24);
    // 0x80041338: jal         0x8003ED74
    // 0x8004133C: nop

    func_8003ED74(rdram, ctx);
        goto after_2;
    // 0x8004133C: nop

    after_2:
L_80041340:
    // 0x80041340: lhu         $a0, 0x26($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X26);
    // 0x80041344: jal         0x8003F0C8
    // 0x80041348: nop

    func_8003F0C8(rdram, ctx);
        goto after_3;
    // 0x80041348: nop

    after_3:
L_8004134C:
    // 0x8004134C: lhu         $v0, 0x0($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X0);
    // 0x80041350: beq         $v0, $s4, L_800413A4
    if (ctx->r2 == ctx->r20) {
        // 0x80041354: addu        $v1, $v0, $zero
        ctx->r3 = ADD32(ctx->r2, 0);
            goto L_800413A4;
    }
    // 0x80041354: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // 0x80041358: sll         $v0, $v1, 3
    ctx->r2 = S32(ctx->r3 << 3);
    // 0x8004135C: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x80041360: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80041364: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x80041368: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8004136C: lw          $a0, 0xBD0($s6)
    ctx->r4 = MEM_W(ctx->r22, 0XBD0);
    // 0x80041370: andi        $v1, $s2, 0xFFFF
    ctx->r3 = ctx->r18 & 0XFFFF;
    // 0x80041374: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x80041378: beq         $v1, $s4, L_800413D0
    if (ctx->r3 == ctx->r20) {
        // 0x8004137C: sh          $s2, 0x2($v0)
        MEM_H(0X2, ctx->r2) = ctx->r18;
            goto L_800413D0;
    }
    // 0x8004137C: sh          $s2, 0x2($v0)
    MEM_H(0X2, ctx->r2) = ctx->r18;
    // 0x80041380: sll         $v0, $v1, 3
    ctx->r2 = S32(ctx->r3 << 3);
    // 0x80041384: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x80041388: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8004138C: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x80041390: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80041394: lhu         $v1, 0x0($s0)
    ctx->r3 = MEM_HU(ctx->r16, 0X0);
    // 0x80041398: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x8004139C: j           L_800413D0
    // 0x800413A0: sh          $v1, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r3;
        goto L_800413D0;
    // 0x800413A0: sh          $v1, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r3;
L_800413A4:
    // 0x800413A4: andi        $v1, $s2, 0xFFFF
    ctx->r3 = ctx->r18 & 0XFFFF;
    // 0x800413A8: beq         $v1, $s4, L_800413D0
    if (ctx->r3 == ctx->r20) {
        // 0x800413AC: sh          $s2, 0x130($s5)
        MEM_H(0X130, ctx->r21) = ctx->r18;
            goto L_800413D0;
    }
    // 0x800413AC: sh          $s2, 0x130($s5)
    MEM_H(0X130, ctx->r21) = ctx->r18;
    // 0x800413B0: sll         $v0, $v1, 3
    ctx->r2 = S32(ctx->r3 << 3);
    // 0x800413B4: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x800413B8: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800413BC: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x800413C0: lw          $v1, 0xBD0($s6)
    ctx->r3 = MEM_W(ctx->r22, 0XBD0);
    // 0x800413C4: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800413C8: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800413CC: sh          $s4, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r20;
L_800413D0:
    // 0x800413D0: lhu         $v0, 0xBD4($s7)
    ctx->r2 = MEM_HU(ctx->r23, 0XBD4);
    // 0x800413D4: sh          $v0, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r2;
    // 0x800413D8: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x800413DC: beql        $v0, $s4, L_8004140C
    if (ctx->r2 == ctx->r20) {
        // 0x800413E0: sh          $s4, 0x0($s0)
        MEM_H(0X0, ctx->r16) = ctx->r20;
            goto L_8004140C;
    }
    goto skip_1;
    // 0x800413E0: sh          $s4, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r20;
    skip_1:
    // 0x800413E4: lhu         $v0, 0xBD4($s7)
    ctx->r2 = MEM_HU(ctx->r23, 0XBD4);
    // 0x800413E8: sll         $v1, $v0, 3
    ctx->r3 = S32(ctx->r2 << 3);
    // 0x800413EC: subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // 0x800413F0: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x800413F4: subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // 0x800413F8: lw          $v0, 0xBD0($s6)
    ctx->r2 = MEM_W(ctx->r22, 0XBD0);
    // 0x800413FC: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x80041400: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x80041404: sh          $s1, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r17;
    // 0x80041408: sh          $s4, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r20;
L_8004140C:
    // 0x8004140C: j           L_800418C4
    // 0x80041410: sh          $s1, 0xBD4($s7)
    MEM_H(0XBD4, ctx->r23) = ctx->r17;
        goto L_800418C4;
    // 0x80041410: sh          $s1, 0xBD4($s7)
    MEM_H(0XBD4, ctx->r23) = ctx->r17;
L_80041414:
    // 0x80041414: lwc1        $f10, 0x10($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X10);
    // 0x80041418: lwc1        $f14, 0x14($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X14);
    // 0x8004141C: lwc1        $f12, 0x18($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X18);
    // 0x80041420: beq         $s3, $zero, L_80041578
    if (ctx->r19 == 0) {
        // 0x80041424: nop
    
            goto L_80041578;
    }
    // 0x80041424: nop

    // 0x80041428: lw          $v0, 0x0($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X0);
    // 0x8004142C: beq         $v0, $zero, L_80041578
    if (ctx->r2 == 0) {
        // 0x80041430: addu        $a2, $zero, $zero
        ctx->r6 = ADD32(0, 0);
            goto L_80041578;
    }
    // 0x80041430: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // 0x80041434: andi        $v0, $a2, 0xFFFF
    ctx->r2 = ctx->r6 & 0XFFFF;
L_80041438:
    // 0x80041438: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8004143C: addu        $v0, $v0, $s3
    ctx->r2 = ADD32(ctx->r2, ctx->r19);
    // 0x80041440: lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X0);
    // 0x80041444: lbu         $v0, 0x20($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X20);
    // 0x80041448: beql        $v0, $zero, L_80041560
    if (ctx->r2 == 0) {
        // 0x8004144C: addiu       $a2, $a2, 0x1
        ctx->r6 = ADD32(ctx->r6, 0X1);
            goto L_80041560;
    }
    goto skip_2;
    // 0x8004144C: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    skip_2:
    // 0x80041450: lwc1        $f16, 0x4($s5)
    ctx->f16.u32l = MEM_W(ctx->r21, 0X4);
    // 0x80041454: lwc1        $f30, 0x4($s0)
    ctx->f30.u32l = MEM_W(ctx->r16, 0X4);
    // 0x80041458: swc1        $f16, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f16.u32l;
    // 0x8004145C: add.s       $f0, $f30, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f30.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f0.fl = ctx->f30.fl + ctx->f16.fl;
    // 0x80041460: lwc1        $f24, 0x0($v1)
    ctx->f24.u32l = MEM_W(ctx->r3, 0X0);
    // 0x80041464: sub.s       $f6, $f0, $f24
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f6.fl = ctx->f0.fl - ctx->f24.fl;
    // 0x80041468: mul.s       $f2, $f6, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = MUL_S(ctx->f6.fl, ctx->f6.fl);
    // 0x8004146C: lwc1        $f26, 0x8($s0)
    ctx->f26.u32l = MEM_W(ctx->r16, 0X8);
    // 0x80041470: lwc1        $f28, 0x8($s5)
    ctx->f28.u32l = MEM_W(ctx->r21, 0X8);
    // 0x80041474: add.s       $f0, $f26, $f28
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f0.fl = ctx->f26.fl + ctx->f28.fl;
    // 0x80041478: lwc1        $f18, 0x4($v1)
    ctx->f18.u32l = MEM_W(ctx->r3, 0X4);
    // 0x8004147C: sub.s       $f6, $f0, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = ctx->f0.fl - ctx->f18.fl;
    // 0x80041480: mul.s       $f4, $f6, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = MUL_S(ctx->f6.fl, ctx->f6.fl);
    // 0x80041484: swc1        $f18, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f18.u32l;
    // 0x80041488: lwc1        $f20, 0xC($s0)
    ctx->f20.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8004148C: lwc1        $f22, 0xC($s5)
    ctx->f22.u32l = MEM_W(ctx->r21, 0XC);
    // 0x80041490: add.s       $f0, $f20, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f0.fl = ctx->f20.fl + ctx->f22.fl;
    // 0x80041494: lwc1        $f16, 0x8($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0X8);
    // 0x80041498: sub.s       $f6, $f0, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = ctx->f0.fl - ctx->f16.fl;
    // 0x8004149C: mul.s       $f0, $f6, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = MUL_S(ctx->f6.fl, ctx->f6.fl);
    // 0x800414A0: add.s       $f2, $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f4.fl;
    // 0x800414A4: swc1        $f16, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f16.u32l;
    // 0x800414A8: add.s       $f8, $f2, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x800414AC: lwc1        $f2, 0x18($v1)
    ctx->f2.u32l = MEM_W(ctx->r3, 0X18);
    // 0x800414B0: c.lt.s      $f8, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f8.fl < ctx->f2.fl;
    // 0x800414B4: nop

    // 0x800414B8: bc1fl       L_80041560
    if (!c1cs) {
        // 0x800414BC: addiu       $a2, $a2, 0x1
        ctx->r6 = ADD32(ctx->r6, 0X1);
            goto L_80041560;
    }
    goto skip_3;
    // 0x800414BC: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    skip_3:
    // 0x800414C0: sqrt.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = sqrtf(ctx->f8.fl);
    // 0x800414C4: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x800414C8: lwc1        $f18, -0x5B98($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X5B98);
    // 0x800414CC: div.s       $f2, $f8, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = DIV_S(ctx->f8.fl, ctx->f2.fl);
    // 0x800414D0: sub.s       $f2, $f18, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = ctx->f18.fl - ctx->f2.fl;
    // 0x800414D4: lwc1        $f16, 0x9C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X9C);
    // 0x800414D8: mul.s       $f8, $f2, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = MUL_S(ctx->f2.fl, ctx->f16.fl);
    // 0x800414DC: lwc1        $f2, 0x1C($v1)
    ctx->f2.u32l = MEM_W(ctx->r3, 0X1C);
    // 0x800414E0: mul.s       $f2, $f2, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f8.fl);
    // 0x800414E4: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x800414E8: div.s       $f6, $f2, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = DIV_S(ctx->f2.fl, ctx->f0.fl);
    // 0x800414EC: c.eq.s      $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f6.fl == ctx->f18.fl;
    // 0x800414F0: nop

    // 0x800414F4: bc1t        L_80041538
    if (c1cs) {
        // 0x800414F8: nop
    
            goto L_80041538;
    }
    // 0x800414F8: nop

    // 0x800414FC: sub.s       $f4, $f24, $f30
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f4.fl = ctx->f24.fl - ctx->f30.fl;
    // 0x80041500: lwc1        $f16, 0x34($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X34);
    // 0x80041504: sub.s       $f4, $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f4.fl - ctx->f16.fl;
    // 0x80041508: mul.s       $f4, $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8004150C: lwc1        $f18, 0x3C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x80041510: sub.s       $f2, $f18, $f26
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f2.fl = ctx->f18.fl - ctx->f26.fl;
    // 0x80041514: sub.s       $f2, $f2, $f28
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f2.fl = ctx->f2.fl - ctx->f28.fl;
    // 0x80041518: mul.s       $f2, $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f6.fl);
    // 0x8004151C: lwc1        $f16, 0x38($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X38);
    // 0x80041520: sub.s       $f0, $f16, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = ctx->f16.fl - ctx->f20.fl;
    // 0x80041524: sub.s       $f0, $f0, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f22.fl;
    // 0x80041528: mul.s       $f0, $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x8004152C: add.s       $f10, $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x80041530: add.s       $f14, $f14, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f14.fl = ctx->f14.fl + ctx->f2.fl;
    // 0x80041534: add.s       $f12, $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = ctx->f12.fl + ctx->f0.fl;
L_80041538:
    // 0x80041538: lwc1        $f4, 0xC($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0XC);
    // 0x8004153C: mul.s       $f4, $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = MUL_S(ctx->f4.fl, ctx->f8.fl);
    // 0x80041540: lwc1        $f2, 0x10($v1)
    ctx->f2.u32l = MEM_W(ctx->r3, 0X10);
    // 0x80041544: mul.s       $f2, $f2, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f8.fl);
    // 0x80041548: lwc1        $f0, 0x14($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X14);
    // 0x8004154C: mul.s       $f0, $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x80041550: add.s       $f10, $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x80041554: add.s       $f14, $f14, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f14.fl = ctx->f14.fl + ctx->f2.fl;
    // 0x80041558: add.s       $f12, $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = ctx->f12.fl + ctx->f0.fl;
    // 0x8004155C: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
L_80041560:
    // 0x80041560: andi        $v0, $a2, 0xFFFF
    ctx->r2 = ctx->r6 & 0XFFFF;
    // 0x80041564: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80041568: addu        $v0, $v0, $s3
    ctx->r2 = ADD32(ctx->r2, ctx->r19);
    // 0x8004156C: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x80041570: bne         $v0, $zero, L_80041438
    if (ctx->r2 != 0) {
        // 0x80041574: andi        $v0, $a2, 0xFFFF
        ctx->r2 = ctx->r6 & 0XFFFF;
            goto L_80041438;
    }
    // 0x80041574: andi        $v0, $a2, 0xFFFF
    ctx->r2 = ctx->r6 & 0XFFFF;
L_80041578:
    // 0x80041578: lwc1        $f4, 0x10($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X10);
    // 0x8004157C: add.s       $f4, $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x80041580: lwc1        $f18, 0x9C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X9C);
    // 0x80041584: mul.s       $f10, $f4, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f18.fl);
    // 0x80041588: lwc1        $f2, 0x14($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X14);
    // 0x8004158C: add.s       $f2, $f2, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f14.fl;
    // 0x80041590: mul.s       $f14, $f2, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f14.fl = MUL_S(ctx->f2.fl, ctx->f18.fl);
    // 0x80041594: lwc1        $f0, 0x18($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X18);
    // 0x80041598: lwc1        $f16, 0x30($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X30);
    // 0x8004159C: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x800415A0: add.s       $f0, $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f12.fl;
    // 0x800415A4: swc1        $f4, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f4.u32l;
    // 0x800415A8: swc1        $f2, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f2.u32l;
    // 0x800415AC: swc1        $f0, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f0.u32l;
    // 0x800415B0: c.eq.s      $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f16.fl == ctx->f18.fl;
    // 0x800415B4: lwc1        $f16, 0x9C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X9C);
    // 0x800415B8: mul.s       $f12, $f0, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = MUL_S(ctx->f0.fl, ctx->f16.fl);
    // 0x800415BC: bc1t        L_800415E8
    if (c1cs) {
        // 0x800415C0: nop
    
            goto L_800415E8;
    }
    // 0x800415C0: nop

    // 0x800415C4: lwc1        $f18, 0x30($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X30);
    // 0x800415C8: mul.s       $f0, $f10, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f0.fl = MUL_S(ctx->f10.fl, ctx->f18.fl);
    // 0x800415CC: nop

    // 0x800415D0: mul.s       $f2, $f14, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f2.fl = MUL_S(ctx->f14.fl, ctx->f18.fl);
    // 0x800415D4: nop

    // 0x800415D8: mul.s       $f4, $f12, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f12.fl, ctx->f18.fl);
    // 0x800415DC: sub.s       $f10, $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f10.fl - ctx->f0.fl;
    // 0x800415E0: sub.s       $f14, $f14, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f14.fl = ctx->f14.fl - ctx->f2.fl;
    // 0x800415E4: sub.s       $f12, $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f12.fl - ctx->f4.fl;
L_800415E8:
    // 0x800415E8: lwc1        $f2, 0x0($fp)
    ctx->f2.u32l = MEM_W(ctx->r30, 0X0);
    // 0x800415EC: add.s       $f2, $f10, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = ctx->f10.fl + ctx->f2.fl;
    // 0x800415F0: lwc1        $f0, 0x4($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X4);
    // 0x800415F4: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x800415F8: swc1        $f0, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f0.u32l;
    // 0x800415FC: lwc1        $f2, 0x4($fp)
    ctx->f2.u32l = MEM_W(ctx->r30, 0X4);
    // 0x80041600: add.s       $f2, $f14, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = ctx->f14.fl + ctx->f2.fl;
    // 0x80041604: lwc1        $f0, 0x8($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X8);
    // 0x80041608: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x8004160C: swc1        $f0, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f0.u32l;
    // 0x80041610: lwc1        $f0, 0x8($fp)
    ctx->f0.u32l = MEM_W(ctx->r30, 0X8);
    // 0x80041614: add.s       $f0, $f12, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f12.fl + ctx->f0.fl;
    // 0x80041618: lwc1        $f2, 0xC($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8004161C: lhu         $v0, 0x20($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X20);
    // 0x80041620: add.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x80041624: andi        $v0, $v0, 0x40
    ctx->r2 = ctx->r2 & 0X40;
    // 0x80041628: beq         $v0, $zero, L_80041678
    if (ctx->r2 == 0) {
        // 0x8004162C: swc1        $f2, 0xC($s0)
        MEM_W(0XC, ctx->r16) = ctx->f2.u32l;
            goto L_80041678;
    }
    // 0x8004162C: swc1        $f2, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f2.u32l;
    // 0x80041630: lhu         $a0, 0x26($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X26);
    // 0x80041634: jal         0x80040218
    // 0x80041638: nop

    func_80040218(rdram, ctx);
        goto after_4;
    // 0x80041638: nop

    after_4:
    // 0x8004163C: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x80041640: beq         $v0, $s4, L_800418C8
    if (ctx->r2 == ctx->r20) {
        // 0x80041644: addu        $s1, $s2, $zero
        ctx->r17 = ADD32(ctx->r18, 0);
            goto L_800418C8;
    }
    // 0x80041644: addu        $s1, $s2, $zero
    ctx->r17 = ADD32(ctx->r18, 0);
    // 0x80041648: lwc1        $f16, 0x9C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X9C);
    // 0x8004164C: lw          $t0, 0xA8($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XA8);
    // 0x80041650: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x80041654: sw          $s5, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r21;
    // 0x80041658: sw          $s0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r16;
    // 0x8004165C: swc1        $f16, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f16.u32l;
    // 0x80041660: sw          $t0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r8;
    // 0x80041664: lhu         $a0, 0x24($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X24);
    // 0x80041668: jal         0x8003E8DC
    // 0x8004166C: addiu       $a2, $sp, 0x20
    ctx->r6 = ADD32(ctx->r29, 0X20);
    func_8003E8DC(rdram, ctx);
        goto after_5;
    // 0x8004166C: addiu       $a2, $sp, 0x20
    ctx->r6 = ADD32(ctx->r29, 0X20);
    after_5:
    // 0x80041670: j           L_800418C8
    // 0x80041674: addu        $s1, $s2, $zero
    ctx->r17 = ADD32(ctx->r18, 0);
        goto L_800418C8;
    // 0x80041674: addu        $s1, $s2, $zero
    ctx->r17 = ADD32(ctx->r18, 0);
L_80041678:
    // 0x80041678: lwc1        $f8, 0x4($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X4);
    // 0x8004167C: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80041680: lwc1        $f0, -0x5B94($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X5B94);
    // 0x80041684: mul.s       $f8, $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x80041688: lwc1        $f6, 0x8($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8004168C: mul.s       $f6, $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x80041690: lwc1        $f4, 0xC($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XC);
    // 0x80041694: mul.s       $f4, $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x80041698: lhu         $v0, 0x28($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X28);
    // 0x8004169C: lwc1        $f16, 0x9C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X9C);
    // 0x800416A0: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x800416A4: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x800416A8: mul.s       $f0, $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f16.fl);
    // 0x800416AC: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x800416B0: lwc1        $f10, -0x5B90($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X5B90);
    // 0x800416B4: mul.s       $f8, $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x800416B8: nop

    // 0x800416BC: mul.s       $f6, $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x800416C0: nop

    // 0x800416C4: mul.s       $f4, $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f4.fl, ctx->f10.fl);
    // 0x800416C8: lhu         $v0, 0x26($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X26);
    // 0x800416CC: mtc1        $v0, $f2
    ctx->f2.u32l = ctx->r2;
    // 0x800416D0: cvt.s.w     $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    ctx->f2.fl = CVT_S_W(ctx->f2.u32l);
    // 0x800416D4: lhu         $v0, 0x26($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X26);
    // 0x800416D8: add.s       $f0, $f2, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x800416DC: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x800416E0: lwc1        $f18, -0x5B8C($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X5B8C);
    // 0x800416E4: andi        $a2, $v0, 0xFF00
    ctx->r6 = ctx->r2 & 0XFF00;
    // 0x800416E8: c.le.s      $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f18.fl <= ctx->f0.fl;
    // 0x800416EC: trunc.w.s   $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    ctx->f16.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x800416F0: mfc1        $v0, $f16
    ctx->r2 = (int32_t)ctx->f16.u32l;
    // 0x800416F4: sh          $v0, 0x3C($s0)
    MEM_H(0X3C, ctx->r16) = ctx->r2;
    // 0x800416F8: trunc.w.s   $f16, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    ctx->f16.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x800416FC: mfc1        $v0, $f16
    ctx->r2 = (int32_t)ctx->f16.u32l;
    // 0x80041700: sh          $v0, 0x3E($s0)
    MEM_H(0X3E, ctx->r16) = ctx->r2;
    // 0x80041704: trunc.w.s   $f16, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    ctx->f16.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x80041708: mfc1        $v0, $f16
    ctx->r2 = (int32_t)ctx->f16.u32l;
    // 0x8004170C: bc1t        L_80041724
    if (c1cs) {
        // 0x80041710: sh          $v0, 0x40($s0)
        MEM_H(0X40, ctx->r16) = ctx->r2;
            goto L_80041724;
    }
    // 0x80041710: sh          $v0, 0x40($s0)
    MEM_H(0X40, ctx->r16) = ctx->r2;
    // 0x80041714: trunc.w.s   $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    ctx->f16.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x80041718: mfc1        $a0, $f16
    ctx->r4 = (int32_t)ctx->f16.u32l;
    // 0x8004171C: j           L_80041744
    // 0x80041720: sh          $a0, 0x26($s0)
    MEM_H(0X26, ctx->r16) = ctx->r4;
        goto L_80041744;
    // 0x80041720: sh          $a0, 0x26($s0)
    MEM_H(0X26, ctx->r16) = ctx->r4;
L_80041724:
    // 0x80041724: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80041728: lwc1        $f16, -0x5B88($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X5B88);
    // 0x8004172C: sub.s       $f0, $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f16.fl;
    // 0x80041730: lui         $v0, 0x8000
    ctx->r2 = S32(0X8000 << 16);
    // 0x80041734: trunc.w.s   $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    ctx->f18.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x80041738: mfc1        $a0, $f18
    ctx->r4 = (int32_t)ctx->f18.u32l;
    // 0x8004173C: or          $a0, $a0, $v0
    ctx->r4 = ctx->r4 | ctx->r2;
    // 0x80041740: sh          $a0, 0x26($s0)
    MEM_H(0X26, ctx->r16) = ctx->r4;
L_80041744:
    // 0x80041744: andi        $v1, $a0, 0xFF00
    ctx->r3 = ctx->r4 & 0XFF00;
    // 0x80041748: andi        $v0, $a2, 0xFFFF
    ctx->r2 = ctx->r6 & 0XFFFF;
    // 0x8004174C: beq         $v1, $v0, L_800417A8
    if (ctx->r3 == ctx->r2) {
        // 0x80041750: addu        $a1, $a0, $zero
        ctx->r5 = ADD32(ctx->r4, 0);
            goto L_800417A8;
    }
    // 0x80041750: addu        $a1, $a0, $zero
    ctx->r5 = ADD32(ctx->r4, 0);
    // 0x80041754: lhu         $v1, 0x24($s0)
    ctx->r3 = MEM_HU(ctx->r16, 0X24);
    // 0x80041758: andi        $v0, $a1, 0xFFFF
    ctx->r2 = ctx->r5 & 0XFFFF;
    // 0x8004175C: sltu        $v0, $v0, $v1
    ctx->r2 = ctx->r2 < ctx->r3 ? 1 : 0;
    // 0x80041760: bne         $v0, $zero, L_8004178C
    if (ctx->r2 != 0) {
        // 0x80041764: nop
    
            goto L_8004178C;
    }
    // 0x80041764: nop

    // 0x80041768: lhu         $v0, 0x20($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X20);
    // 0x8004176C: andi        $v0, $v0, 0x10
    ctx->r2 = ctx->r2 & 0X10;
    // 0x80041770: beq         $v0, $zero, L_80041784
    if (ctx->r2 == 0) {
        // 0x80041774: addiu       $v0, $v1, -0x100
        ctx->r2 = ADD32(ctx->r3, -0X100);
            goto L_80041784;
    }
    // 0x80041774: addiu       $v0, $v1, -0x100
    ctx->r2 = ADD32(ctx->r3, -0X100);
    // 0x80041778: sh          $v0, 0x26($s0)
    MEM_H(0X26, ctx->r16) = ctx->r2;
    // 0x8004177C: j           L_8004178C
    // 0x80041780: sh          $zero, 0x28($s0)
    MEM_H(0X28, ctx->r16) = 0;
        goto L_8004178C;
    // 0x80041780: sh          $zero, 0x28($s0)
    MEM_H(0X28, ctx->r16) = 0;
L_80041784:
    // 0x80041784: subu        $v0, $a0, $v1
    ctx->r2 = SUB32(ctx->r4, ctx->r3);
    // 0x80041788: sh          $v0, 0x26($s0)
    MEM_H(0X26, ctx->r16) = ctx->r2;
L_8004178C:
    // 0x8004178C: lhu         $v0, 0x26($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X26);
    // 0x80041790: lw          $v1, 0x64($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X64);
    // 0x80041794: srl         $v0, $v0, 8
    ctx->r2 = S32(U32(ctx->r2) >> 8);
    // 0x80041798: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x8004179C: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800417A0: lhu         $v0, 0x0($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X0);
    // 0x800417A4: sh          $v0, 0x46($s0)
    MEM_H(0X46, ctx->r16) = ctx->r2;
L_800417A8:
    // 0x800417A8: lhu         $v0, 0x2E($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X2E);
    // 0x800417AC: lwc1        $f16, 0x9C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X9C);
    // 0x800417B0: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x800417B4: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x800417B8: mul.s       $f0, $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f16.fl);
    // 0x800417BC: lhu         $v0, 0x2C($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X2C);
    // 0x800417C0: mtc1        $v0, $f2
    ctx->f2.u32l = ctx->r2;
    // 0x800417C4: cvt.s.w     $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    ctx->f2.fl = CVT_S_W(ctx->f2.u32l);
    // 0x800417C8: lhu         $v0, 0x2C($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X2C);
    // 0x800417CC: add.s       $f0, $f2, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x800417D0: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x800417D4: lwc1        $f18, -0x5B84($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X5B84);
    // 0x800417D8: c.le.s      $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f18.fl <= ctx->f0.fl;
    // 0x800417DC: nop

    // 0x800417E0: bc1t        L_800417F8
    if (c1cs) {
        // 0x800417E4: andi        $a2, $v0, 0xFF00
        ctx->r6 = ctx->r2 & 0XFF00;
            goto L_800417F8;
    }
    // 0x800417E4: andi        $a2, $v0, 0xFF00
    ctx->r6 = ctx->r2 & 0XFF00;
    // 0x800417E8: trunc.w.s   $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    ctx->f16.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800417EC: mfc1        $v1, $f16
    ctx->r3 = (int32_t)ctx->f16.u32l;
    // 0x800417F0: j           L_80041818
    // 0x800417F4: sh          $v1, 0x2C($s0)
    MEM_H(0X2C, ctx->r16) = ctx->r3;
        goto L_80041818;
    // 0x800417F4: sh          $v1, 0x2C($s0)
    MEM_H(0X2C, ctx->r16) = ctx->r3;
L_800417F8:
    // 0x800417F8: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x800417FC: lwc1        $f16, -0x5B80($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X5B80);
    // 0x80041800: sub.s       $f0, $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f16.fl;
    // 0x80041804: lui         $v0, 0x8000
    ctx->r2 = S32(0X8000 << 16);
    // 0x80041808: trunc.w.s   $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    ctx->f18.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x8004180C: mfc1        $v1, $f18
    ctx->r3 = (int32_t)ctx->f18.u32l;
    // 0x80041810: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x80041814: sh          $v1, 0x2C($s0)
    MEM_H(0X2C, ctx->r16) = ctx->r3;
L_80041818:
    // 0x80041818: addu        $a0, $v1, $zero
    ctx->r4 = ADD32(ctx->r3, 0);
    // 0x8004181C: andi        $v1, $v1, 0xFF00
    ctx->r3 = ctx->r3 & 0XFF00;
    // 0x80041820: andi        $v0, $a2, 0xFFFF
    ctx->r2 = ctx->r6 & 0XFFFF;
    // 0x80041824: beq         $v1, $v0, L_80041848
    if (ctx->r3 == ctx->r2) {
        // 0x80041828: srl         $v0, $a0, 6
        ctx->r2 = S32(U32(ctx->r4) >> 6);
            goto L_80041848;
    }
    // 0x80041828: srl         $v0, $a0, 6
    ctx->r2 = S32(U32(ctx->r4) >> 6);
    // 0x8004182C: lw          $v1, 0x68($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X68);
    // 0x80041830: andi        $v0, $v0, 0x3FC
    ctx->r2 = ctx->r2 & 0X3FC;
    // 0x80041834: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80041838: lwl         $t1, 0x0($v0)
    ctx->r9 = do_lwl(rdram, ctx->r9, ctx->r2, 0X0);
    // 0x8004183C: lwr         $t1, 0x3($v0)
    ctx->r9 = do_lwr(rdram, ctx->r9, ctx->r2, 0X3);
    // 0x80041840: swl         $t1, 0x60($s0)
    do_swl(rdram, 0X60, ctx->r16, ctx->r9);
    // 0x80041844: swr         $t1, 0x63($s0)
    do_swr(rdram, 0X63, ctx->r16, ctx->r9);
L_80041848:
    // 0x80041848: lh          $v0, 0x30($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X30);
    // 0x8004184C: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80041850: lwc1        $f2, -0x5B7C($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X5B7C);
    // 0x80041854: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x80041858: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x8004185C: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x80041860: lwc1        $f16, 0x9C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X9C);
    // 0x80041864: mul.s       $f0, $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f16.fl);
    // 0x80041868: lwc1        $f2, 0x54($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X54);
    // 0x8004186C: add.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x80041870: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80041874: lwc1        $f0, -0x5B78($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X5B78);
    // 0x80041878: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x8004187C: nop

    // 0x80041880: bc1f        L_8004188C
    if (!c1cs) {
        // 0x80041884: swc1        $f2, 0x54($s0)
        MEM_W(0X54, ctx->r16) = ctx->f2.u32l;
            goto L_8004188C;
    }
    // 0x80041884: swc1        $f2, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f2.u32l;
    // 0x80041888: swc1        $f0, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f0.u32l;
L_8004188C:
    // 0x8004188C: lwc1        $f0, 0x54($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X54);
    // 0x80041890: swc1        $f0, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f0.u32l;
    // 0x80041894: lw          $t0, 0xA4($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XA4);
    // 0x80041898: beq         $t0, $zero, L_800418C8
    if (ctx->r8 == 0) {
        // 0x8004189C: addu        $s1, $s2, $zero
        ctx->r17 = ADD32(ctx->r18, 0);
            goto L_800418C8;
    }
    // 0x8004189C: addu        $s1, $s2, $zero
    ctx->r17 = ADD32(ctx->r18, 0);
    // 0x800418A0: lw          $v1, 0x0($t0)
    ctx->r3 = MEM_W(ctx->r8, 0X0);
    // 0x800418A4: beq         $v1, $zero, L_800418B4
    if (ctx->r3 == 0) {
        // 0x800418A8: sw          $v1, 0x34($s0)
        MEM_W(0X34, ctx->r16) = ctx->r3;
            goto L_800418B4;
    }
    // 0x800418A8: sw          $v1, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->r3;
    // 0x800418AC: addiu       $v0, $s0, 0x34
    ctx->r2 = ADD32(ctx->r16, 0X34);
    // 0x800418B0: sw          $v0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r2;
L_800418B4:
    // 0x800418B4: sw          $zero, 0x38($s0)
    MEM_W(0X38, ctx->r16) = 0;
    // 0x800418B8: lw          $t1, 0xA4($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XA4);
    // 0x800418BC: addiu       $v0, $s0, 0x34
    ctx->r2 = ADD32(ctx->r16, 0X34);
    // 0x800418C0: sw          $v0, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r2;
L_800418C4:
    // 0x800418C4: addu        $s1, $s2, $zero
    ctx->r17 = ADD32(ctx->r18, 0);
L_800418C8:
    // 0x800418C8: andi        $v0, $s1, 0xFFFF
    ctx->r2 = ctx->r17 & 0XFFFF;
    // 0x800418CC: bne         $v0, $s4, L_800412A4
    if (ctx->r2 != ctx->r20) {
        // 0x800418D0: andi        $v1, $s1, 0xFFFF
        ctx->r3 = ctx->r17 & 0XFFFF;
            goto L_800412A4;
    }
    // 0x800418D0: andi        $v1, $s1, 0xFFFF
    ctx->r3 = ctx->r17 & 0XFFFF;
L_800418D4:
    // 0x800418D4: lw          $ra, 0x64($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X64);
    // 0x800418D8: lw          $fp, 0x60($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X60);
    // 0x800418DC: lw          $s7, 0x5C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X5C);
    // 0x800418E0: lw          $s6, 0x58($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X58);
    // 0x800418E4: lw          $s5, 0x54($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X54);
    // 0x800418E8: lw          $s4, 0x50($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X50);
    // 0x800418EC: lw          $s3, 0x4C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X4C);
    // 0x800418F0: lw          $s2, 0x48($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X48);
    // 0x800418F4: lw          $s1, 0x44($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X44);
    // 0x800418F8: lw          $s0, 0x40($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X40);
    // 0x800418FC: ldc1        $f30, 0x90($sp)
    CHECK_FR(ctx, 30);
    ctx->f30.u64 = LD(ctx->r29, 0X90);
    // 0x80041900: ldc1        $f28, 0x88($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0X88);
    // 0x80041904: ldc1        $f26, 0x80($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X80);
    // 0x80041908: ldc1        $f24, 0x78($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X78);
    // 0x8004190C: ldc1        $f22, 0x70($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X70);
    // 0x80041910: ldc1        $f20, 0x68($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X68);
    // 0x80041914: jr          $ra
    // 0x80041918: addiu       $sp, $sp, 0x98
    ctx->r29 = ADD32(ctx->r29, 0X98);
    return;
    // 0x80041918: addiu       $sp, $sp, 0x98
    ctx->r29 = ADD32(ctx->r29, 0X98);
;}
RECOMP_FUNC void func_8004191C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8004191C: addiu       $sp, $sp, -0xB0
    ctx->r29 = ADD32(ctx->r29, -0XB0);
    // 0x80041920: sw          $ra, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->r31;
    // 0x80041924: sw          $s2, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->r18;
    // 0x80041928: sw          $s1, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->r17;
    // 0x8004192C: sw          $s0, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->r16;
    // 0x80041930: sdc1        $f20, 0xA8($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0XA8, ctx->r29);
    // 0x80041934: jal         0x8004015C
    // 0x80041938: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    func_8004015C(rdram, ctx);
        goto after_0;
    // 0x80041938: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    after_0:
    // 0x8004193C: beq         $v0, $zero, L_80041B2C
    if (ctx->r2 == 0) {
        // 0x80041940: addiu       $a0, $sp, 0x3C
        ctx->r4 = ADD32(ctx->r29, 0X3C);
            goto L_80041B2C;
    }
    // 0x80041940: addiu       $a0, $sp, 0x3C
    ctx->r4 = ADD32(ctx->r29, 0X3C);
    // 0x80041944: addiu       $a1, $v0, 0xC
    ctx->r5 = ADD32(ctx->r2, 0XC);
    // 0x80041948: lw          $t0, 0x0($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X0);
    // 0x8004194C: lw          $t1, 0x4($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X4);
    // 0x80041950: lw          $t2, 0x8($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X8);
    // 0x80041954: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    // 0x80041958: sw          $t1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r9;
    // 0x8004195C: sw          $t2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r10;
    // 0x80041960: lw          $t0, 0xC($v0)
    ctx->r8 = MEM_W(ctx->r2, 0XC);
    // 0x80041964: lw          $t1, 0x10($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X10);
    // 0x80041968: lw          $t2, 0x14($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X14);
    // 0x8004196C: sw          $t0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r8;
    // 0x80041970: sw          $t1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r9;
    // 0x80041974: sw          $t2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r10;
    // 0x80041978: jal         0x80019548
    // 0x8004197C: addiu       $a2, $v0, 0x18
    ctx->r6 = ADD32(ctx->r2, 0X18);
    func_80019548(rdram, ctx);
        goto after_1;
    // 0x8004197C: addiu       $a2, $v0, 0x18
    ctx->r6 = ADD32(ctx->r2, 0X18);
    after_1:
    // 0x80041980: lui         $a0, 0x8004
    ctx->r4 = S32(0X8004 << 16);
    // 0x80041984: addiu       $a0, $a0, 0x3EC
    ctx->r4 = ADD32(ctx->r4, 0X3EC);
    // 0x80041988: addiu       $a1, $sp, 0x10
    ctx->r5 = ADD32(ctx->r29, 0X10);
    // 0x8004198C: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80041990: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x80041994: lw          $v1, 0xC08($v0)
    ctx->r3 = MEM_W(ctx->r2, 0XC08);
    // 0x80041998: addiu       $v0, $zero, 0xC
    ctx->r2 = ADD32(0, 0XC);
    // 0x8004199C: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
    // 0x800419A0: sh          $v0, 0x70($a1)
    MEM_H(0X70, ctx->r5) = ctx->r2;
    // 0x800419A4: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800419A8: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x800419AC: lwc1        $f0, -0x5B74($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X5B74);
    // 0x800419B0: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x800419B4: lwc1        $f2, -0x5B70($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X5B70);
    // 0x800419B8: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x800419BC: lwc1        $f20, -0x5B6C($at)
    ctx->f20.u32l = MEM_W(ctx->r1, -0X5B6C);
    // 0x800419C0: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x800419C4: lwc1        $f4, -0x5B68($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X5B68);
    // 0x800419C8: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x800419CC: lwc1        $f6, -0x5B64($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X5B64);
    // 0x800419D0: addiu       $a3, $zero, 0xF
    ctx->r7 = ADD32(0, 0XF);
    // 0x800419D4: sw          $zero, 0x18($a1)
    MEM_W(0X18, ctx->r5) = 0;
    // 0x800419D8: sw          $zero, 0x14($a1)
    MEM_W(0X14, ctx->r5) = 0;
    // 0x800419DC: sw          $zero, 0x10($a1)
    MEM_W(0X10, ctx->r5) = 0;
    // 0x800419E0: sw          $zero, 0x1C($a1)
    MEM_W(0X1C, ctx->r5) = 0;
    // 0x800419E4: sw          $zero, 0x38($a1)
    MEM_W(0X38, ctx->r5) = 0;
    // 0x800419E8: sh          $zero, 0x3E($a1)
    MEM_H(0X3E, ctx->r5) = 0;
    // 0x800419EC: sh          $zero, 0x3C($a1)
    MEM_H(0X3C, ctx->r5) = 0;
    // 0x800419F0: sw          $zero, 0x44($a1)
    MEM_W(0X44, ctx->r5) = 0;
    // 0x800419F4: sw          $zero, 0x48($a1)
    MEM_W(0X48, ctx->r5) = 0;
    // 0x800419F8: sw          $zero, 0x50($a1)
    MEM_W(0X50, ctx->r5) = 0;
    // 0x800419FC: sw          $zero, 0x54($a1)
    MEM_W(0X54, ctx->r5) = 0;
    // 0x80041A00: sw          $zero, 0x68($a1)
    MEM_W(0X68, ctx->r5) = 0;
    // 0x80041A04: sb          $zero, 0x6C($a1)
    MEM_B(0X6C, ctx->r5) = 0;
    // 0x80041A08: sb          $zero, 0x6D($a1)
    MEM_B(0X6D, ctx->r5) = 0;
    // 0x80041A0C: sh          $zero, 0x72($a1)
    MEM_H(0X72, ctx->r5) = 0;
    // 0x80041A10: sh          $zero, 0x74($a1)
    MEM_H(0X74, ctx->r5) = 0;
    // 0x80041A14: sh          $s0, 0x7C($a1)
    MEM_H(0X7C, ctx->r5) = ctx->r16;
    // 0x80041A18: sw          $zero, 0x78($a1)
    MEM_W(0X78, ctx->r5) = 0;
    // 0x80041A1C: swc1        $f0, 0x40($a1)
    MEM_W(0X40, ctx->r5) = ctx->f0.u32l;
    // 0x80041A20: swc1        $f2, 0x4C($a1)
    MEM_W(0X4C, ctx->r5) = ctx->f2.u32l;
    // 0x80041A24: swc1        $f20, 0x58($a1)
    MEM_W(0X58, ctx->r5) = ctx->f20.u32l;
    // 0x80041A28: swc1        $f4, 0x5C($a1)
    MEM_W(0X5C, ctx->r5) = ctx->f4.u32l;
    // 0x80041A2C: sw          $v1, 0x64($a1)
    MEM_W(0X64, ctx->r5) = ctx->r3;
    // 0x80041A30: sw          $v1, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r3;
    // 0x80041A34: lw          $v1, 0xC04($v0)
    ctx->r3 = MEM_W(ctx->r2, 0XC04);
    // 0x80041A38: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80041A3C: lwc1        $f0, -0x5B60($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X5B60);
    // 0x80041A40: addiu       $v0, $zero, 0x6
    ctx->r2 = ADD32(0, 0X6);
    // 0x80041A44: sb          $v0, 0x7C($sp)
    MEM_B(0X7C, ctx->r29) = ctx->r2;
    // 0x80041A48: addiu       $v0, $zero, 0x10
    ctx->r2 = ADD32(0, 0X10);
    // 0x80041A4C: sb          $v0, 0x7D($sp)
    MEM_B(0X7D, ctx->r29) = ctx->r2;
    // 0x80041A50: addiu       $v0, $zero, 0x19
    ctx->r2 = ADD32(0, 0X19);
    // 0x80041A54: sh          $v0, 0x80($sp)
    MEM_H(0X80, ctx->r29) = ctx->r2;
    // 0x80041A58: addiu       $v0, $zero, 0x100
    ctx->r2 = ADD32(0, 0X100);
    // 0x80041A5C: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    // 0x80041A60: sh          $v0, 0x82($sp)
    MEM_H(0X82, ctx->r29) = ctx->r2;
    // 0x80041A64: sw          $v1, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r3;
    // 0x80041A68: swc1        $f20, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f20.u32l;
    // 0x80041A6C: lhu         $v0, 0x8C($sp)
    ctx->r2 = MEM_HU(ctx->r29, 0X8C);
    // 0x80041A70: addiu       $v1, $zero, 0x168
    ctx->r3 = ADD32(0, 0X168);
    // 0x80041A74: swc1        $f0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f0.u32l;
    // 0x80041A78: sh          $v1, 0x4C($sp)
    MEM_H(0X4C, ctx->r29) = ctx->r3;
    // 0x80041A7C: ori         $v0, $v0, 0x2
    ctx->r2 = ctx->r2 | 0X2;
    // 0x80041A80: jal         0x8003FFEC
    // 0x80041A84: sh          $v0, 0x8C($sp)
    MEM_H(0X8C, ctx->r29) = ctx->r2;
    func_8003FFEC(rdram, ctx);
        goto after_2;
    // 0x80041A84: sh          $v0, 0x8C($sp)
    MEM_H(0X8C, ctx->r29) = ctx->r2;
    after_2:
    // 0x80041A88: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80041A8C: addiu       $v1, $a0, 0xBE0
    ctx->r3 = ADD32(ctx->r4, 0XBE0);
    // 0x80041A90: sb          $s0, 0x20($v1)
    MEM_B(0X20, ctx->r3) = ctx->r16;
    // 0x80041A94: andi        $s0, $v0, 0xFFFF
    ctx->r16 = ctx->r2 & 0XFFFF;
    // 0x80041A98: ori         $s1, $zero, 0xFFFF
    ctx->r17 = 0 | 0XFFFF;
    // 0x80041A9C: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80041AA0: lwc1        $f0, -0x5B5C($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X5B5C);
    // 0x80041AA4: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80041AA8: lwc1        $f2, -0x5B58($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X5B58);
    // 0x80041AAC: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80041AB0: lwc1        $f4, -0x5B54($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X5B54);
    // 0x80041AB4: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80041AB8: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x80041ABC: sw          $zero, 0xC($v1)
    MEM_W(0XC, ctx->r3) = 0;
    // 0x80041AC0: sw          $zero, 0x10($v1)
    MEM_W(0X10, ctx->r3) = 0;
    // 0x80041AC4: sw          $zero, 0x14($v1)
    MEM_W(0X14, ctx->r3) = 0;
    // 0x80041AC8: swc1        $f20, 0x1C($v1)
    MEM_W(0X1C, ctx->r3) = ctx->f20.u32l;
    // 0x80041ACC: sw          $zero, 0x90($sp)
    MEM_W(0X90, ctx->r29) = 0;
    // 0x80041AD0: swc1        $f0, 0xBE0($a0)
    MEM_W(0XBE0, ctx->r4) = ctx->f0.u32l;
    // 0x80041AD4: swc1        $f2, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->f2.u32l;
    // 0x80041AD8: swc1        $f4, 0x18($v1)
    MEM_W(0X18, ctx->r3) = ctx->f4.u32l;
    // 0x80041ADC: lhu         $a1, 0x7E72($v0)
    ctx->r5 = MEM_HU(ctx->r2, 0X7E72);
    // 0x80041AE0: beq         $s0, $s1, L_80041B2C
    if (ctx->r16 == ctx->r17) {
        // 0x80041AE4: andi        $s2, $a1, 0xFFFF
        ctx->r18 = ctx->r5 & 0XFFFF;
            goto L_80041B2C;
    }
    // 0x80041AE4: andi        $s2, $a1, 0xFFFF
    ctx->r18 = ctx->r5 & 0XFFFF;
    // 0x80041AE8: beq         $s2, $s1, L_80041B2C
    if (ctx->r18 == ctx->r17) {
        // 0x80041AEC: addu        $a0, $s0, $zero
        ctx->r4 = ADD32(ctx->r16, 0);
            goto L_80041B2C;
    }
    // 0x80041AEC: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x80041AF0: addiu       $a1, $zero, 0x1000
    ctx->r5 = ADD32(0, 0X1000);
    // 0x80041AF4: jal         0x8003E8DC
    // 0x80041AF8: addiu       $a2, $sp, 0x90
    ctx->r6 = ADD32(ctx->r29, 0X90);
    func_8003E8DC(rdram, ctx);
        goto after_3;
    // 0x80041AF8: addiu       $a2, $sp, 0x90
    ctx->r6 = ADD32(ctx->r29, 0X90);
    after_3:
    // 0x80041AFC: lw          $v0, 0x90($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X90);
    // 0x80041B00: beq         $v0, $zero, L_80041B2C
    if (ctx->r2 == 0) {
        // 0x80041B04: nop
    
            goto L_80041B2C;
    }
    // 0x80041B04: nop

    // 0x80041B08: lhu         $v0, 0x140($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X140);
    // 0x80041B0C: bne         $v0, $s1, L_80041B24
    if (ctx->r2 != ctx->r17) {
        // 0x80041B10: addu        $a0, $s0, $zero
        ctx->r4 = ADD32(ctx->r16, 0);
            goto L_80041B24;
    }
    // 0x80041B10: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x80041B14: jal         0x80040188
    // 0x80041B18: addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    func_80040188(rdram, ctx);
        goto after_4;
    // 0x80041B18: addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    after_4:
    // 0x80041B1C: lw          $v1, 0x90($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X90);
    // 0x80041B20: sh          $v0, 0x140($v1)
    MEM_H(0X140, ctx->r3) = ctx->r2;
L_80041B24:
    // 0x80041B24: lw          $v0, 0x90($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X90);
    // 0x80041B28: sw          $zero, 0x15C($v0)
    MEM_W(0X15C, ctx->r2) = 0;
L_80041B2C:
    // 0x80041B2C: lw          $ra, 0xA4($sp)
    ctx->r31 = MEM_W(ctx->r29, 0XA4);
    // 0x80041B30: lw          $s2, 0xA0($sp)
    ctx->r18 = MEM_W(ctx->r29, 0XA0);
    // 0x80041B34: lw          $s1, 0x9C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X9C);
    // 0x80041B38: lw          $s0, 0x98($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X98);
    // 0x80041B3C: ldc1        $f20, 0xA8($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0XA8);
    // 0x80041B40: jr          $ra
    // 0x80041B44: addiu       $sp, $sp, 0xB0
    ctx->r29 = ADD32(ctx->r29, 0XB0);
    return;
    // 0x80041B44: addiu       $sp, $sp, 0xB0
    ctx->r29 = ADD32(ctx->r29, 0XB0);
;}
RECOMP_FUNC void func_80041B48(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80041B48: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80041B4C: lw          $a0, 0xBD0($v0)
    ctx->r4 = MEM_W(ctx->r2, 0XBD0);
    // 0x80041B50: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80041B54: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x80041B58: jal         0x80001C98
    // 0x80041B5C: nop

    rs_free(rdram, ctx);
        goto after_0;
    // 0x80041B5C: nop

    after_0:
    // 0x80041B60: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80041B64: lw          $a0, 0xC08($v0)
    ctx->r4 = MEM_W(ctx->r2, 0XC08);
    // 0x80041B68: jal         0x80001C98
    // 0x80041B6C: nop

    rs_free(rdram, ctx);
        goto after_1;
    // 0x80041B6C: nop

    after_1:
    // 0x80041B70: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80041B74: lw          $a0, 0xC04($v0)
    ctx->r4 = MEM_W(ctx->r2, 0XC04);
    // 0x80041B78: jal         0x80001C98
    // 0x80041B7C: nop

    rs_free(rdram, ctx);
        goto after_2;
    // 0x80041B7C: nop

    after_2:
    // 0x80041B80: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x80041B84: jr          $ra
    // 0x80041B88: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80041B88: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_80041B8C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80041B8C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80041B90: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x80041B94: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x80041B98: addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    // 0x80041B9C: beq         $a2, $zero, L_80041BEC
    if (ctx->r6 == 0) {
        // 0x80041BA0: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_80041BEC;
    }
    // 0x80041BA0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80041BA4: addiu       $a0, $s0, 0x2C
    ctx->r4 = ADD32(ctx->r16, 0X2C);
    // 0x80041BA8: addiu       $a1, $a2, 0xC
    ctx->r5 = ADD32(ctx->r6, 0XC);
    // 0x80041BAC: lw          $a3, 0x0($a2)
    ctx->r7 = MEM_W(ctx->r6, 0X0);
    // 0x80041BB0: lw          $t0, 0x4($a2)
    ctx->r8 = MEM_W(ctx->r6, 0X4);
    // 0x80041BB4: lw          $t1, 0x8($a2)
    ctx->r9 = MEM_W(ctx->r6, 0X8);
    // 0x80041BB8: sw          $a3, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r7;
    // 0x80041BBC: sw          $t0, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r8;
    // 0x80041BC0: sw          $t1, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r9;
    // 0x80041BC4: lw          $a3, 0xC($a2)
    ctx->r7 = MEM_W(ctx->r6, 0XC);
    // 0x80041BC8: lw          $t0, 0x10($a2)
    ctx->r8 = MEM_W(ctx->r6, 0X10);
    // 0x80041BCC: lw          $t1, 0x14($a2)
    ctx->r9 = MEM_W(ctx->r6, 0X14);
    // 0x80041BD0: sw          $a3, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->r7;
    // 0x80041BD4: sw          $t0, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->r8;
    // 0x80041BD8: sw          $t1, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->r9;
    // 0x80041BDC: jal         0x80019548
    // 0x80041BE0: addiu       $a2, $a2, 0x18
    ctx->r6 = ADD32(ctx->r6, 0X18);
    func_80019548(rdram, ctx);
        goto after_0;
    // 0x80041BE0: addiu       $a2, $a2, 0x18
    ctx->r6 = ADD32(ctx->r6, 0X18);
    after_0:
    // 0x80041BE4: j           L_80041C10
    // 0x80041BE8: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
        goto L_80041C10;
    // 0x80041BE8: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
L_80041BEC:
    // 0x80041BEC: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80041BF0: lwc1        $f0, -0x5B50($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X5B50);
    // 0x80041BF4: sw          $zero, 0x20($s0)
    MEM_W(0X20, ctx->r16) = 0;
    // 0x80041BF8: sw          $zero, 0x24($s0)
    MEM_W(0X24, ctx->r16) = 0;
    // 0x80041BFC: sw          $zero, 0x30($s0)
    MEM_W(0X30, ctx->r16) = 0;
    // 0x80041C00: sw          $zero, 0x34($s0)
    MEM_W(0X34, ctx->r16) = 0;
    // 0x80041C04: swc1        $f0, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->f0.u32l;
    // 0x80041C08: swc1        $f0, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f0.u32l;
    // 0x80041C0C: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
L_80041C10:
    // 0x80041C10: lw          $v1, 0xC08($v0)
    ctx->r3 = MEM_W(ctx->r2, 0XC08);
    // 0x80041C14: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80041C18: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80041C1C: lwc1        $f2, -0x5B4C($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X5B4C);
    // 0x80041C20: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80041C24: lwc1        $f4, -0x5B48($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X5B48);
    // 0x80041C28: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80041C2C: lwc1        $f6, -0x5B44($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X5B44);
    // 0x80041C30: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80041C34: lwc1        $f8, -0x5B40($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X5B40);
    // 0x80041C38: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80041C3C: lwc1        $f10, -0x5B3C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X5B3C);
    // 0x80041C40: addiu       $v0, $zero, 0xC
    ctx->r2 = ADD32(0, 0XC);
    // 0x80041C44: sh          $v0, 0x70($s0)
    MEM_H(0X70, ctx->r16) = ctx->r2;
    // 0x80041C48: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80041C4C: sh          $zero, 0x3E($s0)
    MEM_H(0X3E, ctx->r16) = 0;
    // 0x80041C50: sh          $zero, 0x3C($s0)
    MEM_H(0X3C, ctx->r16) = 0;
    // 0x80041C54: sw          $zero, 0x68($s0)
    MEM_W(0X68, ctx->r16) = 0;
    // 0x80041C58: sb          $zero, 0x6C($s0)
    MEM_B(0X6C, ctx->r16) = 0;
    // 0x80041C5C: sb          $zero, 0x6D($s0)
    MEM_B(0X6D, ctx->r16) = 0;
    // 0x80041C60: sh          $zero, 0x72($s0)
    MEM_H(0X72, ctx->r16) = 0;
    // 0x80041C64: sh          $zero, 0x74($s0)
    MEM_H(0X74, ctx->r16) = 0;
    // 0x80041C68: sh          $v0, 0x7C($s0)
    MEM_H(0X7C, ctx->r16) = ctx->r2;
    // 0x80041C6C: sw          $zero, 0x78($s0)
    MEM_W(0X78, ctx->r16) = 0;
    // 0x80041C70: swc1        $f0, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f0.u32l;
    // 0x80041C74: swc1        $f0, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f0.u32l;
    // 0x80041C78: swc1        $f0, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f0.u32l;
    // 0x80041C7C: swc1        $f0, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f0.u32l;
    // 0x80041C80: swc1        $f0, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->f0.u32l;
    // 0x80041C84: swc1        $f2, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->f2.u32l;
    // 0x80041C88: swc1        $f0, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->f0.u32l;
    // 0x80041C8C: swc1        $f0, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->f0.u32l;
    // 0x80041C90: swc1        $f4, 0x4C($s0)
    MEM_W(0X4C, ctx->r16) = ctx->f4.u32l;
    // 0x80041C94: swc1        $f0, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->f0.u32l;
    // 0x80041C98: swc1        $f0, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f0.u32l;
    // 0x80041C9C: swc1        $f6, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f6.u32l;
    // 0x80041CA0: swc1        $f8, 0x5C($s0)
    MEM_W(0X5C, ctx->r16) = ctx->f8.u32l;
    // 0x80041CA4: sw          $v1, 0x64($s0)
    MEM_W(0X64, ctx->r16) = ctx->r3;
    // 0x80041CA8: swc1        $f10, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f10.u32l;
    // 0x80041CAC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80041CB0: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x80041CB4: jr          $ra
    // 0x80041CB8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80041CB8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_80041CBC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80041CBC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80041CC0: addu        $a1, $a0, $zero
    ctx->r5 = ADD32(ctx->r4, 0);
    // 0x80041CC4: lui         $a0, 0x8004
    ctx->r4 = S32(0X8004 << 16);
    // 0x80041CC8: addiu       $a0, $a0, 0x3EC
    ctx->r4 = ADD32(ctx->r4, 0X3EC);
    // 0x80041CCC: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x80041CD0: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x80041CD4: jal         0x8003FFEC
    // 0x80041CD8: addiu       $a3, $zero, 0xF
    ctx->r7 = ADD32(0, 0XF);
    func_8003FFEC(rdram, ctx);
        goto after_0;
    // 0x80041CD8: addiu       $a3, $zero, 0xF
    ctx->r7 = ADD32(0, 0XF);
    after_0:
    // 0x80041CDC: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x80041CE0: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x80041CE4: jr          $ra
    // 0x80041CE8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80041CE8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_80041CEC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80041CEC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80041CF0: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x80041CF4: jal         0x8003ED74
    // 0x80041CF8: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    func_8003ED74(rdram, ctx);
        goto after_0;
    // 0x80041CF8: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    after_0:
    // 0x80041CFC: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x80041D00: jr          $ra
    // 0x80041D04: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80041D04: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_80041D08(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80041D08: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80041D0C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80041D10: addu        $s0, $a1, $zero
    ctx->r16 = ADD32(ctx->r5, 0);
    // 0x80041D14: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    // 0x80041D18: ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
    // 0x80041D1C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80041D20: beq         $a0, $v0, L_80041D7C
    if (ctx->r4 == ctx->r2) {
        // 0x80041D24: sw          $zero, 0x10($sp)
        MEM_W(0X10, ctx->r29) = 0;
            goto L_80041D7C;
    }
    // 0x80041D24: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80041D28: addiu       $a1, $zero, 0x1000
    ctx->r5 = ADD32(0, 0X1000);
    // 0x80041D2C: jal         0x8003E8DC
    // 0x80041D30: addiu       $a2, $sp, 0x10
    ctx->r6 = ADD32(ctx->r29, 0X10);
    func_8003E8DC(rdram, ctx);
        goto after_0;
    // 0x80041D30: addiu       $a2, $sp, 0x10
    ctx->r6 = ADD32(ctx->r29, 0X10);
    after_0:
    // 0x80041D34: lw          $v0, 0x10($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X10);
    // 0x80041D38: beq         $v0, $zero, L_80041D7C
    if (ctx->r2 == 0) {
        // 0x80041D3C: nop
    
            goto L_80041D7C;
    }
    // 0x80041D3C: nop

    // 0x80041D40: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x80041D44: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x80041D48: addu        $a2, $v0, $zero
    ctx->r6 = ADD32(ctx->r2, 0);
    // 0x80041D4C: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
L_80041D50:
    // 0x80041D50: lw          $v0, 0x134($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X134);
    // 0x80041D54: bnel        $v0, $zero, L_80041D6C
    if (ctx->r2 != 0) {
        // 0x80041D58: addiu       $a1, $a1, 0x4
        ctx->r5 = ADD32(ctx->r5, 0X4);
            goto L_80041D6C;
    }
    goto skip_0;
    // 0x80041D58: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    skip_0:
    // 0x80041D5C: addu        $v0, $a2, $a1
    ctx->r2 = ADD32(ctx->r6, ctx->r5);
    // 0x80041D60: sw          $s0, 0x134($v1)
    MEM_W(0X134, ctx->r3) = ctx->r16;
    // 0x80041D64: j           L_80041D7C
    // 0x80041D68: sw          $zero, 0x134($v0)
    MEM_W(0X134, ctx->r2) = 0;
        goto L_80041D7C;
    // 0x80041D68: sw          $zero, 0x134($v0)
    MEM_W(0X134, ctx->r2) = 0;
L_80041D6C:
    // 0x80041D6C: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x80041D70: slti        $v0, $a0, 0x2
    ctx->r2 = SIGNED(ctx->r4) < 0X2 ? 1 : 0;
    // 0x80041D74: bne         $v0, $zero, L_80041D50
    if (ctx->r2 != 0) {
        // 0x80041D78: addiu       $v1, $v1, 0x4
        ctx->r3 = ADD32(ctx->r3, 0X4);
            goto L_80041D50;
    }
    // 0x80041D78: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
L_80041D7C:
    // 0x80041D7C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80041D80: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80041D84: jr          $ra
    // 0x80041D88: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80041D88: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_80041D8C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80041D8C: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80041D90: sdc1        $f20, 0x30($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X30, ctx->r29);
    // 0x80041D94: mtc1        $a3, $f20
    ctx->f20.u32l = ctx->r7;
    // 0x80041D98: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x80041D9C: addu        $s3, $a2, $zero
    ctx->r19 = ADD32(ctx->r6, 0);
    // 0x80041DA0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80041DA4: andi        $s0, $a0, 0xFFFF
    ctx->r16 = ctx->r4 & 0XFFFF;
    // 0x80041DA8: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80041DAC: ori         $s1, $zero, 0xFFFF
    ctx->r17 = 0 | 0XFFFF;
    // 0x80041DB0: sw          $ra, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r31;
    // 0x80041DB4: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80041DB8: beq         $s0, $s1, L_80041E2C
    if (ctx->r16 == ctx->r17) {
        // 0x80041DBC: sw          $zero, 0x10($sp)
        MEM_W(0X10, ctx->r29) = 0;
            goto L_80041E2C;
    }
    // 0x80041DBC: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80041DC0: andi        $s2, $a1, 0xFFFF
    ctx->r18 = ctx->r5 & 0XFFFF;
    // 0x80041DC4: beq         $s2, $s1, L_80041E2C
    if (ctx->r18 == ctx->r17) {
        // 0x80041DC8: addu        $a0, $s0, $zero
        ctx->r4 = ADD32(ctx->r16, 0);
            goto L_80041E2C;
    }
    // 0x80041DC8: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x80041DCC: addiu       $a1, $zero, 0x1000
    ctx->r5 = ADD32(0, 0X1000);
    // 0x80041DD0: jal         0x8003E8DC
    // 0x80041DD4: addiu       $a2, $sp, 0x10
    ctx->r6 = ADD32(ctx->r29, 0X10);
    func_8003E8DC(rdram, ctx);
        goto after_0;
    // 0x80041DD4: addiu       $a2, $sp, 0x10
    ctx->r6 = ADD32(ctx->r29, 0X10);
    after_0:
    // 0x80041DD8: lw          $v0, 0x10($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X10);
    // 0x80041DDC: beq         $v0, $zero, L_80041E2C
    if (ctx->r2 == 0) {
        // 0x80041DE0: nop
    
            goto L_80041E2C;
    }
    // 0x80041DE0: nop

    // 0x80041DE4: lhu         $v0, 0x140($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X140);
    // 0x80041DE8: bne         $v0, $s1, L_80041E00
    if (ctx->r2 != ctx->r17) {
        // 0x80041DEC: addu        $a0, $s0, $zero
        ctx->r4 = ADD32(ctx->r16, 0);
            goto L_80041E00;
    }
    // 0x80041DEC: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x80041DF0: jal         0x80040188
    // 0x80041DF4: addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    func_80040188(rdram, ctx);
        goto after_1;
    // 0x80041DF4: addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    after_1:
    // 0x80041DF8: lw          $v1, 0x10($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X10);
    // 0x80041DFC: sh          $v0, 0x140($v1)
    MEM_H(0X140, ctx->r3) = ctx->r2;
L_80041E00:
    // 0x80041E00: beq         $s3, $zero, L_80041E24
    if (ctx->r19 == 0) {
        // 0x80041E04: nop
    
            goto L_80041E24;
    }
    // 0x80041E04: nop

    // 0x80041E08: lw          $v0, 0x10($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X10);
    // 0x80041E0C: lw          $t0, 0x0($s3)
    ctx->r8 = MEM_W(ctx->r19, 0X0);
    // 0x80041E10: lw          $t1, 0x4($s3)
    ctx->r9 = MEM_W(ctx->r19, 0X4);
    // 0x80041E14: lw          $t2, 0x8($s3)
    ctx->r10 = MEM_W(ctx->r19, 0X8);
    // 0x80041E18: sw          $t0, 0x144($v0)
    MEM_W(0X144, ctx->r2) = ctx->r8;
    // 0x80041E1C: sw          $t1, 0x148($v0)
    MEM_W(0X148, ctx->r2) = ctx->r9;
    // 0x80041E20: sw          $t2, 0x14C($v0)
    MEM_W(0X14C, ctx->r2) = ctx->r10;
L_80041E24:
    // 0x80041E24: lw          $v0, 0x10($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X10);
    // 0x80041E28: swc1        $f20, 0x15C($v0)
    MEM_W(0X15C, ctx->r2) = ctx->f20.u32l;
L_80041E2C:
    // 0x80041E2C: lw          $ra, 0x28($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X28);
    // 0x80041E30: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x80041E34: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80041E38: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80041E3C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80041E40: ldc1        $f20, 0x30($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X30);
    // 0x80041E44: jr          $ra
    // 0x80041E48: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x80041E48: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_80041E4C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80041E4C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80041E50: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80041E54: addu        $s0, $a1, $zero
    ctx->r16 = ADD32(ctx->r5, 0);
    // 0x80041E58: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    // 0x80041E5C: ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
    // 0x80041E60: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80041E64: beq         $a0, $v0, L_80041E9C
    if (ctx->r4 == ctx->r2) {
        // 0x80041E68: sw          $zero, 0x10($sp)
        MEM_W(0X10, ctx->r29) = 0;
            goto L_80041E9C;
    }
    // 0x80041E68: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80041E6C: addiu       $a1, $zero, 0x1000
    ctx->r5 = ADD32(0, 0X1000);
    // 0x80041E70: jal         0x8003E8DC
    // 0x80041E74: addiu       $a2, $sp, 0x10
    ctx->r6 = ADD32(ctx->r29, 0X10);
    func_8003E8DC(rdram, ctx);
        goto after_0;
    // 0x80041E74: addiu       $a2, $sp, 0x10
    ctx->r6 = ADD32(ctx->r29, 0X10);
    after_0:
    // 0x80041E78: lw          $v0, 0x10($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X10);
    // 0x80041E7C: beq         $v0, $zero, L_80041E9C
    if (ctx->r2 == 0) {
        // 0x80041E80: nop
    
            goto L_80041E9C;
    }
    // 0x80041E80: nop

    // 0x80041E84: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x80041E88: lw          $a3, 0x4($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X4);
    // 0x80041E8C: lw          $t0, 0x8($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X8);
    // 0x80041E90: sw          $v1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r3;
    // 0x80041E94: sw          $a3, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r7;
    // 0x80041E98: sw          $t0, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r8;
L_80041E9C:
    // 0x80041E9C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80041EA0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80041EA4: jr          $ra
    // 0x80041EA8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80041EA8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_80041EAC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80041EAC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80041EB0: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    // 0x80041EB4: ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
    // 0x80041EB8: sw          $ra, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r31;
    // 0x80041EBC: beq         $a0, $v0, L_80041EDC
    if (ctx->r4 == ctx->r2) {
        // 0x80041EC0: sw          $zero, 0x10($sp)
        MEM_W(0X10, ctx->r29) = 0;
            goto L_80041EDC;
    }
    // 0x80041EC0: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80041EC4: addiu       $a1, $zero, 0x1000
    ctx->r5 = ADD32(0, 0X1000);
    // 0x80041EC8: jal         0x8003E8DC
    // 0x80041ECC: addiu       $a2, $sp, 0x10
    ctx->r6 = ADD32(ctx->r29, 0X10);
    func_8003E8DC(rdram, ctx);
        goto after_0;
    // 0x80041ECC: addiu       $a2, $sp, 0x10
    ctx->r6 = ADD32(ctx->r29, 0X10);
    after_0:
    // 0x80041ED0: lw          $v1, 0x10($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X10);
    // 0x80041ED4: bne         $v1, $zero, L_80041EE0
    if (ctx->r3 != 0) {
        // 0x80041ED8: addu        $v0, $v1, $zero
        ctx->r2 = ADD32(ctx->r3, 0);
            goto L_80041EE0;
    }
    // 0x80041ED8: addu        $v0, $v1, $zero
    ctx->r2 = ADD32(ctx->r3, 0);
L_80041EDC:
    // 0x80041EDC: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_80041EE0:
    // 0x80041EE0: lw          $ra, 0x18($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X18);
    // 0x80041EE4: jr          $ra
    // 0x80041EE8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80041EE8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void fake_func_80041EEC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
;}
RECOMP_FUNC void func_80041EF0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80041EF0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80041EF4: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x80041EF8: addu        $s1, $a0, $zero
    ctx->r17 = ADD32(ctx->r4, 0);
    // 0x80041EFC: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x80041F00: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x80041F04: sll         $a0, $s1, 1
    ctx->r4 = S32(ctx->r17 << 1);
    // 0x80041F08: addu        $a0, $a0, $s1
    ctx->r4 = ADD32(ctx->r4, ctx->r17);
    // 0x80041F0C: sll         $a0, $a0, 2
    ctx->r4 = S32(ctx->r4 << 2);
    // 0x80041F10: sw          $ra, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r31;
    // 0x80041F14: jal         0x80001ACC
    // 0x80041F18: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    rs_malloc(rdram, ctx);
        goto after_0;
    // 0x80041F18: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    after_0:
    // 0x80041F1C: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
    // 0x80041F20: blez        $s1, L_80041F5C
    if (SIGNED(ctx->r17) <= 0) {
        // 0x80041F24: sw          $v0, 0x6FCC($s0)
        MEM_W(0X6FCC, ctx->r16) = ctx->r2;
            goto L_80041F5C;
    }
    // 0x80041F24: sw          $v0, 0x6FCC($s0)
    MEM_W(0X6FCC, ctx->r16) = ctx->r2;
    // 0x80041F28: addu        $a1, $v0, $zero
    ctx->r5 = ADD32(ctx->r2, 0);
    // 0x80041F2C: sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3 << 1);
L_80041F30:
    // 0x80041F30: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80041F34: addiu       $a0, $v1, -0x1
    ctx->r4 = ADD32(ctx->r3, -0X1);
    // 0x80041F38: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80041F3C: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80041F40: addu        $v0, $v0, $a1
    ctx->r2 = ADD32(ctx->r2, ctx->r5);
    // 0x80041F44: sh          $a0, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r4;
    // 0x80041F48: sh          $v1, 0x2($v0)
    MEM_H(0X2, ctx->r2) = ctx->r3;
    // 0x80041F4C: sw          $zero, 0x8($v0)
    MEM_W(0X8, ctx->r2) = 0;
    // 0x80041F50: slt         $v0, $v1, $s1
    ctx->r2 = SIGNED(ctx->r3) < SIGNED(ctx->r17) ? 1 : 0;
    // 0x80041F54: bne         $v0, $zero, L_80041F30
    if (ctx->r2 != 0) {
        // 0x80041F58: sll         $v0, $v1, 1
        ctx->r2 = S32(ctx->r3 << 1);
            goto L_80041F30;
    }
    // 0x80041F58: sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3 << 1);
L_80041F5C:
    // 0x80041F5C: ori         $a0, $zero, 0xFFFF
    ctx->r4 = 0 | 0XFFFF;
    // 0x80041F60: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80041F64: sh          $a0, 0x6FC8($v0)
    MEM_H(0X6FC8, ctx->r2) = ctx->r4;
    // 0x80041F68: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80041F6C: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x80041F70: sh          $zero, 0x6FC0($v0)
    MEM_H(0X6FC0, ctx->r2) = 0;
    // 0x80041F74: sll         $v0, $s1, 1
    ctx->r2 = S32(ctx->r17 << 1);
    // 0x80041F78: addu        $v0, $v0, $s1
    ctx->r2 = ADD32(ctx->r2, ctx->r17);
    // 0x80041F7C: lw          $v1, 0x6FCC($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X6FCC);
    // 0x80041F80: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80041F84: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80041F88: sh          $a0, -0xA($v0)
    MEM_H(-0XA, ctx->r2) = ctx->r4;
    // 0x80041F8C: sh          $a0, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r4;
    // 0x80041F90: lw          $ra, 0x18($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X18);
    // 0x80041F94: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x80041F98: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x80041F9C: jr          $ra
    // 0x80041FA0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80041FA0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_80041FA4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80041FA4: lwc1        $f6, 0x8($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X8);
    // 0x80041FA8: lwc1        $f2, 0x8($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X8);
    // 0x80041FAC: c.lt.s      $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f2.fl < ctx->f6.fl;
    // 0x80041FB0: nop

    // 0x80041FB4: bc1f        L_80042110
    if (!c1cs) {
        // 0x80041FB8: nop
    
            goto L_80042110;
    }
    // 0x80041FB8: nop

    // 0x80041FBC: lwc1        $f0, 0x0($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0X0);
    // 0x80041FC0: sub.s       $f4, $f6, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = ctx->f6.fl - ctx->f2.fl;
    // 0x80041FC4: lwc1        $f8, 0x0($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X0);
    // 0x80041FC8: trunc.w.s   $f10, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    ctx->f10.u32l = TRUNC_W_S(ctx->f2.fl);
    // 0x80041FCC: mfc1        $a3, $f10
    ctx->r7 = (int32_t)ctx->f10.u32l;
    // 0x80041FD0: sub.s       $f0, $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f8.fl;
    // 0x80041FD4: trunc.w.s   $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x80041FD8: mfc1        $t0, $f10
    ctx->r8 = (int32_t)ctx->f10.u32l;
    // 0x80041FDC: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x80041FE0: div.s       $f4, $f0, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f4.fl = DIV_S(ctx->f0.fl, ctx->f4.fl);
    // 0x80041FE4: c.lt.s      $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f4.fl < ctx->f2.fl;
    // 0x80041FE8: nop

    // 0x80041FEC: bc1f        L_8004206C
    if (!c1cs) {
        // 0x80041FF0: slt         $v0, $a3, $t0
        ctx->r2 = SIGNED(ctx->r7) < SIGNED(ctx->r8) ? 1 : 0;
            goto L_8004206C;
    }
    // 0x80041FF0: slt         $v0, $a3, $t0
    ctx->r2 = SIGNED(ctx->r7) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x80041FF4: beq         $v0, $zero, L_80042048
    if (ctx->r2 == 0) {
        // 0x80041FF8: lui         $v0, 0x8013
        ctx->r2 = S32(0X8013 << 16);
            goto L_80042048;
    }
    // 0x80041FF8: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80041FFC: addiu       $v0, $v0, 0xC70
    ctx->r2 = ADD32(ctx->r2, 0XC70);
    // 0x80042000: sll         $v1, $a2, 1
    ctx->r3 = S32(ctx->r6 << 1);
    // 0x80042004: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
L_80042008:
    // 0x80042008: addiu       $v0, $a3, 0x1
    ctx->r2 = ADD32(ctx->r7, 0X1);
    // 0x8004200C: lwc1        $f2, 0x8($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X8);
    // 0x80042010: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x80042014: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x80042018: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x8004201C: mul.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x80042020: lwc1        $f2, 0x0($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X0);
    // 0x80042024: add.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x80042028: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x8004202C: addu        $a3, $v0, $zero
    ctx->r7 = ADD32(ctx->r2, 0);
    // 0x80042030: trunc.w.s   $f10, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    ctx->f10.u32l = TRUNC_W_S(ctx->f2.fl);
    // 0x80042034: mfc1        $v0, $f10
    ctx->r2 = (int32_t)ctx->f10.u32l;
    // 0x80042038: sh          $v0, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r2;
    // 0x8004203C: slt         $v0, $a3, $t0
    ctx->r2 = SIGNED(ctx->r7) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x80042040: bne         $v0, $zero, L_80042008
    if (ctx->r2 != 0) {
        // 0x80042044: addiu       $v1, $v1, 0x2
        ctx->r3 = ADD32(ctx->r3, 0X2);
            goto L_80042008;
    }
    // 0x80042044: addiu       $v1, $v1, 0x2
    ctx->r3 = ADD32(ctx->r3, 0X2);
L_80042048:
    // 0x80042048: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8004204C: addiu       $v0, $v0, 0xC70
    ctx->r2 = ADD32(ctx->r2, 0XC70);
    // 0x80042050: sll         $v1, $a2, 1
    ctx->r3 = S32(ctx->r6 << 1);
    // 0x80042054: lwc1        $f0, 0x0($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0X0);
    // 0x80042058: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x8004205C: trunc.w.s   $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    ctx->f10.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x80042060: mfc1        $v0, $f10
    ctx->r2 = (int32_t)ctx->f10.u32l;
    // 0x80042064: j           L_80042110
    // 0x80042068: sh          $v0, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r2;
        goto L_80042110;
    // 0x80042068: sh          $v0, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r2;
L_8004206C:
    // 0x8004206C: beq         $a2, $zero, L_8004209C
    if (ctx->r6 == 0) {
        // 0x80042070: lui         $v1, 0x8013
        ctx->r3 = S32(0X8013 << 16);
            goto L_8004209C;
    }
    // 0x80042070: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x80042074: addiu       $v1, $v1, 0xC70
    ctx->r3 = ADD32(ctx->r3, 0XC70);
    // 0x80042078: sll         $v0, $a2, 1
    ctx->r2 = S32(ctx->r6 << 1);
    // 0x8004207C: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80042080: lh          $v0, 0x0($v0)
    ctx->r2 = MEM_H(ctx->r2, 0X0);
    // 0x80042084: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x80042088: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x8004208C: c.lt.s      $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f8.fl < ctx->f0.fl;
    // 0x80042090: nop

    // 0x80042094: bc1fl       L_800420BC
    if (!c1cs) {
        // 0x80042098: addiu       $a3, $a3, 0x1
        ctx->r7 = ADD32(ctx->r7, 0X1);
            goto L_800420BC;
    }
    goto skip_0;
    // 0x80042098: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    skip_0:
L_8004209C:
    // 0x8004209C: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800420A0: addiu       $v0, $v0, 0xC70
    ctx->r2 = ADD32(ctx->r2, 0XC70);
    // 0x800420A4: sll         $v1, $a2, 1
    ctx->r3 = S32(ctx->r6 << 1);
    // 0x800420A8: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x800420AC: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x800420B0: mfc1        $v0, $f10
    ctx->r2 = (int32_t)ctx->f10.u32l;
    // 0x800420B4: sh          $v0, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r2;
    // 0x800420B8: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
L_800420BC:
    // 0x800420BC: slt         $v0, $t0, $a3
    ctx->r2 = SIGNED(ctx->r8) < SIGNED(ctx->r7) ? 1 : 0;
    // 0x800420C0: bne         $v0, $zero, L_80042110
    if (ctx->r2 != 0) {
        // 0x800420C4: lui         $v0, 0x8013
        ctx->r2 = S32(0X8013 << 16);
            goto L_80042110;
    }
    // 0x800420C4: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800420C8: addiu       $v0, $v0, 0xC70
    ctx->r2 = ADD32(ctx->r2, 0XC70);
    // 0x800420CC: sll         $v1, $a2, 1
    ctx->r3 = S32(ctx->r6 << 1);
    // 0x800420D0: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
L_800420D4:
    // 0x800420D4: lwc1        $f2, 0x8($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X8);
    // 0x800420D8: mtc1        $a3, $f0
    ctx->f0.u32l = ctx->r7;
    // 0x800420DC: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x800420E0: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x800420E4: mul.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x800420E8: lwc1        $f2, 0x0($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X0);
    // 0x800420EC: addiu       $v1, $v1, 0x2
    ctx->r3 = ADD32(ctx->r3, 0X2);
    // 0x800420F0: add.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x800420F4: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x800420F8: trunc.w.s   $f10, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    ctx->f10.u32l = TRUNC_W_S(ctx->f2.fl);
    // 0x800420FC: mfc1        $v0, $f10
    ctx->r2 = (int32_t)ctx->f10.u32l;
    // 0x80042100: sh          $v0, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r2;
    // 0x80042104: slt         $v0, $t0, $a3
    ctx->r2 = SIGNED(ctx->r8) < SIGNED(ctx->r7) ? 1 : 0;
    // 0x80042108: beq         $v0, $zero, L_800420D4
    if (ctx->r2 == 0) {
        // 0x8004210C: addiu       $a2, $a2, 0x1
        ctx->r6 = ADD32(ctx->r6, 0X1);
            goto L_800420D4;
    }
    // 0x8004210C: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
L_80042110:
    // 0x80042110: jr          $ra
    // 0x80042114: addu        $v0, $a2, $zero
    ctx->r2 = ADD32(ctx->r6, 0);
    return;
    // 0x80042114: addu        $v0, $a2, $zero
    ctx->r2 = ADD32(ctx->r6, 0);
;}
RECOMP_FUNC void func_80042118(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80042118: lwc1        $f6, 0x8($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X8);
    // 0x8004211C: lwc1        $f2, 0x8($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X8);
    // 0x80042120: c.lt.s      $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f2.fl < ctx->f6.fl;
    // 0x80042124: nop

    // 0x80042128: bc1f        L_80042290
    if (!c1cs) {
        // 0x8004212C: addu        $v0, $a2, $zero
        ctx->r2 = ADD32(ctx->r6, 0);
            goto L_80042290;
    }
    // 0x8004212C: addu        $v0, $a2, $zero
    ctx->r2 = ADD32(ctx->r6, 0);
    // 0x80042130: lwc1        $f0, 0x0($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0X0);
    // 0x80042134: sub.s       $f4, $f6, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = ctx->f6.fl - ctx->f2.fl;
    // 0x80042138: lwc1        $f8, 0x0($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X0);
    // 0x8004213C: trunc.w.s   $f10, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    ctx->f10.u32l = TRUNC_W_S(ctx->f2.fl);
    // 0x80042140: mfc1        $a3, $f10
    ctx->r7 = (int32_t)ctx->f10.u32l;
    // 0x80042144: sub.s       $f0, $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f8.fl;
    // 0x80042148: trunc.w.s   $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x8004214C: mfc1        $t0, $f10
    ctx->r8 = (int32_t)ctx->f10.u32l;
    // 0x80042150: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x80042154: div.s       $f4, $f0, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f4.fl = DIV_S(ctx->f0.fl, ctx->f4.fl);
    // 0x80042158: c.lt.s      $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f4.fl < ctx->f2.fl;
    // 0x8004215C: nop

    // 0x80042160: bc1f        L_80042218
    if (!c1cs) {
        // 0x80042164: slt         $v0, $a3, $t0
        ctx->r2 = SIGNED(ctx->r7) < SIGNED(ctx->r8) ? 1 : 0;
            goto L_80042218;
    }
    // 0x80042164: slt         $v0, $a3, $t0
    ctx->r2 = SIGNED(ctx->r7) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x80042168: beq         $a2, $zero, L_80042198
    if (ctx->r6 == 0) {
        // 0x8004216C: lui         $v1, 0x8013
        ctx->r3 = S32(0X8013 << 16);
            goto L_80042198;
    }
    // 0x8004216C: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x80042170: addiu       $v1, $v1, 0xD10
    ctx->r3 = ADD32(ctx->r3, 0XD10);
    // 0x80042174: sll         $v0, $a2, 1
    ctx->r2 = S32(ctx->r6 << 1);
    // 0x80042178: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8004217C: lh          $v0, 0x0($v0)
    ctx->r2 = MEM_H(ctx->r2, 0X0);
    // 0x80042180: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x80042184: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x80042188: c.lt.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl < ctx->f8.fl;
    // 0x8004218C: nop

    // 0x80042190: bc1fl       L_800421B8
    if (!c1cs) {
        // 0x80042194: addiu       $a3, $a3, 0x1
        ctx->r7 = ADD32(ctx->r7, 0X1);
            goto L_800421B8;
    }
    goto skip_0;
    // 0x80042194: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    skip_0:
L_80042198:
    // 0x80042198: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8004219C: addiu       $v0, $v0, 0xD10
    ctx->r2 = ADD32(ctx->r2, 0XD10);
    // 0x800421A0: sll         $v1, $a2, 1
    ctx->r3 = S32(ctx->r6 << 1);
    // 0x800421A4: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x800421A8: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x800421AC: mfc1        $v0, $f10
    ctx->r2 = (int32_t)ctx->f10.u32l;
    // 0x800421B0: sh          $v0, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r2;
    // 0x800421B4: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
L_800421B8:
    // 0x800421B8: slt         $v0, $t0, $a3
    ctx->r2 = SIGNED(ctx->r8) < SIGNED(ctx->r7) ? 1 : 0;
    // 0x800421BC: bne         $v0, $zero, L_80042290
    if (ctx->r2 != 0) {
        // 0x800421C0: addu        $v0, $a2, $zero
        ctx->r2 = ADD32(ctx->r6, 0);
            goto L_80042290;
    }
    // 0x800421C0: addu        $v0, $a2, $zero
    ctx->r2 = ADD32(ctx->r6, 0);
    // 0x800421C4: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800421C8: addiu       $v0, $v0, 0xD10
    ctx->r2 = ADD32(ctx->r2, 0XD10);
    // 0x800421CC: sll         $v1, $a2, 1
    ctx->r3 = S32(ctx->r6 << 1);
    // 0x800421D0: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
L_800421D4:
    // 0x800421D4: lwc1        $f2, 0x8($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X8);
    // 0x800421D8: mtc1        $a3, $f0
    ctx->f0.u32l = ctx->r7;
    // 0x800421DC: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x800421E0: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x800421E4: mul.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x800421E8: lwc1        $f2, 0x0($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X0);
    // 0x800421EC: addiu       $v1, $v1, 0x2
    ctx->r3 = ADD32(ctx->r3, 0X2);
    // 0x800421F0: add.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x800421F4: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x800421F8: trunc.w.s   $f10, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    ctx->f10.u32l = TRUNC_W_S(ctx->f2.fl);
    // 0x800421FC: mfc1        $v0, $f10
    ctx->r2 = (int32_t)ctx->f10.u32l;
    // 0x80042200: sh          $v0, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r2;
    // 0x80042204: slt         $v0, $t0, $a3
    ctx->r2 = SIGNED(ctx->r8) < SIGNED(ctx->r7) ? 1 : 0;
    // 0x80042208: beq         $v0, $zero, L_800421D4
    if (ctx->r2 == 0) {
        // 0x8004220C: addiu       $a2, $a2, 0x1
        ctx->r6 = ADD32(ctx->r6, 0X1);
            goto L_800421D4;
    }
    // 0x8004220C: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x80042210: jr          $ra
    // 0x80042214: addu        $v0, $a2, $zero
    ctx->r2 = ADD32(ctx->r6, 0);
    return;
    // 0x80042214: addu        $v0, $a2, $zero
    ctx->r2 = ADD32(ctx->r6, 0);
L_80042218:
    // 0x80042218: beq         $v0, $zero, L_8004226C
    if (ctx->r2 == 0) {
        // 0x8004221C: lui         $v0, 0x8013
        ctx->r2 = S32(0X8013 << 16);
            goto L_8004226C;
    }
    // 0x8004221C: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80042220: addiu       $v0, $v0, 0xD10
    ctx->r2 = ADD32(ctx->r2, 0XD10);
    // 0x80042224: sll         $v1, $a2, 1
    ctx->r3 = S32(ctx->r6 << 1);
    // 0x80042228: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
L_8004222C:
    // 0x8004222C: addiu       $v0, $a3, 0x1
    ctx->r2 = ADD32(ctx->r7, 0X1);
    // 0x80042230: lwc1        $f2, 0x8($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X8);
    // 0x80042234: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x80042238: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x8004223C: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x80042240: mul.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x80042244: lwc1        $f2, 0x0($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X0);
    // 0x80042248: add.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x8004224C: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x80042250: addu        $a3, $v0, $zero
    ctx->r7 = ADD32(ctx->r2, 0);
    // 0x80042254: trunc.w.s   $f10, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    ctx->f10.u32l = TRUNC_W_S(ctx->f2.fl);
    // 0x80042258: mfc1        $v0, $f10
    ctx->r2 = (int32_t)ctx->f10.u32l;
    // 0x8004225C: sh          $v0, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r2;
    // 0x80042260: slt         $v0, $a3, $t0
    ctx->r2 = SIGNED(ctx->r7) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x80042264: bne         $v0, $zero, L_8004222C
    if (ctx->r2 != 0) {
        // 0x80042268: addiu       $v1, $v1, 0x2
        ctx->r3 = ADD32(ctx->r3, 0X2);
            goto L_8004222C;
    }
    // 0x80042268: addiu       $v1, $v1, 0x2
    ctx->r3 = ADD32(ctx->r3, 0X2);
L_8004226C:
    // 0x8004226C: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80042270: addiu       $v0, $v0, 0xD10
    ctx->r2 = ADD32(ctx->r2, 0XD10);
    // 0x80042274: sll         $v1, $a2, 1
    ctx->r3 = S32(ctx->r6 << 1);
    // 0x80042278: lwc1        $f0, 0x0($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0X0);
    // 0x8004227C: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x80042280: trunc.w.s   $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    ctx->f10.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x80042284: mfc1        $v0, $f10
    ctx->r2 = (int32_t)ctx->f10.u32l;
    // 0x80042288: sh          $v0, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r2;
    // 0x8004228C: addu        $v0, $a2, $zero
    ctx->r2 = ADD32(ctx->r6, 0);
L_80042290:
    // 0x80042290: jr          $ra
    // 0x80042294: nop

    return;
    // 0x80042294: nop

;}
RECOMP_FUNC void func_80042298(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80042298: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x8004229C: sw          $s1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r17;
    // 0x800422A0: addu        $s1, $a0, $zero
    ctx->r17 = ADD32(ctx->r4, 0);
    // 0x800422A4: sw          $s3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r19;
    // 0x800422A8: addu        $s3, $a1, $zero
    ctx->r19 = ADD32(ctx->r5, 0);
    // 0x800422AC: sw          $s2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r18;
    // 0x800422B0: sw          $ra, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r31;
    // 0x800422B4: sw          $s0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r16;
    // 0x800422B8: sdc1        $f22, 0x60($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X60, ctx->r29);
    // 0x800422BC: sdc1        $f20, 0x58($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X58, ctx->r29);
    // 0x800422C0: lwc1        $f2, 0x8($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0X8);
    // 0x800422C4: lwc1        $f0, 0x8($s3)
    ctx->f0.u32l = MEM_W(ctx->r19, 0X8);
    // 0x800422C8: mtc1        $a3, $f22
    ctx->f22.u32l = ctx->r7;
    // 0x800422CC: j           L_800422E8
    // 0x800422D0: addu        $s2, $a2, $zero
    ctx->r18 = ADD32(ctx->r6, 0);
        goto L_800422E8;
    // 0x800422D0: addu        $s2, $a2, $zero
    ctx->r18 = ADD32(ctx->r6, 0);
L_800422D4:
    // 0x800422D4: addu        $s1, $s3, $zero
    ctx->r17 = ADD32(ctx->r19, 0);
L_800422D8:
    // 0x800422D8: addu        $s3, $s2, $zero
    ctx->r19 = ADD32(ctx->r18, 0);
    // 0x800422DC: lwc1        $f2, 0x8($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0X8);
    // 0x800422E0: lwc1        $f0, 0x8($s3)
    ctx->f0.u32l = MEM_W(ctx->r19, 0X8);
    // 0x800422E4: addu        $s2, $v0, $zero
    ctx->r18 = ADD32(ctx->r2, 0);
L_800422E8:
    // 0x800422E8: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x800422EC: nop

    // 0x800422F0: bc1t        L_800422D4
    if (c1cs) {
        // 0x800422F4: addu        $v0, $s1, $zero
        ctx->r2 = ADD32(ctx->r17, 0);
            goto L_800422D4;
    }
    // 0x800422F4: addu        $v0, $s1, $zero
    ctx->r2 = ADD32(ctx->r17, 0);
    // 0x800422F8: lwc1        $f0, 0x8($s2)
    ctx->f0.u32l = MEM_W(ctx->r18, 0X8);
    // 0x800422FC: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x80042300: nop

    // 0x80042304: bc1tl       L_800422D8
    if (c1cs) {
        // 0x80042308: addu        $s1, $s3, $zero
        ctx->r17 = ADD32(ctx->r19, 0);
            goto L_800422D8;
    }
    goto skip_0;
    // 0x80042308: addu        $s1, $s3, $zero
    ctx->r17 = ADD32(ctx->r19, 0);
    skip_0:
    // 0x8004230C: lwc1        $f0, 0x0($s3)
    ctx->f0.u32l = MEM_W(ctx->r19, 0X0);
    // 0x80042310: lwc1        $f2, 0x0($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0X0);
    // 0x80042314: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x80042318: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    // 0x8004231C: lwc1        $f0, 0x4($s3)
    ctx->f0.u32l = MEM_W(ctx->r19, 0X4);
    // 0x80042320: lwc1        $f2, 0x4($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0X4);
    // 0x80042324: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x80042328: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    // 0x8004232C: lwc1        $f0, 0x8($s3)
    ctx->f0.u32l = MEM_W(ctx->r19, 0X8);
    // 0x80042330: lwc1        $f2, 0x8($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0X8);
    // 0x80042334: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x80042338: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    // 0x8004233C: lwc1        $f0, 0x0($s2)
    ctx->f0.u32l = MEM_W(ctx->r18, 0X0);
    // 0x80042340: lwc1        $f2, 0x0($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0X0);
    // 0x80042344: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x80042348: swc1        $f0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f0.u32l;
    // 0x8004234C: lwc1        $f0, 0x4($s2)
    ctx->f0.u32l = MEM_W(ctx->r18, 0X4);
    // 0x80042350: lwc1        $f2, 0x4($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0X4);
    // 0x80042354: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x80042358: addiu       $s0, $sp, 0x30
    ctx->r16 = ADD32(ctx->r29, 0X30);
    // 0x8004235C: swc1        $f0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f0.u32l;
    // 0x80042360: lwc1        $f0, 0x8($s2)
    ctx->f0.u32l = MEM_W(ctx->r18, 0X8);
    // 0x80042364: lwc1        $f2, 0x8($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0X8);
    // 0x80042368: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x8004236C: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x80042370: addiu       $a1, $sp, 0x10
    ctx->r5 = ADD32(ctx->r29, 0X10);
    // 0x80042374: addiu       $a2, $sp, 0x20
    ctx->r6 = ADD32(ctx->r29, 0X20);
    // 0x80042378: jal         0x80019548
    // 0x8004237C: swc1        $f0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f0.u32l;
    func_80019548(rdram, ctx);
        goto after_0;
    // 0x8004237C: swc1        $f0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f0.u32l;
    after_0:
    // 0x80042380: jal         0x8001CF58
    // 0x80042384: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    normalize_vector(rdram, ctx);
        goto after_1;
    // 0x80042384: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_1:
    // 0x80042388: lwc1        $f2, 0x34($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X34);
    // 0x8004238C: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80042390: ldc1        $f0, -0x5B30($at)
    CHECK_FR(ctx, 0);
    ctx->f0.u64 = LD(ctx->r1, -0X5B30);
    // 0x80042394: cvt.d.s     $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f2.d = CVT_D_S(ctx->f2.fl);
    // 0x80042398: c.lt.d      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.d < ctx->f0.d;
    // 0x8004239C: nop

    // 0x800423A0: bc1f        L_80042420
    if (!c1cs) {
        // 0x800423A4: nop
    
            goto L_80042420;
    }
    // 0x800423A4: nop

    // 0x800423A8: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x800423AC: ldc1        $f0, -0x5B28($at)
    CHECK_FR(ctx, 0);
    ctx->f0.u64 = LD(ctx->r1, -0X5B28);
    // 0x800423B0: c.lt.d      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.d < ctx->f2.d;
    // 0x800423B4: nop

    // 0x800423B8: bc1f        L_80042420
    if (!c1cs) {
        // 0x800423BC: nop
    
            goto L_80042420;
    }
    // 0x800423BC: nop

    // 0x800423C0: lwc1        $f4, 0x18($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X18);
    // 0x800423C4: lwc1        $f0, 0x20($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X20);
    // 0x800423C8: mul.s       $f4, $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x800423CC: lwc1        $f2, 0x28($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X28);
    // 0x800423D0: lwc1        $f0, 0x10($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X10);
    // 0x800423D4: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x800423D8: sub.s       $f20, $f4, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f20.fl = ctx->f4.fl - ctx->f0.fl;
    // 0x800423DC: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800423E0: c.lt.s      $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f20.fl < ctx->f0.fl;
    // 0x800423E4: nop

    // 0x800423E8: bc1tl       L_800423F0
    if (c1cs) {
        // 0x800423EC: neg.s       $f20, $f20
        CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); 
    ctx->f20.fl = -ctx->f20.fl;
            goto L_800423F0;
    }
    goto skip_1;
    // 0x800423EC: neg.s       $f20, $f20
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); 
    ctx->f20.fl = -ctx->f20.fl;
    skip_1:
L_800423F0:
    // 0x800423F0: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x800423F4: lwc1        $f0, -0x5B20($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X5B20);
    // 0x800423F8: c.lt.s      $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f20.fl < ctx->f0.fl;
    // 0x800423FC: nop

    // 0x80042400: bc1f        L_80042420
    if (!c1cs) {
        // 0x80042404: nop
    
            goto L_80042420;
    }
    // 0x80042404: nop

    // 0x80042408: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8004240C: lwc1        $f0, -0x5B1C($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X5B1C);
    // 0x80042410: c.lt.s      $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f0.fl < ctx->f20.fl;
    // 0x80042414: nop

    // 0x80042418: bc1t        L_80042848
    if (c1cs) {
        // 0x8004241C: nop
    
            goto L_80042848;
    }
    // 0x8004241C: nop

L_80042420:
    // 0x80042420: lwc1        $f12, 0x0($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X0);
    // 0x80042424: lwc1        $f0, 0x30($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X30);
    // 0x80042428: neg.s       $f6, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = -ctx->f12.fl;
    // 0x8004242C: mul.s       $f6, $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x80042430: lwc1        $f0, 0x4($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X4);
    // 0x80042434: lwc1        $f2, 0x34($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X34);
    // 0x80042438: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
    // 0x8004243C: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x80042440: lwc1        $f8, 0x8($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X8);
    // 0x80042444: lwc1        $f4, 0x38($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X38);
    // 0x80042448: neg.s       $f2, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f2.fl = -ctx->f8.fl;
    // 0x8004244C: mul.s       $f2, $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f4.fl);
    // 0x80042450: lwc1        $f10, 0x8($s3)
    ctx->f10.u32l = MEM_W(ctx->r19, 0X8);
    // 0x80042454: add.s       $f6, $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f0.fl;
    // 0x80042458: lwc1        $f4, 0x8($s2)
    ctx->f4.u32l = MEM_W(ctx->r18, 0X8);
    // 0x8004245C: c.lt.s      $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f4.fl < ctx->f10.fl;
    // 0x80042460: nop

    // 0x80042464: bc1f        L_80042500
    if (!c1cs) {
        // 0x80042468: add.s       $f20, $f6, $f2
        CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f20.fl = ctx->f6.fl + ctx->f2.fl;
            goto L_80042500;
    }
    // 0x80042468: add.s       $f20, $f6, $f2
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f20.fl = ctx->f6.fl + ctx->f2.fl;
    // 0x8004246C: sub.s       $f6, $f10, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f10.fl - ctx->f8.fl;
    // 0x80042470: sub.s       $f4, $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f4.fl - ctx->f8.fl;
    // 0x80042474: lwc1        $f0, 0x0($s3)
    ctx->f0.u32l = MEM_W(ctx->r19, 0X0);
    // 0x80042478: sub.s       $f0, $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f12.fl;
    // 0x8004247C: lwc1        $f2, 0x0($s2)
    ctx->f2.u32l = MEM_W(ctx->r18, 0X0);
    // 0x80042480: sub.s       $f2, $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f2.fl = ctx->f2.fl - ctx->f12.fl;
    // 0x80042484: div.s       $f0, $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f6.fl);
    // 0x80042488: div.s       $f2, $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = DIV_S(ctx->f2.fl, ctx->f4.fl);
    // 0x8004248C: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x80042490: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x80042494: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x80042498: nop

    // 0x8004249C: bc1f        L_800424D4
    if (!c1cs) {
        // 0x800424A0: addu        $a0, $s1, $zero
        ctx->r4 = ADD32(ctx->r17, 0);
            goto L_800424D4;
    }
    // 0x800424A0: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x800424A4: addu        $a1, $s3, $zero
    ctx->r5 = ADD32(ctx->r19, 0);
    // 0x800424A8: jal         0x80041FA4
    // 0x800424AC: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    func_80041FA4(rdram, ctx);
        goto after_2;
    // 0x800424AC: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    after_2:
    // 0x800424B0: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    // 0x800424B4: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x800424B8: addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    // 0x800424BC: jal         0x80042118
    // 0x800424C0: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    func_80042118(rdram, ctx);
        goto after_3;
    // 0x800424C0: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    after_3:
    // 0x800424C4: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // 0x800424C8: addu        $a1, $s3, $zero
    ctx->r5 = ADD32(ctx->r19, 0);
    // 0x800424CC: j           L_80042594
    // 0x800424D0: addu        $a2, $v0, $zero
    ctx->r6 = ADD32(ctx->r2, 0);
        goto L_80042594;
    // 0x800424D0: addu        $a2, $v0, $zero
    ctx->r6 = ADD32(ctx->r2, 0);
L_800424D4:
    // 0x800424D4: addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    // 0x800424D8: jal         0x80041FA4
    // 0x800424DC: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    func_80041FA4(rdram, ctx);
        goto after_4;
    // 0x800424DC: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    after_4:
    // 0x800424E0: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // 0x800424E4: addu        $a1, $s3, $zero
    ctx->r5 = ADD32(ctx->r19, 0);
    // 0x800424E8: jal         0x80041FA4
    // 0x800424EC: addu        $a2, $v0, $zero
    ctx->r6 = ADD32(ctx->r2, 0);
    func_80041FA4(rdram, ctx);
        goto after_5;
    // 0x800424EC: addu        $a2, $v0, $zero
    ctx->r6 = ADD32(ctx->r2, 0);
    after_5:
    // 0x800424F0: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    // 0x800424F4: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x800424F8: j           L_80042590
    // 0x800424FC: addu        $a1, $s3, $zero
    ctx->r5 = ADD32(ctx->r19, 0);
        goto L_80042590;
    // 0x800424FC: addu        $a1, $s3, $zero
    ctx->r5 = ADD32(ctx->r19, 0);
L_80042500:
    // 0x80042500: sub.s       $f6, $f4, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f8.fl;
    // 0x80042504: sub.s       $f4, $f10, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f10.fl - ctx->f8.fl;
    // 0x80042508: lwc1        $f0, 0x0($s2)
    ctx->f0.u32l = MEM_W(ctx->r18, 0X0);
    // 0x8004250C: sub.s       $f0, $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f12.fl;
    // 0x80042510: lwc1        $f2, 0x0($s3)
    ctx->f2.u32l = MEM_W(ctx->r19, 0X0);
    // 0x80042514: sub.s       $f2, $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f2.fl = ctx->f2.fl - ctx->f12.fl;
    // 0x80042518: div.s       $f0, $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f6.fl);
    // 0x8004251C: div.s       $f2, $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = DIV_S(ctx->f2.fl, ctx->f4.fl);
    // 0x80042520: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x80042524: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x80042528: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x8004252C: nop

    // 0x80042530: bc1f        L_80042568
    if (!c1cs) {
        // 0x80042534: addu        $a0, $s1, $zero
        ctx->r4 = ADD32(ctx->r17, 0);
            goto L_80042568;
    }
    // 0x80042534: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x80042538: addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    // 0x8004253C: jal         0x80041FA4
    // 0x80042540: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    func_80041FA4(rdram, ctx);
        goto after_6;
    // 0x80042540: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    after_6:
    // 0x80042544: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    // 0x80042548: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x8004254C: addu        $a1, $s3, $zero
    ctx->r5 = ADD32(ctx->r19, 0);
    // 0x80042550: jal         0x80042118
    // 0x80042554: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    func_80042118(rdram, ctx);
        goto after_7;
    // 0x80042554: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    after_7:
    // 0x80042558: addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    // 0x8004255C: addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    // 0x80042560: j           L_80042594
    // 0x80042564: addu        $a2, $v0, $zero
    ctx->r6 = ADD32(ctx->r2, 0);
        goto L_80042594;
    // 0x80042564: addu        $a2, $v0, $zero
    ctx->r6 = ADD32(ctx->r2, 0);
L_80042568:
    // 0x80042568: addu        $a1, $s3, $zero
    ctx->r5 = ADD32(ctx->r19, 0);
    // 0x8004256C: jal         0x80041FA4
    // 0x80042570: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    func_80041FA4(rdram, ctx);
        goto after_8;
    // 0x80042570: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    after_8:
    // 0x80042574: addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    // 0x80042578: addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    // 0x8004257C: jal         0x80041FA4
    // 0x80042580: addu        $a2, $v0, $zero
    ctx->r6 = ADD32(ctx->r2, 0);
    func_80041FA4(rdram, ctx);
        goto after_9;
    // 0x80042580: addu        $a2, $v0, $zero
    ctx->r6 = ADD32(ctx->r2, 0);
    after_9:
    // 0x80042584: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    // 0x80042588: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x8004258C: addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
L_80042590:
    // 0x80042590: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
L_80042594:
    // 0x80042594: jal         0x80042118
    // 0x80042598: nop

    func_80042118(rdram, ctx);
        goto after_10;
    // 0x80042598: nop

    after_10:
    // 0x8004259C: lwc1        $f2, 0x34($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X34);
    // 0x800425A0: lwc1        $f0, 0x8($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X8);
    // 0x800425A4: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800425A8: trunc.w.s   $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    ctx->f16.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800425AC: mfc1        $v0, $f16
    ctx->r2 = (int32_t)ctx->f16.u32l;
    // 0x800425B0: c.lt.s      $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f4.fl < ctx->f2.fl;
    // 0x800425B4: nop

    // 0x800425B8: bc1f        L_80042708
    if (!c1cs) {
        // 0x800425BC: addu        $t3, $v0, $s0
        ctx->r11 = ADD32(ctx->r2, ctx->r16);
            goto L_80042708;
    }
    // 0x800425BC: addu        $t3, $v0, $s0
    ctx->r11 = ADD32(ctx->r2, ctx->r16);
    // 0x800425C0: addu        $a1, $v0, $zero
    ctx->r5 = ADD32(ctx->r2, 0);
    // 0x800425C4: slt         $v0, $t3, $a1
    ctx->r2 = SIGNED(ctx->r11) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x800425C8: bne         $v0, $zero, L_80042848
    if (ctx->r2 != 0) {
        // 0x800425CC: lui         $v0, 0x8013
        ctx->r2 = S32(0X8013 << 16);
            goto L_80042848;
    }
    // 0x800425CC: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800425D0: mov.s       $f14, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    ctx->f14.fl = ctx->f4.fl;
    // 0x800425D4: addiu       $t4, $v0, 0x1DB0
    ctx->r12 = ADD32(ctx->r2, 0X1DB0);
    // 0x800425D8: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800425DC: addiu       $t0, $v0, 0xD10
    ctx->r8 = ADD32(ctx->r2, 0XD10);
    // 0x800425E0: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800425E4: addiu       $a3, $v0, 0xC70
    ctx->r7 = ADD32(ctx->r2, 0XC70);
    // 0x800425E8: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x800425EC: lwc1        $f12, -0x5B18($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X5B18);
    // 0x800425F0: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x800425F4: lwc1        $f10, -0x5B14($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X5B14);
L_800425F8:
    // 0x800425F8: lh          $a0, 0x0($a3)
    ctx->r4 = MEM_H(ctx->r7, 0X0);
    // 0x800425FC: lh          $a2, 0x0($t0)
    ctx->r6 = MEM_H(ctx->r8, 0X0);
    // 0x80042600: slt         $v0, $a2, $a0
    ctx->r2 = SIGNED(ctx->r6) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x80042604: bnel        $v0, $zero, L_800426F0
    if (ctx->r2 != 0) {
        // 0x80042608: addiu       $a1, $a1, 0x1
        ctx->r5 = ADD32(ctx->r5, 0X1);
            goto L_800426F0;
    }
    goto skip_2;
    // 0x80042608: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    skip_2:
    // 0x8004260C: addiu       $t2, $a1, 0x1
    ctx->r10 = ADD32(ctx->r5, 0X1);
    // 0x80042610: sll         $t1, $a1, 6
    ctx->r9 = S32(ctx->r5 << 6);
    // 0x80042614: neg.s       $f8, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = -ctx->f20.fl;
L_80042618:
    // 0x80042618: lwc1        $f6, 0x34($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X34);
    // 0x8004261C: lwc1        $f2, 0x30($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X30);
    // 0x80042620: c.lt.s      $f14, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f14.fl < ctx->f2.fl;
    // 0x80042624: nop

    // 0x80042628: bc1f        L_80042644
    if (!c1cs) {
        // 0x8004262C: div.s       $f4, $f8, $f6
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = DIV_S(ctx->f8.fl, ctx->f6.fl);
            goto L_80042644;
    }
    // 0x8004262C: div.s       $f4, $f8, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = DIV_S(ctx->f8.fl, ctx->f6.fl);
    // 0x80042630: addiu       $v0, $a0, 0x1
    ctx->r2 = ADD32(ctx->r4, 0X1);
    // 0x80042634: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x80042638: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x8004263C: j           L_8004264C
    // 0x80042640: nop

        goto L_8004264C;
    // 0x80042640: nop

L_80042644:
    // 0x80042644: mtc1        $a0, $f0
    ctx->f0.u32l = ctx->r4;
    // 0x80042648: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
L_8004264C:
    // 0x8004264C: mul.s       $f0, $f2, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x80042650: div.s       $f0, $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f6.fl);
    // 0x80042654: lwc1        $f2, 0x38($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X38);
    // 0x80042658: c.lt.s      $f14, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f14.fl < ctx->f2.fl;
    // 0x8004265C: nop

    // 0x80042660: bc1f        L_80042678
    if (!c1cs) {
        // 0x80042664: sub.s       $f4, $f4, $f0
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f4.fl - ctx->f0.fl;
            goto L_80042678;
    }
    // 0x80042664: sub.s       $f4, $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f4.fl - ctx->f0.fl;
    // 0x80042668: mtc1        $t2, $f0
    ctx->f0.u32l = ctx->r10;
    // 0x8004266C: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x80042670: j           L_80042680
    // 0x80042674: nop

        goto L_80042680;
    // 0x80042674: nop

L_80042678:
    // 0x80042678: mtc1        $a1, $f0
    ctx->f0.u32l = ctx->r5;
    // 0x8004267C: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
L_80042680:
    // 0x80042680: mul.s       $f0, $f2, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x80042684: lwc1        $f2, 0x34($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X34);
    // 0x80042688: div.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f2.fl);
    // 0x8004268C: sub.s       $f4, $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f4.fl - ctx->f0.fl;
    // 0x80042690: mul.s       $f0, $f4, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f0.fl = MUL_S(ctx->f4.fl, ctx->f22.fl);
    // 0x80042694: trunc.w.s   $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    ctx->f16.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x80042698: mfc1        $v0, $f16
    ctx->r2 = (int32_t)ctx->f16.u32l;
    // 0x8004269C: mtc1        $v0, $f4
    ctx->f4.u32l = ctx->r2;
    // 0x800426A0: cvt.s.w     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800426A4: c.lt.s      $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f12.fl < ctx->f4.fl;
    // 0x800426A8: nop

    // 0x800426AC: bc1t        L_800426C8
    if (c1cs) {
        // 0x800426B0: mov.s       $f0, $f12
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
            goto L_800426C8;
    }
    // 0x800426B0: mov.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
    // 0x800426B4: mov.s       $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.fl = ctx->f4.fl;
    // 0x800426B8: c.lt.s      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.fl < ctx->f10.fl;
    // 0x800426BC: nop

    // 0x800426C0: bc1tl       L_800426C8
    if (c1cs) {
        // 0x800426C4: mov.s       $f0, $f10
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    ctx->f0.fl = ctx->f10.fl;
            goto L_800426C8;
    }
    goto skip_3;
    // 0x800426C4: mov.s       $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    ctx->f0.fl = ctx->f10.fl;
    skip_3:
L_800426C8:
    // 0x800426C8: addu        $v0, $a0, $t1
    ctx->r2 = ADD32(ctx->r4, ctx->r9);
    // 0x800426CC: addu        $v0, $v0, $t4
    ctx->r2 = ADD32(ctx->r2, ctx->r12);
    // 0x800426D0: trunc.w.s   $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    ctx->f16.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800426D4: mfc1        $v1, $f16
    ctx->r3 = (int32_t)ctx->f16.u32l;
    // 0x800426D8: sb          $v1, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r3;
    // 0x800426DC: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x800426E0: slt         $v0, $a2, $a0
    ctx->r2 = SIGNED(ctx->r6) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x800426E4: beq         $v0, $zero, L_80042618
    if (ctx->r2 == 0) {
        // 0x800426E8: nop
    
            goto L_80042618;
    }
    // 0x800426E8: nop

    // 0x800426EC: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
L_800426F0:
    // 0x800426F0: addiu       $t0, $t0, 0x2
    ctx->r8 = ADD32(ctx->r8, 0X2);
    // 0x800426F4: slt         $v0, $t3, $a1
    ctx->r2 = SIGNED(ctx->r11) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x800426F8: beq         $v0, $zero, L_800425F8
    if (ctx->r2 == 0) {
        // 0x800426FC: addiu       $a3, $a3, 0x2
        ctx->r7 = ADD32(ctx->r7, 0X2);
            goto L_800425F8;
    }
    // 0x800426FC: addiu       $a3, $a3, 0x2
    ctx->r7 = ADD32(ctx->r7, 0X2);
    // 0x80042700: j           L_80042848
    // 0x80042704: nop

        goto L_80042848;
    // 0x80042704: nop

L_80042708:
    // 0x80042708: addu        $a1, $v0, $zero
    ctx->r5 = ADD32(ctx->r2, 0);
    // 0x8004270C: slt         $v0, $t3, $a1
    ctx->r2 = SIGNED(ctx->r11) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x80042710: bne         $v0, $zero, L_80042848
    if (ctx->r2 != 0) {
        // 0x80042714: lui         $v0, 0x8013
        ctx->r2 = S32(0X8013 << 16);
            goto L_80042848;
    }
    // 0x80042714: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80042718: mov.s       $f14, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    ctx->f14.fl = ctx->f4.fl;
    // 0x8004271C: addiu       $t4, $v0, 0xDB0
    ctx->r12 = ADD32(ctx->r2, 0XDB0);
    // 0x80042720: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80042724: addiu       $t0, $v0, 0xD10
    ctx->r8 = ADD32(ctx->r2, 0XD10);
    // 0x80042728: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8004272C: addiu       $a3, $v0, 0xC70
    ctx->r7 = ADD32(ctx->r2, 0XC70);
    // 0x80042730: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80042734: lwc1        $f12, -0x5B10($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X5B10);
    // 0x80042738: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8004273C: lwc1        $f10, -0x5B0C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X5B0C);
L_80042740:
    // 0x80042740: lh          $a0, 0x0($a3)
    ctx->r4 = MEM_H(ctx->r7, 0X0);
    // 0x80042744: lh          $a2, 0x0($t0)
    ctx->r6 = MEM_H(ctx->r8, 0X0);
    // 0x80042748: slt         $v0, $a2, $a0
    ctx->r2 = SIGNED(ctx->r6) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x8004274C: bnel        $v0, $zero, L_80042838
    if (ctx->r2 != 0) {
        // 0x80042750: addiu       $a1, $a1, 0x1
        ctx->r5 = ADD32(ctx->r5, 0X1);
            goto L_80042838;
    }
    goto skip_4;
    // 0x80042750: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    skip_4:
    // 0x80042754: addiu       $t2, $a1, 0x1
    ctx->r10 = ADD32(ctx->r5, 0X1);
    // 0x80042758: sll         $t1, $a1, 6
    ctx->r9 = S32(ctx->r5 << 6);
    // 0x8004275C: neg.s       $f8, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = -ctx->f20.fl;
L_80042760:
    // 0x80042760: lwc1        $f6, 0x34($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X34);
    // 0x80042764: lwc1        $f2, 0x30($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X30);
    // 0x80042768: c.lt.s      $f14, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f14.fl < ctx->f2.fl;
    // 0x8004276C: nop

    // 0x80042770: bc1f        L_8004278C
    if (!c1cs) {
        // 0x80042774: div.s       $f4, $f8, $f6
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = DIV_S(ctx->f8.fl, ctx->f6.fl);
            goto L_8004278C;
    }
    // 0x80042774: div.s       $f4, $f8, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = DIV_S(ctx->f8.fl, ctx->f6.fl);
    // 0x80042778: addiu       $v0, $a0, 0x1
    ctx->r2 = ADD32(ctx->r4, 0X1);
    // 0x8004277C: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x80042780: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x80042784: j           L_80042794
    // 0x80042788: nop

        goto L_80042794;
    // 0x80042788: nop

L_8004278C:
    // 0x8004278C: mtc1        $a0, $f0
    ctx->f0.u32l = ctx->r4;
    // 0x80042790: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
L_80042794:
    // 0x80042794: mul.s       $f0, $f2, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x80042798: div.s       $f0, $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f6.fl);
    // 0x8004279C: lwc1        $f2, 0x38($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X38);
    // 0x800427A0: c.lt.s      $f14, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f14.fl < ctx->f2.fl;
    // 0x800427A4: nop

    // 0x800427A8: bc1f        L_800427C0
    if (!c1cs) {
        // 0x800427AC: sub.s       $f4, $f4, $f0
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f4.fl - ctx->f0.fl;
            goto L_800427C0;
    }
    // 0x800427AC: sub.s       $f4, $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f4.fl - ctx->f0.fl;
    // 0x800427B0: mtc1        $t2, $f0
    ctx->f0.u32l = ctx->r10;
    // 0x800427B4: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x800427B8: j           L_800427C8
    // 0x800427BC: nop

        goto L_800427C8;
    // 0x800427BC: nop

L_800427C0:
    // 0x800427C0: mtc1        $a1, $f0
    ctx->f0.u32l = ctx->r5;
    // 0x800427C4: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
L_800427C8:
    // 0x800427C8: mul.s       $f0, $f2, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x800427CC: lwc1        $f2, 0x34($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X34);
    // 0x800427D0: div.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f2.fl);
    // 0x800427D4: sub.s       $f4, $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f4.fl - ctx->f0.fl;
    // 0x800427D8: mul.s       $f0, $f4, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f0.fl = MUL_S(ctx->f4.fl, ctx->f22.fl);
    // 0x800427DC: trunc.w.s   $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    ctx->f16.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800427E0: mfc1        $v0, $f16
    ctx->r2 = (int32_t)ctx->f16.u32l;
    // 0x800427E4: mtc1        $v0, $f4
    ctx->f4.u32l = ctx->r2;
    // 0x800427E8: cvt.s.w     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800427EC: c.lt.s      $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f12.fl < ctx->f4.fl;
    // 0x800427F0: nop

    // 0x800427F4: bc1t        L_80042810
    if (c1cs) {
        // 0x800427F8: mov.s       $f0, $f12
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
            goto L_80042810;
    }
    // 0x800427F8: mov.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
    // 0x800427FC: mov.s       $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.fl = ctx->f4.fl;
    // 0x80042800: c.lt.s      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.fl < ctx->f10.fl;
    // 0x80042804: nop

    // 0x80042808: bc1tl       L_80042810
    if (c1cs) {
        // 0x8004280C: mov.s       $f0, $f10
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    ctx->f0.fl = ctx->f10.fl;
            goto L_80042810;
    }
    goto skip_5;
    // 0x8004280C: mov.s       $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    ctx->f0.fl = ctx->f10.fl;
    skip_5:
L_80042810:
    // 0x80042810: addu        $v0, $a0, $t1
    ctx->r2 = ADD32(ctx->r4, ctx->r9);
    // 0x80042814: addu        $v0, $v0, $t4
    ctx->r2 = ADD32(ctx->r2, ctx->r12);
    // 0x80042818: trunc.w.s   $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    ctx->f16.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x8004281C: mfc1        $v1, $f16
    ctx->r3 = (int32_t)ctx->f16.u32l;
    // 0x80042820: sb          $v1, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r3;
    // 0x80042824: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x80042828: slt         $v0, $a2, $a0
    ctx->r2 = SIGNED(ctx->r6) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x8004282C: beq         $v0, $zero, L_80042760
    if (ctx->r2 == 0) {
        // 0x80042830: nop
    
            goto L_80042760;
    }
    // 0x80042830: nop

    // 0x80042834: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
L_80042838:
    // 0x80042838: addiu       $t0, $t0, 0x2
    ctx->r8 = ADD32(ctx->r8, 0X2);
    // 0x8004283C: slt         $v0, $t3, $a1
    ctx->r2 = SIGNED(ctx->r11) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x80042840: beq         $v0, $zero, L_80042740
    if (ctx->r2 == 0) {
        // 0x80042844: addiu       $a3, $a3, 0x2
        ctx->r7 = ADD32(ctx->r7, 0X2);
            goto L_80042740;
    }
    // 0x80042844: addiu       $a3, $a3, 0x2
    ctx->r7 = ADD32(ctx->r7, 0X2);
L_80042848:
    // 0x80042848: lw          $ra, 0x50($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X50);
    // 0x8004284C: lw          $s3, 0x4C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X4C);
    // 0x80042850: lw          $s2, 0x48($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X48);
    // 0x80042854: lw          $s1, 0x44($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X44);
    // 0x80042858: lw          $s0, 0x40($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X40);
    // 0x8004285C: ldc1        $f22, 0x60($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X60);
    // 0x80042860: ldc1        $f20, 0x58($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X58);
    // 0x80042864: jr          $ra
    // 0x80042868: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    return;
    // 0x80042868: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
;}
RECOMP_FUNC void func_8004286C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8004286C: addiu       $sp, $sp, -0x70
    ctx->r29 = ADD32(ctx->r29, -0X70);
    // 0x80042870: addiu       $v1, $a0, 0xC
    ctx->r3 = ADD32(ctx->r4, 0XC);
    // 0x80042874: addiu       $a1, $a0, 0x3C
    ctx->r5 = ADD32(ctx->r4, 0X3C);
    // 0x80042878: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8004287C: sw          $ra, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r31;
    // 0x80042880: sw          $s3, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r19;
    // 0x80042884: sw          $s2, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r18;
    // 0x80042888: sw          $s1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r17;
    // 0x8004288C: sw          $s0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r16;
    // 0x80042890: sdc1        $f20, 0x68($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X68, ctx->r29);
    // 0x80042894: lwc1        $f4, 0x0($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X0);
    // 0x80042898: lwc1        $f2, 0x6DD0($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X6DD0);
    // 0x8004289C: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x800428A0: lwc1        $f0, -0x5B08($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X5B08);
    // 0x800428A4: lwc1        $f6, 0x8($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X8);
    // 0x800428A8: div.s       $f20, $f0, $f2
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f20.fl = DIV_S(ctx->f0.fl, ctx->f2.fl);
    // 0x800428AC: mov.s       $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    ctx->f2.fl = ctx->f4.fl;
    // 0x800428B0: mov.s       $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = ctx->f6.fl;
L_800428B4:
    // 0x800428B4: lwc1        $f0, 0x0($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X0);
    // 0x800428B8: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x800428BC: nop

    // 0x800428C0: bc1f        L_800428D0
    if (!c1cs) {
        // 0x800428C4: nop
    
            goto L_800428D0;
    }
    // 0x800428C4: nop

    // 0x800428C8: j           L_800428E0
    // 0x800428CC: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
        goto L_800428E0;
    // 0x800428CC: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
L_800428D0:
    // 0x800428D0: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x800428D4: nop

    // 0x800428D8: bc1tl       L_800428E0
    if (c1cs) {
        // 0x800428DC: mov.s       $f4, $f0
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    ctx->f4.fl = ctx->f0.fl;
            goto L_800428E0;
    }
    goto skip_0;
    // 0x800428DC: mov.s       $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    ctx->f4.fl = ctx->f0.fl;
    skip_0:
L_800428E0:
    // 0x800428E0: lwc1        $f0, 0x8($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X8);
    // 0x800428E4: c.lt.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl < ctx->f8.fl;
    // 0x800428E8: nop

    // 0x800428EC: bc1f        L_800428FC
    if (!c1cs) {
        // 0x800428F0: nop
    
            goto L_800428FC;
    }
    // 0x800428F0: nop

    // 0x800428F4: j           L_8004290C
    // 0x800428F8: mov.s       $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    ctx->f8.fl = ctx->f0.fl;
        goto L_8004290C;
    // 0x800428F8: mov.s       $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    ctx->f8.fl = ctx->f0.fl;
L_800428FC:
    // 0x800428FC: c.lt.s      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.fl < ctx->f0.fl;
    // 0x80042900: nop

    // 0x80042904: bc1tl       L_8004290C
    if (c1cs) {
        // 0x80042908: mov.s       $f6, $f0
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    ctx->f6.fl = ctx->f0.fl;
            goto L_8004290C;
    }
    goto skip_1;
    // 0x80042908: mov.s       $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    ctx->f6.fl = ctx->f0.fl;
    skip_1:
L_8004290C:
    // 0x8004290C: addiu       $v1, $v1, 0xC
    ctx->r3 = ADD32(ctx->r3, 0XC);
    // 0x80042910: slt         $v0, $v1, $a1
    ctx->r2 = SIGNED(ctx->r3) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x80042914: bne         $v0, $zero, L_800428B4
    if (ctx->r2 != 0) {
        // 0x80042918: nop
    
            goto L_800428B4;
    }
    // 0x80042918: nop

    // 0x8004291C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80042920: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x80042924: nop

    // 0x80042928: bc1t        L_80042934
    if (c1cs) {
        // 0x8004292C: addiu       $v1, $zero, 0x1
        ctx->r3 = ADD32(0, 0X1);
            goto L_80042934;
    }
    // 0x8004292C: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x80042930: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
L_80042934:
    // 0x80042934: trunc.w.s   $f10, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    ctx->f10.u32l = TRUNC_W_S(ctx->f2.fl);
    // 0x80042938: mfc1        $v0, $f10
    ctx->r2 = (int32_t)ctx->f10.u32l;
    // 0x8004293C: subu        $a3, $v0, $v1
    ctx->r7 = SUB32(ctx->r2, ctx->r3);
    // 0x80042940: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80042944: sw          $a3, 0x2DB0($v0)
    MEM_W(0X2DB0, ctx->r2) = ctx->r7;
    // 0x80042948: c.le.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl <= ctx->f4.fl;
    // 0x8004294C: nop

    // 0x80042950: bc1t        L_8004295C
    if (c1cs) {
        // 0x80042954: addiu       $v1, $zero, 0x1
        ctx->r3 = ADD32(0, 0X1);
            goto L_8004295C;
    }
    // 0x80042954: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x80042958: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
L_8004295C:
    // 0x8004295C: trunc.w.s   $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    ctx->f10.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x80042960: mfc1        $v0, $f10
    ctx->r2 = (int32_t)ctx->f10.u32l;
    // 0x80042964: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80042968: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x8004296C: sw          $v0, 0x2DB4($v1)
    MEM_W(0X2DB4, ctx->r3) = ctx->r2;
    // 0x80042970: c.lt.s      $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f8.fl < ctx->f0.fl;
    // 0x80042974: nop

    // 0x80042978: bc1t        L_80042984
    if (c1cs) {
        // 0x8004297C: addiu       $v1, $zero, 0x1
        ctx->r3 = ADD32(0, 0X1);
            goto L_80042984;
    }
    // 0x8004297C: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x80042980: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
L_80042984:
    // 0x80042984: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x80042988: mfc1        $v0, $f10
    ctx->r2 = (int32_t)ctx->f10.u32l;
    // 0x8004298C: subu        $a2, $v0, $v1
    ctx->r6 = SUB32(ctx->r2, ctx->r3);
    // 0x80042990: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80042994: sw          $a2, 0x2DB8($v0)
    MEM_W(0X2DB8, ctx->r2) = ctx->r6;
    // 0x80042998: c.le.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl <= ctx->f6.fl;
    // 0x8004299C: nop

    // 0x800429A0: bc1t        L_800429AC
    if (c1cs) {
        // 0x800429A4: addiu       $v1, $zero, 0x1
        ctx->r3 = ADD32(0, 0X1);
            goto L_800429AC;
    }
    // 0x800429A4: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x800429A8: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
L_800429AC:
    // 0x800429AC: trunc.w.s   $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x800429B0: mfc1        $v0, $f10
    ctx->r2 = (int32_t)ctx->f10.u32l;
    // 0x800429B4: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800429B8: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x800429BC: sw          $v0, 0x2DBC($v1)
    MEM_W(0X2DBC, ctx->r3) = ctx->r2;
    // 0x800429C0: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x800429C4: mtc1        $a3, $f4
    ctx->f4.u32l = ctx->r7;
    // 0x800429C8: cvt.s.w     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800429CC: mtc1        $a2, $f2
    ctx->f2.u32l = ctx->r6;
    // 0x800429D0: cvt.s.w     $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    ctx->f2.fl = CVT_S_W(ctx->f2.u32l);
    // 0x800429D4: addiu       $v1, $sp, 0x10
    ctx->r3 = ADD32(ctx->r29, 0X10);
L_800429D8:
    // 0x800429D8: lwc1        $f0, 0x0($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X0);
    // 0x800429DC: sub.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f4.fl;
    // 0x800429E0: swc1        $f0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f0.u32l;
    // 0x800429E4: lwc1        $f0, 0x4($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X4);
    // 0x800429E8: swc1        $f0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->f0.u32l;
    // 0x800429EC: lwc1        $f0, 0x8($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X8);
    // 0x800429F0: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x800429F4: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x800429F8: slti        $v0, $a1, 0x5
    ctx->r2 = SIGNED(ctx->r5) < 0X5 ? 1 : 0;
    // 0x800429FC: addiu       $a0, $a0, 0xC
    ctx->r4 = ADD32(ctx->r4, 0XC);
    // 0x80042A00: swc1        $f0, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->f0.u32l;
    // 0x80042A04: bne         $v0, $zero, L_800429D8
    if (ctx->r2 != 0) {
        // 0x80042A08: addiu       $v1, $v1, 0xC
        ctx->r3 = ADD32(ctx->r3, 0XC);
            goto L_800429D8;
    }
    // 0x80042A08: addiu       $v1, $v1, 0xC
    ctx->r3 = ADD32(ctx->r3, 0XC);
    // 0x80042A0C: lui         $t0, 0x8013
    ctx->r8 = S32(0X8013 << 16);
    // 0x80042A10: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    // 0x80042A14: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80042A18: lui         $a2, 0x8013
    ctx->r6 = S32(0X8013 << 16);
    // 0x80042A1C: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x80042A20: lw          $v1, 0x2DB4($t0)
    ctx->r3 = MEM_W(ctx->r8, 0X2DB4);
    // 0x80042A24: lw          $a0, 0x2DB0($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X2DB0);
    // 0x80042A28: lw          $v0, 0x2DBC($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X2DBC);
    // 0x80042A2C: lw          $a1, 0x2DB8($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X2DB8);
    // 0x80042A30: subu        $v1, $v1, $a0
    ctx->r3 = SUB32(ctx->r3, ctx->r4);
    // 0x80042A34: subu        $v0, $v0, $a1
    ctx->r2 = SUB32(ctx->r2, ctx->r5);
    // 0x80042A38: sw          $v1, 0x2DB4($t0)
    MEM_W(0X2DB4, ctx->r8) = ctx->r3;
    // 0x80042A3C: blez        $v0, L_80042AA8
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80042A40: sw          $v0, 0x2DBC($a2)
        MEM_W(0X2DBC, ctx->r6) = ctx->r2;
            goto L_80042AA8;
    }
    // 0x80042A40: sw          $v0, 0x2DBC($a2)
    MEM_W(0X2DBC, ctx->r6) = ctx->r2;
    // 0x80042A44: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80042A48: addiu       $t2, $v0, 0xDB0
    ctx->r10 = ADD32(ctx->r2, 0XDB0);
    // 0x80042A4C: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80042A50: addiu       $t1, $v0, 0x1DB0
    ctx->r9 = ADD32(ctx->r2, 0X1DB0);
    // 0x80042A54: addiu       $a2, $zero, -0x80
    ctx->r6 = ADD32(0, -0X80);
L_80042A58:
    // 0x80042A58: lw          $v0, 0x2DB4($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X2DB4);
    // 0x80042A5C: blez        $v0, L_80042A90
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80042A60: addu        $a0, $zero, $zero
        ctx->r4 = ADD32(0, 0);
            goto L_80042A90;
    }
    // 0x80042A60: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x80042A64: sll         $a1, $a3, 6
    ctx->r5 = S32(ctx->r7 << 6);
    // 0x80042A68: addu        $v0, $a0, $a1
    ctx->r2 = ADD32(ctx->r4, ctx->r5);
L_80042A6C:
    // 0x80042A6C: addu        $v1, $v0, $t1
    ctx->r3 = ADD32(ctx->r2, ctx->r9);
    // 0x80042A70: addu        $v0, $v0, $t2
    ctx->r2 = ADD32(ctx->r2, ctx->r10);
    // 0x80042A74: sb          $a2, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r6;
    // 0x80042A78: sb          $a2, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r6;
    // 0x80042A7C: lw          $v0, 0x2DB4($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X2DB4);
    // 0x80042A80: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x80042A84: slt         $v0, $a0, $v0
    ctx->r2 = SIGNED(ctx->r4) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80042A88: bne         $v0, $zero, L_80042A6C
    if (ctx->r2 != 0) {
        // 0x80042A8C: addu        $v0, $a0, $a1
        ctx->r2 = ADD32(ctx->r4, ctx->r5);
            goto L_80042A6C;
    }
    // 0x80042A8C: addu        $v0, $a0, $a1
    ctx->r2 = ADD32(ctx->r4, ctx->r5);
L_80042A90:
    // 0x80042A90: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80042A94: lw          $v0, 0x2DBC($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X2DBC);
    // 0x80042A98: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x80042A9C: slt         $v0, $a3, $v0
    ctx->r2 = SIGNED(ctx->r7) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80042AA0: bne         $v0, $zero, L_80042A58
    if (ctx->r2 != 0) {
        // 0x80042AA4: nop
    
            goto L_80042A58;
    }
    // 0x80042AA4: nop

L_80042AA8:
    // 0x80042AA8: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    // 0x80042AAC: addiu       $s2, $sp, 0x1C
    ctx->r18 = ADD32(ctx->r29, 0X1C);
    // 0x80042AB0: addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    // 0x80042AB4: addiu       $s3, $sp, 0x28
    ctx->r19 = ADD32(ctx->r29, 0X28);
    // 0x80042AB8: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x80042ABC: jal         0x80042298
    // 0x80042AC0: addu        $a2, $s3, $zero
    ctx->r6 = ADD32(ctx->r19, 0);
    func_80042298(rdram, ctx);
        goto after_0;
    // 0x80042AC0: addu        $a2, $s3, $zero
    ctx->r6 = ADD32(ctx->r19, 0);
    after_0:
    // 0x80042AC4: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    // 0x80042AC8: addu        $a1, $s3, $zero
    ctx->r5 = ADD32(ctx->r19, 0);
    // 0x80042ACC: addiu       $s1, $sp, 0x34
    ctx->r17 = ADD32(ctx->r29, 0X34);
    // 0x80042AD0: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x80042AD4: jal         0x80042298
    // 0x80042AD8: addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    func_80042298(rdram, ctx);
        goto after_1;
    // 0x80042AD8: addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    after_1:
    // 0x80042ADC: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    // 0x80042AE0: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    // 0x80042AE4: addiu       $s0, $sp, 0x40
    ctx->r16 = ADD32(ctx->r29, 0X40);
    // 0x80042AE8: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x80042AEC: jal         0x80042298
    // 0x80042AF0: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    func_80042298(rdram, ctx);
        goto after_2;
    // 0x80042AF0: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    after_2:
    // 0x80042AF4: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    // 0x80042AF8: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x80042AFC: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x80042B00: jal         0x80042298
    // 0x80042B04: addu        $a2, $s2, $zero
    ctx->r6 = ADD32(ctx->r18, 0);
    func_80042298(rdram, ctx);
        goto after_3;
    // 0x80042B04: addu        $a2, $s2, $zero
    ctx->r6 = ADD32(ctx->r18, 0);
    after_3:
    // 0x80042B08: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // 0x80042B0C: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x80042B10: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x80042B14: jal         0x80042298
    // 0x80042B18: addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    func_80042298(rdram, ctx);
        goto after_4;
    // 0x80042B18: addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    after_4:
    // 0x80042B1C: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x80042B20: addu        $a1, $s3, $zero
    ctx->r5 = ADD32(ctx->r19, 0);
    // 0x80042B24: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x80042B28: jal         0x80042298
    // 0x80042B2C: addu        $a2, $s2, $zero
    ctx->r6 = ADD32(ctx->r18, 0);
    func_80042298(rdram, ctx);
        goto after_5;
    // 0x80042B2C: addu        $a2, $s2, $zero
    ctx->r6 = ADD32(ctx->r18, 0);
    after_5:
    // 0x80042B30: lw          $ra, 0x60($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X60);
    // 0x80042B34: lw          $s3, 0x5C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X5C);
    // 0x80042B38: lw          $s2, 0x58($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X58);
    // 0x80042B3C: lw          $s1, 0x54($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X54);
    // 0x80042B40: lw          $s0, 0x50($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X50);
    // 0x80042B44: ldc1        $f20, 0x68($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X68);
    // 0x80042B48: jr          $ra
    // 0x80042B4C: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
    return;
    // 0x80042B4C: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
;}
RECOMP_FUNC void func_80042B50(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80042B50: addiu       $sp, $sp, -0x80
    ctx->r29 = ADD32(ctx->r29, -0X80);
    // 0x80042B54: sw          $s1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r17;
    // 0x80042B58: addu        $s1, $zero, $zero
    ctx->r17 = ADD32(0, 0);
    // 0x80042B5C: addu        $t1, $s1, $zero
    ctx->r9 = ADD32(ctx->r17, 0);
    // 0x80042B60: addu        $a3, $s1, $zero
    ctx->r7 = ADD32(ctx->r17, 0);
    // 0x80042B64: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80042B68: lwc1        $f0, 0x2DB8($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X2DB8);
    // 0x80042B6C: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x80042B70: addu        $t3, $s1, $zero
    ctx->r11 = ADD32(ctx->r17, 0);
    // 0x80042B74: sw          $a1, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r5;
    // 0x80042B78: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x80042B7C: lui         $a2, 0x8013
    ctx->r6 = S32(0X8013 << 16);
    // 0x80042B80: sw          $ra, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r31;
    // 0x80042B84: sw          $fp, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r30;
    // 0x80042B88: sw          $s7, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r23;
    // 0x80042B8C: sw          $s6, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r22;
    // 0x80042B90: sw          $s5, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r21;
    // 0x80042B94: sw          $s4, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r20;
    // 0x80042B98: sw          $s3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r19;
    // 0x80042B9C: sw          $s2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r18;
    // 0x80042BA0: sw          $s0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r16;
    // 0x80042BA4: sdc1        $f26, 0x78($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X78, ctx->r29);
    // 0x80042BA8: sdc1        $f24, 0x70($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X70, ctx->r29);
    // 0x80042BAC: sdc1        $f22, 0x68($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X68, ctx->r29);
    // 0x80042BB0: sdc1        $f20, 0x60($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X60, ctx->r29);
    // 0x80042BB4: sw          $a0, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r4;
    // 0x80042BB8: lwc1        $f2, 0x8($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X8);
    // 0x80042BBC: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80042BC0: addiu       $v0, $a0, 0x6DC0
    ctx->r2 = ADD32(ctx->r4, 0X6DC0);
    // 0x80042BC4: lw          $a1, 0x2DB4($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X2DB4);
    // 0x80042BC8: lw          $a2, 0x2DBC($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X2DBC);
    // 0x80042BCC: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x80042BD0: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80042BD4: lwc1        $f2, -0x5B04($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X5B04);
    // 0x80042BD8: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x80042BDC: sw          $a1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r5;
    // 0x80042BE0: sw          $a2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r6;
    // 0x80042BE4: lhu         $a2, 0x38($v0)
    ctx->r6 = MEM_HU(ctx->r2, 0X38);
    // 0x80042BE8: lw          $a1, 0x2DB0($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X2DB0);
    // 0x80042BEC: lw          $v1, 0x6DC0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X6DC0);
    // 0x80042BF0: bgez        $a1, L_80042C04
    if (SIGNED(ctx->r5) >= 0) {
        // 0x80042BF4: add.s       $f22, $f0, $f2
        CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f22.fl = ctx->f0.fl + ctx->f2.fl;
            goto L_80042C04;
    }
    // 0x80042BF4: add.s       $f22, $f0, $f2
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f22.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x80042BF8: addu        $s2, $v1, $zero
    ctx->r18 = ADD32(ctx->r3, 0);
    // 0x80042BFC: j           L_80042C28
    // 0x80042C00: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
        goto L_80042C28;
    // 0x80042C00: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
L_80042C04:
    // 0x80042C04: slt         $v0, $a1, $a2
    ctx->r2 = SIGNED(ctx->r5) < SIGNED(ctx->r6) ? 1 : 0;
    // 0x80042C08: bne         $v0, $zero, L_80042C24
    if (ctx->r2 != 0) {
        // 0x80042C0C: sll         $v0, $a1, 1
        ctx->r2 = S32(ctx->r5 << 1);
            goto L_80042C24;
    }
    // 0x80042C0C: sll         $v0, $a1, 1
    ctx->r2 = S32(ctx->r5 << 1);
    // 0x80042C10: sll         $v0, $a2, 1
    ctx->r2 = S32(ctx->r6 << 1);
    // 0x80042C14: addiu       $v0, $v0, -0x2
    ctx->r2 = ADD32(ctx->r2, -0X2);
    // 0x80042C18: addu        $s2, $v1, $v0
    ctx->r18 = ADD32(ctx->r3, ctx->r2);
    // 0x80042C1C: j           L_80042C28
    // 0x80042C20: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
        goto L_80042C28;
    // 0x80042C20: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
L_80042C24:
    // 0x80042C24: addu        $s2, $v1, $v0
    ctx->r18 = ADD32(ctx->r3, ctx->r2);
L_80042C28:
    // 0x80042C28: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80042C2C: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x80042C30: addiu       $v1, $v1, 0x6DC0
    ctx->r3 = ADD32(ctx->r3, 0X6DC0);
    // 0x80042C34: lhu         $a1, 0x3A($v1)
    ctx->r5 = MEM_HU(ctx->r3, 0X3A);
    // 0x80042C38: lw          $a0, 0x2DB8($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X2DB8);
    // 0x80042C3C: slt         $v0, $a0, $a1
    ctx->r2 = SIGNED(ctx->r4) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x80042C40: bne         $v0, $zero, L_80042C60
    if (ctx->r2 != 0) {
        // 0x80042C44: addiu       $v0, $a1, -0x1
        ctx->r2 = ADD32(ctx->r5, -0X1);
            goto L_80042C60;
    }
    // 0x80042C44: addiu       $v0, $a1, -0x1
    ctx->r2 = ADD32(ctx->r5, -0X1);
    // 0x80042C48: lhu         $v1, 0x38($v1)
    ctx->r3 = MEM_HU(ctx->r3, 0X38);
    // 0x80042C4C: mult        $v1, $v0
    result = S64(S32(ctx->r3)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80042C50: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x80042C54: mflo        $t6
    ctx->r14 = lo;
    // 0x80042C58: j           L_80042C80
    // 0x80042C5C: sllv        $v0, $t6, $t3
    ctx->r2 = S32(ctx->r14 << (ctx->r11 & 31));
        goto L_80042C80;
    // 0x80042C5C: sllv        $v0, $t6, $t3
    ctx->r2 = S32(ctx->r14 << (ctx->r11 & 31));
L_80042C60:
    // 0x80042C60: bgez        $a0, L_80042C70
    if (SIGNED(ctx->r4) >= 0) {
        // 0x80042C64: nop
    
            goto L_80042C70;
    }
    // 0x80042C64: nop

    // 0x80042C68: j           L_80042C84
    // 0x80042C6C: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
        goto L_80042C84;
    // 0x80042C6C: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
L_80042C70:
    // 0x80042C70: lhu         $v0, 0x38($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X38);
    // 0x80042C74: mult        $v0, $a0
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80042C78: mflo        $t6
    ctx->r14 = lo;
    // 0x80042C7C: sll         $v0, $t6, 1
    ctx->r2 = S32(ctx->r14 << 1);
L_80042C80:
    // 0x80042C80: addu        $s2, $s2, $v0
    ctx->r18 = ADD32(ctx->r18, ctx->r2);
L_80042C84:
    // 0x80042C84: lui         $a2, 0x8013
    ctx->r6 = S32(0X8013 << 16);
    // 0x80042C88: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x80042C8C: lui         $t0, 0x8013
    ctx->r8 = S32(0X8013 << 16);
    // 0x80042C90: addiu       $a1, $t0, 0x6DC0
    ctx->r5 = ADD32(ctx->r8, 0X6DC0);
    // 0x80042C94: lw          $v0, 0x2DB0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X2DB0);
    // 0x80042C98: lw          $v1, 0x2DB4($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X2DB4);
    // 0x80042C9C: lhu         $a0, 0x38($a1)
    ctx->r4 = MEM_HU(ctx->r5, 0X38);
    // 0x80042CA0: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80042CA4: slt         $v0, $v0, $a0
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x80042CA8: beql        $v0, $zero, L_80042CB0
    if (ctx->r2 == 0) {
        // 0x80042CAC: addiu       $t3, $zero, 0x1
        ctx->r11 = ADD32(0, 0X1);
            goto L_80042CB0;
    }
    goto skip_0;
    // 0x80042CAC: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    skip_0:
L_80042CB0:
    // 0x80042CB0: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80042CB4: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x80042CB8: lw          $v0, 0x2DB8($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X2DB8);
    // 0x80042CBC: lw          $v1, 0x2DBC($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X2DBC);
    // 0x80042CC0: lhu         $a0, 0x3A($a1)
    ctx->r4 = MEM_HU(ctx->r5, 0X3A);
    // 0x80042CC4: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80042CC8: slt         $v0, $v0, $a0
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x80042CCC: beql        $v0, $zero, L_80042CD4
    if (ctx->r2 == 0) {
        // 0x80042CD0: addiu       $t3, $zero, 0x1
        ctx->r11 = ADD32(0, 0X1);
            goto L_80042CD4;
    }
    goto skip_1;
    // 0x80042CD0: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    skip_1:
L_80042CD4:
    // 0x80042CD4: lw          $t6, 0x14($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X14);
    // 0x80042CD8: blez        $t6, L_80043138
    if (SIGNED(ctx->r14) <= 0) {
        // 0x80042CDC: addu        $fp, $zero, $zero
        ctx->r30 = ADD32(0, 0);
            goto L_80043138;
    }
    // 0x80042CDC: addu        $fp, $zero, $zero
    ctx->r30 = ADD32(0, 0);
    // 0x80042CE0: addu        $t4, $a2, $zero
    ctx->r12 = ADD32(ctx->r6, 0);
    // 0x80042CE4: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80042CE8: lwc1        $f26, -0x5B00($at)
    ctx->f26.u32l = MEM_W(ctx->r1, -0X5B00);
    // 0x80042CEC: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80042CF0: addiu       $t5, $v0, 0x1DB0
    ctx->r13 = ADD32(ctx->r2, 0X1DB0);
    // 0x80042CF4: addu        $t0, $a1, $zero
    ctx->r8 = ADD32(ctx->r5, 0);
L_80042CF8:
    // 0x80042CF8: lw          $t6, 0x80($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X80);
    // 0x80042CFC: lwc1        $f0, 0x2DB0($t4)
    ctx->f0.u32l = MEM_W(ctx->r12, 0X2DB0);
    // 0x80042D00: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x80042D04: lwc1        $f2, 0x0($t6)
    ctx->f2.u32l = MEM_W(ctx->r14, 0X0);
    // 0x80042D08: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x80042D0C: addu        $s4, $zero, $zero
    ctx->r20 = ADD32(0, 0);
    // 0x80042D10: lw          $t6, 0x10($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X10);
    // 0x80042D14: blez        $t6, L_80043070
    if (SIGNED(ctx->r14) <= 0) {
        // 0x80042D18: add.s       $f20, $f0, $f26
        CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f20.fl = ctx->f0.fl + ctx->f26.fl;
            goto L_80043070;
    }
    // 0x80042D18: add.s       $f20, $f0, $f26
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f20.fl = ctx->f0.fl + ctx->f26.fl;
    // 0x80042D1C: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80042D20: addiu       $t2, $v0, 0x2DC0
    ctx->r10 = ADD32(ctx->r2, 0X2DC0);
    // 0x80042D24: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80042D28: lwc1        $f24, -0x5AFC($at)
    ctx->f24.u32l = MEM_W(ctx->r1, -0X5AFC);
    // 0x80042D2C: sll         $s6, $fp, 8
    ctx->r22 = S32(ctx->r30 << 8);
    // 0x80042D30: sll         $v0, $a3, 1
    ctx->r2 = S32(ctx->r7 << 1);
    // 0x80042D34: addu        $v0, $v0, $a3
    ctx->r2 = ADD32(ctx->r2, ctx->r7);
    // 0x80042D38: sll         $s7, $v0, 3
    ctx->r23 = S32(ctx->r2 << 3);
L_80042D3C:
    // 0x80042D3C: sll         $v0, $fp, 6
    ctx->r2 = S32(ctx->r30 << 6);
    // 0x80042D40: addu        $a1, $s4, $v0
    ctx->r5 = ADD32(ctx->r20, ctx->r2);
    // 0x80042D44: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x80042D48: addiu       $t6, $t6, 0xDB0
    ctx->r14 = ADD32(ctx->r14, 0XDB0);
    // 0x80042D4C: addu        $s5, $a1, $t6
    ctx->r21 = ADD32(ctx->r5, ctx->r14);
    // 0x80042D50: lb          $a0, 0x0($s5)
    ctx->r4 = MEM_B(ctx->r21, 0X0);
    // 0x80042D54: addiu       $v0, $zero, -0x80
    ctx->r2 = ADD32(0, -0X80);
    // 0x80042D58: bne         $a0, $v0, L_80042D6C
    if (ctx->r4 != ctx->r2) {
        // 0x80042D5C: addu        $v0, $a1, $t5
        ctx->r2 = ADD32(ctx->r5, ctx->r13);
            goto L_80042D6C;
    }
    // 0x80042D5C: addu        $v0, $a1, $t5
    ctx->r2 = ADD32(ctx->r5, ctx->r13);
    // 0x80042D60: lb          $v0, 0x0($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X0);
    // 0x80042D64: beq         $v0, $a0, L_80043020
    if (ctx->r2 == ctx->r4) {
        // 0x80042D68: addu        $v0, $s6, $t2
        ctx->r2 = ADD32(ctx->r22, ctx->r10);
            goto L_80043020;
    }
    // 0x80042D68: addu        $v0, $s6, $t2
    ctx->r2 = ADD32(ctx->r22, ctx->r10);
L_80042D6C:
    // 0x80042D6C: lhu         $v1, 0x0($s2)
    ctx->r3 = MEM_HU(ctx->r18, 0X0);
    // 0x80042D70: andi        $v1, $v1, 0x1FFF
    ctx->r3 = ctx->r3 & 0X1FFF;
    // 0x80042D74: sll         $v0, $v1, 4
    ctx->r2 = S32(ctx->r3 << 4);
    // 0x80042D78: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x80042D7C: lw          $v1, 0x4($t0)
    ctx->r3 = MEM_W(ctx->r8, 0X4);
    // 0x80042D80: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x80042D84: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x80042D88: lb          $v0, 0x3($v1)
    ctx->r2 = MEM_B(ctx->r3, 0X3);
    // 0x80042D8C: slt         $v0, $a0, $v0
    ctx->r2 = SIGNED(ctx->r4) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80042D90: bne         $v0, $zero, L_80042DB0
    if (ctx->r2 != 0) {
        // 0x80042D94: addu        $v0, $a1, $t5
        ctx->r2 = ADD32(ctx->r5, ctx->r13);
            goto L_80042DB0;
    }
    // 0x80042D94: addu        $v0, $a1, $t5
    ctx->r2 = ADD32(ctx->r5, ctx->r13);
    // 0x80042D98: addu        $s3, $a1, $t5
    ctx->r19 = ADD32(ctx->r5, ctx->r13);
    // 0x80042D9C: lb          $v0, 0x4($v1)
    ctx->r2 = MEM_B(ctx->r3, 0X4);
    // 0x80042DA0: lb          $v1, 0x0($s3)
    ctx->r3 = MEM_B(ctx->r19, 0X0);
    // 0x80042DA4: slt         $v0, $v0, $v1
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80042DA8: beq         $v0, $zero, L_80042DC4
    if (ctx->r2 == 0) {
        // 0x80042DAC: addu        $v0, $a1, $t5
        ctx->r2 = ADD32(ctx->r5, ctx->r13);
            goto L_80042DC4;
    }
    // 0x80042DAC: addu        $v0, $a1, $t5
    ctx->r2 = ADD32(ctx->r5, ctx->r13);
L_80042DB0:
    // 0x80042DB0: addiu       $v1, $zero, 0x7F
    ctx->r3 = ADD32(0, 0X7F);
    // 0x80042DB4: sb          $v1, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r3;
    // 0x80042DB8: addu        $v0, $s6, $t2
    ctx->r2 = ADD32(ctx->r22, ctx->r10);
    // 0x80042DBC: j           L_80043020
    // 0x80042DC0: sb          $v1, 0x0($s5)
    MEM_B(0X0, ctx->r21) = ctx->r3;
        goto L_80043020;
    // 0x80042DC0: sb          $v1, 0x0($s5)
    MEM_B(0X0, ctx->r21) = ctx->r3;
L_80042DC4:
    // 0x80042DC4: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80042DC8: lw          $v0, 0x6E1C($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X6E1C);
    // 0x80042DCC: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x80042DD0: addu        $s0, $v0, $s7
    ctx->r16 = ADD32(ctx->r2, ctx->r23);
    // 0x80042DD4: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80042DD8: lhu         $v0, 0xC4C($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0XC4C);
    // 0x80042DDC: slt         $v0, $a3, $v0
    ctx->r2 = SIGNED(ctx->r7) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80042DE0: beq         $v0, $zero, L_80043070
    if (ctx->r2 == 0) {
        // 0x80042DE4: addiu       $s7, $s7, 0x18
        ctx->r23 = ADD32(ctx->r23, 0X18);
            goto L_80043070;
    }
    // 0x80042DE4: addiu       $s7, $s7, 0x18
    ctx->r23 = ADD32(ctx->r23, 0X18);
    // 0x80042DE8: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x80042DEC: lw          $a0, 0x2DB0($t4)
    ctx->r4 = MEM_W(ctx->r12, 0X2DB0);
    // 0x80042DF0: lw          $a1, 0x2DB8($t6)
    ctx->r5 = MEM_W(ctx->r14, 0X2DB8);
    // 0x80042DF4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80042DF8: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    // 0x80042DFC: sw          $t0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r8;
    // 0x80042E00: sw          $t1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r9;
    // 0x80042E04: sw          $t2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r10;
    // 0x80042E08: sw          $t3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r11;
    // 0x80042E0C: sw          $t4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r12;
    // 0x80042E10: sw          $t5, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r13;
    // 0x80042E14: addu        $a0, $s4, $a0
    ctx->r4 = ADD32(ctx->r20, ctx->r4);
    // 0x80042E18: jal         0x80048508
    // 0x80042E1C: addu        $a1, $fp, $a1
    ctx->r5 = ADD32(ctx->r30, ctx->r5);
    func_80048508(rdram, ctx);
        goto after_0;
    // 0x80042E1C: addu        $a1, $fp, $a1
    ctx->r5 = ADD32(ctx->r30, ctx->r5);
    after_0:
    // 0x80042E20: sw          $v0, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->r2;
    // 0x80042E24: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
    // 0x80042E28: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x80042E2C: lw          $t1, 0x20($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X20);
    // 0x80042E30: lw          $t2, 0x24($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X24);
    // 0x80042E34: lw          $t3, 0x28($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X28);
    // 0x80042E38: lw          $t4, 0x2C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X2C);
    // 0x80042E3C: lw          $t5, 0x30($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X30);
    // 0x80042E40: beq         $v0, $zero, L_80042EA4
    if (ctx->r2 == 0) {
        // 0x80042E44: addu        $a0, $v0, $zero
        ctx->r4 = ADD32(ctx->r2, 0);
            goto L_80042EA4;
    }
    // 0x80042E44: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // 0x80042E48: mul.s       $f0, $f20, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = MUL_S(ctx->f20.fl, ctx->f20.fl);
    // 0x80042E4C: nop

    // 0x80042E50: mul.s       $f2, $f22, $f22
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f2.fl = MUL_S(ctx->f22.fl, ctx->f22.fl);
    // 0x80042E54: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    // 0x80042E58: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x80042E5C: sw          $s4, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r20;
    // 0x80042E60: sw          $fp, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->r30;
    // 0x80042E64: swc1        $f0, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f0.u32l;
    // 0x80042E68: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    // 0x80042E6C: sw          $t0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r8;
    // 0x80042E70: sw          $t1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r9;
    // 0x80042E74: sw          $t2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r10;
    // 0x80042E78: sw          $t3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r11;
    // 0x80042E7C: sw          $t4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r12;
    // 0x80042E80: jal         0x80048BAC
    // 0x80042E84: sw          $t5, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r13;
    func_80048BAC(rdram, ctx);
        goto after_1;
    // 0x80042E84: sw          $t5, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r13;
    after_1:
    // 0x80042E88: lw          $t5, 0x30($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X30);
    // 0x80042E8C: lw          $t4, 0x2C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X2C);
    // 0x80042E90: lw          $t3, 0x28($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X28);
    // 0x80042E94: lw          $t2, 0x24($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X24);
    // 0x80042E98: lw          $t1, 0x20($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X20);
    // 0x80042E9C: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x80042EA0: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
L_80042EA4:
    // 0x80042EA4: lw          $v0, 0x14($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X14);
    // 0x80042EA8: bne         $v0, $zero, L_80042EC8
    if (ctx->r2 != 0) {
        // 0x80042EAC: addu        $v0, $s6, $t2
        ctx->r2 = ADD32(ctx->r22, ctx->r10);
            goto L_80042EC8;
    }
    // 0x80042EAC: addu        $v0, $s6, $t2
    ctx->r2 = ADD32(ctx->r22, ctx->r10);
    // 0x80042EB0: addiu       $s7, $s7, -0x18
    ctx->r23 = ADD32(ctx->r23, -0X18);
    // 0x80042EB4: addiu       $a3, $a3, -0x1
    ctx->r7 = ADD32(ctx->r7, -0X1);
    // 0x80042EB8: addiu       $v0, $zero, 0x7E
    ctx->r2 = ADD32(0, 0X7E);
    // 0x80042EBC: sb          $v0, 0x0($s3)
    MEM_B(0X0, ctx->r19) = ctx->r2;
    // 0x80042EC0: j           L_8004301C
    // 0x80042EC4: sb          $v0, 0x0($s5)
    MEM_B(0X0, ctx->r21) = ctx->r2;
        goto L_8004301C;
    // 0x80042EC4: sb          $v0, 0x0($s5)
    MEM_B(0X0, ctx->r21) = ctx->r2;
L_80042EC8:
    // 0x80042EC8: lw          $v1, 0x2DB0($t4)
    ctx->r3 = MEM_W(ctx->r12, 0X2DB0);
    // 0x80042ECC: sw          $s0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r16;
    // 0x80042ED0: addu        $v1, $s4, $v1
    ctx->r3 = ADD32(ctx->r20, ctx->r3);
    // 0x80042ED4: mtc1        $v1, $f0
    ctx->f0.u32l = ctx->r3;
    // 0x80042ED8: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x80042EDC: add.s       $f0, $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f0.fl;
    // 0x80042EE0: lwc1        $f2, 0x20($t0)
    ctx->f2.u32l = MEM_W(ctx->r8, 0X20);
    // 0x80042EE4: lw          $t6, 0x84($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X84);
    // 0x80042EE8: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x80042EEC: lwc1        $f2, 0x0($t6)
    ctx->f2.u32l = MEM_W(ctx->r14, 0X0);
    // 0x80042EF0: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x80042EF4: mul.s       $f0, $f0, $f24
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f24.fl);
    // 0x80042EF8: lw          $a0, 0x14($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X14);
    // 0x80042EFC: mul.s       $f0, $f0, $f26
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f26.fl);
    // 0x80042F00: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x80042F04: lw          $v1, 0x2DB8($t6)
    ctx->r3 = MEM_W(ctx->r14, 0X2DB8);
    // 0x80042F08: addiu       $a0, $a0, 0x20
    ctx->r4 = ADD32(ctx->r4, 0X20);
    // 0x80042F0C: addu        $v1, $fp, $v1
    ctx->r3 = ADD32(ctx->r30, ctx->r3);
    // 0x80042F10: trunc.w.s   $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    ctx->f4.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x80042F14: mfc1        $v0, $f4
    ctx->r2 = (int32_t)ctx->f4.u32l;
    // 0x80042F18: mtc1        $v1, $f0
    ctx->f0.u32l = ctx->r3;
    // 0x80042F1C: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x80042F20: sh          $v0, 0x8($a0)
    MEM_H(0X8, ctx->r4) = ctx->r2;
    // 0x80042F24: add.s       $f0, $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f0.fl;
    // 0x80042F28: lwc1        $f2, 0x2C($t0)
    ctx->f2.u32l = MEM_W(ctx->r8, 0X2C);
    // 0x80042F2C: lw          $t6, 0x84($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X84);
    // 0x80042F30: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x80042F34: lwc1        $f2, 0x8($t6)
    ctx->f2.u32l = MEM_W(ctx->r14, 0X8);
    // 0x80042F38: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x80042F3C: mul.s       $f0, $f0, $f24
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f24.fl);
    // 0x80042F40: nop

    // 0x80042F44: mul.s       $f0, $f0, $f26
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f26.fl);
    // 0x80042F48: sh          $zero, 0xA($a0)
    MEM_H(0XA, ctx->r4) = 0;
    // 0x80042F4C: sb          $zero, 0x10($a0)
    MEM_B(0X10, ctx->r4) = 0;
    // 0x80042F50: trunc.w.s   $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    ctx->f4.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x80042F54: mfc1        $v0, $f4
    ctx->r2 = (int32_t)ctx->f4.u32l;
    // 0x80042F58: bne         $s1, $zero, L_80042F70
    if (ctx->r17 != 0) {
        // 0x80042F5C: sh          $v0, 0xC($a0)
        MEM_H(0XC, ctx->r4) = ctx->r2;
            goto L_80042F70;
    }
    // 0x80042F5C: sh          $v0, 0xC($a0)
    MEM_H(0XC, ctx->r4) = ctx->r2;
    // 0x80042F60: addu        $t1, $s0, $zero
    ctx->r9 = ADD32(ctx->r16, 0);
    // 0x80042F64: sw          $zero, 0x4($t1)
    MEM_W(0X4, ctx->r9) = 0;
    // 0x80042F68: j           L_80043014
    // 0x80042F6C: sw          $zero, 0x0($t1)
    MEM_W(0X0, ctx->r9) = 0;
        goto L_80043014;
    // 0x80042F6C: sw          $zero, 0x0($t1)
    MEM_W(0X0, ctx->r9) = 0;
L_80042F70:
    // 0x80042F70: lwc1        $f2, 0x8($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X8);
    // 0x80042F74: lwc1        $f0, 0x8($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X8);
    // 0x80042F78: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x80042F7C: nop

    // 0x80042F80: bc1f        L_80042FF4
    if (!c1cs) {
        // 0x80042F84: nop
    
            goto L_80042FF4;
    }
    // 0x80042F84: nop

    // 0x80042F88: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x80042F8C: beql        $v0, $zero, L_80042FCC
    if (ctx->r2 == 0) {
        // 0x80042F90: sw          $v0, 0x0($s0)
        MEM_W(0X0, ctx->r16) = ctx->r2;
            goto L_80042FCC;
    }
    goto skip_2;
    // 0x80042F90: sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
    skip_2:
L_80042F94:
    // 0x80042F94: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x80042F98: lwc1        $f0, 0x8($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X8);
    // 0x80042F9C: c.le.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl <= ctx->f0.fl;
    // 0x80042FA0: nop

    // 0x80042FA4: bc1t        L_80042FBC
    if (c1cs) {
        // 0x80042FA8: nop
    
            goto L_80042FBC;
    }
    // 0x80042FA8: nop

    // 0x80042FAC: addu        $s1, $v0, $zero
    ctx->r17 = ADD32(ctx->r2, 0);
    // 0x80042FB0: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x80042FB4: bne         $v0, $zero, L_80042F94
    if (ctx->r2 != 0) {
        // 0x80042FB8: nop
    
            goto L_80042F94;
    }
    // 0x80042FB8: nop

L_80042FBC:
    // 0x80042FBC: beq         $v0, $zero, L_80042FCC
    if (ctx->r2 == 0) {
        // 0x80042FC0: sw          $v0, 0x0($s0)
        MEM_W(0X0, ctx->r16) = ctx->r2;
            goto L_80042FCC;
    }
    // 0x80042FC0: sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
    // 0x80042FC4: j           L_80042FD0
    // 0x80042FC8: sw          $s0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r16;
        goto L_80042FD0;
    // 0x80042FC8: sw          $s0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r16;
L_80042FCC:
    // 0x80042FCC: addu        $t1, $s0, $zero
    ctx->r9 = ADD32(ctx->r16, 0);
L_80042FD0:
    // 0x80042FD0: sw          $s1, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r17;
    // 0x80042FD4: j           L_80043014
    // 0x80042FD8: sw          $s0, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r16;
        goto L_80043014;
    // 0x80042FD8: sw          $s0, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r16;
L_80042FDC:
    // 0x80042FDC: lwc1        $f0, 0x8($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X8);
    // 0x80042FE0: c.le.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl <= ctx->f2.fl;
    // 0x80042FE4: nop

    // 0x80042FE8: bc1t        L_80043000
    if (c1cs) {
        // 0x80042FEC: nop
    
            goto L_80043000;
    }
    // 0x80042FEC: nop

    // 0x80042FF0: addu        $s1, $v0, $zero
    ctx->r17 = ADD32(ctx->r2, 0);
L_80042FF4:
    // 0x80042FF4: lw          $v0, 0x4($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X4);
    // 0x80042FF8: bne         $v0, $zero, L_80042FDC
    if (ctx->r2 != 0) {
        // 0x80042FFC: nop
    
            goto L_80042FDC;
    }
    // 0x80042FFC: nop

L_80043000:
    // 0x80043000: beq         $v0, $zero, L_8004300C
    if (ctx->r2 == 0) {
        // 0x80043004: sw          $v0, 0x4($s0)
        MEM_W(0X4, ctx->r16) = ctx->r2;
            goto L_8004300C;
    }
    // 0x80043004: sw          $v0, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r2;
    // 0x80043008: sw          $s0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r16;
L_8004300C:
    // 0x8004300C: sw          $s1, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r17;
    // 0x80043010: sw          $s0, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->r16;
L_80043014:
    // 0x80043014: j           L_80043024
    // 0x80043018: addu        $s1, $s0, $zero
    ctx->r17 = ADD32(ctx->r16, 0);
        goto L_80043024;
    // 0x80043018: addu        $s1, $s0, $zero
    ctx->r17 = ADD32(ctx->r16, 0);
L_8004301C:
    // 0x8004301C: addu        $v0, $s6, $t2
    ctx->r2 = ADD32(ctx->r22, ctx->r10);
L_80043020:
    // 0x80043020: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
L_80043024:
    // 0x80043024: beql        $t3, $zero, L_80043050
    if (ctx->r11 == 0) {
        // 0x80043028: addiu       $s2, $s2, 0x2
        ctx->r18 = ADD32(ctx->r18, 0X2);
            goto L_80043050;
    }
    goto skip_3;
    // 0x80043028: addiu       $s2, $s2, 0x2
    ctx->r18 = ADD32(ctx->r18, 0X2);
    skip_3:
    // 0x8004302C: lw          $v0, 0x2DB0($t4)
    ctx->r2 = MEM_W(ctx->r12, 0X2DB0);
    // 0x80043030: addu        $v0, $s4, $v0
    ctx->r2 = ADD32(ctx->r20, ctx->r2);
    // 0x80043034: bltz        $v0, L_80043050
    if (SIGNED(ctx->r2) < 0) {
        // 0x80043038: addiu       $v0, $v0, 0x1
        ctx->r2 = ADD32(ctx->r2, 0X1);
            goto L_80043050;
    }
    // 0x80043038: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8004303C: lhu         $v1, 0x38($t0)
    ctx->r3 = MEM_HU(ctx->r8, 0X38);
    // 0x80043040: slt         $v0, $v0, $v1
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80043044: beql        $v0, $zero, L_80043054
    if (ctx->r2 == 0) {
        // 0x80043048: addiu       $s6, $s6, 0x4
        ctx->r22 = ADD32(ctx->r22, 0X4);
            goto L_80043054;
    }
    goto skip_4;
    // 0x80043048: addiu       $s6, $s6, 0x4
    ctx->r22 = ADD32(ctx->r22, 0X4);
    skip_4:
    // 0x8004304C: addiu       $s2, $s2, 0x2
    ctx->r18 = ADD32(ctx->r18, 0X2);
L_80043050:
    // 0x80043050: addiu       $s6, $s6, 0x4
    ctx->r22 = ADD32(ctx->r22, 0X4);
L_80043054:
    // 0x80043054: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    // 0x80043058: lw          $t6, 0x10($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X10);
    // 0x8004305C: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80043060: lwc1        $f0, -0x5AF8($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X5AF8);
    // 0x80043064: slt         $v0, $s4, $t6
    ctx->r2 = SIGNED(ctx->r20) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x80043068: bne         $v0, $zero, L_80042D3C
    if (ctx->r2 != 0) {
        // 0x8004306C: add.s       $f20, $f20, $f0
        CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f20.fl = ctx->f20.fl + ctx->f0.fl;
            goto L_80042D3C;
    }
    // 0x8004306C: add.s       $f20, $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f20.fl = ctx->f20.fl + ctx->f0.fl;
L_80043070:
    // 0x80043070: bne         $t3, $zero, L_8004308C
    if (ctx->r11 != 0) {
        // 0x80043074: nop
    
            goto L_8004308C;
    }
    // 0x80043074: nop

    // 0x80043078: lhu         $v0, 0x38($t0)
    ctx->r2 = MEM_HU(ctx->r8, 0X38);
    // 0x8004307C: lw          $t6, 0x10($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X10);
    // 0x80043080: subu        $v0, $v0, $t6
    ctx->r2 = SUB32(ctx->r2, ctx->r14);
    // 0x80043084: j           L_80043118
    // 0x80043088: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
        goto L_80043118;
    // 0x80043088: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
L_8004308C:
    // 0x8004308C: lw          $a0, 0x2DB0($t4)
    ctx->r4 = MEM_W(ctx->r12, 0X2DB0);
    // 0x80043090: bgez        $a0, L_800430A4
    if (SIGNED(ctx->r4) >= 0) {
        // 0x80043094: lui         $t6, 0x8013
        ctx->r14 = S32(0X8013 << 16);
            goto L_800430A4;
    }
    // 0x80043094: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x80043098: lw          $s2, 0x6DC0($t6)
    ctx->r18 = MEM_W(ctx->r14, 0X6DC0);
    // 0x8004309C: j           L_800430D4
    // 0x800430A0: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
        goto L_800430D4;
    // 0x800430A0: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
L_800430A4:
    // 0x800430A4: lhu         $v1, 0x38($t0)
    ctx->r3 = MEM_HU(ctx->r8, 0X38);
    // 0x800430A8: slt         $v0, $a0, $v1
    ctx->r2 = SIGNED(ctx->r4) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800430AC: bnel        $v0, $zero, L_800430C8
    if (ctx->r2 != 0) {
        // 0x800430B0: sll         $v0, $a0, 1
        ctx->r2 = S32(ctx->r4 << 1);
            goto L_800430C8;
    }
    goto skip_5;
    // 0x800430B0: sll         $v0, $a0, 1
    ctx->r2 = S32(ctx->r4 << 1);
    skip_5:
    // 0x800430B4: sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3 << 1);
    // 0x800430B8: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x800430BC: lw          $v1, 0x6DC0($t6)
    ctx->r3 = MEM_W(ctx->r14, 0X6DC0);
    // 0x800430C0: j           L_800430CC
    // 0x800430C4: addiu       $v0, $v0, -0x2
    ctx->r2 = ADD32(ctx->r2, -0X2);
        goto L_800430CC;
    // 0x800430C4: addiu       $v0, $v0, -0x2
    ctx->r2 = ADD32(ctx->r2, -0X2);
L_800430C8:
    // 0x800430C8: lw          $v1, 0x6DC0($t6)
    ctx->r3 = MEM_W(ctx->r14, 0X6DC0);
L_800430CC:
    // 0x800430CC: addu        $s2, $v1, $v0
    ctx->r18 = ADD32(ctx->r3, ctx->r2);
    // 0x800430D0: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
L_800430D4:
    // 0x800430D4: lw          $v0, 0x2DB8($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X2DB8);
    // 0x800430D8: lhu         $a1, 0x3A($t0)
    ctx->r5 = MEM_HU(ctx->r8, 0X3A);
    // 0x800430DC: addu        $v1, $v0, $fp
    ctx->r3 = ADD32(ctx->r2, ctx->r30);
    // 0x800430E0: addiu       $a0, $v1, 0x1
    ctx->r4 = ADD32(ctx->r3, 0X1);
    // 0x800430E4: slt         $v0, $a0, $a1
    ctx->r2 = SIGNED(ctx->r4) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x800430E8: bne         $v0, $zero, L_80043100
    if (ctx->r2 != 0) {
        // 0x800430EC: addiu       $v0, $a1, -0x1
        ctx->r2 = ADD32(ctx->r5, -0X1);
            goto L_80043100;
    }
    // 0x800430EC: addiu       $v0, $a1, -0x1
    ctx->r2 = ADD32(ctx->r5, -0X1);
    // 0x800430F0: lhu         $v1, 0x38($t0)
    ctx->r3 = MEM_HU(ctx->r8, 0X38);
    // 0x800430F4: mult        $v1, $v0
    result = S64(S32(ctx->r3)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800430F8: j           L_80043110
    // 0x800430FC: nop

        goto L_80043110;
    // 0x800430FC: nop

L_80043100:
    // 0x80043100: bltzl       $v1, L_80043120
    if (SIGNED(ctx->r3) < 0) {
        // 0x80043104: addiu       $fp, $fp, 0x1
        ctx->r30 = ADD32(ctx->r30, 0X1);
            goto L_80043120;
    }
    goto skip_6;
    // 0x80043104: addiu       $fp, $fp, 0x1
    ctx->r30 = ADD32(ctx->r30, 0X1);
    skip_6:
    // 0x80043108: lhu         $v0, 0x38($t0)
    ctx->r2 = MEM_HU(ctx->r8, 0X38);
    // 0x8004310C: mult        $v0, $a0
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
L_80043110:
    // 0x80043110: mflo        $t6
    ctx->r14 = lo;
    // 0x80043114: sll         $v0, $t6, 1
    ctx->r2 = S32(ctx->r14 << 1);
L_80043118:
    // 0x80043118: addu        $s2, $s2, $v0
    ctx->r18 = ADD32(ctx->r18, ctx->r2);
    // 0x8004311C: addiu       $fp, $fp, 0x1
    ctx->r30 = ADD32(ctx->r30, 0X1);
L_80043120:
    // 0x80043120: lw          $t6, 0x14($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X14);
    // 0x80043124: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80043128: lwc1        $f0, -0x5AF4($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X5AF4);
    // 0x8004312C: slt         $v0, $fp, $t6
    ctx->r2 = SIGNED(ctx->r30) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x80043130: bne         $v0, $zero, L_80042CF8
    if (ctx->r2 != 0) {
        // 0x80043134: add.s       $f22, $f22, $f0
        CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f22.fl = ctx->f22.fl + ctx->f0.fl;
            goto L_80042CF8;
    }
    // 0x80043134: add.s       $f22, $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f22.fl = ctx->f22.fl + ctx->f0.fl;
L_80043138:
    // 0x80043138: lw          $ra, 0x5C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X5C);
    // 0x8004313C: lw          $fp, 0x58($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X58);
    // 0x80043140: lw          $s7, 0x54($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X54);
    // 0x80043144: lw          $s6, 0x50($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X50);
    // 0x80043148: lw          $s5, 0x4C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X4C);
    // 0x8004314C: lw          $s4, 0x48($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X48);
    // 0x80043150: lw          $s3, 0x44($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X44);
    // 0x80043154: lw          $s2, 0x40($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X40);
    // 0x80043158: lw          $s1, 0x3C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X3C);
    // 0x8004315C: lw          $s0, 0x38($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X38);
    // 0x80043160: ldc1        $f26, 0x78($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X78);
    // 0x80043164: ldc1        $f24, 0x70($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X70);
    // 0x80043168: ldc1        $f22, 0x68($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X68);
    // 0x8004316C: ldc1        $f20, 0x60($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X60);
    // 0x80043170: addu        $v0, $t1, $zero
    ctx->r2 = ADD32(ctx->r9, 0);
    // 0x80043174: jr          $ra
    // 0x80043178: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
    return;
    // 0x80043178: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
;}
RECOMP_FUNC void func_8004317C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8004317C: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80043180: sw          $s5, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r21;
    // 0x80043184: addu        $s5, $zero, $zero
    ctx->r21 = ADD32(0, 0);
    // 0x80043188: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x8004318C: sw          $fp, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r30;
    // 0x80043190: sw          $s7, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r23;
    // 0x80043194: sw          $s6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r22;
    // 0x80043198: sw          $s4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r20;
    // 0x8004319C: sw          $s3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r19;
    // 0x800431A0: sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // 0x800431A4: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x800431A8: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x800431AC: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x800431B0: bne         $a0, $zero, L_800431CC
    if (ctx->r4 != 0) {
        // 0x800431B4: sw          $a1, 0x3C($sp)
        MEM_W(0X3C, ctx->r29) = ctx->r5;
            goto L_800431CC;
    }
    // 0x800431B4: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x800431B8: j           L_80043780
    // 0x800431BC: addu        $v0, $s5, $zero
    ctx->r2 = ADD32(ctx->r21, 0);
        goto L_80043780;
    // 0x800431BC: addu        $v0, $s5, $zero
    ctx->r2 = ADD32(ctx->r21, 0);
L_800431C0:
    // 0x800431C0: lw          $v0, 0x14($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X14);
    // 0x800431C4: j           L_80043528
    // 0x800431C8: sw          $zero, 0x20($v0)
    MEM_W(0X20, ctx->r2) = 0;
        goto L_80043528;
    // 0x800431C8: sw          $zero, 0x20($v0)
    MEM_W(0X20, ctx->r2) = 0;
L_800431CC:
    // 0x800431CC: addu        $s1, $zero, $zero
    ctx->r17 = ADD32(0, 0);
    // 0x800431D0: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x800431D4: addiu       $v0, $v0, -0x216C
    ctx->r2 = ADD32(ctx->r2, -0X216C);
    // 0x800431D8: lw          $t1, 0x38($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X38);
    // 0x800431DC: lwc1        $f0, 0x4($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X4);
    // 0x800431E0: lwc1        $f2, 0x8($t1)
    ctx->f2.u32l = MEM_W(ctx->r9, 0X8);
    // 0x800431E4: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x800431E8: nop

    // 0x800431EC: bc1f        L_80043218
    if (!c1cs) {
        // 0x800431F0: addu        $s6, $s1, $zero
        ctx->r22 = ADD32(ctx->r17, 0);
            goto L_80043218;
    }
    // 0x800431F0: addu        $s6, $s1, $zero
    ctx->r22 = ADD32(ctx->r17, 0);
    // 0x800431F4: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // 0x800431F8: addiu       $v1, $zero, 0x4
    ctx->r3 = ADD32(0, 0X4);
L_800431FC:
    // 0x800431FC: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x80043200: addu        $v0, $v1, $a0
    ctx->r2 = ADD32(ctx->r3, ctx->r4);
    // 0x80043204: lwc1        $f0, 0x0($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X0);
    // 0x80043208: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x8004320C: nop

    // 0x80043210: bc1t        L_800431FC
    if (c1cs) {
        // 0x80043214: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_800431FC;
    }
    // 0x80043214: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
L_80043218:
    // 0x80043218: lw          $s0, 0x38($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X38);
    // 0x8004321C: addu        $s2, $zero, $zero
    ctx->r18 = ADD32(0, 0);
    // 0x80043220: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x80043224: addiu       $s4, $v0, -0x216C
    ctx->r20 = ADD32(ctx->r2, -0X216C);
    // 0x80043228: addiu       $s7, $zero, 0x3
    ctx->r23 = ADD32(0, 0X3);
    // 0x8004322C: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80043230: addiu       $fp, $v0, 0xB40
    ctx->r30 = ADD32(ctx->r2, 0XB40);
    // 0x80043234: addiu       $s3, $zero, 0xFF
    ctx->r19 = ADD32(0, 0XFF);
    // 0x80043238: addiu       $a0, $s1, 0x1
    ctx->r4 = ADD32(ctx->r17, 0X1);
L_8004323C:
    // 0x8004323C: sll         $v0, $a0, 2
    ctx->r2 = S32(ctx->r4 << 2);
    // 0x80043240: addu        $v0, $v0, $s4
    ctx->r2 = ADD32(ctx->r2, ctx->r20);
    // 0x80043244: lw          $v1, 0x14($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X14);
    // 0x80043248: lwc1        $f2, 0x8($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8004324C: lwc1        $f0, 0x0($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X0);
    // 0x80043250: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x80043254: lhu         $a3, 0x14($v1)
    ctx->r7 = MEM_HU(ctx->r3, 0X14);
    // 0x80043258: bc1f        L_80043294
    if (!c1cs) {
        // 0x8004325C: addiu       $a1, $v1, 0x20
        ctx->r5 = ADD32(ctx->r3, 0X20);
            goto L_80043294;
    }
    // 0x8004325C: addiu       $a1, $v1, 0x20
    ctx->r5 = ADD32(ctx->r3, 0X20);
    // 0x80043260: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x80043264: addiu       $v1, $v0, -0x216C
    ctx->r3 = ADD32(ctx->r2, -0X216C);
    // 0x80043268: addu        $s1, $a0, $zero
    ctx->r17 = ADD32(ctx->r4, 0);
L_8004326C:
    // 0x8004326C: bne         $s1, $s7, L_80043278
    if (ctx->r17 != ctx->r23) {
        // 0x80043270: addiu       $a0, $s1, 0x1
        ctx->r4 = ADD32(ctx->r17, 0X1);
            goto L_80043278;
    }
    // 0x80043270: addiu       $a0, $s1, 0x1
    ctx->r4 = ADD32(ctx->r17, 0X1);
    // 0x80043274: lw          $s6, 0x0($s0)
    ctx->r22 = MEM_W(ctx->r16, 0X0);
L_80043278:
    // 0x80043278: sll         $v0, $a0, 2
    ctx->r2 = S32(ctx->r4 << 2);
    // 0x8004327C: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80043280: lwc1        $f0, 0x0($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X0);
    // 0x80043284: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x80043288: nop

    // 0x8004328C: bc1tl       L_8004326C
    if (c1cs) {
        // 0x80043290: addu        $s1, $a0, $zero
        ctx->r17 = ADD32(ctx->r4, 0);
            goto L_8004326C;
    }
    goto skip_0;
    // 0x80043290: addu        $s1, $a0, $zero
    ctx->r17 = ADD32(ctx->r4, 0);
    skip_0:
L_80043294:
    // 0x80043294: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80043298: beq         $s1, $v0, L_800432D8
    if (ctx->r17 == ctx->r2) {
        // 0x8004329C: slti        $v0, $s1, 0x2
        ctx->r2 = SIGNED(ctx->r17) < 0X2 ? 1 : 0;
            goto L_800432D8;
    }
    // 0x8004329C: slti        $v0, $s1, 0x2
    ctx->r2 = SIGNED(ctx->r17) < 0X2 ? 1 : 0;
    // 0x800432A0: beq         $v0, $zero, L_800432B8
    if (ctx->r2 == 0) {
        // 0x800432A4: addiu       $v0, $zero, 0x2
        ctx->r2 = ADD32(0, 0X2);
            goto L_800432B8;
    }
    // 0x800432A4: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x800432A8: beql        $s1, $zero, L_800432D0
    if (ctx->r17 == 0) {
        // 0x800432AC: addiu       $s2, $s2, 0x1
        ctx->r18 = ADD32(ctx->r18, 0X1);
            goto L_800432D0;
    }
    goto skip_1;
    // 0x800432AC: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    skip_1:
    // 0x800432B0: j           L_80043324
    // 0x800432B4: addiu       $s2, $s2, 0x3
    ctx->r18 = ADD32(ctx->r18, 0X3);
        goto L_80043324;
    // 0x800432B4: addiu       $s2, $s2, 0x3
    ctx->r18 = ADD32(ctx->r18, 0X3);
L_800432B8:
    // 0x800432B8: beql        $s1, $v0, L_800432FC
    if (ctx->r17 == ctx->r2) {
        // 0x800432BC: addiu       $s2, $s2, 0x2
        ctx->r18 = ADD32(ctx->r18, 0X2);
            goto L_800432FC;
    }
    goto skip_2;
    // 0x800432BC: addiu       $s2, $s2, 0x2
    ctx->r18 = ADD32(ctx->r18, 0X2);
    skip_2:
    // 0x800432C0: beq         $s1, $s7, L_80043304
    if (ctx->r17 == ctx->r23) {
        // 0x800432C4: addiu       $s2, $s2, 0x3
        ctx->r18 = ADD32(ctx->r18, 0X3);
            goto L_80043304;
    }
    // 0x800432C4: addiu       $s2, $s2, 0x3
    ctx->r18 = ADD32(ctx->r18, 0X3);
    // 0x800432C8: j           L_80043328
    // 0x800432CC: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
        goto L_80043328;
    // 0x800432CC: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
L_800432D0:
    // 0x800432D0: j           L_80043328
    // 0x800432D4: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
        goto L_80043328;
    // 0x800432D4: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
L_800432D8:
    // 0x800432D8: lwc1        $f4, 0x8($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X8);
    // 0x800432DC: lwc1        $f2, 0x8($s4)
    ctx->f2.u32l = MEM_W(ctx->r20, 0X8);
    // 0x800432E0: sub.s       $f4, $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = ctx->f4.fl - ctx->f2.fl;
    // 0x800432E4: lwc1        $f0, 0x4($s4)
    ctx->f0.u32l = MEM_W(ctx->r20, 0X4);
    // 0x800432E8: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x800432EC: addiu       $s2, $s2, 0x2
    ctx->r18 = ADD32(ctx->r18, 0X2);
    // 0x800432F0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x800432F4: j           L_8004332C
    // 0x800432F8: div.s       $f4, $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = DIV_S(ctx->f4.fl, ctx->f0.fl);
        goto L_8004332C;
    // 0x800432F8: div.s       $f4, $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = DIV_S(ctx->f4.fl, ctx->f0.fl);
L_800432FC:
    // 0x800432FC: j           L_80043328
    // 0x80043300: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
        goto L_80043328;
    // 0x80043300: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
L_80043304:
    // 0x80043304: lwc1        $f4, 0x8($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X8);
    // 0x80043308: lwc1        $f2, 0x10($s4)
    ctx->f2.u32l = MEM_W(ctx->r20, 0X10);
    // 0x8004330C: sub.s       $f4, $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = ctx->f4.fl - ctx->f2.fl;
    // 0x80043310: lwc1        $f0, 0xC($s4)
    ctx->f0.u32l = MEM_W(ctx->r20, 0XC);
    // 0x80043314: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x80043318: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // 0x8004331C: j           L_8004332C
    // 0x80043320: div.s       $f4, $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = DIV_S(ctx->f4.fl, ctx->f0.fl);
        goto L_8004332C;
    // 0x80043320: div.s       $f4, $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = DIV_S(ctx->f4.fl, ctx->f0.fl);
L_80043324:
    // 0x80043324: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
L_80043328:
    // 0x80043328: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
L_8004332C:
    // 0x8004332C: andi        $v0, $a3, 0x8
    ctx->r2 = ctx->r7 & 0X8;
    // 0x80043330: beq         $v0, $zero, L_80043374
    if (ctx->r2 == 0) {
        // 0x80043334: lui         $v1, 0x800
        ctx->r3 = S32(0X800 << 16);
            goto L_80043374;
    }
    // 0x80043334: lui         $v1, 0x800
    ctx->r3 = S32(0X800 << 16);
    // 0x80043338: lw          $v0, 0xC($fp)
    ctx->r2 = MEM_W(ctx->r30, 0XC);
    // 0x8004333C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80043340: and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // 0x80043344: beq         $v0, $zero, L_800433E0
    if (ctx->r2 == 0) {
        // 0x80043348: addiu       $a2, $zero, 0x1
        ctx->r6 = ADD32(0, 0X1);
            goto L_800433E0;
    }
    // 0x80043348: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8004334C: lw          $v0, 0x14($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X14);
    // 0x80043350: sb          $zero, 0xB6($v0)
    MEM_B(0XB6, ctx->r2) = 0;
    // 0x80043354: sb          $zero, 0xB5($v0)
    MEM_B(0XB5, ctx->r2) = 0;
    // 0x80043358: sb          $zero, 0xA6($v0)
    MEM_B(0XA6, ctx->r2) = 0;
    // 0x8004335C: sb          $zero, 0xA4($v0)
    MEM_B(0XA4, ctx->r2) = 0;
    // 0x80043360: sb          $zero, 0x66($v0)
    MEM_B(0X66, ctx->r2) = 0;
    // 0x80043364: sb          $zero, 0x64($v0)
    MEM_B(0X64, ctx->r2) = 0;
    // 0x80043368: sb          $zero, 0x56($v0)
    MEM_B(0X56, ctx->r2) = 0;
    // 0x8004336C: j           L_800433E0
    // 0x80043370: sb          $zero, 0x55($v0)
    MEM_B(0X55, ctx->r2) = 0;
        goto L_800433E0;
    // 0x80043370: sb          $zero, 0x55($v0)
    MEM_B(0X55, ctx->r2) = 0;
L_80043374:
    // 0x80043374: andi        $v0, $a3, 0x4
    ctx->r2 = ctx->r7 & 0X4;
    // 0x80043378: beq         $v0, $zero, L_800433E4
    if (ctx->r2 == 0) {
        // 0x8004337C: addiu       $v0, $zero, 0x2
        ctx->r2 = ADD32(0, 0X2);
            goto L_800433E4;
    }
    // 0x8004337C: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x80043380: lw          $v0, 0xC($fp)
    ctx->r2 = MEM_W(ctx->r30, 0XC);
    // 0x80043384: and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // 0x80043388: beq         $v0, $zero, L_800433E0
    if (ctx->r2 == 0) {
        // 0x8004338C: addiu       $a2, $zero, 0x2
        ctx->r6 = ADD32(0, 0X2);
            goto L_800433E0;
    }
    // 0x8004338C: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x80043390: lw          $v0, 0x14($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X14);
    // 0x80043394: sb          $s3, 0x56($v0)
    MEM_B(0X56, ctx->r2) = ctx->r19;
    // 0x80043398: sb          $s3, 0x55($v0)
    MEM_B(0X55, ctx->r2) = ctx->r19;
    // 0x8004339C: sb          $s3, 0x54($v0)
    MEM_B(0X54, ctx->r2) = ctx->r19;
    // 0x800433A0: lw          $v0, 0x14($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X14);
    // 0x800433A4: sb          $zero, 0x66($v0)
    MEM_B(0X66, ctx->r2) = 0;
    // 0x800433A8: sb          $zero, 0x65($v0)
    MEM_B(0X65, ctx->r2) = 0;
    // 0x800433AC: sb          $zero, 0x64($v0)
    MEM_B(0X64, ctx->r2) = 0;
    // 0x800433B0: lw          $v0, 0x14($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X14);
    // 0x800433B4: sb          $s3, 0xA4($v0)
    MEM_B(0XA4, ctx->r2) = ctx->r19;
    // 0x800433B8: lw          $v0, 0x14($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X14);
    // 0x800433BC: sb          $s3, 0xA5($v0)
    MEM_B(0XA5, ctx->r2) = ctx->r19;
    // 0x800433C0: lw          $v0, 0x14($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X14);
    // 0x800433C4: sb          $zero, 0xA6($v0)
    MEM_B(0XA6, ctx->r2) = 0;
    // 0x800433C8: lw          $v0, 0x14($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X14);
    // 0x800433CC: sb          $s3, 0xB4($v0)
    MEM_B(0XB4, ctx->r2) = ctx->r19;
    // 0x800433D0: lw          $v0, 0x14($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X14);
    // 0x800433D4: sb          $zero, 0xB5($v0)
    MEM_B(0XB5, ctx->r2) = 0;
    // 0x800433D8: lw          $v0, 0x14($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X14);
    // 0x800433DC: sb          $s3, 0xB6($v0)
    MEM_B(0XB6, ctx->r2) = ctx->r19;
L_800433E0:
    // 0x800433E0: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
L_800433E4:
    // 0x800433E4: bne         $a2, $v0, L_80043414
    if (ctx->r6 != ctx->r2) {
        // 0x800433E8: sb          $a2, 0x14($a1)
        MEM_B(0X14, ctx->r5) = ctx->r6;
            goto L_80043414;
    }
    // 0x800433E8: sb          $a2, 0x14($a1)
    MEM_B(0X14, ctx->r5) = ctx->r6;
    // 0x800433EC: sb          $a2, 0x13($a1)
    MEM_B(0X13, ctx->r5) = ctx->r6;
    // 0x800433F0: sb          $a2, 0x12($a1)
    MEM_B(0X12, ctx->r5) = ctx->r6;
    // 0x800433F4: sb          $a2, 0x11($a1)
    MEM_B(0X11, ctx->r5) = ctx->r6;
    // 0x800433F8: sb          $a2, 0x10($a1)
    MEM_B(0X10, ctx->r5) = ctx->r6;
    // 0x800433FC: sh          $zero, 0x1E($a1)
    MEM_H(0X1E, ctx->r5) = 0;
    // 0x80043400: sh          $zero, 0x1C($a1)
    MEM_H(0X1C, ctx->r5) = 0;
    // 0x80043404: sh          $zero, 0x1A($a1)
    MEM_H(0X1A, ctx->r5) = 0;
    // 0x80043408: sh          $zero, 0x18($a1)
    MEM_H(0X18, ctx->r5) = 0;
    // 0x8004340C: j           L_8004347C
    // 0x80043410: sh          $zero, 0x16($a1)
    MEM_H(0X16, ctx->r5) = 0;
        goto L_8004347C;
    // 0x80043410: sh          $zero, 0x16($a1)
    MEM_H(0X16, ctx->r5) = 0;
L_80043414:
    // 0x80043414: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80043418: lwc1        $f0, -0x5AF0($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X5AF0);
    // 0x8004341C: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80043420: lwc1        $f2, -0x5AEC($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X5AEC);
    // 0x80043424: mul.s       $f0, $f4, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x80043428: sb          $a2, 0x13($a1)
    MEM_B(0X13, ctx->r5) = ctx->r6;
    // 0x8004342C: sb          $a2, 0x12($a1)
    MEM_B(0X12, ctx->r5) = ctx->r6;
    // 0x80043430: sb          $a2, 0x11($a1)
    MEM_B(0X11, ctx->r5) = ctx->r6;
    // 0x80043434: c.le.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl <= ctx->f0.fl;
    // 0x80043438: nop

    // 0x8004343C: bc1t        L_80043454
    if (c1cs) {
        // 0x80043440: sb          $a2, 0x10($a1)
        MEM_B(0X10, ctx->r5) = ctx->r6;
            goto L_80043454;
    }
    // 0x80043440: sb          $a2, 0x10($a1)
    MEM_B(0X10, ctx->r5) = ctx->r6;
    // 0x80043444: trunc.w.s   $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    ctx->f6.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x80043448: mfc1        $v1, $f6
    ctx->r3 = (int32_t)ctx->f6.u32l;
    // 0x8004344C: j           L_8004346C
    // 0x80043450: sh          $v1, 0x1E($a1)
    MEM_H(0X1E, ctx->r5) = ctx->r3;
        goto L_8004346C;
    // 0x80043450: sh          $v1, 0x1E($a1)
    MEM_H(0X1E, ctx->r5) = ctx->r3;
L_80043454:
    // 0x80043454: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x80043458: lui         $v0, 0x8000
    ctx->r2 = S32(0X8000 << 16);
    // 0x8004345C: trunc.w.s   $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    ctx->f6.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x80043460: mfc1        $v1, $f6
    ctx->r3 = (int32_t)ctx->f6.u32l;
    // 0x80043464: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x80043468: sh          $v1, 0x1E($a1)
    MEM_H(0X1E, ctx->r5) = ctx->r3;
L_8004346C:
    // 0x8004346C: sh          $v1, 0x1C($a1)
    MEM_H(0X1C, ctx->r5) = ctx->r3;
    // 0x80043470: sh          $v1, 0x1A($a1)
    MEM_H(0X1A, ctx->r5) = ctx->r3;
    // 0x80043474: sh          $v1, 0x18($a1)
    MEM_H(0X18, ctx->r5) = ctx->r3;
    // 0x80043478: sh          $v1, 0x16($a1)
    MEM_H(0X16, ctx->r5) = ctx->r3;
L_8004347C:
    // 0x8004347C: lw          $a0, 0x14($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X14);
    // 0x80043480: lhu         $v0, 0x14($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X14);
    // 0x80043484: andi        $v0, $v0, 0xC0
    ctx->r2 = ctx->r2 & 0XC0;
    // 0x80043488: beq         $v0, $zero, L_8004349C
    if (ctx->r2 == 0) {
        // 0x8004348C: nop
    
            goto L_8004349C;
    }
    // 0x8004348C: nop

    // 0x80043490: jal         0x80046030
    // 0x80043494: nop

    func_80046030(rdram, ctx);
        goto after_0;
    // 0x80043494: nop

    after_0:
    // 0x80043498: lw          $a0, 0x14($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X14);
L_8004349C:
    // 0x8004349C: jal         0x8004B930
    // 0x800434A0: nop

    func_8004B930(rdram, ctx);
        goto after_1;
    // 0x800434A0: nop

    after_1:
    // 0x800434A4: lw          $v1, 0x4($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X4);
    // 0x800434A8: beq         $v1, $zero, L_800431C0
    if (ctx->r3 == 0) {
        // 0x800434AC: nop
    
            goto L_800431C0;
    }
    // 0x800434AC: nop

    // 0x800434B0: lw          $v0, 0x14($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X14);
    // 0x800434B4: lw          $v1, 0x14($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X14);
    // 0x800434B8: addiu       $v0, $v0, 0x20
    ctx->r2 = ADD32(ctx->r2, 0X20);
    // 0x800434BC: sw          $v0, 0x24($v1)
    MEM_W(0X24, ctx->r3) = ctx->r2;
    // 0x800434C0: lw          $v0, 0x4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X4);
    // 0x800434C4: lw          $v0, 0x14($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X14);
    // 0x800434C8: lw          $v1, 0x14($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X14);
    // 0x800434CC: addiu       $v0, $v0, 0x20
    ctx->r2 = ADD32(ctx->r2, 0X20);
    // 0x800434D0: bne         $s5, $zero, L_8004351C
    if (ctx->r21 != 0) {
        // 0x800434D4: sw          $v0, 0x20($v1)
        MEM_W(0X20, ctx->r3) = ctx->r2;
            goto L_8004351C;
    }
    // 0x800434D4: sw          $v0, 0x20($v1)
    MEM_W(0X20, ctx->r3) = ctx->r2;
    // 0x800434D8: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x800434DC: lwc1        $f2, 0x8($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X8);
    // 0x800434E0: lwc1        $f0, -0x214C($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, -0X214C);
    // 0x800434E4: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x800434E8: nop

    // 0x800434EC: bc1f        L_8004351C
    if (!c1cs) {
        // 0x800434F0: nop
    
            goto L_8004351C;
    }
    // 0x800434F0: nop

    // 0x800434F4: lw          $v0, 0x4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X4);
    // 0x800434F8: lw          $v0, 0x14($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X14);
    // 0x800434FC: sw          $zero, 0x24($v0)
    MEM_W(0X24, ctx->r2) = 0;
    // 0x80043500: lw          $v0, 0x14($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X14);
    // 0x80043504: sw          $zero, 0x20($v0)
    MEM_W(0X20, ctx->r2) = 0;
    // 0x80043508: lw          $v0, 0x4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X4);
    // 0x8004350C: lw          $v0, 0x14($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X14);
    // 0x80043510: lw          $t1, 0x3C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X3C);
    // 0x80043514: addiu       $s5, $v0, 0x20
    ctx->r21 = ADD32(ctx->r2, 0X20);
    // 0x80043518: sw          $s5, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r21;
L_8004351C:
    // 0x8004351C: lw          $s0, 0x4($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X4);
    // 0x80043520: j           L_8004323C
    // 0x80043524: addiu       $a0, $s1, 0x1
    ctx->r4 = ADD32(ctx->r17, 0X1);
        goto L_8004323C;
    // 0x80043524: addiu       $a0, $s1, 0x1
    ctx->r4 = ADD32(ctx->r17, 0X1);
L_80043528:
    // 0x80043528: beq         $s0, $s6, L_8004367C
    if (ctx->r16 == ctx->r22) {
        // 0x8004352C: lui         $v0, 0x8013
        ctx->r2 = S32(0X8013 << 16);
            goto L_8004367C;
    }
    // 0x8004352C: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80043530: addiu       $t0, $v0, 0x2DC0
    ctx->r8 = ADD32(ctx->r2, 0X2DC0);
    // 0x80043534: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    // 0x80043538: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_8004353C:
    // 0x8004353C: lw          $v0, 0x14($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X14);
    // 0x80043540: addiu       $a1, $v0, 0x20
    ctx->r5 = ADD32(ctx->r2, 0X20);
    // 0x80043544: lbu         $v0, 0x10($a1)
    ctx->r2 = MEM_BU(ctx->r5, 0X10);
    // 0x80043548: bne         $v0, $zero, L_80043670
    if (ctx->r2 != 0) {
        // 0x8004354C: nop
    
            goto L_80043670;
    }
    // 0x8004354C: nop

    // 0x80043550: lw          $a2, 0x10($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X10);
    // 0x80043554: lw          $s1, 0xC($s0)
    ctx->r17 = MEM_W(ctx->r16, 0XC);
    // 0x80043558: blez        $a2, L_8004358C
    if (SIGNED(ctx->r6) <= 0) {
        // 0x8004355C: sll         $v1, $s1, 2
        ctx->r3 = S32(ctx->r17 << 2);
            goto L_8004358C;
    }
    // 0x8004355C: sll         $v1, $s1, 2
    ctx->r3 = S32(ctx->r17 << 2);
    // 0x80043560: addiu       $v0, $a2, -0x1
    ctx->r2 = ADD32(ctx->r6, -0X1);
    // 0x80043564: sll         $v0, $v0, 8
    ctx->r2 = S32(ctx->r2 << 8);
    // 0x80043568: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x8004356C: addu        $v1, $v1, $t0
    ctx->r3 = ADD32(ctx->r3, ctx->r8);
    // 0x80043570: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80043574: beql        $v0, $zero, L_80043590
    if (ctx->r2 == 0) {
        // 0x80043578: lui         $v0, 0x8013
        ctx->r2 = S32(0X8013 << 16);
            goto L_80043590;
    }
    goto skip_3;
    // 0x80043578: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    skip_3:
    // 0x8004357C: lw          $v0, 0x14($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X14);
    // 0x80043580: lbu         $v0, 0x30($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X30);
    // 0x80043584: beql        $v0, $a3, L_8004364C
    if (ctx->r2 == ctx->r7) {
        // 0x80043588: sb          $a0, 0x14($a1)
        MEM_B(0X14, ctx->r5) = ctx->r4;
            goto L_8004364C;
    }
    goto skip_4;
    // 0x80043588: sb          $a0, 0x14($a1)
    MEM_B(0X14, ctx->r5) = ctx->r4;
    skip_4:
L_8004358C:
    // 0x8004358C: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
L_80043590:
    // 0x80043590: lw          $v0, 0x2DBC($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X2DBC);
    // 0x80043594: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x80043598: slt         $v0, $a2, $v0
    ctx->r2 = SIGNED(ctx->r6) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8004359C: beq         $v0, $zero, L_800435D0
    if (ctx->r2 == 0) {
        // 0x800435A0: sll         $v1, $s1, 2
        ctx->r3 = S32(ctx->r17 << 2);
            goto L_800435D0;
    }
    // 0x800435A0: sll         $v1, $s1, 2
    ctx->r3 = S32(ctx->r17 << 2);
    // 0x800435A4: addiu       $v0, $a2, 0x1
    ctx->r2 = ADD32(ctx->r6, 0X1);
    // 0x800435A8: sll         $v0, $v0, 8
    ctx->r2 = S32(ctx->r2 << 8);
    // 0x800435AC: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x800435B0: addu        $v1, $v1, $t0
    ctx->r3 = ADD32(ctx->r3, ctx->r8);
    // 0x800435B4: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x800435B8: beq         $v0, $zero, L_800435D0
    if (ctx->r2 == 0) {
        // 0x800435BC: nop
    
            goto L_800435D0;
    }
    // 0x800435BC: nop

    // 0x800435C0: lw          $v0, 0x14($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X14);
    // 0x800435C4: lbu         $v0, 0x30($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X30);
    // 0x800435C8: beql        $v0, $a3, L_8004364C
    if (ctx->r2 == ctx->r7) {
        // 0x800435CC: sb          $a0, 0x14($a1)
        MEM_B(0X14, ctx->r5) = ctx->r4;
            goto L_8004364C;
    }
    goto skip_5;
    // 0x800435CC: sb          $a0, 0x14($a1)
    MEM_B(0X14, ctx->r5) = ctx->r4;
    skip_5:
L_800435D0:
    // 0x800435D0: blez        $s1, L_80043604
    if (SIGNED(ctx->r17) <= 0) {
        // 0x800435D4: addiu       $v0, $s1, -0x1
        ctx->r2 = ADD32(ctx->r17, -0X1);
            goto L_80043604;
    }
    // 0x800435D4: addiu       $v0, $s1, -0x1
    ctx->r2 = ADD32(ctx->r17, -0X1);
    // 0x800435D8: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800435DC: sll         $v1, $a2, 8
    ctx->r3 = S32(ctx->r6 << 8);
    // 0x800435E0: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800435E4: addu        $v0, $v0, $t0
    ctx->r2 = ADD32(ctx->r2, ctx->r8);
    // 0x800435E8: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x800435EC: beql        $v0, $zero, L_80043608
    if (ctx->r2 == 0) {
        // 0x800435F0: lui         $v0, 0x8013
        ctx->r2 = S32(0X8013 << 16);
            goto L_80043608;
    }
    goto skip_6;
    // 0x800435F0: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    skip_6:
    // 0x800435F4: lw          $v0, 0x14($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X14);
    // 0x800435F8: lbu         $v0, 0x30($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X30);
    // 0x800435FC: beql        $v0, $a3, L_8004364C
    if (ctx->r2 == ctx->r7) {
        // 0x80043600: sb          $a0, 0x14($a1)
        MEM_B(0X14, ctx->r5) = ctx->r4;
            goto L_8004364C;
    }
    goto skip_7;
    // 0x80043600: sb          $a0, 0x14($a1)
    MEM_B(0X14, ctx->r5) = ctx->r4;
    skip_7:
L_80043604:
    // 0x80043604: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
L_80043608:
    // 0x80043608: lw          $v0, 0x2DB4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X2DB4);
    // 0x8004360C: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x80043610: slt         $v0, $s1, $v0
    ctx->r2 = SIGNED(ctx->r17) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80043614: beq         $v0, $zero, L_80043670
    if (ctx->r2 == 0) {
        // 0x80043618: addiu       $v0, $s1, 0x1
        ctx->r2 = ADD32(ctx->r17, 0X1);
            goto L_80043670;
    }
    // 0x80043618: addiu       $v0, $s1, 0x1
    ctx->r2 = ADD32(ctx->r17, 0X1);
    // 0x8004361C: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80043620: sll         $v1, $a2, 8
    ctx->r3 = S32(ctx->r6 << 8);
    // 0x80043624: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80043628: addu        $v0, $v0, $t0
    ctx->r2 = ADD32(ctx->r2, ctx->r8);
    // 0x8004362C: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x80043630: beq         $v0, $zero, L_80043670
    if (ctx->r2 == 0) {
        // 0x80043634: nop
    
            goto L_80043670;
    }
    // 0x80043634: nop

    // 0x80043638: lw          $v0, 0x14($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X14);
    // 0x8004363C: lbu         $v0, 0x30($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X30);
    // 0x80043640: bne         $v0, $a3, L_80043670
    if (ctx->r2 != ctx->r7) {
        // 0x80043644: nop
    
            goto L_80043670;
    }
    // 0x80043644: nop

    // 0x80043648: sb          $a0, 0x14($a1)
    MEM_B(0X14, ctx->r5) = ctx->r4;
L_8004364C:
    // 0x8004364C: sb          $a0, 0x13($a1)
    MEM_B(0X13, ctx->r5) = ctx->r4;
    // 0x80043650: sb          $a0, 0x12($a1)
    MEM_B(0X12, ctx->r5) = ctx->r4;
    // 0x80043654: sb          $a0, 0x11($a1)
    MEM_B(0X11, ctx->r5) = ctx->r4;
    // 0x80043658: sb          $a0, 0x10($a1)
    MEM_B(0X10, ctx->r5) = ctx->r4;
    // 0x8004365C: sh          $zero, 0x1E($a1)
    MEM_H(0X1E, ctx->r5) = 0;
    // 0x80043660: sh          $zero, 0x1C($a1)
    MEM_H(0X1C, ctx->r5) = 0;
    // 0x80043664: sh          $zero, 0x1A($a1)
    MEM_H(0X1A, ctx->r5) = 0;
    // 0x80043668: sh          $zero, 0x18($a1)
    MEM_H(0X18, ctx->r5) = 0;
    // 0x8004366C: sh          $zero, 0x16($a1)
    MEM_H(0X16, ctx->r5) = 0;
L_80043670:
    // 0x80043670: lw          $s0, 0x0($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X0);
    // 0x80043674: bne         $s0, $s6, L_8004353C
    if (ctx->r16 != ctx->r22) {
        // 0x80043678: nop
    
            goto L_8004353C;
    }
    // 0x80043678: nop

L_8004367C:
    // 0x8004367C: lw          $s0, 0x38($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X38);
    // 0x80043680: beq         $s0, $zero, L_80043770
    if (ctx->r16 == 0) {
        // 0x80043684: lui         $v0, 0x8013
        ctx->r2 = S32(0X8013 << 16);
            goto L_80043770;
    }
    // 0x80043684: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80043688: addiu       $a3, $v0, 0x2DC0
    ctx->r7 = ADD32(ctx->r2, 0X2DC0);
L_8004368C:
    // 0x8004368C: lw          $s1, 0xC($s0)
    ctx->r17 = MEM_W(ctx->r16, 0XC);
    // 0x80043690: lw          $v0, 0x14($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X14);
    // 0x80043694: lw          $a2, 0x10($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X10);
    // 0x80043698: blez        $a2, L_80043700
    if (SIGNED(ctx->r6) <= 0) {
        // 0x8004369C: addiu       $a1, $v0, 0x20
        ctx->r5 = ADD32(ctx->r2, 0X20);
            goto L_80043700;
    }
    // 0x8004369C: addiu       $a1, $v0, 0x20
    ctx->r5 = ADD32(ctx->r2, 0X20);
    // 0x800436A0: sll         $v1, $s1, 2
    ctx->r3 = S32(ctx->r17 << 2);
    // 0x800436A4: addiu       $v0, $a2, -0x1
    ctx->r2 = ADD32(ctx->r6, -0X1);
    // 0x800436A8: sll         $v0, $v0, 8
    ctx->r2 = S32(ctx->r2 << 8);
    // 0x800436AC: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x800436B0: addu        $v1, $v1, $a3
    ctx->r3 = ADD32(ctx->r3, ctx->r7);
    // 0x800436B4: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x800436B8: beq         $v0, $zero, L_80043700
    if (ctx->r2 == 0) {
        // 0x800436BC: nop
    
            goto L_80043700;
    }
    // 0x800436BC: nop

    // 0x800436C0: lw          $v0, 0x14($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X14);
    // 0x800436C4: lbu         $v1, 0x10($a1)
    ctx->r3 = MEM_BU(ctx->r5, 0X10);
    // 0x800436C8: addiu       $a0, $v0, 0x20
    ctx->r4 = ADD32(ctx->r2, 0X20);
    // 0x800436CC: lbu         $v0, 0x10($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X10);
    // 0x800436D0: sltu        $v0, $v0, $v1
    ctx->r2 = ctx->r2 < ctx->r3 ? 1 : 0;
    // 0x800436D4: beq         $v0, $zero, L_800436F0
    if (ctx->r2 == 0) {
        // 0x800436D8: nop
    
            goto L_800436F0;
    }
    // 0x800436D8: nop

    // 0x800436DC: lbu         $v0, 0x13($a1)
    ctx->r2 = MEM_BU(ctx->r5, 0X13);
    // 0x800436E0: sb          $v0, 0x14($a0)
    MEM_B(0X14, ctx->r4) = ctx->r2;
    // 0x800436E4: lhu         $v0, 0x1C($a1)
    ctx->r2 = MEM_HU(ctx->r5, 0X1C);
    // 0x800436E8: j           L_80043700
    // 0x800436EC: sh          $v0, 0x1E($a0)
    MEM_H(0X1E, ctx->r4) = ctx->r2;
        goto L_80043700;
    // 0x800436EC: sh          $v0, 0x1E($a0)
    MEM_H(0X1E, ctx->r4) = ctx->r2;
L_800436F0:
    // 0x800436F0: lbu         $v0, 0x14($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X14);
    // 0x800436F4: sb          $v0, 0x13($a1)
    MEM_B(0X13, ctx->r5) = ctx->r2;
    // 0x800436F8: lhu         $v0, 0x1E($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X1E);
    // 0x800436FC: sh          $v0, 0x1C($a1)
    MEM_H(0X1C, ctx->r5) = ctx->r2;
L_80043700:
    // 0x80043700: blez        $s1, L_80043764
    if (SIGNED(ctx->r17) <= 0) {
        // 0x80043704: addiu       $v0, $s1, -0x1
        ctx->r2 = ADD32(ctx->r17, -0X1);
            goto L_80043764;
    }
    // 0x80043704: addiu       $v0, $s1, -0x1
    ctx->r2 = ADD32(ctx->r17, -0X1);
    // 0x80043708: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8004370C: sll         $v1, $a2, 8
    ctx->r3 = S32(ctx->r6 << 8);
    // 0x80043710: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80043714: addu        $v0, $v0, $a3
    ctx->r2 = ADD32(ctx->r2, ctx->r7);
    // 0x80043718: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x8004371C: beq         $v0, $zero, L_80043764
    if (ctx->r2 == 0) {
        // 0x80043720: nop
    
            goto L_80043764;
    }
    // 0x80043720: nop

    // 0x80043724: lw          $v0, 0x14($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X14);
    // 0x80043728: lbu         $v1, 0x10($a1)
    ctx->r3 = MEM_BU(ctx->r5, 0X10);
    // 0x8004372C: addiu       $a0, $v0, 0x20
    ctx->r4 = ADD32(ctx->r2, 0X20);
    // 0x80043730: lbu         $v0, 0x10($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X10);
    // 0x80043734: sltu        $v0, $v0, $v1
    ctx->r2 = ctx->r2 < ctx->r3 ? 1 : 0;
    // 0x80043738: beq         $v0, $zero, L_80043754
    if (ctx->r2 == 0) {
        // 0x8004373C: nop
    
            goto L_80043754;
    }
    // 0x8004373C: nop

    // 0x80043740: lbu         $v0, 0x11($a1)
    ctx->r2 = MEM_BU(ctx->r5, 0X11);
    // 0x80043744: sb          $v0, 0x12($a0)
    MEM_B(0X12, ctx->r4) = ctx->r2;
    // 0x80043748: lhu         $v0, 0x18($a1)
    ctx->r2 = MEM_HU(ctx->r5, 0X18);
    // 0x8004374C: j           L_80043764
    // 0x80043750: sh          $v0, 0x1A($a0)
    MEM_H(0X1A, ctx->r4) = ctx->r2;
        goto L_80043764;
    // 0x80043750: sh          $v0, 0x1A($a0)
    MEM_H(0X1A, ctx->r4) = ctx->r2;
L_80043754:
    // 0x80043754: lbu         $v0, 0x12($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X12);
    // 0x80043758: sb          $v0, 0x11($a1)
    MEM_B(0X11, ctx->r5) = ctx->r2;
    // 0x8004375C: lhu         $v0, 0x1A($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X1A);
    // 0x80043760: sh          $v0, 0x18($a1)
    MEM_H(0X18, ctx->r5) = ctx->r2;
L_80043764:
    // 0x80043764: lw          $s0, 0x4($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X4);
    // 0x80043768: bne         $s0, $zero, L_8004368C
    if (ctx->r16 != 0) {
        // 0x8004376C: nop
    
            goto L_8004368C;
    }
    // 0x8004376C: nop

L_80043770:
    // 0x80043770: lw          $t1, 0x38($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X38);
    // 0x80043774: lw          $v1, 0x14($t1)
    ctx->r3 = MEM_W(ctx->r9, 0X14);
    // 0x80043778: addu        $v0, $s2, $zero
    ctx->r2 = ADD32(ctx->r18, 0);
    // 0x8004377C: sw          $zero, 0x24($v1)
    MEM_W(0X24, ctx->r3) = 0;
L_80043780:
    // 0x80043780: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x80043784: lw          $fp, 0x30($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X30);
    // 0x80043788: lw          $s7, 0x2C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X2C);
    // 0x8004378C: lw          $s6, 0x28($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X28);
    // 0x80043790: lw          $s5, 0x24($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X24);
    // 0x80043794: lw          $s4, 0x20($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X20);
    // 0x80043798: lw          $s3, 0x1C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X1C);
    // 0x8004379C: lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X18);
    // 0x800437A0: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x800437A4: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x800437A8: jr          $ra
    // 0x800437AC: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x800437AC: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_800437B0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800437B0: addiu       $sp, $sp, -0x88
    ctx->r29 = ADD32(ctx->r29, -0X88);
    // 0x800437B4: sdc1        $f22, 0x70($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X70, ctx->r29);
    // 0x800437B8: mtc1        $a2, $f22
    ctx->f22.u32l = ctx->r6;
    // 0x800437BC: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x800437C0: sw          $s2, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r18;
    // 0x800437C4: lw          $s2, -0x72E4($v0)
    ctx->r18 = MEM_W(ctx->r2, -0X72E4);
    // 0x800437C8: sw          $s3, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r19;
    // 0x800437CC: addu        $s3, $a0, $zero
    ctx->r19 = ADD32(ctx->r4, 0);
    // 0x800437D0: sw          $s4, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r20;
    // 0x800437D4: sw          $ra, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r31;
    // 0x800437D8: sw          $s1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r17;
    // 0x800437DC: sw          $s0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r16;
    // 0x800437E0: sdc1        $f26, 0x80($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X80, ctx->r29);
    // 0x800437E4: sdc1        $f24, 0x78($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X78, ctx->r29);
    // 0x800437E8: sdc1        $f20, 0x68($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X68, ctx->r29);
    // 0x800437EC: jal         0x80049304
    // 0x800437F0: addu        $s4, $a1, $zero
    ctx->r20 = ADD32(ctx->r5, 0);
    func_80049304(rdram, ctx);
        goto after_0;
    // 0x800437F0: addu        $s4, $a1, $zero
    ctx->r20 = ADD32(ctx->r5, 0);
    after_0:
    // 0x800437F4: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x800437F8: addiu       $v1, $v1, 0x7A68
    ctx->r3 = ADD32(ctx->r3, 0X7A68);
    // 0x800437FC: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x80043800: addiu       $a1, $a1, 0x6DC0
    ctx->r5 = ADD32(ctx->r5, 0X6DC0);
    // 0x80043804: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x80043808: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x8004380C: lwc1        $f2, 0x14($a1)
    ctx->f2.u32l = MEM_W(ctx->r5, 0X14);
    // 0x80043810: addiu       $s1, $s2, 0x28
    ctx->r17 = ADD32(ctx->r18, 0X28);
    // 0x80043814: lwc1        $f0, 0x24($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X24);
    // 0x80043818: lw          $v0, -0x7764($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7764);
    // 0x8004381C: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x80043820: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80043824: lwc1        $f6, -0x5AE8($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X5AE8);
    // 0x80043828: andi        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 & 0X1;
    // 0x8004382C: mul.s       $f0, $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x80043830: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80043834: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80043838: lw          $a2, 0x0($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X0);
    // 0x8004383C: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x80043840: swc1        $f0, 0xC10($a0)
    MEM_W(0XC10, ctx->r4) = ctx->f0.u32l;
    // 0x80043844: lwc1        $f2, 0x28($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0X28);
    // 0x80043848: lwc1        $f0, 0x18($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0X18);
    // 0x8004384C: lwc1        $f4, 0xC50($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XC50);
    // 0x80043850: sub.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl - ctx->f0.fl;
    // 0x80043854: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80043858: lwc1        $f0, -0x5AE4($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X5AE4);
    // 0x8004385C: mul.s       $f4, $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x80043860: nop

    // 0x80043864: mul.s       $f2, $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f6.fl);
    // 0x80043868: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8004386C: lwc1        $f0, -0x5AE0($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X5AE0);
    // 0x80043870: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80043874: lwc1        $f26, -0x5ADC($at)
    ctx->f26.u32l = MEM_W(ctx->r1, -0X5ADC);
    // 0x80043878: add.s       $f22, $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f22.fl = ctx->f22.fl + ctx->f0.fl;
    // 0x8004387C: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80043880: lwc1        $f24, -0x5AD8($at)
    ctx->f24.u32l = MEM_W(ctx->r1, -0X5AD8);
    // 0x80043884: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80043888: mul.s       $f22, $f22, $f6
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f22.fl = MUL_S(ctx->f22.fl, ctx->f6.fl);
    // 0x8004388C: lw          $v0, 0x7A60($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X7A60);
    // 0x80043890: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x80043894: sw          $v0, 0x7A74($v1)
    MEM_W(0X7A74, ctx->r3) = ctx->r2;
    // 0x80043898: addiu       $a0, $a0, 0xC10
    ctx->r4 = ADD32(ctx->r4, 0XC10);
    // 0x8004389C: mul.s       $f8, $f22, $f26
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f8.fl = MUL_S(ctx->f22.fl, ctx->f26.fl);
    // 0x800438A0: swc1        $f2, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f2.u32l;
    // 0x800438A4: lwc1        $f0, 0x2C($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X2C);
    // 0x800438A8: lwc1        $f2, 0x1C($a1)
    ctx->f2.u32l = MEM_W(ctx->r5, 0X1C);
    // 0x800438AC: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800438B0: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x800438B4: sw          $a2, 0x7A50($v0)
    MEM_W(0X7A50, ctx->r2) = ctx->r6;
    // 0x800438B8: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x800438BC: lwc1        $f2, -0x5AD4($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X5AD4);
    // 0x800438C0: mul.s       $f0, $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x800438C4: swc1        $f4, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f4.u32l;
    // 0x800438C8: swc1        $f2, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f2.u32l;
    // 0x800438CC: div.s       $f20, $f8, $f24
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f20.fl = DIV_S(ctx->f8.fl, ctx->f24.fl);
    // 0x800438D0: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    // 0x800438D4: jal         0x80033960
    // 0x800438D8: swc1        $f0, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f0.u32l;
    sinf_recomp(rdram, ctx);
        goto after_1;
    // 0x800438D8: swc1        $f0, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f0.u32l;
    after_1:
    // 0x800438DC: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    // 0x800438E0: jal         0x8002B190
    // 0x800438E4: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    cosf_recomp(rdram, ctx);
        goto after_2;
    // 0x800438E4: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    after_2:
    // 0x800438E8: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x800438EC: lwc1        $f12, -0x5AD0($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X5AD0);
    // 0x800438F0: sub.s       $f12, $f12, $f22
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f12.fl = ctx->f12.fl - ctx->f22.fl;
    // 0x800438F4: mul.s       $f12, $f12, $f26
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f12.fl = MUL_S(ctx->f12.fl, ctx->f26.fl);
    // 0x800438F8: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x800438FC: lwc1        $f2, -0x5ACC($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X5ACC);
    // 0x80043900: div.s       $f20, $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f20.fl = DIV_S(ctx->f20.fl, ctx->f0.fl);
    // 0x80043904: div.s       $f2, $f2, $f20
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f2.fl = DIV_S(ctx->f2.fl, ctx->f20.fl);
    // 0x80043908: swc1        $f2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f2.u32l;
    // 0x8004390C: jal         0x80033960
    // 0x80043910: div.s       $f12, $f12, $f24
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f12.fl = DIV_S(ctx->f12.fl, ctx->f24.fl);
    sinf_recomp(rdram, ctx);
        goto after_3;
    // 0x80043910: div.s       $f12, $f12, $f24
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f12.fl = DIV_S(ctx->f12.fl, ctx->f24.fl);
    after_3:
    // 0x80043914: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x80043918: lwc1        $f2, -0x2154($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, -0X2154);
    // 0x8004391C: lwc1        $f4, 0xC50($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XC50);
    // 0x80043920: mul.s       $f2, $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f4.fl);
    // 0x80043924: addiu       $a0, $sp, 0x40
    ctx->r4 = ADD32(ctx->r29, 0X40);
    // 0x80043928: lui         $s0, 0x800A
    ctx->r16 = S32(0X800A << 16);
    // 0x8004392C: div.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = DIV_S(ctx->f2.fl, ctx->f0.fl);
    // 0x80043930: jal         0x8001CF58
    // 0x80043934: swc1        $f2, -0x2150($s0)
    MEM_W(-0X2150, ctx->r16) = ctx->f2.u32l;
    normalize_vector(rdram, ctx);
        goto after_4;
    // 0x80043934: swc1        $f2, -0x2150($s0)
    MEM_W(-0X2150, ctx->r16) = ctx->f2.u32l;
    after_4:
    // 0x80043938: lwc1        $f6, 0x40($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X40);
    // 0x8004393C: lwc1        $f0, -0x2150($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, -0X2150);
    // 0x80043940: mul.s       $f6, $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x80043944: lwc1        $f4, 0x44($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X44);
    // 0x80043948: mul.s       $f4, $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x8004394C: lwc1        $f2, 0x48($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X48);
    // 0x80043950: mul.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x80043954: addiu       $v0, $sp, 0x10
    ctx->r2 = ADD32(ctx->r29, 0X10);
    // 0x80043958: addiu       $s2, $s2, 0x58
    ctx->r18 = ADD32(ctx->r18, 0X58);
    // 0x8004395C: swc1        $f6, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f6.u32l;
    // 0x80043960: swc1        $f4, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f4.u32l;
    // 0x80043964: swc1        $f2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f2.u32l;
L_80043968:
    // 0x80043968: lw          $a3, 0x0($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X0);
    // 0x8004396C: lw          $t0, 0x4($s1)
    ctx->r8 = MEM_W(ctx->r17, 0X4);
    // 0x80043970: lw          $t1, 0x8($s1)
    ctx->r9 = MEM_W(ctx->r17, 0X8);
    // 0x80043974: lw          $t2, 0xC($s1)
    ctx->r10 = MEM_W(ctx->r17, 0XC);
    // 0x80043978: sw          $a3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r7;
    // 0x8004397C: sw          $t0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r8;
    // 0x80043980: sw          $t1, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r9;
    // 0x80043984: sw          $t2, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r10;
    // 0x80043988: addiu       $s1, $s1, 0x10
    ctx->r17 = ADD32(ctx->r17, 0X10);
    // 0x8004398C: bne         $s1, $s2, L_80043968
    if (ctx->r17 != ctx->r18) {
        // 0x80043990: addiu       $v0, $v0, 0x10
        ctx->r2 = ADD32(ctx->r2, 0X10);
            goto L_80043968;
    }
    // 0x80043990: addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
    // 0x80043994: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    // 0x80043998: addiu       $s1, $sp, 0x40
    ctx->r17 = ADD32(ctx->r29, 0X40);
    // 0x8004399C: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    // 0x800439A0: lui         $s2, 0x8013
    ctx->r18 = S32(0X8013 << 16);
    // 0x800439A4: addiu       $s0, $s2, 0xC10
    ctx->r16 = ADD32(ctx->r18, 0XC10);
    // 0x800439A8: lwc1        $f0, 0xC10($s2)
    ctx->f0.u32l = MEM_W(ctx->r18, 0XC10);
    // 0x800439AC: lwc1        $f2, 0x4($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X4);
    // 0x800439B0: lwc1        $f4, 0x8($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X8);
    // 0x800439B4: addiu       $a2, $s0, 0xC
    ctx->r6 = ADD32(ctx->r16, 0XC);
    // 0x800439B8: swc1        $f0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f0.u32l;
    // 0x800439BC: swc1        $f2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f2.u32l;
    // 0x800439C0: jal         0x800193E8
    // 0x800439C4: swc1        $f4, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f4.u32l;
    func_800193E8(rdram, ctx);
        goto after_5;
    // 0x800439C4: swc1        $f4, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f4.u32l;
    after_5:
    // 0x800439C8: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    // 0x800439CC: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    // 0x800439D0: lwc1        $f0, 0x40($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X40);
    // 0x800439D4: addiu       $a2, $s0, 0x18
    ctx->r6 = ADD32(ctx->r16, 0X18);
    // 0x800439D8: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
    // 0x800439DC: jal         0x800193E8
    // 0x800439E0: swc1        $f0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f0.u32l;
    func_800193E8(rdram, ctx);
        goto after_6;
    // 0x800439E0: swc1        $f0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f0.u32l;
    after_6:
    // 0x800439E4: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    // 0x800439E8: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    // 0x800439EC: lwc1        $f0, 0x44($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X44);
    // 0x800439F0: addiu       $a2, $s0, 0x24
    ctx->r6 = ADD32(ctx->r16, 0X24);
    // 0x800439F4: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
    // 0x800439F8: jal         0x800193E8
    // 0x800439FC: swc1        $f0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f0.u32l;
    func_800193E8(rdram, ctx);
        goto after_7;
    // 0x800439FC: swc1        $f0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f0.u32l;
    after_7:
    // 0x80043A00: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    // 0x80043A04: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    // 0x80043A08: lwc1        $f0, 0x40($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X40);
    // 0x80043A0C: addiu       $a2, $s0, 0x30
    ctx->r6 = ADD32(ctx->r16, 0X30);
    // 0x80043A10: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
    // 0x80043A14: jal         0x800193E8
    // 0x80043A18: swc1        $f0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f0.u32l;
    func_800193E8(rdram, ctx);
        goto after_8;
    // 0x80043A18: swc1        $f0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f0.u32l;
    after_8:
    // 0x80043A1C: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x80043A20: addiu       $v1, $v1, 0x6DC0
    ctx->r3 = ADD32(ctx->r3, 0X6DC0);
    // 0x80043A24: lwc1        $f2, 0x14($v1)
    ctx->f2.u32l = MEM_W(ctx->r3, 0X14);
    // 0x80043A28: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80043A2C: lwc1        $f4, -0x5AC8($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X5AC8);
    // 0x80043A30: mul.s       $f2, $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f4.fl);
    // 0x80043A34: lwc1        $f0, 0xC10($s2)
    ctx->f0.u32l = MEM_W(ctx->r18, 0XC10);
    // 0x80043A38: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x80043A3C: trunc.w.s   $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    ctx->f10.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x80043A40: mfc1        $v0, $f10
    ctx->r2 = (int32_t)ctx->f10.u32l;
    // 0x80043A44: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x80043A48: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x80043A4C: add.s       $f0, $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f0.fl;
    // 0x80043A50: swc1        $f0, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->f0.u32l;
    // 0x80043A54: lwc1        $f2, 0x1C($v1)
    ctx->f2.u32l = MEM_W(ctx->r3, 0X1C);
    // 0x80043A58: mul.s       $f2, $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f4.fl);
    // 0x80043A5C: lwc1        $f0, 0x8($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X8);
    // 0x80043A60: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x80043A64: trunc.w.s   $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    ctx->f10.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x80043A68: mfc1        $v0, $f10
    ctx->r2 = (int32_t)ctx->f10.u32l;
    // 0x80043A6C: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x80043A70: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x80043A74: add.s       $f0, $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f0.fl;
    // 0x80043A78: swc1        $f0, 0x8($s3)
    MEM_W(0X8, ctx->r19) = ctx->f0.u32l;
    // 0x80043A7C: lwc1        $f0, 0x18($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X18);
    // 0x80043A80: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x80043A84: jal         0x8004286C
    // 0x80043A88: swc1        $f0, 0x4($s3)
    MEM_W(0X4, ctx->r19) = ctx->f0.u32l;
    func_8004286C(rdram, ctx);
        goto after_9;
    // 0x80043A88: swc1        $f0, 0x4($s3)
    MEM_W(0X4, ctx->r19) = ctx->f0.u32l;
    after_9:
    // 0x80043A8C: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x80043A90: jal         0x80042B50
    // 0x80043A94: addu        $a1, $s3, $zero
    ctx->r5 = ADD32(ctx->r19, 0);
    func_80042B50(rdram, ctx);
        goto after_10;
    // 0x80043A94: addu        $a1, $s3, $zero
    ctx->r5 = ADD32(ctx->r19, 0);
    after_10:
    // 0x80043A98: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    // 0x80043A9C: beq         $s0, $zero, L_80043AB8
    if (ctx->r16 == 0) {
        // 0x80043AA0: addu        $a0, $s0, $zero
        ctx->r4 = ADD32(ctx->r16, 0);
            goto L_80043AB8;
    }
    // 0x80043AA0: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x80043AA4: jal         0x8004317C
    // 0x80043AA8: addu        $a1, $s4, $zero
    ctx->r5 = ADD32(ctx->r20, 0);
    func_8004317C(rdram, ctx);
        goto after_11;
    // 0x80043AA8: addu        $a1, $s4, $zero
    ctx->r5 = ADD32(ctx->r20, 0);
    after_11:
    // 0x80043AAC: lw          $v0, 0x14($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X14);
    // 0x80043AB0: j           L_80043ABC
    // 0x80043AB4: addiu       $v0, $v0, 0x20
    ctx->r2 = ADD32(ctx->r2, 0X20);
        goto L_80043ABC;
    // 0x80043AB4: addiu       $v0, $v0, 0x20
    ctx->r2 = ADD32(ctx->r2, 0X20);
L_80043AB8:
    // 0x80043AB8: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_80043ABC:
    // 0x80043ABC: lw          $ra, 0x64($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X64);
    // 0x80043AC0: lw          $s4, 0x60($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X60);
    // 0x80043AC4: lw          $s3, 0x5C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X5C);
    // 0x80043AC8: lw          $s2, 0x58($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X58);
    // 0x80043ACC: lw          $s1, 0x54($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X54);
    // 0x80043AD0: lw          $s0, 0x50($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X50);
    // 0x80043AD4: ldc1        $f26, 0x80($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X80);
    // 0x80043AD8: ldc1        $f24, 0x78($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X78);
    // 0x80043ADC: ldc1        $f22, 0x70($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X70);
    // 0x80043AE0: ldc1        $f20, 0x68($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X68);
    // 0x80043AE4: jr          $ra
    // 0x80043AE8: addiu       $sp, $sp, 0x88
    ctx->r29 = ADD32(ctx->r29, 0X88);
    return;
    // 0x80043AE8: addiu       $sp, $sp, 0x88
    ctx->r29 = ADD32(ctx->r29, 0X88);
;}
RECOMP_FUNC void func_80043AEC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80043AEC: mtc1        $a3, $f8
    ctx->f8.u32l = ctx->r7;
    // 0x80043AF0: lui         $a3, 0x8013
    ctx->r7 = S32(0X8013 << 16);
    // 0x80043AF4: addiu       $a0, $a3, 0x6DC0
    ctx->r4 = ADD32(ctx->r7, 0X6DC0);
    // 0x80043AF8: lwc1        $f2, 0x20($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X20);
    // 0x80043AFC: sub.s       $f12, $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f12.fl = ctx->f12.fl - ctx->f2.fl;
    // 0x80043B00: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80043B04: lwc1        $f4, -0x5AC4($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X5AC4);
    // 0x80043B08: mul.s       $f12, $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = MUL_S(ctx->f12.fl, ctx->f4.fl);
    // 0x80043B0C: mtc1        $a2, $f6
    ctx->f6.u32l = ctx->r6;
    // 0x80043B10: trunc.w.s   $f10, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    ctx->f10.u32l = TRUNC_W_S(ctx->f12.fl);
    // 0x80043B14: mfc1        $t2, $f10
    ctx->r10 = (int32_t)ctx->f10.u32l;
    // 0x80043B18: bltzl       $t2, L_80043B20
    if (SIGNED(ctx->r10) < 0) {
        // 0x80043B1C: addu        $t2, $zero, $zero
        ctx->r10 = ADD32(0, 0);
            goto L_80043B20;
    }
    goto skip_0;
    // 0x80043B1C: addu        $t2, $zero, $zero
    ctx->r10 = ADD32(0, 0);
    skip_0:
L_80043B20:
    // 0x80043B20: sub.s       $f0, $f14, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f14.fl - ctx->f2.fl;
    // 0x80043B24: mul.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x80043B28: lhu         $v1, 0x38($a0)
    ctx->r3 = MEM_HU(ctx->r4, 0X38);
    // 0x80043B2C: trunc.w.s   $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    ctx->f10.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x80043B30: mfc1        $a2, $f10
    ctx->r6 = (int32_t)ctx->f10.u32l;
    // 0x80043B34: slt         $v0, $a2, $v1
    ctx->r2 = SIGNED(ctx->r6) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80043B38: beql        $v0, $zero, L_80043B40
    if (ctx->r2 == 0) {
        // 0x80043B3C: addiu       $a2, $v1, -0x1
        ctx->r6 = ADD32(ctx->r3, -0X1);
            goto L_80043B40;
    }
    goto skip_1;
    // 0x80043B3C: addiu       $a2, $v1, -0x1
    ctx->r6 = ADD32(ctx->r3, -0X1);
    skip_1:
L_80043B40:
    // 0x80043B40: lwc1        $f2, 0x2C($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X2C);
    // 0x80043B44: sub.s       $f0, $f6, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f6.fl - ctx->f2.fl;
    // 0x80043B48: mul.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x80043B4C: trunc.w.s   $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    ctx->f10.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x80043B50: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x80043B54: bltzl       $a1, L_80043B5C
    if (SIGNED(ctx->r5) < 0) {
        // 0x80043B58: addu        $a1, $zero, $zero
        ctx->r5 = ADD32(0, 0);
            goto L_80043B5C;
    }
    goto skip_2;
    // 0x80043B58: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    skip_2:
L_80043B5C:
    // 0x80043B5C: sub.s       $f0, $f8, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f8.fl - ctx->f2.fl;
    // 0x80043B60: mul.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x80043B64: lhu         $v1, 0x3A($a0)
    ctx->r3 = MEM_HU(ctx->r4, 0X3A);
    // 0x80043B68: trunc.w.s   $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    ctx->f10.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x80043B6C: mfc1        $t0, $f10
    ctx->r8 = (int32_t)ctx->f10.u32l;
    // 0x80043B70: slt         $v0, $t0, $v1
    ctx->r2 = SIGNED(ctx->r8) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80043B74: beql        $v0, $zero, L_80043B7C
    if (ctx->r2 == 0) {
        // 0x80043B78: addiu       $t0, $v1, -0x1
        ctx->r8 = ADD32(ctx->r3, -0X1);
            goto L_80043B7C;
    }
    goto skip_3;
    // 0x80043B78: addiu       $t0, $v1, -0x1
    ctx->r8 = ADD32(ctx->r3, -0X1);
    skip_3:
L_80043B7C:
    // 0x80043B7C: slt         $v0, $t0, $a1
    ctx->r2 = SIGNED(ctx->r8) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x80043B80: bne         $v0, $zero, L_80043C28
    if (ctx->r2 != 0) {
        // 0x80043B84: addu        $t1, $a3, $zero
        ctx->r9 = ADD32(ctx->r7, 0);
            goto L_80043C28;
    }
    // 0x80043B84: addu        $t1, $a3, $zero
    ctx->r9 = ADD32(ctx->r7, 0);
    // 0x80043B88: addu        $a3, $a0, $zero
    ctx->r7 = ADD32(ctx->r4, 0);
    // 0x80043B8C: addu        $a0, $t2, $zero
    ctx->r4 = ADD32(ctx->r10, 0);
L_80043B90:
    // 0x80043B90: slt         $v0, $a2, $a0
    ctx->r2 = SIGNED(ctx->r6) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x80043B94: bnel        $v0, $zero, L_80043C1C
    if (ctx->r2 != 0) {
        // 0x80043B98: addiu       $a1, $a1, 0x1
        ctx->r5 = ADD32(ctx->r5, 0X1);
            goto L_80043C1C;
    }
    goto skip_4;
    // 0x80043B98: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    skip_4:
L_80043B9C:
    // 0x80043B9C: lhu         $v0, 0x38($a3)
    ctx->r2 = MEM_HU(ctx->r7, 0X38);
    // 0x80043BA0: mult        $a1, $v0
    result = S64(S32(ctx->r5)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80043BA4: lw          $v0, 0x6DC0($t1)
    ctx->r2 = MEM_W(ctx->r9, 0X6DC0);
    // 0x80043BA8: mflo        $t3
    ctx->r11 = lo;
    // 0x80043BAC: addu        $v1, $a0, $t3
    ctx->r3 = ADD32(ctx->r4, ctx->r11);
    // 0x80043BB0: sll         $v1, $v1, 1
    ctx->r3 = S32(ctx->r3 << 1);
    // 0x80043BB4: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x80043BB8: lhu         $v0, 0x0($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X0);
    // 0x80043BBC: ori         $v0, $v0, 0x8000
    ctx->r2 = ctx->r2 | 0X8000;
    // 0x80043BC0: sh          $v0, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r2;
    // 0x80043BC4: lhu         $v0, 0x38($a3)
    ctx->r2 = MEM_HU(ctx->r7, 0X38);
    // 0x80043BC8: mult        $a1, $v0
    result = S64(S32(ctx->r5)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80043BCC: lw          $v1, 0x6DC0($t1)
    ctx->r3 = MEM_W(ctx->r9, 0X6DC0);
    // 0x80043BD0: mflo        $t3
    ctx->r11 = lo;
    // 0x80043BD4: addu        $v0, $a0, $t3
    ctx->r2 = ADD32(ctx->r4, ctx->r11);
    // 0x80043BD8: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x80043BDC: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80043BE0: lhu         $v0, 0x0($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X0);
    // 0x80043BE4: andi        $v0, $v0, 0x1FFF
    ctx->r2 = ctx->r2 & 0X1FFF;
    // 0x80043BE8: sll         $v1, $v0, 4
    ctx->r3 = S32(ctx->r2 << 4);
    // 0x80043BEC: subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // 0x80043BF0: lw          $v0, 0x4($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X4);
    // 0x80043BF4: sll         $v1, $v1, 1
    ctx->r3 = S32(ctx->r3 << 1);
    // 0x80043BF8: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x80043BFC: lbu         $v0, 0x2($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X2);
    // 0x80043C00: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x80043C04: ori         $v0, $v0, 0x1
    ctx->r2 = ctx->r2 | 0X1;
    // 0x80043C08: sb          $v0, 0x2($v1)
    MEM_B(0X2, ctx->r3) = ctx->r2;
    // 0x80043C0C: slt         $v0, $a2, $a0
    ctx->r2 = SIGNED(ctx->r6) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x80043C10: beq         $v0, $zero, L_80043B9C
    if (ctx->r2 == 0) {
        // 0x80043C14: nop
    
            goto L_80043B9C;
    }
    // 0x80043C14: nop

    // 0x80043C18: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
L_80043C1C:
    // 0x80043C1C: slt         $v0, $t0, $a1
    ctx->r2 = SIGNED(ctx->r8) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x80043C20: beq         $v0, $zero, L_80043B90
    if (ctx->r2 == 0) {
        // 0x80043C24: addu        $a0, $t2, $zero
        ctx->r4 = ADD32(ctx->r10, 0);
            goto L_80043B90;
    }
    // 0x80043C24: addu        $a0, $t2, $zero
    ctx->r4 = ADD32(ctx->r10, 0);
L_80043C28:
    // 0x80043C28: jr          $ra
    // 0x80043C2C: nop

    return;
    // 0x80043C2C: nop

;}
RECOMP_FUNC void func_80043C30(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80043C30: mtc1        $a3, $f8
    ctx->f8.u32l = ctx->r7;
    // 0x80043C34: lui         $a3, 0x8013
    ctx->r7 = S32(0X8013 << 16);
    // 0x80043C38: addiu       $a0, $a3, 0x6DC0
    ctx->r4 = ADD32(ctx->r7, 0X6DC0);
    // 0x80043C3C: lwc1        $f2, 0x20($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X20);
    // 0x80043C40: sub.s       $f12, $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f12.fl = ctx->f12.fl - ctx->f2.fl;
    // 0x80043C44: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80043C48: lwc1        $f4, -0x5AC0($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X5AC0);
    // 0x80043C4C: mul.s       $f12, $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = MUL_S(ctx->f12.fl, ctx->f4.fl);
    // 0x80043C50: mtc1        $a2, $f6
    ctx->f6.u32l = ctx->r6;
    // 0x80043C54: trunc.w.s   $f10, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    ctx->f10.u32l = TRUNC_W_S(ctx->f12.fl);
    // 0x80043C58: mfc1        $t2, $f10
    ctx->r10 = (int32_t)ctx->f10.u32l;
    // 0x80043C5C: bltzl       $t2, L_80043C64
    if (SIGNED(ctx->r10) < 0) {
        // 0x80043C60: addu        $t2, $zero, $zero
        ctx->r10 = ADD32(0, 0);
            goto L_80043C64;
    }
    goto skip_0;
    // 0x80043C60: addu        $t2, $zero, $zero
    ctx->r10 = ADD32(0, 0);
    skip_0:
L_80043C64:
    // 0x80043C64: sub.s       $f0, $f14, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f14.fl - ctx->f2.fl;
    // 0x80043C68: mul.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x80043C6C: lhu         $v1, 0x38($a0)
    ctx->r3 = MEM_HU(ctx->r4, 0X38);
    // 0x80043C70: trunc.w.s   $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    ctx->f10.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x80043C74: mfc1        $a2, $f10
    ctx->r6 = (int32_t)ctx->f10.u32l;
    // 0x80043C78: slt         $v0, $a2, $v1
    ctx->r2 = SIGNED(ctx->r6) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80043C7C: beql        $v0, $zero, L_80043C84
    if (ctx->r2 == 0) {
        // 0x80043C80: addiu       $a2, $v1, -0x1
        ctx->r6 = ADD32(ctx->r3, -0X1);
            goto L_80043C84;
    }
    goto skip_1;
    // 0x80043C80: addiu       $a2, $v1, -0x1
    ctx->r6 = ADD32(ctx->r3, -0X1);
    skip_1:
L_80043C84:
    // 0x80043C84: lwc1        $f2, 0x2C($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X2C);
    // 0x80043C88: sub.s       $f0, $f6, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f6.fl - ctx->f2.fl;
    // 0x80043C8C: mul.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x80043C90: trunc.w.s   $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    ctx->f10.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x80043C94: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x80043C98: bltzl       $a1, L_80043CA0
    if (SIGNED(ctx->r5) < 0) {
        // 0x80043C9C: addu        $a1, $zero, $zero
        ctx->r5 = ADD32(0, 0);
            goto L_80043CA0;
    }
    goto skip_2;
    // 0x80043C9C: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    skip_2:
L_80043CA0:
    // 0x80043CA0: sub.s       $f0, $f8, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f8.fl - ctx->f2.fl;
    // 0x80043CA4: mul.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x80043CA8: lhu         $v1, 0x3A($a0)
    ctx->r3 = MEM_HU(ctx->r4, 0X3A);
    // 0x80043CAC: trunc.w.s   $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    ctx->f10.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x80043CB0: mfc1        $t0, $f10
    ctx->r8 = (int32_t)ctx->f10.u32l;
    // 0x80043CB4: slt         $v0, $t0, $v1
    ctx->r2 = SIGNED(ctx->r8) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80043CB8: beql        $v0, $zero, L_80043CC0
    if (ctx->r2 == 0) {
        // 0x80043CBC: addiu       $t0, $v1, -0x1
        ctx->r8 = ADD32(ctx->r3, -0X1);
            goto L_80043CC0;
    }
    goto skip_3;
    // 0x80043CBC: addiu       $t0, $v1, -0x1
    ctx->r8 = ADD32(ctx->r3, -0X1);
    skip_3:
L_80043CC0:
    // 0x80043CC0: slt         $v0, $t0, $a1
    ctx->r2 = SIGNED(ctx->r8) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x80043CC4: bne         $v0, $zero, L_80043D6C
    if (ctx->r2 != 0) {
        // 0x80043CC8: addu        $t1, $a3, $zero
        ctx->r9 = ADD32(ctx->r7, 0);
            goto L_80043D6C;
    }
    // 0x80043CC8: addu        $t1, $a3, $zero
    ctx->r9 = ADD32(ctx->r7, 0);
    // 0x80043CCC: addu        $a3, $a0, $zero
    ctx->r7 = ADD32(ctx->r4, 0);
    // 0x80043CD0: addu        $a0, $t2, $zero
    ctx->r4 = ADD32(ctx->r10, 0);
L_80043CD4:
    // 0x80043CD4: slt         $v0, $a2, $a0
    ctx->r2 = SIGNED(ctx->r6) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x80043CD8: bnel        $v0, $zero, L_80043D60
    if (ctx->r2 != 0) {
        // 0x80043CDC: addiu       $a1, $a1, 0x1
        ctx->r5 = ADD32(ctx->r5, 0X1);
            goto L_80043D60;
    }
    goto skip_4;
    // 0x80043CDC: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    skip_4:
L_80043CE0:
    // 0x80043CE0: lhu         $v0, 0x38($a3)
    ctx->r2 = MEM_HU(ctx->r7, 0X38);
    // 0x80043CE4: mult        $a1, $v0
    result = S64(S32(ctx->r5)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80043CE8: lw          $v0, 0x6DC0($t1)
    ctx->r2 = MEM_W(ctx->r9, 0X6DC0);
    // 0x80043CEC: mflo        $t3
    ctx->r11 = lo;
    // 0x80043CF0: addu        $v1, $a0, $t3
    ctx->r3 = ADD32(ctx->r4, ctx->r11);
    // 0x80043CF4: sll         $v1, $v1, 1
    ctx->r3 = S32(ctx->r3 << 1);
    // 0x80043CF8: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x80043CFC: lhu         $v0, 0x0($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X0);
    // 0x80043D00: ori         $v0, $v0, 0x4000
    ctx->r2 = ctx->r2 | 0X4000;
    // 0x80043D04: sh          $v0, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r2;
    // 0x80043D08: lhu         $v0, 0x38($a3)
    ctx->r2 = MEM_HU(ctx->r7, 0X38);
    // 0x80043D0C: mult        $a1, $v0
    result = S64(S32(ctx->r5)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80043D10: lw          $v1, 0x6DC0($t1)
    ctx->r3 = MEM_W(ctx->r9, 0X6DC0);
    // 0x80043D14: mflo        $t3
    ctx->r11 = lo;
    // 0x80043D18: addu        $v0, $a0, $t3
    ctx->r2 = ADD32(ctx->r4, ctx->r11);
    // 0x80043D1C: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x80043D20: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80043D24: lhu         $v0, 0x0($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X0);
    // 0x80043D28: andi        $v0, $v0, 0x1FFF
    ctx->r2 = ctx->r2 & 0X1FFF;
    // 0x80043D2C: sll         $v1, $v0, 4
    ctx->r3 = S32(ctx->r2 << 4);
    // 0x80043D30: subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // 0x80043D34: lw          $v0, 0x4($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X4);
    // 0x80043D38: sll         $v1, $v1, 1
    ctx->r3 = S32(ctx->r3 << 1);
    // 0x80043D3C: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x80043D40: lbu         $v0, 0x2($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X2);
    // 0x80043D44: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x80043D48: ori         $v0, $v0, 0x2
    ctx->r2 = ctx->r2 | 0X2;
    // 0x80043D4C: sb          $v0, 0x2($v1)
    MEM_B(0X2, ctx->r3) = ctx->r2;
    // 0x80043D50: slt         $v0, $a2, $a0
    ctx->r2 = SIGNED(ctx->r6) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x80043D54: beq         $v0, $zero, L_80043CE0
    if (ctx->r2 == 0) {
        // 0x80043D58: nop
    
            goto L_80043CE0;
    }
    // 0x80043D58: nop

    // 0x80043D5C: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
L_80043D60:
    // 0x80043D60: slt         $v0, $t0, $a1
    ctx->r2 = SIGNED(ctx->r8) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x80043D64: beq         $v0, $zero, L_80043CD4
    if (ctx->r2 == 0) {
        // 0x80043D68: addu        $a0, $t2, $zero
        ctx->r4 = ADD32(ctx->r10, 0);
            goto L_80043CD4;
    }
    // 0x80043D68: addu        $a0, $t2, $zero
    ctx->r4 = ADD32(ctx->r10, 0);
L_80043D6C:
    // 0x80043D6C: jr          $ra
    // 0x80043D70: nop

    return;
    // 0x80043D70: nop

;}
RECOMP_FUNC void load_level_hmp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80043D74: addiu       $sp, $sp, -0x88
    ctx->r29 = ADD32(ctx->r29, -0X88);
    // 0x80043D78: sw          $fp, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r30;
    // 0x80043D7C: addu        $fp, $a1, $zero
    ctx->r30 = ADD32(ctx->r5, 0);
    // 0x80043D80: sw          $a0, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r4;
    // 0x80043D84: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    // 0x80043D88: lui         $a1, 0x8004
    ctx->r5 = S32(0X8004 << 16);
    // 0x80043D8C: addiu       $a1, $a1, -0x5ABC
    ctx->r5 = ADD32(ctx->r5, -0X5ABC);
    // 0x80043D90: sw          $ra, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r31;
    // 0x80043D94: sw          $s7, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r23;
    // 0x80043D98: sw          $s6, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r22;
    // 0x80043D9C: sw          $s5, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r21;
    // 0x80043DA0: sw          $s4, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r20;
    // 0x80043DA4: sw          $s3, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r19;
    // 0x80043DA8: sw          $s2, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r18;
    // 0x80043DAC: sw          $s1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r17;
    // 0x80043DB0: sw          $s0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r16;
    // 0x80043DB4: sdc1        $f20, 0x80($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X80, ctx->r29);
    // 0x80043DB8: jal         0x80033CC4
    // 0x80043DBC: addu        $a2, $fp, $zero
    ctx->r6 = ADD32(ctx->r30, 0);
    sprintf_recomp(rdram, ctx);
        goto after_0;
    // 0x80043DBC: addu        $a2, $fp, $zero
    ctx->r6 = ADD32(ctx->r30, 0);
    after_0:
    // 0x80043DC0: lui         $s1, 0x8013
    ctx->r17 = S32(0X8013 << 16);
    // 0x80043DC4: lw          $a0, 0x7CFC($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X7CFC);
    // 0x80043DC8: jal         0x80004D5C
    // 0x80043DCC: addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    get_asset_size_extra(rdram, ctx);
        goto after_1;
    // 0x80043DCC: addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    after_1:
    // 0x80043DD0: addu        $s2, $v0, $zero
    ctx->r18 = ADD32(ctx->r2, 0);
    // 0x80043DD4: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // 0x80043DD8: jal         0x80001ACC
    // 0x80043DDC: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    rs_malloc(rdram, ctx);
        goto after_2;
    // 0x80043DDC: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    after_2:
    // 0x80043DE0: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x80043DE4: addiu       $a3, $sp, 0x18
    ctx->r7 = ADD32(ctx->r29, 0X18);
    // 0x80043DE8: lui         $s0, 0x8014
    ctx->r16 = S32(0X8014 << 16);
    // 0x80043DEC: lw          $a0, -0x76E0($s0)
    ctx->r4 = MEM_W(ctx->r16, -0X76E0);
    // 0x80043DF0: lw          $a2, 0x7CFC($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X7CFC);
    // 0x80043DF4: lui         $s1, 0x8013
    ctx->r17 = S32(0X8013 << 16);
    // 0x80043DF8: sw          $v0, 0x6FC4($s1)
    MEM_W(0X6FC4, ctx->r17) = ctx->r2;
    // 0x80043DFC: jal         0x80004AAC
    // 0x80043E00: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    func_80004AAC(rdram, ctx);
        goto after_3;
    // 0x80043E00: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_3:
    // 0x80043E04: addu        $s3, $v0, $zero
    ctx->r19 = ADD32(ctx->r2, 0);
    // 0x80043E08: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x80043E0C: addu        $a2, $s3, $zero
    ctx->r6 = ADD32(ctx->r19, 0);
    // 0x80043E10: lw          $a0, -0x76E0($s0)
    ctx->r4 = MEM_W(ctx->r16, -0X76E0);
    // 0x80043E14: lw          $v0, 0x6FC4($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X6FC4);
    // 0x80043E18: addu        $a3, $a1, $zero
    ctx->r7 = ADD32(ctx->r5, 0);
    // 0x80043E1C: sw          $s2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r18;
    // 0x80043E20: jal         0x80004E70
    // 0x80043E24: sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    func_80004E70(rdram, ctx);
        goto after_4;
    // 0x80043E24: sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    after_4:
    // 0x80043E28: lw          $a0, -0x76E0($s0)
    ctx->r4 = MEM_W(ctx->r16, -0X76E0);
    // 0x80043E2C: jal         0x80004C70
    // 0x80043E30: addu        $a1, $s3, $zero
    ctx->r5 = ADD32(ctx->r19, 0);
    func_80004C70(rdram, ctx);
        goto after_5;
    // 0x80043E30: addu        $a1, $s3, $zero
    ctx->r5 = ADD32(ctx->r19, 0);
    after_5:
    // 0x80043E34: lw          $v1, 0x6FC4($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X6FC4);
    // 0x80043E38: lw          $v0, 0x1C($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X1C);
    // 0x80043E3C: lw          $a0, 0x20($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X20);
    // 0x80043E40: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80043E44: addu        $a0, $a0, $v1
    ctx->r4 = ADD32(ctx->r4, ctx->r3);
    // 0x80043E48: sw          $a0, 0x20($v1)
    MEM_W(0X20, ctx->r3) = ctx->r4;
    // 0x80043E4C: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80043E50: sw          $v0, 0x1C($v1)
    MEM_W(0X1C, ctx->r3) = ctx->r2;
    // 0x80043E54: addiu       $v0, $v1, 0x28
    ctx->r2 = ADD32(ctx->r3, 0X28);
    // 0x80043E58: sw          $v0, 0x6DC0($a0)
    MEM_W(0X6DC0, ctx->r4) = ctx->r2;
    // 0x80043E5C: lw          $v0, 0x1C($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X1C);
    // 0x80043E60: addiu       $a0, $a0, 0x6DC0
    ctx->r4 = ADD32(ctx->r4, 0X6DC0);
    // 0x80043E64: sw          $v0, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r2;
    // 0x80043E68: lhu         $s7, 0x18($v1)
    ctx->r23 = MEM_HU(ctx->r3, 0X18);
    // 0x80043E6C: beq         $s7, $zero, L_80043FE0
    if (ctx->r23 == 0) {
        // 0x80043E70: addu        $s3, $zero, $zero
        ctx->r19 = ADD32(0, 0);
            goto L_80043FE0;
    }
    // 0x80043E70: addu        $s3, $zero, $zero
    ctx->r19 = ADD32(0, 0);
    // 0x80043E74: addu        $t6, $a0, $zero
    ctx->r14 = ADD32(ctx->r4, 0);
    // 0x80043E78: addu        $t7, $s3, $zero
    ctx->r15 = ADD32(ctx->r19, 0);
L_80043E7C:
    // 0x80043E7C: addu        $s2, $zero, $zero
    ctx->r18 = ADD32(0, 0);
    // 0x80043E80: addiu       $s4, $zero, 0x1
    ctx->r20 = ADD32(0, 0X1);
    // 0x80043E84: addu        $a3, $t7, $zero
    ctx->r7 = ADD32(ctx->r15, 0);
    // 0x80043E88: addiu       $t4, $zero, 0xA
    ctx->r12 = ADD32(0, 0XA);
    // 0x80043E8C: addu        $t3, $s2, $zero
    ctx->r11 = ADD32(ctx->r18, 0);
    // 0x80043E90: addiu       $t2, $zero, 0x6
    ctx->r10 = ADD32(0, 0X6);
    // 0x80043E94: addiu       $t1, $zero, 0x4
    ctx->r9 = ADD32(0, 0X4);
    // 0x80043E98: lw          $v0, 0x4($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X4);
    // 0x80043E9C: addiu       $t0, $zero, 0x5
    ctx->r8 = ADD32(0, 0X5);
    // 0x80043EA0: addu        $t5, $t7, $v0
    ctx->r13 = ADD32(ctx->r15, ctx->r2);
L_80043EA4:
    // 0x80043EA4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80043EA8: addu        $s6, $t1, $zero
    ctx->r22 = ADD32(ctx->r9, 0);
    // 0x80043EAC: addu        $s5, $t2, $zero
    ctx->r21 = ADD32(ctx->r10, 0);
    // 0x80043EB0: addu        $s1, $t3, $zero
    ctx->r17 = ADD32(ctx->r11, 0);
    // 0x80043EB4: addu        $s0, $t4, $zero
    ctx->r16 = ADD32(ctx->r12, 0);
    // 0x80043EB8: addu        $a2, $t0, $a1
    ctx->r6 = ADD32(ctx->r8, ctx->r5);
L_80043EBC:
    // 0x80043EBC: addu        $v1, $t5, $a2
    ctx->r3 = ADD32(ctx->r13, ctx->r6);
    // 0x80043EC0: addu        $v0, $a1, $s6
    ctx->r2 = ADD32(ctx->r5, ctx->r22);
    // 0x80043EC4: addu        $v0, $t5, $v0
    ctx->r2 = ADD32(ctx->r13, ctx->r2);
    // 0x80043EC8: lb          $a0, 0x5($v1)
    ctx->r4 = MEM_B(ctx->r3, 0X5);
    // 0x80043ECC: lb          $v0, 0x5($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X5);
    // 0x80043ED0: subu        $v1, $a0, $v0
    ctx->r3 = SUB32(ctx->r4, ctx->r2);
    // 0x80043ED4: bltz        $v1, L_80043EE4
    if (SIGNED(ctx->r3) < 0) {
        // 0x80043ED8: subu        $v0, $v0, $a0
        ctx->r2 = SUB32(ctx->r2, ctx->r4);
            goto L_80043EE4;
    }
    // 0x80043ED8: subu        $v0, $v0, $a0
    ctx->r2 = SUB32(ctx->r2, ctx->r4);
    // 0x80043EDC: j           L_80043EE8
    // 0x80043EE0: addu        $s2, $s2, $v1
    ctx->r18 = ADD32(ctx->r18, ctx->r3);
        goto L_80043EE8;
    // 0x80043EE0: addu        $s2, $s2, $v1
    ctx->r18 = ADD32(ctx->r18, ctx->r3);
L_80043EE4:
    // 0x80043EE4: addu        $s2, $s2, $v0
    ctx->r18 = ADD32(ctx->r18, ctx->r2);
L_80043EE8:
    // 0x80043EE8: lw          $v0, 0x4($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X4);
    // 0x80043EEC: addu        $v1, $a1, $s5
    ctx->r3 = ADD32(ctx->r5, ctx->r21);
    // 0x80043EF0: addu        $v0, $a3, $v0
    ctx->r2 = ADD32(ctx->r7, ctx->r2);
    // 0x80043EF4: addu        $a0, $v0, $a2
    ctx->r4 = ADD32(ctx->r2, ctx->r6);
    // 0x80043EF8: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80043EFC: lb          $a0, 0x5($a0)
    ctx->r4 = MEM_B(ctx->r4, 0X5);
    // 0x80043F00: lb          $v0, 0x5($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X5);
    // 0x80043F04: subu        $v1, $a0, $v0
    ctx->r3 = SUB32(ctx->r4, ctx->r2);
    // 0x80043F08: bltz        $v1, L_80043F18
    if (SIGNED(ctx->r3) < 0) {
        // 0x80043F0C: subu        $v0, $v0, $a0
        ctx->r2 = SUB32(ctx->r2, ctx->r4);
            goto L_80043F18;
    }
    // 0x80043F0C: subu        $v0, $v0, $a0
    ctx->r2 = SUB32(ctx->r2, ctx->r4);
    // 0x80043F10: j           L_80043F1C
    // 0x80043F14: addu        $s2, $s2, $v1
    ctx->r18 = ADD32(ctx->r18, ctx->r3);
        goto L_80043F1C;
    // 0x80043F14: addu        $s2, $s2, $v1
    ctx->r18 = ADD32(ctx->r18, ctx->r3);
L_80043F18:
    // 0x80043F18: addu        $s2, $s2, $v0
    ctx->r18 = ADD32(ctx->r18, ctx->r2);
L_80043F1C:
    // 0x80043F1C: lw          $v0, 0x4($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X4);
    // 0x80043F20: addu        $v1, $a1, $s1
    ctx->r3 = ADD32(ctx->r5, ctx->r17);
    // 0x80043F24: addu        $v0, $a3, $v0
    ctx->r2 = ADD32(ctx->r7, ctx->r2);
    // 0x80043F28: addu        $a0, $v0, $a2
    ctx->r4 = ADD32(ctx->r2, ctx->r6);
    // 0x80043F2C: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80043F30: lb          $a0, 0x5($a0)
    ctx->r4 = MEM_B(ctx->r4, 0X5);
    // 0x80043F34: lb          $v0, 0x5($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X5);
    // 0x80043F38: subu        $v1, $a0, $v0
    ctx->r3 = SUB32(ctx->r4, ctx->r2);
    // 0x80043F3C: bltz        $v1, L_80043F4C
    if (SIGNED(ctx->r3) < 0) {
        // 0x80043F40: subu        $v0, $v0, $a0
        ctx->r2 = SUB32(ctx->r2, ctx->r4);
            goto L_80043F4C;
    }
    // 0x80043F40: subu        $v0, $v0, $a0
    ctx->r2 = SUB32(ctx->r2, ctx->r4);
    // 0x80043F44: j           L_80043F50
    // 0x80043F48: addu        $s2, $s2, $v1
    ctx->r18 = ADD32(ctx->r18, ctx->r3);
        goto L_80043F50;
    // 0x80043F48: addu        $s2, $s2, $v1
    ctx->r18 = ADD32(ctx->r18, ctx->r3);
L_80043F4C:
    // 0x80043F4C: addu        $s2, $s2, $v0
    ctx->r18 = ADD32(ctx->r18, ctx->r2);
L_80043F50:
    // 0x80043F50: lw          $v0, 0x4($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X4);
    // 0x80043F54: addu        $v1, $a1, $s0
    ctx->r3 = ADD32(ctx->r5, ctx->r16);
    // 0x80043F58: addu        $v0, $a3, $v0
    ctx->r2 = ADD32(ctx->r7, ctx->r2);
    // 0x80043F5C: addu        $a0, $v0, $a2
    ctx->r4 = ADD32(ctx->r2, ctx->r6);
    // 0x80043F60: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80043F64: lb          $a0, 0x5($a0)
    ctx->r4 = MEM_B(ctx->r4, 0X5);
    // 0x80043F68: lb          $v0, 0x5($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X5);
    // 0x80043F6C: subu        $v1, $a0, $v0
    ctx->r3 = SUB32(ctx->r4, ctx->r2);
    // 0x80043F70: bltz        $v1, L_80043F80
    if (SIGNED(ctx->r3) < 0) {
        // 0x80043F74: subu        $v0, $v0, $a0
        ctx->r2 = SUB32(ctx->r2, ctx->r4);
            goto L_80043F80;
    }
    // 0x80043F74: subu        $v0, $v0, $a0
    ctx->r2 = SUB32(ctx->r2, ctx->r4);
    // 0x80043F78: j           L_80043F84
    // 0x80043F7C: addu        $s2, $s2, $v1
    ctx->r18 = ADD32(ctx->r18, ctx->r3);
        goto L_80043F84;
    // 0x80043F7C: addu        $s2, $s2, $v1
    ctx->r18 = ADD32(ctx->r18, ctx->r3);
L_80043F80:
    // 0x80043F80: addu        $s2, $s2, $v0
    ctx->r18 = ADD32(ctx->r18, ctx->r2);
L_80043F84:
    // 0x80043F84: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x80043F88: slti        $v0, $a1, 0x4
    ctx->r2 = SIGNED(ctx->r5) < 0X4 ? 1 : 0;
    // 0x80043F8C: bne         $v0, $zero, L_80043EBC
    if (ctx->r2 != 0) {
        // 0x80043F90: addiu       $a2, $a2, 0x1
        ctx->r6 = ADD32(ctx->r6, 0X1);
            goto L_80043EBC;
    }
    // 0x80043F90: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x80043F94: addiu       $t4, $t4, 0x5
    ctx->r12 = ADD32(ctx->r12, 0X5);
    // 0x80043F98: addiu       $t3, $t3, 0x5
    ctx->r11 = ADD32(ctx->r11, 0X5);
    // 0x80043F9C: addiu       $t2, $t2, 0x5
    ctx->r10 = ADD32(ctx->r10, 0X5);
    // 0x80043FA0: addiu       $t1, $t1, 0x5
    ctx->r9 = ADD32(ctx->r9, 0X5);
    // 0x80043FA4: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    // 0x80043FA8: slti        $v0, $s4, 0x4
    ctx->r2 = SIGNED(ctx->r20) < 0X4 ? 1 : 0;
    // 0x80043FAC: bne         $v0, $zero, L_80043EA4
    if (ctx->r2 != 0) {
        // 0x80043FB0: addiu       $t0, $t0, 0x5
        ctx->r8 = ADD32(ctx->r8, 0X5);
            goto L_80043EA4;
    }
    // 0x80043FB0: addiu       $t0, $t0, 0x5
    ctx->r8 = ADD32(ctx->r8, 0X5);
    // 0x80043FB4: slti        $v0, $s2, 0x14
    ctx->r2 = SIGNED(ctx->r18) < 0X14 ? 1 : 0;
    // 0x80043FB8: beq         $v0, $zero, L_80043FD4
    if (ctx->r2 == 0) {
        // 0x80043FBC: addiu       $s3, $s3, 0x1
        ctx->r19 = ADD32(ctx->r19, 0X1);
            goto L_80043FD4;
    }
    // 0x80043FBC: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x80043FC0: lw          $v1, 0x4($t6)
    ctx->r3 = MEM_W(ctx->r14, 0X4);
    // 0x80043FC4: addu        $v1, $t7, $v1
    ctx->r3 = ADD32(ctx->r15, ctx->r3);
    // 0x80043FC8: lbu         $v0, 0x2($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X2);
    // 0x80043FCC: ori         $v0, $v0, 0x1
    ctx->r2 = ctx->r2 | 0X1;
    // 0x80043FD0: sb          $v0, 0x2($v1)
    MEM_B(0X2, ctx->r3) = ctx->r2;
L_80043FD4:
    // 0x80043FD4: slt         $v0, $s3, $s7
    ctx->r2 = SIGNED(ctx->r19) < SIGNED(ctx->r23) ? 1 : 0;
    // 0x80043FD8: bne         $v0, $zero, L_80043E7C
    if (ctx->r2 != 0) {
        // 0x80043FDC: addiu       $t7, $t7, 0x1E
        ctx->r15 = ADD32(ctx->r15, 0X1E);
            goto L_80043E7C;
    }
    // 0x80043FDC: addiu       $t7, $t7, 0x1E
    ctx->r15 = ADD32(ctx->r15, 0X1E);
L_80043FE0:
    // 0x80043FE0: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80043FE4: lw          $v1, 0x6FC4($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X6FC4);
    // 0x80043FE8: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80043FEC: lwc1        $f6, 0x0($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X0);
    // 0x80043FF0: addiu       $s0, $v0, 0x6DC0
    ctx->r16 = ADD32(ctx->r2, 0X6DC0);
    // 0x80043FF4: swc1        $f6, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->f6.u32l;
    // 0x80043FF8: lhu         $v0, 0x24($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X24);
    // 0x80043FFC: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x80044000: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x80044004: add.s       $f0, $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f0.fl;
    // 0x80044008: add.s       $f0, $f6, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f6.fl + ctx->f0.fl;
    // 0x8004400C: swc1        $f0, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f0.u32l;
    // 0x80044010: lwc1        $f4, 0x8($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X8);
    // 0x80044014: swc1        $f4, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f4.u32l;
    // 0x80044018: lhu         $v0, 0x26($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X26);
    // 0x8004401C: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x80044020: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x80044024: add.s       $f0, $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f0.fl;
    // 0x80044028: add.s       $f0, $f4, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f4.fl + ctx->f0.fl;
    // 0x8004402C: swc1        $f0, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->f0.u32l;
    // 0x80044030: lhu         $v0, 0x24($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X24);
    // 0x80044034: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x80044038: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x8004403C: add.s       $f0, $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f0.fl;
    // 0x80044040: swc1        $f0, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->f0.u32l;
    // 0x80044044: lhu         $v0, 0x26($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X26);
    // 0x80044048: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x8004404C: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x80044050: add.s       $f0, $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f0.fl;
    // 0x80044054: swc1        $f0, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->f0.u32l;
    // 0x80044058: lhu         $v0, 0x24($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X24);
    // 0x8004405C: sh          $v0, 0x38($s0)
    MEM_H(0X38, ctx->r16) = ctx->r2;
    // 0x80044060: lhu         $v0, 0x26($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X26);
    // 0x80044064: lhu         $a0, 0x38($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X38);
    // 0x80044068: sh          $v0, 0x3A($s0)
    MEM_H(0X3A, ctx->r16) = ctx->r2;
    // 0x8004406C: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x80044070: mult        $a0, $v0
    result = S64(S32(ctx->r4)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80044074: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80044078: lwc1        $f0, -0x5AAC($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X5AAC);
    // 0x8004407C: lwc1        $f2, 0x10($v1)
    ctx->f2.u32l = MEM_W(ctx->r3, 0X10);
    // 0x80044080: mul.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x80044084: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x80044088: swc1        $f6, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f6.u32l;
    // 0x8004408C: mflo        $t8
    ctx->r24 = lo;
    // 0x80044090: swc1        $f2, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f2.u32l;
    // 0x80044094: lwc1        $f0, 0x4($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X4);
    // 0x80044098: sll         $a0, $t8, 1
    ctx->r4 = S32(ctx->r24 << 1);
    // 0x8004409C: swc1        $f4, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f4.u32l;
    // 0x800440A0: jal         0x80001ACC
    // 0x800440A4: swc1        $f0, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f0.u32l;
    rs_malloc(rdram, ctx);
        goto after_6;
    // 0x800440A4: swc1        $f0, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f0.u32l;
    after_6:
    // 0x800440A8: lhu         $a0, 0x38($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X38);
    // 0x800440AC: lhu         $v1, 0x3A($s0)
    ctx->r3 = MEM_HU(ctx->r16, 0X3A);
    // 0x800440B0: mult        $a0, $v1
    result = S64(S32(ctx->r4)) * S64(S32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800440B4: addu        $s3, $zero, $zero
    ctx->r19 = ADD32(0, 0);
    // 0x800440B8: mflo        $t8
    ctx->r24 = lo;
    // 0x800440BC: blez        $t8, L_800440FC
    if (SIGNED(ctx->r24) <= 0) {
        // 0x800440C0: sw          $v0, 0x8($s0)
        MEM_W(0X8, ctx->r16) = ctx->r2;
            goto L_800440FC;
    }
    // 0x800440C0: sw          $v0, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r2;
    // 0x800440C4: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x800440C8: ori         $a1, $zero, 0xFFFF
    ctx->r5 = 0 | 0XFFFF;
L_800440CC:
    // 0x800440CC: lw          $v1, 0x8($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X8);
    // 0x800440D0: sll         $v0, $s3, 1
    ctx->r2 = S32(ctx->r19 << 1);
    // 0x800440D4: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800440D8: sh          $a1, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r5;
    // 0x800440DC: lhu         $v1, 0x38($a0)
    ctx->r3 = MEM_HU(ctx->r4, 0X38);
    // 0x800440E0: lhu         $v0, 0x3A($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X3A);
    // 0x800440E4: mult        $v1, $v0
    result = S64(S32(ctx->r3)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800440E8: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x800440EC: mflo        $t8
    ctx->r24 = lo;
    // 0x800440F0: slt         $v0, $s3, $t8
    ctx->r2 = SIGNED(ctx->r19) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x800440F4: bne         $v0, $zero, L_800440CC
    if (ctx->r2 != 0) {
        // 0x800440F8: nop
    
            goto L_800440CC;
    }
    // 0x800440F8: nop

L_800440FC:
    // 0x800440FC: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x80044100: addiu       $a0, $a1, 0x6DC0
    ctx->r4 = ADD32(ctx->r5, 0X6DC0);
    // 0x80044104: lhu         $v1, 0x38($a0)
    ctx->r3 = MEM_HU(ctx->r4, 0X38);
    // 0x80044108: lhu         $v0, 0x3A($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X3A);
    // 0x8004410C: mult        $v1, $v0
    result = S64(S32(ctx->r3)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80044110: mflo        $t8
    ctx->r24 = lo;
    // 0x80044114: blez        $t8, L_80044180
    if (SIGNED(ctx->r24) <= 0) {
        // 0x80044118: addu        $s3, $zero, $zero
        ctx->r19 = ADD32(0, 0);
            goto L_80044180;
    }
    // 0x80044118: addu        $s3, $zero, $zero
    ctx->r19 = ADD32(0, 0);
    // 0x8004411C: addu        $a3, $a1, $zero
    ctx->r7 = ADD32(ctx->r5, 0);
    // 0x80044120: addu        $a2, $a0, $zero
    ctx->r6 = ADD32(ctx->r4, 0);
L_80044124:
    // 0x80044124: lw          $v1, 0x6DC0($a3)
    ctx->r3 = MEM_W(ctx->r7, 0X6DC0);
    // 0x80044128: sll         $v0, $s3, 1
    ctx->r2 = S32(ctx->r19 << 1);
    // 0x8004412C: addu        $a1, $v0, $v1
    ctx->r5 = ADD32(ctx->r2, ctx->r3);
    // 0x80044130: lhu         $a0, 0x0($a1)
    ctx->r4 = MEM_HU(ctx->r5, 0X0);
    // 0x80044134: andi        $v1, $a0, 0x1FFF
    ctx->r3 = ctx->r4 & 0X1FFF;
    // 0x80044138: sll         $v0, $v1, 4
    ctx->r2 = S32(ctx->r3 << 4);
    // 0x8004413C: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x80044140: lw          $v1, 0x4($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X4);
    // 0x80044144: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x80044148: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8004414C: lbu         $v0, 0x2($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X2);
    // 0x80044150: andi        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 & 0X1;
    // 0x80044154: beq         $v0, $zero, L_80044160
    if (ctx->r2 == 0) {
        // 0x80044158: ori         $v0, $a0, 0x8000
        ctx->r2 = ctx->r4 | 0X8000;
            goto L_80044160;
    }
    // 0x80044158: ori         $v0, $a0, 0x8000
    ctx->r2 = ctx->r4 | 0X8000;
    // 0x8004415C: sh          $v0, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r2;
L_80044160:
    // 0x80044160: lhu         $v1, 0x38($a2)
    ctx->r3 = MEM_HU(ctx->r6, 0X38);
    // 0x80044164: lhu         $v0, 0x3A($a2)
    ctx->r2 = MEM_HU(ctx->r6, 0X3A);
    // 0x80044168: mult        $v1, $v0
    result = S64(S32(ctx->r3)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8004416C: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x80044170: mflo        $t8
    ctx->r24 = lo;
    // 0x80044174: slt         $v0, $s3, $t8
    ctx->r2 = SIGNED(ctx->r19) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x80044178: bne         $v0, $zero, L_80044124
    if (ctx->r2 != 0) {
        // 0x8004417C: nop
    
            goto L_80044124;
    }
    // 0x8004417C: nop

L_80044180:
    // 0x80044180: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    // 0x80044184: lui         $a1, 0x8004
    ctx->r5 = S32(0X8004 << 16);
    // 0x80044188: addiu       $a1, $a1, -0x5AB4
    ctx->r5 = ADD32(ctx->r5, -0X5AB4);
    // 0x8004418C: jal         0x80033CC4
    // 0x80044190: addu        $a2, $fp, $zero
    ctx->r6 = ADD32(ctx->r30, 0);
    sprintf_recomp(rdram, ctx);
        goto after_7;
    // 0x80044190: addu        $a2, $fp, $zero
    ctx->r6 = ADD32(ctx->r30, 0);
    after_7:
    // 0x80044194: lui         $s1, 0x8013
    ctx->r17 = S32(0X8013 << 16);
    // 0x80044198: lw          $a0, 0x7CFC($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X7CFC);
    // 0x8004419C: jal         0x80004D5C
    // 0x800441A0: addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    get_asset_size_extra(rdram, ctx);
        goto after_8;
    // 0x800441A0: addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    after_8:
    // 0x800441A4: addu        $s2, $v0, $zero
    ctx->r18 = ADD32(ctx->r2, 0);
    // 0x800441A8: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // 0x800441AC: jal         0x80001ACC
    // 0x800441B0: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    rs_malloc(rdram, ctx);
        goto after_9;
    // 0x800441B0: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    after_9:
    // 0x800441B4: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x800441B8: addiu       $a3, $sp, 0x18
    ctx->r7 = ADD32(ctx->r29, 0X18);
    // 0x800441BC: lui         $s0, 0x8014
    ctx->r16 = S32(0X8014 << 16);
    // 0x800441C0: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x800441C4: lw          $a0, -0x76E0($s0)
    ctx->r4 = MEM_W(ctx->r16, -0X76E0);
    // 0x800441C8: lw          $a2, 0x7CFC($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X7CFC);
    // 0x800441CC: addiu       $s1, $v1, 0x6DC0
    ctx->r17 = ADD32(ctx->r3, 0X6DC0);
    // 0x800441D0: sw          $v0, 0xC($s1)
    MEM_W(0XC, ctx->r17) = ctx->r2;
    // 0x800441D4: jal         0x80004AAC
    // 0x800441D8: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    func_80004AAC(rdram, ctx);
        goto after_10;
    // 0x800441D8: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_10:
    // 0x800441DC: addu        $s3, $v0, $zero
    ctx->r19 = ADD32(ctx->r2, 0);
    // 0x800441E0: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x800441E4: addu        $a2, $s3, $zero
    ctx->r6 = ADD32(ctx->r19, 0);
    // 0x800441E8: lw          $a0, -0x76E0($s0)
    ctx->r4 = MEM_W(ctx->r16, -0X76E0);
    // 0x800441EC: lw          $v0, 0xC($s1)
    ctx->r2 = MEM_W(ctx->r17, 0XC);
    // 0x800441F0: addu        $a3, $a1, $zero
    ctx->r7 = ADD32(ctx->r5, 0);
    // 0x800441F4: sw          $s2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r18;
    // 0x800441F8: jal         0x80004E70
    // 0x800441FC: sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    func_80004E70(rdram, ctx);
        goto after_11;
    // 0x800441FC: sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    after_11:
    // 0x80044200: lw          $a0, -0x76E0($s0)
    ctx->r4 = MEM_W(ctx->r16, -0X76E0);
    // 0x80044204: jal         0x80004C70
    // 0x80044208: addu        $a1, $s3, $zero
    ctx->r5 = ADD32(ctx->r19, 0);
    func_80004C70(rdram, ctx);
        goto after_12;
    // 0x80044208: addu        $a1, $s3, $zero
    ctx->r5 = ADD32(ctx->r19, 0);
    after_12:
    // 0x8004420C: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80044210: lw          $v1, 0x6FC4($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X6FC4);
    // 0x80044214: lhu         $v0, 0x1A($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X1A);
    // 0x80044218: beq         $v0, $zero, L_80044254
    if (ctx->r2 == 0) {
        // 0x8004421C: addu        $s3, $zero, $zero
        ctx->r19 = ADD32(0, 0);
            goto L_80044254;
    }
    // 0x8004421C: addu        $s3, $zero, $zero
    ctx->r19 = ADD32(0, 0);
    // 0x80044220: addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    // 0x80044224: ori         $a1, $zero, 0xFFFF
    ctx->r5 = 0 | 0XFFFF;
    // 0x80044228: addu        $a0, $v1, $zero
    ctx->r4 = ADD32(ctx->r3, 0);
    // 0x8004422C: sll         $v0, $s3, 2
    ctx->r2 = S32(ctx->r19 << 2);
L_80044230:
    // 0x80044230: lw          $v1, 0xC($a2)
    ctx->r3 = MEM_W(ctx->r6, 0XC);
    // 0x80044234: ori         $v0, $v0, 0x2
    ctx->r2 = ctx->r2 | 0X2;
    // 0x80044238: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8004423C: sh          $a1, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r5;
    // 0x80044240: lhu         $v0, 0x1A($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X1A);
    // 0x80044244: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x80044248: slt         $v0, $s3, $v0
    ctx->r2 = SIGNED(ctx->r19) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8004424C: bne         $v0, $zero, L_80044230
    if (ctx->r2 != 0) {
        // 0x80044250: sll         $v0, $s3, 2
        ctx->r2 = S32(ctx->r19 << 2);
            goto L_80044230;
    }
    // 0x80044250: sll         $v0, $s3, 2
    ctx->r2 = S32(ctx->r19 << 2);
L_80044254:
    // 0x80044254: addu        $s5, $zero, $zero
    ctx->r21 = ADD32(0, 0);
    // 0x80044258: addu        $s4, $s5, $zero
    ctx->r20 = ADD32(ctx->r21, 0);
    // 0x8004425C: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80044260: lw          $v1, 0x6FC4($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X6FC4);
    // 0x80044264: sw          $zero, 0x50($sp)
    MEM_W(0X50, ctx->r29) = 0;
    // 0x80044268: lhu         $a0, 0x1A($v1)
    ctx->r4 = MEM_HU(ctx->r3, 0X1A);
    // 0x8004426C: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80044270: lwc1        $f20, -0x5AA8($at)
    ctx->f20.u32l = MEM_W(ctx->r1, -0X5AA8);
    // 0x80044274: jal         0x80046310
    // 0x80044278: addu        $fp, $v0, $zero
    ctx->r30 = ADD32(ctx->r2, 0);
    func_80046310(rdram, ctx);
        goto after_13;
    // 0x80044278: addu        $fp, $v0, $zero
    ctx->r30 = ADD32(ctx->r2, 0);
    after_13:
L_8004427C:
    // 0x8004427C: lw          $v0, 0x6FC4($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X6FC4);
    // 0x80044280: lw          $v0, 0x20($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X20);
    // 0x80044284: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x80044288: blez        $v0, L_80044534
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8004428C: addu        $s3, $zero, $zero
        ctx->r19 = ADD32(0, 0);
            goto L_80044534;
    }
    // 0x8004428C: addu        $s3, $zero, $zero
    ctx->r19 = ADD32(0, 0);
    // 0x80044290: addiu       $s2, $zero, 0xC
    ctx->r18 = ADD32(0, 0XC);
    // 0x80044294: addu        $s0, $s3, $zero
    ctx->r16 = ADD32(ctx->r19, 0);
    // 0x80044298: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8004429C: addiu       $v0, $v0, 0x6DC0
    ctx->r2 = ADD32(ctx->r2, 0X6DC0);
    // 0x800442A0: sll         $v1, $s4, 2
    ctx->r3 = S32(ctx->r20 << 2);
    // 0x800442A4: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x800442A8: sw          $v1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r3;
    // 0x800442AC: sll         $v0, $s4, 1
    ctx->r2 = S32(ctx->r20 << 1);
    // 0x800442B0: addu        $v0, $v0, $s4
    ctx->r2 = ADD32(ctx->r2, ctx->r20);
    // 0x800442B4: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800442B8: subu        $v0, $v0, $s4
    ctx->r2 = SUB32(ctx->r2, ctx->r20);
    // 0x800442BC: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x800442C0: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x800442C4: addiu       $t8, $t8, 0x6E20
    ctx->r24 = ADD32(ctx->r24, 0X6E20);
    // 0x800442C8: addu        $s1, $v0, $t8
    ctx->r17 = ADD32(ctx->r2, ctx->r24);
    // 0x800442CC: addu        $s6, $v0, $zero
    ctx->r22 = ADD32(ctx->r2, 0);
    // 0x800442D0: addiu       $s7, $s6, -0x58
    ctx->r23 = ADD32(ctx->r22, -0X58);
L_800442D4:
    // 0x800442D4: lw          $a2, 0x6FC4($fp)
    ctx->r6 = MEM_W(ctx->r30, 0X6FC4);
    // 0x800442D8: lw          $a0, 0x20($a2)
    ctx->r4 = MEM_W(ctx->r6, 0X20);
    // 0x800442DC: addu        $v1, $a0, $s0
    ctx->r3 = ADD32(ctx->r4, ctx->r16);
    // 0x800442E0: lbu         $a1, 0x18($v1)
    ctx->r5 = MEM_BU(ctx->r3, 0X18);
    // 0x800442E4: bne         $a1, $zero, L_80044484
    if (ctx->r5 != 0) {
        // 0x800442E8: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80044484;
    }
    // 0x800442E8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800442EC: lbu         $v0, 0x1B($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X1B);
    // 0x800442F0: beq         $v0, $zero, L_8004430C
    if (ctx->r2 == 0) {
        // 0x800442F4: nop
    
            goto L_8004430C;
    }
    // 0x800442F4: nop

    // 0x800442F8: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x800442FC: addiu       $t8, $t8, 0xB40
    ctx->r24 = ADD32(ctx->r24, 0XB40);
    // 0x80044300: lbu         $v0, 0x23($t8)
    ctx->r2 = MEM_BU(ctx->r24, 0X23);
    // 0x80044304: beq         $v0, $zero, L_80044514
    if (ctx->r2 == 0) {
        // 0x80044308: lui         $v0, 0x8013
        ctx->r2 = S32(0X8013 << 16);
            goto L_80044514;
    }
    // 0x80044308: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
L_8004430C:
    // 0x8004430C: bgtz        $s4, L_80044514
    if (SIGNED(ctx->r20) > 0) {
        // 0x80044310: lui         $v0, 0x8013
        ctx->r2 = S32(0X8013 << 16);
            goto L_80044514;
    }
    // 0x80044310: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80044314: bne         $s5, $zero, L_80044514
    if (ctx->r21 != 0) {
        // 0x80044318: nop
    
            goto L_80044514;
    }
    // 0x80044318: nop

    // 0x8004431C: addu        $a0, $a0, $s2
    ctx->r4 = ADD32(ctx->r4, ctx->r18);
    // 0x80044320: jal         0x8001CF58
    // 0x80044324: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    normalize_vector(rdram, ctx);
        goto after_14;
    // 0x80044324: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    after_14:
    // 0x80044328: lw          $a0, 0x6FC4($fp)
    ctx->r4 = MEM_W(ctx->r30, 0X6FC4);
    // 0x8004432C: lw          $v0, 0x20($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X20);
    // 0x80044330: addu        $v1, $v0, $s0
    ctx->r3 = ADD32(ctx->r2, ctx->r16);
    // 0x80044334: lbu         $v0, 0x19($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X19);
    // 0x80044338: beq         $v0, $zero, L_80044374
    if (ctx->r2 == 0) {
        // 0x8004433C: nop
    
            goto L_80044374;
    }
    // 0x8004433C: nop

    // 0x80044340: lwc1        $f0, 0xC($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0XC);
    // 0x80044344: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
    // 0x80044348: swc1        $f0, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->f0.u32l;
    // 0x8004434C: lw          $v0, 0x20($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X20);
    // 0x80044350: addu        $v0, $v0, $s0
    ctx->r2 = ADD32(ctx->r2, ctx->r16);
    // 0x80044354: lwc1        $f0, 0x10($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X10);
    // 0x80044358: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
    // 0x8004435C: swc1        $f0, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->f0.u32l;
    // 0x80044360: lw          $v0, 0x20($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X20);
    // 0x80044364: addu        $v0, $v0, $s0
    ctx->r2 = ADD32(ctx->r2, ctx->r16);
    // 0x80044368: lwc1        $f0, 0x14($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X14);
    // 0x8004436C: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
    // 0x80044370: swc1        $f0, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->f0.u32l;
L_80044374:
    // 0x80044374: lw          $t8, 0x88($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X88);
    // 0x80044378: bnel        $t8, $zero, L_80044458
    if (ctx->r24 != 0) {
        // 0x8004437C: addiu       $s1, $s1, 0x58
        ctx->r17 = ADD32(ctx->r17, 0X58);
            goto L_80044458;
    }
    goto skip_0;
    // 0x8004437C: addiu       $s1, $s1, 0x58
    ctx->r17 = ADD32(ctx->r17, 0X58);
    skip_0:
    // 0x80044380: bne         $s4, $zero, L_80044398
    if (ctx->r20 != 0) {
        // 0x80044384: sw          $zero, 0x0($s1)
        MEM_W(0X0, ctx->r17) = 0;
            goto L_80044398;
    }
    // 0x80044384: sw          $zero, 0x0($s1)
    MEM_W(0X0, ctx->r17) = 0;
    // 0x80044388: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x8004438C: addiu       $t8, $t8, 0x6E20
    ctx->r24 = ADD32(ctx->r24, 0X6E20);
    // 0x80044390: j           L_800443BC
    // 0x80044394: sw          $zero, 0x4($t8)
    MEM_W(0X4, ctx->r24) = 0;
        goto L_800443BC;
    // 0x80044394: sw          $zero, 0x4($t8)
    MEM_W(0X4, ctx->r24) = 0;
L_80044398:
    // 0x80044398: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x8004439C: addiu       $t8, $t8, 0x6E20
    ctx->r24 = ADD32(ctx->r24, 0X6E20);
    // 0x800443A0: addiu       $v0, $t8, -0x58
    ctx->r2 = ADD32(ctx->r24, -0X58);
    // 0x800443A4: addu        $v0, $s6, $v0
    ctx->r2 = ADD32(ctx->r22, ctx->r2);
    // 0x800443A8: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x800443AC: addiu       $t8, $t8, 0x6E20
    ctx->r24 = ADD32(ctx->r24, 0X6E20);
    // 0x800443B0: sw          $v0, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->r2;
    // 0x800443B4: addu        $v0, $s7, $t8
    ctx->r2 = ADD32(ctx->r23, ctx->r24);
    // 0x800443B8: sw          $s1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r17;
L_800443BC:
    // 0x800443BC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800443C0: sb          $v0, 0x8($s1)
    MEM_B(0X8, ctx->r17) = ctx->r2;
    // 0x800443C4: lw          $v1, 0x6FC4($fp)
    ctx->r3 = MEM_W(ctx->r30, 0X6FC4);
    // 0x800443C8: lw          $v0, 0x20($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X20);
    // 0x800443CC: addu        $v0, $v0, $s0
    ctx->r2 = ADD32(ctx->r2, ctx->r16);
    // 0x800443D0: lwc1        $f0, 0x1C($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X1C);
    // 0x800443D4: swc1        $f0, 0x18($s1)
    MEM_W(0X18, ctx->r17) = ctx->f0.u32l;
    // 0x800443D8: lw          $v0, 0x20($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X20);
    // 0x800443DC: addu        $v0, $v0, $s0
    ctx->r2 = ADD32(ctx->r2, ctx->r16);
    // 0x800443E0: lwc1        $f0, 0x20($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X20);
    // 0x800443E4: swc1        $f0, 0x1C($s1)
    MEM_W(0X1C, ctx->r17) = ctx->f0.u32l;
    // 0x800443E8: lw          $v0, 0x20($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X20);
    // 0x800443EC: addu        $v0, $v0, $s0
    ctx->r2 = ADD32(ctx->r2, ctx->r16);
    // 0x800443F0: lwc1        $f0, 0x24($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X24);
    // 0x800443F4: swc1        $f0, 0x20($s1)
    MEM_W(0X20, ctx->r17) = ctx->f0.u32l;
    // 0x800443F8: lw          $v0, 0x20($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X20);
    // 0x800443FC: addu        $v0, $v0, $s0
    ctx->r2 = ADD32(ctx->r2, ctx->r16);
    // 0x80044400: lwc1        $f0, 0xC($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0XC);
    // 0x80044404: div.s       $f0, $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f20.fl);
    // 0x80044408: swc1        $f0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f0.u32l;
    // 0x8004440C: lw          $v0, 0x20($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X20);
    // 0x80044410: addu        $v0, $v0, $s0
    ctx->r2 = ADD32(ctx->r2, ctx->r16);
    // 0x80044414: lwc1        $f0, 0x10($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X10);
    // 0x80044418: div.s       $f0, $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f20.fl);
    // 0x8004441C: swc1        $f0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f0.u32l;
    // 0x80044420: lw          $v0, 0x20($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X20);
    // 0x80044424: addu        $v0, $v0, $s0
    ctx->r2 = ADD32(ctx->r2, ctx->r16);
    // 0x80044428: lwc1        $f0, 0x14($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X14);
    // 0x8004442C: addiu       $a0, $sp, 0x40
    ctx->r4 = ADD32(ctx->r29, 0X40);
    // 0x80044430: div.s       $f0, $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f20.fl);
    // 0x80044434: jal         0x8001CF58
    // 0x80044438: swc1        $f0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f0.u32l;
    normalize_vector(rdram, ctx);
        goto after_15;
    // 0x80044438: swc1        $f0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f0.u32l;
    after_15:
    // 0x8004443C: lwc1        $f0, 0x40($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X40);
    // 0x80044440: swc1        $f0, 0x24($s1)
    MEM_W(0X24, ctx->r17) = ctx->f0.u32l;
    // 0x80044444: lwc1        $f0, 0x44($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X44);
    // 0x80044448: swc1        $f0, 0x28($s1)
    MEM_W(0X28, ctx->r17) = ctx->f0.u32l;
    // 0x8004444C: lwc1        $f0, 0x48($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X48);
    // 0x80044450: swc1        $f0, 0x2C($s1)
    MEM_W(0X2C, ctx->r17) = ctx->f0.u32l;
    // 0x80044454: addiu       $s1, $s1, 0x58
    ctx->r17 = ADD32(ctx->r17, 0X58);
L_80044458:
    // 0x80044458: addiu       $s6, $s6, 0x58
    ctx->r22 = ADD32(ctx->r22, 0X58);
    // 0x8004445C: addiu       $s7, $s7, 0x58
    ctx->r23 = ADD32(ctx->r23, 0X58);
    // 0x80044460: lw          $v0, 0x6FC4($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X6FC4);
    // 0x80044464: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    // 0x80044468: lw          $v0, 0x20($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X20);
    // 0x8004446C: lw          $t8, 0x54($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X54);
    // 0x80044470: addu        $v0, $v0, $s2
    ctx->r2 = ADD32(ctx->r2, ctx->r18);
    // 0x80044474: sw          $v0, 0x48($t8)
    MEM_W(0X48, ctx->r24) = ctx->r2;
    // 0x80044478: addiu       $t8, $t8, 0x4
    ctx->r24 = ADD32(ctx->r24, 0X4);
    // 0x8004447C: j           L_80044510
    // 0x80044480: sw          $t8, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r24;
        goto L_80044510;
    // 0x80044480: sw          $t8, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r24;
L_80044484:
    // 0x80044484: bne         $a1, $v0, L_80044514
    if (ctx->r5 != ctx->r2) {
        // 0x80044488: lui         $v0, 0x8013
        ctx->r2 = S32(0X8013 << 16);
            goto L_80044514;
    }
    // 0x80044488: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8004448C: lbu         $v0, 0x19($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X19);
    // 0x80044490: beq         $v0, $zero, L_800444D4
    if (ctx->r2 == 0) {
        // 0x80044494: nop
    
            goto L_800444D4;
    }
    // 0x80044494: nop

    // 0x80044498: bne         $s5, $a1, L_800444D4
    if (ctx->r21 != ctx->r5) {
        // 0x8004449C: nop
    
            goto L_800444D4;
    }
    // 0x8004449C: nop

    // 0x800444A0: lwc1        $f0, 0xC($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0XC);
    // 0x800444A4: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
    // 0x800444A8: swc1        $f0, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->f0.u32l;
    // 0x800444AC: lw          $v0, 0x20($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X20);
    // 0x800444B0: addu        $v0, $v0, $s0
    ctx->r2 = ADD32(ctx->r2, ctx->r16);
    // 0x800444B4: lwc1        $f0, 0x10($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X10);
    // 0x800444B8: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
    // 0x800444BC: swc1        $f0, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->f0.u32l;
    // 0x800444C0: lw          $v0, 0x20($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X20);
    // 0x800444C4: addu        $v0, $v0, $s0
    ctx->r2 = ADD32(ctx->r2, ctx->r16);
    // 0x800444C8: lwc1        $f0, 0x14($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X14);
    // 0x800444CC: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
    // 0x800444D0: swc1        $f0, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->f0.u32l;
L_800444D4:
    // 0x800444D4: bne         $s5, $zero, L_80044500
    if (ctx->r21 != 0) {
        // 0x800444D8: addiu       $a1, $zero, 0x1
        ctx->r5 = ADD32(0, 0X1);
            goto L_80044500;
    }
    // 0x800444D8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x800444DC: lw          $v0, 0x6FC4($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X6FC4);
    // 0x800444E0: lw          $a0, 0x20($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X20);
    // 0x800444E4: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x800444E8: jal         0x8004B1E4
    // 0x800444EC: addu        $a0, $a0, $s2
    ctx->r4 = ADD32(ctx->r4, ctx->r18);
    func_8004B1E4(rdram, ctx);
        goto after_16;
    // 0x800444EC: addu        $a0, $a0, $s2
    ctx->r4 = ADD32(ctx->r4, ctx->r18);
    after_16:
    // 0x800444F0: lw          $t8, 0x50($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X50);
    // 0x800444F4: addu        $t8, $t8, $v0
    ctx->r24 = ADD32(ctx->r24, ctx->r2);
    // 0x800444F8: j           L_80044510
    // 0x800444FC: sw          $t8, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r24;
        goto L_80044510;
    // 0x800444FC: sw          $t8, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r24;
L_80044500:
    // 0x80044500: lw          $v0, 0x6FC4($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X6FC4);
    // 0x80044504: lw          $a0, 0x20($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X20);
    // 0x80044508: jal         0x8004B1E4
    // 0x8004450C: addu        $a0, $a0, $s2
    ctx->r4 = ADD32(ctx->r4, ctx->r18);
    func_8004B1E4(rdram, ctx);
        goto after_17;
    // 0x8004450C: addu        $a0, $a0, $s2
    ctx->r4 = ADD32(ctx->r4, ctx->r18);
    after_17:
L_80044510:
    // 0x80044510: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
L_80044514:
    // 0x80044514: lw          $v0, 0x6FC4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X6FC4);
    // 0x80044518: addiu       $s2, $s2, 0x20
    ctx->r18 = ADD32(ctx->r18, 0X20);
    // 0x8004451C: lw          $v0, 0x20($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X20);
    // 0x80044520: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x80044524: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x80044528: slt         $v0, $s3, $v0
    ctx->r2 = SIGNED(ctx->r19) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8004452C: bne         $v0, $zero, L_800442D4
    if (ctx->r2 != 0) {
        // 0x80044530: addiu       $s0, $s0, 0x20
        ctx->r16 = ADD32(ctx->r16, 0X20);
            goto L_800442D4;
    }
    // 0x80044530: addiu       $s0, $s0, 0x20
    ctx->r16 = ADD32(ctx->r16, 0X20);
L_80044534:
    // 0x80044534: bnel        $s5, $zero, L_8004456C
    if (ctx->r21 != 0) {
        // 0x80044538: addiu       $s5, $s5, 0x1
        ctx->r21 = ADD32(ctx->r21, 0X1);
            goto L_8004456C;
    }
    goto skip_1;
    // 0x80044538: addiu       $s5, $s5, 0x1
    ctx->r21 = ADD32(ctx->r21, 0X1);
    skip_1:
    // 0x8004453C: jal         0x8006B694
    // 0x80044540: nop

    func_8006B694(rdram, ctx);
        goto after_18;
    // 0x80044540: nop

    after_18:
    // 0x80044544: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x80044548: lhu         $a0, 0xC4C($v1)
    ctx->r4 = MEM_HU(ctx->r3, 0XC4C);
    // 0x8004454C: lw          $t8, 0x50($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X50);
    // 0x80044550: addu        $a0, $t8, $a0
    ctx->r4 = ADD32(ctx->r24, ctx->r4);
    // 0x80044554: jal         0x80041EF0
    // 0x80044558: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    func_80041EF0(rdram, ctx);
        goto after_19;
    // 0x80044558: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    after_19:
    // 0x8004455C: lw          $t8, 0x50($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X50);
    // 0x80044560: beq         $t8, $zero, L_80044578
    if (ctx->r24 == 0) {
        // 0x80044564: slti        $a1, $s4, 0x4
        ctx->r5 = SIGNED(ctx->r20) < 0X4 ? 1 : 0;
            goto L_80044578;
    }
    // 0x80044564: slti        $a1, $s4, 0x4
    ctx->r5 = SIGNED(ctx->r20) < 0X4 ? 1 : 0;
    // 0x80044568: addiu       $s5, $s5, 0x1
    ctx->r21 = ADD32(ctx->r21, 0X1);
L_8004456C:
    // 0x8004456C: slti        $v0, $s5, 0x2
    ctx->r2 = SIGNED(ctx->r21) < 0X2 ? 1 : 0;
    // 0x80044570: bne         $v0, $zero, L_8004427C
    if (ctx->r2 != 0) {
        // 0x80044574: slti        $a1, $s4, 0x4
        ctx->r5 = SIGNED(ctx->r20) < 0X4 ? 1 : 0;
            goto L_8004427C;
    }
    // 0x80044574: slti        $a1, $s4, 0x4
    ctx->r5 = SIGNED(ctx->r20) < 0X4 ? 1 : 0;
L_80044578:
    // 0x80044578: beq         $a1, $zero, L_80044590
    if (ctx->r5 == 0) {
        // 0x8004457C: lui         $v1, 0x8013
        ctx->r3 = S32(0X8013 << 16);
            goto L_80044590;
    }
    // 0x8004457C: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x80044580: addiu       $v1, $v1, 0x6DC0
    ctx->r3 = ADD32(ctx->r3, 0X6DC0);
    // 0x80044584: sll         $v0, $s4, 2
    ctx->r2 = S32(ctx->r20 << 2);
    // 0x80044588: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8004458C: sw          $zero, 0x48($v0)
    MEM_W(0X48, ctx->r2) = 0;
L_80044590:
    // 0x80044590: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80044594: lw          $a0, 0x6FC4($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X6FC4);
    // 0x80044598: lw          $v0, 0x20($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X20);
    // 0x8004459C: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x800445A0: lbu         $v0, 0x4($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X4);
    // 0x800445A4: addiu       $v1, $v1, 0x6DC0
    ctx->r3 = ADD32(ctx->r3, 0X6DC0);
    // 0x800445A8: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x800445AC: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x800445B0: swc1        $f0, 0x3C($v1)
    MEM_W(0X3C, ctx->r3) = ctx->f0.u32l;
    // 0x800445B4: lw          $v0, 0x20($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X20);
    // 0x800445B8: lbu         $v0, 0x5($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X5);
    // 0x800445BC: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x800445C0: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x800445C4: swc1        $f0, 0x40($v1)
    MEM_W(0X40, ctx->r3) = ctx->f0.u32l;
    // 0x800445C8: lw          $v0, 0x20($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X20);
    // 0x800445CC: lbu         $v0, 0x6($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X6);
    // 0x800445D0: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x800445D4: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x800445D8: swc1        $f0, 0x44($v1)
    MEM_W(0X44, ctx->r3) = ctx->f0.u32l;
    // 0x800445DC: lw          $v0, 0x20($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X20);
    // 0x800445E0: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x800445E4: lwc1        $f2, -0x5AA4($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X5AA4);
    // 0x800445E8: lbu         $v0, 0x8($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X8);
    // 0x800445EC: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x800445F0: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x800445F4: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x800445F8: div.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f2.fl);
    // 0x800445FC: swc1        $f0, 0x6FB0($v1)
    MEM_W(0X6FB0, ctx->r3) = ctx->f0.u32l;
    // 0x80044600: lw          $v0, 0x20($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X20);
    // 0x80044604: lbu         $v0, 0x9($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X9);
    // 0x80044608: addiu       $v1, $v1, 0x6FB0
    ctx->r3 = ADD32(ctx->r3, 0X6FB0);
    // 0x8004460C: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x80044610: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x80044614: div.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f2.fl);
    // 0x80044618: swc1        $f0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->f0.u32l;
    // 0x8004461C: lw          $v0, 0x20($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X20);
    // 0x80044620: lbu         $v0, 0xA($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0XA);
    // 0x80044624: lw          $t8, 0x88($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X88);
    // 0x80044628: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x8004462C: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x80044630: div.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f2.fl);
    // 0x80044634: bne         $t8, $zero, L_800446EC
    if (ctx->r24 != 0) {
        // 0x80044638: swc1        $f0, 0x8($v1)
        MEM_W(0X8, ctx->r3) = ctx->f0.u32l;
            goto L_800446EC;
    }
    // 0x80044638: swc1        $f0, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->f0.u32l;
    // 0x8004463C: beq         $a1, $zero, L_800446D8
    if (ctx->r5 == 0) {
        // 0x80044640: lui         $v0, 0x8013
        ctx->r2 = S32(0X8013 << 16);
            goto L_800446D8;
    }
    // 0x80044640: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80044644: addiu       $a1, $v0, 0x6E20
    ctx->r5 = ADD32(ctx->r2, 0X6E20);
    // 0x80044648: sll         $v0, $s4, 1
    ctx->r2 = S32(ctx->r20 << 1);
    // 0x8004464C: addu        $v0, $v0, $s4
    ctx->r2 = ADD32(ctx->r2, ctx->r20);
    // 0x80044650: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80044654: subu        $v0, $v0, $s4
    ctx->r2 = SUB32(ctx->r2, ctx->r20);
    // 0x80044658: sll         $v1, $v0, 3
    ctx->r3 = S32(ctx->r2 << 3);
    // 0x8004465C: addu        $a0, $v1, $a1
    ctx->r4 = ADD32(ctx->r3, ctx->r5);
    // 0x80044660: bne         $s4, $zero, L_80044670
    if (ctx->r20 != 0) {
        // 0x80044664: sw          $zero, 0x0($a0)
        MEM_W(0X0, ctx->r4) = 0;
            goto L_80044670;
    }
    // 0x80044664: sw          $zero, 0x0($a0)
    MEM_W(0X0, ctx->r4) = 0;
    // 0x80044668: j           L_8004469C
    // 0x8004466C: sw          $zero, 0x4($a1)
    MEM_W(0X4, ctx->r5) = 0;
        goto L_8004469C;
    // 0x8004466C: sw          $zero, 0x4($a1)
    MEM_W(0X4, ctx->r5) = 0;
L_80044670:
    // 0x80044670: addiu       $v0, $a1, -0x58
    ctx->r2 = ADD32(ctx->r5, -0X58);
    // 0x80044674: addu        $v0, $v1, $v0
    ctx->r2 = ADD32(ctx->r3, ctx->r2);
    // 0x80044678: addiu       $v1, $s4, -0x1
    ctx->r3 = ADD32(ctx->r20, -0X1);
    // 0x8004467C: sw          $v0, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r2;
    // 0x80044680: sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3 << 1);
    // 0x80044684: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80044688: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8004468C: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x80044690: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x80044694: addu        $v0, $v0, $a1
    ctx->r2 = ADD32(ctx->r2, ctx->r5);
    // 0x80044698: sw          $a0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r4;
L_8004469C:
    // 0x8004469C: sll         $v0, $s4, 1
    ctx->r2 = S32(ctx->r20 << 1);
    // 0x800446A0: addu        $v0, $v0, $s4
    ctx->r2 = ADD32(ctx->r2, ctx->r20);
    // 0x800446A4: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800446A8: subu        $v0, $v0, $s4
    ctx->r2 = SUB32(ctx->r2, ctx->r20);
    // 0x800446AC: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    // 0x800446B0: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x800446B4: addiu       $v1, $v1, 0x6E20
    ctx->r3 = ADD32(ctx->r3, 0X6E20);
    // 0x800446B8: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x800446BC: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x800446C0: lwc1        $f0, -0x5AA0($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X5AA0);
    // 0x800446C4: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800446C8: sb          $zero, 0x8($v0)
    MEM_B(0X8, ctx->r2) = 0;
    // 0x800446CC: swc1        $f0, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->f0.u32l;
    // 0x800446D0: swc1        $f0, 0x28($v0)
    MEM_W(0X28, ctx->r2) = ctx->f0.u32l;
    // 0x800446D4: swc1        $f0, 0x2C($v0)
    MEM_W(0X2C, ctx->r2) = ctx->f0.u32l;
L_800446D8:
    // 0x800446D8: blez        $s4, L_800446EC
    if (SIGNED(ctx->r20) <= 0) {
        // 0x800446DC: lui         $v1, 0x8014
        ctx->r3 = S32(0X8014 << 16);
            goto L_800446EC;
    }
    // 0x800446DC: lui         $v1, 0x8014
    ctx->r3 = S32(0X8014 << 16);
    // 0x800446E0: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800446E4: addiu       $v0, $v0, 0x6E20
    ctx->r2 = ADD32(ctx->r2, 0X6E20);
    // 0x800446E8: sw          $v0, -0x72DC($v1)
    MEM_W(-0X72DC, ctx->r3) = ctx->r2;
L_800446EC:
    // 0x800446EC: lw          $ra, 0x7C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X7C);
    // 0x800446F0: lw          $fp, 0x78($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X78);
    // 0x800446F4: lw          $s7, 0x74($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X74);
    // 0x800446F8: lw          $s6, 0x70($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X70);
    // 0x800446FC: lw          $s5, 0x6C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X6C);
    // 0x80044700: lw          $s4, 0x68($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X68);
    // 0x80044704: lw          $s3, 0x64($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X64);
    // 0x80044708: lw          $s2, 0x60($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X60);
    // 0x8004470C: lw          $s1, 0x5C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X5C);
    // 0x80044710: lw          $s0, 0x58($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X58);
    // 0x80044714: ldc1        $f20, 0x80($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X80);
    // 0x80044718: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8004471C: jr          $ra
    // 0x80044720: addiu       $sp, $sp, 0x88
    ctx->r29 = ADD32(ctx->r29, 0X88);
    return;
    // 0x80044720: addiu       $sp, $sp, 0x88
    ctx->r29 = ADD32(ctx->r29, 0X88);
;}
RECOMP_FUNC void func_80044724(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80044724: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x80044728: sw          $s0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r16;
    // 0x8004472C: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x80044730: andi        $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 & 0XFFFF;
    // 0x80044734: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x80044738: sw          $ra, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r31;
    // 0x8004473C: sw          $s3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r19;
    // 0x80044740: sw          $s2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r18;
    // 0x80044744: sw          $s1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r17;
    // 0x80044748: lw          $s2, 0x4($s0)
    ctx->r18 = MEM_W(ctx->r16, 0X4);
    // 0x8004474C: beq         $a1, $v0, L_80044BC4
    if (ctx->r5 == ctx->r2) {
        // 0x80044750: slti        $v0, $a1, 0x3
        ctx->r2 = SIGNED(ctx->r5) < 0X3 ? 1 : 0;
            goto L_80044BC4;
    }
    // 0x80044750: slti        $v0, $a1, 0x3
    ctx->r2 = SIGNED(ctx->r5) < 0X3 ? 1 : 0;
    // 0x80044754: beq         $v0, $zero, L_8004476C
    if (ctx->r2 == 0) {
        // 0x80044758: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_8004476C;
    }
    // 0x80044758: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8004475C: beq         $a1, $v0, L_80044780
    if (ctx->r5 == ctx->r2) {
        // 0x80044760: addiu       $a0, $zero, 0x118
        ctx->r4 = ADD32(0, 0X118);
            goto L_80044780;
    }
    // 0x80044760: addiu       $a0, $zero, 0x118
    ctx->r4 = ADD32(0, 0X118);
    // 0x80044764: j           L_80044BC4
    // 0x80044768: nop

        goto L_80044BC4;
    // 0x80044768: nop

L_8004476C:
    // 0x8004476C: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // 0x80044770: beq         $a1, $v0, L_80044888
    if (ctx->r5 == ctx->r2) {
        // 0x80044774: addu        $s1, $a2, $zero
        ctx->r17 = ADD32(ctx->r6, 0);
            goto L_80044888;
    }
    // 0x80044774: addu        $s1, $a2, $zero
    ctx->r17 = ADD32(ctx->r6, 0);
    // 0x80044778: j           L_80044BC4
    // 0x8004477C: nop

        goto L_80044BC4;
    // 0x8004477C: nop

L_80044780:
    // 0x80044780: jal         0x80001ACC
    // 0x80044784: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    rs_malloc(rdram, ctx);
        goto after_0;
    // 0x80044784: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    after_0:
    // 0x80044788: addu        $s2, $v0, $zero
    ctx->r18 = ADD32(ctx->r2, 0);
    // 0x8004478C: addiu       $s1, $s2, 0xA8
    ctx->r17 = ADD32(ctx->r18, 0XA8);
    // 0x80044790: sw          $s2, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r18;
    // 0x80044794: sw          $s1, 0x4C($s2)
    MEM_W(0X4C, ctx->r18) = ctx->r17;
    // 0x80044798: sw          $zero, 0x54($s2)
    MEM_W(0X54, ctx->r18) = 0;
    // 0x8004479C: jal         0x8006B3F0
    // 0x800447A0: sw          $zero, 0x50($s2)
    MEM_W(0X50, ctx->r18) = 0;
    func_8006B3F0(rdram, ctx);
        goto after_1;
    // 0x800447A0: sw          $zero, 0x50($s2)
    MEM_W(0X50, ctx->r18) = 0;
    after_1:
    // 0x800447A4: addiu       $s0, $s2, 0x4C
    ctx->r16 = ADD32(ctx->r18, 0X4C);
    // 0x800447A8: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x800447AC: lui         $v1, 0x8004
    ctx->r3 = S32(0X8004 << 16);
    // 0x800447B0: or          $v0, $v0, $v1
    ctx->r2 = ctx->r2 | ctx->r3;
    // 0x800447B4: sw          $v0, 0x58($s2)
    MEM_W(0X58, ctx->r18) = ctx->r2;
    // 0x800447B8: sw          $zero, 0x5C($s2)
    MEM_W(0X5C, ctx->r18) = 0;
    // 0x800447BC: sw          $zero, 0x64($s2)
    MEM_W(0X64, ctx->r18) = 0;
    // 0x800447C0: sw          $zero, 0x60($s2)
    MEM_W(0X60, ctx->r18) = 0;
    // 0x800447C4: sw          $zero, 0x6C($s2)
    MEM_W(0X6C, ctx->r18) = 0;
    // 0x800447C8: sw          $zero, 0x74($s2)
    MEM_W(0X74, ctx->r18) = 0;
    // 0x800447CC: jal         0x8000A85C
    // 0x800447D0: sw          $zero, 0x70($s2)
    MEM_W(0X70, ctx->r18) = 0;
    func_8000A85C(rdram, ctx);
        goto after_2;
    // 0x800447D0: sw          $zero, 0x70($s2)
    MEM_W(0X70, ctx->r18) = 0;
    after_2:
    // 0x800447D4: sw          $zero, 0xA8($s2)
    MEM_W(0XA8, ctx->r18) = 0;
    // 0x800447D8: sw          $s0, 0xAC($s2)
    MEM_W(0XAC, ctx->r18) = ctx->r16;
    // 0x800447DC: jal         0x8006B458
    // 0x800447E0: sw          $zero, 0xB0($s2)
    MEM_W(0XB0, ctx->r18) = 0;
    func_8006B458(rdram, ctx);
        goto after_3;
    // 0x800447E0: sw          $zero, 0xB0($s2)
    MEM_W(0XB0, ctx->r18) = 0;
    after_3:
    // 0x800447E4: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x800447E8: lui         $v1, 0x8005
    ctx->r3 = S32(0X8005 << 16);
    // 0x800447EC: or          $v0, $v0, $v1
    ctx->r2 = ctx->r2 | ctx->r3;
    // 0x800447F0: sw          $v0, 0xB4($s2)
    MEM_W(0XB4, ctx->r18) = ctx->r2;
    // 0x800447F4: sw          $zero, 0xB8($s2)
    MEM_W(0XB8, ctx->r18) = 0;
    // 0x800447F8: sw          $zero, 0xC0($s2)
    MEM_W(0XC0, ctx->r18) = 0;
    // 0x800447FC: sw          $zero, 0xBC($s2)
    MEM_W(0XBC, ctx->r18) = 0;
    // 0x80044800: sw          $zero, 0xC8($s2)
    MEM_W(0XC8, ctx->r18) = 0;
    // 0x80044804: sw          $zero, 0xD0($s2)
    MEM_W(0XD0, ctx->r18) = 0;
    // 0x80044808: jal         0x8000A85C
    // 0x8004480C: sw          $zero, 0xCC($s2)
    MEM_W(0XCC, ctx->r18) = 0;
    func_8000A85C(rdram, ctx);
        goto after_4;
    // 0x8004480C: sw          $zero, 0xCC($s2)
    MEM_W(0XCC, ctx->r18) = 0;
    after_4:
    // 0x80044810: addiu       $s1, $s2, 0x1C
    ctx->r17 = ADD32(ctx->r18, 0X1C);
    // 0x80044814: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x80044818: sw          $zero, 0xC($s2)
    MEM_W(0XC, ctx->r18) = 0;
    // 0x8004481C: sw          $zero, 0x8($s2)
    MEM_W(0X8, ctx->r18) = 0;
    // 0x80044820: sw          $zero, 0x4($s2)
    MEM_W(0X4, ctx->r18) = 0;
    // 0x80044824: sw          $zero, 0x0($s2)
    MEM_W(0X0, ctx->r18) = 0;
    // 0x80044828: sw          $s0, 0x10($s2)
    MEM_W(0X10, ctx->r18) = ctx->r16;
    // 0x8004482C: jal         0x8001CA50
    // 0x80044830: sw          $zero, 0x14($s2)
    MEM_W(0X14, ctx->r18) = 0;
    func_8001CA50(rdram, ctx);
        goto after_5;
    // 0x80044830: sw          $zero, 0x14($s2)
    MEM_W(0X14, ctx->r18) = 0;
    after_5:
    // 0x80044834: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80044838: lwc1        $f2, 0x6DD0($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X6DD0);
    // 0x8004483C: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80044840: lwc1        $f0, -0x5A9C($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X5A9C);
    // 0x80044844: mul.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x80044848: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8004484C: lwc1        $f0, -0x5A98($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X5A98);
    // 0x80044850: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x80044854: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80044858: mfc1        $a2, $f2
    ctx->r6 = (int32_t)ctx->f2.u32l;
    // 0x8004485C: jal         0x8001CB04
    // 0x80044860: addu        $a3, $a1, $zero
    ctx->r7 = ADD32(ctx->r5, 0);
    func_8001CB04(rdram, ctx);
        goto after_6;
    // 0x80044860: addu        $a3, $a1, $zero
    ctx->r7 = ADD32(ctx->r5, 0);
    after_6:
    // 0x80044864: lui         $a0, 0x8006
    ctx->r4 = S32(0X8006 << 16);
    // 0x80044868: addiu       $a0, $a0, -0x433C
    ctx->r4 = ADD32(ctx->r4, -0X433C);
    // 0x8004486C: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x80044870: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x80044874: addiu       $a3, $zero, 0x64
    ctx->r7 = ADD32(0, 0X64);
    // 0x80044878: jal         0x8003FFEC
    // 0x8004487C: sw          $zero, 0x108($s2)
    MEM_W(0X108, ctx->r18) = 0;
    func_8003FFEC(rdram, ctx);
        goto after_7;
    // 0x8004487C: sw          $zero, 0x108($s2)
    MEM_W(0X108, ctx->r18) = 0;
    after_7:
    // 0x80044880: j           L_80044BC4
    // 0x80044884: sh          $v0, 0x104($s2)
    MEM_H(0X104, ctx->r18) = ctx->r2;
        goto L_80044BC4;
    // 0x80044884: sh          $v0, 0x104($s2)
    MEM_H(0X104, ctx->r18) = ctx->r2;
L_80044888:
    // 0x80044888: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8004488C: lw          $v1, 0xB70($v0)
    ctx->r3 = MEM_W(ctx->r2, 0XB70);
    // 0x80044890: addiu       $v0, $zero, 0xA
    ctx->r2 = ADD32(0, 0XA);
    // 0x80044894: bne         $v1, $v0, L_800448B4
    if (ctx->r3 != ctx->r2) {
        // 0x80044898: sw          $zero, 0xC8($s2)
        MEM_W(0XC8, ctx->r18) = 0;
            goto L_800448B4;
    }
    // 0x80044898: sw          $zero, 0xC8($s2)
    MEM_W(0XC8, ctx->r18) = 0;
    // 0x8004489C: addu        $s3, $zero, $zero
    ctx->r19 = ADD32(0, 0);
    // 0x800448A0: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x800448A4: lwc1        $f0, -0x5A94($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X5A94);
    // 0x800448A8: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x800448AC: j           L_800448CC
    // 0x800448B0: swc1        $f0, -0x2154($v0)
    MEM_W(-0X2154, ctx->r2) = ctx->f0.u32l;
        goto L_800448CC;
    // 0x800448B0: swc1        $f0, -0x2154($v0)
    MEM_W(-0X2154, ctx->r2) = ctx->f0.u32l;
L_800448B4:
    // 0x800448B4: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x800448B8: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    // 0x800448BC: lw          $a2, 0x20($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X20);
    // 0x800448C0: jal         0x800437B0
    // 0x800448C4: addiu       $a1, $s2, 0xC8
    ctx->r5 = ADD32(ctx->r18, 0XC8);
    func_800437B0(rdram, ctx);
        goto after_8;
    // 0x800448C4: addiu       $a1, $s2, 0xC8
    ctx->r5 = ADD32(ctx->r18, 0XC8);
    after_8:
    // 0x800448C8: addu        $s3, $v0, $zero
    ctx->r19 = ADD32(ctx->r2, 0);
L_800448CC:
    // 0x800448CC: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x800448D0: jal         0x800455C8
    // 0x800448D4: nop

    func_800455C8(rdram, ctx);
        goto after_9;
    // 0x800448D4: nop

    after_9:
    // 0x800448D8: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x800448DC: lw          $v1, 0x0($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X0);
    // 0x800448E0: lwc1        $f2, 0x6FBC($a1)
    ctx->f2.u32l = MEM_W(ctx->r5, 0X6FBC);
    // 0x800448E4: lwc1        $f4, 0x28($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X28);
    // 0x800448E8: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800448EC: mul.s       $f2, $f4, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = MUL_S(ctx->f4.fl, ctx->f2.fl);
    // 0x800448F0: lbu         $a0, 0x6E18($v0)
    ctx->r4 = MEM_BU(ctx->r2, 0X6E18);
    // 0x800448F4: addiu       $v0, $v0, 0x6E18
    ctx->r2 = ADD32(ctx->r2, 0X6E18);
    // 0x800448F8: lbu         $a1, 0x1($v0)
    ctx->r5 = MEM_BU(ctx->r2, 0X1);
    // 0x800448FC: lbu         $a2, 0x2($v0)
    ctx->r6 = MEM_BU(ctx->r2, 0X2);
    // 0x80044900: sub.s       $f4, $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = ctx->f4.fl - ctx->f2.fl;
    // 0x80044904: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80044908: lwc1        $f0, -0x5A90($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X5A90);
    // 0x8004490C: mfc1        $a3, $f2
    ctx->r7 = (int32_t)ctx->f2.u32l;
    // 0x80044910: div.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f4.fl);
    // 0x80044914: jal         0x80017AE0
    // 0x80044918: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    func_80017AE0(rdram, ctx);
        goto after_10;
    // 0x80044918: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    after_10:
    // 0x8004491C: jal         0x80017B48
    // 0x80044920: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_80017B48(rdram, ctx);
        goto after_11;
    // 0x80044920: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_11:
    // 0x80044924: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80044928: lbu         $v1, 0xB39($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0XB39);
    // 0x8004492C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80044930: beq         $v1, $v0, L_8004498C
    if (ctx->r3 == ctx->r2) {
        // 0x80044934: addu        $a0, $zero, $zero
        ctx->r4 = ADD32(0, 0);
            goto L_8004498C;
    }
    // 0x80044934: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x80044938: lw          $v0, 0x108($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X108);
    // 0x8004493C: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80044940: sw          $v0, 0x108($s2)
    MEM_W(0X108, ctx->r18) = ctx->r2;
    // 0x80044944: slti        $v0, $v0, 0x5
    ctx->r2 = SIGNED(ctx->r2) < 0X5 ? 1 : 0;
    // 0x80044948: bne         $v0, $zero, L_8004498C
    if (ctx->r2 != 0) {
        // 0x8004494C: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_8004498C;
    }
    // 0x8004494C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80044950: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80044954: lw          $v0, 0xB50($v0)
    ctx->r2 = MEM_W(ctx->r2, 0XB50);
    // 0x80044958: andi        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 & 0X1;
    // 0x8004495C: bne         $v0, $zero, L_8004498C
    if (ctx->r2 != 0) {
        // 0x80044960: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_8004498C;
    }
    // 0x80044960: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80044964: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x80044968: lw          $v0, -0x35E4($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X35E4);
    // 0x8004496C: andi        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 & 0X1;
    // 0x80044970: bne         $v0, $zero, L_8004498C
    if (ctx->r2 != 0) {
        // 0x80044974: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_8004498C;
    }
    // 0x80044974: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80044978: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x8004497C: lbu         $v0, -0x77C8($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X77C8);
    // 0x80044980: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80044984: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // 0x80044988: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8004498C:
    // 0x8004498C: bne         $a0, $v0, L_80044AD0
    if (ctx->r4 != ctx->r2) {
        // 0x80044990: lui         $v1, 0x8014
        ctx->r3 = S32(0X8014 << 16);
            goto L_80044AD0;
    }
    // 0x80044990: lui         $v1, 0x8014
    ctx->r3 = S32(0X8014 << 16);
    // 0x80044994: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x80044998: lw          $v0, -0x72E4($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X72E4);
    // 0x8004499C: lwc1        $f0, 0x30($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X30);
    // 0x800449A0: swc1        $f0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f0.u32l;
    // 0x800449A4: lwc1        $f0, 0x3C($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X3C);
    // 0x800449A8: addiu       $s0, $sp, 0x28
    ctx->r16 = ADD32(ctx->r29, 0X28);
    // 0x800449AC: swc1        $f0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f0.u32l;
    // 0x800449B0: lwc1        $f0, 0x48($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X48);
    // 0x800449B4: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x800449B8: jal         0x8001CF58
    // 0x800449BC: swc1        $f0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f0.u32l;
    normalize_vector(rdram, ctx);
        goto after_12;
    // 0x800449BC: swc1        $f0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f0.u32l;
    after_12:
    // 0x800449C0: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x800449C4: jal         0x8001CFE8
    // 0x800449C8: addiu       $a1, $s2, 0x10C
    ctx->r5 = ADD32(ctx->r18, 0X10C);
    func_8001CFE8(rdram, ctx);
        goto after_13;
    // 0x800449C8: addiu       $a1, $s2, 0x10C
    ctx->r5 = ADD32(ctx->r18, 0X10C);
    after_13:
    // 0x800449CC: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x800449D0: lwc1        $f2, -0x5A8C($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X5A8C);
    // 0x800449D4: c.le.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl <= ctx->f0.fl;
    // 0x800449D8: nop

    // 0x800449DC: bc1f        L_80044A30
    if (!c1cs) {
        // 0x800449E0: lui         $a2, 0xCFFF
        ctx->r6 = S32(0XCFFF << 16);
            goto L_80044A30;
    }
    // 0x800449E0: lui         $a2, 0xCFFF
    ctx->r6 = S32(0XCFFF << 16);
    // 0x800449E4: lui         $v1, 0x8014
    ctx->r3 = S32(0X8014 << 16);
    // 0x800449E8: ori         $a2, $a2, 0xFFFF
    ctx->r6 = ctx->r6 | 0XFFFF;
    // 0x800449EC: lui         $a1, 0x8014
    ctx->r5 = S32(0X8014 << 16);
    // 0x800449F0: lw          $v0, -0x7768($v1)
    ctx->r2 = MEM_W(ctx->r3, -0X7768);
    // 0x800449F4: addiu       $a0, $zero, -0x12
    ctx->r4 = ADD32(0, -0X12);
    // 0x800449F8: ori         $v0, $v0, 0x11
    ctx->r2 = ctx->r2 | 0X11;
    // 0x800449FC: sw          $v0, -0x7768($v1)
    MEM_W(-0X7768, ctx->r3) = ctx->r2;
    // 0x80044A00: lw          $v1, -0x76D8($a1)
    ctx->r3 = MEM_W(ctx->r5, -0X76D8);
    // 0x80044A04: lw          $v0, 0x58($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X58);
    // 0x80044A08: and         $v1, $v1, $a0
    ctx->r3 = ctx->r3 & ctx->r4;
    // 0x80044A0C: and         $v0, $v0, $a2
    ctx->r2 = ctx->r2 & ctx->r6;
    // 0x80044A10: sw          $v1, -0x76D8($a1)
    MEM_W(-0X76D8, ctx->r5) = ctx->r3;
    // 0x80044A14: lui         $v1, 0x3000
    ctx->r3 = S32(0X3000 << 16);
    // 0x80044A18: or          $v0, $v0, $v1
    ctx->r2 = ctx->r2 | ctx->r3;
    // 0x80044A1C: sw          $v0, 0x58($s2)
    MEM_W(0X58, ctx->r18) = ctx->r2;
    // 0x80044A20: and         $v0, $v0, $a2
    ctx->r2 = ctx->r2 & ctx->r6;
    // 0x80044A24: or          $v0, $v0, $v1
    ctx->r2 = ctx->r2 | ctx->r3;
    // 0x80044A28: j           L_80044A74
    // 0x80044A2C: sw          $v0, 0xB4($s2)
    MEM_W(0XB4, ctx->r18) = ctx->r2;
        goto L_80044A74;
    // 0x80044A2C: sw          $v0, 0xB4($s2)
    MEM_W(0XB4, ctx->r18) = ctx->r2;
L_80044A30:
    // 0x80044A30: lui         $a1, 0xCFFF
    ctx->r5 = S32(0XCFFF << 16);
    // 0x80044A34: lui         $v1, 0x8014
    ctx->r3 = S32(0X8014 << 16);
    // 0x80044A38: ori         $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 | 0XFFFF;
    // 0x80044A3C: lw          $v0, -0x76D8($v1)
    ctx->r2 = MEM_W(ctx->r3, -0X76D8);
    // 0x80044A40: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80044A44: ori         $v0, $v0, 0x11
    ctx->r2 = ctx->r2 | 0X11;
    // 0x80044A48: sw          $v0, -0x76D8($v1)
    MEM_W(-0X76D8, ctx->r3) = ctx->r2;
    // 0x80044A4C: lw          $v0, -0x7768($a0)
    ctx->r2 = MEM_W(ctx->r4, -0X7768);
    // 0x80044A50: addiu       $v1, $zero, -0x12
    ctx->r3 = ADD32(0, -0X12);
    // 0x80044A54: and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // 0x80044A58: sw          $v0, -0x7768($a0)
    MEM_W(-0X7768, ctx->r4) = ctx->r2;
    // 0x80044A5C: lw          $v0, 0x58($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X58);
    // 0x80044A60: lw          $v1, 0xB4($s2)
    ctx->r3 = MEM_W(ctx->r18, 0XB4);
    // 0x80044A64: and         $v0, $v0, $a1
    ctx->r2 = ctx->r2 & ctx->r5;
    // 0x80044A68: and         $v1, $v1, $a1
    ctx->r3 = ctx->r3 & ctx->r5;
    // 0x80044A6C: sw          $v0, 0x58($s2)
    MEM_W(0X58, ctx->r18) = ctx->r2;
    // 0x80044A70: sw          $v1, 0xB4($s2)
    MEM_W(0XB4, ctx->r18) = ctx->r3;
L_80044A74:
    // 0x80044A74: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80044A78: lbu         $v0, 0xB39($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0XB39);
    // 0x80044A7C: bne         $v0, $zero, L_80044AD0
    if (ctx->r2 != 0) {
        // 0x80044A80: lui         $v1, 0x8014
        ctx->r3 = S32(0X8014 << 16);
            goto L_80044AD0;
    }
    // 0x80044A80: lui         $v1, 0x8014
    ctx->r3 = S32(0X8014 << 16);
    // 0x80044A84: lui         $s0, 0x8014
    ctx->r16 = S32(0X8014 << 16);
    // 0x80044A88: lw          $v0, -0x7768($s0)
    ctx->r2 = MEM_W(ctx->r16, -0X7768);
    // 0x80044A8C: andi        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 & 0X1;
    // 0x80044A90: bne         $v0, $zero, L_80044AD4
    if (ctx->r2 != 0) {
        // 0x80044A94: addiu       $v1, $v1, -0x72E8
        ctx->r3 = ADD32(ctx->r3, -0X72E8);
            goto L_80044AD4;
    }
    // 0x80044A94: addiu       $v1, $v1, -0x72E8
    ctx->r3 = ADD32(ctx->r3, -0X72E8);
    // 0x80044A98: jal         0x800AE3BC
    // 0x80044A9C: nop

    func_800AE3BC(rdram, ctx);
        goto after_14;
    // 0x80044A9C: nop

    after_14:
    // 0x80044AA0: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x80044AA4: bne         $v0, $zero, L_80044AD0
    if (ctx->r2 != 0) {
        // 0x80044AA8: lui         $v1, 0x8014
        ctx->r3 = S32(0X8014 << 16);
            goto L_80044AD0;
    }
    // 0x80044AA8: lui         $v1, 0x8014
    ctx->r3 = S32(0X8014 << 16);
    // 0x80044AAC: lw          $v0, -0x7768($s0)
    ctx->r2 = MEM_W(ctx->r16, -0X7768);
    // 0x80044AB0: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80044AB4: ori         $v0, $v0, 0x11
    ctx->r2 = ctx->r2 | 0X11;
    // 0x80044AB8: sw          $v0, -0x7768($s0)
    MEM_W(-0X7768, ctx->r16) = ctx->r2;
    // 0x80044ABC: lw          $v0, -0x76D8($a0)
    ctx->r2 = MEM_W(ctx->r4, -0X76D8);
    // 0x80044AC0: addiu       $v1, $zero, -0x12
    ctx->r3 = ADD32(0, -0X12);
    // 0x80044AC4: and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // 0x80044AC8: sw          $v0, -0x76D8($a0)
    MEM_W(-0X76D8, ctx->r4) = ctx->r2;
    // 0x80044ACC: lui         $v1, 0x8014
    ctx->r3 = S32(0X8014 << 16);
L_80044AD0:
    // 0x80044AD0: addiu       $v1, $v1, -0x72E8
    ctx->r3 = ADD32(ctx->r3, -0X72E8);
L_80044AD4:
    // 0x80044AD4: lw          $v0, 0x4($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X4);
    // 0x80044AD8: lwc1        $f0, 0x30($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X30);
    // 0x80044ADC: swc1        $f0, 0x10C($s2)
    MEM_W(0X10C, ctx->r18) = ctx->f0.u32l;
    // 0x80044AE0: lw          $v0, 0x4($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X4);
    // 0x80044AE4: lwc1        $f0, 0x3C($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X3C);
    // 0x80044AE8: swc1        $f0, 0x110($s2)
    MEM_W(0X110, ctx->r18) = ctx->f0.u32l;
    // 0x80044AEC: lw          $v0, 0x4($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X4);
    // 0x80044AF0: lwc1        $f0, 0x48($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X48);
    // 0x80044AF4: addiu       $a0, $s2, 0x10C
    ctx->r4 = ADD32(ctx->r18, 0X10C);
    // 0x80044AF8: jal         0x8001CF58
    // 0x80044AFC: swc1        $f0, 0x114($s2)
    MEM_W(0X114, ctx->r18) = ctx->f0.u32l;
    normalize_vector(rdram, ctx);
        goto after_15;
    // 0x80044AFC: swc1        $f0, 0x114($s2)
    MEM_W(0X114, ctx->r18) = ctx->f0.u32l;
    after_15:
    // 0x80044B00: beq         $s3, $zero, L_80044B70
    if (ctx->r19 == 0) {
        // 0x80044B04: lui         $v0, 0x8013
        ctx->r2 = S32(0X8013 << 16);
            goto L_80044B70;
    }
    // 0x80044B04: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80044B08: sw          $s3, 0x6C($s2)
    MEM_W(0X6C, ctx->r18) = ctx->r19;
    // 0x80044B0C: lwc1        $f4, 0x6DD0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X6DD0);
    // 0x80044B10: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80044B14: lwc1        $f0, -0x5A88($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X5A88);
    // 0x80044B18: mul.s       $f4, $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x80044B1C: addiu       $s0, $s2, 0x1C
    ctx->r16 = ADD32(ctx->r18, 0X1C);
    // 0x80044B20: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80044B24: lwc1        $f2, -0x5A84($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X5A84);
    // 0x80044B28: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x80044B2C: mfc1        $a1, $f2
    ctx->r5 = (int32_t)ctx->f2.u32l;
    // 0x80044B30: mfc1        $a2, $f4
    ctx->r6 = (int32_t)ctx->f4.u32l;
    // 0x80044B34: jal         0x8001CB64
    // 0x80044B38: addu        $a3, $a1, $zero
    ctx->r7 = ADD32(ctx->r5, 0);
    func_8001CB64(rdram, ctx);
        goto after_16;
    // 0x80044B38: addu        $a3, $a1, $zero
    ctx->r7 = ADD32(ctx->r5, 0);
    after_16:
    // 0x80044B3C: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x80044B40: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    // 0x80044B44: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x80044B48: jal         0x8001CA90
    // 0x80044B4C: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_8001CA90(rdram, ctx);
        goto after_17;
    // 0x80044B4C: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_17:
    // 0x80044B50: lw          $v0, 0x8($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X8);
    // 0x80044B54: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x80044B58: beq         $v0, $zero, L_80044B64
    if (ctx->r2 == 0) {
        // 0x80044B5C: sw          $v0, 0x0($s2)
        MEM_W(0X0, ctx->r18) = ctx->r2;
            goto L_80044B64;
    }
    // 0x80044B5C: sw          $v0, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r2;
    // 0x80044B60: sw          $s2, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r18;
L_80044B64:
    // 0x80044B64: lw          $v0, 0x8($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X8);
    // 0x80044B68: sw          $s2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r18;
    // 0x80044B6C: sw          $zero, 0x4($s2)
    MEM_W(0X4, ctx->r18) = 0;
L_80044B70:
    // 0x80044B70: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80044B74: lbu         $v1, 0xB39($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0XB39);
    // 0x80044B78: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80044B7C: bne         $v1, $v0, L_80044B94
    if (ctx->r3 != ctx->r2) {
        // 0x80044B80: lui         $v0, 0x8013
        ctx->r2 = S32(0X8013 << 16);
            goto L_80044B94;
    }
    // 0x80044B80: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80044B84: lw          $v1, 0xB70($v0)
    ctx->r3 = MEM_W(ctx->r2, 0XB70);
    // 0x80044B88: addiu       $v0, $zero, 0x13
    ctx->r2 = ADD32(0, 0X13);
    // 0x80044B8C: beq         $v1, $v0, L_80044BA8
    if (ctx->r3 == ctx->r2) {
        // 0x80044B90: lui         $v0, 0x8014
        ctx->r2 = S32(0X8014 << 16);
            goto L_80044BA8;
    }
    // 0x80044B90: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
L_80044B94:
    // 0x80044B94: lhu         $a0, 0x104($s2)
    ctx->r4 = MEM_HU(ctx->r18, 0X104);
    // 0x80044B98: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x80044B9C: jal         0x8003E8DC
    // 0x80044BA0: addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    func_8003E8DC(rdram, ctx);
        goto after_18;
    // 0x80044BA0: addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    after_18:
    // 0x80044BA4: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
L_80044BA8:
    // 0x80044BA8: lw          $a0, -0x7768($v0)
    ctx->r4 = MEM_W(ctx->r2, -0X7768);
    // 0x80044BAC: jal         0x8001B7B8
    // 0x80044BB0: nop

    func_8001B7B8(rdram, ctx);
        goto after_19;
    // 0x80044BB0: nop

    after_19:
    // 0x80044BB4: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x80044BB8: lw          $a0, -0x76D8($v0)
    ctx->r4 = MEM_W(ctx->r2, -0X76D8);
    // 0x80044BBC: jal         0x8001B7C8
    // 0x80044BC0: nop

    func_8001B7C8(rdram, ctx);
        goto after_20;
    // 0x80044BC0: nop

    after_20:
L_80044BC4:
    // 0x80044BC4: lw          $ra, 0x48($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X48);
    // 0x80044BC8: lw          $s3, 0x44($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X44);
    // 0x80044BCC: lw          $s2, 0x40($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X40);
    // 0x80044BD0: lw          $s1, 0x3C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X3C);
    // 0x80044BD4: lw          $s0, 0x38($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X38);
    // 0x80044BD8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80044BDC: jr          $ra
    // 0x80044BE0: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x80044BE0: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}
RECOMP_FUNC void func_80044BE4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80044BE4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80044BE8: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x80044BEC: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x80044BF0: lw          $v0, 0x6FC4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X6FC4);
    // 0x80044BF4: sw          $ra, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r31;
    // 0x80044BF8: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x80044BFC: lhu         $a0, 0x18($v0)
    ctx->r4 = MEM_HU(ctx->r2, 0X18);
    // 0x80044C00: jal         0x80001ACC
    // 0x80044C04: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    rs_malloc(rdram, ctx);
        goto after_0;
    // 0x80044C04: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    after_0:
    // 0x80044C08: addu        $s1, $v0, $zero
    ctx->r17 = ADD32(ctx->r2, 0);
    // 0x80044C0C: lw          $v0, 0x6FC4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X6FC4);
    // 0x80044C10: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x80044C14: lhu         $a2, 0x18($v0)
    ctx->r6 = MEM_HU(ctx->r2, 0X18);
    // 0x80044C18: jal         0x800078E0
    // 0x80044C1C: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    rs_memset(rdram, ctx);
        goto after_1;
    // 0x80044C1C: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    after_1:
    // 0x80044C20: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x80044C24: addiu       $a0, $v1, 0x6DC0
    ctx->r4 = ADD32(ctx->r3, 0X6DC0);
    // 0x80044C28: lhu         $v0, 0x3A($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X3A);
    // 0x80044C2C: lw          $a3, 0x6DC0($v1)
    ctx->r7 = MEM_W(ctx->r3, 0X6DC0);
    // 0x80044C30: beq         $v0, $zero, L_80044DD0
    if (ctx->r2 == 0) {
        // 0x80044C34: addu        $a1, $zero, $zero
        ctx->r5 = ADD32(0, 0);
            goto L_80044DD0;
    }
    // 0x80044C34: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x80044C38: addu        $t0, $v1, $zero
    ctx->r8 = ADD32(ctx->r3, 0);
    // 0x80044C3C: addu        $a2, $a0, $zero
    ctx->r6 = ADD32(ctx->r4, 0);
    // 0x80044C40: addiu       $s0, $zero, -0x11
    ctx->r16 = ADD32(0, -0X11);
    // 0x80044C44: addiu       $t7, $zero, -0x2
    ctx->r15 = ADD32(0, -0X2);
    // 0x80044C48: addiu       $t6, $zero, -0x21
    ctx->r14 = ADD32(0, -0X21);
    // 0x80044C4C: addiu       $t5, $zero, -0x3
    ctx->r13 = ADD32(0, -0X3);
    // 0x80044C50: addiu       $t4, $zero, -0x81
    ctx->r12 = ADD32(0, -0X81);
L_80044C54:
    // 0x80044C54: lhu         $v0, 0x38($a2)
    ctx->r2 = MEM_HU(ctx->r6, 0X38);
    // 0x80044C58: beq         $v0, $zero, L_80044DBC
    if (ctx->r2 == 0) {
        // 0x80044C5C: addu        $a0, $zero, $zero
        ctx->r4 = ADD32(0, 0);
            goto L_80044DBC;
    }
    // 0x80044C5C: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x80044C60: addiu       $t3, $a1, -0x1
    ctx->r11 = ADD32(ctx->r5, -0X1);
    // 0x80044C64: addiu       $t2, $a1, 0x1
    ctx->r10 = ADD32(ctx->r5, 0X1);
L_80044C68:
    // 0x80044C68: lhu         $v0, 0x0($a3)
    ctx->r2 = MEM_HU(ctx->r7, 0X0);
    // 0x80044C6C: andi        $v0, $v0, 0x1FFF
    ctx->r2 = ctx->r2 & 0X1FFF;
    // 0x80044C70: addu        $v0, $s1, $v0
    ctx->r2 = ADD32(ctx->r17, ctx->r2);
    // 0x80044C74: lbu         $t1, 0x0($v0)
    ctx->r9 = MEM_BU(ctx->r2, 0X0);
    // 0x80044C78: blez        $a0, L_80044CB8
    if (SIGNED(ctx->r4) <= 0) {
        // 0x80044C7C: nop
    
            goto L_80044CB8;
    }
    // 0x80044C7C: nop

    // 0x80044C80: lhu         $v0, 0x38($a2)
    ctx->r2 = MEM_HU(ctx->r6, 0X38);
    // 0x80044C84: mult        $a1, $v0
    result = S64(S32(ctx->r5)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80044C88: lw          $v1, 0x6DC0($t0)
    ctx->r3 = MEM_W(ctx->r8, 0X6DC0);
    // 0x80044C8C: mflo        $t8
    ctx->r24 = lo;
    // 0x80044C90: addu        $v0, $t8, $a0
    ctx->r2 = ADD32(ctx->r24, ctx->r4);
    // 0x80044C94: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x80044C98: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80044C9C: lhu         $v1, -0x2($v0)
    ctx->r3 = MEM_HU(ctx->r2, -0X2);
    // 0x80044CA0: andi        $v0, $v1, 0xC000
    ctx->r2 = ctx->r3 & 0XC000;
    // 0x80044CA4: beql        $v0, $zero, L_80044CAC
    if (ctx->r2 == 0) {
        // 0x80044CA8: and         $t1, $t1, $s0
        ctx->r9 = ctx->r9 & ctx->r16;
            goto L_80044CAC;
    }
    goto skip_0;
    // 0x80044CA8: and         $t1, $t1, $s0
    ctx->r9 = ctx->r9 & ctx->r16;
    skip_0:
L_80044CAC:
    // 0x80044CAC: andi        $v0, $v1, 0x8000
    ctx->r2 = ctx->r3 & 0X8000;
    // 0x80044CB0: beql        $v0, $zero, L_80044CB8
    if (ctx->r2 == 0) {
        // 0x80044CB4: and         $t1, $t1, $t7
        ctx->r9 = ctx->r9 & ctx->r15;
            goto L_80044CB8;
    }
    goto skip_1;
    // 0x80044CB4: and         $t1, $t1, $t7
    ctx->r9 = ctx->r9 & ctx->r15;
    skip_1:
L_80044CB8:
    // 0x80044CB8: lhu         $v1, 0x38($a2)
    ctx->r3 = MEM_HU(ctx->r6, 0X38);
    // 0x80044CBC: addiu       $v0, $v1, -0x1
    ctx->r2 = ADD32(ctx->r3, -0X1);
    // 0x80044CC0: slt         $v0, $a0, $v0
    ctx->r2 = SIGNED(ctx->r4) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80044CC4: mult        $a1, $v1
    result = S64(S32(ctx->r5)) * S64(S32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80044CC8: beq         $v0, $zero, L_80044D00
    if (ctx->r2 == 0) {
        // 0x80044CCC: nop
    
            goto L_80044D00;
    }
    // 0x80044CCC: nop

    // 0x80044CD0: lw          $v1, 0x6DC0($t0)
    ctx->r3 = MEM_W(ctx->r8, 0X6DC0);
    // 0x80044CD4: mflo        $t8
    ctx->r24 = lo;
    // 0x80044CD8: addu        $v0, $t8, $a0
    ctx->r2 = ADD32(ctx->r24, ctx->r4);
    // 0x80044CDC: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x80044CE0: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80044CE4: lhu         $v1, 0x2($v0)
    ctx->r3 = MEM_HU(ctx->r2, 0X2);
    // 0x80044CE8: andi        $v0, $v1, 0xC000
    ctx->r2 = ctx->r3 & 0XC000;
    // 0x80044CEC: beql        $v0, $zero, L_80044CF4
    if (ctx->r2 == 0) {
        // 0x80044CF0: and         $t1, $t1, $t6
        ctx->r9 = ctx->r9 & ctx->r14;
            goto L_80044CF4;
    }
    goto skip_2;
    // 0x80044CF0: and         $t1, $t1, $t6
    ctx->r9 = ctx->r9 & ctx->r14;
    skip_2:
L_80044CF4:
    // 0x80044CF4: andi        $v0, $v1, 0x8000
    ctx->r2 = ctx->r3 & 0X8000;
    // 0x80044CF8: beql        $v0, $zero, L_80044D00
    if (ctx->r2 == 0) {
        // 0x80044CFC: and         $t1, $t1, $t5
        ctx->r9 = ctx->r9 & ctx->r13;
            goto L_80044D00;
    }
    goto skip_3;
    // 0x80044CFC: and         $t1, $t1, $t5
    ctx->r9 = ctx->r9 & ctx->r13;
    skip_3:
L_80044D00:
    // 0x80044D00: blez        $a1, L_80044D4C
    if (SIGNED(ctx->r5) <= 0) {
        // 0x80044D04: nop
    
            goto L_80044D4C;
    }
    // 0x80044D04: nop

    // 0x80044D08: lhu         $v0, 0x38($a2)
    ctx->r2 = MEM_HU(ctx->r6, 0X38);
    // 0x80044D0C: mult        $t3, $v0
    result = S64(S32(ctx->r11)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80044D10: lw          $v1, 0x6DC0($t0)
    ctx->r3 = MEM_W(ctx->r8, 0X6DC0);
    // 0x80044D14: mflo        $t8
    ctx->r24 = lo;
    // 0x80044D18: addu        $v0, $a0, $t8
    ctx->r2 = ADD32(ctx->r4, ctx->r24);
    // 0x80044D1C: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x80044D20: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80044D24: lhu         $v1, 0x0($v0)
    ctx->r3 = MEM_HU(ctx->r2, 0X0);
    // 0x80044D28: andi        $v0, $v1, 0xC000
    ctx->r2 = ctx->r3 & 0XC000;
    // 0x80044D2C: bne         $v0, $zero, L_80044D40
    if (ctx->r2 != 0) {
        // 0x80044D30: andi        $v0, $v1, 0x8000
        ctx->r2 = ctx->r3 & 0X8000;
            goto L_80044D40;
    }
    // 0x80044D30: andi        $v0, $v1, 0x8000
    ctx->r2 = ctx->r3 & 0X8000;
    // 0x80044D34: addiu       $v0, $zero, -0x41
    ctx->r2 = ADD32(0, -0X41);
    // 0x80044D38: and         $t1, $t1, $v0
    ctx->r9 = ctx->r9 & ctx->r2;
    // 0x80044D3C: andi        $v0, $v1, 0x8000
    ctx->r2 = ctx->r3 & 0X8000;
L_80044D40:
    // 0x80044D40: bne         $v0, $zero, L_80044D4C
    if (ctx->r2 != 0) {
        // 0x80044D44: addiu       $v0, $zero, -0x5
        ctx->r2 = ADD32(0, -0X5);
            goto L_80044D4C;
    }
    // 0x80044D44: addiu       $v0, $zero, -0x5
    ctx->r2 = ADD32(0, -0X5);
    // 0x80044D48: and         $t1, $t1, $v0
    ctx->r9 = ctx->r9 & ctx->r2;
L_80044D4C:
    // 0x80044D4C: lhu         $v0, 0x3A($a2)
    ctx->r2 = MEM_HU(ctx->r6, 0X3A);
    // 0x80044D50: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x80044D54: slt         $v0, $a1, $v0
    ctx->r2 = SIGNED(ctx->r5) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80044D58: beq         $v0, $zero, L_80044D98
    if (ctx->r2 == 0) {
        // 0x80044D5C: nop
    
            goto L_80044D98;
    }
    // 0x80044D5C: nop

    // 0x80044D60: lhu         $v0, 0x38($a2)
    ctx->r2 = MEM_HU(ctx->r6, 0X38);
    // 0x80044D64: mult        $t2, $v0
    result = S64(S32(ctx->r10)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80044D68: lw          $v1, 0x6DC0($t0)
    ctx->r3 = MEM_W(ctx->r8, 0X6DC0);
    // 0x80044D6C: mflo        $t8
    ctx->r24 = lo;
    // 0x80044D70: addu        $v0, $a0, $t8
    ctx->r2 = ADD32(ctx->r4, ctx->r24);
    // 0x80044D74: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x80044D78: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80044D7C: lhu         $v1, 0x0($v0)
    ctx->r3 = MEM_HU(ctx->r2, 0X0);
    // 0x80044D80: andi        $v0, $v1, 0xC000
    ctx->r2 = ctx->r3 & 0XC000;
    // 0x80044D84: beql        $v0, $zero, L_80044D8C
    if (ctx->r2 == 0) {
        // 0x80044D88: and         $t1, $t1, $t4
        ctx->r9 = ctx->r9 & ctx->r12;
            goto L_80044D8C;
    }
    goto skip_4;
    // 0x80044D88: and         $t1, $t1, $t4
    ctx->r9 = ctx->r9 & ctx->r12;
    skip_4:
L_80044D8C:
    // 0x80044D8C: andi        $v0, $v1, 0x8000
    ctx->r2 = ctx->r3 & 0X8000;
    // 0x80044D90: beql        $v0, $zero, L_80044D98
    if (ctx->r2 == 0) {
        // 0x80044D94: and         $t1, $t1, $t4
        ctx->r9 = ctx->r9 & ctx->r12;
            goto L_80044D98;
    }
    goto skip_5;
    // 0x80044D94: and         $t1, $t1, $t4
    ctx->r9 = ctx->r9 & ctx->r12;
    skip_5:
L_80044D98:
    // 0x80044D98: lhu         $v0, 0x0($a3)
    ctx->r2 = MEM_HU(ctx->r7, 0X0);
    // 0x80044D9C: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x80044DA0: andi        $v0, $v0, 0x1FFF
    ctx->r2 = ctx->r2 & 0X1FFF;
    // 0x80044DA4: addu        $v0, $s1, $v0
    ctx->r2 = ADD32(ctx->r17, ctx->r2);
    // 0x80044DA8: sb          $t1, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r9;
    // 0x80044DAC: lhu         $v0, 0x38($a2)
    ctx->r2 = MEM_HU(ctx->r6, 0X38);
    // 0x80044DB0: slt         $v0, $a0, $v0
    ctx->r2 = SIGNED(ctx->r4) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80044DB4: bne         $v0, $zero, L_80044C68
    if (ctx->r2 != 0) {
        // 0x80044DB8: addiu       $a3, $a3, 0x2
        ctx->r7 = ADD32(ctx->r7, 0X2);
            goto L_80044C68;
    }
    // 0x80044DB8: addiu       $a3, $a3, 0x2
    ctx->r7 = ADD32(ctx->r7, 0X2);
L_80044DBC:
    // 0x80044DBC: lhu         $v0, 0x3A($a2)
    ctx->r2 = MEM_HU(ctx->r6, 0X3A);
    // 0x80044DC0: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x80044DC4: slt         $v0, $a1, $v0
    ctx->r2 = SIGNED(ctx->r5) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80044DC8: bne         $v0, $zero, L_80044C54
    if (ctx->r2 != 0) {
        // 0x80044DCC: nop
    
            goto L_80044C54;
    }
    // 0x80044DCC: nop

L_80044DD0:
    // 0x80044DD0: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80044DD4: lw          $v0, 0x6FC4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X6FC4);
    // 0x80044DD8: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x80044DDC: lhu         $v0, 0x18($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X18);
    // 0x80044DE0: lw          $v1, 0x6DC4($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X6DC4);
    // 0x80044DE4: beq         $v0, $zero, L_800453AC
    if (ctx->r2 == 0) {
        // 0x80044DE8: addu        $t2, $zero, $zero
        ctx->r10 = ADD32(0, 0);
            goto L_800453AC;
    }
    // 0x80044DE8: addu        $t2, $zero, $zero
    ctx->r10 = ADD32(0, 0);
    // 0x80044DEC: lui         $t3, 0x5555
    ctx->r11 = S32(0X5555 << 16);
    // 0x80044DF0: ori         $t3, $t3, 0x5556
    ctx->r11 = ctx->r11 | 0X5556;
    // 0x80044DF4: addiu       $a3, $v1, 0x10
    ctx->r7 = ADD32(ctx->r3, 0X10);
L_80044DF8:
    // 0x80044DF8: addu        $v0, $s1, $t2
    ctx->r2 = ADD32(ctx->r17, ctx->r10);
    // 0x80044DFC: lbu         $v1, -0xE($a3)
    ctx->r3 = MEM_BU(ctx->r7, -0XE);
    // 0x80044E00: lbu         $t1, 0x0($v0)
    ctx->r9 = MEM_BU(ctx->r2, 0X0);
    // 0x80044E04: andi        $v0, $v1, 0x18
    ctx->r2 = ctx->r3 & 0X18;
    // 0x80044E08: bne         $v0, $zero, L_80045394
    if (ctx->r2 != 0) {
        // 0x80044E0C: lui         $v0, 0x8013
        ctx->r2 = S32(0X8013 << 16);
            goto L_80045394;
    }
    // 0x80044E0C: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80044E10: andi        $v0, $v1, 0x2
    ctx->r2 = ctx->r3 & 0X2;
    // 0x80044E14: beq         $v0, $zero, L_80045088
    if (ctx->r2 == 0) {
        // 0x80044E18: andi        $v0, $t1, 0x40
        ctx->r2 = ctx->r9 & 0X40;
            goto L_80045088;
    }
    // 0x80044E18: andi        $v0, $t1, 0x40
    ctx->r2 = ctx->r9 & 0X40;
    // 0x80044E1C: beq         $v0, $zero, L_80044E70
    if (ctx->r2 == 0) {
        // 0x80044E20: andi        $v0, $t1, 0x10
        ctx->r2 = ctx->r9 & 0X10;
            goto L_80044E70;
    }
    // 0x80044E20: andi        $v0, $t1, 0x10
    ctx->r2 = ctx->r9 & 0X10;
    // 0x80044E24: lb          $a0, -0x9($a3)
    ctx->r4 = MEM_B(ctx->r7, -0X9);
    // 0x80044E28: lb          $v0, -0xB($a3)
    ctx->r2 = MEM_B(ctx->r7, -0XB);
    // 0x80044E2C: lb          $v1, -0x7($a3)
    ctx->r3 = MEM_B(ctx->r7, -0X7);
    // 0x80044E30: lb          $a1, -0x9($a3)
    ctx->r5 = MEM_B(ctx->r7, -0X9);
    // 0x80044E34: subu        $a0, $a0, $v0
    ctx->r4 = SUB32(ctx->r4, ctx->r2);
    // 0x80044E38: srl         $v0, $a0, 31
    ctx->r2 = S32(U32(ctx->r4) >> 31);
    // 0x80044E3C: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // 0x80044E40: sra         $a0, $a0, 1
    ctx->r4 = S32(SIGNED(ctx->r4) >> 1);
    // 0x80044E44: lbu         $v0, -0xB($a3)
    ctx->r2 = MEM_BU(ctx->r7, -0XB);
    // 0x80044E48: subu        $v1, $v1, $a1
    ctx->r3 = SUB32(ctx->r3, ctx->r5);
    // 0x80044E4C: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x80044E50: sb          $v0, -0xA($a3)
    MEM_B(-0XA, ctx->r7) = ctx->r2;
    // 0x80044E54: srl         $v0, $v1, 31
    ctx->r2 = S32(U32(ctx->r3) >> 31);
    // 0x80044E58: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x80044E5C: lbu         $v0, -0x9($a3)
    ctx->r2 = MEM_BU(ctx->r7, -0X9);
    // 0x80044E60: sra         $v1, $v1, 1
    ctx->r3 = S32(SIGNED(ctx->r3) >> 1);
    // 0x80044E64: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80044E68: sb          $v0, -0x8($a3)
    MEM_B(-0X8, ctx->r7) = ctx->r2;
    // 0x80044E6C: andi        $v0, $t1, 0x10
    ctx->r2 = ctx->r9 & 0X10;
L_80044E70:
    // 0x80044E70: beq         $v0, $zero, L_80044EC4
    if (ctx->r2 == 0) {
        // 0x80044E74: andi        $v0, $t1, 0x20
        ctx->r2 = ctx->r9 & 0X20;
            goto L_80044EC4;
    }
    // 0x80044E74: andi        $v0, $t1, 0x20
    ctx->r2 = ctx->r9 & 0X20;
    // 0x80044E78: lb          $a0, -0x1($a3)
    ctx->r4 = MEM_B(ctx->r7, -0X1);
    // 0x80044E7C: lb          $v0, -0xB($a3)
    ctx->r2 = MEM_B(ctx->r7, -0XB);
    // 0x80044E80: lb          $v1, 0x9($a3)
    ctx->r3 = MEM_B(ctx->r7, 0X9);
    // 0x80044E84: lb          $a1, -0x1($a3)
    ctx->r5 = MEM_B(ctx->r7, -0X1);
    // 0x80044E88: subu        $a0, $a0, $v0
    ctx->r4 = SUB32(ctx->r4, ctx->r2);
    // 0x80044E8C: srl         $v0, $a0, 31
    ctx->r2 = S32(U32(ctx->r4) >> 31);
    // 0x80044E90: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // 0x80044E94: sra         $a0, $a0, 1
    ctx->r4 = S32(SIGNED(ctx->r4) >> 1);
    // 0x80044E98: lbu         $v0, -0xB($a3)
    ctx->r2 = MEM_BU(ctx->r7, -0XB);
    // 0x80044E9C: subu        $v1, $v1, $a1
    ctx->r3 = SUB32(ctx->r3, ctx->r5);
    // 0x80044EA0: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x80044EA4: sb          $v0, -0x6($a3)
    MEM_B(-0X6, ctx->r7) = ctx->r2;
    // 0x80044EA8: srl         $v0, $v1, 31
    ctx->r2 = S32(U32(ctx->r3) >> 31);
    // 0x80044EAC: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x80044EB0: lbu         $v0, -0x1($a3)
    ctx->r2 = MEM_BU(ctx->r7, -0X1);
    // 0x80044EB4: sra         $v1, $v1, 1
    ctx->r3 = S32(SIGNED(ctx->r3) >> 1);
    // 0x80044EB8: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80044EBC: sb          $v0, 0x4($a3)
    MEM_B(0X4, ctx->r7) = ctx->r2;
    // 0x80044EC0: andi        $v0, $t1, 0x20
    ctx->r2 = ctx->r9 & 0X20;
L_80044EC4:
    // 0x80044EC4: beq         $v0, $zero, L_80044F18
    if (ctx->r2 == 0) {
        // 0x80044EC8: andi        $v0, $t1, 0x80
        ctx->r2 = ctx->r9 & 0X80;
            goto L_80044F18;
    }
    // 0x80044EC8: andi        $v0, $t1, 0x80
    ctx->r2 = ctx->r9 & 0X80;
    // 0x80044ECC: lb          $a0, 0x3($a3)
    ctx->r4 = MEM_B(ctx->r7, 0X3);
    // 0x80044ED0: lb          $v0, -0x7($a3)
    ctx->r2 = MEM_B(ctx->r7, -0X7);
    // 0x80044ED4: lb          $v1, 0xD($a3)
    ctx->r3 = MEM_B(ctx->r7, 0XD);
    // 0x80044ED8: lb          $a1, 0x3($a3)
    ctx->r5 = MEM_B(ctx->r7, 0X3);
    // 0x80044EDC: subu        $a0, $a0, $v0
    ctx->r4 = SUB32(ctx->r4, ctx->r2);
    // 0x80044EE0: srl         $v0, $a0, 31
    ctx->r2 = S32(U32(ctx->r4) >> 31);
    // 0x80044EE4: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // 0x80044EE8: sra         $a0, $a0, 1
    ctx->r4 = S32(SIGNED(ctx->r4) >> 1);
    // 0x80044EEC: lbu         $v0, -0x7($a3)
    ctx->r2 = MEM_BU(ctx->r7, -0X7);
    // 0x80044EF0: subu        $v1, $v1, $a1
    ctx->r3 = SUB32(ctx->r3, ctx->r5);
    // 0x80044EF4: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x80044EF8: sb          $v0, -0x2($a3)
    MEM_B(-0X2, ctx->r7) = ctx->r2;
    // 0x80044EFC: srl         $v0, $v1, 31
    ctx->r2 = S32(U32(ctx->r3) >> 31);
    // 0x80044F00: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x80044F04: lbu         $v0, 0x3($a3)
    ctx->r2 = MEM_BU(ctx->r7, 0X3);
    // 0x80044F08: sra         $v1, $v1, 1
    ctx->r3 = S32(SIGNED(ctx->r3) >> 1);
    // 0x80044F0C: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80044F10: sb          $v0, 0x8($a3)
    MEM_B(0X8, ctx->r7) = ctx->r2;
    // 0x80044F14: andi        $v0, $t1, 0x80
    ctx->r2 = ctx->r9 & 0X80;
L_80044F18:
    // 0x80044F18: beq         $v0, $zero, L_80044F68
    if (ctx->r2 == 0) {
        // 0x80044F1C: nop
    
            goto L_80044F68;
    }
    // 0x80044F1C: nop

    // 0x80044F20: lb          $a0, 0xB($a3)
    ctx->r4 = MEM_B(ctx->r7, 0XB);
    // 0x80044F24: lb          $v0, 0x9($a3)
    ctx->r2 = MEM_B(ctx->r7, 0X9);
    // 0x80044F28: lb          $v1, 0xD($a3)
    ctx->r3 = MEM_B(ctx->r7, 0XD);
    // 0x80044F2C: lb          $a1, 0xB($a3)
    ctx->r5 = MEM_B(ctx->r7, 0XB);
    // 0x80044F30: subu        $a0, $a0, $v0
    ctx->r4 = SUB32(ctx->r4, ctx->r2);
    // 0x80044F34: srl         $v0, $a0, 31
    ctx->r2 = S32(U32(ctx->r4) >> 31);
    // 0x80044F38: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // 0x80044F3C: sra         $a0, $a0, 1
    ctx->r4 = S32(SIGNED(ctx->r4) >> 1);
    // 0x80044F40: lbu         $v0, 0x9($a3)
    ctx->r2 = MEM_BU(ctx->r7, 0X9);
    // 0x80044F44: subu        $v1, $v1, $a1
    ctx->r3 = SUB32(ctx->r3, ctx->r5);
    // 0x80044F48: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x80044F4C: sb          $v0, 0xA($a3)
    MEM_B(0XA, ctx->r7) = ctx->r2;
    // 0x80044F50: srl         $v0, $v1, 31
    ctx->r2 = S32(U32(ctx->r3) >> 31);
    // 0x80044F54: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x80044F58: lbu         $v0, 0xB($a3)
    ctx->r2 = MEM_BU(ctx->r7, 0XB);
    // 0x80044F5C: sra         $v1, $v1, 1
    ctx->r3 = S32(SIGNED(ctx->r3) >> 1);
    // 0x80044F60: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80044F64: sb          $v0, 0xC($a3)
    MEM_B(0XC, ctx->r7) = ctx->r2;
L_80044F68:
    // 0x80044F68: lb          $v1, 0x1($a3)
    ctx->r3 = MEM_B(ctx->r7, 0X1);
    // 0x80044F6C: lb          $v0, -0xB($a3)
    ctx->r2 = MEM_B(ctx->r7, -0XB);
    // 0x80044F70: lb          $a0, 0x1($a3)
    ctx->r4 = MEM_B(ctx->r7, 0X1);
    // 0x80044F74: lb          $a1, -0x9($a3)
    ctx->r5 = MEM_B(ctx->r7, -0X9);
    // 0x80044F78: subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // 0x80044F7C: srl         $v0, $v1, 31
    ctx->r2 = S32(U32(ctx->r3) >> 31);
    // 0x80044F80: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x80044F84: sra         $v1, $v1, 1
    ctx->r3 = S32(SIGNED(ctx->r3) >> 1);
    // 0x80044F88: lbu         $v0, -0xB($a3)
    ctx->r2 = MEM_BU(ctx->r7, -0XB);
    // 0x80044F8C: subu        $a0, $a0, $a1
    ctx->r4 = SUB32(ctx->r4, ctx->r5);
    // 0x80044F90: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80044F94: sb          $v0, -0x5($a3)
    MEM_B(-0X5, ctx->r7) = ctx->r2;
    // 0x80044F98: srl         $v0, $a0, 31
    ctx->r2 = S32(U32(ctx->r4) >> 31);
    // 0x80044F9C: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // 0x80044FA0: sra         $a0, $a0, 1
    ctx->r4 = S32(SIGNED(ctx->r4) >> 1);
    // 0x80044FA4: lbu         $v0, -0x9($a3)
    ctx->r2 = MEM_BU(ctx->r7, -0X9);
    // 0x80044FA8: lb          $v1, 0x3($a3)
    ctx->r3 = MEM_B(ctx->r7, 0X3);
    // 0x80044FAC: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x80044FB0: subu        $v1, $v1, $a1
    ctx->r3 = SUB32(ctx->r3, ctx->r5);
    // 0x80044FB4: sb          $v0, -0x4($a3)
    MEM_B(-0X4, ctx->r7) = ctx->r2;
    // 0x80044FB8: srl         $v0, $v1, 31
    ctx->r2 = S32(U32(ctx->r3) >> 31);
    // 0x80044FBC: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x80044FC0: sra         $v1, $v1, 1
    ctx->r3 = S32(SIGNED(ctx->r3) >> 1);
    // 0x80044FC4: lbu         $v0, -0x9($a3)
    ctx->r2 = MEM_BU(ctx->r7, -0X9);
    // 0x80044FC8: lb          $a0, 0x1($a3)
    ctx->r4 = MEM_B(ctx->r7, 0X1);
    // 0x80044FCC: lb          $a1, -0x1($a3)
    ctx->r5 = MEM_B(ctx->r7, -0X1);
    // 0x80044FD0: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80044FD4: subu        $a0, $a0, $a1
    ctx->r4 = SUB32(ctx->r4, ctx->r5);
    // 0x80044FD8: sb          $v0, -0x3($a3)
    MEM_B(-0X3, ctx->r7) = ctx->r2;
    // 0x80044FDC: srl         $v0, $a0, 31
    ctx->r2 = S32(U32(ctx->r4) >> 31);
    // 0x80044FE0: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // 0x80044FE4: sra         $a0, $a0, 1
    ctx->r4 = S32(SIGNED(ctx->r4) >> 1);
    // 0x80044FE8: lbu         $v0, -0x1($a3)
    ctx->r2 = MEM_BU(ctx->r7, -0X1);
    // 0x80044FEC: lb          $v1, 0x3($a3)
    ctx->r3 = MEM_B(ctx->r7, 0X3);
    // 0x80044FF0: lb          $a1, 0x1($a3)
    ctx->r5 = MEM_B(ctx->r7, 0X1);
    // 0x80044FF4: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x80044FF8: subu        $v1, $v1, $a1
    ctx->r3 = SUB32(ctx->r3, ctx->r5);
    // 0x80044FFC: sb          $v0, 0x0($a3)
    MEM_B(0X0, ctx->r7) = ctx->r2;
    // 0x80045000: srl         $v0, $v1, 31
    ctx->r2 = S32(U32(ctx->r3) >> 31);
    // 0x80045004: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x80045008: sra         $v1, $v1, 1
    ctx->r3 = S32(SIGNED(ctx->r3) >> 1);
    // 0x8004500C: lbu         $v0, 0x1($a3)
    ctx->r2 = MEM_BU(ctx->r7, 0X1);
    // 0x80045010: lb          $a0, 0xB($a3)
    ctx->r4 = MEM_B(ctx->r7, 0XB);
    // 0x80045014: lb          $a1, -0x1($a3)
    ctx->r5 = MEM_B(ctx->r7, -0X1);
    // 0x80045018: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8004501C: subu        $a0, $a0, $a1
    ctx->r4 = SUB32(ctx->r4, ctx->r5);
    // 0x80045020: sb          $v0, 0x2($a3)
    MEM_B(0X2, ctx->r7) = ctx->r2;
    // 0x80045024: srl         $v0, $a0, 31
    ctx->r2 = S32(U32(ctx->r4) >> 31);
    // 0x80045028: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // 0x8004502C: sra         $a0, $a0, 1
    ctx->r4 = S32(SIGNED(ctx->r4) >> 1);
    // 0x80045030: lbu         $v0, -0x1($a3)
    ctx->r2 = MEM_BU(ctx->r7, -0X1);
    // 0x80045034: lb          $a1, 0xB($a3)
    ctx->r5 = MEM_B(ctx->r7, 0XB);
    // 0x80045038: lb          $v1, 0x1($a3)
    ctx->r3 = MEM_B(ctx->r7, 0X1);
    // 0x8004503C: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x80045040: subu        $a1, $a1, $v1
    ctx->r5 = SUB32(ctx->r5, ctx->r3);
    // 0x80045044: sb          $v0, 0x5($a3)
    MEM_B(0X5, ctx->r7) = ctx->r2;
    // 0x80045048: srl         $v0, $a1, 31
    ctx->r2 = S32(U32(ctx->r5) >> 31);
    // 0x8004504C: addu        $a1, $a1, $v0
    ctx->r5 = ADD32(ctx->r5, ctx->r2);
    // 0x80045050: sra         $a1, $a1, 1
    ctx->r5 = S32(SIGNED(ctx->r5) >> 1);
    // 0x80045054: lbu         $v0, 0x1($a3)
    ctx->r2 = MEM_BU(ctx->r7, 0X1);
    // 0x80045058: lb          $v1, 0xD($a3)
    ctx->r3 = MEM_B(ctx->r7, 0XD);
    // 0x8004505C: lb          $a0, 0x1($a3)
    ctx->r4 = MEM_B(ctx->r7, 0X1);
    // 0x80045060: addu        $v0, $v0, $a1
    ctx->r2 = ADD32(ctx->r2, ctx->r5);
    // 0x80045064: subu        $v1, $v1, $a0
    ctx->r3 = SUB32(ctx->r3, ctx->r4);
    // 0x80045068: sb          $v0, 0x6($a3)
    MEM_B(0X6, ctx->r7) = ctx->r2;
    // 0x8004506C: srl         $v0, $v1, 31
    ctx->r2 = S32(U32(ctx->r3) >> 31);
    // 0x80045070: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x80045074: lbu         $v0, 0x1($a3)
    ctx->r2 = MEM_BU(ctx->r7, 0X1);
    // 0x80045078: sra         $v1, $v1, 1
    ctx->r3 = S32(SIGNED(ctx->r3) >> 1);
    // 0x8004507C: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80045080: j           L_80045390
    // 0x80045084: sb          $v0, 0x7($a3)
    MEM_B(0X7, ctx->r7) = ctx->r2;
        goto L_80045390;
    // 0x80045084: sb          $v0, 0x7($a3)
    MEM_B(0X7, ctx->r7) = ctx->r2;
L_80045088:
    // 0x80045088: andi        $v0, $v1, 0x1
    ctx->r2 = ctx->r3 & 0X1;
    // 0x8004508C: beq         $v0, $zero, L_80045390
    if (ctx->r2 == 0) {
        // 0x80045090: andi        $v0, $t1, 0x4
        ctx->r2 = ctx->r9 & 0X4;
            goto L_80045390;
    }
    // 0x80045090: andi        $v0, $t1, 0x4
    ctx->r2 = ctx->r9 & 0X4;
    // 0x80045094: beq         $v0, $zero, L_800450F4
    if (ctx->r2 == 0) {
        // 0x80045098: andi        $v0, $t1, 0x2
        ctx->r2 = ctx->r9 & 0X2;
            goto L_800450F4;
    }
    // 0x80045098: andi        $v0, $t1, 0x2
    ctx->r2 = ctx->r9 & 0X2;
    // 0x8004509C: lb          $t0, -0xB($a3)
    ctx->r8 = MEM_B(ctx->r7, -0XB);
    // 0x800450A0: lb          $v0, -0x7($a3)
    ctx->r2 = MEM_B(ctx->r7, -0X7);
    // 0x800450A4: subu        $a2, $v0, $t0
    ctx->r6 = SUB32(ctx->r2, ctx->r8);
    // 0x800450A8: bgez        $a2, L_800450B4
    if (SIGNED(ctx->r6) >= 0) {
        // 0x800450AC: addu        $a0, $a2, $zero
        ctx->r4 = ADD32(ctx->r6, 0);
            goto L_800450B4;
    }
    // 0x800450AC: addu        $a0, $a2, $zero
    ctx->r4 = ADD32(ctx->r6, 0);
    // 0x800450B0: addiu       $a0, $a2, 0x3
    ctx->r4 = ADD32(ctx->r6, 0X3);
L_800450B4:
    // 0x800450B4: sll         $v0, $a2, 1
    ctx->r2 = S32(ctx->r6 << 1);
    // 0x800450B8: addu        $v1, $v0, $a2
    ctx->r3 = ADD32(ctx->r2, ctx->r6);
    // 0x800450BC: sra         $v0, $a0, 2
    ctx->r2 = S32(SIGNED(ctx->r4) >> 2);
    // 0x800450C0: addu        $v0, $t0, $v0
    ctx->r2 = ADD32(ctx->r8, ctx->r2);
    // 0x800450C4: sb          $v0, -0xA($a3)
    MEM_B(-0XA, ctx->r7) = ctx->r2;
    // 0x800450C8: srl         $v0, $a2, 31
    ctx->r2 = S32(U32(ctx->r6) >> 31);
    // 0x800450CC: addu        $v0, $a2, $v0
    ctx->r2 = ADD32(ctx->r6, ctx->r2);
    // 0x800450D0: sra         $v0, $v0, 1
    ctx->r2 = S32(SIGNED(ctx->r2) >> 1);
    // 0x800450D4: addu        $v0, $t0, $v0
    ctx->r2 = ADD32(ctx->r8, ctx->r2);
    // 0x800450D8: bgez        $v1, L_800450E4
    if (SIGNED(ctx->r3) >= 0) {
        // 0x800450DC: sb          $v0, -0x9($a3)
        MEM_B(-0X9, ctx->r7) = ctx->r2;
            goto L_800450E4;
    }
    // 0x800450DC: sb          $v0, -0x9($a3)
    MEM_B(-0X9, ctx->r7) = ctx->r2;
    // 0x800450E0: addiu       $v1, $v1, 0x3
    ctx->r3 = ADD32(ctx->r3, 0X3);
L_800450E4:
    // 0x800450E4: sra         $v0, $v1, 2
    ctx->r2 = S32(SIGNED(ctx->r3) >> 2);
    // 0x800450E8: addu        $v0, $t0, $v0
    ctx->r2 = ADD32(ctx->r8, ctx->r2);
    // 0x800450EC: sb          $v0, -0x8($a3)
    MEM_B(-0X8, ctx->r7) = ctx->r2;
    // 0x800450F0: andi        $v0, $t1, 0x2
    ctx->r2 = ctx->r9 & 0X2;
L_800450F4:
    // 0x800450F4: beq         $v0, $zero, L_80045154
    if (ctx->r2 == 0) {
        // 0x800450F8: andi        $v0, $t1, 0x1
        ctx->r2 = ctx->r9 & 0X1;
            goto L_80045154;
    }
    // 0x800450F8: andi        $v0, $t1, 0x1
    ctx->r2 = ctx->r9 & 0X1;
    // 0x800450FC: lb          $t0, -0x7($a3)
    ctx->r8 = MEM_B(ctx->r7, -0X7);
    // 0x80045100: lb          $v0, 0xD($a3)
    ctx->r2 = MEM_B(ctx->r7, 0XD);
    // 0x80045104: subu        $a2, $v0, $t0
    ctx->r6 = SUB32(ctx->r2, ctx->r8);
    // 0x80045108: bgez        $a2, L_80045114
    if (SIGNED(ctx->r6) >= 0) {
        // 0x8004510C: addu        $a0, $a2, $zero
        ctx->r4 = ADD32(ctx->r6, 0);
            goto L_80045114;
    }
    // 0x8004510C: addu        $a0, $a2, $zero
    ctx->r4 = ADD32(ctx->r6, 0);
    // 0x80045110: addiu       $a0, $a2, 0x3
    ctx->r4 = ADD32(ctx->r6, 0X3);
L_80045114:
    // 0x80045114: sll         $v0, $a2, 1
    ctx->r2 = S32(ctx->r6 << 1);
    // 0x80045118: addu        $v1, $v0, $a2
    ctx->r3 = ADD32(ctx->r2, ctx->r6);
    // 0x8004511C: sra         $v0, $a0, 2
    ctx->r2 = S32(SIGNED(ctx->r4) >> 2);
    // 0x80045120: addu        $v0, $t0, $v0
    ctx->r2 = ADD32(ctx->r8, ctx->r2);
    // 0x80045124: sb          $v0, -0x2($a3)
    MEM_B(-0X2, ctx->r7) = ctx->r2;
    // 0x80045128: srl         $v0, $a2, 31
    ctx->r2 = S32(U32(ctx->r6) >> 31);
    // 0x8004512C: addu        $v0, $a2, $v0
    ctx->r2 = ADD32(ctx->r6, ctx->r2);
    // 0x80045130: sra         $v0, $v0, 1
    ctx->r2 = S32(SIGNED(ctx->r2) >> 1);
    // 0x80045134: addu        $v0, $t0, $v0
    ctx->r2 = ADD32(ctx->r8, ctx->r2);
    // 0x80045138: bgez        $v1, L_80045144
    if (SIGNED(ctx->r3) >= 0) {
        // 0x8004513C: sb          $v0, 0x3($a3)
        MEM_B(0X3, ctx->r7) = ctx->r2;
            goto L_80045144;
    }
    // 0x8004513C: sb          $v0, 0x3($a3)
    MEM_B(0X3, ctx->r7) = ctx->r2;
    // 0x80045140: addiu       $v1, $v1, 0x3
    ctx->r3 = ADD32(ctx->r3, 0X3);
L_80045144:
    // 0x80045144: sra         $v0, $v1, 2
    ctx->r2 = S32(SIGNED(ctx->r3) >> 2);
    // 0x80045148: addu        $v0, $t0, $v0
    ctx->r2 = ADD32(ctx->r8, ctx->r2);
    // 0x8004514C: sb          $v0, 0x8($a3)
    MEM_B(0X8, ctx->r7) = ctx->r2;
    // 0x80045150: andi        $v0, $t1, 0x1
    ctx->r2 = ctx->r9 & 0X1;
L_80045154:
    // 0x80045154: beq         $v0, $zero, L_800451B4
    if (ctx->r2 == 0) {
        // 0x80045158: andi        $v0, $t1, 0x8
        ctx->r2 = ctx->r9 & 0X8;
            goto L_800451B4;
    }
    // 0x80045158: andi        $v0, $t1, 0x8
    ctx->r2 = ctx->r9 & 0X8;
    // 0x8004515C: lb          $t0, -0xB($a3)
    ctx->r8 = MEM_B(ctx->r7, -0XB);
    // 0x80045160: lb          $v0, 0x9($a3)
    ctx->r2 = MEM_B(ctx->r7, 0X9);
    // 0x80045164: subu        $a2, $v0, $t0
    ctx->r6 = SUB32(ctx->r2, ctx->r8);
    // 0x80045168: bgez        $a2, L_80045174
    if (SIGNED(ctx->r6) >= 0) {
        // 0x8004516C: addu        $a0, $a2, $zero
        ctx->r4 = ADD32(ctx->r6, 0);
            goto L_80045174;
    }
    // 0x8004516C: addu        $a0, $a2, $zero
    ctx->r4 = ADD32(ctx->r6, 0);
    // 0x80045170: addiu       $a0, $a2, 0x3
    ctx->r4 = ADD32(ctx->r6, 0X3);
L_80045174:
    // 0x80045174: sll         $v0, $a2, 1
    ctx->r2 = S32(ctx->r6 << 1);
    // 0x80045178: addu        $v1, $v0, $a2
    ctx->r3 = ADD32(ctx->r2, ctx->r6);
    // 0x8004517C: sra         $v0, $a0, 2
    ctx->r2 = S32(SIGNED(ctx->r4) >> 2);
    // 0x80045180: addu        $v0, $t0, $v0
    ctx->r2 = ADD32(ctx->r8, ctx->r2);
    // 0x80045184: sb          $v0, -0x6($a3)
    MEM_B(-0X6, ctx->r7) = ctx->r2;
    // 0x80045188: srl         $v0, $a2, 31
    ctx->r2 = S32(U32(ctx->r6) >> 31);
    // 0x8004518C: addu        $v0, $a2, $v0
    ctx->r2 = ADD32(ctx->r6, ctx->r2);
    // 0x80045190: sra         $v0, $v0, 1
    ctx->r2 = S32(SIGNED(ctx->r2) >> 1);
    // 0x80045194: addu        $v0, $t0, $v0
    ctx->r2 = ADD32(ctx->r8, ctx->r2);
    // 0x80045198: bgez        $v1, L_800451A4
    if (SIGNED(ctx->r3) >= 0) {
        // 0x8004519C: sb          $v0, -0x1($a3)
        MEM_B(-0X1, ctx->r7) = ctx->r2;
            goto L_800451A4;
    }
    // 0x8004519C: sb          $v0, -0x1($a3)
    MEM_B(-0X1, ctx->r7) = ctx->r2;
    // 0x800451A0: addiu       $v1, $v1, 0x3
    ctx->r3 = ADD32(ctx->r3, 0X3);
L_800451A4:
    // 0x800451A4: sra         $v0, $v1, 2
    ctx->r2 = S32(SIGNED(ctx->r3) >> 2);
    // 0x800451A8: addu        $v0, $t0, $v0
    ctx->r2 = ADD32(ctx->r8, ctx->r2);
    // 0x800451AC: sb          $v0, 0x4($a3)
    MEM_B(0X4, ctx->r7) = ctx->r2;
    // 0x800451B0: andi        $v0, $t1, 0x8
    ctx->r2 = ctx->r9 & 0X8;
L_800451B4:
    // 0x800451B4: beq         $v0, $zero, L_80045210
    if (ctx->r2 == 0) {
        // 0x800451B8: nop
    
            goto L_80045210;
    }
    // 0x800451B8: nop

    // 0x800451BC: lb          $t0, 0x9($a3)
    ctx->r8 = MEM_B(ctx->r7, 0X9);
    // 0x800451C0: lb          $v0, 0xD($a3)
    ctx->r2 = MEM_B(ctx->r7, 0XD);
    // 0x800451C4: subu        $a2, $v0, $t0
    ctx->r6 = SUB32(ctx->r2, ctx->r8);
    // 0x800451C8: bgez        $a2, L_800451D4
    if (SIGNED(ctx->r6) >= 0) {
        // 0x800451CC: addu        $a0, $a2, $zero
        ctx->r4 = ADD32(ctx->r6, 0);
            goto L_800451D4;
    }
    // 0x800451CC: addu        $a0, $a2, $zero
    ctx->r4 = ADD32(ctx->r6, 0);
    // 0x800451D0: addiu       $a0, $a2, 0x3
    ctx->r4 = ADD32(ctx->r6, 0X3);
L_800451D4:
    // 0x800451D4: sll         $v0, $a2, 1
    ctx->r2 = S32(ctx->r6 << 1);
    // 0x800451D8: addu        $v1, $v0, $a2
    ctx->r3 = ADD32(ctx->r2, ctx->r6);
    // 0x800451DC: sra         $v0, $a0, 2
    ctx->r2 = S32(SIGNED(ctx->r4) >> 2);
    // 0x800451E0: addu        $v0, $t0, $v0
    ctx->r2 = ADD32(ctx->r8, ctx->r2);
    // 0x800451E4: sb          $v0, 0xA($a3)
    MEM_B(0XA, ctx->r7) = ctx->r2;
    // 0x800451E8: srl         $v0, $a2, 31
    ctx->r2 = S32(U32(ctx->r6) >> 31);
    // 0x800451EC: addu        $v0, $a2, $v0
    ctx->r2 = ADD32(ctx->r6, ctx->r2);
    // 0x800451F0: sra         $v0, $v0, 1
    ctx->r2 = S32(SIGNED(ctx->r2) >> 1);
    // 0x800451F4: addu        $v0, $t0, $v0
    ctx->r2 = ADD32(ctx->r8, ctx->r2);
    // 0x800451F8: bgez        $v1, L_80045204
    if (SIGNED(ctx->r3) >= 0) {
        // 0x800451FC: sb          $v0, 0xB($a3)
        MEM_B(0XB, ctx->r7) = ctx->r2;
            goto L_80045204;
    }
    // 0x800451FC: sb          $v0, 0xB($a3)
    MEM_B(0XB, ctx->r7) = ctx->r2;
    // 0x80045200: addiu       $v1, $v1, 0x3
    ctx->r3 = ADD32(ctx->r3, 0X3);
L_80045204:
    // 0x80045204: sra         $v0, $v1, 2
    ctx->r2 = S32(SIGNED(ctx->r3) >> 2);
    // 0x80045208: addu        $v0, $t0, $v0
    ctx->r2 = ADD32(ctx->r8, ctx->r2);
    // 0x8004520C: sb          $v0, 0xC($a3)
    MEM_B(0XC, ctx->r7) = ctx->r2;
L_80045210:
    // 0x80045210: lb          $t0, -0xB($a3)
    ctx->r8 = MEM_B(ctx->r7, -0XB);
    // 0x80045214: lb          $v0, 0xD($a3)
    ctx->r2 = MEM_B(ctx->r7, 0XD);
    // 0x80045218: subu        $a2, $v0, $t0
    ctx->r6 = SUB32(ctx->r2, ctx->r8);
    // 0x8004521C: bgez        $a2, L_80045228
    if (SIGNED(ctx->r6) >= 0) {
        // 0x80045220: addu        $a0, $a2, $zero
        ctx->r4 = ADD32(ctx->r6, 0);
            goto L_80045228;
    }
    // 0x80045220: addu        $a0, $a2, $zero
    ctx->r4 = ADD32(ctx->r6, 0);
    // 0x80045224: addiu       $a0, $a2, 0x3
    ctx->r4 = ADD32(ctx->r6, 0X3);
L_80045228:
    // 0x80045228: sll         $v0, $a2, 1
    ctx->r2 = S32(ctx->r6 << 1);
    // 0x8004522C: addu        $v1, $v0, $a2
    ctx->r3 = ADD32(ctx->r2, ctx->r6);
    // 0x80045230: sra         $v0, $a0, 2
    ctx->r2 = S32(SIGNED(ctx->r4) >> 2);
    // 0x80045234: addu        $v0, $t0, $v0
    ctx->r2 = ADD32(ctx->r8, ctx->r2);
    // 0x80045238: sb          $v0, -0x5($a3)
    MEM_B(-0X5, ctx->r7) = ctx->r2;
    // 0x8004523C: srl         $v0, $a2, 31
    ctx->r2 = S32(U32(ctx->r6) >> 31);
    // 0x80045240: addu        $v0, $a2, $v0
    ctx->r2 = ADD32(ctx->r6, ctx->r2);
    // 0x80045244: sra         $v0, $v0, 1
    ctx->r2 = S32(SIGNED(ctx->r2) >> 1);
    // 0x80045248: addu        $v0, $t0, $v0
    ctx->r2 = ADD32(ctx->r8, ctx->r2);
    // 0x8004524C: bgez        $v1, L_80045258
    if (SIGNED(ctx->r3) >= 0) {
        // 0x80045250: sb          $v0, 0x1($a3)
        MEM_B(0X1, ctx->r7) = ctx->r2;
            goto L_80045258;
    }
    // 0x80045250: sb          $v0, 0x1($a3)
    MEM_B(0X1, ctx->r7) = ctx->r2;
    // 0x80045254: addiu       $v1, $v1, 0x3
    ctx->r3 = ADD32(ctx->r3, 0X3);
L_80045258:
    // 0x80045258: sra         $v0, $v1, 2
    ctx->r2 = S32(SIGNED(ctx->r3) >> 2);
    // 0x8004525C: lb          $v1, 0xD($a3)
    ctx->r3 = MEM_B(ctx->r7, 0XD);
    // 0x80045260: lb          $a0, -0x7($a3)
    ctx->r4 = MEM_B(ctx->r7, -0X7);
    // 0x80045264: addu        $v0, $t0, $v0
    ctx->r2 = ADD32(ctx->r8, ctx->r2);
    // 0x80045268: sb          $v0, 0x7($a3)
    MEM_B(0X7, ctx->r7) = ctx->r2;
    // 0x8004526C: subu        $v0, $v1, $a0
    ctx->r2 = SUB32(ctx->r3, ctx->r4);
    // 0x80045270: bltzl       $v0, L_80045278
    if (SIGNED(ctx->r2) < 0) {
        // 0x80045274: addiu       $v0, $v0, 0x3
        ctx->r2 = ADD32(ctx->r2, 0X3);
            goto L_80045278;
    }
    goto skip_6;
    // 0x80045274: addiu       $v0, $v0, 0x3
    ctx->r2 = ADD32(ctx->r2, 0X3);
    skip_6:
L_80045278:
    // 0x80045278: sra         $v0, $v0, 2
    ctx->r2 = S32(SIGNED(ctx->r2) >> 2);
    // 0x8004527C: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x80045280: lb          $t0, -0x5($a3)
    ctx->r8 = MEM_B(ctx->r7, -0X5);
    // 0x80045284: lb          $v1, 0x9($a3)
    ctx->r3 = MEM_B(ctx->r7, 0X9);
    // 0x80045288: lb          $t1, -0xB($a3)
    ctx->r9 = MEM_B(ctx->r7, -0XB);
    // 0x8004528C: lb          $a1, -0x7($a3)
    ctx->r5 = MEM_B(ctx->r7, -0X7);
    // 0x80045290: subu        $a2, $v0, $t0
    ctx->r6 = SUB32(ctx->r2, ctx->r8);
    // 0x80045294: subu        $v1, $v1, $t1
    ctx->r3 = SUB32(ctx->r3, ctx->r9);
    // 0x80045298: sll         $a0, $v1, 1
    ctx->r4 = S32(ctx->r3 << 1);
    // 0x8004529C: addu        $a0, $a0, $v1
    ctx->r4 = ADD32(ctx->r4, ctx->r3);
    // 0x800452A0: lb          $v0, 0xD($a3)
    ctx->r2 = MEM_B(ctx->r7, 0XD);
    // 0x800452A4: mult        $a2, $t3
    result = S64(S32(ctx->r6)) * S64(S32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800452A8: subu        $v0, $v0, $a1
    ctx->r2 = SUB32(ctx->r2, ctx->r5);
    // 0x800452AC: srl         $v1, $v0, 31
    ctx->r3 = S32(U32(ctx->r2) >> 31);
    // 0x800452B0: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800452B4: sra         $v0, $v0, 1
    ctx->r2 = S32(SIGNED(ctx->r2) >> 1);
    // 0x800452B8: lb          $v1, 0x1($a3)
    ctx->r3 = MEM_B(ctx->r7, 0X1);
    // 0x800452BC: addu        $v0, $v0, $a1
    ctx->r2 = ADD32(ctx->r2, ctx->r5);
    // 0x800452C0: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x800452C4: srl         $v1, $v0, 31
    ctx->r3 = S32(U32(ctx->r2) >> 31);
    // 0x800452C8: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800452CC: lbu         $v1, 0x1($a3)
    ctx->r3 = MEM_BU(ctx->r7, 0X1);
    // 0x800452D0: sra         $v0, $v0, 1
    ctx->r2 = S32(SIGNED(ctx->r2) >> 1);
    // 0x800452D4: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x800452D8: sb          $v1, 0x2($a3)
    MEM_B(0X2, ctx->r7) = ctx->r3;
    // 0x800452DC: sra         $v1, $a2, 31
    ctx->r3 = S32(SIGNED(ctx->r6) >> 31);
    // 0x800452E0: mfhi        $a1
    ctx->r5 = hi;
    // 0x800452E4: sll         $v0, $a2, 1
    ctx->r2 = S32(ctx->r6 << 1);
    // 0x800452E8: subu        $v1, $a1, $v1
    ctx->r3 = SUB32(ctx->r5, ctx->r3);
    // 0x800452EC: mult        $v0, $t3
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800452F0: addu        $v1, $t0, $v1
    ctx->r3 = ADD32(ctx->r8, ctx->r3);
    // 0x800452F4: sra         $v0, $v0, 31
    ctx->r2 = S32(SIGNED(ctx->r2) >> 31);
    // 0x800452F8: sb          $v1, -0x4($a3)
    MEM_B(-0X4, ctx->r7) = ctx->r3;
    // 0x800452FC: lb          $v1, 0x7($a3)
    ctx->r3 = MEM_B(ctx->r7, 0X7);
    // 0x80045300: mfhi        $t4
    ctx->r12 = hi;
    // 0x80045304: subu        $v0, $t4, $v0
    ctx->r2 = SUB32(ctx->r12, ctx->r2);
    // 0x80045308: addu        $v0, $t0, $v0
    ctx->r2 = ADD32(ctx->r8, ctx->r2);
    // 0x8004530C: bgez        $a0, L_80045318
    if (SIGNED(ctx->r4) >= 0) {
        // 0x80045310: sb          $v0, -0x3($a3)
        MEM_B(-0X3, ctx->r7) = ctx->r2;
            goto L_80045318;
    }
    // 0x80045310: sb          $v0, -0x3($a3)
    MEM_B(-0X3, ctx->r7) = ctx->r2;
    // 0x80045314: addiu       $a0, $a0, 0x3
    ctx->r4 = ADD32(ctx->r4, 0X3);
L_80045318:
    // 0x80045318: sra         $v0, $a0, 2
    ctx->r2 = S32(SIGNED(ctx->r4) >> 2);
    // 0x8004531C: addu        $t0, $v0, $t1
    ctx->r8 = ADD32(ctx->r2, ctx->r9);
    // 0x80045320: subu        $a2, $v1, $t0
    ctx->r6 = SUB32(ctx->r3, ctx->r8);
    // 0x80045324: mult        $a2, $t3
    result = S64(S32(ctx->r6)) * S64(S32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80045328: sll         $a0, $a2, 1
    ctx->r4 = S32(ctx->r6 << 1);
    // 0x8004532C: sra         $a1, $a2, 31
    ctx->r5 = S32(SIGNED(ctx->r6) >> 31);
    // 0x80045330: lb          $a2, -0xB($a3)
    ctx->r6 = MEM_B(ctx->r7, -0XB);
    // 0x80045334: mfhi        $v1
    ctx->r3 = hi;
    // 0x80045338: subu        $a1, $v1, $a1
    ctx->r5 = SUB32(ctx->r3, ctx->r5);
    // 0x8004533C: addu        $a1, $t0, $a1
    ctx->r5 = ADD32(ctx->r8, ctx->r5);
    // 0x80045340: mult        $a0, $t3
    result = S64(S32(ctx->r4)) * S64(S32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80045344: lb          $v1, 0x9($a3)
    ctx->r3 = MEM_B(ctx->r7, 0X9);
    // 0x80045348: sra         $a0, $a0, 31
    ctx->r4 = S32(SIGNED(ctx->r4) >> 31);
    // 0x8004534C: sb          $a1, 0x5($a3)
    MEM_B(0X5, ctx->r7) = ctx->r5;
    // 0x80045350: subu        $v1, $v1, $a2
    ctx->r3 = SUB32(ctx->r3, ctx->r6);
    // 0x80045354: mfhi        $v0
    ctx->r2 = hi;
    // 0x80045358: subu        $a0, $v0, $a0
    ctx->r4 = SUB32(ctx->r2, ctx->r4);
    // 0x8004535C: addu        $a0, $t0, $a0
    ctx->r4 = ADD32(ctx->r8, ctx->r4);
    // 0x80045360: srl         $v0, $v1, 31
    ctx->r2 = S32(U32(ctx->r3) >> 31);
    // 0x80045364: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x80045368: sra         $v1, $v1, 1
    ctx->r3 = S32(SIGNED(ctx->r3) >> 1);
    // 0x8004536C: lb          $v0, 0x1($a3)
    ctx->r2 = MEM_B(ctx->r7, 0X1);
    // 0x80045370: addu        $t0, $v1, $a2
    ctx->r8 = ADD32(ctx->r3, ctx->r6);
    // 0x80045374: sb          $a0, 0x6($a3)
    MEM_B(0X6, ctx->r7) = ctx->r4;
    // 0x80045378: subu        $v0, $v0, $t0
    ctx->r2 = SUB32(ctx->r2, ctx->r8);
    // 0x8004537C: srl         $v1, $v0, 31
    ctx->r3 = S32(U32(ctx->r2) >> 31);
    // 0x80045380: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80045384: sra         $v0, $v0, 1
    ctx->r2 = S32(SIGNED(ctx->r2) >> 1);
    // 0x80045388: addu        $v0, $t0, $v0
    ctx->r2 = ADD32(ctx->r8, ctx->r2);
    // 0x8004538C: sb          $v0, 0x0($a3)
    MEM_B(0X0, ctx->r7) = ctx->r2;
L_80045390:
    // 0x80045390: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
L_80045394:
    // 0x80045394: lw          $v0, 0x6FC4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X6FC4);
    // 0x80045398: addiu       $t2, $t2, 0x1
    ctx->r10 = ADD32(ctx->r10, 0X1);
    // 0x8004539C: lhu         $v0, 0x18($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X18);
    // 0x800453A0: slt         $v0, $t2, $v0
    ctx->r2 = SIGNED(ctx->r10) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800453A4: bne         $v0, $zero, L_80044DF8
    if (ctx->r2 != 0) {
        // 0x800453A8: addiu       $a3, $a3, 0x1E
        ctx->r7 = ADD32(ctx->r7, 0X1E);
            goto L_80044DF8;
    }
    // 0x800453A8: addiu       $a3, $a3, 0x1E
    ctx->r7 = ADD32(ctx->r7, 0X1E);
L_800453AC:
    // 0x800453AC: jal         0x80001C98
    // 0x800453B0: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    rs_free(rdram, ctx);
        goto after_2;
    // 0x800453B0: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    after_2:
    // 0x800453B4: lw          $ra, 0x18($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X18);
    // 0x800453B8: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x800453BC: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x800453C0: jr          $ra
    // 0x800453C4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x800453C4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
