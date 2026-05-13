#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void func_80060900(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80060900: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80060904: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x80060908: addu        $s3, $a0, $zero
    ctx->r19 = ADD32(ctx->r4, 0);
    // 0x8006090C: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80060910: andi        $s1, $a1, 0xFFFF
    ctx->r17 = ctx->r5 & 0XFFFF;
    // 0x80060914: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x80060918: sw          $ra, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r31;
    // 0x8006091C: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80060920: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80060924: lw          $s0, 0x4($s3)
    ctx->r16 = MEM_W(ctx->r19, 0X4);
    // 0x80060928: beq         $s1, $v0, L_80060D6C
    if (ctx->r17 == ctx->r2) {
        // 0x8006092C: slti        $v0, $s1, 0x3
        ctx->r2 = SIGNED(ctx->r17) < 0X3 ? 1 : 0;
            goto L_80060D6C;
    }
    // 0x8006092C: slti        $v0, $s1, 0x3
    ctx->r2 = SIGNED(ctx->r17) < 0X3 ? 1 : 0;
    // 0x80060930: beq         $v0, $zero, L_80060948
    if (ctx->r2 == 0) {
        // 0x80060934: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80060948;
    }
    // 0x80060934: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80060938: beq         $s1, $v0, L_80060964
    if (ctx->r17 == ctx->r2) {
        // 0x8006093C: addiu       $v0, $zero, 0x300
        ctx->r2 = ADD32(0, 0X300);
            goto L_80060964;
    }
    // 0x8006093C: addiu       $v0, $zero, 0x300
    ctx->r2 = ADD32(0, 0X300);
    // 0x80060940: j           L_80060D70
    // 0x80060944: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80060D70;
    // 0x80060944: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80060948:
    // 0x80060948: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x8006094C: beq         $s1, $v0, L_80060AA4
    if (ctx->r17 == ctx->r2) {
        // 0x80060950: addiu       $v0, $zero, 0x4
        ctx->r2 = ADD32(0, 0X4);
            goto L_80060AA4;
    }
    // 0x80060950: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // 0x80060954: beq         $s1, $v0, L_80060C2C
    if (ctx->r17 == ctx->r2) {
        // 0x80060958: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80060C2C;
    }
    // 0x80060958: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8006095C: j           L_80060D70
    // 0x80060960: nop

        goto L_80060D70;
    // 0x80060960: nop

L_80060964:
    // 0x80060964: addu        $s2, $a2, $zero
    ctx->r18 = ADD32(ctx->r6, 0);
    // 0x80060968: jal         0x80003430
    // 0x8006096C: sh          $v0, 0x10($s0)
    MEM_H(0X10, ctx->r16) = ctx->r2;
    rand_recomp(rdram, ctx);
        goto after_0;
    // 0x8006096C: sh          $v0, 0x10($s0)
    MEM_H(0X10, ctx->r16) = ctx->r2;
    after_0:
    // 0x80060970: addiu       $v1, $zero, 0xFF
    ctx->r3 = ADD32(0, 0XFF);
    // 0x80060974: andi        $v0, $v0, 0x1C00
    ctx->r2 = ctx->r2 & 0X1C00;
    // 0x80060978: sb          $v1, 0x2E($s0)
    MEM_B(0X2E, ctx->r16) = ctx->r3;
    // 0x8006097C: sb          $v1, 0x2D($s0)
    MEM_B(0X2D, ctx->r16) = ctx->r3;
    // 0x80060980: sb          $v1, 0x2C($s0)
    MEM_B(0X2C, ctx->r16) = ctx->r3;
    // 0x80060984: sb          $v1, 0x2F($s0)
    MEM_B(0X2F, ctx->r16) = ctx->r3;
    // 0x80060988: lhu         $v1, 0x10($s0)
    ctx->r3 = MEM_HU(ctx->r16, 0X10);
    // 0x8006098C: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80060990: lwc1        $f0, -0x4CE8($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X4CE8);
    // 0x80060994: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x80060998: sh          $v1, 0x10($s0)
    MEM_H(0X10, ctx->r16) = ctx->r3;
    // 0x8006099C: swc1        $f0, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->f0.u32l;
    // 0x800609A0: lbu         $v0, 0x10($s2)
    ctx->r2 = MEM_BU(ctx->r18, 0X10);
    // 0x800609A4: sb          $v0, 0x50($s0)
    MEM_B(0X50, ctx->r16) = ctx->r2;
    // 0x800609A8: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x800609AC: beql        $v0, $zero, L_800609BC
    if (ctx->r2 == 0) {
        // 0x800609B0: lui         $v0, 0x8014
        ctx->r2 = S32(0X8014 << 16);
            goto L_800609BC;
    }
    goto skip_0;
    // 0x800609B0: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    skip_0:
    // 0x800609B4: beq         $v0, $s1, L_800609C8
    if (ctx->r2 == ctx->r17) {
        // 0x800609B8: lui         $v0, 0x8014
        ctx->r2 = S32(0X8014 << 16);
            goto L_800609C8;
    }
    // 0x800609B8: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
L_800609BC:
    // 0x800609BC: lhu         $v0, -0x6700($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X6700);
    // 0x800609C0: j           L_800609D0
    // 0x800609C4: nop

        goto L_800609D0;
    // 0x800609C4: nop

L_800609C8:
    // 0x800609C8: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x800609CC: lhu         $v0, -0x66F0($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X66F0);
L_800609D0:
    // 0x800609D0: jal         0x80003430
    // 0x800609D4: sh          $v0, 0x12($s0)
    MEM_H(0X12, ctx->r16) = ctx->r2;
    rand_recomp(rdram, ctx);
        goto after_1;
    // 0x800609D4: sh          $v0, 0x12($s0)
    MEM_H(0X12, ctx->r16) = ctx->r2;
    after_1:
    // 0x800609D8: andi        $v0, $v0, 0x7F
    ctx->r2 = ctx->r2 & 0X7F;
    // 0x800609DC: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x800609E0: lwc1        $f2, -0x4CE4($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X4CE4);
    // 0x800609E4: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x800609E8: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x800609EC: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x800609F0: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x800609F4: lwc1        $f2, -0x4CE0($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X4CE0);
    // 0x800609F8: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x800609FC: abs.s       $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = fabsf(ctx->f0.fl);
    // 0x80060A00: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80060A04: lwc1        $f0, -0x4CDC($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X4CDC);
    // 0x80060A08: add.s       $f4, $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f0.fl;
    // 0x80060A0C: lwc1        $f0, 0x8($s2)
    ctx->f0.u32l = MEM_W(ctx->r18, 0X8);
    // 0x80060A10: mul.s       $f4, $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x80060A14: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80060A18: lwc1        $f0, -0x4CD8($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X4CD8);
    // 0x80060A1C: swc1        $f4, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->f4.u32l;
    // 0x80060A20: lwc1        $f2, 0xC($s2)
    ctx->f2.u32l = MEM_W(ctx->r18, 0XC);
    // 0x80060A24: mul.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x80060A28: mov.s       $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.fl = ctx->f4.fl;
    // 0x80060A2C: sub.s       $f2, $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = ctx->f2.fl - ctx->f4.fl;
    // 0x80060A30: swc1        $f0, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f0.u32l;
    // 0x80060A34: swc1        $f0, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->f0.u32l;
    // 0x80060A38: swc1        $f2, 0x4C($s0)
    MEM_W(0X4C, ctx->r16) = ctx->f2.u32l;
    // 0x80060A3C: lw          $v0, 0x4($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X4);
    // 0x80060A40: beq         $v0, $zero, L_80060A68
    if (ctx->r2 == 0) {
        // 0x80060A44: nop
    
            goto L_80060A68;
    }
    // 0x80060A44: nop

    // 0x80060A48: lbu         $v0, 0x0($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X0);
    // 0x80060A4C: sb          $v0, 0x2C($s0)
    MEM_B(0X2C, ctx->r16) = ctx->r2;
    // 0x80060A50: lw          $v0, 0x4($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X4);
    // 0x80060A54: lbu         $v0, 0x1($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X1);
    // 0x80060A58: sb          $v0, 0x2D($s0)
    MEM_B(0X2D, ctx->r16) = ctx->r2;
    // 0x80060A5C: lw          $v0, 0x4($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X4);
    // 0x80060A60: lbu         $v0, 0x2($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X2);
    // 0x80060A64: sb          $v0, 0x2E($s0)
    MEM_B(0X2E, ctx->r16) = ctx->r2;
L_80060A68:
    // 0x80060A68: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x80060A6C: lw          $t0, 0x0($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X0);
    // 0x80060A70: lw          $t1, 0x4($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X4);
    // 0x80060A74: lw          $t2, 0x8($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X8);
    // 0x80060A78: sw          $t0, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->r8;
    // 0x80060A7C: sw          $t1, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->r9;
    // 0x80060A80: sw          $t2, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->r10;
    // 0x80060A84: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x80060A88: sw          $zero, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = 0;
    // 0x80060A8C: sw          $zero, 0x40($s0)
    MEM_W(0X40, ctx->r16) = 0;
    // 0x80060A90: lhu         $a0, -0x6A8C($v0)
    ctx->r4 = MEM_HU(ctx->r2, -0X6A8C);
    // 0x80060A94: jal         0x8003E684
    // 0x80060A98: addu        $a1, $s3, $zero
    ctx->r5 = ADD32(ctx->r19, 0);
    func_8003E684(rdram, ctx);
        goto after_2;
    // 0x80060A98: addu        $a1, $s3, $zero
    ctx->r5 = ADD32(ctx->r19, 0);
    after_2:
    // 0x80060A9C: j           L_80060D70
    // 0x80060AA0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80060D70;
    // 0x80060AA0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80060AA4:
    // 0x80060AA4: lwc1        $f2, 0x40($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X40);
    // 0x80060AA8: lwc1        $f0, 0x0($a2)
    ctx->f0.u32l = MEM_W(ctx->r6, 0X0);
    // 0x80060AAC: add.s       $f6, $f2, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x80060AB0: lbu         $v1, 0x50($s0)
    ctx->r3 = MEM_BU(ctx->r16, 0X50);
    // 0x80060AB4: beq         $v1, $zero, L_80060AC8
    if (ctx->r3 == 0) {
        // 0x80060AB8: swc1        $f6, 0x40($s0)
        MEM_W(0X40, ctx->r16) = ctx->f6.u32l;
            goto L_80060AC8;
    }
    // 0x80060AB8: swc1        $f6, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->f6.u32l;
    // 0x80060ABC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80060AC0: beq         $v1, $v0, L_80060B80
    if (ctx->r3 == ctx->r2) {
        // 0x80060AC4: nop
    
            goto L_80060B80;
    }
    // 0x80060AC4: nop

L_80060AC8:
    // 0x80060AC8: lwc1        $f2, 0x0($a2)
    ctx->f2.u32l = MEM_W(ctx->r6, 0X0);
    // 0x80060ACC: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80060AD0: lwc1        $f0, -0x4CD4($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X4CD4);
    // 0x80060AD4: mul.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x80060AD8: lwc1        $f0, 0x3C($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X3C);
    // 0x80060ADC: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x80060AE0: swc1        $f0, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = ctx->f0.u32l;
    // 0x80060AE4: lwc1        $f0, 0x4C($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X4C);
    // 0x80060AE8: lwc1        $f2, 0x0($a2)
    ctx->f2.u32l = MEM_W(ctx->r6, 0X0);
    // 0x80060AEC: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x80060AF0: lwc1        $f2, 0x48($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X48);
    // 0x80060AF4: lwc1        $f4, 0x40($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X40);
    // 0x80060AF8: add.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x80060AFC: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80060B00: lwc1        $f0, -0x4CD0($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X4CD0);
    // 0x80060B04: c.le.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl <= ctx->f4.fl;
    // 0x80060B08: swc1        $f2, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->f2.u32l;
    // 0x80060B0C: swc1        $f2, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f2.u32l;
    // 0x80060B10: bc1f        L_80060D6C
    if (!c1cs) {
        // 0x80060B14: swc1        $f2, 0x20($s0)
        MEM_W(0X20, ctx->r16) = ctx->f2.u32l;
            goto L_80060D6C;
    }
    // 0x80060B14: swc1        $f2, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->f2.u32l;
    // 0x80060B18: lwc1        $f0, 0x0($a2)
    ctx->f0.u32l = MEM_W(ctx->r6, 0X0);
    // 0x80060B1C: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80060B20: lwc1        $f2, -0x4CCC($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X4CCC);
    // 0x80060B24: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x80060B28: lwc1        $f2, 0x44($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X44);
    // 0x80060B2C: sub.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl - ctx->f0.fl;
    // 0x80060B30: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80060B34: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x80060B38: nop

    // 0x80060B3C: bc1f        L_80060B6C
    if (!c1cs) {
        // 0x80060B40: swc1        $f2, 0x44($s0)
        MEM_W(0X44, ctx->r16) = ctx->f2.u32l;
            goto L_80060B6C;
    }
    // 0x80060B40: swc1        $f2, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->f2.u32l;
    // 0x80060B44: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80060B48: lwc1        $f0, -0x4CC8($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X4CC8);
    // 0x80060B4C: c.le.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl <= ctx->f2.fl;
    // 0x80060B50: nop

    // 0x80060B54: bc1tl       L_80060C14
    if (c1cs) {
        // 0x80060B58: sub.s       $f0, $f2, $f0
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f2.fl - ctx->f0.fl;
            goto L_80060C14;
    }
    goto skip_1;
    // 0x80060B58: sub.s       $f0, $f2, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f2.fl - ctx->f0.fl;
    skip_1:
    // 0x80060B5C: trunc.w.s   $f8, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    ctx->f8.u32l = TRUNC_W_S(ctx->f2.fl);
    // 0x80060B60: mfc1        $v1, $f8
    ctx->r3 = (int32_t)ctx->f8.u32l;
    // 0x80060B64: j           L_80060D6C
    // 0x80060B68: sb          $v1, 0x2F($s0)
    MEM_B(0X2F, ctx->r16) = ctx->r3;
        goto L_80060D6C;
    // 0x80060B68: sb          $v1, 0x2F($s0)
    MEM_B(0X2F, ctx->r16) = ctx->r3;
L_80060B6C:
    // 0x80060B6C: lhu         $a0, 0x16($s3)
    ctx->r4 = MEM_HU(ctx->r19, 0X16);
    // 0x80060B70: jal         0x8003ED74
    // 0x80060B74: nop

    func_8003ED74(rdram, ctx);
        goto after_3;
    // 0x80060B74: nop

    after_3:
    // 0x80060B78: j           L_80060D70
    // 0x80060B7C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80060D70;
    // 0x80060B7C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80060B80:
    // 0x80060B80: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80060B84: lwc1        $f0, -0x4CC4($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X4CC4);
    // 0x80060B88: mul.s       $f0, $f6, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x80060B8C: lwc1        $f2, 0x40($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X40);
    // 0x80060B90: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80060B94: lwc1        $f4, -0x4CC0($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X4CC0);
    // 0x80060B98: mul.s       $f2, $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f4.fl);
    // 0x80060B9C: add.s       $f0, $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f0.fl;
    // 0x80060BA0: add.s       $f2, $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f2.fl;
    // 0x80060BA4: swc1        $f0, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = ctx->f0.u32l;
    // 0x80060BA8: sub.s       $f4, $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = ctx->f4.fl - ctx->f2.fl;
    // 0x80060BAC: lwc1        $f0, 0x4C($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X4C);
    // 0x80060BB0: swc1        $f4, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->f4.u32l;
    // 0x80060BB4: lwc1        $f2, 0x0($a2)
    ctx->f2.u32l = MEM_W(ctx->r6, 0X0);
    // 0x80060BB8: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x80060BBC: add.s       $f0, $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f0.fl;
    // 0x80060BC0: lwc1        $f2, 0x48($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X48);
    // 0x80060BC4: lwc1        $f4, 0x40($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X40);
    // 0x80060BC8: add.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x80060BCC: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80060BD0: lwc1        $f0, -0x4CBC($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X4CBC);
    // 0x80060BD4: c.le.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl <= ctx->f0.fl;
    // 0x80060BD8: swc1        $f2, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->f2.u32l;
    // 0x80060BDC: swc1        $f2, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f2.u32l;
    // 0x80060BE0: bc1f        L_80060B6C
    if (!c1cs) {
        // 0x80060BE4: swc1        $f2, 0x20($s0)
        MEM_W(0X20, ctx->r16) = ctx->f2.u32l;
            goto L_80060B6C;
    }
    // 0x80060BE4: swc1        $f2, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->f2.u32l;
    // 0x80060BE8: lwc1        $f0, 0x44($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X44);
    // 0x80060BEC: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80060BF0: lwc1        $f2, -0x4CB8($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X4CB8);
    // 0x80060BF4: c.le.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl <= ctx->f0.fl;
    // 0x80060BF8: nop

    // 0x80060BFC: bc1tl       L_80060C14
    if (c1cs) {
        // 0x80060C00: sub.s       $f0, $f0, $f2
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
            goto L_80060C14;
    }
    goto skip_2;
    // 0x80060C00: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    skip_2:
    // 0x80060C04: trunc.w.s   $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    ctx->f8.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x80060C08: mfc1        $v1, $f8
    ctx->r3 = (int32_t)ctx->f8.u32l;
    // 0x80060C0C: j           L_80060D6C
    // 0x80060C10: sb          $v1, 0x2F($s0)
    MEM_B(0X2F, ctx->r16) = ctx->r3;
        goto L_80060D6C;
    // 0x80060C10: sb          $v1, 0x2F($s0)
    MEM_B(0X2F, ctx->r16) = ctx->r3;
L_80060C14:
    // 0x80060C14: lui         $v0, 0x8000
    ctx->r2 = S32(0X8000 << 16);
    // 0x80060C18: trunc.w.s   $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    ctx->f8.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x80060C1C: mfc1        $v1, $f8
    ctx->r3 = (int32_t)ctx->f8.u32l;
    // 0x80060C20: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x80060C24: j           L_80060D6C
    // 0x80060C28: sb          $v1, 0x2F($s0)
    MEM_B(0X2F, ctx->r16) = ctx->r3;
        goto L_80060D6C;
    // 0x80060C28: sb          $v1, 0x2F($s0)
    MEM_B(0X2F, ctx->r16) = ctx->r3;
L_80060C2C:
    // 0x80060C2C: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x80060C30: addu        $s1, $a2, $zero
    ctx->r17 = ADD32(ctx->r6, 0);
    // 0x80060C34: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80060C38: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x80060C3C: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x80060C40: jal         0x8001DC34
    // 0x80060C44: addiu       $a2, $s0, 0x30
    ctx->r6 = ADD32(ctx->r16, 0X30);
    func_8001DC34(rdram, ctx);
        goto after_4;
    // 0x80060C44: addiu       $a2, $s0, 0x30
    ctx->r6 = ADD32(ctx->r16, 0X30);
    after_4:
    // 0x80060C48: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x80060C4C: beq         $v0, $zero, L_80060D70
    if (ctx->r2 == 0) {
        // 0x80060C50: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80060D70;
    }
    // 0x80060C50: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80060C54: lbu         $v1, 0x50($s0)
    ctx->r3 = MEM_BU(ctx->r16, 0X50);
    // 0x80060C58: beql        $v1, $zero, L_80060C68
    if (ctx->r3 == 0) {
        // 0x80060C5C: lui         $v0, 0x2AAA
        ctx->r2 = S32(0X2AAA << 16);
            goto L_80060C68;
    }
    goto skip_3;
    // 0x80060C5C: lui         $v0, 0x2AAA
    ctx->r2 = S32(0X2AAA << 16);
    skip_3:
    // 0x80060C60: beq         $v1, $v0, L_80060CB4
    if (ctx->r3 == ctx->r2) {
        // 0x80060C64: lui         $v0, 0x2AAA
        ctx->r2 = S32(0X2AAA << 16);
            goto L_80060CB4;
    }
    // 0x80060C64: lui         $v0, 0x2AAA
    ctx->r2 = S32(0X2AAA << 16);
L_80060C68:
    // 0x80060C68: lwc1        $f0, 0x3C($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X3C);
    // 0x80060C6C: ori         $v0, $v0, 0xAAAB
    ctx->r2 = ctx->r2 | 0XAAAB;
    // 0x80060C70: trunc.w.s   $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    ctx->f8.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x80060C74: mfc1        $a0, $f8
    ctx->r4 = (int32_t)ctx->f8.u32l;
    // 0x80060C78: mult        $a0, $v0
    result = S64(S32(ctx->r4)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80060C7C: lui         $a1, 0x8014
    ctx->r5 = S32(0X8014 << 16);
    // 0x80060C80: addiu       $a1, $a1, -0x6700
    ctx->r5 = ADD32(ctx->r5, -0X6700);
    // 0x80060C84: sra         $v1, $a0, 31
    ctx->r3 = S32(SIGNED(ctx->r4) >> 31);
    // 0x80060C88: mfhi        $t0
    ctx->r8 = hi;
    // 0x80060C8C: subu        $v1, $t0, $v1
    ctx->r3 = SUB32(ctx->r8, ctx->r3);
    // 0x80060C90: sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3 << 1);
    // 0x80060C94: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80060C98: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x80060C9C: subu        $a0, $a0, $v0
    ctx->r4 = SUB32(ctx->r4, ctx->r2);
    // 0x80060CA0: sll         $a0, $a0, 1
    ctx->r4 = S32(ctx->r4 << 1);
    // 0x80060CA4: addu        $a0, $a0, $a1
    ctx->r4 = ADD32(ctx->r4, ctx->r5);
    // 0x80060CA8: lhu         $v0, 0x0($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X0);
    // 0x80060CAC: j           L_80060CF0
    // 0x80060CB0: sh          $v0, 0x12($s0)
    MEM_H(0X12, ctx->r16) = ctx->r2;
        goto L_80060CF0;
    // 0x80060CB0: sh          $v0, 0x12($s0)
    MEM_H(0X12, ctx->r16) = ctx->r2;
L_80060CB4:
    // 0x80060CB4: lwc1        $f0, 0x3C($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X3C);
    // 0x80060CB8: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x80060CBC: addiu       $a1, $v0, -0x66F0
    ctx->r5 = ADD32(ctx->r2, -0X66F0);
    // 0x80060CC0: trunc.w.s   $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    ctx->f8.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x80060CC4: mfc1        $v1, $f8
    ctx->r3 = (int32_t)ctx->f8.u32l;
    // 0x80060CC8: bgez        $v1, L_80060CD4
    if (SIGNED(ctx->r3) >= 0) {
        // 0x80060CCC: addu        $a0, $v1, $zero
        ctx->r4 = ADD32(ctx->r3, 0);
            goto L_80060CD4;
    }
    // 0x80060CCC: addu        $a0, $v1, $zero
    ctx->r4 = ADD32(ctx->r3, 0);
    // 0x80060CD0: addiu       $a0, $v1, 0x7
    ctx->r4 = ADD32(ctx->r3, 0X7);
L_80060CD4:
    // 0x80060CD4: sra         $v0, $a0, 3
    ctx->r2 = S32(SIGNED(ctx->r4) >> 3);
    // 0x80060CD8: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x80060CDC: subu        $v0, $v1, $v0
    ctx->r2 = SUB32(ctx->r3, ctx->r2);
    // 0x80060CE0: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x80060CE4: addu        $v0, $v0, $a1
    ctx->r2 = ADD32(ctx->r2, ctx->r5);
    // 0x80060CE8: lhu         $v0, 0x0($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X0);
    // 0x80060CEC: sh          $v0, 0x12($s0)
    MEM_H(0X12, ctx->r16) = ctx->r2;
L_80060CF0:
    // 0x80060CF0: lwc1        $f0, 0x30($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X30);
    // 0x80060CF4: lwc1        $f2, 0x18($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0X18);
    // 0x80060CF8: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x80060CFC: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80060D00: lwc1        $f4, -0x4CB4($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X4CB4);
    // 0x80060D04: mul.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x80060D08: trunc.w.s   $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    ctx->f8.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x80060D0C: mfc1        $v0, $f8
    ctx->r2 = (int32_t)ctx->f8.u32l;
    // 0x80060D10: lwc1        $f0, 0x34($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X34);
    // 0x80060D14: sh          $v0, 0x8($s0)
    MEM_H(0X8, ctx->r16) = ctx->r2;
    // 0x80060D18: lwc1        $f2, 0x1C($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0X1C);
    // 0x80060D1C: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x80060D20: mul.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x80060D24: trunc.w.s   $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    ctx->f8.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x80060D28: mfc1        $v0, $f8
    ctx->r2 = (int32_t)ctx->f8.u32l;
    // 0x80060D2C: lwc1        $f0, 0x38($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X38);
    // 0x80060D30: sh          $v0, 0xA($s0)
    MEM_H(0XA, ctx->r16) = ctx->r2;
    // 0x80060D34: lwc1        $f2, 0x20($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0X20);
    // 0x80060D38: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x80060D3C: mul.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x80060D40: trunc.w.s   $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    ctx->f8.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x80060D44: mfc1        $v0, $f8
    ctx->r2 = (int32_t)ctx->f8.u32l;
    // 0x80060D48: sh          $v0, 0xC($s0)
    MEM_H(0XC, ctx->r16) = ctx->r2;
    // 0x80060D4C: lw          $v0, 0x48($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X48);
    // 0x80060D50: lw          $v0, 0x20($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X20);
    // 0x80060D54: beq         $v0, $zero, L_80060D60
    if (ctx->r2 == 0) {
        // 0x80060D58: sw          $v0, 0x0($s0)
        MEM_W(0X0, ctx->r16) = ctx->r2;
            goto L_80060D60;
    }
    // 0x80060D58: sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
    // 0x80060D5C: sw          $s0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r16;
L_80060D60:
    // 0x80060D60: sw          $zero, 0x4($s0)
    MEM_W(0X4, ctx->r16) = 0;
    // 0x80060D64: lw          $v0, 0x48($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X48);
    // 0x80060D68: sw          $s0, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->r16;
L_80060D6C:
    // 0x80060D6C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80060D70:
    // 0x80060D70: lw          $ra, 0x28($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X28);
    // 0x80060D74: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x80060D78: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80060D7C: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80060D80: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80060D84: jr          $ra
    // 0x80060D88: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x80060D88: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_80060D8C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80060D8C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80060D90: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80060D94: addu        $s2, $a0, $zero
    ctx->r18 = ADD32(ctx->r4, 0);
    // 0x80060D98: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80060D9C: andi        $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 & 0XFFFF;
    // 0x80060DA0: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x80060DA4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80060DA8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80060DAC: lw          $s0, 0x4($s2)
    ctx->r16 = MEM_W(ctx->r18, 0X4);
    // 0x80060DB0: beq         $a1, $v0, L_80061070
    if (ctx->r5 == ctx->r2) {
        // 0x80060DB4: addu        $s1, $a2, $zero
        ctx->r17 = ADD32(ctx->r6, 0);
            goto L_80061070;
    }
    // 0x80060DB4: addu        $s1, $a2, $zero
    ctx->r17 = ADD32(ctx->r6, 0);
    // 0x80060DB8: slti        $v0, $a1, 0x3
    ctx->r2 = SIGNED(ctx->r5) < 0X3 ? 1 : 0;
    // 0x80060DBC: beq         $v0, $zero, L_80060DD4
    if (ctx->r2 == 0) {
        // 0x80060DC0: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80060DD4;
    }
    // 0x80060DC0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80060DC4: beq         $a1, $v0, L_80060DF0
    if (ctx->r5 == ctx->r2) {
        // 0x80060DC8: addiu       $v0, $zero, 0x300
        ctx->r2 = ADD32(0, 0X300);
            goto L_80060DF0;
    }
    // 0x80060DC8: addiu       $v0, $zero, 0x300
    ctx->r2 = ADD32(0, 0X300);
    // 0x80060DCC: j           L_80061074
    // 0x80060DD0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80061074;
    // 0x80060DD0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80060DD4:
    // 0x80060DD4: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x80060DD8: beq         $a1, $v0, L_80060F0C
    if (ctx->r5 == ctx->r2) {
        // 0x80060DDC: addiu       $v0, $zero, 0x4
        ctx->r2 = ADD32(0, 0X4);
            goto L_80060F0C;
    }
    // 0x80060DDC: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // 0x80060DE0: beq         $a1, $v0, L_80060FD0
    if (ctx->r5 == ctx->r2) {
        // 0x80060DE4: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80060FD0;
    }
    // 0x80060DE4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80060DE8: j           L_80061074
    // 0x80060DEC: nop

        goto L_80061074;
    // 0x80060DEC: nop

L_80060DF0:
    // 0x80060DF0: jal         0x80003430
    // 0x80060DF4: sh          $v0, 0x10($s0)
    MEM_H(0X10, ctx->r16) = ctx->r2;
    rand_recomp(rdram, ctx);
        goto after_0;
    // 0x80060DF4: sh          $v0, 0x10($s0)
    MEM_H(0X10, ctx->r16) = ctx->r2;
    after_0:
    // 0x80060DF8: lhu         $v1, 0x10($s0)
    ctx->r3 = MEM_HU(ctx->r16, 0X10);
    // 0x80060DFC: andi        $v0, $v0, 0x1C00
    ctx->r2 = ctx->r2 & 0X1C00;
    // 0x80060E00: sw          $zero, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = 0;
    // 0x80060E04: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x80060E08: sh          $v1, 0x10($s0)
    MEM_H(0X10, ctx->r16) = ctx->r3;
    // 0x80060E0C: lw          $v0, 0x8($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X8);
    // 0x80060E10: lbu         $v0, 0x0($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X0);
    // 0x80060E14: sb          $v0, 0x2C($s0)
    MEM_B(0X2C, ctx->r16) = ctx->r2;
    // 0x80060E18: lw          $v0, 0x8($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X8);
    // 0x80060E1C: lbu         $v0, 0x1($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X1);
    // 0x80060E20: sb          $v0, 0x2D($s0)
    MEM_B(0X2D, ctx->r16) = ctx->r2;
    // 0x80060E24: lw          $v0, 0x8($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X8);
    // 0x80060E28: lbu         $v0, 0x2($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X2);
    // 0x80060E2C: sb          $v0, 0x2E($s0)
    MEM_B(0X2E, ctx->r16) = ctx->r2;
    // 0x80060E30: lw          $v0, 0x8($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X8);
    // 0x80060E34: lbu         $v0, 0x3($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X3);
    // 0x80060E38: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80060E3C: lwc1        $f2, -0x4CB0($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X4CB0);
    // 0x80060E40: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x80060E44: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x80060E48: c.le.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl <= ctx->f0.fl;
    // 0x80060E4C: nop

    // 0x80060E50: bc1t        L_80060E68
    if (c1cs) {
        // 0x80060E54: swc1        $f0, 0x44($s0)
        MEM_W(0X44, ctx->r16) = ctx->f0.u32l;
            goto L_80060E68;
    }
    // 0x80060E54: swc1        $f0, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->f0.u32l;
    // 0x80060E58: trunc.w.s   $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    ctx->f8.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x80060E5C: mfc1        $v1, $f8
    ctx->r3 = (int32_t)ctx->f8.u32l;
    // 0x80060E60: j           L_80060E80
    // 0x80060E64: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
        goto L_80060E80;
    // 0x80060E64: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
L_80060E68:
    // 0x80060E68: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x80060E6C: lui         $v0, 0x8000
    ctx->r2 = S32(0X8000 << 16);
    // 0x80060E70: trunc.w.s   $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    ctx->f8.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x80060E74: mfc1        $v1, $f8
    ctx->r3 = (int32_t)ctx->f8.u32l;
    // 0x80060E78: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x80060E7C: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
L_80060E80:
    // 0x80060E80: sb          $v1, 0x2F($s0)
    MEM_B(0X2F, ctx->r16) = ctx->r3;
    // 0x80060E84: lhu         $v0, -0x66F4($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X66F4);
    // 0x80060E88: jal         0x80003430
    // 0x80060E8C: sh          $v0, 0x12($s0)
    MEM_H(0X12, ctx->r16) = ctx->r2;
    rand_recomp(rdram, ctx);
        goto after_1;
    // 0x80060E8C: sh          $v0, 0x12($s0)
    MEM_H(0X12, ctx->r16) = ctx->r2;
    after_1:
    // 0x80060E90: lwc1        $f6, 0x4($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X4);
    // 0x80060E94: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80060E98: lwc1        $f0, -0x4CAC($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X4CAC);
    // 0x80060E9C: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x80060EA0: mul.s       $f6, $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x80060EA4: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80060EA8: lwc1        $f2, -0x4CA8($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X4CA8);
    // 0x80060EAC: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80060EB0: lwc1        $f4, -0x4CA4($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X4CA4);
    // 0x80060EB4: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x80060EB8: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x80060EBC: div.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f2.fl);
    // 0x80060EC0: add.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f4.fl;
    // 0x80060EC4: mul.s       $f0, $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x80060EC8: swc1        $f0, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f0.u32l;
    // 0x80060ECC: swc1        $f0, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->f0.u32l;
    // 0x80060ED0: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x80060ED4: lw          $t1, 0x0($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X0);
    // 0x80060ED8: lw          $t2, 0x4($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X4);
    // 0x80060EDC: lw          $t3, 0x8($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X8);
    // 0x80060EE0: sw          $t1, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->r9;
    // 0x80060EE4: sw          $t2, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->r10;
    // 0x80060EE8: sw          $t3, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->r11;
    // 0x80060EEC: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x80060EF0: sw          $zero, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = 0;
    // 0x80060EF4: sw          $zero, 0x40($s0)
    MEM_W(0X40, ctx->r16) = 0;
    // 0x80060EF8: lhu         $a0, -0x6A8C($v0)
    ctx->r4 = MEM_HU(ctx->r2, -0X6A8C);
    // 0x80060EFC: jal         0x8003E684
    // 0x80060F00: addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    func_8003E684(rdram, ctx);
        goto after_2;
    // 0x80060F00: addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    after_2:
    // 0x80060F04: j           L_80061074
    // 0x80060F08: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80061074;
    // 0x80060F08: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80060F0C:
    // 0x80060F0C: lwc1        $f0, 0x40($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X40);
    // 0x80060F10: lwc1        $f2, 0x0($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0X0);
    // 0x80060F14: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x80060F18: swc1        $f0, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->f0.u32l;
    // 0x80060F1C: lwc1        $f6, 0x0($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X0);
    // 0x80060F20: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80060F24: lwc1        $f0, -0x4CA0($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X4CA0);
    // 0x80060F28: mul.s       $f6, $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x80060F2C: lwc1        $f4, 0x20($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X20);
    // 0x80060F30: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80060F34: lwc1        $f0, -0x4C9C($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X4C9C);
    // 0x80060F38: mul.s       $f4, $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x80060F3C: lwc1        $f2, 0x24($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X24);
    // 0x80060F40: mul.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x80060F44: lwc1        $f0, 0x44($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X44);
    // 0x80060F48: sub.s       $f0, $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f6.fl;
    // 0x80060F4C: swc1        $f2, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f2.u32l;
    // 0x80060F50: lwc1        $f2, 0x34($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X34);
    // 0x80060F54: swc1        $f4, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->f4.u32l;
    // 0x80060F58: swc1        $f0, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->f0.u32l;
    // 0x80060F5C: lwc1        $f0, 0x0($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X0);
    // 0x80060F60: lwc1        $f4, 0x44($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X44);
    // 0x80060F64: sub.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl - ctx->f0.fl;
    // 0x80060F68: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80060F6C: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x80060F70: nop

    // 0x80060F74: bc1f        L_80060FBC
    if (!c1cs) {
        // 0x80060F78: swc1        $f2, 0x34($s0)
        MEM_W(0X34, ctx->r16) = ctx->f2.u32l;
            goto L_80060FBC;
    }
    // 0x80060F78: swc1        $f2, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->f2.u32l;
    // 0x80060F7C: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80060F80: lwc1        $f0, -0x4C98($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X4C98);
    // 0x80060F84: c.le.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl <= ctx->f4.fl;
    // 0x80060F88: nop

    // 0x80060F8C: bc1tl       L_80060FA4
    if (c1cs) {
        // 0x80060F90: sub.s       $f0, $f4, $f0
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f0.fl;
            goto L_80060FA4;
    }
    goto skip_0;
    // 0x80060F90: sub.s       $f0, $f4, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f0.fl;
    skip_0:
    // 0x80060F94: trunc.w.s   $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x80060F98: mfc1        $v1, $f8
    ctx->r3 = (int32_t)ctx->f8.u32l;
    // 0x80060F9C: j           L_80061070
    // 0x80060FA0: sb          $v1, 0x2F($s0)
    MEM_B(0X2F, ctx->r16) = ctx->r3;
        goto L_80061070;
    // 0x80060FA0: sb          $v1, 0x2F($s0)
    MEM_B(0X2F, ctx->r16) = ctx->r3;
L_80060FA4:
    // 0x80060FA4: lui         $v0, 0x8000
    ctx->r2 = S32(0X8000 << 16);
    // 0x80060FA8: trunc.w.s   $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    ctx->f8.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x80060FAC: mfc1        $v1, $f8
    ctx->r3 = (int32_t)ctx->f8.u32l;
    // 0x80060FB0: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x80060FB4: j           L_80061070
    // 0x80060FB8: sb          $v1, 0x2F($s0)
    MEM_B(0X2F, ctx->r16) = ctx->r3;
        goto L_80061070;
    // 0x80060FB8: sb          $v1, 0x2F($s0)
    MEM_B(0X2F, ctx->r16) = ctx->r3;
L_80060FBC:
    // 0x80060FBC: lhu         $a0, 0x16($s2)
    ctx->r4 = MEM_HU(ctx->r18, 0X16);
    // 0x80060FC0: jal         0x8003ED74
    // 0x80060FC4: nop

    func_8003ED74(rdram, ctx);
        goto after_3;
    // 0x80060FC4: nop

    after_3:
    // 0x80060FC8: j           L_80061074
    // 0x80060FCC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80061074;
    // 0x80060FCC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80060FD0:
    // 0x80060FD0: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x80060FD4: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80060FD8: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x80060FDC: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x80060FE0: jal         0x8001DC34
    // 0x80060FE4: addiu       $a2, $s0, 0x30
    ctx->r6 = ADD32(ctx->r16, 0X30);
    func_8001DC34(rdram, ctx);
        goto after_4;
    // 0x80060FE4: addiu       $a2, $s0, 0x30
    ctx->r6 = ADD32(ctx->r16, 0X30);
    after_4:
    // 0x80060FE8: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x80060FEC: beq         $v0, $zero, L_80061074
    if (ctx->r2 == 0) {
        // 0x80060FF0: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80061074;
    }
    // 0x80060FF0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80060FF4: lwc1        $f0, 0x30($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X30);
    // 0x80060FF8: lwc1        $f2, 0x18($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0X18);
    // 0x80060FFC: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x80061000: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80061004: lwc1        $f4, -0x4C94($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X4C94);
    // 0x80061008: mul.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x8006100C: trunc.w.s   $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    ctx->f8.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x80061010: mfc1        $v0, $f8
    ctx->r2 = (int32_t)ctx->f8.u32l;
    // 0x80061014: lwc1        $f0, 0x34($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X34);
    // 0x80061018: sh          $v0, 0x8($s0)
    MEM_H(0X8, ctx->r16) = ctx->r2;
    // 0x8006101C: lwc1        $f2, 0x1C($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0X1C);
    // 0x80061020: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x80061024: mul.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x80061028: trunc.w.s   $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    ctx->f8.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x8006102C: mfc1        $v0, $f8
    ctx->r2 = (int32_t)ctx->f8.u32l;
    // 0x80061030: lwc1        $f0, 0x38($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X38);
    // 0x80061034: sh          $v0, 0xA($s0)
    MEM_H(0XA, ctx->r16) = ctx->r2;
    // 0x80061038: lwc1        $f2, 0x20($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0X20);
    // 0x8006103C: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x80061040: mul.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x80061044: trunc.w.s   $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    ctx->f8.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x80061048: mfc1        $v0, $f8
    ctx->r2 = (int32_t)ctx->f8.u32l;
    // 0x8006104C: sh          $v0, 0xC($s0)
    MEM_H(0XC, ctx->r16) = ctx->r2;
    // 0x80061050: lw          $v0, 0x48($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X48);
    // 0x80061054: lw          $v0, 0x20($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X20);
    // 0x80061058: beq         $v0, $zero, L_80061064
    if (ctx->r2 == 0) {
        // 0x8006105C: sw          $v0, 0x0($s0)
        MEM_W(0X0, ctx->r16) = ctx->r2;
            goto L_80061064;
    }
    // 0x8006105C: sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
    // 0x80061060: sw          $s0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r16;
L_80061064:
    // 0x80061064: sw          $zero, 0x4($s0)
    MEM_W(0X4, ctx->r16) = 0;
    // 0x80061068: lw          $v0, 0x48($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X48);
    // 0x8006106C: sw          $s0, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->r16;
L_80061070:
    // 0x80061070: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80061074:
    // 0x80061074: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80061078: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8006107C: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80061080: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80061084: jr          $ra
    // 0x80061088: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80061088: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_8006108C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006108C: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80061090: lbu         $v0, 0xB63($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0XB63);
    // 0x80061094: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80061098: bne         $v0, $zero, L_800610D8
    if (ctx->r2 != 0) {
        // 0x8006109C: sw          $ra, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r31;
            goto L_800610D8;
    }
    // 0x8006109C: sw          $ra, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r31;
    // 0x800610A0: jal         0x8006B180
    // 0x800610A4: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    func_8006B180(rdram, ctx);
        goto after_0;
    // 0x800610A4: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    after_0:
    // 0x800610A8: bne         $v0, $zero, L_800610B4
    if (ctx->r2 != 0) {
        // 0x800610AC: addu        $v1, $zero, $zero
        ctx->r3 = ADD32(0, 0);
            goto L_800610B4;
    }
    // 0x800610AC: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
    // 0x800610B0: addiu       $v1, $zero, 0x3
    ctx->r3 = ADD32(0, 0X3);
L_800610B4:
    // 0x800610B4: sw          $v1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r3;
    // 0x800610B8: lui         $a0, 0x8004
    ctx->r4 = S32(0X8004 << 16);
    // 0x800610BC: addiu       $a0, $a0, -0x4C90
    ctx->r4 = ADD32(ctx->r4, -0X4C90);
    // 0x800610C0: lui         $a1, 0x8004
    ctx->r5 = S32(0X8004 << 16);
    // 0x800610C4: addiu       $a1, $a1, -0x4C84
    ctx->r5 = ADD32(ctx->r5, -0X4C84);
    // 0x800610C8: lui         $a2, 0x8014
    ctx->r6 = S32(0X8014 << 16);
    // 0x800610CC: addiu       $a2, $a2, -0x6790
    ctx->r6 = ADD32(ctx->r6, -0X6790);
    // 0x800610D0: j           L_8006111C
    // 0x800610D4: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
        goto L_8006111C;
    // 0x800610D4: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
L_800610D8:
    // 0x800610D8: lui         $a0, 0x8004
    ctx->r4 = S32(0X8004 << 16);
    // 0x800610DC: addiu       $a0, $a0, -0x4C90
    ctx->r4 = ADD32(ctx->r4, -0X4C90);
    // 0x800610E0: lui         $a1, 0x8004
    ctx->r5 = S32(0X8004 << 16);
    // 0x800610E4: addiu       $a1, $a1, -0x4C84
    ctx->r5 = ADD32(ctx->r5, -0X4C84);
    // 0x800610E8: lui         $a2, 0x8014
    ctx->r6 = S32(0X8014 << 16);
    // 0x800610EC: addiu       $a2, $a2, -0x6790
    ctx->r6 = ADD32(ctx->r6, -0X6790);
    // 0x800610F0: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    // 0x800610F4: jal         0x80054EF0
    // 0x800610F8: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    func_80054EF0(rdram, ctx);
        goto after_1;
    // 0x800610F8: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_1:
    // 0x800610FC: lui         $a0, 0x8004
    ctx->r4 = S32(0X8004 << 16);
    // 0x80061100: addiu       $a0, $a0, -0x4C78
    ctx->r4 = ADD32(ctx->r4, -0X4C78);
    // 0x80061104: lui         $a1, 0x8004
    ctx->r5 = S32(0X8004 << 16);
    // 0x80061108: addiu       $a1, $a1, -0x4C68
    ctx->r5 = ADD32(ctx->r5, -0X4C68);
    // 0x8006110C: lui         $a2, 0x8014
    ctx->r6 = S32(0X8014 << 16);
    // 0x80061110: addiu       $a2, $a2, -0x6768
    ctx->r6 = ADD32(ctx->r6, -0X6768);
    // 0x80061114: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    // 0x80061118: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
L_8006111C:
    // 0x8006111C: jal         0x80054EF0
    // 0x80061120: nop

    func_80054EF0(rdram, ctx);
        goto after_2;
    // 0x80061120: nop

    after_2:
    // 0x80061124: lui         $a0, 0x8004
    ctx->r4 = S32(0X8004 << 16);
    // 0x80061128: addiu       $a0, $a0, -0x4C5C
    ctx->r4 = ADD32(ctx->r4, -0X4C5C);
    // 0x8006112C: lui         $a1, 0x8004
    ctx->r5 = S32(0X8004 << 16);
    // 0x80061130: addiu       $a1, $a1, -0x4C50
    ctx->r5 = ADD32(ctx->r5, -0X4C50);
    // 0x80061134: lui         $a2, 0x8014
    ctx->r6 = S32(0X8014 << 16);
    // 0x80061138: addiu       $a2, $a2, -0x6700
    ctx->r6 = ADD32(ctx->r6, -0X6700);
    // 0x8006113C: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    // 0x80061140: jal         0x80054EF0
    // 0x80061144: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    func_80054EF0(rdram, ctx);
        goto after_3;
    // 0x80061144: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_3:
    // 0x80061148: lui         $a0, 0x8004
    ctx->r4 = S32(0X8004 << 16);
    // 0x8006114C: addiu       $a0, $a0, -0x4C44
    ctx->r4 = ADD32(ctx->r4, -0X4C44);
    // 0x80061150: lui         $a1, 0x8004
    ctx->r5 = S32(0X8004 << 16);
    // 0x80061154: addiu       $a1, $a1, -0x4C38
    ctx->r5 = ADD32(ctx->r5, -0X4C38);
    // 0x80061158: lui         $a2, 0x8014
    ctx->r6 = S32(0X8014 << 16);
    // 0x8006115C: addiu       $a2, $a2, -0x66F0
    ctx->r6 = ADD32(ctx->r6, -0X66F0);
    // 0x80061160: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    // 0x80061164: jal         0x80054EF0
    // 0x80061168: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    func_80054EF0(rdram, ctx);
        goto after_4;
    // 0x80061168: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_4:
    // 0x8006116C: lui         $a0, 0x8004
    ctx->r4 = S32(0X8004 << 16);
    // 0x80061170: addiu       $a0, $a0, -0x4C2C
    ctx->r4 = ADD32(ctx->r4, -0X4C2C);
    // 0x80061174: lui         $a1, 0x8004
    ctx->r5 = S32(0X8004 << 16);
    // 0x80061178: addiu       $a1, $a1, -0x4C20
    ctx->r5 = ADD32(ctx->r5, -0X4C20);
    // 0x8006117C: lui         $a2, 0x8014
    ctx->r6 = S32(0X8014 << 16);
    // 0x80061180: addiu       $a2, $a2, -0x66F4
    ctx->r6 = ADD32(ctx->r6, -0X66F4);
    // 0x80061184: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    // 0x80061188: jal         0x80054EF0
    // 0x8006118C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    func_80054EF0(rdram, ctx);
        goto after_5;
    // 0x8006118C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_5:
    // 0x80061190: lui         $a0, 0x8004
    ctx->r4 = S32(0X8004 << 16);
    // 0x80061194: jal         0x8006488C
    // 0x80061198: addiu       $a0, $a0, -0x4C14
    ctx->r4 = ADD32(ctx->r4, -0X4C14);
    load_asset(rdram, ctx);
        goto after_6;
    // 0x80061198: addiu       $a0, $a0, -0x4C14
    ctx->r4 = ADD32(ctx->r4, -0X4C14);
    after_6:
    // 0x8006119C: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // 0x800611A0: addu        $t0, $zero, $zero
    ctx->r8 = ADD32(0, 0);
    // 0x800611A4: lui         $a3, 0x8013
    ctx->r7 = S32(0X8013 << 16);
    // 0x800611A8: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x800611AC: addiu       $a1, $v0, -0x6740
    ctx->r5 = ADD32(ctx->r2, -0X6740);
    // 0x800611B0: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
    // 0x800611B4: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x800611B8: addiu       $v1, $v0, -0x66E0
    ctx->r3 = ADD32(ctx->r2, -0X66E0);
L_800611BC:
    // 0x800611BC: lw          $v0, 0xB70($a3)
    ctx->r2 = MEM_W(ctx->r7, 0XB70);
    // 0x800611C0: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800611C4: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x800611C8: lbu         $v0, 0x0($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X0);
    // 0x800611CC: sb          $v0, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r2;
    // 0x800611D0: lw          $v0, 0xB70($a3)
    ctx->r2 = MEM_W(ctx->r7, 0XB70);
    // 0x800611D4: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800611D8: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x800611DC: lbu         $v0, 0x1($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X1);
    // 0x800611E0: sb          $v0, 0x1($v1)
    MEM_B(0X1, ctx->r3) = ctx->r2;
    // 0x800611E4: lw          $v0, 0xB70($a3)
    ctx->r2 = MEM_W(ctx->r7, 0XB70);
    // 0x800611E8: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800611EC: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x800611F0: lbu         $v0, 0x2($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X2);
    // 0x800611F4: sb          $a2, 0x3($v1)
    MEM_B(0X3, ctx->r3) = ctx->r6;
    // 0x800611F8: sb          $v0, 0x2($v1)
    MEM_B(0X2, ctx->r3) = ctx->r2;
    // 0x800611FC: lw          $v0, 0xB70($a3)
    ctx->r2 = MEM_W(ctx->r7, 0XB70);
    // 0x80061200: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80061204: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x80061208: lbu         $v0, 0x80($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X80);
    // 0x8006120C: sb          $v0, 0x0($a1)
    MEM_B(0X0, ctx->r5) = ctx->r2;
    // 0x80061210: lw          $v0, 0xB70($a3)
    ctx->r2 = MEM_W(ctx->r7, 0XB70);
    // 0x80061214: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80061218: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x8006121C: lbu         $v0, 0x81($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X81);
    // 0x80061220: sb          $v0, 0x1($a1)
    MEM_B(0X1, ctx->r5) = ctx->r2;
    // 0x80061224: lw          $v0, 0xB70($a3)
    ctx->r2 = MEM_W(ctx->r7, 0XB70);
    // 0x80061228: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    // 0x8006122C: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80061230: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x80061234: lbu         $v0, 0x82($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X82);
    // 0x80061238: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x8006123C: sb          $a2, 0x3($a1)
    MEM_B(0X3, ctx->r5) = ctx->r6;
    // 0x80061240: addiu       $a2, $a2, -0x10
    ctx->r6 = ADD32(ctx->r6, -0X10);
    // 0x80061244: sb          $v0, 0x2($a1)
    MEM_B(0X2, ctx->r5) = ctx->r2;
    // 0x80061248: slti        $v0, $t0, 0x10
    ctx->r2 = SIGNED(ctx->r8) < 0X10 ? 1 : 0;
    // 0x8006124C: bne         $v0, $zero, L_800611BC
    if (ctx->r2 != 0) {
        // 0x80061250: addiu       $a1, $a1, 0x4
        ctx->r5 = ADD32(ctx->r5, 0X4);
            goto L_800611BC;
    }
    // 0x80061250: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x80061254: jal         0x80001C98
    // 0x80061258: nop

    rs_free(rdram, ctx);
        goto after_7;
    // 0x80061258: nop

    after_7:
    // 0x8006125C: lw          $ra, 0x18($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X18);
    // 0x80061260: jr          $ra
    // 0x80061264: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80061264: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_80061268(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80061268: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8006126C: sw          $a0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r4;
    // 0x80061270: lui         $a0, 0x8006
    ctx->r4 = S32(0X8006 << 16);
    // 0x80061274: addiu       $a0, $a0, 0x690
    ctx->r4 = ADD32(ctx->r4, 0X690);
    // 0x80061278: addiu       $a1, $sp, 0x10
    ctx->r5 = ADD32(ctx->r29, 0X10);
    // 0x8006127C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80061280: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80061284: lwc1        $f0, -0x4C08($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X4C08);
    // 0x80061288: addiu       $a3, $zero, 0xA
    ctx->r7 = ADD32(0, 0XA);
    // 0x8006128C: sw          $ra, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r31;
    // 0x80061290: jal         0x8003FFEC
    // 0x80061294: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    func_8003FFEC(rdram, ctx);
        goto after_0;
    // 0x80061294: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    after_0:
    // 0x80061298: lw          $ra, 0x28($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X28);
    // 0x8006129C: jr          $ra
    // 0x800612A0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x800612A0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_800612A4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800612A4: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800612A8: sw          $a0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r4;
    // 0x800612AC: lui         $a0, 0x8006
    ctx->r4 = S32(0X8006 << 16);
    // 0x800612B0: addiu       $a0, $a0, 0x690
    ctx->r4 = ADD32(ctx->r4, 0X690);
    // 0x800612B4: mtc1        $a1, $f0
    ctx->f0.u32l = ctx->r5;
    // 0x800612B8: addiu       $a1, $sp, 0x10
    ctx->r5 = ADD32(ctx->r29, 0X10);
    // 0x800612BC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x800612C0: addiu       $a3, $zero, 0xA
    ctx->r7 = ADD32(0, 0XA);
    // 0x800612C4: sw          $ra, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r31;
    // 0x800612C8: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    // 0x800612CC: jal         0x8003FFEC
    // 0x800612D0: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    func_8003FFEC(rdram, ctx);
        goto after_0;
    // 0x800612D0: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    after_0:
    // 0x800612D4: lw          $ra, 0x28($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X28);
    // 0x800612D8: jr          $ra
    // 0x800612DC: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x800612DC: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_800612E0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800612E0: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800612E4: sw          $a0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r4;
    // 0x800612E8: lui         $a0, 0x8006
    ctx->r4 = S32(0X8006 << 16);
    // 0x800612EC: mtc1        $a1, $f4
    ctx->f4.u32l = ctx->r5;
    // 0x800612F0: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x800612F4: lwc1        $f2, -0x4C04($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X4C04);
    // 0x800612F8: addiu       $a0, $a0, 0x900
    ctx->r4 = ADD32(ctx->r4, 0X900);
    // 0x800612FC: mul.s       $f2, $f4, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = MUL_S(ctx->f4.fl, ctx->f2.fl);
    // 0x80061300: addiu       $a1, $sp, 0x10
    ctx->r5 = ADD32(ctx->r29, 0X10);
    // 0x80061304: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80061308: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8006130C: lwc1        $f0, -0x4C00($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X4C00);
    // 0x80061310: addiu       $a3, $zero, 0xA
    ctx->r7 = ADD32(0, 0XA);
    // 0x80061314: mul.s       $f4, $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x80061318: sw          $ra, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r31;
    // 0x8006131C: sb          $zero, 0x20($sp)
    MEM_B(0X20, ctx->r29) = 0;
    // 0x80061320: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x80061324: swc1        $f2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f2.u32l;
    // 0x80061328: jal         0x8003FFEC
    // 0x8006132C: swc1        $f4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f4.u32l;
    func_8003FFEC(rdram, ctx);
        goto after_0;
    // 0x8006132C: swc1        $f4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f4.u32l;
    after_0:
    // 0x80061330: lw          $ra, 0x28($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X28);
    // 0x80061334: jr          $ra
    // 0x80061338: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x80061338: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_8006133C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006133C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80061340: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80061344: sw          $a0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r4;
    // 0x80061348: lui         $a0, 0x8006
    ctx->r4 = S32(0X8006 << 16);
    // 0x8006134C: addiu       $a0, $a0, 0x900
    ctx->r4 = ADD32(ctx->r4, 0X900);
    // 0x80061350: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    // 0x80061354: addiu       $a1, $sp, 0x10
    ctx->r5 = ADD32(ctx->r29, 0X10);
    // 0x80061358: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    // 0x8006135C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80061360: sw          $a3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r7;
    // 0x80061364: addiu       $a3, $zero, 0xA
    ctx->r7 = ADD32(0, 0XA);
    // 0x80061368: sw          $ra, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r31;
    // 0x8006136C: jal         0x8003FFEC
    // 0x80061370: sb          $v0, 0x20($sp)
    MEM_B(0X20, ctx->r29) = ctx->r2;
    func_8003FFEC(rdram, ctx);
        goto after_0;
    // 0x80061370: sb          $v0, 0x20($sp)
    MEM_B(0X20, ctx->r29) = ctx->r2;
    after_0:
    // 0x80061374: lw          $ra, 0x28($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X28);
    // 0x80061378: jr          $ra
    // 0x8006137C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x8006137C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_80061380(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80061380: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80061384: sw          $a0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r4;
    // 0x80061388: lui         $a0, 0x8006
    ctx->r4 = S32(0X8006 << 16);
    // 0x8006138C: addiu       $a0, $a0, 0xD8C
    ctx->r4 = ADD32(ctx->r4, 0XD8C);
    // 0x80061390: sw          $a1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r5;
    // 0x80061394: addiu       $a1, $sp, 0x10
    ctx->r5 = ADD32(ctx->r29, 0X10);
    // 0x80061398: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    // 0x8006139C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x800613A0: sw          $ra, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r31;
    // 0x800613A4: jal         0x8003FFEC
    // 0x800613A8: addiu       $a3, $zero, 0xA
    ctx->r7 = ADD32(0, 0XA);
    func_8003FFEC(rdram, ctx);
        goto after_0;
    // 0x800613A8: addiu       $a3, $zero, 0xA
    ctx->r7 = ADD32(0, 0XA);
    after_0:
    // 0x800613AC: lw          $ra, 0x20($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X20);
    // 0x800613B0: jr          $ra
    // 0x800613B4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x800613B4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void fake_func_800613B8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
;}
RECOMP_FUNC void func_800613C0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800613C0: addiu       $sp, $sp, -0x120
    ctx->r29 = ADD32(ctx->r29, -0X120);
    // 0x800613C4: addiu       $v1, $sp, 0x58
    ctx->r3 = ADD32(ctx->r29, 0X58);
    // 0x800613C8: lui         $v0, 0x8004
    ctx->r2 = S32(0X8004 << 16);
    // 0x800613CC: addiu       $v0, $v0, -0x4944
    ctx->r2 = ADD32(ctx->r2, -0X4944);
    // 0x800613D0: sw          $a0, 0x120($sp)
    MEM_W(0X120, ctx->r29) = ctx->r4;
    // 0x800613D4: addiu       $a0, $v0, 0x20
    ctx->r4 = ADD32(ctx->r2, 0X20);
    // 0x800613D8: sw          $ra, 0x114($sp)
    MEM_W(0X114, ctx->r29) = ctx->r31;
    // 0x800613DC: sw          $fp, 0x110($sp)
    MEM_W(0X110, ctx->r29) = ctx->r30;
    // 0x800613E0: sw          $s7, 0x10C($sp)
    MEM_W(0X10C, ctx->r29) = ctx->r23;
    // 0x800613E4: sw          $s6, 0x108($sp)
    MEM_W(0X108, ctx->r29) = ctx->r22;
    // 0x800613E8: sw          $s5, 0x104($sp)
    MEM_W(0X104, ctx->r29) = ctx->r21;
    // 0x800613EC: sw          $s4, 0x100($sp)
    MEM_W(0X100, ctx->r29) = ctx->r20;
    // 0x800613F0: sw          $s3, 0xFC($sp)
    MEM_W(0XFC, ctx->r29) = ctx->r19;
    // 0x800613F4: sw          $s2, 0xF8($sp)
    MEM_W(0XF8, ctx->r29) = ctx->r18;
    // 0x800613F8: sw          $s1, 0xF4($sp)
    MEM_W(0XF4, ctx->r29) = ctx->r17;
    // 0x800613FC: sw          $s0, 0xF0($sp)
    MEM_W(0XF0, ctx->r29) = ctx->r16;
    // 0x80061400: sdc1        $f20, 0x118($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X118, ctx->r29);
    // 0x80061404: sh          $a1, 0xE0($sp)
    MEM_H(0XE0, ctx->r29) = ctx->r5;
    // 0x80061408: sh          $a2, 0xE2($sp)
    MEM_H(0XE2, ctx->r29) = ctx->r6;
    // 0x8006140C: sh          $a3, 0xE4($sp)
    MEM_H(0XE4, ctx->r29) = ctx->r7;
    // 0x80061410: sb          $zero, 0xE6($sp)
    MEM_B(0XE6, ctx->r29) = 0;
L_80061414:
    // 0x80061414: lw          $t0, 0x0($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X0);
    // 0x80061418: lw          $t1, 0x4($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X4);
    // 0x8006141C: lw          $t2, 0x8($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X8);
    // 0x80061420: lw          $t3, 0xC($v0)
    ctx->r11 = MEM_W(ctx->r2, 0XC);
    // 0x80061424: sw          $t0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r8;
    // 0x80061428: sw          $t1, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r9;
    // 0x8006142C: sw          $t2, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r10;
    // 0x80061430: sw          $t3, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r11;
    // 0x80061434: addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
    // 0x80061438: bne         $v0, $a0, L_80061414
    if (ctx->r2 != ctx->r4) {
        // 0x8006143C: addiu       $v1, $v1, 0x10
        ctx->r3 = ADD32(ctx->r3, 0X10);
            goto L_80061414;
    }
    // 0x8006143C: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
    // 0x80061440: lw          $t0, 0x0($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X0);
    // 0x80061444: sw          $t0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r8;
    // 0x80061448: addiu       $v1, $sp, 0x80
    ctx->r3 = ADD32(ctx->r29, 0X80);
    // 0x8006144C: lui         $v0, 0x8004
    ctx->r2 = S32(0X8004 << 16);
    // 0x80061450: addiu       $v0, $v0, -0x491C
    ctx->r2 = ADD32(ctx->r2, -0X491C);
    // 0x80061454: addiu       $a0, $v0, 0x30
    ctx->r4 = ADD32(ctx->r2, 0X30);
L_80061458:
    // 0x80061458: lw          $t0, 0x0($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X0);
    // 0x8006145C: lw          $t1, 0x4($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X4);
    // 0x80061460: lw          $t2, 0x8($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X8);
    // 0x80061464: lw          $t3, 0xC($v0)
    ctx->r11 = MEM_W(ctx->r2, 0XC);
    // 0x80061468: sw          $t0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r8;
    // 0x8006146C: sw          $t1, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r9;
    // 0x80061470: sw          $t2, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r10;
    // 0x80061474: sw          $t3, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r11;
    // 0x80061478: addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
    // 0x8006147C: bne         $v0, $a0, L_80061458
    if (ctx->r2 != ctx->r4) {
        // 0x80061480: addiu       $v1, $v1, 0x10
        ctx->r3 = ADD32(ctx->r3, 0X10);
            goto L_80061458;
    }
    // 0x80061480: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
    // 0x80061484: addiu       $a0, $zero, 0x100
    ctx->r4 = ADD32(0, 0X100);
    // 0x80061488: lui         $a2, 0x800A
    ctx->r6 = S32(0X800A << 16);
    // 0x8006148C: addiu       $a2, $a2, -0x3F0
    ctx->r6 = ADD32(ctx->r6, -0X3F0);
    // 0x80061490: lw          $t0, 0x0($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X0);
    // 0x80061494: sw          $t0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r8;
    // 0x80061498: lhu         $v1, 0xE0($sp)
    ctx->r3 = MEM_HU(ctx->r29, 0XE0);
    // 0x8006149C: lbu         $v0, 0xE1($sp)
    ctx->r2 = MEM_BU(ctx->r29, 0XE1);
    // 0x800614A0: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x800614A4: addu        $v1, $v1, $a2
    ctx->r3 = ADD32(ctx->r3, ctx->r6);
    // 0x800614A8: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800614AC: addu        $v0, $v0, $a2
    ctx->r2 = ADD32(ctx->r2, ctx->r6);
    // 0x800614B0: lw          $s4, 0x0($v1)
    ctx->r20 = MEM_W(ctx->r3, 0X0);
    // 0x800614B4: lw          $s0, 0x0($v0)
    ctx->r16 = MEM_W(ctx->r2, 0X0);
    // 0x800614B8: jal         0x80001ACC
    // 0x800614BC: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    rs_malloc(rdram, ctx);
        goto after_0;
    // 0x800614BC: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    after_0:
    // 0x800614C0: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x800614C4: sw          $v0, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->r2;
    // 0x800614C8: addiu       $v0, $a0, -0x1
    ctx->r2 = ADD32(ctx->r4, -0X1);
L_800614CC:
    // 0x800614CC: sltiu       $v0, $v0, 0x6
    ctx->r2 = ctx->r2 < 0X6 ? 1 : 0;
    // 0x800614D0: beq         $v0, $zero, L_800614E0
    if (ctx->r2 == 0) {
        // 0x800614D4: addiu       $a3, $zero, 0xFF
        ctx->r7 = ADD32(0, 0XFF);
            goto L_800614E0;
    }
    // 0x800614D4: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    // 0x800614D8: j           L_80061514
    // 0x800614DC: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
        goto L_80061514;
    // 0x800614DC: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
L_800614E0:
    // 0x800614E0: lhu         $v0, 0x0($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X0);
    // 0x800614E4: beq         $v0, $zero, L_80061514
    if (ctx->r2 == 0) {
        // 0x800614E8: addu        $v1, $zero, $zero
        ctx->r3 = ADD32(0, 0);
            goto L_80061514;
    }
    // 0x800614E8: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
    // 0x800614EC: lw          $a2, 0xC($s0)
    ctx->r6 = MEM_W(ctx->r16, 0XC);
    // 0x800614F0: addu        $a1, $v0, $zero
    ctx->r5 = ADD32(ctx->r2, 0);
    // 0x800614F4: addu        $v0, $a2, $v1
    ctx->r2 = ADD32(ctx->r6, ctx->r3);
L_800614F8:
    // 0x800614F8: lbu         $v0, 0x0($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X0);
    // 0x800614FC: beql        $v0, $a0, L_80061514
    if (ctx->r2 == ctx->r4) {
        // 0x80061500: addu        $a3, $v1, $zero
        ctx->r7 = ADD32(ctx->r3, 0);
            goto L_80061514;
    }
    goto skip_0;
    // 0x80061500: addu        $a3, $v1, $zero
    ctx->r7 = ADD32(ctx->r3, 0);
    skip_0:
    // 0x80061504: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80061508: sltu        $v0, $v1, $a1
    ctx->r2 = ctx->r3 < ctx->r5 ? 1 : 0;
    // 0x8006150C: bne         $v0, $zero, L_800614F8
    if (ctx->r2 != 0) {
        // 0x80061510: addu        $v0, $a2, $v1
        ctx->r2 = ADD32(ctx->r6, ctx->r3);
            goto L_800614F8;
    }
    // 0x80061510: addu        $v0, $a2, $v1
    ctx->r2 = ADD32(ctx->r6, ctx->r3);
L_80061514:
    // 0x80061514: lw          $v0, 0x20($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X20);
    // 0x80061518: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x8006151C: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x80061520: sb          $a3, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r7;
    // 0x80061524: sltiu       $v0, $a0, 0x100
    ctx->r2 = ctx->r4 < 0X100 ? 1 : 0;
    // 0x80061528: bne         $v0, $zero, L_800614CC
    if (ctx->r2 != 0) {
        // 0x8006152C: addiu       $v0, $a0, -0x1
        ctx->r2 = ADD32(ctx->r4, -0X1);
            goto L_800614CC;
    }
    // 0x8006152C: addiu       $v0, $a0, -0x1
    ctx->r2 = ADD32(ctx->r4, -0X1);
    // 0x80061530: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x80061534: lhu         $a0, 0x0($s4)
    ctx->r4 = MEM_HU(ctx->r20, 0X0);
    // 0x80061538: addu        $s2, $a1, $zero
    ctx->r18 = ADD32(ctx->r5, 0);
    // 0x8006153C: jal         0x80001ACC
    // 0x80061540: sll         $a0, $a0, 1
    ctx->r4 = S32(ctx->r4 << 1);
    rs_malloc(rdram, ctx);
        goto after_1;
    // 0x80061540: sll         $a0, $a0, 1
    ctx->r4 = S32(ctx->r4 << 1);
    after_1:
    // 0x80061544: lhu         $a0, 0x0($s4)
    ctx->r4 = MEM_HU(ctx->r20, 0X0);
    // 0x80061548: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x8006154C: sw          $v0, 0x28($s4)
    MEM_W(0X28, ctx->r20) = ctx->r2;
    // 0x80061550: jal         0x80001ACC
    // 0x80061554: sll         $a0, $a0, 1
    ctx->r4 = S32(ctx->r4 << 1);
    rs_malloc(rdram, ctx);
        goto after_2;
    // 0x80061554: sll         $a0, $a0, 1
    ctx->r4 = S32(ctx->r4 << 1);
    after_2:
    // 0x80061558: addiu       $v1, $sp, 0xB8
    ctx->r3 = ADD32(ctx->r29, 0XB8);
    // 0x8006155C: sw          $v0, 0x24($s4)
    MEM_W(0X24, ctx->r20) = ctx->r2;
L_80061560:
    // 0x80061560: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
    // 0x80061564: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x80061568: sltiu       $v0, $s2, 0x8
    ctx->r2 = ctx->r18 < 0X8 ? 1 : 0;
    // 0x8006156C: bne         $v0, $zero, L_80061560
    if (ctx->r2 != 0) {
        // 0x80061570: addiu       $v1, $v1, 0x4
        ctx->r3 = ADD32(ctx->r3, 0X4);
            goto L_80061560;
    }
    // 0x80061570: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x80061574: lbu         $v0, 0x1D($s4)
    ctx->r2 = MEM_BU(ctx->r20, 0X1D);
    // 0x80061578: beq         $v0, $zero, L_8006165C
    if (ctx->r2 == 0) {
        // 0x8006157C: addu        $s2, $zero, $zero
        ctx->r18 = ADD32(0, 0);
            goto L_8006165C;
    }
    // 0x8006157C: addu        $s2, $zero, $zero
    ctx->r18 = ADD32(0, 0);
    // 0x80061580: lui         $fp, 0x8004
    ctx->r30 = S32(0X8004 << 16);
    // 0x80061584: lui         $s7, 0x8004
    ctx->r23 = S32(0X8004 << 16);
    // 0x80061588: lui         $s5, 0x8014
    ctx->r21 = S32(0X8014 << 16);
    // 0x8006158C: lui         $s6, 0x8013
    ctx->r22 = S32(0X8013 << 16);
L_80061590:
    // 0x80061590: beq         $s2, $zero, L_800615A8
    if (ctx->r18 == 0) {
        // 0x80061594: sb          $zero, 0xD8($sp)
        MEM_B(0XD8, ctx->r29) = 0;
            goto L_800615A8;
    }
    // 0x80061594: sb          $zero, 0xD8($sp)
    MEM_B(0XD8, ctx->r29) = 0;
    // 0x80061598: addiu       $a0, $sp, 0xD8
    ctx->r4 = ADD32(ctx->r29, 0XD8);
    // 0x8006159C: addiu       $a1, $fp, -0x48E8
    ctx->r5 = ADD32(ctx->r30, -0X48E8);
    // 0x800615A0: jal         0x80033CC4
    // 0x800615A4: addu        $a2, $s2, $zero
    ctx->r6 = ADD32(ctx->r18, 0);
    sprintf_recomp(rdram, ctx);
        goto after_3;
    // 0x800615A4: addu        $a2, $s2, $zero
    ctx->r6 = ADD32(ctx->r18, 0);
    after_3:
L_800615A8:
    // 0x800615A8: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    // 0x800615AC: addiu       $a1, $s7, -0x48E0
    ctx->r5 = ADD32(ctx->r23, -0X48E0);
    // 0x800615B0: lw          $a2, 0x10($s4)
    ctx->r6 = MEM_W(ctx->r20, 0X10);
    // 0x800615B4: jal         0x80033CC4
    // 0x800615B8: addiu       $a3, $sp, 0xD8
    ctx->r7 = ADD32(ctx->r29, 0XD8);
    sprintf_recomp(rdram, ctx);
        goto after_4;
    // 0x800615B8: addiu       $a3, $sp, 0xD8
    ctx->r7 = ADD32(ctx->r29, 0XD8);
    after_4:
    // 0x800615BC: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    // 0x800615C0: jal         0x80004D5C
    // 0x800615C4: addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    get_asset_size_extra(rdram, ctx);
        goto after_5;
    // 0x800615C4: addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    after_5:
    // 0x800615C8: addu        $s3, $v0, $zero
    ctx->r19 = ADD32(ctx->r2, 0);
    // 0x800615CC: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x800615D0: beq         $s3, $v0, L_8006165C
    if (ctx->r19 == ctx->r2) {
        // 0x800615D4: nop
    
            goto L_8006165C;
    }
    // 0x800615D4: nop

    // 0x800615D8: beq         $s3, $zero, L_8006165C
    if (ctx->r19 == 0) {
        // 0x800615DC: addu        $a0, $s3, $zero
        ctx->r4 = ADD32(ctx->r19, 0);
            goto L_8006165C;
    }
    // 0x800615DC: addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    // 0x800615E0: jal         0x80001ACC
    // 0x800615E4: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    rs_malloc(rdram, ctx);
        goto after_6;
    // 0x800615E4: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    after_6:
    // 0x800615E8: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x800615EC: addiu       $a3, $sp, 0x18
    ctx->r7 = ADD32(ctx->r29, 0X18);
    // 0x800615F0: sll         $v1, $s2, 2
    ctx->r3 = S32(ctx->r18 << 2);
    // 0x800615F4: addiu       $s0, $sp, 0xB8
    ctx->r16 = ADD32(ctx->r29, 0XB8);
    // 0x800615F8: lw          $a0, -0x76E0($s5)
    ctx->r4 = MEM_W(ctx->r21, -0X76E0);
    // 0x800615FC: lw          $a2, 0x7CFC($s6)
    ctx->r6 = MEM_W(ctx->r22, 0X7CFC);
    // 0x80061600: addu        $s0, $s0, $v1
    ctx->r16 = ADD32(ctx->r16, ctx->r3);
    // 0x80061604: sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
    // 0x80061608: jal         0x80004AAC
    // 0x8006160C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    func_80004AAC(rdram, ctx);
        goto after_7;
    // 0x8006160C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_7:
    // 0x80061610: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x80061614: addu        $s1, $v0, $zero
    ctx->r17 = ADD32(ctx->r2, 0);
    // 0x80061618: lw          $a0, -0x76E0($s5)
    ctx->r4 = MEM_W(ctx->r21, -0X76E0);
    // 0x8006161C: addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    // 0x80061620: sw          $s3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r19;
    // 0x80061624: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80061628: addu        $a3, $a1, $zero
    ctx->r7 = ADD32(ctx->r5, 0);
    // 0x8006162C: jal         0x80004E70
    // 0x80061630: sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    setupAssetDma(rdram, ctx);
        goto after_8;
    // 0x80061630: sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    after_8:
    // 0x80061634: lw          $a0, -0x76E0($s5)
    ctx->r4 = MEM_W(ctx->r21, -0X76E0);
    // 0x80061638: jal         0x80004C70
    // 0x8006163C: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    teardownAssetDma(rdram, ctx);
        goto after_9;
    // 0x8006163C: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    after_9:
    // 0x80061640: addiu       $v1, $s2, 0x1
    ctx->r3 = ADD32(ctx->r18, 0X1);
    // 0x80061644: sb          $v1, 0xE6($sp)
    MEM_B(0XE6, ctx->r29) = ctx->r3;
    // 0x80061648: lbu         $v0, 0x1D($s4)
    ctx->r2 = MEM_BU(ctx->r20, 0X1D);
    // 0x8006164C: addu        $s2, $v1, $zero
    ctx->r18 = ADD32(ctx->r3, 0);
    // 0x80061650: sltu        $v0, $s2, $v0
    ctx->r2 = ctx->r18 < ctx->r2 ? 1 : 0;
    // 0x80061654: bne         $v0, $zero, L_80061590
    if (ctx->r2 != 0) {
        // 0x80061658: nop
    
            goto L_80061590;
    }
    // 0x80061658: nop

L_8006165C:
    // 0x8006165C: lw          $v1, 0xB8($sp)
    ctx->r3 = MEM_W(ctx->r29, 0XB8);
    // 0x80061660: lbu         $v0, 0x8($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X8);
    // 0x80061664: sb          $v0, 0xB0($sp)
    MEM_B(0XB0, ctx->r29) = ctx->r2;
    // 0x80061668: lbu         $v0, 0x9($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X9);
    // 0x8006166C: sb          $v0, 0xB1($sp)
    MEM_B(0XB1, ctx->r29) = ctx->r2;
    // 0x80061670: lbu         $v0, 0xA($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0XA);
    // 0x80061674: lw          $v1, 0xA4($sp)
    ctx->r3 = MEM_W(ctx->r29, 0XA4);
    // 0x80061678: sb          $v0, 0xB2($sp)
    MEM_B(0XB2, ctx->r29) = ctx->r2;
    // 0x8006167C: lhu         $v0, 0x6($s4)
    ctx->r2 = MEM_HU(ctx->r20, 0X6);
    // 0x80061680: sh          $v0, 0xAA($sp)
    MEM_H(0XAA, ctx->r29) = ctx->r2;
    // 0x80061684: lbu         $v0, 0xF8($s4)
    ctx->r2 = MEM_BU(ctx->r20, 0XF8);
    // 0x80061688: sb          $v0, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r2;
    // 0x8006168C: lbu         $v0, 0xF8($s4)
    ctx->r2 = MEM_BU(ctx->r20, 0XF8);
    // 0x80061690: sb          $v0, 0x6C($sp)
    MEM_B(0X6C, ctx->r29) = ctx->r2;
    // 0x80061694: lhu         $v0, 0x0($s4)
    ctx->r2 = MEM_HU(ctx->r20, 0X0);
    // 0x80061698: beq         $v0, $zero, L_800618FC
    if (ctx->r2 == 0) {
        // 0x8006169C: addu        $s2, $zero, $zero
        ctx->r18 = ADD32(0, 0);
            goto L_800618FC;
    }
    // 0x8006169C: addu        $s2, $zero, $zero
    ctx->r18 = ADD32(0, 0);
    // 0x800616A0: addiu       $fp, $zero, 0x1
    ctx->r30 = ADD32(0, 0X1);
    // 0x800616A4: addiu       $t0, $sp, 0x80
    ctx->r8 = ADD32(ctx->r29, 0X80);
    // 0x800616A8: addiu       $t1, $sp, 0xB8
    ctx->r9 = ADD32(ctx->r29, 0XB8);
    // 0x800616AC: lbu         $s7, 0xE6($sp)
    ctx->r23 = MEM_BU(ctx->r29, 0XE6);
    // 0x800616B0: addu        $s6, $s2, $zero
    ctx->r22 = ADD32(ctx->r18, 0);
    // 0x800616B4: sw          $t0, 0xE8($sp)
    MEM_W(0XE8, ctx->r29) = ctx->r8;
    // 0x800616B8: sw          $t1, 0xEC($sp)
    MEM_W(0XEC, ctx->r29) = ctx->r9;
L_800616BC:
    // 0x800616BC: lw          $v0, 0xC($s4)
    ctx->r2 = MEM_W(ctx->r20, 0XC);
    // 0x800616C0: addu        $v0, $v0, $s2
    ctx->r2 = ADD32(ctx->r2, ctx->r18);
    // 0x800616C4: lbu         $v0, 0x0($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X0);
    // 0x800616C8: sb          $v0, 0x6D($sp)
    MEM_B(0X6D, ctx->r29) = ctx->r2;
    // 0x800616CC: lw          $v0, 0xC($s4)
    ctx->r2 = MEM_W(ctx->r20, 0XC);
    // 0x800616D0: lw          $v1, 0xA4($sp)
    ctx->r3 = MEM_W(ctx->r29, 0XA4);
    // 0x800616D4: addu        $v0, $v0, $s2
    ctx->r2 = ADD32(ctx->r2, ctx->r18);
    // 0x800616D8: lbu         $v0, 0x0($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X0);
    // 0x800616DC: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x800616E0: beq         $s7, $zero, L_80061770
    if (ctx->r23 == 0) {
        // 0x800616E4: sb          $v0, 0x1($v1)
        MEM_B(0X1, ctx->r3) = ctx->r2;
            goto L_80061770;
    }
    // 0x800616E4: sb          $v0, 0x1($v1)
    MEM_B(0X1, ctx->r3) = ctx->r2;
    // 0x800616E8: lw          $a3, 0xE8($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XE8);
    // 0x800616EC: lw          $a2, 0xEC($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XEC);
L_800616F0:
    // 0x800616F0: lhu         $v0, 0x2($s4)
    ctx->r2 = MEM_HU(ctx->r20, 0X2);
    // 0x800616F4: sllv        $v1, $fp, $a1
    ctx->r3 = S32(ctx->r30 << (ctx->r5 & 31));
    // 0x800616F8: divu        $zero, $v0, $v1
    lo = S32(U32(ctx->r2) / U32(ctx->r3)); hi = S32(U32(ctx->r2) % U32(ctx->r3));
    // 0x800616FC: bne         $v1, $zero, L_80061708
    if (ctx->r3 != 0) {
        // 0x80061700: nop
    
            goto L_80061708;
    }
    // 0x80061700: nop

    // 0x80061704: break       7
    do_break(2147882756);
L_80061708:
    // 0x80061708: mflo        $v0
    ctx->r2 = lo;
    // 0x8006170C: lhu         $a0, 0x4($s4)
    ctx->r4 = MEM_HU(ctx->r20, 0X4);
    // 0x80061710: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80061714: srl         $v0, $v0, 1
    ctx->r2 = S32(U32(ctx->r2) >> 1);
    // 0x80061718: mult        $v0, $a0
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8006171C: mflo        $t4
    ctx->r12 = lo;
    // 0x80061720: nop

    // 0x80061724: nop

    // 0x80061728: divu        $zero, $t4, $v1
    lo = S32(U32(ctx->r12) / U32(ctx->r3)); hi = S32(U32(ctx->r12) % U32(ctx->r3));
    // 0x8006172C: bne         $v1, $zero, L_80061738
    if (ctx->r3 != 0) {
        // 0x80061730: nop
    
            goto L_80061738;
    }
    // 0x80061730: nop

    // 0x80061734: break       7
    do_break(2147882804);
L_80061738:
    // 0x80061738: mflo        $v1
    ctx->r3 = lo;
    // 0x8006173C: nop

    // 0x80061740: nop

    // 0x80061744: mult        $v1, $s2
    result = S64(S32(ctx->r3)) * S64(S32(ctx->r18)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80061748: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x8006174C: lw          $v1, 0x0($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X0);
    // 0x80061750: addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
    // 0x80061754: mflo        $t4
    ctx->r12 = lo;
    // 0x80061758: addiu       $v0, $t4, 0xC
    ctx->r2 = ADD32(ctx->r12, 0XC);
    // 0x8006175C: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x80061760: sw          $v1, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r3;
    // 0x80061764: sltu        $v0, $a1, $s7
    ctx->r2 = ctx->r5 < ctx->r23 ? 1 : 0;
    // 0x80061768: bne         $v0, $zero, L_800616F0
    if (ctx->r2 != 0) {
        // 0x8006176C: addiu       $a3, $a3, 0x4
        ctx->r7 = ADD32(ctx->r7, 0X4);
            goto L_800616F0;
    }
    // 0x8006176C: addiu       $a3, $a3, 0x4
    ctx->r7 = ADD32(ctx->r7, 0X4);
L_80061770:
    // 0x80061770: bne         $s7, $fp, L_80061838
    if (ctx->r23 != ctx->r30) {
        // 0x80061774: addiu       $v0, $zero, 0x3
        ctx->r2 = ADD32(0, 0X3);
            goto L_80061838;
    }
    // 0x80061774: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x80061778: lhu         $v1, 0xE0($sp)
    ctx->r3 = MEM_HU(ctx->r29, 0XE0);
    // 0x8006177C: beq         $v1, $v0, L_80061838
    if (ctx->r3 == ctx->r2) {
        // 0x80061780: nop
    
            goto L_80061838;
    }
    // 0x80061780: nop

    // 0x80061784: lw          $v0, 0x18($s4)
    ctx->r2 = MEM_W(ctx->r20, 0X18);
    // 0x80061788: addu        $v0, $v0, $s2
    ctx->r2 = ADD32(ctx->r2, ctx->r18);
    // 0x8006178C: lbu         $s0, 0x0($v0)
    ctx->r16 = MEM_BU(ctx->r2, 0X0);
    // 0x80061790: beq         $v1, $zero, L_800617A0
    if (ctx->r3 == 0) {
        // 0x80061794: addiu       $v0, $zero, 0x5
        ctx->r2 = ADD32(0, 0X5);
            goto L_800617A0;
    }
    // 0x80061794: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
    // 0x80061798: bne         $v1, $v0, L_800617BC
    if (ctx->r3 != ctx->r2) {
        // 0x8006179C: addiu       $v0, $s0, 0x1
        ctx->r2 = ADD32(ctx->r16, 0X1);
            goto L_800617BC;
    }
    // 0x8006179C: addiu       $v0, $s0, 0x1
    ctx->r2 = ADD32(ctx->r16, 0X1);
L_800617A0:
    // 0x800617A0: addiu       $s0, $s0, 0x3
    ctx->r16 = ADD32(ctx->r16, 0X3);
    // 0x800617A4: lhu         $v1, 0x2($s4)
    ctx->r3 = MEM_HU(ctx->r20, 0X2);
    // 0x800617A8: andi        $v0, $s0, 0xFFFF
    ctx->r2 = ctx->r16 & 0XFFFF;
    // 0x800617AC: sltu        $v0, $v1, $v0
    ctx->r2 = ctx->r3 < ctx->r2 ? 1 : 0;
    // 0x800617B0: bnel        $v0, $zero, L_800617B8
    if (ctx->r2 != 0) {
        // 0x800617B4: addu        $s0, $v1, $zero
        ctx->r16 = ADD32(ctx->r3, 0);
            goto L_800617B8;
    }
    goto skip_1;
    // 0x800617B4: addu        $s0, $v1, $zero
    ctx->r16 = ADD32(ctx->r3, 0);
    skip_1:
L_800617B8:
    // 0x800617B8: addiu       $v0, $s0, 0x1
    ctx->r2 = ADD32(ctx->r16, 0X1);
L_800617BC:
    // 0x800617BC: andi        $s0, $v0, 0xFFFE
    ctx->r16 = ctx->r2 & 0XFFFE;
    // 0x800617C0: lhu         $v0, 0x6($s4)
    ctx->r2 = MEM_HU(ctx->r20, 0X6);
    // 0x800617C4: beq         $v0, $zero, L_80061830
    if (ctx->r2 == 0) {
        // 0x800617C8: addu        $s1, $zero, $zero
        ctx->r17 = ADD32(0, 0);
            goto L_80061830;
    }
    // 0x800617C8: addu        $s1, $zero, $zero
    ctx->r17 = ADD32(0, 0);
    // 0x800617CC: andi        $s3, $s0, 0xFFFF
    ctx->r19 = ctx->r16 & 0XFFFF;
    // 0x800617D0: srl         $s5, $s3, 1
    ctx->r21 = S32(U32(ctx->r19) >> 1);
    // 0x800617D4: andi        $a1, $s1, 0xFFFF
    ctx->r5 = ctx->r17 & 0XFFFF;
L_800617D8:
    // 0x800617D8: mult        $a1, $s3
    result = S64(S32(ctx->r5)) * S64(S32(ctx->r19)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800617DC: andi        $a2, $s5, 0xFFFF
    ctx->r6 = ctx->r21 & 0XFFFF;
    // 0x800617E0: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x800617E4: mflo        $a0
    ctx->r4 = lo;
    // 0x800617E8: lhu         $v0, 0x2($s4)
    ctx->r2 = MEM_HU(ctx->r20, 0X2);
    // 0x800617EC: srl         $v1, $a0, 31
    ctx->r3 = S32(U32(ctx->r4) >> 31);
    // 0x800617F0: mult        $a1, $v0
    result = S64(S32(ctx->r5)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800617F4: addu        $a0, $a0, $v1
    ctx->r4 = ADD32(ctx->r4, ctx->r3);
    // 0x800617F8: lw          $v1, 0x80($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X80);
    // 0x800617FC: sra         $a0, $a0, 1
    ctx->r4 = S32(SIGNED(ctx->r4) >> 1);
    // 0x80061800: addu        $a0, $v1, $a0
    ctx->r4 = ADD32(ctx->r3, ctx->r4);
    // 0x80061804: mflo        $a1
    ctx->r5 = lo;
    // 0x80061808: srl         $v0, $a1, 31
    ctx->r2 = S32(U32(ctx->r5) >> 31);
    // 0x8006180C: addu        $a1, $a1, $v0
    ctx->r5 = ADD32(ctx->r5, ctx->r2);
    // 0x80061810: sra         $a1, $a1, 1
    ctx->r5 = S32(SIGNED(ctx->r5) >> 1);
    // 0x80061814: jal         0x80018EF4
    // 0x80061818: addu        $a1, $v1, $a1
    ctx->r5 = ADD32(ctx->r3, ctx->r5);
    zmemcpy(rdram, ctx);
        goto after_10;
    // 0x80061818: addu        $a1, $v1, $a1
    ctx->r5 = ADD32(ctx->r3, ctx->r5);
    after_10:
    // 0x8006181C: lhu         $v1, 0x6($s4)
    ctx->r3 = MEM_HU(ctx->r20, 0X6);
    // 0x80061820: andi        $v0, $s1, 0xFFFF
    ctx->r2 = ctx->r17 & 0XFFFF;
    // 0x80061824: sltu        $v0, $v0, $v1
    ctx->r2 = ctx->r2 < ctx->r3 ? 1 : 0;
    // 0x80061828: bne         $v0, $zero, L_800617D8
    if (ctx->r2 != 0) {
        // 0x8006182C: andi        $a1, $s1, 0xFFFF
        ctx->r5 = ctx->r17 & 0XFFFF;
            goto L_800617D8;
    }
    // 0x8006182C: andi        $a1, $s1, 0xFFFF
    ctx->r5 = ctx->r17 & 0XFFFF;
L_80061830:
    // 0x80061830: j           L_80061840
    // 0x80061834: sh          $s0, 0xA8($sp)
    MEM_H(0XA8, ctx->r29) = ctx->r16;
        goto L_80061840;
    // 0x80061834: sh          $s0, 0xA8($sp)
    MEM_H(0XA8, ctx->r29) = ctx->r16;
L_80061838:
    // 0x80061838: lhu         $v0, 0x2($s4)
    ctx->r2 = MEM_HU(ctx->r20, 0X2);
    // 0x8006183C: sh          $v0, 0xA8($sp)
    MEM_H(0XA8, ctx->r29) = ctx->r2;
L_80061840:
    // 0x80061840: lbu         $t0, 0xE6($sp)
    ctx->r8 = MEM_BU(ctx->r29, 0XE6);
    // 0x80061844: sb          $t0, 0xAC($sp)
    MEM_B(0XAC, ctx->r29) = ctx->r8;
    // 0x80061848: lbu         $v0, 0x1F($s4)
    ctx->r2 = MEM_BU(ctx->r20, 0X1F);
    // 0x8006184C: bne         $v0, $fp, L_8006188C
    if (ctx->r2 != ctx->r30) {
        // 0x80061850: ori         $v1, $zero, 0xFFFF
        ctx->r3 = 0 | 0XFFFF;
            goto L_8006188C;
    }
    // 0x80061850: ori         $v1, $zero, 0xFFFF
    ctx->r3 = 0 | 0XFFFF;
    // 0x80061854: addiu       $a0, $sp, 0x58
    ctx->r4 = ADD32(ctx->r29, 0X58);
    // 0x80061858: addiu       $a1, $sp, 0x80
    ctx->r5 = ADD32(ctx->r29, 0X80);
    // 0x8006185C: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // 0x80061860: lw          $v1, 0xA4($sp)
    ctx->r3 = MEM_W(ctx->r29, 0XA4);
    // 0x80061864: addiu       $v0, $zero, 0x53
    ctx->r2 = ADD32(0, 0X53);
    // 0x80061868: sb          $v0, 0x6E($sp)
    MEM_B(0X6E, ctx->r29) = ctx->r2;
    // 0x8006186C: sb          $v0, 0x2($v1)
    MEM_B(0X2, ctx->r3) = ctx->r2;
    // 0x80061870: addiu       $v0, $zero, 0x4004
    ctx->r2 = ADD32(0, 0X4004);
    // 0x80061874: jal         0x80022B90
    // 0x80061878: sh          $v0, 0xAE($sp)
    MEM_H(0XAE, ctx->r29) = ctx->r2;
    registerHmtTextureInTable(rdram, ctx);
        goto after_11;
    // 0x80061878: sh          $v0, 0xAE($sp)
    MEM_H(0XAE, ctx->r29) = ctx->r2;
    after_11:
    // 0x8006187C: lw          $v1, 0x28($s4)
    ctx->r3 = MEM_W(ctx->r20, 0X28);
    // 0x80061880: addu        $v1, $s6, $v1
    ctx->r3 = ADD32(ctx->r22, ctx->r3);
    // 0x80061884: j           L_80061898
    // 0x80061888: sh          $v0, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r2;
        goto L_80061898;
    // 0x80061888: sh          $v0, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r2;
L_8006188C:
    // 0x8006188C: lw          $v0, 0x28($s4)
    ctx->r2 = MEM_W(ctx->r20, 0X28);
    // 0x80061890: addu        $v0, $s6, $v0
    ctx->r2 = ADD32(ctx->r22, ctx->r2);
    // 0x80061894: sh          $v1, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r3;
L_80061898:
    // 0x80061898: lbu         $v0, 0x1E($s4)
    ctx->r2 = MEM_BU(ctx->r20, 0X1E);
    // 0x8006189C: bne         $v0, $fp, L_800618DC
    if (ctx->r2 != ctx->r30) {
        // 0x800618A0: ori         $v1, $zero, 0xFFFF
        ctx->r3 = 0 | 0XFFFF;
            goto L_800618DC;
    }
    // 0x800618A0: ori         $v1, $zero, 0xFFFF
    ctx->r3 = 0 | 0XFFFF;
    // 0x800618A4: addiu       $a0, $sp, 0x58
    ctx->r4 = ADD32(ctx->r29, 0X58);
    // 0x800618A8: addiu       $a1, $sp, 0x80
    ctx->r5 = ADD32(ctx->r29, 0X80);
    // 0x800618AC: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // 0x800618B0: lw          $v1, 0xA4($sp)
    ctx->r3 = MEM_W(ctx->r29, 0XA4);
    // 0x800618B4: addiu       $v0, $zero, 0x41
    ctx->r2 = ADD32(0, 0X41);
    // 0x800618B8: sb          $v0, 0x6E($sp)
    MEM_B(0X6E, ctx->r29) = ctx->r2;
    // 0x800618BC: sb          $v0, 0x2($v1)
    MEM_B(0X2, ctx->r3) = ctx->r2;
    // 0x800618C0: addiu       $v0, $zero, 0x2004
    ctx->r2 = ADD32(0, 0X2004);
    // 0x800618C4: jal         0x80022B90
    // 0x800618C8: sh          $v0, 0xAE($sp)
    MEM_H(0XAE, ctx->r29) = ctx->r2;
    registerHmtTextureInTable(rdram, ctx);
        goto after_12;
    // 0x800618C8: sh          $v0, 0xAE($sp)
    MEM_H(0XAE, ctx->r29) = ctx->r2;
    after_12:
    // 0x800618CC: lw          $v1, 0x24($s4)
    ctx->r3 = MEM_W(ctx->r20, 0X24);
    // 0x800618D0: addu        $v1, $s6, $v1
    ctx->r3 = ADD32(ctx->r22, ctx->r3);
    // 0x800618D4: j           L_800618E8
    // 0x800618D8: sh          $v0, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r2;
        goto L_800618E8;
    // 0x800618D8: sh          $v0, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r2;
L_800618DC:
    // 0x800618DC: lw          $v0, 0x24($s4)
    ctx->r2 = MEM_W(ctx->r20, 0X24);
    // 0x800618E0: addu        $v0, $s6, $v0
    ctx->r2 = ADD32(ctx->r22, ctx->r2);
    // 0x800618E4: sh          $v1, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r3;
L_800618E8:
    // 0x800618E8: lhu         $v0, 0x0($s4)
    ctx->r2 = MEM_HU(ctx->r20, 0X0);
    // 0x800618EC: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x800618F0: sltu        $v0, $s2, $v0
    ctx->r2 = ctx->r18 < ctx->r2 ? 1 : 0;
    // 0x800618F4: bne         $v0, $zero, L_800616BC
    if (ctx->r2 != 0) {
        // 0x800618F8: addiu       $s6, $s6, 0x2
        ctx->r22 = ADD32(ctx->r22, 0X2);
            goto L_800616BC;
    }
    // 0x800618F8: addiu       $s6, $s6, 0x2
    ctx->r22 = ADD32(ctx->r22, 0X2);
L_800618FC:
    // 0x800618FC: addu        $s2, $zero, $zero
    ctx->r18 = ADD32(0, 0);
    // 0x80061900: addiu       $s0, $sp, 0xB8
    ctx->r16 = ADD32(ctx->r29, 0XB8);
L_80061904:
    // 0x80061904: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80061908: beq         $a0, $zero, L_8006191C
    if (ctx->r4 == 0) {
        // 0x8006190C: addiu       $s2, $s2, 0x1
        ctx->r18 = ADD32(ctx->r18, 0X1);
            goto L_8006191C;
    }
    // 0x8006190C: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x80061910: jal         0x80001C98
    // 0x80061914: nop

    rs_free(rdram, ctx);
        goto after_13;
    // 0x80061914: nop

    after_13:
    // 0x80061918: sw          $zero, 0x0($s0)
    MEM_W(0X0, ctx->r16) = 0;
L_8006191C:
    // 0x8006191C: sltiu       $v0, $s2, 0x8
    ctx->r2 = ctx->r18 < 0X8 ? 1 : 0;
    // 0x80061920: bne         $v0, $zero, L_80061904
    if (ctx->r2 != 0) {
        // 0x80061924: addiu       $s0, $s0, 0x4
        ctx->r16 = ADD32(ctx->r16, 0X4);
            goto L_80061904;
    }
    // 0x80061924: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x80061928: addu        $s2, $zero, $zero
    ctx->r18 = ADD32(0, 0);
    // 0x8006192C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80061930: addu        $v1, $s4, $zero
    ctx->r3 = ADD32(ctx->r20, 0);
L_80061934:
    // 0x80061934: addu        $v0, $s4, $s2
    ctx->r2 = ADD32(ctx->r20, ctx->r18);
    // 0x80061938: sb          $a0, 0x84($v0)
    MEM_B(0X84, ctx->r2) = ctx->r4;
    // 0x8006193C: sw          $zero, 0x34($v1)
    MEM_W(0X34, ctx->r3) = 0;
    // 0x80061940: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x80061944: sltiu       $v0, $s2, 0x14
    ctx->r2 = ctx->r18 < 0X14 ? 1 : 0;
    // 0x80061948: bne         $v0, $zero, L_80061934
    if (ctx->r2 != 0) {
        // 0x8006194C: addiu       $v1, $v1, 0x4
        ctx->r3 = ADD32(ctx->r3, 0X4);
            goto L_80061934;
    }
    // 0x8006194C: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x80061950: lhu         $v0, 0xE2($sp)
    ctx->r2 = MEM_HU(ctx->r29, 0XE2);
    // 0x80061954: beq         $v0, $zero, L_80061988
    if (ctx->r2 == 0) {
        // 0x80061958: addu        $s2, $zero, $zero
        ctx->r18 = ADD32(0, 0);
            goto L_80061988;
    }
    // 0x80061958: addu        $s2, $zero, $zero
    ctx->r18 = ADD32(0, 0);
    // 0x8006195C: addu        $s1, $v0, $zero
    ctx->r17 = ADD32(ctx->r2, 0);
    // 0x80061960: addu        $s0, $s4, $zero
    ctx->r16 = ADD32(ctx->r20, 0);
L_80061964:
    // 0x80061964: addiu       $a0, $zero, 0x30
    ctx->r4 = ADD32(0, 0X30);
    // 0x80061968: jal         0x80001ACC
    // 0x8006196C: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    rs_malloc(rdram, ctx);
        goto after_14;
    // 0x8006196C: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    after_14:
    // 0x80061970: sw          $v0, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->r2;
    // 0x80061974: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x80061978: sltu        $v0, $s2, $s1
    ctx->r2 = ctx->r18 < ctx->r17 ? 1 : 0;
    // 0x8006197C: bne         $v0, $zero, L_80061964
    if (ctx->r2 != 0) {
        // 0x80061980: addiu       $s0, $s0, 0x4
        ctx->r16 = ADD32(ctx->r16, 0X4);
            goto L_80061964;
    }
    // 0x80061980: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x80061984: lhu         $v0, 0xE2($sp)
    ctx->r2 = MEM_HU(ctx->r29, 0XE2);
L_80061988:
    // 0x80061988: beq         $v0, $zero, L_800619F4
    if (ctx->r2 == 0) {
        // 0x8006198C: addu        $s2, $zero, $zero
        ctx->r18 = ADD32(0, 0);
            goto L_800619F4;
    }
    // 0x8006198C: addu        $s2, $zero, $zero
    ctx->r18 = ADD32(0, 0);
    // 0x80061990: addiu       $s5, $zero, 0x1
    ctx->r21 = ADD32(0, 0X1);
    // 0x80061994: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80061998: lwc1        $f20, -0x48D4($at)
    ctx->f20.u32l = MEM_W(ctx->r1, -0X48D4);
    // 0x8006199C: addiu       $s7, $zero, 0x12
    ctx->r23 = ADD32(0, 0X12);
    // 0x800619A0: addiu       $s3, $zero, 0xFF
    ctx->r19 = ADD32(0, 0XFF);
    // 0x800619A4: addu        $s6, $v0, $zero
    ctx->r22 = ADD32(ctx->r2, 0);
    // 0x800619A8: addu        $s1, $s4, $zero
    ctx->r17 = ADD32(ctx->r20, 0);
L_800619AC:
    // 0x800619AC: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x800619B0: addiu       $a2, $zero, 0x30
    ctx->r6 = ADD32(0, 0X30);
    // 0x800619B4: lw          $s0, 0x34($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X34);
    // 0x800619B8: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x800619BC: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x800619C0: jal         0x800078E0
    // 0x800619C4: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    rs_memset(rdram, ctx);
        goto after_15;
    // 0x800619C4: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_15:
    // 0x800619C8: sltu        $v0, $s2, $s6
    ctx->r2 = ctx->r18 < ctx->r22 ? 1 : 0;
    // 0x800619CC: sh          $s5, 0xA($s0)
    MEM_H(0XA, ctx->r16) = ctx->r21;
    // 0x800619D0: sh          $s5, 0x8($s0)
    MEM_H(0X8, ctx->r16) = ctx->r21;
    // 0x800619D4: swc1        $f20, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f20.u32l;
    // 0x800619D8: swc1        $f20, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->f20.u32l;
    // 0x800619DC: sw          $s7, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->r23;
    // 0x800619E0: sb          $s3, 0x2C($s0)
    MEM_B(0X2C, ctx->r16) = ctx->r19;
    // 0x800619E4: sb          $s3, 0x2D($s0)
    MEM_B(0X2D, ctx->r16) = ctx->r19;
    // 0x800619E8: sb          $s3, 0x2E($s0)
    MEM_B(0X2E, ctx->r16) = ctx->r19;
    // 0x800619EC: bne         $v0, $zero, L_800619AC
    if (ctx->r2 != 0) {
        // 0x800619F0: sb          $s3, 0x2F($s0)
        MEM_B(0X2F, ctx->r16) = ctx->r19;
            goto L_800619AC;
    }
    // 0x800619F0: sb          $s3, 0x2F($s0)
    MEM_B(0X2F, ctx->r16) = ctx->r19;
L_800619F4:
    // 0x800619F4: lhu         $s1, 0xE4($sp)
    ctx->r17 = MEM_HU(ctx->r29, 0XE4);
    // 0x800619F8: lhu         $s0, 0xE2($sp)
    ctx->r16 = MEM_HU(ctx->r29, 0XE2);
    // 0x800619FC: lhu         $t0, 0xE2($sp)
    ctx->r8 = MEM_HU(ctx->r29, 0XE2);
    // 0x80061A00: sll         $a0, $s0, 2
    ctx->r4 = S32(ctx->r16 << 2);
    // 0x80061A04: sh          $t0, 0x2C($s4)
    MEM_H(0X2C, ctx->r20) = ctx->r8;
    // 0x80061A08: sw          $zero, 0x30($s4)
    MEM_W(0X30, ctx->r20) = 0;
    // 0x80061A0C: lw          $t1, 0x120($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X120);
    // 0x80061A10: mult        $s1, $a0
    result = S64(S32(ctx->r17)) * S64(S32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80061A14: sw          $t1, 0xF4($s4)
    MEM_W(0XF4, ctx->r20) = ctx->r9;
    // 0x80061A18: sw          $zero, 0xFC($s4)
    MEM_W(0XFC, ctx->r20) = 0;
    // 0x80061A1C: lhu         $t2, 0xE4($sp)
    ctx->r10 = MEM_HU(ctx->r29, 0XE4);
    // 0x80061A20: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x80061A24: mflo        $a0
    ctx->r4 = lo;
    // 0x80061A28: jal         0x80001ACC
    // 0x80061A2C: sh          $t2, 0xE8($s4)
    MEM_H(0XE8, ctx->r20) = ctx->r10;
    rs_malloc(rdram, ctx);
        goto after_16;
    // 0x80061A2C: sh          $t2, 0xE8($s4)
    MEM_H(0XE8, ctx->r20) = ctx->r10;
    after_16:
    // 0x80061A30: sll         $s0, $s0, 1
    ctx->r16 = S32(ctx->r16 << 1);
    // 0x80061A34: mult        $s1, $s0
    result = S64(S32(ctx->r17)) * S64(S32(ctx->r16)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80061A38: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x80061A3C: mflo        $a0
    ctx->r4 = lo;
    // 0x80061A40: jal         0x80001ACC
    // 0x80061A44: sw          $v0, 0xEC($s4)
    MEM_W(0XEC, ctx->r20) = ctx->r2;
    rs_malloc(rdram, ctx);
        goto after_17;
    // 0x80061A44: sw          $v0, 0xEC($s4)
    MEM_W(0XEC, ctx->r20) = ctx->r2;
    after_17:
    // 0x80061A48: lbu         $v1, 0x1F($s4)
    ctx->r3 = MEM_BU(ctx->r20, 0X1F);
    // 0x80061A4C: sw          $v0, 0xF0($s4)
    MEM_W(0XF0, ctx->r20) = ctx->r2;
    // 0x80061A50: sb          $v1, 0x102($s4)
    MEM_B(0X102, ctx->r20) = ctx->r3;
    // 0x80061A54: lw          $ra, 0x114($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X114);
    // 0x80061A58: lw          $fp, 0x110($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X110);
    // 0x80061A5C: lw          $s7, 0x10C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X10C);
    // 0x80061A60: lw          $s6, 0x108($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X108);
    // 0x80061A64: lw          $s5, 0x104($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X104);
    // 0x80061A68: lw          $s4, 0x100($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X100);
    // 0x80061A6C: lw          $s3, 0xFC($sp)
    ctx->r19 = MEM_W(ctx->r29, 0XFC);
    // 0x80061A70: lw          $s2, 0xF8($sp)
    ctx->r18 = MEM_W(ctx->r29, 0XF8);
    // 0x80061A74: lw          $s1, 0xF4($sp)
    ctx->r17 = MEM_W(ctx->r29, 0XF4);
    // 0x80061A78: lw          $s0, 0xF0($sp)
    ctx->r16 = MEM_W(ctx->r29, 0XF0);
    // 0x80061A7C: ldc1        $f20, 0x118($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X118);
    // 0x80061A80: jr          $ra
    // 0x80061A84: addiu       $sp, $sp, 0x120
    ctx->r29 = ADD32(ctx->r29, 0X120);
    return;
    // 0x80061A84: addiu       $sp, $sp, 0x120
    ctx->r29 = ADD32(ctx->r29, 0X120);
;}
RECOMP_FUNC void func_80061A88(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80061A88: addiu       $sp, $sp, -0xE0
    ctx->r29 = ADD32(ctx->r29, -0XE0);
    // 0x80061A8C: addiu       $v1, $sp, 0x50
    ctx->r3 = ADD32(ctx->r29, 0X50);
    // 0x80061A90: lui         $v0, 0x8004
    ctx->r2 = S32(0X8004 << 16);
    // 0x80061A94: addiu       $v0, $v0, -0x4944
    ctx->r2 = ADD32(ctx->r2, -0X4944);
    // 0x80061A98: sb          $a0, 0xB0($sp)
    MEM_B(0XB0, ctx->r29) = ctx->r4;
    // 0x80061A9C: addiu       $a0, $v0, 0x20
    ctx->r4 = ADD32(ctx->r2, 0X20);
    // 0x80061AA0: sw          $ra, 0xDC($sp)
    MEM_W(0XDC, ctx->r29) = ctx->r31;
    // 0x80061AA4: sw          $fp, 0xD8($sp)
    MEM_W(0XD8, ctx->r29) = ctx->r30;
    // 0x80061AA8: sw          $s7, 0xD4($sp)
    MEM_W(0XD4, ctx->r29) = ctx->r23;
    // 0x80061AAC: sw          $s6, 0xD0($sp)
    MEM_W(0XD0, ctx->r29) = ctx->r22;
    // 0x80061AB0: sw          $s5, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->r21;
    // 0x80061AB4: sw          $s4, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->r20;
    // 0x80061AB8: sw          $s3, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->r19;
    // 0x80061ABC: sw          $s2, 0xC0($sp)
    MEM_W(0XC0, ctx->r29) = ctx->r18;
    // 0x80061AC0: sw          $s1, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->r17;
    // 0x80061AC4: sw          $s0, 0xB8($sp)
    MEM_W(0XB8, ctx->r29) = ctx->r16;
L_80061AC8:
    // 0x80061AC8: lw          $a3, 0x0($v0)
    ctx->r7 = MEM_W(ctx->r2, 0X0);
    // 0x80061ACC: lw          $t0, 0x4($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X4);
    // 0x80061AD0: lw          $t1, 0x8($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X8);
    // 0x80061AD4: lw          $t2, 0xC($v0)
    ctx->r10 = MEM_W(ctx->r2, 0XC);
    // 0x80061AD8: sw          $a3, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r7;
    // 0x80061ADC: sw          $t0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r8;
    // 0x80061AE0: sw          $t1, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r9;
    // 0x80061AE4: sw          $t2, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r10;
    // 0x80061AE8: addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
    // 0x80061AEC: bne         $v0, $a0, L_80061AC8
    if (ctx->r2 != ctx->r4) {
        // 0x80061AF0: addiu       $v1, $v1, 0x10
        ctx->r3 = ADD32(ctx->r3, 0X10);
            goto L_80061AC8;
    }
    // 0x80061AF0: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
    // 0x80061AF4: addiu       $s0, $sp, 0x78
    ctx->r16 = ADD32(ctx->r29, 0X78);
    // 0x80061AF8: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x80061AFC: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x80061B00: addiu       $a2, $zero, 0x34
    ctx->r6 = ADD32(0, 0X34);
    // 0x80061B04: lw          $a3, 0x0($v0)
    ctx->r7 = MEM_W(ctx->r2, 0X0);
    // 0x80061B08: jal         0x800078E0
    // 0x80061B0C: sw          $a3, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r7;
    rs_memset(rdram, ctx);
        goto after_0;
    // 0x80061B0C: sw          $a3, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r7;
    after_0:
    // 0x80061B10: addu        $s2, $zero, $zero
    ctx->r18 = ADD32(0, 0);
    // 0x80061B14: addiu       $fp, $zero, 0x41
    ctx->r30 = ADD32(0, 0X41);
    // 0x80061B18: addiu       $s6, $sp, 0x50
    ctx->r22 = ADD32(ctx->r29, 0X50);
    // 0x80061B1C: addu        $s5, $s0, $zero
    ctx->r21 = ADD32(ctx->r16, 0);
    // 0x80061B20: addiu       $s7, $zero, 0x53
    ctx->r23 = ADD32(0, 0X53);
    // 0x80061B24: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x80061B28: addiu       $s1, $v0, -0x6690
    ctx->r17 = ADD32(ctx->r2, -0X6690);
    // 0x80061B2C: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x80061B30: addiu       $s4, $v0, -0x6680
    ctx->r20 = ADD32(ctx->r2, -0X6680);
    // 0x80061B34: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x80061B38: addiu       $s3, $v0, -0x1290
    ctx->r19 = ADD32(ctx->r2, -0X1290);
    // 0x80061B3C: lui         $v0, 0x8004
    ctx->r2 = S32(0X8004 << 16);
    // 0x80061B40: addiu       $v0, $v0, -0x4920
    ctx->r2 = ADD32(ctx->r2, -0X4920);
    // 0x80061B44: sw          $v0, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->r2;
    // 0x80061B48: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80061B4C: sb          $v0, 0xA4($sp)
    MEM_B(0XA4, ctx->r29) = ctx->r2;
L_80061B50:
    // 0x80061B50: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    // 0x80061B54: lui         $a1, 0x8004
    ctx->r5 = S32(0X8004 << 16);
    // 0x80061B58: lw          $a2, 0x0($s3)
    ctx->r6 = MEM_W(ctx->r19, 0X0);
    // 0x80061B5C: jal         0x80033CC4
    // 0x80061B60: addiu       $a1, $a1, -0x48D0
    ctx->r5 = ADD32(ctx->r5, -0X48D0);
    sprintf_recomp(rdram, ctx);
        goto after_1;
    // 0x80061B60: addiu       $a1, $a1, -0x48D0
    ctx->r5 = ADD32(ctx->r5, -0X48D0);
    after_1:
    // 0x80061B64: jal         0x8006488C
    // 0x80061B68: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    load_asset(rdram, ctx);
        goto after_2;
    // 0x80061B68: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    after_2:
    // 0x80061B6C: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    // 0x80061B70: lbu         $v0, 0x8($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X8);
    // 0x80061B74: lw          $v1, 0x9C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X9C);
    // 0x80061B78: sb          $v0, 0xA8($sp)
    MEM_B(0XA8, ctx->r29) = ctx->r2;
    // 0x80061B7C: lbu         $v0, 0x9($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X9);
    // 0x80061B80: sb          $v0, 0xA9($sp)
    MEM_B(0XA9, ctx->r29) = ctx->r2;
    // 0x80061B84: lbu         $v0, 0xA($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0XA);
    // 0x80061B88: addu        $a0, $s6, $zero
    ctx->r4 = ADD32(ctx->r22, 0);
    // 0x80061B8C: sb          $v0, 0xAA($sp)
    MEM_B(0XAA, ctx->r29) = ctx->r2;
    // 0x80061B90: lhu         $v0, 0x4($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X4);
    // 0x80061B94: addu        $a1, $s5, $zero
    ctx->r5 = ADD32(ctx->r21, 0);
    // 0x80061B98: sh          $v0, 0xA0($sp)
    MEM_H(0XA0, ctx->r29) = ctx->r2;
    // 0x80061B9C: lhu         $v0, 0x6($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X6);
    // 0x80061BA0: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // 0x80061BA4: sh          $v0, 0xA2($sp)
    MEM_H(0XA2, ctx->r29) = ctx->r2;
    // 0x80061BA8: addiu       $a3, $zero, 0x58
    ctx->r7 = ADD32(0, 0X58);
    // 0x80061BAC: sb          $a3, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r7;
    // 0x80061BB0: lw          $v0, 0x9C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X9C);
    // 0x80061BB4: addiu       $v1, $s2, 0x30
    ctx->r3 = ADD32(ctx->r18, 0X30);
    // 0x80061BB8: sb          $v1, 0x1($v0)
    MEM_B(0X1, ctx->r2) = ctx->r3;
    // 0x80061BBC: addu        $t0, $a3, $zero
    ctx->r8 = ADD32(ctx->r7, 0);
    // 0x80061BC0: sb          $v1, 0x65($sp)
    MEM_B(0X65, ctx->r29) = ctx->r3;
    // 0x80061BC4: lw          $v1, 0x9C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X9C);
    // 0x80061BC8: addiu       $v0, $s0, 0xC
    ctx->r2 = ADD32(ctx->r16, 0XC);
    // 0x80061BCC: sw          $v0, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r2;
    // 0x80061BD0: ori         $v0, $zero, 0x8002
    ctx->r2 = 0 | 0X8002;
    // 0x80061BD4: sb          $t0, 0x64($sp)
    MEM_B(0X64, ctx->r29) = ctx->r8;
    // 0x80061BD8: sb          $fp, 0x66($sp)
    MEM_B(0X66, ctx->r29) = ctx->r30;
    // 0x80061BDC: sb          $fp, 0x2($v1)
    MEM_B(0X2, ctx->r3) = ctx->r30;
    // 0x80061BE0: jal         0x80022B90
    // 0x80061BE4: sh          $v0, 0xA6($sp)
    MEM_H(0XA6, ctx->r29) = ctx->r2;
    registerHmtTextureInTable(rdram, ctx);
        goto after_3;
    // 0x80061BE4: sh          $v0, 0xA6($sp)
    MEM_H(0XA6, ctx->r29) = ctx->r2;
    after_3:
    // 0x80061BE8: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // 0x80061BEC: sh          $v1, 0x0($s4)
    MEM_H(0X0, ctx->r20) = ctx->r3;
    // 0x80061BF0: lbu         $v0, 0xB0($sp)
    ctx->r2 = MEM_BU(ctx->r29, 0XB0);
    // 0x80061BF4: bnel        $v0, $zero, L_80061C24
    if (ctx->r2 != 0) {
        // 0x80061BF8: sh          $v1, 0x0($s1)
        MEM_H(0X0, ctx->r17) = ctx->r3;
            goto L_80061C24;
    }
    goto skip_0;
    // 0x80061BF8: sh          $v1, 0x0($s1)
    MEM_H(0X0, ctx->r17) = ctx->r3;
    skip_0:
    // 0x80061BFC: addu        $a0, $s6, $zero
    ctx->r4 = ADD32(ctx->r22, 0);
    // 0x80061C00: addu        $a1, $s5, $zero
    ctx->r5 = ADD32(ctx->r21, 0);
    // 0x80061C04: lw          $v0, 0x9C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X9C);
    // 0x80061C08: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // 0x80061C0C: sb          $s7, 0x66($sp)
    MEM_B(0X66, ctx->r29) = ctx->r23;
    // 0x80061C10: sb          $s7, 0x2($v0)
    MEM_B(0X2, ctx->r2) = ctx->r23;
    // 0x80061C14: addiu       $v0, $zero, 0x4002
    ctx->r2 = ADD32(0, 0X4002);
    // 0x80061C18: jal         0x80022B90
    // 0x80061C1C: sh          $v0, 0xA6($sp)
    MEM_H(0XA6, ctx->r29) = ctx->r2;
    registerHmtTextureInTable(rdram, ctx);
        goto after_4;
    // 0x80061C1C: sh          $v0, 0xA6($sp)
    MEM_H(0XA6, ctx->r29) = ctx->r2;
    after_4:
    // 0x80061C20: sh          $v0, 0x0($s1)
    MEM_H(0X0, ctx->r17) = ctx->r2;
L_80061C24:
    // 0x80061C24: jal         0x80001C98
    // 0x80061C28: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    rs_free(rdram, ctx);
        goto after_5;
    // 0x80061C28: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_5:
    // 0x80061C2C: addiu       $s1, $s1, 0x2
    ctx->r17 = ADD32(ctx->r17, 0X2);
    // 0x80061C30: addiu       $s4, $s4, 0x2
    ctx->r20 = ADD32(ctx->r20, 0X2);
    // 0x80061C34: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x80061C38: sltiu       $v0, $s2, 0x6
    ctx->r2 = ctx->r18 < 0X6 ? 1 : 0;
    // 0x80061C3C: bne         $v0, $zero, L_80061B50
    if (ctx->r2 != 0) {
        // 0x80061C40: addiu       $s3, $s3, 0x4
        ctx->r19 = ADD32(ctx->r19, 0X4);
            goto L_80061B50;
    }
    // 0x80061C40: addiu       $s3, $s3, 0x4
    ctx->r19 = ADD32(ctx->r19, 0X4);
    // 0x80061C44: lw          $ra, 0xDC($sp)
    ctx->r31 = MEM_W(ctx->r29, 0XDC);
    // 0x80061C48: lw          $fp, 0xD8($sp)
    ctx->r30 = MEM_W(ctx->r29, 0XD8);
    // 0x80061C4C: lw          $s7, 0xD4($sp)
    ctx->r23 = MEM_W(ctx->r29, 0XD4);
    // 0x80061C50: lw          $s6, 0xD0($sp)
    ctx->r22 = MEM_W(ctx->r29, 0XD0);
    // 0x80061C54: lw          $s5, 0xCC($sp)
    ctx->r21 = MEM_W(ctx->r29, 0XCC);
    // 0x80061C58: lw          $s4, 0xC8($sp)
    ctx->r20 = MEM_W(ctx->r29, 0XC8);
    // 0x80061C5C: lw          $s3, 0xC4($sp)
    ctx->r19 = MEM_W(ctx->r29, 0XC4);
    // 0x80061C60: lw          $s2, 0xC0($sp)
    ctx->r18 = MEM_W(ctx->r29, 0XC0);
    // 0x80061C64: lw          $s1, 0xBC($sp)
    ctx->r17 = MEM_W(ctx->r29, 0XBC);
    // 0x80061C68: lw          $s0, 0xB8($sp)
    ctx->r16 = MEM_W(ctx->r29, 0XB8);
    // 0x80061C6C: jr          $ra
    // 0x80061C70: addiu       $sp, $sp, 0xE0
    ctx->r29 = ADD32(ctx->r29, 0XE0);
    return;
    // 0x80061C70: addiu       $sp, $sp, 0xE0
    ctx->r29 = ADD32(ctx->r29, 0XE0);
;}
RECOMP_FUNC void func_80061C74(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80061C74: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80061C78: sw          $s3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r19;
    // 0x80061C7C: addu        $s3, $a1, $zero
    ctx->r19 = ADD32(ctx->r5, 0);
    // 0x80061C80: sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // 0x80061C84: lui         $v1, 0x800A
    ctx->r3 = S32(0X800A << 16);
    // 0x80061C88: addiu       $v1, $v1, -0x3F0
    ctx->r3 = ADD32(ctx->r3, -0X3F0);
    // 0x80061C8C: andi        $v0, $a0, 0xFFFF
    ctx->r2 = ctx->r4 & 0XFFFF;
    // 0x80061C90: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80061C94: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80061C98: sw          $ra, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r31;
    // 0x80061C9C: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x80061CA0: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x80061CA4: lw          $s1, 0x0($v0)
    ctx->r17 = MEM_W(ctx->r2, 0X0);
    // 0x80061CA8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80061CAC: lw          $v1, 0x30($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X30);
    // 0x80061CB0: sllv        $v0, $v0, $s3
    ctx->r2 = S32(ctx->r2 << (ctx->r19 & 31));
    // 0x80061CB4: and         $v1, $v1, $v0
    ctx->r3 = ctx->r3 & ctx->r2;
    // 0x80061CB8: beq         $v1, $zero, L_80061F18
    if (ctx->r3 == 0) {
        // 0x80061CBC: addu        $s2, $a2, $zero
        ctx->r18 = ADD32(ctx->r6, 0);
            goto L_80061F18;
    }
    // 0x80061CBC: addu        $s2, $a2, $zero
    ctx->r18 = ADD32(ctx->r6, 0);
    // 0x80061CC0: andi        $v1, $s2, 0xFF
    ctx->r3 = ctx->r18 & 0XFF;
    // 0x80061CC4: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // 0x80061CC8: bnel        $v1, $v0, L_80061CE0
    if (ctx->r3 != ctx->r2) {
        // 0x80061CCC: andi        $a0, $a0, 0xFFFF
        ctx->r4 = ctx->r4 & 0XFFFF;
            goto L_80061CE0;
    }
    goto skip_0;
    // 0x80061CCC: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    skip_0:
    // 0x80061CD0: lbu         $v0, 0x1F($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X1F);
    // 0x80061CD4: beql        $v0, $zero, L_80061CDC
    if (ctx->r2 == 0) {
        // 0x80061CD8: addiu       $s2, $zero, 0xFE
        ctx->r18 = ADD32(0, 0XFE);
            goto L_80061CDC;
    }
    goto skip_1;
    // 0x80061CD8: addiu       $s2, $zero, 0xFE
    ctx->r18 = ADD32(0, 0XFE);
    skip_1:
L_80061CDC:
    // 0x80061CDC: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
L_80061CE0:
    // 0x80061CE0: andi        $s0, $s3, 0xFFFF
    ctx->r16 = ctx->r19 & 0XFFFF;
    // 0x80061CE4: jal         0x80063C3C
    // 0x80061CE8: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    func_80063C3C(rdram, ctx);
        goto after_0;
    // 0x80061CE8: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    after_0:
    // 0x80061CEC: addu        $a1, $v0, $zero
    ctx->r5 = ADD32(ctx->r2, 0);
    // 0x80061CF0: andi        $v1, $s2, 0xFF
    ctx->r3 = ctx->r18 & 0XFF;
    // 0x80061CF4: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // 0x80061CF8: bne         $v1, $v0, L_80061DFC
    if (ctx->r3 != ctx->r2) {
        // 0x80061CFC: addu        $v0, $s1, $s0
        ctx->r2 = ADD32(ctx->r17, ctx->r16);
            goto L_80061DFC;
    }
    // 0x80061CFC: addu        $v0, $s1, $s0
    ctx->r2 = ADD32(ctx->r17, ctx->r16);
    // 0x80061D00: lbu         $v0, 0x84($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X84);
    // 0x80061D04: bne         $v0, $zero, L_80061DEC
    if (ctx->r2 != 0) {
        // 0x80061D08: nop
    
            goto L_80061DEC;
    }
    // 0x80061D08: nop

    // 0x80061D0C: lhu         $v0, 0x8($a1)
    ctx->r2 = MEM_HU(ctx->r5, 0X8);
    // 0x80061D10: beq         $v0, $zero, L_80061DDC
    if (ctx->r2 == 0) {
        // 0x80061D14: addu        $t2, $zero, $zero
        ctx->r10 = ADD32(0, 0);
            goto L_80061DDC;
    }
    // 0x80061D14: addu        $t2, $zero, $zero
    ctx->r10 = ADD32(0, 0);
    // 0x80061D18: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x80061D1C: addiu       $t5, $v0, -0x6680
    ctx->r13 = ADD32(ctx->r2, -0X6680);
    // 0x80061D20: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x80061D24: addiu       $t4, $v0, -0x6690
    ctx->r12 = ADD32(ctx->r2, -0X6690);
    // 0x80061D28: addu        $t3, $t2, $zero
    ctx->r11 = ADD32(ctx->r10, 0);
L_80061D2C:
    // 0x80061D2C: lhu         $v0, 0x0($s1)
    ctx->r2 = MEM_HU(ctx->r17, 0X0);
    // 0x80061D30: beq         $v0, $zero, L_80061D84
    if (ctx->r2 == 0) {
        // 0x80061D34: addu        $a0, $zero, $zero
        ctx->r4 = ADD32(0, 0);
            goto L_80061D84;
    }
    // 0x80061D34: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x80061D38: addu        $t0, $t3, $zero
    ctx->r8 = ADD32(ctx->r11, 0);
L_80061D3C:
    // 0x80061D3C: lw          $v0, 0xC($a1)
    ctx->r2 = MEM_W(ctx->r5, 0XC);
    // 0x80061D40: sll         $a2, $a0, 1
    ctx->r6 = S32(ctx->r4 << 1);
    // 0x80061D44: addu        $a3, $t0, $v0
    ctx->r7 = ADD32(ctx->r8, ctx->r2);
    // 0x80061D48: lw          $v0, 0x24($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X24);
    // 0x80061D4C: lhu         $v1, 0x0($a3)
    ctx->r3 = MEM_HU(ctx->r7, 0X0);
    // 0x80061D50: addu        $v0, $a2, $v0
    ctx->r2 = ADD32(ctx->r6, ctx->r2);
    // 0x80061D54: lhu         $v0, 0x0($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X0);
    // 0x80061D58: bne         $v1, $v0, L_80061D74
    if (ctx->r3 != ctx->r2) {
        // 0x80061D5C: addiu       $a0, $a0, 0x1
        ctx->r4 = ADD32(ctx->r4, 0X1);
            goto L_80061D74;
    }
    // 0x80061D5C: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x80061D60: lw          $v0, 0x28($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X28);
    // 0x80061D64: addu        $v0, $a2, $v0
    ctx->r2 = ADD32(ctx->r6, ctx->r2);
    // 0x80061D68: lhu         $v0, 0x0($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X0);
    // 0x80061D6C: j           L_80061D84
    // 0x80061D70: sh          $v0, 0x0($a3)
    MEM_H(0X0, ctx->r7) = ctx->r2;
        goto L_80061D84;
    // 0x80061D70: sh          $v0, 0x0($a3)
    MEM_H(0X0, ctx->r7) = ctx->r2;
L_80061D74:
    // 0x80061D74: lhu         $v0, 0x0($s1)
    ctx->r2 = MEM_HU(ctx->r17, 0X0);
    // 0x80061D78: sltu        $v0, $a0, $v0
    ctx->r2 = ctx->r4 < ctx->r2 ? 1 : 0;
    // 0x80061D7C: bne         $v0, $zero, L_80061D3C
    if (ctx->r2 != 0) {
        // 0x80061D80: nop
    
            goto L_80061D3C;
    }
    // 0x80061D80: nop

L_80061D84:
    // 0x80061D84: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x80061D88: addu        $t1, $t3, $zero
    ctx->r9 = ADD32(ctx->r11, 0);
    // 0x80061D8C: addu        $t0, $t4, $zero
    ctx->r8 = ADD32(ctx->r12, 0);
    // 0x80061D90: addu        $a3, $t5, $zero
    ctx->r7 = ADD32(ctx->r13, 0);
L_80061D94:
    // 0x80061D94: lw          $v0, 0xC($a1)
    ctx->r2 = MEM_W(ctx->r5, 0XC);
    // 0x80061D98: addu        $a2, $t1, $v0
    ctx->r6 = ADD32(ctx->r9, ctx->r2);
    // 0x80061D9C: lhu         $v1, 0x0($a2)
    ctx->r3 = MEM_HU(ctx->r6, 0X0);
    // 0x80061DA0: lhu         $v0, 0x0($a3)
    ctx->r2 = MEM_HU(ctx->r7, 0X0);
    // 0x80061DA4: bnel        $v1, $v0, L_80061DB8
    if (ctx->r3 != ctx->r2) {
        // 0x80061DA8: addiu       $t0, $t0, 0x2
        ctx->r8 = ADD32(ctx->r8, 0X2);
            goto L_80061DB8;
    }
    goto skip_2;
    // 0x80061DA8: addiu       $t0, $t0, 0x2
    ctx->r8 = ADD32(ctx->r8, 0X2);
    skip_2:
    // 0x80061DAC: lhu         $v0, 0x0($t0)
    ctx->r2 = MEM_HU(ctx->r8, 0X0);
    // 0x80061DB0: j           L_80061DC8
    // 0x80061DB4: sh          $v0, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r2;
        goto L_80061DC8;
    // 0x80061DB4: sh          $v0, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r2;
L_80061DB8:
    // 0x80061DB8: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x80061DBC: sltiu       $v0, $a0, 0x6
    ctx->r2 = ctx->r4 < 0X6 ? 1 : 0;
    // 0x80061DC0: bne         $v0, $zero, L_80061D94
    if (ctx->r2 != 0) {
        // 0x80061DC4: addiu       $a3, $a3, 0x2
        ctx->r7 = ADD32(ctx->r7, 0X2);
            goto L_80061D94;
    }
    // 0x80061DC4: addiu       $a3, $a3, 0x2
    ctx->r7 = ADD32(ctx->r7, 0X2);
L_80061DC8:
    // 0x80061DC8: lhu         $v0, 0x8($a1)
    ctx->r2 = MEM_HU(ctx->r5, 0X8);
    // 0x80061DCC: addiu       $t2, $t2, 0x1
    ctx->r10 = ADD32(ctx->r10, 0X1);
    // 0x80061DD0: sltu        $v0, $t2, $v0
    ctx->r2 = ctx->r10 < ctx->r2 ? 1 : 0;
    // 0x80061DD4: bne         $v0, $zero, L_80061D2C
    if (ctx->r2 != 0) {
        // 0x80061DD8: addiu       $t3, $t3, 0x2
        ctx->r11 = ADD32(ctx->r11, 0X2);
            goto L_80061D2C;
    }
    // 0x80061DD8: addiu       $t3, $t3, 0x2
    ctx->r11 = ADD32(ctx->r11, 0X2);
L_80061DDC:
    // 0x80061DDC: andi        $v0, $s3, 0xFFFF
    ctx->r2 = ctx->r19 & 0XFFFF;
    // 0x80061DE0: addu        $v0, $s1, $v0
    ctx->r2 = ADD32(ctx->r17, ctx->r2);
    // 0x80061DE4: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x80061DE8: sb          $v1, 0x84($v0)
    MEM_B(0X84, ctx->r2) = ctx->r3;
L_80061DEC:
    // 0x80061DEC: lw          $v0, 0x14($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X14);
    // 0x80061DF0: addiu       $v1, $zero, -0x2
    ctx->r3 = ADD32(0, -0X2);
    // 0x80061DF4: j           L_80061EEC
    // 0x80061DF8: and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
        goto L_80061EEC;
    // 0x80061DF8: and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
L_80061DFC:
    // 0x80061DFC: lbu         $v0, 0x84($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X84);
    // 0x80061E00: beq         $v0, $zero, L_80061EE4
    if (ctx->r2 == 0) {
        // 0x80061E04: nop
    
            goto L_80061EE4;
    }
    // 0x80061E04: nop

    // 0x80061E08: lhu         $v0, 0x8($a1)
    ctx->r2 = MEM_HU(ctx->r5, 0X8);
    // 0x80061E0C: beq         $v0, $zero, L_80061ED8
    if (ctx->r2 == 0) {
        // 0x80061E10: addu        $t2, $zero, $zero
        ctx->r10 = ADD32(0, 0);
            goto L_80061ED8;
    }
    // 0x80061E10: addu        $t2, $zero, $zero
    ctx->r10 = ADD32(0, 0);
    // 0x80061E14: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x80061E18: addiu       $t5, $v0, -0x6690
    ctx->r13 = ADD32(ctx->r2, -0X6690);
    // 0x80061E1C: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x80061E20: addiu       $t4, $v0, -0x6680
    ctx->r12 = ADD32(ctx->r2, -0X6680);
    // 0x80061E24: addu        $t3, $t2, $zero
    ctx->r11 = ADD32(ctx->r10, 0);
L_80061E28:
    // 0x80061E28: lhu         $v0, 0x0($s1)
    ctx->r2 = MEM_HU(ctx->r17, 0X0);
    // 0x80061E2C: beq         $v0, $zero, L_80061E80
    if (ctx->r2 == 0) {
        // 0x80061E30: addu        $a0, $zero, $zero
        ctx->r4 = ADD32(0, 0);
            goto L_80061E80;
    }
    // 0x80061E30: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x80061E34: addu        $t0, $t3, $zero
    ctx->r8 = ADD32(ctx->r11, 0);
L_80061E38:
    // 0x80061E38: lw          $v0, 0xC($a1)
    ctx->r2 = MEM_W(ctx->r5, 0XC);
    // 0x80061E3C: sll         $a2, $a0, 1
    ctx->r6 = S32(ctx->r4 << 1);
    // 0x80061E40: addu        $a3, $t0, $v0
    ctx->r7 = ADD32(ctx->r8, ctx->r2);
    // 0x80061E44: lw          $v0, 0x28($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X28);
    // 0x80061E48: lhu         $v1, 0x0($a3)
    ctx->r3 = MEM_HU(ctx->r7, 0X0);
    // 0x80061E4C: addu        $v0, $a2, $v0
    ctx->r2 = ADD32(ctx->r6, ctx->r2);
    // 0x80061E50: lhu         $v0, 0x0($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X0);
    // 0x80061E54: bne         $v1, $v0, L_80061E70
    if (ctx->r3 != ctx->r2) {
        // 0x80061E58: addiu       $a0, $a0, 0x1
        ctx->r4 = ADD32(ctx->r4, 0X1);
            goto L_80061E70;
    }
    // 0x80061E58: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x80061E5C: lw          $v0, 0x24($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X24);
    // 0x80061E60: addu        $v0, $a2, $v0
    ctx->r2 = ADD32(ctx->r6, ctx->r2);
    // 0x80061E64: lhu         $v0, 0x0($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X0);
    // 0x80061E68: j           L_80061E80
    // 0x80061E6C: sh          $v0, 0x0($a3)
    MEM_H(0X0, ctx->r7) = ctx->r2;
        goto L_80061E80;
    // 0x80061E6C: sh          $v0, 0x0($a3)
    MEM_H(0X0, ctx->r7) = ctx->r2;
L_80061E70:
    // 0x80061E70: lhu         $v0, 0x0($s1)
    ctx->r2 = MEM_HU(ctx->r17, 0X0);
    // 0x80061E74: sltu        $v0, $a0, $v0
    ctx->r2 = ctx->r4 < ctx->r2 ? 1 : 0;
    // 0x80061E78: bne         $v0, $zero, L_80061E38
    if (ctx->r2 != 0) {
        // 0x80061E7C: nop
    
            goto L_80061E38;
    }
    // 0x80061E7C: nop

L_80061E80:
    // 0x80061E80: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x80061E84: addu        $t1, $t3, $zero
    ctx->r9 = ADD32(ctx->r11, 0);
    // 0x80061E88: addu        $t0, $t4, $zero
    ctx->r8 = ADD32(ctx->r12, 0);
    // 0x80061E8C: addu        $a3, $t5, $zero
    ctx->r7 = ADD32(ctx->r13, 0);
L_80061E90:
    // 0x80061E90: lw          $v0, 0xC($a1)
    ctx->r2 = MEM_W(ctx->r5, 0XC);
    // 0x80061E94: addu        $a2, $t1, $v0
    ctx->r6 = ADD32(ctx->r9, ctx->r2);
    // 0x80061E98: lhu         $v1, 0x0($a2)
    ctx->r3 = MEM_HU(ctx->r6, 0X0);
    // 0x80061E9C: lhu         $v0, 0x0($a3)
    ctx->r2 = MEM_HU(ctx->r7, 0X0);
    // 0x80061EA0: bnel        $v1, $v0, L_80061EB4
    if (ctx->r3 != ctx->r2) {
        // 0x80061EA4: addiu       $t0, $t0, 0x2
        ctx->r8 = ADD32(ctx->r8, 0X2);
            goto L_80061EB4;
    }
    goto skip_3;
    // 0x80061EA4: addiu       $t0, $t0, 0x2
    ctx->r8 = ADD32(ctx->r8, 0X2);
    skip_3:
    // 0x80061EA8: lhu         $v0, 0x0($t0)
    ctx->r2 = MEM_HU(ctx->r8, 0X0);
    // 0x80061EAC: j           L_80061EC4
    // 0x80061EB0: sh          $v0, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r2;
        goto L_80061EC4;
    // 0x80061EB0: sh          $v0, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r2;
L_80061EB4:
    // 0x80061EB4: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x80061EB8: sltiu       $v0, $a0, 0x6
    ctx->r2 = ctx->r4 < 0X6 ? 1 : 0;
    // 0x80061EBC: bne         $v0, $zero, L_80061E90
    if (ctx->r2 != 0) {
        // 0x80061EC0: addiu       $a3, $a3, 0x2
        ctx->r7 = ADD32(ctx->r7, 0X2);
            goto L_80061E90;
    }
    // 0x80061EC0: addiu       $a3, $a3, 0x2
    ctx->r7 = ADD32(ctx->r7, 0X2);
L_80061EC4:
    // 0x80061EC4: lhu         $v0, 0x8($a1)
    ctx->r2 = MEM_HU(ctx->r5, 0X8);
    // 0x80061EC8: addiu       $t2, $t2, 0x1
    ctx->r10 = ADD32(ctx->r10, 0X1);
    // 0x80061ECC: sltu        $v0, $t2, $v0
    ctx->r2 = ctx->r10 < ctx->r2 ? 1 : 0;
    // 0x80061ED0: bne         $v0, $zero, L_80061E28
    if (ctx->r2 != 0) {
        // 0x80061ED4: addiu       $t3, $t3, 0x2
        ctx->r11 = ADD32(ctx->r11, 0X2);
            goto L_80061E28;
    }
    // 0x80061ED4: addiu       $t3, $t3, 0x2
    ctx->r11 = ADD32(ctx->r11, 0X2);
L_80061ED8:
    // 0x80061ED8: andi        $v0, $s3, 0xFFFF
    ctx->r2 = ctx->r19 & 0XFFFF;
    // 0x80061EDC: addu        $v0, $s1, $v0
    ctx->r2 = ADD32(ctx->r17, ctx->r2);
    // 0x80061EE0: sb          $zero, 0x84($v0)
    MEM_B(0X84, ctx->r2) = 0;
L_80061EE4:
    // 0x80061EE4: lw          $v0, 0x14($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X14);
    // 0x80061EE8: ori         $v0, $v0, 0x1
    ctx->r2 = ctx->r2 | 0X1;
L_80061EEC:
    // 0x80061EEC: sw          $v0, 0x14($a1)
    MEM_W(0X14, ctx->r5) = ctx->r2;
    // 0x80061EF0: sb          $s2, 0x2F($a1)
    MEM_B(0X2F, ctx->r5) = ctx->r18;
    // 0x80061EF4: lw          $a0, 0xF4($s1)
    ctx->r4 = MEM_W(ctx->r17, 0XF4);
    // 0x80061EF8: beq         $a0, $zero, L_80061F18
    if (ctx->r4 == 0) {
        // 0x80061EFC: andi        $v0, $s2, 0xFF
        ctx->r2 = ctx->r18 & 0XFF;
            goto L_80061F18;
    }
    // 0x80061EFC: andi        $v0, $s2, 0xFF
    ctx->r2 = ctx->r18 & 0XFF;
    // 0x80061F00: beq         $v0, $zero, L_80061F10
    if (ctx->r2 == 0) {
        // 0x80061F04: addu        $a2, $zero, $zero
        ctx->r6 = ADD32(0, 0);
            goto L_80061F10;
    }
    // 0x80061F04: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // 0x80061F08: lhu         $v0, 0x8($a1)
    ctx->r2 = MEM_HU(ctx->r5, 0X8);
    // 0x80061F0C: sltu        $a2, $a2, $v0
    ctx->r6 = ctx->r6 < ctx->r2 ? 1 : 0;
L_80061F10:
    // 0x80061F10: jal         0x800646AC
    // 0x80061F14: nop

    func_800646AC(rdram, ctx);
        goto after_1;
    // 0x80061F14: nop

    after_1:
L_80061F18:
    // 0x80061F18: lw          $ra, 0x20($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X20);
    // 0x80061F1C: lw          $s3, 0x1C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X1C);
    // 0x80061F20: lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X18);
    // 0x80061F24: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x80061F28: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x80061F2C: jr          $ra
    // 0x80061F30: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80061F30: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_80061F34(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80061F34: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80061F38: sw          $s5, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r21;
    // 0x80061F3C: addu        $s5, $a0, $zero
    ctx->r21 = ADD32(ctx->r4, 0);
    // 0x80061F40: sw          $s7, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r23;
    // 0x80061F44: addu        $s7, $a1, $zero
    ctx->r23 = ADD32(ctx->r5, 0);
    // 0x80061F48: sw          $s4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r20;
    // 0x80061F4C: addiu       $s4, $zero, 0x2710
    ctx->r20 = ADD32(0, 0X2710);
    // 0x80061F50: lui         $v1, 0x800A
    ctx->r3 = S32(0X800A << 16);
    // 0x80061F54: addiu       $v1, $v1, -0x3F0
    ctx->r3 = ADD32(ctx->r3, -0X3F0);
    // 0x80061F58: andi        $v0, $s5, 0xFFFF
    ctx->r2 = ctx->r21 & 0XFFFF;
    // 0x80061F5C: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80061F60: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80061F64: andi        $v1, $s7, 0xFFFF
    ctx->r3 = ctx->r23 & 0XFFFF;
    // 0x80061F68: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x80061F6C: sw          $ra, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r31;
    // 0x80061F70: sw          $s6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r22;
    // 0x80061F74: sw          $s3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r19;
    // 0x80061F78: sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // 0x80061F7C: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x80061F80: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x80061F84: sdc1        $f20, 0x38($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X38, ctx->r29);
    // 0x80061F88: lw          $s6, 0x0($v0)
    ctx->r22 = MEM_W(ctx->r2, 0X0);
    // 0x80061F8C: addiu       $s3, $zero, -0x2710
    ctx->r19 = ADD32(0, -0X2710);
    // 0x80061F90: addu        $v1, $s6, $v1
    ctx->r3 = ADD32(ctx->r22, ctx->r3);
    // 0x80061F94: lw          $s1, 0x34($v1)
    ctx->r17 = MEM_W(ctx->r3, 0X34);
    // 0x80061F98: lhu         $v0, 0x8($s1)
    ctx->r2 = MEM_HU(ctx->r17, 0X8);
    // 0x80061F9C: mtc1        $a2, $f20
    ctx->f20.u32l = ctx->r6;
    // 0x80061FA0: beq         $v0, $zero, L_80062024
    if (ctx->r2 == 0) {
        // 0x80061FA4: addu        $s2, $zero, $zero
        ctx->r18 = ADD32(0, 0);
            goto L_80062024;
    }
    // 0x80061FA4: addu        $s2, $zero, $zero
    ctx->r18 = ADD32(0, 0);
    // 0x80061FA8: sll         $s0, $s2, 16
    ctx->r16 = S32(ctx->r18 << 16);
L_80061FAC:
    // 0x80061FAC: sra         $s0, $s0, 16
    ctx->r16 = S32(SIGNED(ctx->r16) >> 16);
    // 0x80061FB0: lw          $v1, 0xC($s1)
    ctx->r3 = MEM_W(ctx->r17, 0XC);
    // 0x80061FB4: sll         $v0, $s0, 1
    ctx->r2 = S32(ctx->r16 << 1);
    // 0x80061FB8: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80061FBC: lhu         $a1, 0x0($v0)
    ctx->r5 = MEM_HU(ctx->r2, 0X0);
    // 0x80061FC0: jal         0x80063A68
    // 0x80061FC4: andi        $a0, $s5, 0xFFFF
    ctx->r4 = ctx->r21 & 0XFFFF;
    func_80063A68(rdram, ctx);
        goto after_0;
    // 0x80061FC4: andi        $a0, $s5, 0xFFFF
    ctx->r4 = ctx->r21 & 0XFFFF;
    after_0:
    // 0x80061FC8: lw          $v1, 0x10($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X10);
    // 0x80061FCC: sll         $s0, $s0, 2
    ctx->r16 = S32(ctx->r16 << 2);
    // 0x80061FD0: addu        $s0, $s0, $v1
    ctx->r16 = ADD32(ctx->r16, ctx->r3);
    // 0x80061FD4: lhu         $s0, 0x0($s0)
    ctx->r16 = MEM_HU(ctx->r16, 0X0);
    // 0x80061FD8: addu        $a0, $s0, $v0
    ctx->r4 = ADD32(ctx->r16, ctx->r2);
    // 0x80061FDC: sll         $v1, $a0, 16
    ctx->r3 = S32(ctx->r4 << 16);
    // 0x80061FE0: sll         $v0, $s3, 16
    ctx->r2 = S32(ctx->r19 << 16);
    // 0x80061FE4: slt         $v0, $v0, $v1
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80061FE8: bnel        $v0, $zero, L_80061FF0
    if (ctx->r2 != 0) {
        // 0x80061FEC: addu        $s3, $a0, $zero
        ctx->r19 = ADD32(ctx->r4, 0);
            goto L_80061FF0;
    }
    goto skip_0;
    // 0x80061FEC: addu        $s3, $a0, $zero
    ctx->r19 = ADD32(ctx->r4, 0);
    skip_0:
L_80061FF0:
    // 0x80061FF0: sll         $v0, $s0, 16
    ctx->r2 = S32(ctx->r16 << 16);
    // 0x80061FF4: sll         $v1, $s4, 16
    ctx->r3 = S32(ctx->r20 << 16);
    // 0x80061FF8: slt         $v0, $v0, $v1
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80061FFC: bnel        $v0, $zero, L_80062004
    if (ctx->r2 != 0) {
        // 0x80062000: addu        $s4, $s0, $zero
        ctx->r20 = ADD32(ctx->r16, 0);
            goto L_80062004;
    }
    goto skip_1;
    // 0x80062000: addu        $s4, $s0, $zero
    ctx->r20 = ADD32(ctx->r16, 0);
    skip_1:
L_80062004:
    // 0x80062004: addiu       $v0, $s2, 0x1
    ctx->r2 = ADD32(ctx->r18, 0X1);
    // 0x80062008: addu        $s2, $v0, $zero
    ctx->r18 = ADD32(ctx->r2, 0);
    // 0x8006200C: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x80062010: lhu         $v1, 0x8($s1)
    ctx->r3 = MEM_HU(ctx->r17, 0X8);
    // 0x80062014: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x80062018: slt         $v0, $v0, $v1
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8006201C: bne         $v0, $zero, L_80061FAC
    if (ctx->r2 != 0) {
        // 0x80062020: sll         $s0, $s2, 16
        ctx->r16 = S32(ctx->r18 << 16);
            goto L_80061FAC;
    }
    // 0x80062020: sll         $s0, $s2, 16
    ctx->r16 = S32(ctx->r18 << 16);
L_80062024:
    // 0x80062024: sll         $a1, $s3, 16
    ctx->r5 = S32(ctx->r19 << 16);
    // 0x80062028: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
    // 0x8006202C: sll         $a0, $s4, 16
    ctx->r4 = S32(ctx->r20 << 16);
    // 0x80062030: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    // 0x80062034: subu        $a1, $a1, $a0
    ctx->r5 = SUB32(ctx->r5, ctx->r4);
    // 0x80062038: mtc1        $a1, $f4
    ctx->f4.u32l = ctx->r5;
    // 0x8006203C: cvt.s.w     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80062040: lhu         $v0, 0x8($s1)
    ctx->r2 = MEM_HU(ctx->r17, 0X8);
    // 0x80062044: lw          $a2, 0x10($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X10);
    // 0x80062048: lhu         $v1, 0x6($s6)
    ctx->r3 = MEM_HU(ctx->r22, 0X6);
    // 0x8006204C: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80062050: lwc1        $f8, -0x48C4($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X48C4);
    // 0x80062054: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80062058: addu        $v0, $v0, $a2
    ctx->r2 = ADD32(ctx->r2, ctx->r6);
    // 0x8006205C: mul.s       $f4, $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = MUL_S(ctx->f4.fl, ctx->f8.fl);
    // 0x80062060: lh          $v0, -0x2($v0)
    ctx->r2 = MEM_H(ctx->r2, -0X2);
    // 0x80062064: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80062068: lwc1        $f6, -0x48C0($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X48C0);
    // 0x8006206C: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80062070: lh          $v1, 0x2($a2)
    ctx->r3 = MEM_H(ctx->r6, 0X2);
    // 0x80062074: sub.s       $f6, $f6, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = ctx->f6.fl - ctx->f20.fl;
    // 0x80062078: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x8006207C: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x80062080: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x80062084: mul.s       $f0, $f6, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x80062088: mtc1        $a0, $f2
    ctx->f2.u32l = ctx->r4;
    // 0x8006208C: cvt.s.w     $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    ctx->f2.fl = CVT_S_W(ctx->f2.u32l);
    // 0x80062090: swc1        $f20, 0x24($s1)
    MEM_W(0X24, ctx->r17) = ctx->f20.u32l;
    // 0x80062094: swc1        $f20, 0x28($s1)
    MEM_W(0X28, ctx->r17) = ctx->f20.u32l;
    // 0x80062098: add.s       $f4, $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f2.fl;
    // 0x8006209C: andi        $v1, $s7, 0xFFFF
    ctx->r3 = ctx->r23 & 0XFFFF;
    // 0x800620A0: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x800620A4: mul.s       $f6, $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f6.fl, ctx->f4.fl);
    // 0x800620A8: addu        $v1, $s6, $v1
    ctx->r3 = ADD32(ctx->r22, ctx->r3);
    // 0x800620AC: lh          $v0, 0x98($v1)
    ctx->r2 = MEM_H(ctx->r3, 0X98);
    // 0x800620B0: mtc1        $v0, $f2
    ctx->f2.u32l = ctx->r2;
    // 0x800620B4: cvt.s.w     $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    ctx->f2.fl = CVT_S_W(ctx->f2.u32l);
    // 0x800620B8: add.s       $f2, $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f6.fl;
    // 0x800620BC: mul.s       $f0, $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x800620C0: swc1        $f2, 0x18($s1)
    MEM_W(0X18, ctx->r17) = ctx->f2.u32l;
    // 0x800620C4: lh          $v0, 0x9A($v1)
    ctx->r2 = MEM_H(ctx->r3, 0X9A);
    // 0x800620C8: mtc1        $v0, $f2
    ctx->f2.u32l = ctx->r2;
    // 0x800620CC: cvt.s.w     $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    ctx->f2.fl = CVT_S_W(ctx->f2.u32l);
    // 0x800620D0: add.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x800620D4: swc1        $f2, 0x1C($s1)
    MEM_W(0X1C, ctx->r17) = ctx->f2.u32l;
    // 0x800620D8: lw          $ra, 0x30($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X30);
    // 0x800620DC: lw          $s7, 0x2C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X2C);
    // 0x800620E0: lw          $s6, 0x28($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X28);
    // 0x800620E4: lw          $s5, 0x24($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X24);
    // 0x800620E8: lw          $s4, 0x20($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X20);
    // 0x800620EC: lw          $s3, 0x1C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X1C);
    // 0x800620F0: lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X18);
    // 0x800620F4: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x800620F8: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x800620FC: ldc1        $f20, 0x38($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X38);
    // 0x80062100: jr          $ra
    // 0x80062104: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x80062104: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void func_80062108(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80062108: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x8006210C: sw          $s0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r16;
    // 0x80062110: addu        $s0, $a3, $zero
    ctx->r16 = ADD32(ctx->r7, 0);
    // 0x80062114: sw          $s6, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r22;
    // 0x80062118: addu        $s6, $zero, $zero
    ctx->r22 = ADD32(0, 0);
    // 0x8006211C: sw          $s5, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r21;
    // 0x80062120: addu        $s5, $zero, $zero
    ctx->r21 = ADD32(0, 0);
    // 0x80062124: sw          $s3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r19;
    // 0x80062128: addu        $s3, $zero, $zero
    ctx->r19 = ADD32(0, 0);
    // 0x8006212C: lui         $v1, 0x800A
    ctx->r3 = S32(0X800A << 16);
    // 0x80062130: sh          $a0, 0x10($sp)
    MEM_H(0X10, ctx->r29) = ctx->r4;
    // 0x80062134: lhu         $v0, 0x10($sp)
    ctx->r2 = MEM_HU(ctx->r29, 0X10);
    // 0x80062138: lhu         $t1, 0x6A($sp)
    ctx->r9 = MEM_HU(ctx->r29, 0X6A);
    // 0x8006213C: addiu       $v1, $v1, -0x3F0
    ctx->r3 = ADD32(ctx->r3, -0X3F0);
    // 0x80062140: sw          $ra, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r31;
    // 0x80062144: sw          $fp, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r30;
    // 0x80062148: sw          $s7, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r23;
    // 0x8006214C: sw          $s4, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r20;
    // 0x80062150: sw          $s2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r18;
    // 0x80062154: sw          $s1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r17;
    // 0x80062158: sw          $a1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r5;
    // 0x8006215C: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80062160: sh          $t1, 0x1E($sp)
    MEM_H(0X1E, ctx->r29) = ctx->r9;
    // 0x80062164: lhu         $t1, 0x6E($sp)
    ctx->r9 = MEM_HU(ctx->r29, 0X6E);
    // 0x80062168: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8006216C: sh          $t1, 0x26($sp)
    MEM_H(0X26, ctx->r29) = ctx->r9;
    // 0x80062170: lw          $s1, 0x0($v0)
    ctx->r17 = MEM_W(ctx->r2, 0X0);
    // 0x80062174: lw          $t1, 0xC($a1)
    ctx->r9 = MEM_W(ctx->r5, 0XC);
    // 0x80062178: sw          $t1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r9;
    // 0x8006217C: lw          $s7, 0x10($a1)
    ctx->r23 = MEM_W(ctx->r5, 0X10);
    // 0x80062180: jal         0x80064248
    // 0x80062184: addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    func_80064248(rdram, ctx);
        goto after_0;
    // 0x80062184: addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    after_0:
    // 0x80062188: addu        $a2, $v0, $zero
    ctx->r6 = ADD32(ctx->r2, 0);
    // 0x8006218C: addiu       $fp, $zero, 0xFF
    ctx->r30 = ADD32(0, 0XFF);
    // 0x80062190: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x80062194: addu        $s2, $s7, $zero
    ctx->r18 = ADD32(ctx->r23, 0);
L_80062198:
    // 0x80062198: lbu         $a0, 0x0($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X0);
    // 0x8006219C: addiu       $t1, $zero, 0x20
    ctx->r9 = ADD32(0, 0X20);
    // 0x800621A0: andi        $v1, $a0, 0xFF
    ctx->r3 = ctx->r4 & 0XFF;
    // 0x800621A4: beq         $v1, $t1, L_800621FC
    if (ctx->r3 == ctx->r9) {
        // 0x800621A8: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_800621FC;
    }
    // 0x800621A8: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x800621AC: slti        $v0, $v1, 0x21
    ctx->r2 = SIGNED(ctx->r3) < 0X21 ? 1 : 0;
    // 0x800621B0: beq         $v0, $zero, L_800621E8
    if (ctx->r2 == 0) {
        // 0x800621B4: addiu       $v0, $zero, 0x9
        ctx->r2 = ADD32(0, 0X9);
            goto L_800621E8;
    }
    // 0x800621B4: addiu       $v0, $zero, 0x9
    ctx->r2 = ADD32(0, 0X9);
    // 0x800621B8: beq         $v1, $v0, L_80062218
    if (ctx->r3 == ctx->r2) {
        // 0x800621BC: slti        $v0, $v1, 0xA
        ctx->r2 = SIGNED(ctx->r3) < 0XA ? 1 : 0;
            goto L_80062218;
    }
    // 0x800621BC: slti        $v0, $v1, 0xA
    ctx->r2 = SIGNED(ctx->r3) < 0XA ? 1 : 0;
    // 0x800621C0: beql        $v0, $zero, L_800621D8
    if (ctx->r2 == 0) {
        // 0x800621C4: addiu       $t1, $zero, 0xA
        ctx->r9 = ADD32(0, 0XA);
            goto L_800621D8;
    }
    goto skip_0;
    // 0x800621C4: addiu       $t1, $zero, 0xA
    ctx->r9 = ADD32(0, 0XA);
    skip_0:
    // 0x800621C8: beq         $v1, $zero, L_8006241C
    if (ctx->r3 == 0) {
        // 0x800621CC: andi        $a0, $a0, 0xFF
        ctx->r4 = ctx->r4 & 0XFF;
            goto L_8006241C;
    }
    // 0x800621CC: andi        $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 & 0XFF;
    // 0x800621D0: j           L_80062298
    // 0x800621D4: sltiu       $v0, $a0, 0x20
    ctx->r2 = ctx->r4 < 0X20 ? 1 : 0;
        goto L_80062298;
    // 0x800621D4: sltiu       $v0, $a0, 0x20
    ctx->r2 = ctx->r4 < 0X20 ? 1 : 0;
L_800621D8:
    // 0x800621D8: beq         $v1, $t1, L_8006226C
    if (ctx->r3 == ctx->r9) {
        // 0x800621DC: andi        $a0, $a0, 0xFF
        ctx->r4 = ctx->r4 & 0XFF;
            goto L_8006226C;
    }
    // 0x800621DC: andi        $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 & 0XFF;
    // 0x800621E0: j           L_80062298
    // 0x800621E4: sltiu       $v0, $a0, 0x20
    ctx->r2 = ctx->r4 < 0X20 ? 1 : 0;
        goto L_80062298;
    // 0x800621E4: sltiu       $v0, $a0, 0x20
    ctx->r2 = ctx->r4 < 0X20 ? 1 : 0;
L_800621E8:
    // 0x800621E8: addiu       $v0, $zero, 0x7E
    ctx->r2 = ADD32(0, 0X7E);
    // 0x800621EC: beq         $v1, $v0, L_8006224C
    if (ctx->r3 == ctx->r2) {
        // 0x800621F0: andi        $a0, $a0, 0xFF
        ctx->r4 = ctx->r4 & 0XFF;
            goto L_8006224C;
    }
    // 0x800621F0: andi        $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 & 0XFF;
    // 0x800621F4: j           L_80062298
    // 0x800621F8: sltiu       $v0, $a0, 0x20
    ctx->r2 = ctx->r4 < 0X20 ? 1 : 0;
        goto L_80062298;
    // 0x800621F8: sltiu       $v0, $a0, 0x20
    ctx->r2 = ctx->r4 < 0X20 ? 1 : 0;
L_800621FC:
    // 0x800621FC: lbu         $v0, 0x1C($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X1C);
    // 0x80062200: lhu         $v1, 0x2($s1)
    ctx->r3 = MEM_HU(ctx->r17, 0X2);
    // 0x80062204: lhu         $a0, 0x8($s1)
    ctx->r4 = MEM_HU(ctx->r17, 0X8);
    // 0x80062208: sll         $v0, $v0, 24
    ctx->r2 = S32(ctx->r2 << 24);
    // 0x8006220C: sra         $v0, $v0, 24
    ctx->r2 = S32(SIGNED(ctx->r2) >> 24);
    // 0x80062210: j           L_80062338
    // 0x80062214: addu        $v1, $v1, $a0
    ctx->r3 = ADD32(ctx->r3, ctx->r4);
        goto L_80062338;
    // 0x80062214: addu        $v1, $v1, $a0
    ctx->r3 = ADD32(ctx->r3, ctx->r4);
L_80062218:
    // 0x80062218: lw          $a0, 0xFC($s1)
    ctx->r4 = MEM_W(ctx->r17, 0XFC);
    // 0x8006221C: beq         $a0, $zero, L_80062198
    if (ctx->r4 == 0) {
        // 0x80062220: andi        $v0, $s6, 0xFF
        ctx->r2 = ctx->r22 & 0XFF;
            goto L_80062198;
    }
    // 0x80062220: andi        $v0, $s6, 0xFF
    ctx->r2 = ctx->r22 & 0XFF;
    // 0x80062224: sll         $v1, $v0, 1
    ctx->r3 = S32(ctx->r2 << 1);
    // 0x80062228: addu        $v1, $v1, $a0
    ctx->r3 = ADD32(ctx->r3, ctx->r4);
    // 0x8006222C: lh          $a0, 0x100($s1)
    ctx->r4 = MEM_H(ctx->r17, 0X100);
    // 0x80062230: lhu         $a2, 0x0($v1)
    ctx->r6 = MEM_HU(ctx->r3, 0X0);
    // 0x80062234: addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
    // 0x80062238: slt         $v0, $v0, $a0
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x8006223C: bnel        $v0, $zero, L_80062198
    if (ctx->r2 != 0) {
        // 0x80062240: addiu       $s6, $s6, 0x1
        ctx->r22 = ADD32(ctx->r22, 0X1);
            goto L_80062198;
    }
    goto skip_1;
    // 0x80062240: addiu       $s6, $s6, 0x1
    ctx->r22 = ADD32(ctx->r22, 0X1);
    skip_1:
    // 0x80062244: j           L_80062198
    // 0x80062248: nop

        goto L_80062198;
    // 0x80062248: nop

L_8006224C:
    // 0x8006224C: addiu       $a0, $s5, 0x1
    ctx->r4 = ADD32(ctx->r21, 0X1);
    // 0x80062250: addu        $s5, $a0, $zero
    ctx->r21 = ADD32(ctx->r4, 0);
    // 0x80062254: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x80062258: jal         0x80064248
    // 0x8006225C: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    func_80064248(rdram, ctx);
        goto after_1;
    // 0x8006225C: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    after_1:
    // 0x80062260: addu        $a2, $v0, $zero
    ctx->r6 = ADD32(ctx->r2, 0);
    // 0x80062264: j           L_80062198
    // 0x80062268: addu        $s6, $zero, $zero
    ctx->r22 = ADD32(0, 0);
        goto L_80062198;
    // 0x80062268: addu        $s6, $zero, $zero
    ctx->r22 = ADD32(0, 0);
L_8006226C:
    // 0x8006226C: lhu         $a0, 0x4($s1)
    ctx->r4 = MEM_HU(ctx->r17, 0X4);
    // 0x80062270: lhu         $v0, 0xA($s1)
    ctx->r2 = MEM_HU(ctx->r17, 0XA);
    // 0x80062274: addu        $s6, $zero, $zero
    ctx->r22 = ADD32(0, 0);
    // 0x80062278: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // 0x8006227C: addu        $a0, $s5, $a0
    ctx->r4 = ADD32(ctx->r21, ctx->r4);
    // 0x80062280: addu        $s5, $a0, $zero
    ctx->r21 = ADD32(ctx->r4, 0);
    // 0x80062284: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x80062288: jal         0x80064248
    // 0x8006228C: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    func_80064248(rdram, ctx);
        goto after_2;
    // 0x8006228C: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    after_2:
    // 0x80062290: j           L_80062198
    // 0x80062294: addu        $a2, $v0, $zero
    ctx->r6 = ADD32(ctx->r2, 0);
        goto L_80062198;
    // 0x80062294: addu        $a2, $v0, $zero
    ctx->r6 = ADD32(ctx->r2, 0);
L_80062298:
    // 0x80062298: bne         $v0, $zero, L_80062328
    if (ctx->r2 != 0) {
        // 0x8006229C: sltiu       $v0, $a0, 0x7
        ctx->r2 = ctx->r4 < 0X7 ? 1 : 0;
            goto L_80062328;
    }
    // 0x8006229C: sltiu       $v0, $a0, 0x7
    ctx->r2 = ctx->r4 < 0X7 ? 1 : 0;
    // 0x800622A0: lw          $v0, 0x20($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X20);
    // 0x800622A4: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x800622A8: lbu         $a0, 0x0($v0)
    ctx->r4 = MEM_BU(ctx->r2, 0X0);
    // 0x800622AC: andi        $a1, $a0, 0xFF
    ctx->r5 = ctx->r4 & 0XFF;
    // 0x800622B0: beq         $a1, $fp, L_80062330
    if (ctx->r5 == ctx->r30) {
        // 0x800622B4: nop
    
            goto L_80062330;
    }
    // 0x800622B4: nop

    // 0x800622B8: lbu         $v0, 0x102($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X102);
    // 0x800622BC: beq         $v0, $zero, L_800622D0
    if (ctx->r2 == 0) {
        // 0x800622C0: addu        $a3, $s4, $zero
        ctx->r7 = ADD32(ctx->r20, 0);
            goto L_800622D0;
    }
    // 0x800622C0: addu        $a3, $s4, $zero
    ctx->r7 = ADD32(ctx->r20, 0);
    // 0x800622C4: lw          $v1, 0x28($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X28);
    // 0x800622C8: j           L_800622D8
    // 0x800622CC: sll         $v0, $a1, 1
    ctx->r2 = S32(ctx->r5 << 1);
        goto L_800622D8;
    // 0x800622CC: sll         $v0, $a1, 1
    ctx->r2 = S32(ctx->r5 << 1);
L_800622D0:
    // 0x800622D0: lw          $v1, 0x24($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X24);
    // 0x800622D4: sll         $v0, $a1, 1
    ctx->r2 = S32(ctx->r5 << 1);
L_800622D8:
    // 0x800622D8: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800622DC: lhu         $v0, 0x0($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X0);
    // 0x800622E0: sh          $v0, 0x0($a3)
    MEM_H(0X0, ctx->r7) = ctx->r2;
    // 0x800622E4: sll         $v0, $a2, 16
    ctx->r2 = S32(ctx->r6 << 16);
    // 0x800622E8: sra         $a1, $v0, 16
    ctx->r5 = S32(SIGNED(ctx->r2) >> 16);
    // 0x800622EC: sh          $a2, 0x0($s2)
    MEM_H(0X0, ctx->r18) = ctx->r6;
    // 0x800622F0: sh          $s5, 0x2($s2)
    MEM_H(0X2, ctx->r18) = ctx->r21;
    // 0x800622F4: lbu         $v0, 0x14($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X14);
    // 0x800622F8: lh          $v1, 0x8($s1)
    ctx->r3 = MEM_H(ctx->r17, 0X8);
    // 0x800622FC: beq         $v0, $zero, L_80062310
    if (ctx->r2 == 0) {
        // 0x80062300: nop
    
            goto L_80062310;
    }
    // 0x80062300: nop

    // 0x80062304: lhu         $v0, 0x2($s1)
    ctx->r2 = MEM_HU(ctx->r17, 0X2);
    // 0x80062308: j           L_80062320
    // 0x8006230C: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
        goto L_80062320;
    // 0x8006230C: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
L_80062310:
    // 0x80062310: lw          $v0, 0x18($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X18);
    // 0x80062314: addu        $v0, $a0, $v0
    ctx->r2 = ADD32(ctx->r4, ctx->r2);
    // 0x80062318: lbu         $v0, 0x0($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X0);
    // 0x8006231C: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
L_80062320:
    // 0x80062320: j           L_800623A8
    // 0x80062324: addu        $a2, $a1, $v0
    ctx->r6 = ADD32(ctx->r5, ctx->r2);
        goto L_800623A8;
    // 0x80062324: addu        $a2, $a1, $v0
    ctx->r6 = ADD32(ctx->r5, ctx->r2);
L_80062328:
    // 0x80062328: bne         $v0, $zero, L_80062344
    if (ctx->r2 != 0) {
        // 0x8006232C: addiu       $a0, $a0, -0x1
        ctx->r4 = ADD32(ctx->r4, -0X1);
            goto L_80062344;
    }
    // 0x8006232C: addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
L_80062330:
    // 0x80062330: lhu         $v0, 0x2($s1)
    ctx->r2 = MEM_HU(ctx->r17, 0X2);
    // 0x80062334: lhu         $v1, 0x8($s1)
    ctx->r3 = MEM_HU(ctx->r17, 0X8);
L_80062338:
    // 0x80062338: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8006233C: j           L_80062198
    // 0x80062340: addu        $a2, $a2, $v0
    ctx->r6 = ADD32(ctx->r6, ctx->r2);
        goto L_80062198;
    // 0x80062340: addu        $a2, $a2, $v0
    ctx->r6 = ADD32(ctx->r6, ctx->r2);
L_80062344:
    // 0x80062344: sll         $v0, $a0, 1
    ctx->r2 = S32(ctx->r4 << 1);
    // 0x80062348: lui         $t1, 0x8014
    ctx->r9 = S32(0X8014 << 16);
    // 0x8006234C: addiu       $t1, $t1, -0x6690
    ctx->r9 = ADD32(ctx->r9, -0X6690);
    // 0x80062350: addu        $v0, $v0, $t1
    ctx->r2 = ADD32(ctx->r2, ctx->r9);
    // 0x80062354: sll         $v1, $a0, 2
    ctx->r3 = S32(ctx->r4 << 2);
    // 0x80062358: lui         $t1, 0x800A
    ctx->r9 = S32(0X800A << 16);
    // 0x8006235C: addiu       $t1, $t1, -0x1270
    ctx->r9 = ADD32(ctx->r9, -0X1270);
    // 0x80062360: lhu         $v0, 0x0($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X0);
    // 0x80062364: addu        $v1, $v1, $t1
    ctx->r3 = ADD32(ctx->r3, ctx->r9);
    // 0x80062368: sh          $v0, 0x0($s4)
    MEM_H(0X0, ctx->r20) = ctx->r2;
    // 0x8006236C: lhu         $v0, 0x0($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X0);
    // 0x80062370: addu        $v0, $a2, $v0
    ctx->r2 = ADD32(ctx->r6, ctx->r2);
    // 0x80062374: sh          $v0, 0x0($s2)
    MEM_H(0X0, ctx->r18) = ctx->r2;
    // 0x80062378: lhu         $v0, 0x2($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X2);
    // 0x8006237C: addu        $v0, $s5, $v0
    ctx->r2 = ADD32(ctx->r21, ctx->r2);
    // 0x80062380: sh          $v0, 0x2($s2)
    MEM_H(0X2, ctx->r18) = ctx->r2;
    // 0x80062384: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x80062388: addiu       $v0, $v0, -0x1278
    ctx->r2 = ADD32(ctx->r2, -0X1278);
    // 0x8006238C: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // 0x80062390: lbu         $v0, 0x0($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X0);
    // 0x80062394: lhu         $v1, 0x8($s1)
    ctx->r3 = MEM_HU(ctx->r17, 0X8);
    // 0x80062398: sll         $v0, $v0, 24
    ctx->r2 = S32(ctx->r2 << 24);
    // 0x8006239C: sra         $v0, $v0, 24
    ctx->r2 = S32(SIGNED(ctx->r2) >> 24);
    // 0x800623A0: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800623A4: addu        $a2, $a2, $v0
    ctx->r6 = ADD32(ctx->r6, ctx->r2);
L_800623A8:
    // 0x800623A8: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
    // 0x800623AC: addiu       $s4, $s4, 0x2
    ctx->r20 = ADD32(ctx->r20, 0X2);
    // 0x800623B0: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x800623B4: lbu         $v0, -0x66A0($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X66A0);
    // 0x800623B8: andi        $v0, $v0, 0x4
    ctx->r2 = ctx->r2 & 0X4;
    // 0x800623BC: beq         $v0, $zero, L_80062198
    if (ctx->r2 == 0) {
        // 0x800623C0: addiu       $s3, $s3, 0x1
        ctx->r19 = ADD32(ctx->r19, 0X1);
            goto L_80062198;
    }
    // 0x800623C0: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x800623C4: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x800623C8: sll         $v1, $a2, 16
    ctx->r3 = S32(ctx->r6 << 16);
    // 0x800623CC: lh          $v0, -0x669C($v0)
    ctx->r2 = MEM_H(ctx->r2, -0X669C);
    // 0x800623D0: sra         $v1, $v1, 16
    ctx->r3 = S32(SIGNED(ctx->r3) >> 16);
    // 0x800623D4: slt         $v0, $v0, $v1
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800623D8: beq         $v0, $zero, L_80062198
    if (ctx->r2 == 0) {
        // 0x800623DC: nop
    
            goto L_80062198;
    }
    // 0x800623DC: nop

    // 0x800623E0: addiu       $s0, $s0, -0x1
    ctx->r16 = ADD32(ctx->r16, -0X1);
L_800623E4:
    // 0x800623E4: lbu         $v1, 0x0($s0)
    ctx->r3 = MEM_BU(ctx->r16, 0X0);
    // 0x800623E8: lw          $v0, 0x20($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X20);
    // 0x800623EC: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800623F0: lbu         $v0, 0x0($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X0);
    // 0x800623F4: beq         $v0, $fp, L_80062408
    if (ctx->r2 == ctx->r30) {
        // 0x800623F8: addiu       $t1, $zero, 0x20
        ctx->r9 = ADD32(0, 0X20);
            goto L_80062408;
    }
    // 0x800623F8: addiu       $t1, $zero, 0x20
    ctx->r9 = ADD32(0, 0X20);
    // 0x800623FC: addiu       $s2, $s2, -0x4
    ctx->r18 = ADD32(ctx->r18, -0X4);
    // 0x80062400: addiu       $s4, $s4, -0x2
    ctx->r20 = ADD32(ctx->r20, -0X2);
    // 0x80062404: addiu       $s3, $s3, -0x1
    ctx->r19 = ADD32(ctx->r19, -0X1);
L_80062408:
    // 0x80062408: bnel        $v1, $t1, L_800623E4
    if (ctx->r3 != ctx->r9) {
        // 0x8006240C: addiu       $s0, $s0, -0x1
        ctx->r16 = ADD32(ctx->r16, -0X1);
            goto L_800623E4;
    }
    goto skip_2;
    // 0x8006240C: addiu       $s0, $s0, -0x1
    ctx->r16 = ADD32(ctx->r16, -0X1);
    skip_2:
    // 0x80062410: addiu       $t1, $zero, 0xA
    ctx->r9 = ADD32(0, 0XA);
    // 0x80062414: j           L_80062198
    // 0x80062418: sb          $t1, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r9;
        goto L_80062198;
    // 0x80062418: sb          $t1, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r9;
L_8006241C:
    // 0x8006241C: lw          $t1, 0x5C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X5C);
    // 0x80062420: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80062424: sh          $s3, 0x8($t1)
    MEM_H(0X8, ctx->r9) = ctx->r19;
    // 0x80062428: lhu         $t1, 0x1E($sp)
    ctx->r9 = MEM_HU(ctx->r29, 0X1E);
    // 0x8006242C: lbu         $v1, -0x66A0($a0)
    ctx->r3 = MEM_BU(ctx->r4, -0X66A0);
    // 0x80062430: sll         $v0, $t1, 16
    ctx->r2 = S32(ctx->r9 << 16);
    // 0x80062434: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x80062438: lw          $t1, 0x5C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X5C);
    // 0x8006243C: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x80062440: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x80062444: swc1        $f0, 0x18($t1)
    MEM_W(0X18, ctx->r9) = ctx->f0.u32l;
    // 0x80062448: lhu         $t1, 0x26($sp)
    ctx->r9 = MEM_HU(ctx->r29, 0X26);
    // 0x8006244C: andi        $v1, $v1, 0x12
    ctx->r3 = ctx->r3 & 0X12;
    // 0x80062450: sll         $v0, $t1, 16
    ctx->r2 = S32(ctx->r9 << 16);
    // 0x80062454: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x80062458: lw          $t1, 0x5C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X5C);
    // 0x8006245C: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x80062460: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x80062464: beq         $v1, $zero, L_80062594
    if (ctx->r3 == 0) {
        // 0x80062468: swc1        $f0, 0x1C($t1)
        MEM_W(0X1C, ctx->r9) = ctx->f0.u32l;
            goto L_80062594;
    }
    // 0x80062468: swc1        $f0, 0x1C($t1)
    MEM_W(0X1C, ctx->r9) = ctx->f0.u32l;
    // 0x8006246C: beq         $s3, $zero, L_80062594
    if (ctx->r19 == 0) {
        // 0x80062470: addu        $s1, $zero, $zero
        ctx->r17 = ADD32(0, 0);
            goto L_80062594;
    }
    // 0x80062470: addu        $s1, $zero, $zero
    ctx->r17 = ADD32(0, 0);
    // 0x80062474: addiu       $s4, $s3, -0x1
    ctx->r20 = ADD32(ctx->r19, -0X1);
    // 0x80062478: lui         $s6, 0x8014
    ctx->r22 = S32(0X8014 << 16);
    // 0x8006247C: addu        $s5, $a0, $zero
    ctx->r21 = ADD32(ctx->r4, 0);
L_80062480:
    // 0x80062480: sltu        $v0, $s1, $s3
    ctx->r2 = ctx->r17 < ctx->r19 ? 1 : 0;
    // 0x80062484: beq         $v0, $zero, L_800624DC
    if (ctx->r2 == 0) {
        // 0x80062488: addu        $s2, $s1, $zero
        ctx->r18 = ADD32(ctx->r17, 0);
            goto L_800624DC;
    }
    // 0x80062488: addu        $s2, $s1, $zero
    ctx->r18 = ADD32(ctx->r17, 0);
    // 0x8006248C: addu        $v0, $s2, $zero
    ctx->r2 = ADD32(ctx->r18, 0);
L_80062490:
    // 0x80062490: addiu       $a0, $v0, 0x1
    ctx->r4 = ADD32(ctx->r2, 0X1);
    // 0x80062494: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x80062498: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x8006249C: sltu        $v0, $v0, $s4
    ctx->r2 = ctx->r2 < ctx->r20 ? 1 : 0;
    // 0x800624A0: beq         $v0, $zero, L_800624C8
    if (ctx->r2 == 0) {
        // 0x800624A4: addu        $s2, $a0, $zero
        ctx->r18 = ADD32(ctx->r4, 0);
            goto L_800624C8;
    }
    // 0x800624A4: addu        $s2, $a0, $zero
    ctx->r18 = ADD32(ctx->r4, 0);
    // 0x800624A8: sll         $v0, $a0, 16
    ctx->r2 = S32(ctx->r4 << 16);
    // 0x800624AC: sra         $v0, $v0, 14
    ctx->r2 = S32(SIGNED(ctx->r2) >> 14);
    // 0x800624B0: addu        $v0, $v0, $s7
    ctx->r2 = ADD32(ctx->r2, ctx->r23);
    // 0x800624B4: lh          $v1, 0x0($v0)
    ctx->r3 = MEM_H(ctx->r2, 0X0);
    // 0x800624B8: lh          $v0, -0x4($v0)
    ctx->r2 = MEM_H(ctx->r2, -0X4);
    // 0x800624BC: slt         $v0, $v0, $v1
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800624C0: beq         $v0, $zero, L_800624E0
    if (ctx->r2 == 0) {
        // 0x800624C4: sll         $v0, $s2, 16
        ctx->r2 = S32(ctx->r18 << 16);
            goto L_800624E0;
    }
    // 0x800624C4: sll         $v0, $s2, 16
    ctx->r2 = S32(ctx->r18 << 16);
L_800624C8:
    // 0x800624C8: sll         $v0, $a0, 16
    ctx->r2 = S32(ctx->r4 << 16);
    // 0x800624CC: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x800624D0: sltu        $v0, $v0, $s3
    ctx->r2 = ctx->r2 < ctx->r19 ? 1 : 0;
    // 0x800624D4: bne         $v0, $zero, L_80062490
    if (ctx->r2 != 0) {
        // 0x800624D8: addu        $v0, $s2, $zero
        ctx->r2 = ADD32(ctx->r18, 0);
            goto L_80062490;
    }
    // 0x800624D8: addu        $v0, $s2, $zero
    ctx->r2 = ADD32(ctx->r18, 0);
L_800624DC:
    // 0x800624DC: sll         $v0, $s2, 16
    ctx->r2 = S32(ctx->r18 << 16);
L_800624E0:
    // 0x800624E0: sra         $s0, $v0, 16
    ctx->r16 = S32(SIGNED(ctx->r2) >> 16);
    // 0x800624E4: sll         $v0, $s0, 1
    ctx->r2 = S32(ctx->r16 << 1);
    // 0x800624E8: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x800624EC: lhu         $a0, 0x10($sp)
    ctx->r4 = MEM_HU(ctx->r29, 0X10);
    // 0x800624F0: addu        $v0, $v0, $t1
    ctx->r2 = ADD32(ctx->r2, ctx->r9);
    // 0x800624F4: lhu         $a1, -0x2($v0)
    ctx->r5 = MEM_HU(ctx->r2, -0X2);
    // 0x800624F8: jal         0x80063A68
    // 0x800624FC: nop

    func_80063A68(rdram, ctx);
        goto after_3;
    // 0x800624FC: nop

    after_3:
    // 0x80062500: sll         $v1, $s0, 2
    ctx->r3 = S32(ctx->r16 << 2);
    // 0x80062504: addu        $v1, $v1, $s7
    ctx->r3 = ADD32(ctx->r3, ctx->r23);
    // 0x80062508: lhu         $v1, -0x4($v1)
    ctx->r3 = MEM_HU(ctx->r3, -0X4);
    // 0x8006250C: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x80062510: slt         $v0, $s1, $s0
    ctx->r2 = SIGNED(ctx->r17) < SIGNED(ctx->r16) ? 1 : 0;
    // 0x80062514: beq         $v0, $zero, L_80062580
    if (ctx->r2 == 0) {
        // 0x80062518: addu        $a1, $s1, $zero
        ctx->r5 = ADD32(ctx->r17, 0);
            goto L_80062580;
    }
    // 0x80062518: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    // 0x8006251C: lbu         $v0, -0x66A0($s5)
    ctx->r2 = MEM_BU(ctx->r21, -0X66A0);
    // 0x80062520: addu        $t0, $s0, $zero
    ctx->r8 = ADD32(ctx->r16, 0);
    // 0x80062524: andi        $a3, $v0, 0x2
    ctx->r7 = ctx->r2 & 0X2;
    // 0x80062528: sll         $v0, $v1, 16
    ctx->r2 = S32(ctx->r3 << 16);
    // 0x8006252C: lh          $v1, -0x669E($s6)
    ctx->r3 = MEM_H(ctx->r22, -0X669E);
    // 0x80062530: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x80062534: subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // 0x80062538: srl         $v0, $v1, 31
    ctx->r2 = S32(U32(ctx->r3) >> 31);
    // 0x8006253C: addu        $v0, $v1, $v0
    ctx->r2 = ADD32(ctx->r3, ctx->r2);
    // 0x80062540: sra         $a2, $v0, 1
    ctx->r6 = S32(SIGNED(ctx->r2) >> 1);
    // 0x80062544: sll         $v0, $a1, 16
    ctx->r2 = S32(ctx->r5 << 16);
L_80062548:
    // 0x80062548: sra         $v0, $v0, 14
    ctx->r2 = S32(SIGNED(ctx->r2) >> 14);
    // 0x8006254C: addu        $v0, $v0, $s7
    ctx->r2 = ADD32(ctx->r2, ctx->r23);
    // 0x80062550: lh          $a0, 0x0($v0)
    ctx->r4 = MEM_H(ctx->r2, 0X0);
    // 0x80062554: beql        $a3, $zero, L_80062560
    if (ctx->r7 == 0) {
        // 0x80062558: addu        $a0, $a0, $v1
        ctx->r4 = ADD32(ctx->r4, ctx->r3);
            goto L_80062560;
    }
    goto skip_3;
    // 0x80062558: addu        $a0, $a0, $v1
    ctx->r4 = ADD32(ctx->r4, ctx->r3);
    skip_3:
    // 0x8006255C: addu        $a0, $a0, $a2
    ctx->r4 = ADD32(ctx->r4, ctx->r6);
L_80062560:
    // 0x80062560: sh          $a0, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r4;
    // 0x80062564: addiu       $v0, $a1, 0x1
    ctx->r2 = ADD32(ctx->r5, 0X1);
    // 0x80062568: addu        $a1, $v0, $zero
    ctx->r5 = ADD32(ctx->r2, 0);
    // 0x8006256C: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x80062570: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x80062574: slt         $v0, $v0, $t0
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x80062578: bne         $v0, $zero, L_80062548
    if (ctx->r2 != 0) {
        // 0x8006257C: sll         $v0, $a1, 16
        ctx->r2 = S32(ctx->r5 << 16);
            goto L_80062548;
    }
    // 0x8006257C: sll         $v0, $a1, 16
    ctx->r2 = S32(ctx->r5 << 16);
L_80062580:
    // 0x80062580: sll         $v0, $s2, 16
    ctx->r2 = S32(ctx->r18 << 16);
    // 0x80062584: sra         $s1, $v0, 16
    ctx->r17 = S32(SIGNED(ctx->r2) >> 16);
    // 0x80062588: sltu        $v0, $s1, $s3
    ctx->r2 = ctx->r17 < ctx->r19 ? 1 : 0;
    // 0x8006258C: bne         $v0, $zero, L_80062480
    if (ctx->r2 != 0) {
        // 0x80062590: nop
    
            goto L_80062480;
    }
    // 0x80062590: nop

L_80062594:
    // 0x80062594: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
    // 0x80062598: lw          $fp, 0x50($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X50);
    // 0x8006259C: lw          $s7, 0x4C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X4C);
    // 0x800625A0: lw          $s6, 0x48($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X48);
    // 0x800625A4: lw          $s5, 0x44($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X44);
    // 0x800625A8: lw          $s4, 0x40($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X40);
    // 0x800625AC: lw          $s3, 0x3C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X3C);
    // 0x800625B0: lw          $s2, 0x38($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X38);
    // 0x800625B4: lw          $s1, 0x34($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X34);
    // 0x800625B8: lw          $s0, 0x30($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X30);
    // 0x800625BC: jr          $ra
    // 0x800625C0: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    return;
    // 0x800625C0: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
;}
RECOMP_FUNC void func_800625C4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800625C4: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x800625C8: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    // 0x800625CC: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x800625D0: addiu       $v0, $v0, -0x3F0
    ctx->r2 = ADD32(ctx->r2, -0X3F0);
    // 0x800625D4: sw          $s4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r20;
    // 0x800625D8: sh          $a0, 0x18($sp)
    MEM_H(0X18, ctx->r29) = ctx->r4;
    // 0x800625DC: andi        $s4, $a0, 0xFFFF
    ctx->r20 = ctx->r4 & 0XFFFF;
    // 0x800625E0: lhu         $t0, 0x22($sp)
    ctx->r8 = MEM_HU(ctx->r29, 0X22);
    // 0x800625E4: sll         $v1, $s4, 2
    ctx->r3 = S32(ctx->r20 << 2);
    // 0x800625E8: sw          $s3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r19;
    // 0x800625EC: addu        $s3, $v1, $v0
    ctx->r19 = ADD32(ctx->r3, ctx->r2);
    // 0x800625F0: sw          $ra, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r31;
    // 0x800625F4: sw          $fp, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r30;
    // 0x800625F8: sw          $s7, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r23;
    // 0x800625FC: sw          $s6, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r22;
    // 0x80062600: sw          $s5, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r21;
    // 0x80062604: sw          $s2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r18;
    // 0x80062608: sw          $s1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r17;
    // 0x8006260C: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x80062610: sw          $a1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r5;
    // 0x80062614: andi        $a0, $t0, 0xFFFF
    ctx->r4 = ctx->r8 & 0XFFFF;
    // 0x80062618: sh          $t0, 0x1C($sp)
    MEM_H(0X1C, ctx->r29) = ctx->r8;
    // 0x8006261C: lw          $s2, 0x0($s3)
    ctx->r18 = MEM_W(ctx->r19, 0X0);
    // 0x80062620: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80062624: lw          $v0, 0x30($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X30);
    // 0x80062628: sllv        $v1, $t0, $a0
    ctx->r3 = S32(ctx->r8 << (ctx->r4 & 31));
    // 0x8006262C: or          $v0, $v0, $v1
    ctx->r2 = ctx->r2 | ctx->r3;
    // 0x80062630: sw          $v0, 0x30($s2)
    MEM_W(0X30, ctx->r18) = ctx->r2;
    // 0x80062634: lw          $s5, 0x60($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X60);
    // 0x80062638: lw          $s6, 0x64($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X64);
    // 0x8006263C: lbu         $v1, 0x1F($s2)
    ctx->r3 = MEM_BU(ctx->r18, 0X1F);
    // 0x80062640: addu        $v0, $s2, $a0
    ctx->r2 = ADD32(ctx->r18, ctx->r4);
    // 0x80062644: sb          $v1, 0x84($v0)
    MEM_B(0X84, ctx->r2) = ctx->r3;
    // 0x80062648: lhu         $v0, 0xE8($s2)
    ctx->r2 = MEM_HU(ctx->r18, 0XE8);
    // 0x8006264C: mult        $v0, $a0
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80062650: sll         $v0, $a0, 2
    ctx->r2 = S32(ctx->r4 << 2);
    // 0x80062654: addu        $s1, $s2, $v0
    ctx->r17 = ADD32(ctx->r18, ctx->r2);
    // 0x80062658: lw          $v0, 0xEC($s2)
    ctx->r2 = MEM_W(ctx->r18, 0XEC);
    // 0x8006265C: lw          $s0, 0x34($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X34);
    // 0x80062660: mflo        $t0
    ctx->r8 = lo;
    // 0x80062664: sll         $v1, $t0, 2
    ctx->r3 = S32(ctx->r8 << 2);
    // 0x80062668: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8006266C: sw          $v0, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->r2;
    // 0x80062670: lhu         $v0, 0xE8($s2)
    ctx->r2 = MEM_HU(ctx->r18, 0XE8);
    // 0x80062674: mult        $v0, $a0
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80062678: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x8006267C: lw          $a3, 0x54($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X54);
    // 0x80062680: addu        $a0, $s4, $zero
    ctx->r4 = ADD32(ctx->r20, 0);
    // 0x80062684: lw          $v0, 0xF0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0XF0);
    // 0x80062688: mflo        $t0
    ctx->r8 = lo;
    // 0x8006268C: sll         $v1, $t0, 1
    ctx->r3 = S32(ctx->r8 << 1);
    // 0x80062690: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80062694: sw          $v0, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r2;
    // 0x80062698: sll         $v0, $s5, 16
    ctx->r2 = S32(ctx->r21 << 16);
    // 0x8006269C: sra         $fp, $v0, 16
    ctx->r30 = S32(SIGNED(ctx->r2) >> 16);
    // 0x800626A0: sll         $v0, $s6, 16
    ctx->r2 = S32(ctx->r22 << 16);
    // 0x800626A4: lhu         $v1, 0xE8($s2)
    ctx->r3 = MEM_HU(ctx->r18, 0XE8);
    // 0x800626A8: sra         $s7, $v0, 16
    ctx->r23 = S32(SIGNED(ctx->r2) >> 16);
    // 0x800626AC: sw          $fp, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r30;
    // 0x800626B0: sw          $s7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r23;
    // 0x800626B4: sh          $a2, 0x1A($sp)
    MEM_H(0X1A, ctx->r29) = ctx->r6;
    // 0x800626B8: jal         0x80062108
    // 0x800626BC: addu        $a2, $v1, $zero
    ctx->r6 = ADD32(ctx->r3, 0);
    func_80062108(rdram, ctx);
        goto after_0;
    // 0x800626BC: addu        $a2, $v1, $zero
    ctx->r6 = ADD32(ctx->r3, 0);
    after_0:
    // 0x800626C0: lw          $a0, 0xF4($s2)
    ctx->r4 = MEM_W(ctx->r18, 0XF4);
    // 0x800626C4: beq         $a0, $zero, L_800626DC
    if (ctx->r4 == 0) {
        // 0x800626C8: nop
    
            goto L_800626DC;
    }
    // 0x800626C8: nop

    // 0x800626CC: lhu         $a2, 0x8($s0)
    ctx->r6 = MEM_HU(ctx->r16, 0X8);
    // 0x800626D0: lw          $a1, 0x34($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X34);
    // 0x800626D4: jal         0x800646AC
    // 0x800626D8: sltu        $a2, $zero, $a2
    ctx->r6 = 0 < ctx->r6 ? 1 : 0;
    func_800646AC(rdram, ctx);
        goto after_1;
    // 0x800626D8: sltu        $a2, $zero, $a2
    ctx->r6 = 0 < ctx->r6 ? 1 : 0;
    after_1:
L_800626DC:
    // 0x800626DC: lbu         $v0, 0x1F($s2)
    ctx->r2 = MEM_BU(ctx->r18, 0X1F);
    // 0x800626E0: bne         $v0, $zero, L_800626F4
    if (ctx->r2 != 0) {
        // 0x800626E4: nop
    
            goto L_800626F4;
    }
    // 0x800626E4: nop

    // 0x800626E8: lw          $v0, 0x14($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X14);
    // 0x800626EC: ori         $v0, $v0, 0x1
    ctx->r2 = ctx->r2 | 0X1;
    // 0x800626F0: sw          $v0, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->r2;
L_800626F4:
    // 0x800626F4: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x800626F8: addiu       $a0, $t0, 0x1
    ctx->r4 = ADD32(ctx->r8, 0X1);
    // 0x800626FC: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    // 0x80062700: sh          $s5, 0x98($s1)
    MEM_H(0X98, ctx->r17) = ctx->r21;
    // 0x80062704: sh          $s6, 0x9A($s1)
    MEM_H(0X9A, ctx->r17) = ctx->r22;
    // 0x80062708: lw          $s0, 0x0($s3)
    ctx->r16 = MEM_W(ctx->r19, 0X0);
    // 0x8006270C: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80062710: lw          $v0, 0x30($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X30);
    // 0x80062714: sllv        $v1, $t0, $a0
    ctx->r3 = S32(ctx->r8 << (ctx->r4 & 31));
    // 0x80062718: or          $v0, $v0, $v1
    ctx->r2 = ctx->r2 | ctx->r3;
    // 0x8006271C: lbu         $v1, 0x1F($s0)
    ctx->r3 = MEM_BU(ctx->r16, 0X1F);
    // 0x80062720: sw          $v0, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->r2;
    // 0x80062724: addu        $v0, $s0, $a0
    ctx->r2 = ADD32(ctx->r16, ctx->r4);
    // 0x80062728: sb          $v1, 0x84($v0)
    MEM_B(0X84, ctx->r2) = ctx->r3;
    // 0x8006272C: lhu         $v0, 0xE8($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0XE8);
    // 0x80062730: mult        $v0, $a0
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80062734: sll         $v0, $a0, 2
    ctx->r2 = S32(ctx->r4 << 2);
    // 0x80062738: addu        $s3, $s0, $v0
    ctx->r19 = ADD32(ctx->r16, ctx->r2);
    // 0x8006273C: lw          $v0, 0xEC($s0)
    ctx->r2 = MEM_W(ctx->r16, 0XEC);
    // 0x80062740: lw          $s1, 0x34($s3)
    ctx->r17 = MEM_W(ctx->r19, 0X34);
    // 0x80062744: mflo        $t0
    ctx->r8 = lo;
    // 0x80062748: sll         $v1, $t0, 2
    ctx->r3 = S32(ctx->r8 << 2);
    // 0x8006274C: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80062750: sw          $v0, 0x10($s1)
    MEM_W(0X10, ctx->r17) = ctx->r2;
    // 0x80062754: lhu         $v0, 0xE8($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0XE8);
    // 0x80062758: mult        $v0, $a0
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8006275C: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    // 0x80062760: lw          $a3, 0x54($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X54);
    // 0x80062764: lw          $v0, 0xF0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0XF0);
    // 0x80062768: mflo        $t0
    ctx->r8 = lo;
    // 0x8006276C: sll         $v1, $t0, 1
    ctx->r3 = S32(ctx->r8 << 1);
    // 0x80062770: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80062774: sw          $v0, 0xC($s1)
    MEM_W(0XC, ctx->r17) = ctx->r2;
    // 0x80062778: lhu         $a2, 0xE8($s0)
    ctx->r6 = MEM_HU(ctx->r16, 0XE8);
    // 0x8006277C: addu        $a0, $s4, $zero
    ctx->r4 = ADD32(ctx->r20, 0);
    // 0x80062780: sw          $fp, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r30;
    // 0x80062784: jal         0x80062108
    // 0x80062788: sw          $s7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r23;
    func_80062108(rdram, ctx);
        goto after_2;
    // 0x80062788: sw          $s7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r23;
    after_2:
    // 0x8006278C: lw          $a0, 0xF4($s0)
    ctx->r4 = MEM_W(ctx->r16, 0XF4);
    // 0x80062790: beq         $a0, $zero, L_800627A8
    if (ctx->r4 == 0) {
        // 0x80062794: nop
    
            goto L_800627A8;
    }
    // 0x80062794: nop

    // 0x80062798: lhu         $a2, 0x8($s1)
    ctx->r6 = MEM_HU(ctx->r17, 0X8);
    // 0x8006279C: lw          $a1, 0x34($s3)
    ctx->r5 = MEM_W(ctx->r19, 0X34);
    // 0x800627A0: jal         0x800646AC
    // 0x800627A4: sltu        $a2, $zero, $a2
    ctx->r6 = 0 < ctx->r6 ? 1 : 0;
    func_800646AC(rdram, ctx);
        goto after_3;
    // 0x800627A4: sltu        $a2, $zero, $a2
    ctx->r6 = 0 < ctx->r6 ? 1 : 0;
    after_3:
L_800627A8:
    // 0x800627A8: lbu         $v0, 0x1F($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X1F);
    // 0x800627AC: bne         $v0, $zero, L_800627C0
    if (ctx->r2 != 0) {
        // 0x800627B0: addiu       $a0, $zero, 0x18
        ctx->r4 = ADD32(0, 0X18);
            goto L_800627C0;
    }
    // 0x800627B0: addiu       $a0, $zero, 0x18
    ctx->r4 = ADD32(0, 0X18);
    // 0x800627B4: lw          $v0, 0x14($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X14);
    // 0x800627B8: ori         $v0, $v0, 0x1
    ctx->r2 = ctx->r2 | 0X1;
    // 0x800627BC: sw          $v0, 0x14($s1)
    MEM_W(0X14, ctx->r17) = ctx->r2;
L_800627C0:
    // 0x800627C0: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x800627C4: sh          $s5, 0x98($s3)
    MEM_H(0X98, ctx->r19) = ctx->r21;
    // 0x800627C8: jal         0x80001ACC
    // 0x800627CC: sh          $s6, 0x9A($s3)
    MEM_H(0X9A, ctx->r19) = ctx->r22;
    rs_malloc(rdram, ctx);
        goto after_4;
    // 0x800627CC: sh          $s6, 0x9A($s3)
    MEM_H(0X9A, ctx->r19) = ctx->r22;
    after_4:
    // 0x800627D0: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    // 0x800627D4: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    // 0x800627D8: sb          $zero, 0x0($s0)
    MEM_B(0X0, ctx->r16) = 0;
    // 0x800627DC: sb          $zero, 0x1($s0)
    MEM_B(0X1, ctx->r16) = 0;
    // 0x800627E0: sw          $zero, 0x4($s0)
    MEM_W(0X4, ctx->r16) = 0;
    // 0x800627E4: lbu         $t0, 0x19($sp)
    ctx->r8 = MEM_BU(ctx->r29, 0X19);
    // 0x800627E8: sb          $t0, 0x8($s0)
    MEM_B(0X8, ctx->r16) = ctx->r8;
    // 0x800627EC: lbu         $t0, 0x1D($sp)
    ctx->r8 = MEM_BU(ctx->r29, 0X1D);
    // 0x800627F0: sh          $s5, 0xA($s0)
    MEM_H(0XA, ctx->r16) = ctx->r21;
    // 0x800627F4: sh          $s6, 0xC($s0)
    MEM_H(0XC, ctx->r16) = ctx->r22;
    // 0x800627F8: sb          $t0, 0x9($s0)
    MEM_B(0X9, ctx->r16) = ctx->r8;
    // 0x800627FC: lbu         $t0, 0x1B($sp)
    ctx->r8 = MEM_BU(ctx->r29, 0X1B);
    // 0x80062800: sb          $t0, 0xE($s0)
    MEM_B(0XE, ctx->r16) = ctx->r8;
    // 0x80062804: lw          $t0, 0x54($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X54);
    // 0x80062808: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x8006280C: sw          $t0, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->r8;
    // 0x80062810: lw          $v0, 0xF4($s2)
    ctx->r2 = MEM_W(ctx->r18, 0XF4);
    // 0x80062814: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // 0x80062818: jal         0x80062B04
    // 0x8006281C: sw          $v0, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->r2;
    func_80062B04(rdram, ctx);
        goto after_5;
    // 0x8006281C: sw          $v0, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->r2;
    after_5:
    // 0x80062820: addu        $v0, $s0, $zero
    ctx->r2 = ADD32(ctx->r16, 0);
    // 0x80062824: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
    // 0x80062828: lw          $fp, 0x48($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X48);
    // 0x8006282C: lw          $s7, 0x44($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X44);
    // 0x80062830: lw          $s6, 0x40($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X40);
    // 0x80062834: lw          $s5, 0x3C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X3C);
    // 0x80062838: lw          $s4, 0x38($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X38);
    // 0x8006283C: lw          $s3, 0x34($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X34);
    // 0x80062840: lw          $s2, 0x30($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X30);
    // 0x80062844: lw          $s1, 0x2C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X2C);
    // 0x80062848: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x8006284C: jr          $ra
    // 0x80062850: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x80062850: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}
RECOMP_FUNC void func_80062854(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80062854: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80062858: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8006285C: addu        $s2, $a0, $zero
    ctx->r18 = ADD32(ctx->r4, 0);
    // 0x80062860: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x80062864: addu        $fp, $a1, $zero
    ctx->r30 = ADD32(ctx->r5, 0);
    // 0x80062868: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x8006286C: addiu       $s6, $zero, 0x1
    ctx->r22 = ADD32(0, 0X1);
    // 0x80062870: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x80062874: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x80062878: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x8006287C: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x80062880: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x80062884: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80062888: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8006288C: lbu         $v0, 0x0($s2)
    ctx->r2 = MEM_BU(ctx->r18, 0X0);
    // 0x80062890: lbu         $a0, 0x8($s2)
    ctx->r4 = MEM_BU(ctx->r18, 0X8);
    // 0x80062894: lbu         $a1, 0x9($s2)
    ctx->r5 = MEM_BU(ctx->r18, 0X9);
    // 0x80062898: lhu         $s5, 0xA($s2)
    ctx->r21 = MEM_HU(ctx->r18, 0XA);
    // 0x8006289C: lhu         $s4, 0xC($s2)
    ctx->r20 = MEM_HU(ctx->r18, 0XC);
    // 0x800628A0: subu        $v0, $s6, $v0
    ctx->r2 = SUB32(ctx->r22, ctx->r2);
    // 0x800628A4: sb          $v0, 0x0($s2)
    MEM_B(0X0, ctx->r18) = ctx->r2;
    // 0x800628A8: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x800628AC: addiu       $s7, $v0, -0x3F0
    ctx->r23 = ADD32(ctx->r2, -0X3F0);
    // 0x800628B0: sll         $v0, $a0, 2
    ctx->r2 = S32(ctx->r4 << 2);
    // 0x800628B4: addu        $v0, $v0, $s7
    ctx->r2 = ADD32(ctx->r2, ctx->r23);
    // 0x800628B8: lbu         $v1, 0x0($s2)
    ctx->r3 = MEM_BU(ctx->r18, 0X0);
    // 0x800628BC: lw          $s0, 0x0($v0)
    ctx->r16 = MEM_W(ctx->r2, 0X0);
    // 0x800628C0: addu        $v1, $v1, $a1
    ctx->r3 = ADD32(ctx->r3, ctx->r5);
    // 0x800628C4: lw          $v0, 0x30($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X30);
    // 0x800628C8: sllv        $a1, $s6, $v1
    ctx->r5 = S32(ctx->r22 << (ctx->r3 & 31));
    // 0x800628CC: or          $v0, $v0, $a1
    ctx->r2 = ctx->r2 | ctx->r5;
    // 0x800628D0: lbu         $a1, 0x1F($s0)
    ctx->r5 = MEM_BU(ctx->r16, 0X1F);
    // 0x800628D4: sw          $v0, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->r2;
    // 0x800628D8: addu        $v0, $s0, $v1
    ctx->r2 = ADD32(ctx->r16, ctx->r3);
    // 0x800628DC: sb          $a1, 0x84($v0)
    MEM_B(0X84, ctx->r2) = ctx->r5;
    // 0x800628E0: lhu         $v0, 0xE8($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0XE8);
    // 0x800628E4: mult        $v0, $v1
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800628E8: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x800628EC: addu        $s3, $s0, $v0
    ctx->r19 = ADD32(ctx->r16, ctx->r2);
    // 0x800628F0: lw          $v0, 0xEC($s0)
    ctx->r2 = MEM_W(ctx->r16, 0XEC);
    // 0x800628F4: lw          $s1, 0x34($s3)
    ctx->r17 = MEM_W(ctx->r19, 0X34);
    // 0x800628F8: mflo        $t0
    ctx->r8 = lo;
    // 0x800628FC: sll         $a1, $t0, 2
    ctx->r5 = S32(ctx->r8 << 2);
    // 0x80062900: addu        $v0, $v0, $a1
    ctx->r2 = ADD32(ctx->r2, ctx->r5);
    // 0x80062904: sw          $v0, 0x10($s1)
    MEM_W(0X10, ctx->r17) = ctx->r2;
    // 0x80062908: lhu         $v0, 0xE8($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0XE8);
    // 0x8006290C: mult        $v0, $v1
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80062910: addu        $a3, $fp, $zero
    ctx->r7 = ADD32(ctx->r30, 0);
    // 0x80062914: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    // 0x80062918: lw          $v0, 0xF0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0XF0);
    // 0x8006291C: mflo        $t0
    ctx->r8 = lo;
    // 0x80062920: sllv        $v1, $t0, $s6
    ctx->r3 = S32(ctx->r8 << (ctx->r22 & 31));
    // 0x80062924: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80062928: sw          $v0, 0xC($s1)
    MEM_W(0XC, ctx->r17) = ctx->r2;
    // 0x8006292C: sll         $v0, $s5, 16
    ctx->r2 = S32(ctx->r21 << 16);
    // 0x80062930: lhu         $a2, 0xE8($s0)
    ctx->r6 = MEM_HU(ctx->r16, 0XE8);
    // 0x80062934: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x80062938: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // 0x8006293C: sll         $v0, $s4, 16
    ctx->r2 = S32(ctx->r20 << 16);
    // 0x80062940: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x80062944: jal         0x80062108
    // 0x80062948: sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    func_80062108(rdram, ctx);
        goto after_0;
    // 0x80062948: sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    after_0:
    // 0x8006294C: lw          $a0, 0xF4($s0)
    ctx->r4 = MEM_W(ctx->r16, 0XF4);
    // 0x80062950: beq         $a0, $zero, L_80062968
    if (ctx->r4 == 0) {
        // 0x80062954: nop
    
            goto L_80062968;
    }
    // 0x80062954: nop

    // 0x80062958: lhu         $a2, 0x8($s1)
    ctx->r6 = MEM_HU(ctx->r17, 0X8);
    // 0x8006295C: lw          $a1, 0x34($s3)
    ctx->r5 = MEM_W(ctx->r19, 0X34);
    // 0x80062960: jal         0x800646AC
    // 0x80062964: sltu        $a2, $zero, $a2
    ctx->r6 = 0 < ctx->r6 ? 1 : 0;
    func_800646AC(rdram, ctx);
        goto after_1;
    // 0x80062964: sltu        $a2, $zero, $a2
    ctx->r6 = 0 < ctx->r6 ? 1 : 0;
    after_1:
L_80062968:
    // 0x80062968: lbu         $v0, 0x1F($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X1F);
    // 0x8006296C: bnel        $v0, $zero, L_80062984
    if (ctx->r2 != 0) {
        // 0x80062970: sh          $s5, 0x98($s3)
        MEM_H(0X98, ctx->r19) = ctx->r21;
            goto L_80062984;
    }
    goto skip_0;
    // 0x80062970: sh          $s5, 0x98($s3)
    MEM_H(0X98, ctx->r19) = ctx->r21;
    skip_0:
    // 0x80062974: lw          $v0, 0x14($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X14);
    // 0x80062978: ori         $v0, $v0, 0x1
    ctx->r2 = ctx->r2 | 0X1;
    // 0x8006297C: sw          $v0, 0x14($s1)
    MEM_W(0X14, ctx->r17) = ctx->r2;
    // 0x80062980: sh          $s5, 0x98($s3)
    MEM_H(0X98, ctx->r19) = ctx->r21;
L_80062984:
    // 0x80062984: sh          $s4, 0x9A($s3)
    MEM_H(0X9A, ctx->r19) = ctx->r20;
    // 0x80062988: lbu         $v0, 0x0($s2)
    ctx->r2 = MEM_BU(ctx->r18, 0X0);
    // 0x8006298C: lbu         $v1, 0x9($s2)
    ctx->r3 = MEM_BU(ctx->r18, 0X9);
    // 0x80062990: lbu         $a0, 0x8($s2)
    ctx->r4 = MEM_BU(ctx->r18, 0X8);
    // 0x80062994: lw          $a3, 0x10($s2)
    ctx->r7 = MEM_W(ctx->r18, 0X10);
    // 0x80062998: lhu         $s5, 0xA($s2)
    ctx->r21 = MEM_HU(ctx->r18, 0XA);
    // 0x8006299C: lhu         $s4, 0xC($s2)
    ctx->r20 = MEM_HU(ctx->r18, 0XC);
    // 0x800629A0: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x800629A4: subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // 0x800629A8: sll         $v0, $a0, 2
    ctx->r2 = S32(ctx->r4 << 2);
    // 0x800629AC: addu        $v0, $v0, $s7
    ctx->r2 = ADD32(ctx->r2, ctx->r23);
    // 0x800629B0: lw          $s0, 0x0($v0)
    ctx->r16 = MEM_W(ctx->r2, 0X0);
    // 0x800629B4: andi        $v1, $v1, 0xFFFF
    ctx->r3 = ctx->r3 & 0XFFFF;
    // 0x800629B8: lw          $v0, 0x30($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X30);
    // 0x800629BC: sllv        $a1, $s6, $v1
    ctx->r5 = S32(ctx->r22 << (ctx->r3 & 31));
    // 0x800629C0: or          $v0, $v0, $a1
    ctx->r2 = ctx->r2 | ctx->r5;
    // 0x800629C4: lbu         $a1, 0x1F($s0)
    ctx->r5 = MEM_BU(ctx->r16, 0X1F);
    // 0x800629C8: sw          $v0, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->r2;
    // 0x800629CC: addu        $v0, $s0, $v1
    ctx->r2 = ADD32(ctx->r16, ctx->r3);
    // 0x800629D0: sb          $a1, 0x84($v0)
    MEM_B(0X84, ctx->r2) = ctx->r5;
    // 0x800629D4: lhu         $v0, 0xE8($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0XE8);
    // 0x800629D8: mult        $v0, $v1
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800629DC: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x800629E0: addu        $s3, $s0, $v0
    ctx->r19 = ADD32(ctx->r16, ctx->r2);
    // 0x800629E4: lw          $v0, 0xEC($s0)
    ctx->r2 = MEM_W(ctx->r16, 0XEC);
    // 0x800629E8: lw          $s1, 0x34($s3)
    ctx->r17 = MEM_W(ctx->r19, 0X34);
    // 0x800629EC: mflo        $t0
    ctx->r8 = lo;
    // 0x800629F0: sll         $a1, $t0, 2
    ctx->r5 = S32(ctx->r8 << 2);
    // 0x800629F4: addu        $v0, $v0, $a1
    ctx->r2 = ADD32(ctx->r2, ctx->r5);
    // 0x800629F8: sw          $v0, 0x10($s1)
    MEM_W(0X10, ctx->r17) = ctx->r2;
    // 0x800629FC: lhu         $v0, 0xE8($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0XE8);
    // 0x80062A00: mult        $v0, $v1
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80062A04: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    // 0x80062A08: lw          $v0, 0xF0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0XF0);
    // 0x80062A0C: mflo        $t0
    ctx->r8 = lo;
    // 0x80062A10: sll         $v1, $t0, 1
    ctx->r3 = S32(ctx->r8 << 1);
    // 0x80062A14: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80062A18: sw          $v0, 0xC($s1)
    MEM_W(0XC, ctx->r17) = ctx->r2;
    // 0x80062A1C: sll         $v0, $s5, 16
    ctx->r2 = S32(ctx->r21 << 16);
    // 0x80062A20: lhu         $a2, 0xE8($s0)
    ctx->r6 = MEM_HU(ctx->r16, 0XE8);
    // 0x80062A24: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x80062A28: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // 0x80062A2C: sll         $v0, $s4, 16
    ctx->r2 = S32(ctx->r20 << 16);
    // 0x80062A30: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x80062A34: jal         0x80062108
    // 0x80062A38: sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    func_80062108(rdram, ctx);
        goto after_2;
    // 0x80062A38: sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    after_2:
    // 0x80062A3C: lw          $a0, 0xF4($s0)
    ctx->r4 = MEM_W(ctx->r16, 0XF4);
    // 0x80062A40: beq         $a0, $zero, L_80062A58
    if (ctx->r4 == 0) {
        // 0x80062A44: nop
    
            goto L_80062A58;
    }
    // 0x80062A44: nop

    // 0x80062A48: lhu         $a2, 0x8($s1)
    ctx->r6 = MEM_HU(ctx->r17, 0X8);
    // 0x80062A4C: lw          $a1, 0x34($s3)
    ctx->r5 = MEM_W(ctx->r19, 0X34);
    // 0x80062A50: jal         0x800646AC
    // 0x80062A54: sltu        $a2, $zero, $a2
    ctx->r6 = 0 < ctx->r6 ? 1 : 0;
    func_800646AC(rdram, ctx);
        goto after_3;
    // 0x80062A54: sltu        $a2, $zero, $a2
    ctx->r6 = 0 < ctx->r6 ? 1 : 0;
    after_3:
L_80062A58:
    // 0x80062A58: lbu         $v0, 0x1F($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X1F);
    // 0x80062A5C: bnel        $v0, $zero, L_80062A74
    if (ctx->r2 != 0) {
        // 0x80062A60: sh          $s5, 0x98($s3)
        MEM_H(0X98, ctx->r19) = ctx->r21;
            goto L_80062A74;
    }
    goto skip_1;
    // 0x80062A60: sh          $s5, 0x98($s3)
    MEM_H(0X98, ctx->r19) = ctx->r21;
    skip_1:
    // 0x80062A64: lw          $v0, 0x14($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X14);
    // 0x80062A68: ori         $v0, $v0, 0x1
    ctx->r2 = ctx->r2 | 0X1;
    // 0x80062A6C: sw          $v0, 0x14($s1)
    MEM_W(0X14, ctx->r17) = ctx->r2;
    // 0x80062A70: sh          $s5, 0x98($s3)
    MEM_H(0X98, ctx->r19) = ctx->r21;
L_80062A74:
    // 0x80062A74: sh          $s4, 0x9A($s3)
    MEM_H(0X9A, ctx->r19) = ctx->r20;
    // 0x80062A78: lb          $v1, 0x1($s2)
    ctx->r3 = MEM_B(ctx->r18, 0X1);
    // 0x80062A7C: beq         $v1, $zero, L_80062A9C
    if (ctx->r3 == 0) {
        // 0x80062A80: addiu       $v0, $zero, -0x1
        ctx->r2 = ADD32(0, -0X1);
            goto L_80062A9C;
    }
    // 0x80062A80: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x80062A84: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80062A88: beql        $v1, $v0, L_80062A9C
    if (ctx->r3 == ctx->r2) {
        // 0x80062A8C: swc1        $f0, 0x4($s2)
        MEM_W(0X4, ctx->r18) = ctx->f0.u32l;
            goto L_80062A9C;
    }
    goto skip_2;
    // 0x80062A8C: swc1        $f0, 0x4($s2)
    MEM_W(0X4, ctx->r18) = ctx->f0.u32l;
    skip_2:
    // 0x80062A90: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80062A94: lwc1        $f0, -0x48BC($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X48BC);
    // 0x80062A98: swc1        $f0, 0x4($s2)
    MEM_W(0X4, ctx->r18) = ctx->f0.u32l;
L_80062A9C:
    // 0x80062A9C: lwc1        $f2, 0x4($s2)
    ctx->f2.u32l = MEM_W(ctx->r18, 0X4);
    // 0x80062AA0: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80062AA4: lwc1        $f0, -0x48B8($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X48B8);
    // 0x80062AA8: c.eq.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl == ctx->f0.fl;
    // 0x80062AAC: nop

    // 0x80062AB0: bc1f        L_80062ABC
    if (!c1cs) {
        // 0x80062AB4: addiu       $a0, $zero, 0x1
        ctx->r4 = ADD32(0, 0X1);
            goto L_80062ABC;
    }
    // 0x80062AB4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80062AB8: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
L_80062ABC:
    // 0x80062ABC: lbu         $v0, 0x0($s2)
    ctx->r2 = MEM_BU(ctx->r18, 0X0);
    // 0x80062AC0: lbu         $v1, 0x9($s2)
    ctx->r3 = MEM_BU(ctx->r18, 0X9);
    // 0x80062AC4: sb          $a0, 0x1($s2)
    MEM_B(0X1, ctx->r18) = ctx->r4;
    // 0x80062AC8: sw          $fp, 0x10($s2)
    MEM_W(0X10, ctx->r18) = ctx->r30;
    // 0x80062ACC: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x80062AD0: lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X38);
    // 0x80062AD4: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x80062AD8: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x80062ADC: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x80062AE0: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x80062AE4: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x80062AE8: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80062AEC: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80062AF0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80062AF4: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80062AF8: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x80062AFC: jr          $ra
    // 0x80062B00: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x80062B00: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void func_80062B04(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80062B04: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80062B08: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x80062B0C: mtc1        $a1, $f20
    ctx->f20.u32l = ctx->r5;
    // 0x80062B10: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x80062B14: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x80062B18: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80062B1C: lb          $v1, 0x1($s0)
    ctx->r3 = MEM_B(ctx->r16, 0X1);
    // 0x80062B20: mtc1        $a2, $f2
    ctx->f2.u32l = ctx->r6;
    // 0x80062B24: beq         $v1, $zero, L_80062BB8
    if (ctx->r3 == 0) {
        // 0x80062B28: nop
    
            goto L_80062BB8;
    }
    // 0x80062B28: nop

    // 0x80062B2C: lbu         $v0, 0xE($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0XE);
    // 0x80062B30: mult        $v1, $v0
    result = S64(S32(ctx->r3)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80062B34: mflo        $a3
    ctx->r7 = lo;
    // 0x80062B38: mtc1        $a3, $f0
    ctx->f0.u32l = ctx->r7;
    // 0x80062B3C: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x80062B40: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x80062B44: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80062B48: lwc1        $f2, -0x48B4($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X48B4);
    // 0x80062B4C: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x80062B50: lwc1        $f2, 0x4($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X4);
    // 0x80062B54: add.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x80062B58: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80062B5C: c.lt.s      $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f2.fl < ctx->f4.fl;
    // 0x80062B60: nop

    // 0x80062B64: bc1t        L_80062B84
    if (c1cs) {
        // 0x80062B68: swc1        $f2, 0x4($s0)
        MEM_W(0X4, ctx->r16) = ctx->f2.u32l;
            goto L_80062B84;
    }
    // 0x80062B68: swc1        $f2, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f2.u32l;
    // 0x80062B6C: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80062B70: lwc1        $f0, -0x48B0($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X48B0);
    // 0x80062B74: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x80062B78: nop

    // 0x80062B7C: bc1f        L_80062BB8
    if (!c1cs) {
        // 0x80062B80: nop
    
            goto L_80062BB8;
    }
    // 0x80062B80: nop

L_80062B84:
    // 0x80062B84: lwc1        $f0, 0x4($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X4);
    // 0x80062B88: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x80062B8C: nop

    // 0x80062B90: bc1f        L_80062B9C
    if (!c1cs) {
        // 0x80062B94: sb          $zero, 0x1($s0)
        MEM_B(0X1, ctx->r16) = 0;
            goto L_80062B9C;
    }
    // 0x80062B94: sb          $zero, 0x1($s0)
    MEM_B(0X1, ctx->r16) = 0;
    // 0x80062B98: swc1        $f4, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f4.u32l;
L_80062B9C:
    // 0x80062B9C: lwc1        $f0, 0x4($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X4);
    // 0x80062BA0: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80062BA4: lwc1        $f2, -0x48AC($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X48AC);
    // 0x80062BA8: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x80062BAC: nop

    // 0x80062BB0: bc1tl       L_80062BB8
    if (c1cs) {
        // 0x80062BB4: swc1        $f2, 0x4($s0)
        MEM_W(0X4, ctx->r16) = ctx->f2.u32l;
            goto L_80062BB8;
    }
    goto skip_0;
    // 0x80062BB4: swc1        $f2, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f2.u32l;
    skip_0:
L_80062BB8:
    // 0x80062BB8: lwc1        $f2, 0x4($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X4);
    // 0x80062BBC: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80062BC0: lwc1        $f0, -0x48A8($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X48A8);
    // 0x80062BC4: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x80062BC8: mul.s       $f0, $f20, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = MUL_S(ctx->f20.fl, ctx->f0.fl);
    // 0x80062BCC: lbu         $a0, 0x8($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X8);
    // 0x80062BD0: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80062BD4: lwc1        $f2, -0x48A4($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X48A4);
    // 0x80062BD8: lbu         $a1, 0x9($s0)
    ctx->r5 = MEM_BU(ctx->r16, 0X9);
    // 0x80062BDC: c.le.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl <= ctx->f0.fl;
    // 0x80062BE0: nop

    // 0x80062BE4: bc1tl       L_80062BFC
    if (c1cs) {
        // 0x80062BE8: sub.s       $f0, $f0, $f2
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
            goto L_80062BFC;
    }
    goto skip_1;
    // 0x80062BE8: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    skip_1:
    // 0x80062BEC: trunc.w.s   $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    ctx->f6.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x80062BF0: mfc1        $a2, $f6
    ctx->r6 = (int32_t)ctx->f6.u32l;
    // 0x80062BF4: j           L_80062C0C
    // 0x80062BF8: nop

        goto L_80062C0C;
    // 0x80062BF8: nop

L_80062BFC:
    // 0x80062BFC: lui         $v0, 0x8000
    ctx->r2 = S32(0X8000 << 16);
    // 0x80062C00: trunc.w.s   $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    ctx->f6.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x80062C04: mfc1        $a2, $f6
    ctx->r6 = (int32_t)ctx->f6.u32l;
    // 0x80062C08: or          $a2, $a2, $v0
    ctx->r6 = ctx->r6 | ctx->r2;
L_80062C0C:
    // 0x80062C0C: jal         0x80061C74
    // 0x80062C10: andi        $a2, $a2, 0xFF
    ctx->r6 = ctx->r6 & 0XFF;
    func_80061C74(rdram, ctx);
        goto after_0;
    // 0x80062C10: andi        $a2, $a2, 0xFF
    ctx->r6 = ctx->r6 & 0XFF;
    after_0:
    // 0x80062C14: lwc1        $f0, 0x4($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X4);
    // 0x80062C18: mul.s       $f0, $f20, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = MUL_S(ctx->f20.fl, ctx->f0.fl);
    // 0x80062C1C: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80062C20: lwc1        $f2, -0x48A0($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X48A0);
    // 0x80062C24: lbu         $v0, 0x9($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X9);
    // 0x80062C28: lbu         $a0, 0x8($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X8);
    // 0x80062C2C: c.le.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl <= ctx->f0.fl;
    // 0x80062C30: nop

    // 0x80062C34: bc1t        L_80062C4C
    if (c1cs) {
        // 0x80062C38: addiu       $a1, $v0, 0x1
        ctx->r5 = ADD32(ctx->r2, 0X1);
            goto L_80062C4C;
    }
    // 0x80062C38: addiu       $a1, $v0, 0x1
    ctx->r5 = ADD32(ctx->r2, 0X1);
    // 0x80062C3C: trunc.w.s   $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    ctx->f6.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x80062C40: mfc1        $a2, $f6
    ctx->r6 = (int32_t)ctx->f6.u32l;
    // 0x80062C44: j           L_80062C60
    // 0x80062C48: nop

        goto L_80062C60;
    // 0x80062C48: nop

L_80062C4C:
    // 0x80062C4C: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x80062C50: lui         $v0, 0x8000
    ctx->r2 = S32(0X8000 << 16);
    // 0x80062C54: trunc.w.s   $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    ctx->f6.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x80062C58: mfc1        $a2, $f6
    ctx->r6 = (int32_t)ctx->f6.u32l;
    // 0x80062C5C: or          $a2, $a2, $v0
    ctx->r6 = ctx->r6 | ctx->r2;
L_80062C60:
    // 0x80062C60: jal         0x80061C74
    // 0x80062C64: andi        $a2, $a2, 0xFF
    ctx->r6 = ctx->r6 & 0XFF;
    func_80061C74(rdram, ctx);
        goto after_1;
    // 0x80062C64: andi        $a2, $a2, 0xFF
    ctx->r6 = ctx->r6 & 0XFF;
    after_1:
    // 0x80062C68: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80062C6C: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x80062C70: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x80062C74: jr          $ra
    // 0x80062C78: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80062C78: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_80062C7C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80062C7C: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x80062C80: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x80062C84: addu        $s5, $a1, $zero
    ctx->r21 = ADD32(ctx->r5, 0);
    // 0x80062C88: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80062C8C: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x80062C90: addiu       $a0, $zero, 0x458
    ctx->r4 = ADD32(0, 0X458);
    // 0x80062C94: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x80062C98: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x80062C9C: addu        $s4, $a3, $zero
    ctx->r20 = ADD32(ctx->r7, 0);
    // 0x80062CA0: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x80062CA4: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x80062CA8: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x80062CAC: addiu       $fp, $v0, -0x3F0
    ctx->r30 = ADD32(ctx->r2, -0X3F0);
    // 0x80062CB0: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80062CB4: lw          $s1, 0x58($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X58);
    // 0x80062CB8: andi        $v0, $s0, 0xFFFF
    ctx->r2 = ctx->r16 & 0XFFFF;
    // 0x80062CBC: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80062CC0: lw          $s2, 0x5C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X5C);
    // 0x80062CC4: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80062CC8: sdc1        $f20, 0x40($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X40, ctx->r29);
    // 0x80062CCC: lwc1        $f20, 0x60($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X60);
    // 0x80062CD0: addu        $v0, $v0, $fp
    ctx->r2 = ADD32(ctx->r2, ctx->r30);
    // 0x80062CD4: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x80062CD8: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x80062CDC: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x80062CE0: lw          $s7, 0x0($v0)
    ctx->r23 = MEM_W(ctx->r2, 0X0);
    // 0x80062CE4: jal         0x80001ACC
    // 0x80062CE8: addu        $s3, $a2, $zero
    ctx->r19 = ADD32(ctx->r6, 0);
    rs_malloc(rdram, ctx);
        goto after_0;
    // 0x80062CE8: addu        $s3, $a2, $zero
    ctx->r19 = ADD32(ctx->r6, 0);
    after_0:
    // 0x80062CEC: addu        $s6, $v0, $zero
    ctx->r22 = ADD32(ctx->r2, 0);
    // 0x80062CF0: addu        $a0, $s6, $zero
    ctx->r4 = ADD32(ctx->r22, 0);
    // 0x80062CF4: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x80062CF8: jal         0x800078E0
    // 0x80062CFC: addiu       $a2, $zero, 0x458
    ctx->r6 = ADD32(0, 0X458);
    rs_memset(rdram, ctx);
        goto after_1;
    // 0x80062CFC: addiu       $a2, $zero, 0x458
    ctx->r6 = ADD32(0, 0X458);
    after_1:
    // 0x80062D00: sb          $s0, 0x3C($s6)
    MEM_B(0X3C, ctx->r22) = ctx->r16;
    // 0x80062D04: sb          $s3, 0x3D($s6)
    MEM_B(0X3D, ctx->r22) = ctx->r19;
    // 0x80062D08: sh          $s4, 0x40($s6)
    MEM_H(0X40, ctx->r22) = ctx->r20;
    // 0x80062D0C: sb          $s5, 0x46($s6)
    MEM_B(0X46, ctx->r22) = ctx->r21;
    // 0x80062D10: sh          $s1, 0x42($s6)
    MEM_H(0X42, ctx->r22) = ctx->r17;
    // 0x80062D14: sb          $s2, 0x48($s6)
    MEM_B(0X48, ctx->r22) = ctx->r18;
    // 0x80062D18: swc1        $f20, 0x38($s6)
    MEM_W(0X38, ctx->r22) = ctx->f20.u32l;
    // 0x80062D1C: lw          $v0, 0xF4($s7)
    ctx->r2 = MEM_W(ctx->r23, 0XF4);
    // 0x80062D20: sw          $v0, 0x450($s6)
    MEM_W(0X450, ctx->r22) = ctx->r2;
    // 0x80062D24: lh          $a0, 0x2($s7)
    ctx->r4 = MEM_H(ctx->r23, 0X2);
    // 0x80062D28: lh          $a1, 0x6($s7)
    ctx->r5 = MEM_H(ctx->r23, 0X6);
    // 0x80062D2C: jal         0x800638C4
    // 0x80062D30: nop

    func_800638C4(rdram, ctx);
        goto after_2;
    // 0x80062D30: nop

    after_2:
    // 0x80062D34: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80062D38: lwc1        $f0, -0x4898($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X4898);
    // 0x80062D3C: sw          $v0, 0x44C($s6)
    MEM_W(0X44C, ctx->r22) = ctx->r2;
    // 0x80062D40: sb          $zero, 0x2F($v0)
    MEM_B(0X2F, ctx->r2) = 0;
    // 0x80062D44: addiu       $v0, $zero, 0x12
    ctx->r2 = ADD32(0, 0X12);
    // 0x80062D48: sw          $v0, 0x14($s6)
    MEM_W(0X14, ctx->r22) = ctx->r2;
    // 0x80062D4C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80062D50: sh          $v0, 0x8($s6)
    MEM_H(0X8, ctx->r22) = ctx->r2;
    // 0x80062D54: sh          $v0, 0xA($s6)
    MEM_H(0XA, ctx->r22) = ctx->r2;
    // 0x80062D58: swc1        $f0, 0x24($s6)
    MEM_W(0X24, ctx->r22) = ctx->f0.u32l;
    // 0x80062D5C: swc1        $f0, 0x28($s6)
    MEM_W(0X28, ctx->r22) = ctx->f0.u32l;
    // 0x80062D60: lbu         $v0, 0x1F($s7)
    ctx->r2 = MEM_BU(ctx->r23, 0X1F);
    // 0x80062D64: bne         $v0, $zero, L_80062D78
    if (ctx->r2 != 0) {
        // 0x80062D68: nop
    
            goto L_80062D78;
    }
    // 0x80062D68: nop

    // 0x80062D6C: lw          $v0, 0x14($s6)
    ctx->r2 = MEM_W(ctx->r22, 0X14);
    // 0x80062D70: ori         $v0, $v0, 0x1
    ctx->r2 = ctx->r2 | 0X1;
    // 0x80062D74: sw          $v0, 0x14($s6)
    MEM_W(0X14, ctx->r22) = ctx->r2;
L_80062D78:
    // 0x80062D78: lw          $a0, 0xF4($s7)
    ctx->r4 = MEM_W(ctx->r23, 0XF4);
    // 0x80062D7C: beq         $a0, $zero, L_80062DBC
    if (ctx->r4 == 0) {
        // 0x80062D80: addu        $a1, $s6, $zero
        ctx->r5 = ADD32(ctx->r22, 0);
            goto L_80062DBC;
    }
    // 0x80062D80: addu        $a1, $s6, $zero
    ctx->r5 = ADD32(ctx->r22, 0);
    // 0x80062D84: jal         0x800642A0
    // 0x80062D88: addiu       $a2, $zero, 0xA
    ctx->r6 = ADD32(0, 0XA);
    func_800642A0(rdram, ctx);
        goto after_3;
    // 0x80062D88: addiu       $a2, $zero, 0xA
    ctx->r6 = ADD32(0, 0XA);
    after_3:
    // 0x80062D8C: lw          $a0, 0xF4($s7)
    ctx->r4 = MEM_W(ctx->r23, 0XF4);
    // 0x80062D90: lw          $a1, 0x44C($s6)
    ctx->r5 = MEM_W(ctx->r22, 0X44C);
    // 0x80062D94: jal         0x800642A0
    // 0x80062D98: addiu       $a2, $zero, 0xA
    ctx->r6 = ADD32(0, 0XA);
    func_800642A0(rdram, ctx);
        goto after_4;
    // 0x80062D98: addiu       $a2, $zero, 0xA
    ctx->r6 = ADD32(0, 0XA);
    after_4:
    // 0x80062D9C: addu        $a1, $s6, $zero
    ctx->r5 = ADD32(ctx->r22, 0);
    // 0x80062DA0: lw          $a0, 0xF4($s7)
    ctx->r4 = MEM_W(ctx->r23, 0XF4);
    // 0x80062DA4: jal         0x800646AC
    // 0x80062DA8: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    func_800646AC(rdram, ctx);
        goto after_5;
    // 0x80062DA8: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    after_5:
    // 0x80062DAC: lw          $a0, 0xF4($s7)
    ctx->r4 = MEM_W(ctx->r23, 0XF4);
    // 0x80062DB0: lw          $a1, 0x44C($s6)
    ctx->r5 = MEM_W(ctx->r22, 0X44C);
    // 0x80062DB4: jal         0x800646AC
    // 0x80062DB8: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    func_800646AC(rdram, ctx);
        goto after_6;
    // 0x80062DB8: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    after_6:
L_80062DBC:
    // 0x80062DBC: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x80062DC0: lbu         $a0, 0x3C($s6)
    ctx->r4 = MEM_BU(ctx->r22, 0X3C);
    // 0x80062DC4: lbu         $a1, 0x3D($s6)
    ctx->r5 = MEM_BU(ctx->r22, 0X3D);
    // 0x80062DC8: lhu         $s4, 0x40($s6)
    ctx->r20 = MEM_HU(ctx->r22, 0X40);
    // 0x80062DCC: sll         $v0, $a0, 2
    ctx->r2 = S32(ctx->r4 << 2);
    // 0x80062DD0: addu        $v0, $v0, $fp
    ctx->r2 = ADD32(ctx->r2, ctx->r30);
    // 0x80062DD4: lw          $s0, 0x0($v0)
    ctx->r16 = MEM_W(ctx->r2, 0X0);
    // 0x80062DD8: lhu         $s3, 0x42($s6)
    ctx->r19 = MEM_HU(ctx->r22, 0X42);
    // 0x80062DDC: lw          $v0, 0x30($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X30);
    // 0x80062DE0: sllv        $v1, $v1, $a1
    ctx->r3 = S32(ctx->r3 << (ctx->r5 & 31));
    // 0x80062DE4: or          $v0, $v0, $v1
    ctx->r2 = ctx->r2 | ctx->r3;
    // 0x80062DE8: lbu         $v1, 0x1F($s0)
    ctx->r3 = MEM_BU(ctx->r16, 0X1F);
    // 0x80062DEC: sw          $v0, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->r2;
    // 0x80062DF0: addu        $v0, $s0, $a1
    ctx->r2 = ADD32(ctx->r16, ctx->r5);
    // 0x80062DF4: sb          $v1, 0x84($v0)
    MEM_B(0X84, ctx->r2) = ctx->r3;
    // 0x80062DF8: lhu         $v0, 0xE8($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0XE8);
    // 0x80062DFC: mult        $v0, $a1
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80062E00: sll         $v0, $a1, 2
    ctx->r2 = S32(ctx->r5 << 2);
    // 0x80062E04: addu        $s2, $s0, $v0
    ctx->r18 = ADD32(ctx->r16, ctx->r2);
    // 0x80062E08: lw          $v0, 0xEC($s0)
    ctx->r2 = MEM_W(ctx->r16, 0XEC);
    // 0x80062E0C: lw          $s1, 0x34($s2)
    ctx->r17 = MEM_W(ctx->r18, 0X34);
    // 0x80062E10: mflo        $t0
    ctx->r8 = lo;
    // 0x80062E14: sll         $v1, $t0, 2
    ctx->r3 = S32(ctx->r8 << 2);
    // 0x80062E18: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80062E1C: sw          $v0, 0x10($s1)
    MEM_W(0X10, ctx->r17) = ctx->r2;
    // 0x80062E20: lhu         $v0, 0xE8($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0XE8);
    // 0x80062E24: mult        $v0, $a1
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80062E28: lui         $a3, 0x8004
    ctx->r7 = S32(0X8004 << 16);
    // 0x80062E2C: addiu       $a3, $a3, -0x489C
    ctx->r7 = ADD32(ctx->r7, -0X489C);
    // 0x80062E30: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    // 0x80062E34: lw          $v0, 0xF0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0XF0);
    // 0x80062E38: mflo        $t0
    ctx->r8 = lo;
    // 0x80062E3C: sll         $v1, $t0, 1
    ctx->r3 = S32(ctx->r8 << 1);
    // 0x80062E40: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80062E44: sw          $v0, 0xC($s1)
    MEM_W(0XC, ctx->r17) = ctx->r2;
    // 0x80062E48: sll         $v0, $s4, 16
    ctx->r2 = S32(ctx->r20 << 16);
    // 0x80062E4C: lhu         $a2, 0xE8($s0)
    ctx->r6 = MEM_HU(ctx->r16, 0XE8);
    // 0x80062E50: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x80062E54: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // 0x80062E58: sll         $v0, $s3, 16
    ctx->r2 = S32(ctx->r19 << 16);
    // 0x80062E5C: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x80062E60: jal         0x80062108
    // 0x80062E64: sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    func_80062108(rdram, ctx);
        goto after_7;
    // 0x80062E64: sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    after_7:
    // 0x80062E68: lw          $a0, 0xF4($s0)
    ctx->r4 = MEM_W(ctx->r16, 0XF4);
    // 0x80062E6C: beq         $a0, $zero, L_80062E84
    if (ctx->r4 == 0) {
        // 0x80062E70: nop
    
            goto L_80062E84;
    }
    // 0x80062E70: nop

    // 0x80062E74: lhu         $a2, 0x8($s1)
    ctx->r6 = MEM_HU(ctx->r17, 0X8);
    // 0x80062E78: lw          $a1, 0x34($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X34);
    // 0x80062E7C: jal         0x800646AC
    // 0x80062E80: sltu        $a2, $zero, $a2
    ctx->r6 = 0 < ctx->r6 ? 1 : 0;
    func_800646AC(rdram, ctx);
        goto after_8;
    // 0x80062E80: sltu        $a2, $zero, $a2
    ctx->r6 = 0 < ctx->r6 ? 1 : 0;
    after_8:
L_80062E84:
    // 0x80062E84: lbu         $v0, 0x1F($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X1F);
    // 0x80062E88: bne         $v0, $zero, L_80062EA0
    if (ctx->r2 != 0) {
        // 0x80062E8C: addu        $v0, $s6, $zero
        ctx->r2 = ADD32(ctx->r22, 0);
            goto L_80062EA0;
    }
    // 0x80062E8C: addu        $v0, $s6, $zero
    ctx->r2 = ADD32(ctx->r22, 0);
    // 0x80062E90: lw          $v0, 0x14($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X14);
    // 0x80062E94: ori         $v0, $v0, 0x1
    ctx->r2 = ctx->r2 | 0X1;
    // 0x80062E98: sw          $v0, 0x14($s1)
    MEM_W(0X14, ctx->r17) = ctx->r2;
    // 0x80062E9C: addu        $v0, $s6, $zero
    ctx->r2 = ADD32(ctx->r22, 0);
L_80062EA0:
    // 0x80062EA0: sh          $s4, 0x98($s2)
    MEM_H(0X98, ctx->r18) = ctx->r20;
    // 0x80062EA4: sh          $s3, 0x9A($s2)
    MEM_H(0X9A, ctx->r18) = ctx->r19;
    // 0x80062EA8: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x80062EAC: lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X38);
    // 0x80062EB0: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x80062EB4: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x80062EB8: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x80062EBC: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x80062EC0: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x80062EC4: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80062EC8: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80062ECC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80062ED0: ldc1        $f20, 0x40($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X40);
    // 0x80062ED4: jr          $ra
    // 0x80062ED8: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x80062ED8: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void func_80062EDC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80062EDC: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80062EE0: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80062EE4: addu        $s2, $a0, $zero
    ctx->r18 = ADD32(ctx->r4, 0);
    // 0x80062EE8: sw          $ra, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r31;
    // 0x80062EEC: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x80062EF0: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x80062EF4: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x80062EF8: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x80062EFC: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x80062F00: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80062F04: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80062F08: lbu         $v0, 0x454($s2)
    ctx->r2 = MEM_BU(ctx->r18, 0X454);
    // 0x80062F0C: bne         $v0, $zero, L_80063044
    if (ctx->r2 != 0) {
        // 0x80062F10: addu        $a3, $a1, $zero
        ctx->r7 = ADD32(ctx->r5, 0);
            goto L_80063044;
    }
    // 0x80062F10: addu        $a3, $a1, $zero
    ctx->r7 = ADD32(ctx->r5, 0);
    // 0x80062F14: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x80062F18: addiu       $s6, $v0, -0x3F0
    ctx->r22 = ADD32(ctx->r2, -0X3F0);
    // 0x80062F1C: lbu         $a0, 0x3C($s2)
    ctx->r4 = MEM_BU(ctx->r18, 0X3C);
    // 0x80062F20: lbu         $a1, 0x3D($s2)
    ctx->r5 = MEM_BU(ctx->r18, 0X3D);
    // 0x80062F24: lhu         $s5, 0x40($s2)
    ctx->r21 = MEM_HU(ctx->r18, 0X40);
    // 0x80062F28: addiu       $s7, $zero, 0x1
    ctx->r23 = ADD32(0, 0X1);
    // 0x80062F2C: sw          $zero, 0x30($s2)
    MEM_W(0X30, ctx->r18) = 0;
    // 0x80062F30: sw          $zero, 0x34($s2)
    MEM_W(0X34, ctx->r18) = 0;
    // 0x80062F34: sb          $a2, 0x47($s2)
    MEM_B(0X47, ctx->r18) = ctx->r6;
    // 0x80062F38: sb          $zero, 0x455($s2)
    MEM_B(0X455, ctx->r18) = 0;
    // 0x80062F3C: sll         $v0, $a0, 2
    ctx->r2 = S32(ctx->r4 << 2);
    // 0x80062F40: addu        $v0, $v0, $s6
    ctx->r2 = ADD32(ctx->r2, ctx->r22);
    // 0x80062F44: lw          $s0, 0x0($v0)
    ctx->r16 = MEM_W(ctx->r2, 0X0);
    // 0x80062F48: lhu         $s4, 0x42($s2)
    ctx->r20 = MEM_HU(ctx->r18, 0X42);
    // 0x80062F4C: lw          $v0, 0x30($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X30);
    // 0x80062F50: sllv        $v1, $s7, $a1
    ctx->r3 = S32(ctx->r23 << (ctx->r5 & 31));
    // 0x80062F54: or          $v0, $v0, $v1
    ctx->r2 = ctx->r2 | ctx->r3;
    // 0x80062F58: lbu         $v1, 0x1F($s0)
    ctx->r3 = MEM_BU(ctx->r16, 0X1F);
    // 0x80062F5C: sw          $v0, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->r2;
    // 0x80062F60: addu        $v0, $s0, $a1
    ctx->r2 = ADD32(ctx->r16, ctx->r5);
    // 0x80062F64: sb          $v1, 0x84($v0)
    MEM_B(0X84, ctx->r2) = ctx->r3;
    // 0x80062F68: lhu         $v0, 0xE8($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0XE8);
    // 0x80062F6C: mult        $v0, $a1
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80062F70: sll         $v0, $a1, 2
    ctx->r2 = S32(ctx->r5 << 2);
    // 0x80062F74: addu        $s3, $s0, $v0
    ctx->r19 = ADD32(ctx->r16, ctx->r2);
    // 0x80062F78: lw          $v0, 0xEC($s0)
    ctx->r2 = MEM_W(ctx->r16, 0XEC);
    // 0x80062F7C: lw          $s1, 0x34($s3)
    ctx->r17 = MEM_W(ctx->r19, 0X34);
    // 0x80062F80: mflo        $t0
    ctx->r8 = lo;
    // 0x80062F84: sll         $v1, $t0, 2
    ctx->r3 = S32(ctx->r8 << 2);
    // 0x80062F88: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80062F8C: sw          $v0, 0x10($s1)
    MEM_W(0X10, ctx->r17) = ctx->r2;
    // 0x80062F90: lhu         $v0, 0xE8($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0XE8);
    // 0x80062F94: mult        $v0, $a1
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80062F98: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    // 0x80062F9C: lw          $v0, 0xF0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0XF0);
    // 0x80062FA0: mflo        $t0
    ctx->r8 = lo;
    // 0x80062FA4: sllv        $v1, $t0, $s7
    ctx->r3 = S32(ctx->r8 << (ctx->r23 & 31));
    // 0x80062FA8: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80062FAC: sw          $v0, 0xC($s1)
    MEM_W(0XC, ctx->r17) = ctx->r2;
    // 0x80062FB0: sll         $v0, $s5, 16
    ctx->r2 = S32(ctx->r21 << 16);
    // 0x80062FB4: lhu         $a2, 0xE8($s0)
    ctx->r6 = MEM_HU(ctx->r16, 0XE8);
    // 0x80062FB8: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x80062FBC: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // 0x80062FC0: sll         $v0, $s4, 16
    ctx->r2 = S32(ctx->r20 << 16);
    // 0x80062FC4: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x80062FC8: jal         0x80062108
    // 0x80062FCC: sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    func_80062108(rdram, ctx);
        goto after_0;
    // 0x80062FCC: sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    after_0:
    // 0x80062FD0: lw          $a0, 0xF4($s0)
    ctx->r4 = MEM_W(ctx->r16, 0XF4);
    // 0x80062FD4: beq         $a0, $zero, L_80062FEC
    if (ctx->r4 == 0) {
        // 0x80062FD8: nop
    
            goto L_80062FEC;
    }
    // 0x80062FD8: nop

    // 0x80062FDC: lhu         $a2, 0x8($s1)
    ctx->r6 = MEM_HU(ctx->r17, 0X8);
    // 0x80062FE0: lw          $a1, 0x34($s3)
    ctx->r5 = MEM_W(ctx->r19, 0X34);
    // 0x80062FE4: jal         0x800646AC
    // 0x80062FE8: sltu        $a2, $zero, $a2
    ctx->r6 = 0 < ctx->r6 ? 1 : 0;
    func_800646AC(rdram, ctx);
        goto after_1;
    // 0x80062FE8: sltu        $a2, $zero, $a2
    ctx->r6 = 0 < ctx->r6 ? 1 : 0;
    after_1:
L_80062FEC:
    // 0x80062FEC: lbu         $v0, 0x1F($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X1F);
    // 0x80062FF0: bne         $v0, $zero, L_80063004
    if (ctx->r2 != 0) {
        // 0x80062FF4: addu        $a2, $zero, $zero
        ctx->r6 = ADD32(0, 0);
            goto L_80063004;
    }
    // 0x80062FF4: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // 0x80062FF8: lw          $v0, 0x14($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X14);
    // 0x80062FFC: ori         $v0, $v0, 0x1
    ctx->r2 = ctx->r2 | 0X1;
    // 0x80063000: sw          $v0, 0x14($s1)
    MEM_W(0X14, ctx->r17) = ctx->r2;
L_80063004:
    // 0x80063004: sh          $s5, 0x98($s3)
    MEM_H(0X98, ctx->r19) = ctx->r21;
    // 0x80063008: sh          $s4, 0x9A($s3)
    MEM_H(0X9A, ctx->r19) = ctx->r20;
    // 0x8006300C: lbu         $v1, 0x3C($s2)
    ctx->r3 = MEM_BU(ctx->r18, 0X3C);
    // 0x80063010: lbu         $v0, 0x3D($s2)
    ctx->r2 = MEM_BU(ctx->r18, 0X3D);
    // 0x80063014: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x80063018: addu        $v1, $v1, $s6
    ctx->r3 = ADD32(ctx->r3, ctx->r22);
    // 0x8006301C: lw          $v1, 0x0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X0);
    // 0x80063020: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80063024: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x80063028: lw          $s0, 0x34($v1)
    ctx->r16 = MEM_W(ctx->r3, 0X34);
    // 0x8006302C: lw          $a0, 0x450($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X450);
    // 0x80063030: jal         0x800646AC
    // 0x80063034: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    func_800646AC(rdram, ctx);
        goto after_2;
    // 0x80063034: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    after_2:
    // 0x80063038: lhu         $v0, 0x8($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X8);
    // 0x8006303C: sb          $s7, 0x456($s2)
    MEM_B(0X456, ctx->r18) = ctx->r23;
    // 0x80063040: sh          $v0, 0x44($s2)
    MEM_H(0X44, ctx->r18) = ctx->r2;
L_80063044:
    // 0x80063044: lw          $ra, 0x38($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X38);
    // 0x80063048: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x8006304C: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x80063050: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x80063054: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x80063058: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x8006305C: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80063060: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80063064: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80063068: jr          $ra
    // 0x8006306C: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x8006306C: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void func_80063070(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80063070: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80063074: sdc1        $f20, 0x28($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X28, ctx->r29);
    // 0x80063078: mtc1        $a1, $f20
    ctx->f20.u32l = ctx->r5;
    // 0x8006307C: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x80063080: addu        $s1, $a0, $zero
    ctx->r17 = ADD32(ctx->r4, 0);
    // 0x80063084: sw          $s4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r20;
    // 0x80063088: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8006308C: sw          $s3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r19;
    // 0x80063090: sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // 0x80063094: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x80063098: lbu         $v0, 0x454($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X454);
    // 0x8006309C: lw          $s3, 0x44C($s1)
    ctx->r19 = MEM_W(ctx->r17, 0X44C);
    // 0x800630A0: beq         $v0, $zero, L_80063234
    if (ctx->r2 == 0) {
        // 0x800630A4: addu        $s4, $zero, $zero
        ctx->r20 = ADD32(0, 0);
            goto L_80063234;
    }
    // 0x800630A4: addu        $s4, $zero, $zero
    ctx->r20 = ADD32(0, 0);
    // 0x800630A8: lwc1        $f0, 0x30($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X30);
    // 0x800630AC: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800630B0: c.eq.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl == ctx->f4.fl;
    // 0x800630B4: nop

    // 0x800630B8: bc1tl       L_800630C0
    if (c1cs) {
        // 0x800630BC: addiu       $s4, $zero, 0x3
        ctx->r20 = ADD32(0, 0X3);
            goto L_800630C0;
    }
    goto skip_0;
    // 0x800630BC: addiu       $s4, $zero, 0x3
    ctx->r20 = ADD32(0, 0X3);
    skip_0:
L_800630C0:
    // 0x800630C0: add.s       $f0, $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f20.fl;
    // 0x800630C4: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x800630C8: lwc1        $f2, -0x4894($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X4894);
    // 0x800630CC: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x800630D0: nop

    // 0x800630D4: bc1f        L_8006389C
    if (!c1cs) {
        // 0x800630D8: swc1        $f0, 0x30($s1)
        MEM_W(0X30, ctx->r17) = ctx->f0.u32l;
            goto L_8006389C;
    }
    // 0x800630D8: swc1        $f0, 0x30($s1)
    MEM_W(0X30, ctx->r17) = ctx->f0.u32l;
    // 0x800630DC: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x800630E0: addiu       $a1, $v0, -0x3F0
    ctx->r5 = ADD32(ctx->r2, -0X3F0);
    // 0x800630E4: lbu         $v1, 0x3C($s1)
    ctx->r3 = MEM_BU(ctx->r17, 0X3C);
    // 0x800630E8: lbu         $v0, 0x3D($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X3D);
    // 0x800630EC: swc1        $f4, 0x30($s1)
    MEM_W(0X30, ctx->r17) = ctx->f4.u32l;
    // 0x800630F0: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x800630F4: addu        $v1, $v1, $a1
    ctx->r3 = ADD32(ctx->r3, ctx->r5);
    // 0x800630F8: lw          $v1, 0x0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X0);
    // 0x800630FC: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80063100: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x80063104: lw          $s0, 0x34($v1)
    ctx->r16 = MEM_W(ctx->r3, 0X34);
    // 0x80063108: lw          $v0, 0x10($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X10);
    // 0x8006310C: addiu       $v1, $zero, 0x3
    ctx->r3 = ADD32(0, 0X3);
    // 0x80063110: lhu         $a0, 0x2($v0)
    ctx->r4 = MEM_HU(ctx->r2, 0X2);
    // 0x80063114: beq         $s4, $v1, L_80063120
    if (ctx->r20 == ctx->r3) {
        // 0x80063118: addu        $a2, $zero, $zero
        ctx->r6 = ADD32(0, 0);
            goto L_80063120;
    }
    // 0x80063118: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // 0x8006311C: addiu       $s4, $zero, 0x4
    ctx->r20 = ADD32(0, 0X4);
L_80063120:
    // 0x80063120: sll         $v0, $a0, 16
    ctx->r2 = S32(ctx->r4 << 16);
    // 0x80063124: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x80063128: bne         $v0, $a0, L_800631BC
    if (ctx->r2 != ctx->r4) {
        // 0x8006312C: andi        $a0, $a2, 0xFFFF
        ctx->r4 = ctx->r6 & 0XFFFF;
            goto L_800631BC;
    }
    // 0x8006312C: andi        $a0, $a2, 0xFFFF
    ctx->r4 = ctx->r6 & 0XFFFF;
    // 0x80063130: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // 0x80063134: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
L_80063138:
    // 0x80063138: lhu         $v0, 0x8($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X8);
    // 0x8006313C: andi        $v1, $a2, 0xFFFF
    ctx->r3 = ctx->r6 & 0XFFFF;
    // 0x80063140: bnel        $v0, $v1, L_800631A4
    if (ctx->r2 != ctx->r3) {
        // 0x80063144: sll         $v1, $v1, 2
        ctx->r3 = S32(ctx->r3 << 2);
            goto L_800631A4;
    }
    goto skip_1;
    // 0x80063144: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    skip_1:
    // 0x80063148: lw          $a0, 0x450($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X450);
    // 0x8006314C: beq         $a0, $zero, L_8006319C
    if (ctx->r4 == 0) {
        // 0x80063150: sb          $zero, 0x454($s1)
        MEM_B(0X454, ctx->r17) = 0;
            goto L_8006319C;
    }
    // 0x80063150: sb          $zero, 0x454($s1)
    MEM_B(0X454, ctx->r17) = 0;
    // 0x80063154: lbu         $v0, 0x3C($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X3C);
    // 0x80063158: lbu         $v1, 0x3D($s1)
    ctx->r3 = MEM_BU(ctx->r17, 0X3D);
    // 0x8006315C: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80063160: addu        $v0, $v0, $a1
    ctx->r2 = ADD32(ctx->r2, ctx->r5);
    // 0x80063164: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x80063168: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x8006316C: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80063170: lw          $a1, 0x34($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X34);
    // 0x80063174: jal         0x800646AC
    // 0x80063178: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    func_800646AC(rdram, ctx);
        goto after_0;
    // 0x80063178: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    after_0:
    // 0x8006317C: addu        $a1, $s3, $zero
    ctx->r5 = ADD32(ctx->r19, 0);
    // 0x80063180: lw          $a0, 0x450($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X450);
    // 0x80063184: jal         0x800646AC
    // 0x80063188: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    func_800646AC(rdram, ctx);
        goto after_1;
    // 0x80063188: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    after_1:
    // 0x8006318C: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    // 0x80063190: lw          $a0, 0x450($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X450);
    // 0x80063194: jal         0x800646AC
    // 0x80063198: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    func_800646AC(rdram, ctx);
        goto after_2;
    // 0x80063198: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    after_2:
L_8006319C:
    // 0x8006319C: j           L_800638A0
    // 0x800631A0: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
        goto L_800638A0;
    // 0x800631A0: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
L_800631A4:
    // 0x800631A4: lw          $v0, 0x10($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X10);
    // 0x800631A8: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x800631AC: lh          $v0, 0x2($v1)
    ctx->r2 = MEM_H(ctx->r3, 0X2);
    // 0x800631B0: beql        $v0, $a0, L_80063138
    if (ctx->r2 == ctx->r4) {
        // 0x800631B4: addiu       $a2, $a2, 0x1
        ctx->r6 = ADD32(ctx->r6, 0X1);
            goto L_80063138;
    }
    goto skip_2;
    // 0x800631B4: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    skip_2:
    // 0x800631B8: andi        $a0, $a2, 0xFFFF
    ctx->r4 = ctx->r6 & 0XFFFF;
L_800631BC:
    // 0x800631BC: lw          $v0, 0xC($s0)
    ctx->r2 = MEM_W(ctx->r16, 0XC);
    // 0x800631C0: sll         $v1, $a0, 1
    ctx->r3 = S32(ctx->r4 << 1);
    // 0x800631C4: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800631C8: sw          $v0, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r2;
    // 0x800631CC: lw          $v0, 0x10($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X10);
    // 0x800631D0: sll         $a0, $a0, 2
    ctx->r4 = S32(ctx->r4 << 2);
    // 0x800631D4: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x800631D8: sw          $v0, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->r2;
    // 0x800631DC: lhu         $v0, 0x8($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X8);
    // 0x800631E0: lw          $a1, 0x10($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X10);
    // 0x800631E4: subu        $v1, $v0, $a2
    ctx->r3 = SUB32(ctx->r2, ctx->r6);
    // 0x800631E8: sh          $v1, 0x8($s0)
    MEM_H(0X8, ctx->r16) = ctx->r3;
    // 0x800631EC: lh          $a0, 0x2($a1)
    ctx->r4 = MEM_H(ctx->r5, 0X2);
    // 0x800631F0: lhu         $v0, 0x2($a1)
    ctx->r2 = MEM_HU(ctx->r5, 0X2);
    // 0x800631F4: bne         $a0, $v0, L_80063228
    if (ctx->r4 != ctx->r2) {
        // 0x800631F8: addu        $a2, $zero, $zero
        ctx->r6 = ADD32(0, 0);
            goto L_80063228;
    }
    // 0x800631F8: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // 0x800631FC: andi        $a3, $v1, 0xFFFF
    ctx->r7 = ctx->r3 & 0XFFFF;
    // 0x80063200: addu        $v1, $a0, $zero
    ctx->r3 = ADD32(ctx->r4, 0);
    // 0x80063204: andi        $v0, $a2, 0xFFFF
    ctx->r2 = ctx->r6 & 0XFFFF;
L_80063208:
    // 0x80063208: beq         $a3, $v0, L_8006389C
    if (ctx->r7 == ctx->r2) {
        // 0x8006320C: addiu       $a2, $a2, 0x1
        ctx->r6 = ADD32(ctx->r6, 0X1);
            goto L_8006389C;
    }
    // 0x8006320C: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x80063210: andi        $v0, $a2, 0xFFFF
    ctx->r2 = ctx->r6 & 0XFFFF;
    // 0x80063214: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80063218: addu        $v0, $v0, $a1
    ctx->r2 = ADD32(ctx->r2, ctx->r5);
    // 0x8006321C: lh          $v0, 0x2($v0)
    ctx->r2 = MEM_H(ctx->r2, 0X2);
    // 0x80063220: beq         $v0, $v1, L_80063208
    if (ctx->r2 == ctx->r3) {
        // 0x80063224: andi        $v0, $a2, 0xFFFF
        ctx->r2 = ctx->r6 & 0XFFFF;
            goto L_80063208;
    }
    // 0x80063224: andi        $v0, $a2, 0xFFFF
    ctx->r2 = ctx->r6 & 0XFFFF;
L_80063228:
    // 0x80063228: addu        $t0, $a2, $zero
    ctx->r8 = ADD32(ctx->r6, 0);
    // 0x8006322C: j           L_80063318
    // 0x80063230: addu        $s2, $s1, $zero
    ctx->r18 = ADD32(ctx->r17, 0);
        goto L_80063318;
    // 0x80063230: addu        $s2, $s1, $zero
    ctx->r18 = ADD32(ctx->r17, 0);
L_80063234:
    // 0x80063234: lbu         $v0, 0x456($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X456);
    // 0x80063238: beq         $v0, $zero, L_8006389C
    if (ctx->r2 == 0) {
        // 0x8006323C: lui         $v0, 0x800A
        ctx->r2 = S32(0X800A << 16);
            goto L_8006389C;
    }
    // 0x8006323C: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x80063240: addiu       $v0, $v0, -0x3F0
    ctx->r2 = ADD32(ctx->r2, -0X3F0);
    // 0x80063244: lwc1        $f2, 0x30($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0X30);
    // 0x80063248: lbu         $v1, 0x3C($s1)
    ctx->r3 = MEM_BU(ctx->r17, 0X3C);
    // 0x8006324C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80063250: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x80063254: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x80063258: c.eq.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl == ctx->f0.fl;
    // 0x8006325C: lbu         $v0, 0x3D($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X3D);
    // 0x80063260: lw          $v1, 0x0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X0);
    // 0x80063264: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80063268: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x8006326C: lw          $s0, 0x34($v1)
    ctx->r16 = MEM_W(ctx->r3, 0X34);
    // 0x80063270: bc1tl       L_80063278
    if (c1cs) {
        // 0x80063274: addiu       $s4, $zero, 0x1
        ctx->r20 = ADD32(0, 0X1);
            goto L_80063278;
    }
    goto skip_3;
    // 0x80063274: addiu       $s4, $zero, 0x1
    ctx->r20 = ADD32(0, 0X1);
    skip_3:
L_80063278:
    // 0x80063278: lbu         $v0, 0x46($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X46);
    // 0x8006327C: add.s       $f2, $f2, $f20
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f20.fl;
    // 0x80063280: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x80063284: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x80063288: mul.s       $f0, $f2, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x8006328C: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80063290: lwc1        $f4, -0x4890($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X4890);
    // 0x80063294: c.le.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl <= ctx->f0.fl;
    // 0x80063298: nop

    // 0x8006329C: bc1t        L_800632B4
    if (c1cs) {
        // 0x800632A0: swc1        $f2, 0x30($s1)
        MEM_W(0X30, ctx->r17) = ctx->f2.u32l;
            goto L_800632B4;
    }
    // 0x800632A0: swc1        $f2, 0x30($s1)
    MEM_W(0X30, ctx->r17) = ctx->f2.u32l;
    // 0x800632A4: trunc.w.s   $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    ctx->f10.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800632A8: mfc1        $v1, $f10
    ctx->r3 = (int32_t)ctx->f10.u32l;
    // 0x800632AC: j           L_800632CC
    // 0x800632B0: sh          $v1, 0x3E($s1)
    MEM_H(0X3E, ctx->r17) = ctx->r3;
        goto L_800632CC;
    // 0x800632B0: sh          $v1, 0x3E($s1)
    MEM_H(0X3E, ctx->r17) = ctx->r3;
L_800632B4:
    // 0x800632B4: sub.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f4.fl;
    // 0x800632B8: lui         $v0, 0x8000
    ctx->r2 = S32(0X8000 << 16);
    // 0x800632BC: trunc.w.s   $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    ctx->f10.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800632C0: mfc1        $v1, $f10
    ctx->r3 = (int32_t)ctx->f10.u32l;
    // 0x800632C4: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x800632C8: sh          $v1, 0x3E($s1)
    MEM_H(0X3E, ctx->r17) = ctx->r3;
L_800632CC:
    // 0x800632CC: andi        $v0, $v1, 0xFFFF
    ctx->r2 = ctx->r3 & 0XFFFF;
    // 0x800632D0: bne         $v0, $zero, L_800632DC
    if (ctx->r2 != 0) {
        // 0x800632D4: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_800632DC;
    }
    // 0x800632D4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800632D8: sh          $v0, 0x3E($s1)
    MEM_H(0X3E, ctx->r17) = ctx->r2;
L_800632DC:
    // 0x800632DC: lhu         $v1, 0x3E($s1)
    ctx->r3 = MEM_HU(ctx->r17, 0X3E);
    // 0x800632E0: lh          $v0, 0x44($s1)
    ctx->r2 = MEM_H(ctx->r17, 0X44);
    // 0x800632E4: slt         $v0, $v0, $v1
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800632E8: lhu         $v1, 0x44($s1)
    ctx->r3 = MEM_HU(ctx->r17, 0X44);
    // 0x800632EC: bnel        $v0, $zero, L_800632F4
    if (ctx->r2 != 0) {
        // 0x800632F0: sh          $v1, 0x3E($s1)
        MEM_H(0X3E, ctx->r17) = ctx->r3;
            goto L_800632F4;
    }
    goto skip_4;
    // 0x800632F0: sh          $v1, 0x3E($s1)
    MEM_H(0X3E, ctx->r17) = ctx->r3;
    skip_4:
L_800632F4:
    // 0x800632F4: lhu         $v0, 0x3E($s1)
    ctx->r2 = MEM_HU(ctx->r17, 0X3E);
    // 0x800632F8: addu        $t0, $v0, $zero
    ctx->r8 = ADD32(ctx->r2, 0);
    // 0x800632FC: sh          $t0, 0x8($s0)
    MEM_H(0X8, ctx->r16) = ctx->r8;
    // 0x80063300: lbu         $v1, 0x47($s1)
    ctx->r3 = MEM_BU(ctx->r17, 0X47);
    // 0x80063304: andi        $v0, $t0, 0xFFFF
    ctx->r2 = ctx->r8 & 0XFFFF;
    // 0x80063308: sltu        $v0, $v1, $v0
    ctx->r2 = ctx->r3 < ctx->r2 ? 1 : 0;
    // 0x8006330C: beq         $v0, $zero, L_80063318
    if (ctx->r2 == 0) {
        // 0x80063310: addu        $s2, $s1, $zero
        ctx->r18 = ADD32(ctx->r17, 0);
            goto L_80063318;
    }
    // 0x80063310: addu        $s2, $s1, $zero
    ctx->r18 = ADD32(ctx->r17, 0);
    // 0x80063314: addu        $t0, $v1, $zero
    ctx->r8 = ADD32(ctx->r3, 0);
L_80063318:
    // 0x80063318: lui         $v1, 0x800A
    ctx->r3 = S32(0X800A << 16);
    // 0x8006331C: addiu       $v1, $v1, -0x3F0
    ctx->r3 = ADD32(ctx->r3, -0X3F0);
    // 0x80063320: lbu         $v0, 0x3C($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X3C);
    // 0x80063324: lwc1        $f4, 0x38($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X38);
    // 0x80063328: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8006332C: lwc1        $f0, -0x488C($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X488C);
    // 0x80063330: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80063334: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80063338: lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X0);
    // 0x8006333C: sub.s       $f0, $f4, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f0.fl;
    // 0x80063340: lhu         $v0, 0x2($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X2);
    // 0x80063344: mtc1        $v0, $f6
    ctx->f6.u32l = ctx->r2;
    // 0x80063348: cvt.s.w     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8006334C: mul.s       $f6, $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x80063350: lhu         $v0, 0x6($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X6);
    // 0x80063354: mtc1        $v0, $f2
    ctx->f2.u32l = ctx->r2;
    // 0x80063358: cvt.s.w     $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    ctx->f2.fl = CVT_S_W(ctx->f2.u32l);
    // 0x8006335C: mul.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x80063360: add.s       $f4, $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f4.fl;
    // 0x80063364: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // 0x80063368: andi        $a3, $t0, 0xFFFF
    ctx->r7 = ctx->r8 & 0XFFFF;
    // 0x8006336C: div.s       $f6, $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = DIV_S(ctx->f6.fl, ctx->f4.fl);
    // 0x80063370: beq         $a3, $zero, L_8006347C
    if (ctx->r7 == 0) {
        // 0x80063374: div.s       $f8, $f2, $f4
        CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = DIV_S(ctx->f2.fl, ctx->f4.fl);
            goto L_8006347C;
    }
    // 0x80063374: div.s       $f8, $f2, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = DIV_S(ctx->f2.fl, ctx->f4.fl);
    // 0x80063378: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8006337C: lwc1        $f4, -0x4888($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X4888);
L_80063380:
    // 0x80063380: lbu         $v0, 0x454($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X454);
    // 0x80063384: bne         $v0, $zero, L_800633FC
    if (ctx->r2 != 0) {
        // 0x80063388: andi        $v1, $a2, 0xFFFF
        ctx->r3 = ctx->r6 & 0XFFFF;
            goto L_800633FC;
    }
    // 0x80063388: andi        $v1, $a2, 0xFFFF
    ctx->r3 = ctx->r6 & 0XFFFF;
    // 0x8006338C: andi        $a1, $a2, 0xFFFF
    ctx->r5 = ctx->r6 & 0XFFFF;
    // 0x80063390: lhu         $v0, 0x8($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X8);
    // 0x80063394: lw          $v1, 0x10($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X10);
    // 0x80063398: subu        $v0, $v0, $a3
    ctx->r2 = SUB32(ctx->r2, ctx->r7);
    // 0x8006339C: addu        $v0, $v0, $a1
    ctx->r2 = ADD32(ctx->r2, ctx->r5);
    // 0x800633A0: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800633A4: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800633A8: lh          $v0, 0x0($v0)
    ctx->r2 = MEM_H(ctx->r2, 0X0);
    // 0x800633AC: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x800633B0: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x800633B4: sub.s       $f0, $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f6.fl;
    // 0x800633B8: lwc1        $f2, 0x38($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0X38);
    // 0x800633BC: div.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f2.fl);
    // 0x800633C0: add.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f4.fl;
    // 0x800633C4: sll         $a0, $a1, 2
    ctx->r4 = S32(ctx->r5 << 2);
    // 0x800633C8: addu        $a0, $s1, $a0
    ctx->r4 = ADD32(ctx->r17, ctx->r4);
    // 0x800633CC: trunc.w.s   $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    ctx->f10.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800633D0: mfc1        $v0, $f10
    ctx->r2 = (int32_t)ctx->f10.u32l;
    // 0x800633D4: sh          $v0, 0x4A($a0)
    MEM_H(0X4A, ctx->r4) = ctx->r2;
    // 0x800633D8: lhu         $v0, 0x8($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X8);
    // 0x800633DC: lw          $v1, 0x10($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X10);
    // 0x800633E0: subu        $v0, $v0, $a3
    ctx->r2 = SUB32(ctx->r2, ctx->r7);
    // 0x800633E4: addu        $v0, $v0, $a1
    ctx->r2 = ADD32(ctx->r2, ctx->r5);
    // 0x800633E8: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800633EC: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800633F0: lh          $v0, 0x2($v0)
    ctx->r2 = MEM_H(ctx->r2, 0X2);
    // 0x800633F4: j           L_80063440
    // 0x800633F8: nop

        goto L_80063440;
    // 0x800633F8: nop

L_800633FC:
    // 0x800633FC: lw          $v0, 0x10($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X10);
    // 0x80063400: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x80063404: addu        $v0, $v1, $v0
    ctx->r2 = ADD32(ctx->r3, ctx->r2);
    // 0x80063408: lh          $v0, 0x0($v0)
    ctx->r2 = MEM_H(ctx->r2, 0X0);
    // 0x8006340C: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x80063410: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x80063414: sub.s       $f0, $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f6.fl;
    // 0x80063418: lwc1        $f2, 0x38($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0X38);
    // 0x8006341C: div.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f2.fl);
    // 0x80063420: add.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f4.fl;
    // 0x80063424: addu        $a0, $s1, $v1
    ctx->r4 = ADD32(ctx->r17, ctx->r3);
    // 0x80063428: trunc.w.s   $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    ctx->f10.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x8006342C: mfc1        $v0, $f10
    ctx->r2 = (int32_t)ctx->f10.u32l;
    // 0x80063430: sh          $v0, 0x4A($a0)
    MEM_H(0X4A, ctx->r4) = ctx->r2;
    // 0x80063434: lw          $v0, 0x10($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X10);
    // 0x80063438: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x8006343C: lh          $v0, 0x2($v1)
    ctx->r2 = MEM_H(ctx->r3, 0X2);
L_80063440:
    // 0x80063440: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x80063444: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x80063448: sub.s       $f0, $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f8.fl;
    // 0x8006344C: lwc1        $f2, 0x38($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0X38);
    // 0x80063450: div.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f2.fl);
    // 0x80063454: add.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f4.fl;
    // 0x80063458: trunc.w.s   $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    ctx->f10.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x8006345C: mfc1        $v0, $f10
    ctx->r2 = (int32_t)ctx->f10.u32l;
    // 0x80063460: sh          $v0, 0x4C($a0)
    MEM_H(0X4C, ctx->r4) = ctx->r2;
    // 0x80063464: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x80063468: andi        $a3, $t0, 0xFFFF
    ctx->r7 = ctx->r8 & 0XFFFF;
    // 0x8006346C: andi        $v0, $a2, 0xFFFF
    ctx->r2 = ctx->r6 & 0XFFFF;
    // 0x80063470: sltu        $v0, $v0, $a3
    ctx->r2 = ctx->r2 < ctx->r7 ? 1 : 0;
    // 0x80063474: bne         $v0, $zero, L_80063380
    if (ctx->r2 != 0) {
        // 0x80063478: nop
    
            goto L_80063380;
    }
    // 0x80063478: nop

L_8006347C:
    // 0x8006347C: addiu       $v0, $s1, 0x4A
    ctx->r2 = ADD32(ctx->r17, 0X4A);
    // 0x80063480: sw          $v0, 0x10($s2)
    MEM_W(0X10, ctx->r18) = ctx->r2;
    // 0x80063484: sh          $t0, 0x8($s2)
    MEM_H(0X8, ctx->r18) = ctx->r8;
    // 0x80063488: lbu         $v0, 0x454($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X454);
    // 0x8006348C: lw          $a0, 0xC($s0)
    ctx->r4 = MEM_W(ctx->r16, 0XC);
    // 0x80063490: bnel        $v0, $zero, L_800634B0
    if (ctx->r2 != 0) {
        // 0x80063494: sw          $a0, 0xC($s2)
        MEM_W(0XC, ctx->r18) = ctx->r4;
            goto L_800634B0;
    }
    goto skip_5;
    // 0x80063494: sw          $a0, 0xC($s2)
    MEM_W(0XC, ctx->r18) = ctx->r4;
    skip_5:
    // 0x80063498: lhu         $v0, 0x8($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X8);
    // 0x8006349C: andi        $v1, $t0, 0xFFFF
    ctx->r3 = ctx->r8 & 0XFFFF;
    // 0x800634A0: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x800634A4: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x800634A8: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // 0x800634AC: sw          $a0, 0xC($s2)
    MEM_W(0XC, ctx->r18) = ctx->r4;
L_800634B0:
    // 0x800634B0: lwc1        $f0, 0x18($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X18);
    // 0x800634B4: swc1        $f0, 0x18($s2)
    MEM_W(0X18, ctx->r18) = ctx->f0.u32l;
    // 0x800634B8: lwc1        $f0, 0x1C($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X1C);
    // 0x800634BC: swc1        $f0, 0x1C($s2)
    MEM_W(0X1C, ctx->r18) = ctx->f0.u32l;
    // 0x800634C0: lbu         $v0, 0x2C($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X2C);
    // 0x800634C4: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x800634C8: lwc1        $f2, -0x4884($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X4884);
    // 0x800634CC: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x800634D0: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x800634D4: mul.s       $f2, $f0, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x800634D8: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x800634DC: lwc1        $f0, -0x4880($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X4880);
    // 0x800634E0: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x800634E4: nop

    // 0x800634E8: bc1t        L_8006352C
    if (c1cs) {
        // 0x800634EC: addiu       $v0, $zero, 0xFF
        ctx->r2 = ADD32(0, 0XFF);
            goto L_8006352C;
    }
    // 0x800634EC: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // 0x800634F0: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x800634F4: lwc1        $f0, -0x487C($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X487C);
    // 0x800634F8: c.le.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl <= ctx->f2.fl;
    // 0x800634FC: nop

    // 0x80063500: bc1tl       L_80063518
    if (c1cs) {
        // 0x80063504: sub.s       $f0, $f2, $f0
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f2.fl - ctx->f0.fl;
            goto L_80063518;
    }
    goto skip_6;
    // 0x80063504: sub.s       $f0, $f2, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f2.fl - ctx->f0.fl;
    skip_6:
    // 0x80063508: trunc.w.s   $f10, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    ctx->f10.u32l = TRUNC_W_S(ctx->f2.fl);
    // 0x8006350C: mfc1        $v1, $f10
    ctx->r3 = (int32_t)ctx->f10.u32l;
    // 0x80063510: j           L_8006352C
    // 0x80063514: addu        $v0, $v1, $zero
    ctx->r2 = ADD32(ctx->r3, 0);
        goto L_8006352C;
    // 0x80063514: addu        $v0, $v1, $zero
    ctx->r2 = ADD32(ctx->r3, 0);
L_80063518:
    // 0x80063518: lui         $v0, 0x8000
    ctx->r2 = S32(0X8000 << 16);
    // 0x8006351C: trunc.w.s   $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    ctx->f10.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x80063520: mfc1        $v1, $f10
    ctx->r3 = (int32_t)ctx->f10.u32l;
    // 0x80063524: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x80063528: addu        $v0, $v1, $zero
    ctx->r2 = ADD32(ctx->r3, 0);
L_8006352C:
    // 0x8006352C: sb          $v0, 0x2C($s2)
    MEM_B(0X2C, ctx->r18) = ctx->r2;
    // 0x80063530: lbu         $v0, 0x2D($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X2D);
    // 0x80063534: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80063538: lwc1        $f2, -0x4878($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X4878);
    // 0x8006353C: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x80063540: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x80063544: mul.s       $f2, $f0, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x80063548: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8006354C: lwc1        $f0, -0x4874($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X4874);
    // 0x80063550: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x80063554: nop

    // 0x80063558: bc1t        L_8006359C
    if (c1cs) {
        // 0x8006355C: addiu       $v0, $zero, 0xFF
        ctx->r2 = ADD32(0, 0XFF);
            goto L_8006359C;
    }
    // 0x8006355C: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // 0x80063560: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80063564: lwc1        $f0, -0x4870($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X4870);
    // 0x80063568: c.le.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl <= ctx->f2.fl;
    // 0x8006356C: nop

    // 0x80063570: bc1tl       L_80063588
    if (c1cs) {
        // 0x80063574: sub.s       $f0, $f2, $f0
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f2.fl - ctx->f0.fl;
            goto L_80063588;
    }
    goto skip_7;
    // 0x80063574: sub.s       $f0, $f2, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f2.fl - ctx->f0.fl;
    skip_7:
    // 0x80063578: trunc.w.s   $f10, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    ctx->f10.u32l = TRUNC_W_S(ctx->f2.fl);
    // 0x8006357C: mfc1        $v1, $f10
    ctx->r3 = (int32_t)ctx->f10.u32l;
    // 0x80063580: j           L_8006359C
    // 0x80063584: addu        $v0, $v1, $zero
    ctx->r2 = ADD32(ctx->r3, 0);
        goto L_8006359C;
    // 0x80063584: addu        $v0, $v1, $zero
    ctx->r2 = ADD32(ctx->r3, 0);
L_80063588:
    // 0x80063588: lui         $v0, 0x8000
    ctx->r2 = S32(0X8000 << 16);
    // 0x8006358C: trunc.w.s   $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    ctx->f10.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x80063590: mfc1        $v1, $f10
    ctx->r3 = (int32_t)ctx->f10.u32l;
    // 0x80063594: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x80063598: addu        $v0, $v1, $zero
    ctx->r2 = ADD32(ctx->r3, 0);
L_8006359C:
    // 0x8006359C: sb          $v0, 0x2D($s2)
    MEM_B(0X2D, ctx->r18) = ctx->r2;
    // 0x800635A0: lbu         $v0, 0x2E($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X2E);
    // 0x800635A4: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x800635A8: lwc1        $f2, -0x486C($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X486C);
    // 0x800635AC: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x800635B0: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x800635B4: mul.s       $f2, $f0, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x800635B8: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x800635BC: lwc1        $f0, -0x4868($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X4868);
    // 0x800635C0: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x800635C4: nop

    // 0x800635C8: bc1t        L_8006360C
    if (c1cs) {
        // 0x800635CC: addiu       $v0, $zero, 0xFF
        ctx->r2 = ADD32(0, 0XFF);
            goto L_8006360C;
    }
    // 0x800635CC: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // 0x800635D0: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x800635D4: lwc1        $f0, -0x4864($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X4864);
    // 0x800635D8: c.le.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl <= ctx->f2.fl;
    // 0x800635DC: nop

    // 0x800635E0: bc1tl       L_800635F8
    if (c1cs) {
        // 0x800635E4: sub.s       $f0, $f2, $f0
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f2.fl - ctx->f0.fl;
            goto L_800635F8;
    }
    goto skip_8;
    // 0x800635E4: sub.s       $f0, $f2, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f2.fl - ctx->f0.fl;
    skip_8:
    // 0x800635E8: trunc.w.s   $f10, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    ctx->f10.u32l = TRUNC_W_S(ctx->f2.fl);
    // 0x800635EC: mfc1        $v1, $f10
    ctx->r3 = (int32_t)ctx->f10.u32l;
    // 0x800635F0: j           L_8006360C
    // 0x800635F4: addu        $v0, $v1, $zero
    ctx->r2 = ADD32(ctx->r3, 0);
        goto L_8006360C;
    // 0x800635F4: addu        $v0, $v1, $zero
    ctx->r2 = ADD32(ctx->r3, 0);
L_800635F8:
    // 0x800635F8: lui         $v0, 0x8000
    ctx->r2 = S32(0X8000 << 16);
    // 0x800635FC: trunc.w.s   $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    ctx->f10.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x80063600: mfc1        $v1, $f10
    ctx->r3 = (int32_t)ctx->f10.u32l;
    // 0x80063604: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x80063608: addu        $v0, $v1, $zero
    ctx->r2 = ADD32(ctx->r3, 0);
L_8006360C:
    // 0x8006360C: sb          $v0, 0x2E($s2)
    MEM_B(0X2E, ctx->r18) = ctx->r2;
    // 0x80063610: lbu         $v0, 0x48($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X48);
    // 0x80063614: sb          $v0, 0x2F($s2)
    MEM_B(0X2F, ctx->r18) = ctx->r2;
    // 0x80063618: lwc1        $f0, 0x38($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X38);
    // 0x8006361C: swc1        $f0, 0x24($s2)
    MEM_W(0X24, ctx->r18) = ctx->f0.u32l;
    // 0x80063620: lwc1        $f0, 0x38($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X38);
    // 0x80063624: swc1        $f0, 0x28($s2)
    MEM_W(0X28, ctx->r18) = ctx->f0.u32l;
    // 0x80063628: lhu         $v0, 0x8($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X8);
    // 0x8006362C: lw          $v1, 0x10($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X10);
    // 0x80063630: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80063634: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80063638: lh          $v0, -0x4($v0)
    ctx->r2 = MEM_H(ctx->r2, -0X4);
    // 0x8006363C: lwc1        $f0, 0x18($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X18);
    // 0x80063640: mtc1        $v0, $f2
    ctx->f2.u32l = ctx->r2;
    // 0x80063644: cvt.s.w     $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    ctx->f2.fl = CVT_S_W(ctx->f2.u32l);
    // 0x80063648: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x8006364C: swc1        $f0, 0x18($s3)
    MEM_W(0X18, ctx->r19) = ctx->f0.u32l;
    // 0x80063650: lhu         $v0, 0x8($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X8);
    // 0x80063654: lw          $v1, 0x10($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X10);
    // 0x80063658: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8006365C: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80063660: lh          $v0, -0x2($v0)
    ctx->r2 = MEM_H(ctx->r2, -0X2);
    // 0x80063664: lwc1        $f0, 0x1C($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X1C);
    // 0x80063668: mtc1        $v0, $f2
    ctx->f2.u32l = ctx->r2;
    // 0x8006366C: cvt.s.w     $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    ctx->f2.fl = CVT_S_W(ctx->f2.u32l);
    // 0x80063670: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x80063674: swc1        $f0, 0x1C($s3)
    MEM_W(0X1C, ctx->r19) = ctx->f0.u32l;
    // 0x80063678: lbu         $v0, 0x2C($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X2C);
    // 0x8006367C: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80063680: lwc1        $f2, -0x4860($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X4860);
    // 0x80063684: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x80063688: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x8006368C: mul.s       $f2, $f0, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x80063690: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80063694: lwc1        $f0, -0x485C($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X485C);
    // 0x80063698: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x8006369C: nop

    // 0x800636A0: bc1t        L_800636E4
    if (c1cs) {
        // 0x800636A4: addiu       $v0, $zero, 0xFF
        ctx->r2 = ADD32(0, 0XFF);
            goto L_800636E4;
    }
    // 0x800636A4: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // 0x800636A8: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x800636AC: lwc1        $f0, -0x4858($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X4858);
    // 0x800636B0: c.le.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl <= ctx->f2.fl;
    // 0x800636B4: nop

    // 0x800636B8: bc1tl       L_800636D0
    if (c1cs) {
        // 0x800636BC: sub.s       $f0, $f2, $f0
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f2.fl - ctx->f0.fl;
            goto L_800636D0;
    }
    goto skip_9;
    // 0x800636BC: sub.s       $f0, $f2, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f2.fl - ctx->f0.fl;
    skip_9:
    // 0x800636C0: trunc.w.s   $f10, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    ctx->f10.u32l = TRUNC_W_S(ctx->f2.fl);
    // 0x800636C4: mfc1        $v1, $f10
    ctx->r3 = (int32_t)ctx->f10.u32l;
    // 0x800636C8: j           L_800636E4
    // 0x800636CC: addu        $v0, $v1, $zero
    ctx->r2 = ADD32(ctx->r3, 0);
        goto L_800636E4;
    // 0x800636CC: addu        $v0, $v1, $zero
    ctx->r2 = ADD32(ctx->r3, 0);
L_800636D0:
    // 0x800636D0: lui         $v0, 0x8000
    ctx->r2 = S32(0X8000 << 16);
    // 0x800636D4: trunc.w.s   $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    ctx->f10.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800636D8: mfc1        $v1, $f10
    ctx->r3 = (int32_t)ctx->f10.u32l;
    // 0x800636DC: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x800636E0: addu        $v0, $v1, $zero
    ctx->r2 = ADD32(ctx->r3, 0);
L_800636E4:
    // 0x800636E4: sb          $v0, 0x2C($s3)
    MEM_B(0X2C, ctx->r19) = ctx->r2;
    // 0x800636E8: lbu         $v0, 0x2D($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X2D);
    // 0x800636EC: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x800636F0: lwc1        $f2, -0x4854($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X4854);
    // 0x800636F4: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x800636F8: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x800636FC: mul.s       $f2, $f0, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x80063700: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80063704: lwc1        $f0, -0x4850($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X4850);
    // 0x80063708: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x8006370C: nop

    // 0x80063710: bc1t        L_80063754
    if (c1cs) {
        // 0x80063714: addiu       $v0, $zero, 0xFF
        ctx->r2 = ADD32(0, 0XFF);
            goto L_80063754;
    }
    // 0x80063714: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // 0x80063718: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8006371C: lwc1        $f0, -0x484C($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X484C);
    // 0x80063720: c.le.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl <= ctx->f2.fl;
    // 0x80063724: nop

    // 0x80063728: bc1tl       L_80063740
    if (c1cs) {
        // 0x8006372C: sub.s       $f0, $f2, $f0
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f2.fl - ctx->f0.fl;
            goto L_80063740;
    }
    goto skip_10;
    // 0x8006372C: sub.s       $f0, $f2, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f2.fl - ctx->f0.fl;
    skip_10:
    // 0x80063730: trunc.w.s   $f10, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    ctx->f10.u32l = TRUNC_W_S(ctx->f2.fl);
    // 0x80063734: mfc1        $v1, $f10
    ctx->r3 = (int32_t)ctx->f10.u32l;
    // 0x80063738: j           L_80063754
    // 0x8006373C: addu        $v0, $v1, $zero
    ctx->r2 = ADD32(ctx->r3, 0);
        goto L_80063754;
    // 0x8006373C: addu        $v0, $v1, $zero
    ctx->r2 = ADD32(ctx->r3, 0);
L_80063740:
    // 0x80063740: lui         $v0, 0x8000
    ctx->r2 = S32(0X8000 << 16);
    // 0x80063744: trunc.w.s   $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    ctx->f10.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x80063748: mfc1        $v1, $f10
    ctx->r3 = (int32_t)ctx->f10.u32l;
    // 0x8006374C: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x80063750: addu        $v0, $v1, $zero
    ctx->r2 = ADD32(ctx->r3, 0);
L_80063754:
    // 0x80063754: sb          $v0, 0x2D($s3)
    MEM_B(0X2D, ctx->r19) = ctx->r2;
    // 0x80063758: lbu         $v0, 0x2E($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X2E);
    // 0x8006375C: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80063760: lwc1        $f2, -0x4848($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X4848);
    // 0x80063764: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x80063768: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x8006376C: mul.s       $f2, $f0, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x80063770: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80063774: lwc1        $f0, -0x4844($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X4844);
    // 0x80063778: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x8006377C: nop

    // 0x80063780: bc1t        L_800637C4
    if (c1cs) {
        // 0x80063784: addiu       $v0, $zero, 0xFF
        ctx->r2 = ADD32(0, 0XFF);
            goto L_800637C4;
    }
    // 0x80063784: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // 0x80063788: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8006378C: lwc1        $f0, -0x4840($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X4840);
    // 0x80063790: c.le.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl <= ctx->f2.fl;
    // 0x80063794: nop

    // 0x80063798: bc1tl       L_800637B0
    if (c1cs) {
        // 0x8006379C: sub.s       $f0, $f2, $f0
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f2.fl - ctx->f0.fl;
            goto L_800637B0;
    }
    goto skip_11;
    // 0x8006379C: sub.s       $f0, $f2, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f2.fl - ctx->f0.fl;
    skip_11:
    // 0x800637A0: trunc.w.s   $f10, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    ctx->f10.u32l = TRUNC_W_S(ctx->f2.fl);
    // 0x800637A4: mfc1        $v1, $f10
    ctx->r3 = (int32_t)ctx->f10.u32l;
    // 0x800637A8: j           L_800637C4
    // 0x800637AC: addu        $v0, $v1, $zero
    ctx->r2 = ADD32(ctx->r3, 0);
        goto L_800637C4;
    // 0x800637AC: addu        $v0, $v1, $zero
    ctx->r2 = ADD32(ctx->r3, 0);
L_800637B0:
    // 0x800637B0: lui         $v0, 0x8000
    ctx->r2 = S32(0X8000 << 16);
    // 0x800637B4: trunc.w.s   $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    ctx->f10.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800637B8: mfc1        $v1, $f10
    ctx->r3 = (int32_t)ctx->f10.u32l;
    // 0x800637BC: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x800637C0: addu        $v0, $v1, $zero
    ctx->r2 = ADD32(ctx->r3, 0);
L_800637C4:
    // 0x800637C4: sb          $v0, 0x2E($s3)
    MEM_B(0X2E, ctx->r19) = ctx->r2;
    // 0x800637C8: lbu         $v0, 0x454($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X454);
    // 0x800637CC: bne         $v0, $zero, L_800637D8
    if (ctx->r2 != 0) {
        // 0x800637D0: addu        $a2, $zero, $zero
        ctx->r6 = ADD32(0, 0);
            goto L_800637D8;
    }
    // 0x800637D0: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // 0x800637D4: addiu       $a2, $zero, -0x80
    ctx->r6 = ADD32(0, -0X80);
L_800637D8:
    // 0x800637D8: sb          $a2, 0x2F($s3)
    MEM_B(0X2F, ctx->r19) = ctx->r6;
    // 0x800637DC: lw          $a0, 0x450($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X450);
    // 0x800637E0: beq         $a0, $zero, L_8006381C
    if (ctx->r4 == 0) {
        // 0x800637E4: addu        $a1, $s3, $zero
        ctx->r5 = ADD32(ctx->r19, 0);
            goto L_8006381C;
    }
    // 0x800637E4: addu        $a1, $s3, $zero
    ctx->r5 = ADD32(ctx->r19, 0);
    // 0x800637E8: andi        $a2, $a2, 0xFF
    ctx->r6 = ctx->r6 & 0XFF;
    // 0x800637EC: jal         0x800646AC
    // 0x800637F0: sltu        $a2, $zero, $a2
    ctx->r6 = 0 < ctx->r6 ? 1 : 0;
    func_800646AC(rdram, ctx);
        goto after_3;
    // 0x800637F0: sltu        $a2, $zero, $a2
    ctx->r6 = 0 < ctx->r6 ? 1 : 0;
    after_3:
    // 0x800637F4: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    // 0x800637F8: lhu         $a2, 0x8($s2)
    ctx->r6 = MEM_HU(ctx->r18, 0X8);
    // 0x800637FC: lw          $a0, 0x450($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X450);
    // 0x80063800: jal         0x800646AC
    // 0x80063804: sltu        $a2, $zero, $a2
    ctx->r6 = 0 < ctx->r6 ? 1 : 0;
    func_800646AC(rdram, ctx);
        goto after_4;
    // 0x80063804: sltu        $a2, $zero, $a2
    ctx->r6 = 0 < ctx->r6 ? 1 : 0;
    after_4:
    // 0x80063808: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x8006380C: lhu         $a2, 0x3E($s1)
    ctx->r6 = MEM_HU(ctx->r17, 0X3E);
    // 0x80063810: lw          $a0, 0x450($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X450);
    // 0x80063814: jal         0x800646AC
    // 0x80063818: sltu        $a2, $zero, $a2
    ctx->r6 = 0 < ctx->r6 ? 1 : 0;
    func_800646AC(rdram, ctx);
        goto after_5;
    // 0x80063818: sltu        $a2, $zero, $a2
    ctx->r6 = 0 < ctx->r6 ? 1 : 0;
    after_5:
L_8006381C:
    // 0x8006381C: lbu         $v0, 0x454($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X454);
    // 0x80063820: bne         $v0, $zero, L_800638A0
    if (ctx->r2 != 0) {
        // 0x80063824: addu        $v0, $s4, $zero
        ctx->r2 = ADD32(ctx->r20, 0);
            goto L_800638A0;
    }
    // 0x80063824: addu        $v0, $s4, $zero
    ctx->r2 = ADD32(ctx->r20, 0);
    // 0x80063828: lhu         $v1, 0x3E($s1)
    ctx->r3 = MEM_HU(ctx->r17, 0X3E);
    // 0x8006382C: lh          $v0, 0x44($s1)
    ctx->r2 = MEM_H(ctx->r17, 0X44);
    // 0x80063830: bne         $v1, $v0, L_800638A0
    if (ctx->r3 != ctx->r2) {
        // 0x80063834: addu        $v0, $s4, $zero
        ctx->r2 = ADD32(ctx->r20, 0);
            goto L_800638A0;
    }
    // 0x80063834: addu        $v0, $s4, $zero
    ctx->r2 = ADD32(ctx->r20, 0);
    // 0x80063838: lw          $a0, 0x450($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X450);
    // 0x8006383C: beq         $a0, $zero, L_8006384C
    if (ctx->r4 == 0) {
        // 0x80063840: addu        $a1, $s3, $zero
        ctx->r5 = ADD32(ctx->r19, 0);
            goto L_8006384C;
    }
    // 0x80063840: addu        $a1, $s3, $zero
    ctx->r5 = ADD32(ctx->r19, 0);
    // 0x80063844: jal         0x800646AC
    // 0x80063848: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    func_800646AC(rdram, ctx);
        goto after_6;
    // 0x80063848: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    after_6:
L_8006384C:
    // 0x8006384C: lbu         $v0, 0x455($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X455);
    // 0x80063850: bne         $v0, $zero, L_80063860
    if (ctx->r2 != 0) {
        // 0x80063854: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80063860;
    }
    // 0x80063854: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80063858: sb          $v0, 0x455($s1)
    MEM_B(0X455, ctx->r17) = ctx->r2;
    // 0x8006385C: addiu       $s4, $zero, 0x2
    ctx->r20 = ADD32(0, 0X2);
L_80063860:
    // 0x80063860: lbu         $v0, 0x47($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X47);
    // 0x80063864: beql        $v0, $zero, L_8006389C
    if (ctx->r2 == 0) {
        // 0x80063868: sb          $zero, 0x456($s1)
        MEM_B(0X456, ctx->r17) = 0;
            goto L_8006389C;
    }
    goto skip_12;
    // 0x80063868: sb          $zero, 0x456($s1)
    MEM_B(0X456, ctx->r17) = 0;
    skip_12:
    // 0x8006386C: lwc1        $f0, 0x34($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X34);
    // 0x80063870: add.s       $f0, $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f20.fl;
    // 0x80063874: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80063878: lwc1        $f2, -0x483C($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X483C);
    // 0x8006387C: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x80063880: nop

    // 0x80063884: bc1f        L_8006389C
    if (!c1cs) {
        // 0x80063888: swc1        $f0, 0x34($s1)
        MEM_W(0X34, ctx->r17) = ctx->f0.u32l;
            goto L_8006389C;
    }
    // 0x80063888: swc1        $f0, 0x34($s1)
    MEM_W(0X34, ctx->r17) = ctx->f0.u32l;
    // 0x8006388C: lbu         $v0, 0x47($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X47);
    // 0x80063890: sw          $zero, 0x34($s1)
    MEM_W(0X34, ctx->r17) = 0;
    // 0x80063894: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x80063898: sb          $v0, 0x47($s1)
    MEM_B(0X47, ctx->r17) = ctx->r2;
L_8006389C:
    // 0x8006389C: addu        $v0, $s4, $zero
    ctx->r2 = ADD32(ctx->r20, 0);
L_800638A0:
    // 0x800638A0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800638A4: lw          $s4, 0x20($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X20);
    // 0x800638A8: lw          $s3, 0x1C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X1C);
    // 0x800638AC: lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X18);
    // 0x800638B0: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x800638B4: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x800638B8: ldc1        $f20, 0x28($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X28);
    // 0x800638BC: jr          $ra
    // 0x800638C0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x800638C0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_800638C4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800638C4: addiu       $sp, $sp, -0x88
    ctx->r29 = ADD32(ctx->r29, -0X88);
    // 0x800638C8: sw          $s2, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r18;
    // 0x800638CC: addu        $s2, $a0, $zero
    ctx->r18 = ADD32(ctx->r4, 0);
    // 0x800638D0: sw          $s3, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r19;
    // 0x800638D4: addu        $s3, $a1, $zero
    ctx->r19 = ADD32(ctx->r5, 0);
    // 0x800638D8: addiu       $v1, $sp, 0x10
    ctx->r3 = ADD32(ctx->r29, 0X10);
    // 0x800638DC: lui         $v0, 0x8004
    ctx->r2 = S32(0X8004 << 16);
    // 0x800638E0: addiu       $v0, $v0, -0x4838
    ctx->r2 = ADD32(ctx->r2, -0X4838);
    // 0x800638E4: addiu       $a0, $v0, 0x20
    ctx->r4 = ADD32(ctx->r2, 0X20);
    // 0x800638E8: sw          $ra, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r31;
    // 0x800638EC: sw          $s1, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r17;
    // 0x800638F0: sw          $s0, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r16;
L_800638F4:
    // 0x800638F4: lw          $a3, 0x0($v0)
    ctx->r7 = MEM_W(ctx->r2, 0X0);
    // 0x800638F8: lw          $t0, 0x4($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X4);
    // 0x800638FC: lw          $t1, 0x8($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X8);
    // 0x80063900: lw          $t2, 0xC($v0)
    ctx->r10 = MEM_W(ctx->r2, 0XC);
    // 0x80063904: sw          $a3, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r7;
    // 0x80063908: sw          $t0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r8;
    // 0x8006390C: sw          $t1, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r9;
    // 0x80063910: sw          $t2, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r10;
    // 0x80063914: addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
    // 0x80063918: bne         $v0, $a0, L_800638F4
    if (ctx->r2 != ctx->r4) {
        // 0x8006391C: addiu       $v1, $v1, 0x10
        ctx->r3 = ADD32(ctx->r3, 0X10);
            goto L_800638F4;
    }
    // 0x8006391C: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
    // 0x80063920: lw          $a3, 0x0($v0)
    ctx->r7 = MEM_W(ctx->r2, 0X0);
    // 0x80063924: sw          $a3, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r7;
    // 0x80063928: addiu       $v1, $sp, 0x38
    ctx->r3 = ADD32(ctx->r29, 0X38);
    // 0x8006392C: lui         $v0, 0x8004
    ctx->r2 = S32(0X8004 << 16);
    // 0x80063930: addiu       $v0, $v0, -0x480C
    ctx->r2 = ADD32(ctx->r2, -0X480C);
    // 0x80063934: addiu       $a0, $v0, 0x30
    ctx->r4 = ADD32(ctx->r2, 0X30);
L_80063938:
    // 0x80063938: lw          $a3, 0x0($v0)
    ctx->r7 = MEM_W(ctx->r2, 0X0);
    // 0x8006393C: lw          $t0, 0x4($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X4);
    // 0x80063940: lw          $t1, 0x8($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X8);
    // 0x80063944: lw          $t2, 0xC($v0)
    ctx->r10 = MEM_W(ctx->r2, 0XC);
    // 0x80063948: sw          $a3, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r7;
    // 0x8006394C: sw          $t0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r8;
    // 0x80063950: sw          $t1, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r9;
    // 0x80063954: sw          $t2, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r10;
    // 0x80063958: addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
    // 0x8006395C: bne         $v0, $a0, L_80063938
    if (ctx->r2 != ctx->r4) {
        // 0x80063960: addiu       $v1, $v1, 0x10
        ctx->r3 = ADD32(ctx->r3, 0X10);
            goto L_80063938;
    }
    // 0x80063960: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
    // 0x80063964: addiu       $a0, $zero, 0x34
    ctx->r4 = ADD32(0, 0X34);
    // 0x80063968: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x8006396C: lw          $a3, 0x0($v0)
    ctx->r7 = MEM_W(ctx->r2, 0X0);
    // 0x80063970: jal         0x80001ACC
    // 0x80063974: sw          $a3, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r7;
    rs_malloc(rdram, ctx);
        goto after_0;
    // 0x80063974: sw          $a3, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r7;
    after_0:
    // 0x80063978: addu        $s1, $v0, $zero
    ctx->r17 = ADD32(ctx->r2, 0);
    // 0x8006397C: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x80063980: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x80063984: jal         0x800078E0
    // 0x80063988: addiu       $a2, $zero, 0x34
    ctx->r6 = ADD32(0, 0X34);
    rs_memset(rdram, ctx);
        goto after_1;
    // 0x80063988: addiu       $a2, $zero, 0x34
    ctx->r6 = ADD32(0, 0X34);
    after_1:
    // 0x8006398C: sll         $s0, $s2, 16
    ctx->r16 = S32(ctx->r18 << 16);
    // 0x80063990: sra         $s0, $s0, 16
    ctx->r16 = S32(SIGNED(ctx->r16) >> 16);
    // 0x80063994: sll         $v0, $s3, 16
    ctx->r2 = S32(ctx->r19 << 16);
    // 0x80063998: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x8006399C: mult        $s0, $v0
    result = S64(S32(ctx->r16)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800639A0: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x800639A4: sh          $s2, 0x60($sp)
    MEM_H(0X60, ctx->r29) = ctx->r18;
    // 0x800639A8: sh          $s3, 0x62($sp)
    MEM_H(0X62, ctx->r29) = ctx->r19;
    // 0x800639AC: mflo        $s0
    ctx->r16 = lo;
    // 0x800639B0: jal         0x80001ACC
    // 0x800639B4: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    rs_malloc(rdram, ctx);
        goto after_2;
    // 0x800639B4: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_2:
    // 0x800639B8: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // 0x800639BC: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x800639C0: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    // 0x800639C4: jal         0x800078E0
    // 0x800639C8: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    rs_memset(rdram, ctx);
        goto after_3;
    // 0x800639C8: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    after_3:
    // 0x800639CC: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    // 0x800639D0: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    // 0x800639D4: jal         0x80022B90
    // 0x800639D8: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    registerHmtTextureInTable(rdram, ctx);
        goto after_4;
    // 0x800639D8: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    after_4:
    // 0x800639DC: sh          $v0, 0x30($s1)
    MEM_H(0X30, ctx->r17) = ctx->r2;
    // 0x800639E0: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x800639E4: jal         0x80001C98
    // 0x800639E8: nop

    rs_free(rdram, ctx);
        goto after_5;
    // 0x800639E8: nop

    after_5:
    // 0x800639EC: addu        $v0, $s1, $zero
    ctx->r2 = ADD32(ctx->r17, 0);
    // 0x800639F0: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800639F4: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x800639F8: lwc1        $f2, -0x47D8($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X47D8);
    // 0x800639FC: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x80063A00: sh          $v1, 0xA($v0)
    MEM_H(0XA, ctx->r2) = ctx->r3;
    // 0x80063A04: sh          $v1, 0x8($v0)
    MEM_H(0X8, ctx->r2) = ctx->r3;
    // 0x80063A08: addiu       $v1, $zero, 0x3
    ctx->r3 = ADD32(0, 0X3);
    // 0x80063A0C: sw          $v1, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->r3;
    // 0x80063A10: addiu       $v1, $v0, 0x30
    ctx->r3 = ADD32(ctx->r2, 0X30);
    // 0x80063A14: sw          $v1, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r3;
    // 0x80063A18: addiu       $v1, $zero, 0xFF
    ctx->r3 = ADD32(0, 0XFF);
    // 0x80063A1C: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80063A20: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
    // 0x80063A24: sw          $zero, 0x10($v0)
    MEM_W(0X10, ctx->r2) = 0;
    // 0x80063A28: sb          $v1, 0x2F($v0)
    MEM_B(0X2F, ctx->r2) = ctx->r3;
    // 0x80063A2C: sb          $v1, 0x2E($v0)
    MEM_B(0X2E, ctx->r2) = ctx->r3;
    // 0x80063A30: sb          $v1, 0x2D($v0)
    MEM_B(0X2D, ctx->r2) = ctx->r3;
    // 0x80063A34: sb          $v1, 0x2C($v0)
    MEM_B(0X2C, ctx->r2) = ctx->r3;
    // 0x80063A38: swc1        $f0, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->f0.u32l;
    // 0x80063A3C: swc1        $f0, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->f0.u32l;
    // 0x80063A40: swc1        $f2, 0x28($v0)
    MEM_W(0X28, ctx->r2) = ctx->f2.u32l;
    // 0x80063A44: swc1        $f2, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->f2.u32l;
    // 0x80063A48: swc1        $f0, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->f0.u32l;
    // 0x80063A4C: lw          $ra, 0x80($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X80);
    // 0x80063A50: lw          $s3, 0x7C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X7C);
    // 0x80063A54: lw          $s2, 0x78($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X78);
    // 0x80063A58: lw          $s1, 0x74($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X74);
    // 0x80063A5C: lw          $s0, 0x70($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X70);
    // 0x80063A60: jr          $ra
    // 0x80063A64: addiu       $sp, $sp, 0x88
    ctx->r29 = ADD32(ctx->r29, 0X88);
    return;
    // 0x80063A64: addiu       $sp, $sp, 0x88
    ctx->r29 = ADD32(ctx->r29, 0X88);
;}
RECOMP_FUNC void func_80063A68(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80063A68: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x80063A6C: addiu       $v0, $v0, -0x3F0
    ctx->r2 = ADD32(ctx->r2, -0X3F0);
    // 0x80063A70: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    // 0x80063A74: sll         $a0, $a0, 2
    ctx->r4 = S32(ctx->r4 << 2);
    // 0x80063A78: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // 0x80063A7C: lw          $a0, 0x0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X0);
    // 0x80063A80: lhu         $v0, 0x0($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X0);
    // 0x80063A84: beq         $v0, $zero, L_80063B00
    if (ctx->r2 == 0) {
        // 0x80063A88: addu        $a2, $zero, $zero
        ctx->r6 = ADD32(0, 0);
            goto L_80063B00;
    }
    // 0x80063A88: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // 0x80063A8C: lw          $t2, 0x24($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X24);
    // 0x80063A90: andi        $t0, $a1, 0xFFFF
    ctx->r8 = ctx->r5 & 0XFFFF;
    // 0x80063A94: addu        $t1, $v0, $zero
    ctx->r9 = ADD32(ctx->r2, 0);
    // 0x80063A98: andi        $a3, $a2, 0xFFFF
    ctx->r7 = ctx->r6 & 0XFFFF;
L_80063A9C:
    // 0x80063A9C: sll         $v1, $a3, 1
    ctx->r3 = S32(ctx->r7 << 1);
    // 0x80063AA0: addu        $v0, $v1, $t2
    ctx->r2 = ADD32(ctx->r3, ctx->r10);
    // 0x80063AA4: lhu         $v0, 0x0($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X0);
    // 0x80063AA8: beq         $v0, $t0, L_80063AC4
    if (ctx->r2 == ctx->r8) {
        // 0x80063AAC: nop
    
            goto L_80063AC4;
    }
    // 0x80063AAC: nop

    // 0x80063AB0: lw          $v0, 0x28($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X28);
    // 0x80063AB4: addu        $v0, $v1, $v0
    ctx->r2 = ADD32(ctx->r3, ctx->r2);
    // 0x80063AB8: lhu         $v0, 0x0($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X0);
    // 0x80063ABC: bnel        $v0, $t0, L_80063AF0
    if (ctx->r2 != ctx->r8) {
        // 0x80063AC0: addiu       $a2, $a2, 0x1
        ctx->r6 = ADD32(ctx->r6, 0X1);
            goto L_80063AF0;
    }
    goto skip_0;
    // 0x80063AC0: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    skip_0:
L_80063AC4:
    // 0x80063AC4: lbu         $v0, 0x14($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X14);
    // 0x80063AC8: beq         $v0, $zero, L_80063ADC
    if (ctx->r2 == 0) {
        // 0x80063ACC: nop
    
            goto L_80063ADC;
    }
    // 0x80063ACC: nop

    // 0x80063AD0: lh          $v0, 0x2($a0)
    ctx->r2 = MEM_H(ctx->r4, 0X2);
    // 0x80063AD4: jr          $ra
    // 0x80063AD8: nop

    return;
    // 0x80063AD8: nop

L_80063ADC:
    // 0x80063ADC: lw          $v0, 0x18($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X18);
    // 0x80063AE0: addu        $v0, $v0, $a3
    ctx->r2 = ADD32(ctx->r2, ctx->r7);
    // 0x80063AE4: lbu         $v0, 0x0($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X0);
    // 0x80063AE8: jr          $ra
    // 0x80063AEC: nop

    return;
    // 0x80063AEC: nop

L_80063AF0:
    // 0x80063AF0: andi        $v0, $a2, 0xFFFF
    ctx->r2 = ctx->r6 & 0XFFFF;
    // 0x80063AF4: sltu        $v0, $v0, $t1
    ctx->r2 = ctx->r2 < ctx->r9 ? 1 : 0;
    // 0x80063AF8: bne         $v0, $zero, L_80063A9C
    if (ctx->r2 != 0) {
        // 0x80063AFC: andi        $a3, $a2, 0xFFFF
        ctx->r7 = ctx->r6 & 0XFFFF;
            goto L_80063A9C;
    }
    // 0x80063AFC: andi        $a3, $a2, 0xFFFF
    ctx->r7 = ctx->r6 & 0XFFFF;
L_80063B00:
    // 0x80063B00: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x80063B04: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x80063B08: addiu       $a3, $v0, -0x6690
    ctx->r7 = ADD32(ctx->r2, -0X6690);
    // 0x80063B0C: andi        $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 & 0XFFFF;
    // 0x80063B10: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x80063B14: addiu       $a2, $v0, -0x1278
    ctx->r6 = ADD32(ctx->r2, -0X1278);
    // 0x80063B18: andi        $v1, $a0, 0xFFFF
    ctx->r3 = ctx->r4 & 0XFFFF;
L_80063B1C:
    // 0x80063B1C: sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3 << 1);
    // 0x80063B20: addu        $v0, $v0, $a3
    ctx->r2 = ADD32(ctx->r2, ctx->r7);
    // 0x80063B24: lhu         $v0, 0x0($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X0);
    // 0x80063B28: bne         $v0, $a1, L_80063B40
    if (ctx->r2 != ctx->r5) {
        // 0x80063B2C: addiu       $a0, $a0, 0x1
        ctx->r4 = ADD32(ctx->r4, 0X1);
            goto L_80063B40;
    }
    // 0x80063B2C: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x80063B30: addu        $v0, $v1, $a2
    ctx->r2 = ADD32(ctx->r3, ctx->r6);
    // 0x80063B34: lb          $v0, 0x0($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X0);
    // 0x80063B38: jr          $ra
    // 0x80063B3C: nop

    return;
    // 0x80063B3C: nop

L_80063B40:
    // 0x80063B40: andi        $v0, $a0, 0xFFFF
    ctx->r2 = ctx->r4 & 0XFFFF;
    // 0x80063B44: sltiu       $v0, $v0, 0x6
    ctx->r2 = ctx->r2 < 0X6 ? 1 : 0;
    // 0x80063B48: bne         $v0, $zero, L_80063B1C
    if (ctx->r2 != 0) {
        // 0x80063B4C: andi        $v1, $a0, 0xFFFF
        ctx->r3 = ctx->r4 & 0XFFFF;
            goto L_80063B1C;
    }
    // 0x80063B4C: andi        $v1, $a0, 0xFFFF
    ctx->r3 = ctx->r4 & 0XFFFF;
    // 0x80063B50: jr          $ra
    // 0x80063B54: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    return;
    // 0x80063B54: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
;}
RECOMP_FUNC void func_80063B58(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80063B58: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // 0x80063B5C: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x80063B60: addiu       $a3, $v0, -0x3F0
    ctx->r7 = ADD32(ctx->r2, -0X3F0);
L_80063B64:
    // 0x80063B64: lw          $v1, 0x0($a3)
    ctx->r3 = MEM_W(ctx->r7, 0X0);
    // 0x80063B68: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x80063B6C: addu        $a1, $v1, $zero
    ctx->r5 = ADD32(ctx->r3, 0);
    // 0x80063B70: sw          $zero, 0x20($v1)
    MEM_W(0X20, ctx->r3) = 0;
    // 0x80063B74: sw          $zero, 0x24($v1)
    MEM_W(0X24, ctx->r3) = 0;
    // 0x80063B78: sw          $zero, 0x28($v1)
    MEM_W(0X28, ctx->r3) = 0;
    // 0x80063B7C: sh          $zero, 0x2C($v1)
    MEM_H(0X2C, ctx->r3) = 0;
    // 0x80063B80: sw          $zero, 0x30($v1)
    MEM_W(0X30, ctx->r3) = 0;
L_80063B84:
    // 0x80063B84: sw          $zero, 0x34($a1)
    MEM_W(0X34, ctx->r5) = 0;
    // 0x80063B88: addu        $v0, $v1, $a0
    ctx->r2 = ADD32(ctx->r3, ctx->r4);
    // 0x80063B8C: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x80063B90: sb          $zero, 0x84($v0)
    MEM_B(0X84, ctx->r2) = 0;
    // 0x80063B94: sltiu       $v0, $a0, 0x14
    ctx->r2 = ctx->r4 < 0X14 ? 1 : 0;
    // 0x80063B98: bne         $v0, $zero, L_80063B84
    if (ctx->r2 != 0) {
        // 0x80063B9C: addiu       $a1, $a1, 0x4
        ctx->r5 = ADD32(ctx->r5, 0X4);
            goto L_80063B84;
    }
    // 0x80063B9C: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x80063BA0: addiu       $a3, $a3, 0x4
    ctx->r7 = ADD32(ctx->r7, 0X4);
    // 0x80063BA4: addiu       $v0, $a2, 0x41
    ctx->r2 = ADD32(ctx->r6, 0X41);
    // 0x80063BA8: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x80063BAC: sb          $v0, 0xF8($v1)
    MEM_B(0XF8, ctx->r3) = ctx->r2;
    // 0x80063BB0: sltiu       $v0, $a2, 0xC
    ctx->r2 = ctx->r6 < 0XC ? 1 : 0;
    // 0x80063BB4: sw          $zero, 0xEC($v1)
    MEM_W(0XEC, ctx->r3) = 0;
    // 0x80063BB8: sw          $zero, 0xF0($v1)
    MEM_W(0XF0, ctx->r3) = 0;
    // 0x80063BBC: sw          $zero, 0xF4($v1)
    MEM_W(0XF4, ctx->r3) = 0;
    // 0x80063BC0: bne         $v0, $zero, L_80063B64
    if (ctx->r2 != 0) {
        // 0x80063BC4: sw          $zero, 0xFC($v1)
        MEM_W(0XFC, ctx->r3) = 0;
            goto L_80063B64;
    }
    // 0x80063BC4: sw          $zero, 0xFC($v1)
    MEM_W(0XFC, ctx->r3) = 0;
    // 0x80063BC8: lui         $v1, 0x8014
    ctx->r3 = S32(0X8014 << 16);
    // 0x80063BCC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80063BD0: sb          $v0, -0x66A0($v1)
    MEM_B(-0X66A0, ctx->r3) = ctx->r2;
    // 0x80063BD4: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x80063BD8: addiu       $v1, $zero, 0x140
    ctx->r3 = ADD32(0, 0X140);
    // 0x80063BDC: sh          $v1, -0x669E($v0)
    MEM_H(-0X669E, ctx->r2) = ctx->r3;
    // 0x80063BE0: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x80063BE4: jr          $ra
    // 0x80063BE8: sh          $v1, -0x669C($v0)
    MEM_H(-0X669C, ctx->r2) = ctx->r3;
    return;
    // 0x80063BE8: sh          $v1, -0x669C($v0)
    MEM_H(-0X669C, ctx->r2) = ctx->r3;
;}
RECOMP_FUNC void func_80063BEC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80063BEC: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x80063BF0: addiu       $v0, $v0, -0x3F0
    ctx->r2 = ADD32(ctx->r2, -0X3F0);
    // 0x80063BF4: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    // 0x80063BF8: sll         $a0, $a0, 2
    ctx->r4 = S32(ctx->r4 << 2);
    // 0x80063BFC: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // 0x80063C00: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x80063C04: sw          $zero, 0x28($v0)
    MEM_W(0X28, ctx->r2) = 0;
    // 0x80063C08: sw          $zero, 0x24($v0)
    MEM_W(0X24, ctx->r2) = 0;
    // 0x80063C0C: sw          $zero, 0x20($v0)
    MEM_W(0X20, ctx->r2) = 0;
    // 0x80063C10: jr          $ra
    // 0x80063C14: sw          $zero, 0x30($v0)
    MEM_W(0X30, ctx->r2) = 0;
    return;
    // 0x80063C14: sw          $zero, 0x30($v0)
    MEM_W(0X30, ctx->r2) = 0;
;}
RECOMP_FUNC void func_80063C18(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80063C18: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x80063C1C: addiu       $v0, $v0, -0x3F0
    ctx->r2 = ADD32(ctx->r2, -0X3F0);
    // 0x80063C20: andi        $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 & 0XFF;
    // 0x80063C24: sll         $a0, $a0, 2
    ctx->r4 = S32(ctx->r4 << 2);
    // 0x80063C28: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // 0x80063C2C: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x80063C30: lw          $v0, 0x20($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X20);
    // 0x80063C34: jr          $ra
    // 0x80063C38: nop

    return;
    // 0x80063C38: nop

;}
RECOMP_FUNC void func_80063C3C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80063C3C: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x80063C40: addiu       $v0, $v0, -0x3F0
    ctx->r2 = ADD32(ctx->r2, -0X3F0);
    // 0x80063C44: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    // 0x80063C48: sll         $a0, $a0, 2
    ctx->r4 = S32(ctx->r4 << 2);
    // 0x80063C4C: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // 0x80063C50: andi        $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 & 0XFFFF;
    // 0x80063C54: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x80063C58: sll         $a1, $a1, 2
    ctx->r5 = S32(ctx->r5 << 2);
    // 0x80063C5C: addu        $v0, $v0, $a1
    ctx->r2 = ADD32(ctx->r2, ctx->r5);
    // 0x80063C60: lw          $v0, 0x34($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X34);
    // 0x80063C64: jr          $ra
    // 0x80063C68: nop

    return;
    // 0x80063C68: nop

;}
RECOMP_FUNC void func_80063C6C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80063C6C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80063C70: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x80063C74: addiu       $v0, $v0, -0x3F0
    ctx->r2 = ADD32(ctx->r2, -0X3F0);
    // 0x80063C78: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    // 0x80063C7C: sll         $a0, $a0, 2
    ctx->r4 = S32(ctx->r4 << 2);
    // 0x80063C80: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // 0x80063C84: sw          $ra, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r31;
    // 0x80063C88: sw          $s3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r19;
    // 0x80063C8C: sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // 0x80063C90: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x80063C94: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x80063C98: lw          $s1, 0x0($a0)
    ctx->r17 = MEM_W(ctx->r4, 0X0);
    // 0x80063C9C: lw          $v0, 0xF4($s1)
    ctx->r2 = MEM_W(ctx->r17, 0XF4);
    // 0x80063CA0: beq         $v0, $zero, L_80063CE0
    if (ctx->r2 == 0) {
        // 0x80063CA4: addu        $s3, $a1, $zero
        ctx->r19 = ADD32(ctx->r5, 0);
            goto L_80063CE0;
    }
    // 0x80063CA4: addu        $s3, $a1, $zero
    ctx->r19 = ADD32(ctx->r5, 0);
    // 0x80063CA8: lhu         $v0, 0x2C($s1)
    ctx->r2 = MEM_HU(ctx->r17, 0X2C);
    // 0x80063CAC: beq         $v0, $zero, L_80063CE0
    if (ctx->r2 == 0) {
        // 0x80063CB0: addu        $s0, $zero, $zero
        ctx->r16 = ADD32(0, 0);
            goto L_80063CE0;
    }
    // 0x80063CB0: addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
    // 0x80063CB4: addu        $s2, $s1, $zero
    ctx->r18 = ADD32(ctx->r17, 0);
L_80063CB8:
    // 0x80063CB8: lw          $a1, 0x34($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X34);
    // 0x80063CBC: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
    // 0x80063CC0: lw          $a0, 0xF4($s1)
    ctx->r4 = MEM_W(ctx->r17, 0XF4);
    // 0x80063CC4: jal         0x800642A0
    // 0x80063CC8: andi        $a2, $s3, 0xFF
    ctx->r6 = ctx->r19 & 0XFF;
    func_800642A0(rdram, ctx);
        goto after_0;
    // 0x80063CC8: andi        $a2, $s3, 0xFF
    ctx->r6 = ctx->r19 & 0XFF;
    after_0:
    // 0x80063CCC: lhu         $v0, 0x2C($s1)
    ctx->r2 = MEM_HU(ctx->r17, 0X2C);
    // 0x80063CD0: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80063CD4: sltu        $v0, $s0, $v0
    ctx->r2 = ctx->r16 < ctx->r2 ? 1 : 0;
    // 0x80063CD8: bne         $v0, $zero, L_80063CB8
    if (ctx->r2 != 0) {
        // 0x80063CDC: nop
    
            goto L_80063CB8;
    }
    // 0x80063CDC: nop

L_80063CE0:
    // 0x80063CE0: lw          $ra, 0x20($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X20);
    // 0x80063CE4: lw          $s3, 0x1C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X1C);
    // 0x80063CE8: lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X18);
    // 0x80063CEC: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x80063CF0: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x80063CF4: jr          $ra
    // 0x80063CF8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80063CF8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_80063CFC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80063CFC: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80063D00: lui         $v1, 0x800A
    ctx->r3 = S32(0X800A << 16);
    // 0x80063D04: addiu       $v1, $v1, -0x3F0
    ctx->r3 = ADD32(ctx->r3, -0X3F0);
    // 0x80063D08: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    // 0x80063D0C: sll         $v0, $a0, 2
    ctx->r2 = S32(ctx->r4 << 2);
    // 0x80063D10: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80063D14: andi        $a2, $a2, 0xFFFF
    ctx->r6 = ctx->r6 & 0XFFFF;
    // 0x80063D18: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80063D1C: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x80063D20: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x80063D24: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80063D28: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80063D2C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80063D30: lw          $s0, 0x0($v0)
    ctx->r16 = MEM_W(ctx->r2, 0X0);
    // 0x80063D34: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80063D38: lw          $v1, 0x30($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X30);
    // 0x80063D3C: sllv        $v0, $v0, $a2
    ctx->r2 = S32(ctx->r2 << (ctx->r6 & 31));
    // 0x80063D40: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x80063D44: sw          $v1, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->r3;
    // 0x80063D48: lw          $s4, 0x40($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X40);
    // 0x80063D4C: lbu         $v1, 0x1F($s0)
    ctx->r3 = MEM_BU(ctx->r16, 0X1F);
    // 0x80063D50: addu        $v0, $s0, $a2
    ctx->r2 = ADD32(ctx->r16, ctx->r6);
    // 0x80063D54: sb          $v1, 0x84($v0)
    MEM_B(0X84, ctx->r2) = ctx->r3;
    // 0x80063D58: lhu         $v0, 0xE8($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0XE8);
    // 0x80063D5C: mult        $v0, $a2
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80063D60: sll         $v0, $a2, 2
    ctx->r2 = S32(ctx->r6 << 2);
    // 0x80063D64: addu        $s2, $s0, $v0
    ctx->r18 = ADD32(ctx->r16, ctx->r2);
    // 0x80063D68: lw          $v0, 0xEC($s0)
    ctx->r2 = MEM_W(ctx->r16, 0XEC);
    // 0x80063D6C: lw          $s1, 0x34($s2)
    ctx->r17 = MEM_W(ctx->r18, 0X34);
    // 0x80063D70: mflo        $t1
    ctx->r9 = lo;
    // 0x80063D74: sll         $v1, $t1, 2
    ctx->r3 = S32(ctx->r9 << 2);
    // 0x80063D78: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80063D7C: sw          $v0, 0x10($s1)
    MEM_W(0X10, ctx->r17) = ctx->r2;
    // 0x80063D80: lhu         $v0, 0xE8($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0XE8);
    // 0x80063D84: addu        $t0, $a1, $zero
    ctx->r8 = ADD32(ctx->r5, 0);
    // 0x80063D88: mult        $v0, $a2
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80063D8C: addu        $s3, $a3, $zero
    ctx->r19 = ADD32(ctx->r7, 0);
    // 0x80063D90: addu        $a3, $t0, $zero
    ctx->r7 = ADD32(ctx->r8, 0);
    // 0x80063D94: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    // 0x80063D98: lw          $v0, 0xF0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0XF0);
    // 0x80063D9C: mflo        $t1
    ctx->r9 = lo;
    // 0x80063DA0: sll         $v1, $t1, 1
    ctx->r3 = S32(ctx->r9 << 1);
    // 0x80063DA4: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80063DA8: sw          $v0, 0xC($s1)
    MEM_W(0XC, ctx->r17) = ctx->r2;
    // 0x80063DAC: sll         $v0, $s3, 16
    ctx->r2 = S32(ctx->r19 << 16);
    // 0x80063DB0: lhu         $a2, 0xE8($s0)
    ctx->r6 = MEM_HU(ctx->r16, 0XE8);
    // 0x80063DB4: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x80063DB8: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // 0x80063DBC: sll         $v0, $s4, 16
    ctx->r2 = S32(ctx->r20 << 16);
    // 0x80063DC0: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x80063DC4: jal         0x80062108
    // 0x80063DC8: sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    func_80062108(rdram, ctx);
        goto after_0;
    // 0x80063DC8: sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    after_0:
    // 0x80063DCC: lw          $a0, 0xF4($s0)
    ctx->r4 = MEM_W(ctx->r16, 0XF4);
    // 0x80063DD0: beq         $a0, $zero, L_80063DE8
    if (ctx->r4 == 0) {
        // 0x80063DD4: nop
    
            goto L_80063DE8;
    }
    // 0x80063DD4: nop

    // 0x80063DD8: lhu         $a2, 0x8($s1)
    ctx->r6 = MEM_HU(ctx->r17, 0X8);
    // 0x80063DDC: lw          $a1, 0x34($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X34);
    // 0x80063DE0: jal         0x800646AC
    // 0x80063DE4: sltu        $a2, $zero, $a2
    ctx->r6 = 0 < ctx->r6 ? 1 : 0;
    func_800646AC(rdram, ctx);
        goto after_1;
    // 0x80063DE4: sltu        $a2, $zero, $a2
    ctx->r6 = 0 < ctx->r6 ? 1 : 0;
    after_1:
L_80063DE8:
    // 0x80063DE8: lbu         $v0, 0x1F($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X1F);
    // 0x80063DEC: bne         $v0, $zero, L_80063E00
    if (ctx->r2 != 0) {
        // 0x80063DF0: nop
    
            goto L_80063E00;
    }
    // 0x80063DF0: nop

    // 0x80063DF4: lw          $v0, 0x14($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X14);
    // 0x80063DF8: ori         $v0, $v0, 0x1
    ctx->r2 = ctx->r2 | 0X1;
    // 0x80063DFC: sw          $v0, 0x14($s1)
    MEM_W(0X14, ctx->r17) = ctx->r2;
L_80063E00:
    // 0x80063E00: lw          $v0, 0x34($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X34);
    // 0x80063E04: sh          $s3, 0x98($s2)
    MEM_H(0X98, ctx->r18) = ctx->r19;
    // 0x80063E08: sh          $s4, 0x9A($s2)
    MEM_H(0X9A, ctx->r18) = ctx->r20;
    // 0x80063E0C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80063E10: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x80063E14: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x80063E18: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80063E1C: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80063E20: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80063E24: jr          $ra
    // 0x80063E28: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x80063E28: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_80063E2C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80063E2C: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x80063E30: sb          $a0, -0x66A0($v0)
    MEM_B(-0X66A0, ctx->r2) = ctx->r4;
    // 0x80063E34: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x80063E38: sh          $a1, -0x669E($v0)
    MEM_H(-0X669E, ctx->r2) = ctx->r5;
    // 0x80063E3C: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x80063E40: jr          $ra
    // 0x80063E44: sh          $a2, -0x669C($v0)
    MEM_H(-0X669C, ctx->r2) = ctx->r6;
    return;
    // 0x80063E44: sh          $a2, -0x669C($v0)
    MEM_H(-0X669C, ctx->r2) = ctx->r6;
;}
RECOMP_FUNC void func_80063E48(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80063E48: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x80063E4C: jr          $ra
    // 0x80063E50: sw          $a0, -0x6698($v0)
    MEM_W(-0X6698, ctx->r2) = ctx->r4;
    return;
    // 0x80063E50: sw          $a0, -0x6698($v0)
    MEM_W(-0X6698, ctx->r2) = ctx->r4;
;}
RECOMP_FUNC void func_80063E54(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80063E54: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x80063E58: addiu       $v0, $v0, -0x3F0
    ctx->r2 = ADD32(ctx->r2, -0X3F0);
    // 0x80063E5C: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    // 0x80063E60: sll         $a0, $a0, 2
    ctx->r4 = S32(ctx->r4 << 2);
    // 0x80063E64: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // 0x80063E68: andi        $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 & 0XFFFF;
    // 0x80063E6C: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x80063E70: sll         $a1, $a1, 2
    ctx->r5 = S32(ctx->r5 << 2);
    // 0x80063E74: addu        $v0, $v0, $a1
    ctx->r2 = ADD32(ctx->r2, ctx->r5);
    // 0x80063E78: lw          $v1, 0x34($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X34);
    // 0x80063E7C: lbu         $v0, 0x0($a2)
    ctx->r2 = MEM_BU(ctx->r6, 0X0);
    // 0x80063E80: sb          $v0, 0x2C($v1)
    MEM_B(0X2C, ctx->r3) = ctx->r2;
    // 0x80063E84: lbu         $v0, 0x1($a2)
    ctx->r2 = MEM_BU(ctx->r6, 0X1);
    // 0x80063E88: sb          $v0, 0x2D($v1)
    MEM_B(0X2D, ctx->r3) = ctx->r2;
    // 0x80063E8C: lbu         $v0, 0x2($a2)
    ctx->r2 = MEM_BU(ctx->r6, 0X2);
    // 0x80063E90: jr          $ra
    // 0x80063E94: sb          $v0, 0x2E($v1)
    MEM_B(0X2E, ctx->r3) = ctx->r2;
    return;
    // 0x80063E94: sb          $v0, 0x2E($v1)
    MEM_B(0X2E, ctx->r3) = ctx->r2;
;}
RECOMP_FUNC void func_80063E98(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80063E98: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x80063E9C: addiu       $v0, $v0, -0x3F0
    ctx->r2 = ADD32(ctx->r2, -0X3F0);
    // 0x80063EA0: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    // 0x80063EA4: sll         $a0, $a0, 2
    ctx->r4 = S32(ctx->r4 << 2);
    // 0x80063EA8: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // 0x80063EAC: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x80063EB0: andi        $a2, $a2, 0xFF
    ctx->r6 = ctx->r6 & 0XFF;
    // 0x80063EB4: sw          $a1, 0xFC($v0)
    MEM_W(0XFC, ctx->r2) = ctx->r5;
    // 0x80063EB8: jr          $ra
    // 0x80063EBC: sh          $a2, 0x100($v0)
    MEM_H(0X100, ctx->r2) = ctx->r6;
    return;
    // 0x80063EBC: sh          $a2, 0x100($v0)
    MEM_H(0X100, ctx->r2) = ctx->r6;
;}
RECOMP_FUNC void func_80063EC0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80063EC0: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x80063EC4: addiu       $v0, $v0, -0x3F0
    ctx->r2 = ADD32(ctx->r2, -0X3F0);
    // 0x80063EC8: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    // 0x80063ECC: sll         $a0, $a0, 2
    ctx->r4 = S32(ctx->r4 << 2);
    // 0x80063ED0: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // 0x80063ED4: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x80063ED8: sw          $zero, 0xFC($v0)
    MEM_W(0XFC, ctx->r2) = 0;
    // 0x80063EDC: jr          $ra
    // 0x80063EE0: sh          $zero, 0x100($v0)
    MEM_H(0X100, ctx->r2) = 0;
    return;
    // 0x80063EE0: sh          $zero, 0x100($v0)
    MEM_H(0X100, ctx->r2) = 0;
;}
RECOMP_FUNC void func_80063EE4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80063EE4: lb          $v0, 0x1($a0)
    ctx->r2 = MEM_B(ctx->r4, 0X1);
    // 0x80063EE8: jr          $ra
    // 0x80063EEC: sltu        $v0, $zero, $v0
    ctx->r2 = 0 < ctx->r2 ? 1 : 0;
    return;
    // 0x80063EEC: sltu        $v0, $zero, $v0
    ctx->r2 = 0 < ctx->r2 ? 1 : 0;
;}
RECOMP_FUNC void func_80063EF0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80063EF0: lui         $a1, 0x800A
    ctx->r5 = S32(0X800A << 16);
    // 0x80063EF4: addiu       $a1, $a1, -0x3F0
    ctx->r5 = ADD32(ctx->r5, -0X3F0);
    // 0x80063EF8: lbu         $v0, 0x8($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X8);
    // 0x80063EFC: lbu         $v1, 0x0($a0)
    ctx->r3 = MEM_BU(ctx->r4, 0X0);
    // 0x80063F00: lbu         $a0, 0x9($a0)
    ctx->r4 = MEM_BU(ctx->r4, 0X9);
    // 0x80063F04: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80063F08: addu        $v0, $v0, $a1
    ctx->r2 = ADD32(ctx->r2, ctx->r5);
    // 0x80063F0C: addu        $v1, $v1, $a0
    ctx->r3 = ADD32(ctx->r3, ctx->r4);
    // 0x80063F10: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x80063F14: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x80063F18: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80063F1C: lw          $v0, 0x34($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X34);
    // 0x80063F20: jr          $ra
    // 0x80063F24: nop

    return;
    // 0x80063F24: nop

;}
RECOMP_FUNC void func_80063F28(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80063F28: lui         $a1, 0x800A
    ctx->r5 = S32(0X800A << 16);
    // 0x80063F2C: addiu       $a1, $a1, -0x3F0
    ctx->r5 = ADD32(ctx->r5, -0X3F0);
    // 0x80063F30: lbu         $v0, 0x0($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X0);
    // 0x80063F34: lbu         $v1, 0x9($a0)
    ctx->r3 = MEM_BU(ctx->r4, 0X9);
    // 0x80063F38: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x80063F3C: subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // 0x80063F40: lbu         $v0, 0x8($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X8);
    // 0x80063F44: andi        $v1, $v1, 0xFFFF
    ctx->r3 = ctx->r3 & 0XFFFF;
    // 0x80063F48: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80063F4C: addu        $v0, $v0, $a1
    ctx->r2 = ADD32(ctx->r2, ctx->r5);
    // 0x80063F50: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x80063F54: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x80063F58: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80063F5C: lw          $v0, 0x34($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X34);
    // 0x80063F60: jr          $ra
    // 0x80063F64: nop

    return;
    // 0x80063F64: nop

;}
RECOMP_FUNC void func_80063F68(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80063F68: jr          $ra
    // 0x80063F6C: addu        $v0, $a0, $zero
    ctx->r2 = ADD32(ctx->r4, 0);
    return;
    // 0x80063F6C: addu        $v0, $a0, $zero
    ctx->r2 = ADD32(ctx->r4, 0);
;}
RECOMP_FUNC void func_80063F70(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80063F70: lw          $v0, 0x44C($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X44C);
    // 0x80063F74: jr          $ra
    // 0x80063F78: nop

    return;
    // 0x80063F78: nop

;}
RECOMP_FUNC void func_80063F7C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80063F7C: lbu         $v0, 0x454($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X454);
    // 0x80063F80: bne         $v0, $zero, L_80063F94
    if (ctx->r2 != 0) {
        // 0x80063F84: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80063F94;
    }
    // 0x80063F84: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80063F88: sb          $zero, 0x456($a0)
    MEM_B(0X456, ctx->r4) = 0;
    // 0x80063F8C: sb          $v0, 0x454($a0)
    MEM_B(0X454, ctx->r4) = ctx->r2;
    // 0x80063F90: sw          $zero, 0x30($a0)
    MEM_W(0X30, ctx->r4) = 0;
L_80063F94:
    // 0x80063F94: jr          $ra
    // 0x80063F98: nop

    return;
    // 0x80063F98: nop

;}
RECOMP_FUNC void func_80063F9C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80063F9C: lui         $v1, 0xFF00
    ctx->r3 = S32(0XFF00 << 16);
    // 0x80063FA0: lw          $v0, 0x454($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X454);
    // 0x80063FA4: ori         $v1, $v1, 0xFF00
    ctx->r3 = ctx->r3 | 0XFF00;
    // 0x80063FA8: and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // 0x80063FAC: jr          $ra
    // 0x80063FB0: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
    return;
    // 0x80063FB0: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
;}
RECOMP_FUNC void func_80063FB4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80063FB4: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x80063FB8: addiu       $v0, $v0, -0x3F0
    ctx->r2 = ADD32(ctx->r2, -0X3F0);
    // 0x80063FBC: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    // 0x80063FC0: sll         $a0, $a0, 2
    ctx->r4 = S32(ctx->r4 << 2);
    // 0x80063FC4: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // 0x80063FC8: lw          $a0, 0x0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X0);
    // 0x80063FCC: lhu         $v0, 0x0($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X0);
    // 0x80063FD0: beq         $v0, $zero, L_80064020
    if (ctx->r2 == 0) {
        // 0x80063FD4: addu        $v1, $zero, $zero
        ctx->r3 = ADD32(0, 0);
            goto L_80064020;
    }
    // 0x80063FD4: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
    // 0x80063FD8: lw          $t0, 0xC($a0)
    ctx->r8 = MEM_W(ctx->r4, 0XC);
    // 0x80063FDC: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    // 0x80063FE0: addu        $a3, $v0, $zero
    ctx->r7 = ADD32(ctx->r2, 0);
    // 0x80063FE4: andi        $a2, $v1, 0xFFFF
    ctx->r6 = ctx->r3 & 0XFFFF;
L_80063FE8:
    // 0x80063FE8: addu        $v0, $t0, $a2
    ctx->r2 = ADD32(ctx->r8, ctx->r6);
    // 0x80063FEC: lbu         $v0, 0x0($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X0);
    // 0x80063FF0: bne         $v0, $a1, L_80064010
    if (ctx->r2 != ctx->r5) {
        // 0x80063FF4: addiu       $v1, $v1, 0x1
        ctx->r3 = ADD32(ctx->r3, 0X1);
            goto L_80064010;
    }
    // 0x80063FF4: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80063FF8: lw          $v1, 0x28($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X28);
    // 0x80063FFC: sll         $v0, $a2, 1
    ctx->r2 = S32(ctx->r6 << 1);
    // 0x80064000: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80064004: lhu         $v0, 0x0($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X0);
    // 0x80064008: jr          $ra
    // 0x8006400C: nop

    return;
    // 0x8006400C: nop

L_80064010:
    // 0x80064010: andi        $v0, $v1, 0xFFFF
    ctx->r2 = ctx->r3 & 0XFFFF;
    // 0x80064014: sltu        $v0, $v0, $a3
    ctx->r2 = ctx->r2 < ctx->r7 ? 1 : 0;
    // 0x80064018: bne         $v0, $zero, L_80063FE8
    if (ctx->r2 != 0) {
        // 0x8006401C: andi        $a2, $v1, 0xFFFF
        ctx->r6 = ctx->r3 & 0XFFFF;
            goto L_80063FE8;
    }
    // 0x8006401C: andi        $a2, $v1, 0xFFFF
    ctx->r6 = ctx->r3 & 0XFFFF;
L_80064020:
    // 0x80064020: jr          $ra
    // 0x80064024: ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
    return;
    // 0x80064024: ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
;}
RECOMP_FUNC void func_80064028(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80064028: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x8006402C: addiu       $v0, $v0, -0x3F0
    ctx->r2 = ADD32(ctx->r2, -0X3F0);
    // 0x80064030: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    // 0x80064034: sll         $a0, $a0, 2
    ctx->r4 = S32(ctx->r4 << 2);
    // 0x80064038: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // 0x8006403C: lw          $a0, 0x0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X0);
    // 0x80064040: lhu         $v0, 0x0($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X0);
    // 0x80064044: beq         $v0, $zero, L_80064094
    if (ctx->r2 == 0) {
        // 0x80064048: addu        $v1, $zero, $zero
        ctx->r3 = ADD32(0, 0);
            goto L_80064094;
    }
    // 0x80064048: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
    // 0x8006404C: lw          $t1, 0xC($a0)
    ctx->r9 = MEM_W(ctx->r4, 0XC);
    // 0x80064050: andi        $t0, $a1, 0xFF
    ctx->r8 = ctx->r5 & 0XFF;
    // 0x80064054: addu        $a3, $v0, $zero
    ctx->r7 = ADD32(ctx->r2, 0);
    // 0x80064058: andi        $a2, $v1, 0xFFFF
    ctx->r6 = ctx->r3 & 0XFFFF;
L_8006405C:
    // 0x8006405C: addu        $v0, $t1, $a2
    ctx->r2 = ADD32(ctx->r9, ctx->r6);
    // 0x80064060: lbu         $v0, 0x0($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X0);
    // 0x80064064: bne         $v0, $t0, L_80064084
    if (ctx->r2 != ctx->r8) {
        // 0x80064068: addiu       $v1, $v1, 0x1
        ctx->r3 = ADD32(ctx->r3, 0X1);
            goto L_80064084;
    }
    // 0x80064068: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8006406C: lw          $v1, 0x24($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X24);
    // 0x80064070: sll         $v0, $a2, 1
    ctx->r2 = S32(ctx->r6 << 1);
    // 0x80064074: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80064078: lhu         $v0, 0x0($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X0);
    // 0x8006407C: jr          $ra
    // 0x80064080: nop

    return;
    // 0x80064080: nop

L_80064084:
    // 0x80064084: andi        $v0, $v1, 0xFFFF
    ctx->r2 = ctx->r3 & 0XFFFF;
    // 0x80064088: sltu        $v0, $v0, $a3
    ctx->r2 = ctx->r2 < ctx->r7 ? 1 : 0;
    // 0x8006408C: bne         $v0, $zero, L_8006405C
    if (ctx->r2 != 0) {
        // 0x80064090: andi        $a2, $v1, 0xFFFF
        ctx->r6 = ctx->r3 & 0XFFFF;
            goto L_8006405C;
    }
    // 0x80064090: andi        $a2, $v1, 0xFFFF
    ctx->r6 = ctx->r3 & 0XFFFF;
L_80064094:
    // 0x80064094: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
    // 0x80064098: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    // 0x8006409C: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x800640A0: addiu       $a0, $v0, -0x6680
    ctx->r4 = ADD32(ctx->r2, -0X6680);
    // 0x800640A4: addiu       $v0, $v1, 0x1
    ctx->r2 = ADD32(ctx->r3, 0X1);
L_800640A8:
    // 0x800640A8: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x800640AC: bnel        $a1, $v0, L_800640CC
    if (ctx->r5 != ctx->r2) {
        // 0x800640B0: addiu       $v1, $v1, 0x1
        ctx->r3 = ADD32(ctx->r3, 0X1);
            goto L_800640CC;
    }
    goto skip_0;
    // 0x800640B0: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    skip_0:
    // 0x800640B4: andi        $v0, $v1, 0xFFFF
    ctx->r2 = ctx->r3 & 0XFFFF;
    // 0x800640B8: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x800640BC: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x800640C0: lhu         $v0, 0x0($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X0);
    // 0x800640C4: jr          $ra
    // 0x800640C8: nop

    return;
    // 0x800640C8: nop

L_800640CC:
    // 0x800640CC: andi        $v0, $v1, 0xFFFF
    ctx->r2 = ctx->r3 & 0XFFFF;
    // 0x800640D0: sltiu       $v0, $v0, 0x6
    ctx->r2 = ctx->r2 < 0X6 ? 1 : 0;
    // 0x800640D4: bne         $v0, $zero, L_800640A8
    if (ctx->r2 != 0) {
        // 0x800640D8: addiu       $v0, $v1, 0x1
        ctx->r2 = ADD32(ctx->r3, 0X1);
            goto L_800640A8;
    }
    // 0x800640D8: addiu       $v0, $v1, 0x1
    ctx->r2 = ADD32(ctx->r3, 0X1);
    // 0x800640DC: jr          $ra
    // 0x800640E0: ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
    return;
    // 0x800640E0: ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
;}
RECOMP_FUNC void func_800640E4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800640E4: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x800640E8: addiu       $v0, $v0, -0x3F0
    ctx->r2 = ADD32(ctx->r2, -0X3F0);
    // 0x800640EC: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    // 0x800640F0: sll         $a0, $a0, 2
    ctx->r4 = S32(ctx->r4 << 2);
    // 0x800640F4: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // 0x800640F8: lw          $a0, 0x0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X0);
    // 0x800640FC: lhu         $v0, 0x0($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X0);
    // 0x80064100: beq         $v0, $zero, L_8006414C
    if (ctx->r2 == 0) {
        // 0x80064104: addu        $v1, $zero, $zero
        ctx->r3 = ADD32(0, 0);
            goto L_8006414C;
    }
    // 0x80064104: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
    // 0x80064108: lw          $t0, 0xC($a0)
    ctx->r8 = MEM_W(ctx->r4, 0XC);
    // 0x8006410C: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    // 0x80064110: addu        $a3, $v0, $zero
    ctx->r7 = ADD32(ctx->r2, 0);
    // 0x80064114: andi        $a2, $v1, 0xFFFF
    ctx->r6 = ctx->r3 & 0XFFFF;
L_80064118:
    // 0x80064118: addu        $v0, $t0, $a2
    ctx->r2 = ADD32(ctx->r8, ctx->r6);
    // 0x8006411C: lbu         $v0, 0x0($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X0);
    // 0x80064120: bne         $v0, $a1, L_8006413C
    if (ctx->r2 != ctx->r5) {
        // 0x80064124: addiu       $v1, $v1, 0x1
        ctx->r3 = ADD32(ctx->r3, 0X1);
            goto L_8006413C;
    }
    // 0x80064124: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80064128: lw          $v0, 0x18($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X18);
    // 0x8006412C: addu        $v0, $v0, $a2
    ctx->r2 = ADD32(ctx->r2, ctx->r6);
    // 0x80064130: lbu         $v0, 0x0($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X0);
    // 0x80064134: jr          $ra
    // 0x80064138: nop

    return;
    // 0x80064138: nop

L_8006413C:
    // 0x8006413C: andi        $v0, $v1, 0xFFFF
    ctx->r2 = ctx->r3 & 0XFFFF;
    // 0x80064140: sltu        $v0, $v0, $a3
    ctx->r2 = ctx->r2 < ctx->r7 ? 1 : 0;
    // 0x80064144: bne         $v0, $zero, L_80064118
    if (ctx->r2 != 0) {
        // 0x80064148: andi        $a2, $v1, 0xFFFF
        ctx->r6 = ctx->r3 & 0XFFFF;
            goto L_80064118;
    }
    // 0x80064148: andi        $a2, $v1, 0xFFFF
    ctx->r6 = ctx->r3 & 0XFFFF;
L_8006414C:
    // 0x8006414C: jr          $ra
    // 0x80064150: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    return;
    // 0x80064150: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
;}
RECOMP_FUNC void func_80064154(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80064154: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x80064158: addiu       $v0, $v0, -0x3F0
    ctx->r2 = ADD32(ctx->r2, -0X3F0);
    // 0x8006415C: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    // 0x80064160: sll         $a0, $a0, 2
    ctx->r4 = S32(ctx->r4 << 2);
    // 0x80064164: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // 0x80064168: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8006416C: lh          $v0, 0x6($v0)
    ctx->r2 = MEM_H(ctx->r2, 0X6);
    // 0x80064170: jr          $ra
    // 0x80064174: nop

    return;
    // 0x80064174: nop

;}
RECOMP_FUNC void func_80064178(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80064178: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x8006417C: addiu       $v0, $v0, -0x3F0
    ctx->r2 = ADD32(ctx->r2, -0X3F0);
    // 0x80064180: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    // 0x80064184: sll         $a0, $a0, 2
    ctx->r4 = S32(ctx->r4 << 2);
    // 0x80064188: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // 0x8006418C: andi        $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 & 0XFFFF;
    // 0x80064190: lw          $a2, 0x0($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X0);
    // 0x80064194: sll         $a1, $a1, 2
    ctx->r5 = S32(ctx->r5 << 2);
    // 0x80064198: addu        $a1, $a2, $a1
    ctx->r5 = ADD32(ctx->r6, ctx->r5);
    // 0x8006419C: lw          $a1, 0x34($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X34);
    // 0x800641A0: lhu         $v0, 0x8($a1)
    ctx->r2 = MEM_HU(ctx->r5, 0X8);
    // 0x800641A4: lw          $a0, 0x10($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X10);
    // 0x800641A8: lwc1        $f2, 0x28($a1)
    ctx->f2.u32l = MEM_W(ctx->r5, 0X28);
    // 0x800641AC: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800641B0: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x800641B4: lhu         $v1, -0x2($v0)
    ctx->r3 = MEM_HU(ctx->r2, -0X2);
    // 0x800641B8: lhu         $a0, 0x2($a0)
    ctx->r4 = MEM_HU(ctx->r4, 0X2);
    // 0x800641BC: lhu         $v0, 0x6($a2)
    ctx->r2 = MEM_HU(ctx->r6, 0X6);
    // 0x800641C0: subu        $v1, $v1, $a0
    ctx->r3 = SUB32(ctx->r3, ctx->r4);
    // 0x800641C4: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800641C8: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x800641CC: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x800641D0: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x800641D4: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x800641D8: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x800641DC: trunc.w.s   $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    ctx->f4.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800641E0: mfc1        $v0, $f4
    ctx->r2 = (int32_t)ctx->f4.u32l;
    // 0x800641E4: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x800641E8: jr          $ra
    // 0x800641EC: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    return;
    // 0x800641EC: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
;}
RECOMP_FUNC void func_800641F0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800641F0: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x800641F4: addiu       $v0, $v0, -0x3F0
    ctx->r2 = ADD32(ctx->r2, -0X3F0);
    // 0x800641F8: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    // 0x800641FC: sll         $a0, $a0, 2
    ctx->r4 = S32(ctx->r4 << 2);
    // 0x80064200: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // 0x80064204: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x80064208: lhu         $v0, 0x4($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X4);
    // 0x8006420C: lhu         $v1, 0xA($v1)
    ctx->r3 = MEM_HU(ctx->r3, 0XA);
    // 0x80064210: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80064214: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x80064218: jr          $ra
    // 0x8006421C: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    return;
    // 0x8006421C: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
;}
RECOMP_FUNC void func_80064220(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80064220: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x80064224: addiu       $v0, $v0, -0x3F0
    ctx->r2 = ADD32(ctx->r2, -0X3F0);
    // 0x80064228: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    // 0x8006422C: sll         $a0, $a0, 2
    ctx->r4 = S32(ctx->r4 << 2);
    // 0x80064230: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // 0x80064234: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    // 0x80064238: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8006423C: sltiu       $a1, $a1, 0x1
    ctx->r5 = ctx->r5 < 0X1 ? 1 : 0;
    // 0x80064240: jr          $ra
    // 0x80064244: sb          $a1, 0x102($v0)
    MEM_B(0X102, ctx->r2) = ctx->r5;
    return;
    // 0x80064244: sb          $a1, 0x102($v0)
    MEM_B(0X102, ctx->r2) = ctx->r5;
;}
RECOMP_FUNC void func_80064248(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80064248: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x8006424C: lbu         $v0, -0x66A0($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X66A0);
    // 0x80064250: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80064254: andi        $v0, $v0, 0x8
    ctx->r2 = ctx->r2 & 0X8;
    // 0x80064258: beq         $v0, $zero, L_8006427C
    if (ctx->r2 == 0) {
        // 0x8006425C: sw          $ra, 0x10($sp)
        MEM_W(0X10, ctx->r29) = ctx->r31;
            goto L_8006427C;
    }
    // 0x8006425C: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x80064260: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x80064264: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x80064268: lw          $v0, -0x6698($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X6698);
    // 0x8006426C: jalr        $v0
    // 0x80064270: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_0;
    // 0x80064270: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    after_0:
    // 0x80064274: j           L_80064284
    // 0x80064278: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
        goto L_80064284;
    // 0x80064278: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
L_8006427C:
    // 0x8006427C: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // 0x80064280: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
L_80064284:
    // 0x80064284: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x80064288: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x8006428C: jr          $ra
    // 0x80064290: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80064290: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void fake_func_80064294(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
;}
RECOMP_FUNC void func_800642A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800642A0: addu        $t2, $a0, $zero
    ctx->r10 = ADD32(ctx->r4, 0);
    // 0x800642A4: lhu         $v0, 0x4($t2)
    ctx->r2 = MEM_HU(ctx->r10, 0X4);
    // 0x800642A8: beq         $v0, $zero, L_800642E4
    if (ctx->r2 == 0) {
        // 0x800642AC: addu        $t0, $zero, $zero
        ctx->r8 = ADD32(0, 0);
            goto L_800642E4;
    }
    // 0x800642AC: addu        $t0, $zero, $zero
    ctx->r8 = ADD32(0, 0);
    // 0x800642B0: lw          $a0, 0x0($t2)
    ctx->r4 = MEM_W(ctx->r10, 0X0);
    // 0x800642B4: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // 0x800642B8: andi        $v0, $t0, 0xFF
    ctx->r2 = ctx->r8 & 0XFF;
L_800642BC:
    // 0x800642BC: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x800642C0: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x800642C4: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x800642C8: beq         $v0, $a1, L_800643BC
    if (ctx->r2 == ctx->r5) {
        // 0x800642CC: addiu       $t0, $t0, 0x1
        ctx->r8 = ADD32(ctx->r8, 0X1);
            goto L_800643BC;
    }
    // 0x800642CC: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    // 0x800642D0: andi        $v0, $t0, 0xFF
    ctx->r2 = ctx->r8 & 0XFF;
    // 0x800642D4: sltu        $v0, $v0, $v1
    ctx->r2 = ctx->r2 < ctx->r3 ? 1 : 0;
    // 0x800642D8: bne         $v0, $zero, L_800642BC
    if (ctx->r2 != 0) {
        // 0x800642DC: andi        $v0, $t0, 0xFF
        ctx->r2 = ctx->r8 & 0XFF;
            goto L_800642BC;
    }
    // 0x800642DC: andi        $v0, $t0, 0xFF
    ctx->r2 = ctx->r8 & 0XFF;
    // 0x800642E0: lhu         $v0, 0x4($t2)
    ctx->r2 = MEM_HU(ctx->r10, 0X4);
L_800642E4:
    // 0x800642E4: beq         $v0, $zero, L_80064328
    if (ctx->r2 == 0) {
        // 0x800642E8: addu        $t0, $zero, $zero
        ctx->r8 = ADD32(0, 0);
            goto L_80064328;
    }
    // 0x800642E8: addu        $t0, $zero, $zero
    ctx->r8 = ADD32(0, 0);
    // 0x800642EC: lw          $a3, 0x0($t2)
    ctx->r7 = MEM_W(ctx->r10, 0X0);
    // 0x800642F0: andi        $a0, $a2, 0xFF
    ctx->r4 = ctx->r6 & 0XFF;
    // 0x800642F4: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // 0x800642F8: andi        $v0, $t0, 0xFF
    ctx->r2 = ctx->r8 & 0XFF;
L_800642FC:
    // 0x800642FC: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x80064300: addu        $v0, $v0, $a3
    ctx->r2 = ADD32(ctx->r2, ctx->r7);
    // 0x80064304: lbu         $v0, 0x4($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X4);
    // 0x80064308: sltu        $v0, $v0, $a0
    ctx->r2 = ctx->r2 < ctx->r4 ? 1 : 0;
    // 0x8006430C: beq         $v0, $zero, L_80064328
    if (ctx->r2 == 0) {
        // 0x80064310: nop
    
            goto L_80064328;
    }
    // 0x80064310: nop

    // 0x80064314: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    // 0x80064318: andi        $v0, $t0, 0xFF
    ctx->r2 = ctx->r8 & 0XFF;
    // 0x8006431C: sltu        $v0, $v0, $v1
    ctx->r2 = ctx->r2 < ctx->r3 ? 1 : 0;
    // 0x80064320: bne         $v0, $zero, L_800642FC
    if (ctx->r2 != 0) {
        // 0x80064324: andi        $v0, $t0, 0xFF
        ctx->r2 = ctx->r8 & 0XFF;
            goto L_800642FC;
    }
    // 0x80064324: andi        $v0, $t0, 0xFF
    ctx->r2 = ctx->r8 & 0XFF;
L_80064328:
    // 0x80064328: lbu         $t1, 0x5($t2)
    ctx->r9 = MEM_BU(ctx->r10, 0X5);
    // 0x8006432C: andi        $t3, $t0, 0xFF
    ctx->r11 = ctx->r8 & 0XFF;
    // 0x80064330: andi        $a3, $t1, 0xFF
    ctx->r7 = ctx->r9 & 0XFF;
    // 0x80064334: sltu        $v0, $t3, $a3
    ctx->r2 = ctx->r11 < ctx->r7 ? 1 : 0;
    // 0x80064338: beq         $v0, $zero, L_80064388
    if (ctx->r2 == 0) {
        // 0x8006433C: andi        $v1, $t0, 0xFF
        ctx->r3 = ctx->r8 & 0XFF;
            goto L_80064388;
    }
    // 0x8006433C: andi        $v1, $t0, 0xFF
    ctx->r3 = ctx->r8 & 0XFF;
L_80064340:
    // 0x80064340: lw          $v1, 0x0($t2)
    ctx->r3 = MEM_W(ctx->r10, 0X0);
    // 0x80064344: sll         $a0, $a3, 3
    ctx->r4 = S32(ctx->r7 << 3);
    // 0x80064348: addu        $v1, $a0, $v1
    ctx->r3 = ADD32(ctx->r4, ctx->r3);
    // 0x8006434C: lw          $v0, -0x8($v1)
    ctx->r2 = MEM_W(ctx->r3, -0X8);
    // 0x80064350: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x80064354: lw          $v0, 0x0($t2)
    ctx->r2 = MEM_W(ctx->r10, 0X0);
    // 0x80064358: addu        $v0, $a0, $v0
    ctx->r2 = ADD32(ctx->r4, ctx->r2);
    // 0x8006435C: lbu         $v1, -0x4($v0)
    ctx->r3 = MEM_BU(ctx->r2, -0X4);
    // 0x80064360: sb          $v1, 0x4($v0)
    MEM_B(0X4, ctx->r2) = ctx->r3;
    // 0x80064364: lw          $v0, 0x0($t2)
    ctx->r2 = MEM_W(ctx->r10, 0X0);
    // 0x80064368: addiu       $t1, $t1, -0x1
    ctx->r9 = ADD32(ctx->r9, -0X1);
    // 0x8006436C: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // 0x80064370: lbu         $v0, -0x3($a0)
    ctx->r2 = MEM_BU(ctx->r4, -0X3);
    // 0x80064374: andi        $a3, $t1, 0xFF
    ctx->r7 = ctx->r9 & 0XFF;
    // 0x80064378: sb          $v0, 0x5($a0)
    MEM_B(0X5, ctx->r4) = ctx->r2;
    // 0x8006437C: sltu        $v0, $t3, $a3
    ctx->r2 = ctx->r11 < ctx->r7 ? 1 : 0;
    // 0x80064380: bne         $v0, $zero, L_80064340
    if (ctx->r2 != 0) {
        // 0x80064384: andi        $v1, $t0, 0xFF
        ctx->r3 = ctx->r8 & 0XFF;
            goto L_80064340;
    }
    // 0x80064384: andi        $v1, $t0, 0xFF
    ctx->r3 = ctx->r8 & 0XFF;
L_80064388:
    // 0x80064388: lw          $v0, 0x0($t2)
    ctx->r2 = MEM_W(ctx->r10, 0X0);
    // 0x8006438C: sll         $v1, $v1, 3
    ctx->r3 = S32(ctx->r3 << 3);
    // 0x80064390: addu        $v0, $v1, $v0
    ctx->r2 = ADD32(ctx->r3, ctx->r2);
    // 0x80064394: sw          $a1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r5;
    // 0x80064398: lw          $v0, 0x0($t2)
    ctx->r2 = MEM_W(ctx->r10, 0X0);
    // 0x8006439C: addu        $v0, $v1, $v0
    ctx->r2 = ADD32(ctx->r3, ctx->r2);
    // 0x800643A0: sb          $a2, 0x4($v0)
    MEM_B(0X4, ctx->r2) = ctx->r6;
    // 0x800643A4: lw          $v0, 0x0($t2)
    ctx->r2 = MEM_W(ctx->r10, 0X0);
    // 0x800643A8: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x800643AC: sb          $zero, 0x5($v1)
    MEM_B(0X5, ctx->r3) = 0;
    // 0x800643B0: lhu         $v0, 0x4($t2)
    ctx->r2 = MEM_HU(ctx->r10, 0X4);
    // 0x800643B4: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800643B8: sh          $v0, 0x4($t2)
    MEM_H(0X4, ctx->r10) = ctx->r2;
L_800643BC:
    // 0x800643BC: jr          $ra
    // 0x800643C0: nop

    return;
    // 0x800643C0: nop

;}
