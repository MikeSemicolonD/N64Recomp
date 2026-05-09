#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void func_800AFE4C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AFE4C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800AFE50: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x800AFE54: addu        $s1, $a0, $zero
    ctx->r17 = ADD32(ctx->r4, 0);
    // 0x800AFE58: addu        $a0, $a1, $zero
    ctx->r4 = ADD32(ctx->r5, 0);
    // 0x800AFE5C: sw          $ra, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r31;
    // 0x800AFE60: beq         $a0, $zero, L_800AFE78
    if (ctx->r4 == 0) {
        // 0x800AFE64: sw          $s0, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r16;
            goto L_800AFE78;
    }
    // 0x800AFE64: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x800AFE68: jal         0x800AFCF4
    // 0x800AFE6C: nop

    func_800AFCF4(rdram, ctx);
        goto after_0;
    // 0x800AFE6C: nop

    after_0:
    // 0x800AFE70: bne         $v0, $zero, L_800B0030
    if (ctx->r2 != 0) {
        // 0x800AFE74: nop
    
            goto L_800B0030;
    }
    // 0x800AFE74: nop

L_800AFE78:
    // 0x800AFE78: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x800AFE7C: jal         0x80047B48
    // 0x800AFE80: addiu       $a0, $a0, 0x558C
    ctx->r4 = ADD32(ctx->r4, 0X558C);
    getLevelDatItemByName(rdram, ctx);
        goto after_1;
    // 0x800AFE80: addiu       $a0, $a0, 0x558C
    ctx->r4 = ADD32(ctx->r4, 0X558C);
    after_1:
    // 0x800AFE84: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // 0x800AFE88: beq         $a0, $zero, L_800AFF54
    if (ctx->r4 == 0) {
        // 0x800AFE8C: lui         $v1, 0x8013
        ctx->r3 = S32(0X8013 << 16);
            goto L_800AFF54;
    }
    // 0x800AFE8C: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x800AFE90: lwc1        $f0, 0x10($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X10);
    // 0x800AFE94: swc1        $f0, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->f0.u32l;
    // 0x800AFE98: lwc1        $f0, 0x14($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X14);
    // 0x800AFE9C: swc1        $f0, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->f0.u32l;
    // 0x800AFEA0: lwc1        $f0, 0x18($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X18);
    // 0x800AFEA4: addiu       $v1, $v1, 0x6DC0
    ctx->r3 = ADD32(ctx->r3, 0X6DC0);
    // 0x800AFEA8: swc1        $f0, 0xC($s1)
    MEM_W(0XC, ctx->r17) = ctx->f0.u32l;
    // 0x800AFEAC: lw          $t0, 0x1C($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X1C);
    // 0x800AFEB0: lw          $t1, 0x20($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X20);
    // 0x800AFEB4: lw          $t2, 0x24($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X24);
    // 0x800AFEB8: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x800AFEBC: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    // 0x800AFEC0: sw          $t2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r10;
    // 0x800AFEC4: lwc1        $f2, 0x20($v1)
    ctx->f2.u32l = MEM_W(ctx->r3, 0X20);
    // 0x800AFEC8: lwc1        $f0, 0x8C($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X8C);
    // 0x800AFECC: lwc1        $f4, 0x8C($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X8C);
    // 0x800AFED0: add.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x800AFED4: lwc1        $f0, 0x24($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X24);
    // 0x800AFED8: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800AFEDC: sub.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f4.fl;
    // 0x800AFEE0: swc1        $f2, -0x4870($v0)
    MEM_W(-0X4870, ctx->r2) = ctx->f2.u32l;
    // 0x800AFEE4: lwc1        $f2, 0x2C($v1)
    ctx->f2.u32l = MEM_W(ctx->r3, 0X2C);
    // 0x800AFEE8: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800AFEEC: add.s       $f2, $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f4.fl;
    // 0x800AFEF0: swc1        $f0, -0x486C($v0)
    MEM_W(-0X486C, ctx->r2) = ctx->f0.u32l;
    // 0x800AFEF4: lwc1        $f0, 0x30($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X30);
    // 0x800AFEF8: sub.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f4.fl;
    // 0x800AFEFC: lwc1        $f4, 0x84($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X84);
    // 0x800AFF00: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800AFF04: swc1        $f2, -0x4868($v0)
    MEM_W(-0X4868, ctx->r2) = ctx->f2.u32l;
    // 0x800AFF08: lwc1        $f2, 0x88($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X88);
    // 0x800AFF0C: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800AFF10: c.lt.s      $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f4.fl < ctx->f2.fl;
    // 0x800AFF14: nop

    // 0x800AFF18: bc1f        L_800AFF30
    if (!c1cs) {
        // 0x800AFF1C: swc1        $f0, -0x4864($v0)
        MEM_W(-0X4864, ctx->r2) = ctx->f0.u32l;
            goto L_800AFF30;
    }
    // 0x800AFF1C: swc1        $f0, -0x4864($v0)
    MEM_W(-0X4864, ctx->r2) = ctx->f0.u32l;
    // 0x800AFF20: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800AFF24: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    // 0x800AFF28: j           L_800AFF48
    // 0x800AFF2C: swc1        $f4, -0x4860($v0)
    MEM_W(-0X4860, ctx->r2) = ctx->f4.u32l;
        goto L_800AFF48;
    // 0x800AFF2C: swc1        $f4, -0x4860($v0)
    MEM_W(-0X4860, ctx->r2) = ctx->f4.u32l;
L_800AFF30:
    // 0x800AFF30: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800AFF34: lwc1        $f0, 0x55A4($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X55A4);
    // 0x800AFF38: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800AFF3C: swc1        $f0, -0x4860($v0)
    MEM_W(-0X4860, ctx->r2) = ctx->f0.u32l;
    // 0x800AFF40: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800AFF44: lwc1        $f0, 0x55A8($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X55A8);
L_800AFF48:
    // 0x800AFF48: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800AFF4C: j           L_800B0060
    // 0x800AFF50: swc1        $f0, -0x485C($v0)
    MEM_W(-0X485C, ctx->r2) = ctx->f0.u32l;
        goto L_800B0060;
    // 0x800AFF50: swc1        $f0, -0x485C($v0)
    MEM_W(-0X485C, ctx->r2) = ctx->f0.u32l;
L_800AFF54:
    // 0x800AFF54: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x800AFF58: addiu       $s0, $s0, 0x6DC0
    ctx->r16 = ADD32(ctx->r16, 0X6DC0);
    // 0x800AFF5C: lwc1        $f0, 0x24($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X24);
    // 0x800AFF60: lwc1        $f2, 0x20($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X20);
    // 0x800AFF64: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x800AFF68: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800AFF6C: lwc1        $f4, 0x55AC($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X55AC);
    // 0x800AFF70: mul.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x800AFF74: add.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x800AFF78: swc1        $f2, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->f2.u32l;
    // 0x800AFF7C: lwc1        $f0, 0x30($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X30);
    // 0x800AFF80: lwc1        $f14, 0x2C($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x800AFF84: sub.s       $f0, $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f14.fl;
    // 0x800AFF88: mul.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x800AFF8C: lui         $a2, 0x8014
    ctx->r6 = S32(0X8014 << 16);
    // 0x800AFF90: addiu       $a2, $a2, -0x7FA8
    ctx->r6 = ADD32(ctx->r6, -0X7FA8);
    // 0x800AFF94: add.s       $f14, $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = ctx->f14.fl + ctx->f0.fl;
    // 0x800AFF98: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    // 0x800AFF9C: mov.s       $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    ctx->f12.fl = ctx->f2.fl;
    // 0x800AFFA0: jal         0x80067D90
    // 0x800AFFA4: swc1        $f14, 0xC($s1)
    MEM_W(0XC, ctx->r17) = ctx->f14.u32l;
    func_80067D90(rdram, ctx);
        goto after_2;
    // 0x800AFFA4: swc1        $f14, 0xC($s1)
    MEM_W(0XC, ctx->r17) = ctx->f14.u32l;
    after_2:
    // 0x800AFFA8: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800AFFAC: lwc1        $f2, 0x55B0($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X55B0);
    // 0x800AFFB0: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800AFFB4: lwc1        $f4, 0x55B4($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X55B4);
    // 0x800AFFB8: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x800AFFBC: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800AFFC0: lwc1        $f2, 0x55B8($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X55B8);
    // 0x800AFFC4: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800AFFC8: swc1        $f2, -0x4860($v0)
    MEM_W(-0X4860, ctx->r2) = ctx->f2.u32l;
    // 0x800AFFCC: swc1        $f0, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->f0.u32l;
    // 0x800AFFD0: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800AFFD4: lwc1        $f0, 0x55BC($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X55BC);
    // 0x800AFFD8: lwc1        $f2, 0x20($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X20);
    // 0x800AFFDC: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800AFFE0: swc1        $f4, -0x485C($v0)
    MEM_W(-0X485C, ctx->r2) = ctx->f4.u32l;
    // 0x800AFFE4: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x800AFFE8: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x800AFFEC: add.s       $f2, $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f4.fl;
    // 0x800AFFF0: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    // 0x800AFFF4: lwc1        $f0, 0x24($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X24);
    // 0x800AFFF8: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800AFFFC: sub.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f4.fl;
    // 0x800B0000: swc1        $f2, -0x4870($v0)
    MEM_W(-0X4870, ctx->r2) = ctx->f2.u32l;
    // 0x800B0004: lwc1        $f2, 0x2C($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x800B0008: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800B000C: add.s       $f2, $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f4.fl;
    // 0x800B0010: swc1        $f0, -0x486C($v0)
    MEM_W(-0X486C, ctx->r2) = ctx->f0.u32l;
    // 0x800B0014: lwc1        $f0, 0x30($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X30);
    // 0x800B0018: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800B001C: sub.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f4.fl;
    // 0x800B0020: swc1        $f2, -0x4868($v0)
    MEM_W(-0X4868, ctx->r2) = ctx->f2.u32l;
    // 0x800B0024: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800B0028: j           L_800B0060
    // 0x800B002C: swc1        $f0, -0x4864($v0)
    MEM_W(-0X4864, ctx->r2) = ctx->f0.u32l;
        goto L_800B0060;
    // 0x800B002C: swc1        $f0, -0x4864($v0)
    MEM_W(-0X4864, ctx->r2) = ctx->f0.u32l;
L_800B0030:
    // 0x800B0030: lwc1        $f0, 0x10($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X10);
    // 0x800B0034: swc1        $f0, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->f0.u32l;
    // 0x800B0038: lwc1        $f0, 0x14($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X14);
    // 0x800B003C: swc1        $f0, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->f0.u32l;
    // 0x800B0040: lwc1        $f0, 0x18($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X18);
    // 0x800B0044: swc1        $f0, 0xC($s1)
    MEM_W(0XC, ctx->r17) = ctx->f0.u32l;
    // 0x800B0048: lw          $t0, 0x1C($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X1C);
    // 0x800B004C: lw          $t1, 0x20($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X20);
    // 0x800B0050: lw          $t2, 0x24($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X24);
    // 0x800B0054: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x800B0058: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    // 0x800B005C: sw          $t2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r10;
L_800B0060:
    // 0x800B0060: lui         $s0, 0x8014
    ctx->r16 = S32(0X8014 << 16);
    // 0x800B0064: addiu       $s0, $s0, -0x7FF4
    ctx->r16 = ADD32(ctx->r16, -0X7FF4);
    // 0x800B0068: lw          $v0, 0xB8($s1)
    ctx->r2 = MEM_W(ctx->r17, 0XB8);
    // 0x800B006C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800B0070: sll         $a0, $v0, 2
    ctx->r4 = S32(ctx->r2 << 2);
    // 0x800B0074: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // 0x800B0078: sll         $a0, $a0, 2
    ctx->r4 = S32(ctx->r4 << 2);
    // 0x800B007C: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // 0x800B0080: sll         $a0, $a0, 5
    ctx->r4 = S32(ctx->r4 << 5);
    // 0x800B0084: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x800B0088: addu        $a0, $a0, $s0
    ctx->r4 = ADD32(ctx->r4, ctx->r16);
    // 0x800B008C: addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    // 0x800B0090: jal         0x800AA570
    // 0x800B0094: addu        $a3, $a1, $zero
    ctx->r7 = ADD32(ctx->r5, 0);
    func_800AA570(rdram, ctx);
        goto after_3;
    // 0x800B0094: addu        $a3, $a1, $zero
    ctx->r7 = ADD32(ctx->r5, 0);
    after_3:
    // 0x800B0098: lw          $v0, 0xB8($s1)
    ctx->r2 = MEM_W(ctx->r17, 0XB8);
    // 0x800B009C: lw          $a1, 0x10($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X10);
    // 0x800B00A0: sll         $a0, $v0, 2
    ctx->r4 = S32(ctx->r2 << 2);
    // 0x800B00A4: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // 0x800B00A8: sll         $a0, $a0, 2
    ctx->r4 = S32(ctx->r4 << 2);
    // 0x800B00AC: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // 0x800B00B0: sll         $a0, $a0, 5
    ctx->r4 = S32(ctx->r4 << 5);
    // 0x800B00B4: jal         0x8001CB9C
    // 0x800B00B8: addu        $a0, $a0, $s0
    ctx->r4 = ADD32(ctx->r4, ctx->r16);
    func_8001CB9C(rdram, ctx);
        goto after_4;
    // 0x800B00B8: addu        $a0, $a0, $s0
    ctx->r4 = ADD32(ctx->r4, ctx->r16);
    after_4:
    // 0x800B00BC: lw          $v0, 0xB8($s1)
    ctx->r2 = MEM_W(ctx->r17, 0XB8);
    // 0x800B00C0: lw          $a1, 0x14($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X14);
    // 0x800B00C4: sll         $a0, $v0, 2
    ctx->r4 = S32(ctx->r2 << 2);
    // 0x800B00C8: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // 0x800B00CC: sll         $a0, $a0, 2
    ctx->r4 = S32(ctx->r4 << 2);
    // 0x800B00D0: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // 0x800B00D4: sll         $a0, $a0, 5
    ctx->r4 = S32(ctx->r4 << 5);
    // 0x800B00D8: jal         0x8001CCCC
    // 0x800B00DC: addu        $a0, $a0, $s0
    ctx->r4 = ADD32(ctx->r4, ctx->r16);
    func_8001CCCC(rdram, ctx);
        goto after_5;
    // 0x800B00DC: addu        $a0, $a0, $s0
    ctx->r4 = ADD32(ctx->r4, ctx->r16);
    after_5:
    // 0x800B00E0: lw          $v0, 0xB8($s1)
    ctx->r2 = MEM_W(ctx->r17, 0XB8);
    // 0x800B00E4: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x800B00E8: sll         $a0, $v0, 2
    ctx->r4 = S32(ctx->r2 << 2);
    // 0x800B00EC: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // 0x800B00F0: sll         $a0, $a0, 2
    ctx->r4 = S32(ctx->r4 << 2);
    // 0x800B00F4: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // 0x800B00F8: sll         $a0, $a0, 5
    ctx->r4 = S32(ctx->r4 << 5);
    // 0x800B00FC: jal         0x8001CDFC
    // 0x800B0100: addu        $a0, $a0, $s0
    ctx->r4 = ADD32(ctx->r4, ctx->r16);
    func_8001CDFC(rdram, ctx);
        goto after_6;
    // 0x800B0100: addu        $a0, $a0, $s0
    ctx->r4 = ADD32(ctx->r4, ctx->r16);
    after_6:
    // 0x800B0104: lw          $v1, 0xB8($s1)
    ctx->r3 = MEM_W(ctx->r17, 0XB8);
    // 0x800B0108: lwc1        $f0, 0x4($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X4);
    // 0x800B010C: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x800B0110: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800B0114: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800B0118: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800B011C: sll         $v0, $v0, 5
    ctx->r2 = S32(ctx->r2 << 5);
    // 0x800B0120: addu        $v0, $v0, $s0
    ctx->r2 = ADD32(ctx->r2, ctx->r16);
    // 0x800B0124: swc1        $f0, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->f0.u32l;
    // 0x800B0128: lw          $v1, 0xB8($s1)
    ctx->r3 = MEM_W(ctx->r17, 0XB8);
    // 0x800B012C: lwc1        $f0, 0x8($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X8);
    // 0x800B0130: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x800B0134: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800B0138: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800B013C: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800B0140: sll         $v0, $v0, 5
    ctx->r2 = S32(ctx->r2 << 5);
    // 0x800B0144: addu        $v0, $v0, $s0
    ctx->r2 = ADD32(ctx->r2, ctx->r16);
    // 0x800B0148: swc1        $f0, 0x28($v0)
    MEM_W(0X28, ctx->r2) = ctx->f0.u32l;
    // 0x800B014C: lw          $v1, 0xB8($s1)
    ctx->r3 = MEM_W(ctx->r17, 0XB8);
    // 0x800B0150: lwc1        $f0, 0xC($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0XC);
    // 0x800B0154: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x800B0158: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800B015C: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800B0160: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800B0164: sll         $v0, $v0, 5
    ctx->r2 = S32(ctx->r2 << 5);
    // 0x800B0168: addu        $v0, $v0, $s0
    ctx->r2 = ADD32(ctx->r2, ctx->r16);
    // 0x800B016C: swc1        $f0, 0x2C($v0)
    MEM_W(0X2C, ctx->r2) = ctx->f0.u32l;
    // 0x800B0170: lw          $v0, 0xB8($s1)
    ctx->r2 = MEM_W(ctx->r17, 0XB8);
    // 0x800B0174: addiu       $a0, $s1, 0x4
    ctx->r4 = ADD32(ctx->r17, 0X4);
    // 0x800B0178: sll         $a1, $v0, 2
    ctx->r5 = S32(ctx->r2 << 2);
    // 0x800B017C: addu        $a1, $a1, $v0
    ctx->r5 = ADD32(ctx->r5, ctx->r2);
    // 0x800B0180: sll         $a1, $a1, 2
    ctx->r5 = S32(ctx->r5 << 2);
    // 0x800B0184: addu        $a1, $a1, $v0
    ctx->r5 = ADD32(ctx->r5, ctx->r2);
    // 0x800B0188: sll         $a1, $a1, 5
    ctx->r5 = S32(ctx->r5 << 5);
    // 0x800B018C: jal         0x80059D18
    // 0x800B0190: addu        $a1, $a1, $s0
    ctx->r5 = ADD32(ctx->r5, ctx->r16);
    func_80059D18(rdram, ctx);
        goto after_7;
    // 0x800B0190: addu        $a1, $a1, $s0
    ctx->r5 = ADD32(ctx->r5, ctx->r16);
    after_7:
    // 0x800B0194: addiu       $a1, $sp, 0x10
    ctx->r5 = ADD32(ctx->r29, 0X10);
    // 0x800B0198: lw          $v0, 0xB8($s1)
    ctx->r2 = MEM_W(ctx->r17, 0XB8);
    // 0x800B019C: addiu       $a2, $s1, 0xCC
    ctx->r6 = ADD32(ctx->r17, 0XCC);
    // 0x800B01A0: sll         $a0, $v0, 2
    ctx->r4 = S32(ctx->r2 << 2);
    // 0x800B01A4: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // 0x800B01A8: sll         $a0, $a0, 2
    ctx->r4 = S32(ctx->r4 << 2);
    // 0x800B01AC: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // 0x800B01B0: sll         $a0, $a0, 5
    ctx->r4 = S32(ctx->r4 << 5);
    // 0x800B01B4: jal         0x800A9B80
    // 0x800B01B8: addu        $a0, $a0, $s0
    ctx->r4 = ADD32(ctx->r4, ctx->r16);
    func_800A9B80(rdram, ctx);
        goto after_8;
    // 0x800B01B8: addu        $a0, $a0, $s0
    ctx->r4 = ADD32(ctx->r4, ctx->r16);
    after_8:
    // 0x800B01BC: lhu         $a0, 0xB6($s1)
    ctx->r4 = MEM_HU(ctx->r17, 0XB6);
    // 0x800B01C0: jal         0x8004013C
    // 0x800B01C4: nop

    func_8004013C(rdram, ctx);
        goto after_9;
    // 0x800B01C4: nop

    after_9:
    // 0x800B01C8: jal         0x800F2AB4
    // 0x800B01CC: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    func_800F2AB4(rdram, ctx);
        goto after_10;
    // 0x800B01CC: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    after_10:
    // 0x800B01D0: lw          $ra, 0x28($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X28);
    // 0x800B01D4: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x800B01D8: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x800B01DC: jr          $ra
    // 0x800B01E0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x800B01E0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_800B0148(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B0148: addiu       $sp, $sp, -0xC8
    ctx->r29 = ADD32(ctx->r29, -0XC8);
    // 0x800B014C: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x800B0150: addiu       $a0, $sp, 0x20
    ctx->r4 = ADD32(ctx->r29, 0X20);
    // 0x800B0154: sw          $ra, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->r31;
    // 0x800B0158: sw          $fp, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->r30;
    // 0x800B015C: sw          $s7, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->r23;
    // 0x800B0160: sw          $s6, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->r22;
    // 0x800B0164: sw          $s5, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->r21;
    // 0x800B0168: sw          $s4, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->r20;
    // 0x800B016C: sw          $s3, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->r19;
    // 0x800B0170: sw          $s2, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->r18;
    // 0x800B0174: sw          $s1, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->r17;
    // 0x800B0178: sw          $s0, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->r16;
    // 0x800B017C: sdc1        $f22, 0xC0($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0XC0, ctx->r29);
    // 0x800B0180: sdc1        $f20, 0xB8($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0XB8, ctx->r29);
    // 0x800B0184: addiu       $t3, $v0, 0x5994
    ctx->r11 = ADD32(ctx->r2, 0X5994);
    // 0x800B0188: lw          $t0, 0x0($t3)
    ctx->r8 = MEM_W(ctx->r11, 0X0);
    // 0x800B018C: lw          $t1, 0x4($t3)
    ctx->r9 = MEM_W(ctx->r11, 0X4);
    // 0x800B0190: lw          $t2, 0x8($t3)
    ctx->r10 = MEM_W(ctx->r11, 0X8);
    // 0x800B0194: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x800B0198: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    // 0x800B019C: sw          $t2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r10;
    // 0x800B01A0: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x800B01A4: addiu       $v1, $v0, 0x59A0
    ctx->r3 = ADD32(ctx->r2, 0X59A0);
    // 0x800B01A8: addiu       $v0, $v1, 0x20
    ctx->r2 = ADD32(ctx->r3, 0X20);
L_800B01AC:
    // 0x800B01AC: lw          $t0, 0x0($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X0);
    // 0x800B01B0: lw          $t1, 0x4($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X4);
    // 0x800B01B4: lw          $t2, 0x8($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X8);
    // 0x800B01B8: lw          $t3, 0xC($v1)
    ctx->r11 = MEM_W(ctx->r3, 0XC);
    // 0x800B01BC: sw          $t0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r8;
    // 0x800B01C0: sw          $t1, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r9;
    // 0x800B01C4: sw          $t2, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r10;
    // 0x800B01C8: sw          $t3, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r11;
    // 0x800B01CC: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
    // 0x800B01D0: bne         $v1, $v0, L_800B01AC
    if (ctx->r3 != ctx->r2) {
        // 0x800B01D4: addiu       $a0, $a0, 0x10
        ctx->r4 = ADD32(ctx->r4, 0X10);
            goto L_800B01AC;
    }
    // 0x800B01D4: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    // 0x800B01D8: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x800B01DC: lwc1        $f12, -0x2510($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, -0X2510);
    // 0x800B01E0: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x800B01E4: lw          $t0, 0x0($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X0);
    // 0x800B01E8: sw          $t0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r8;
    // 0x800B01EC: addiu       $t3, $v0, 0x59C4
    ctx->r11 = ADD32(ctx->r2, 0X59C4);
    // 0x800B01F0: lw          $t0, 0x0($t3)
    ctx->r8 = MEM_W(ctx->r11, 0X0);
    // 0x800B01F4: lw          $t1, 0x4($t3)
    ctx->r9 = MEM_W(ctx->r11, 0X4);
    // 0x800B01F8: lw          $t2, 0x8($t3)
    ctx->r10 = MEM_W(ctx->r11, 0X8);
    // 0x800B01FC: sw          $t0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r8;
    // 0x800B0200: sw          $t1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r9;
    // 0x800B0204: sw          $t2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r10;
    // 0x800B0208: jal         0x800662E0
    // 0x800B020C: lui         $s0, 0x800D
    ctx->r16 = S32(0X800D << 16);
    func_800662E0(rdram, ctx);
        goto after_0;
    // 0x800B020C: lui         $s0, 0x800D
    ctx->r16 = S32(0X800D << 16);
    after_0:
    // 0x800B0210: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800B0214: lwc1        $f2, 0x59D0($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X59D0);
    // 0x800B0218: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x800B021C: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800B0220: lwc1        $f2, 0x59D4($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X59D4);
    // 0x800B0224: addiu       $s0, $s0, -0x2024
    ctx->r16 = ADD32(ctx->r16, -0X2024);
    // 0x800B0228: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x800B022C: lui         $a2, 0x4080
    ctx->r6 = S32(0X4080 << 16);
    // 0x800B0230: lui         $a3, 0x4100
    ctx->r7 = S32(0X4100 << 16);
    // 0x800B0234: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x800B0238: jal         0x8001CB64
    // 0x800B023C: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_8001CB64(rdram, ctx);
        goto after_1;
    // 0x800B023C: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_1:
    // 0x800B0240: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x800B0244: lw          $a1, -0x2520($v0)
    ctx->r5 = MEM_W(ctx->r2, -0X2520);
    // 0x800B0248: jal         0x8001CCCC
    // 0x800B024C: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_8001CCCC(rdram, ctx);
        goto after_2;
    // 0x800B024C: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_2:
    // 0x800B0250: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800B0254: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x800B0258: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x800B025C: lui         $a2, 0x40B9
    ctx->r6 = S32(0X40B9 << 16);
    // 0x800B0260: ori         $a2, $a2, 0x999A
    ctx->r6 = ctx->r6 | 0X999A;
    // 0x800B0264: jal         0x8001CA90
    // 0x800B0268: addu        $a3, $a1, $zero
    ctx->r7 = ADD32(ctx->r5, 0);
    func_8001CA90(rdram, ctx);
        goto after_3;
    // 0x800B0268: addu        $a3, $a1, $zero
    ctx->r7 = ADD32(ctx->r5, 0);
    after_3:
    // 0x800B026C: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x800B0270: lwc1        $f0, -0x24E8($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, -0X24E8);
    // 0x800B0274: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800B0278: lwc1        $f12, 0x59D8($at)
    ctx->f12.u32l = MEM_W(ctx->r1, 0X59D8);
    // 0x800B027C: mul.s       $f12, $f0, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = MUL_S(ctx->f0.fl, ctx->f12.fl);
    // 0x800B0280: jal         0x80033960
    // 0x800B0284: addiu       $s0, $s0, -0x1C
    ctx->r16 = ADD32(ctx->r16, -0X1C);
    sinf_recomp(rdram, ctx);
        goto after_4;
    // 0x800B0284: addiu       $s0, $s0, -0x1C
    ctx->r16 = ADD32(ctx->r16, -0X1C);
    after_4:
    // 0x800B0288: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800B028C: lwc1        $f2, 0x59DC($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X59DC);
    // 0x800B0290: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x800B0294: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800B0298: lwc1        $f2, 0x59E0($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X59E0);
    // 0x800B029C: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x800B02A0: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800B02A4: lwc1        $f2, 0x59E4($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X59E4);
    // 0x800B02A8: c.le.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl <= ctx->f0.fl;
    // 0x800B02AC: nop

    // 0x800B02B0: bc1tl       L_800B02C8
    if (c1cs) {
        // 0x800B02B4: sub.s       $f0, $f0, $f2
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
            goto L_800B02C8;
    }
    goto skip_0;
    // 0x800B02B4: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    skip_0:
    // 0x800B02B8: trunc.w.s   $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    ctx->f6.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800B02BC: mfc1        $a0, $f6
    ctx->r4 = (int32_t)ctx->f6.u32l;
    // 0x800B02C0: j           L_800B02DC
    // 0x800B02C4: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
        goto L_800B02DC;
    // 0x800B02C4: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
L_800B02C8:
    // 0x800B02C8: lui         $v0, 0x8000
    ctx->r2 = S32(0X8000 << 16);
    // 0x800B02CC: trunc.w.s   $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    ctx->f6.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800B02D0: mfc1        $a0, $f6
    ctx->r4 = (int32_t)ctx->f6.u32l;
    // 0x800B02D4: or          $a0, $a0, $v0
    ctx->r4 = ctx->r4 | ctx->r2;
    // 0x800B02D8: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
L_800B02DC:
    // 0x800B02DC: addiu       $a1, $v1, -0x2040
    ctx->r5 = ADD32(ctx->r3, -0X2040);
    // 0x800B02E0: lw          $v0, 0x58($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X58);
    // 0x800B02E4: sb          $a0, 0xD7($s0)
    MEM_B(0XD7, ctx->r16) = ctx->r4;
    // 0x800B02E8: ori         $v0, $v0, 0x20
    ctx->r2 = ctx->r2 | 0X20;
    // 0x800B02EC: sw          $v0, 0x58($a1)
    MEM_W(0X58, ctx->r5) = ctx->r2;
    // 0x800B02F0: lui         $a0, 0x800D
    ctx->r4 = S32(0X800D << 16);
    // 0x800B02F4: lw          $v0, -0x2380($a0)
    ctx->r2 = MEM_W(ctx->r4, -0X2380);
    // 0x800B02F8: beq         $v0, $zero, L_800B0304
    if (ctx->r2 == 0) {
        // 0x800B02FC: sw          $v0, -0x2040($v1)
        MEM_W(-0X2040, ctx->r3) = ctx->r2;
            goto L_800B0304;
    }
    // 0x800B02FC: sw          $v0, -0x2040($v1)
    MEM_W(-0X2040, ctx->r3) = ctx->r2;
    // 0x800B0300: sw          $a1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r5;
L_800B0304:
    // 0x800B0304: sw          $zero, 0x4($a1)
    MEM_W(0X4, ctx->r5) = 0;
    // 0x800B0308: sw          $a1, -0x2380($a0)
    MEM_W(-0X2380, ctx->r4) = ctx->r5;
    // 0x800B030C: addiu       $s4, $zero, 0x1
    ctx->r20 = ADD32(0, 0X1);
    // 0x800B0310: lui         $s3, 0x800D
    ctx->r19 = S32(0X800D << 16);
    // 0x800B0314: addiu       $s7, $a1, 0x1C
    ctx->r23 = ADD32(ctx->r5, 0X1C);
    // 0x800B0318: lui         $s6, 0x800D
    ctx->r22 = S32(0X800D << 16);
    // 0x800B031C: addu        $s5, $a1, $zero
    ctx->r21 = ADD32(ctx->r5, 0);
    // 0x800B0320: addu        $s2, $a0, $zero
    ctx->r18 = ADD32(ctx->r4, 0);
    // 0x800B0324: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
L_800B0328:
    // 0x800B0328: jal         0x80003430
    // 0x800B032C: nop

    rand_recomp(rdram, ctx);
        goto after_5;
    // 0x800B032C: nop

    after_5:
    // 0x800B0330: lwc1        $f0, -0x2510($s3)
    ctx->f0.u32l = MEM_W(ctx->r19, -0X2510);
    // 0x800B0334: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800B0338: lwc1        $f2, 0x59E8($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X59E8);
    // 0x800B033C: sub.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl - ctx->f0.fl;
    // 0x800B0340: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800B0344: lwc1        $f0, 0x59EC($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X59EC);
    // 0x800B0348: mul.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x800B034C: andi        $v0, $v0, 0x1F
    ctx->r2 = ctx->r2 & 0X1F;
    // 0x800B0350: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800B0354: lwc1        $f0, 0x59F0($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X59F0);
    // 0x800B0358: mtc1        $v0, $f4
    ctx->f4.u32l = ctx->r2;
    // 0x800B035C: cvt.s.w     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800B0360: mul.s       $f4, $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x800B0364: andi        $v0, $s4, 0xFF
    ctx->r2 = ctx->r20 & 0XFF;
    // 0x800B0368: sll         $s0, $v0, 6
    ctx->r16 = S32(ctx->r2 << 6);
    // 0x800B036C: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800B0370: lwc1        $f0, 0x59F4($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X59F4);
    // 0x800B0374: subu        $s0, $s0, $v0
    ctx->r16 = SUB32(ctx->r16, ctx->r2);
    // 0x800B0378: add.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x800B037C: sll         $s0, $s0, 2
    ctx->r16 = S32(ctx->r16 << 2);
    // 0x800B0380: addu        $s1, $s0, $s7
    ctx->r17 = ADD32(ctx->r16, ctx->r23);
    // 0x800B0384: add.s       $f2, $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f4.fl;
    // 0x800B0388: lui         $a1, 0x3E4C
    ctx->r5 = S32(0X3E4C << 16);
    // 0x800B038C: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    // 0x800B0390: lui         $a3, 0x4100
    ctx->r7 = S32(0X4100 << 16);
    // 0x800B0394: mfc1        $a2, $f2
    ctx->r6 = (int32_t)ctx->f2.u32l;
    // 0x800B0398: jal         0x8001CB64
    // 0x800B039C: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    func_8001CB64(rdram, ctx);
        goto after_6;
    // 0x800B039C: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    after_6:
    // 0x800B03A0: jal         0x80003430
    // 0x800B03A4: addu        $s0, $s0, $s5
    ctx->r16 = ADD32(ctx->r16, ctx->r21);
    rand_recomp(rdram, ctx);
        goto after_7;
    // 0x800B03A4: addu        $s0, $s0, $s5
    ctx->r16 = ADD32(ctx->r16, ctx->r21);
    after_7:
    // 0x800B03A8: lwc1        $f2, -0x2510($s3)
    ctx->f2.u32l = MEM_W(ctx->r19, -0X2510);
    // 0x800B03AC: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800B03B0: lwc1        $f0, 0x59F8($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X59F8);
    // 0x800B03B4: mul.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x800B03B8: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800B03BC: lwc1        $f0, 0x59FC($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X59FC);
    // 0x800B03C0: andi        $v0, $v0, 0x7F
    ctx->r2 = ctx->r2 & 0X7F;
    // 0x800B03C4: add.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x800B03C8: addiu       $v0, $v0, -0x40
    ctx->r2 = ADD32(ctx->r2, -0X40);
    // 0x800B03CC: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x800B03D0: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x800B03D4: mul.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x800B03D8: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800B03DC: lwc1        $f0, 0x5A00($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X5A00);
    // 0x800B03E0: div.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = DIV_S(ctx->f2.fl, ctx->f0.fl);
    // 0x800B03E4: mfc1        $a1, $f2
    ctx->r5 = (int32_t)ctx->f2.u32l;
    // 0x800B03E8: jal         0x8001CDFC
    // 0x800B03EC: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    func_8001CDFC(rdram, ctx);
        goto after_8;
    // 0x800B03EC: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    after_8:
    // 0x800B03F0: lw          $a1, -0x2520($s6)
    ctx->r5 = MEM_W(ctx->r22, -0X2520);
    // 0x800B03F4: jal         0x8001CCCC
    // 0x800B03F8: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    func_8001CCCC(rdram, ctx);
        goto after_9;
    // 0x800B03F8: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    after_9:
    // 0x800B03FC: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x800B0400: lui         $a2, 0x40B9
    ctx->r6 = S32(0X40B9 << 16);
    // 0x800B0404: ori         $a2, $a2, 0x999A
    ctx->r6 = ctx->r6 | 0X999A;
    // 0x800B0408: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x800B040C: jal         0x8001CA90
    // 0x800B0410: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    func_8001CA90(rdram, ctx);
        goto after_10;
    // 0x800B0410: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    after_10:
    // 0x800B0414: lw          $v0, 0x58($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X58);
    // 0x800B0418: ori         $v0, $v0, 0x20
    ctx->r2 = ctx->r2 | 0X20;
    // 0x800B041C: sw          $v0, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->r2;
    // 0x800B0420: lw          $v0, -0x2380($s2)
    ctx->r2 = MEM_W(ctx->r18, -0X2380);
    // 0x800B0424: beq         $v0, $zero, L_800B0430
    if (ctx->r2 == 0) {
        // 0x800B0428: sw          $v0, 0x0($s0)
        MEM_W(0X0, ctx->r16) = ctx->r2;
            goto L_800B0430;
    }
    // 0x800B0428: sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
    // 0x800B042C: sw          $s0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r16;
L_800B0430:
    // 0x800B0430: sw          $zero, 0x4($s0)
    MEM_W(0X4, ctx->r16) = 0;
    // 0x800B0434: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    // 0x800B0438: andi        $v0, $s4, 0xFF
    ctx->r2 = ctx->r20 & 0XFF;
    // 0x800B043C: sltiu       $v0, $v0, 0x4
    ctx->r2 = ctx->r2 < 0X4 ? 1 : 0;
    // 0x800B0440: bne         $v0, $zero, L_800B0328
    if (ctx->r2 != 0) {
        // 0x800B0444: sw          $s0, -0x2380($s2)
        MEM_W(-0X2380, ctx->r18) = ctx->r16;
            goto L_800B0328;
    }
    // 0x800B0444: sw          $s0, -0x2380($s2)
    MEM_W(-0X2380, ctx->r18) = ctx->r16;
    // 0x800B0448: addiu       $s4, $zero, 0x4
    ctx->r20 = ADD32(0, 0X4);
    // 0x800B044C: addiu       $t1, $sp, -0x10
    ctx->r9 = ADD32(ctx->r29, -0X10);
    // 0x800B0450: addiu       $s6, $sp, 0x68
    ctx->r22 = ADD32(ctx->r29, 0X68);
    // 0x800B0454: addiu       $s5, $sp, 0x78
    ctx->r21 = ADD32(ctx->r29, 0X78);
    // 0x800B0458: lui         $t2, 0x800D
    ctx->r10 = S32(0X800D << 16);
    // 0x800B045C: addiu       $t2, $t2, -0x2024
    ctx->r10 = ADD32(ctx->r10, -0X2024);
    // 0x800B0460: addiu       $fp, $t2, -0x1C
    ctx->r30 = ADD32(ctx->r10, -0X1C);
    // 0x800B0464: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800B0468: lwc1        $f22, 0x5A04($at)
    ctx->f22.u32l = MEM_W(ctx->r1, 0X5A04);
    // 0x800B046C: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800B0470: lwc1        $f20, 0x5A08($at)
    ctx->f20.u32l = MEM_W(ctx->r1, 0X5A08);
    // 0x800B0474: lui         $s7, 0x800D
    ctx->r23 = S32(0X800D << 16);
    // 0x800B0478: sw          $t1, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r9;
L_800B047C:
    // 0x800B047C: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x800B0480: andi        $s0, $s4, 0xFF
    ctx->r16 = ctx->r20 & 0XFF;
    // 0x800B0484: lwc1        $f2, -0x2510($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, -0X2510);
    // 0x800B0488: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800B048C: lwc1        $f0, 0x5A0C($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X5A0C);
    // 0x800B0490: sll         $s2, $s0, 6
    ctx->r18 = S32(ctx->r16 << 6);
    // 0x800B0494: mul.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x800B0498: subu        $s2, $s2, $s0
    ctx->r18 = SUB32(ctx->r18, ctx->r16);
    // 0x800B049C: sll         $s2, $s2, 2
    ctx->r18 = S32(ctx->r18 << 2);
    // 0x800B04A0: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800B04A4: lwc1        $f0, 0x5A10($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X5A10);
    // 0x800B04A8: lui         $t3, 0x800D
    ctx->r11 = S32(0X800D << 16);
    // 0x800B04AC: add.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x800B04B0: addiu       $t3, $t3, -0x2024
    ctx->r11 = ADD32(ctx->r11, -0X2024);
    // 0x800B04B4: addu        $s3, $s2, $t3
    ctx->r19 = ADD32(ctx->r18, ctx->r11);
    // 0x800B04B8: mfc1        $a1, $f2
    ctx->r5 = (int32_t)ctx->f2.u32l;
    // 0x800B04BC: addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    // 0x800B04C0: addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    // 0x800B04C4: jal         0x8001CB64
    // 0x800B04C8: addu        $a3, $a1, $zero
    ctx->r7 = ADD32(ctx->r5, 0);
    func_8001CB64(rdram, ctx);
        goto after_11;
    // 0x800B04C8: addu        $a3, $a1, $zero
    ctx->r7 = ADD32(ctx->r5, 0);
    after_11:
    // 0x800B04CC: addiu       $s1, $s0, -0x4
    ctx->r17 = ADD32(ctx->r16, -0X4);
    // 0x800B04D0: sll         $v0, $s1, 2
    ctx->r2 = S32(ctx->r17 << 2);
    // 0x800B04D4: addu        $v0, $sp, $v0
    ctx->r2 = ADD32(ctx->r29, ctx->r2);
    // 0x800B04D8: lw          $a1, 0x10($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X10);
    // 0x800B04DC: jal         0x8001CCCC
    // 0x800B04E0: addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    func_8001CCCC(rdram, ctx);
        goto after_12;
    // 0x800B04E0: addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    after_12:
    // 0x800B04E4: sll         $v0, $s0, 1
    ctx->r2 = S32(ctx->r16 << 1);
    // 0x800B04E8: addu        $v0, $v0, $s0
    ctx->r2 = ADD32(ctx->r2, ctx->r16);
    // 0x800B04EC: lw          $t0, 0x88($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X88);
    // 0x800B04F0: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800B04F4: addu        $v0, $t0, $v0
    ctx->r2 = ADD32(ctx->r8, ctx->r2);
    // 0x800B04F8: lwc1        $f0, 0x0($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X0);
    // 0x800B04FC: addu        $a0, $s6, $zero
    ctx->r4 = ADD32(ctx->r22, 0);
    // 0x800B0500: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
    // 0x800B0504: swc1        $f0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f0.u32l;
    // 0x800B0508: lwc1        $f0, 0x4($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X4);
    // 0x800B050C: addiu       $a1, $sp, 0x58
    ctx->r5 = ADD32(ctx->r29, 0X58);
    // 0x800B0510: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
    // 0x800B0514: swc1        $f0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f0.u32l;
    // 0x800B0518: lwc1        $f0, 0x8($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X8);
    // 0x800B051C: addiu       $a2, $sp, 0x48
    ctx->r6 = ADD32(ctx->r29, 0X48);
    // 0x800B0520: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
    // 0x800B0524: jal         0x80019548
    // 0x800B0528: swc1        $f0, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f0.u32l;
    func_80019548(rdram, ctx);
        goto after_13;
    // 0x800B0528: swc1        $f0, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f0.u32l;
    after_13:
    // 0x800B052C: addu        $a0, $s5, $zero
    ctx->r4 = ADD32(ctx->r21, 0);
    // 0x800B0530: mfc1        $a2, $f22
    ctx->r6 = (int32_t)ctx->f22.u32l;
    // 0x800B0534: jal         0x8001D144
    // 0x800B0538: addu        $a1, $s6, $zero
    ctx->r5 = ADD32(ctx->r22, 0);
    func_8001D144(rdram, ctx);
        goto after_14;
    // 0x800B0538: addu        $a1, $s6, $zero
    ctx->r5 = ADD32(ctx->r22, 0);
    after_14:
    // 0x800B053C: addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    // 0x800B0540: jal         0x8001DAEC
    // 0x800B0544: addu        $a1, $s5, $zero
    ctx->r5 = ADD32(ctx->r21, 0);
    func_8001DAEC(rdram, ctx);
        goto after_15;
    // 0x800B0544: addu        $a1, $s5, $zero
    ctx->r5 = ADD32(ctx->r21, 0);
    after_15:
    // 0x800B0548: sll         $v0, $s1, 1
    ctx->r2 = S32(ctx->r17 << 1);
    // 0x800B054C: addu        $v0, $v0, $s1
    ctx->r2 = ADD32(ctx->r2, ctx->r17);
    // 0x800B0550: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800B0554: addiu       $v1, $sp, 0x20
    ctx->r3 = ADD32(ctx->r29, 0X20);
    // 0x800B0558: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x800B055C: lw          $a1, 0x0($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X0);
    // 0x800B0560: lw          $a2, 0x4($v1)
    ctx->r6 = MEM_W(ctx->r3, 0X4);
    // 0x800B0564: lw          $a3, 0x8($v1)
    ctx->r7 = MEM_W(ctx->r3, 0X8);
    // 0x800B0568: jal         0x8001CA90
    // 0x800B056C: addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    func_8001CA90(rdram, ctx);
        goto after_16;
    // 0x800B056C: addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    after_16:
    // 0x800B0570: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x800B0574: lwc1        $f0, -0x24E8($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, -0X24E8);
    // 0x800B0578: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800B057C: lwc1        $f12, 0x5A14($at)
    ctx->f12.u32l = MEM_W(ctx->r1, 0X5A14);
    // 0x800B0580: mul.s       $f12, $f0, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = MUL_S(ctx->f0.fl, ctx->f12.fl);
    // 0x800B0584: jal         0x80033960
    // 0x800B0588: addu        $s2, $s2, $fp
    ctx->r18 = ADD32(ctx->r18, ctx->r30);
    sinf_recomp(rdram, ctx);
        goto after_17;
    // 0x800B0588: addu        $s2, $s2, $fp
    ctx->r18 = ADD32(ctx->r18, ctx->r30);
    after_17:
    // 0x800B058C: mul.s       $f0, $f0, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f22.fl);
    // 0x800B0590: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800B0594: lwc1        $f2, 0x5A18($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X5A18);
    // 0x800B0598: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x800B059C: c.le.s      $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f20.fl <= ctx->f0.fl;
    // 0x800B05A0: nop

    // 0x800B05A4: bc1tl       L_800B05BC
    if (c1cs) {
        // 0x800B05A8: sub.s       $f0, $f0, $f20
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f20.fl;
            goto L_800B05BC;
    }
    goto skip_1;
    // 0x800B05A8: sub.s       $f0, $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f20.fl;
    skip_1:
    // 0x800B05AC: trunc.w.s   $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    ctx->f6.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800B05B0: mfc1        $v1, $f6
    ctx->r3 = (int32_t)ctx->f6.u32l;
    // 0x800B05B4: j           L_800B05D0
    // 0x800B05B8: andi        $v0, $s4, 0xFF
    ctx->r2 = ctx->r20 & 0XFF;
        goto L_800B05D0;
    // 0x800B05B8: andi        $v0, $s4, 0xFF
    ctx->r2 = ctx->r20 & 0XFF;
L_800B05BC:
    // 0x800B05BC: lui         $v0, 0x8000
    ctx->r2 = S32(0X8000 << 16);
    // 0x800B05C0: trunc.w.s   $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    ctx->f6.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800B05C4: mfc1        $v1, $f6
    ctx->r3 = (int32_t)ctx->f6.u32l;
    // 0x800B05C8: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x800B05CC: andi        $v0, $s4, 0xFF
    ctx->r2 = ctx->r20 & 0XFF;
L_800B05D0:
    // 0x800B05D0: sb          $v1, 0xD7($s2)
    MEM_B(0XD7, ctx->r18) = ctx->r3;
    // 0x800B05D4: sll         $v1, $v0, 6
    ctx->r3 = S32(ctx->r2 << 6);
    // 0x800B05D8: subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // 0x800B05DC: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x800B05E0: addu        $v1, $v1, $fp
    ctx->r3 = ADD32(ctx->r3, ctx->r30);
    // 0x800B05E4: lw          $v0, 0x58($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X58);
    // 0x800B05E8: ori         $v0, $v0, 0x20
    ctx->r2 = ctx->r2 | 0X20;
    // 0x800B05EC: sw          $v0, 0x58($v1)
    MEM_W(0X58, ctx->r3) = ctx->r2;
    // 0x800B05F0: lw          $v0, -0x2380($s7)
    ctx->r2 = MEM_W(ctx->r23, -0X2380);
    // 0x800B05F4: beq         $v0, $zero, L_800B0600
    if (ctx->r2 == 0) {
        // 0x800B05F8: sw          $v0, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->r2;
            goto L_800B0600;
    }
    // 0x800B05F8: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x800B05FC: sw          $v1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r3;
L_800B0600:
    // 0x800B0600: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x800B0604: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    // 0x800B0608: andi        $v0, $s4, 0xFF
    ctx->r2 = ctx->r20 & 0XFF;
    // 0x800B060C: sltiu       $v0, $v0, 0x7
    ctx->r2 = ctx->r2 < 0X7 ? 1 : 0;
    // 0x800B0610: bne         $v0, $zero, L_800B047C
    if (ctx->r2 != 0) {
        // 0x800B0614: sw          $v1, -0x2380($s7)
        MEM_W(-0X2380, ctx->r23) = ctx->r3;
            goto L_800B047C;
    }
    // 0x800B0614: sw          $v1, -0x2380($s7)
    MEM_W(-0X2380, ctx->r23) = ctx->r3;
    // 0x800B0618: lw          $ra, 0xB4($sp)
    ctx->r31 = MEM_W(ctx->r29, 0XB4);
    // 0x800B061C: lw          $fp, 0xB0($sp)
    ctx->r30 = MEM_W(ctx->r29, 0XB0);
    // 0x800B0620: lw          $s7, 0xAC($sp)
    ctx->r23 = MEM_W(ctx->r29, 0XAC);
    // 0x800B0624: lw          $s6, 0xA8($sp)
    ctx->r22 = MEM_W(ctx->r29, 0XA8);
    // 0x800B0628: lw          $s5, 0xA4($sp)
    ctx->r21 = MEM_W(ctx->r29, 0XA4);
    // 0x800B062C: lw          $s4, 0xA0($sp)
    ctx->r20 = MEM_W(ctx->r29, 0XA0);
    // 0x800B0630: lw          $s3, 0x9C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X9C);
    // 0x800B0634: lw          $s2, 0x98($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X98);
    // 0x800B0638: lw          $s1, 0x94($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X94);
    // 0x800B063C: lw          $s0, 0x90($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X90);
    // 0x800B0640: ldc1        $f22, 0xC0($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0XC0);
    // 0x800B0644: ldc1        $f20, 0xB8($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0XB8);
    // 0x800B0648: jr          $ra
    // 0x800B064C: addiu       $sp, $sp, 0xC8
    ctx->r29 = ADD32(ctx->r29, 0XC8);
    return;
    // 0x800B064C: addiu       $sp, $sp, 0xC8
    ctx->r29 = ADD32(ctx->r29, 0XC8);
;}
RECOMP_FUNC void func_800B01E4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B01E4: addiu       $sp, $sp, -0xB0
    ctx->r29 = ADD32(ctx->r29, -0XB0);
    // 0x800B01E8: sw          $s2, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r18;
    // 0x800B01EC: addu        $s2, $a0, $zero
    ctx->r18 = ADD32(ctx->r4, 0);
    // 0x800B01F0: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x800B01F4: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800B01F8: sw          $ra, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->r31;
    // 0x800B01FC: sw          $s3, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->r19;
    // 0x800B0200: sw          $s1, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r17;
    // 0x800B0204: sw          $s0, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r16;
    // 0x800B0208: sdc1        $f24, 0xA8($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0XA8, ctx->r29);
    // 0x800B020C: sdc1        $f22, 0xA0($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0XA0, ctx->r29);
    // 0x800B0210: sdc1        $f20, 0x98($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X98, ctx->r29);
    // 0x800B0214: addiu       $t3, $v0, 0x55C0
    ctx->r11 = ADD32(ctx->r2, 0X55C0);
    // 0x800B0218: lwl         $t0, 0x0($t3)
    ctx->r8 = do_lwl(rdram, ctx->r8, ctx->r11, 0X0);
    // 0x800B021C: lwr         $t0, 0x3($t3)
    ctx->r8 = do_lwr(rdram, ctx->r8, ctx->r11, 0X3);
    // 0x800B0220: swl         $t0, 0x50($sp)
    do_swl(rdram, 0X50, ctx->r29, ctx->r8);
    // 0x800B0224: swr         $t0, 0x53($sp)
    do_swr(rdram, 0X53, ctx->r29, ctx->r8);
    // 0x800B0228: lw          $v1, 0xB8($s2)
    ctx->r3 = MEM_W(ctx->r18, 0XB8);
    // 0x800B022C: addiu       $a0, $a0, 0x7DB8
    ctx->r4 = ADD32(ctx->r4, 0X7DB8);
    // 0x800B0230: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x800B0234: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800B0238: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800B023C: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800B0240: sll         $v0, $v0, 5
    ctx->r2 = S32(ctx->r2 << 5);
    // 0x800B0244: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x800B0248: lhu         $v1, 0x184($v0)
    ctx->r3 = MEM_HU(ctx->r2, 0X184);
    // 0x800B024C: andi        $v0, $v1, 0x10
    ctx->r2 = ctx->r3 & 0X10;
    // 0x800B0250: bne         $v0, $zero, L_800B0828
    if (ctx->r2 != 0) {
        // 0x800B0254: addu        $s3, $a1, $zero
        ctx->r19 = ADD32(ctx->r5, 0);
            goto L_800B0828;
    }
    // 0x800B0254: addu        $s3, $a1, $zero
    ctx->r19 = ADD32(ctx->r5, 0);
    // 0x800B0258: andi        $v0, $v1, 0x20
    ctx->r2 = ctx->r3 & 0X20;
    // 0x800B025C: bne         $v0, $zero, L_800B0828
    if (ctx->r2 != 0) {
        // 0x800B0260: nop
    
            goto L_800B0828;
    }
    // 0x800B0260: nop

    // 0x800B0264: jal         0x800FC108
    // 0x800B0268: nop

    func_800FC108(rdram, ctx);
        goto after_0;
    // 0x800B0268: nop

    after_0:
    // 0x800B026C: jal         0x800AD320
    // 0x800B0270: nop

    func_800AD320(rdram, ctx);
        goto after_1;
    // 0x800B0270: nop

    after_1:
    // 0x800B0274: lhu         $v1, 0x1CC($s2)
    ctx->r3 = MEM_HU(ctx->r18, 0X1CC);
    // 0x800B0278: ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
    // 0x800B027C: beq         $v1, $v0, L_800B02BC
    if (ctx->r3 == ctx->r2) {
        // 0x800B0280: addu        $s0, $v0, $zero
        ctx->r16 = ADD32(ctx->r2, 0);
            goto L_800B02BC;
    }
    // 0x800B0280: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
L_800B0284:
    // 0x800B0284: lhu         $a0, 0x1CC($s2)
    ctx->r4 = MEM_HU(ctx->r18, 0X1CC);
    // 0x800B0288: jal         0x80040218
    // 0x800B028C: nop

    func_80040218(rdram, ctx);
        goto after_2;
    // 0x800B028C: nop

    after_2:
    // 0x800B0290: andi        $a0, $v0, 0xFFFF
    ctx->r4 = ctx->r2 & 0XFFFF;
    // 0x800B0294: beq         $a0, $s0, L_800B02AC
    if (ctx->r4 == ctx->r16) {
        // 0x800B0298: nop
    
            goto L_800B02AC;
    }
    // 0x800B0298: nop

    // 0x800B029C: jal         0x8003ED74
    // 0x800B02A0: nop

    func_8003ED74(rdram, ctx);
        goto after_3;
    // 0x800B02A0: nop

    after_3:
    // 0x800B02A4: j           L_800B0284
    // 0x800B02A8: nop

        goto L_800B0284;
    // 0x800B02A8: nop

L_800B02AC:
    // 0x800B02AC: lhu         $a0, 0x1CC($s2)
    ctx->r4 = MEM_HU(ctx->r18, 0X1CC);
    // 0x800B02B0: jal         0x8003F0C8
    // 0x800B02B4: nop

    func_8003F0C8(rdram, ctx);
        goto after_4;
    // 0x800B02B4: nop

    after_4:
    // 0x800B02B8: sh          $s0, 0x1CC($s2)
    MEM_H(0X1CC, ctx->r18) = ctx->r16;
L_800B02BC:
    // 0x800B02BC: lbu         $v0, 0x24C($s2)
    ctx->r2 = MEM_BU(ctx->r18, 0X24C);
    // 0x800B02C0: beq         $v0, $zero, L_800B02D4
    if (ctx->r2 == 0) {
        // 0x800B02C4: nop
    
            goto L_800B02D4;
    }
    // 0x800B02C4: nop

    // 0x800B02C8: sb          $zero, 0x24C($s2)
    MEM_B(0X24C, ctx->r18) = 0;
    // 0x800B02CC: jal         0x80098DE0
    // 0x800B02D0: addiu       $a0, $s2, 0x208
    ctx->r4 = ADD32(ctx->r18, 0X208);
    func_80098DE0(rdram, ctx);
        goto after_5;
    // 0x800B02D0: addiu       $a0, $s2, 0x208
    ctx->r4 = ADD32(ctx->r18, 0X208);
    after_5:
L_800B02D4:
    // 0x800B02D4: jal         0x8003E5F8
    // 0x800B02D8: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    func_8003E5F8(rdram, ctx);
        goto after_6;
    // 0x800B02D8: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    after_6:
    // 0x800B02DC: lui         $a2, 0x8014
    ctx->r6 = S32(0X8014 << 16);
    // 0x800B02E0: addiu       $a2, $a2, -0x7FA8
    ctx->r6 = ADD32(ctx->r6, -0X7FA8);
    // 0x800B02E4: lwc1        $f12, 0x4($s2)
    ctx->f12.u32l = MEM_W(ctx->r18, 0X4);
    // 0x800B02E8: lwc1        $f14, 0xC($s2)
    ctx->f14.u32l = MEM_W(ctx->r18, 0XC);
    // 0x800B02EC: addiu       $a3, $sp, 0x58
    ctx->r7 = ADD32(ctx->r29, 0X58);
    // 0x800B02F0: jal         0x80067D90
    // 0x800B02F4: sh          $v0, 0x1CC($s2)
    MEM_H(0X1CC, ctx->r18) = ctx->r2;
    func_80067D90(rdram, ctx);
        goto after_7;
    // 0x800B02F4: sh          $v0, 0x1CC($s2)
    MEM_H(0X1CC, ctx->r18) = ctx->r2;
    after_7:
    // 0x800B02F8: lwc1        $f2, 0x5C($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x800B02FC: lwc1        $f0, 0x8($s2)
    ctx->f0.u32l = MEM_W(ctx->r18, 0X8);
    // 0x800B0300: c.le.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl <= ctx->f0.fl;
    // 0x800B0304: nop

    // 0x800B0308: bc1f        L_800B0320
    if (!c1cs) {
        // 0x800B030C: lui         $a1, 0x8011
        ctx->r5 = S32(0X8011 << 16);
            goto L_800B0320;
    }
    // 0x800B030C: lui         $a1, 0x8011
    ctx->r5 = S32(0X8011 << 16);
    // 0x800B0310: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800B0314: lwc1        $f0, 0x55C4($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X55C4);
    // 0x800B0318: sub.s       $f0, $f2, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f2.fl - ctx->f0.fl;
    // 0x800B031C: swc1        $f0, 0x8($s2)
    MEM_W(0X8, ctx->r18) = ctx->f0.u32l;
L_800B0320:
    // 0x800B0320: lhu         $a0, 0xB6($s2)
    ctx->r4 = MEM_HU(ctx->r18, 0XB6);
    // 0x800B0324: lw          $v0, -0x35E4($a1)
    ctx->r2 = MEM_W(ctx->r5, -0X35E4);
    // 0x800B0328: lhu         $v1, 0x180($s2)
    ctx->r3 = MEM_HU(ctx->r18, 0X180);
    // 0x800B032C: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800B0330: lwc1        $f0, 0x55C8($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X55C8);
    // 0x800B0334: sw          $zero, 0x2C($s2)
    MEM_W(0X2C, ctx->r18) = 0;
    // 0x800B0338: ori         $v0, $v0, 0x100
    ctx->r2 = ctx->r2 | 0X100;
    // 0x800B033C: andi        $v1, $v1, 0xFFF6
    ctx->r3 = ctx->r3 & 0XFFF6;
    // 0x800B0340: ori         $v1, $v1, 0x190
    ctx->r3 = ctx->r3 | 0X190;
    // 0x800B0344: sw          $v0, -0x35E4($a1)
    MEM_W(-0X35E4, ctx->r5) = ctx->r2;
    // 0x800B0348: sh          $v1, 0x180($s2)
    MEM_H(0X180, ctx->r18) = ctx->r3;
    // 0x800B034C: jal         0x8004013C
    // 0x800B0350: swc1        $f0, 0x184($s2)
    MEM_W(0X184, ctx->r18) = ctx->f0.u32l;
    func_8004013C(rdram, ctx);
        goto after_8;
    // 0x800B0350: swc1        $f0, 0x184($s2)
    MEM_W(0X184, ctx->r18) = ctx->f0.u32l;
    after_8:
    // 0x800B0354: jal         0x800F2AA4
    // 0x800B0358: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    func_800F2AA4(rdram, ctx);
        goto after_9;
    // 0x800B0358: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    after_9:
    // 0x800B035C: lui         $s0, 0x8014
    ctx->r16 = S32(0X8014 << 16);
    // 0x800B0360: lw          $v1, 0xB8($s2)
    ctx->r3 = MEM_W(ctx->r18, 0XB8);
    // 0x800B0364: addiu       $s0, $s0, -0x72E8
    ctx->r16 = ADD32(ctx->r16, -0X72E8);
    // 0x800B0368: sw          $zero, 0x140($s2)
    MEM_W(0X140, ctx->r18) = 0;
    // 0x800B036C: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x800B0370: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800B0374: sll         $v0, $v0, 4
    ctx->r2 = S32(ctx->r2 << 4);
    // 0x800B0378: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800B037C: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800B0380: addu        $v0, $v0, $s0
    ctx->r2 = ADD32(ctx->r2, ctx->r16);
    // 0x800B0384: lw          $s1, 0x4($v0)
    ctx->r17 = MEM_W(ctx->r2, 0X4);
    // 0x800B0388: lwc1        $f0, 0x4($s2)
    ctx->f0.u32l = MEM_W(ctx->r18, 0X4);
    // 0x800B038C: lwc1        $f2, 0x10($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0X10);
    // 0x800B0390: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x800B0394: swc1        $f0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f0.u32l;
    // 0x800B0398: lwc1        $f0, 0x8($s2)
    ctx->f0.u32l = MEM_W(ctx->r18, 0X8);
    // 0x800B039C: lwc1        $f2, 0x14($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0X14);
    // 0x800B03A0: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x800B03A4: swc1        $f0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f0.u32l;
    // 0x800B03A8: lwc1        $f0, 0xC($s2)
    ctx->f0.u32l = MEM_W(ctx->r18, 0XC);
    // 0x800B03AC: lwc1        $f2, 0x18($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0X18);
    // 0x800B03B0: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x800B03B4: addiu       $a0, $sp, 0x20
    ctx->r4 = ADD32(ctx->r29, 0X20);
    // 0x800B03B8: jal         0x8001CF2C
    // 0x800B03BC: swc1        $f0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f0.u32l;
    func_8001CF2C(rdram, ctx);
        goto after_10;
    // 0x800B03BC: swc1        $f0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f0.u32l;
    after_10:
    // 0x800B03C0: lw          $v1, 0xB8($s2)
    ctx->r3 = MEM_W(ctx->r18, 0XB8);
    // 0x800B03C4: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x800B03C8: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800B03CC: sll         $v0, $v0, 4
    ctx->r2 = S32(ctx->r2 << 4);
    // 0x800B03D0: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800B03D4: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800B03D8: addu        $v0, $v0, $s0
    ctx->r2 = ADD32(ctx->r2, ctx->r16);
    // 0x800B03DC: lw          $v0, 0x4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X4);
    // 0x800B03E0: lhu         $v1, 0x4($v0)
    ctx->r3 = MEM_HU(ctx->r2, 0X4);
    // 0x800B03E4: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x800B03E8: beq         $v1, $v0, L_800B0470
    if (ctx->r3 == ctx->r2) {
        // 0x800B03EC: mov.s       $f2, $f0
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
            goto L_800B0470;
    }
    // 0x800B03EC: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
    // 0x800B03F0: lhu         $v0, 0x0($s1)
    ctx->r2 = MEM_HU(ctx->r17, 0X0);
    // 0x800B03F4: andi        $v0, $v0, 0x10
    ctx->r2 = ctx->r2 & 0X10;
    // 0x800B03F8: bne         $v0, $zero, L_800B0424
    if (ctx->r2 != 0) {
        // 0x800B03FC: addiu       $v0, $zero, 0x2
        ctx->r2 = ADD32(0, 0X2);
            goto L_800B0424;
    }
    // 0x800B03FC: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x800B0400: lhu         $v1, 0x4($s1)
    ctx->r3 = MEM_HU(ctx->r17, 0X4);
    // 0x800B0404: bne         $v1, $v0, L_800B0424
    if (ctx->r3 != ctx->r2) {
        // 0x800B0408: nop
    
            goto L_800B0424;
    }
    // 0x800B0408: nop

    // 0x800B040C: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800B0410: lwc1        $f0, 0x55CC($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X55CC);
    // 0x800B0414: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x800B0418: nop

    // 0x800B041C: bc1t        L_800B0470
    if (c1cs) {
        // 0x800B0420: nop
    
            goto L_800B0470;
    }
    // 0x800B0420: nop

L_800B0424:
    // 0x800B0424: lw          $v0, 0xB8($s2)
    ctx->r2 = MEM_W(ctx->r18, 0XB8);
    // 0x800B0428: sll         $v1, $v0, 5
    ctx->r3 = S32(ctx->r2 << 5);
    // 0x800B042C: subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // 0x800B0430: sll         $v1, $v1, 5
    ctx->r3 = S32(ctx->r3 << 5);
    // 0x800B0434: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x800B0438: addiu       $v0, $v0, -0x75D8
    ctx->r2 = ADD32(ctx->r2, -0X75D8);
    // 0x800B043C: addu        $a0, $v1, $v0
    ctx->r4 = ADD32(ctx->r3, ctx->r2);
    // 0x800B0440: beq         $s1, $a0, L_800B047C
    if (ctx->r17 == ctx->r4) {
        // 0x800B0444: lui         $v0, 0x8013
        ctx->r2 = S32(0X8013 << 16);
            goto L_800B047C;
    }
    // 0x800B0444: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800B0448: lhu         $v0, 0x0($s1)
    ctx->r2 = MEM_HU(ctx->r17, 0X0);
    // 0x800B044C: andi        $v0, $v0, 0x10
    ctx->r2 = ctx->r2 & 0X10;
    // 0x800B0450: beq         $v0, $zero, L_800B0470
    if (ctx->r2 == 0) {
        // 0x800B0454: addiu       $v0, $zero, 0x4
        ctx->r2 = ADD32(0, 0X4);
            goto L_800B0470;
    }
    // 0x800B0454: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // 0x800B0458: lhu         $v1, 0x2($s1)
    ctx->r3 = MEM_HU(ctx->r17, 0X2);
    // 0x800B045C: bne         $v1, $v0, L_800B0470
    if (ctx->r3 != ctx->r2) {
        // 0x800B0460: nop
    
            goto L_800B0470;
    }
    // 0x800B0460: nop

    // 0x800B0464: lw          $v0, 0xC0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0XC0);
    // 0x800B0468: beq         $v0, $a0, L_800B047C
    if (ctx->r2 == ctx->r4) {
        // 0x800B046C: lui         $v0, 0x8013
        ctx->r2 = S32(0X8013 << 16);
            goto L_800B047C;
    }
    // 0x800B046C: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
L_800B0470:
    // 0x800B0470: jal         0x800514A4
    // 0x800B0474: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    func_800514A4(rdram, ctx);
        goto after_11;
    // 0x800B0474: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    after_11:
    // 0x800B0478: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
L_800B047C:
    // 0x800B047C: sw          $zero, 0xC0($s2)
    MEM_W(0XC0, ctx->r18) = 0;
    // 0x800B0480: lw          $v0, 0xB50($v0)
    ctx->r2 = MEM_W(ctx->r2, 0XB50);
    // 0x800B0484: andi        $v0, $v0, 0x60
    ctx->r2 = ctx->r2 & 0X60;
    // 0x800B0488: bne         $v0, $zero, L_800B0500
    if (ctx->r2 != 0) {
        // 0x800B048C: addiu       $s1, $zero, 0xC
        ctx->r17 = ADD32(0, 0XC);
            goto L_800B0500;
    }
    // 0x800B048C: addiu       $s1, $zero, 0xC
    ctx->r17 = ADD32(0, 0XC);
    // 0x800B0490: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800B0494: lw          $v0, -0x35E0($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X35E0);
    // 0x800B0498: bne         $v0, $zero, L_800B0504
    if (ctx->r2 != 0) {
        // 0x800B049C: lui         $v0, 0x8014
        ctx->r2 = S32(0X8014 << 16);
            goto L_800B0504;
    }
    // 0x800B049C: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x800B04A0: lw          $v0, 0x1C4($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X1C4);
    // 0x800B04A4: slt         $v0, $s1, $v0
    ctx->r2 = SIGNED(ctx->r17) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800B04A8: beq         $v0, $zero, L_800B04C8
    if (ctx->r2 == 0) {
        // 0x800B04AC: nop
    
            goto L_800B04C8;
    }
    // 0x800B04AC: nop

    // 0x800B04B0: lbu         $a0, 0xBB($s2)
    ctx->r4 = MEM_BU(ctx->r18, 0XBB);
    // 0x800B04B4: jal         0x80003150
    // 0x800B04B8: nop

    func_80003150(rdram, ctx);
        goto after_12;
    // 0x800B04B8: nop

    after_12:
    // 0x800B04BC: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x800B04C0: bne         $v0, $zero, L_800B0504
    if (ctx->r2 != 0) {
        // 0x800B04C4: lui         $v0, 0x8014
        ctx->r2 = S32(0X8014 << 16);
            goto L_800B0504;
    }
    // 0x800B04C4: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
L_800B04C8:
    // 0x800B04C8: lw          $a0, 0x1C0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X1C0);
    // 0x800B04CC: addiu       $s0, $zero, -0x1
    ctx->r16 = ADD32(0, -0X1);
    // 0x800B04D0: beql        $a0, $s0, L_800B04E4
    if (ctx->r4 == ctx->r16) {
        // 0x800B04D4: lui         $a1, 0x8011
        ctx->r5 = S32(0X8011 << 16);
            goto L_800B04E4;
    }
    goto skip_0;
    // 0x800B04D4: lui         $a1, 0x8011
    ctx->r5 = S32(0X8011 << 16);
    skip_0:
    // 0x800B04D8: jal         0x80002BA8
    // 0x800B04DC: nop

    func_80002BA8(rdram, ctx);
        goto after_13;
    // 0x800B04DC: nop

    after_13:
    // 0x800B04E0: lui         $a1, 0x8011
    ctx->r5 = S32(0X8011 << 16);
L_800B04E4:
    // 0x800B04E4: addiu       $a1, $a1, -0x4430
    ctx->r5 = ADD32(ctx->r5, -0X4430);
    // 0x800B04E8: lbu         $a0, 0xBB($s2)
    ctx->r4 = MEM_BU(ctx->r18, 0XBB);
    // 0x800B04EC: jal         0x80002ADC
    // 0x800B04F0: addiu       $a1, $a1, 0x90
    ctx->r5 = ADD32(ctx->r5, 0X90);
    func_80002ADC(rdram, ctx);
        goto after_14;
    // 0x800B04F0: addiu       $a1, $a1, 0x90
    ctx->r5 = ADD32(ctx->r5, 0X90);
    after_14:
    // 0x800B04F4: beq         $v0, $s0, L_800B0500
    if (ctx->r2 == ctx->r16) {
        // 0x800B04F8: sw          $v0, 0x1C0($s2)
        MEM_W(0X1C0, ctx->r18) = ctx->r2;
            goto L_800B0500;
    }
    // 0x800B04F8: sw          $v0, 0x1C0($s2)
    MEM_W(0X1C0, ctx->r18) = ctx->r2;
    // 0x800B04FC: sw          $s1, 0x1C4($s2)
    MEM_W(0X1C4, ctx->r18) = ctx->r17;
L_800B0500:
    // 0x800B0500: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
L_800B0504:
    // 0x800B0504: addiu       $s1, $v0, -0x7FA8
    ctx->r17 = ADD32(ctx->r2, -0X7FA8);
    // 0x800B0508: addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    // 0x800B050C: lwc1        $f12, 0x4($s2)
    ctx->f12.u32l = MEM_W(ctx->r18, 0X4);
    // 0x800B0510: lwc1        $f14, 0xC($s2)
    ctx->f14.u32l = MEM_W(ctx->r18, 0XC);
    // 0x800B0514: jal         0x80067D90
    // 0x800B0518: addiu       $a3, $sp, 0x58
    ctx->r7 = ADD32(ctx->r29, 0X58);
    func_80067D90(rdram, ctx);
        goto after_15;
    // 0x800B0518: addiu       $a3, $sp, 0x58
    ctx->r7 = ADD32(ctx->r29, 0X58);
    after_15:
    // 0x800B051C: lwc1        $f2, 0x5C($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x800B0520: lwc1        $f0, 0x8($s2)
    ctx->f0.u32l = MEM_W(ctx->r18, 0X8);
    // 0x800B0524: c.le.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl <= ctx->f0.fl;
    // 0x800B0528: nop

    // 0x800B052C: bc1f        L_800B0544
    if (!c1cs) {
        // 0x800B0530: nop
    
            goto L_800B0544;
    }
    // 0x800B0530: nop

    // 0x800B0534: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800B0538: lwc1        $f0, 0x55D0($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X55D0);
    // 0x800B053C: sub.s       $f0, $f2, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f2.fl - ctx->f0.fl;
    // 0x800B0540: swc1        $f0, 0x8($s2)
    MEM_W(0X8, ctx->r18) = ctx->f0.u32l;
L_800B0544:
    // 0x800B0544: lbu         $v0, 0x24C($s2)
    ctx->r2 = MEM_BU(ctx->r18, 0X24C);
    // 0x800B0548: beq         $v0, $zero, L_800B0560
    if (ctx->r2 == 0) {
        // 0x800B054C: andi        $s0, $s3, 0xFF
        ctx->r16 = ctx->r19 & 0XFF;
            goto L_800B0560;
    }
    // 0x800B054C: andi        $s0, $s3, 0xFF
    ctx->r16 = ctx->r19 & 0XFF;
    // 0x800B0550: sb          $zero, 0x24C($s2)
    MEM_B(0X24C, ctx->r18) = 0;
    // 0x800B0554: jal         0x80098DE0
    // 0x800B0558: addiu       $a0, $s2, 0x208
    ctx->r4 = ADD32(ctx->r18, 0X208);
    func_80098DE0(rdram, ctx);
        goto after_16;
    // 0x800B0558: addiu       $a0, $s2, 0x208
    ctx->r4 = ADD32(ctx->r18, 0X208);
    after_16:
    // 0x800B055C: andi        $s0, $s3, 0xFF
    ctx->r16 = ctx->r19 & 0XFF;
L_800B0560:
    // 0x800B0560: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800B0564: bnel        $s0, $v0, L_800B05C4
    if (ctx->r16 != ctx->r2) {
        // 0x800B0568: addiu       $s0, $s2, 0x4
        ctx->r16 = ADD32(ctx->r18, 0X4);
            goto L_800B05C4;
    }
    goto skip_1;
    // 0x800B0568: addiu       $s0, $s2, 0x4
    ctx->r16 = ADD32(ctx->r18, 0X4);
    skip_1:
    // 0x800B056C: lwc1        $f12, 0x4($s2)
    ctx->f12.u32l = MEM_W(ctx->r18, 0X4);
    // 0x800B0570: lwc1        $f14, 0xC($s2)
    ctx->f14.u32l = MEM_W(ctx->r18, 0XC);
    // 0x800B0574: jal         0x800698F4
    // 0x800B0578: addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    func_800698F4(rdram, ctx);
        goto after_17;
    // 0x800B0578: addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    after_17:
    // 0x800B057C: bne         $v0, $s0, L_800B05C4
    if (ctx->r2 != ctx->r16) {
        // 0x800B0580: addiu       $s0, $s2, 0x4
        ctx->r16 = ADD32(ctx->r18, 0X4);
            goto L_800B05C4;
    }
    // 0x800B0580: addiu       $s0, $s2, 0x4
    ctx->r16 = ADD32(ctx->r18, 0X4);
    // 0x800B0584: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800B0588: lwc1        $f0, 0x55D4($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X55D4);
    // 0x800B058C: lui         $a1, 0x3E4C
    ctx->r5 = S32(0X3E4C << 16);
    // 0x800B0590: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    // 0x800B0594: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800B0598: lwc1        $f2, 0x55D8($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X55D8);
    // 0x800B059C: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x800B05A0: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800B05A4: lwc1        $f0, 0x55DC($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X55DC);
    // 0x800B05A8: addiu       $a0, $s2, 0x4
    ctx->r4 = ADD32(ctx->r18, 0X4);
    // 0x800B05AC: swc1        $f2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f2.u32l;
    // 0x800B05B0: addu        $a3, $a2, $zero
    ctx->r7 = ADD32(ctx->r6, 0);
    // 0x800B05B4: jal         0x80077858
    // 0x800B05B8: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    func_80077858(rdram, ctx);
        goto after_18;
    // 0x800B05B8: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    after_18:
    // 0x800B05BC: j           L_800B06EC
    // 0x800B05C0: nop

        goto L_800B06EC;
    // 0x800B05C0: nop

L_800B05C4:
    // 0x800B05C4: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800B05C8: lwc1        $f20, 0x55E0($at)
    ctx->f20.u32l = MEM_W(ctx->r1, 0X55E0);
    // 0x800B05CC: lui         $a3, 0x40B4
    ctx->r7 = S32(0X40B4 << 16);
    // 0x800B05D0: lhu         $a1, 0xB6($s2)
    ctx->r5 = MEM_HU(ctx->r18, 0XB6);
    // 0x800B05D4: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800B05D8: lwc1        $f0, 0x55E4($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X55E4);
    // 0x800B05DC: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x800B05E0: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x800B05E4: jal         0x8007764C
    // 0x800B05E8: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    func_8007764C(rdram, ctx);
        goto after_19;
    // 0x800B05E8: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    after_19:
    // 0x800B05EC: ori         $a0, $zero, 0x8002
    ctx->r4 = 0 | 0X8002;
    // 0x800B05F0: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x800B05F4: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // 0x800B05F8: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800B05FC: lwc1        $f22, 0x55E8($at)
    ctx->f22.u32l = MEM_W(ctx->r1, 0X55E8);
    // 0x800B0600: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800B0604: lwc1        $f24, 0x55EC($at)
    ctx->f24.u32l = MEM_W(ctx->r1, 0X55EC);
    // 0x800B0608: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800B060C: lwc1        $f0, 0x55F0($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X55F0);
    // 0x800B0610: addu        $a3, $a2, $zero
    ctx->r7 = ADD32(ctx->r6, 0);
    // 0x800B0614: swc1        $f20, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f20.u32l;
    // 0x800B0618: swc1        $f22, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f22.u32l;
    // 0x800B061C: swc1        $f24, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f24.u32l;
    // 0x800B0620: jal         0x80072684
    // 0x800B0624: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    func_80072684(rdram, ctx);
        goto after_20;
    // 0x800B0624: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    after_20:
    // 0x800B0628: ori         $a0, $zero, 0x8001
    ctx->r4 = 0 | 0X8001;
    // 0x800B062C: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x800B0630: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // 0x800B0634: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800B0638: lwc1        $f0, 0x55F4($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X55F4);
    // 0x800B063C: addiu       $a3, $sp, 0x50
    ctx->r7 = ADD32(ctx->r29, 0X50);
    // 0x800B0640: swc1        $f22, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f22.u32l;
    // 0x800B0644: swc1        $f20, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f20.u32l;
    // 0x800B0648: swc1        $f24, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f24.u32l;
    // 0x800B064C: jal         0x80072684
    // 0x800B0650: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    func_80072684(rdram, ctx);
        goto after_21;
    // 0x800B0650: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    after_21:
    // 0x800B0654: jal         0x80003430
    // 0x800B0658: addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
    rand_recomp(rdram, ctx);
        goto after_22;
    // 0x800B0658: addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
    after_22:
    // 0x800B065C: lui         $v1, 0x5555
    ctx->r3 = S32(0X5555 << 16);
    // 0x800B0660: ori         $v1, $v1, 0x5556
    ctx->r3 = ctx->r3 | 0X5556;
    // 0x800B0664: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x800B0668: sra         $a0, $v0, 16
    ctx->r4 = S32(SIGNED(ctx->r2) >> 16);
    // 0x800B066C: mult        $a0, $v1
    result = S64(S32(ctx->r4)) * S64(S32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800B0670: sra         $v0, $v0, 31
    ctx->r2 = S32(SIGNED(ctx->r2) >> 31);
    // 0x800B0674: mfhi        $t0
    ctx->r8 = hi;
    // 0x800B0678: subu        $v0, $t0, $v0
    ctx->r2 = SUB32(ctx->r8, ctx->r2);
    // 0x800B067C: sll         $v1, $v0, 1
    ctx->r3 = S32(ctx->r2 << 1);
    // 0x800B0680: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x800B0684: subu        $a0, $a0, $v1
    ctx->r4 = SUB32(ctx->r4, ctx->r3);
    // 0x800B0688: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x800B068C: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    // 0x800B0690: addiu       $s1, $a0, 0x2
    ctx->r17 = ADD32(ctx->r4, 0X2);
    // 0x800B0694: blez        $s1, L_800B06EC
    if (SIGNED(ctx->r17) <= 0) {
        // 0x800B0698: nop
    
            goto L_800B06EC;
    }
    // 0x800B0698: nop

    // 0x800B069C: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800B06A0: lwc1        $f22, 0x55F8($at)
    ctx->f22.u32l = MEM_W(ctx->r1, 0X55F8);
    // 0x800B06A4: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800B06A8: lwc1        $f20, 0x55FC($at)
    ctx->f20.u32l = MEM_W(ctx->r1, 0X55FC);
L_800B06AC:
    // 0x800B06AC: jal         0x80003430
    // 0x800B06B0: nop

    rand_recomp(rdram, ctx);
        goto after_23;
    // 0x800B06B0: nop

    after_23:
    // 0x800B06B4: andi        $v0, $v0, 0x7F
    ctx->r2 = ctx->r2 & 0X7F;
    // 0x800B06B8: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x800B06BC: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x800B06C0: sub.s       $f0, $f0, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f22.fl;
    // 0x800B06C4: div.s       $f0, $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f20.fl);
    // 0x800B06C8: add.s       $f0, $f0, $f24
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f24.fl;
    // 0x800B06CC: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x800B06D0: addiu       $a0, $s2, 0x4
    ctx->r4 = ADD32(ctx->r18, 0X4);
    // 0x800B06D4: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x800B06D8: jal         0x800612A4
    // 0x800B06DC: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    func_800612A4(rdram, ctx);
        goto after_24;
    // 0x800B06DC: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    after_24:
    // 0x800B06E0: slt         $v0, $s0, $s1
    ctx->r2 = SIGNED(ctx->r16) < SIGNED(ctx->r17) ? 1 : 0;
    // 0x800B06E4: bne         $v0, $zero, L_800B06AC
    if (ctx->r2 != 0) {
        // 0x800B06E8: nop
    
            goto L_800B06AC;
    }
    // 0x800B06E8: nop

L_800B06EC:
    // 0x800B06EC: jal         0x80003430
    // 0x800B06F0: addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
    rand_recomp(rdram, ctx);
        goto after_25;
    // 0x800B06F0: addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
    after_25:
    // 0x800B06F4: lui         $v1, 0x6666
    ctx->r3 = S32(0X6666 << 16);
    // 0x800B06F8: ori         $v1, $v1, 0x6667
    ctx->r3 = ctx->r3 | 0X6667;
    // 0x800B06FC: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x800B0700: sra         $a0, $v0, 16
    ctx->r4 = S32(SIGNED(ctx->r2) >> 16);
    // 0x800B0704: mult        $a0, $v1
    result = S64(S32(ctx->r4)) * S64(S32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800B0708: sra         $v0, $v0, 31
    ctx->r2 = S32(SIGNED(ctx->r2) >> 31);
    // 0x800B070C: mfhi        $t0
    ctx->r8 = hi;
    // 0x800B0710: sra         $v1, $t0, 1
    ctx->r3 = S32(SIGNED(ctx->r8) >> 1);
    // 0x800B0714: subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // 0x800B0718: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x800B071C: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800B0720: subu        $a0, $a0, $v0
    ctx->r4 = SUB32(ctx->r4, ctx->r2);
    // 0x800B0724: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x800B0728: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    // 0x800B072C: addiu       $s1, $a0, 0xA
    ctx->r17 = ADD32(ctx->r4, 0XA);
    // 0x800B0730: blez        $s1, L_800B0828
    if (SIGNED(ctx->r17) <= 0) {
        // 0x800B0734: addiu       $s3, $sp, 0x30
        ctx->r19 = ADD32(ctx->r29, 0X30);
            goto L_800B0828;
    }
    // 0x800B0734: addiu       $s3, $sp, 0x30
    ctx->r19 = ADD32(ctx->r29, 0X30);
    // 0x800B0738: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800B073C: lwc1        $f24, 0x5600($at)
    ctx->f24.u32l = MEM_W(ctx->r1, 0X5600);
    // 0x800B0740: addiu       $a0, $sp, 0x40
    ctx->r4 = ADD32(ctx->r29, 0X40);
L_800B0744:
    // 0x800B0744: addu        $a1, $s3, $zero
    ctx->r5 = ADD32(ctx->r19, 0);
    // 0x800B0748: lui         $a2, 0x4000
    ctx->r6 = S32(0X4000 << 16);
    // 0x800B074C: addiu       $a3, $zero, 0x3C
    ctx->r7 = ADD32(0, 0X3C);
    // 0x800B0750: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x800B0754: jal         0x8007202C
    // 0x800B0758: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    func_8007202C(rdram, ctx);
        goto after_26;
    // 0x800B0758: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    after_26:
    // 0x800B075C: lui         $a1, 0x4040
    ctx->r5 = S32(0X4040 << 16);
    // 0x800B0760: lui         $a2, 0x4080
    ctx->r6 = S32(0X4080 << 16);
    // 0x800B0764: jal         0x80072300
    // 0x800B0768: addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    func_80072300(rdram, ctx);
        goto after_27;
    // 0x800B0768: addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    after_27:
    // 0x800B076C: jal         0x80003430
    // 0x800B0770: nop

    rand_recomp(rdram, ctx);
        goto after_28;
    // 0x800B0770: nop

    after_28:
    // 0x800B0774: andi        $v0, $v0, 0x7F
    ctx->r2 = ctx->r2 & 0X7F;
    // 0x800B0778: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x800B077C: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x800B0780: sub.s       $f0, $f0, $f24
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f24.fl;
    // 0x800B0784: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800B0788: lwc1        $f2, 0x5604($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X5604);
    // 0x800B078C: div.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f2.fl);
    // 0x800B0790: abs.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f22.fl = fabsf(ctx->f0.fl);
    // 0x800B0794: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800B0798: lwc1        $f0, 0x5608($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X5608);
    // 0x800B079C: jal         0x80003430
    // 0x800B07A0: add.s       $f22, $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f22.fl = ctx->f22.fl + ctx->f0.fl;
    rand_recomp(rdram, ctx);
        goto after_29;
    // 0x800B07A0: add.s       $f22, $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f22.fl = ctx->f22.fl + ctx->f0.fl;
    after_29:
    // 0x800B07A4: andi        $v0, $v0, 0x7F
    ctx->r2 = ctx->r2 & 0X7F;
    // 0x800B07A8: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x800B07AC: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x800B07B0: sub.s       $f0, $f0, $f24
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f24.fl;
    // 0x800B07B4: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800B07B8: lwc1        $f2, 0x560C($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X560C);
    // 0x800B07BC: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x800B07C0: abs.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f20.fl = fabsf(ctx->f0.fl);
    // 0x800B07C4: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800B07C8: lwc1        $f0, 0x5610($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X5610);
    // 0x800B07CC: jal         0x80003430
    // 0x800B07D0: add.s       $f20, $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f20.fl = ctx->f20.fl + ctx->f0.fl;
    rand_recomp(rdram, ctx);
        goto after_30;
    // 0x800B07D0: add.s       $f20, $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f20.fl = ctx->f20.fl + ctx->f0.fl;
    after_30:
    // 0x800B07D4: andi        $v0, $v0, 0x7F
    ctx->r2 = ctx->r2 & 0X7F;
    // 0x800B07D8: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x800B07DC: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x800B07E0: sub.s       $f0, $f0, $f24
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f24.fl;
    // 0x800B07E4: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800B07E8: lwc1        $f2, 0x5614($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X5614);
    // 0x800B07EC: div.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f2.fl);
    // 0x800B07F0: abs.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = fabsf(ctx->f0.fl);
    // 0x800B07F4: addiu       $a0, $s2, 0x4
    ctx->r4 = ADD32(ctx->r18, 0X4);
    // 0x800B07F8: addu        $a1, $s3, $zero
    ctx->r5 = ADD32(ctx->r19, 0);
    // 0x800B07FC: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800B0800: lwc1        $f0, 0x5618($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X5618);
    // 0x800B0804: mfc1        $a2, $f22
    ctx->r6 = (int32_t)ctx->f22.u32l;
    // 0x800B0808: add.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x800B080C: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x800B0810: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x800B0814: jal         0x80072384
    // 0x800B0818: swc1        $f2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f2.u32l;
    func_80072384(rdram, ctx);
        goto after_31;
    // 0x800B0818: swc1        $f2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f2.u32l;
    after_31:
    // 0x800B081C: slt         $v0, $s0, $s1
    ctx->r2 = SIGNED(ctx->r16) < SIGNED(ctx->r17) ? 1 : 0;
    // 0x800B0820: bne         $v0, $zero, L_800B0744
    if (ctx->r2 != 0) {
        // 0x800B0824: addiu       $a0, $sp, 0x40
        ctx->r4 = ADD32(ctx->r29, 0X40);
            goto L_800B0744;
    }
    // 0x800B0824: addiu       $a0, $sp, 0x40
    ctx->r4 = ADD32(ctx->r29, 0X40);
L_800B0828:
    // 0x800B0828: lw          $ra, 0x90($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X90);
    // 0x800B082C: lw          $s3, 0x8C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X8C);
    // 0x800B0830: lw          $s2, 0x88($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X88);
    // 0x800B0834: lw          $s1, 0x84($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X84);
    // 0x800B0838: lw          $s0, 0x80($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X80);
    // 0x800B083C: ldc1        $f24, 0xA8($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0XA8);
    // 0x800B0840: ldc1        $f22, 0xA0($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0XA0);
    // 0x800B0844: ldc1        $f20, 0x98($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X98);
    // 0x800B0848: jr          $ra
    // 0x800B084C: addiu       $sp, $sp, 0xB0
    ctx->r29 = ADD32(ctx->r29, 0XB0);
    return;
    // 0x800B084C: addiu       $sp, $sp, 0xB0
    ctx->r29 = ADD32(ctx->r29, 0XB0);
;}
RECOMP_FUNC void func_800B0650(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B0650: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x800B0654: lbu         $v0, -0x253C($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X253C);
    // 0x800B0658: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800B065C: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x800B0660: addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
    // 0x800B0664: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800B0668: sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // 0x800B066C: addiu       $v0, $v0, -0x2
    ctx->r2 = ADD32(ctx->r2, -0X2);
    // 0x800B0670: sltiu       $v0, $v0, 0x2
    ctx->r2 = ctx->r2 < 0X2 ? 1 : 0;
    // 0x800B0674: beq         $v0, $zero, L_800B06C4
    if (ctx->r2 == 0) {
        // 0x800B0678: sw          $s1, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r17;
            goto L_800B06C4;
    }
    // 0x800B0678: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x800B067C: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x800B0680: lbu         $v0, -0x253B($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X253B);
    // 0x800B0684: bne         $v0, $zero, L_800B06C8
    if (ctx->r2 != 0) {
        // 0x800B0688: andi        $v0, $s0, 0xFF
        ctx->r2 = ctx->r16 & 0XFF;
            goto L_800B06C8;
    }
    // 0x800B0688: andi        $v0, $s0, 0xFF
    ctx->r2 = ctx->r16 & 0XFF;
    // 0x800B068C: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x800B0690: lb          $v0, -0x2540($v0)
    ctx->r2 = MEM_B(ctx->r2, -0X2540);
    // 0x800B0694: bne         $v0, $zero, L_800B06C8
    if (ctx->r2 != 0) {
        // 0x800B0698: andi        $v0, $s0, 0xFF
        ctx->r2 = ctx->r16 & 0XFF;
            goto L_800B06C8;
    }
    // 0x800B0698: andi        $v0, $s0, 0xFF
    ctx->r2 = ctx->r16 & 0XFF;
    // 0x800B069C: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x800B06A0: lbu         $a0, -0x2538($v0)
    ctx->r4 = MEM_BU(ctx->r2, -0X2538);
    // 0x800B06A4: jal         0x80079F50
    // 0x800B06A8: nop

    getControllerNewButtonsPressed(rdram, ctx);
        goto after_0;
    // 0x800B06A8: nop

    after_0:
    // 0x800B06AC: andi        $v0, $v0, 0x4000
    ctx->r2 = ctx->r2 & 0X4000;
    // 0x800B06B0: beq         $v0, $zero, L_800B06C4
    if (ctx->r2 == 0) {
        // 0x800B06B4: lui         $v0, 0x800D
        ctx->r2 = S32(0X800D << 16);
            goto L_800B06C4;
    }
    // 0x800B06B4: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x800B06B8: lbu         $v0, -0x2542($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X2542);
    // 0x800B06BC: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x800B06C0: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
L_800B06C4:
    // 0x800B06C4: andi        $v0, $s0, 0xFF
    ctx->r2 = ctx->r16 & 0XFF;
L_800B06C8:
    // 0x800B06C8: bne         $v0, $zero, L_800B06E0
    if (ctx->r2 != 0) {
        // 0x800B06CC: lui         $v0, 0x800D
        ctx->r2 = S32(0X800D << 16);
            goto L_800B06E0;
    }
    // 0x800B06CC: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x800B06D0: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x800B06D4: lbu         $v0, -0x2542($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X2542);
    // 0x800B06D8: beq         $v0, $zero, L_800B07DC
    if (ctx->r2 == 0) {
        // 0x800B06DC: lui         $v0, 0x800D
        ctx->r2 = S32(0X800D << 16);
            goto L_800B07DC;
    }
    // 0x800B06DC: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
L_800B06E0:
    // 0x800B06E0: lw          $a0, -0x2058($v0)
    ctx->r4 = MEM_W(ctx->r2, -0X2058);
    // 0x800B06E4: jal         0x80063EE4
    // 0x800B06E8: nop

    func_80063EE4(rdram, ctx);
        goto after_1;
    // 0x800B06E8: nop

    after_1:
    // 0x800B06EC: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x800B06F0: bne         $v0, $zero, L_800B07DC
    if (ctx->r2 != 0) {
        // 0x800B06F4: lui         $s2, 0x800D
        ctx->r18 = S32(0X800D << 16);
            goto L_800B07DC;
    }
    // 0x800B06F4: lui         $s2, 0x800D
    ctx->r18 = S32(0X800D << 16);
    // 0x800B06F8: lbu         $v0, -0x2545($s2)
    ctx->r2 = MEM_BU(ctx->r18, -0X2545);
    // 0x800B06FC: beq         $v0, $zero, L_800B073C
    if (ctx->r2 == 0) {
        // 0x800B0700: lui         $v0, 0x800D
        ctx->r2 = S32(0X800D << 16);
            goto L_800B073C;
    }
    // 0x800B0700: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x800B0704: lw          $a0, -0x2054($v0)
    ctx->r4 = MEM_W(ctx->r2, -0X2054);
    // 0x800B0708: jal         0x80063F7C
    // 0x800B070C: lui         $s1, 0x800D
    ctx->r17 = S32(0X800D << 16);
    func_80063F7C(rdram, ctx);
        goto after_2;
    // 0x800B070C: lui         $s1, 0x800D
    ctx->r17 = S32(0X800D << 16);
    after_2:
    // 0x800B0710: lw          $a0, -0x3900($s1)
    ctx->r4 = MEM_W(ctx->r17, -0X3900);
    // 0x800B0714: addiu       $s0, $zero, -0x1
    ctx->r16 = ADD32(0, -0X1);
    // 0x800B0718: beq         $a0, $s0, L_800B0730
    if (ctx->r4 == ctx->r16) {
        // 0x800B071C: lui         $v1, 0x800D
        ctx->r3 = S32(0X800D << 16);
            goto L_800B0730;
    }
    // 0x800B071C: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x800B0720: jal         0x800894F0
    // 0x800B0724: nop

    func_800894F0(rdram, ctx);
        goto after_3;
    // 0x800B0724: nop

    after_3:
    // 0x800B0728: sw          $s0, -0x3900($s1)
    MEM_W(-0X3900, ctx->r17) = ctx->r16;
    // 0x800B072C: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
L_800B0730:
    // 0x800B0730: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800B0734: sb          $zero, -0x2545($s2)
    MEM_B(-0X2545, ctx->r18) = 0;
    // 0x800B0738: sb          $v0, -0x2544($v1)
    MEM_B(-0X2544, ctx->r3) = ctx->r2;
L_800B073C:
    // 0x800B073C: lui         $s0, 0x800D
    ctx->r16 = S32(0X800D << 16);
    // 0x800B0740: lbu         $v1, -0x2539($s0)
    ctx->r3 = MEM_BU(ctx->r16, -0X2539);
    // 0x800B0744: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800B0748: bne         $v1, $v0, L_800B079C
    if (ctx->r3 != ctx->r2) {
        // 0x800B074C: nop
    
            goto L_800B079C;
    }
    // 0x800B074C: nop

    // 0x800B0750: jal         0x8005589C
    // 0x800B0754: addiu       $a0, $zero, 0x39
    ctx->r4 = ADD32(0, 0X39);
    getGameOrFrontText(rdram, ctx);
        goto after_4;
    // 0x800B0754: addiu       $a0, $zero, 0x39
    ctx->r4 = ADD32(0, 0X39);
    after_4:
    // 0x800B0758: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x800B075C: lw          $a0, -0x2058($v1)
    ctx->r4 = MEM_W(ctx->r3, -0X2058);
    // 0x800B0760: jal         0x80062854
    // 0x800B0764: addu        $a1, $v0, $zero
    ctx->r5 = ADD32(ctx->r2, 0);
    func_80062854(rdram, ctx);
        goto after_5;
    // 0x800B0764: addu        $a1, $v0, $zero
    ctx->r5 = ADD32(ctx->r2, 0);
    after_5:
    // 0x800B0768: addiu       $a0, $zero, 0x19
    ctx->r4 = ADD32(0, 0X19);
    // 0x800B076C: addiu       $a1, $zero, 0x5F
    ctx->r5 = ADD32(0, 0X5F);
    // 0x800B0770: jal         0x80087EE8
    // 0x800B0774: addiu       $a2, $zero, 0x40
    ctx->r6 = ADD32(0, 0X40);
    func_80087EE8(rdram, ctx);
        goto after_6;
    // 0x800B0774: addiu       $a2, $zero, 0x40
    ctx->r6 = ADD32(0, 0X40);
    after_6:
    // 0x800B0778: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x800B077C: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800B0780: lwc1        $f0, 0x5A1C($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X5A1C);
    // 0x800B0784: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x800B0788: sb          $v0, -0x253C($v1)
    MEM_B(-0X253C, ctx->r3) = ctx->r2;
    // 0x800B078C: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x800B0790: sb          $zero, -0x2539($s0)
    MEM_B(-0X2539, ctx->r16) = 0;
    // 0x800B0794: j           L_800B07DC
    // 0x800B0798: swc1        $f0, -0x1958($v0)
    MEM_W(-0X1958, ctx->r2) = ctx->f0.u32l;
        goto L_800B07DC;
    // 0x800B0798: swc1        $f0, -0x1958($v0)
    MEM_W(-0X1958, ctx->r2) = ctx->f0.u32l;
L_800B079C:
    // 0x800B079C: jal         0x800B4264
    // 0x800B07A0: nop

    func_800B4264(rdram, ctx);
        goto after_7;
    // 0x800B07A0: nop

    after_7:
    // 0x800B07A4: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x800B07A8: bne         $v0, $zero, L_800B07DC
    if (ctx->r2 != 0) {
        // 0x800B07AC: nop
    
            goto L_800B07DC;
    }
    // 0x800B07AC: nop

    // 0x800B07B0: jal         0x800B2564
    // 0x800B07B4: nop

    func_800B2564(rdram, ctx);
        goto after_8;
    // 0x800B07B4: nop

    after_8:
    // 0x800B07B8: lui         $a0, 0xFF
    ctx->r4 = S32(0XFF << 16);
    // 0x800B07BC: ori         $a0, $a0, 0xFFFE
    ctx->r4 = ctx->r4 | 0XFFFE;
    // 0x800B07C0: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x800B07C4: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // 0x800B07C8: sb          $v0, -0x253C($v1)
    MEM_B(-0X253C, ctx->r3) = ctx->r2;
    // 0x800B07CC: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x800B07D0: sb          $zero, -0x253B($v0)
    MEM_B(-0X253B, ctx->r2) = 0;
    // 0x800B07D4: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x800B07D8: sw          $a0, -0x2534($v0)
    MEM_W(-0X2534, ctx->r2) = ctx->r4;
L_800B07DC:
    // 0x800B07DC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800B07E0: lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X18);
    // 0x800B07E4: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x800B07E8: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x800B07EC: jr          $ra
    // 0x800B07F0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x800B07F0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_800B07F4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B07F4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800B07F8: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x800B07FC: lui         $s0, 0x800D
    ctx->r16 = S32(0X800D << 16);
    // 0x800B0800: lbu         $v0, -0x2544($s0)
    ctx->r2 = MEM_BU(ctx->r16, -0X2544);
    // 0x800B0804: beq         $v0, $zero, L_800B0834
    if (ctx->r2 == 0) {
        // 0x800B0808: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_800B0834;
    }
    // 0x800B0808: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800B080C: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x800B0810: lw          $a0, -0x2054($v0)
    ctx->r4 = MEM_W(ctx->r2, -0X2054);
    // 0x800B0814: jal         0x80063F9C
    // 0x800B0818: nop

    func_80063F9C(rdram, ctx);
        goto after_0;
    // 0x800B0818: nop

    after_0:
    // 0x800B081C: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x800B0820: beq         $v0, $zero, L_800B0834
    if (ctx->r2 == 0) {
        // 0x800B0824: lui         $v1, 0x800D
        ctx->r3 = S32(0X800D << 16);
            goto L_800B0834;
    }
    // 0x800B0824: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x800B0828: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800B082C: sb          $v0, -0x2540($v1)
    MEM_B(-0X2540, ctx->r3) = ctx->r2;
    // 0x800B0830: sb          $zero, -0x2544($s0)
    MEM_B(-0X2544, ctx->r16) = 0;
L_800B0834:
    // 0x800B0834: lui         $a0, 0x800D
    ctx->r4 = S32(0X800D << 16);
    // 0x800B0838: lb          $v1, -0x2540($a0)
    ctx->r3 = MEM_B(ctx->r4, -0X2540);
    // 0x800B083C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x800B0840: bnel        $v1, $v0, L_800B088C
    if (ctx->r3 != ctx->r2) {
        // 0x800B0844: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_800B088C;
    }
    goto skip_0;
    // 0x800B0844: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_0:
    // 0x800B0848: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x800B084C: lwc1        $f2, -0x24FC($v1)
    ctx->f2.u32l = MEM_W(ctx->r3, -0X24FC);
    // 0x800B0850: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800B0854: lwc1        $f0, 0x5A20($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X5A20);
    // 0x800B0858: c.le.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl <= ctx->f0.fl;
    // 0x800B085C: nop

    // 0x800B0860: bc1f        L_800B0874
    if (!c1cs) {
        // 0x800B0864: lui         $v0, 0x800D
        ctx->r2 = S32(0X800D << 16);
            goto L_800B0874;
    }
    // 0x800B0864: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x800B0868: swc1        $f0, -0x24FC($v1)
    MEM_W(-0X24FC, ctx->r3) = ctx->f0.u32l;
    // 0x800B086C: j           L_800B08E4
    // 0x800B0870: sb          $zero, -0x2540($a0)
    MEM_B(-0X2540, ctx->r4) = 0;
        goto L_800B08E4;
    // 0x800B0870: sb          $zero, -0x2540($a0)
    MEM_B(-0X2540, ctx->r4) = 0;
L_800B0874:
    // 0x800B0874: lwc1        $f0, -0x24F0($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, -0X24F0);
    // 0x800B0878: sub.s       $f0, $f2, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f2.fl - ctx->f0.fl;
    // 0x800B087C: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x800B0880: c.le.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl <= ctx->f2.fl;
    // 0x800B0884: j           L_800B08D8
    // 0x800B0888: swc1        $f0, -0x24FC($v1)
    MEM_W(-0X24FC, ctx->r3) = ctx->f0.u32l;
        goto L_800B08D8;
    // 0x800B0888: swc1        $f0, -0x24FC($v1)
    MEM_W(-0X24FC, ctx->r3) = ctx->f0.u32l;
L_800B088C:
    // 0x800B088C: bne         $v1, $v0, L_800B08E4
    if (ctx->r3 != ctx->r2) {
        // 0x800B0890: nop
    
            goto L_800B08E4;
    }
    // 0x800B0890: nop

    // 0x800B0894: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x800B0898: lwc1        $f4, -0x24FC($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, -0X24FC);
    // 0x800B089C: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800B08A0: lwc1        $f2, 0x5A24($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X5A24);
    // 0x800B08A4: c.le.s      $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f2.fl <= ctx->f4.fl;
    // 0x800B08A8: nop

    // 0x800B08AC: bc1f        L_800B08C4
    if (!c1cs) {
        // 0x800B08B0: lui         $v0, 0x800D
        ctx->r2 = S32(0X800D << 16);
            goto L_800B08C4;
    }
    // 0x800B08B0: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x800B08B4: swc1        $f2, -0x24FC($v1)
    MEM_W(-0X24FC, ctx->r3) = ctx->f2.u32l;
    // 0x800B08B8: sb          $zero, -0x2540($a0)
    MEM_B(-0X2540, ctx->r4) = 0;
    // 0x800B08BC: j           L_800B08E4
    // 0x800B08C0: sb          $zero, -0x2545($v0)
    MEM_B(-0X2545, ctx->r2) = 0;
        goto L_800B08E4;
    // 0x800B08C0: sb          $zero, -0x2545($v0)
    MEM_B(-0X2545, ctx->r2) = 0;
L_800B08C4:
    // 0x800B08C4: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x800B08C8: lwc1        $f0, -0x24F0($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, -0X24F0);
    // 0x800B08CC: add.s       $f0, $f4, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f4.fl + ctx->f0.fl;
    // 0x800B08D0: swc1        $f0, -0x24FC($v1)
    MEM_W(-0X24FC, ctx->r3) = ctx->f0.u32l;
    // 0x800B08D4: c.le.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl <= ctx->f0.fl;
L_800B08D8:
    // 0x800B08D8: nop

    // 0x800B08DC: bc1tl       L_800B08E4
    if (c1cs) {
        // 0x800B08E0: swc1        $f2, -0x24FC($v1)
        MEM_W(-0X24FC, ctx->r3) = ctx->f2.u32l;
            goto L_800B08E4;
    }
    goto skip_1;
    // 0x800B08E0: swc1        $f2, -0x24FC($v1)
    MEM_W(-0X24FC, ctx->r3) = ctx->f2.u32l;
    skip_1:
L_800B08E4:
    // 0x800B08E4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800B08E8: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x800B08EC: jr          $ra
    // 0x800B08F0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x800B08F0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_800B0850(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B0850: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800B0854: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800B0858: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x800B085C: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800B0860: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800B0864: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x800B0868: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x800B086C: lw          $v1, 0xB8($s0)
    ctx->r3 = MEM_W(ctx->r16, 0XB8);
    // 0x800B0870: addiu       $a0, $a0, 0x7DB8
    ctx->r4 = ADD32(ctx->r4, 0X7DB8);
    // 0x800B0874: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x800B0878: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800B087C: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800B0880: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800B0884: sll         $v0, $v0, 5
    ctx->r2 = S32(ctx->r2 << 5);
    // 0x800B0888: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x800B088C: lhu         $v1, 0x184($v0)
    ctx->r3 = MEM_HU(ctx->r2, 0X184);
    // 0x800B0890: andi        $v0, $v1, 0x8
    ctx->r2 = ctx->r3 & 0X8;
    // 0x800B0894: bne         $v0, $zero, L_800B0A70
    if (ctx->r2 != 0) {
        // 0x800B0898: andi        $v0, $v1, 0x10
        ctx->r2 = ctx->r3 & 0X10;
            goto L_800B0A70;
    }
    // 0x800B0898: andi        $v0, $v1, 0x10
    ctx->r2 = ctx->r3 & 0X10;
    // 0x800B089C: bne         $v0, $zero, L_800B0A70
    if (ctx->r2 != 0) {
        // 0x800B08A0: andi        $v0, $v1, 0x20
        ctx->r2 = ctx->r3 & 0X20;
            goto L_800B0A70;
    }
    // 0x800B08A0: andi        $v0, $v1, 0x20
    ctx->r2 = ctx->r3 & 0X20;
    // 0x800B08A4: bne         $v0, $zero, L_800B0A70
    if (ctx->r2 != 0) {
        // 0x800B08A8: nop
    
            goto L_800B0A70;
    }
    // 0x800B08A8: nop

    // 0x800B08AC: jal         0x800FC108
    // 0x800B08B0: nop

    func_800FC108(rdram, ctx);
        goto after_0;
    // 0x800B08B0: nop

    after_0:
    // 0x800B08B4: jal         0x800AD320
    // 0x800B08B8: nop

    func_800AD320(rdram, ctx);
        goto after_1;
    // 0x800B08B8: nop

    after_1:
    // 0x800B08BC: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x800B08C0: lw          $v0, -0x35E4($a0)
    ctx->r2 = MEM_W(ctx->r4, -0X35E4);
    // 0x800B08C4: lhu         $v1, 0x180($s0)
    ctx->r3 = MEM_HU(ctx->r16, 0X180);
    // 0x800B08C8: ori         $v0, $v0, 0x100
    ctx->r2 = ctx->r2 | 0X100;
    // 0x800B08CC: andi        $v1, $v1, 0xFFFE
    ctx->r3 = ctx->r3 & 0XFFFE;
    // 0x800B08D0: ori         $v1, $v1, 0x8
    ctx->r3 = ctx->r3 | 0X8;
    // 0x800B08D4: sw          $v0, -0x35E4($a0)
    MEM_W(-0X35E4, ctx->r4) = ctx->r2;
    // 0x800B08D8: jal         0x80003430
    // 0x800B08DC: sh          $v1, 0x180($s0)
    MEM_H(0X180, ctx->r16) = ctx->r3;
    rand_recomp(rdram, ctx);
        goto after_2;
    // 0x800B08DC: sh          $v1, 0x180($s0)
    MEM_H(0X180, ctx->r16) = ctx->r3;
    after_2:
    // 0x800B08E0: andi        $v0, $v0, 0x3F
    ctx->r2 = ctx->r2 & 0X3F;
    // 0x800B08E4: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800B08E8: lwc1        $f2, 0x561C($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X561C);
    // 0x800B08EC: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x800B08F0: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x800B08F4: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x800B08F8: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800B08FC: lwc1        $f2, 0x5620($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X5620);
    // 0x800B0900: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x800B0904: nop

    // 0x800B0908: bc1f        L_800B0920
    if (!c1cs) {
        // 0x800B090C: nop
    
            goto L_800B0920;
    }
    // 0x800B090C: nop

    // 0x800B0910: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800B0914: lwc1        $f0, 0x5624($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X5624);
    // 0x800B0918: j           L_800B092C
    // 0x800B091C: swc1        $f0, 0x140($s0)
    MEM_W(0X140, ctx->r16) = ctx->f0.u32l;
        goto L_800B092C;
    // 0x800B091C: swc1        $f0, 0x140($s0)
    MEM_W(0X140, ctx->r16) = ctx->f0.u32l;
L_800B0920:
    // 0x800B0920: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800B0924: lwc1        $f0, 0x5628($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X5628);
    // 0x800B0928: swc1        $f0, 0x140($s0)
    MEM_W(0X140, ctx->r16) = ctx->f0.u32l;
L_800B092C:
    // 0x800B092C: jal         0x80003430
    // 0x800B0930: sw          $zero, 0xC0($s0)
    MEM_W(0XC0, ctx->r16) = 0;
    rand_recomp(rdram, ctx);
        goto after_3;
    // 0x800B0930: sw          $zero, 0xC0($s0)
    MEM_W(0XC0, ctx->r16) = 0;
    after_3:
    // 0x800B0934: andi        $a0, $v0, 0x3
    ctx->r4 = ctx->r2 & 0X3;
    // 0x800B0938: slti        $v0, $a0, 0x3
    ctx->r2 = SIGNED(ctx->r4) < 0X3 ? 1 : 0;
    // 0x800B093C: beql        $v0, $zero, L_800B0944
    if (ctx->r2 == 0) {
        // 0x800B0940: addiu       $a0, $zero, 0x2
        ctx->r4 = ADD32(0, 0X2);
            goto L_800B0944;
    }
    goto skip_0;
    // 0x800B0940: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    skip_0:
L_800B0944:
    // 0x800B0944: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800B0948: lbu         $v1, 0xB40($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0XB40);
    // 0x800B094C: addiu       $v0, $zero, 0xF
    ctx->r2 = ADD32(0, 0XF);
    // 0x800B0950: beql        $v1, $v0, L_800B095C
    if (ctx->r3 == ctx->r2) {
        // 0x800B0954: addiu       $a0, $a0, 0x1FE
        ctx->r4 = ADD32(ctx->r4, 0X1FE);
            goto L_800B095C;
    }
    goto skip_1;
    // 0x800B0954: addiu       $a0, $a0, 0x1FE
    ctx->r4 = ADD32(ctx->r4, 0X1FE);
    skip_1:
    // 0x800B0958: addiu       $a0, $a0, 0x116
    ctx->r4 = ADD32(ctx->r4, 0X116);
L_800B095C:
    // 0x800B095C: addiu       $a1, $zero, 0x73
    ctx->r5 = ADD32(0, 0X73);
    // 0x800B0960: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // 0x800B0964: jal         0x80066EE4
    // 0x800B0968: addiu       $a3, $zero, 0x30
    ctx->r7 = ADD32(0, 0X30);
    func_80066EE4(rdram, ctx);
        goto after_4;
    // 0x800B0968: addiu       $a3, $zero, 0x30
    ctx->r7 = ADD32(0, 0X30);
    after_4:
    // 0x800B096C: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800B0970: lwc1        $f0, 0x562C($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X562C);
    // 0x800B0974: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x800B0978: jal         0x80051814
    // 0x800B097C: swc1        $f0, 0x18C($s0)
    MEM_W(0X18C, ctx->r16) = ctx->f0.u32l;
    func_80051814(rdram, ctx);
        goto after_5;
    // 0x800B097C: swc1        $f0, 0x18C($s0)
    MEM_W(0X18C, ctx->r16) = ctx->f0.u32l;
    after_5:
    // 0x800B0980: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x800B0984: lui         $a3, 0x41A0
    ctx->r7 = S32(0X41A0 << 16);
    // 0x800B0988: lhu         $a0, 0xB6($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0XB6);
    // 0x800B098C: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800B0990: lwc1        $f0, 0x5630($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X5630);
    // 0x800B0994: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x800B0998: jal         0x8006F4B0
    // 0x800B099C: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    func_8006F4B0(rdram, ctx);
        goto after_6;
    // 0x800B099C: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    after_6:
    // 0x800B09A0: andi        $a0, $v0, 0xFFFF
    ctx->r4 = ctx->r2 & 0XFFFF;
    // 0x800B09A4: ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
    // 0x800B09A8: beq         $a0, $v0, L_800B09C4
    if (ctx->r4 == ctx->r2) {
        // 0x800B09AC: nop
    
            goto L_800B09C4;
    }
    // 0x800B09AC: nop

    // 0x800B09B0: jal         0x8004013C
    // 0x800B09B4: nop

    func_8004013C(rdram, ctx);
        goto after_7;
    // 0x800B09B4: nop

    after_7:
    // 0x800B09B8: lhu         $a0, 0x1CC($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X1CC);
    // 0x800B09BC: jal         0x8003E684
    // 0x800B09C0: addu        $a1, $v0, $zero
    ctx->r5 = ADD32(ctx->r2, 0);
    func_8003E684(rdram, ctx);
        goto after_8;
    // 0x800B09C0: addu        $a1, $v0, $zero
    ctx->r5 = ADD32(ctx->r2, 0);
    after_8:
L_800B09C4:
    // 0x800B09C4: lhu         $a0, 0xB6($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0XB6);
    // 0x800B09C8: jal         0x8004013C
    // 0x800B09CC: addiu       $s2, $zero, 0xB
    ctx->r18 = ADD32(0, 0XB);
    func_8004013C(rdram, ctx);
        goto after_9;
    // 0x800B09CC: addiu       $s2, $zero, 0xB
    ctx->r18 = ADD32(0, 0XB);
    after_9:
    // 0x800B09D0: jal         0x800F2AA4
    // 0x800B09D4: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    func_800F2AA4(rdram, ctx);
        goto after_10;
    // 0x800B09D4: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    after_10:
    // 0x800B09D8: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800B09DC: lw          $v0, 0xB50($v0)
    ctx->r2 = MEM_W(ctx->r2, 0XB50);
    // 0x800B09E0: andi        $v0, $v0, 0x60
    ctx->r2 = ctx->r2 & 0X60;
    // 0x800B09E4: bne         $v0, $zero, L_800B0A58
    if (ctx->r2 != 0) {
        // 0x800B09E8: lui         $v0, 0x8011
        ctx->r2 = S32(0X8011 << 16);
            goto L_800B0A58;
    }
    // 0x800B09E8: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800B09EC: lw          $v0, -0x35E0($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X35E0);
    // 0x800B09F0: bne         $v0, $zero, L_800B0A58
    if (ctx->r2 != 0) {
        // 0x800B09F4: nop
    
            goto L_800B0A58;
    }
    // 0x800B09F4: nop

    // 0x800B09F8: lw          $v0, 0x1C4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1C4);
    // 0x800B09FC: slt         $v0, $s2, $v0
    ctx->r2 = SIGNED(ctx->r18) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800B0A00: beq         $v0, $zero, L_800B0A20
    if (ctx->r2 == 0) {
        // 0x800B0A04: nop
    
            goto L_800B0A20;
    }
    // 0x800B0A04: nop

    // 0x800B0A08: lbu         $a0, 0xBB($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0XBB);
    // 0x800B0A0C: jal         0x80003150
    // 0x800B0A10: nop

    func_80003150(rdram, ctx);
        goto after_11;
    // 0x800B0A10: nop

    after_11:
    // 0x800B0A14: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x800B0A18: bne         $v0, $zero, L_800B0A58
    if (ctx->r2 != 0) {
        // 0x800B0A1C: nop
    
            goto L_800B0A58;
    }
    // 0x800B0A1C: nop

L_800B0A20:
    // 0x800B0A20: lw          $a0, 0x1C0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X1C0);
    // 0x800B0A24: addiu       $s1, $zero, -0x1
    ctx->r17 = ADD32(0, -0X1);
    // 0x800B0A28: beql        $a0, $s1, L_800B0A3C
    if (ctx->r4 == ctx->r17) {
        // 0x800B0A2C: lui         $a1, 0x8011
        ctx->r5 = S32(0X8011 << 16);
            goto L_800B0A3C;
    }
    goto skip_2;
    // 0x800B0A2C: lui         $a1, 0x8011
    ctx->r5 = S32(0X8011 << 16);
    skip_2:
    // 0x800B0A30: jal         0x80002BA8
    // 0x800B0A34: nop

    func_80002BA8(rdram, ctx);
        goto after_12;
    // 0x800B0A34: nop

    after_12:
    // 0x800B0A38: lui         $a1, 0x8011
    ctx->r5 = S32(0X8011 << 16);
L_800B0A3C:
    // 0x800B0A3C: addiu       $a1, $a1, -0x4430
    ctx->r5 = ADD32(ctx->r5, -0X4430);
    // 0x800B0A40: lbu         $a0, 0xBB($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0XBB);
    // 0x800B0A44: jal         0x80002ADC
    // 0x800B0A48: addiu       $a1, $a1, 0x84
    ctx->r5 = ADD32(ctx->r5, 0X84);
    func_80002ADC(rdram, ctx);
        goto after_13;
    // 0x800B0A48: addiu       $a1, $a1, 0x84
    ctx->r5 = ADD32(ctx->r5, 0X84);
    after_13:
    // 0x800B0A4C: beq         $v0, $s1, L_800B0A58
    if (ctx->r2 == ctx->r17) {
        // 0x800B0A50: sw          $v0, 0x1C0($s0)
        MEM_W(0X1C0, ctx->r16) = ctx->r2;
            goto L_800B0A58;
    }
    // 0x800B0A50: sw          $v0, 0x1C0($s0)
    MEM_W(0X1C0, ctx->r16) = ctx->r2;
    // 0x800B0A54: sw          $s2, 0x1C4($s0)
    MEM_W(0X1C4, ctx->r16) = ctx->r18;
L_800B0A58:
    // 0x800B0A58: lbu         $v0, 0x24C($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X24C);
    // 0x800B0A5C: beq         $v0, $zero, L_800B0A70
    if (ctx->r2 == 0) {
        // 0x800B0A60: nop
    
            goto L_800B0A70;
    }
    // 0x800B0A60: nop

    // 0x800B0A64: sb          $zero, 0x24C($s0)
    MEM_B(0X24C, ctx->r16) = 0;
    // 0x800B0A68: jal         0x80098DE0
    // 0x800B0A6C: addiu       $a0, $s0, 0x208
    ctx->r4 = ADD32(ctx->r16, 0X208);
    func_80098DE0(rdram, ctx);
        goto after_14;
    // 0x800B0A6C: addiu       $a0, $s0, 0x208
    ctx->r4 = ADD32(ctx->r16, 0X208);
    after_14:
L_800B0A70:
    // 0x800B0A70: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800B0A74: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x800B0A78: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x800B0A7C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800B0A80: jr          $ra
    // 0x800B0A84: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x800B0A84: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_800B08F4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B08F4: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x800B08F8: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x800B08FC: lw          $v1, -0x228C($v0)
    ctx->r3 = MEM_W(ctx->r2, -0X228C);
    // 0x800B0900: addiu       $v0, $zero, 0xD2
    ctx->r2 = ADD32(0, 0XD2);
    // 0x800B0904: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x800B0908: lui         $s1, 0x800D
    ctx->r17 = S32(0X800D << 16);
    // 0x800B090C: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x800B0910: sw          $s6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r22;
    // 0x800B0914: sw          $s5, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r21;
    // 0x800B0918: sw          $s4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r20;
    // 0x800B091C: sw          $s3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r19;
    // 0x800B0920: sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // 0x800B0924: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x800B0928: sdc1        $f30, 0x58($sp)
    CHECK_FR(ctx, 30);
    SD(ctx->f30.u64, 0X58, ctx->r29);
    // 0x800B092C: sdc1        $f28, 0x50($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0X50, ctx->r29);
    // 0x800B0930: sdc1        $f26, 0x48($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X48, ctx->r29);
    // 0x800B0934: sdc1        $f24, 0x40($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X40, ctx->r29);
    // 0x800B0938: sdc1        $f22, 0x38($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X38, ctx->r29);
    // 0x800B093C: sdc1        $f20, 0x30($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X30, ctx->r29);
    // 0x800B0940: sb          $v0, 0x2F($v1)
    MEM_B(0X2F, ctx->r3) = ctx->r2;
    // 0x800B0944: lw          $v1, -0x2288($s1)
    ctx->r3 = MEM_W(ctx->r17, -0X2288);
    // 0x800B0948: addiu       $v0, $zero, 0x8C
    ctx->r2 = ADD32(0, 0X8C);
    // 0x800B094C: sb          $v0, 0x2F($v1)
    MEM_B(0X2F, ctx->r3) = ctx->r2;
    // 0x800B0950: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x800B0954: lbu         $v0, -0x253C($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X253C);
    // 0x800B0958: addiu       $v0, $v0, -0x2
    ctx->r2 = ADD32(ctx->r2, -0X2);
    // 0x800B095C: sltiu       $v0, $v0, 0x2
    ctx->r2 = ctx->r2 < 0X2 ? 1 : 0;
    // 0x800B0960: beq         $v0, $zero, L_800B0A30
    if (ctx->r2 == 0) {
        // 0x800B0964: mov.s       $f28, $f12
        CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 12);
    ctx->f28.fl = ctx->f12.fl;
            goto L_800B0A30;
    }
    // 0x800B0964: mov.s       $f28, $f12
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 12);
    ctx->f28.fl = ctx->f12.fl;
    // 0x800B0968: lui         $s0, 0x800D
    ctx->r16 = S32(0X800D << 16);
    // 0x800B096C: lwc1        $f0, -0x2508($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, -0X2508);
    // 0x800B0970: sub.s       $f0, $f0, $f28
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f28.fl;
    // 0x800B0974: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x800B0978: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x800B097C: nop

    // 0x800B0980: bc1f        L_800B0A30
    if (!c1cs) {
        // 0x800B0984: swc1        $f0, -0x2508($s0)
        MEM_W(-0X2508, ctx->r16) = ctx->f0.u32l;
            goto L_800B0A30;
    }
    // 0x800B0984: swc1        $f0, -0x2508($s0)
    MEM_W(-0X2508, ctx->r16) = ctx->f0.u32l;
    // 0x800B0988: add.s       $f0, $f0, $f28
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f28.fl;
    // 0x800B098C: c.le.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl <= ctx->f0.fl;
    // 0x800B0990: nop

    // 0x800B0994: bc1f        L_800B09A8
    if (!c1cs) {
        // 0x800B0998: addiu       $a0, $zero, 0x2D
        ctx->r4 = ADD32(0, 0X2D);
            goto L_800B09A8;
    }
    // 0x800B0998: addiu       $a0, $zero, 0x2D
    ctx->r4 = ADD32(0, 0X2D);
    // 0x800B099C: addiu       $a1, $zero, 0x50
    ctx->r5 = ADD32(0, 0X50);
    // 0x800B09A0: jal         0x80087EE8
    // 0x800B09A4: addiu       $a2, $zero, 0x40
    ctx->r6 = ADD32(0, 0X40);
    func_80087EE8(rdram, ctx);
        goto after_0;
    // 0x800B09A4: addiu       $a2, $zero, 0x40
    ctx->r6 = ADD32(0, 0X40);
    after_0:
L_800B09A8:
    // 0x800B09A8: jal         0x80003430
    // 0x800B09AC: nop

    rand_recomp(rdram, ctx);
        goto after_1;
    // 0x800B09AC: nop

    after_1:
    // 0x800B09B0: lui         $v1, 0x8208
    ctx->r3 = S32(0X8208 << 16);
    // 0x800B09B4: ori         $v1, $v1, 0x2083
    ctx->r3 = ctx->r3 | 0X2083;
    // 0x800B09B8: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x800B09BC: sra         $a0, $v0, 16
    ctx->r4 = S32(SIGNED(ctx->r2) >> 16);
    // 0x800B09C0: mult        $a0, $v1
    result = S64(S32(ctx->r4)) * S64(S32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800B09C4: sra         $v0, $v0, 31
    ctx->r2 = S32(SIGNED(ctx->r2) >> 31);
    // 0x800B09C8: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800B09CC: lwc1        $f0, 0x5A28($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X5A28);
    // 0x800B09D0: mfhi        $t0
    ctx->r8 = hi;
    // 0x800B09D4: addu        $v1, $t0, $a0
    ctx->r3 = ADD32(ctx->r8, ctx->r4);
    // 0x800B09D8: sra         $v1, $v1, 5
    ctx->r3 = S32(SIGNED(ctx->r3) >> 5);
    // 0x800B09DC: subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // 0x800B09E0: sll         $v0, $v1, 6
    ctx->r2 = S32(ctx->r3 << 6);
    // 0x800B09E4: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x800B09E8: subu        $a0, $a0, $v0
    ctx->r4 = SUB32(ctx->r4, ctx->r2);
    // 0x800B09EC: lw          $v0, -0x2288($s1)
    ctx->r2 = MEM_W(ctx->r17, -0X2288);
    // 0x800B09F0: addiu       $a0, $a0, 0x50
    ctx->r4 = ADD32(ctx->r4, 0X50);
    // 0x800B09F4: sb          $a0, 0x2F($v0)
    MEM_B(0X2F, ctx->r2) = ctx->r4;
    // 0x800B09F8: lwc1        $f2, -0x2508($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, -0X2508);
    // 0x800B09FC: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x800B0A00: nop

    // 0x800B0A04: bc1f        L_800B0A34
    if (!c1cs) {
        // 0x800B0A08: lui         $v0, 0x800D
        ctx->r2 = S32(0X800D << 16);
            goto L_800B0A34;
    }
    // 0x800B0A08: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x800B0A0C: jal         0x80003430
    // 0x800B0A10: nop

    rand_recomp(rdram, ctx);
        goto after_2;
    // 0x800B0A10: nop

    after_2:
    // 0x800B0A14: andi        $v0, $v0, 0x7
    ctx->r2 = ctx->r2 & 0X7;
    // 0x800B0A18: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800B0A1C: lwc1        $f2, 0x5A2C($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X5A2C);
    // 0x800B0A20: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x800B0A24: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x800B0A28: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x800B0A2C: swc1        $f0, -0x2508($s0)
    MEM_W(-0X2508, ctx->r16) = ctx->f0.u32l;
L_800B0A30:
    // 0x800B0A30: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
L_800B0A34:
    // 0x800B0A34: lwc1        $f0, -0x24E8($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, -0X24E8);
    // 0x800B0A38: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800B0A3C: lwc1        $f12, 0x5A30($at)
    ctx->f12.u32l = MEM_W(ctx->r1, 0X5A30);
    // 0x800B0A40: mul.s       $f12, $f0, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = MUL_S(ctx->f0.fl, ctx->f12.fl);
    // 0x800B0A44: jal         0x80033960
    // 0x800B0A48: nop

    sinf_recomp(rdram, ctx);
        goto after_3;
    // 0x800B0A48: nop

    after_3:
    // 0x800B0A4C: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800B0A50: lwc1        $f2, 0x5A34($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X5A34);
    // 0x800B0A54: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x800B0A58: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x800B0A5C: lbu         $v1, -0x253B($v0)
    ctx->r3 = MEM_BU(ctx->r2, -0X253B);
    // 0x800B0A60: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800B0A64: lwc1        $f2, 0x5A38($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X5A38);
    // 0x800B0A68: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800B0A6C: beq         $v1, $v0, L_800B0A80
    if (ctx->r3 == ctx->r2) {
        // 0x800B0A70: add.s       $f6, $f0, $f2
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = ctx->f0.fl + ctx->f2.fl;
            goto L_800B0A80;
    }
    // 0x800B0A70: add.s       $f6, $f0, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x800B0A74: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x800B0A78: bne         $v1, $v0, L_800B0A9C
    if (ctx->r3 != ctx->r2) {
        // 0x800B0A7C: nop
    
            goto L_800B0A9C;
    }
    // 0x800B0A7C: nop

L_800B0A80:
    // 0x800B0A80: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x800B0A84: lbu         $v1, -0x253C($v0)
    ctx->r3 = MEM_BU(ctx->r2, -0X253C);
    // 0x800B0A88: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // 0x800B0A8C: beq         $v1, $v0, L_800B0A9C
    if (ctx->r3 == ctx->r2) {
        // 0x800B0A90: lui         $v0, 0x800D
        ctx->r2 = S32(0X800D << 16);
            goto L_800B0A9C;
    }
    // 0x800B0A90: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x800B0A94: lwc1        $f0, -0x2510($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, -0X2510);
    // 0x800B0A98: mul.s       $f6, $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
L_800B0A9C:
    // 0x800B0A9C: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800B0AA0: lwc1        $f2, 0x5A3C($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X5A3C);
    // 0x800B0AA4: mul.s       $f2, $f6, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = MUL_S(ctx->f6.fl, ctx->f2.fl);
    // 0x800B0AA8: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x800B0AAC: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x800B0AB0: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800B0AB4: lwc1        $f0, 0x5A40($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X5A40);
    // 0x800B0AB8: lwc1        $f4, -0x251C($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, -0X251C);
    // 0x800B0ABC: mul.s       $f0, $f6, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x800B0AC0: addiu       $v0, $v0, -0x24E0
    ctx->r2 = ADD32(ctx->r2, -0X24E0);
    // 0x800B0AC4: swc1        $f6, 0xDC($v0)
    MEM_W(0XDC, ctx->r2) = ctx->f6.u32l;
    // 0x800B0AC8: swc1        $f4, 0x118($v0)
    MEM_W(0X118, ctx->r2) = ctx->f4.u32l;
    // 0x800B0ACC: swc1        $f2, 0xD4($v0)
    MEM_W(0XD4, ctx->r2) = ctx->f2.u32l;
    // 0x800B0AD0: swc1        $f0, 0xD8($v0)
    MEM_W(0XD8, ctx->r2) = ctx->f0.u32l;
    // 0x800B0AD4: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x800B0AD8: lbu         $v1, -0x253B($v0)
    ctx->r3 = MEM_BU(ctx->r2, -0X253B);
    // 0x800B0ADC: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x800B0AE0: beq         $v1, $v0, L_800B0B6C
    if (ctx->r3 == ctx->r2) {
        // 0x800B0AE4: lui         $v0, 0x800D
        ctx->r2 = S32(0X800D << 16);
            goto L_800B0B6C;
    }
    // 0x800B0AE4: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x800B0AE8: lbu         $v1, -0x253C($v0)
    ctx->r3 = MEM_BU(ctx->r2, -0X253C);
    // 0x800B0AEC: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // 0x800B0AF0: beq         $v1, $v0, L_800B0B6C
    if (ctx->r3 == ctx->r2) {
        // 0x800B0AF4: addu        $a1, $zero, $zero
        ctx->r5 = ADD32(0, 0);
            goto L_800B0B6C;
    }
    // 0x800B0AF4: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x800B0AF8: addiu       $a2, $zero, 0x20
    ctx->r6 = ADD32(0, 0X20);
    // 0x800B0AFC: lui         $s0, 0x800D
    ctx->r16 = S32(0X800D << 16);
    // 0x800B0B00: addiu       $s0, $s0, -0x2310
    ctx->r16 = ADD32(ctx->r16, -0X2310);
    // 0x800B0B04: lw          $a0, 0x4($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X4);
    // 0x800B0B08: jal         0x8005955C
    // 0x800B0B0C: lui         $a3, 0x10
    ctx->r7 = S32(0X10 << 16);
    func_8005955C(rdram, ctx);
        goto after_4;
    // 0x800B0B0C: lui         $a3, 0x10
    ctx->r7 = S32(0X10 << 16);
    after_4:
    // 0x800B0B10: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x800B0B14: addiu       $a2, $zero, 0x20
    ctx->r6 = ADD32(0, 0X20);
    // 0x800B0B18: lw          $a0, 0x24($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X24);
    // 0x800B0B1C: jal         0x8005955C
    // 0x800B0B20: lui         $a3, 0x10
    ctx->r7 = S32(0X10 << 16);
    func_8005955C(rdram, ctx);
        goto after_5;
    // 0x800B0B20: lui         $a3, 0x10
    ctx->r7 = S32(0X10 << 16);
    after_5:
    // 0x800B0B24: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x800B0B28: addiu       $a2, $zero, 0x20
    ctx->r6 = ADD32(0, 0X20);
    // 0x800B0B2C: lw          $a0, 0x44($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X44);
    // 0x800B0B30: jal         0x8005955C
    // 0x800B0B34: lui         $a3, 0x10
    ctx->r7 = S32(0X10 << 16);
    func_8005955C(rdram, ctx);
        goto after_6;
    // 0x800B0B34: lui         $a3, 0x10
    ctx->r7 = S32(0X10 << 16);
    after_6:
    // 0x800B0B38: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x800B0B3C: addiu       $a2, $zero, 0x20
    ctx->r6 = ADD32(0, 0X20);
    // 0x800B0B40: lw          $a0, 0x64($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X64);
    // 0x800B0B44: jal         0x8005955C
    // 0x800B0B48: lui         $a3, 0x10
    ctx->r7 = S32(0X10 << 16);
    func_8005955C(rdram, ctx);
        goto after_7;
    // 0x800B0B48: lui         $a3, 0x10
    ctx->r7 = S32(0X10 << 16);
    after_7:
    // 0x800B0B4C: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800B0B50: lwc1        $f2, 0x5A44($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X5A44);
    // 0x800B0B54: mul.s       $f2, $f28, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f28.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = MUL_S(ctx->f28.fl, ctx->f2.fl);
    // 0x800B0B58: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x800B0B5C: lwc1        $f0, -0x24E8($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, -0X24E8);
    // 0x800B0B60: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x800B0B64: j           L_800B0BC4
    // 0x800B0B68: swc1        $f0, -0x24E8($v0)
    MEM_W(-0X24E8, ctx->r2) = ctx->f0.u32l;
        goto L_800B0BC4;
    // 0x800B0B68: swc1        $f0, -0x24E8($v0)
    MEM_W(-0X24E8, ctx->r2) = ctx->f0.u32l;
L_800B0B6C:
    // 0x800B0B6C: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x800B0B70: addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    // 0x800B0B74: lui         $s0, 0x800D
    ctx->r16 = S32(0X800D << 16);
    // 0x800B0B78: addiu       $s0, $s0, -0x2310
    ctx->r16 = ADD32(ctx->r16, -0X2310);
    // 0x800B0B7C: lw          $a0, 0x4($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X4);
    // 0x800B0B80: jal         0x8005955C
    // 0x800B0B84: addiu       $a3, $zero, 0x20
    ctx->r7 = ADD32(0, 0X20);
    func_8005955C(rdram, ctx);
        goto after_8;
    // 0x800B0B84: addiu       $a3, $zero, 0x20
    ctx->r7 = ADD32(0, 0X20);
    after_8:
    // 0x800B0B88: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x800B0B8C: addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    // 0x800B0B90: lw          $a0, 0x24($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X24);
    // 0x800B0B94: jal         0x8005955C
    // 0x800B0B98: addiu       $a3, $zero, 0x20
    ctx->r7 = ADD32(0, 0X20);
    func_8005955C(rdram, ctx);
        goto after_9;
    // 0x800B0B98: addiu       $a3, $zero, 0x20
    ctx->r7 = ADD32(0, 0X20);
    after_9:
    // 0x800B0B9C: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x800B0BA0: addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    // 0x800B0BA4: lw          $a0, 0x44($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X44);
    // 0x800B0BA8: jal         0x8005955C
    // 0x800B0BAC: addiu       $a3, $zero, 0x20
    ctx->r7 = ADD32(0, 0X20);
    func_8005955C(rdram, ctx);
        goto after_10;
    // 0x800B0BAC: addiu       $a3, $zero, 0x20
    ctx->r7 = ADD32(0, 0X20);
    after_10:
    // 0x800B0BB0: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x800B0BB4: addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    // 0x800B0BB8: lw          $a0, 0x64($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X64);
    // 0x800B0BBC: jal         0x8005955C
    // 0x800B0BC0: addiu       $a3, $zero, 0x20
    ctx->r7 = ADD32(0, 0X20);
    func_8005955C(rdram, ctx);
        goto after_11;
    // 0x800B0BC0: addiu       $a3, $zero, 0x20
    ctx->r7 = ADD32(0, 0X20);
    after_11:
L_800B0BC4:
    // 0x800B0BC4: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x800B0BC8: lwc1        $f0, -0x24EC($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, -0X24EC);
    // 0x800B0BCC: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800B0BD0: lwc1        $f12, 0x5A48($at)
    ctx->f12.u32l = MEM_W(ctx->r1, 0X5A48);
    // 0x800B0BD4: jal         0x80033960
    // 0x800B0BD8: div.s       $f12, $f0, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = DIV_S(ctx->f0.fl, ctx->f12.fl);
    sinf_recomp(rdram, ctx);
        goto after_12;
    // 0x800B0BD8: div.s       $f12, $f0, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = DIV_S(ctx->f0.fl, ctx->f12.fl);
    after_12:
    // 0x800B0BDC: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x800B0BE0: lwc1        $f12, -0x2510($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, -0X2510);
    // 0x800B0BE4: jal         0x800662E0
    // 0x800B0BE8: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
    func_800662E0(rdram, ctx);
        goto after_13;
    // 0x800B0BE8: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
    after_13:
    // 0x800B0BEC: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800B0BF0: lwc1        $f2, 0x5A4C($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X5A4C);
    // 0x800B0BF4: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x800B0BF8: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800B0BFC: lwc1        $f2, 0x5A50($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X5A50);
    // 0x800B0C00: mul.s       $f2, $f22, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = MUL_S(ctx->f22.fl, ctx->f2.fl);
    // 0x800B0C04: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800B0C08: lwc1        $f4, 0x5A54($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X5A54);
    // 0x800B0C0C: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x800B0C10: add.s       $f4, $f2, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f4.fl = ctx->f2.fl + ctx->f4.fl;
    // 0x800B0C14: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800B0C18: lwc1        $f2, 0x5A58($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X5A58);
    // 0x800B0C1C: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800B0C20: lwc1        $f6, 0x5A5C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X5A5C);
    // 0x800B0C24: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x800B0C28: lw          $a0, -0x228C($v0)
    ctx->r4 = MEM_W(ctx->r2, -0X228C);
    // 0x800B0C2C: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800B0C30: lwc1        $f2, 0x5A60($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X5A60);
    // 0x800B0C34: c.le.s      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.fl <= ctx->f4.fl;
    // 0x800B0C38: mul.s       $f24, $f0, $f2
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f24.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x800B0C3C: bc1tl       L_800B0C54
    if (c1cs) {
        // 0x800B0C40: sub.s       $f0, $f4, $f6
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f6.fl;
            goto L_800B0C54;
    }
    goto skip_0;
    // 0x800B0C40: sub.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f6.fl;
    skip_0:
    // 0x800B0C44: trunc.w.s   $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    ctx->f10.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x800B0C48: mfc1        $v1, $f10
    ctx->r3 = (int32_t)ctx->f10.u32l;
    // 0x800B0C4C: j           L_800B0C64
    // 0x800B0C50: nop

        goto L_800B0C64;
    // 0x800B0C50: nop

L_800B0C54:
    // 0x800B0C54: lui         $v0, 0x8000
    ctx->r2 = S32(0X8000 << 16);
    // 0x800B0C58: trunc.w.s   $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    ctx->f10.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800B0C5C: mfc1        $v1, $f10
    ctx->r3 = (int32_t)ctx->f10.u32l;
    // 0x800B0C60: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
L_800B0C64:
    // 0x800B0C64: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800B0C68: lwc1        $f0, 0x5A64($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X5A64);
    // 0x800B0C6C: mul.s       $f0, $f22, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = MUL_S(ctx->f22.fl, ctx->f0.fl);
    // 0x800B0C70: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x800B0C74: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800B0C78: lwc1        $f2, 0x5A68($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X5A68);
    // 0x800B0C7C: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800B0C80: lwc1        $f4, 0x5A6C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X5A6C);
    // 0x800B0C84: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x800B0C88: sb          $v1, 0x2C($a0)
    MEM_B(0X2C, ctx->r4) = ctx->r3;
    // 0x800B0C8C: lw          $a0, -0x228C($v0)
    ctx->r4 = MEM_W(ctx->r2, -0X228C);
    // 0x800B0C90: c.le.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl <= ctx->f0.fl;
    // 0x800B0C94: nop

    // 0x800B0C98: bc1tl       L_800B0CB0
    if (c1cs) {
        // 0x800B0C9C: sub.s       $f0, $f0, $f4
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f4.fl;
            goto L_800B0CB0;
    }
    goto skip_1;
    // 0x800B0C9C: sub.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f4.fl;
    skip_1:
    // 0x800B0CA0: trunc.w.s   $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    ctx->f10.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800B0CA4: mfc1        $v1, $f10
    ctx->r3 = (int32_t)ctx->f10.u32l;
    // 0x800B0CA8: j           L_800B0CC0
    // 0x800B0CAC: nop

        goto L_800B0CC0;
    // 0x800B0CAC: nop

L_800B0CB0:
    // 0x800B0CB0: lui         $v0, 0x8000
    ctx->r2 = S32(0X8000 << 16);
    // 0x800B0CB4: trunc.w.s   $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    ctx->f10.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800B0CB8: mfc1        $v1, $f10
    ctx->r3 = (int32_t)ctx->f10.u32l;
    // 0x800B0CBC: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
L_800B0CC0:
    // 0x800B0CC0: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800B0CC4: lwc1        $f0, 0x5A70($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X5A70);
    // 0x800B0CC8: mul.s       $f0, $f22, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = MUL_S(ctx->f22.fl, ctx->f0.fl);
    // 0x800B0CCC: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x800B0CD0: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800B0CD4: lwc1        $f2, 0x5A74($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X5A74);
    // 0x800B0CD8: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800B0CDC: lwc1        $f4, 0x5A78($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X5A78);
    // 0x800B0CE0: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x800B0CE4: sb          $v1, 0x2D($a0)
    MEM_B(0X2D, ctx->r4) = ctx->r3;
    // 0x800B0CE8: lw          $a0, -0x228C($v0)
    ctx->r4 = MEM_W(ctx->r2, -0X228C);
    // 0x800B0CEC: c.le.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl <= ctx->f0.fl;
    // 0x800B0CF0: nop

    // 0x800B0CF4: bc1tl       L_800B0D0C
    if (c1cs) {
        // 0x800B0CF8: sub.s       $f0, $f0, $f4
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f4.fl;
            goto L_800B0D0C;
    }
    goto skip_2;
    // 0x800B0CF8: sub.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f4.fl;
    skip_2:
    // 0x800B0CFC: trunc.w.s   $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    ctx->f10.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800B0D00: mfc1        $v1, $f10
    ctx->r3 = (int32_t)ctx->f10.u32l;
    // 0x800B0D04: j           L_800B0D20
    // 0x800B0D08: lui         $s0, 0x800D
    ctx->r16 = S32(0X800D << 16);
        goto L_800B0D20;
    // 0x800B0D08: lui         $s0, 0x800D
    ctx->r16 = S32(0X800D << 16);
L_800B0D0C:
    // 0x800B0D0C: lui         $v0, 0x8000
    ctx->r2 = S32(0X8000 << 16);
    // 0x800B0D10: trunc.w.s   $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    ctx->f10.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800B0D14: mfc1        $v1, $f10
    ctx->r3 = (int32_t)ctx->f10.u32l;
    // 0x800B0D18: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x800B0D1C: lui         $s0, 0x800D
    ctx->r16 = S32(0X800D << 16);
L_800B0D20:
    // 0x800B0D20: sb          $v1, 0x2E($a0)
    MEM_B(0X2E, ctx->r4) = ctx->r3;
    // 0x800B0D24: lwc1        $f0, -0x24EC($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, -0X24EC);
    // 0x800B0D28: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800B0D2C: lwc1        $f12, 0x5A7C($at)
    ctx->f12.u32l = MEM_W(ctx->r1, 0X5A7C);
    // 0x800B0D30: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800B0D34: lwc1        $f20, 0x5A80($at)
    ctx->f20.u32l = MEM_W(ctx->r1, 0X5A80);
    // 0x800B0D38: jal         0x80033960
    // 0x800B0D3C: div.s       $f12, $f0, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = DIV_S(ctx->f0.fl, ctx->f12.fl);
    sinf_recomp(rdram, ctx);
        goto after_14;
    // 0x800B0D3C: div.s       $f12, $f0, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = DIV_S(ctx->f0.fl, ctx->f12.fl);
    after_14:
    // 0x800B0D40: mul.s       $f0, $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f20.fl);
    // 0x800B0D44: lwc1        $f2, -0x24EC($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, -0X24EC);
    // 0x800B0D48: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800B0D4C: lwc1        $f12, 0x5A84($at)
    ctx->f12.u32l = MEM_W(ctx->r1, 0X5A84);
    // 0x800B0D50: add.s       $f26, $f0, $f24
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f26.fl = ctx->f0.fl + ctx->f24.fl;
    // 0x800B0D54: jal         0x80033960
    // 0x800B0D58: div.s       $f12, $f2, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = DIV_S(ctx->f2.fl, ctx->f12.fl);
    sinf_recomp(rdram, ctx);
        goto after_15;
    // 0x800B0D58: div.s       $f12, $f2, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = DIV_S(ctx->f2.fl, ctx->f12.fl);
    after_15:
    // 0x800B0D5C: mul.s       $f0, $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f20.fl);
    // 0x800B0D60: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800B0D64: lwc1        $f8, 0x5A88($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X5A88);
    // 0x800B0D68: mul.s       $f8, $f26, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f8.fl = MUL_S(ctx->f26.fl, ctx->f8.fl);
    // 0x800B0D6C: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x800B0D70: add.s       $f24, $f0, $f24
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f24.fl = ctx->f0.fl + ctx->f24.fl;
    // 0x800B0D74: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800B0D78: lwc1        $f0, 0x5A8C($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X5A8C);
    // 0x800B0D7C: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x800B0D80: mul.s       $f0, $f24, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = MUL_S(ctx->f24.fl, ctx->f0.fl);
    // 0x800B0D84: lw          $v0, -0x228C($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X228C);
    // 0x800B0D88: lwc1        $f4, -0x2508($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, -0X2508);
    // 0x800B0D8C: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x800B0D90: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800B0D94: lwc1        $f6, 0x5A90($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X5A90);
    // 0x800B0D98: c.lt.s      $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f4.fl < ctx->f2.fl;
    // 0x800B0D9C: swc1        $f26, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->f26.u32l;
    // 0x800B0DA0: sub.s       $f0, $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f6.fl;
    // 0x800B0DA4: swc1        $f8, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->f8.u32l;
    // 0x800B0DA8: swc1        $f24, 0x28($v0)
    MEM_W(0X28, ctx->r2) = ctx->f24.u32l;
    // 0x800B0DAC: bc1f        L_800B0E0C
    if (!c1cs) {
        // 0x800B0DB0: swc1        $f0, 0x1C($v0)
        MEM_W(0X1C, ctx->r2) = ctx->f0.u32l;
            goto L_800B0E0C;
    }
    // 0x800B0DB0: swc1        $f0, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->f0.u32l;
    // 0x800B0DB4: jal         0x80003430
    // 0x800B0DB8: nop

    rand_recomp(rdram, ctx);
        goto after_16;
    // 0x800B0DB8: nop

    after_16:
    // 0x800B0DBC: andi        $v0, $v0, 0xF
    ctx->r2 = ctx->r2 & 0XF;
    // 0x800B0DC0: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800B0DC4: lwc1        $f20, 0x5A94($at)
    ctx->f20.u32l = MEM_W(ctx->r1, 0X5A94);
    // 0x800B0DC8: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x800B0DCC: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x800B0DD0: div.s       $f0, $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f20.fl);
    // 0x800B0DD4: jal         0x80003430
    // 0x800B0DD8: add.s       $f26, $f26, $f0
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f26.fl = ctx->f26.fl + ctx->f0.fl;
    rand_recomp(rdram, ctx);
        goto after_17;
    // 0x800B0DD8: add.s       $f26, $f26, $f0
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f26.fl = ctx->f26.fl + ctx->f0.fl;
    after_17:
    // 0x800B0DDC: andi        $v0, $v0, 0xF
    ctx->r2 = ctx->r2 & 0XF;
    // 0x800B0DE0: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x800B0DE4: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x800B0DE8: div.s       $f0, $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f20.fl);
    // 0x800B0DEC: jal         0x80003430
    // 0x800B0DF0: add.s       $f24, $f24, $f0
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f24.fl = ctx->f24.fl + ctx->f0.fl;
    rand_recomp(rdram, ctx);
        goto after_18;
    // 0x800B0DF0: add.s       $f24, $f24, $f0
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f24.fl = ctx->f24.fl + ctx->f0.fl;
    after_18:
    // 0x800B0DF4: andi        $v0, $v0, 0xF
    ctx->r2 = ctx->r2 & 0XF;
    // 0x800B0DF8: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800B0DFC: lwc1        $f2, 0x5A98($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X5A98);
    // 0x800B0E00: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x800B0E04: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x800B0E08: div.s       $f22, $f0, $f2
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f22.fl = DIV_S(ctx->f0.fl, ctx->f2.fl);
L_800B0E0C:
    // 0x800B0E0C: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800B0E10: lwc1        $f0, 0x5A9C($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X5A9C);
    // 0x800B0E14: mul.s       $f0, $f22, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = MUL_S(ctx->f22.fl, ctx->f0.fl);
    // 0x800B0E18: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800B0E1C: lwc1        $f2, 0x5AA0($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X5AA0);
    // 0x800B0E20: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x800B0E24: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x800B0E28: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800B0E2C: lwc1        $f2, 0x5AA4($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X5AA4);
    // 0x800B0E30: lw          $a0, -0x2288($v0)
    ctx->r4 = MEM_W(ctx->r2, -0X2288);
    // 0x800B0E34: c.le.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl <= ctx->f0.fl;
    // 0x800B0E38: nop

    // 0x800B0E3C: bc1tl       L_800B0E54
    if (c1cs) {
        // 0x800B0E40: sub.s       $f0, $f0, $f2
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
            goto L_800B0E54;
    }
    goto skip_3;
    // 0x800B0E40: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    skip_3:
    // 0x800B0E44: trunc.w.s   $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    ctx->f10.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800B0E48: mfc1        $v1, $f10
    ctx->r3 = (int32_t)ctx->f10.u32l;
    // 0x800B0E4C: j           L_800B0E64
    // 0x800B0E50: nop

        goto L_800B0E64;
    // 0x800B0E50: nop

L_800B0E54:
    // 0x800B0E54: lui         $v0, 0x8000
    ctx->r2 = S32(0X8000 << 16);
    // 0x800B0E58: trunc.w.s   $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    ctx->f10.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800B0E5C: mfc1        $v1, $f10
    ctx->r3 = (int32_t)ctx->f10.u32l;
    // 0x800B0E60: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
L_800B0E64:
    // 0x800B0E64: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800B0E68: lwc1        $f0, 0x5AA8($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X5AA8);
    // 0x800B0E6C: mul.s       $f0, $f22, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = MUL_S(ctx->f22.fl, ctx->f0.fl);
    // 0x800B0E70: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x800B0E74: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800B0E78: lwc1        $f2, 0x5AAC($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X5AAC);
    // 0x800B0E7C: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800B0E80: lwc1        $f4, 0x5AB0($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X5AB0);
    // 0x800B0E84: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x800B0E88: sb          $v1, 0x2C($a0)
    MEM_B(0X2C, ctx->r4) = ctx->r3;
    // 0x800B0E8C: lw          $a0, -0x2288($v0)
    ctx->r4 = MEM_W(ctx->r2, -0X2288);
    // 0x800B0E90: c.le.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl <= ctx->f0.fl;
    // 0x800B0E94: nop

    // 0x800B0E98: bc1tl       L_800B0EB0
    if (c1cs) {
        // 0x800B0E9C: sub.s       $f0, $f0, $f4
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f4.fl;
            goto L_800B0EB0;
    }
    goto skip_4;
    // 0x800B0E9C: sub.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f4.fl;
    skip_4:
    // 0x800B0EA0: trunc.w.s   $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    ctx->f10.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800B0EA4: mfc1        $v1, $f10
    ctx->r3 = (int32_t)ctx->f10.u32l;
    // 0x800B0EA8: j           L_800B0EC0
    // 0x800B0EAC: nop

        goto L_800B0EC0;
    // 0x800B0EAC: nop

L_800B0EB0:
    // 0x800B0EB0: lui         $v0, 0x8000
    ctx->r2 = S32(0X8000 << 16);
    // 0x800B0EB4: trunc.w.s   $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    ctx->f10.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800B0EB8: mfc1        $v1, $f10
    ctx->r3 = (int32_t)ctx->f10.u32l;
    // 0x800B0EBC: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
L_800B0EC0:
    // 0x800B0EC0: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800B0EC4: lwc1        $f0, 0x5AB4($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X5AB4);
    // 0x800B0EC8: mul.s       $f0, $f22, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = MUL_S(ctx->f22.fl, ctx->f0.fl);
    // 0x800B0ECC: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x800B0ED0: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800B0ED4: lwc1        $f2, 0x5AB8($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X5AB8);
    // 0x800B0ED8: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800B0EDC: lwc1        $f4, 0x5ABC($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X5ABC);
    // 0x800B0EE0: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x800B0EE4: sb          $v1, 0x2E($a0)
    MEM_B(0X2E, ctx->r4) = ctx->r3;
    // 0x800B0EE8: lw          $a0, -0x2288($v0)
    ctx->r4 = MEM_W(ctx->r2, -0X2288);
    // 0x800B0EEC: c.le.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl <= ctx->f0.fl;
    // 0x800B0EF0: nop

    // 0x800B0EF4: bc1tl       L_800B0F0C
    if (c1cs) {
        // 0x800B0EF8: sub.s       $f0, $f0, $f4
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f4.fl;
            goto L_800B0F0C;
    }
    goto skip_5;
    // 0x800B0EF8: sub.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f4.fl;
    skip_5:
    // 0x800B0EFC: trunc.w.s   $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    ctx->f10.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800B0F00: mfc1        $v1, $f10
    ctx->r3 = (int32_t)ctx->f10.u32l;
    // 0x800B0F04: j           L_800B0F1C
    // 0x800B0F08: nop

        goto L_800B0F1C;
    // 0x800B0F08: nop

L_800B0F0C:
    // 0x800B0F0C: lui         $v0, 0x8000
    ctx->r2 = S32(0X8000 << 16);
    // 0x800B0F10: trunc.w.s   $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    ctx->f10.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800B0F14: mfc1        $v1, $f10
    ctx->r3 = (int32_t)ctx->f10.u32l;
    // 0x800B0F18: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
L_800B0F1C:
    // 0x800B0F1C: jal         0x80003430
    // 0x800B0F20: sb          $v1, 0x2D($a0)
    MEM_B(0X2D, ctx->r4) = ctx->r3;
    rand_recomp(rdram, ctx);
        goto after_19;
    // 0x800B0F20: sb          $v1, 0x2D($a0)
    MEM_B(0X2D, ctx->r4) = ctx->r3;
    after_19:
    // 0x800B0F24: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800B0F28: lwc1        $f2, 0x5AC0($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X5AC0);
    // 0x800B0F2C: mul.s       $f2, $f26, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = MUL_S(ctx->f26.fl, ctx->f2.fl);
    // 0x800B0F30: lui         $s0, 0x800D
    ctx->r16 = S32(0X800D << 16);
    // 0x800B0F34: andi        $v0, $v0, 0x3
    ctx->r2 = ctx->r2 & 0X3;
    // 0x800B0F38: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x800B0F3C: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x800B0F40: add.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x800B0F44: lw          $v0, -0x2288($s0)
    ctx->r2 = MEM_W(ctx->r16, -0X2288);
    // 0x800B0F48: jal         0x80003430
    // 0x800B0F4C: swc1        $f2, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->f2.u32l;
    rand_recomp(rdram, ctx);
        goto after_20;
    // 0x800B0F4C: swc1        $f2, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->f2.u32l;
    after_20:
    // 0x800B0F50: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800B0F54: lwc1        $f0, 0x5AC4($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X5AC4);
    // 0x800B0F58: mul.s       $f0, $f24, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = MUL_S(ctx->f24.fl, ctx->f0.fl);
    // 0x800B0F5C: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800B0F60: lwc1        $f2, 0x5AC8($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X5AC8);
    // 0x800B0F64: andi        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 & 0X1;
    // 0x800B0F68: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x800B0F6C: mtc1        $v0, $f2
    ctx->f2.u32l = ctx->r2;
    // 0x800B0F70: cvt.s.w     $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    ctx->f2.fl = CVT_S_W(ctx->f2.u32l);
    // 0x800B0F74: lw          $v0, -0x2288($s0)
    ctx->r2 = MEM_W(ctx->r16, -0X2288);
    // 0x800B0F78: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x800B0F7C: swc1        $f26, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->f26.u32l;
    // 0x800B0F80: swc1        $f24, 0x28($v0)
    MEM_W(0X28, ctx->r2) = ctx->f24.u32l;
    // 0x800B0F84: swc1        $f0, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->f0.u32l;
    // 0x800B0F88: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x800B0F8C: lbu         $v1, -0x2539($v0)
    ctx->r3 = MEM_BU(ctx->r2, -0X2539);
    // 0x800B0F90: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800B0F94: bne         $v1, $v0, L_800B0FC8
    if (ctx->r3 != ctx->r2) {
        // 0x800B0F98: lui         $v0, 0x800D
        ctx->r2 = S32(0X800D << 16);
            goto L_800B0FC8;
    }
    // 0x800B0F98: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x800B0F9C: lwc1        $f0, -0x24F8($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, -0X24F8);
    // 0x800B0FA0: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800B0FA4: lwc1        $f2, 0x5ACC($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X5ACC);
    // 0x800B0FA8: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x800B0FAC: nop

    // 0x800B0FB0: bc1fl       L_800B1000
    if (!c1cs) {
        // 0x800B0FB4: lui         $v0, 0x800D
        ctx->r2 = S32(0X800D << 16);
            goto L_800B1000;
    }
    goto skip_6;
    // 0x800B0FB4: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    skip_6:
    // 0x800B0FB8: sub.s       $f0, $f0, $f28
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f28.fl;
    // 0x800B0FBC: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x800B0FC0: j           L_800B0FF0
    // 0x800B0FC4: swc1        $f0, -0x24F8($v0)
    MEM_W(-0X24F8, ctx->r2) = ctx->f0.u32l;
        goto L_800B0FF0;
    // 0x800B0FC4: swc1        $f0, -0x24F8($v0)
    MEM_W(-0X24F8, ctx->r2) = ctx->f0.u32l;
L_800B0FC8:
    // 0x800B0FC8: lwc1        $f0, -0x24F8($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, -0X24F8);
    // 0x800B0FCC: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800B0FD0: lwc1        $f2, 0x5AD0($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X5AD0);
    // 0x800B0FD4: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x800B0FD8: nop

    // 0x800B0FDC: bc1fl       L_800B1000
    if (!c1cs) {
        // 0x800B0FE0: lui         $v0, 0x800D
        ctx->r2 = S32(0X800D << 16);
            goto L_800B1000;
    }
    goto skip_7;
    // 0x800B0FE0: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    skip_7:
    // 0x800B0FE4: add.s       $f0, $f0, $f28
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f28.fl;
    // 0x800B0FE8: swc1        $f0, -0x24F8($v0)
    MEM_W(-0X24F8, ctx->r2) = ctx->f0.u32l;
    // 0x800B0FEC: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
L_800B0FF0:
    // 0x800B0FF0: nop

    // 0x800B0FF4: bc1tl       L_800B0FFC
    if (c1cs) {
        // 0x800B0FF8: swc1        $f2, -0x24F8($v0)
        MEM_W(-0X24F8, ctx->r2) = ctx->f2.u32l;
            goto L_800B0FFC;
    }
    goto skip_8;
    // 0x800B0FF8: swc1        $f2, -0x24F8($v0)
    MEM_W(-0X24F8, ctx->r2) = ctx->f2.u32l;
    skip_8:
L_800B0FFC:
    // 0x800B0FFC: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
L_800B1000:
    // 0x800B1000: lwc1        $f12, -0x24FC($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, -0X24FC);
    // 0x800B1004: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x800B1008: lwc1        $f20, -0x24F8($v0)
    ctx->f20.u32l = MEM_W(ctx->r2, -0X24F8);
    // 0x800B100C: jal         0x800662E0
    // 0x800B1010: nop

    func_800662E0(rdram, ctx);
        goto after_21;
    // 0x800B1010: nop

    after_21:
    // 0x800B1014: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x800B1018: lw          $a0, -0x228C($v0)
    ctx->r4 = MEM_W(ctx->r2, -0X228C);
    // 0x800B101C: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x800B1020: lbu         $v1, 0x2F($a0)
    ctx->r3 = MEM_BU(ctx->r4, 0X2F);
    // 0x800B1024: lwc1        $f4, -0x2510($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, -0X2510);
    // 0x800B1028: mtc1        $v1, $f2
    ctx->f2.u32l = ctx->r3;
    // 0x800B102C: cvt.s.w     $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    ctx->f2.fl = CVT_S_W(ctx->f2.u32l);
    // 0x800B1030: mul.s       $f2, $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f4.fl);
    // 0x800B1034: nop

    // 0x800B1038: mul.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x800B103C: nop

    // 0x800B1040: mul.s       $f0, $f2, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = MUL_S(ctx->f2.fl, ctx->f20.fl);
    // 0x800B1044: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800B1048: lwc1        $f2, 0x5AD4($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X5AD4);
    // 0x800B104C: c.le.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl <= ctx->f0.fl;
    // 0x800B1050: nop

    // 0x800B1054: bc1tl       L_800B106C
    if (c1cs) {
        // 0x800B1058: sub.s       $f0, $f0, $f2
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
            goto L_800B106C;
    }
    goto skip_9;
    // 0x800B1058: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    skip_9:
    // 0x800B105C: trunc.w.s   $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    ctx->f10.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800B1060: mfc1        $v1, $f10
    ctx->r3 = (int32_t)ctx->f10.u32l;
    // 0x800B1064: j           L_800B1080
    // 0x800B1068: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
        goto L_800B1080;
    // 0x800B1068: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
L_800B106C:
    // 0x800B106C: lui         $v0, 0x8000
    ctx->r2 = S32(0X8000 << 16);
    // 0x800B1070: trunc.w.s   $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    ctx->f10.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800B1074: mfc1        $v1, $f10
    ctx->r3 = (int32_t)ctx->f10.u32l;
    // 0x800B1078: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x800B107C: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
L_800B1080:
    // 0x800B1080: sb          $v1, 0x2F($a0)
    MEM_B(0X2F, ctx->r4) = ctx->r3;
    // 0x800B1084: lwc1        $f12, -0x24FC($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, -0X24FC);
    // 0x800B1088: jal         0x800662E0
    // 0x800B108C: nop

    func_800662E0(rdram, ctx);
        goto after_22;
    // 0x800B108C: nop

    after_22:
    // 0x800B1090: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x800B1094: lw          $a0, -0x2288($v0)
    ctx->r4 = MEM_W(ctx->r2, -0X2288);
    // 0x800B1098: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x800B109C: lbu         $v1, 0x2F($a0)
    ctx->r3 = MEM_BU(ctx->r4, 0X2F);
    // 0x800B10A0: lwc1        $f4, -0x2510($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, -0X2510);
    // 0x800B10A4: mtc1        $v1, $f2
    ctx->f2.u32l = ctx->r3;
    // 0x800B10A8: cvt.s.w     $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    ctx->f2.fl = CVT_S_W(ctx->f2.u32l);
    // 0x800B10AC: mul.s       $f2, $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f4.fl);
    // 0x800B10B0: nop

    // 0x800B10B4: mul.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x800B10B8: nop

    // 0x800B10BC: mul.s       $f0, $f2, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = MUL_S(ctx->f2.fl, ctx->f20.fl);
    // 0x800B10C0: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800B10C4: lwc1        $f2, 0x5AD8($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X5AD8);
    // 0x800B10C8: c.le.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl <= ctx->f0.fl;
    // 0x800B10CC: nop

    // 0x800B10D0: bc1tl       L_800B10E8
    if (c1cs) {
        // 0x800B10D4: sub.s       $f0, $f0, $f2
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
            goto L_800B10E8;
    }
    goto skip_10;
    // 0x800B10D4: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    skip_10:
    // 0x800B10D8: trunc.w.s   $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    ctx->f10.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800B10DC: mfc1        $v1, $f10
    ctx->r3 = (int32_t)ctx->f10.u32l;
    // 0x800B10E0: j           L_800B10FC
    // 0x800B10E4: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
        goto L_800B10FC;
    // 0x800B10E4: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
L_800B10E8:
    // 0x800B10E8: lui         $v0, 0x8000
    ctx->r2 = S32(0X8000 << 16);
    // 0x800B10EC: trunc.w.s   $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    ctx->f10.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800B10F0: mfc1        $v1, $f10
    ctx->r3 = (int32_t)ctx->f10.u32l;
    // 0x800B10F4: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x800B10F8: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
L_800B10FC:
    // 0x800B10FC: sb          $v1, 0x2F($a0)
    MEM_B(0X2F, ctx->r4) = ctx->r3;
    // 0x800B1100: lwc1        $f6, -0x24FC($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, -0X24FC);
    // 0x800B1104: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x800B1108: lbu         $v1, -0x2539($v0)
    ctx->r3 = MEM_BU(ctx->r2, -0X2539);
    // 0x800B110C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800B1110: beq         $v1, $v0, L_800B1124
    if (ctx->r3 == ctx->r2) {
        // 0x800B1114: addu        $s2, $zero, $zero
        ctx->r18 = ADD32(0, 0);
            goto L_800B1124;
    }
    // 0x800B1114: addu        $s2, $zero, $zero
    ctx->r18 = ADD32(0, 0);
    // 0x800B1118: mtc1        $zero, $f22
    ctx->f22.u32l = 0;
    // 0x800B111C: j           L_800B11B0
    // 0x800B1120: lui         $s6, 0x8000
    ctx->r22 = S32(0X8000 << 16);
        goto L_800B11B0;
    // 0x800B1120: lui         $s6, 0x8000
    ctx->r22 = S32(0X8000 << 16);
L_800B1124:
    // 0x800B1124: lui         $s0, 0x800D
    ctx->r16 = S32(0X800D << 16);
    // 0x800B1128: lwc1        $f2, -0x2510($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, -0X2510);
    // 0x800B112C: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800B1130: lwc1        $f0, 0x5ADC($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X5ADC);
    // 0x800B1134: mul.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x800B1138: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x800B113C: lwc1        $f4, -0x2508($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, -0X2508);
    // 0x800B1140: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800B1144: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x800B1148: mul.s       $f22, $f2, $f6
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f22.fl = MUL_S(ctx->f2.fl, ctx->f6.fl);
    // 0x800B114C: bc1f        L_800B11B0
    if (!c1cs) {
        // 0x800B1150: lui         $s6, 0x8000
        ctx->r22 = S32(0X8000 << 16);
            goto L_800B11B0;
    }
    // 0x800B1150: lui         $s6, 0x8000
    ctx->r22 = S32(0X8000 << 16);
    // 0x800B1154: jal         0x80003430
    // 0x800B1158: addu        $s2, $zero, $zero
    ctx->r18 = ADD32(0, 0);
    rand_recomp(rdram, ctx);
        goto after_23;
    // 0x800B1158: addu        $s2, $zero, $zero
    ctx->r18 = ADD32(0, 0);
    after_23:
    // 0x800B115C: lui         $v1, 0x8208
    ctx->r3 = S32(0X8208 << 16);
    // 0x800B1160: ori         $v1, $v1, 0x2083
    ctx->r3 = ctx->r3 | 0X2083;
    // 0x800B1164: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x800B1168: sra         $a0, $v0, 16
    ctx->r4 = S32(SIGNED(ctx->r2) >> 16);
    // 0x800B116C: mult        $a0, $v1
    result = S64(S32(ctx->r4)) * S64(S32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800B1170: sra         $v0, $v0, 31
    ctx->r2 = S32(SIGNED(ctx->r2) >> 31);
    // 0x800B1174: lwc1        $f2, -0x2510($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, -0X2510);
    // 0x800B1178: mfhi        $t0
    ctx->r8 = hi;
    // 0x800B117C: addu        $v1, $t0, $a0
    ctx->r3 = ADD32(ctx->r8, ctx->r4);
    // 0x800B1180: sra         $v1, $v1, 5
    ctx->r3 = S32(SIGNED(ctx->r3) >> 5);
    // 0x800B1184: subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // 0x800B1188: sll         $v0, $v1, 6
    ctx->r2 = S32(ctx->r3 << 6);
    // 0x800B118C: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x800B1190: subu        $a0, $a0, $v0
    ctx->r4 = SUB32(ctx->r4, ctx->r2);
    // 0x800B1194: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x800B1198: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    // 0x800B119C: addiu       $a0, $a0, 0x50
    ctx->r4 = ADD32(ctx->r4, 0X50);
    // 0x800B11A0: mtc1        $a0, $f0
    ctx->f0.u32l = ctx->r4;
    // 0x800B11A4: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x800B11A8: mul.s       $f22, $f2, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f22.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x800B11AC: lui         $s6, 0x8000
    ctx->r22 = S32(0X8000 << 16);
L_800B11B0:
    // 0x800B11B0: lui         $s5, 0x800D
    ctx->r21 = S32(0X800D << 16);
    // 0x800B11B4: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x800B11B8: addiu       $s1, $v0, -0x2080
    ctx->r17 = ADD32(ctx->r2, -0X2080);
    // 0x800B11BC: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x800B11C0: addiu       $s4, $v0, -0x38D8
    ctx->r20 = ADD32(ctx->r2, -0X38D8);
    // 0x800B11C4: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x800B11C8: addiu       $s3, $v0, -0x38FC
    ctx->r19 = ADD32(ctx->r2, -0X38FC);
    // 0x800B11CC: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x800B11D0: addiu       $s0, $v0, -0x2250
    ctx->r16 = ADD32(ctx->r2, -0X2250);
    // 0x800B11D4: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800B11D8: lwc1        $f30, 0x5AE0($at)
    ctx->f30.u32l = MEM_W(ctx->r1, 0X5AE0);
    // 0x800B11DC: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800B11E0: lwc1        $f20, 0x5AE4($at)
    ctx->f20.u32l = MEM_W(ctx->r1, 0X5AE4);
    // 0x800B11E4: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800B11E8: lwc1        $f28, 0x5AE8($at)
    ctx->f28.u32l = MEM_W(ctx->r1, 0X5AE8);
L_800B11EC:
    // 0x800B11EC: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x800B11F0: lbu         $a0, -0x253F($v0)
    ctx->r4 = MEM_BU(ctx->r2, -0X253F);
    // 0x800B11F4: jal         0x800C63C0
    // 0x800B11F8: nop

    getAvailablePlayerCraftFlagsIgnoreUnlocks(rdram, ctx);
        goto after_24;
    // 0x800B11F8: nop

    after_24:
    // 0x800B11FC: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x800B1200: sllv        $v1, $v1, $s2
    ctx->r3 = S32(ctx->r3 << (ctx->r18 & 31));
    // 0x800B1204: and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // 0x800B1208: beql        $v0, $zero, L_800B12D0
    if (ctx->r2 == 0) {
        // 0x800B120C: addiu       $s1, $s1, 0x4
        ctx->r17 = ADD32(ctx->r17, 0X4);
            goto L_800B12D0;
    }
    goto skip_11;
    // 0x800B120C: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    skip_11:
    // 0x800B1210: c.le.s      $f30, $f22
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 22);
    c1cs = ctx->f30.fl <= ctx->f22.fl;
    // 0x800B1214: nop

    // 0x800B1218: bc1t        L_800B1230
    if (c1cs) {
        // 0x800B121C: addu        $v1, $s0, $zero
        ctx->r3 = ADD32(ctx->r16, 0);
            goto L_800B1230;
    }
    // 0x800B121C: addu        $v1, $s0, $zero
    ctx->r3 = ADD32(ctx->r16, 0);
    // 0x800B1220: trunc.w.s   $f10, $f22
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 22);
    ctx->f10.u32l = TRUNC_W_S(ctx->f22.fl);
    // 0x800B1224: mfc1        $v0, $f10
    ctx->r2 = (int32_t)ctx->f10.u32l;
    // 0x800B1228: j           L_800B1244
    // 0x800B122C: sb          $v0, 0x2F($v1)
    MEM_B(0X2F, ctx->r3) = ctx->r2;
        goto L_800B1244;
    // 0x800B122C: sb          $v0, 0x2F($v1)
    MEM_B(0X2F, ctx->r3) = ctx->r2;
L_800B1230:
    // 0x800B1230: sub.s       $f0, $f22, $f30
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f0.fl = ctx->f22.fl - ctx->f30.fl;
    // 0x800B1234: trunc.w.s   $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    ctx->f10.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800B1238: mfc1        $v0, $f10
    ctx->r2 = (int32_t)ctx->f10.u32l;
    // 0x800B123C: or          $v0, $v0, $s6
    ctx->r2 = ctx->r2 | ctx->r22;
    // 0x800B1240: sb          $v0, 0x2F($v1)
    MEM_B(0X2F, ctx->r3) = ctx->r2;
L_800B1244:
    // 0x800B1244: lwc1        $f0, 0x0($s3)
    ctx->f0.u32l = MEM_W(ctx->r19, 0X0);
    // 0x800B1248: mul.s       $f0, $f26, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = MUL_S(ctx->f26.fl, ctx->f0.fl);
    // 0x800B124C: swc1        $f0, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f0.u32l;
    // 0x800B1250: mov.s       $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    ctx->f4.fl = ctx->f0.fl;
    // 0x800B1254: lwc1        $f0, 0x0($s4)
    ctx->f0.u32l = MEM_W(ctx->r20, 0X0);
    // 0x800B1258: mul.s       $f0, $f24, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = MUL_S(ctx->f24.fl, ctx->f0.fl);
    // 0x800B125C: nop

    // 0x800B1260: mul.s       $f4, $f4, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = MUL_S(ctx->f4.fl, ctx->f20.fl);
    // 0x800B1264: swc1        $f0, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->f0.u32l;
    // 0x800B1268: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
    // 0x800B126C: mul.s       $f2, $f2, $f20
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f20.fl);
    // 0x800B1270: sub.s       $f4, $f4, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = ctx->f4.fl - ctx->f20.fl;
    // 0x800B1274: mul.s       $f4, $f4, $f28
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f4.fl = MUL_S(ctx->f4.fl, ctx->f28.fl);
    // 0x800B1278: lh          $v0, 0x0($s1)
    ctx->r2 = MEM_H(ctx->r17, 0X0);
    // 0x800B127C: sub.s       $f2, $f2, $f20
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f2.fl = ctx->f2.fl - ctx->f20.fl;
    // 0x800B1280: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x800B1284: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x800B1288: sub.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f4.fl;
    // 0x800B128C: mul.s       $f2, $f2, $f28
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f28.fl);
    // 0x800B1290: swc1        $f0, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f0.u32l;
    // 0x800B1294: lh          $v0, 0x2($s1)
    ctx->r2 = MEM_H(ctx->r17, 0X2);
    // 0x800B1298: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x800B129C: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x800B12A0: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x800B12A4: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x800B12A8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x800B12AC: c.eq.s      $f22, $f2
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f22.fl == ctx->f2.fl;
    // 0x800B12B0: nop

    // 0x800B12B4: bc1f        L_800B12C0
    if (!c1cs) {
        // 0x800B12B8: swc1        $f0, 0x1C($s0)
        MEM_W(0X1C, ctx->r16) = ctx->f0.u32l;
            goto L_800B12C0;
    }
    // 0x800B12B8: swc1        $f0, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f0.u32l;
    // 0x800B12BC: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
L_800B12C0:
    // 0x800B12C0: lw          $a0, -0x2324($s5)
    ctx->r4 = MEM_W(ctx->r21, -0X2324);
    // 0x800B12C4: jal         0x800646AC
    // 0x800B12C8: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    func_800646AC(rdram, ctx);
        goto after_25;
    // 0x800B12C8: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    after_25:
    // 0x800B12CC: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
L_800B12D0:
    // 0x800B12D0: addiu       $s4, $s4, 0x4
    ctx->r20 = ADD32(ctx->r20, 0X4);
    // 0x800B12D4: addiu       $s3, $s3, 0x4
    ctx->r19 = ADD32(ctx->r19, 0X4);
    // 0x800B12D8: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x800B12DC: sltiu       $v0, $s2, 0x9
    ctx->r2 = ctx->r18 < 0X9 ? 1 : 0;
    // 0x800B12E0: bne         $v0, $zero, L_800B11EC
    if (ctx->r2 != 0) {
        // 0x800B12E4: addiu       $s0, $s0, 0x30
        ctx->r16 = ADD32(ctx->r16, 0X30);
            goto L_800B11EC;
    }
    // 0x800B12E4: addiu       $s0, $s0, 0x30
    ctx->r16 = ADD32(ctx->r16, 0X30);
    // 0x800B12E8: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x800B12EC: lwc1        $f0, -0x24F8($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, -0X24F8);
    // 0x800B12F0: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800B12F4: lwc1        $f2, 0x5AEC($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X5AEC);
    // 0x800B12F8: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x800B12FC: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800B1300: lwc1        $f2, 0x5AF0($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X5AF0);
    // 0x800B1304: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x800B1308: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800B130C: lwc1        $f8, 0x5AF4($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X5AF4);
    // 0x800B1310: sub.s       $f4, $f8, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f8.fl - ctx->f0.fl;
    // 0x800B1314: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x800B1318: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x800B131C: nop

    // 0x800B1320: bc1tl       L_800B1328
    if (c1cs) {
        // 0x800B1324: mov.s       $f4, $f6
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    ctx->f4.fl = ctx->f6.fl;
            goto L_800B1328;
    }
    goto skip_12;
    // 0x800B1324: mov.s       $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    ctx->f4.fl = ctx->f6.fl;
    skip_12:
L_800B1328:
    // 0x800B1328: c.lt.s      $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f8.fl < ctx->f4.fl;
    // 0x800B132C: nop

    // 0x800B1330: bc1tl       L_800B1338
    if (c1cs) {
        // 0x800B1334: mov.s       $f4, $f8
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    ctx->f4.fl = ctx->f8.fl;
            goto L_800B1338;
    }
    goto skip_13;
    // 0x800B1334: mov.s       $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    ctx->f4.fl = ctx->f8.fl;
    skip_13:
L_800B1338:
    // 0x800B1338: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x800B133C: lbu         $v1, -0x253C($v0)
    ctx->r3 = MEM_BU(ctx->r2, -0X253C);
    // 0x800B1340: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // 0x800B1344: bne         $v1, $v0, L_800B135C
    if (ctx->r3 != ctx->r2) {
        // 0x800B1348: lui         $v0, 0x800D
        ctx->r2 = S32(0X800D << 16);
            goto L_800B135C;
    }
    // 0x800B1348: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x800B134C: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x800B1350: lwc1        $f0, -0x2510($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, -0X2510);
    // 0x800B1354: mul.s       $f4, $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x800B1358: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
L_800B135C:
    // 0x800B135C: lwc1        $f0, -0x24FC($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, -0X24FC);
    // 0x800B1360: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800B1364: lwc1        $f2, 0x5AF8($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X5AF8);
    // 0x800B1368: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x800B136C: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800B1370: lwc1        $f2, 0x5AFC($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X5AFC);
    // 0x800B1374: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x800B1378: c.lt.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl < ctx->f6.fl;
    // 0x800B137C: nop

    // 0x800B1380: bc1tl       L_800B1388
    if (c1cs) {
        // 0x800B1384: mov.s       $f0, $f6
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    ctx->f0.fl = ctx->f6.fl;
            goto L_800B1388;
    }
    goto skip_14;
    // 0x800B1384: mov.s       $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    ctx->f0.fl = ctx->f6.fl;
    skip_14:
L_800B1388:
    // 0x800B1388: c.lt.s      $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f8.fl < ctx->f0.fl;
    // 0x800B138C: nop

    // 0x800B1390: bc1tl       L_800B1398
    if (c1cs) {
        // 0x800B1394: mov.s       $f0, $f8
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    ctx->f0.fl = ctx->f8.fl;
            goto L_800B1398;
    }
    goto skip_15;
    // 0x800B1394: mov.s       $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    ctx->f0.fl = ctx->f8.fl;
    skip_15:
L_800B1398:
    // 0x800B1398: mul.s       $f4, $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x800B139C: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800B13A0: lwc1        $f0, 0x5B00($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X5B00);
    // 0x800B13A4: mul.s       $f0, $f4, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x800B13A8: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800B13AC: lwc1        $f2, 0x5B04($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X5B04);
    // 0x800B13B0: c.le.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl <= ctx->f0.fl;
    // 0x800B13B4: nop

    // 0x800B13B8: bc1tl       L_800B13D0
    if (c1cs) {
        // 0x800B13BC: sub.s       $f0, $f0, $f2
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
            goto L_800B13D0;
    }
    goto skip_16;
    // 0x800B13BC: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    skip_16:
    // 0x800B13C0: trunc.w.s   $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    ctx->f10.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800B13C4: mfc1        $a2, $f10
    ctx->r6 = (int32_t)ctx->f10.u32l;
    // 0x800B13C8: j           L_800B13E4
    // 0x800B13CC: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
        goto L_800B13E4;
    // 0x800B13CC: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
L_800B13D0:
    // 0x800B13D0: lui         $v0, 0x8000
    ctx->r2 = S32(0X8000 << 16);
    // 0x800B13D4: trunc.w.s   $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    ctx->f10.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800B13D8: mfc1        $a2, $f10
    ctx->r6 = (int32_t)ctx->f10.u32l;
    // 0x800B13DC: or          $a2, $a2, $v0
    ctx->r6 = ctx->r6 | ctx->r2;
    // 0x800B13E0: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
L_800B13E4:
    // 0x800B13E4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x800B13E8: jal         0x80061C74
    // 0x800B13EC: andi        $a2, $a2, 0xFF
    ctx->r6 = ctx->r6 & 0XFF;
    func_80061C74(rdram, ctx);
        goto after_26;
    // 0x800B13EC: andi        $a2, $a2, 0xFF
    ctx->r6 = ctx->r6 & 0XFF;
    after_26:
    // 0x800B13F0: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x800B13F4: lw          $s6, 0x28($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X28);
    // 0x800B13F8: lw          $s5, 0x24($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X24);
    // 0x800B13FC: lw          $s4, 0x20($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X20);
    // 0x800B1400: lw          $s3, 0x1C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X1C);
    // 0x800B1404: lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X18);
    // 0x800B1408: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x800B140C: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x800B1410: ldc1        $f30, 0x58($sp)
    CHECK_FR(ctx, 30);
    ctx->f30.u64 = LD(ctx->r29, 0X58);
    // 0x800B1414: ldc1        $f28, 0x50($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0X50);
    // 0x800B1418: ldc1        $f26, 0x48($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X48);
    // 0x800B141C: ldc1        $f24, 0x40($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X40);
    // 0x800B1420: ldc1        $f22, 0x38($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X38);
    // 0x800B1424: ldc1        $f20, 0x30($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X30);
    // 0x800B1428: jr          $ra
    // 0x800B142C: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    return;
    // 0x800B142C: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
;}
RECOMP_FUNC void func_800B0A88(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B0A88: addiu       $sp, $sp, -0xA0
    ctx->r29 = ADD32(ctx->r29, -0XA0);
    // 0x800B0A8C: sdc1        $f20, 0x98($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X98, ctx->r29);
    // 0x800B0A90: mtc1        $a1, $f20
    ctx->f20.u32l = ctx->r5;
    // 0x800B0A94: sw          $s1, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r17;
    // 0x800B0A98: addu        $s1, $a0, $zero
    ctx->r17 = ADD32(ctx->r4, 0);
    // 0x800B0A9C: sw          $ra, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->r31;
    // 0x800B0AA0: sw          $s3, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->r19;
    // 0x800B0AA4: sw          $s2, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r18;
    // 0x800B0AA8: sw          $s0, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r16;
    // 0x800B0AAC: lwc1        $f2, 0x14($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0X14);
    // 0x800B0AB0: lw          $v1, 0xB8($s1)
    ctx->r3 = MEM_W(ctx->r17, 0XB8);
    // 0x800B0AB4: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800B0AB8: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x800B0ABC: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800B0AC0: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800B0AC4: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800B0AC8: sll         $v0, $v0, 5
    ctx->r2 = S32(ctx->r2 << 5);
    // 0x800B0ACC: lui         $v1, 0x8014
    ctx->r3 = S32(0X8014 << 16);
    // 0x800B0AD0: addiu       $v1, $v1, -0x7FF4
    ctx->r3 = ADD32(ctx->r3, -0X7FF4);
    // 0x800B0AD4: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x800B0AD8: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800B0ADC: lwc1        $f0, 0x5634($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X5634);
    // 0x800B0AE0: bc1f        L_800B0AF0
    if (!c1cs) {
        // 0x800B0AE4: addu        $s2, $v0, $v1
        ctx->r18 = ADD32(ctx->r2, ctx->r3);
            goto L_800B0AF0;
    }
    // 0x800B0AE4: addu        $s2, $v0, $v1
    ctx->r18 = ADD32(ctx->r2, ctx->r3);
    // 0x800B0AE8: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800B0AEC: lwc1        $f0, 0x5638($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X5638);
L_800B0AF0:
    // 0x800B0AF0: mul.s       $f0, $f20, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = MUL_S(ctx->f20.fl, ctx->f0.fl);
    // 0x800B0AF4: add.s       $f0, $f2, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x800B0AF8: swc1        $f0, 0x14($s1)
    MEM_W(0X14, ctx->r17) = ctx->f0.u32l;
    // 0x800B0AFC: lwc1        $f0, 0x14($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X14);
    // 0x800B0B00: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800B0B04: lwc1        $f2, 0x563C($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X563C);
    // 0x800B0B08: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x800B0B0C: nop

    // 0x800B0B10: bc1tl       L_800B0B18
    if (c1cs) {
        // 0x800B0B14: swc1        $f2, 0x14($s1)
        MEM_W(0X14, ctx->r17) = ctx->f2.u32l;
            goto L_800B0B18;
    }
    goto skip_0;
    // 0x800B0B14: swc1        $f2, 0x14($s1)
    MEM_W(0X14, ctx->r17) = ctx->f2.u32l;
    skip_0:
L_800B0B18:
    // 0x800B0B18: addiu       $s0, $s1, 0x10
    ctx->r16 = ADD32(ctx->r17, 0X10);
    // 0x800B0B1C: jal         0x800AA350
    // 0x800B0B20: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_800AA350(rdram, ctx);
        goto after_0;
    // 0x800B0B20: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_0:
    // 0x800B0B24: lwc1        $f0, 0x140($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X140);
    // 0x800B0B28: mul.s       $f0, $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f20.fl);
    // 0x800B0B2C: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    // 0x800B0B30: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x800B0B34: jal         0x8001D144
    // 0x800B0B38: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    func_8001D144(rdram, ctx);
        goto after_1;
    // 0x800B0B38: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    after_1:
    // 0x800B0B3C: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    // 0x800B0B40: addiu       $s0, $s1, 0x1C
    ctx->r16 = ADD32(ctx->r17, 0X1C);
    // 0x800B0B44: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x800B0B48: jal         0x8001D3C4
    // 0x800B0B4C: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    func_8001D3C4(rdram, ctx);
        goto after_2;
    // 0x800B0B4C: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    after_2:
    // 0x800B0B50: jal         0x800AA350
    // 0x800B0B54: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_800AA350(rdram, ctx);
        goto after_3;
    // 0x800B0B54: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_3:
    // 0x800B0B58: addiu       $s0, $s1, 0x4
    ctx->r16 = ADD32(ctx->r17, 0X4);
    // 0x800B0B5C: jal         0x80059F10
    // 0x800B0B60: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_80059F10(rdram, ctx);
        goto after_4;
    // 0x800B0B60: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_4:
    // 0x800B0B64: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // 0x800B0B68: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x800B0B6C: jal         0x80059B50
    // 0x800B0B70: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    func_80059B50(rdram, ctx);
        goto after_5;
    // 0x800B0B70: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    after_5:
    // 0x800B0B74: lwc1        $f8, 0xE8($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0XE8);
    // 0x800B0B78: lwc1        $f0, 0x10($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X10);
    // 0x800B0B7C: mul.s       $f8, $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x800B0B80: lwc1        $f6, 0xE8($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0XE8);
    // 0x800B0B84: lwc1        $f0, 0x14($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X14);
    // 0x800B0B88: mul.s       $f6, $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x800B0B8C: lwc1        $f4, 0xE8($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0XE8);
    // 0x800B0B90: lwc1        $f0, 0x18($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X18);
    // 0x800B0B94: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x800B0B98: mul.s       $f4, $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x800B0B9C: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x800B0BA0: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800B0BA4: lwc1        $f2, 0x5640($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X5640);
    // 0x800B0BA8: lwc1        $f0, 0xE8($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0XE8);
    // 0x800B0BAC: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x800B0BB0: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x800B0BB4: addiu       $a3, $s1, 0x28
    ctx->r7 = ADD32(ctx->r17, 0X28);
    // 0x800B0BB8: swc1        $f8, 0x28($s1)
    MEM_W(0X28, ctx->r17) = ctx->f8.u32l;
    // 0x800B0BBC: swc1        $f6, 0x2C($s1)
    MEM_W(0X2C, ctx->r17) = ctx->f6.u32l;
    // 0x800B0BC0: swc1        $f4, 0x30($s1)
    MEM_W(0X30, ctx->r17) = ctx->f4.u32l;
    // 0x800B0BC4: jal         0x800AA3E0
    // 0x800B0BC8: swc1        $f0, 0xE8($s1)
    MEM_W(0XE8, ctx->r17) = ctx->f0.u32l;
    func_800AA3E0(rdram, ctx);
        goto after_6;
    // 0x800B0BC8: swc1        $f0, 0xE8($s1)
    MEM_W(0XE8, ctx->r17) = ctx->f0.u32l;
    after_6:
    // 0x800B0BCC: lwc1        $f0, 0x4($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X4);
    // 0x800B0BD0: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // 0x800B0BD4: swc1        $f0, 0x24($s2)
    MEM_W(0X24, ctx->r18) = ctx->f0.u32l;
    // 0x800B0BD8: lwc1        $f0, 0x8($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X8);
    // 0x800B0BDC: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    // 0x800B0BE0: swc1        $f0, 0x28($s2)
    MEM_W(0X28, ctx->r18) = ctx->f0.u32l;
    // 0x800B0BE4: lwc1        $f0, 0xC($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0XC);
    // 0x800B0BE8: addiu       $a2, $s1, 0xCC
    ctx->r6 = ADD32(ctx->r17, 0XCC);
    // 0x800B0BEC: jal         0x800A9B80
    // 0x800B0BF0: swc1        $f0, 0x2C($s2)
    MEM_W(0X2C, ctx->r18) = ctx->f0.u32l;
    func_800A9B80(rdram, ctx);
        goto after_7;
    // 0x800B0BF0: swc1        $f0, 0x2C($s2)
    MEM_W(0X2C, ctx->r18) = ctx->f0.u32l;
    after_7:
    // 0x800B0BF4: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x800B0BF8: jal         0x80059D18
    // 0x800B0BFC: addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    func_80059D18(rdram, ctx);
        goto after_8;
    // 0x800B0BFC: addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    after_8:
    // 0x800B0C00: lwc1        $f0, 0x18C($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X18C);
    // 0x800B0C04: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x800B0C08: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x800B0C0C: nop

    // 0x800B0C10: bc1f        L_800B0C3C
    if (!c1cs) {
        // 0x800B0C14: nop
    
            goto L_800B0C3C;
    }
    // 0x800B0C14: nop

    // 0x800B0C18: sub.s       $f0, $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f20.fl;
    // 0x800B0C1C: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x800B0C20: nop

    // 0x800B0C24: bc1f        L_800B0C3C
    if (!c1cs) {
        // 0x800B0C28: swc1        $f0, 0x18C($s1)
        MEM_W(0X18C, ctx->r17) = ctx->f0.u32l;
            goto L_800B0C3C;
    }
    // 0x800B0C28: swc1        $f0, 0x18C($s1)
    MEM_W(0X18C, ctx->r17) = ctx->f0.u32l;
    // 0x800B0C2C: swc1        $f2, 0x18C($s1)
    MEM_W(0X18C, ctx->r17) = ctx->f2.u32l;
    // 0x800B0C30: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x800B0C34: jal         0x800B01E4
    // 0x800B0C38: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    func_800B01E4(rdram, ctx);
        goto after_9;
    // 0x800B0C38: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    after_9:
L_800B0C3C:
    // 0x800B0C3C: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x800B0C40: jal         0x800AECF8
    // 0x800B0C44: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    func_800AECF8(rdram, ctx);
        goto after_10;
    // 0x800B0C44: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    after_10:
    // 0x800B0C48: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x800B0C4C: addiu       $a2, $s1, 0xCC
    ctx->r6 = ADD32(ctx->r17, 0XCC);
    // 0x800B0C50: addiu       $a3, $s1, 0xD0
    ctx->r7 = ADD32(ctx->r17, 0XD0);
    // 0x800B0C54: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x800B0C58: addiu       $v0, $s1, 0xD4
    ctx->r2 = ADD32(ctx->r17, 0XD4);
    // 0x800B0C5C: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // 0x800B0C60: addiu       $v0, $sp, 0x78
    ctx->r2 = ADD32(ctx->r29, 0X78);
    // 0x800B0C64: jal         0x800FEF10
    // 0x800B0C68: sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    func_800FEF10(rdram, ctx);
        goto after_11;
    // 0x800B0C68: sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    after_11:
    // 0x800B0C6C: andi        $v1, $v0, 0xFF
    ctx->r3 = ctx->r2 & 0XFF;
    // 0x800B0C70: addiu       $s3, $zero, 0x1
    ctx->r19 = ADD32(0, 0X1);
    // 0x800B0C74: beq         $v1, $s3, L_800B0C8C
    if (ctx->r3 == ctx->r19) {
        // 0x800B0C78: addiu       $v0, $zero, 0x2
        ctx->r2 = ADD32(0, 0X2);
            goto L_800B0C8C;
    }
    // 0x800B0C78: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x800B0C7C: beq         $v1, $v0, L_800B0DAC
    if (ctx->r3 == ctx->r2) {
        // 0x800B0C80: nop
    
            goto L_800B0DAC;
    }
    // 0x800B0C80: nop

    // 0x800B0C84: j           L_800B0ED4
    // 0x800B0C88: nop

        goto L_800B0ED4;
    // 0x800B0C88: nop

L_800B0C8C:
    // 0x800B0C8C: lbu         $v0, 0x78($sp)
    ctx->r2 = MEM_BU(ctx->r29, 0X78);
    // 0x800B0C90: bne         $v0, $zero, L_800B0CD8
    if (ctx->r2 != 0) {
        // 0x800B0C94: addu        $a0, $zero, $zero
        ctx->r4 = ADD32(0, 0);
            goto L_800B0CD8;
    }
    // 0x800B0C94: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x800B0C98: addiu       $a1, $s1, 0x4
    ctx->r5 = ADD32(ctx->r17, 0X4);
    // 0x800B0C9C: addiu       $a2, $s1, 0x28
    ctx->r6 = ADD32(ctx->r17, 0X28);
    // 0x800B0CA0: lui         $a3, 0x41A0
    ctx->r7 = S32(0X41A0 << 16);
    // 0x800B0CA4: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800B0CA8: lwc1        $f0, 0x5644($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X5644);
    // 0x800B0CAC: addiu       $v0, $zero, 0x3E
    ctx->r2 = ADD32(0, 0X3E);
    // 0x800B0CB0: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // 0x800B0CB4: addiu       $v0, $zero, 0x7A
    ctx->r2 = ADD32(0, 0X7A);
    // 0x800B0CB8: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x800B0CBC: addiu       $v0, $zero, 0x28
    ctx->r2 = ADD32(0, 0X28);
    // 0x800B0CC0: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x800B0CC4: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x800B0CC8: jal         0x800989D8
    // 0x800B0CCC: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    func_800989D8(rdram, ctx);
        goto after_12;
    // 0x800B0CCC: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    after_12:
    // 0x800B0CD0: j           L_800B0D98
    // 0x800B0CD4: nop

        goto L_800B0D98;
    // 0x800B0CD4: nop

L_800B0CD8:
    // 0x800B0CD8: addiu       $s0, $s1, 0x4
    ctx->r16 = ADD32(ctx->r17, 0X4);
    // 0x800B0CDC: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x800B0CE0: addiu       $a2, $s1, 0x28
    ctx->r6 = ADD32(ctx->r17, 0X28);
    // 0x800B0CE4: lui         $a3, 0x41C0
    ctx->r7 = S32(0X41C0 << 16);
    // 0x800B0CE8: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800B0CEC: lwc1        $f0, 0x5648($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X5648);
    // 0x800B0CF0: addiu       $v0, $zero, 0xC
    ctx->r2 = ADD32(0, 0XC);
    // 0x800B0CF4: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // 0x800B0CF8: addiu       $v0, $zero, 0x73
    ctx->r2 = ADD32(0, 0X73);
    // 0x800B0CFC: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x800B0D00: addiu       $v0, $zero, 0x28
    ctx->r2 = ADD32(0, 0X28);
    // 0x800B0D04: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x800B0D08: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x800B0D0C: jal         0x800989D8
    // 0x800B0D10: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    func_800989D8(rdram, ctx);
        goto after_13;
    // 0x800B0D10: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    after_13:
    // 0x800B0D14: lui         $a2, 0x8014
    ctx->r6 = S32(0X8014 << 16);
    // 0x800B0D18: lwc1        $f12, 0x4($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X4);
    // 0x800B0D1C: lwc1        $f14, 0xC($s1)
    ctx->f14.u32l = MEM_W(ctx->r17, 0XC);
    // 0x800B0D20: jal         0x800698F4
    // 0x800B0D24: addiu       $a2, $a2, -0x7FA8
    ctx->r6 = ADD32(ctx->r6, -0X7FA8);
    func_800698F4(rdram, ctx);
        goto after_14;
    // 0x800B0D24: addiu       $a2, $a2, -0x7FA8
    ctx->r6 = ADD32(ctx->r6, -0X7FA8);
    after_14:
    // 0x800B0D28: beq         $v0, $s3, L_800B0D98
    if (ctx->r2 == ctx->r19) {
        // 0x800B0D2C: addiu       $a0, $s1, 0x10
        ctx->r4 = ADD32(ctx->r17, 0X10);
            goto L_800B0D98;
    }
    // 0x800B0D2C: addiu       $a0, $s1, 0x10
    ctx->r4 = ADD32(ctx->r17, 0X10);
    // 0x800B0D30: jal         0x8001CF58
    // 0x800B0D34: sw          $zero, 0x14($s1)
    MEM_W(0X14, ctx->r17) = 0;
    normalize_vector(rdram, ctx);
        goto after_15;
    // 0x800B0D34: sw          $zero, 0x14($s1)
    MEM_W(0X14, ctx->r17) = 0;
    after_15:
    // 0x800B0D38: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800B0D3C: lwc1        $f20, 0x564C($at)
    ctx->f20.u32l = MEM_W(ctx->r1, 0X564C);
    // 0x800B0D40: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x800B0D44: sw          $zero, 0x1C($s1)
    MEM_W(0X1C, ctx->r17) = 0;
    // 0x800B0D48: sw          $zero, 0x24($s1)
    MEM_W(0X24, ctx->r17) = 0;
    // 0x800B0D4C: jal         0x80059F10
    // 0x800B0D50: swc1        $f20, 0x20($s1)
    MEM_W(0X20, ctx->r17) = ctx->f20.u32l;
    func_80059F10(rdram, ctx);
        goto after_16;
    // 0x800B0D50: swc1        $f20, 0x20($s1)
    MEM_W(0X20, ctx->r17) = ctx->f20.u32l;
    after_16:
    // 0x800B0D54: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x800B0D58: lw          $v0, 0xB8($s1)
    ctx->r2 = MEM_W(ctx->r17, 0XB8);
    // 0x800B0D5C: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x800B0D60: sll         $a0, $v0, 2
    ctx->r4 = S32(ctx->r2 << 2);
    // 0x800B0D64: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // 0x800B0D68: sll         $a0, $a0, 2
    ctx->r4 = S32(ctx->r4 << 2);
    // 0x800B0D6C: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // 0x800B0D70: sll         $a0, $a0, 5
    ctx->r4 = S32(ctx->r4 << 5);
    // 0x800B0D74: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x800B0D78: addiu       $v0, $v0, -0x7FF4
    ctx->r2 = ADD32(ctx->r2, -0X7FF4);
    // 0x800B0D7C: jal         0x80059B50
    // 0x800B0D80: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    func_80059B50(rdram, ctx);
        goto after_17;
    // 0x800B0D80: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    after_17:
    // 0x800B0D84: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x800B0D88: lui         $a1, 0x3EC0
    ctx->r5 = S32(0X3EC0 << 16);
    // 0x800B0D8C: lui         $a2, 0x3EF0
    ctx->r6 = S32(0X3EF0 << 16);
    // 0x800B0D90: jal         0x8006C6FC
    // 0x800B0D94: addiu       $a3, $zero, 0xC
    ctx->r7 = ADD32(0, 0XC);
    func_8006C6FC(rdram, ctx);
        goto after_18;
    // 0x800B0D94: addiu       $a3, $zero, 0xC
    ctx->r7 = ADD32(0, 0XC);
    after_18:
L_800B0D98:
    // 0x800B0D98: lbu         $a1, 0x78($sp)
    ctx->r5 = MEM_BU(ctx->r29, 0X78);
    // 0x800B0D9C: jal         0x800B01E4
    // 0x800B0DA0: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    func_800B01E4(rdram, ctx);
        goto after_19;
    // 0x800B0DA0: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    after_19:
    // 0x800B0DA4: j           L_800B0F34
    // 0x800B0DA8: addiu       $s0, $s1, 0x4
    ctx->r16 = ADD32(ctx->r17, 0X4);
        goto L_800B0F34;
    // 0x800B0DA8: addiu       $s0, $s1, 0x4
    ctx->r16 = ADD32(ctx->r17, 0X4);
L_800B0DAC:
    // 0x800B0DAC: lbu         $v0, 0x78($sp)
    ctx->r2 = MEM_BU(ctx->r29, 0X78);
    // 0x800B0DB0: bne         $v0, $zero, L_800B0DF8
    if (ctx->r2 != 0) {
        // 0x800B0DB4: addu        $a0, $zero, $zero
        ctx->r4 = ADD32(0, 0);
            goto L_800B0DF8;
    }
    // 0x800B0DB4: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x800B0DB8: addiu       $a1, $s1, 0x4
    ctx->r5 = ADD32(ctx->r17, 0X4);
    // 0x800B0DBC: addiu       $a2, $s1, 0x28
    ctx->r6 = ADD32(ctx->r17, 0X28);
    // 0x800B0DC0: lui         $a3, 0x41A0
    ctx->r7 = S32(0X41A0 << 16);
    // 0x800B0DC4: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800B0DC8: lwc1        $f0, 0x5650($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X5650);
    // 0x800B0DCC: addiu       $v0, $zero, 0x3E
    ctx->r2 = ADD32(0, 0X3E);
    // 0x800B0DD0: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // 0x800B0DD4: addiu       $v0, $zero, 0x7A
    ctx->r2 = ADD32(0, 0X7A);
    // 0x800B0DD8: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x800B0DDC: addiu       $v0, $zero, 0x28
    ctx->r2 = ADD32(0, 0X28);
    // 0x800B0DE0: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x800B0DE4: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x800B0DE8: jal         0x800989D8
    // 0x800B0DEC: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    func_800989D8(rdram, ctx);
        goto after_20;
    // 0x800B0DEC: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    after_20:
    // 0x800B0DF0: j           L_800B0EB8
    // 0x800B0DF4: nop

        goto L_800B0EB8;
    // 0x800B0DF4: nop

L_800B0DF8:
    // 0x800B0DF8: addiu       $s0, $s1, 0x4
    ctx->r16 = ADD32(ctx->r17, 0X4);
    // 0x800B0DFC: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x800B0E00: addiu       $a2, $s1, 0x28
    ctx->r6 = ADD32(ctx->r17, 0X28);
    // 0x800B0E04: lui         $a3, 0x41C0
    ctx->r7 = S32(0X41C0 << 16);
    // 0x800B0E08: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800B0E0C: lwc1        $f0, 0x5654($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X5654);
    // 0x800B0E10: addiu       $v0, $zero, 0xC
    ctx->r2 = ADD32(0, 0XC);
    // 0x800B0E14: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // 0x800B0E18: addiu       $v0, $zero, 0x73
    ctx->r2 = ADD32(0, 0X73);
    // 0x800B0E1C: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x800B0E20: addiu       $v0, $zero, 0x28
    ctx->r2 = ADD32(0, 0X28);
    // 0x800B0E24: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x800B0E28: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x800B0E2C: jal         0x800989D8
    // 0x800B0E30: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    func_800989D8(rdram, ctx);
        goto after_21;
    // 0x800B0E30: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    after_21:
    // 0x800B0E34: lui         $a2, 0x8014
    ctx->r6 = S32(0X8014 << 16);
    // 0x800B0E38: lwc1        $f12, 0x4($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X4);
    // 0x800B0E3C: lwc1        $f14, 0xC($s1)
    ctx->f14.u32l = MEM_W(ctx->r17, 0XC);
    // 0x800B0E40: jal         0x800698F4
    // 0x800B0E44: addiu       $a2, $a2, -0x7FA8
    ctx->r6 = ADD32(ctx->r6, -0X7FA8);
    func_800698F4(rdram, ctx);
        goto after_22;
    // 0x800B0E44: addiu       $a2, $a2, -0x7FA8
    ctx->r6 = ADD32(ctx->r6, -0X7FA8);
    after_22:
    // 0x800B0E48: beq         $v0, $s3, L_800B0EB8
    if (ctx->r2 == ctx->r19) {
        // 0x800B0E4C: addiu       $a0, $s1, 0x10
        ctx->r4 = ADD32(ctx->r17, 0X10);
            goto L_800B0EB8;
    }
    // 0x800B0E4C: addiu       $a0, $s1, 0x10
    ctx->r4 = ADD32(ctx->r17, 0X10);
    // 0x800B0E50: jal         0x8001CF58
    // 0x800B0E54: sw          $zero, 0x14($s1)
    MEM_W(0X14, ctx->r17) = 0;
    normalize_vector(rdram, ctx);
        goto after_23;
    // 0x800B0E54: sw          $zero, 0x14($s1)
    MEM_W(0X14, ctx->r17) = 0;
    after_23:
    // 0x800B0E58: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800B0E5C: lwc1        $f20, 0x5658($at)
    ctx->f20.u32l = MEM_W(ctx->r1, 0X5658);
    // 0x800B0E60: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x800B0E64: sw          $zero, 0x1C($s1)
    MEM_W(0X1C, ctx->r17) = 0;
    // 0x800B0E68: sw          $zero, 0x24($s1)
    MEM_W(0X24, ctx->r17) = 0;
    // 0x800B0E6C: jal         0x80059F10
    // 0x800B0E70: swc1        $f20, 0x20($s1)
    MEM_W(0X20, ctx->r17) = ctx->f20.u32l;
    func_80059F10(rdram, ctx);
        goto after_24;
    // 0x800B0E70: swc1        $f20, 0x20($s1)
    MEM_W(0X20, ctx->r17) = ctx->f20.u32l;
    after_24:
    // 0x800B0E74: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x800B0E78: lw          $v0, 0xB8($s1)
    ctx->r2 = MEM_W(ctx->r17, 0XB8);
    // 0x800B0E7C: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x800B0E80: sll         $a0, $v0, 2
    ctx->r4 = S32(ctx->r2 << 2);
    // 0x800B0E84: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // 0x800B0E88: sll         $a0, $a0, 2
    ctx->r4 = S32(ctx->r4 << 2);
    // 0x800B0E8C: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // 0x800B0E90: sll         $a0, $a0, 5
    ctx->r4 = S32(ctx->r4 << 5);
    // 0x800B0E94: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x800B0E98: addiu       $v0, $v0, -0x7FF4
    ctx->r2 = ADD32(ctx->r2, -0X7FF4);
    // 0x800B0E9C: jal         0x80059B50
    // 0x800B0EA0: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    func_80059B50(rdram, ctx);
        goto after_25;
    // 0x800B0EA0: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    after_25:
    // 0x800B0EA4: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x800B0EA8: lui         $a1, 0x3EC0
    ctx->r5 = S32(0X3EC0 << 16);
    // 0x800B0EAC: lui         $a2, 0x3EF0
    ctx->r6 = S32(0X3EF0 << 16);
    // 0x800B0EB0: jal         0x8006C6FC
    // 0x800B0EB4: addiu       $a3, $zero, 0xC
    ctx->r7 = ADD32(0, 0XC);
    func_8006C6FC(rdram, ctx);
        goto after_26;
    // 0x800B0EB4: addiu       $a3, $zero, 0xC
    ctx->r7 = ADD32(0, 0XC);
    after_26:
L_800B0EB8:
    // 0x800B0EB8: lbu         $a1, 0x78($sp)
    ctx->r5 = MEM_BU(ctx->r29, 0X78);
    // 0x800B0EBC: jal         0x800B01E4
    // 0x800B0EC0: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    func_800B01E4(rdram, ctx);
        goto after_27;
    // 0x800B0EC0: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    after_27:
    // 0x800B0EC4: jal         0x80059F10
    // 0x800B0EC8: addiu       $a0, $s1, 0x4
    ctx->r4 = ADD32(ctx->r17, 0X4);
    func_80059F10(rdram, ctx);
        goto after_28;
    // 0x800B0EC8: addiu       $a0, $s1, 0x4
    ctx->r4 = ADD32(ctx->r17, 0X4);
    after_28:
    // 0x800B0ECC: j           L_800B0F34
    // 0x800B0ED0: addiu       $s0, $s1, 0x4
    ctx->r16 = ADD32(ctx->r17, 0X4);
        goto L_800B0F34;
    // 0x800B0ED0: addiu       $s0, $s1, 0x4
    ctx->r16 = ADD32(ctx->r17, 0X4);
L_800B0ED4:
    // 0x800B0ED4: lwc1        $f2, 0x140($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0X140);
    // 0x800B0ED8: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800B0EDC: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x800B0EE0: nop

    // 0x800B0EE4: bc1f        L_800B0F0C
    if (!c1cs) {
        // 0x800B0EE8: nop
    
            goto L_800B0F0C;
    }
    // 0x800B0EE8: nop

    // 0x800B0EEC: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800B0EF0: lwc1        $f0, 0x565C($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X565C);
    // 0x800B0EF4: add.s       $f0, $f2, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x800B0EF8: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800B0EFC: lwc1        $f2, 0x5660($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X5660);
    // 0x800B0F00: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x800B0F04: j           L_800B0F28
    // 0x800B0F08: swc1        $f0, 0x140($s1)
    MEM_W(0X140, ctx->r17) = ctx->f0.u32l;
        goto L_800B0F28;
    // 0x800B0F08: swc1        $f0, 0x140($s1)
    MEM_W(0X140, ctx->r17) = ctx->f0.u32l;
L_800B0F0C:
    // 0x800B0F0C: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800B0F10: lwc1        $f0, 0x5664($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X5664);
    // 0x800B0F14: sub.s       $f0, $f2, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f2.fl - ctx->f0.fl;
    // 0x800B0F18: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800B0F1C: lwc1        $f2, 0x5668($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X5668);
    // 0x800B0F20: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x800B0F24: swc1        $f0, 0x140($s1)
    MEM_W(0X140, ctx->r17) = ctx->f0.u32l;
L_800B0F28:
    // 0x800B0F28: bc1tl       L_800B0F30
    if (c1cs) {
        // 0x800B0F2C: swc1        $f2, 0x140($s1)
        MEM_W(0X140, ctx->r17) = ctx->f2.u32l;
            goto L_800B0F30;
    }
    goto skip_1;
    // 0x800B0F2C: swc1        $f2, 0x140($s1)
    MEM_W(0X140, ctx->r17) = ctx->f2.u32l;
    skip_1:
L_800B0F30:
    // 0x800B0F30: addiu       $s0, $s1, 0x4
    ctx->r16 = ADD32(ctx->r17, 0X4);
L_800B0F34:
    // 0x800B0F34: jal         0x80059F10
    // 0x800B0F38: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_80059F10(rdram, ctx);
        goto after_29;
    // 0x800B0F38: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_29:
    // 0x800B0F3C: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // 0x800B0F40: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x800B0F44: jal         0x80059B50
    // 0x800B0F48: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    func_80059B50(rdram, ctx);
        goto after_30;
    // 0x800B0F48: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    after_30:
    // 0x800B0F4C: lw          $v1, 0xB8($s1)
    ctx->r3 = MEM_W(ctx->r17, 0XB8);
    // 0x800B0F50: lwc1        $f0, 0x4($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X4);
    // 0x800B0F54: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x800B0F58: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800B0F5C: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800B0F60: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800B0F64: sll         $v0, $v0, 5
    ctx->r2 = S32(ctx->r2 << 5);
    // 0x800B0F68: lui         $v1, 0x8014
    ctx->r3 = S32(0X8014 << 16);
    // 0x800B0F6C: addiu       $v1, $v1, -0x7FF4
    ctx->r3 = ADD32(ctx->r3, -0X7FF4);
    // 0x800B0F70: addu        $s0, $v0, $v1
    ctx->r16 = ADD32(ctx->r2, ctx->r3);
    // 0x800B0F74: swc1        $f0, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f0.u32l;
    // 0x800B0F78: lwc1        $f0, 0x8($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X8);
    // 0x800B0F7C: swc1        $f0, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->f0.u32l;
    // 0x800B0F80: lwc1        $f0, 0xC($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0XC);
    // 0x800B0F84: swc1        $f0, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f0.u32l;
    // 0x800B0F88: lhu         $v1, 0xB4($s1)
    ctx->r3 = MEM_HU(ctx->r17, 0XB4);
    // 0x800B0F8C: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
    // 0x800B0F90: lui         $a1, 0x3C4C
    ctx->r5 = S32(0X3C4C << 16);
    // 0x800B0F94: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    // 0x800B0F98: bne         $v1, $v0, L_800B0FA8
    if (ctx->r3 != ctx->r2) {
        // 0x800B0F9C: addiu       $a0, $sp, 0x48
        ctx->r4 = ADD32(ctx->r29, 0X48);
            goto L_800B0FA8;
    }
    // 0x800B0F9C: addiu       $a0, $sp, 0x48
    ctx->r4 = ADD32(ctx->r29, 0X48);
    // 0x800B0FA0: lui         $a1, 0x3CB3
    ctx->r5 = S32(0X3CB3 << 16);
    // 0x800B0FA4: ori         $a1, $a1, 0x3333
    ctx->r5 = ctx->r5 | 0X3333;
L_800B0FA8:
    // 0x800B0FA8: addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    // 0x800B0FAC: jal         0x8001CB64
    // 0x800B0FB0: addu        $a3, $a1, $zero
    ctx->r7 = ADD32(ctx->r5, 0);
    func_8001CB64(rdram, ctx);
        goto after_31;
    // 0x800B0FB0: addu        $a3, $a1, $zero
    ctx->r7 = ADD32(ctx->r5, 0);
    after_31:
    // 0x800B0FB4: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x800B0FB8: lw          $a2, 0x0($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X0);
    // 0x800B0FBC: addiu       $a1, $sp, 0x48
    ctx->r5 = ADD32(ctx->r29, 0X48);
    // 0x800B0FC0: jal         0x800191C4
    // 0x800B0FC4: addiu       $a2, $a2, 0x28
    ctx->r6 = ADD32(ctx->r6, 0X28);
    func_800191C4(rdram, ctx);
        goto after_32;
    // 0x800B0FC4: addiu       $a2, $a2, 0x28
    ctx->r6 = ADD32(ctx->r6, 0X28);
    after_32:
    // 0x800B0FC8: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x800B0FCC: lw          $v1, 0xB8($s1)
    ctx->r3 = MEM_W(ctx->r17, 0XB8);
    // 0x800B0FD0: addiu       $a0, $a0, -0x7FC4
    ctx->r4 = ADD32(ctx->r4, -0X7FC4);
    // 0x800B0FD4: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x800B0FD8: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800B0FDC: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800B0FE0: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800B0FE4: sll         $v0, $v0, 5
    ctx->r2 = S32(ctx->r2 << 5);
    // 0x800B0FE8: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x800B0FEC: lw          $t0, 0xCC($s1)
    ctx->r8 = MEM_W(ctx->r17, 0XCC);
    // 0x800B0FF0: lw          $t1, 0xD0($s1)
    ctx->r9 = MEM_W(ctx->r17, 0XD0);
    // 0x800B0FF4: lw          $t2, 0xD4($s1)
    ctx->r10 = MEM_W(ctx->r17, 0XD4);
    // 0x800B0FF8: sw          $t0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r8;
    // 0x800B0FFC: sw          $t1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r9;
    // 0x800B1000: sw          $t2, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r10;
    // 0x800B1004: lw          $ra, 0x90($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X90);
    // 0x800B1008: lw          $s3, 0x8C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X8C);
    // 0x800B100C: lw          $s2, 0x88($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X88);
    // 0x800B1010: lw          $s1, 0x84($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X84);
    // 0x800B1014: lw          $s0, 0x80($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X80);
    // 0x800B1018: ldc1        $f20, 0x98($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X98);
    // 0x800B101C: jr          $ra
    // 0x800B1020: addiu       $sp, $sp, 0xA0
    ctx->r29 = ADD32(ctx->r29, 0XA0);
    return;
    // 0x800B1020: addiu       $sp, $sp, 0xA0
    ctx->r29 = ADD32(ctx->r29, 0XA0);
;}
RECOMP_FUNC void func_800B1024(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B1024: mtc1        $a1, $f6
    ctx->f6.u32l = ctx->r5;
    // 0x800B1028: addiu       $sp, $sp, -0x90
    ctx->r29 = ADD32(ctx->r29, -0X90);
    // 0x800B102C: sw          $s1, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r17;
    // 0x800B1030: addu        $s1, $a0, $zero
    ctx->r17 = ADD32(ctx->r4, 0);
    // 0x800B1034: sw          $ra, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r31;
    // 0x800B1038: sw          $s2, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r18;
    // 0x800B103C: sw          $s0, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r16;
    // 0x800B1040: sdc1        $f20, 0x88($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X88, ctx->r29);
    // 0x800B1044: lwc1        $f0, 0x184($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X184);
    // 0x800B1048: lw          $v1, 0xB8($s1)
    ctx->r3 = MEM_W(ctx->r17, 0XB8);
    // 0x800B104C: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x800B1050: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x800B1054: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800B1058: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800B105C: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800B1060: sll         $v0, $v0, 5
    ctx->r2 = S32(ctx->r2 << 5);
    // 0x800B1064: lui         $v1, 0x8014
    ctx->r3 = S32(0X8014 << 16);
    // 0x800B1068: sub.s       $f0, $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f6.fl;
    // 0x800B106C: addiu       $a0, $v1, -0x7FF4
    ctx->r4 = ADD32(ctx->r3, -0X7FF4);
    // 0x800B1070: addu        $s2, $v0, $a0
    ctx->r18 = ADD32(ctx->r2, ctx->r4);
    // 0x800B1074: c.le.s      $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f0.fl <= ctx->f20.fl;
    // 0x800B1078: nop

    // 0x800B107C: bc1f        L_800B1144
    if (!c1cs) {
        // 0x800B1080: swc1        $f0, 0x184($s1)
        MEM_W(0X184, ctx->r17) = ctx->f0.u32l;
            goto L_800B1144;
    }
    // 0x800B1080: swc1        $f0, 0x184($s1)
    MEM_W(0X184, ctx->r17) = ctx->f0.u32l;
    // 0x800B1084: lhu         $v0, 0x180($s1)
    ctx->r2 = MEM_HU(ctx->r17, 0X180);
    // 0x800B1088: lw          $v1, 0xB8($s1)
    ctx->r3 = MEM_W(ctx->r17, 0XB8);
    // 0x800B108C: ori         $a1, $v0, 0x100
    ctx->r5 = ctx->r2 | 0X100;
    // 0x800B1090: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x800B1094: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800B1098: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800B109C: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800B10A0: sll         $v0, $v0, 5
    ctx->r2 = S32(ctx->r2 << 5);
    // 0x800B10A4: addu        $v0, $a0, $v0
    ctx->r2 = ADD32(ctx->r4, ctx->r2);
    // 0x800B10A8: sh          $a1, 0x180($s1)
    MEM_H(0X180, ctx->r17) = ctx->r5;
    // 0x800B10AC: lhu         $v0, -0xD0($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0XD0);
    // 0x800B10B0: andi        $v0, $v0, 0x20
    ctx->r2 = ctx->r2 & 0X20;
    // 0x800B10B4: bne         $v0, $zero, L_800B13C4
    if (ctx->r2 != 0) {
        // 0x800B10B8: addiu       $a0, $s1, 0x4
        ctx->r4 = ADD32(ctx->r17, 0X4);
            goto L_800B13C4;
    }
    // 0x800B10B8: addiu       $a0, $s1, 0x4
    ctx->r4 = ADD32(ctx->r17, 0X4);
    // 0x800B10BC: andi        $v0, $a1, 0xFFE6
    ctx->r2 = ctx->r5 & 0XFFE6;
    // 0x800B10C0: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800B10C4: lwc1        $f0, 0x566C($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X566C);
    // 0x800B10C8: ori         $v0, $v0, 0x20
    ctx->r2 = ctx->r2 | 0X20;
    // 0x800B10CC: sh          $v0, 0x180($s1)
    MEM_H(0X180, ctx->r17) = ctx->r2;
    // 0x800B10D0: swc1        $f20, 0xC0($s1)
    MEM_W(0XC0, ctx->r17) = ctx->f20.u32l;
    // 0x800B10D4: jal         0x80059F10
    // 0x800B10D8: swc1        $f0, 0x184($s1)
    MEM_W(0X184, ctx->r17) = ctx->f0.u32l;
    func_80059F10(rdram, ctx);
        goto after_0;
    // 0x800B10D8: swc1        $f0, 0x184($s1)
    MEM_W(0X184, ctx->r17) = ctx->f0.u32l;
    after_0:
    // 0x800B10DC: lui         $a2, 0x8014
    ctx->r6 = S32(0X8014 << 16);
    // 0x800B10E0: addiu       $a2, $a2, -0x7FA8
    ctx->r6 = ADD32(ctx->r6, -0X7FA8);
    // 0x800B10E4: lwc1        $f12, 0x4($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X4);
    // 0x800B10E8: lwc1        $f14, 0xC($s1)
    ctx->f14.u32l = MEM_W(ctx->r17, 0XC);
    // 0x800B10EC: jal         0x80067D90
    // 0x800B10F0: addiu       $a3, $sp, 0x20
    ctx->r7 = ADD32(ctx->r29, 0X20);
    func_80067D90(rdram, ctx);
        goto after_1;
    // 0x800B10F0: addiu       $a3, $sp, 0x20
    ctx->r7 = ADD32(ctx->r29, 0X20);
    after_1:
    // 0x800B10F4: lwc1        $f2, 0x24($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X24);
    // 0x800B10F8: lwc1        $f0, 0x8($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X8);
    // 0x800B10FC: c.le.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl <= ctx->f0.fl;
    // 0x800B1100: nop

    // 0x800B1104: bc1f        L_800B111C
    if (!c1cs) {
        // 0x800B1108: lui         $v0, 0x8011
        ctx->r2 = S32(0X8011 << 16);
            goto L_800B111C;
    }
    // 0x800B1108: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800B110C: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800B1110: lwc1        $f0, 0x5670($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X5670);
    // 0x800B1114: sub.s       $f0, $f2, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f2.fl - ctx->f0.fl;
    // 0x800B1118: swc1        $f0, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->f0.u32l;
L_800B111C:
    // 0x800B111C: lw          $v0, -0x35E0($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X35E0);
    // 0x800B1120: bne         $v0, $zero, L_800B13C4
    if (ctx->r2 != 0) {
        // 0x800B1124: lui         $a1, 0x8011
        ctx->r5 = S32(0X8011 << 16);
            goto L_800B13C4;
    }
    // 0x800B1124: lui         $a1, 0x8011
    ctx->r5 = S32(0X8011 << 16);
    // 0x800B1128: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
    // 0x800B112C: lw          $v0, -0x3620($a1)
    ctx->r2 = MEM_W(ctx->r5, -0X3620);
    // 0x800B1130: lbu         $a0, 0xBB($s1)
    ctx->r4 = MEM_BU(ctx->r17, 0XBB);
    // 0x800B1134: ori         $v0, $v0, 0x2
    ctx->r2 = ctx->r2 | 0X2;
    // 0x800B1138: sb          $a0, -0x35E8($v1)
    MEM_B(-0X35E8, ctx->r3) = ctx->r4;
    // 0x800B113C: j           L_800B13C4
    // 0x800B1140: sw          $v0, -0x3620($a1)
    MEM_W(-0X3620, ctx->r5) = ctx->r2;
        goto L_800B13C4;
    // 0x800B1140: sw          $v0, -0x3620($a1)
    MEM_W(-0X3620, ctx->r5) = ctx->r2;
L_800B1144:
    // 0x800B1144: lwc1        $f2, 0x28($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0X28);
    // 0x800B1148: c.lt.s      $f20, $f2
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f20.fl < ctx->f2.fl;
    // 0x800B114C: nop

    // 0x800B1150: bc1t        L_800B116C
    if (c1cs) {
        // 0x800B1154: nop
    
            goto L_800B116C;
    }
    // 0x800B1154: nop

    // 0x800B1158: lwc1        $f0, 0x30($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X30);
    // 0x800B115C: c.lt.s      $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f20.fl < ctx->f0.fl;
    // 0x800B1160: nop

    // 0x800B1164: bc1f        L_800B11D4
    if (!c1cs) {
        // 0x800B1168: lui         $a2, 0x8014
        ctx->r6 = S32(0X8014 << 16);
            goto L_800B11D4;
    }
    // 0x800B1168: lui         $a2, 0x8014
    ctx->r6 = S32(0X8014 << 16);
L_800B116C:
    // 0x800B116C: mul.s       $f0, $f2, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = MUL_S(ctx->f2.fl, ctx->f6.fl);
    // 0x800B1170: lwc1        $f4, 0x30($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X30);
    // 0x800B1174: mul.s       $f4, $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x800B1178: addiu       $s0, $s1, 0x28
    ctx->r16 = ADD32(ctx->r17, 0X28);
    // 0x800B117C: lwc1        $f2, 0x4($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0X4);
    // 0x800B1180: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x800B1184: add.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x800B1188: lwc1        $f0, 0xC($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0XC);
    // 0x800B118C: lui         $a1, 0x3F40
    ctx->r5 = S32(0X3F40 << 16);
    // 0x800B1190: add.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f4.fl;
    // 0x800B1194: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    // 0x800B1198: swc1        $f2, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->f2.u32l;
    // 0x800B119C: jal         0x800AA3B4
    // 0x800B11A0: swc1        $f0, 0xC($s1)
    MEM_W(0XC, ctx->r17) = ctx->f0.u32l;
    func_800AA3B4(rdram, ctx);
        goto after_2;
    // 0x800B11A0: swc1        $f0, 0xC($s1)
    MEM_W(0XC, ctx->r17) = ctx->f0.u32l;
    after_2:
    // 0x800B11A4: jal         0x8001CF2C
    // 0x800B11A8: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_8001CF2C(rdram, ctx);
        goto after_3;
    // 0x800B11A8: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_3:
    // 0x800B11AC: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800B11B0: lwc1        $f2, 0x5674($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X5674);
    // 0x800B11B4: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x800B11B8: nop

    // 0x800B11BC: bc1f        L_800B11D4
    if (!c1cs) {
        // 0x800B11C0: lui         $a2, 0x8014
        ctx->r6 = S32(0X8014 << 16);
            goto L_800B11D4;
    }
    // 0x800B11C0: lui         $a2, 0x8014
    ctx->r6 = S32(0X8014 << 16);
    // 0x800B11C4: swc1        $f20, 0x28($s1)
    MEM_W(0X28, ctx->r17) = ctx->f20.u32l;
    // 0x800B11C8: swc1        $f20, 0x2C($s1)
    MEM_W(0X2C, ctx->r17) = ctx->f20.u32l;
    // 0x800B11CC: swc1        $f20, 0x30($s1)
    MEM_W(0X30, ctx->r17) = ctx->f20.u32l;
    // 0x800B11D0: swc1        $f20, 0xE8($s1)
    MEM_W(0XE8, ctx->r17) = ctx->f20.u32l;
L_800B11D4:
    // 0x800B11D4: addiu       $a2, $a2, -0x7FA8
    ctx->r6 = ADD32(ctx->r6, -0X7FA8);
    // 0x800B11D8: lwc1        $f12, 0x4($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X4);
    // 0x800B11DC: lwc1        $f14, 0xC($s1)
    ctx->f14.u32l = MEM_W(ctx->r17, 0XC);
    // 0x800B11E0: jal         0x80067D90
    // 0x800B11E4: addiu       $a3, $sp, 0x20
    ctx->r7 = ADD32(ctx->r29, 0X20);
    func_80067D90(rdram, ctx);
        goto after_4;
    // 0x800B11E4: addiu       $a3, $sp, 0x20
    ctx->r7 = ADD32(ctx->r29, 0X20);
    after_4:
    // 0x800B11E8: lwc1        $f2, 0x24($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X24);
    // 0x800B11EC: lwc1        $f0, 0x8($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X8);
    // 0x800B11F0: c.le.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl <= ctx->f0.fl;
    // 0x800B11F4: nop

    // 0x800B11F8: bc1f        L_800B1210
    if (!c1cs) {
        // 0x800B11FC: addiu       $s0, $s1, 0x10
        ctx->r16 = ADD32(ctx->r17, 0X10);
            goto L_800B1210;
    }
    // 0x800B11FC: addiu       $s0, $s1, 0x10
    ctx->r16 = ADD32(ctx->r17, 0X10);
    // 0x800B1200: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800B1204: lwc1        $f0, 0x5678($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X5678);
    // 0x800B1208: sub.s       $f0, $f2, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f2.fl - ctx->f0.fl;
    // 0x800B120C: swc1        $f0, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->f0.u32l;
L_800B1210:
    // 0x800B1210: jal         0x800AA350
    // 0x800B1214: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_800AA350(rdram, ctx);
        goto after_5;
    // 0x800B1214: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_5:
    // 0x800B1218: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    // 0x800B121C: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x800B1220: jal         0x8001D144
    // 0x800B1224: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    func_8001D144(rdram, ctx);
        goto after_6;
    // 0x800B1224: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    after_6:
    // 0x800B1228: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    // 0x800B122C: addiu       $s0, $s1, 0x1C
    ctx->r16 = ADD32(ctx->r17, 0X1C);
    // 0x800B1230: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x800B1234: jal         0x8001D3C4
    // 0x800B1238: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    func_8001D3C4(rdram, ctx);
        goto after_7;
    // 0x800B1238: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    after_7:
    // 0x800B123C: jal         0x800AA350
    // 0x800B1240: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_800AA350(rdram, ctx);
        goto after_8;
    // 0x800B1240: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_8:
    // 0x800B1244: addiu       $s0, $s1, 0x4
    ctx->r16 = ADD32(ctx->r17, 0X4);
    // 0x800B1248: jal         0x80059F10
    // 0x800B124C: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_80059F10(rdram, ctx);
        goto after_9;
    // 0x800B124C: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_9:
    // 0x800B1250: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // 0x800B1254: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x800B1258: jal         0x80059B50
    // 0x800B125C: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    func_80059B50(rdram, ctx);
        goto after_10;
    // 0x800B125C: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    after_10:
    // 0x800B1260: lw          $v1, 0xB8($s1)
    ctx->r3 = MEM_W(ctx->r17, 0XB8);
    // 0x800B1264: lwc1        $f0, 0x4($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X4);
    // 0x800B1268: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x800B126C: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800B1270: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800B1274: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800B1278: sll         $v0, $v0, 5
    ctx->r2 = S32(ctx->r2 << 5);
    // 0x800B127C: lui         $v1, 0x8014
    ctx->r3 = S32(0X8014 << 16);
    // 0x800B1280: addiu       $v1, $v1, -0x7FF4
    ctx->r3 = ADD32(ctx->r3, -0X7FF4);
    // 0x800B1284: addu        $s0, $v0, $v1
    ctx->r16 = ADD32(ctx->r2, ctx->r3);
    // 0x800B1288: swc1        $f0, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f0.u32l;
    // 0x800B128C: lwc1        $f0, 0x8($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X8);
    // 0x800B1290: swc1        $f0, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->f0.u32l;
    // 0x800B1294: lwc1        $f0, 0xC($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0XC);
    // 0x800B1298: swc1        $f0, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f0.u32l;
    // 0x800B129C: lhu         $v1, 0xB4($s1)
    ctx->r3 = MEM_HU(ctx->r17, 0XB4);
    // 0x800B12A0: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
    // 0x800B12A4: lui         $a1, 0x3C4C
    ctx->r5 = S32(0X3C4C << 16);
    // 0x800B12A8: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    // 0x800B12AC: bne         $v1, $v0, L_800B12BC
    if (ctx->r3 != ctx->r2) {
        // 0x800B12B0: addiu       $a0, $sp, 0x48
        ctx->r4 = ADD32(ctx->r29, 0X48);
            goto L_800B12BC;
    }
    // 0x800B12B0: addiu       $a0, $sp, 0x48
    ctx->r4 = ADD32(ctx->r29, 0X48);
    // 0x800B12B4: lui         $a1, 0x3CB3
    ctx->r5 = S32(0X3CB3 << 16);
    // 0x800B12B8: ori         $a1, $a1, 0x3333
    ctx->r5 = ctx->r5 | 0X3333;
L_800B12BC:
    // 0x800B12BC: addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    // 0x800B12C0: jal         0x8001CB64
    // 0x800B12C4: addu        $a3, $a1, $zero
    ctx->r7 = ADD32(ctx->r5, 0);
    func_8001CB64(rdram, ctx);
        goto after_11;
    // 0x800B12C4: addu        $a3, $a1, $zero
    ctx->r7 = ADD32(ctx->r5, 0);
    after_11:
    // 0x800B12C8: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x800B12CC: lw          $a2, 0x0($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X0);
    // 0x800B12D0: addiu       $a1, $sp, 0x48
    ctx->r5 = ADD32(ctx->r29, 0X48);
    // 0x800B12D4: jal         0x800191C4
    // 0x800B12D8: addiu       $a2, $a2, 0x28
    ctx->r6 = ADD32(ctx->r6, 0X28);
    func_800191C4(rdram, ctx);
        goto after_12;
    // 0x800B12D8: addiu       $a2, $a2, 0x28
    ctx->r6 = ADD32(ctx->r6, 0X28);
    after_12:
    // 0x800B12DC: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x800B12E0: lw          $v1, 0xB8($s1)
    ctx->r3 = MEM_W(ctx->r17, 0XB8);
    // 0x800B12E4: addiu       $a0, $a0, -0x7FC4
    ctx->r4 = ADD32(ctx->r4, -0X7FC4);
    // 0x800B12E8: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x800B12EC: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800B12F0: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800B12F4: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800B12F8: sll         $v0, $v0, 5
    ctx->r2 = S32(ctx->r2 << 5);
    // 0x800B12FC: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x800B1300: lw          $t0, 0xCC($s1)
    ctx->r8 = MEM_W(ctx->r17, 0XCC);
    // 0x800B1304: lw          $t1, 0xD0($s1)
    ctx->r9 = MEM_W(ctx->r17, 0XD0);
    // 0x800B1308: lw          $t2, 0xD4($s1)
    ctx->r10 = MEM_W(ctx->r17, 0XD4);
    // 0x800B130C: sw          $t0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r8;
    // 0x800B1310: sw          $t1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r9;
    // 0x800B1314: sw          $t2, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r10;
    // 0x800B1318: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x800B131C: lw          $v1, 0xB8($s1)
    ctx->r3 = MEM_W(ctx->r17, 0XB8);
    // 0x800B1320: addiu       $a1, $v0, -0x72E8
    ctx->r5 = ADD32(ctx->r2, -0X72E8);
    // 0x800B1324: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x800B1328: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800B132C: sll         $v0, $v0, 4
    ctx->r2 = S32(ctx->r2 << 4);
    // 0x800B1330: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800B1334: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800B1338: addu        $v0, $v0, $a1
    ctx->r2 = ADD32(ctx->r2, ctx->r5);
    // 0x800B133C: lw          $a0, 0x4($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X4);
    // 0x800B1340: lhu         $v1, 0x4($a0)
    ctx->r3 = MEM_HU(ctx->r4, 0X4);
    // 0x800B1344: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // 0x800B1348: bne         $v1, $v0, L_800B13C4
    if (ctx->r3 != ctx->r2) {
        // 0x800B134C: nop
    
            goto L_800B13C4;
    }
    // 0x800B134C: nop

    // 0x800B1350: lwc1        $f2, 0xD8($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0XD8);
    // 0x800B1354: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800B1358: c.lt.s      $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f2.fl < ctx->f4.fl;
    // 0x800B135C: nop

    // 0x800B1360: bc1f        L_800B1380
    if (!c1cs) {
        // 0x800B1364: nop
    
            goto L_800B1380;
    }
    // 0x800B1364: nop

    // 0x800B1368: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800B136C: lwc1        $f0, 0x567C($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X567C);
    // 0x800B1370: add.s       $f0, $f2, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x800B1374: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x800B1378: j           L_800B1394
    // 0x800B137C: swc1        $f0, 0xD8($a0)
    MEM_W(0XD8, ctx->r4) = ctx->f0.u32l;
        goto L_800B1394;
    // 0x800B137C: swc1        $f0, 0xD8($a0)
    MEM_W(0XD8, ctx->r4) = ctx->f0.u32l;
L_800B1380:
    // 0x800B1380: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800B1384: lwc1        $f0, 0x5680($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X5680);
    // 0x800B1388: sub.s       $f0, $f2, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f2.fl - ctx->f0.fl;
    // 0x800B138C: swc1        $f0, 0xD8($a0)
    MEM_W(0XD8, ctx->r4) = ctx->f0.u32l;
    // 0x800B1390: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
L_800B1394:
    // 0x800B1394: nop

    // 0x800B1398: bc1f        L_800B13C4
    if (!c1cs) {
        // 0x800B139C: nop
    
            goto L_800B13C4;
    }
    // 0x800B139C: nop

    // 0x800B13A0: lw          $v0, 0xB8($s1)
    ctx->r2 = MEM_W(ctx->r17, 0XB8);
    // 0x800B13A4: sll         $v1, $v0, 2
    ctx->r3 = S32(ctx->r2 << 2);
    // 0x800B13A8: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x800B13AC: sll         $v1, $v1, 4
    ctx->r3 = S32(ctx->r3 << 4);
    // 0x800B13B0: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x800B13B4: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x800B13B8: addu        $v1, $v1, $a1
    ctx->r3 = ADD32(ctx->r3, ctx->r5);
    // 0x800B13BC: lw          $v0, 0x4($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X4);
    // 0x800B13C0: swc1        $f4, 0xD8($v0)
    MEM_W(0XD8, ctx->r2) = ctx->f4.u32l;
L_800B13C4:
    // 0x800B13C4: lw          $ra, 0x84($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X84);
    // 0x800B13C8: lw          $s2, 0x80($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X80);
    // 0x800B13CC: lw          $s1, 0x7C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X7C);
    // 0x800B13D0: lw          $s0, 0x78($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X78);
    // 0x800B13D4: ldc1        $f20, 0x88($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X88);
    // 0x800B13D8: jr          $ra
    // 0x800B13DC: addiu       $sp, $sp, 0x90
    ctx->r29 = ADD32(ctx->r29, 0X90);
    return;
    // 0x800B13DC: addiu       $sp, $sp, 0x90
    ctx->r29 = ADD32(ctx->r29, 0X90);
;}
RECOMP_FUNC void func_800B13E0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B13E0: mtc1        $a1, $f6
    ctx->f6.u32l = ctx->r5;
    // 0x800B13E4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800B13E8: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x800B13EC: addu        $s1, $a0, $zero
    ctx->r17 = ADD32(ctx->r4, 0);
    // 0x800B13F0: sw          $ra, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r31;
    // 0x800B13F4: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x800B13F8: lwc1        $f2, 0xC8($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0XC8);
    // 0x800B13FC: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800B1400: lwc1        $f4, 0xC0($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0XC0);
    // 0x800B1404: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x800B1408: nop

    // 0x800B140C: bc1f        L_800B143C
    if (!c1cs) {
        // 0x800B1410: addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
            goto L_800B143C;
    }
    // 0x800B1410: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // 0x800B1414: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800B1418: lwc1        $f0, 0x5684($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X5684);
    // 0x800B141C: c.eq.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl == ctx->f0.fl;
    // 0x800B1420: nop

    // 0x800B1424: bc1f        L_800B143C
    if (!c1cs) {
        // 0x800B1428: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_800B143C;
    }
    // 0x800B1428: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800B142C: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800B1430: lwc1        $f0, 0x5688($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X5688);
    // 0x800B1434: sub.s       $f0, $f2, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f2.fl - ctx->f0.fl;
    // 0x800B1438: swc1        $f0, 0xC8($s1)
    MEM_W(0XC8, ctx->r17) = ctx->f0.u32l;
L_800B143C:
    // 0x800B143C: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x800B1440: bne         $v0, $zero, L_800B1450
    if (ctx->r2 != 0) {
        // 0x800B1444: nop
    
            goto L_800B1450;
    }
    // 0x800B1444: nop

    // 0x800B1448: j           L_800B1458
    // 0x800B144C: sub.s       $f2, $f4, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = ctx->f4.fl - ctx->f6.fl;
        goto L_800B1458;
    // 0x800B144C: sub.s       $f2, $f4, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = ctx->f4.fl - ctx->f6.fl;
L_800B1450:
    // 0x800B1450: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800B1454: sub.s       $f2, $f4, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f4.fl - ctx->f0.fl;
L_800B1458:
    // 0x800B1458: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800B145C: c.le.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl <= ctx->f0.fl;
    // 0x800B1460: nop

    // 0x800B1464: bc1f        L_800B1484
    if (!c1cs) {
        // 0x800B1468: swc1        $f2, 0xC0($s1)
        MEM_W(0XC0, ctx->r17) = ctx->f2.u32l;
            goto L_800B1484;
    }
    // 0x800B1468: swc1        $f2, 0xC0($s1)
    MEM_W(0XC0, ctx->r17) = ctx->f2.u32l;
    // 0x800B146C: jal         0x800B0850
    // 0x800B1470: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    func_800B0850(rdram, ctx);
        goto after_0;
    // 0x800B1470: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    after_0:
    // 0x800B1474: jal         0x801006A8
    // 0x800B1478: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    func_801006A8(rdram, ctx);
        goto after_1;
    // 0x800B1478: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    after_1:
    // 0x800B147C: j           L_800B1BD4
    // 0x800B1480: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_800B1BD4;
    // 0x800B1480: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800B1484:
    // 0x800B1484: lhu         $v1, 0xB4($s1)
    ctx->r3 = MEM_HU(ctx->r17, 0XB4);
    // 0x800B1488: sltiu       $v0, $v1, 0x9
    ctx->r2 = ctx->r3 < 0X9 ? 1 : 0;
    // 0x800B148C: beq         $v0, $zero, L_800B1BC8
    if (ctx->r2 == 0) {
        // 0x800B1490: lui         $v0, 0x800A
        ctx->r2 = S32(0X800A << 16);
            goto L_800B1BC8;
    }
    // 0x800B1490: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x800B1494: addiu       $v0, $v0, 0x5690
    ctx->r2 = ADD32(ctx->r2, 0X5690);
    // 0x800B1498: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x800B149C: addu        $v1, $v1, $v0
    gpr jr_addend_800B14A4 = ctx->r3;
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x800B14A0: lw          $v0, 0x0($v1)
    ctx->r2 = ADD32(ctx->r3, 0X0);
    // 0x800B14A4: jr          $v0
    // 0x800B14A8: nop

    switch (jr_addend_800B14A4 >> 2) {
        case 0: goto L_800B14AC; break;
        case 1: goto L_800B1660; break;
        case 2: goto L_800B1A28; break;
        case 3: goto L_800B1BC8; break;
        case 4: goto L_800B1BC8; break;
        case 5: goto L_800B1AD8; break;
        case 6: goto L_800B1BC8; break;
        case 7: goto L_800B1BC8; break;
        case 8: goto L_800B14AC; break;
        default: switch_error(__func__, 0x800B14A4, 0x800A5690);
    }
    // 0x800B14A8: nop

L_800B14AC:
    // 0x800B14AC: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800B14B0: lbu         $v0, -0x6948($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X6948);
    // 0x800B14B4: beq         $v0, $zero, L_800B1BC8
    if (ctx->r2 == 0) {
        // 0x800B14B8: nop
    
            goto L_800B1BC8;
    }
    // 0x800B14B8: nop

    // 0x800B14BC: lwc1        $f0, 0xC0($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0XC0);
    // 0x800B14C0: lwc1        $f2, 0xC4($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0XC4);
    // 0x800B14C4: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800B14C8: lwc1        $f4, 0x56B4($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X56B4);
    // 0x800B14CC: div.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f2.fl);
    // 0x800B14D0: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x800B14D4: nop

    // 0x800B14D8: bc1f        L_800B1BC8
    if (!c1cs) {
        // 0x800B14DC: lui         $v0, 0x8013
        ctx->r2 = S32(0X8013 << 16);
            goto L_800B1BC8;
    }
    // 0x800B14DC: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800B14E0: lbu         $v1, 0xB40($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0XB40);
    // 0x800B14E4: addiu       $v0, $zero, 0xF
    ctx->r2 = ADD32(0, 0XF);
    // 0x800B14E8: beq         $v1, $v0, L_800B14F4
    if (ctx->r3 == ctx->r2) {
        // 0x800B14EC: addiu       $a0, $zero, 0x28C
        ctx->r4 = ADD32(0, 0X28C);
            goto L_800B14F4;
    }
    // 0x800B14EC: addiu       $a0, $zero, 0x28C
    ctx->r4 = ADD32(0, 0X28C);
    // 0x800B14F0: addiu       $a0, $zero, 0x272
    ctx->r4 = ADD32(0, 0X272);
L_800B14F4:
    // 0x800B14F4: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x800B14F8: addiu       $v0, $zero, 0x28C
    ctx->r2 = ADD32(0, 0X28C);
    // 0x800B14FC: beq         $s0, $v0, L_800B15B0
    if (ctx->r16 == ctx->r2) {
        // 0x800B1500: addu        $v1, $zero, $zero
        ctx->r3 = ADD32(0, 0);
            goto L_800B15B0;
    }
    // 0x800B1500: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
    // 0x800B1504: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800B1508: addiu       $a1, $v0, -0x48C0
    ctx->r5 = ADD32(ctx->r2, -0X48C0);
    // 0x800B150C: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800B1510: addiu       $a0, $v0, -0x4880
    ctx->r4 = ADD32(ctx->r2, -0X4880);
    // 0x800B1514: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x800B1518: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
L_800B151C:
    // 0x800B151C: addu        $v0, $v0, $a1
    ctx->r2 = ADD32(ctx->r2, ctx->r5);
    // 0x800B1520: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x800B1524: bnel        $v0, $s0, L_800B1544
    if (ctx->r2 != ctx->r16) {
        // 0x800B1528: addiu       $v1, $v1, 0x1
        ctx->r3 = ADD32(ctx->r3, 0X1);
            goto L_800B1544;
    }
    goto skip_0;
    // 0x800B1528: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    skip_0:
    // 0x800B152C: addu        $v1, $v1, $a0
    ctx->r3 = ADD32(ctx->r3, ctx->r4);
    // 0x800B1530: lbu         $v0, 0x0($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X0);
    // 0x800B1534: bne         $v0, $zero, L_800B15B4
    if (ctx->r2 != 0) {
        // 0x800B1538: lui         $v0, 0x8013
        ctx->r2 = S32(0X8013 << 16);
            goto L_800B15B4;
    }
    // 0x800B1538: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800B153C: j           L_800B1554
    // 0x800B1540: sb          $a2, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r6;
        goto L_800B1554;
    // 0x800B1540: sb          $a2, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r6;
L_800B1544:
    // 0x800B1544: slti        $v0, $v1, 0xE
    ctx->r2 = SIGNED(ctx->r3) < 0XE ? 1 : 0;
    // 0x800B1548: bne         $v0, $zero, L_800B151C
    if (ctx->r2 != 0) {
        // 0x800B154C: sll         $v0, $v1, 2
        ctx->r2 = S32(ctx->r3 << 2);
            goto L_800B151C;
    }
    // 0x800B154C: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x800B1550: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
L_800B1554:
    // 0x800B1554: lbu         $v1, 0xB40($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0XB40);
    // 0x800B1558: addiu       $v0, $zero, 0xF
    ctx->r2 = ADD32(0, 0XF);
    // 0x800B155C: beq         $v1, $v0, L_800B1574
    if (ctx->r3 == ctx->r2) {
        // 0x800B1560: addiu       $v0, $zero, 0x104
        ctx->r2 = ADD32(0, 0X104);
            goto L_800B1574;
    }
    // 0x800B1560: addiu       $v0, $zero, 0x104
    ctx->r2 = ADD32(0, 0X104);
    // 0x800B1564: beq         $s0, $v0, L_800B1580
    if (ctx->r16 == ctx->r2) {
        // 0x800B1568: addu        $a0, $s0, $zero
        ctx->r4 = ADD32(ctx->r16, 0);
            goto L_800B1580;
    }
    // 0x800B1568: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x800B156C: j           L_800B158C
    // 0x800B1570: addiu       $a1, $zero, 0x73
    ctx->r5 = ADD32(0, 0X73);
        goto L_800B158C;
    // 0x800B1570: addiu       $a1, $zero, 0x73
    ctx->r5 = ADD32(0, 0X73);
L_800B1574:
    // 0x800B1574: addiu       $v0, $zero, 0x28C
    ctx->r2 = ADD32(0, 0X28C);
    // 0x800B1578: bne         $s0, $v0, L_800B1588
    if (ctx->r16 != ctx->r2) {
        // 0x800B157C: addu        $a0, $s0, $zero
        ctx->r4 = ADD32(ctx->r16, 0);
            goto L_800B1588;
    }
    // 0x800B157C: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
L_800B1580:
    // 0x800B1580: j           L_800B158C
    // 0x800B1584: addiu       $a1, $zero, 0x78
    ctx->r5 = ADD32(0, 0X78);
        goto L_800B158C;
    // 0x800B1584: addiu       $a1, $zero, 0x78
    ctx->r5 = ADD32(0, 0X78);
L_800B1588:
    // 0x800B1588: addiu       $a1, $zero, 0x73
    ctx->r5 = ADD32(0, 0X73);
L_800B158C:
    // 0x800B158C: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // 0x800B1590: jal         0x80066EE4
    // 0x800B1594: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    func_80066EE4(rdram, ctx);
        goto after_2;
    // 0x800B1594: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    after_2:
    // 0x800B1598: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800B159C: lwc1        $f0, 0x56B8($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X56B8);
    // 0x800B15A0: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800B15A4: sw          $s0, -0x694C($v0)
    MEM_W(-0X694C, ctx->r2) = ctx->r16;
    // 0x800B15A8: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800B15AC: swc1        $f0, -0x6950($v0)
    MEM_W(-0X6950, ctx->r2) = ctx->f0.u32l;
L_800B15B0:
    // 0x800B15B0: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
L_800B15B4:
    // 0x800B15B4: lbu         $v1, 0xB40($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0XB40);
    // 0x800B15B8: addiu       $v0, $zero, 0xF
    ctx->r2 = ADD32(0, 0XF);
    // 0x800B15BC: beq         $v1, $v0, L_800B15C8
    if (ctx->r3 == ctx->r2) {
        // 0x800B15C0: addiu       $a0, $zero, 0x28C
        ctx->r4 = ADD32(0, 0X28C);
            goto L_800B15C8;
    }
    // 0x800B15C0: addiu       $a0, $zero, 0x28C
    ctx->r4 = ADD32(0, 0X28C);
    // 0x800B15C4: addiu       $a0, $zero, 0x104
    ctx->r4 = ADD32(0, 0X104);
L_800B15C8:
    // 0x800B15C8: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x800B15CC: addiu       $v0, $zero, 0x28C
    ctx->r2 = ADD32(0, 0X28C);
    // 0x800B15D0: beq         $s0, $v0, L_800B1A1C
    if (ctx->r16 == ctx->r2) {
        // 0x800B15D4: addu        $v1, $zero, $zero
        ctx->r3 = ADD32(0, 0);
            goto L_800B1A1C;
    }
    // 0x800B15D4: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
    // 0x800B15D8: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800B15DC: addiu       $a1, $v0, -0x48C0
    ctx->r5 = ADD32(ctx->r2, -0X48C0);
    // 0x800B15E0: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800B15E4: addiu       $a0, $v0, -0x4880
    ctx->r4 = ADD32(ctx->r2, -0X4880);
    // 0x800B15E8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x800B15EC: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
L_800B15F0:
    // 0x800B15F0: addu        $v0, $v0, $a1
    ctx->r2 = ADD32(ctx->r2, ctx->r5);
    // 0x800B15F4: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x800B15F8: bnel        $v0, $s0, L_800B1618
    if (ctx->r2 != ctx->r16) {
        // 0x800B15FC: addiu       $v1, $v1, 0x1
        ctx->r3 = ADD32(ctx->r3, 0X1);
            goto L_800B1618;
    }
    goto skip_1;
    // 0x800B15FC: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    skip_1:
    // 0x800B1600: addu        $v1, $v1, $a0
    ctx->r3 = ADD32(ctx->r3, ctx->r4);
    // 0x800B1604: lbu         $v0, 0x0($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X0);
    // 0x800B1608: bne         $v0, $zero, L_800B1A20
    if (ctx->r2 != 0) {
        // 0x800B160C: lui         $v0, 0x8011
        ctx->r2 = S32(0X8011 << 16);
            goto L_800B1A20;
    }
    // 0x800B160C: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800B1610: j           L_800B1624
    // 0x800B1614: sb          $a2, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r6;
        goto L_800B1624;
    // 0x800B1614: sb          $a2, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r6;
L_800B1618:
    // 0x800B1618: slti        $v0, $v1, 0xE
    ctx->r2 = SIGNED(ctx->r3) < 0XE ? 1 : 0;
    // 0x800B161C: bne         $v0, $zero, L_800B15F0
    if (ctx->r2 != 0) {
        // 0x800B1620: sll         $v0, $v1, 2
        ctx->r2 = S32(ctx->r3 << 2);
            goto L_800B15F0;
    }
    // 0x800B1620: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
L_800B1624:
    // 0x800B1624: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800B1628: lbu         $v1, 0xB40($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0XB40);
    // 0x800B162C: addiu       $v0, $zero, 0xF
    ctx->r2 = ADD32(0, 0XF);
    // 0x800B1630: beq         $v1, $v0, L_800B1648
    if (ctx->r3 == ctx->r2) {
        // 0x800B1634: addiu       $v0, $zero, 0x104
        ctx->r2 = ADD32(0, 0X104);
            goto L_800B1648;
    }
    // 0x800B1634: addiu       $v0, $zero, 0x104
    ctx->r2 = ADD32(0, 0X104);
    // 0x800B1638: beq         $s0, $v0, L_800B1654
    if (ctx->r16 == ctx->r2) {
        // 0x800B163C: addu        $a0, $s0, $zero
        ctx->r4 = ADD32(ctx->r16, 0);
            goto L_800B1654;
    }
    // 0x800B163C: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x800B1640: j           L_800B19F8
    // 0x800B1644: addiu       $a1, $zero, 0x73
    ctx->r5 = ADD32(0, 0X73);
        goto L_800B19F8;
    // 0x800B1644: addiu       $a1, $zero, 0x73
    ctx->r5 = ADD32(0, 0X73);
L_800B1648:
    // 0x800B1648: addiu       $v0, $zero, 0x28C
    ctx->r2 = ADD32(0, 0X28C);
    // 0x800B164C: bne         $s0, $v0, L_800B19F4
    if (ctx->r16 != ctx->r2) {
        // 0x800B1650: addu        $a0, $s0, $zero
        ctx->r4 = ADD32(ctx->r16, 0);
            goto L_800B19F4;
    }
    // 0x800B1650: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
L_800B1654:
    // 0x800B1654: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x800B1658: j           L_800B19F8
    // 0x800B165C: addiu       $a1, $zero, 0x78
    ctx->r5 = ADD32(0, 0X78);
        goto L_800B19F8;
    // 0x800B165C: addiu       $a1, $zero, 0x78
    ctx->r5 = ADD32(0, 0X78);
L_800B1660:
    // 0x800B1660: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800B1664: lbu         $v1, 0xB40($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0XB40);
    // 0x800B1668: addiu       $v0, $zero, 0xF
    ctx->r2 = ADD32(0, 0XF);
    // 0x800B166C: beq         $v1, $v0, L_800B1678
    if (ctx->r3 == ctx->r2) {
        // 0x800B1670: addiu       $a0, $zero, 0x206
        ctx->r4 = ADD32(0, 0X206);
            goto L_800B1678;
    }
    // 0x800B1670: addiu       $a0, $zero, 0x206
    ctx->r4 = ADD32(0, 0X206);
    // 0x800B1674: addiu       $a0, $zero, 0x122
    ctx->r4 = ADD32(0, 0X122);
L_800B1678:
    // 0x800B1678: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x800B167C: addiu       $v0, $zero, 0x28C
    ctx->r2 = ADD32(0, 0X28C);
    // 0x800B1680: bne         $s0, $v0, L_800B1690
    if (ctx->r16 != ctx->r2) {
        // 0x800B1684: addu        $v1, $zero, $zero
        ctx->r3 = ADD32(0, 0);
            goto L_800B1690;
    }
    // 0x800B1684: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
    // 0x800B1688: j           L_800B1744
    // 0x800B168C: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
        goto L_800B1744;
    // 0x800B168C: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
L_800B1690:
    // 0x800B1690: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800B1694: addiu       $a1, $v0, -0x48C0
    ctx->r5 = ADD32(ctx->r2, -0X48C0);
    // 0x800B1698: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800B169C: addiu       $a0, $v0, -0x4880
    ctx->r4 = ADD32(ctx->r2, -0X4880);
    // 0x800B16A0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x800B16A4: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
L_800B16A8:
    // 0x800B16A8: addu        $v0, $v0, $a1
    ctx->r2 = ADD32(ctx->r2, ctx->r5);
    // 0x800B16AC: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x800B16B0: bnel        $v0, $s0, L_800B16D0
    if (ctx->r2 != ctx->r16) {
        // 0x800B16B4: addiu       $v1, $v1, 0x1
        ctx->r3 = ADD32(ctx->r3, 0X1);
            goto L_800B16D0;
    }
    goto skip_2;
    // 0x800B16B4: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    skip_2:
    // 0x800B16B8: addu        $v1, $v1, $a0
    ctx->r3 = ADD32(ctx->r3, ctx->r4);
    // 0x800B16BC: lbu         $v0, 0x0($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X0);
    // 0x800B16C0: bnel        $v0, $zero, L_800B1744
    if (ctx->r2 != 0) {
        // 0x800B16C4: addu        $v1, $zero, $zero
        ctx->r3 = ADD32(0, 0);
            goto L_800B1744;
    }
    goto skip_3;
    // 0x800B16C4: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
    skip_3:
    // 0x800B16C8: j           L_800B16DC
    // 0x800B16CC: sb          $a2, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r6;
        goto L_800B16DC;
    // 0x800B16CC: sb          $a2, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r6;
L_800B16D0:
    // 0x800B16D0: slti        $v0, $v1, 0xE
    ctx->r2 = SIGNED(ctx->r3) < 0XE ? 1 : 0;
    // 0x800B16D4: bne         $v0, $zero, L_800B16A8
    if (ctx->r2 != 0) {
        // 0x800B16D8: sll         $v0, $v1, 2
        ctx->r2 = S32(ctx->r3 << 2);
            goto L_800B16A8;
    }
    // 0x800B16D8: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
L_800B16DC:
    // 0x800B16DC: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800B16E0: lbu         $v1, 0xB40($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0XB40);
    // 0x800B16E4: addiu       $v0, $zero, 0xF
    ctx->r2 = ADD32(0, 0XF);
    // 0x800B16E8: beq         $v1, $v0, L_800B1700
    if (ctx->r3 == ctx->r2) {
        // 0x800B16EC: addiu       $v0, $zero, 0x104
        ctx->r2 = ADD32(0, 0X104);
            goto L_800B1700;
    }
    // 0x800B16EC: addiu       $v0, $zero, 0x104
    ctx->r2 = ADD32(0, 0X104);
    // 0x800B16F0: beq         $s0, $v0, L_800B170C
    if (ctx->r16 == ctx->r2) {
        // 0x800B16F4: addu        $a0, $s0, $zero
        ctx->r4 = ADD32(ctx->r16, 0);
            goto L_800B170C;
    }
    // 0x800B16F4: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x800B16F8: j           L_800B171C
    // 0x800B16FC: addiu       $a1, $zero, 0x73
    ctx->r5 = ADD32(0, 0X73);
        goto L_800B171C;
    // 0x800B16FC: addiu       $a1, $zero, 0x73
    ctx->r5 = ADD32(0, 0X73);
L_800B1700:
    // 0x800B1700: addiu       $v0, $zero, 0x28C
    ctx->r2 = ADD32(0, 0X28C);
    // 0x800B1704: bne         $s0, $v0, L_800B1718
    if (ctx->r16 != ctx->r2) {
        // 0x800B1708: addu        $a0, $s0, $zero
        ctx->r4 = ADD32(ctx->r16, 0);
            goto L_800B1718;
    }
    // 0x800B1708: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
L_800B170C:
    // 0x800B170C: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x800B1710: j           L_800B171C
    // 0x800B1714: addiu       $a1, $zero, 0x78
    ctx->r5 = ADD32(0, 0X78);
        goto L_800B171C;
    // 0x800B1714: addiu       $a1, $zero, 0x78
    ctx->r5 = ADD32(0, 0X78);
L_800B1718:
    // 0x800B1718: addiu       $a1, $zero, 0x73
    ctx->r5 = ADD32(0, 0X73);
L_800B171C:
    // 0x800B171C: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // 0x800B1720: jal         0x80066EE4
    // 0x800B1724: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    func_80066EE4(rdram, ctx);
        goto after_3;
    // 0x800B1724: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_3:
    // 0x800B1728: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x800B172C: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800B1730: lwc1        $f0, 0x56BC($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X56BC);
    // 0x800B1734: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800B1738: sw          $s0, -0x694C($v0)
    MEM_W(-0X694C, ctx->r2) = ctx->r16;
    // 0x800B173C: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800B1740: swc1        $f0, -0x6950($v0)
    MEM_W(-0X6950, ctx->r2) = ctx->f0.u32l;
L_800B1744:
    // 0x800B1744: andi        $v0, $v1, 0xFF
    ctx->r2 = ctx->r3 & 0XFF;
    // 0x800B1748: bne         $v0, $zero, L_800B1BD4
    if (ctx->r2 != 0) {
        // 0x800B174C: addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
            goto L_800B1BD4;
    }
    // 0x800B174C: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // 0x800B1750: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800B1754: lbu         $v1, 0xB40($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0XB40);
    // 0x800B1758: addiu       $v0, $zero, 0xF
    ctx->r2 = ADD32(0, 0XF);
    // 0x800B175C: beq         $v1, $v0, L_800B1768
    if (ctx->r3 == ctx->r2) {
        // 0x800B1760: addiu       $a0, $zero, 0x207
        ctx->r4 = ADD32(0, 0X207);
            goto L_800B1768;
    }
    // 0x800B1760: addiu       $a0, $zero, 0x207
    ctx->r4 = ADD32(0, 0X207);
    // 0x800B1764: addiu       $a0, $zero, 0x123
    ctx->r4 = ADD32(0, 0X123);
L_800B1768:
    // 0x800B1768: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x800B176C: addiu       $v0, $zero, 0x28C
    ctx->r2 = ADD32(0, 0X28C);
    // 0x800B1770: bne         $s0, $v0, L_800B1780
    if (ctx->r16 != ctx->r2) {
        // 0x800B1774: addu        $v1, $zero, $zero
        ctx->r3 = ADD32(0, 0);
            goto L_800B1780;
    }
    // 0x800B1774: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
    // 0x800B1778: j           L_800B1834
    // 0x800B177C: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
        goto L_800B1834;
    // 0x800B177C: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
L_800B1780:
    // 0x800B1780: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800B1784: addiu       $a1, $v0, -0x48C0
    ctx->r5 = ADD32(ctx->r2, -0X48C0);
    // 0x800B1788: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800B178C: addiu       $a0, $v0, -0x4880
    ctx->r4 = ADD32(ctx->r2, -0X4880);
    // 0x800B1790: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x800B1794: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
L_800B1798:
    // 0x800B1798: addu        $v0, $v0, $a1
    ctx->r2 = ADD32(ctx->r2, ctx->r5);
    // 0x800B179C: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x800B17A0: bnel        $v0, $s0, L_800B17C0
    if (ctx->r2 != ctx->r16) {
        // 0x800B17A4: addiu       $v1, $v1, 0x1
        ctx->r3 = ADD32(ctx->r3, 0X1);
            goto L_800B17C0;
    }
    goto skip_4;
    // 0x800B17A4: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    skip_4:
    // 0x800B17A8: addu        $v1, $v1, $a0
    ctx->r3 = ADD32(ctx->r3, ctx->r4);
    // 0x800B17AC: lbu         $v0, 0x0($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X0);
    // 0x800B17B0: bnel        $v0, $zero, L_800B1834
    if (ctx->r2 != 0) {
        // 0x800B17B4: addu        $v1, $zero, $zero
        ctx->r3 = ADD32(0, 0);
            goto L_800B1834;
    }
    goto skip_5;
    // 0x800B17B4: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
    skip_5:
    // 0x800B17B8: j           L_800B17CC
    // 0x800B17BC: sb          $a2, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r6;
        goto L_800B17CC;
    // 0x800B17BC: sb          $a2, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r6;
L_800B17C0:
    // 0x800B17C0: slti        $v0, $v1, 0xE
    ctx->r2 = SIGNED(ctx->r3) < 0XE ? 1 : 0;
    // 0x800B17C4: bne         $v0, $zero, L_800B1798
    if (ctx->r2 != 0) {
        // 0x800B17C8: sll         $v0, $v1, 2
        ctx->r2 = S32(ctx->r3 << 2);
            goto L_800B1798;
    }
    // 0x800B17C8: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
L_800B17CC:
    // 0x800B17CC: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800B17D0: lbu         $v1, 0xB40($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0XB40);
    // 0x800B17D4: addiu       $v0, $zero, 0xF
    ctx->r2 = ADD32(0, 0XF);
    // 0x800B17D8: beq         $v1, $v0, L_800B17F0
    if (ctx->r3 == ctx->r2) {
        // 0x800B17DC: addiu       $v0, $zero, 0x104
        ctx->r2 = ADD32(0, 0X104);
            goto L_800B17F0;
    }
    // 0x800B17DC: addiu       $v0, $zero, 0x104
    ctx->r2 = ADD32(0, 0X104);
    // 0x800B17E0: beq         $s0, $v0, L_800B17FC
    if (ctx->r16 == ctx->r2) {
        // 0x800B17E4: addu        $a0, $s0, $zero
        ctx->r4 = ADD32(ctx->r16, 0);
            goto L_800B17FC;
    }
    // 0x800B17E4: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x800B17E8: j           L_800B180C
    // 0x800B17EC: addiu       $a1, $zero, 0x73
    ctx->r5 = ADD32(0, 0X73);
        goto L_800B180C;
    // 0x800B17EC: addiu       $a1, $zero, 0x73
    ctx->r5 = ADD32(0, 0X73);
L_800B17F0:
    // 0x800B17F0: addiu       $v0, $zero, 0x28C
    ctx->r2 = ADD32(0, 0X28C);
    // 0x800B17F4: bne         $s0, $v0, L_800B1808
    if (ctx->r16 != ctx->r2) {
        // 0x800B17F8: addu        $a0, $s0, $zero
        ctx->r4 = ADD32(ctx->r16, 0);
            goto L_800B1808;
    }
    // 0x800B17F8: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
L_800B17FC:
    // 0x800B17FC: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x800B1800: j           L_800B180C
    // 0x800B1804: addiu       $a1, $zero, 0x78
    ctx->r5 = ADD32(0, 0X78);
        goto L_800B180C;
    // 0x800B1804: addiu       $a1, $zero, 0x78
    ctx->r5 = ADD32(0, 0X78);
L_800B1808:
    // 0x800B1808: addiu       $a1, $zero, 0x73
    ctx->r5 = ADD32(0, 0X73);
L_800B180C:
    // 0x800B180C: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // 0x800B1810: jal         0x80066EE4
    // 0x800B1814: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    func_80066EE4(rdram, ctx);
        goto after_4;
    // 0x800B1814: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_4:
    // 0x800B1818: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x800B181C: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800B1820: lwc1        $f0, 0x56C0($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X56C0);
    // 0x800B1824: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800B1828: sw          $s0, -0x694C($v0)
    MEM_W(-0X694C, ctx->r2) = ctx->r16;
    // 0x800B182C: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800B1830: swc1        $f0, -0x6950($v0)
    MEM_W(-0X6950, ctx->r2) = ctx->f0.u32l;
L_800B1834:
    // 0x800B1834: andi        $v0, $v1, 0xFF
    ctx->r2 = ctx->r3 & 0XFF;
    // 0x800B1838: bne         $v0, $zero, L_800B1BD4
    if (ctx->r2 != 0) {
        // 0x800B183C: addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
            goto L_800B1BD4;
    }
    // 0x800B183C: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // 0x800B1840: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800B1844: lbu         $v0, -0x6948($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X6948);
    // 0x800B1848: beq         $v0, $zero, L_800B1BC8
    if (ctx->r2 == 0) {
        // 0x800B184C: nop
    
            goto L_800B1BC8;
    }
    // 0x800B184C: nop

    // 0x800B1850: lwc1        $f0, 0xC0($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0XC0);
    // 0x800B1854: lwc1        $f2, 0xC4($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0XC4);
    // 0x800B1858: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800B185C: lwc1        $f4, 0x56C4($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X56C4);
    // 0x800B1860: div.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f2.fl);
    // 0x800B1864: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x800B1868: nop

    // 0x800B186C: bc1f        L_800B1BC8
    if (!c1cs) {
        // 0x800B1870: lui         $v0, 0x8013
        ctx->r2 = S32(0X8013 << 16);
            goto L_800B1BC8;
    }
    // 0x800B1870: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800B1874: lbu         $v1, 0xB40($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0XB40);
    // 0x800B1878: addiu       $v0, $zero, 0xF
    ctx->r2 = ADD32(0, 0XF);
    // 0x800B187C: beq         $v1, $v0, L_800B1888
    if (ctx->r3 == ctx->r2) {
        // 0x800B1880: addiu       $a0, $zero, 0x28C
        ctx->r4 = ADD32(0, 0X28C);
            goto L_800B1888;
    }
    // 0x800B1880: addiu       $a0, $zero, 0x28C
    ctx->r4 = ADD32(0, 0X28C);
    // 0x800B1884: addiu       $a0, $zero, 0x272
    ctx->r4 = ADD32(0, 0X272);
L_800B1888:
    // 0x800B1888: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x800B188C: addiu       $v0, $zero, 0x28C
    ctx->r2 = ADD32(0, 0X28C);
    // 0x800B1890: beq         $s0, $v0, L_800B1944
    if (ctx->r16 == ctx->r2) {
        // 0x800B1894: addu        $v1, $zero, $zero
        ctx->r3 = ADD32(0, 0);
            goto L_800B1944;
    }
    // 0x800B1894: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
    // 0x800B1898: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800B189C: addiu       $a1, $v0, -0x48C0
    ctx->r5 = ADD32(ctx->r2, -0X48C0);
    // 0x800B18A0: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800B18A4: addiu       $a0, $v0, -0x4880
    ctx->r4 = ADD32(ctx->r2, -0X4880);
    // 0x800B18A8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x800B18AC: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
L_800B18B0:
    // 0x800B18B0: addu        $v0, $v0, $a1
    ctx->r2 = ADD32(ctx->r2, ctx->r5);
    // 0x800B18B4: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x800B18B8: bnel        $v0, $s0, L_800B18D8
    if (ctx->r2 != ctx->r16) {
        // 0x800B18BC: addiu       $v1, $v1, 0x1
        ctx->r3 = ADD32(ctx->r3, 0X1);
            goto L_800B18D8;
    }
    goto skip_6;
    // 0x800B18BC: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    skip_6:
    // 0x800B18C0: addu        $v1, $v1, $a0
    ctx->r3 = ADD32(ctx->r3, ctx->r4);
    // 0x800B18C4: lbu         $v0, 0x0($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X0);
    // 0x800B18C8: bne         $v0, $zero, L_800B1948
    if (ctx->r2 != 0) {
        // 0x800B18CC: lui         $v0, 0x8013
        ctx->r2 = S32(0X8013 << 16);
            goto L_800B1948;
    }
    // 0x800B18CC: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800B18D0: j           L_800B18E8
    // 0x800B18D4: sb          $a2, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r6;
        goto L_800B18E8;
    // 0x800B18D4: sb          $a2, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r6;
L_800B18D8:
    // 0x800B18D8: slti        $v0, $v1, 0xE
    ctx->r2 = SIGNED(ctx->r3) < 0XE ? 1 : 0;
    // 0x800B18DC: bne         $v0, $zero, L_800B18B0
    if (ctx->r2 != 0) {
        // 0x800B18E0: sll         $v0, $v1, 2
        ctx->r2 = S32(ctx->r3 << 2);
            goto L_800B18B0;
    }
    // 0x800B18E0: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x800B18E4: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
L_800B18E8:
    // 0x800B18E8: lbu         $v1, 0xB40($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0XB40);
    // 0x800B18EC: addiu       $v0, $zero, 0xF
    ctx->r2 = ADD32(0, 0XF);
    // 0x800B18F0: beq         $v1, $v0, L_800B1908
    if (ctx->r3 == ctx->r2) {
        // 0x800B18F4: addiu       $v0, $zero, 0x104
        ctx->r2 = ADD32(0, 0X104);
            goto L_800B1908;
    }
    // 0x800B18F4: addiu       $v0, $zero, 0x104
    ctx->r2 = ADD32(0, 0X104);
    // 0x800B18F8: beq         $s0, $v0, L_800B1914
    if (ctx->r16 == ctx->r2) {
        // 0x800B18FC: addu        $a0, $s0, $zero
        ctx->r4 = ADD32(ctx->r16, 0);
            goto L_800B1914;
    }
    // 0x800B18FC: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x800B1900: j           L_800B1920
    // 0x800B1904: addiu       $a1, $zero, 0x73
    ctx->r5 = ADD32(0, 0X73);
        goto L_800B1920;
    // 0x800B1904: addiu       $a1, $zero, 0x73
    ctx->r5 = ADD32(0, 0X73);
L_800B1908:
    // 0x800B1908: addiu       $v0, $zero, 0x28C
    ctx->r2 = ADD32(0, 0X28C);
    // 0x800B190C: bne         $s0, $v0, L_800B191C
    if (ctx->r16 != ctx->r2) {
        // 0x800B1910: addu        $a0, $s0, $zero
        ctx->r4 = ADD32(ctx->r16, 0);
            goto L_800B191C;
    }
    // 0x800B1910: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
L_800B1914:
    // 0x800B1914: j           L_800B1920
    // 0x800B1918: addiu       $a1, $zero, 0x78
    ctx->r5 = ADD32(0, 0X78);
        goto L_800B1920;
    // 0x800B1918: addiu       $a1, $zero, 0x78
    ctx->r5 = ADD32(0, 0X78);
L_800B191C:
    // 0x800B191C: addiu       $a1, $zero, 0x73
    ctx->r5 = ADD32(0, 0X73);
L_800B1920:
    // 0x800B1920: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // 0x800B1924: jal         0x80066EE4
    // 0x800B1928: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    func_80066EE4(rdram, ctx);
        goto after_5;
    // 0x800B1928: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    after_5:
    // 0x800B192C: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800B1930: lwc1        $f0, 0x56C8($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X56C8);
    // 0x800B1934: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800B1938: sw          $s0, -0x694C($v0)
    MEM_W(-0X694C, ctx->r2) = ctx->r16;
    // 0x800B193C: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800B1940: swc1        $f0, -0x6950($v0)
    MEM_W(-0X6950, ctx->r2) = ctx->f0.u32l;
L_800B1944:
    // 0x800B1944: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
L_800B1948:
    // 0x800B1948: lbu         $v1, 0xB40($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0XB40);
    // 0x800B194C: addiu       $v0, $zero, 0xF
    ctx->r2 = ADD32(0, 0XF);
    // 0x800B1950: beq         $v1, $v0, L_800B195C
    if (ctx->r3 == ctx->r2) {
        // 0x800B1954: addiu       $a0, $zero, 0x28C
        ctx->r4 = ADD32(0, 0X28C);
            goto L_800B195C;
    }
    // 0x800B1954: addiu       $a0, $zero, 0x28C
    ctx->r4 = ADD32(0, 0X28C);
    // 0x800B1958: addiu       $a0, $zero, 0x104
    ctx->r4 = ADD32(0, 0X104);
L_800B195C:
    // 0x800B195C: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x800B1960: addiu       $v0, $zero, 0x28C
    ctx->r2 = ADD32(0, 0X28C);
    // 0x800B1964: beq         $s0, $v0, L_800B1A1C
    if (ctx->r16 == ctx->r2) {
        // 0x800B1968: addu        $v1, $zero, $zero
        ctx->r3 = ADD32(0, 0);
            goto L_800B1A1C;
    }
    // 0x800B1968: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
    // 0x800B196C: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800B1970: addiu       $a1, $v0, -0x48C0
    ctx->r5 = ADD32(ctx->r2, -0X48C0);
    // 0x800B1974: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800B1978: addiu       $a0, $v0, -0x4880
    ctx->r4 = ADD32(ctx->r2, -0X4880);
    // 0x800B197C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x800B1980: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
L_800B1984:
    // 0x800B1984: addu        $v0, $v0, $a1
    ctx->r2 = ADD32(ctx->r2, ctx->r5);
    // 0x800B1988: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x800B198C: bnel        $v0, $s0, L_800B19AC
    if (ctx->r2 != ctx->r16) {
        // 0x800B1990: addiu       $v1, $v1, 0x1
        ctx->r3 = ADD32(ctx->r3, 0X1);
            goto L_800B19AC;
    }
    goto skip_7;
    // 0x800B1990: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    skip_7:
    // 0x800B1994: addu        $v1, $v1, $a0
    ctx->r3 = ADD32(ctx->r3, ctx->r4);
    // 0x800B1998: lbu         $v0, 0x0($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X0);
    // 0x800B199C: bne         $v0, $zero, L_800B1A20
    if (ctx->r2 != 0) {
        // 0x800B19A0: lui         $v0, 0x8011
        ctx->r2 = S32(0X8011 << 16);
            goto L_800B1A20;
    }
    // 0x800B19A0: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800B19A4: j           L_800B19B8
    // 0x800B19A8: sb          $a2, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r6;
        goto L_800B19B8;
    // 0x800B19A8: sb          $a2, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r6;
L_800B19AC:
    // 0x800B19AC: slti        $v0, $v1, 0xE
    ctx->r2 = SIGNED(ctx->r3) < 0XE ? 1 : 0;
    // 0x800B19B0: bne         $v0, $zero, L_800B1984
    if (ctx->r2 != 0) {
        // 0x800B19B4: sll         $v0, $v1, 2
        ctx->r2 = S32(ctx->r3 << 2);
            goto L_800B1984;
    }
    // 0x800B19B4: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
L_800B19B8:
    // 0x800B19B8: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800B19BC: lbu         $v1, 0xB40($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0XB40);
    // 0x800B19C0: addiu       $v0, $zero, 0xF
    ctx->r2 = ADD32(0, 0XF);
    // 0x800B19C4: beq         $v1, $v0, L_800B19DC
    if (ctx->r3 == ctx->r2) {
        // 0x800B19C8: addiu       $v0, $zero, 0x104
        ctx->r2 = ADD32(0, 0X104);
            goto L_800B19DC;
    }
    // 0x800B19C8: addiu       $v0, $zero, 0x104
    ctx->r2 = ADD32(0, 0X104);
    // 0x800B19CC: beq         $s0, $v0, L_800B19E8
    if (ctx->r16 == ctx->r2) {
        // 0x800B19D0: addu        $a0, $s0, $zero
        ctx->r4 = ADD32(ctx->r16, 0);
            goto L_800B19E8;
    }
    // 0x800B19D0: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x800B19D4: j           L_800B19F8
    // 0x800B19D8: addiu       $a1, $zero, 0x73
    ctx->r5 = ADD32(0, 0X73);
        goto L_800B19F8;
    // 0x800B19D8: addiu       $a1, $zero, 0x73
    ctx->r5 = ADD32(0, 0X73);
L_800B19DC:
    // 0x800B19DC: addiu       $v0, $zero, 0x28C
    ctx->r2 = ADD32(0, 0X28C);
    // 0x800B19E0: bne         $s0, $v0, L_800B19F4
    if (ctx->r16 != ctx->r2) {
        // 0x800B19E4: addu        $a0, $s0, $zero
        ctx->r4 = ADD32(ctx->r16, 0);
            goto L_800B19F4;
    }
    // 0x800B19E4: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
L_800B19E8:
    // 0x800B19E8: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x800B19EC: j           L_800B19F8
    // 0x800B19F0: addiu       $a1, $zero, 0x78
    ctx->r5 = ADD32(0, 0X78);
        goto L_800B19F8;
    // 0x800B19F0: addiu       $a1, $zero, 0x78
    ctx->r5 = ADD32(0, 0X78);
L_800B19F4:
    // 0x800B19F4: addiu       $a1, $zero, 0x73
    ctx->r5 = ADD32(0, 0X73);
L_800B19F8:
    // 0x800B19F8: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // 0x800B19FC: jal         0x80066EE4
    // 0x800B1A00: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    func_80066EE4(rdram, ctx);
        goto after_6;
    // 0x800B1A00: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_6:
    // 0x800B1A04: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800B1A08: lwc1        $f0, 0x56CC($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X56CC);
    // 0x800B1A0C: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800B1A10: sw          $s0, -0x694C($v0)
    MEM_W(-0X694C, ctx->r2) = ctx->r16;
    // 0x800B1A14: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800B1A18: swc1        $f0, -0x6950($v0)
    MEM_W(-0X6950, ctx->r2) = ctx->f0.u32l;
L_800B1A1C:
    // 0x800B1A1C: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
L_800B1A20:
    // 0x800B1A20: j           L_800B1BD0
    // 0x800B1A24: sb          $zero, -0x6948($v0)
    MEM_B(-0X6948, ctx->r2) = 0;
        goto L_800B1BD0;
    // 0x800B1A24: sb          $zero, -0x6948($v0)
    MEM_B(-0X6948, ctx->r2) = 0;
L_800B1A28:
    // 0x800B1A28: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800B1A2C: lbu         $v1, 0xB40($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0XB40);
    // 0x800B1A30: addiu       $v0, $zero, 0xF
    ctx->r2 = ADD32(0, 0XF);
    // 0x800B1A34: beq         $v1, $v0, L_800B1A40
    if (ctx->r3 == ctx->r2) {
        // 0x800B1A38: addiu       $a0, $zero, 0x208
        ctx->r4 = ADD32(0, 0X208);
            goto L_800B1A40;
    }
    // 0x800B1A38: addiu       $a0, $zero, 0x208
    ctx->r4 = ADD32(0, 0X208);
    // 0x800B1A3C: addiu       $a0, $zero, 0x124
    ctx->r4 = ADD32(0, 0X124);
L_800B1A40:
    // 0x800B1A40: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x800B1A44: addiu       $v0, $zero, 0x28C
    ctx->r2 = ADD32(0, 0X28C);
    // 0x800B1A48: beq         $s0, $v0, L_800B1B00
    if (ctx->r16 == ctx->r2) {
        // 0x800B1A4C: addu        $v1, $zero, $zero
        ctx->r3 = ADD32(0, 0);
            goto L_800B1B00;
    }
    // 0x800B1A4C: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
    // 0x800B1A50: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800B1A54: addiu       $a1, $v0, -0x48C0
    ctx->r5 = ADD32(ctx->r2, -0X48C0);
    // 0x800B1A58: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800B1A5C: addiu       $a0, $v0, -0x4880
    ctx->r4 = ADD32(ctx->r2, -0X4880);
    // 0x800B1A60: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x800B1A64: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
L_800B1A68:
    // 0x800B1A68: addu        $v0, $v0, $a1
    ctx->r2 = ADD32(ctx->r2, ctx->r5);
    // 0x800B1A6C: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x800B1A70: bnel        $v0, $s0, L_800B1A90
    if (ctx->r2 != ctx->r16) {
        // 0x800B1A74: addiu       $v1, $v1, 0x1
        ctx->r3 = ADD32(ctx->r3, 0X1);
            goto L_800B1A90;
    }
    goto skip_8;
    // 0x800B1A74: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    skip_8:
    // 0x800B1A78: addu        $v1, $v1, $a0
    ctx->r3 = ADD32(ctx->r3, ctx->r4);
    // 0x800B1A7C: lbu         $v0, 0x0($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X0);
    // 0x800B1A80: bnel        $v0, $zero, L_800B1BBC
    if (ctx->r2 != 0) {
        // 0x800B1A84: addu        $v1, $zero, $zero
        ctx->r3 = ADD32(0, 0);
            goto L_800B1BBC;
    }
    goto skip_9;
    // 0x800B1A84: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
    skip_9:
    // 0x800B1A88: j           L_800B1A9C
    // 0x800B1A8C: sb          $a2, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r6;
        goto L_800B1A9C;
    // 0x800B1A8C: sb          $a2, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r6;
L_800B1A90:
    // 0x800B1A90: slti        $v0, $v1, 0xE
    ctx->r2 = SIGNED(ctx->r3) < 0XE ? 1 : 0;
    // 0x800B1A94: bne         $v0, $zero, L_800B1A68
    if (ctx->r2 != 0) {
        // 0x800B1A98: sll         $v0, $v1, 2
        ctx->r2 = S32(ctx->r3 << 2);
            goto L_800B1A68;
    }
    // 0x800B1A98: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
L_800B1A9C:
    // 0x800B1A9C: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800B1AA0: lbu         $v1, 0xB40($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0XB40);
    // 0x800B1AA4: addiu       $v0, $zero, 0xF
    ctx->r2 = ADD32(0, 0XF);
    // 0x800B1AA8: beq         $v1, $v0, L_800B1AC0
    if (ctx->r3 == ctx->r2) {
        // 0x800B1AAC: addiu       $v0, $zero, 0x104
        ctx->r2 = ADD32(0, 0X104);
            goto L_800B1AC0;
    }
    // 0x800B1AAC: addiu       $v0, $zero, 0x104
    ctx->r2 = ADD32(0, 0X104);
    // 0x800B1AB0: beq         $s0, $v0, L_800B1ACC
    if (ctx->r16 == ctx->r2) {
        // 0x800B1AB4: addu        $a0, $s0, $zero
        ctx->r4 = ADD32(ctx->r16, 0);
            goto L_800B1ACC;
    }
    // 0x800B1AB4: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x800B1AB8: j           L_800B1B94
    // 0x800B1ABC: addiu       $a1, $zero, 0x73
    ctx->r5 = ADD32(0, 0X73);
        goto L_800B1B94;
    // 0x800B1ABC: addiu       $a1, $zero, 0x73
    ctx->r5 = ADD32(0, 0X73);
L_800B1AC0:
    // 0x800B1AC0: addiu       $v0, $zero, 0x28C
    ctx->r2 = ADD32(0, 0X28C);
    // 0x800B1AC4: bne         $s0, $v0, L_800B1B90
    if (ctx->r16 != ctx->r2) {
        // 0x800B1AC8: addu        $a0, $s0, $zero
        ctx->r4 = ADD32(ctx->r16, 0);
            goto L_800B1B90;
    }
    // 0x800B1AC8: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
L_800B1ACC:
    // 0x800B1ACC: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x800B1AD0: j           L_800B1B94
    // 0x800B1AD4: addiu       $a1, $zero, 0x78
    ctx->r5 = ADD32(0, 0X78);
        goto L_800B1B94;
    // 0x800B1AD4: addiu       $a1, $zero, 0x78
    ctx->r5 = ADD32(0, 0X78);
L_800B1AD8:
    // 0x800B1AD8: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800B1ADC: lbu         $v1, 0xB40($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0XB40);
    // 0x800B1AE0: addiu       $v0, $zero, 0xF
    ctx->r2 = ADD32(0, 0XF);
    // 0x800B1AE4: beq         $v1, $v0, L_800B1AF0
    if (ctx->r3 == ctx->r2) {
        // 0x800B1AE8: addiu       $a0, $zero, 0x28C
        ctx->r4 = ADD32(0, 0X28C);
            goto L_800B1AF0;
    }
    // 0x800B1AE8: addiu       $a0, $zero, 0x28C
    ctx->r4 = ADD32(0, 0X28C);
    // 0x800B1AEC: addiu       $a0, $zero, 0x132
    ctx->r4 = ADD32(0, 0X132);
L_800B1AF0:
    // 0x800B1AF0: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x800B1AF4: addiu       $v0, $zero, 0x28C
    ctx->r2 = ADD32(0, 0X28C);
    // 0x800B1AF8: bne         $s0, $v0, L_800B1B08
    if (ctx->r16 != ctx->r2) {
        // 0x800B1AFC: addu        $v1, $zero, $zero
        ctx->r3 = ADD32(0, 0);
            goto L_800B1B08;
    }
    // 0x800B1AFC: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
L_800B1B00:
    // 0x800B1B00: j           L_800B1BBC
    // 0x800B1B04: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
        goto L_800B1BBC;
    // 0x800B1B04: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
L_800B1B08:
    // 0x800B1B08: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800B1B0C: addiu       $a1, $v0, -0x48C0
    ctx->r5 = ADD32(ctx->r2, -0X48C0);
    // 0x800B1B10: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800B1B14: addiu       $a0, $v0, -0x4880
    ctx->r4 = ADD32(ctx->r2, -0X4880);
    // 0x800B1B18: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x800B1B1C: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
L_800B1B20:
    // 0x800B1B20: addu        $v0, $v0, $a1
    ctx->r2 = ADD32(ctx->r2, ctx->r5);
    // 0x800B1B24: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x800B1B28: bnel        $v0, $s0, L_800B1B48
    if (ctx->r2 != ctx->r16) {
        // 0x800B1B2C: addiu       $v1, $v1, 0x1
        ctx->r3 = ADD32(ctx->r3, 0X1);
            goto L_800B1B48;
    }
    goto skip_10;
    // 0x800B1B2C: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    skip_10:
    // 0x800B1B30: addu        $v1, $v1, $a0
    ctx->r3 = ADD32(ctx->r3, ctx->r4);
    // 0x800B1B34: lbu         $v0, 0x0($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X0);
    // 0x800B1B38: bnel        $v0, $zero, L_800B1BBC
    if (ctx->r2 != 0) {
        // 0x800B1B3C: addu        $v1, $zero, $zero
        ctx->r3 = ADD32(0, 0);
            goto L_800B1BBC;
    }
    goto skip_11;
    // 0x800B1B3C: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
    skip_11:
    // 0x800B1B40: j           L_800B1B54
    // 0x800B1B44: sb          $a2, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r6;
        goto L_800B1B54;
    // 0x800B1B44: sb          $a2, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r6;
L_800B1B48:
    // 0x800B1B48: slti        $v0, $v1, 0xE
    ctx->r2 = SIGNED(ctx->r3) < 0XE ? 1 : 0;
    // 0x800B1B4C: bne         $v0, $zero, L_800B1B20
    if (ctx->r2 != 0) {
        // 0x800B1B50: sll         $v0, $v1, 2
        ctx->r2 = S32(ctx->r3 << 2);
            goto L_800B1B20;
    }
    // 0x800B1B50: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
L_800B1B54:
    // 0x800B1B54: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800B1B58: lbu         $v1, 0xB40($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0XB40);
    // 0x800B1B5C: addiu       $v0, $zero, 0xF
    ctx->r2 = ADD32(0, 0XF);
    // 0x800B1B60: beq         $v1, $v0, L_800B1B78
    if (ctx->r3 == ctx->r2) {
        // 0x800B1B64: addiu       $v0, $zero, 0x104
        ctx->r2 = ADD32(0, 0X104);
            goto L_800B1B78;
    }
    // 0x800B1B64: addiu       $v0, $zero, 0x104
    ctx->r2 = ADD32(0, 0X104);
    // 0x800B1B68: beq         $s0, $v0, L_800B1B84
    if (ctx->r16 == ctx->r2) {
        // 0x800B1B6C: addu        $a0, $s0, $zero
        ctx->r4 = ADD32(ctx->r16, 0);
            goto L_800B1B84;
    }
    // 0x800B1B6C: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x800B1B70: j           L_800B1B94
    // 0x800B1B74: addiu       $a1, $zero, 0x73
    ctx->r5 = ADD32(0, 0X73);
        goto L_800B1B94;
    // 0x800B1B74: addiu       $a1, $zero, 0x73
    ctx->r5 = ADD32(0, 0X73);
L_800B1B78:
    // 0x800B1B78: addiu       $v0, $zero, 0x28C
    ctx->r2 = ADD32(0, 0X28C);
    // 0x800B1B7C: bne         $s0, $v0, L_800B1B90
    if (ctx->r16 != ctx->r2) {
        // 0x800B1B80: addu        $a0, $s0, $zero
        ctx->r4 = ADD32(ctx->r16, 0);
            goto L_800B1B90;
    }
    // 0x800B1B80: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
L_800B1B84:
    // 0x800B1B84: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x800B1B88: j           L_800B1B94
    // 0x800B1B8C: addiu       $a1, $zero, 0x78
    ctx->r5 = ADD32(0, 0X78);
        goto L_800B1B94;
    // 0x800B1B8C: addiu       $a1, $zero, 0x78
    ctx->r5 = ADD32(0, 0X78);
L_800B1B90:
    // 0x800B1B90: addiu       $a1, $zero, 0x73
    ctx->r5 = ADD32(0, 0X73);
L_800B1B94:
    // 0x800B1B94: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // 0x800B1B98: jal         0x80066EE4
    // 0x800B1B9C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    func_80066EE4(rdram, ctx);
        goto after_7;
    // 0x800B1B9C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_7:
    // 0x800B1BA0: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x800B1BA4: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800B1BA8: lwc1        $f0, 0x56D0($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X56D0);
    // 0x800B1BAC: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800B1BB0: sw          $s0, -0x694C($v0)
    MEM_W(-0X694C, ctx->r2) = ctx->r16;
    // 0x800B1BB4: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800B1BB8: swc1        $f0, -0x6950($v0)
    MEM_W(-0X6950, ctx->r2) = ctx->f0.u32l;
L_800B1BBC:
    // 0x800B1BBC: andi        $v0, $v1, 0xFF
    ctx->r2 = ctx->r3 & 0XFF;
    // 0x800B1BC0: bne         $v0, $zero, L_800B1BD4
    if (ctx->r2 != 0) {
        // 0x800B1BC4: addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
            goto L_800B1BD4;
    }
    // 0x800B1BC4: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_800B1BC8:
    // 0x800B1BC8: jal         0x800AE960
    // 0x800B1BCC: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    func_800AE960(rdram, ctx);
        goto after_8;
    // 0x800B1BCC: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    after_8:
L_800B1BD0:
    // 0x800B1BD0: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_800B1BD4:
    // 0x800B1BD4: lw          $ra, 0x18($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X18);
    // 0x800B1BD8: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x800B1BDC: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x800B1BE0: jr          $ra
    // 0x800B1BE4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x800B1BE4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_800B1430(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B1430: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x800B1434: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x800B1438: addu        $s1, $zero, $zero
    ctx->r17 = ADD32(0, 0);
    // 0x800B143C: sw          $s3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r19;
    // 0x800B1440: addiu       $s3, $zero, 0xB4
    ctx->r19 = ADD32(0, 0XB4);
    // 0x800B1444: sw          $s5, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r21;
    // 0x800B1448: addiu       $s5, $zero, 0xF5
    ctx->r21 = ADD32(0, 0XF5);
    // 0x800B144C: sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // 0x800B1450: addiu       $s2, $zero, 0xFF
    ctx->r18 = ADD32(0, 0XFF);
    // 0x800B1454: sw          $s4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r20;
    // 0x800B1458: addiu       $s4, $zero, 0x37
    ctx->r20 = ADD32(0, 0X37);
    // 0x800B145C: sdc1        $f20, 0x30($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X30, ctx->r29);
    // 0x800B1460: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800B1464: lwc1        $f20, 0x5B08($at)
    ctx->f20.u32l = MEM_W(ctx->r1, 0X5B08);
    // 0x800B1468: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x800B146C: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x800B1470: addiu       $s0, $v0, -0x2040
    ctx->r16 = ADD32(ctx->r2, -0X2040);
    // 0x800B1474: sw          $ra, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r31;
L_800B1478:
    // 0x800B1478: lui         $v0, 0x900
    ctx->r2 = S32(0X900 << 16);
    // 0x800B147C: ori         $v0, $v0, 0x9
    ctx->r2 = ctx->r2 | 0X9;
    // 0x800B1480: addiu       $a0, $s0, 0x4C
    ctx->r4 = ADD32(ctx->r16, 0X4C);
    // 0x800B1484: sw          $v0, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->r2;
    // 0x800B1488: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x800B148C: sw          $v0, 0x60($s0)
    MEM_W(0X60, ctx->r16) = ctx->r2;
    // 0x800B1490: addiu       $v0, $s0, 0xA8
    ctx->r2 = ADD32(ctx->r16, 0XA8);
    // 0x800B1494: sw          $v0, 0x6C($s0)
    MEM_W(0X6C, ctx->r16) = ctx->r2;
    // 0x800B1498: addiu       $v0, $s0, 0xD8
    ctx->r2 = ADD32(ctx->r16, 0XD8);
    // 0x800B149C: sw          $zero, 0xC($s0)
    MEM_W(0XC, ctx->r16) = 0;
    // 0x800B14A0: sw          $zero, 0x8($s0)
    MEM_W(0X8, ctx->r16) = 0;
    // 0x800B14A4: sw          $zero, 0x4($s0)
    MEM_W(0X4, ctx->r16) = 0;
    // 0x800B14A8: sw          $zero, 0x0($s0)
    MEM_W(0X0, ctx->r16) = 0;
    // 0x800B14AC: sw          $a0, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->r4;
    // 0x800B14B0: sw          $zero, 0x14($s0)
    MEM_W(0X14, ctx->r16) = 0;
    // 0x800B14B4: sw          $zero, 0x50($s0)
    MEM_W(0X50, ctx->r16) = 0;
    // 0x800B14B8: sw          $zero, 0x4C($s0)
    MEM_W(0X4C, ctx->r16) = 0;
    // 0x800B14BC: sw          $zero, 0x54($s0)
    MEM_W(0X54, ctx->r16) = 0;
    // 0x800B14C0: sw          $zero, 0x68($s0)
    MEM_W(0X68, ctx->r16) = 0;
    // 0x800B14C4: sw          $zero, 0x5C($s0)
    MEM_W(0X5C, ctx->r16) = 0;
    // 0x800B14C8: sw          $zero, 0x64($s0)
    MEM_W(0X64, ctx->r16) = 0;
    // 0x800B14CC: sw          $v0, 0x70($s0)
    MEM_W(0X70, ctx->r16) = ctx->r2;
    // 0x800B14D0: jal         0x8000A85C
    // 0x800B14D4: sw          $zero, 0x74($s0)
    MEM_W(0X74, ctx->r16) = 0;
    func_8000A85C(rdram, ctx);
        goto after_0;
    // 0x800B14D4: sw          $zero, 0x74($s0)
    MEM_W(0X74, ctx->r16) = 0;
    after_0:
    // 0x800B14D8: lui         $a0, 0x80C
    ctx->r4 = S32(0X80C << 16);
    // 0x800B14DC: ori         $a0, $a0, 0x5000
    ctx->r4 = ctx->r4 | 0X5000;
    // 0x800B14E0: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x800B14E4: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    // 0x800B14E8: addiu       $v0, $s0, 0xB8
    ctx->r2 = ADD32(ctx->r16, 0XB8);
    // 0x800B14EC: sw          $v0, 0xB0($s0)
    MEM_W(0XB0, ctx->r16) = ctx->r2;
    // 0x800B14F0: addiu       $v0, $zero, 0x10
    ctx->r2 = ADD32(0, 0X10);
    // 0x800B14F4: sw          $v0, 0xB8($s0)
    MEM_W(0XB8, ctx->r16) = ctx->r2;
    // 0x800B14F8: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // 0x800B14FC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800B1500: ori         $v1, $v1, 0x82
    ctx->r3 = ctx->r3 | 0X82;
    // 0x800B1504: sw          $zero, 0xAC($s0)
    MEM_W(0XAC, ctx->r16) = 0;
    // 0x800B1508: sw          $zero, 0xA8($s0)
    MEM_W(0XA8, ctx->r16) = 0;
    // 0x800B150C: sw          $v0, 0xB4($s0)
    MEM_W(0XB4, ctx->r16) = ctx->r2;
    // 0x800B1510: sw          $a0, 0xBC($s0)
    MEM_W(0XBC, ctx->r16) = ctx->r4;
    // 0x800B1514: sw          $zero, 0xC0($s0)
    MEM_W(0XC0, ctx->r16) = 0;
    // 0x800B1518: sw          $zero, 0xC0($s0)
    MEM_W(0XC0, ctx->r16) = 0;
    // 0x800B151C: sw          $v1, 0xB8($s0)
    MEM_W(0XB8, ctx->r16) = ctx->r3;
L_800B1520:
    // 0x800B1520: sh          $a1, 0xC4($a2)
    MEM_H(0XC4, ctx->r6) = ctx->r5;
    // 0x800B1524: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x800B1528: sltiu       $v0, $a1, 0x3
    ctx->r2 = ctx->r5 < 0X3 ? 1 : 0;
    // 0x800B152C: bne         $v0, $zero, L_800B1520
    if (ctx->r2 != 0) {
        // 0x800B1530: addiu       $a2, $a2, 0x2
        ctx->r6 = ADD32(ctx->r6, 0X2);
            goto L_800B1520;
    }
    // 0x800B1530: addiu       $a2, $a2, 0x2
    ctx->r6 = ADD32(ctx->r6, 0X2);
    // 0x800B1534: bne         $s1, $zero, L_800B1574
    if (ctx->r17 != 0) {
        // 0x800B1538: sltiu       $v0, $s1, 0x4
        ctx->r2 = ctx->r17 < 0X4 ? 1 : 0;
            goto L_800B1574;
    }
    // 0x800B1538: sltiu       $v0, $s1, 0x4
    ctx->r2 = ctx->r17 < 0X4 ? 1 : 0;
    // 0x800B153C: addiu       $v0, $zero, 0xA0
    ctx->r2 = ADD32(0, 0XA0);
    // 0x800B1540: sb          $s3, 0xCC($s0)
    MEM_B(0XCC, ctx->r16) = ctx->r19;
    // 0x800B1544: sb          $s3, 0xCD($s0)
    MEM_B(0XCD, ctx->r16) = ctx->r19;
    // 0x800B1548: sb          $s5, 0xCE($s0)
    MEM_B(0XCE, ctx->r16) = ctx->r21;
    // 0x800B154C: sb          $zero, 0xCF($s0)
    MEM_B(0XCF, ctx->r16) = 0;
    // 0x800B1550: sb          $s3, 0xD0($s0)
    MEM_B(0XD0, ctx->r16) = ctx->r19;
    // 0x800B1554: sb          $s3, 0xD1($s0)
    MEM_B(0XD1, ctx->r16) = ctx->r19;
    // 0x800B1558: sb          $s5, 0xD2($s0)
    MEM_B(0XD2, ctx->r16) = ctx->r21;
    // 0x800B155C: sb          $zero, 0xD3($s0)
    MEM_B(0XD3, ctx->r16) = 0;
    // 0x800B1560: sb          $zero, 0xD4($s0)
    MEM_B(0XD4, ctx->r16) = 0;
    // 0x800B1564: sb          $zero, 0xD5($s0)
    MEM_B(0XD5, ctx->r16) = 0;
    // 0x800B1568: sb          $v0, 0xD6($s0)
    MEM_B(0XD6, ctx->r16) = ctx->r2;
    // 0x800B156C: j           L_800B15EC
    // 0x800B1570: sb          $zero, 0xD7($s0)
    MEM_B(0XD7, ctx->r16) = 0;
        goto L_800B15EC;
    // 0x800B1570: sb          $zero, 0xD7($s0)
    MEM_B(0XD7, ctx->r16) = 0;
L_800B1574:
    // 0x800B1574: beq         $v0, $zero, L_800B15B0
    if (ctx->r2 == 0) {
        // 0x800B1578: addiu       $v0, $zero, 0x50
        ctx->r2 = ADD32(0, 0X50);
            goto L_800B15B0;
    }
    // 0x800B1578: addiu       $v0, $zero, 0x50
    ctx->r2 = ADD32(0, 0X50);
    // 0x800B157C: sb          $v0, 0xD4($s0)
    MEM_B(0XD4, ctx->r16) = ctx->r2;
    // 0x800B1580: sb          $v0, 0xD5($s0)
    MEM_B(0XD5, ctx->r16) = ctx->r2;
    // 0x800B1584: addiu       $v0, $zero, 0xC8
    ctx->r2 = ADD32(0, 0XC8);
    // 0x800B1588: sb          $s2, 0xCC($s0)
    MEM_B(0XCC, ctx->r16) = ctx->r18;
    // 0x800B158C: sb          $s2, 0xCD($s0)
    MEM_B(0XCD, ctx->r16) = ctx->r18;
    // 0x800B1590: sb          $s2, 0xCE($s0)
    MEM_B(0XCE, ctx->r16) = ctx->r18;
    // 0x800B1594: sb          $zero, 0xCF($s0)
    MEM_B(0XCF, ctx->r16) = 0;
    // 0x800B1598: sb          $s2, 0xD0($s0)
    MEM_B(0XD0, ctx->r16) = ctx->r18;
    // 0x800B159C: sb          $s2, 0xD1($s0)
    MEM_B(0XD1, ctx->r16) = ctx->r18;
    // 0x800B15A0: sb          $s2, 0xD2($s0)
    MEM_B(0XD2, ctx->r16) = ctx->r18;
    // 0x800B15A4: sb          $zero, 0xD3($s0)
    MEM_B(0XD3, ctx->r16) = 0;
    // 0x800B15A8: j           L_800B15E8
    // 0x800B15AC: sb          $s2, 0xD6($s0)
    MEM_B(0XD6, ctx->r16) = ctx->r18;
        goto L_800B15E8;
    // 0x800B15AC: sb          $s2, 0xD6($s0)
    MEM_B(0XD6, ctx->r16) = ctx->r18;
L_800B15B0:
    // 0x800B15B0: addiu       $v0, $zero, 0x1E
    ctx->r2 = ADD32(0, 0X1E);
    // 0x800B15B4: sb          $v0, 0xD4($s0)
    MEM_B(0XD4, ctx->r16) = ctx->r2;
    // 0x800B15B8: sb          $v0, 0xD5($s0)
    MEM_B(0XD5, ctx->r16) = ctx->r2;
    // 0x800B15BC: addiu       $v0, $zero, 0xE1
    ctx->r2 = ADD32(0, 0XE1);
    // 0x800B15C0: sb          $v0, 0xD6($s0)
    MEM_B(0XD6, ctx->r16) = ctx->r2;
    // 0x800B15C4: addiu       $v0, $zero, 0x9B
    ctx->r2 = ADD32(0, 0X9B);
    // 0x800B15C8: sb          $zero, 0xCC($s0)
    MEM_B(0XCC, ctx->r16) = 0;
    // 0x800B15CC: sb          $zero, 0xCD($s0)
    MEM_B(0XCD, ctx->r16) = 0;
    // 0x800B15D0: sb          $s4, 0xCE($s0)
    MEM_B(0XCE, ctx->r16) = ctx->r20;
    // 0x800B15D4: sb          $zero, 0xCF($s0)
    MEM_B(0XCF, ctx->r16) = 0;
    // 0x800B15D8: sb          $zero, 0xD0($s0)
    MEM_B(0XD0, ctx->r16) = 0;
    // 0x800B15DC: sb          $zero, 0xD1($s0)
    MEM_B(0XD1, ctx->r16) = 0;
    // 0x800B15E0: sb          $s4, 0xD2($s0)
    MEM_B(0XD2, ctx->r16) = ctx->r20;
    // 0x800B15E4: sb          $zero, 0xD3($s0)
    MEM_B(0XD3, ctx->r16) = 0;
L_800B15E8:
    // 0x800B15E8: sb          $v0, 0xD7($s0)
    MEM_B(0XD7, ctx->r16) = ctx->r2;
L_800B15EC:
    // 0x800B15EC: lw          $v0, 0x70($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X70);
    // 0x800B15F0: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800B15F4: lwc1        $f0, 0x5B0C($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X5B0C);
    // 0x800B15F8: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800B15FC: lwc1        $f2, 0x5B10($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X5B10);
    // 0x800B1600: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x800B1604: swc1        $f0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f0.u32l;
    // 0x800B1608: swc1        $f20, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f20.u32l;
    // 0x800B160C: sw          $zero, 0x8($v0)
    MEM_W(0X8, ctx->r2) = 0;
    // 0x800B1610: swc1        $f2, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->f2.u32l;
    // 0x800B1614: swc1        $f20, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->f20.u32l;
    // 0x800B1618: sw          $zero, 0x14($v0)
    MEM_W(0X14, ctx->r2) = 0;
    // 0x800B161C: sw          $zero, 0x18($v0)
    MEM_W(0X18, ctx->r2) = 0;
    // 0x800B1620: sw          $zero, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = 0;
    // 0x800B1624: sw          $zero, 0x20($v0)
    MEM_W(0X20, ctx->r2) = 0;
    // 0x800B1628: sltiu       $v0, $s1, 0x7
    ctx->r2 = ctx->r17 < 0X7 ? 1 : 0;
    // 0x800B162C: bne         $v0, $zero, L_800B1478
    if (ctx->r2 != 0) {
        // 0x800B1630: addiu       $s0, $s0, 0xFC
        ctx->r16 = ADD32(ctx->r16, 0XFC);
            goto L_800B1478;
    }
    // 0x800B1630: addiu       $s0, $s0, 0xFC
    ctx->r16 = ADD32(ctx->r16, 0XFC);
    // 0x800B1634: lw          $ra, 0x28($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X28);
    // 0x800B1638: lw          $s5, 0x24($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X24);
    // 0x800B163C: lw          $s4, 0x20($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X20);
    // 0x800B1640: lw          $s3, 0x1C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X1C);
    // 0x800B1644: lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X18);
    // 0x800B1648: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x800B164C: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x800B1650: ldc1        $f20, 0x30($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X30);
    // 0x800B1654: jr          $ra
    // 0x800B1658: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x800B1658: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void bridgeLoadShipBlueprints(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B165C: addiu       $sp, $sp, -0xA8
    ctx->r29 = ADD32(ctx->r29, -0XA8);
    // 0x800B1660: addiu       $v1, $sp, 0x30
    ctx->r3 = ADD32(ctx->r29, 0X30);
    // 0x800B1664: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x800B1668: addiu       $v0, $v0, 0x5B54
    ctx->r2 = ADD32(ctx->r2, 0X5B54);
    // 0x800B166C: sw          $a0, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->r4;
    // 0x800B1670: addiu       $a0, $v0, 0x20
    ctx->r4 = ADD32(ctx->r2, 0X20);
    // 0x800B1674: sw          $ra, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->r31;
    // 0x800B1678: sw          $fp, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->r30;
    // 0x800B167C: sw          $s7, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->r23;
    // 0x800B1680: sw          $s6, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->r22;
    // 0x800B1684: sw          $s5, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->r21;
    // 0x800B1688: sw          $s4, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->r20;
    // 0x800B168C: sw          $s3, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->r19;
    // 0x800B1690: sw          $s2, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r18;
    // 0x800B1694: sw          $s1, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r17;
    // 0x800B1698: sw          $s0, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r16;
L_800B169C:
    // 0x800B169C: lw          $a3, 0x0($v0)
    ctx->r7 = MEM_W(ctx->r2, 0X0);
    // 0x800B16A0: lw          $t0, 0x4($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X4);
    // 0x800B16A4: lw          $t1, 0x8($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X8);
    // 0x800B16A8: lw          $t2, 0xC($v0)
    ctx->r10 = MEM_W(ctx->r2, 0XC);
    // 0x800B16AC: sw          $a3, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r7;
    // 0x800B16B0: sw          $t0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r8;
    // 0x800B16B4: sw          $t1, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r9;
    // 0x800B16B8: sw          $t2, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r10;
    // 0x800B16BC: addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
    // 0x800B16C0: bne         $v0, $a0, L_800B169C
    if (ctx->r2 != ctx->r4) {
        // 0x800B16C4: addiu       $v1, $v1, 0x10
        ctx->r3 = ADD32(ctx->r3, 0X10);
            goto L_800B169C;
    }
    // 0x800B16C4: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
    // 0x800B16C8: lw          $a3, 0x0($v0)
    ctx->r7 = MEM_W(ctx->r2, 0X0);
    // 0x800B16CC: sw          $a3, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r7;
    // 0x800B16D0: addu        $s4, $zero, $zero
    ctx->r20 = ADD32(0, 0);
    // 0x800B16D4: addiu       $s7, $zero, 0x1
    ctx->r23 = ADD32(0, 0X1);
    // 0x800B16D8: addiu       $fp, $sp, 0x58
    ctx->r30 = ADD32(ctx->r29, 0X58);
    // 0x800B16DC: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x800B16E0: addiu       $s6, $v0, -0x38D8
    ctx->r22 = ADD32(ctx->r2, -0X38D8);
    // 0x800B16E4: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x800B16E8: addiu       $s5, $v0, -0x38FC
    ctx->r21 = ADD32(ctx->r2, -0X38FC);
    // 0x800B16EC: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x800B16F0: addiu       $s2, $v0, -0x2250
    ctx->r18 = ADD32(ctx->r2, -0X2250);
    // 0x800B16F4: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x800B16F8: addiu       $s3, $v0, -0x20A0
    ctx->r19 = ADD32(ctx->r2, -0X20A0);
L_800B16FC:
    // 0x800B16FC: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    // 0x800B1700: lui         $a1, 0x800A
    ctx->r5 = S32(0X800A << 16);
    // 0x800B1704: addiu       $a1, $a1, 0x5B78
    ctx->r5 = ADD32(ctx->r5, 0X5B78);
    // 0x800B1708: sll         $v0, $s4, 2
    ctx->r2 = S32(ctx->r20 << 2);
    // 0x800B170C: addu        $v0, $sp, $v0
    ctx->r2 = ADD32(ctx->r29, ctx->r2);
    // 0x800B1710: lw          $a2, 0x30($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X30);
    // 0x800B1714: jal         0x80033CC4
    // 0x800B1718: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    sprintf_recomp(rdram, ctx);
        goto after_0;
    // 0x800B1718: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    after_0:
    // 0x800B171C: jal         0x8006488C
    // 0x800B1720: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    load_asset(rdram, ctx);
        goto after_1;
    // 0x800B1720: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    after_1:
    // 0x800B1724: addu        $s1, $v0, $zero
    ctx->r17 = ADD32(ctx->r2, 0);
    // 0x800B1728: addiu       $s0, $s1, 0x4
    ctx->r16 = ADD32(ctx->r17, 0X4);
    // 0x800B172C: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x800B1730: jal         0x80055488
    // 0x800B1734: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    full_header_image_offset_convert(rdram, ctx);
        goto after_2;
    // 0x800B1734: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    after_2:
    // 0x800B1738: sh          $s7, 0x58($sp)
    MEM_H(0X58, ctx->r29) = ctx->r23;
    // 0x800B173C: lw          $a1, 0x24($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X24);
    // 0x800B1740: jal         0x8000761C
    // 0x800B1744: addiu       $a0, $sp, 0x6C
    ctx->r4 = ADD32(ctx->r29, 0X6C);
    rs_strcpy(rdram, ctx);
        goto after_3;
    // 0x800B1744: addiu       $a0, $sp, 0x6C
    ctx->r4 = ADD32(ctx->r29, 0X6C);
    after_3:
    // 0x800B1748: addu        $a0, $fp, $zero
    ctx->r4 = ADD32(ctx->r30, 0);
    // 0x800B174C: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x800B1750: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x800B1754: addiu       $v0, $zero, 0x2004
    ctx->r2 = ADD32(0, 0X2004);
    // 0x800B1758: jal         0x80022B90
    // 0x800B175C: sh          $v0, 0x2E($a1)
    MEM_H(0X2E, ctx->r5) = ctx->r2;
    func_80022B90(rdram, ctx);
        goto after_4;
    // 0x800B175C: sh          $v0, 0x2E($a1)
    MEM_H(0X2E, ctx->r5) = ctx->r2;
    after_4:
    // 0x800B1760: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // 0x800B1764: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x800B1768: addiu       $a2, $zero, 0x30
    ctx->r6 = ADD32(0, 0X30);
    // 0x800B176C: jal         0x800078E0
    // 0x800B1770: sh          $v0, 0x0($s3)
    MEM_H(0X0, ctx->r19) = ctx->r2;
    rs_memset(rdram, ctx);
        goto after_5;
    // 0x800B1770: sh          $v0, 0x0($s3)
    MEM_H(0X0, ctx->r19) = ctx->r2;
    after_5:
    // 0x800B1774: addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    // 0x800B1778: lw          $a0, 0xA8($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XA8);
    // 0x800B177C: addiu       $a2, $zero, 0xA
    ctx->r6 = ADD32(0, 0XA);
    // 0x800B1780: sw          $s3, 0xC($s2)
    MEM_W(0XC, ctx->r18) = ctx->r19;
    // 0x800B1784: sh          $s7, 0xA($s2)
    MEM_H(0XA, ctx->r18) = ctx->r23;
    // 0x800B1788: sh          $s7, 0x8($s2)
    MEM_H(0X8, ctx->r18) = ctx->r23;
    // 0x800B178C: lwc1        $f0, 0x0($s5)
    ctx->f0.u32l = MEM_W(ctx->r21, 0X0);
    // 0x800B1790: addiu       $s5, $s5, 0x4
    ctx->r21 = ADD32(ctx->r21, 0X4);
    // 0x800B1794: addiu       $s3, $s3, 0x2
    ctx->r19 = ADD32(ctx->r19, 0X2);
    // 0x800B1798: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x800B179C: swc1        $f0, 0x24($s2)
    MEM_W(0X24, ctx->r18) = ctx->f0.u32l;
    // 0x800B17A0: lwc1        $f0, 0x0($s6)
    ctx->f0.u32l = MEM_W(ctx->r22, 0X0);
    // 0x800B17A4: addiu       $s6, $s6, 0x4
    ctx->r22 = ADD32(ctx->r22, 0X4);
    // 0x800B17A8: sw          $v0, 0x14($s2)
    MEM_W(0X14, ctx->r18) = ctx->r2;
    // 0x800B17AC: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // 0x800B17B0: sb          $zero, 0x2C($s2)
    MEM_B(0X2C, ctx->r18) = 0;
    // 0x800B17B4: sb          $zero, 0x2D($s2)
    MEM_B(0X2D, ctx->r18) = 0;
    // 0x800B17B8: sb          $zero, 0x2E($s2)
    MEM_B(0X2E, ctx->r18) = 0;
    // 0x800B17BC: sb          $v0, 0x2F($s2)
    MEM_B(0X2F, ctx->r18) = ctx->r2;
    // 0x800B17C0: jal         0x800642A0
    // 0x800B17C4: swc1        $f0, 0x28($s2)
    MEM_W(0X28, ctx->r18) = ctx->f0.u32l;
    func_800642A0(rdram, ctx);
        goto after_6;
    // 0x800B17C4: swc1        $f0, 0x28($s2)
    MEM_W(0X28, ctx->r18) = ctx->f0.u32l;
    after_6:
    // 0x800B17C8: jal         0x80001C98
    // 0x800B17CC: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    rs_free(rdram, ctx);
        goto after_7;
    // 0x800B17CC: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    after_7:
    // 0x800B17D0: sltiu       $v0, $s4, 0x9
    ctx->r2 = ctx->r20 < 0X9 ? 1 : 0;
    // 0x800B17D4: bne         $v0, $zero, L_800B16FC
    if (ctx->r2 != 0) {
        // 0x800B17D8: addiu       $s2, $s2, 0x30
        ctx->r18 = ADD32(ctx->r18, 0X30);
            goto L_800B16FC;
    }
    // 0x800B17D8: addiu       $s2, $s2, 0x30
    ctx->r18 = ADD32(ctx->r18, 0X30);
    // 0x800B17DC: lw          $ra, 0xA4($sp)
    ctx->r31 = MEM_W(ctx->r29, 0XA4);
    // 0x800B17E0: lw          $fp, 0xA0($sp)
    ctx->r30 = MEM_W(ctx->r29, 0XA0);
    // 0x800B17E4: lw          $s7, 0x9C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X9C);
    // 0x800B17E8: lw          $s6, 0x98($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X98);
    // 0x800B17EC: lw          $s5, 0x94($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X94);
    // 0x800B17F0: lw          $s4, 0x90($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X90);
    // 0x800B17F4: lw          $s3, 0x8C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X8C);
    // 0x800B17F8: lw          $s2, 0x88($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X88);
    // 0x800B17FC: lw          $s1, 0x84($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X84);
    // 0x800B1800: lw          $s0, 0x80($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X80);
    // 0x800B1804: jr          $ra
    // 0x800B1808: addiu       $sp, $sp, 0xA8
    ctx->r29 = ADD32(ctx->r29, 0XA8);
    return;
    // 0x800B1808: addiu       $sp, $sp, 0xA8
    ctx->r29 = ADD32(ctx->r29, 0XA8);
;}
RECOMP_FUNC void func_800B180C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B180C: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x800B1810: sw          $fp, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r30;
    // 0x800B1814: addu        $fp, $a0, $zero
    ctx->r30 = ADD32(ctx->r4, 0);
    // 0x800B1818: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x800B181C: andi        $s0, $a1, 0xFF
    ctx->r16 = ctx->r5 & 0XFF;
    // 0x800B1820: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x800B1824: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x800B1828: sw          $s7, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r23;
    // 0x800B182C: sw          $s6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r22;
    // 0x800B1830: sw          $s5, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r21;
    // 0x800B1834: sw          $s4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r20;
    // 0x800B1838: sw          $s3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r19;
    // 0x800B183C: sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // 0x800B1840: jal         0x800C6234
    // 0x800B1844: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    getAvailablePlayerCraftFlagsConsiderUnlocks(rdram, ctx);
        goto after_0;
    // 0x800B1844: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    after_0:
    // 0x800B1848: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x800B184C: jal         0x800C63C0
    // 0x800B1850: addu        $s6, $v0, $zero
    ctx->r22 = ADD32(ctx->r2, 0);
    getAvailablePlayerCraftFlagsIgnoreUnlocks(rdram, ctx);
        goto after_1;
    // 0x800B1850: addu        $s6, $v0, $zero
    ctx->r22 = ADD32(ctx->r2, 0);
    after_1:
    // 0x800B1854: addu        $s4, $v0, $zero
    ctx->r20 = ADD32(ctx->r2, 0);
    // 0x800B1858: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
    // 0x800B185C: addu        $s0, $v1, $zero
    ctx->r16 = ADD32(ctx->r3, 0);
    // 0x800B1860: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x800B1864: sllv        $v0, $a0, $s0
    ctx->r2 = S32(ctx->r4 << (ctx->r16 & 31));
L_800B1868:
    // 0x800B1868: and         $v0, $s4, $v0
    ctx->r2 = ctx->r20 & ctx->r2;
    // 0x800B186C: bnel        $v0, $zero, L_800B1874
    if (ctx->r2 != 0) {
        // 0x800B1870: addiu       $v1, $v1, 0x1
        ctx->r3 = ADD32(ctx->r3, 0X1);
            goto L_800B1874;
    }
    goto skip_0;
    // 0x800B1870: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    skip_0:
L_800B1874:
    // 0x800B1874: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x800B1878: sltiu       $v0, $s0, 0x9
    ctx->r2 = ctx->r16 < 0X9 ? 1 : 0;
    // 0x800B187C: bne         $v0, $zero, L_800B1868
    if (ctx->r2 != 0) {
        // 0x800B1880: sllv        $v0, $a0, $s0
        ctx->r2 = S32(ctx->r4 << (ctx->r16 & 31));
            goto L_800B1868;
    }
    // 0x800B1880: sllv        $v0, $a0, $s0
    ctx->r2 = S32(ctx->r4 << (ctx->r16 & 31));
    // 0x800B1884: addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
    // 0x800B1888: addiu       $s5, $zero, 0x1
    ctx->r21 = ADD32(0, 0X1);
    // 0x800B188C: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x800B1890: addiu       $s7, $v0, -0x38B4
    ctx->r23 = ADD32(ctx->r2, -0X38B4);
    // 0x800B1894: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x800B1898: addiu       $s1, $v0, -0x2250
    ctx->r17 = ADD32(ctx->r2, -0X2250);
    // 0x800B189C: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x800B18A0: addiu       $s2, $v0, -0x2080
    ctx->r18 = ADD32(ctx->r2, -0X2080);
    // 0x800B18A4: addiu       $v0, $v1, -0x1
    ctx->r2 = ADD32(ctx->r3, -0X1);
    // 0x800B18A8: sll         $s3, $v0, 5
    ctx->r19 = S32(ctx->r2 << 5);
L_800B18AC:
    // 0x800B18AC: sllv        $a0, $s5, $s0
    ctx->r4 = S32(ctx->r21 << (ctx->r16 & 31));
    // 0x800B18B0: and         $v0, $s4, $a0
    ctx->r2 = ctx->r20 & ctx->r4;
    // 0x800B18B4: beq         $v0, $zero, L_800B1950
    if (ctx->r2 == 0) {
        // 0x800B18B8: addu        $v1, $s3, $s7
        ctx->r3 = ADD32(ctx->r19, ctx->r23);
            goto L_800B1950;
    }
    // 0x800B18B8: addu        $v1, $s3, $s7
    ctx->r3 = ADD32(ctx->r19, ctx->r23);
    // 0x800B18BC: lh          $v0, 0x0($v1)
    ctx->r2 = MEM_H(ctx->r3, 0X0);
    // 0x800B18C0: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800B18C4: lwc1        $f2, 0x5B88($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X5B88);
    // 0x800B18C8: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800B18CC: lwc1        $f4, 0x5B8C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X5B8C);
    // 0x800B18D0: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x800B18D4: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x800B18D8: div.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f2.fl);
    // 0x800B18DC: sub.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f4.fl;
    // 0x800B18E0: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800B18E4: lwc1        $f2, 0x5B90($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X5B90);
    // 0x800B18E8: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x800B18EC: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800B18F0: lwc1        $f2, 0x5B94($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X5B94);
    // 0x800B18F4: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x800B18F8: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800B18FC: lwc1        $f4, 0x5B98($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X5B98);
    // 0x800B1900: trunc.w.s   $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    ctx->f6.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800B1904: mfc1        $v0, $f6
    ctx->r2 = (int32_t)ctx->f6.u32l;
    // 0x800B1908: swc1        $f0, 0x18($s1)
    MEM_W(0X18, ctx->r17) = ctx->f0.u32l;
    // 0x800B190C: sh          $v0, 0x0($s2)
    MEM_H(0X0, ctx->r18) = ctx->r2;
    // 0x800B1910: lh          $v0, 0x2($v1)
    ctx->r2 = MEM_H(ctx->r3, 0X2);
    // 0x800B1914: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800B1918: lwc1        $f2, 0x5B9C($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X5B9C);
    // 0x800B191C: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x800B1920: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x800B1924: div.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f2.fl);
    // 0x800B1928: sub.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f4.fl;
    // 0x800B192C: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800B1930: lwc1        $f2, 0x5BA0($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X5BA0);
    // 0x800B1934: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x800B1938: addiu       $s3, $s3, 0x4
    ctx->r19 = ADD32(ctx->r19, 0X4);
    // 0x800B193C: div.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f2.fl);
    // 0x800B1940: trunc.w.s   $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    ctx->f6.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800B1944: mfc1        $v0, $f6
    ctx->r2 = (int32_t)ctx->f6.u32l;
    // 0x800B1948: swc1        $f0, 0x1C($s1)
    MEM_W(0X1C, ctx->r17) = ctx->f0.u32l;
    // 0x800B194C: sh          $v0, 0x2($s2)
    MEM_H(0X2, ctx->r18) = ctx->r2;
L_800B1950:
    // 0x800B1950: and         $v0, $s6, $a0
    ctx->r2 = ctx->r22 & ctx->r4;
    // 0x800B1954: beq         $v0, $zero, L_800B1978
    if (ctx->r2 == 0) {
        // 0x800B1958: lui         $v0, 0x800D
        ctx->r2 = S32(0X800D << 16);
            goto L_800B1978;
    }
    // 0x800B1958: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x800B195C: addiu       $a3, $v0, -0x3908
    ctx->r7 = ADD32(ctx->r2, -0X3908);
    // 0x800B1960: lwl         $t0, 0x0($a3)
    ctx->r8 = do_lwl(rdram, ctx->r8, ctx->r7, 0X0);
    // 0x800B1964: lwr         $t0, 0x3($a3)
    ctx->r8 = do_lwr(rdram, ctx->r8, ctx->r7, 0X3);
    // 0x800B1968: swl         $t0, 0x2C($s1)
    do_swl(rdram, 0X2C, ctx->r17, ctx->r8);
    // 0x800B196C: swr         $t0, 0x2F($s1)
    do_swr(rdram, 0X2F, ctx->r17, ctx->r8);
    // 0x800B1970: j           L_800B1994
    // 0x800B1974: addu        $a0, $fp, $zero
    ctx->r4 = ADD32(ctx->r30, 0);
        goto L_800B1994;
    // 0x800B1974: addu        $a0, $fp, $zero
    ctx->r4 = ADD32(ctx->r30, 0);
L_800B1978:
    // 0x800B1978: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x800B197C: addiu       $a3, $v0, -0x3904
    ctx->r7 = ADD32(ctx->r2, -0X3904);
    // 0x800B1980: lwl         $t0, 0x0($a3)
    ctx->r8 = do_lwl(rdram, ctx->r8, ctx->r7, 0X0);
    // 0x800B1984: lwr         $t0, 0x3($a3)
    ctx->r8 = do_lwr(rdram, ctx->r8, ctx->r7, 0X3);
    // 0x800B1988: swl         $t0, 0x2C($s1)
    do_swl(rdram, 0X2C, ctx->r17, ctx->r8);
    // 0x800B198C: swr         $t0, 0x2F($s1)
    do_swr(rdram, 0X2F, ctx->r17, ctx->r8);
    // 0x800B1990: addu        $a0, $fp, $zero
    ctx->r4 = ADD32(ctx->r30, 0);
L_800B1994:
    // 0x800B1994: sllv        $a2, $s5, $s0
    ctx->r6 = S32(ctx->r21 << (ctx->r16 & 31));
    // 0x800B1998: and         $a2, $s4, $a2
    ctx->r6 = ctx->r20 & ctx->r6;
    // 0x800B199C: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    // 0x800B19A0: jal         0x800646AC
    // 0x800B19A4: sltu        $a2, $zero, $a2
    ctx->r6 = 0 < ctx->r6 ? 1 : 0;
    func_800646AC(rdram, ctx);
        goto after_2;
    // 0x800B19A4: sltu        $a2, $zero, $a2
    ctx->r6 = 0 < ctx->r6 ? 1 : 0;
    after_2:
    // 0x800B19A8: addiu       $s1, $s1, 0x30
    ctx->r17 = ADD32(ctx->r17, 0X30);
    // 0x800B19AC: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x800B19B0: sltiu       $v0, $s0, 0x9
    ctx->r2 = ctx->r16 < 0X9 ? 1 : 0;
    // 0x800B19B4: bne         $v0, $zero, L_800B18AC
    if (ctx->r2 != 0) {
        // 0x800B19B8: addiu       $s2, $s2, 0x4
        ctx->r18 = ADD32(ctx->r18, 0X4);
            goto L_800B18AC;
    }
    // 0x800B19B8: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
    // 0x800B19BC: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x800B19C0: lw          $fp, 0x30($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X30);
    // 0x800B19C4: lw          $s7, 0x2C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X2C);
    // 0x800B19C8: lw          $s6, 0x28($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X28);
    // 0x800B19CC: lw          $s5, 0x24($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X24);
    // 0x800B19D0: lw          $s4, 0x20($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X20);
    // 0x800B19D4: lw          $s3, 0x1C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X1C);
    // 0x800B19D8: lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X18);
    // 0x800B19DC: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x800B19E0: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x800B19E4: jr          $ra
    // 0x800B19E8: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x800B19E8: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_800B19EC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B19EC: addiu       $sp, $sp, -0x140
    ctx->r29 = ADD32(ctx->r29, -0X140);
    // 0x800B19F0: sw          $s1, 0x124($sp)
    MEM_W(0X124, ctx->r29) = ctx->r17;
    // 0x800B19F4: addu        $s1, $zero, $zero
    ctx->r17 = ADD32(0, 0);
    // 0x800B19F8: andi        $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 & 0XFF;
    // 0x800B19FC: sw          $ra, 0x138($sp)
    MEM_W(0X138, ctx->r29) = ctx->r31;
    // 0x800B1A00: sw          $s5, 0x134($sp)
    MEM_W(0X134, ctx->r29) = ctx->r21;
    // 0x800B1A04: sw          $s4, 0x130($sp)
    MEM_W(0X130, ctx->r29) = ctx->r20;
    // 0x800B1A08: sw          $s3, 0x12C($sp)
    MEM_W(0X12C, ctx->r29) = ctx->r19;
    // 0x800B1A0C: sw          $s2, 0x128($sp)
    MEM_W(0X128, ctx->r29) = ctx->r18;
    // 0x800B1A10: jal         0x800C63C0
    // 0x800B1A14: sw          $s0, 0x120($sp)
    MEM_W(0X120, ctx->r29) = ctx->r16;
    getAvailablePlayerCraftFlagsIgnoreUnlocks(rdram, ctx);
        goto after_0;
    // 0x800B1A14: sw          $s0, 0x120($sp)
    MEM_W(0X120, ctx->r29) = ctx->r16;
    after_0:
    // 0x800B1A18: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // 0x800B1A1C: addu        $v1, $s1, $zero
    ctx->r3 = ADD32(ctx->r17, 0);
    // 0x800B1A20: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x800B1A24: sllv        $v0, $a1, $v1
    ctx->r2 = S32(ctx->r5 << (ctx->r3 & 31));
L_800B1A28:
    // 0x800B1A28: and         $v0, $a0, $v0
    ctx->r2 = ctx->r4 & ctx->r2;
    // 0x800B1A2C: bnel        $v0, $zero, L_800B1A34
    if (ctx->r2 != 0) {
        // 0x800B1A30: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_800B1A34;
    }
    goto skip_0;
    // 0x800B1A30: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    skip_0:
L_800B1A34:
    // 0x800B1A34: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800B1A38: andi        $v0, $v1, 0xFF
    ctx->r2 = ctx->r3 & 0XFF;
    // 0x800B1A3C: sltiu       $v0, $v0, 0x9
    ctx->r2 = ctx->r2 < 0X9 ? 1 : 0;
    // 0x800B1A40: bne         $v0, $zero, L_800B1A28
    if (ctx->r2 != 0) {
        // 0x800B1A44: sllv        $v0, $a1, $v1
        ctx->r2 = S32(ctx->r5 << (ctx->r3 & 31));
            goto L_800B1A28;
    }
    // 0x800B1A44: sllv        $v0, $a1, $v1
    ctx->r2 = S32(ctx->r5 << (ctx->r3 & 31));
    // 0x800B1A48: jal         0x8005589C
    // 0x800B1A4C: addiu       $a0, $zero, 0x48
    ctx->r4 = ADD32(0, 0X48);
    getGameOrFrontText(rdram, ctx);
        goto after_1;
    // 0x800B1A4C: addiu       $a0, $zero, 0x48
    ctx->r4 = ADD32(0, 0X48);
    after_1:
    // 0x800B1A50: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x800B1A54: lw          $v1, 0xB4C($v1)
    ctx->r3 = MEM_W(ctx->r3, 0XB4C);
    // 0x800B1A58: andi        $v1, $v1, 0x200
    ctx->r3 = ctx->r3 & 0X200;
    // 0x800B1A5C: beq         $v1, $zero, L_800B1A74
    if (ctx->r3 == 0) {
        // 0x800B1A60: addu        $s5, $v0, $zero
        ctx->r21 = ADD32(ctx->r2, 0);
            goto L_800B1A74;
    }
    // 0x800B1A60: addu        $s5, $v0, $zero
    ctx->r21 = ADD32(ctx->r2, 0);
    // 0x800B1A64: jal         0x8005589C
    // 0x800B1A68: addiu       $a0, $zero, 0x4B
    ctx->r4 = ADD32(0, 0X4B);
    getGameOrFrontText(rdram, ctx);
        goto after_2;
    // 0x800B1A68: addiu       $a0, $zero, 0x4B
    ctx->r4 = ADD32(0, 0X4B);
    after_2:
    // 0x800B1A6C: j           L_800B1A7C
    // 0x800B1A70: addu        $s2, $v0, $zero
    ctx->r18 = ADD32(ctx->r2, 0);
        goto L_800B1A7C;
    // 0x800B1A70: addu        $s2, $v0, $zero
    ctx->r18 = ADD32(ctx->r2, 0);
L_800B1A74:
    // 0x800B1A74: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x800B1A78: addiu       $s2, $v0, 0x5BA4
    ctx->r18 = ADD32(ctx->r2, 0X5BA4);
L_800B1A7C:
    // 0x800B1A7C: jal         0x8005589C
    // 0x800B1A80: addiu       $a0, $zero, 0x4D
    ctx->r4 = ADD32(0, 0X4D);
    getGameOrFrontText(rdram, ctx);
        goto after_3;
    // 0x800B1A80: addiu       $a0, $zero, 0x4D
    ctx->r4 = ADD32(0, 0X4D);
    after_3:
    // 0x800B1A84: addiu       $a0, $zero, 0x4A
    ctx->r4 = ADD32(0, 0X4A);
    // 0x800B1A88: jal         0x8005589C
    // 0x800B1A8C: addu        $s4, $v0, $zero
    ctx->r20 = ADD32(ctx->r2, 0);
    getGameOrFrontText(rdram, ctx);
        goto after_4;
    // 0x800B1A8C: addu        $s4, $v0, $zero
    ctx->r20 = ADD32(ctx->r2, 0);
    after_4:
    // 0x800B1A90: addu        $s3, $v0, $zero
    ctx->r19 = ADD32(ctx->r2, 0);
    // 0x800B1A94: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800B1A98: lw          $v0, 0xB4C($v0)
    ctx->r2 = MEM_W(ctx->r2, 0XB4C);
    // 0x800B1A9C: lui         $v1, 0x1
    ctx->r3 = S32(0X1 << 16);
    // 0x800B1AA0: and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // 0x800B1AA4: beq         $v0, $zero, L_800B1ABC
    if (ctx->r2 == 0) {
        // 0x800B1AA8: lui         $v0, 0x800A
        ctx->r2 = S32(0X800A << 16);
            goto L_800B1ABC;
    }
    // 0x800B1AA8: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x800B1AAC: jal         0x8005589C
    // 0x800B1AB0: addiu       $a0, $zero, 0x4B
    ctx->r4 = ADD32(0, 0X4B);
    getGameOrFrontText(rdram, ctx);
        goto after_5;
    // 0x800B1AB0: addiu       $a0, $zero, 0x4B
    ctx->r4 = ADD32(0, 0X4B);
    after_5:
    // 0x800B1AB4: j           L_800B1AC0
    // 0x800B1AB8: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
        goto L_800B1AC0;
    // 0x800B1AB8: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
L_800B1ABC:
    // 0x800B1ABC: addiu       $s0, $v0, 0x5BA4
    ctx->r16 = ADD32(ctx->r2, 0X5BA4);
L_800B1AC0:
    // 0x800B1AC0: jal         0x8005589C
    // 0x800B1AC4: addiu       $a0, $zero, 0x4C
    ctx->r4 = ADD32(0, 0X4C);
    getGameOrFrontText(rdram, ctx);
        goto after_6;
    // 0x800B1AC4: addiu       $a0, $zero, 0x4C
    ctx->r4 = ADD32(0, 0X4C);
    after_6:
    // 0x800B1AC8: addiu       $a0, $sp, 0x20
    ctx->r4 = ADD32(ctx->r29, 0X20);
    // 0x800B1ACC: lui         $a1, 0x800A
    ctx->r5 = S32(0X800A << 16);
    // 0x800B1AD0: addiu       $a1, $a1, 0x5BA8
    ctx->r5 = ADD32(ctx->r5, 0X5BA8);
    // 0x800B1AD4: addu        $a2, $s5, $zero
    ctx->r6 = ADD32(ctx->r21, 0);
    // 0x800B1AD8: addu        $a3, $s2, $zero
    ctx->r7 = ADD32(ctx->r18, 0);
    // 0x800B1ADC: sw          $s4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r20;
    // 0x800B1AE0: sw          $s3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r19;
    // 0x800B1AE4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800B1AE8: jal         0x80033CC4
    // 0x800B1AEC: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    sprintf_recomp(rdram, ctx);
        goto after_7;
    // 0x800B1AEC: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_7:
    // 0x800B1AF0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800B1AF4: bne         $s1, $v0, L_800B1B00
    if (ctx->r17 != ctx->r2) {
        // 0x800B1AF8: ori         $v1, $zero, 0xFFD0
        ctx->r3 = 0 | 0XFFD0;
            goto L_800B1B00;
    }
    // 0x800B1AF8: ori         $v1, $zero, 0xFFD0
    ctx->r3 = 0 | 0XFFD0;
    // 0x800B1AFC: ori         $v1, $zero, 0xFFFD
    ctx->r3 = 0 | 0XFFFD;
L_800B1B00:
    // 0x800B1B00: sll         $v0, $v1, 16
    ctx->r2 = S32(ctx->r3 << 16);
    // 0x800B1B04: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x800B1B08: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x800B1B0C: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    // 0x800B1B10: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x800B1B14: addiu       $a3, $zero, -0x100
    ctx->r7 = ADD32(0, -0X100);
    // 0x800B1B18: jal         0x80063CFC
    // 0x800B1B1C: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    func_80063CFC(rdram, ctx);
        goto after_8;
    // 0x800B1B1C: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    after_8:
    // 0x800B1B20: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x800B1B24: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x800B1B28: lui         $a2, 0x800D
    ctx->r6 = S32(0X800D << 16);
    // 0x800B1B2C: jal         0x80063E54
    // 0x800B1B30: addiu       $a2, $a2, -0x390C
    ctx->r6 = ADD32(ctx->r6, -0X390C);
    func_80063E54(rdram, ctx);
        goto after_9;
    // 0x800B1B30: addiu       $a2, $a2, -0x390C
    ctx->r6 = ADD32(ctx->r6, -0X390C);
    after_9:
    // 0x800B1B34: lw          $ra, 0x138($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X138);
    // 0x800B1B38: lw          $s5, 0x134($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X134);
    // 0x800B1B3C: lw          $s4, 0x130($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X130);
    // 0x800B1B40: lw          $s3, 0x12C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X12C);
    // 0x800B1B44: lw          $s2, 0x128($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X128);
    // 0x800B1B48: lw          $s1, 0x124($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X124);
    // 0x800B1B4C: lw          $s0, 0x120($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X120);
    // 0x800B1B50: jr          $ra
    // 0x800B1B54: addiu       $sp, $sp, 0x140
    ctx->r29 = ADD32(ctx->r29, 0X140);
    return;
    // 0x800B1B54: addiu       $sp, $sp, 0x140
    ctx->r29 = ADD32(ctx->r29, 0X140);
;}
RECOMP_FUNC void func_800B1B58(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B1B58: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800B1B5C: sdc1        $f20, 0x28($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X28, ctx->r29);
    // 0x800B1B60: mov.s       $f20, $f12
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 12);
    ctx->f20.fl = ctx->f12.fl;
    // 0x800B1B64: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x800B1B68: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800B1B6C: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x800B1B70: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x800B1B74: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800B1B78: lw          $a0, -0x2054($v0)
    ctx->r4 = MEM_W(ctx->r2, -0X2054);
    // 0x800B1B7C: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x800B1B80: ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
    // 0x800B1B84: sh          $zero, 0x10($sp)
    MEM_H(0X10, ctx->r29) = 0;
    // 0x800B1B88: jal         0x80063070
    // 0x800B1B8C: sh          $v0, 0x12($sp)
    MEM_H(0X12, ctx->r29) = ctx->r2;
    func_80063070(rdram, ctx);
        goto after_0;
    // 0x800B1B8C: sh          $v0, 0x12($sp)
    MEM_H(0X12, ctx->r29) = ctx->r2;
    after_0:
    // 0x800B1B90: andi        $s0, $v0, 0xFF
    ctx->r16 = ctx->r2 & 0XFF;
    // 0x800B1B94: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x800B1B98: beq         $s0, $v0, L_800B1C40
    if (ctx->r16 == ctx->r2) {
        // 0x800B1B9C: slti        $v0, $s0, 0x3
        ctx->r2 = SIGNED(ctx->r16) < 0X3 ? 1 : 0;
            goto L_800B1C40;
    }
    // 0x800B1B9C: slti        $v0, $s0, 0x3
    ctx->r2 = SIGNED(ctx->r16) < 0X3 ? 1 : 0;
    // 0x800B1BA0: beq         $v0, $zero, L_800B1BB8
    if (ctx->r2 == 0) {
        // 0x800B1BA4: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_800B1BB8;
    }
    // 0x800B1BA4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800B1BA8: beq         $s0, $v0, L_800B1BD4
    if (ctx->r16 == ctx->r2) {
        // 0x800B1BAC: lui         $v0, 0x800D
        ctx->r2 = S32(0X800D << 16);
            goto L_800B1BD4;
    }
    // 0x800B1BAC: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x800B1BB0: j           L_800B1C98
    // 0x800B1BB4: nop

        goto L_800B1C98;
    // 0x800B1BB4: nop

L_800B1BB8:
    // 0x800B1BB8: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x800B1BBC: beq         $s0, $v0, L_800B1C5C
    if (ctx->r16 == ctx->r2) {
        // 0x800B1BC0: addiu       $v0, $zero, 0x4
        ctx->r2 = ADD32(0, 0X4);
            goto L_800B1C5C;
    }
    // 0x800B1BC0: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // 0x800B1BC4: beq         $s0, $v0, L_800B1C84
    if (ctx->r16 == ctx->r2) {
        // 0x800B1BC8: lui         $v0, 0x800D
        ctx->r2 = S32(0X800D << 16);
            goto L_800B1C84;
    }
    // 0x800B1BC8: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x800B1BCC: j           L_800B1C98
    // 0x800B1BD0: nop

        goto L_800B1C98;
    // 0x800B1BD0: nop

L_800B1BD4:
    // 0x800B1BD4: lui         $s1, 0x800D
    ctx->r17 = S32(0X800D << 16);
    // 0x800B1BD8: lw          $v0, -0x2050($s1)
    ctx->r2 = MEM_W(ctx->r17, -0X2050);
    // 0x800B1BDC: bne         $v0, $zero, L_800B1C28
    if (ctx->r2 != 0) {
        // 0x800B1BE0: addiu       $a0, $zero, 0x43
        ctx->r4 = ADD32(0, 0X43);
            goto L_800B1C28;
    }
    // 0x800B1BE0: addiu       $a0, $zero, 0x43
    ctx->r4 = ADD32(0, 0X43);
    // 0x800B1BE4: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    // 0x800B1BE8: addiu       $a2, $zero, 0x6E
    ctx->r6 = ADD32(0, 0X6E);
    // 0x800B1BEC: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x800B1BF0: lbu         $v0, -0x253F($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X253F);
    // 0x800B1BF4: lui         $a1, 0x3F33
    ctx->r5 = S32(0X3F33 << 16);
    // 0x800B1BF8: ori         $a1, $a1, 0x3333
    ctx->r5 = ctx->r5 | 0X3333;
    // 0x800B1BFC: addiu       $v0, $v0, 0x279
    ctx->r2 = ADD32(ctx->r2, 0X279);
    // 0x800B1C00: jal         0x800CBF60
    // 0x800B1C04: sh          $v0, 0x10($sp)
    MEM_H(0X10, ctx->r29) = ctx->r2;
    func_800CBF60(rdram, ctx);
        goto after_1;
    // 0x800B1C04: sh          $v0, 0x10($sp)
    MEM_H(0X10, ctx->r29) = ctx->r2;
    after_1:
    // 0x800B1C08: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800B1C0C: lwc1        $f0, 0x5BB8($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X5BB8);
    // 0x800B1C10: sw          $v0, -0x2050($s1)
    MEM_W(-0X2050, ctx->r17) = ctx->r2;
    // 0x800B1C14: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x800B1C18: sb          $s0, -0x2541($v0)
    MEM_B(-0X2541, ctx->r2) = ctx->r16;
    // 0x800B1C1C: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x800B1C20: swc1        $f0, -0x24F4($v0)
    MEM_W(-0X24F4, ctx->r2) = ctx->f0.u32l;
    // 0x800B1C24: addiu       $a0, $zero, 0x43
    ctx->r4 = ADD32(0, 0X43);
L_800B1C28:
    // 0x800B1C28: addiu       $a1, $zero, 0x32
    ctx->r5 = ADD32(0, 0X32);
    // 0x800B1C2C: jal         0x80087EE8
    // 0x800B1C30: addiu       $a2, $zero, 0x40
    ctx->r6 = ADD32(0, 0X40);
    func_80087EE8(rdram, ctx);
        goto after_2;
    // 0x800B1C30: addiu       $a2, $zero, 0x40
    ctx->r6 = ADD32(0, 0X40);
    after_2:
    // 0x800B1C34: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x800B1C38: j           L_800B1C94
    // 0x800B1C3C: sw          $v0, -0x3900($v1)
    MEM_W(-0X3900, ctx->r3) = ctx->r2;
        goto L_800B1C94;
    // 0x800B1C3C: sw          $v0, -0x3900($v1)
    MEM_W(-0X3900, ctx->r3) = ctx->r2;
L_800B1C40:
    // 0x800B1C40: lui         $s0, 0x800D
    ctx->r16 = S32(0X800D << 16);
    // 0x800B1C44: lw          $a0, -0x3900($s0)
    ctx->r4 = MEM_W(ctx->r16, -0X3900);
    // 0x800B1C48: jal         0x800894F0
    // 0x800B1C4C: nop

    func_800894F0(rdram, ctx);
        goto after_3;
    // 0x800B1C4C: nop

    after_3:
    // 0x800B1C50: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x800B1C54: j           L_800B1C94
    // 0x800B1C58: sw          $v0, -0x3900($s0)
    MEM_W(-0X3900, ctx->r16) = ctx->r2;
        goto L_800B1C94;
    // 0x800B1C58: sw          $v0, -0x3900($s0)
    MEM_W(-0X3900, ctx->r16) = ctx->r2;
L_800B1C5C:
    // 0x800B1C5C: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x800B1C60: lw          $a0, -0x2050($v0)
    ctx->r4 = MEM_W(ctx->r2, -0X2050);
    // 0x800B1C64: beq         $a0, $zero, L_800B1C78
    if (ctx->r4 == 0) {
        // 0x800B1C68: lui         $v0, 0x800D
        ctx->r2 = S32(0X800D << 16);
            goto L_800B1C78;
    }
    // 0x800B1C68: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x800B1C6C: jal         0x800CC02C
    // 0x800B1C70: nop

    func_800CC02C(rdram, ctx);
        goto after_4;
    // 0x800B1C70: nop

    after_4:
    // 0x800B1C74: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
L_800B1C78:
    // 0x800B1C78: lw          $a0, -0x3900($v0)
    ctx->r4 = MEM_W(ctx->r2, -0X3900);
    // 0x800B1C7C: jal         0x800894F0
    // 0x800B1C80: nop

    func_800894F0(rdram, ctx);
        goto after_5;
    // 0x800B1C80: nop

    after_5:
L_800B1C84:
    // 0x800B1C84: addiu       $a0, $zero, 0x42
    ctx->r4 = ADD32(0, 0X42);
    // 0x800B1C88: addiu       $a1, $zero, 0x55
    ctx->r5 = ADD32(0, 0X55);
    // 0x800B1C8C: jal         0x80087EE8
    // 0x800B1C90: addiu       $a2, $zero, 0x40
    ctx->r6 = ADD32(0, 0X40);
    func_80087EE8(rdram, ctx);
        goto after_6;
    // 0x800B1C90: addiu       $a2, $zero, 0x40
    ctx->r6 = ADD32(0, 0X40);
    after_6:
L_800B1C94:
    // 0x800B1C94: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
L_800B1C98:
    // 0x800B1C98: lbu         $v0, -0x253B($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X253B);
    // 0x800B1C9C: bne         $v0, $zero, L_800B1D38
    if (ctx->r2 != 0) {
        // 0x800B1CA0: lui         $s0, 0x800D
        ctx->r16 = S32(0X800D << 16);
            goto L_800B1D38;
    }
    // 0x800B1CA0: lui         $s0, 0x800D
    ctx->r16 = S32(0X800D << 16);
    // 0x800B1CA4: lwc1        $f0, -0x24F4($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, -0X24F4);
    // 0x800B1CA8: sub.s       $f12, $f0, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f12.fl = ctx->f0.fl - ctx->f20.fl;
    // 0x800B1CAC: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800B1CB0: lwc1        $f0, 0x5BBC($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X5BBC);
    // 0x800B1CB4: c.lt.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl < ctx->f12.fl;
    // 0x800B1CB8: nop

    // 0x800B1CBC: bc1f        L_800B1D38
    if (!c1cs) {
        // 0x800B1CC0: swc1        $f12, -0x24F4($s0)
        MEM_W(-0X24F4, ctx->r16) = ctx->f12.u32l;
            goto L_800B1D38;
    }
    // 0x800B1CC0: swc1        $f12, -0x24F4($s0)
    MEM_W(-0X24F4, ctx->r16) = ctx->f12.u32l;
    // 0x800B1CC4: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800B1CC8: c.lt.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl < ctx->f0.fl;
    // 0x800B1CCC: nop

    // 0x800B1CD0: bc1f        L_800B1D38
    if (!c1cs) {
        // 0x800B1CD4: lui         $s2, 0x800D
        ctx->r18 = S32(0X800D << 16);
            goto L_800B1D38;
    }
    // 0x800B1CD4: lui         $s2, 0x800D
    ctx->r18 = S32(0X800D << 16);
    // 0x800B1CD8: lbu         $v0, -0x2541($s2)
    ctx->r2 = MEM_BU(ctx->r18, -0X2541);
    // 0x800B1CDC: bne         $v0, $zero, L_800B1D38
    if (ctx->r2 != 0) {
        // 0x800B1CE0: lui         $s1, 0x800D
        ctx->r17 = S32(0X800D << 16);
            goto L_800B1D38;
    }
    // 0x800B1CE0: lui         $s1, 0x800D
    ctx->r17 = S32(0X800D << 16);
    // 0x800B1CE4: lw          $v0, -0x2050($s1)
    ctx->r2 = MEM_W(ctx->r17, -0X2050);
    // 0x800B1CE8: bne         $v0, $zero, L_800B1D38
    if (ctx->r2 != 0) {
        // 0x800B1CEC: lui         $v0, 0x800D
        ctx->r2 = S32(0X800D << 16);
            goto L_800B1D38;
    }
    // 0x800B1CEC: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x800B1CF0: lbu         $v1, -0x253C($v0)
    ctx->r3 = MEM_BU(ctx->r2, -0X253C);
    // 0x800B1CF4: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // 0x800B1CF8: beq         $v1, $v0, L_800B1D38
    if (ctx->r3 == ctx->r2) {
        // 0x800B1CFC: addiu       $a0, $sp, 0x10
        ctx->r4 = ADD32(ctx->r29, 0X10);
            goto L_800B1D38;
    }
    // 0x800B1CFC: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    // 0x800B1D00: addiu       $a2, $zero, 0x6E
    ctx->r6 = ADD32(0, 0X6E);
    // 0x800B1D04: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x800B1D08: lbu         $v0, -0x253F($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X253F);
    // 0x800B1D0C: lui         $a1, 0x3F33
    ctx->r5 = S32(0X3F33 << 16);
    // 0x800B1D10: ori         $a1, $a1, 0x3333
    ctx->r5 = ctx->r5 | 0X3333;
    // 0x800B1D14: addiu       $v0, $v0, 0x279
    ctx->r2 = ADD32(ctx->r2, 0X279);
    // 0x800B1D18: jal         0x800CBF60
    // 0x800B1D1C: sh          $v0, 0x10($sp)
    MEM_H(0X10, ctx->r29) = ctx->r2;
    func_800CBF60(rdram, ctx);
        goto after_7;
    // 0x800B1D1C: sh          $v0, 0x10($sp)
    MEM_H(0X10, ctx->r29) = ctx->r2;
    after_7:
    // 0x800B1D20: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800B1D24: lwc1        $f0, 0x5BC0($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X5BC0);
    // 0x800B1D28: sw          $v0, -0x2050($s1)
    MEM_W(-0X2050, ctx->r17) = ctx->r2;
    // 0x800B1D2C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800B1D30: sb          $v0, -0x2541($s2)
    MEM_B(-0X2541, ctx->r18) = ctx->r2;
    // 0x800B1D34: swc1        $f0, -0x24F4($s0)
    MEM_W(-0X24F4, ctx->r16) = ctx->f0.u32l;
L_800B1D38:
    // 0x800B1D38: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800B1D3C: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x800B1D40: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x800B1D44: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800B1D48: ldc1        $f20, 0x28($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X28);
    // 0x800B1D4C: jr          $ra
    // 0x800B1D50: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x800B1D50: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_800B1BE8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B1BE8: addiu       $sp, $sp, -0x1D8
    ctx->r29 = ADD32(ctx->r29, -0X1D8);
    // 0x800B1BEC: sw          $s3, 0x18C($sp)
    MEM_W(0X18C, ctx->r29) = ctx->r19;
    // 0x800B1BF0: addu        $s3, $a0, $zero
    ctx->r19 = ADD32(ctx->r4, 0);
    // 0x800B1BF4: sw          $fp, 0x1A0($sp)
    MEM_W(0X1A0, ctx->r29) = ctx->r30;
    // 0x800B1BF8: addu        $fp, $zero, $zero
    ctx->r30 = ADD32(0, 0);
    // 0x800B1BFC: sw          $s6, 0x198($sp)
    MEM_W(0X198, ctx->r29) = ctx->r22;
    // 0x800B1C00: addiu       $s6, $s3, 0x4
    ctx->r22 = ADD32(ctx->r19, 0X4);
    // 0x800B1C04: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800B1C08: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x800B1C0C: lw          $v1, -0x35E0($v0)
    ctx->r3 = MEM_W(ctx->r2, -0X35E0);
    // 0x800B1C10: addiu       $v0, $zero, 0x7
    ctx->r2 = ADD32(0, 0X7);
    // 0x800B1C14: sw          $ra, 0x1A4($sp)
    MEM_W(0X1A4, ctx->r29) = ctx->r31;
    // 0x800B1C18: sw          $s7, 0x19C($sp)
    MEM_W(0X19C, ctx->r29) = ctx->r23;
    // 0x800B1C1C: sw          $s5, 0x194($sp)
    MEM_W(0X194, ctx->r29) = ctx->r21;
    // 0x800B1C20: sw          $s4, 0x190($sp)
    MEM_W(0X190, ctx->r29) = ctx->r20;
    // 0x800B1C24: sw          $s2, 0x188($sp)
    MEM_W(0X188, ctx->r29) = ctx->r18;
    // 0x800B1C28: sw          $s1, 0x184($sp)
    MEM_W(0X184, ctx->r29) = ctx->r17;
    // 0x800B1C2C: sw          $s0, 0x180($sp)
    MEM_W(0X180, ctx->r29) = ctx->r16;
    // 0x800B1C30: sdc1        $f30, 0x1D0($sp)
    CHECK_FR(ctx, 30);
    SD(ctx->f30.u64, 0X1D0, ctx->r29);
    // 0x800B1C34: sdc1        $f28, 0x1C8($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0X1C8, ctx->r29);
    // 0x800B1C38: sdc1        $f26, 0x1C0($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X1C0, ctx->r29);
    // 0x800B1C3C: sdc1        $f24, 0x1B8($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X1B8, ctx->r29);
    // 0x800B1C40: sdc1        $f22, 0x1B0($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X1B0, ctx->r29);
    // 0x800B1C44: sdc1        $f20, 0x1A8($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X1A8, ctx->r29);
    // 0x800B1C48: sw          $a1, 0x1DC($sp)
    MEM_W(0X1DC, ctx->r29) = ctx->r5;
    // 0x800B1C4C: sb          $zero, 0x174($sp)
    MEM_B(0X174, ctx->r29) = 0;
    // 0x800B1C50: beq         $v1, $v0, L_800B36B4
    if (ctx->r3 == ctx->r2) {
        // 0x800B1C54: mov.s       $f30, $f6
        CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 6);
    ctx->f30.fl = ctx->f6.fl;
            goto L_800B36B4;
    }
    // 0x800B1C54: mov.s       $f30, $f6
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 6);
    ctx->f30.fl = ctx->f6.fl;
    // 0x800B1C58: lwc1        $f2, 0xC8($s3)
    ctx->f2.u32l = MEM_W(ctx->r19, 0XC8);
    // 0x800B1C5C: c.lt.s      $f6, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f6.fl < ctx->f2.fl;
    // 0x800B1C60: nop

    // 0x800B1C64: bc1f        L_800B1CA4
    if (!c1cs) {
        // 0x800B1C68: lui         $v0, 0x8011
        ctx->r2 = S32(0X8011 << 16);
            goto L_800B1CA4;
    }
    // 0x800B1C68: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800B1C6C: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800B1C70: lwc1        $f0, 0x56D4($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X56D4);
    // 0x800B1C74: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x800B1C78: nop

    // 0x800B1C7C: bc1f        L_800B1CA4
    if (!c1cs) {
        // 0x800B1C80: nop
    
            goto L_800B1CA4;
    }
    // 0x800B1C80: nop

    // 0x800B1C84: lwc1        $f10, 0x1DC($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X1DC);
    // 0x800B1C88: sub.s       $f0, $f2, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = ctx->f2.fl - ctx->f10.fl;
    // 0x800B1C8C: c.lt.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl < ctx->f6.fl;
    // 0x800B1C90: nop

    // 0x800B1C94: bc1f        L_800B1CA4
    if (!c1cs) {
        // 0x800B1C98: swc1        $f0, 0xC8($s3)
        MEM_W(0XC8, ctx->r19) = ctx->f0.u32l;
            goto L_800B1CA4;
    }
    // 0x800B1C98: swc1        $f0, 0xC8($s3)
    MEM_W(0XC8, ctx->r19) = ctx->f0.u32l;
    // 0x800B1C9C: swc1        $f6, 0xC8($s3)
    MEM_W(0XC8, ctx->r19) = ctx->f6.u32l;
    // 0x800B1CA0: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
L_800B1CA4:
    // 0x800B1CA4: lw          $v1, 0xB8($s3)
    ctx->r3 = MEM_W(ctx->r19, 0XB8);
    // 0x800B1CA8: addiu       $v0, $v0, -0x4228
    ctx->r2 = ADD32(ctx->r2, -0X4228);
    // 0x800B1CAC: sll         $v1, $v1, 3
    ctx->r3 = S32(ctx->r3 << 3);
    // 0x800B1CB0: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x800B1CB4: lwc1        $f2, 0x0($v1)
    ctx->f2.u32l = MEM_W(ctx->r3, 0X0);
    // 0x800B1CB8: abs.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = fabsf(ctx->f2.fl);
    // 0x800B1CBC: lwc1        $f4, 0x128($s3)
    ctx->f4.u32l = MEM_W(ctx->r19, 0X128);
    // 0x800B1CC0: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x800B1CC4: nop

    // 0x800B1CC8: bc1f        L_800B1CEC
    if (!c1cs) {
        // 0x800B1CCC: nop
    
            goto L_800B1CEC;
    }
    // 0x800B1CCC: nop

    // 0x800B1CD0: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800B1CD4: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x800B1CD8: nop

    // 0x800B1CDC: bc1fl       L_800B1CF0
    if (!c1cs) {
        // 0x800B1CE0: add.s       $f28, $f2, $f4
        CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f28.fl = ctx->f2.fl + ctx->f4.fl;
            goto L_800B1CF0;
    }
    goto skip_0;
    // 0x800B1CE0: add.s       $f28, $f2, $f4
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f28.fl = ctx->f2.fl + ctx->f4.fl;
    skip_0:
    // 0x800B1CE4: j           L_800B1CF0
    // 0x800B1CE8: sub.s       $f28, $f2, $f4
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f28.fl = ctx->f2.fl - ctx->f4.fl;
        goto L_800B1CF0;
    // 0x800B1CE8: sub.s       $f28, $f2, $f4
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f28.fl = ctx->f2.fl - ctx->f4.fl;
L_800B1CEC:
    // 0x800B1CEC: mtc1        $zero, $f28
    ctx->f28.u32l = 0;
L_800B1CF0:
    // 0x800B1CF0: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800B1CF4: lw          $v1, 0xB8($s3)
    ctx->r3 = MEM_W(ctx->r19, 0XB8);
    // 0x800B1CF8: addiu       $v0, $v0, -0x4228
    ctx->r2 = ADD32(ctx->r2, -0X4228);
    // 0x800B1CFC: sll         $v1, $v1, 3
    ctx->r3 = S32(ctx->r3 << 3);
    // 0x800B1D00: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x800B1D04: lwc1        $f2, 0x4($v1)
    ctx->f2.u32l = MEM_W(ctx->r3, 0X4);
    // 0x800B1D08: abs.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = fabsf(ctx->f2.fl);
    // 0x800B1D0C: lwc1        $f4, 0x12C($s3)
    ctx->f4.u32l = MEM_W(ctx->r19, 0X12C);
    // 0x800B1D10: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x800B1D14: nop

    // 0x800B1D18: bc1f        L_800B1D40
    if (!c1cs) {
        // 0x800B1D1C: nop
    
            goto L_800B1D40;
    }
    // 0x800B1D1C: nop

    // 0x800B1D20: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800B1D24: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x800B1D28: nop

    // 0x800B1D2C: bc1fl       L_800B1D44
    if (!c1cs) {
        // 0x800B1D30: add.s       $f26, $f2, $f4
        CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f26.fl = ctx->f2.fl + ctx->f4.fl;
            goto L_800B1D44;
    }
    goto skip_1;
    // 0x800B1D30: add.s       $f26, $f2, $f4
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f26.fl = ctx->f2.fl + ctx->f4.fl;
    skip_1:
    // 0x800B1D34: lwc1        $f0, 0x128($s3)
    ctx->f0.u32l = MEM_W(ctx->r19, 0X128);
    // 0x800B1D38: j           L_800B1D44
    // 0x800B1D3C: sub.s       $f26, $f2, $f0
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f26.fl = ctx->f2.fl - ctx->f0.fl;
        goto L_800B1D44;
    // 0x800B1D3C: sub.s       $f26, $f2, $f0
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f26.fl = ctx->f2.fl - ctx->f0.fl;
L_800B1D40:
    // 0x800B1D40: mtc1        $zero, $f26
    ctx->f26.u32l = 0;
L_800B1D44:
    // 0x800B1D44: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x800B1D48: lw          $v1, 0xB8($s3)
    ctx->r3 = MEM_W(ctx->r19, 0XB8);
    // 0x800B1D4C: addiu       $a0, $a0, -0x72E8
    ctx->r4 = ADD32(ctx->r4, -0X72E8);
    // 0x800B1D50: sll         $a1, $v1, 2
    ctx->r5 = S32(ctx->r3 << 2);
    // 0x800B1D54: addu        $v0, $a1, $v1
    ctx->r2 = ADD32(ctx->r5, ctx->r3);
    // 0x800B1D58: sll         $v0, $v0, 4
    ctx->r2 = S32(ctx->r2 << 4);
    // 0x800B1D5C: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800B1D60: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800B1D64: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x800B1D68: lw          $v0, 0x4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X4);
    // 0x800B1D6C: lhu         $v0, 0x4($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X4);
    // 0x800B1D70: addiu       $v0, $v0, -0x2
    ctx->r2 = ADD32(ctx->r2, -0X2);
    // 0x800B1D74: sltiu       $v0, $v0, 0x2
    ctx->r2 = ctx->r2 < 0X2 ? 1 : 0;
    // 0x800B1D78: beq         $v0, $zero, L_800B1D94
    if (ctx->r2 == 0) {
        // 0x800B1D7C: lui         $v0, 0x8013
        ctx->r2 = S32(0X8013 << 16);
            goto L_800B1D94;
    }
    // 0x800B1D7C: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800B1D80: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800B1D84: lwc1        $f0, 0x56D8($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X56D8);
    // 0x800B1D88: mul.s       $f28, $f28, $f0
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f28.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f28.fl = MUL_S(ctx->f28.fl, ctx->f0.fl);
    // 0x800B1D8C: nop

    // 0x800B1D90: mul.s       $f26, $f26, $f0
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f26.fl = MUL_S(ctx->f26.fl, ctx->f0.fl);
L_800B1D94:
    // 0x800B1D94: addiu       $v0, $v0, 0xB40
    ctx->r2 = ADD32(ctx->r2, 0XB40);
    // 0x800B1D98: addu        $v0, $a1, $v0
    ctx->r2 = ADD32(ctx->r5, ctx->r2);
    // 0x800B1D9C: lw          $v0, 0xC($v0)
    ctx->r2 = MEM_W(ctx->r2, 0XC);
    // 0x800B1DA0: andi        $v0, $v0, 0x40
    ctx->r2 = ctx->r2 & 0X40;
    // 0x800B1DA4: bne         $v0, $zero, L_800B1DD8
    if (ctx->r2 != 0) {
        // 0x800B1DA8: lui         $a0, 0x8011
        ctx->r4 = S32(0X8011 << 16);
            goto L_800B1DD8;
    }
    // 0x800B1DA8: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x800B1DAC: lhu         $v1, 0xB4($s3)
    ctx->r3 = MEM_HU(ctx->r19, 0XB4);
    // 0x800B1DB0: slti        $v0, $v1, 0x5
    ctx->r2 = SIGNED(ctx->r3) < 0X5 ? 1 : 0;
    // 0x800B1DB4: beq         $v0, $zero, L_800B1DC4
    if (ctx->r2 == 0) {
        // 0x800B1DB8: slti        $v0, $v1, 0x3
        ctx->r2 = SIGNED(ctx->r3) < 0X3 ? 1 : 0;
            goto L_800B1DC4;
    }
    // 0x800B1DB8: slti        $v0, $v1, 0x3
    ctx->r2 = SIGNED(ctx->r3) < 0X3 ? 1 : 0;
    // 0x800B1DBC: beq         $v0, $zero, L_800B1DD8
    if (ctx->r2 == 0) {
        // 0x800B1DC0: nop
    
            goto L_800B1DD8;
    }
    // 0x800B1DC0: nop

L_800B1DC4:
    // 0x800B1DC4: abs.s       $f0, $f28
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f28.fl); 
    ctx->f0.fl = fabsf(ctx->f28.fl);
    // 0x800B1DC8: mul.s       $f28, $f28, $f0
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f28.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f28.fl = MUL_S(ctx->f28.fl, ctx->f0.fl);
    // 0x800B1DCC: abs.s       $f0, $f26
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f26.fl); 
    ctx->f0.fl = fabsf(ctx->f26.fl);
    // 0x800B1DD0: mul.s       $f26, $f26, $f0
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f26.fl = MUL_S(ctx->f26.fl, ctx->f0.fl);
    // 0x800B1DD4: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
L_800B1DD8:
    // 0x800B1DD8: lwc1        $f0, -0x6950($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, -0X6950);
    // 0x800B1DDC: lw          $v0, 0xB8($s3)
    ctx->r2 = MEM_W(ctx->r19, 0XB8);
    // 0x800B1DE0: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x800B1DE4: sll         $v1, $v0, 2
    ctx->r3 = S32(ctx->r2 << 2);
    // 0x800B1DE8: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x800B1DEC: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x800B1DF0: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x800B1DF4: sll         $v1, $v1, 5
    ctx->r3 = S32(ctx->r3 << 5);
    // 0x800B1DF8: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x800B1DFC: addiu       $a1, $v0, -0x7FF4
    ctx->r5 = ADD32(ctx->r2, -0X7FF4);
    // 0x800B1E00: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x800B1E04: nop

    // 0x800B1E08: bc1f        L_800B1E1C
    if (!c1cs) {
        // 0x800B1E0C: addu        $s4, $v1, $a1
        ctx->r20 = ADD32(ctx->r3, ctx->r5);
            goto L_800B1E1C;
    }
    // 0x800B1E0C: addu        $s4, $v1, $a1
    ctx->r20 = ADD32(ctx->r3, ctx->r5);
    // 0x800B1E10: lwc1        $f10, 0x1DC($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X1DC);
    // 0x800B1E14: sub.s       $f0, $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f10.fl;
    // 0x800B1E18: swc1        $f0, -0x6950($a0)
    MEM_W(-0X6950, ctx->r4) = ctx->f0.u32l;
L_800B1E1C:
    // 0x800B1E1C: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x800B1E20: lbu         $v0, -0x77C8($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X77C8);
    // 0x800B1E24: beq         $v0, $zero, L_800B1E60
    if (ctx->r2 == 0) {
        // 0x800B1E28: lui         $a0, 0x8014
        ctx->r4 = S32(0X8014 << 16);
            goto L_800B1E60;
    }
    // 0x800B1E28: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x800B1E2C: lw          $v1, 0xB8($s3)
    ctx->r3 = MEM_W(ctx->r19, 0XB8);
    // 0x800B1E30: addiu       $a0, $a0, -0x72E8
    ctx->r4 = ADD32(ctx->r4, -0X72E8);
    // 0x800B1E34: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x800B1E38: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800B1E3C: sll         $v0, $v0, 4
    ctx->r2 = S32(ctx->r2 << 4);
    // 0x800B1E40: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800B1E44: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800B1E48: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x800B1E4C: lw          $v0, 0x4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X4);
    // 0x800B1E50: lhu         $v0, 0x0($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X0);
    // 0x800B1E54: andi        $v0, $v0, 0x80
    ctx->r2 = ctx->r2 & 0X80;
    // 0x800B1E58: bne         $v0, $zero, L_800B36B4
    if (ctx->r2 != 0) {
        // 0x800B1E5C: nop
    
            goto L_800B36B4;
    }
    // 0x800B1E5C: nop

L_800B1E60:
    // 0x800B1E60: lw          $v0, 0xB8($s3)
    ctx->r2 = MEM_W(ctx->r19, 0XB8);
    // 0x800B1E64: sll         $v1, $v0, 2
    ctx->r3 = S32(ctx->r2 << 2);
    // 0x800B1E68: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x800B1E6C: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x800B1E70: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x800B1E74: sll         $v1, $v1, 5
    ctx->r3 = S32(ctx->r3 << 5);
    // 0x800B1E78: addu        $v1, $a1, $v1
    ctx->r3 = ADD32(ctx->r5, ctx->r3);
    // 0x800B1E7C: lhu         $v1, -0xD0($v1)
    ctx->r3 = MEM_HU(ctx->r3, -0XD0);
    // 0x800B1E80: andi        $v0, $v1, 0x8
    ctx->r2 = ctx->r3 & 0X8;
    // 0x800B1E84: beq         $v0, $zero, L_800B1EA0
    if (ctx->r2 == 0) {
        // 0x800B1E88: andi        $v0, $v1, 0x10
        ctx->r2 = ctx->r3 & 0X10;
            goto L_800B1EA0;
    }
    // 0x800B1E88: andi        $v0, $v1, 0x10
    ctx->r2 = ctx->r3 & 0X10;
    // 0x800B1E8C: lw          $a1, 0x1DC($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1DC);
    // 0x800B1E90: jal         0x800B0A88
    // 0x800B1E94: addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    func_800B0A88(rdram, ctx);
        goto after_0;
    // 0x800B1E94: addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    after_0:
    // 0x800B1E98: j           L_800B36B4
    // 0x800B1E9C: nop

        goto L_800B36B4;
    // 0x800B1E9C: nop

L_800B1EA0:
    // 0x800B1EA0: beq         $v0, $zero, L_800B1EBC
    if (ctx->r2 == 0) {
        // 0x800B1EA4: andi        $v0, $v1, 0x20
        ctx->r2 = ctx->r3 & 0X20;
            goto L_800B1EBC;
    }
    // 0x800B1EA4: andi        $v0, $v1, 0x20
    ctx->r2 = ctx->r3 & 0X20;
    // 0x800B1EA8: lw          $a1, 0x1DC($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1DC);
    // 0x800B1EAC: jal         0x800B1024
    // 0x800B1EB0: addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    func_800B1024(rdram, ctx);
        goto after_1;
    // 0x800B1EB0: addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    after_1:
    // 0x800B1EB4: j           L_800B36B4
    // 0x800B1EB8: nop

        goto L_800B36B4;
    // 0x800B1EB8: nop

L_800B1EBC:
    // 0x800B1EBC: bne         $v0, $zero, L_800B36B4
    if (ctx->r2 != 0) {
        // 0x800B1EC0: andi        $v0, $v1, 0x40
        ctx->r2 = ctx->r3 & 0X40;
            goto L_800B36B4;
    }
    // 0x800B1EC0: andi        $v0, $v1, 0x40
    ctx->r2 = ctx->r3 & 0X40;
    // 0x800B1EC4: beq         $v0, $zero, L_800B1EF0
    if (ctx->r2 == 0) {
        // 0x800B1EC8: nop
    
            goto L_800B1EF0;
    }
    // 0x800B1EC8: nop

    // 0x800B1ECC: lwc1        $f0, 0x184($s3)
    ctx->f0.u32l = MEM_W(ctx->r19, 0X184);
    // 0x800B1ED0: lwc1        $f10, 0x1DC($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X1DC);
    // 0x800B1ED4: sub.s       $f0, $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f10.fl;
    // 0x800B1ED8: c.le.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl <= ctx->f2.fl;
    // 0x800B1EDC: nop

    // 0x800B1EE0: bc1f        L_800B1EF0
    if (!c1cs) {
        // 0x800B1EE4: swc1        $f0, 0x184($s3)
        MEM_W(0X184, ctx->r19) = ctx->f0.u32l;
            goto L_800B1EF0;
    }
    // 0x800B1EE4: swc1        $f0, 0x184($s3)
    MEM_W(0X184, ctx->r19) = ctx->f0.u32l;
    // 0x800B1EE8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800B1EEC: sh          $v0, 0x180($s3)
    MEM_H(0X180, ctx->r19) = ctx->r2;
L_800B1EF0:
    // 0x800B1EF0: lwc1        $f2, 0xC0($s3)
    ctx->f2.u32l = MEM_W(ctx->r19, 0XC0);
    // 0x800B1EF4: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800B1EF8: c.le.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl <= ctx->f0.fl;
    // 0x800B1EFC: nop

    // 0x800B1F00: bc1t        L_800B1FA8
    if (c1cs) {
        // 0x800B1F04: lui         $v0, 0x8013
        ctx->r2 = S32(0X8013 << 16);
            goto L_800B1FA8;
    }
    // 0x800B1F04: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800B1F08: lw          $v1, 0x7CE4($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X7CE4);
    // 0x800B1F0C: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x800B1F10: beq         $v1, $v0, L_800B1FA8
    if (ctx->r3 == ctx->r2) {
        // 0x800B1F14: nop
    
            goto L_800B1FA8;
    }
    // 0x800B1F14: nop

    // 0x800B1F18: lwc1        $f0, 0xC4($s3)
    ctx->f0.u32l = MEM_W(ctx->r19, 0XC4);
    // 0x800B1F1C: c.eq.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl == ctx->f0.fl;
    // 0x800B1F20: nop

    // 0x800B1F24: bc1t        L_800B1FA8
    if (c1cs) {
        // 0x800B1F28: lui         $v0, 0x8011
        ctx->r2 = S32(0X8011 << 16);
            goto L_800B1FA8;
    }
    // 0x800B1F28: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800B1F2C: lbu         $v0, -0x6948($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X6948);
    // 0x800B1F30: beq         $v0, $zero, L_800B1FA8
    if (ctx->r2 == 0) {
        // 0x800B1F34: addiu       $v0, $zero, 0x5
        ctx->r2 = ADD32(0, 0X5);
            goto L_800B1FA8;
    }
    // 0x800B1F34: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
    // 0x800B1F38: lhu         $v1, 0xB4($s3)
    ctx->r3 = MEM_HU(ctx->r19, 0XB4);
    // 0x800B1F3C: beq         $v1, $v0, L_800B1F74
    if (ctx->r3 == ctx->r2) {
        // 0x800B1F40: slti        $v0, $v1, 0x6
        ctx->r2 = SIGNED(ctx->r3) < 0X6 ? 1 : 0;
            goto L_800B1F74;
    }
    // 0x800B1F40: slti        $v0, $v1, 0x6
    ctx->r2 = SIGNED(ctx->r3) < 0X6 ? 1 : 0;
    // 0x800B1F44: beq         $v0, $zero, L_800B1F64
    if (ctx->r2 == 0) {
        // 0x800B1F48: slti        $v0, $v1, 0x2
        ctx->r2 = SIGNED(ctx->r3) < 0X2 ? 1 : 0;
            goto L_800B1F64;
    }
    // 0x800B1F48: slti        $v0, $v1, 0x2
    ctx->r2 = SIGNED(ctx->r3) < 0X2 ? 1 : 0;
    // 0x800B1F4C: beq         $v0, $zero, L_800B1FA8
    if (ctx->r2 == 0) {
        // 0x800B1F50: nop
    
            goto L_800B1FA8;
    }
    // 0x800B1F50: nop

    // 0x800B1F54: bltz        $v1, L_800B1FA8
    if (SIGNED(ctx->r3) < 0) {
        // 0x800B1F58: nop
    
            goto L_800B1FA8;
    }
    // 0x800B1F58: nop

    // 0x800B1F5C: j           L_800B1F70
    // 0x800B1F60: nop

        goto L_800B1F70;
    // 0x800B1F60: nop

L_800B1F64:
    // 0x800B1F64: addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
    // 0x800B1F68: bne         $v1, $v0, L_800B1FA8
    if (ctx->r3 != ctx->r2) {
        // 0x800B1F6C: nop
    
            goto L_800B1FA8;
    }
    // 0x800B1F6C: nop

L_800B1F70:
    // 0x800B1F70: lwc1        $f0, 0xC4($s3)
    ctx->f0.u32l = MEM_W(ctx->r19, 0XC4);
L_800B1F74:
    // 0x800B1F74: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800B1F78: lwc1        $f2, 0x56DC($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X56DC);
    // 0x800B1F7C: lwc1        $f10, 0x1DC($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X1DC);
    // 0x800B1F80: div.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f2.fl);
    // 0x800B1F84: mul.s       $f0, $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x800B1F88: lwc1        $f2, 0xC0($s3)
    ctx->f2.u32l = MEM_W(ctx->r19, 0XC0);
    // 0x800B1F8C: add.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x800B1F90: lwc1        $f0, 0xC4($s3)
    ctx->f0.u32l = MEM_W(ctx->r19, 0XC4);
    // 0x800B1F94: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x800B1F98: nop

    // 0x800B1F9C: bc1f        L_800B1FA8
    if (!c1cs) {
        // 0x800B1FA0: swc1        $f2, 0xC0($s3)
        MEM_W(0XC0, ctx->r19) = ctx->f2.u32l;
            goto L_800B1FA8;
    }
    // 0x800B1FA0: swc1        $f2, 0xC0($s3)
    MEM_W(0XC0, ctx->r19) = ctx->f2.u32l;
    // 0x800B1FA4: swc1        $f0, 0xC0($s3)
    MEM_W(0XC0, ctx->r19) = ctx->f0.u32l;
L_800B1FA8:
    // 0x800B1FA8: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x800B1FAC: lwc1        $f4, 0xCC($s3)
    ctx->f4.u32l = MEM_W(ctx->r19, 0XCC);
    // 0x800B1FB0: lwc1        $f6, 0xD0($s3)
    ctx->f6.u32l = MEM_W(ctx->r19, 0XD0);
    // 0x800B1FB4: lwc1        $f8, 0xD4($s3)
    ctx->f8.u32l = MEM_W(ctx->r19, 0XD4);
    // 0x800B1FB8: lwc1        $f0, 0x0($s4)
    ctx->f0.u32l = MEM_W(ctx->r20, 0X0);
    // 0x800B1FBC: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    // 0x800B1FC0: swc1        $f0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f0.u32l;
    // 0x800B1FC4: lwc1        $f0, 0xC($s4)
    ctx->f0.u32l = MEM_W(ctx->r20, 0XC);
    // 0x800B1FC8: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    // 0x800B1FCC: swc1        $f0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f0.u32l;
    // 0x800B1FD0: lwc1        $f2, 0x18($s4)
    ctx->f2.u32l = MEM_W(ctx->r20, 0X18);
    // 0x800B1FD4: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800B1FD8: lwc1        $f0, 0x56E0($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X56E0);
    // 0x800B1FDC: mov.s       $f22, $f20
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 20);
    ctx->f22.fl = ctx->f20.fl;
    // 0x800B1FE0: swc1        $f20, 0x178($sp)
    MEM_W(0X178, ctx->r29) = ctx->f20.u32l;
    // 0x800B1FE4: swc1        $f4, 0x16C($sp)
    MEM_W(0X16C, ctx->r29) = ctx->f4.u32l;
    // 0x800B1FE8: swc1        $f6, 0x168($sp)
    MEM_W(0X168, ctx->r29) = ctx->f6.u32l;
    // 0x800B1FEC: swc1        $f8, 0x170($sp)
    MEM_W(0X170, ctx->r29) = ctx->f8.u32l;
    // 0x800B1FF0: swc1        $f20, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f20.u32l;
    // 0x800B1FF4: swc1        $f20, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f20.u32l;
    // 0x800B1FF8: swc1        $f0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f0.u32l;
    // 0x800B1FFC: jal         0x8001CFE8
    // 0x800B2000: swc1        $f2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f2.u32l;
    func_8001CFE8(rdram, ctx);
        goto after_2;
    // 0x800B2000: swc1        $f2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f2.u32l;
    after_2:
    // 0x800B2004: c.lt.s      $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f20.fl < ctx->f0.fl;
    // 0x800B2008: nop

    // 0x800B200C: bc1tl       L_800B2014
    if (c1cs) {
        // 0x800B2010: addiu       $fp, $zero, 0x1
        ctx->r30 = ADD32(0, 0X1);
            goto L_800B2014;
    }
    goto skip_2;
    // 0x800B2010: addiu       $fp, $zero, 0x1
    ctx->r30 = ADD32(0, 0X1);
    skip_2:
L_800B2014:
    // 0x800B2014: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x800B2018: addiu       $v1, $v1, 0xB40
    ctx->r3 = ADD32(ctx->r3, 0XB40);
    // 0x800B201C: lw          $a1, 0xB8($s3)
    ctx->r5 = MEM_W(ctx->r19, 0XB8);
    // 0x800B2020: lwc1        $f0, 0xF8($s3)
    ctx->f0.u32l = MEM_W(ctx->r19, 0XF8);
    // 0x800B2024: sll         $v0, $a1, 2
    ctx->r2 = S32(ctx->r5 << 2);
    // 0x800B2028: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800B202C: lui         $v1, 0x100
    ctx->r3 = S32(0X100 << 16);
    // 0x800B2030: lw          $v0, 0xC($v0)
    ctx->r2 = MEM_W(ctx->r2, 0XC);
    // 0x800B2034: mul.s       $f4, $f28, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f28.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f28.fl, ctx->f0.fl);
    // 0x800B2038: and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // 0x800B203C: beq         $v0, $zero, L_800B20BC
    if (ctx->r2 == 0) {
        // 0x800B2040: lui         $v0, 0x8013
        ctx->r2 = S32(0X8013 << 16);
            goto L_800B20BC;
    }
    // 0x800B2040: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800B2044: addiu       $v0, $v0, 0xB88
    ctx->r2 = ADD32(ctx->r2, 0XB88);
    // 0x800B2048: sll         $v1, $a1, 1
    ctx->r3 = S32(ctx->r5 << 1);
    // 0x800B204C: addu        $v1, $v1, $a1
    ctx->r3 = ADD32(ctx->r3, ctx->r5);
    // 0x800B2050: sll         $v1, $v1, 1
    ctx->r3 = S32(ctx->r3 << 1);
    // 0x800B2054: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x800B2058: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x800B205C: addiu       $a0, $a0, -0x41E8
    ctx->r4 = ADD32(ctx->r4, -0X41E8);
    // 0x800B2060: sll         $v0, $a1, 3
    ctx->r2 = S32(ctx->r5 << 3);
    // 0x800B2064: addu        $v0, $v0, $a1
    ctx->r2 = ADD32(ctx->r2, ctx->r5);
    // 0x800B2068: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800B206C: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x800B2070: lhu         $v1, 0x0($v1)
    ctx->r3 = MEM_HU(ctx->r3, 0X0);
    // 0x800B2074: lhu         $v0, 0x20($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X20);
    // 0x800B2078: and         $v1, $v1, $v0
    ctx->r3 = ctx->r3 & ctx->r2;
    // 0x800B207C: beq         $v1, $zero, L_800B20BC
    if (ctx->r3 == 0) {
        // 0x800B2080: nop
    
            goto L_800B20BC;
    }
    // 0x800B2080: nop

    // 0x800B2084: lwc1        $f0, 0x110($s3)
    ctx->f0.u32l = MEM_W(ctx->r19, 0X110);
    // 0x800B2088: mul.s       $f0, $f4, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x800B208C: lwc1        $f2, 0xFC($s3)
    ctx->f2.u32l = MEM_W(ctx->r19, 0XFC);
    // 0x800B2090: lhu         $v1, 0xB4($s3)
    ctx->r3 = MEM_HU(ctx->r19, 0XB4);
    // 0x800B2094: mul.s       $f20, $f0, $f2
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f20.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x800B2098: beq         $v1, $zero, L_800B20A8
    if (ctx->r3 == 0) {
        // 0x800B209C: addiu       $v0, $zero, 0x5
        ctx->r2 = ADD32(0, 0X5);
            goto L_800B20A8;
    }
    // 0x800B209C: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
    // 0x800B20A0: bne         $v1, $v0, L_800B20DC
    if (ctx->r3 != ctx->r2) {
        // 0x800B20A4: lui         $v1, 0x8013
        ctx->r3 = S32(0X8013 << 16);
            goto L_800B20DC;
    }
    // 0x800B20A4: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
L_800B20A8:
    // 0x800B20A8: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800B20AC: lwc1        $f0, 0x56E4($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X56E4);
    // 0x800B20B0: mul.s       $f20, $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f20.fl = MUL_S(ctx->f20.fl, ctx->f0.fl);
    // 0x800B20B4: j           L_800B20D8
    // 0x800B20B8: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
        goto L_800B20D8;
    // 0x800B20B8: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
L_800B20BC:
    // 0x800B20BC: lwc1        $f0, 0x110($s3)
    ctx->f0.u32l = MEM_W(ctx->r19, 0X110);
    // 0x800B20C0: neg.s       $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = -ctx->f4.fl;
    // 0x800B20C4: mul.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x800B20C8: lwc1        $f0, 0xFC($s3)
    ctx->f0.u32l = MEM_W(ctx->r19, 0XFC);
    // 0x800B20CC: mul.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x800B20D0: sub.s       $f20, $f20, $f2
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f20.fl = ctx->f20.fl - ctx->f2.fl;
    // 0x800B20D4: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
L_800B20D8:
    // 0x800B20D8: lw          $a1, 0xB8($s3)
    ctx->r5 = MEM_W(ctx->r19, 0XB8);
L_800B20DC:
    // 0x800B20DC: addiu       $v1, $v1, 0xB40
    ctx->r3 = ADD32(ctx->r3, 0XB40);
    // 0x800B20E0: sll         $v0, $a1, 2
    ctx->r2 = S32(ctx->r5 << 2);
    // 0x800B20E4: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800B20E8: lw          $v0, 0xC($v0)
    ctx->r2 = MEM_W(ctx->r2, 0XC);
    // 0x800B20EC: lui         $v1, 0x100
    ctx->r3 = S32(0X100 << 16);
    // 0x800B20F0: and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // 0x800B20F4: beq         $v0, $zero, L_800B213C
    if (ctx->r2 == 0) {
        // 0x800B20F8: lui         $v0, 0x8013
        ctx->r2 = S32(0X8013 << 16);
            goto L_800B213C;
    }
    // 0x800B20F8: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800B20FC: addiu       $v0, $v0, 0xB88
    ctx->r2 = ADD32(ctx->r2, 0XB88);
    // 0x800B2100: sll         $v1, $a1, 1
    ctx->r3 = S32(ctx->r5 << 1);
    // 0x800B2104: addu        $v1, $v1, $a1
    ctx->r3 = ADD32(ctx->r3, ctx->r5);
    // 0x800B2108: sll         $v1, $v1, 1
    ctx->r3 = S32(ctx->r3 << 1);
    // 0x800B210C: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x800B2110: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x800B2114: addiu       $a0, $a0, -0x41E8
    ctx->r4 = ADD32(ctx->r4, -0X41E8);
    // 0x800B2118: sll         $v0, $a1, 3
    ctx->r2 = S32(ctx->r5 << 3);
    // 0x800B211C: addu        $v0, $v0, $a1
    ctx->r2 = ADD32(ctx->r2, ctx->r5);
    // 0x800B2120: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800B2124: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x800B2128: lhu         $v1, 0x0($v1)
    ctx->r3 = MEM_HU(ctx->r3, 0X0);
    // 0x800B212C: lhu         $v0, 0x20($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X20);
    // 0x800B2130: and         $v1, $v1, $v0
    ctx->r3 = ctx->r3 & ctx->r2;
    // 0x800B2134: bne         $v1, $zero, L_800B22C8
    if (ctx->r3 != 0) {
        // 0x800B2138: andi        $v0, $fp, 0xFF
        ctx->r2 = ctx->r30 & 0XFF;
            goto L_800B22C8;
    }
    // 0x800B2138: andi        $v0, $fp, 0xFF
    ctx->r2 = ctx->r30 & 0XFF;
L_800B213C:
    // 0x800B213C: lwc1        $f2, 0xF8($s3)
    ctx->f2.u32l = MEM_W(ctx->r19, 0XF8);
    // 0x800B2140: mul.s       $f4, $f28, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f28.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f28.fl, ctx->f2.fl);
    // 0x800B2144: lwc1        $f0, 0x118($s3)
    ctx->f0.u32l = MEM_W(ctx->r19, 0X118);
    // 0x800B2148: mul.s       $f0, $f4, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x800B214C: nop

    // 0x800B2150: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x800B2154: lhu         $v1, 0xB4($s3)
    ctx->r3 = MEM_HU(ctx->r19, 0XB4);
    // 0x800B2158: bltz        $v1, L_800B2280
    if (SIGNED(ctx->r3) < 0) {
        // 0x800B215C: sub.s       $f22, $f22, $f0
        CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f22.fl = ctx->f22.fl - ctx->f0.fl;
            goto L_800B2280;
    }
    // 0x800B215C: sub.s       $f22, $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f22.fl = ctx->f22.fl - ctx->f0.fl;
    // 0x800B2160: slti        $v0, $v1, 0x3
    ctx->r2 = SIGNED(ctx->r3) < 0X3 ? 1 : 0;
    // 0x800B2164: bne         $v0, $zero, L_800B2180
    if (ctx->r2 != 0) {
        // 0x800B2168: addiu       $s0, $sp, 0xB8
        ctx->r16 = ADD32(ctx->r29, 0XB8);
            goto L_800B2180;
    }
    // 0x800B2168: addiu       $s0, $sp, 0xB8
    ctx->r16 = ADD32(ctx->r29, 0XB8);
    // 0x800B216C: slti        $v0, $v1, 0x9
    ctx->r2 = SIGNED(ctx->r3) < 0X9 ? 1 : 0;
    // 0x800B2170: beq         $v0, $zero, L_800B2280
    if (ctx->r2 == 0) {
        // 0x800B2174: slti        $v0, $v1, 0x5
        ctx->r2 = SIGNED(ctx->r3) < 0X5 ? 1 : 0;
            goto L_800B2280;
    }
    // 0x800B2174: slti        $v0, $v1, 0x5
    ctx->r2 = SIGNED(ctx->r3) < 0X5 ? 1 : 0;
    // 0x800B2178: bne         $v0, $zero, L_800B2280
    if (ctx->r2 != 0) {
        // 0x800B217C: nop
    
            goto L_800B2280;
    }
    // 0x800B217C: nop

L_800B2180:
    // 0x800B2180: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x800B2184: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800B2188: lwc1        $f0, 0x56E8($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X56E8);
    // 0x800B218C: addiu       $s1, $sp, 0xA8
    ctx->r17 = ADD32(ctx->r29, 0XA8);
    // 0x800B2190: sw          $zero, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = 0;
    // 0x800B2194: sw          $zero, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = 0;
    // 0x800B2198: swc1        $f0, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->f0.u32l;
    // 0x800B219C: lwc1        $f0, 0x8($s4)
    ctx->f0.u32l = MEM_W(ctx->r20, 0X8);
    // 0x800B21A0: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    // 0x800B21A4: swc1        $f0, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->f0.u32l;
    // 0x800B21A8: lwc1        $f0, 0x14($s4)
    ctx->f0.u32l = MEM_W(ctx->r20, 0X14);
    // 0x800B21AC: addiu       $s2, $sp, 0x98
    ctx->r18 = ADD32(ctx->r29, 0X98);
    // 0x800B21B0: swc1        $f0, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->f0.u32l;
    // 0x800B21B4: lwc1        $f0, 0x20($s4)
    ctx->f0.u32l = MEM_W(ctx->r20, 0X20);
    // 0x800B21B8: addu        $a2, $s2, $zero
    ctx->r6 = ADD32(ctx->r18, 0);
    // 0x800B21BC: jal         0x80019548
    // 0x800B21C0: swc1        $f0, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->f0.u32l;
    func_80019548(rdram, ctx);
        goto after_3;
    // 0x800B21C0: swc1        $f0, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->f0.u32l;
    after_3:
    // 0x800B21C4: jal         0x8001CF58
    // 0x800B21C8: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    normalize_vector(rdram, ctx);
        goto after_4;
    // 0x800B21C8: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_4:
    // 0x800B21CC: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x800B21D0: addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    // 0x800B21D4: jal         0x80019548
    // 0x800B21D8: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    func_80019548(rdram, ctx);
        goto after_5;
    // 0x800B21D8: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    after_5:
    // 0x800B21DC: jal         0x8001CF58
    // 0x800B21E0: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    normalize_vector(rdram, ctx);
        goto after_6;
    // 0x800B21E0: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    after_6:
    // 0x800B21E4: lwc1        $f0, 0x0($s4)
    ctx->f0.u32l = MEM_W(ctx->r20, 0X0);
    // 0x800B21E8: swc1        $f0, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->f0.u32l;
    // 0x800B21EC: lwc1        $f0, 0xC($s4)
    ctx->f0.u32l = MEM_W(ctx->r20, 0XC);
    // 0x800B21F0: addiu       $a0, $sp, 0xC8
    ctx->r4 = ADD32(ctx->r29, 0XC8);
    // 0x800B21F4: swc1        $f0, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->f0.u32l;
    // 0x800B21F8: lwc1        $f0, 0x18($s4)
    ctx->f0.u32l = MEM_W(ctx->r20, 0X18);
    // 0x800B21FC: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    // 0x800B2200: jal         0x8001CFE8
    // 0x800B2204: swc1        $f0, 0xD0($sp)
    MEM_W(0XD0, ctx->r29) = ctx->f0.u32l;
    func_8001CFE8(rdram, ctx);
        goto after_7;
    // 0x800B2204: swc1        $f0, 0xD0($sp)
    MEM_W(0XD0, ctx->r29) = ctx->f0.u32l;
    after_7:
    // 0x800B2208: jal         0x8001C400
    // 0x800B220C: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    func_8001C400(rdram, ctx);
        goto after_8;
    // 0x800B220C: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    after_8:
    // 0x800B2210: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800B2214: lwc1        $f2, 0x56EC($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X56EC);
    // 0x800B2218: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
    // 0x800B221C: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x800B2220: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800B2224: lwc1        $f2, 0x56F0($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X56F0);
    // 0x800B2228: div.s       $f24, $f0, $f2
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f24.fl = DIV_S(ctx->f0.fl, ctx->f2.fl);
    // 0x800B222C: abs.s       $f0, $f24
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f24.fl); 
    ctx->f0.fl = fabsf(ctx->f24.fl);
    // 0x800B2230: lwc1        $f6, 0x120($s3)
    ctx->f6.u32l = MEM_W(ctx->r19, 0X120);
    // 0x800B2234: c.le.s      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.fl <= ctx->f0.fl;
    // 0x800B2238: nop

    // 0x800B223C: bc1f        L_800B2250
    if (!c1cs) {
        // 0x800B2240: nop
    
            goto L_800B2250;
    }
    // 0x800B2240: nop

    // 0x800B2244: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800B2248: lwc1        $f0, 0x56F4($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X56F4);
    // 0x800B224C: mul.s       $f22, $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f22.fl = MUL_S(ctx->f22.fl, ctx->f0.fl);
L_800B2250:
    // 0x800B2250: abs.s       $f0, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f22.fl); 
    ctx->f0.fl = fabsf(ctx->f22.fl);
    // 0x800B2254: lwc1        $f10, 0x1DC($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X1DC);
    // 0x800B2258: mul.s       $f30, $f0, $f10
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f30.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x800B225C: abs.s       $f0, $f28
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f28.fl); 
    ctx->f0.fl = fabsf(ctx->f28.fl);
    // 0x800B2260: abs.s       $f2, $f24
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f24.fl); 
    ctx->f2.fl = fabsf(ctx->f24.fl);
    // 0x800B2264: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800B2268: lwc1        $f4, 0x56F8($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X56F8);
    // 0x800B226C: mul.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x800B2270: div.s       $f2, $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = DIV_S(ctx->f2.fl, ctx->f6.fl);
    // 0x800B2274: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x800B2278: nop

    // 0x800B227C: mul.s       $f30, $f30, $f0
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f30.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f30.fl = MUL_S(ctx->f30.fl, ctx->f0.fl);
L_800B2280:
    // 0x800B2280: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800B2284: c.lt.s      $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f22.fl < ctx->f0.fl;
    // 0x800B2288: nop

    // 0x800B228C: bc1f        L_800B22A4
    if (!c1cs) {
        // 0x800B2290: andi        $v0, $fp, 0xFF
        ctx->r2 = ctx->r30 & 0XFF;
            goto L_800B22A4;
    }
    // 0x800B2290: andi        $v0, $fp, 0xFF
    ctx->r2 = ctx->r30 & 0XFF;
    // 0x800B2294: beq         $v0, $zero, L_800B22F0
    if (ctx->r2 == 0) {
        // 0x800B2298: nop
    
            goto L_800B22F0;
    }
    // 0x800B2298: nop

    // 0x800B229C: j           L_800B22AC
    // 0x800B22A0: nop

        goto L_800B22AC;
    // 0x800B22A0: nop

L_800B22A4:
    // 0x800B22A4: bne         $v0, $zero, L_800B22D0
    if (ctx->r2 != 0) {
        // 0x800B22A8: nop
    
            goto L_800B22D0;
    }
    // 0x800B22A8: nop

L_800B22AC:
    // 0x800B22AC: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800B22B0: lwc1        $f0, 0x56FC($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X56FC);
    // 0x800B22B4: mul.s       $f22, $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f22.fl = MUL_S(ctx->f22.fl, ctx->f0.fl);
    // 0x800B22B8: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800B22BC: lwc1        $f0, 0x5700($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X5700);
    // 0x800B22C0: mul.s       $f20, $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f20.fl = MUL_S(ctx->f20.fl, ctx->f0.fl);
    // 0x800B22C4: andi        $v0, $fp, 0xFF
    ctx->r2 = ctx->r30 & 0XFF;
L_800B22C8:
    // 0x800B22C8: beq         $v0, $zero, L_800B22EC
    if (ctx->r2 == 0) {
        // 0x800B22CC: nop
    
            goto L_800B22EC;
    }
    // 0x800B22CC: nop

L_800B22D0:
    // 0x800B22D0: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800B22D4: c.lt.s      $f0, $f28
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 28);
    c1cs = ctx->f0.fl < ctx->f28.fl;
    // 0x800B22D8: nop

    // 0x800B22DC: bc1t        L_800B2300
    if (c1cs) {
        // 0x800B22E0: andi        $v0, $fp, 0xFF
        ctx->r2 = ctx->r30 & 0XFF;
            goto L_800B2300;
    }
    // 0x800B22E0: andi        $v0, $fp, 0xFF
    ctx->r2 = ctx->r30 & 0XFF;
    // 0x800B22E4: bne         $v0, $zero, L_800B2304
    if (ctx->r2 != 0) {
        // 0x800B22E8: nop
    
            goto L_800B2304;
    }
    // 0x800B22E8: nop

L_800B22EC:
    // 0x800B22EC: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
L_800B22F0:
    // 0x800B22F0: c.lt.s      $f28, $f0
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f28.fl < ctx->f0.fl;
    // 0x800B22F4: nop

    // 0x800B22F8: bc1f        L_800B2304
    if (!c1cs) {
        // 0x800B22FC: nop
    
            goto L_800B2304;
    }
    // 0x800B22FC: nop

L_800B2300:
    // 0x800B2300: mtc1        $zero, $f30
    ctx->f30.u32l = 0;
L_800B2304:
    // 0x800B2304: lwc1        $f2, 0x114($s3)
    ctx->f2.u32l = MEM_W(ctx->r19, 0X114);
    // 0x800B2308: lwc1        $f0, 0xF8($s3)
    ctx->f0.u32l = MEM_W(ctx->r19, 0XF8);
    // 0x800B230C: mul.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x800B2310: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x800B2314: lw          $v0, 0xB8($s3)
    ctx->r2 = MEM_W(ctx->r19, 0XB8);
    // 0x800B2318: addiu       $v1, $v1, 0xB40
    ctx->r3 = ADD32(ctx->r3, 0XB40);
    // 0x800B231C: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800B2320: mul.s       $f0, $f26, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = MUL_S(ctx->f26.fl, ctx->f0.fl);
    // 0x800B2324: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800B2328: lw          $v0, 0xC($v0)
    ctx->r2 = MEM_W(ctx->r2, 0XC);
    // 0x800B232C: andi        $v0, $v0, 0x4
    ctx->r2 = ctx->r2 & 0X4;
    // 0x800B2330: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
    // 0x800B2334: mul.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x800B2338: bnel        $v0, $zero, L_800B2340
    if (ctx->r2 != 0) {
        // 0x800B233C: neg.s       $f2, $f2
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = -ctx->f2.fl;
            goto L_800B2340;
    }
    goto skip_3;
    // 0x800B233C: neg.s       $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = -ctx->f2.fl;
    skip_3:
L_800B2340:
    // 0x800B2340: lwc1        $f10, 0x178($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X178);
    // 0x800B2344: add.s       $f10, $f10, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = ctx->f10.fl + ctx->f2.fl;
    // 0x800B2348: swc1        $f10, 0x178($sp)
    MEM_W(0X178, ctx->r29) = ctx->f10.u32l;
    // 0x800B234C: lwc1        $f2, 0x13C($s3)
    ctx->f2.u32l = MEM_W(ctx->r19, 0X13C);
    // 0x800B2350: lwc1        $f0, 0xD4($s3)
    ctx->f0.u32l = MEM_W(ctx->r19, 0XD4);
    // 0x800B2354: mov.s       $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    ctx->f4.fl = ctx->f2.fl;
    // 0x800B2358: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x800B235C: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x800B2360: c.lt.s      $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f2.fl < ctx->f4.fl;
    // 0x800B2364: nop

    // 0x800B2368: bc1f        L_800B2384
    if (!c1cs) {
        // 0x800B236C: swc1        $f0, 0xD4($s3)
        MEM_W(0XD4, ctx->r19) = ctx->f0.u32l;
            goto L_800B2384;
    }
    // 0x800B236C: swc1        $f0, 0xD4($s3)
    MEM_W(0XD4, ctx->r19) = ctx->f0.u32l;
    // 0x800B2370: lwc1        $f0, 0x140($s3)
    ctx->f0.u32l = MEM_W(ctx->r19, 0X140);
    // 0x800B2374: sub.s       $f0, $f4, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f0.fl;
    // 0x800B2378: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x800B237C: j           L_800B2394
    // 0x800B2380: swc1        $f0, 0x13C($s3)
    MEM_W(0X13C, ctx->r19) = ctx->f0.u32l;
        goto L_800B2394;
    // 0x800B2380: swc1        $f0, 0x13C($s3)
    MEM_W(0X13C, ctx->r19) = ctx->f0.u32l;
L_800B2384:
    // 0x800B2384: lwc1        $f0, 0x140($s3)
    ctx->f0.u32l = MEM_W(ctx->r19, 0X140);
    // 0x800B2388: add.s       $f0, $f4, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f4.fl + ctx->f0.fl;
    // 0x800B238C: swc1        $f0, 0x13C($s3)
    MEM_W(0X13C, ctx->r19) = ctx->f0.u32l;
    // 0x800B2390: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
L_800B2394:
    // 0x800B2394: nop

    // 0x800B2398: bc1tl       L_800B23A0
    if (c1cs) {
        // 0x800B239C: swc1        $f2, 0x13C($s3)
        MEM_W(0X13C, ctx->r19) = ctx->f2.u32l;
            goto L_800B23A0;
    }
    goto skip_4;
    // 0x800B239C: swc1        $f2, 0x13C($s3)
    MEM_W(0X13C, ctx->r19) = ctx->f2.u32l;
    skip_4:
L_800B23A0:
    // 0x800B23A0: lwc1        $f2, 0xD0($s3)
    ctx->f2.u32l = MEM_W(ctx->r19, 0XD0);
    // 0x800B23A4: lwc1        $f0, 0x14C($s3)
    ctx->f0.u32l = MEM_W(ctx->r19, 0X14C);
    // 0x800B23A8: add.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x800B23AC: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x800B23B0: mov.s       $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    ctx->f4.fl = ctx->f0.fl;
    // 0x800B23B4: c.lt.s      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.fl < ctx->f4.fl;
    // 0x800B23B8: nop

    // 0x800B23BC: bc1f        L_800B23D8
    if (!c1cs) {
        // 0x800B23C0: swc1        $f2, 0xD0($s3)
        MEM_W(0XD0, ctx->r19) = ctx->f2.u32l;
            goto L_800B23D8;
    }
    // 0x800B23C0: swc1        $f2, 0xD0($s3)
    MEM_W(0XD0, ctx->r19) = ctx->f2.u32l;
    // 0x800B23C4: lwc1        $f0, 0x150($s3)
    ctx->f0.u32l = MEM_W(ctx->r19, 0X150);
    // 0x800B23C8: sub.s       $f0, $f4, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f0.fl;
    // 0x800B23CC: c.lt.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl < ctx->f6.fl;
    // 0x800B23D0: j           L_800B23E8
    // 0x800B23D4: swc1        $f0, 0x14C($s3)
    MEM_W(0X14C, ctx->r19) = ctx->f0.u32l;
        goto L_800B23E8;
    // 0x800B23D4: swc1        $f0, 0x14C($s3)
    MEM_W(0X14C, ctx->r19) = ctx->f0.u32l;
L_800B23D8:
    // 0x800B23D8: lwc1        $f0, 0x150($s3)
    ctx->f0.u32l = MEM_W(ctx->r19, 0X150);
    // 0x800B23DC: add.s       $f0, $f4, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f4.fl + ctx->f0.fl;
    // 0x800B23E0: swc1        $f0, 0x14C($s3)
    MEM_W(0X14C, ctx->r19) = ctx->f0.u32l;
    // 0x800B23E4: c.lt.s      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.fl < ctx->f0.fl;
L_800B23E8:
    // 0x800B23E8: nop

    // 0x800B23EC: bc1tl       L_800B23F4
    if (c1cs) {
        // 0x800B23F0: swc1        $f6, 0x14C($s3)
        MEM_W(0X14C, ctx->r19) = ctx->f6.u32l;
            goto L_800B23F4;
    }
    goto skip_5;
    // 0x800B23F0: swc1        $f6, 0x14C($s3)
    MEM_W(0X14C, ctx->r19) = ctx->f6.u32l;
    skip_5:
L_800B23F4:
    // 0x800B23F4: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800B23F8: lw          $v1, 0xB8($s3)
    ctx->r3 = MEM_W(ctx->r19, 0XB8);
    // 0x800B23FC: addiu       $a0, $a0, 0x7DB8
    ctx->r4 = ADD32(ctx->r4, 0X7DB8);
    // 0x800B2400: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x800B2404: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800B2408: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800B240C: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800B2410: sll         $v0, $v0, 5
    ctx->r2 = S32(ctx->r2 << 5);
    // 0x800B2414: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x800B2418: lhu         $v0, 0x184($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X184);
    // 0x800B241C: andi        $v0, $v0, 0x2
    ctx->r2 = ctx->r2 & 0X2;
    // 0x800B2420: bne         $v0, $zero, L_800B2438
    if (ctx->r2 != 0) {
        // 0x800B2424: nop
    
            goto L_800B2438;
    }
    // 0x800B2424: nop

    // 0x800B2428: swc1        $f22, 0xD8($s3)
    MEM_W(0XD8, ctx->r19) = ctx->f22.u32l;
    // 0x800B242C: lwc1        $f10, 0x178($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X178);
    // 0x800B2430: swc1        $f10, 0xDC($s3)
    MEM_W(0XDC, ctx->r19) = ctx->f10.u32l;
    // 0x800B2434: swc1        $f20, 0xE0($s3)
    MEM_W(0XE0, ctx->r19) = ctx->f20.u32l;
L_800B2438:
    // 0x800B2438: lwc1        $f4, 0xD8($s3)
    ctx->f4.u32l = MEM_W(ctx->r19, 0XD8);
    // 0x800B243C: lwc1        $f10, 0x1DC($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X1DC);
    // 0x800B2440: mul.s       $f4, $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f4.fl, ctx->f10.fl);
    // 0x800B2444: lwc1        $f2, 0xDC($s3)
    ctx->f2.u32l = MEM_W(ctx->r19, 0XDC);
    // 0x800B2448: mul.s       $f2, $f2, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f10.fl);
    // 0x800B244C: lwc1        $f0, 0xE0($s3)
    ctx->f0.u32l = MEM_W(ctx->r19, 0XE0);
    // 0x800B2450: mul.s       $f0, $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x800B2454: swc1        $f4, 0xD8($s3)
    MEM_W(0XD8, ctx->r19) = ctx->f4.u32l;
    // 0x800B2458: swc1        $f2, 0xDC($s3)
    MEM_W(0XDC, ctx->r19) = ctx->f2.u32l;
    // 0x800B245C: swc1        $f0, 0xE0($s3)
    MEM_W(0XE0, ctx->r19) = ctx->f0.u32l;
    // 0x800B2460: lwc1        $f0, 0x8($s4)
    ctx->f0.u32l = MEM_W(ctx->r20, 0X8);
    // 0x800B2464: swc1        $f0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f0.u32l;
    // 0x800B2468: lwc1        $f0, 0x14($s4)
    ctx->f0.u32l = MEM_W(ctx->r20, 0X14);
    // 0x800B246C: swc1        $f0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f0.u32l;
    // 0x800B2470: lwc1        $f0, 0x20($s4)
    ctx->f0.u32l = MEM_W(ctx->r20, 0X20);
    // 0x800B2474: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    // 0x800B2478: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x800B247C: jal         0x800AA350
    // 0x800B2480: swc1        $f0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f0.u32l;
    func_800AA350(rdram, ctx);
        goto after_9;
    // 0x800B2480: swc1        $f0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f0.u32l;
    after_9:
    // 0x800B2484: lwc1        $f0, 0x8($s4)
    ctx->f0.u32l = MEM_W(ctx->r20, 0X8);
    // 0x800B2488: swc1        $f0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f0.u32l;
    // 0x800B248C: lwc1        $f0, 0x14($s4)
    ctx->f0.u32l = MEM_W(ctx->r20, 0X14);
    // 0x800B2490: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    // 0x800B2494: swc1        $f0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f0.u32l;
    // 0x800B2498: lwc1        $f0, 0x20($s4)
    ctx->f0.u32l = MEM_W(ctx->r20, 0X20);
    // 0x800B249C: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    // 0x800B24A0: jal         0x8001CFE8
    // 0x800B24A4: swc1        $f0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f0.u32l;
    func_8001CFE8(rdram, ctx);
        goto after_10;
    // 0x800B24A4: swc1        $f0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f0.u32l;
    after_10:
    // 0x800B24A8: jal         0x8001C400
    // 0x800B24AC: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    func_8001C400(rdram, ctx);
        goto after_11;
    // 0x800B24AC: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    after_11:
    // 0x800B24B0: lui         $a2, 0x8013
    ctx->r6 = S32(0X8013 << 16);
    // 0x800B24B4: addiu       $v1, $a2, 0xB40
    ctx->r3 = ADD32(ctx->r6, 0XB40);
    // 0x800B24B8: lw          $a1, 0xB8($s3)
    ctx->r5 = MEM_W(ctx->r19, 0XB8);
    // 0x800B24BC: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800B24C0: lwc1        $f2, 0x5704($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X5704);
    // 0x800B24C4: sll         $v0, $a1, 2
    ctx->r2 = S32(ctx->r5 << 2);
    // 0x800B24C8: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x800B24CC: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800B24D0: lw          $v0, 0xC($v0)
    ctx->r2 = MEM_W(ctx->r2, 0XC);
    // 0x800B24D4: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800B24D8: lwc1        $f2, 0x5708($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X5708);
    // 0x800B24DC: andi        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 & 0X1;
    // 0x800B24E0: beq         $v0, $zero, L_800B25B0
    if (ctx->r2 == 0) {
        // 0x800B24E4: sub.s       $f4, $f2, $f0
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f2.fl - ctx->f0.fl;
            goto L_800B25B0;
    }
    // 0x800B24E4: sub.s       $f4, $f2, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f2.fl - ctx->f0.fl;
    // 0x800B24E8: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x800B24EC: c.eq.s      $f26, $f6
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f26.fl == ctx->f6.fl;
    // 0x800B24F0: nop

    // 0x800B24F4: bc1f        L_800B25B4
    if (!c1cs) {
        // 0x800B24F8: lui         $v0, 0x8011
        ctx->r2 = S32(0X8011 << 16);
            goto L_800B25B4;
    }
    // 0x800B24F8: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800B24FC: c.eq.s      $f28, $f6
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f28.fl == ctx->f6.fl;
    // 0x800B2500: nop

    // 0x800B2504: bc1f        L_800B25B0
    if (!c1cs) {
        // 0x800B2508: lui         $v0, 0x8013
        ctx->r2 = S32(0X8013 << 16);
            goto L_800B25B0;
    }
    // 0x800B2508: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800B250C: addiu       $v0, $v0, 0xB88
    ctx->r2 = ADD32(ctx->r2, 0XB88);
    // 0x800B2510: sll         $v1, $a1, 1
    ctx->r3 = S32(ctx->r5 << 1);
    // 0x800B2514: addu        $v1, $v1, $a1
    ctx->r3 = ADD32(ctx->r3, ctx->r5);
    // 0x800B2518: sll         $v1, $v1, 1
    ctx->r3 = S32(ctx->r3 << 1);
    // 0x800B251C: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x800B2520: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x800B2524: addiu       $a0, $a0, -0x41E8
    ctx->r4 = ADD32(ctx->r4, -0X41E8);
    // 0x800B2528: sll         $v0, $a1, 3
    ctx->r2 = S32(ctx->r5 << 3);
    // 0x800B252C: addu        $v0, $v0, $a1
    ctx->r2 = ADD32(ctx->r2, ctx->r5);
    // 0x800B2530: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800B2534: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x800B2538: lhu         $v1, 0x0($v1)
    ctx->r3 = MEM_HU(ctx->r3, 0X0);
    // 0x800B253C: lhu         $v0, 0x20($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X20);
    // 0x800B2540: and         $v1, $v1, $v0
    ctx->r3 = ctx->r3 & ctx->r2;
    // 0x800B2544: bnel        $v1, $zero, L_800B25B4
    if (ctx->r3 != 0) {
        // 0x800B2548: lui         $v0, 0x8011
        ctx->r2 = S32(0X8011 << 16);
            goto L_800B25B4;
    }
    goto skip_6;
    // 0x800B2548: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    skip_6:
    // 0x800B254C: abs.s       $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = fabsf(ctx->f4.fl);
    // 0x800B2550: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800B2554: lwc1        $f0, 0x570C($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X570C);
    // 0x800B2558: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x800B255C: nop

    // 0x800B2560: bc1f        L_800B2594
    if (!c1cs) {
        // 0x800B2564: nop
    
            goto L_800B2594;
    }
    // 0x800B2564: nop

    // 0x800B2568: lwc1        $f0, 0x14($s4)
    ctx->f0.u32l = MEM_W(ctx->r20, 0X14);
    // 0x800B256C: c.lt.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl < ctx->f6.fl;
    // 0x800B2570: nop

    // 0x800B2574: bc1t        L_800B258C
    if (c1cs) {
        // 0x800B2578: lui         $v1, 0x8011
        ctx->r3 = S32(0X8011 << 16);
            goto L_800B258C;
    }
    // 0x800B2578: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
    // 0x800B257C: lbu         $v1, 0xB40($a2)
    ctx->r3 = MEM_BU(ctx->r6, 0XB40);
    // 0x800B2580: addiu       $v0, $zero, 0xA
    ctx->r2 = ADD32(0, 0XA);
    // 0x800B2584: bne         $v1, $v0, L_800B2594
    if (ctx->r3 != ctx->r2) {
        // 0x800B2588: lui         $v1, 0x8011
        ctx->r3 = S32(0X8011 << 16);
            goto L_800B2594;
    }
    // 0x800B2588: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
L_800B258C:
    // 0x800B258C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800B2590: sb          $v0, -0x6947($v1)
    MEM_B(-0X6947, ctx->r3) = ctx->r2;
L_800B2594:
    // 0x800B2594: abs.s       $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = fabsf(ctx->f4.fl);
    // 0x800B2598: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800B259C: lwc1        $f0, 0x5710($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X5710);
    // 0x800B25A0: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x800B25A4: nop

    // 0x800B25A8: bc1f        L_800B25BC
    if (!c1cs) {
        // 0x800B25AC: lui         $v0, 0x8013
        ctx->r2 = S32(0X8013 << 16);
            goto L_800B25BC;
    }
    // 0x800B25AC: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
L_800B25B0:
    // 0x800B25B0: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
L_800B25B4:
    // 0x800B25B4: sb          $zero, -0x6947($v0)
    MEM_B(-0X6947, ctx->r2) = 0;
    // 0x800B25B8: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
L_800B25BC:
    // 0x800B25BC: lw          $a1, 0xB8($s3)
    ctx->r5 = MEM_W(ctx->r19, 0XB8);
    // 0x800B25C0: addiu       $v0, $v0, 0xB40
    ctx->r2 = ADD32(ctx->r2, 0XB40);
    // 0x800B25C4: sll         $v1, $a1, 2
    ctx->r3 = S32(ctx->r5 << 2);
    // 0x800B25C8: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x800B25CC: lw          $v1, 0xC($v1)
    ctx->r3 = MEM_W(ctx->r3, 0XC);
    // 0x800B25D0: andi        $v0, $v1, 0x2
    ctx->r2 = ctx->r3 & 0X2;
    // 0x800B25D4: beql        $v0, $zero, L_800B2660
    if (ctx->r2 == 0) {
        // 0x800B25D8: lui         $v1, 0x8013
        ctx->r3 = S32(0X8013 << 16);
            goto L_800B2660;
    }
    goto skip_7;
    // 0x800B25D8: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    skip_7:
    // 0x800B25DC: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800B25E0: c.eq.s      $f26, $f0
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f26.fl == ctx->f0.fl;
    // 0x800B25E4: nop

    // 0x800B25E8: bc1fl       L_800B2660
    if (!c1cs) {
        // 0x800B25EC: lui         $v1, 0x8013
        ctx->r3 = S32(0X8013 << 16);
            goto L_800B2660;
    }
    goto skip_8;
    // 0x800B25EC: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    skip_8:
    // 0x800B25F0: c.eq.s      $f28, $f0
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f28.fl == ctx->f0.fl;
    // 0x800B25F4: nop

    // 0x800B25F8: bc1f        L_800B265C
    if (!c1cs) {
        // 0x800B25FC: lui         $v0, 0x100
        ctx->r2 = S32(0X100 << 16);
            goto L_800B265C;
    }
    // 0x800B25FC: lui         $v0, 0x100
    ctx->r2 = S32(0X100 << 16);
    // 0x800B2600: and         $v0, $v1, $v0
    ctx->r2 = ctx->r3 & ctx->r2;
    // 0x800B2604: beq         $v0, $zero, L_800B2654
    if (ctx->r2 == 0) {
        // 0x800B2608: lui         $v0, 0x8013
        ctx->r2 = S32(0X8013 << 16);
            goto L_800B2654;
    }
    // 0x800B2608: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800B260C: addiu       $v0, $v0, 0xB88
    ctx->r2 = ADD32(ctx->r2, 0XB88);
    // 0x800B2610: sll         $v1, $a1, 1
    ctx->r3 = S32(ctx->r5 << 1);
    // 0x800B2614: addu        $v1, $v1, $a1
    ctx->r3 = ADD32(ctx->r3, ctx->r5);
    // 0x800B2618: sll         $v1, $v1, 1
    ctx->r3 = S32(ctx->r3 << 1);
    // 0x800B261C: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x800B2620: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x800B2624: addiu       $a0, $a0, -0x41E8
    ctx->r4 = ADD32(ctx->r4, -0X41E8);
    // 0x800B2628: sll         $v0, $a1, 3
    ctx->r2 = S32(ctx->r5 << 3);
    // 0x800B262C: addu        $v0, $v0, $a1
    ctx->r2 = ADD32(ctx->r2, ctx->r5);
    // 0x800B2630: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800B2634: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x800B2638: lhu         $v1, 0x0($v1)
    ctx->r3 = MEM_HU(ctx->r3, 0X0);
    // 0x800B263C: lhu         $v0, 0x20($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X20);
    // 0x800B2640: and         $v1, $v1, $v0
    ctx->r3 = ctx->r3 & ctx->r2;
    // 0x800B2644: beq         $v1, $zero, L_800B2658
    if (ctx->r3 == 0) {
        // 0x800B2648: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_800B2658;
    }
    // 0x800B2648: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800B264C: j           L_800B265C
    // 0x800B2650: sb          $zero, 0x174($sp)
    MEM_B(0X174, ctx->r29) = 0;
        goto L_800B265C;
    // 0x800B2650: sb          $zero, 0x174($sp)
    MEM_B(0X174, ctx->r29) = 0;
L_800B2654:
    // 0x800B2654: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800B2658:
    // 0x800B2658: sb          $v0, 0x174($sp)
    MEM_B(0X174, ctx->r29) = ctx->r2;
L_800B265C:
    // 0x800B265C: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
L_800B2660:
    // 0x800B2660: lw          $v0, 0xB8($s3)
    ctx->r2 = MEM_W(ctx->r19, 0XB8);
    // 0x800B2664: addiu       $v1, $v1, 0xB40
    ctx->r3 = ADD32(ctx->r3, 0XB40);
    // 0x800B2668: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800B266C: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800B2670: lw          $v0, 0xC($v0)
    ctx->r2 = MEM_W(ctx->r2, 0XC);
    // 0x800B2674: lui         $v1, 0x100
    ctx->r3 = S32(0X100 << 16);
    // 0x800B2678: and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // 0x800B267C: bne         $v0, $zero, L_800B26B4
    if (ctx->r2 != 0) {
        // 0x800B2680: nop
    
            goto L_800B26B4;
    }
    // 0x800B2680: nop

    // 0x800B2684: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800B2688: c.eq.s      $f26, $f0
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f26.fl == ctx->f0.fl;
    // 0x800B268C: nop

    // 0x800B2690: bc1fl       L_800B26B4
    if (!c1cs) {
        // 0x800B2694: sb          $zero, 0x174($sp)
        MEM_B(0X174, ctx->r29) = 0;
            goto L_800B26B4;
    }
    goto skip_9;
    // 0x800B2694: sb          $zero, 0x174($sp)
    MEM_B(0X174, ctx->r29) = 0;
    skip_9:
    // 0x800B2698: c.eq.s      $f28, $f0
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f28.fl == ctx->f0.fl;
    // 0x800B269C: nop

    // 0x800B26A0: bc1f        L_800B26B0
    if (!c1cs) {
        // 0x800B26A4: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_800B26B0;
    }
    // 0x800B26A4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800B26A8: j           L_800B26B4
    // 0x800B26AC: sb          $v0, 0x174($sp)
    MEM_B(0X174, ctx->r29) = ctx->r2;
        goto L_800B26B4;
    // 0x800B26AC: sb          $v0, 0x174($sp)
    MEM_B(0X174, ctx->r29) = ctx->r2;
L_800B26B0:
    // 0x800B26B0: sb          $zero, 0x174($sp)
    MEM_B(0X174, ctx->r29) = 0;
L_800B26B4:
    // 0x800B26B4: abs.s       $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = fabsf(ctx->f4.fl);
    // 0x800B26B8: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800B26BC: lwc1        $f0, 0x5714($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X5714);
    // 0x800B26C0: c.le.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl <= ctx->f2.fl;
    // 0x800B26C4: nop

    // 0x800B26C8: bc1tl       L_800B26D0
    if (c1cs) {
        // 0x800B26CC: sb          $zero, 0x174($sp)
        MEM_B(0X174, ctx->r29) = 0;
            goto L_800B26D0;
    }
    goto skip_10;
    // 0x800B26CC: sb          $zero, 0x174($sp)
    MEM_B(0X174, ctx->r29) = 0;
    skip_10:
L_800B26D0:
    // 0x800B26D0: abs.s       $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = fabsf(ctx->f4.fl);
    // 0x800B26D4: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800B26D8: lwc1        $f0, 0x5718($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X5718);
    // 0x800B26DC: c.le.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl <= ctx->f2.fl;
    // 0x800B26E0: nop

    // 0x800B26E4: bc1tl       L_800B26EC
    if (c1cs) {
        // 0x800B26E8: sw          $zero, 0xD8($s3)
        MEM_W(0XD8, ctx->r19) = 0;
            goto L_800B26EC;
    }
    goto skip_11;
    // 0x800B26E8: sw          $zero, 0xD8($s3)
    MEM_W(0XD8, ctx->r19) = 0;
    skip_11:
L_800B26EC:
    // 0x800B26EC: abs.s       $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = fabsf(ctx->f4.fl);
    // 0x800B26F0: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800B26F4: lwc1        $f6, 0x571C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X571C);
    // 0x800B26F8: c.le.s      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.fl <= ctx->f0.fl;
    // 0x800B26FC: nop

    // 0x800B2700: bc1f        L_800B2724
    if (!c1cs) {
        // 0x800B2704: nop
    
            goto L_800B2724;
    }
    // 0x800B2704: nop

    // 0x800B2708: abs.s       $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = fabsf(ctx->f4.fl);
    // 0x800B270C: sub.s       $f0, $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f6.fl;
    // 0x800B2710: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800B2714: lwc1        $f2, 0x5720($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X5720);
    // 0x800B2718: div.s       $f0, $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f6.fl);
    // 0x800B271C: sub.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl - ctx->f0.fl;
    // 0x800B2720: mul.s       $f30, $f30, $f2
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f30.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f30.fl = MUL_S(ctx->f30.fl, ctx->f2.fl);
L_800B2724:
    // 0x800B2724: lwc1        $f0, 0xDC($s3)
    ctx->f0.u32l = MEM_W(ctx->r19, 0XDC);
    // 0x800B2728: sub.s       $f0, $f0, $f30
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f30.fl;
    // 0x800B272C: lw          $a1, 0x1DC($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1DC);
    // 0x800B2730: addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    // 0x800B2734: jal         0x800AE5C4
    // 0x800B2738: swc1        $f0, 0xDC($s3)
    MEM_W(0XDC, ctx->r19) = ctx->f0.u32l;
    func_800AE5C4(rdram, ctx);
        goto after_12;
    // 0x800B2738: swc1        $f0, 0xDC($s3)
    MEM_W(0XDC, ctx->r19) = ctx->f0.u32l;
    after_12:
    // 0x800B273C: addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    // 0x800B2740: addiu       $a2, $sp, 0x168
    ctx->r6 = ADD32(ctx->r29, 0X168);
    // 0x800B2744: addiu       $a3, $sp, 0x16C
    ctx->r7 = ADD32(ctx->r29, 0X16C);
    // 0x800B2748: addiu       $v0, $sp, 0x170
    ctx->r2 = ADD32(ctx->r29, 0X170);
    // 0x800B274C: lw          $a1, 0x1DC($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1DC);
    // 0x800B2750: lui         $s0, 0x8011
    ctx->r16 = S32(0X8011 << 16);
    // 0x800B2754: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // 0x800B2758: addiu       $v0, $s0, -0x6947
    ctx->r2 = ADD32(ctx->r16, -0X6947);
    // 0x800B275C: sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    // 0x800B2760: addiu       $v0, $sp, 0x174
    ctx->r2 = ADD32(ctx->r29, 0X174);
    // 0x800B2764: jal         0x800AF04C
    // 0x800B2768: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    func_800AF04C(rdram, ctx);
        goto after_13;
    // 0x800B2768: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    after_13:
    // 0x800B276C: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x800B2770: lw          $a1, 0xB8($s3)
    ctx->r5 = MEM_W(ctx->r19, 0XB8);
    // 0x800B2774: addiu       $v1, $v1, 0x7DB8
    ctx->r3 = ADD32(ctx->r3, 0X7DB8);
    // 0x800B2778: sll         $v0, $a1, 2
    ctx->r2 = S32(ctx->r5 << 2);
    // 0x800B277C: addu        $v0, $v0, $a1
    ctx->r2 = ADD32(ctx->r2, ctx->r5);
    // 0x800B2780: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800B2784: addu        $v0, $v0, $a1
    ctx->r2 = ADD32(ctx->r2, ctx->r5);
    // 0x800B2788: sll         $v0, $v0, 5
    ctx->r2 = S32(ctx->r2 << 5);
    // 0x800B278C: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800B2790: lhu         $v0, 0x184($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X184);
    // 0x800B2794: andi        $v0, $v0, 0x2
    ctx->r2 = ctx->r2 & 0X2;
    // 0x800B2798: beq         $v0, $zero, L_800B27AC
    if (ctx->r2 == 0) {
        // 0x800B279C: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_800B27AC;
    }
    // 0x800B279C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800B27A0: sb          $v0, -0x6947($s0)
    MEM_B(-0X6947, ctx->r16) = ctx->r2;
    // 0x800B27A4: j           L_800B27FC
    // 0x800B27A8: sb          $v0, 0x174($sp)
    MEM_B(0X174, ctx->r29) = ctx->r2;
        goto L_800B27FC;
    // 0x800B27A8: sb          $v0, 0x174($sp)
    MEM_B(0X174, ctx->r29) = ctx->r2;
L_800B27AC:
    // 0x800B27AC: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800B27B0: addiu       $v0, $v0, 0xB88
    ctx->r2 = ADD32(ctx->r2, 0XB88);
    // 0x800B27B4: sll         $v1, $a1, 1
    ctx->r3 = S32(ctx->r5 << 1);
    // 0x800B27B8: addu        $v1, $v1, $a1
    ctx->r3 = ADD32(ctx->r3, ctx->r5);
    // 0x800B27BC: sll         $v1, $v1, 1
    ctx->r3 = S32(ctx->r3 << 1);
    // 0x800B27C0: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x800B27C4: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x800B27C8: addiu       $a0, $a0, -0x41E8
    ctx->r4 = ADD32(ctx->r4, -0X41E8);
    // 0x800B27CC: sll         $v0, $a1, 3
    ctx->r2 = S32(ctx->r5 << 3);
    // 0x800B27D0: addu        $v0, $v0, $a1
    ctx->r2 = ADD32(ctx->r2, ctx->r5);
    // 0x800B27D4: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800B27D8: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x800B27DC: lhu         $v1, 0x0($v1)
    ctx->r3 = MEM_HU(ctx->r3, 0X0);
    // 0x800B27E0: lhu         $v0, 0x6($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X6);
    // 0x800B27E4: and         $v1, $v1, $v0
    ctx->r3 = ctx->r3 & ctx->r2;
    // 0x800B27E8: beq         $v1, $zero, L_800B2800
    if (ctx->r3 == 0) {
        // 0x800B27EC: addiu       $s0, $sp, 0xB8
        ctx->r16 = ADD32(ctx->r29, 0XB8);
            goto L_800B2800;
    }
    // 0x800B27EC: addiu       $s0, $sp, 0xB8
    ctx->r16 = ADD32(ctx->r29, 0XB8);
    // 0x800B27F0: sw          $zero, 0xD8($s3)
    MEM_W(0XD8, ctx->r19) = 0;
    // 0x800B27F4: sw          $zero, 0xDC($s3)
    MEM_W(0XDC, ctx->r19) = 0;
    // 0x800B27F8: sw          $zero, 0xE0($s3)
    MEM_W(0XE0, ctx->r19) = 0;
L_800B27FC:
    // 0x800B27FC: addiu       $s0, $sp, 0xB8
    ctx->r16 = ADD32(ctx->r29, 0XB8);
L_800B2800:
    // 0x800B2800: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x800B2804: lwc1        $f4, 0xDC($s3)
    ctx->f4.u32l = MEM_W(ctx->r19, 0XDC);
    // 0x800B2808: lwc1        $f0, 0x14C($s3)
    ctx->f0.u32l = MEM_W(ctx->r19, 0X14C);
    // 0x800B280C: lwc1        $f2, 0xE0($s3)
    ctx->f2.u32l = MEM_W(ctx->r19, 0XE0);
    // 0x800B2810: add.s       $f4, $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f0.fl;
    // 0x800B2814: lwc1        $f0, 0x13C($s3)
    ctx->f0.u32l = MEM_W(ctx->r19, 0X13C);
    // 0x800B2818: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800B281C: lwc1        $f20, 0x5724($at)
    ctx->f20.u32l = MEM_W(ctx->r1, 0X5724);
    // 0x800B2820: add.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x800B2824: addiu       $s1, $sp, 0xA8
    ctx->r17 = ADD32(ctx->r29, 0XA8);
    // 0x800B2828: swc1        $f4, 0xDC($s3)
    MEM_W(0XDC, ctx->r19) = ctx->f4.u32l;
    // 0x800B282C: swc1        $f2, 0xE0($s3)
    MEM_W(0XE0, ctx->r19) = ctx->f2.u32l;
    // 0x800B2830: sw          $zero, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = 0;
    // 0x800B2834: swc1        $f20, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->f20.u32l;
    // 0x800B2838: sw          $zero, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = 0;
    // 0x800B283C: lwc1        $f0, 0x8($s4)
    ctx->f0.u32l = MEM_W(ctx->r20, 0X8);
    // 0x800B2840: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    // 0x800B2844: swc1        $f0, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->f0.u32l;
    // 0x800B2848: lwc1        $f0, 0x14($s4)
    ctx->f0.u32l = MEM_W(ctx->r20, 0X14);
    // 0x800B284C: addiu       $s2, $sp, 0x98
    ctx->r18 = ADD32(ctx->r29, 0X98);
    // 0x800B2850: swc1        $f0, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->f0.u32l;
    // 0x800B2854: lwc1        $f0, 0x20($s4)
    ctx->f0.u32l = MEM_W(ctx->r20, 0X20);
    // 0x800B2858: addu        $a2, $s2, $zero
    ctx->r6 = ADD32(ctx->r18, 0);
    // 0x800B285C: jal         0x80019548
    // 0x800B2860: swc1        $f0, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->f0.u32l;
    func_80019548(rdram, ctx);
        goto after_14;
    // 0x800B2860: swc1        $f0, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->f0.u32l;
    after_14:
    // 0x800B2864: jal         0x8001CF58
    // 0x800B2868: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    normalize_vector(rdram, ctx);
        goto after_15;
    // 0x800B2868: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_15:
    // 0x800B286C: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x800B2870: addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    // 0x800B2874: jal         0x80019548
    // 0x800B2878: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    func_80019548(rdram, ctx);
        goto after_16;
    // 0x800B2878: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    after_16:
    // 0x800B287C: jal         0x8001CF58
    // 0x800B2880: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    normalize_vector(rdram, ctx);
        goto after_17;
    // 0x800B2880: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    after_17:
    // 0x800B2884: lwc1        $f0, 0x0($s4)
    ctx->f0.u32l = MEM_W(ctx->r20, 0X0);
    // 0x800B2888: swc1        $f0, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->f0.u32l;
    // 0x800B288C: lwc1        $f0, 0xC($s4)
    ctx->f0.u32l = MEM_W(ctx->r20, 0XC);
    // 0x800B2890: addiu       $a0, $sp, 0xC8
    ctx->r4 = ADD32(ctx->r29, 0XC8);
    // 0x800B2894: swc1        $f0, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->f0.u32l;
    // 0x800B2898: lwc1        $f0, 0x18($s4)
    ctx->f0.u32l = MEM_W(ctx->r20, 0X18);
    // 0x800B289C: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    // 0x800B28A0: jal         0x8001CFE8
    // 0x800B28A4: swc1        $f0, 0xD0($sp)
    MEM_W(0XD0, ctx->r29) = ctx->f0.u32l;
    func_8001CFE8(rdram, ctx);
        goto after_18;
    // 0x800B28A4: swc1        $f0, 0xD0($sp)
    MEM_W(0XD0, ctx->r29) = ctx->f0.u32l;
    after_18:
    // 0x800B28A8: jal         0x8001C400
    // 0x800B28AC: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    func_8001C400(rdram, ctx);
        goto after_19;
    // 0x800B28AC: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    after_19:
    // 0x800B28B0: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800B28B4: lwc1        $f2, 0x5728($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X5728);
    // 0x800B28B8: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
    // 0x800B28BC: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x800B28C0: addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    // 0x800B28C4: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800B28C8: lwc1        $f2, 0x572C($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X572C);
    // 0x800B28CC: lw          $a1, 0x1DC($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1DC);
    // 0x800B28D0: jal         0x800AECF8
    // 0x800B28D4: div.s       $f24, $f0, $f2
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f24.fl = DIV_S(ctx->f0.fl, ctx->f2.fl);
    func_800AECF8(rdram, ctx);
        goto after_20;
    // 0x800B28D4: div.s       $f24, $f0, $f2
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f24.fl = DIV_S(ctx->f0.fl, ctx->f2.fl);
    after_20:
    // 0x800B28D8: addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    // 0x800B28DC: addiu       $a2, $sp, 0x168
    ctx->r6 = ADD32(ctx->r29, 0X168);
    // 0x800B28E0: addiu       $a3, $sp, 0x16C
    ctx->r7 = ADD32(ctx->r29, 0X16C);
    // 0x800B28E4: lw          $a1, 0x1DC($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1DC);
    // 0x800B28E8: addiu       $v0, $sp, 0x170
    ctx->r2 = ADD32(ctx->r29, 0X170);
    // 0x800B28EC: lw          $t1, 0x10($s3)
    ctx->r9 = MEM_W(ctx->r19, 0X10);
    // 0x800B28F0: lw          $t2, 0x14($s3)
    ctx->r10 = MEM_W(ctx->r19, 0X14);
    // 0x800B28F4: lw          $t3, 0x18($s3)
    ctx->r11 = MEM_W(ctx->r19, 0X18);
    // 0x800B28F8: sw          $t1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r9;
    // 0x800B28FC: sw          $t2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r10;
    // 0x800B2900: sw          $t3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r11;
    // 0x800B2904: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // 0x800B2908: addiu       $v0, $sp, 0x175
    ctx->r2 = ADD32(ctx->r29, 0X175);
    // 0x800B290C: addiu       $s5, $s3, 0x10
    ctx->r21 = ADD32(ctx->r19, 0X10);
    // 0x800B2910: jal         0x800FEF10
    // 0x800B2914: sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    func_800FEF10(rdram, ctx);
        goto after_21;
    // 0x800B2914: sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    after_21:
    // 0x800B2918: andi        $v1, $v0, 0xFF
    ctx->r3 = ctx->r2 & 0XFF;
    // 0x800B291C: addiu       $s7, $zero, 0x1
    ctx->r23 = ADD32(0, 0X1);
    // 0x800B2920: beq         $v1, $s7, L_800B2938
    if (ctx->r3 == ctx->r23) {
        // 0x800B2924: addiu       $v0, $zero, 0x2
        ctx->r2 = ADD32(0, 0X2);
            goto L_800B2938;
    }
    // 0x800B2924: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x800B2928: beq         $v1, $v0, L_800B2D2C
    if (ctx->r3 == ctx->r2) {
        // 0x800B292C: addu        $a0, $zero, $zero
        ctx->r4 = ADD32(0, 0);
            goto L_800B2D2C;
    }
    // 0x800B292C: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x800B2930: j           L_800B2F1C
    // 0x800B2934: nop

        goto L_800B2F1C;
    // 0x800B2934: nop

L_800B2938:
    // 0x800B2938: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800B293C: sb          $zero, -0x6947($v0)
    MEM_B(-0X6947, ctx->r2) = 0;
    // 0x800B2940: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800B2944: lw          $a0, 0xB8($s3)
    ctx->r4 = MEM_W(ctx->r19, 0XB8);
    // 0x800B2948: addiu       $v0, $v0, 0xB40
    ctx->r2 = ADD32(ctx->r2, 0XB40);
    // 0x800B294C: sll         $a1, $a0, 2
    ctx->r5 = S32(ctx->r4 << 2);
    // 0x800B2950: addu        $v0, $a1, $v0
    ctx->r2 = ADD32(ctx->r5, ctx->r2);
    // 0x800B2954: lw          $v0, 0xC($v0)
    ctx->r2 = MEM_W(ctx->r2, 0XC);
    // 0x800B2958: lui         $v1, 0x80
    ctx->r3 = S32(0X80 << 16);
    // 0x800B295C: and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // 0x800B2960: bne         $v0, $zero, L_800B2F1C
    if (ctx->r2 != 0) {
        // 0x800B2964: lui         $v0, 0x8013
        ctx->r2 = S32(0X8013 << 16);
            goto L_800B2F1C;
    }
    // 0x800B2964: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800B2968: addiu       $v0, $v0, 0x7DB8
    ctx->r2 = ADD32(ctx->r2, 0X7DB8);
    // 0x800B296C: addu        $v1, $a1, $a0
    ctx->r3 = ADD32(ctx->r5, ctx->r4);
    // 0x800B2970: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x800B2974: addu        $v1, $v1, $a0
    ctx->r3 = ADD32(ctx->r3, ctx->r4);
    // 0x800B2978: sll         $v1, $v1, 5
    ctx->r3 = S32(ctx->r3 << 5);
    // 0x800B297C: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x800B2980: lhu         $v0, 0x184($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X184);
    // 0x800B2984: andi        $v0, $v0, 0x78
    ctx->r2 = ctx->r2 & 0X78;
    // 0x800B2988: bne         $v0, $zero, L_800B2F1C
    if (ctx->r2 != 0) {
        // 0x800B298C: nop
    
            goto L_800B2F1C;
    }
    // 0x800B298C: nop

    // 0x800B2990: lwc1        $f2, 0xC8($s3)
    ctx->f2.u32l = MEM_W(ctx->r19, 0XC8);
    // 0x800B2994: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800B2998: lwc1        $f4, 0xC0($s3)
    ctx->f4.u32l = MEM_W(ctx->r19, 0XC0);
    // 0x800B299C: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x800B29A0: nop

    // 0x800B29A4: bc1f        L_800B29CC
    if (!c1cs) {
        // 0x800B29A8: addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
            goto L_800B29CC;
    }
    // 0x800B29A8: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // 0x800B29AC: c.eq.s      $f2, $f20
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f2.fl == ctx->f20.fl;
    // 0x800B29B0: nop

    // 0x800B29B4: bc1f        L_800B29CC
    if (!c1cs) {
        // 0x800B29B8: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_800B29CC;
    }
    // 0x800B29B8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800B29BC: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800B29C0: lwc1        $f0, 0x5730($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X5730);
    // 0x800B29C4: sub.s       $f0, $f2, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f2.fl - ctx->f0.fl;
    // 0x800B29C8: swc1        $f0, 0xC8($s3)
    MEM_W(0XC8, ctx->r19) = ctx->f0.u32l;
L_800B29CC:
    // 0x800B29CC: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x800B29D0: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800B29D4: lwc1        $f0, 0x5734($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X5734);
    // 0x800B29D8: beql        $v0, $zero, L_800B29E8
    if (ctx->r2 == 0) {
        // 0x800B29DC: sub.s       $f2, $f4, $f0
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f4.fl - ctx->f0.fl;
            goto L_800B29E8;
    }
    goto skip_12;
    // 0x800B29DC: sub.s       $f2, $f4, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f4.fl - ctx->f0.fl;
    skip_12:
    // 0x800B29E0: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800B29E4: sub.s       $f2, $f4, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f4.fl - ctx->f0.fl;
L_800B29E8:
    // 0x800B29E8: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800B29EC: c.le.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl <= ctx->f0.fl;
    // 0x800B29F0: nop

    // 0x800B29F4: bc1f        L_800B2A70
    if (!c1cs) {
        // 0x800B29F8: swc1        $f2, 0xC0($s3)
        MEM_W(0XC0, ctx->r19) = ctx->f2.u32l;
            goto L_800B2A70;
    }
    // 0x800B29F8: swc1        $f2, 0xC0($s3)
    MEM_W(0XC0, ctx->r19) = ctx->f2.u32l;
    // 0x800B29FC: lbu         $v0, 0x175($sp)
    ctx->r2 = MEM_BU(ctx->r29, 0X175);
    // 0x800B2A00: bne         $v0, $zero, L_800B2A58
    if (ctx->r2 != 0) {
        // 0x800B2A04: addu        $a1, $v0, $zero
        ctx->r5 = ADD32(ctx->r2, 0);
            goto L_800B2A58;
    }
    // 0x800B2A04: addu        $a1, $v0, $zero
    ctx->r5 = ADD32(ctx->r2, 0);
    // 0x800B2A08: jal         0x800B01E4
    // 0x800B2A0C: addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    func_800B01E4(rdram, ctx);
        goto after_22;
    // 0x800B2A0C: addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    after_22:
    // 0x800B2A10: jal         0x80003430
    // 0x800B2A14: nop

    rand_recomp(rdram, ctx);
        goto after_23;
    // 0x800B2A14: nop

    after_23:
    // 0x800B2A18: andi        $a0, $v0, 0x3
    ctx->r4 = ctx->r2 & 0X3;
    // 0x800B2A1C: slti        $v0, $a0, 0x3
    ctx->r2 = SIGNED(ctx->r4) < 0X3 ? 1 : 0;
    // 0x800B2A20: beql        $v0, $zero, L_800B2A28
    if (ctx->r2 == 0) {
        // 0x800B2A24: addiu       $a0, $zero, 0x2
        ctx->r4 = ADD32(0, 0X2);
            goto L_800B2A28;
    }
    goto skip_13;
    // 0x800B2A24: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    skip_13:
L_800B2A28:
    // 0x800B2A28: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800B2A2C: lbu         $v1, 0xB40($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0XB40);
    // 0x800B2A30: addiu       $v0, $zero, 0xF
    ctx->r2 = ADD32(0, 0XF);
    // 0x800B2A34: beql        $v1, $v0, L_800B2A40
    if (ctx->r3 == ctx->r2) {
        // 0x800B2A38: addiu       $a0, $a0, 0x1FE
        ctx->r4 = ADD32(ctx->r4, 0X1FE);
            goto L_800B2A40;
    }
    goto skip_14;
    // 0x800B2A38: addiu       $a0, $a0, 0x1FE
    ctx->r4 = ADD32(ctx->r4, 0X1FE);
    skip_14:
    // 0x800B2A3C: addiu       $a0, $a0, 0x116
    ctx->r4 = ADD32(ctx->r4, 0X116);
L_800B2A40:
    // 0x800B2A40: addiu       $a1, $zero, 0x73
    ctx->r5 = ADD32(0, 0X73);
    // 0x800B2A44: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // 0x800B2A48: jal         0x80066EE4
    // 0x800B2A4C: addiu       $a3, $zero, 0x30
    ctx->r7 = ADD32(0, 0X30);
    func_80066EE4(rdram, ctx);
        goto after_24;
    // 0x800B2A4C: addiu       $a3, $zero, 0x30
    ctx->r7 = ADD32(0, 0X30);
    after_24:
    // 0x800B2A50: j           L_800B2A60
    // 0x800B2A54: nop

        goto L_800B2A60;
    // 0x800B2A54: nop

L_800B2A58:
    // 0x800B2A58: jal         0x800B0850
    // 0x800B2A5C: addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    func_800B0850(rdram, ctx);
        goto after_25;
    // 0x800B2A5C: addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    after_25:
L_800B2A60:
    // 0x800B2A60: jal         0x801006A8
    // 0x800B2A64: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    func_801006A8(rdram, ctx);
        goto after_26;
    // 0x800B2A64: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    after_26:
    // 0x800B2A68: j           L_800B2F1C
    // 0x800B2A6C: nop

        goto L_800B2F1C;
    // 0x800B2A6C: nop

L_800B2A70:
    // 0x800B2A70: lbu         $v0, 0x175($sp)
    ctx->r2 = MEM_BU(ctx->r29, 0X175);
    // 0x800B2A74: bne         $v0, $zero, L_800B2B40
    if (ctx->r2 != 0) {
        // 0x800B2A78: addiu       $a0, $sp, 0x28
        ctx->r4 = ADD32(ctx->r29, 0X28);
            goto L_800B2B40;
    }
    // 0x800B2A78: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    // 0x800B2A7C: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x800B2A80: addiu       $a1, $s3, 0x4
    ctx->r5 = ADD32(ctx->r19, 0X4);
    // 0x800B2A84: addiu       $a2, $s3, 0x28
    ctx->r6 = ADD32(ctx->r19, 0X28);
    // 0x800B2A88: lui         $a3, 0x41A0
    ctx->r7 = S32(0X41A0 << 16);
    // 0x800B2A8C: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800B2A90: lwc1        $f0, 0x5738($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X5738);
    // 0x800B2A94: addiu       $v0, $zero, 0x3E
    ctx->r2 = ADD32(0, 0X3E);
    // 0x800B2A98: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // 0x800B2A9C: addiu       $v0, $zero, 0x7A
    ctx->r2 = ADD32(0, 0X7A);
    // 0x800B2AA0: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x800B2AA4: addiu       $v0, $zero, 0x28
    ctx->r2 = ADD32(0, 0X28);
    // 0x800B2AA8: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x800B2AAC: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x800B2AB0: jal         0x800989D8
    // 0x800B2AB4: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    func_800989D8(rdram, ctx);
        goto after_27;
    // 0x800B2AB4: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    after_27:
    // 0x800B2AB8: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800B2ABC: lw          $v0, 0xB50($v0)
    ctx->r2 = MEM_W(ctx->r2, 0XB50);
    // 0x800B2AC0: andi        $v0, $v0, 0x60
    ctx->r2 = ctx->r2 & 0X60;
    // 0x800B2AC4: bne         $v0, $zero, L_800B2F1C
    if (ctx->r2 != 0) {
        // 0x800B2AC8: addiu       $s1, $zero, 0x7
        ctx->r17 = ADD32(0, 0X7);
            goto L_800B2F1C;
    }
    // 0x800B2AC8: addiu       $s1, $zero, 0x7
    ctx->r17 = ADD32(0, 0X7);
    // 0x800B2ACC: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800B2AD0: lw          $v0, -0x35E0($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X35E0);
    // 0x800B2AD4: bne         $v0, $zero, L_800B2F1C
    if (ctx->r2 != 0) {
        // 0x800B2AD8: nop
    
            goto L_800B2F1C;
    }
    // 0x800B2AD8: nop

    // 0x800B2ADC: lw          $v0, 0x1C4($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X1C4);
    // 0x800B2AE0: slt         $v0, $s1, $v0
    ctx->r2 = SIGNED(ctx->r17) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800B2AE4: beq         $v0, $zero, L_800B2B04
    if (ctx->r2 == 0) {
        // 0x800B2AE8: nop
    
            goto L_800B2B04;
    }
    // 0x800B2AE8: nop

    // 0x800B2AEC: lbu         $a0, 0xBB($s3)
    ctx->r4 = MEM_BU(ctx->r19, 0XBB);
    // 0x800B2AF0: jal         0x80003150
    // 0x800B2AF4: nop

    func_80003150(rdram, ctx);
        goto after_28;
    // 0x800B2AF4: nop

    after_28:
    // 0x800B2AF8: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x800B2AFC: bne         $v0, $zero, L_800B2F1C
    if (ctx->r2 != 0) {
        // 0x800B2B00: nop
    
            goto L_800B2F1C;
    }
    // 0x800B2B00: nop

L_800B2B04:
    // 0x800B2B04: lw          $a0, 0x1C0($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X1C0);
    // 0x800B2B08: addiu       $s0, $zero, -0x1
    ctx->r16 = ADD32(0, -0X1);
    // 0x800B2B0C: beql        $a0, $s0, L_800B2B20
    if (ctx->r4 == ctx->r16) {
        // 0x800B2B10: lui         $a1, 0x8011
        ctx->r5 = S32(0X8011 << 16);
            goto L_800B2B20;
    }
    goto skip_15;
    // 0x800B2B10: lui         $a1, 0x8011
    ctx->r5 = S32(0X8011 << 16);
    skip_15:
    // 0x800B2B14: jal         0x80002BA8
    // 0x800B2B18: nop

    func_80002BA8(rdram, ctx);
        goto after_29;
    // 0x800B2B18: nop

    after_29:
    // 0x800B2B1C: lui         $a1, 0x8011
    ctx->r5 = S32(0X8011 << 16);
L_800B2B20:
    // 0x800B2B20: addiu       $a1, $a1, -0x4430
    ctx->r5 = ADD32(ctx->r5, -0X4430);
    // 0x800B2B24: lbu         $a0, 0xBB($s3)
    ctx->r4 = MEM_BU(ctx->r19, 0XBB);
    // 0x800B2B28: jal         0x80002ADC
    // 0x800B2B2C: addiu       $a1, $a1, 0x54
    ctx->r5 = ADD32(ctx->r5, 0X54);
    func_80002ADC(rdram, ctx);
        goto after_30;
    // 0x800B2B2C: addiu       $a1, $a1, 0x54
    ctx->r5 = ADD32(ctx->r5, 0X54);
    after_30:
    // 0x800B2B30: beq         $v0, $s0, L_800B2F1C
    if (ctx->r2 == ctx->r16) {
        // 0x800B2B34: sw          $v0, 0x1C0($s3)
        MEM_W(0X1C0, ctx->r19) = ctx->r2;
            goto L_800B2F1C;
    }
    // 0x800B2B34: sw          $v0, 0x1C0($s3)
    MEM_W(0X1C0, ctx->r19) = ctx->r2;
    // 0x800B2B38: j           L_800B2F1C
    // 0x800B2B3C: sw          $s1, 0x1C4($s3)
    MEM_W(0X1C4, ctx->r19) = ctx->r17;
        goto L_800B2F1C;
    // 0x800B2B3C: sw          $s1, 0x1C4($s3)
    MEM_W(0X1C4, ctx->r19) = ctx->r17;
L_800B2B40:
    // 0x800B2B40: jal         0x8001CFE8
    // 0x800B2B44: addiu       $a1, $s3, 0x10
    ctx->r5 = ADD32(ctx->r19, 0X10);
    func_8001CFE8(rdram, ctx);
        goto after_31;
    // 0x800B2B44: addiu       $a1, $s3, 0x10
    ctx->r5 = ADD32(ctx->r19, 0X10);
    after_31:
    // 0x800B2B48: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800B2B4C: lwc1        $f2, 0x573C($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X573C);
    // 0x800B2B50: mov.s       $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    ctx->f4.fl = ctx->f0.fl;
    // 0x800B2B54: c.lt.s      $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f2.fl < ctx->f4.fl;
    // 0x800B2B58: nop

    // 0x800B2B5C: bc1f        L_800B2BD8
    if (!c1cs) {
        // 0x800B2B60: lui         $v0, 0x8013
        ctx->r2 = S32(0X8013 << 16);
            goto L_800B2BD8;
    }
    // 0x800B2B60: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800B2B64: lw          $v0, 0xB50($v0)
    ctx->r2 = MEM_W(ctx->r2, 0XB50);
    // 0x800B2B68: andi        $v0, $v0, 0x60
    ctx->r2 = ctx->r2 & 0X60;
    // 0x800B2B6C: bne         $v0, $zero, L_800B2CE8
    if (ctx->r2 != 0) {
        // 0x800B2B70: addiu       $s1, $zero, 0x4
        ctx->r17 = ADD32(0, 0X4);
            goto L_800B2CE8;
    }
    // 0x800B2B70: addiu       $s1, $zero, 0x4
    ctx->r17 = ADD32(0, 0X4);
    // 0x800B2B74: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800B2B78: lw          $v0, -0x35E0($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X35E0);
    // 0x800B2B7C: bne         $v0, $zero, L_800B2CEC
    if (ctx->r2 != 0) {
        // 0x800B2B80: addu        $a0, $zero, $zero
        ctx->r4 = ADD32(0, 0);
            goto L_800B2CEC;
    }
    // 0x800B2B80: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x800B2B84: lw          $v0, 0x1C4($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X1C4);
    // 0x800B2B88: slt         $v0, $s1, $v0
    ctx->r2 = SIGNED(ctx->r17) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800B2B8C: beq         $v0, $zero, L_800B2BAC
    if (ctx->r2 == 0) {
        // 0x800B2B90: nop
    
            goto L_800B2BAC;
    }
    // 0x800B2B90: nop

    // 0x800B2B94: lbu         $a0, 0xBB($s3)
    ctx->r4 = MEM_BU(ctx->r19, 0XBB);
    // 0x800B2B98: jal         0x80003150
    // 0x800B2B9C: nop

    func_80003150(rdram, ctx);
        goto after_32;
    // 0x800B2B9C: nop

    after_32:
    // 0x800B2BA0: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x800B2BA4: bne         $v0, $zero, L_800B2CEC
    if (ctx->r2 != 0) {
        // 0x800B2BA8: addu        $a0, $zero, $zero
        ctx->r4 = ADD32(0, 0);
            goto L_800B2CEC;
    }
    // 0x800B2BA8: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
L_800B2BAC:
    // 0x800B2BAC: lw          $a0, 0x1C0($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X1C0);
    // 0x800B2BB0: addiu       $s0, $zero, -0x1
    ctx->r16 = ADD32(0, -0X1);
    // 0x800B2BB4: beql        $a0, $s0, L_800B2BC8
    if (ctx->r4 == ctx->r16) {
        // 0x800B2BB8: lui         $a1, 0x8011
        ctx->r5 = S32(0X8011 << 16);
            goto L_800B2BC8;
    }
    goto skip_16;
    // 0x800B2BB8: lui         $a1, 0x8011
    ctx->r5 = S32(0X8011 << 16);
    skip_16:
    // 0x800B2BBC: jal         0x80002BA8
    // 0x800B2BC0: nop

    func_80002BA8(rdram, ctx);
        goto after_33;
    // 0x800B2BC0: nop

    after_33:
    // 0x800B2BC4: lui         $a1, 0x8011
    ctx->r5 = S32(0X8011 << 16);
L_800B2BC8:
    // 0x800B2BC8: addiu       $a1, $a1, -0x4430
    ctx->r5 = ADD32(ctx->r5, -0X4430);
    // 0x800B2BCC: lbu         $a0, 0xBB($s3)
    ctx->r4 = MEM_BU(ctx->r19, 0XBB);
    // 0x800B2BD0: j           L_800B2CD4
    // 0x800B2BD4: addiu       $a1, $a1, 0x30
    ctx->r5 = ADD32(ctx->r5, 0X30);
        goto L_800B2CD4;
    // 0x800B2BD4: addiu       $a1, $a1, 0x30
    ctx->r5 = ADD32(ctx->r5, 0X30);
L_800B2BD8:
    // 0x800B2BD8: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800B2BDC: lwc1        $f0, 0x5740($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X5740);
    // 0x800B2BE0: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x800B2BE4: nop

    // 0x800B2BE8: bc1fl       L_800B2C64
    if (!c1cs) {
        // 0x800B2BEC: lui         $v0, 0x8013
        ctx->r2 = S32(0X8013 << 16);
            goto L_800B2C64;
    }
    goto skip_17;
    // 0x800B2BEC: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    skip_17:
    // 0x800B2BF0: lw          $v0, 0xB50($v0)
    ctx->r2 = MEM_W(ctx->r2, 0XB50);
    // 0x800B2BF4: andi        $v0, $v0, 0x60
    ctx->r2 = ctx->r2 & 0X60;
    // 0x800B2BF8: bne         $v0, $zero, L_800B2CE8
    if (ctx->r2 != 0) {
        // 0x800B2BFC: addiu       $s1, $zero, 0x5
        ctx->r17 = ADD32(0, 0X5);
            goto L_800B2CE8;
    }
    // 0x800B2BFC: addiu       $s1, $zero, 0x5
    ctx->r17 = ADD32(0, 0X5);
    // 0x800B2C00: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800B2C04: lw          $v0, -0x35E0($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X35E0);
    // 0x800B2C08: bne         $v0, $zero, L_800B2CEC
    if (ctx->r2 != 0) {
        // 0x800B2C0C: addu        $a0, $zero, $zero
        ctx->r4 = ADD32(0, 0);
            goto L_800B2CEC;
    }
    // 0x800B2C0C: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x800B2C10: lw          $v0, 0x1C4($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X1C4);
    // 0x800B2C14: slt         $v0, $s1, $v0
    ctx->r2 = SIGNED(ctx->r17) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800B2C18: beq         $v0, $zero, L_800B2C38
    if (ctx->r2 == 0) {
        // 0x800B2C1C: nop
    
            goto L_800B2C38;
    }
    // 0x800B2C1C: nop

    // 0x800B2C20: lbu         $a0, 0xBB($s3)
    ctx->r4 = MEM_BU(ctx->r19, 0XBB);
    // 0x800B2C24: jal         0x80003150
    // 0x800B2C28: nop

    func_80003150(rdram, ctx);
        goto after_34;
    // 0x800B2C28: nop

    after_34:
    // 0x800B2C2C: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x800B2C30: bne         $v0, $zero, L_800B2CEC
    if (ctx->r2 != 0) {
        // 0x800B2C34: addu        $a0, $zero, $zero
        ctx->r4 = ADD32(0, 0);
            goto L_800B2CEC;
    }
    // 0x800B2C34: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
L_800B2C38:
    // 0x800B2C38: lw          $a0, 0x1C0($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X1C0);
    // 0x800B2C3C: addiu       $s0, $zero, -0x1
    ctx->r16 = ADD32(0, -0X1);
    // 0x800B2C40: beql        $a0, $s0, L_800B2C54
    if (ctx->r4 == ctx->r16) {
        // 0x800B2C44: lui         $a1, 0x8011
        ctx->r5 = S32(0X8011 << 16);
            goto L_800B2C54;
    }
    goto skip_18;
    // 0x800B2C44: lui         $a1, 0x8011
    ctx->r5 = S32(0X8011 << 16);
    skip_18:
    // 0x800B2C48: jal         0x80002BA8
    // 0x800B2C4C: nop

    func_80002BA8(rdram, ctx);
        goto after_35;
    // 0x800B2C4C: nop

    after_35:
    // 0x800B2C50: lui         $a1, 0x8011
    ctx->r5 = S32(0X8011 << 16);
L_800B2C54:
    // 0x800B2C54: addiu       $a1, $a1, -0x4430
    ctx->r5 = ADD32(ctx->r5, -0X4430);
    // 0x800B2C58: lbu         $a0, 0xBB($s3)
    ctx->r4 = MEM_BU(ctx->r19, 0XBB);
    // 0x800B2C5C: j           L_800B2CD4
    // 0x800B2C60: addiu       $a1, $a1, 0x3C
    ctx->r5 = ADD32(ctx->r5, 0X3C);
        goto L_800B2CD4;
    // 0x800B2C60: addiu       $a1, $a1, 0x3C
    ctx->r5 = ADD32(ctx->r5, 0X3C);
L_800B2C64:
    // 0x800B2C64: lw          $v0, 0xB50($v0)
    ctx->r2 = MEM_W(ctx->r2, 0XB50);
    // 0x800B2C68: andi        $v0, $v0, 0x60
    ctx->r2 = ctx->r2 & 0X60;
    // 0x800B2C6C: bne         $v0, $zero, L_800B2CE8
    if (ctx->r2 != 0) {
        // 0x800B2C70: addiu       $s1, $zero, 0x6
        ctx->r17 = ADD32(0, 0X6);
            goto L_800B2CE8;
    }
    // 0x800B2C70: addiu       $s1, $zero, 0x6
    ctx->r17 = ADD32(0, 0X6);
    // 0x800B2C74: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800B2C78: lw          $v0, -0x35E0($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X35E0);
    // 0x800B2C7C: bne         $v0, $zero, L_800B2CEC
    if (ctx->r2 != 0) {
        // 0x800B2C80: addu        $a0, $zero, $zero
        ctx->r4 = ADD32(0, 0);
            goto L_800B2CEC;
    }
    // 0x800B2C80: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x800B2C84: lw          $v0, 0x1C4($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X1C4);
    // 0x800B2C88: slt         $v0, $s1, $v0
    ctx->r2 = SIGNED(ctx->r17) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800B2C8C: beq         $v0, $zero, L_800B2CAC
    if (ctx->r2 == 0) {
        // 0x800B2C90: nop
    
            goto L_800B2CAC;
    }
    // 0x800B2C90: nop

    // 0x800B2C94: lbu         $a0, 0xBB($s3)
    ctx->r4 = MEM_BU(ctx->r19, 0XBB);
    // 0x800B2C98: jal         0x80003150
    // 0x800B2C9C: nop

    func_80003150(rdram, ctx);
        goto after_36;
    // 0x800B2C9C: nop

    after_36:
    // 0x800B2CA0: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x800B2CA4: bne         $v0, $zero, L_800B2CEC
    if (ctx->r2 != 0) {
        // 0x800B2CA8: addu        $a0, $zero, $zero
        ctx->r4 = ADD32(0, 0);
            goto L_800B2CEC;
    }
    // 0x800B2CA8: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
L_800B2CAC:
    // 0x800B2CAC: lw          $a0, 0x1C0($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X1C0);
    // 0x800B2CB0: addiu       $s0, $zero, -0x1
    ctx->r16 = ADD32(0, -0X1);
    // 0x800B2CB4: beq         $a0, $s0, L_800B2CC8
    if (ctx->r4 == ctx->r16) {
        // 0x800B2CB8: lui         $a1, 0x8011
        ctx->r5 = S32(0X8011 << 16);
            goto L_800B2CC8;
    }
    // 0x800B2CB8: lui         $a1, 0x8011
    ctx->r5 = S32(0X8011 << 16);
    // 0x800B2CBC: jal         0x80002BA8
    // 0x800B2CC0: nop

    func_80002BA8(rdram, ctx);
        goto after_37;
    // 0x800B2CC0: nop

    after_37:
    // 0x800B2CC4: lui         $a1, 0x8011
    ctx->r5 = S32(0X8011 << 16);
L_800B2CC8:
    // 0x800B2CC8: addiu       $a1, $a1, -0x4430
    ctx->r5 = ADD32(ctx->r5, -0X4430);
    // 0x800B2CCC: lbu         $a0, 0xBB($s3)
    ctx->r4 = MEM_BU(ctx->r19, 0XBB);
    // 0x800B2CD0: addiu       $a1, $a1, 0x48
    ctx->r5 = ADD32(ctx->r5, 0X48);
L_800B2CD4:
    // 0x800B2CD4: jal         0x80002ADC
    // 0x800B2CD8: nop

    func_80002ADC(rdram, ctx);
        goto after_38;
    // 0x800B2CD8: nop

    after_38:
    // 0x800B2CDC: beq         $v0, $s0, L_800B2CE8
    if (ctx->r2 == ctx->r16) {
        // 0x800B2CE0: sw          $v0, 0x1C0($s3)
        MEM_W(0X1C0, ctx->r19) = ctx->r2;
            goto L_800B2CE8;
    }
    // 0x800B2CE0: sw          $v0, 0x1C0($s3)
    MEM_W(0X1C0, ctx->r19) = ctx->r2;
    // 0x800B2CE4: sw          $s1, 0x1C4($s3)
    MEM_W(0X1C4, ctx->r19) = ctx->r17;
L_800B2CE8:
    // 0x800B2CE8: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
L_800B2CEC:
    // 0x800B2CEC: addiu       $a1, $s3, 0x4
    ctx->r5 = ADD32(ctx->r19, 0X4);
    // 0x800B2CF0: addiu       $a2, $s3, 0x28
    ctx->r6 = ADD32(ctx->r19, 0X28);
    // 0x800B2CF4: lui         $a3, 0x41C0
    ctx->r7 = S32(0X41C0 << 16);
    // 0x800B2CF8: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800B2CFC: lwc1        $f0, 0x5744($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X5744);
    // 0x800B2D00: addiu       $v0, $zero, 0xC
    ctx->r2 = ADD32(0, 0XC);
    // 0x800B2D04: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // 0x800B2D08: addiu       $v0, $zero, 0x73
    ctx->r2 = ADD32(0, 0X73);
    // 0x800B2D0C: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x800B2D10: addiu       $v0, $zero, 0x28
    ctx->r2 = ADD32(0, 0X28);
    // 0x800B2D14: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x800B2D18: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x800B2D1C: jal         0x800989D8
    // 0x800B2D20: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    func_800989D8(rdram, ctx);
        goto after_39;
    // 0x800B2D20: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    after_39:
    // 0x800B2D24: j           L_800B2F1C
    // 0x800B2D28: nop

        goto L_800B2F1C;
    // 0x800B2D28: nop

L_800B2D2C:
    // 0x800B2D2C: addiu       $s1, $s3, 0x4
    ctx->r17 = ADD32(ctx->r19, 0X4);
    // 0x800B2D30: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    // 0x800B2D34: addiu       $s0, $s3, 0x28
    ctx->r16 = ADD32(ctx->r19, 0X28);
    // 0x800B2D38: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    // 0x800B2D3C: lui         $a3, 0x41C0
    ctx->r7 = S32(0X41C0 << 16);
    // 0x800B2D40: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800B2D44: lwc1        $f0, 0x5748($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X5748);
    // 0x800B2D48: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800B2D4C: sb          $zero, -0x6947($v0)
    MEM_B(-0X6947, ctx->r2) = 0;
    // 0x800B2D50: addiu       $v0, $zero, 0x22
    ctx->r2 = ADD32(0, 0X22);
    // 0x800B2D54: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // 0x800B2D58: addiu       $v0, $zero, 0x7E
    ctx->r2 = ADD32(0, 0X7E);
    // 0x800B2D5C: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x800B2D60: addiu       $v0, $zero, 0x32
    ctx->r2 = ADD32(0, 0X32);
    // 0x800B2D64: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x800B2D68: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x800B2D6C: jal         0x800989D8
    // 0x800B2D70: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    func_800989D8(rdram, ctx);
        goto after_40;
    // 0x800B2D70: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    after_40:
    // 0x800B2D74: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800B2D78: lw          $a0, 0xB8($s3)
    ctx->r4 = MEM_W(ctx->r19, 0XB8);
    // 0x800B2D7C: addiu       $v0, $v0, 0xB40
    ctx->r2 = ADD32(ctx->r2, 0XB40);
    // 0x800B2D80: sll         $a1, $a0, 2
    ctx->r5 = S32(ctx->r4 << 2);
    // 0x800B2D84: addu        $v0, $a1, $v0
    ctx->r2 = ADD32(ctx->r5, ctx->r2);
    // 0x800B2D88: lw          $v0, 0xC($v0)
    ctx->r2 = MEM_W(ctx->r2, 0XC);
    // 0x800B2D8C: lui         $v1, 0x80
    ctx->r3 = S32(0X80 << 16);
    // 0x800B2D90: and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // 0x800B2D94: bne         $v0, $zero, L_800B2F1C
    if (ctx->r2 != 0) {
        // 0x800B2D98: lui         $v0, 0x8013
        ctx->r2 = S32(0X8013 << 16);
            goto L_800B2F1C;
    }
    // 0x800B2D98: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800B2D9C: addiu       $s2, $v0, 0x7DB8
    ctx->r18 = ADD32(ctx->r2, 0X7DB8);
    // 0x800B2DA0: addu        $v0, $a1, $a0
    ctx->r2 = ADD32(ctx->r5, ctx->r4);
    // 0x800B2DA4: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800B2DA8: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x800B2DAC: sll         $v0, $v0, 5
    ctx->r2 = S32(ctx->r2 << 5);
    // 0x800B2DB0: addu        $v0, $v0, $s2
    ctx->r2 = ADD32(ctx->r2, ctx->r18);
    // 0x800B2DB4: lhu         $v0, 0x184($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X184);
    // 0x800B2DB8: andi        $v0, $v0, 0x78
    ctx->r2 = ctx->r2 & 0X78;
    // 0x800B2DBC: bne         $v0, $zero, L_800B2F1C
    if (ctx->r2 != 0) {
        // 0x800B2DC0: nop
    
            goto L_800B2F1C;
    }
    // 0x800B2DC0: nop

    // 0x800B2DC4: lbu         $v0, 0x175($sp)
    ctx->r2 = MEM_BU(ctx->r29, 0X175);
    // 0x800B2DC8: bne         $v0, $zero, L_800B2E10
    if (ctx->r2 != 0) {
        // 0x800B2DCC: addu        $a0, $zero, $zero
        ctx->r4 = ADD32(0, 0);
            goto L_800B2E10;
    }
    // 0x800B2DCC: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x800B2DD0: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    // 0x800B2DD4: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    // 0x800B2DD8: lui         $a3, 0x41A0
    ctx->r7 = S32(0X41A0 << 16);
    // 0x800B2DDC: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800B2DE0: lwc1        $f0, 0x574C($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X574C);
    // 0x800B2DE4: addiu       $v0, $zero, 0x3E
    ctx->r2 = ADD32(0, 0X3E);
    // 0x800B2DE8: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // 0x800B2DEC: addiu       $v0, $zero, 0x7A
    ctx->r2 = ADD32(0, 0X7A);
    // 0x800B2DF0: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x800B2DF4: addiu       $v0, $zero, 0x28
    ctx->r2 = ADD32(0, 0X28);
    // 0x800B2DF8: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x800B2DFC: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x800B2E00: jal         0x800989D8
    // 0x800B2E04: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    func_800989D8(rdram, ctx);
        goto after_41;
    // 0x800B2E04: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    after_41:
    // 0x800B2E08: j           L_800B2EC0
    // 0x800B2E0C: nop

        goto L_800B2EC0;
    // 0x800B2E0C: nop

L_800B2E10:
    // 0x800B2E10: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    // 0x800B2E14: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    // 0x800B2E18: lui         $a3, 0x41C0
    ctx->r7 = S32(0X41C0 << 16);
    // 0x800B2E1C: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800B2E20: lwc1        $f0, 0x5750($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X5750);
    // 0x800B2E24: addiu       $v0, $zero, 0xC
    ctx->r2 = ADD32(0, 0XC);
    // 0x800B2E28: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // 0x800B2E2C: addiu       $v0, $zero, 0x73
    ctx->r2 = ADD32(0, 0X73);
    // 0x800B2E30: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x800B2E34: addiu       $v0, $zero, 0x28
    ctx->r2 = ADD32(0, 0X28);
    // 0x800B2E38: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x800B2E3C: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x800B2E40: jal         0x800989D8
    // 0x800B2E44: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    func_800989D8(rdram, ctx);
        goto after_42;
    // 0x800B2E44: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    after_42:
    // 0x800B2E48: lui         $a2, 0x8014
    ctx->r6 = S32(0X8014 << 16);
    // 0x800B2E4C: lwc1        $f12, 0x4($s3)
    ctx->f12.u32l = MEM_W(ctx->r19, 0X4);
    // 0x800B2E50: lwc1        $f14, 0xC($s3)
    ctx->f14.u32l = MEM_W(ctx->r19, 0XC);
    // 0x800B2E54: jal         0x800698F4
    // 0x800B2E58: addiu       $a2, $a2, -0x7FA8
    ctx->r6 = ADD32(ctx->r6, -0X7FA8);
    func_800698F4(rdram, ctx);
        goto after_43;
    // 0x800B2E58: addiu       $a2, $a2, -0x7FA8
    ctx->r6 = ADD32(ctx->r6, -0X7FA8);
    after_43:
    // 0x800B2E5C: beq         $v0, $s7, L_800B2EC0
    if (ctx->r2 == ctx->r23) {
        // 0x800B2E60: addu        $a0, $s5, $zero
        ctx->r4 = ADD32(ctx->r21, 0);
            goto L_800B2EC0;
    }
    // 0x800B2E60: addu        $a0, $s5, $zero
    ctx->r4 = ADD32(ctx->r21, 0);
    // 0x800B2E64: jal         0x8001CF58
    // 0x800B2E68: sw          $zero, 0x14($s3)
    MEM_W(0X14, ctx->r19) = 0;
    normalize_vector(rdram, ctx);
        goto after_44;
    // 0x800B2E68: sw          $zero, 0x14($s3)
    MEM_W(0X14, ctx->r19) = 0;
    after_44:
    // 0x800B2E6C: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x800B2E70: sw          $zero, 0x1C($s3)
    MEM_W(0X1C, ctx->r19) = 0;
    // 0x800B2E74: swc1        $f20, 0x20($s3)
    MEM_W(0X20, ctx->r19) = ctx->f20.u32l;
    // 0x800B2E78: jal         0x80059F10
    // 0x800B2E7C: sw          $zero, 0x24($s3)
    MEM_W(0X24, ctx->r19) = 0;
    func_80059F10(rdram, ctx);
        goto after_45;
    // 0x800B2E7C: sw          $zero, 0x24($s3)
    MEM_W(0X24, ctx->r19) = 0;
    after_45:
    // 0x800B2E80: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    // 0x800B2E84: lw          $v0, 0xB8($s3)
    ctx->r2 = MEM_W(ctx->r19, 0XB8);
    // 0x800B2E88: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x800B2E8C: sll         $a0, $v0, 2
    ctx->r4 = S32(ctx->r2 << 2);
    // 0x800B2E90: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // 0x800B2E94: sll         $a0, $a0, 2
    ctx->r4 = S32(ctx->r4 << 2);
    // 0x800B2E98: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // 0x800B2E9C: sll         $a0, $a0, 5
    ctx->r4 = S32(ctx->r4 << 5);
    // 0x800B2EA0: addiu       $v0, $s2, 0x254
    ctx->r2 = ADD32(ctx->r18, 0X254);
    // 0x800B2EA4: jal         0x80059B50
    // 0x800B2EA8: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    func_80059B50(rdram, ctx);
        goto after_46;
    // 0x800B2EA8: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    after_46:
    // 0x800B2EAC: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x800B2EB0: lui         $a1, 0x3EC0
    ctx->r5 = S32(0X3EC0 << 16);
    // 0x800B2EB4: lui         $a2, 0x3EF0
    ctx->r6 = S32(0X3EF0 << 16);
    // 0x800B2EB8: jal         0x8006C6FC
    // 0x800B2EBC: addiu       $a3, $zero, 0xC
    ctx->r7 = ADD32(0, 0XC);
    func_8006C6FC(rdram, ctx);
        goto after_47;
    // 0x800B2EBC: addiu       $a3, $zero, 0xC
    ctx->r7 = ADD32(0, 0XC);
    after_47:
L_800B2EC0:
    // 0x800B2EC0: lbu         $a1, 0x175($sp)
    ctx->r5 = MEM_BU(ctx->r29, 0X175);
    // 0x800B2EC4: jal         0x800B01E4
    // 0x800B2EC8: addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    func_800B01E4(rdram, ctx);
        goto after_48;
    // 0x800B2EC8: addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    after_48:
    // 0x800B2ECC: jal         0x80003430
    // 0x800B2ED0: nop

    rand_recomp(rdram, ctx);
        goto after_49;
    // 0x800B2ED0: nop

    after_49:
    // 0x800B2ED4: andi        $a0, $v0, 0x3
    ctx->r4 = ctx->r2 & 0X3;
    // 0x800B2ED8: slti        $v0, $a0, 0x3
    ctx->r2 = SIGNED(ctx->r4) < 0X3 ? 1 : 0;
    // 0x800B2EDC: beql        $v0, $zero, L_800B2EE4
    if (ctx->r2 == 0) {
        // 0x800B2EE0: addiu       $a0, $zero, 0x2
        ctx->r4 = ADD32(0, 0X2);
            goto L_800B2EE4;
    }
    goto skip_19;
    // 0x800B2EE0: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    skip_19:
L_800B2EE4:
    // 0x800B2EE4: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800B2EE8: lbu         $v1, 0xB40($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0XB40);
    // 0x800B2EEC: addiu       $v0, $zero, 0xF
    ctx->r2 = ADD32(0, 0XF);
    // 0x800B2EF0: beql        $v1, $v0, L_800B2EFC
    if (ctx->r3 == ctx->r2) {
        // 0x800B2EF4: addiu       $a0, $a0, 0x1FE
        ctx->r4 = ADD32(ctx->r4, 0X1FE);
            goto L_800B2EFC;
    }
    goto skip_20;
    // 0x800B2EF4: addiu       $a0, $a0, 0x1FE
    ctx->r4 = ADD32(ctx->r4, 0X1FE);
    skip_20:
    // 0x800B2EF8: addiu       $a0, $a0, 0x116
    ctx->r4 = ADD32(ctx->r4, 0X116);
L_800B2EFC:
    // 0x800B2EFC: addiu       $a1, $zero, 0x73
    ctx->r5 = ADD32(0, 0X73);
    // 0x800B2F00: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // 0x800B2F04: jal         0x80066EE4
    // 0x800B2F08: addiu       $a3, $zero, 0x30
    ctx->r7 = ADD32(0, 0X30);
    func_80066EE4(rdram, ctx);
        goto after_50;
    // 0x800B2F08: addiu       $a3, $zero, 0x30
    ctx->r7 = ADD32(0, 0X30);
    after_50:
    // 0x800B2F0C: jal         0x801006A8
    // 0x800B2F10: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    func_801006A8(rdram, ctx);
        goto after_51;
    // 0x800B2F10: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    after_51:
    // 0x800B2F14: jal         0x80059F10
    // 0x800B2F18: addiu       $a0, $s3, 0x4
    ctx->r4 = ADD32(ctx->r19, 0X4);
    func_80059F10(rdram, ctx);
        goto after_52;
    // 0x800B2F18: addiu       $a0, $s3, 0x4
    ctx->r4 = ADD32(ctx->r19, 0X4);
    after_52:
L_800B2F1C:
    // 0x800B2F1C: lwc1        $f2, 0x20($s3)
    ctx->f2.u32l = MEM_W(ctx->r19, 0X20);
    // 0x800B2F20: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800B2F24: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x800B2F28: nop

    // 0x800B2F2C: bc1f        L_800B2F50
    if (!c1cs) {
        // 0x800B2F30: andi        $v0, $fp, 0xFF
        ctx->r2 = ctx->r30 & 0XFF;
            goto L_800B2F50;
    }
    // 0x800B2F30: andi        $v0, $fp, 0xFF
    ctx->r2 = ctx->r30 & 0XFF;
    // 0x800B2F34: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800B2F38: lwc1        $f0, 0x5754($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X5754);
    // 0x800B2F3C: beql        $v0, $zero, L_800B2F50
    if (ctx->r2 == 0) {
        // 0x800B2F40: sub.s       $f24, $f0, $f24
        CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f24.fl = ctx->f0.fl - ctx->f24.fl;
            goto L_800B2F50;
    }
    goto skip_21;
    // 0x800B2F40: sub.s       $f24, $f0, $f24
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f24.fl = ctx->f0.fl - ctx->f24.fl;
    skip_21:
    // 0x800B2F44: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800B2F48: lwc1        $f0, 0x5758($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X5758);
    // 0x800B2F4C: sub.s       $f24, $f0, $f24
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f24.fl = ctx->f0.fl - ctx->f24.fl;
L_800B2F50:
    // 0x800B2F50: lwc1        $f0, 0x134($s3)
    ctx->f0.u32l = MEM_W(ctx->r19, 0X134);
    // 0x800B2F54: neg.s       $f2, $f24
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f24.fl); 
    ctx->f2.fl = -ctx->f24.fl;
    // 0x800B2F58: mul.s       $f4, $f2, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x800B2F5C: lwc1        $f10, 0x1DC($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X1DC);
    // 0x800B2F60: lbu         $v0, 0x174($sp)
    ctx->r2 = MEM_BU(ctx->r29, 0X174);
    // 0x800B2F64: mul.s       $f4, $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f4.fl, ctx->f10.fl);
    // 0x800B2F68: beq         $v0, $zero, L_800B2F90
    if (ctx->r2 == 0) {
        // 0x800B2F6C: lui         $a0, 0x8013
        ctx->r4 = S32(0X8013 << 16);
            goto L_800B2F90;
    }
    // 0x800B2F6C: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800B2F70: abs.s       $f2, $f24
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f24.fl); 
    ctx->f2.fl = fabsf(ctx->f24.fl);
    // 0x800B2F74: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800B2F78: lwc1        $f0, 0x575C($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X575C);
    // 0x800B2F7C: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x800B2F80: nop

    // 0x800B2F84: bc1tl       L_800B2F90
    if (c1cs) {
        // 0x800B2F88: swc1        $f4, 0xE0($s3)
        MEM_W(0XE0, ctx->r19) = ctx->f4.u32l;
            goto L_800B2F90;
    }
    goto skip_22;
    // 0x800B2F88: swc1        $f4, 0xE0($s3)
    MEM_W(0XE0, ctx->r19) = ctx->f4.u32l;
    skip_22:
    // 0x800B2F8C: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
L_800B2F90:
    // 0x800B2F90: lw          $v1, 0xB8($s3)
    ctx->r3 = MEM_W(ctx->r19, 0XB8);
    // 0x800B2F94: addiu       $a0, $a0, 0x7DB8
    ctx->r4 = ADD32(ctx->r4, 0X7DB8);
    // 0x800B2F98: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x800B2F9C: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800B2FA0: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800B2FA4: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800B2FA8: sll         $v0, $v0, 5
    ctx->r2 = S32(ctx->r2 << 5);
    // 0x800B2FAC: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x800B2FB0: lhu         $v0, 0x184($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X184);
    // 0x800B2FB4: andi        $v0, $v0, 0x2
    ctx->r2 = ctx->r2 & 0X2;
    // 0x800B2FB8: bnel        $v0, $zero, L_800B2FC0
    if (ctx->r2 != 0) {
        // 0x800B2FBC: swc1        $f4, 0xE0($s3)
        MEM_W(0XE0, ctx->r19) = ctx->f4.u32l;
            goto L_800B2FC0;
    }
    goto skip_23;
    // 0x800B2FBC: swc1        $f4, 0xE0($s3)
    MEM_W(0XE0, ctx->r19) = ctx->f4.u32l;
    skip_23:
L_800B2FC0:
    // 0x800B2FC0: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800B2FC4: lbu         $v0, -0x6947($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X6947);
    // 0x800B2FC8: beq         $v0, $zero, L_800B3070
    if (ctx->r2 == 0) {
        // 0x800B2FCC: addiu       $a0, $sp, 0x28
        ctx->r4 = ADD32(ctx->r29, 0X28);
            goto L_800B3070;
    }
    // 0x800B2FCC: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    // 0x800B2FD0: lwc1        $f0, 0x8($s4)
    ctx->f0.u32l = MEM_W(ctx->r20, 0X8);
    // 0x800B2FD4: swc1        $f0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f0.u32l;
    // 0x800B2FD8: lwc1        $f0, 0x14($s4)
    ctx->f0.u32l = MEM_W(ctx->r20, 0X14);
    // 0x800B2FDC: swc1        $f0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f0.u32l;
    // 0x800B2FE0: lwc1        $f0, 0x20($s4)
    ctx->f0.u32l = MEM_W(ctx->r20, 0X20);
    // 0x800B2FE4: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x800B2FE8: jal         0x800AA350
    // 0x800B2FEC: swc1        $f0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f0.u32l;
    func_800AA350(rdram, ctx);
        goto after_53;
    // 0x800B2FEC: swc1        $f0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f0.u32l;
    after_53:
    // 0x800B2FF0: lwc1        $f0, 0x8($s4)
    ctx->f0.u32l = MEM_W(ctx->r20, 0X8);
    // 0x800B2FF4: swc1        $f0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f0.u32l;
    // 0x800B2FF8: lwc1        $f0, 0x14($s4)
    ctx->f0.u32l = MEM_W(ctx->r20, 0X14);
    // 0x800B2FFC: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    // 0x800B3000: swc1        $f0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f0.u32l;
    // 0x800B3004: lwc1        $f0, 0x20($s4)
    ctx->f0.u32l = MEM_W(ctx->r20, 0X20);
    // 0x800B3008: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    // 0x800B300C: jal         0x8001CFE8
    // 0x800B3010: swc1        $f0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f0.u32l;
    func_8001CFE8(rdram, ctx);
        goto after_54;
    // 0x800B3010: swc1        $f0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f0.u32l;
    after_54:
    // 0x800B3014: jal         0x8001C400
    // 0x800B3018: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    func_8001C400(rdram, ctx);
        goto after_55;
    // 0x800B3018: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    after_55:
    // 0x800B301C: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800B3020: lwc1        $f2, 0x5760($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X5760);
    // 0x800B3024: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x800B3028: lwc1        $f6, 0x14($s3)
    ctx->f6.u32l = MEM_W(ctx->r19, 0X14);
    // 0x800B302C: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x800B3030: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800B3034: lwc1        $f4, 0x5764($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X5764);
    // 0x800B3038: c.lt.s      $f6, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f6.fl < ctx->f2.fl;
    // 0x800B303C: nop

    // 0x800B3040: bc1f        L_800B3058
    if (!c1cs) {
        // 0x800B3044: sub.s       $f4, $f4, $f0
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f4.fl - ctx->f0.fl;
            goto L_800B3058;
    }
    // 0x800B3044: sub.s       $f4, $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f4.fl - ctx->f0.fl;
    // 0x800B3048: lwc1        $f0, 0x130($s3)
    ctx->f0.u32l = MEM_W(ctx->r19, 0X130);
    // 0x800B304C: mul.s       $f0, $f4, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x800B3050: j           L_800B3064
    // 0x800B3054: nop

        goto L_800B3064;
    // 0x800B3054: nop

L_800B3058:
    // 0x800B3058: lwc1        $f2, 0x130($s3)
    ctx->f2.u32l = MEM_W(ctx->r19, 0X130);
    // 0x800B305C: neg.s       $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = -ctx->f4.fl;
    // 0x800B3060: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
L_800B3064:
    // 0x800B3064: lwc1        $f10, 0x1DC($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X1DC);
    // 0x800B3068: mul.s       $f0, $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x800B306C: swc1        $f0, 0xDC($s3)
    MEM_W(0XDC, ctx->r19) = ctx->f0.u32l;
L_800B3070:
    // 0x800B3070: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800B3074: addiu       $v0, $v0, 0xB88
    ctx->r2 = ADD32(ctx->r2, 0XB88);
    // 0x800B3078: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x800B307C: addiu       $a0, $a0, -0x41E8
    ctx->r4 = ADD32(ctx->r4, -0X41E8);
    // 0x800B3080: lw          $a1, 0xB8($s3)
    ctx->r5 = MEM_W(ctx->r19, 0XB8);
    // 0x800B3084: lwc1        $f8, 0xE0($s3)
    ctx->f8.u32l = MEM_W(ctx->r19, 0XE0);
    // 0x800B3088: sll         $v1, $a1, 1
    ctx->r3 = S32(ctx->r5 << 1);
    // 0x800B308C: addu        $v1, $v1, $a1
    ctx->r3 = ADD32(ctx->r3, ctx->r5);
    // 0x800B3090: sll         $v1, $v1, 1
    ctx->r3 = S32(ctx->r3 << 1);
    // 0x800B3094: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x800B3098: sll         $t0, $a1, 3
    ctx->r8 = S32(ctx->r5 << 3);
    // 0x800B309C: addu        $v0, $t0, $a1
    ctx->r2 = ADD32(ctx->r8, ctx->r5);
    // 0x800B30A0: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800B30A4: addu        $a3, $v0, $a0
    ctx->r7 = ADD32(ctx->r2, ctx->r4);
    // 0x800B30A8: lhu         $a2, 0x0($v1)
    ctx->r6 = MEM_HU(ctx->r3, 0X0);
    // 0x800B30AC: lhu         $v0, 0x20($a3)
    ctx->r2 = MEM_HU(ctx->r7, 0X20);
    // 0x800B30B0: and         $v0, $a2, $v0
    ctx->r2 = ctx->r6 & ctx->r2;
    // 0x800B30B4: bne         $v0, $zero, L_800B31E4
    if (ctx->r2 != 0) {
        // 0x800B30B8: add.s       $f6, $f24, $f8
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f24.fl + ctx->f8.fl;
            goto L_800B31E4;
    }
    // 0x800B30B8: add.s       $f6, $f24, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f24.fl + ctx->f8.fl;
    // 0x800B30BC: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800B30C0: addiu       $v0, $v0, 0xB40
    ctx->r2 = ADD32(ctx->r2, 0XB40);
    // 0x800B30C4: sll         $a0, $a1, 2
    ctx->r4 = S32(ctx->r5 << 2);
    // 0x800B30C8: addu        $v0, $a0, $v0
    ctx->r2 = ADD32(ctx->r4, ctx->r2);
    // 0x800B30CC: lw          $v0, 0xC($v0)
    ctx->r2 = MEM_W(ctx->r2, 0XC);
    // 0x800B30D0: lui         $v1, 0x100
    ctx->r3 = S32(0X100 << 16);
    // 0x800B30D4: and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // 0x800B30D8: beq         $v0, $zero, L_800B3280
    if (ctx->r2 == 0) {
        // 0x800B30DC: lui         $v0, 0x8013
        ctx->r2 = S32(0X8013 << 16);
            goto L_800B3280;
    }
    // 0x800B30DC: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800B30E0: addiu       $v0, $v0, 0x7DB8
    ctx->r2 = ADD32(ctx->r2, 0X7DB8);
    // 0x800B30E4: addu        $v1, $a0, $a1
    ctx->r3 = ADD32(ctx->r4, ctx->r5);
    // 0x800B30E8: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x800B30EC: addu        $v1, $v1, $a1
    ctx->r3 = ADD32(ctx->r3, ctx->r5);
    // 0x800B30F0: sll         $v1, $v1, 5
    ctx->r3 = S32(ctx->r3 << 5);
    // 0x800B30F4: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x800B30F8: lhu         $v0, 0x184($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X184);
    // 0x800B30FC: andi        $v0, $v0, 0x2
    ctx->r2 = ctx->r2 & 0X2;
    // 0x800B3100: bne         $v0, $zero, L_800B31EC
    if (ctx->r2 != 0) {
        // 0x800B3104: lui         $v0, 0x8013
        ctx->r2 = S32(0X8013 << 16);
            goto L_800B31EC;
    }
    // 0x800B3104: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800B3108: lhu         $v0, 0x6($a3)
    ctx->r2 = MEM_HU(ctx->r7, 0X6);
    // 0x800B310C: and         $v0, $a2, $v0
    ctx->r2 = ctx->r6 & ctx->r2;
    // 0x800B3110: bne         $v0, $zero, L_800B31EC
    if (ctx->r2 != 0) {
        // 0x800B3114: lui         $v0, 0x8013
        ctx->r2 = S32(0X8013 << 16);
            goto L_800B31EC;
    }
    // 0x800B3114: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800B3118: lwc1        $f10, 0x14($s4)
    ctx->f10.u32l = MEM_W(ctx->r20, 0X14);
    // 0x800B311C: abs.s       $f2, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = fabsf(ctx->f10.fl);
    // 0x800B3120: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800B3124: lwc1        $f0, 0x5768($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X5768);
    // 0x800B3128: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x800B312C: nop

    // 0x800B3130: bc1f        L_800B31E4
    if (!c1cs) {
        // 0x800B3134: lui         $v0, 0x8011
        ctx->r2 = S32(0X8011 << 16);
            goto L_800B31E4;
    }
    // 0x800B3134: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800B3138: addiu       $v0, $v0, -0x4228
    ctx->r2 = ADD32(ctx->r2, -0X4228);
    // 0x800B313C: addu        $v0, $t0, $v0
    ctx->r2 = ADD32(ctx->r8, ctx->r2);
    // 0x800B3140: lwc1        $f2, 0x4($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X4);
    // 0x800B3144: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800B3148: lwc1        $f0, 0x576C($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X576C);
    // 0x800B314C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800B3150: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x800B3154: nop

    // 0x800B3158: bc1f        L_800B3168
    if (!c1cs) {
        // 0x800B315C: nop
    
            goto L_800B3168;
    }
    // 0x800B315C: nop

    // 0x800B3160: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800B3164: lwc1        $f4, 0x5770($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X5770);
L_800B3168:
    // 0x800B3168: abs.s       $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = fabsf(ctx->f4.fl);
    // 0x800B316C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800B3170: c.eq.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl == ctx->f4.fl;
    // 0x800B3174: nop

    // 0x800B3178: bc1t        L_800B31E8
    if (c1cs) {
        // 0x800B317C: lui         $v0, 0x8013
        ctx->r2 = S32(0X8013 << 16);
            goto L_800B31E8;
    }
    // 0x800B317C: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800B3180: lwc1        $f0, 0x120($s3)
    ctx->f0.u32l = MEM_W(ctx->r19, 0X120);
    // 0x800B3184: neg.s       $f2, $f28
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f28.fl); 
    ctx->f2.fl = -ctx->f28.fl;
    // 0x800B3188: mul.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x800B318C: lwc1        $f0, 0xFC($s3)
    ctx->f0.u32l = MEM_W(ctx->r19, 0XFC);
    // 0x800B3190: c.eq.s      $f28, $f4
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f28.fl == ctx->f4.fl;
    // 0x800B3194: mul.s       $f6, $f2, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x800B3198: bc1t        L_800B31E8
    if (c1cs) {
        // 0x800B319C: nop
    
            goto L_800B31E8;
    }
    // 0x800B319C: nop

    // 0x800B31A0: sub.s       $f0, $f6, $f24
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f0.fl = ctx->f6.fl - ctx->f24.fl;
    // 0x800B31A4: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x800B31A8: lwc1        $f10, 0x1DC($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X1DC);
    // 0x800B31AC: mul.s       $f2, $f0, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x800B31B0: abs.s       $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = fabsf(ctx->f8.fl);
    // 0x800B31B4: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x800B31B8: nop

    // 0x800B31BC: bc1tl       L_800B31C4
    if (c1cs) {
        // 0x800B31C0: swc1        $f2, 0xE0($s3)
        MEM_W(0XE0, ctx->r19) = ctx->f2.u32l;
            goto L_800B31C4;
    }
    goto skip_24;
    // 0x800B31C0: swc1        $f2, 0xE0($s3)
    MEM_W(0XE0, ctx->r19) = ctx->f2.u32l;
    skip_24:
L_800B31C4:
    // 0x800B31C4: lwc1        $f10, 0xE0($s3)
    ctx->f10.u32l = MEM_W(ctx->r19, 0XE0);
    // 0x800B31C8: abs.s       $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = fabsf(ctx->f10.fl);
    // 0x800B31CC: c.lt.s      $f6, $f24
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 24);
    c1cs = ctx->f6.fl < ctx->f24.fl;
    // 0x800B31D0: nop

    // 0x800B31D4: bc1f        L_800B31E4
    if (!c1cs) {
        // 0x800B31D8: swc1        $f0, 0xE0($s3)
        MEM_W(0XE0, ctx->r19) = ctx->f0.u32l;
            goto L_800B31E4;
    }
    // 0x800B31D8: swc1        $f0, 0xE0($s3)
    MEM_W(0XE0, ctx->r19) = ctx->f0.u32l;
    // 0x800B31DC: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
    // 0x800B31E0: swc1        $f0, 0xE0($s3)
    MEM_W(0XE0, ctx->r19) = ctx->f0.u32l;
L_800B31E4:
    // 0x800B31E4: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
L_800B31E8:
    // 0x800B31E8: lw          $a1, 0xB8($s3)
    ctx->r5 = MEM_W(ctx->r19, 0XB8);
L_800B31EC:
    // 0x800B31EC: addiu       $v0, $v0, 0xB40
    ctx->r2 = ADD32(ctx->r2, 0XB40);
    // 0x800B31F0: sll         $a0, $a1, 2
    ctx->r4 = S32(ctx->r5 << 2);
    // 0x800B31F4: addu        $v0, $a0, $v0
    ctx->r2 = ADD32(ctx->r4, ctx->r2);
    // 0x800B31F8: lw          $v0, 0xC($v0)
    ctx->r2 = MEM_W(ctx->r2, 0XC);
    // 0x800B31FC: lui         $v1, 0x100
    ctx->r3 = S32(0X100 << 16);
    // 0x800B3200: and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // 0x800B3204: beq         $v0, $zero, L_800B3280
    if (ctx->r2 == 0) {
        // 0x800B3208: lui         $v0, 0x8013
        ctx->r2 = S32(0X8013 << 16);
            goto L_800B3280;
    }
    // 0x800B3208: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800B320C: addiu       $v0, $v0, 0x7DB8
    ctx->r2 = ADD32(ctx->r2, 0X7DB8);
    // 0x800B3210: addu        $v1, $a0, $a1
    ctx->r3 = ADD32(ctx->r4, ctx->r5);
    // 0x800B3214: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x800B3218: addu        $v1, $v1, $a1
    ctx->r3 = ADD32(ctx->r3, ctx->r5);
    // 0x800B321C: sll         $v1, $v1, 5
    ctx->r3 = S32(ctx->r3 << 5);
    // 0x800B3220: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x800B3224: lhu         $v0, 0x184($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X184);
    // 0x800B3228: andi        $v0, $v0, 0x2
    ctx->r2 = ctx->r2 & 0X2;
    // 0x800B322C: bne         $v0, $zero, L_800B334C
    if (ctx->r2 != 0) {
        // 0x800B3230: lui         $v0, 0x8013
        ctx->r2 = S32(0X8013 << 16);
            goto L_800B334C;
    }
    // 0x800B3230: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800B3234: addiu       $v0, $v0, 0xB88
    ctx->r2 = ADD32(ctx->r2, 0XB88);
    // 0x800B3238: sll         $v1, $a1, 1
    ctx->r3 = S32(ctx->r5 << 1);
    // 0x800B323C: addu        $v1, $v1, $a1
    ctx->r3 = ADD32(ctx->r3, ctx->r5);
    // 0x800B3240: sll         $v1, $v1, 1
    ctx->r3 = S32(ctx->r3 << 1);
    // 0x800B3244: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x800B3248: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x800B324C: addiu       $a0, $a0, -0x41E8
    ctx->r4 = ADD32(ctx->r4, -0X41E8);
    // 0x800B3250: sll         $v0, $a1, 3
    ctx->r2 = S32(ctx->r5 << 3);
    // 0x800B3254: addu        $v0, $v0, $a1
    ctx->r2 = ADD32(ctx->r2, ctx->r5);
    // 0x800B3258: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800B325C: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x800B3260: lhu         $v1, 0x0($v1)
    ctx->r3 = MEM_HU(ctx->r3, 0X0);
    // 0x800B3264: lhu         $v0, 0x20($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X20);
    // 0x800B3268: and         $v1, $v1, $v0
    ctx->r3 = ctx->r3 & ctx->r2;
    // 0x800B326C: bne         $v1, $zero, L_800B334C
    if (ctx->r3 != 0) {
        // 0x800B3270: nop
    
            goto L_800B334C;
    }
    // 0x800B3270: nop

    // 0x800B3274: lbu         $v0, 0x174($sp)
    ctx->r2 = MEM_BU(ctx->r29, 0X174);
    // 0x800B3278: bne         $v0, $zero, L_800B334C
    if (ctx->r2 != 0) {
        // 0x800B327C: nop
    
            goto L_800B334C;
    }
    // 0x800B327C: nop

L_800B3280:
    // 0x800B3280: abs.s       $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = fabsf(ctx->f6.fl);
    // 0x800B3284: lwc1        $f0, 0x120($s3)
    ctx->f0.u32l = MEM_W(ctx->r19, 0X120);
    // 0x800B3288: c.le.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl <= ctx->f2.fl;
    // 0x800B328C: nop

    // 0x800B3290: bc1f        L_800B334C
    if (!c1cs) {
        // 0x800B3294: andi        $v0, $fp, 0xFF
        ctx->r2 = ctx->r30 & 0XFF;
            goto L_800B334C;
    }
    // 0x800B3294: andi        $v0, $fp, 0xFF
    ctx->r2 = ctx->r30 & 0XFF;
    // 0x800B3298: beq         $v0, $zero, L_800B32BC
    if (ctx->r2 == 0) {
        // 0x800B329C: nop
    
            goto L_800B32BC;
    }
    // 0x800B329C: nop

    // 0x800B32A0: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800B32A4: c.lt.s      $f28, $f0
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f28.fl < ctx->f0.fl;
    // 0x800B32A8: nop

    // 0x800B32AC: bc1t        L_800B32D0
    if (c1cs) {
        // 0x800B32B0: lui         $v1, 0x8013
        ctx->r3 = S32(0X8013 << 16);
            goto L_800B32D0;
    }
    // 0x800B32B0: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x800B32B4: j           L_800B334C
    // 0x800B32B8: nop

        goto L_800B334C;
    // 0x800B32B8: nop

L_800B32BC:
    // 0x800B32BC: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800B32C0: c.lt.s      $f0, $f28
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 28);
    c1cs = ctx->f0.fl < ctx->f28.fl;
    // 0x800B32C4: nop

    // 0x800B32C8: bc1f        L_800B334C
    if (!c1cs) {
        // 0x800B32CC: lui         $v1, 0x8013
        ctx->r3 = S32(0X8013 << 16);
            goto L_800B334C;
    }
    // 0x800B32CC: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
L_800B32D0:
    // 0x800B32D0: lw          $v0, 0xB8($s3)
    ctx->r2 = MEM_W(ctx->r19, 0XB8);
    // 0x800B32D4: addiu       $v1, $v1, 0xB40
    ctx->r3 = ADD32(ctx->r3, 0XB40);
    // 0x800B32D8: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800B32DC: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800B32E0: lw          $v0, 0xC($v0)
    ctx->r2 = MEM_W(ctx->r2, 0XC);
    // 0x800B32E4: lui         $v1, 0x100
    ctx->r3 = S32(0X100 << 16);
    // 0x800B32E8: and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // 0x800B32EC: beq         $v0, $zero, L_800B3314
    if (ctx->r2 == 0) {
        // 0x800B32F0: andi        $v0, $fp, 0xFF
        ctx->r2 = ctx->r30 & 0XFF;
            goto L_800B3314;
    }
    // 0x800B32F0: andi        $v0, $fp, 0xFF
    ctx->r2 = ctx->r30 & 0XFF;
    // 0x800B32F4: lwc1        $f10, 0x14($s4)
    ctx->f10.u32l = MEM_W(ctx->r20, 0X14);
    // 0x800B32F8: abs.s       $f2, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = fabsf(ctx->f10.fl);
    // 0x800B32FC: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800B3300: lwc1        $f0, 0x5774($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X5774);
    // 0x800B3304: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x800B3308: nop

    // 0x800B330C: bc1f        L_800B334C
    if (!c1cs) {
        // 0x800B3310: nop
    
            goto L_800B334C;
    }
    // 0x800B3310: nop

L_800B3314:
    // 0x800B3314: beq         $v0, $zero, L_800B3330
    if (ctx->r2 == 0) {
        // 0x800B3318: nop
    
            goto L_800B3330;
    }
    // 0x800B3318: nop

    // 0x800B331C: abs.s       $f2, $f24
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f24.fl); 
    ctx->f2.fl = fabsf(ctx->f24.fl);
    // 0x800B3320: lwc1        $f0, 0x120($s3)
    ctx->f0.u32l = MEM_W(ctx->r19, 0X120);
    // 0x800B3324: lwc1        $f10, 0x1DC($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X1DC);
    // 0x800B3328: j           L_800B3344
    // 0x800B332C: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
        goto L_800B3344;
    // 0x800B332C: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
L_800B3330:
    // 0x800B3330: abs.s       $f2, $f24
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f24.fl); 
    ctx->f2.fl = fabsf(ctx->f24.fl);
    // 0x800B3334: lwc1        $f0, 0x120($s3)
    ctx->f0.u32l = MEM_W(ctx->r19, 0X120);
    // 0x800B3338: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x800B333C: lwc1        $f10, 0x1DC($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X1DC);
    // 0x800B3340: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
L_800B3344:
    // 0x800B3344: mul.s       $f0, $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x800B3348: swc1        $f0, 0xE0($s3)
    MEM_W(0XE0, ctx->r19) = ctx->f0.u32l;
L_800B334C:
    // 0x800B334C: lwc1        $f10, 0xD8($s3)
    ctx->f10.u32l = MEM_W(ctx->r19, 0XD8);
    // 0x800B3350: abs.s       $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = fabsf(ctx->f10.fl);
    // 0x800B3354: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800B3358: lwc1        $f2, 0x5778($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X5778);
    // 0x800B335C: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x800B3360: nop

    // 0x800B3364: bc1tl       L_800B336C
    if (c1cs) {
        // 0x800B3368: sw          $zero, 0xD8($s3)
        MEM_W(0XD8, ctx->r19) = 0;
            goto L_800B336C;
    }
    goto skip_25;
    // 0x800B3368: sw          $zero, 0xD8($s3)
    MEM_W(0XD8, ctx->r19) = 0;
    skip_25:
L_800B336C:
    // 0x800B336C: lwc1        $f10, 0xDC($s3)
    ctx->f10.u32l = MEM_W(ctx->r19, 0XDC);
    // 0x800B3370: abs.s       $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = fabsf(ctx->f10.fl);
    // 0x800B3374: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x800B3378: nop

    // 0x800B337C: bc1tl       L_800B3384
    if (c1cs) {
        // 0x800B3380: sw          $zero, 0xDC($s3)
        MEM_W(0XDC, ctx->r19) = 0;
            goto L_800B3384;
    }
    goto skip_26;
    // 0x800B3380: sw          $zero, 0xDC($s3)
    MEM_W(0XDC, ctx->r19) = 0;
    skip_26:
L_800B3384:
    // 0x800B3384: lwc1        $f10, 0xE0($s3)
    ctx->f10.u32l = MEM_W(ctx->r19, 0XE0);
    // 0x800B3388: abs.s       $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = fabsf(ctx->f10.fl);
    // 0x800B338C: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x800B3390: nop

    // 0x800B3394: bc1tl       L_800B339C
    if (c1cs) {
        // 0x800B3398: sw          $zero, 0xE0($s3)
        MEM_W(0XE0, ctx->r19) = 0;
            goto L_800B339C;
    }
    goto skip_27;
    // 0x800B3398: sw          $zero, 0xE0($s3)
    MEM_W(0XE0, ctx->r19) = 0;
    skip_27:
L_800B339C:
    // 0x800B339C: lwc1        $f12, 0x16C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X16C);
    // 0x800B33A0: lwc1        $f0, 0xD8($s3)
    ctx->f0.u32l = MEM_W(ctx->r19, 0XD8);
    // 0x800B33A4: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800B33A8: lwc1        $f20, 0x577C($at)
    ctx->f20.u32l = MEM_W(ctx->r1, 0X577C);
    // 0x800B33AC: add.s       $f12, $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = ctx->f12.fl + ctx->f0.fl;
    // 0x800B33B0: mov.s       $f14, $f20
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 20);
    ctx->f14.fl = ctx->f20.fl;
    // 0x800B33B4: jal         0x8001E20C
    // 0x800B33B8: swc1        $f12, 0xCC($s3)
    MEM_W(0XCC, ctx->r19) = ctx->f12.u32l;
    func_8001E20C(rdram, ctx);
        goto after_56;
    // 0x800B33B8: swc1        $f12, 0xCC($s3)
    MEM_W(0XCC, ctx->r19) = ctx->f12.u32l;
    after_56:
    // 0x800B33BC: lwc1        $f12, 0x168($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X168);
    // 0x800B33C0: lwc1        $f0, 0xDC($s3)
    ctx->f0.u32l = MEM_W(ctx->r19, 0XDC);
    // 0x800B33C4: add.s       $f12, $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = ctx->f12.fl + ctx->f0.fl;
    // 0x800B33C8: mov.s       $f14, $f20
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 20);
    ctx->f14.fl = ctx->f20.fl;
    // 0x800B33CC: jal         0x8001E20C
    // 0x800B33D0: swc1        $f12, 0xD0($s3)
    MEM_W(0XD0, ctx->r19) = ctx->f12.u32l;
    func_8001E20C(rdram, ctx);
        goto after_57;
    // 0x800B33D0: swc1        $f12, 0xD0($s3)
    MEM_W(0XD0, ctx->r19) = ctx->f12.u32l;
    after_57:
    // 0x800B33D4: lwc1        $f12, 0x170($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X170);
    // 0x800B33D8: lwc1        $f0, 0xE0($s3)
    ctx->f0.u32l = MEM_W(ctx->r19, 0XE0);
    // 0x800B33DC: add.s       $f12, $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = ctx->f12.fl + ctx->f0.fl;
    // 0x800B33E0: mov.s       $f14, $f20
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 20);
    ctx->f14.fl = ctx->f20.fl;
    // 0x800B33E4: jal         0x8001E20C
    // 0x800B33E8: swc1        $f12, 0xD4($s3)
    MEM_W(0XD4, ctx->r19) = ctx->f12.u32l;
    func_8001E20C(rdram, ctx);
        goto after_58;
    // 0x800B33E8: swc1        $f12, 0xD4($s3)
    MEM_W(0XD4, ctx->r19) = ctx->f12.u32l;
    after_58:
    // 0x800B33EC: lwc1        $f0, 0x8($s4)
    ctx->f0.u32l = MEM_W(ctx->r20, 0X8);
    // 0x800B33F0: swc1        $f0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f0.u32l;
    // 0x800B33F4: lwc1        $f0, 0x14($s4)
    ctx->f0.u32l = MEM_W(ctx->r20, 0X14);
    // 0x800B33F8: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    // 0x800B33FC: swc1        $f0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f0.u32l;
    // 0x800B3400: lwc1        $f2, 0x20($s4)
    ctx->f2.u32l = MEM_W(ctx->r20, 0X20);
    // 0x800B3404: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800B3408: lwc1        $f0, 0x5780($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X5780);
    // 0x800B340C: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    // 0x800B3410: sw          $zero, 0x38($sp)
    MEM_W(0X38, ctx->r29) = 0;
    // 0x800B3414: sw          $zero, 0x40($sp)
    MEM_W(0X40, ctx->r29) = 0;
    // 0x800B3418: swc1        $f0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f0.u32l;
    // 0x800B341C: jal         0x8001CFE8
    // 0x800B3420: swc1        $f2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f2.u32l;
    func_8001CFE8(rdram, ctx);
        goto after_59;
    // 0x800B3420: swc1        $f2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f2.u32l;
    after_59:
    // 0x800B3424: jal         0x8001C400
    // 0x800B3428: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    func_8001C400(rdram, ctx);
        goto after_60;
    // 0x800B3428: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    after_60:
    // 0x800B342C: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800B3430: lwc1        $f2, 0x5784($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X5784);
    // 0x800B3434: mul.s       $f4, $f0, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x800B3438: lwc1        $f0, 0x124($s3)
    ctx->f0.u32l = MEM_W(ctx->r19, 0X124);
    // 0x800B343C: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x800B3440: nop

    // 0x800B3444: bc1fl       L_800B3478
    if (!c1cs) {
        // 0x800B3448: neg.s       $f0, $f0
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
            goto L_800B3478;
    }
    goto skip_28;
    // 0x800B3448: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
    skip_28:
    // 0x800B344C: lwc1        $f0, 0xDC($s3)
    ctx->f0.u32l = MEM_W(ctx->r19, 0XDC);
    // 0x800B3450: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x800B3454: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x800B3458: nop

    // 0x800B345C: bc1f        L_800B3470
    if (!c1cs) {
        // 0x800B3460: nop
    
            goto L_800B3470;
    }
    // 0x800B3460: nop

    // 0x800B3464: lwc1        $f0, 0x168($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X168);
    // 0x800B3468: swc1        $f2, 0xDC($s3)
    MEM_W(0XDC, ctx->r19) = ctx->f2.u32l;
    // 0x800B346C: swc1        $f0, 0xD0($s3)
    MEM_W(0XD0, ctx->r19) = ctx->f0.u32l;
L_800B3470:
    // 0x800B3470: lwc1        $f0, 0x124($s3)
    ctx->f0.u32l = MEM_W(ctx->r19, 0X124);
    // 0x800B3474: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
L_800B3478:
    // 0x800B3478: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x800B347C: nop

    // 0x800B3480: bc1f        L_800B34AC
    if (!c1cs) {
        // 0x800B3484: nop
    
            goto L_800B34AC;
    }
    // 0x800B3484: nop

    // 0x800B3488: lwc1        $f0, 0xDC($s3)
    ctx->f0.u32l = MEM_W(ctx->r19, 0XDC);
    // 0x800B348C: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x800B3490: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x800B3494: nop

    // 0x800B3498: bc1f        L_800B34AC
    if (!c1cs) {
        // 0x800B349C: nop
    
            goto L_800B34AC;
    }
    // 0x800B349C: nop

    // 0x800B34A0: lwc1        $f0, 0x168($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X168);
    // 0x800B34A4: swc1        $f2, 0xDC($s3)
    MEM_W(0XDC, ctx->r19) = ctx->f2.u32l;
    // 0x800B34A8: swc1        $f0, 0xD0($s3)
    MEM_W(0XD0, ctx->r19) = ctx->f0.u32l;
L_800B34AC:
    // 0x800B34AC: lhu         $v1, 0xB4($s3)
    ctx->r3 = MEM_HU(ctx->r19, 0XB4);
    // 0x800B34B0: sltiu       $v0, $v1, 0x9
    ctx->r2 = ctx->r3 < 0X9 ? 1 : 0;
    // 0x800B34B4: beq         $v0, $zero, L_800B34F0
    if (ctx->r2 == 0) {
        // 0x800B34B8: lui         $v0, 0x800A
        ctx->r2 = S32(0X800A << 16);
            goto L_800B34F0;
    }
    // 0x800B34B8: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x800B34BC: addiu       $v0, $v0, 0x5788
    ctx->r2 = ADD32(ctx->r2, 0X5788);
    // 0x800B34C0: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x800B34C4: addu        $v1, $v1, $v0
    gpr jr_addend_800B34CC = ctx->r3;
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x800B34C8: lw          $v0, 0x0($v1)
    ctx->r2 = ADD32(ctx->r3, 0X0);
    // 0x800B34CC: jr          $v0
    // 0x800B34D0: nop

    switch (jr_addend_800B34CC >> 2) {
        case 0: goto L_800B34F0; break;
        case 1: goto L_800B34F0; break;
        case 2: goto L_800B34F0; break;
        case 3: goto L_800B34D4; break;
        case 4: goto L_800B34D4; break;
        case 5: goto L_800B34F0; break;
        case 6: goto L_800B34F0; break;
        case 7: goto L_800B34F0; break;
        case 8: goto L_800B34F0; break;
        default: switch_error(__func__, 0x800B34CC, 0x800A5788);
    }
    // 0x800B34D0: nop

L_800B34D4:
    // 0x800B34D4: addu        $a0, $s4, $zero
    ctx->r4 = ADD32(ctx->r20, 0);
    // 0x800B34D8: lw          $a1, 0xCC($s3)
    ctx->r5 = MEM_W(ctx->r19, 0XCC);
    // 0x800B34DC: lw          $a2, 0xD0($s3)
    ctx->r6 = MEM_W(ctx->r19, 0XD0);
    // 0x800B34E0: jal         0x800AA570
    // 0x800B34E4: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    func_800AA570(rdram, ctx);
        goto after_61;
    // 0x800B34E4: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    after_61:
    // 0x800B34E8: j           L_800B3518
    // 0x800B34EC: nop

        goto L_800B3518;
    // 0x800B34EC: nop

L_800B34F0:
    // 0x800B34F0: addiu       $s0, $sp, 0x58
    ctx->r16 = ADD32(ctx->r29, 0X58);
    // 0x800B34F4: lw          $a1, 0xD8($s3)
    ctx->r5 = MEM_W(ctx->r19, 0XD8);
    // 0x800B34F8: lw          $a2, 0xDC($s3)
    ctx->r6 = MEM_W(ctx->r19, 0XDC);
    // 0x800B34FC: lw          $a3, 0xE0($s3)
    ctx->r7 = MEM_W(ctx->r19, 0XE0);
    // 0x800B3500: jal         0x800AA570
    // 0x800B3504: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_800AA570(rdram, ctx);
        goto after_62;
    // 0x800B3504: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_62:
    // 0x800B3508: addu        $a0, $s4, $zero
    ctx->r4 = ADD32(ctx->r20, 0);
    // 0x800B350C: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x800B3510: jal         0x800191C4
    // 0x800B3514: addu        $a2, $s4, $zero
    ctx->r6 = ADD32(ctx->r20, 0);
    func_800191C4(rdram, ctx);
        goto after_63;
    // 0x800B3514: addu        $a2, $s4, $zero
    ctx->r6 = ADD32(ctx->r20, 0);
    after_63:
L_800B3518:
    // 0x800B3518: lhu         $v1, 0xB4($s3)
    ctx->r3 = MEM_HU(ctx->r19, 0XB4);
    // 0x800B351C: slti        $v0, $v1, 0x5
    ctx->r2 = SIGNED(ctx->r3) < 0X5 ? 1 : 0;
    // 0x800B3520: beq         $v0, $zero, L_800B3558
    if (ctx->r2 == 0) {
        // 0x800B3524: slti        $v0, $v1, 0x3
        ctx->r2 = SIGNED(ctx->r3) < 0X3 ? 1 : 0;
            goto L_800B3558;
    }
    // 0x800B3524: slti        $v0, $v1, 0x3
    ctx->r2 = SIGNED(ctx->r3) < 0X3 ? 1 : 0;
    // 0x800B3528: bne         $v0, $zero, L_800B3558
    if (ctx->r2 != 0) {
        // 0x800B352C: addiu       $s0, $sp, 0x58
        ctx->r16 = ADD32(ctx->r29, 0X58);
            goto L_800B3558;
    }
    // 0x800B352C: addiu       $s0, $sp, 0x58
    ctx->r16 = ADD32(ctx->r29, 0X58);
    // 0x800B3530: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800B3534: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x800B3538: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x800B353C: lw          $a3, 0xD4($s3)
    ctx->r7 = MEM_W(ctx->r19, 0XD4);
    // 0x800B3540: jal         0x800AA570
    // 0x800B3544: addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    func_800AA570(rdram, ctx);
        goto after_64;
    // 0x800B3544: addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    after_64:
    // 0x800B3548: addu        $a0, $s4, $zero
    ctx->r4 = ADD32(ctx->r20, 0);
    // 0x800B354C: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x800B3550: jal         0x800191C4
    // 0x800B3554: addu        $a2, $s4, $zero
    ctx->r6 = ADD32(ctx->r20, 0);
    func_800191C4(rdram, ctx);
        goto after_65;
    // 0x800B3554: addu        $a2, $s4, $zero
    ctx->r6 = ADD32(ctx->r20, 0);
    after_65:
L_800B3558:
    // 0x800B3558: lwc1        $f0, 0x8($s4)
    ctx->f0.u32l = MEM_W(ctx->r20, 0X8);
    // 0x800B355C: swc1        $f0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f0.u32l;
    // 0x800B3560: lwc1        $f0, 0x14($s4)
    ctx->f0.u32l = MEM_W(ctx->r20, 0X14);
    // 0x800B3564: swc1        $f0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f0.u32l;
    // 0x800B3568: lwc1        $f0, 0x20($s4)
    ctx->f0.u32l = MEM_W(ctx->r20, 0X20);
    // 0x800B356C: addiu       $a0, $sp, 0x48
    ctx->r4 = ADD32(ctx->r29, 0X48);
    // 0x800B3570: jal         0x800AA350
    // 0x800B3574: swc1        $f0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f0.u32l;
    func_800AA350(rdram, ctx);
        goto after_66;
    // 0x800B3574: swc1        $f0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f0.u32l;
    after_66:
    // 0x800B3578: lwc1        $f0, 0xE8($s3)
    ctx->f0.u32l = MEM_W(ctx->r19, 0XE8);
    // 0x800B357C: lwc1        $f2, 0x48($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X48);
    // 0x800B3580: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x800B3584: swc1        $f0, 0x24($s6)
    MEM_W(0X24, ctx->r22) = ctx->f0.u32l;
    // 0x800B3588: lwc1        $f0, 0xE8($s3)
    ctx->f0.u32l = MEM_W(ctx->r19, 0XE8);
    // 0x800B358C: lwc1        $f2, 0x4C($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x800B3590: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x800B3594: swc1        $f0, 0x28($s6)
    MEM_W(0X28, ctx->r22) = ctx->f0.u32l;
    // 0x800B3598: lwc1        $f2, 0xE8($s3)
    ctx->f2.u32l = MEM_W(ctx->r19, 0XE8);
    // 0x800B359C: lwc1        $f0, 0x50($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X50);
    // 0x800B35A0: mul.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x800B35A4: addu        $a0, $s6, $zero
    ctx->r4 = ADD32(ctx->r22, 0);
    // 0x800B35A8: lw          $a1, 0x1DC($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1DC);
    // 0x800B35AC: swc1        $f2, 0x2C($s6)
    MEM_W(0X2C, ctx->r22) = ctx->f2.u32l;
    // 0x800B35B0: lw          $t1, 0x48($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X48);
    // 0x800B35B4: lw          $t2, 0x4C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X4C);
    // 0x800B35B8: lw          $t3, 0x50($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X50);
    // 0x800B35BC: sw          $t1, 0xC($s6)
    MEM_W(0XC, ctx->r22) = ctx->r9;
    // 0x800B35C0: sw          $t2, 0x10($s6)
    MEM_W(0X10, ctx->r22) = ctx->r10;
    // 0x800B35C4: sw          $t3, 0x14($s6)
    MEM_W(0X14, ctx->r22) = ctx->r11;
    // 0x800B35C8: jal         0x800AA6D0
    // 0x800B35CC: addiu       $a2, $s3, 0x34
    ctx->r6 = ADD32(ctx->r19, 0X34);
    func_800AA6D0(rdram, ctx);
        goto after_67;
    // 0x800B35CC: addiu       $a2, $s3, 0x34
    ctx->r6 = ADD32(ctx->r19, 0X34);
    after_67:
    // 0x800B35D0: addu        $a0, $s6, $zero
    ctx->r4 = ADD32(ctx->r22, 0);
    // 0x800B35D4: addu        $a1, $s6, $zero
    ctx->r5 = ADD32(ctx->r22, 0);
    // 0x800B35D8: lw          $a2, 0x1DC($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1DC);
    // 0x800B35DC: jal         0x800AA3E0
    // 0x800B35E0: addiu       $a3, $s6, 0x24
    ctx->r7 = ADD32(ctx->r22, 0X24);
    func_800AA3E0(rdram, ctx);
        goto after_68;
    // 0x800B35E0: addiu       $a3, $s6, 0x24
    ctx->r7 = ADD32(ctx->r22, 0X24);
    after_68:
    // 0x800B35E4: lwc1        $f0, 0x4($s4)
    ctx->f0.u32l = MEM_W(ctx->r20, 0X4);
    // 0x800B35E8: swc1        $f0, 0x18($s6)
    MEM_W(0X18, ctx->r22) = ctx->f0.u32l;
    // 0x800B35EC: lwc1        $f0, 0x10($s4)
    ctx->f0.u32l = MEM_W(ctx->r20, 0X10);
    // 0x800B35F0: swc1        $f0, 0x1C($s6)
    MEM_W(0X1C, ctx->r22) = ctx->f0.u32l;
    // 0x800B35F4: lwc1        $f0, 0x1C($s4)
    ctx->f0.u32l = MEM_W(ctx->r20, 0X1C);
    // 0x800B35F8: swc1        $f0, 0x20($s6)
    MEM_W(0X20, ctx->r22) = ctx->f0.u32l;
    // 0x800B35FC: lw          $v1, 0xB8($s3)
    ctx->r3 = MEM_W(ctx->r19, 0XB8);
    // 0x800B3600: lwc1        $f0, 0x4($s3)
    ctx->f0.u32l = MEM_W(ctx->r19, 0X4);
    // 0x800B3604: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x800B3608: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800B360C: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800B3610: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800B3614: sll         $v0, $v0, 5
    ctx->r2 = S32(ctx->r2 << 5);
    // 0x800B3618: lui         $v1, 0x8014
    ctx->r3 = S32(0X8014 << 16);
    // 0x800B361C: addiu       $v1, $v1, -0x7FF4
    ctx->r3 = ADD32(ctx->r3, -0X7FF4);
    // 0x800B3620: addu        $s0, $v0, $v1
    ctx->r16 = ADD32(ctx->r2, ctx->r3);
    // 0x800B3624: swc1        $f0, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f0.u32l;
    // 0x800B3628: lwc1        $f0, 0x8($s3)
    ctx->f0.u32l = MEM_W(ctx->r19, 0X8);
    // 0x800B362C: swc1        $f0, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->f0.u32l;
    // 0x800B3630: lwc1        $f0, 0xC($s3)
    ctx->f0.u32l = MEM_W(ctx->r19, 0XC);
    // 0x800B3634: swc1        $f0, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f0.u32l;
    // 0x800B3638: lhu         $v1, 0xB4($s3)
    ctx->r3 = MEM_HU(ctx->r19, 0XB4);
    // 0x800B363C: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
    // 0x800B3640: lui         $a1, 0x3C4C
    ctx->r5 = S32(0X3C4C << 16);
    // 0x800B3644: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    // 0x800B3648: bne         $v1, $v0, L_800B3658
    if (ctx->r3 != ctx->r2) {
        // 0x800B364C: addiu       $a0, $sp, 0xD8
        ctx->r4 = ADD32(ctx->r29, 0XD8);
            goto L_800B3658;
    }
    // 0x800B364C: addiu       $a0, $sp, 0xD8
    ctx->r4 = ADD32(ctx->r29, 0XD8);
    // 0x800B3650: lui         $a1, 0x3CB3
    ctx->r5 = S32(0X3CB3 << 16);
    // 0x800B3654: ori         $a1, $a1, 0x3333
    ctx->r5 = ctx->r5 | 0X3333;
L_800B3658:
    // 0x800B3658: addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    // 0x800B365C: jal         0x8001CB64
    // 0x800B3660: addu        $a3, $a1, $zero
    ctx->r7 = ADD32(ctx->r5, 0);
    func_8001CB64(rdram, ctx);
        goto after_69;
    // 0x800B3660: addu        $a3, $a1, $zero
    ctx->r7 = ADD32(ctx->r5, 0);
    after_69:
    // 0x800B3664: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x800B3668: lw          $a2, 0x0($s3)
    ctx->r6 = MEM_W(ctx->r19, 0X0);
    // 0x800B366C: addiu       $a1, $sp, 0xD8
    ctx->r5 = ADD32(ctx->r29, 0XD8);
    // 0x800B3670: jal         0x800191C4
    // 0x800B3674: addiu       $a2, $a2, 0x28
    ctx->r6 = ADD32(ctx->r6, 0X28);
    func_800191C4(rdram, ctx);
        goto after_70;
    // 0x800B3674: addiu       $a2, $a2, 0x28
    ctx->r6 = ADD32(ctx->r6, 0X28);
    after_70:
    // 0x800B3678: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x800B367C: lw          $v1, 0xB8($s3)
    ctx->r3 = MEM_W(ctx->r19, 0XB8);
    // 0x800B3680: addiu       $a0, $a0, -0x7FC4
    ctx->r4 = ADD32(ctx->r4, -0X7FC4);
    // 0x800B3684: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x800B3688: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800B368C: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800B3690: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800B3694: sll         $v0, $v0, 5
    ctx->r2 = S32(ctx->r2 << 5);
    // 0x800B3698: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x800B369C: lw          $t1, 0xCC($s3)
    ctx->r9 = MEM_W(ctx->r19, 0XCC);
    // 0x800B36A0: lw          $t2, 0xD0($s3)
    ctx->r10 = MEM_W(ctx->r19, 0XD0);
    // 0x800B36A4: lw          $t3, 0xD4($s3)
    ctx->r11 = MEM_W(ctx->r19, 0XD4);
    // 0x800B36A8: sw          $t1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r9;
    // 0x800B36AC: sw          $t2, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r10;
    // 0x800B36B0: sw          $t3, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r11;
L_800B36B4:
    // 0x800B36B4: lw          $ra, 0x1A4($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1A4);
    // 0x800B36B8: lw          $fp, 0x1A0($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X1A0);
    // 0x800B36BC: lw          $s7, 0x19C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X19C);
    // 0x800B36C0: lw          $s6, 0x198($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X198);
    // 0x800B36C4: lw          $s5, 0x194($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X194);
    // 0x800B36C8: lw          $s4, 0x190($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X190);
    // 0x800B36CC: lw          $s3, 0x18C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X18C);
    // 0x800B36D0: lw          $s2, 0x188($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X188);
    // 0x800B36D4: lw          $s1, 0x184($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X184);
    // 0x800B36D8: lw          $s0, 0x180($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X180);
    // 0x800B36DC: ldc1        $f30, 0x1D0($sp)
    CHECK_FR(ctx, 30);
    ctx->f30.u64 = LD(ctx->r29, 0X1D0);
    // 0x800B36E0: ldc1        $f28, 0x1C8($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0X1C8);
    // 0x800B36E4: ldc1        $f26, 0x1C0($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X1C0);
    // 0x800B36E8: ldc1        $f24, 0x1B8($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X1B8);
    // 0x800B36EC: ldc1        $f22, 0x1B0($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X1B0);
    // 0x800B36F0: ldc1        $f20, 0x1A8($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X1A8);
    // 0x800B36F4: jr          $ra
    // 0x800B36F8: addiu       $sp, $sp, 0x1D8
    ctx->r29 = ADD32(ctx->r29, 0X1D8);
    return;
    // 0x800B36F8: addiu       $sp, $sp, 0x1D8
    ctx->r29 = ADD32(ctx->r29, 0X1D8);
;}
RECOMP_FUNC void func_800B1D54(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B1D54: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x800B1D58: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x800B1D5C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800B1D60: lui         $s0, 0x800A
    ctx->r16 = S32(0X800A << 16);
    // 0x800B1D64: addiu       $s0, $s0, 0x5BC4
    ctx->r16 = ADD32(ctx->r16, 0X5BC4);
    // 0x800B1D68: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x800B1D6C: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    // 0x800B1D70: addiu       $a3, $zero, -0x100
    ctx->r7 = ADD32(0, -0X100);
    // 0x800B1D74: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x800B1D78: addiu       $s1, $zero, 0x72
    ctx->r17 = ADD32(0, 0X72);
    // 0x800B1D7C: sw          $ra, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r31;
    // 0x800B1D80: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x800B1D84: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x800B1D88: sdc1        $f20, 0x30($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X30, ctx->r29);
    // 0x800B1D8C: jal         0x80063CFC
    // 0x800B1D90: sw          $s1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r17;
    func_80063CFC(rdram, ctx);
        goto after_0;
    // 0x800B1D90: sw          $s1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r17;
    after_0:
    // 0x800B1D94: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x800B1D98: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x800B1D9C: addiu       $a2, $zero, 0x9
    ctx->r6 = ADD32(0, 0X9);
    // 0x800B1DA0: addiu       $a3, $zero, -0x100
    ctx->r7 = ADD32(0, -0X100);
    // 0x800B1DA4: jal         0x80063CFC
    // 0x800B1DA8: sw          $s1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r17;
    func_80063CFC(rdram, ctx);
        goto after_1;
    // 0x800B1DA8: sw          $s1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r17;
    after_1:
    // 0x800B1DAC: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x800B1DB0: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    // 0x800B1DB4: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800B1DB8: lwc1        $f20, 0x5BD0($at)
    ctx->f20.u32l = MEM_W(ctx->r1, 0X5BD0);
    // 0x800B1DBC: addiu       $s2, $zero, 0x4
    ctx->r18 = ADD32(0, 0X4);
    // 0x800B1DC0: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x800B1DC4: jal         0x80061F34
    // 0x800B1DC8: lui         $s3, 0x800D
    ctx->r19 = S32(0X800D << 16);
    func_80061F34(rdram, ctx);
        goto after_2;
    // 0x800B1DC8: lui         $s3, 0x800D
    ctx->r19 = S32(0X800D << 16);
    after_2:
    // 0x800B1DCC: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x800B1DD0: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x800B1DD4: jal         0x80061F34
    // 0x800B1DD8: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    func_80061F34(rdram, ctx);
        goto after_3;
    // 0x800B1DD8: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    after_3:
    // 0x800B1DDC: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x800B1DE0: jal         0x80063C3C
    // 0x800B1DE4: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    func_80063C3C(rdram, ctx);
        goto after_4;
    // 0x800B1DE4: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    after_4:
    // 0x800B1DE8: addu        $a1, $v0, $zero
    ctx->r5 = ADD32(ctx->r2, 0);
    // 0x800B1DEC: lui         $s0, 0x800D
    ctx->r16 = S32(0X800D << 16);
    // 0x800B1DF0: lw          $a0, -0x2324($s0)
    ctx->r4 = MEM_W(ctx->r16, -0X2324);
    // 0x800B1DF4: jal         0x800646F8
    // 0x800B1DF8: addiu       $a2, $zero, 0x19
    ctx->r6 = ADD32(0, 0X19);
    func_800646F8(rdram, ctx);
        goto after_5;
    // 0x800B1DF8: addiu       $a2, $zero, 0x19
    ctx->r6 = ADD32(0, 0X19);
    after_5:
    // 0x800B1DFC: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x800B1E00: jal         0x80063C3C
    // 0x800B1E04: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    func_80063C3C(rdram, ctx);
        goto after_6;
    // 0x800B1E04: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    after_6:
    // 0x800B1E08: addu        $a1, $v0, $zero
    ctx->r5 = ADD32(ctx->r2, 0);
    // 0x800B1E0C: lw          $a0, -0x2324($s0)
    ctx->r4 = MEM_W(ctx->r16, -0X2324);
    // 0x800B1E10: jal         0x800646F8
    // 0x800B1E14: addiu       $a2, $zero, 0x19
    ctx->r6 = ADD32(0, 0X19);
    func_800646F8(rdram, ctx);
        goto after_7;
    // 0x800B1E14: addiu       $a2, $zero, 0x19
    ctx->r6 = ADD32(0, 0X19);
    after_7:
    // 0x800B1E18: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x800B1E1C: lui         $s0, 0x800A
    ctx->r16 = S32(0X800A << 16);
    // 0x800B1E20: addiu       $s0, $s0, 0x5BC8
    ctx->r16 = ADD32(ctx->r16, 0X5BC8);
    // 0x800B1E24: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x800B1E28: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x800B1E2C: addiu       $a3, $zero, -0x100
    ctx->r7 = ADD32(0, -0X100);
    // 0x800B1E30: addiu       $s1, $zero, 0x76
    ctx->r17 = ADD32(0, 0X76);
    // 0x800B1E34: jal         0x80063CFC
    // 0x800B1E38: sw          $s1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r17;
    func_80063CFC(rdram, ctx);
        goto after_8;
    // 0x800B1E38: sw          $s1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r17;
    after_8:
    // 0x800B1E3C: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x800B1E40: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x800B1E44: addiu       $a2, $zero, 0x7
    ctx->r6 = ADD32(0, 0X7);
    // 0x800B1E48: addiu       $a3, $zero, -0x100
    ctx->r7 = ADD32(0, -0X100);
    // 0x800B1E4C: jal         0x80063CFC
    // 0x800B1E50: sw          $s1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r17;
    func_80063CFC(rdram, ctx);
        goto after_9;
    // 0x800B1E50: sw          $s1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r17;
    after_9:
    // 0x800B1E54: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x800B1E58: lui         $s0, 0x800A
    ctx->r16 = S32(0X800A << 16);
    // 0x800B1E5C: addiu       $s0, $s0, 0x5BCC
    ctx->r16 = ADD32(ctx->r16, 0X5BCC);
    // 0x800B1E60: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x800B1E64: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    // 0x800B1E68: addiu       $a3, $zero, -0x100
    ctx->r7 = ADD32(0, -0X100);
    // 0x800B1E6C: jal         0x80063CFC
    // 0x800B1E70: sw          $s1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r17;
    func_80063CFC(rdram, ctx);
        goto after_10;
    // 0x800B1E70: sw          $s1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r17;
    after_10:
    // 0x800B1E74: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x800B1E78: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x800B1E7C: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    // 0x800B1E80: addiu       $a3, $zero, -0x100
    ctx->r7 = ADD32(0, -0X100);
    // 0x800B1E84: jal         0x80063CFC
    // 0x800B1E88: sw          $s1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r17;
    func_80063CFC(rdram, ctx);
        goto after_11;
    // 0x800B1E88: sw          $s1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r17;
    after_11:
    // 0x800B1E8C: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
L_800B1E90:
    // 0x800B1E90: andi        $s0, $s2, 0xFF
    ctx->r16 = ctx->r18 & 0XFF;
    // 0x800B1E94: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x800B1E98: jal         0x80061C74
    // 0x800B1E9C: addu        $a2, $a0, $zero
    ctx->r6 = ADD32(ctx->r4, 0);
    func_80061C74(rdram, ctx);
        goto after_12;
    // 0x800B1E9C: addu        $a2, $a0, $zero
    ctx->r6 = ADD32(ctx->r4, 0);
    after_12:
    // 0x800B1EA0: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x800B1EA4: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x800B1EA8: jal         0x80063E54
    // 0x800B1EAC: addiu       $a2, $s3, -0x390C
    ctx->r6 = ADD32(ctx->r19, -0X390C);
    func_80063E54(rdram, ctx);
        goto after_13;
    // 0x800B1EAC: addiu       $a2, $s3, -0x390C
    ctx->r6 = ADD32(ctx->r19, -0X390C);
    after_13:
    // 0x800B1EB0: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x800B1EB4: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x800B1EB8: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x800B1EBC: jal         0x80061F34
    // 0x800B1EC0: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    func_80061F34(rdram, ctx);
        goto after_14;
    // 0x800B1EC0: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    after_14:
    // 0x800B1EC4: andi        $v0, $s2, 0xFF
    ctx->r2 = ctx->r18 & 0XFF;
    // 0x800B1EC8: sltiu       $v0, $v0, 0xA
    ctx->r2 = ctx->r2 < 0XA ? 1 : 0;
    // 0x800B1ECC: bne         $v0, $zero, L_800B1E90
    if (ctx->r2 != 0) {
        // 0x800B1ED0: addu        $a0, $zero, $zero
        ctx->r4 = ADD32(0, 0);
            goto L_800B1E90;
    }
    // 0x800B1ED0: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x800B1ED4: lw          $ra, 0x28($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X28);
    // 0x800B1ED8: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x800B1EDC: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x800B1EE0: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x800B1EE4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800B1EE8: ldc1        $f20, 0x30($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X30);
    // 0x800B1EEC: jr          $ra
    // 0x800B1EF0: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x800B1EF0: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_800B1EF4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B1EF4: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x800B1EF8: sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // 0x800B1EFC: andi        $s2, $a0, 0xFF
    ctx->r18 = ctx->r4 & 0XFF;
    // 0x800B1F00: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x800B1F04: sw          $fp, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r30;
    // 0x800B1F08: addu        $fp, $a1, $zero
    ctx->r30 = ADD32(ctx->r5, 0);
    // 0x800B1F0C: lw          $a0, -0x205C($v0)
    ctx->r4 = MEM_W(ctx->r2, -0X205C);
    // 0x800B1F10: sltu        $v0, $zero, $s2
    ctx->r2 = 0 < ctx->r18 ? 1 : 0;
    // 0x800B1F14: sw          $s6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r22;
    // 0x800B1F18: addu        $s6, $v0, $zero
    ctx->r22 = ADD32(ctx->r2, 0);
    // 0x800B1F1C: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x800B1F20: addiu       $a1, $s2, 0x1
    ctx->r5 = ADD32(ctx->r18, 0X1);
    // 0x800B1F24: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x800B1F28: sdc1        $f20, 0x38($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X38, ctx->r29);
    // 0x800B1F2C: mtc1        $a2, $f20
    ctx->f20.u32l = ctx->r6;
    // 0x800B1F30: lw          $v0, -0x2530($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X2530);
    // 0x800B1F34: sllv        $v1, $v1, $a1
    ctx->r3 = S32(ctx->r3 << (ctx->r5 & 31));
    // 0x800B1F38: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x800B1F3C: sw          $s7, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r23;
    // 0x800B1F40: sw          $s5, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r21;
    // 0x800B1F44: sw          $s4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r20;
    // 0x800B1F48: sw          $s3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r19;
    // 0x800B1F4C: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x800B1F50: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x800B1F54: and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // 0x800B1F58: sltu        $v0, $zero, $v0
    ctx->r2 = 0 < ctx->r2 ? 1 : 0;
    // 0x800B1F5C: jal         0x80063EF0
    // 0x800B1F60: addu        $s7, $v0, $zero
    ctx->r23 = ADD32(ctx->r2, 0);
    func_80063EF0(rdram, ctx);
        goto after_0;
    // 0x800B1F60: addu        $s7, $v0, $zero
    ctx->r23 = ADD32(ctx->r2, 0);
    after_0:
    // 0x800B1F64: addu        $s3, $v0, $zero
    ctx->r19 = ADD32(ctx->r2, 0);
    // 0x800B1F68: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x800B1F6C: lhu         $v0, 0x8($s3)
    ctx->r2 = MEM_HU(ctx->r19, 0X8);
    // 0x800B1F70: lw          $v1, 0x10($s3)
    ctx->r3 = MEM_W(ctx->r19, 0X10);
    // 0x800B1F74: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800B1F78: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800B1F7C: lhu         $s0, 0x0($v1)
    ctx->r16 = MEM_HU(ctx->r3, 0X0);
    // 0x800B1F80: lhu         $s1, -0x4($v0)
    ctx->r17 = MEM_HU(ctx->r2, -0X4);
    // 0x800B1F84: jal         0x80063C3C
    // 0x800B1F88: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_80063C3C(rdram, ctx);
        goto after_1;
    // 0x800B1F88: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_1:
    // 0x800B1F8C: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x800B1F90: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    // 0x800B1F94: lw          $v0, 0x10($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X10);
    // 0x800B1F98: addiu       $s4, $s0, -0x22
    ctx->r20 = ADD32(ctx->r16, -0X22);
    // 0x800B1F9C: addiu       $s5, $s1, 0x1C
    ctx->r21 = ADD32(ctx->r17, 0X1C);
    // 0x800B1FA0: addiu       $s0, $s0, -0x20
    ctx->r16 = ADD32(ctx->r16, -0X20);
    // 0x800B1FA4: jal         0x80063C3C
    // 0x800B1FA8: sh          $s0, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r16;
    func_80063C3C(rdram, ctx);
        goto after_2;
    // 0x800B1FA8: sh          $s0, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r16;
    after_2:
    // 0x800B1FAC: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x800B1FB0: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    // 0x800B1FB4: lw          $v0, 0x10($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X10);
    // 0x800B1FB8: addiu       $s1, $s1, 0x1A
    ctx->r17 = ADD32(ctx->r17, 0X1A);
    // 0x800B1FBC: jal         0x80063C3C
    // 0x800B1FC0: sh          $s1, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r17;
    func_80063C3C(rdram, ctx);
        goto after_3;
    // 0x800B1FC0: sh          $s1, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r17;
    after_3:
    // 0x800B1FC4: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x800B1FC8: addiu       $v1, $v1, 0xB10
    ctx->r3 = ADD32(ctx->r3, 0XB10);
    // 0x800B1FCC: addu        $s2, $s2, $v1
    ctx->r18 = ADD32(ctx->r18, ctx->r3);
    // 0x800B1FD0: lbu         $v1, 0xC($s2)
    ctx->r3 = MEM_BU(ctx->r18, 0XC);
    // 0x800B1FD4: beq         $v1, $zero, L_800B1FE8
    if (ctx->r3 == 0) {
        // 0x800B1FD8: addu        $s0, $v0, $zero
        ctx->r16 = ADD32(ctx->r2, 0);
            goto L_800B1FE8;
    }
    // 0x800B1FD8: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    // 0x800B1FDC: addiu       $v0, $v1, 0x1
    ctx->r2 = ADD32(ctx->r3, 0X1);
    // 0x800B1FE0: j           L_800B1FEC
    // 0x800B1FE4: andi        $a1, $v0, 0xFF
    ctx->r5 = ctx->r2 & 0XFF;
        goto L_800B1FEC;
    // 0x800B1FE4: andi        $a1, $v0, 0xFF
    ctx->r5 = ctx->r2 & 0XFF;
L_800B1FE8:
    // 0x800B1FE8: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
L_800B1FEC:
    // 0x800B1FEC: jal         0x80064028
    // 0x800B1FF0: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    func_80064028(rdram, ctx);
        goto after_4;
    // 0x800B1FF0: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    after_4:
    // 0x800B1FF4: lw          $v1, 0xC($s0)
    ctx->r3 = MEM_W(ctx->r16, 0XC);
    // 0x800B1FF8: sh          $v0, 0x2($v1)
    MEM_H(0X2, ctx->r3) = ctx->r2;
    // 0x800B1FFC: sh          $v0, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r2;
    // 0x800B2000: lw          $v1, 0x10($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X10);
    // 0x800B2004: addiu       $v0, $s4, -0x2
    ctx->r2 = ADD32(ctx->r20, -0X2);
    // 0x800B2008: sh          $v0, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r2;
    // 0x800B200C: lw          $v1, 0x10($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X10);
    // 0x800B2010: addiu       $v0, $s5, -0x7
    ctx->r2 = ADD32(ctx->r21, -0X7);
    // 0x800B2014: sh          $v0, 0x4($v1)
    MEM_H(0X4, ctx->r3) = ctx->r2;
    // 0x800B2018: lbu         $v0, 0x2F($s3)
    ctx->r2 = MEM_BU(ctx->r19, 0X2F);
    // 0x800B201C: sltiu       $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 < 0XFF ? 1 : 0;
    // 0x800B2020: beq         $v0, $zero, L_800B2058
    if (ctx->r2 == 0) {
        // 0x800B2024: nop
    
            goto L_800B2058;
    }
    // 0x800B2024: nop

    // 0x800B2028: lbu         $v0, 0x2F($s3)
    ctx->r2 = MEM_BU(ctx->r19, 0X2F);
    // 0x800B202C: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x800B2030: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x800B2034: mul.s       $f0, $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f20.fl);
    // 0x800B2038: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800B203C: lwc1        $f2, 0x5BD4($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X5BD4);
    // 0x800B2040: c.le.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl <= ctx->f0.fl;
    // 0x800B2044: nop

    // 0x800B2048: bc1f        L_800B207C
    if (!c1cs) {
        // 0x800B204C: nop
    
            goto L_800B207C;
    }
    // 0x800B204C: nop

    // 0x800B2050: j           L_800B208C
    // 0x800B2054: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
        goto L_800B208C;
    // 0x800B2054: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
L_800B2058:
    // 0x800B2058: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800B205C: lwc1        $f0, 0x5BD8($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X5BD8);
    // 0x800B2060: mul.s       $f0, $f20, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = MUL_S(ctx->f20.fl, ctx->f0.fl);
    // 0x800B2064: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800B2068: lwc1        $f2, 0x5BDC($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X5BDC);
    // 0x800B206C: c.le.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl <= ctx->f0.fl;
    // 0x800B2070: nop

    // 0x800B2074: bc1tl       L_800B208C
    if (c1cs) {
        // 0x800B2078: sub.s       $f0, $f0, $f2
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
            goto L_800B208C;
    }
    goto skip_0;
    // 0x800B2078: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    skip_0:
L_800B207C:
    // 0x800B207C: trunc.w.s   $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    ctx->f4.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800B2080: mfc1        $v1, $f4
    ctx->r3 = (int32_t)ctx->f4.u32l;
    // 0x800B2084: j           L_800B20A0
    // 0x800B2088: addu        $s1, $v1, $zero
    ctx->r17 = ADD32(ctx->r3, 0);
        goto L_800B20A0;
    // 0x800B2088: addu        $s1, $v1, $zero
    ctx->r17 = ADD32(ctx->r3, 0);
L_800B208C:
    // 0x800B208C: lui         $v0, 0x8000
    ctx->r2 = S32(0X8000 << 16);
    // 0x800B2090: trunc.w.s   $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    ctx->f4.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800B2094: mfc1        $v1, $f4
    ctx->r3 = (int32_t)ctx->f4.u32l;
    // 0x800B2098: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x800B209C: addu        $s1, $v1, $zero
    ctx->r17 = ADD32(ctx->r3, 0);
L_800B20A0:
    // 0x800B20A0: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x800B20A4: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    // 0x800B20A8: andi        $s2, $s1, 0xFF
    ctx->r18 = ctx->r17 & 0XFF;
    // 0x800B20AC: jal         0x80061C74
    // 0x800B20B0: addu        $a2, $s2, $zero
    ctx->r6 = ADD32(ctx->r18, 0);
    func_80061C74(rdram, ctx);
        goto after_5;
    // 0x800B20B0: addu        $a2, $s2, $zero
    ctx->r6 = ADD32(ctx->r18, 0);
    after_5:
    // 0x800B20B4: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x800B20B8: lw          $v0, 0xC($a1)
    ctx->r2 = MEM_W(ctx->r5, 0XC);
    // 0x800B20BC: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x800B20C0: lhu         $a2, 0x0($v0)
    ctx->r6 = MEM_HU(ctx->r2, 0X0);
    // 0x800B20C4: lw          $a0, -0x2324($v1)
    ctx->r4 = MEM_W(ctx->r3, -0X2324);
    // 0x800B20C8: xori        $a2, $a2, 0xFFFF
    ctx->r6 = ctx->r6 ^ 0XFFFF;
    // 0x800B20CC: jal         0x800646AC
    // 0x800B20D0: sltu        $a2, $zero, $a2
    ctx->r6 = 0 < ctx->r6 ? 1 : 0;
    func_800646AC(rdram, ctx);
        goto after_6;
    // 0x800B20D0: sltu        $a2, $zero, $a2
    ctx->r6 = 0 < ctx->r6 ? 1 : 0;
    after_6:
    // 0x800B20D4: andi        $v0, $s6, 0xFF
    ctx->r2 = ctx->r22 & 0XFF;
    // 0x800B20D8: beq         $v0, $zero, L_800B2150
    if (ctx->r2 == 0) {
        // 0x800B20DC: lui         $v0, 0x800D
        ctx->r2 = S32(0X800D << 16);
            goto L_800B2150;
    }
    // 0x800B20DC: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x800B20E0: lwc1        $f0, -0x24EC($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, -0X24EC);
    // 0x800B20E4: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800B20E8: lwc1        $f12, 0x5BE0($at)
    ctx->f12.u32l = MEM_W(ctx->r1, 0X5BE0);
    // 0x800B20EC: jal         0x80033960
    // 0x800B20F0: div.s       $f12, $f0, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = DIV_S(ctx->f0.fl, ctx->f12.fl);
    sinf_recomp(rdram, ctx);
        goto after_7;
    // 0x800B20F0: div.s       $f12, $f0, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = DIV_S(ctx->f0.fl, ctx->f12.fl);
    after_7:
    // 0x800B20F4: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800B20F8: lwc1        $f2, 0x5BE4($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X5BE4);
    // 0x800B20FC: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x800B2100: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x800B2104: mtc1        $s2, $f2
    ctx->f2.u32l = ctx->r18;
    // 0x800B2108: cvt.s.w     $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    ctx->f2.fl = CVT_S_W(ctx->f2.u32l);
    // 0x800B210C: mul.s       $f0, $f2, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x800B2110: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800B2114: lwc1        $f2, 0x5BE8($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X5BE8);
    // 0x800B2118: c.le.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl <= ctx->f0.fl;
    // 0x800B211C: nop

    // 0x800B2120: bc1tl       L_800B2138
    if (c1cs) {
        // 0x800B2124: sub.s       $f0, $f0, $f2
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
            goto L_800B2138;
    }
    goto skip_1;
    // 0x800B2124: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    skip_1:
    // 0x800B2128: trunc.w.s   $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    ctx->f4.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800B212C: mfc1        $a2, $f4
    ctx->r6 = (int32_t)ctx->f4.u32l;
    // 0x800B2130: j           L_800B2154
    // 0x800B2134: andi        $a2, $a2, 0xFF
    ctx->r6 = ctx->r6 & 0XFF;
        goto L_800B2154;
    // 0x800B2134: andi        $a2, $a2, 0xFF
    ctx->r6 = ctx->r6 & 0XFF;
L_800B2138:
    // 0x800B2138: lui         $v0, 0x8000
    ctx->r2 = S32(0X8000 << 16);
    // 0x800B213C: trunc.w.s   $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    ctx->f4.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800B2140: mfc1        $a2, $f4
    ctx->r6 = (int32_t)ctx->f4.u32l;
    // 0x800B2144: or          $a2, $a2, $v0
    ctx->r6 = ctx->r6 | ctx->r2;
    // 0x800B2148: j           L_800B2154
    // 0x800B214C: andi        $a2, $a2, 0xFF
    ctx->r6 = ctx->r6 & 0XFF;
        goto L_800B2154;
    // 0x800B214C: andi        $a2, $a2, 0xFF
    ctx->r6 = ctx->r6 & 0XFF;
L_800B2150:
    // 0x800B2150: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
L_800B2154:
    // 0x800B2154: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x800B2158: jal         0x80061C74
    // 0x800B215C: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_80061C74(rdram, ctx);
        goto after_8;
    // 0x800B215C: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_8:
    // 0x800B2160: andi        $v0, $s7, 0xFF
    ctx->r2 = ctx->r23 & 0XFF;
    // 0x800B2164: beq         $v0, $zero, L_800B21E0
    if (ctx->r2 == 0) {
        // 0x800B2168: lui         $v0, 0x800D
        ctx->r2 = S32(0X800D << 16);
            goto L_800B21E0;
    }
    // 0x800B2168: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x800B216C: lwc1        $f0, -0x24EC($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, -0X24EC);
    // 0x800B2170: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800B2174: lwc1        $f12, 0x5BEC($at)
    ctx->f12.u32l = MEM_W(ctx->r1, 0X5BEC);
    // 0x800B2178: jal         0x80033960
    // 0x800B217C: div.s       $f12, $f0, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = DIV_S(ctx->f0.fl, ctx->f12.fl);
    sinf_recomp(rdram, ctx);
        goto after_9;
    // 0x800B217C: div.s       $f12, $f0, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = DIV_S(ctx->f0.fl, ctx->f12.fl);
    after_9:
    // 0x800B2180: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800B2184: lwc1        $f2, 0x5BF0($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X5BF0);
    // 0x800B2188: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x800B218C: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x800B2190: andi        $v0, $s1, 0xFF
    ctx->r2 = ctx->r17 & 0XFF;
    // 0x800B2194: mtc1        $v0, $f2
    ctx->f2.u32l = ctx->r2;
    // 0x800B2198: cvt.s.w     $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    ctx->f2.fl = CVT_S_W(ctx->f2.u32l);
    // 0x800B219C: mul.s       $f0, $f2, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x800B21A0: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800B21A4: lwc1        $f2, 0x5BF4($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X5BF4);
    // 0x800B21A8: c.le.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl <= ctx->f0.fl;
    // 0x800B21AC: nop

    // 0x800B21B0: bc1tl       L_800B21C8
    if (c1cs) {
        // 0x800B21B4: sub.s       $f0, $f0, $f2
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
            goto L_800B21C8;
    }
    goto skip_2;
    // 0x800B21B4: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    skip_2:
    // 0x800B21B8: trunc.w.s   $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    ctx->f4.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800B21BC: mfc1        $a2, $f4
    ctx->r6 = (int32_t)ctx->f4.u32l;
    // 0x800B21C0: j           L_800B21E4
    // 0x800B21C4: andi        $a2, $a2, 0xFF
    ctx->r6 = ctx->r6 & 0XFF;
        goto L_800B21E4;
    // 0x800B21C4: andi        $a2, $a2, 0xFF
    ctx->r6 = ctx->r6 & 0XFF;
L_800B21C8:
    // 0x800B21C8: lui         $v0, 0x8000
    ctx->r2 = S32(0X8000 << 16);
    // 0x800B21CC: trunc.w.s   $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    ctx->f4.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800B21D0: mfc1        $a2, $f4
    ctx->r6 = (int32_t)ctx->f4.u32l;
    // 0x800B21D4: or          $a2, $a2, $v0
    ctx->r6 = ctx->r6 | ctx->r2;
    // 0x800B21D8: j           L_800B21E4
    // 0x800B21DC: andi        $a2, $a2, 0xFF
    ctx->r6 = ctx->r6 & 0XFF;
        goto L_800B21E4;
    // 0x800B21DC: andi        $a2, $a2, 0xFF
    ctx->r6 = ctx->r6 & 0XFF;
L_800B21E0:
    // 0x800B21E0: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
L_800B21E4:
    // 0x800B21E4: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x800B21E8: jal         0x80061C74
    // 0x800B21EC: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    func_80061C74(rdram, ctx);
        goto after_10;
    // 0x800B21EC: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_10:
    // 0x800B21F0: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x800B21F4: lw          $a0, -0x205C($v0)
    ctx->r4 = MEM_W(ctx->r2, -0X205C);
    // 0x800B21F8: jal         0x80063F28
    // 0x800B21FC: nop

    func_80063F28(rdram, ctx);
        goto after_11;
    // 0x800B21FC: nop

    after_11:
    // 0x800B2200: addu        $s3, $v0, $zero
    ctx->r19 = ADD32(ctx->r2, 0);
    // 0x800B2204: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x800B2208: lhu         $v0, 0x8($s3)
    ctx->r2 = MEM_HU(ctx->r19, 0X8);
    // 0x800B220C: lw          $v1, 0x10($s3)
    ctx->r3 = MEM_W(ctx->r19, 0X10);
    // 0x800B2210: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800B2214: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800B2218: lhu         $s0, 0x0($v1)
    ctx->r16 = MEM_HU(ctx->r3, 0X0);
    // 0x800B221C: lhu         $s1, -0x4($v0)
    ctx->r17 = MEM_HU(ctx->r2, -0X4);
    // 0x800B2220: jal         0x80063C3C
    // 0x800B2224: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    func_80063C3C(rdram, ctx);
        goto after_12;
    // 0x800B2224: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    after_12:
    // 0x800B2228: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x800B222C: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    // 0x800B2230: lw          $v0, 0x10($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X10);
    // 0x800B2234: addiu       $s4, $s0, -0x22
    ctx->r20 = ADD32(ctx->r16, -0X22);
    // 0x800B2238: addiu       $s5, $s1, 0x1C
    ctx->r21 = ADD32(ctx->r17, 0X1C);
    // 0x800B223C: addiu       $s0, $s0, -0x20
    ctx->r16 = ADD32(ctx->r16, -0X20);
    // 0x800B2240: jal         0x80063C3C
    // 0x800B2244: sh          $s0, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r16;
    func_80063C3C(rdram, ctx);
        goto after_13;
    // 0x800B2244: sh          $s0, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r16;
    after_13:
    // 0x800B2248: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x800B224C: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    // 0x800B2250: lw          $v0, 0x10($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X10);
    // 0x800B2254: addiu       $s1, $s1, 0x1A
    ctx->r17 = ADD32(ctx->r17, 0X1A);
    // 0x800B2258: jal         0x80063C3C
    // 0x800B225C: sh          $s1, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r17;
    func_80063C3C(rdram, ctx);
        goto after_14;
    // 0x800B225C: sh          $s1, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r17;
    after_14:
    // 0x800B2260: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800B2264: addiu       $a0, $a0, 0xB10
    ctx->r4 = ADD32(ctx->r4, 0XB10);
    // 0x800B2268: andi        $v1, $fp, 0xFF
    ctx->r3 = ctx->r30 & 0XFF;
    // 0x800B226C: addu        $v1, $v1, $a0
    ctx->r3 = ADD32(ctx->r3, ctx->r4);
    // 0x800B2270: lbu         $v1, 0xC($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0XC);
    // 0x800B2274: beq         $v1, $zero, L_800B2288
    if (ctx->r3 == 0) {
        // 0x800B2278: addu        $s0, $v0, $zero
        ctx->r16 = ADD32(ctx->r2, 0);
            goto L_800B2288;
    }
    // 0x800B2278: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    // 0x800B227C: addiu       $v0, $v1, 0x1
    ctx->r2 = ADD32(ctx->r3, 0X1);
    // 0x800B2280: j           L_800B228C
    // 0x800B2284: andi        $a1, $v0, 0xFF
    ctx->r5 = ctx->r2 & 0XFF;
        goto L_800B228C;
    // 0x800B2284: andi        $a1, $v0, 0xFF
    ctx->r5 = ctx->r2 & 0XFF;
L_800B2288:
    // 0x800B2288: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
L_800B228C:
    // 0x800B228C: jal         0x80064028
    // 0x800B2290: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    func_80064028(rdram, ctx);
        goto after_15;
    // 0x800B2290: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    after_15:
    // 0x800B2294: lw          $v1, 0xC($s0)
    ctx->r3 = MEM_W(ctx->r16, 0XC);
    // 0x800B2298: sh          $v0, 0x2($v1)
    MEM_H(0X2, ctx->r3) = ctx->r2;
    // 0x800B229C: sh          $v0, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r2;
    // 0x800B22A0: lw          $v1, 0x10($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X10);
    // 0x800B22A4: addiu       $v0, $s4, -0x2
    ctx->r2 = ADD32(ctx->r20, -0X2);
    // 0x800B22A8: sh          $v0, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r2;
    // 0x800B22AC: lw          $v1, 0x10($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X10);
    // 0x800B22B0: addiu       $v0, $s5, -0x7
    ctx->r2 = ADD32(ctx->r21, -0X7);
    // 0x800B22B4: sh          $v0, 0x4($v1)
    MEM_H(0X4, ctx->r3) = ctx->r2;
    // 0x800B22B8: lbu         $v0, 0x2F($s3)
    ctx->r2 = MEM_BU(ctx->r19, 0X2F);
    // 0x800B22BC: sltiu       $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 < 0XFF ? 1 : 0;
    // 0x800B22C0: beq         $v0, $zero, L_800B22F8
    if (ctx->r2 == 0) {
        // 0x800B22C4: nop
    
            goto L_800B22F8;
    }
    // 0x800B22C4: nop

    // 0x800B22C8: lbu         $v0, 0x2F($s3)
    ctx->r2 = MEM_BU(ctx->r19, 0X2F);
    // 0x800B22CC: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x800B22D0: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x800B22D4: mul.s       $f0, $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f20.fl);
    // 0x800B22D8: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800B22DC: lwc1        $f2, 0x5BF8($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X5BF8);
    // 0x800B22E0: c.le.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl <= ctx->f0.fl;
    // 0x800B22E4: nop

    // 0x800B22E8: bc1f        L_800B231C
    if (!c1cs) {
        // 0x800B22EC: nop
    
            goto L_800B231C;
    }
    // 0x800B22EC: nop

    // 0x800B22F0: j           L_800B232C
    // 0x800B22F4: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
        goto L_800B232C;
    // 0x800B22F4: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
L_800B22F8:
    // 0x800B22F8: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800B22FC: lwc1        $f0, 0x5BFC($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X5BFC);
    // 0x800B2300: mul.s       $f0, $f20, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = MUL_S(ctx->f20.fl, ctx->f0.fl);
    // 0x800B2304: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800B2308: lwc1        $f2, 0x5C00($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X5C00);
    // 0x800B230C: c.le.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl <= ctx->f0.fl;
    // 0x800B2310: nop

    // 0x800B2314: bc1tl       L_800B232C
    if (c1cs) {
        // 0x800B2318: sub.s       $f0, $f0, $f2
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
            goto L_800B232C;
    }
    goto skip_3;
    // 0x800B2318: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    skip_3:
L_800B231C:
    // 0x800B231C: trunc.w.s   $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    ctx->f4.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800B2320: mfc1        $a2, $f4
    ctx->r6 = (int32_t)ctx->f4.u32l;
    // 0x800B2324: j           L_800B2340
    // 0x800B2328: addu        $s1, $a2, $zero
    ctx->r17 = ADD32(ctx->r6, 0);
        goto L_800B2340;
    // 0x800B2328: addu        $s1, $a2, $zero
    ctx->r17 = ADD32(ctx->r6, 0);
L_800B232C:
    // 0x800B232C: lui         $v0, 0x8000
    ctx->r2 = S32(0X8000 << 16);
    // 0x800B2330: trunc.w.s   $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    ctx->f4.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800B2334: mfc1        $a2, $f4
    ctx->r6 = (int32_t)ctx->f4.u32l;
    // 0x800B2338: or          $a2, $a2, $v0
    ctx->r6 = ctx->r6 | ctx->r2;
    // 0x800B233C: addu        $s1, $a2, $zero
    ctx->r17 = ADD32(ctx->r6, 0);
L_800B2340:
    // 0x800B2340: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x800B2344: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    // 0x800B2348: andi        $s2, $s1, 0xFF
    ctx->r18 = ctx->r17 & 0XFF;
    // 0x800B234C: jal         0x80061C74
    // 0x800B2350: addu        $a2, $s2, $zero
    ctx->r6 = ADD32(ctx->r18, 0);
    func_80061C74(rdram, ctx);
        goto after_16;
    // 0x800B2350: addu        $a2, $s2, $zero
    ctx->r6 = ADD32(ctx->r18, 0);
    after_16:
    // 0x800B2354: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x800B2358: lw          $v0, 0xC($a1)
    ctx->r2 = MEM_W(ctx->r5, 0XC);
    // 0x800B235C: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x800B2360: lhu         $a2, 0x0($v0)
    ctx->r6 = MEM_HU(ctx->r2, 0X0);
    // 0x800B2364: lw          $a0, -0x2324($v1)
    ctx->r4 = MEM_W(ctx->r3, -0X2324);
    // 0x800B2368: xori        $a2, $a2, 0xFFFF
    ctx->r6 = ctx->r6 ^ 0XFFFF;
    // 0x800B236C: jal         0x800646AC
    // 0x800B2370: sltu        $a2, $zero, $a2
    ctx->r6 = 0 < ctx->r6 ? 1 : 0;
    func_800646AC(rdram, ctx);
        goto after_17;
    // 0x800B2370: sltu        $a2, $zero, $a2
    ctx->r6 = 0 < ctx->r6 ? 1 : 0;
    after_17:
    // 0x800B2374: andi        $v0, $s6, 0xFF
    ctx->r2 = ctx->r22 & 0XFF;
    // 0x800B2378: beq         $v0, $zero, L_800B23F0
    if (ctx->r2 == 0) {
        // 0x800B237C: lui         $v0, 0x800D
        ctx->r2 = S32(0X800D << 16);
            goto L_800B23F0;
    }
    // 0x800B237C: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x800B2380: lwc1        $f0, -0x24EC($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, -0X24EC);
    // 0x800B2384: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800B2388: lwc1        $f12, 0x5C04($at)
    ctx->f12.u32l = MEM_W(ctx->r1, 0X5C04);
    // 0x800B238C: jal         0x80033960
    // 0x800B2390: div.s       $f12, $f0, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = DIV_S(ctx->f0.fl, ctx->f12.fl);
    sinf_recomp(rdram, ctx);
        goto after_18;
    // 0x800B2390: div.s       $f12, $f0, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = DIV_S(ctx->f0.fl, ctx->f12.fl);
    after_18:
    // 0x800B2394: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800B2398: lwc1        $f2, 0x5C08($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X5C08);
    // 0x800B239C: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x800B23A0: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x800B23A4: mtc1        $s2, $f2
    ctx->f2.u32l = ctx->r18;
    // 0x800B23A8: cvt.s.w     $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    ctx->f2.fl = CVT_S_W(ctx->f2.u32l);
    // 0x800B23AC: mul.s       $f0, $f2, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x800B23B0: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800B23B4: lwc1        $f2, 0x5C0C($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X5C0C);
    // 0x800B23B8: c.le.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl <= ctx->f0.fl;
    // 0x800B23BC: nop

    // 0x800B23C0: bc1tl       L_800B23D8
    if (c1cs) {
        // 0x800B23C4: sub.s       $f0, $f0, $f2
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
            goto L_800B23D8;
    }
    goto skip_4;
    // 0x800B23C4: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    skip_4:
    // 0x800B23C8: trunc.w.s   $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    ctx->f4.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800B23CC: mfc1        $a2, $f4
    ctx->r6 = (int32_t)ctx->f4.u32l;
    // 0x800B23D0: j           L_800B23F4
    // 0x800B23D4: andi        $a2, $a2, 0xFF
    ctx->r6 = ctx->r6 & 0XFF;
        goto L_800B23F4;
    // 0x800B23D4: andi        $a2, $a2, 0xFF
    ctx->r6 = ctx->r6 & 0XFF;
L_800B23D8:
    // 0x800B23D8: lui         $v0, 0x8000
    ctx->r2 = S32(0X8000 << 16);
    // 0x800B23DC: trunc.w.s   $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    ctx->f4.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800B23E0: mfc1        $a2, $f4
    ctx->r6 = (int32_t)ctx->f4.u32l;
    // 0x800B23E4: or          $a2, $a2, $v0
    ctx->r6 = ctx->r6 | ctx->r2;
    // 0x800B23E8: j           L_800B23F4
    // 0x800B23EC: andi        $a2, $a2, 0xFF
    ctx->r6 = ctx->r6 & 0XFF;
        goto L_800B23F4;
    // 0x800B23EC: andi        $a2, $a2, 0xFF
    ctx->r6 = ctx->r6 & 0XFF;
L_800B23F0:
    // 0x800B23F0: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
L_800B23F4:
    // 0x800B23F4: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x800B23F8: jal         0x80061C74
    // 0x800B23FC: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    func_80061C74(rdram, ctx);
        goto after_19;
    // 0x800B23FC: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    after_19:
    // 0x800B2400: andi        $v0, $s7, 0xFF
    ctx->r2 = ctx->r23 & 0XFF;
    // 0x800B2404: beq         $v0, $zero, L_800B2480
    if (ctx->r2 == 0) {
        // 0x800B2408: lui         $v0, 0x800D
        ctx->r2 = S32(0X800D << 16);
            goto L_800B2480;
    }
    // 0x800B2408: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x800B240C: lwc1        $f0, -0x24EC($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, -0X24EC);
    // 0x800B2410: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800B2414: lwc1        $f12, 0x5C10($at)
    ctx->f12.u32l = MEM_W(ctx->r1, 0X5C10);
    // 0x800B2418: jal         0x80033960
    // 0x800B241C: div.s       $f12, $f0, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = DIV_S(ctx->f0.fl, ctx->f12.fl);
    sinf_recomp(rdram, ctx);
        goto after_20;
    // 0x800B241C: div.s       $f12, $f0, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = DIV_S(ctx->f0.fl, ctx->f12.fl);
    after_20:
    // 0x800B2420: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800B2424: lwc1        $f2, 0x5C14($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X5C14);
    // 0x800B2428: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x800B242C: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x800B2430: andi        $v0, $s1, 0xFF
    ctx->r2 = ctx->r17 & 0XFF;
    // 0x800B2434: mtc1        $v0, $f2
    ctx->f2.u32l = ctx->r2;
    // 0x800B2438: cvt.s.w     $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    ctx->f2.fl = CVT_S_W(ctx->f2.u32l);
    // 0x800B243C: mul.s       $f0, $f2, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x800B2440: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800B2444: lwc1        $f2, 0x5C18($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X5C18);
    // 0x800B2448: c.le.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl <= ctx->f0.fl;
    // 0x800B244C: nop

    // 0x800B2450: bc1tl       L_800B2468
    if (c1cs) {
        // 0x800B2454: sub.s       $f0, $f0, $f2
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
            goto L_800B2468;
    }
    goto skip_5;
    // 0x800B2454: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    skip_5:
    // 0x800B2458: trunc.w.s   $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    ctx->f4.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800B245C: mfc1        $a2, $f4
    ctx->r6 = (int32_t)ctx->f4.u32l;
    // 0x800B2460: j           L_800B2484
    // 0x800B2464: andi        $a2, $a2, 0xFF
    ctx->r6 = ctx->r6 & 0XFF;
        goto L_800B2484;
    // 0x800B2464: andi        $a2, $a2, 0xFF
    ctx->r6 = ctx->r6 & 0XFF;
L_800B2468:
    // 0x800B2468: lui         $v0, 0x8000
    ctx->r2 = S32(0X8000 << 16);
    // 0x800B246C: trunc.w.s   $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    ctx->f4.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800B2470: mfc1        $a2, $f4
    ctx->r6 = (int32_t)ctx->f4.u32l;
    // 0x800B2474: or          $a2, $a2, $v0
    ctx->r6 = ctx->r6 | ctx->r2;
    // 0x800B2478: j           L_800B2484
    // 0x800B247C: andi        $a2, $a2, 0xFF
    ctx->r6 = ctx->r6 & 0XFF;
        goto L_800B2484;
    // 0x800B247C: andi        $a2, $a2, 0xFF
    ctx->r6 = ctx->r6 & 0XFF;
L_800B2480:
    // 0x800B2480: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
L_800B2484:
    // 0x800B2484: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x800B2488: jal         0x80061C74
    // 0x800B248C: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    func_80061C74(rdram, ctx);
        goto after_21;
    // 0x800B248C: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_21:
    // 0x800B2490: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x800B2494: lw          $fp, 0x30($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X30);
    // 0x800B2498: lw          $s7, 0x2C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X2C);
    // 0x800B249C: lw          $s6, 0x28($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X28);
    // 0x800B24A0: lw          $s5, 0x24($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X24);
    // 0x800B24A4: lw          $s4, 0x20($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X20);
    // 0x800B24A8: lw          $s3, 0x1C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X1C);
    // 0x800B24AC: lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X18);
    // 0x800B24B0: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x800B24B4: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x800B24B8: ldc1        $f20, 0x38($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X38);
    // 0x800B24BC: jr          $ra
    // 0x800B24C0: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x800B24C0: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void func_800B24C4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B24C4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800B24C8: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x800B24CC: jal         0x8008DA00
    // 0x800B24D0: nop

    func_8008DA00(rdram, ctx);
        goto after_0;
    // 0x800B24D0: nop

    after_0:
L_800B24D4:
    // 0x800B24D4: jal         0x8008E57C
    // 0x800B24D8: nop

    func_8008E57C(rdram, ctx);
        goto after_1;
    // 0x800B24D8: nop

    after_1:
    // 0x800B24DC: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x800B24E0: beq         $v0, $zero, L_800B24D4
    if (ctx->r2 == 0) {
        // 0x800B24E4: nop
    
            goto L_800B24D4;
    }
    // 0x800B24E4: nop

    // 0x800B24E8: jal         0x8000BF60
    // 0x800B24EC: nop

    func_8000BF60(rdram, ctx);
        goto after_2;
    // 0x800B24EC: nop

    after_2:
    // 0x800B24F0: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x800B24F4: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x800B24F8: lw          $a0, -0x2324($v0)
    ctx->r4 = MEM_W(ctx->r2, -0X2324);
    // 0x800B24FC: jal         0x800B4274
    // 0x800B2500: addiu       $a1, $a1, -0x2380
    ctx->r5 = ADD32(ctx->r5, -0X2380);
    func_800B4274(rdram, ctx);
        goto after_3;
    // 0x800B2500: addiu       $a1, $a1, -0x2380
    ctx->r5 = ADD32(ctx->r5, -0X2380);
    after_3:
    // 0x800B2504: jal         0x800B3F00
    // 0x800B2508: nop

    func_800B3F00(rdram, ctx);
        goto after_4;
    // 0x800B2508: nop

    after_4:
    // 0x800B250C: jal         0x800678E4
    // 0x800B2510: nop

    func_800678E4(rdram, ctx);
        goto after_5;
    // 0x800B2510: nop

    after_5:
    // 0x800B2514: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x800B2518: jr          $ra
    // 0x800B251C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x800B251C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_800B2520(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B2520: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800B2524: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x800B2528: lui         $s0, 0x800D
    ctx->r16 = S32(0X800D << 16);
    // 0x800B252C: lw          $a0, -0x2050($s0)
    ctx->r4 = MEM_W(ctx->r16, -0X2050);
    // 0x800B2530: beq         $a0, $zero, L_800B2554
    if (ctx->r4 == 0) {
        // 0x800B2534: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_800B2554;
    }
    // 0x800B2534: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800B2538: mfc1        $a1, $f12
    ctx->r5 = (int32_t)ctx->f12.u32l;
    // 0x800B253C: jal         0x800CBE00
    // 0x800B2540: nop

    func_800CBE00(rdram, ctx);
        goto after_0;
    // 0x800B2540: nop

    after_0:
    // 0x800B2544: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x800B2548: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x800B254C: beql        $v0, $v1, L_800B2554
    if (ctx->r2 == ctx->r3) {
        // 0x800B2550: sw          $zero, -0x2050($s0)
        MEM_W(-0X2050, ctx->r16) = 0;
            goto L_800B2554;
    }
    goto skip_0;
    // 0x800B2550: sw          $zero, -0x2050($s0)
    MEM_W(-0X2050, ctx->r16) = 0;
    skip_0:
L_800B2554:
    // 0x800B2554: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800B2558: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x800B255C: jr          $ra
    // 0x800B2560: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x800B2560: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_800B2564(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B2564: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800B2568: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x800B256C: addiu       $a1, $zero, 0x190
    ctx->r5 = ADD32(0, 0X190);
    // 0x800B2570: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x800B2574: lw          $a2, -0x2320($v0)
    ctx->r6 = MEM_W(ctx->r2, -0X2320);
    // 0x800B2578: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x800B257C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800B2580: jal         0x800964C8
    // 0x800B2584: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    func_800964C8(rdram, ctx);
        goto after_0;
    // 0x800B2584: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    after_0:
    // 0x800B2588: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x800B258C: addiu       $a1, $zero, 0x190
    ctx->r5 = ADD32(0, 0X190);
    // 0x800B2590: jal         0x8008E0B0
    // 0x800B2594: addiu       $a2, $zero, 0xFE
    ctx->r6 = ADD32(0, 0XFE);
    func_8008E0B0(rdram, ctx);
        goto after_1;
    // 0x800B2594: addiu       $a2, $zero, 0xFE
    ctx->r6 = ADD32(0, 0XFE);
    after_1:
    // 0x800B2598: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x800B259C: lw          $a0, -0x2050($v0)
    ctx->r4 = MEM_W(ctx->r2, -0X2050);
    // 0x800B25A0: beql        $a0, $zero, L_800B25B4
    if (ctx->r4 == 0) {
        // 0x800B25A4: addu        $a1, $zero, $zero
        ctx->r5 = ADD32(0, 0);
            goto L_800B25B4;
    }
    goto skip_0;
    // 0x800B25A4: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    skip_0:
    // 0x800B25A8: jal         0x800CC02C
    // 0x800B25AC: nop

    func_800CC02C(rdram, ctx);
        goto after_2;
    // 0x800B25AC: nop

    after_2:
    // 0x800B25B0: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
L_800B25B4:
    // 0x800B25B4: lui         $a2, 0x1000
    ctx->r6 = S32(0X1000 << 16);
    // 0x800B25B8: lui         $s0, 0x800D
    ctx->r16 = S32(0X800D << 16);
    // 0x800B25BC: addiu       $s0, $s0, -0x2310
    ctx->r16 = ADD32(ctx->r16, -0X2310);
    // 0x800B25C0: lw          $a0, 0x44($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X44);
    // 0x800B25C4: jal         0x8005955C
    // 0x800B25C8: addu        $a3, $a1, $zero
    ctx->r7 = ADD32(ctx->r5, 0);
    func_8005955C(rdram, ctx);
        goto after_3;
    // 0x800B25C8: addu        $a3, $a1, $zero
    ctx->r7 = ADD32(ctx->r5, 0);
    after_3:
    // 0x800B25CC: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x800B25D0: lui         $a2, 0x1000
    ctx->r6 = S32(0X1000 << 16);
    // 0x800B25D4: lw          $a0, 0x64($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X64);
    // 0x800B25D8: jal         0x8005955C
    // 0x800B25DC: addu        $a3, $a1, $zero
    ctx->r7 = ADD32(ctx->r5, 0);
    func_8005955C(rdram, ctx);
        goto after_4;
    // 0x800B25DC: addu        $a3, $a1, $zero
    ctx->r7 = ADD32(ctx->r5, 0);
    after_4:
    // 0x800B25E0: lw          $a0, 0x44($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X44);
    // 0x800B25E4: jal         0x80059614
    // 0x800B25E8: nop

    func_80059614(rdram, ctx);
        goto after_5;
    // 0x800B25E8: nop

    after_5:
    // 0x800B25EC: lw          $a0, 0x64($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X64);
    // 0x800B25F0: jal         0x80059614
    // 0x800B25F4: nop

    func_80059614(rdram, ctx);
        goto after_6;
    // 0x800B25F4: nop

    after_6:
    // 0x800B25F8: jal         0x8001B7C8
    // 0x800B25FC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_8001B7C8(rdram, ctx);
        goto after_7;
    // 0x800B25FC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_7:
    // 0x800B2600: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x800B2604: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x800B2608: lw          $a0, -0x2324($v0)
    ctx->r4 = MEM_W(ctx->r2, -0X2324);
    // 0x800B260C: lui         $a2, 0x41C0
    ctx->r6 = S32(0X41C0 << 16);
    // 0x800B2610: jal         0x800B4048
    // 0x800B2614: addiu       $a1, $a1, -0x2380
    ctx->r5 = ADD32(ctx->r5, -0X2380);
    func_800B4048(rdram, ctx);
        goto after_8;
    // 0x800B2614: addiu       $a1, $a1, -0x2380
    ctx->r5 = ADD32(ctx->r5, -0X2380);
    after_8:
    // 0x800B2618: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800B261C: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x800B2620: jr          $ra
    // 0x800B2624: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x800B2624: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void fake_func_800B2628(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
;}
RECOMP_FUNC void func_800B2630(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B2630: addiu       $sp, $sp, -0x90
    ctx->r29 = ADD32(ctx->r29, -0X90);
    // 0x800B2634: sw          $s1, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r17;
    // 0x800B2638: addu        $s1, $a0, $zero
    ctx->r17 = ADD32(ctx->r4, 0);
    // 0x800B263C: sw          $ra, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r31;
    // 0x800B2640: sw          $s3, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r19;
    // 0x800B2644: sw          $s2, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r18;
    // 0x800B2648: sw          $s0, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r16;
    // 0x800B264C: lhu         $v0, 0x0($s1)
    ctx->r2 = MEM_HU(ctx->r17, 0X0);
    // 0x800B2650: sh          $v0, 0x40($sp)
    MEM_H(0X40, ctx->r29) = ctx->r2;
    // 0x800B2654: lhu         $v0, 0x2($s1)
    ctx->r2 = MEM_HU(ctx->r17, 0X2);
    // 0x800B2658: sh          $v0, 0x42($sp)
    MEM_H(0X42, ctx->r29) = ctx->r2;
    // 0x800B265C: lhu         $v0, 0x34($s1)
    ctx->r2 = MEM_HU(ctx->r17, 0X34);
    // 0x800B2660: sh          $v0, 0x68($sp)
    MEM_H(0X68, ctx->r29) = ctx->r2;
    // 0x800B2664: lhu         $v0, 0x36($s1)
    ctx->r2 = MEM_HU(ctx->r17, 0X36);
    // 0x800B2668: sh          $v0, 0x6A($sp)
    MEM_H(0X6A, ctx->r29) = ctx->r2;
    // 0x800B266C: lw          $v0, 0x10($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X10);
    // 0x800B2670: addu        $s2, $a1, $zero
    ctx->r18 = ADD32(ctx->r5, 0);
    // 0x800B2674: lhu         $v1, 0x0($v0)
    ctx->r3 = MEM_HU(ctx->r2, 0X0);
    // 0x800B2678: addiu       $v0, $zero, 0x50
    ctx->r2 = ADD32(0, 0X50);
    // 0x800B267C: sw          $zero, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = 0;
    // 0x800B2680: sh          $v0, 0x44($sp)
    MEM_H(0X44, ctx->r29) = ctx->r2;
    // 0x800B2684: sw          $v1, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r3;
    // 0x800B2688: lhu         $v0, 0x34($s1)
    ctx->r2 = MEM_HU(ctx->r17, 0X34);
    // 0x800B268C: beq         $v0, $zero, L_800B26A4
    if (ctx->r2 == 0) {
        // 0x800B2690: addu        $s3, $a3, $zero
        ctx->r19 = ADD32(ctx->r7, 0);
            goto L_800B26A4;
    }
    // 0x800B2690: addu        $s3, $a3, $zero
    ctx->r19 = ADD32(ctx->r7, 0);
    // 0x800B2694: lhu         $v0, 0x36($s1)
    ctx->r2 = MEM_HU(ctx->r17, 0X36);
    // 0x800B2698: beq         $v0, $zero, L_800B26A4
    if (ctx->r2 == 0) {
        // 0x800B269C: addiu       $v0, $zero, 0xD0
        ctx->r2 = ADD32(0, 0XD0);
            goto L_800B26A4;
    }
    // 0x800B269C: addiu       $v0, $zero, 0xD0
    ctx->r2 = ADD32(0, 0XD0);
    // 0x800B26A0: sh          $v0, 0x44($sp)
    MEM_H(0X44, ctx->r29) = ctx->r2;
L_800B26A4:
    // 0x800B26A4: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    // 0x800B26A8: lui         $a1, 0x800A
    ctx->r5 = S32(0X800A << 16);
    // 0x800B26AC: jal         0x80033CC4
    // 0x800B26B0: addiu       $a1, $a1, 0x5C20
    ctx->r5 = ADD32(ctx->r5, 0X5C20);
    sprintf_recomp(rdram, ctx);
        goto after_0;
    // 0x800B26B0: addiu       $a1, $a1, 0x5C20
    ctx->r5 = ADD32(ctx->r5, 0X5C20);
    after_0:
    // 0x800B26B4: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    // 0x800B26B8: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    // 0x800B26BC: addiu       $a2, $sp, 0x70
    ctx->r6 = ADD32(ctx->r29, 0X70);
    // 0x800B26C0: jal         0x800C6970
    // 0x800B26C4: addu        $a3, $s3, $zero
    ctx->r7 = ADD32(ctx->r19, 0);
    loadJfifAsset(rdram, ctx);
        goto after_1;
    // 0x800B26C4: addu        $a3, $s3, $zero
    ctx->r7 = ADD32(ctx->r19, 0);
    after_1:
    // 0x800B26C8: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // 0x800B26CC: sw          $a0, 0x6C($s2)
    MEM_W(0X6C, ctx->r18) = ctx->r4;
    // 0x800B26D0: lw          $v1, 0x10($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X10);
    // 0x800B26D4: lhu         $v0, 0x4($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X4);
    // 0x800B26D8: bnel        $v0, $zero, L_800B28D8
    if (ctx->r2 != 0) {
        // 0x800B26DC: addiu       $a0, $s2, 0x14
        ctx->r4 = ADD32(ctx->r18, 0X14);
            goto L_800B28D8;
    }
    goto skip_0;
    // 0x800B26DC: addiu       $a0, $s2, 0x14
    ctx->r4 = ADD32(ctx->r18, 0X14);
    skip_0:
    // 0x800B26E0: lhu         $v0, 0x3C($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X3C);
    // 0x800B26E4: sh          $v0, 0x4($v1)
    MEM_H(0X4, ctx->r3) = ctx->r2;
    // 0x800B26E8: lw          $v0, 0x6C($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X6C);
    // 0x800B26EC: lw          $v1, 0x10($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X10);
    // 0x800B26F0: lhu         $v0, 0x3E($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X3E);
    // 0x800B26F4: sh          $v0, 0x6($v1)
    MEM_H(0X6, ctx->r3) = ctx->r2;
    // 0x800B26F8: lw          $v0, 0x10($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X10);
    // 0x800B26FC: lhu         $v1, 0x0($v0)
    ctx->r3 = MEM_HU(ctx->r2, 0X0);
    // 0x800B2700: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x800B2704: beq         $v1, $v0, L_800B2740
    if (ctx->r3 == ctx->r2) {
        // 0x800B2708: slti        $v0, $v1, 0x4
        ctx->r2 = SIGNED(ctx->r3) < 0X4 ? 1 : 0;
            goto L_800B2740;
    }
    // 0x800B2708: slti        $v0, $v1, 0x4
    ctx->r2 = SIGNED(ctx->r3) < 0X4 ? 1 : 0;
    // 0x800B270C: beq         $v0, $zero, L_800B2724
    if (ctx->r2 == 0) {
        // 0x800B2710: addiu       $v0, $zero, 0x2
        ctx->r2 = ADD32(0, 0X2);
            goto L_800B2724;
    }
    // 0x800B2710: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x800B2714: beq         $v1, $v0, L_800B274C
    if (ctx->r3 == ctx->r2) {
        // 0x800B2718: addiu       $v0, $zero, 0x4
        ctx->r2 = ADD32(0, 0X4);
            goto L_800B274C;
    }
    // 0x800B2718: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // 0x800B271C: j           L_800B2750
    // 0x800B2720: nop

        goto L_800B2750;
    // 0x800B2720: nop

L_800B2724:
    // 0x800B2724: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // 0x800B2728: beq         $v1, $v0, L_800B2748
    if (ctx->r3 == ctx->r2) {
        // 0x800B272C: addiu       $v0, $zero, 0x5
        ctx->r2 = ADD32(0, 0X5);
            goto L_800B2748;
    }
    // 0x800B272C: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
    // 0x800B2730: beq         $v1, $v0, L_800B274C
    if (ctx->r3 == ctx->r2) {
        // 0x800B2734: addiu       $v0, $zero, 0x2
        ctx->r2 = ADD32(0, 0X2);
            goto L_800B274C;
    }
    // 0x800B2734: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x800B2738: j           L_800B2750
    // 0x800B273C: nop

        goto L_800B2750;
    // 0x800B273C: nop

L_800B2740:
    // 0x800B2740: j           L_800B274C
    // 0x800B2744: addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
        goto L_800B274C;
    // 0x800B2744: addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
L_800B2748:
    // 0x800B2748: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800B274C:
    // 0x800B274C: sh          $v0, 0x4($s1)
    MEM_H(0X4, ctx->r17) = ctx->r2;
L_800B2750:
    // 0x800B2750: lw          $v1, 0x10($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X10);
    // 0x800B2754: lhu         $v0, 0x0($s1)
    ctx->r2 = MEM_HU(ctx->r17, 0X0);
    // 0x800B2758: lhu         $a2, 0x4($v1)
    ctx->r6 = MEM_HU(ctx->r3, 0X4);
    // 0x800B275C: addu        $a2, $a2, $v0
    ctx->r6 = ADD32(ctx->r6, ctx->r2);
    // 0x800B2760: addiu       $a2, $a2, -0x1
    ctx->r6 = ADD32(ctx->r6, -0X1);
    // 0x800B2764: div         $zero, $a2, $v0
    lo = S32(S64(S32(ctx->r6)) / S64(S32(ctx->r2))); hi = S32(S64(S32(ctx->r6)) % S64(S32(ctx->r2)));
    // 0x800B2768: bne         $v0, $zero, L_800B2774
    if (ctx->r2 != 0) {
        // 0x800B276C: nop
    
            goto L_800B2774;
    }
    // 0x800B276C: nop

    // 0x800B2770: break       7
    do_break(2148214640);
L_800B2774:
    // 0x800B2774: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800B2778: bne         $v0, $at, L_800B278C
    if (ctx->r2 != ctx->r1) {
        // 0x800B277C: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800B278C;
    }
    // 0x800B277C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800B2780: bne         $a2, $at, L_800B278C
    if (ctx->r6 != ctx->r1) {
        // 0x800B2784: nop
    
            goto L_800B278C;
    }
    // 0x800B2784: nop

    // 0x800B2788: break       6
    do_break(2148214664);
L_800B278C:
    // 0x800B278C: mflo        $a2
    ctx->r6 = lo;
    // 0x800B2790: lhu         $v0, 0x6($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X6);
    // 0x800B2794: lhu         $v1, 0x2($s1)
    ctx->r3 = MEM_HU(ctx->r17, 0X2);
    // 0x800B2798: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800B279C: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x800B27A0: div         $zero, $v0, $v1
    lo = S32(S64(S32(ctx->r2)) / S64(S32(ctx->r3))); hi = S32(S64(S32(ctx->r2)) % S64(S32(ctx->r3)));
    // 0x800B27A4: bne         $v1, $zero, L_800B27B0
    if (ctx->r3 != 0) {
        // 0x800B27A8: nop
    
            goto L_800B27B0;
    }
    // 0x800B27A8: nop

    // 0x800B27AC: break       7
    do_break(2148214700);
L_800B27B0:
    // 0x800B27B0: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800B27B4: bne         $v1, $at, L_800B27C8
    if (ctx->r3 != ctx->r1) {
        // 0x800B27B8: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800B27C8;
    }
    // 0x800B27B8: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800B27BC: bne         $v0, $at, L_800B27C8
    if (ctx->r2 != ctx->r1) {
        // 0x800B27C0: nop
    
            goto L_800B27C8;
    }
    // 0x800B27C0: nop

    // 0x800B27C4: break       6
    do_break(2148214724);
L_800B27C8:
    // 0x800B27C8: mflo        $v0
    ctx->r2 = lo;
    // 0x800B27CC: nop

    // 0x800B27D0: nop

    // 0x800B27D4: mult        $a2, $v0
    result = S64(S32(ctx->r6)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800B27D8: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x800B27DC: mflo        $a2
    ctx->r6 = lo;
    // 0x800B27E0: sll         $a0, $a2, 1
    ctx->r4 = S32(ctx->r6 << 1);
    // 0x800B27E4: jal         0x80001ACC
    // 0x800B27E8: sw          $a2, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->r6;
    rs_malloc(rdram, ctx);
        goto after_2;
    // 0x800B27E8: sw          $a2, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->r6;
    after_2:
    // 0x800B27EC: lw          $v1, 0x8($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X8);
    // 0x800B27F0: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x800B27F4: beq         $v1, $zero, L_800B2824
    if (ctx->r3 == 0) {
        // 0x800B27F8: sw          $v0, 0x14($s1)
        MEM_W(0X14, ctx->r17) = ctx->r2;
            goto L_800B2824;
    }
    // 0x800B27F8: sw          $v0, 0x14($s1)
    MEM_W(0X14, ctx->r17) = ctx->r2;
    // 0x800B27FC: ori         $a1, $zero, 0xFFFF
    ctx->r5 = 0 | 0XFFFF;
L_800B2800:
    // 0x800B2800: lw          $v0, 0x14($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X14);
    // 0x800B2804: sll         $v1, $a0, 1
    ctx->r3 = S32(ctx->r4 << 1);
    // 0x800B2808: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x800B280C: sh          $a1, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r5;
    // 0x800B2810: lw          $v0, 0x8($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X8);
    // 0x800B2814: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x800B2818: sltu        $v0, $a0, $v0
    ctx->r2 = ctx->r4 < ctx->r2 ? 1 : 0;
    // 0x800B281C: bne         $v0, $zero, L_800B2800
    if (ctx->r2 != 0) {
        // 0x800B2820: nop
    
            goto L_800B2800;
    }
    // 0x800B2820: nop

L_800B2824:
    // 0x800B2824: lw          $v0, 0xC($s1)
    ctx->r2 = MEM_W(ctx->r17, 0XC);
    // 0x800B2828: bnel        $v0, $zero, L_800B2854
    if (ctx->r2 != 0) {
        // 0x800B282C: addu        $a1, $zero, $zero
        ctx->r5 = ADD32(0, 0);
            goto L_800B2854;
    }
    goto skip_1;
    // 0x800B282C: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    skip_1:
    // 0x800B2830: addiu       $a0, $zero, 0x30
    ctx->r4 = ADD32(0, 0X30);
    // 0x800B2834: jal         0x80001ACC
    // 0x800B2838: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    rs_malloc(rdram, ctx);
        goto after_3;
    // 0x800B2838: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    after_3:
    // 0x800B283C: sw          $v0, 0xC($s1)
    MEM_W(0XC, ctx->r17) = ctx->r2;
    // 0x800B2840: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // 0x800B2844: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x800B2848: jal         0x800078E0
    // 0x800B284C: addiu       $a2, $zero, 0x30
    ctx->r6 = ADD32(0, 0X30);
    rs_memset(rdram, ctx);
        goto after_4;
    // 0x800B284C: addiu       $a2, $zero, 0x30
    ctx->r6 = ADD32(0, 0X30);
    after_4:
    // 0x800B2850: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
L_800B2854:
    // 0x800B2854: lw          $a0, 0x8($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X8);
    // 0x800B2858: lw          $s0, 0xC($s1)
    ctx->r16 = MEM_W(ctx->r17, 0XC);
    // 0x800B285C: jal         0x80001ACC
    // 0x800B2860: sll         $a0, $a0, 1
    ctx->r4 = S32(ctx->r4 << 1);
    rs_malloc(rdram, ctx);
        goto after_5;
    // 0x800B2860: sll         $a0, $a0, 1
    ctx->r4 = S32(ctx->r4 << 1);
    after_5:
    // 0x800B2864: sw          $v0, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r2;
    // 0x800B2868: lw          $v0, 0x6C($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X6C);
    // 0x800B286C: lhu         $v1, 0x0($s1)
    ctx->r3 = MEM_HU(ctx->r17, 0X0);
    // 0x800B2870: lhu         $v0, 0x3C($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X3C);
    // 0x800B2874: divu        $zero, $v0, $v1
    lo = S32(U32(ctx->r2) / U32(ctx->r3)); hi = S32(U32(ctx->r2) % U32(ctx->r3));
    // 0x800B2878: bne         $v1, $zero, L_800B2884
    if (ctx->r3 != 0) {
        // 0x800B287C: nop
    
            goto L_800B2884;
    }
    // 0x800B287C: nop

    // 0x800B2880: break       7
    do_break(2148214912);
L_800B2884:
    // 0x800B2884: mflo        $v0
    ctx->r2 = lo;
    // 0x800B2888: sh          $v0, 0x8($s0)
    MEM_H(0X8, ctx->r16) = ctx->r2;
    // 0x800B288C: lw          $v0, 0x6C($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X6C);
    // 0x800B2890: lhu         $v1, 0x3E($v0)
    ctx->r3 = MEM_HU(ctx->r2, 0X3E);
    // 0x800B2894: lhu         $v0, 0x2($s1)
    ctx->r2 = MEM_HU(ctx->r17, 0X2);
    // 0x800B2898: divu        $zero, $v1, $v0
    lo = S32(U32(ctx->r3) / U32(ctx->r2)); hi = S32(U32(ctx->r3) % U32(ctx->r2));
    // 0x800B289C: bne         $v0, $zero, L_800B28A8
    if (ctx->r2 != 0) {
        // 0x800B28A0: nop
    
            goto L_800B28A8;
    }
    // 0x800B28A0: nop

    // 0x800B28A4: break       7
    do_break(2148214948);
L_800B28A8:
    // 0x800B28A8: mflo        $v1
    ctx->r3 = lo;
    // 0x800B28AC: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800B28B0: lwc1        $f0, 0x5C3C($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X5C3C);
    // 0x800B28B4: swc1        $f0, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f0.u32l;
    // 0x800B28B8: swc1        $f0, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->f0.u32l;
    // 0x800B28BC: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // 0x800B28C0: sb          $v0, 0x2C($s0)
    MEM_B(0X2C, ctx->r16) = ctx->r2;
    // 0x800B28C4: sb          $v0, 0x2D($s0)
    MEM_B(0X2D, ctx->r16) = ctx->r2;
    // 0x800B28C8: sb          $v0, 0x2E($s0)
    MEM_B(0X2E, ctx->r16) = ctx->r2;
    // 0x800B28CC: sb          $v0, 0x2F($s0)
    MEM_B(0X2F, ctx->r16) = ctx->r2;
    // 0x800B28D0: sh          $v1, 0xA($s0)
    MEM_H(0XA, ctx->r16) = ctx->r3;
    // 0x800B28D4: addiu       $a0, $s2, 0x14
    ctx->r4 = ADD32(ctx->r18, 0X14);
L_800B28D8:
    // 0x800B28D8: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x800B28DC: addiu       $t3, $v0, 0x5C2C
    ctx->r11 = ADD32(ctx->r2, 0X5C2C);
    // 0x800B28E0: lw          $t0, 0x0($t3)
    ctx->r8 = MEM_W(ctx->r11, 0X0);
    // 0x800B28E4: lh          $t1, 0x4($t3)
    ctx->r9 = MEM_H(ctx->r11, 0X4);
    // 0x800B28E8: sw          $t0, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r8;
    // 0x800B28EC: sh          $t1, 0x4($s2)
    MEM_H(0X4, ctx->r18) = ctx->r9;
    // 0x800B28F0: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x800B28F4: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x800B28F8: addiu       $t3, $v0, 0x5C34
    ctx->r11 = ADD32(ctx->r2, 0X5C34);
    // 0x800B28FC: lw          $t0, 0x0($t3)
    ctx->r8 = MEM_W(ctx->r11, 0X0);
    // 0x800B2900: lh          $t1, 0x4($t3)
    ctx->r9 = MEM_H(ctx->r11, 0X4);
    // 0x800B2904: lb          $t2, 0x6($t3)
    ctx->r10 = MEM_B(ctx->r11, 0X6);
    // 0x800B2908: sw          $t0, 0x8($s2)
    MEM_W(0X8, ctx->r18) = ctx->r8;
    // 0x800B290C: sh          $t1, 0xC($s2)
    MEM_H(0XC, ctx->r18) = ctx->r9;
    // 0x800B2910: sb          $t2, 0xE($s2)
    MEM_B(0XE, ctx->r18) = ctx->r10;
    // 0x800B2914: lbu         $v0, 0x18($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X18);
    // 0x800B2918: addiu       $a2, $zero, 0x24
    ctx->r6 = ADD32(0, 0X24);
    // 0x800B291C: addiu       $v0, $v0, 0x41
    ctx->r2 = ADD32(ctx->r2, 0X41);
    // 0x800B2920: sb          $v0, 0x1($s2)
    MEM_B(0X1, ctx->r18) = ctx->r2;
    // 0x800B2924: lbu         $v0, 0x18($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X18);
    // 0x800B2928: addiu       $s0, $s2, 0x8
    ctx->r16 = ADD32(ctx->r18, 0X8);
    // 0x800B292C: addiu       $v0, $v0, 0x41
    ctx->r2 = ADD32(ctx->r2, 0X41);
    // 0x800B2930: jal         0x800078E0
    // 0x800B2934: sb          $v0, 0x9($s2)
    MEM_B(0X9, ctx->r18) = ctx->r2;
    rs_memset(rdram, ctx);
        goto after_6;
    // 0x800B2934: sb          $v0, 0x9($s2)
    MEM_B(0X9, ctx->r18) = ctx->r2;
    after_6:
    // 0x800B2938: addiu       $a0, $s2, 0x38
    ctx->r4 = ADD32(ctx->r18, 0X38);
    // 0x800B293C: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x800B2940: jal         0x800078E0
    // 0x800B2944: addiu       $a2, $zero, 0x34
    ctx->r6 = ADD32(0, 0X34);
    rs_memset(rdram, ctx);
        goto after_7;
    // 0x800B2944: addiu       $a2, $zero, 0x34
    ctx->r6 = ADD32(0, 0X34);
    after_7:
    // 0x800B2948: addiu       $a0, $s2, 0x28
    ctx->r4 = ADD32(ctx->r18, 0X28);
    // 0x800B294C: jal         0x8000761C
    // 0x800B2950: addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    rs_strcpy(rdram, ctx);
        goto after_8;
    // 0x800B2950: addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    after_8:
    // 0x800B2954: sw          $s0, 0x5C($s2)
    MEM_W(0X5C, ctx->r18) = ctx->r16;
    // 0x800B2958: lhu         $v0, 0x0($s1)
    ctx->r2 = MEM_HU(ctx->r17, 0X0);
    // 0x800B295C: sh          $v0, 0x60($s2)
    MEM_H(0X60, ctx->r18) = ctx->r2;
    // 0x800B2960: lhu         $v0, 0x2($s1)
    ctx->r2 = MEM_HU(ctx->r17, 0X2);
    // 0x800B2964: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x800B2968: sb          $a1, 0x64($s2)
    MEM_B(0X64, ctx->r18) = ctx->r5;
    // 0x800B296C: sh          $v0, 0x62($s2)
    MEM_H(0X62, ctx->r18) = ctx->r2;
    // 0x800B2970: lw          $v0, 0x10($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X10);
    // 0x800B2974: lhu         $a0, 0x0($v0)
    ctx->r4 = MEM_HU(ctx->r2, 0X0);
    // 0x800B2978: sh          $a0, 0x66($s2)
    MEM_H(0X66, ctx->r18) = ctx->r4;
    // 0x800B297C: lw          $v1, 0x1C($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X1C);
    // 0x800B2980: andi        $v0, $v1, 0x6
    ctx->r2 = ctx->r3 & 0X6;
    // 0x800B2984: beq         $v0, $zero, L_800B2A00
    if (ctx->r2 == 0) {
        // 0x800B2988: andi        $v0, $v1, 0x2
        ctx->r2 = ctx->r3 & 0X2;
            goto L_800B2A00;
    }
    // 0x800B2988: andi        $v0, $v1, 0x2
    ctx->r2 = ctx->r3 & 0X2;
    // 0x800B298C: beq         $v0, $zero, L_800B29A0
    if (ctx->r2 == 0) {
        // 0x800B2990: ori         $v0, $a0, 0x800
        ctx->r2 = ctx->r4 | 0X800;
            goto L_800B29A0;
    }
    // 0x800B2990: ori         $v0, $a0, 0x800
    ctx->r2 = ctx->r4 | 0X800;
    // 0x800B2994: sh          $v0, 0x66($s2)
    MEM_H(0X66, ctx->r18) = ctx->r2;
    // 0x800B2998: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // 0x800B299C: sw          $v0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r2;
L_800B29A0:
    // 0x800B29A0: lw          $v0, 0x1C($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X1C);
    // 0x800B29A4: andi        $v0, $v0, 0x4
    ctx->r2 = ctx->r2 & 0X4;
    // 0x800B29A8: beq         $v0, $zero, L_800B29C4
    if (ctx->r2 == 0) {
        // 0x800B29AC: nop
    
            goto L_800B29C4;
    }
    // 0x800B29AC: nop

    // 0x800B29B0: lhu         $v0, 0x66($s2)
    ctx->r2 = MEM_HU(ctx->r18, 0X66);
    // 0x800B29B4: ori         $v0, $v0, 0x400
    ctx->r2 = ctx->r2 | 0X400;
    // 0x800B29B8: sh          $v0, 0x66($s2)
    MEM_H(0X66, ctx->r18) = ctx->r2;
    // 0x800B29BC: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
    // 0x800B29C0: sw          $v0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r2;
L_800B29C4:
    // 0x800B29C4: lhu         $v0, 0x0($s1)
    ctx->r2 = MEM_HU(ctx->r17, 0X0);
    // 0x800B29C8: srl         $v0, $v0, 1
    ctx->r2 = S32(U32(ctx->r2) >> 1);
    // 0x800B29CC: sh          $v0, 0x40($sp)
    MEM_H(0X40, ctx->r29) = ctx->r2;
    // 0x800B29D0: lhu         $v0, 0x2($s1)
    ctx->r2 = MEM_HU(ctx->r17, 0X2);
    // 0x800B29D4: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    // 0x800B29D8: srl         $v0, $v0, 1
    ctx->r2 = S32(U32(ctx->r2) >> 1);
    // 0x800B29DC: sh          $v0, 0x42($sp)
    MEM_H(0X42, ctx->r29) = ctx->r2;
    // 0x800B29E0: jal         0x800B43F4
    // 0x800B29E4: sb          $a1, 0x65($s2)
    MEM_B(0X65, ctx->r18) = ctx->r5;
    func_800B43F4(rdram, ctx);
        goto after_9;
    // 0x800B29E4: sb          $a1, 0x65($s2)
    MEM_B(0X65, ctx->r18) = ctx->r5;
    after_9:
    // 0x800B29E8: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // 0x800B29EC: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    // 0x800B29F0: addiu       $a2, $sp, 0x70
    ctx->r6 = ADD32(ctx->r29, 0X70);
    // 0x800B29F4: jal         0x800C6970
    // 0x800B29F8: addu        $a3, $s3, $zero
    ctx->r7 = ADD32(ctx->r19, 0);
    loadJfifAsset(rdram, ctx);
        goto after_10;
    // 0x800B29F8: addu        $a3, $s3, $zero
    ctx->r7 = ADD32(ctx->r19, 0);
    after_10:
    // 0x800B29FC: sw          $v0, 0x70($s2)
    MEM_W(0X70, ctx->r18) = ctx->r2;
L_800B2A00:
    // 0x800B2A00: lhu         $v1, 0x0($s1)
    ctx->r3 = MEM_HU(ctx->r17, 0X0);
    // 0x800B2A04: lhu         $v0, 0x2($s1)
    ctx->r2 = MEM_HU(ctx->r17, 0X2);
    // 0x800B2A08: mult        $v1, $v0
    result = S64(S32(ctx->r3)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800B2A0C: mflo        $a1
    ctx->r5 = lo;
    // 0x800B2A10: lhu         $v0, 0x4($s1)
    ctx->r2 = MEM_HU(ctx->r17, 0X4);
    // 0x800B2A14: nop

    // 0x800B2A18: mult        $a1, $v0
    result = S64(S32(ctx->r5)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800B2A1C: mflo        $v0
    ctx->r2 = lo;
    // 0x800B2A20: srl         $v1, $v0, 31
    ctx->r3 = S32(U32(ctx->r2) >> 31);
    // 0x800B2A24: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800B2A28: lw          $v1, 0x1C($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X1C);
    // 0x800B2A2C: andi        $v1, $v1, 0x6
    ctx->r3 = ctx->r3 & 0X6;
    // 0x800B2A30: beq         $v1, $zero, L_800B2A4C
    if (ctx->r3 == 0) {
        // 0x800B2A34: sra         $a0, $v0, 1
        ctx->r4 = S32(SIGNED(ctx->r2) >> 1);
            goto L_800B2A4C;
    }
    // 0x800B2A34: sra         $a0, $v0, 1
    ctx->r4 = S32(SIGNED(ctx->r2) >> 1);
    // 0x800B2A38: addu        $v0, $a1, $zero
    ctx->r2 = ADD32(ctx->r5, 0);
    // 0x800B2A3C: bltzl       $v0, L_800B2A44
    if (SIGNED(ctx->r2) < 0) {
        // 0x800B2A40: addiu       $v0, $v0, 0x3
        ctx->r2 = ADD32(ctx->r2, 0X3);
            goto L_800B2A44;
    }
    goto skip_2;
    // 0x800B2A40: addiu       $v0, $v0, 0x3
    ctx->r2 = ADD32(ctx->r2, 0X3);
    skip_2:
L_800B2A44:
    // 0x800B2A44: j           L_800B2A50
    // 0x800B2A48: sra         $s0, $v0, 2
    ctx->r16 = S32(SIGNED(ctx->r2) >> 2);
        goto L_800B2A50;
    // 0x800B2A48: sra         $s0, $v0, 2
    ctx->r16 = S32(SIGNED(ctx->r2) >> 2);
L_800B2A4C:
    // 0x800B2A4C: addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
L_800B2A50:
    // 0x800B2A50: jal         0x80001ACC
    // 0x800B2A54: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    rs_malloc(rdram, ctx);
        goto after_11;
    // 0x800B2A54: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    after_11:
    // 0x800B2A58: sw          $v0, 0x38($s2)
    MEM_W(0X38, ctx->r18) = ctx->r2;
    // 0x800B2A5C: lw          $v0, 0x1C($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X1C);
    // 0x800B2A60: andi        $v0, $v0, 0x6
    ctx->r2 = ctx->r2 & 0X6;
    // 0x800B2A64: beq         $v0, $zero, L_800B2A78
    if (ctx->r2 == 0) {
        // 0x800B2A68: addu        $a0, $s0, $zero
        ctx->r4 = ADD32(ctx->r16, 0);
            goto L_800B2A78;
    }
    // 0x800B2A68: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x800B2A6C: jal         0x80001ACC
    // 0x800B2A70: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    rs_malloc(rdram, ctx);
        goto after_12;
    // 0x800B2A70: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    after_12:
    // 0x800B2A74: sw          $v0, 0x3C($s2)
    MEM_W(0X3C, ctx->r18) = ctx->r2;
L_800B2A78:
    // 0x800B2A78: sw          $zero, 0x10($s2)
    MEM_W(0X10, ctx->r18) = 0;
    // 0x800B2A7C: lw          $ra, 0x88($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X88);
    // 0x800B2A80: lw          $s3, 0x84($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X84);
    // 0x800B2A84: lw          $s2, 0x80($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X80);
    // 0x800B2A88: lw          $s1, 0x7C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X7C);
    // 0x800B2A8C: lw          $s0, 0x78($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X78);
    // 0x800B2A90: jr          $ra
    // 0x800B2A94: addiu       $sp, $sp, 0x90
    ctx->r29 = ADD32(ctx->r29, 0X90);
    return;
    // 0x800B2A94: addiu       $sp, $sp, 0x90
    ctx->r29 = ADD32(ctx->r29, 0X90);
;}
RECOMP_FUNC void func_800B2A98(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B2A98: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x800B2A9C: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x800B2AA0: addu        $s1, $a0, $zero
    ctx->r17 = ADD32(ctx->r4, 0);
    // 0x800B2AA4: sw          $s5, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r21;
    // 0x800B2AA8: addu        $s5, $a1, $zero
    ctx->r21 = ADD32(ctx->r5, 0);
    // 0x800B2AAC: sw          $s7, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r23;
    // 0x800B2AB0: addu        $s7, $a2, $zero
    ctx->r23 = ADD32(ctx->r6, 0);
    // 0x800B2AB4: addiu       $a0, $zero, 0x38
    ctx->r4 = ADD32(0, 0X38);
    // 0x800B2AB8: sw          $s6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r22;
    // 0x800B2ABC: lw          $s6, 0x48($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X48);
    // 0x800B2AC0: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x800B2AC4: sw          $fp, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r30;
    // 0x800B2AC8: sw          $s4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r20;
    // 0x800B2ACC: sw          $s3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r19;
    // 0x800B2AD0: sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // 0x800B2AD4: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x800B2AD8: sw          $a3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r7;
    // 0x800B2ADC: lw          $v0, 0x10($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X10);
    // 0x800B2AE0: lw          $fp, 0x4C($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X4C);
    // 0x800B2AE4: lhu         $s3, 0x0($s1)
    ctx->r19 = MEM_HU(ctx->r17, 0X0);
    // 0x800B2AE8: lhu         $s4, 0x2($s1)
    ctx->r20 = MEM_HU(ctx->r17, 0X2);
    // 0x800B2AEC: lhu         $s2, 0x0($v0)
    ctx->r18 = MEM_HU(ctx->r2, 0X0);
    // 0x800B2AF0: jal         0x80001ACC
    // 0x800B2AF4: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    rs_malloc(rdram, ctx);
        goto after_0;
    // 0x800B2AF4: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    after_0:
    // 0x800B2AF8: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    // 0x800B2AFC: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x800B2B00: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x800B2B04: jal         0x800078E0
    // 0x800B2B08: addiu       $a2, $zero, 0x38
    ctx->r6 = ADD32(0, 0X38);
    rs_memset(rdram, ctx);
        goto after_1;
    // 0x800B2B08: addiu       $a2, $zero, 0x38
    ctx->r6 = ADD32(0, 0X38);
    after_1:
    // 0x800B2B0C: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    // 0x800B2B10: jal         0x80001ACC
    // 0x800B2B14: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    rs_malloc(rdram, ctx);
        goto after_2;
    // 0x800B2B14: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    after_2:
    // 0x800B2B18: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // 0x800B2B1C: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x800B2B20: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    // 0x800B2B24: jal         0x800078E0
    // 0x800B2B28: sw          $a0, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->r4;
    rs_memset(rdram, ctx);
        goto after_3;
    // 0x800B2B28: sw          $a0, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->r4;
    after_3:
    // 0x800B2B2C: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x800B2B30: lw          $v0, 0x10($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X10);
    // 0x800B2B34: lbu         $a0, -0x37B0($v1)
    ctx->r4 = MEM_BU(ctx->r3, -0X37B0);
    // 0x800B2B38: sh          $s2, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r18;
    // 0x800B2B3C: addiu       $v0, $a0, 0x1
    ctx->r2 = ADD32(ctx->r4, 0X1);
    // 0x800B2B40: addu        $s2, $s0, $zero
    ctx->r18 = ADD32(ctx->r16, 0);
    // 0x800B2B44: sb          $v0, -0x37B0($v1)
    MEM_B(-0X37B0, ctx->r3) = ctx->r2;
    // 0x800B2B48: sb          $a0, 0x18($s0)
    MEM_B(0X18, ctx->r16) = ctx->r4;
    // 0x800B2B4C: lbu         $v0, -0x37B0($v1)
    ctx->r2 = MEM_BU(ctx->r3, -0X37B0);
    // 0x800B2B50: lw          $t0, 0x44($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X44);
    // 0x800B2B54: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x800B2B58: sw          $t0, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->r8;
    // 0x800B2B5C: sh          $s3, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r19;
    // 0x800B2B60: sh          $s4, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r20;
    // 0x800B2B64: sb          $v0, -0x37B0($v1)
    MEM_B(-0X37B0, ctx->r3) = ctx->r2;
    // 0x800B2B68: lbu         $v0, 0x18($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X18);
    // 0x800B2B6C: lw          $v1, 0x10($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X10);
    // 0x800B2B70: sb          $v0, 0x18($s2)
    MEM_B(0X18, ctx->r18) = ctx->r2;
    // 0x800B2B74: sh          $s5, 0x4($v1)
    MEM_H(0X4, ctx->r3) = ctx->r21;
    // 0x800B2B78: lw          $v0, 0x10($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X10);
    // 0x800B2B7C: sh          $s7, 0x6($v0)
    MEM_H(0X6, ctx->r2) = ctx->r23;
    // 0x800B2B80: lw          $v0, 0x10($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X10);
    // 0x800B2B84: sh          $s6, 0x34($s2)
    MEM_H(0X34, ctx->r18) = ctx->r22;
    // 0x800B2B88: sh          $fp, 0x36($s2)
    MEM_H(0X36, ctx->r18) = ctx->r30;
    // 0x800B2B8C: lhu         $v1, 0x0($v0)
    ctx->r3 = MEM_HU(ctx->r2, 0X0);
    // 0x800B2B90: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x800B2B94: beq         $v1, $v0, L_800B2BD0
    if (ctx->r3 == ctx->r2) {
        // 0x800B2B98: slti        $v0, $v1, 0x4
        ctx->r2 = SIGNED(ctx->r3) < 0X4 ? 1 : 0;
            goto L_800B2BD0;
    }
    // 0x800B2B98: slti        $v0, $v1, 0x4
    ctx->r2 = SIGNED(ctx->r3) < 0X4 ? 1 : 0;
    // 0x800B2B9C: beq         $v0, $zero, L_800B2BB4
    if (ctx->r2 == 0) {
        // 0x800B2BA0: addiu       $v0, $zero, 0x2
        ctx->r2 = ADD32(0, 0X2);
            goto L_800B2BB4;
    }
    // 0x800B2BA0: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x800B2BA4: beq         $v1, $v0, L_800B2BDC
    if (ctx->r3 == ctx->r2) {
        // 0x800B2BA8: addiu       $v0, $zero, 0x4
        ctx->r2 = ADD32(0, 0X4);
            goto L_800B2BDC;
    }
    // 0x800B2BA8: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // 0x800B2BAC: j           L_800B2BE0
    // 0x800B2BB0: nop

        goto L_800B2BE0;
    // 0x800B2BB0: nop

L_800B2BB4:
    // 0x800B2BB4: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // 0x800B2BB8: beq         $v1, $v0, L_800B2BD8
    if (ctx->r3 == ctx->r2) {
        // 0x800B2BBC: addiu       $v0, $zero, 0x5
        ctx->r2 = ADD32(0, 0X5);
            goto L_800B2BD8;
    }
    // 0x800B2BBC: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
    // 0x800B2BC0: beq         $v1, $v0, L_800B2BDC
    if (ctx->r3 == ctx->r2) {
        // 0x800B2BC4: addiu       $v0, $zero, 0x2
        ctx->r2 = ADD32(0, 0X2);
            goto L_800B2BDC;
    }
    // 0x800B2BC4: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x800B2BC8: j           L_800B2BE0
    // 0x800B2BCC: nop

        goto L_800B2BE0;
    // 0x800B2BCC: nop

L_800B2BD0:
    // 0x800B2BD0: j           L_800B2BDC
    // 0x800B2BD4: addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
        goto L_800B2BDC;
    // 0x800B2BD4: addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
L_800B2BD8:
    // 0x800B2BD8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800B2BDC:
    // 0x800B2BDC: sh          $v0, 0x4($s2)
    MEM_H(0X4, ctx->r18) = ctx->r2;
L_800B2BE0:
    // 0x800B2BE0: lw          $a0, 0x10($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X10);
    // 0x800B2BE4: lhu         $v0, 0x0($s2)
    ctx->r2 = MEM_HU(ctx->r18, 0X0);
    // 0x800B2BE8: lhu         $v1, 0x4($a0)
    ctx->r3 = MEM_HU(ctx->r4, 0X4);
    // 0x800B2BEC: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x800B2BF0: addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
    // 0x800B2BF4: div         $zero, $v1, $v0
    lo = S32(S64(S32(ctx->r3)) / S64(S32(ctx->r2))); hi = S32(S64(S32(ctx->r3)) % S64(S32(ctx->r2)));
    // 0x800B2BF8: bne         $v0, $zero, L_800B2C04
    if (ctx->r2 != 0) {
        // 0x800B2BFC: nop
    
            goto L_800B2C04;
    }
    // 0x800B2BFC: nop

    // 0x800B2C00: break       7
    do_break(2148215808);
L_800B2C04:
    // 0x800B2C04: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800B2C08: bne         $v0, $at, L_800B2C1C
    if (ctx->r2 != ctx->r1) {
        // 0x800B2C0C: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800B2C1C;
    }
    // 0x800B2C0C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800B2C10: bne         $v1, $at, L_800B2C1C
    if (ctx->r3 != ctx->r1) {
        // 0x800B2C14: nop
    
            goto L_800B2C1C;
    }
    // 0x800B2C14: nop

    // 0x800B2C18: break       6
    do_break(2148215832);
L_800B2C1C:
    // 0x800B2C1C: mflo        $v1
    ctx->r3 = lo;
    // 0x800B2C20: lhu         $v0, 0x6($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X6);
    // 0x800B2C24: lhu         $a0, 0x2($s2)
    ctx->r4 = MEM_HU(ctx->r18, 0X2);
    // 0x800B2C28: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x800B2C2C: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x800B2C30: div         $zero, $v0, $a0
    lo = S32(S64(S32(ctx->r2)) / S64(S32(ctx->r4))); hi = S32(S64(S32(ctx->r2)) % S64(S32(ctx->r4)));
    // 0x800B2C34: bne         $a0, $zero, L_800B2C40
    if (ctx->r4 != 0) {
        // 0x800B2C38: nop
    
            goto L_800B2C40;
    }
    // 0x800B2C38: nop

    // 0x800B2C3C: break       7
    do_break(2148215868);
L_800B2C40:
    // 0x800B2C40: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800B2C44: bne         $a0, $at, L_800B2C58
    if (ctx->r4 != ctx->r1) {
        // 0x800B2C48: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800B2C58;
    }
    // 0x800B2C48: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800B2C4C: bne         $v0, $at, L_800B2C58
    if (ctx->r2 != ctx->r1) {
        // 0x800B2C50: nop
    
            goto L_800B2C58;
    }
    // 0x800B2C50: nop

    // 0x800B2C54: break       6
    do_break(2148215892);
L_800B2C58:
    // 0x800B2C58: mflo        $v0
    ctx->r2 = lo;
    // 0x800B2C5C: nop

    // 0x800B2C60: nop

    // 0x800B2C64: mult        $v1, $v0
    result = S64(S32(ctx->r3)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800B2C68: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x800B2C6C: mflo        $v1
    ctx->r3 = lo;
    // 0x800B2C70: sll         $a0, $v1, 1
    ctx->r4 = S32(ctx->r3 << 1);
    // 0x800B2C74: jal         0x80001ACC
    // 0x800B2C78: sw          $v1, 0x8($s2)
    MEM_W(0X8, ctx->r18) = ctx->r3;
    rs_malloc(rdram, ctx);
        goto after_4;
    // 0x800B2C78: sw          $v1, 0x8($s2)
    MEM_W(0X8, ctx->r18) = ctx->r3;
    after_4:
    // 0x800B2C7C: addiu       $a0, $zero, 0x30
    ctx->r4 = ADD32(0, 0X30);
    // 0x800B2C80: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x800B2C84: jal         0x80001ACC
    // 0x800B2C88: sw          $v0, 0x14($s2)
    MEM_W(0X14, ctx->r18) = ctx->r2;
    rs_malloc(rdram, ctx);
        goto after_5;
    // 0x800B2C88: sw          $v0, 0x14($s2)
    MEM_W(0X14, ctx->r18) = ctx->r2;
    after_5:
    // 0x800B2C8C: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // 0x800B2C90: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x800B2C94: addiu       $a2, $zero, 0x30
    ctx->r6 = ADD32(0, 0X30);
    // 0x800B2C98: jal         0x800078E0
    // 0x800B2C9C: sw          $a0, 0xC($s2)
    MEM_W(0XC, ctx->r18) = ctx->r4;
    rs_memset(rdram, ctx);
        goto after_6;
    // 0x800B2C9C: sw          $a0, 0xC($s2)
    MEM_W(0XC, ctx->r18) = ctx->r4;
    after_6:
    // 0x800B2CA0: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x800B2CA4: lw          $a0, 0x8($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X8);
    // 0x800B2CA8: lw          $s0, 0xC($s2)
    ctx->r16 = MEM_W(ctx->r18, 0XC);
    // 0x800B2CAC: jal         0x80001ACC
    // 0x800B2CB0: sll         $a0, $a0, 1
    ctx->r4 = S32(ctx->r4 << 1);
    rs_malloc(rdram, ctx);
        goto after_7;
    // 0x800B2CB0: sll         $a0, $a0, 1
    ctx->r4 = S32(ctx->r4 << 1);
    after_7:
    // 0x800B2CB4: sw          $v0, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r2;
    // 0x800B2CB8: lhu         $v1, 0x0($s2)
    ctx->r3 = MEM_HU(ctx->r18, 0X0);
    // 0x800B2CBC: andi        $v0, $s5, 0xFFFF
    ctx->r2 = ctx->r21 & 0XFFFF;
    // 0x800B2CC0: divu        $zero, $v0, $v1
    lo = S32(U32(ctx->r2) / U32(ctx->r3)); hi = S32(U32(ctx->r2) % U32(ctx->r3));
    // 0x800B2CC4: bne         $v1, $zero, L_800B2CD0
    if (ctx->r3 != 0) {
        // 0x800B2CC8: nop
    
            goto L_800B2CD0;
    }
    // 0x800B2CC8: nop

    // 0x800B2CCC: break       7
    do_break(2148216012);
L_800B2CD0:
    // 0x800B2CD0: mflo        $v0
    ctx->r2 = lo;
    // 0x800B2CD4: sh          $v0, 0x8($s0)
    MEM_H(0X8, ctx->r16) = ctx->r2;
    // 0x800B2CD8: lhu         $v0, 0x2($s2)
    ctx->r2 = MEM_HU(ctx->r18, 0X2);
    // 0x800B2CDC: andi        $a0, $s7, 0xFFFF
    ctx->r4 = ctx->r23 & 0XFFFF;
    // 0x800B2CE0: divu        $zero, $a0, $v0
    lo = S32(U32(ctx->r4) / U32(ctx->r2)); hi = S32(U32(ctx->r4) % U32(ctx->r2));
    // 0x800B2CE4: bne         $v0, $zero, L_800B2CF0
    if (ctx->r2 != 0) {
        // 0x800B2CE8: nop
    
            goto L_800B2CF0;
    }
    // 0x800B2CE8: nop

    // 0x800B2CEC: break       7
    do_break(2148216044);
L_800B2CF0:
    // 0x800B2CF0: mflo        $a0
    ctx->r4 = lo;
    // 0x800B2CF4: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800B2CF8: lwc1        $f0, 0x5C48($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X5C48);
    // 0x800B2CFC: addiu       $v1, $zero, 0xFF
    ctx->r3 = ADD32(0, 0XFF);
    // 0x800B2D00: swc1        $f0, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f0.u32l;
    // 0x800B2D04: swc1        $f0, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->f0.u32l;
    // 0x800B2D08: sb          $v1, 0x2C($s0)
    MEM_B(0X2C, ctx->r16) = ctx->r3;
    // 0x800B2D0C: sb          $v1, 0x2D($s0)
    MEM_B(0X2D, ctx->r16) = ctx->r3;
    // 0x800B2D10: sb          $v1, 0x2E($s0)
    MEM_B(0X2E, ctx->r16) = ctx->r3;
    // 0x800B2D14: sb          $v1, 0x2F($s0)
    MEM_B(0X2F, ctx->r16) = ctx->r3;
    // 0x800B2D18: addu        $v0, $s2, $zero
    ctx->r2 = ADD32(ctx->r18, 0);
    // 0x800B2D1C: sh          $a0, 0xA($s0)
    MEM_H(0XA, ctx->r16) = ctx->r4;
    // 0x800B2D20: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x800B2D24: lw          $fp, 0x30($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X30);
    // 0x800B2D28: lw          $s7, 0x2C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X2C);
    // 0x800B2D2C: lw          $s6, 0x28($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X28);
    // 0x800B2D30: lw          $s5, 0x24($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X24);
    // 0x800B2D34: lw          $s4, 0x20($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X20);
    // 0x800B2D38: lw          $s3, 0x1C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X1C);
    // 0x800B2D3C: lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X18);
    // 0x800B2D40: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x800B2D44: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x800B2D48: jr          $ra
    // 0x800B2D4C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x800B2D4C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_800B2D50(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B2D50: addiu       $sp, $sp, -0xE0
    ctx->r29 = ADD32(ctx->r29, -0XE0);
    // 0x800B2D54: sw          $s1, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->r17;
    // 0x800B2D58: addu        $s1, $a0, $zero
    ctx->r17 = ADD32(ctx->r4, 0);
    // 0x800B2D5C: sw          $s2, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->r18;
    // 0x800B2D60: addu        $s2, $a1, $zero
    ctx->r18 = ADD32(ctx->r5, 0);
    // 0x800B2D64: sw          $s3, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->r19;
    // 0x800B2D68: addu        $s3, $a2, $zero
    ctx->r19 = ADD32(ctx->r6, 0);
    // 0x800B2D6C: addiu       $a0, $zero, 0x38
    ctx->r4 = ADD32(0, 0X38);
    // 0x800B2D70: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x800B2D74: sw          $s5, 0xD4($sp)
    MEM_W(0XD4, ctx->r29) = ctx->r21;
    // 0x800B2D78: addu        $s5, $a3, $zero
    ctx->r21 = ADD32(ctx->r7, 0);
    // 0x800B2D7C: sw          $ra, 0xDC($sp)
    MEM_W(0XDC, ctx->r29) = ctx->r31;
    // 0x800B2D80: sw          $s6, 0xD8($sp)
    MEM_W(0XD8, ctx->r29) = ctx->r22;
    // 0x800B2D84: sw          $s4, 0xD0($sp)
    MEM_W(0XD0, ctx->r29) = ctx->r20;
    // 0x800B2D88: jal         0x80001ACC
    // 0x800B2D8C: sw          $s0, 0xC0($sp)
    MEM_W(0XC0, ctx->r29) = ctx->r16;
    rs_malloc(rdram, ctx);
        goto after_0;
    // 0x800B2D8C: sw          $s0, 0xC0($sp)
    MEM_W(0XC0, ctx->r29) = ctx->r16;
    after_0:
    // 0x800B2D90: addu        $s4, $v0, $zero
    ctx->r20 = ADD32(ctx->r2, 0);
    // 0x800B2D94: addu        $a0, $s4, $zero
    ctx->r4 = ADD32(ctx->r20, 0);
    // 0x800B2D98: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x800B2D9C: jal         0x800078E0
    // 0x800B2DA0: addiu       $a2, $zero, 0x38
    ctx->r6 = ADD32(0, 0X38);
    rs_memset(rdram, ctx);
        goto after_1;
    // 0x800B2DA0: addiu       $a2, $zero, 0x38
    ctx->r6 = ADD32(0, 0X38);
    after_1:
    // 0x800B2DA4: addiu       $s0, $sp, 0x20
    ctx->r16 = ADD32(ctx->r29, 0X20);
    // 0x800B2DA8: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x800B2DAC: lui         $a1, 0x800A
    ctx->r5 = S32(0X800A << 16);
    // 0x800B2DB0: addiu       $a1, $a1, 0x5C20
    ctx->r5 = ADD32(ctx->r5, 0X5C20);
    // 0x800B2DB4: jal         0x80033CC4
    // 0x800B2DB8: addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    sprintf_recomp(rdram, ctx);
        goto after_2;
    // 0x800B2DB8: addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    after_2:
    // 0x800B2DBC: jal         0x8006488C
    // 0x800B2DC0: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    load_asset(rdram, ctx);
        goto after_3;
    // 0x800B2DC0: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_3:
    // 0x800B2DC4: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x800B2DC8: lbu         $a0, -0x37B0($v1)
    ctx->r4 = MEM_BU(ctx->r3, -0X37B0);
    // 0x800B2DCC: sw          $v0, 0x10($s4)
    MEM_W(0X10, ctx->r20) = ctx->r2;
    // 0x800B2DD0: lw          $a1, 0x10($s4)
    ctx->r5 = MEM_W(ctx->r20, 0X10);
    // 0x800B2DD4: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x800B2DD8: sw          $zero, 0x1C($s4)
    MEM_W(0X1C, ctx->r20) = 0;
    // 0x800B2DDC: sh          $s2, 0x0($s4)
    MEM_H(0X0, ctx->r20) = ctx->r18;
    // 0x800B2DE0: sh          $s3, 0x2($s4)
    MEM_H(0X2, ctx->r20) = ctx->r19;
    // 0x800B2DE4: sh          $v0, 0x4($s4)
    MEM_H(0X4, ctx->r20) = ctx->r2;
    // 0x800B2DE8: addiu       $v0, $a0, 0x1
    ctx->r2 = ADD32(ctx->r4, 0X1);
    // 0x800B2DEC: sb          $v0, -0x37B0($v1)
    MEM_B(-0X37B0, ctx->r3) = ctx->r2;
    // 0x800B2DF0: sb          $a0, 0x18($s4)
    MEM_B(0X18, ctx->r20) = ctx->r4;
    // 0x800B2DF4: lhu         $v0, 0x0($a1)
    ctx->r2 = MEM_HU(ctx->r5, 0X0);
    // 0x800B2DF8: andi        $v0, $v0, 0xF
    ctx->r2 = ctx->r2 & 0XF;
    // 0x800B2DFC: bne         $v0, $zero, L_800B2E10
    if (ctx->r2 != 0) {
        // 0x800B2E00: addiu       $s0, $zero, 0x100
        ctx->r16 = ADD32(0, 0X100);
            goto L_800B2E10;
    }
    // 0x800B2E00: addiu       $s0, $zero, 0x100
    ctx->r16 = ADD32(0, 0X100);
    // 0x800B2E04: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800B2E08: sh          $v0, 0x4($s4)
    MEM_H(0X4, ctx->r20) = ctx->r2;
    // 0x800B2E0C: addiu       $s0, $zero, 0x10
    ctx->r16 = ADD32(0, 0X10);
L_800B2E10:
    // 0x800B2E10: lw          $v0, 0x10($s4)
    ctx->r2 = MEM_W(ctx->r20, 0X10);
    // 0x800B2E14: lhu         $v0, 0x0($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X0);
    // 0x800B2E18: addiu       $v1, $zero, 0x2
    ctx->r3 = ADD32(0, 0X2);
    // 0x800B2E1C: andi        $v0, $v0, 0xF
    ctx->r2 = ctx->r2 & 0XF;
    // 0x800B2E20: bne         $v0, $v1, L_800B2E2C
    if (ctx->r2 != ctx->r3) {
        // 0x800B2E24: addiu       $v0, $zero, 0x4
        ctx->r2 = ADD32(0, 0X4);
            goto L_800B2E2C;
    }
    // 0x800B2E24: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // 0x800B2E28: sh          $v0, 0x4($s4)
    MEM_H(0X4, ctx->r20) = ctx->r2;
L_800B2E2C:
    // 0x800B2E2C: lw          $v0, 0x10($s4)
    ctx->r2 = MEM_W(ctx->r20, 0X10);
    // 0x800B2E30: lhu         $v0, 0x0($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X0);
    // 0x800B2E34: addiu       $v1, $zero, 0x3
    ctx->r3 = ADD32(0, 0X3);
    // 0x800B2E38: andi        $v0, $v0, 0xF
    ctx->r2 = ctx->r2 & 0XF;
    // 0x800B2E3C: bne         $v0, $v1, L_800B2E48
    if (ctx->r2 != ctx->r3) {
        // 0x800B2E40: addiu       $v0, $zero, 0x8
        ctx->r2 = ADD32(0, 0X8);
            goto L_800B2E48;
    }
    // 0x800B2E40: addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
    // 0x800B2E44: sh          $v0, 0x4($s4)
    MEM_H(0X4, ctx->r20) = ctx->r2;
L_800B2E48:
    // 0x800B2E48: lw          $v0, 0x10($s4)
    ctx->r2 = MEM_W(ctx->r20, 0X10);
    // 0x800B2E4C: lhu         $a2, 0x4($v0)
    ctx->r6 = MEM_HU(ctx->r2, 0X4);
    // 0x800B2E50: lhu         $v0, 0x0($s4)
    ctx->r2 = MEM_HU(ctx->r20, 0X0);
    // 0x800B2E54: addu        $a2, $a2, $v0
    ctx->r6 = ADD32(ctx->r6, ctx->r2);
    // 0x800B2E58: addiu       $a2, $a2, -0x1
    ctx->r6 = ADD32(ctx->r6, -0X1);
    // 0x800B2E5C: div         $zero, $a2, $v0
    lo = S32(S64(S32(ctx->r6)) / S64(S32(ctx->r2))); hi = S32(S64(S32(ctx->r6)) % S64(S32(ctx->r2)));
    // 0x800B2E60: bne         $v0, $zero, L_800B2E6C
    if (ctx->r2 != 0) {
        // 0x800B2E64: nop
    
            goto L_800B2E6C;
    }
    // 0x800B2E64: nop

    // 0x800B2E68: break       7
    do_break(2148216424);
L_800B2E6C:
    // 0x800B2E6C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800B2E70: bne         $v0, $at, L_800B2E84
    if (ctx->r2 != ctx->r1) {
        // 0x800B2E74: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800B2E84;
    }
    // 0x800B2E74: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800B2E78: bne         $a2, $at, L_800B2E84
    if (ctx->r6 != ctx->r1) {
        // 0x800B2E7C: nop
    
            goto L_800B2E84;
    }
    // 0x800B2E7C: nop

    // 0x800B2E80: break       6
    do_break(2148216448);
L_800B2E84:
    // 0x800B2E84: mflo        $a2
    ctx->r6 = lo;
    // 0x800B2E88: lhu         $v1, 0x2($s4)
    ctx->r3 = MEM_HU(ctx->r20, 0X2);
    // 0x800B2E8C: lw          $v0, 0x10($s4)
    ctx->r2 = MEM_W(ctx->r20, 0X10);
    // 0x800B2E90: sw          $a2, 0x8($s4)
    MEM_W(0X8, ctx->r20) = ctx->r6;
    // 0x800B2E94: lhu         $v0, 0x6($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X6);
    // 0x800B2E98: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800B2E9C: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x800B2EA0: div         $zero, $v0, $v1
    lo = S32(S64(S32(ctx->r2)) / S64(S32(ctx->r3))); hi = S32(S64(S32(ctx->r2)) % S64(S32(ctx->r3)));
    // 0x800B2EA4: bne         $v1, $zero, L_800B2EB0
    if (ctx->r3 != 0) {
        // 0x800B2EA8: nop
    
            goto L_800B2EB0;
    }
    // 0x800B2EA8: nop

    // 0x800B2EAC: break       7
    do_break(2148216492);
L_800B2EB0:
    // 0x800B2EB0: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800B2EB4: bne         $v1, $at, L_800B2EC8
    if (ctx->r3 != ctx->r1) {
        // 0x800B2EB8: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800B2EC8;
    }
    // 0x800B2EB8: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800B2EBC: bne         $v0, $at, L_800B2EC8
    if (ctx->r2 != ctx->r1) {
        // 0x800B2EC0: nop
    
            goto L_800B2EC8;
    }
    // 0x800B2EC0: nop

    // 0x800B2EC4: break       6
    do_break(2148216516);
L_800B2EC8:
    // 0x800B2EC8: mflo        $v0
    ctx->r2 = lo;
    // 0x800B2ECC: nop

    // 0x800B2ED0: nop

    // 0x800B2ED4: mult        $a2, $v0
    result = S64(S32(ctx->r6)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800B2ED8: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x800B2EDC: mflo        $a2
    ctx->r6 = lo;
    // 0x800B2EE0: sll         $a0, $a2, 1
    ctx->r4 = S32(ctx->r6 << 1);
    // 0x800B2EE4: jal         0x80001ACC
    // 0x800B2EE8: sw          $a2, 0x8($s4)
    MEM_W(0X8, ctx->r20) = ctx->r6;
    rs_malloc(rdram, ctx);
        goto after_4;
    // 0x800B2EE8: sw          $a2, 0x8($s4)
    MEM_W(0X8, ctx->r20) = ctx->r6;
    after_4:
    // 0x800B2EEC: lw          $v1, 0x8($s4)
    ctx->r3 = MEM_W(ctx->r20, 0X8);
    // 0x800B2EF0: addu        $s2, $zero, $zero
    ctx->r18 = ADD32(0, 0);
    // 0x800B2EF4: beq         $v1, $zero, L_800B2F24
    if (ctx->r3 == 0) {
        // 0x800B2EF8: sw          $v0, 0x14($s4)
        MEM_W(0X14, ctx->r20) = ctx->r2;
            goto L_800B2F24;
    }
    // 0x800B2EF8: sw          $v0, 0x14($s4)
    MEM_W(0X14, ctx->r20) = ctx->r2;
    // 0x800B2EFC: ori         $a0, $zero, 0xFFFF
    ctx->r4 = 0 | 0XFFFF;
L_800B2F00:
    // 0x800B2F00: lw          $v0, 0x14($s4)
    ctx->r2 = MEM_W(ctx->r20, 0X14);
    // 0x800B2F04: sll         $v1, $s2, 1
    ctx->r3 = S32(ctx->r18 << 1);
    // 0x800B2F08: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x800B2F0C: sh          $a0, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r4;
    // 0x800B2F10: lw          $v0, 0x8($s4)
    ctx->r2 = MEM_W(ctx->r20, 0X8);
    // 0x800B2F14: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x800B2F18: sltu        $v0, $s2, $v0
    ctx->r2 = ctx->r18 < ctx->r2 ? 1 : 0;
    // 0x800B2F1C: bne         $v0, $zero, L_800B2F00
    if (ctx->r2 != 0) {
        // 0x800B2F20: nop
    
            goto L_800B2F00;
    }
    // 0x800B2F20: nop

L_800B2F24:
    // 0x800B2F24: addiu       $a0, $zero, 0x30
    ctx->r4 = ADD32(0, 0X30);
    // 0x800B2F28: jal         0x80001ACC
    // 0x800B2F2C: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    rs_malloc(rdram, ctx);
        goto after_5;
    // 0x800B2F2C: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    after_5:
    // 0x800B2F30: addu        $s3, $v0, $zero
    ctx->r19 = ADD32(ctx->r2, 0);
    // 0x800B2F34: addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    // 0x800B2F38: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x800B2F3C: addiu       $a2, $zero, 0x30
    ctx->r6 = ADD32(0, 0X30);
    // 0x800B2F40: jal         0x800078E0
    // 0x800B2F44: sw          $s3, 0xC($s4)
    MEM_W(0XC, ctx->r20) = ctx->r19;
    rs_memset(rdram, ctx);
        goto after_6;
    // 0x800B2F44: sw          $s3, 0xC($s4)
    MEM_W(0XC, ctx->r20) = ctx->r19;
    after_6:
    // 0x800B2F48: lw          $a0, 0x8($s4)
    ctx->r4 = MEM_W(ctx->r20, 0X8);
    // 0x800B2F4C: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x800B2F50: jal         0x80001ACC
    // 0x800B2F54: sll         $a0, $a0, 1
    ctx->r4 = S32(ctx->r4 << 1);
    rs_malloc(rdram, ctx);
        goto after_7;
    // 0x800B2F54: sll         $a0, $a0, 1
    ctx->r4 = S32(ctx->r4 << 1);
    after_7:
    // 0x800B2F58: lw          $v1, 0xC($s4)
    ctx->r3 = MEM_W(ctx->r20, 0XC);
    // 0x800B2F5C: addiu       $a0, $sp, 0x98
    ctx->r4 = ADD32(ctx->r29, 0X98);
    // 0x800B2F60: sw          $v0, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r2;
    // 0x800B2F64: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x800B2F68: addiu       $t3, $v0, 0x5C2C
    ctx->r11 = ADD32(ctx->r2, 0X5C2C);
    // 0x800B2F6C: lw          $t0, 0x0($t3)
    ctx->r8 = MEM_W(ctx->r11, 0X0);
    // 0x800B2F70: lh          $t1, 0x4($t3)
    ctx->r9 = MEM_H(ctx->r11, 0X4);
    // 0x800B2F74: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x800B2F78: sh          $t1, 0x14($sp)
    MEM_H(0X14, ctx->r29) = ctx->r9;
    // 0x800B2F7C: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x800B2F80: addiu       $t3, $v0, 0x5C34
    ctx->r11 = ADD32(ctx->r2, 0X5C34);
    // 0x800B2F84: lw          $t0, 0x0($t3)
    ctx->r8 = MEM_W(ctx->r11, 0X0);
    // 0x800B2F88: lh          $t1, 0x4($t3)
    ctx->r9 = MEM_H(ctx->r11, 0X4);
    // 0x800B2F8C: lb          $t2, 0x6($t3)
    ctx->r10 = MEM_B(ctx->r11, 0X6);
    // 0x800B2F90: sw          $t0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r8;
    // 0x800B2F94: sh          $t1, 0x1C($sp)
    MEM_H(0X1C, ctx->r29) = ctx->r9;
    // 0x800B2F98: sb          $t2, 0x1E($sp)
    MEM_B(0X1E, ctx->r29) = ctx->r10;
    // 0x800B2F9C: lbu         $v0, 0x18($s4)
    ctx->r2 = MEM_BU(ctx->r20, 0X18);
    // 0x800B2FA0: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x800B2FA4: addiu       $v0, $v0, 0x41
    ctx->r2 = ADD32(ctx->r2, 0X41);
    // 0x800B2FA8: sb          $v0, 0x11($sp)
    MEM_B(0X11, ctx->r29) = ctx->r2;
    // 0x800B2FAC: lbu         $v0, 0x18($s4)
    ctx->r2 = MEM_BU(ctx->r20, 0X18);
    // 0x800B2FB0: addiu       $a2, $zero, 0x24
    ctx->r6 = ADD32(0, 0X24);
    // 0x800B2FB4: addiu       $v0, $v0, 0x41
    ctx->r2 = ADD32(ctx->r2, 0X41);
    // 0x800B2FB8: jal         0x800078E0
    // 0x800B2FBC: sb          $v0, 0x19($sp)
    MEM_B(0X19, ctx->r29) = ctx->r2;
    rs_memset(rdram, ctx);
        goto after_8;
    // 0x800B2FBC: sb          $v0, 0x19($sp)
    MEM_B(0X19, ctx->r29) = ctx->r2;
    after_8:
    // 0x800B2FC0: addiu       $a0, $sp, 0x60
    ctx->r4 = ADD32(ctx->r29, 0X60);
    // 0x800B2FC4: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x800B2FC8: jal         0x800078E0
    // 0x800B2FCC: addiu       $a2, $zero, 0x34
    ctx->r6 = ADD32(0, 0X34);
    rs_memset(rdram, ctx);
        goto after_9;
    // 0x800B2FCC: addiu       $a2, $zero, 0x34
    ctx->r6 = ADD32(0, 0X34);
    after_9:
    // 0x800B2FD0: addiu       $a0, $sp, 0xAC
    ctx->r4 = ADD32(ctx->r29, 0XAC);
    // 0x800B2FD4: jal         0x8000761C
    // 0x800B2FD8: addiu       $a1, $sp, 0x10
    ctx->r5 = ADD32(ctx->r29, 0X10);
    rs_strcpy(rdram, ctx);
        goto after_10;
    // 0x800B2FD8: addiu       $a1, $sp, 0x10
    ctx->r5 = ADD32(ctx->r29, 0X10);
    after_10:
    // 0x800B2FDC: addiu       $v0, $sp, 0x18
    ctx->r2 = ADD32(ctx->r29, 0X18);
    // 0x800B2FE0: sw          $v0, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r2;
    // 0x800B2FE4: lhu         $v0, 0x0($s4)
    ctx->r2 = MEM_HU(ctx->r20, 0X0);
    // 0x800B2FE8: sh          $v0, 0x88($sp)
    MEM_H(0X88, ctx->r29) = ctx->r2;
    // 0x800B2FEC: lhu         $v1, 0x2($s4)
    ctx->r3 = MEM_HU(ctx->r20, 0X2);
    // 0x800B2FF0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800B2FF4: sb          $v0, 0x8C($sp)
    MEM_B(0X8C, ctx->r29) = ctx->r2;
    // 0x800B2FF8: sh          $v1, 0x8A($sp)
    MEM_H(0X8A, ctx->r29) = ctx->r3;
    // 0x800B2FFC: lw          $v0, 0x10($s4)
    ctx->r2 = MEM_W(ctx->r20, 0X10);
    // 0x800B3000: lhu         $v1, 0x0($v0)
    ctx->r3 = MEM_HU(ctx->r2, 0X0);
    // 0x800B3004: andi        $v0, $s5, 0xFF
    ctx->r2 = ctx->r21 & 0XFF;
    // 0x800B3008: bnel        $v0, $zero, L_800B3010
    if (ctx->r2 != 0) {
        // 0x800B300C: ori         $v1, $v1, 0x2000
        ctx->r3 = ctx->r3 | 0X2000;
            goto L_800B3010;
    }
    goto skip_0;
    // 0x800B300C: ori         $v1, $v1, 0x2000
    ctx->r3 = ctx->r3 | 0X2000;
    skip_0:
L_800B3010:
    // 0x800B3010: sh          $v1, 0x8E($sp)
    MEM_H(0X8E, ctx->r29) = ctx->r3;
    // 0x800B3014: lw          $v0, 0x10($s4)
    ctx->r2 = MEM_W(ctx->r20, 0X10);
    // 0x800B3018: addiu       $v0, $v0, 0xC
    ctx->r2 = ADD32(ctx->r2, 0XC);
    // 0x800B301C: sw          $v0, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r2;
    // 0x800B3020: lhu         $v1, 0x0($s4)
    ctx->r3 = MEM_HU(ctx->r20, 0X0);
    // 0x800B3024: lhu         $v0, 0x2($s4)
    ctx->r2 = MEM_HU(ctx->r20, 0X2);
    // 0x800B3028: mult        $v1, $v0
    result = S64(S32(ctx->r3)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800B302C: mflo        $v1
    ctx->r3 = lo;
    // 0x800B3030: lhu         $a0, 0x4($s4)
    ctx->r4 = MEM_HU(ctx->r20, 0X4);
    // 0x800B3034: nop

    // 0x800B3038: mult        $v1, $a0
    result = S64(S32(ctx->r3)) * S64(S32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800B303C: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x800B3040: mflo        $a0
    ctx->r4 = lo;
    // 0x800B3044: srl         $v0, $a0, 31
    ctx->r2 = S32(U32(ctx->r4) >> 31);
    // 0x800B3048: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // 0x800B304C: jal         0x80001ACC
    // 0x800B3050: sra         $a0, $a0, 1
    ctx->r4 = S32(SIGNED(ctx->r4) >> 1);
    rs_malloc(rdram, ctx);
        goto after_11;
    // 0x800B3050: sra         $a0, $a0, 1
    ctx->r4 = S32(SIGNED(ctx->r4) >> 1);
    after_11:
    // 0x800B3054: sw          $v0, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r2;
    // 0x800B3058: lw          $v1, 0x10($s4)
    ctx->r3 = MEM_W(ctx->r20, 0X10);
    // 0x800B305C: lhu         $v0, 0x0($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X0);
    // 0x800B3060: andi        $v0, $v0, 0x8000
    ctx->r2 = ctx->r2 & 0X8000;
    // 0x800B3064: beq         $v0, $zero, L_800B3074
    if (ctx->r2 == 0) {
        // 0x800B3068: addiu       $v1, $v1, 0xC
        ctx->r3 = ADD32(ctx->r3, 0XC);
            goto L_800B3074;
    }
    // 0x800B3068: addiu       $v1, $v1, 0xC
    ctx->r3 = ADD32(ctx->r3, 0XC);
    // 0x800B306C: j           L_800B307C
    // 0x800B3070: sll         $v0, $s0, 2
    ctx->r2 = S32(ctx->r16 << 2);
        goto L_800B307C;
    // 0x800B3070: sll         $v0, $s0, 2
    ctx->r2 = S32(ctx->r16 << 2);
L_800B3074:
    // 0x800B3074: sll         $v0, $s0, 1
    ctx->r2 = S32(ctx->r16 << 1);
    // 0x800B3078: addu        $v0, $v0, $s0
    ctx->r2 = ADD32(ctx->r2, ctx->r16);
L_800B307C:
    // 0x800B307C: addu        $s5, $v1, $v0
    ctx->r21 = ADD32(ctx->r3, ctx->r2);
    // 0x800B3080: lw          $v0, 0x10($s4)
    ctx->r2 = MEM_W(ctx->r20, 0X10);
    // 0x800B3084: lhu         $v0, 0x0($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X0);
    // 0x800B3088: andi        $v1, $v0, 0xF
    ctx->r3 = ctx->r2 & 0XF;
    // 0x800B308C: addiu       $v0, $v1, -0x4
    ctx->r2 = ADD32(ctx->r3, -0X4);
    // 0x800B3090: sltiu       $v0, $v0, 0x2
    ctx->r2 = ctx->r2 < 0X2 ? 1 : 0;
    // 0x800B3094: bne         $v0, $zero, L_800B30B0
    if (ctx->r2 != 0) {
        // 0x800B3098: andi        $v1, $v1, 0xFFFF
        ctx->r3 = ctx->r3 & 0XFFFF;
            goto L_800B30B0;
    }
    // 0x800B3098: andi        $v1, $v1, 0xFFFF
    ctx->r3 = ctx->r3 & 0XFFFF;
    // 0x800B309C: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x800B30A0: beq         $v1, $v0, L_800B30B0
    if (ctx->r3 == ctx->r2) {
        // 0x800B30A4: addiu       $v0, $zero, 0x3
        ctx->r2 = ADD32(0, 0X3);
            goto L_800B30B0;
    }
    // 0x800B30A4: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x800B30A8: bne         $v1, $v0, L_800B30B8
    if (ctx->r3 != ctx->r2) {
        // 0x800B30AC: nop
    
            goto L_800B30B8;
    }
    // 0x800B30AC: nop

L_800B30B0:
    // 0x800B30B0: lw          $v0, 0x10($s4)
    ctx->r2 = MEM_W(ctx->r20, 0X10);
    // 0x800B30B4: addiu       $s5, $v0, 0xC
    ctx->r21 = ADD32(ctx->r2, 0XC);
L_800B30B8:
    // 0x800B30B8: lw          $v0, 0x8($s4)
    ctx->r2 = MEM_W(ctx->r20, 0X8);
    // 0x800B30BC: beq         $v0, $zero, L_800B3240
    if (ctx->r2 == 0) {
        // 0x800B30C0: addu        $s2, $zero, $zero
        ctx->r18 = ADD32(0, 0);
            goto L_800B3240;
    }
    // 0x800B30C0: addu        $s2, $zero, $zero
    ctx->r18 = ADD32(0, 0);
    // 0x800B30C4: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x800B30C8: addiu       $s6, $v0, 0x5C40
    ctx->r22 = ADD32(ctx->r2, 0X5C40);
    // 0x800B30CC: addiu       $a0, $sp, 0xAE
    ctx->r4 = ADD32(ctx->r29, 0XAE);
L_800B30D0:
    // 0x800B30D0: addu        $a1, $s6, $zero
    ctx->r5 = ADD32(ctx->r22, 0);
    // 0x800B30D4: jal         0x80033CC4
    // 0x800B30D8: addu        $a2, $s2, $zero
    ctx->r6 = ADD32(ctx->r18, 0);
    sprintf_recomp(rdram, ctx);
        goto after_12;
    // 0x800B30D8: addu        $a2, $s2, $zero
    ctx->r6 = ADD32(ctx->r18, 0);
    after_12:
    // 0x800B30DC: addu        $a1, $s6, $zero
    ctx->r5 = ADD32(ctx->r22, 0);
    // 0x800B30E0: lw          $a0, 0x84($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X84);
    // 0x800B30E4: addu        $a2, $s2, $zero
    ctx->r6 = ADD32(ctx->r18, 0);
    // 0x800B30E8: jal         0x80033CC4
    // 0x800B30EC: addiu       $a0, $a0, 0x2
    ctx->r4 = ADD32(ctx->r4, 0X2);
    sprintf_recomp(rdram, ctx);
        goto after_13;
    // 0x800B30EC: addiu       $a0, $a0, 0x2
    ctx->r4 = ADD32(ctx->r4, 0X2);
    after_13:
    // 0x800B30F0: lw          $v0, 0x10($s4)
    ctx->r2 = MEM_W(ctx->r20, 0X10);
    // 0x800B30F4: lhu         $a1, 0x4($v0)
    ctx->r5 = MEM_HU(ctx->r2, 0X4);
    // 0x800B30F8: lhu         $v0, 0x0($s4)
    ctx->r2 = MEM_HU(ctx->r20, 0X0);
    // 0x800B30FC: divu        $zero, $a1, $v0
    lo = S32(U32(ctx->r5) / U32(ctx->r2)); hi = S32(U32(ctx->r5) % U32(ctx->r2));
    // 0x800B3100: bne         $v0, $zero, L_800B310C
    if (ctx->r2 != 0) {
        // 0x800B3104: nop
    
            goto L_800B310C;
    }
    // 0x800B3104: nop

    // 0x800B3108: break       7
    do_break(2148217096);
L_800B310C:
    // 0x800B310C: mflo        $a0
    ctx->r4 = lo;
    // 0x800B3110: nop

    // 0x800B3114: nop

    // 0x800B3118: divu        $zero, $s2, $a0
    lo = S32(U32(ctx->r18) / U32(ctx->r4)); hi = S32(U32(ctx->r18) % U32(ctx->r4));
    // 0x800B311C: bne         $a0, $zero, L_800B3128
    if (ctx->r4 != 0) {
        // 0x800B3120: nop
    
            goto L_800B3128;
    }
    // 0x800B3120: nop

    // 0x800B3124: break       7
    do_break(2148217124);
L_800B3128:
    // 0x800B3128: mflo        $a0
    ctx->r4 = lo;
    // 0x800B312C: mfhi        $v1
    ctx->r3 = hi;
    // 0x800B3130: nop

    // 0x800B3134: nop

    // 0x800B3138: mult        $v1, $v0
    result = S64(S32(ctx->r3)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800B313C: mflo        $s1
    ctx->r17 = lo;
    // 0x800B3140: lhu         $v1, 0x2($s4)
    ctx->r3 = MEM_HU(ctx->r20, 0X2);
    // 0x800B3144: nop

    // 0x800B3148: mult        $a0, $v1
    result = S64(S32(ctx->r4)) * S64(S32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800B314C: mflo        $t4
    ctx->r12 = lo;
    // 0x800B3150: nop

    // 0x800B3154: nop

    // 0x800B3158: mult        $t4, $a1
    result = S64(S32(ctx->r12)) * S64(S32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800B315C: mflo        $t4
    ctx->r12 = lo;
    // 0x800B3160: lhu         $v0, 0x4($s4)
    ctx->r2 = MEM_HU(ctx->r20, 0X4);
    // 0x800B3164: addu        $s1, $s1, $t4
    ctx->r17 = ADD32(ctx->r17, ctx->r12);
    // 0x800B3168: mult        $s1, $v0
    result = S64(S32(ctx->r17)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800B316C: addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
    // 0x800B3170: mflo        $s1
    ctx->r17 = lo;
    // 0x800B3174: beq         $v1, $zero, L_800B3200
    if (ctx->r3 == 0) {
        // 0x800B3178: srl         $s1, $s1, 1
        ctx->r17 = S32(U32(ctx->r17) >> 1);
            goto L_800B3200;
    }
    // 0x800B3178: srl         $s1, $s1, 1
    ctx->r17 = S32(U32(ctx->r17) >> 1);
L_800B317C:
    // 0x800B317C: lhu         $a2, 0x0($s4)
    ctx->r6 = MEM_HU(ctx->r20, 0X0);
    // 0x800B3180: mult        $s0, $a2
    result = S64(S32(ctx->r16)) * S64(S32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800B3184: mflo        $t4
    ctx->r12 = lo;
    // 0x800B3188: lhu         $v1, 0x4($s4)
    ctx->r3 = MEM_HU(ctx->r20, 0X4);
    // 0x800B318C: nop

    // 0x800B3190: mult        $t4, $v1
    result = S64(S32(ctx->r12)) * S64(S32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800B3194: mflo        $a0
    ctx->r4 = lo;
    // 0x800B3198: nop

    // 0x800B319C: nop

    // 0x800B31A0: mult        $a2, $v1
    result = S64(S32(ctx->r6)) * S64(S32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800B31A4: lw          $v0, 0x10($s4)
    ctx->r2 = MEM_W(ctx->r20, 0X10);
    // 0x800B31A8: mflo        $a2
    ctx->r6 = lo;
    // 0x800B31AC: lhu         $v0, 0x4($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X4);
    // 0x800B31B0: nop

    // 0x800B31B4: mult        $s0, $v0
    result = S64(S32(ctx->r16)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800B31B8: mflo        $t4
    ctx->r12 = lo;
    // 0x800B31BC: srl         $a0, $a0, 1
    ctx->r4 = S32(U32(ctx->r4) >> 1);
    // 0x800B31C0: srl         $v0, $a2, 31
    ctx->r2 = S32(U32(ctx->r6) >> 31);
    // 0x800B31C4: mult        $t4, $v1
    result = S64(S32(ctx->r12)) * S64(S32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800B31C8: addu        $a2, $a2, $v0
    ctx->r6 = ADD32(ctx->r6, ctx->r2);
    // 0x800B31CC: lw          $v0, 0x60($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X60);
    // 0x800B31D0: sra         $a2, $a2, 1
    ctx->r6 = S32(SIGNED(ctx->r6) >> 1);
    // 0x800B31D4: addu        $a0, $v0, $a0
    ctx->r4 = ADD32(ctx->r2, ctx->r4);
    // 0x800B31D8: mflo        $v1
    ctx->r3 = lo;
    // 0x800B31DC: srl         $a1, $v1, 1
    ctx->r5 = S32(U32(ctx->r3) >> 1);
    // 0x800B31E0: addu        $a1, $s1, $a1
    ctx->r5 = ADD32(ctx->r17, ctx->r5);
    // 0x800B31E4: jal         0x80018EF4
    // 0x800B31E8: addu        $a1, $s5, $a1
    ctx->r5 = ADD32(ctx->r21, ctx->r5);
    zmemcpy(rdram, ctx);
        goto after_14;
    // 0x800B31E8: addu        $a1, $s5, $a1
    ctx->r5 = ADD32(ctx->r21, ctx->r5);
    after_14:
    // 0x800B31EC: lhu         $v0, 0x2($s4)
    ctx->r2 = MEM_HU(ctx->r20, 0X2);
    // 0x800B31F0: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x800B31F4: sltu        $v0, $s0, $v0
    ctx->r2 = ctx->r16 < ctx->r2 ? 1 : 0;
    // 0x800B31F8: bne         $v0, $zero, L_800B317C
    if (ctx->r2 != 0) {
        // 0x800B31FC: nop
    
            goto L_800B317C;
    }
    // 0x800B31FC: nop

L_800B3200:
    // 0x800B3200: addiu       $a0, $sp, 0x98
    ctx->r4 = ADD32(ctx->r29, 0X98);
    // 0x800B3204: addiu       $a1, $sp, 0x60
    ctx->r5 = ADD32(ctx->r29, 0X60);
    // 0x800B3208: jal         0x80022B90
    // 0x800B320C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_80022B90(rdram, ctx);
        goto after_15;
    // 0x800B320C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_15:
    // 0x800B3210: sll         $a0, $s2, 1
    ctx->r4 = S32(ctx->r18 << 1);
    // 0x800B3214: lw          $v1, 0xC($s3)
    ctx->r3 = MEM_W(ctx->r19, 0XC);
    // 0x800B3218: lw          $a1, 0x14($s4)
    ctx->r5 = MEM_W(ctx->r20, 0X14);
    // 0x800B321C: addu        $v1, $a0, $v1
    ctx->r3 = ADD32(ctx->r4, ctx->r3);
    // 0x800B3220: addu        $a0, $a0, $a1
    ctx->r4 = ADD32(ctx->r4, ctx->r5);
    // 0x800B3224: sh          $v0, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r2;
    // 0x800B3228: sh          $v0, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r2;
    // 0x800B322C: lw          $v0, 0x8($s4)
    ctx->r2 = MEM_W(ctx->r20, 0X8);
    // 0x800B3230: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x800B3234: sltu        $v0, $s2, $v0
    ctx->r2 = ctx->r18 < ctx->r2 ? 1 : 0;
    // 0x800B3238: bne         $v0, $zero, L_800B30D0
    if (ctx->r2 != 0) {
        // 0x800B323C: addiu       $a0, $sp, 0xAE
        ctx->r4 = ADD32(ctx->r29, 0XAE);
            goto L_800B30D0;
    }
    // 0x800B323C: addiu       $a0, $sp, 0xAE
    ctx->r4 = ADD32(ctx->r29, 0XAE);
L_800B3240:
    // 0x800B3240: lw          $a0, 0x60($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X60);
    // 0x800B3244: jal         0x80001C98
    // 0x800B3248: nop

    rs_free(rdram, ctx);
        goto after_16;
    // 0x800B3248: nop

    after_16:
    // 0x800B324C: lw          $v0, 0x10($s4)
    ctx->r2 = MEM_W(ctx->r20, 0X10);
    // 0x800B3250: lhu         $v1, 0x0($s4)
    ctx->r3 = MEM_HU(ctx->r20, 0X0);
    // 0x800B3254: lhu         $v0, 0x4($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X4);
    // 0x800B3258: divu        $zero, $v0, $v1
    lo = S32(U32(ctx->r2) / U32(ctx->r3)); hi = S32(U32(ctx->r2) % U32(ctx->r3));
    // 0x800B325C: bne         $v1, $zero, L_800B3268
    if (ctx->r3 != 0) {
        // 0x800B3260: nop
    
            goto L_800B3268;
    }
    // 0x800B3260: nop

    // 0x800B3264: break       7
    do_break(2148217444);
L_800B3268:
    // 0x800B3268: mflo        $v0
    ctx->r2 = lo;
    // 0x800B326C: sh          $v0, 0x8($s3)
    MEM_H(0X8, ctx->r19) = ctx->r2;
    // 0x800B3270: lw          $v0, 0x10($s4)
    ctx->r2 = MEM_W(ctx->r20, 0X10);
    // 0x800B3274: lhu         $v1, 0x6($v0)
    ctx->r3 = MEM_HU(ctx->r2, 0X6);
    // 0x800B3278: lhu         $v0, 0x2($s4)
    ctx->r2 = MEM_HU(ctx->r20, 0X2);
    // 0x800B327C: divu        $zero, $v1, $v0
    lo = S32(U32(ctx->r3) / U32(ctx->r2)); hi = S32(U32(ctx->r3) % U32(ctx->r2));
    // 0x800B3280: bne         $v0, $zero, L_800B328C
    if (ctx->r2 != 0) {
        // 0x800B3284: nop
    
            goto L_800B328C;
    }
    // 0x800B3284: nop

    // 0x800B3288: break       7
    do_break(2148217480);
L_800B328C:
    // 0x800B328C: mflo        $v1
    ctx->r3 = lo;
    // 0x800B3290: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800B3294: lwc1        $f0, 0x5C4C($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X5C4C);
    // 0x800B3298: swc1        $f0, 0x24($s3)
    MEM_W(0X24, ctx->r19) = ctx->f0.u32l;
    // 0x800B329C: swc1        $f0, 0x28($s3)
    MEM_W(0X28, ctx->r19) = ctx->f0.u32l;
    // 0x800B32A0: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // 0x800B32A4: sb          $v0, 0x2C($s3)
    MEM_B(0X2C, ctx->r19) = ctx->r2;
    // 0x800B32A8: sb          $v0, 0x2D($s3)
    MEM_B(0X2D, ctx->r19) = ctx->r2;
    // 0x800B32AC: sb          $v0, 0x2E($s3)
    MEM_B(0X2E, ctx->r19) = ctx->r2;
    // 0x800B32B0: sb          $v0, 0x2F($s3)
    MEM_B(0X2F, ctx->r19) = ctx->r2;
    // 0x800B32B4: sh          $v1, 0xA($s3)
    MEM_H(0XA, ctx->r19) = ctx->r3;
    // 0x800B32B8: lw          $a0, 0x10($s4)
    ctx->r4 = MEM_W(ctx->r20, 0X10);
    // 0x800B32BC: jal         0x80001C98
    // 0x800B32C0: nop

    rs_free(rdram, ctx);
        goto after_17;
    // 0x800B32C0: nop

    after_17:
    // 0x800B32C4: addu        $v0, $s4, $zero
    ctx->r2 = ADD32(ctx->r20, 0);
    // 0x800B32C8: sw          $zero, 0x10($v0)
    MEM_W(0X10, ctx->r2) = 0;
    // 0x800B32CC: lw          $ra, 0xDC($sp)
    ctx->r31 = MEM_W(ctx->r29, 0XDC);
    // 0x800B32D0: lw          $s6, 0xD8($sp)
    ctx->r22 = MEM_W(ctx->r29, 0XD8);
    // 0x800B32D4: lw          $s5, 0xD4($sp)
    ctx->r21 = MEM_W(ctx->r29, 0XD4);
    // 0x800B32D8: lw          $s4, 0xD0($sp)
    ctx->r20 = MEM_W(ctx->r29, 0XD0);
    // 0x800B32DC: lw          $s3, 0xCC($sp)
    ctx->r19 = MEM_W(ctx->r29, 0XCC);
    // 0x800B32E0: lw          $s2, 0xC8($sp)
    ctx->r18 = MEM_W(ctx->r29, 0XC8);
    // 0x800B32E4: lw          $s1, 0xC4($sp)
    ctx->r17 = MEM_W(ctx->r29, 0XC4);
    // 0x800B32E8: lw          $s0, 0xC0($sp)
    ctx->r16 = MEM_W(ctx->r29, 0XC0);
    // 0x800B32EC: jr          $ra
    // 0x800B32F0: addiu       $sp, $sp, 0xE0
    ctx->r29 = ADD32(ctx->r29, 0XE0);
    return;
    // 0x800B32F0: addiu       $sp, $sp, 0xE0
    ctx->r29 = ADD32(ctx->r29, 0XE0);
;}
RECOMP_FUNC void func_800B32F4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B32F4: addiu       $sp, $sp, -0x90
    ctx->r29 = ADD32(ctx->r29, -0X90);
    // 0x800B32F8: sw          $s1, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r17;
    // 0x800B32FC: addu        $s1, $a0, $zero
    ctx->r17 = ADD32(ctx->r4, 0);
    // 0x800B3300: sw          $s2, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r18;
    // 0x800B3304: addu        $s2, $a1, $zero
    ctx->r18 = ADD32(ctx->r5, 0);
    // 0x800B3308: addiu       $v1, $sp, 0x10
    ctx->r3 = ADD32(ctx->r29, 0X10);
    // 0x800B330C: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x800B3310: addiu       $v0, $v0, 0x5C58
    ctx->r2 = ADD32(ctx->r2, 0X5C58);
    // 0x800B3314: addiu       $a0, $v0, 0x20
    ctx->r4 = ADD32(ctx->r2, 0X20);
    // 0x800B3318: sw          $ra, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r31;
    // 0x800B331C: sw          $s5, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r21;
    // 0x800B3320: sw          $s4, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r20;
    // 0x800B3324: sw          $s3, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r19;
    // 0x800B3328: sw          $s0, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r16;
L_800B332C:
    // 0x800B332C: lw          $a3, 0x0($v0)
    ctx->r7 = MEM_W(ctx->r2, 0X0);
    // 0x800B3330: lw          $t0, 0x4($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X4);
    // 0x800B3334: lw          $t1, 0x8($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X8);
    // 0x800B3338: lw          $t2, 0xC($v0)
    ctx->r10 = MEM_W(ctx->r2, 0XC);
    // 0x800B333C: sw          $a3, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r7;
    // 0x800B3340: sw          $t0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r8;
    // 0x800B3344: sw          $t1, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r9;
    // 0x800B3348: sw          $t2, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r10;
    // 0x800B334C: addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
    // 0x800B3350: bne         $v0, $a0, L_800B332C
    if (ctx->r2 != ctx->r4) {
        // 0x800B3354: addiu       $v1, $v1, 0x10
        ctx->r3 = ADD32(ctx->r3, 0X10);
            goto L_800B332C;
    }
    // 0x800B3354: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
    // 0x800B3358: lw          $a3, 0x0($v0)
    ctx->r7 = MEM_W(ctx->r2, 0X0);
    // 0x800B335C: sw          $a3, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r7;
    // 0x800B3360: addiu       $v1, $sp, 0x38
    ctx->r3 = ADD32(ctx->r29, 0X38);
    // 0x800B3364: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x800B3368: addiu       $v0, $v0, 0x5C7C
    ctx->r2 = ADD32(ctx->r2, 0X5C7C);
    // 0x800B336C: addiu       $a0, $v0, 0x30
    ctx->r4 = ADD32(ctx->r2, 0X30);
L_800B3370:
    // 0x800B3370: lw          $a3, 0x0($v0)
    ctx->r7 = MEM_W(ctx->r2, 0X0);
    // 0x800B3374: lw          $t0, 0x4($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X4);
    // 0x800B3378: lw          $t1, 0x8($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X8);
    // 0x800B337C: lw          $t2, 0xC($v0)
    ctx->r10 = MEM_W(ctx->r2, 0XC);
    // 0x800B3380: sw          $a3, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r7;
    // 0x800B3384: sw          $t0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r8;
    // 0x800B3388: sw          $t1, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r9;
    // 0x800B338C: sw          $t2, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r10;
    // 0x800B3390: addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
    // 0x800B3394: bne         $v0, $a0, L_800B3370
    if (ctx->r2 != ctx->r4) {
        // 0x800B3398: addiu       $v1, $v1, 0x10
        ctx->r3 = ADD32(ctx->r3, 0X10);
            goto L_800B3370;
    }
    // 0x800B3398: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
    // 0x800B339C: addiu       $a0, $zero, 0x38
    ctx->r4 = ADD32(0, 0X38);
    // 0x800B33A0: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x800B33A4: lw          $a3, 0x0($v0)
    ctx->r7 = MEM_W(ctx->r2, 0X0);
    // 0x800B33A8: jal         0x80001ACC
    // 0x800B33AC: sw          $a3, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r7;
    rs_malloc(rdram, ctx);
        goto after_0;
    // 0x800B33AC: sw          $a3, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r7;
    after_0:
    // 0x800B33B0: addu        $s4, $v0, $zero
    ctx->r20 = ADD32(ctx->r2, 0);
    // 0x800B33B4: addu        $a0, $s4, $zero
    ctx->r4 = ADD32(ctx->r20, 0);
    // 0x800B33B8: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x800B33BC: jal         0x800078E0
    // 0x800B33C0: addiu       $a2, $zero, 0x38
    ctx->r6 = ADD32(0, 0X38);
    rs_memset(rdram, ctx);
        goto after_1;
    // 0x800B33C0: addiu       $a2, $zero, 0x38
    ctx->r6 = ADD32(0, 0X38);
    after_1:
    // 0x800B33C4: addiu       $v0, $zero, 0x40
    ctx->r2 = ADD32(0, 0X40);
    // 0x800B33C8: sll         $s1, $s1, 16
    ctx->r17 = S32(ctx->r17 << 16);
    // 0x800B33CC: sh          $v0, 0x0($s4)
    MEM_H(0X0, ctx->r20) = ctx->r2;
    // 0x800B33D0: andi        $v1, $v0, 0xFFFF
    ctx->r3 = ctx->r2 & 0XFFFF;
    // 0x800B33D4: sra         $s1, $s1, 16
    ctx->r17 = S32(SIGNED(ctx->r17) >> 16);
    // 0x800B33D8: div         $zero, $s1, $v1
    lo = S32(S64(S32(ctx->r17)) / S64(S32(ctx->r3))); hi = S32(S64(S32(ctx->r17)) % S64(S32(ctx->r3)));
    // 0x800B33DC: bne         $v1, $zero, L_800B33E8
    if (ctx->r3 != 0) {
        // 0x800B33E0: nop
    
            goto L_800B33E8;
    }
    // 0x800B33E0: nop

    // 0x800B33E4: break       7
    do_break(2148217828);
L_800B33E8:
    // 0x800B33E8: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800B33EC: bne         $v1, $at, L_800B3400
    if (ctx->r3 != ctx->r1) {
        // 0x800B33F0: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800B3400;
    }
    // 0x800B33F0: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800B33F4: bne         $s1, $at, L_800B3400
    if (ctx->r17 != ctx->r1) {
        // 0x800B33F8: nop
    
            goto L_800B3400;
    }
    // 0x800B33F8: nop

    // 0x800B33FC: break       6
    do_break(2148217852);
L_800B3400:
    // 0x800B3400: mflo        $v1
    ctx->r3 = lo;
    // 0x800B3404: addiu       $v0, $zero, 0x10
    ctx->r2 = ADD32(0, 0X10);
    // 0x800B3408: sll         $s2, $s2, 16
    ctx->r18 = S32(ctx->r18 << 16);
    // 0x800B340C: sh          $v0, 0x2($s4)
    MEM_H(0X2, ctx->r20) = ctx->r2;
    // 0x800B3410: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x800B3414: sra         $s2, $s2, 16
    ctx->r18 = S32(SIGNED(ctx->r18) >> 16);
    // 0x800B3418: div         $zero, $s2, $v0
    lo = S32(S64(S32(ctx->r18)) / S64(S32(ctx->r2))); hi = S32(S64(S32(ctx->r18)) % S64(S32(ctx->r2)));
    // 0x800B341C: bne         $v0, $zero, L_800B3428
    if (ctx->r2 != 0) {
        // 0x800B3420: nop
    
            goto L_800B3428;
    }
    // 0x800B3420: nop

    // 0x800B3424: break       7
    do_break(2148217892);
L_800B3428:
    // 0x800B3428: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800B342C: bne         $v0, $at, L_800B3440
    if (ctx->r2 != ctx->r1) {
        // 0x800B3430: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800B3440;
    }
    // 0x800B3430: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800B3434: bne         $s2, $at, L_800B3440
    if (ctx->r18 != ctx->r1) {
        // 0x800B3438: nop
    
            goto L_800B3440;
    }
    // 0x800B3438: nop

    // 0x800B343C: break       6
    do_break(2148217916);
L_800B3440:
    // 0x800B3440: mflo        $v0
    ctx->r2 = lo;
    // 0x800B3444: nop

    // 0x800B3448: nop

    // 0x800B344C: mult        $v1, $v0
    result = S64(S32(ctx->r3)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800B3450: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x800B3454: addiu       $s3, $zero, 0x1
    ctx->r19 = ADD32(0, 0X1);
    // 0x800B3458: sh          $s3, 0x4($s4)
    MEM_H(0X4, ctx->r20) = ctx->r19;
    // 0x800B345C: sw          $v1, 0x8($s4)
    MEM_W(0X8, ctx->r20) = ctx->r3;
    // 0x800B3460: mflo        $v0
    ctx->r2 = lo;
    // 0x800B3464: sll         $a0, $v0, 1
    ctx->r4 = S32(ctx->r2 << 1);
    // 0x800B3468: jal         0x80001ACC
    // 0x800B346C: sw          $v0, 0x8($s4)
    MEM_W(0X8, ctx->r20) = ctx->r2;
    rs_malloc(rdram, ctx);
        goto after_2;
    // 0x800B346C: sw          $v0, 0x8($s4)
    MEM_W(0X8, ctx->r20) = ctx->r2;
    after_2:
    // 0x800B3470: addiu       $a0, $zero, 0x30
    ctx->r4 = ADD32(0, 0X30);
    // 0x800B3474: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x800B3478: jal         0x80001ACC
    // 0x800B347C: sw          $v0, 0x14($s4)
    MEM_W(0X14, ctx->r20) = ctx->r2;
    rs_malloc(rdram, ctx);
        goto after_3;
    // 0x800B347C: sw          $v0, 0x14($s4)
    MEM_W(0X14, ctx->r20) = ctx->r2;
    after_3:
    // 0x800B3480: addu        $s5, $v0, $zero
    ctx->r21 = ADD32(ctx->r2, 0);
    // 0x800B3484: addu        $a0, $s5, $zero
    ctx->r4 = ADD32(ctx->r21, 0);
    // 0x800B3488: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x800B348C: addiu       $a2, $zero, 0x30
    ctx->r6 = ADD32(0, 0X30);
    // 0x800B3490: jal         0x800078E0
    // 0x800B3494: sw          $s5, 0xC($s4)
    MEM_W(0XC, ctx->r20) = ctx->r21;
    rs_memset(rdram, ctx);
        goto after_4;
    // 0x800B3494: sw          $s5, 0xC($s4)
    MEM_W(0XC, ctx->r20) = ctx->r21;
    after_4:
    // 0x800B3498: lw          $a0, 0x8($s4)
    ctx->r4 = MEM_W(ctx->r20, 0X8);
    // 0x800B349C: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x800B34A0: jal         0x80001ACC
    // 0x800B34A4: sll         $a0, $a0, 1
    ctx->r4 = S32(ctx->r4 << 1);
    rs_malloc(rdram, ctx);
        goto after_5;
    // 0x800B34A4: sll         $a0, $a0, 1
    ctx->r4 = S32(ctx->r4 << 1);
    after_5:
    // 0x800B34A8: sw          $v0, 0xC($s5)
    MEM_W(0XC, ctx->r21) = ctx->r2;
    // 0x800B34AC: lhu         $v1, 0x0($s4)
    ctx->r3 = MEM_HU(ctx->r20, 0X0);
    // 0x800B34B0: lhu         $v0, 0x2($s4)
    ctx->r2 = MEM_HU(ctx->r20, 0X2);
    // 0x800B34B4: mult        $v1, $v0
    result = S64(S32(ctx->r3)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800B34B8: lhu         $s0, 0x4($s4)
    ctx->r16 = MEM_HU(ctx->r20, 0X4);
    // 0x800B34BC: mflo        $t3
    ctx->r11 = lo;
    // 0x800B34C0: sh          $v1, 0x60($sp)
    MEM_H(0X60, ctx->r29) = ctx->r3;
    // 0x800B34C4: lhu         $v0, 0x2($s4)
    ctx->r2 = MEM_HU(ctx->r20, 0X2);
    // 0x800B34C8: mult        $t3, $s0
    result = S64(S32(ctx->r11)) * S64(S32(ctx->r16)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800B34CC: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x800B34D0: sb          $s3, 0x64($sp)
    MEM_B(0X64, ctx->r29) = ctx->r19;
    // 0x800B34D4: sb          $zero, 0x65($sp)
    MEM_B(0X65, ctx->r29) = 0;
    // 0x800B34D8: sh          $v0, 0x62($sp)
    MEM_H(0X62, ctx->r29) = ctx->r2;
    // 0x800B34DC: mflo        $s0
    ctx->r16 = lo;
    // 0x800B34E0: srl         $v0, $s0, 31
    ctx->r2 = S32(U32(ctx->r16) >> 31);
    // 0x800B34E4: addu        $s0, $s0, $v0
    ctx->r16 = ADD32(ctx->r16, ctx->r2);
    // 0x800B34E8: sra         $s0, $s0, 1
    ctx->r16 = S32(SIGNED(ctx->r16) >> 1);
    // 0x800B34EC: jal         0x80001ACC
    // 0x800B34F0: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    rs_malloc(rdram, ctx);
        goto after_6;
    // 0x800B34F0: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_6:
    // 0x800B34F4: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // 0x800B34F8: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x800B34FC: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    // 0x800B3500: jal         0x800078E0
    // 0x800B3504: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    rs_memset(rdram, ctx);
        goto after_7;
    // 0x800B3504: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    after_7:
    // 0x800B3508: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    // 0x800B350C: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    // 0x800B3510: lui         $a2, 0x800D
    ctx->r6 = S32(0X800D << 16);
    // 0x800B3514: lbu         $v0, -0x37B0($a2)
    ctx->r2 = MEM_BU(ctx->r6, -0X37B0);
    // 0x800B3518: lw          $v1, 0x5C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X5C);
    // 0x800B351C: addiu       $v0, $v0, 0x41
    ctx->r2 = ADD32(ctx->r2, 0X41);
    // 0x800B3520: sb          $v0, 0x1($v1)
    MEM_B(0X1, ctx->r3) = ctx->r2;
    // 0x800B3524: lbu         $v0, -0x37B0($a2)
    ctx->r2 = MEM_BU(ctx->r6, -0X37B0);
    // 0x800B3528: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x800B352C: addiu       $v0, $v0, 0x41
    ctx->r2 = ADD32(ctx->r2, 0X41);
    // 0x800B3530: jal         0x80022B90
    // 0x800B3534: sb          $v0, 0x25($sp)
    MEM_B(0X25, ctx->r29) = ctx->r2;
    func_80022B90(rdram, ctx);
        goto after_8;
    // 0x800B3534: sb          $v0, 0x25($sp)
    MEM_B(0X25, ctx->r29) = ctx->r2;
    after_8:
    // 0x800B3538: lw          $v1, 0x14($s4)
    ctx->r3 = MEM_W(ctx->r20, 0X14);
    // 0x800B353C: lw          $a0, 0xC($s5)
    ctx->r4 = MEM_W(ctx->r21, 0XC);
    // 0x800B3540: sh          $v0, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r2;
    // 0x800B3544: sh          $v0, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r2;
    // 0x800B3548: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x800B354C: jal         0x80001C98
    // 0x800B3550: nop

    rs_free(rdram, ctx);
        goto after_9;
    // 0x800B3550: nop

    after_9:
    // 0x800B3554: lhu         $v0, 0x0($s4)
    ctx->r2 = MEM_HU(ctx->r20, 0X0);
    // 0x800B3558: div         $zero, $s1, $v0
    lo = S32(S64(S32(ctx->r17)) / S64(S32(ctx->r2))); hi = S32(S64(S32(ctx->r17)) % S64(S32(ctx->r2)));
    // 0x800B355C: bne         $v0, $zero, L_800B3568
    if (ctx->r2 != 0) {
        // 0x800B3560: nop
    
            goto L_800B3568;
    }
    // 0x800B3560: nop

    // 0x800B3564: break       7
    do_break(2148218212);
L_800B3568:
    // 0x800B3568: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800B356C: bne         $v0, $at, L_800B3580
    if (ctx->r2 != ctx->r1) {
        // 0x800B3570: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800B3580;
    }
    // 0x800B3570: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800B3574: bne         $s1, $at, L_800B3580
    if (ctx->r17 != ctx->r1) {
        // 0x800B3578: nop
    
            goto L_800B3580;
    }
    // 0x800B3578: nop

    // 0x800B357C: break       6
    do_break(2148218236);
L_800B3580:
    // 0x800B3580: mflo        $s1
    ctx->r17 = lo;
    // 0x800B3584: sh          $s1, 0x8($s5)
    MEM_H(0X8, ctx->r21) = ctx->r17;
    // 0x800B3588: lhu         $v0, 0x2($s4)
    ctx->r2 = MEM_HU(ctx->r20, 0X2);
    // 0x800B358C: div         $zero, $s2, $v0
    lo = S32(S64(S32(ctx->r18)) / S64(S32(ctx->r2))); hi = S32(S64(S32(ctx->r18)) % S64(S32(ctx->r2)));
    // 0x800B3590: bne         $v0, $zero, L_800B359C
    if (ctx->r2 != 0) {
        // 0x800B3594: nop
    
            goto L_800B359C;
    }
    // 0x800B3594: nop

    // 0x800B3598: break       7
    do_break(2148218264);
L_800B359C:
    // 0x800B359C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800B35A0: bne         $v0, $at, L_800B35B4
    if (ctx->r2 != ctx->r1) {
        // 0x800B35A4: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800B35B4;
    }
    // 0x800B35A4: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800B35A8: bne         $s2, $at, L_800B35B4
    if (ctx->r18 != ctx->r1) {
        // 0x800B35AC: nop
    
            goto L_800B35B4;
    }
    // 0x800B35AC: nop

    // 0x800B35B0: break       6
    do_break(2148218288);
L_800B35B4:
    // 0x800B35B4: mflo        $s2
    ctx->r18 = lo;
    // 0x800B35B8: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800B35BC: lwc1        $f0, 0x5CB0($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X5CB0);
    // 0x800B35C0: swc1        $f0, 0x28($s5)
    MEM_W(0X28, ctx->r21) = ctx->f0.u32l;
    // 0x800B35C4: swc1        $f0, 0x24($s5)
    MEM_W(0X24, ctx->r21) = ctx->f0.u32l;
    // 0x800B35C8: sh          $s2, 0xA($s5)
    MEM_H(0XA, ctx->r21) = ctx->r18;
    // 0x800B35CC: lw          $v0, 0x8($s4)
    ctx->r2 = MEM_W(ctx->r20, 0X8);
    // 0x800B35D0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x800B35D4: sltu        $v0, $a1, $v0
    ctx->r2 = ctx->r5 < ctx->r2 ? 1 : 0;
    // 0x800B35D8: beq         $v0, $zero, L_800B3618
    if (ctx->r2 == 0) {
        // 0x800B35DC: lui         $v1, 0x800D
        ctx->r3 = S32(0X800D << 16);
            goto L_800B3618;
    }
    // 0x800B35DC: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x800B35E0: ori         $a2, $zero, 0xFFFF
    ctx->r6 = 0 | 0XFFFF;
L_800B35E4:
    // 0x800B35E4: lw          $v0, 0xC($s5)
    ctx->r2 = MEM_W(ctx->r21, 0XC);
    // 0x800B35E8: sll         $v1, $a1, 1
    ctx->r3 = S32(ctx->r5 << 1);
    // 0x800B35EC: lhu         $a0, 0x0($v0)
    ctx->r4 = MEM_HU(ctx->r2, 0X0);
    // 0x800B35F0: addu        $v0, $v1, $v0
    ctx->r2 = ADD32(ctx->r3, ctx->r2);
    // 0x800B35F4: sh          $a0, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r4;
    // 0x800B35F8: lw          $v0, 0x14($s4)
    ctx->r2 = MEM_W(ctx->r20, 0X14);
    // 0x800B35FC: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x800B3600: sh          $a2, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r6;
    // 0x800B3604: lw          $v0, 0x8($s4)
    ctx->r2 = MEM_W(ctx->r20, 0X8);
    // 0x800B3608: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x800B360C: sltu        $v0, $a1, $v0
    ctx->r2 = ctx->r5 < ctx->r2 ? 1 : 0;
    // 0x800B3610: bne         $v0, $zero, L_800B35E4
    if (ctx->r2 != 0) {
        // 0x800B3614: lui         $v1, 0x800D
        ctx->r3 = S32(0X800D << 16);
            goto L_800B35E4;
    }
    // 0x800B3614: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
L_800B3618:
    // 0x800B3618: lbu         $a1, -0x37B0($v1)
    ctx->r5 = MEM_BU(ctx->r3, -0X37B0);
    // 0x800B361C: addu        $v0, $s4, $zero
    ctx->r2 = ADD32(ctx->r20, 0);
    // 0x800B3620: addiu       $a0, $a1, 0x1
    ctx->r4 = ADD32(ctx->r5, 0X1);
    // 0x800B3624: sb          $a0, -0x37B0($v1)
    MEM_B(-0X37B0, ctx->r3) = ctx->r4;
    // 0x800B3628: sb          $a1, 0x18($v0)
    MEM_B(0X18, ctx->r2) = ctx->r5;
    // 0x800B362C: lw          $ra, 0x88($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X88);
    // 0x800B3630: lw          $s5, 0x84($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X84);
    // 0x800B3634: lw          $s4, 0x80($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X80);
    // 0x800B3638: lw          $s3, 0x7C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X7C);
    // 0x800B363C: lw          $s2, 0x78($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X78);
    // 0x800B3640: lw          $s1, 0x74($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X74);
    // 0x800B3644: lw          $s0, 0x70($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X70);
    // 0x800B3648: jr          $ra
    // 0x800B364C: addiu       $sp, $sp, 0x90
    ctx->r29 = ADD32(ctx->r29, 0X90);
    return;
    // 0x800B364C: addiu       $sp, $sp, 0x90
    ctx->r29 = ADD32(ctx->r29, 0X90);
;}
RECOMP_FUNC void func_800B3650(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B3650: addiu       $sp, $sp, -0xC0
    ctx->r29 = ADD32(ctx->r29, -0XC0);
    // 0x800B3654: sw          $s5, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->r21;
    // 0x800B3658: addu        $s5, $a0, $zero
    ctx->r21 = ADD32(ctx->r4, 0);
    // 0x800B365C: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x800B3660: sw          $s6, 0xB8($sp)
    MEM_W(0XB8, ctx->r29) = ctx->r22;
    // 0x800B3664: addiu       $s6, $v0, 0x5C40
    ctx->r22 = ADD32(ctx->r2, 0X5C40);
    // 0x800B3668: sw          $ra, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->r31;
    // 0x800B366C: sw          $s4, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->r20;
    // 0x800B3670: sw          $s3, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->r19;
    // 0x800B3674: sw          $s2, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->r18;
    // 0x800B3678: sw          $s1, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->r17;
    // 0x800B367C: sw          $s0, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->r16;
L_800B3680:
    // 0x800B3680: lw          $a0, 0x0($s5)
    ctx->r4 = MEM_W(ctx->r21, 0X0);
    // 0x800B3684: jal         0x80006F24
    // 0x800B3688: addu        $s4, $zero, $zero
    ctx->r20 = ADD32(0, 0);
    func_80006F24(rdram, ctx);
        goto after_0;
    // 0x800B3688: addu        $s4, $zero, $zero
    ctx->r20 = ADD32(0, 0);
    after_0:
    // 0x800B368C: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    // 0x800B3690: addu        $s3, $v0, $zero
    ctx->r19 = ADD32(ctx->r2, 0);
    // 0x800B3694: lw          $a0, 0x14($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X14);
    // 0x800B3698: lw          $a3, 0x0($s5)
    ctx->r7 = MEM_W(ctx->r21, 0X0);
    // 0x800B369C: jal         0x800B2630
    // 0x800B36A0: addiu       $a2, $s3, 0x18
    ctx->r6 = ADD32(ctx->r19, 0X18);
    func_800B2630(rdram, ctx);
        goto after_1;
    // 0x800B36A0: addiu       $a2, $s3, 0x18
    ctx->r6 = ADD32(ctx->r19, 0X18);
    after_1:
    // 0x800B36A4: lw          $v1, 0x14($s3)
    ctx->r3 = MEM_W(ctx->r19, 0X14);
    // 0x800B36A8: lw          $v0, 0x8($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X8);
    // 0x800B36AC: beq         $v0, $zero, L_800B37B4
    if (ctx->r2 == 0) {
        // 0x800B36B0: nop
    
            goto L_800B37B4;
    }
    // 0x800B36B0: nop

    // 0x800B36B4: addu        $s1, $v1, $zero
    ctx->r17 = ADD32(ctx->r3, 0);
L_800B36B8:
    // 0x800B36B8: addu        $s2, $zero, $zero
    ctx->r18 = ADD32(0, 0);
L_800B36BC:
    // 0x800B36BC: addiu       $a0, $sp, 0x52
    ctx->r4 = ADD32(ctx->r29, 0X52);
    // 0x800B36C0: lw          $a2, 0x38($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X38);
    // 0x800B36C4: jal         0x80033CC4
    // 0x800B36C8: addu        $a1, $s6, $zero
    ctx->r5 = ADD32(ctx->r22, 0);
    sprintf_recomp(rdram, ctx);
        goto after_2;
    // 0x800B36C8: addu        $a1, $s6, $zero
    ctx->r5 = ADD32(ctx->r22, 0);
    after_2:
    // 0x800B36CC: addu        $a1, $s6, $zero
    ctx->r5 = ADD32(ctx->r22, 0);
    // 0x800B36D0: lw          $a0, 0x84($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X84);
    // 0x800B36D4: lw          $a2, 0x38($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X38);
    // 0x800B36D8: jal         0x80033CC4
    // 0x800B36DC: addiu       $a0, $a0, 0x2
    ctx->r4 = ADD32(ctx->r4, 0X2);
    sprintf_recomp(rdram, ctx);
        goto after_3;
    // 0x800B36DC: addiu       $a0, $a0, 0x2
    ctx->r4 = ADD32(ctx->r4, 0X2);
    after_3:
    // 0x800B36E0: lw          $a0, 0x94($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X94);
    // 0x800B36E4: lw          $a1, 0x60($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X60);
    // 0x800B36E8: jal         0x800C8C1C
    // 0x800B36EC: nop

    func_800C8C1C(rdram, ctx);
        goto after_4;
    // 0x800B36EC: nop

    after_4:
    // 0x800B36F0: lw          $v0, 0x1C($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X1C);
    // 0x800B36F4: andi        $v0, $v0, 0x6
    ctx->r2 = ctx->r2 & 0X6;
    // 0x800B36F8: beq         $v0, $zero, L_800B3710
    if (ctx->r2 == 0) {
        // 0x800B36FC: nop
    
            goto L_800B3710;
    }
    // 0x800B36FC: nop

    // 0x800B3700: lw          $a0, 0x98($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X98);
    // 0x800B3704: lw          $a1, 0x64($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X64);
    // 0x800B3708: jal         0x800C8C1C
    // 0x800B370C: nop

    func_800C8C1C(rdram, ctx);
        goto after_5;
    // 0x800B370C: nop

    after_5:
L_800B3710:
    // 0x800B3710: lw          $v0, 0x38($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X38);
    // 0x800B3714: lw          $v1, 0x14($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X14);
    // 0x800B3718: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x800B371C: addu        $s0, $v0, $v1
    ctx->r16 = ADD32(ctx->r2, ctx->r3);
    // 0x800B3720: lhu         $v1, 0x0($s0)
    ctx->r3 = MEM_HU(ctx->r16, 0X0);
    // 0x800B3724: ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
    // 0x800B3728: bne         $v1, $v0, L_800B3748
    if (ctx->r3 != ctx->r2) {
        // 0x800B372C: addiu       $a1, $sp, 0x3C
        ctx->r5 = ADD32(ctx->r29, 0X3C);
            goto L_800B3748;
    }
    // 0x800B372C: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    // 0x800B3730: addiu       $a0, $sp, 0x3C
    ctx->r4 = ADD32(ctx->r29, 0X3C);
    // 0x800B3734: addiu       $a1, $sp, 0x60
    ctx->r5 = ADD32(ctx->r29, 0X60);
    // 0x800B3738: jal         0x80022B90
    // 0x800B373C: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    func_80022B90(rdram, ctx);
        goto after_6;
    // 0x800B373C: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    after_6:
    // 0x800B3740: j           L_800B375C
    // 0x800B3744: sh          $v0, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r2;
        goto L_800B375C;
    // 0x800B3744: sh          $v0, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r2;
L_800B3748:
    // 0x800B3748: lhu         $a0, 0x0($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X0);
    // 0x800B374C: addiu       $a2, $sp, 0x60
    ctx->r6 = ADD32(ctx->r29, 0X60);
    // 0x800B3750: jal         0x80022C00
    // 0x800B3754: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    func_80022C00(rdram, ctx);
        goto after_7;
    // 0x800B3754: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    after_7:
    // 0x800B3758: sh          $v0, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r2;
L_800B375C:
    // 0x800B375C: lw          $v1, 0x38($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X38);
    // 0x800B3760: lw          $v0, 0x14($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X14);
    // 0x800B3764: lw          $a0, 0xC($s1)
    ctx->r4 = MEM_W(ctx->r17, 0XC);
    // 0x800B3768: sll         $v1, $v1, 1
    ctx->r3 = S32(ctx->r3 << 1);
    // 0x800B376C: addu        $v0, $v1, $v0
    ctx->r2 = ADD32(ctx->r3, ctx->r2);
    // 0x800B3770: lw          $a0, 0xC($a0)
    ctx->r4 = MEM_W(ctx->r4, 0XC);
    // 0x800B3774: lhu         $v0, 0x0($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X0);
    // 0x800B3778: addu        $v1, $v1, $a0
    ctx->r3 = ADD32(ctx->r3, ctx->r4);
    // 0x800B377C: sh          $v0, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r2;
    // 0x800B3780: lw          $v0, 0x38($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X38);
    // 0x800B3784: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x800B3788: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800B378C: beq         $s2, $zero, L_800B36BC
    if (ctx->r18 == 0) {
        // 0x800B3790: sw          $v0, 0x38($sp)
        MEM_W(0X38, ctx->r29) = ctx->r2;
            goto L_800B36BC;
    }
    // 0x800B3790: sw          $v0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r2;
    // 0x800B3794: lw          $a0, 0x0($s5)
    ctx->r4 = MEM_W(ctx->r21, 0X0);
    // 0x800B3798: jal         0x800072AC
    // 0x800B379C: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    func_800072AC(rdram, ctx);
        goto after_8;
    // 0x800B379C: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    after_8:
    // 0x800B37A0: lw          $v1, 0x14($s3)
    ctx->r3 = MEM_W(ctx->r19, 0X14);
    // 0x800B37A4: lw          $v0, 0x8($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X8);
    // 0x800B37A8: sltu        $v0, $s4, $v0
    ctx->r2 = ctx->r20 < ctx->r2 ? 1 : 0;
    // 0x800B37AC: bnel        $v0, $zero, L_800B36B8
    if (ctx->r2 != 0) {
        // 0x800B37B0: addu        $s1, $v1, $zero
        ctx->r17 = ADD32(ctx->r3, 0);
            goto L_800B36B8;
    }
    goto skip_0;
    // 0x800B37B0: addu        $s1, $v1, $zero
    ctx->r17 = ADD32(ctx->r3, 0);
    skip_0:
L_800B37B4:
    // 0x800B37B4: lw          $v0, 0x14($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X14);
    // 0x800B37B8: lw          $v0, 0x1C($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X1C);
    // 0x800B37BC: andi        $v0, $v0, 0x6
    ctx->r2 = ctx->r2 & 0X6;
    // 0x800B37C0: beq         $v0, $zero, L_800B37E0
    if (ctx->r2 == 0) {
        // 0x800B37C4: nop
    
            goto L_800B37E0;
    }
    // 0x800B37C4: nop

    // 0x800B37C8: lw          $a0, 0x64($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X64);
    // 0x800B37CC: jal         0x80001C98
    // 0x800B37D0: nop

    rs_free(rdram, ctx);
        goto after_9;
    // 0x800B37D0: nop

    after_9:
    // 0x800B37D4: lw          $a0, 0x98($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X98);
    // 0x800B37D8: jal         0x800C6DBC
    // 0x800B37DC: nop

    func_800C6DBC(rdram, ctx);
        goto after_10;
    // 0x800B37DC: nop

    after_10:
L_800B37E0:
    // 0x800B37E0: lw          $a0, 0x60($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X60);
    // 0x800B37E4: jal         0x80001C98
    // 0x800B37E8: nop

    rs_free(rdram, ctx);
        goto after_11;
    // 0x800B37E8: nop

    after_11:
    // 0x800B37EC: lw          $a0, 0x94($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X94);
    // 0x800B37F0: jal         0x800C6DBC
    // 0x800B37F4: nop

    func_800C6DBC(rdram, ctx);
        goto after_12;
    // 0x800B37F4: nop

    after_12:
    // 0x800B37F8: lw          $v0, 0x5C($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X5C);
    // 0x800B37FC: addiu       $a2, $sp, 0x10
    ctx->r6 = ADD32(ctx->r29, 0X10);
    // 0x800B3800: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x800B3804: lw          $a0, 0x0($s5)
    ctx->r4 = MEM_W(ctx->r21, 0X0);
    // 0x800B3808: lw          $a1, 0x58($s3)
    ctx->r5 = MEM_W(ctx->r19, 0X58);
    // 0x800B380C: jal         0x80006F78
    // 0x800B3810: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    func_80006F78(rdram, ctx);
        goto after_13;
    // 0x800B3810: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    after_13:
    // 0x800B3814: jal         0x80001C98
    // 0x800B3818: addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    rs_free(rdram, ctx);
        goto after_14;
    // 0x800B3818: addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    after_14:
    // 0x800B381C: j           L_800B3680
    // 0x800B3820: nop

        goto L_800B3680;
    // 0x800B3820: nop

;}
RECOMP_FUNC void func_800B36FC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B36FC: lui         $a3, 0x8011
    ctx->r7 = S32(0X8011 << 16);
    // 0x800B3700: addiu       $a3, $a3, -0x4058
    ctx->r7 = ADD32(ctx->r7, -0X4058);
    // 0x800B3704: lui         $a2, 0x8011
    ctx->r6 = S32(0X8011 << 16);
    // 0x800B3708: lw          $v1, 0xB8($a0)
    ctx->r3 = MEM_W(ctx->r4, 0XB8);
    // 0x800B370C: addiu       $a2, $a2, -0x41E8
    ctx->r6 = ADD32(ctx->r6, -0X41E8);
    // 0x800B3710: sll         $a1, $v1, 1
    ctx->r5 = S32(ctx->r3 << 1);
    // 0x800B3714: addu        $a1, $a1, $a3
    ctx->r5 = ADD32(ctx->r5, ctx->r7);
    // 0x800B3718: sll         $v0, $v1, 3
    ctx->r2 = S32(ctx->r3 << 3);
    // 0x800B371C: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800B3720: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800B3724: addu        $v0, $v0, $a2
    ctx->r2 = ADD32(ctx->r2, ctx->r6);
    // 0x800B3728: lhu         $v1, 0x0($a1)
    ctx->r3 = MEM_HU(ctx->r5, 0X0);
    // 0x800B372C: lhu         $v0, 0x0($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X0);
    // 0x800B3730: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x800B3734: sh          $v1, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r3;
    // 0x800B3738: lw          $v1, 0xB8($a0)
    ctx->r3 = MEM_W(ctx->r4, 0XB8);
    // 0x800B373C: sll         $a1, $v1, 1
    ctx->r5 = S32(ctx->r3 << 1);
    // 0x800B3740: addu        $a1, $a1, $a3
    ctx->r5 = ADD32(ctx->r5, ctx->r7);
    // 0x800B3744: sll         $v0, $v1, 3
    ctx->r2 = S32(ctx->r3 << 3);
    // 0x800B3748: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800B374C: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800B3750: addu        $v0, $v0, $a2
    ctx->r2 = ADD32(ctx->r2, ctx->r6);
    // 0x800B3754: lhu         $v1, 0x0($a1)
    ctx->r3 = MEM_HU(ctx->r5, 0X0);
    // 0x800B3758: lhu         $v0, 0x4($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X4);
    // 0x800B375C: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x800B3760: sh          $v1, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r3;
    // 0x800B3764: lw          $v1, 0xB8($a0)
    ctx->r3 = MEM_W(ctx->r4, 0XB8);
    // 0x800B3768: sll         $a1, $v1, 1
    ctx->r5 = S32(ctx->r3 << 1);
    // 0x800B376C: addu        $a1, $a1, $a3
    ctx->r5 = ADD32(ctx->r5, ctx->r7);
    // 0x800B3770: sll         $v0, $v1, 3
    ctx->r2 = S32(ctx->r3 << 3);
    // 0x800B3774: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800B3778: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800B377C: addu        $v0, $v0, $a2
    ctx->r2 = ADD32(ctx->r2, ctx->r6);
    // 0x800B3780: lhu         $v1, 0x0($a1)
    ctx->r3 = MEM_HU(ctx->r5, 0X0);
    // 0x800B3784: lhu         $v0, 0x2($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X2);
    // 0x800B3788: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x800B378C: sh          $v1, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r3;
    // 0x800B3790: lw          $v1, 0xB8($a0)
    ctx->r3 = MEM_W(ctx->r4, 0XB8);
    // 0x800B3794: sll         $a0, $v1, 1
    ctx->r4 = S32(ctx->r3 << 1);
    // 0x800B3798: addu        $a0, $a0, $a3
    ctx->r4 = ADD32(ctx->r4, ctx->r7);
    // 0x800B379C: sll         $v0, $v1, 3
    ctx->r2 = S32(ctx->r3 << 3);
    // 0x800B37A0: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800B37A4: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800B37A8: addu        $v0, $v0, $a2
    ctx->r2 = ADD32(ctx->r2, ctx->r6);
    // 0x800B37AC: lhu         $v1, 0x0($a0)
    ctx->r3 = MEM_HU(ctx->r4, 0X0);
    // 0x800B37B0: lhu         $v0, 0x1E($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X1E);
    // 0x800B37B4: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x800B37B8: jr          $ra
    // 0x800B37BC: sh          $v1, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r3;
    return;
    // 0x800B37BC: sh          $v1, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r3;
;}
RECOMP_FUNC void func_800B37C0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B37C0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800B37C4: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x800B37C8: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x800B37CC: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800B37D0: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
    // 0x800B37D4: sw          $zero, -0x6950($v0)
    MEM_W(-0X6950, ctx->r2) = 0;
    // 0x800B37D8: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x800B37DC: lui         $a1, 0x8011
    ctx->r5 = S32(0X8011 << 16);
    // 0x800B37E0: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800B37E4: sw          $ra, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r31;
    // 0x800B37E8: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x800B37EC: sw          $v0, -0x694C($v1)
    MEM_W(-0X694C, ctx->r3) = ctx->r2;
    // 0x800B37F0: lw          $v1, 0xB8($s0)
    ctx->r3 = MEM_W(ctx->r16, 0XB8);
    // 0x800B37F4: addiu       $a0, $a0, 0x7DB8
    ctx->r4 = ADD32(ctx->r4, 0X7DB8);
    // 0x800B37F8: sw          $zero, 0x28($s0)
    MEM_W(0X28, ctx->r16) = 0;
    // 0x800B37FC: sw          $zero, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = 0;
    // 0x800B3800: sw          $zero, 0x30($s0)
    MEM_W(0X30, ctx->r16) = 0;
    // 0x800B3804: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x800B3808: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800B380C: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800B3810: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800B3814: sll         $v0, $v0, 5
    ctx->r2 = S32(ctx->r2 << 5);
    // 0x800B3818: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x800B381C: lhu         $v0, 0x184($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X184);
    // 0x800B3820: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x800B3824: andi        $v0, $v0, 0x40
    ctx->r2 = ctx->r2 & 0X40;
    // 0x800B3828: bne         $v0, $zero, L_800B384C
    if (ctx->r2 != 0) {
        // 0x800B382C: sb          $v1, -0x6948($a1)
        MEM_B(-0X6948, ctx->r5) = ctx->r3;
            goto L_800B384C;
    }
    // 0x800B382C: sb          $v1, -0x6948($a1)
    MEM_B(-0X6948, ctx->r5) = ctx->r3;
    // 0x800B3830: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x800B3834: sw          $v0, 0x1C8($s0)
    MEM_W(0X1C8, ctx->r16) = ctx->r2;
    // 0x800B3838: ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
    // 0x800B383C: sw          $zero, 0x184($s0)
    MEM_W(0X184, ctx->r16) = 0;
    // 0x800B3840: sw          $zero, 0x15C($s0)
    MEM_W(0X15C, ctx->r16) = 0;
    // 0x800B3844: j           L_800B3858
    // 0x800B3848: sh          $v0, 0x1CC($s0)
    MEM_H(0X1CC, ctx->r16) = ctx->r2;
        goto L_800B3858;
    // 0x800B3848: sh          $v0, 0x1CC($s0)
    MEM_H(0X1CC, ctx->r16) = ctx->r2;
L_800B384C:
    // 0x800B384C: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800B3850: lwc1        $f0, 0x57AC($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X57AC);
    // 0x800B3854: swc1        $f0, 0x184($s0)
    MEM_W(0X184, ctx->r16) = ctx->f0.u32l;
L_800B3858:
    // 0x800B3858: lhu         $v1, 0x1CC($s0)
    ctx->r3 = MEM_HU(ctx->r16, 0X1CC);
    // 0x800B385C: ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
    // 0x800B3860: beq         $v1, $v0, L_800B38A0
    if (ctx->r3 == ctx->r2) {
        // 0x800B3864: addu        $s1, $v0, $zero
        ctx->r17 = ADD32(ctx->r2, 0);
            goto L_800B38A0;
    }
    // 0x800B3864: addu        $s1, $v0, $zero
    ctx->r17 = ADD32(ctx->r2, 0);
L_800B3868:
    // 0x800B3868: lhu         $a0, 0x1CC($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X1CC);
    // 0x800B386C: jal         0x80040218
    // 0x800B3870: nop

    func_80040218(rdram, ctx);
        goto after_0;
    // 0x800B3870: nop

    after_0:
    // 0x800B3874: andi        $a0, $v0, 0xFFFF
    ctx->r4 = ctx->r2 & 0XFFFF;
    // 0x800B3878: beq         $a0, $s1, L_800B3890
    if (ctx->r4 == ctx->r17) {
        // 0x800B387C: nop
    
            goto L_800B3890;
    }
    // 0x800B387C: nop

    // 0x800B3880: jal         0x8003ED74
    // 0x800B3884: nop

    func_8003ED74(rdram, ctx);
        goto after_1;
    // 0x800B3884: nop

    after_1:
    // 0x800B3888: j           L_800B3868
    // 0x800B388C: nop

        goto L_800B3868;
    // 0x800B388C: nop

L_800B3890:
    // 0x800B3890: lhu         $a0, 0x1CC($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X1CC);
    // 0x800B3894: jal         0x8003F0C8
    // 0x800B3898: nop

    func_8003F0C8(rdram, ctx);
        goto after_2;
    // 0x800B3898: nop

    after_2:
    // 0x800B389C: sh          $s1, 0x1CC($s0)
    MEM_H(0X1CC, ctx->r16) = ctx->r17;
L_800B38A0:
    // 0x800B38A0: lbu         $v0, 0x24C($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X24C);
    // 0x800B38A4: beq         $v0, $zero, L_800B38B8
    if (ctx->r2 == 0) {
        // 0x800B38A8: nop
    
            goto L_800B38B8;
    }
    // 0x800B38A8: nop

    // 0x800B38AC: sb          $zero, 0x24C($s0)
    MEM_B(0X24C, ctx->r16) = 0;
    // 0x800B38B0: jal         0x80098DE0
    // 0x800B38B4: addiu       $a0, $s0, 0x208
    ctx->r4 = ADD32(ctx->r16, 0X208);
    func_80098DE0(rdram, ctx);
        goto after_3;
    // 0x800B38B4: addiu       $a0, $s0, 0x208
    ctx->r4 = ADD32(ctx->r16, 0X208);
    after_3:
L_800B38B8:
    // 0x800B38B8: jal         0x8003E5F8
    // 0x800B38BC: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    func_8003E5F8(rdram, ctx);
        goto after_4;
    // 0x800B38BC: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    after_4:
    // 0x800B38C0: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x800B38C4: sh          $v0, 0x1CC($s0)
    MEM_H(0X1CC, ctx->r16) = ctx->r2;
    // 0x800B38C8: lw          $v0, 0xB8($s0)
    ctx->r2 = MEM_W(ctx->r16, 0XB8);
    // 0x800B38CC: addiu       $v1, $v1, 0xB40
    ctx->r3 = ADD32(ctx->r3, 0XB40);
    // 0x800B38D0: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800B38D4: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800B38D8: lw          $v0, 0xC($v0)
    ctx->r2 = MEM_W(ctx->r2, 0XC);
    // 0x800B38DC: andi        $v0, $v0, 0x200
    ctx->r2 = ctx->r2 & 0X200;
    // 0x800B38E0: beq         $v0, $zero, L_800B38F8
    if (ctx->r2 == 0) {
        // 0x800B38E4: nop
    
            goto L_800B38F8;
    }
    // 0x800B38E4: nop

    // 0x800B38E8: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800B38EC: lwc1        $f0, 0x57B0($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X57B0);
    // 0x800B38F0: j           L_800B3904
    // 0x800B38F4: swc1        $f0, 0x16C($s0)
    MEM_W(0X16C, ctx->r16) = ctx->f0.u32l;
        goto L_800B3904;
    // 0x800B38F4: swc1        $f0, 0x16C($s0)
    MEM_W(0X16C, ctx->r16) = ctx->f0.u32l;
L_800B38F8:
    // 0x800B38F8: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800B38FC: lwc1        $f0, 0x57B4($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X57B4);
    // 0x800B3900: swc1        $f0, 0x16C($s0)
    MEM_W(0X16C, ctx->r16) = ctx->f0.u32l;
L_800B3904:
    // 0x800B3904: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800B3908: lui         $v1, 0x1
    ctx->r3 = S32(0X1 << 16);
    // 0x800B390C: lw          $v0, 0xB18($v0)
    ctx->r2 = MEM_W(ctx->r2, 0XB18);
    // 0x800B3910: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800B3914: and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // 0x800B3918: beq         $v0, $zero, L_800B3928
    if (ctx->r2 == 0) {
        // 0x800B391C: nop
    
            goto L_800B3928;
    }
    // 0x800B391C: nop

    // 0x800B3920: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800B3924: lwc1        $f0, 0x57B8($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X57B8);
L_800B3928:
    // 0x800B3928: lw          $a0, 0xB8($s0)
    ctx->r4 = MEM_W(ctx->r16, 0XB8);
    // 0x800B392C: lhu         $a1, 0xB4($s0)
    ctx->r5 = MEM_HU(ctx->r16, 0XB4);
    // 0x800B3930: addiu       $a2, $s0, 0x4
    ctx->r6 = ADD32(ctx->r16, 0X4);
    // 0x800B3934: swc1        $f0, 0xC8($s0)
    MEM_W(0XC8, ctx->r16) = ctx->f0.u32l;
    // 0x800B3938: sw          $zero, 0x188($s0)
    MEM_W(0X188, ctx->r16) = 0;
    // 0x800B393C: sw          $zero, 0x18C($s0)
    MEM_W(0X18C, ctx->r16) = 0;
    // 0x800B3940: jal         0x800531BC
    // 0x800B3944: sw          $zero, 0x17C($s0)
    MEM_W(0X17C, ctx->r16) = 0;
    func_800531BC(rdram, ctx);
        goto after_5;
    // 0x800B3944: sw          $zero, 0x17C($s0)
    MEM_W(0X17C, ctx->r16) = 0;
    after_5:
    // 0x800B3948: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x800B394C: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800B3950: sw          $zero, -0x4394($v0)
    MEM_W(-0X4394, ctx->r2) = 0;
    // 0x800B3954: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800B3958: lui         $a1, 0x8011
    ctx->r5 = S32(0X8011 << 16);
    // 0x800B395C: sw          $zero, -0x4390($v0)
    MEM_W(-0X4390, ctx->r2) = 0;
    // 0x800B3960: lw          $v0, -0x35E4($a1)
    ctx->r2 = MEM_W(ctx->r5, -0X35E4);
    // 0x800B3964: addiu       $v1, $zero, -0x101
    ctx->r3 = ADD32(0, -0X101);
    // 0x800B3968: sw          $zero, 0x1A0($s0)
    MEM_W(0X1A0, ctx->r16) = 0;
    // 0x800B396C: sw          $zero, 0x19C($s0)
    MEM_W(0X19C, ctx->r16) = 0;
    // 0x800B3970: sw          $zero, 0x198($s0)
    MEM_W(0X198, ctx->r16) = 0;
    // 0x800B3974: and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // 0x800B3978: jal         0x800B36FC
    // 0x800B397C: sw          $v0, -0x35E4($a1)
    MEM_W(-0X35E4, ctx->r5) = ctx->r2;
    func_800B36FC(rdram, ctx);
        goto after_6;
    // 0x800B397C: sw          $v0, -0x35E4($a1)
    MEM_W(-0X35E4, ctx->r5) = ctx->r2;
    after_6:
    // 0x800B3980: jal         0x800AE830
    // 0x800B3984: nop

    func_800AE830(rdram, ctx);
        goto after_7;
    // 0x800B3984: nop

    after_7:
    // 0x800B3988: lhu         $v1, 0xB4($s0)
    ctx->r3 = MEM_HU(ctx->r16, 0XB4);
    // 0x800B398C: slti        $v0, $v1, 0x5
    ctx->r2 = SIGNED(ctx->r3) < 0X5 ? 1 : 0;
    // 0x800B3990: beq         $v0, $zero, L_800B39C4
    if (ctx->r2 == 0) {
        // 0x800B3994: slti        $v0, $v1, 0x3
        ctx->r2 = SIGNED(ctx->r3) < 0X3 ? 1 : 0;
            goto L_800B39C4;
    }
    // 0x800B3994: slti        $v0, $v1, 0x3
    ctx->r2 = SIGNED(ctx->r3) < 0X3 ? 1 : 0;
    // 0x800B3998: bne         $v0, $zero, L_800B39C8
    if (ctx->r2 != 0) {
        // 0x800B399C: lui         $v0, 0x8013
        ctx->r2 = S32(0X8013 << 16);
            goto L_800B39C8;
    }
    // 0x800B399C: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800B39A0: lui         $a0, 0xFEFF
    ctx->r4 = S32(0XFEFF << 16);
    // 0x800B39A4: lw          $v1, 0xB8($s0)
    ctx->r3 = MEM_W(ctx->r16, 0XB8);
    // 0x800B39A8: addiu       $v0, $v0, 0xB40
    ctx->r2 = ADD32(ctx->r2, 0XB40);
    // 0x800B39AC: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x800B39B0: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x800B39B4: lw          $v0, 0xC($v1)
    ctx->r2 = MEM_W(ctx->r3, 0XC);
    // 0x800B39B8: ori         $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 | 0XFFFF;
    // 0x800B39BC: j           L_800B39E4
    // 0x800B39C0: and         $v0, $v0, $a0
    ctx->r2 = ctx->r2 & ctx->r4;
        goto L_800B39E4;
    // 0x800B39C0: and         $v0, $v0, $a0
    ctx->r2 = ctx->r2 & ctx->r4;
L_800B39C4:
    // 0x800B39C4: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
L_800B39C8:
    // 0x800B39C8: lw          $v1, 0xB8($s0)
    ctx->r3 = MEM_W(ctx->r16, 0XB8);
    // 0x800B39CC: addiu       $v0, $v0, 0xB40
    ctx->r2 = ADD32(ctx->r2, 0XB40);
    // 0x800B39D0: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x800B39D4: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x800B39D8: lw          $v0, 0xC($v1)
    ctx->r2 = MEM_W(ctx->r3, 0XC);
    // 0x800B39DC: lui         $a0, 0x100
    ctx->r4 = S32(0X100 << 16);
    // 0x800B39E0: or          $v0, $v0, $a0
    ctx->r2 = ctx->r2 | ctx->r4;
L_800B39E4:
    // 0x800B39E4: sw          $v0, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r2;
    // 0x800B39E8: jal         0x800AE3F0
    // 0x800B39EC: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_800AE3F0(rdram, ctx);
        goto after_8;
    // 0x800B39EC: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_8:
    // 0x800B39F0: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800B39F4: sb          $zero, -0x6947($v0)
    MEM_B(-0X6947, ctx->r2) = 0;
    // 0x800B39F8: sb          $zero, 0x1BC($s0)
    MEM_B(0X1BC, ctx->r16) = 0;
    // 0x800B39FC: lw          $ra, 0x18($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X18);
    // 0x800B3A00: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x800B3A04: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x800B3A08: jr          $ra
    // 0x800B3A0C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x800B3A0C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_800B3824(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B3824: addiu       $sp, $sp, -0x710
    ctx->r29 = ADD32(ctx->r29, -0X710);
    // 0x800B3828: sdc1        $f24, 0x708($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X708, ctx->r29);
    // 0x800B382C: mov.s       $f24, $f12
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 12);
    ctx->f24.fl = ctx->f12.fl;
    // 0x800B3830: addiu       $v1, $sp, 0x610
    ctx->r3 = ADD32(ctx->r29, 0X610);
    // 0x800B3834: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x800B3838: addiu       $v0, $v0, 0x5CB4
    ctx->r2 = ADD32(ctx->r2, 0X5CB4);
    // 0x800B383C: addiu       $a0, $v0, 0x20
    ctx->r4 = ADD32(ctx->r2, 0X20);
    // 0x800B3840: sw          $ra, 0x6F0($sp)
    MEM_W(0X6F0, ctx->r29) = ctx->r31;
    // 0x800B3844: sw          $s7, 0x6EC($sp)
    MEM_W(0X6EC, ctx->r29) = ctx->r23;
    // 0x800B3848: sw          $s6, 0x6E8($sp)
    MEM_W(0X6E8, ctx->r29) = ctx->r22;
    // 0x800B384C: sw          $s5, 0x6E4($sp)
    MEM_W(0X6E4, ctx->r29) = ctx->r21;
    // 0x800B3850: sw          $s4, 0x6E0($sp)
    MEM_W(0X6E0, ctx->r29) = ctx->r20;
    // 0x800B3854: sw          $s3, 0x6DC($sp)
    MEM_W(0X6DC, ctx->r29) = ctx->r19;
    // 0x800B3858: sw          $s2, 0x6D8($sp)
    MEM_W(0X6D8, ctx->r29) = ctx->r18;
    // 0x800B385C: sw          $s1, 0x6D4($sp)
    MEM_W(0X6D4, ctx->r29) = ctx->r17;
    // 0x800B3860: sw          $s0, 0x6D0($sp)
    MEM_W(0X6D0, ctx->r29) = ctx->r16;
    // 0x800B3864: sdc1        $f22, 0x700($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X700, ctx->r29);
    // 0x800B3868: sdc1        $f20, 0x6F8($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X6F8, ctx->r29);
L_800B386C:
    // 0x800B386C: lw          $a3, 0x0($v0)
    ctx->r7 = MEM_W(ctx->r2, 0X0);
    // 0x800B3870: lw          $t0, 0x4($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X4);
    // 0x800B3874: lw          $t1, 0x8($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X8);
    // 0x800B3878: lw          $t2, 0xC($v0)
    ctx->r10 = MEM_W(ctx->r2, 0XC);
    // 0x800B387C: sw          $a3, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r7;
    // 0x800B3880: sw          $t0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r8;
    // 0x800B3884: sw          $t1, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r9;
    // 0x800B3888: sw          $t2, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r10;
    // 0x800B388C: addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
    // 0x800B3890: bne         $v0, $a0, L_800B386C
    if (ctx->r2 != ctx->r4) {
        // 0x800B3894: addiu       $v1, $v1, 0x10
        ctx->r3 = ADD32(ctx->r3, 0X10);
            goto L_800B386C;
    }
    // 0x800B3894: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
    // 0x800B3898: lw          $a3, 0x0($v0)
    ctx->r7 = MEM_W(ctx->r2, 0X0);
    // 0x800B389C: sw          $a3, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r7;
    // 0x800B38A0: addiu       $v1, $sp, 0x638
    ctx->r3 = ADD32(ctx->r29, 0X638);
    // 0x800B38A4: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x800B38A8: addiu       $v0, $v0, 0x5CD8
    ctx->r2 = ADD32(ctx->r2, 0X5CD8);
    // 0x800B38AC: addiu       $a0, $v0, 0x20
    ctx->r4 = ADD32(ctx->r2, 0X20);
L_800B38B0:
    // 0x800B38B0: lw          $a3, 0x0($v0)
    ctx->r7 = MEM_W(ctx->r2, 0X0);
    // 0x800B38B4: lw          $t0, 0x4($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X4);
    // 0x800B38B8: lw          $t1, 0x8($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X8);
    // 0x800B38BC: lw          $t2, 0xC($v0)
    ctx->r10 = MEM_W(ctx->r2, 0XC);
    // 0x800B38C0: sw          $a3, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r7;
    // 0x800B38C4: sw          $t0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r8;
    // 0x800B38C8: sw          $t1, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r9;
    // 0x800B38CC: sw          $t2, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r10;
    // 0x800B38D0: addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
    // 0x800B38D4: bne         $v0, $a0, L_800B38B0
    if (ctx->r2 != ctx->r4) {
        // 0x800B38D8: addiu       $v1, $v1, 0x10
        ctx->r3 = ADD32(ctx->r3, 0X10);
            goto L_800B38B0;
    }
    // 0x800B38D8: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
    // 0x800B38DC: lw          $a3, 0x0($v0)
    ctx->r7 = MEM_W(ctx->r2, 0X0);
    // 0x800B38E0: sw          $a3, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r7;
    // 0x800B38E4: addiu       $v1, $sp, 0x660
    ctx->r3 = ADD32(ctx->r29, 0X660);
    // 0x800B38E8: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x800B38EC: addiu       $v0, $v0, 0x5D04
    ctx->r2 = ADD32(ctx->r2, 0X5D04);
    // 0x800B38F0: addiu       $a0, $v0, 0x30
    ctx->r4 = ADD32(ctx->r2, 0X30);
L_800B38F4:
    // 0x800B38F4: lw          $a3, 0x0($v0)
    ctx->r7 = MEM_W(ctx->r2, 0X0);
    // 0x800B38F8: lw          $t0, 0x4($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X4);
    // 0x800B38FC: lw          $t1, 0x8($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X8);
    // 0x800B3900: lw          $t2, 0xC($v0)
    ctx->r10 = MEM_W(ctx->r2, 0XC);
    // 0x800B3904: sw          $a3, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r7;
    // 0x800B3908: sw          $t0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r8;
    // 0x800B390C: sw          $t1, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r9;
    // 0x800B3910: sw          $t2, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r10;
    // 0x800B3914: addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
    // 0x800B3918: bne         $v0, $a0, L_800B38F4
    if (ctx->r2 != ctx->r4) {
        // 0x800B391C: addiu       $v1, $v1, 0x10
        ctx->r3 = ADD32(ctx->r3, 0X10);
            goto L_800B38F4;
    }
    // 0x800B391C: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
    // 0x800B3920: lw          $a3, 0x0($v0)
    ctx->r7 = MEM_W(ctx->r2, 0X0);
    // 0x800B3924: sw          $a3, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r7;
    // 0x800B3928: addiu       $v1, $sp, 0x698
    ctx->r3 = ADD32(ctx->r29, 0X698);
    // 0x800B392C: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x800B3930: addiu       $v0, $v0, 0x5D40
    ctx->r2 = ADD32(ctx->r2, 0X5D40);
    // 0x800B3934: addiu       $a0, $v0, 0x30
    ctx->r4 = ADD32(ctx->r2, 0X30);
L_800B3938:
    // 0x800B3938: lw          $a3, 0x0($v0)
    ctx->r7 = MEM_W(ctx->r2, 0X0);
    // 0x800B393C: lw          $t0, 0x4($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X4);
    // 0x800B3940: lw          $t1, 0x8($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X8);
    // 0x800B3944: lw          $t2, 0xC($v0)
    ctx->r10 = MEM_W(ctx->r2, 0XC);
    // 0x800B3948: sw          $a3, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r7;
    // 0x800B394C: sw          $t0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r8;
    // 0x800B3950: sw          $t1, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r9;
    // 0x800B3954: sw          $t2, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r10;
    // 0x800B3958: addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
    // 0x800B395C: bne         $v0, $a0, L_800B3938
    if (ctx->r2 != ctx->r4) {
        // 0x800B3960: addiu       $v1, $v1, 0x10
        ctx->r3 = ADD32(ctx->r3, 0X10);
            goto L_800B3938;
    }
    // 0x800B3960: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
    // 0x800B3964: addu        $s1, $zero, $zero
    ctx->r17 = ADD32(0, 0);
    // 0x800B3968: addiu       $s5, $sp, 0x10
    ctx->r21 = ADD32(ctx->r29, 0X10);
    // 0x800B396C: addiu       $s7, $zero, 0xFF
    ctx->r23 = ADD32(0, 0XFF);
    // 0x800B3970: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800B3974: ldc1        $f22, 0x5D78($at)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r1, 0X5D78);
    // 0x800B3978: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800B397C: lwc1        $f20, 0x5D80($at)
    ctx->f20.u32l = MEM_W(ctx->r1, 0X5D80);
    // 0x800B3980: lui         $s6, 0x8000
    ctx->r22 = S32(0X8000 << 16);
    // 0x800B3984: lw          $a3, 0x0($v0)
    ctx->r7 = MEM_W(ctx->r2, 0X0);
    // 0x800B3988: sw          $a3, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r7;
    // 0x800B398C: addu        $s2, $zero, $zero
    ctx->r18 = ADD32(0, 0);
L_800B3990:
    // 0x800B3990: sll         $s4, $s1, 3
    ctx->r20 = S32(ctx->r17 << 3);
    // 0x800B3994: addu        $s3, $s1, $zero
    ctx->r19 = ADD32(ctx->r17, 0);
L_800B3998:
    // 0x800B3998: addu        $s0, $s4, $s2
    ctx->r16 = ADD32(ctx->r20, ctx->r18);
    // 0x800B399C: addu        $v0, $s5, $s0
    ctx->r2 = ADD32(ctx->r21, ctx->r16);
    // 0x800B39A0: mtc1        $s1, $f12
    ctx->f12.u32l = ctx->r17;
    // 0x800B39A4: cvt.d.w     $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    ctx->f12.d = CVT_D_W(ctx->f12.u32l);
    // 0x800B39A8: bgez        $s1, L_800B39B4
    if (SIGNED(ctx->r17) >= 0) {
        // 0x800B39AC: sb          $s7, 0x0($v0)
        MEM_B(0X0, ctx->r2) = ctx->r23;
            goto L_800B39B4;
    }
    // 0x800B39AC: sb          $s7, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r23;
    // 0x800B39B0: add.d       $f12, $f12, $f22
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f12.d); NAN_CHECK(ctx->f22.d); 
    ctx->f12.d = ctx->f12.d + ctx->f22.d;
L_800B39B4:
    // 0x800B39B4: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800B39B8: lwc1        $f0, 0x5D84($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X5D84);
    // 0x800B39BC: cvt.s.d     $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.d); 
    ctx->f12.fl = CVT_S_D(ctx->f12.d);
    // 0x800B39C0: mul.s       $f12, $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = MUL_S(ctx->f12.fl, ctx->f0.fl);
    // 0x800B39C4: jal         0x800662E0
    // 0x800B39C8: nop

    func_800662E0(rdram, ctx);
        goto after_0;
    // 0x800B39C8: nop

    after_0:
    // 0x800B39CC: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800B39D0: lwc1        $f2, 0x5D88($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X5D88);
    // 0x800B39D4: mul.s       $f2, $f0, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x800B39D8: c.lt.s      $f24, $f2
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f24.fl < ctx->f2.fl;
    // 0x800B39DC: nop

    // 0x800B39E0: bc1tl       L_800B39E8
    if (c1cs) {
        // 0x800B39E4: mov.s       $f2, $f24
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 24);
    ctx->f2.fl = ctx->f24.fl;
            goto L_800B39E8;
    }
    goto skip_0;
    // 0x800B39E4: mov.s       $f2, $f24
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 24);
    ctx->f2.fl = ctx->f24.fl;
    skip_0:
L_800B39E8:
    // 0x800B39E8: addiu       $v0, $sp, 0x210
    ctx->r2 = ADD32(ctx->r29, 0X210);
    // 0x800B39EC: c.le.s      $f20, $f2
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f20.fl <= ctx->f2.fl;
    // 0x800B39F0: nop

    // 0x800B39F4: bc1t        L_800B3A0C
    if (c1cs) {
        // 0x800B39F8: addu        $v0, $v0, $s0
        ctx->r2 = ADD32(ctx->r2, ctx->r16);
            goto L_800B3A0C;
    }
    // 0x800B39F8: addu        $v0, $v0, $s0
    ctx->r2 = ADD32(ctx->r2, ctx->r16);
    // 0x800B39FC: trunc.w.s   $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    ctx->f4.u32l = TRUNC_W_S(ctx->f2.fl);
    // 0x800B3A00: mfc1        $v1, $f4
    ctx->r3 = (int32_t)ctx->f4.u32l;
    // 0x800B3A04: j           L_800B3A20
    // 0x800B3A08: sb          $v1, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r3;
        goto L_800B3A20;
    // 0x800B3A08: sb          $v1, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r3;
L_800B3A0C:
    // 0x800B3A0C: sub.s       $f0, $f2, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = ctx->f2.fl - ctx->f20.fl;
    // 0x800B3A10: trunc.w.s   $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    ctx->f4.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800B3A14: mfc1        $v1, $f4
    ctx->r3 = (int32_t)ctx->f4.u32l;
    // 0x800B3A18: or          $v1, $v1, $s6
    ctx->r3 = ctx->r3 | ctx->r22;
    // 0x800B3A1C: sb          $v1, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r3;
L_800B3A20:
    // 0x800B3A20: addiu       $v0, $sp, 0x410
    ctx->r2 = ADD32(ctx->r29, 0X410);
    // 0x800B3A24: c.le.s      $f20, $f2
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f20.fl <= ctx->f2.fl;
    // 0x800B3A28: nop

    // 0x800B3A2C: bc1t        L_800B3A44
    if (c1cs) {
        // 0x800B3A30: addu        $v0, $v0, $s3
        ctx->r2 = ADD32(ctx->r2, ctx->r19);
            goto L_800B3A44;
    }
    // 0x800B3A30: addu        $v0, $v0, $s3
    ctx->r2 = ADD32(ctx->r2, ctx->r19);
    // 0x800B3A34: trunc.w.s   $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    ctx->f4.u32l = TRUNC_W_S(ctx->f2.fl);
    // 0x800B3A38: mfc1        $v1, $f4
    ctx->r3 = (int32_t)ctx->f4.u32l;
    // 0x800B3A3C: j           L_800B3A58
    // 0x800B3A40: sb          $v1, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r3;
        goto L_800B3A58;
    // 0x800B3A40: sb          $v1, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r3;
L_800B3A44:
    // 0x800B3A44: sub.s       $f0, $f2, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = ctx->f2.fl - ctx->f20.fl;
    // 0x800B3A48: trunc.w.s   $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    ctx->f4.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800B3A4C: mfc1        $v1, $f4
    ctx->r3 = (int32_t)ctx->f4.u32l;
    // 0x800B3A50: or          $v1, $v1, $s6
    ctx->r3 = ctx->r3 | ctx->r22;
    // 0x800B3A54: sb          $v1, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r3;
L_800B3A58:
    // 0x800B3A58: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x800B3A5C: sltiu       $v0, $s2, 0x8
    ctx->r2 = ctx->r18 < 0X8 ? 1 : 0;
    // 0x800B3A60: bne         $v0, $zero, L_800B3998
    if (ctx->r2 != 0) {
        // 0x800B3A64: addiu       $s3, $s3, 0x40
        ctx->r19 = ADD32(ctx->r19, 0X40);
            goto L_800B3998;
    }
    // 0x800B3A64: addiu       $s3, $s3, 0x40
    ctx->r19 = ADD32(ctx->r19, 0X40);
    // 0x800B3A68: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x800B3A6C: sltiu       $v0, $s1, 0x40
    ctx->r2 = ctx->r17 < 0X40 ? 1 : 0;
    // 0x800B3A70: bne         $v0, $zero, L_800B3990
    if (ctx->r2 != 0) {
        // 0x800B3A74: addu        $s2, $zero, $zero
        ctx->r18 = ADD32(0, 0);
            goto L_800B3990;
    }
    // 0x800B3A74: addu        $s2, $zero, $zero
    ctx->r18 = ADD32(0, 0);
    // 0x800B3A78: addiu       $a0, $sp, 0x610
    ctx->r4 = ADD32(ctx->r29, 0X610);
    // 0x800B3A7C: addiu       $a1, $sp, 0x660
    ctx->r5 = ADD32(ctx->r29, 0X660);
    // 0x800B3A80: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x800B3A84: addiu       $v1, $sp, 0x10
    ctx->r3 = ADD32(ctx->r29, 0X10);
    // 0x800B3A88: addiu       $v0, $sp, 0x210
    ctx->r2 = ADD32(ctx->r29, 0X210);
    // 0x800B3A8C: sw          $v0, 0x69C($sp)
    MEM_W(0X69C, ctx->r29) = ctx->r2;
    // 0x800B3A90: addiu       $v0, $sp, 0x410
    ctx->r2 = ADD32(ctx->r29, 0X410);
    // 0x800B3A94: sw          $v1, 0x698($sp)
    MEM_W(0X698, ctx->r29) = ctx->r3;
    // 0x800B3A98: sw          $v1, 0x660($sp)
    MEM_W(0X660, ctx->r29) = ctx->r3;
    // 0x800B3A9C: jal         0x80022B90
    // 0x800B3AA0: sw          $v0, 0x664($sp)
    MEM_W(0X664, ctx->r29) = ctx->r2;
    func_80022B90(rdram, ctx);
        goto after_1;
    // 0x800B3AA0: sw          $v0, 0x664($sp)
    MEM_W(0X664, ctx->r29) = ctx->r2;
    after_1:
    // 0x800B3AA4: addiu       $a0, $sp, 0x638
    ctx->r4 = ADD32(ctx->r29, 0X638);
    // 0x800B3AA8: addiu       $a1, $sp, 0x698
    ctx->r5 = ADD32(ctx->r29, 0X698);
    // 0x800B3AAC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x800B3AB0: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x800B3AB4: jal         0x80022B90
    // 0x800B3AB8: sh          $v0, -0x1910($v1)
    MEM_H(-0X1910, ctx->r3) = ctx->r2;
    func_80022B90(rdram, ctx);
        goto after_2;
    // 0x800B3AB8: sh          $v0, -0x1910($v1)
    MEM_H(-0X1910, ctx->r3) = ctx->r2;
    after_2:
    // 0x800B3ABC: lw          $ra, 0x6F0($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X6F0);
    // 0x800B3AC0: lw          $s7, 0x6EC($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X6EC);
    // 0x800B3AC4: lw          $s6, 0x6E8($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X6E8);
    // 0x800B3AC8: lw          $s5, 0x6E4($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X6E4);
    // 0x800B3ACC: lw          $s4, 0x6E0($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X6E0);
    // 0x800B3AD0: lw          $s3, 0x6DC($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X6DC);
    // 0x800B3AD4: lw          $s2, 0x6D8($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X6D8);
    // 0x800B3AD8: lw          $s1, 0x6D4($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X6D4);
    // 0x800B3ADC: lw          $s0, 0x6D0($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X6D0);
    // 0x800B3AE0: ldc1        $f24, 0x708($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X708);
    // 0x800B3AE4: ldc1        $f22, 0x700($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X700);
    // 0x800B3AE8: ldc1        $f20, 0x6F8($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X6F8);
    // 0x800B3AEC: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x800B3AF0: sh          $v0, -0x190E($v1)
    MEM_H(-0X190E, ctx->r3) = ctx->r2;
    // 0x800B3AF4: jr          $ra
    // 0x800B3AF8: addiu       $sp, $sp, 0x710
    ctx->r29 = ADD32(ctx->r29, 0X710);
    return;
    // 0x800B3AF8: addiu       $sp, $sp, 0x710
    ctx->r29 = ADD32(ctx->r29, 0X710);
;}
RECOMP_FUNC void func_800B3A10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B3A10: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x800B3A14: lbu         $v0, -0x77C8($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X77C8);
    // 0x800B3A18: addiu       $sp, $sp, -0x88
    ctx->r29 = ADD32(ctx->r29, -0X88);
    // 0x800B3A1C: sw          $s1, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r17;
    // 0x800B3A20: sw          $s3, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r19;
    // 0x800B3A24: addu        $s3, $a1, $zero
    ctx->r19 = ADD32(ctx->r5, 0);
    // 0x800B3A28: sw          $ra, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r31;
    // 0x800B3A2C: sw          $s2, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r18;
    // 0x800B3A30: sw          $s0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r16;
    // 0x800B3A34: sdc1        $f20, 0x80($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X80, ctx->r29);
    // 0x800B3A38: lw          $s2, 0x8($s3)
    ctx->r18 = MEM_W(ctx->r19, 0X8);
    // 0x800B3A3C: bne         $v0, $zero, L_800B3E2C
    if (ctx->r2 != 0) {
        // 0x800B3A40: addu        $s1, $a0, $zero
        ctx->r17 = ADD32(ctx->r4, 0);
            goto L_800B3E2C;
    }
    // 0x800B3A40: addu        $s1, $a0, $zero
    ctx->r17 = ADD32(ctx->r4, 0);
    // 0x800B3A44: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x800B3A48: lbu         $v0, -0x76DA($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X76DA);
    // 0x800B3A4C: bne         $v0, $zero, L_800B3E2C
    if (ctx->r2 != 0) {
        // 0x800B3A50: lui         $v0, 0x8013
        ctx->r2 = S32(0X8013 << 16);
            goto L_800B3E2C;
    }
    // 0x800B3A50: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800B3A54: lw          $a0, 0xB8($s1)
    ctx->r4 = MEM_W(ctx->r17, 0XB8);
    // 0x800B3A58: addiu       $v0, $v0, 0xB40
    ctx->r2 = ADD32(ctx->r2, 0XB40);
    // 0x800B3A5C: sll         $a1, $a0, 2
    ctx->r5 = S32(ctx->r4 << 2);
    // 0x800B3A60: addu        $v0, $a1, $v0
    ctx->r2 = ADD32(ctx->r5, ctx->r2);
    // 0x800B3A64: lw          $v0, 0xC($v0)
    ctx->r2 = MEM_W(ctx->r2, 0XC);
    // 0x800B3A68: lui         $v1, 0x80
    ctx->r3 = S32(0X80 << 16);
    // 0x800B3A6C: and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // 0x800B3A70: bne         $v0, $zero, L_800B3E2C
    if (ctx->r2 != 0) {
        // 0x800B3A74: lui         $v0, 0x8013
        ctx->r2 = S32(0X8013 << 16);
            goto L_800B3E2C;
    }
    // 0x800B3A74: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800B3A78: addiu       $v0, $v0, 0x7DB8
    ctx->r2 = ADD32(ctx->r2, 0X7DB8);
    // 0x800B3A7C: addu        $v1, $a1, $a0
    ctx->r3 = ADD32(ctx->r5, ctx->r4);
    // 0x800B3A80: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x800B3A84: addu        $v1, $v1, $a0
    ctx->r3 = ADD32(ctx->r3, ctx->r4);
    // 0x800B3A88: sll         $v1, $v1, 5
    ctx->r3 = S32(ctx->r3 << 5);
    // 0x800B3A8C: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x800B3A90: lhu         $v0, 0x184($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X184);
    // 0x800B3A94: andi        $v0, $v0, 0x78
    ctx->r2 = ctx->r2 & 0X78;
    // 0x800B3A98: bne         $v0, $zero, L_800B3E2C
    if (ctx->r2 != 0) {
        // 0x800B3A9C: nop
    
            goto L_800B3E2C;
    }
    // 0x800B3A9C: nop

    // 0x800B3AA0: beq         $s2, $zero, L_800B3C28
    if (ctx->r18 == 0) {
        // 0x800B3AA4: addiu       $a1, $s1, 0x4
        ctx->r5 = ADD32(ctx->r17, 0X4);
            goto L_800B3C28;
    }
    // 0x800B3AA4: addiu       $a1, $s1, 0x4
    ctx->r5 = ADD32(ctx->r17, 0X4);
    // 0x800B3AA8: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x800B3AAC: addiu       $a2, $s1, 0x28
    ctx->r6 = ADD32(ctx->r17, 0X28);
    // 0x800B3AB0: lui         $a3, 0x41C0
    ctx->r7 = S32(0X41C0 << 16);
    // 0x800B3AB4: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800B3AB8: lwc1        $f0, 0x57BC($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X57BC);
    // 0x800B3ABC: addiu       $v0, $zero, 0x1B
    ctx->r2 = ADD32(0, 0X1B);
    // 0x800B3AC0: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // 0x800B3AC4: addiu       $v0, $zero, 0x7F
    ctx->r2 = ADD32(0, 0X7F);
    // 0x800B3AC8: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x800B3ACC: addiu       $v0, $zero, 0x5A
    ctx->r2 = ADD32(0, 0X5A);
    // 0x800B3AD0: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x800B3AD4: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x800B3AD8: jal         0x800989D8
    // 0x800B3ADC: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    func_800989D8(rdram, ctx);
        goto after_0;
    // 0x800B3ADC: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    after_0:
    // 0x800B3AE0: lhu         $v1, 0xB4($s1)
    ctx->r3 = MEM_HU(ctx->r17, 0XB4);
    // 0x800B3AE4: sltiu       $v0, $v1, 0x9
    ctx->r2 = ctx->r3 < 0X9 ? 1 : 0;
    // 0x800B3AE8: beq         $v0, $zero, L_800B3B40
    if (ctx->r2 == 0) {
        // 0x800B3AEC: lui         $v0, 0x800A
        ctx->r2 = S32(0X800A << 16);
            goto L_800B3B40;
    }
    // 0x800B3AEC: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x800B3AF0: addiu       $v0, $v0, 0x57C0
    ctx->r2 = ADD32(ctx->r2, 0X57C0);
    // 0x800B3AF4: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x800B3AF8: addu        $v1, $v1, $v0
    gpr jr_addend_800B3B00 = ctx->r3;
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x800B3AFC: lw          $v0, 0x0($v1)
    ctx->r2 = ADD32(ctx->r3, 0X0);
    // 0x800B3B00: jr          $v0
    // 0x800B3B04: nop

    switch (jr_addend_800B3B00 >> 2) {
        case 0: goto L_800B3B08; break;
        case 1: goto L_800B3B28; break;
        case 2: goto L_800B3B08; break;
        case 3: goto L_800B3B18; break;
        case 4: goto L_800B3B18; break;
        case 5: goto L_800B3B38; break;
        case 6: goto L_800B3B18; break;
        case 7: goto L_800B3B28; break;
        case 8: goto L_800B3B08; break;
        default: switch_error(__func__, 0x800B3B00, 0x800A57C0);
    }
    // 0x800B3B04: nop

L_800B3B08:
    // 0x800B3B08: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800B3B0C: lwc1        $f20, 0x57E4($at)
    ctx->f20.u32l = MEM_W(ctx->r1, 0X57E4);
    // 0x800B3B10: j           L_800B3B40
    // 0x800B3B14: nop

        goto L_800B3B40;
    // 0x800B3B14: nop

L_800B3B18:
    // 0x800B3B18: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800B3B1C: lwc1        $f20, 0x57E8($at)
    ctx->f20.u32l = MEM_W(ctx->r1, 0X57E8);
    // 0x800B3B20: j           L_800B3B40
    // 0x800B3B24: nop

        goto L_800B3B40;
    // 0x800B3B24: nop

L_800B3B28:
    // 0x800B3B28: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800B3B2C: lwc1        $f20, 0x57EC($at)
    ctx->f20.u32l = MEM_W(ctx->r1, 0X57EC);
    // 0x800B3B30: j           L_800B3B40
    // 0x800B3B34: nop

        goto L_800B3B40;
    // 0x800B3B34: nop

L_800B3B38:
    // 0x800B3B38: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800B3B3C: lwc1        $f20, 0x57F0($at)
    ctx->f20.u32l = MEM_W(ctx->r1, 0X57F0);
L_800B3B40:
    // 0x800B3B40: lhu         $v1, 0x4($s3)
    ctx->r3 = MEM_HU(ctx->r19, 0X4);
    // 0x800B3B44: addiu       $v0, $zero, 0xC
    ctx->r2 = ADD32(0, 0XC);
    // 0x800B3B48: beq         $v1, $v0, L_800B3BAC
    if (ctx->r3 == ctx->r2) {
        // 0x800B3B4C: slti        $v0, $v1, 0xD
        ctx->r2 = SIGNED(ctx->r3) < 0XD ? 1 : 0;
            goto L_800B3BAC;
    }
    // 0x800B3B4C: slti        $v0, $v1, 0xD
    ctx->r2 = SIGNED(ctx->r3) < 0XD ? 1 : 0;
    // 0x800B3B50: beq         $v0, $zero, L_800B3B68
    if (ctx->r2 == 0) {
        // 0x800B3B54: slti        $v0, $v1, 0xA
        ctx->r2 = SIGNED(ctx->r3) < 0XA ? 1 : 0;
            goto L_800B3B68;
    }
    // 0x800B3B54: slti        $v0, $v1, 0xA
    ctx->r2 = SIGNED(ctx->r3) < 0XA ? 1 : 0;
    // 0x800B3B58: bne         $v0, $zero, L_800B3BF0
    if (ctx->r2 != 0) {
        // 0x800B3B5C: addu        $a0, $s2, $zero
        ctx->r4 = ADD32(ctx->r18, 0);
            goto L_800B3BF0;
    }
    // 0x800B3B5C: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // 0x800B3B60: j           L_800B3B78
    // 0x800B3B64: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
        goto L_800B3B78;
    // 0x800B3B64: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
L_800B3B68:
    // 0x800B3B68: addiu       $v0, $zero, 0xD
    ctx->r2 = ADD32(0, 0XD);
    // 0x800B3B6C: bne         $v1, $v0, L_800B3BF0
    if (ctx->r3 != ctx->r2) {
        // 0x800B3B70: addu        $a0, $s2, $zero
        ctx->r4 = ADD32(ctx->r18, 0);
            goto L_800B3BF0;
    }
    // 0x800B3B70: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // 0x800B3B74: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
L_800B3B78:
    // 0x800B3B78: addiu       $s0, $sp, 0x58
    ctx->r16 = ADD32(ctx->r29, 0X58);
    // 0x800B3B7C: lui         $a3, 0xBDCC
    ctx->r7 = S32(0XBDCC << 16);
    // 0x800B3B80: ori         $a3, $a3, 0xCCCD
    ctx->r7 = ctx->r7 | 0XCCCD;
    // 0x800B3B84: jal         0x80077784
    // 0x800B3B88: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    func_80077784(rdram, ctx);
        goto after_1;
    // 0x800B3B88: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    after_1:
    // 0x800B3B8C: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800B3B90: lwc1        $f0, 0x57F4($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X57F4);
    // 0x800B3B94: mul.s       $f20, $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f20.fl = MUL_S(ctx->f20.fl, ctx->f0.fl);
    // 0x800B3B98: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x800B3B9C: jal         0x800612A4
    // 0x800B3BA0: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_800612A4(rdram, ctx);
        goto after_2;
    // 0x800B3BA0: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_2:
    // 0x800B3BA4: j           L_800B3C2C
    // 0x800B3BA8: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
        goto L_800B3C2C;
    // 0x800B3BA8: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
L_800B3BAC:
    // 0x800B3BAC: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // 0x800B3BB0: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x800B3BB4: addiu       $s0, $sp, 0x58
    ctx->r16 = ADD32(ctx->r29, 0X58);
    // 0x800B3BB8: lui         $a3, 0xBDCC
    ctx->r7 = S32(0XBDCC << 16);
    // 0x800B3BBC: ori         $a3, $a3, 0xCCCD
    ctx->r7 = ctx->r7 | 0XCCCD;
    // 0x800B3BC0: jal         0x80077784
    // 0x800B3BC4: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    func_80077784(rdram, ctx);
        goto after_3;
    // 0x800B3BC4: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    after_3:
    // 0x800B3BC8: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800B3BCC: lwc1        $f0, 0x57F8($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X57F8);
    // 0x800B3BD0: mul.s       $f20, $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f20.fl = MUL_S(ctx->f20.fl, ctx->f0.fl);
    // 0x800B3BD4: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x800B3BD8: ori         $a1, $zero, 0xFFFF
    ctx->r5 = 0 | 0XFFFF;
    // 0x800B3BDC: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x800B3BE0: jal         0x80077570
    // 0x800B3BE4: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    func_80077570(rdram, ctx);
        goto after_4;
    // 0x800B3BE4: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    after_4:
    // 0x800B3BE8: j           L_800B3C2C
    // 0x800B3BEC: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
        goto L_800B3C2C;
    // 0x800B3BEC: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
L_800B3BF0:
    // 0x800B3BF0: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x800B3BF4: addiu       $s0, $sp, 0x58
    ctx->r16 = ADD32(ctx->r29, 0X58);
    // 0x800B3BF8: lui         $a3, 0xBDCC
    ctx->r7 = S32(0XBDCC << 16);
    // 0x800B3BFC: ori         $a3, $a3, 0xCCCD
    ctx->r7 = ctx->r7 | 0XCCCD;
    // 0x800B3C00: jal         0x80077784
    // 0x800B3C04: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    func_80077784(rdram, ctx);
        goto after_5;
    // 0x800B3C04: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    after_5:
    // 0x800B3C08: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800B3C0C: lwc1        $f0, 0x57FC($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X57FC);
    // 0x800B3C10: mul.s       $f20, $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f20.fl = MUL_S(ctx->f20.fl, ctx->f0.fl);
    // 0x800B3C14: lui         $a2, 0x3CA3
    ctx->r6 = S32(0X3CA3 << 16);
    // 0x800B3C18: ori         $a2, $a2, 0xD70A
    ctx->r6 = ctx->r6 | 0XD70A;
    // 0x800B3C1C: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x800B3C20: jal         0x80073E4C
    // 0x800B3C24: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_80073E4C(rdram, ctx);
        goto after_6;
    // 0x800B3C24: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_6:
L_800B3C28:
    // 0x800B3C28: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
L_800B3C2C:
    // 0x800B3C2C: lw          $v0, 0xB50($v0)
    ctx->r2 = MEM_W(ctx->r2, 0XB50);
    // 0x800B3C30: andi        $v0, $v0, 0x60
    ctx->r2 = ctx->r2 & 0X60;
    // 0x800B3C34: bne         $v0, $zero, L_800B3CA4
    if (ctx->r2 != 0) {
        // 0x800B3C38: lui         $v0, 0x8011
        ctx->r2 = S32(0X8011 << 16);
            goto L_800B3CA4;
    }
    // 0x800B3C38: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800B3C3C: lw          $v1, -0x35E0($v0)
    ctx->r3 = MEM_W(ctx->r2, -0X35E0);
    // 0x800B3C40: bne         $v1, $zero, L_800B3CA4
    if (ctx->r3 != 0) {
        // 0x800B3C44: nop
    
            goto L_800B3CA4;
    }
    // 0x800B3C44: nop

    // 0x800B3C48: lw          $v0, 0x1C4($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X1C4);
    // 0x800B3C4C: slt         $v0, $v1, $v0
    ctx->r2 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800B3C50: beq         $v0, $zero, L_800B3C70
    if (ctx->r2 == 0) {
        // 0x800B3C54: nop
    
            goto L_800B3C70;
    }
    // 0x800B3C54: nop

    // 0x800B3C58: lbu         $a0, 0xBB($s1)
    ctx->r4 = MEM_BU(ctx->r17, 0XBB);
    // 0x800B3C5C: jal         0x80003150
    // 0x800B3C60: nop

    func_80003150(rdram, ctx);
        goto after_7;
    // 0x800B3C60: nop

    after_7:
    // 0x800B3C64: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x800B3C68: bne         $v0, $zero, L_800B3CA4
    if (ctx->r2 != 0) {
        // 0x800B3C6C: nop
    
            goto L_800B3CA4;
    }
    // 0x800B3C6C: nop

L_800B3C70:
    // 0x800B3C70: lw          $a0, 0x1C0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X1C0);
    // 0x800B3C74: addiu       $s0, $zero, -0x1
    ctx->r16 = ADD32(0, -0X1);
    // 0x800B3C78: beql        $a0, $s0, L_800B3C8C
    if (ctx->r4 == ctx->r16) {
        // 0x800B3C7C: lui         $a1, 0x8011
        ctx->r5 = S32(0X8011 << 16);
            goto L_800B3C8C;
    }
    goto skip_0;
    // 0x800B3C7C: lui         $a1, 0x8011
    ctx->r5 = S32(0X8011 << 16);
    skip_0:
    // 0x800B3C80: jal         0x80002BA8
    // 0x800B3C84: nop

    func_80002BA8(rdram, ctx);
        goto after_8;
    // 0x800B3C84: nop

    after_8:
    // 0x800B3C88: lui         $a1, 0x8011
    ctx->r5 = S32(0X8011 << 16);
L_800B3C8C:
    // 0x800B3C8C: lbu         $a0, 0xBB($s1)
    ctx->r4 = MEM_BU(ctx->r17, 0XBB);
    // 0x800B3C90: jal         0x80002ADC
    // 0x800B3C94: addiu       $a1, $a1, -0x4430
    ctx->r5 = ADD32(ctx->r5, -0X4430);
    func_80002ADC(rdram, ctx);
        goto after_9;
    // 0x800B3C94: addiu       $a1, $a1, -0x4430
    ctx->r5 = ADD32(ctx->r5, -0X4430);
    after_9:
    // 0x800B3C98: beq         $v0, $s0, L_800B3CA4
    if (ctx->r2 == ctx->r16) {
        // 0x800B3C9C: sw          $v0, 0x1C0($s1)
        MEM_W(0X1C0, ctx->r17) = ctx->r2;
            goto L_800B3CA4;
    }
    // 0x800B3C9C: sw          $v0, 0x1C0($s1)
    MEM_W(0X1C0, ctx->r17) = ctx->r2;
    // 0x800B3CA0: sw          $zero, 0x1C4($s1)
    MEM_W(0X1C4, ctx->r17) = 0;
L_800B3CA4:
    // 0x800B3CA4: lhu         $v0, 0x6($s3)
    ctx->r2 = MEM_HU(ctx->r19, 0X6);
    // 0x800B3CA8: mtc1        $v0, $f8
    ctx->f8.u32l = ctx->r2;
    // 0x800B3CAC: cvt.s.w     $f8, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    ctx->f8.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800B3CB0: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x800B3CB4: jal         0x800B13E0
    // 0x800B3CB8: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    func_800B13E0(rdram, ctx);
        goto after_10;
    // 0x800B3CB8: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    after_10:
    // 0x800B3CBC: lhu         $v0, 0x6($s3)
    ctx->r2 = MEM_HU(ctx->r19, 0X6);
    // 0x800B3CC0: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800B3CC4: lwc1        $f0, 0x5800($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X5800);
    // 0x800B3CC8: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800B3CCC: lwc1        $f4, 0x5804($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X5804);
    // 0x800B3CD0: mtc1        $v0, $f2
    ctx->f2.u32l = ctx->r2;
    // 0x800B3CD4: cvt.s.w     $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    ctx->f2.fl = CVT_S_W(ctx->f2.u32l);
    // 0x800B3CD8: div.s       $f20, $f2, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f20.fl = DIV_S(ctx->f2.fl, ctx->f0.fl);
    // 0x800B3CDC: c.lt.s      $f4, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f4.fl < ctx->f20.fl;
    // 0x800B3CE0: nop

    // 0x800B3CE4: bc1tl       L_800B3CEC
    if (c1cs) {
        // 0x800B3CE8: mov.s       $f20, $f4
        CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    ctx->f20.fl = ctx->f4.fl;
            goto L_800B3CEC;
    }
    goto skip_1;
    // 0x800B3CE8: mov.s       $f20, $f4
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    ctx->f20.fl = ctx->f4.fl;
    skip_1:
L_800B3CEC:
    // 0x800B3CEC: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x800B3CF0: c.lt.s      $f20, $f6
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f20.fl < ctx->f6.fl;
    // 0x800B3CF4: nop

    // 0x800B3CF8: bc1tl       L_800B3D00
    if (c1cs) {
        // 0x800B3CFC: mov.s       $f20, $f6
        CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    ctx->f20.fl = ctx->f6.fl;
            goto L_800B3D00;
    }
    goto skip_2;
    // 0x800B3CFC: mov.s       $f20, $f6
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    ctx->f20.fl = ctx->f6.fl;
    skip_2:
L_800B3D00:
    // 0x800B3D00: beql        $s2, $zero, L_800B3E08
    if (ctx->r18 == 0) {
        // 0x800B3D04: addu        $a0, $zero, $zero
        ctx->r4 = ADD32(0, 0);
            goto L_800B3E08;
    }
    goto skip_3;
    // 0x800B3D04: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    skip_3:
    // 0x800B3D08: lwc1        $f0, 0x4($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X4);
    // 0x800B3D0C: lwc1        $f2, 0x0($s2)
    ctx->f2.u32l = MEM_W(ctx->r18, 0X0);
    // 0x800B3D10: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x800B3D14: swc1        $f0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f0.u32l;
    // 0x800B3D18: lwc1        $f2, 0x8($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0X8);
    // 0x800B3D1C: lwc1        $f0, 0x4($s2)
    ctx->f0.u32l = MEM_W(ctx->r18, 0X4);
    // 0x800B3D20: sub.s       $f4, $f2, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f2.fl - ctx->f0.fl;
    // 0x800B3D24: swc1        $f4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f4.u32l;
    // 0x800B3D28: lwc1        $f0, 0xC($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0XC);
    // 0x800B3D2C: lwc1        $f2, 0x8($s2)
    ctx->f2.u32l = MEM_W(ctx->r18, 0X8);
    // 0x800B3D30: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x800B3D34: c.lt.s      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.fl < ctx->f4.fl;
    // 0x800B3D38: nop

    // 0x800B3D3C: bc1f        L_800B3D58
    if (!c1cs) {
        // 0x800B3D40: swc1        $f0, 0x30($sp)
        MEM_W(0X30, ctx->r29) = ctx->f0.u32l;
            goto L_800B3D58;
    }
    // 0x800B3D40: swc1        $f0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f0.u32l;
    // 0x800B3D44: lwc1        $f0, 0x20($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X20);
    // 0x800B3D48: c.lt.s      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.fl < ctx->f0.fl;
    // 0x800B3D4C: nop

    // 0x800B3D50: bc1t        L_800B3D7C
    if (c1cs) {
        // 0x800B3D54: nop
    
            goto L_800B3D7C;
    }
    // 0x800B3D54: nop

L_800B3D58:
    // 0x800B3D58: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x800B3D5C: nop

    // 0x800B3D60: bc1f        L_800B3D90
    if (!c1cs) {
        // 0x800B3D64: nop
    
            goto L_800B3D90;
    }
    // 0x800B3D64: nop

    // 0x800B3D68: lwc1        $f0, 0x20($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X20);
    // 0x800B3D6C: c.lt.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl < ctx->f6.fl;
    // 0x800B3D70: nop

    // 0x800B3D74: bc1f        L_800B3D90
    if (!c1cs) {
        // 0x800B3D78: nop
    
            goto L_800B3D90;
    }
    // 0x800B3D78: nop

L_800B3D7C:
    // 0x800B3D7C: lwc1        $f2, 0x148($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0X148);
    // 0x800B3D80: mul.s       $f2, $f2, $f20
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f20.fl);
    // 0x800B3D84: lwc1        $f0, 0x14C($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X14C);
    // 0x800B3D88: j           L_800B3DA0
    // 0x800B3D8C: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
        goto L_800B3DA0;
    // 0x800B3D8C: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
L_800B3D90:
    // 0x800B3D90: lwc1        $f2, 0x148($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0X148);
    // 0x800B3D94: mul.s       $f2, $f2, $f20
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f20.fl);
    // 0x800B3D98: lwc1        $f0, 0x14C($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X14C);
    // 0x800B3D9C: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
L_800B3DA0:
    // 0x800B3DA0: swc1        $f0, 0x14C($s1)
    MEM_W(0X14C, ctx->r17) = ctx->f0.u32l;
    // 0x800B3DA4: jal         0x800AA350
    // 0x800B3DA8: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    func_800AA350(rdram, ctx);
        goto after_11;
    // 0x800B3DA8: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    after_11:
    // 0x800B3DAC: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    // 0x800B3DB0: jal         0x8001CFE8
    // 0x800B3DB4: addiu       $a1, $s1, 0x10
    ctx->r5 = ADD32(ctx->r17, 0X10);
    func_8001CFE8(rdram, ctx);
        goto after_12;
    // 0x800B3DB4: addiu       $a1, $s1, 0x10
    ctx->r5 = ADD32(ctx->r17, 0X10);
    after_12:
    // 0x800B3DB8: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x800B3DBC: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x800B3DC0: nop

    // 0x800B3DC4: bc1f        L_800B3DE0
    if (!c1cs) {
        // 0x800B3DC8: nop
    
            goto L_800B3DE0;
    }
    // 0x800B3DC8: nop

    // 0x800B3DCC: lwc1        $f2, 0x138($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0X138);
    // 0x800B3DD0: mul.s       $f2, $f2, $f20
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f20.fl);
    // 0x800B3DD4: lwc1        $f0, 0x13C($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X13C);
    // 0x800B3DD8: j           L_800B3DF0
    // 0x800B3DDC: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
        goto L_800B3DF0;
    // 0x800B3DDC: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
L_800B3DE0:
    // 0x800B3DE0: lwc1        $f2, 0x138($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0X138);
    // 0x800B3DE4: mul.s       $f2, $f2, $f20
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f20.fl);
    // 0x800B3DE8: lwc1        $f0, 0x13C($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X13C);
    // 0x800B3DEC: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
L_800B3DF0:
    // 0x800B3DF0: swc1        $f0, 0x13C($s1)
    MEM_W(0X13C, ctx->r17) = ctx->f0.u32l;
    // 0x800B3DF4: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x800B3DF8: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x800B3DFC: jal         0x800C6FFC
    // 0x800B3E00: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    func_800C6FFC(rdram, ctx);
        goto after_13;
    // 0x800B3E00: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    after_13:
    // 0x800B3E04: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
L_800B3E08:
    // 0x800B3E08: jal         0x800EFD64
    // 0x800B3E0C: addu        $a1, $a0, $zero
    ctx->r5 = ADD32(ctx->r4, 0);
    func_800EFD64(rdram, ctx);
        goto after_14;
    // 0x800B3E0C: addu        $a1, $a0, $zero
    ctx->r5 = ADD32(ctx->r4, 0);
    after_14:
    // 0x800B3E10: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    // 0x800B3E14: addiu       $a2, $sp, 0x38
    ctx->r6 = ADD32(ctx->r29, 0X38);
    // 0x800B3E18: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x800B3E1C: lhu         $a0, -0x6A82($v0)
    ctx->r4 = MEM_HU(ctx->r2, -0X6A82);
    // 0x800B3E20: addiu       $v0, $zero, 0xB
    ctx->r2 = ADD32(0, 0XB);
    // 0x800B3E24: jal         0x8003E8DC
    // 0x800B3E28: sb          $v0, 0x50($sp)
    MEM_B(0X50, ctx->r29) = ctx->r2;
    func_8003E8DC(rdram, ctx);
        goto after_15;
    // 0x800B3E28: sb          $v0, 0x50($sp)
    MEM_B(0X50, ctx->r29) = ctx->r2;
    after_15:
L_800B3E2C:
    // 0x800B3E2C: lw          $ra, 0x78($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X78);
    // 0x800B3E30: lw          $s3, 0x74($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X74);
    // 0x800B3E34: lw          $s2, 0x70($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X70);
    // 0x800B3E38: lw          $s1, 0x6C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X6C);
    // 0x800B3E3C: lw          $s0, 0x68($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X68);
    // 0x800B3E40: ldc1        $f20, 0x80($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X80);
    // 0x800B3E44: jr          $ra
    // 0x800B3E48: addiu       $sp, $sp, 0x88
    ctx->r29 = ADD32(ctx->r29, 0X88);
    return;
    // 0x800B3E48: addiu       $sp, $sp, 0x88
    ctx->r29 = ADD32(ctx->r29, 0X88);
;}
RECOMP_FUNC void func_800B3AFC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B3AFC: addiu       $sp, $sp, -0xA0
    ctx->r29 = ADD32(ctx->r29, -0XA0);
    // 0x800B3B00: sw          $s3, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->r19;
    // 0x800B3B04: addu        $s3, $a0, $zero
    ctx->r19 = ADD32(ctx->r4, 0);
    // 0x800B3B08: addu        $a0, $a1, $zero
    ctx->r4 = ADD32(ctx->r5, 0);
    // 0x800B3B0C: sw          $s0, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r16;
    // 0x800B3B10: sll         $s0, $a2, 16
    ctx->r16 = S32(ctx->r6 << 16);
    // 0x800B3B14: sra         $s0, $s0, 16
    ctx->r16 = S32(SIGNED(ctx->r16) >> 16);
    // 0x800B3B18: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x800B3B1C: sw          $s1, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->r17;
    // 0x800B3B20: sll         $s1, $a3, 16
    ctx->r17 = S32(ctx->r7 << 16);
    // 0x800B3B24: lw          $a3, 0xB0($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XB0);
    // 0x800B3B28: sra         $s1, $s1, 16
    ctx->r17 = S32(SIGNED(ctx->r17) >> 16);
    // 0x800B3B2C: sw          $s2, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->r18;
    // 0x800B3B30: lw          $s2, 0xB4($sp)
    ctx->r18 = MEM_W(ctx->r29, 0XB4);
    // 0x800B3B34: addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    // 0x800B3B38: sw          $ra, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->r31;
    // 0x800B3B3C: jal         0x800B42D4
    // 0x800B3B40: sw          $s4, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->r20;
    func_800B42D4(rdram, ctx);
        goto after_0;
    // 0x800B3B40: sw          $s4, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->r20;
    after_0:
    // 0x800B3B44: addu        $s4, $v0, $zero
    ctx->r20 = ADD32(ctx->r2, 0);
    // 0x800B3B48: addu        $a0, $s4, $zero
    ctx->r4 = ADD32(ctx->r20, 0);
    // 0x800B3B4C: addiu       $a1, $sp, 0x10
    ctx->r5 = ADD32(ctx->r29, 0X10);
    // 0x800B3B50: addu        $a2, $s3, $zero
    ctx->r6 = ADD32(ctx->r19, 0);
    // 0x800B3B54: jal         0x800B2630
    // 0x800B3B58: addu        $a3, $s2, $zero
    ctx->r7 = ADD32(ctx->r18, 0);
    func_800B2630(rdram, ctx);
        goto after_1;
    // 0x800B3B58: addu        $a3, $s2, $zero
    ctx->r7 = ADD32(ctx->r18, 0);
    after_1:
    // 0x800B3B5C: addu        $a0, $s4, $zero
    ctx->r4 = ADD32(ctx->r20, 0);
    // 0x800B3B60: lhu         $a2, 0xA($s4)
    ctx->r6 = MEM_HU(ctx->r20, 0XA);
    // 0x800B3B64: jal         0x800B3D14
    // 0x800B3B68: addiu       $a1, $sp, 0x10
    ctx->r5 = ADD32(ctx->r29, 0X10);
    func_800B3D14(rdram, ctx);
        goto after_2;
    // 0x800B3B68: addiu       $a1, $sp, 0x10
    ctx->r5 = ADD32(ctx->r29, 0X10);
    after_2:
    // 0x800B3B6C: lw          $v0, 0x7C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X7C);
    // 0x800B3B70: lhu         $v0, 0x3C($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X3C);
    // 0x800B3B74: div         $zero, $v0, $s0
    lo = S32(S64(S32(ctx->r2)) / S64(S32(ctx->r16))); hi = S32(S64(S32(ctx->r2)) % S64(S32(ctx->r16)));
    // 0x800B3B78: bne         $s0, $zero, L_800B3B84
    if (ctx->r16 != 0) {
        // 0x800B3B7C: nop
    
            goto L_800B3B84;
    }
    // 0x800B3B7C: nop

    // 0x800B3B80: break       7
    do_break(2148219776);
L_800B3B84:
    // 0x800B3B84: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800B3B88: bne         $s0, $at, L_800B3B9C
    if (ctx->r16 != ctx->r1) {
        // 0x800B3B8C: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800B3B9C;
    }
    // 0x800B3B8C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800B3B90: bne         $v0, $at, L_800B3B9C
    if (ctx->r2 != ctx->r1) {
        // 0x800B3B94: nop
    
            goto L_800B3B9C;
    }
    // 0x800B3B94: nop

    // 0x800B3B98: break       6
    do_break(2148219800);
L_800B3B9C:
    // 0x800B3B9C: mflo        $v0
    ctx->r2 = lo;
    // 0x800B3BA0: lw          $a2, 0xC($s4)
    ctx->r6 = MEM_W(ctx->r20, 0XC);
    // 0x800B3BA4: sh          $v0, 0x8($a2)
    MEM_H(0X8, ctx->r6) = ctx->r2;
    // 0x800B3BA8: lw          $v0, 0x7C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X7C);
    // 0x800B3BAC: lhu         $v1, 0x3E($v0)
    ctx->r3 = MEM_HU(ctx->r2, 0X3E);
    // 0x800B3BB0: div         $zero, $v1, $s1
    lo = S32(S64(S32(ctx->r3)) / S64(S32(ctx->r17))); hi = S32(S64(S32(ctx->r3)) % S64(S32(ctx->r17)));
    // 0x800B3BB4: bne         $s1, $zero, L_800B3BC0
    if (ctx->r17 != 0) {
        // 0x800B3BB8: nop
    
            goto L_800B3BC0;
    }
    // 0x800B3BB8: nop

    // 0x800B3BBC: break       7
    do_break(2148219836);
L_800B3BC0:
    // 0x800B3BC0: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800B3BC4: bne         $s1, $at, L_800B3BD8
    if (ctx->r17 != ctx->r1) {
        // 0x800B3BC8: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800B3BD8;
    }
    // 0x800B3BC8: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800B3BCC: bne         $v1, $at, L_800B3BD8
    if (ctx->r3 != ctx->r1) {
        // 0x800B3BD0: nop
    
            goto L_800B3BD8;
    }
    // 0x800B3BD0: nop

    // 0x800B3BD4: break       6
    do_break(2148219860);
L_800B3BD8:
    // 0x800B3BD8: mflo        $v1
    ctx->r3 = lo;
    // 0x800B3BDC: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800B3BE0: lwc1        $f0, 0x5D8C($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X5D8C);
    // 0x800B3BE4: swc1        $f0, 0x24($a2)
    MEM_W(0X24, ctx->r6) = ctx->f0.u32l;
    // 0x800B3BE8: swc1        $f0, 0x28($a2)
    MEM_W(0X28, ctx->r6) = ctx->f0.u32l;
    // 0x800B3BEC: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // 0x800B3BF0: sb          $v0, 0x2C($a2)
    MEM_B(0X2C, ctx->r6) = ctx->r2;
    // 0x800B3BF4: sb          $v0, 0x2D($a2)
    MEM_B(0X2D, ctx->r6) = ctx->r2;
    // 0x800B3BF8: sb          $v0, 0x2E($a2)
    MEM_B(0X2E, ctx->r6) = ctx->r2;
    // 0x800B3BFC: sb          $v0, 0x2F($a2)
    MEM_B(0X2F, ctx->r6) = ctx->r2;
    // 0x800B3C00: sh          $v1, 0xA($a2)
    MEM_H(0XA, ctx->r6) = ctx->r3;
    // 0x800B3C04: lw          $v0, 0x8($s4)
    ctx->r2 = MEM_W(ctx->r20, 0X8);
    // 0x800B3C08: beq         $v0, $zero, L_800B3C40
    if (ctx->r2 == 0) {
        // 0x800B3C0C: addu        $a1, $zero, $zero
        ctx->r5 = ADD32(0, 0);
            goto L_800B3C40;
    }
    // 0x800B3C0C: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x800B3C10: sll         $v1, $a1, 1
    ctx->r3 = S32(ctx->r5 << 1);
L_800B3C14:
    // 0x800B3C14: lw          $v0, 0x14($s4)
    ctx->r2 = MEM_W(ctx->r20, 0X14);
    // 0x800B3C18: lw          $a0, 0xC($a2)
    ctx->r4 = MEM_W(ctx->r6, 0XC);
    // 0x800B3C1C: addu        $v0, $v1, $v0
    ctx->r2 = ADD32(ctx->r3, ctx->r2);
    // 0x800B3C20: lhu         $v0, 0x0($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X0);
    // 0x800B3C24: addu        $v1, $v1, $a0
    ctx->r3 = ADD32(ctx->r3, ctx->r4);
    // 0x800B3C28: sh          $v0, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r2;
    // 0x800B3C2C: lw          $v0, 0x8($s4)
    ctx->r2 = MEM_W(ctx->r20, 0X8);
    // 0x800B3C30: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x800B3C34: sltu        $v0, $a1, $v0
    ctx->r2 = ctx->r5 < ctx->r2 ? 1 : 0;
    // 0x800B3C38: bne         $v0, $zero, L_800B3C14
    if (ctx->r2 != 0) {
        // 0x800B3C3C: sll         $v1, $a1, 1
        ctx->r3 = S32(ctx->r5 << 1);
            goto L_800B3C14;
    }
    // 0x800B3C3C: sll         $v1, $a1, 1
    ctx->r3 = S32(ctx->r5 << 1);
L_800B3C40:
    // 0x800B3C40: addu        $a0, $s4, $zero
    ctx->r4 = ADD32(ctx->r20, 0);
    // 0x800B3C44: jal         0x800B3E5C
    // 0x800B3C48: addiu       $a1, $sp, 0x10
    ctx->r5 = ADD32(ctx->r29, 0X10);
    func_800B3E5C(rdram, ctx);
        goto after_3;
    // 0x800B3C48: addiu       $a1, $sp, 0x10
    ctx->r5 = ADD32(ctx->r29, 0X10);
    after_3:
    // 0x800B3C4C: addu        $v0, $s4, $zero
    ctx->r2 = ADD32(ctx->r20, 0);
    // 0x800B3C50: lw          $ra, 0x9C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X9C);
    // 0x800B3C54: lw          $s4, 0x98($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X98);
    // 0x800B3C58: lw          $s3, 0x94($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X94);
    // 0x800B3C5C: lw          $s2, 0x90($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X90);
    // 0x800B3C60: lw          $s1, 0x8C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X8C);
    // 0x800B3C64: lw          $s0, 0x88($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X88);
    // 0x800B3C68: jr          $ra
    // 0x800B3C6C: addiu       $sp, $sp, 0xA0
    ctx->r29 = ADD32(ctx->r29, 0XA0);
    return;
    // 0x800B3C6C: addiu       $sp, $sp, 0xA0
    ctx->r29 = ADD32(ctx->r29, 0XA0);
;}
RECOMP_FUNC void func_800B3C70(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B3C70: addiu       $sp, $sp, -0x90
    ctx->r29 = ADD32(ctx->r29, -0X90);
    // 0x800B3C74: sw          $s0, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r16;
    // 0x800B3C78: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x800B3C7C: addu        $v0, $a1, $zero
    ctx->r2 = ADD32(ctx->r5, 0);
    // 0x800B3C80: addu        $a3, $a2, $zero
    ctx->r7 = ADD32(ctx->r6, 0);
    // 0x800B3C84: addiu       $a1, $sp, 0x10
    ctx->r5 = ADD32(ctx->r29, 0X10);
    // 0x800B3C88: sw          $ra, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->r31;
    // 0x800B3C8C: jal         0x800B2630
    // 0x800B3C90: addu        $a2, $v0, $zero
    ctx->r6 = ADD32(ctx->r2, 0);
    func_800B2630(rdram, ctx);
        goto after_0;
    // 0x800B3C90: addu        $a2, $v0, $zero
    ctx->r6 = ADD32(ctx->r2, 0);
    after_0:
    // 0x800B3C94: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x800B3C98: lhu         $a2, 0xA($s0)
    ctx->r6 = MEM_HU(ctx->r16, 0XA);
    // 0x800B3C9C: jal         0x800B3D14
    // 0x800B3CA0: addiu       $a1, $sp, 0x10
    ctx->r5 = ADD32(ctx->r29, 0X10);
    func_800B3D14(rdram, ctx);
        goto after_1;
    // 0x800B3CA0: addiu       $a1, $sp, 0x10
    ctx->r5 = ADD32(ctx->r29, 0X10);
    after_1:
    // 0x800B3CA4: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x800B3CA8: jal         0x800B3E5C
    // 0x800B3CAC: addiu       $a1, $sp, 0x10
    ctx->r5 = ADD32(ctx->r29, 0X10);
    func_800B3E5C(rdram, ctx);
        goto after_2;
    // 0x800B3CAC: addiu       $a1, $sp, 0x10
    ctx->r5 = ADD32(ctx->r29, 0X10);
    after_2:
    // 0x800B3CB0: lw          $ra, 0x8C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X8C);
    // 0x800B3CB4: lw          $s0, 0x88($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X88);
    // 0x800B3CB8: jr          $ra
    // 0x800B3CBC: addiu       $sp, $sp, 0x90
    ctx->r29 = ADD32(ctx->r29, 0X90);
    return;
    // 0x800B3CBC: addiu       $sp, $sp, 0x90
    ctx->r29 = ADD32(ctx->r29, 0X90);
;}
RECOMP_FUNC void func_800B3CC0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B3CC0: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x800B3CC4: lbu         $v0, -0x37B0($v1)
    ctx->r2 = MEM_BU(ctx->r3, -0X37B0);
    // 0x800B3CC8: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x800B3CCC: jr          $ra
    // 0x800B3CD0: sb          $v0, -0x37B0($v1)
    MEM_B(-0X37B0, ctx->r3) = ctx->r2;
    return;
    // 0x800B3CD0: sb          $v0, -0x37B0($v1)
    MEM_B(-0X37B0, ctx->r3) = ctx->r2;
;}
RECOMP_FUNC void func_800B3CD4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B3CD4: sll         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5 << 16);
    // 0x800B3CD8: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
    // 0x800B3CDC: mtc1        $a1, $f0
    ctx->f0.u32l = ctx->r5;
    // 0x800B3CE0: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x800B3CE4: sll         $a2, $a2, 16
    ctx->r6 = S32(ctx->r6 << 16);
    // 0x800B3CE8: lw          $v0, 0xC($a0)
    ctx->r2 = MEM_W(ctx->r4, 0XC);
    // 0x800B3CEC: sra         $a2, $a2, 16
    ctx->r6 = S32(SIGNED(ctx->r6) >> 16);
    // 0x800B3CF0: swc1        $f0, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->f0.u32l;
    // 0x800B3CF4: lw          $v0, 0xC($a0)
    ctx->r2 = MEM_W(ctx->r4, 0XC);
    // 0x800B3CF8: mtc1        $a2, $f0
    ctx->f0.u32l = ctx->r6;
    // 0x800B3CFC: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x800B3D00: jr          $ra
    // 0x800B3D04: swc1        $f0, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->f0.u32l;
    return;
    // 0x800B3D04: swc1        $f0, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->f0.u32l;
;}
RECOMP_FUNC void func_800B3D08(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B3D08: lw          $v0, 0xC($a0)
    ctx->r2 = MEM_W(ctx->r4, 0XC);
    // 0x800B3D0C: jr          $ra
    // 0x800B3D10: nop

    return;
    // 0x800B3D10: nop

;}
RECOMP_FUNC void func_800B3D14(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B3D14: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800B3D18: sw          $s3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r19;
    // 0x800B3D1C: addu        $s3, $a0, $zero
    ctx->r19 = ADD32(ctx->r4, 0);
    // 0x800B3D20: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x800B3D24: addu        $s1, $a1, $zero
    ctx->r17 = ADD32(ctx->r5, 0);
    // 0x800B3D28: sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // 0x800B3D2C: addu        $s2, $zero, $zero
    ctx->r18 = ADD32(0, 0);
    // 0x800B3D30: sw          $s4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r20;
    // 0x800B3D34: addu        $s4, $a2, $zero
    ctx->r20 = ADD32(ctx->r6, 0);
    // 0x800B3D38: andi        $v0, $s4, 0xFFFF
    ctx->r2 = ctx->r20 & 0XFFFF;
    // 0x800B3D3C: sw          $ra, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r31;
    // 0x800B3D40: sw          $s5, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r21;
    // 0x800B3D44: beq         $v0, $zero, L_800B3E38
    if (ctx->r2 == 0) {
        // 0x800B3D48: sw          $s0, 0x10($sp)
        MEM_W(0X10, ctx->r29) = ctx->r16;
            goto L_800B3E38;
    }
    // 0x800B3D48: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x800B3D4C: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x800B3D50: addiu       $s5, $v0, 0x5C40
    ctx->r21 = ADD32(ctx->r2, 0X5C40);
    // 0x800B3D54: addiu       $a0, $s1, 0x2A
    ctx->r4 = ADD32(ctx->r17, 0X2A);
L_800B3D58:
    // 0x800B3D58: lw          $a2, 0x10($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X10);
    // 0x800B3D5C: jal         0x80033CC4
    // 0x800B3D60: addu        $a1, $s5, $zero
    ctx->r5 = ADD32(ctx->r21, 0);
    sprintf_recomp(rdram, ctx);
        goto after_0;
    // 0x800B3D60: addu        $a1, $s5, $zero
    ctx->r5 = ADD32(ctx->r21, 0);
    after_0:
    // 0x800B3D64: addu        $a1, $s5, $zero
    ctx->r5 = ADD32(ctx->r21, 0);
    // 0x800B3D68: lw          $a0, 0x5C($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X5C);
    // 0x800B3D6C: lw          $a2, 0x10($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X10);
    // 0x800B3D70: jal         0x80033CC4
    // 0x800B3D74: addiu       $a0, $a0, 0x2
    ctx->r4 = ADD32(ctx->r4, 0X2);
    sprintf_recomp(rdram, ctx);
        goto after_1;
    // 0x800B3D74: addiu       $a0, $a0, 0x2
    ctx->r4 = ADD32(ctx->r4, 0X2);
    after_1:
    // 0x800B3D78: lw          $a0, 0x6C($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X6C);
    // 0x800B3D7C: lw          $a1, 0x38($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X38);
    // 0x800B3D80: jal         0x800C8C1C
    // 0x800B3D84: nop

    func_800C8C1C(rdram, ctx);
        goto after_2;
    // 0x800B3D84: nop

    after_2:
    // 0x800B3D88: lw          $v0, 0x1C($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X1C);
    // 0x800B3D8C: andi        $v0, $v0, 0x6
    ctx->r2 = ctx->r2 & 0X6;
    // 0x800B3D90: beq         $v0, $zero, L_800B3DA8
    if (ctx->r2 == 0) {
        // 0x800B3D94: nop
    
            goto L_800B3DA8;
    }
    // 0x800B3D94: nop

    // 0x800B3D98: lw          $a0, 0x70($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X70);
    // 0x800B3D9C: lw          $a1, 0x3C($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X3C);
    // 0x800B3DA0: jal         0x800C8C1C
    // 0x800B3DA4: nop

    func_800C8C1C(rdram, ctx);
        goto after_3;
    // 0x800B3DA4: nop

    after_3:
L_800B3DA8:
    // 0x800B3DA8: lw          $v0, 0x10($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X10);
    // 0x800B3DAC: lw          $v1, 0x14($s3)
    ctx->r3 = MEM_W(ctx->r19, 0X14);
    // 0x800B3DB0: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x800B3DB4: addu        $s0, $v0, $v1
    ctx->r16 = ADD32(ctx->r2, ctx->r3);
    // 0x800B3DB8: lhu         $v1, 0x0($s0)
    ctx->r3 = MEM_HU(ctx->r16, 0X0);
    // 0x800B3DBC: ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
    // 0x800B3DC0: bne         $v1, $v0, L_800B3DE0
    if (ctx->r3 != ctx->r2) {
        // 0x800B3DC4: addiu       $a1, $s1, 0x14
        ctx->r5 = ADD32(ctx->r17, 0X14);
            goto L_800B3DE0;
    }
    // 0x800B3DC4: addiu       $a1, $s1, 0x14
    ctx->r5 = ADD32(ctx->r17, 0X14);
    // 0x800B3DC8: addiu       $a0, $s1, 0x14
    ctx->r4 = ADD32(ctx->r17, 0X14);
    // 0x800B3DCC: addiu       $a1, $s1, 0x38
    ctx->r5 = ADD32(ctx->r17, 0X38);
    // 0x800B3DD0: jal         0x80022B90
    // 0x800B3DD4: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    func_80022B90(rdram, ctx);
        goto after_4;
    // 0x800B3DD4: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    after_4:
    // 0x800B3DD8: j           L_800B3DF4
    // 0x800B3DDC: sh          $v0, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r2;
        goto L_800B3DF4;
    // 0x800B3DDC: sh          $v0, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r2;
L_800B3DE0:
    // 0x800B3DE0: lhu         $a0, 0x0($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X0);
    // 0x800B3DE4: addiu       $a2, $s1, 0x38
    ctx->r6 = ADD32(ctx->r17, 0X38);
    // 0x800B3DE8: jal         0x80022C00
    // 0x800B3DEC: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    func_80022C00(rdram, ctx);
        goto after_5;
    // 0x800B3DEC: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    after_5:
    // 0x800B3DF0: sh          $v0, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r2;
L_800B3DF4:
    // 0x800B3DF4: lw          $v1, 0x10($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X10);
    // 0x800B3DF8: lw          $v0, 0x14($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X14);
    // 0x800B3DFC: lw          $a0, 0xC($s3)
    ctx->r4 = MEM_W(ctx->r19, 0XC);
    // 0x800B3E00: sll         $v1, $v1, 1
    ctx->r3 = S32(ctx->r3 << 1);
    // 0x800B3E04: addu        $v0, $v1, $v0
    ctx->r2 = ADD32(ctx->r3, ctx->r2);
    // 0x800B3E08: lw          $a0, 0xC($a0)
    ctx->r4 = MEM_W(ctx->r4, 0XC);
    // 0x800B3E0C: lhu         $v0, 0x0($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X0);
    // 0x800B3E10: addu        $v1, $v1, $a0
    ctx->r3 = ADD32(ctx->r3, ctx->r4);
    // 0x800B3E14: sh          $v0, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r2;
    // 0x800B3E18: lw          $v0, 0x10($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X10);
    // 0x800B3E1C: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x800B3E20: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800B3E24: sw          $v0, 0x10($s1)
    MEM_W(0X10, ctx->r17) = ctx->r2;
    // 0x800B3E28: andi        $v0, $s4, 0xFFFF
    ctx->r2 = ctx->r20 & 0XFFFF;
    // 0x800B3E2C: sltu        $v0, $s2, $v0
    ctx->r2 = ctx->r18 < ctx->r2 ? 1 : 0;
    // 0x800B3E30: bne         $v0, $zero, L_800B3D58
    if (ctx->r2 != 0) {
        // 0x800B3E34: addiu       $a0, $s1, 0x2A
        ctx->r4 = ADD32(ctx->r17, 0X2A);
            goto L_800B3D58;
    }
    // 0x800B3E34: addiu       $a0, $s1, 0x2A
    ctx->r4 = ADD32(ctx->r17, 0X2A);
L_800B3E38:
    // 0x800B3E38: lw          $ra, 0x28($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X28);
    // 0x800B3E3C: lw          $s5, 0x24($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X24);
    // 0x800B3E40: lw          $s4, 0x20($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X20);
    // 0x800B3E44: lw          $s3, 0x1C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X1C);
    // 0x800B3E48: lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X18);
    // 0x800B3E4C: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x800B3E50: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x800B3E54: jr          $ra
    // 0x800B3E58: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x800B3E58: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_800B3E4C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B3E4C: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800B3E50: lw          $v0, 0xB50($v0)
    ctx->r2 = MEM_W(ctx->r2, 0XB50);
    // 0x800B3E54: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800B3E58: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x800B3E5C: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x800B3E60: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x800B3E64: addu        $s1, $a1, $zero
    ctx->r17 = ADD32(ctx->r5, 0);
    // 0x800B3E68: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800B3E6C: andi        $v0, $v0, 0x60
    ctx->r2 = ctx->r2 & 0X60;
    // 0x800B3E70: bne         $v0, $zero, L_800B3EF4
    if (ctx->r2 != 0) {
        // 0x800B3E74: sw          $s2, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r18;
            goto L_800B3EF4;
    }
    // 0x800B3E74: sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // 0x800B3E78: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800B3E7C: lw          $v0, -0x35E0($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X35E0);
    // 0x800B3E80: bne         $v0, $zero, L_800B3EF4
    if (ctx->r2 != 0) {
        // 0x800B3E84: nop
    
            goto L_800B3EF4;
    }
    // 0x800B3E84: nop

    // 0x800B3E88: lw          $v0, 0x1C4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1C4);
    // 0x800B3E8C: slt         $v0, $s1, $v0
    ctx->r2 = SIGNED(ctx->r17) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800B3E90: beq         $v0, $zero, L_800B3EB0
    if (ctx->r2 == 0) {
        // 0x800B3E94: nop
    
            goto L_800B3EB0;
    }
    // 0x800B3E94: nop

    // 0x800B3E98: lbu         $a0, 0xBB($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0XBB);
    // 0x800B3E9C: jal         0x80003150
    // 0x800B3EA0: nop

    func_80003150(rdram, ctx);
        goto after_0;
    // 0x800B3EA0: nop

    after_0:
    // 0x800B3EA4: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x800B3EA8: bne         $v0, $zero, L_800B3EF4
    if (ctx->r2 != 0) {
        // 0x800B3EAC: nop
    
            goto L_800B3EF4;
    }
    // 0x800B3EAC: nop

L_800B3EB0:
    // 0x800B3EB0: lw          $a0, 0x1C0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X1C0);
    // 0x800B3EB4: addiu       $s2, $zero, -0x1
    ctx->r18 = ADD32(0, -0X1);
    // 0x800B3EB8: beq         $a0, $s2, L_800B3ECC
    if (ctx->r4 == ctx->r18) {
        // 0x800B3EBC: sll         $v0, $s1, 1
        ctx->r2 = S32(ctx->r17 << 1);
            goto L_800B3ECC;
    }
    // 0x800B3EBC: sll         $v0, $s1, 1
    ctx->r2 = S32(ctx->r17 << 1);
    // 0x800B3EC0: jal         0x80002BA8
    // 0x800B3EC4: nop

    func_80002BA8(rdram, ctx);
        goto after_1;
    // 0x800B3EC4: nop

    after_1:
    // 0x800B3EC8: sll         $v0, $s1, 1
    ctx->r2 = S32(ctx->r17 << 1);
L_800B3ECC:
    // 0x800B3ECC: addu        $v0, $v0, $s1
    ctx->r2 = ADD32(ctx->r2, ctx->r17);
    // 0x800B3ED0: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800B3ED4: lui         $a1, 0x8011
    ctx->r5 = S32(0X8011 << 16);
    // 0x800B3ED8: addiu       $a1, $a1, -0x4430
    ctx->r5 = ADD32(ctx->r5, -0X4430);
    // 0x800B3EDC: lbu         $a0, 0xBB($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0XBB);
    // 0x800B3EE0: jal         0x80002ADC
    // 0x800B3EE4: addu        $a1, $v0, $a1
    ctx->r5 = ADD32(ctx->r2, ctx->r5);
    func_80002ADC(rdram, ctx);
        goto after_2;
    // 0x800B3EE4: addu        $a1, $v0, $a1
    ctx->r5 = ADD32(ctx->r2, ctx->r5);
    after_2:
    // 0x800B3EE8: beq         $v0, $s2, L_800B3EF4
    if (ctx->r2 == ctx->r18) {
        // 0x800B3EEC: sw          $v0, 0x1C0($s0)
        MEM_W(0X1C0, ctx->r16) = ctx->r2;
            goto L_800B3EF4;
    }
    // 0x800B3EEC: sw          $v0, 0x1C0($s0)
    MEM_W(0X1C0, ctx->r16) = ctx->r2;
    // 0x800B3EF0: sw          $s1, 0x1C4($s0)
    MEM_W(0X1C4, ctx->r16) = ctx->r17;
L_800B3EF4:
    // 0x800B3EF4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800B3EF8: lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X18);
    // 0x800B3EFC: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x800B3F00: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x800B3F04: jr          $ra
    // 0x800B3F08: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x800B3F08: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_800B3E5C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B3E5C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800B3E60: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800B3E64: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x800B3E68: lw          $v0, 0x1C($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1C);
    // 0x800B3E6C: andi        $v0, $v0, 0x6
    ctx->r2 = ctx->r2 & 0X6;
    // 0x800B3E70: beq         $v0, $zero, L_800B3E90
    if (ctx->r2 == 0) {
        // 0x800B3E74: addu        $s0, $a1, $zero
        ctx->r16 = ADD32(ctx->r5, 0);
            goto L_800B3E90;
    }
    // 0x800B3E74: addu        $s0, $a1, $zero
    ctx->r16 = ADD32(ctx->r5, 0);
    // 0x800B3E78: lw          $a0, 0x3C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X3C);
    // 0x800B3E7C: jal         0x80001C98
    // 0x800B3E80: nop

    rs_free(rdram, ctx);
        goto after_0;
    // 0x800B3E80: nop

    after_0:
    // 0x800B3E84: lw          $a0, 0x70($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X70);
    // 0x800B3E88: jal         0x800C6DBC
    // 0x800B3E8C: nop

    func_800C6DBC(rdram, ctx);
        goto after_1;
    // 0x800B3E8C: nop

    after_1:
L_800B3E90:
    // 0x800B3E90: lw          $a0, 0x38($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X38);
    // 0x800B3E94: jal         0x80001C98
    // 0x800B3E98: nop

    rs_free(rdram, ctx);
        goto after_2;
    // 0x800B3E98: nop

    after_2:
    // 0x800B3E9C: lw          $a0, 0x6C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X6C);
    // 0x800B3EA0: jal         0x800C6DBC
    // 0x800B3EA4: nop

    func_800C6DBC(rdram, ctx);
        goto after_3;
    // 0x800B3EA4: nop

    after_3:
    // 0x800B3EA8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800B3EAC: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x800B3EB0: jr          $ra
    // 0x800B3EB4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x800B3EB4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_800B3EB8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B3EB8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800B3EBC: andi        $a2, $a0, 0xFF
    ctx->r6 = ctx->r4 & 0XFF;
    // 0x800B3EC0: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    // 0x800B3EC4: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x800B3EC8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800B3ECC: lui         $a3, 0x800B
    ctx->r7 = S32(0X800B << 16);
    // 0x800B3ED0: addiu       $a1, $zero, 0x800
    ctx->r5 = ADD32(0, 0X800);
    // 0x800B3ED4: addiu       $a3, $a3, 0x3650
    ctx->r7 = ADD32(ctx->r7, 0X3650);
    // 0x800B3ED8: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x800B3EDC: jal         0x80006C28
    // 0x800B3EE0: sw          $v0, -0x37AC($v1)
    MEM_W(-0X37AC, ctx->r3) = ctx->r2;
    func_80006C28(rdram, ctx);
        goto after_0;
    // 0x800B3EE0: sw          $v0, -0x37AC($v1)
    MEM_W(-0X37AC, ctx->r3) = ctx->r2;
    after_0:
    // 0x800B3EE4: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // 0x800B3EE8: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x800B3EEC: jal         0x80006D9C
    // 0x800B3EF0: sw          $a0, -0x37A8($v0)
    MEM_W(-0X37A8, ctx->r2) = ctx->r4;
    func_80006D9C(rdram, ctx);
        goto after_1;
    // 0x800B3EF0: sw          $a0, -0x37A8($v0)
    MEM_W(-0X37A8, ctx->r2) = ctx->r4;
    after_1:
    // 0x800B3EF4: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x800B3EF8: jr          $ra
    // 0x800B3EFC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x800B3EFC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_800B3F00(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B3F00: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x800B3F04: lw          $a0, -0x37A8($v0)
    ctx->r4 = MEM_W(ctx->r2, -0X37A8);
    // 0x800B3F08: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800B3F0C: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x800B3F10: jal         0x800070BC
    // 0x800B3F14: nop

    func_800070BC(rdram, ctx);
        goto after_0;
    // 0x800B3F14: nop

    after_0:
    // 0x800B3F18: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x800B3F1C: jr          $ra
    // 0x800B3F20: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x800B3F20: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_800B3F0C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B3F0C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800B3F10: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x800B3F14: addu        $s1, $a0, $zero
    ctx->r17 = ADD32(ctx->r4, 0);
    // 0x800B3F18: sw          $ra, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r31;
    // 0x800B3F1C: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x800B3F20: lw          $a0, 0x1C0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X1C0);
    // 0x800B3F24: addiu       $s0, $zero, -0x1
    ctx->r16 = ADD32(0, -0X1);
    // 0x800B3F28: beq         $a0, $s0, L_800B3F3C
    if (ctx->r4 == ctx->r16) {
        // 0x800B3F2C: nop
    
            goto L_800B3F3C;
    }
    // 0x800B3F2C: nop

    // 0x800B3F30: jal         0x80002BA8
    // 0x800B3F34: nop

    func_80002BA8(rdram, ctx);
        goto after_0;
    // 0x800B3F34: nop

    after_0:
    // 0x800B3F38: sw          $s0, 0x1C0($s1)
    MEM_W(0X1C0, ctx->r17) = ctx->r16;
L_800B3F3C:
    // 0x800B3F3C: lw          $ra, 0x18($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X18);
    // 0x800B3F40: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x800B3F44: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x800B3F48: jr          $ra
    // 0x800B3F4C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x800B3F4C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_800B3F24(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B3F24: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800B3F28: sw          $s4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r20;
    // 0x800B3F2C: addu        $s4, $a0, $zero
    ctx->r20 = ADD32(ctx->r4, 0);
    // 0x800B3F30: sw          $s3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r19;
    // 0x800B3F34: addu        $s3, $a1, $zero
    ctx->r19 = ADD32(ctx->r5, 0);
    // 0x800B3F38: addiu       $a0, $zero, 0x60
    ctx->r4 = ADD32(0, 0X60);
    // 0x800B3F3C: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x800B3F40: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800B3F44: sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // 0x800B3F48: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x800B3F4C: jal         0x80001ACC
    // 0x800B3F50: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    rs_malloc(rdram, ctx);
        goto after_0;
    // 0x800B3F50: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    after_0:
    // 0x800B3F54: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    // 0x800B3F58: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x800B3F5C: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x800B3F60: jal         0x800078E0
    // 0x800B3F64: addiu       $a2, $zero, 0x60
    ctx->r6 = ADD32(0, 0X60);
    rs_memset(rdram, ctx);
        goto after_1;
    // 0x800B3F64: addiu       $a2, $zero, 0x60
    ctx->r6 = ADD32(0, 0X60);
    after_1:
    // 0x800B3F68: addiu       $a0, $s0, 0x18
    ctx->r4 = ADD32(ctx->r16, 0X18);
    // 0x800B3F6C: lui         $s2, 0x8014
    ctx->r18 = S32(0X8014 << 16);
    // 0x800B3F70: lui         $s1, 0x800D
    ctx->r17 = S32(0X800D << 16);
    // 0x800B3F74: lw          $v0, -0x76E0($s2)
    ctx->r2 = MEM_W(ctx->r18, -0X76E0);
    // 0x800B3F78: lw          $v1, -0x37AC($s1)
    ctx->r3 = MEM_W(ctx->r17, -0X37AC);
    // 0x800B3F7C: addu        $a1, $s3, $zero
    ctx->r5 = ADD32(ctx->r19, 0);
    // 0x800B3F80: sw          $s4, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->r20;
    // 0x800B3F84: sw          $v0, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->r2;
    // 0x800B3F88: jal         0x8000761C
    // 0x800B3F8C: sw          $v1, 0x5C($s0)
    MEM_W(0X5C, ctx->r16) = ctx->r3;
    rs_strcpy(rdram, ctx);
        goto after_2;
    // 0x800B3F8C: sw          $v1, 0x5C($s0)
    MEM_W(0X5C, ctx->r16) = ctx->r3;
    after_2:
    // 0x800B3F90: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    // 0x800B3F94: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x800B3F98: lw          $a0, -0x76E0($s2)
    ctx->r4 = MEM_W(ctx->r18, -0X76E0);
    // 0x800B3F9C: lw          $a1, -0x37A8($v0)
    ctx->r5 = MEM_W(ctx->r2, -0X37A8);
    // 0x800B3FA0: jal         0x80006F78
    // 0x800B3FA4: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    func_80006F78(rdram, ctx);
        goto after_3;
    // 0x800B3FA4: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    after_3:
    // 0x800B3FA8: lw          $v0, -0x37AC($s1)
    ctx->r2 = MEM_W(ctx->r17, -0X37AC);
    // 0x800B3FAC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800B3FB0: lw          $s4, 0x20($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X20);
    // 0x800B3FB4: lw          $s3, 0x1C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X1C);
    // 0x800B3FB8: lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X18);
    // 0x800B3FBC: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800B3FC0: sw          $v0, -0x37AC($s1)
    MEM_W(-0X37AC, ctx->r17) = ctx->r2;
    // 0x800B3FC4: lbu         $v0, 0x5F($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X5F);
    // 0x800B3FC8: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x800B3FCC: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x800B3FD0: jr          $ra
    // 0x800B3FD4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x800B3FD4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_800B3F50(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B3F50: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800B3F54: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x800B3F58: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x800B3F5C: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x800B3F60: lui         $s1, 0x8011
    ctx->r17 = S32(0X8011 << 16);
    // 0x800B3F64: lw          $v0, -0x694C($s1)
    ctx->r2 = MEM_W(ctx->r17, -0X694C);
    // 0x800B3F68: addu        $a3, $a1, $zero
    ctx->r7 = ADD32(ctx->r5, 0);
    // 0x800B3F6C: beq         $s0, $v0, L_800B3FA0
    if (ctx->r16 == ctx->r2) {
        // 0x800B3F70: sw          $ra, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r31;
            goto L_800B3FA0;
    }
    // 0x800B3F70: sw          $ra, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r31;
    // 0x800B3F74: addiu       $v0, $zero, 0x28C
    ctx->r2 = ADD32(0, 0X28C);
    // 0x800B3F78: beq         $s0, $v0, L_800B3FA0
    if (ctx->r16 == ctx->r2) {
        // 0x800B3F7C: addiu       $a1, $zero, 0x73
        ctx->r5 = ADD32(0, 0X73);
            goto L_800B3FA0;
    }
    // 0x800B3F7C: addiu       $a1, $zero, 0x73
    ctx->r5 = ADD32(0, 0X73);
    // 0x800B3F80: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // 0x800B3F84: jal         0x80066EE4
    // 0x800B3F88: andi        $a3, $a3, 0xFFFF
    ctx->r7 = ctx->r7 & 0XFFFF;
    func_80066EE4(rdram, ctx);
        goto after_0;
    // 0x800B3F88: andi        $a3, $a3, 0xFFFF
    ctx->r7 = ctx->r7 & 0XFFFF;
    after_0:
    // 0x800B3F8C: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800B3F90: lwc1        $f0, 0x5808($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X5808);
    // 0x800B3F94: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800B3F98: sw          $s0, -0x694C($s1)
    MEM_W(-0X694C, ctx->r17) = ctx->r16;
    // 0x800B3F9C: swc1        $f0, -0x6950($v0)
    MEM_W(-0X6950, ctx->r2) = ctx->f0.u32l;
L_800B3FA0:
    // 0x800B3FA0: lw          $ra, 0x18($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X18);
    // 0x800B3FA4: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x800B3FA8: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x800B3FAC: jr          $ra
    // 0x800B3FB0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x800B3FB0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_800B3FB4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B3FB4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800B3FB8: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x800B3FBC: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x800B3FC0: addu        $a3, $a1, $zero
    ctx->r7 = ADD32(ctx->r5, 0);
    // 0x800B3FC4: addiu       $v0, $zero, 0x28C
    ctx->r2 = ADD32(0, 0X28C);
    // 0x800B3FC8: bne         $s0, $v0, L_800B3FD8
    if (ctx->r16 != ctx->r2) {
        // 0x800B3FCC: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_800B3FD8;
    }
    // 0x800B3FCC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800B3FD0: j           L_800B4090
    // 0x800B3FD4: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
        goto L_800B4090;
    // 0x800B3FD4: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_800B3FD8:
    // 0x800B3FD8: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
    // 0x800B3FDC: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800B3FE0: addiu       $a1, $v0, -0x48C0
    ctx->r5 = ADD32(ctx->r2, -0X48C0);
    // 0x800B3FE4: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800B3FE8: addiu       $a0, $v0, -0x4880
    ctx->r4 = ADD32(ctx->r2, -0X4880);
    // 0x800B3FEC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x800B3FF0: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
L_800B3FF4:
    // 0x800B3FF4: addu        $v0, $v0, $a1
    ctx->r2 = ADD32(ctx->r2, ctx->r5);
    // 0x800B3FF8: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x800B3FFC: bnel        $v0, $s0, L_800B401C
    if (ctx->r2 != ctx->r16) {
        // 0x800B4000: addiu       $v1, $v1, 0x1
        ctx->r3 = ADD32(ctx->r3, 0X1);
            goto L_800B401C;
    }
    goto skip_0;
    // 0x800B4000: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    skip_0:
    // 0x800B4004: addu        $v1, $v1, $a0
    ctx->r3 = ADD32(ctx->r3, ctx->r4);
    // 0x800B4008: lbu         $v0, 0x0($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X0);
    // 0x800B400C: bne         $v0, $zero, L_800B4090
    if (ctx->r2 != 0) {
        // 0x800B4010: addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
            goto L_800B4090;
    }
    // 0x800B4010: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // 0x800B4014: j           L_800B4028
    // 0x800B4018: sb          $a2, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r6;
        goto L_800B4028;
    // 0x800B4018: sb          $a2, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r6;
L_800B401C:
    // 0x800B401C: slti        $v0, $v1, 0xE
    ctx->r2 = SIGNED(ctx->r3) < 0XE ? 1 : 0;
    // 0x800B4020: bne         $v0, $zero, L_800B3FF4
    if (ctx->r2 != 0) {
        // 0x800B4024: sll         $v0, $v1, 2
        ctx->r2 = S32(ctx->r3 << 2);
            goto L_800B3FF4;
    }
    // 0x800B4024: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
L_800B4028:
    // 0x800B4028: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800B402C: lbu         $v1, 0xB40($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0XB40);
    // 0x800B4030: addiu       $v0, $zero, 0xF
    ctx->r2 = ADD32(0, 0XF);
    // 0x800B4034: beq         $v1, $v0, L_800B404C
    if (ctx->r3 == ctx->r2) {
        // 0x800B4038: addiu       $v0, $zero, 0x104
        ctx->r2 = ADD32(0, 0X104);
            goto L_800B404C;
    }
    // 0x800B4038: addiu       $v0, $zero, 0x104
    ctx->r2 = ADD32(0, 0X104);
    // 0x800B403C: beq         $s0, $v0, L_800B4058
    if (ctx->r16 == ctx->r2) {
        // 0x800B4040: addu        $a0, $s0, $zero
        ctx->r4 = ADD32(ctx->r16, 0);
            goto L_800B4058;
    }
    // 0x800B4040: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x800B4044: j           L_800B4068
    // 0x800B4048: addiu       $a1, $zero, 0x73
    ctx->r5 = ADD32(0, 0X73);
        goto L_800B4068;
    // 0x800B4048: addiu       $a1, $zero, 0x73
    ctx->r5 = ADD32(0, 0X73);
L_800B404C:
    // 0x800B404C: addiu       $v0, $zero, 0x28C
    ctx->r2 = ADD32(0, 0X28C);
    // 0x800B4050: bne         $s0, $v0, L_800B4064
    if (ctx->r16 != ctx->r2) {
        // 0x800B4054: addu        $a0, $s0, $zero
        ctx->r4 = ADD32(ctx->r16, 0);
            goto L_800B4064;
    }
    // 0x800B4054: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
L_800B4058:
    // 0x800B4058: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x800B405C: j           L_800B4068
    // 0x800B4060: addiu       $a1, $zero, 0x78
    ctx->r5 = ADD32(0, 0X78);
        goto L_800B4068;
    // 0x800B4060: addiu       $a1, $zero, 0x78
    ctx->r5 = ADD32(0, 0X78);
L_800B4064:
    // 0x800B4064: addiu       $a1, $zero, 0x73
    ctx->r5 = ADD32(0, 0X73);
L_800B4068:
    // 0x800B4068: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // 0x800B406C: jal         0x80066EE4
    // 0x800B4070: andi        $a3, $a3, 0xFFFF
    ctx->r7 = ctx->r7 & 0XFFFF;
    func_80066EE4(rdram, ctx);
        goto after_0;
    // 0x800B4070: andi        $a3, $a3, 0xFFFF
    ctx->r7 = ctx->r7 & 0XFFFF;
    after_0:
    // 0x800B4074: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800B4078: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800B407C: lwc1        $f0, 0x580C($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X580C);
    // 0x800B4080: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
    // 0x800B4084: sw          $s0, -0x694C($v1)
    MEM_W(-0X694C, ctx->r3) = ctx->r16;
    // 0x800B4088: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
    // 0x800B408C: swc1        $f0, -0x6950($v1)
    MEM_W(-0X6950, ctx->r3) = ctx->f0.u32l;
L_800B4090:
    // 0x800B4090: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800B4094: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x800B4098: jr          $ra
    // 0x800B409C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x800B409C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_800B3FD8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B3FD8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800B3FDC: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x800B3FE0: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x800B3FE4: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x800B3FE8: lw          $a0, -0x76E0($v0)
    ctx->r4 = MEM_W(ctx->r2, -0X76E0);
    // 0x800B3FEC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800B3FF0: jal         0x80006EC4
    // 0x800B3FF4: nop

    func_80006EC4(rdram, ctx);
        goto after_0;
    // 0x800B3FF4: nop

    after_0:
    // 0x800B3FF8: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // 0x800B3FFC: beq         $v1, $zero, L_800B400C
    if (ctx->r3 == 0) {
        // 0x800B4000: nop
    
            goto L_800B400C;
    }
    // 0x800B4000: nop

    // 0x800B4004: lbu         $v0, 0x17($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X17);
    // 0x800B4008: sb          $v0, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r2;
L_800B400C:
    // 0x800B400C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800B4010: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x800B4014: sltu        $v0, $zero, $v1
    ctx->r2 = 0 < ctx->r3 ? 1 : 0;
    // 0x800B4018: jr          $ra
    // 0x800B401C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x800B401C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_800B4020(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B4020: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800B4024: addiu       $a0, $zero, 0x40
    ctx->r4 = ADD32(0, 0X40);
    // 0x800B4028: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x800B402C: jal         0x800B32F4
    // 0x800B4030: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    func_800B32F4(rdram, ctx);
        goto after_0;
    // 0x800B4030: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    after_0:
    // 0x800B4034: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x800B4038: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x800B403C: sw          $v0, -0x379C($v1)
    MEM_W(-0X379C, ctx->r3) = ctx->r2;
    // 0x800B4040: jr          $ra
    // 0x800B4044: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x800B4044: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_800B4048(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B4048: addu        $t0, $a1, $zero
    ctx->r8 = ADD32(ctx->r5, 0);
    // 0x800B404C: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x800B4050: mtc1        $a2, $f4
    ctx->f4.u32l = ctx->r6;
    // 0x800B4054: lw          $v0, -0x37A4($a1)
    ctx->r2 = MEM_W(ctx->r5, -0X37A4);
    // 0x800B4058: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800B405C: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x800B4060: addu        $s1, $a0, $zero
    ctx->r17 = ADD32(ctx->r4, 0);
    // 0x800B4064: sw          $ra, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r31;
    // 0x800B4068: bne         $v0, $zero, L_800B4138
    if (ctx->r2 != 0) {
        // 0x800B406C: sw          $s0, 0x10($sp)
        MEM_W(0X10, ctx->r29) = ctx->r16;
            goto L_800B4138;
    }
    // 0x800B406C: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x800B4070: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x800B4074: lwc1        $f0, 0x10($t0)
    ctx->f0.u32l = MEM_W(ctx->r8, 0X10);
    // 0x800B4078: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x800B407C: lui         $a3, 0x240
    ctx->r7 = S32(0X240 << 16);
    // 0x800B4080: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800B4084: lwc1        $f2, 0x5D90($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X5D90);
    // 0x800B4088: lw          $v1, -0x379C($v0)
    ctx->r3 = MEM_W(ctx->r2, -0X379C);
    // 0x800B408C: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x800B4090: ori         $a3, $a3, 0x3
    ctx->r7 = ctx->r7 | 0X3;
    // 0x800B4094: lw          $s0, 0xC($v1)
    ctx->r16 = MEM_W(ctx->r3, 0XC);
    // 0x800B4098: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800B409C: lwc1        $f2, 0x5D94($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X5D94);
    // 0x800B40A0: swc1        $f0, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f0.u32l;
    // 0x800B40A4: lwc1        $f0, 0x14($t0)
    ctx->f0.u32l = MEM_W(ctx->r8, 0X14);
    // 0x800B40A8: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x800B40AC: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x800B40B0: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // 0x800B40B4: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x800B40B8: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800B40BC: lwc1        $f2, 0x5D98($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X5D98);
    // 0x800B40C0: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800B40C4: lwc1        $f6, 0x5D9C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X5D9C);
    // 0x800B40C8: mul.s       $f2, $f4, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = MUL_S(ctx->f4.fl, ctx->f2.fl);
    // 0x800B40CC: sb          $zero, -0x37A0($v0)
    MEM_B(-0X37A0, ctx->r2) = 0;
    // 0x800B40D0: sw          $v1, -0x37A4($a1)
    MEM_W(-0X37A4, ctx->r5) = ctx->r3;
    // 0x800B40D4: swc1        $f0, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->f0.u32l;
    // 0x800B40D8: lwc1        $f0, 0x10($t0)
    ctx->f0.u32l = MEM_W(ctx->r8, 0X10);
    // 0x800B40DC: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x800B40E0: mul.s       $f0, $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x800B40E4: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x800B40E8: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x800B40EC: lw          $v0, 0x14($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X14);
    // 0x800B40F0: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800B40F4: lwc1        $f4, 0x5DA0($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X5DA0);
    // 0x800B40F8: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
    // 0x800B40FC: swc1        $f0, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f0.u32l;
    // 0x800B4100: lwc1        $f0, 0x14($t0)
    ctx->f0.u32l = MEM_W(ctx->r8, 0X14);
    // 0x800B4104: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x800B4108: mul.s       $f0, $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x800B410C: or          $v0, $v0, $a3
    ctx->r2 = ctx->r2 | ctx->r7;
    // 0x800B4110: swc1        $f2, -0x190C($v1)
    MEM_W(-0X190C, ctx->r3) = ctx->f2.u32l;
    // 0x800B4114: swc1        $f4, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->f4.u32l;
    // 0x800B4118: sw          $v0, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->r2;
    // 0x800B411C: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
    // 0x800B4120: jal         0x800642A0
    // 0x800B4124: swc1        $f0, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f0.u32l;
    func_800642A0(rdram, ctx);
        goto after_0;
    // 0x800B4124: swc1        $f0, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f0.u32l;
    after_0:
    // 0x800B4128: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x800B412C: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x800B4130: jal         0x800646AC
    // 0x800B4134: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_800646AC(rdram, ctx);
        goto after_1;
    // 0x800B4134: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_1:
L_800B4138:
    // 0x800B4138: lui         $v0, 0x8003
    ctx->r2 = S32(0X8003 << 16);
    // 0x800B413C: lw          $v0, 0x75A4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X75A4);
    // 0x800B4140: andi        $v0, $v0, 0x80
    ctx->r2 = ctx->r2 & 0X80;
    // 0x800B4144: bne         $v0, $zero, L_800B4154
    if (ctx->r2 != 0) {
        // 0x800B4148: nop
    
            goto L_800B4154;
    }
    // 0x800B4148: nop

    // 0x800B414C: jal         0x8001B7C8
    // 0x800B4150: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    func_8001B7C8(rdram, ctx);
        goto after_2;
    // 0x800B4150: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    after_2:
L_800B4154:
    // 0x800B4154: lw          $ra, 0x18($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X18);
    // 0x800B4158: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x800B415C: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x800B4160: jr          $ra
    // 0x800B4164: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x800B4164: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_800B40A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B40A0: addiu       $v0, $zero, 0x28C
    ctx->r2 = ADD32(0, 0X28C);
    // 0x800B40A4: beq         $a0, $v0, L_800B40E8
    if (ctx->r4 == ctx->r2) {
        // 0x800B40A8: addu        $v1, $zero, $zero
        ctx->r3 = ADD32(0, 0);
            goto L_800B40E8;
    }
    // 0x800B40A8: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
    // 0x800B40AC: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800B40B0: addiu       $a2, $v0, -0x48C0
    ctx->r6 = ADD32(ctx->r2, -0X48C0);
    // 0x800B40B4: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800B40B8: addiu       $a1, $v0, -0x4880
    ctx->r5 = ADD32(ctx->r2, -0X4880);
    // 0x800B40BC: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
L_800B40C0:
    // 0x800B40C0: addu        $v0, $v0, $a2
    ctx->r2 = ADD32(ctx->r2, ctx->r6);
    // 0x800B40C4: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x800B40C8: bnel        $v0, $a0, L_800B40DC
    if (ctx->r2 != ctx->r4) {
        // 0x800B40CC: addiu       $v1, $v1, 0x1
        ctx->r3 = ADD32(ctx->r3, 0X1);
            goto L_800B40DC;
    }
    goto skip_0;
    // 0x800B40CC: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    skip_0:
    // 0x800B40D0: addu        $v0, $v1, $a1
    ctx->r2 = ADD32(ctx->r3, ctx->r5);
    // 0x800B40D4: jr          $ra
    // 0x800B40D8: sb          $zero, 0x0($v0)
    MEM_B(0X0, ctx->r2) = 0;
    return;
    // 0x800B40D8: sb          $zero, 0x0($v0)
    MEM_B(0X0, ctx->r2) = 0;
L_800B40DC:
    // 0x800B40DC: slti        $v0, $v1, 0xE
    ctx->r2 = SIGNED(ctx->r3) < 0XE ? 1 : 0;
    // 0x800B40E0: bne         $v0, $zero, L_800B40C0
    if (ctx->r2 != 0) {
        // 0x800B40E4: sll         $v0, $v1, 2
        ctx->r2 = S32(ctx->r3 << 2);
            goto L_800B40C0;
    }
    // 0x800B40E4: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
L_800B40E8:
    // 0x800B40E8: jr          $ra
    // 0x800B40EC: nop

    return;
    // 0x800B40EC: nop

;}
RECOMP_FUNC void func_800B40F0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B40F0: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x800B40F4: addiu       $v1, $v1, 0x7DB8
    ctx->r3 = ADD32(ctx->r3, 0X7DB8);
    // 0x800B40F8: andi        $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 & 0XFF;
    // 0x800B40FC: sll         $v0, $a0, 2
    ctx->r2 = S32(ctx->r4 << 2);
    // 0x800B4100: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x800B4104: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800B4108: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x800B410C: sll         $v0, $v0, 5
    ctx->r2 = S32(ctx->r2 << 5);
    // 0x800B4110: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800B4114: lw          $a2, 0x0($a1)
    ctx->r6 = MEM_W(ctx->r5, 0X0);
    // 0x800B4118: lw          $a3, 0x4($a1)
    ctx->r7 = MEM_W(ctx->r5, 0X4);
    // 0x800B411C: lw          $t0, 0x8($a1)
    ctx->r8 = MEM_W(ctx->r5, 0X8);
    // 0x800B4120: sw          $a2, 0x19C($v0)
    MEM_W(0X19C, ctx->r2) = ctx->r6;
    // 0x800B4124: sw          $a3, 0x1A0($v0)
    MEM_W(0X1A0, ctx->r2) = ctx->r7;
    // 0x800B4128: sw          $t0, 0x1A4($v0)
    MEM_W(0X1A4, ctx->r2) = ctx->r8;
    // 0x800B412C: jr          $ra
    // 0x800B4130: nop

    return;
    // 0x800B4130: nop

;}
