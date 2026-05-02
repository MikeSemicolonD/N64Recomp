#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void func_800EFDE0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800EFDE0: addiu       $sp, $sp, -0x90
    ctx->r29 = ADD32(ctx->r29, -0X90);
    // 0x800EFDE4: sw          $s3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r19;
    // 0x800EFDE8: sw          $s2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r18;
    // 0x800EFDEC: sw          $a0, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->r4;
    // 0x800EFDF0: addiu       $s2, $a0, 0x114
    ctx->r18 = ADD32(ctx->r4, 0X114);
    // 0x800EFDF4: sw          $ra, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r31;
    // 0x800EFDF8: sw          $fp, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r30;
    // 0x800EFDFC: sw          $s7, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r23;
    // 0x800EFE00: sw          $s6, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r22;
    // 0x800EFE04: sw          $s5, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r21;
    // 0x800EFE08: sw          $s4, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r20;
    // 0x800EFE0C: sw          $s1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r17;
    // 0x800EFE10: sw          $s0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r16;
    // 0x800EFE14: sdc1        $f28, 0x88($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0X88, ctx->r29);
    // 0x800EFE18: sdc1        $f26, 0x80($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X80, ctx->r29);
    // 0x800EFE1C: sdc1        $f24, 0x78($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X78, ctx->r29);
    // 0x800EFE20: sdc1        $f22, 0x70($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X70, ctx->r29);
    // 0x800EFE24: sdc1        $f20, 0x68($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X68, ctx->r29);
    // 0x800EFE28: sw          $a2, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->r6;
    // 0x800EFE2C: lbu         $v0, 0x21($s2)
    ctx->r2 = MEM_BU(ctx->r18, 0X21);
    // 0x800EFE30: mtc1        $a3, $f2
    ctx->f2.u32l = ctx->r7;
    // 0x800EFE34: beq         $v0, $zero, L_800F0674
    if (ctx->r2 == 0) {
        // 0x800EFE38: addu        $s3, $a1, $zero
        ctx->r19 = ADD32(ctx->r5, 0);
            goto L_800F0674;
    }
    // 0x800EFE38: addu        $s3, $a1, $zero
    ctx->r19 = ADD32(ctx->r5, 0);
    // 0x800EFE3C: lwc1        $f0, 0x10($s2)
    ctx->f0.u32l = MEM_W(ctx->r18, 0X10);
    // 0x800EFE40: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x800EFE44: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x800EFE48: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x800EFE4C: nop

    // 0x800EFE50: bc1t        L_800F0674
    if (c1cs) {
        // 0x800EFE54: swc1        $f0, 0x10($s2)
        MEM_W(0X10, ctx->r18) = ctx->f0.u32l;
            goto L_800F0674;
    }
    // 0x800EFE54: swc1        $f0, 0x10($s2)
    MEM_W(0X10, ctx->r18) = ctx->f0.u32l;
    // 0x800EFE58: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800EFE5C: lwc1        $f0, -0x7690($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X7690);
    // 0x800EFE60: lw          $a0, 0x14($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X14);
    // 0x800EFE64: beq         $a0, $zero, L_800EFF58
    if (ctx->r4 == 0) {
        // 0x800EFE68: swc1        $f0, 0x10($s2)
        MEM_W(0X10, ctx->r18) = ctx->f0.u32l;
            goto L_800EFF58;
    }
    // 0x800EFE68: swc1        $f0, 0x10($s2)
    MEM_W(0X10, ctx->r18) = ctx->f0.u32l;
    // 0x800EFE6C: jal         0x80047B48
    // 0x800EFE70: nop

    getLevelDatItemByName(rdram, ctx);
        goto after_0;
    // 0x800EFE70: nop

    after_0:
    // 0x800EFE74: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    // 0x800EFE78: beq         $s0, $zero, L_800EFF58
    if (ctx->r16 == 0) {
        // 0x800EFE7C: ori         $s1, $zero, 0xFFFF
        ctx->r17 = 0 | 0XFFFF;
            goto L_800EFF58;
    }
    // 0x800EFE7C: ori         $s1, $zero, 0xFFFF
    ctx->r17 = 0 | 0XFFFF;
    // 0x800EFE80: lhu         $v0, 0x6($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X6);
    // 0x800EFE84: beq         $v0, $s1, L_800EFF58
    if (ctx->r2 == ctx->r17) {
        // 0x800EFE88: nop
    
            goto L_800EFF58;
    }
    // 0x800EFE88: nop

    // 0x800EFE8C: jal         0x8004013C
    // 0x800EFE90: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    func_8004013C(rdram, ctx);
        goto after_1;
    // 0x800EFE90: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    after_1:
    // 0x800EFE94: lhu         $v0, 0x14($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X14);
    // 0x800EFE98: andi        $v0, $v0, 0x10
    ctx->r2 = ctx->r2 & 0X10;
    // 0x800EFE9C: bne         $v0, $zero, L_800EFF58
    if (ctx->r2 != 0) {
        // 0x800EFEA0: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_800EFF58;
    }
    // 0x800EFEA0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800EFEA4: lbu         $v1, 0x20($s2)
    ctx->r3 = MEM_BU(ctx->r18, 0X20);
    // 0x800EFEA8: bne         $v1, $v0, L_800EFEF8
    if (ctx->r3 != ctx->r2) {
        // 0x800EFEAC: nop
    
            goto L_800EFEF8;
    }
    // 0x800EFEAC: nop

    // 0x800EFEB0: lhu         $v0, 0x1A($s2)
    ctx->r2 = MEM_HU(ctx->r18, 0X1A);
    // 0x800EFEB4: beq         $v0, $s1, L_800EFEF8
    if (ctx->r2 == ctx->r17) {
        // 0x800EFEB8: nop
    
            goto L_800EFEF8;
    }
    // 0x800EFEB8: nop

    // 0x800EFEBC: lhu         $a0, 0x1C($s2)
    ctx->r4 = MEM_HU(ctx->r18, 0X1C);
    // 0x800EFEC0: jal         0x8003FC28
    // 0x800EFEC4: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    func_8003FC28(rdram, ctx);
        goto after_2;
    // 0x800EFEC4: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    after_2:
    // 0x800EFEC8: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x800EFECC: beql        $v0, $s1, L_800EFEF0
    if (ctx->r2 == ctx->r17) {
        // 0x800EFED0: sh          $s1, 0x1A($s2)
        MEM_H(0X1A, ctx->r18) = ctx->r17;
            goto L_800EFEF0;
    }
    goto skip_0;
    // 0x800EFED0: sh          $s1, 0x1A($s2)
    MEM_H(0X1A, ctx->r18) = ctx->r17;
    skip_0:
    // 0x800EFED4: lhu         $a0, 0x1E($s2)
    ctx->r4 = MEM_HU(ctx->r18, 0X1E);
    // 0x800EFED8: jal         0x8004013C
    // 0x800EFEDC: nop

    func_8004013C(rdram, ctx);
        goto after_3;
    // 0x800EFEDC: nop

    after_3:
    // 0x800EFEE0: lhu         $a0, 0x1E($s2)
    ctx->r4 = MEM_HU(ctx->r18, 0X1E);
    // 0x800EFEE4: jal         0x8003E7D0
    // 0x800EFEE8: addu        $a1, $v0, $zero
    ctx->r5 = ADD32(ctx->r2, 0);
    func_8003E7D0(rdram, ctx);
        goto after_4;
    // 0x800EFEE8: addu        $a1, $v0, $zero
    ctx->r5 = ADD32(ctx->r2, 0);
    after_4:
    // 0x800EFEEC: sh          $s1, 0x1A($s2)
    MEM_H(0X1A, ctx->r18) = ctx->r17;
L_800EFEF0:
    // 0x800EFEF0: sh          $s1, 0x1E($s2)
    MEM_H(0X1E, ctx->r18) = ctx->r17;
    // 0x800EFEF4: sb          $zero, 0x20($s2)
    MEM_B(0X20, ctx->r18) = 0;
L_800EFEF8:
    // 0x800EFEF8: lhu         $s0, 0x6($s0)
    ctx->r16 = MEM_HU(ctx->r16, 0X6);
    // 0x800EFEFC: ori         $s1, $zero, 0xFFFF
    ctx->r17 = 0 | 0XFFFF;
    // 0x800EFF00: andi        $a0, $s0, 0xFFFF
    ctx->r4 = ctx->r16 & 0XFFFF;
    // 0x800EFF04: beq         $a0, $s1, L_800EFF4C
    if (ctx->r4 == ctx->r17) {
        // 0x800EFF08: addu        $v1, $zero, $zero
        ctx->r3 = ADD32(0, 0);
            goto L_800EFF4C;
    }
    // 0x800EFF08: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
    // 0x800EFF0C: jal         0x8004013C
    // 0x800EFF10: nop

    func_8004013C(rdram, ctx);
        goto after_5;
    // 0x800EFF10: nop

    after_5:
    // 0x800EFF14: lhu         $a0, 0x1C($s2)
    ctx->r4 = MEM_HU(ctx->r18, 0X1C);
    // 0x800EFF18: jal         0x8003E684
    // 0x800EFF1C: addu        $a1, $v0, $zero
    ctx->r5 = ADD32(ctx->r2, 0);
    func_8003E684(rdram, ctx);
        goto after_6;
    // 0x800EFF1C: addu        $a1, $v0, $zero
    ctx->r5 = ADD32(ctx->r2, 0);
    after_6:
    // 0x800EFF20: sh          $v0, 0x1E($s2)
    MEM_H(0X1E, ctx->r18) = ctx->r2;
    // 0x800EFF24: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x800EFF28: beq         $v0, $s1, L_800EFF40
    if (ctx->r2 == ctx->r17) {
        // 0x800EFF2C: addiu       $v1, $zero, 0x1
        ctx->r3 = ADD32(0, 0X1);
            goto L_800EFF40;
    }
    // 0x800EFF2C: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x800EFF30: addu        $v0, $v1, $zero
    ctx->r2 = ADD32(ctx->r3, 0);
    // 0x800EFF34: sh          $s0, 0x1A($s2)
    MEM_H(0X1A, ctx->r18) = ctx->r16;
    // 0x800EFF38: j           L_800EFF4C
    // 0x800EFF3C: sb          $v0, 0x20($s2)
    MEM_B(0X20, ctx->r18) = ctx->r2;
        goto L_800EFF4C;
    // 0x800EFF3C: sb          $v0, 0x20($s2)
    MEM_B(0X20, ctx->r18) = ctx->r2;
L_800EFF40:
    // 0x800EFF40: sh          $v0, 0x1A($s2)
    MEM_H(0X1A, ctx->r18) = ctx->r2;
    // 0x800EFF44: sb          $zero, 0x20($s2)
    MEM_B(0X20, ctx->r18) = 0;
    // 0x800EFF48: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
L_800EFF4C:
    // 0x800EFF4C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800EFF50: beq         $v1, $v0, L_800F0678
    if (ctx->r3 == ctx->r2) {
        // 0x800EFF54: nop
    
            goto L_800F0678;
    }
    // 0x800EFF54: nop

L_800EFF58:
    // 0x800EFF58: lb          $v0, 0x18($s2)
    ctx->r2 = MEM_B(ctx->r18, 0X18);
    // 0x800EFF5C: addiu       $v1, $zero, 0x6
    ctx->r3 = ADD32(0, 0X6);
    // 0x800EFF60: bnel        $v0, $v1, L_800EFF68
    if (ctx->r2 != ctx->r3) {
        // 0x800EFF64: addu        $s3, $v0, $zero
        ctx->r19 = ADD32(ctx->r2, 0);
            goto L_800EFF68;
    }
    goto skip_1;
    // 0x800EFF64: addu        $s3, $v0, $zero
    ctx->r19 = ADD32(ctx->r2, 0);
    skip_1:
L_800EFF68:
    // 0x800EFF68: lb          $v0, 0x19($s2)
    ctx->r2 = MEM_B(ctx->r18, 0X19);
    // 0x800EFF6C: bnel        $v0, $v1, L_800EFF74
    if (ctx->r2 != ctx->r3) {
        // 0x800EFF70: sw          $v0, 0x98($sp)
        MEM_W(0X98, ctx->r29) = ctx->r2;
            goto L_800EFF74;
    }
    goto skip_2;
    // 0x800EFF70: sw          $v0, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->r2;
    skip_2:
L_800EFF74:
    // 0x800EFF74: addiu       $s7, $zero, 0x1
    ctx->r23 = ADD32(0, 0X1);
    // 0x800EFF78: addu        $fp, $zero, $zero
    ctx->r30 = ADD32(0, 0);
    // 0x800EFF7C: sltiu       $v0, $s3, 0xB
    ctx->r2 = ctx->r19 < 0XB ? 1 : 0;
    // 0x800EFF80: beq         $v0, $zero, L_800F0124
    if (ctx->r2 == 0) {
        // 0x800EFF84: addu        $s6, $fp, $zero
        ctx->r22 = ADD32(ctx->r30, 0);
            goto L_800F0124;
    }
    // 0x800EFF84: addu        $s6, $fp, $zero
    ctx->r22 = ADD32(ctx->r30, 0);
    // 0x800EFF88: lui         $v0, 0x800B
    ctx->r2 = S32(0X800B << 16);
    // 0x800EFF8C: addiu       $v0, $v0, -0x7688
    ctx->r2 = ADD32(ctx->r2, -0X7688);
    // 0x800EFF90: sll         $v1, $s3, 2
    ctx->r3 = S32(ctx->r19 << 2);
    // 0x800EFF94: addu        $v1, $v1, $v0
    gpr jr_addend_800EFF9C = ctx->r3;
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x800EFF98: lw          $v0, 0x0($v1)
    ctx->r2 = ADD32(ctx->r3, 0X0);
    // 0x800EFF9C: jr          $v0
    // 0x800EFFA0: nop

    switch (jr_addend_800EFF9C >> 2) {
        case 0: goto L_800EFFA8; break;
        case 1: goto L_800EFFC0; break;
        case 2: goto L_800EFFF0; break;
        case 3: goto L_800F001C; break;
        case 4: goto L_800F006C; break;
        case 5: goto L_800F0044; break;
        case 6: goto L_800F00C4; break;
        case 7: goto L_800EFFA4; break;
        case 8: goto L_800EFFB8; break;
        case 9: goto L_800EFFE8; break;
        case 10: goto L_800F0014; break;
        default: switch_error(__func__, 0x800EFF9C, 0x800A8978);
    }
    // 0x800EFFA0: nop

L_800EFFA4:
    // 0x800EFFA4: addiu       $s6, $zero, 0x1
    ctx->r22 = ADD32(0, 0X1);
L_800EFFA8:
    // 0x800EFFA8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800EFFAC: sh          $v0, 0x18($sp)
    MEM_H(0X18, ctx->r29) = ctx->r2;
    // 0x800EFFB0: j           L_800F0124
    // 0x800EFFB4: addu        $fp, $v0, $zero
    ctx->r30 = ADD32(ctx->r2, 0);
        goto L_800F0124;
    // 0x800EFFB4: addu        $fp, $v0, $zero
    ctx->r30 = ADD32(ctx->r2, 0);
L_800EFFB8:
    // 0x800EFFB8: addiu       $fp, $zero, 0x1
    ctx->r30 = ADD32(0, 0X1);
    // 0x800EFFBC: addu        $s6, $fp, $zero
    ctx->r22 = ADD32(ctx->r30, 0);
L_800EFFC0:
    // 0x800EFFC0: lw          $t0, 0x90($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X90);
    // 0x800EFFC4: lh          $v1, 0x19A($t0)
    ctx->r3 = MEM_H(ctx->r8, 0X19A);
    // 0x800EFFC8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800EFFCC: bne         $v1, $v0, L_800EFFE0
    if (ctx->r3 != ctx->r2) {
        // 0x800EFFD0: addiu       $v0, $zero, 0x7
        ctx->r2 = ADD32(0, 0X7);
            goto L_800EFFE0;
    }
    // 0x800EFFD0: addiu       $v0, $zero, 0x7
    ctx->r2 = ADD32(0, 0X7);
    // 0x800EFFD4: addiu       $v0, $zero, 0x9
    ctx->r2 = ADD32(0, 0X9);
    // 0x800EFFD8: j           L_800F0124
    // 0x800EFFDC: sh          $v0, 0x18($sp)
    MEM_H(0X18, ctx->r29) = ctx->r2;
        goto L_800F0124;
    // 0x800EFFDC: sh          $v0, 0x18($sp)
    MEM_H(0X18, ctx->r29) = ctx->r2;
L_800EFFE0:
    // 0x800EFFE0: j           L_800F0124
    // 0x800EFFE4: sh          $v0, 0x18($sp)
    MEM_H(0X18, ctx->r29) = ctx->r2;
        goto L_800F0124;
    // 0x800EFFE4: sh          $v0, 0x18($sp)
    MEM_H(0X18, ctx->r29) = ctx->r2;
L_800EFFE8:
    // 0x800EFFE8: addiu       $fp, $zero, 0x1
    ctx->r30 = ADD32(0, 0X1);
    // 0x800EFFEC: addu        $s6, $fp, $zero
    ctx->r22 = ADD32(ctx->r30, 0);
L_800EFFF0:
    // 0x800EFFF0: lw          $t0, 0x90($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X90);
    // 0x800EFFF4: lh          $v1, 0x19A($t0)
    ctx->r3 = MEM_H(ctx->r8, 0X19A);
    // 0x800EFFF8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800EFFFC: bne         $v1, $v0, L_800F000C
    if (ctx->r3 != ctx->r2) {
        // 0x800F0000: addiu       $v0, $zero, 0x5
        ctx->r2 = ADD32(0, 0X5);
            goto L_800F000C;
    }
    // 0x800F0000: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
    // 0x800F0004: j           L_800F0124
    // 0x800F0008: sh          $zero, 0x18($sp)
    MEM_H(0X18, ctx->r29) = 0;
        goto L_800F0124;
    // 0x800F0008: sh          $zero, 0x18($sp)
    MEM_H(0X18, ctx->r29) = 0;
L_800F000C:
    // 0x800F000C: j           L_800F0124
    // 0x800F0010: sh          $v0, 0x18($sp)
    MEM_H(0X18, ctx->r29) = ctx->r2;
        goto L_800F0124;
    // 0x800F0010: sh          $v0, 0x18($sp)
    MEM_H(0X18, ctx->r29) = ctx->r2;
L_800F0014:
    // 0x800F0014: addiu       $fp, $zero, 0x1
    ctx->r30 = ADD32(0, 0X1);
    // 0x800F0018: addu        $s6, $fp, $zero
    ctx->r22 = ADD32(ctx->r30, 0);
L_800F001C:
    // 0x800F001C: lw          $t0, 0x90($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X90);
    // 0x800F0020: lh          $v1, 0x19A($t0)
    ctx->r3 = MEM_H(ctx->r8, 0X19A);
    // 0x800F0024: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800F0028: bne         $v1, $v0, L_800F003C
    if (ctx->r3 != ctx->r2) {
        // 0x800F002C: addiu       $v0, $zero, 0x6
        ctx->r2 = ADD32(0, 0X6);
            goto L_800F003C;
    }
    // 0x800F002C: addiu       $v0, $zero, 0x6
    ctx->r2 = ADD32(0, 0X6);
    // 0x800F0030: addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
    // 0x800F0034: j           L_800F0124
    // 0x800F0038: sh          $v0, 0x18($sp)
    MEM_H(0X18, ctx->r29) = ctx->r2;
        goto L_800F0124;
    // 0x800F0038: sh          $v0, 0x18($sp)
    MEM_H(0X18, ctx->r29) = ctx->r2;
L_800F003C:
    // 0x800F003C: j           L_800F0124
    // 0x800F0040: sh          $v0, 0x18($sp)
    MEM_H(0X18, ctx->r29) = ctx->r2;
        goto L_800F0124;
    // 0x800F0040: sh          $v0, 0x18($sp)
    MEM_H(0X18, ctx->r29) = ctx->r2;
L_800F0044:
    // 0x800F0044: lw          $t0, 0x90($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X90);
    // 0x800F0048: lh          $v1, 0x19A($t0)
    ctx->r3 = MEM_H(ctx->r8, 0X19A);
    // 0x800F004C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800F0050: bne         $v1, $v0, L_800F0064
    if (ctx->r3 != ctx->r2) {
        // 0x800F0054: addiu       $v0, $zero, 0xD
        ctx->r2 = ADD32(0, 0XD);
            goto L_800F0064;
    }
    // 0x800F0054: addiu       $v0, $zero, 0xD
    ctx->r2 = ADD32(0, 0XD);
    // 0x800F0058: addiu       $v0, $zero, 0xC
    ctx->r2 = ADD32(0, 0XC);
    // 0x800F005C: j           L_800F0124
    // 0x800F0060: sh          $v0, 0x18($sp)
    MEM_H(0X18, ctx->r29) = ctx->r2;
        goto L_800F0124;
    // 0x800F0060: sh          $v0, 0x18($sp)
    MEM_H(0X18, ctx->r29) = ctx->r2;
L_800F0064:
    // 0x800F0064: j           L_800F0124
    // 0x800F0068: sh          $v0, 0x18($sp)
    MEM_H(0X18, ctx->r29) = ctx->r2;
        goto L_800F0124;
    // 0x800F0068: sh          $v0, 0x18($sp)
    MEM_H(0X18, ctx->r29) = ctx->r2;
L_800F006C:
    // 0x800F006C: lw          $t0, 0x90($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X90);
    // 0x800F0070: lh          $v1, 0x19A($t0)
    ctx->r3 = MEM_H(ctx->r8, 0X19A);
    // 0x800F0074: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800F0078: bne         $v1, $v0, L_800F00A0
    if (ctx->r3 != ctx->r2) {
        // 0x800F007C: addiu       $s7, $zero, 0x4
        ctx->r23 = ADD32(0, 0X4);
            goto L_800F00A0;
    }
    // 0x800F007C: addiu       $s7, $zero, 0x4
    ctx->r23 = ADD32(0, 0X4);
    // 0x800F0080: addiu       $v0, $zero, 0xC
    ctx->r2 = ADD32(0, 0XC);
    // 0x800F0084: sh          $v0, 0x18($sp)
    MEM_H(0X18, ctx->r29) = ctx->r2;
    // 0x800F0088: addiu       $v0, $zero, 0x9
    ctx->r2 = ADD32(0, 0X9);
    // 0x800F008C: sh          $v0, 0x1C($sp)
    MEM_H(0X1C, ctx->r29) = ctx->r2;
    // 0x800F0090: addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
    // 0x800F0094: sh          $zero, 0x1A($sp)
    MEM_H(0X1A, ctx->r29) = 0;
    // 0x800F0098: j           L_800F0124
    // 0x800F009C: sh          $v0, 0x1E($sp)
    MEM_H(0X1E, ctx->r29) = ctx->r2;
        goto L_800F0124;
    // 0x800F009C: sh          $v0, 0x1E($sp)
    MEM_H(0X1E, ctx->r29) = ctx->r2;
L_800F00A0:
    // 0x800F00A0: addiu       $v0, $zero, 0xD
    ctx->r2 = ADD32(0, 0XD);
    // 0x800F00A4: sh          $v0, 0x18($sp)
    MEM_H(0X18, ctx->r29) = ctx->r2;
    // 0x800F00A8: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
    // 0x800F00AC: sh          $v0, 0x1A($sp)
    MEM_H(0X1A, ctx->r29) = ctx->r2;
    // 0x800F00B0: addiu       $v0, $zero, 0x7
    ctx->r2 = ADD32(0, 0X7);
    // 0x800F00B4: sh          $v0, 0x1C($sp)
    MEM_H(0X1C, ctx->r29) = ctx->r2;
    // 0x800F00B8: addiu       $v0, $zero, 0x6
    ctx->r2 = ADD32(0, 0X6);
    // 0x800F00BC: j           L_800F0124
    // 0x800F00C0: sh          $v0, 0x1E($sp)
    MEM_H(0X1E, ctx->r29) = ctx->r2;
        goto L_800F0124;
    // 0x800F00C0: sh          $v0, 0x1E($sp)
    MEM_H(0X1E, ctx->r29) = ctx->r2;
L_800F00C4:
    // 0x800F00C4: lbu         $v1, 0x20($s2)
    ctx->r3 = MEM_BU(ctx->r18, 0X20);
    // 0x800F00C8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800F00CC: bne         $v1, $v0, L_800F0678
    if (ctx->r3 != ctx->r2) {
        // 0x800F00D0: addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
            goto L_800F0678;
    }
    // 0x800F00D0: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // 0x800F00D4: lhu         $v0, 0x1A($s2)
    ctx->r2 = MEM_HU(ctx->r18, 0X1A);
    // 0x800F00D8: ori         $s0, $zero, 0xFFFF
    ctx->r16 = 0 | 0XFFFF;
    // 0x800F00DC: beq         $v0, $s0, L_800F0678
    if (ctx->r2 == ctx->r16) {
        // 0x800F00E0: addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
            goto L_800F0678;
    }
    // 0x800F00E0: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // 0x800F00E4: lhu         $a0, 0x1C($s2)
    ctx->r4 = MEM_HU(ctx->r18, 0X1C);
    // 0x800F00E8: jal         0x8003FC28
    // 0x800F00EC: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    func_8003FC28(rdram, ctx);
        goto after_7;
    // 0x800F00EC: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    after_7:
    // 0x800F00F0: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x800F00F4: beql        $v0, $s0, L_800F0118
    if (ctx->r2 == ctx->r16) {
        // 0x800F00F8: sh          $s0, 0x1A($s2)
        MEM_H(0X1A, ctx->r18) = ctx->r16;
            goto L_800F0118;
    }
    goto skip_3;
    // 0x800F00F8: sh          $s0, 0x1A($s2)
    MEM_H(0X1A, ctx->r18) = ctx->r16;
    skip_3:
    // 0x800F00FC: lhu         $a0, 0x1E($s2)
    ctx->r4 = MEM_HU(ctx->r18, 0X1E);
    // 0x800F0100: jal         0x8004013C
    // 0x800F0104: nop

    func_8004013C(rdram, ctx);
        goto after_8;
    // 0x800F0104: nop

    after_8:
    // 0x800F0108: lhu         $a0, 0x1E($s2)
    ctx->r4 = MEM_HU(ctx->r18, 0X1E);
    // 0x800F010C: jal         0x8003E7D0
    // 0x800F0110: addu        $a1, $v0, $zero
    ctx->r5 = ADD32(ctx->r2, 0);
    func_8003E7D0(rdram, ctx);
        goto after_9;
    // 0x800F0110: addu        $a1, $v0, $zero
    ctx->r5 = ADD32(ctx->r2, 0);
    after_9:
    // 0x800F0114: sh          $s0, 0x1A($s2)
    MEM_H(0X1A, ctx->r18) = ctx->r16;
L_800F0118:
    // 0x800F0118: sh          $s0, 0x1E($s2)
    MEM_H(0X1E, ctx->r18) = ctx->r16;
    // 0x800F011C: j           L_800F0674
    // 0x800F0120: sb          $zero, 0x20($s2)
    MEM_B(0X20, ctx->r18) = 0;
        goto L_800F0674;
    // 0x800F0120: sb          $zero, 0x20($s2)
    MEM_B(0X20, ctx->r18) = 0;
L_800F0124:
    // 0x800F0124: ori         $s4, $zero, 0xFFFF
    ctx->r20 = 0 | 0XFFFF;
    // 0x800F0128: mtc1        $zero, $f26
    ctx->f26.u32l = 0;
    // 0x800F012C: beq         $s7, $zero, L_800F02B8
    if (ctx->r23 == 0) {
        // 0x800F0130: addu        $s3, $zero, $zero
        ctx->r19 = ADD32(0, 0);
            goto L_800F02B8;
    }
    // 0x800F0130: addu        $s3, $zero, $zero
    ctx->r19 = ADD32(0, 0);
    // 0x800F0134: ori         $s5, $zero, 0xFFFF
    ctx->r21 = 0 | 0XFFFF;
    // 0x800F0138: sll         $v0, $s3, 1
    ctx->r2 = S32(ctx->r19 << 1);
L_800F013C:
    // 0x800F013C: addu        $v0, $sp, $v0
    ctx->r2 = ADD32(ctx->r29, ctx->r2);
    // 0x800F0140: lui         $t0, 0x8014
    ctx->r8 = S32(0X8014 << 16);
    // 0x800F0144: lhu         $v0, 0x18($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X18);
    // 0x800F0148: addiu       $t0, $t0, -0x6AA0
    ctx->r8 = ADD32(ctx->r8, -0X6AA0);
    // 0x800F014C: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x800F0150: addu        $v0, $v0, $t0
    ctx->r2 = ADD32(ctx->r2, ctx->r8);
    // 0x800F0154: lhu         $a0, 0x0($v0)
    ctx->r4 = MEM_HU(ctx->r2, 0X0);
    // 0x800F0158: jal         0x8003FC28
    // 0x800F015C: addiu       $a1, $sp, 0x10
    ctx->r5 = ADD32(ctx->r29, 0X10);
    func_8003FC28(rdram, ctx);
        goto after_10;
    // 0x800F015C: addiu       $a1, $sp, 0x10
    ctx->r5 = ADD32(ctx->r29, 0X10);
    after_10:
    // 0x800F0160: j           L_800F029C
    // 0x800F0164: addu        $s1, $v0, $zero
    ctx->r17 = ADD32(ctx->r2, 0);
        goto L_800F029C;
    // 0x800F0164: addu        $s1, $v0, $zero
    ctx->r17 = ADD32(ctx->r2, 0);
L_800F0168:
    // 0x800F0168: jal         0x8004013C
    // 0x800F016C: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_8004013C(rdram, ctx);
        goto after_11;
    // 0x800F016C: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_11:
    // 0x800F0170: lhu         $v0, 0x14($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X14);
    // 0x800F0174: andi        $v0, $v0, 0x10
    ctx->r2 = ctx->r2 & 0X10;
    // 0x800F0178: bne         $v0, $zero, L_800F02A8
    if (ctx->r2 != 0) {
        // 0x800F017C: andi        $v0, $s6, 0xFF
        ctx->r2 = ctx->r22 & 0XFF;
            goto L_800F02A8;
    }
    // 0x800F017C: andi        $v0, $s6, 0xFF
    ctx->r2 = ctx->r22 & 0XFF;
    // 0x800F0180: beq         $v0, $zero, L_800F0198
    if (ctx->r2 == 0) {
        // 0x800F0184: nop
    
            goto L_800F0198;
    }
    // 0x800F0184: nop

    // 0x800F0188: jal         0x800F27F0
    // 0x800F018C: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_800F27F0(rdram, ctx);
        goto after_12;
    // 0x800F018C: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_12:
    // 0x800F0190: bne         $v0, $zero, L_800F0290
    if (ctx->r2 != 0) {
        // 0x800F0194: nop
    
            goto L_800F0290;
    }
    // 0x800F0194: nop

L_800F0198:
    // 0x800F0198: lw          $t0, 0x90($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X90);
    // 0x800F019C: lhu         $a0, 0x198($t0)
    ctx->r4 = MEM_HU(ctx->r8, 0X198);
    // 0x800F01A0: jal         0x8004015C
    // 0x800F01A4: nop

    func_8004015C(rdram, ctx);
        goto after_13;
    // 0x800F01A4: nop

    after_13:
    // 0x800F01A8: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x800F01AC: jal         0x8004015C
    // 0x800F01B0: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    func_8004015C(rdram, ctx);
        goto after_14;
    // 0x800F01B0: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    after_14:
    // 0x800F01B4: lwc1        $f4, 0x0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X0);
    // 0x800F01B8: lwc1        $f0, 0x0($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X0);
    // 0x800F01BC: sub.s       $f4, $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f4.fl - ctx->f0.fl;
    // 0x800F01C0: lwc1        $f6, 0x4($s2)
    ctx->f6.u32l = MEM_W(ctx->r18, 0X4);
    // 0x800F01C4: lwc1        $f24, 0x0($s2)
    ctx->f24.u32l = MEM_W(ctx->r18, 0X0);
    // 0x800F01C8: mul.s       $f6, $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f6.fl = MUL_S(ctx->f6.fl, ctx->f6.fl);
    // 0x800F01CC: swc1        $f4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f4.u32l;
    // 0x800F01D0: lwc1        $f2, 0x4($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X4);
    // 0x800F01D4: lwc1        $f0, 0x4($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X4);
    // 0x800F01D8: sub.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl - ctx->f0.fl;
    // 0x800F01DC: mul.s       $f4, $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f4.fl = MUL_S(ctx->f4.fl, ctx->f4.fl);
    // 0x800F01E0: swc1        $f2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f2.u32l;
    // 0x800F01E4: lwc1        $f0, 0x8($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X8);
    // 0x800F01E8: lwc1        $f2, 0x8($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X8);
    // 0x800F01EC: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x800F01F0: mul.s       $f2, $f0, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x800F01F4: add.s       $f4, $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f2.fl;
    // 0x800F01F8: c.lt.s      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.fl < ctx->f4.fl;
    // 0x800F01FC: nop

    // 0x800F0200: bc1t        L_800F0248
    if (c1cs) {
        // 0x800F0204: swc1        $f0, 0x30($sp)
        MEM_W(0X30, ctx->r29) = ctx->f0.u32l;
            goto L_800F0248;
    }
    // 0x800F0204: swc1        $f0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f0.u32l;
    // 0x800F0208: addiu       $s0, $s0, 0xC
    ctx->r16 = ADD32(ctx->r16, 0XC);
    // 0x800F020C: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x800F0210: jal         0x8001CFE8
    // 0x800F0214: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    func_8001CFE8(rdram, ctx);
        goto after_15;
    // 0x800F0214: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    after_15:
    // 0x800F0218: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x800F021C: jal         0x8001CF2C
    // 0x800F0220: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
    func_8001CF2C(rdram, ctx);
        goto after_16;
    // 0x800F0220: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
    after_16:
    // 0x800F0224: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    // 0x800F0228: jal         0x8001CF2C
    // 0x800F022C: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    func_8001CF2C(rdram, ctx);
        goto after_17;
    // 0x800F022C: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    after_17:
    // 0x800F0230: mul.s       $f20, $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f20.fl = MUL_S(ctx->f20.fl, ctx->f0.fl);
    // 0x800F0234: div.s       $f22, $f22, $f20
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f22.fl = DIV_S(ctx->f22.fl, ctx->f20.fl);
    // 0x800F0238: c.lt.s      $f22, $f24
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 24);
    c1cs = ctx->f22.fl < ctx->f24.fl;
    // 0x800F023C: nop

    // 0x800F0240: bc1f        L_800F0250
    if (!c1cs) {
        // 0x800F0244: nop
    
            goto L_800F0250;
    }
    // 0x800F0244: nop

L_800F0248:
    // 0x800F0248: j           L_800F0260
    // 0x800F024C: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
        goto L_800F0260;
    // 0x800F024C: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
L_800F0250:
    // 0x800F0250: jal         0x8001CF2C
    // 0x800F0254: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    func_8001CF2C(rdram, ctx);
        goto after_18;
    // 0x800F0254: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    after_18:
    // 0x800F0258: swc1        $f0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f0.u32l;
    // 0x800F025C: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_800F0260:
    // 0x800F0260: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800F0264: bne         $v1, $v0, L_800F0290
    if (ctx->r3 != ctx->r2) {
        // 0x800F0268: andi        $v0, $s4, 0xFFFF
        ctx->r2 = ctx->r20 & 0XFFFF;
            goto L_800F0290;
    }
    // 0x800F0268: andi        $v0, $s4, 0xFFFF
    ctx->r2 = ctx->r20 & 0XFFFF;
    // 0x800F026C: beq         $v0, $s5, L_800F0288
    if (ctx->r2 == ctx->r21) {
        // 0x800F0270: nop
    
            goto L_800F0288;
    }
    // 0x800F0270: nop

    // 0x800F0274: lwc1        $f0, 0x38($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X38);
    // 0x800F0278: c.lt.s      $f0, $f26
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 26);
    c1cs = ctx->f0.fl < ctx->f26.fl;
    // 0x800F027C: nop

    // 0x800F0280: bc1f        L_800F0290
    if (!c1cs) {
        // 0x800F0284: nop
    
            goto L_800F0290;
    }
    // 0x800F0284: nop

L_800F0288:
    // 0x800F0288: lwc1        $f26, 0x38($sp)
    ctx->f26.u32l = MEM_W(ctx->r29, 0X38);
    // 0x800F028C: addu        $s4, $s1, $zero
    ctx->r20 = ADD32(ctx->r17, 0);
L_800F0290:
    // 0x800F0290: jal         0x8003EEF4
    // 0x800F0294: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    func_8003EEF4(rdram, ctx);
        goto after_19;
    // 0x800F0294: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    after_19:
    // 0x800F0298: addu        $s1, $v0, $zero
    ctx->r17 = ADD32(ctx->r2, 0);
L_800F029C:
    // 0x800F029C: andi        $v0, $s1, 0xFFFF
    ctx->r2 = ctx->r17 & 0XFFFF;
    // 0x800F02A0: bne         $v0, $s5, L_800F0168
    if (ctx->r2 != ctx->r21) {
        // 0x800F02A4: andi        $s0, $s1, 0xFFFF
        ctx->r16 = ctx->r17 & 0XFFFF;
            goto L_800F0168;
    }
    // 0x800F02A4: andi        $s0, $s1, 0xFFFF
    ctx->r16 = ctx->r17 & 0XFFFF;
L_800F02A8:
    // 0x800F02A8: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x800F02AC: slt         $v0, $s3, $s7
    ctx->r2 = SIGNED(ctx->r19) < SIGNED(ctx->r23) ? 1 : 0;
    // 0x800F02B0: bne         $v0, $zero, L_800F013C
    if (ctx->r2 != 0) {
        // 0x800F02B4: sll         $v0, $s3, 1
        ctx->r2 = S32(ctx->r19 << 1);
            goto L_800F013C;
    }
    // 0x800F02B4: sll         $v0, $s3, 1
    ctx->r2 = S32(ctx->r19 << 1);
L_800F02B8:
    // 0x800F02B8: andi        $v1, $s4, 0xFFFF
    ctx->r3 = ctx->r20 & 0XFFFF;
    // 0x800F02BC: ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
    // 0x800F02C0: bne         $v1, $v0, L_800F02E8
    if (ctx->r3 != ctx->r2) {
        // 0x800F02C4: andi        $v0, $fp, 0xFF
        ctx->r2 = ctx->r30 & 0XFF;
            goto L_800F02E8;
    }
    // 0x800F02C4: andi        $v0, $fp, 0xFF
    ctx->r2 = ctx->r30 & 0XFF;
    // 0x800F02C8: lw          $t0, 0x98($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X98);
    // 0x800F02CC: addiu       $v0, $zero, 0x6
    ctx->r2 = ADD32(0, 0X6);
    // 0x800F02D0: beq         $t0, $v0, L_800F02E4
    if (ctx->r8 == ctx->r2) {
        // 0x800F02D4: addu        $s3, $t0, $zero
        ctx->r19 = ADD32(ctx->r8, 0);
            goto L_800F02E4;
    }
    // 0x800F02D4: addu        $s3, $t0, $zero
    ctx->r19 = ADD32(ctx->r8, 0);
    // 0x800F02D8: addu        $t0, $v0, $zero
    ctx->r8 = ADD32(ctx->r2, 0);
    // 0x800F02DC: j           L_800EFF74
    // 0x800F02E0: sw          $t0, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->r8;
        goto L_800EFF74;
    // 0x800F02E0: sw          $t0, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->r8;
L_800F02E4:
    // 0x800F02E4: andi        $v0, $fp, 0xFF
    ctx->r2 = ctx->r30 & 0XFF;
L_800F02E8:
    // 0x800F02E8: bne         $v0, $zero, L_800F0584
    if (ctx->r2 != 0) {
        // 0x800F02EC: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_800F0584;
    }
    // 0x800F02EC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800F02F0: lw          $t0, 0x90($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X90);
    // 0x800F02F4: lh          $v1, 0x19A($t0)
    ctx->r3 = MEM_H(ctx->r8, 0X19A);
    // 0x800F02F8: bne         $v1, $v0, L_800F0584
    if (ctx->r3 != ctx->r2) {
        // 0x800F02FC: andi        $v1, $s4, 0xFFFF
        ctx->r3 = ctx->r20 & 0XFFFF;
            goto L_800F0584;
    }
    // 0x800F02FC: andi        $v1, $s4, 0xFFFF
    ctx->r3 = ctx->r20 & 0XFFFF;
    // 0x800F0300: addu        $s3, $zero, $zero
    ctx->r19 = ADD32(0, 0);
    // 0x800F0304: ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
    // 0x800F0308: beq         $v1, $v0, L_800F0384
    if (ctx->r3 == ctx->r2) {
        // 0x800F030C: addu        $s0, $s3, $zero
        ctx->r16 = ADD32(ctx->r19, 0);
            goto L_800F0384;
    }
    // 0x800F030C: addu        $s0, $s3, $zero
    ctx->r16 = ADD32(ctx->r19, 0);
    // 0x800F0310: jal         0x80003430
    // 0x800F0314: nop

    rand_recomp(rdram, ctx);
        goto after_20;
    // 0x800F0314: nop

    after_20:
    // 0x800F0318: lui         $v1, 0x51EB
    ctx->r3 = S32(0X51EB << 16);
    // 0x800F031C: ori         $v1, $v1, 0x851F
    ctx->r3 = ctx->r3 | 0X851F;
    // 0x800F0320: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x800F0324: sra         $a0, $v0, 16
    ctx->r4 = S32(SIGNED(ctx->r2) >> 16);
    // 0x800F0328: mult        $a0, $v1
    result = S64(S32(ctx->r4)) * S64(S32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800F032C: sra         $v0, $v0, 31
    ctx->r2 = S32(SIGNED(ctx->r2) >> 31);
    // 0x800F0330: mfhi        $t0
    ctx->r8 = hi;
    // 0x800F0334: sra         $v1, $t0, 5
    ctx->r3 = S32(SIGNED(ctx->r8) >> 5);
    // 0x800F0338: subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // 0x800F033C: sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3 << 1);
    // 0x800F0340: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800F0344: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x800F0348: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800F034C: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800F0350: subu        $a0, $a0, $v0
    ctx->r4 = SUB32(ctx->r4, ctx->r2);
    // 0x800F0354: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x800F0358: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
    // 0x800F035C: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800F0360: lw          $v0, 0x7CE4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X7CE4);
    // 0x800F0364: addiu       $v1, $v1, -0x4CE0
    ctx->r3 = ADD32(ctx->r3, -0X4CE0);
    // 0x800F0368: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800F036C: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800F0370: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x800F0374: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    // 0x800F0378: slt         $a0, $a0, $v0
    ctx->r4 = SIGNED(ctx->r4) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800F037C: beq         $a0, $zero, L_800F0388
    if (ctx->r4 == 0) {
        // 0x800F0380: nop
    
            goto L_800F0388;
    }
    // 0x800F0380: nop

L_800F0384:
    // 0x800F0384: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
L_800F0388:
    // 0x800F0388: jal         0x80003430
    // 0x800F038C: nop

    rand_recomp(rdram, ctx);
        goto after_21;
    // 0x800F038C: nop

    after_21:
    // 0x800F0390: lui         $v1, 0x51EB
    ctx->r3 = S32(0X51EB << 16);
    // 0x800F0394: ori         $v1, $v1, 0x851F
    ctx->r3 = ctx->r3 | 0X851F;
    // 0x800F0398: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x800F039C: sra         $a0, $v0, 16
    ctx->r4 = S32(SIGNED(ctx->r2) >> 16);
    // 0x800F03A0: mult        $a0, $v1
    result = S64(S32(ctx->r4)) * S64(S32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800F03A4: sra         $v0, $v0, 31
    ctx->r2 = S32(SIGNED(ctx->r2) >> 31);
    // 0x800F03A8: mfhi        $t0
    ctx->r8 = hi;
    // 0x800F03AC: sra         $v1, $t0, 5
    ctx->r3 = S32(SIGNED(ctx->r8) >> 5);
    // 0x800F03B0: subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // 0x800F03B4: sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3 << 1);
    // 0x800F03B8: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800F03BC: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x800F03C0: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800F03C4: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800F03C8: subu        $a0, $a0, $v0
    ctx->r4 = SUB32(ctx->r4, ctx->r2);
    // 0x800F03CC: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x800F03D0: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
    // 0x800F03D4: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800F03D8: lw          $v0, 0x7CE4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X7CE4);
    // 0x800F03DC: addiu       $v1, $v1, -0x4CD0
    ctx->r3 = ADD32(ctx->r3, -0X4CD0);
    // 0x800F03E0: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800F03E4: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800F03E8: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x800F03EC: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    // 0x800F03F0: slt         $a0, $a0, $v0
    ctx->r4 = SIGNED(ctx->r4) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800F03F4: beq         $a0, $zero, L_800F0410
    if (ctx->r4 == 0) {
        // 0x800F03F8: nop
    
            goto L_800F0410;
    }
    // 0x800F03F8: nop

    // 0x800F03FC: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
    // 0x800F0400: lwc1        $f24, 0xC($s2)
    ctx->f24.u32l = MEM_W(ctx->r18, 0XC);
    // 0x800F0404: lwc1        $f28, 0x8($s2)
    ctx->f28.u32l = MEM_W(ctx->r18, 0X8);
    // 0x800F0408: j           L_800F0418
    // 0x800F040C: addu        $s3, $s0, $zero
    ctx->r19 = ADD32(ctx->r16, 0);
        goto L_800F0418;
    // 0x800F040C: addu        $s3, $s0, $zero
    ctx->r19 = ADD32(ctx->r16, 0);
L_800F0410:
    // 0x800F0410: lwc1        $f24, 0x4($s2)
    ctx->f24.u32l = MEM_W(ctx->r18, 0X4);
    // 0x800F0414: lwc1        $f28, 0x0($s2)
    ctx->f28.u32l = MEM_W(ctx->r18, 0X0);
L_800F0418:
    // 0x800F0418: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800F041C: bne         $s0, $v0, L_800F0584
    if (ctx->r16 != ctx->r2) {
        // 0x800F0420: lui         $v0, 0x8014
        ctx->r2 = S32(0X8014 << 16);
            goto L_800F0584;
    }
    // 0x800F0420: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x800F0424: lhu         $a0, -0x6A9E($v0)
    ctx->r4 = MEM_HU(ctx->r2, -0X6A9E);
    // 0x800F0428: jal         0x8003FC28
    // 0x800F042C: addiu       $a1, $sp, 0x10
    ctx->r5 = ADD32(ctx->r29, 0X10);
    func_8003FC28(rdram, ctx);
        goto after_22;
    // 0x800F042C: addiu       $a1, $sp, 0x10
    ctx->r5 = ADD32(ctx->r29, 0X10);
    after_22:
    // 0x800F0430: addu        $s1, $v0, $zero
    ctx->r17 = ADD32(ctx->r2, 0);
    // 0x800F0434: andi        $v1, $s1, 0xFFFF
    ctx->r3 = ctx->r17 & 0XFFFF;
    // 0x800F0438: ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
    // 0x800F043C: beq         $v1, $v0, L_800F0584
    if (ctx->r3 == ctx->r2) {
        // 0x800F0440: andi        $s0, $s1, 0xFFFF
        ctx->r16 = ctx->r17 & 0XFFFF;
            goto L_800F0584;
    }
    // 0x800F0440: andi        $s0, $s1, 0xFFFF
    ctx->r16 = ctx->r17 & 0XFFFF;
    // 0x800F0444: addu        $s5, $v0, $zero
    ctx->r21 = ADD32(ctx->r2, 0);
L_800F0448:
    // 0x800F0448: jal         0x8004013C
    // 0x800F044C: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_8004013C(rdram, ctx);
        goto after_23;
    // 0x800F044C: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_23:
    // 0x800F0450: lhu         $v0, 0x14($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X14);
    // 0x800F0454: andi        $v0, $v0, 0x10
    ctx->r2 = ctx->r2 & 0X10;
    // 0x800F0458: bne         $v0, $zero, L_800F0584
    if (ctx->r2 != 0) {
        // 0x800F045C: nop
    
            goto L_800F0584;
    }
    // 0x800F045C: nop

    // 0x800F0460: lw          $t0, 0x90($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X90);
    // 0x800F0464: lhu         $a0, 0x198($t0)
    ctx->r4 = MEM_HU(ctx->r8, 0X198);
    // 0x800F0468: jal         0x8004015C
    // 0x800F046C: nop

    func_8004015C(rdram, ctx);
        goto after_24;
    // 0x800F046C: nop

    after_24:
    // 0x800F0470: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x800F0474: jal         0x8004015C
    // 0x800F0478: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    func_8004015C(rdram, ctx);
        goto after_25;
    // 0x800F0478: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    after_25:
    // 0x800F047C: lwc1        $f4, 0x0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X0);
    // 0x800F0480: lwc1        $f0, 0x0($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X0);
    // 0x800F0484: sub.s       $f4, $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f4.fl - ctx->f0.fl;
    // 0x800F0488: mul.s       $f6, $f24, $f24
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f6.fl = MUL_S(ctx->f24.fl, ctx->f24.fl);
    // 0x800F048C: swc1        $f4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f4.u32l;
    // 0x800F0490: lwc1        $f2, 0x4($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X4);
    // 0x800F0494: lwc1        $f0, 0x4($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X4);
    // 0x800F0498: sub.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl - ctx->f0.fl;
    // 0x800F049C: mul.s       $f4, $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f4.fl = MUL_S(ctx->f4.fl, ctx->f4.fl);
    // 0x800F04A0: swc1        $f2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f2.u32l;
    // 0x800F04A4: lwc1        $f2, 0x8($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X8);
    // 0x800F04A8: lwc1        $f0, 0x8($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X8);
    // 0x800F04AC: sub.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl - ctx->f0.fl;
    // 0x800F04B0: mul.s       $f0, $f2, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x800F04B4: add.s       $f4, $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f0.fl;
    // 0x800F04B8: c.lt.s      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.fl < ctx->f4.fl;
    // 0x800F04BC: nop

    // 0x800F04C0: bc1t        L_800F0508
    if (c1cs) {
        // 0x800F04C4: swc1        $f2, 0x30($sp)
        MEM_W(0X30, ctx->r29) = ctx->f2.u32l;
            goto L_800F0508;
    }
    // 0x800F04C4: swc1        $f2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f2.u32l;
    // 0x800F04C8: addiu       $s0, $s0, 0xC
    ctx->r16 = ADD32(ctx->r16, 0XC);
    // 0x800F04CC: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x800F04D0: jal         0x8001CFE8
    // 0x800F04D4: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    func_8001CFE8(rdram, ctx);
        goto after_26;
    // 0x800F04D4: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    after_26:
    // 0x800F04D8: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x800F04DC: jal         0x8001CF2C
    // 0x800F04E0: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
    func_8001CF2C(rdram, ctx);
        goto after_27;
    // 0x800F04E0: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
    after_27:
    // 0x800F04E4: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    // 0x800F04E8: jal         0x8001CF2C
    // 0x800F04EC: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    func_8001CF2C(rdram, ctx);
        goto after_28;
    // 0x800F04EC: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    after_28:
    // 0x800F04F0: mul.s       $f20, $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f20.fl = MUL_S(ctx->f20.fl, ctx->f0.fl);
    // 0x800F04F4: div.s       $f22, $f22, $f20
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f22.fl = DIV_S(ctx->f22.fl, ctx->f20.fl);
    // 0x800F04F8: c.lt.s      $f22, $f28
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 28);
    c1cs = ctx->f22.fl < ctx->f28.fl;
    // 0x800F04FC: nop

    // 0x800F0500: bc1f        L_800F0510
    if (!c1cs) {
        // 0x800F0504: nop
    
            goto L_800F0510;
    }
    // 0x800F0504: nop

L_800F0508:
    // 0x800F0508: j           L_800F0520
    // 0x800F050C: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
        goto L_800F0520;
    // 0x800F050C: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_800F0510:
    // 0x800F0510: jal         0x8001CF2C
    // 0x800F0514: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    func_8001CF2C(rdram, ctx);
        goto after_29;
    // 0x800F0514: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    after_29:
    // 0x800F0518: swc1        $f0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f0.u32l;
    // 0x800F051C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800F0520:
    // 0x800F0520: andi        $v1, $v0, 0xFF
    ctx->r3 = ctx->r2 & 0XFF;
    // 0x800F0524: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800F0528: bne         $v1, $v0, L_800F056C
    if (ctx->r3 != ctx->r2) {
        // 0x800F052C: nop
    
            goto L_800F056C;
    }
    // 0x800F052C: nop

    // 0x800F0530: bne         $s3, $v1, L_800F0544
    if (ctx->r19 != ctx->r3) {
        // 0x800F0534: andi        $v0, $s4, 0xFFFF
        ctx->r2 = ctx->r20 & 0XFFFF;
            goto L_800F0544;
    }
    // 0x800F0534: andi        $v0, $s4, 0xFFFF
    ctx->r2 = ctx->r20 & 0XFFFF;
    // 0x800F0538: addu        $s3, $zero, $zero
    ctx->r19 = ADD32(0, 0);
    // 0x800F053C: ori         $s4, $zero, 0xFFFF
    ctx->r20 = 0 | 0XFFFF;
    // 0x800F0540: andi        $v0, $s4, 0xFFFF
    ctx->r2 = ctx->r20 & 0XFFFF;
L_800F0544:
    // 0x800F0544: beq         $v0, $s5, L_800F0560
    if (ctx->r2 == ctx->r21) {
        // 0x800F0548: nop
    
            goto L_800F0560;
    }
    // 0x800F0548: nop

    // 0x800F054C: lwc1        $f0, 0x38($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X38);
    // 0x800F0550: c.lt.s      $f0, $f26
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 26);
    c1cs = ctx->f0.fl < ctx->f26.fl;
    // 0x800F0554: nop

    // 0x800F0558: bc1f        L_800F056C
    if (!c1cs) {
        // 0x800F055C: nop
    
            goto L_800F056C;
    }
    // 0x800F055C: nop

L_800F0560:
    // 0x800F0560: lwc1        $f26, 0x38($sp)
    ctx->f26.u32l = MEM_W(ctx->r29, 0X38);
    // 0x800F0564: addu        $s4, $s1, $zero
    ctx->r20 = ADD32(ctx->r17, 0);
    // 0x800F0568: addiu       $s6, $zero, 0x1
    ctx->r22 = ADD32(0, 0X1);
L_800F056C:
    // 0x800F056C: jal         0x8003EEF4
    // 0x800F0570: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    func_8003EEF4(rdram, ctx);
        goto after_30;
    // 0x800F0570: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    after_30:
    // 0x800F0574: addu        $s1, $v0, $zero
    ctx->r17 = ADD32(ctx->r2, 0);
    // 0x800F0578: andi        $v0, $s1, 0xFFFF
    ctx->r2 = ctx->r17 & 0XFFFF;
    // 0x800F057C: bne         $v0, $s5, L_800F0448
    if (ctx->r2 != ctx->r21) {
        // 0x800F0580: andi        $s0, $s1, 0xFFFF
        ctx->r16 = ctx->r17 & 0XFFFF;
            goto L_800F0448;
    }
    // 0x800F0580: andi        $s0, $s1, 0xFFFF
    ctx->r16 = ctx->r17 & 0XFFFF;
L_800F0584:
    // 0x800F0584: jal         0x8006C994
    // 0x800F0588: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    func_8006C994(rdram, ctx);
        goto after_31;
    // 0x800F0588: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    after_31:
    // 0x800F058C: andi        $v1, $s4, 0xFFFF
    ctx->r3 = ctx->r20 & 0XFFFF;
    // 0x800F0590: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x800F0594: beq         $v1, $v0, L_800F05A8
    if (ctx->r3 == ctx->r2) {
        // 0x800F0598: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_800F05A8;
    }
    // 0x800F0598: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800F059C: lbu         $v1, 0x23($s2)
    ctx->r3 = MEM_BU(ctx->r18, 0X23);
    // 0x800F05A0: bne         $v1, $v0, L_800F05C0
    if (ctx->r3 != ctx->r2) {
        // 0x800F05A4: nop
    
            goto L_800F05C0;
    }
    // 0x800F05A4: nop

L_800F05A8:
    // 0x800F05A8: lbu         $v0, 0x23($s2)
    ctx->r2 = MEM_BU(ctx->r18, 0X23);
    // 0x800F05AC: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800F05B0: lwc1        $f0, -0x765C($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X765C);
    // 0x800F05B4: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x800F05B8: sb          $v0, 0x23($s2)
    MEM_B(0X23, ctx->r18) = ctx->r2;
    // 0x800F05BC: swc1        $f0, 0x10($s2)
    MEM_W(0X10, ctx->r18) = ctx->f0.u32l;
L_800F05C0:
    // 0x800F05C0: lbu         $v1, 0x20($s2)
    ctx->r3 = MEM_BU(ctx->r18, 0X20);
    // 0x800F05C4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800F05C8: bne         $v1, $v0, L_800F061C
    if (ctx->r3 != ctx->r2) {
        // 0x800F05CC: sb          $s6, 0x22($s2)
        MEM_B(0X22, ctx->r18) = ctx->r22;
            goto L_800F061C;
    }
    // 0x800F05CC: sb          $s6, 0x22($s2)
    MEM_B(0X22, ctx->r18) = ctx->r22;
    // 0x800F05D0: lhu         $v0, 0x1A($s2)
    ctx->r2 = MEM_HU(ctx->r18, 0X1A);
    // 0x800F05D4: ori         $s0, $zero, 0xFFFF
    ctx->r16 = 0 | 0XFFFF;
    // 0x800F05D8: beq         $v0, $s0, L_800F0624
    if (ctx->r2 == ctx->r16) {
        // 0x800F05DC: andi        $a0, $s4, 0xFFFF
        ctx->r4 = ctx->r20 & 0XFFFF;
            goto L_800F0624;
    }
    // 0x800F05DC: andi        $a0, $s4, 0xFFFF
    ctx->r4 = ctx->r20 & 0XFFFF;
    // 0x800F05E0: lhu         $a0, 0x1C($s2)
    ctx->r4 = MEM_HU(ctx->r18, 0X1C);
    // 0x800F05E4: jal         0x8003FC28
    // 0x800F05E8: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    func_8003FC28(rdram, ctx);
        goto after_32;
    // 0x800F05E8: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    after_32:
    // 0x800F05EC: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x800F05F0: beql        $v0, $s0, L_800F0614
    if (ctx->r2 == ctx->r16) {
        // 0x800F05F4: sh          $s0, 0x1A($s2)
        MEM_H(0X1A, ctx->r18) = ctx->r16;
            goto L_800F0614;
    }
    goto skip_4;
    // 0x800F05F4: sh          $s0, 0x1A($s2)
    MEM_H(0X1A, ctx->r18) = ctx->r16;
    skip_4:
    // 0x800F05F8: lhu         $a0, 0x1E($s2)
    ctx->r4 = MEM_HU(ctx->r18, 0X1E);
    // 0x800F05FC: jal         0x8004013C
    // 0x800F0600: nop

    func_8004013C(rdram, ctx);
        goto after_33;
    // 0x800F0600: nop

    after_33:
    // 0x800F0604: lhu         $a0, 0x1E($s2)
    ctx->r4 = MEM_HU(ctx->r18, 0X1E);
    // 0x800F0608: jal         0x8003E7D0
    // 0x800F060C: addu        $a1, $v0, $zero
    ctx->r5 = ADD32(ctx->r2, 0);
    func_8003E7D0(rdram, ctx);
        goto after_34;
    // 0x800F060C: addu        $a1, $v0, $zero
    ctx->r5 = ADD32(ctx->r2, 0);
    after_34:
    // 0x800F0610: sh          $s0, 0x1A($s2)
    MEM_H(0X1A, ctx->r18) = ctx->r16;
L_800F0614:
    // 0x800F0614: sh          $s0, 0x1E($s2)
    MEM_H(0X1E, ctx->r18) = ctx->r16;
    // 0x800F0618: sb          $zero, 0x20($s2)
    MEM_B(0X20, ctx->r18) = 0;
L_800F061C:
    // 0x800F061C: andi        $a0, $s4, 0xFFFF
    ctx->r4 = ctx->r20 & 0XFFFF;
    // 0x800F0620: ori         $s0, $zero, 0xFFFF
    ctx->r16 = 0 | 0XFFFF;
L_800F0624:
    // 0x800F0624: beq         $a0, $s0, L_800F0678
    if (ctx->r4 == ctx->r16) {
        // 0x800F0628: addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
            goto L_800F0678;
    }
    // 0x800F0628: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // 0x800F062C: jal         0x8004013C
    // 0x800F0630: nop

    func_8004013C(rdram, ctx);
        goto after_35;
    // 0x800F0630: nop

    after_35:
    // 0x800F0634: lhu         $a0, 0x1C($s2)
    ctx->r4 = MEM_HU(ctx->r18, 0X1C);
    // 0x800F0638: jal         0x8003E684
    // 0x800F063C: addu        $a1, $v0, $zero
    ctx->r5 = ADD32(ctx->r2, 0);
    func_8003E684(rdram, ctx);
        goto after_36;
    // 0x800F063C: addu        $a1, $v0, $zero
    ctx->r5 = ADD32(ctx->r2, 0);
    after_36:
    // 0x800F0640: sh          $v0, 0x1E($s2)
    MEM_H(0X1E, ctx->r18) = ctx->r2;
    // 0x800F0644: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x800F0648: beq         $v0, $s0, L_800F0660
    if (ctx->r2 == ctx->r16) {
        // 0x800F064C: addiu       $v1, $zero, 0x1
        ctx->r3 = ADD32(0, 0X1);
            goto L_800F0660;
    }
    // 0x800F064C: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x800F0650: addu        $v0, $v1, $zero
    ctx->r2 = ADD32(ctx->r3, 0);
    // 0x800F0654: sh          $s4, 0x1A($s2)
    MEM_H(0X1A, ctx->r18) = ctx->r20;
    // 0x800F0658: j           L_800F066C
    // 0x800F065C: sb          $v0, 0x20($s2)
    MEM_B(0X20, ctx->r18) = ctx->r2;
        goto L_800F066C;
    // 0x800F065C: sb          $v0, 0x20($s2)
    MEM_B(0X20, ctx->r18) = ctx->r2;
L_800F0660:
    // 0x800F0660: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
    // 0x800F0664: sh          $v0, 0x1A($s2)
    MEM_H(0X1A, ctx->r18) = ctx->r2;
    // 0x800F0668: sb          $zero, 0x20($s2)
    MEM_B(0X20, ctx->r18) = 0;
L_800F066C:
    // 0x800F066C: j           L_800F0678
    // 0x800F0670: addu        $v0, $v1, $zero
    ctx->r2 = ADD32(ctx->r3, 0);
        goto L_800F0678;
    // 0x800F0670: addu        $v0, $v1, $zero
    ctx->r2 = ADD32(ctx->r3, 0);
L_800F0674:
    // 0x800F0674: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_800F0678:
    // 0x800F0678: lw          $ra, 0x64($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X64);
    // 0x800F067C: lw          $fp, 0x60($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X60);
    // 0x800F0680: lw          $s7, 0x5C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X5C);
    // 0x800F0684: lw          $s6, 0x58($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X58);
    // 0x800F0688: lw          $s5, 0x54($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X54);
    // 0x800F068C: lw          $s4, 0x50($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X50);
    // 0x800F0690: lw          $s3, 0x4C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X4C);
    // 0x800F0694: lw          $s2, 0x48($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X48);
    // 0x800F0698: lw          $s1, 0x44($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X44);
    // 0x800F069C: lw          $s0, 0x40($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X40);
    // 0x800F06A0: ldc1        $f28, 0x88($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0X88);
    // 0x800F06A4: ldc1        $f26, 0x80($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X80);
    // 0x800F06A8: ldc1        $f24, 0x78($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X78);
    // 0x800F06AC: ldc1        $f22, 0x70($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X70);
    // 0x800F06B0: ldc1        $f20, 0x68($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X68);
    // 0x800F06B4: jr          $ra
    // 0x800F06B8: addiu       $sp, $sp, 0x90
    ctx->r29 = ADD32(ctx->r29, 0X90);
    return;
    // 0x800F06B8: addiu       $sp, $sp, 0x90
    ctx->r29 = ADD32(ctx->r29, 0X90);
;}
RECOMP_FUNC void func_800F06BC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F06BC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800F06C0: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x800F06C4: addiu       $s0, $a0, 0x114
    ctx->r16 = ADD32(ctx->r4, 0X114);
    // 0x800F06C8: sw          $ra, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r31;
    // 0x800F06CC: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x800F06D0: lbu         $v0, 0x21($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X21);
    // 0x800F06D4: beq         $v0, $zero, L_800F0798
    if (ctx->r2 == 0) {
        // 0x800F06D8: addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
            goto L_800F0798;
    }
    // 0x800F06D8: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // 0x800F06DC: lbu         $v0, 0x20($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X20);
    // 0x800F06E0: beq         $v0, $zero, L_800F0794
    if (ctx->r2 == 0) {
        // 0x800F06E4: ori         $s1, $zero, 0xFFFF
        ctx->r17 = 0 | 0XFFFF;
            goto L_800F0794;
    }
    // 0x800F06E4: ori         $s1, $zero, 0xFFFF
    ctx->r17 = 0 | 0XFFFF;
    // 0x800F06E8: lhu         $v0, 0x1C($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X1C);
    // 0x800F06EC: beq         $v0, $s1, L_800F0798
    if (ctx->r2 == ctx->r17) {
        // 0x800F06F0: addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
            goto L_800F0798;
    }
    // 0x800F06F0: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // 0x800F06F4: lhu         $v0, 0x1E($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X1E);
    // 0x800F06F8: beq         $v0, $s1, L_800F0798
    if (ctx->r2 == ctx->r17) {
        // 0x800F06FC: addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
            goto L_800F0798;
    }
    // 0x800F06FC: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // 0x800F0700: lhu         $v0, 0x1A($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X1A);
    // 0x800F0704: beq         $v0, $s1, L_800F0798
    if (ctx->r2 == ctx->r17) {
        // 0x800F0708: addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
            goto L_800F0798;
    }
    // 0x800F0708: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // 0x800F070C: lhu         $a0, 0x1C($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X1C);
    // 0x800F0710: jal         0x8003FC28
    // 0x800F0714: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    func_8003FC28(rdram, ctx);
        goto after_0;
    // 0x800F0714: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    after_0:
    // 0x800F0718: andi        $a0, $v0, 0xFFFF
    ctx->r4 = ctx->r2 & 0XFFFF;
    // 0x800F071C: beq         $a0, $s1, L_800F073C
    if (ctx->r4 == ctx->r17) {
        // 0x800F0720: nop
    
            goto L_800F073C;
    }
    // 0x800F0720: nop

    // 0x800F0724: jal         0x8004013C
    // 0x800F0728: nop

    func_8004013C(rdram, ctx);
        goto after_1;
    // 0x800F0728: nop

    after_1:
    // 0x800F072C: lhu         $v0, 0x14($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X14);
    // 0x800F0730: andi        $v0, $v0, 0x10
    ctx->r2 = ctx->r2 & 0X10;
    // 0x800F0734: beq         $v0, $zero, L_800F0798
    if (ctx->r2 == 0) {
        // 0x800F0738: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_800F0798;
    }
    // 0x800F0738: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800F073C:
    // 0x800F073C: lbu         $v1, 0x20($s0)
    ctx->r3 = MEM_BU(ctx->r16, 0X20);
    // 0x800F0740: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800F0744: bne         $v1, $v0, L_800F0798
    if (ctx->r3 != ctx->r2) {
        // 0x800F0748: addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
            goto L_800F0798;
    }
    // 0x800F0748: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // 0x800F074C: lhu         $v0, 0x1A($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X1A);
    // 0x800F0750: beq         $v0, $s1, L_800F0798
    if (ctx->r2 == ctx->r17) {
        // 0x800F0754: addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
            goto L_800F0798;
    }
    // 0x800F0754: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // 0x800F0758: lhu         $a0, 0x1C($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X1C);
    // 0x800F075C: jal         0x8003FC28
    // 0x800F0760: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    func_8003FC28(rdram, ctx);
        goto after_2;
    // 0x800F0760: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    after_2:
    // 0x800F0764: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x800F0768: beql        $v0, $s1, L_800F078C
    if (ctx->r2 == ctx->r17) {
        // 0x800F076C: sh          $s1, 0x1A($s0)
        MEM_H(0X1A, ctx->r16) = ctx->r17;
            goto L_800F078C;
    }
    goto skip_0;
    // 0x800F076C: sh          $s1, 0x1A($s0)
    MEM_H(0X1A, ctx->r16) = ctx->r17;
    skip_0:
    // 0x800F0770: lhu         $a0, 0x1E($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X1E);
    // 0x800F0774: jal         0x8004013C
    // 0x800F0778: nop

    func_8004013C(rdram, ctx);
        goto after_3;
    // 0x800F0778: nop

    after_3:
    // 0x800F077C: lhu         $a0, 0x1E($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X1E);
    // 0x800F0780: jal         0x8003E7D0
    // 0x800F0784: addu        $a1, $v0, $zero
    ctx->r5 = ADD32(ctx->r2, 0);
    func_8003E7D0(rdram, ctx);
        goto after_4;
    // 0x800F0784: addu        $a1, $v0, $zero
    ctx->r5 = ADD32(ctx->r2, 0);
    after_4:
    // 0x800F0788: sh          $s1, 0x1A($s0)
    MEM_H(0X1A, ctx->r16) = ctx->r17;
L_800F078C:
    // 0x800F078C: sh          $s1, 0x1E($s0)
    MEM_H(0X1E, ctx->r16) = ctx->r17;
    // 0x800F0790: sb          $zero, 0x20($s0)
    MEM_B(0X20, ctx->r16) = 0;
L_800F0794:
    // 0x800F0794: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_800F0798:
    // 0x800F0798: lw          $ra, 0x18($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X18);
    // 0x800F079C: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x800F07A0: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x800F07A4: jr          $ra
    // 0x800F07A8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x800F07A8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_800F07AC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F07AC: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x800F07B0: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x800F07B4: addu        $s3, $a0, $zero
    ctx->r19 = ADD32(ctx->r4, 0);
    // 0x800F07B8: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x800F07BC: addiu       $s0, $s3, 0x114
    ctx->r16 = ADD32(ctx->r19, 0X114);
    // 0x800F07C0: sw          $ra, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r31;
    // 0x800F07C4: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x800F07C8: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x800F07CC: sdc1        $f26, 0x50($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X50, ctx->r29);
    // 0x800F07D0: sdc1        $f24, 0x48($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X48, ctx->r29);
    // 0x800F07D4: sdc1        $f22, 0x40($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X40, ctx->r29);
    // 0x800F07D8: sdc1        $f20, 0x38($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X38, ctx->r29);
    // 0x800F07DC: lbu         $v0, 0x21($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X21);
    // 0x800F07E0: beq         $v0, $zero, L_800F097C
    if (ctx->r2 == 0) {
        // 0x800F07E4: addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
            goto L_800F097C;
    }
    // 0x800F07E4: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // 0x800F07E8: lbu         $v0, 0x20($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X20);
    // 0x800F07EC: beq         $v0, $zero, L_800F0978
    if (ctx->r2 == 0) {
        // 0x800F07F0: ori         $s2, $zero, 0xFFFF
        ctx->r18 = 0 | 0XFFFF;
            goto L_800F0978;
    }
    // 0x800F07F0: ori         $s2, $zero, 0xFFFF
    ctx->r18 = 0 | 0XFFFF;
    // 0x800F07F4: lhu         $v0, 0x1C($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X1C);
    // 0x800F07F8: beq         $v0, $s2, L_800F097C
    if (ctx->r2 == ctx->r18) {
        // 0x800F07FC: addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
            goto L_800F097C;
    }
    // 0x800F07FC: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // 0x800F0800: lhu         $v0, 0x1E($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X1E);
    // 0x800F0804: beq         $v0, $s2, L_800F097C
    if (ctx->r2 == ctx->r18) {
        // 0x800F0808: addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
            goto L_800F097C;
    }
    // 0x800F0808: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // 0x800F080C: lhu         $v0, 0x1A($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X1A);
    // 0x800F0810: beq         $v0, $s2, L_800F097C
    if (ctx->r2 == ctx->r18) {
        // 0x800F0814: addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
            goto L_800F097C;
    }
    // 0x800F0814: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // 0x800F0818: lhu         $a0, 0x1C($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X1C);
    // 0x800F081C: jal         0x8003FC28
    // 0x800F0820: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    func_8003FC28(rdram, ctx);
        goto after_0;
    // 0x800F0820: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    after_0:
    // 0x800F0824: andi        $s1, $v0, 0xFFFF
    ctx->r17 = ctx->r2 & 0XFFFF;
    // 0x800F0828: beq         $s1, $s2, L_800F0848
    if (ctx->r17 == ctx->r18) {
        // 0x800F082C: nop
    
            goto L_800F0848;
    }
    // 0x800F082C: nop

    // 0x800F0830: jal         0x8004013C
    // 0x800F0834: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    func_8004013C(rdram, ctx);
        goto after_1;
    // 0x800F0834: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    after_1:
    // 0x800F0838: lhu         $v0, 0x14($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X14);
    // 0x800F083C: andi        $v0, $v0, 0x10
    ctx->r2 = ctx->r2 & 0X10;
    // 0x800F0840: beq         $v0, $zero, L_800F08A4
    if (ctx->r2 == 0) {
        // 0x800F0844: nop
    
            goto L_800F08A4;
    }
    // 0x800F0844: nop

L_800F0848:
    // 0x800F0848: lbu         $v1, 0x20($s0)
    ctx->r3 = MEM_BU(ctx->r16, 0X20);
    // 0x800F084C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800F0850: bne         $v1, $v0, L_800F097C
    if (ctx->r3 != ctx->r2) {
        // 0x800F0854: addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
            goto L_800F097C;
    }
    // 0x800F0854: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // 0x800F0858: lhu         $v0, 0x1A($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X1A);
    // 0x800F085C: beq         $v0, $s2, L_800F097C
    if (ctx->r2 == ctx->r18) {
        // 0x800F0860: addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
            goto L_800F097C;
    }
    // 0x800F0860: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // 0x800F0864: lhu         $a0, 0x1C($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X1C);
    // 0x800F0868: jal         0x8003FC28
    // 0x800F086C: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    func_8003FC28(rdram, ctx);
        goto after_2;
    // 0x800F086C: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    after_2:
    // 0x800F0870: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x800F0874: beql        $v0, $s2, L_800F0898
    if (ctx->r2 == ctx->r18) {
        // 0x800F0878: sh          $s2, 0x1A($s0)
        MEM_H(0X1A, ctx->r16) = ctx->r18;
            goto L_800F0898;
    }
    goto skip_0;
    // 0x800F0878: sh          $s2, 0x1A($s0)
    MEM_H(0X1A, ctx->r16) = ctx->r18;
    skip_0:
    // 0x800F087C: lhu         $a0, 0x1E($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X1E);
    // 0x800F0880: jal         0x8004013C
    // 0x800F0884: nop

    func_8004013C(rdram, ctx);
        goto after_3;
    // 0x800F0884: nop

    after_3:
    // 0x800F0888: lhu         $a0, 0x1E($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X1E);
    // 0x800F088C: jal         0x8003E7D0
    // 0x800F0890: addu        $a1, $v0, $zero
    ctx->r5 = ADD32(ctx->r2, 0);
    func_8003E7D0(rdram, ctx);
        goto after_4;
    // 0x800F0890: addu        $a1, $v0, $zero
    ctx->r5 = ADD32(ctx->r2, 0);
    after_4:
    // 0x800F0894: sh          $s2, 0x1A($s0)
    MEM_H(0X1A, ctx->r16) = ctx->r18;
L_800F0898:
    // 0x800F0898: sh          $s2, 0x1E($s0)
    MEM_H(0X1E, ctx->r16) = ctx->r18;
    // 0x800F089C: j           L_800F0978
    // 0x800F08A0: sb          $zero, 0x20($s0)
    MEM_B(0X20, ctx->r16) = 0;
        goto L_800F0978;
    // 0x800F08A0: sb          $zero, 0x20($s0)
    MEM_B(0X20, ctx->r16) = 0;
L_800F08A4:
    // 0x800F08A4: lhu         $a0, 0x198($s3)
    ctx->r4 = MEM_HU(ctx->r19, 0X198);
    // 0x800F08A8: jal         0x8004015C
    // 0x800F08AC: nop

    func_8004015C(rdram, ctx);
        goto after_5;
    // 0x800F08AC: nop

    after_5:
    // 0x800F08B0: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x800F08B4: jal         0x8004015C
    // 0x800F08B8: addu        $s1, $v0, $zero
    ctx->r17 = ADD32(ctx->r2, 0);
    func_8004015C(rdram, ctx);
        goto after_6;
    // 0x800F08B8: addu        $s1, $v0, $zero
    ctx->r17 = ADD32(ctx->r2, 0);
    after_6:
    // 0x800F08BC: lwc1        $f4, 0x0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X0);
    // 0x800F08C0: lwc1        $f0, 0x0($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X0);
    // 0x800F08C4: sub.s       $f4, $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f4.fl - ctx->f0.fl;
    // 0x800F08C8: lwc1        $f6, 0xC($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XC);
    // 0x800F08CC: lwc1        $f26, 0x8($s0)
    ctx->f26.u32l = MEM_W(ctx->r16, 0X8);
    // 0x800F08D0: mul.s       $f6, $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f6.fl = MUL_S(ctx->f6.fl, ctx->f6.fl);
    // 0x800F08D4: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x800F08D8: lwc1        $f0, 0x4($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X4);
    // 0x800F08DC: lwc1        $f2, 0x4($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0X4);
    // 0x800F08E0: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x800F08E4: mul.s       $f4, $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f4.fl = MUL_S(ctx->f4.fl, ctx->f4.fl);
    // 0x800F08E8: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    // 0x800F08EC: lwc1        $f0, 0x8($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X8);
    // 0x800F08F0: lwc1        $f2, 0x8($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0X8);
    // 0x800F08F4: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x800F08F8: mul.s       $f2, $f0, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x800F08FC: add.s       $f24, $f4, $f2
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f24.fl = ctx->f4.fl + ctx->f2.fl;
    // 0x800F0900: c.lt.s      $f6, $f24
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 24);
    c1cs = ctx->f6.fl < ctx->f24.fl;
    // 0x800F0904: nop

    // 0x800F0908: bc1t        L_800F0978
    if (c1cs) {
        // 0x800F090C: swc1        $f0, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
            goto L_800F0978;
    }
    // 0x800F090C: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    // 0x800F0910: addiu       $s0, $s1, 0xC
    ctx->r16 = ADD32(ctx->r17, 0XC);
    // 0x800F0914: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x800F0918: jal         0x8001CFE8
    // 0x800F091C: addiu       $a1, $sp, 0x10
    ctx->r5 = ADD32(ctx->r29, 0X10);
    func_8001CFE8(rdram, ctx);
        goto after_7;
    // 0x800F091C: addiu       $a1, $sp, 0x10
    ctx->r5 = ADD32(ctx->r29, 0X10);
    after_7:
    // 0x800F0920: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x800F0924: jal         0x8001CF2C
    // 0x800F0928: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
    func_8001CF2C(rdram, ctx);
        goto after_8;
    // 0x800F0928: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
    after_8:
    // 0x800F092C: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    // 0x800F0930: jal         0x8001CF2C
    // 0x800F0934: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    func_8001CF2C(rdram, ctx);
        goto after_9;
    // 0x800F0934: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    after_9:
    // 0x800F0938: mul.s       $f20, $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f20.fl = MUL_S(ctx->f20.fl, ctx->f0.fl);
    // 0x800F093C: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800F0940: lwc1        $f0, -0x7658($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X7658);
    // 0x800F0944: c.lt.s      $f24, $f0
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f24.fl < ctx->f0.fl;
    // 0x800F0948: nop

    // 0x800F094C: bc1f        L_800F0968
    if (!c1cs) {
        // 0x800F0950: div.s       $f22, $f22, $f20
        CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f22.fl = DIV_S(ctx->f22.fl, ctx->f20.fl);
            goto L_800F0968;
    }
    // 0x800F0950: div.s       $f22, $f22, $f20
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f22.fl = DIV_S(ctx->f22.fl, ctx->f20.fl);
    // 0x800F0954: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800F0958: c.le.s      $f0, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    c1cs = ctx->f0.fl <= ctx->f22.fl;
    // 0x800F095C: nop

    // 0x800F0960: bc1t        L_800F097C
    if (c1cs) {
        // 0x800F0964: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_800F097C;
    }
    // 0x800F0964: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800F0968:
    // 0x800F0968: c.lt.s      $f22, $f26
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 26);
    c1cs = ctx->f22.fl < ctx->f26.fl;
    // 0x800F096C: nop

    // 0x800F0970: bc1f        L_800F097C
    if (!c1cs) {
        // 0x800F0974: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_800F097C;
    }
    // 0x800F0974: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800F0978:
    // 0x800F0978: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_800F097C:
    // 0x800F097C: lw          $ra, 0x30($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X30);
    // 0x800F0980: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x800F0984: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x800F0988: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x800F098C: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x800F0990: ldc1        $f26, 0x50($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X50);
    // 0x800F0994: ldc1        $f24, 0x48($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X48);
    // 0x800F0998: ldc1        $f22, 0x40($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X40);
    // 0x800F099C: ldc1        $f20, 0x38($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X38);
    // 0x800F09A0: jr          $ra
    // 0x800F09A4: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    return;
    // 0x800F09A4: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
;}
RECOMP_FUNC void func_800F09A8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F09A8: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x800F09AC: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x800F09B0: addu        $s3, $a0, $zero
    ctx->r19 = ADD32(ctx->r4, 0);
    // 0x800F09B4: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x800F09B8: addiu       $s0, $s3, 0x114
    ctx->r16 = ADD32(ctx->r19, 0X114);
    // 0x800F09BC: sw          $ra, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r31;
    // 0x800F09C0: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x800F09C4: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x800F09C8: sdc1        $f26, 0x50($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X50, ctx->r29);
    // 0x800F09CC: sdc1        $f24, 0x48($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X48, ctx->r29);
    // 0x800F09D0: sdc1        $f22, 0x40($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X40, ctx->r29);
    // 0x800F09D4: sdc1        $f20, 0x38($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X38, ctx->r29);
    // 0x800F09D8: lbu         $v0, 0x21($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X21);
    // 0x800F09DC: beq         $v0, $zero, L_800F0B78
    if (ctx->r2 == 0) {
        // 0x800F09E0: addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
            goto L_800F0B78;
    }
    // 0x800F09E0: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // 0x800F09E4: lbu         $v0, 0x20($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X20);
    // 0x800F09E8: beq         $v0, $zero, L_800F0B74
    if (ctx->r2 == 0) {
        // 0x800F09EC: ori         $s2, $zero, 0xFFFF
        ctx->r18 = 0 | 0XFFFF;
            goto L_800F0B74;
    }
    // 0x800F09EC: ori         $s2, $zero, 0xFFFF
    ctx->r18 = 0 | 0XFFFF;
    // 0x800F09F0: lhu         $v0, 0x1C($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X1C);
    // 0x800F09F4: beq         $v0, $s2, L_800F0B78
    if (ctx->r2 == ctx->r18) {
        // 0x800F09F8: addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
            goto L_800F0B78;
    }
    // 0x800F09F8: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // 0x800F09FC: lhu         $v0, 0x1E($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X1E);
    // 0x800F0A00: beq         $v0, $s2, L_800F0B78
    if (ctx->r2 == ctx->r18) {
        // 0x800F0A04: addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
            goto L_800F0B78;
    }
    // 0x800F0A04: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // 0x800F0A08: lhu         $v0, 0x1A($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X1A);
    // 0x800F0A0C: beq         $v0, $s2, L_800F0B78
    if (ctx->r2 == ctx->r18) {
        // 0x800F0A10: addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
            goto L_800F0B78;
    }
    // 0x800F0A10: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // 0x800F0A14: lhu         $a0, 0x1C($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X1C);
    // 0x800F0A18: jal         0x8003FC28
    // 0x800F0A1C: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    func_8003FC28(rdram, ctx);
        goto after_0;
    // 0x800F0A1C: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    after_0:
    // 0x800F0A20: andi        $s1, $v0, 0xFFFF
    ctx->r17 = ctx->r2 & 0XFFFF;
    // 0x800F0A24: beq         $s1, $s2, L_800F0A44
    if (ctx->r17 == ctx->r18) {
        // 0x800F0A28: nop
    
            goto L_800F0A44;
    }
    // 0x800F0A28: nop

    // 0x800F0A2C: jal         0x8004013C
    // 0x800F0A30: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    func_8004013C(rdram, ctx);
        goto after_1;
    // 0x800F0A30: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    after_1:
    // 0x800F0A34: lhu         $v0, 0x14($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X14);
    // 0x800F0A38: andi        $v0, $v0, 0x10
    ctx->r2 = ctx->r2 & 0X10;
    // 0x800F0A3C: beq         $v0, $zero, L_800F0AA0
    if (ctx->r2 == 0) {
        // 0x800F0A40: nop
    
            goto L_800F0AA0;
    }
    // 0x800F0A40: nop

L_800F0A44:
    // 0x800F0A44: lbu         $v1, 0x20($s0)
    ctx->r3 = MEM_BU(ctx->r16, 0X20);
    // 0x800F0A48: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800F0A4C: bne         $v1, $v0, L_800F0B78
    if (ctx->r3 != ctx->r2) {
        // 0x800F0A50: addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
            goto L_800F0B78;
    }
    // 0x800F0A50: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // 0x800F0A54: lhu         $v0, 0x1A($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X1A);
    // 0x800F0A58: beq         $v0, $s2, L_800F0B78
    if (ctx->r2 == ctx->r18) {
        // 0x800F0A5C: addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
            goto L_800F0B78;
    }
    // 0x800F0A5C: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // 0x800F0A60: lhu         $a0, 0x1C($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X1C);
    // 0x800F0A64: jal         0x8003FC28
    // 0x800F0A68: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    func_8003FC28(rdram, ctx);
        goto after_2;
    // 0x800F0A68: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    after_2:
    // 0x800F0A6C: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x800F0A70: beql        $v0, $s2, L_800F0A94
    if (ctx->r2 == ctx->r18) {
        // 0x800F0A74: sh          $s2, 0x1A($s0)
        MEM_H(0X1A, ctx->r16) = ctx->r18;
            goto L_800F0A94;
    }
    goto skip_0;
    // 0x800F0A74: sh          $s2, 0x1A($s0)
    MEM_H(0X1A, ctx->r16) = ctx->r18;
    skip_0:
    // 0x800F0A78: lhu         $a0, 0x1E($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X1E);
    // 0x800F0A7C: jal         0x8004013C
    // 0x800F0A80: nop

    func_8004013C(rdram, ctx);
        goto after_3;
    // 0x800F0A80: nop

    after_3:
    // 0x800F0A84: lhu         $a0, 0x1E($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X1E);
    // 0x800F0A88: jal         0x8003E7D0
    // 0x800F0A8C: addu        $a1, $v0, $zero
    ctx->r5 = ADD32(ctx->r2, 0);
    func_8003E7D0(rdram, ctx);
        goto after_4;
    // 0x800F0A8C: addu        $a1, $v0, $zero
    ctx->r5 = ADD32(ctx->r2, 0);
    after_4:
    // 0x800F0A90: sh          $s2, 0x1A($s0)
    MEM_H(0X1A, ctx->r16) = ctx->r18;
L_800F0A94:
    // 0x800F0A94: sh          $s2, 0x1E($s0)
    MEM_H(0X1E, ctx->r16) = ctx->r18;
    // 0x800F0A98: j           L_800F0B74
    // 0x800F0A9C: sb          $zero, 0x20($s0)
    MEM_B(0X20, ctx->r16) = 0;
        goto L_800F0B74;
    // 0x800F0A9C: sb          $zero, 0x20($s0)
    MEM_B(0X20, ctx->r16) = 0;
L_800F0AA0:
    // 0x800F0AA0: lhu         $a0, 0x198($s3)
    ctx->r4 = MEM_HU(ctx->r19, 0X198);
    // 0x800F0AA4: jal         0x8004015C
    // 0x800F0AA8: nop

    func_8004015C(rdram, ctx);
        goto after_5;
    // 0x800F0AA8: nop

    after_5:
    // 0x800F0AAC: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x800F0AB0: jal         0x8004015C
    // 0x800F0AB4: addu        $s1, $v0, $zero
    ctx->r17 = ADD32(ctx->r2, 0);
    func_8004015C(rdram, ctx);
        goto after_6;
    // 0x800F0AB4: addu        $s1, $v0, $zero
    ctx->r17 = ADD32(ctx->r2, 0);
    after_6:
    // 0x800F0AB8: lwc1        $f4, 0x0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X0);
    // 0x800F0ABC: lwc1        $f0, 0x0($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X0);
    // 0x800F0AC0: sub.s       $f4, $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f4.fl - ctx->f0.fl;
    // 0x800F0AC4: lwc1        $f6, 0x4($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X4);
    // 0x800F0AC8: lwc1        $f26, 0x114($s3)
    ctx->f26.u32l = MEM_W(ctx->r19, 0X114);
    // 0x800F0ACC: mul.s       $f6, $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f6.fl = MUL_S(ctx->f6.fl, ctx->f6.fl);
    // 0x800F0AD0: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x800F0AD4: lwc1        $f0, 0x4($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X4);
    // 0x800F0AD8: lwc1        $f2, 0x4($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0X4);
    // 0x800F0ADC: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x800F0AE0: mul.s       $f4, $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f4.fl = MUL_S(ctx->f4.fl, ctx->f4.fl);
    // 0x800F0AE4: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    // 0x800F0AE8: lwc1        $f0, 0x8($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X8);
    // 0x800F0AEC: lwc1        $f2, 0x8($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0X8);
    // 0x800F0AF0: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x800F0AF4: mul.s       $f2, $f0, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x800F0AF8: add.s       $f24, $f4, $f2
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f24.fl = ctx->f4.fl + ctx->f2.fl;
    // 0x800F0AFC: c.lt.s      $f6, $f24
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 24);
    c1cs = ctx->f6.fl < ctx->f24.fl;
    // 0x800F0B00: nop

    // 0x800F0B04: bc1t        L_800F0B74
    if (c1cs) {
        // 0x800F0B08: swc1        $f0, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
            goto L_800F0B74;
    }
    // 0x800F0B08: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    // 0x800F0B0C: addiu       $s0, $s1, 0xC
    ctx->r16 = ADD32(ctx->r17, 0XC);
    // 0x800F0B10: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x800F0B14: jal         0x8001CFE8
    // 0x800F0B18: addiu       $a1, $sp, 0x10
    ctx->r5 = ADD32(ctx->r29, 0X10);
    func_8001CFE8(rdram, ctx);
        goto after_7;
    // 0x800F0B18: addiu       $a1, $sp, 0x10
    ctx->r5 = ADD32(ctx->r29, 0X10);
    after_7:
    // 0x800F0B1C: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x800F0B20: jal         0x8001CF2C
    // 0x800F0B24: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
    func_8001CF2C(rdram, ctx);
        goto after_8;
    // 0x800F0B24: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
    after_8:
    // 0x800F0B28: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    // 0x800F0B2C: jal         0x8001CF2C
    // 0x800F0B30: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    func_8001CF2C(rdram, ctx);
        goto after_9;
    // 0x800F0B30: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    after_9:
    // 0x800F0B34: mul.s       $f20, $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f20.fl = MUL_S(ctx->f20.fl, ctx->f0.fl);
    // 0x800F0B38: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800F0B3C: lwc1        $f0, -0x7654($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X7654);
    // 0x800F0B40: c.lt.s      $f24, $f0
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f24.fl < ctx->f0.fl;
    // 0x800F0B44: nop

    // 0x800F0B48: bc1f        L_800F0B64
    if (!c1cs) {
        // 0x800F0B4C: div.s       $f22, $f22, $f20
        CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f22.fl = DIV_S(ctx->f22.fl, ctx->f20.fl);
            goto L_800F0B64;
    }
    // 0x800F0B4C: div.s       $f22, $f22, $f20
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f22.fl = DIV_S(ctx->f22.fl, ctx->f20.fl);
    // 0x800F0B50: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800F0B54: c.le.s      $f0, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    c1cs = ctx->f0.fl <= ctx->f22.fl;
    // 0x800F0B58: nop

    // 0x800F0B5C: bc1t        L_800F0B78
    if (c1cs) {
        // 0x800F0B60: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_800F0B78;
    }
    // 0x800F0B60: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800F0B64:
    // 0x800F0B64: c.lt.s      $f22, $f26
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 26);
    c1cs = ctx->f22.fl < ctx->f26.fl;
    // 0x800F0B68: nop

    // 0x800F0B6C: bc1f        L_800F0B78
    if (!c1cs) {
        // 0x800F0B70: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_800F0B78;
    }
    // 0x800F0B70: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800F0B74:
    // 0x800F0B74: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_800F0B78:
    // 0x800F0B78: lw          $ra, 0x30($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X30);
    // 0x800F0B7C: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x800F0B80: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x800F0B84: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x800F0B88: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x800F0B8C: ldc1        $f26, 0x50($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X50);
    // 0x800F0B90: ldc1        $f24, 0x48($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X48);
    // 0x800F0B94: ldc1        $f22, 0x40($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X40);
    // 0x800F0B98: ldc1        $f20, 0x38($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X38);
    // 0x800F0B9C: jr          $ra
    // 0x800F0BA0: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    return;
    // 0x800F0BA0: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
;}
RECOMP_FUNC void func_800F0BA4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F0BA4: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x800F0BA8: sdc1        $f22, 0x40($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X40, ctx->r29);
    // 0x800F0BAC: mtc1        $a1, $f22
    ctx->f22.u32l = ctx->r5;
    // 0x800F0BB0: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x800F0BB4: addu        $s3, $a0, $zero
    ctx->r19 = ADD32(ctx->r4, 0);
    // 0x800F0BB8: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x800F0BBC: addiu       $s0, $s3, 0x114
    ctx->r16 = ADD32(ctx->r19, 0X114);
    // 0x800F0BC0: sw          $ra, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r31;
    // 0x800F0BC4: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x800F0BC8: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x800F0BCC: sdc1        $f26, 0x50($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X50, ctx->r29);
    // 0x800F0BD0: sdc1        $f24, 0x48($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X48, ctx->r29);
    // 0x800F0BD4: sdc1        $f20, 0x38($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X38, ctx->r29);
    // 0x800F0BD8: lbu         $v0, 0x21($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X21);
    // 0x800F0BDC: mtc1        $a2, $f20
    ctx->f20.u32l = ctx->r6;
    // 0x800F0BE0: beq         $v0, $zero, L_800F0D98
    if (ctx->r2 == 0) {
        // 0x800F0BE4: addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
            goto L_800F0D98;
    }
    // 0x800F0BE4: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // 0x800F0BE8: lbu         $v0, 0x20($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X20);
    // 0x800F0BEC: beq         $v0, $zero, L_800F0D94
    if (ctx->r2 == 0) {
        // 0x800F0BF0: ori         $s2, $zero, 0xFFFF
        ctx->r18 = 0 | 0XFFFF;
            goto L_800F0D94;
    }
    // 0x800F0BF0: ori         $s2, $zero, 0xFFFF
    ctx->r18 = 0 | 0XFFFF;
    // 0x800F0BF4: lhu         $v0, 0x1C($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X1C);
    // 0x800F0BF8: beq         $v0, $s2, L_800F0D98
    if (ctx->r2 == ctx->r18) {
        // 0x800F0BFC: addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
            goto L_800F0D98;
    }
    // 0x800F0BFC: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // 0x800F0C00: lhu         $v0, 0x1E($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X1E);
    // 0x800F0C04: beq         $v0, $s2, L_800F0D98
    if (ctx->r2 == ctx->r18) {
        // 0x800F0C08: addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
            goto L_800F0D98;
    }
    // 0x800F0C08: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // 0x800F0C0C: lhu         $v0, 0x1A($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X1A);
    // 0x800F0C10: beq         $v0, $s2, L_800F0D98
    if (ctx->r2 == ctx->r18) {
        // 0x800F0C14: addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
            goto L_800F0D98;
    }
    // 0x800F0C14: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // 0x800F0C18: lhu         $a0, 0x1C($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X1C);
    // 0x800F0C1C: jal         0x8003FC28
    // 0x800F0C20: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    func_8003FC28(rdram, ctx);
        goto after_0;
    // 0x800F0C20: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    after_0:
    // 0x800F0C24: andi        $s1, $v0, 0xFFFF
    ctx->r17 = ctx->r2 & 0XFFFF;
    // 0x800F0C28: beq         $s1, $s2, L_800F0C48
    if (ctx->r17 == ctx->r18) {
        // 0x800F0C2C: nop
    
            goto L_800F0C48;
    }
    // 0x800F0C2C: nop

    // 0x800F0C30: jal         0x8004013C
    // 0x800F0C34: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    func_8004013C(rdram, ctx);
        goto after_1;
    // 0x800F0C34: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    after_1:
    // 0x800F0C38: lhu         $v0, 0x14($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X14);
    // 0x800F0C3C: andi        $v0, $v0, 0x10
    ctx->r2 = ctx->r2 & 0X10;
    // 0x800F0C40: beq         $v0, $zero, L_800F0CA4
    if (ctx->r2 == 0) {
        // 0x800F0C44: nop
    
            goto L_800F0CA4;
    }
    // 0x800F0C44: nop

L_800F0C48:
    // 0x800F0C48: lbu         $v1, 0x20($s0)
    ctx->r3 = MEM_BU(ctx->r16, 0X20);
    // 0x800F0C4C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800F0C50: bne         $v1, $v0, L_800F0D98
    if (ctx->r3 != ctx->r2) {
        // 0x800F0C54: addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
            goto L_800F0D98;
    }
    // 0x800F0C54: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // 0x800F0C58: lhu         $v0, 0x1A($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X1A);
    // 0x800F0C5C: beq         $v0, $s2, L_800F0D98
    if (ctx->r2 == ctx->r18) {
        // 0x800F0C60: addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
            goto L_800F0D98;
    }
    // 0x800F0C60: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // 0x800F0C64: lhu         $a0, 0x1C($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X1C);
    // 0x800F0C68: jal         0x8003FC28
    // 0x800F0C6C: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    func_8003FC28(rdram, ctx);
        goto after_2;
    // 0x800F0C6C: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    after_2:
    // 0x800F0C70: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x800F0C74: beql        $v0, $s2, L_800F0C98
    if (ctx->r2 == ctx->r18) {
        // 0x800F0C78: sh          $s2, 0x1A($s0)
        MEM_H(0X1A, ctx->r16) = ctx->r18;
            goto L_800F0C98;
    }
    goto skip_0;
    // 0x800F0C78: sh          $s2, 0x1A($s0)
    MEM_H(0X1A, ctx->r16) = ctx->r18;
    skip_0:
    // 0x800F0C7C: lhu         $a0, 0x1E($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X1E);
    // 0x800F0C80: jal         0x8004013C
    // 0x800F0C84: nop

    func_8004013C(rdram, ctx);
        goto after_3;
    // 0x800F0C84: nop

    after_3:
    // 0x800F0C88: lhu         $a0, 0x1E($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X1E);
    // 0x800F0C8C: jal         0x8003E7D0
    // 0x800F0C90: addu        $a1, $v0, $zero
    ctx->r5 = ADD32(ctx->r2, 0);
    func_8003E7D0(rdram, ctx);
        goto after_4;
    // 0x800F0C90: addu        $a1, $v0, $zero
    ctx->r5 = ADD32(ctx->r2, 0);
    after_4:
    // 0x800F0C94: sh          $s2, 0x1A($s0)
    MEM_H(0X1A, ctx->r16) = ctx->r18;
L_800F0C98:
    // 0x800F0C98: sh          $s2, 0x1E($s0)
    MEM_H(0X1E, ctx->r16) = ctx->r18;
    // 0x800F0C9C: j           L_800F0D94
    // 0x800F0CA0: sb          $zero, 0x20($s0)
    MEM_B(0X20, ctx->r16) = 0;
        goto L_800F0D94;
    // 0x800F0CA0: sb          $zero, 0x20($s0)
    MEM_B(0X20, ctx->r16) = 0;
L_800F0CA4:
    // 0x800F0CA4: lhu         $a0, 0x198($s3)
    ctx->r4 = MEM_HU(ctx->r19, 0X198);
    // 0x800F0CA8: jal         0x8004015C
    // 0x800F0CAC: nop

    func_8004015C(rdram, ctx);
        goto after_5;
    // 0x800F0CAC: nop

    after_5:
    // 0x800F0CB0: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800F0CB4: lwc1        $f12, -0x7650($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X7650);
    // 0x800F0CB8: mul.s       $f12, $f20, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = MUL_S(ctx->f20.fl, ctx->f12.fl);
    // 0x800F0CBC: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800F0CC0: lwc1        $f20, -0x764C($at)
    ctx->f20.u32l = MEM_W(ctx->r1, -0X764C);
    // 0x800F0CC4: mul.s       $f20, $f22, $f20
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f20.fl = MUL_S(ctx->f22.fl, ctx->f20.fl);
    // 0x800F0CC8: jal         0x8002B190
    // 0x800F0CCC: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    cosf_recomp(rdram, ctx);
        goto after_6;
    // 0x800F0CCC: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    after_6:
    // 0x800F0CD0: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x800F0CD4: jal         0x8004015C
    // 0x800F0CD8: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
    func_8004015C(rdram, ctx);
        goto after_7;
    // 0x800F0CD8: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
    after_7:
    // 0x800F0CDC: lwc1        $f4, 0x0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X0);
    // 0x800F0CE0: lwc1        $f0, 0x0($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X0);
    // 0x800F0CE4: sub.s       $f4, $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f4.fl - ctx->f0.fl;
    // 0x800F0CE8: mul.s       $f20, $f20, $f20
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f20.fl = MUL_S(ctx->f20.fl, ctx->f20.fl);
    // 0x800F0CEC: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x800F0CF0: lwc1        $f0, 0x4($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X4);
    // 0x800F0CF4: lwc1        $f2, 0x4($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X4);
    // 0x800F0CF8: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x800F0CFC: mul.s       $f4, $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f4.fl = MUL_S(ctx->f4.fl, ctx->f4.fl);
    // 0x800F0D00: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    // 0x800F0D04: lwc1        $f0, 0x8($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X8);
    // 0x800F0D08: lwc1        $f2, 0x8($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X8);
    // 0x800F0D0C: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x800F0D10: mul.s       $f2, $f0, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x800F0D14: add.s       $f24, $f4, $f2
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f24.fl = ctx->f4.fl + ctx->f2.fl;
    // 0x800F0D18: mov.s       $f26, $f22
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 22);
    ctx->f26.fl = ctx->f22.fl;
    // 0x800F0D1C: c.lt.s      $f20, $f24
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 24);
    c1cs = ctx->f20.fl < ctx->f24.fl;
    // 0x800F0D20: nop

    // 0x800F0D24: bc1t        L_800F0D94
    if (c1cs) {
        // 0x800F0D28: swc1        $f0, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
            goto L_800F0D94;
    }
    // 0x800F0D28: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    // 0x800F0D2C: addiu       $s0, $s0, 0xC
    ctx->r16 = ADD32(ctx->r16, 0XC);
    // 0x800F0D30: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x800F0D34: jal         0x8001CFE8
    // 0x800F0D38: addiu       $a1, $sp, 0x10
    ctx->r5 = ADD32(ctx->r29, 0X10);
    func_8001CFE8(rdram, ctx);
        goto after_8;
    // 0x800F0D38: addiu       $a1, $sp, 0x10
    ctx->r5 = ADD32(ctx->r29, 0X10);
    after_8:
    // 0x800F0D3C: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x800F0D40: jal         0x8001CF2C
    // 0x800F0D44: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
    func_8001CF2C(rdram, ctx);
        goto after_9;
    // 0x800F0D44: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
    after_9:
    // 0x800F0D48: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    // 0x800F0D4C: jal         0x8001CF2C
    // 0x800F0D50: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    func_8001CF2C(rdram, ctx);
        goto after_10;
    // 0x800F0D50: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    after_10:
    // 0x800F0D54: mul.s       $f20, $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f20.fl = MUL_S(ctx->f20.fl, ctx->f0.fl);
    // 0x800F0D58: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800F0D5C: lwc1        $f0, -0x7648($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X7648);
    // 0x800F0D60: c.lt.s      $f24, $f0
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f24.fl < ctx->f0.fl;
    // 0x800F0D64: nop

    // 0x800F0D68: bc1f        L_800F0D84
    if (!c1cs) {
        // 0x800F0D6C: div.s       $f22, $f22, $f20
        CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f22.fl = DIV_S(ctx->f22.fl, ctx->f20.fl);
            goto L_800F0D84;
    }
    // 0x800F0D6C: div.s       $f22, $f22, $f20
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f22.fl = DIV_S(ctx->f22.fl, ctx->f20.fl);
    // 0x800F0D70: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800F0D74: c.le.s      $f0, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    c1cs = ctx->f0.fl <= ctx->f22.fl;
    // 0x800F0D78: nop

    // 0x800F0D7C: bc1t        L_800F0D98
    if (c1cs) {
        // 0x800F0D80: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_800F0D98;
    }
    // 0x800F0D80: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800F0D84:
    // 0x800F0D84: c.lt.s      $f22, $f26
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 26);
    c1cs = ctx->f22.fl < ctx->f26.fl;
    // 0x800F0D88: nop

    // 0x800F0D8C: bc1f        L_800F0D98
    if (!c1cs) {
        // 0x800F0D90: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_800F0D98;
    }
    // 0x800F0D90: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800F0D94:
    // 0x800F0D94: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_800F0D98:
    // 0x800F0D98: lw          $ra, 0x30($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X30);
    // 0x800F0D9C: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x800F0DA0: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x800F0DA4: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x800F0DA8: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x800F0DAC: ldc1        $f26, 0x50($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X50);
    // 0x800F0DB0: ldc1        $f24, 0x48($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X48);
    // 0x800F0DB4: ldc1        $f22, 0x40($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X40);
    // 0x800F0DB8: ldc1        $f20, 0x38($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X38);
    // 0x800F0DBC: jr          $ra
    // 0x800F0DC0: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    return;
    // 0x800F0DC0: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
;}
RECOMP_FUNC void func_800F0DC4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F0DC4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800F0DC8: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x800F0DCC: addu        $s0, $a1, $zero
    ctx->r16 = ADD32(ctx->r5, 0);
    // 0x800F0DD0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800F0DD4: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x800F0DD8: lw          $v0, 0x18($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X18);
    // 0x800F0DDC: mtc1        $a2, $f2
    ctx->f2.u32l = ctx->r6;
    // 0x800F0DE0: beq         $v0, $zero, L_800F0F80
    if (ctx->r2 == 0) {
        // 0x800F0DE4: nop
    
            goto L_800F0F80;
    }
    // 0x800F0DE4: nop

    // 0x800F0DE8: lwc1        $f0, 0xC($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0XC);
    // 0x800F0DEC: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x800F0DF0: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x800F0DF4: c.le.s      $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f0.fl <= ctx->f20.fl;
    // 0x800F0DF8: nop

    // 0x800F0DFC: bc1t        L_800F0E18
    if (c1cs) {
        // 0x800F0E00: swc1        $f0, 0xC($s0)
        MEM_W(0XC, ctx->r16) = ctx->f0.u32l;
            goto L_800F0E18;
    }
    // 0x800F0E00: swc1        $f0, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f0.u32l;
    // 0x800F0E04: lwc1        $f0, 0x10($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X10);
    // 0x800F0E08: c.lt.s      $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f20.fl < ctx->f0.fl;
    // 0x800F0E0C: nop

    // 0x800F0E10: bc1f        L_800F0F80
    if (!c1cs) {
        // 0x800F0E14: nop
    
            goto L_800F0F80;
    }
    // 0x800F0E14: nop

L_800F0E18:
    // 0x800F0E18: lwc1        $f0, 0x10($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X10);
    // 0x800F0E1C: c.lt.s      $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f20.fl < ctx->f0.fl;
    // 0x800F0E20: nop

    // 0x800F0E24: bc1f        L_800F0E88
    if (!c1cs) {
        // 0x800F0E28: nop
    
            goto L_800F0E88;
    }
    // 0x800F0E28: nop

    // 0x800F0E2C: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x800F0E30: c.le.s      $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f0.fl <= ctx->f20.fl;
    // 0x800F0E34: nop

    // 0x800F0E38: bc1f        L_800F0F80
    if (!c1cs) {
        // 0x800F0E3C: swc1        $f0, 0x10($s0)
        MEM_W(0X10, ctx->r16) = ctx->f0.u32l;
            goto L_800F0F80;
    }
    // 0x800F0E3C: swc1        $f0, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f0.u32l;
    // 0x800F0E40: lbu         $v0, 0x2B($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X2B);
    // 0x800F0E44: beq         $v0, $zero, L_800F0F80
    if (ctx->r2 == 0) {
        // 0x800F0E48: nop
    
            goto L_800F0F80;
    }
    // 0x800F0E48: nop

    // 0x800F0E4C: lbu         $v0, 0x28($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X28);
    // 0x800F0E50: swc1        $f20, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f20.u32l;
    // 0x800F0E54: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800F0E58: sb          $v0, 0x28($s0)
    MEM_B(0X28, ctx->r16) = ctx->r2;
    // 0x800F0E5C: lhu         $a0, 0x198($a0)
    ctx->r4 = MEM_HU(ctx->r4, 0X198);
    // 0x800F0E60: jal         0x8004013C
    // 0x800F0E64: nop

    func_8004013C(rdram, ctx);
        goto after_0;
    // 0x800F0E64: nop

    after_0:
    // 0x800F0E68: lb          $a1, 0x28($s0)
    ctx->r5 = MEM_B(ctx->r16, 0X28);
    // 0x800F0E6C: lw          $v1, 0x18($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X18);
    // 0x800F0E70: jalr        $v1
    // 0x800F0E74: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    LOOKUP_FUNC(ctx->r3)(rdram, ctx);
        goto after_1;
    // 0x800F0E74: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    after_1:
    // 0x800F0E78: bnel        $v0, $zero, L_800F0F80
    if (ctx->r2 != 0) {
        // 0x800F0E7C: sw          $zero, 0x18($s0)
        MEM_W(0X18, ctx->r16) = 0;
            goto L_800F0F80;
    }
    goto skip_0;
    // 0x800F0E7C: sw          $zero, 0x18($s0)
    MEM_W(0X18, ctx->r16) = 0;
    skip_0:
    // 0x800F0E80: j           L_800F0F80
    // 0x800F0E84: nop

        goto L_800F0F80;
    // 0x800F0E84: nop

L_800F0E88:
    // 0x800F0E88: lbu         $v0, 0x2B($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X2B);
    // 0x800F0E8C: beq         $v0, $zero, L_800F0F6C
    if (ctx->r2 == 0) {
        // 0x800F0E90: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_800F0F6C;
    }
    // 0x800F0E90: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800F0E94: swc1        $f20, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f20.u32l;
    // 0x800F0E98: sb          $zero, 0x28($s0)
    MEM_B(0X28, ctx->r16) = 0;
    // 0x800F0E9C: lhu         $a0, 0x198($a0)
    ctx->r4 = MEM_HU(ctx->r4, 0X198);
    // 0x800F0EA0: jal         0x8004013C
    // 0x800F0EA4: nop

    func_8004013C(rdram, ctx);
        goto after_2;
    // 0x800F0EA4: nop

    after_2:
    // 0x800F0EA8: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // 0x800F0EAC: lw          $v0, 0x18($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X18);
    // 0x800F0EB0: jalr        $v0
    // 0x800F0EB4: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_3;
    // 0x800F0EB4: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    after_3:
    // 0x800F0EB8: bnel        $v0, $zero, L_800F0EC0
    if (ctx->r2 != 0) {
        // 0x800F0EBC: sw          $zero, 0x18($s0)
        MEM_W(0X18, ctx->r16) = 0;
            goto L_800F0EC0;
    }
    goto skip_1;
    // 0x800F0EBC: sw          $zero, 0x18($s0)
    MEM_W(0X18, ctx->r16) = 0;
    skip_1:
L_800F0EC0:
    // 0x800F0EC0: lhu         $v0, 0x1E($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X1E);
    // 0x800F0EC4: lh          $v1, 0x1C($s0)
    ctx->r3 = MEM_H(ctx->r16, 0X1C);
    // 0x800F0EC8: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800F0ECC: sh          $v0, 0x1E($s0)
    MEM_H(0X1E, ctx->r16) = ctx->r2;
    // 0x800F0ED0: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x800F0ED4: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x800F0ED8: slt         $v0, $v0, $v1
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800F0EDC: bne         $v0, $zero, L_800F0F04
    if (ctx->r2 != 0) {
        // 0x800F0EE0: nop
    
            goto L_800F0F04;
    }
    // 0x800F0EE0: nop

    // 0x800F0EE4: lwc1        $f0, 0x4($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X4);
    // 0x800F0EE8: c.eq.s      $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f0.fl == ctx->f20.fl;
    // 0x800F0EEC: nop

    // 0x800F0EF0: bc1tl       L_800F0F04
    if (c1cs) {
        // 0x800F0EF4: sh          $zero, 0x1E($s0)
        MEM_H(0X1E, ctx->r16) = 0;
            goto L_800F0F04;
    }
    goto skip_2;
    // 0x800F0EF4: sh          $zero, 0x1E($s0)
    MEM_H(0X1E, ctx->r16) = 0;
    skip_2:
    // 0x800F0EF8: sb          $zero, 0x2B($s0)
    MEM_B(0X2B, ctx->r16) = 0;
    // 0x800F0EFC: j           L_800F0F80
    // 0x800F0F00: swc1        $f0, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f0.u32l;
        goto L_800F0F80;
    // 0x800F0F00: swc1        $f0, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f0.u32l;
L_800F0F04:
    // 0x800F0F04: lwc1        $f2, 0x8($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X8);
    // 0x800F0F08: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800F0F0C: lh          $v0, 0x1C($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X1C);
    // 0x800F0F10: c.eq.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl == ctx->f0.fl;
    // 0x800F0F14: lwc1        $f0, 0x0($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X0);
    // 0x800F0F18: mtc1        $v0, $f2
    ctx->f2.u32l = ctx->r2;
    // 0x800F0F1C: cvt.s.w     $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    ctx->f2.fl = CVT_S_W(ctx->f2.u32l);
    // 0x800F0F20: div.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f2.fl);
    // 0x800F0F24: bc1t        L_800F0F80
    if (c1cs) {
        // 0x800F0F28: swc1        $f0, 0xC($s0)
        MEM_W(0XC, ctx->r16) = ctx->f0.u32l;
            goto L_800F0F80;
    }
    // 0x800F0F28: swc1        $f0, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f0.u32l;
    // 0x800F0F2C: jal         0x80003430
    // 0x800F0F30: nop

    rand_recomp(rdram, ctx);
        goto after_4;
    // 0x800F0F30: nop

    after_4:
    // 0x800F0F34: andi        $v0, $v0, 0x7F
    ctx->r2 = ctx->r2 & 0X7F;
    // 0x800F0F38: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x800F0F3C: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x800F0F40: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800F0F44: lwc1        $f2, -0x7644($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X7644);
    // 0x800F0F48: lwc1        $f4, 0x8($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X8);
    // 0x800F0F4C: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x800F0F50: div.s       $f2, $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = DIV_S(ctx->f2.fl, ctx->f4.fl);
    // 0x800F0F54: div.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f2.fl);
    // 0x800F0F58: abs.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = fabsf(ctx->f0.fl);
    // 0x800F0F5C: lwc1        $f0, 0xC($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0XC);
    // 0x800F0F60: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x800F0F64: j           L_800F0F80
    // 0x800F0F68: swc1        $f0, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f0.u32l;
        goto L_800F0F80;
    // 0x800F0F68: swc1        $f0, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f0.u32l;
L_800F0F6C:
    // 0x800F0F6C: swc1        $f20, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f20.u32l;
    // 0x800F0F70: sb          $v0, 0x2B($s0)
    MEM_B(0X2B, ctx->r16) = ctx->r2;
    // 0x800F0F74: sh          $zero, 0x1E($s0)
    MEM_H(0X1E, ctx->r16) = 0;
    // 0x800F0F78: swc1        $f20, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f20.u32l;
    // 0x800F0F7C: sb          $zero, 0x28($s0)
    MEM_B(0X28, ctx->r16) = 0;
L_800F0F80:
    // 0x800F0F80: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800F0F84: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x800F0F88: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x800F0F8C: jr          $ra
    // 0x800F0F90: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x800F0F90: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_800F0F94(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F0F94: addiu       $sp, $sp, -0x98
    ctx->r29 = ADD32(ctx->r29, -0X98);
    // 0x800F0F98: sw          $s2, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r18;
    // 0x800F0F9C: addu        $s2, $a1, $zero
    ctx->r18 = ADD32(ctx->r5, 0);
    // 0x800F0FA0: sdc1        $f20, 0x80($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X80, ctx->r29);
    // 0x800F0FA4: mtc1        $a2, $f20
    ctx->f20.u32l = ctx->r6;
    // 0x800F0FA8: sw          $ra, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r31;
    // 0x800F0FAC: sw          $s1, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r17;
    // 0x800F0FB0: sw          $s0, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r16;
    // 0x800F0FB4: sdc1        $f24, 0x90($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X90, ctx->r29);
    // 0x800F0FB8: sdc1        $f22, 0x88($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X88, ctx->r29);
    // 0x800F0FBC: lhu         $a0, 0x130($a0)
    ctx->r4 = MEM_HU(ctx->r4, 0X130);
    // 0x800F0FC0: mtc1        $a3, $f24
    ctx->f24.u32l = ctx->r7;
    // 0x800F0FC4: jal         0x8003FC28
    // 0x800F0FC8: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    func_8003FC28(rdram, ctx);
        goto after_0;
    // 0x800F0FC8: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    after_0:
    // 0x800F0FCC: jal         0x8004013C
    // 0x800F0FD0: andi        $a0, $v0, 0xFFFF
    ctx->r4 = ctx->r2 & 0XFFFF;
    func_8004013C(rdram, ctx);
        goto after_1;
    // 0x800F0FD0: andi        $a0, $v0, 0xFFFF
    ctx->r4 = ctx->r2 & 0XFFFF;
    after_1:
    // 0x800F0FD4: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    // 0x800F0FD8: lw          $v0, 0xC($s0)
    ctx->r2 = MEM_W(ctx->r16, 0XC);
    // 0x800F0FDC: bne         $v0, $zero, L_800F0FF0
    if (ctx->r2 != 0) {
        // 0x800F0FE0: addiu       $s1, $sp, 0x10
        ctx->r17 = ADD32(ctx->r29, 0X10);
            goto L_800F0FF0;
    }
    // 0x800F0FE0: addiu       $s1, $sp, 0x10
    ctx->r17 = ADD32(ctx->r29, 0X10);
    // 0x800F0FE4: lw          $a1, 0x8($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X8);
    // 0x800F0FE8: j           L_800F1014
    // 0x800F0FEC: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
        goto L_800F1014;
    // 0x800F0FEC: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
L_800F0FF0:
    // 0x800F0FF0: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x800F0FF4: lw          $a1, 0x8($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X8);
    // 0x800F0FF8: jal         0x80018EF4
    // 0x800F0FFC: addiu       $a2, $zero, 0x30
    ctx->r6 = ADD32(0, 0X30);
    zmemcpy(rdram, ctx);
        goto after_2;
    // 0x800F0FFC: addiu       $a2, $zero, 0x30
    ctx->r6 = ADD32(0, 0X30);
    after_2:
    // 0x800F1000: lw          $a0, 0xC($s0)
    ctx->r4 = MEM_W(ctx->r16, 0XC);
    // 0x800F1004: jal         0x8006AC7C
    // 0x800F1008: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    func_8006AC7C(rdram, ctx);
        goto after_3;
    // 0x800F1008: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    after_3:
    // 0x800F100C: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    // 0x800F1010: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
L_800F1014:
    // 0x800F1014: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x800F1018: jal         0x800F2AC4
    // 0x800F101C: addiu       $a3, $sp, 0x40
    ctx->r7 = ADD32(ctx->r29, 0X40);
    func_800F2AC4(rdram, ctx);
        goto after_4;
    // 0x800F101C: addiu       $a3, $sp, 0x40
    ctx->r7 = ADD32(ctx->r29, 0X40);
    after_4:
    // 0x800F1020: lw          $v1, 0x40($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X40);
    // 0x800F1024: lw          $t0, 0x44($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X44);
    // 0x800F1028: lw          $t1, 0x48($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X48);
    // 0x800F102C: sw          $v1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r3;
    // 0x800F1030: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    // 0x800F1034: sw          $t1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r9;
    // 0x800F1038: lwc1        $f0, 0x10($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X10);
    // 0x800F103C: lwc1        $f2, 0x0($s2)
    ctx->f2.u32l = MEM_W(ctx->r18, 0X0);
    // 0x800F1040: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x800F1044: addiu       $v0, $sp, 0x10
    ctx->r2 = ADD32(ctx->r29, 0X10);
    // 0x800F1048: swc1        $f0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f0.u32l;
    // 0x800F104C: lwc1        $f0, 0x4($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X4);
    // 0x800F1050: lwc1        $f2, 0x4($s2)
    ctx->f2.u32l = MEM_W(ctx->r18, 0X4);
    // 0x800F1054: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x800F1058: swc1        $f0, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f0.u32l;
    // 0x800F105C: lwc1        $f0, 0x8($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X8);
    // 0x800F1060: lwc1        $f2, 0x8($s2)
    ctx->f2.u32l = MEM_W(ctx->r18, 0X8);
    // 0x800F1064: addiu       $s0, $s2, 0xC
    ctx->r16 = ADD32(ctx->r18, 0XC);
    // 0x800F1068: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x800F106C: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x800F1070: addiu       $a1, $sp, 0x50
    ctx->r5 = ADD32(ctx->r29, 0X50);
    // 0x800F1074: jal         0x8001CFE8
    // 0x800F1078: swc1        $f0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f0.u32l;
    func_8001CFE8(rdram, ctx);
        goto after_5;
    // 0x800F1078: swc1        $f0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f0.u32l;
    after_5:
    // 0x800F107C: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x800F1080: jal         0x8001CF2C
    // 0x800F1084: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
    func_8001CF2C(rdram, ctx);
        goto after_6;
    // 0x800F1084: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
    after_6:
    // 0x800F1088: addiu       $a0, $sp, 0x50
    ctx->r4 = ADD32(ctx->r29, 0X50);
    // 0x800F108C: jal         0x8001CF2C
    // 0x800F1090: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    func_8001CF2C(rdram, ctx);
        goto after_7;
    // 0x800F1090: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    after_7:
    // 0x800F1094: mul.s       $f20, $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f20.fl = MUL_S(ctx->f20.fl, ctx->f0.fl);
    // 0x800F1098: jal         0x8001C5CC
    // 0x800F109C: div.s       $f12, $f22, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f12.fl = DIV_S(ctx->f22.fl, ctx->f20.fl);
    func_8001C5CC(rdram, ctx);
        goto after_8;
    // 0x800F109C: div.s       $f12, $f22, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f12.fl = DIV_S(ctx->f22.fl, ctx->f20.fl);
    after_8:
    // 0x800F10A0: addiu       $a0, $sp, 0x60
    ctx->r4 = ADD32(ctx->r29, 0X60);
    // 0x800F10A4: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x800F10A8: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800F10AC: lwc1        $f2, -0x7640($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X7640);
    // 0x800F10B0: mul.s       $f20, $f0, $f2
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f20.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x800F10B4: jal         0x80019548
    // 0x800F10B8: addiu       $a2, $sp, 0x50
    ctx->r6 = ADD32(ctx->r29, 0X50);
    func_80019548(rdram, ctx);
        goto after_9;
    // 0x800F10B8: addiu       $a2, $sp, 0x50
    ctx->r6 = ADD32(ctx->r29, 0X50);
    after_9:
    // 0x800F10BC: jal         0x8001CF2C
    // 0x800F10C0: addiu       $a0, $sp, 0x60
    ctx->r4 = ADD32(ctx->r29, 0X60);
    func_8001CF2C(rdram, ctx);
        goto after_10;
    // 0x800F10C0: addiu       $a0, $sp, 0x60
    ctx->r4 = ADD32(ctx->r29, 0X60);
    after_10:
    // 0x800F10C4: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x800F10C8: c.eq.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl == ctx->f2.fl;
    // 0x800F10CC: nop

    // 0x800F10D0: bc1t        L_800F10E4
    if (c1cs) {
        // 0x800F10D4: mov.s       $f4, $f20
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    ctx->f4.fl = ctx->f20.fl;
            goto L_800F10E4;
    }
    // 0x800F10D4: mov.s       $f4, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    ctx->f4.fl = ctx->f20.fl;
    // 0x800F10D8: jal         0x8001CF58
    // 0x800F10DC: addiu       $a0, $sp, 0x60
    ctx->r4 = ADD32(ctx->r29, 0X60);
    normalize_vector(rdram, ctx);
        goto after_11;
    // 0x800F10DC: addiu       $a0, $sp, 0x60
    ctx->r4 = ADD32(ctx->r29, 0X60);
    after_11:
    // 0x800F10E0: mov.s       $f4, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    ctx->f4.fl = ctx->f20.fl;
L_800F10E4:
    // 0x800F10E4: lw          $v1, 0x60($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X60);
    // 0x800F10E8: lw          $t0, 0x64($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X64);
    // 0x800F10EC: lw          $t1, 0x68($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X68);
    // 0x800F10F0: sw          $v1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r3;
    // 0x800F10F4: sw          $t0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r8;
    // 0x800F10F8: sw          $t1, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r9;
    // 0x800F10FC: abs.s       $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = fabsf(ctx->f4.fl);
    // 0x800F1100: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800F1104: lwc1        $f0, -0x763C($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X763C);
    // 0x800F1108: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x800F110C: nop

    // 0x800F1110: bc1f        L_800F1174
    if (!c1cs) {
        // 0x800F1114: nop
    
            goto L_800F1174;
    }
    // 0x800F1114: nop

    // 0x800F1118: c.lt.s      $f24, $f4
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f24.fl < ctx->f4.fl;
    // 0x800F111C: nop

    // 0x800F1120: bc1fl       L_800F1130
    if (!c1cs) {
        // 0x800F1124: neg.s       $f0, $f24
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f24.fl); 
    ctx->f0.fl = -ctx->f24.fl;
            goto L_800F1130;
    }
    goto skip_0;
    // 0x800F1124: neg.s       $f0, $f24
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f24.fl); 
    ctx->f0.fl = -ctx->f24.fl;
    skip_0:
    // 0x800F1128: j           L_800F1140
    // 0x800F112C: mov.s       $f4, $f24
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 24);
    ctx->f4.fl = ctx->f24.fl;
        goto L_800F1140;
    // 0x800F112C: mov.s       $f4, $f24
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 24);
    ctx->f4.fl = ctx->f24.fl;
L_800F1130:
    // 0x800F1130: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x800F1134: nop

    // 0x800F1138: bc1tl       L_800F1140
    if (c1cs) {
        // 0x800F113C: mov.s       $f4, $f0
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    ctx->f4.fl = ctx->f0.fl;
            goto L_800F1140;
    }
    goto skip_1;
    // 0x800F113C: mov.s       $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    ctx->f4.fl = ctx->f0.fl;
    skip_1:
L_800F1140:
    // 0x800F1140: addiu       $s0, $sp, 0x50
    ctx->r16 = ADD32(ctx->r29, 0X50);
    // 0x800F1144: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x800F1148: mfc1        $a2, $f4
    ctx->r6 = (int32_t)ctx->f4.u32l;
    // 0x800F114C: jal         0x8001D144
    // 0x800F1150: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    func_8001D144(rdram, ctx);
        goto after_12;
    // 0x800F1150: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    after_12:
    // 0x800F1154: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x800F1158: addiu       $a1, $s2, 0xC
    ctx->r5 = ADD32(ctx->r18, 0XC);
    // 0x800F115C: jal         0x8001D3C4
    // 0x800F1160: addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    func_8001D3C4(rdram, ctx);
        goto after_13;
    // 0x800F1160: addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    after_13:
    // 0x800F1164: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x800F1168: addiu       $a1, $s2, 0x18
    ctx->r5 = ADD32(ctx->r18, 0X18);
    // 0x800F116C: jal         0x8001D3C4
    // 0x800F1170: addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    func_8001D3C4(rdram, ctx);
        goto after_14;
    // 0x800F1170: addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    after_14:
L_800F1174:
    // 0x800F1174: lw          $ra, 0x7C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X7C);
    // 0x800F1178: lw          $s2, 0x78($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X78);
    // 0x800F117C: lw          $s1, 0x74($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X74);
    // 0x800F1180: lw          $s0, 0x70($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X70);
    // 0x800F1184: ldc1        $f24, 0x90($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X90);
    // 0x800F1188: ldc1        $f22, 0x88($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X88);
    // 0x800F118C: ldc1        $f20, 0x80($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X80);
    // 0x800F1190: jr          $ra
    // 0x800F1194: addiu       $sp, $sp, 0x98
    ctx->r29 = ADD32(ctx->r29, 0X98);
    return;
    // 0x800F1194: addiu       $sp, $sp, 0x98
    ctx->r29 = ADD32(ctx->r29, 0X98);
;}
RECOMP_FUNC void func_800F1198(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F1198: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800F119C: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x800F11A0: addu        $s1, $a0, $zero
    ctx->r17 = ADD32(ctx->r4, 0);
    // 0x800F11A4: sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // 0x800F11A8: addu        $s2, $a1, $zero
    ctx->r18 = ADD32(ctx->r5, 0);
    // 0x800F11AC: sw          $s3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r19;
    // 0x800F11B0: addu        $s3, $a3, $zero
    ctx->r19 = ADD32(ctx->r7, 0);
    // 0x800F11B4: slt         $v0, $a2, $s3
    ctx->r2 = SIGNED(ctx->r6) < SIGNED(ctx->r19) ? 1 : 0;
    // 0x800F11B8: sw          $ra, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r31;
    // 0x800F11BC: beq         $v0, $zero, L_800F12F4
    if (ctx->r2 == 0) {
        // 0x800F11C0: sw          $s0, 0x10($sp)
        MEM_W(0X10, ctx->r29) = ctx->r16;
            goto L_800F12F4;
    }
    // 0x800F11C0: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x800F11C4: addu        $v1, $a2, $s3
    ctx->r3 = ADD32(ctx->r6, ctx->r19);
    // 0x800F11C8: srl         $v0, $v1, 31
    ctx->r2 = S32(U32(ctx->r3) >> 31);
    // 0x800F11CC: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x800F11D0: sra         $v1, $v1, 1
    ctx->r3 = S32(SIGNED(ctx->r3) >> 1);
    // 0x800F11D4: sll         $v0, $a2, 2
    ctx->r2 = S32(ctx->r6 << 2);
    // 0x800F11D8: addu        $t2, $v0, $s1
    ctx->r10 = ADD32(ctx->r2, ctx->r17);
    // 0x800F11DC: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x800F11E0: addu        $v0, $v0, $s1
    ctx->r2 = ADD32(ctx->r2, ctx->r17);
    // 0x800F11E4: addu        $s0, $a2, $zero
    ctx->r16 = ADD32(ctx->r6, 0);
    // 0x800F11E8: sll         $v1, $v1, 1
    ctx->r3 = S32(ctx->r3 << 1);
    // 0x800F11EC: lwc1        $f2, 0x0($t2)
    ctx->f2.u32l = MEM_W(ctx->r10, 0X0);
    // 0x800F11F0: lwc1        $f0, 0x0($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X0);
    // 0x800F11F4: addu        $v1, $v1, $s2
    ctx->r3 = ADD32(ctx->r3, ctx->r18);
    // 0x800F11F8: swc1        $f0, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->f0.u32l;
    // 0x800F11FC: swc1        $f2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f2.u32l;
    // 0x800F1200: sll         $v0, $a2, 1
    ctx->r2 = S32(ctx->r6 << 1);
    // 0x800F1204: addu        $a1, $v0, $s2
    ctx->r5 = ADD32(ctx->r2, ctx->r18);
    // 0x800F1208: lhu         $a0, 0x0($a1)
    ctx->r4 = MEM_HU(ctx->r5, 0X0);
    // 0x800F120C: lhu         $v0, 0x0($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X0);
    // 0x800F1210: addiu       $t1, $s0, 0x1
    ctx->r9 = ADD32(ctx->r16, 0X1);
    // 0x800F1214: sh          $v0, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r2;
    // 0x800F1218: slt         $v0, $s3, $t1
    ctx->r2 = SIGNED(ctx->r19) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x800F121C: bne         $v0, $zero, L_800F1290
    if (ctx->r2 != 0) {
        // 0x800F1220: sh          $a0, 0x0($v1)
        MEM_H(0X0, ctx->r3) = ctx->r4;
            goto L_800F1290;
    }
    // 0x800F1220: sh          $a0, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r4;
    // 0x800F1224: sll         $v0, $t1, 1
    ctx->r2 = S32(ctx->r9 << 1);
    // 0x800F1228: addu        $t0, $v0, $s2
    ctx->r8 = ADD32(ctx->r2, ctx->r18);
    // 0x800F122C: sll         $v0, $t1, 2
    ctx->r2 = S32(ctx->r9 << 2);
    // 0x800F1230: addu        $a3, $v0, $s1
    ctx->r7 = ADD32(ctx->r2, ctx->r17);
    // 0x800F1234: addu        $a0, $a1, $zero
    ctx->r4 = ADD32(ctx->r5, 0);
    // 0x800F1238: addu        $a1, $t2, $zero
    ctx->r5 = ADD32(ctx->r10, 0);
L_800F123C:
    // 0x800F123C: lwc1        $f2, 0x0($a3)
    ctx->f2.u32l = MEM_W(ctx->r7, 0X0);
    // 0x800F1240: lwc1        $f0, 0x0($t2)
    ctx->f0.u32l = MEM_W(ctx->r10, 0X0);
    // 0x800F1244: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x800F1248: nop

    // 0x800F124C: bc1fl       L_800F1280
    if (!c1cs) {
        // 0x800F1250: addiu       $t0, $t0, 0x2
        ctx->r8 = ADD32(ctx->r8, 0X2);
            goto L_800F1280;
    }
    goto skip_0;
    // 0x800F1250: addiu       $t0, $t0, 0x2
    ctx->r8 = ADD32(ctx->r8, 0X2);
    skip_0:
    // 0x800F1254: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x800F1258: lwc1        $f0, 0x0($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0X0);
    // 0x800F125C: addiu       $a0, $a0, 0x2
    ctx->r4 = ADD32(ctx->r4, 0X2);
    // 0x800F1260: swc1        $f2, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f2.u32l;
    // 0x800F1264: swc1        $f0, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->f0.u32l;
    // 0x800F1268: lhu         $v1, 0x0($a0)
    ctx->r3 = MEM_HU(ctx->r4, 0X0);
    // 0x800F126C: lhu         $v0, 0x0($t0)
    ctx->r2 = MEM_HU(ctx->r8, 0X0);
    // 0x800F1270: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x800F1274: sh          $v0, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r2;
    // 0x800F1278: sh          $v1, 0x0($t0)
    MEM_H(0X0, ctx->r8) = ctx->r3;
    // 0x800F127C: addiu       $t0, $t0, 0x2
    ctx->r8 = ADD32(ctx->r8, 0X2);
L_800F1280:
    // 0x800F1280: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
    // 0x800F1284: slt         $v0, $s3, $t1
    ctx->r2 = SIGNED(ctx->r19) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x800F1288: beq         $v0, $zero, L_800F123C
    if (ctx->r2 == 0) {
        // 0x800F128C: addiu       $a3, $a3, 0x4
        ctx->r7 = ADD32(ctx->r7, 0X4);
            goto L_800F123C;
    }
    // 0x800F128C: addiu       $a3, $a3, 0x4
    ctx->r7 = ADD32(ctx->r7, 0X4);
L_800F1290:
    // 0x800F1290: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x800F1294: sll         $v1, $a2, 2
    ctx->r3 = S32(ctx->r6 << 2);
    // 0x800F1298: addu        $v1, $v1, $s1
    ctx->r3 = ADD32(ctx->r3, ctx->r17);
    // 0x800F129C: sll         $v0, $s0, 2
    ctx->r2 = S32(ctx->r16 << 2);
    // 0x800F12A0: addu        $v0, $v0, $s1
    ctx->r2 = ADD32(ctx->r2, ctx->r17);
    // 0x800F12A4: lwc1        $f2, 0x0($v1)
    ctx->f2.u32l = MEM_W(ctx->r3, 0X0);
    // 0x800F12A8: lwc1        $f0, 0x0($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X0);
    // 0x800F12AC: addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    // 0x800F12B0: swc1        $f0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f0.u32l;
    // 0x800F12B4: sll         $v1, $a2, 1
    ctx->r3 = S32(ctx->r6 << 1);
    // 0x800F12B8: addu        $v1, $v1, $s2
    ctx->r3 = ADD32(ctx->r3, ctx->r18);
    // 0x800F12BC: swc1        $f2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f2.u32l;
    // 0x800F12C0: sll         $v0, $s0, 1
    ctx->r2 = S32(ctx->r16 << 1);
    // 0x800F12C4: addu        $v0, $v0, $s2
    ctx->r2 = ADD32(ctx->r2, ctx->r18);
    // 0x800F12C8: lhu         $t1, 0x0($v1)
    ctx->r9 = MEM_HU(ctx->r3, 0X0);
    // 0x800F12CC: lhu         $t0, 0x0($v0)
    ctx->r8 = MEM_HU(ctx->r2, 0X0);
    // 0x800F12D0: addiu       $a3, $s0, -0x1
    ctx->r7 = ADD32(ctx->r16, -0X1);
    // 0x800F12D4: sh          $t0, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r8;
    // 0x800F12D8: jal         0x800F1198
    // 0x800F12DC: sh          $t1, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r9;
    func_800F1198(rdram, ctx);
        goto after_0;
    // 0x800F12DC: sh          $t1, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r9;
    after_0:
    // 0x800F12E0: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x800F12E4: addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    // 0x800F12E8: addiu       $a2, $s0, 0x1
    ctx->r6 = ADD32(ctx->r16, 0X1);
    // 0x800F12EC: jal         0x800F1198
    // 0x800F12F0: addu        $a3, $s3, $zero
    ctx->r7 = ADD32(ctx->r19, 0);
    func_800F1198(rdram, ctx);
        goto after_1;
    // 0x800F12F0: addu        $a3, $s3, $zero
    ctx->r7 = ADD32(ctx->r19, 0);
    after_1:
L_800F12F4:
    // 0x800F12F4: lw          $ra, 0x20($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X20);
    // 0x800F12F8: lw          $s3, 0x1C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X1C);
    // 0x800F12FC: lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X18);
    // 0x800F1300: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x800F1304: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x800F1308: jr          $ra
    // 0x800F130C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x800F130C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_800F1310(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F1310: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x800F1314: addu        $v0, $a0, $zero
    ctx->r2 = ADD32(ctx->r4, 0);
    // 0x800F1318: sw          $s1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r17;
    // 0x800F131C: addu        $s1, $a2, $zero
    ctx->r17 = ADD32(ctx->r6, 0);
    // 0x800F1320: sw          $ra, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r31;
    // 0x800F1324: sw          $s4, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r20;
    // 0x800F1328: sw          $s3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r19;
    // 0x800F132C: sw          $s2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r18;
    // 0x800F1330: sw          $s0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r16;
    // 0x800F1334: sh          $zero, 0x18($s1)
    MEM_H(0X18, ctx->r17) = 0;
    // 0x800F1338: lw          $t0, 0x0($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X0);
    // 0x800F133C: lw          $t1, 0x4($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X4);
    // 0x800F1340: lw          $t2, 0x8($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X8);
    // 0x800F1344: sw          $t0, 0x54($s1)
    MEM_W(0X54, ctx->r17) = ctx->r8;
    // 0x800F1348: sw          $t1, 0x58($s1)
    MEM_W(0X58, ctx->r17) = ctx->r9;
    // 0x800F134C: sw          $t2, 0x5C($s1)
    MEM_W(0X5C, ctx->r17) = ctx->r10;
    // 0x800F1350: sw          $zero, 0x1C($s1)
    MEM_W(0X1C, ctx->r17) = 0;
    // 0x800F1354: sh          $zero, 0x0($s1)
    MEM_H(0X0, ctx->r17) = 0;
    // 0x800F1358: lwc1        $f0, 0xC($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0XC);
    // 0x800F135C: lwc1        $f2, 0x14($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0X14);
    // 0x800F1360: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x800F1364: swc1        $f0, 0x48($s1)
    MEM_W(0X48, ctx->r17) = ctx->f0.u32l;
    // 0x800F1368: lwc1        $f0, 0x10($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X10);
    // 0x800F136C: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x800F1370: addiu       $a0, $s1, 0x54
    ctx->r4 = ADD32(ctx->r17, 0X54);
    // 0x800F1374: swc1        $f0, 0x4C($s1)
    MEM_W(0X4C, ctx->r17) = ctx->f0.u32l;
    // 0x800F1378: lwc1        $f0, 0x14($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X14);
    // 0x800F137C: addu        $s0, $a1, $zero
    ctx->r16 = ADD32(ctx->r5, 0);
    // 0x800F1380: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x800F1384: addiu       $a1, $s1, 0x48
    ctx->r5 = ADD32(ctx->r17, 0X48);
    // 0x800F1388: lui         $a2, 0x8014
    ctx->r6 = S32(0X8014 << 16);
    // 0x800F138C: addiu       $a2, $a2, -0x7FA8
    ctx->r6 = ADD32(ctx->r6, -0X7FA8);
    // 0x800F1390: addiu       $a3, $sp, 0x10
    ctx->r7 = ADD32(ctx->r29, 0X10);
    // 0x800F1394: jal         0x80068D5C
    // 0x800F1398: swc1        $f0, 0x50($s1)
    MEM_W(0X50, ctx->r17) = ctx->f0.u32l;
    func_80068D5C(rdram, ctx);
        goto after_0;
    // 0x800F1398: swc1        $f0, 0x50($s1)
    MEM_W(0X50, ctx->r17) = ctx->f0.u32l;
    after_0:
    // 0x800F139C: beq         $v0, $zero, L_800F13DC
    if (ctx->r2 == 0) {
        // 0x800F13A0: andi        $a0, $s0, 0xFFFF
        ctx->r4 = ctx->r16 & 0XFFFF;
            goto L_800F13DC;
    }
    // 0x800F13A0: andi        $a0, $s0, 0xFFFF
    ctx->r4 = ctx->r16 & 0XFFFF;
    // 0x800F13A4: lwc1        $f0, 0x10($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X10);
    // 0x800F13A8: lwc1        $f2, 0x54($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0X54);
    // 0x800F13AC: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x800F13B0: lwc1        $f2, 0x58($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0X58);
    // 0x800F13B4: swc1        $f0, 0x48($s1)
    MEM_W(0X48, ctx->r17) = ctx->f0.u32l;
    // 0x800F13B8: lwc1        $f0, 0x14($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X14);
    // 0x800F13BC: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x800F13C0: lwc1        $f2, 0x5C($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0X5C);
    // 0x800F13C4: swc1        $f0, 0x4C($s1)
    MEM_W(0X4C, ctx->r17) = ctx->f0.u32l;
    // 0x800F13C8: lwc1        $f0, 0x18($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X18);
    // 0x800F13CC: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x800F13D0: swc1        $f0, 0x50($s1)
    MEM_W(0X50, ctx->r17) = ctx->f0.u32l;
    // 0x800F13D4: lwc1        $f0, 0x2C($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x800F13D8: swc1        $f0, 0x14($s1)
    MEM_W(0X14, ctx->r17) = ctx->f0.u32l;
L_800F13DC:
    // 0x800F13DC: jal         0x8003FC28
    // 0x800F13E0: addiu       $a1, $s1, 0x40
    ctx->r5 = ADD32(ctx->r17, 0X40);
    func_8003FC28(rdram, ctx);
        goto after_1;
    // 0x800F13E0: addiu       $a1, $s1, 0x40
    ctx->r5 = ADD32(ctx->r17, 0X40);
    after_1:
    // 0x800F13E4: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // 0x800F13E8: andi        $v1, $a0, 0xFFFF
    ctx->r3 = ctx->r4 & 0XFFFF;
    // 0x800F13EC: ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
    // 0x800F13F0: beql        $v1, $v0, L_800F1440
    if (ctx->r3 == ctx->r2) {
        // 0x800F13F4: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_800F1440;
    }
    goto skip_0;
    // 0x800F13F4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_0:
    // 0x800F13F8: addu        $s2, $v0, $zero
    ctx->r18 = ADD32(ctx->r2, 0);
    // 0x800F13FC: andi        $s0, $a0, 0xFFFF
    ctx->r16 = ctx->r4 & 0XFFFF;
L_800F1400:
    // 0x800F1400: jal         0x8004013C
    // 0x800F1404: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_8004013C(rdram, ctx);
        goto after_2;
    // 0x800F1404: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_2:
    // 0x800F1408: lw          $a0, 0xC($v0)
    ctx->r4 = MEM_W(ctx->r2, 0XC);
    // 0x800F140C: addiu       $a1, $s1, 0x54
    ctx->r5 = ADD32(ctx->r17, 0X54);
    // 0x800F1410: addiu       $a2, $s1, 0x48
    ctx->r6 = ADD32(ctx->r17, 0X48);
    // 0x800F1414: jal         0x8006A944
    // 0x800F1418: addiu       $a3, $sp, 0x10
    ctx->r7 = ADD32(ctx->r29, 0X10);
    func_8006A944(rdram, ctx);
        goto after_3;
    // 0x800F1418: addiu       $a3, $sp, 0x10
    ctx->r7 = ADD32(ctx->r29, 0X10);
    after_3:
    // 0x800F141C: bne         $v0, $zero, L_800F1550
    if (ctx->r2 != 0) {
        // 0x800F1420: addu        $a0, $s0, $zero
        ctx->r4 = ADD32(ctx->r16, 0);
            goto L_800F1550;
    }
    // 0x800F1420: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x800F1424: jal         0x8003EEF4
    // 0x800F1428: addiu       $a0, $s1, 0x40
    ctx->r4 = ADD32(ctx->r17, 0X40);
    func_8003EEF4(rdram, ctx);
        goto after_4;
    // 0x800F1428: addiu       $a0, $s1, 0x40
    ctx->r4 = ADD32(ctx->r17, 0X40);
    after_4:
    // 0x800F142C: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // 0x800F1430: andi        $v0, $a0, 0xFFFF
    ctx->r2 = ctx->r4 & 0XFFFF;
    // 0x800F1434: bnel        $v0, $s2, L_800F1400
    if (ctx->r2 != ctx->r18) {
        // 0x800F1438: andi        $s0, $a0, 0xFFFF
        ctx->r16 = ctx->r4 & 0XFFFF;
            goto L_800F1400;
    }
    goto skip_1;
    // 0x800F1438: andi        $s0, $a0, 0xFFFF
    ctx->r16 = ctx->r4 & 0XFFFF;
    skip_1:
    // 0x800F143C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800F1440:
    // 0x800F1440: sh          $v0, 0x18($s1)
    MEM_H(0X18, ctx->r17) = ctx->r2;
    // 0x800F1444: ori         $a0, $zero, 0xFFFF
    ctx->r4 = 0 | 0XFFFF;
L_800F1448:
    // 0x800F1448: lh          $v0, 0x0($s1)
    ctx->r2 = MEM_H(ctx->r17, 0X0);
    // 0x800F144C: lhu         $v1, 0x0($s1)
    ctx->r3 = MEM_HU(ctx->r17, 0X0);
    // 0x800F1450: slti        $v0, $v0, 0x8
    ctx->r2 = SIGNED(ctx->r2) < 0X8 ? 1 : 0;
    // 0x800F1454: beq         $v0, $zero, L_800F1524
    if (ctx->r2 == 0) {
        // 0x800F1458: nop
    
            goto L_800F1524;
    }
    // 0x800F1458: nop

    // 0x800F145C: ori         $s3, $zero, 0xFFFF
    ctx->r19 = 0 | 0XFFFF;
    // 0x800F1460: addiu       $s4, $zero, 0x1
    ctx->r20 = ADD32(0, 0X1);
L_800F1464:
    // 0x800F1464: beq         $a0, $s3, L_800F1524
    if (ctx->r4 == ctx->r19) {
        // 0x800F1468: sll         $v0, $v1, 16
        ctx->r2 = S32(ctx->r3 << 16);
            goto L_800F1524;
    }
    // 0x800F1468: sll         $v0, $v1, 16
    ctx->r2 = S32(ctx->r3 << 16);
    // 0x800F146C: sra         $v0, $v0, 14
    ctx->r2 = S32(SIGNED(ctx->r2) >> 14);
    // 0x800F1470: lwc1        $f0, 0x1C($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X1C);
    // 0x800F1474: addu        $v0, $s1, $v0
    ctx->r2 = ADD32(ctx->r17, ctx->r2);
    // 0x800F1478: swc1        $f0, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->f0.u32l;
    // 0x800F147C: lh          $v0, 0x0($s1)
    ctx->r2 = MEM_H(ctx->r17, 0X0);
    // 0x800F1480: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x800F1484: addu        $v0, $s1, $v0
    ctx->r2 = ADD32(ctx->r17, ctx->r2);
    // 0x800F1488: sh          $a0, 0x2($v0)
    MEM_H(0X2, ctx->r2) = ctx->r4;
    // 0x800F148C: lhu         $v0, 0x0($s1)
    ctx->r2 = MEM_HU(ctx->r17, 0X0);
    // 0x800F1490: lh          $v1, 0x18($s1)
    ctx->r3 = MEM_H(ctx->r17, 0X18);
    // 0x800F1494: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800F1498: bne         $v1, $zero, L_800F150C
    if (ctx->r3 != 0) {
        // 0x800F149C: sh          $v0, 0x0($s1)
        MEM_H(0X0, ctx->r17) = ctx->r2;
            goto L_800F150C;
    }
    // 0x800F149C: sh          $v0, 0x0($s1)
    MEM_H(0X0, ctx->r17) = ctx->r2;
    // 0x800F14A0: jal         0x8003EEF4
    // 0x800F14A4: addiu       $a0, $s1, 0x40
    ctx->r4 = ADD32(ctx->r17, 0X40);
    func_8003EEF4(rdram, ctx);
        goto after_5;
    // 0x800F14A4: addiu       $a0, $s1, 0x40
    ctx->r4 = ADD32(ctx->r17, 0X40);
    after_5:
    // 0x800F14A8: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // 0x800F14AC: andi        $v0, $a0, 0xFFFF
    ctx->r2 = ctx->r4 & 0XFFFF;
    // 0x800F14B0: beql        $v0, $s3, L_800F150C
    if (ctx->r2 == ctx->r19) {
        // 0x800F14B4: sh          $s4, 0x18($s1)
        MEM_H(0X18, ctx->r17) = ctx->r20;
            goto L_800F150C;
    }
    goto skip_2;
    // 0x800F14B4: sh          $s4, 0x18($s1)
    MEM_H(0X18, ctx->r17) = ctx->r20;
    skip_2:
    // 0x800F14B8: ori         $s2, $zero, 0xFFFF
    ctx->r18 = 0 | 0XFFFF;
    // 0x800F14BC: andi        $s0, $a0, 0xFFFF
    ctx->r16 = ctx->r4 & 0XFFFF;
L_800F14C0:
    // 0x800F14C0: jal         0x8004013C
    // 0x800F14C4: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_8004013C(rdram, ctx);
        goto after_6;
    // 0x800F14C4: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_6:
    // 0x800F14C8: lw          $a0, 0xC($v0)
    ctx->r4 = MEM_W(ctx->r2, 0XC);
    // 0x800F14CC: addiu       $a1, $s1, 0x54
    ctx->r5 = ADD32(ctx->r17, 0X54);
    // 0x800F14D0: addiu       $a2, $s1, 0x48
    ctx->r6 = ADD32(ctx->r17, 0X48);
    // 0x800F14D4: jal         0x8006A944
    // 0x800F14D8: addiu       $a3, $sp, 0x10
    ctx->r7 = ADD32(ctx->r29, 0X10);
    func_8006A944(rdram, ctx);
        goto after_7;
    // 0x800F14D8: addiu       $a3, $sp, 0x10
    ctx->r7 = ADD32(ctx->r29, 0X10);
    after_7:
    // 0x800F14DC: beq         $v0, $zero, L_800F14F0
    if (ctx->r2 == 0) {
        // 0x800F14E0: addu        $a0, $s0, $zero
        ctx->r4 = ADD32(ctx->r16, 0);
            goto L_800F14F0;
    }
    // 0x800F14E0: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x800F14E4: lwc1        $f0, 0x28($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X28);
    // 0x800F14E8: j           L_800F1510
    // 0x800F14EC: swc1        $f0, 0x1C($s1)
    MEM_W(0X1C, ctx->r17) = ctx->f0.u32l;
        goto L_800F1510;
    // 0x800F14EC: swc1        $f0, 0x1C($s1)
    MEM_W(0X1C, ctx->r17) = ctx->f0.u32l;
L_800F14F0:
    // 0x800F14F0: jal         0x8003EEF4
    // 0x800F14F4: addiu       $a0, $s1, 0x40
    ctx->r4 = ADD32(ctx->r17, 0X40);
    func_8003EEF4(rdram, ctx);
        goto after_8;
    // 0x800F14F4: addiu       $a0, $s1, 0x40
    ctx->r4 = ADD32(ctx->r17, 0X40);
    after_8:
    // 0x800F14F8: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // 0x800F14FC: andi        $v0, $a0, 0xFFFF
    ctx->r2 = ctx->r4 & 0XFFFF;
    // 0x800F1500: bne         $v0, $s2, L_800F14C0
    if (ctx->r2 != ctx->r18) {
        // 0x800F1504: andi        $s0, $a0, 0xFFFF
        ctx->r16 = ctx->r4 & 0XFFFF;
            goto L_800F14C0;
    }
    // 0x800F1504: andi        $s0, $a0, 0xFFFF
    ctx->r16 = ctx->r4 & 0XFFFF;
    // 0x800F1508: sh          $s4, 0x18($s1)
    MEM_H(0X18, ctx->r17) = ctx->r20;
L_800F150C:
    // 0x800F150C: ori         $a0, $zero, 0xFFFF
    ctx->r4 = 0 | 0XFFFF;
L_800F1510:
    // 0x800F1510: lh          $v0, 0x0($s1)
    ctx->r2 = MEM_H(ctx->r17, 0X0);
    // 0x800F1514: lhu         $v1, 0x0($s1)
    ctx->r3 = MEM_HU(ctx->r17, 0X0);
    // 0x800F1518: slti        $v0, $v0, 0x8
    ctx->r2 = SIGNED(ctx->r2) < 0X8 ? 1 : 0;
    // 0x800F151C: bne         $v0, $zero, L_800F1464
    if (ctx->r2 != 0) {
        // 0x800F1520: nop
    
            goto L_800F1464;
    }
    // 0x800F1520: nop

L_800F1524:
    // 0x800F1524: lh          $a3, 0x0($s1)
    ctx->r7 = MEM_H(ctx->r17, 0X0);
    // 0x800F1528: slti        $v0, $a3, 0x3
    ctx->r2 = SIGNED(ctx->r7) < 0X3 ? 1 : 0;
    // 0x800F152C: bne         $v0, $zero, L_800F155C
    if (ctx->r2 != 0) {
        // 0x800F1530: addiu       $v0, $zero, 0x2
        ctx->r2 = ADD32(0, 0X2);
            goto L_800F155C;
    }
    // 0x800F1530: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x800F1534: addiu       $a0, $s1, 0x20
    ctx->r4 = ADD32(ctx->r17, 0X20);
    // 0x800F1538: addiu       $a1, $s1, 0x2
    ctx->r5 = ADD32(ctx->r17, 0X2);
    // 0x800F153C: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // 0x800F1540: jal         0x800F1198
    // 0x800F1544: addiu       $a3, $a3, -0x1
    ctx->r7 = ADD32(ctx->r7, -0X1);
    func_800F1198(rdram, ctx);
        goto after_9;
    // 0x800F1544: addiu       $a3, $a3, -0x1
    ctx->r7 = ADD32(ctx->r7, -0X1);
    after_9:
    // 0x800F1548: j           L_800F1594
    // 0x800F154C: nop

        goto L_800F1594;
    // 0x800F154C: nop

L_800F1550:
    // 0x800F1550: lwc1        $f0, 0x28($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X28);
    // 0x800F1554: j           L_800F1448
    // 0x800F1558: swc1        $f0, 0x1C($s1)
    MEM_W(0X1C, ctx->r17) = ctx->f0.u32l;
        goto L_800F1448;
    // 0x800F1558: swc1        $f0, 0x1C($s1)
    MEM_W(0X1C, ctx->r17) = ctx->f0.u32l;
L_800F155C:
    // 0x800F155C: bne         $a3, $v0, L_800F1594
    if (ctx->r7 != ctx->r2) {
        // 0x800F1560: nop
    
            goto L_800F1594;
    }
    // 0x800F1560: nop

    // 0x800F1564: lwc1        $f2, 0x20($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0X20);
    // 0x800F1568: lwc1        $f0, 0x24($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X24);
    // 0x800F156C: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x800F1570: nop

    // 0x800F1574: bc1f        L_800F1594
    if (!c1cs) {
        // 0x800F1578: nop
    
            goto L_800F1594;
    }
    // 0x800F1578: nop

    // 0x800F157C: lhu         $v1, 0x2($s1)
    ctx->r3 = MEM_HU(ctx->r17, 0X2);
    // 0x800F1580: lhu         $v0, 0x4($s1)
    ctx->r2 = MEM_HU(ctx->r17, 0X4);
    // 0x800F1584: swc1        $f0, 0x20($s1)
    MEM_W(0X20, ctx->r17) = ctx->f0.u32l;
    // 0x800F1588: swc1        $f2, 0x24($s1)
    MEM_W(0X24, ctx->r17) = ctx->f2.u32l;
    // 0x800F158C: sh          $v0, 0x2($s1)
    MEM_H(0X2, ctx->r17) = ctx->r2;
    // 0x800F1590: sh          $v1, 0x4($s1)
    MEM_H(0X4, ctx->r17) = ctx->r3;
L_800F1594:
    // 0x800F1594: lh          $v0, 0x0($s1)
    ctx->r2 = MEM_H(ctx->r17, 0X0);
    // 0x800F1598: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
    // 0x800F159C: lw          $s4, 0x48($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X48);
    // 0x800F15A0: lw          $s3, 0x44($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X44);
    // 0x800F15A4: lw          $s2, 0x40($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X40);
    // 0x800F15A8: lw          $s1, 0x3C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X3C);
    // 0x800F15AC: lw          $s0, 0x38($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X38);
    // 0x800F15B0: jr          $ra
    // 0x800F15B4: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x800F15B4: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}
RECOMP_FUNC void func_800F15B8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F15B8: addiu       $sp, $sp, -0xE8
    ctx->r29 = ADD32(ctx->r29, -0XE8);
    // 0x800F15BC: sw          $s1, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->r17;
    // 0x800F15C0: addu        $s1, $a0, $zero
    ctx->r17 = ADD32(ctx->r4, 0);
    // 0x800F15C4: sw          $ra, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->r31;
    // 0x800F15C8: sw          $s7, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->r23;
    // 0x800F15CC: sw          $s6, 0xC0($sp)
    MEM_W(0XC0, ctx->r29) = ctx->r22;
    // 0x800F15D0: sw          $s5, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->r21;
    // 0x800F15D4: sw          $s4, 0xB8($sp)
    MEM_W(0XB8, ctx->r29) = ctx->r20;
    // 0x800F15D8: sw          $s3, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->r19;
    // 0x800F15DC: sw          $s2, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->r18;
    // 0x800F15E0: sw          $s0, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->r16;
    // 0x800F15E4: sdc1        $f24, 0xE0($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0XE0, ctx->r29);
    // 0x800F15E8: sdc1        $f22, 0xD8($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0XD8, ctx->r29);
    // 0x800F15EC: sdc1        $f20, 0xD0($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0XD0, ctx->r29);
    // 0x800F15F0: lwc1        $f0, 0x18($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X18);
    // 0x800F15F4: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800F15F8: lwc1        $f12, -0x7638($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X7638);
    // 0x800F15FC: mul.s       $f12, $f0, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = MUL_S(ctx->f0.fl, ctx->f12.fl);
    // 0x800F1600: addu        $s2, $zero, $zero
    ctx->r18 = ADD32(0, 0);
    // 0x800F1604: jal         0x8002B190
    // 0x800F1608: addu        $s5, $s2, $zero
    ctx->r21 = ADD32(ctx->r18, 0);
    cosf_recomp(rdram, ctx);
        goto after_0;
    // 0x800F1608: addu        $s5, $s2, $zero
    ctx->r21 = ADD32(ctx->r18, 0);
    after_0:
    // 0x800F160C: ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
    // 0x800F1610: lw          $a0, 0x24($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X24);
    // 0x800F1614: sh          $v0, 0x2C($s1)
    MEM_H(0X2C, ctx->r17) = ctx->r2;
    // 0x800F1618: lbu         $v1, 0x0($a0)
    ctx->r3 = MEM_BU(ctx->r4, 0X0);
    // 0x800F161C: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // 0x800F1620: beq         $v1, $v0, L_800F17D4
    if (ctx->r3 == ctx->r2) {
        // 0x800F1624: mov.s       $f24, $f0
        CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 0);
    ctx->f24.fl = ctx->f0.fl;
            goto L_800F17D4;
    }
    // 0x800F1624: mov.s       $f24, $f0
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 0);
    ctx->f24.fl = ctx->f0.fl;
    // 0x800F1628: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x800F162C: addiu       $s7, $v0, -0x6AA0
    ctx->r23 = ADD32(ctx->r2, -0X6AA0);
    // 0x800F1630: ori         $s6, $zero, 0xFFFF
    ctx->r22 = 0 | 0XFFFF;
    // 0x800F1634: addiu       $s4, $sp, 0x18
    ctx->r20 = ADD32(ctx->r29, 0X18);
    // 0x800F1638: addu        $v0, $a0, $s5
    ctx->r2 = ADD32(ctx->r4, ctx->r21);
L_800F163C:
    // 0x800F163C: lbu         $v0, 0x0($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X0);
    // 0x800F1640: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x800F1644: addu        $v0, $v0, $s7
    ctx->r2 = ADD32(ctx->r2, ctx->r23);
    // 0x800F1648: lhu         $a0, 0x0($v0)
    ctx->r4 = MEM_HU(ctx->r2, 0X0);
    // 0x800F164C: jal         0x8003FC28
    // 0x800F1650: addiu       $a1, $sp, 0x10
    ctx->r5 = ADD32(ctx->r29, 0X10);
    func_8003FC28(rdram, ctx);
        goto after_1;
    // 0x800F1650: addiu       $a1, $sp, 0x10
    ctx->r5 = ADD32(ctx->r29, 0X10);
    after_1:
    // 0x800F1654: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    // 0x800F1658: andi        $v0, $s0, 0xFFFF
    ctx->r2 = ctx->r16 & 0XFFFF;
    // 0x800F165C: beq         $v0, $s6, L_800F17B8
    if (ctx->r2 == ctx->r22) {
        // 0x800F1660: sll         $v0, $s2, 1
        ctx->r2 = S32(ctx->r18 << 1);
            goto L_800F17B8;
    }
    // 0x800F1660: sll         $v0, $s2, 1
    ctx->r2 = S32(ctx->r18 << 1);
    // 0x800F1664: addu        $s3, $v0, $s1
    ctx->r19 = ADD32(ctx->r2, ctx->r17);
L_800F1668:
    // 0x800F1668: lhu         $v0, 0x28($s1)
    ctx->r2 = MEM_HU(ctx->r17, 0X28);
    // 0x800F166C: andi        $a0, $s0, 0xFFFF
    ctx->r4 = ctx->r16 & 0XFFFF;
    // 0x800F1670: beq         $a0, $v0, L_800F17A0
    if (ctx->r4 == ctx->r2) {
        // 0x800F1674: nop
    
            goto L_800F17A0;
    }
    // 0x800F1674: nop

    // 0x800F1678: jal         0x8004013C
    // 0x800F167C: nop

    func_8004013C(rdram, ctx);
        goto after_2;
    // 0x800F167C: nop

    after_2:
    // 0x800F1680: lbu         $v1, 0x2A($s1)
    ctx->r3 = MEM_BU(ctx->r17, 0X2A);
    // 0x800F1684: beq         $v1, $zero, L_800F169C
    if (ctx->r3 == 0) {
        // 0x800F1688: addu        $a1, $v0, $zero
        ctx->r5 = ADD32(ctx->r2, 0);
            goto L_800F169C;
    }
    // 0x800F1688: addu        $a1, $v0, $zero
    ctx->r5 = ADD32(ctx->r2, 0);
    // 0x800F168C: lhu         $v0, 0x14($a1)
    ctx->r2 = MEM_HU(ctx->r5, 0X14);
    // 0x800F1690: andi        $v0, $v0, 0x100
    ctx->r2 = ctx->r2 & 0X100;
    // 0x800F1694: bne         $v0, $zero, L_800F17A0
    if (ctx->r2 != 0) {
        // 0x800F1698: nop
    
            goto L_800F17A0;
    }
    // 0x800F1698: nop

L_800F169C:
    // 0x800F169C: lw          $a0, 0xC($a1)
    ctx->r4 = MEM_W(ctx->r5, 0XC);
    // 0x800F16A0: beq         $a0, $zero, L_800F16B8
    if (ctx->r4 == 0) {
        // 0x800F16A4: nop
    
            goto L_800F16B8;
    }
    // 0x800F16A4: nop

    // 0x800F16A8: jal         0x8006AC7C
    // 0x800F16AC: addu        $a1, $s4, $zero
    ctx->r5 = ADD32(ctx->r20, 0);
    func_8006AC7C(rdram, ctx);
        goto after_3;
    // 0x800F16AC: addu        $a1, $s4, $zero
    ctx->r5 = ADD32(ctx->r20, 0);
    after_3:
    // 0x800F16B0: j           L_800F16C4
    // 0x800F16B4: addu        $v0, $s4, $zero
    ctx->r2 = ADD32(ctx->r20, 0);
        goto L_800F16C4;
    // 0x800F16B4: addu        $v0, $s4, $zero
    ctx->r2 = ADD32(ctx->r20, 0);
L_800F16B8:
    // 0x800F16B8: lw          $v0, 0x8($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X8);
    // 0x800F16BC: beq         $v0, $zero, L_800F17A0
    if (ctx->r2 == 0) {
        // 0x800F16C0: nop
    
            goto L_800F17A0;
    }
    // 0x800F16C0: nop

L_800F16C4:
    // 0x800F16C4: lwc1        $f0, 0x0($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X0);
    // 0x800F16C8: lwc1        $f2, 0x0($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0X0);
    // 0x800F16CC: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x800F16D0: mul.s       $f4, $f0, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x800F16D4: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    // 0x800F16D8: lwc1        $f0, 0x4($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X4);
    // 0x800F16DC: lwc1        $f2, 0x4($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0X4);
    // 0x800F16E0: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x800F16E4: mul.s       $f6, $f0, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x800F16E8: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    // 0x800F16EC: lwc1        $f0, 0x8($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X8);
    // 0x800F16F0: lwc1        $f2, 0x8($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0X8);
    // 0x800F16F4: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x800F16F8: mul.s       $f2, $f0, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x800F16FC: swc1        $f0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f0.u32l;
    // 0x800F1700: lwc1        $f0, 0x1C($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X1C);
    // 0x800F1704: mul.s       $f0, $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x800F1708: add.s       $f4, $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x800F170C: add.s       $f22, $f4, $f2
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f22.fl = ctx->f4.fl + ctx->f2.fl;
    // 0x800F1710: c.le.s      $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f22.fl <= ctx->f0.fl;
    // 0x800F1714: nop

    // 0x800F1718: bc1f        L_800F17A0
    if (!c1cs) {
        // 0x800F171C: nop
    
            goto L_800F17A0;
    }
    // 0x800F171C: nop

    // 0x800F1720: lwc1        $f0, 0x20($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X20);
    // 0x800F1724: mul.s       $f0, $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x800F1728: c.le.s      $f0, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    c1cs = ctx->f0.fl <= ctx->f22.fl;
    // 0x800F172C: nop

    // 0x800F1730: bc1f        L_800F17A0
    if (!c1cs) {
        // 0x800F1734: addiu       $a0, $s1, 0xC
        ctx->r4 = ADD32(ctx->r17, 0XC);
            goto L_800F17A0;
    }
    // 0x800F1734: addiu       $a0, $s1, 0xC
    ctx->r4 = ADD32(ctx->r17, 0XC);
    // 0x800F1738: jal         0x8001CFE8
    // 0x800F173C: addu        $a1, $s4, $zero
    ctx->r5 = ADD32(ctx->r20, 0);
    func_8001CFE8(rdram, ctx);
        goto after_4;
    // 0x800F173C: addu        $a1, $s4, $zero
    ctx->r5 = ADD32(ctx->r20, 0);
    after_4:
    // 0x800F1740: addu        $a0, $s4, $zero
    ctx->r4 = ADD32(ctx->r20, 0);
    // 0x800F1744: jal         0x8001CF2C
    // 0x800F1748: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    func_8001CF2C(rdram, ctx);
        goto after_5;
    // 0x800F1748: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    after_5:
    // 0x800F174C: div.s       $f20, $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f20.fl = DIV_S(ctx->f20.fl, ctx->f0.fl);
    // 0x800F1750: c.le.s      $f24, $f20
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f24.fl <= ctx->f20.fl;
    // 0x800F1754: nop

    // 0x800F1758: bc1f        L_800F17A0
    if (!c1cs) {
        // 0x800F175C: nop
    
            goto L_800F17A0;
    }
    // 0x800F175C: nop

    // 0x800F1760: sh          $s0, 0x2C($s3)
    MEM_H(0X2C, ctx->r19) = ctx->r16;
    // 0x800F1764: sqrt.s      $f4, $f22
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f22.fl); 
    ctx->f4.fl = sqrtf(ctx->f22.fl);
    // 0x800F1768: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800F176C: lwc1        $f2, -0x7634($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X7634);
    // 0x800F1770: sub.s       $f2, $f2, $f20
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f2.fl = ctx->f2.fl - ctx->f20.fl;
    // 0x800F1774: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800F1778: lwc1        $f0, -0x7630($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X7630);
    // 0x800F177C: mul.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x800F1780: sll         $v0, $s2, 2
    ctx->r2 = S32(ctx->r18 << 2);
    // 0x800F1784: add.s       $f2, $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f4.fl;
    // 0x800F1788: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x800F178C: addu        $v0, $sp, $v0
    ctx->r2 = ADD32(ctx->r29, ctx->r2);
    // 0x800F1790: swc1        $f2, 0x28($v0)
    MEM_W(0X28, ctx->r2) = ctx->f2.u32l;
    // 0x800F1794: addiu       $v0, $zero, 0x20
    ctx->r2 = ADD32(0, 0X20);
    // 0x800F1798: beq         $s2, $v0, L_800F17D4
    if (ctx->r18 == ctx->r2) {
        // 0x800F179C: addiu       $s3, $s3, 0x2
        ctx->r19 = ADD32(ctx->r19, 0X2);
            goto L_800F17D4;
    }
    // 0x800F179C: addiu       $s3, $s3, 0x2
    ctx->r19 = ADD32(ctx->r19, 0X2);
L_800F17A0:
    // 0x800F17A0: jal         0x8003EEF4
    // 0x800F17A4: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    func_8003EEF4(rdram, ctx);
        goto after_6;
    // 0x800F17A4: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    after_6:
    // 0x800F17A8: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    // 0x800F17AC: andi        $v0, $s0, 0xFFFF
    ctx->r2 = ctx->r16 & 0XFFFF;
    // 0x800F17B0: bne         $v0, $s6, L_800F1668
    if (ctx->r2 != ctx->r22) {
        // 0x800F17B4: nop
    
            goto L_800F1668;
    }
    // 0x800F17B4: nop

L_800F17B8:
    // 0x800F17B8: lw          $a0, 0x24($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X24);
    // 0x800F17BC: addiu       $s5, $s5, 0x1
    ctx->r21 = ADD32(ctx->r21, 0X1);
    // 0x800F17C0: addu        $v0, $a0, $s5
    ctx->r2 = ADD32(ctx->r4, ctx->r21);
    // 0x800F17C4: lbu         $v1, 0x0($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X0);
    // 0x800F17C8: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // 0x800F17CC: bne         $v1, $v0, L_800F163C
    if (ctx->r3 != ctx->r2) {
        // 0x800F17D0: addu        $v0, $a0, $s5
        ctx->r2 = ADD32(ctx->r4, ctx->r21);
            goto L_800F163C;
    }
    // 0x800F17D0: addu        $v0, $a0, $s5
    ctx->r2 = ADD32(ctx->r4, ctx->r21);
L_800F17D4:
    // 0x800F17D4: slti        $v0, $s2, 0x3
    ctx->r2 = SIGNED(ctx->r18) < 0X3 ? 1 : 0;
    // 0x800F17D8: bne         $v0, $zero, L_800F17FC
    if (ctx->r2 != 0) {
        // 0x800F17DC: addiu       $v0, $zero, 0x2
        ctx->r2 = ADD32(0, 0X2);
            goto L_800F17FC;
    }
    // 0x800F17DC: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x800F17E0: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    // 0x800F17E4: addiu       $a1, $s1, 0x2C
    ctx->r5 = ADD32(ctx->r17, 0X2C);
    // 0x800F17E8: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // 0x800F17EC: jal         0x800F1198
    // 0x800F17F0: addiu       $a3, $s2, -0x1
    ctx->r7 = ADD32(ctx->r18, -0X1);
    func_800F1198(rdram, ctx);
        goto after_7;
    // 0x800F17F0: addiu       $a3, $s2, -0x1
    ctx->r7 = ADD32(ctx->r18, -0X1);
    after_7:
    // 0x800F17F4: j           L_800F1838
    // 0x800F17F8: addu        $v0, $s2, $zero
    ctx->r2 = ADD32(ctx->r18, 0);
        goto L_800F1838;
    // 0x800F17F8: addu        $v0, $s2, $zero
    ctx->r2 = ADD32(ctx->r18, 0);
L_800F17FC:
    // 0x800F17FC: bne         $s2, $v0, L_800F1838
    if (ctx->r18 != ctx->r2) {
        // 0x800F1800: addu        $v0, $s2, $zero
        ctx->r2 = ADD32(ctx->r18, 0);
            goto L_800F1838;
    }
    // 0x800F1800: addu        $v0, $s2, $zero
    ctx->r2 = ADD32(ctx->r18, 0);
    // 0x800F1804: lwc1        $f2, 0x28($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X28);
    // 0x800F1808: lwc1        $f0, 0x2C($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x800F180C: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x800F1810: nop

    // 0x800F1814: bc1f        L_800F1838
    if (!c1cs) {
        // 0x800F1818: nop
    
            goto L_800F1838;
    }
    // 0x800F1818: nop

    // 0x800F181C: lhu         $v1, 0x2C($s1)
    ctx->r3 = MEM_HU(ctx->r17, 0X2C);
    // 0x800F1820: swc1        $f0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f0.u32l;
    // 0x800F1824: lhu         $v0, 0x2E($s1)
    ctx->r2 = MEM_HU(ctx->r17, 0X2E);
    // 0x800F1828: sh          $v0, 0x2C($s1)
    MEM_H(0X2C, ctx->r17) = ctx->r2;
    // 0x800F182C: swc1        $f2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f2.u32l;
    // 0x800F1830: sh          $v1, 0x2E($s1)
    MEM_H(0X2E, ctx->r17) = ctx->r3;
    // 0x800F1834: addu        $v0, $s2, $zero
    ctx->r2 = ADD32(ctx->r18, 0);
L_800F1838:
    // 0x800F1838: lw          $ra, 0xC8($sp)
    ctx->r31 = MEM_W(ctx->r29, 0XC8);
    // 0x800F183C: lw          $s7, 0xC4($sp)
    ctx->r23 = MEM_W(ctx->r29, 0XC4);
    // 0x800F1840: lw          $s6, 0xC0($sp)
    ctx->r22 = MEM_W(ctx->r29, 0XC0);
    // 0x800F1844: lw          $s5, 0xBC($sp)
    ctx->r21 = MEM_W(ctx->r29, 0XBC);
    // 0x800F1848: lw          $s4, 0xB8($sp)
    ctx->r20 = MEM_W(ctx->r29, 0XB8);
    // 0x800F184C: lw          $s3, 0xB4($sp)
    ctx->r19 = MEM_W(ctx->r29, 0XB4);
    // 0x800F1850: lw          $s2, 0xB0($sp)
    ctx->r18 = MEM_W(ctx->r29, 0XB0);
    // 0x800F1854: lw          $s1, 0xAC($sp)
    ctx->r17 = MEM_W(ctx->r29, 0XAC);
    // 0x800F1858: lw          $s0, 0xA8($sp)
    ctx->r16 = MEM_W(ctx->r29, 0XA8);
    // 0x800F185C: ldc1        $f24, 0xE0($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0XE0);
    // 0x800F1860: ldc1        $f22, 0xD8($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0XD8);
    // 0x800F1864: ldc1        $f20, 0xD0($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0XD0);
    // 0x800F1868: jr          $ra
    // 0x800F186C: addiu       $sp, $sp, 0xE8
    ctx->r29 = ADD32(ctx->r29, 0XE8);
    return;
    // 0x800F186C: addiu       $sp, $sp, 0xE8
    ctx->r29 = ADD32(ctx->r29, 0XE8);
;}
RECOMP_FUNC void func_800F1870(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F1870: addiu       $sp, $sp, -0x90
    ctx->r29 = ADD32(ctx->r29, -0X90);
    // 0x800F1874: sw          $s2, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r18;
    // 0x800F1878: addu        $s2, $a0, $zero
    ctx->r18 = ADD32(ctx->r4, 0);
    // 0x800F187C: addu        $a0, $a1, $zero
    ctx->r4 = ADD32(ctx->r5, 0);
    // 0x800F1880: sw          $s1, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r17;
    // 0x800F1884: addu        $s1, $a2, $zero
    ctx->r17 = ADD32(ctx->r6, 0);
    // 0x800F1888: sw          $s3, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r19;
    // 0x800F188C: sw          $ra, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r31;
    // 0x800F1890: sw          $s0, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r16;
    // 0x800F1894: sdc1        $f20, 0x88($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X88, ctx->r29);
    // 0x800F1898: beq         $s1, $zero, L_800F18B4
    if (ctx->r17 == 0) {
        // 0x800F189C: addu        $s3, $a3, $zero
        ctx->r19 = ADD32(ctx->r7, 0);
            goto L_800F18B4;
    }
    // 0x800F189C: addu        $s3, $a3, $zero
    ctx->r19 = ADD32(ctx->r7, 0);
    // 0x800F18A0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800F18A4: beq         $s1, $v0, L_800F18C0
    if (ctx->r17 == ctx->r2) {
        // 0x800F18A8: nop
    
            goto L_800F18C0;
    }
    // 0x800F18A8: nop

    // 0x800F18AC: j           L_800F18CC
    // 0x800F18B0: nop

        goto L_800F18CC;
    // 0x800F18B0: nop

L_800F18B4:
    // 0x800F18B4: lh          $v0, 0x15C($s2)
    ctx->r2 = MEM_H(ctx->r18, 0X15C);
    // 0x800F18B8: j           L_800F18D0
    // 0x800F18BC: nop

        goto L_800F18D0;
    // 0x800F18BC: nop

L_800F18C0:
    // 0x800F18C0: lh          $v0, 0x188($s2)
    ctx->r2 = MEM_H(ctx->r18, 0X188);
    // 0x800F18C4: j           L_800F18D0
    // 0x800F18C8: nop

        goto L_800F18D0;
    // 0x800F18C8: nop

L_800F18CC:
    // 0x800F18CC: lh          $v0, 0x24($s1)
    ctx->r2 = MEM_H(ctx->r17, 0X24);
L_800F18D0:
    // 0x800F18D0: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800F18D4: lwc1        $f2, -0x762C($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X762C);
    // 0x800F18D8: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x800F18DC: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x800F18E0: div.s       $f20, $f0, $f2
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f20.fl = DIV_S(ctx->f0.fl, ctx->f2.fl);
    // 0x800F18E4: addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
    // 0x800F18E8: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x800F18EC: lhu         $a1, -0x6A84($v0)
    ctx->r5 = MEM_HU(ctx->r2, -0X6A84);
    // 0x800F18F0: addiu       $a2, $sp, 0x10
    ctx->r6 = ADD32(ctx->r29, 0X10);
    // 0x800F18F4: jal         0x800F1310
    // 0x800F18F8: swc1        $f20, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f20.u32l;
    func_800F1310(rdram, ctx);
        goto after_0;
    // 0x800F18F8: swc1        $f20, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f20.u32l;
    after_0:
    // 0x800F18FC: lwc1        $f0, 0x24($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X24);
    // 0x800F1900: c.eq.s      $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f0.fl == ctx->f20.fl;
    // 0x800F1904: nop

    // 0x800F1908: bc1t        L_800F1920
    if (c1cs) {
        // 0x800F190C: addu        $a1, $v0, $zero
        ctx->r5 = ADD32(ctx->r2, 0);
            goto L_800F1920;
    }
    // 0x800F190C: addu        $a1, $v0, $zero
    ctx->r5 = ADD32(ctx->r2, 0);
    // 0x800F1910: beq         $s3, $zero, L_800F1928
    if (ctx->r19 == 0) {
        // 0x800F1914: addiu       $s0, $zero, 0x1
        ctx->r16 = ADD32(0, 0X1);
            goto L_800F1928;
    }
    // 0x800F1914: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
    // 0x800F1918: j           L_800F1928
    // 0x800F191C: swc1        $f0, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->f0.u32l;
        goto L_800F1928;
    // 0x800F191C: swc1        $f0, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->f0.u32l;
L_800F1920:
    // 0x800F1920: bnel        $s3, $zero, L_800F1928
    if (ctx->r19 != 0) {
        // 0x800F1924: sw          $zero, 0x0($s3)
        MEM_W(0X0, ctx->r19) = 0;
            goto L_800F1928;
    }
    goto skip_0;
    // 0x800F1924: sw          $zero, 0x0($s3)
    MEM_W(0X0, ctx->r19) = 0;
    skip_0:
L_800F1928:
    // 0x800F1928: beq         $s1, $zero, L_800F1940
    if (ctx->r17 == 0) {
        // 0x800F192C: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_800F1940;
    }
    // 0x800F192C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800F1930: beql        $s1, $v0, L_800F1950
    if (ctx->r17 == ctx->r2) {
        // 0x800F1934: sb          $s0, 0x18D($s2)
        MEM_B(0X18D, ctx->r18) = ctx->r16;
            goto L_800F1950;
    }
    goto skip_1;
    // 0x800F1934: sb          $s0, 0x18D($s2)
    MEM_B(0X18D, ctx->r18) = ctx->r16;
    skip_1:
    // 0x800F1938: j           L_800F195C
    // 0x800F193C: sb          $s0, 0x29($s1)
    MEM_B(0X29, ctx->r17) = ctx->r16;
        goto L_800F195C;
    // 0x800F193C: sb          $s0, 0x29($s1)
    MEM_B(0X29, ctx->r17) = ctx->r16;
L_800F1940:
    // 0x800F1940: sb          $s0, 0x161($s2)
    MEM_B(0X161, ctx->r18) = ctx->r16;
    // 0x800F1944: lwc1        $f0, 0x24($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X24);
    // 0x800F1948: j           L_800F1964
    // 0x800F194C: swc1        $f0, 0x158($s2)
    MEM_W(0X158, ctx->r18) = ctx->f0.u32l;
        goto L_800F1964;
    // 0x800F194C: swc1        $f0, 0x158($s2)
    MEM_W(0X158, ctx->r18) = ctx->f0.u32l;
L_800F1950:
    // 0x800F1950: lwc1        $f0, 0x24($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X24);
    // 0x800F1954: j           L_800F1964
    // 0x800F1958: swc1        $f0, 0x184($s2)
    MEM_W(0X184, ctx->r18) = ctx->f0.u32l;
        goto L_800F1964;
    // 0x800F1958: swc1        $f0, 0x184($s2)
    MEM_W(0X184, ctx->r18) = ctx->f0.u32l;
L_800F195C:
    // 0x800F195C: lwc1        $f0, 0x24($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X24);
    // 0x800F1960: swc1        $f0, 0x20($s1)
    MEM_W(0X20, ctx->r17) = ctx->f0.u32l;
L_800F1964:
    // 0x800F1964: beq         $a1, $zero, L_800F19B8
    if (ctx->r5 == 0) {
        // 0x800F1968: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_800F19B8;
    }
    // 0x800F1968: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800F196C: lh          $v1, 0x19A($s2)
    ctx->r3 = MEM_H(ctx->r18, 0X19A);
    // 0x800F1970: bne         $v1, $v0, L_800F1A98
    if (ctx->r3 != ctx->r2) {
        // 0x800F1974: nop
    
            goto L_800F1A98;
    }
    // 0x800F1974: nop

    // 0x800F1978: lbu         $v0, 0x136($s2)
    ctx->r2 = MEM_BU(ctx->r18, 0X136);
    // 0x800F197C: bne         $v0, $zero, L_800F1A10
    if (ctx->r2 != 0) {
        // 0x800F1980: nop
    
            goto L_800F1A10;
    }
    // 0x800F1980: nop

    // 0x800F1984: blez        $a1, L_800F1B1C
    if (SIGNED(ctx->r5) <= 0) {
        // 0x800F1988: addu        $v1, $zero, $zero
        ctx->r3 = ADD32(0, 0);
            goto L_800F1B1C;
    }
    // 0x800F1988: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
    // 0x800F198C: addiu       $a2, $sp, 0x10
    ctx->r6 = ADD32(ctx->r29, 0X10);
    // 0x800F1990: addiu       $s0, $zero, 0x3
    ctx->r16 = ADD32(0, 0X3);
    // 0x800F1994: addiu       $s1, $zero, 0x1
    ctx->r17 = ADD32(0, 0X1);
    // 0x800F1998: sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3 << 1);
L_800F199C:
    // 0x800F199C: addu        $v0, $a2, $v0
    ctx->r2 = ADD32(ctx->r6, ctx->r2);
    // 0x800F19A0: lhu         $a0, 0x2($v0)
    ctx->r4 = MEM_HU(ctx->r2, 0X2);
    // 0x800F19A4: lhu         $v0, 0x198($s2)
    ctx->r2 = MEM_HU(ctx->r18, 0X198);
    // 0x800F19A8: bne         $a0, $v0, L_800F19C0
    if (ctx->r4 != ctx->r2) {
        // 0x800F19AC: addiu       $v0, $v1, 0x1
        ctx->r2 = ADD32(ctx->r3, 0X1);
            goto L_800F19C0;
    }
    // 0x800F19AC: addiu       $v0, $v1, 0x1
    ctx->r2 = ADD32(ctx->r3, 0X1);
    // 0x800F19B0: bnel        $v0, $a1, L_800F19FC
    if (ctx->r2 != ctx->r5) {
        // 0x800F19B4: addu        $v1, $v0, $zero
        ctx->r3 = ADD32(ctx->r2, 0);
            goto L_800F19FC;
    }
    goto skip_2;
    // 0x800F19B4: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    skip_2:
L_800F19B8:
    // 0x800F19B8: j           L_800F1B20
    // 0x800F19BC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_800F1B20;
    // 0x800F19BC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800F19C0:
    // 0x800F19C0: jal         0x8004013C
    // 0x800F19C4: nop

    func_8004013C(rdram, ctx);
        goto after_1;
    // 0x800F19C4: nop

    after_1:
    // 0x800F19C8: lw          $v1, 0x10($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X10);
    // 0x800F19CC: beq         $v1, $zero, L_800F19E0
    if (ctx->r3 == 0) {
        // 0x800F19D0: nop
    
            goto L_800F19E0;
    }
    // 0x800F19D0: nop

    // 0x800F19D4: lh          $v0, 0x19A($v1)
    ctx->r2 = MEM_H(ctx->r3, 0X19A);
    // 0x800F19D8: j           L_800F19EC
    // 0x800F19DC: nop

        goto L_800F19EC;
    // 0x800F19DC: nop

L_800F19E0:
    // 0x800F19E0: lbu         $v0, 0x15($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X15);
    // 0x800F19E4: srl         $v0, $v0, 6
    ctx->r2 = S32(U32(ctx->r2) >> 6);
    // 0x800F19E8: subu        $v0, $s0, $v0
    ctx->r2 = SUB32(ctx->r16, ctx->r2);
L_800F19EC:
    // 0x800F19EC: beq         $v0, $s1, L_800F1B1C
    if (ctx->r2 == ctx->r17) {
        // 0x800F19F0: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_800F1B1C;
    }
    // 0x800F19F0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800F19F4: j           L_800F1B20
    // 0x800F19F8: nop

        goto L_800F1B20;
    // 0x800F19F8: nop

L_800F19FC:
    // 0x800F19FC: slt         $v0, $v1, $a1
    ctx->r2 = SIGNED(ctx->r3) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x800F1A00: bne         $v0, $zero, L_800F199C
    if (ctx->r2 != 0) {
        // 0x800F1A04: sll         $v0, $v1, 1
        ctx->r2 = S32(ctx->r3 << 1);
            goto L_800F199C;
    }
    // 0x800F1A04: sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3 << 1);
    // 0x800F1A08: j           L_800F1B20
    // 0x800F1A0C: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
        goto L_800F1B20;
    // 0x800F1A0C: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_800F1A10:
    // 0x800F1A10: blez        $a1, L_800F1B1C
    if (SIGNED(ctx->r5) <= 0) {
        // 0x800F1A14: addu        $v1, $zero, $zero
        ctx->r3 = ADD32(0, 0);
            goto L_800F1B1C;
    }
    // 0x800F1A14: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
    // 0x800F1A18: addiu       $a2, $sp, 0x10
    ctx->r6 = ADD32(ctx->r29, 0X10);
    // 0x800F1A1C: addiu       $s0, $zero, 0x3
    ctx->r16 = ADD32(0, 0X3);
    // 0x800F1A20: sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3 << 1);
L_800F1A24:
    // 0x800F1A24: addu        $v0, $a2, $v0
    ctx->r2 = ADD32(ctx->r6, ctx->r2);
    // 0x800F1A28: lhu         $a0, 0x2($v0)
    ctx->r4 = MEM_HU(ctx->r2, 0X2);
    // 0x800F1A2C: lhu         $v0, 0x198($s2)
    ctx->r2 = MEM_HU(ctx->r18, 0X198);
    // 0x800F1A30: bne         $a0, $v0, L_800F1A48
    if (ctx->r4 != ctx->r2) {
        // 0x800F1A34: addiu       $v0, $v1, 0x1
        ctx->r2 = ADD32(ctx->r3, 0X1);
            goto L_800F1A48;
    }
    // 0x800F1A34: addiu       $v0, $v1, 0x1
    ctx->r2 = ADD32(ctx->r3, 0X1);
    // 0x800F1A38: bnel        $v0, $a1, L_800F1A84
    if (ctx->r2 != ctx->r5) {
        // 0x800F1A3C: addu        $v1, $v0, $zero
        ctx->r3 = ADD32(ctx->r2, 0);
            goto L_800F1A84;
    }
    goto skip_3;
    // 0x800F1A3C: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    skip_3:
    // 0x800F1A40: j           L_800F1B20
    // 0x800F1A44: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_800F1B20;
    // 0x800F1A44: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800F1A48:
    // 0x800F1A48: jal         0x8004013C
    // 0x800F1A4C: nop

    func_8004013C(rdram, ctx);
        goto after_2;
    // 0x800F1A4C: nop

    after_2:
    // 0x800F1A50: lw          $v1, 0x10($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X10);
    // 0x800F1A54: beq         $v1, $zero, L_800F1A68
    if (ctx->r3 == 0) {
        // 0x800F1A58: nop
    
            goto L_800F1A68;
    }
    // 0x800F1A58: nop

    // 0x800F1A5C: lh          $v0, 0x19A($v1)
    ctx->r2 = MEM_H(ctx->r3, 0X19A);
    // 0x800F1A60: j           L_800F1A74
    // 0x800F1A64: nop

        goto L_800F1A74;
    // 0x800F1A64: nop

L_800F1A68:
    // 0x800F1A68: lbu         $v0, 0x15($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X15);
    // 0x800F1A6C: srl         $v0, $v0, 6
    ctx->r2 = S32(U32(ctx->r2) >> 6);
    // 0x800F1A70: subu        $v0, $s0, $v0
    ctx->r2 = SUB32(ctx->r16, ctx->r2);
L_800F1A74:
    // 0x800F1A74: bne         $v0, $zero, L_800F1B1C
    if (ctx->r2 != 0) {
        // 0x800F1A78: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_800F1B1C;
    }
    // 0x800F1A78: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800F1A7C: j           L_800F1B20
    // 0x800F1A80: nop

        goto L_800F1B20;
    // 0x800F1A80: nop

L_800F1A84:
    // 0x800F1A84: slt         $v0, $v1, $a1
    ctx->r2 = SIGNED(ctx->r3) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x800F1A88: bne         $v0, $zero, L_800F1A24
    if (ctx->r2 != 0) {
        // 0x800F1A8C: sll         $v0, $v1, 1
        ctx->r2 = S32(ctx->r3 << 1);
            goto L_800F1A24;
    }
    // 0x800F1A8C: sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3 << 1);
    // 0x800F1A90: j           L_800F1B20
    // 0x800F1A94: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
        goto L_800F1B20;
    // 0x800F1A94: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_800F1A98:
    // 0x800F1A98: blez        $a1, L_800F1B1C
    if (SIGNED(ctx->r5) <= 0) {
        // 0x800F1A9C: addu        $v1, $zero, $zero
        ctx->r3 = ADD32(0, 0);
            goto L_800F1B1C;
    }
    // 0x800F1A9C: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
    // 0x800F1AA0: addiu       $a2, $sp, 0x10
    ctx->r6 = ADD32(ctx->r29, 0X10);
    // 0x800F1AA4: addiu       $s0, $zero, 0x3
    ctx->r16 = ADD32(0, 0X3);
    // 0x800F1AA8: addiu       $s1, $zero, 0x1
    ctx->r17 = ADD32(0, 0X1);
    // 0x800F1AAC: sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3 << 1);
L_800F1AB0:
    // 0x800F1AB0: addu        $v0, $a2, $v0
    ctx->r2 = ADD32(ctx->r6, ctx->r2);
    // 0x800F1AB4: lhu         $a0, 0x2($v0)
    ctx->r4 = MEM_HU(ctx->r2, 0X2);
    // 0x800F1AB8: lhu         $v0, 0x198($s2)
    ctx->r2 = MEM_HU(ctx->r18, 0X198);
    // 0x800F1ABC: bne         $a0, $v0, L_800F1AD4
    if (ctx->r4 != ctx->r2) {
        // 0x800F1AC0: addiu       $v0, $v1, 0x1
        ctx->r2 = ADD32(ctx->r3, 0X1);
            goto L_800F1AD4;
    }
    // 0x800F1AC0: addiu       $v0, $v1, 0x1
    ctx->r2 = ADD32(ctx->r3, 0X1);
    // 0x800F1AC4: bnel        $v0, $a1, L_800F1B10
    if (ctx->r2 != ctx->r5) {
        // 0x800F1AC8: addu        $v1, $v0, $zero
        ctx->r3 = ADD32(ctx->r2, 0);
            goto L_800F1B10;
    }
    goto skip_4;
    // 0x800F1AC8: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    skip_4:
    // 0x800F1ACC: j           L_800F1B20
    // 0x800F1AD0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_800F1B20;
    // 0x800F1AD0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800F1AD4:
    // 0x800F1AD4: jal         0x8004013C
    // 0x800F1AD8: nop

    func_8004013C(rdram, ctx);
        goto after_3;
    // 0x800F1AD8: nop

    after_3:
    // 0x800F1ADC: lw          $v1, 0x10($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X10);
    // 0x800F1AE0: beq         $v1, $zero, L_800F1AF4
    if (ctx->r3 == 0) {
        // 0x800F1AE4: nop
    
            goto L_800F1AF4;
    }
    // 0x800F1AE4: nop

    // 0x800F1AE8: lh          $v0, 0x19A($v1)
    ctx->r2 = MEM_H(ctx->r3, 0X19A);
    // 0x800F1AEC: j           L_800F1B00
    // 0x800F1AF0: nop

        goto L_800F1B00;
    // 0x800F1AF0: nop

L_800F1AF4:
    // 0x800F1AF4: lbu         $v0, 0x15($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X15);
    // 0x800F1AF8: srl         $v0, $v0, 6
    ctx->r2 = S32(U32(ctx->r2) >> 6);
    // 0x800F1AFC: subu        $v0, $s0, $v0
    ctx->r2 = SUB32(ctx->r16, ctx->r2);
L_800F1B00:
    // 0x800F1B00: bne         $v0, $s1, L_800F1B1C
    if (ctx->r2 != ctx->r17) {
        // 0x800F1B04: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_800F1B1C;
    }
    // 0x800F1B04: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800F1B08: j           L_800F1B20
    // 0x800F1B0C: nop

        goto L_800F1B20;
    // 0x800F1B0C: nop

L_800F1B10:
    // 0x800F1B10: slt         $v0, $v1, $a1
    ctx->r2 = SIGNED(ctx->r3) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x800F1B14: bne         $v0, $zero, L_800F1AB0
    if (ctx->r2 != 0) {
        // 0x800F1B18: sll         $v0, $v1, 1
        ctx->r2 = S32(ctx->r3 << 1);
            goto L_800F1AB0;
    }
    // 0x800F1B18: sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3 << 1);
L_800F1B1C:
    // 0x800F1B1C: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_800F1B20:
    // 0x800F1B20: lw          $ra, 0x80($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X80);
    // 0x800F1B24: lw          $s3, 0x7C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X7C);
    // 0x800F1B28: lw          $s2, 0x78($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X78);
    // 0x800F1B2C: lw          $s1, 0x74($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X74);
    // 0x800F1B30: lw          $s0, 0x70($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X70);
    // 0x800F1B34: ldc1        $f20, 0x88($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X88);
    // 0x800F1B38: jr          $ra
    // 0x800F1B3C: addiu       $sp, $sp, 0x90
    ctx->r29 = ADD32(ctx->r29, 0X90);
    return;
    // 0x800F1B3C: addiu       $sp, $sp, 0x90
    ctx->r29 = ADD32(ctx->r29, 0X90);
;}
RECOMP_FUNC void func_800F1B40(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F1B40: addiu       $sp, $sp, -0x90
    ctx->r29 = ADD32(ctx->r29, -0X90);
    // 0x800F1B44: sdc1        $f20, 0x78($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X78, ctx->r29);
    // 0x800F1B48: lwc1        $f20, 0xA0($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0XA0);
    // 0x800F1B4C: sdc1        $f22, 0x80($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X80, ctx->r29);
    // 0x800F1B50: lwc1        $f22, 0xA4($sp)
    ctx->f22.u32l = MEM_W(ctx->r29, 0XA4);
    // 0x800F1B54: sw          $s4, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r20;
    // 0x800F1B58: lw          $s4, 0xA8($sp)
    ctx->r20 = MEM_W(ctx->r29, 0XA8);
    // 0x800F1B5C: lw          $v0, 0xB0($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XB0);
    // 0x800F1B60: sw          $s2, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r18;
    // 0x800F1B64: lw          $s2, 0xB4($sp)
    ctx->r18 = MEM_W(ctx->r29, 0XB4);
    // 0x800F1B68: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800F1B6C: sw          $s5, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r21;
    // 0x800F1B70: addu        $s5, $a0, $zero
    ctx->r21 = ADD32(ctx->r4, 0);
    // 0x800F1B74: sw          $s6, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r22;
    // 0x800F1B78: addu        $s6, $a3, $zero
    ctx->r22 = ADD32(ctx->r7, 0);
    // 0x800F1B7C: sw          $s3, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r19;
    // 0x800F1B80: addu        $s3, $a2, $zero
    ctx->r19 = ADD32(ctx->r6, 0);
    // 0x800F1B84: sw          $ra, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r31;
    // 0x800F1B88: sw          $fp, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r30;
    // 0x800F1B8C: sw          $s7, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r23;
    // 0x800F1B90: sw          $s1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r17;
    // 0x800F1B94: sw          $s0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r16;
    // 0x800F1B98: sdc1        $f24, 0x88($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X88, ctx->r29);
    // 0x800F1B9C: sh          $a2, 0x0($s6)
    MEM_H(0X0, ctx->r22) = ctx->r6;
    // 0x800F1BA0: addu        $s1, $v0, $zero
    ctx->r17 = ADD32(ctx->r2, 0);
    // 0x800F1BA4: c.eq.s      $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f20.fl == ctx->f0.fl;
    // 0x800F1BA8: nop

    // 0x800F1BAC: bc1t        L_800F1E40
    if (c1cs) {
        // 0x800F1BB0: sb          $zero, 0x0($s2)
        MEM_B(0X0, ctx->r18) = 0;
            goto L_800F1E40;
    }
    // 0x800F1BB0: sb          $zero, 0x0($s2)
    MEM_B(0X0, ctx->r18) = 0;
    // 0x800F1BB4: lwc1        $f0, 0x0($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0X0);
    // 0x800F1BB8: mul.s       $f0, $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f20.fl);
    // 0x800F1BBC: swc1        $f0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f0.u32l;
    // 0x800F1BC0: lwc1        $f0, 0x4($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0X4);
    // 0x800F1BC4: mul.s       $f0, $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f20.fl);
    // 0x800F1BC8: swc1        $f0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f0.u32l;
    // 0x800F1BCC: lwc1        $f0, 0x8($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0X8);
    // 0x800F1BD0: mul.s       $f0, $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f20.fl);
    // 0x800F1BD4: andi        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 & 0X1;
    // 0x800F1BD8: beq         $v0, $zero, L_800F1C94
    if (ctx->r2 == 0) {
        // 0x800F1BDC: swc1        $f0, 0x48($sp)
        MEM_W(0X48, ctx->r29) = ctx->f0.u32l;
            goto L_800F1C94;
    }
    // 0x800F1BDC: swc1        $f0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f0.u32l;
    // 0x800F1BE0: addu        $a0, $s5, $zero
    ctx->r4 = ADD32(ctx->r21, 0);
    // 0x800F1BE4: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    // 0x800F1BE8: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x800F1BEC: addiu       $s0, $v0, -0x7FA8
    ctx->r16 = ADD32(ctx->r2, -0X7FA8);
    // 0x800F1BF0: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    // 0x800F1BF4: jal         0x80068D5C
    // 0x800F1BF8: addiu       $a3, $sp, 0x10
    ctx->r7 = ADD32(ctx->r29, 0X10);
    func_80068D5C(rdram, ctx);
        goto after_0;
    // 0x800F1BF8: addiu       $a3, $sp, 0x10
    ctx->r7 = ADD32(ctx->r29, 0X10);
    after_0:
    // 0x800F1BFC: beq         $v0, $zero, L_800F1C94
    if (ctx->r2 == 0) {
        // 0x800F1C00: addu        $a2, $s0, $zero
        ctx->r6 = ADD32(ctx->r16, 0);
            goto L_800F1C94;
    }
    // 0x800F1C00: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    // 0x800F1C04: lwc1        $f0, 0x10($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X10);
    // 0x800F1C08: lwc1        $f2, 0x0($s5)
    ctx->f2.u32l = MEM_W(ctx->r21, 0X0);
    // 0x800F1C0C: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x800F1C10: swc1        $f0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f0.u32l;
    // 0x800F1C14: lwc1        $f0, 0x14($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X14);
    // 0x800F1C18: lwc1        $f2, 0x4($s5)
    ctx->f2.u32l = MEM_W(ctx->r21, 0X4);
    // 0x800F1C1C: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x800F1C20: swc1        $f0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f0.u32l;
    // 0x800F1C24: lwc1        $f0, 0x18($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X18);
    // 0x800F1C28: lwc1        $f2, 0x8($s5)
    ctx->f2.u32l = MEM_W(ctx->r21, 0X8);
    // 0x800F1C2C: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x800F1C30: ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
    // 0x800F1C34: swc1        $f0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f0.u32l;
    // 0x800F1C38: sh          $v0, 0x0($s6)
    MEM_H(0X0, ctx->r22) = ctx->r2;
    // 0x800F1C3C: lwc1        $f12, 0x10($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X10);
    // 0x800F1C40: lwc1        $f14, 0x18($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X18);
    // 0x800F1C44: jal         0x80068180
    // 0x800F1C48: addiu       $a3, $sp, 0x10
    ctx->r7 = ADD32(ctx->r29, 0X10);
    func_80068180(rdram, ctx);
        goto after_1;
    // 0x800F1C48: addiu       $a3, $sp, 0x10
    ctx->r7 = ADD32(ctx->r29, 0X10);
    after_1:
    // 0x800F1C4C: lw          $v0, 0xAC($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XAC);
    // 0x800F1C50: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x800F1C54: lw          $t1, 0x20($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X20);
    // 0x800F1C58: lw          $t2, 0x24($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X24);
    // 0x800F1C5C: sw          $t0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r8;
    // 0x800F1C60: sw          $t1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r9;
    // 0x800F1C64: sw          $t2, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r10;
    // 0x800F1C68: lbu         $v0, 0x0($s2)
    ctx->r2 = MEM_BU(ctx->r18, 0X0);
    // 0x800F1C6C: ori         $v0, $v0, 0x1
    ctx->r2 = ctx->r2 | 0X1;
    // 0x800F1C70: beq         $s4, $zero, L_800F1C80
    if (ctx->r20 == 0) {
        // 0x800F1C74: sb          $v0, 0x0($s2)
        MEM_B(0X0, ctx->r18) = ctx->r2;
            goto L_800F1C80;
    }
    // 0x800F1C74: sb          $v0, 0x0($s2)
    MEM_B(0X0, ctx->r18) = ctx->r2;
    // 0x800F1C78: lwc1        $f0, 0x2C($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x800F1C7C: swc1        $f0, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->f0.u32l;
L_800F1C80:
    // 0x800F1C80: lwc1        $f20, 0x2C($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x800F1C84: c.le.s      $f20, $f22
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 22);
    c1cs = ctx->f20.fl <= ctx->f22.fl;
    // 0x800F1C88: nop

    // 0x800F1C8C: bc1t        L_800F1E40
    if (c1cs) {
        // 0x800F1C90: mov.s       $f0, $f20
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    ctx->f0.fl = ctx->f20.fl;
            goto L_800F1E40;
    }
    // 0x800F1C90: mov.s       $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    ctx->f0.fl = ctx->f20.fl;
L_800F1C94:
    // 0x800F1C94: andi        $v0, $s1, 0x2
    ctx->r2 = ctx->r17 & 0X2;
    // 0x800F1C98: beq         $v0, $zero, L_800F1E3C
    if (ctx->r2 == 0) {
        // 0x800F1C9C: addiu       $v0, $zero, 0xFF
        ctx->r2 = ADD32(0, 0XFF);
            goto L_800F1E3C;
    }
    // 0x800F1C9C: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // 0x800F1CA0: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x800F1CA4: lbu         $v1, -0x4CC0($a0)
    ctx->r3 = MEM_BU(ctx->r4, -0X4CC0);
    // 0x800F1CA8: beq         $v1, $v0, L_800F1E3C
    if (ctx->r3 == ctx->r2) {
        // 0x800F1CAC: lui         $v0, 0x8014
        ctx->r2 = S32(0X8014 << 16);
            goto L_800F1E3C;
    }
    // 0x800F1CAC: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x800F1CB0: addiu       $fp, $v0, -0x6AA0
    ctx->r30 = ADD32(ctx->r2, -0X6AA0);
    // 0x800F1CB4: ori         $s7, $zero, 0xFFFF
    ctx->r23 = 0 | 0XFFFF;
    // 0x800F1CB8: andi        $s4, $s3, 0xFFFF
    ctx->r20 = ctx->r19 & 0XFFFF;
    // 0x800F1CBC: mtc1        $zero, $f24
    ctx->f24.u32l = 0;
    // 0x800F1CC0: addiu       $s1, $a0, -0x4CC0
    ctx->r17 = ADD32(ctx->r4, -0X4CC0);
L_800F1CC4:
    // 0x800F1CC4: lbu         $v0, 0x1($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X1);
    // 0x800F1CC8: bne         $v0, $zero, L_800F1D80
    if (ctx->r2 != 0) {
        // 0x800F1CCC: nop
    
            goto L_800F1D80;
    }
    // 0x800F1CCC: nop

    // 0x800F1CD0: lbu         $v0, 0x0($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X0);
    // 0x800F1CD4: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x800F1CD8: addu        $v0, $v0, $fp
    ctx->r2 = ADD32(ctx->r2, ctx->r30);
    // 0x800F1CDC: lhu         $a0, 0x0($v0)
    ctx->r4 = MEM_HU(ctx->r2, 0X0);
    // 0x800F1CE0: jal         0x8003FC28
    // 0x800F1CE4: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    func_8003FC28(rdram, ctx);
        goto after_2;
    // 0x800F1CE4: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    after_2:
    // 0x800F1CE8: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    // 0x800F1CEC: andi        $v0, $s0, 0xFFFF
    ctx->r2 = ctx->r16 & 0XFFFF;
    // 0x800F1CF0: beql        $v0, $s7, L_800F1E2C
    if (ctx->r2 == ctx->r23) {
        // 0x800F1CF4: addiu       $s1, $s1, 0x2
        ctx->r17 = ADD32(ctx->r17, 0X2);
            goto L_800F1E2C;
    }
    goto skip_0;
    // 0x800F1CF4: addiu       $s1, $s1, 0x2
    ctx->r17 = ADD32(ctx->r17, 0X2);
    skip_0:
    // 0x800F1CF8: ori         $s3, $zero, 0xFFFF
    ctx->r19 = 0 | 0XFFFF;
    // 0x800F1CFC: andi        $a0, $s0, 0xFFFF
    ctx->r4 = ctx->r16 & 0XFFFF;
L_800F1D00:
    // 0x800F1D00: beql        $a0, $s4, L_800F1E2C
    if (ctx->r4 == ctx->r20) {
        // 0x800F1D04: addiu       $s1, $s1, 0x2
        ctx->r17 = ADD32(ctx->r17, 0X2);
            goto L_800F1E2C;
    }
    goto skip_1;
    // 0x800F1D04: addiu       $s1, $s1, 0x2
    ctx->r17 = ADD32(ctx->r17, 0X2);
    skip_1:
    // 0x800F1D08: jal         0x8004013C
    // 0x800F1D0C: nop

    func_8004013C(rdram, ctx);
        goto after_3;
    // 0x800F1D0C: nop

    after_3:
    // 0x800F1D10: lw          $a0, 0xC($v0)
    ctx->r4 = MEM_W(ctx->r2, 0XC);
    // 0x800F1D14: beq         $a0, $zero, L_800F1D60
    if (ctx->r4 == 0) {
        // 0x800F1D18: addu        $a1, $s5, $zero
        ctx->r5 = ADD32(ctx->r21, 0);
            goto L_800F1D60;
    }
    // 0x800F1D18: addu        $a1, $s5, $zero
    ctx->r5 = ADD32(ctx->r21, 0);
    // 0x800F1D1C: addiu       $a2, $sp, 0x40
    ctx->r6 = ADD32(ctx->r29, 0X40);
    // 0x800F1D20: jal         0x8006A944
    // 0x800F1D24: addiu       $a3, $sp, 0x10
    ctx->r7 = ADD32(ctx->r29, 0X10);
    func_8006A944(rdram, ctx);
        goto after_4;
    // 0x800F1D24: addiu       $a3, $sp, 0x10
    ctx->r7 = ADD32(ctx->r29, 0X10);
    after_4:
    // 0x800F1D28: beq         $v0, $zero, L_800F1D60
    if (ctx->r2 == 0) {
        // 0x800F1D2C: nop
    
            goto L_800F1D60;
    }
    // 0x800F1D2C: nop

    // 0x800F1D30: lwc1        $f0, 0x2C($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x800F1D34: c.lt.s      $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f0.fl < ctx->f20.fl;
    // 0x800F1D38: nop

    // 0x800F1D3C: bc1f        L_800F1D60
    if (!c1cs) {
        // 0x800F1D40: nop
    
            goto L_800F1D60;
    }
    // 0x800F1D40: nop

    // 0x800F1D44: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x800F1D48: sh          $s0, 0x0($s6)
    MEM_H(0X0, ctx->r22) = ctx->r16;
    // 0x800F1D4C: lbu         $v0, 0x0($s2)
    ctx->r2 = MEM_BU(ctx->r18, 0X0);
    // 0x800F1D50: c.le.s      $f20, $f22
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 22);
    c1cs = ctx->f20.fl <= ctx->f22.fl;
    // 0x800F1D54: ori         $v0, $v0, 0x2
    ctx->r2 = ctx->r2 | 0X2;
    // 0x800F1D58: bc1t        L_800F1E3C
    if (c1cs) {
        // 0x800F1D5C: sb          $v0, 0x0($s2)
        MEM_B(0X0, ctx->r18) = ctx->r2;
            goto L_800F1E3C;
    }
    // 0x800F1D5C: sb          $v0, 0x0($s2)
    MEM_B(0X0, ctx->r18) = ctx->r2;
L_800F1D60:
    // 0x800F1D60: jal         0x8003EEF4
    // 0x800F1D64: addiu       $a0, $sp, 0x38
    ctx->r4 = ADD32(ctx->r29, 0X38);
    func_8003EEF4(rdram, ctx);
        goto after_5;
    // 0x800F1D64: addiu       $a0, $sp, 0x38
    ctx->r4 = ADD32(ctx->r29, 0X38);
    after_5:
    // 0x800F1D68: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    // 0x800F1D6C: andi        $v0, $s0, 0xFFFF
    ctx->r2 = ctx->r16 & 0XFFFF;
    // 0x800F1D70: beql        $v0, $s3, L_800F1E2C
    if (ctx->r2 == ctx->r19) {
        // 0x800F1D74: addiu       $s1, $s1, 0x2
        ctx->r17 = ADD32(ctx->r17, 0X2);
            goto L_800F1E2C;
    }
    goto skip_2;
    // 0x800F1D74: addiu       $s1, $s1, 0x2
    ctx->r17 = ADD32(ctx->r17, 0X2);
    skip_2:
    // 0x800F1D78: j           L_800F1D00
    // 0x800F1D7C: andi        $a0, $s0, 0xFFFF
    ctx->r4 = ctx->r16 & 0XFFFF;
        goto L_800F1D00;
    // 0x800F1D7C: andi        $a0, $s0, 0xFFFF
    ctx->r4 = ctx->r16 & 0XFFFF;
L_800F1D80:
    // 0x800F1D80: lbu         $v0, 0x0($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X0);
    // 0x800F1D84: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x800F1D88: addu        $v0, $v0, $fp
    ctx->r2 = ADD32(ctx->r2, ctx->r30);
    // 0x800F1D8C: lhu         $a0, 0x0($v0)
    ctx->r4 = MEM_HU(ctx->r2, 0X0);
    // 0x800F1D90: jal         0x8003FC28
    // 0x800F1D94: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    func_8003FC28(rdram, ctx);
        goto after_6;
    // 0x800F1D94: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    after_6:
    // 0x800F1D98: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    // 0x800F1D9C: andi        $v0, $s0, 0xFFFF
    ctx->r2 = ctx->r16 & 0XFFFF;
    // 0x800F1DA0: beql        $v0, $s7, L_800F1E2C
    if (ctx->r2 == ctx->r23) {
        // 0x800F1DA4: addiu       $s1, $s1, 0x2
        ctx->r17 = ADD32(ctx->r17, 0X2);
            goto L_800F1E2C;
    }
    goto skip_3;
    // 0x800F1DA4: addiu       $s1, $s1, 0x2
    ctx->r17 = ADD32(ctx->r17, 0X2);
    skip_3:
    // 0x800F1DA8: ori         $s3, $zero, 0xFFFF
    ctx->r19 = 0 | 0XFFFF;
    // 0x800F1DAC: andi        $a0, $s0, 0xFFFF
    ctx->r4 = ctx->r16 & 0XFFFF;
L_800F1DB0:
    // 0x800F1DB0: beql        $a0, $s4, L_800F1E2C
    if (ctx->r4 == ctx->r20) {
        // 0x800F1DB4: addiu       $s1, $s1, 0x2
        ctx->r17 = ADD32(ctx->r17, 0X2);
            goto L_800F1E2C;
    }
    goto skip_4;
    // 0x800F1DB4: addiu       $s1, $s1, 0x2
    ctx->r17 = ADD32(ctx->r17, 0X2);
    skip_4:
    // 0x800F1DB8: jal         0x8004013C
    // 0x800F1DBC: nop

    func_8004013C(rdram, ctx);
        goto after_7;
    // 0x800F1DBC: nop

    after_7:
    // 0x800F1DC0: lw          $a0, 0xC($v0)
    ctx->r4 = MEM_W(ctx->r2, 0XC);
    // 0x800F1DC4: beq         $a0, $zero, L_800F1E10
    if (ctx->r4 == 0) {
        // 0x800F1DC8: addu        $a1, $s5, $zero
        ctx->r5 = ADD32(ctx->r21, 0);
            goto L_800F1E10;
    }
    // 0x800F1DC8: addu        $a1, $s5, $zero
    ctx->r5 = ADD32(ctx->r21, 0);
    // 0x800F1DCC: jal         0x8006AB78
    // 0x800F1DD0: addiu       $a2, $sp, 0x40
    ctx->r6 = ADD32(ctx->r29, 0X40);
    func_8006AB78(rdram, ctx);
        goto after_8;
    // 0x800F1DD0: addiu       $a2, $sp, 0x40
    ctx->r6 = ADD32(ctx->r29, 0X40);
    after_8:
    // 0x800F1DD4: c.lt.s      $f24, $f0
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f24.fl < ctx->f0.fl;
    // 0x800F1DD8: nop

    // 0x800F1DDC: bc1f        L_800F1E10
    if (!c1cs) {
        // 0x800F1DE0: nop
    
            goto L_800F1E10;
    }
    // 0x800F1DE0: nop

    // 0x800F1DE4: c.lt.s      $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f0.fl < ctx->f20.fl;
    // 0x800F1DE8: nop

    // 0x800F1DEC: bc1f        L_800F1E10
    if (!c1cs) {
        // 0x800F1DF0: nop
    
            goto L_800F1E10;
    }
    // 0x800F1DF0: nop

    // 0x800F1DF4: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x800F1DF8: sh          $s0, 0x0($s6)
    MEM_H(0X0, ctx->r22) = ctx->r16;
    // 0x800F1DFC: lbu         $v0, 0x0($s2)
    ctx->r2 = MEM_BU(ctx->r18, 0X0);
    // 0x800F1E00: c.le.s      $f20, $f22
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 22);
    c1cs = ctx->f20.fl <= ctx->f22.fl;
    // 0x800F1E04: ori         $v0, $v0, 0x2
    ctx->r2 = ctx->r2 | 0X2;
    // 0x800F1E08: bc1t        L_800F1E3C
    if (c1cs) {
        // 0x800F1E0C: sb          $v0, 0x0($s2)
        MEM_B(0X0, ctx->r18) = ctx->r2;
            goto L_800F1E3C;
    }
    // 0x800F1E0C: sb          $v0, 0x0($s2)
    MEM_B(0X0, ctx->r18) = ctx->r2;
L_800F1E10:
    // 0x800F1E10: jal         0x8003EEF4
    // 0x800F1E14: addiu       $a0, $sp, 0x38
    ctx->r4 = ADD32(ctx->r29, 0X38);
    func_8003EEF4(rdram, ctx);
        goto after_9;
    // 0x800F1E14: addiu       $a0, $sp, 0x38
    ctx->r4 = ADD32(ctx->r29, 0X38);
    after_9:
    // 0x800F1E18: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    // 0x800F1E1C: andi        $v0, $s0, 0xFFFF
    ctx->r2 = ctx->r16 & 0XFFFF;
    // 0x800F1E20: bnel        $v0, $s3, L_800F1DB0
    if (ctx->r2 != ctx->r19) {
        // 0x800F1E24: andi        $a0, $s0, 0xFFFF
        ctx->r4 = ctx->r16 & 0XFFFF;
            goto L_800F1DB0;
    }
    goto skip_5;
    // 0x800F1E24: andi        $a0, $s0, 0xFFFF
    ctx->r4 = ctx->r16 & 0XFFFF;
    skip_5:
    // 0x800F1E28: addiu       $s1, $s1, 0x2
    ctx->r17 = ADD32(ctx->r17, 0X2);
L_800F1E2C:
    // 0x800F1E2C: lbu         $v1, 0x0($s1)
    ctx->r3 = MEM_BU(ctx->r17, 0X0);
    // 0x800F1E30: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // 0x800F1E34: bne         $v1, $v0, L_800F1CC4
    if (ctx->r3 != ctx->r2) {
        // 0x800F1E38: nop
    
            goto L_800F1CC4;
    }
    // 0x800F1E38: nop

L_800F1E3C:
    // 0x800F1E3C: mov.s       $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    ctx->f0.fl = ctx->f20.fl;
L_800F1E40:
    // 0x800F1E40: lw          $ra, 0x74($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X74);
    // 0x800F1E44: lw          $fp, 0x70($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X70);
    // 0x800F1E48: lw          $s7, 0x6C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X6C);
    // 0x800F1E4C: lw          $s6, 0x68($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X68);
    // 0x800F1E50: lw          $s5, 0x64($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X64);
    // 0x800F1E54: lw          $s4, 0x60($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X60);
    // 0x800F1E58: lw          $s3, 0x5C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X5C);
    // 0x800F1E5C: lw          $s2, 0x58($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X58);
    // 0x800F1E60: lw          $s1, 0x54($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X54);
    // 0x800F1E64: lw          $s0, 0x50($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X50);
    // 0x800F1E68: ldc1        $f24, 0x88($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X88);
    // 0x800F1E6C: ldc1        $f22, 0x80($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X80);
    // 0x800F1E70: ldc1        $f20, 0x78($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X78);
    // 0x800F1E74: jr          $ra
    // 0x800F1E78: addiu       $sp, $sp, 0x90
    ctx->r29 = ADD32(ctx->r29, 0X90);
    return;
    // 0x800F1E78: addiu       $sp, $sp, 0x90
    ctx->r29 = ADD32(ctx->r29, 0X90);
;}
RECOMP_FUNC void func_800F1E7C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F1E7C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800F1E80: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x800F1E84: lw          $s3, 0x40($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X40);
    // 0x800F1E88: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800F1E8C: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x800F1E90: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x800F1E94: addu        $s2, $a2, $zero
    ctx->r18 = ADD32(ctx->r6, 0);
    // 0x800F1E98: sw          $ra, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r31;
    // 0x800F1E9C: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x800F1EA0: lbu         $v0, 0x1A7($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X1A7);
    // 0x800F1EA4: bne         $v0, $zero, L_800F1F18
    if (ctx->r2 != 0) {
        // 0x800F1EA8: addu        $s1, $s3, $zero
        ctx->r17 = ADD32(ctx->r19, 0);
            goto L_800F1F18;
    }
    // 0x800F1EA8: addu        $s1, $s3, $zero
    ctx->r17 = ADD32(ctx->r19, 0);
    // 0x800F1EAC: ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
    // 0x800F1EB0: sh          $v0, 0x6($s2)
    MEM_H(0X6, ctx->r18) = ctx->r2;
    // 0x800F1EB4: andi        $v0, $a1, 0xFF
    ctx->r2 = ctx->r5 & 0XFF;
    // 0x800F1EB8: bne         $v0, $zero, L_800F1F98
    if (ctx->r2 != 0) {
        // 0x800F1EBC: lui         $v1, 0xFF00
        ctx->r3 = S32(0XFF00 << 16);
            goto L_800F1F98;
    }
    // 0x800F1EBC: lui         $v1, 0xFF00
    ctx->r3 = S32(0XFF00 << 16);
    // 0x800F1EC0: lw          $v0, 0x1A4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1A4);
    // 0x800F1EC4: ori         $v1, $v1, 0xFF00
    ctx->r3 = ctx->r3 | 0XFF00;
    // 0x800F1EC8: and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // 0x800F1ECC: bne         $v0, $zero, L_800F1F98
    if (ctx->r2 != 0) {
        // 0x800F1ED0: andi        $v1, $a3, 0xFF
        ctx->r3 = ctx->r7 & 0XFF;
            goto L_800F1F98;
    }
    // 0x800F1ED0: andi        $v1, $a3, 0xFF
    ctx->r3 = ctx->r7 & 0XFF;
    // 0x800F1ED4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800F1ED8: bne         $v1, $v0, L_800F1F08
    if (ctx->r3 != ctx->r2) {
        // 0x800F1EDC: addu        $a0, $s2, $zero
        ctx->r4 = ADD32(ctx->r18, 0);
            goto L_800F1F08;
    }
    // 0x800F1EDC: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // 0x800F1EE0: lhu         $a0, 0x198($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X198);
    // 0x800F1EE4: jal         0x8004015C
    // 0x800F1EE8: nop

    func_8004015C(rdram, ctx);
        goto after_0;
    // 0x800F1EE8: nop

    after_0:
    // 0x800F1EEC: lw          $t0, 0x0($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X0);
    // 0x800F1EF0: lw          $t1, 0x4($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X4);
    // 0x800F1EF4: lw          $t2, 0x8($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X8);
    // 0x800F1EF8: sw          $t0, 0x10($s2)
    MEM_W(0X10, ctx->r18) = ctx->r8;
    // 0x800F1EFC: sw          $t1, 0x14($s2)
    MEM_W(0X14, ctx->r18) = ctx->r9;
    // 0x800F1F00: sw          $t2, 0x18($s2)
    MEM_W(0X18, ctx->r18) = ctx->r10;
    // 0x800F1F04: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
L_800F1F08:
    // 0x800F1F08: jal         0x80046620
    // 0x800F1F0C: addiu       $a1, $a0, 0x10
    ctx->r5 = ADD32(ctx->r4, 0X10);
    func_80046620(rdram, ctx);
        goto after_1;
    // 0x800F1F0C: addiu       $a1, $a0, 0x10
    ctx->r5 = ADD32(ctx->r4, 0X10);
    after_1:
    // 0x800F1F10: j           L_800F1F98
    // 0x800F1F14: nop

        goto L_800F1F98;
    // 0x800F1F14: nop

L_800F1F18:
    // 0x800F1F18: lhu         $v1, 0x6($s2)
    ctx->r3 = MEM_HU(ctx->r18, 0X6);
    // 0x800F1F1C: lhu         $v0, 0x198($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X198);
    // 0x800F1F20: bne         $v1, $v0, L_800F1F34
    if (ctx->r3 != ctx->r2) {
        // 0x800F1F24: andi        $v0, $a1, 0xFF
        ctx->r2 = ctx->r5 & 0XFF;
            goto L_800F1F34;
    }
    // 0x800F1F24: andi        $v0, $a1, 0xFF
    ctx->r2 = ctx->r5 & 0XFF;
    // 0x800F1F28: ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
    // 0x800F1F2C: sh          $v0, 0x6($s2)
    MEM_H(0X6, ctx->r18) = ctx->r2;
    // 0x800F1F30: andi        $v0, $a1, 0xFF
    ctx->r2 = ctx->r5 & 0XFF;
L_800F1F34:
    // 0x800F1F34: bne         $v0, $zero, L_800F1F68
    if (ctx->r2 != 0) {
        // 0x800F1F38: lui         $v1, 0xFF00
        ctx->r3 = S32(0XFF00 << 16);
            goto L_800F1F68;
    }
    // 0x800F1F38: lui         $v1, 0xFF00
    ctx->r3 = S32(0XFF00 << 16);
    // 0x800F1F3C: lw          $v0, 0x1A4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1A4);
    // 0x800F1F40: ori         $v1, $v1, 0xFF00
    ctx->r3 = ctx->r3 | 0XFF00;
    // 0x800F1F44: and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // 0x800F1F48: bne         $v0, $zero, L_800F1F68
    if (ctx->r2 != 0) {
        // 0x800F1F4C: nop
    
            goto L_800F1F68;
    }
    // 0x800F1F4C: nop

    // 0x800F1F50: lw          $v1, 0x19C($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X19C);
    // 0x800F1F54: beq         $v1, $zero, L_800F1F98
    if (ctx->r3 == 0) {
        // 0x800F1F58: nop
    
            goto L_800F1F98;
    }
    // 0x800F1F58: nop

    // 0x800F1F5C: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x800F1F60: j           L_800F1F94
    // 0x800F1F64: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
        goto L_800F1F94;
    // 0x800F1F64: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
L_800F1F68:
    // 0x800F1F68: lw          $v1, 0x19C($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X19C);
    // 0x800F1F6C: beq         $v1, $zero, L_800F1F80
    if (ctx->r3 == 0) {
        // 0x800F1F70: nop
    
            goto L_800F1F80;
    }
    // 0x800F1F70: nop

    // 0x800F1F74: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x800F1F78: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x800F1F7C: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
L_800F1F80:
    // 0x800F1F80: lw          $v1, 0x1A0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X1A0);
    // 0x800F1F84: beq         $v1, $zero, L_800F1F98
    if (ctx->r3 == 0) {
        // 0x800F1F88: nop
    
            goto L_800F1F98;
    }
    // 0x800F1F88: nop

    // 0x800F1F8C: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x800F1F90: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
L_800F1F94:
    // 0x800F1F94: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
L_800F1F98:
    // 0x800F1F98: lbu         $v0, 0x1A5($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X1A5);
    // 0x800F1F9C: beq         $v0, $zero, L_800F1FD4
    if (ctx->r2 == 0) {
        // 0x800F1FA0: nop
    
            goto L_800F1FD4;
    }
    // 0x800F1FA0: nop

    // 0x800F1FA4: beq         $s3, $zero, L_800F1FD4
    if (ctx->r19 == 0) {
        // 0x800F1FA8: nop
    
            goto L_800F1FD4;
    }
    // 0x800F1FA8: nop

    // 0x800F1FAC: lw          $v0, 0x10($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X10);
    // 0x800F1FB0: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // 0x800F1FB4: lw          $v0, 0x14($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X14);
    // 0x800F1FB8: sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    // 0x800F1FBC: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x800F1FC0: lw          $a1, 0x4($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X4);
    // 0x800F1FC4: lw          $a2, 0x8($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X8);
    // 0x800F1FC8: lw          $a3, 0xC($s1)
    ctx->r7 = MEM_W(ctx->r17, 0XC);
    // 0x800F1FCC: jal         0x80065914
    // 0x800F1FD0: nop

    datItemSetObjectiveBooleanCount(rdram, ctx);
        goto after_2;
    // 0x800F1FD0: nop

    after_2:
L_800F1FD4:
    // 0x800F1FD4: lw          $ra, 0x28($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X28);
    // 0x800F1FD8: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x800F1FDC: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x800F1FE0: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x800F1FE4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800F1FE8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800F1FEC: jr          $ra
    // 0x800F1FF0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x800F1FF0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_800F1FF4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F1FF4: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800F1FF8: sw          $ra, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r31;
    // 0x800F1FFC: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x800F2000: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x800F2004: lbu         $v0, 0x1A7($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X1A7);
    // 0x800F2008: bne         $v0, $zero, L_800F205C
    if (ctx->r2 != 0) {
        // 0x800F200C: addu        $s1, $a1, $zero
        ctx->r17 = ADD32(ctx->r5, 0);
            goto L_800F205C;
    }
    // 0x800F200C: addu        $s1, $a1, $zero
    ctx->r17 = ADD32(ctx->r5, 0);
    // 0x800F2010: lhu         $a0, 0x198($a0)
    ctx->r4 = MEM_HU(ctx->r4, 0X198);
    // 0x800F2014: jal         0x8004015C
    // 0x800F2018: nop

    func_8004015C(rdram, ctx);
        goto after_0;
    // 0x800F2018: nop

    after_0:
    // 0x800F201C: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    // 0x800F2020: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x800F2024: jal         0x80059E00
    // 0x800F2028: addiu       $a1, $sp, 0x10
    ctx->r5 = ADD32(ctx->r29, 0X10);
    func_80059E00(rdram, ctx);
        goto after_1;
    // 0x800F2028: addiu       $a1, $sp, 0x10
    ctx->r5 = ADD32(ctx->r29, 0X10);
    after_1:
    // 0x800F202C: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x800F2030: lw          $a2, 0x4($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X4);
    // 0x800F2034: lw          $a3, 0x8($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X8);
    // 0x800F2038: sw          $v1, 0x10($s1)
    MEM_W(0X10, ctx->r17) = ctx->r3;
    // 0x800F203C: sw          $a2, 0x14($s1)
    MEM_W(0X14, ctx->r17) = ctx->r6;
    // 0x800F2040: sw          $a3, 0x18($s1)
    MEM_W(0X18, ctx->r17) = ctx->r7;
    // 0x800F2044: lw          $v1, 0x10($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X10);
    // 0x800F2048: lw          $a2, 0x14($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X14);
    // 0x800F204C: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
    // 0x800F2050: sw          $v1, 0x1C($s1)
    MEM_W(0X1C, ctx->r17) = ctx->r3;
    // 0x800F2054: sw          $a2, 0x20($s1)
    MEM_W(0X20, ctx->r17) = ctx->r6;
    // 0x800F2058: sw          $a3, 0x24($s1)
    MEM_W(0X24, ctx->r17) = ctx->r7;
L_800F205C:
    // 0x800F205C: lw          $ra, 0x28($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X28);
    // 0x800F2060: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x800F2064: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x800F2068: jr          $ra
    // 0x800F206C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x800F206C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void setNpcHealth(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F2070: lbu         $v0, 0x1A7($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X1A7);
    // 0x800F2074: bne         $v0, $zero, L_800F20B0
    if (ctx->r2 != 0) {
        // 0x800F2078: addu        $a3, $a2, $zero
        ctx->r7 = ADD32(ctx->r6, 0);
            goto L_800F20B0;
    }
    // 0x800F2078: addu        $a3, $a2, $zero
    ctx->r7 = ADD32(ctx->r6, 0);
    // 0x800F207C: sw          $a1, 0x190($a0)
    MEM_W(0X190, ctx->r4) = ctx->r5;
    // 0x800F2080: lw          $v1, 0x54($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X54);
    // 0x800F2084: lui         $v0, 0x8000
    ctx->r2 = S32(0X8000 << 16);
    // 0x800F2088: bne         $v1, $v0, L_800F20A4
    if (ctx->r3 != ctx->r2) {
        // 0x800F208C: lui         $v0, 0x8013
        ctx->r2 = S32(0X8013 << 16);
            goto L_800F20A4;
    }
    // 0x800F208C: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800F2090: lw          $v0, 0x7CE4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X7CE4);
    // 0x800F2094: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800F2098: addu        $v0, $v0, $a1
    ctx->r2 = ADD32(ctx->r2, ctx->r5);
    // 0x800F209C: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x800F20A0: sw          $v0, 0x54($a2)
    MEM_W(0X54, ctx->r6) = ctx->r2;
L_800F20A4:
    // 0x800F20A4: lw          $v0, 0x54($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X54);
    // 0x800F20A8: j           L_800F20D0
    // 0x800F20AC: sw          $v0, 0x194($a0)
    MEM_W(0X194, ctx->r4) = ctx->r2;
        goto L_800F20D0;
    // 0x800F20AC: sw          $v0, 0x194($a0)
    MEM_W(0X194, ctx->r4) = ctx->r2;
L_800F20B0:
    // 0x800F20B0: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800F20B4: lw          $v0, 0x7CE4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X7CE4);
    // 0x800F20B8: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800F20BC: addu        $v0, $v0, $a1
    ctx->r2 = ADD32(ctx->r2, ctx->r5);
    // 0x800F20C0: lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X0);
    // 0x800F20C4: sw          $v1, 0x190($a0)
    MEM_W(0X190, ctx->r4) = ctx->r3;
    // 0x800F20C8: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x800F20CC: sw          $v0, 0x194($a0)
    MEM_W(0X194, ctx->r4) = ctx->r2;
L_800F20D0:
    // 0x800F20D0: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800F20D4: lw          $v0, 0x7CE4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X7CE4);
    // 0x800F20D8: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800F20DC: addu        $v0, $v0, $a1
    ctx->r2 = ADD32(ctx->r2, ctx->r5);
    // 0x800F20E0: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x800F20E4: jr          $ra
    // 0x800F20E8: nop

    return;
    // 0x800F20E8: nop

;}
RECOMP_FUNC void getNpcCurrentHealth(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F20EC: lbu         $v0, 0x1A7($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X1A7);
    // 0x800F20F0: bne         $v0, $zero, L_800F2114
    if (ctx->r2 != 0) {
        // 0x800F20F4: lui         $v0, 0x8013
        ctx->r2 = S32(0X8013 << 16);
            goto L_800F2114;
    }
    // 0x800F20F4: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800F20F8: lw          $v0, 0x7CE4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X7CE4);
    // 0x800F20FC: lw          $v1, 0x190($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X190);
    // 0x800F2100: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800F2104: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800F2108: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x800F210C: jr          $ra
    // 0x800F2110: nop

    return;
    // 0x800F2110: nop

L_800F2114:
    // 0x800F2114: lw          $v0, 0x190($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X190);
    // 0x800F2118: jr          $ra
    // 0x800F211C: nop

    return;
    // 0x800F211C: nop

;}
RECOMP_FUNC void dealDamageToNpc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F2120: lbu         $v0, 0x1A7($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X1A7);
    // 0x800F2124: bne         $v0, $zero, L_800F214C
    if (ctx->r2 != 0) {
        // 0x800F2128: lui         $v0, 0x8013
        ctx->r2 = S32(0X8013 << 16);
            goto L_800F214C;
    }
    // 0x800F2128: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800F212C: lw          $v1, 0x7CE4($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X7CE4);
    // 0x800F2130: lw          $v0, 0x190($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X190);
    // 0x800F2134: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x800F2138: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x800F213C: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x800F2140: subu        $v0, $v0, $a1
    ctx->r2 = SUB32(ctx->r2, ctx->r5);
    // 0x800F2144: jr          $ra
    // 0x800F2148: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    return;
    // 0x800F2148: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
L_800F214C:
    // 0x800F214C: lw          $v0, 0x190($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X190);
    // 0x800F2150: subu        $v0, $v0, $a1
    ctx->r2 = SUB32(ctx->r2, ctx->r5);
    // 0x800F2154: jr          $ra
    // 0x800F2158: sw          $v0, 0x190($a0)
    MEM_W(0X190, ctx->r4) = ctx->r2;
    return;
    // 0x800F2158: sw          $v0, 0x190($a0)
    MEM_W(0X190, ctx->r4) = ctx->r2;
;}
RECOMP_FUNC void getNpcMissingHealth(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F215C: lbu         $v0, 0x1A7($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X1A7);
    // 0x800F2160: bne         $v0, $zero, L_800F218C
    if (ctx->r2 != 0) {
        // 0x800F2164: nop
    
            goto L_800F218C;
    }
    // 0x800F2164: nop

    // 0x800F2168: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800F216C: lw          $v0, 0x7CE4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X7CE4);
    // 0x800F2170: lw          $v1, 0x190($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X190);
    // 0x800F2174: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800F2178: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800F217C: lw          $v1, 0x194($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X194);
    // 0x800F2180: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x800F2184: jr          $ra
    // 0x800F2188: subu        $v0, $v1, $v0
    ctx->r2 = SUB32(ctx->r3, ctx->r2);
    return;
    // 0x800F2188: subu        $v0, $v1, $v0
    ctx->r2 = SUB32(ctx->r3, ctx->r2);
L_800F218C:
    // 0x800F218C: lw          $v1, 0x194($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X194);
    // 0x800F2190: lw          $v0, 0x190($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X190);
    // 0x800F2194: jr          $ra
    // 0x800F2198: subu        $v0, $v1, $v0
    ctx->r2 = SUB32(ctx->r3, ctx->r2);
    return;
    // 0x800F2198: subu        $v0, $v1, $v0
    ctx->r2 = SUB32(ctx->r3, ctx->r2);
;}
RECOMP_FUNC void getNpcHealthPercentage(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F219C: lbu         $v0, 0x1A7($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X1A7);
    // 0x800F21A0: bne         $v0, $zero, L_800F21E0
    if (ctx->r2 != 0) {
        // 0x800F21A4: lui         $v0, 0x8013
        ctx->r2 = S32(0X8013 << 16);
            goto L_800F21E0;
    }
    // 0x800F21A4: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800F21A8: lwc1        $f2, 0x194($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X194);
    // 0x800F21AC: cvt.s.w     $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    ctx->f2.fl = CVT_S_W(ctx->f2.u32l);
    // 0x800F21B0: lw          $v0, 0x7CE4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X7CE4);
    // 0x800F21B4: lw          $v1, 0x190($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X190);
    // 0x800F21B8: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800F21BC: lwc1        $f4, -0x7628($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X7628);
    // 0x800F21C0: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800F21C4: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800F21C8: lwc1        $f0, 0x0($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X0);
    // 0x800F21CC: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x800F21D0: div.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f2.fl);
    // 0x800F21D4: mul.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x800F21D8: jr          $ra
    // 0x800F21DC: nop

    return;
    // 0x800F21DC: nop

L_800F21E0:
    // 0x800F21E0: lwc1        $f0, 0x190($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X190);
    // 0x800F21E4: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x800F21E8: lwc1        $f2, 0x194($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X194);
    // 0x800F21EC: cvt.s.w     $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    ctx->f2.fl = CVT_S_W(ctx->f2.u32l);
    // 0x800F21F0: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800F21F4: lwc1        $f4, -0x7624($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X7624);
    // 0x800F21F8: div.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f2.fl);
    // 0x800F21FC: mul.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x800F2200: jr          $ra
    // 0x800F2204: nop

    return;
    // 0x800F2204: nop

;}
RECOMP_FUNC void func_800F2208(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F2208: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x800F220C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800F2210: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x800F2214: sdc1        $f26, 0x40($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X40, ctx->r29);
    // 0x800F2218: sdc1        $f24, 0x38($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X38, ctx->r29);
    // 0x800F221C: sdc1        $f22, 0x30($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X30, ctx->r29);
    // 0x800F2220: sdc1        $f20, 0x28($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X28, ctx->r29);
    // 0x800F2224: lwc1        $f4, 0x0($a3)
    ctx->f4.u32l = MEM_W(ctx->r7, 0X0);
    // 0x800F2228: lwc1        $f0, 0x0($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X0);
    // 0x800F222C: mtc1        $a1, $f8
    ctx->f8.u32l = ctx->r5;
    // 0x800F2230: sub.s       $f4, $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f4.fl - ctx->f0.fl;
    // 0x800F2234: mtc1        $a1, $f10
    ctx->f10.u32l = ctx->r5;
    // 0x800F2238: mul.s       $f6, $f8, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x800F223C: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x800F2240: lwc1        $f0, 0x4($a3)
    ctx->f0.u32l = MEM_W(ctx->r7, 0X4);
    // 0x800F2244: lwc1        $f2, 0x4($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X4);
    // 0x800F2248: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x800F224C: mul.s       $f4, $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f4.fl = MUL_S(ctx->f4.fl, ctx->f4.fl);
    // 0x800F2250: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    // 0x800F2254: lwc1        $f0, 0x8($a3)
    ctx->f0.u32l = MEM_W(ctx->r7, 0X8);
    // 0x800F2258: lwc1        $f2, 0x8($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X8);
    // 0x800F225C: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x800F2260: mul.s       $f2, $f0, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x800F2264: mtc1        $a2, $f26
    ctx->f26.u32l = ctx->r6;
    // 0x800F2268: add.s       $f24, $f4, $f2
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f24.fl = ctx->f4.fl + ctx->f2.fl;
    // 0x800F226C: c.lt.s      $f6, $f24
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 24);
    c1cs = ctx->f6.fl < ctx->f24.fl;
    // 0x800F2270: nop

    // 0x800F2274: bc1f        L_800F2284
    if (!c1cs) {
        // 0x800F2278: swc1        $f0, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
            goto L_800F2284;
    }
    // 0x800F2278: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    // 0x800F227C: j           L_800F22F0
    // 0x800F2280: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
        goto L_800F22F0;
    // 0x800F2280: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_800F2284:
    // 0x800F2284: addiu       $s0, $a0, 0xC
    ctx->r16 = ADD32(ctx->r4, 0XC);
    // 0x800F2288: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x800F228C: jal         0x8001CFE8
    // 0x800F2290: addiu       $a1, $sp, 0x10
    ctx->r5 = ADD32(ctx->r29, 0X10);
    func_8001CFE8(rdram, ctx);
        goto after_0;
    // 0x800F2290: addiu       $a1, $sp, 0x10
    ctx->r5 = ADD32(ctx->r29, 0X10);
    after_0:
    // 0x800F2294: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x800F2298: jal         0x8001CF2C
    // 0x800F229C: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
    func_8001CF2C(rdram, ctx);
        goto after_1;
    // 0x800F229C: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
    after_1:
    // 0x800F22A0: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    // 0x800F22A4: jal         0x8001CF2C
    // 0x800F22A8: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    func_8001CF2C(rdram, ctx);
        goto after_2;
    // 0x800F22A8: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    after_2:
    // 0x800F22AC: mul.s       $f20, $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f20.fl = MUL_S(ctx->f20.fl, ctx->f0.fl);
    // 0x800F22B0: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800F22B4: lwc1        $f0, -0x7620($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X7620);
    // 0x800F22B8: c.lt.s      $f24, $f0
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f24.fl < ctx->f0.fl;
    // 0x800F22BC: nop

    // 0x800F22C0: bc1f        L_800F22DC
    if (!c1cs) {
        // 0x800F22C4: div.s       $f22, $f22, $f20
        CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f22.fl = DIV_S(ctx->f22.fl, ctx->f20.fl);
            goto L_800F22DC;
    }
    // 0x800F22C4: div.s       $f22, $f22, $f20
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f22.fl = DIV_S(ctx->f22.fl, ctx->f20.fl);
    // 0x800F22C8: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800F22CC: c.le.s      $f0, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    c1cs = ctx->f0.fl <= ctx->f22.fl;
    // 0x800F22D0: nop

    // 0x800F22D4: bc1t        L_800F22F0
    if (c1cs) {
        // 0x800F22D8: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_800F22F0;
    }
    // 0x800F22D8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800F22DC:
    // 0x800F22DC: c.lt.s      $f22, $f26
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 26);
    c1cs = ctx->f22.fl < ctx->f26.fl;
    // 0x800F22E0: nop

    // 0x800F22E4: bc1t        L_800F22F0
    if (c1cs) {
        // 0x800F22E8: addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
            goto L_800F22F0;
    }
    // 0x800F22E8: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // 0x800F22EC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800F22F0:
    // 0x800F22F0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800F22F4: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x800F22F8: ldc1        $f26, 0x40($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X40);
    // 0x800F22FC: ldc1        $f24, 0x38($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X38);
    // 0x800F2300: ldc1        $f22, 0x30($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X30);
    // 0x800F2304: ldc1        $f20, 0x28($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X28);
    // 0x800F2308: jr          $ra
    // 0x800F230C: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x800F230C: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void func_800F2310(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F2310: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x800F2314: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800F2318: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x800F231C: sdc1        $f24, 0x38($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X38, ctx->r29);
    // 0x800F2320: sdc1        $f22, 0x30($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X30, ctx->r29);
    // 0x800F2324: sdc1        $f20, 0x28($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X28, ctx->r29);
    // 0x800F2328: lwc1        $f4, 0x0($a3)
    ctx->f4.u32l = MEM_W(ctx->r7, 0X0);
    // 0x800F232C: lwc1        $f0, 0x0($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X0);
    // 0x800F2330: mtc1        $a1, $f8
    ctx->f8.u32l = ctx->r5;
    // 0x800F2334: sub.s       $f4, $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f4.fl - ctx->f0.fl;
    // 0x800F2338: mtc1        $a1, $f10
    ctx->f10.u32l = ctx->r5;
    // 0x800F233C: mul.s       $f6, $f8, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x800F2340: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x800F2344: lwc1        $f0, 0x4($a3)
    ctx->f0.u32l = MEM_W(ctx->r7, 0X4);
    // 0x800F2348: lwc1        $f2, 0x4($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X4);
    // 0x800F234C: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x800F2350: mul.s       $f4, $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f4.fl = MUL_S(ctx->f4.fl, ctx->f4.fl);
    // 0x800F2354: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    // 0x800F2358: lwc1        $f0, 0x8($a3)
    ctx->f0.u32l = MEM_W(ctx->r7, 0X8);
    // 0x800F235C: lwc1        $f2, 0x8($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X8);
    // 0x800F2360: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x800F2364: mul.s       $f2, $f0, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x800F2368: mtc1        $a2, $f24
    ctx->f24.u32l = ctx->r6;
    // 0x800F236C: add.s       $f4, $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f2.fl;
    // 0x800F2370: c.lt.s      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.fl < ctx->f4.fl;
    // 0x800F2374: nop

    // 0x800F2378: bc1t        L_800F23D8
    if (c1cs) {
        // 0x800F237C: swc1        $f0, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
            goto L_800F23D8;
    }
    // 0x800F237C: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    // 0x800F2380: addiu       $s0, $a0, 0xC
    ctx->r16 = ADD32(ctx->r4, 0XC);
    // 0x800F2384: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x800F2388: jal         0x8001CFE8
    // 0x800F238C: addiu       $a1, $sp, 0x10
    ctx->r5 = ADD32(ctx->r29, 0X10);
    func_8001CFE8(rdram, ctx);
        goto after_0;
    // 0x800F238C: addiu       $a1, $sp, 0x10
    ctx->r5 = ADD32(ctx->r29, 0X10);
    after_0:
    // 0x800F2390: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x800F2394: jal         0x8001CF2C
    // 0x800F2398: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
    func_8001CF2C(rdram, ctx);
        goto after_1;
    // 0x800F2398: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
    after_1:
    // 0x800F239C: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    // 0x800F23A0: jal         0x8001CF2C
    // 0x800F23A4: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    func_8001CF2C(rdram, ctx);
        goto after_2;
    // 0x800F23A4: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    after_2:
    // 0x800F23A8: mul.s       $f20, $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f20.fl = MUL_S(ctx->f20.fl, ctx->f0.fl);
    // 0x800F23AC: div.s       $f22, $f22, $f20
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f22.fl = DIV_S(ctx->f22.fl, ctx->f20.fl);
    // 0x800F23B0: c.lt.s      $f22, $f24
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 24);
    c1cs = ctx->f22.fl < ctx->f24.fl;
    // 0x800F23B4: nop

    // 0x800F23B8: bc1tl       L_800F23DC
    if (c1cs) {
        // 0x800F23BC: addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
            goto L_800F23DC;
    }
    goto skip_0;
    // 0x800F23BC: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    skip_0:
    // 0x800F23C0: jal         0x8001CF2C
    // 0x800F23C4: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    func_8001CF2C(rdram, ctx);
        goto after_3;
    // 0x800F23C4: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    after_3:
    // 0x800F23C8: lw          $v0, 0x50($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X50);
    // 0x800F23CC: swc1        $f0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f0.u32l;
    // 0x800F23D0: j           L_800F23DC
    // 0x800F23D4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_800F23DC;
    // 0x800F23D4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800F23D8:
    // 0x800F23D8: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_800F23DC:
    // 0x800F23DC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800F23E0: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x800F23E4: ldc1        $f24, 0x38($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X38);
    // 0x800F23E8: ldc1        $f22, 0x30($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X30);
    // 0x800F23EC: ldc1        $f20, 0x28($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X28);
    // 0x800F23F0: jr          $ra
    // 0x800F23F4: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x800F23F4: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void func_800F23F8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F23F8: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x800F23FC: sw          $s0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r16;
    // 0x800F2400: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x800F2404: sw          $ra, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r31;
    // 0x800F2408: sw          $s1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r17;
    // 0x800F240C: sdc1        $f24, 0x50($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X50, ctx->r29);
    // 0x800F2410: sdc1        $f22, 0x48($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X48, ctx->r29);
    // 0x800F2414: sdc1        $f20, 0x40($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X40, ctx->r29);
    // 0x800F2418: lwc1        $f4, 0x0($a3)
    ctx->f4.u32l = MEM_W(ctx->r7, 0X0);
    // 0x800F241C: lwc1        $f0, 0x0($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X0);
    // 0x800F2420: mtc1        $a1, $f8
    ctx->f8.u32l = ctx->r5;
    // 0x800F2424: sub.s       $f4, $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f4.fl - ctx->f0.fl;
    // 0x800F2428: mtc1        $a1, $f10
    ctx->f10.u32l = ctx->r5;
    // 0x800F242C: mul.s       $f6, $f8, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x800F2430: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x800F2434: lwc1        $f0, 0x4($a3)
    ctx->f0.u32l = MEM_W(ctx->r7, 0X4);
    // 0x800F2438: lwc1        $f2, 0x4($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X4);
    // 0x800F243C: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x800F2440: mul.s       $f4, $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f4.fl = MUL_S(ctx->f4.fl, ctx->f4.fl);
    // 0x800F2444: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    // 0x800F2448: lwc1        $f0, 0x8($a3)
    ctx->f0.u32l = MEM_W(ctx->r7, 0X8);
    // 0x800F244C: lwc1        $f2, 0x8($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X8);
    // 0x800F2450: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x800F2454: mul.s       $f2, $f0, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x800F2458: mtc1        $a2, $f24
    ctx->f24.u32l = ctx->r6;
    // 0x800F245C: add.s       $f4, $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f2.fl;
    // 0x800F2460: c.lt.s      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.fl < ctx->f4.fl;
    // 0x800F2464: nop

    // 0x800F2468: bc1t        L_800F24B8
    if (c1cs) {
        // 0x800F246C: swc1        $f0, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
            goto L_800F24B8;
    }
    // 0x800F246C: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    // 0x800F2470: jal         0x8001CF58
    // 0x800F2474: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    normalize_vector(rdram, ctx);
        goto after_0;
    // 0x800F2474: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    after_0:
    // 0x800F2478: addiu       $s1, $s0, 0xC
    ctx->r17 = ADD32(ctx->r16, 0XC);
    // 0x800F247C: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x800F2480: jal         0x8001CFE8
    // 0x800F2484: addiu       $a1, $sp, 0x10
    ctx->r5 = ADD32(ctx->r29, 0X10);
    func_8001CFE8(rdram, ctx);
        goto after_1;
    // 0x800F2484: addiu       $a1, $sp, 0x10
    ctx->r5 = ADD32(ctx->r29, 0X10);
    after_1:
    // 0x800F2488: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x800F248C: jal         0x8001CF2C
    // 0x800F2490: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
    func_8001CF2C(rdram, ctx);
        goto after_2;
    // 0x800F2490: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
    after_2:
    // 0x800F2494: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    // 0x800F2498: jal         0x8001CF2C
    // 0x800F249C: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    func_8001CF2C(rdram, ctx);
        goto after_3;
    // 0x800F249C: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    after_3:
    // 0x800F24A0: mul.s       $f20, $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f20.fl = MUL_S(ctx->f20.fl, ctx->f0.fl);
    // 0x800F24A4: div.s       $f12, $f22, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f12.fl = DIV_S(ctx->f22.fl, ctx->f20.fl);
    // 0x800F24A8: c.lt.s      $f12, $f24
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 24);
    c1cs = ctx->f12.fl < ctx->f24.fl;
    // 0x800F24AC: nop

    // 0x800F24B0: bc1f        L_800F24C0
    if (!c1cs) {
        // 0x800F24B4: nop
    
            goto L_800F24C0;
    }
    // 0x800F24B4: nop

L_800F24B8:
    // 0x800F24B8: j           L_800F2520
    // 0x800F24BC: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
        goto L_800F2520;
    // 0x800F24BC: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_800F24C0:
    // 0x800F24C0: jal         0x8001C5CC
    // 0x800F24C4: nop

    func_8001C5CC(rdram, ctx);
        goto after_4;
    // 0x800F24C4: nop

    after_4:
    // 0x800F24C8: addiu       $s0, $sp, 0x20
    ctx->r16 = ADD32(ctx->r29, 0X20);
    // 0x800F24CC: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x800F24D0: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    // 0x800F24D4: jal         0x80019548
    // 0x800F24D8: addiu       $a2, $sp, 0x10
    ctx->r6 = ADD32(ctx->r29, 0X10);
    func_80019548(rdram, ctx);
        goto after_5;
    // 0x800F24D8: addiu       $a2, $sp, 0x10
    ctx->r6 = ADD32(ctx->r29, 0X10);
    after_5:
    // 0x800F24DC: jal         0x8001CF2C
    // 0x800F24E0: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_8001CF2C(rdram, ctx);
        goto after_6;
    // 0x800F24E0: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_6:
    // 0x800F24E4: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x800F24E8: c.eq.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl == ctx->f2.fl;
    // 0x800F24EC: nop

    // 0x800F24F0: bc1t        L_800F2500
    if (c1cs) {
        // 0x800F24F4: nop
    
            goto L_800F2500;
    }
    // 0x800F24F4: nop

    // 0x800F24F8: jal         0x8001CF58
    // 0x800F24FC: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    normalize_vector(rdram, ctx);
        goto after_7;
    // 0x800F24FC: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_7:
L_800F2500:
    // 0x800F2500: lw          $v0, 0x6C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X6C);
    // 0x800F2504: lw          $v1, 0x20($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X20);
    // 0x800F2508: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x800F250C: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x800F2510: sw          $v1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r3;
    // 0x800F2514: sw          $t0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r8;
    // 0x800F2518: sw          $t1, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r9;
    // 0x800F251C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800F2520:
    // 0x800F2520: lw          $ra, 0x38($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X38);
    // 0x800F2524: lw          $s1, 0x34($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X34);
    // 0x800F2528: lw          $s0, 0x30($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X30);
    // 0x800F252C: ldc1        $f24, 0x50($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X50);
    // 0x800F2530: ldc1        $f22, 0x48($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X48);
    // 0x800F2534: ldc1        $f20, 0x40($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X40);
    // 0x800F2538: jr          $ra
    // 0x800F253C: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    return;
    // 0x800F253C: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
;}
RECOMP_FUNC void func_800F2540(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F2540: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x800F2544: sw          $s0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r16;
    // 0x800F2548: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x800F254C: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x800F2550: sw          $s2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r18;
    // 0x800F2554: sw          $s1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r17;
    // 0x800F2558: sdc1        $f22, 0x48($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X48, ctx->r29);
    // 0x800F255C: sdc1        $f20, 0x40($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X40, ctx->r29);
    // 0x800F2560: lwc1        $f0, 0x0($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0X0);
    // 0x800F2564: lwc1        $f2, 0x0($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X0);
    // 0x800F2568: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x800F256C: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    // 0x800F2570: lwc1        $f0, 0x4($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0X4);
    // 0x800F2574: lwc1        $f2, 0x4($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X4);
    // 0x800F2578: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x800F257C: addu        $s2, $a2, $zero
    ctx->r18 = ADD32(ctx->r6, 0);
    // 0x800F2580: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    // 0x800F2584: lwc1        $f0, 0x8($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0X8);
    // 0x800F2588: lwc1        $f2, 0x8($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X8);
    // 0x800F258C: addiu       $s0, $s0, 0xC
    ctx->r16 = ADD32(ctx->r16, 0XC);
    // 0x800F2590: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x800F2594: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x800F2598: addiu       $a1, $sp, 0x10
    ctx->r5 = ADD32(ctx->r29, 0X10);
    // 0x800F259C: jal         0x8001CFE8
    // 0x800F25A0: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    func_8001CFE8(rdram, ctx);
        goto after_0;
    // 0x800F25A0: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    after_0:
    // 0x800F25A4: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x800F25A8: jal         0x8001CF2C
    // 0x800F25AC: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
    func_8001CF2C(rdram, ctx);
        goto after_1;
    // 0x800F25AC: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
    after_1:
    // 0x800F25B0: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    // 0x800F25B4: jal         0x8001CF2C
    // 0x800F25B8: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    func_8001CF2C(rdram, ctx);
        goto after_2;
    // 0x800F25B8: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    after_2:
    // 0x800F25BC: mul.s       $f20, $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f20.fl = MUL_S(ctx->f20.fl, ctx->f0.fl);
    // 0x800F25C0: jal         0x8001C5CC
    // 0x800F25C4: div.s       $f12, $f22, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f12.fl = DIV_S(ctx->f22.fl, ctx->f20.fl);
    func_8001C5CC(rdram, ctx);
        goto after_3;
    // 0x800F25C4: div.s       $f12, $f22, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f12.fl = DIV_S(ctx->f22.fl, ctx->f20.fl);
    after_3:
    // 0x800F25C8: addiu       $s1, $sp, 0x20
    ctx->r17 = ADD32(ctx->r29, 0X20);
    // 0x800F25CC: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x800F25D0: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x800F25D4: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800F25D8: lwc1        $f2, -0x761C($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X761C);
    // 0x800F25DC: mul.s       $f20, $f0, $f2
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f20.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x800F25E0: jal         0x80019548
    // 0x800F25E4: addiu       $a2, $sp, 0x10
    ctx->r6 = ADD32(ctx->r29, 0X10);
    func_80019548(rdram, ctx);
        goto after_4;
    // 0x800F25E4: addiu       $a2, $sp, 0x10
    ctx->r6 = ADD32(ctx->r29, 0X10);
    after_4:
    // 0x800F25E8: jal         0x8001CF2C
    // 0x800F25EC: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    func_8001CF2C(rdram, ctx);
        goto after_5;
    // 0x800F25EC: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    after_5:
    // 0x800F25F0: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x800F25F4: c.eq.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl == ctx->f2.fl;
    // 0x800F25F8: nop

    // 0x800F25FC: bc1t        L_800F2610
    if (c1cs) {
        // 0x800F2600: mov.s       $f0, $f20
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    ctx->f0.fl = ctx->f20.fl;
            goto L_800F2610;
    }
    // 0x800F2600: mov.s       $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    ctx->f0.fl = ctx->f20.fl;
    // 0x800F2604: jal         0x8001CF58
    // 0x800F2608: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    normalize_vector(rdram, ctx);
        goto after_6;
    // 0x800F2608: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    after_6:
    // 0x800F260C: mov.s       $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    ctx->f0.fl = ctx->f20.fl;
L_800F2610:
    // 0x800F2610: lw          $v0, 0x20($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X20);
    // 0x800F2614: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x800F2618: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x800F261C: sw          $v0, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r2;
    // 0x800F2620: sw          $v1, 0x4($s2)
    MEM_W(0X4, ctx->r18) = ctx->r3;
    // 0x800F2624: sw          $a3, 0x8($s2)
    MEM_W(0X8, ctx->r18) = ctx->r7;
    // 0x800F2628: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x800F262C: lw          $s2, 0x38($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X38);
    // 0x800F2630: lw          $s1, 0x34($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X34);
    // 0x800F2634: lw          $s0, 0x30($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X30);
    // 0x800F2638: ldc1        $f22, 0x48($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X48);
    // 0x800F263C: ldc1        $f20, 0x40($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X40);
    // 0x800F2640: jr          $ra
    // 0x800F2644: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x800F2644: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}
RECOMP_FUNC void func_800F2648(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F2648: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x800F264C: sw          $s0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r16;
    // 0x800F2650: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x800F2654: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x800F2658: sw          $s2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r18;
    // 0x800F265C: sw          $s1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r17;
    // 0x800F2660: sdc1        $f22, 0x48($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X48, ctx->r29);
    // 0x800F2664: sdc1        $f20, 0x40($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X40, ctx->r29);
    // 0x800F2668: lwc1        $f0, 0x0($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0X0);
    // 0x800F266C: lwc1        $f2, 0x0($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X0);
    // 0x800F2670: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x800F2674: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    // 0x800F2678: lwc1        $f0, 0x4($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0X4);
    // 0x800F267C: lwc1        $f2, 0x4($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X4);
    // 0x800F2680: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x800F2684: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    // 0x800F2688: lwc1        $f0, 0x8($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0X8);
    // 0x800F268C: lwc1        $f2, 0x8($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X8);
    // 0x800F2690: addu        $s2, $a2, $zero
    ctx->r18 = ADD32(ctx->r6, 0);
    // 0x800F2694: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x800F2698: addu        $s1, $a3, $zero
    ctx->r17 = ADD32(ctx->r7, 0);
    // 0x800F269C: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    // 0x800F26A0: jal         0x8001CF2C
    // 0x800F26A4: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    func_8001CF2C(rdram, ctx);
        goto after_0;
    // 0x800F26A4: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    after_0:
    // 0x800F26A8: addiu       $s0, $s0, 0xC
    ctx->r16 = ADD32(ctx->r16, 0XC);
    // 0x800F26AC: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x800F26B0: addiu       $a1, $sp, 0x10
    ctx->r5 = ADD32(ctx->r29, 0X10);
    // 0x800F26B4: jal         0x8001CFE8
    // 0x800F26B8: swc1        $f0, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->f0.u32l;
    func_8001CFE8(rdram, ctx);
        goto after_1;
    // 0x800F26B8: swc1        $f0, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->f0.u32l;
    after_1:
    // 0x800F26BC: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x800F26C0: jal         0x8001CF2C
    // 0x800F26C4: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
    func_8001CF2C(rdram, ctx);
        goto after_2;
    // 0x800F26C4: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
    after_2:
    // 0x800F26C8: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    // 0x800F26CC: jal         0x8001CF2C
    // 0x800F26D0: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    func_8001CF2C(rdram, ctx);
        goto after_3;
    // 0x800F26D0: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    after_3:
    // 0x800F26D4: mul.s       $f20, $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f20.fl = MUL_S(ctx->f20.fl, ctx->f0.fl);
    // 0x800F26D8: jal         0x8001C5CC
    // 0x800F26DC: div.s       $f12, $f22, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f12.fl = DIV_S(ctx->f22.fl, ctx->f20.fl);
    func_8001C5CC(rdram, ctx);
        goto after_4;
    // 0x800F26DC: div.s       $f12, $f22, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f12.fl = DIV_S(ctx->f22.fl, ctx->f20.fl);
    after_4:
    // 0x800F26E0: addiu       $s1, $sp, 0x20
    ctx->r17 = ADD32(ctx->r29, 0X20);
    // 0x800F26E4: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x800F26E8: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x800F26EC: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800F26F0: lwc1        $f2, -0x7618($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X7618);
    // 0x800F26F4: mul.s       $f20, $f0, $f2
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f20.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x800F26F8: jal         0x80019548
    // 0x800F26FC: addiu       $a2, $sp, 0x10
    ctx->r6 = ADD32(ctx->r29, 0X10);
    func_80019548(rdram, ctx);
        goto after_5;
    // 0x800F26FC: addiu       $a2, $sp, 0x10
    ctx->r6 = ADD32(ctx->r29, 0X10);
    after_5:
    // 0x800F2700: jal         0x8001CF2C
    // 0x800F2704: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    func_8001CF2C(rdram, ctx);
        goto after_6;
    // 0x800F2704: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    after_6:
    // 0x800F2708: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x800F270C: c.eq.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl == ctx->f2.fl;
    // 0x800F2710: nop

    // 0x800F2714: bc1t        L_800F2728
    if (c1cs) {
        // 0x800F2718: mov.s       $f0, $f20
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    ctx->f0.fl = ctx->f20.fl;
            goto L_800F2728;
    }
    // 0x800F2718: mov.s       $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    ctx->f0.fl = ctx->f20.fl;
    // 0x800F271C: jal         0x8001CF58
    // 0x800F2720: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    normalize_vector(rdram, ctx);
        goto after_7;
    // 0x800F2720: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    after_7:
    // 0x800F2724: mov.s       $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    ctx->f0.fl = ctx->f20.fl;
L_800F2728:
    // 0x800F2728: lw          $v0, 0x20($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X20);
    // 0x800F272C: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x800F2730: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x800F2734: sw          $v0, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r2;
    // 0x800F2738: sw          $v1, 0x4($s2)
    MEM_W(0X4, ctx->r18) = ctx->r3;
    // 0x800F273C: sw          $t0, 0x8($s2)
    MEM_W(0X8, ctx->r18) = ctx->r8;
    // 0x800F2740: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x800F2744: lw          $s2, 0x38($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X38);
    // 0x800F2748: lw          $s1, 0x34($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X34);
    // 0x800F274C: lw          $s0, 0x30($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X30);
    // 0x800F2750: ldc1        $f22, 0x48($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X48);
    // 0x800F2754: ldc1        $f20, 0x40($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X40);
    // 0x800F2758: jr          $ra
    // 0x800F275C: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x800F275C: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}
RECOMP_FUNC void func_800F2760(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F2760: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x800F2764: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x800F2768: addu        $s3, $a0, $zero
    ctx->r19 = ADD32(ctx->r4, 0);
    // 0x800F276C: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x800F2770: addu        $s1, $zero, $zero
    ctx->r17 = ADD32(0, 0);
    // 0x800F2774: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x800F2778: addiu       $s2, $sp, 0x18
    ctx->r18 = ADD32(ctx->r29, 0X18);
    // 0x800F277C: sdc1        $f20, 0x38($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X38, ctx->r29);
    // 0x800F2780: mtc1        $a1, $f20
    ctx->f20.u32l = ctx->r5;
    // 0x800F2784: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x800F2788: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x800F278C: addiu       $s0, $v0, -0x72E8
    ctx->r16 = ADD32(ctx->r2, -0X72E8);
    // 0x800F2790: sw          $ra, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r31;
L_800F2794:
    // 0x800F2794: lbu         $v0, 0x0($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X0);
    // 0x800F2798: beq         $v0, $zero, L_800F27C0
    if (ctx->r2 == 0) {
        // 0x800F279C: addiu       $a0, $s0, 0x8
        ctx->r4 = ADD32(ctx->r16, 0X8);
            goto L_800F27C0;
    }
    // 0x800F279C: addiu       $a0, $s0, 0x8
    ctx->r4 = ADD32(ctx->r16, 0X8);
    // 0x800F27A0: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x800F27A4: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x800F27A8: addu        $a2, $s3, $zero
    ctx->r6 = ADD32(ctx->r19, 0);
    // 0x800F27AC: jal         0x8001DC34
    // 0x800F27B0: sw          $s2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r18;
    func_8001DC34(rdram, ctx);
        goto after_0;
    // 0x800F27B0: sw          $s2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r18;
    after_0:
    // 0x800F27B4: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x800F27B8: bne         $v0, $zero, L_800F27D0
    if (ctx->r2 != 0) {
        // 0x800F27BC: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_800F27D0;
    }
    // 0x800F27BC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800F27C0:
    // 0x800F27C0: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x800F27C4: blez        $s1, L_800F2794
    if (SIGNED(ctx->r17) <= 0) {
        // 0x800F27C8: addiu       $s0, $s0, 0x144
        ctx->r16 = ADD32(ctx->r16, 0X144);
            goto L_800F2794;
    }
    // 0x800F27C8: addiu       $s0, $s0, 0x144
    ctx->r16 = ADD32(ctx->r16, 0X144);
    // 0x800F27CC: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_800F27D0:
    // 0x800F27D0: lw          $ra, 0x30($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X30);
    // 0x800F27D4: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x800F27D8: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x800F27DC: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x800F27E0: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x800F27E4: ldc1        $f20, 0x38($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X38);
    // 0x800F27E8: jr          $ra
    // 0x800F27EC: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x800F27EC: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void func_800F27F0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F27F0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800F27F4: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x800F27F8: jal         0x8004013C
    // 0x800F27FC: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    func_8004013C(rdram, ctx);
        goto after_0;
    // 0x800F27FC: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    after_0:
    // 0x800F2800: lw          $v1, 0x10($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X10);
    // 0x800F2804: bne         $v1, $zero, L_800F2820
    if (ctx->r3 != 0) {
        // 0x800F2808: nop
    
            goto L_800F2820;
    }
    // 0x800F2808: nop

    // 0x800F280C: lbu         $v0, 0x15($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X15);
    // 0x800F2810: addiu       $v1, $zero, 0x3
    ctx->r3 = ADD32(0, 0X3);
    // 0x800F2814: srl         $v0, $v0, 6
    ctx->r2 = S32(U32(ctx->r2) >> 6);
    // 0x800F2818: j           L_800F2824
    // 0x800F281C: subu        $v0, $v1, $v0
    ctx->r2 = SUB32(ctx->r3, ctx->r2);
        goto L_800F2824;
    // 0x800F281C: subu        $v0, $v1, $v0
    ctx->r2 = SUB32(ctx->r3, ctx->r2);
L_800F2820:
    // 0x800F2820: lh          $v0, 0x19A($v1)
    ctx->r2 = MEM_H(ctx->r3, 0X19A);
L_800F2824:
    // 0x800F2824: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x800F2828: jr          $ra
    // 0x800F282C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x800F282C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_800F2830(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F2830: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800F2834: addu        $v0, $a0, $zero
    ctx->r2 = ADD32(ctx->r4, 0);
    // 0x800F2838: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800F283C: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x800F2840: lhu         $a0, 0x198($v0)
    ctx->r4 = MEM_HU(ctx->r2, 0X198);
    // 0x800F2844: addu        $s0, $a1, $zero
    ctx->r16 = ADD32(ctx->r5, 0);
    // 0x800F2848: jal         0x8004013C
    // 0x800F284C: sh          $s0, 0x19A($v0)
    MEM_H(0X19A, ctx->r2) = ctx->r16;
    func_8004013C(rdram, ctx);
        goto after_0;
    // 0x800F284C: sh          $s0, 0x19A($v0)
    MEM_H(0X19A, ctx->r2) = ctx->r16;
    after_0:
    // 0x800F2850: addiu       $v1, $zero, 0x3
    ctx->r3 = ADD32(0, 0X3);
    // 0x800F2854: subu        $v1, $v1, $s0
    ctx->r3 = SUB32(ctx->r3, ctx->r16);
    // 0x800F2858: lhu         $a0, 0x14($v0)
    ctx->r4 = MEM_HU(ctx->r2, 0X14);
    // 0x800F285C: sll         $v1, $v1, 6
    ctx->r3 = S32(ctx->r3 << 6);
    // 0x800F2860: andi        $a0, $a0, 0xFF3F
    ctx->r4 = ctx->r4 & 0XFF3F;
    // 0x800F2864: or          $a0, $a0, $v1
    ctx->r4 = ctx->r4 | ctx->r3;
    // 0x800F2868: sh          $a0, 0x14($v0)
    MEM_H(0X14, ctx->r2) = ctx->r4;
    // 0x800F286C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800F2870: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x800F2874: jr          $ra
    // 0x800F2878: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x800F2878: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_800F287C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F287C: lh          $v0, 0x19A($a0)
    ctx->r2 = MEM_H(ctx->r4, 0X19A);
    // 0x800F2880: jr          $ra
    // 0x800F2884: nop

    return;
    // 0x800F2884: nop

;}
RECOMP_FUNC void func_800F2888(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F2888: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x800F288C: sdc1        $f28, 0x38($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0X38, ctx->r29);
    // 0x800F2890: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800F2894: lwc1        $f28, -0x7614($at)
    ctx->f28.u32l = MEM_W(ctx->r1, -0X7614);
    // 0x800F2898: mtc1        $a1, $f4
    ctx->f4.u32l = ctx->r5;
    // 0x800F289C: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x800F28A0: mtc1        $a2, $f20
    ctx->f20.u32l = ctx->r6;
    // 0x800F28A4: sdc1        $f26, 0x30($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X30, ctx->r29);
    // 0x800F28A8: mtc1        $a3, $f26
    ctx->f26.u32l = ctx->r7;
    // 0x800F28AC: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x800F28B0: lwc1        $f22, 0x50($sp)
    ctx->f22.u32l = MEM_W(ctx->r29, 0X50);
    // 0x800F28B4: sdc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X28, ctx->r29);
    // 0x800F28B8: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800F28BC: lwc1        $f24, -0x7610($at)
    ctx->f24.u32l = MEM_W(ctx->r1, -0X7610);
    // 0x800F28C0: mul.s       $f12, $f4, $f28
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f12.fl = MUL_S(ctx->f4.fl, ctx->f28.fl);
    // 0x800F28C4: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x800F28C8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800F28CC: jal         0x8002B190
    // 0x800F28D0: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    cosf_recomp(rdram, ctx);
        goto after_0;
    // 0x800F28D0: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    after_0:
    // 0x800F28D4: mul.s       $f20, $f20, $f24
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f20.fl = MUL_S(ctx->f20.fl, ctx->f24.fl);
    // 0x800F28D8: nop

    // 0x800F28DC: mul.s       $f12, $f26, $f28
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f12.fl = MUL_S(ctx->f26.fl, ctx->f28.fl);
    // 0x800F28E0: swc1        $f0, 0x114($s0)
    MEM_W(0X114, ctx->r16) = ctx->f0.u32l;
    // 0x800F28E4: jal         0x8002B190
    // 0x800F28E8: swc1        $f20, 0x118($s0)
    MEM_W(0X118, ctx->r16) = ctx->f20.u32l;
    cosf_recomp(rdram, ctx);
        goto after_1;
    // 0x800F28E8: swc1        $f20, 0x118($s0)
    MEM_W(0X118, ctx->r16) = ctx->f20.u32l;
    after_1:
    // 0x800F28EC: mul.s       $f22, $f22, $f24
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f22.fl = MUL_S(ctx->f22.fl, ctx->f24.fl);
    // 0x800F28F0: swc1        $f0, 0x11C($s0)
    MEM_W(0X11C, ctx->r16) = ctx->f0.u32l;
    // 0x800F28F4: jal         0x80003430
    // 0x800F28F8: swc1        $f22, 0x120($s0)
    MEM_W(0X120, ctx->r16) = ctx->f22.u32l;
    rand_recomp(rdram, ctx);
        goto after_2;
    // 0x800F28F8: swc1        $f22, 0x120($s0)
    MEM_W(0X120, ctx->r16) = ctx->f22.u32l;
    after_2:
    // 0x800F28FC: lui         $v1, 0x8888
    ctx->r3 = S32(0X8888 << 16);
    // 0x800F2900: ori         $v1, $v1, 0x8889
    ctx->r3 = ctx->r3 | 0X8889;
    // 0x800F2904: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x800F2908: sra         $a0, $v0, 16
    ctx->r4 = S32(SIGNED(ctx->r2) >> 16);
    // 0x800F290C: mult        $a0, $v1
    result = S64(S32(ctx->r4)) * S64(S32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800F2910: sra         $v0, $v0, 31
    ctx->r2 = S32(SIGNED(ctx->r2) >> 31);
    // 0x800F2914: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800F2918: lwc1        $f2, -0x760C($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X760C);
    // 0x800F291C: mfhi        $t0
    ctx->r8 = hi;
    // 0x800F2920: addu        $v1, $t0, $a0
    ctx->r3 = ADD32(ctx->r8, ctx->r4);
    // 0x800F2924: sra         $v1, $v1, 4
    ctx->r3 = S32(SIGNED(ctx->r3) >> 4);
    // 0x800F2928: subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // 0x800F292C: sll         $v0, $v1, 4
    ctx->r2 = S32(ctx->r3 << 4);
    // 0x800F2930: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x800F2934: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x800F2938: subu        $a0, $a0, $v0
    ctx->r4 = SUB32(ctx->r4, ctx->r2);
    // 0x800F293C: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x800F2940: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    // 0x800F2944: mtc1        $a0, $f0
    ctx->f0.u32l = ctx->r4;
    // 0x800F2948: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x800F294C: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x800F2950: sb          $zero, 0x136($s0)
    MEM_B(0X136, ctx->r16) = 0;
    // 0x800F2954: sb          $zero, 0x137($s0)
    MEM_B(0X137, ctx->r16) = 0;
    // 0x800F2958: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800F295C: sb          $v0, 0x135($s0)
    MEM_B(0X135, ctx->r16) = ctx->r2;
    // 0x800F2960: swc1        $f0, 0x124($s0)
    MEM_W(0X124, ctx->r16) = ctx->f0.u32l;
    // 0x800F2964: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800F2968: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x800F296C: ldc1        $f28, 0x38($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0X38);
    // 0x800F2970: ldc1        $f26, 0x30($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X30);
    // 0x800F2974: ldc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X28);
    // 0x800F2978: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x800F297C: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x800F2980: jr          $ra
    // 0x800F2984: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x800F2984: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void func_800F2988(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F2988: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800F298C: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x800F2990: addu        $s1, $a1, $zero
    ctx->r17 = ADD32(ctx->r5, 0);
    // 0x800F2994: sw          $ra, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r31;
    // 0x800F2998: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x800F299C: lhu         $a0, 0x130($a0)
    ctx->r4 = MEM_HU(ctx->r4, 0X130);
    // 0x800F29A0: jal         0x8003FC28
    // 0x800F29A4: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    func_8003FC28(rdram, ctx);
        goto after_0;
    // 0x800F29A4: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    after_0:
    // 0x800F29A8: jal         0x8004013C
    // 0x800F29AC: andi        $a0, $v0, 0xFFFF
    ctx->r4 = ctx->r2 & 0XFFFF;
    func_8004013C(rdram, ctx);
        goto after_1;
    // 0x800F29AC: andi        $a0, $v0, 0xFFFF
    ctx->r4 = ctx->r2 & 0XFFFF;
    after_1:
    // 0x800F29B0: beq         $s1, $zero, L_800F29C4
    if (ctx->r17 == 0) {
        // 0x800F29B4: addu        $s0, $v0, $zero
        ctx->r16 = ADD32(ctx->r2, 0);
            goto L_800F29C4;
    }
    // 0x800F29B4: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    // 0x800F29B8: lw          $v0, 0xC($s0)
    ctx->r2 = MEM_W(ctx->r16, 0XC);
    // 0x800F29BC: bne         $v0, $zero, L_800F29D0
    if (ctx->r2 != 0) {
        // 0x800F29C0: addu        $a0, $s1, $zero
        ctx->r4 = ADD32(ctx->r17, 0);
            goto L_800F29D0;
    }
    // 0x800F29C0: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
L_800F29C4:
    // 0x800F29C4: lw          $v0, 0x8($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X8);
    // 0x800F29C8: j           L_800F29EC
    // 0x800F29CC: nop

        goto L_800F29EC;
    // 0x800F29CC: nop

L_800F29D0:
    // 0x800F29D0: lw          $a1, 0x8($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X8);
    // 0x800F29D4: jal         0x80018EF4
    // 0x800F29D8: addiu       $a2, $zero, 0x30
    ctx->r6 = ADD32(0, 0X30);
    zmemcpy(rdram, ctx);
        goto after_2;
    // 0x800F29D8: addiu       $a2, $zero, 0x30
    ctx->r6 = ADD32(0, 0X30);
    after_2:
    // 0x800F29DC: lw          $a0, 0xC($s0)
    ctx->r4 = MEM_W(ctx->r16, 0XC);
    // 0x800F29E0: jal         0x8006AC7C
    // 0x800F29E4: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    func_8006AC7C(rdram, ctx);
        goto after_3;
    // 0x800F29E4: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    after_3:
    // 0x800F29E8: addu        $v0, $s1, $zero
    ctx->r2 = ADD32(ctx->r17, 0);
L_800F29EC:
    // 0x800F29EC: lw          $ra, 0x18($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X18);
    // 0x800F29F0: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x800F29F4: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x800F29F8: jr          $ra
    // 0x800F29FC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x800F29FC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_800F2A00(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F2A00: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800F2A04: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x800F2A08: lhu         $a0, 0x130($a0)
    ctx->r4 = MEM_HU(ctx->r4, 0X130);
    // 0x800F2A0C: jal         0x8003FC28
    // 0x800F2A10: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    func_8003FC28(rdram, ctx);
        goto after_0;
    // 0x800F2A10: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    after_0:
    // 0x800F2A14: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x800F2A18: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x800F2A1C: jr          $ra
    // 0x800F2A20: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x800F2A20: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_800F2A24(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F2A24: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800F2A28: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x800F2A2C: addiu       $s0, $a0, 0x114
    ctx->r16 = ADD32(ctx->r4, 0X114);
    // 0x800F2A30: sw          $ra, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r31;
    // 0x800F2A34: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x800F2A38: lbu         $v1, 0x20($s0)
    ctx->r3 = MEM_BU(ctx->r16, 0X20);
    // 0x800F2A3C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800F2A40: bne         $v1, $v0, L_800F2A90
    if (ctx->r3 != ctx->r2) {
        // 0x800F2A44: ori         $s1, $zero, 0xFFFF
        ctx->r17 = 0 | 0XFFFF;
            goto L_800F2A90;
    }
    // 0x800F2A44: ori         $s1, $zero, 0xFFFF
    ctx->r17 = 0 | 0XFFFF;
    // 0x800F2A48: lhu         $v0, 0x1A($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X1A);
    // 0x800F2A4C: beq         $v0, $s1, L_800F2A90
    if (ctx->r2 == ctx->r17) {
        // 0x800F2A50: nop
    
            goto L_800F2A90;
    }
    // 0x800F2A50: nop

    // 0x800F2A54: lhu         $a0, 0x1C($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X1C);
    // 0x800F2A58: jal         0x8003FC28
    // 0x800F2A5C: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    func_8003FC28(rdram, ctx);
        goto after_0;
    // 0x800F2A5C: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    after_0:
    // 0x800F2A60: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x800F2A64: beql        $v0, $s1, L_800F2A88
    if (ctx->r2 == ctx->r17) {
        // 0x800F2A68: sh          $s1, 0x1A($s0)
        MEM_H(0X1A, ctx->r16) = ctx->r17;
            goto L_800F2A88;
    }
    goto skip_0;
    // 0x800F2A68: sh          $s1, 0x1A($s0)
    MEM_H(0X1A, ctx->r16) = ctx->r17;
    skip_0:
    // 0x800F2A6C: lhu         $a0, 0x1E($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X1E);
    // 0x800F2A70: jal         0x8004013C
    // 0x800F2A74: nop

    func_8004013C(rdram, ctx);
        goto after_1;
    // 0x800F2A74: nop

    after_1:
    // 0x800F2A78: lhu         $a0, 0x1E($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X1E);
    // 0x800F2A7C: jal         0x8003E7D0
    // 0x800F2A80: addu        $a1, $v0, $zero
    ctx->r5 = ADD32(ctx->r2, 0);
    func_8003E7D0(rdram, ctx);
        goto after_2;
    // 0x800F2A80: addu        $a1, $v0, $zero
    ctx->r5 = ADD32(ctx->r2, 0);
    after_2:
    // 0x800F2A84: sh          $s1, 0x1A($s0)
    MEM_H(0X1A, ctx->r16) = ctx->r17;
L_800F2A88:
    // 0x800F2A88: sh          $s1, 0x1E($s0)
    MEM_H(0X1E, ctx->r16) = ctx->r17;
    // 0x800F2A8C: sb          $zero, 0x20($s0)
    MEM_B(0X20, ctx->r16) = 0;
L_800F2A90:
    // 0x800F2A90: lw          $ra, 0x18($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X18);
    // 0x800F2A94: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x800F2A98: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x800F2A9C: jr          $ra
    // 0x800F2AA0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x800F2AA0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_800F2AA4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F2AA4: lhu         $v0, 0x14($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X14);
    // 0x800F2AA8: ori         $v0, $v0, 0x10
    ctx->r2 = ctx->r2 | 0X10;
    // 0x800F2AAC: jr          $ra
    // 0x800F2AB0: sh          $v0, 0x14($a0)
    MEM_H(0X14, ctx->r4) = ctx->r2;
    return;
    // 0x800F2AB0: sh          $v0, 0x14($a0)
    MEM_H(0X14, ctx->r4) = ctx->r2;
;}
RECOMP_FUNC void func_800F2AB4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F2AB4: lhu         $v0, 0x14($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X14);
    // 0x800F2AB8: andi        $v0, $v0, 0xFFEF
    ctx->r2 = ctx->r2 & 0XFFEF;
    // 0x800F2ABC: jr          $ra
    // 0x800F2AC0: sh          $v0, 0x14($a0)
    MEM_H(0X14, ctx->r4) = ctx->r2;
    return;
    // 0x800F2AC0: sh          $v0, 0x14($a0)
    MEM_H(0X14, ctx->r4) = ctx->r2;
;}
RECOMP_FUNC void func_800F2AC4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F2AC4: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x800F2AC8: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x800F2ACC: addu        $s0, $a1, $zero
    ctx->r16 = ADD32(ctx->r5, 0);
    // 0x800F2AD0: sw          $ra, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r31;
    // 0x800F2AD4: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x800F2AD8: sdc1        $f20, 0x30($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X30, ctx->r29);
    // 0x800F2ADC: lwc1        $f0, 0x0($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X0);
    // 0x800F2AE0: lwc1        $f2, 0x0($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X0);
    // 0x800F2AE4: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x800F2AE8: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    // 0x800F2AEC: lwc1        $f0, 0x4($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X4);
    // 0x800F2AF0: lwc1        $f2, 0x4($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X4);
    // 0x800F2AF4: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x800F2AF8: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    // 0x800F2AFC: lwc1        $f0, 0x8($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X8);
    // 0x800F2B00: lwc1        $f2, 0x8($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X8);
    // 0x800F2B04: addu        $s1, $a3, $zero
    ctx->r17 = ADD32(ctx->r7, 0);
    // 0x800F2B08: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x800F2B0C: mtc1        $a2, $f20
    ctx->f20.u32l = ctx->r6;
    // 0x800F2B10: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    // 0x800F2B14: jal         0x8001CF2C
    // 0x800F2B18: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    func_8001CF2C(rdram, ctx);
        goto after_0;
    // 0x800F2B18: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    after_0:
    // 0x800F2B1C: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x800F2B20: mov.s       $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    ctx->f4.fl = ctx->f2.fl;
    // 0x800F2B24: c.lt.s      $f4, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f4.fl < ctx->f20.fl;
    // 0x800F2B28: nop

    // 0x800F2B2C: bc1tl       L_800F2B34
    if (c1cs) {
        // 0x800F2B30: div.s       $f4, $f0, $f20
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = DIV_S(ctx->f0.fl, ctx->f20.fl);
            goto L_800F2B34;
    }
    goto skip_0;
    // 0x800F2B30: div.s       $f4, $f0, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = DIV_S(ctx->f0.fl, ctx->f20.fl);
    skip_0:
L_800F2B34:
    // 0x800F2B34: lwc1        $f2, 0x24($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X24);
    // 0x800F2B38: mul.s       $f2, $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f4.fl);
    // 0x800F2B3C: lwc1        $f0, 0x0($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X0);
    // 0x800F2B40: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x800F2B44: swc1        $f0, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->f0.u32l;
    // 0x800F2B48: lwc1        $f2, 0x28($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X28);
    // 0x800F2B4C: mul.s       $f2, $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f4.fl);
    // 0x800F2B50: lwc1        $f0, 0x4($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X4);
    // 0x800F2B54: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x800F2B58: swc1        $f0, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->f0.u32l;
    // 0x800F2B5C: lwc1        $f2, 0x2C($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x800F2B60: mul.s       $f2, $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f4.fl);
    // 0x800F2B64: lwc1        $f0, 0x8($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X8);
    // 0x800F2B68: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x800F2B6C: swc1        $f0, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->f0.u32l;
    // 0x800F2B70: lw          $ra, 0x28($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X28);
    // 0x800F2B74: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x800F2B78: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x800F2B7C: ldc1        $f20, 0x30($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X30);
    // 0x800F2B80: jr          $ra
    // 0x800F2B84: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x800F2B84: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_800F2B88(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F2B88: mtc1        $a1, $f0
    ctx->f0.u32l = ctx->r5;
    // 0x800F2B8C: mtc1        $a2, $f2
    ctx->f2.u32l = ctx->r6;
    // 0x800F2B90: lw          $v0, 0x18($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X18);
    // 0x800F2B94: mtc1        $a3, $f4
    ctx->f4.u32l = ctx->r7;
    // 0x800F2B98: bnel        $v0, $zero, L_800F2BA4
    if (ctx->r2 != 0) {
        // 0x800F2B9C: addiu       $a0, $a0, 0x164
        ctx->r4 = ADD32(ctx->r4, 0X164);
            goto L_800F2BA4;
    }
    goto skip_0;
    // 0x800F2B9C: addiu       $a0, $a0, 0x164
    ctx->r4 = ADD32(ctx->r4, 0X164);
    skip_0:
    // 0x800F2BA0: addiu       $a0, $a0, 0x138
    ctx->r4 = ADD32(ctx->r4, 0X138);
L_800F2BA4:
    // 0x800F2BA4: trunc.w.s   $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    ctx->f10.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x800F2BA8: mfc1        $a3, $f10
    ctx->r7 = (int32_t)ctx->f10.u32l;
    // 0x800F2BAC: lwc1        $f8, 0x24($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X24);
    // 0x800F2BB0: sll         $v0, $a3, 16
    ctx->r2 = S32(ctx->r7 << 16);
    // 0x800F2BB4: swc1        $f0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f0.u32l;
    // 0x800F2BB8: swc1        $f2, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f2.u32l;
    // 0x800F2BBC: bne         $v0, $zero, L_800F2BCC
    if (ctx->r2 != 0) {
        // 0x800F2BC0: sh          $a3, 0x1C($a0)
        MEM_H(0X1C, ctx->r4) = ctx->r7;
            goto L_800F2BCC;
    }
    // 0x800F2BC0: sh          $a3, 0x1C($a0)
    MEM_H(0X1C, ctx->r4) = ctx->r7;
    // 0x800F2BC4: addiu       $v0, $a3, 0x1
    ctx->r2 = ADD32(ctx->r7, 0X1);
    // 0x800F2BC8: sh          $v0, 0x1C($a0)
    MEM_H(0X1C, ctx->r4) = ctx->r2;
L_800F2BCC:
    // 0x800F2BCC: lwc1        $f0, 0x10($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X10);
    // 0x800F2BD0: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800F2BD4: lwc1        $f6, -0x7608($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X7608);
    // 0x800F2BD8: swc1        $f0, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f0.u32l;
    // 0x800F2BDC: lw          $v0, 0x14($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X14);
    // 0x800F2BE0: sw          $zero, 0xC($a0)
    MEM_W(0XC, ctx->r4) = 0;
    // 0x800F2BE4: sw          $v0, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->r2;
    // 0x800F2BE8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800F2BEC: sb          $v0, 0x2B($a0)
    MEM_B(0X2B, ctx->r4) = ctx->r2;
    // 0x800F2BF0: lwc1        $f2, 0x20($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X20);
    // 0x800F2BF4: sh          $zero, 0x1E($a0)
    MEM_H(0X1E, ctx->r4) = 0;
    // 0x800F2BF8: mul.s       $f2, $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f6.fl);
    // 0x800F2BFC: sw          $zero, 0x10($a0)
    MEM_W(0X10, ctx->r4) = 0;
    // 0x800F2C00: sb          $zero, 0x28($a0)
    MEM_B(0X28, ctx->r4) = 0;
    // 0x800F2C04: lwc1        $f0, 0x1C($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x800F2C08: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800F2C0C: lwc1        $f4, -0x7604($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X7604);
    // 0x800F2C10: mul.s       $f0, $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x800F2C14: trunc.w.s   $f10, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    ctx->f10.u32l = TRUNC_W_S(ctx->f2.fl);
    // 0x800F2C18: mfc1        $v0, $f10
    ctx->r2 = (int32_t)ctx->f10.u32l;
    // 0x800F2C1C: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800F2C20: lwc1        $f2, -0x7600($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X7600);
    // 0x800F2C24: swc1        $f4, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->f4.u32l;
    // 0x800F2C28: sh          $v0, 0x24($a0)
    MEM_H(0X24, ctx->r4) = ctx->r2;
    // 0x800F2C2C: trunc.w.s   $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    ctx->f10.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800F2C30: mfc1        $v0, $f10
    ctx->r2 = (int32_t)ctx->f10.u32l;
    // 0x800F2C34: c.lt.s      $f2, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f2.fl < ctx->f8.fl;
    // 0x800F2C38: nop

    // 0x800F2C3C: bc1f        L_800F2C48
    if (!c1cs) {
        // 0x800F2C40: sh          $v0, 0x26($a0)
        MEM_H(0X26, ctx->r4) = ctx->r2;
            goto L_800F2C48;
    }
    // 0x800F2C40: sh          $v0, 0x26($a0)
    MEM_H(0X26, ctx->r4) = ctx->r2;
    // 0x800F2C44: mov.s       $f8, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    ctx->f8.fl = ctx->f2.fl;
L_800F2C48:
    // 0x800F2C48: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800F2C4C: lwc1        $f0, -0x75FC($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X75FC);
    // 0x800F2C50: mul.s       $f0, $f8, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x800F2C54: sb          $zero, 0x29($a0)
    MEM_B(0X29, ctx->r4) = 0;
    // 0x800F2C58: sw          $zero, 0x20($a0)
    MEM_W(0X20, ctx->r4) = 0;
    // 0x800F2C5C: trunc.w.s   $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    ctx->f10.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800F2C60: mfc1        $v0, $f10
    ctx->r2 = (int32_t)ctx->f10.u32l;
    // 0x800F2C64: jr          $ra
    // 0x800F2C68: sb          $v0, 0x2A($a0)
    MEM_B(0X2A, ctx->r4) = ctx->r2;
    return;
    // 0x800F2C68: sb          $v0, 0x2A($a0)
    MEM_B(0X2A, ctx->r4) = ctx->r2;
;}
RECOMP_FUNC void func_800F2C6C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F2C6C: lwc1        $f8, 0x20($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X20);
    // 0x800F2C70: mtc1        $a3, $f10
    ctx->f10.u32l = ctx->r7;
    // 0x800F2C74: sw          $a1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r5;
    // 0x800F2C78: sw          $a2, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r6;
    // 0x800F2C7C: trunc.w.s   $f10, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    ctx->f10.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x800F2C80: mfc1        $a3, $f10
    ctx->r7 = (int32_t)ctx->f10.u32l;
    // 0x800F2C84: sll         $v0, $a3, 16
    ctx->r2 = S32(ctx->r7 << 16);
    // 0x800F2C88: bne         $v0, $zero, L_800F2C98
    if (ctx->r2 != 0) {
        // 0x800F2C8C: sh          $a3, 0x1C($a0)
        MEM_H(0X1C, ctx->r4) = ctx->r7;
            goto L_800F2C98;
    }
    // 0x800F2C8C: sh          $a3, 0x1C($a0)
    MEM_H(0X1C, ctx->r4) = ctx->r7;
    // 0x800F2C90: addiu       $v0, $a3, 0x1
    ctx->r2 = ADD32(ctx->r7, 0X1);
    // 0x800F2C94: sh          $v0, 0x1C($a0)
    MEM_H(0X1C, ctx->r4) = ctx->r2;
L_800F2C98:
    // 0x800F2C98: lwc1        $f0, 0x10($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X10);
    // 0x800F2C9C: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800F2CA0: lwc1        $f6, -0x75F8($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X75F8);
    // 0x800F2CA4: swc1        $f0, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f0.u32l;
    // 0x800F2CA8: lw          $v0, 0x14($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X14);
    // 0x800F2CAC: sw          $zero, 0xC($a0)
    MEM_W(0XC, ctx->r4) = 0;
    // 0x800F2CB0: sw          $v0, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->r2;
    // 0x800F2CB4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800F2CB8: sb          $v0, 0x2B($a0)
    MEM_B(0X2B, ctx->r4) = ctx->r2;
    // 0x800F2CBC: lwc1        $f2, 0x1C($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x800F2CC0: sh          $zero, 0x1E($a0)
    MEM_H(0X1E, ctx->r4) = 0;
    // 0x800F2CC4: mul.s       $f2, $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f6.fl);
    // 0x800F2CC8: sw          $zero, 0x10($a0)
    MEM_W(0X10, ctx->r4) = 0;
    // 0x800F2CCC: sb          $zero, 0x28($a0)
    MEM_B(0X28, ctx->r4) = 0;
    // 0x800F2CD0: lwc1        $f0, 0x18($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X18);
    // 0x800F2CD4: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800F2CD8: lwc1        $f4, -0x75F4($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X75F4);
    // 0x800F2CDC: mul.s       $f0, $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x800F2CE0: trunc.w.s   $f10, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    ctx->f10.u32l = TRUNC_W_S(ctx->f2.fl);
    // 0x800F2CE4: mfc1        $v0, $f10
    ctx->r2 = (int32_t)ctx->f10.u32l;
    // 0x800F2CE8: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800F2CEC: lwc1        $f2, -0x75F0($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X75F0);
    // 0x800F2CF0: swc1        $f4, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->f4.u32l;
    // 0x800F2CF4: sh          $v0, 0x24($a0)
    MEM_H(0X24, ctx->r4) = ctx->r2;
    // 0x800F2CF8: trunc.w.s   $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    ctx->f10.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800F2CFC: mfc1        $v0, $f10
    ctx->r2 = (int32_t)ctx->f10.u32l;
    // 0x800F2D00: c.lt.s      $f2, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f2.fl < ctx->f8.fl;
    // 0x800F2D04: nop

    // 0x800F2D08: bc1f        L_800F2D14
    if (!c1cs) {
        // 0x800F2D0C: sh          $v0, 0x26($a0)
        MEM_H(0X26, ctx->r4) = ctx->r2;
            goto L_800F2D14;
    }
    // 0x800F2D0C: sh          $v0, 0x26($a0)
    MEM_H(0X26, ctx->r4) = ctx->r2;
    // 0x800F2D10: mov.s       $f8, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    ctx->f8.fl = ctx->f2.fl;
L_800F2D14:
    // 0x800F2D14: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800F2D18: lwc1        $f0, -0x75EC($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X75EC);
    // 0x800F2D1C: mul.s       $f0, $f8, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x800F2D20: sb          $zero, 0x29($a0)
    MEM_B(0X29, ctx->r4) = 0;
    // 0x800F2D24: sw          $zero, 0x20($a0)
    MEM_W(0X20, ctx->r4) = 0;
    // 0x800F2D28: trunc.w.s   $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    ctx->f10.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800F2D2C: mfc1        $v0, $f10
    ctx->r2 = (int32_t)ctx->f10.u32l;
    // 0x800F2D30: jr          $ra
    // 0x800F2D34: sb          $v0, 0x2A($a0)
    MEM_B(0X2A, ctx->r4) = ctx->r2;
    return;
    // 0x800F2D34: sb          $v0, 0x2A($a0)
    MEM_B(0X2A, ctx->r4) = ctx->r2;
;}
RECOMP_FUNC void func_800F2D38(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F2D38: mtc1        $a1, $f0
    ctx->f0.u32l = ctx->r5;
    // 0x800F2D3C: mtc1        $a2, $f2
    ctx->f2.u32l = ctx->r6;
    // 0x800F2D40: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800F2D44: bne         $a3, $zero, L_800F2D54
    if (ctx->r7 != 0) {
        // 0x800F2D48: sw          $ra, 0x10($sp)
        MEM_W(0X10, ctx->r29) = ctx->r31;
            goto L_800F2D54;
    }
    // 0x800F2D48: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x800F2D4C: j           L_800F2D58
    // 0x800F2D50: addiu       $a1, $a0, 0x138
    ctx->r5 = ADD32(ctx->r4, 0X138);
        goto L_800F2D58;
    // 0x800F2D50: addiu       $a1, $a0, 0x138
    ctx->r5 = ADD32(ctx->r4, 0X138);
L_800F2D54:
    // 0x800F2D54: addiu       $a1, $a0, 0x164
    ctx->r5 = ADD32(ctx->r4, 0X164);
L_800F2D58:
    // 0x800F2D58: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x800F2D5C: mfc1        $a3, $f2
    ctx->r7 = (int32_t)ctx->f2.u32l;
    // 0x800F2D60: jal         0x800F0DC4
    // 0x800F2D64: nop

    func_800F0DC4(rdram, ctx);
        goto after_0;
    // 0x800F2D64: nop

    after_0:
    // 0x800F2D68: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x800F2D6C: jr          $ra
    // 0x800F2D70: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x800F2D70: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_800F2D74(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F2D74: mtc1        $a1, $f0
    ctx->f0.u32l = ctx->r5;
    // 0x800F2D78: bnel        $a2, $zero, L_800F2D84
    if (ctx->r6 != 0) {
        // 0x800F2D7C: addiu       $a0, $a0, 0x164
        ctx->r4 = ADD32(ctx->r4, 0X164);
            goto L_800F2D84;
    }
    goto skip_0;
    // 0x800F2D7C: addiu       $a0, $a0, 0x164
    ctx->r4 = ADD32(ctx->r4, 0X164);
    skip_0:
    // 0x800F2D80: addiu       $a0, $a0, 0x138
    ctx->r4 = ADD32(ctx->r4, 0X138);
L_800F2D84:
    // 0x800F2D84: lw          $v0, 0x18($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X18);
    // 0x800F2D88: beq         $v0, $zero, L_800F2D9C
    if (ctx->r2 == 0) {
        // 0x800F2D8C: nop
    
            goto L_800F2D9C;
    }
    // 0x800F2D8C: nop

    // 0x800F2D90: lbu         $v0, 0x2B($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X2B);
    // 0x800F2D94: bnel        $v0, $zero, L_800F2D9C
    if (ctx->r2 != 0) {
        // 0x800F2D98: swc1        $f0, 0x10($a0)
        MEM_W(0X10, ctx->r4) = ctx->f0.u32l;
            goto L_800F2D9C;
    }
    goto skip_1;
    // 0x800F2D98: swc1        $f0, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->f0.u32l;
    skip_1:
L_800F2D9C:
    // 0x800F2D9C: jr          $ra
    // 0x800F2DA0: nop

    return;
    // 0x800F2DA0: nop

;}
RECOMP_FUNC void func_800F2DA4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F2DA4: lw          $v0, 0x18($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X18);
    // 0x800F2DA8: mtc1        $a1, $f0
    ctx->f0.u32l = ctx->r5;
    // 0x800F2DAC: beq         $v0, $zero, L_800F2DC0
    if (ctx->r2 == 0) {
        // 0x800F2DB0: nop
    
            goto L_800F2DC0;
    }
    // 0x800F2DB0: nop

    // 0x800F2DB4: lbu         $v0, 0x2B($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X2B);
    // 0x800F2DB8: bnel        $v0, $zero, L_800F2DC0
    if (ctx->r2 != 0) {
        // 0x800F2DBC: swc1        $f0, 0x10($a0)
        MEM_W(0X10, ctx->r4) = ctx->f0.u32l;
            goto L_800F2DC0;
    }
    goto skip_0;
    // 0x800F2DBC: swc1        $f0, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->f0.u32l;
    skip_0:
L_800F2DC0:
    // 0x800F2DC0: jr          $ra
    // 0x800F2DC4: nop

    return;
    // 0x800F2DC4: nop

;}
RECOMP_FUNC void func_800F2DC8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F2DC8: addiu       $sp, $sp, -0x78
    ctx->r29 = ADD32(ctx->r29, -0X78);
    // 0x800F2DCC: sw          $s1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r17;
    // 0x800F2DD0: addu        $s1, $a0, $zero
    ctx->r17 = ADD32(ctx->r4, 0);
    // 0x800F2DD4: addu        $v1, $a1, $zero
    ctx->r3 = ADD32(ctx->r5, 0);
    // 0x800F2DD8: sw          $ra, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r31;
    // 0x800F2DDC: sw          $s3, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r19;
    // 0x800F2DE0: sw          $s2, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r18;
    // 0x800F2DE4: sw          $s0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r16;
    // 0x800F2DE8: sdc1        $f22, 0x70($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X70, ctx->r29);
    // 0x800F2DEC: sdc1        $f20, 0x68($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X68, ctx->r29);
    // 0x800F2DF0: lb          $v0, 0x162($s1)
    ctx->r2 = MEM_B(ctx->r17, 0X162);
    // 0x800F2DF4: beq         $v0, $zero, L_800F2EEC
    if (ctx->r2 == 0) {
        // 0x800F2DF8: addu        $s0, $a2, $zero
        ctx->r16 = ADD32(ctx->r6, 0);
            goto L_800F2EEC;
    }
    // 0x800F2DF8: addu        $s0, $a2, $zero
    ctx->r16 = ADD32(ctx->r6, 0);
    // 0x800F2DFC: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    // 0x800F2E00: addiu       $s2, $v1, 0x18
    ctx->r18 = ADD32(ctx->r3, 0X18);
    // 0x800F2E04: addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    // 0x800F2E08: addiu       $s3, $v1, 0xC
    ctx->r19 = ADD32(ctx->r3, 0XC);
    // 0x800F2E0C: jal         0x80019548
    // 0x800F2E10: addu        $a2, $s3, $zero
    ctx->r6 = ADD32(ctx->r19, 0);
    func_80019548(rdram, ctx);
        goto after_0;
    // 0x800F2E10: addu        $a2, $s3, $zero
    ctx->r6 = ADD32(ctx->r19, 0);
    after_0:
    // 0x800F2E14: andi        $v0, $s0, 0xFF
    ctx->r2 = ctx->r16 & 0XFF;
    // 0x800F2E18: bnel        $v0, $zero, L_800F2E8C
    if (ctx->r2 != 0) {
        // 0x800F2E1C: addiu       $s1, $sp, 0x30
        ctx->r17 = ADD32(ctx->r29, 0X30);
            goto L_800F2E8C;
    }
    goto skip_0;
    // 0x800F2E1C: addiu       $s1, $sp, 0x30
    ctx->r17 = ADD32(ctx->r29, 0X30);
    skip_0:
    // 0x800F2E20: lb          $v0, 0x162($s1)
    ctx->r2 = MEM_B(ctx->r17, 0X162);
    // 0x800F2E24: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800F2E28: lwc1        $f0, -0x75E8($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X75E8);
    // 0x800F2E2C: mtc1        $v0, $f20
    ctx->f20.u32l = ctx->r2;
    // 0x800F2E30: cvt.s.w     $f20, $f20
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    ctx->f20.fl = CVT_S_W(ctx->f20.u32l);
    // 0x800F2E34: mul.s       $f20, $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f20.fl = MUL_S(ctx->f20.fl, ctx->f0.fl);
    // 0x800F2E38: jal         0x80003430
    // 0x800F2E3C: nop

    rand_recomp(rdram, ctx);
        goto after_1;
    // 0x800F2E3C: nop

    after_1:
    // 0x800F2E40: andi        $v0, $v0, 0x7F
    ctx->r2 = ctx->r2 & 0X7F;
    // 0x800F2E44: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800F2E48: lwc1        $f22, -0x75E4($at)
    ctx->f22.u32l = MEM_W(ctx->r1, -0X75E4);
    // 0x800F2E4C: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x800F2E50: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x800F2E54: sub.s       $f0, $f0, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f22.fl;
    // 0x800F2E58: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800F2E5C: div.s       $f20, $f22, $f20
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f20.fl = DIV_S(ctx->f22.fl, ctx->f20.fl);
    // 0x800F2E60: div.s       $f0, $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f20.fl);
    // 0x800F2E64: jal         0x80003430
    // 0x800F2E68: swc1        $f0, -0x3B90($v0)
    MEM_W(-0X3B90, ctx->r2) = ctx->f0.u32l;
    rand_recomp(rdram, ctx);
        goto after_2;
    // 0x800F2E68: swc1        $f0, -0x3B90($v0)
    MEM_W(-0X3B90, ctx->r2) = ctx->f0.u32l;
    after_2:
    // 0x800F2E6C: andi        $v0, $v0, 0x7F
    ctx->r2 = ctx->r2 & 0X7F;
    // 0x800F2E70: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x800F2E74: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x800F2E78: sub.s       $f0, $f0, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f22.fl;
    // 0x800F2E7C: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800F2E80: div.s       $f0, $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f20.fl);
    // 0x800F2E84: swc1        $f0, -0x3B8C($v0)
    MEM_W(-0X3B8C, ctx->r2) = ctx->f0.u32l;
    // 0x800F2E88: addiu       $s1, $sp, 0x30
    ctx->r17 = ADD32(ctx->r29, 0X30);
L_800F2E8C:
    // 0x800F2E8C: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x800F2E90: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800F2E94: lw          $a2, -0x3B90($v0)
    ctx->r6 = MEM_W(ctx->r2, -0X3B90);
    // 0x800F2E98: jal         0x8001D240
    // 0x800F2E9C: addiu       $a1, $sp, 0x10
    ctx->r5 = ADD32(ctx->r29, 0X10);
    func_8001D240(rdram, ctx);
        goto after_3;
    // 0x800F2E9C: addiu       $a1, $sp, 0x10
    ctx->r5 = ADD32(ctx->r29, 0X10);
    after_3:
    // 0x800F2EA0: addiu       $s0, $sp, 0x40
    ctx->r16 = ADD32(ctx->r29, 0X40);
    // 0x800F2EA4: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x800F2EA8: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800F2EAC: lw          $a2, -0x3B8C($v0)
    ctx->r6 = MEM_W(ctx->r2, -0X3B8C);
    // 0x800F2EB0: jal         0x8001D240
    // 0x800F2EB4: addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    func_8001D240(rdram, ctx);
        goto after_4;
    // 0x800F2EB4: addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    after_4:
    // 0x800F2EB8: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x800F2EBC: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    // 0x800F2EC0: addiu       $s0, $sp, 0x20
    ctx->r16 = ADD32(ctx->r29, 0X20);
    // 0x800F2EC4: jal         0x8001D2C0
    // 0x800F2EC8: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    func_8001D2C0(rdram, ctx);
        goto after_5;
    // 0x800F2EC8: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    after_5:
    // 0x800F2ECC: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x800F2ED0: addu        $a1, $s3, $zero
    ctx->r5 = ADD32(ctx->r19, 0);
    // 0x800F2ED4: jal         0x8001D3C4
    // 0x800F2ED8: addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    func_8001D3C4(rdram, ctx);
        goto after_6;
    // 0x800F2ED8: addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    after_6:
    // 0x800F2EDC: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x800F2EE0: addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    // 0x800F2EE4: jal         0x8001D3C4
    // 0x800F2EE8: addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    func_8001D3C4(rdram, ctx);
        goto after_7;
    // 0x800F2EE8: addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    after_7:
L_800F2EEC:
    // 0x800F2EEC: lw          $ra, 0x60($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X60);
    // 0x800F2EF0: lw          $s3, 0x5C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X5C);
    // 0x800F2EF4: lw          $s2, 0x58($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X58);
    // 0x800F2EF8: lw          $s1, 0x54($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X54);
    // 0x800F2EFC: lw          $s0, 0x50($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X50);
    // 0x800F2F00: ldc1        $f22, 0x70($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X70);
    // 0x800F2F04: ldc1        $f20, 0x68($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X68);
    // 0x800F2F08: jr          $ra
    // 0x800F2F0C: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
    return;
    // 0x800F2F0C: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
;}
RECOMP_FUNC void func_800F2F10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F2F10: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x800F2F14: sw          $s0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r16;
    // 0x800F2F18: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x800F2F1C: sdc1        $f20, 0x50($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X50, ctx->r29);
    // 0x800F2F20: mtc1        $a2, $f20
    ctx->f20.u32l = ctx->r6;
    // 0x800F2F24: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    // 0x800F2F28: sw          $s2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r18;
    // 0x800F2F2C: lw          $s2, 0x68($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X68);
    // 0x800F2F30: addiu       $a2, $zero, 0x30
    ctx->r6 = ADD32(0, 0X30);
    // 0x800F2F34: sw          $s1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r17;
    // 0x800F2F38: sw          $ra, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r31;
    // 0x800F2F3C: jal         0x80018EF4
    // 0x800F2F40: addu        $s1, $a3, $zero
    ctx->r17 = ADD32(ctx->r7, 0);
    zmemcpy(rdram, ctx);
        goto after_0;
    // 0x800F2F40: addu        $s1, $a3, $zero
    ctx->r17 = ADD32(ctx->r7, 0);
    after_0:
    // 0x800F2F44: lwc1        $f0, 0x1C($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x800F2F48: mul.s       $f0, $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f20.fl);
    // 0x800F2F4C: lwc1        $f4, 0x20($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X20);
    // 0x800F2F50: mul.s       $f4, $f4, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = MUL_S(ctx->f4.fl, ctx->f20.fl);
    // 0x800F2F54: lwc1        $f8, 0x24($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X24);
    // 0x800F2F58: mul.s       $f8, $f8, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = MUL_S(ctx->f8.fl, ctx->f20.fl);
    // 0x800F2F5C: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x800F2F60: lwc1        $f6, 0x10($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X10);
    // 0x800F2F64: addiu       $a1, $sp, 0x10
    ctx->r5 = ADD32(ctx->r29, 0X10);
    // 0x800F2F68: add.s       $f6, $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f0.fl;
    // 0x800F2F6C: lwc1        $f2, 0x14($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X14);
    // 0x800F2F70: addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    // 0x800F2F74: add.s       $f2, $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f4.fl;
    // 0x800F2F78: lwc1        $f0, 0x18($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X18);
    // 0x800F2F7C: addu        $a3, $s2, $zero
    ctx->r7 = ADD32(ctx->r18, 0);
    // 0x800F2F80: add.s       $f0, $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f8.fl;
    // 0x800F2F84: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    // 0x800F2F88: swc1        $f2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f2.u32l;
    // 0x800F2F8C: jal         0x800F1870
    // 0x800F2F90: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    func_800F1870(rdram, ctx);
        goto after_1;
    // 0x800F2F90: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    after_1:
    // 0x800F2F94: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
    // 0x800F2F98: lw          $s2, 0x48($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X48);
    // 0x800F2F9C: lw          $s1, 0x44($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X44);
    // 0x800F2FA0: lw          $s0, 0x40($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X40);
    // 0x800F2FA4: ldc1        $f20, 0x50($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X50);
    // 0x800F2FA8: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x800F2FAC: jr          $ra
    // 0x800F2FB0: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    return;
    // 0x800F2FB0: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
;}
RECOMP_FUNC void func_800F2FB4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F2FB4: lwc1        $f0, 0x14C($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X14C);
    // 0x800F2FB8: jr          $ra
    // 0x800F2FBC: nop

    return;
    // 0x800F2FBC: nop

;}
RECOMP_FUNC void func_800F2FC0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F2FC0: sw          $a1, 0x14C($a0)
    MEM_W(0X14C, ctx->r4) = ctx->r5;
    // 0x800F2FC4: jr          $ra
    // 0x800F2FC8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x800F2FC8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
;}
RECOMP_FUNC void func_800F2FCC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F2FCC: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x800F2FD0: sdc1        $f20, 0x58($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X58, ctx->r29);
    // 0x800F2FD4: lwc1        $f20, 0x7C($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X7C);
    // 0x800F2FD8: sdc1        $f22, 0x60($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X60, ctx->r29);
    // 0x800F2FDC: lwc1        $f22, 0x80($sp)
    ctx->f22.u32l = MEM_W(ctx->r29, 0X80);
    // 0x800F2FE0: sw          $s1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r17;
    // 0x800F2FE4: addu        $s1, $a0, $zero
    ctx->r17 = ADD32(ctx->r4, 0);
    // 0x800F2FE8: sw          $s2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r18;
    // 0x800F2FEC: addu        $s2, $a1, $zero
    ctx->r18 = ADD32(ctx->r5, 0);
    // 0x800F2FF0: sw          $s3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r19;
    // 0x800F2FF4: addu        $s3, $a2, $zero
    ctx->r19 = ADD32(ctx->r6, 0);
    // 0x800F2FF8: sw          $s4, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r20;
    // 0x800F2FFC: sw          $s0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r16;
    // 0x800F3000: lbu         $s0, 0x7B($sp)
    ctx->r16 = MEM_BU(ctx->r29, 0X7B);
    // 0x800F3004: sw          $ra, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r31;
    // 0x800F3008: jal         0x800F2FB4
    // 0x800F300C: addu        $s4, $a3, $zero
    ctx->r20 = ADD32(ctx->r7, 0);
    func_800F2FB4(rdram, ctx);
        goto after_0;
    // 0x800F300C: addu        $s4, $a3, $zero
    ctx->r20 = ADD32(ctx->r7, 0);
    after_0:
    // 0x800F3010: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // 0x800F3014: addu        $a2, $s3, $zero
    ctx->r6 = ADD32(ctx->r19, 0);
    // 0x800F3018: lhu         $a1, 0x198($s1)
    ctx->r5 = MEM_HU(ctx->r17, 0X198);
    // 0x800F301C: addu        $a3, $s4, $zero
    ctx->r7 = ADD32(ctx->r20, 0);
    // 0x800F3020: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    // 0x800F3024: andi        $s0, $s0, 0xFF
    ctx->r16 = ctx->r16 & 0XFF;
    // 0x800F3028: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x800F302C: jal         0x8005E3B0
    // 0x800F3030: swc1        $f20, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f20.u32l;
    func_8005E3B0(rdram, ctx);
        goto after_1;
    // 0x800F3030: swc1        $f20, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f20.u32l;
    after_1:
    // 0x800F3034: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800F3038: c.le.s      $f0, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    c1cs = ctx->f0.fl <= ctx->f22.fl;
    // 0x800F303C: nop

    // 0x800F3040: bc1f        L_800F3080
    if (!c1cs) {
        // 0x800F3044: addu        $s0, $v0, $zero
        ctx->r16 = ADD32(ctx->r2, 0);
            goto L_800F3080;
    }
    // 0x800F3044: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    // 0x800F3048: c.eq.s      $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f22.fl == ctx->f0.fl;
    // 0x800F304C: nop

    // 0x800F3050: bc1f        L_800F3060
    if (!c1cs) {
        // 0x800F3054: swc1        $f22, 0x38($sp)
        MEM_W(0X38, ctx->r29) = ctx->f22.u32l;
            goto L_800F3060;
    }
    // 0x800F3054: swc1        $f22, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f22.u32l;
    // 0x800F3058: j           L_800F3064
    // 0x800F305C: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
        goto L_800F3064;
    // 0x800F305C: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
L_800F3060:
    // 0x800F3060: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800F3064:
    // 0x800F3064: sb          $v0, 0x3C($sp)
    MEM_B(0X3C, ctx->r29) = ctx->r2;
    // 0x800F3068: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x800F306C: sh          $v0, 0x20($sp)
    MEM_H(0X20, ctx->r29) = ctx->r2;
    // 0x800F3070: andi        $a0, $s0, 0xFFFF
    ctx->r4 = ctx->r16 & 0XFFFF;
    // 0x800F3074: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    // 0x800F3078: jal         0x8003E8DC
    // 0x800F307C: addiu       $a2, $sp, 0x20
    ctx->r6 = ADD32(ctx->r29, 0X20);
    func_8003E8DC(rdram, ctx);
        goto after_2;
    // 0x800F307C: addiu       $a2, $sp, 0x20
    ctx->r6 = ADD32(ctx->r29, 0X20);
    after_2:
L_800F3080:
    // 0x800F3080: andi        $v0, $s0, 0xFFFF
    ctx->r2 = ctx->r16 & 0XFFFF;
    // 0x800F3084: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
    // 0x800F3088: lw          $s4, 0x50($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X50);
    // 0x800F308C: lw          $s3, 0x4C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X4C);
    // 0x800F3090: lw          $s2, 0x48($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X48);
    // 0x800F3094: lw          $s1, 0x44($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X44);
    // 0x800F3098: lw          $s0, 0x40($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X40);
    // 0x800F309C: ldc1        $f22, 0x60($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X60);
    // 0x800F30A0: ldc1        $f20, 0x58($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X58);
    // 0x800F30A4: jr          $ra
    // 0x800F30A8: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    return;
    // 0x800F30A8: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
;}
RECOMP_FUNC void func_800F30AC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F30AC: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x800F30B0: lbu         $v0, 0x0($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X0);
    // 0x800F30B4: beq         $v0, $zero, L_800F3138
    if (ctx->r2 == 0) {
        // 0x800F30B8: addu        $v1, $zero, $zero
        ctx->r3 = ADD32(0, 0);
            goto L_800F3138;
    }
    // 0x800F30B8: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
    // 0x800F30BC: addiu       $a3, $zero, 0x7C
    ctx->r7 = ADD32(0, 0X7C);
    // 0x800F30C0: addiu       $t0, $a1, 0x1
    ctx->r8 = ADD32(ctx->r5, 0X1);
L_800F30C4:
    // 0x800F30C4: bne         $v0, $a3, L_800F30D4
    if (ctx->r2 != ctx->r7) {
        // 0x800F30C8: nop
    
            goto L_800F30D4;
    }
    // 0x800F30C8: nop

    // 0x800F30CC: j           L_800F30E0
    // 0x800F30D0: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
        goto L_800F30E0;
    // 0x800F30D0: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
L_800F30D4:
    // 0x800F30D4: lbu         $v0, 0x1($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X1);
    // 0x800F30D8: bne         $v0, $zero, L_800F30E4
    if (ctx->r2 != 0) {
        // 0x800F30DC: nop
    
            goto L_800F30E4;
    }
    // 0x800F30DC: nop

L_800F30E0:
    // 0x800F30E0: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
L_800F30E4:
    // 0x800F30E4: bnel        $v1, $a1, L_800F312C
    if (ctx->r3 != ctx->r5) {
        // 0x800F30E8: addiu       $a0, $a0, 0x1
        ctx->r4 = ADD32(ctx->r4, 0X1);
            goto L_800F312C;
    }
    goto skip_0;
    // 0x800F30E8: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    skip_0:
    // 0x800F30EC: lbu         $v0, 0x0($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X0);
    // 0x800F30F0: beql        $v0, $zero, L_800F3118
    if (ctx->r2 == 0) {
        // 0x800F30F4: sb          $zero, 0x0($a2)
        MEM_B(0X0, ctx->r6) = 0;
            goto L_800F3118;
    }
    goto skip_1;
    // 0x800F30F4: sb          $zero, 0x0($a2)
    MEM_B(0X0, ctx->r6) = 0;
    skip_1:
L_800F30F8:
    // 0x800F30F8: beql        $v0, $a3, L_800F3118
    if (ctx->r2 == ctx->r7) {
        // 0x800F30FC: sb          $zero, 0x0($a2)
        MEM_B(0X0, ctx->r6) = 0;
            goto L_800F3118;
    }
    goto skip_2;
    // 0x800F30FC: sb          $zero, 0x0($a2)
    MEM_B(0X0, ctx->r6) = 0;
    skip_2:
    // 0x800F3100: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x800F3104: sb          $v0, 0x0($a2)
    MEM_B(0X0, ctx->r6) = ctx->r2;
    // 0x800F3108: lbu         $v0, 0x0($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X0);
    // 0x800F310C: bne         $v0, $zero, L_800F30F8
    if (ctx->r2 != 0) {
        // 0x800F3110: addiu       $a2, $a2, 0x1
        ctx->r6 = ADD32(ctx->r6, 0X1);
            goto L_800F30F8;
    }
    // 0x800F3110: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x800F3114: sb          $zero, 0x0($a2)
    MEM_B(0X0, ctx->r6) = 0;
L_800F3118:
    // 0x800F3118: lbu         $v1, 0x0($a0)
    ctx->r3 = MEM_BU(ctx->r4, 0X0);
    // 0x800F311C: beq         $v1, $zero, L_800F313C
    if (ctx->r3 == 0) {
        // 0x800F3120: addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
            goto L_800F313C;
    }
    // 0x800F3120: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // 0x800F3124: jr          $ra
    // 0x800F3128: addu        $v0, $t0, $zero
    ctx->r2 = ADD32(ctx->r8, 0);
    return;
    // 0x800F3128: addu        $v0, $t0, $zero
    ctx->r2 = ADD32(ctx->r8, 0);
L_800F312C:
    // 0x800F312C: lbu         $v0, 0x0($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X0);
    // 0x800F3130: bne         $v0, $zero, L_800F30C4
    if (ctx->r2 != 0) {
        // 0x800F3134: nop
    
            goto L_800F30C4;
    }
    // 0x800F3134: nop

L_800F3138:
    // 0x800F3138: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_800F313C:
    // 0x800F313C: jr          $ra
    // 0x800F3140: nop

    return;
    // 0x800F3140: nop

;}
RECOMP_FUNC void func_800F3144(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F3144: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800F3148: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x800F314C: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x800F3150: sw          $ra, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r31;
    // 0x800F3154: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x800F3158: lbu         $v0, 0x0($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X0);
    // 0x800F315C: beq         $v0, $zero, L_800F323C
    if (ctx->r2 == 0) {
        // 0x800F3160: addu        $s1, $a1, $zero
        ctx->r17 = ADD32(ctx->r5, 0);
            goto L_800F323C;
    }
    // 0x800F3160: addu        $s1, $a1, $zero
    ctx->r17 = ADD32(ctx->r5, 0);
    // 0x800F3164: jal         0x80003430
    // 0x800F3168: nop

    rand_recomp(rdram, ctx);
        goto after_0;
    // 0x800F3168: nop

    after_0:
    // 0x800F316C: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    // 0x800F3170: addiu       $a0, $s0, 0x1
    ctx->r4 = ADD32(ctx->r16, 0X1);
    // 0x800F3174: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x800F3178: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x800F317C: lbu         $v1, 0x0($s0)
    ctx->r3 = MEM_BU(ctx->r16, 0X0);
    // 0x800F3180: lbu         $a2, 0x0($a0)
    ctx->r6 = MEM_BU(ctx->r4, 0X0);
    // 0x800F3184: div         $zero, $v0, $v1
    lo = S32(S64(S32(ctx->r2)) / S64(S32(ctx->r3))); hi = S32(S64(S32(ctx->r2)) % S64(S32(ctx->r3)));
    // 0x800F3188: bne         $v1, $zero, L_800F3194
    if (ctx->r3 != 0) {
        // 0x800F318C: nop
    
            goto L_800F3194;
    }
    // 0x800F318C: nop

    // 0x800F3190: break       7
    do_break(2148479376);
L_800F3194:
    // 0x800F3194: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800F3198: bne         $v1, $at, L_800F31AC
    if (ctx->r3 != ctx->r1) {
        // 0x800F319C: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800F31AC;
    }
    // 0x800F319C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800F31A0: bne         $v0, $at, L_800F31AC
    if (ctx->r2 != ctx->r1) {
        // 0x800F31A4: nop
    
            goto L_800F31AC;
    }
    // 0x800F31A4: nop

    // 0x800F31A8: break       6
    do_break(2148479400);
L_800F31AC:
    // 0x800F31AC: mfhi        $t0
    ctx->r8 = hi;
    // 0x800F31B0: beq         $a2, $zero, L_800F3230
    if (ctx->r6 == 0) {
        // 0x800F31B4: addu        $a3, $zero, $zero
        ctx->r7 = ADD32(0, 0);
            goto L_800F3230;
    }
    // 0x800F31B4: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    // 0x800F31B8: addiu       $v1, $zero, 0x7C
    ctx->r3 = ADD32(0, 0X7C);
L_800F31BC:
    // 0x800F31BC: bne         $a2, $v1, L_800F31CC
    if (ctx->r6 != ctx->r3) {
        // 0x800F31C0: nop
    
            goto L_800F31CC;
    }
    // 0x800F31C0: nop

    // 0x800F31C4: j           L_800F31D8
    // 0x800F31C8: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
        goto L_800F31D8;
    // 0x800F31C8: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
L_800F31CC:
    // 0x800F31CC: lbu         $v0, 0x1($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X1);
    // 0x800F31D0: bne         $v0, $zero, L_800F31DC
    if (ctx->r2 != 0) {
        // 0x800F31D4: nop
    
            goto L_800F31DC;
    }
    // 0x800F31D4: nop

L_800F31D8:
    // 0x800F31D8: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
L_800F31DC:
    // 0x800F31DC: bnel        $a3, $t0, L_800F3224
    if (ctx->r7 != ctx->r8) {
        // 0x800F31E0: addiu       $a0, $a0, 0x1
        ctx->r4 = ADD32(ctx->r4, 0X1);
            goto L_800F3224;
    }
    goto skip_0;
    // 0x800F31E0: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    skip_0:
    // 0x800F31E4: lbu         $v0, 0x0($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X0);
    // 0x800F31E8: beql        $v0, $zero, L_800F3210
    if (ctx->r2 == 0) {
        // 0x800F31EC: sb          $zero, 0x0($a1)
        MEM_B(0X0, ctx->r5) = 0;
            goto L_800F3210;
    }
    goto skip_1;
    // 0x800F31EC: sb          $zero, 0x0($a1)
    MEM_B(0X0, ctx->r5) = 0;
    skip_1:
L_800F31F0:
    // 0x800F31F0: beql        $v0, $v1, L_800F3210
    if (ctx->r2 == ctx->r3) {
        // 0x800F31F4: sb          $zero, 0x0($a1)
        MEM_B(0X0, ctx->r5) = 0;
            goto L_800F3210;
    }
    goto skip_2;
    // 0x800F31F4: sb          $zero, 0x0($a1)
    MEM_B(0X0, ctx->r5) = 0;
    skip_2:
    // 0x800F31F8: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x800F31FC: sb          $v0, 0x0($a1)
    MEM_B(0X0, ctx->r5) = ctx->r2;
    // 0x800F3200: lbu         $v0, 0x0($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X0);
    // 0x800F3204: bne         $v0, $zero, L_800F31F0
    if (ctx->r2 != 0) {
        // 0x800F3208: addiu       $a1, $a1, 0x1
        ctx->r5 = ADD32(ctx->r5, 0X1);
            goto L_800F31F0;
    }
    // 0x800F3208: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x800F320C: sb          $zero, 0x0($a1)
    MEM_B(0X0, ctx->r5) = 0;
L_800F3210:
    // 0x800F3210: lbu         $v0, 0x0($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X0);
    // 0x800F3214: beq         $v0, $zero, L_800F3234
    if (ctx->r2 == 0) {
        // 0x800F3218: addu        $v1, $zero, $zero
        ctx->r3 = ADD32(0, 0);
            goto L_800F3234;
    }
    // 0x800F3218: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
    // 0x800F321C: j           L_800F3234
    // 0x800F3220: addiu       $v1, $t0, 0x1
    ctx->r3 = ADD32(ctx->r8, 0X1);
        goto L_800F3234;
    // 0x800F3220: addiu       $v1, $t0, 0x1
    ctx->r3 = ADD32(ctx->r8, 0X1);
L_800F3224:
    // 0x800F3224: lbu         $a2, 0x0($a0)
    ctx->r6 = MEM_BU(ctx->r4, 0X0);
    // 0x800F3228: bne         $a2, $zero, L_800F31BC
    if (ctx->r6 != 0) {
        // 0x800F322C: nop
    
            goto L_800F31BC;
    }
    // 0x800F322C: nop

L_800F3230:
    // 0x800F3230: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
L_800F3234:
    // 0x800F3234: j           L_800F3244
    // 0x800F3238: addu        $v0, $v1, $zero
    ctx->r2 = ADD32(ctx->r3, 0);
        goto L_800F3244;
    // 0x800F3238: addu        $v0, $v1, $zero
    ctx->r2 = ADD32(ctx->r3, 0);
L_800F323C:
    // 0x800F323C: sb          $zero, 0x0($s1)
    MEM_B(0X0, ctx->r17) = 0;
    // 0x800F3240: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_800F3244:
    // 0x800F3244: lw          $ra, 0x18($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X18);
    // 0x800F3248: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x800F324C: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x800F3250: jr          $ra
    // 0x800F3254: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x800F3254: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_800F3258(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F3258: jr          $ra
    // 0x800F325C: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    return;
    // 0x800F325C: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
;}
RECOMP_FUNC void func_800F3260(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F3260: lbu         $v0, 0x15($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X15);
    // 0x800F3264: addiu       $v1, $zero, 0x2
    ctx->r3 = ADD32(0, 0X2);
    // 0x800F3268: srl         $v0, $v0, 6
    ctx->r2 = S32(U32(ctx->r2) >> 6);
    // 0x800F326C: bne         $v0, $v1, L_800F3284
    if (ctx->r2 != ctx->r3) {
        // 0x800F3270: lui         $v1, 0x8013
        ctx->r3 = S32(0X8013 << 16);
            goto L_800F3284;
    }
    // 0x800F3270: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x800F3274: addiu       $v1, $v1, 0xB78
    ctx->r3 = ADD32(ctx->r3, 0XB78);
    // 0x800F3278: lhu         $v0, 0xC($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0XC);
    // 0x800F327C: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800F3280: sh          $v0, 0xC($v1)
    MEM_H(0XC, ctx->r3) = ctx->r2;
L_800F3284:
    // 0x800F3284: jr          $ra
    // 0x800F3288: nop

    return;
    // 0x800F3288: nop

;}
RECOMP_FUNC void func_800F3290(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F3290: addiu       $sp, $sp, -0x78
    ctx->r29 = ADD32(ctx->r29, -0X78);
    // 0x800F3294: sw          $s6, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r22;
    // 0x800F3298: addu        $s6, $a0, $zero
    ctx->r22 = ADD32(ctx->r4, 0);
    // 0x800F329C: sw          $s1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r17;
    // 0x800F32A0: addu        $s1, $a1, $zero
    ctx->r17 = ADD32(ctx->r5, 0);
    // 0x800F32A4: sw          $s4, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r20;
    // 0x800F32A8: addu        $s4, $zero, $zero
    ctx->r20 = ADD32(0, 0);
    // 0x800F32AC: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x800F32B0: sw          $fp, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r30;
    // 0x800F32B4: addiu       $fp, $v0, -0x7760
    ctx->r30 = ADD32(ctx->r2, -0X7760);
    // 0x800F32B8: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x800F32BC: sw          $s7, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r23;
    // 0x800F32C0: addiu       $s7, $v0, -0x7FA0
    ctx->r23 = ADD32(ctx->r2, -0X7FA0);
    // 0x800F32C4: sw          $ra, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r31;
    // 0x800F32C8: sw          $s5, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r21;
    // 0x800F32CC: sw          $s3, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r19;
    // 0x800F32D0: sw          $s2, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r18;
    // 0x800F32D4: sw          $s0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r16;
    // 0x800F32D8: lw          $v0, 0x24($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X24);
    // 0x800F32DC: addiu       $s5, $zero, 0x1
    ctx->r21 = ADD32(0, 0X1);
    // 0x800F32E0: addiu       $s3, $v0, 0x54
    ctx->r19 = ADD32(ctx->r2, 0X54);
    // 0x800F32E4: addiu       $s0, $v0, 0x58
    ctx->r16 = ADD32(ctx->r2, 0X58);
L_800F32E8:
    // 0x800F32E8: lw          $a0, 0x24($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X24);
    // 0x800F32EC: lw          $v0, 0x8($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X8);
    // 0x800F32F0: lw          $v1, 0x0($s3)
    ctx->r3 = MEM_W(ctx->r19, 0X0);
    // 0x800F32F4: addu        $s2, $a0, $v0
    ctx->r18 = ADD32(ctx->r4, ctx->r2);
    // 0x800F32F8: addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
    // 0x800F32FC: sltiu       $v0, $v1, 0x7
    ctx->r2 = ctx->r3 < 0X7 ? 1 : 0;
    // 0x800F3300: beq         $v0, $zero, L_800F3480
    if (ctx->r2 == 0) {
        // 0x800F3304: sll         $v0, $v1, 2
        ctx->r2 = S32(ctx->r3 << 2);
            goto L_800F3480;
    }
    // 0x800F3304: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x800F3308: lui         $a3, 0x800B
    ctx->r7 = S32(0X800B << 16);
    // 0x800F330C: addiu       $a3, $a3, -0x75E0
    ctx->r7 = ADD32(ctx->r7, -0X75E0);
    // 0x800F3310: addu        $v0, $v0, $a3
    gpr jr_addend_800F3318 = ctx->r2;
    ctx->r2 = ADD32(ctx->r2, ctx->r7);
    // 0x800F3314: lw          $v0, 0x0($v0)
    ctx->r2 = ADD32(ctx->r2, 0X0);
    // 0x800F3318: jr          $v0
    // 0x800F331C: nop

    switch (jr_addend_800F3318 >> 2) {
        case 0: goto L_800F3320; break;
        case 1: goto L_800F3344; break;
        case 2: goto L_800F339C; break;
        case 3: goto L_800F33DC; break;
        case 4: goto L_800F33F0; break;
        case 5: goto L_800F3418; break;
        case 6: goto L_800F3434; break;
        default: switch_error(__func__, 0x800F3318, 0x800A8A20);
    }
    // 0x800F331C: nop

L_800F3320:
    // 0x800F3320: lwc1        $f0, 0x0($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X0);
    // 0x800F3324: lw          $v1, 0x34($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X34);
    // 0x800F3328: trunc.w.s   $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    ctx->f4.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800F332C: mfc1        $v0, $f4
    ctx->r2 = (int32_t)ctx->f4.u32l;
    // 0x800F3330: slt         $v0, $v0, $v1
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800F3334: bne         $v0, $zero, L_800F3490
    if (ctx->r2 != 0) {
        // 0x800F3338: addiu       $s0, $s0, 0x10
        ctx->r16 = ADD32(ctx->r16, 0X10);
            goto L_800F3490;
    }
    // 0x800F3338: addiu       $s0, $s0, 0x10
    ctx->r16 = ADD32(ctx->r16, 0X10);
    // 0x800F333C: j           L_800F34A0
    // 0x800F3340: nop

        goto L_800F34A0;
    // 0x800F3340: nop

L_800F3344:
    // 0x800F3344: lwc1        $f0, 0x0($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X0);
    // 0x800F3348: trunc.w.s   $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    ctx->f4.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800F334C: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x800F3350: bne         $a1, $zero, L_800F3360
    if (ctx->r5 != 0) {
        // 0x800F3354: slti        $v0, $a1, 0x81
        ctx->r2 = SIGNED(ctx->r5) < 0X81 ? 1 : 0;
            goto L_800F3360;
    }
    // 0x800F3354: slti        $v0, $a1, 0x81
    ctx->r2 = SIGNED(ctx->r5) < 0X81 ? 1 : 0;
    // 0x800F3358: j           L_800F337C
    // 0x800F335C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_800F337C;
    // 0x800F335C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800F3360:
    // 0x800F3360: beq         $v0, $zero, L_800F3374
    if (ctx->r2 == 0) {
        // 0x800F3364: addu        $v0, $a1, $fp
        ctx->r2 = ADD32(ctx->r5, ctx->r30);
            goto L_800F3374;
    }
    // 0x800F3364: addu        $v0, $a1, $fp
    ctx->r2 = ADD32(ctx->r5, ctx->r30);
    // 0x800F3368: lbu         $v0, -0x1($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X1);
    // 0x800F336C: j           L_800F337C
    // 0x800F3370: sltu        $v0, $zero, $v0
    ctx->r2 = 0 < ctx->r2 ? 1 : 0;
        goto L_800F337C;
    // 0x800F3370: sltu        $v0, $zero, $v0
    ctx->r2 = 0 < ctx->r2 ? 1 : 0;
L_800F3374:
    // 0x800F3374: jal         0x800F3258
    // 0x800F3378: addu        $a0, $s6, $zero
    ctx->r4 = ADD32(ctx->r22, 0);
    func_800F3258(rdram, ctx);
        goto after_0;
    // 0x800F3378: addu        $a0, $s6, $zero
    ctx->r4 = ADD32(ctx->r22, 0);
    after_0:
L_800F337C:
    // 0x800F337C: lwc1        $f0, 0x4($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X4);
    // 0x800F3380: andi        $v1, $v0, 0xFF
    ctx->r3 = ctx->r2 & 0XFF;
    // 0x800F3384: trunc.w.s   $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    ctx->f4.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800F3388: mfc1        $v0, $f4
    ctx->r2 = (int32_t)ctx->f4.u32l;
    // 0x800F338C: bne         $v1, $v0, L_800F3490
    if (ctx->r3 != ctx->r2) {
        // 0x800F3390: addiu       $s0, $s0, 0x10
        ctx->r16 = ADD32(ctx->r16, 0X10);
            goto L_800F3490;
    }
    // 0x800F3390: addiu       $s0, $s0, 0x10
    ctx->r16 = ADD32(ctx->r16, 0X10);
    // 0x800F3394: j           L_800F33F4
    // 0x800F3398: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
        goto L_800F33F4;
    // 0x800F3398: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
L_800F339C:
    // 0x800F339C: lwc1        $f0, 0x0($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X0);
    // 0x800F33A0: trunc.w.s   $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    ctx->f4.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800F33A4: mfc1        $v0, $f4
    ctx->r2 = (int32_t)ctx->f4.u32l;
    // 0x800F33A8: blez        $v0, L_800F348C
    if (SIGNED(ctx->r2) <= 0) {
        // 0x800F33AC: addiu       $v0, $v0, -0x1
        ctx->r2 = ADD32(ctx->r2, -0X1);
            goto L_800F348C;
    }
    // 0x800F33AC: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x800F33B0: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800F33B4: addu        $v0, $v0, $s7
    ctx->r2 = ADD32(ctx->r2, ctx->r23);
    // 0x800F33B8: lwc1        $f0, 0x4($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X4);
    // 0x800F33BC: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x800F33C0: trunc.w.s   $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    ctx->f4.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800F33C4: mfc1        $v1, $f4
    ctx->r3 = (int32_t)ctx->f4.u32l;
    // 0x800F33C8: slt         $v0, $v0, $v1
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800F33CC: bne         $v0, $zero, L_800F3490
    if (ctx->r2 != 0) {
        // 0x800F33D0: addiu       $s0, $s0, 0x10
        ctx->r16 = ADD32(ctx->r16, 0X10);
            goto L_800F3490;
    }
    // 0x800F33D0: addiu       $s0, $s0, 0x10
    ctx->r16 = ADD32(ctx->r16, 0X10);
    // 0x800F33D4: j           L_800F33F4
    // 0x800F33D8: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
        goto L_800F33F4;
    // 0x800F33D8: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
L_800F33DC:
    // 0x800F33DC: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // 0x800F33E0: jal         0x800F3144
    // 0x800F33E4: addiu       $a1, $sp, 0x10
    ctx->r5 = ADD32(ctx->r29, 0X10);
    func_800F3144(rdram, ctx);
        goto after_1;
    // 0x800F33E4: addiu       $a1, $sp, 0x10
    ctx->r5 = ADD32(ctx->r29, 0X10);
    after_1:
    // 0x800F33E8: j           L_800F3400
    // 0x800F33EC: nop

        goto L_800F3400;
    // 0x800F33EC: nop

L_800F33F0:
    // 0x800F33F0: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
L_800F33F4:
    // 0x800F33F4: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x800F33F8: jal         0x800F30AC
    // 0x800F33FC: addiu       $a2, $sp, 0x10
    ctx->r6 = ADD32(ctx->r29, 0X10);
    func_800F30AC(rdram, ctx);
        goto after_2;
    // 0x800F33FC: addiu       $a2, $sp, 0x10
    ctx->r6 = ADD32(ctx->r29, 0X10);
    after_2:
L_800F3400:
    // 0x800F3400: jal         0x80047B48
    // 0x800F3404: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    getLevelDatItemByName(rdram, ctx);
        goto after_3;
    // 0x800F3404: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    after_3:
    // 0x800F3408: sw          $v0, 0x28($s1)
    MEM_W(0X28, ctx->r17) = ctx->r2;
    // 0x800F340C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800F3410: j           L_800F34AC
    // 0x800F3414: sw          $zero, 0x34($s1)
    MEM_W(0X34, ctx->r17) = 0;
        goto L_800F34AC;
    // 0x800F3414: sw          $zero, 0x34($s1)
    MEM_W(0X34, ctx->r17) = 0;
L_800F3418:
    // 0x800F3418: lwc1        $f0, 0x0($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X0);
    // 0x800F341C: trunc.w.s   $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    ctx->f4.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800F3420: mfc1        $v0, $f4
    ctx->r2 = (int32_t)ctx->f4.u32l;
    // 0x800F3424: beql        $v0, $s5, L_800F342C
    if (ctx->r2 == ctx->r21) {
        // 0x800F3428: sb          $s5, 0x1A5($s6)
        MEM_B(0X1A5, ctx->r22) = ctx->r21;
            goto L_800F342C;
    }
    goto skip_0;
    // 0x800F3428: sb          $s5, 0x1A5($s6)
    MEM_B(0X1A5, ctx->r22) = ctx->r21;
    skip_0:
L_800F342C:
    // 0x800F342C: j           L_800F34AC
    // 0x800F3430: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
        goto L_800F34AC;
    // 0x800F3430: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_800F3434:
    // 0x800F3434: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // 0x800F3438: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x800F343C: jal         0x800F30AC
    // 0x800F3440: addiu       $a2, $sp, 0x10
    ctx->r6 = ADD32(ctx->r29, 0X10);
    func_800F30AC(rdram, ctx);
        goto after_4;
    // 0x800F3440: addiu       $a2, $sp, 0x10
    ctx->r6 = ADD32(ctx->r29, 0X10);
    after_4:
    // 0x800F3444: jal         0x80047B48
    // 0x800F3448: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    getLevelDatItemByName(rdram, ctx);
        goto after_5;
    // 0x800F3448: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    after_5:
    // 0x800F344C: sw          $v0, 0x28($s1)
    MEM_W(0X28, ctx->r17) = ctx->r2;
    // 0x800F3450: sw          $zero, 0x34($s1)
    MEM_W(0X34, ctx->r17) = 0;
    // 0x800F3454: lwc1        $f0, 0x0($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X0);
    // 0x800F3458: swc1        $f0, 0x104($s1)
    MEM_W(0X104, ctx->r17) = ctx->f0.u32l;
    // 0x800F345C: lw          $v0, 0x50($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X50);
    // 0x800F3460: bne         $v0, $s5, L_800F34AC
    if (ctx->r2 != ctx->r21) {
        // 0x800F3464: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_800F34AC;
    }
    // 0x800F3464: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800F3468: lwc1        $f0, 0x14($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X14);
    // 0x800F346C: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800F3470: lwc1        $f2, -0x75C4($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X75C4);
    // 0x800F3474: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x800F3478: j           L_800F34AC
    // 0x800F347C: swc1        $f0, 0x14($s1)
    MEM_W(0X14, ctx->r17) = ctx->f0.u32l;
        goto L_800F34AC;
    // 0x800F347C: swc1        $f0, 0x14($s1)
    MEM_W(0X14, ctx->r17) = ctx->f0.u32l;
L_800F3480:
    // 0x800F3480: sw          $a0, 0x28($s1)
    MEM_W(0X28, ctx->r17) = ctx->r4;
    // 0x800F3484: j           L_800F34AC
    // 0x800F3488: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_800F34AC;
    // 0x800F3488: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800F348C:
    // 0x800F348C: addiu       $s0, $s0, 0x10
    ctx->r16 = ADD32(ctx->r16, 0X10);
L_800F3490:
    // 0x800F3490: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    // 0x800F3494: slti        $v0, $s4, 0x8
    ctx->r2 = SIGNED(ctx->r20) < 0X8 ? 1 : 0;
    // 0x800F3498: bne         $v0, $zero, L_800F32E8
    if (ctx->r2 != 0) {
        // 0x800F349C: addiu       $s3, $s3, 0x10
        ctx->r19 = ADD32(ctx->r19, 0X10);
            goto L_800F32E8;
    }
    // 0x800F349C: addiu       $s3, $s3, 0x10
    ctx->r19 = ADD32(ctx->r19, 0X10);
L_800F34A0:
    // 0x800F34A0: lw          $v1, 0x24($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X24);
    // 0x800F34A4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800F34A8: sw          $v1, 0x28($s1)
    MEM_W(0X28, ctx->r17) = ctx->r3;
L_800F34AC:
    // 0x800F34AC: lw          $ra, 0x74($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X74);
    // 0x800F34B0: lw          $fp, 0x70($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X70);
    // 0x800F34B4: lw          $s7, 0x6C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X6C);
    // 0x800F34B8: lw          $s6, 0x68($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X68);
    // 0x800F34BC: lw          $s5, 0x64($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X64);
    // 0x800F34C0: lw          $s4, 0x60($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X60);
    // 0x800F34C4: lw          $s3, 0x5C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X5C);
    // 0x800F34C8: lw          $s2, 0x58($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X58);
    // 0x800F34CC: lw          $s1, 0x54($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X54);
    // 0x800F34D0: lw          $s0, 0x50($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X50);
    // 0x800F34D4: jr          $ra
    // 0x800F34D8: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
    return;
    // 0x800F34D8: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
;}
