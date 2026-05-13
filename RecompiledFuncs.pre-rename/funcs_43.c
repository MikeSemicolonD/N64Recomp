#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void func_800FBC4C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800FBC4C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800FBC50: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800FBC54: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x800FBC58: lwc1        $f0, -0x3614($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, -0X3614);
    // 0x800FBC5C: lbu         $v1, -0x3610($a0)
    ctx->r3 = MEM_BU(ctx->r4, -0X3610);
    // 0x800FBC60: add.s       $f2, $f0, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f2.fl = ctx->f0.fl + ctx->f12.fl;
    // 0x800FBC64: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800FBC68: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x800FBC6C: bne         $v1, $zero, L_800FBC94
    if (ctx->r3 != 0) {
        // 0x800FBC70: swc1        $f2, -0x3614($v0)
        MEM_W(-0X3614, ctx->r2) = ctx->f2.u32l;
            goto L_800FBC94;
    }
    // 0x800FBC70: swc1        $f2, -0x3614($v0)
    MEM_W(-0X3614, ctx->r2) = ctx->f2.u32l;
    // 0x800FBC74: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800FBC78: lwc1        $f0, -0x6F68($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X6F68);
    // 0x800FBC7C: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x800FBC80: nop

    // 0x800FBC84: bc1f        L_800FBC94
    if (!c1cs) {
        // 0x800FBC88: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_800FBC94;
    }
    // 0x800FBC88: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800FBC8C: j           L_800FBD38
    // 0x800FBC90: sb          $v0, -0x3610($a0)
    MEM_B(-0X3610, ctx->r4) = ctx->r2;
        goto L_800FBD38;
    // 0x800FBC90: sb          $v0, -0x3610($a0)
    MEM_B(-0X3610, ctx->r4) = ctx->r2;
L_800FBC94:
    // 0x800FBC94: lui         $s0, 0x8011
    ctx->r16 = S32(0X8011 << 16);
    // 0x800FBC98: lbu         $v1, -0x3610($s0)
    ctx->r3 = MEM_BU(ctx->r16, -0X3610);
    // 0x800FBC9C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800FBCA0: bne         $v1, $v0, L_800FBCDC
    if (ctx->r3 != ctx->r2) {
        // 0x800FBCA4: addiu       $v0, $zero, 0x2
        ctx->r2 = ADD32(0, 0X2);
            goto L_800FBCDC;
    }
    // 0x800FBCA4: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x800FBCA8: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800FBCAC: lbu         $a0, -0x35E8($v0)
    ctx->r4 = MEM_BU(ctx->r2, -0X35E8);
    // 0x800FBCB0: jal         0x8006C994
    // 0x800FBCB4: nop

    func_8006C994(rdram, ctx);
        goto after_0;
    // 0x800FBCB4: nop

    after_0:
    // 0x800FBCB8: andi        $a0, $v0, 0xFFFF
    ctx->r4 = ctx->r2 & 0XFFFF;
    // 0x800FBCBC: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    // 0x800FBCC0: jal         0x8003E8DC
    // 0x800FBCC4: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    slotDispatcherIter(rdram, ctx);
        goto after_1;
    // 0x800FBCC4: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    after_1:
    // 0x800FBCC8: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800FBCCC: sw          $zero, -0x3614($v0)
    MEM_W(-0X3614, ctx->r2) = 0;
    // 0x800FBCD0: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x800FBCD4: j           L_800FBD38
    // 0x800FBCD8: sb          $v0, -0x3610($s0)
    MEM_B(-0X3610, ctx->r16) = ctx->r2;
        goto L_800FBD38;
    // 0x800FBCD8: sb          $v0, -0x3610($s0)
    MEM_B(-0X3610, ctx->r16) = ctx->r2;
L_800FBCDC:
    // 0x800FBCDC: bne         $v1, $v0, L_800FBD38
    if (ctx->r3 != ctx->r2) {
        // 0x800FBCE0: lui         $v0, 0x8011
        ctx->r2 = S32(0X8011 << 16);
            goto L_800FBD38;
    }
    // 0x800FBCE0: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800FBCE4: lwc1        $f2, -0x3614($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, -0X3614);
    // 0x800FBCE8: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800FBCEC: lwc1        $f0, -0x6F64($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X6F64);
    // 0x800FBCF0: c.le.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl <= ctx->f2.fl;
    // 0x800FBCF4: nop

    // 0x800FBCF8: bc1f        L_800FBD38
    if (!c1cs) {
        // 0x800FBCFC: nop
    
            goto L_800FBD38;
    }
    // 0x800FBCFC: nop

    // 0x800FBD00: jal         0x800C3FEC
    // 0x800FBD04: nop

    func_800C3FEC(rdram, ctx);
        goto after_2;
    // 0x800FBD04: nop

    after_2:
    // 0x800FBD08: jal         0x800C72E8
    // 0x800FBD0C: nop

    func_800C72E8(rdram, ctx);
        goto after_3;
    // 0x800FBD0C: nop

    after_3:
    // 0x800FBD10: jal         0x800EFBB4
    // 0x800FBD14: nop

    func_800EFBB4(rdram, ctx);
        goto after_4;
    // 0x800FBD14: nop

    after_4:
    // 0x800FBD18: jal         0x800ECDDC
    // 0x800FBD1C: nop

    func_800ECDDC(rdram, ctx);
        goto after_5;
    // 0x800FBD1C: nop

    after_5:
    // 0x800FBD20: jal         0x80067820
    // 0x800FBD24: nop

    func_80067820(rdram, ctx);
        goto after_6;
    // 0x800FBD24: nop

    after_6:
    // 0x800FBD28: jal         0x80067990
    // 0x800FBD2C: nop

    func_80067990(rdram, ctx);
        goto after_7;
    // 0x800FBD2C: nop

    after_7:
    // 0x800FBD30: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800FBD34: sw          $zero, -0x35E0($v0)
    MEM_W(-0X35E0, ctx->r2) = 0;
L_800FBD38:
    // 0x800FBD38: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800FBD3C: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x800FBD40: jr          $ra
    // 0x800FBD44: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x800FBD44: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_800FBD48(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800FBD48: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800FBD4C: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x800FBD50: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // 0x800FBD54: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800FBD58: addiu       $a0, $v0, -0x4058
    ctx->r4 = ADD32(ctx->r2, -0X4058);
    // 0x800FBD5C: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800FBD60: addiu       $a1, $v0, -0x41E8
    ctx->r5 = ADD32(ctx->r2, -0X41E8);
L_800FBD64:
    // 0x800FBD64: lhu         $v1, 0x1A($a1)
    ctx->r3 = MEM_HU(ctx->r5, 0X1A);
    // 0x800FBD68: addiu       $a1, $a1, 0x24
    ctx->r5 = ADD32(ctx->r5, 0X24);
    // 0x800FBD6C: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x800FBD70: lhu         $v0, 0x0($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X0);
    // 0x800FBD74: nor         $v1, $zero, $v1
    ctx->r3 = ~(0 | ctx->r3);
    // 0x800FBD78: and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // 0x800FBD7C: sh          $v0, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r2;
    // 0x800FBD80: blez        $a2, L_800FBD64
    if (SIGNED(ctx->r6) <= 0) {
        // 0x800FBD84: addiu       $a0, $a0, 0x2
        ctx->r4 = ADD32(ctx->r4, 0X2);
            goto L_800FBD64;
    }
    // 0x800FBD84: addiu       $a0, $a0, 0x2
    ctx->r4 = ADD32(ctx->r4, 0X2);
    // 0x800FBD88: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x800FBD8C: lw          $v0, -0x35E0($a0)
    ctx->r2 = MEM_W(ctx->r4, -0X35E0);
    // 0x800FBD90: addiu       $v1, $zero, 0x6
    ctx->r3 = ADD32(0, 0X6);
    // 0x800FBD94: beq         $v0, $v1, L_800FBDBC
    if (ctx->r2 == ctx->r3) {
        // 0x800FBD98: addiu       $a1, $zero, 0x3E8
        ctx->r5 = ADD32(0, 0X3E8);
            goto L_800FBDBC;
    }
    // 0x800FBD98: addiu       $a1, $zero, 0x3E8
    ctx->r5 = ADD32(0, 0X3E8);
    // 0x800FBD9C: sw          $v1, -0x35E0($a0)
    MEM_W(-0X35E0, ctx->r4) = ctx->r3;
    // 0x800FBDA0: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x800FBDA4: jal         0x8008E0B0
    // 0x800FBDA8: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    func_8008E0B0(rdram, ctx);
        goto after_0;
    // 0x800FBDA8: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    after_0:
    // 0x800FBDAC: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800FBDB0: lwc1        $f0, -0x6F60($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X6F60);
    // 0x800FBDB4: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800FBDB8: swc1        $f0, -0x3614($v0)
    MEM_W(-0X3614, ctx->r2) = ctx->f0.u32l;
L_800FBDBC:
    // 0x800FBDBC: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x800FBDC0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800FBDC4: jr          $ra
    // 0x800FBDC8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x800FBDC8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_800FBDCC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800FBDCC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800FBDD0: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800FBDD4: lw          $v1, -0x35E0($v0)
    ctx->r3 = MEM_W(ctx->r2, -0X35E0);
    // 0x800FBDD8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800FBDDC: bne         $v1, $v0, L_800FBE04
    if (ctx->r3 != ctx->r2) {
        // 0x800FBDE0: sw          $ra, 0x10($sp)
        MEM_W(0X10, ctx->r29) = ctx->r31;
            goto L_800FBE04;
    }
    // 0x800FBDE0: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x800FBDE4: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800FBDE8: lwc1        $f12, -0x6F5C($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X6F5C);
    // 0x800FBDEC: jal         0x800EF1B0
    // 0x800FBDF0: nop

    func_800EF1B0(rdram, ctx);
        goto after_0;
    // 0x800FBDF0: nop

    after_0:
    // 0x800FBDF4: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
    // 0x800FBDF8: lbu         $v0, -0x3610($v1)
    ctx->r2 = MEM_BU(ctx->r3, -0X3610);
    // 0x800FBDFC: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800FBE00: sb          $v0, -0x3610($v1)
    MEM_B(-0X3610, ctx->r3) = ctx->r2;
L_800FBE04:
    // 0x800FBE04: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x800FBE08: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800FBE0C: jr          $ra
    // 0x800FBE10: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x800FBE10: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void fake_func_800FBE14(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
;}
RECOMP_FUNC void func_800FBE20(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800FBE20: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800FBE24: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x800FBE28: addu        $s1, $zero, $zero
    ctx->r17 = ADD32(0, 0);
    // 0x800FBE2C: andi        $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 & 0XFF;
    // 0x800FBE30: sll         $v0, $a0, 2
    ctx->r2 = S32(ctx->r4 << 2);
    // 0x800FBE34: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x800FBE38: sll         $v0, $v0, 4
    ctx->r2 = S32(ctx->r2 << 4);
    // 0x800FBE3C: subu        $v0, $v0, $a0
    ctx->r2 = SUB32(ctx->r2, ctx->r4);
    // 0x800FBE40: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x800FBE44: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
    // 0x800FBE48: addiu       $v1, $v1, -0x35D0
    ctx->r3 = ADD32(ctx->r3, -0X35D0);
    // 0x800FBE4C: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x800FBE50: addu        $s0, $v0, $v1
    ctx->r16 = ADD32(ctx->r2, ctx->r3);
    // 0x800FBE54: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800FBE58: sw          $s3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r19;
    // 0x800FBE5C: addu        $s3, $s0, $zero
    ctx->r19 = ADD32(ctx->r16, 0);
    // 0x800FBE60: sw          $ra, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r31;
    // 0x800FBE64: sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // 0x800FBE68: sb          $a1, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r5;
    // 0x800FBE6C: sb          $a2, 0x2($s0)
    MEM_B(0X2, ctx->r16) = ctx->r6;
    // 0x800FBE70: sb          $a2, 0x3($s0)
    MEM_B(0X3, ctx->r16) = ctx->r6;
    // 0x800FBE74: sb          $a3, 0x4($s0)
    MEM_B(0X4, ctx->r16) = ctx->r7;
    // 0x800FBE78: lw          $v0, 0xB4C($v0)
    ctx->r2 = MEM_W(ctx->r2, 0XB4C);
    // 0x800FBE7C: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
    // 0x800FBE80: srl         $v0, $v0, 7
    ctx->r2 = S32(U32(ctx->r2) >> 7);
    // 0x800FBE84: andi        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 & 0X1;
    // 0x800FBE88: sb          $v0, 0x5($s0)
    MEM_B(0X5, ctx->r16) = ctx->r2;
    // 0x800FBE8C: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800FBE90: lw          $v0, -0x35E4($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X35E4);
    // 0x800FBE94: addiu       $s2, $v1, -0x4BDC
    ctx->r18 = ADD32(ctx->r3, -0X4BDC);
    // 0x800FBE98: srl         $v0, $v0, 10
    ctx->r2 = S32(U32(ctx->r2) >> 10);
    // 0x800FBE9C: andi        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 & 0X1;
    // 0x800FBEA0: sb          $v0, 0x6($s0)
    MEM_B(0X6, ctx->r16) = ctx->r2;
L_800FBEA4:
    // 0x800FBEA4: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    // 0x800FBEA8: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
    // 0x800FBEAC: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x800FBEB0: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x800FBEB4: jal         0x800554D8
    // 0x800FBEB8: addiu       $a2, $zero, 0x2000
    ctx->r6 = ADD32(0, 0X2000);
    func_800554D8(rdram, ctx);
        goto after_0;
    // 0x800FBEB8: addiu       $a2, $zero, 0x2000
    ctx->r6 = ADD32(0, 0X2000);
    after_0:
    // 0x800FBEBC: sh          $v0, 0xA($s3)
    MEM_H(0XA, ctx->r19) = ctx->r2;
    // 0x800FBEC0: sltiu       $v0, $s1, 0xA
    ctx->r2 = ctx->r17 < 0XA ? 1 : 0;
    // 0x800FBEC4: bne         $v0, $zero, L_800FBEA4
    if (ctx->r2 != 0) {
        // 0x800FBEC8: addiu       $s3, $s3, 0x2
        ctx->r19 = ADD32(ctx->r19, 0X2);
            goto L_800FBEA4;
    }
    // 0x800FBEC8: addiu       $s3, $s3, 0x2
    ctx->r19 = ADD32(ctx->r19, 0X2);
    // 0x800FBECC: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    // 0x800FBED0: addiu       $v1, $s0, 0x28
    ctx->r3 = ADD32(ctx->r16, 0X28);
    // 0x800FBED4: addu        $a1, $a0, $zero
    ctx->r5 = ADD32(ctx->r4, 0);
    // 0x800FBED8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800FBEDC: sh          $v0, 0x30($s0)
    MEM_H(0X30, ctx->r16) = ctx->r2;
    // 0x800FBEE0: sh          $v0, 0x32($s0)
    MEM_H(0X32, ctx->r16) = ctx->r2;
    // 0x800FBEE4: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x800FBEE8: sw          $v0, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = ctx->r2;
    // 0x800FBEEC: addiu       $v0, $s0, 0xA
    ctx->r2 = ADD32(ctx->r16, 0XA);
    // 0x800FBEF0: sw          $zero, 0x48($s0)
    MEM_W(0X48, ctx->r16) = 0;
    // 0x800FBEF4: sw          $v0, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->r2;
L_800FBEF8:
    // 0x800FBEF8: lw          $t2, 0x0($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X0);
    // 0x800FBEFC: lw          $t3, 0x4($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X4);
    // 0x800FBF00: lw          $t4, 0x8($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X8);
    // 0x800FBF04: lw          $t5, 0xC($v1)
    ctx->r13 = MEM_W(ctx->r3, 0XC);
    // 0x800FBF08: sw          $t2, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r10;
    // 0x800FBF0C: sw          $t3, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r11;
    // 0x800FBF10: sw          $t4, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r12;
    // 0x800FBF14: sw          $t5, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r13;
    // 0x800FBF18: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
    // 0x800FBF1C: bne         $v1, $a1, L_800FBEF8
    if (ctx->r3 != ctx->r5) {
        // 0x800FBF20: addiu       $a0, $a0, 0x10
        ctx->r4 = ADD32(ctx->r4, 0X10);
            goto L_800FBEF8;
    }
    // 0x800FBF20: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    // 0x800FBF24: addiu       $v0, $s0, 0xC
    ctx->r2 = ADD32(ctx->r16, 0XC);
    // 0x800FBF28: sw          $v0, 0x64($s0)
    MEM_W(0X64, ctx->r16) = ctx->r2;
    // 0x800FBF2C: addiu       $v1, $s0, 0x1A8
    ctx->r3 = ADD32(ctx->r16, 0X1A8);
    // 0x800FBF30: addiu       $v0, $s0, 0x28
    ctx->r2 = ADD32(ctx->r16, 0X28);
    // 0x800FBF34: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
L_800FBF38:
    // 0x800FBF38: lw          $t2, 0x0($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X0);
    // 0x800FBF3C: lw          $t3, 0x4($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X4);
    // 0x800FBF40: lw          $t4, 0x8($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X8);
    // 0x800FBF44: lw          $t5, 0xC($v0)
    ctx->r13 = MEM_W(ctx->r2, 0XC);
    // 0x800FBF48: sw          $t2, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r10;
    // 0x800FBF4C: sw          $t3, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r11;
    // 0x800FBF50: sw          $t4, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r12;
    // 0x800FBF54: sw          $t5, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r13;
    // 0x800FBF58: addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
    // 0x800FBF5C: bne         $v0, $a0, L_800FBF38
    if (ctx->r2 != ctx->r4) {
        // 0x800FBF60: addiu       $v1, $v1, 0x10
        ctx->r3 = ADD32(ctx->r3, 0X10);
            goto L_800FBF38;
    }
    // 0x800FBF60: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
    // 0x800FBF64: addiu       $a0, $s0, 0x1D8
    ctx->r4 = ADD32(ctx->r16, 0X1D8);
    // 0x800FBF68: addiu       $v1, $s0, 0x1A8
    ctx->r3 = ADD32(ctx->r16, 0X1A8);
    // 0x800FBF6C: addu        $a1, $a0, $zero
    ctx->r5 = ADD32(ctx->r4, 0);
    // 0x800FBF70: addiu       $v0, $s0, 0x1A
    ctx->r2 = ADD32(ctx->r16, 0X1A);
    // 0x800FBF74: sw          $v0, 0x1B4($s0)
    MEM_W(0X1B4, ctx->r16) = ctx->r2;
    // 0x800FBF78: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // 0x800FBF7C: sb          $v0, 0x1D4($s0)
    MEM_B(0X1D4, ctx->r16) = ctx->r2;
    // 0x800FBF80: addiu       $v0, $zero, 0xD2
    ctx->r2 = ADD32(0, 0XD2);
    // 0x800FBF84: sb          $v0, 0x1D5($s0)
    MEM_B(0X1D5, ctx->r16) = ctx->r2;
    // 0x800FBF88: sb          $zero, 0x1D6($s0)
    MEM_B(0X1D6, ctx->r16) = 0;
L_800FBF8C:
    // 0x800FBF8C: lw          $t2, 0x0($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X0);
    // 0x800FBF90: lw          $t3, 0x4($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X4);
    // 0x800FBF94: lw          $t4, 0x8($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X8);
    // 0x800FBF98: lw          $t5, 0xC($v1)
    ctx->r13 = MEM_W(ctx->r3, 0XC);
    // 0x800FBF9C: sw          $t2, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r10;
    // 0x800FBFA0: sw          $t3, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r11;
    // 0x800FBFA4: sw          $t4, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r12;
    // 0x800FBFA8: sw          $t5, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r13;
    // 0x800FBFAC: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
    // 0x800FBFB0: bne         $v1, $a1, L_800FBF8C
    if (ctx->r3 != ctx->r5) {
        // 0x800FBFB4: addiu       $a0, $a0, 0x10
        ctx->r4 = ADD32(ctx->r4, 0X10);
            goto L_800FBF8C;
    }
    // 0x800FBFB4: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    // 0x800FBFB8: addu        $s1, $zero, $zero
    ctx->r17 = ADD32(0, 0);
    // 0x800FBFBC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x800FBFC0: addiu       $t1, $zero, 0x3
    ctx->r9 = ADD32(0, 0X3);
    // 0x800FBFC4: addiu       $t0, $zero, 0xFF
    ctx->r8 = ADD32(0, 0XFF);
    // 0x800FBFC8: addiu       $a3, $zero, 0xBE
    ctx->r7 = ADD32(0, 0XBE);
    // 0x800FBFCC: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    // 0x800FBFD0: addiu       $a0, $zero, 0x90
    ctx->r4 = ADD32(0, 0X90);
    // 0x800FBFD4: addiu       $v0, $s0, 0x1C
    ctx->r2 = ADD32(ctx->r16, 0X1C);
    // 0x800FBFD8: sw          $v0, 0x1E4($s0)
    MEM_W(0X1E4, ctx->r16) = ctx->r2;
    // 0x800FBFDC: addu        $v0, $a2, $zero
    ctx->r2 = ADD32(ctx->r6, 0);
    // 0x800FBFE0: sh          $v0, 0x90($s0)
    MEM_H(0X90, ctx->r16) = ctx->r2;
    // 0x800FBFE4: sh          $v0, 0x92($s0)
    MEM_H(0X92, ctx->r16) = ctx->r2;
    // 0x800FBFE8: addu        $v0, $t1, $zero
    ctx->r2 = ADD32(ctx->r9, 0);
    // 0x800FBFEC: sw          $v0, 0x9C($s0)
    MEM_W(0X9C, ctx->r16) = ctx->r2;
    // 0x800FBFF0: addu        $v0, $t0, $zero
    ctx->r2 = ADD32(ctx->r8, 0);
    // 0x800FBFF4: sb          $v0, 0xB4($s0)
    MEM_B(0XB4, ctx->r16) = ctx->r2;
    // 0x800FBFF8: addiu       $v0, $zero, 0xD2
    ctx->r2 = ADD32(0, 0XD2);
    // 0x800FBFFC: sb          $v0, 0xB5($s0)
    MEM_B(0XB5, ctx->r16) = ctx->r2;
    // 0x800FC000: addiu       $v0, $s0, 0xE
    ctx->r2 = ADD32(ctx->r16, 0XE);
    // 0x800FC004: sw          $zero, 0xA8($s0)
    MEM_W(0XA8, ctx->r16) = 0;
    // 0x800FC008: sb          $zero, 0xB6($s0)
    MEM_B(0XB6, ctx->r16) = 0;
    // 0x800FC00C: sw          $v0, 0x94($s0)
    MEM_W(0X94, ctx->r16) = ctx->r2;
L_800FC010:
    // 0x800FC010: addu        $v1, $s0, $a1
    ctx->r3 = ADD32(ctx->r16, ctx->r5);
    // 0x800FC014: addiu       $a1, $a1, 0x2
    ctx->r5 = ADD32(ctx->r5, 0X2);
    // 0x800FC018: addu        $v0, $s0, $a0
    ctx->r2 = ADD32(ctx->r16, ctx->r4);
    // 0x800FC01C: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x800FC020: sh          $a2, 0x30($v0)
    MEM_H(0X30, ctx->r2) = ctx->r6;
    // 0x800FC024: sh          $a2, 0x32($v0)
    MEM_H(0X32, ctx->r2) = ctx->r6;
    // 0x800FC028: sw          $zero, 0x48($v0)
    MEM_W(0X48, ctx->r2) = 0;
    // 0x800FC02C: sw          $t1, 0x3C($v0)
    MEM_W(0X3C, ctx->r2) = ctx->r9;
    // 0x800FC030: sb          $t0, 0x54($v0)
    MEM_B(0X54, ctx->r2) = ctx->r8;
    // 0x800FC034: sb          $zero, 0x55($v0)
    MEM_B(0X55, ctx->r2) = 0;
    // 0x800FC038: sb          $zero, 0x56($v0)
    MEM_B(0X56, ctx->r2) = 0;
    // 0x800FC03C: sb          $a3, 0x57($v0)
    MEM_B(0X57, ctx->r2) = ctx->r7;
    // 0x800FC040: sw          $v1, 0x34($v0)
    MEM_W(0X34, ctx->r2) = ctx->r3;
    // 0x800FC044: sltiu       $v0, $s1, 0x5
    ctx->r2 = ctx->r17 < 0X5 ? 1 : 0;
    // 0x800FC048: bne         $v0, $zero, L_800FC010
    if (ctx->r2 != 0) {
        // 0x800FC04C: addiu       $a0, $a0, 0x30
        ctx->r4 = ADD32(ctx->r4, 0X30);
            goto L_800FC010;
    }
    // 0x800FC04C: addiu       $a0, $a0, 0x30
    ctx->r4 = ADD32(ctx->r4, 0X30);
    // 0x800FC050: lbu         $v0, 0x0($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X0);
    // 0x800FC054: addiu       $v1, $v0, -0x1
    ctx->r3 = ADD32(ctx->r2, -0X1);
    // 0x800FC058: sltiu       $v0, $v1, 0x8
    ctx->r2 = ctx->r3 < 0X8 ? 1 : 0;
    // 0x800FC05C: beq         $v0, $zero, L_800FC090
    if (ctx->r2 == 0) {
        // 0x800FC060: lui         $v0, 0x800B
        ctx->r2 = S32(0X800B << 16);
            goto L_800FC090;
    }
    // 0x800FC060: lui         $v0, 0x800B
    ctx->r2 = S32(0X800B << 16);
    // 0x800FC064: addiu       $v0, $v0, -0x6EC8
    ctx->r2 = ADD32(ctx->r2, -0X6EC8);
    // 0x800FC068: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x800FC06C: addu        $v1, $v1, $v0
    gpr jr_addend_800FC074 = ctx->r3;
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x800FC070: lw          $v0, 0x0($v1)
    ctx->r2 = ADD32(ctx->r3, 0X0);
    // 0x800FC074: jr          $v0
    // 0x800FC078: nop

    switch (jr_addend_800FC074 >> 2) {
        case 0: goto L_800FC08C; break;
        case 1: goto L_800FC08C; break;
        case 2: goto L_800FC07C; break;
        case 3: goto L_800FC08C; break;
        case 4: goto L_800FC08C; break;
        case 5: goto L_800FC090; break;
        case 6: goto L_800FC090; break;
        case 7: goto L_800FC07C; break;
        default: switch_error(__func__, 0x800FC074, 0x800A9138);
    }
    // 0x800FC078: nop

L_800FC07C:
    // 0x800FC07C: sb          $zero, 0x1($s0)
    MEM_B(0X1, ctx->r16) = 0;
    // 0x800FC080: sb          $zero, 0x210($s0)
    MEM_B(0X210, ctx->r16) = 0;
    // 0x800FC084: j           L_800FC090
    // 0x800FC088: sb          $zero, 0x211($s0)
    MEM_B(0X211, ctx->r16) = 0;
        goto L_800FC090;
    // 0x800FC088: sb          $zero, 0x211($s0)
    MEM_B(0X211, ctx->r16) = 0;
L_800FC08C:
    // 0x800FC08C: sb          $zero, 0x1($s0)
    MEM_B(0X1, ctx->r16) = 0;
L_800FC090:
    // 0x800FC090: jal         0x8006C940
    // 0x800FC094: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    getPlayerVehicleId(rdram, ctx);
        goto after_1;
    // 0x800FC094: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    after_1:
    // 0x800FC098: bne         $v0, $zero, L_800FC0BC
    if (ctx->r2 != 0) {
        // 0x800FC09C: nop
    
            goto L_800FC0BC;
    }
    // 0x800FC09C: nop

    // 0x800FC0A0: jal         0x800B585C
    // 0x800FC0A4: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    func_800B585C(rdram, ctx);
        goto after_2;
    // 0x800FC0A4: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    after_2:
    // 0x800FC0A8: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x800FC0AC: bne         $v0, $zero, L_800FC0BC
    if (ctx->r2 != 0) {
        // 0x800FC0B0: nop
    
            goto L_800FC0BC;
    }
    // 0x800FC0B0: nop

    // 0x800FC0B4: j           L_800FC0C8
    // 0x800FC0B8: sw          $zero, 0x24($s0)
    MEM_W(0X24, ctx->r16) = 0;
        goto L_800FC0C8;
    // 0x800FC0B8: sw          $zero, 0x24($s0)
    MEM_W(0X24, ctx->r16) = 0;
L_800FC0BC:
    // 0x800FC0BC: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800FC0C0: lwc1        $f0, -0x6EA8($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X6EA8);
    // 0x800FC0C4: swc1        $f0, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f0.u32l;
L_800FC0C8:
    // 0x800FC0C8: addu        $s1, $zero, $zero
    ctx->r17 = ADD32(0, 0);
    // 0x800FC0CC: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800FC0D0: addiu       $v1, $v0, -0x35D0
    ctx->r3 = ADD32(ctx->r2, -0X35D0);
L_800FC0D4:
    // 0x800FC0D4: sb          $zero, 0x274($v1)
    MEM_B(0X274, ctx->r3) = 0;
    // 0x800FC0D8: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x800FC0DC: sltiu       $v0, $s1, 0x2
    ctx->r2 = ctx->r17 < 0X2 ? 1 : 0;
    // 0x800FC0E0: bne         $v0, $zero, L_800FC0D4
    if (ctx->r2 != 0) {
        // 0x800FC0E4: addiu       $v1, $v1, 0x278
        ctx->r3 = ADD32(ctx->r3, 0X278);
            goto L_800FC0D4;
    }
    // 0x800FC0E4: addiu       $v1, $v1, 0x278
    ctx->r3 = ADD32(ctx->r3, 0X278);
    // 0x800FC0E8: lbu         $v0, 0x0($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X0);
    // 0x800FC0EC: lw          $ra, 0x20($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X20);
    // 0x800FC0F0: lw          $s3, 0x1C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X1C);
    // 0x800FC0F4: lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X18);
    // 0x800FC0F8: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x800FC0FC: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x800FC100: jr          $ra
    // 0x800FC104: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x800FC104: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_800FC108(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800FC108: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800FC10C: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x800FC110: addu        $s1, $zero, $zero
    ctx->r17 = ADD32(0, 0);
    // 0x800FC114: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800FC118: sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // 0x800FC11C: addiu       $s2, $v0, -0x35D0
    ctx->r18 = ADD32(ctx->r2, -0X35D0);
    // 0x800FC120: sw          $s4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r20;
    // 0x800FC124: addiu       $s4, $s2, 0x230
    ctx->r20 = ADD32(ctx->r18, 0X230);
    // 0x800FC128: lui         $v0, 0x800B
    ctx->r2 = S32(0X800B << 16);
    // 0x800FC12C: sw          $s3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r19;
    // 0x800FC130: addiu       $s3, $v0, -0x6EA0
    ctx->r19 = ADD32(ctx->r2, -0X6EA0);
    // 0x800FC134: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800FC138: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x800FC13C: andi        $v0, $s1, 0xFF
    ctx->r2 = ctx->r17 & 0XFF;
L_800FC140:
    // 0x800FC140: sll         $v1, $v0, 2
    ctx->r3 = S32(ctx->r2 << 2);
    // 0x800FC144: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x800FC148: sll         $v1, $v1, 4
    ctx->r3 = S32(ctx->r3 << 4);
    // 0x800FC14C: subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // 0x800FC150: sll         $v1, $v1, 3
    ctx->r3 = S32(ctx->r3 << 3);
    // 0x800FC154: addu        $v1, $v1, $s2
    ctx->r3 = ADD32(ctx->r3, ctx->r18);
    // 0x800FC158: lbu         $a0, 0x0($v1)
    ctx->r4 = MEM_BU(ctx->r3, 0X0);
    // 0x800FC15C: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x800FC160: beq         $a0, $v0, L_800FC170
    if (ctx->r4 == ctx->r2) {
        // 0x800FC164: addiu       $v0, $zero, 0x8
        ctx->r2 = ADD32(0, 0X8);
            goto L_800FC170;
    }
    // 0x800FC164: addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
    // 0x800FC168: bne         $a0, $v0, L_800FC18C
    if (ctx->r4 != ctx->r2) {
        // 0x800FC16C: andi        $v0, $s1, 0xFF
        ctx->r2 = ctx->r17 & 0XFF;
            goto L_800FC18C;
    }
    // 0x800FC16C: andi        $v0, $s1, 0xFF
    ctx->r2 = ctx->r17 & 0XFF;
L_800FC170:
    // 0x800FC170: lbu         $v0, 0x210($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X210);
    // 0x800FC174: beq         $v0, $zero, L_800FC18C
    if (ctx->r2 == 0) {
        // 0x800FC178: andi        $v0, $s1, 0xFF
        ctx->r2 = ctx->r17 & 0XFF;
            goto L_800FC18C;
    }
    // 0x800FC178: andi        $v0, $s1, 0xFF
    ctx->r2 = ctx->r17 & 0XFF;
    // 0x800FC17C: lhu         $a0, 0x212($v1)
    ctx->r4 = MEM_HU(ctx->r3, 0X212);
    // 0x800FC180: jal         0x8003F0C8
    // 0x800FC184: nop

    func_8003F0C8(rdram, ctx);
        goto after_0;
    // 0x800FC184: nop

    after_0:
    // 0x800FC188: andi        $v0, $s1, 0xFF
    ctx->r2 = ctx->r17 & 0XFF;
L_800FC18C:
    // 0x800FC18C: sll         $v1, $v0, 2
    ctx->r3 = S32(ctx->r2 << 2);
    // 0x800FC190: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x800FC194: sll         $v1, $v1, 4
    ctx->r3 = S32(ctx->r3 << 4);
    // 0x800FC198: subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // 0x800FC19C: sll         $v1, $v1, 3
    ctx->r3 = S32(ctx->r3 << 3);
    // 0x800FC1A0: addu        $s0, $v1, $s2
    ctx->r16 = ADD32(ctx->r3, ctx->r18);
    // 0x800FC1A4: lbu         $v0, 0x274($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X274);
    // 0x800FC1A8: beq         $v0, $zero, L_800FC1BC
    if (ctx->r2 == 0) {
        // 0x800FC1AC: nop
    
            goto L_800FC1BC;
    }
    // 0x800FC1AC: nop

    // 0x800FC1B0: jal         0x80098DE0
    // 0x800FC1B4: addu        $a0, $v1, $s4
    ctx->r4 = ADD32(ctx->r3, ctx->r20);
    func_80098DE0(rdram, ctx);
        goto after_1;
    // 0x800FC1B4: addu        $a0, $v1, $s4
    ctx->r4 = ADD32(ctx->r3, ctx->r20);
    after_1:
    // 0x800FC1B8: sb          $zero, 0x274($s0)
    MEM_B(0X274, ctx->r16) = 0;
L_800FC1BC:
    // 0x800FC1BC: lbu         $v0, 0x0($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X0);
    // 0x800FC1C0: addiu       $v1, $v0, -0x1
    ctx->r3 = ADD32(ctx->r2, -0X1);
    // 0x800FC1C4: sltiu       $v0, $v1, 0x8
    ctx->r2 = ctx->r3 < 0X8 ? 1 : 0;
    // 0x800FC1C8: beq         $v0, $zero, L_800FC1F4
    if (ctx->r2 == 0) {
        // 0x800FC1CC: sll         $v0, $v1, 2
        ctx->r2 = S32(ctx->r3 << 2);
            goto L_800FC1F4;
    }
    // 0x800FC1CC: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x800FC1D0: addu        $v0, $v0, $s3
    gpr jr_addend_800FC1D8 = ctx->r2;
    ctx->r2 = ADD32(ctx->r2, ctx->r19);
    // 0x800FC1D4: lw          $v0, 0x0($v0)
    ctx->r2 = ADD32(ctx->r2, 0X0);
    // 0x800FC1D8: jr          $v0
    // 0x800FC1DC: nop

    switch (jr_addend_800FC1D8 >> 2) {
        case 0: goto L_800FC1F0; break;
        case 1: goto L_800FC1F0; break;
        case 2: goto L_800FC1E0; break;
        case 3: goto L_800FC1F0; break;
        case 4: goto L_800FC1F0; break;
        case 5: goto L_800FC1F4; break;
        case 6: goto L_800FC1F4; break;
        case 7: goto L_800FC1E0; break;
        default: switch_error(__func__, 0x800FC1D8, 0x800A9160);
    }
    // 0x800FC1DC: nop

L_800FC1E0:
    // 0x800FC1E0: sb          $zero, 0x1($s0)
    MEM_B(0X1, ctx->r16) = 0;
    // 0x800FC1E4: sb          $zero, 0x210($s0)
    MEM_B(0X210, ctx->r16) = 0;
    // 0x800FC1E8: j           L_800FC1F4
    // 0x800FC1EC: sb          $zero, 0x211($s0)
    MEM_B(0X211, ctx->r16) = 0;
        goto L_800FC1F4;
    // 0x800FC1EC: sb          $zero, 0x211($s0)
    MEM_B(0X211, ctx->r16) = 0;
L_800FC1F0:
    // 0x800FC1F0: sb          $zero, 0x1($s0)
    MEM_B(0X1, ctx->r16) = 0;
L_800FC1F4:
    // 0x800FC1F4: jal         0x8006C940
    // 0x800FC1F8: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    getPlayerVehicleId(rdram, ctx);
        goto after_2;
    // 0x800FC1F8: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    after_2:
    // 0x800FC1FC: bne         $v0, $zero, L_800FC220
    if (ctx->r2 != 0) {
        // 0x800FC200: nop
    
            goto L_800FC220;
    }
    // 0x800FC200: nop

    // 0x800FC204: jal         0x800B585C
    // 0x800FC208: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    func_800B585C(rdram, ctx);
        goto after_3;
    // 0x800FC208: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    after_3:
    // 0x800FC20C: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x800FC210: bne         $v0, $zero, L_800FC220
    if (ctx->r2 != 0) {
        // 0x800FC214: nop
    
            goto L_800FC220;
    }
    // 0x800FC214: nop

    // 0x800FC218: j           L_800FC22C
    // 0x800FC21C: sw          $zero, 0x24($s0)
    MEM_W(0X24, ctx->r16) = 0;
        goto L_800FC22C;
    // 0x800FC21C: sw          $zero, 0x24($s0)
    MEM_W(0X24, ctx->r16) = 0;
L_800FC220:
    // 0x800FC220: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800FC224: lwc1        $f0, -0x6E80($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X6E80);
    // 0x800FC228: swc1        $f0, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f0.u32l;
L_800FC22C:
    // 0x800FC22C: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x800FC230: andi        $v0, $s1, 0xFF
    ctx->r2 = ctx->r17 & 0XFF;
    // 0x800FC234: sltiu       $v0, $v0, 0x2
    ctx->r2 = ctx->r2 < 0X2 ? 1 : 0;
    // 0x800FC238: bnel        $v0, $zero, L_800FC140
    if (ctx->r2 != 0) {
        // 0x800FC23C: andi        $v0, $s1, 0xFF
        ctx->r2 = ctx->r17 & 0XFF;
            goto L_800FC140;
    }
    goto skip_0;
    // 0x800FC23C: andi        $v0, $s1, 0xFF
    ctx->r2 = ctx->r17 & 0XFF;
    skip_0:
    // 0x800FC240: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800FC244: lw          $s4, 0x20($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X20);
    // 0x800FC248: lw          $s3, 0x1C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X1C);
    // 0x800FC24C: lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X18);
    // 0x800FC250: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x800FC254: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x800FC258: jr          $ra
    // 0x800FC25C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x800FC25C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_800FC260(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800FC260: addiu       $sp, $sp, -0x98
    ctx->r29 = ADD32(ctx->r29, -0X98);
    // 0x800FC264: sw          $s4, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r20;
    // 0x800FC268: addu        $s4, $a0, $zero
    ctx->r20 = ADD32(ctx->r4, 0);
    // 0x800FC26C: sw          $s3, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r19;
    // 0x800FC270: ori         $s3, $zero, 0xFFFF
    ctx->r19 = 0 | 0XFFFF;
    // 0x800FC274: sw          $s7, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r23;
    // 0x800FC278: addu        $s7, $zero, $zero
    ctx->r23 = ADD32(0, 0);
    // 0x800FC27C: sw          $s1, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r17;
    // 0x800FC280: addu        $s1, $zero, $zero
    ctx->r17 = ADD32(0, 0);
    // 0x800FC284: sw          $s6, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r22;
    // 0x800FC288: addu        $s6, $a1, $zero
    ctx->r22 = ADD32(ctx->r5, 0);
    // 0x800FC28C: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x800FC290: lhu         $v0, -0x4B4C($a0)
    ctx->r2 = MEM_HU(ctx->r4, -0X4B4C);
    // 0x800FC294: ori         $v1, $zero, 0xFFFF
    ctx->r3 = 0 | 0XFFFF;
    // 0x800FC298: sw          $ra, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r31;
    // 0x800FC29C: sw          $fp, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r30;
    // 0x800FC2A0: sw          $s5, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r21;
    // 0x800FC2A4: sw          $s2, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r18;
    // 0x800FC2A8: sw          $s0, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r16;
    // 0x800FC2AC: sdc1        $f22, 0x90($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X90, ctx->r29);
    // 0x800FC2B0: sdc1        $f20, 0x88($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X88, ctx->r29);
    // 0x800FC2B4: sw          $a2, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->r6;
    // 0x800FC2B8: beq         $v0, $v1, L_800FC480
    if (ctx->r2 == ctx->r3) {
        // 0x800FC2BC: sw          $a3, 0xA4($sp)
        MEM_W(0XA4, ctx->r29) = ctx->r7;
            goto L_800FC480;
    }
    // 0x800FC2BC: sw          $a3, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->r7;
    // 0x800FC2C0: addu        $s5, $v1, $zero
    ctx->r21 = ADD32(ctx->r3, 0);
    // 0x800FC2C4: addiu       $s2, $a0, -0x4B4C
    ctx->r18 = ADD32(ctx->r4, -0X4B4C);
L_800FC2C8:
    // 0x800FC2C8: lui         $t0, 0x8014
    ctx->r8 = S32(0X8014 << 16);
    // 0x800FC2CC: lhu         $v0, 0x0($s2)
    ctx->r2 = MEM_HU(ctx->r18, 0X0);
    // 0x800FC2D0: addiu       $t0, $t0, -0x6AA0
    ctx->r8 = ADD32(ctx->r8, -0X6AA0);
    // 0x800FC2D4: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x800FC2D8: addu        $v0, $v0, $t0
    ctx->r2 = ADD32(ctx->r2, ctx->r8);
    // 0x800FC2DC: lhu         $a0, 0x0($v0)
    ctx->r4 = MEM_HU(ctx->r2, 0X0);
    // 0x800FC2E0: jal         0x8003FC28
    // 0x800FC2E4: addiu       $a1, $sp, 0x50
    ctx->r5 = ADD32(ctx->r29, 0X50);
    func_8003FC28(rdram, ctx);
        goto after_0;
    // 0x800FC2E4: addiu       $a1, $sp, 0x50
    ctx->r5 = ADD32(ctx->r29, 0X50);
    after_0:
    // 0x800FC2E8: j           L_800FC464
    // 0x800FC2EC: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
        goto L_800FC464;
    // 0x800FC2EC: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
L_800FC2F0:
    // 0x800FC2F0: jal         0x8004013C
    // 0x800FC2F4: andi        $a0, $s0, 0xFFFF
    ctx->r4 = ctx->r16 & 0XFFFF;
    func_8004013C(rdram, ctx);
        goto after_1;
    // 0x800FC2F4: andi        $a0, $s0, 0xFFFF
    ctx->r4 = ctx->r16 & 0XFFFF;
    after_1:
    // 0x800FC2F8: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // 0x800FC2FC: lhu         $v0, 0x14($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X14);
    // 0x800FC300: andi        $v0, $v0, 0x100
    ctx->r2 = ctx->r2 & 0X100;
    // 0x800FC304: bne         $v0, $zero, L_800FC458
    if (ctx->r2 != 0) {
        // 0x800FC308: nop
    
            goto L_800FC458;
    }
    // 0x800FC308: nop

    // 0x800FC30C: lw          $a0, 0xC($v1)
    ctx->r4 = MEM_W(ctx->r3, 0XC);
    // 0x800FC310: beq         $a0, $zero, L_800FC328
    if (ctx->r4 == 0) {
        // 0x800FC314: nop
    
            goto L_800FC328;
    }
    // 0x800FC314: nop

    // 0x800FC318: jal         0x8006AC7C
    // 0x800FC31C: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    func_8006AC7C(rdram, ctx);
        goto after_2;
    // 0x800FC31C: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    after_2:
    // 0x800FC320: j           L_800FC344
    // 0x800FC324: nop

        goto L_800FC344;
    // 0x800FC324: nop

L_800FC328:
    // 0x800FC328: lw          $v0, 0x8($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X8);
    // 0x800FC32C: lw          $t1, 0x0($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X0);
    // 0x800FC330: lw          $t2, 0x4($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X4);
    // 0x800FC334: lw          $t3, 0x8($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X8);
    // 0x800FC338: sw          $t1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r9;
    // 0x800FC33C: sw          $t2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r10;
    // 0x800FC340: sw          $t3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r11;
L_800FC344:
    // 0x800FC344: lwc1        $f0, 0x20($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X20);
    // 0x800FC348: lwc1        $f2, 0x0($s4)
    ctx->f2.u32l = MEM_W(ctx->r20, 0X0);
    // 0x800FC34C: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x800FC350: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    // 0x800FC354: lwc1        $f0, 0x24($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X24);
    // 0x800FC358: lwc1        $f2, 0x4($s4)
    ctx->f2.u32l = MEM_W(ctx->r20, 0X4);
    // 0x800FC35C: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x800FC360: lwc1        $f2, 0x28($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X28);
    // 0x800FC364: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    // 0x800FC368: lwc1        $f0, 0x8($s4)
    ctx->f0.u32l = MEM_W(ctx->r20, 0X8);
    // 0x800FC36C: sub.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl - ctx->f0.fl;
    // 0x800FC370: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    // 0x800FC374: jal         0x8001CF2C
    // 0x800FC378: swc1        $f2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f2.u32l;
    func_8001CF2C(rdram, ctx);
        goto after_3;
    // 0x800FC378: swc1        $f2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f2.u32l;
    after_3:
    // 0x800FC37C: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x800FC380: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x800FC384: c.lt.s      $f2, $f20
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f2.fl < ctx->f20.fl;
    // 0x800FC388: nop

    // 0x800FC38C: bc1f        L_800FC458
    if (!c1cs) {
        // 0x800FC390: nop
    
            goto L_800FC458;
    }
    // 0x800FC390: nop

    // 0x800FC394: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800FC398: lwc1        $f0, -0x6E7C($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X6E7C);
    // 0x800FC39C: c.lt.s      $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f20.fl < ctx->f0.fl;
    // 0x800FC3A0: nop

    // 0x800FC3A4: bc1f        L_800FC458
    if (!c1cs) {
        // 0x800FC3A8: addiu       $a0, $sp, 0x10
        ctx->r4 = ADD32(ctx->r29, 0X10);
            goto L_800FC458;
    }
    // 0x800FC3A8: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    // 0x800FC3AC: addiu       $a1, $s4, 0xC
    ctx->r5 = ADD32(ctx->r20, 0XC);
    // 0x800FC3B0: lwc1        $f0, 0x10($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X10);
    // 0x800FC3B4: lwc1        $f2, 0x18($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X18);
    // 0x800FC3B8: div.s       $f0, $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f20.fl);
    // 0x800FC3BC: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    // 0x800FC3C0: lwc1        $f0, 0x14($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X14);
    // 0x800FC3C4: div.s       $f2, $f2, $f20
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f2.fl = DIV_S(ctx->f2.fl, ctx->f20.fl);
    // 0x800FC3C8: swc1        $f2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f2.u32l;
    // 0x800FC3CC: div.s       $f0, $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f20.fl);
    // 0x800FC3D0: jal         0x8001CFE8
    // 0x800FC3D4: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    func_8001CFE8(rdram, ctx);
        goto after_4;
    // 0x800FC3D4: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    after_4:
    // 0x800FC3D8: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800FC3DC: lwc1        $f2, -0x6E78($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X6E78);
    // 0x800FC3E0: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x800FC3E4: nop

    // 0x800FC3E8: bc1f        L_800FC458
    if (!c1cs) {
        // 0x800FC3EC: andi        $v1, $s0, 0xFFFF
        ctx->r3 = ctx->r16 & 0XFFFF;
            goto L_800FC458;
    }
    // 0x800FC3EC: andi        $v1, $s0, 0xFFFF
    ctx->r3 = ctx->r16 & 0XFFFF;
    // 0x800FC3F0: andi        $v0, $s6, 0xFFFF
    ctx->r2 = ctx->r22 & 0XFFFF;
    // 0x800FC3F4: bne         $v1, $v0, L_800FC41C
    if (ctx->r3 != ctx->r2) {
        // 0x800FC3F8: andi        $v0, $s3, 0xFFFF
        ctx->r2 = ctx->r19 & 0XFFFF;
            goto L_800FC41C;
    }
    // 0x800FC3F8: andi        $v0, $s3, 0xFFFF
    ctx->r2 = ctx->r19 & 0XFFFF;
    // 0x800FC3FC: addiu       $s7, $zero, 0x1
    ctx->r23 = ADD32(0, 0X1);
    // 0x800FC400: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x800FC404: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
    // 0x800FC408: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
    // 0x800FC40C: sw          $t0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r8;
    // 0x800FC410: sw          $t1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r9;
    // 0x800FC414: sw          $t2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r10;
    // 0x800FC418: addu        $fp, $s1, $zero
    ctx->r30 = ADD32(ctx->r17, 0);
L_800FC41C:
    // 0x800FC41C: beql        $v0, $s5, L_800FC438
    if (ctx->r2 == ctx->r21) {
        // 0x800FC420: addu        $s3, $s0, $zero
        ctx->r19 = ADD32(ctx->r16, 0);
            goto L_800FC438;
    }
    goto skip_0;
    // 0x800FC420: addu        $s3, $s0, $zero
    ctx->r19 = ADD32(ctx->r16, 0);
    skip_0:
    // 0x800FC424: c.lt.s      $f22, $f20
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f22.fl < ctx->f20.fl;
    // 0x800FC428: nop

    // 0x800FC42C: bc1t        L_800FC458
    if (c1cs) {
        // 0x800FC430: nop
    
            goto L_800FC458;
    }
    // 0x800FC430: nop

    // 0x800FC434: addu        $s3, $s0, $zero
    ctx->r19 = ADD32(ctx->r16, 0);
L_800FC438:
    // 0x800FC438: mov.s       $f22, $f20
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 20);
    ctx->f22.fl = ctx->f20.fl;
    // 0x800FC43C: lw          $t4, 0x20($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X20);
    // 0x800FC440: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x800FC444: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x800FC448: sw          $t4, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r12;
    // 0x800FC44C: sw          $t0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r8;
    // 0x800FC450: sw          $t1, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r9;
    // 0x800FC454: sb          $s1, 0x58($sp)
    MEM_B(0X58, ctx->r29) = ctx->r17;
L_800FC458:
    // 0x800FC458: jal         0x8003EEF4
    // 0x800FC45C: addiu       $a0, $sp, 0x50
    ctx->r4 = ADD32(ctx->r29, 0X50);
    func_8003EEF4(rdram, ctx);
        goto after_5;
    // 0x800FC45C: addiu       $a0, $sp, 0x50
    ctx->r4 = ADD32(ctx->r29, 0X50);
    after_5:
    // 0x800FC460: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
L_800FC464:
    // 0x800FC464: andi        $v0, $s0, 0xFFFF
    ctx->r2 = ctx->r16 & 0XFFFF;
    // 0x800FC468: bne         $v0, $s5, L_800FC2F0
    if (ctx->r2 != ctx->r21) {
        // 0x800FC46C: nop
    
            goto L_800FC2F0;
    }
    // 0x800FC46C: nop

    // 0x800FC470: addiu       $s2, $s2, 0x2
    ctx->r18 = ADD32(ctx->r18, 0X2);
    // 0x800FC474: lhu         $v0, 0x0($s2)
    ctx->r2 = MEM_HU(ctx->r18, 0X0);
    // 0x800FC478: bne         $v0, $s5, L_800FC2C8
    if (ctx->r2 != ctx->r21) {
        // 0x800FC47C: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_800FC2C8;
    }
    // 0x800FC47C: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
L_800FC480:
    // 0x800FC480: andi        $v0, $s7, 0xFF
    ctx->r2 = ctx->r23 & 0XFF;
    // 0x800FC484: beq         $v0, $zero, L_800FC4EC
    if (ctx->r2 == 0) {
        // 0x800FC488: andi        $v0, $s3, 0xFFFF
        ctx->r2 = ctx->r19 & 0XFFFF;
            goto L_800FC4EC;
    }
    // 0x800FC488: andi        $v0, $s3, 0xFFFF
    ctx->r2 = ctx->r19 & 0XFFFF;
    // 0x800FC48C: andi        $a1, $s6, 0xFFFF
    ctx->r5 = ctx->r22 & 0XFFFF;
    // 0x800FC490: beq         $v0, $a1, L_800FC4F0
    if (ctx->r2 == ctx->r5) {
        // 0x800FC494: andi        $v1, $s3, 0xFFFF
        ctx->r3 = ctx->r19 & 0XFFFF;
            goto L_800FC4F0;
    }
    // 0x800FC494: andi        $v1, $s3, 0xFFFF
    ctx->r3 = ctx->r19 & 0XFFFF;
    // 0x800FC498: lw          $t3, 0xA4($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XA4);
    // 0x800FC49C: lwc1        $f0, 0x214($t3)
    ctx->f0.u32l = MEM_W(ctx->r11, 0X214);
    // 0x800FC4A0: lwc1        $f2, 0xAC($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0XAC);
    // 0x800FC4A4: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x800FC4A8: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800FC4AC: lwc1        $f2, -0x6E74($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X6E74);
    // 0x800FC4B0: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x800FC4B4: nop

    // 0x800FC4B8: bc1f        L_800FC4F0
    if (!c1cs) {
        // 0x800FC4BC: swc1        $f0, 0x214($t3)
        MEM_W(0X214, ctx->r11) = ctx->f0.u32l;
            goto L_800FC4F0;
    }
    // 0x800FC4BC: swc1        $f0, 0x214($t3)
    MEM_W(0X214, ctx->r11) = ctx->f0.u32l;
    // 0x800FC4C0: lw          $t4, 0xA0($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XA0);
    // 0x800FC4C4: lw          $t0, 0x30($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X30);
    // 0x800FC4C8: lw          $t1, 0x34($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X34);
    // 0x800FC4CC: lw          $t2, 0x38($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X38);
    // 0x800FC4D0: sw          $t0, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r8;
    // 0x800FC4D4: sw          $t1, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r9;
    // 0x800FC4D8: sw          $t2, 0x8($t4)
    MEM_W(0X8, ctx->r12) = ctx->r10;
    // 0x800FC4DC: lw          $t4, 0xA8($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XA8);
    // 0x800FC4E0: addu        $v0, $a1, $zero
    ctx->r2 = ADD32(ctx->r5, 0);
    // 0x800FC4E4: j           L_800FC52C
    // 0x800FC4E8: sb          $fp, 0x0($t4)
    MEM_B(0X0, ctx->r12) = ctx->r30;
        goto L_800FC52C;
    // 0x800FC4E8: sb          $fp, 0x0($t4)
    MEM_B(0X0, ctx->r12) = ctx->r30;
L_800FC4EC:
    // 0x800FC4EC: andi        $v1, $s3, 0xFFFF
    ctx->r3 = ctx->r19 & 0XFFFF;
L_800FC4F0:
    // 0x800FC4F0: lw          $t0, 0xA4($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XA4);
    // 0x800FC4F4: ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
    // 0x800FC4F8: beq         $v1, $v0, L_800FC528
    if (ctx->r3 == ctx->r2) {
        // 0x800FC4FC: sw          $zero, 0x214($t0)
        MEM_W(0X214, ctx->r8) = 0;
            goto L_800FC528;
    }
    // 0x800FC4FC: sw          $zero, 0x214($t0)
    MEM_W(0X214, ctx->r8) = 0;
    // 0x800FC500: lw          $t1, 0xA0($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XA0);
    // 0x800FC504: lw          $t2, 0x40($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X40);
    // 0x800FC508: lw          $t3, 0x44($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X44);
    // 0x800FC50C: lw          $t4, 0x48($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X48);
    // 0x800FC510: sw          $t2, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r10;
    // 0x800FC514: sw          $t3, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r11;
    // 0x800FC518: sw          $t4, 0x8($t1)
    MEM_W(0X8, ctx->r9) = ctx->r12;
    // 0x800FC51C: lbu         $t2, 0x58($sp)
    ctx->r10 = MEM_BU(ctx->r29, 0X58);
    // 0x800FC520: lw          $t1, 0xA8($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XA8);
    // 0x800FC524: sb          $t2, 0x0($t1)
    MEM_B(0X0, ctx->r9) = ctx->r10;
L_800FC528:
    // 0x800FC528: addu        $v0, $v1, $zero
    ctx->r2 = ADD32(ctx->r3, 0);
L_800FC52C:
    // 0x800FC52C: lw          $ra, 0x84($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X84);
    // 0x800FC530: lw          $fp, 0x80($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X80);
    // 0x800FC534: lw          $s7, 0x7C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X7C);
    // 0x800FC538: lw          $s6, 0x78($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X78);
    // 0x800FC53C: lw          $s5, 0x74($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X74);
    // 0x800FC540: lw          $s4, 0x70($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X70);
    // 0x800FC544: lw          $s3, 0x6C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X6C);
    // 0x800FC548: lw          $s2, 0x68($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X68);
    // 0x800FC54C: lw          $s1, 0x64($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X64);
    // 0x800FC550: lw          $s0, 0x60($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X60);
    // 0x800FC554: ldc1        $f22, 0x90($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X90);
    // 0x800FC558: ldc1        $f20, 0x88($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X88);
    // 0x800FC55C: jr          $ra
    // 0x800FC560: addiu       $sp, $sp, 0x98
    ctx->r29 = ADD32(ctx->r29, 0X98);
    return;
    // 0x800FC560: addiu       $sp, $sp, 0x98
    ctx->r29 = ADD32(ctx->r29, 0X98);
;}
RECOMP_FUNC void func_800FC564(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800FC564: addiu       $sp, $sp, -0x110
    ctx->r29 = ADD32(ctx->r29, -0X110);
    // 0x800FC568: sw          $s1, 0xE4($sp)
    MEM_W(0XE4, ctx->r29) = ctx->r17;
    // 0x800FC56C: addu        $s1, $a0, $zero
    ctx->r17 = ADD32(ctx->r4, 0);
    // 0x800FC570: sw          $s0, 0xE0($sp)
    MEM_W(0XE0, ctx->r29) = ctx->r16;
    // 0x800FC574: addu        $s0, $a1, $zero
    ctx->r16 = ADD32(ctx->r5, 0);
    // 0x800FC578: addu        $a0, $a2, $zero
    ctx->r4 = ADD32(ctx->r6, 0);
    // 0x800FC57C: lui         $a1, 0x800B
    ctx->r5 = S32(0X800B << 16);
    // 0x800FC580: addiu       $a1, $a1, -0x6E70
    ctx->r5 = ADD32(ctx->r5, -0X6E70);
    // 0x800FC584: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // 0x800FC588: addiu       $a3, $sp, 0xB0
    ctx->r7 = ADD32(ctx->r29, 0XB0);
    // 0x800FC58C: addiu       $v0, $sp, 0x80
    ctx->r2 = ADD32(ctx->r29, 0X80);
    // 0x800FC590: sw          $ra, 0xE8($sp)
    MEM_W(0XE8, ctx->r29) = ctx->r31;
    // 0x800FC594: sdc1        $f26, 0x108($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X108, ctx->r29);
    // 0x800FC598: sdc1        $f24, 0x100($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X100, ctx->r29);
    // 0x800FC59C: sdc1        $f22, 0xF8($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0XF8, ctx->r29);
    // 0x800FC5A0: sdc1        $f20, 0xF0($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0XF0, ctx->r29);
    // 0x800FC5A4: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // 0x800FC5A8: jal         0x80058360
    // 0x800FC5AC: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    func_80058360(rdram, ctx);
        goto after_0;
    // 0x800FC5AC: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    after_0:
    // 0x800FC5B0: lw          $v1, 0xB0($sp)
    ctx->r3 = MEM_W(ctx->r29, 0XB0);
    // 0x800FC5B4: lw          $t0, 0xB4($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XB4);
    // 0x800FC5B8: lw          $t1, 0xB8($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XB8);
    // 0x800FC5BC: sw          $v1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r3;
    // 0x800FC5C0: sw          $t0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r8;
    // 0x800FC5C4: sw          $t1, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r9;
    // 0x800FC5C8: lwc1        $f0, 0xC($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0XC);
    // 0x800FC5CC: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800FC5D0: lwc1        $f4, -0x6E6C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X6E6C);
    // 0x800FC5D4: mul.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x800FC5D8: lwc1        $f2, 0x24($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X24);
    // 0x800FC5DC: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x800FC5E0: swc1        $f0, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f0.u32l;
    // 0x800FC5E4: lwc1        $f0, 0x10($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X10);
    // 0x800FC5E8: mul.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x800FC5EC: lwc1        $f2, 0x28($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X28);
    // 0x800FC5F0: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x800FC5F4: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800FC5F8: lwc1        $f2, -0x6E68($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X6E68);
    // 0x800FC5FC: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x800FC600: swc1        $f0, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f0.u32l;
    // 0x800FC604: lwc1        $f0, 0x14($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X14);
    // 0x800FC608: mul.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x800FC60C: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x800FC610: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800FC614: lwc1        $f22, -0x6E64($at)
    ctx->f22.u32l = MEM_W(ctx->r1, -0X6E64);
    // 0x800FC618: lwc1        $f2, 0x2C($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x800FC61C: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800FC620: lwc1        $f26, -0x6E60($at)
    ctx->f26.u32l = MEM_W(ctx->r1, -0X6E60);
    // 0x800FC624: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x800FC628: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800FC62C: lwc1        $f24, -0x6E5C($at)
    ctx->f24.u32l = MEM_W(ctx->r1, -0X6E5C);
    // 0x800FC630: lui         $s0, 0x8014
    ctx->r16 = S32(0X8014 << 16);
    // 0x800FC634: swc1        $f0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f0.u32l;
L_800FC638:
    // 0x800FC638: lwc1        $f2, 0x60($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X60);
    // 0x800FC63C: mul.s       $f2, $f2, $f22
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f22.fl);
    // 0x800FC640: lwc1        $f4, 0x64($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X64);
    // 0x800FC644: mul.s       $f8, $f4, $f22
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f22.fl);
    // 0x800FC648: lwc1        $f0, 0x68($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X68);
    // 0x800FC64C: mul.s       $f0, $f0, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f22.fl);
    // 0x800FC650: add.s       $f4, $f4, $f26
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f26.fl;
    // 0x800FC654: lwc1        $f10, 0x40($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X40);
    // 0x800FC658: add.s       $f2, $f10, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = ctx->f10.fl + ctx->f2.fl;
    // 0x800FC65C: lwc1        $f6, 0x44($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X44);
    // 0x800FC660: addiu       $a0, $sp, 0x40
    ctx->r4 = ADD32(ctx->r29, 0X40);
    // 0x800FC664: add.s       $f8, $f6, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x800FC668: lwc1        $f12, 0x48($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X48);
    // 0x800FC66C: addiu       $a1, $sp, 0x70
    ctx->r5 = ADD32(ctx->r29, 0X70);
    // 0x800FC670: add.s       $f0, $f12, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f12.fl + ctx->f0.fl;
    // 0x800FC674: addiu       $a2, $s0, -0x7FA8
    ctx->r6 = ADD32(ctx->r16, -0X7FA8);
    // 0x800FC678: addiu       $a3, $sp, 0x18
    ctx->r7 = ADD32(ctx->r29, 0X18);
    // 0x800FC67C: sub.s       $f10, $f2, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = ctx->f2.fl - ctx->f10.fl;
    // 0x800FC680: swc1        $f4, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f4.u32l;
    // 0x800FC684: swc1        $f2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f2.u32l;
    // 0x800FC688: sub.s       $f6, $f8, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f6.fl = ctx->f8.fl - ctx->f6.fl;
    // 0x800FC68C: swc1        $f8, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f8.u32l;
    // 0x800FC690: swc1        $f0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f0.u32l;
    // 0x800FC694: sub.s       $f0, $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f12.fl;
    // 0x800FC698: swc1        $f10, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->f10.u32l;
    // 0x800FC69C: swc1        $f6, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->f6.u32l;
    // 0x800FC6A0: jal         0x80068D5C
    // 0x800FC6A4: swc1        $f0, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->f0.u32l;
    func_80068D5C(rdram, ctx);
        goto after_1;
    // 0x800FC6A4: swc1        $f0, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->f0.u32l;
    after_1:
    // 0x800FC6A8: beq         $v0, $zero, L_800FC6D0
    if (ctx->r2 == 0) {
        // 0x800FC6AC: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_800FC6D0;
    }
    // 0x800FC6AC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800FC6B0: lw          $v1, 0x18($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X18);
    // 0x800FC6B4: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x800FC6B8: lw          $t1, 0x20($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X20);
    // 0x800FC6BC: sw          $v1, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r3;
    // 0x800FC6C0: sw          $t0, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->r8;
    // 0x800FC6C4: sw          $t1, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->r9;
    // 0x800FC6C8: j           L_800FC6FC
    // 0x800FC6CC: nop

        goto L_800FC6FC;
    // 0x800FC6CC: nop

L_800FC6D0:
    // 0x800FC6D0: add.s       $f20, $f20, $f22
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f20.fl = ctx->f20.fl + ctx->f22.fl;
    // 0x800FC6D4: lw          $v1, 0x50($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X50);
    // 0x800FC6D8: lw          $t0, 0x54($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X54);
    // 0x800FC6DC: lw          $t1, 0x58($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X58);
    // 0x800FC6E0: sw          $v1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r3;
    // 0x800FC6E4: sw          $t0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r8;
    // 0x800FC6E8: sw          $t1, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r9;
    // 0x800FC6EC: c.lt.s      $f20, $f24
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 24);
    c1cs = ctx->f20.fl < ctx->f24.fl;
    // 0x800FC6F0: nop

    // 0x800FC6F4: bc1t        L_800FC638
    if (c1cs) {
        // 0x800FC6F8: addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
            goto L_800FC638;
    }
    // 0x800FC6F8: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_800FC6FC:
    // 0x800FC6FC: lw          $ra, 0xE8($sp)
    ctx->r31 = MEM_W(ctx->r29, 0XE8);
    // 0x800FC700: lw          $s1, 0xE4($sp)
    ctx->r17 = MEM_W(ctx->r29, 0XE4);
    // 0x800FC704: lw          $s0, 0xE0($sp)
    ctx->r16 = MEM_W(ctx->r29, 0XE0);
    // 0x800FC708: ldc1        $f26, 0x108($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X108);
    // 0x800FC70C: ldc1        $f24, 0x100($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X100);
    // 0x800FC710: ldc1        $f22, 0xF8($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0XF8);
    // 0x800FC714: ldc1        $f20, 0xF0($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0XF0);
    // 0x800FC718: jr          $ra
    // 0x800FC71C: addiu       $sp, $sp, 0x110
    ctx->r29 = ADD32(ctx->r29, 0X110);
    return;
    // 0x800FC71C: addiu       $sp, $sp, 0x110
    ctx->r29 = ADD32(ctx->r29, 0X110);
;}
RECOMP_FUNC void func_800FC720(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800FC720: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x800FC724: sw          $s4, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r20;
    // 0x800FC728: addu        $s4, $a2, $zero
    ctx->r20 = ADD32(ctx->r6, 0);
    // 0x800FC72C: sw          $s3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r19;
    // 0x800FC730: addu        $s3, $a3, $zero
    ctx->r19 = ADD32(ctx->r7, 0);
    // 0x800FC734: sw          $s5, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r21;
    // 0x800FC738: addu        $s5, $zero, $zero
    ctx->r21 = ADD32(0, 0);
    // 0x800FC73C: andi        $v1, $a0, 0xFF
    ctx->r3 = ctx->r4 & 0XFF;
    // 0x800FC740: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x800FC744: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x800FC748: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800FC74C: sll         $v0, $v0, 4
    ctx->r2 = S32(ctx->r2 << 4);
    // 0x800FC750: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x800FC754: sdc1        $f20, 0x60($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X60, ctx->r29);
    // 0x800FC758: mtc1        $a1, $f20
    ctx->f20.u32l = ctx->r5;
    // 0x800FC75C: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x800FC760: lw          $a1, 0xB4C($a1)
    ctx->r5 = MEM_W(ctx->r5, 0XB4C);
    // 0x800FC764: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x800FC768: sw          $s2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r18;
    // 0x800FC76C: lbu         $s2, 0x7B($sp)
    ctx->r18 = MEM_BU(ctx->r29, 0X7B);
    // 0x800FC770: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
    // 0x800FC774: sw          $s6, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r22;
    // 0x800FC778: lhu         $s6, 0x82($sp)
    ctx->r22 = MEM_HU(ctx->r29, 0X82);
    // 0x800FC77C: addiu       $v1, $v1, -0x35D0
    ctx->r3 = ADD32(ctx->r3, -0X35D0);
    // 0x800FC780: sw          $s1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r17;
    // 0x800FC784: addu        $s1, $v0, $v1
    ctx->r17 = ADD32(ctx->r2, ctx->r3);
    // 0x800FC788: sw          $ra, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r31;
    // 0x800FC78C: sw          $s0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r16;
    // 0x800FC790: srl         $a1, $a1, 7
    ctx->r5 = S32(U32(ctx->r5) >> 7);
    // 0x800FC794: andi        $a1, $a1, 0x1
    ctx->r5 = ctx->r5 & 0X1;
    // 0x800FC798: jal         0x8006C940
    // 0x800FC79C: sb          $a1, 0x5($s1)
    MEM_B(0X5, ctx->r17) = ctx->r5;
    getPlayerVehicleId(rdram, ctx);
        goto after_0;
    // 0x800FC79C: sb          $a1, 0x5($s1)
    MEM_B(0X5, ctx->r17) = ctx->r5;
    after_0:
    // 0x800FC7A0: bne         $v0, $zero, L_800FC7FC
    if (ctx->r2 != 0) {
        // 0x800FC7A4: nop
    
            goto L_800FC7FC;
    }
    // 0x800FC7A4: nop

    // 0x800FC7A8: jal         0x800B585C
    // 0x800FC7AC: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    func_800B585C(rdram, ctx);
        goto after_1;
    // 0x800FC7AC: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    after_1:
    // 0x800FC7B0: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x800FC7B4: bne         $v0, $zero, L_800FC7FC
    if (ctx->r2 != 0) {
        // 0x800FC7B8: nop
    
            goto L_800FC7FC;
    }
    // 0x800FC7B8: nop

    // 0x800FC7BC: lwc1        $f2, 0x24($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0X24);
    // 0x800FC7C0: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800FC7C4: c.lt.s      $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f4.fl < ctx->f2.fl;
    // 0x800FC7C8: nop

    // 0x800FC7CC: bc1f        L_800FC840
    if (!c1cs) {
        // 0x800FC7D0: addiu       $s0, $zero, 0x1
        ctx->r16 = ADD32(0, 0X1);
            goto L_800FC840;
    }
    // 0x800FC7D0: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
    // 0x800FC7D4: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800FC7D8: lwc1        $f0, -0x6E58($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X6E58);
    // 0x800FC7DC: mul.s       $f0, $f20, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = MUL_S(ctx->f20.fl, ctx->f0.fl);
    // 0x800FC7E0: sub.s       $f0, $f2, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f2.fl - ctx->f0.fl;
    // 0x800FC7E4: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x800FC7E8: nop

    // 0x800FC7EC: bc1f        L_800FC840
    if (!c1cs) {
        // 0x800FC7F0: swc1        $f0, 0x24($s1)
        MEM_W(0X24, ctx->r17) = ctx->f0.u32l;
            goto L_800FC840;
    }
    // 0x800FC7F0: swc1        $f0, 0x24($s1)
    MEM_W(0X24, ctx->r17) = ctx->f0.u32l;
    // 0x800FC7F4: j           L_800FC840
    // 0x800FC7F8: swc1        $f4, 0x24($s1)
    MEM_W(0X24, ctx->r17) = ctx->f4.u32l;
        goto L_800FC840;
    // 0x800FC7F8: swc1        $f4, 0x24($s1)
    MEM_W(0X24, ctx->r17) = ctx->f4.u32l;
L_800FC7FC:
    // 0x800FC7FC: lwc1        $f2, 0x24($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0X24);
    // 0x800FC800: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800FC804: lwc1        $f4, -0x6E54($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X6E54);
    // 0x800FC808: c.lt.s      $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f2.fl < ctx->f4.fl;
    // 0x800FC80C: nop

    // 0x800FC810: bc1f        L_800FC840
    if (!c1cs) {
        // 0x800FC814: addu        $s0, $zero, $zero
        ctx->r16 = ADD32(0, 0);
            goto L_800FC840;
    }
    // 0x800FC814: addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
    // 0x800FC818: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800FC81C: lwc1        $f0, -0x6E50($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X6E50);
    // 0x800FC820: mul.s       $f0, $f20, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = MUL_S(ctx->f20.fl, ctx->f0.fl);
    // 0x800FC824: add.s       $f0, $f2, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x800FC828: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x800FC82C: nop

    // 0x800FC830: bc1f        L_800FC840
    if (!c1cs) {
        // 0x800FC834: swc1        $f0, 0x24($s1)
        MEM_W(0X24, ctx->r17) = ctx->f0.u32l;
            goto L_800FC840;
    }
    // 0x800FC834: swc1        $f0, 0x24($s1)
    MEM_W(0X24, ctx->r17) = ctx->f0.u32l;
    // 0x800FC838: swc1        $f4, 0x24($s1)
    MEM_W(0X24, ctx->r17) = ctx->f4.u32l;
    // 0x800FC83C: addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
L_800FC840:
    // 0x800FC840: lbu         $v0, 0x0($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X0);
    // 0x800FC844: addiu       $v1, $v0, -0x1
    ctx->r3 = ADD32(ctx->r2, -0X1);
    // 0x800FC848: sltiu       $v0, $v1, 0x9
    ctx->r2 = ctx->r3 < 0X9 ? 1 : 0;
    // 0x800FC84C: beq         $v0, $zero, L_800FD2C4
    if (ctx->r2 == 0) {
        // 0x800FC850: lui         $v0, 0x800B
        ctx->r2 = S32(0X800B << 16);
            goto L_800FD2C4;
    }
    // 0x800FC850: lui         $v0, 0x800B
    ctx->r2 = S32(0X800B << 16);
    // 0x800FC854: addiu       $v0, $v0, -0x6E48
    ctx->r2 = ADD32(ctx->r2, -0X6E48);
    // 0x800FC858: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x800FC85C: addu        $v1, $v1, $v0
    gpr jr_addend_800FC864 = ctx->r3;
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x800FC860: lw          $v0, 0x0($v1)
    ctx->r2 = ADD32(ctx->r3, 0X0);
    // 0x800FC864: jr          $v0
    // 0x800FC868: nop

    switch (jr_addend_800FC864 >> 2) {
        case 0: goto L_800FD0DC; break;
        case 1: goto L_800FD07C; break;
        case 2: goto L_800FC86C; break;
        case 3: goto L_800FCD1C; break;
        case 4: goto L_800FD07C; break;
        case 5: goto L_800FD2C4; break;
        case 6: goto L_800FD07C; break;
        case 7: goto L_800FC86C; break;
        case 8: goto L_800FD07C; break;
        default: switch_error(__func__, 0x800FC864, 0x800A91B8);
    }
    // 0x800FC868: nop

L_800FC86C:
    // 0x800FC86C: lbu         $v1, 0x1($s1)
    ctx->r3 = MEM_BU(ctx->r17, 0X1);
    // 0x800FC870: sltiu       $v0, $v1, 0x5
    ctx->r2 = ctx->r3 < 0X5 ? 1 : 0;
    // 0x800FC874: beq         $v0, $zero, L_800FD2C4
    if (ctx->r2 == 0) {
        // 0x800FC878: lui         $v0, 0x800B
        ctx->r2 = S32(0X800B << 16);
            goto L_800FD2C4;
    }
    // 0x800FC878: lui         $v0, 0x800B
    ctx->r2 = S32(0X800B << 16);
    // 0x800FC87C: addiu       $v0, $v0, -0x6E20
    ctx->r2 = ADD32(ctx->r2, -0X6E20);
    // 0x800FC880: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x800FC884: addu        $v1, $v1, $v0
    gpr jr_addend_800FC88C = ctx->r3;
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x800FC888: lw          $v0, 0x0($v1)
    ctx->r2 = ADD32(ctx->r3, 0X0);
    // 0x800FC88C: jr          $v0
    // 0x800FC890: nop

    switch (jr_addend_800FC88C >> 2) {
        case 0: goto L_800FC894; break;
        case 1: goto L_800FC8D8; break;
        case 2: goto L_800FC9DC; break;
        case 3: goto L_800FCC64; break;
        case 4: goto L_800FD2B4; break;
        default: switch_error(__func__, 0x800FC88C, 0x800A91E0);
    }
    // 0x800FC890: nop

L_800FC894:
    // 0x800FC894: andi        $v0, $s2, 0xFF
    ctx->r2 = ctx->r18 & 0XFF;
    // 0x800FC898: beq         $v0, $zero, L_800FD2C4
    if (ctx->r2 == 0) {
        // 0x800FC89C: nop
    
            goto L_800FD2C4;
    }
    // 0x800FC89C: nop

    // 0x800FC8A0: lbu         $v0, 0x2($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X2);
    // 0x800FC8A4: beq         $v0, $zero, L_800FCD98
    if (ctx->r2 == 0) {
        // 0x800FC8A8: andi        $v0, $s0, 0xFF
        ctx->r2 = ctx->r16 & 0XFF;
            goto L_800FCD98;
    }
    // 0x800FC8A8: andi        $v0, $s0, 0xFF
    ctx->r2 = ctx->r16 & 0XFF;
    // 0x800FC8AC: bne         $v0, $zero, L_800FCD9C
    if (ctx->r2 != 0) {
        // 0x800FC8B0: addiu       $a0, $zero, 0x67
        ctx->r4 = ADD32(0, 0X67);
            goto L_800FCD9C;
    }
    // 0x800FC8B0: addiu       $a0, $zero, 0x67
    ctx->r4 = ADD32(0, 0X67);
    // 0x800FC8B4: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800FC8B8: lwc1        $f0, -0x6E0C($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X6E0C);
    // 0x800FC8BC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800FC8C0: sb          $v0, 0x1($s1)
    MEM_B(0X1, ctx->r17) = ctx->r2;
    // 0x800FC8C4: sb          $zero, 0x8($s1)
    MEM_B(0X8, ctx->r17) = 0;
    // 0x800FC8C8: sb          $zero, 0x7($s1)
    MEM_B(0X7, ctx->r17) = 0;
    // 0x800FC8CC: sw          $zero, 0x218($s1)
    MEM_W(0X218, ctx->r17) = 0;
    // 0x800FC8D0: j           L_800FD2C4
    // 0x800FC8D4: swc1        $f0, 0x20($s1)
    MEM_W(0X20, ctx->r17) = ctx->f0.u32l;
        goto L_800FD2C4;
    // 0x800FC8D4: swc1        $f0, 0x20($s1)
    MEM_W(0X20, ctx->r17) = ctx->f0.u32l;
L_800FC8D8:
    // 0x800FC8D8: andi        $v0, $s0, 0xFF
    ctx->r2 = ctx->r16 & 0XFF;
    // 0x800FC8DC: bne         $v0, $zero, L_800FCEB8
    if (ctx->r2 != 0) {
        // 0x800FC8E0: nop
    
            goto L_800FCEB8;
    }
    // 0x800FC8E0: nop

    // 0x800FC8E4: lwc1        $f0, 0x218($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X218);
    // 0x800FC8E8: add.s       $f0, $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f20.fl;
    // 0x800FC8EC: lwc1        $f2, 0x20($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0X20);
    // 0x800FC8F0: sub.s       $f4, $f2, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = ctx->f2.fl - ctx->f20.fl;
    // 0x800FC8F4: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x800FC8F8: c.lt.s      $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f2.fl < ctx->f4.fl;
    // 0x800FC8FC: swc1        $f0, 0x218($s1)
    MEM_W(0X218, ctx->r17) = ctx->f0.u32l;
    // 0x800FC900: bc1f        L_800FC9B8
    if (!c1cs) {
        // 0x800FC904: swc1        $f4, 0x20($s1)
        MEM_W(0X20, ctx->r17) = ctx->f4.u32l;
            goto L_800FC9B8;
    }
    // 0x800FC904: swc1        $f4, 0x20($s1)
    MEM_W(0X20, ctx->r17) = ctx->f4.u32l;
    // 0x800FC908: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800FC90C: lwc1        $f0, -0x6E08($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X6E08);
    // 0x800FC910: mul.s       $f0, $f4, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x800FC914: add.s       $f0, $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f0.fl;
    // 0x800FC918: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800FC91C: lwc1        $f2, -0x6E04($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X6E04);
    // 0x800FC920: c.le.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl <= ctx->f0.fl;
    // 0x800FC924: nop

    // 0x800FC928: bc1tl       L_800FC940
    if (c1cs) {
        // 0x800FC92C: sub.s       $f0, $f0, $f2
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
            goto L_800FC940;
    }
    goto skip_0;
    // 0x800FC92C: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    skip_0:
    // 0x800FC930: trunc.w.s   $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    ctx->f6.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800FC934: mfc1        $a0, $f6
    ctx->r4 = (int32_t)ctx->f6.u32l;
    // 0x800FC938: j           L_800FC954
    // 0x800FC93C: addiu       $v0, $zero, 0xBE
    ctx->r2 = ADD32(0, 0XBE);
        goto L_800FC954;
    // 0x800FC93C: addiu       $v0, $zero, 0xBE
    ctx->r2 = ADD32(0, 0XBE);
L_800FC940:
    // 0x800FC940: lui         $v0, 0x8000
    ctx->r2 = S32(0X8000 << 16);
    // 0x800FC944: trunc.w.s   $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    ctx->f6.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800FC948: mfc1        $a0, $f6
    ctx->r4 = (int32_t)ctx->f6.u32l;
    // 0x800FC94C: or          $a0, $a0, $v0
    ctx->r4 = ctx->r4 | ctx->r2;
    // 0x800FC950: addiu       $v0, $zero, 0xBE
    ctx->r2 = ADD32(0, 0XBE);
L_800FC954:
    // 0x800FC954: lbu         $v1, 0x6($s1)
    ctx->r3 = MEM_BU(ctx->r17, 0X6);
    // 0x800FC958: subu        $v0, $v0, $a0
    ctx->r2 = SUB32(ctx->r2, ctx->r4);
    // 0x800FC95C: bne         $v1, $zero, L_800FC9A4
    if (ctx->r3 != 0) {
        // 0x800FC960: sb          $v0, 0x8($s1)
        MEM_B(0X8, ctx->r17) = ctx->r2;
            goto L_800FC9A4;
    }
    // 0x800FC960: sb          $v0, 0x8($s1)
    MEM_B(0X8, ctx->r17) = ctx->r2;
    // 0x800FC964: andi        $v0, $s2, 0xFF
    ctx->r2 = ctx->r18 & 0XFF;
    // 0x800FC968: beq         $v0, $zero, L_800FD040
    if (ctx->r2 == 0) {
        // 0x800FC96C: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_800FD040;
    }
    // 0x800FC96C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800FC970: lbu         $v0, 0x7($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X7);
    // 0x800FC974: beq         $v0, $zero, L_800FD2C4
    if (ctx->r2 == 0) {
        // 0x800FC978: nop
    
            goto L_800FD2C4;
    }
    // 0x800FC978: nop

    // 0x800FC97C: lwc1        $f2, 0x218($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0X218);
    // 0x800FC980: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800FC984: lwc1        $f0, -0x6E00($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X6E00);
    // 0x800FC988: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x800FC98C: nop

    // 0x800FC990: bc1f        L_800FCEB8
    if (!c1cs) {
        // 0x800FC994: sb          $zero, 0x7($s1)
        MEM_B(0X7, ctx->r17) = 0;
            goto L_800FCEB8;
    }
    // 0x800FC994: sb          $zero, 0x7($s1)
    MEM_B(0X7, ctx->r17) = 0;
    // 0x800FC998: addiu       $s5, $zero, 0x1
    ctx->r21 = ADD32(0, 0X1);
    // 0x800FC99C: j           L_800FCEB8
    // 0x800FC9A0: sb          $s5, 0x211($s1)
    MEM_B(0X211, ctx->r17) = ctx->r21;
        goto L_800FCEB8;
    // 0x800FC9A0: sb          $s5, 0x211($s1)
    MEM_B(0X211, ctx->r17) = ctx->r21;
L_800FC9A4:
    // 0x800FC9A4: andi        $v0, $s2, 0xFF
    ctx->r2 = ctx->r18 & 0XFF;
    // 0x800FC9A8: bne         $v0, $zero, L_800FD2C4
    if (ctx->r2 != 0) {
        // 0x800FC9AC: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_800FD2C4;
    }
    // 0x800FC9AC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800FC9B0: j           L_800FCEB8
    // 0x800FC9B4: sb          $v0, 0x7($s1)
    MEM_B(0X7, ctx->r17) = ctx->r2;
        goto L_800FCEB8;
    // 0x800FC9B4: sb          $v0, 0x7($s1)
    MEM_B(0X7, ctx->r17) = ctx->r2;
L_800FC9B8:
    // 0x800FC9B8: addiu       $v0, $zero, 0xBE
    ctx->r2 = ADD32(0, 0XBE);
    // 0x800FC9BC: sb          $v0, 0x8($s1)
    MEM_B(0X8, ctx->r17) = ctx->r2;
    // 0x800FC9C0: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x800FC9C4: sb          $v0, 0x1($s1)
    MEM_B(0X1, ctx->r17) = ctx->r2;
    // 0x800FC9C8: ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
    // 0x800FC9CC: sh          $v0, 0x208($s1)
    MEM_H(0X208, ctx->r17) = ctx->r2;
    // 0x800FC9D0: sb          $zero, 0x210($s1)
    MEM_B(0X210, ctx->r17) = 0;
    // 0x800FC9D4: j           L_800FD2C4
    // 0x800FC9D8: sh          $v0, 0x212($s1)
    MEM_H(0X212, ctx->r17) = ctx->r2;
        goto L_800FD2C4;
    // 0x800FC9D8: sh          $v0, 0x212($s1)
    MEM_H(0X212, ctx->r17) = ctx->r2;
L_800FC9DC:
    // 0x800FC9DC: andi        $v0, $s0, 0xFF
    ctx->r2 = ctx->r16 & 0XFF;
    // 0x800FC9E0: beq         $v0, $zero, L_800FCA1C
    if (ctx->r2 == 0) {
        // 0x800FC9E4: addu        $a0, $s4, $zero
        ctx->r4 = ADD32(ctx->r20, 0);
            goto L_800FCA1C;
    }
    // 0x800FC9E4: addu        $a0, $s4, $zero
    ctx->r4 = ADD32(ctx->r20, 0);
    // 0x800FC9E8: lbu         $v0, 0x210($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X210);
    // 0x800FC9EC: beq         $v0, $zero, L_800FCA00
    if (ctx->r2 == 0) {
        // 0x800FC9F0: nop
    
            goto L_800FCA00;
    }
    // 0x800FC9F0: nop

    // 0x800FC9F4: lhu         $a0, 0x212($s1)
    ctx->r4 = MEM_HU(ctx->r17, 0X212);
    // 0x800FC9F8: jal         0x8003F0C8
    // 0x800FC9FC: nop

    func_8003F0C8(rdram, ctx);
        goto after_2;
    // 0x800FC9FC: nop

    after_2:
L_800FCA00:
    // 0x800FCA00: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800FCA04: lwc1        $f0, -0x6DFC($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X6DFC);
    // 0x800FCA08: ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
    // 0x800FCA0C: sh          $v0, 0x208($s1)
    MEM_H(0X208, ctx->r17) = ctx->r2;
    // 0x800FCA10: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x800FCA14: j           L_800FD070
    // 0x800FCA18: sb          $zero, 0x210($s1)
    MEM_B(0X210, ctx->r17) = 0;
        goto L_800FD070;
    // 0x800FCA18: sb          $zero, 0x210($s1)
    MEM_B(0X210, ctx->r17) = 0;
L_800FCA1C:
    // 0x800FCA1C: addiu       $a2, $sp, 0x28
    ctx->r6 = ADD32(ctx->r29, 0X28);
    // 0x800FCA20: addu        $a3, $s1, $zero
    ctx->r7 = ADD32(ctx->r17, 0);
    // 0x800FCA24: lhu         $a1, 0x208($s1)
    ctx->r5 = MEM_HU(ctx->r17, 0X208);
    // 0x800FCA28: addiu       $v0, $sp, 0x38
    ctx->r2 = ADD32(ctx->r29, 0X38);
    // 0x800FCA2C: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // 0x800FCA30: jal         0x800FC260
    // 0x800FCA34: swc1        $f20, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f20.u32l;
    func_800FC260(rdram, ctx);
        goto after_3;
    // 0x800FCA34: swc1        $f20, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f20.u32l;
    after_3:
    // 0x800FCA38: lbu         $v1, 0x210($s1)
    ctx->r3 = MEM_BU(ctx->r17, 0X210);
    // 0x800FCA3C: bne         $v1, $zero, L_800FCAF4
    if (ctx->r3 != 0) {
        // 0x800FCA40: addu        $a0, $v0, $zero
        ctx->r4 = ADD32(ctx->r2, 0);
            goto L_800FCAF4;
    }
    // 0x800FCA40: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // 0x800FCA44: andi        $v1, $a0, 0xFFFF
    ctx->r3 = ctx->r4 & 0XFFFF;
    // 0x800FCA48: ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
    // 0x800FCA4C: beq         $v1, $v0, L_800FCAE0
    if (ctx->r3 == ctx->r2) {
        // 0x800FCA50: nop
    
            goto L_800FCAE0;
    }
    // 0x800FCA50: nop

    // 0x800FCA54: lhu         $v0, 0x208($s1)
    ctx->r2 = MEM_HU(ctx->r17, 0X208);
    // 0x800FCA58: bne         $v1, $v0, L_800FCAE0
    if (ctx->r3 != ctx->r2) {
        // 0x800FCA5C: nop
    
            goto L_800FCAE0;
    }
    // 0x800FCA5C: nop

    // 0x800FCA60: lwc1        $f0, 0x20C($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X20C);
    // 0x800FCA64: sub.s       $f0, $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f20.fl;
    // 0x800FCA68: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x800FCA6C: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x800FCA70: nop

    // 0x800FCA74: bc1f        L_800FCBF4
    if (!c1cs) {
        // 0x800FCA78: swc1        $f0, 0x20C($s1)
        MEM_W(0X20C, ctx->r17) = ctx->f0.u32l;
            goto L_800FCBF4;
    }
    // 0x800FCA78: swc1        $f0, 0x20C($s1)
    MEM_W(0X20C, ctx->r17) = ctx->f0.u32l;
    // 0x800FCA7C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800FCA80: sb          $v0, 0x210($s1)
    MEM_B(0X210, ctx->r17) = ctx->r2;
    // 0x800FCA84: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x800FCA88: lw          $t2, 0x2C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X2C);
    // 0x800FCA8C: lw          $t3, 0x30($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X30);
    // 0x800FCA90: sw          $t1, 0x21C($s1)
    MEM_W(0X21C, ctx->r17) = ctx->r9;
    // 0x800FCA94: sw          $t2, 0x220($s1)
    MEM_W(0X220, ctx->r17) = ctx->r10;
    // 0x800FCA98: sw          $t3, 0x224($s1)
    MEM_W(0X224, ctx->r17) = ctx->r11;
    // 0x800FCA9C: lhu         $a1, 0x208($s1)
    ctx->r5 = MEM_HU(ctx->r17, 0X208);
    // 0x800FCAA0: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800FCAA4: lwc1        $f0, -0x6DF8($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X6DF8);
    // 0x800FCAA8: andi        $a0, $s6, 0xFFFF
    ctx->r4 = ctx->r22 & 0XFFFF;
    // 0x800FCAAC: jal         0x80040188
    // 0x800FCAB0: swc1        $f0, 0x20C($s1)
    MEM_W(0X20C, ctx->r17) = ctx->f0.u32l;
    func_80040188(rdram, ctx);
        goto after_4;
    // 0x800FCAB0: swc1        $f0, 0x20C($s1)
    MEM_W(0X20C, ctx->r17) = ctx->f0.u32l;
    after_4:
    // 0x800FCAB4: lbu         $v1, 0x38($sp)
    ctx->r3 = MEM_BU(ctx->r29, 0X38);
    // 0x800FCAB8: sh          $v0, 0x212($s1)
    MEM_H(0X212, ctx->r17) = ctx->r2;
    // 0x800FCABC: sltiu       $v1, $v1, 0x4
    ctx->r3 = ctx->r3 < 0X4 ? 1 : 0;
    // 0x800FCAC0: bne         $v1, $zero, L_800FCACC
    if (ctx->r3 != 0) {
        // 0x800FCAC4: addiu       $a0, $zero, 0x68
        ctx->r4 = ADD32(0, 0X68);
            goto L_800FCACC;
    }
    // 0x800FCAC4: addiu       $a0, $zero, 0x68
    ctx->r4 = ADD32(0, 0X68);
    // 0x800FCAC8: addiu       $a0, $zero, 0x69
    ctx->r4 = ADD32(0, 0X69);
L_800FCACC:
    // 0x800FCACC: addiu       $a1, $zero, 0x6E
    ctx->r5 = ADD32(0, 0X6E);
    // 0x800FCAD0: jal         0x80087EE8
    // 0x800FCAD4: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    func_80087EE8(rdram, ctx);
        goto after_5;
    // 0x800FCAD4: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    after_5:
    // 0x800FCAD8: j           L_800FCBF4
    // 0x800FCADC: nop

        goto L_800FCBF4;
    // 0x800FCADC: nop

L_800FCAE0:
    // 0x800FCAE0: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800FCAE4: lwc1        $f0, -0x6DF4($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X6DF4);
    // 0x800FCAE8: sh          $a0, 0x208($s1)
    MEM_H(0X208, ctx->r17) = ctx->r4;
    // 0x800FCAEC: j           L_800FCBF4
    // 0x800FCAF0: swc1        $f0, 0x20C($s1)
    MEM_W(0X20C, ctx->r17) = ctx->f0.u32l;
        goto L_800FCBF4;
    // 0x800FCAF0: swc1        $f0, 0x20C($s1)
    MEM_W(0X20C, ctx->r17) = ctx->f0.u32l;
L_800FCAF4:
    // 0x800FCAF4: lhu         $v1, 0x208($s1)
    ctx->r3 = MEM_HU(ctx->r17, 0X208);
    // 0x800FCAF8: andi        $v0, $a0, 0xFFFF
    ctx->r2 = ctx->r4 & 0XFFFF;
    // 0x800FCAFC: beq         $v0, $v1, L_800FCBB8
    if (ctx->r2 == ctx->r3) {
        // 0x800FCB00: nop
    
            goto L_800FCBB8;
    }
    // 0x800FCB00: nop

    // 0x800FCB04: lwc1        $f0, 0x20C($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X20C);
    // 0x800FCB08: sub.s       $f0, $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f20.fl;
    // 0x800FCB0C: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x800FCB10: c.le.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl <= ctx->f0.fl;
    // 0x800FCB14: nop

    // 0x800FCB18: bc1f        L_800FCB9C
    if (!c1cs) {
        // 0x800FCB1C: swc1        $f0, 0x20C($s1)
        MEM_W(0X20C, ctx->r17) = ctx->f0.u32l;
            goto L_800FCB9C;
    }
    // 0x800FCB1C: swc1        $f0, 0x20C($s1)
    MEM_W(0X20C, ctx->r17) = ctx->f0.u32l;
    // 0x800FCB20: lhu         $a0, 0x212($s1)
    ctx->r4 = MEM_HU(ctx->r17, 0X212);
    // 0x800FCB24: jal         0x80040218
    // 0x800FCB28: nop

    func_80040218(rdram, ctx);
        goto after_6;
    // 0x800FCB28: nop

    after_6:
    // 0x800FCB2C: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x800FCB30: ori         $v1, $zero, 0xFFFF
    ctx->r3 = 0 | 0XFFFF;
    // 0x800FCB34: beq         $v0, $v1, L_800FCB90
    if (ctx->r2 == ctx->r3) {
        // 0x800FCB38: nop
    
            goto L_800FCB90;
    }
    // 0x800FCB38: nop

    // 0x800FCB3C: lhu         $a0, 0x208($s1)
    ctx->r4 = MEM_HU(ctx->r17, 0X208);
    // 0x800FCB40: jal         0x8004013C
    // 0x800FCB44: nop

    func_8004013C(rdram, ctx);
        goto after_7;
    // 0x800FCB44: nop

    after_7:
    // 0x800FCB48: beq         $v0, $zero, L_800FCBF4
    if (ctx->r2 == 0) {
        // 0x800FCB4C: nop
    
            goto L_800FCBF4;
    }
    // 0x800FCB4C: nop

    // 0x800FCB50: lw          $a0, 0xC($v0)
    ctx->r4 = MEM_W(ctx->r2, 0XC);
    // 0x800FCB54: beq         $a0, $zero, L_800FCB6C
    if (ctx->r4 == 0) {
        // 0x800FCB58: nop
    
            goto L_800FCB6C;
    }
    // 0x800FCB58: nop

    // 0x800FCB5C: jal         0x8006AC7C
    // 0x800FCB60: addiu       $a1, $s1, 0x21C
    ctx->r5 = ADD32(ctx->r17, 0X21C);
    func_8006AC7C(rdram, ctx);
        goto after_8;
    // 0x800FCB60: addiu       $a1, $s1, 0x21C
    ctx->r5 = ADD32(ctx->r17, 0X21C);
    after_8:
    // 0x800FCB64: j           L_800FCBF4
    // 0x800FCB68: nop

        goto L_800FCBF4;
    // 0x800FCB68: nop

L_800FCB6C:
    // 0x800FCB6C: lw          $v0, 0x8($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X8);
    // 0x800FCB70: lw          $t1, 0x0($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X0);
    // 0x800FCB74: lw          $t2, 0x4($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X4);
    // 0x800FCB78: lw          $t3, 0x8($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X8);
    // 0x800FCB7C: sw          $t1, 0x21C($s1)
    MEM_W(0X21C, ctx->r17) = ctx->r9;
    // 0x800FCB80: sw          $t2, 0x220($s1)
    MEM_W(0X220, ctx->r17) = ctx->r10;
    // 0x800FCB84: sw          $t3, 0x224($s1)
    MEM_W(0X224, ctx->r17) = ctx->r11;
    // 0x800FCB88: j           L_800FCBF4
    // 0x800FCB8C: nop

        goto L_800FCBF4;
    // 0x800FCB8C: nop

L_800FCB90:
    // 0x800FCB90: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800FCB94: lwc1        $f0, -0x6DF0($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X6DF0);
    // 0x800FCB98: swc1        $f0, 0x20C($s1)
    MEM_W(0X20C, ctx->r17) = ctx->f0.u32l;
L_800FCB9C:
    // 0x800FCB9C: lhu         $a0, 0x212($s1)
    ctx->r4 = MEM_HU(ctx->r17, 0X212);
    // 0x800FCBA0: ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
    // 0x800FCBA4: sb          $zero, 0x210($s1)
    MEM_B(0X210, ctx->r17) = 0;
    // 0x800FCBA8: jal         0x8003F0C8
    // 0x800FCBAC: sh          $v0, 0x208($s1)
    MEM_H(0X208, ctx->r17) = ctx->r2;
    func_8003F0C8(rdram, ctx);
        goto after_9;
    // 0x800FCBAC: sh          $v0, 0x208($s1)
    MEM_H(0X208, ctx->r17) = ctx->r2;
    after_9:
    // 0x800FCBB0: j           L_800FCBF4
    // 0x800FCBB4: nop

        goto L_800FCBF4;
    // 0x800FCBB4: nop

L_800FCBB8:
    // 0x800FCBB8: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800FCBBC: lwc1        $f0, -0x6DEC($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X6DEC);
    // 0x800FCBC0: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x800FCBC4: lw          $t2, 0x2C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X2C);
    // 0x800FCBC8: lw          $t3, 0x30($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X30);
    // 0x800FCBCC: sw          $t1, 0x21C($s1)
    MEM_W(0X21C, ctx->r17) = ctx->r9;
    // 0x800FCBD0: sw          $t2, 0x220($s1)
    MEM_W(0X220, ctx->r17) = ctx->r10;
    // 0x800FCBD4: sw          $t3, 0x224($s1)
    MEM_W(0X224, ctx->r17) = ctx->r11;
    // 0x800FCBD8: lhu         $a0, 0x212($s1)
    ctx->r4 = MEM_HU(ctx->r17, 0X212);
    // 0x800FCBDC: jal         0x80040218
    // 0x800FCBE0: swc1        $f0, 0x20C($s1)
    MEM_W(0X20C, ctx->r17) = ctx->f0.u32l;
    func_80040218(rdram, ctx);
        goto after_10;
    // 0x800FCBE0: swc1        $f0, 0x20C($s1)
    MEM_W(0X20C, ctx->r17) = ctx->f0.u32l;
    after_10:
    // 0x800FCBE4: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x800FCBE8: ori         $v1, $zero, 0xFFFF
    ctx->r3 = 0 | 0XFFFF;
    // 0x800FCBEC: beq         $v0, $v1, L_800FCB90
    if (ctx->r2 == ctx->r3) {
        // 0x800FCBF0: nop
    
            goto L_800FCB90;
    }
    // 0x800FCBF0: nop

L_800FCBF4:
    // 0x800FCBF4: lbu         $v0, 0x6($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X6);
    // 0x800FCBF8: bne         $v0, $zero, L_800FCC1C
    if (ctx->r2 != 0) {
        // 0x800FCBFC: andi        $v0, $s2, 0xFF
        ctx->r2 = ctx->r18 & 0XFF;
            goto L_800FCC1C;
    }
    // 0x800FCBFC: andi        $v0, $s2, 0xFF
    ctx->r2 = ctx->r18 & 0XFF;
    // 0x800FCC00: beq         $v0, $zero, L_800FD040
    if (ctx->r2 == 0) {
        // 0x800FCC04: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_800FD040;
    }
    // 0x800FCC04: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800FCC08: lbu         $v0, 0x7($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X7);
    // 0x800FCC0C: beq         $v0, $zero, L_800FD2C4
    if (ctx->r2 == 0) {
        // 0x800FCC10: nop
    
            goto L_800FD2C4;
    }
    // 0x800FCC10: nop

    // 0x800FCC14: j           L_800FCC24
    // 0x800FCC18: sb          $zero, 0x7($s1)
    MEM_B(0X7, ctx->r17) = 0;
        goto L_800FCC24;
    // 0x800FCC18: sb          $zero, 0x7($s1)
    MEM_B(0X7, ctx->r17) = 0;
L_800FCC1C:
    // 0x800FCC1C: bne         $v0, $zero, L_800FD2C4
    if (ctx->r2 != 0) {
        // 0x800FCC20: nop
    
            goto L_800FD2C4;
    }
    // 0x800FCC20: nop

L_800FCC24:
    // 0x800FCC24: lbu         $v0, 0x210($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X210);
    // 0x800FCC28: beq         $v0, $zero, L_800FCC48
    if (ctx->r2 == 0) {
        // 0x800FCC2C: nop
    
            goto L_800FCC48;
    }
    // 0x800FCC2C: nop

    // 0x800FCC30: lhu         $v1, 0x208($s1)
    ctx->r3 = MEM_HU(ctx->r17, 0X208);
    // 0x800FCC34: lw          $v0, 0x7C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X7C);
    // 0x800FCC38: sh          $v1, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r3;
    // 0x800FCC3C: lhu         $a0, 0x212($s1)
    ctx->r4 = MEM_HU(ctx->r17, 0X212);
    // 0x800FCC40: jal         0x8003F0C8
    // 0x800FCC44: addiu       $s5, $zero, 0x1
    ctx->r21 = ADD32(0, 0X1);
    func_8003F0C8(rdram, ctx);
        goto after_11;
    // 0x800FCC44: addiu       $s5, $zero, 0x1
    ctx->r21 = ADD32(0, 0X1);
    after_11:
L_800FCC48:
    // 0x800FCC48: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800FCC4C: lwc1        $f0, -0x6DE8($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X6DE8);
    // 0x800FCC50: ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
    // 0x800FCC54: sh          $v0, 0x208($s1)
    MEM_H(0X208, ctx->r17) = ctx->r2;
    // 0x800FCC58: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x800FCC5C: j           L_800FD070
    // 0x800FCC60: sb          $zero, 0x210($s1)
    MEM_B(0X210, ctx->r17) = 0;
        goto L_800FD070;
    // 0x800FCC60: sb          $zero, 0x210($s1)
    MEM_B(0X210, ctx->r17) = 0;
L_800FCC64:
    // 0x800FCC64: lwc1        $f0, 0x20($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X20);
    // 0x800FCC68: sub.s       $f2, $f0, $f20
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f2.fl = ctx->f0.fl - ctx->f20.fl;
    // 0x800FCC6C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800FCC70: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x800FCC74: nop

    // 0x800FCC78: bc1f        L_800FCD14
    if (!c1cs) {
        // 0x800FCC7C: swc1        $f2, 0x20($s1)
        MEM_W(0X20, ctx->r17) = ctx->f2.u32l;
            goto L_800FCD14;
    }
    // 0x800FCC7C: swc1        $f2, 0x20($s1)
    MEM_W(0X20, ctx->r17) = ctx->f2.u32l;
    // 0x800FCC80: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800FCC84: lwc1        $f0, -0x6DE4($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X6DE4);
    // 0x800FCC88: mul.s       $f0, $f2, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x800FCC8C: add.s       $f0, $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f0.fl;
    // 0x800FCC90: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800FCC94: lwc1        $f2, -0x6DE0($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X6DE0);
    // 0x800FCC98: c.le.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl <= ctx->f0.fl;
    // 0x800FCC9C: nop

    // 0x800FCCA0: bc1tl       L_800FCCB8
    if (c1cs) {
        // 0x800FCCA4: sub.s       $f0, $f0, $f2
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
            goto L_800FCCB8;
    }
    goto skip_1;
    // 0x800FCCA4: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    skip_1:
    // 0x800FCCA8: trunc.w.s   $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    ctx->f6.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800FCCAC: mfc1        $v1, $f6
    ctx->r3 = (int32_t)ctx->f6.u32l;
    // 0x800FCCB0: j           L_800FCCCC
    // 0x800FCCB4: sb          $v1, 0x8($s1)
    MEM_B(0X8, ctx->r17) = ctx->r3;
        goto L_800FCCCC;
    // 0x800FCCB4: sb          $v1, 0x8($s1)
    MEM_B(0X8, ctx->r17) = ctx->r3;
L_800FCCB8:
    // 0x800FCCB8: lui         $v0, 0x8000
    ctx->r2 = S32(0X8000 << 16);
    // 0x800FCCBC: trunc.w.s   $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    ctx->f6.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800FCCC0: mfc1        $v1, $f6
    ctx->r3 = (int32_t)ctx->f6.u32l;
    // 0x800FCCC4: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x800FCCC8: sb          $v1, 0x8($s1)
    MEM_B(0X8, ctx->r17) = ctx->r3;
L_800FCCCC:
    // 0x800FCCCC: andi        $v0, $s0, 0xFF
    ctx->r2 = ctx->r16 & 0XFF;
    // 0x800FCCD0: bne         $v0, $zero, L_800FD2C4
    if (ctx->r2 != 0) {
        // 0x800FCCD4: nop
    
            goto L_800FD2C4;
    }
    // 0x800FCCD4: nop

    // 0x800FCCD8: lbu         $v0, 0x6($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X6);
    // 0x800FCCDC: bne         $v0, $zero, L_800FCD00
    if (ctx->r2 != 0) {
        // 0x800FCCE0: andi        $v0, $s2, 0xFF
        ctx->r2 = ctx->r18 & 0XFF;
            goto L_800FCD00;
    }
    // 0x800FCCE0: andi        $v0, $s2, 0xFF
    ctx->r2 = ctx->r18 & 0XFF;
    // 0x800FCCE4: beq         $v0, $zero, L_800FD040
    if (ctx->r2 == 0) {
        // 0x800FCCE8: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_800FD040;
    }
    // 0x800FCCE8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800FCCEC: lbu         $v0, 0x7($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X7);
    // 0x800FCCF0: beq         $v0, $zero, L_800FD2C4
    if (ctx->r2 == 0) {
        // 0x800FCCF4: nop
    
            goto L_800FD2C4;
    }
    // 0x800FCCF4: nop

    // 0x800FCCF8: j           L_800FCD08
    // 0x800FCCFC: sb          $zero, 0x7($s1)
    MEM_B(0X7, ctx->r17) = 0;
        goto L_800FCD08;
    // 0x800FCCFC: sb          $zero, 0x7($s1)
    MEM_B(0X7, ctx->r17) = 0;
L_800FCD00:
    // 0x800FCD00: beq         $v0, $zero, L_800FD2C4
    if (ctx->r2 == 0) {
        // 0x800FCD04: nop
    
            goto L_800FD2C4;
    }
    // 0x800FCD04: nop

L_800FCD08:
    // 0x800FCD08: lbu         $v0, 0x2($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X2);
    // 0x800FCD0C: j           L_800FD05C
    // 0x800FCD10: nop

        goto L_800FD05C;
    // 0x800FCD10: nop

L_800FCD14:
    // 0x800FCD14: j           L_800FD2C0
    // 0x800FCD18: sb          $zero, 0x8($s1)
    MEM_B(0X8, ctx->r17) = 0;
        goto L_800FD2C0;
    // 0x800FCD18: sb          $zero, 0x8($s1)
    MEM_B(0X8, ctx->r17) = 0;
L_800FCD1C:
    // 0x800FCD1C: lbu         $v1, 0x1($s1)
    ctx->r3 = MEM_BU(ctx->r17, 0X1);
    // 0x800FCD20: sltiu       $v0, $v1, 0x5
    ctx->r2 = ctx->r3 < 0X5 ? 1 : 0;
    // 0x800FCD24: beq         $v0, $zero, L_800FD2C4
    if (ctx->r2 == 0) {
        // 0x800FCD28: lui         $v0, 0x800B
        ctx->r2 = S32(0X800B << 16);
            goto L_800FD2C4;
    }
    // 0x800FCD28: lui         $v0, 0x800B
    ctx->r2 = S32(0X800B << 16);
    // 0x800FCD2C: addiu       $v0, $v0, -0x6DD8
    ctx->r2 = ADD32(ctx->r2, -0X6DD8);
    // 0x800FCD30: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x800FCD34: addu        $v1, $v1, $v0
    gpr jr_addend_800FCD3C = ctx->r3;
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x800FCD38: lw          $v0, 0x0($v1)
    ctx->r2 = ADD32(ctx->r3, 0X0);
    // 0x800FCD3C: jr          $v0
    // 0x800FCD40: nop

    switch (jr_addend_800FCD3C >> 2) {
        case 0: goto L_800FCD44; break;
        case 1: goto L_800FCDB4; break;
        case 2: goto L_800FCED8; break;
        case 3: goto L_800FCF60; break;
        case 4: goto L_800FD2B4; break;
        default: switch_error(__func__, 0x800FCD3C, 0x800A9228);
    }
    // 0x800FCD40: nop

L_800FCD44:
    // 0x800FCD44: andi        $v0, $s2, 0xFF
    ctx->r2 = ctx->r18 & 0XFF;
    // 0x800FCD48: beq         $v0, $zero, L_800FD2C4
    if (ctx->r2 == 0) {
        // 0x800FCD4C: nop
    
            goto L_800FD2C4;
    }
    // 0x800FCD4C: nop

    // 0x800FCD50: lbu         $v0, 0x2($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X2);
    // 0x800FCD54: beq         $v0, $zero, L_800FCD98
    if (ctx->r2 == 0) {
        // 0x800FCD58: andi        $v0, $s0, 0xFF
        ctx->r2 = ctx->r16 & 0XFF;
            goto L_800FCD98;
    }
    // 0x800FCD58: andi        $v0, $s0, 0xFF
    ctx->r2 = ctx->r16 & 0XFF;
    // 0x800FCD5C: bne         $v0, $zero, L_800FCD9C
    if (ctx->r2 != 0) {
        // 0x800FCD60: addiu       $a0, $zero, 0x67
        ctx->r4 = ADD32(0, 0X67);
            goto L_800FCD9C;
    }
    // 0x800FCD60: addiu       $a0, $zero, 0x67
    ctx->r4 = ADD32(0, 0X67);
    // 0x800FCD64: lwc1        $f2, 0x1C($s4)
    ctx->f2.u32l = MEM_W(ctx->r20, 0X1C);
    // 0x800FCD68: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800FCD6C: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x800FCD70: nop

    // 0x800FCD74: bc1f        L_800FD2C4
    if (!c1cs) {
        // 0x800FCD78: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_800FD2C4;
    }
    // 0x800FCD78: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800FCD7C: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800FCD80: lwc1        $f0, -0x6DC4($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X6DC4);
    // 0x800FCD84: sb          $v0, 0x1($s1)
    MEM_B(0X1, ctx->r17) = ctx->r2;
    // 0x800FCD88: sb          $zero, 0x8($s1)
    MEM_B(0X8, ctx->r17) = 0;
    // 0x800FCD8C: sb          $zero, 0x7($s1)
    MEM_B(0X7, ctx->r17) = 0;
    // 0x800FCD90: j           L_800FD2C4
    // 0x800FCD94: swc1        $f0, 0x20($s1)
    MEM_W(0X20, ctx->r17) = ctx->f0.u32l;
        goto L_800FD2C4;
    // 0x800FCD94: swc1        $f0, 0x20($s1)
    MEM_W(0X20, ctx->r17) = ctx->f0.u32l;
L_800FCD98:
    // 0x800FCD98: addiu       $a0, $zero, 0x67
    ctx->r4 = ADD32(0, 0X67);
L_800FCD9C:
    // 0x800FCD9C: addiu       $a1, $zero, 0x5A
    ctx->r5 = ADD32(0, 0X5A);
    // 0x800FCDA0: jal         0x80087EE8
    // 0x800FCDA4: addiu       $a2, $zero, 0x40
    ctx->r6 = ADD32(0, 0X40);
    func_80087EE8(rdram, ctx);
        goto after_12;
    // 0x800FCDA4: addiu       $a2, $zero, 0x40
    ctx->r6 = ADD32(0, 0X40);
    after_12:
    // 0x800FCDA8: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // 0x800FCDAC: j           L_800FD2C4
    // 0x800FCDB0: sb          $v0, 0x1($s1)
    MEM_B(0X1, ctx->r17) = ctx->r2;
        goto L_800FD2C4;
    // 0x800FCDB0: sb          $v0, 0x1($s1)
    MEM_B(0X1, ctx->r17) = ctx->r2;
L_800FCDB4:
    // 0x800FCDB4: andi        $v0, $s0, 0xFF
    ctx->r2 = ctx->r16 & 0XFF;
    // 0x800FCDB8: bne         $v0, $zero, L_800FCEB8
    if (ctx->r2 != 0) {
        // 0x800FCDBC: nop
    
            goto L_800FCEB8;
    }
    // 0x800FCDBC: nop

    // 0x800FCDC0: lwc1        $f0, 0x20($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X20);
    // 0x800FCDC4: sub.s       $f2, $f0, $f20
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f2.fl = ctx->f0.fl - ctx->f20.fl;
    // 0x800FCDC8: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800FCDCC: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x800FCDD0: nop

    // 0x800FCDD4: bc1f        L_800FCE34
    if (!c1cs) {
        // 0x800FCDD8: swc1        $f2, 0x20($s1)
        MEM_W(0X20, ctx->r17) = ctx->f2.u32l;
            goto L_800FCE34;
    }
    // 0x800FCDD8: swc1        $f2, 0x20($s1)
    MEM_W(0X20, ctx->r17) = ctx->f2.u32l;
    // 0x800FCDDC: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800FCDE0: lwc1        $f0, -0x6DC0($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X6DC0);
    // 0x800FCDE4: mul.s       $f0, $f2, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x800FCDE8: add.s       $f0, $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f0.fl;
    // 0x800FCDEC: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800FCDF0: lwc1        $f2, -0x6DBC($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X6DBC);
    // 0x800FCDF4: c.le.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl <= ctx->f0.fl;
    // 0x800FCDF8: nop

    // 0x800FCDFC: bc1tl       L_800FCE14
    if (c1cs) {
        // 0x800FCE00: sub.s       $f0, $f0, $f2
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
            goto L_800FCE14;
    }
    goto skip_2;
    // 0x800FCE00: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    skip_2:
    // 0x800FCE04: trunc.w.s   $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    ctx->f6.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800FCE08: mfc1        $v1, $f6
    ctx->r3 = (int32_t)ctx->f6.u32l;
    // 0x800FCE0C: j           L_800FCE28
    // 0x800FCE10: addiu       $v0, $zero, 0xC8
    ctx->r2 = ADD32(0, 0XC8);
        goto L_800FCE28;
    // 0x800FCE10: addiu       $v0, $zero, 0xC8
    ctx->r2 = ADD32(0, 0XC8);
L_800FCE14:
    // 0x800FCE14: lui         $v0, 0x8000
    ctx->r2 = S32(0X8000 << 16);
    // 0x800FCE18: trunc.w.s   $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    ctx->f6.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800FCE1C: mfc1        $v1, $f6
    ctx->r3 = (int32_t)ctx->f6.u32l;
    // 0x800FCE20: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x800FCE24: addiu       $v0, $zero, 0xC8
    ctx->r2 = ADD32(0, 0XC8);
L_800FCE28:
    // 0x800FCE28: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x800FCE2C: j           L_800FCE44
    // 0x800FCE30: sb          $v0, 0x8($s1)
    MEM_B(0X8, ctx->r17) = ctx->r2;
        goto L_800FCE44;
    // 0x800FCE30: sb          $v0, 0x8($s1)
    MEM_B(0X8, ctx->r17) = ctx->r2;
L_800FCE34:
    // 0x800FCE34: addiu       $v0, $zero, 0xC8
    ctx->r2 = ADD32(0, 0XC8);
    // 0x800FCE38: sb          $v0, 0x8($s1)
    MEM_B(0X8, ctx->r17) = ctx->r2;
    // 0x800FCE3C: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x800FCE40: sb          $v0, 0x1($s1)
    MEM_B(0X1, ctx->r17) = ctx->r2;
L_800FCE44:
    // 0x800FCE44: addiu       $a0, $s1, 0x21C
    ctx->r4 = ADD32(ctx->r17, 0X21C);
    // 0x800FCE48: addu        $a1, $s4, $zero
    ctx->r5 = ADD32(ctx->r20, 0);
    // 0x800FCE4C: jal         0x800FC564
    // 0x800FCE50: addu        $a2, $s3, $zero
    ctx->r6 = ADD32(ctx->r19, 0);
    func_800FC564(rdram, ctx);
        goto after_13;
    // 0x800FCE50: addu        $a2, $s3, $zero
    ctx->r6 = ADD32(ctx->r19, 0);
    after_13:
    // 0x800FCE54: lbu         $v1, 0x6($s1)
    ctx->r3 = MEM_BU(ctx->r17, 0X6);
    // 0x800FCE58: bne         $v1, $zero, L_800FCE8C
    if (ctx->r3 != 0) {
        // 0x800FCE5C: sb          $v0, 0x228($s1)
        MEM_B(0X228, ctx->r17) = ctx->r2;
            goto L_800FCE8C;
    }
    // 0x800FCE5C: sb          $v0, 0x228($s1)
    MEM_B(0X228, ctx->r17) = ctx->r2;
    // 0x800FCE60: andi        $v0, $s2, 0xFF
    ctx->r2 = ctx->r18 & 0XFF;
    // 0x800FCE64: bne         $v0, $zero, L_800FCE74
    if (ctx->r2 != 0) {
        // 0x800FCE68: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_800FCE74;
    }
    // 0x800FCE68: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800FCE6C: j           L_800FCEA0
    // 0x800FCE70: sb          $v0, 0x7($s1)
    MEM_B(0X7, ctx->r17) = ctx->r2;
        goto L_800FCEA0;
    // 0x800FCE70: sb          $v0, 0x7($s1)
    MEM_B(0X7, ctx->r17) = ctx->r2;
L_800FCE74:
    // 0x800FCE74: lbu         $v0, 0x7($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X7);
    // 0x800FCE78: beq         $v0, $zero, L_800FCEA0
    if (ctx->r2 == 0) {
        // 0x800FCE7C: nop
    
            goto L_800FCEA0;
    }
    // 0x800FCE7C: nop

    // 0x800FCE80: sb          $zero, 0x7($s1)
    MEM_B(0X7, ctx->r17) = 0;
    // 0x800FCE84: j           L_800FCEB8
    // 0x800FCE88: addiu       $s5, $zero, 0x1
    ctx->r21 = ADD32(0, 0X1);
        goto L_800FCEB8;
    // 0x800FCE88: addiu       $s5, $zero, 0x1
    ctx->r21 = ADD32(0, 0X1);
L_800FCE8C:
    // 0x800FCE8C: andi        $v0, $s2, 0xFF
    ctx->r2 = ctx->r18 & 0XFF;
    // 0x800FCE90: bne         $v0, $zero, L_800FCEA0
    if (ctx->r2 != 0) {
        // 0x800FCE94: nop
    
            goto L_800FCEA0;
    }
    // 0x800FCE94: nop

    // 0x800FCE98: j           L_800FCEB8
    // 0x800FCE9C: addiu       $s5, $zero, 0x1
    ctx->r21 = ADD32(0, 0X1);
        goto L_800FCEB8;
    // 0x800FCE9C: addiu       $s5, $zero, 0x1
    ctx->r21 = ADD32(0, 0X1);
L_800FCEA0:
    // 0x800FCEA0: lwc1        $f2, 0x1C($s4)
    ctx->f2.u32l = MEM_W(ctx->r20, 0X1C);
    // 0x800FCEA4: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800FCEA8: c.le.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl <= ctx->f0.fl;
    // 0x800FCEAC: nop

    // 0x800FCEB0: bc1f        L_800FD2C4
    if (!c1cs) {
        // 0x800FCEB4: nop
    
            goto L_800FD2C4;
    }
    // 0x800FCEB4: nop

L_800FCEB8:
    // 0x800FCEB8: lwc1        $f0, 0x20($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X20);
    // 0x800FCEBC: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800FCEC0: lwc1        $f2, -0x6DB8($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X6DB8);
    // 0x800FCEC4: sub.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl - ctx->f0.fl;
    // 0x800FCEC8: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x800FCECC: sb          $v0, 0x1($s1)
    MEM_B(0X1, ctx->r17) = ctx->r2;
    // 0x800FCED0: j           L_800FD2C4
    // 0x800FCED4: swc1        $f2, 0x20($s1)
    MEM_W(0X20, ctx->r17) = ctx->f2.u32l;
        goto L_800FD2C4;
    // 0x800FCED4: swc1        $f2, 0x20($s1)
    MEM_W(0X20, ctx->r17) = ctx->f2.u32l;
L_800FCED8:
    // 0x800FCED8: addiu       $a0, $s1, 0x21C
    ctx->r4 = ADD32(ctx->r17, 0X21C);
    // 0x800FCEDC: addu        $a1, $s4, $zero
    ctx->r5 = ADD32(ctx->r20, 0);
    // 0x800FCEE0: jal         0x800FC564
    // 0x800FCEE4: addu        $a2, $s3, $zero
    ctx->r6 = ADD32(ctx->r19, 0);
    func_800FC564(rdram, ctx);
        goto after_14;
    // 0x800FCEE4: addu        $a2, $s3, $zero
    ctx->r6 = ADD32(ctx->r19, 0);
    after_14:
    // 0x800FCEE8: sb          $v0, 0x228($s1)
    MEM_B(0X228, ctx->r17) = ctx->r2;
    // 0x800FCEEC: andi        $v0, $s0, 0xFF
    ctx->r2 = ctx->r16 & 0XFF;
    // 0x800FCEF0: bne         $v0, $zero, L_800FCF50
    if (ctx->r2 != 0) {
        // 0x800FCEF4: nop
    
            goto L_800FCF50;
    }
    // 0x800FCEF4: nop

    // 0x800FCEF8: lbu         $v0, 0x6($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X6);
    // 0x800FCEFC: beq         $v0, $zero, L_800FCF14
    if (ctx->r2 == 0) {
        // 0x800FCF00: andi        $v0, $s2, 0xFF
        ctx->r2 = ctx->r18 & 0XFF;
            goto L_800FCF14;
    }
    // 0x800FCF00: andi        $v0, $s2, 0xFF
    ctx->r2 = ctx->r18 & 0XFF;
    // 0x800FCF04: bne         $v0, $zero, L_800FCF38
    if (ctx->r2 != 0) {
        // 0x800FCF08: nop
    
            goto L_800FCF38;
    }
    // 0x800FCF08: nop

    // 0x800FCF0C: j           L_800FCF50
    // 0x800FCF10: addiu       $s5, $zero, 0x1
    ctx->r21 = ADD32(0, 0X1);
        goto L_800FCF50;
    // 0x800FCF10: addiu       $s5, $zero, 0x1
    ctx->r21 = ADD32(0, 0X1);
L_800FCF14:
    // 0x800FCF14: beq         $v0, $zero, L_800FCF34
    if (ctx->r2 == 0) {
        // 0x800FCF18: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_800FCF34;
    }
    // 0x800FCF18: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800FCF1C: lbu         $v0, 0x7($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X7);
    // 0x800FCF20: beq         $v0, $zero, L_800FCF38
    if (ctx->r2 == 0) {
        // 0x800FCF24: nop
    
            goto L_800FCF38;
    }
    // 0x800FCF24: nop

    // 0x800FCF28: sb          $zero, 0x7($s1)
    MEM_B(0X7, ctx->r17) = 0;
    // 0x800FCF2C: j           L_800FCF50
    // 0x800FCF30: addiu       $s5, $zero, 0x1
    ctx->r21 = ADD32(0, 0X1);
        goto L_800FCF50;
    // 0x800FCF30: addiu       $s5, $zero, 0x1
    ctx->r21 = ADD32(0, 0X1);
L_800FCF34:
    // 0x800FCF34: sb          $v0, 0x7($s1)
    MEM_B(0X7, ctx->r17) = ctx->r2;
L_800FCF38:
    // 0x800FCF38: lwc1        $f2, 0x1C($s4)
    ctx->f2.u32l = MEM_W(ctx->r20, 0X1C);
    // 0x800FCF3C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800FCF40: c.le.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl <= ctx->f0.fl;
    // 0x800FCF44: nop

    // 0x800FCF48: bc1f        L_800FD2C4
    if (!c1cs) {
        // 0x800FCF4C: nop
    
            goto L_800FD2C4;
    }
    // 0x800FCF4C: nop

L_800FCF50:
    // 0x800FCF50: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800FCF54: lwc1        $f0, -0x6DB4($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X6DB4);
    // 0x800FCF58: j           L_800FD070
    // 0x800FCF5C: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
        goto L_800FD070;
    // 0x800FCF5C: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
L_800FCF60:
    // 0x800FCF60: lwc1        $f0, 0x20($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X20);
    // 0x800FCF64: sub.s       $f2, $f0, $f20
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f2.fl = ctx->f0.fl - ctx->f20.fl;
    // 0x800FCF68: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800FCF6C: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x800FCF70: nop

    // 0x800FCF74: bc1f        L_800FCFCC
    if (!c1cs) {
        // 0x800FCF78: swc1        $f2, 0x20($s1)
        MEM_W(0X20, ctx->r17) = ctx->f2.u32l;
            goto L_800FCFCC;
    }
    // 0x800FCF78: swc1        $f2, 0x20($s1)
    MEM_W(0X20, ctx->r17) = ctx->f2.u32l;
    // 0x800FCF7C: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800FCF80: lwc1        $f0, -0x6DB0($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X6DB0);
    // 0x800FCF84: mul.s       $f0, $f2, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x800FCF88: add.s       $f0, $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f0.fl;
    // 0x800FCF8C: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800FCF90: lwc1        $f2, -0x6DAC($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X6DAC);
    // 0x800FCF94: c.le.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl <= ctx->f0.fl;
    // 0x800FCF98: nop

    // 0x800FCF9C: bc1tl       L_800FCFB4
    if (c1cs) {
        // 0x800FCFA0: sub.s       $f0, $f0, $f2
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
            goto L_800FCFB4;
    }
    goto skip_3;
    // 0x800FCFA0: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    skip_3:
    // 0x800FCFA4: trunc.w.s   $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    ctx->f6.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800FCFA8: mfc1        $v1, $f6
    ctx->r3 = (int32_t)ctx->f6.u32l;
    // 0x800FCFAC: j           L_800FCFE8
    // 0x800FCFB0: sb          $v1, 0x8($s1)
    MEM_B(0X8, ctx->r17) = ctx->r3;
        goto L_800FCFE8;
    // 0x800FCFB0: sb          $v1, 0x8($s1)
    MEM_B(0X8, ctx->r17) = ctx->r3;
L_800FCFB4:
    // 0x800FCFB4: lui         $v0, 0x8000
    ctx->r2 = S32(0X8000 << 16);
    // 0x800FCFB8: trunc.w.s   $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    ctx->f6.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800FCFBC: mfc1        $v1, $f6
    ctx->r3 = (int32_t)ctx->f6.u32l;
    // 0x800FCFC0: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x800FCFC4: j           L_800FCFE8
    // 0x800FCFC8: sb          $v1, 0x8($s1)
    MEM_B(0X8, ctx->r17) = ctx->r3;
        goto L_800FCFE8;
    // 0x800FCFC8: sb          $v1, 0x8($s1)
    MEM_B(0X8, ctx->r17) = ctx->r3;
L_800FCFCC:
    // 0x800FCFCC: andi        $v0, $s2, 0xFF
    ctx->r2 = ctx->r18 & 0XFF;
    // 0x800FCFD0: beq         $v0, $zero, L_800FCFE4
    if (ctx->r2 == 0) {
        // 0x800FCFD4: sb          $zero, 0x8($s1)
        MEM_B(0X8, ctx->r17) = 0;
            goto L_800FCFE4;
    }
    // 0x800FCFD4: sb          $zero, 0x8($s1)
    MEM_B(0X8, ctx->r17) = 0;
    // 0x800FCFD8: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // 0x800FCFDC: j           L_800FCFE8
    // 0x800FCFE0: sb          $v0, 0x1($s1)
    MEM_B(0X1, ctx->r17) = ctx->r2;
        goto L_800FCFE8;
    // 0x800FCFE0: sb          $v0, 0x1($s1)
    MEM_B(0X1, ctx->r17) = ctx->r2;
L_800FCFE4:
    // 0x800FCFE4: sb          $zero, 0x1($s1)
    MEM_B(0X1, ctx->r17) = 0;
L_800FCFE8:
    // 0x800FCFE8: addiu       $a0, $s1, 0x21C
    ctx->r4 = ADD32(ctx->r17, 0X21C);
    // 0x800FCFEC: addu        $a1, $s4, $zero
    ctx->r5 = ADD32(ctx->r20, 0);
    // 0x800FCFF0: jal         0x800FC564
    // 0x800FCFF4: addu        $a2, $s3, $zero
    ctx->r6 = ADD32(ctx->r19, 0);
    func_800FC564(rdram, ctx);
        goto after_15;
    // 0x800FCFF4: addu        $a2, $s3, $zero
    ctx->r6 = ADD32(ctx->r19, 0);
    after_15:
    // 0x800FCFF8: sb          $v0, 0x228($s1)
    MEM_B(0X228, ctx->r17) = ctx->r2;
    // 0x800FCFFC: andi        $v0, $s0, 0xFF
    ctx->r2 = ctx->r16 & 0XFF;
    // 0x800FD000: bne         $v0, $zero, L_800FD2C4
    if (ctx->r2 != 0) {
        // 0x800FD004: nop
    
            goto L_800FD2C4;
    }
    // 0x800FD004: nop

    // 0x800FD008: lbu         $v0, 0x2($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X2);
    // 0x800FD00C: beq         $v0, $zero, L_800FD2C4
    if (ctx->r2 == 0) {
        // 0x800FD010: nop
    
            goto L_800FD2C4;
    }
    // 0x800FD010: nop

    // 0x800FD014: lwc1        $f2, 0x1C($s4)
    ctx->f2.u32l = MEM_W(ctx->r20, 0X1C);
    // 0x800FD018: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800FD01C: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x800FD020: nop

    // 0x800FD024: bc1f        L_800FD2C4
    if (!c1cs) {
        // 0x800FD028: nop
    
            goto L_800FD2C4;
    }
    // 0x800FD028: nop

    // 0x800FD02C: lbu         $v0, 0x6($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X6);
    // 0x800FD030: bne         $v0, $zero, L_800FD05C
    if (ctx->r2 != 0) {
        // 0x800FD034: andi        $v0, $s2, 0xFF
        ctx->r2 = ctx->r18 & 0XFF;
            goto L_800FD05C;
    }
    // 0x800FD034: andi        $v0, $s2, 0xFF
    ctx->r2 = ctx->r18 & 0XFF;
    // 0x800FD038: bne         $v0, $zero, L_800FD048
    if (ctx->r2 != 0) {
        // 0x800FD03C: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_800FD048;
    }
    // 0x800FD03C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800FD040:
    // 0x800FD040: j           L_800FD2C4
    // 0x800FD044: sb          $v0, 0x7($s1)
    MEM_B(0X7, ctx->r17) = ctx->r2;
        goto L_800FD2C4;
    // 0x800FD044: sb          $v0, 0x7($s1)
    MEM_B(0X7, ctx->r17) = ctx->r2;
L_800FD048:
    // 0x800FD048: lbu         $v0, 0x7($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X7);
    // 0x800FD04C: beq         $v0, $zero, L_800FD2C4
    if (ctx->r2 == 0) {
        // 0x800FD050: nop
    
            goto L_800FD2C4;
    }
    // 0x800FD050: nop

    // 0x800FD054: j           L_800FD064
    // 0x800FD058: sb          $zero, 0x7($s1)
    MEM_B(0X7, ctx->r17) = 0;
        goto L_800FD064;
    // 0x800FD058: sb          $zero, 0x7($s1)
    MEM_B(0X7, ctx->r17) = 0;
L_800FD05C:
    // 0x800FD05C: beq         $v0, $zero, L_800FD2C4
    if (ctx->r2 == 0) {
        // 0x800FD060: nop
    
            goto L_800FD2C4;
    }
    // 0x800FD060: nop

L_800FD064:
    // 0x800FD064: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800FD068: lwc1        $f0, -0x6DA8($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X6DA8);
    // 0x800FD06C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800FD070:
    // 0x800FD070: sb          $v0, 0x1($s1)
    MEM_B(0X1, ctx->r17) = ctx->r2;
    // 0x800FD074: j           L_800FD2C4
    // 0x800FD078: swc1        $f0, 0x20($s1)
    MEM_W(0X20, ctx->r17) = ctx->f0.u32l;
        goto L_800FD2C4;
    // 0x800FD078: swc1        $f0, 0x20($s1)
    MEM_W(0X20, ctx->r17) = ctx->f0.u32l;
L_800FD07C:
    // 0x800FD07C: lbu         $v1, 0x1($s1)
    ctx->r3 = MEM_BU(ctx->r17, 0X1);
    // 0x800FD080: beq         $v1, $zero, L_800FD098
    if (ctx->r3 == 0) {
        // 0x800FD084: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_800FD098;
    }
    // 0x800FD084: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800FD088: beq         $v1, $v0, L_800FD2B8
    if (ctx->r3 == ctx->r2) {
        // 0x800FD08C: andi        $v0, $s2, 0xFF
        ctx->r2 = ctx->r18 & 0XFF;
            goto L_800FD2B8;
    }
    // 0x800FD08C: andi        $v0, $s2, 0xFF
    ctx->r2 = ctx->r18 & 0XFF;
    // 0x800FD090: j           L_800FD2C4
    // 0x800FD094: nop

        goto L_800FD2C4;
    // 0x800FD094: nop

L_800FD098:
    // 0x800FD098: andi        $v0, $s2, 0xFF
    ctx->r2 = ctx->r18 & 0XFF;
    // 0x800FD09C: beq         $v0, $zero, L_800FD2C4
    if (ctx->r2 == 0) {
        // 0x800FD0A0: nop
    
            goto L_800FD2C4;
    }
    // 0x800FD0A0: nop

    // 0x800FD0A4: lbu         $v0, 0x2($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X2);
    // 0x800FD0A8: beq         $v0, $zero, L_800FD0C0
    if (ctx->r2 == 0) {
        // 0x800FD0AC: andi        $v0, $s0, 0xFF
        ctx->r2 = ctx->r16 & 0XFF;
            goto L_800FD0C0;
    }
    // 0x800FD0AC: andi        $v0, $s0, 0xFF
    ctx->r2 = ctx->r16 & 0XFF;
    // 0x800FD0B0: bne         $v0, $zero, L_800FD0C4
    if (ctx->r2 != 0) {
        // 0x800FD0B4: addiu       $a0, $zero, 0x67
        ctx->r4 = ADD32(0, 0X67);
            goto L_800FD0C4;
    }
    // 0x800FD0B4: addiu       $a0, $zero, 0x67
    ctx->r4 = ADD32(0, 0X67);
    // 0x800FD0B8: j           L_800FD0D0
    // 0x800FD0BC: addiu       $s5, $zero, 0x1
    ctx->r21 = ADD32(0, 0X1);
        goto L_800FD0D0;
    // 0x800FD0BC: addiu       $s5, $zero, 0x1
    ctx->r21 = ADD32(0, 0X1);
L_800FD0C0:
    // 0x800FD0C0: addiu       $a0, $zero, 0x67
    ctx->r4 = ADD32(0, 0X67);
L_800FD0C4:
    // 0x800FD0C4: addiu       $a1, $zero, 0x5A
    ctx->r5 = ADD32(0, 0X5A);
    // 0x800FD0C8: jal         0x80087EE8
    // 0x800FD0CC: addiu       $a2, $zero, 0x40
    ctx->r6 = ADD32(0, 0X40);
    func_80087EE8(rdram, ctx);
        goto after_16;
    // 0x800FD0CC: addiu       $a2, $zero, 0x40
    ctx->r6 = ADD32(0, 0X40);
    after_16:
L_800FD0D0:
    // 0x800FD0D0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800FD0D4: j           L_800FD2C4
    // 0x800FD0D8: sb          $v0, 0x1($s1)
    MEM_B(0X1, ctx->r17) = ctx->r2;
        goto L_800FD2C4;
    // 0x800FD0D8: sb          $v0, 0x1($s1)
    MEM_B(0X1, ctx->r17) = ctx->r2;
L_800FD0DC:
    // 0x800FD0DC: lbu         $v1, 0x1($s1)
    ctx->r3 = MEM_BU(ctx->r17, 0X1);
    // 0x800FD0E0: addiu       $s3, $zero, 0x1
    ctx->r19 = ADD32(0, 0X1);
    // 0x800FD0E4: beq         $v1, $s3, L_800FD1B0
    if (ctx->r3 == ctx->r19) {
        // 0x800FD0E8: slti        $v0, $v1, 0x2
        ctx->r2 = SIGNED(ctx->r3) < 0X2 ? 1 : 0;
            goto L_800FD1B0;
    }
    // 0x800FD0E8: slti        $v0, $v1, 0x2
    ctx->r2 = SIGNED(ctx->r3) < 0X2 ? 1 : 0;
    // 0x800FD0EC: beq         $v0, $zero, L_800FD104
    if (ctx->r2 == 0) {
        // 0x800FD0F0: addiu       $v0, $zero, 0x2
        ctx->r2 = ADD32(0, 0X2);
            goto L_800FD104;
    }
    // 0x800FD0F0: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x800FD0F4: beq         $v1, $zero, L_800FD114
    if (ctx->r3 == 0) {
        // 0x800FD0F8: andi        $v0, $s2, 0xFF
        ctx->r2 = ctx->r18 & 0XFF;
            goto L_800FD114;
    }
    // 0x800FD0F8: andi        $v0, $s2, 0xFF
    ctx->r2 = ctx->r18 & 0XFF;
    // 0x800FD0FC: j           L_800FD2C4
    // 0x800FD100: nop

        goto L_800FD2C4;
    // 0x800FD100: nop

L_800FD104:
    // 0x800FD104: beq         $v1, $v0, L_800FD2B8
    if (ctx->r3 == ctx->r2) {
        // 0x800FD108: andi        $v0, $s2, 0xFF
        ctx->r2 = ctx->r18 & 0XFF;
            goto L_800FD2B8;
    }
    // 0x800FD108: andi        $v0, $s2, 0xFF
    ctx->r2 = ctx->r18 & 0XFF;
    // 0x800FD10C: j           L_800FD2C4
    // 0x800FD110: nop

        goto L_800FD2C4;
    // 0x800FD110: nop

L_800FD114:
    // 0x800FD114: beq         $v0, $zero, L_800FD2C4
    if (ctx->r2 == 0) {
        // 0x800FD118: nop
    
            goto L_800FD2C4;
    }
    // 0x800FD118: nop

    // 0x800FD11C: lbu         $v0, 0x2($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X2);
    // 0x800FD120: beq         $v0, $zero, L_800FD198
    if (ctx->r2 == 0) {
        // 0x800FD124: andi        $v0, $s0, 0xFF
        ctx->r2 = ctx->r16 & 0XFF;
            goto L_800FD198;
    }
    // 0x800FD124: andi        $v0, $s0, 0xFF
    ctx->r2 = ctx->r16 & 0XFF;
    // 0x800FD128: bne         $v0, $zero, L_800FD19C
    if (ctx->r2 != 0) {
        // 0x800FD12C: addiu       $a0, $zero, 0x67
        ctx->r4 = ADD32(0, 0X67);
            goto L_800FD19C;
    }
    // 0x800FD12C: addiu       $a0, $zero, 0x67
    ctx->r4 = ADD32(0, 0X67);
    // 0x800FD130: addiu       $s0, $s1, 0x230
    ctx->r16 = ADD32(ctx->r17, 0X230);
    // 0x800FD134: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x800FD138: addu        $a1, $s4, $zero
    ctx->r5 = ADD32(ctx->r20, 0);
    // 0x800FD13C: addiu       $a2, $a1, 0x24
    ctx->r6 = ADD32(ctx->r5, 0X24);
    // 0x800FD140: lui         $a3, 0x4190
    ctx->r7 = S32(0X4190 << 16);
    // 0x800FD144: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800FD148: lwc1        $f0, -0x6DA4($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X6DA4);
    // 0x800FD14C: addiu       $v0, $zero, 0x7
    ctx->r2 = ADD32(0, 0X7);
    // 0x800FD150: sb          $s3, 0x1($s1)
    MEM_B(0X1, ctx->r17) = ctx->r19;
    // 0x800FD154: sw          $zero, 0x22C($s1)
    MEM_W(0X22C, ctx->r17) = 0;
    // 0x800FD158: sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    // 0x800FD15C: addiu       $v0, $zero, 0x3A
    ctx->r2 = ADD32(0, 0X3A);
    // 0x800FD160: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // 0x800FD164: addiu       $v0, $zero, 0x64
    ctx->r2 = ADD32(0, 0X64);
    // 0x800FD168: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x800FD16C: addiu       $v0, $zero, 0x3C
    ctx->r2 = ADD32(0, 0X3C);
    // 0x800FD170: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x800FD174: jal         0x800989D8
    // 0x800FD178: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    func_800989D8(rdram, ctx);
        goto after_17;
    // 0x800FD178: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    after_17:
    // 0x800FD17C: jal         0x80098E84
    // 0x800FD180: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_80098E84(rdram, ctx);
        goto after_18;
    // 0x800FD180: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_18:
    // 0x800FD184: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // 0x800FD188: jal         0x80088D1C
    // 0x800FD18C: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    func_80088D1C(rdram, ctx);
        goto after_19;
    // 0x800FD18C: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    after_19:
    // 0x800FD190: j           L_800FD2C4
    // 0x800FD194: sb          $s3, 0x274($s1)
    MEM_B(0X274, ctx->r17) = ctx->r19;
        goto L_800FD2C4;
    // 0x800FD194: sb          $s3, 0x274($s1)
    MEM_B(0X274, ctx->r17) = ctx->r19;
L_800FD198:
    // 0x800FD198: addiu       $a0, $zero, 0x67
    ctx->r4 = ADD32(0, 0X67);
L_800FD19C:
    // 0x800FD19C: addiu       $a1, $zero, 0x5A
    ctx->r5 = ADD32(0, 0X5A);
    // 0x800FD1A0: jal         0x80087EE8
    // 0x800FD1A4: addiu       $a2, $zero, 0x40
    ctx->r6 = ADD32(0, 0X40);
    func_80087EE8(rdram, ctx);
        goto after_20;
    // 0x800FD1A4: addiu       $a2, $zero, 0x40
    ctx->r6 = ADD32(0, 0X40);
    after_20:
    // 0x800FD1A8: j           L_800FD218
    // 0x800FD1AC: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
        goto L_800FD218;
    // 0x800FD1AC: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
L_800FD1B0:
    // 0x800FD1B0: lwc1        $f0, 0x22C($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X22C);
    // 0x800FD1B4: add.s       $f0, $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f20.fl;
    // 0x800FD1B8: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800FD1BC: lwc1        $f2, -0x6DA0($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X6DA0);
    // 0x800FD1C0: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800FD1C4: lwc1        $f4, -0x6D9C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X6D9C);
    // 0x800FD1C8: div.s       $f2, $f0, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = DIV_S(ctx->f0.fl, ctx->f2.fl);
    // 0x800FD1CC: add.s       $f20, $f2, $f4
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f20.fl = ctx->f2.fl + ctx->f4.fl;
    // 0x800FD1D0: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800FD1D4: lwc1        $f2, -0x6D98($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X6D98);
    // 0x800FD1D8: c.lt.s      $f2, $f20
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f2.fl < ctx->f20.fl;
    // 0x800FD1DC: nop

    // 0x800FD1E0: bc1f        L_800FD1EC
    if (!c1cs) {
        // 0x800FD1E4: swc1        $f0, 0x22C($s1)
        MEM_W(0X22C, ctx->r17) = ctx->f0.u32l;
            goto L_800FD1EC;
    }
    // 0x800FD1E4: swc1        $f0, 0x22C($s1)
    MEM_W(0X22C, ctx->r17) = ctx->f0.u32l;
    // 0x800FD1E8: mov.s       $f20, $f2
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    ctx->f20.fl = ctx->f2.fl;
L_800FD1EC:
    // 0x800FD1EC: andi        $v0, $s2, 0xFF
    ctx->r2 = ctx->r18 & 0XFF;
    // 0x800FD1F0: beq         $v0, $zero, L_800FD200
    if (ctx->r2 == 0) {
        // 0x800FD1F4: andi        $v0, $s0, 0xFF
        ctx->r2 = ctx->r16 & 0XFF;
            goto L_800FD200;
    }
    // 0x800FD1F4: andi        $v0, $s0, 0xFF
    ctx->r2 = ctx->r16 & 0XFF;
    // 0x800FD1F8: beql        $v0, $zero, L_800FD240
    if (ctx->r2 == 0) {
        // 0x800FD1FC: addiu       $s0, $s1, 0x230
        ctx->r16 = ADD32(ctx->r17, 0X230);
            goto L_800FD240;
    }
    goto skip_4;
    // 0x800FD1FC: addiu       $s0, $s1, 0x230
    ctx->r16 = ADD32(ctx->r17, 0X230);
    skip_4:
L_800FD200:
    // 0x800FD200: jal         0x80098DE0
    // 0x800FD204: addiu       $a0, $s1, 0x230
    ctx->r4 = ADD32(ctx->r17, 0X230);
    func_80098DE0(rdram, ctx);
        goto after_21;
    // 0x800FD204: addiu       $a0, $s1, 0x230
    ctx->r4 = ADD32(ctx->r17, 0X230);
    after_21:
    // 0x800FD208: andi        $v0, $s0, 0xFF
    ctx->r2 = ctx->r16 & 0XFF;
    // 0x800FD20C: beq         $v0, $zero, L_800FD220
    if (ctx->r2 == 0) {
        // 0x800FD210: sb          $zero, 0x274($s1)
        MEM_B(0X274, ctx->r17) = 0;
            goto L_800FD220;
    }
    // 0x800FD210: sb          $zero, 0x274($s1)
    MEM_B(0X274, ctx->r17) = 0;
    // 0x800FD214: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
L_800FD218:
    // 0x800FD218: j           L_800FD2C4
    // 0x800FD21C: sb          $v0, 0x1($s1)
    MEM_B(0X1, ctx->r17) = ctx->r2;
        goto L_800FD2C4;
    // 0x800FD21C: sb          $v0, 0x1($s1)
    MEM_B(0X1, ctx->r17) = ctx->r2;
L_800FD220:
    // 0x800FD220: lwc1        $f2, 0x22C($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0X22C);
    // 0x800FD224: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800FD228: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x800FD22C: nop

    // 0x800FD230: bc1f        L_800FD2C4
    if (!c1cs) {
        // 0x800FD234: sb          $zero, 0x1($s1)
        MEM_B(0X1, ctx->r17) = 0;
            goto L_800FD2C4;
    }
    // 0x800FD234: sb          $zero, 0x1($s1)
    MEM_B(0X1, ctx->r17) = 0;
    // 0x800FD238: j           L_800FD2C4
    // 0x800FD23C: addiu       $s5, $zero, 0x1
    ctx->r21 = ADD32(0, 0X1);
        goto L_800FD2C4;
    // 0x800FD23C: addiu       $s5, $zero, 0x1
    ctx->r21 = ADD32(0, 0X1);
L_800FD240:
    // 0x800FD240: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x800FD244: addu        $a1, $s4, $zero
    ctx->r5 = ADD32(ctx->r20, 0);
    // 0x800FD248: addiu       $a2, $a1, 0x24
    ctx->r6 = ADD32(ctx->r5, 0X24);
    // 0x800FD24C: jal         0x800988E8
    // 0x800FD250: addiu       $a3, $zero, 0x64
    ctx->r7 = ADD32(0, 0X64);
    func_800988E8(rdram, ctx);
        goto after_22;
    // 0x800FD250: addiu       $a3, $zero, 0x64
    ctx->r7 = ADD32(0, 0X64);
    after_22:
    // 0x800FD254: jal         0x80098E84
    // 0x800FD258: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_80098E84(rdram, ctx);
        goto after_23;
    // 0x800FD258: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_23:
    // 0x800FD25C: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800FD260: lwc1        $f0, -0x6D94($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X6D94);
    // 0x800FD264: mul.s       $f0, $f20, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = MUL_S(ctx->f20.fl, ctx->f0.fl);
    // 0x800FD268: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800FD26C: lwc1        $f2, -0x6D90($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X6D90);
    // 0x800FD270: c.le.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl <= ctx->f0.fl;
    // 0x800FD274: nop

    // 0x800FD278: bc1t        L_800FD290
    if (c1cs) {
        // 0x800FD27C: addu        $a0, $v0, $zero
        ctx->r4 = ADD32(ctx->r2, 0);
            goto L_800FD290;
    }
    // 0x800FD27C: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // 0x800FD280: trunc.w.s   $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    ctx->f6.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800FD284: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x800FD288: j           L_800FD2A4
    // 0x800FD28C: nop

        goto L_800FD2A4;
    // 0x800FD28C: nop

L_800FD290:
    // 0x800FD290: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x800FD294: lui         $v0, 0x8000
    ctx->r2 = S32(0X8000 << 16);
    // 0x800FD298: trunc.w.s   $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    ctx->f6.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800FD29C: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x800FD2A0: or          $a1, $a1, $v0
    ctx->r5 = ctx->r5 | ctx->r2;
L_800FD2A4:
    // 0x800FD2A4: jal         0x80088D1C
    // 0x800FD2A8: andi        $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 & 0XFFFF;
    func_80088D1C(rdram, ctx);
        goto after_24;
    // 0x800FD2A8: andi        $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 & 0XFFFF;
    after_24:
    // 0x800FD2AC: j           L_800FD2C4
    // 0x800FD2B0: nop

        goto L_800FD2C4;
    // 0x800FD2B0: nop

L_800FD2B4:
    // 0x800FD2B4: andi        $v0, $s2, 0xFF
    ctx->r2 = ctx->r18 & 0XFF;
L_800FD2B8:
    // 0x800FD2B8: bne         $v0, $zero, L_800FD2C4
    if (ctx->r2 != 0) {
        // 0x800FD2BC: nop
    
            goto L_800FD2C4;
    }
    // 0x800FD2BC: nop

L_800FD2C0:
    // 0x800FD2C0: sb          $zero, 0x1($s1)
    MEM_B(0X1, ctx->r17) = 0;
L_800FD2C4:
    // 0x800FD2C4: lbu         $a0, 0x2($s1)
    ctx->r4 = MEM_BU(ctx->r17, 0X2);
    // 0x800FD2C8: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // 0x800FD2CC: andi        $v1, $a0, 0xFF
    ctx->r3 = ctx->r4 & 0XFF;
    // 0x800FD2D0: beq         $v1, $v0, L_800FD2EC
    if (ctx->r3 == ctx->r2) {
        // 0x800FD2D4: andi        $v0, $s5, 0xFF
        ctx->r2 = ctx->r21 & 0XFF;
            goto L_800FD2EC;
    }
    // 0x800FD2D4: andi        $v0, $s5, 0xFF
    ctx->r2 = ctx->r21 & 0XFF;
    // 0x800FD2D8: beq         $v0, $zero, L_800FD2F0
    if (ctx->r2 == 0) {
        // 0x800FD2DC: addu        $v0, $s5, $zero
        ctx->r2 = ADD32(ctx->r21, 0);
            goto L_800FD2F0;
    }
    // 0x800FD2DC: addu        $v0, $s5, $zero
    ctx->r2 = ADD32(ctx->r21, 0);
    // 0x800FD2E0: beq         $v1, $zero, L_800FD2EC
    if (ctx->r3 == 0) {
        // 0x800FD2E4: addiu       $v0, $a0, -0x1
        ctx->r2 = ADD32(ctx->r4, -0X1);
            goto L_800FD2EC;
    }
    // 0x800FD2E4: addiu       $v0, $a0, -0x1
    ctx->r2 = ADD32(ctx->r4, -0X1);
    // 0x800FD2E8: sb          $v0, 0x2($s1)
    MEM_B(0X2, ctx->r17) = ctx->r2;
L_800FD2EC:
    // 0x800FD2EC: addu        $v0, $s5, $zero
    ctx->r2 = ADD32(ctx->r21, 0);
L_800FD2F0:
    // 0x800FD2F0: lw          $ra, 0x5C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X5C);
    // 0x800FD2F4: lw          $s6, 0x58($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X58);
    // 0x800FD2F8: lw          $s5, 0x54($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X54);
    // 0x800FD2FC: lw          $s4, 0x50($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X50);
    // 0x800FD300: lw          $s3, 0x4C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X4C);
    // 0x800FD304: lw          $s2, 0x48($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X48);
    // 0x800FD308: lw          $s1, 0x44($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X44);
    // 0x800FD30C: lw          $s0, 0x40($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X40);
    // 0x800FD310: ldc1        $f20, 0x60($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X60);
    // 0x800FD314: jr          $ra
    // 0x800FD318: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    return;
    // 0x800FD318: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
;}
RECOMP_FUNC void func_800FD31C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800FD31C: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800FD320: lw          $v0, -0x35E4($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X35E4);
    // 0x800FD324: addiu       $sp, $sp, -0x88
    ctx->r29 = ADD32(ctx->r29, -0X88);
    // 0x800FD328: sw          $s4, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r20;
    // 0x800FD32C: addu        $s4, $a1, $zero
    ctx->r20 = ADD32(ctx->r5, 0);
    // 0x800FD330: sw          $s3, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r19;
    // 0x800FD334: sw          $ra, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r31;
    // 0x800FD338: sw          $s5, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r21;
    // 0x800FD33C: sw          $s2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r18;
    // 0x800FD340: sw          $s1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r17;
    // 0x800FD344: sw          $s0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r16;
    // 0x800FD348: sdc1        $f26, 0x80($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X80, ctx->r29);
    // 0x800FD34C: sdc1        $f24, 0x78($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X78, ctx->r29);
    // 0x800FD350: sdc1        $f22, 0x70($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X70, ctx->r29);
    // 0x800FD354: sdc1        $f20, 0x68($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X68, ctx->r29);
    // 0x800FD358: andi        $v0, $v0, 0x100
    ctx->r2 = ctx->r2 & 0X100;
    // 0x800FD35C: bne         $v0, $zero, L_800FE400
    if (ctx->r2 != 0) {
        // 0x800FD360: addu        $s3, $a2, $zero
        ctx->r19 = ADD32(ctx->r6, 0);
            goto L_800FE400;
    }
    // 0x800FD360: addu        $s3, $a2, $zero
    ctx->r19 = ADD32(ctx->r6, 0);
    // 0x800FD364: andi        $v1, $a0, 0xFF
    ctx->r3 = ctx->r4 & 0XFF;
    // 0x800FD368: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x800FD36C: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800FD370: sll         $v0, $v0, 4
    ctx->r2 = S32(ctx->r2 << 4);
    // 0x800FD374: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x800FD378: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x800FD37C: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
    // 0x800FD380: addiu       $v1, $v1, -0x35D0
    ctx->r3 = ADD32(ctx->r3, -0X35D0);
    // 0x800FD384: addu        $s2, $v0, $v1
    ctx->r18 = ADD32(ctx->r2, ctx->r3);
    // 0x800FD388: lbu         $v0, 0x5($s2)
    ctx->r2 = MEM_BU(ctx->r18, 0X5);
    // 0x800FD38C: beq         $v0, $zero, L_800FD3BC
    if (ctx->r2 == 0) {
        // 0x800FD390: nop
    
            goto L_800FD3BC;
    }
    // 0x800FD390: nop

    // 0x800FD394: jal         0x8006C940
    // 0x800FD398: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    getPlayerVehicleId(rdram, ctx);
        goto after_0;
    // 0x800FD398: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    after_0:
    // 0x800FD39C: addiu       $v1, $zero, 0x4
    ctx->r3 = ADD32(0, 0X4);
    // 0x800FD3A0: bne         $v0, $v1, L_800FD3BC
    if (ctx->r2 != ctx->r3) {
        // 0x800FD3A4: nop
    
            goto L_800FD3BC;
    }
    // 0x800FD3A4: nop

    // 0x800FD3A8: jal         0x800AE3BC
    // 0x800FD3AC: nop

    func_800AE3BC(rdram, ctx);
        goto after_1;
    // 0x800FD3AC: nop

    after_1:
    // 0x800FD3B0: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x800FD3B4: beq         $v0, $zero, L_800FE400
    if (ctx->r2 == 0) {
        // 0x800FD3B8: nop
    
            goto L_800FE400;
    }
    // 0x800FD3B8: nop

L_800FD3BC:
    // 0x800FD3BC: lw          $v0, 0x0($s4)
    ctx->r2 = MEM_W(ctx->r20, 0X0);
    // 0x800FD3C0: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800FD3C4: lwc1        $f2, -0x6D8C($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X6D8C);
    // 0x800FD3C8: lwc1        $f0, 0x10($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X10);
    // 0x800FD3CC: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x800FD3D0: div.s       $f24, $f0, $f2
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f24.fl = DIV_S(ctx->f0.fl, ctx->f2.fl);
    // 0x800FD3D4: lwc1        $f2, 0x14($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X14);
    // 0x800FD3D8: cvt.s.w     $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    ctx->f2.fl = CVT_S_W(ctx->f2.u32l);
    // 0x800FD3DC: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800FD3E0: lwc1        $f0, -0x6D88($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X6D88);
    // 0x800FD3E4: lbu         $v0, 0x5($s2)
    ctx->r2 = MEM_BU(ctx->r18, 0X5);
    // 0x800FD3E8: bne         $v0, $zero, L_800FD414
    if (ctx->r2 != 0) {
        // 0x800FD3EC: div.s       $f26, $f2, $f0
        CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f26.fl = DIV_S(ctx->f2.fl, ctx->f0.fl);
            goto L_800FD414;
    }
    // 0x800FD3EC: div.s       $f26, $f2, $f0
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f26.fl = DIV_S(ctx->f2.fl, ctx->f0.fl);
    // 0x800FD3F0: lbu         $v1, 0x0($s2)
    ctx->r3 = MEM_BU(ctx->r18, 0X0);
    // 0x800FD3F4: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x800FD3F8: beq         $v1, $v0, L_800FD408
    if (ctx->r3 == ctx->r2) {
        // 0x800FD3FC: addiu       $v0, $zero, 0x8
        ctx->r2 = ADD32(0, 0X8);
            goto L_800FD408;
    }
    // 0x800FD3FC: addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
    // 0x800FD400: bne         $v1, $v0, L_800FDB60
    if (ctx->r3 != ctx->r2) {
        // 0x800FD404: addiu       $v0, $zero, 0x4
        ctx->r2 = ADD32(0, 0X4);
            goto L_800FDB60;
    }
    // 0x800FD404: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
L_800FD408:
    // 0x800FD408: lbu         $v0, 0x1($s2)
    ctx->r2 = MEM_BU(ctx->r18, 0X1);
    // 0x800FD40C: beq         $v0, $zero, L_800FDB58
    if (ctx->r2 == 0) {
        // 0x800FD410: nop
    
            goto L_800FDB58;
    }
    // 0x800FD410: nop

L_800FD414:
    // 0x800FD414: jal         0x8006C940
    // 0x800FD418: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    getPlayerVehicleId(rdram, ctx);
        goto after_2;
    // 0x800FD418: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    after_2:
    // 0x800FD41C: addiu       $v1, $zero, 0x4
    ctx->r3 = ADD32(0, 0X4);
    // 0x800FD420: bne         $v0, $v1, L_800FD43C
    if (ctx->r2 != ctx->r3) {
        // 0x800FD424: nop
    
            goto L_800FD43C;
    }
    // 0x800FD424: nop

    // 0x800FD428: lwc1        $f0, 0x18($s3)
    ctx->f0.u32l = MEM_W(ctx->r19, 0X18);
    // 0x800FD42C: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800FD430: lwc1        $f2, -0x6D84($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X6D84);
    // 0x800FD434: j           L_800FD45C
    // 0x800FD438: nop

        goto L_800FD45C;
    // 0x800FD438: nop

L_800FD43C:
    // 0x800FD43C: jal         0x8006C940
    // 0x800FD440: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    getPlayerVehicleId(rdram, ctx);
        goto after_3;
    // 0x800FD440: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    after_3:
    // 0x800FD444: addiu       $v1, $zero, 0x7
    ctx->r3 = ADD32(0, 0X7);
    // 0x800FD448: bne         $v0, $v1, L_800FD480
    if (ctx->r2 != ctx->r3) {
        // 0x800FD44C: nop
    
            goto L_800FD480;
    }
    // 0x800FD44C: nop

    // 0x800FD450: lwc1        $f0, 0x18($s3)
    ctx->f0.u32l = MEM_W(ctx->r19, 0X18);
    // 0x800FD454: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800FD458: lwc1        $f2, -0x6D80($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X6D80);
L_800FD45C:
    // 0x800FD45C: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x800FD460: swc1        $f0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f0.u32l;
    // 0x800FD464: lwc1        $f0, 0x1C($s3)
    ctx->f0.u32l = MEM_W(ctx->r19, 0X1C);
    // 0x800FD468: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x800FD46C: swc1        $f0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f0.u32l;
    // 0x800FD470: lwc1        $f0, 0x20($s3)
    ctx->f0.u32l = MEM_W(ctx->r19, 0X20);
    // 0x800FD474: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x800FD478: j           L_800FD490
    // 0x800FD47C: swc1        $f0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f0.u32l;
        goto L_800FD490;
    // 0x800FD47C: swc1        $f0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f0.u32l;
L_800FD480:
    // 0x800FD480: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800FD484: swc1        $f0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f0.u32l;
    // 0x800FD488: swc1        $f0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f0.u32l;
    // 0x800FD48C: swc1        $f0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f0.u32l;
L_800FD490:
    // 0x800FD490: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x800FD494: addiu       $a0, $v0, -0x72E8
    ctx->r4 = ADD32(ctx->r2, -0X72E8);
    // 0x800FD498: lw          $v0, 0x4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X4);
    // 0x800FD49C: lhu         $v1, 0x4($v0)
    ctx->r3 = MEM_HU(ctx->r2, 0X4);
    // 0x800FD4A0: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x800FD4A4: beq         $v1, $v0, L_800FD574
    if (ctx->r3 == ctx->r2) {
        // 0x800FD4A8: addu        $s1, $zero, $zero
        ctx->r17 = ADD32(0, 0);
            goto L_800FD574;
    }
    // 0x800FD4A8: addu        $s1, $zero, $zero
    ctx->r17 = ADD32(0, 0);
    // 0x800FD4AC: lwc1        $f10, 0x38($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X38);
    // 0x800FD4B0: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800FD4B4: lwc1        $f4, -0x6D7C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X6D7C);
    // 0x800FD4B8: mul.s       $f0, $f10, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = MUL_S(ctx->f10.fl, ctx->f4.fl);
    // 0x800FD4BC: lwc1        $f2, 0x0($s3)
    ctx->f2.u32l = MEM_W(ctx->r19, 0X0);
    // 0x800FD4C0: add.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x800FD4C4: lwc1        $f0, 0xC($s3)
    ctx->f0.u32l = MEM_W(ctx->r19, 0XC);
    // 0x800FD4C8: add.s       $f0, $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f0.fl;
    // 0x800FD4CC: add.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x800FD4D0: lwc1        $f8, 0x3C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x800FD4D4: mul.s       $f0, $f8, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = MUL_S(ctx->f8.fl, ctx->f4.fl);
    // 0x800FD4D8: swc1        $f2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f2.u32l;
    // 0x800FD4DC: lwc1        $f2, 0x4($s3)
    ctx->f2.u32l = MEM_W(ctx->r19, 0X4);
    // 0x800FD4E0: add.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x800FD4E4: lwc1        $f0, 0x10($s3)
    ctx->f0.u32l = MEM_W(ctx->r19, 0X10);
    // 0x800FD4E8: add.s       $f0, $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f0.fl;
    // 0x800FD4EC: add.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x800FD4F0: lwc1        $f6, 0x40($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X40);
    // 0x800FD4F4: mul.s       $f4, $f6, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f4.fl = MUL_S(ctx->f6.fl, ctx->f4.fl);
    // 0x800FD4F8: swc1        $f2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f2.u32l;
    // 0x800FD4FC: lwc1        $f2, 0x8($s3)
    ctx->f2.u32l = MEM_W(ctx->r19, 0X8);
    // 0x800FD500: add.s       $f2, $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f4.fl;
    // 0x800FD504: lwc1        $f0, 0x14($s3)
    ctx->f0.u32l = MEM_W(ctx->r19, 0X14);
    // 0x800FD508: add.s       $f0, $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f0.fl;
    // 0x800FD50C: add.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x800FD510: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800FD514: lwc1        $f4, -0x6D78($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X6D78);
    // 0x800FD518: swc1        $f2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f2.u32l;
    // 0x800FD51C: lwc1        $f2, 0xC($s3)
    ctx->f2.u32l = MEM_W(ctx->r19, 0XC);
    // 0x800FD520: mul.s       $f2, $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f4.fl);
    // 0x800FD524: lwc1        $f0, 0x0($s3)
    ctx->f0.u32l = MEM_W(ctx->r19, 0X0);
    // 0x800FD528: add.s       $f0, $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f10.fl;
    // 0x800FD52C: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x800FD530: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    // 0x800FD534: lwc1        $f2, 0x10($s3)
    ctx->f2.u32l = MEM_W(ctx->r19, 0X10);
    // 0x800FD538: mul.s       $f2, $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f4.fl);
    // 0x800FD53C: lwc1        $f0, 0x4($s3)
    ctx->f0.u32l = MEM_W(ctx->r19, 0X4);
    // 0x800FD540: add.s       $f0, $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f8.fl;
    // 0x800FD544: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x800FD548: swc1        $f0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f0.u32l;
    // 0x800FD54C: lwc1        $f2, 0x14($s3)
    ctx->f2.u32l = MEM_W(ctx->r19, 0X14);
    // 0x800FD550: mul.s       $f2, $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f4.fl);
    // 0x800FD554: lwc1        $f0, 0x8($s3)
    ctx->f0.u32l = MEM_W(ctx->r19, 0X8);
    // 0x800FD558: add.s       $f0, $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f6.fl;
    // 0x800FD55C: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x800FD560: j           L_800FD61C
    // 0x800FD564: swc1        $f0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f0.u32l;
        goto L_800FD61C;
    // 0x800FD564: swc1        $f0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f0.u32l;
L_800FD568:
    // 0x800FD568: lw          $v0, 0x4($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X4);
    // 0x800FD56C: j           L_800FD58C
    // 0x800FD570: addiu       $s5, $v0, 0x28
    ctx->r21 = ADD32(ctx->r2, 0X28);
        goto L_800FD58C;
    // 0x800FD570: addiu       $s5, $v0, 0x28
    ctx->r21 = ADD32(ctx->r2, 0X28);
L_800FD574:
    // 0x800FD574: addu        $v1, $a0, $zero
    ctx->r3 = ADD32(ctx->r4, 0);
L_800FD578:
    // 0x800FD578: lbu         $v0, 0x0($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X0);
    // 0x800FD57C: bne         $v0, $zero, L_800FD568
    if (ctx->r2 != 0) {
        // 0x800FD580: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_800FD568;
    }
    // 0x800FD580: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x800FD584: beq         $s1, $zero, L_800FD578
    if (ctx->r17 == 0) {
        // 0x800FD588: addiu       $v1, $v1, 0x144
        ctx->r3 = ADD32(ctx->r3, 0X144);
            goto L_800FD578;
    }
    // 0x800FD588: addiu       $v1, $v1, 0x144
    ctx->r3 = ADD32(ctx->r3, 0X144);
L_800FD58C:
    // 0x800FD58C: jal         0x8006C940
    // 0x800FD590: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    getPlayerVehicleId(rdram, ctx);
        goto after_4;
    // 0x800FD590: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    after_4:
    // 0x800FD594: addiu       $v1, $zero, 0x4
    ctx->r3 = ADD32(0, 0X4);
    // 0x800FD598: beq         $v0, $v1, L_800FD5C8
    if (ctx->r2 == ctx->r3) {
        // 0x800FD59C: nop
    
            goto L_800FD5C8;
    }
    // 0x800FD59C: nop

    // 0x800FD5A0: lwc1        $f0, 0xC($s3)
    ctx->f0.u32l = MEM_W(ctx->r19, 0XC);
    // 0x800FD5A4: add.s       $f0, $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f0.fl;
    // 0x800FD5A8: lwc1        $f2, 0x24($s5)
    ctx->f2.u32l = MEM_W(ctx->r21, 0X24);
    // 0x800FD5AC: add.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x800FD5B0: swc1        $f2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f2.u32l;
    // 0x800FD5B4: swc1        $f2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f2.u32l;
    // 0x800FD5B8: lwc1        $f0, 0x10($s3)
    ctx->f0.u32l = MEM_W(ctx->r19, 0X10);
    // 0x800FD5BC: lwc1        $f2, 0x28($s5)
    ctx->f2.u32l = MEM_W(ctx->r21, 0X28);
    // 0x800FD5C0: j           L_800FD5F8
    // 0x800FD5C4: add.s       $f0, $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f0.fl;
        goto L_800FD5F8;
    // 0x800FD5C4: add.s       $f0, $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f0.fl;
L_800FD5C8:
    // 0x800FD5C8: lwc1        $f0, 0xC($s3)
    ctx->f0.u32l = MEM_W(ctx->r19, 0XC);
    // 0x800FD5CC: add.s       $f0, $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f0.fl;
    // 0x800FD5D0: lwc1        $f2, 0x24($s5)
    ctx->f2.u32l = MEM_W(ctx->r21, 0X24);
    // 0x800FD5D4: add.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x800FD5D8: swc1        $f2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f2.u32l;
    // 0x800FD5DC: swc1        $f2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f2.u32l;
    // 0x800FD5E0: lwc1        $f0, 0x10($s3)
    ctx->f0.u32l = MEM_W(ctx->r19, 0X10);
    // 0x800FD5E4: add.s       $f0, $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f0.fl;
    // 0x800FD5E8: lwc1        $f2, 0x28($s5)
    ctx->f2.u32l = MEM_W(ctx->r21, 0X28);
    // 0x800FD5EC: add.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x800FD5F0: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800FD5F4: lwc1        $f0, -0x6D74($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X6D74);
L_800FD5F8:
    // 0x800FD5F8: add.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x800FD5FC: swc1        $f2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f2.u32l;
    // 0x800FD600: swc1        $f2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f2.u32l;
    // 0x800FD604: lwc1        $f0, 0x14($s3)
    ctx->f0.u32l = MEM_W(ctx->r19, 0X14);
    // 0x800FD608: add.s       $f0, $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f0.fl;
    // 0x800FD60C: lwc1        $f2, 0x2C($s5)
    ctx->f2.u32l = MEM_W(ctx->r21, 0X2C);
    // 0x800FD610: add.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x800FD614: swc1        $f2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f2.u32l;
    // 0x800FD618: swc1        $f2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f2.u32l;
L_800FD61C:
    // 0x800FD61C: lw          $v0, 0x0($s4)
    ctx->r2 = MEM_W(ctx->r20, 0X0);
    // 0x800FD620: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800FD624: lwc1        $f0, -0x6D70($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X6D70);
    // 0x800FD628: lwc1        $f2, 0x20($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X20);
    // 0x800FD62C: mul.s       $f20, $f2, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f20.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x800FD630: addu        $s1, $zero, $zero
    ctx->r17 = ADD32(0, 0);
    // 0x800FD634: addiu       $s0, $sp, 0x10
    ctx->r16 = ADD32(ctx->r29, 0X10);
    // 0x800FD638: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800FD63C: lwc1        $f22, -0x6D6C($at)
    ctx->f22.u32l = MEM_W(ctx->r1, -0X6D6C);
    // 0x800FD640: jal         0x8002B190
    // 0x800FD644: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    cosf_recomp(rdram, ctx);
        goto after_5;
    // 0x800FD644: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    after_5:
    // 0x800FD648: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    // 0x800FD64C: jal         0x80033960
    // 0x800FD650: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    sinf_recomp(rdram, ctx);
        goto after_6;
    // 0x800FD650: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    after_6:
    // 0x800FD654: div.s       $f20, $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f20.fl = DIV_S(ctx->f20.fl, ctx->f0.fl);
L_800FD658:
    // 0x800FD658: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x800FD65C: lw          $a0, 0x0($s4)
    ctx->r4 = MEM_W(ctx->r20, 0X0);
    // 0x800FD660: addiu       $a2, $sp, 0x38
    ctx->r6 = ADD32(ctx->r29, 0X38);
    // 0x800FD664: jal         0x800193E8
    // 0x800FD668: addiu       $a0, $a0, 0x2C
    ctx->r4 = ADD32(ctx->r4, 0X2C);
    func_800193E8(rdram, ctx);
        goto after_7;
    // 0x800FD668: addiu       $a0, $a0, 0x2C
    ctx->r4 = ADD32(ctx->r4, 0X2C);
    after_7:
    // 0x800FD66C: lwc1        $f0, 0x38($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X38);
    // 0x800FD670: mul.s       $f0, $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f20.fl);
    // 0x800FD674: lwc1        $f2, 0x40($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X40);
    // 0x800FD678: div.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f2.fl);
    // 0x800FD67C: mul.s       $f0, $f0, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f22.fl);
    // 0x800FD680: swc1        $f0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f0.u32l;
    // 0x800FD684: lwc1        $f0, 0x3C($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x800FD688: mul.s       $f0, $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f20.fl);
    // 0x800FD68C: lwc1        $f2, 0x40($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X40);
    // 0x800FD690: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x800FD694: div.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f2.fl);
    // 0x800FD698: swc1        $f0, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f0.u32l;
    // 0x800FD69C: lwc1        $f0, 0x40($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X40);
    // 0x800FD6A0: sltiu       $v0, $s1, 0x2
    ctx->r2 = ctx->r17 < 0X2 ? 1 : 0;
    // 0x800FD6A4: swc1        $f0, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f0.u32l;
    // 0x800FD6A8: bne         $v0, $zero, L_800FD658
    if (ctx->r2 != 0) {
        // 0x800FD6AC: addiu       $s0, $s0, 0xC
        ctx->r16 = ADD32(ctx->r16, 0XC);
            goto L_800FD658;
    }
    // 0x800FD6AC: addiu       $s0, $s0, 0xC
    ctx->r16 = ADD32(ctx->r16, 0XC);
    // 0x800FD6B0: lw          $v0, 0x0($s4)
    ctx->r2 = MEM_W(ctx->r20, 0X0);
    // 0x800FD6B4: lw          $v0, 0x10($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X10);
    // 0x800FD6B8: lwc1        $f2, 0x10($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X10);
    // 0x800FD6BC: srl         $v1, $v0, 31
    ctx->r3 = S32(U32(ctx->r2) >> 31);
    // 0x800FD6C0: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800FD6C4: sra         $v0, $v0, 1
    ctx->r2 = S32(SIGNED(ctx->r2) >> 1);
    // 0x800FD6C8: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x800FD6CC: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x800FD6D0: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x800FD6D4: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800FD6D8: lwc1        $f4, -0x6D68($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X6D68);
    // 0x800FD6DC: mul.s       $f2, $f24, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = MUL_S(ctx->f24.fl, ctx->f4.fl);
    // 0x800FD6E0: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x800FD6E4: swc1        $f0, 0x40($s2)
    MEM_W(0X40, ctx->r18) = ctx->f0.u32l;
    // 0x800FD6E8: lw          $v0, 0x0($s4)
    ctx->r2 = MEM_W(ctx->r20, 0X0);
    // 0x800FD6EC: mul.s       $f4, $f26, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f4.fl = MUL_S(ctx->f26.fl, ctx->f4.fl);
    // 0x800FD6F0: lw          $v0, 0x14($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X14);
    // 0x800FD6F4: lwc1        $f2, 0x14($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X14);
    // 0x800FD6F8: srl         $v1, $v0, 31
    ctx->r3 = S32(U32(ctx->r2) >> 31);
    // 0x800FD6FC: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800FD700: sra         $v0, $v0, 1
    ctx->r2 = S32(SIGNED(ctx->r2) >> 1);
    // 0x800FD704: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x800FD708: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x800FD70C: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x800FD710: sub.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f4.fl;
    // 0x800FD714: swc1        $f0, 0x44($s2)
    MEM_W(0X44, ctx->r18) = ctx->f0.u32l;
    // 0x800FD718: lw          $v0, 0x0($s4)
    ctx->r2 = MEM_W(ctx->r20, 0X0);
    // 0x800FD71C: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800FD720: lwc1        $f2, -0x6D64($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X6D64);
    // 0x800FD724: lwc1        $f0, 0x10($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X10);
    // 0x800FD728: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x800FD72C: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x800FD730: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x800FD734: swc1        $f0, 0x4C($s2)
    MEM_W(0X4C, ctx->r18) = ctx->f0.u32l;
    // 0x800FD738: lw          $v0, 0x0($s4)
    ctx->r2 = MEM_W(ctx->r20, 0X0);
    // 0x800FD73C: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800FD740: lwc1        $f2, -0x6D60($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X6D60);
    // 0x800FD744: lwc1        $f0, 0x14($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X14);
    // 0x800FD748: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x800FD74C: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x800FD750: lbu         $v0, 0x1($s2)
    ctx->r2 = MEM_BU(ctx->r18, 0X1);
    // 0x800FD754: lbu         $v1, 0x0($s2)
    ctx->r3 = MEM_BU(ctx->r18, 0X0);
    // 0x800FD758: sltu        $a0, $zero, $v0
    ctx->r4 = 0 < ctx->r2 ? 1 : 0;
    // 0x800FD75C: addu        $a2, $a0, $zero
    ctx->r6 = ADD32(ctx->r4, 0);
    // 0x800FD760: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // 0x800FD764: bne         $v1, $v0, L_800FD770
    if (ctx->r3 != ctx->r2) {
        // 0x800FD768: swc1        $f0, 0x50($s2)
        MEM_W(0X50, ctx->r18) = ctx->f0.u32l;
            goto L_800FD770;
    }
    // 0x800FD768: swc1        $f0, 0x50($s2)
    MEM_W(0X50, ctx->r18) = ctx->f0.u32l;
    // 0x800FD76C: addu        $a1, $a0, $zero
    ctx->r5 = ADD32(ctx->r4, 0);
L_800FD770:
    // 0x800FD770: lbu         $v1, 0x8($s2)
    ctx->r3 = MEM_BU(ctx->r18, 0X8);
    // 0x800FD774: lbu         $v0, 0x5($s2)
    ctx->r2 = MEM_BU(ctx->r18, 0X5);
    // 0x800FD778: lwc1        $f6, 0x24($s2)
    ctx->f6.u32l = MEM_W(ctx->r18, 0X24);
    // 0x800FD77C: beq         $v0, $zero, L_800FD888
    if (ctx->r2 == 0) {
        // 0x800FD780: addiu       $a0, $s2, 0x54
        ctx->r4 = ADD32(ctx->r18, 0X54);
            goto L_800FD888;
    }
    // 0x800FD780: addiu       $a0, $s2, 0x54
    ctx->r4 = ADD32(ctx->r18, 0X54);
    // 0x800FD784: andi        $v0, $a1, 0xFF
    ctx->r2 = ctx->r5 & 0XFF;
    // 0x800FD788: beq         $v0, $zero, L_800FD7E8
    if (ctx->r2 == 0) {
        // 0x800FD78C: andi        $v0, $v1, 0xFF
        ctx->r2 = ctx->r3 & 0XFF;
            goto L_800FD7E8;
    }
    // 0x800FD78C: andi        $v0, $v1, 0xFF
    ctx->r2 = ctx->r3 & 0XFF;
    // 0x800FD790: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x800FD794: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x800FD798: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800FD79C: lwc1        $f4, -0x6D5C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X6D5C);
    // 0x800FD7A0: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800FD7A4: lwc1        $f2, -0x6D58($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X6D58);
    // 0x800FD7A8: div.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f4.fl);
    // 0x800FD7AC: sub.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl - ctx->f0.fl;
    // 0x800FD7B0: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800FD7B4: lwc1        $f0, -0x6D54($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X6D54);
    // 0x800FD7B8: mul.s       $f0, $f2, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x800FD7BC: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800FD7C0: lwc1        $f2, -0x6D50($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X6D50);
    // 0x800FD7C4: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // 0x800FD7C8: sb          $zero, 0x54($s2)
    MEM_B(0X54, ctx->r18) = 0;
    // 0x800FD7CC: sb          $v0, 0x1($a0)
    MEM_B(0X1, ctx->r4) = ctx->r2;
    // 0x800FD7D0: c.le.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl <= ctx->f0.fl;
    // 0x800FD7D4: nop

    // 0x800FD7D8: bc1f        L_800FD844
    if (!c1cs) {
        // 0x800FD7DC: sb          $zero, 0x2($a0)
        MEM_B(0X2, ctx->r4) = 0;
            goto L_800FD844;
    }
    // 0x800FD7DC: sb          $zero, 0x2($a0)
    MEM_B(0X2, ctx->r4) = 0;
    // 0x800FD7E0: j           L_800FD858
    // 0x800FD7E4: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
        goto L_800FD858;
    // 0x800FD7E4: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
L_800FD7E8:
    // 0x800FD7E8: andi        $v0, $a2, 0xFF
    ctx->r2 = ctx->r6 & 0XFF;
    // 0x800FD7EC: beq         $v0, $zero, L_800FD870
    if (ctx->r2 == 0) {
        // 0x800FD7F0: andi        $v0, $v1, 0xFF
        ctx->r2 = ctx->r3 & 0XFF;
            goto L_800FD870;
    }
    // 0x800FD7F0: andi        $v0, $v1, 0xFF
    ctx->r2 = ctx->r3 & 0XFF;
    // 0x800FD7F4: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x800FD7F8: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x800FD7FC: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800FD800: lwc1        $f4, -0x6D4C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X6D4C);
    // 0x800FD804: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800FD808: lwc1        $f2, -0x6D48($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X6D48);
    // 0x800FD80C: div.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f4.fl);
    // 0x800FD810: sub.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl - ctx->f0.fl;
    // 0x800FD814: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800FD818: lwc1        $f0, -0x6D44($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X6D44);
    // 0x800FD81C: mul.s       $f0, $f2, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x800FD820: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800FD824: lwc1        $f2, -0x6D40($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X6D40);
    // 0x800FD828: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // 0x800FD82C: sb          $zero, 0x54($s2)
    MEM_B(0X54, ctx->r18) = 0;
    // 0x800FD830: sb          $v0, 0x1($a0)
    MEM_B(0X1, ctx->r4) = ctx->r2;
    // 0x800FD834: c.le.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl <= ctx->f0.fl;
    // 0x800FD838: nop

    // 0x800FD83C: bc1t        L_800FD854
    if (c1cs) {
        // 0x800FD840: sb          $zero, 0x2($a0)
        MEM_B(0X2, ctx->r4) = 0;
            goto L_800FD854;
    }
    // 0x800FD840: sb          $zero, 0x2($a0)
    MEM_B(0X2, ctx->r4) = 0;
L_800FD844:
    // 0x800FD844: trunc.w.s   $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    ctx->f14.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800FD848: mfc1        $v1, $f14
    ctx->r3 = (int32_t)ctx->f14.u32l;
    // 0x800FD84C: j           L_800FD888
    // 0x800FD850: sb          $v1, 0x3($a0)
    MEM_B(0X3, ctx->r4) = ctx->r3;
        goto L_800FD888;
    // 0x800FD850: sb          $v1, 0x3($a0)
    MEM_B(0X3, ctx->r4) = ctx->r3;
L_800FD854:
    // 0x800FD854: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
L_800FD858:
    // 0x800FD858: lui         $v0, 0x8000
    ctx->r2 = S32(0X8000 << 16);
    // 0x800FD85C: trunc.w.s   $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    ctx->f14.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800FD860: mfc1        $v1, $f14
    ctx->r3 = (int32_t)ctx->f14.u32l;
    // 0x800FD864: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x800FD868: j           L_800FD888
    // 0x800FD86C: sb          $v1, 0x3($a0)
    MEM_B(0X3, ctx->r4) = ctx->r3;
        goto L_800FD888;
    // 0x800FD86C: sb          $v1, 0x3($a0)
    MEM_B(0X3, ctx->r4) = ctx->r3;
L_800FD870:
    // 0x800FD870: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // 0x800FD874: sb          $zero, 0x54($s2)
    MEM_B(0X54, ctx->r18) = 0;
    // 0x800FD878: sb          $v0, 0x1($a0)
    MEM_B(0X1, ctx->r4) = ctx->r2;
    // 0x800FD87C: addiu       $v0, $zero, 0x64
    ctx->r2 = ADD32(0, 0X64);
    // 0x800FD880: sb          $zero, 0x2($a0)
    MEM_B(0X2, ctx->r4) = 0;
    // 0x800FD884: sb          $v0, 0x3($a0)
    MEM_B(0X3, ctx->r4) = ctx->r2;
L_800FD888:
    // 0x800FD888: lbu         $v0, 0x3($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X3);
    // 0x800FD88C: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x800FD890: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x800FD894: mul.s       $f0, $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x800FD898: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800FD89C: lwc1        $f2, -0x6D3C($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X6D3C);
    // 0x800FD8A0: c.le.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl <= ctx->f0.fl;
    // 0x800FD8A4: nop

    // 0x800FD8A8: bc1tl       L_800FD8C0
    if (c1cs) {
        // 0x800FD8AC: sub.s       $f0, $f0, $f2
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
            goto L_800FD8C0;
    }
    goto skip_0;
    // 0x800FD8AC: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    skip_0:
    // 0x800FD8B0: trunc.w.s   $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    ctx->f14.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800FD8B4: mfc1        $v1, $f14
    ctx->r3 = (int32_t)ctx->f14.u32l;
    // 0x800FD8B8: j           L_800FD8D4
    // 0x800FD8BC: sb          $v1, 0x3($a0)
    MEM_B(0X3, ctx->r4) = ctx->r3;
        goto L_800FD8D4;
    // 0x800FD8BC: sb          $v1, 0x3($a0)
    MEM_B(0X3, ctx->r4) = ctx->r3;
L_800FD8C0:
    // 0x800FD8C0: lui         $v0, 0x8000
    ctx->r2 = S32(0X8000 << 16);
    // 0x800FD8C4: trunc.w.s   $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    ctx->f14.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800FD8C8: mfc1        $v1, $f14
    ctx->r3 = (int32_t)ctx->f14.u32l;
    // 0x800FD8CC: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x800FD8D0: sb          $v1, 0x3($a0)
    MEM_B(0X3, ctx->r4) = ctx->r3;
L_800FD8D4:
    // 0x800FD8D4: lw          $v0, 0x0($s4)
    ctx->r2 = MEM_W(ctx->r20, 0X0);
    // 0x800FD8D8: lw          $v0, 0x8($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X8);
    // 0x800FD8DC: beq         $v0, $zero, L_800FD8F4
    if (ctx->r2 == 0) {
        // 0x800FD8E0: sw          $v0, 0x28($s2)
        MEM_W(0X28, ctx->r18) = ctx->r2;
            goto L_800FD8F4;
    }
    // 0x800FD8E0: sw          $v0, 0x28($s2)
    MEM_W(0X28, ctx->r18) = ctx->r2;
    // 0x800FD8E4: lw          $v0, 0x0($s4)
    ctx->r2 = MEM_W(ctx->r20, 0X0);
    // 0x800FD8E8: lw          $v1, 0x8($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X8);
    // 0x800FD8EC: addiu       $v0, $s2, 0x28
    ctx->r2 = ADD32(ctx->r18, 0X28);
    // 0x800FD8F0: sw          $v0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r2;
L_800FD8F4:
    // 0x800FD8F4: sw          $zero, 0x2C($s2)
    MEM_W(0X2C, ctx->r18) = 0;
    // 0x800FD8F8: lw          $v1, 0x0($s4)
    ctx->r3 = MEM_W(ctx->r20, 0X0);
    // 0x800FD8FC: addiu       $v0, $s2, 0x28
    ctx->r2 = ADD32(ctx->r18, 0X28);
    // 0x800FD900: sw          $v0, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r2;
    // 0x800FD904: lw          $v0, 0x0($s4)
    ctx->r2 = MEM_W(ctx->r20, 0X0);
    // 0x800FD908: lw          $v0, 0x10($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X10);
    // 0x800FD90C: lwc1        $f2, 0x1C($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x800FD910: srl         $v1, $v0, 31
    ctx->r3 = S32(U32(ctx->r2) >> 31);
    // 0x800FD914: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800FD918: sra         $v0, $v0, 1
    ctx->r2 = S32(SIGNED(ctx->r2) >> 1);
    // 0x800FD91C: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x800FD920: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x800FD924: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x800FD928: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800FD92C: lwc1        $f4, -0x6D38($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X6D38);
    // 0x800FD930: mul.s       $f2, $f24, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = MUL_S(ctx->f24.fl, ctx->f4.fl);
    // 0x800FD934: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x800FD938: swc1        $f0, 0x70($s2)
    MEM_W(0X70, ctx->r18) = ctx->f0.u32l;
    // 0x800FD93C: lw          $v0, 0x0($s4)
    ctx->r2 = MEM_W(ctx->r20, 0X0);
    // 0x800FD940: mul.s       $f4, $f26, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f4.fl = MUL_S(ctx->f26.fl, ctx->f4.fl);
    // 0x800FD944: lw          $v0, 0x14($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X14);
    // 0x800FD948: lwc1        $f2, 0x20($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X20);
    // 0x800FD94C: srl         $v1, $v0, 31
    ctx->r3 = S32(U32(ctx->r2) >> 31);
    // 0x800FD950: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800FD954: sra         $v0, $v0, 1
    ctx->r2 = S32(SIGNED(ctx->r2) >> 1);
    // 0x800FD958: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x800FD95C: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x800FD960: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x800FD964: sub.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f4.fl;
    // 0x800FD968: swc1        $f0, 0x74($s2)
    MEM_W(0X74, ctx->r18) = ctx->f0.u32l;
    // 0x800FD96C: lw          $v0, 0x0($s4)
    ctx->r2 = MEM_W(ctx->r20, 0X0);
    // 0x800FD970: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800FD974: lwc1        $f2, -0x6D34($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X6D34);
    // 0x800FD978: lwc1        $f0, 0x10($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X10);
    // 0x800FD97C: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x800FD980: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x800FD984: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x800FD988: swc1        $f0, 0x7C($s2)
    MEM_W(0X7C, ctx->r18) = ctx->f0.u32l;
    // 0x800FD98C: lw          $v0, 0x0($s4)
    ctx->r2 = MEM_W(ctx->r20, 0X0);
    // 0x800FD990: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800FD994: lwc1        $f2, -0x6D30($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X6D30);
    // 0x800FD998: lwc1        $f0, 0x14($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X14);
    // 0x800FD99C: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x800FD9A0: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x800FD9A4: lbu         $v0, 0x1($s2)
    ctx->r2 = MEM_BU(ctx->r18, 0X1);
    // 0x800FD9A8: lbu         $v1, 0x0($s2)
    ctx->r3 = MEM_BU(ctx->r18, 0X0);
    // 0x800FD9AC: sltu        $a0, $zero, $v0
    ctx->r4 = 0 < ctx->r2 ? 1 : 0;
    // 0x800FD9B0: addu        $a2, $a0, $zero
    ctx->r6 = ADD32(ctx->r4, 0);
    // 0x800FD9B4: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // 0x800FD9B8: bne         $v1, $v0, L_800FD9C4
    if (ctx->r3 != ctx->r2) {
        // 0x800FD9BC: swc1        $f0, 0x80($s2)
        MEM_W(0X80, ctx->r18) = ctx->f0.u32l;
            goto L_800FD9C4;
    }
    // 0x800FD9BC: swc1        $f0, 0x80($s2)
    MEM_W(0X80, ctx->r18) = ctx->f0.u32l;
    // 0x800FD9C0: addu        $a1, $a0, $zero
    ctx->r5 = ADD32(ctx->r4, 0);
L_800FD9C4:
    // 0x800FD9C4: lbu         $v1, 0x8($s2)
    ctx->r3 = MEM_BU(ctx->r18, 0X8);
    // 0x800FD9C8: lbu         $v0, 0x5($s2)
    ctx->r2 = MEM_BU(ctx->r18, 0X5);
    // 0x800FD9CC: lwc1        $f6, 0x24($s2)
    ctx->f6.u32l = MEM_W(ctx->r18, 0X24);
    // 0x800FD9D0: beq         $v0, $zero, L_800FDADC
    if (ctx->r2 == 0) {
        // 0x800FD9D4: addiu       $a0, $s2, 0x84
        ctx->r4 = ADD32(ctx->r18, 0X84);
            goto L_800FDADC;
    }
    // 0x800FD9D4: addiu       $a0, $s2, 0x84
    ctx->r4 = ADD32(ctx->r18, 0X84);
    // 0x800FD9D8: andi        $v0, $a1, 0xFF
    ctx->r2 = ctx->r5 & 0XFF;
    // 0x800FD9DC: beq         $v0, $zero, L_800FDA3C
    if (ctx->r2 == 0) {
        // 0x800FD9E0: andi        $v0, $v1, 0xFF
        ctx->r2 = ctx->r3 & 0XFF;
            goto L_800FDA3C;
    }
    // 0x800FD9E0: andi        $v0, $v1, 0xFF
    ctx->r2 = ctx->r3 & 0XFF;
    // 0x800FD9E4: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x800FD9E8: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x800FD9EC: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800FD9F0: lwc1        $f4, -0x6D2C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X6D2C);
    // 0x800FD9F4: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800FD9F8: lwc1        $f2, -0x6D28($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X6D28);
    // 0x800FD9FC: div.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f4.fl);
    // 0x800FDA00: sub.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl - ctx->f0.fl;
    // 0x800FDA04: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800FDA08: lwc1        $f0, -0x6D24($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X6D24);
    // 0x800FDA0C: mul.s       $f0, $f2, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x800FDA10: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800FDA14: lwc1        $f2, -0x6D20($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X6D20);
    // 0x800FDA18: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // 0x800FDA1C: sb          $zero, 0x84($s2)
    MEM_B(0X84, ctx->r18) = 0;
    // 0x800FDA20: sb          $v0, 0x1($a0)
    MEM_B(0X1, ctx->r4) = ctx->r2;
    // 0x800FDA24: c.le.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl <= ctx->f0.fl;
    // 0x800FDA28: nop

    // 0x800FDA2C: bc1f        L_800FDA98
    if (!c1cs) {
        // 0x800FDA30: sb          $zero, 0x2($a0)
        MEM_B(0X2, ctx->r4) = 0;
            goto L_800FDA98;
    }
    // 0x800FDA30: sb          $zero, 0x2($a0)
    MEM_B(0X2, ctx->r4) = 0;
    // 0x800FDA34: j           L_800FDAAC
    // 0x800FDA38: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
        goto L_800FDAAC;
    // 0x800FDA38: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
L_800FDA3C:
    // 0x800FDA3C: andi        $v0, $a2, 0xFF
    ctx->r2 = ctx->r6 & 0XFF;
    // 0x800FDA40: beq         $v0, $zero, L_800FDAC4
    if (ctx->r2 == 0) {
        // 0x800FDA44: andi        $v0, $v1, 0xFF
        ctx->r2 = ctx->r3 & 0XFF;
            goto L_800FDAC4;
    }
    // 0x800FDA44: andi        $v0, $v1, 0xFF
    ctx->r2 = ctx->r3 & 0XFF;
    // 0x800FDA48: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x800FDA4C: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x800FDA50: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800FDA54: lwc1        $f4, -0x6D1C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X6D1C);
    // 0x800FDA58: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800FDA5C: lwc1        $f2, -0x6D18($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X6D18);
    // 0x800FDA60: div.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f4.fl);
    // 0x800FDA64: sub.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl - ctx->f0.fl;
    // 0x800FDA68: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800FDA6C: lwc1        $f0, -0x6D14($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X6D14);
    // 0x800FDA70: mul.s       $f0, $f2, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x800FDA74: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800FDA78: lwc1        $f2, -0x6D10($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X6D10);
    // 0x800FDA7C: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // 0x800FDA80: sb          $zero, 0x84($s2)
    MEM_B(0X84, ctx->r18) = 0;
    // 0x800FDA84: sb          $v0, 0x1($a0)
    MEM_B(0X1, ctx->r4) = ctx->r2;
    // 0x800FDA88: c.le.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl <= ctx->f0.fl;
    // 0x800FDA8C: nop

    // 0x800FDA90: bc1t        L_800FDAA8
    if (c1cs) {
        // 0x800FDA94: sb          $zero, 0x2($a0)
        MEM_B(0X2, ctx->r4) = 0;
            goto L_800FDAA8;
    }
    // 0x800FDA94: sb          $zero, 0x2($a0)
    MEM_B(0X2, ctx->r4) = 0;
L_800FDA98:
    // 0x800FDA98: trunc.w.s   $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    ctx->f14.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800FDA9C: mfc1        $v1, $f14
    ctx->r3 = (int32_t)ctx->f14.u32l;
    // 0x800FDAA0: j           L_800FDADC
    // 0x800FDAA4: sb          $v1, 0x3($a0)
    MEM_B(0X3, ctx->r4) = ctx->r3;
        goto L_800FDADC;
    // 0x800FDAA4: sb          $v1, 0x3($a0)
    MEM_B(0X3, ctx->r4) = ctx->r3;
L_800FDAA8:
    // 0x800FDAA8: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
L_800FDAAC:
    // 0x800FDAAC: lui         $v0, 0x8000
    ctx->r2 = S32(0X8000 << 16);
    // 0x800FDAB0: trunc.w.s   $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    ctx->f14.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800FDAB4: mfc1        $v1, $f14
    ctx->r3 = (int32_t)ctx->f14.u32l;
    // 0x800FDAB8: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x800FDABC: j           L_800FDADC
    // 0x800FDAC0: sb          $v1, 0x3($a0)
    MEM_B(0X3, ctx->r4) = ctx->r3;
        goto L_800FDADC;
    // 0x800FDAC0: sb          $v1, 0x3($a0)
    MEM_B(0X3, ctx->r4) = ctx->r3;
L_800FDAC4:
    // 0x800FDAC4: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // 0x800FDAC8: sb          $zero, 0x84($s2)
    MEM_B(0X84, ctx->r18) = 0;
    // 0x800FDACC: sb          $v0, 0x1($a0)
    MEM_B(0X1, ctx->r4) = ctx->r2;
    // 0x800FDAD0: addiu       $v0, $zero, 0x64
    ctx->r2 = ADD32(0, 0X64);
    // 0x800FDAD4: sb          $zero, 0x2($a0)
    MEM_B(0X2, ctx->r4) = 0;
    // 0x800FDAD8: sb          $v0, 0x3($a0)
    MEM_B(0X3, ctx->r4) = ctx->r2;
L_800FDADC:
    // 0x800FDADC: lbu         $v0, 0x3($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X3);
    // 0x800FDAE0: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x800FDAE4: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x800FDAE8: mul.s       $f0, $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x800FDAEC: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800FDAF0: lwc1        $f2, -0x6D0C($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X6D0C);
    // 0x800FDAF4: c.le.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl <= ctx->f0.fl;
    // 0x800FDAF8: nop

    // 0x800FDAFC: bc1tl       L_800FDB14
    if (c1cs) {
        // 0x800FDB00: sub.s       $f0, $f0, $f2
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
            goto L_800FDB14;
    }
    goto skip_1;
    // 0x800FDB00: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    skip_1:
    // 0x800FDB04: trunc.w.s   $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    ctx->f14.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800FDB08: mfc1        $v1, $f14
    ctx->r3 = (int32_t)ctx->f14.u32l;
    // 0x800FDB0C: j           L_800FDB28
    // 0x800FDB10: sb          $v1, 0x3($a0)
    MEM_B(0X3, ctx->r4) = ctx->r3;
        goto L_800FDB28;
    // 0x800FDB10: sb          $v1, 0x3($a0)
    MEM_B(0X3, ctx->r4) = ctx->r3;
L_800FDB14:
    // 0x800FDB14: lui         $v0, 0x8000
    ctx->r2 = S32(0X8000 << 16);
    // 0x800FDB18: trunc.w.s   $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    ctx->f14.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800FDB1C: mfc1        $v1, $f14
    ctx->r3 = (int32_t)ctx->f14.u32l;
    // 0x800FDB20: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x800FDB24: sb          $v1, 0x3($a0)
    MEM_B(0X3, ctx->r4) = ctx->r3;
L_800FDB28:
    // 0x800FDB28: lw          $v0, 0x0($s4)
    ctx->r2 = MEM_W(ctx->r20, 0X0);
    // 0x800FDB2C: lw          $v0, 0x8($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X8);
    // 0x800FDB30: beq         $v0, $zero, L_800FDB48
    if (ctx->r2 == 0) {
        // 0x800FDB34: sw          $v0, 0x58($s2)
        MEM_W(0X58, ctx->r18) = ctx->r2;
            goto L_800FDB48;
    }
    // 0x800FDB34: sw          $v0, 0x58($s2)
    MEM_W(0X58, ctx->r18) = ctx->r2;
    // 0x800FDB38: lw          $v0, 0x0($s4)
    ctx->r2 = MEM_W(ctx->r20, 0X0);
    // 0x800FDB3C: lw          $v1, 0x8($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X8);
    // 0x800FDB40: addiu       $v0, $s2, 0x58
    ctx->r2 = ADD32(ctx->r18, 0X58);
    // 0x800FDB44: sw          $v0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r2;
L_800FDB48:
    // 0x800FDB48: sw          $zero, 0x5C($s2)
    MEM_W(0X5C, ctx->r18) = 0;
    // 0x800FDB4C: lw          $v1, 0x0($s4)
    ctx->r3 = MEM_W(ctx->r20, 0X0);
    // 0x800FDB50: addiu       $v0, $s2, 0x58
    ctx->r2 = ADD32(ctx->r18, 0X58);
    // 0x800FDB54: sw          $v0, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r2;
L_800FDB58:
    // 0x800FDB58: lbu         $v1, 0x0($s2)
    ctx->r3 = MEM_BU(ctx->r18, 0X0);
    // 0x800FDB5C: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
L_800FDB60:
    // 0x800FDB60: beq         $v1, $v0, L_800FE248
    if (ctx->r3 == ctx->r2) {
        // 0x800FDB64: slti        $v0, $v1, 0x5
        ctx->r2 = SIGNED(ctx->r3) < 0X5 ? 1 : 0;
            goto L_800FE248;
    }
    // 0x800FDB64: slti        $v0, $v1, 0x5
    ctx->r2 = SIGNED(ctx->r3) < 0X5 ? 1 : 0;
    // 0x800FDB68: beq         $v0, $zero, L_800FDB80
    if (ctx->r2 == 0) {
        // 0x800FDB6C: addiu       $v0, $zero, 0x3
        ctx->r2 = ADD32(0, 0X3);
            goto L_800FDB80;
    }
    // 0x800FDB6C: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x800FDB70: beq         $v1, $v0, L_800FDB8C
    if (ctx->r3 == ctx->r2) {
        // 0x800FDB74: nop
    
            goto L_800FDB8C;
    }
    // 0x800FDB74: nop

    // 0x800FDB78: j           L_800FE400
    // 0x800FDB7C: nop

        goto L_800FE400;
    // 0x800FDB7C: nop

L_800FDB80:
    // 0x800FDB80: addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
    // 0x800FDB84: bne         $v1, $v0, L_800FE400
    if (ctx->r3 != ctx->r2) {
        // 0x800FDB88: nop
    
            goto L_800FE400;
    }
    // 0x800FDB88: nop

L_800FDB8C:
    // 0x800FDB8C: lbu         $v0, 0x1($s2)
    ctx->r2 = MEM_BU(ctx->r18, 0X1);
    // 0x800FDB90: beq         $v0, $zero, L_800FE400
    if (ctx->r2 == 0) {
        // 0x800FDB94: lui         $v0, 0x8014
        ctx->r2 = S32(0X8014 << 16);
            goto L_800FE400;
    }
    // 0x800FDB94: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x800FDB98: addiu       $a0, $v0, -0x72E8
    ctx->r4 = ADD32(ctx->r2, -0X72E8);
    // 0x800FDB9C: lw          $v0, 0x4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X4);
    // 0x800FDBA0: lhu         $v1, 0x4($v0)
    ctx->r3 = MEM_HU(ctx->r2, 0X4);
    // 0x800FDBA4: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x800FDBA8: beq         $v1, $v0, L_800FDC40
    if (ctx->r3 == ctx->r2) {
        // 0x800FDBAC: addu        $s1, $zero, $zero
        ctx->r17 = ADD32(0, 0);
            goto L_800FDC40;
    }
    // 0x800FDBAC: addu        $s1, $zero, $zero
    ctx->r17 = ADD32(0, 0);
    // 0x800FDBB0: lwc1        $f2, 0xC($s3)
    ctx->f2.u32l = MEM_W(ctx->r19, 0XC);
    // 0x800FDBB4: add.s       $f2, $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f2.fl;
    // 0x800FDBB8: lwc1        $f0, 0x0($s3)
    ctx->f0.u32l = MEM_W(ctx->r19, 0X0);
    // 0x800FDBBC: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x800FDBC0: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    // 0x800FDBC4: lwc1        $f2, 0x10($s3)
    ctx->f2.u32l = MEM_W(ctx->r19, 0X10);
    // 0x800FDBC8: add.s       $f2, $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f2.fl;
    // 0x800FDBCC: lwc1        $f0, 0x4($s3)
    ctx->f0.u32l = MEM_W(ctx->r19, 0X4);
    // 0x800FDBD0: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x800FDBD4: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    // 0x800FDBD8: lwc1        $f2, 0x14($s3)
    ctx->f2.u32l = MEM_W(ctx->r19, 0X14);
    // 0x800FDBDC: add.s       $f2, $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f2.fl;
    // 0x800FDBE0: lwc1        $f0, 0x8($s3)
    ctx->f0.u32l = MEM_W(ctx->r19, 0X8);
    // 0x800FDBE4: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x800FDBE8: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800FDBEC: lwc1        $f4, -0x6D08($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X6D08);
    // 0x800FDBF0: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    // 0x800FDBF4: lwc1        $f2, 0xC($s3)
    ctx->f2.u32l = MEM_W(ctx->r19, 0XC);
    // 0x800FDBF8: mul.s       $f2, $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f4.fl);
    // 0x800FDBFC: lwc1        $f0, 0x0($s3)
    ctx->f0.u32l = MEM_W(ctx->r19, 0X0);
    // 0x800FDC00: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x800FDC04: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    // 0x800FDC08: lwc1        $f2, 0x10($s3)
    ctx->f2.u32l = MEM_W(ctx->r19, 0X10);
    // 0x800FDC0C: mul.s       $f2, $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f4.fl);
    // 0x800FDC10: lwc1        $f0, 0x4($s3)
    ctx->f0.u32l = MEM_W(ctx->r19, 0X4);
    // 0x800FDC14: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x800FDC18: swc1        $f0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f0.u32l;
    // 0x800FDC1C: lwc1        $f2, 0x14($s3)
    ctx->f2.u32l = MEM_W(ctx->r19, 0X14);
    // 0x800FDC20: mul.s       $f2, $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f4.fl);
    // 0x800FDC24: lwc1        $f0, 0x8($s3)
    ctx->f0.u32l = MEM_W(ctx->r19, 0X8);
    // 0x800FDC28: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x800FDC2C: j           L_800FDCE8
    // 0x800FDC30: swc1        $f0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f0.u32l;
        goto L_800FDCE8;
    // 0x800FDC30: swc1        $f0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f0.u32l;
L_800FDC34:
    // 0x800FDC34: lw          $v0, 0x4($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X4);
    // 0x800FDC38: j           L_800FDC58
    // 0x800FDC3C: addiu       $s5, $v0, 0x28
    ctx->r21 = ADD32(ctx->r2, 0X28);
        goto L_800FDC58;
    // 0x800FDC3C: addiu       $s5, $v0, 0x28
    ctx->r21 = ADD32(ctx->r2, 0X28);
L_800FDC40:
    // 0x800FDC40: addu        $v1, $a0, $zero
    ctx->r3 = ADD32(ctx->r4, 0);
L_800FDC44:
    // 0x800FDC44: lbu         $v0, 0x0($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X0);
    // 0x800FDC48: bne         $v0, $zero, L_800FDC34
    if (ctx->r2 != 0) {
        // 0x800FDC4C: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_800FDC34;
    }
    // 0x800FDC4C: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x800FDC50: beq         $s1, $zero, L_800FDC44
    if (ctx->r17 == 0) {
        // 0x800FDC54: addiu       $v1, $v1, 0x144
        ctx->r3 = ADD32(ctx->r3, 0X144);
            goto L_800FDC44;
    }
    // 0x800FDC54: addiu       $v1, $v1, 0x144
    ctx->r3 = ADD32(ctx->r3, 0X144);
L_800FDC58:
    // 0x800FDC58: jal         0x8006C940
    // 0x800FDC5C: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    getPlayerVehicleId(rdram, ctx);
        goto after_8;
    // 0x800FDC5C: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    after_8:
    // 0x800FDC60: addiu       $v1, $zero, 0x4
    ctx->r3 = ADD32(0, 0X4);
    // 0x800FDC64: beq         $v0, $v1, L_800FDC94
    if (ctx->r2 == ctx->r3) {
        // 0x800FDC68: nop
    
            goto L_800FDC94;
    }
    // 0x800FDC68: nop

    // 0x800FDC6C: lwc1        $f0, 0xC($s3)
    ctx->f0.u32l = MEM_W(ctx->r19, 0XC);
    // 0x800FDC70: add.s       $f0, $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f0.fl;
    // 0x800FDC74: lwc1        $f2, 0x24($s5)
    ctx->f2.u32l = MEM_W(ctx->r21, 0X24);
    // 0x800FDC78: add.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x800FDC7C: swc1        $f2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f2.u32l;
    // 0x800FDC80: swc1        $f2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f2.u32l;
    // 0x800FDC84: lwc1        $f0, 0x10($s3)
    ctx->f0.u32l = MEM_W(ctx->r19, 0X10);
    // 0x800FDC88: lwc1        $f2, 0x28($s5)
    ctx->f2.u32l = MEM_W(ctx->r21, 0X28);
    // 0x800FDC8C: j           L_800FDCC4
    // 0x800FDC90: add.s       $f0, $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f0.fl;
        goto L_800FDCC4;
    // 0x800FDC90: add.s       $f0, $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f0.fl;
L_800FDC94:
    // 0x800FDC94: lwc1        $f0, 0xC($s3)
    ctx->f0.u32l = MEM_W(ctx->r19, 0XC);
    // 0x800FDC98: add.s       $f0, $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f0.fl;
    // 0x800FDC9C: lwc1        $f2, 0x24($s5)
    ctx->f2.u32l = MEM_W(ctx->r21, 0X24);
    // 0x800FDCA0: add.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x800FDCA4: swc1        $f2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f2.u32l;
    // 0x800FDCA8: swc1        $f2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f2.u32l;
    // 0x800FDCAC: lwc1        $f0, 0x10($s3)
    ctx->f0.u32l = MEM_W(ctx->r19, 0X10);
    // 0x800FDCB0: add.s       $f0, $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f0.fl;
    // 0x800FDCB4: lwc1        $f2, 0x28($s5)
    ctx->f2.u32l = MEM_W(ctx->r21, 0X28);
    // 0x800FDCB8: add.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x800FDCBC: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800FDCC0: lwc1        $f0, -0x6D04($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X6D04);
L_800FDCC4:
    // 0x800FDCC4: add.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x800FDCC8: swc1        $f2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f2.u32l;
    // 0x800FDCCC: swc1        $f2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f2.u32l;
    // 0x800FDCD0: lwc1        $f0, 0x14($s3)
    ctx->f0.u32l = MEM_W(ctx->r19, 0X14);
    // 0x800FDCD4: add.s       $f0, $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f0.fl;
    // 0x800FDCD8: lwc1        $f2, 0x2C($s5)
    ctx->f2.u32l = MEM_W(ctx->r21, 0X2C);
    // 0x800FDCDC: add.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x800FDCE0: swc1        $f2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f2.u32l;
    // 0x800FDCE4: swc1        $f2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f2.u32l;
L_800FDCE8:
    // 0x800FDCE8: lw          $v0, 0x0($s4)
    ctx->r2 = MEM_W(ctx->r20, 0X0);
    // 0x800FDCEC: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800FDCF0: lwc1        $f0, -0x6D00($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X6D00);
    // 0x800FDCF4: lwc1        $f2, 0x20($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X20);
    // 0x800FDCF8: mul.s       $f20, $f2, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f20.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x800FDCFC: addu        $s1, $zero, $zero
    ctx->r17 = ADD32(0, 0);
    // 0x800FDD00: addiu       $s0, $sp, 0x10
    ctx->r16 = ADD32(ctx->r29, 0X10);
    // 0x800FDD04: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800FDD08: lwc1        $f22, -0x6CFC($at)
    ctx->f22.u32l = MEM_W(ctx->r1, -0X6CFC);
    // 0x800FDD0C: jal         0x8002B190
    // 0x800FDD10: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    cosf_recomp(rdram, ctx);
        goto after_9;
    // 0x800FDD10: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    after_9:
    // 0x800FDD14: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    // 0x800FDD18: jal         0x80033960
    // 0x800FDD1C: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    sinf_recomp(rdram, ctx);
        goto after_10;
    // 0x800FDD1C: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    after_10:
    // 0x800FDD20: div.s       $f20, $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f20.fl = DIV_S(ctx->f20.fl, ctx->f0.fl);
L_800FDD24:
    // 0x800FDD24: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x800FDD28: lw          $a0, 0x0($s4)
    ctx->r4 = MEM_W(ctx->r20, 0X0);
    // 0x800FDD2C: addiu       $a2, $sp, 0x38
    ctx->r6 = ADD32(ctx->r29, 0X38);
    // 0x800FDD30: jal         0x800193E8
    // 0x800FDD34: addiu       $a0, $a0, 0x2C
    ctx->r4 = ADD32(ctx->r4, 0X2C);
    func_800193E8(rdram, ctx);
        goto after_11;
    // 0x800FDD34: addiu       $a0, $a0, 0x2C
    ctx->r4 = ADD32(ctx->r4, 0X2C);
    after_11:
    // 0x800FDD38: lwc1        $f0, 0x38($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X38);
    // 0x800FDD3C: mul.s       $f0, $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f20.fl);
    // 0x800FDD40: lwc1        $f2, 0x40($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X40);
    // 0x800FDD44: div.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f2.fl);
    // 0x800FDD48: mul.s       $f0, $f0, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f22.fl);
    // 0x800FDD4C: swc1        $f0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f0.u32l;
    // 0x800FDD50: lwc1        $f0, 0x3C($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x800FDD54: mul.s       $f0, $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f20.fl);
    // 0x800FDD58: lwc1        $f2, 0x40($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X40);
    // 0x800FDD5C: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x800FDD60: div.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f2.fl);
    // 0x800FDD64: swc1        $f0, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f0.u32l;
    // 0x800FDD68: lwc1        $f0, 0x40($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X40);
    // 0x800FDD6C: sltiu       $v0, $s1, 0x2
    ctx->r2 = ctx->r17 < 0X2 ? 1 : 0;
    // 0x800FDD70: swc1        $f0, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f0.u32l;
    // 0x800FDD74: bne         $v0, $zero, L_800FDD24
    if (ctx->r2 != 0) {
        // 0x800FDD78: addiu       $s0, $s0, 0xC
        ctx->r16 = ADD32(ctx->r16, 0XC);
            goto L_800FDD24;
    }
    // 0x800FDD78: addiu       $s0, $s0, 0xC
    ctx->r16 = ADD32(ctx->r16, 0XC);
    // 0x800FDD7C: lw          $v0, 0x0($s4)
    ctx->r2 = MEM_W(ctx->r20, 0X0);
    // 0x800FDD80: lw          $v0, 0x10($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X10);
    // 0x800FDD84: lwc1        $f2, 0x10($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X10);
    // 0x800FDD88: srl         $v1, $v0, 31
    ctx->r3 = S32(U32(ctx->r2) >> 31);
    // 0x800FDD8C: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800FDD90: sra         $v0, $v0, 1
    ctx->r2 = S32(SIGNED(ctx->r2) >> 1);
    // 0x800FDD94: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x800FDD98: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x800FDD9C: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x800FDDA0: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800FDDA4: lwc1        $f4, -0x6CF8($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X6CF8);
    // 0x800FDDA8: mul.s       $f2, $f24, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = MUL_S(ctx->f24.fl, ctx->f4.fl);
    // 0x800FDDAC: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x800FDDB0: swc1        $f0, 0x1C0($s2)
    MEM_W(0X1C0, ctx->r18) = ctx->f0.u32l;
    // 0x800FDDB4: lw          $v0, 0x0($s4)
    ctx->r2 = MEM_W(ctx->r20, 0X0);
    // 0x800FDDB8: mul.s       $f4, $f26, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f4.fl = MUL_S(ctx->f26.fl, ctx->f4.fl);
    // 0x800FDDBC: lw          $v0, 0x14($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X14);
    // 0x800FDDC0: lwc1        $f2, 0x14($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X14);
    // 0x800FDDC4: srl         $v1, $v0, 31
    ctx->r3 = S32(U32(ctx->r2) >> 31);
    // 0x800FDDC8: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800FDDCC: sra         $v0, $v0, 1
    ctx->r2 = S32(SIGNED(ctx->r2) >> 1);
    // 0x800FDDD0: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x800FDDD4: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x800FDDD8: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x800FDDDC: sub.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f4.fl;
    // 0x800FDDE0: swc1        $f0, 0x1C4($s2)
    MEM_W(0X1C4, ctx->r18) = ctx->f0.u32l;
    // 0x800FDDE4: lw          $v0, 0x0($s4)
    ctx->r2 = MEM_W(ctx->r20, 0X0);
    // 0x800FDDE8: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800FDDEC: lwc1        $f2, -0x6CF4($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X6CF4);
    // 0x800FDDF0: lwc1        $f0, 0x10($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X10);
    // 0x800FDDF4: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x800FDDF8: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x800FDDFC: swc1        $f0, 0x1CC($s2)
    MEM_W(0X1CC, ctx->r18) = ctx->f0.u32l;
    // 0x800FDE00: lw          $v0, 0x0($s4)
    ctx->r2 = MEM_W(ctx->r20, 0X0);
    // 0x800FDE04: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800FDE08: lwc1        $f0, -0x6CF0($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X6CF0);
    // 0x800FDE0C: lwc1        $f2, 0x14($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X14);
    // 0x800FDE10: cvt.s.w     $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    ctx->f2.fl = CVT_S_W(ctx->f2.u32l);
    // 0x800FDE14: mul.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x800FDE18: lbu         $v0, 0x8($s2)
    ctx->r2 = MEM_BU(ctx->r18, 0X8);
    // 0x800FDE1C: lwc1        $f4, 0x24($s2)
    ctx->f4.u32l = MEM_W(ctx->r18, 0X24);
    // 0x800FDE20: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x800FDE24: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x800FDE28: mul.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x800FDE2C: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800FDE30: lwc1        $f4, -0x6CEC($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X6CEC);
    // 0x800FDE34: c.le.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl <= ctx->f0.fl;
    // 0x800FDE38: nop

    // 0x800FDE3C: bc1t        L_800FDE54
    if (c1cs) {
        // 0x800FDE40: swc1        $f2, 0x1D0($s2)
        MEM_W(0X1D0, ctx->r18) = ctx->f2.u32l;
            goto L_800FDE54;
    }
    // 0x800FDE40: swc1        $f2, 0x1D0($s2)
    MEM_W(0X1D0, ctx->r18) = ctx->f2.u32l;
    // 0x800FDE44: trunc.w.s   $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    ctx->f14.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800FDE48: mfc1        $v1, $f14
    ctx->r3 = (int32_t)ctx->f14.u32l;
    // 0x800FDE4C: j           L_800FDE6C
    // 0x800FDE50: sb          $v1, 0x1D7($s2)
    MEM_B(0X1D7, ctx->r18) = ctx->r3;
        goto L_800FDE6C;
    // 0x800FDE50: sb          $v1, 0x1D7($s2)
    MEM_B(0X1D7, ctx->r18) = ctx->r3;
L_800FDE54:
    // 0x800FDE54: sub.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f4.fl;
    // 0x800FDE58: lui         $v0, 0x8000
    ctx->r2 = S32(0X8000 << 16);
    // 0x800FDE5C: trunc.w.s   $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    ctx->f14.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800FDE60: mfc1        $v1, $f14
    ctx->r3 = (int32_t)ctx->f14.u32l;
    // 0x800FDE64: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x800FDE68: sb          $v1, 0x1D7($s2)
    MEM_B(0X1D7, ctx->r18) = ctx->r3;
L_800FDE6C:
    // 0x800FDE6C: lw          $v0, 0x0($s4)
    ctx->r2 = MEM_W(ctx->r20, 0X0);
    // 0x800FDE70: lw          $v0, 0x8($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X8);
    // 0x800FDE74: beq         $v0, $zero, L_800FDE8C
    if (ctx->r2 == 0) {
        // 0x800FDE78: sw          $v0, 0x1A8($s2)
        MEM_W(0X1A8, ctx->r18) = ctx->r2;
            goto L_800FDE8C;
    }
    // 0x800FDE78: sw          $v0, 0x1A8($s2)
    MEM_W(0X1A8, ctx->r18) = ctx->r2;
    // 0x800FDE7C: lw          $v0, 0x0($s4)
    ctx->r2 = MEM_W(ctx->r20, 0X0);
    // 0x800FDE80: lw          $v1, 0x8($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X8);
    // 0x800FDE84: addiu       $v0, $s2, 0x1A8
    ctx->r2 = ADD32(ctx->r18, 0X1A8);
    // 0x800FDE88: sw          $v0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r2;
L_800FDE8C:
    // 0x800FDE8C: sw          $zero, 0x1AC($s2)
    MEM_W(0X1AC, ctx->r18) = 0;
    // 0x800FDE90: lw          $v1, 0x0($s4)
    ctx->r3 = MEM_W(ctx->r20, 0X0);
    // 0x800FDE94: addiu       $v0, $s2, 0x1A8
    ctx->r2 = ADD32(ctx->r18, 0X1A8);
    // 0x800FDE98: sw          $v0, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r2;
    // 0x800FDE9C: lw          $v0, 0x0($s4)
    ctx->r2 = MEM_W(ctx->r20, 0X0);
    // 0x800FDEA0: lw          $v0, 0x10($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X10);
    // 0x800FDEA4: lwc1        $f2, 0x1C($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x800FDEA8: srl         $v1, $v0, 31
    ctx->r3 = S32(U32(ctx->r2) >> 31);
    // 0x800FDEAC: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800FDEB0: sra         $v0, $v0, 1
    ctx->r2 = S32(SIGNED(ctx->r2) >> 1);
    // 0x800FDEB4: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x800FDEB8: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x800FDEBC: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x800FDEC0: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800FDEC4: lwc1        $f4, -0x6CE8($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X6CE8);
    // 0x800FDEC8: mul.s       $f2, $f24, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = MUL_S(ctx->f24.fl, ctx->f4.fl);
    // 0x800FDECC: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x800FDED0: swc1        $f0, 0x1F0($s2)
    MEM_W(0X1F0, ctx->r18) = ctx->f0.u32l;
    // 0x800FDED4: lw          $v0, 0x0($s4)
    ctx->r2 = MEM_W(ctx->r20, 0X0);
    // 0x800FDED8: mul.s       $f4, $f26, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f4.fl = MUL_S(ctx->f26.fl, ctx->f4.fl);
    // 0x800FDEDC: lw          $v0, 0x14($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X14);
    // 0x800FDEE0: lwc1        $f2, 0x20($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X20);
    // 0x800FDEE4: srl         $v1, $v0, 31
    ctx->r3 = S32(U32(ctx->r2) >> 31);
    // 0x800FDEE8: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800FDEEC: sra         $v0, $v0, 1
    ctx->r2 = S32(SIGNED(ctx->r2) >> 1);
    // 0x800FDEF0: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x800FDEF4: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x800FDEF8: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x800FDEFC: sub.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f4.fl;
    // 0x800FDF00: swc1        $f0, 0x1F4($s2)
    MEM_W(0X1F4, ctx->r18) = ctx->f0.u32l;
    // 0x800FDF04: lw          $v0, 0x0($s4)
    ctx->r2 = MEM_W(ctx->r20, 0X0);
    // 0x800FDF08: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800FDF0C: lwc1        $f2, -0x6CE4($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X6CE4);
    // 0x800FDF10: lwc1        $f0, 0x10($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X10);
    // 0x800FDF14: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x800FDF18: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x800FDF1C: swc1        $f0, 0x1FC($s2)
    MEM_W(0X1FC, ctx->r18) = ctx->f0.u32l;
    // 0x800FDF20: lw          $v0, 0x0($s4)
    ctx->r2 = MEM_W(ctx->r20, 0X0);
    // 0x800FDF24: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800FDF28: lwc1        $f2, -0x6CE0($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X6CE0);
    // 0x800FDF2C: lwc1        $f0, 0x14($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X14);
    // 0x800FDF30: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x800FDF34: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x800FDF38: lbu         $v0, 0x1D7($s2)
    ctx->r2 = MEM_BU(ctx->r18, 0X1D7);
    // 0x800FDF3C: sb          $v0, 0x207($s2)
    MEM_B(0X207, ctx->r18) = ctx->r2;
    // 0x800FDF40: swc1        $f0, 0x200($s2)
    MEM_W(0X200, ctx->r18) = ctx->f0.u32l;
    // 0x800FDF44: lw          $v0, 0x0($s4)
    ctx->r2 = MEM_W(ctx->r20, 0X0);
    // 0x800FDF48: lw          $v0, 0x8($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X8);
    // 0x800FDF4C: beq         $v0, $zero, L_800FDF64
    if (ctx->r2 == 0) {
        // 0x800FDF50: sw          $v0, 0x1D8($s2)
        MEM_W(0X1D8, ctx->r18) = ctx->r2;
            goto L_800FDF64;
    }
    // 0x800FDF50: sw          $v0, 0x1D8($s2)
    MEM_W(0X1D8, ctx->r18) = ctx->r2;
    // 0x800FDF54: lw          $v0, 0x0($s4)
    ctx->r2 = MEM_W(ctx->r20, 0X0);
    // 0x800FDF58: lw          $v1, 0x8($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X8);
    // 0x800FDF5C: addiu       $v0, $s2, 0x1D8
    ctx->r2 = ADD32(ctx->r18, 0X1D8);
    // 0x800FDF60: sw          $v0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r2;
L_800FDF64:
    // 0x800FDF64: sw          $zero, 0x1DC($s2)
    MEM_W(0X1DC, ctx->r18) = 0;
    // 0x800FDF68: lw          $v0, 0x0($s4)
    ctx->r2 = MEM_W(ctx->r20, 0X0);
    // 0x800FDF6C: addiu       $v1, $s2, 0x1D8
    ctx->r3 = ADD32(ctx->r18, 0X1D8);
    // 0x800FDF70: sw          $v1, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r3;
    // 0x800FDF74: lbu         $v0, 0x210($s2)
    ctx->r2 = MEM_BU(ctx->r18, 0X210);
    // 0x800FDF78: beq         $v0, $zero, L_800FE400
    if (ctx->r2 == 0) {
        // 0x800FDF7C: nop
    
            goto L_800FE400;
    }
    // 0x800FDF7C: nop

    // 0x800FDF80: lhu         $a0, 0x212($s2)
    ctx->r4 = MEM_HU(ctx->r18, 0X212);
    // 0x800FDF84: jal         0x80040218
    // 0x800FDF88: nop

    func_80040218(rdram, ctx);
        goto after_12;
    // 0x800FDF88: nop

    after_12:
    // 0x800FDF8C: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x800FDF90: ori         $v1, $zero, 0xFFFF
    ctx->r3 = 0 | 0XFFFF;
    // 0x800FDF94: beq         $v0, $v1, L_800FE400
    if (ctx->r2 == ctx->r3) {
        // 0x800FDF98: nop
    
            goto L_800FE400;
    }
    // 0x800FDF98: nop

    // 0x800FDF9C: lw          $t2, 0x21C($s2)
    ctx->r10 = MEM_W(ctx->r18, 0X21C);
    // 0x800FDFA0: lw          $t3, 0x220($s2)
    ctx->r11 = MEM_W(ctx->r18, 0X220);
    // 0x800FDFA4: lw          $t4, 0x224($s2)
    ctx->r12 = MEM_W(ctx->r18, 0X224);
    // 0x800FDFA8: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x800FDFAC: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    // 0x800FDFB0: sw          $t4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r12;
    // 0x800FDFB4: lw          $v0, 0x0($s4)
    ctx->r2 = MEM_W(ctx->r20, 0X0);
    // 0x800FDFB8: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800FDFBC: lwc1        $f0, -0x6CDC($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X6CDC);
    // 0x800FDFC0: lwc1        $f2, 0x20($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X20);
    // 0x800FDFC4: mul.s       $f20, $f2, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f20.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x800FDFC8: jal         0x8002B190
    // 0x800FDFCC: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    cosf_recomp(rdram, ctx);
        goto after_13;
    // 0x800FDFCC: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    after_13:
    // 0x800FDFD0: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    // 0x800FDFD4: jal         0x80033960
    // 0x800FDFD8: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    sinf_recomp(rdram, ctx);
        goto after_14;
    // 0x800FDFD8: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    after_14:
    // 0x800FDFDC: div.s       $f20, $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f20.fl = DIV_S(ctx->f20.fl, ctx->f0.fl);
    // 0x800FDFE0: addiu       $a1, $sp, 0x10
    ctx->r5 = ADD32(ctx->r29, 0X10);
    // 0x800FDFE4: lw          $a0, 0x0($s4)
    ctx->r4 = MEM_W(ctx->r20, 0X0);
    // 0x800FDFE8: addiu       $a2, $sp, 0x38
    ctx->r6 = ADD32(ctx->r29, 0X38);
    // 0x800FDFEC: jal         0x800193E8
    // 0x800FDFF0: addiu       $a0, $a0, 0x2C
    ctx->r4 = ADD32(ctx->r4, 0X2C);
    func_800193E8(rdram, ctx);
        goto after_15;
    // 0x800FDFF0: addiu       $a0, $a0, 0x2C
    ctx->r4 = ADD32(ctx->r4, 0X2C);
    after_15:
    // 0x800FDFF4: lwc1        $f6, 0x40($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X40);
    // 0x800FDFF8: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800FDFFC: lwc1        $f0, -0x6CD8($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X6CD8);
    // 0x800FE000: c.lt.s      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.fl < ctx->f0.fl;
    // 0x800FE004: nop

    // 0x800FE008: bc1t        L_800FE070
    if (c1cs) {
        // 0x800FE00C: nop
    
            goto L_800FE070;
    }
    // 0x800FE00C: nop

    // 0x800FE010: lwc1        $f0, 0x38($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X38);
    // 0x800FE014: mul.s       $f0, $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f20.fl);
    // 0x800FE018: lwc1        $f2, 0x3C($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x800FE01C: mul.s       $f2, $f2, $f20
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f20.fl);
    // 0x800FE020: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800FE024: lwc1        $f4, -0x6CD4($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X6CD4);
    // 0x800FE028: div.s       $f0, $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f6.fl);
    // 0x800FE02C: mul.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x800FE030: swc1        $f6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f6.u32l;
    // 0x800FE034: div.s       $f2, $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = DIV_S(ctx->f2.fl, ctx->f6.fl);
    // 0x800FE038: swc1        $f2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f2.u32l;
    // 0x800FE03C: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    // 0x800FE040: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x800FE044: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800FE048: lwc1        $f4, -0x6CD0($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X6CD0);
    // 0x800FE04C: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x800FE050: nop

    // 0x800FE054: bc1t        L_800FE070
    if (c1cs) {
        // 0x800FE058: nop
    
            goto L_800FE070;
    }
    // 0x800FE058: nop

    // 0x800FE05C: abs.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = fabsf(ctx->f2.fl);
    // 0x800FE060: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x800FE064: nop

    // 0x800FE068: bc1f        L_800FE08C
    if (!c1cs) {
        // 0x800FE06C: nop
    
            goto L_800FE08C;
    }
    // 0x800FE06C: nop

L_800FE070:
    // 0x800FE070: lhu         $a0, 0x212($s2)
    ctx->r4 = MEM_HU(ctx->r18, 0X212);
    // 0x800FE074: jal         0x8003F0C8
    // 0x800FE078: nop

    func_8003F0C8(rdram, ctx);
        goto after_16;
    // 0x800FE078: nop

    after_16:
    // 0x800FE07C: ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
    // 0x800FE080: sb          $zero, 0x210($s2)
    MEM_B(0X210, ctx->r18) = 0;
    // 0x800FE084: j           L_800FE400
    // 0x800FE088: sh          $v0, 0x208($s2)
    MEM_H(0X208, ctx->r18) = ctx->r2;
        goto L_800FE400;
    // 0x800FE088: sh          $v0, 0x208($s2)
    MEM_H(0X208, ctx->r18) = ctx->r2;
L_800FE08C:
    // 0x800FE08C: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800FE090: lwc1        $f0, -0x6CCC($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X6CCC);
    // 0x800FE094: mul.s       $f0, $f20, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = MUL_S(ctx->f20.fl, ctx->f0.fl);
    // 0x800FE098: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800FE09C: lwc1        $f2, -0x6CC8($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X6CC8);
    // 0x800FE0A0: div.s       $f6, $f0, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f6.fl = DIV_S(ctx->f0.fl, ctx->f6.fl);
    // 0x800FE0A4: c.lt.s      $f6, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f6.fl < ctx->f2.fl;
    // 0x800FE0A8: nop

    // 0x800FE0AC: bc1t        L_800FE0D4
    if (c1cs) {
        // 0x800FE0B0: mov.s       $f0, $f2
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
            goto L_800FE0D4;
    }
    // 0x800FE0B0: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    // 0x800FE0B4: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800FE0B8: lwc1        $f2, -0x6CC4($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X6CC4);
    // 0x800FE0BC: mov.s       $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    ctx->f0.fl = ctx->f6.fl;
    // 0x800FE0C0: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x800FE0C4: nop

    // 0x800FE0C8: bc1f        L_800FE0D8
    if (!c1cs) {
        // 0x800FE0CC: mov.s       $f6, $f0
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    ctx->f6.fl = ctx->f0.fl;
            goto L_800FE0D8;
    }
    // 0x800FE0CC: mov.s       $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    ctx->f6.fl = ctx->f0.fl;
    // 0x800FE0D0: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
L_800FE0D4:
    // 0x800FE0D4: mov.s       $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    ctx->f6.fl = ctx->f0.fl;
L_800FE0D8:
    // 0x800FE0D8: addu        $s1, $zero, $zero
    ctx->r17 = ADD32(0, 0);
    // 0x800FE0DC: addiu       $a3, $zero, 0xB8
    ctx->r7 = ADD32(0, 0XB8);
    // 0x800FE0E0: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800FE0E4: addiu       $a2, $v0, -0x4C10
    ctx->r6 = ADD32(ctx->r2, -0X4C10);
    // 0x800FE0E8: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800FE0EC: addiu       $a1, $v0, -0x4C04
    ctx->r5 = ADD32(ctx->r2, -0X4C04);
    // 0x800FE0F0: addiu       $t0, $zero, 0x90
    ctx->r8 = ADD32(0, 0X90);
    // 0x800FE0F4: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800FE0F8: lwc1        $f12, -0x6CC0($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X6CC0);
    // 0x800FE0FC: lw          $v0, 0x0($s4)
    ctx->r2 = MEM_W(ctx->r20, 0X0);
    // 0x800FE100: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800FE104: lwc1        $f10, -0x6CBC($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X6CBC);
    // 0x800FE108: lwc1        $f2, 0x14($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X14);
    // 0x800FE10C: cvt.s.w     $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    ctx->f2.fl = CVT_S_W(ctx->f2.u32l);
    // 0x800FE110: mul.s       $f2, $f6, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = MUL_S(ctx->f6.fl, ctx->f2.fl);
    // 0x800FE114: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800FE118: lwc1        $f4, -0x6CB8($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X6CB8);
    // 0x800FE11C: lwc1        $f0, 0x10($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X10);
    // 0x800FE120: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x800FE124: div.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f4.fl);
    // 0x800FE128: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800FE12C: lwc1        $f4, -0x6CB4($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X6CB4);
    // 0x800FE130: mul.s       $f6, $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x800FE134: div.s       $f8, $f2, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = DIV_S(ctx->f2.fl, ctx->f4.fl);
L_800FE138:
    // 0x800FE138: lw          $v0, 0x0($s4)
    ctx->r2 = MEM_W(ctx->r20, 0X0);
    // 0x800FE13C: lwc1        $f0, 0x10($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X10);
    // 0x800FE140: lwc1        $f4, 0x0($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X0);
    // 0x800FE144: lw          $v0, 0x10($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X10);
    // 0x800FE148: mul.s       $f4, $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x800FE14C: srl         $v1, $v0, 31
    ctx->r3 = S32(U32(ctx->r2) >> 31);
    // 0x800FE150: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800FE154: sra         $v0, $v0, 1
    ctx->r2 = S32(SIGNED(ctx->r2) >> 1);
    // 0x800FE158: mtc1        $v0, $f2
    ctx->f2.u32l = ctx->r2;
    // 0x800FE15C: cvt.s.w     $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    ctx->f2.fl = CVT_S_W(ctx->f2.u32l);
    // 0x800FE160: mul.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x800FE164: lbu         $v0, 0x0($a2)
    ctx->r2 = MEM_BU(ctx->r6, 0X0);
    // 0x800FE168: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x800FE16C: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x800FE170: mul.s       $f0, $f0, $f24
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f24.fl);
    // 0x800FE174: add.s       $f2, $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f4.fl;
    // 0x800FE178: sub.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl - ctx->f0.fl;
    // 0x800FE17C: addu        $a0, $s2, $t0
    ctx->r4 = ADD32(ctx->r18, ctx->r8);
    // 0x800FE180: swc1        $f2, 0x40($a0)
    MEM_W(0X40, ctx->r4) = ctx->f2.u32l;
    // 0x800FE184: lw          $v0, 0x0($s4)
    ctx->r2 = MEM_W(ctx->r20, 0X0);
    // 0x800FE188: lwc1        $f0, 0x14($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X14);
    // 0x800FE18C: lwc1        $f4, 0x4($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X4);
    // 0x800FE190: lw          $v0, 0x14($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X14);
    // 0x800FE194: mul.s       $f4, $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = MUL_S(ctx->f4.fl, ctx->f8.fl);
    // 0x800FE198: srl         $v1, $v0, 31
    ctx->r3 = S32(U32(ctx->r2) >> 31);
    // 0x800FE19C: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800FE1A0: sra         $v0, $v0, 1
    ctx->r2 = S32(SIGNED(ctx->r2) >> 1);
    // 0x800FE1A4: mtc1        $v0, $f2
    ctx->f2.u32l = ctx->r2;
    // 0x800FE1A8: cvt.s.w     $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    ctx->f2.fl = CVT_S_W(ctx->f2.u32l);
    // 0x800FE1AC: mul.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x800FE1B0: lbu         $v0, 0x1($a2)
    ctx->r2 = MEM_BU(ctx->r6, 0X1);
    // 0x800FE1B4: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x800FE1B8: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x800FE1BC: mul.s       $f0, $f0, $f26
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f26.fl);
    // 0x800FE1C0: add.s       $f2, $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f4.fl;
    // 0x800FE1C4: sub.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl - ctx->f0.fl;
    // 0x800FE1C8: swc1        $f2, 0x44($a0)
    MEM_W(0X44, ctx->r4) = ctx->f2.u32l;
    // 0x800FE1CC: lw          $v0, 0x0($s4)
    ctx->r2 = MEM_W(ctx->r20, 0X0);
    // 0x800FE1D0: lwc1        $f0, 0x10($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X10);
    // 0x800FE1D4: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x800FE1D8: mul.s       $f0, $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f12.fl);
    // 0x800FE1DC: swc1        $f0, 0x4C($a0)
    MEM_W(0X4C, ctx->r4) = ctx->f0.u32l;
    // 0x800FE1E0: lw          $v0, 0x0($s4)
    ctx->r2 = MEM_W(ctx->r20, 0X0);
    // 0x800FE1E4: lwc1        $f0, 0x14($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X14);
    // 0x800FE1E8: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x800FE1EC: mul.s       $f0, $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x800FE1F0: swc1        $f0, 0x50($a0)
    MEM_W(0X50, ctx->r4) = ctx->f0.u32l;
    // 0x800FE1F4: lw          $v0, 0x0($s4)
    ctx->r2 = MEM_W(ctx->r20, 0X0);
    // 0x800FE1F8: lw          $v0, 0x8($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X8);
    // 0x800FE1FC: beq         $v0, $zero, L_800FE214
    if (ctx->r2 == 0) {
        // 0x800FE200: sw          $v0, 0x28($a0)
        MEM_W(0X28, ctx->r4) = ctx->r2;
            goto L_800FE214;
    }
    // 0x800FE200: sw          $v0, 0x28($a0)
    MEM_W(0X28, ctx->r4) = ctx->r2;
    // 0x800FE204: lw          $v0, 0x0($s4)
    ctx->r2 = MEM_W(ctx->r20, 0X0);
    // 0x800FE208: lw          $v1, 0x8($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X8);
    // 0x800FE20C: addu        $v0, $s2, $a3
    ctx->r2 = ADD32(ctx->r18, ctx->r7);
    // 0x800FE210: sw          $v0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r2;
L_800FE214:
    // 0x800FE214: addu        $v1, $s2, $a3
    ctx->r3 = ADD32(ctx->r18, ctx->r7);
    // 0x800FE218: addiu       $a3, $a3, 0x30
    ctx->r7 = ADD32(ctx->r7, 0X30);
    // 0x800FE21C: addiu       $a2, $a2, 0x2
    ctx->r6 = ADD32(ctx->r6, 0X2);
    // 0x800FE220: addiu       $a1, $a1, 0x8
    ctx->r5 = ADD32(ctx->r5, 0X8);
    // 0x800FE224: sw          $zero, 0x2C($a0)
    MEM_W(0X2C, ctx->r4) = 0;
    // 0x800FE228: lw          $v0, 0x0($s4)
    ctx->r2 = MEM_W(ctx->r20, 0X0);
    // 0x800FE22C: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x800FE230: sw          $v1, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r3;
    // 0x800FE234: sltiu       $v0, $s1, 0x5
    ctx->r2 = ctx->r17 < 0X5 ? 1 : 0;
    // 0x800FE238: bne         $v0, $zero, L_800FE138
    if (ctx->r2 != 0) {
        // 0x800FE23C: addiu       $t0, $t0, 0x30
        ctx->r8 = ADD32(ctx->r8, 0X30);
            goto L_800FE138;
    }
    // 0x800FE23C: addiu       $t0, $t0, 0x30
    ctx->r8 = ADD32(ctx->r8, 0X30);
    // 0x800FE240: j           L_800FE400
    // 0x800FE244: nop

        goto L_800FE400;
    // 0x800FE244: nop

L_800FE248:
    // 0x800FE248: lbu         $v0, 0x1($s2)
    ctx->r2 = MEM_BU(ctx->r18, 0X1);
    // 0x800FE24C: beq         $v0, $zero, L_800FE400
    if (ctx->r2 == 0) {
        // 0x800FE250: nop
    
            goto L_800FE400;
    }
    // 0x800FE250: nop

    // 0x800FE254: lbu         $v0, 0x228($s2)
    ctx->r2 = MEM_BU(ctx->r18, 0X228);
    // 0x800FE258: beq         $v0, $zero, L_800FE400
    if (ctx->r2 == 0) {
        // 0x800FE25C: nop
    
            goto L_800FE400;
    }
    // 0x800FE25C: nop

    // 0x800FE260: lw          $v0, 0x0($s4)
    ctx->r2 = MEM_W(ctx->r20, 0X0);
    // 0x800FE264: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800FE268: lwc1        $f0, -0x6CB0($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X6CB0);
    // 0x800FE26C: lwc1        $f2, 0x20($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X20);
    // 0x800FE270: mul.s       $f20, $f2, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f20.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x800FE274: jal         0x8002B190
    // 0x800FE278: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    cosf_recomp(rdram, ctx);
        goto after_17;
    // 0x800FE278: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    after_17:
    // 0x800FE27C: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    // 0x800FE280: jal         0x80033960
    // 0x800FE284: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    sinf_recomp(rdram, ctx);
        goto after_18;
    // 0x800FE284: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    after_18:
    // 0x800FE288: div.s       $f20, $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f20.fl = DIV_S(ctx->f20.fl, ctx->f0.fl);
    // 0x800FE28C: addiu       $a1, $s2, 0x21C
    ctx->r5 = ADD32(ctx->r18, 0X21C);
    // 0x800FE290: lw          $a0, 0x0($s4)
    ctx->r4 = MEM_W(ctx->r20, 0X0);
    // 0x800FE294: addiu       $a2, $sp, 0x10
    ctx->r6 = ADD32(ctx->r29, 0X10);
    // 0x800FE298: jal         0x800193E8
    // 0x800FE29C: addiu       $a0, $a0, 0x2C
    ctx->r4 = ADD32(ctx->r4, 0X2C);
    func_800193E8(rdram, ctx);
        goto after_19;
    // 0x800FE29C: addiu       $a0, $a0, 0x2C
    ctx->r4 = ADD32(ctx->r4, 0X2C);
    after_19:
    // 0x800FE2A0: lw          $v0, 0x0($s4)
    ctx->r2 = MEM_W(ctx->r20, 0X0);
    // 0x800FE2A4: lwc1        $f6, 0x18($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X18);
    // 0x800FE2A8: lwc1        $f0, 0x24($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X24);
    // 0x800FE2AC: c.lt.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl < ctx->f6.fl;
    // 0x800FE2B0: nop

    // 0x800FE2B4: bc1f        L_800FE400
    if (!c1cs) {
        // 0x800FE2B8: nop
    
            goto L_800FE400;
    }
    // 0x800FE2B8: nop

    // 0x800FE2BC: lwc1        $f0, 0x28($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X28);
    // 0x800FE2C0: c.lt.s      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.fl < ctx->f0.fl;
    // 0x800FE2C4: nop

    // 0x800FE2C8: bc1f        L_800FE400
    if (!c1cs) {
        // 0x800FE2CC: nop
    
            goto L_800FE400;
    }
    // 0x800FE2CC: nop

    // 0x800FE2D0: lwc1        $f0, 0x10($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X10);
    // 0x800FE2D4: mul.s       $f0, $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f20.fl);
    // 0x800FE2D8: lwc1        $f2, 0x14($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X14);
    // 0x800FE2DC: mul.s       $f2, $f2, $f20
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f20.fl);
    // 0x800FE2E0: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800FE2E4: lwc1        $f4, -0x6CAC($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X6CAC);
    // 0x800FE2E8: div.s       $f0, $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f6.fl);
    // 0x800FE2EC: mul.s       $f4, $f0, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x800FE2F0: div.s       $f2, $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = DIV_S(ctx->f2.fl, ctx->f6.fl);
    // 0x800FE2F4: swc1        $f2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f2.u32l;
    // 0x800FE2F8: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x800FE2FC: abs.s       $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = fabsf(ctx->f4.fl);
    // 0x800FE300: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800FE304: lwc1        $f6, -0x6CA8($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X6CA8);
    // 0x800FE308: c.lt.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl < ctx->f6.fl;
    // 0x800FE30C: nop

    // 0x800FE310: bc1f        L_800FE400
    if (!c1cs) {
        // 0x800FE314: nop
    
            goto L_800FE400;
    }
    // 0x800FE314: nop

    // 0x800FE318: abs.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = fabsf(ctx->f2.fl);
    // 0x800FE31C: c.lt.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl < ctx->f6.fl;
    // 0x800FE320: nop

    // 0x800FE324: bc1f        L_800FE400
    if (!c1cs) {
        // 0x800FE328: nop
    
            goto L_800FE400;
    }
    // 0x800FE328: nop

    // 0x800FE32C: lw          $v0, 0x0($s4)
    ctx->r2 = MEM_W(ctx->r20, 0X0);
    // 0x800FE330: lw          $v0, 0x10($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X10);
    // 0x800FE334: srl         $v1, $v0, 31
    ctx->r3 = S32(U32(ctx->r2) >> 31);
    // 0x800FE338: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800FE33C: sra         $v0, $v0, 1
    ctx->r2 = S32(SIGNED(ctx->r2) >> 1);
    // 0x800FE340: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x800FE344: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x800FE348: mul.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x800FE34C: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800FE350: lwc1        $f4, -0x6CA4($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X6CA4);
    // 0x800FE354: mul.s       $f2, $f24, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = MUL_S(ctx->f24.fl, ctx->f4.fl);
    // 0x800FE358: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x800FE35C: swc1        $f0, 0xA0($s2)
    MEM_W(0XA0, ctx->r18) = ctx->f0.u32l;
    // 0x800FE360: lw          $v0, 0x0($s4)
    ctx->r2 = MEM_W(ctx->r20, 0X0);
    // 0x800FE364: mul.s       $f4, $f26, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f4.fl = MUL_S(ctx->f26.fl, ctx->f4.fl);
    // 0x800FE368: lw          $v0, 0x14($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X14);
    // 0x800FE36C: lwc1        $f2, 0x14($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X14);
    // 0x800FE370: srl         $v1, $v0, 31
    ctx->r3 = S32(U32(ctx->r2) >> 31);
    // 0x800FE374: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800FE378: sra         $v0, $v0, 1
    ctx->r2 = S32(SIGNED(ctx->r2) >> 1);
    // 0x800FE37C: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x800FE380: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x800FE384: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x800FE388: sub.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f4.fl;
    // 0x800FE38C: swc1        $f0, 0xA4($s2)
    MEM_W(0XA4, ctx->r18) = ctx->f0.u32l;
    // 0x800FE390: lw          $v0, 0x0($s4)
    ctx->r2 = MEM_W(ctx->r20, 0X0);
    // 0x800FE394: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800FE398: lwc1        $f2, -0x6CA0($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X6CA0);
    // 0x800FE39C: lwc1        $f0, 0x10($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X10);
    // 0x800FE3A0: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x800FE3A4: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x800FE3A8: swc1        $f0, 0xAC($s2)
    MEM_W(0XAC, ctx->r18) = ctx->f0.u32l;
    // 0x800FE3AC: lw          $v0, 0x0($s4)
    ctx->r2 = MEM_W(ctx->r20, 0X0);
    // 0x800FE3B0: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800FE3B4: lwc1        $f2, -0x6C9C($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X6C9C);
    // 0x800FE3B8: lwc1        $f0, 0x14($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X14);
    // 0x800FE3BC: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x800FE3C0: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x800FE3C4: lbu         $v0, 0x8($s2)
    ctx->r2 = MEM_BU(ctx->r18, 0X8);
    // 0x800FE3C8: sb          $v0, 0xB7($s2)
    MEM_B(0XB7, ctx->r18) = ctx->r2;
    // 0x800FE3CC: swc1        $f0, 0xB0($s2)
    MEM_W(0XB0, ctx->r18) = ctx->f0.u32l;
    // 0x800FE3D0: lw          $v0, 0x0($s4)
    ctx->r2 = MEM_W(ctx->r20, 0X0);
    // 0x800FE3D4: lw          $v0, 0x8($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X8);
    // 0x800FE3D8: beq         $v0, $zero, L_800FE3F0
    if (ctx->r2 == 0) {
        // 0x800FE3DC: sw          $v0, 0x88($s2)
        MEM_W(0X88, ctx->r18) = ctx->r2;
            goto L_800FE3F0;
    }
    // 0x800FE3DC: sw          $v0, 0x88($s2)
    MEM_W(0X88, ctx->r18) = ctx->r2;
    // 0x800FE3E0: lw          $v0, 0x0($s4)
    ctx->r2 = MEM_W(ctx->r20, 0X0);
    // 0x800FE3E4: lw          $v1, 0x8($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X8);
    // 0x800FE3E8: addiu       $v0, $s2, 0x88
    ctx->r2 = ADD32(ctx->r18, 0X88);
    // 0x800FE3EC: sw          $v0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r2;
L_800FE3F0:
    // 0x800FE3F0: sw          $zero, 0x8C($s2)
    MEM_W(0X8C, ctx->r18) = 0;
    // 0x800FE3F4: lw          $v1, 0x0($s4)
    ctx->r3 = MEM_W(ctx->r20, 0X0);
    // 0x800FE3F8: addiu       $v0, $s2, 0x88
    ctx->r2 = ADD32(ctx->r18, 0X88);
    // 0x800FE3FC: sw          $v0, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r2;
L_800FE400:
    // 0x800FE400: lw          $ra, 0x60($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X60);
    // 0x800FE404: lw          $s5, 0x5C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X5C);
    // 0x800FE408: lw          $s4, 0x58($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X58);
    // 0x800FE40C: lw          $s3, 0x54($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X54);
    // 0x800FE410: lw          $s2, 0x50($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X50);
    // 0x800FE414: lw          $s1, 0x4C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X4C);
    // 0x800FE418: lw          $s0, 0x48($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X48);
    // 0x800FE41C: ldc1        $f26, 0x80($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X80);
    // 0x800FE420: ldc1        $f24, 0x78($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X78);
    // 0x800FE424: ldc1        $f22, 0x70($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X70);
    // 0x800FE428: ldc1        $f20, 0x68($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X68);
    // 0x800FE42C: jr          $ra
    // 0x800FE430: addiu       $sp, $sp, 0x88
    ctx->r29 = ADD32(ctx->r29, 0X88);
    return;
    // 0x800FE430: addiu       $sp, $sp, 0x88
    ctx->r29 = ADD32(ctx->r29, 0X88);
;}
RECOMP_FUNC void func_800FE434(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800FE434: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800FE438: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x800FE43C: addu        $s1, $zero, $zero
    ctx->r17 = ADD32(0, 0);
    // 0x800FE440: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800FE444: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x800FE448: addiu       $s0, $v0, -0x35D0
    ctx->r16 = ADD32(ctx->r2, -0X35D0);
    // 0x800FE44C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800FE450: sw          $s4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r20;
    // 0x800FE454: sw          $s3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r19;
    // 0x800FE458: sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
L_800FE45C:
    // 0x800FE45C: lhu         $a0, 0xA($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0XA);
    // 0x800FE460: addiu       $s0, $s0, 0x2
    ctx->r16 = ADD32(ctx->r16, 0X2);
    // 0x800FE464: jal         0x80022790
    // 0x800FE468: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    func_80022790(rdram, ctx);
        goto after_0;
    // 0x800FE468: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    after_0:
    // 0x800FE46C: sltiu       $v0, $s1, 0xA
    ctx->r2 = ctx->r17 < 0XA ? 1 : 0;
    // 0x800FE470: bne         $v0, $zero, L_800FE45C
    if (ctx->r2 != 0) {
        // 0x800FE474: addiu       $s4, $zero, 0x3
        ctx->r20 = ADD32(0, 0X3);
            goto L_800FE45C;
    }
    // 0x800FE474: addiu       $s4, $zero, 0x3
    ctx->r20 = ADD32(0, 0X3);
    // 0x800FE478: addiu       $s3, $zero, 0x8
    ctx->r19 = ADD32(0, 0X8);
    // 0x800FE47C: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800FE480: addiu       $v0, $v0, -0x35D0
    ctx->r2 = ADD32(ctx->r2, -0X35D0);
    // 0x800FE484: addiu       $s1, $v0, 0x230
    ctx->r17 = ADD32(ctx->r2, 0X230);
    // 0x800FE488: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    // 0x800FE48C: addiu       $s2, $s0, 0x4F0
    ctx->r18 = ADD32(ctx->r16, 0X4F0);
L_800FE490:
    // 0x800FE490: lbu         $v0, 0x0($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X0);
    // 0x800FE494: beq         $v0, $s4, L_800FE4A4
    if (ctx->r2 == ctx->r20) {
        // 0x800FE498: nop
    
            goto L_800FE4A4;
    }
    // 0x800FE498: nop

    // 0x800FE49C: bne         $v0, $s3, L_800FE4BC
    if (ctx->r2 != ctx->r19) {
        // 0x800FE4A0: nop
    
            goto L_800FE4BC;
    }
    // 0x800FE4A0: nop

L_800FE4A4:
    // 0x800FE4A4: lbu         $v0, 0x210($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X210);
    // 0x800FE4A8: beq         $v0, $zero, L_800FE4BC
    if (ctx->r2 == 0) {
        // 0x800FE4AC: nop
    
            goto L_800FE4BC;
    }
    // 0x800FE4AC: nop

    // 0x800FE4B0: lhu         $a0, 0x212($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X212);
    // 0x800FE4B4: jal         0x8003F0C8
    // 0x800FE4B8: nop

    func_8003F0C8(rdram, ctx);
        goto after_1;
    // 0x800FE4B8: nop

    after_1:
L_800FE4BC:
    // 0x800FE4BC: lbu         $v0, 0x274($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X274);
    // 0x800FE4C0: beql        $v0, $zero, L_800FE4D4
    if (ctx->r2 == 0) {
        // 0x800FE4C4: addiu       $s0, $s0, 0x278
        ctx->r16 = ADD32(ctx->r16, 0X278);
            goto L_800FE4D4;
    }
    goto skip_0;
    // 0x800FE4C4: addiu       $s0, $s0, 0x278
    ctx->r16 = ADD32(ctx->r16, 0X278);
    skip_0:
    // 0x800FE4C8: jal         0x80098DE0
    // 0x800FE4CC: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    func_80098DE0(rdram, ctx);
        goto after_2;
    // 0x800FE4CC: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    after_2:
    // 0x800FE4D0: addiu       $s0, $s0, 0x278
    ctx->r16 = ADD32(ctx->r16, 0X278);
L_800FE4D4:
    // 0x800FE4D4: sltu        $v0, $s0, $s2
    ctx->r2 = ctx->r16 < ctx->r18 ? 1 : 0;
    // 0x800FE4D8: bne         $v0, $zero, L_800FE490
    if (ctx->r2 != 0) {
        // 0x800FE4DC: addiu       $s1, $s1, 0x278
        ctx->r17 = ADD32(ctx->r17, 0X278);
            goto L_800FE490;
    }
    // 0x800FE4DC: addiu       $s1, $s1, 0x278
    ctx->r17 = ADD32(ctx->r17, 0X278);
    // 0x800FE4E0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800FE4E4: lw          $s4, 0x20($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X20);
    // 0x800FE4E8: lw          $s3, 0x1C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X1C);
    // 0x800FE4EC: lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X18);
    // 0x800FE4F0: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x800FE4F4: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x800FE4F8: jr          $ra
    // 0x800FE4FC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x800FE4FC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_800FE500(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800FE500: addiu       $sp, $sp, -0x110
    ctx->r29 = ADD32(ctx->r29, -0X110);
    // 0x800FE504: sw          $s3, 0xF4($sp)
    MEM_W(0XF4, ctx->r29) = ctx->r19;
    // 0x800FE508: addu        $s3, $a2, $zero
    ctx->r19 = ADD32(ctx->r6, 0);
    // 0x800FE50C: sw          $s4, 0xF8($sp)
    MEM_W(0XF8, ctx->r29) = ctx->r20;
    // 0x800FE510: lw          $s4, 0x120($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X120);
    // 0x800FE514: lw          $a2, 0x124($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X124);
    // 0x800FE518: sw          $s5, 0xFC($sp)
    MEM_W(0XFC, ctx->r29) = ctx->r21;
    // 0x800FE51C: lhu         $s5, 0x12A($sp)
    ctx->r21 = MEM_HU(ctx->r29, 0X12A);
    // 0x800FE520: sw          $s2, 0xF0($sp)
    MEM_W(0XF0, ctx->r29) = ctx->r18;
    // 0x800FE524: addu        $s2, $a0, $zero
    ctx->r18 = ADD32(ctx->r4, 0);
    // 0x800FE528: sw          $s1, 0xEC($sp)
    MEM_W(0XEC, ctx->r29) = ctx->r17;
    // 0x800FE52C: sw          $ra, 0x100($sp)
    MEM_W(0X100, ctx->r29) = ctx->r31;
    // 0x800FE530: sw          $s0, 0xE8($sp)
    MEM_W(0XE8, ctx->r29) = ctx->r16;
    // 0x800FE534: sdc1        $f20, 0x108($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X108, ctx->r29);
    // 0x800FE538: addiu       $v1, $s4, -0x1
    ctx->r3 = ADD32(ctx->r20, -0X1);
    // 0x800FE53C: sltiu       $v0, $v1, 0x9
    ctx->r2 = ctx->r3 < 0X9 ? 1 : 0;
    // 0x800FE540: beq         $v0, $zero, L_800FEC70
    if (ctx->r2 == 0) {
        // 0x800FE544: addu        $s1, $a1, $zero
        ctx->r17 = ADD32(ctx->r5, 0);
            goto L_800FEC70;
    }
    // 0x800FE544: addu        $s1, $a1, $zero
    ctx->r17 = ADD32(ctx->r5, 0);
    // 0x800FE548: lui         $v0, 0x800B
    ctx->r2 = S32(0X800B << 16);
    // 0x800FE54C: addiu       $v0, $v0, -0x6C88
    ctx->r2 = ADD32(ctx->r2, -0X6C88);
    // 0x800FE550: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x800FE554: addu        $v1, $v1, $v0
    gpr jr_addend_800FE55C = ctx->r3;
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x800FE558: lw          $v0, 0x0($v1)
    ctx->r2 = ADD32(ctx->r3, 0X0);
    // 0x800FE55C: jr          $v0
    // 0x800FE560: nop

    switch (jr_addend_800FE55C >> 2) {
        case 0: goto L_800FEAD0; break;
        case 1: goto L_800FE854; break;
        case 2: goto L_800FE564; break;
        case 3: goto L_800FE750; break;
        case 4: goto L_800FE854; break;
        case 5: goto L_800FEC70; break;
        case 6: goto L_800FE9DC; break;
        case 7: goto L_800FE564; break;
        case 8: goto L_800FE9DC; break;
        default: switch_error(__func__, 0x800FE55C, 0x800A9378);
    }
    // 0x800FE560: nop

L_800FE564:
    // 0x800FE564: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x800FE568: addiu       $a0, $a0, -0x35D0
    ctx->r4 = ADD32(ctx->r4, -0X35D0);
    // 0x800FE56C: andi        $v1, $s2, 0xFF
    ctx->r3 = ctx->r18 & 0XFF;
    // 0x800FE570: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x800FE574: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800FE578: sll         $v0, $v0, 4
    ctx->r2 = S32(ctx->r2 << 4);
    // 0x800FE57C: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x800FE580: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x800FE584: addu        $s0, $v0, $a0
    ctx->r16 = ADD32(ctx->r2, ctx->r4);
    // 0x800FE588: lbu         $v0, 0x211($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X211);
    // 0x800FE58C: beq         $v0, $zero, L_800FE59C
    if (ctx->r2 == 0) {
        // 0x800FE590: addu        $a0, $a3, $zero
        ctx->r4 = ADD32(ctx->r7, 0);
            goto L_800FE59C;
    }
    // 0x800FE590: addu        $a0, $a3, $zero
    ctx->r4 = ADD32(ctx->r7, 0);
    // 0x800FE594: j           L_800FE858
    // 0x800FE598: sb          $zero, 0x211($s0)
    MEM_B(0X211, ctx->r16) = 0;
        goto L_800FE858;
    // 0x800FE598: sb          $zero, 0x211($s0)
    MEM_B(0X211, ctx->r16) = 0;
L_800FE59C:
    // 0x800FE59C: lui         $a1, 0x800B
    ctx->r5 = S32(0X800B << 16);
    // 0x800FE5A0: addiu       $a1, $a1, -0x6C98
    ctx->r5 = ADD32(ctx->r5, -0X6C98);
    // 0x800FE5A4: addiu       $a3, $sp, 0x28
    ctx->r7 = ADD32(ctx->r29, 0X28);
    // 0x800FE5A8: addiu       $v0, $sp, 0x58
    ctx->r2 = ADD32(ctx->r29, 0X58);
    // 0x800FE5AC: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // 0x800FE5B0: jal         0x80058360
    // 0x800FE5B4: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    func_80058360(rdram, ctx);
        goto after_0;
    // 0x800FE5B4: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    after_0:
    // 0x800FE5B8: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x800FE5BC: bnel        $s4, $v0, L_800FE638
    if (ctx->r20 != ctx->r2) {
        // 0x800FE5C0: addiu       $a0, $zero, 0xD
        ctx->r4 = ADD32(0, 0XD);
            goto L_800FE638;
    }
    goto skip_0;
    // 0x800FE5C0: addiu       $a0, $zero, 0xD
    ctx->r4 = ADD32(0, 0XD);
    skip_0:
    // 0x800FE5C4: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    // 0x800FE5C8: andi        $a1, $s1, 0xFFFF
    ctx->r5 = ctx->r17 & 0XFFFF;
    // 0x800FE5CC: addiu       $a2, $sp, 0x28
    ctx->r6 = ADD32(ctx->r29, 0X28);
    // 0x800FE5D0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800FE5D4: lui         $a3, 0x8011
    ctx->r7 = S32(0X8011 << 16);
    // 0x800FE5D8: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800FE5DC: lwc1        $f0, -0x6C64($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X6C64);
    // 0x800FE5E0: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
    // 0x800FE5E4: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // 0x800FE5E8: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    // 0x800FE5EC: lbu         $v0, 0x4($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X4);
    // 0x800FE5F0: addiu       $v1, $v1, -0x4B84
    ctx->r3 = ADD32(ctx->r3, -0X4B84);
    // 0x800FE5F4: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800FE5F8: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800FE5FC: lwc1        $f0, 0x0($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X0);
    // 0x800FE600: addiu       $a3, $a3, -0x4B40
    ctx->r7 = ADD32(ctx->r7, -0X4B40);
    // 0x800FE604: jal         0x8005E3B0
    // 0x800FE608: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    func_8005E3B0(rdram, ctx);
        goto after_1;
    // 0x800FE608: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    after_1:
    // 0x800FE60C: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x800FE610: lbu         $v1, 0x4($s0)
    ctx->r3 = MEM_BU(ctx->r16, 0X4);
    // 0x800FE614: addiu       $a0, $a0, -0x4B94
    ctx->r4 = ADD32(ctx->r4, -0X4B94);
    // 0x800FE618: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x800FE61C: addu        $v1, $v1, $a0
    ctx->r3 = ADD32(ctx->r3, ctx->r4);
    // 0x800FE620: lwc1        $f0, 0x0($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X0);
    // 0x800FE624: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x800FE628: swc1        $f0, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->f0.u32l;
    // 0x800FE62C: lbu         $v1, 0x4($s0)
    ctx->r3 = MEM_BU(ctx->r16, 0X4);
    // 0x800FE630: j           L_800FE6A4
    // 0x800FE634: addiu       $a0, $a0, -0x4B8C
    ctx->r4 = ADD32(ctx->r4, -0X4B8C);
        goto L_800FE6A4;
    // 0x800FE634: addiu       $a0, $a0, -0x4B8C
    ctx->r4 = ADD32(ctx->r4, -0X4B8C);
L_800FE638:
    // 0x800FE638: andi        $a1, $s1, 0xFFFF
    ctx->r5 = ctx->r17 & 0XFFFF;
    // 0x800FE63C: addiu       $a2, $sp, 0x28
    ctx->r6 = ADD32(ctx->r29, 0X28);
    // 0x800FE640: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800FE644: lui         $a3, 0x8011
    ctx->r7 = S32(0X8011 << 16);
    // 0x800FE648: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800FE64C: lwc1        $f0, -0x6C60($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X6C60);
    // 0x800FE650: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
    // 0x800FE654: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // 0x800FE658: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    // 0x800FE65C: lbu         $v0, 0x4($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X4);
    // 0x800FE660: addiu       $v1, $v1, -0x4B6C
    ctx->r3 = ADD32(ctx->r3, -0X4B6C);
    // 0x800FE664: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800FE668: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800FE66C: lwc1        $f0, 0x0($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X0);
    // 0x800FE670: addiu       $a3, $a3, -0x4B40
    ctx->r7 = ADD32(ctx->r7, -0X4B40);
    // 0x800FE674: jal         0x8005E3B0
    // 0x800FE678: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    func_8005E3B0(rdram, ctx);
        goto after_2;
    // 0x800FE678: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    after_2:
    // 0x800FE67C: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x800FE680: lbu         $v1, 0x4($s0)
    ctx->r3 = MEM_BU(ctx->r16, 0X4);
    // 0x800FE684: addiu       $a0, $a0, -0x4B7C
    ctx->r4 = ADD32(ctx->r4, -0X4B7C);
    // 0x800FE688: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x800FE68C: addu        $v1, $v1, $a0
    ctx->r3 = ADD32(ctx->r3, ctx->r4);
    // 0x800FE690: lwc1        $f0, 0x0($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X0);
    // 0x800FE694: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x800FE698: swc1        $f0, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->f0.u32l;
    // 0x800FE69C: lbu         $v1, 0x4($s0)
    ctx->r3 = MEM_BU(ctx->r16, 0X4);
    // 0x800FE6A0: addiu       $a0, $a0, -0x4B74
    ctx->r4 = ADD32(ctx->r4, -0X4B74);
L_800FE6A4:
    // 0x800FE6A4: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x800FE6A8: addu        $v1, $v1, $a0
    ctx->r3 = ADD32(ctx->r3, ctx->r4);
    // 0x800FE6AC: lwc1        $f0, 0x0($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X0);
    // 0x800FE6B0: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // 0x800FE6B4: swc1        $f0, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->f0.u32l;
    // 0x800FE6B8: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    // 0x800FE6BC: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    // 0x800FE6C0: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800FE6C4: lwc1        $f0, -0x6C5C($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X6C5C);
    // 0x800FE6C8: addiu       $a2, $sp, 0xB8
    ctx->r6 = ADD32(ctx->r29, 0XB8);
    // 0x800FE6CC: sh          $zero, 0xB8($sp)
    MEM_H(0XB8, ctx->r29) = 0;
    // 0x800FE6D0: sh          $s5, 0xBA($sp)
    MEM_H(0XBA, ctx->r29) = ctx->r21;
    // 0x800FE6D4: sw          $zero, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = 0;
    // 0x800FE6D8: sb          $zero, 0xCC($sp)
    MEM_B(0XCC, ctx->r29) = 0;
    // 0x800FE6DC: jal         0x8003E8DC
    // 0x800FE6E0: swc1        $f0, 0xC0($sp)
    MEM_W(0XC0, ctx->r29) = ctx->f0.u32l;
    slotDispatcherIter(rdram, ctx);
        goto after_3;
    // 0x800FE6E0: swc1        $f0, 0xC0($sp)
    MEM_W(0XC0, ctx->r29) = ctx->f0.u32l;
    after_3:
    // 0x800FE6E4: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x800FE6E8: bne         $s4, $v0, L_800FE720
    if (ctx->r20 != ctx->r2) {
        // 0x800FE6EC: addu        $a0, $zero, $zero
        ctx->r4 = ADD32(0, 0);
            goto L_800FE720;
    }
    // 0x800FE6EC: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x800FE6F0: addu        $a1, $s3, $zero
    ctx->r5 = ADD32(ctx->r19, 0);
    // 0x800FE6F4: addiu       $a2, $a1, 0x24
    ctx->r6 = ADD32(ctx->r5, 0X24);
    // 0x800FE6F8: lui         $a3, 0x4190
    ctx->r7 = S32(0X4190 << 16);
    // 0x800FE6FC: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800FE700: lwc1        $f0, -0x6C58($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X6C58);
    // 0x800FE704: addiu       $v0, $zero, 0x46
    ctx->r2 = ADD32(0, 0X46);
    // 0x800FE708: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // 0x800FE70C: addiu       $v0, $zero, 0x78
    ctx->r2 = ADD32(0, 0X78);
    // 0x800FE710: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x800FE714: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x800FE718: j           L_800FEC68
    // 0x800FE71C: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
        goto L_800FEC68;
    // 0x800FE71C: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
L_800FE720:
    // 0x800FE720: addu        $a1, $s3, $zero
    ctx->r5 = ADD32(ctx->r19, 0);
    // 0x800FE724: addiu       $a2, $a1, 0x24
    ctx->r6 = ADD32(ctx->r5, 0X24);
    // 0x800FE728: lui         $a3, 0x4190
    ctx->r7 = S32(0X4190 << 16);
    // 0x800FE72C: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800FE730: lwc1        $f0, -0x6C54($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X6C54);
    // 0x800FE734: addiu       $v0, $zero, 0x46
    ctx->r2 = ADD32(0, 0X46);
    // 0x800FE738: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // 0x800FE73C: addiu       $v0, $zero, 0x78
    ctx->r2 = ADD32(0, 0X78);
    // 0x800FE740: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x800FE744: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x800FE748: j           L_800FEC68
    // 0x800FE74C: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
        goto L_800FEC68;
    // 0x800FE74C: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
L_800FE750:
    // 0x800FE750: addu        $a0, $a3, $zero
    ctx->r4 = ADD32(ctx->r7, 0);
    // 0x800FE754: lui         $a1, 0x800B
    ctx->r5 = S32(0X800B << 16);
    // 0x800FE758: addiu       $a1, $a1, -0x6C90
    ctx->r5 = ADD32(ctx->r5, -0X6C90);
    // 0x800FE75C: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // 0x800FE760: addiu       $a3, $sp, 0x28
    ctx->r7 = ADD32(ctx->r29, 0X28);
    // 0x800FE764: addiu       $v0, $sp, 0x58
    ctx->r2 = ADD32(ctx->r29, 0X58);
    // 0x800FE768: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // 0x800FE76C: jal         0x80058360
    // 0x800FE770: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    func_80058360(rdram, ctx);
        goto after_4;
    // 0x800FE770: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    after_4:
    // 0x800FE774: lwc1        $f0, 0xC($s3)
    ctx->f0.u32l = MEM_W(ctx->r19, 0XC);
    // 0x800FE778: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800FE77C: lwc1        $f4, -0x6C50($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X6C50);
    // 0x800FE780: mul.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x800FE784: lwc1        $f2, 0x24($s3)
    ctx->f2.u32l = MEM_W(ctx->r19, 0X24);
    // 0x800FE788: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x800FE78C: swc1        $f0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f0.u32l;
    // 0x800FE790: lwc1        $f0, 0x10($s3)
    ctx->f0.u32l = MEM_W(ctx->r19, 0X10);
    // 0x800FE794: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    // 0x800FE798: mul.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x800FE79C: andi        $a1, $s1, 0xFFFF
    ctx->r5 = ctx->r17 & 0XFFFF;
    // 0x800FE7A0: addiu       $a2, $sp, 0x28
    ctx->r6 = ADD32(ctx->r29, 0X28);
    // 0x800FE7A4: lwc1        $f2, 0x28($s3)
    ctx->f2.u32l = MEM_W(ctx->r19, 0X28);
    // 0x800FE7A8: lui         $t0, 0x8011
    ctx->r8 = S32(0X8011 << 16);
    // 0x800FE7AC: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x800FE7B0: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800FE7B4: lwc1        $f2, -0x6C4C($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X6C4C);
    // 0x800FE7B8: lui         $a3, 0x8011
    ctx->r7 = S32(0X8011 << 16);
    // 0x800FE7BC: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x800FE7C0: addiu       $a3, $a3, -0x35D0
    ctx->r7 = ADD32(ctx->r7, -0X35D0);
    // 0x800FE7C4: andi        $v1, $s2, 0xFF
    ctx->r3 = ctx->r18 & 0XFF;
    // 0x800FE7C8: swc1        $f0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f0.u32l;
    // 0x800FE7CC: lwc1        $f0, 0x14($s3)
    ctx->f0.u32l = MEM_W(ctx->r19, 0X14);
    // 0x800FE7D0: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x800FE7D4: mul.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x800FE7D8: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800FE7DC: sll         $v0, $v0, 4
    ctx->r2 = S32(ctx->r2 << 4);
    // 0x800FE7E0: lwc1        $f2, 0x2C($s3)
    ctx->f2.u32l = MEM_W(ctx->r19, 0X2C);
    // 0x800FE7E4: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x800FE7E8: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x800FE7EC: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x800FE7F0: addu        $v0, $v0, $a3
    ctx->r2 = ADD32(ctx->r2, ctx->r7);
    // 0x800FE7F4: swc1        $f0, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f0.u32l;
    // 0x800FE7F8: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x800FE7FC: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x800FE800: lbu         $v0, 0x4($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X4);
    // 0x800FE804: addiu       $t0, $t0, -0x4B54
    ctx->r8 = ADD32(ctx->r8, -0X4B54);
    // 0x800FE808: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800FE80C: addu        $v0, $v0, $t0
    ctx->r2 = ADD32(ctx->r2, ctx->r8);
    // 0x800FE810: lwc1        $f0, 0x0($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X0);
    // 0x800FE814: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    // 0x800FE818: jal         0x8005E3B0
    // 0x800FE81C: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    func_8005E3B0(rdram, ctx);
        goto after_5;
    // 0x800FE81C: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    after_5:
    // 0x800FE820: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x800FE824: addu        $a1, $s3, $zero
    ctx->r5 = ADD32(ctx->r19, 0);
    // 0x800FE828: addiu       $a2, $a1, 0x24
    ctx->r6 = ADD32(ctx->r5, 0X24);
    // 0x800FE82C: lui         $a3, 0x4190
    ctx->r7 = S32(0X4190 << 16);
    // 0x800FE830: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800FE834: lwc1        $f0, -0x6C48($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X6C48);
    // 0x800FE838: addiu       $v0, $zero, 0x47
    ctx->r2 = ADD32(0, 0X47);
    // 0x800FE83C: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // 0x800FE840: addiu       $v0, $zero, 0x78
    ctx->r2 = ADD32(0, 0X78);
    // 0x800FE844: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x800FE848: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x800FE84C: j           L_800FEC68
    // 0x800FE850: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
        goto L_800FEC68;
    // 0x800FE850: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
L_800FE854:
    // 0x800FE854: addu        $a0, $a3, $zero
    ctx->r4 = ADD32(ctx->r7, 0);
L_800FE858:
    // 0x800FE858: lui         $a1, 0x800B
    ctx->r5 = S32(0X800B << 16);
    // 0x800FE85C: addiu       $a1, $a1, -0x6C98
    ctx->r5 = ADD32(ctx->r5, -0X6C98);
    // 0x800FE860: addiu       $a3, $sp, 0x28
    ctx->r7 = ADD32(ctx->r29, 0X28);
    // 0x800FE864: addiu       $v0, $sp, 0x58
    ctx->r2 = ADD32(ctx->r29, 0X58);
    // 0x800FE868: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // 0x800FE86C: jal         0x80058360
    // 0x800FE870: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    func_80058360(rdram, ctx);
        goto after_6;
    // 0x800FE870: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    after_6:
    // 0x800FE874: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x800FE878: bne         $s4, $v0, L_800FE930
    if (ctx->r20 != ctx->r2) {
        // 0x800FE87C: addiu       $a0, $zero, 0xD
        ctx->r4 = ADD32(0, 0XD);
            goto L_800FE930;
    }
    // 0x800FE87C: addiu       $a0, $zero, 0xD
    ctx->r4 = ADD32(0, 0XD);
    // 0x800FE880: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    // 0x800FE884: andi        $a1, $s1, 0xFFFF
    ctx->r5 = ctx->r17 & 0XFFFF;
    // 0x800FE888: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800FE88C: lui         $a3, 0x8011
    ctx->r7 = S32(0X8011 << 16);
    // 0x800FE890: lui         $a2, 0x8011
    ctx->r6 = S32(0X8011 << 16);
    // 0x800FE894: addiu       $a2, $a2, -0x35D0
    ctx->r6 = ADD32(ctx->r6, -0X35D0);
    // 0x800FE898: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // 0x800FE89C: andi        $v0, $s2, 0xFF
    ctx->r2 = ctx->r18 & 0XFF;
    // 0x800FE8A0: sll         $v1, $v0, 2
    ctx->r3 = S32(ctx->r2 << 2);
    // 0x800FE8A4: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x800FE8A8: sll         $v1, $v1, 4
    ctx->r3 = S32(ctx->r3 << 4);
    // 0x800FE8AC: subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // 0x800FE8B0: sll         $v1, $v1, 3
    ctx->r3 = S32(ctx->r3 << 3);
    // 0x800FE8B4: addu        $v1, $v1, $a2
    ctx->r3 = ADD32(ctx->r3, ctx->r6);
    // 0x800FE8B8: addiu       $a3, $a3, -0x4BB4
    ctx->r7 = ADD32(ctx->r7, -0X4BB4);
    // 0x800FE8BC: addiu       $a2, $sp, 0x28
    ctx->r6 = ADD32(ctx->r29, 0X28);
    // 0x800FE8C0: lbu         $v0, 0x4($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X4);
    // 0x800FE8C4: lui         $t0, 0x8011
    ctx->r8 = S32(0X8011 << 16);
    // 0x800FE8C8: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800FE8CC: addu        $v0, $v0, $a3
    ctx->r2 = ADD32(ctx->r2, ctx->r7);
    // 0x800FE8D0: lwc1        $f0, 0x0($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X0);
    // 0x800FE8D4: addiu       $t0, $t0, -0x4BAC
    ctx->r8 = ADD32(ctx->r8, -0X4BAC);
    // 0x800FE8D8: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    // 0x800FE8DC: lbu         $v0, 0x4($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X4);
    // 0x800FE8E0: lui         $a3, 0x8011
    ctx->r7 = S32(0X8011 << 16);
    // 0x800FE8E4: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800FE8E8: addu        $v0, $v0, $t0
    ctx->r2 = ADD32(ctx->r2, ctx->r8);
    // 0x800FE8EC: lwc1        $f0, 0x0($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X0);
    // 0x800FE8F0: addiu       $a3, $a3, -0x4B40
    ctx->r7 = ADD32(ctx->r7, -0X4B40);
    // 0x800FE8F4: jal         0x8005E3B0
    // 0x800FE8F8: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    func_8005E3B0(rdram, ctx);
        goto after_7;
    // 0x800FE8F8: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    after_7:
    // 0x800FE8FC: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x800FE900: addu        $a1, $s3, $zero
    ctx->r5 = ADD32(ctx->r19, 0);
    // 0x800FE904: addiu       $a2, $a1, 0x24
    ctx->r6 = ADD32(ctx->r5, 0X24);
    // 0x800FE908: lui         $a3, 0x4190
    ctx->r7 = S32(0X4190 << 16);
    // 0x800FE90C: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800FE910: lwc1        $f0, -0x6C44($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X6C44);
    // 0x800FE914: addiu       $v0, $zero, 0x46
    ctx->r2 = ADD32(0, 0X46);
    // 0x800FE918: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // 0x800FE91C: addiu       $v0, $zero, 0x78
    ctx->r2 = ADD32(0, 0X78);
    // 0x800FE920: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x800FE924: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x800FE928: j           L_800FEC68
    // 0x800FE92C: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
        goto L_800FEC68;
    // 0x800FE92C: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
L_800FE930:
    // 0x800FE930: andi        $a1, $s1, 0xFFFF
    ctx->r5 = ctx->r17 & 0XFFFF;
    // 0x800FE934: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800FE938: lui         $a3, 0x8011
    ctx->r7 = S32(0X8011 << 16);
    // 0x800FE93C: lui         $a2, 0x8011
    ctx->r6 = S32(0X8011 << 16);
    // 0x800FE940: addiu       $a2, $a2, -0x35D0
    ctx->r6 = ADD32(ctx->r6, -0X35D0);
    // 0x800FE944: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // 0x800FE948: andi        $v0, $s2, 0xFF
    ctx->r2 = ctx->r18 & 0XFF;
    // 0x800FE94C: sll         $v1, $v0, 2
    ctx->r3 = S32(ctx->r2 << 2);
    // 0x800FE950: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x800FE954: sll         $v1, $v1, 4
    ctx->r3 = S32(ctx->r3 << 4);
    // 0x800FE958: subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // 0x800FE95C: sll         $v1, $v1, 3
    ctx->r3 = S32(ctx->r3 << 3);
    // 0x800FE960: addu        $v1, $v1, $a2
    ctx->r3 = ADD32(ctx->r3, ctx->r6);
    // 0x800FE964: addiu       $a3, $a3, -0x4BA4
    ctx->r7 = ADD32(ctx->r7, -0X4BA4);
    // 0x800FE968: addiu       $a2, $sp, 0x28
    ctx->r6 = ADD32(ctx->r29, 0X28);
    // 0x800FE96C: lbu         $v0, 0x4($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X4);
    // 0x800FE970: lui         $t0, 0x8011
    ctx->r8 = S32(0X8011 << 16);
    // 0x800FE974: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800FE978: addu        $v0, $v0, $a3
    ctx->r2 = ADD32(ctx->r2, ctx->r7);
    // 0x800FE97C: lwc1        $f0, 0x0($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X0);
    // 0x800FE980: addiu       $t0, $t0, -0x4B9C
    ctx->r8 = ADD32(ctx->r8, -0X4B9C);
    // 0x800FE984: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    // 0x800FE988: lbu         $v0, 0x4($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X4);
    // 0x800FE98C: lui         $a3, 0x8011
    ctx->r7 = S32(0X8011 << 16);
    // 0x800FE990: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800FE994: addu        $v0, $v0, $t0
    ctx->r2 = ADD32(ctx->r2, ctx->r8);
    // 0x800FE998: lwc1        $f0, 0x0($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X0);
    // 0x800FE99C: addiu       $a3, $a3, -0x4B40
    ctx->r7 = ADD32(ctx->r7, -0X4B40);
    // 0x800FE9A0: jal         0x8005E3B0
    // 0x800FE9A4: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    func_8005E3B0(rdram, ctx);
        goto after_8;
    // 0x800FE9A4: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    after_8:
    // 0x800FE9A8: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x800FE9AC: addu        $a1, $s3, $zero
    ctx->r5 = ADD32(ctx->r19, 0);
    // 0x800FE9B0: addiu       $a2, $a1, 0x24
    ctx->r6 = ADD32(ctx->r5, 0X24);
    // 0x800FE9B4: lui         $a3, 0x4190
    ctx->r7 = S32(0X4190 << 16);
    // 0x800FE9B8: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800FE9BC: lwc1        $f0, -0x6C40($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X6C40);
    // 0x800FE9C0: addiu       $v0, $zero, 0x46
    ctx->r2 = ADD32(0, 0X46);
    // 0x800FE9C4: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // 0x800FE9C8: addiu       $v0, $zero, 0x78
    ctx->r2 = ADD32(0, 0X78);
    // 0x800FE9CC: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x800FE9D0: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x800FE9D4: j           L_800FEC68
    // 0x800FE9D8: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
        goto L_800FEC68;
    // 0x800FE9D8: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
L_800FE9DC:
    // 0x800FE9DC: addu        $a0, $a3, $zero
    ctx->r4 = ADD32(ctx->r7, 0);
    // 0x800FE9E0: lui         $a1, 0x800B
    ctx->r5 = S32(0X800B << 16);
    // 0x800FE9E4: addiu       $a1, $a1, -0x6C98
    ctx->r5 = ADD32(ctx->r5, -0X6C98);
    // 0x800FE9E8: addiu       $a3, $sp, 0x28
    ctx->r7 = ADD32(ctx->r29, 0X28);
    // 0x800FE9EC: addiu       $v0, $sp, 0x58
    ctx->r2 = ADD32(ctx->r29, 0X58);
    // 0x800FE9F0: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // 0x800FE9F4: jal         0x80058360
    // 0x800FE9F8: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    func_80058360(rdram, ctx);
        goto after_9;
    // 0x800FE9F8: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    after_9:
    // 0x800FE9FC: addiu       $a0, $zero, 0xE
    ctx->r4 = ADD32(0, 0XE);
    // 0x800FEA00: andi        $a1, $s1, 0xFFFF
    ctx->r5 = ctx->r17 & 0XFFFF;
    // 0x800FEA04: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800FEA08: lui         $a3, 0x8011
    ctx->r7 = S32(0X8011 << 16);
    // 0x800FEA0C: lui         $a2, 0x8011
    ctx->r6 = S32(0X8011 << 16);
    // 0x800FEA10: addiu       $a2, $a2, -0x35D0
    ctx->r6 = ADD32(ctx->r6, -0X35D0);
    // 0x800FEA14: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // 0x800FEA18: andi        $v0, $s2, 0xFF
    ctx->r2 = ctx->r18 & 0XFF;
    // 0x800FEA1C: sll         $v1, $v0, 2
    ctx->r3 = S32(ctx->r2 << 2);
    // 0x800FEA20: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x800FEA24: sll         $v1, $v1, 4
    ctx->r3 = S32(ctx->r3 << 4);
    // 0x800FEA28: subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // 0x800FEA2C: sll         $v1, $v1, 3
    ctx->r3 = S32(ctx->r3 << 3);
    // 0x800FEA30: addu        $v1, $v1, $a2
    ctx->r3 = ADD32(ctx->r3, ctx->r6);
    // 0x800FEA34: addiu       $a3, $a3, -0x4B64
    ctx->r7 = ADD32(ctx->r7, -0X4B64);
    // 0x800FEA38: addiu       $a2, $sp, 0x28
    ctx->r6 = ADD32(ctx->r29, 0X28);
    // 0x800FEA3C: lbu         $v0, 0x4($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X4);
    // 0x800FEA40: lui         $t0, 0x8011
    ctx->r8 = S32(0X8011 << 16);
    // 0x800FEA44: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800FEA48: addu        $v0, $v0, $a3
    ctx->r2 = ADD32(ctx->r2, ctx->r7);
    // 0x800FEA4C: lwc1        $f0, 0x0($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X0);
    // 0x800FEA50: addiu       $t0, $t0, -0x4B5C
    ctx->r8 = ADD32(ctx->r8, -0X4B5C);
    // 0x800FEA54: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    // 0x800FEA58: lbu         $v0, 0x4($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X4);
    // 0x800FEA5C: lui         $a3, 0x8011
    ctx->r7 = S32(0X8011 << 16);
    // 0x800FEA60: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800FEA64: addu        $v0, $v0, $t0
    ctx->r2 = ADD32(ctx->r2, ctx->r8);
    // 0x800FEA68: lwc1        $f0, 0x0($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X0);
    // 0x800FEA6C: addiu       $a3, $a3, -0x4B40
    ctx->r7 = ADD32(ctx->r7, -0X4B40);
    // 0x800FEA70: jal         0x8005E3B0
    // 0x800FEA74: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    func_8005E3B0(rdram, ctx);
        goto after_10;
    // 0x800FEA74: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    after_10:
    // 0x800FEA78: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // 0x800FEA7C: addiu       $v0, $zero, 0x9
    ctx->r2 = ADD32(0, 0X9);
    // 0x800FEA80: bnel        $s4, $v0, L_800FEAA0
    if (ctx->r20 != ctx->r2) {
        // 0x800FEA84: addu        $a0, $zero, $zero
        ctx->r4 = ADD32(0, 0);
            goto L_800FEAA0;
    }
    goto skip_1;
    // 0x800FEA84: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    skip_1:
    // 0x800FEA88: sh          $zero, 0xB8($sp)
    MEM_H(0XB8, ctx->r29) = 0;
    // 0x800FEA8C: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    // 0x800FEA90: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    // 0x800FEA94: jal         0x8003E8DC
    // 0x800FEA98: addiu       $a2, $sp, 0xB8
    ctx->r6 = ADD32(ctx->r29, 0XB8);
    slotDispatcherIter(rdram, ctx);
        goto after_11;
    // 0x800FEA98: addiu       $a2, $sp, 0xB8
    ctx->r6 = ADD32(ctx->r29, 0XB8);
    after_11:
    // 0x800FEA9C: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
L_800FEAA0:
    // 0x800FEAA0: addu        $a1, $s3, $zero
    ctx->r5 = ADD32(ctx->r19, 0);
    // 0x800FEAA4: addiu       $a2, $a1, 0x24
    ctx->r6 = ADD32(ctx->r5, 0X24);
    // 0x800FEAA8: lui         $a3, 0x4190
    ctx->r7 = S32(0X4190 << 16);
    // 0x800FEAAC: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800FEAB0: lwc1        $f0, -0x6C3C($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X6C3C);
    // 0x800FEAB4: addiu       $v0, $zero, 0x46
    ctx->r2 = ADD32(0, 0X46);
    // 0x800FEAB8: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // 0x800FEABC: addiu       $v0, $zero, 0x78
    ctx->r2 = ADD32(0, 0X78);
    // 0x800FEAC0: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x800FEAC4: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x800FEAC8: j           L_800FEC68
    // 0x800FEACC: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
        goto L_800FEC68;
    // 0x800FEACC: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
L_800FEAD0:
    // 0x800FEAD0: addu        $a0, $a3, $zero
    ctx->r4 = ADD32(ctx->r7, 0);
    // 0x800FEAD4: lui         $a1, 0x800B
    ctx->r5 = S32(0X800B << 16);
    // 0x800FEAD8: addiu       $a1, $a1, -0x6C98
    ctx->r5 = ADD32(ctx->r5, -0X6C98);
    // 0x800FEADC: addiu       $a3, $sp, 0x28
    ctx->r7 = ADD32(ctx->r29, 0X28);
    // 0x800FEAE0: addiu       $v0, $sp, 0x58
    ctx->r2 = ADD32(ctx->r29, 0X58);
    // 0x800FEAE4: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // 0x800FEAE8: jal         0x80058360
    // 0x800FEAEC: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    func_80058360(rdram, ctx);
        goto after_12;
    // 0x800FEAEC: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    after_12:
    // 0x800FEAF0: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x800FEAF4: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800FEAF8: addiu       $a2, $v0, 0x7DB8
    ctx->r6 = ADD32(ctx->r2, 0X7DB8);
    // 0x800FEAFC: lw          $v1, 0xBC($a2)
    ctx->r3 = MEM_W(ctx->r6, 0XBC);
    // 0x800FEB00: addiu       $a0, $a0, -0x72E8
    ctx->r4 = ADD32(ctx->r4, -0X72E8);
    // 0x800FEB04: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x800FEB08: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800FEB0C: sll         $v0, $v0, 4
    ctx->r2 = S32(ctx->r2 << 4);
    // 0x800FEB10: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800FEB14: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800FEB18: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x800FEB1C: lw          $v0, 0x4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X4);
    // 0x800FEB20: lhu         $v1, 0x4($v0)
    ctx->r3 = MEM_HU(ctx->r2, 0X4);
    // 0x800FEB24: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x800FEB28: bne         $v1, $v0, L_800FEB4C
    if (ctx->r3 != ctx->r2) {
        // 0x800FEB2C: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_800FEB4C;
    }
    // 0x800FEB2C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800FEB30: lhu         $v1, 0xB8($a2)
    ctx->r3 = MEM_HU(ctx->r6, 0XB8);
    // 0x800FEB34: bne         $v1, $v0, L_800FEB4C
    if (ctx->r3 != ctx->r2) {
        // 0x800FEB38: addiu       $a0, $sp, 0x28
        ctx->r4 = ADD32(ctx->r29, 0X28);
            goto L_800FEB4C;
    }
    // 0x800FEB38: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    // 0x800FEB3C: lui         $a1, 0x8011
    ctx->r5 = S32(0X8011 << 16);
    // 0x800FEB40: addiu       $a1, $a1, -0x4B34
    ctx->r5 = ADD32(ctx->r5, -0X4B34);
    // 0x800FEB44: jal         0x800C713C
    // 0x800FEB48: addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
    func_800C713C(rdram, ctx);
        goto after_13;
    // 0x800FEB48: addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
    after_13:
L_800FEB4C:
    // 0x800FEB4C: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800FEB50: lwc1        $f20, -0x6C38($at)
    ctx->f20.u32l = MEM_W(ctx->r1, -0X6C38);
    // 0x800FEB54: addiu       $a0, $sp, 0x88
    ctx->r4 = ADD32(ctx->r29, 0X88);
    // 0x800FEB58: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x800FEB5C: jal         0x80059B50
    // 0x800FEB60: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    func_80059B50(rdram, ctx);
        goto after_14;
    // 0x800FEB60: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    after_14:
    // 0x800FEB64: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x800FEB68: addiu       $a0, $a0, -0x35D0
    ctx->r4 = ADD32(ctx->r4, -0X35D0);
    // 0x800FEB6C: andi        $v1, $s2, 0xFF
    ctx->r3 = ctx->r18 & 0XFF;
    // 0x800FEB70: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x800FEB74: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800FEB78: sll         $v0, $v0, 4
    ctx->r2 = S32(ctx->r2 << 4);
    // 0x800FEB7C: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x800FEB80: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x800FEB84: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x800FEB88: lwc1        $f0, 0x22C($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X22C);
    // 0x800FEB8C: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800FEB90: lwc1        $f4, -0x6C34($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X6C34);
    // 0x800FEB94: div.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = DIV_S(ctx->f0.fl, ctx->f4.fl);
    // 0x800FEB98: c.lt.s      $f20, $f6
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f20.fl < ctx->f6.fl;
    // 0x800FEB9C: nop

    // 0x800FEBA0: bc1tl       L_800FEBA8
    if (c1cs) {
        // 0x800FEBA4: mov.s       $f6, $f20
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    ctx->f6.fl = ctx->f20.fl;
            goto L_800FEBA8;
    }
    goto skip_2;
    // 0x800FEBA4: mov.s       $f6, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    ctx->f6.fl = ctx->f20.fl;
    skip_2:
L_800FEBA8:
    // 0x800FEBA8: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800FEBAC: lwc1        $f2, -0x6C30($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X6C30);
    // 0x800FEBB0: c.lt.s      $f6, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f6.fl < ctx->f2.fl;
    // 0x800FEBB4: nop

    // 0x800FEBB8: bc1f        L_800FEBC4
    if (!c1cs) {
        // 0x800FEBBC: mov.s       $f0, $f6
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    ctx->f0.fl = ctx->f6.fl;
            goto L_800FEBC4;
    }
    // 0x800FEBBC: mov.s       $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    ctx->f0.fl = ctx->f6.fl;
    // 0x800FEBC0: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
L_800FEBC4:
    // 0x800FEBC4: mul.s       $f4, $f0, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x800FEBC8: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800FEBCC: lwc1        $f2, -0x6C2C($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X6C2C);
    // 0x800FEBD0: mul.s       $f2, $f0, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x800FEBD4: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800FEBD8: lwc1        $f0, -0x6C28($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X6C28);
    // 0x800FEBDC: add.s       $f6, $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f0.fl;
    // 0x800FEBE0: swc1        $f4, 0xD8($sp)
    MEM_W(0XD8, ctx->r29) = ctx->f4.u32l;
    // 0x800FEBE4: swc1        $f4, 0xDC($sp)
    MEM_W(0XDC, ctx->r29) = ctx->f4.u32l;
    // 0x800FEBE8: c.lt.s      $f20, $f6
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f20.fl < ctx->f6.fl;
    // 0x800FEBEC: nop

    // 0x800FEBF0: bc1f        L_800FEBFC
    if (!c1cs) {
        // 0x800FEBF4: swc1        $f2, 0xE0($sp)
        MEM_W(0XE0, ctx->r29) = ctx->f2.u32l;
            goto L_800FEBFC;
    }
    // 0x800FEBF4: swc1        $f2, 0xE0($sp)
    MEM_W(0XE0, ctx->r29) = ctx->f2.u32l;
    // 0x800FEBF8: mov.s       $f6, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    ctx->f6.fl = ctx->f20.fl;
L_800FEBFC:
    // 0x800FEBFC: addiu       $a0, $zero, 0xC
    ctx->r4 = ADD32(0, 0XC);
    // 0x800FEC00: andi        $a1, $s1, 0xFFFF
    ctx->r5 = ctx->r17 & 0XFFFF;
    // 0x800FEC04: addiu       $a2, $sp, 0x28
    ctx->r6 = ADD32(ctx->r29, 0X28);
    // 0x800FEC08: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800FEC0C: lwc1        $f0, -0x6C24($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X6C24);
    // 0x800FEC10: addiu       $a3, $sp, 0xD8
    ctx->r7 = ADD32(ctx->r29, 0XD8);
    // 0x800FEC14: mul.s       $f0, $f6, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x800FEC18: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800FEC1C: lwc1        $f2, -0x6C20($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X6C20);
    // 0x800FEC20: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800FEC24: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // 0x800FEC28: swc1        $f2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f2.u32l;
    // 0x800FEC2C: jal         0x8005E3B0
    // 0x800FEC30: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    func_8005E3B0(rdram, ctx);
        goto after_15;
    // 0x800FEC30: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    after_15:
    // 0x800FEC34: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x800FEC38: addu        $a1, $s3, $zero
    ctx->r5 = ADD32(ctx->r19, 0);
    // 0x800FEC3C: addiu       $a2, $a1, 0x24
    ctx->r6 = ADD32(ctx->r5, 0X24);
    // 0x800FEC40: lui         $a3, 0x41A0
    ctx->r7 = S32(0X41A0 << 16);
    // 0x800FEC44: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800FEC48: lwc1        $f0, -0x6C1C($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X6C1C);
    // 0x800FEC4C: addiu       $v0, $zero, 0x34
    ctx->r2 = ADD32(0, 0X34);
    // 0x800FEC50: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // 0x800FEC54: addiu       $v0, $zero, 0x78
    ctx->r2 = ADD32(0, 0X78);
    // 0x800FEC58: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x800FEC5C: addiu       $v0, $zero, 0x3C
    ctx->r2 = ADD32(0, 0X3C);
    // 0x800FEC60: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x800FEC64: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
L_800FEC68:
    // 0x800FEC68: jal         0x800989D8
    // 0x800FEC6C: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    func_800989D8(rdram, ctx);
        goto after_16;
    // 0x800FEC6C: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    after_16:
L_800FEC70:
    // 0x800FEC70: lw          $ra, 0x100($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X100);
    // 0x800FEC74: lw          $s5, 0xFC($sp)
    ctx->r21 = MEM_W(ctx->r29, 0XFC);
    // 0x800FEC78: lw          $s4, 0xF8($sp)
    ctx->r20 = MEM_W(ctx->r29, 0XF8);
    // 0x800FEC7C: lw          $s3, 0xF4($sp)
    ctx->r19 = MEM_W(ctx->r29, 0XF4);
    // 0x800FEC80: lw          $s2, 0xF0($sp)
    ctx->r18 = MEM_W(ctx->r29, 0XF0);
    // 0x800FEC84: lw          $s1, 0xEC($sp)
    ctx->r17 = MEM_W(ctx->r29, 0XEC);
    // 0x800FEC88: lw          $s0, 0xE8($sp)
    ctx->r16 = MEM_W(ctx->r29, 0XE8);
    // 0x800FEC8C: ldc1        $f20, 0x108($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X108);
    // 0x800FEC90: jr          $ra
    // 0x800FEC94: addiu       $sp, $sp, 0x110
    ctx->r29 = ADD32(ctx->r29, 0X110);
    return;
    // 0x800FEC94: addiu       $sp, $sp, 0x110
    ctx->r29 = ADD32(ctx->r29, 0X110);
;}
RECOMP_FUNC void func_800FEC98(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800FEC98: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800FEC9C: andi        $v0, $a0, 0xFF
    ctx->r2 = ctx->r4 & 0XFF;
    // 0x800FECA0: bne         $v0, $zero, L_800FED14
    if (ctx->r2 != 0) {
        // 0x800FECA4: sw          $ra, 0x10($sp)
        MEM_W(0X10, ctx->r29) = ctx->r31;
            goto L_800FED14;
    }
    // 0x800FECA4: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x800FECA8: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800FECAC: lbu         $v0, 0xB12($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0XB12);
    // 0x800FECB0: addiu       $v1, $v0, -0x2
    ctx->r3 = ADD32(ctx->r2, -0X2);
    // 0x800FECB4: sltiu       $v0, $v1, 0x7
    ctx->r2 = ctx->r3 < 0X7 ? 1 : 0;
    // 0x800FECB8: beq         $v0, $zero, L_800FED14
    if (ctx->r2 == 0) {
        // 0x800FECBC: lui         $v0, 0x800B
        ctx->r2 = S32(0X800B << 16);
            goto L_800FED14;
    }
    // 0x800FECBC: lui         $v0, 0x800B
    ctx->r2 = S32(0X800B << 16);
    // 0x800FECC0: addiu       $v0, $v0, -0x6C18
    ctx->r2 = ADD32(ctx->r2, -0X6C18);
    // 0x800FECC4: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x800FECC8: addu        $v1, $v1, $v0
    gpr jr_addend_800FECD0 = ctx->r3;
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x800FECCC: lw          $v0, 0x0($v1)
    ctx->r2 = ADD32(ctx->r3, 0X0);
    // 0x800FECD0: jr          $v0
    // 0x800FECD4: nop

    switch (jr_addend_800FECD0 >> 2) {
        case 0: goto L_800FECD8; break;
        case 1: goto L_800FECD8; break;
        case 2: goto L_800FED00; break;
        case 3: goto L_800FECEC; break;
        case 4: goto L_800FED14; break;
        case 5: goto L_800FED14; break;
        case 6: goto L_800FECEC; break;
        default: switch_error(__func__, 0x800FECD0, 0x800A93E8);
    }
    // 0x800FECD4: nop

L_800FECD8:
    // 0x800FECD8: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800FECDC: lw          $v0, 0xB4C($v0)
    ctx->r2 = MEM_W(ctx->r2, 0XB4C);
    // 0x800FECE0: srl         $v0, $v0, 10
    ctx->r2 = S32(U32(ctx->r2) >> 10);
    // 0x800FECE4: j           L_800FED18
    // 0x800FECE8: andi        $a3, $v0, 0x1
    ctx->r7 = ctx->r2 & 0X1;
        goto L_800FED18;
    // 0x800FECE8: andi        $a3, $v0, 0x1
    ctx->r7 = ctx->r2 & 0X1;
L_800FECEC:
    // 0x800FECEC: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800FECF0: lw          $v0, 0xB4C($v0)
    ctx->r2 = MEM_W(ctx->r2, 0XB4C);
    // 0x800FECF4: srl         $v0, $v0, 12
    ctx->r2 = S32(U32(ctx->r2) >> 12);
    // 0x800FECF8: j           L_800FED18
    // 0x800FECFC: andi        $a3, $v0, 0x1
    ctx->r7 = ctx->r2 & 0X1;
        goto L_800FED18;
    // 0x800FECFC: andi        $a3, $v0, 0x1
    ctx->r7 = ctx->r2 & 0X1;
L_800FED00:
    // 0x800FED00: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800FED04: lw          $v0, 0xB4C($v0)
    ctx->r2 = MEM_W(ctx->r2, 0XB4C);
    // 0x800FED08: srl         $v0, $v0, 15
    ctx->r2 = S32(U32(ctx->r2) >> 15);
    // 0x800FED0C: j           L_800FED18
    // 0x800FED10: andi        $a3, $v0, 0x1
    ctx->r7 = ctx->r2 & 0X1;
        goto L_800FED18;
    // 0x800FED10: andi        $a3, $v0, 0x1
    ctx->r7 = ctx->r2 & 0X1;
L_800FED14:
    // 0x800FED14: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
L_800FED18:
    // 0x800FED18: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800FED1C: addiu       $v0, $v0, 0xB10
    ctx->r2 = ADD32(ctx->r2, 0XB10);
    // 0x800FED20: lbu         $a1, 0x2($v0)
    ctx->r5 = MEM_BU(ctx->r2, 0X2);
    // 0x800FED24: lbu         $a2, 0x3($v0)
    ctx->r6 = MEM_BU(ctx->r2, 0X3);
    // 0x800FED28: jal         0x800FBE20
    // 0x800FED2C: andi        $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 & 0XFF;
    func_800FBE20(rdram, ctx);
        goto after_0;
    // 0x800FED2C: andi        $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 & 0XFF;
    after_0:
    // 0x800FED30: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x800FED34: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x800FED38: jr          $ra
    // 0x800FED3C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x800FED3C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_800FED40(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800FED40: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800FED44: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x800FED48: addu        $s1, $zero, $zero
    ctx->r17 = ADD32(0, 0);
    // 0x800FED4C: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800FED50: sw          $s3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r19;
    // 0x800FED54: addiu       $s3, $v0, -0x35D0
    ctx->r19 = ADD32(ctx->r2, -0X35D0);
    // 0x800FED58: sdc1        $f20, 0x28($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X28, ctx->r29);
    // 0x800FED5C: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800FED60: lwc1        $f20, -0x6BFC($at)
    ctx->f20.u32l = MEM_W(ctx->r1, -0X6BFC);
    // 0x800FED64: lui         $v0, 0x800B
    ctx->r2 = S32(0X800B << 16);
    // 0x800FED68: sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // 0x800FED6C: addiu       $s2, $v0, -0x6BF8
    ctx->r18 = ADD32(ctx->r2, -0X6BF8);
    // 0x800FED70: sw          $ra, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r31;
    // 0x800FED74: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x800FED78: andi        $v1, $s1, 0xFF
    ctx->r3 = ctx->r17 & 0XFF;
L_800FED7C:
    // 0x800FED7C: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x800FED80: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800FED84: sll         $v0, $v0, 4
    ctx->r2 = S32(ctx->r2 << 4);
    // 0x800FED88: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x800FED8C: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x800FED90: addu        $s0, $v0, $s3
    ctx->r16 = ADD32(ctx->r2, ctx->r19);
    // 0x800FED94: lbu         $v0, 0x0($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X0);
    // 0x800FED98: addiu       $v1, $v0, -0x1
    ctx->r3 = ADD32(ctx->r2, -0X1);
    // 0x800FED9C: sltiu       $v0, $v1, 0x8
    ctx->r2 = ctx->r3 < 0X8 ? 1 : 0;
    // 0x800FEDA0: beq         $v0, $zero, L_800FEDCC
    if (ctx->r2 == 0) {
        // 0x800FEDA4: sll         $v0, $v1, 2
        ctx->r2 = S32(ctx->r3 << 2);
            goto L_800FEDCC;
    }
    // 0x800FEDA4: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x800FEDA8: addu        $v0, $v0, $s2
    gpr jr_addend_800FEDB0 = ctx->r2;
    ctx->r2 = ADD32(ctx->r2, ctx->r18);
    // 0x800FEDAC: lw          $v0, 0x0($v0)
    ctx->r2 = ADD32(ctx->r2, 0X0);
    // 0x800FEDB0: jr          $v0
    // 0x800FEDB4: nop

    switch (jr_addend_800FEDB0 >> 2) {
        case 0: goto L_800FEDC8; break;
        case 1: goto L_800FEDC8; break;
        case 2: goto L_800FEDB8; break;
        case 3: goto L_800FEDC8; break;
        case 4: goto L_800FEDC8; break;
        case 5: goto L_800FEDCC; break;
        case 6: goto L_800FEDCC; break;
        case 7: goto L_800FEDB8; break;
        default: switch_error(__func__, 0x800FEDB0, 0x800A9408);
    }
    // 0x800FEDB4: nop

L_800FEDB8:
    // 0x800FEDB8: sb          $zero, 0x1($s0)
    MEM_B(0X1, ctx->r16) = 0;
    // 0x800FEDBC: sb          $zero, 0x210($s0)
    MEM_B(0X210, ctx->r16) = 0;
    // 0x800FEDC0: j           L_800FEDCC
    // 0x800FEDC4: sb          $zero, 0x211($s0)
    MEM_B(0X211, ctx->r16) = 0;
        goto L_800FEDCC;
    // 0x800FEDC4: sb          $zero, 0x211($s0)
    MEM_B(0X211, ctx->r16) = 0;
L_800FEDC8:
    // 0x800FEDC8: sb          $zero, 0x1($s0)
    MEM_B(0X1, ctx->r16) = 0;
L_800FEDCC:
    // 0x800FEDCC: jal         0x8006C940
    // 0x800FEDD0: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    getPlayerVehicleId(rdram, ctx);
        goto after_0;
    // 0x800FEDD0: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    after_0:
    // 0x800FEDD4: bnel        $v0, $zero, L_800FEDF4
    if (ctx->r2 != 0) {
        // 0x800FEDD8: swc1        $f20, 0x24($s0)
        MEM_W(0X24, ctx->r16) = ctx->f20.u32l;
            goto L_800FEDF4;
    }
    goto skip_0;
    // 0x800FEDD8: swc1        $f20, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f20.u32l;
    skip_0:
    // 0x800FEDDC: jal         0x800B585C
    // 0x800FEDE0: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    func_800B585C(rdram, ctx);
        goto after_1;
    // 0x800FEDE0: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    after_1:
    // 0x800FEDE4: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x800FEDE8: bnel        $v0, $zero, L_800FEDF4
    if (ctx->r2 != 0) {
        // 0x800FEDEC: swc1        $f20, 0x24($s0)
        MEM_W(0X24, ctx->r16) = ctx->f20.u32l;
            goto L_800FEDF4;
    }
    goto skip_1;
    // 0x800FEDEC: swc1        $f20, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f20.u32l;
    skip_1:
    // 0x800FEDF0: sw          $zero, 0x24($s0)
    MEM_W(0X24, ctx->r16) = 0;
L_800FEDF4:
    // 0x800FEDF4: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x800FEDF8: andi        $v0, $s1, 0xFF
    ctx->r2 = ctx->r17 & 0XFF;
    // 0x800FEDFC: sltiu       $v0, $v0, 0x2
    ctx->r2 = ctx->r2 < 0X2 ? 1 : 0;
    // 0x800FEE00: bne         $v0, $zero, L_800FED7C
    if (ctx->r2 != 0) {
        // 0x800FEE04: andi        $v1, $s1, 0xFF
        ctx->r3 = ctx->r17 & 0XFF;
            goto L_800FED7C;
    }
    // 0x800FEE04: andi        $v1, $s1, 0xFF
    ctx->r3 = ctx->r17 & 0XFF;
    // 0x800FEE08: lw          $ra, 0x20($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X20);
    // 0x800FEE0C: lw          $s3, 0x1C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X1C);
    // 0x800FEE10: lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X18);
    // 0x800FEE14: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x800FEE18: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x800FEE1C: ldc1        $f20, 0x28($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X28);
    // 0x800FEE20: jr          $ra
    // 0x800FEE24: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x800FEE24: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_800FEE28(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800FEE28: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x800FEE2C: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800FEE30: addiu       $a1, $v0, -0x35D0
    ctx->r5 = ADD32(ctx->r2, -0X35D0);
    // 0x800FEE34: andi        $v1, $a0, 0xFF
    ctx->r3 = ctx->r4 & 0XFF;
L_800FEE38:
    // 0x800FEE38: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x800FEE3C: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800FEE40: sll         $v0, $v0, 4
    ctx->r2 = S32(ctx->r2 << 4);
    // 0x800FEE44: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x800FEE48: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x800FEE4C: addu        $v0, $v0, $a1
    ctx->r2 = ADD32(ctx->r2, ctx->r5);
    // 0x800FEE50: lbu         $v1, 0x3($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X3);
    // 0x800FEE54: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x800FEE58: sb          $v1, 0x2($v0)
    MEM_B(0X2, ctx->r2) = ctx->r3;
    // 0x800FEE5C: andi        $v0, $a0, 0xFF
    ctx->r2 = ctx->r4 & 0XFF;
    // 0x800FEE60: sltiu       $v0, $v0, 0x2
    ctx->r2 = ctx->r2 < 0X2 ? 1 : 0;
    // 0x800FEE64: bne         $v0, $zero, L_800FEE38
    if (ctx->r2 != 0) {
        // 0x800FEE68: andi        $v1, $a0, 0xFF
        ctx->r3 = ctx->r4 & 0XFF;
            goto L_800FEE38;
    }
    // 0x800FEE68: andi        $v1, $a0, 0xFF
    ctx->r3 = ctx->r4 & 0XFF;
    // 0x800FEE6C: jr          $ra
    // 0x800FEE70: nop

    return;
    // 0x800FEE70: nop

;}
RECOMP_FUNC void func_800FEE74(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800FEE74: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800FEE78: addiu       $a1, $v0, -0x35D0
    ctx->r5 = ADD32(ctx->r2, -0X35D0);
    // 0x800FEE7C: lbu         $v1, -0x35D0($v0)
    ctx->r3 = MEM_BU(ctx->r2, -0X35D0);
    // 0x800FEE80: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // 0x800FEE84: bne         $v1, $v0, L_800FEEC4
    if (ctx->r3 != ctx->r2) {
        // 0x800FEE88: nop
    
            goto L_800FEEC4;
    }
    // 0x800FEE88: nop

    // 0x800FEE8C: lbu         $v0, 0x1($a1)
    ctx->r2 = MEM_BU(ctx->r5, 0X1);
    // 0x800FEE90: beq         $v0, $zero, L_800FEEC4
    if (ctx->r2 == 0) {
        // 0x800FEE94: nop
    
            goto L_800FEEC4;
    }
    // 0x800FEE94: nop

    // 0x800FEE98: lbu         $v0, 0x228($a1)
    ctx->r2 = MEM_BU(ctx->r5, 0X228);
    // 0x800FEE9C: beq         $v0, $zero, L_800FEEC4
    if (ctx->r2 == 0) {
        // 0x800FEEA0: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_800FEEC4;
    }
    // 0x800FEEA0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800FEEA4: lw          $a2, 0x21C($a1)
    ctx->r6 = MEM_W(ctx->r5, 0X21C);
    // 0x800FEEA8: lw          $a3, 0x220($a1)
    ctx->r7 = MEM_W(ctx->r5, 0X220);
    // 0x800FEEAC: lw          $t0, 0x224($a1)
    ctx->r8 = MEM_W(ctx->r5, 0X224);
    // 0x800FEEB0: sw          $a2, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r6;
    // 0x800FEEB4: sw          $a3, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r7;
    // 0x800FEEB8: sw          $t0, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r8;
    // 0x800FEEBC: jr          $ra
    // 0x800FEEC0: nop

    return;
    // 0x800FEEC0: nop

L_800FEEC4:
    // 0x800FEEC4: jr          $ra
    // 0x800FEEC8: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    return;
    // 0x800FEEC8: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
;}
RECOMP_FUNC void func_800FEECC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800FEECC: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800FEED0: addiu       $a1, $v0, -0x35D0
    ctx->r5 = ADD32(ctx->r2, -0X35D0);
    // 0x800FEED4: lbu         $v1, -0x35D0($v0)
    ctx->r3 = MEM_BU(ctx->r2, -0X35D0);
    // 0x800FEED8: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // 0x800FEEDC: bne         $v1, $v0, L_800FEEEC
    if (ctx->r3 != ctx->r2) {
        // 0x800FEEE0: addu        $a0, $zero, $zero
        ctx->r4 = ADD32(0, 0);
            goto L_800FEEEC;
    }
    // 0x800FEEE0: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x800FEEE4: lbu         $v0, 0x1($a1)
    ctx->r2 = MEM_BU(ctx->r5, 0X1);
    // 0x800FEEE8: sltu        $a0, $a0, $v0
    ctx->r4 = ctx->r4 < ctx->r2 ? 1 : 0;
L_800FEEEC:
    // 0x800FEEEC: jr          $ra
    // 0x800FEEF0: addu        $v0, $a0, $zero
    ctx->r2 = ADD32(ctx->r4, 0);
    return;
    // 0x800FEEF0: addu        $v0, $a0, $zero
    ctx->r2 = ADD32(ctx->r4, 0);
;}
RECOMP_FUNC void getHudSecondaryWeponCount(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800FEEF4: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800FEEF8: lbu         $v0, -0x35CE($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X35CE);
    // 0x800FEEFC: jr          $ra
    // 0x800FEF00: nop

    return;
    // 0x800FEF00: nop

;}
RECOMP_FUNC void fake_func_800FEF04(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
;}
RECOMP_FUNC void func_800FEF10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800FEF10: addiu       $sp, $sp, -0x4F8
    ctx->r29 = ADD32(ctx->r29, -0X4F8);
    // 0x800FEF14: sdc1        $f24, 0x4E0($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X4E0, ctx->r29);
    // 0x800FEF18: mtc1        $a1, $f24
    ctx->f24.u32l = ctx->r5;
    // 0x800FEF1C: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x800FEF20: sw          $ra, 0x4CC($sp)
    MEM_W(0X4CC, ctx->r29) = ctx->r31;
    // 0x800FEF24: sw          $fp, 0x4C8($sp)
    MEM_W(0X4C8, ctx->r29) = ctx->r30;
    // 0x800FEF28: sw          $s7, 0x4C4($sp)
    MEM_W(0X4C4, ctx->r29) = ctx->r23;
    // 0x800FEF2C: sw          $s6, 0x4C0($sp)
    MEM_W(0X4C0, ctx->r29) = ctx->r22;
    // 0x800FEF30: sw          $s5, 0x4BC($sp)
    MEM_W(0X4BC, ctx->r29) = ctx->r21;
    // 0x800FEF34: sw          $s4, 0x4B8($sp)
    MEM_W(0X4B8, ctx->r29) = ctx->r20;
    // 0x800FEF38: sw          $s3, 0x4B4($sp)
    MEM_W(0X4B4, ctx->r29) = ctx->r19;
    // 0x800FEF3C: sw          $s2, 0x4B0($sp)
    MEM_W(0X4B0, ctx->r29) = ctx->r18;
    // 0x800FEF40: sw          $s1, 0x4AC($sp)
    MEM_W(0X4AC, ctx->r29) = ctx->r17;
    // 0x800FEF44: sw          $s0, 0x4A8($sp)
    MEM_W(0X4A8, ctx->r29) = ctx->r16;
    // 0x800FEF48: sdc1        $f28, 0x4F0($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0X4F0, ctx->r29);
    // 0x800FEF4C: sdc1        $f26, 0x4E8($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X4E8, ctx->r29);
    // 0x800FEF50: sdc1        $f22, 0x4D8($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X4D8, ctx->r29);
    // 0x800FEF54: sdc1        $f20, 0x4D0($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X4D0, ctx->r29);
    // 0x800FEF58: sw          $a0, 0x4F8($sp)
    MEM_W(0X4F8, ctx->r29) = ctx->r4;
    // 0x800FEF5C: sw          $a2, 0x500($sp)
    MEM_W(0X500, ctx->r29) = ctx->r6;
    // 0x800FEF60: sw          $a3, 0x504($sp)
    MEM_W(0X504, ctx->r29) = ctx->r7;
    // 0x800FEF64: c.eq.s      $f24, $f6
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f24.fl == ctx->f6.fl;
    // 0x800FEF68: nop

    // 0x800FEF6C: bc1t        L_800FFDB4
    if (c1cs) {
        // 0x800FEF70: sb          $zero, 0x497($sp)
        MEM_B(0X497, ctx->r29) = 0;
            goto L_800FFDB4;
    }
    // 0x800FEF70: sb          $zero, 0x497($sp)
    MEM_B(0X497, ctx->r29) = 0;
    // 0x800FEF74: lwc1        $f0, 0x28($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X28);
    // 0x800FEF78: mul.s       $f0, $f0, $f24
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f24.fl);
    // 0x800FEF7C: addu        $t0, $a0, $zero
    ctx->r8 = ADD32(ctx->r4, 0);
    // 0x800FEF80: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    // 0x800FEF84: lwc1        $f2, 0x2C($t0)
    ctx->f2.u32l = MEM_W(ctx->r8, 0X2C);
    // 0x800FEF88: mul.s       $f4, $f2, $f24
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f4.fl = MUL_S(ctx->f2.fl, ctx->f24.fl);
    // 0x800FEF8C: swc1        $f4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f4.u32l;
    // 0x800FEF90: lwc1        $f2, 0x30($t0)
    ctx->f2.u32l = MEM_W(ctx->r8, 0X30);
    // 0x800FEF94: mul.s       $f2, $f2, $f24
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f24.fl);
    // 0x800FEF98: c.eq.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl == ctx->f6.fl;
    // 0x800FEF9C: nop

    // 0x800FEFA0: bc1f        L_800FEFC8
    if (!c1cs) {
        // 0x800FEFA4: swc1        $f2, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->f2.u32l;
            goto L_800FEFC8;
    }
    // 0x800FEFA4: swc1        $f2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f2.u32l;
    // 0x800FEFA8: c.eq.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl == ctx->f6.fl;
    // 0x800FEFAC: nop

    // 0x800FEFB0: bc1f        L_800FEFC8
    if (!c1cs) {
        // 0x800FEFB4: nop
    
            goto L_800FEFC8;
    }
    // 0x800FEFB4: nop

    // 0x800FEFB8: c.eq.s      $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f2.fl == ctx->f6.fl;
    // 0x800FEFBC: nop

    // 0x800FEFC0: bc1t        L_800FFA54
    if (c1cs) {
        // 0x800FEFC4: nop
    
            goto L_800FFA54;
    }
    // 0x800FEFC4: nop

L_800FEFC8:
    // 0x800FEFC8: lw          $t1, 0x4F8($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X4F8);
    // 0x800FEFCC: lw          $v0, 0xB8($t1)
    ctx->r2 = MEM_W(ctx->r9, 0XB8);
    // 0x800FEFD0: sw          $zero, 0x48C($sp)
    MEM_W(0X48C, ctx->r29) = 0;
    // 0x800FEFD4: sll         $v1, $v0, 2
    ctx->r3 = S32(ctx->r2 << 2);
    // 0x800FEFD8: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x800FEFDC: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x800FEFE0: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x800FEFE4: sll         $v1, $v1, 5
    ctx->r3 = S32(ctx->r3 << 5);
    // 0x800FEFE8: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x800FEFEC: addiu       $v0, $v0, -0x7FF4
    ctx->r2 = ADD32(ctx->r2, -0X7FF4);
    // 0x800FEFF0: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x800FEFF4: sw          $v1, 0x498($sp)
    MEM_W(0X498, ctx->r29) = ctx->r3;
L_800FEFF8:
    // 0x800FEFF8: lw          $t2, 0x4F8($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X4F8);
    // 0x800FEFFC: addiu       $v1, $sp, 0x78
    ctx->r3 = ADD32(ctx->r29, 0X78);
    // 0x800FF000: addiu       $v0, $t2, 0x4
    ctx->r2 = ADD32(ctx->r10, 0X4);
    // 0x800FF004: addiu       $a0, $t2, 0x34
    ctx->r4 = ADD32(ctx->r10, 0X34);
L_800FF008:
    // 0x800FF008: lw          $t3, 0x0($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X0);
    // 0x800FF00C: lw          $t4, 0x4($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X4);
    // 0x800FF010: lw          $t0, 0x8($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X8);
    // 0x800FF014: lw          $t1, 0xC($v0)
    ctx->r9 = MEM_W(ctx->r2, 0XC);
    // 0x800FF018: sw          $t3, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r11;
    // 0x800FF01C: sw          $t4, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r12;
    // 0x800FF020: sw          $t0, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r8;
    // 0x800FF024: sw          $t1, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r9;
    // 0x800FF028: addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
    // 0x800FF02C: bne         $v0, $a0, L_800FF008
    if (ctx->r2 != ctx->r4) {
        // 0x800FF030: addiu       $v1, $v1, 0x10
        ctx->r3 = ADD32(ctx->r3, 0X10);
            goto L_800FF008;
    }
    // 0x800FF030: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
    // 0x800FF034: addiu       $s4, $zero, 0x1
    ctx->r20 = ADD32(0, 0X1);
    // 0x800FF038: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800FF03C: addiu       $s2, $v0, -0x4B10
    ctx->r18 = ADD32(ctx->r2, -0X4B10);
    // 0x800FF040: addiu       $s1, $sp, 0xA8
    ctx->r17 = ADD32(ctx->r29, 0XA8);
    // 0x800FF044: addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
    // 0x800FF048: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
L_800FF04C:
    // 0x800FF04C: addu        $a3, $s1, $zero
    ctx->r7 = ADD32(ctx->r17, 0);
    // 0x800FF050: addiu       $s1, $s1, 0x30
    ctx->r17 = ADD32(ctx->r17, 0X30);
    // 0x800FF054: addu        $v0, $s0, $s2
    ctx->r2 = ADD32(ctx->r16, ctx->r18);
    // 0x800FF058: lw          $t2, 0x4F8($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X4F8);
    // 0x800FF05C: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x800FF060: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x800FF064: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x800FF068: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    // 0x800FF06C: lw          $a0, 0x0($t2)
    ctx->r4 = MEM_W(ctx->r10, 0X0);
    // 0x800FF070: jal         0x80058360
    // 0x800FF074: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    func_80058360(rdram, ctx);
        goto after_0;
    // 0x800FF074: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    after_0:
    // 0x800FF078: sltiu       $v0, $s4, 0x6
    ctx->r2 = ctx->r20 < 0X6 ? 1 : 0;
    // 0x800FF07C: bne         $v0, $zero, L_800FF04C
    if (ctx->r2 != 0) {
        // 0x800FF080: addu        $a2, $zero, $zero
        ctx->r6 = ADD32(0, 0);
            goto L_800FF04C;
    }
    // 0x800FF080: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // 0x800FF084: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x800FF088: lw          $v0, -0x72E4($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X72E4);
    // 0x800FF08C: lhu         $v1, 0x4($v0)
    ctx->r3 = MEM_HU(ctx->r2, 0X4);
    // 0x800FF090: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x800FF094: bne         $v1, $v0, L_800FF1A0
    if (ctx->r3 != ctx->r2) {
        // 0x800FF098: addu        $s7, $zero, $zero
        ctx->r23 = ADD32(0, 0);
            goto L_800FF1A0;
    }
    // 0x800FF098: addu        $s7, $zero, $zero
    ctx->r23 = ADD32(0, 0);
    // 0x800FF09C: lw          $t3, 0x4F8($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X4F8);
    // 0x800FF0A0: lhu         $v0, 0xB4($t3)
    ctx->r2 = MEM_HU(ctx->r11, 0XB4);
    // 0x800FF0A4: beq         $v0, $zero, L_800FF0BC
    if (ctx->r2 == 0) {
        // 0x800FF0A8: nop
    
            goto L_800FF0BC;
    }
    // 0x800FF0A8: nop

    // 0x800FF0AC: beq         $v0, $v1, L_800FF0D0
    if (ctx->r2 == ctx->r3) {
        // 0x800FF0B0: nop
    
            goto L_800FF0D0;
    }
    // 0x800FF0B0: nop

    // 0x800FF0B4: j           L_800FF0EC
    // 0x800FF0B8: nop

        goto L_800FF0EC;
    // 0x800FF0B8: nop

L_800FF0BC:
    // 0x800FF0BC: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800FF0C0: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800FF0C4: lwc1        $f2, -0x6BBC($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X6BBC);
    // 0x800FF0C8: j           L_800FF0E0
    // 0x800FF0CC: swc1        $f0, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->f0.u32l;
        goto L_800FF0E0;
    // 0x800FF0CC: swc1        $f0, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->f0.u32l;
L_800FF0D0:
    // 0x800FF0D0: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800FF0D4: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800FF0D8: lwc1        $f2, -0x6BB8($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X6BB8);
    // 0x800FF0DC: swc1        $f0, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->f0.u32l;
L_800FF0E0:
    // 0x800FF0E0: swc1        $f0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f0.u32l;
    // 0x800FF0E4: j           L_800FF0FC
    // 0x800FF0E8: swc1        $f2, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->f2.u32l;
        goto L_800FF0FC;
    // 0x800FF0E8: swc1        $f2, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->f2.u32l;
L_800FF0EC:
    // 0x800FF0EC: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800FF0F0: swc1        $f0, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->f0.u32l;
    // 0x800FF0F4: swc1        $f0, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->f0.u32l;
    // 0x800FF0F8: swc1        $f0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f0.u32l;
L_800FF0FC:
    // 0x800FF0FC: addiu       $a0, $sp, 0x58
    ctx->r4 = ADD32(ctx->r29, 0X58);
    // 0x800FF100: addiu       $a1, $sp, 0x180
    ctx->r5 = ADD32(ctx->r29, 0X180);
    // 0x800FF104: jal         0x80019548
    // 0x800FF108: addiu       $a2, $sp, 0x174
    ctx->r6 = ADD32(ctx->r29, 0X174);
    func_80019548(rdram, ctx);
        goto after_1;
    // 0x800FF108: addiu       $a2, $sp, 0x174
    ctx->r6 = ADD32(ctx->r29, 0X174);
    after_1:
    // 0x800FF10C: lwc1        $f4, 0x58($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X58);
    // 0x800FF110: lwc1        $f8, 0x68($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X68);
    // 0x800FF114: mul.s       $f4, $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = MUL_S(ctx->f4.fl, ctx->f8.fl);
    // 0x800FF118: lwc1        $f18, 0x180($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X180);
    // 0x800FF11C: lwc1        $f10, 0x6C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x800FF120: mul.s       $f18, $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = MUL_S(ctx->f18.fl, ctx->f10.fl);
    // 0x800FF124: lwc1        $f16, 0x174($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X174);
    // 0x800FF128: lwc1        $f12, 0x70($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X70);
    // 0x800FF12C: mul.s       $f16, $f16, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f16.fl = MUL_S(ctx->f16.fl, ctx->f12.fl);
    // 0x800FF130: lwc1        $f0, 0x5C($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x800FF134: mul.s       $f0, $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x800FF138: lwc1        $f6, 0x184($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X184);
    // 0x800FF13C: mul.s       $f6, $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x800FF140: lwc1        $f14, 0x178($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X178);
    // 0x800FF144: mul.s       $f14, $f14, $f12
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f14.fl = MUL_S(ctx->f14.fl, ctx->f12.fl);
    // 0x800FF148: lwc1        $f2, 0x60($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X60);
    // 0x800FF14C: mul.s       $f2, $f2, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f8.fl);
    // 0x800FF150: lwc1        $f8, 0x188($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X188);
    // 0x800FF154: mul.s       $f8, $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x800FF158: lwc1        $f10, 0x17C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X17C);
    // 0x800FF15C: mul.s       $f10, $f10, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = MUL_S(ctx->f10.fl, ctx->f12.fl);
    // 0x800FF160: add.s       $f4, $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f18.fl;
    // 0x800FF164: add.s       $f0, $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f6.fl;
    // 0x800FF168: add.s       $f2, $f2, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f8.fl;
    // 0x800FF16C: add.s       $f4, $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f16.fl;
    // 0x800FF170: add.s       $f0, $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f14.fl;
    // 0x800FF174: add.s       $f2, $f2, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f10.fl;
    // 0x800FF178: lwc1        $f6, 0x168($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X168);
    // 0x800FF17C: add.s       $f6, $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f4.fl;
    // 0x800FF180: lwc1        $f4, 0x16C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X16C);
    // 0x800FF184: add.s       $f4, $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f0.fl;
    // 0x800FF188: lwc1        $f0, 0x170($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X170);
    // 0x800FF18C: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x800FF190: swc1        $f6, 0x168($sp)
    MEM_W(0X168, ctx->r29) = ctx->f6.u32l;
    // 0x800FF194: swc1        $f4, 0x16C($sp)
    MEM_W(0X16C, ctx->r29) = ctx->f4.u32l;
    // 0x800FF198: swc1        $f0, 0x170($sp)
    MEM_W(0X170, ctx->r29) = ctx->f0.u32l;
    // 0x800FF19C: addu        $s7, $zero, $zero
    ctx->r23 = ADD32(0, 0);
L_800FF1A0:
    // 0x800FF1A0: addu        $s4, $s7, $zero
    ctx->r20 = ADD32(ctx->r23, 0);
    // 0x800FF1A4: addiu       $t4, $sp, 0x468
    ctx->r12 = ADD32(ctx->r29, 0X468);
    // 0x800FF1A8: addiu       $t0, $sp, 0x18
    ctx->r8 = ADD32(ctx->r29, 0X18);
    // 0x800FF1AC: addu        $fp, $s7, $zero
    ctx->r30 = ADD32(ctx->r23, 0);
    // 0x800FF1B0: sw          $t4, 0x49C($sp)
    MEM_W(0X49C, ctx->r29) = ctx->r12;
    // 0x800FF1B4: sw          $t0, 0x4A0($sp)
    MEM_W(0X4A0, ctx->r29) = ctx->r8;
    // 0x800FF1B8: sw          $zero, 0x4A4($sp)
    MEM_W(0X4A4, ctx->r29) = 0;
L_800FF1BC:
    // 0x800FF1BC: lui         $t1, 0x8011
    ctx->r9 = S32(0X8011 << 16);
    // 0x800FF1C0: lhu         $v0, -0x4B14($t1)
    ctx->r2 = MEM_HU(ctx->r9, -0X4B14);
    // 0x800FF1C4: ori         $t2, $zero, 0xFFFF
    ctx->r10 = 0 | 0XFFFF;
    // 0x800FF1C8: beq         $v0, $t2, L_800FF354
    if (ctx->r2 == ctx->r10) {
        // 0x800FF1CC: addu        $s2, $zero, $zero
        ctx->r18 = ADD32(0, 0);
            goto L_800FF354;
    }
    // 0x800FF1CC: addu        $s2, $zero, $zero
    ctx->r18 = ADD32(0, 0);
    // 0x800FF1D0: lw          $t3, 0x4A4($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X4A4);
    // 0x800FF1D4: lw          $t4, 0x4A0($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X4A0);
    // 0x800FF1D8: lui         $s3, 0x8011
    ctx->r19 = S32(0X8011 << 16);
    // 0x800FF1DC: addiu       $s3, $s3, -0x4B14
    ctx->r19 = ADD32(ctx->r19, -0X4B14);
    // 0x800FF1E0: addu        $s5, $t3, $t4
    ctx->r21 = ADD32(ctx->r11, ctx->r12);
    // 0x800FF1E4: addiu       $s5, $s5, 0x60
    ctx->r21 = ADD32(ctx->r21, 0X60);
L_800FF1E8:
    // 0x800FF1E8: lui         $t0, 0x8014
    ctx->r8 = S32(0X8014 << 16);
    // 0x800FF1EC: addiu       $t0, $t0, -0x6AA0
    ctx->r8 = ADD32(ctx->r8, -0X6AA0);
    // 0x800FF1F0: lhu         $v0, 0x0($s3)
    ctx->r2 = MEM_HU(ctx->r19, 0X0);
    // 0x800FF1F4: lw          $a1, 0x49C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X49C);
    // 0x800FF1F8: lw          $t1, 0x4F8($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X4F8);
    // 0x800FF1FC: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x800FF200: addu        $v0, $v0, $t0
    ctx->r2 = ADD32(ctx->r2, ctx->r8);
    // 0x800FF204: lhu         $a0, 0x0($v0)
    ctx->r4 = MEM_HU(ctx->r2, 0X0);
    // 0x800FF208: lhu         $s0, 0xB6($t1)
    ctx->r16 = MEM_HU(ctx->r9, 0XB6);
    // 0x800FF20C: jal         0x8003FC28
    // 0x800FF210: nop

    func_8003FC28(rdram, ctx);
        goto after_2;
    // 0x800FF210: nop

    after_2:
    // 0x800FF214: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // 0x800FF218: andi        $v0, $a0, 0xFFFF
    ctx->r2 = ctx->r4 & 0XFFFF;
    // 0x800FF21C: ori         $t2, $zero, 0xFFFF
    ctx->r10 = 0 | 0XFFFF;
    // 0x800FF220: beq         $v0, $t2, L_800FF2B0
    if (ctx->r2 == ctx->r10) {
        // 0x800FF224: ori         $v1, $zero, 0xFFFF
        ctx->r3 = 0 | 0XFFFF;
            goto L_800FF2B0;
    }
    // 0x800FF224: ori         $v1, $zero, 0xFFFF
    ctx->r3 = 0 | 0XFFFF;
    // 0x800FF228: andi        $s6, $s0, 0xFFFF
    ctx->r22 = ctx->r16 & 0XFFFF;
    // 0x800FF22C: andi        $s0, $a0, 0xFFFF
    ctx->r16 = ctx->r4 & 0XFFFF;
L_800FF230:
    // 0x800FF230: beq         $s6, $s0, L_800FF290
    if (ctx->r22 == ctx->r16) {
        // 0x800FF234: nop
    
            goto L_800FF290;
    }
    // 0x800FF234: nop

    // 0x800FF238: jal         0x8004013C
    // 0x800FF23C: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_8004013C(rdram, ctx);
        goto after_3;
    // 0x800FF23C: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_3:
    // 0x800FF240: addu        $s1, $v0, $zero
    ctx->r17 = ADD32(ctx->r2, 0);
    // 0x800FF244: lw          $v0, 0xC($s1)
    ctx->r2 = MEM_W(ctx->r17, 0XC);
    // 0x800FF248: beq         $v0, $zero, L_800FF290
    if (ctx->r2 == 0) {
        // 0x800FF24C: addu        $a0, $s0, $zero
        ctx->r4 = ADD32(ctx->r16, 0);
            goto L_800FF290;
    }
    // 0x800FF24C: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x800FF250: addiu       $a1, $zero, 0xB
    ctx->r5 = ADD32(0, 0XB);
    // 0x800FF254: addiu       $a2, $sp, 0x470
    ctx->r6 = ADD32(ctx->r29, 0X470);
    // 0x800FF258: lw          $t3, 0x49C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X49C);
    // 0x800FF25C: addiu       $t4, $zero, -0x1
    ctx->r12 = ADD32(0, -0X1);
    // 0x800FF260: jal         0x8003E8DC
    // 0x800FF264: sh          $t4, 0xA($t3)
    MEM_H(0XA, ctx->r11) = ctx->r12;
    slotDispatcherIter(rdram, ctx);
        goto after_4;
    // 0x800FF264: sh          $t4, 0xA($t3)
    MEM_H(0XA, ctx->r11) = ctx->r12;
    after_4:
    // 0x800FF268: lh          $v0, 0x472($sp)
    ctx->r2 = MEM_H(ctx->r29, 0X472);
    // 0x800FF26C: slti        $v0, $v0, 0x1000
    ctx->r2 = SIGNED(ctx->r2) < 0X1000 ? 1 : 0;
    // 0x800FF270: beq         $v0, $zero, L_800FF290
    if (ctx->r2 == 0) {
        // 0x800FF274: addu        $a1, $s5, $zero
        ctx->r5 = ADD32(ctx->r21, 0);
            goto L_800FF290;
    }
    // 0x800FF274: addu        $a1, $s5, $zero
    ctx->r5 = ADD32(ctx->r21, 0);
    // 0x800FF278: lw          $a0, 0xC($s1)
    ctx->r4 = MEM_W(ctx->r17, 0XC);
    // 0x800FF27C: lw          $a2, 0x4A0($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X4A0);
    // 0x800FF280: jal         0x8006A944
    // 0x800FF284: addiu       $a3, $sp, 0x440
    ctx->r7 = ADD32(ctx->r29, 0X440);
    func_8006A944(rdram, ctx);
        goto after_5;
    // 0x800FF284: addiu       $a3, $sp, 0x440
    ctx->r7 = ADD32(ctx->r29, 0X440);
    after_5:
    // 0x800FF288: bne         $v0, $zero, L_800FF2B0
    if (ctx->r2 != 0) {
        // 0x800FF28C: addu        $v1, $s0, $zero
        ctx->r3 = ADD32(ctx->r16, 0);
            goto L_800FF2B0;
    }
    // 0x800FF28C: addu        $v1, $s0, $zero
    ctx->r3 = ADD32(ctx->r16, 0);
L_800FF290:
    // 0x800FF290: jal         0x8003EEF4
    // 0x800FF294: addiu       $a0, $sp, 0x468
    ctx->r4 = ADD32(ctx->r29, 0X468);
    func_8003EEF4(rdram, ctx);
        goto after_6;
    // 0x800FF294: addiu       $a0, $sp, 0x468
    ctx->r4 = ADD32(ctx->r29, 0X468);
    after_6:
    // 0x800FF298: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // 0x800FF29C: andi        $v0, $a0, 0xFFFF
    ctx->r2 = ctx->r4 & 0XFFFF;
    // 0x800FF2A0: ori         $t0, $zero, 0xFFFF
    ctx->r8 = 0 | 0XFFFF;
    // 0x800FF2A4: bne         $v0, $t0, L_800FF230
    if (ctx->r2 != ctx->r8) {
        // 0x800FF2A8: andi        $s0, $a0, 0xFFFF
        ctx->r16 = ctx->r4 & 0XFFFF;
            goto L_800FF230;
    }
    // 0x800FF2A8: andi        $s0, $a0, 0xFFFF
    ctx->r16 = ctx->r4 & 0XFFFF;
    // 0x800FF2AC: ori         $v1, $zero, 0xFFFF
    ctx->r3 = 0 | 0XFFFF;
L_800FF2B0:
    // 0x800FF2B0: ori         $t1, $zero, 0xFFFF
    ctx->r9 = 0 | 0XFFFF;
    // 0x800FF2B4: bne         $v1, $t1, L_800FF2D0
    if (ctx->r3 != ctx->r9) {
        // 0x800FF2B8: sll         $v0, $s2, 1
        ctx->r2 = S32(ctx->r18 << 1);
            goto L_800FF2D0;
    }
    // 0x800FF2B8: sll         $v0, $s2, 1
    ctx->r2 = S32(ctx->r18 << 1);
    // 0x800FF2BC: addiu       $s3, $s3, 0x2
    ctx->r19 = ADD32(ctx->r19, 0X2);
    // 0x800FF2C0: lhu         $v0, 0x0($s3)
    ctx->r2 = MEM_HU(ctx->r19, 0X0);
    // 0x800FF2C4: bne         $v0, $t1, L_800FF1E8
    if (ctx->r2 != ctx->r9) {
        // 0x800FF2C8: addiu       $s2, $s2, 0x1
        ctx->r18 = ADD32(ctx->r18, 0X1);
            goto L_800FF1E8;
    }
    // 0x800FF2C8: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x800FF2CC: sll         $v0, $s2, 1
    ctx->r2 = S32(ctx->r18 << 1);
L_800FF2D0:
    // 0x800FF2D0: lui         $t2, 0x8011
    ctx->r10 = S32(0X8011 << 16);
    // 0x800FF2D4: addiu       $t2, $t2, -0x4B14
    ctx->r10 = ADD32(ctx->r10, -0X4B14);
    // 0x800FF2D8: addu        $v0, $v0, $t2
    ctx->r2 = ADD32(ctx->r2, ctx->r10);
    // 0x800FF2DC: lhu         $v0, 0x0($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X0);
    // 0x800FF2E0: ori         $t3, $zero, 0xFFFF
    ctx->r11 = 0 | 0XFFFF;
    // 0x800FF2E4: beq         $v0, $t3, L_800FF354
    if (ctx->r2 == ctx->r11) {
        // 0x800FF2E8: addiu       $v0, $sp, 0x198
        ctx->r2 = ADD32(ctx->r29, 0X198);
            goto L_800FF354;
    }
    // 0x800FF2E8: addiu       $v0, $sp, 0x198
    ctx->r2 = ADD32(ctx->r29, 0X198);
    // 0x800FF2EC: addu        $v0, $v0, $fp
    ctx->r2 = ADD32(ctx->r2, ctx->r30);
    // 0x800FF2F0: sh          $v1, 0x2($v0)
    MEM_H(0X2, ctx->r2) = ctx->r3;
    // 0x800FF2F4: addiu       $a0, $v0, 0x4
    ctx->r4 = ADD32(ctx->r2, 0X4);
    // 0x800FF2F8: addiu       $v1, $sp, 0x440
    ctx->r3 = ADD32(ctx->r29, 0X440);
    // 0x800FF2FC: addiu       $v0, $sp, 0x460
    ctx->r2 = ADD32(ctx->r29, 0X460);
L_800FF300:
    // 0x800FF300: lw          $t4, 0x0($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X0);
    // 0x800FF304: lw          $t0, 0x4($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X4);
    // 0x800FF308: lw          $t1, 0x8($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X8);
    // 0x800FF30C: lw          $t2, 0xC($v1)
    ctx->r10 = MEM_W(ctx->r3, 0XC);
    // 0x800FF310: sw          $t4, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r12;
    // 0x800FF314: sw          $t0, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r8;
    // 0x800FF318: sw          $t1, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r9;
    // 0x800FF31C: sw          $t2, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r10;
    // 0x800FF320: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
    // 0x800FF324: bne         $v1, $v0, L_800FF300
    if (ctx->r3 != ctx->r2) {
        // 0x800FF328: addiu       $a0, $a0, 0x10
        ctx->r4 = ADD32(ctx->r4, 0X10);
            goto L_800FF300;
    }
    // 0x800FF328: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    // 0x800FF32C: addiu       $v0, $sp, 0x198
    ctx->r2 = ADD32(ctx->r29, 0X198);
    // 0x800FF330: addu        $v0, $v0, $fp
    ctx->r2 = ADD32(ctx->r2, ctx->r30);
    // 0x800FF334: addiu       $fp, $fp, 0x2C
    ctx->r30 = ADD32(ctx->r30, 0X2C);
    // 0x800FF338: addiu       $s7, $s7, 0x1
    ctx->r23 = ADD32(ctx->r23, 0X1);
    // 0x800FF33C: lw          $t3, 0x0($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X0);
    // 0x800FF340: lw          $t4, 0x4($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X4);
    // 0x800FF344: sw          $t3, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r11;
    // 0x800FF348: sw          $t4, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r12;
    // 0x800FF34C: sb          $zero, 0x0($v0)
    MEM_B(0X0, ctx->r2) = 0;
    // 0x800FF350: sb          $s4, 0x1($v0)
    MEM_B(0X1, ctx->r2) = ctx->r20;
L_800FF354:
    // 0x800FF354: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    // 0x800FF358: lw          $t2, 0x4A4($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X4A4);
    // 0x800FF35C: sltiu       $v0, $s4, 0x6
    ctx->r2 = ctx->r20 < 0X6 ? 1 : 0;
    // 0x800FF360: addiu       $t2, $t2, 0x30
    ctx->r10 = ADD32(ctx->r10, 0X30);
    // 0x800FF364: bne         $v0, $zero, L_800FF1BC
    if (ctx->r2 != 0) {
        // 0x800FF368: sw          $t2, 0x4A4($sp)
        MEM_W(0X4A4, ctx->r29) = ctx->r10;
            goto L_800FF1BC;
    }
    // 0x800FF368: sw          $t2, 0x4A4($sp)
    MEM_W(0X4A4, ctx->r29) = ctx->r10;
    // 0x800FF36C: addu        $s4, $zero, $zero
    ctx->r20 = ADD32(0, 0);
    // 0x800FF370: lui         $s3, 0x8014
    ctx->r19 = S32(0X8014 << 16);
    // 0x800FF374: addiu       $s2, $zero, 0x1
    ctx->r18 = ADD32(0, 0X1);
    // 0x800FF378: addiu       $s1, $sp, 0x78
    ctx->r17 = ADD32(ctx->r29, 0X78);
    // 0x800FF37C: addiu       $v1, $sp, 0x198
    ctx->r3 = ADD32(ctx->r29, 0X198);
    // 0x800FF380: sll         $v0, $s7, 1
    ctx->r2 = S32(ctx->r23 << 1);
    // 0x800FF384: addu        $v0, $v0, $s7
    ctx->r2 = ADD32(ctx->r2, ctx->r23);
    // 0x800FF388: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800FF38C: subu        $v0, $v0, $s7
    ctx->r2 = SUB32(ctx->r2, ctx->r23);
    // 0x800FF390: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800FF394: addu        $s0, $v0, $v1
    ctx->r16 = ADD32(ctx->r2, ctx->r3);
L_800FF398:
    // 0x800FF398: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x800FF39C: addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    // 0x800FF3A0: addiu       $a2, $s3, -0x7FA8
    ctx->r6 = ADD32(ctx->r19, -0X7FA8);
    // 0x800FF3A4: jal         0x80068D5C
    // 0x800FF3A8: addiu       $a3, $s0, 0x4
    ctx->r7 = ADD32(ctx->r16, 0X4);
    func_80068D5C(rdram, ctx);
        goto after_7;
    // 0x800FF3A8: addiu       $a3, $s0, 0x4
    ctx->r7 = ADD32(ctx->r16, 0X4);
    after_7:
    // 0x800FF3AC: beql        $v0, $zero, L_800FF3C8
    if (ctx->r2 == 0) {
        // 0x800FF3B0: addiu       $s4, $s4, 0x1
        ctx->r20 = ADD32(ctx->r20, 0X1);
            goto L_800FF3C8;
    }
    goto skip_0;
    // 0x800FF3B0: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    skip_0:
    // 0x800FF3B4: sb          $s2, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r18;
    // 0x800FF3B8: sb          $s4, 0x1($s0)
    MEM_B(0X1, ctx->r16) = ctx->r20;
    // 0x800FF3BC: addiu       $s0, $s0, 0x2C
    ctx->r16 = ADD32(ctx->r16, 0X2C);
    // 0x800FF3C0: addiu       $s7, $s7, 0x1
    ctx->r23 = ADD32(ctx->r23, 0X1);
    // 0x800FF3C4: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
L_800FF3C8:
    // 0x800FF3C8: sltiu       $v0, $s4, 0x6
    ctx->r2 = ctx->r20 < 0X6 ? 1 : 0;
    // 0x800FF3CC: bne         $v0, $zero, L_800FF398
    if (ctx->r2 != 0) {
        // 0x800FF3D0: addiu       $s1, $s1, 0x30
        ctx->r17 = ADD32(ctx->r17, 0X30);
            goto L_800FF398;
    }
    // 0x800FF3D0: addiu       $s1, $s1, 0x30
    ctx->r17 = ADD32(ctx->r17, 0X30);
    // 0x800FF3D4: beq         $s7, $zero, L_800FFA54
    if (ctx->r23 == 0) {
        // 0x800FF3D8: addiu       $s2, $zero, 0x1
        ctx->r18 = ADD32(0, 0X1);
            goto L_800FFA54;
    }
    // 0x800FF3D8: addiu       $s2, $zero, 0x1
    ctx->r18 = ADD32(0, 0X1);
    // 0x800FF3DC: sltu        $v0, $s2, $s7
    ctx->r2 = ctx->r18 < ctx->r23 ? 1 : 0;
    // 0x800FF3E0: beq         $v0, $zero, L_800FF434
    if (ctx->r2 == 0) {
        // 0x800FF3E4: sw          $zero, 0x488($sp)
        MEM_W(0X488, ctx->r29) = 0;
            goto L_800FF434;
    }
    // 0x800FF3E4: sw          $zero, 0x488($sp)
    MEM_W(0X488, ctx->r29) = 0;
    // 0x800FF3E8: addiu       $a0, $sp, 0x198
    ctx->r4 = ADD32(ctx->r29, 0X198);
    // 0x800FF3EC: addiu       $v1, $sp, 0x1C4
    ctx->r3 = ADD32(ctx->r29, 0X1C4);
L_800FF3F0:
    // 0x800FF3F0: lw          $t3, 0x488($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X488);
    // 0x800FF3F4: lwc1        $f0, 0x1C($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X1C);
    // 0x800FF3F8: sll         $v0, $t3, 1
    ctx->r2 = S32(ctx->r11 << 1);
    // 0x800FF3FC: addu        $v0, $v0, $t3
    ctx->r2 = ADD32(ctx->r2, ctx->r11);
    // 0x800FF400: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800FF404: subu        $v0, $v0, $t3
    ctx->r2 = SUB32(ctx->r2, ctx->r11);
    // 0x800FF408: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800FF40C: addu        $v0, $a0, $v0
    ctx->r2 = ADD32(ctx->r4, ctx->r2);
    // 0x800FF410: lwc1        $f2, 0x1C($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X1C);
    // 0x800FF414: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x800FF418: nop

    // 0x800FF41C: bc1tl       L_800FF424
    if (c1cs) {
        // 0x800FF420: sw          $s2, 0x488($sp)
        MEM_W(0X488, ctx->r29) = ctx->r18;
            goto L_800FF424;
    }
    goto skip_1;
    // 0x800FF420: sw          $s2, 0x488($sp)
    MEM_W(0X488, ctx->r29) = ctx->r18;
    skip_1:
L_800FF424:
    // 0x800FF424: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x800FF428: sltu        $v0, $s2, $s7
    ctx->r2 = ctx->r18 < ctx->r23 ? 1 : 0;
    // 0x800FF42C: bne         $v0, $zero, L_800FF3F0
    if (ctx->r2 != 0) {
        // 0x800FF430: addiu       $v1, $v1, 0x2C
        ctx->r3 = ADD32(ctx->r3, 0X2C);
            goto L_800FF3F0;
    }
    // 0x800FF430: addiu       $v1, $v1, 0x2C
    ctx->r3 = ADD32(ctx->r3, 0X2C);
L_800FF434:
    // 0x800FF434: lw          $t4, 0x488($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X488);
    // 0x800FF438: addiu       $v1, $sp, 0x198
    ctx->r3 = ADD32(ctx->r29, 0X198);
    // 0x800FF43C: sll         $v0, $t4, 1
    ctx->r2 = S32(ctx->r12 << 1);
    // 0x800FF440: addu        $v0, $v0, $t4
    ctx->r2 = ADD32(ctx->r2, ctx->r12);
    // 0x800FF444: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800FF448: subu        $v0, $v0, $t4
    ctx->r2 = SUB32(ctx->r2, ctx->r12);
    // 0x800FF44C: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800FF450: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x800FF454: lbu         $v1, 0x1($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X1);
    // 0x800FF458: sltiu       $v0, $v1, 0x6
    ctx->r2 = ctx->r3 < 0X6 ? 1 : 0;
    // 0x800FF45C: beq         $v0, $zero, L_800FF98C
    if (ctx->r2 == 0) {
        // 0x800FF460: lui         $v0, 0x800B
        ctx->r2 = S32(0X800B << 16);
            goto L_800FF98C;
    }
    // 0x800FF460: lui         $v0, 0x800B
    ctx->r2 = S32(0X800B << 16);
    // 0x800FF464: addiu       $v0, $v0, -0x6BB0
    ctx->r2 = ADD32(ctx->r2, -0X6BB0);
    // 0x800FF468: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x800FF46C: addu        $v1, $v1, $v0
    gpr jr_addend_800FF474 = ctx->r3;
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x800FF470: lw          $v0, 0x0($v1)
    ctx->r2 = ADD32(ctx->r3, 0X0);
    // 0x800FF474: jr          $v0
    // 0x800FF478: nop

    switch (jr_addend_800FF474 >> 2) {
        case 0: goto L_800FF610; break;
        case 1: goto L_800FF520; break;
        case 2: goto L_800FF598; break;
        case 3: goto L_800FF47C; break;
        case 4: goto L_800FF4C8; break;
        case 5: goto L_800FF610; break;
        default: switch_error(__func__, 0x800FF474, 0x800A9450);
    }
    // 0x800FF478: nop

L_800FF47C:
    // 0x800FF47C: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800FF480: lwc1        $f20, -0x6B98($at)
    ctx->f20.u32l = MEM_W(ctx->r1, -0X6B98);
    // 0x800FF484: mul.s       $f20, $f24, $f20
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f20.fl = MUL_S(ctx->f24.fl, ctx->f20.fl);
    // 0x800FF488: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x800FF48C: jal         0x8001CD6C
    // 0x800FF490: addiu       $a0, $sp, 0x3D8
    ctx->r4 = ADD32(ctx->r29, 0X3D8);
    func_8001CD6C(rdram, ctx);
        goto after_8;
    // 0x800FF490: addiu       $a0, $sp, 0x3D8
    ctx->r4 = ADD32(ctx->r29, 0X3D8);
    after_8:
    // 0x800FF494: lw          $t0, 0x504($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X504);
    // 0x800FF498: lwc1        $f0, 0x0($t0)
    ctx->f0.u32l = MEM_W(ctx->r8, 0X0);
    // 0x800FF49C: sub.s       $f0, $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f20.fl;
    // 0x800FF4A0: swc1        $f0, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->f0.u32l;
    // 0x800FF4A4: lw          $t1, 0x4F8($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X4F8);
    // 0x800FF4A8: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x800FF4AC: lwc1        $f0, 0xD8($t1)
    ctx->f0.u32l = MEM_W(ctx->r9, 0XD8);
    // 0x800FF4B0: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x800FF4B4: nop

    // 0x800FF4B8: bc1tl       L_800FF98C
    if (c1cs) {
        // 0x800FF4BC: swc1        $f2, 0xD8($t1)
        MEM_W(0XD8, ctx->r9) = ctx->f2.u32l;
            goto L_800FF98C;
    }
    goto skip_2;
    // 0x800FF4BC: swc1        $f2, 0xD8($t1)
    MEM_W(0XD8, ctx->r9) = ctx->f2.u32l;
    skip_2:
    // 0x800FF4C0: j           L_800FF98C
    // 0x800FF4C4: nop

        goto L_800FF98C;
    // 0x800FF4C4: nop

L_800FF4C8:
    // 0x800FF4C8: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800FF4CC: lwc1        $f0, -0x6B94($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X6B94);
    // 0x800FF4D0: mul.s       $f0, $f24, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = MUL_S(ctx->f24.fl, ctx->f0.fl);
    // 0x800FF4D4: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x800FF4D8: jal         0x8001CD6C
    // 0x800FF4DC: addiu       $a0, $sp, 0x3D8
    ctx->r4 = ADD32(ctx->r29, 0X3D8);
    func_8001CD6C(rdram, ctx);
        goto after_9;
    // 0x800FF4DC: addiu       $a0, $sp, 0x3D8
    ctx->r4 = ADD32(ctx->r29, 0X3D8);
    after_9:
    // 0x800FF4E0: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800FF4E4: lwc1        $f2, -0x6B90($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X6B90);
    // 0x800FF4E8: mul.s       $f2, $f24, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = MUL_S(ctx->f24.fl, ctx->f2.fl);
    // 0x800FF4EC: lw          $t2, 0x504($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X504);
    // 0x800FF4F0: lwc1        $f0, 0x0($t2)
    ctx->f0.u32l = MEM_W(ctx->r10, 0X0);
    // 0x800FF4F4: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x800FF4F8: swc1        $f0, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->f0.u32l;
    // 0x800FF4FC: lw          $t3, 0x4F8($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X4F8);
    // 0x800FF500: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x800FF504: lwc1        $f0, 0xD8($t3)
    ctx->f0.u32l = MEM_W(ctx->r11, 0XD8);
    // 0x800FF508: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x800FF50C: nop

    // 0x800FF510: bc1tl       L_800FF98C
    if (c1cs) {
        // 0x800FF514: swc1        $f2, 0xD8($t3)
        MEM_W(0XD8, ctx->r11) = ctx->f2.u32l;
            goto L_800FF98C;
    }
    goto skip_3;
    // 0x800FF514: swc1        $f2, 0xD8($t3)
    MEM_W(0XD8, ctx->r11) = ctx->f2.u32l;
    skip_3:
    // 0x800FF518: j           L_800FF98C
    // 0x800FF51C: nop

        goto L_800FF98C;
    // 0x800FF51C: nop

L_800FF520:
    // 0x800FF520: lw          $t4, 0x488($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X488);
    // 0x800FF524: sll         $v0, $t4, 1
    ctx->r2 = S32(ctx->r12 << 1);
    // 0x800FF528: addu        $v0, $v0, $t4
    ctx->r2 = ADD32(ctx->r2, ctx->r12);
    // 0x800FF52C: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800FF530: subu        $v0, $v0, $t4
    ctx->r2 = SUB32(ctx->r2, ctx->r12);
    // 0x800FF534: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800FF538: addu        $v0, $sp, $v0
    ctx->r2 = ADD32(ctx->r29, ctx->r2);
    // 0x800FF53C: lbu         $v1, 0x198($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X198);
    // 0x800FF540: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800FF544: beq         $v1, $v0, L_800FF818
    if (ctx->r3 == ctx->r2) {
        // 0x800FF548: addiu       $v1, $sp, 0x198
        ctx->r3 = ADD32(ctx->r29, 0X198);
            goto L_800FF818;
    }
    // 0x800FF548: addiu       $v1, $sp, 0x198
    ctx->r3 = ADD32(ctx->r29, 0X198);
    // 0x800FF54C: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800FF550: lwc1        $f0, -0x6B8C($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X6B8C);
    // 0x800FF554: mul.s       $f0, $f24, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = MUL_S(ctx->f24.fl, ctx->f0.fl);
    // 0x800FF558: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x800FF55C: jal         0x8001CC3C
    // 0x800FF560: addiu       $a0, $sp, 0x3D8
    ctx->r4 = ADD32(ctx->r29, 0X3D8);
    func_8001CC3C(rdram, ctx);
        goto after_10;
    // 0x800FF560: addiu       $a0, $sp, 0x3D8
    ctx->r4 = ADD32(ctx->r29, 0X3D8);
    after_10:
    // 0x800FF564: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800FF568: lwc1        $f2, -0x6B88($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X6B88);
    // 0x800FF56C: mul.s       $f2, $f24, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = MUL_S(ctx->f24.fl, ctx->f2.fl);
    // 0x800FF570: lw          $t0, 0x500($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X500);
    // 0x800FF574: lwc1        $f0, 0x0($t0)
    ctx->f0.u32l = MEM_W(ctx->r8, 0X0);
    // 0x800FF578: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x800FF57C: swc1        $f0, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->f0.u32l;
    // 0x800FF580: lw          $t1, 0x4F8($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X4F8);
    // 0x800FF584: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x800FF588: lwc1        $f0, 0xDC($t1)
    ctx->f0.u32l = MEM_W(ctx->r9, 0XDC);
    // 0x800FF58C: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x800FF590: j           L_800FF934
    // 0x800FF594: nop

        goto L_800FF934;
    // 0x800FF594: nop

L_800FF598:
    // 0x800FF598: lw          $t2, 0x488($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X488);
    // 0x800FF59C: sll         $v0, $t2, 1
    ctx->r2 = S32(ctx->r10 << 1);
    // 0x800FF5A0: addu        $v0, $v0, $t2
    ctx->r2 = ADD32(ctx->r2, ctx->r10);
    // 0x800FF5A4: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800FF5A8: subu        $v0, $v0, $t2
    ctx->r2 = SUB32(ctx->r2, ctx->r10);
    // 0x800FF5AC: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800FF5B0: addu        $v0, $sp, $v0
    ctx->r2 = ADD32(ctx->r29, ctx->r2);
    // 0x800FF5B4: lbu         $v1, 0x198($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X198);
    // 0x800FF5B8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800FF5BC: beq         $v1, $v0, L_800FF810
    if (ctx->r3 == ctx->r2) {
        // 0x800FF5C0: nop
    
            goto L_800FF810;
    }
    // 0x800FF5C0: nop

    // 0x800FF5C4: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800FF5C8: lwc1        $f20, -0x6B84($at)
    ctx->f20.u32l = MEM_W(ctx->r1, -0X6B84);
    // 0x800FF5CC: mul.s       $f20, $f24, $f20
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f20.fl = MUL_S(ctx->f24.fl, ctx->f20.fl);
    // 0x800FF5D0: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x800FF5D4: jal         0x8001CC3C
    // 0x800FF5D8: addiu       $a0, $sp, 0x3D8
    ctx->r4 = ADD32(ctx->r29, 0X3D8);
    func_8001CC3C(rdram, ctx);
        goto after_11;
    // 0x800FF5D8: addiu       $a0, $sp, 0x3D8
    ctx->r4 = ADD32(ctx->r29, 0X3D8);
    after_11:
    // 0x800FF5DC: lw          $t3, 0x500($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X500);
    // 0x800FF5E0: lwc1        $f0, 0x0($t3)
    ctx->f0.u32l = MEM_W(ctx->r11, 0X0);
    // 0x800FF5E4: sub.s       $f0, $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f20.fl;
    // 0x800FF5E8: swc1        $f0, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->f0.u32l;
    // 0x800FF5EC: lw          $t4, 0x4F8($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X4F8);
    // 0x800FF5F0: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x800FF5F4: lwc1        $f0, 0xDC($t4)
    ctx->f0.u32l = MEM_W(ctx->r12, 0XDC);
    // 0x800FF5F8: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x800FF5FC: nop

    // 0x800FF600: bc1tl       L_800FF98C
    if (c1cs) {
        // 0x800FF604: swc1        $f2, 0xDC($t4)
        MEM_W(0XDC, ctx->r12) = ctx->f2.u32l;
            goto L_800FF98C;
    }
    goto skip_4;
    // 0x800FF604: swc1        $f2, 0xDC($t4)
    MEM_W(0XDC, ctx->r12) = ctx->f2.u32l;
    skip_4:
    // 0x800FF608: j           L_800FF98C
    // 0x800FF60C: nop

        goto L_800FF98C;
    // 0x800FF60C: nop

L_800FF610:
    // 0x800FF610: addiu       $v1, $sp, 0x198
    ctx->r3 = ADD32(ctx->r29, 0X198);
    // 0x800FF614: lw          $t0, 0x4F8($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X4F8);
    // 0x800FF618: lw          $t1, 0x488($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X488);
    // 0x800FF61C: addiu       $a0, $t0, 0x1C
    ctx->r4 = ADD32(ctx->r8, 0X1C);
    // 0x800FF620: sll         $v0, $t1, 1
    ctx->r2 = S32(ctx->r9 << 1);
    // 0x800FF624: addu        $v0, $v0, $t1
    ctx->r2 = ADD32(ctx->r2, ctx->r9);
    // 0x800FF628: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800FF62C: subu        $v0, $v0, $t1
    ctx->r2 = SUB32(ctx->r2, ctx->r9);
    // 0x800FF630: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800FF634: addu        $s1, $v1, $v0
    ctx->r17 = ADD32(ctx->r3, ctx->r2);
    // 0x800FF638: addiu       $s0, $s1, 0x10
    ctx->r16 = ADD32(ctx->r17, 0X10);
    // 0x800FF63C: jal         0x8001CFE8
    // 0x800FF640: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    func_8001CFE8(rdram, ctx);
        goto after_12;
    // 0x800FF640: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    after_12:
    // 0x800FF644: jal         0x8001C400
    // 0x800FF648: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    func_8001C400(rdram, ctx);
        goto after_13;
    // 0x800FF648: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    after_13:
    // 0x800FF64C: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x800FF650: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800FF654: lwc1        $f20, -0x6B80($at)
    ctx->f20.u32l = MEM_W(ctx->r1, -0X6B80);
    // 0x800FF658: lw          $t2, 0x4F8($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X4F8);
    // 0x800FF65C: mul.s       $f22, $f0, $f20
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f22.fl = MUL_S(ctx->f0.fl, ctx->f20.fl);
    // 0x800FF660: jal         0x8001CFE8
    // 0x800FF664: addiu       $a0, $t2, 0x10
    ctx->r4 = ADD32(ctx->r10, 0X10);
    func_8001CFE8(rdram, ctx);
        goto after_14;
    // 0x800FF664: addiu       $a0, $t2, 0x10
    ctx->r4 = ADD32(ctx->r10, 0X10);
    after_14:
    // 0x800FF668: jal         0x8001C5CC
    // 0x800FF66C: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    func_8001C5CC(rdram, ctx);
        goto after_15;
    // 0x800FF66C: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    after_15:
    // 0x800FF670: mul.s       $f26, $f0, $f20
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f26.fl = MUL_S(ctx->f0.fl, ctx->f20.fl);
    // 0x800FF674: abs.s       $f2, $f22
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f22.fl); 
    ctx->f2.fl = fabsf(ctx->f22.fl);
    // 0x800FF678: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800FF67C: lwc1        $f0, -0x6B7C($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X6B7C);
    // 0x800FF680: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x800FF684: nop

    // 0x800FF688: bc1f        L_800FF748
    if (!c1cs) {
        // 0x800FF68C: nop
    
            goto L_800FF748;
    }
    // 0x800FF68C: nop

    // 0x800FF690: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800FF694: lwc1        $f0, -0x6B78($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X6B78);
    // 0x800FF698: c.lt.s      $f26, $f0
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f26.fl < ctx->f0.fl;
    // 0x800FF69C: nop

    // 0x800FF6A0: bc1f        L_800FF738
    if (!c1cs) {
        // 0x800FF6A4: nop
    
            goto L_800FF738;
    }
    // 0x800FF6A4: nop

    // 0x800FF6A8: lbu         $v1, 0x0($s1)
    ctx->r3 = MEM_BU(ctx->r17, 0X0);
    // 0x800FF6AC: beq         $v1, $zero, L_800FF6C4
    if (ctx->r3 == 0) {
        // 0x800FF6B0: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_800FF6C4;
    }
    // 0x800FF6B0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800FF6B4: beq         $v1, $v0, L_800FF6E0
    if (ctx->r3 == ctx->r2) {
        // 0x800FF6B8: addiu       $t3, $zero, 0x2
        ctx->r11 = ADD32(0, 0X2);
            goto L_800FF6E0;
    }
    // 0x800FF6B8: addiu       $t3, $zero, 0x2
    ctx->r11 = ADD32(0, 0X2);
    // 0x800FF6BC: j           L_800FF738
    // 0x800FF6C0: nop

        goto L_800FF738;
    // 0x800FF6C0: nop

L_800FF6C4:
    // 0x800FF6C4: lwc1        $f2, 0x24($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0X24);
    // 0x800FF6C8: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800FF6CC: lwc1        $f0, -0x6B74($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X6B74);
    // 0x800FF6D0: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x800FF6D4: nop

    // 0x800FF6D8: bc1t        L_800FF748
    if (c1cs) {
        // 0x800FF6DC: addiu       $t3, $zero, 0x2
        ctx->r11 = ADD32(0, 0X2);
            goto L_800FF748;
    }
    // 0x800FF6DC: addiu       $t3, $zero, 0x2
    ctx->r11 = ADD32(0, 0X2);
L_800FF6E0:
    // 0x800FF6E0: lw          $t4, 0x488($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X488);
    // 0x800FF6E4: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800FF6E8: lw          $t0, 0x4F8($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X4F8);
    // 0x800FF6EC: addiu       $v1, $sp, 0x198
    ctx->r3 = ADD32(ctx->r29, 0X198);
    // 0x800FF6F0: sb          $t3, 0x497($sp)
    MEM_B(0X497, ctx->r29) = ctx->r11;
    // 0x800FF6F4: sll         $v0, $t4, 1
    ctx->r2 = S32(ctx->r12 << 1);
    // 0x800FF6F8: addu        $v0, $v0, $t4
    ctx->r2 = ADD32(ctx->r2, ctx->r12);
    // 0x800FF6FC: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800FF700: subu        $v0, $v0, $t4
    ctx->r2 = SUB32(ctx->r2, ctx->r12);
    // 0x800FF704: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800FF708: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x800FF70C: lw          $t1, 0x4($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X4);
    // 0x800FF710: lw          $t2, 0x8($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X8);
    // 0x800FF714: lw          $t3, 0xC($v1)
    ctx->r11 = MEM_W(ctx->r3, 0XC);
    // 0x800FF718: sw          $t1, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r9;
    // 0x800FF71C: sw          $t2, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->r10;
    // 0x800FF720: sw          $t3, 0xC($t0)
    MEM_W(0XC, ctx->r8) = ctx->r11;
    // 0x800FF724: swc1        $f0, 0x30($t0)
    MEM_W(0X30, ctx->r8) = ctx->f0.u32l;
    // 0x800FF728: swc1        $f0, 0x2C($t0)
    MEM_W(0X2C, ctx->r8) = ctx->f0.u32l;
    // 0x800FF72C: swc1        $f0, 0x28($t0)
    MEM_W(0X28, ctx->r8) = ctx->f0.u32l;
    // 0x800FF730: j           L_800FFC30
    // 0x800FF734: swc1        $f0, 0xE8($t0)
    MEM_W(0XE8, ctx->r8) = ctx->f0.u32l;
        goto L_800FFC30;
    // 0x800FF734: swc1        $f0, 0xE8($t0)
    MEM_W(0XE8, ctx->r8) = ctx->f0.u32l;
L_800FF738:
    // 0x800FF738: jal         0x8001CA50
    // 0x800FF73C: addiu       $a0, $sp, 0x3D8
    ctx->r4 = ADD32(ctx->r29, 0X3D8);
    func_8001CA50(rdram, ctx);
        goto after_16;
    // 0x800FF73C: addiu       $a0, $sp, 0x3D8
    ctx->r4 = ADD32(ctx->r29, 0X3D8);
    after_16:
    // 0x800FF740: j           L_800FF98C
    // 0x800FF744: nop

        goto L_800FF98C;
    // 0x800FF744: nop

L_800FF748:
    // 0x800FF748: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800FF74C: lwc1        $f0, -0x6B70($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X6B70);
    // 0x800FF750: c.lt.s      $f0, $f26
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 26);
    c1cs = ctx->f0.fl < ctx->f26.fl;
    // 0x800FF754: nop

    // 0x800FF758: bc1f        L_800FF7E4
    if (!c1cs) {
        // 0x800FF75C: nop
    
            goto L_800FF7E4;
    }
    // 0x800FF75C: nop

    // 0x800FF760: lw          $t0, 0x488($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X488);
    // 0x800FF764: sll         $v0, $t0, 1
    ctx->r2 = S32(ctx->r8 << 1);
    // 0x800FF768: addu        $v0, $v0, $t0
    ctx->r2 = ADD32(ctx->r2, ctx->r8);
    // 0x800FF76C: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800FF770: subu        $v0, $v0, $t0
    ctx->r2 = SUB32(ctx->r2, ctx->r8);
    // 0x800FF774: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800FF778: addu        $v0, $sp, $v0
    ctx->r2 = ADD32(ctx->r29, ctx->r2);
    // 0x800FF77C: lbu         $v1, 0x198($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X198);
    // 0x800FF780: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800FF784: beq         $v1, $v0, L_800FF810
    if (ctx->r3 == ctx->r2) {
        // 0x800FF788: nop
    
            goto L_800FF810;
    }
    // 0x800FF788: nop

    // 0x800FF78C: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800FF790: lwc1        $f0, -0x6B6C($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X6B6C);
    // 0x800FF794: mul.s       $f0, $f24, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = MUL_S(ctx->f24.fl, ctx->f0.fl);
    // 0x800FF798: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x800FF79C: jal         0x8001CC3C
    // 0x800FF7A0: addiu       $a0, $sp, 0x3D8
    ctx->r4 = ADD32(ctx->r29, 0X3D8);
    func_8001CC3C(rdram, ctx);
        goto after_17;
    // 0x800FF7A0: addiu       $a0, $sp, 0x3D8
    ctx->r4 = ADD32(ctx->r29, 0X3D8);
    after_17:
    // 0x800FF7A4: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800FF7A8: lwc1        $f2, -0x6B68($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X6B68);
    // 0x800FF7AC: mul.s       $f2, $f24, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = MUL_S(ctx->f24.fl, ctx->f2.fl);
    // 0x800FF7B0: lw          $t1, 0x500($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X500);
    // 0x800FF7B4: lwc1        $f0, 0x0($t1)
    ctx->f0.u32l = MEM_W(ctx->r9, 0X0);
    // 0x800FF7B8: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x800FF7BC: swc1        $f0, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->f0.u32l;
    // 0x800FF7C0: lw          $t2, 0x4F8($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X4F8);
    // 0x800FF7C4: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x800FF7C8: lwc1        $f0, 0xDC($t2)
    ctx->f0.u32l = MEM_W(ctx->r10, 0XDC);
    // 0x800FF7CC: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x800FF7D0: nop

    // 0x800FF7D4: bc1tl       L_800FF98C
    if (c1cs) {
        // 0x800FF7D8: swc1        $f2, 0xDC($t2)
        MEM_W(0XDC, ctx->r10) = ctx->f2.u32l;
            goto L_800FF98C;
    }
    goto skip_5;
    // 0x800FF7D8: swc1        $f2, 0xDC($t2)
    MEM_W(0XDC, ctx->r10) = ctx->f2.u32l;
    skip_5:
    // 0x800FF7DC: j           L_800FF98C
    // 0x800FF7E0: nop

        goto L_800FF98C;
    // 0x800FF7E0: nop

L_800FF7E4:
    // 0x800FF7E4: lw          $t3, 0x488($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X488);
    // 0x800FF7E8: sll         $v0, $t3, 1
    ctx->r2 = S32(ctx->r11 << 1);
    // 0x800FF7EC: addu        $v0, $v0, $t3
    ctx->r2 = ADD32(ctx->r2, ctx->r11);
    // 0x800FF7F0: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800FF7F4: subu        $v0, $v0, $t3
    ctx->r2 = SUB32(ctx->r2, ctx->r11);
    // 0x800FF7F8: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800FF7FC: addu        $v0, $sp, $v0
    ctx->r2 = ADD32(ctx->r29, ctx->r2);
    // 0x800FF800: lbu         $v1, 0x198($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X198);
    // 0x800FF804: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800FF808: bne         $v1, $v0, L_800FF948
    if (ctx->r3 != ctx->r2) {
        // 0x800FF80C: nop
    
            goto L_800FF948;
    }
    // 0x800FF80C: nop

L_800FF810:
    // 0x800FF810: lw          $t4, 0x488($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X488);
    // 0x800FF814: addiu       $v1, $sp, 0x198
    ctx->r3 = ADD32(ctx->r29, 0X198);
L_800FF818:
    // 0x800FF818: sll         $v0, $t4, 1
    ctx->r2 = S32(ctx->r12 << 1);
    // 0x800FF81C: addu        $v0, $v0, $t4
    ctx->r2 = ADD32(ctx->r2, ctx->r12);
    // 0x800FF820: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800FF824: subu        $v0, $v0, $t4
    ctx->r2 = SUB32(ctx->r2, ctx->r12);
    // 0x800FF828: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800FF82C: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x800FF830: lbu         $v0, 0x1($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X1);
    // 0x800FF834: bne         $v0, $zero, L_800FF8FC
    if (ctx->r2 != 0) {
        // 0x800FF838: nop
    
            goto L_800FF8FC;
    }
    // 0x800FF838: nop

    // 0x800FF83C: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800FF840: lwc1        $f20, -0x6B64($at)
    ctx->f20.u32l = MEM_W(ctx->r1, -0X6B64);
    // 0x800FF844: lw          $t0, 0x4F8($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X4F8);
    // 0x800FF848: c.lt.s      $f26, $f20
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f26.fl < ctx->f20.fl;
    // 0x800FF84C: lw          $t1, 0x4($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X4);
    // 0x800FF850: lw          $t2, 0x8($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X8);
    // 0x800FF854: lw          $t3, 0xC($v1)
    ctx->r11 = MEM_W(ctx->r3, 0XC);
    // 0x800FF858: sw          $t1, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r9;
    // 0x800FF85C: sw          $t2, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->r10;
    // 0x800FF860: sw          $t3, 0xC($t0)
    MEM_W(0XC, ctx->r8) = ctx->r11;
    // 0x800FF864: bc1f        L_800FF8FC
    if (!c1cs) {
        // 0x800FF868: addiu       $s1, $sp, 0x38
        ctx->r17 = ADD32(ctx->r29, 0X38);
            goto L_800FF8FC;
    }
    // 0x800FF868: addiu       $s1, $sp, 0x38
    ctx->r17 = ADD32(ctx->r29, 0X38);
    // 0x800FF86C: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x800FF870: addiu       $s2, $t0, 0x1C
    ctx->r18 = ADD32(ctx->r8, 0X1C);
    // 0x800FF874: addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    // 0x800FF878: jal         0x80019548
    // 0x800FF87C: addiu       $a2, $v1, 0x10
    ctx->r6 = ADD32(ctx->r3, 0X10);
    func_80019548(rdram, ctx);
        goto after_18;
    // 0x800FF87C: addiu       $a2, $v1, 0x10
    ctx->r6 = ADD32(ctx->r3, 0X10);
    after_18:
    // 0x800FF880: sub.s       $f2, $f20, $f26
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f2.fl = ctx->f20.fl - ctx->f26.fl;
    // 0x800FF884: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800FF888: lwc1        $f0, -0x6B60($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X6B60);
    // 0x800FF88C: mul.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x800FF890: addiu       $s0, $sp, 0x408
    ctx->r16 = ADD32(ctx->r29, 0X408);
    // 0x800FF894: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x800FF898: mfc1        $a2, $f2
    ctx->r6 = (int32_t)ctx->f2.u32l;
    // 0x800FF89C: jal         0x8001D144
    // 0x800FF8A0: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    func_8001D144(rdram, ctx);
        goto after_19;
    // 0x800FF8A0: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    after_19:
    // 0x800FF8A4: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x800FF8A8: lw          $t0, 0x4F8($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X4F8);
    // 0x800FF8AC: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    // 0x800FF8B0: lw          $t1, 0x10($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X10);
    // 0x800FF8B4: lw          $t2, 0x14($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X14);
    // 0x800FF8B8: lw          $t3, 0x18($t0)
    ctx->r11 = MEM_W(ctx->r8, 0X18);
    // 0x800FF8BC: sw          $t1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r9;
    // 0x800FF8C0: sw          $t2, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r10;
    // 0x800FF8C4: sw          $t3, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r11;
    // 0x800FF8C8: jal         0x8001D3C4
    // 0x800FF8CC: addiu       $a2, $t0, 0x10
    ctx->r6 = ADD32(ctx->r8, 0X10);
    func_8001D3C4(rdram, ctx);
        goto after_20;
    // 0x800FF8CC: addiu       $a2, $t0, 0x10
    ctx->r6 = ADD32(ctx->r8, 0X10);
    after_20:
    // 0x800FF8D0: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x800FF8D4: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    // 0x800FF8D8: lw          $t0, 0x4F8($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X4F8);
    // 0x800FF8DC: lw          $t1, 0x1C($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X1C);
    // 0x800FF8E0: lw          $t2, 0x20($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X20);
    // 0x800FF8E4: lw          $t3, 0x24($t0)
    ctx->r11 = MEM_W(ctx->r8, 0X24);
    // 0x800FF8E8: sw          $t1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r9;
    // 0x800FF8EC: sw          $t2, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r10;
    // 0x800FF8F0: sw          $t3, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r11;
    // 0x800FF8F4: jal         0x8001D3C4
    // 0x800FF8F8: addu        $a2, $s2, $zero
    ctx->r6 = ADD32(ctx->r18, 0);
    func_8001D3C4(rdram, ctx);
        goto after_21;
    // 0x800FF8F8: addu        $a2, $s2, $zero
    ctx->r6 = ADD32(ctx->r18, 0);
    after_21:
L_800FF8FC:
    // 0x800FF8FC: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800FF900: lwc1        $f20, -0x6B5C($at)
    ctx->f20.u32l = MEM_W(ctx->r1, -0X6B5C);
    // 0x800FF904: mul.s       $f20, $f24, $f20
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f20.fl = MUL_S(ctx->f24.fl, ctx->f20.fl);
    // 0x800FF908: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x800FF90C: jal         0x8001CC3C
    // 0x800FF910: addiu       $a0, $sp, 0x3D8
    ctx->r4 = ADD32(ctx->r29, 0X3D8);
    func_8001CC3C(rdram, ctx);
        goto after_22;
    // 0x800FF910: addiu       $a0, $sp, 0x3D8
    ctx->r4 = ADD32(ctx->r29, 0X3D8);
    after_22:
    // 0x800FF914: lw          $t0, 0x500($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X500);
    // 0x800FF918: lwc1        $f0, 0x0($t0)
    ctx->f0.u32l = MEM_W(ctx->r8, 0X0);
    // 0x800FF91C: sub.s       $f0, $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f20.fl;
    // 0x800FF920: swc1        $f0, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->f0.u32l;
    // 0x800FF924: lw          $t1, 0x4F8($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X4F8);
    // 0x800FF928: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x800FF92C: lwc1        $f0, 0xDC($t1)
    ctx->f0.u32l = MEM_W(ctx->r9, 0XDC);
    // 0x800FF930: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
L_800FF934:
    // 0x800FF934: nop

    // 0x800FF938: bc1tl       L_800FF98C
    if (c1cs) {
        // 0x800FF93C: swc1        $f2, 0xDC($t1)
        MEM_W(0XDC, ctx->r9) = ctx->f2.u32l;
            goto L_800FF98C;
    }
    goto skip_6;
    // 0x800FF93C: swc1        $f2, 0xDC($t1)
    MEM_W(0XDC, ctx->r9) = ctx->f2.u32l;
    skip_6:
    // 0x800FF940: j           L_800FF98C
    // 0x800FF944: nop

        goto L_800FF98C;
    // 0x800FF944: nop

L_800FF948:
    // 0x800FF948: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800FF94C: lwc1        $f20, -0x6B58($at)
    ctx->f20.u32l = MEM_W(ctx->r1, -0X6B58);
    // 0x800FF950: mul.s       $f20, $f24, $f20
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f20.fl = MUL_S(ctx->f24.fl, ctx->f20.fl);
    // 0x800FF954: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x800FF958: jal         0x8001CC3C
    // 0x800FF95C: addiu       $a0, $sp, 0x3D8
    ctx->r4 = ADD32(ctx->r29, 0X3D8);
    func_8001CC3C(rdram, ctx);
        goto after_23;
    // 0x800FF95C: addiu       $a0, $sp, 0x3D8
    ctx->r4 = ADD32(ctx->r29, 0X3D8);
    after_23:
    // 0x800FF960: lw          $t2, 0x500($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X500);
    // 0x800FF964: lwc1        $f0, 0x0($t2)
    ctx->f0.u32l = MEM_W(ctx->r10, 0X0);
    // 0x800FF968: sub.s       $f0, $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f20.fl;
    // 0x800FF96C: swc1        $f0, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->f0.u32l;
    // 0x800FF970: lw          $t3, 0x4F8($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X4F8);
    // 0x800FF974: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x800FF978: lwc1        $f0, 0xDC($t3)
    ctx->f0.u32l = MEM_W(ctx->r11, 0XDC);
    // 0x800FF97C: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x800FF980: nop

    // 0x800FF984: bc1tl       L_800FF98C
    if (c1cs) {
        // 0x800FF988: swc1        $f2, 0xDC($t3)
        MEM_W(0XDC, ctx->r11) = ctx->f2.u32l;
            goto L_800FF98C;
    }
    goto skip_7;
    // 0x800FF988: swc1        $f2, 0xDC($t3)
    MEM_W(0XDC, ctx->r11) = ctx->f2.u32l;
    skip_7:
L_800FF98C:
    // 0x800FF98C: lw          $v0, 0x498($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X498);
    // 0x800FF990: addiu       $v1, $sp, 0x3A8
    ctx->r3 = ADD32(ctx->r29, 0X3A8);
    // 0x800FF994: addiu       $a0, $v0, 0x30
    ctx->r4 = ADD32(ctx->r2, 0X30);
L_800FF998:
    // 0x800FF998: lw          $t4, 0x0($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X0);
    // 0x800FF99C: lw          $t0, 0x4($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X4);
    // 0x800FF9A0: lw          $t1, 0x8($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X8);
    // 0x800FF9A4: lw          $t2, 0xC($v0)
    ctx->r10 = MEM_W(ctx->r2, 0XC);
    // 0x800FF9A8: sw          $t4, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r12;
    // 0x800FF9AC: sw          $t0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r8;
    // 0x800FF9B0: sw          $t1, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r9;
    // 0x800FF9B4: sw          $t2, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r10;
    // 0x800FF9B8: addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
    // 0x800FF9BC: bne         $v0, $a0, L_800FF998
    if (ctx->r2 != ctx->r4) {
        // 0x800FF9C0: addiu       $v1, $v1, 0x10
        ctx->r3 = ADD32(ctx->r3, 0X10);
            goto L_800FF998;
    }
    // 0x800FF9C0: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
    // 0x800FF9C4: addiu       $a0, $sp, 0x3A8
    ctx->r4 = ADD32(ctx->r29, 0X3A8);
    // 0x800FF9C8: lw          $a2, 0x498($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X498);
    // 0x800FF9CC: jal         0x800191C4
    // 0x800FF9D0: addiu       $a1, $sp, 0x3D8
    ctx->r5 = ADD32(ctx->r29, 0X3D8);
    func_800191C4(rdram, ctx);
        goto after_24;
    // 0x800FF9D0: addiu       $a1, $sp, 0x3D8
    ctx->r5 = ADD32(ctx->r29, 0X3D8);
    after_24:
    // 0x800FF9D4: lw          $t3, 0x4F8($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X4F8);
    // 0x800FF9D8: lw          $a1, 0x498($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X498);
    // 0x800FF9DC: jal         0x80059D18
    // 0x800FF9E0: addiu       $a0, $t3, 0x4
    ctx->r4 = ADD32(ctx->r11, 0X4);
    func_80059D18(rdram, ctx);
        goto after_25;
    // 0x800FF9E0: addiu       $a0, $t3, 0x4
    ctx->r4 = ADD32(ctx->r11, 0X4);
    after_25:
    // 0x800FF9E4: lw          $t4, 0x4F8($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X4F8);
    // 0x800FF9E8: lwc1        $f0, 0x10($t4)
    ctx->f0.u32l = MEM_W(ctx->r12, 0X10);
    // 0x800FF9EC: lwc1        $f2, 0xE8($t4)
    ctx->f2.u32l = MEM_W(ctx->r12, 0XE8);
    // 0x800FF9F0: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x800FF9F4: nop

    // 0x800FF9F8: mul.s       $f2, $f0, $f24
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f2.fl = MUL_S(ctx->f0.fl, ctx->f24.fl);
    // 0x800FF9FC: swc1        $f0, 0x28($t4)
    MEM_W(0X28, ctx->r12) = ctx->f0.u32l;
    // 0x800FFA00: swc1        $f2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f2.u32l;
    // 0x800FFA04: lwc1        $f0, 0x14($t4)
    ctx->f0.u32l = MEM_W(ctx->r12, 0X14);
    // 0x800FFA08: lwc1        $f2, 0xE8($t4)
    ctx->f2.u32l = MEM_W(ctx->r12, 0XE8);
    // 0x800FFA0C: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x800FFA10: nop

    // 0x800FFA14: mul.s       $f2, $f0, $f24
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f2.fl = MUL_S(ctx->f0.fl, ctx->f24.fl);
    // 0x800FFA18: swc1        $f0, 0x2C($t4)
    MEM_W(0X2C, ctx->r12) = ctx->f0.u32l;
    // 0x800FFA1C: swc1        $f2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f2.u32l;
    // 0x800FFA20: lwc1        $f2, 0x18($t4)
    ctx->f2.u32l = MEM_W(ctx->r12, 0X18);
    // 0x800FFA24: lwc1        $f0, 0xE8($t4)
    ctx->f0.u32l = MEM_W(ctx->r12, 0XE8);
    // 0x800FFA28: mul.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x800FFA2C: lw          $t1, 0x48C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X48C);
    // 0x800FFA30: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x800FFA34: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
    // 0x800FFA38: mul.s       $f0, $f2, $f24
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f0.fl = MUL_S(ctx->f2.fl, ctx->f24.fl);
    // 0x800FFA3C: sltiu       $v0, $t1, 0x5
    ctx->r2 = ctx->r9 < 0X5 ? 1 : 0;
    // 0x800FFA40: sb          $t0, 0x497($sp)
    MEM_B(0X497, ctx->r29) = ctx->r8;
    // 0x800FFA44: sw          $t1, 0x48C($sp)
    MEM_W(0X48C, ctx->r29) = ctx->r9;
    // 0x800FFA48: swc1        $f2, 0x30($t4)
    MEM_W(0X30, ctx->r12) = ctx->f2.u32l;
    // 0x800FFA4C: bne         $v0, $zero, L_800FEFF8
    if (ctx->r2 != 0) {
        // 0x800FFA50: swc1        $f0, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->f0.u32l;
            goto L_800FEFF8;
    }
    // 0x800FFA50: swc1        $f0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f0.u32l;
L_800FFA54:
    // 0x800FFA54: lw          $t2, 0x4F8($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X4F8);
    // 0x800FFA58: lwc1        $f12, 0x18($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X18);
    // 0x800FFA5C: lwc1        $f0, 0x4($t2)
    ctx->f0.u32l = MEM_W(ctx->r10, 0X4);
    // 0x800FFA60: lwc1        $f14, 0x20($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X20);
    // 0x800FFA64: add.s       $f12, $f0, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = ctx->f0.fl + ctx->f12.fl;
    // 0x800FFA68: lwc1        $f0, 0xC($t2)
    ctx->f0.u32l = MEM_W(ctx->r10, 0XC);
    // 0x800FFA6C: lui         $a2, 0x8014
    ctx->r6 = S32(0X8014 << 16);
    // 0x800FFA70: add.s       $f14, $f0, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f14.fl = ctx->f0.fl + ctx->f14.fl;
    // 0x800FFA74: addiu       $a2, $a2, -0x7FA8
    ctx->r6 = ADD32(ctx->r6, -0X7FA8);
    // 0x800FFA78: jal         0x80067D90
    // 0x800FFA7C: addiu       $a3, $sp, 0x418
    ctx->r7 = ADD32(ctx->r29, 0X418);
    func_80067D90(rdram, ctx);
        goto after_26;
    // 0x800FFA7C: addiu       $a3, $sp, 0x418
    ctx->r7 = ADD32(ctx->r29, 0X418);
    after_26:
    // 0x800FFA80: jal         0x800B41EC
    // 0x800FFA84: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    func_800B41EC(rdram, ctx);
        goto after_27;
    // 0x800FFA84: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    after_27:
    // 0x800FFA88: c.lt.s      $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f20.fl < ctx->f0.fl;
    // 0x800FFA8C: nop

    // 0x800FFA90: bc1f        L_800FFAA4
    if (!c1cs) {
        // 0x800FFA94: nop
    
            goto L_800FFAA4;
    }
    // 0x800FFA94: nop

    // 0x800FFA98: jal         0x800B41EC
    // 0x800FFA9C: nop

    func_800B41EC(rdram, ctx);
        goto after_28;
    // 0x800FFA9C: nop

    after_28:
    // 0x800FFAA0: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
L_800FFAA4:
    // 0x800FFAA4: lw          $t3, 0x4F8($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X4F8);
    // 0x800FFAA8: lwc1        $f2, 0x1C($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x800FFAAC: lwc1        $f0, 0x8($t3)
    ctx->f0.u32l = MEM_W(ctx->r11, 0X8);
    // 0x800FFAB0: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x800FFAB4: c.lt.s      $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f20.fl < ctx->f0.fl;
    // 0x800FFAB8: nop

    // 0x800FFABC: bc1f        L_800FFC30
    if (!c1cs) {
        // 0x800FFAC0: addiu       $s0, $sp, 0x48
        ctx->r16 = ADD32(ctx->r29, 0X48);
            goto L_800FFC30;
    }
    // 0x800FFAC0: addiu       $s0, $sp, 0x48
    ctx->r16 = ADD32(ctx->r29, 0X48);
    // 0x800FFAC4: lwc1        $f2, 0x424($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X424);
    // 0x800FFAC8: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800FFACC: lwc1        $f10, -0x6B54($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X6B54);
    // 0x800FFAD0: mul.s       $f2, $f2, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f10.fl);
    // 0x800FFAD4: lwc1        $f6, 0x428($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X428);
    // 0x800FFAD8: mul.s       $f6, $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x800FFADC: lwc1        $f4, 0x4($t3)
    ctx->f4.u32l = MEM_W(ctx->r11, 0X4);
    // 0x800FFAE0: lwc1        $f0, 0x18($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X18);
    // 0x800FFAE4: add.s       $f4, $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f0.fl;
    // 0x800FFAE8: sub.s       $f4, $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = ctx->f4.fl - ctx->f2.fl;
    // 0x800FFAEC: sub.s       $f6, $f20, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f6.fl = ctx->f20.fl - ctx->f6.fl;
    // 0x800FFAF0: lwc1        $f8, 0x42C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X42C);
    // 0x800FFAF4: lwc1        $f0, 0x20($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X20);
    // 0x800FFAF8: mul.s       $f8, $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x800FFAFC: swc1        $f4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f4.u32l;
    // 0x800FFB00: swc1        $f6, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f6.u32l;
    // 0x800FFB04: lwc1        $f2, 0xC($t3)
    ctx->f2.u32l = MEM_W(ctx->r11, 0XC);
    // 0x800FFB08: add.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x800FFB0C: sub.s       $f2, $f2, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f2.fl = ctx->f2.fl - ctx->f8.fl;
    // 0x800FFB10: swc1        $f2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f2.u32l;
    // 0x800FFB14: lwc1        $f0, 0x4($t3)
    ctx->f0.u32l = MEM_W(ctx->r11, 0X4);
    // 0x800FFB18: sub.s       $f4, $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f4.fl - ctx->f0.fl;
    // 0x800FFB1C: swc1        $f4, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f4.u32l;
    // 0x800FFB20: lwc1        $f0, 0x8($t3)
    ctx->f0.u32l = MEM_W(ctx->r11, 0X8);
    // 0x800FFB24: sub.s       $f6, $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f6.fl - ctx->f0.fl;
    // 0x800FFB28: swc1        $f6, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f6.u32l;
    // 0x800FFB2C: lwc1        $f0, 0xC($t3)
    ctx->f0.u32l = MEM_W(ctx->r11, 0XC);
    // 0x800FFB30: sub.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl - ctx->f0.fl;
    // 0x800FFB34: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x800FFB38: jal         0x8001CF58
    // 0x800FFB3C: swc1        $f2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f2.u32l;
    normalize_vector(rdram, ctx);
        goto after_29;
    // 0x800FFB3C: swc1        $f2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f2.u32l;
    after_29:
    // 0x800FFB40: lw          $t4, 0x4F8($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X4F8);
    // 0x800FFB44: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x800FFB48: addiu       $s2, $t4, 0x10
    ctx->r18 = ADD32(ctx->r12, 0X10);
    // 0x800FFB4C: lw          $t0, 0x38($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X38);
    // 0x800FFB50: lw          $t1, 0x3C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X3C);
    // 0x800FFB54: lw          $t2, 0x40($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X40);
    // 0x800FFB58: sw          $t0, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r8;
    // 0x800FFB5C: sw          $t1, 0x8($t4)
    MEM_W(0X8, ctx->r12) = ctx->r9;
    // 0x800FFB60: sw          $t2, 0xC($t4)
    MEM_W(0XC, ctx->r12) = ctx->r10;
    // 0x800FFB64: jal         0x8001CFE8
    // 0x800FFB68: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    func_8001CFE8(rdram, ctx);
        goto after_30;
    // 0x800FFB68: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    after_30:
    // 0x800FFB6C: jal         0x8001C5CC
    // 0x800FFB70: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    func_8001C5CC(rdram, ctx);
        goto after_31;
    // 0x800FFB70: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    after_31:
    // 0x800FFB74: addiu       $s1, $sp, 0x28
    ctx->r17 = ADD32(ctx->r29, 0X28);
    // 0x800FFB78: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x800FFB7C: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800FFB80: lwc1        $f2, -0x6B50($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X6B50);
    // 0x800FFB84: addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    // 0x800FFB88: mul.s       $f26, $f0, $f2
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f26.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x800FFB8C: jal         0x80019548
    // 0x800FFB90: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    func_80019548(rdram, ctx);
        goto after_32;
    // 0x800FFB90: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    after_32:
    // 0x800FFB94: addiu       $s0, $sp, 0x408
    ctx->r16 = ADD32(ctx->r29, 0X408);
    // 0x800FFB98: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x800FFB9C: mfc1        $a2, $f26
    ctx->r6 = (int32_t)ctx->f26.u32l;
    // 0x800FFBA0: jal         0x8001D144
    // 0x800FFBA4: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    func_8001D144(rdram, ctx);
        goto after_33;
    // 0x800FFBA4: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    after_33:
    // 0x800FFBA8: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x800FFBAC: addiu       $s1, $sp, 0x38
    ctx->r17 = ADD32(ctx->r29, 0X38);
    // 0x800FFBB0: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    // 0x800FFBB4: lw          $t4, 0x4F8($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X4F8);
    // 0x800FFBB8: lw          $t0, 0x10($t4)
    ctx->r8 = MEM_W(ctx->r12, 0X10);
    // 0x800FFBBC: lw          $t1, 0x14($t4)
    ctx->r9 = MEM_W(ctx->r12, 0X14);
    // 0x800FFBC0: lw          $t2, 0x18($t4)
    ctx->r10 = MEM_W(ctx->r12, 0X18);
    // 0x800FFBC4: sw          $t0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r8;
    // 0x800FFBC8: sw          $t1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r9;
    // 0x800FFBCC: sw          $t2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r10;
    // 0x800FFBD0: jal         0x8001D3C4
    // 0x800FFBD4: addu        $a2, $s2, $zero
    ctx->r6 = ADD32(ctx->r18, 0);
    func_8001D3C4(rdram, ctx);
        goto after_34;
    // 0x800FFBD4: addu        $a2, $s2, $zero
    ctx->r6 = ADD32(ctx->r18, 0);
    after_34:
    // 0x800FFBD8: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x800FFBDC: lw          $t4, 0x4F8($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X4F8);
    // 0x800FFBE0: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    // 0x800FFBE4: lw          $t0, 0x1C($t4)
    ctx->r8 = MEM_W(ctx->r12, 0X1C);
    // 0x800FFBE8: lw          $t1, 0x20($t4)
    ctx->r9 = MEM_W(ctx->r12, 0X20);
    // 0x800FFBEC: lw          $t2, 0x24($t4)
    ctx->r10 = MEM_W(ctx->r12, 0X24);
    // 0x800FFBF0: sw          $t0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r8;
    // 0x800FFBF4: sw          $t1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r9;
    // 0x800FFBF8: sw          $t2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r10;
    // 0x800FFBFC: jal         0x8001D3C4
    // 0x800FFC00: addiu       $a2, $t4, 0x1C
    ctx->r6 = ADD32(ctx->r12, 0X1C);
    func_8001D3C4(rdram, ctx);
        goto after_35;
    // 0x800FFC00: addiu       $a2, $t4, 0x1C
    ctx->r6 = ADD32(ctx->r12, 0X1C);
    after_35:
    // 0x800FFC04: lw          $t4, 0x4F8($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X4F8);
    // 0x800FFC08: lwc1        $f6, 0x10($t4)
    ctx->f6.u32l = MEM_W(ctx->r12, 0X10);
    // 0x800FFC0C: lwc1        $f0, 0xE8($t4)
    ctx->f0.u32l = MEM_W(ctx->r12, 0XE8);
    // 0x800FFC10: mul.s       $f6, $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x800FFC14: lwc1        $f4, 0x14($t4)
    ctx->f4.u32l = MEM_W(ctx->r12, 0X14);
    // 0x800FFC18: mul.s       $f4, $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x800FFC1C: lwc1        $f2, 0x18($t4)
    ctx->f2.u32l = MEM_W(ctx->r12, 0X18);
    // 0x800FFC20: mul.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x800FFC24: swc1        $f6, 0x28($t4)
    MEM_W(0X28, ctx->r12) = ctx->f6.u32l;
    // 0x800FFC28: swc1        $f4, 0x2C($t4)
    MEM_W(0X2C, ctx->r12) = ctx->f4.u32l;
    // 0x800FFC2C: swc1        $f2, 0x30($t4)
    MEM_W(0X30, ctx->r12) = ctx->f2.u32l;
L_800FFC30:
    // 0x800FFC30: lbu         $t0, 0x497($sp)
    ctx->r8 = MEM_BU(ctx->r29, 0X497);
    // 0x800FFC34: beq         $t0, $zero, L_800FFD80
    if (ctx->r8 == 0) {
        // 0x800FFC38: addiu       $v1, $sp, 0x198
        ctx->r3 = ADD32(ctx->r29, 0X198);
            goto L_800FFD80;
    }
    // 0x800FFC38: addiu       $v1, $sp, 0x198
    ctx->r3 = ADD32(ctx->r29, 0X198);
    // 0x800FFC3C: lw          $t1, 0x488($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X488);
    // 0x800FFC40: sll         $v0, $t1, 1
    ctx->r2 = S32(ctx->r9 << 1);
    // 0x800FFC44: addu        $v0, $v0, $t1
    ctx->r2 = ADD32(ctx->r2, ctx->r9);
    // 0x800FFC48: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800FFC4C: subu        $v0, $v0, $t1
    ctx->r2 = SUB32(ctx->r2, ctx->r9);
    // 0x800FFC50: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800FFC54: addu        $s0, $v1, $v0
    ctx->r16 = ADD32(ctx->r3, ctx->r2);
    // 0x800FFC58: lbu         $v0, 0x0($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X0);
    // 0x800FFC5C: lw          $v1, 0x50C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X50C);
    // 0x800FFC60: sb          $v0, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r2;
    // 0x800FFC64: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x800FFC68: bne         $v0, $zero, L_800FFD80
    if (ctx->r2 != 0) {
        // 0x800FFC6C: nop
    
            goto L_800FFD80;
    }
    // 0x800FFC6C: nop

    // 0x800FFC70: jal         0x8006C994
    // 0x800FFC74: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    func_8006C994(rdram, ctx);
        goto after_36;
    // 0x800FFC74: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    after_36:
    // 0x800FFC78: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    // 0x800FFC7C: sh          $v0, 0x468($sp)
    MEM_H(0X468, ctx->r29) = ctx->r2;
    // 0x800FFC80: sb          $zero, 0x46A($sp)
    MEM_B(0X46A, ctx->r29) = 0;
    // 0x800FFC84: lhu         $a0, 0x2($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X2);
    // 0x800FFC88: jal         0x8003E8DC
    // 0x800FFC8C: addiu       $a2, $sp, 0x468
    ctx->r6 = ADD32(ctx->r29, 0X468);
    slotDispatcherIter(rdram, ctx);
        goto after_37;
    // 0x800FFC8C: addiu       $a2, $sp, 0x468
    ctx->r6 = ADD32(ctx->r29, 0X468);
    after_37:
    // 0x800FFC90: lbu         $v0, 0x46A($sp)
    ctx->r2 = MEM_BU(ctx->r29, 0X46A);
    // 0x800FFC94: bne         $v0, $zero, L_800FFD80
    if (ctx->r2 != 0) {
        // 0x800FFC98: nop
    
            goto L_800FFD80;
    }
    // 0x800FFC98: nop

    // 0x800FFC9C: lwc1        $f0, 0x24($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X24);
    // 0x800FFCA0: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800FFCA4: lwc1        $f2, -0x6B4C($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X6B4C);
    // 0x800FFCA8: sub.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl - ctx->f0.fl;
    // 0x800FFCAC: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800FFCB0: lwc1        $f0, -0x6B48($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X6B48);
    // 0x800FFCB4: mul.s       $f0, $f2, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x800FFCB8: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800FFCBC: lwc1        $f2, -0x6B44($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X6B44);
    // 0x800FFCC0: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x800FFCC4: nop

    // 0x800FFCC8: bc1tl       L_800FFCE8
    if (c1cs) {
        // 0x800FFCCC: mov.s       $f0, $f2
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
            goto L_800FFCE8;
    }
    goto skip_8;
    // 0x800FFCCC: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    skip_8:
    // 0x800FFCD0: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800FFCD4: lwc1        $f2, -0x6B40($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X6B40);
    // 0x800FFCD8: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x800FFCDC: nop

    // 0x800FFCE0: bc1tl       L_800FFCE8
    if (c1cs) {
        // 0x800FFCE4: mov.s       $f0, $f2
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
            goto L_800FFCE8;
    }
    goto skip_9;
    // 0x800FFCE4: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    skip_9:
L_800FFCE8:
    // 0x800FFCE8: lbu         $t2, 0x497($sp)
    ctx->r10 = MEM_BU(ctx->r29, 0X497);
    // 0x800FFCEC: ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
    // 0x800FFCF0: sh          $v0, 0x478($sp)
    MEM_H(0X478, ctx->r29) = ctx->r2;
    // 0x800FFCF4: sh          $v0, 0x47A($sp)
    MEM_H(0X47A, ctx->r29) = ctx->r2;
    // 0x800FFCF8: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x800FFCFC: beq         $t2, $v0, L_800FFD44
    if (ctx->r10 == ctx->r2) {
        // 0x800FFD00: sh          $zero, 0x47C($sp)
        MEM_H(0X47C, ctx->r29) = 0;
            goto L_800FFD44;
    }
    // 0x800FFD00: sh          $zero, 0x47C($sp)
    MEM_H(0X47C, ctx->r29) = 0;
    // 0x800FFD04: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800FFD08: lwc1        $f2, -0x6B3C($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X6B3C);
    // 0x800FFD0C: c.le.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl <= ctx->f0.fl;
    // 0x800FFD10: nop

    // 0x800FFD14: bc1tl       L_800FFD2C
    if (c1cs) {
        // 0x800FFD18: sub.s       $f0, $f0, $f2
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
            goto L_800FFD2C;
    }
    goto skip_10;
    // 0x800FFD18: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    skip_10:
    // 0x800FFD1C: trunc.w.s   $f28, $f0
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 0);
    ctx->f28.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800FFD20: mfc1        $v1, $f28
    ctx->r3 = (int32_t)ctx->f28.u32l;
    // 0x800FFD24: j           L_800FFD4C
    // 0x800FFD28: sh          $v1, 0x47E($sp)
    MEM_H(0X47E, ctx->r29) = ctx->r3;
        goto L_800FFD4C;
    // 0x800FFD28: sh          $v1, 0x47E($sp)
    MEM_H(0X47E, ctx->r29) = ctx->r3;
L_800FFD2C:
    // 0x800FFD2C: lui         $v0, 0x8000
    ctx->r2 = S32(0X8000 << 16);
    // 0x800FFD30: trunc.w.s   $f28, $f0
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 0);
    ctx->f28.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800FFD34: mfc1        $v1, $f28
    ctx->r3 = (int32_t)ctx->f28.u32l;
    // 0x800FFD38: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x800FFD3C: j           L_800FFD4C
    // 0x800FFD40: sh          $v1, 0x47E($sp)
    MEM_H(0X47E, ctx->r29) = ctx->r3;
        goto L_800FFD4C;
    // 0x800FFD40: sh          $v1, 0x47E($sp)
    MEM_H(0X47E, ctx->r29) = ctx->r3;
L_800FFD44:
    // 0x800FFD44: addiu       $v0, $zero, 0x1F4
    ctx->r2 = ADD32(0, 0X1F4);
    // 0x800FFD48: sh          $v0, 0x47E($sp)
    MEM_H(0X47E, ctx->r29) = ctx->r2;
L_800FFD4C:
    // 0x800FFD4C: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    // 0x800FFD50: lw          $t1, 0x488($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X488);
    // 0x800FFD54: addiu       $v1, $sp, 0x198
    ctx->r3 = ADD32(ctx->r29, 0X198);
    // 0x800FFD58: sw          $zero, 0x480($sp)
    MEM_W(0X480, ctx->r29) = 0;
    // 0x800FFD5C: sll         $v0, $t1, 1
    ctx->r2 = S32(ctx->r9 << 1);
    // 0x800FFD60: addu        $v0, $v0, $t1
    ctx->r2 = ADD32(ctx->r2, ctx->r9);
    // 0x800FFD64: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800FFD68: subu        $v0, $v0, $t1
    ctx->r2 = SUB32(ctx->r2, ctx->r9);
    // 0x800FFD6C: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800FFD70: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x800FFD74: lhu         $a0, 0x2($v1)
    ctx->r4 = MEM_HU(ctx->r3, 0X2);
    // 0x800FFD78: jal         0x8003E8DC
    // 0x800FFD7C: addiu       $a2, $sp, 0x478
    ctx->r6 = ADD32(ctx->r29, 0X478);
    slotDispatcherIter(rdram, ctx);
        goto after_38;
    // 0x800FFD7C: addiu       $a2, $sp, 0x478
    ctx->r6 = ADD32(ctx->r29, 0X478);
    after_38:
L_800FFD80:
    // 0x800FFD80: lw          $t2, 0x4F8($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X4F8);
    // 0x800FFD84: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x800FFD88: lw          $v0, 0xB8($t2)
    ctx->r2 = MEM_W(ctx->r10, 0XB8);
    // 0x800FFD8C: addiu       $a1, $t2, 0x4
    ctx->r5 = ADD32(ctx->r10, 0X4);
    // 0x800FFD90: sll         $a0, $v0, 2
    ctx->r4 = S32(ctx->r2 << 2);
    // 0x800FFD94: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // 0x800FFD98: sll         $a0, $a0, 2
    ctx->r4 = S32(ctx->r4 << 2);
    // 0x800FFD9C: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // 0x800FFDA0: sll         $a0, $a0, 5
    ctx->r4 = S32(ctx->r4 << 5);
    // 0x800FFDA4: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x800FFDA8: addiu       $v0, $v0, -0x7FF4
    ctx->r2 = ADD32(ctx->r2, -0X7FF4);
    // 0x800FFDAC: jal         0x80059B50
    // 0x800FFDB0: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    func_80059B50(rdram, ctx);
        goto after_39;
    // 0x800FFDB0: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    after_39:
L_800FFDB4:
    // 0x800FFDB4: lbu         $t3, 0x497($sp)
    ctx->r11 = MEM_BU(ctx->r29, 0X497);
    // 0x800FFDB8: lw          $ra, 0x4CC($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4CC);
    // 0x800FFDBC: lw          $fp, 0x4C8($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X4C8);
    // 0x800FFDC0: lw          $s7, 0x4C4($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X4C4);
    // 0x800FFDC4: lw          $s6, 0x4C0($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X4C0);
    // 0x800FFDC8: lw          $s5, 0x4BC($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X4BC);
    // 0x800FFDCC: lw          $s4, 0x4B8($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X4B8);
    // 0x800FFDD0: lw          $s3, 0x4B4($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X4B4);
    // 0x800FFDD4: lw          $s2, 0x4B0($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X4B0);
    // 0x800FFDD8: lw          $s1, 0x4AC($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X4AC);
    // 0x800FFDDC: lw          $s0, 0x4A8($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X4A8);
    // 0x800FFDE0: ldc1        $f28, 0x4F0($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0X4F0);
    // 0x800FFDE4: ldc1        $f26, 0x4E8($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X4E8);
    // 0x800FFDE8: ldc1        $f24, 0x4E0($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X4E0);
    // 0x800FFDEC: ldc1        $f22, 0x4D8($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X4D8);
    // 0x800FFDF0: ldc1        $f20, 0x4D0($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X4D0);
    // 0x800FFDF4: addu        $v0, $t3, $zero
    ctx->r2 = ADD32(ctx->r11, 0);
    // 0x800FFDF8: jr          $ra
    // 0x800FFDFC: addiu       $sp, $sp, 0x4F8
    ctx->r29 = ADD32(ctx->r29, 0X4F8);
    return;
    // 0x800FFDFC: addiu       $sp, $sp, 0x4F8
    ctx->r29 = ADD32(ctx->r29, 0X4F8);
;}
RECOMP_FUNC void func_800FFE00(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800FFE00: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800FFE04: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x800FFE08: addu        $s1, $a0, $zero
    ctx->r17 = ADD32(ctx->r4, 0);
    // 0x800FFE0C: sw          $ra, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r31;
    // 0x800FFE10: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x800FFE14: lhu         $v1, 0xB4($s1)
    ctx->r3 = MEM_HU(ctx->r17, 0XB4);
    // 0x800FFE18: slti        $v0, $v1, 0x4
    ctx->r2 = SIGNED(ctx->r3) < 0X4 ? 1 : 0;
    // 0x800FFE1C: beql        $v0, $zero, L_800FFE3C
    if (ctx->r2 == 0) {
        // 0x800FFE20: addiu       $v0, $zero, 0x7
        ctx->r2 = ADD32(0, 0X7);
            goto L_800FFE3C;
    }
    goto skip_0;
    // 0x800FFE20: addiu       $v0, $zero, 0x7
    ctx->r2 = ADD32(0, 0X7);
    skip_0:
    // 0x800FFE24: bne         $v1, $zero, L_800FFE88
    if (ctx->r3 != 0) {
        // 0x800FFE28: lui         $a1, 0x800B
        ctx->r5 = S32(0X800B << 16);
            goto L_800FFE88;
    }
    // 0x800FFE28: lui         $a1, 0x800B
    ctx->r5 = S32(0X800B << 16);
    // 0x800FFE2C: beq         $v1, $zero, L_800FFE4C
    if (ctx->r3 == 0) {
        // 0x800FFE30: lui         $v0, 0x8011
        ctx->r2 = S32(0X8011 << 16);
            goto L_800FFE4C;
    }
    // 0x800FFE30: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800FFE34: j           L_800FFEA8
    // 0x800FFE38: sb          $zero, -0x30B8($v0)
    MEM_B(-0X30B8, ctx->r2) = 0;
        goto L_800FFEA8;
    // 0x800FFE38: sb          $zero, -0x30B8($v0)
    MEM_B(-0X30B8, ctx->r2) = 0;
L_800FFE3C:
    // 0x800FFE3C: beq         $v1, $v0, L_800FFE84
    if (ctx->r3 == ctx->r2) {
        // 0x800FFE40: lui         $v0, 0x8011
        ctx->r2 = S32(0X8011 << 16);
            goto L_800FFE84;
    }
    // 0x800FFE40: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800FFE44: j           L_800FFEA8
    // 0x800FFE48: sb          $zero, -0x30B8($v0)
    MEM_B(-0X30B8, ctx->r2) = 0;
        goto L_800FFEA8;
    // 0x800FFE48: sb          $zero, -0x30B8($v0)
    MEM_B(-0X30B8, ctx->r2) = 0;
L_800FFE4C:
    // 0x800FFE4C: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x800FFE50: jal         0x800594F8
    // 0x800FFE54: addiu       $a1, $a1, -0x6B30
    ctx->r5 = ADD32(ctx->r5, -0X6B30);
    func_800594F8(rdram, ctx);
        goto after_0;
    // 0x800FFE54: addiu       $a1, $a1, -0x6B30
    ctx->r5 = ADD32(ctx->r5, -0X6B30);
    after_0:
    // 0x800FFE58: lui         $a1, 0x800B
    ctx->r5 = S32(0X800B << 16);
    // 0x800FFE5C: addiu       $a1, $a1, -0x6B28
    ctx->r5 = ADD32(ctx->r5, -0X6B28);
    // 0x800FFE60: lui         $s0, 0x8011
    ctx->r16 = S32(0X8011 << 16);
    // 0x800FFE64: sw          $v0, -0x30C8($s0)
    MEM_W(-0X30C8, ctx->r16) = ctx->r2;
    // 0x800FFE68: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x800FFE6C: jal         0x800594F8
    // 0x800FFE70: addiu       $s0, $s0, -0x30C8
    ctx->r16 = ADD32(ctx->r16, -0X30C8);
    func_800594F8(rdram, ctx);
        goto after_1;
    // 0x800FFE70: addiu       $s0, $s0, -0x30C8
    ctx->r16 = ADD32(ctx->r16, -0X30C8);
    after_1:
    // 0x800FFE74: sw          $v0, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r2;
    // 0x800FFE78: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x800FFE7C: j           L_800FFEA8
    // 0x800FFE80: sb          $v0, 0x10($s0)
    MEM_B(0X10, ctx->r16) = ctx->r2;
        goto L_800FFEA8;
    // 0x800FFE80: sb          $v0, 0x10($s0)
    MEM_B(0X10, ctx->r16) = ctx->r2;
L_800FFE84:
    // 0x800FFE84: lui         $a1, 0x800B
    ctx->r5 = S32(0X800B << 16);
L_800FFE88:
    // 0x800FFE88: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x800FFE8C: jal         0x800594F8
    // 0x800FFE90: addiu       $a1, $a1, -0x6B30
    ctx->r5 = ADD32(ctx->r5, -0X6B30);
    func_800594F8(rdram, ctx);
        goto after_2;
    // 0x800FFE90: addiu       $a1, $a1, -0x6B30
    ctx->r5 = ADD32(ctx->r5, -0X6B30);
    after_2:
    // 0x800FFE94: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
    // 0x800FFE98: sw          $v0, -0x30C8($v1)
    MEM_W(-0X30C8, ctx->r3) = ctx->r2;
    // 0x800FFE9C: addiu       $v1, $v1, -0x30C8
    ctx->r3 = ADD32(ctx->r3, -0X30C8);
    // 0x800FFEA0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800FFEA4: sb          $v0, 0x10($v1)
    MEM_B(0X10, ctx->r3) = ctx->r2;
L_800FFEA8:
    // 0x800FFEA8: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800FFEAC: addiu       $v1, $v0, -0x30C8
    ctx->r3 = ADD32(ctx->r2, -0X30C8);
    // 0x800FFEB0: lbu         $v0, 0x10($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X10);
    // 0x800FFEB4: addu        $t2, $zero, $zero
    ctx->r10 = ADD32(0, 0);
    // 0x800FFEB8: beq         $v0, $zero, L_80100198
    if (ctx->r2 == 0) {
        // 0x800FFEBC: sb          $zero, 0x11($v1)
        MEM_B(0X11, ctx->r3) = 0;
            goto L_80100198;
    }
    // 0x800FFEBC: sb          $zero, 0x11($v1)
    MEM_B(0X11, ctx->r3) = 0;
    // 0x800FFEC0: addu        $a2, $v1, $zero
    ctx->r6 = ADD32(ctx->r3, 0);
    // 0x800FFEC4: andi        $v0, $t2, 0xFF
    ctx->r2 = ctx->r10 & 0XFF;
L_800FFEC8:
    // 0x800FFEC8: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800FFECC: addu        $v0, $v0, $a2
    ctx->r2 = ADD32(ctx->r2, ctx->r6);
    // 0x800FFED0: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x800FFED4: lw          $a3, 0x0($v0)
    ctx->r7 = MEM_W(ctx->r2, 0X0);
    // 0x800FFED8: addiu       $a0, $zero, -0x9
    ctx->r4 = ADD32(0, -0X9);
    // 0x800FFEDC: lw          $v0, 0xC($a3)
    ctx->r2 = MEM_W(ctx->r7, 0XC);
    // 0x800FFEE0: lw          $v1, 0x20($a3)
    ctx->r3 = MEM_W(ctx->r7, 0X20);
    // 0x800FFEE4: and         $v0, $v0, $a0
    ctx->r2 = ctx->r2 & ctx->r4;
    // 0x800FFEE8: sw          $v0, 0xC($a3)
    MEM_W(0XC, ctx->r7) = ctx->r2;
    // 0x800FFEEC: lw          $v0, 0xC($v1)
    ctx->r2 = MEM_W(ctx->r3, 0XC);
    // 0x800FFEF0: lw          $t0, 0x8($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X8);
    // 0x800FFEF4: beq         $v0, $zero, L_80100180
    if (ctx->r2 == 0) {
        // 0x800FFEF8: addu        $t1, $zero, $zero
        ctx->r9 = ADD32(0, 0);
            goto L_80100180;
    }
    // 0x800FFEF8: addu        $t1, $zero, $zero
    ctx->r9 = ADD32(0, 0);
L_800FFEFC:
    // 0x800FFEFC: lhu         $a1, 0x4($t0)
    ctx->r5 = MEM_HU(ctx->r8, 0X4);
    // 0x800FFF00: lbu         $a0, 0x11($a2)
    ctx->r4 = MEM_BU(ctx->r6, 0X11);
    // 0x800FFF04: lw          $v1, 0x24($a3)
    ctx->r3 = MEM_W(ctx->r7, 0X24);
    // 0x800FFF08: andi        $a1, $a1, 0xFC
    ctx->r5 = ctx->r5 & 0XFC;
    // 0x800FFF0C: addu        $a1, $t0, $a1
    ctx->r5 = ADD32(ctx->r8, ctx->r5);
    // 0x800FFF10: sll         $a0, $a0, 4
    ctx->r4 = S32(ctx->r4 << 4);
    // 0x800FFF14: lhu         $v0, 0x0($a1)
    ctx->r2 = MEM_HU(ctx->r5, 0X0);
    // 0x800FFF18: addu        $a0, $a0, $a2
    ctx->r4 = ADD32(ctx->r4, ctx->r6);
    // 0x800FFF1C: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x800FFF20: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x800FFF24: sw          $v1, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->r3;
    // 0x800FFF28: lbu         $v1, 0x11($a2)
    ctx->r3 = MEM_BU(ctx->r6, 0X11);
    // 0x800FFF2C: lhu         $v0, 0x0($a1)
    ctx->r2 = MEM_HU(ctx->r5, 0X0);
    // 0x800FFF30: lw          $a0, 0x24($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X24);
    // 0x800FFF34: sll         $v1, $v1, 5
    ctx->r3 = S32(ctx->r3 << 5);
    // 0x800FFF38: addu        $v1, $v1, $a2
    ctx->r3 = ADD32(ctx->r3, ctx->r6);
    // 0x800FFF3C: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x800FFF40: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x800FFF44: lwl         $t3, 0x0($v0)
    ctx->r11 = do_lwl(rdram, ctx->r11, ctx->r2, 0X0);
    // 0x800FFF48: lwr         $t3, 0x3($v0)
    ctx->r11 = do_lwr(rdram, ctx->r11, ctx->r2, 0X3);
    // 0x800FFF4C: lwl         $t4, 0x4($v0)
    ctx->r12 = do_lwl(rdram, ctx->r12, ctx->r2, 0X4);
    // 0x800FFF50: lwr         $t4, 0x7($v0)
    ctx->r12 = do_lwr(rdram, ctx->r12, ctx->r2, 0X7);
    // 0x800FFF54: swl         $t3, 0x54($v1)
    do_swl(rdram, 0X54, ctx->r3, ctx->r11);
    // 0x800FFF58: swr         $t3, 0x57($v1)
    do_swr(rdram, 0X57, ctx->r3, ctx->r11);
    // 0x800FFF5C: swl         $t4, 0x58($v1)
    do_swl(rdram, 0X58, ctx->r3, ctx->r12);
    // 0x800FFF60: swr         $t4, 0x5B($v1)
    do_swr(rdram, 0X5B, ctx->r3, ctx->r12);
    // 0x800FFF64: lbu         $a0, 0x11($a2)
    ctx->r4 = MEM_BU(ctx->r6, 0X11);
    // 0x800FFF68: lhu         $v0, 0x2($a1)
    ctx->r2 = MEM_HU(ctx->r5, 0X2);
    // 0x800FFF6C: lw          $v1, 0x24($a3)
    ctx->r3 = MEM_W(ctx->r7, 0X24);
    // 0x800FFF70: sll         $a0, $a0, 4
    ctx->r4 = S32(ctx->r4 << 4);
    // 0x800FFF74: addu        $a0, $a0, $a2
    ctx->r4 = ADD32(ctx->r4, ctx->r6);
    // 0x800FFF78: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x800FFF7C: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x800FFF80: sw          $v1, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->r3;
    // 0x800FFF84: lbu         $v1, 0x11($a2)
    ctx->r3 = MEM_BU(ctx->r6, 0X11);
    // 0x800FFF88: lhu         $v0, 0x2($a1)
    ctx->r2 = MEM_HU(ctx->r5, 0X2);
    // 0x800FFF8C: lw          $a0, 0x24($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X24);
    // 0x800FFF90: sll         $v1, $v1, 5
    ctx->r3 = S32(ctx->r3 << 5);
    // 0x800FFF94: addu        $v1, $v1, $a2
    ctx->r3 = ADD32(ctx->r3, ctx->r6);
    // 0x800FFF98: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x800FFF9C: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x800FFFA0: lwl         $t3, 0x0($v0)
    ctx->r11 = do_lwl(rdram, ctx->r11, ctx->r2, 0X0);
    // 0x800FFFA4: lwr         $t3, 0x3($v0)
    ctx->r11 = do_lwr(rdram, ctx->r11, ctx->r2, 0X3);
    // 0x800FFFA8: lwl         $t4, 0x4($v0)
    ctx->r12 = do_lwl(rdram, ctx->r12, ctx->r2, 0X4);
    // 0x800FFFAC: lwr         $t4, 0x7($v0)
    ctx->r12 = do_lwr(rdram, ctx->r12, ctx->r2, 0X7);
    // 0x800FFFB0: swl         $t3, 0x5C($v1)
    do_swl(rdram, 0X5C, ctx->r3, ctx->r11);
    // 0x800FFFB4: swr         $t3, 0x5F($v1)
    do_swr(rdram, 0X5F, ctx->r3, ctx->r11);
    // 0x800FFFB8: swl         $t4, 0x60($v1)
    do_swl(rdram, 0X60, ctx->r3, ctx->r12);
    // 0x800FFFBC: swr         $t4, 0x63($v1)
    do_swr(rdram, 0X63, ctx->r3, ctx->r12);
    // 0x800FFFC0: lbu         $a0, 0x11($a2)
    ctx->r4 = MEM_BU(ctx->r6, 0X11);
    // 0x800FFFC4: lhu         $v0, 0x4($a1)
    ctx->r2 = MEM_HU(ctx->r5, 0X4);
    // 0x800FFFC8: lw          $v1, 0x24($a3)
    ctx->r3 = MEM_W(ctx->r7, 0X24);
    // 0x800FFFCC: sll         $a0, $a0, 4
    ctx->r4 = S32(ctx->r4 << 4);
    // 0x800FFFD0: addu        $a0, $a0, $a2
    ctx->r4 = ADD32(ctx->r4, ctx->r6);
    // 0x800FFFD4: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x800FFFD8: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x800FFFDC: sw          $v1, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = ctx->r3;
    // 0x800FFFE0: lbu         $v1, 0x11($a2)
    ctx->r3 = MEM_BU(ctx->r6, 0X11);
    // 0x800FFFE4: lhu         $v0, 0x4($a1)
    ctx->r2 = MEM_HU(ctx->r5, 0X4);
    // 0x800FFFE8: lw          $a0, 0x24($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X24);
    // 0x800FFFEC: sll         $v1, $v1, 5
    ctx->r3 = S32(ctx->r3 << 5);
    // 0x800FFFF0: addu        $v1, $v1, $a2
    ctx->r3 = ADD32(ctx->r3, ctx->r6);
    // 0x800FFFF4: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x800FFFF8: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x800FFFFC: lwl         $t3, 0x0($v0)
    ctx->r11 = do_lwl(rdram, ctx->r11, ctx->r2, 0X0);
    // 0x80100000: lwr         $t3, 0x3($v0)
    ctx->r11 = do_lwr(rdram, ctx->r11, ctx->r2, 0X3);
    // 0x80100004: lwl         $t4, 0x4($v0)
    ctx->r12 = do_lwl(rdram, ctx->r12, ctx->r2, 0X4);
    // 0x80100008: lwr         $t4, 0x7($v0)
    ctx->r12 = do_lwr(rdram, ctx->r12, ctx->r2, 0X7);
    // 0x8010000C: swl         $t3, 0x64($v1)
    do_swl(rdram, 0X64, ctx->r3, ctx->r11);
    // 0x80100010: swr         $t3, 0x67($v1)
    do_swr(rdram, 0X67, ctx->r3, ctx->r11);
    // 0x80100014: swl         $t4, 0x68($v1)
    do_swl(rdram, 0X68, ctx->r3, ctx->r12);
    // 0x80100018: swr         $t4, 0x6B($v1)
    do_swr(rdram, 0X6B, ctx->r3, ctx->r12);
    // 0x8010001C: lbu         $a0, 0x11($a2)
    ctx->r4 = MEM_BU(ctx->r6, 0X11);
    // 0x80100020: lhu         $v0, 0x6($a1)
    ctx->r2 = MEM_HU(ctx->r5, 0X6);
    // 0x80100024: lw          $v1, 0x24($a3)
    ctx->r3 = MEM_W(ctx->r7, 0X24);
    // 0x80100028: sll         $a0, $a0, 4
    ctx->r4 = S32(ctx->r4 << 4);
    // 0x8010002C: addu        $a0, $a0, $a2
    ctx->r4 = ADD32(ctx->r4, ctx->r6);
    // 0x80100030: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x80100034: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x80100038: sw          $v1, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r3;
    // 0x8010003C: lbu         $v1, 0x11($a2)
    ctx->r3 = MEM_BU(ctx->r6, 0X11);
    // 0x80100040: lhu         $v0, 0x6($a1)
    ctx->r2 = MEM_HU(ctx->r5, 0X6);
    // 0x80100044: lw          $a0, 0x24($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X24);
    // 0x80100048: sll         $v1, $v1, 5
    ctx->r3 = S32(ctx->r3 << 5);
    // 0x8010004C: addu        $v1, $v1, $a2
    ctx->r3 = ADD32(ctx->r3, ctx->r6);
    // 0x80100050: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x80100054: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x80100058: lwl         $t3, 0x0($v0)
    ctx->r11 = do_lwl(rdram, ctx->r11, ctx->r2, 0X0);
    // 0x8010005C: lwr         $t3, 0x3($v0)
    ctx->r11 = do_lwr(rdram, ctx->r11, ctx->r2, 0X3);
    // 0x80100060: lwl         $t4, 0x4($v0)
    ctx->r12 = do_lwl(rdram, ctx->r12, ctx->r2, 0X4);
    // 0x80100064: lwr         $t4, 0x7($v0)
    ctx->r12 = do_lwr(rdram, ctx->r12, ctx->r2, 0X7);
    // 0x80100068: swl         $t3, 0x6C($v1)
    do_swl(rdram, 0X6C, ctx->r3, ctx->r11);
    // 0x8010006C: swr         $t3, 0x6F($v1)
    do_swr(rdram, 0X6F, ctx->r3, ctx->r11);
    // 0x80100070: swl         $t4, 0x70($v1)
    do_swl(rdram, 0X70, ctx->r3, ctx->r12);
    // 0x80100074: swr         $t4, 0x73($v1)
    do_swr(rdram, 0X73, ctx->r3, ctx->r12);
    // 0x80100078: lbu         $v0, 0x11($a2)
    ctx->r2 = MEM_BU(ctx->r6, 0X11);
    // 0x8010007C: sll         $a1, $v0, 3
    ctx->r5 = S32(ctx->r2 << 3);
    // 0x80100080: sll         $v0, $v0, 4
    ctx->r2 = S32(ctx->r2 << 4);
    // 0x80100084: addu        $v0, $v0, $a2
    ctx->r2 = ADD32(ctx->r2, ctx->r6);
    // 0x80100088: lw          $v1, 0x14($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X14);
    // 0x8010008C: lw          $a0, 0x18($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X18);
    // 0x80100090: lh          $v1, 0x0($v1)
    ctx->r3 = MEM_H(ctx->r3, 0X0);
    // 0x80100094: lh          $a0, 0x0($a0)
    ctx->r4 = MEM_H(ctx->r4, 0X0);
    // 0x80100098: addu        $a1, $a1, $a2
    ctx->r5 = ADD32(ctx->r5, ctx->r6);
    // 0x8010009C: addu        $v1, $v1, $a0
    ctx->r3 = ADD32(ctx->r3, ctx->r4);
    // 0x801000A0: lw          $a0, 0x1C($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X1C);
    // 0x801000A4: lw          $v0, 0x20($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X20);
    // 0x801000A8: lh          $a0, 0x0($a0)
    ctx->r4 = MEM_H(ctx->r4, 0X0);
    // 0x801000AC: lh          $v0, 0x0($v0)
    ctx->r2 = MEM_H(ctx->r2, 0X0);
    // 0x801000B0: addu        $v1, $v1, $a0
    ctx->r3 = ADD32(ctx->r3, ctx->r4);
    // 0x801000B4: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x801000B8: srl         $v1, $v1, 2
    ctx->r3 = S32(U32(ctx->r3) >> 2);
    // 0x801000BC: sh          $v1, 0xD4($a1)
    MEM_H(0XD4, ctx->r5) = ctx->r3;
    // 0x801000C0: lbu         $v0, 0x11($a2)
    ctx->r2 = MEM_BU(ctx->r6, 0X11);
    // 0x801000C4: sll         $a1, $v0, 3
    ctx->r5 = S32(ctx->r2 << 3);
    // 0x801000C8: sll         $v0, $v0, 4
    ctx->r2 = S32(ctx->r2 << 4);
    // 0x801000CC: addu        $v0, $v0, $a2
    ctx->r2 = ADD32(ctx->r2, ctx->r6);
    // 0x801000D0: lw          $v1, 0x14($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X14);
    // 0x801000D4: lw          $a0, 0x18($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X18);
    // 0x801000D8: lh          $v1, 0x2($v1)
    ctx->r3 = MEM_H(ctx->r3, 0X2);
    // 0x801000DC: lh          $a0, 0x2($a0)
    ctx->r4 = MEM_H(ctx->r4, 0X2);
    // 0x801000E0: addu        $a1, $a1, $a2
    ctx->r5 = ADD32(ctx->r5, ctx->r6);
    // 0x801000E4: addu        $v1, $v1, $a0
    ctx->r3 = ADD32(ctx->r3, ctx->r4);
    // 0x801000E8: lw          $a0, 0x1C($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X1C);
    // 0x801000EC: lw          $v0, 0x20($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X20);
    // 0x801000F0: lh          $a0, 0x2($a0)
    ctx->r4 = MEM_H(ctx->r4, 0X2);
    // 0x801000F4: lh          $v0, 0x2($v0)
    ctx->r2 = MEM_H(ctx->r2, 0X2);
    // 0x801000F8: addu        $v1, $v1, $a0
    ctx->r3 = ADD32(ctx->r3, ctx->r4);
    // 0x801000FC: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x80100100: srl         $v1, $v1, 2
    ctx->r3 = S32(U32(ctx->r3) >> 2);
    // 0x80100104: sh          $v1, 0xD6($a1)
    MEM_H(0XD6, ctx->r5) = ctx->r3;
    // 0x80100108: lbu         $v1, 0x11($a2)
    ctx->r3 = MEM_BU(ctx->r6, 0X11);
    // 0x8010010C: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
    // 0x80100110: sll         $a1, $v1, 3
    ctx->r5 = S32(ctx->r3 << 3);
    // 0x80100114: sll         $v1, $v1, 4
    ctx->r3 = S32(ctx->r3 << 4);
    // 0x80100118: addu        $v1, $v1, $a2
    ctx->r3 = ADD32(ctx->r3, ctx->r6);
    // 0x8010011C: lw          $v0, 0x14($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X14);
    // 0x80100120: lw          $a0, 0x18($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X18);
    // 0x80100124: lh          $v0, 0x4($v0)
    ctx->r2 = MEM_H(ctx->r2, 0X4);
    // 0x80100128: lh          $a0, 0x4($a0)
    ctx->r4 = MEM_H(ctx->r4, 0X4);
    // 0x8010012C: addu        $a1, $a1, $a2
    ctx->r5 = ADD32(ctx->r5, ctx->r6);
    // 0x80100130: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x80100134: lw          $a0, 0x1C($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X1C);
    // 0x80100138: lw          $v1, 0x20($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X20);
    // 0x8010013C: lh          $a0, 0x4($a0)
    ctx->r4 = MEM_H(ctx->r4, 0X4);
    // 0x80100140: lh          $v1, 0x4($v1)
    ctx->r3 = MEM_H(ctx->r3, 0X4);
    // 0x80100144: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x80100148: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8010014C: srl         $v0, $v0, 2
    ctx->r2 = S32(U32(ctx->r2) >> 2);
    // 0x80100150: sh          $v0, 0xD8($a1)
    MEM_H(0XD8, ctx->r5) = ctx->r2;
    // 0x80100154: lbu         $v0, 0x11($a2)
    ctx->r2 = MEM_BU(ctx->r6, 0X11);
    // 0x80100158: lbu         $v1, 0x4($t0)
    ctx->r3 = MEM_BU(ctx->r8, 0X4);
    // 0x8010015C: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80100160: andi        $v1, $v1, 0x3F
    ctx->r3 = ctx->r3 & 0X3F;
    // 0x80100164: sb          $v0, 0x11($a2)
    MEM_B(0X11, ctx->r6) = ctx->r2;
    // 0x80100168: lw          $v0, 0x20($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X20);
    // 0x8010016C: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x80100170: lw          $v0, 0xC($v0)
    ctx->r2 = MEM_W(ctx->r2, 0XC);
    // 0x80100174: sltu        $v0, $t1, $v0
    ctx->r2 = ctx->r9 < ctx->r2 ? 1 : 0;
    // 0x80100178: bne         $v0, $zero, L_800FFEFC
    if (ctx->r2 != 0) {
        // 0x8010017C: addu        $t0, $t0, $v1
        ctx->r8 = ADD32(ctx->r8, ctx->r3);
            goto L_800FFEFC;
    }
    // 0x8010017C: addu        $t0, $t0, $v1
    ctx->r8 = ADD32(ctx->r8, ctx->r3);
L_80100180:
    // 0x80100180: addiu       $t2, $t2, 0x1
    ctx->r10 = ADD32(ctx->r10, 0X1);
    // 0x80100184: lbu         $v1, 0x10($a2)
    ctx->r3 = MEM_BU(ctx->r6, 0X10);
    // 0x80100188: andi        $v0, $t2, 0xFF
    ctx->r2 = ctx->r10 & 0XFF;
    // 0x8010018C: sltu        $v0, $v0, $v1
    ctx->r2 = ctx->r2 < ctx->r3 ? 1 : 0;
    // 0x80100190: bne         $v0, $zero, L_800FFEC8
    if (ctx->r2 != 0) {
        // 0x80100194: andi        $v0, $t2, 0xFF
        ctx->r2 = ctx->r10 & 0XFF;
            goto L_800FFEC8;
    }
    // 0x80100194: andi        $v0, $t2, 0xFF
    ctx->r2 = ctx->r10 & 0XFF;
L_80100198:
    // 0x80100198: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x8010019C: lwc1        $f0, 0xE8($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0XE8);
    // 0x801001A0: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x801001A4: lwc1        $f2, -0x6B20($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X6B20);
    // 0x801001A8: addiu       $v0, $v0, -0x30C8
    ctx->r2 = ADD32(ctx->r2, -0X30C8);
    // 0x801001AC: swc1        $f0, 0xF4($v0)
    MEM_W(0XF4, ctx->r2) = ctx->f0.u32l;
    // 0x801001B0: swc1        $f2, 0xF8($v0)
    MEM_W(0XF8, ctx->r2) = ctx->f2.u32l;
    // 0x801001B4: lw          $ra, 0x18($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X18);
    // 0x801001B8: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x801001BC: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x801001C0: jr          $ra
    // 0x801001C4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x801001C4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_801001C8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801001C8: addiu       $sp, $sp, -0xA0
    ctx->r29 = ADD32(ctx->r29, -0XA0);
    // 0x801001CC: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x801001D0: sw          $a0, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->r4;
    // 0x801001D4: addiu       $a0, $v0, -0x30C8
    ctx->r4 = ADD32(ctx->r2, -0X30C8);
    // 0x801001D8: sw          $ra, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r31;
    // 0x801001DC: sw          $fp, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r30;
    // 0x801001E0: sw          $s7, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r23;
    // 0x801001E4: sw          $s6, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r22;
    // 0x801001E8: sw          $s5, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r21;
    // 0x801001EC: sw          $s4, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r20;
    // 0x801001F0: sw          $s3, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r19;
    // 0x801001F4: sw          $s2, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r18;
    // 0x801001F8: sw          $s1, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r17;
    // 0x801001FC: sw          $s0, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r16;
    // 0x80100200: sdc1        $f24, 0x98($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X98, ctx->r29);
    // 0x80100204: sdc1        $f22, 0x90($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X90, ctx->r29);
    // 0x80100208: sdc1        $f20, 0x88($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X88, ctx->r29);
    // 0x8010020C: lbu         $v0, 0x11($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X11);
    // 0x80100210: mtc1        $a1, $f10
    ctx->f10.u32l = ctx->r5;
    // 0x80100214: beq         $v0, $zero, L_80100558
    if (ctx->r2 == 0) {
        // 0x80100218: nop
    
            goto L_80100558;
    }
    // 0x80100218: nop

    // 0x8010021C: lw          $a3, 0xA0($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XA0);
    // 0x80100220: lhu         $v0, 0xB4($a3)
    ctx->r2 = MEM_HU(ctx->r7, 0XB4);
    // 0x80100224: lwc1        $f8, 0xE8($a3)
    ctx->f8.u32l = MEM_W(ctx->r7, 0XE8);
    // 0x80100228: sll         $v1, $v0, 3
    ctx->r3 = S32(ctx->r2 << 3);
    // 0x8010022C: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x80100230: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x80100234: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x80100238: addiu       $v0, $v0, -0x4ACC
    ctx->r2 = ADD32(ctx->r2, -0X4ACC);
    // 0x8010023C: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x80100240: lwc1        $f4, 0x0($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X0);
    // 0x80100244: sub.s       $f0, $f8, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f8.fl - ctx->f4.fl;
    // 0x80100248: lwc1        $f2, 0xC($v1)
    ctx->f2.u32l = MEM_W(ctx->r3, 0XC);
    // 0x8010024C: mul.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x80100250: lwc1        $f0, 0x4($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X4);
    // 0x80100254: sub.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f4.fl;
    // 0x80100258: lwc1        $f6, 0xF4($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0XF4);
    // 0x8010025C: c.lt.s      $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f6.fl < ctx->f8.fl;
    // 0x80100260: lwc1        $f4, 0x8($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X8);
    // 0x80100264: div.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = DIV_S(ctx->f2.fl, ctx->f0.fl);
    // 0x80100268: bc1f        L_801002A0
    if (!c1cs) {
        // 0x8010026C: add.s       $f4, $f4, $f2
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f2.fl;
            goto L_801002A0;
    }
    // 0x8010026C: add.s       $f4, $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f2.fl;
    // 0x80100270: sub.s       $f0, $f8, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f8.fl - ctx->f6.fl;
    // 0x80100274: lwc1        $f6, 0x20($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X20);
    // 0x80100278: div.s       $f2, $f0, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = DIV_S(ctx->f0.fl, ctx->f10.fl);
    // 0x8010027C: c.lt.s      $f6, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f6.fl < ctx->f2.fl;
    // 0x80100280: nop

    // 0x80100284: bc1tl       L_8010028C
    if (c1cs) {
        // 0x80100288: mov.s       $f2, $f6
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    ctx->f2.fl = ctx->f6.fl;
            goto L_8010028C;
    }
    goto skip_0;
    // 0x80100288: mov.s       $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    ctx->f2.fl = ctx->f6.fl;
    skip_0:
L_8010028C:
    // 0x8010028C: lwc1        $f0, 0x10($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X10);
    // 0x80100290: div.s       $f0, $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f6.fl);
    // 0x80100294: mul.s       $f0, $f2, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x80100298: j           L_801002DC
    // 0x8010029C: add.s       $f22, $f4, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f22.fl = ctx->f4.fl + ctx->f0.fl;
        goto L_801002DC;
    // 0x8010029C: add.s       $f22, $f4, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f22.fl = ctx->f4.fl + ctx->f0.fl;
L_801002A0:
    // 0x801002A0: c.lt.s      $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f8.fl < ctx->f6.fl;
    // 0x801002A4: nop

    // 0x801002A8: bc1f        L_801002DC
    if (!c1cs) {
        // 0x801002AC: mov.s       $f22, $f4
        CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 4);
    ctx->f22.fl = ctx->f4.fl;
            goto L_801002DC;
    }
    // 0x801002AC: mov.s       $f22, $f4
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 4);
    ctx->f22.fl = ctx->f4.fl;
    // 0x801002B0: sub.s       $f0, $f6, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x801002B4: lwc1        $f6, 0x20($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X20);
    // 0x801002B8: div.s       $f2, $f0, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = DIV_S(ctx->f0.fl, ctx->f10.fl);
    // 0x801002BC: c.lt.s      $f6, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f6.fl < ctx->f2.fl;
    // 0x801002C0: nop

    // 0x801002C4: bc1tl       L_801002CC
    if (c1cs) {
        // 0x801002C8: mov.s       $f2, $f6
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    ctx->f2.fl = ctx->f6.fl;
            goto L_801002CC;
    }
    goto skip_1;
    // 0x801002C8: mov.s       $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    ctx->f2.fl = ctx->f6.fl;
    skip_1:
L_801002CC:
    // 0x801002CC: lwc1        $f0, 0x14($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X14);
    // 0x801002D0: div.s       $f0, $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f6.fl);
    // 0x801002D4: mul.s       $f0, $f2, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x801002D8: sub.s       $f22, $f4, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f22.fl = ctx->f4.fl - ctx->f0.fl;
L_801002DC:
    // 0x801002DC: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x801002E0: addiu       $v0, $v0, -0x30C8
    ctx->r2 = ADD32(ctx->r2, -0X30C8);
    // 0x801002E4: lwc1        $f2, 0xF8($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0XF8);
    // 0x801002E8: c.lt.s      $f2, $f22
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 22);
    c1cs = ctx->f2.fl < ctx->f22.fl;
    // 0x801002EC: nop

    // 0x801002F0: bc1f        L_80100310
    if (!c1cs) {
        // 0x801002F4: nop
    
            goto L_80100310;
    }
    // 0x801002F4: nop

    // 0x801002F8: lwc1        $f0, 0x18($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X18);
    // 0x801002FC: mul.s       $f0, $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x80100300: add.s       $f0, $f2, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x80100304: c.lt.s      $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f22.fl < ctx->f0.fl;
    // 0x80100308: j           L_80100324
    // 0x8010030C: swc1        $f0, 0xF8($v0)
    MEM_W(0XF8, ctx->r2) = ctx->f0.u32l;
        goto L_80100324;
    // 0x8010030C: swc1        $f0, 0xF8($v0)
    MEM_W(0XF8, ctx->r2) = ctx->f0.u32l;
L_80100310:
    // 0x80100310: lwc1        $f0, 0x1C($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X1C);
    // 0x80100314: mul.s       $f0, $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x80100318: sub.s       $f0, $f2, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f2.fl - ctx->f0.fl;
    // 0x8010031C: swc1        $f0, 0xF8($v0)
    MEM_W(0XF8, ctx->r2) = ctx->f0.u32l;
    // 0x80100320: c.lt.s      $f0, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    c1cs = ctx->f0.fl < ctx->f22.fl;
L_80100324:
    // 0x80100324: nop

    // 0x80100328: bc1tl       L_80100330
    if (c1cs) {
        // 0x8010032C: swc1        $f22, 0xF8($v0)
        MEM_W(0XF8, ctx->r2) = ctx->f22.u32l;
            goto L_80100330;
    }
    goto skip_2;
    // 0x8010032C: swc1        $f22, 0xF8($v0)
    MEM_W(0XF8, ctx->r2) = ctx->f22.u32l;
    skip_2:
L_80100330:
    // 0x80100330: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x80100334: addiu       $v1, $v0, -0x30C8
    ctx->r3 = ADD32(ctx->r2, -0X30C8);
    // 0x80100338: lwc1        $f0, 0xF8($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0XF8);
    // 0x8010033C: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80100340: lwc1        $f2, -0x6B1C($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X6B1C);
    // 0x80100344: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
    // 0x80100348: c.lt.s      $f22, $f2
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f22.fl < ctx->f2.fl;
    // 0x8010034C: nop

    // 0x80100350: bc1fl       L_80100358
    if (!c1cs) {
        // 0x80100354: mov.s       $f22, $f2
        CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 2);
    ctx->f22.fl = ctx->f2.fl;
            goto L_80100358;
    }
    goto skip_3;
    // 0x80100354: mov.s       $f22, $f2
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 2);
    ctx->f22.fl = ctx->f2.fl;
    skip_3:
L_80100358:
    // 0x80100358: lbu         $v0, 0x11($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X11);
    // 0x8010035C: beq         $v0, $zero, L_80100548
    if (ctx->r2 == 0) {
        // 0x80100360: addu        $s5, $zero, $zero
        ctx->r21 = ADD32(0, 0);
            goto L_80100548;
    }
    // 0x80100360: addu        $s5, $zero, $zero
    ctx->r21 = ADD32(0, 0);
    // 0x80100364: addiu       $fp, $sp, 0x20
    ctx->r30 = ADD32(ctx->r29, 0X20);
    // 0x80100368: addu        $s6, $v1, $zero
    ctx->r22 = ADD32(ctx->r3, 0);
    // 0x8010036C: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80100370: lwc1        $f24, -0x6B18($at)
    ctx->f24.u32l = MEM_W(ctx->r1, -0X6B18);
    // 0x80100374: addiu       $s3, $s6, 0xD4
    ctx->r19 = ADD32(ctx->r22, 0XD4);
L_80100378:
    // 0x80100378: addu        $s2, $zero, $zero
    ctx->r18 = ADD32(0, 0);
    // 0x8010037C: addu        $a1, $fp, $zero
    ctx->r5 = ADD32(ctx->r30, 0);
    // 0x80100380: sll         $a2, $s5, 5
    ctx->r6 = S32(ctx->r21 << 5);
L_80100384:
    // 0x80100384: addu        $a0, $a2, $s6
    ctx->r4 = ADD32(ctx->r6, ctx->r22);
    // 0x80100388: lh          $v0, 0x54($a0)
    ctx->r2 = MEM_H(ctx->r4, 0X54);
    // 0x8010038C: lh          $v1, 0x0($s3)
    ctx->r3 = MEM_H(ctx->r19, 0X0);
    // 0x80100390: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x80100394: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x80100398: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x8010039C: mul.s       $f0, $f0, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f22.fl);
    // 0x801003A0: swc1        $f0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f0.u32l;
    // 0x801003A4: lh          $v0, 0x56($a0)
    ctx->r2 = MEM_H(ctx->r4, 0X56);
    // 0x801003A8: lh          $v1, 0x2($s3)
    ctx->r3 = MEM_H(ctx->r19, 0X2);
    // 0x801003AC: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x801003B0: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x801003B4: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x801003B8: mul.s       $f0, $f0, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f22.fl);
    // 0x801003BC: swc1        $f0, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->f0.u32l;
    // 0x801003C0: lh          $v0, 0x58($a0)
    ctx->r2 = MEM_H(ctx->r4, 0X58);
    // 0x801003C4: lh          $v1, 0x4($s3)
    ctx->r3 = MEM_H(ctx->r19, 0X4);
    // 0x801003C8: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x801003CC: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x801003D0: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x801003D4: mul.s       $f0, $f0, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f22.fl);
    // 0x801003D8: addiu       $a2, $a2, 0x8
    ctx->r6 = ADD32(ctx->r6, 0X8);
    // 0x801003DC: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x801003E0: sltiu       $v0, $s2, 0x4
    ctx->r2 = ctx->r18 < 0X4 ? 1 : 0;
    // 0x801003E4: swc1        $f0, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->f0.u32l;
    // 0x801003E8: bne         $v0, $zero, L_80100384
    if (ctx->r2 != 0) {
        // 0x801003EC: addiu       $a1, $a1, 0xC
        ctx->r5 = ADD32(ctx->r5, 0XC);
            goto L_80100384;
    }
    // 0x801003EC: addiu       $a1, $a1, 0xC
    ctx->r5 = ADD32(ctx->r5, 0XC);
    // 0x801003F0: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x801003F4: lw          $a3, 0xA0($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XA0);
    // 0x801003F8: addiu       $a0, $a0, -0x4988
    ctx->r4 = ADD32(ctx->r4, -0X4988);
    // 0x801003FC: jal         0x8001CFE8
    // 0x80100400: addiu       $a1, $a3, 0x1C
    ctx->r5 = ADD32(ctx->r7, 0X1C);
    func_8001CFE8(rdram, ctx);
        goto after_0;
    // 0x80100400: addiu       $a1, $a3, 0x1C
    ctx->r5 = ADD32(ctx->r7, 0X1C);
    after_0:
    // 0x80100404: addiu       $s0, $sp, 0x50
    ctx->r16 = ADD32(ctx->r29, 0X50);
    // 0x80100408: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x8010040C: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    // 0x80100410: addiu       $a2, $sp, 0x2C
    ctx->r6 = ADD32(ctx->r29, 0X2C);
    // 0x80100414: addu        $s2, $zero, $zero
    ctx->r18 = ADD32(0, 0);
    // 0x80100418: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8010041C: lwc1        $f2, -0x6B14($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X6B14);
    // 0x80100420: lui         $s7, 0x8000
    ctx->r23 = S32(0X8000 << 16);
    // 0x80100424: mul.s       $f20, $f0, $f2
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f20.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x80100428: sll         $s1, $s5, 4
    ctx->r17 = S32(ctx->r21 << 4);
    // 0x8010042C: jal         0x80019548
    // 0x80100430: addu        $s4, $fp, $zero
    ctx->r20 = ADD32(ctx->r30, 0);
    func_80019548(rdram, ctx);
        goto after_1;
    // 0x80100430: addu        $s4, $fp, $zero
    ctx->r20 = ADD32(ctx->r30, 0);
    after_1:
    // 0x80100434: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    // 0x80100438: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x8010043C: jal         0x8001D144
    // 0x80100440: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    func_8001D144(rdram, ctx);
        goto after_2;
    // 0x80100440: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    after_2:
L_80100444:
    // 0x80100444: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    // 0x80100448: addu        $a1, $s4, $zero
    ctx->r5 = ADD32(ctx->r20, 0);
    // 0x8010044C: jal         0x8001D3C4
    // 0x80100450: addiu       $a2, $sp, 0x50
    ctx->r6 = ADD32(ctx->r29, 0X50);
    func_8001D3C4(rdram, ctx);
        goto after_3;
    // 0x80100450: addiu       $a2, $sp, 0x50
    ctx->r6 = ADD32(ctx->r29, 0X50);
    after_3:
    // 0x80100454: addu        $v0, $s1, $s6
    ctx->r2 = ADD32(ctx->r17, ctx->r22);
    // 0x80100458: lwc1        $f0, 0x50($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X50);
    // 0x8010045C: lw          $a0, 0x14($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X14);
    // 0x80100460: c.le.s      $f24, $f0
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f24.fl <= ctx->f0.fl;
    // 0x80100464: nop

    // 0x80100468: bc1tl       L_80100480
    if (c1cs) {
        // 0x8010046C: sub.s       $f0, $f0, $f24
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f24.fl;
            goto L_80100480;
    }
    goto skip_4;
    // 0x8010046C: sub.s       $f0, $f0, $f24
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f24.fl;
    skip_4:
    // 0x80100470: trunc.w.s   $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x80100474: mfc1        $v1, $f12
    ctx->r3 = (int32_t)ctx->f12.u32l;
    // 0x80100478: j           L_8010048C
    // 0x8010047C: nop

        goto L_8010048C;
    // 0x8010047C: nop

L_80100480:
    // 0x80100480: trunc.w.s   $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x80100484: mfc1        $v1, $f12
    ctx->r3 = (int32_t)ctx->f12.u32l;
    // 0x80100488: or          $v1, $v1, $s7
    ctx->r3 = ctx->r3 | ctx->r23;
L_8010048C:
    // 0x8010048C: lhu         $v0, 0x0($s3)
    ctx->r2 = MEM_HU(ctx->r19, 0X0);
    // 0x80100490: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80100494: sh          $v0, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r2;
    // 0x80100498: addu        $v0, $s1, $s6
    ctx->r2 = ADD32(ctx->r17, ctx->r22);
    // 0x8010049C: lwc1        $f0, 0x54($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X54);
    // 0x801004A0: lw          $a0, 0x14($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X14);
    // 0x801004A4: c.le.s      $f24, $f0
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f24.fl <= ctx->f0.fl;
    // 0x801004A8: nop

    // 0x801004AC: bc1tl       L_801004C4
    if (c1cs) {
        // 0x801004B0: sub.s       $f0, $f0, $f24
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f24.fl;
            goto L_801004C4;
    }
    goto skip_5;
    // 0x801004B0: sub.s       $f0, $f0, $f24
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f24.fl;
    skip_5:
    // 0x801004B4: trunc.w.s   $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x801004B8: mfc1        $v1, $f12
    ctx->r3 = (int32_t)ctx->f12.u32l;
    // 0x801004BC: j           L_801004D0
    // 0x801004C0: nop

        goto L_801004D0;
    // 0x801004C0: nop

L_801004C4:
    // 0x801004C4: trunc.w.s   $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x801004C8: mfc1        $v1, $f12
    ctx->r3 = (int32_t)ctx->f12.u32l;
    // 0x801004CC: or          $v1, $v1, $s7
    ctx->r3 = ctx->r3 | ctx->r23;
L_801004D0:
    // 0x801004D0: lhu         $v0, 0x2($s3)
    ctx->r2 = MEM_HU(ctx->r19, 0X2);
    // 0x801004D4: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x801004D8: sh          $v0, 0x2($a0)
    MEM_H(0X2, ctx->r4) = ctx->r2;
    // 0x801004DC: addu        $v0, $s1, $s6
    ctx->r2 = ADD32(ctx->r17, ctx->r22);
    // 0x801004E0: lwc1        $f0, 0x58($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X58);
    // 0x801004E4: lw          $a0, 0x14($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X14);
    // 0x801004E8: c.le.s      $f24, $f0
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f24.fl <= ctx->f0.fl;
    // 0x801004EC: nop

    // 0x801004F0: bc1tl       L_80100508
    if (c1cs) {
        // 0x801004F4: sub.s       $f0, $f0, $f24
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f24.fl;
            goto L_80100508;
    }
    goto skip_6;
    // 0x801004F4: sub.s       $f0, $f0, $f24
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f24.fl;
    skip_6:
    // 0x801004F8: trunc.w.s   $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x801004FC: mfc1        $v1, $f12
    ctx->r3 = (int32_t)ctx->f12.u32l;
    // 0x80100500: j           L_80100518
    // 0x80100504: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
        goto L_80100518;
    // 0x80100504: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
L_80100508:
    // 0x80100508: trunc.w.s   $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x8010050C: mfc1        $v1, $f12
    ctx->r3 = (int32_t)ctx->f12.u32l;
    // 0x80100510: or          $v1, $v1, $s7
    ctx->r3 = ctx->r3 | ctx->r23;
    // 0x80100514: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
L_80100518:
    // 0x80100518: lhu         $v0, 0x4($s3)
    ctx->r2 = MEM_HU(ctx->r19, 0X4);
    // 0x8010051C: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x80100520: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80100524: sh          $v0, 0x4($a0)
    MEM_H(0X4, ctx->r4) = ctx->r2;
    // 0x80100528: sltiu       $v0, $s2, 0x4
    ctx->r2 = ctx->r18 < 0X4 ? 1 : 0;
    // 0x8010052C: bne         $v0, $zero, L_80100444
    if (ctx->r2 != 0) {
        // 0x80100530: addiu       $s4, $s4, 0xC
        ctx->r20 = ADD32(ctx->r20, 0XC);
            goto L_80100444;
    }
    // 0x80100530: addiu       $s4, $s4, 0xC
    ctx->r20 = ADD32(ctx->r20, 0XC);
    // 0x80100534: lbu         $v0, 0x11($s6)
    ctx->r2 = MEM_BU(ctx->r22, 0X11);
    // 0x80100538: addiu       $s5, $s5, 0x1
    ctx->r21 = ADD32(ctx->r21, 0X1);
    // 0x8010053C: sltu        $v0, $s5, $v0
    ctx->r2 = ctx->r21 < ctx->r2 ? 1 : 0;
    // 0x80100540: bne         $v0, $zero, L_80100378
    if (ctx->r2 != 0) {
        // 0x80100544: addiu       $s3, $s3, 0x8
        ctx->r19 = ADD32(ctx->r19, 0X8);
            goto L_80100378;
    }
    // 0x80100544: addiu       $s3, $s3, 0x8
    ctx->r19 = ADD32(ctx->r19, 0X8);
L_80100548:
    // 0x80100548: lw          $a3, 0xA0($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XA0);
    // 0x8010054C: lwc1        $f0, 0xE8($a3)
    ctx->f0.u32l = MEM_W(ctx->r7, 0XE8);
    // 0x80100550: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x80100554: swc1        $f0, -0x2FD4($v0)
    MEM_W(-0X2FD4, ctx->r2) = ctx->f0.u32l;
L_80100558:
    // 0x80100558: lw          $ra, 0x84($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X84);
    // 0x8010055C: lw          $fp, 0x80($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X80);
    // 0x80100560: lw          $s7, 0x7C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X7C);
    // 0x80100564: lw          $s6, 0x78($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X78);
    // 0x80100568: lw          $s5, 0x74($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X74);
    // 0x8010056C: lw          $s4, 0x70($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X70);
    // 0x80100570: lw          $s3, 0x6C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X6C);
    // 0x80100574: lw          $s2, 0x68($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X68);
    // 0x80100578: lw          $s1, 0x64($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X64);
    // 0x8010057C: lw          $s0, 0x60($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X60);
    // 0x80100580: ldc1        $f24, 0x98($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X98);
    // 0x80100584: ldc1        $f22, 0x90($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X90);
    // 0x80100588: ldc1        $f20, 0x88($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X88);
    // 0x8010058C: jr          $ra
    // 0x80100590: addiu       $sp, $sp, 0xA0
    ctx->r29 = ADD32(ctx->r29, 0XA0);
    return;
    // 0x80100590: addiu       $sp, $sp, 0xA0
    ctx->r29 = ADD32(ctx->r29, 0XA0);
;}
RECOMP_FUNC void func_80100594(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80100594: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80100598: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
    // 0x8010059C: addiu       $v1, $v1, -0x30E0
    ctx->r3 = ADD32(ctx->r3, -0X30E0);
    // 0x801005A0: andi        $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 & 0XFF;
    // 0x801005A4: sll         $v0, $a0, 1
    ctx->r2 = S32(ctx->r4 << 1);
    // 0x801005A8: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x801005AC: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x801005B0: addu        $a0, $v0, $v1
    ctx->r4 = ADD32(ctx->r2, ctx->r3);
    // 0x801005B4: sw          $s3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r19;
    // 0x801005B8: addu        $s3, $zero, $zero
    ctx->r19 = ADD32(0, 0);
    // 0x801005BC: sw          $s7, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r23;
    // 0x801005C0: addu        $s7, $v1, $zero
    ctx->r23 = ADD32(ctx->r3, 0);
    // 0x801005C4: sw          $s5, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r21;
    // 0x801005C8: addu        $s5, $v0, $zero
    ctx->r21 = ADD32(ctx->r2, 0);
    // 0x801005CC: sw          $fp, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r30;
    // 0x801005D0: addu        $fp, $a0, $zero
    ctx->r30 = ADD32(ctx->r4, 0);
    // 0x801005D4: sw          $s6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r22;
    // 0x801005D8: ori         $s6, $zero, 0xFFFF
    ctx->r22 = 0 | 0XFFFF;
    // 0x801005DC: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x801005E0: sw          $s4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r20;
    // 0x801005E4: sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // 0x801005E8: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x801005EC: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x801005F0: sb          $zero, 0x10($a0)
    MEM_B(0X10, ctx->r4) = 0;
L_801005F4:
    // 0x801005F4: lw          $v0, 0x4($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X4);
    // 0x801005F8: lbu         $v0, 0x0($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X0);
    // 0x801005FC: beq         $v0, $zero, L_80100664
    if (ctx->r2 == 0) {
        // 0x80100600: addu        $s1, $zero, $zero
        ctx->r17 = ADD32(0, 0);
            goto L_80100664;
    }
    // 0x80100600: addu        $s1, $zero, $zero
    ctx->r17 = ADD32(0, 0);
    // 0x80100604: andi        $v0, $s3, 0xFF
    ctx->r2 = ctx->r19 & 0XFF;
    // 0x80100608: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8010060C: addu        $v0, $v0, $s5
    ctx->r2 = ADD32(ctx->r2, ctx->r21);
    // 0x80100610: addu        $s2, $v0, $s7
    ctx->r18 = ADD32(ctx->r2, ctx->r23);
    // 0x80100614: addu        $s4, $s5, $s7
    ctx->r20 = ADD32(ctx->r21, ctx->r23);
    // 0x80100618: andi        $v0, $s1, 0xFF
    ctx->r2 = ctx->r17 & 0XFF;
L_8010061C:
    // 0x8010061C: lw          $v1, 0x8($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X8);
    // 0x80100620: sll         $s0, $v0, 1
    ctx->r16 = S32(ctx->r2 << 1);
    // 0x80100624: addu        $v1, $s0, $v1
    ctx->r3 = ADD32(ctx->r16, ctx->r3);
    // 0x80100628: lhu         $v0, 0x0($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X0);
    // 0x8010062C: beq         $v0, $s6, L_80100648
    if (ctx->r2 == ctx->r22) {
        // 0x80100630: nop
    
            goto L_80100648;
    }
    // 0x80100630: nop

    // 0x80100634: jal         0x8003ED74
    // 0x80100638: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    func_8003ED74(rdram, ctx);
        goto after_0;
    // 0x80100638: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    after_0:
    // 0x8010063C: lw          $v0, 0x8($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X8);
    // 0x80100640: addu        $v0, $s0, $v0
    ctx->r2 = ADD32(ctx->r16, ctx->r2);
    // 0x80100644: sh          $s6, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r22;
L_80100648:
    // 0x80100648: lw          $v0, 0x4($s4)
    ctx->r2 = MEM_W(ctx->r20, 0X4);
    // 0x8010064C: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80100650: lbu         $v1, 0x0($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X0);
    // 0x80100654: andi        $v0, $s1, 0xFF
    ctx->r2 = ctx->r17 & 0XFF;
    // 0x80100658: sltu        $v0, $v0, $v1
    ctx->r2 = ctx->r2 < ctx->r3 ? 1 : 0;
    // 0x8010065C: bne         $v0, $zero, L_8010061C
    if (ctx->r2 != 0) {
        // 0x80100660: andi        $v0, $s1, 0xFF
        ctx->r2 = ctx->r17 & 0XFF;
            goto L_8010061C;
    }
    // 0x80100660: andi        $v0, $s1, 0xFF
    ctx->r2 = ctx->r17 & 0XFF;
L_80100664:
    // 0x80100664: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x80100668: andi        $v0, $s3, 0xFF
    ctx->r2 = ctx->r19 & 0XFF;
    // 0x8010066C: sltiu       $v0, $v0, 0x2
    ctx->r2 = ctx->r2 < 0X2 ? 1 : 0;
    // 0x80100670: bne         $v0, $zero, L_801005F4
    if (ctx->r2 != 0) {
        // 0x80100674: nop
    
            goto L_801005F4;
    }
    // 0x80100674: nop

    // 0x80100678: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x8010067C: lw          $fp, 0x30($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X30);
    // 0x80100680: lw          $s7, 0x2C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X2C);
    // 0x80100684: lw          $s6, 0x28($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X28);
    // 0x80100688: lw          $s5, 0x24($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X24);
    // 0x8010068C: lw          $s4, 0x20($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X20);
    // 0x80100690: lw          $s3, 0x1C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X1C);
    // 0x80100694: lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X18);
    // 0x80100698: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x8010069C: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x801006A0: jr          $ra
    // 0x801006A4: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x801006A4: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_801006A8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801006A8: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x801006AC: lui         $a1, 0x8011
    ctx->r5 = S32(0X8011 << 16);
    // 0x801006B0: addiu       $a1, $a1, -0x30E0
    ctx->r5 = ADD32(ctx->r5, -0X30E0);
    // 0x801006B4: andi        $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 & 0XFF;
    // 0x801006B8: sll         $v1, $a0, 1
    ctx->r3 = S32(ctx->r4 << 1);
    // 0x801006BC: addu        $v1, $v1, $a0
    ctx->r3 = ADD32(ctx->r3, ctx->r4);
    // 0x801006C0: sll         $v1, $v1, 3
    ctx->r3 = S32(ctx->r3 << 3);
    // 0x801006C4: addu        $a0, $v1, $a1
    ctx->r4 = ADD32(ctx->r3, ctx->r5);
    // 0x801006C8: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x801006CC: sw          $s3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r19;
    // 0x801006D0: addu        $s3, $zero, $zero
    ctx->r19 = ADD32(0, 0);
    // 0x801006D4: sw          $s7, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r23;
    // 0x801006D8: addu        $s7, $a1, $zero
    ctx->r23 = ADD32(ctx->r5, 0);
    // 0x801006DC: sw          $s5, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r21;
    // 0x801006E0: addu        $s5, $v1, $zero
    ctx->r21 = ADD32(ctx->r3, 0);
    // 0x801006E4: sw          $fp, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r30;
    // 0x801006E8: addu        $fp, $a0, $zero
    ctx->r30 = ADD32(ctx->r4, 0);
    // 0x801006EC: sw          $s6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r22;
    // 0x801006F0: ori         $s6, $zero, 0xFFFF
    ctx->r22 = 0 | 0XFFFF;
    // 0x801006F4: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x801006F8: sw          $s4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r20;
    // 0x801006FC: sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // 0x80100700: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x80100704: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x80100708: sb          $v0, 0x10($a0)
    MEM_B(0X10, ctx->r4) = ctx->r2;
L_8010070C:
    // 0x8010070C: lw          $v0, 0x4($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X4);
    // 0x80100710: lbu         $v0, 0x0($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X0);
    // 0x80100714: beq         $v0, $zero, L_8010077C
    if (ctx->r2 == 0) {
        // 0x80100718: addu        $s1, $zero, $zero
        ctx->r17 = ADD32(0, 0);
            goto L_8010077C;
    }
    // 0x80100718: addu        $s1, $zero, $zero
    ctx->r17 = ADD32(0, 0);
    // 0x8010071C: andi        $v0, $s3, 0xFF
    ctx->r2 = ctx->r19 & 0XFF;
    // 0x80100720: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80100724: addu        $v0, $v0, $s5
    ctx->r2 = ADD32(ctx->r2, ctx->r21);
    // 0x80100728: addu        $s2, $v0, $s7
    ctx->r18 = ADD32(ctx->r2, ctx->r23);
    // 0x8010072C: addu        $s4, $s5, $s7
    ctx->r20 = ADD32(ctx->r21, ctx->r23);
    // 0x80100730: andi        $v0, $s1, 0xFF
    ctx->r2 = ctx->r17 & 0XFF;
L_80100734:
    // 0x80100734: lw          $v1, 0x8($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X8);
    // 0x80100738: sll         $s0, $v0, 1
    ctx->r16 = S32(ctx->r2 << 1);
    // 0x8010073C: addu        $v1, $s0, $v1
    ctx->r3 = ADD32(ctx->r16, ctx->r3);
    // 0x80100740: lhu         $v0, 0x0($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X0);
    // 0x80100744: beq         $v0, $s6, L_80100760
    if (ctx->r2 == ctx->r22) {
        // 0x80100748: nop
    
            goto L_80100760;
    }
    // 0x80100748: nop

    // 0x8010074C: jal         0x8003ED74
    // 0x80100750: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    func_8003ED74(rdram, ctx);
        goto after_0;
    // 0x80100750: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    after_0:
    // 0x80100754: lw          $v0, 0x8($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X8);
    // 0x80100758: addu        $v0, $s0, $v0
    ctx->r2 = ADD32(ctx->r16, ctx->r2);
    // 0x8010075C: sh          $s6, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r22;
L_80100760:
    // 0x80100760: lw          $v0, 0x4($s4)
    ctx->r2 = MEM_W(ctx->r20, 0X4);
    // 0x80100764: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80100768: lbu         $v1, 0x0($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X0);
    // 0x8010076C: andi        $v0, $s1, 0xFF
    ctx->r2 = ctx->r17 & 0XFF;
    // 0x80100770: sltu        $v0, $v0, $v1
    ctx->r2 = ctx->r2 < ctx->r3 ? 1 : 0;
    // 0x80100774: bne         $v0, $zero, L_80100734
    if (ctx->r2 != 0) {
        // 0x80100778: andi        $v0, $s1, 0xFF
        ctx->r2 = ctx->r17 & 0XFF;
            goto L_80100734;
    }
    // 0x80100778: andi        $v0, $s1, 0xFF
    ctx->r2 = ctx->r17 & 0XFF;
L_8010077C:
    // 0x8010077C: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x80100780: andi        $v0, $s3, 0xFF
    ctx->r2 = ctx->r19 & 0XFF;
    // 0x80100784: sltiu       $v0, $v0, 0x2
    ctx->r2 = ctx->r2 < 0X2 ? 1 : 0;
    // 0x80100788: bne         $v0, $zero, L_8010070C
    if (ctx->r2 != 0) {
        // 0x8010078C: nop
    
            goto L_8010070C;
    }
    // 0x8010078C: nop

    // 0x80100790: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x80100794: lw          $fp, 0x30($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X30);
    // 0x80100798: lw          $s7, 0x2C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X2C);
    // 0x8010079C: lw          $s6, 0x28($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X28);
    // 0x801007A0: lw          $s5, 0x24($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X24);
    // 0x801007A4: lw          $s4, 0x20($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X20);
    // 0x801007A8: lw          $s3, 0x1C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X1C);
    // 0x801007AC: lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X18);
    // 0x801007B0: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x801007B4: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x801007B8: jr          $ra
    // 0x801007BC: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x801007BC: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_801007C0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801007C0: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x801007C4: sw          $s5, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r21;
    // 0x801007C8: addu        $s5, $a0, $zero
    ctx->r21 = ADD32(ctx->r4, 0);
    // 0x801007CC: sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // 0x801007D0: addu        $s2, $a2, $zero
    ctx->r18 = ADD32(ctx->r6, 0);
    // 0x801007D4: sw          $s4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r20;
    // 0x801007D8: addu        $s4, $a1, $zero
    ctx->r20 = ADD32(ctx->r5, 0);
    // 0x801007DC: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x801007E0: sw          $s3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r19;
    // 0x801007E4: addiu       $s3, $v0, -0x30E0
    ctx->r19 = ADD32(ctx->r2, -0X30E0);
    // 0x801007E8: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x801007EC: andi        $s1, $s4, 0xFF
    ctx->r17 = ctx->r20 & 0XFF;
    // 0x801007F0: sll         $v0, $s1, 1
    ctx->r2 = S32(ctx->r17 << 1);
    // 0x801007F4: addu        $v0, $v0, $s1
    ctx->r2 = ADD32(ctx->r2, ctx->r17);
    // 0x801007F8: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x801007FC: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x80100800: addu        $s0, $v0, $s3
    ctx->r16 = ADD32(ctx->r2, ctx->r19);
    // 0x80100804: sw          $ra, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r31;
    // 0x80100808: sw          $s2, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r18;
    // 0x8010080C: sw          $s5, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r21;
    // 0x80100810: lbu         $v0, 0x0($s2)
    ctx->r2 = MEM_BU(ctx->r18, 0X0);
    // 0x80100814: beq         $v0, $zero, L_80100924
    if (ctx->r2 == 0) {
        // 0x80100818: addu        $a0, $v0, $zero
        ctx->r4 = ADD32(ctx->r2, 0);
            goto L_80100924;
    }
    // 0x80100818: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // 0x8010081C: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x80100820: jal         0x80001ACC
    // 0x80100824: sll         $a0, $a0, 1
    ctx->r4 = S32(ctx->r4 << 1);
    rs_malloc(rdram, ctx);
        goto after_0;
    // 0x80100824: sll         $a0, $a0, 1
    ctx->r4 = S32(ctx->r4 << 1);
    after_0:
    // 0x80100828: sw          $v0, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r2;
    // 0x8010082C: lbu         $a0, 0x0($s2)
    ctx->r4 = MEM_BU(ctx->r18, 0X0);
    // 0x80100830: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x80100834: jal         0x80001ACC
    // 0x80100838: sll         $a0, $a0, 1
    ctx->r4 = S32(ctx->r4 << 1);
    rs_malloc(rdram, ctx);
        goto after_1;
    // 0x80100838: sll         $a0, $a0, 1
    ctx->r4 = S32(ctx->r4 << 1);
    after_1:
    // 0x8010083C: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    // 0x80100840: addu        $t2, $s3, $zero
    ctx->r10 = ADD32(ctx->r19, 0);
    // 0x80100844: addu        $t4, $s1, $zero
    ctx->r12 = ADD32(ctx->r17, 0);
    // 0x80100848: addu        $t1, $s0, $zero
    ctx->r9 = ADD32(ctx->r16, 0);
    // 0x8010084C: addu        $t5, $zero, $zero
    ctx->r13 = ADD32(0, 0);
    // 0x80100850: ori         $t3, $zero, 0xFFFF
    ctx->r11 = 0 | 0XFFFF;
    // 0x80100854: sw          $v0, 0xC($t1)
    MEM_W(0XC, ctx->r9) = ctx->r2;
L_80100858:
    // 0x80100858: lw          $v0, 0x4($t1)
    ctx->r2 = MEM_W(ctx->r9, 0X4);
    // 0x8010085C: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x80100860: lbu         $v0, 0x0($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X0);
    // 0x80100864: sltu        $v0, $t5, $v0
    ctx->r2 = ctx->r13 < ctx->r2 ? 1 : 0;
    // 0x80100868: beq         $v0, $zero, L_801008C0
    if (ctx->r2 == 0) {
        // 0x8010086C: addu        $a2, $t4, $zero
        ctx->r6 = ADD32(ctx->r12, 0);
            goto L_801008C0;
    }
    // 0x8010086C: addu        $a2, $t4, $zero
    ctx->r6 = ADD32(ctx->r12, 0);
    // 0x80100870: andi        $v0, $a3, 0xFF
    ctx->r2 = ctx->r7 & 0XFF;
    // 0x80100874: sll         $t0, $v0, 2
    ctx->r8 = S32(ctx->r2 << 2);
    // 0x80100878: sll         $a0, $a2, 1
    ctx->r4 = S32(ctx->r6 << 1);
L_8010087C:
    // 0x8010087C: addu        $a0, $a0, $a2
    ctx->r4 = ADD32(ctx->r4, ctx->r6);
    // 0x80100880: sll         $a0, $a0, 3
    ctx->r4 = S32(ctx->r4 << 3);
    // 0x80100884: addu        $v1, $t0, $a0
    ctx->r3 = ADD32(ctx->r8, ctx->r4);
    // 0x80100888: addu        $v1, $v1, $t2
    ctx->r3 = ADD32(ctx->r3, ctx->r10);
    // 0x8010088C: andi        $v0, $a1, 0xFF
    ctx->r2 = ctx->r5 & 0XFF;
    // 0x80100890: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x80100894: lw          $v1, 0x8($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X8);
    // 0x80100898: addu        $a0, $a0, $t2
    ctx->r4 = ADD32(ctx->r4, ctx->r10);
    // 0x8010089C: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x801008A0: sh          $t3, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r11;
    // 0x801008A4: lw          $v0, 0x4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X4);
    // 0x801008A8: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x801008AC: lbu         $v1, 0x0($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X0);
    // 0x801008B0: andi        $v0, $a1, 0xFF
    ctx->r2 = ctx->r5 & 0XFF;
    // 0x801008B4: sltu        $v0, $v0, $v1
    ctx->r2 = ctx->r2 < ctx->r3 ? 1 : 0;
    // 0x801008B8: bne         $v0, $zero, L_8010087C
    if (ctx->r2 != 0) {
        // 0x801008BC: sll         $a0, $a2, 1
        ctx->r4 = S32(ctx->r6 << 1);
            goto L_8010087C;
    }
    // 0x801008BC: sll         $a0, $a2, 1
    ctx->r4 = S32(ctx->r6 << 1);
L_801008C0:
    // 0x801008C0: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x801008C4: andi        $v0, $a3, 0xFF
    ctx->r2 = ctx->r7 & 0XFF;
    // 0x801008C8: sltiu       $v0, $v0, 0x2
    ctx->r2 = ctx->r2 < 0X2 ? 1 : 0;
    // 0x801008CC: bne         $v0, $zero, L_80100858
    if (ctx->r2 != 0) {
        // 0x801008D0: andi        $s0, $s4, 0xFF
        ctx->r16 = ctx->r20 & 0XFF;
            goto L_80100858;
    }
    // 0x801008D0: andi        $s0, $s4, 0xFF
    ctx->r16 = ctx->r20 & 0XFF;
    // 0x801008D4: jal         0x80100594
    // 0x801008D8: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_80100594(rdram, ctx);
        goto after_2;
    // 0x801008D8: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_2:
    // 0x801008DC: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
    // 0x801008E0: addiu       $v1, $v1, -0x30E0
    ctx->r3 = ADD32(ctx->r3, -0X30E0);
    // 0x801008E4: sll         $v0, $s0, 1
    ctx->r2 = S32(ctx->r16 << 1);
    // 0x801008E8: addu        $v0, $v0, $s0
    ctx->r2 = ADD32(ctx->r2, ctx->r16);
    // 0x801008EC: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x801008F0: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x801008F4: lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X0);
    // 0x801008F8: sb          $zero, 0x10($v0)
    MEM_B(0X10, ctx->r2) = 0;
    // 0x801008FC: sb          $zero, 0x11($v0)
    MEM_B(0X11, ctx->r2) = 0;
    // 0x80100900: sb          $zero, 0x12($v0)
    MEM_B(0X12, ctx->r2) = 0;
    // 0x80100904: sb          $zero, 0x13($v0)
    MEM_B(0X13, ctx->r2) = 0;
    // 0x80100908: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x8010090C: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80100910: lwc1        $f0, -0x6B10($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X6B10);
    // 0x80100914: lwc1        $f2, 0xE8($v1)
    ctx->f2.u32l = MEM_W(ctx->r3, 0XE8);
    // 0x80100918: addiu       $v0, $v0, -0x30C8
    ctx->r2 = ADD32(ctx->r2, -0X30C8);
    // 0x8010091C: swc1        $f0, 0xF8($v0)
    MEM_W(0XF8, ctx->r2) = ctx->f0.u32l;
    // 0x80100920: swc1        $f2, 0xF4($v0)
    MEM_W(0XF4, ctx->r2) = ctx->f2.u32l;
L_80100924:
    // 0x80100924: jal         0x800FFE00
    // 0x80100928: addu        $a0, $s5, $zero
    ctx->r4 = ADD32(ctx->r21, 0);
    func_800FFE00(rdram, ctx);
        goto after_3;
    // 0x80100928: addu        $a0, $s5, $zero
    ctx->r4 = ADD32(ctx->r21, 0);
    after_3:
    // 0x8010092C: lw          $ra, 0x28($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X28);
    // 0x80100930: lw          $s5, 0x24($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X24);
    // 0x80100934: lw          $s4, 0x20($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X20);
    // 0x80100938: lw          $s3, 0x1C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X1C);
    // 0x8010093C: lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X18);
    // 0x80100940: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x80100944: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x80100948: jr          $ra
    // 0x8010094C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x8010094C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_80100950(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80100950: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x80100954: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80100958: sdc1        $f24, 0x58($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X58, ctx->r29);
    // 0x8010095C: mtc1        $a1, $f24
    ctx->f24.u32l = ctx->r5;
    // 0x80100960: lw          $v1, 0xB70($v0)
    ctx->r3 = MEM_W(ctx->r2, 0XB70);
    // 0x80100964: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
    // 0x80100968: sw          $ra, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r31;
    // 0x8010096C: sw          $s7, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r23;
    // 0x80100970: sw          $s6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r22;
    // 0x80100974: sw          $s5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r21;
    // 0x80100978: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x8010097C: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x80100980: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x80100984: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x80100988: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8010098C: sdc1        $f22, 0x50($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X50, ctx->r29);
    // 0x80100990: sdc1        $f20, 0x48($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X48, ctx->r29);
    // 0x80100994: beq         $v1, $v0, L_801009A4
    if (ctx->r3 == ctx->r2) {
        // 0x80100998: addiu       $v0, $zero, 0x11
        ctx->r2 = ADD32(0, 0X11);
            goto L_801009A4;
    }
    // 0x80100998: addiu       $v0, $zero, 0x11
    ctx->r2 = ADD32(0, 0X11);
    // 0x8010099C: bne         $v1, $v0, L_801009A8
    if (ctx->r3 != ctx->r2) {
        // 0x801009A0: addiu       $s4, $zero, 0x1
        ctx->r20 = ADD32(0, 0X1);
            goto L_801009A8;
    }
    // 0x801009A0: addiu       $s4, $zero, 0x1
    ctx->r20 = ADD32(0, 0X1);
L_801009A4:
    // 0x801009A4: addu        $s4, $zero, $zero
    ctx->r20 = ADD32(0, 0);
L_801009A8:
    // 0x801009A8: andi        $v0, $a0, 0xFF
    ctx->r2 = ctx->r4 & 0XFF;
    // 0x801009AC: sll         $v1, $v0, 1
    ctx->r3 = S32(ctx->r2 << 1);
    // 0x801009B0: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x801009B4: sll         $v1, $v1, 3
    ctx->r3 = S32(ctx->r3 << 3);
    // 0x801009B8: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x801009BC: addiu       $v0, $v0, -0x30E0
    ctx->r2 = ADD32(ctx->r2, -0X30E0);
    // 0x801009C0: addu        $s1, $v1, $v0
    ctx->r17 = ADD32(ctx->r3, ctx->r2);
    // 0x801009C4: lw          $v0, 0x4($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X4);
    // 0x801009C8: lbu         $a0, 0x0($v0)
    ctx->r4 = MEM_BU(ctx->r2, 0X0);
    // 0x801009CC: beq         $a0, $zero, L_80100EF8
    if (ctx->r4 == 0) {
        // 0x801009D0: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80100EF8;
    }
    // 0x801009D0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x801009D4: lbu         $v1, 0x10($s1)
    ctx->r3 = MEM_BU(ctx->r17, 0X10);
    // 0x801009D8: beq         $v1, $v0, L_80100BD8
    if (ctx->r3 == ctx->r2) {
        // 0x801009DC: slti        $v0, $v1, 0x2
        ctx->r2 = SIGNED(ctx->r3) < 0X2 ? 1 : 0;
            goto L_80100BD8;
    }
    // 0x801009DC: slti        $v0, $v1, 0x2
    ctx->r2 = SIGNED(ctx->r3) < 0X2 ? 1 : 0;
    // 0x801009E0: beq         $v0, $zero, L_80100CA0
    if (ctx->r2 == 0) {
        // 0x801009E4: andi        $v0, $s4, 0xFF
        ctx->r2 = ctx->r20 & 0XFF;
            goto L_80100CA0;
    }
    // 0x801009E4: andi        $v0, $s4, 0xFF
    ctx->r2 = ctx->r20 & 0XFF;
    // 0x801009E8: bne         $v1, $zero, L_80100CA0
    if (ctx->r3 != 0) {
        // 0x801009EC: nop
    
            goto L_80100CA0;
    }
    // 0x801009EC: nop

    // 0x801009F0: lbu         $v0, 0x12($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X12);
    // 0x801009F4: beq         $v0, $zero, L_80100C9C
    if (ctx->r2 == 0) {
        // 0x801009F8: sltu        $v0, $v1, $a0
        ctx->r2 = ctx->r3 < ctx->r4 ? 1 : 0;
            goto L_80100C9C;
    }
    // 0x801009F8: sltu        $v0, $v1, $a0
    ctx->r2 = ctx->r3 < ctx->r4 ? 1 : 0;
    // 0x801009FC: beq         $v0, $zero, L_80100BC4
    if (ctx->r2 == 0) {
        // 0x80100A00: addu        $s2, $zero, $zero
        ctx->r18 = ADD32(0, 0);
            goto L_80100BC4;
    }
    // 0x80100A00: addu        $s2, $zero, $zero
    ctx->r18 = ADD32(0, 0);
    // 0x80100A04: addiu       $s3, $zero, 0x1
    ctx->r19 = ADD32(0, 0X1);
    // 0x80100A08: lui         $s5, 0x8000
    ctx->r21 = S32(0X8000 << 16);
    // 0x80100A0C: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x80100A10: addiu       $s7, $v0, -0x4AEC
    ctx->r23 = ADD32(ctx->r2, -0X4AEC);
    // 0x80100A14: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x80100A18: addiu       $s6, $v0, -0x4ADC
    ctx->r22 = ADD32(ctx->r2, -0X4ADC);
    // 0x80100A1C: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80100A20: lwc1        $f22, -0x6B0C($at)
    ctx->f22.u32l = MEM_W(ctx->r1, -0X6B0C);
    // 0x80100A24: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80100A28: lwc1        $f20, -0x6B08($at)
    ctx->f20.u32l = MEM_W(ctx->r1, -0X6B08);
L_80100A2C:
    // 0x80100A2C: lw          $v1, 0x4($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X4);
    // 0x80100A30: andi        $v0, $s2, 0xFF
    ctx->r2 = ctx->r18 & 0XFF;
    // 0x80100A34: lw          $v1, 0x4($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X4);
    // 0x80100A38: sll         $v0, $v0, 4
    ctx->r2 = S32(ctx->r2 << 4);
    // 0x80100A3C: addu        $a0, $v0, $v1
    ctx->r4 = ADD32(ctx->r2, ctx->r3);
    // 0x80100A40: lbu         $v1, 0x5($a0)
    ctx->r3 = MEM_BU(ctx->r4, 0X5);
    // 0x80100A44: andi        $v0, $v1, 0x1
    ctx->r2 = ctx->r3 & 0X1;
    // 0x80100A48: beq         $v0, $zero, L_80100BA8
    if (ctx->r2 == 0) {
        // 0x80100A4C: andi        $v0, $s4, 0xFF
        ctx->r2 = ctx->r20 & 0XFF;
            goto L_80100BA8;
    }
    // 0x80100A4C: andi        $v0, $s4, 0xFF
    ctx->r2 = ctx->r20 & 0XFF;
    // 0x80100A50: bne         $v0, $zero, L_80100A60
    if (ctx->r2 != 0) {
        // 0x80100A54: andi        $v0, $v1, 0xF0
        ctx->r2 = ctx->r3 & 0XF0;
            goto L_80100A60;
    }
    // 0x80100A54: andi        $v0, $v1, 0xF0
    ctx->r2 = ctx->r3 & 0XF0;
    // 0x80100A58: beq         $v0, $zero, L_80100BA8
    if (ctx->r2 == 0) {
        // 0x80100A5C: nop
    
            goto L_80100BA8;
    }
    // 0x80100A5C: nop

L_80100A60:
    // 0x80100A60: lbu         $v0, 0x12($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X12);
    // 0x80100A64: bne         $v0, $s3, L_80100AFC
    if (ctx->r2 != ctx->r19) {
        // 0x80100A68: nop
    
            goto L_80100AFC;
    }
    // 0x80100A68: nop

    // 0x80100A6C: lwc1        $f2, 0xC($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0XC);
    // 0x80100A70: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80100A74: lwc1        $f0, -0x6B04($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X6B04);
    // 0x80100A78: mul.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x80100A7C: lwc1        $f0, 0x8($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X8);
    // 0x80100A80: mul.s       $f4, $f0, $f22
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f22.fl);
    // 0x80100A84: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x80100A88: lhu         $a0, 0xB6($v0)
    ctx->r4 = MEM_HU(ctx->r2, 0XB6);
    // 0x80100A8C: c.le.s      $f20, $f2
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f20.fl <= ctx->f2.fl;
    // 0x80100A90: nop

    // 0x80100A94: bc1tl       L_80100AAC
    if (c1cs) {
        // 0x80100A98: sub.s       $f0, $f2, $f20
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = ctx->f2.fl - ctx->f20.fl;
            goto L_80100AAC;
    }
    goto skip_0;
    // 0x80100A98: sub.s       $f0, $f2, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = ctx->f2.fl - ctx->f20.fl;
    skip_0:
    // 0x80100A9C: trunc.w.s   $f6, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    ctx->f6.u32l = TRUNC_W_S(ctx->f2.fl);
    // 0x80100AA0: mfc1        $t0, $f6
    ctx->r8 = (int32_t)ctx->f6.u32l;
    // 0x80100AA4: j           L_80100AB8
    // 0x80100AA8: nop

        goto L_80100AB8;
    // 0x80100AA8: nop

L_80100AAC:
    // 0x80100AAC: trunc.w.s   $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    ctx->f6.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x80100AB0: mfc1        $t0, $f6
    ctx->r8 = (int32_t)ctx->f6.u32l;
    // 0x80100AB4: or          $t0, $t0, $s5
    ctx->r8 = ctx->r8 | ctx->r21;
L_80100AB8:
    // 0x80100AB8: lw          $v0, 0x4($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X4);
    // 0x80100ABC: andi        $s0, $s2, 0xFF
    ctx->r16 = ctx->r18 & 0XFF;
    // 0x80100AC0: lw          $a2, 0x4($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X4);
    // 0x80100AC4: sll         $v1, $s0, 4
    ctx->r3 = S32(ctx->r16 << 4);
    // 0x80100AC8: addu        $a2, $v1, $a2
    ctx->r6 = ADD32(ctx->r3, ctx->r6);
    // 0x80100ACC: lbu         $v0, 0x4($a2)
    ctx->r2 = MEM_BU(ctx->r6, 0X4);
    // 0x80100AD0: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // 0x80100AD4: lw          $v0, 0x4($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X4);
    // 0x80100AD8: lw          $v0, 0x4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X4);
    // 0x80100ADC: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x80100AE0: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x80100AE4: lbu         $v0, 0x5($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X5);
    // 0x80100AE8: sw          $s3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r19;
    // 0x80100AEC: srl         $v0, $v0, 4
    ctx->r2 = S32(U32(ctx->r2) >> 4);
    // 0x80100AF0: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80100AF4: j           L_80100B88
    // 0x80100AF8: addu        $v0, $v0, $s7
    ctx->r2 = ADD32(ctx->r2, ctx->r23);
        goto L_80100B88;
    // 0x80100AF8: addu        $v0, $v0, $s7
    ctx->r2 = ADD32(ctx->r2, ctx->r23);
L_80100AFC:
    // 0x80100AFC: lwc1        $f2, 0xC($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0XC);
    // 0x80100B00: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80100B04: lwc1        $f0, -0x6B00($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X6B00);
    // 0x80100B08: mul.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x80100B0C: lwc1        $f0, 0x8($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X8);
    // 0x80100B10: mul.s       $f4, $f0, $f22
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f22.fl);
    // 0x80100B14: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x80100B18: lhu         $a0, 0xB6($v0)
    ctx->r4 = MEM_HU(ctx->r2, 0XB6);
    // 0x80100B1C: c.le.s      $f20, $f2
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f20.fl <= ctx->f2.fl;
    // 0x80100B20: nop

    // 0x80100B24: bc1tl       L_80100B3C
    if (c1cs) {
        // 0x80100B28: sub.s       $f0, $f2, $f20
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = ctx->f2.fl - ctx->f20.fl;
            goto L_80100B3C;
    }
    goto skip_1;
    // 0x80100B28: sub.s       $f0, $f2, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = ctx->f2.fl - ctx->f20.fl;
    skip_1:
    // 0x80100B2C: trunc.w.s   $f6, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    ctx->f6.u32l = TRUNC_W_S(ctx->f2.fl);
    // 0x80100B30: mfc1        $t0, $f6
    ctx->r8 = (int32_t)ctx->f6.u32l;
    // 0x80100B34: j           L_80100B48
    // 0x80100B38: nop

        goto L_80100B48;
    // 0x80100B38: nop

L_80100B3C:
    // 0x80100B3C: trunc.w.s   $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    ctx->f6.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x80100B40: mfc1        $t0, $f6
    ctx->r8 = (int32_t)ctx->f6.u32l;
    // 0x80100B44: or          $t0, $t0, $s5
    ctx->r8 = ctx->r8 | ctx->r21;
L_80100B48:
    // 0x80100B48: lw          $v0, 0x4($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X4);
    // 0x80100B4C: andi        $s0, $s2, 0xFF
    ctx->r16 = ctx->r18 & 0XFF;
    // 0x80100B50: lw          $a2, 0x4($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X4);
    // 0x80100B54: sll         $v1, $s0, 4
    ctx->r3 = S32(ctx->r16 << 4);
    // 0x80100B58: addu        $a2, $v1, $a2
    ctx->r6 = ADD32(ctx->r3, ctx->r6);
    // 0x80100B5C: lbu         $v0, 0x4($a2)
    ctx->r2 = MEM_BU(ctx->r6, 0X4);
    // 0x80100B60: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // 0x80100B64: lw          $v0, 0x4($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X4);
    // 0x80100B68: lw          $v0, 0x4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X4);
    // 0x80100B6C: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x80100B70: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x80100B74: lbu         $v0, 0x5($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X5);
    // 0x80100B78: sw          $s3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r19;
    // 0x80100B7C: srl         $v0, $v0, 4
    ctx->r2 = S32(U32(ctx->r2) >> 4);
    // 0x80100B80: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80100B84: addu        $v0, $v0, $s6
    ctx->r2 = ADD32(ctx->r2, ctx->r22);
L_80100B88:
    // 0x80100B88: sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    // 0x80100B8C: lw          $a3, 0x0($a2)
    ctx->r7 = MEM_W(ctx->r6, 0X0);
    // 0x80100B90: jal         0x80072988
    // 0x80100B94: andi        $a2, $t0, 0xFF
    ctx->r6 = ctx->r8 & 0XFF;
    func_80072988(rdram, ctx);
        goto after_0;
    // 0x80100B94: andi        $a2, $t0, 0xFF
    ctx->r6 = ctx->r8 & 0XFF;
    after_0:
    // 0x80100B98: lw          $v1, 0x8($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X8);
    // 0x80100B9C: sll         $s0, $s0, 1
    ctx->r16 = S32(ctx->r16 << 1);
    // 0x80100BA0: addu        $s0, $s0, $v1
    ctx->r16 = ADD32(ctx->r16, ctx->r3);
    // 0x80100BA4: sh          $v0, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r2;
L_80100BA8:
    // 0x80100BA8: lw          $v0, 0x4($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X4);
    // 0x80100BAC: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x80100BB0: lbu         $v1, 0x0($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X0);
    // 0x80100BB4: andi        $v0, $s2, 0xFF
    ctx->r2 = ctx->r18 & 0XFF;
    // 0x80100BB8: sltu        $v0, $v0, $v1
    ctx->r2 = ctx->r2 < ctx->r3 ? 1 : 0;
    // 0x80100BBC: bne         $v0, $zero, L_80100A2C
    if (ctx->r2 != 0) {
        // 0x80100BC0: nop
    
            goto L_80100A2C;
    }
    // 0x80100BC0: nop

L_80100BC4:
    // 0x80100BC4: lbu         $v1, 0x12($s1)
    ctx->r3 = MEM_BU(ctx->r17, 0X12);
    // 0x80100BC8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80100BCC: sb          $v0, 0x10($s1)
    MEM_B(0X10, ctx->r17) = ctx->r2;
    // 0x80100BD0: j           L_80100C9C
    // 0x80100BD4: sb          $v1, 0x13($s1)
    MEM_B(0X13, ctx->r17) = ctx->r3;
        goto L_80100C9C;
    // 0x80100BD4: sb          $v1, 0x13($s1)
    MEM_B(0X13, ctx->r17) = ctx->r3;
L_80100BD8:
    // 0x80100BD8: lwc1        $f0, 0x14($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X14);
    // 0x80100BDC: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x80100BE0: c.eq.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl == ctx->f2.fl;
    // 0x80100BE4: nop

    // 0x80100BE8: bc1t        L_80100C0C
    if (c1cs) {
        // 0x80100BEC: nop
    
            goto L_80100C0C;
    }
    // 0x80100BEC: nop

    // 0x80100BF0: sub.s       $f0, $f0, $f24
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f24.fl;
    // 0x80100BF4: c.le.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl <= ctx->f2.fl;
    // 0x80100BF8: nop

    // 0x80100BFC: bc1f        L_80100C0C
    if (!c1cs) {
        // 0x80100C00: swc1        $f0, 0x14($s1)
        MEM_W(0X14, ctx->r17) = ctx->f0.u32l;
            goto L_80100C0C;
    }
    // 0x80100C00: swc1        $f0, 0x14($s1)
    MEM_W(0X14, ctx->r17) = ctx->f0.u32l;
    // 0x80100C04: j           L_80100C1C
    // 0x80100C08: sb          $zero, 0x12($s1)
    MEM_B(0X12, ctx->r17) = 0;
        goto L_80100C1C;
    // 0x80100C08: sb          $zero, 0x12($s1)
    MEM_B(0X12, ctx->r17) = 0;
L_80100C0C:
    // 0x80100C0C: lbu         $v1, 0x12($s1)
    ctx->r3 = MEM_BU(ctx->r17, 0X12);
    // 0x80100C10: lbu         $v0, 0x13($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X13);
    // 0x80100C14: beq         $v1, $v0, L_80100CA0
    if (ctx->r3 == ctx->r2) {
        // 0x80100C18: andi        $v0, $s4, 0xFF
        ctx->r2 = ctx->r20 & 0XFF;
            goto L_80100CA0;
    }
    // 0x80100C18: andi        $v0, $s4, 0xFF
    ctx->r2 = ctx->r20 & 0XFF;
L_80100C1C:
    // 0x80100C1C: lw          $a0, 0x4($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X4);
    // 0x80100C20: lbu         $v0, 0x0($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X0);
    // 0x80100C24: beq         $v0, $zero, L_80100C94
    if (ctx->r2 == 0) {
        // 0x80100C28: addu        $s2, $zero, $zero
        ctx->r18 = ADD32(0, 0);
            goto L_80100C94;
    }
    // 0x80100C28: addu        $s2, $zero, $zero
    ctx->r18 = ADD32(0, 0);
    // 0x80100C2C: ori         $s3, $zero, 0xFFFF
    ctx->r19 = 0 | 0XFFFF;
    // 0x80100C30: andi        $a1, $s2, 0xFF
    ctx->r5 = ctx->r18 & 0XFF;
L_80100C34:
    // 0x80100C34: lw          $v0, 0x4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X4);
    // 0x80100C38: sll         $v1, $a1, 4
    ctx->r3 = S32(ctx->r5 << 4);
    // 0x80100C3C: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x80100C40: lbu         $v0, 0x5($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X5);
    // 0x80100C44: andi        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 & 0X1;
    // 0x80100C48: beq         $v0, $zero, L_80100C78
    if (ctx->r2 == 0) {
        // 0x80100C4C: sll         $s0, $a1, 1
        ctx->r16 = S32(ctx->r5 << 1);
            goto L_80100C78;
    }
    // 0x80100C4C: sll         $s0, $a1, 1
    ctx->r16 = S32(ctx->r5 << 1);
    // 0x80100C50: lw          $v0, 0x8($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X8);
    // 0x80100C54: addu        $v1, $s0, $v0
    ctx->r3 = ADD32(ctx->r16, ctx->r2);
    // 0x80100C58: lhu         $v0, 0x0($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X0);
    // 0x80100C5C: beq         $v0, $s3, L_80100C78
    if (ctx->r2 == ctx->r19) {
        // 0x80100C60: nop
    
            goto L_80100C78;
    }
    // 0x80100C60: nop

    // 0x80100C64: jal         0x80072ACC
    // 0x80100C68: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    func_80072ACC(rdram, ctx);
        goto after_1;
    // 0x80100C68: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    after_1:
    // 0x80100C6C: lw          $v0, 0x8($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X8);
    // 0x80100C70: addu        $v0, $s0, $v0
    ctx->r2 = ADD32(ctx->r16, ctx->r2);
    // 0x80100C74: sh          $s3, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r19;
L_80100C78:
    // 0x80100C78: lw          $a0, 0x4($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X4);
    // 0x80100C7C: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x80100C80: lbu         $v1, 0x0($a0)
    ctx->r3 = MEM_BU(ctx->r4, 0X0);
    // 0x80100C84: andi        $v0, $s2, 0xFF
    ctx->r2 = ctx->r18 & 0XFF;
    // 0x80100C88: sltu        $v0, $v0, $v1
    ctx->r2 = ctx->r2 < ctx->r3 ? 1 : 0;
    // 0x80100C8C: bne         $v0, $zero, L_80100C34
    if (ctx->r2 != 0) {
        // 0x80100C90: andi        $a1, $s2, 0xFF
        ctx->r5 = ctx->r18 & 0XFF;
            goto L_80100C34;
    }
    // 0x80100C90: andi        $a1, $s2, 0xFF
    ctx->r5 = ctx->r18 & 0XFF;
L_80100C94:
    // 0x80100C94: sb          $zero, 0x13($s1)
    MEM_B(0X13, ctx->r17) = 0;
    // 0x80100C98: sb          $zero, 0x10($s1)
    MEM_B(0X10, ctx->r17) = 0;
L_80100C9C:
    // 0x80100C9C: andi        $v0, $s4, 0xFF
    ctx->r2 = ctx->r20 & 0XFF;
L_80100CA0:
    // 0x80100CA0: beq         $v0, $zero, L_80100EF8
    if (ctx->r2 == 0) {
        // 0x80100CA4: nop
    
            goto L_80100EF8;
    }
    // 0x80100CA4: nop

    // 0x80100CA8: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x80100CAC: lhu         $v1, 0xB4($v0)
    ctx->r3 = MEM_HU(ctx->r2, 0XB4);
    // 0x80100CB0: sltiu       $v0, $v1, 0x9
    ctx->r2 = ctx->r3 < 0X9 ? 1 : 0;
    // 0x80100CB4: beq         $v0, $zero, L_80100D44
    if (ctx->r2 == 0) {
        // 0x80100CB8: lui         $v0, 0x800B
        ctx->r2 = S32(0X800B << 16);
            goto L_80100D44;
    }
    // 0x80100CB8: lui         $v0, 0x800B
    ctx->r2 = S32(0X800B << 16);
    // 0x80100CBC: addiu       $v0, $v0, -0x6AF8
    ctx->r2 = ADD32(ctx->r2, -0X6AF8);
    // 0x80100CC0: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x80100CC4: addu        $v1, $v1, $v0
    gpr jr_addend_80100CCC = ctx->r3;
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x80100CC8: lw          $v0, 0x0($v1)
    ctx->r2 = ADD32(ctx->r3, 0X0);
    // 0x80100CCC: jr          $v0
    // 0x80100CD0: nop

    switch (jr_addend_80100CCC >> 2) {
        case 0: goto L_80100CD4; break;
        case 1: goto L_80100D44; break;
        case 2: goto L_80100CE8; break;
        case 3: goto L_80100CFC; break;
        case 4: goto L_80100D44; break;
        case 5: goto L_80100D44; break;
        case 6: goto L_80100D44; break;
        case 7: goto L_80100D10; break;
        case 8: goto L_80100D24; break;
        default: switch_error(__func__, 0x80100CCC, 0x800A9508);
    }
    // 0x80100CD0: nop

L_80100CD4:
    // 0x80100CD4: jal         0x800B585C
    // 0x80100CD8: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    func_800B585C(rdram, ctx);
        goto after_2;
    // 0x80100CD8: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    after_2:
    // 0x80100CDC: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x80100CE0: j           L_80100D48
    // 0x80100CE4: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
        goto L_80100D48;
    // 0x80100CE4: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
L_80100CE8:
    // 0x80100CE8: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x80100CEC: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80100CF0: lwc1        $f0, -0x6AD4($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X6AD4);
    // 0x80100CF4: j           L_80100D30
    // 0x80100CF8: nop

        goto L_80100D30;
    // 0x80100CF8: nop

L_80100CFC:
    // 0x80100CFC: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x80100D00: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80100D04: lwc1        $f0, -0x6AD0($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X6AD0);
    // 0x80100D08: j           L_80100D30
    // 0x80100D0C: nop

        goto L_80100D30;
    // 0x80100D0C: nop

L_80100D10:
    // 0x80100D10: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x80100D14: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80100D18: lwc1        $f0, -0x6ACC($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X6ACC);
    // 0x80100D1C: j           L_80100D30
    // 0x80100D20: nop

        goto L_80100D30;
    // 0x80100D20: nop

L_80100D24:
    // 0x80100D24: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x80100D28: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80100D2C: lwc1        $f0, -0x6AC8($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X6AC8);
L_80100D30:
    // 0x80100D30: lwc1        $f2, 0xE8($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0XE8);
    // 0x80100D34: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x80100D38: nop

    // 0x80100D3C: bc1t        L_80100D48
    if (c1cs) {
        // 0x80100D40: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80100D48;
    }
    // 0x80100D40: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80100D44:
    // 0x80100D44: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_80100D48:
    // 0x80100D48: andi        $v1, $v0, 0xFF
    ctx->r3 = ctx->r2 & 0XFF;
    // 0x80100D4C: beq         $v1, $zero, L_80100E6C
    if (ctx->r3 == 0) {
        // 0x80100D50: nop
    
            goto L_80100E6C;
    }
    // 0x80100D50: nop

    // 0x80100D54: lbu         $v1, 0x11($s1)
    ctx->r3 = MEM_BU(ctx->r17, 0X11);
    // 0x80100D58: bne         $v1, $zero, L_80100EF8
    if (ctx->r3 != 0) {
        // 0x80100D5C: nop
    
            goto L_80100EF8;
    }
    // 0x80100D5C: nop

    // 0x80100D60: lw          $a0, 0x4($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X4);
    // 0x80100D64: lbu         $v0, 0x0($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X0);
    // 0x80100D68: sltu        $v0, $v1, $v0
    ctx->r2 = ctx->r3 < ctx->r2 ? 1 : 0;
    // 0x80100D6C: beq         $v0, $zero, L_80100E60
    if (ctx->r2 == 0) {
        // 0x80100D70: addu        $s2, $zero, $zero
        ctx->r18 = ADD32(0, 0);
            goto L_80100E60;
    }
    // 0x80100D70: addu        $s2, $zero, $zero
    ctx->r18 = ADD32(0, 0);
    // 0x80100D74: lui         $s4, 0x8000
    ctx->r20 = S32(0X8000 << 16);
    // 0x80100D78: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x80100D7C: addiu       $s3, $v0, -0x4AF0
    ctx->r19 = ADD32(ctx->r2, -0X4AF0);
    // 0x80100D80: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80100D84: lwc1        $f22, -0x6AC4($at)
    ctx->f22.u32l = MEM_W(ctx->r1, -0X6AC4);
    // 0x80100D88: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80100D8C: lwc1        $f20, -0x6AC0($at)
    ctx->f20.u32l = MEM_W(ctx->r1, -0X6AC0);
    // 0x80100D90: andi        $v0, $s2, 0xFF
    ctx->r2 = ctx->r18 & 0XFF;
L_80100D94:
    // 0x80100D94: lw          $v1, 0x4($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X4);
    // 0x80100D98: sll         $v0, $v0, 4
    ctx->r2 = S32(ctx->r2 << 4);
    // 0x80100D9C: addu        $v1, $v0, $v1
    ctx->r3 = ADD32(ctx->r2, ctx->r3);
    // 0x80100DA0: lbu         $v0, 0x5($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X5);
    // 0x80100DA4: andi        $v0, $v0, 0x2
    ctx->r2 = ctx->r2 & 0X2;
    // 0x80100DA8: beq         $v0, $zero, L_80100E44
    if (ctx->r2 == 0) {
        // 0x80100DAC: nop
    
            goto L_80100E44;
    }
    // 0x80100DAC: nop

    // 0x80100DB0: lwc1        $f2, 0xC($v1)
    ctx->f2.u32l = MEM_W(ctx->r3, 0XC);
    // 0x80100DB4: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80100DB8: lwc1        $f0, -0x6ABC($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X6ABC);
    // 0x80100DBC: mul.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x80100DC0: lwc1        $f0, 0x8($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X8);
    // 0x80100DC4: mul.s       $f4, $f0, $f22
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f22.fl);
    // 0x80100DC8: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x80100DCC: lhu         $a0, 0xB6($v0)
    ctx->r4 = MEM_HU(ctx->r2, 0XB6);
    // 0x80100DD0: c.le.s      $f20, $f2
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f20.fl <= ctx->f2.fl;
    // 0x80100DD4: nop

    // 0x80100DD8: bc1tl       L_80100DF0
    if (c1cs) {
        // 0x80100DDC: sub.s       $f0, $f2, $f20
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = ctx->f2.fl - ctx->f20.fl;
            goto L_80100DF0;
    }
    goto skip_2;
    // 0x80100DDC: sub.s       $f0, $f2, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = ctx->f2.fl - ctx->f20.fl;
    skip_2:
    // 0x80100DE0: trunc.w.s   $f6, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    ctx->f6.u32l = TRUNC_W_S(ctx->f2.fl);
    // 0x80100DE4: mfc1        $t0, $f6
    ctx->r8 = (int32_t)ctx->f6.u32l;
    // 0x80100DE8: j           L_80100E00
    // 0x80100DEC: andi        $s0, $s2, 0xFF
    ctx->r16 = ctx->r18 & 0XFF;
        goto L_80100E00;
    // 0x80100DEC: andi        $s0, $s2, 0xFF
    ctx->r16 = ctx->r18 & 0XFF;
L_80100DF0:
    // 0x80100DF0: trunc.w.s   $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    ctx->f6.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x80100DF4: mfc1        $t0, $f6
    ctx->r8 = (int32_t)ctx->f6.u32l;
    // 0x80100DF8: or          $t0, $t0, $s4
    ctx->r8 = ctx->r8 | ctx->r20;
    // 0x80100DFC: andi        $s0, $s2, 0xFF
    ctx->r16 = ctx->r18 & 0XFF;
L_80100E00:
    // 0x80100E00: lw          $v0, 0x4($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X4);
    // 0x80100E04: sll         $v1, $s0, 4
    ctx->r3 = S32(ctx->r16 << 4);
    // 0x80100E08: lw          $v0, 0x4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X4);
    // 0x80100E0C: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x80100E10: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x80100E14: lbu         $a2, 0x4($v1)
    ctx->r6 = MEM_BU(ctx->r3, 0X4);
    // 0x80100E18: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80100E1C: sw          $s3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r19;
    // 0x80100E20: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // 0x80100E24: sw          $a2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r6;
    // 0x80100E28: lw          $a3, 0x0($v1)
    ctx->r7 = MEM_W(ctx->r3, 0X0);
    // 0x80100E2C: jal         0x80072988
    // 0x80100E30: andi        $a2, $t0, 0xFF
    ctx->r6 = ctx->r8 & 0XFF;
    func_80072988(rdram, ctx);
        goto after_3;
    // 0x80100E30: andi        $a2, $t0, 0xFF
    ctx->r6 = ctx->r8 & 0XFF;
    after_3:
    // 0x80100E34: lw          $v1, 0xC($s1)
    ctx->r3 = MEM_W(ctx->r17, 0XC);
    // 0x80100E38: sll         $s0, $s0, 1
    ctx->r16 = S32(ctx->r16 << 1);
    // 0x80100E3C: addu        $s0, $s0, $v1
    ctx->r16 = ADD32(ctx->r16, ctx->r3);
    // 0x80100E40: sh          $v0, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r2;
L_80100E44:
    // 0x80100E44: lw          $a0, 0x4($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X4);
    // 0x80100E48: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x80100E4C: lbu         $v1, 0x0($a0)
    ctx->r3 = MEM_BU(ctx->r4, 0X0);
    // 0x80100E50: andi        $v0, $s2, 0xFF
    ctx->r2 = ctx->r18 & 0XFF;
    // 0x80100E54: sltu        $v0, $v0, $v1
    ctx->r2 = ctx->r2 < ctx->r3 ? 1 : 0;
    // 0x80100E58: bne         $v0, $zero, L_80100D94
    if (ctx->r2 != 0) {
        // 0x80100E5C: andi        $v0, $s2, 0xFF
        ctx->r2 = ctx->r18 & 0XFF;
            goto L_80100D94;
    }
    // 0x80100E5C: andi        $v0, $s2, 0xFF
    ctx->r2 = ctx->r18 & 0XFF;
L_80100E60:
    // 0x80100E60: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80100E64: j           L_80100EF8
    // 0x80100E68: sb          $v0, 0x11($s1)
    MEM_B(0X11, ctx->r17) = ctx->r2;
        goto L_80100EF8;
    // 0x80100E68: sb          $v0, 0x11($s1)
    MEM_B(0X11, ctx->r17) = ctx->r2;
L_80100E6C:
    // 0x80100E6C: lbu         $v0, 0x11($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X11);
    // 0x80100E70: beq         $v0, $zero, L_80100EF8
    if (ctx->r2 == 0) {
        // 0x80100E74: nop
    
            goto L_80100EF8;
    }
    // 0x80100E74: nop

    // 0x80100E78: lw          $a0, 0x4($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X4);
    // 0x80100E7C: lbu         $v0, 0x0($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X0);
    // 0x80100E80: sltu        $v0, $v1, $v0
    ctx->r2 = ctx->r3 < ctx->r2 ? 1 : 0;
    // 0x80100E84: beq         $v0, $zero, L_80100EF4
    if (ctx->r2 == 0) {
        // 0x80100E88: addu        $s2, $zero, $zero
        ctx->r18 = ADD32(0, 0);
            goto L_80100EF4;
    }
    // 0x80100E88: addu        $s2, $zero, $zero
    ctx->r18 = ADD32(0, 0);
    // 0x80100E8C: ori         $s3, $zero, 0xFFFF
    ctx->r19 = 0 | 0XFFFF;
    // 0x80100E90: andi        $a1, $s2, 0xFF
    ctx->r5 = ctx->r18 & 0XFF;
L_80100E94:
    // 0x80100E94: lw          $v0, 0x4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X4);
    // 0x80100E98: sll         $v1, $a1, 4
    ctx->r3 = S32(ctx->r5 << 4);
    // 0x80100E9C: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x80100EA0: lbu         $v0, 0x5($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X5);
    // 0x80100EA4: andi        $v0, $v0, 0x2
    ctx->r2 = ctx->r2 & 0X2;
    // 0x80100EA8: beq         $v0, $zero, L_80100ED8
    if (ctx->r2 == 0) {
        // 0x80100EAC: sll         $s0, $a1, 1
        ctx->r16 = S32(ctx->r5 << 1);
            goto L_80100ED8;
    }
    // 0x80100EAC: sll         $s0, $a1, 1
    ctx->r16 = S32(ctx->r5 << 1);
    // 0x80100EB0: lw          $v0, 0xC($s1)
    ctx->r2 = MEM_W(ctx->r17, 0XC);
    // 0x80100EB4: addu        $v1, $s0, $v0
    ctx->r3 = ADD32(ctx->r16, ctx->r2);
    // 0x80100EB8: lhu         $v0, 0x0($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X0);
    // 0x80100EBC: beq         $v0, $s3, L_80100ED8
    if (ctx->r2 == ctx->r19) {
        // 0x80100EC0: nop
    
            goto L_80100ED8;
    }
    // 0x80100EC0: nop

    // 0x80100EC4: jal         0x80072ACC
    // 0x80100EC8: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    func_80072ACC(rdram, ctx);
        goto after_4;
    // 0x80100EC8: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    after_4:
    // 0x80100ECC: lw          $v0, 0xC($s1)
    ctx->r2 = MEM_W(ctx->r17, 0XC);
    // 0x80100ED0: addu        $v0, $s0, $v0
    ctx->r2 = ADD32(ctx->r16, ctx->r2);
    // 0x80100ED4: sh          $s3, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r19;
L_80100ED8:
    // 0x80100ED8: lw          $a0, 0x4($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X4);
    // 0x80100EDC: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x80100EE0: lbu         $v1, 0x0($a0)
    ctx->r3 = MEM_BU(ctx->r4, 0X0);
    // 0x80100EE4: andi        $v0, $s2, 0xFF
    ctx->r2 = ctx->r18 & 0XFF;
    // 0x80100EE8: sltu        $v0, $v0, $v1
    ctx->r2 = ctx->r2 < ctx->r3 ? 1 : 0;
    // 0x80100EEC: bne         $v0, $zero, L_80100E94
    if (ctx->r2 != 0) {
        // 0x80100EF0: andi        $a1, $s2, 0xFF
        ctx->r5 = ctx->r18 & 0XFF;
            goto L_80100E94;
    }
    // 0x80100EF0: andi        $a1, $s2, 0xFF
    ctx->r5 = ctx->r18 & 0XFF;
L_80100EF4:
    // 0x80100EF4: sb          $zero, 0x11($s1)
    MEM_B(0X11, ctx->r17) = 0;
L_80100EF8:
    // 0x80100EF8: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x80100EFC: mfc1        $a1, $f24
    ctx->r5 = (int32_t)ctx->f24.u32l;
    // 0x80100F00: jal         0x801001C8
    // 0x80100F04: nop

    func_801001C8(rdram, ctx);
        goto after_5;
    // 0x80100F04: nop

    after_5:
    // 0x80100F08: lw          $ra, 0x40($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X40);
    // 0x80100F0C: lw          $s7, 0x3C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X3C);
    // 0x80100F10: lw          $s6, 0x38($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X38);
    // 0x80100F14: lw          $s5, 0x34($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X34);
    // 0x80100F18: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x80100F1C: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x80100F20: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x80100F24: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x80100F28: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80100F2C: ldc1        $f24, 0x58($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X58);
    // 0x80100F30: ldc1        $f22, 0x50($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X50);
    // 0x80100F34: ldc1        $f20, 0x48($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X48);
    // 0x80100F38: jr          $ra
    // 0x80100F3C: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    return;
    // 0x80100F3C: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
;}
RECOMP_FUNC void func_80100F40(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80100F40: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80100F44: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
    // 0x80100F48: addiu       $v1, $v1, -0x30E0
    ctx->r3 = ADD32(ctx->r3, -0X30E0);
    // 0x80100F4C: andi        $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 & 0XFF;
    // 0x80100F50: sll         $v0, $a0, 1
    ctx->r2 = S32(ctx->r4 << 1);
    // 0x80100F54: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x80100F58: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x80100F5C: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x80100F60: addu        $s0, $v0, $v1
    ctx->r16 = ADD32(ctx->r2, ctx->r3);
    // 0x80100F64: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80100F68: lw          $v0, 0x4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X4);
    // 0x80100F6C: lbu         $v0, 0x0($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X0);
    // 0x80100F70: beq         $v0, $zero, L_80100F98
    if (ctx->r2 == 0) {
        // 0x80100F74: nop
    
            goto L_80100F98;
    }
    // 0x80100F74: nop

    // 0x80100F78: jal         0x80100594
    // 0x80100F7C: nop

    func_80100594(rdram, ctx);
        goto after_0;
    // 0x80100F7C: nop

    after_0:
    // 0x80100F80: lw          $a0, 0x8($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X8);
    // 0x80100F84: jal         0x80001C98
    // 0x80100F88: nop

    rs_free(rdram, ctx);
        goto after_1;
    // 0x80100F88: nop

    after_1:
    // 0x80100F8C: lw          $a0, 0xC($s0)
    ctx->r4 = MEM_W(ctx->r16, 0XC);
    // 0x80100F90: jal         0x80001C98
    // 0x80100F94: nop

    rs_free(rdram, ctx);
        goto after_2;
    // 0x80100F94: nop

    after_2:
L_80100F98:
    // 0x80100F98: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80100F9C: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x80100FA0: jr          $ra
    // 0x80100FA4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80100FA4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_80100FA8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80100FA8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80100FAC: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x80100FB0: andi        $s0, $a0, 0xFF
    ctx->r16 = ctx->r4 & 0XFF;
    // 0x80100FB4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80100FB8: jal         0x80100594
    // 0x80100FBC: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_80100594(rdram, ctx);
        goto after_0;
    // 0x80100FBC: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_0:
    // 0x80100FC0: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
    // 0x80100FC4: addiu       $v1, $v1, -0x30E0
    ctx->r3 = ADD32(ctx->r3, -0X30E0);
    // 0x80100FC8: sll         $v0, $s0, 1
    ctx->r2 = S32(ctx->r16 << 1);
    // 0x80100FCC: addu        $v0, $v0, $s0
    ctx->r2 = ADD32(ctx->r2, ctx->r16);
    // 0x80100FD0: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x80100FD4: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80100FD8: lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X0);
    // 0x80100FDC: sb          $zero, 0x10($v0)
    MEM_B(0X10, ctx->r2) = 0;
    // 0x80100FE0: sb          $zero, 0x11($v0)
    MEM_B(0X11, ctx->r2) = 0;
    // 0x80100FE4: sb          $zero, 0x12($v0)
    MEM_B(0X12, ctx->r2) = 0;
    // 0x80100FE8: sb          $zero, 0x13($v0)
    MEM_B(0X13, ctx->r2) = 0;
    // 0x80100FEC: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x80100FF0: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80100FF4: lwc1        $f0, -0x6AB8($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X6AB8);
    // 0x80100FF8: lwc1        $f2, 0xE8($v1)
    ctx->f2.u32l = MEM_W(ctx->r3, 0XE8);
    // 0x80100FFC: addiu       $v0, $v0, -0x30C8
    ctx->r2 = ADD32(ctx->r2, -0X30C8);
    // 0x80101000: swc1        $f0, 0xF8($v0)
    MEM_W(0XF8, ctx->r2) = ctx->f0.u32l;
    // 0x80101004: swc1        $f2, 0xF4($v0)
    MEM_W(0XF4, ctx->r2) = ctx->f2.u32l;
    // 0x80101008: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8010100C: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x80101010: jr          $ra
    // 0x80101014: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80101014: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_80101018(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80101018: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
    // 0x8010101C: addiu       $v1, $v1, -0x30E0
    ctx->r3 = ADD32(ctx->r3, -0X30E0);
    // 0x80101020: andi        $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 & 0XFF;
    // 0x80101024: sll         $v0, $a0, 1
    ctx->r2 = S32(ctx->r4 << 1);
    // 0x80101028: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x8010102C: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x80101030: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80101034: sb          $a1, 0x12($v0)
    MEM_B(0X12, ctx->r2) = ctx->r5;
    // 0x80101038: jr          $ra
    // 0x8010103C: sw          $a2, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->r6;
    return;
    // 0x8010103C: sw          $a2, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->r6;
;}
RECOMP_FUNC void func_80101040(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80101040: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
    // 0x80101044: addiu       $v1, $v1, -0x30E0
    ctx->r3 = ADD32(ctx->r3, -0X30E0);
    // 0x80101048: andi        $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 & 0XFF;
    // 0x8010104C: sll         $v0, $a0, 1
    ctx->r2 = S32(ctx->r4 << 1);
    // 0x80101050: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x80101054: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x80101058: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8010105C: lbu         $v0, 0x13($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X13);
    // 0x80101060: jr          $ra
    // 0x80101064: nop

    return;
    // 0x80101064: nop

;}
RECOMP_FUNC void func_80101068(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80101068: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
    // 0x8010106C: addiu       $v1, $v1, -0x30E0
    ctx->r3 = ADD32(ctx->r3, -0X30E0);
    // 0x80101070: andi        $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 & 0XFF;
    // 0x80101074: sll         $v0, $a0, 1
    ctx->r2 = S32(ctx->r4 << 1);
    // 0x80101078: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x8010107C: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x80101080: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80101084: lwc1        $f0, 0x14($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X14);
    // 0x80101088: jr          $ra
    // 0x8010108C: nop

    return;
    // 0x8010108C: nop

;}
RECOMP_FUNC void lv0_initializeObjectTracking(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80101090: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80101094: addiu       $a0, $zero, 0x61
    ctx->r4 = ADD32(0, 0X61);
    // 0x80101098: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8010109C: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x801010A0: sw          $zero, -0x4970($v0)
    MEM_W(-0X4970, ctx->r2) = 0;
    // 0x801010A4: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x801010A8: sw          $zero, -0x496C($v0)
    MEM_W(-0X496C, ctx->r2) = 0;
    // 0x801010AC: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x801010B0: sw          $zero, -0x4968($v0)
    MEM_W(-0X4968, ctx->r2) = 0;
    // 0x801010B4: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x801010B8: sw          $zero, -0x4964($v0)
    MEM_W(-0X4964, ctx->r2) = 0;
    // 0x801010BC: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x801010C0: sw          $zero, -0x4960($v0)
    MEM_W(-0X4960, ctx->r2) = 0;
    // 0x801010C4: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x801010C8: sw          $zero, -0x495C($v0)
    MEM_W(-0X495C, ctx->r2) = 0;
    // 0x801010CC: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x801010D0: sw          $ra, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r31;
    // 0x801010D4: jal         0x800C7540
    // 0x801010D8: sw          $zero, -0x4958($v0)
    MEM_W(-0X4958, ctx->r2) = 0;
    setObjectiveBoolean(rdram, ctx);
        goto after_0;
    // 0x801010D8: sw          $zero, -0x4958($v0)
    MEM_W(-0X4958, ctx->r2) = 0;
    after_0:
    // 0x801010DC: addiu       $a0, $zero, 0x62
    ctx->r4 = ADD32(0, 0X62);
    // 0x801010E0: jal         0x800C7540
    // 0x801010E4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    setObjectiveBoolean(rdram, ctx);
        goto after_1;
    // 0x801010E4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x801010E8: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    // 0x801010EC: jal         0x800C7540
    // 0x801010F0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    setObjectiveBoolean(rdram, ctx);
        goto after_2;
    // 0x801010F0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_2:
    // 0x801010F4: lui         $a0, 0x8010
    ctx->r4 = S32(0X8010 << 16);
    // 0x801010F8: addiu       $a0, $a0, 0x1934
    ctx->r4 = ADD32(ctx->r4, 0X1934);
    // 0x801010FC: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x80101100: addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    // 0x80101104: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x80101108: addiu       $v0, $zero, 0x15
    ctx->r2 = ADD32(0, 0X15);
    // 0x8010110C: jal         0x800C7830
    // 0x80101110: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    addBooleanCountHandleWrapper(rdram, ctx);
        goto after_3;
    // 0x80101110: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    after_3:
    // 0x80101114: lui         $a0, 0x8010
    ctx->r4 = S32(0X8010 << 16);
    // 0x80101118: addiu       $a0, $a0, 0x18EC
    ctx->r4 = ADD32(ctx->r4, 0X18EC);
    // 0x8010111C: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x80101120: addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    // 0x80101124: addiu       $a3, $zero, 0x14
    ctx->r7 = ADD32(0, 0X14);
    // 0x80101128: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8010112C: jal         0x800C7830
    // 0x80101130: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    addBooleanCountHandleWrapper(rdram, ctx);
        goto after_4;
    // 0x80101130: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    after_4:
    // 0x80101134: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80101138: lwc1        $f12, -0x6AB0($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X6AB0);
    // 0x8010113C: jal         0x800C7CEC
    // 0x80101140: nop

    func_800C7CEC(rdram, ctx);
        goto after_5;
    // 0x80101140: nop

    after_5:
    // 0x80101144: addiu       $a0, $zero, 0x3C
    ctx->r4 = ADD32(0, 0X3C);
    // 0x80101148: jal         0x800C7540
    // 0x8010114C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    setObjectiveBoolean(rdram, ctx);
        goto after_6;
    // 0x8010114C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_6:
    // 0x80101150: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x80101154: jal         0x800C76FC
    // 0x80101158: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    setObjectiveTimer(rdram, ctx);
        goto after_7;
    // 0x80101158: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    after_7:
    // 0x8010115C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80101160: jal         0x800C7660
    // 0x80101164: addu        $a1, $a0, $zero
    ctx->r5 = ADD32(ctx->r4, 0);
    setObjectiveHiddenFlag(rdram, ctx);
        goto after_8;
    // 0x80101164: addu        $a1, $a0, $zero
    ctx->r5 = ADD32(ctx->r4, 0);
    after_8:
    // 0x80101168: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8010116C: jal         0x800C7660
    // 0x80101170: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    setObjectiveHiddenFlag(rdram, ctx);
        goto after_9;
    // 0x80101170: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_9:
    // 0x80101174: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80101178: jal         0x800C7660
    // 0x8010117C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    setObjectiveHiddenFlag(rdram, ctx);
        goto after_10;
    // 0x8010117C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_10:
    // 0x80101180: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80101184: jal         0x800C7660
    // 0x80101188: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    setObjectiveHiddenFlag(rdram, ctx);
        goto after_11;
    // 0x80101188: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_11:
    // 0x8010118C: lw          $ra, 0x18($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X18);
    // 0x80101190: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // 0x80101194: jr          $ra
    // 0x80101198: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80101198: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void lv0_checkComplexObjectives(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8010119C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x801011A0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801011A4: sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // 0x801011A8: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x801011AC: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x801011B0: sdc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X20, ctx->r29);
    // 0x801011B4: jal         0x800C761C
    // 0x801011B8: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    getObjectiveCount(rdram, ctx);
        goto after_0;
    // 0x801011B8: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_0:
    // 0x801011BC: slti        $v0, $v0, 0x3
    ctx->r2 = SIGNED(ctx->r2) < 0X3 ? 1 : 0;
    // 0x801011C0: bne         $v0, $zero, L_801011E8
    if (ctx->r2 != 0) {
        // 0x801011C4: nop
    
            goto L_801011E8;
    }
    // 0x801011C4: nop

    // 0x801011C8: jal         0x800C7738
    // 0x801011CC: nop

    func_800C7738(rdram, ctx);
        goto after_1;
    // 0x801011CC: nop

    after_1:
    // 0x801011D0: lui         $a1, 0x3E99
    ctx->r5 = S32(0X3E99 << 16);
    // 0x801011D4: ori         $a1, $a1, 0x999A
    ctx->r5 = ctx->r5 | 0X999A;
    // 0x801011D8: jal         0x800C7D1C
    // 0x801011DC: addiu       $a0, $zero, 0x229
    ctx->r4 = ADD32(0, 0X229);
    playObjectiveVoiceLine2(rdram, ctx);
        goto after_2;
    // 0x801011DC: addiu       $a0, $zero, 0x229
    ctx->r4 = ADD32(0, 0X229);
    after_2:
    // 0x801011E0: j           L_801018D0
    // 0x801011E4: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
        goto L_801018D0;
    // 0x801011E4: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_801011E8:
    // 0x801011E8: jal         0x800C761C
    // 0x801011EC: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    getObjectiveCount(rdram, ctx);
        goto after_3;
    // 0x801011EC: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_3:
    // 0x801011F0: slti        $v0, $v0, 0x9
    ctx->r2 = SIGNED(ctx->r2) < 0X9 ? 1 : 0;
    // 0x801011F4: bne         $v0, $zero, L_8010121C
    if (ctx->r2 != 0) {
        // 0x801011F8: nop
    
            goto L_8010121C;
    }
    // 0x801011F8: nop

    // 0x801011FC: jal         0x800C7738
    // 0x80101200: nop

    func_800C7738(rdram, ctx);
        goto after_4;
    // 0x80101200: nop

    after_4:
    // 0x80101204: lui         $a1, 0x3E99
    ctx->r5 = S32(0X3E99 << 16);
    // 0x80101208: ori         $a1, $a1, 0x999A
    ctx->r5 = ctx->r5 | 0X999A;
    // 0x8010120C: jal         0x800C7D1C
    // 0x80101210: addiu       $a0, $zero, 0x22A
    ctx->r4 = ADD32(0, 0X22A);
    playObjectiveVoiceLine2(rdram, ctx);
        goto after_5;
    // 0x80101210: addiu       $a0, $zero, 0x22A
    ctx->r4 = ADD32(0, 0X22A);
    after_5:
    // 0x80101214: j           L_801018D0
    // 0x80101218: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
        goto L_801018D0;
    // 0x80101218: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_8010121C:
    // 0x8010121C: jal         0x800C761C
    // 0x80101220: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    getObjectiveCount(rdram, ctx);
        goto after_6;
    // 0x80101220: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    after_6:
    // 0x80101224: slti        $v0, $v0, 0x6
    ctx->r2 = SIGNED(ctx->r2) < 0X6 ? 1 : 0;
    // 0x80101228: bne         $v0, $zero, L_80101250
    if (ctx->r2 != 0) {
        // 0x8010122C: nop
    
            goto L_80101250;
    }
    // 0x8010122C: nop

    // 0x80101230: jal         0x800C76B0
    // 0x80101234: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    activateObjectiveCompleteFlag(rdram, ctx);
        goto after_7;
    // 0x80101234: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_7:
    // 0x80101238: jal         0x800C76B0
    // 0x8010123C: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    activateObjectiveCompleteFlag(rdram, ctx);
        goto after_8;
    // 0x8010123C: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    after_8:
    // 0x80101240: jal         0x800C776C
    // 0x80101244: nop

    func_800C776C(rdram, ctx);
        goto after_9;
    // 0x80101244: nop

    after_9:
    // 0x80101248: j           L_801018D0
    // 0x8010124C: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
        goto L_801018D0;
    // 0x8010124C: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_80101250:
    // 0x80101250: jal         0x800C76E0
    // 0x80101254: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    getObjectiveTimer(rdram, ctx);
        goto after_10;
    // 0x80101254: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_10:
    // 0x80101258: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8010125C: lwc1        $f2, -0x6A8C($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X6A8C);
    // 0x80101260: c.le.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl <= ctx->f0.fl;
    // 0x80101264: nop

    // 0x80101268: bc1f        L_801012AC
    if (!c1cs) {
        // 0x8010126C: lui         $v0, 0x800B
        ctx->r2 = S32(0X800B << 16);
            goto L_801012AC;
    }
    // 0x8010126C: lui         $v0, 0x800B
    ctx->r2 = S32(0X800B << 16);
    // 0x80101270: addiu       $s0, $v0, -0x6AAC
    ctx->r16 = ADD32(ctx->r2, -0X6AAC);
    // 0x80101274: jal         0x800C78A0
    // 0x80101278: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    calculateDatItemDistanceToPlayer(rdram, ctx);
        goto after_11;
    // 0x80101278: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_11:
    // 0x8010127C: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80101280: lwc1        $f2, -0x6A88($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X6A88);
    // 0x80101284: c.le.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl <= ctx->f0.fl;
    // 0x80101288: nop

    // 0x8010128C: bc1f        L_801012AC
    if (!c1cs) {
        // 0x80101290: nop
    
            goto L_801012AC;
    }
    // 0x80101290: nop

    // 0x80101294: jal         0x800C7B60
    // 0x80101298: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    getDatItemHealth(rdram, ctx);
        goto after_12;
    // 0x80101298: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_12:
    // 0x8010129C: blez        $v0, L_801012AC
    if (SIGNED(ctx->r2) <= 0) {
        // 0x801012A0: addu        $a0, $s0, $zero
        ctx->r4 = ADD32(ctx->r16, 0);
            goto L_801012AC;
    }
    // 0x801012A0: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x801012A4: jal         0x800C7390
    // 0x801012A8: addiu       $a1, $zero, 0x1E
    ctx->r5 = ADD32(0, 0X1E);
    dealDamagetoDatItem(rdram, ctx);
        goto after_13;
    // 0x801012A8: addiu       $a1, $zero, 0x1E
    ctx->r5 = ADD32(0, 0X1E);
    after_13:
L_801012AC:
    // 0x801012AC: jal         0x800C76E0
    // 0x801012B0: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    getObjectiveTimer(rdram, ctx);
        goto after_14;
    // 0x801012B0: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    after_14:
    // 0x801012B4: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x801012B8: lwc1        $f2, -0x6A84($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X6A84);
    // 0x801012BC: c.le.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl <= ctx->f0.fl;
    // 0x801012C0: nop

    // 0x801012C4: bc1f        L_80101304
    if (!c1cs) {
        // 0x801012C8: nop
    
            goto L_80101304;
    }
    // 0x801012C8: nop

    // 0x801012CC: jal         0x800C759C
    // 0x801012D0: addiu       $a0, $zero, 0x3C
    ctx->r4 = ADD32(0, 0X3C);
    getObjectiveBoolean(rdram, ctx);
        goto after_15;
    // 0x801012D0: addiu       $a0, $zero, 0x3C
    ctx->r4 = ADD32(0, 0X3C);
    after_15:
    // 0x801012D4: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // 0x801012D8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x801012DC: bne         $v1, $v0, L_80101304
    if (ctx->r3 != ctx->r2) {
        // 0x801012E0: lui         $v0, 0x8011
        ctx->r2 = S32(0X8011 << 16);
            goto L_80101304;
    }
    // 0x801012E0: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x801012E4: lw          $v0, -0x495C($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X495C);
    // 0x801012E8: bne         $v0, $v1, L_80101304
    if (ctx->r2 != ctx->r3) {
        // 0x801012EC: addiu       $a0, $zero, 0x3C
        ctx->r4 = ADD32(0, 0X3C);
            goto L_80101304;
    }
    // 0x801012EC: addiu       $a0, $zero, 0x3C
    ctx->r4 = ADD32(0, 0X3C);
    // 0x801012F0: jal         0x800C7540
    // 0x801012F4: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    setObjectiveBoolean(rdram, ctx);
        goto after_16;
    // 0x801012F4: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    after_16:
    // 0x801012F8: addiu       $a0, $zero, 0x3D
    ctx->r4 = ADD32(0, 0X3D);
    // 0x801012FC: jal         0x800C7540
    // 0x80101300: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    setObjectiveBoolean(rdram, ctx);
        goto after_17;
    // 0x80101300: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_17:
L_80101304:
    // 0x80101304: jal         0x800C759C
    // 0x80101308: addiu       $a0, $zero, 0x1F
    ctx->r4 = ADD32(0, 0X1F);
    getObjectiveBoolean(rdram, ctx);
        goto after_18;
    // 0x80101308: addiu       $a0, $zero, 0x1F
    ctx->r4 = ADD32(0, 0X1F);
    after_18:
    // 0x8010130C: addu        $s1, $v0, $zero
    ctx->r17 = ADD32(ctx->r2, 0);
    // 0x80101310: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80101314: bne         $s1, $v0, L_80101358
    if (ctx->r17 != ctx->r2) {
        // 0x80101318: nop
    
            goto L_80101358;
    }
    // 0x80101318: nop

    // 0x8010131C: jal         0x800C759C
    // 0x80101320: addiu       $a0, $zero, 0x18
    ctx->r4 = ADD32(0, 0X18);
    getObjectiveBoolean(rdram, ctx);
        goto after_19;
    // 0x80101320: addiu       $a0, $zero, 0x18
    ctx->r4 = ADD32(0, 0X18);
    after_19:
    // 0x80101324: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    // 0x80101328: bne         $s0, $s1, L_80101358
    if (ctx->r16 != ctx->r17) {
        // 0x8010132C: nop
    
            goto L_80101358;
    }
    // 0x8010132C: nop

    // 0x80101330: jal         0x800C759C
    // 0x80101334: addiu       $a0, $zero, 0x19
    ctx->r4 = ADD32(0, 0X19);
    getObjectiveBoolean(rdram, ctx);
        goto after_20;
    // 0x80101334: addiu       $a0, $zero, 0x19
    ctx->r4 = ADD32(0, 0X19);
    after_20:
    // 0x80101338: bne         $v0, $s0, L_80101358
    if (ctx->r2 != ctx->r16) {
        // 0x8010133C: nop
    
            goto L_80101358;
    }
    // 0x8010133C: nop

    // 0x80101340: jal         0x800C759C
    // 0x80101344: addiu       $a0, $zero, 0x33
    ctx->r4 = ADD32(0, 0X33);
    getObjectiveBoolean(rdram, ctx);
        goto after_21;
    // 0x80101344: addiu       $a0, $zero, 0x33
    ctx->r4 = ADD32(0, 0X33);
    after_21:
    // 0x80101348: bne         $v0, $zero, L_80101358
    if (ctx->r2 != 0) {
        // 0x8010134C: addiu       $a0, $zero, 0x33
        ctx->r4 = ADD32(0, 0X33);
            goto L_80101358;
    }
    // 0x8010134C: addiu       $a0, $zero, 0x33
    ctx->r4 = ADD32(0, 0X33);
    // 0x80101350: jal         0x800C7540
    // 0x80101354: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    setObjectiveBoolean(rdram, ctx);
        goto after_22;
    // 0x80101354: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_22:
L_80101358:
    // 0x80101358: jal         0x800C759C
    // 0x8010135C: addiu       $a0, $zero, 0x26
    ctx->r4 = ADD32(0, 0X26);
    getObjectiveBoolean(rdram, ctx);
        goto after_23;
    // 0x8010135C: addiu       $a0, $zero, 0x26
    ctx->r4 = ADD32(0, 0X26);
    after_23:
    // 0x80101360: addu        $s1, $v0, $zero
    ctx->r17 = ADD32(ctx->r2, 0);
    // 0x80101364: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80101368: bne         $s1, $v0, L_801013D4
    if (ctx->r17 != ctx->r2) {
        // 0x8010136C: nop
    
            goto L_801013D4;
    }
    // 0x8010136C: nop

    // 0x80101370: jal         0x800C759C
    // 0x80101374: addiu       $a0, $zero, 0x27
    ctx->r4 = ADD32(0, 0X27);
    getObjectiveBoolean(rdram, ctx);
        goto after_24;
    // 0x80101374: addiu       $a0, $zero, 0x27
    ctx->r4 = ADD32(0, 0X27);
    after_24:
    // 0x80101378: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    // 0x8010137C: bne         $s0, $s1, L_801013D4
    if (ctx->r16 != ctx->r17) {
        // 0x80101380: nop
    
            goto L_801013D4;
    }
    // 0x80101380: nop

    // 0x80101384: jal         0x800C759C
    // 0x80101388: addiu       $a0, $zero, 0x1B
    ctx->r4 = ADD32(0, 0X1B);
    getObjectiveBoolean(rdram, ctx);
        goto after_25;
    // 0x80101388: addiu       $a0, $zero, 0x1B
    ctx->r4 = ADD32(0, 0X1B);
    after_25:
    // 0x8010138C: addu        $s1, $v0, $zero
    ctx->r17 = ADD32(ctx->r2, 0);
    // 0x80101390: bne         $s1, $s0, L_801013D4
    if (ctx->r17 != ctx->r16) {
        // 0x80101394: nop
    
            goto L_801013D4;
    }
    // 0x80101394: nop

    // 0x80101398: jal         0x800C759C
    // 0x8010139C: addiu       $a0, $zero, 0x1C
    ctx->r4 = ADD32(0, 0X1C);
    getObjectiveBoolean(rdram, ctx);
        goto after_26;
    // 0x8010139C: addiu       $a0, $zero, 0x1C
    ctx->r4 = ADD32(0, 0X1C);
    after_26:
    // 0x801013A0: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    // 0x801013A4: bne         $s0, $s1, L_801013D4
    if (ctx->r16 != ctx->r17) {
        // 0x801013A8: nop
    
            goto L_801013D4;
    }
    // 0x801013A8: nop

    // 0x801013AC: jal         0x800C759C
    // 0x801013B0: addiu       $a0, $zero, 0x1D
    ctx->r4 = ADD32(0, 0X1D);
    getObjectiveBoolean(rdram, ctx);
        goto after_27;
    // 0x801013B0: addiu       $a0, $zero, 0x1D
    ctx->r4 = ADD32(0, 0X1D);
    after_27:
    // 0x801013B4: bne         $v0, $s0, L_801013D4
    if (ctx->r2 != ctx->r16) {
        // 0x801013B8: nop
    
            goto L_801013D4;
    }
    // 0x801013B8: nop

    // 0x801013BC: jal         0x800C759C
    // 0x801013C0: addiu       $a0, $zero, 0x34
    ctx->r4 = ADD32(0, 0X34);
    getObjectiveBoolean(rdram, ctx);
        goto after_28;
    // 0x801013C0: addiu       $a0, $zero, 0x34
    ctx->r4 = ADD32(0, 0X34);
    after_28:
    // 0x801013C4: bne         $v0, $zero, L_801013D4
    if (ctx->r2 != 0) {
        // 0x801013C8: addiu       $a0, $zero, 0x34
        ctx->r4 = ADD32(0, 0X34);
            goto L_801013D4;
    }
    // 0x801013C8: addiu       $a0, $zero, 0x34
    ctx->r4 = ADD32(0, 0X34);
    // 0x801013CC: jal         0x800C7540
    // 0x801013D0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    setObjectiveBoolean(rdram, ctx);
        goto after_29;
    // 0x801013D0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_29:
L_801013D4:
    // 0x801013D4: jal         0x800C759C
    // 0x801013D8: addiu       $a0, $zero, 0x20
    ctx->r4 = ADD32(0, 0X20);
    getObjectiveBoolean(rdram, ctx);
        goto after_30;
    // 0x801013D8: addiu       $a0, $zero, 0x20
    ctx->r4 = ADD32(0, 0X20);
    after_30:
    // 0x801013DC: addu        $s1, $v0, $zero
    ctx->r17 = ADD32(ctx->r2, 0);
    // 0x801013E0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x801013E4: bne         $s1, $v0, L_80101464
    if (ctx->r17 != ctx->r2) {
        // 0x801013E8: nop
    
            goto L_80101464;
    }
    // 0x801013E8: nop

    // 0x801013EC: jal         0x800C759C
    // 0x801013F0: addiu       $a0, $zero, 0x21
    ctx->r4 = ADD32(0, 0X21);
    getObjectiveBoolean(rdram, ctx);
        goto after_31;
    // 0x801013F0: addiu       $a0, $zero, 0x21
    ctx->r4 = ADD32(0, 0X21);
    after_31:
    // 0x801013F4: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    // 0x801013F8: bne         $s0, $s1, L_80101464
    if (ctx->r16 != ctx->r17) {
        // 0x801013FC: nop
    
            goto L_80101464;
    }
    // 0x801013FC: nop

    // 0x80101400: jal         0x800C759C
    // 0x80101404: addiu       $a0, $zero, 0x28
    ctx->r4 = ADD32(0, 0X28);
    getObjectiveBoolean(rdram, ctx);
        goto after_32;
    // 0x80101404: addiu       $a0, $zero, 0x28
    ctx->r4 = ADD32(0, 0X28);
    after_32:
    // 0x80101408: addu        $s1, $v0, $zero
    ctx->r17 = ADD32(ctx->r2, 0);
    // 0x8010140C: bne         $s1, $s0, L_80101464
    if (ctx->r17 != ctx->r16) {
        // 0x80101410: nop
    
            goto L_80101464;
    }
    // 0x80101410: nop

    // 0x80101414: jal         0x800C759C
    // 0x80101418: addiu       $a0, $zero, 0x29
    ctx->r4 = ADD32(0, 0X29);
    getObjectiveBoolean(rdram, ctx);
        goto after_33;
    // 0x80101418: addiu       $a0, $zero, 0x29
    ctx->r4 = ADD32(0, 0X29);
    after_33:
    // 0x8010141C: addu        $s2, $v0, $zero
    ctx->r18 = ADD32(ctx->r2, 0);
    // 0x80101420: bne         $s2, $s1, L_80101464
    if (ctx->r18 != ctx->r17) {
        // 0x80101424: nop
    
            goto L_80101464;
    }
    // 0x80101424: nop

    // 0x80101428: jal         0x800C759C
    // 0x8010142C: addiu       $a0, $zero, 0x2A
    ctx->r4 = ADD32(0, 0X2A);
    getObjectiveBoolean(rdram, ctx);
        goto after_34;
    // 0x8010142C: addiu       $a0, $zero, 0x2A
    ctx->r4 = ADD32(0, 0X2A);
    after_34:
    // 0x80101430: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    // 0x80101434: bne         $s0, $s2, L_80101464
    if (ctx->r16 != ctx->r18) {
        // 0x80101438: nop
    
            goto L_80101464;
    }
    // 0x80101438: nop

    // 0x8010143C: jal         0x800C759C
    // 0x80101440: addiu       $a0, $zero, 0x2B
    ctx->r4 = ADD32(0, 0X2B);
    getObjectiveBoolean(rdram, ctx);
        goto after_35;
    // 0x80101440: addiu       $a0, $zero, 0x2B
    ctx->r4 = ADD32(0, 0X2B);
    after_35:
    // 0x80101444: bne         $v0, $s0, L_80101464
    if (ctx->r2 != ctx->r16) {
        // 0x80101448: nop
    
            goto L_80101464;
    }
    // 0x80101448: nop

    // 0x8010144C: jal         0x800C759C
    // 0x80101450: addiu       $a0, $zero, 0x35
    ctx->r4 = ADD32(0, 0X35);
    getObjectiveBoolean(rdram, ctx);
        goto after_36;
    // 0x80101450: addiu       $a0, $zero, 0x35
    ctx->r4 = ADD32(0, 0X35);
    after_36:
    // 0x80101454: bne         $v0, $zero, L_80101464
    if (ctx->r2 != 0) {
        // 0x80101458: addiu       $a0, $zero, 0x35
        ctx->r4 = ADD32(0, 0X35);
            goto L_80101464;
    }
    // 0x80101458: addiu       $a0, $zero, 0x35
    ctx->r4 = ADD32(0, 0X35);
    // 0x8010145C: jal         0x800C7540
    // 0x80101460: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    setObjectiveBoolean(rdram, ctx);
        goto after_37;
    // 0x80101460: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_37:
L_80101464:
    // 0x80101464: jal         0x800C759C
    // 0x80101468: addiu       $a0, $zero, 0x22
    ctx->r4 = ADD32(0, 0X22);
    getObjectiveBoolean(rdram, ctx);
        goto after_38;
    // 0x80101468: addiu       $a0, $zero, 0x22
    ctx->r4 = ADD32(0, 0X22);
    after_38:
    // 0x8010146C: addu        $s1, $v0, $zero
    ctx->r17 = ADD32(ctx->r2, 0);
    // 0x80101470: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80101474: bne         $s1, $v0, L_801014E0
    if (ctx->r17 != ctx->r2) {
        // 0x80101478: nop
    
            goto L_801014E0;
    }
    // 0x80101478: nop

    // 0x8010147C: jal         0x800C759C
    // 0x80101480: addiu       $a0, $zero, 0x23
    ctx->r4 = ADD32(0, 0X23);
    getObjectiveBoolean(rdram, ctx);
        goto after_39;
    // 0x80101480: addiu       $a0, $zero, 0x23
    ctx->r4 = ADD32(0, 0X23);
    after_39:
    // 0x80101484: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    // 0x80101488: bne         $s0, $s1, L_801014E0
    if (ctx->r16 != ctx->r17) {
        // 0x8010148C: nop
    
            goto L_801014E0;
    }
    // 0x8010148C: nop

    // 0x80101490: jal         0x800C759C
    // 0x80101494: addiu       $a0, $zero, 0x2D
    ctx->r4 = ADD32(0, 0X2D);
    getObjectiveBoolean(rdram, ctx);
        goto after_40;
    // 0x80101494: addiu       $a0, $zero, 0x2D
    ctx->r4 = ADD32(0, 0X2D);
    after_40:
    // 0x80101498: addu        $s1, $v0, $zero
    ctx->r17 = ADD32(ctx->r2, 0);
    // 0x8010149C: bne         $s1, $s0, L_801014E0
    if (ctx->r17 != ctx->r16) {
        // 0x801014A0: nop
    
            goto L_801014E0;
    }
    // 0x801014A0: nop

    // 0x801014A4: jal         0x800C759C
    // 0x801014A8: addiu       $a0, $zero, 0x2E
    ctx->r4 = ADD32(0, 0X2E);
    getObjectiveBoolean(rdram, ctx);
        goto after_41;
    // 0x801014A8: addiu       $a0, $zero, 0x2E
    ctx->r4 = ADD32(0, 0X2E);
    after_41:
    // 0x801014AC: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    // 0x801014B0: bne         $s0, $s1, L_801014E0
    if (ctx->r16 != ctx->r17) {
        // 0x801014B4: nop
    
            goto L_801014E0;
    }
    // 0x801014B4: nop

    // 0x801014B8: jal         0x800C759C
    // 0x801014BC: addiu       $a0, $zero, 0x2F
    ctx->r4 = ADD32(0, 0X2F);
    getObjectiveBoolean(rdram, ctx);
        goto after_42;
    // 0x801014BC: addiu       $a0, $zero, 0x2F
    ctx->r4 = ADD32(0, 0X2F);
    after_42:
    // 0x801014C0: bne         $v0, $s0, L_801014E0
    if (ctx->r2 != ctx->r16) {
        // 0x801014C4: nop
    
            goto L_801014E0;
    }
    // 0x801014C4: nop

    // 0x801014C8: jal         0x800C759C
    // 0x801014CC: addiu       $a0, $zero, 0x36
    ctx->r4 = ADD32(0, 0X36);
    getObjectiveBoolean(rdram, ctx);
        goto after_43;
    // 0x801014CC: addiu       $a0, $zero, 0x36
    ctx->r4 = ADD32(0, 0X36);
    after_43:
    // 0x801014D0: bne         $v0, $zero, L_801014E0
    if (ctx->r2 != 0) {
        // 0x801014D4: addiu       $a0, $zero, 0x36
        ctx->r4 = ADD32(0, 0X36);
            goto L_801014E0;
    }
    // 0x801014D4: addiu       $a0, $zero, 0x36
    ctx->r4 = ADD32(0, 0X36);
    // 0x801014D8: jal         0x800C7540
    // 0x801014DC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    setObjectiveBoolean(rdram, ctx);
        goto after_44;
    // 0x801014DC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_44:
L_801014E0:
    // 0x801014E0: jal         0x800C759C
    // 0x801014E4: addiu       $a0, $zero, 0x24
    ctx->r4 = ADD32(0, 0X24);
    getObjectiveBoolean(rdram, ctx);
        goto after_45;
    // 0x801014E4: addiu       $a0, $zero, 0x24
    ctx->r4 = ADD32(0, 0X24);
    after_45:
    // 0x801014E8: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    // 0x801014EC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x801014F0: bne         $s0, $v0, L_80101520
    if (ctx->r16 != ctx->r2) {
        // 0x801014F4: nop
    
            goto L_80101520;
    }
    // 0x801014F4: nop

    // 0x801014F8: jal         0x800C759C
    // 0x801014FC: addiu       $a0, $zero, 0x25
    ctx->r4 = ADD32(0, 0X25);
    getObjectiveBoolean(rdram, ctx);
        goto after_46;
    // 0x801014FC: addiu       $a0, $zero, 0x25
    ctx->r4 = ADD32(0, 0X25);
    after_46:
    // 0x80101500: bne         $v0, $s0, L_80101520
    if (ctx->r2 != ctx->r16) {
        // 0x80101504: nop
    
            goto L_80101520;
    }
    // 0x80101504: nop

    // 0x80101508: jal         0x800C759C
    // 0x8010150C: addiu       $a0, $zero, 0x37
    ctx->r4 = ADD32(0, 0X37);
    getObjectiveBoolean(rdram, ctx);
        goto after_47;
    // 0x8010150C: addiu       $a0, $zero, 0x37
    ctx->r4 = ADD32(0, 0X37);
    after_47:
    // 0x80101510: bne         $v0, $zero, L_80101520
    if (ctx->r2 != 0) {
        // 0x80101514: addiu       $a0, $zero, 0x37
        ctx->r4 = ADD32(0, 0X37);
            goto L_80101520;
    }
    // 0x80101514: addiu       $a0, $zero, 0x37
    ctx->r4 = ADD32(0, 0X37);
    // 0x80101518: jal         0x800C7540
    // 0x8010151C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    setObjectiveBoolean(rdram, ctx);
        goto after_48;
    // 0x8010151C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_48:
L_80101520:
    // 0x80101520: jal         0x800C759C
    // 0x80101524: addiu       $a0, $zero, 0x18
    ctx->r4 = ADD32(0, 0X18);
    getObjectiveBoolean(rdram, ctx);
        goto after_49;
    // 0x80101524: addiu       $a0, $zero, 0x18
    ctx->r4 = ADD32(0, 0X18);
    after_49:
    // 0x80101528: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    // 0x8010152C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80101530: bne         $s0, $v0, L_80101560
    if (ctx->r16 != ctx->r2) {
        // 0x80101534: nop
    
            goto L_80101560;
    }
    // 0x80101534: nop

    // 0x80101538: jal         0x800C759C
    // 0x8010153C: addiu       $a0, $zero, 0x19
    ctx->r4 = ADD32(0, 0X19);
    getObjectiveBoolean(rdram, ctx);
        goto after_50;
    // 0x8010153C: addiu       $a0, $zero, 0x19
    ctx->r4 = ADD32(0, 0X19);
    after_50:
    // 0x80101540: bne         $v0, $s0, L_80101560
    if (ctx->r2 != ctx->r16) {
        // 0x80101544: nop
    
            goto L_80101560;
    }
    // 0x80101544: nop

    // 0x80101548: jal         0x800C759C
    // 0x8010154C: addiu       $a0, $zero, 0x1A
    ctx->r4 = ADD32(0, 0X1A);
    getObjectiveBoolean(rdram, ctx);
        goto after_51;
    // 0x8010154C: addiu       $a0, $zero, 0x1A
    ctx->r4 = ADD32(0, 0X1A);
    after_51:
    // 0x80101550: bne         $v0, $zero, L_80101560
    if (ctx->r2 != 0) {
        // 0x80101554: addiu       $a0, $zero, 0x1A
        ctx->r4 = ADD32(0, 0X1A);
            goto L_80101560;
    }
    // 0x80101554: addiu       $a0, $zero, 0x1A
    ctx->r4 = ADD32(0, 0X1A);
    // 0x80101558: jal         0x800C7540
    // 0x8010155C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    setObjectiveBoolean(rdram, ctx);
        goto after_52;
    // 0x8010155C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_52:
L_80101560:
    // 0x80101560: jal         0x800C759C
    // 0x80101564: addiu       $a0, $zero, 0x1B
    ctx->r4 = ADD32(0, 0X1B);
    getObjectiveBoolean(rdram, ctx);
        goto after_53;
    // 0x80101564: addiu       $a0, $zero, 0x1B
    ctx->r4 = ADD32(0, 0X1B);
    after_53:
    // 0x80101568: addu        $s1, $v0, $zero
    ctx->r17 = ADD32(ctx->r2, 0);
    // 0x8010156C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80101570: bne         $s1, $v0, L_801015B4
    if (ctx->r17 != ctx->r2) {
        // 0x80101574: nop
    
            goto L_801015B4;
    }
    // 0x80101574: nop

    // 0x80101578: jal         0x800C759C
    // 0x8010157C: addiu       $a0, $zero, 0x1C
    ctx->r4 = ADD32(0, 0X1C);
    getObjectiveBoolean(rdram, ctx);
        goto after_54;
    // 0x8010157C: addiu       $a0, $zero, 0x1C
    ctx->r4 = ADD32(0, 0X1C);
    after_54:
    // 0x80101580: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    // 0x80101584: bne         $s0, $s1, L_801015B4
    if (ctx->r16 != ctx->r17) {
        // 0x80101588: nop
    
            goto L_801015B4;
    }
    // 0x80101588: nop

    // 0x8010158C: jal         0x800C759C
    // 0x80101590: addiu       $a0, $zero, 0x1D
    ctx->r4 = ADD32(0, 0X1D);
    getObjectiveBoolean(rdram, ctx);
        goto after_55;
    // 0x80101590: addiu       $a0, $zero, 0x1D
    ctx->r4 = ADD32(0, 0X1D);
    after_55:
    // 0x80101594: bne         $v0, $s0, L_801015B4
    if (ctx->r2 != ctx->r16) {
        // 0x80101598: nop
    
            goto L_801015B4;
    }
    // 0x80101598: nop

    // 0x8010159C: jal         0x800C759C
    // 0x801015A0: addiu       $a0, $zero, 0x1E
    ctx->r4 = ADD32(0, 0X1E);
    getObjectiveBoolean(rdram, ctx);
        goto after_56;
    // 0x801015A0: addiu       $a0, $zero, 0x1E
    ctx->r4 = ADD32(0, 0X1E);
    after_56:
    // 0x801015A4: bne         $v0, $zero, L_801015B4
    if (ctx->r2 != 0) {
        // 0x801015A8: addiu       $a0, $zero, 0x1E
        ctx->r4 = ADD32(0, 0X1E);
            goto L_801015B4;
    }
    // 0x801015A8: addiu       $a0, $zero, 0x1E
    ctx->r4 = ADD32(0, 0X1E);
    // 0x801015AC: jal         0x800C7540
    // 0x801015B0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    setObjectiveBoolean(rdram, ctx);
        goto after_57;
    // 0x801015B0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_57:
L_801015B4:
    // 0x801015B4: jal         0x800C759C
    // 0x801015B8: addiu       $a0, $zero, 0x28
    ctx->r4 = ADD32(0, 0X28);
    getObjectiveBoolean(rdram, ctx);
        goto after_58;
    // 0x801015B8: addiu       $a0, $zero, 0x28
    ctx->r4 = ADD32(0, 0X28);
    after_58:
    // 0x801015BC: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    // 0x801015C0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x801015C4: bne         $s0, $v0, L_8010161C
    if (ctx->r16 != ctx->r2) {
        // 0x801015C8: nop
    
            goto L_8010161C;
    }
    // 0x801015C8: nop

    // 0x801015CC: jal         0x800C759C
    // 0x801015D0: addiu       $a0, $zero, 0x29
    ctx->r4 = ADD32(0, 0X29);
    getObjectiveBoolean(rdram, ctx);
        goto after_59;
    // 0x801015D0: addiu       $a0, $zero, 0x29
    ctx->r4 = ADD32(0, 0X29);
    after_59:
    // 0x801015D4: addu        $s1, $v0, $zero
    ctx->r17 = ADD32(ctx->r2, 0);
    // 0x801015D8: bne         $s1, $s0, L_8010161C
    if (ctx->r17 != ctx->r16) {
        // 0x801015DC: nop
    
            goto L_8010161C;
    }
    // 0x801015DC: nop

    // 0x801015E0: jal         0x800C759C
    // 0x801015E4: addiu       $a0, $zero, 0x2A
    ctx->r4 = ADD32(0, 0X2A);
    getObjectiveBoolean(rdram, ctx);
        goto after_60;
    // 0x801015E4: addiu       $a0, $zero, 0x2A
    ctx->r4 = ADD32(0, 0X2A);
    after_60:
    // 0x801015E8: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    // 0x801015EC: bne         $s0, $s1, L_8010161C
    if (ctx->r16 != ctx->r17) {
        // 0x801015F0: nop
    
            goto L_8010161C;
    }
    // 0x801015F0: nop

    // 0x801015F4: jal         0x800C759C
    // 0x801015F8: addiu       $a0, $zero, 0x2B
    ctx->r4 = ADD32(0, 0X2B);
    getObjectiveBoolean(rdram, ctx);
        goto after_61;
    // 0x801015F8: addiu       $a0, $zero, 0x2B
    ctx->r4 = ADD32(0, 0X2B);
    after_61:
    // 0x801015FC: bne         $v0, $s0, L_8010161C
    if (ctx->r2 != ctx->r16) {
        // 0x80101600: nop
    
            goto L_8010161C;
    }
    // 0x80101600: nop

    // 0x80101604: jal         0x800C759C
    // 0x80101608: addiu       $a0, $zero, 0x2C
    ctx->r4 = ADD32(0, 0X2C);
    getObjectiveBoolean(rdram, ctx);
        goto after_62;
    // 0x80101608: addiu       $a0, $zero, 0x2C
    ctx->r4 = ADD32(0, 0X2C);
    after_62:
    // 0x8010160C: bne         $v0, $zero, L_8010161C
    if (ctx->r2 != 0) {
        // 0x80101610: addiu       $a0, $zero, 0x2C
        ctx->r4 = ADD32(0, 0X2C);
            goto L_8010161C;
    }
    // 0x80101610: addiu       $a0, $zero, 0x2C
    ctx->r4 = ADD32(0, 0X2C);
    // 0x80101614: jal         0x800C7540
    // 0x80101618: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    setObjectiveBoolean(rdram, ctx);
        goto after_63;
    // 0x80101618: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_63:
L_8010161C:
    // 0x8010161C: jal         0x800C759C
    // 0x80101620: addiu       $a0, $zero, 0x2D
    ctx->r4 = ADD32(0, 0X2D);
    getObjectiveBoolean(rdram, ctx);
        goto after_64;
    // 0x80101620: addiu       $a0, $zero, 0x2D
    ctx->r4 = ADD32(0, 0X2D);
    after_64:
    // 0x80101624: addu        $s1, $v0, $zero
    ctx->r17 = ADD32(ctx->r2, 0);
    // 0x80101628: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8010162C: bne         $s1, $v0, L_80101678
    if (ctx->r17 != ctx->r2) {
        // 0x80101630: lui         $s0, 0x8011
        ctx->r16 = S32(0X8011 << 16);
            goto L_80101678;
    }
    // 0x80101630: lui         $s0, 0x8011
    ctx->r16 = S32(0X8011 << 16);
    // 0x80101634: jal         0x800C759C
    // 0x80101638: addiu       $a0, $zero, 0x2E
    ctx->r4 = ADD32(0, 0X2E);
    getObjectiveBoolean(rdram, ctx);
        goto after_65;
    // 0x80101638: addiu       $a0, $zero, 0x2E
    ctx->r4 = ADD32(0, 0X2E);
    after_65:
    // 0x8010163C: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    // 0x80101640: bnel        $s0, $s1, L_80101678
    if (ctx->r16 != ctx->r17) {
        // 0x80101644: lui         $s0, 0x8011
        ctx->r16 = S32(0X8011 << 16);
            goto L_80101678;
    }
    goto skip_0;
    // 0x80101644: lui         $s0, 0x8011
    ctx->r16 = S32(0X8011 << 16);
    skip_0:
    // 0x80101648: jal         0x800C759C
    // 0x8010164C: addiu       $a0, $zero, 0x2F
    ctx->r4 = ADD32(0, 0X2F);
    getObjectiveBoolean(rdram, ctx);
        goto after_66;
    // 0x8010164C: addiu       $a0, $zero, 0x2F
    ctx->r4 = ADD32(0, 0X2F);
    after_66:
    // 0x80101650: bne         $v0, $s0, L_80101678
    if (ctx->r2 != ctx->r16) {
        // 0x80101654: lui         $s0, 0x8011
        ctx->r16 = S32(0X8011 << 16);
            goto L_80101678;
    }
    // 0x80101654: lui         $s0, 0x8011
    ctx->r16 = S32(0X8011 << 16);
    // 0x80101658: jal         0x800C759C
    // 0x8010165C: addiu       $a0, $zero, 0x30
    ctx->r4 = ADD32(0, 0X30);
    getObjectiveBoolean(rdram, ctx);
        goto after_67;
    // 0x8010165C: addiu       $a0, $zero, 0x30
    ctx->r4 = ADD32(0, 0X30);
    after_67:
    // 0x80101660: bne         $v0, $zero, L_80101678
    if (ctx->r2 != 0) {
        // 0x80101664: lui         $s0, 0x8011
        ctx->r16 = S32(0X8011 << 16);
            goto L_80101678;
    }
    // 0x80101664: lui         $s0, 0x8011
    ctx->r16 = S32(0X8011 << 16);
    // 0x80101668: addiu       $a0, $zero, 0x30
    ctx->r4 = ADD32(0, 0X30);
    // 0x8010166C: jal         0x800C7540
    // 0x80101670: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    setObjectiveBoolean(rdram, ctx);
        goto after_68;
    // 0x80101670: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_68:
    // 0x80101674: lui         $s0, 0x8011
    ctx->r16 = S32(0X8011 << 16);
L_80101678:
    // 0x80101678: lw          $v1, -0x4958($s0)
    ctx->r3 = MEM_W(ctx->r16, -0X4958);
    // 0x8010167C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80101680: bne         $v1, $v0, L_801016AC
    if (ctx->r3 != ctx->r2) {
        // 0x80101684: lui         $a3, 0x8011
        ctx->r7 = S32(0X8011 << 16);
            goto L_801016AC;
    }
    // 0x80101684: lui         $a3, 0x8011
    ctx->r7 = S32(0X8011 << 16);
    // 0x80101688: jal         0x800C76E0
    // 0x8010168C: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    getObjectiveTimer(rdram, ctx);
        goto after_69;
    // 0x8010168C: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    after_69:
    // 0x80101690: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80101694: lwc1        $f2, -0x6A80($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X6A80);
    // 0x80101698: c.le.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl <= ctx->f0.fl;
    // 0x8010169C: nop

    // 0x801016A0: bc1tl       L_801016A8
    if (c1cs) {
        // 0x801016A4: sw          $zero, -0x4958($s0)
        MEM_W(-0X4958, ctx->r16) = 0;
            goto L_801016A8;
    }
    goto skip_1;
    // 0x801016A4: sw          $zero, -0x4958($s0)
    MEM_W(-0X4958, ctx->r16) = 0;
    skip_1:
L_801016A8:
    // 0x801016A8: lui         $a3, 0x8011
    ctx->r7 = S32(0X8011 << 16);
L_801016AC:
    // 0x801016AC: lw          $v0, -0x4958($a3)
    ctx->r2 = MEM_W(ctx->r7, -0X4958);
    // 0x801016B0: bne         $v0, $zero, L_801018D0
    if (ctx->r2 != 0) {
        // 0x801016B4: addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
            goto L_801018D0;
    }
    // 0x801016B4: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // 0x801016B8: lui         $a2, 0x8011
    ctx->r6 = S32(0X8011 << 16);
    // 0x801016BC: lw          $v1, -0x4970($a2)
    ctx->r3 = MEM_W(ctx->r6, -0X4970);
    // 0x801016C0: bne         $v1, $zero, L_801016E4
    if (ctx->r3 != 0) {
        // 0x801016C4: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_801016E4;
    }
    // 0x801016C4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x801016C8: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    // 0x801016CC: lui         $a1, 0x40A0
    ctx->r5 = S32(0X40A0 << 16);
    // 0x801016D0: sw          $v0, -0x4970($a2)
    MEM_W(-0X4970, ctx->r6) = ctx->r2;
    // 0x801016D4: jal         0x800C76FC
    // 0x801016D8: sw          $v0, -0x4958($a3)
    MEM_W(-0X4958, ctx->r7) = ctx->r2;
    setObjectiveTimer(rdram, ctx);
        goto after_70;
    // 0x801016D8: sw          $v0, -0x4958($a3)
    MEM_W(-0X4958, ctx->r7) = ctx->r2;
    after_70:
    // 0x801016DC: j           L_801018D0
    // 0x801016E0: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
        goto L_801018D0;
    // 0x801016E0: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_801016E4:
    // 0x801016E4: bne         $v1, $v0, L_80101728
    if (ctx->r3 != ctx->r2) {
        // 0x801016E8: lui         $v0, 0x8011
        ctx->r2 = S32(0X8011 << 16);
            goto L_80101728;
    }
    // 0x801016E8: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x801016EC: lui         $a2, 0x8011
    ctx->r6 = S32(0X8011 << 16);
    // 0x801016F0: lw          $v0, -0x496C($a2)
    ctx->r2 = MEM_W(ctx->r6, -0X496C);
    // 0x801016F4: bne         $v0, $zero, L_80101728
    if (ctx->r2 != 0) {
        // 0x801016F8: lui         $v0, 0x8011
        ctx->r2 = S32(0X8011 << 16);
            goto L_80101728;
    }
    // 0x801016F8: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x801016FC: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    // 0x80101700: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x80101704: sw          $v1, -0x496C($a2)
    MEM_W(-0X496C, ctx->r6) = ctx->r3;
    // 0x80101708: jal         0x800C76FC
    // 0x8010170C: sw          $v1, -0x4958($a3)
    MEM_W(-0X4958, ctx->r7) = ctx->r3;
    setObjectiveTimer(rdram, ctx);
        goto after_71;
    // 0x8010170C: sw          $v1, -0x4958($a3)
    MEM_W(-0X4958, ctx->r7) = ctx->r3;
    after_71:
    // 0x80101710: lui         $a1, 0x3E99
    ctx->r5 = S32(0X3E99 << 16);
    // 0x80101714: ori         $a1, $a1, 0x999A
    ctx->r5 = ctx->r5 | 0X999A;
    // 0x80101718: jal         0x800C7D1C
    // 0x8010171C: addiu       $a0, $zero, 0x224
    ctx->r4 = ADD32(0, 0X224);
    playObjectiveVoiceLine2(rdram, ctx);
        goto after_72;
    // 0x8010171C: addiu       $a0, $zero, 0x224
    ctx->r4 = ADD32(0, 0X224);
    after_72:
    // 0x80101720: j           L_801018D0
    // 0x80101724: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
        goto L_801018D0;
    // 0x80101724: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_80101728:
    // 0x80101728: lw          $v1, -0x496C($v0)
    ctx->r3 = MEM_W(ctx->r2, -0X496C);
    // 0x8010172C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80101730: bne         $v1, $v0, L_80101778
    if (ctx->r3 != ctx->r2) {
        // 0x80101734: lui         $a2, 0x8011
        ctx->r6 = S32(0X8011 << 16);
            goto L_80101778;
    }
    // 0x80101734: lui         $a2, 0x8011
    ctx->r6 = S32(0X8011 << 16);
    // 0x80101738: lw          $v0, -0x4968($a2)
    ctx->r2 = MEM_W(ctx->r6, -0X4968);
    // 0x8010173C: bne         $v0, $zero, L_80101778
    if (ctx->r2 != 0) {
        // 0x80101740: addiu       $a0, $zero, 0x7
        ctx->r4 = ADD32(0, 0X7);
            goto L_80101778;
    }
    // 0x80101740: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    // 0x80101744: lui         $a1, 0x40A0
    ctx->r5 = S32(0X40A0 << 16);
    // 0x80101748: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x8010174C: sw          $v1, -0x4968($a2)
    MEM_W(-0X4968, ctx->r6) = ctx->r3;
    // 0x80101750: jal         0x800C76FC
    // 0x80101754: sw          $v1, -0x4958($v0)
    MEM_W(-0X4958, ctx->r2) = ctx->r3;
    setObjectiveTimer(rdram, ctx);
        goto after_73;
    // 0x80101754: sw          $v1, -0x4958($v0)
    MEM_W(-0X4958, ctx->r2) = ctx->r3;
    after_73:
    // 0x80101758: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x8010175C: jal         0x800C7660
    // 0x80101760: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    setObjectiveHiddenFlag(rdram, ctx);
        goto after_74;
    // 0x80101760: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_74:
    // 0x80101764: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x80101768: jal         0x800C7660
    // 0x8010176C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    setObjectiveHiddenFlag(rdram, ctx);
        goto after_75;
    // 0x8010176C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_75:
    // 0x80101770: j           L_801018D0
    // 0x80101774: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
        goto L_801018D0;
    // 0x80101774: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_80101778:
    // 0x80101778: jal         0x800C759C
    // 0x8010177C: addiu       $a0, $zero, 0x1F
    ctx->r4 = ADD32(0, 0X1F);
    getObjectiveBoolean(rdram, ctx);
        goto after_76;
    // 0x8010177C: addiu       $a0, $zero, 0x1F
    ctx->r4 = ADD32(0, 0X1F);
    after_76:
    // 0x80101780: bne         $v0, $zero, L_801017E4
    if (ctx->r2 != 0) {
        // 0x80101784: nop
    
            goto L_801017E4;
    }
    // 0x80101784: nop

    // 0x80101788: jal         0x800C759C
    // 0x8010178C: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    getObjectiveBoolean(rdram, ctx);
        goto after_77;
    // 0x8010178C: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    after_77:
    // 0x80101790: bne         $v0, $zero, L_801017E4
    if (ctx->r2 != 0) {
        // 0x80101794: nop
    
            goto L_801017E4;
    }
    // 0x80101794: nop

    // 0x80101798: jal         0x800C759C
    // 0x8010179C: addiu       $a0, $zero, 0x1A
    ctx->r4 = ADD32(0, 0X1A);
    getObjectiveBoolean(rdram, ctx);
        goto after_78;
    // 0x8010179C: addiu       $a0, $zero, 0x1A
    ctx->r4 = ADD32(0, 0X1A);
    after_78:
    // 0x801017A0: bne         $v0, $zero, L_801017E4
    if (ctx->r2 != 0) {
        // 0x801017A4: lui         $a2, 0x8011
        ctx->r6 = S32(0X8011 << 16);
            goto L_801017E4;
    }
    // 0x801017A4: lui         $a2, 0x8011
    ctx->r6 = S32(0X8011 << 16);
    // 0x801017A8: lw          $v0, -0x4964($a2)
    ctx->r2 = MEM_W(ctx->r6, -0X4964);
    // 0x801017AC: bne         $v0, $zero, L_801017E4
    if (ctx->r2 != 0) {
        // 0x801017B0: addiu       $a0, $zero, 0x7
        ctx->r4 = ADD32(0, 0X7);
            goto L_801017E4;
    }
    // 0x801017B0: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    // 0x801017B4: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x801017B8: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    // 0x801017BC: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x801017C0: sw          $v1, -0x4964($a2)
    MEM_W(-0X4964, ctx->r6) = ctx->r3;
    // 0x801017C4: jal         0x800C76FC
    // 0x801017C8: sw          $v1, -0x4958($v0)
    MEM_W(-0X4958, ctx->r2) = ctx->r3;
    setObjectiveTimer(rdram, ctx);
        goto after_79;
    // 0x801017C8: sw          $v1, -0x4958($v0)
    MEM_W(-0X4958, ctx->r2) = ctx->r3;
    after_79:
    // 0x801017CC: lui         $a1, 0x3E99
    ctx->r5 = S32(0X3E99 << 16);
    // 0x801017D0: ori         $a1, $a1, 0x999A
    ctx->r5 = ctx->r5 | 0X999A;
    // 0x801017D4: jal         0x800C7D1C
    // 0x801017D8: addiu       $a0, $zero, 0x225
    ctx->r4 = ADD32(0, 0X225);
    playObjectiveVoiceLine2(rdram, ctx);
        goto after_80;
    // 0x801017D8: addiu       $a0, $zero, 0x225
    ctx->r4 = ADD32(0, 0X225);
    after_80:
    // 0x801017DC: j           L_801018D0
    // 0x801017E0: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
        goto L_801018D0;
    // 0x801017E0: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_801017E4:
    // 0x801017E4: jal         0x800C759C
    // 0x801017E8: addiu       $a0, $zero, 0x16
    ctx->r4 = ADD32(0, 0X16);
    getObjectiveBoolean(rdram, ctx);
        goto after_81;
    // 0x801017E8: addiu       $a0, $zero, 0x16
    ctx->r4 = ADD32(0, 0X16);
    after_81:
    // 0x801017EC: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // 0x801017F0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x801017F4: bne         $v1, $v0, L_80101834
    if (ctx->r3 != ctx->r2) {
        // 0x801017F8: lui         $a2, 0x8011
        ctx->r6 = S32(0X8011 << 16);
            goto L_80101834;
    }
    // 0x801017F8: lui         $a2, 0x8011
    ctx->r6 = S32(0X8011 << 16);
    // 0x801017FC: lw          $v0, -0x4960($a2)
    ctx->r2 = MEM_W(ctx->r6, -0X4960);
    // 0x80101800: bne         $v0, $zero, L_80101834
    if (ctx->r2 != 0) {
        // 0x80101804: addiu       $a0, $zero, 0x7
        ctx->r4 = ADD32(0, 0X7);
            goto L_80101834;
    }
    // 0x80101804: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    // 0x80101808: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x8010180C: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x80101810: sw          $v1, -0x4960($a2)
    MEM_W(-0X4960, ctx->r6) = ctx->r3;
    // 0x80101814: jal         0x800C76FC
    // 0x80101818: sw          $v1, -0x4958($v0)
    MEM_W(-0X4958, ctx->r2) = ctx->r3;
    setObjectiveTimer(rdram, ctx);
        goto after_82;
    // 0x80101818: sw          $v1, -0x4958($v0)
    MEM_W(-0X4958, ctx->r2) = ctx->r3;
    after_82:
    // 0x8010181C: lui         $a1, 0x3E99
    ctx->r5 = S32(0X3E99 << 16);
    // 0x80101820: ori         $a1, $a1, 0x999A
    ctx->r5 = ctx->r5 | 0X999A;
    // 0x80101824: jal         0x800C7D1C
    // 0x80101828: addiu       $a0, $zero, 0x1F0
    ctx->r4 = ADD32(0, 0X1F0);
    playObjectiveVoiceLine2(rdram, ctx);
        goto after_83;
    // 0x80101828: addiu       $a0, $zero, 0x1F0
    ctx->r4 = ADD32(0, 0X1F0);
    after_83:
    // 0x8010182C: j           L_801018D0
    // 0x80101830: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
        goto L_801018D0;
    // 0x80101830: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_80101834:
    // 0x80101834: jal         0x800C761C
    // 0x80101838: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    getObjectiveCount(rdram, ctx);
        goto after_84;
    // 0x80101838: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_84:
    // 0x8010183C: slti        $v0, $v0, 0x15
    ctx->r2 = SIGNED(ctx->r2) < 0X15 ? 1 : 0;
    // 0x80101840: bne         $v0, $zero, L_801018D0
    if (ctx->r2 != 0) {
        // 0x80101844: addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
            goto L_801018D0;
    }
    // 0x80101844: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // 0x80101848: lui         $a1, 0x8011
    ctx->r5 = S32(0X8011 << 16);
    // 0x8010184C: lw          $v0, -0x495C($a1)
    ctx->r2 = MEM_W(ctx->r5, -0X495C);
    // 0x80101850: bne         $v0, $zero, L_801018D0
    if (ctx->r2 != 0) {
        // 0x80101854: addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
            goto L_801018D0;
    }
    // 0x80101854: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // 0x80101858: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8010185C: addu        $v1, $a0, $zero
    ctx->r3 = ADD32(ctx->r4, 0);
    // 0x80101860: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x80101864: sw          $v1, -0x495C($a1)
    MEM_W(-0X495C, ctx->r5) = ctx->r3;
    // 0x80101868: jal         0x800C76B0
    // 0x8010186C: sw          $v1, -0x4958($v0)
    MEM_W(-0X4958, ctx->r2) = ctx->r3;
    activateObjectiveCompleteFlag(rdram, ctx);
        goto after_85;
    // 0x8010186C: sw          $v1, -0x4958($v0)
    MEM_W(-0X4958, ctx->r2) = ctx->r3;
    after_85:
    // 0x80101870: jal         0x800C76B0
    // 0x80101874: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    activateObjectiveCompleteFlag(rdram, ctx);
        goto after_86;
    // 0x80101874: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_86:
    // 0x80101878: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x8010187C: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x80101880: jal         0x800C7884
    // 0x80101884: addiu       $a0, $a0, -0x6AA0
    ctx->r4 = ADD32(ctx->r4, -0X6AA0);
    func_800C7884(rdram, ctx);
        goto after_87;
    // 0x80101884: addiu       $a0, $a0, -0x6AA0
    ctx->r4 = ADD32(ctx->r4, -0X6AA0);
    after_87:
    // 0x80101888: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x8010188C: jal         0x800C76FC
    // 0x80101890: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    setObjectiveTimer(rdram, ctx);
        goto after_88;
    // 0x80101890: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    after_88:
    // 0x80101894: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80101898: jal         0x800C76FC
    // 0x8010189C: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    setObjectiveTimer(rdram, ctx);
        goto after_89;
    // 0x8010189C: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    after_89:
    // 0x801018A0: lui         $a1, 0x4000
    ctx->r5 = S32(0X4000 << 16);
    // 0x801018A4: jal         0x800C7D1C
    // 0x801018A8: addiu       $a0, $zero, 0x228
    ctx->r4 = ADD32(0, 0X228);
    playObjectiveVoiceLine2(rdram, ctx);
        goto after_90;
    // 0x801018A8: addiu       $a0, $zero, 0x228
    ctx->r4 = ADD32(0, 0X228);
    after_90:
    // 0x801018AC: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x801018B0: jal         0x800C7660
    // 0x801018B4: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    setObjectiveHiddenFlag(rdram, ctx);
        goto after_91;
    // 0x801018B4: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_91:
    // 0x801018B8: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x801018BC: jal         0x800C7660
    // 0x801018C0: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    setObjectiveHiddenFlag(rdram, ctx);
        goto after_92;
    // 0x801018C0: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_92:
    // 0x801018C4: jal         0x800C7D98
    // 0x801018C8: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    func_800C7D98(rdram, ctx);
        goto after_93;
    // 0x801018C8: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    after_93:
    // 0x801018CC: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_801018D0:
    // 0x801018D0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801018D4: lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X18);
    // 0x801018D8: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x801018DC: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x801018E0: ldc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X20);
    // 0x801018E4: jr          $ra
    // 0x801018E8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x801018E8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_801018EC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801018EC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801018F0: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x801018F4: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x801018F8: lwc1        $f20, -0x6A7C($at)
    ctx->f20.u32l = MEM_W(ctx->r1, -0X6A7C);
    // 0x801018FC: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80101900: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x80101904: jal         0x800C7D1C
    // 0x80101908: addiu       $a0, $zero, 0x26E
    ctx->r4 = ADD32(0, 0X26E);
    playObjectiveVoiceLine2(rdram, ctx);
        goto after_0;
    // 0x80101908: addiu       $a0, $zero, 0x26E
    ctx->r4 = ADD32(0, 0X26E);
    after_0:
    // 0x8010190C: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80101910: jal         0x800C7D1C
    // 0x80101914: addiu       $a0, $zero, 0x148
    ctx->r4 = ADD32(0, 0X148);
    playObjectiveVoiceLine2(rdram, ctx);
        goto after_1;
    // 0x80101914: addiu       $a0, $zero, 0x148
    ctx->r4 = ADD32(0, 0X148);
    after_1:
    // 0x80101918: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x8010191C: jal         0x800C7D1C
    // 0x80101920: addiu       $a0, $zero, 0x270
    ctx->r4 = ADD32(0, 0X270);
    playObjectiveVoiceLine2(rdram, ctx);
        goto after_2;
    // 0x80101920: addiu       $a0, $zero, 0x270
    ctx->r4 = ADD32(0, 0X270);
    after_2:
    // 0x80101924: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x80101928: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x8010192C: jr          $ra
    // 0x80101930: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80101930: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_80101934(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80101934: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80101938: addiu       $a0, $zero, 0x73
    ctx->r4 = ADD32(0, 0X73);
    // 0x8010193C: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x80101940: jal         0x800C75C0
    // 0x80101944: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    setObjectiveCount(rdram, ctx);
        goto after_0;
    // 0x80101944: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    after_0:
    // 0x80101948: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x8010194C: jr          $ra
    // 0x80101950: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80101950: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void lv0_80101954(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80101954: jr          $ra
    // 0x80101958: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    return;
    // 0x80101958: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
;}
RECOMP_FUNC void lv0_calculateFriendliesSaved(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8010195C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80101960: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x80101964: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80101968: jal         0x800C761C
    // 0x8010196C: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    getObjectiveCount(rdram, ctx);
        goto after_0;
    // 0x8010196C: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    after_0:
    // 0x80101970: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x80101974: jal         0x800C761C
    // 0x80101978: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    getObjectiveCount(rdram, ctx);
        goto after_1;
    // 0x80101978: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    after_1:
    // 0x8010197C: addu        $s0, $s0, $v0
    ctx->r16 = ADD32(ctx->r16, ctx->r2);
    // 0x80101980: addiu       $a0, $zero, 0x33
    ctx->r4 = ADD32(0, 0X33);
    // 0x80101984: jal         0x800C77B0
    // 0x80101988: subu        $a0, $a0, $s0
    ctx->r4 = SUB32(ctx->r4, ctx->r16);
    setFriendliesSaved(rdram, ctx);
        goto after_2;
    // 0x80101988: subu        $a0, $a0, $s0
    ctx->r4 = SUB32(ctx->r4, ctx->r16);
    after_2:
    // 0x8010198C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80101990: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x80101994: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // 0x80101998: jr          $ra
    // 0x8010199C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8010199C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void lv1_initializeObjectTracking(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801019A0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x801019A4: addiu       $a0, $zero, 0x2F
    ctx->r4 = ADD32(0, 0X2F);
    // 0x801019A8: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x801019AC: lui         $s2, 0x8011
    ctx->r18 = S32(0X8011 << 16);
    // 0x801019B0: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x801019B4: lui         $s1, 0x8011
    ctx->r17 = S32(0X8011 << 16);
    // 0x801019B8: lui         $a1, 0x4000
    ctx->r5 = S32(0X4000 << 16);
    // 0x801019BC: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x801019C0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x801019C4: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
    // 0x801019C8: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x801019CC: sw          $zero, -0x2FC0($s2)
    MEM_W(-0X2FC0, ctx->r18) = 0;
    // 0x801019D0: sw          $zero, -0x2FBC($s1)
    MEM_W(-0X2FBC, ctx->r17) = 0;
    // 0x801019D4: jal         0x800C7D1C
    // 0x801019D8: sw          $s0, -0x4950($v0)
    MEM_W(-0X4950, ctx->r2) = ctx->r16;
    playObjectiveVoiceLine2(rdram, ctx);
        goto after_0;
    // 0x801019D8: sw          $s0, -0x4950($v0)
    MEM_W(-0X4950, ctx->r2) = ctx->r16;
    after_0:
    // 0x801019DC: addiu       $a0, $zero, 0x100
    ctx->r4 = ADD32(0, 0X100);
    // 0x801019E0: jal         0x800C7D1C
    // 0x801019E4: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    playObjectiveVoiceLine2(rdram, ctx);
        goto after_1;
    // 0x801019E4: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    after_1:
    // 0x801019E8: lui         $a0, 0x8010
    ctx->r4 = S32(0X8010 << 16);
    // 0x801019EC: addiu       $a0, $a0, 0x1AD8
    ctx->r4 = ADD32(ctx->r4, 0X1AD8);
    // 0x801019F0: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x801019F4: addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    // 0x801019F8: addiu       $a3, $zero, 0xD
    ctx->r7 = ADD32(0, 0XD);
    // 0x801019FC: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x80101A00: jal         0x800C7830
    // 0x80101A04: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    addBooleanCountHandleWrapper(rdram, ctx);
        goto after_2;
    // 0x80101A04: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    after_2:
    // 0x80101A08: lui         $a0, 0x8010
    ctx->r4 = S32(0X8010 << 16);
    // 0x80101A0C: addiu       $a0, $a0, 0x1B98
    ctx->r4 = ADD32(ctx->r4, 0X1B98);
    // 0x80101A10: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x80101A14: addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    // 0x80101A18: addiu       $a3, $zero, 0xD
    ctx->r7 = ADD32(0, 0XD);
    // 0x80101A1C: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x80101A20: jal         0x800C7830
    // 0x80101A24: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    addBooleanCountHandleWrapper(rdram, ctx);
        goto after_3;
    // 0x80101A24: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    after_3:
    // 0x80101A28: lui         $a0, 0x8010
    ctx->r4 = S32(0X8010 << 16);
    // 0x80101A2C: addiu       $a0, $a0, 0x1AF8
    ctx->r4 = ADD32(ctx->r4, 0X1AF8);
    // 0x80101A30: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    // 0x80101A34: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    // 0x80101A38: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    // 0x80101A3C: jal         0x800C7830
    // 0x80101A40: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    addBooleanCountHandleWrapper(rdram, ctx);
        goto after_4;
    // 0x80101A40: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_4:
    // 0x80101A44: lui         $a0, 0x8010
    ctx->r4 = S32(0X8010 << 16);
    // 0x80101A48: addiu       $a0, $a0, 0x1B34
    ctx->r4 = ADD32(ctx->r4, 0X1B34);
    // 0x80101A4C: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x80101A50: addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    // 0x80101A54: addiu       $a3, $zero, 0xA
    ctx->r7 = ADD32(0, 0XA);
    // 0x80101A58: jal         0x800C7830
    // 0x80101A5C: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    addBooleanCountHandleWrapper(rdram, ctx);
        goto after_5;
    // 0x80101A5C: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    after_5:
    // 0x80101A60: lui         $a0, 0x8010
    ctx->r4 = S32(0X8010 << 16);
    // 0x80101A64: addiu       $a0, $a0, 0x1B54
    ctx->r4 = ADD32(ctx->r4, 0X1B54);
    // 0x80101A68: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x80101A6C: addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    // 0x80101A70: addiu       $a3, $zero, 0x32
    ctx->r7 = ADD32(0, 0X32);
    // 0x80101A74: jal         0x800C7830
    // 0x80101A78: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    addBooleanCountHandleWrapper(rdram, ctx);
        goto after_6;
    // 0x80101A78: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    after_6:
    // 0x80101A7C: lui         $a0, 0x8010
    ctx->r4 = S32(0X8010 << 16);
    // 0x80101A80: addiu       $a0, $a0, 0x1B74
    ctx->r4 = ADD32(ctx->r4, 0X1B74);
    // 0x80101A84: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    // 0x80101A88: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    // 0x80101A8C: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    // 0x80101A90: jal         0x800C7830
    // 0x80101A94: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    addBooleanCountHandleWrapper(rdram, ctx);
        goto after_7;
    // 0x80101A94: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_7:
    // 0x80101A98: lui         $a0, 0x8010
    ctx->r4 = S32(0X8010 << 16);
    // 0x80101A9C: addiu       $a0, $a0, 0x1BB8
    ctx->r4 = ADD32(ctx->r4, 0X1BB8);
    // 0x80101AA0: addiu       $a1, $zero, 0xE
    ctx->r5 = ADD32(0, 0XE);
    // 0x80101AA4: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    // 0x80101AA8: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    // 0x80101AAC: jal         0x800C7830
    // 0x80101AB0: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    addBooleanCountHandleWrapper(rdram, ctx);
        goto after_8;
    // 0x80101AB0: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_8:
    // 0x80101AB4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80101AB8: sw          $zero, -0x2FC0($s2)
    MEM_W(-0X2FC0, ctx->r18) = 0;
    // 0x80101ABC: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80101AC0: sw          $zero, -0x2FBC($s1)
    MEM_W(-0X2FBC, ctx->r17) = 0;
    // 0x80101AC4: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80101AC8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80101ACC: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // 0x80101AD0: jr          $ra
    // 0x80101AD4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80101AD4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_80101AD8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80101AD8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80101ADC: addiu       $a0, $zero, 0xB
    ctx->r4 = ADD32(0, 0XB);
    // 0x80101AE0: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x80101AE4: jal         0x800C7D1C
    // 0x80101AE8: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    playObjectiveVoiceLine2(rdram, ctx);
        goto after_0;
    // 0x80101AE8: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    after_0:
    // 0x80101AEC: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x80101AF0: jr          $ra
    // 0x80101AF4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80101AF4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_80101AF8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80101AF8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80101AFC: addiu       $a0, $zero, 0x4C
    ctx->r4 = ADD32(0, 0X4C);
    // 0x80101B00: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x80101B04: jal         0x800C7D1C
    // 0x80101B08: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    playObjectiveVoiceLine2(rdram, ctx);
        goto after_0;
    // 0x80101B08: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    after_0:
    // 0x80101B0C: lui         $a1, 0x4040
    ctx->r5 = S32(0X4040 << 16);
    // 0x80101B10: jal         0x800C7D1C
    // 0x80101B14: addiu       $a0, $zero, 0x29C
    ctx->r4 = ADD32(0, 0X29C);
    playObjectiveVoiceLine2(rdram, ctx);
        goto after_1;
    // 0x80101B14: addiu       $a0, $zero, 0x29C
    ctx->r4 = ADD32(0, 0X29C);
    after_1:
    // 0x80101B18: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x80101B1C: addiu       $a0, $a0, -0x6A70
    ctx->r4 = ADD32(ctx->r4, -0X6A70);
    // 0x80101B20: jal         0x800C7D60
    // 0x80101B24: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    func_800C7D60(rdram, ctx);
        goto after_2;
    // 0x80101B24: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    after_2:
    // 0x80101B28: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x80101B2C: jr          $ra
    // 0x80101B30: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80101B30: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_80101B34(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80101B34: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80101B38: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    // 0x80101B3C: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x80101B40: jal         0x800C7D1C
    // 0x80101B44: addiu       $a0, $zero, 0x21C
    ctx->r4 = ADD32(0, 0X21C);
    playObjectiveVoiceLine2(rdram, ctx);
        goto after_0;
    // 0x80101B44: addiu       $a0, $zero, 0x21C
    ctx->r4 = ADD32(0, 0X21C);
    after_0:
    // 0x80101B48: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x80101B4C: jr          $ra
    // 0x80101B50: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80101B50: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_80101B54(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80101B54: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80101B58: lui         $a1, 0x3F00
    ctx->r5 = S32(0X3F00 << 16);
    // 0x80101B5C: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x80101B60: jal         0x800C7D1C
    // 0x80101B64: addiu       $a0, $zero, 0x4D
    ctx->r4 = ADD32(0, 0X4D);
    playObjectiveVoiceLine2(rdram, ctx);
        goto after_0;
    // 0x80101B64: addiu       $a0, $zero, 0x4D
    ctx->r4 = ADD32(0, 0X4D);
    after_0:
    // 0x80101B68: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x80101B6C: jr          $ra
    // 0x80101B70: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80101B70: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_80101B74(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80101B74: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80101B78: lui         $a1, 0x3E99
    ctx->r5 = S32(0X3E99 << 16);
    // 0x80101B7C: ori         $a1, $a1, 0x999A
    ctx->r5 = ctx->r5 | 0X999A;
    // 0x80101B80: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x80101B84: jal         0x800C7D1C
    // 0x80101B88: addiu       $a0, $zero, 0x1F8
    ctx->r4 = ADD32(0, 0X1F8);
    playObjectiveVoiceLine2(rdram, ctx);
        goto after_0;
    // 0x80101B88: addiu       $a0, $zero, 0x1F8
    ctx->r4 = ADD32(0, 0X1F8);
    after_0:
    // 0x80101B8C: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x80101B90: jr          $ra
    // 0x80101B94: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80101B94: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_80101B98(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80101B98: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80101B9C: lui         $a1, 0x3F00
    ctx->r5 = S32(0X3F00 << 16);
    // 0x80101BA0: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x80101BA4: jal         0x800C7D1C
    // 0x80101BA8: addiu       $a0, $zero, 0x22C
    ctx->r4 = ADD32(0, 0X22C);
    playObjectiveVoiceLine2(rdram, ctx);
        goto after_0;
    // 0x80101BA8: addiu       $a0, $zero, 0x22C
    ctx->r4 = ADD32(0, 0X22C);
    after_0:
    // 0x80101BAC: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x80101BB0: jr          $ra
    // 0x80101BB4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80101BB4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_80101BB8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80101BB8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80101BBC: addiu       $a0, $zero, 0x21C
    ctx->r4 = ADD32(0, 0X21C);
    // 0x80101BC0: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x80101BC4: jal         0x800C7D1C
    // 0x80101BC8: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    playObjectiveVoiceLine2(rdram, ctx);
        goto after_0;
    // 0x80101BC8: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    after_0:
    // 0x80101BCC: lui         $a1, 0x4000
    ctx->r5 = S32(0X4000 << 16);
    // 0x80101BD0: jal         0x800C7D1C
    // 0x80101BD4: addiu       $a0, $zero, 0x4D
    ctx->r4 = ADD32(0, 0X4D);
    playObjectiveVoiceLine2(rdram, ctx);
        goto after_1;
    // 0x80101BD4: addiu       $a0, $zero, 0x4D
    ctx->r4 = ADD32(0, 0X4D);
    after_1:
    // 0x80101BD8: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x80101BDC: jr          $ra
    // 0x80101BE0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80101BE0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void lv1_80101BE4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80101BE4: jr          $ra
    // 0x80101BE8: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    return;
    // 0x80101BE8: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
;}
RECOMP_FUNC void lv1_calculateFriendliesSaved(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80101BEC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80101BF0: addiu       $a0, $zero, 0x28
    ctx->r4 = ADD32(0, 0X28);
    // 0x80101BF4: sw          $ra, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r31;
    // 0x80101BF8: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x80101BFC: jal         0x800C761C
    // 0x80101C00: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    getObjectiveCount(rdram, ctx);
        goto after_0;
    // 0x80101C00: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    after_0:
    // 0x80101C04: addiu       $a0, $zero, 0xD
    ctx->r4 = ADD32(0, 0XD);
    // 0x80101C08: jal         0x800C761C
    // 0x80101C0C: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    getObjectiveCount(rdram, ctx);
        goto after_1;
    // 0x80101C0C: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    after_1:
    // 0x80101C10: addiu       $a0, $zero, 0x29
    ctx->r4 = ADD32(0, 0X29);
    // 0x80101C14: jal         0x800C761C
    // 0x80101C18: addu        $s1, $v0, $zero
    ctx->r17 = ADD32(ctx->r2, 0);
    getObjectiveCount(rdram, ctx);
        goto after_2;
    // 0x80101C18: addu        $s1, $v0, $zero
    ctx->r17 = ADD32(ctx->r2, 0);
    after_2:
    // 0x80101C1C: addu        $s0, $s0, $s1
    ctx->r16 = ADD32(ctx->r16, ctx->r17);
    // 0x80101C20: addu        $s0, $s0, $v0
    ctx->r16 = ADD32(ctx->r16, ctx->r2);
    // 0x80101C24: addiu       $a0, $zero, 0x13
    ctx->r4 = ADD32(0, 0X13);
    // 0x80101C28: jal         0x800C77B0
    // 0x80101C2C: subu        $a0, $a0, $s0
    ctx->r4 = SUB32(ctx->r4, ctx->r16);
    setFriendliesSaved(rdram, ctx);
        goto after_3;
    // 0x80101C2C: subu        $a0, $a0, $s0
    ctx->r4 = SUB32(ctx->r4, ctx->r16);
    after_3:
    // 0x80101C30: lw          $ra, 0x18($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X18);
    // 0x80101C34: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x80101C38: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x80101C3C: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // 0x80101C40: jr          $ra
    // 0x80101C44: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80101C44: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void lv1_checkComplexObjectives(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80101C48: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80101C4C: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x80101C50: lui         $s0, 0x8011
    ctx->r16 = S32(0X8011 << 16);
    // 0x80101C54: lw          $v0, -0x2FC0($s0)
    ctx->r2 = MEM_W(ctx->r16, -0X2FC0);
    // 0x80101C58: bne         $v0, $zero, L_80101CB8
    if (ctx->r2 != 0) {
        // 0x80101C5C: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_80101CB8;
    }
    // 0x80101C5C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80101C60: jal         0x800C761C
    // 0x80101C64: addiu       $a0, $zero, 0xD
    ctx->r4 = ADD32(0, 0XD);
    getObjectiveCount(rdram, ctx);
        goto after_0;
    // 0x80101C64: addiu       $a0, $zero, 0xD
    ctx->r4 = ADD32(0, 0XD);
    after_0:
    // 0x80101C68: slti        $v0, $v0, 0x5
    ctx->r2 = SIGNED(ctx->r2) < 0X5 ? 1 : 0;
    // 0x80101C6C: bne         $v0, $zero, L_80101C90
    if (ctx->r2 != 0) {
        // 0x80101C70: nop
    
            goto L_80101C90;
    }
    // 0x80101C70: nop

    // 0x80101C74: jal         0x800C7738
    // 0x80101C78: nop

    func_800C7738(rdram, ctx);
        goto after_1;
    // 0x80101C78: nop

    after_1:
    // 0x80101C7C: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    // 0x80101C80: jal         0x800C7D1C
    // 0x80101C84: addiu       $a0, $zero, 0x50
    ctx->r4 = ADD32(0, 0X50);
    playObjectiveVoiceLine2(rdram, ctx);
        goto after_2;
    // 0x80101C84: addiu       $a0, $zero, 0x50
    ctx->r4 = ADD32(0, 0X50);
    after_2:
    // 0x80101C88: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80101C8C: sw          $v0, -0x2FC0($s0)
    MEM_W(-0X2FC0, ctx->r16) = ctx->r2;
L_80101C90:
    // 0x80101C90: jal         0x800C759C
    // 0x80101C94: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    getObjectiveBoolean(rdram, ctx);
        goto after_3;
    // 0x80101C94: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    after_3:
    // 0x80101C98: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // 0x80101C9C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80101CA0: bne         $v1, $v0, L_80101CB8
    if (ctx->r3 != ctx->r2) {
        // 0x80101CA4: nop
    
            goto L_80101CB8;
    }
    // 0x80101CA4: nop

    // 0x80101CA8: jal         0x800C776C
    // 0x80101CAC: sw          $v1, -0x2FC0($s0)
    MEM_W(-0X2FC0, ctx->r16) = ctx->r3;
    func_800C776C(rdram, ctx);
        goto after_4;
    // 0x80101CAC: sw          $v1, -0x2FC0($s0)
    MEM_W(-0X2FC0, ctx->r16) = ctx->r3;
    after_4:
    // 0x80101CB0: jal         0x800C76B0
    // 0x80101CB4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    activateObjectiveCompleteFlag(rdram, ctx);
        goto after_5;
    // 0x80101CB4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_5:
L_80101CB8:
    // 0x80101CB8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80101CBC: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x80101CC0: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // 0x80101CC4: jr          $ra
    // 0x80101CC8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80101CC8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void fake_func_80101CCC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
;}
RECOMP_FUNC void lv2_initializeObjectTracking(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80101CD0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80101CD4: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80101CD8: lwc1        $f12, -0x6A50($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X6A50);
    // 0x80101CDC: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x80101CE0: sw          $zero, -0x493C($v0)
    MEM_W(-0X493C, ctx->r2) = 0;
    // 0x80101CE4: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x80101CE8: sw          $zero, -0x4938($v0)
    MEM_W(-0X4938, ctx->r2) = 0;
    // 0x80101CEC: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x80101CF0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80101CF4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80101CF8: jal         0x800C7CEC
    // 0x80101CFC: sw          $zero, -0x4934($v0)
    MEM_W(-0X4934, ctx->r2) = 0;
    func_800C7CEC(rdram, ctx);
        goto after_0;
    // 0x80101CFC: sw          $zero, -0x4934($v0)
    MEM_W(-0X4934, ctx->r2) = 0;
    after_0:
    // 0x80101D00: addiu       $a0, $zero, 0x20
    ctx->r4 = ADD32(0, 0X20);
    // 0x80101D04: jal         0x800C7540
    // 0x80101D08: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    setObjectiveBoolean(rdram, ctx);
        goto after_1;
    // 0x80101D08: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x80101D0C: lui         $a0, 0x8010
    ctx->r4 = S32(0X8010 << 16);
    // 0x80101D10: addiu       $a0, $a0, 0x26CC
    ctx->r4 = ADD32(ctx->r4, 0X26CC);
    // 0x80101D14: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x80101D18: addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    // 0x80101D1C: addiu       $a3, $zero, 0x3D
    ctx->r7 = ADD32(0, 0X3D);
    // 0x80101D20: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80101D24: jal         0x800C7830
    // 0x80101D28: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    addBooleanCountHandleWrapper(rdram, ctx);
        goto after_2;
    // 0x80101D28: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    after_2:
    // 0x80101D2C: lui         $a0, 0x8010
    ctx->r4 = S32(0X8010 << 16);
    // 0x80101D30: addiu       $a0, $a0, 0x26EC
    ctx->r4 = ADD32(ctx->r4, 0X26EC);
    // 0x80101D34: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x80101D38: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80101D3C: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    // 0x80101D40: jal         0x800C7830
    // 0x80101D44: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    addBooleanCountHandleWrapper(rdram, ctx);
        goto after_3;
    // 0x80101D44: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_3:
    // 0x80101D48: lui         $a0, 0x8010
    ctx->r4 = S32(0X8010 << 16);
    // 0x80101D4C: addiu       $a0, $a0, 0x270C
    ctx->r4 = ADD32(ctx->r4, 0X270C);
    // 0x80101D50: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    // 0x80101D54: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80101D58: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    // 0x80101D5C: jal         0x800C7830
    // 0x80101D60: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    addBooleanCountHandleWrapper(rdram, ctx);
        goto after_4;
    // 0x80101D60: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_4:
    // 0x80101D64: lui         $a0, 0x8010
    ctx->r4 = S32(0X8010 << 16);
    // 0x80101D68: addiu       $a0, $a0, 0x272C
    ctx->r4 = ADD32(ctx->r4, 0X272C);
    // 0x80101D6C: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    // 0x80101D70: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80101D74: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    // 0x80101D78: jal         0x800C7830
    // 0x80101D7C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    addBooleanCountHandleWrapper(rdram, ctx);
        goto after_5;
    // 0x80101D7C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_5:
    // 0x80101D80: lui         $a0, 0x8010
    ctx->r4 = S32(0X8010 << 16);
    // 0x80101D84: addiu       $a0, $a0, 0x274C
    ctx->r4 = ADD32(ctx->r4, 0X274C);
    // 0x80101D88: addiu       $a1, $zero, 0x40
    ctx->r5 = ADD32(0, 0X40);
    // 0x80101D8C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80101D90: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    // 0x80101D94: jal         0x800C7830
    // 0x80101D98: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    addBooleanCountHandleWrapper(rdram, ctx);
        goto after_6;
    // 0x80101D98: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_6:
    // 0x80101D9C: lui         $a0, 0x8010
    ctx->r4 = S32(0X8010 << 16);
    // 0x80101DA0: addiu       $a0, $a0, 0x276C
    ctx->r4 = ADD32(ctx->r4, 0X276C);
    // 0x80101DA4: addiu       $a1, $zero, 0x41
    ctx->r5 = ADD32(0, 0X41);
    // 0x80101DA8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80101DAC: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    // 0x80101DB0: jal         0x800C7830
    // 0x80101DB4: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    addBooleanCountHandleWrapper(rdram, ctx);
        goto after_7;
    // 0x80101DB4: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_7:
    // 0x80101DB8: lui         $a0, 0x8010
    ctx->r4 = S32(0X8010 << 16);
    // 0x80101DBC: addiu       $a0, $a0, 0x278C
    ctx->r4 = ADD32(ctx->r4, 0X278C);
    // 0x80101DC0: addiu       $a1, $zero, 0x42
    ctx->r5 = ADD32(0, 0X42);
    // 0x80101DC4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80101DC8: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    // 0x80101DCC: jal         0x800C7830
    // 0x80101DD0: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    addBooleanCountHandleWrapper(rdram, ctx);
        goto after_8;
    // 0x80101DD0: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_8:
    // 0x80101DD4: lui         $a0, 0x8010
    ctx->r4 = S32(0X8010 << 16);
    // 0x80101DD8: addiu       $a0, $a0, 0x27AC
    ctx->r4 = ADD32(ctx->r4, 0X27AC);
    // 0x80101DDC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80101DE0: addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    // 0x80101DE4: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    // 0x80101DE8: jal         0x800C7830
    // 0x80101DEC: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    addBooleanCountHandleWrapper(rdram, ctx);
        goto after_9;
    // 0x80101DEC: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_9:
    // 0x80101DF0: lui         $a0, 0x8010
    ctx->r4 = S32(0X8010 << 16);
    // 0x80101DF4: addiu       $a0, $a0, 0x27F0
    ctx->r4 = ADD32(ctx->r4, 0X27F0);
    // 0x80101DF8: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80101DFC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80101E00: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    // 0x80101E04: jal         0x800C7830
    // 0x80101E08: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    addBooleanCountHandleWrapper(rdram, ctx);
        goto after_10;
    // 0x80101E08: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_10:
    // 0x80101E0C: lui         $a0, 0x8010
    ctx->r4 = S32(0X8010 << 16);
    // 0x80101E10: addiu       $a0, $a0, 0x2834
    ctx->r4 = ADD32(ctx->r4, 0X2834);
    // 0x80101E14: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x80101E18: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80101E1C: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    // 0x80101E20: jal         0x800C7830
    // 0x80101E24: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    addBooleanCountHandleWrapper(rdram, ctx);
        goto after_11;
    // 0x80101E24: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_11:
    // 0x80101E28: lui         $a0, 0x8010
    ctx->r4 = S32(0X8010 << 16);
    // 0x80101E2C: addiu       $a0, $a0, 0x2878
    ctx->r4 = ADD32(ctx->r4, 0X2878);
    // 0x80101E30: addiu       $a1, $zero, 0x3D
    ctx->r5 = ADD32(0, 0X3D);
    // 0x80101E34: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80101E38: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    // 0x80101E3C: jal         0x800C7830
    // 0x80101E40: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    addBooleanCountHandleWrapper(rdram, ctx);
        goto after_12;
    // 0x80101E40: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_12:
    // 0x80101E44: lui         $a0, 0x8010
    ctx->r4 = S32(0X8010 << 16);
    // 0x80101E48: addiu       $a0, $a0, 0x28B0
    ctx->r4 = ADD32(ctx->r4, 0X28B0);
    // 0x80101E4C: addiu       $a1, $zero, 0x3E
    ctx->r5 = ADD32(0, 0X3E);
    // 0x80101E50: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80101E54: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    // 0x80101E58: jal         0x800C7830
    // 0x80101E5C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    addBooleanCountHandleWrapper(rdram, ctx);
        goto after_13;
    // 0x80101E5C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_13:
    // 0x80101E60: lui         $a0, 0x8010
    ctx->r4 = S32(0X8010 << 16);
    // 0x80101E64: addiu       $a0, $a0, 0x28F4
    ctx->r4 = ADD32(ctx->r4, 0X28F4);
    // 0x80101E68: addiu       $a1, $zero, 0x3F
    ctx->r5 = ADD32(0, 0X3F);
    // 0x80101E6C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80101E70: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    // 0x80101E74: jal         0x800C7830
    // 0x80101E78: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    addBooleanCountHandleWrapper(rdram, ctx);
        goto after_14;
    // 0x80101E78: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_14:
    // 0x80101E7C: lui         $a0, 0x8010
    ctx->r4 = S32(0X8010 << 16);
    // 0x80101E80: addiu       $a0, $a0, 0x2938
    ctx->r4 = ADD32(ctx->r4, 0X2938);
    // 0x80101E84: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x80101E88: addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    // 0x80101E8C: addiu       $a3, $zero, 0xB
    ctx->r7 = ADD32(0, 0XB);
    // 0x80101E90: addiu       $s0, $zero, 0x4
    ctx->r16 = ADD32(0, 0X4);
    // 0x80101E94: jal         0x800C7830
    // 0x80101E98: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    addBooleanCountHandleWrapper(rdram, ctx);
        goto after_15;
    // 0x80101E98: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    after_15:
    // 0x80101E9C: lui         $a0, 0x8010
    ctx->r4 = S32(0X8010 << 16);
    // 0x80101EA0: addiu       $a0, $a0, 0x299C
    ctx->r4 = ADD32(ctx->r4, 0X299C);
    // 0x80101EA4: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x80101EA8: addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    // 0x80101EAC: addiu       $a3, $zero, 0xC
    ctx->r7 = ADD32(0, 0XC);
    // 0x80101EB0: jal         0x800C7830
    // 0x80101EB4: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    addBooleanCountHandleWrapper(rdram, ctx);
        goto after_16;
    // 0x80101EB4: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    after_16:
    // 0x80101EB8: lui         $a0, 0x8010
    ctx->r4 = S32(0X8010 << 16);
    // 0x80101EBC: addiu       $a0, $a0, 0x2A00
    ctx->r4 = ADD32(ctx->r4, 0X2A00);
    // 0x80101EC0: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x80101EC4: addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    // 0x80101EC8: addiu       $a3, $zero, 0xD
    ctx->r7 = ADD32(0, 0XD);
    // 0x80101ECC: jal         0x800C7830
    // 0x80101ED0: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    addBooleanCountHandleWrapper(rdram, ctx);
        goto after_17;
    // 0x80101ED0: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    after_17:
    // 0x80101ED4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80101ED8: jal         0x800C7660
    // 0x80101EDC: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    setObjectiveHiddenFlag(rdram, ctx);
        goto after_18;
    // 0x80101EDC: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_18:
    // 0x80101EE0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80101EE4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80101EE8: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // 0x80101EEC: jr          $ra
    // 0x80101EF0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80101EF0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
