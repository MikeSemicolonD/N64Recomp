#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void func_800C6340(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C6340: lui         $a2, 0x8011
    ctx->r6 = S32(0X8011 << 16);
    // 0x800C6344: lh          $v1, -0x3F80($a2)
    ctx->r3 = MEM_H(ctx->r6, -0X3F80);
    // 0x800C6348: lhu         $a1, -0x3F80($a2)
    ctx->r5 = MEM_HU(ctx->r6, -0X3F80);
    // 0x800C634C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800C6350: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x800C6354: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x800C6358: slti        $v0, $v1, 0x20
    ctx->r2 = SIGNED(ctx->r3) < 0X20 ? 1 : 0;
    // 0x800C635C: beq         $v0, $zero, L_800C63B0
    if (ctx->r2 == 0) {
        // 0x800C6360: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_800C63B0;
    }
    // 0x800C6360: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C6364: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800C6368: addiu       $v0, $v0, -0x4000
    ctx->r2 = ADD32(ctx->r2, -0X4000);
    // 0x800C636C: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x800C6370: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x800C6374: sw          $s0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r16;
    // 0x800C6378: lw          $a0, 0x2C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X2C);
    // 0x800C637C: addiu       $v0, $a1, 0x1
    ctx->r2 = ADD32(ctx->r5, 0X1);
    // 0x800C6380: beq         $a0, $zero, L_800C63B0
    if (ctx->r4 == 0) {
        // 0x800C6384: sh          $v0, -0x3F80($a2)
        MEM_H(-0X3F80, ctx->r6) = ctx->r2;
            goto L_800C63B0;
    }
    // 0x800C6384: sh          $v0, -0x3F80($a2)
    MEM_H(-0X3F80, ctx->r6) = ctx->r2;
    // 0x800C6388: addu        $a0, $a0, $s0
    ctx->r4 = ADD32(ctx->r4, ctx->r16);
    // 0x800C638C: lbu         $v1, 0x0($a0)
    ctx->r3 = MEM_BU(ctx->r4, 0X0);
    // 0x800C6390: addiu       $v0, $zero, 0x2D
    ctx->r2 = ADD32(0, 0X2D);
    // 0x800C6394: beql        $v1, $v0, L_800C63B0
    if (ctx->r3 == ctx->r2) {
        // 0x800C6398: sw          $zero, 0x2C($s0)
        MEM_W(0X2C, ctx->r16) = 0;
            goto L_800C63B0;
    }
    goto skip_0;
    // 0x800C6398: sw          $zero, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = 0;
    skip_0:
    // 0x800C639C: jal         0x80047B48
    // 0x800C63A0: nop

    getLevelDatItemByName(rdram, ctx);
        goto after_0;
    // 0x800C63A0: nop

    after_0:
    // 0x800C63A4: beql        $v0, $zero, L_800C63B0
    if (ctx->r2 == 0) {
        // 0x800C63A8: sw          $zero, 0x2C($s0)
        MEM_W(0X2C, ctx->r16) = 0;
            goto L_800C63B0;
    }
    goto skip_1;
    // 0x800C63A8: sw          $zero, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = 0;
    skip_1:
    // 0x800C63AC: sw          $v0, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->r2;
L_800C63B0:
    // 0x800C63B0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800C63B4: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x800C63B8: jr          $ra
    // 0x800C63BC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x800C63BC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void getAvailablePlayerCraftFlagsIgnoreUnlocks(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C63C0: lui         $v1, 0x800A
    ctx->r3 = S32(0X800A << 16);
    // 0x800C63C4: addiu       $v1, $v1, -0x13B0
    ctx->r3 = ADD32(ctx->r3, -0X13B0);
    // 0x800C63C8: sll         $v0, $a0, 2
    ctx->r2 = S32(ctx->r4 << 2);
    // 0x800C63CC: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800C63D0: lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X0);
    // 0x800C63D4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800C63D8: sllv        $a1, $v0, $v1
    ctx->r5 = S32(ctx->r2 << (ctx->r3 & 31));
    // 0x800C63DC: andi        $v0, $a1, 0xD
    ctx->r2 = ctx->r5 & 0XD;
    // 0x800C63E0: bnel        $v0, $zero, L_800C63E8
    if (ctx->r2 != 0) {
        // 0x800C63E4: ori         $a1, $a1, 0xD
        ctx->r5 = ctx->r5 | 0XD;
            goto L_800C63E8;
    }
    goto skip_0;
    // 0x800C63E4: ori         $a1, $a1, 0xD
    ctx->r5 = ctx->r5 | 0XD;
    skip_0:
L_800C63E8:
    // 0x800C63E8: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800C63EC: addiu       $a2, $v0, 0xB40
    ctx->r6 = ADD32(ctx->r2, 0XB40);
    // 0x800C63F0: lw          $v1, 0xC($a2)
    ctx->r3 = MEM_W(ctx->r6, 0XC);
    // 0x800C63F4: lui         $v0, 0x8
    ctx->r2 = S32(0X8 << 16);
    // 0x800C63F8: and         $v0, $v1, $v0
    ctx->r2 = ctx->r3 & ctx->r2;
    // 0x800C63FC: bnel        $v0, $zero, L_800C6404
    if (ctx->r2 != 0) {
        // 0x800C6400: ori         $a1, $a1, 0x7F
        ctx->r5 = ctx->r5 | 0X7F;
            goto L_800C6404;
    }
    goto skip_1;
    // 0x800C6400: ori         $a1, $a1, 0x7F
    ctx->r5 = ctx->r5 | 0X7F;
    skip_1:
L_800C6404:
    // 0x800C6404: lw          $v0, 0x18($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X18);
    // 0x800C6408: andi        $v0, $v0, 0x4
    ctx->r2 = ctx->r2 & 0X4;
    // 0x800C640C: bnel        $v0, $zero, L_800C6428
    if (ctx->r2 != 0) {
        // 0x800C6410: ori         $a1, $a1, 0x20
        ctx->r5 = ctx->r5 | 0X20;
            goto L_800C6428;
    }
    goto skip_2;
    // 0x800C6410: ori         $a1, $a1, 0x20
    ctx->r5 = ctx->r5 | 0X20;
    skip_2:
    // 0x800C6414: lui         $v0, 0x2
    ctx->r2 = S32(0X2 << 16);
    // 0x800C6418: and         $v0, $v1, $v0
    ctx->r2 = ctx->r3 & ctx->r2;
    // 0x800C641C: beq         $v0, $zero, L_800C642C
    if (ctx->r2 == 0) {
        // 0x800C6420: lui         $v0, 0x8013
        ctx->r2 = S32(0X8013 << 16);
            goto L_800C642C;
    }
    // 0x800C6420: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800C6424: ori         $a1, $a1, 0x20
    ctx->r5 = ctx->r5 | 0X20;
L_800C6428:
    // 0x800C6428: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
L_800C642C:
    // 0x800C642C: addiu       $v1, $v0, 0xB40
    ctx->r3 = ADD32(ctx->r2, 0XB40);
    // 0x800C6430: lw          $v0, 0x18($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X18);
    // 0x800C6434: andi        $v0, $v0, 0x8
    ctx->r2 = ctx->r2 & 0X8;
    // 0x800C6438: bnel        $v0, $zero, L_800C6458
    if (ctx->r2 != 0) {
        // 0x800C643C: ori         $a1, $a1, 0x40
        ctx->r5 = ctx->r5 | 0X40;
            goto L_800C6458;
    }
    goto skip_3;
    // 0x800C643C: ori         $a1, $a1, 0x40
    ctx->r5 = ctx->r5 | 0X40;
    skip_3:
    // 0x800C6440: lw          $v0, 0xC($v1)
    ctx->r2 = MEM_W(ctx->r3, 0XC);
    // 0x800C6444: lui         $v1, 0x4
    ctx->r3 = S32(0X4 << 16);
    // 0x800C6448: and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // 0x800C644C: beq         $v0, $zero, L_800C645C
    if (ctx->r2 == 0) {
        // 0x800C6450: addiu       $v0, $zero, 0xA
        ctx->r2 = ADD32(0, 0XA);
            goto L_800C645C;
    }
    // 0x800C6450: addiu       $v0, $zero, 0xA
    ctx->r2 = ADD32(0, 0XA);
    // 0x800C6454: ori         $a1, $a1, 0x40
    ctx->r5 = ctx->r5 | 0X40;
L_800C6458:
    // 0x800C6458: addiu       $v0, $zero, 0xA
    ctx->r2 = ADD32(0, 0XA);
L_800C645C:
    // 0x800C645C: bne         $a0, $v0, L_800C6478
    if (ctx->r4 != ctx->r2) {
        // 0x800C6460: addiu       $v0, $zero, 0x11
        ctx->r2 = ADD32(0, 0X11);
            goto L_800C6478;
    }
    // 0x800C6460: addiu       $v0, $zero, 0x11
    ctx->r2 = ADD32(0, 0X11);
    // 0x800C6464: addiu       $v0, $zero, -0x9
    ctx->r2 = ADD32(0, -0X9);
    // 0x800C6468: and         $a1, $a1, $v0
    ctx->r5 = ctx->r5 & ctx->r2;
    // 0x800C646C: addiu       $v0, $zero, -0x11
    ctx->r2 = ADD32(0, -0X11);
    // 0x800C6470: and         $a1, $a1, $v0
    ctx->r5 = ctx->r5 & ctx->r2;
    // 0x800C6474: addiu       $v0, $zero, 0x11
    ctx->r2 = ADD32(0, 0X11);
L_800C6478:
    // 0x800C6478: beql        $a0, $v0, L_800C6480
    if (ctx->r4 == ctx->r2) {
        // 0x800C647C: andi        $a1, $a1, 0x1
        ctx->r5 = ctx->r5 & 0X1;
            goto L_800C6480;
    }
    goto skip_4;
    // 0x800C647C: andi        $a1, $a1, 0x1
    ctx->r5 = ctx->r5 & 0X1;
    skip_4:
L_800C6480:
    // 0x800C6480: addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
    // 0x800C6484: beql        $a0, $v0, L_800C648C
    if (ctx->r4 == ctx->r2) {
        // 0x800C6488: andi        $a1, $a1, 0x3
        ctx->r5 = ctx->r5 & 0X3;
            goto L_800C648C;
    }
    goto skip_5;
    // 0x800C6488: andi        $a1, $a1, 0x3
    ctx->r5 = ctx->r5 & 0X3;
    skip_5:
L_800C648C:
    // 0x800C648C: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x800C6490: beq         $a0, $v0, L_800C64B0
    if (ctx->r4 == ctx->r2) {
        // 0x800C6494: addiu       $v0, $zero, 0x6
        ctx->r2 = ADD32(0, 0X6);
            goto L_800C64B0;
    }
    // 0x800C6494: addiu       $v0, $zero, 0x6
    ctx->r2 = ADD32(0, 0X6);
    // 0x800C6498: beq         $a0, $v0, L_800C64B0
    if (ctx->r4 == ctx->r2) {
        // 0x800C649C: addiu       $v0, $zero, 0xB
        ctx->r2 = ADD32(0, 0XB);
            goto L_800C64B0;
    }
    // 0x800C649C: addiu       $v0, $zero, 0xB
    ctx->r2 = ADD32(0, 0XB);
    // 0x800C64A0: beq         $a0, $v0, L_800C64B0
    if (ctx->r4 == ctx->r2) {
        // 0x800C64A4: addiu       $v0, $zero, 0x12
        ctx->r2 = ADD32(0, 0X12);
            goto L_800C64B0;
    }
    // 0x800C64A4: addiu       $v0, $zero, 0x12
    ctx->r2 = ADD32(0, 0X12);
    // 0x800C64A8: bne         $a0, $v0, L_800C64B8
    if (ctx->r4 != ctx->r2) {
        // 0x800C64AC: addiu       $v0, $zero, 0x10
        ctx->r2 = ADD32(0, 0X10);
            goto L_800C64B8;
    }
    // 0x800C64AC: addiu       $v0, $zero, 0x10
    ctx->r2 = ADD32(0, 0X10);
L_800C64B0:
    // 0x800C64B0: andi        $a1, $a1, 0x10
    ctx->r5 = ctx->r5 & 0X10;
    // 0x800C64B4: addiu       $v0, $zero, 0x10
    ctx->r2 = ADD32(0, 0X10);
L_800C64B8:
    // 0x800C64B8: beql        $a0, $v0, L_800C64C0
    if (ctx->r4 == ctx->r2) {
        // 0x800C64BC: andi        $a1, $a1, 0x80
        ctx->r5 = ctx->r5 & 0X80;
            goto L_800C64C0;
    }
    goto skip_6;
    // 0x800C64BC: andi        $a1, $a1, 0x80
    ctx->r5 = ctx->r5 & 0X80;
    skip_6:
L_800C64C0:
    // 0x800C64C0: jr          $ra
    // 0x800C64C4: addu        $v0, $a1, $zero
    ctx->r2 = ADD32(ctx->r5, 0);
    return;
    // 0x800C64C4: addu        $v0, $a1, $zero
    ctx->r2 = ADD32(ctx->r5, 0);
;}
RECOMP_FUNC void getAvailableShipsForLevel(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C63C0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800C63C4: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800C63C8: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x800C63CC: lw          $s1, -0x4020($v0)
    ctx->r17 = MEM_W(ctx->r2, -0X4020);
    // 0x800C63D0: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x800C63D4: sw          $ra, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r31;
    // 0x800C63D8: jal         0x8006C8F0
    // 0x800C63DC: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    func_8006C8F0(rdram, ctx);
        goto after_0;
    // 0x800C63DC: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    after_0:
    // 0x800C63E0: lwc1        $f0, 0x0($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X0);
    // 0x800C63E4: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800C63E8: lwc1        $f2, 0x686C($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X686C);
    // 0x800C63EC: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x800C63F0: trunc.w.s   $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    ctx->f4.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800C63F4: mfc1        $v1, $f4
    ctx->r3 = (int32_t)ctx->f4.u32l;
    // 0x800C63F8: sh          $v1, 0x85C($s1)
    MEM_H(0X85C, ctx->r17) = ctx->r3;
    // 0x800C63FC: lwc1        $f0, 0x8($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X8);
    // 0x800C6400: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x800C6404: addiu       $s0, $zero, -0x10
    ctx->r16 = ADD32(0, -0X10);
    // 0x800C6408: trunc.w.s   $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    ctx->f4.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800C640C: mfc1        $v0, $f4
    ctx->r2 = (int32_t)ctx->f4.u32l;
    // 0x800C6410: sh          $v0, 0x85E($s1)
    MEM_H(0X85E, ctx->r17) = ctx->r2;
L_800C6414:
    // 0x800C6414: lh          $a1, 0x85C($s1)
    ctx->r5 = MEM_H(ctx->r17, 0X85C);
    // 0x800C6418: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x800C641C: jal         0x800C41B0
    // 0x800C6420: addu        $a1, $a1, $s0
    ctx->r5 = ADD32(ctx->r5, ctx->r16);
    func_800C41B0(rdram, ctx);
        goto after_1;
    // 0x800C6420: addu        $a1, $a1, $s0
    ctx->r5 = ADD32(ctx->r5, ctx->r16);
    after_1:
    // 0x800C6424: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x800C6428: slti        $v0, $s0, 0x10
    ctx->r2 = SIGNED(ctx->r16) < 0X10 ? 1 : 0;
    // 0x800C642C: bne         $v0, $zero, L_800C6414
    if (ctx->r2 != 0) {
        // 0x800C6430: addiu       $a2, $s1, 0x824
        ctx->r6 = ADD32(ctx->r17, 0X824);
            goto L_800C6414;
    }
    // 0x800C6430: addiu       $a2, $s1, 0x824
    ctx->r6 = ADD32(ctx->r17, 0X824);
    // 0x800C6434: addiu       $a1, $s1, 0x800
    ctx->r5 = ADD32(ctx->r17, 0X800);
    // 0x800C6438: lhu         $a0, 0x858($s1)
    ctx->r4 = MEM_HU(ctx->r17, 0X858);
    // 0x800C643C: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    // 0x800C6440: jal         0x80022C00
    // 0x800C6444: sh          $zero, 0xDB8($s1)
    MEM_H(0XDB8, ctx->r17) = 0;
    func_80022C00(rdram, ctx);
        goto after_2;
    // 0x800C6444: sh          $zero, 0xDB8($s1)
    MEM_H(0XDB8, ctx->r17) = 0;
    after_2:
    // 0x800C6448: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x800C644C: sh          $v0, 0xDC8($s1)
    MEM_H(0XDC8, ctx->r17) = ctx->r2;
    // 0x800C6450: sw          $zero, 0xDCC($s1)
    MEM_W(0XDCC, ctx->r17) = 0;
    // 0x800C6454: lw          $ra, 0x18($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X18);
    // 0x800C6458: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x800C645C: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x800C6460: jr          $ra
    // 0x800C6464: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x800C6464: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_800C6468(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C6468: lwc1        $f2, 0xDCC($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0XDCC);
    // 0x800C646C: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800C6470: lwc1        $f0, 0x6870($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X6870);
    // 0x800C6474: mtc1        $a1, $f4
    ctx->f4.u32l = ctx->r5;
    // 0x800C6478: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x800C647C: nop

    // 0x800C6480: bc1f        L_800C6490
    if (!c1cs) {
        // 0x800C6484: nop
    
            goto L_800C6490;
    }
    // 0x800C6484: nop

    // 0x800C6488: add.s       $f0, $f2, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f2.fl + ctx->f4.fl;
    // 0x800C648C: swc1        $f0, 0xDCC($a0)
    MEM_W(0XDCC, ctx->r4) = ctx->f0.u32l;
L_800C6490:
    // 0x800C6490: jr          $ra
    // 0x800C6494: nop

    return;
    // 0x800C6494: nop

;}
RECOMP_FUNC void func_800C6498(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C6498: lbu         $v0, 0xDD0($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0XDD0);
    // 0x800C649C: jr          $ra
    // 0x800C64A0: nop

    return;
    // 0x800C64A0: nop

;}
RECOMP_FUNC void fake_func_800C64A4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
;}
RECOMP_FUNC void func_800C64B0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C64B0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800C64B4: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800C64B8: addiu       $v0, $v0, -0x5BE0
    ctx->r2 = ADD32(ctx->r2, -0X5BE0);
    // 0x800C64BC: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    // 0x800C64C0: sll         $a1, $a1, 2
    ctx->r5 = S32(ctx->r5 << 2);
    // 0x800C64C4: addu        $v1, $a1, $v0
    ctx->r3 = ADD32(ctx->r5, ctx->r2);
    // 0x800C64C8: sw          $ra, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r31;
    // 0x800C64CC: sw          $s3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r19;
    // 0x800C64D0: sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // 0x800C64D4: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x800C64D8: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x800C64DC: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x800C64E0: beq         $v0, $zero, L_800C65B0
    if (ctx->r2 == 0) {
        // 0x800C64E4: addu        $s0, $a0, $zero
        ctx->r16 = ADD32(ctx->r4, 0);
            goto L_800C65B0;
    }
    // 0x800C64E4: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x800C64E8: sb          $zero, 0x1E0($s0)
    MEM_B(0X1E0, ctx->r16) = 0;
    // 0x800C64EC: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x800C64F0: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x800C64F4: beq         $v0, $zero, L_800C65B0
    if (ctx->r2 == 0) {
        // 0x800C64F8: addu        $s1, $zero, $zero
        ctx->r17 = ADD32(0, 0);
            goto L_800C65B0;
    }
    // 0x800C64F8: addu        $s1, $zero, $zero
    ctx->r17 = ADD32(0, 0);
    // 0x800C64FC: addu        $s2, $v1, $zero
    ctx->r18 = ADD32(ctx->r3, 0);
    // 0x800C6500: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800C6504: addiu       $s3, $v0, -0x5DFC
    ctx->r19 = ADD32(ctx->r2, -0X5DFC);
    // 0x800C6508: andi        $v0, $s1, 0xFF
    ctx->r2 = ctx->r17 & 0XFF;
    // 0x800C650C: lw          $v1, 0x0($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X0);
L_800C6510:
    // 0x800C6510: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x800C6514: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800C6518: lw          $a0, 0x0($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X0);
    // 0x800C651C: jal         0x800C723C
    // 0x800C6520: nop

    func_800C723C(rdram, ctx);
        goto after_0;
    // 0x800C6520: nop

    after_0:
    // 0x800C6524: addu        $a1, $v0, $zero
    ctx->r5 = ADD32(ctx->r2, 0);
    // 0x800C6528: beq         $a1, $zero, L_800C6590
    if (ctx->r5 == 0) {
        // 0x800C652C: addiu       $a2, $zero, 0x1
        ctx->r6 = ADD32(0, 0X1);
            goto L_800C6590;
    }
    // 0x800C652C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x800C6530: lbu         $v0, 0x1E0($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X1E0);
    // 0x800C6534: sll         $a0, $v0, 3
    ctx->r4 = S32(ctx->r2 << 3);
    // 0x800C6538: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // 0x800C653C: sll         $a0, $a0, 3
    ctx->r4 = S32(ctx->r4 << 3);
    // 0x800C6540: addiu       $a0, $a0, 0x18
    ctx->r4 = ADD32(ctx->r4, 0X18);
    // 0x800C6544: jal         0x800BFEA0
    // 0x800C6548: addu        $a0, $s0, $a0
    ctx->r4 = ADD32(ctx->r16, ctx->r4);
    func_800BFEA0(rdram, ctx);
        goto after_1;
    // 0x800C6548: addu        $a0, $s0, $a0
    ctx->r4 = ADD32(ctx->r16, ctx->r4);
    after_1:
    // 0x800C654C: lbu         $v1, 0x1E0($s0)
    ctx->r3 = MEM_BU(ctx->r16, 0X1E0);
    // 0x800C6550: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    // 0x800C6554: sll         $v0, $v1, 3
    ctx->r2 = S32(ctx->r3 << 3);
    // 0x800C6558: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x800C655C: lbu         $v0, 0x4($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X4);
    // 0x800C6560: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x800C6564: sll         $v0, $v0, 4
    ctx->r2 = S32(ctx->r2 << 4);
    // 0x800C6568: addu        $v0, $v0, $s3
    ctx->r2 = ADD32(ctx->r2, ctx->r19);
    // 0x800C656C: lwc1        $f0, 0x0($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X0);
    // 0x800C6570: addu        $v1, $s0, $v1
    ctx->r3 = ADD32(ctx->r16, ctx->r3);
    // 0x800C6574: swc1        $f0, 0x1C8($v1)
    MEM_W(0X1C8, ctx->r3) = ctx->f0.u32l;
    // 0x800C6578: lbu         $v0, 0x1E0($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X1E0);
    // 0x800C657C: addu        $v0, $s0, $v0
    ctx->r2 = ADD32(ctx->r16, ctx->r2);
    // 0x800C6580: sb          $zero, 0x1E1($v0)
    MEM_B(0X1E1, ctx->r2) = 0;
    // 0x800C6584: lbu         $v0, 0x1E0($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X1E0);
    // 0x800C6588: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800C658C: sb          $v0, 0x1E0($s0)
    MEM_B(0X1E0, ctx->r16) = ctx->r2;
L_800C6590:
    // 0x800C6590: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x800C6594: andi        $v0, $s1, 0xFF
    ctx->r2 = ctx->r17 & 0XFF;
    // 0x800C6598: lw          $v1, 0x0($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X0);
    // 0x800C659C: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x800C65A0: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800C65A4: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x800C65A8: bne         $v0, $zero, L_800C6510
    if (ctx->r2 != 0) {
        // 0x800C65AC: andi        $v0, $s1, 0xFF
        ctx->r2 = ctx->r17 & 0XFF;
            goto L_800C6510;
    }
    // 0x800C65AC: andi        $v0, $s1, 0xFF
    ctx->r2 = ctx->r17 & 0XFF;
L_800C65B0:
    // 0x800C65B0: lw          $ra, 0x20($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X20);
    // 0x800C65B4: lw          $s3, 0x1C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X1C);
    // 0x800C65B8: lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X18);
    // 0x800C65BC: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x800C65C0: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x800C65C4: jr          $ra
    // 0x800C65C8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x800C65C8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void unlockLevelsAndCraftsBasedOnMedalsEarned(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C64C8: addu        $t1, $zero, $zero
    ctx->r9 = ADD32(0, 0);
    // 0x800C64CC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x800C64D0: addu        $a3, $a2, $zero
    ctx->r7 = ADD32(ctx->r6, 0);
    // 0x800C64D4: addu        $t0, $a2, $zero
    ctx->r8 = ADD32(ctx->r6, 0);
    // 0x800C64D8: addu        $a1, $t1, $zero
    ctx->r5 = ADD32(ctx->r9, 0);
    // 0x800C64DC: andi        $v0, $a1, 0xFF
    ctx->r2 = ctx->r5 & 0XFF;
L_800C64E0:
    // 0x800C64E0: addu        $v0, $a0, $v0
    ctx->r2 = ADD32(ctx->r4, ctx->r2);
    // 0x800C64E4: lbu         $v1, 0x0($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X0);
    // 0x800C64E8: sltiu       $v0, $v1, 0x3
    ctx->r2 = ctx->r3 < 0X3 ? 1 : 0;
    // 0x800C64EC: bnel        $v0, $zero, L_800C64F4
    if (ctx->r2 != 0) {
        // 0x800C64F0: addu        $t0, $zero, $zero
        ctx->r8 = ADD32(0, 0);
            goto L_800C64F4;
    }
    goto skip_0;
    // 0x800C64F0: addu        $t0, $zero, $zero
    ctx->r8 = ADD32(0, 0);
    skip_0:
L_800C64F4:
    // 0x800C64F4: sltiu       $v0, $v1, 0x2
    ctx->r2 = ctx->r3 < 0X2 ? 1 : 0;
    // 0x800C64F8: bnel        $v0, $zero, L_800C6500
    if (ctx->r2 != 0) {
        // 0x800C64FC: addu        $a3, $zero, $zero
        ctx->r7 = ADD32(0, 0);
            goto L_800C6500;
    }
    goto skip_1;
    // 0x800C64FC: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    skip_1:
L_800C6500:
    // 0x800C6500: beql        $v1, $zero, L_800C6508
    if (ctx->r3 == 0) {
        // 0x800C6504: addu        $a2, $zero, $zero
        ctx->r6 = ADD32(0, 0);
            goto L_800C6508;
    }
    goto skip_2;
    // 0x800C6504: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    skip_2:
L_800C6508:
    // 0x800C6508: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x800C650C: andi        $v0, $a1, 0xFF
    ctx->r2 = ctx->r5 & 0XFF;
    // 0x800C6510: sltiu       $v0, $v0, 0x10
    ctx->r2 = ctx->r2 < 0X10 ? 1 : 0;
    // 0x800C6514: bne         $v0, $zero, L_800C64E0
    if (ctx->r2 != 0) {
        // 0x800C6518: andi        $v0, $a1, 0xFF
        ctx->r2 = ctx->r5 & 0XFF;
            goto L_800C64E0;
    }
    // 0x800C6518: andi        $v0, $a1, 0xFF
    ctx->r2 = ctx->r5 & 0XFF;
    // 0x800C651C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800C6520: bne         $a2, $v0, L_800C654C
    if (ctx->r6 != ctx->r2) {
        // 0x800C6524: lui         $a1, 0x10
        ctx->r5 = S32(0X10 << 16);
            goto L_800C654C;
    }
    // 0x800C6524: lui         $a1, 0x10
    ctx->r5 = S32(0X10 << 16);
    // 0x800C6528: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800C652C: addiu       $a2, $v0, 0xB40
    ctx->r6 = ADD32(ctx->r2, 0XB40);
    // 0x800C6530: lw          $v1, 0xC($a2)
    ctx->r3 = MEM_W(ctx->r6, 0XC);
    // 0x800C6534: and         $v0, $v1, $a1
    ctx->r2 = ctx->r3 & ctx->r5;
    // 0x800C6538: beql        $v0, $zero, L_800C6540
    if (ctx->r2 == 0) {
        // 0x800C653C: addiu       $t1, $zero, 0x1
        ctx->r9 = ADD32(0, 0X1);
            goto L_800C6540;
    }
    goto skip_3;
    // 0x800C653C: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    skip_3:
L_800C6540:
    // 0x800C6540: or          $v0, $v1, $a1
    ctx->r2 = ctx->r3 | ctx->r5;
    // 0x800C6544: sw          $v0, 0xC($a2)
    MEM_W(0XC, ctx->r6) = ctx->r2;
    // 0x800C6548: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800C654C:
    // 0x800C654C: bne         $a3, $v0, L_800C657C
    if (ctx->r7 != ctx->r2) {
        // 0x800C6550: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_800C657C;
    }
    // 0x800C6550: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800C6554: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800C6558: addiu       $a2, $v0, 0xB40
    ctx->r6 = ADD32(ctx->r2, 0XB40);
    // 0x800C655C: lw          $v1, 0xC($a2)
    ctx->r3 = MEM_W(ctx->r6, 0XC);
    // 0x800C6560: lui         $a1, 0x20
    ctx->r5 = S32(0X20 << 16);
    // 0x800C6564: and         $v0, $v1, $a1
    ctx->r2 = ctx->r3 & ctx->r5;
    // 0x800C6568: beql        $v0, $zero, L_800C6570
    if (ctx->r2 == 0) {
        // 0x800C656C: addiu       $t1, $zero, 0x1
        ctx->r9 = ADD32(0, 0X1);
            goto L_800C6570;
    }
    goto skip_4;
    // 0x800C656C: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    skip_4:
L_800C6570:
    // 0x800C6570: or          $v0, $v1, $a1
    ctx->r2 = ctx->r3 | ctx->r5;
    // 0x800C6574: sw          $v0, 0xC($a2)
    MEM_W(0XC, ctx->r6) = ctx->r2;
    // 0x800C6578: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800C657C:
    // 0x800C657C: bne         $t0, $v0, L_800C65AC
    if (ctx->r8 != ctx->r2) {
        // 0x800C6580: lui         $v0, 0x8013
        ctx->r2 = S32(0X8013 << 16);
            goto L_800C65AC;
    }
    // 0x800C6580: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800C6584: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800C6588: addiu       $a2, $v0, 0xB40
    ctx->r6 = ADD32(ctx->r2, 0XB40);
    // 0x800C658C: lw          $v1, 0xC($a2)
    ctx->r3 = MEM_W(ctx->r6, 0XC);
    // 0x800C6590: lui         $a1, 0x40
    ctx->r5 = S32(0X40 << 16);
    // 0x800C6594: and         $v0, $v1, $a1
    ctx->r2 = ctx->r3 & ctx->r5;
    // 0x800C6598: beql        $v0, $zero, L_800C65A0
    if (ctx->r2 == 0) {
        // 0x800C659C: addiu       $t1, $zero, 0x1
        ctx->r9 = ADD32(0, 0X1);
            goto L_800C65A0;
    }
    goto skip_5;
    // 0x800C659C: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    skip_5:
L_800C65A0:
    // 0x800C65A0: or          $v0, $v1, $a1
    ctx->r2 = ctx->r3 | ctx->r5;
    // 0x800C65A4: sw          $v0, 0xC($a2)
    MEM_W(0XC, ctx->r6) = ctx->r2;
    // 0x800C65A8: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
L_800C65AC:
    // 0x800C65AC: sb          $t1, 0xB35($v0)
    MEM_B(0XB35, ctx->r2) = ctx->r9;
    // 0x800C65B0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x800C65B4: addu        $a3, $a2, $zero
    ctx->r7 = ADD32(ctx->r6, 0);
    // 0x800C65B8: addu        $t0, $a2, $zero
    ctx->r8 = ADD32(ctx->r6, 0);
    // 0x800C65BC: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    // 0x800C65C0: andi        $v0, $a1, 0xFF
    ctx->r2 = ctx->r5 & 0XFF;
L_800C65C4:
    // 0x800C65C4: addu        $v0, $a0, $v0
    ctx->r2 = ADD32(ctx->r4, ctx->r2);
    // 0x800C65C8: lbu         $v1, 0x0($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X0);
    // 0x800C65CC: sltiu       $v0, $v1, 0x3
    ctx->r2 = ctx->r3 < 0X3 ? 1 : 0;
    // 0x800C65D0: bnel        $v0, $zero, L_800C65D8
    if (ctx->r2 != 0) {
        // 0x800C65D4: addu        $t0, $zero, $zero
        ctx->r8 = ADD32(0, 0);
            goto L_800C65D8;
    }
    goto skip_6;
    // 0x800C65D4: addu        $t0, $zero, $zero
    ctx->r8 = ADD32(0, 0);
    skip_6:
L_800C65D8:
    // 0x800C65D8: sltiu       $v0, $v1, 0x2
    ctx->r2 = ctx->r3 < 0X2 ? 1 : 0;
    // 0x800C65DC: bnel        $v0, $zero, L_800C65E4
    if (ctx->r2 != 0) {
        // 0x800C65E0: addu        $a3, $zero, $zero
        ctx->r7 = ADD32(0, 0);
            goto L_800C65E4;
    }
    goto skip_7;
    // 0x800C65E0: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    skip_7:
L_800C65E4:
    // 0x800C65E4: beql        $v1, $zero, L_800C65EC
    if (ctx->r3 == 0) {
        // 0x800C65E8: addu        $a2, $zero, $zero
        ctx->r6 = ADD32(0, 0);
            goto L_800C65EC;
    }
    goto skip_8;
    // 0x800C65E8: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    skip_8:
L_800C65EC:
    // 0x800C65EC: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x800C65F0: andi        $v0, $a1, 0xFF
    ctx->r2 = ctx->r5 & 0XFF;
    // 0x800C65F4: sltiu       $v0, $v0, 0x13
    ctx->r2 = ctx->r2 < 0X13 ? 1 : 0;
    // 0x800C65F8: bne         $v0, $zero, L_800C65C4
    if (ctx->r2 != 0) {
        // 0x800C65FC: andi        $v0, $a1, 0xFF
        ctx->r2 = ctx->r5 & 0XFF;
            goto L_800C65C4;
    }
    // 0x800C65FC: andi        $v0, $a1, 0xFF
    ctx->r2 = ctx->r5 & 0XFF;
    // 0x800C6600: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x800C6604: bne         $a2, $a1, L_800C6620
    if (ctx->r6 != ctx->r5) {
        // 0x800C6608: lui         $v0, 0x8013
        ctx->r2 = S32(0X8013 << 16);
            goto L_800C6620;
    }
    // 0x800C6608: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800C660C: addiu       $v0, $v0, 0xB40
    ctx->r2 = ADD32(ctx->r2, 0XB40);
    // 0x800C6610: lw          $v1, 0xC($v0)
    ctx->r3 = MEM_W(ctx->r2, 0XC);
    // 0x800C6614: lui         $a0, 0x2
    ctx->r4 = S32(0X2 << 16);
    // 0x800C6618: or          $v1, $v1, $a0
    ctx->r3 = ctx->r3 | ctx->r4;
    // 0x800C661C: sw          $v1, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r3;
L_800C6620:
    // 0x800C6620: bne         $a3, $a1, L_800C663C
    if (ctx->r7 != ctx->r5) {
        // 0x800C6624: lui         $v0, 0x8013
        ctx->r2 = S32(0X8013 << 16);
            goto L_800C663C;
    }
    // 0x800C6624: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800C6628: addiu       $v0, $v0, 0xB40
    ctx->r2 = ADD32(ctx->r2, 0XB40);
    // 0x800C662C: lw          $v1, 0xC($v0)
    ctx->r3 = MEM_W(ctx->r2, 0XC);
    // 0x800C6630: lui         $a0, 0x4
    ctx->r4 = S32(0X4 << 16);
    // 0x800C6634: or          $v1, $v1, $a0
    ctx->r3 = ctx->r3 | ctx->r4;
    // 0x800C6638: sw          $v1, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r3;
L_800C663C:
    // 0x800C663C: bne         $t0, $a1, L_800C6658
    if (ctx->r8 != ctx->r5) {
        // 0x800C6640: lui         $v0, 0x8013
        ctx->r2 = S32(0X8013 << 16);
            goto L_800C6658;
    }
    // 0x800C6640: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800C6644: addiu       $v0, $v0, 0xB40
    ctx->r2 = ADD32(ctx->r2, 0XB40);
    // 0x800C6648: lw          $v1, 0xC($v0)
    ctx->r3 = MEM_W(ctx->r2, 0XC);
    // 0x800C664C: lui         $a0, 0x8
    ctx->r4 = S32(0X8 << 16);
    // 0x800C6650: or          $v1, $v1, $a0
    ctx->r3 = ctx->r3 | ctx->r4;
    // 0x800C6654: sw          $v1, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r3;
L_800C6658:
    // 0x800C6658: jr          $ra
    // 0x800C665C: nop

    return;
    // 0x800C665C: nop

;}
RECOMP_FUNC void func_800C65CC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C65CC: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x800C65D0: sw          $s3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r19;
    // 0x800C65D4: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800C65D8: addiu       $v0, $v0, -0x5BE0
    ctx->r2 = ADD32(ctx->r2, -0X5BE0);
    // 0x800C65DC: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    // 0x800C65E0: sll         $a1, $a1, 2
    ctx->r5 = S32(ctx->r5 << 2);
    // 0x800C65E4: addu        $v1, $a1, $v0
    ctx->r3 = ADD32(ctx->r5, ctx->r2);
    // 0x800C65E8: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x800C65EC: sw          $s6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r22;
    // 0x800C65F0: sw          $s5, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r21;
    // 0x800C65F4: sw          $s4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r20;
    // 0x800C65F8: sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // 0x800C65FC: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x800C6600: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x800C6604: sdc1        $f22, 0x38($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X38, ctx->r29);
    // 0x800C6608: sdc1        $f20, 0x30($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X30, ctx->r29);
    // 0x800C660C: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x800C6610: mtc1        $a2, $f22
    ctx->f22.u32l = ctx->r6;
    // 0x800C6614: beq         $v0, $zero, L_800C6870
    if (ctx->r2 == 0) {
        // 0x800C6618: addu        $s3, $a0, $zero
        ctx->r19 = ADD32(ctx->r4, 0);
            goto L_800C6870;
    }
    // 0x800C6618: addu        $s3, $a0, $zero
    ctx->r19 = ADD32(ctx->r4, 0);
    // 0x800C661C: lbu         $v0, 0x1E0($s3)
    ctx->r2 = MEM_BU(ctx->r19, 0X1E0);
    // 0x800C6620: beq         $v0, $zero, L_800C6870
    if (ctx->r2 == 0) {
        // 0x800C6624: addu        $s0, $zero, $zero
        ctx->r16 = ADD32(0, 0);
            goto L_800C6870;
    }
    // 0x800C6624: addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
    // 0x800C6628: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800C662C: addiu       $s6, $v0, -0x5DFC
    ctx->r22 = ADD32(ctx->r2, -0X5DFC);
    // 0x800C6630: addu        $s4, $v1, $zero
    ctx->r20 = ADD32(ctx->r3, 0);
    // 0x800C6634: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800C6638: lwc1        $f20, 0x690C($at)
    ctx->f20.u32l = MEM_W(ctx->r1, 0X690C);
    // 0x800C663C: lui         $s5, 0x8000
    ctx->r21 = S32(0X8000 << 16);
    // 0x800C6640: andi        $a1, $s0, 0xFF
    ctx->r5 = ctx->r16 & 0XFF;
L_800C6644:
    // 0x800C6644: sll         $v0, $a1, 2
    ctx->r2 = S32(ctx->r5 << 2);
    // 0x800C6648: addu        $a2, $s3, $v0
    ctx->r6 = ADD32(ctx->r19, ctx->r2);
    // 0x800C664C: lwc1        $f2, 0x1C8($a2)
    ctx->f2.u32l = MEM_W(ctx->r6, 0X1C8);
    // 0x800C6650: sub.s       $f2, $f2, $f22
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f2.fl = ctx->f2.fl - ctx->f22.fl;
    // 0x800C6654: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800C6658: c.le.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl <= ctx->f0.fl;
    // 0x800C665C: nop

    // 0x800C6660: bc1f        L_800C66A8
    if (!c1cs) {
        // 0x800C6664: swc1        $f2, 0x1C8($a2)
        MEM_W(0X1C8, ctx->r6) = ctx->f2.u32l;
            goto L_800C66A8;
    }
    // 0x800C6664: swc1        $f2, 0x1C8($a2)
    MEM_W(0X1C8, ctx->r6) = ctx->f2.u32l;
    // 0x800C6668: addu        $a0, $s3, $a1
    ctx->r4 = ADD32(ctx->r19, ctx->r5);
    // 0x800C666C: lbu         $v0, 0x1E1($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X1E1);
    // 0x800C6670: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800C6674: andi        $v0, $v0, 0x3
    ctx->r2 = ctx->r2 & 0X3;
    // 0x800C6678: sb          $v0, 0x1E1($a0)
    MEM_B(0X1E1, ctx->r4) = ctx->r2;
    // 0x800C667C: lw          $v0, 0x0($s4)
    ctx->r2 = MEM_W(ctx->r20, 0X0);
    // 0x800C6680: sll         $v1, $a1, 3
    ctx->r3 = S32(ctx->r5 << 3);
    // 0x800C6684: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x800C6688: lbu         $v0, 0x1E1($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X1E1);
    // 0x800C668C: lbu         $v1, 0x4($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X4);
    // 0x800C6690: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800C6694: sll         $v1, $v1, 4
    ctx->r3 = S32(ctx->r3 << 4);
    // 0x800C6698: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800C669C: addu        $v0, $v0, $s6
    ctx->r2 = ADD32(ctx->r2, ctx->r22);
    // 0x800C66A0: lwc1        $f0, 0x0($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X0);
    // 0x800C66A4: swc1        $f0, 0x1C8($a2)
    MEM_W(0X1C8, ctx->r6) = ctx->f0.u32l;
L_800C66A8:
    // 0x800C66A8: addu        $a0, $s3, $a1
    ctx->r4 = ADD32(ctx->r19, ctx->r5);
    // 0x800C66AC: sll         $v0, $a1, 3
    ctx->r2 = S32(ctx->r5 << 3);
    // 0x800C66B0: lw          $v1, 0x0($s4)
    ctx->r3 = MEM_W(ctx->r20, 0X0);
    // 0x800C66B4: lbu         $a0, 0x1E1($a0)
    ctx->r4 = MEM_BU(ctx->r4, 0X1E1);
    // 0x800C66B8: lwc1        $f2, 0x1C8($a2)
    ctx->f2.u32l = MEM_W(ctx->r6, 0X1C8);
    // 0x800C66BC: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800C66C0: lbu         $v0, 0x4($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X4);
    // 0x800C66C4: sll         $v1, $a0, 2
    ctx->r3 = S32(ctx->r4 << 2);
    // 0x800C66C8: sll         $v0, $v0, 4
    ctx->r2 = S32(ctx->r2 << 4);
    // 0x800C66CC: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x800C66D0: addu        $v1, $v1, $s6
    ctx->r3 = ADD32(ctx->r3, ctx->r22);
    // 0x800C66D4: lwc1        $f0, 0x0($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X0);
    // 0x800C66D8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800C66DC: beq         $a0, $v0, L_800C6720
    if (ctx->r4 == ctx->r2) {
        // 0x800C66E0: div.s       $f2, $f2, $f0
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = DIV_S(ctx->f2.fl, ctx->f0.fl);
            goto L_800C6720;
    }
    // 0x800C66E0: div.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = DIV_S(ctx->f2.fl, ctx->f0.fl);
    // 0x800C66E4: slti        $v0, $a0, 0x2
    ctx->r2 = SIGNED(ctx->r4) < 0X2 ? 1 : 0;
    // 0x800C66E8: beq         $v0, $zero, L_800C6700
    if (ctx->r2 == 0) {
        // 0x800C66EC: addiu       $v0, $zero, 0x2
        ctx->r2 = ADD32(0, 0X2);
            goto L_800C6700;
    }
    // 0x800C66EC: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x800C66F0: beq         $a0, $zero, L_800C6718
    if (ctx->r4 == 0) {
        // 0x800C66F4: andi        $v0, $s0, 0xFF
        ctx->r2 = ctx->r16 & 0XFF;
            goto L_800C6718;
    }
    // 0x800C66F4: andi        $v0, $s0, 0xFF
    ctx->r2 = ctx->r16 & 0XFF;
    // 0x800C66F8: j           L_800C6798
    // 0x800C66FC: nop

        goto L_800C6798;
    // 0x800C66FC: nop

L_800C6700:
    // 0x800C6700: beq         $a0, $v0, L_800C6750
    if (ctx->r4 == ctx->r2) {
        // 0x800C6704: addiu       $v0, $zero, 0x3
        ctx->r2 = ADD32(0, 0X3);
            goto L_800C6750;
    }
    // 0x800C6704: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x800C6708: beq         $a0, $v0, L_800C6758
    if (ctx->r4 == ctx->r2) {
        // 0x800C670C: andi        $v0, $s0, 0xFF
        ctx->r2 = ctx->r16 & 0XFF;
            goto L_800C6758;
    }
    // 0x800C670C: andi        $v0, $s0, 0xFF
    ctx->r2 = ctx->r16 & 0XFF;
    // 0x800C6710: j           L_800C6798
    // 0x800C6714: nop

        goto L_800C6798;
    // 0x800C6714: nop

L_800C6718:
    // 0x800C6718: j           L_800C6794
    // 0x800C671C: addu        $s2, $zero, $zero
    ctx->r18 = ADD32(0, 0);
        goto L_800C6794;
    // 0x800C671C: addu        $s2, $zero, $zero
    ctx->r18 = ADD32(0, 0);
L_800C6720:
    // 0x800C6720: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800C6724: lwc1        $f0, 0x6910($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X6910);
    // 0x800C6728: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x800C672C: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800C6730: lwc1        $f2, 0x6914($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X6914);
    // 0x800C6734: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x800C6738: c.le.s      $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f20.fl <= ctx->f0.fl;
    // 0x800C673C: nop

    // 0x800C6740: bc1f        L_800C6774
    if (!c1cs) {
        // 0x800C6744: nop
    
            goto L_800C6774;
    }
    // 0x800C6744: nop

    // 0x800C6748: j           L_800C6784
    // 0x800C674C: sub.s       $f0, $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f20.fl;
        goto L_800C6784;
    // 0x800C674C: sub.s       $f0, $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f20.fl;
L_800C6750:
    // 0x800C6750: j           L_800C6794
    // 0x800C6754: addiu       $s2, $zero, 0xFF
    ctx->r18 = ADD32(0, 0XFF);
        goto L_800C6794;
    // 0x800C6754: addiu       $s2, $zero, 0xFF
    ctx->r18 = ADD32(0, 0XFF);
L_800C6758:
    // 0x800C6758: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800C675C: lwc1        $f0, 0x6918($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X6918);
    // 0x800C6760: mul.s       $f0, $f2, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x800C6764: c.le.s      $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f20.fl <= ctx->f0.fl;
    // 0x800C6768: nop

    // 0x800C676C: bc1tl       L_800C6784
    if (c1cs) {
        // 0x800C6770: sub.s       $f0, $f0, $f20
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f20.fl;
            goto L_800C6784;
    }
    goto skip_0;
    // 0x800C6770: sub.s       $f0, $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f20.fl;
    skip_0:
L_800C6774:
    // 0x800C6774: trunc.w.s   $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    ctx->f4.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800C6778: mfc1        $v0, $f4
    ctx->r2 = (int32_t)ctx->f4.u32l;
    // 0x800C677C: j           L_800C6794
    // 0x800C6780: addu        $s2, $v0, $zero
    ctx->r18 = ADD32(ctx->r2, 0);
        goto L_800C6794;
    // 0x800C6780: addu        $s2, $v0, $zero
    ctx->r18 = ADD32(ctx->r2, 0);
L_800C6784:
    // 0x800C6784: trunc.w.s   $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    ctx->f4.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800C6788: mfc1        $v0, $f4
    ctx->r2 = (int32_t)ctx->f4.u32l;
    // 0x800C678C: or          $v0, $v0, $s5
    ctx->r2 = ctx->r2 | ctx->r21;
    // 0x800C6790: addu        $s2, $v0, $zero
    ctx->r18 = ADD32(ctx->r2, 0);
L_800C6794:
    // 0x800C6794: andi        $v0, $s0, 0xFF
    ctx->r2 = ctx->r16 & 0XFF;
L_800C6798:
    // 0x800C6798: lw          $v1, 0x0($s4)
    ctx->r3 = MEM_W(ctx->r20, 0X0);
    // 0x800C679C: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x800C67A0: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800C67A4: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x800C67A8: lbu         $v1, 0x5($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X5);
    // 0x800C67AC: addiu       $v0, $zero, 0x72
    ctx->r2 = ADD32(0, 0X72);
    // 0x800C67B0: beq         $v1, $v0, L_800C67E4
    if (ctx->r3 == ctx->r2) {
        // 0x800C67B4: slti        $v0, $v1, 0x73
        ctx->r2 = SIGNED(ctx->r3) < 0X73 ? 1 : 0;
            goto L_800C67E4;
    }
    // 0x800C67B4: slti        $v0, $v1, 0x73
    ctx->r2 = SIGNED(ctx->r3) < 0X73 ? 1 : 0;
    // 0x800C67B8: beq         $v0, $zero, L_800C67D0
    if (ctx->r2 == 0) {
        // 0x800C67BC: addiu       $v0, $zero, 0x67
        ctx->r2 = ADD32(0, 0X67);
            goto L_800C67D0;
    }
    // 0x800C67BC: addiu       $v0, $zero, 0x67
    ctx->r2 = ADD32(0, 0X67);
    // 0x800C67C0: beq         $v1, $v0, L_800C67F0
    if (ctx->r3 == ctx->r2) {
        // 0x800C67C4: andi        $v1, $s0, 0xFF
        ctx->r3 = ctx->r16 & 0XFF;
            goto L_800C67F0;
    }
    // 0x800C67C4: andi        $v1, $s0, 0xFF
    ctx->r3 = ctx->r16 & 0XFF;
    // 0x800C67C8: j           L_800C680C
    // 0x800C67CC: addu        $v0, $s3, $v1
    ctx->r2 = ADD32(ctx->r19, ctx->r3);
        goto L_800C680C;
    // 0x800C67CC: addu        $v0, $s3, $v1
    ctx->r2 = ADD32(ctx->r19, ctx->r3);
L_800C67D0:
    // 0x800C67D0: addiu       $v0, $zero, 0x77
    ctx->r2 = ADD32(0, 0X77);
    // 0x800C67D4: beq         $v1, $v0, L_800C67FC
    if (ctx->r3 == ctx->r2) {
        // 0x800C67D8: andi        $v1, $s0, 0xFF
        ctx->r3 = ctx->r16 & 0XFF;
            goto L_800C67FC;
    }
    // 0x800C67D8: andi        $v1, $s0, 0xFF
    ctx->r3 = ctx->r16 & 0XFF;
    // 0x800C67DC: j           L_800C680C
    // 0x800C67E0: addu        $v0, $s3, $v1
    ctx->r2 = ADD32(ctx->r19, ctx->r3);
        goto L_800C680C;
    // 0x800C67E0: addu        $v0, $s3, $v1
    ctx->r2 = ADD32(ctx->r19, ctx->r3);
L_800C67E4:
    // 0x800C67E4: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800C67E8: j           L_800C6804
    // 0x800C67EC: addiu       $s1, $v0, -0x5BE4
    ctx->r17 = ADD32(ctx->r2, -0X5BE4);
        goto L_800C6804;
    // 0x800C67EC: addiu       $s1, $v0, -0x5BE4
    ctx->r17 = ADD32(ctx->r2, -0X5BE4);
L_800C67F0:
    // 0x800C67F0: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800C67F4: j           L_800C6804
    // 0x800C67F8: addiu       $s1, $v0, -0x5BE8
    ctx->r17 = ADD32(ctx->r2, -0X5BE8);
        goto L_800C6804;
    // 0x800C67F8: addiu       $s1, $v0, -0x5BE8
    ctx->r17 = ADD32(ctx->r2, -0X5BE8);
L_800C67FC:
    // 0x800C67FC: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800C6800: addiu       $s1, $v0, -0x5BEC
    ctx->r17 = ADD32(ctx->r2, -0X5BEC);
L_800C6804:
    // 0x800C6804: andi        $v1, $s0, 0xFF
    ctx->r3 = ctx->r16 & 0XFF;
    // 0x800C6808: addu        $v0, $s3, $v1
    ctx->r2 = ADD32(ctx->r19, ctx->r3);
L_800C680C:
    // 0x800C680C: sb          $s2, 0x3($s1)
    MEM_B(0X3, ctx->r17) = ctx->r18;
    // 0x800C6810: lbu         $v0, 0x1E1($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X1E1);
    // 0x800C6814: bne         $v0, $zero, L_800C6834
    if (ctx->r2 != 0) {
        // 0x800C6818: sll         $a0, $v1, 3
        ctx->r4 = S32(ctx->r3 << 3);
            goto L_800C6834;
    }
    // 0x800C6818: sll         $a0, $v1, 3
    ctx->r4 = S32(ctx->r3 << 3);
    // 0x800C681C: addu        $a0, $a0, $v1
    ctx->r4 = ADD32(ctx->r4, ctx->r3);
    // 0x800C6820: sll         $a0, $a0, 3
    ctx->r4 = S32(ctx->r4 << 3);
    // 0x800C6824: addiu       $a0, $a0, 0x18
    ctx->r4 = ADD32(ctx->r4, 0X18);
    // 0x800C6828: addu        $a0, $s3, $a0
    ctx->r4 = ADD32(ctx->r19, ctx->r4);
    // 0x800C682C: j           L_800C6850
    // 0x800C6830: ori         $a1, $zero, 0xFFFF
    ctx->r5 = 0 | 0XFFFF;
        goto L_800C6850;
    // 0x800C6830: ori         $a1, $zero, 0xFFFF
    ctx->r5 = 0 | 0XFFFF;
L_800C6834:
    // 0x800C6834: addu        $a0, $a0, $v1
    ctx->r4 = ADD32(ctx->r4, ctx->r3);
    // 0x800C6838: sll         $a0, $a0, 3
    ctx->r4 = S32(ctx->r4 << 3);
    // 0x800C683C: addiu       $a0, $a0, 0x18
    ctx->r4 = ADD32(ctx->r4, 0X18);
    // 0x800C6840: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800C6844: lw          $v0, 0xC08($v0)
    ctx->r2 = MEM_W(ctx->r2, 0XC08);
    // 0x800C6848: addu        $a0, $s3, $a0
    ctx->r4 = ADD32(ctx->r19, ctx->r4);
    // 0x800C684C: lhu         $a1, 0x24($v0)
    ctx->r5 = MEM_HU(ctx->r2, 0X24);
L_800C6850:
    // 0x800C6850: jal         0x800C4060
    // 0x800C6854: addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    func_800C4060(rdram, ctx);
        goto after_0;
    // 0x800C6854: addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    after_0:
    // 0x800C6858: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x800C685C: lbu         $v1, 0x1E0($s3)
    ctx->r3 = MEM_BU(ctx->r19, 0X1E0);
    // 0x800C6860: andi        $v0, $s0, 0xFF
    ctx->r2 = ctx->r16 & 0XFF;
    // 0x800C6864: sltu        $v0, $v0, $v1
    ctx->r2 = ctx->r2 < ctx->r3 ? 1 : 0;
    // 0x800C6868: bne         $v0, $zero, L_800C6644
    if (ctx->r2 != 0) {
        // 0x800C686C: andi        $a1, $s0, 0xFF
        ctx->r5 = ctx->r16 & 0XFF;
            goto L_800C6644;
    }
    // 0x800C686C: andi        $a1, $s0, 0xFF
    ctx->r5 = ctx->r16 & 0XFF;
L_800C6870:
    // 0x800C6870: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x800C6874: lw          $s6, 0x28($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X28);
    // 0x800C6878: lw          $s5, 0x24($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X24);
    // 0x800C687C: lw          $s4, 0x20($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X20);
    // 0x800C6880: lw          $s3, 0x1C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X1C);
    // 0x800C6884: lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X18);
    // 0x800C6888: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x800C688C: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x800C6890: ldc1        $f22, 0x38($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X38);
    // 0x800C6894: ldc1        $f20, 0x30($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X30);
    // 0x800C6898: jr          $ra
    // 0x800C689C: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x800C689C: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void func_800C6660(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C6660: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x800C6664: sw          $ra, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r31;
    // 0x800C6668: sdc1        $f20, 0x40($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X40, ctx->r29);
    // 0x800C666C: jal         0x8000BC00
    // 0x800C6670: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    timeSnapshotFiller(rdram, ctx);
        goto after_0;
    // 0x800C6670: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    after_0:
    // 0x800C6674: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x800C6678: lw          $v1, -0x7764($v0)
    ctx->r3 = MEM_W(ctx->r2, -0X7764);
    // 0x800C667C: lwc1        $f20, 0x30($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X30);
    // 0x800C6680: lwc1        $f14, 0x2C($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x800C6684: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800C6688: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    // 0x800C668C: jal         0x8001E20C
    // 0x800C6690: sw          $v1, -0x7764($v0)
    MEM_W(-0X7764, ctx->r2) = ctx->r3;
    floatModulo(rdram, ctx);
        goto after_1;
    // 0x800C6690: sw          $v1, -0x7764($v0)
    MEM_W(-0X7764, ctx->r2) = ctx->r3;
    after_1:
    // 0x800C6694: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x800C6698: mov.s       $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    ctx->f4.fl = ctx->f0.fl;
    // 0x800C669C: c.lt.s      $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f2.fl < ctx->f4.fl;
    // 0x800C66A0: nop

    // 0x800C66A4: bc1f        L_800C66D8
    if (!c1cs) {
        // 0x800C66A8: nop
    
            goto L_800C66D8;
    }
    // 0x800C66A8: nop

    // 0x800C66AC: lwc1        $f6, 0x2C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x800C66B0: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800C66B4: lwc1        $f2, 0x76A4($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X76A4);
    // 0x800C66B8: div.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = DIV_S(ctx->f4.fl, ctx->f6.fl);
    // 0x800C66BC: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x800C66C0: nop

    // 0x800C66C4: bc1fl       L_800C66D4
    if (!c1cs) {
        // 0x800C66C8: add.s       $f0, $f20, $f6
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f20.fl + ctx->f6.fl;
            goto L_800C66D4;
    }
    goto skip_0;
    // 0x800C66C8: add.s       $f0, $f20, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f20.fl + ctx->f6.fl;
    skip_0:
    // 0x800C66CC: j           L_800C66D8
    // 0x800C66D0: sub.s       $f20, $f20, $f4
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f20.fl = ctx->f20.fl - ctx->f4.fl;
        goto L_800C66D8;
    // 0x800C66D0: sub.s       $f20, $f20, $f4
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f20.fl = ctx->f20.fl - ctx->f4.fl;
L_800C66D4:
    // 0x800C66D4: sub.s       $f20, $f0, $f4
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f20.fl = ctx->f0.fl - ctx->f4.fl;
L_800C66D8:
    // 0x800C66D8: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800C66DC: c.le.s      $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f20.fl <= ctx->f0.fl;
    // 0x800C66E0: nop

    // 0x800C66E4: bc1f        L_800C66F4
    if (!c1cs) {
        // 0x800C66E8: nop
    
            goto L_800C66F4;
    }
    // 0x800C66E8: nop

    // 0x800C66EC: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800C66F0: lwc1        $f20, 0x76A8($at)
    ctx->f20.u32l = MEM_W(ctx->r1, 0X76A8);
L_800C66F4:
    // 0x800C66F4: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800C66F8: lwc1        $f0, 0x76AC($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X76AC);
    // 0x800C66FC: c.lt.s      $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f0.fl < ctx->f20.fl;
    // 0x800C6700: nop

    // 0x800C6704: bc1tl       L_800C670C
    if (c1cs) {
        // 0x800C6708: mov.s       $f20, $f0
        CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
            goto L_800C670C;
    }
    goto skip_1;
    // 0x800C6708: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    skip_1:
L_800C670C:
    // 0x800C670C: mov.s       $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    ctx->f0.fl = ctx->f20.fl;
    // 0x800C6710: lw          $ra, 0x38($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X38);
    // 0x800C6714: ldc1        $f20, 0x40($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X40);
    // 0x800C6718: jr          $ra
    // 0x800C671C: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x800C671C: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void getLevelHardwiredDifficulty(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C6720: jr          $ra
    // 0x800C6724: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    return;
    // 0x800C6724: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
;}
RECOMP_FUNC void getSecondaryWeaponForLevelAndCraft(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C6728: andi        $v1, $a1, 0xFF
    ctx->r3 = ctx->r5 & 0XFF;
    // 0x800C672C: sltiu       $v0, $v1, 0x9
    ctx->r2 = ctx->r3 < 0X9 ? 1 : 0;
    // 0x800C6730: beq         $v0, $zero, L_800C6788
    if (ctx->r2 == 0) {
        // 0x800C6734: addiu       $a3, $zero, 0xFF
        ctx->r7 = ADD32(0, 0XFF);
            goto L_800C6788;
    }
    // 0x800C6734: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    // 0x800C6738: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x800C673C: addiu       $v0, $v0, 0x76B0
    ctx->r2 = ADD32(ctx->r2, 0X76B0);
    // 0x800C6740: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x800C6744: addu        $v1, $v1, $v0
    gpr jr_addend_800C674C = ctx->r3;
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x800C6748: lw          $v0, 0x0($v1)
    ctx->r2 = ADD32(ctx->r3, 0X0);
    // 0x800C674C: jr          $v0
    // 0x800C6750: nop

    switch (jr_addend_800C674C >> 2) {
        case 0: goto L_800C6754; break;
        case 1: goto L_800C675C; break;
        case 2: goto L_800C6764; break;
        case 3: goto L_800C676C; break;
        case 4: goto L_800C6774; break;
        case 5: goto L_800C6784; break;
        case 6: goto L_800C677C; break;
        case 7: goto L_800C677C; break;
        case 8: goto L_800C6784; break;
        default: switch_error(__func__, 0x800C674C, 0x800A76B0);
    }
    // 0x800C6750: nop

L_800C6754:
    // 0x800C6754: j           L_800C6788
    // 0x800C6758: addiu       $a3, $zero, 0x5
    ctx->r7 = ADD32(0, 0X5);
        goto L_800C6788;
    // 0x800C6758: addiu       $a3, $zero, 0x5
    ctx->r7 = ADD32(0, 0X5);
L_800C675C:
    // 0x800C675C: j           L_800C6788
    // 0x800C6760: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
        goto L_800C6788;
    // 0x800C6760: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
L_800C6764:
    // 0x800C6764: j           L_800C6788
    // 0x800C6768: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
        goto L_800C6788;
    // 0x800C6768: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
L_800C676C:
    // 0x800C676C: j           L_800C6788
    // 0x800C6770: addiu       $a3, $zero, 0x7
    ctx->r7 = ADD32(0, 0X7);
        goto L_800C6788;
    // 0x800C6770: addiu       $a3, $zero, 0x7
    ctx->r7 = ADD32(0, 0X7);
L_800C6774:
    // 0x800C6774: j           L_800C6788
    // 0x800C6778: addiu       $a3, $zero, 0x6
    ctx->r7 = ADD32(0, 0X6);
        goto L_800C6788;
    // 0x800C6778: addiu       $a3, $zero, 0x6
    ctx->r7 = ADD32(0, 0X6);
L_800C677C:
    // 0x800C677C: j           L_800C6788
    // 0x800C6780: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
        goto L_800C6788;
    // 0x800C6780: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
L_800C6784:
    // 0x800C6784: addiu       $a3, $zero, 0x8
    ctx->r7 = ADD32(0, 0X8);
L_800C6788:
    // 0x800C6788: andi        $v1, $a0, 0xFF
    ctx->r3 = ctx->r4 & 0XFF;
    // 0x800C678C: addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
    // 0x800C6790: bne         $v1, $v0, L_800C67A8
    if (ctx->r3 != ctx->r2) {
        // 0x800C6794: addiu       $v0, $zero, 0x2
        ctx->r2 = ADD32(0, 0X2);
            goto L_800C67A8;
    }
    // 0x800C6794: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x800C6798: andi        $v0, $a1, 0xFF
    ctx->r2 = ctx->r5 & 0XFF;
    // 0x800C679C: beql        $v0, $zero, L_800C67A4
    if (ctx->r2 == 0) {
        // 0x800C67A0: addiu       $a3, $zero, 0x1
        ctx->r7 = ADD32(0, 0X1);
            goto L_800C67A4;
    }
    goto skip_0;
    // 0x800C67A0: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    skip_0:
L_800C67A4:
    // 0x800C67A4: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
L_800C67A8:
    // 0x800C67A8: bne         $a3, $v0, L_800C67D8
    if (ctx->r7 != ctx->r2) {
        // 0x800C67AC: addiu       $v0, $zero, 0x5
        ctx->r2 = ADD32(0, 0X5);
            goto L_800C67D8;
    }
    // 0x800C67AC: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
    // 0x800C67B0: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800C67B4: addiu       $v0, $v0, 0xB40
    ctx->r2 = ADD32(ctx->r2, 0XB40);
    // 0x800C67B8: andi        $v1, $a2, 0xFF
    ctx->r3 = ctx->r6 & 0XFF;
    // 0x800C67BC: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x800C67C0: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x800C67C4: lw          $v0, 0xC($v1)
    ctx->r2 = MEM_W(ctx->r3, 0XC);
    // 0x800C67C8: andi        $v0, $v0, 0x800
    ctx->r2 = ctx->r2 & 0X800;
    // 0x800C67CC: bnel        $v0, $zero, L_800C67D4
    if (ctx->r2 != 0) {
        // 0x800C67D0: addiu       $a3, $zero, 0x3
        ctx->r7 = ADD32(0, 0X3);
            goto L_800C67D4;
    }
    goto skip_1;
    // 0x800C67D0: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    skip_1:
L_800C67D4:
    // 0x800C67D4: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
L_800C67D8:
    // 0x800C67D8: bne         $a3, $v0, L_800C6808
    if (ctx->r7 != ctx->r2) {
        // 0x800C67DC: addiu       $v0, $zero, 0x7
        ctx->r2 = ADD32(0, 0X7);
            goto L_800C6808;
    }
    // 0x800C67DC: addiu       $v0, $zero, 0x7
    ctx->r2 = ADD32(0, 0X7);
    // 0x800C67E0: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800C67E4: addiu       $v0, $v0, 0xB40
    ctx->r2 = ADD32(ctx->r2, 0XB40);
    // 0x800C67E8: andi        $v1, $a2, 0xFF
    ctx->r3 = ctx->r6 & 0XFF;
    // 0x800C67EC: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x800C67F0: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x800C67F4: lw          $v0, 0xC($v1)
    ctx->r2 = MEM_W(ctx->r3, 0XC);
    // 0x800C67F8: andi        $v0, $v0, 0x2000
    ctx->r2 = ctx->r2 & 0X2000;
    // 0x800C67FC: bnel        $v0, $zero, L_800C6804
    if (ctx->r2 != 0) {
        // 0x800C6800: addiu       $a3, $zero, 0x8
        ctx->r7 = ADD32(0, 0X8);
            goto L_800C6804;
    }
    goto skip_2;
    // 0x800C6800: addiu       $a3, $zero, 0x8
    ctx->r7 = ADD32(0, 0X8);
    skip_2:
L_800C6804:
    // 0x800C6804: addiu       $v0, $zero, 0x7
    ctx->r2 = ADD32(0, 0X7);
L_800C6808:
    // 0x800C6808: bne         $a3, $v0, L_800C6830
    if (ctx->r7 != ctx->r2) {
        // 0x800C680C: lui         $v0, 0x8013
        ctx->r2 = S32(0X8013 << 16);
            goto L_800C6830;
    }
    // 0x800C680C: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800C6810: addiu       $v0, $v0, 0xB40
    ctx->r2 = ADD32(ctx->r2, 0XB40);
    // 0x800C6814: andi        $v1, $a2, 0xFF
    ctx->r3 = ctx->r6 & 0XFF;
    // 0x800C6818: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x800C681C: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x800C6820: lw          $v0, 0xC($v1)
    ctx->r2 = MEM_W(ctx->r3, 0XC);
    // 0x800C6824: andi        $v0, $v0, 0x4000
    ctx->r2 = ctx->r2 & 0X4000;
    // 0x800C6828: bnel        $v0, $zero, L_800C6830
    if (ctx->r2 != 0) {
        // 0x800C682C: addiu       $a3, $zero, 0x9
        ctx->r7 = ADD32(0, 0X9);
            goto L_800C6830;
    }
    goto skip_3;
    // 0x800C682C: addiu       $a3, $zero, 0x9
    ctx->r7 = ADD32(0, 0X9);
    skip_3:
L_800C6830:
    // 0x800C6830: jr          $ra
    // 0x800C6834: addu        $v0, $a3, $zero
    ctx->r2 = ADD32(ctx->r7, 0);
    return;
    // 0x800C6834: addu        $v0, $a3, $zero
    ctx->r2 = ADD32(ctx->r7, 0);
;}
RECOMP_FUNC void hasKasanMoorDefected(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C6838: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
    // 0x800C683C: andi        $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 & 0XFF;
    // 0x800C6840: sltu        $a0, $a0, $v0
    ctx->r4 = ctx->r4 < ctx->r2 ? 1 : 0;
    // 0x800C6844: bnel        $a0, $zero, L_800C684C
    if (ctx->r4 != 0) {
        // 0x800C6848: addiu       $v0, $zero, 0x4
        ctx->r2 = ADD32(0, 0X4);
            goto L_800C684C;
    }
    goto skip_0;
    // 0x800C6848: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    skip_0:
L_800C684C:
    // 0x800C684C: jr          $ra
    // 0x800C6850: nop

    return;
    // 0x800C6850: nop

;}
RECOMP_FUNC void func_800C6854(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C6854: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800C6858: sw          $s3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r19;
    // 0x800C685C: addu        $s3, $a0, $zero
    ctx->r19 = ADD32(ctx->r4, 0);
    // 0x800C6860: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x800C6864: addu        $s0, $a1, $zero
    ctx->r16 = ADD32(ctx->r5, 0);
    // 0x800C6868: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x800C686C: addu        $s1, $a2, $zero
    ctx->r17 = ADD32(ctx->r6, 0);
    // 0x800C6870: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x800C6874: sw          $ra, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r31;
    // 0x800C6878: jal         0x800C6234
    // 0x800C687C: sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    getAvailablePlayerCraftFlagsConsiderUnlocks(rdram, ctx);
        goto after_0;
    // 0x800C687C: sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    after_0:
    // 0x800C6880: andi        $a0, $s0, 0xFF
    ctx->r4 = ctx->r16 & 0XFF;
    // 0x800C6884: lui         $s2, 0xFF
    ctx->r18 = S32(0XFF << 16);
    // 0x800C6888: ori         $s2, $s2, 0xFFFF
    ctx->r18 = ctx->r18 | 0XFFFF;
    // 0x800C688C: lui         $a1, 0x800A
    ctx->r5 = S32(0X800A << 16);
    // 0x800C6890: addiu       $a1, $a1, -0x13B0
    ctx->r5 = ADD32(ctx->r5, -0X13B0);
    // 0x800C6894: sll         $v1, $s1, 2
    ctx->r3 = S32(ctx->r17 << 2);
    // 0x800C6898: addu        $v1, $v1, $a1
    ctx->r3 = ADD32(ctx->r3, ctx->r5);
    // 0x800C689C: addu        $a2, $v0, $zero
    ctx->r6 = ADD32(ctx->r2, 0);
    // 0x800C68A0: lbu         $a1, 0x3($v1)
    ctx->r5 = MEM_BU(ctx->r3, 0X3);
    // 0x800C68A4: jal         0x800A9364
    // 0x800C68A8: andi        $a3, $s1, 0xFF
    ctx->r7 = ctx->r17 & 0XFF;
    hangarInitialize(rdram, ctx);
        goto after_1;
    // 0x800C68A8: andi        $a3, $s1, 0xFF
    ctx->r7 = ctx->r17 & 0XFF;
    after_1:
L_800C68AC:
    // 0x800C68AC: jal         0x800AAD9C
    // 0x800C68B0: andi        $a0, $s1, 0xFF
    ctx->r4 = ctx->r17 & 0XFF;
    func_800AAD9C(rdram, ctx);
        goto after_2;
    // 0x800C68B0: andi        $a0, $s1, 0xFF
    ctx->r4 = ctx->r17 & 0XFF;
    after_2:
    // 0x800C68B4: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    // 0x800C68B8: beq         $s0, $s2, L_800C68AC
    if (ctx->r16 == ctx->r18) {
        // 0x800C68BC: nop
    
            goto L_800C68AC;
    }
    // 0x800C68BC: nop

    // 0x800C68C0: jal         0x800AE74C
    // 0x800C68C4: nop

    func_800AE74C(rdram, ctx);
        goto after_3;
    // 0x800C68C4: nop

    after_3:
    // 0x800C68C8: lui         $v0, 0xFF
    ctx->r2 = S32(0XFF << 16);
    // 0x800C68CC: ori         $v0, $v0, 0xFFFE
    ctx->r2 = ctx->r2 | 0XFFFE;
    // 0x800C68D0: bnel        $s0, $v0, L_800C68E0
    if (ctx->r16 != ctx->r2) {
        // 0x800C68D4: sb          $s0, 0x1($s3)
        MEM_B(0X1, ctx->r19) = ctx->r16;
            goto L_800C68E0;
    }
    goto skip_0;
    // 0x800C68D4: sb          $s0, 0x1($s3)
    MEM_B(0X1, ctx->r19) = ctx->r16;
    skip_0:
    // 0x800C68D8: j           L_800C68E4
    // 0x800C68DC: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
        goto L_800C68E4;
    // 0x800C68DC: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_800C68E0:
    // 0x800C68E0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800C68E4:
    // 0x800C68E4: lw          $ra, 0x20($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X20);
    // 0x800C68E8: lw          $s3, 0x1C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X1C);
    // 0x800C68EC: lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X18);
    // 0x800C68F0: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x800C68F4: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x800C68F8: jr          $ra
    // 0x800C68FC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x800C68FC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_800C68A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C68A0: addiu       $sp, $sp, -0xC0
    ctx->r29 = ADD32(ctx->r29, -0XC0);
    // 0x800C68A4: sw          $s1, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->r17;
    // 0x800C68A8: addu        $s1, $a0, $zero
    ctx->r17 = ADD32(ctx->r4, 0);
    // 0x800C68AC: sw          $s0, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->r16;
    // 0x800C68B0: addu        $s0, $a2, $zero
    ctx->r16 = ADD32(ctx->r6, 0);
    // 0x800C68B4: sw          $s3, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->r19;
    // 0x800C68B8: andi        $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 & 0XFFFF;
    // 0x800C68BC: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x800C68C0: sw          $ra, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->r31;
    // 0x800C68C4: sw          $s2, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->r18;
    // 0x800C68C8: sdc1        $f20, 0xB8($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0XB8, ctx->r29);
    // 0x800C68CC: lw          $s2, 0x4($s1)
    ctx->r18 = MEM_W(ctx->r17, 0X4);
    // 0x800C68D0: beq         $a1, $v0, L_800C69D4
    if (ctx->r5 == ctx->r2) {
        // 0x800C68D4: addu        $s3, $s0, $zero
        ctx->r19 = ADD32(ctx->r16, 0);
            goto L_800C69D4;
    }
    // 0x800C68D4: addu        $s3, $s0, $zero
    ctx->r19 = ADD32(ctx->r16, 0);
    // 0x800C68D8: slti        $v0, $a1, 0x3
    ctx->r2 = SIGNED(ctx->r5) < 0X3 ? 1 : 0;
    // 0x800C68DC: beq         $v0, $zero, L_800C68F4
    if (ctx->r2 == 0) {
        // 0x800C68E0: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_800C68F4;
    }
    // 0x800C68E0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800C68E4: beq         $a1, $v0, L_800C6910
    if (ctx->r5 == ctx->r2) {
        // 0x800C68E8: addiu       $a0, $zero, 0x1E8
        ctx->r4 = ADD32(0, 0X1E8);
            goto L_800C6910;
    }
    // 0x800C68E8: addiu       $a0, $zero, 0x1E8
    ctx->r4 = ADD32(0, 0X1E8);
    // 0x800C68EC: j           L_800C6FD8
    // 0x800C68F0: nop

        goto L_800C6FD8;
    // 0x800C68F0: nop

L_800C68F4:
    // 0x800C68F4: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    // 0x800C68F8: beq         $a1, $a3, L_800C69E8
    if (ctx->r5 == ctx->r7) {
        // 0x800C68FC: addiu       $v0, $zero, 0x4
        ctx->r2 = ADD32(0, 0X4);
            goto L_800C69E8;
    }
    // 0x800C68FC: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // 0x800C6900: beq         $a1, $v0, L_800C6E84
    if (ctx->r5 == ctx->r2) {
        // 0x800C6904: lui         $v1, 0x8014
        ctx->r3 = S32(0X8014 << 16);
            goto L_800C6E84;
    }
    // 0x800C6904: lui         $v1, 0x8014
    ctx->r3 = S32(0X8014 << 16);
    // 0x800C6908: j           L_800C6FD8
    // 0x800C690C: nop

        goto L_800C6FD8;
    // 0x800C690C: nop

L_800C6910:
    // 0x800C6910: jal         0x80001ACC
    // 0x800C6914: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    rs_malloc(rdram, ctx);
        goto after_0;
    // 0x800C6914: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    after_0:
    // 0x800C6918: addu        $s2, $v0, $zero
    ctx->r18 = ADD32(ctx->r2, 0);
    // 0x800C691C: sw          $s2, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->r18;
    // 0x800C6920: lwc1        $f0, 0x0($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X0);
    // 0x800C6924: lui         $s0, 0x8011
    ctx->r16 = S32(0X8011 << 16);
    // 0x800C6928: addiu       $s0, $s0, -0x5F04
    ctx->r16 = ADD32(ctx->r16, -0X5F04);
    // 0x800C692C: trunc.w.s   $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    ctx->f8.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800C6930: mfc1        $a0, $f8
    ctx->r4 = (int32_t)ctx->f8.u32l;
    // 0x800C6934: jal         0x8006C940
    // 0x800C6938: sw          $a0, 0x4($s2)
    MEM_W(0X4, ctx->r18) = ctx->r4;
    getPlayerVehicleId(rdram, ctx);
        goto after_1;
    // 0x800C6938: sw          $a0, 0x4($s2)
    MEM_W(0X4, ctx->r18) = ctx->r4;
    after_1:
    // 0x800C693C: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800C6940: addu        $v0, $v0, $s0
    ctx->r2 = ADD32(ctx->r2, ctx->r16);
    // 0x800C6944: lw          $a0, 0x0($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X0);
    // 0x800C6948: jal         0x80056EB0
    // 0x800C694C: nop

    walkMeshdef0List(rdram, ctx);
        goto after_2;
    // 0x800C694C: nop

    after_2:
    // 0x800C6950: addiu       $a0, $v0, 0x28
    ctx->r4 = ADD32(ctx->r2, 0X28);
    // 0x800C6954: jal         0x8001CA50
    // 0x800C6958: sw          $v0, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r2;
    func_8001CA50(rdram, ctx);
        goto after_3;
    // 0x800C6958: sw          $v0, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r2;
    after_3:
    // 0x800C695C: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x800C6960: lhu         $a0, -0x6A8C($v0)
    ctx->r4 = MEM_HU(ctx->r2, -0X6A8C);
    // 0x800C6964: jal         0x8003E684
    // 0x800C6968: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    func_8003E684(rdram, ctx);
        goto after_4;
    // 0x800C6968: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    after_4:
    // 0x800C696C: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x800C6970: lui         $a2, 0x1
    ctx->r6 = S32(0X1 << 16);
    // 0x800C6974: ori         $a2, $a2, 0x8
    ctx->r6 = ctx->r6 | 0X8;
    // 0x800C6978: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    // 0x800C697C: jal         0x8005955C
    // 0x800C6980: addu        $a3, $a1, $zero
    ctx->r7 = ADD32(ctx->r5, 0);
    func_8005955C(rdram, ctx);
        goto after_5;
    // 0x800C6980: addu        $a3, $a1, $zero
    ctx->r7 = ADD32(ctx->r5, 0);
    after_5:
    // 0x800C6984: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    // 0x800C6988: sw          $zero, 0x14($s2)
    MEM_W(0X14, ctx->r18) = 0;
    // 0x800C698C: lwc1        $f0, 0x14($s2)
    ctx->f0.u32l = MEM_W(ctx->r18, 0X14);
    // 0x800C6990: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800C6994: sw          $s2, -0x3F70($v0)
    MEM_W(-0X3F70, ctx->r2) = ctx->r18;
    // 0x800C6998: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800C699C: sw          $zero, 0x8($s2)
    MEM_W(0X8, ctx->r18) = 0;
    // 0x800C69A0: sw          $zero, 0xC($s2)
    MEM_W(0XC, ctx->r18) = 0;
    // 0x800C69A4: sw          $zero, 0x10($s2)
    MEM_W(0X10, ctx->r18) = 0;
    // 0x800C69A8: addiu       $a0, $a0, 0x28
    ctx->r4 = ADD32(ctx->r4, 0X28);
    // 0x800C69AC: jal         0x8001CA50
    // 0x800C69B0: swc1        $f0, -0x5E00($v0)
    MEM_W(-0X5E00, ctx->r2) = ctx->f0.u32l;
    func_8001CA50(rdram, ctx);
        goto after_6;
    // 0x800C69B0: swc1        $f0, -0x5E00($v0)
    MEM_W(-0X5E00, ctx->r2) = ctx->f0.u32l;
    after_6:
    // 0x800C69B4: lw          $a0, 0x4($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X4);
    // 0x800C69B8: jal         0x8006C940
    // 0x800C69BC: nop

    getPlayerVehicleId(rdram, ctx);
        goto after_7;
    // 0x800C69BC: nop

    after_7:
    // 0x800C69C0: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // 0x800C69C4: jal         0x800C64B0
    // 0x800C69C8: andi        $a1, $v0, 0xFF
    ctx->r5 = ctx->r2 & 0XFF;
    func_800C64B0(rdram, ctx);
        goto after_8;
    // 0x800C69C8: andi        $a1, $v0, 0xFF
    ctx->r5 = ctx->r2 & 0XFF;
    after_8:
    // 0x800C69CC: j           L_800C6FD8
    // 0x800C69D0: nop

        goto L_800C6FD8;
    // 0x800C69D0: nop

L_800C69D4:
    // 0x800C69D4: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    // 0x800C69D8: jal         0x8005779C
    // 0x800C69DC: nop

    func_8005779C(rdram, ctx);
        goto after_9;
    // 0x800C69DC: nop

    after_9:
    // 0x800C69E0: j           L_800C6FD8
    // 0x800C69E4: nop

        goto L_800C6FD8;
    // 0x800C69E4: nop

L_800C69E8:
    // 0x800C69E8: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800C69EC: lui         $s0, 0x8011
    ctx->r16 = S32(0X8011 << 16);
    // 0x800C69F0: lw          $a0, 0x4($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X4);
    // 0x800C69F4: lwc1        $f0, 0x14($s2)
    ctx->f0.u32l = MEM_W(ctx->r18, 0X14);
    // 0x800C69F8: addiu       $s0, $s0, -0x5EE0
    ctx->r16 = ADD32(ctx->r16, -0X5EE0);
    // 0x800C69FC: jal         0x8006C940
    // 0x800C6A00: swc1        $f0, -0x5E00($v0)
    MEM_W(-0X5E00, ctx->r2) = ctx->f0.u32l;
    getPlayerVehicleId(rdram, ctx);
        goto after_10;
    // 0x800C6A00: swc1        $f0, -0x5E00($v0)
    MEM_W(-0X5E00, ctx->r2) = ctx->f0.u32l;
    after_10:
    // 0x800C6A04: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800C6A08: addu        $v0, $v0, $s0
    ctx->r2 = ADD32(ctx->r2, ctx->r16);
    // 0x800C6A0C: lw          $a0, 0x4($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X4);
    // 0x800C6A10: lwc1        $f20, 0x0($v0)
    ctx->f20.u32l = MEM_W(ctx->r2, 0X0);
    // 0x800C6A14: jal         0x8006C940
    // 0x800C6A18: nop

    getPlayerVehicleId(rdram, ctx);
        goto after_11;
    // 0x800C6A18: nop

    after_11:
    // 0x800C6A1C: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    // 0x800C6A20: sll         $v1, $v0, 1
    ctx->r3 = S32(ctx->r2 << 1);
    // 0x800C6A24: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x800C6A28: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x800C6A2C: lui         $a2, 0x8011
    ctx->r6 = S32(0X8011 << 16);
    // 0x800C6A30: addiu       $a2, $a2, -0x5F70
    ctx->r6 = ADD32(ctx->r6, -0X5F70);
    // 0x800C6A34: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x800C6A38: jal         0x800AA3B4
    // 0x800C6A3C: addu        $a2, $v1, $a2
    ctx->r6 = ADD32(ctx->r3, ctx->r6);
    func_800AA3B4(rdram, ctx);
        goto after_12;
    // 0x800C6A3C: addu        $a2, $v1, $a2
    ctx->r6 = ADD32(ctx->r3, ctx->r6);
    after_12:
    // 0x800C6A40: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    // 0x800C6A44: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x800C6A48: lw          $v1, 0x4($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X4);
    // 0x800C6A4C: addiu       $a0, $a0, -0x7FF4
    ctx->r4 = ADD32(ctx->r4, -0X7FF4);
    // 0x800C6A50: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x800C6A54: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800C6A58: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800C6A5C: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800C6A60: sll         $v0, $v0, 5
    ctx->r2 = S32(ctx->r2 << 5);
    // 0x800C6A64: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x800C6A68: addiu       $v1, $v0, 0x30
    ctx->r3 = ADD32(ctx->r2, 0X30);
L_800C6A6C:
    // 0x800C6A6C: lw          $t1, 0x0($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X0);
    // 0x800C6A70: lw          $t2, 0x4($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X4);
    // 0x800C6A74: lw          $t3, 0x8($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X8);
    // 0x800C6A78: lw          $t0, 0xC($v0)
    ctx->r8 = MEM_W(ctx->r2, 0XC);
    // 0x800C6A7C: sw          $t1, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r9;
    // 0x800C6A80: sw          $t2, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r10;
    // 0x800C6A84: sw          $t3, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->r11;
    // 0x800C6A88: sw          $t0, 0xC($a1)
    MEM_W(0XC, ctx->r5) = ctx->r8;
    // 0x800C6A8C: addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
    // 0x800C6A90: bne         $v0, $v1, L_800C6A6C
    if (ctx->r2 != ctx->r3) {
        // 0x800C6A94: addiu       $a1, $a1, 0x10
        ctx->r5 = ADD32(ctx->r5, 0X10);
            goto L_800C6A6C;
    }
    // 0x800C6A94: addiu       $a1, $a1, 0x10
    ctx->r5 = ADD32(ctx->r5, 0X10);
    // 0x800C6A98: lw          $a0, 0x4($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X4);
    // 0x800C6A9C: jal         0x8006C940
    // 0x800C6AA0: nop

    getPlayerVehicleId(rdram, ctx);
        goto after_13;
    // 0x800C6AA0: nop

    after_13:
    // 0x800C6AA4: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // 0x800C6AA8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800C6AAC: beq         $v1, $v0, L_800C6AF4
    if (ctx->r3 == ctx->r2) {
        // 0x800C6AB0: addiu       $v0, $zero, 0x5
        ctx->r2 = ADD32(0, 0X5);
            goto L_800C6AF4;
    }
    // 0x800C6AB0: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
    // 0x800C6AB4: bne         $v1, $v0, L_800C6AF8
    if (ctx->r3 != ctx->r2) {
        // 0x800C6AB8: lui         $v0, 0x8013
        ctx->r2 = S32(0X8013 << 16);
            goto L_800C6AF8;
    }
    // 0x800C6AB8: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800C6ABC: addiu       $a0, $sp, 0x40
    ctx->r4 = ADD32(ctx->r29, 0X40);
    // 0x800C6AC0: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    // 0x800C6AC4: lwc1        $f0, 0x10($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X10);
    // 0x800C6AC8: addiu       $a2, $sp, 0x30
    ctx->r6 = ADD32(ctx->r29, 0X30);
    // 0x800C6ACC: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x800C6AD0: sw          $zero, 0x28($sp)
    MEM_W(0X28, ctx->r29) = 0;
    // 0x800C6AD4: jal         0x800193E8
    // 0x800C6AD8: swc1        $f0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f0.u32l;
    func_800193E8(rdram, ctx);
        goto after_14;
    // 0x800C6AD8: swc1        $f0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f0.u32l;
    after_14:
    // 0x800C6ADC: lwc1        $f0, 0x30($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X30);
    // 0x800C6AE0: lwc1        $f2, 0x34($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X34);
    // 0x800C6AE4: lwc1        $f4, 0x38($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X38);
    // 0x800C6AE8: swc1        $f0, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f0.u32l;
    // 0x800C6AEC: swc1        $f2, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f2.u32l;
    // 0x800C6AF0: swc1        $f4, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->f4.u32l;
L_800C6AF4:
    // 0x800C6AF4: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
L_800C6AF8:
    // 0x800C6AF8: lw          $a1, 0x4($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X4);
    // 0x800C6AFC: addiu       $v0, $v0, 0x7DB8
    ctx->r2 = ADD32(ctx->r2, 0X7DB8);
    // 0x800C6B00: sll         $v1, $a1, 2
    ctx->r3 = S32(ctx->r5 << 2);
    // 0x800C6B04: addu        $v1, $v1, $a1
    ctx->r3 = ADD32(ctx->r3, ctx->r5);
    // 0x800C6B08: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x800C6B0C: addu        $v1, $v1, $a1
    ctx->r3 = ADD32(ctx->r3, ctx->r5);
    // 0x800C6B10: sll         $v1, $v1, 5
    ctx->r3 = S32(ctx->r3 << 5);
    // 0x800C6B14: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x800C6B18: lhu         $v0, 0x184($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X184);
    // 0x800C6B1C: andi        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 & 0X1;
    // 0x800C6B20: beq         $v0, $zero, L_800C6D64
    if (ctx->r2 == 0) {
        // 0x800C6B24: sll         $v1, $a1, 1
        ctx->r3 = S32(ctx->r5 << 1);
            goto L_800C6D64;
    }
    // 0x800C6B24: sll         $v1, $a1, 1
    ctx->r3 = S32(ctx->r5 << 1);
    // 0x800C6B28: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800C6B2C: addiu       $v0, $v0, 0xB88
    ctx->r2 = ADD32(ctx->r2, 0XB88);
    // 0x800C6B30: addu        $v1, $v1, $a1
    ctx->r3 = ADD32(ctx->r3, ctx->r5);
    // 0x800C6B34: sll         $v1, $v1, 1
    ctx->r3 = S32(ctx->r3 << 1);
    // 0x800C6B38: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x800C6B3C: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x800C6B40: addiu       $a0, $a0, -0x41E8
    ctx->r4 = ADD32(ctx->r4, -0X41E8);
    // 0x800C6B44: sll         $a2, $a1, 3
    ctx->r6 = S32(ctx->r5 << 3);
    // 0x800C6B48: addu        $v0, $a2, $a1
    ctx->r2 = ADD32(ctx->r6, ctx->r5);
    // 0x800C6B4C: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800C6B50: addu        $a0, $v0, $a0
    ctx->r4 = ADD32(ctx->r2, ctx->r4);
    // 0x800C6B54: lhu         $v1, 0x0($v1)
    ctx->r3 = MEM_HU(ctx->r3, 0X0);
    // 0x800C6B58: lhu         $v0, 0x20($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X20);
    // 0x800C6B5C: and         $v0, $v1, $v0
    ctx->r2 = ctx->r3 & ctx->r2;
    // 0x800C6B60: bnel        $v0, $zero, L_800C6C7C
    if (ctx->r2 != 0) {
        // 0x800C6B64: lui         $v1, 0x8011
        ctx->r3 = S32(0X8011 << 16);
            goto L_800C6C7C;
    }
    goto skip_0;
    // 0x800C6B64: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
    skip_0:
    // 0x800C6B68: lhu         $v0, 0x6($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X6);
    // 0x800C6B6C: and         $v0, $v1, $v0
    ctx->r2 = ctx->r3 & ctx->r2;
    // 0x800C6B70: bnel        $v0, $zero, L_800C6C7C
    if (ctx->r2 != 0) {
        // 0x800C6B74: lui         $v1, 0x8011
        ctx->r3 = S32(0X8011 << 16);
            goto L_800C6C7C;
    }
    goto skip_1;
    // 0x800C6B74: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
    skip_1:
    // 0x800C6B78: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800C6B7C: addiu       $v0, $v0, -0x4228
    ctx->r2 = ADD32(ctx->r2, -0X4228);
    // 0x800C6B80: addu        $v0, $a2, $v0
    ctx->r2 = ADD32(ctx->r6, ctx->r2);
    // 0x800C6B84: lwc1        $f4, 0x0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X0);
    // 0x800C6B88: abs.s       $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = fabsf(ctx->f4.fl);
    // 0x800C6B8C: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800C6B90: lwc1        $f0, 0x691C($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X691C);
    // 0x800C6B94: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x800C6B98: nop

    // 0x800C6B9C: bc1fl       L_800C6C7C
    if (!c1cs) {
        // 0x800C6BA0: lui         $v1, 0x8011
        ctx->r3 = S32(0X8011 << 16);
            goto L_800C6C7C;
    }
    goto skip_2;
    // 0x800C6BA0: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
    skip_2:
    // 0x800C6BA4: lwc1        $f2, 0x8($s2)
    ctx->f2.u32l = MEM_W(ctx->r18, 0X8);
    // 0x800C6BA8: abs.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = fabsf(ctx->f2.fl);
    // 0x800C6BAC: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800C6BB0: lwc1        $f6, 0x6920($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X6920);
    // 0x800C6BB4: c.lt.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl < ctx->f6.fl;
    // 0x800C6BB8: nop

    // 0x800C6BBC: bc1fl       L_800C6C10
    if (!c1cs) {
        // 0x800C6BC0: lui         $v1, 0x8011
        ctx->r3 = S32(0X8011 << 16);
            goto L_800C6C10;
    }
    goto skip_3;
    // 0x800C6BC0: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
    skip_3:
    // 0x800C6BC4: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800C6BC8: lwc1        $f0, 0x6924($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X6924);
    // 0x800C6BCC: mul.s       $f0, $f4, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x800C6BD0: add.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x800C6BD4: swc1        $f2, 0x8($s2)
    MEM_W(0X8, ctx->r18) = ctx->f2.u32l;
    // 0x800C6BD8: abs.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = fabsf(ctx->f2.fl);
    // 0x800C6BDC: c.lt.s      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.fl < ctx->f0.fl;
    // 0x800C6BE0: nop

    // 0x800C6BE4: bc1f        L_800C6C10
    if (!c1cs) {
        // 0x800C6BE8: lui         $v1, 0x8011
        ctx->r3 = S32(0X8011 << 16);
            goto L_800C6C10;
    }
    // 0x800C6BE8: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
    // 0x800C6BEC: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800C6BF0: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800C6BF4: lwc1        $f4, 0x6928($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X6928);
    // 0x800C6BF8: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x800C6BFC: nop

    // 0x800C6C00: bc1tl       L_800C6C08
    if (c1cs) {
        // 0x800C6C04: mov.s       $f4, $f6
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    ctx->f4.fl = ctx->f6.fl;
            goto L_800C6C08;
    }
    goto skip_4;
    // 0x800C6C04: mov.s       $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    ctx->f4.fl = ctx->f6.fl;
    skip_4:
L_800C6C08:
    // 0x800C6C08: swc1        $f4, 0x8($s2)
    MEM_W(0X8, ctx->r18) = ctx->f4.u32l;
    // 0x800C6C0C: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
L_800C6C10:
    // 0x800C6C10: addiu       $v1, $v1, -0x4228
    ctx->r3 = ADD32(ctx->r3, -0X4228);
    // 0x800C6C14: lw          $v0, 0x4($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X4);
    // 0x800C6C18: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800C6C1C: lwc1        $f2, 0x692C($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X692C);
    // 0x800C6C20: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x800C6C24: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800C6C28: lwc1        $f0, 0x4($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X4);
    // 0x800C6C2C: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x800C6C30: lwc1        $f2, 0xC($s2)
    ctx->f2.u32l = MEM_W(ctx->r18, 0XC);
    // 0x800C6C34: add.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x800C6C38: swc1        $f2, 0xC($s2)
    MEM_W(0XC, ctx->r18) = ctx->f2.u32l;
    // 0x800C6C3C: abs.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = fabsf(ctx->f2.fl);
    // 0x800C6C40: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800C6C44: lwc1        $f6, 0x6930($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X6930);
    // 0x800C6C48: c.lt.s      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.fl < ctx->f0.fl;
    // 0x800C6C4C: nop

    // 0x800C6C50: bc1f        L_800C6C7C
    if (!c1cs) {
        // 0x800C6C54: lui         $v1, 0x8011
        ctx->r3 = S32(0X8011 << 16);
            goto L_800C6C7C;
    }
    // 0x800C6C54: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
    // 0x800C6C58: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800C6C5C: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800C6C60: lwc1        $f4, 0x6934($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X6934);
    // 0x800C6C64: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x800C6C68: nop

    // 0x800C6C6C: bc1tl       L_800C6C74
    if (c1cs) {
        // 0x800C6C70: mov.s       $f4, $f6
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    ctx->f4.fl = ctx->f6.fl;
            goto L_800C6C74;
    }
    goto skip_5;
    // 0x800C6C70: mov.s       $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    ctx->f4.fl = ctx->f6.fl;
    skip_5:
L_800C6C74:
    // 0x800C6C74: swc1        $f4, 0xC($s2)
    MEM_W(0XC, ctx->r18) = ctx->f4.u32l;
    // 0x800C6C78: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
L_800C6C7C:
    // 0x800C6C7C: addiu       $v1, $v1, -0x4228
    ctx->r3 = ADD32(ctx->r3, -0X4228);
    // 0x800C6C80: lw          $v0, 0x4($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X4);
    // 0x800C6C84: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800C6C88: lwc1        $f0, 0x6938($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X6938);
    // 0x800C6C8C: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x800C6C90: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800C6C94: lwc1        $f2, 0x4($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X4);
    // 0x800C6C98: mul.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x800C6C9C: lwc1        $f4, 0x8($s2)
    ctx->f4.u32l = MEM_W(ctx->r18, 0X8);
    // 0x800C6CA0: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x800C6CA4: c.lt.s      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.fl < ctx->f4.fl;
    // 0x800C6CA8: nop

    // 0x800C6CAC: bc1f        L_800C6CCC
    if (!c1cs) {
        // 0x800C6CB0: swc1        $f2, 0x10($s2)
        MEM_W(0X10, ctx->r18) = ctx->f2.u32l;
            goto L_800C6CCC;
    }
    // 0x800C6CB0: swc1        $f2, 0x10($s2)
    MEM_W(0X10, ctx->r18) = ctx->f2.u32l;
    // 0x800C6CB4: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800C6CB8: lwc1        $f0, 0x693C($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X693C);
    // 0x800C6CBC: sub.s       $f0, $f4, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f0.fl;
    // 0x800C6CC0: c.lt.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl < ctx->f6.fl;
    // 0x800C6CC4: j           L_800C6CE0
    // 0x800C6CC8: swc1        $f0, 0x8($s2)
    MEM_W(0X8, ctx->r18) = ctx->f0.u32l;
        goto L_800C6CE0;
    // 0x800C6CC8: swc1        $f0, 0x8($s2)
    MEM_W(0X8, ctx->r18) = ctx->f0.u32l;
L_800C6CCC:
    // 0x800C6CCC: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800C6CD0: lwc1        $f0, 0x6940($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X6940);
    // 0x800C6CD4: add.s       $f0, $f4, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f4.fl + ctx->f0.fl;
    // 0x800C6CD8: swc1        $f0, 0x8($s2)
    MEM_W(0X8, ctx->r18) = ctx->f0.u32l;
    // 0x800C6CDC: c.lt.s      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.fl < ctx->f0.fl;
L_800C6CE0:
    // 0x800C6CE0: nop

    // 0x800C6CE4: bc1tl       L_800C6CEC
    if (c1cs) {
        // 0x800C6CE8: swc1        $f6, 0x8($s2)
        MEM_W(0X8, ctx->r18) = ctx->f6.u32l;
            goto L_800C6CEC;
    }
    goto skip_6;
    // 0x800C6CE8: swc1        $f6, 0x8($s2)
    MEM_W(0X8, ctx->r18) = ctx->f6.u32l;
    skip_6:
L_800C6CEC:
    // 0x800C6CEC: lwc1        $f2, 0xC($s2)
    ctx->f2.u32l = MEM_W(ctx->r18, 0XC);
    // 0x800C6CF0: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800C6CF4: c.lt.s      $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f4.fl < ctx->f2.fl;
    // 0x800C6CF8: nop

    // 0x800C6CFC: bc1f        L_800C6D1C
    if (!c1cs) {
        // 0x800C6D00: nop
    
            goto L_800C6D1C;
    }
    // 0x800C6D00: nop

    // 0x800C6D04: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800C6D08: lwc1        $f0, 0x6944($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X6944);
    // 0x800C6D0C: sub.s       $f0, $f2, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f2.fl - ctx->f0.fl;
    // 0x800C6D10: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x800C6D14: j           L_800C6D30
    // 0x800C6D18: swc1        $f0, 0xC($s2)
    MEM_W(0XC, ctx->r18) = ctx->f0.u32l;
        goto L_800C6D30;
    // 0x800C6D18: swc1        $f0, 0xC($s2)
    MEM_W(0XC, ctx->r18) = ctx->f0.u32l;
L_800C6D1C:
    // 0x800C6D1C: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800C6D20: lwc1        $f0, 0x6948($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X6948);
    // 0x800C6D24: add.s       $f0, $f2, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x800C6D28: swc1        $f0, 0xC($s2)
    MEM_W(0XC, ctx->r18) = ctx->f0.u32l;
    // 0x800C6D2C: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
L_800C6D30:
    // 0x800C6D30: nop

    // 0x800C6D34: bc1tl       L_800C6D3C
    if (c1cs) {
        // 0x800C6D38: swc1        $f4, 0xC($s2)
        MEM_W(0XC, ctx->r18) = ctx->f4.u32l;
            goto L_800C6D3C;
    }
    goto skip_7;
    // 0x800C6D38: swc1        $f4, 0xC($s2)
    MEM_W(0XC, ctx->r18) = ctx->f4.u32l;
    skip_7:
L_800C6D3C:
    // 0x800C6D3C: lwc1        $f0, 0x14($s2)
    ctx->f0.u32l = MEM_W(ctx->r18, 0X14);
    // 0x800C6D40: lwc1        $f2, 0x0($s3)
    ctx->f2.u32l = MEM_W(ctx->r19, 0X0);
    // 0x800C6D44: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x800C6D48: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x800C6D4C: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x800C6D50: nop

    // 0x800C6D54: bc1f        L_800C6D68
    if (!c1cs) {
        // 0x800C6D58: swc1        $f0, 0x14($s2)
        MEM_W(0X14, ctx->r18) = ctx->f0.u32l;
            goto L_800C6D68;
    }
    // 0x800C6D58: swc1        $f0, 0x14($s2)
    MEM_W(0X14, ctx->r18) = ctx->f0.u32l;
    // 0x800C6D5C: j           L_800C6D68
    // 0x800C6D60: swc1        $f2, 0x14($s2)
    MEM_W(0X14, ctx->r18) = ctx->f2.u32l;
        goto L_800C6D68;
    // 0x800C6D60: swc1        $f2, 0x14($s2)
    MEM_W(0X14, ctx->r18) = ctx->f2.u32l;
L_800C6D64:
    // 0x800C6D64: sw          $zero, 0x14($s2)
    MEM_W(0X14, ctx->r18) = 0;
L_800C6D68:
    // 0x800C6D68: lwc1        $f0, 0x14($s2)
    ctx->f0.u32l = MEM_W(ctx->r18, 0X14);
    // 0x800C6D6C: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800C6D70: swc1        $f0, -0x5E00($v0)
    MEM_W(-0X5E00, ctx->r2) = ctx->f0.u32l;
    // 0x800C6D74: lw          $v1, 0x4($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X4);
    // 0x800C6D78: lwc1        $f0, 0x10($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X10);
    // 0x800C6D7C: sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3 << 1);
    // 0x800C6D80: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800C6D84: sll         $v1, $v0, 5
    ctx->r3 = S32(ctx->r2 << 5);
    // 0x800C6D88: subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // 0x800C6D8C: sll         $v1, $v1, 4
    ctx->r3 = S32(ctx->r3 << 4);
    // 0x800C6D90: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x800C6D94: addiu       $v0, $v0, -0x7D98
    ctx->r2 = ADD32(ctx->r2, -0X7D98);
    // 0x800C6D98: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x800C6D9C: swc1        $f0, 0x58($v1)
    MEM_W(0X58, ctx->r3) = ctx->f0.u32l;
    // 0x800C6DA0: lwc1        $f0, 0x68($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X68);
    // 0x800C6DA4: lwc1        $f2, 0x14($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X14);
    // 0x800C6DA8: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x800C6DAC: swc1        $f0, 0x5C($v1)
    MEM_W(0X5C, ctx->r3) = ctx->f0.u32l;
    // 0x800C6DB0: lwc1        $f0, 0x6C($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X6C);
    // 0x800C6DB4: lwc1        $f2, 0x18($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X18);
    // 0x800C6DB8: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x800C6DBC: addiu       $s1, $sp, 0x40
    ctx->r17 = ADD32(ctx->r29, 0X40);
    // 0x800C6DC0: swc1        $f0, 0x60($v1)
    MEM_W(0X60, ctx->r3) = ctx->f0.u32l;
    // 0x800C6DC4: lwc1        $f0, 0x8($s2)
    ctx->f0.u32l = MEM_W(ctx->r18, 0X8);
    // 0x800C6DC8: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x800C6DCC: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    // 0x800C6DD0: lwc1        $f0, 0xC($s2)
    ctx->f0.u32l = MEM_W(ctx->r18, 0XC);
    // 0x800C6DD4: addiu       $a1, $sp, 0x10
    ctx->r5 = ADD32(ctx->r29, 0X10);
    // 0x800C6DD8: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    // 0x800C6DDC: lwc1        $f0, 0x10($s2)
    ctx->f0.u32l = MEM_W(ctx->r18, 0X10);
    // 0x800C6DE0: addiu       $a2, $sp, 0x20
    ctx->r6 = ADD32(ctx->r29, 0X20);
    // 0x800C6DE4: jal         0x800193E8
    // 0x800C6DE8: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    func_800193E8(rdram, ctx);
        goto after_15;
    // 0x800C6DE8: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    after_15:
    // 0x800C6DEC: addiu       $s0, $sp, 0x70
    ctx->r16 = ADD32(ctx->r29, 0X70);
    // 0x800C6DF0: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x800C6DF4: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x800C6DF8: addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    // 0x800C6DFC: jal         0x8001CB64
    // 0x800C6E00: addu        $a3, $a1, $zero
    ctx->r7 = ADD32(ctx->r5, 0);
    func_8001CB64(rdram, ctx);
        goto after_16;
    // 0x800C6E00: addu        $a3, $a1, $zero
    ctx->r7 = ADD32(ctx->r5, 0);
    after_16:
    // 0x800C6E04: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x800C6E08: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x800C6E0C: jal         0x800191C4
    // 0x800C6E10: addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    func_800191C4(rdram, ctx);
        goto after_17;
    // 0x800C6E10: addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    after_17:
    // 0x800C6E14: lwc1        $f0, 0x20($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X20);
    // 0x800C6E18: lwc1        $f2, 0x24($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X24);
    // 0x800C6E1C: lwc1        $f4, 0x28($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X28);
    // 0x800C6E20: swc1        $f0, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f0.u32l;
    // 0x800C6E24: swc1        $f2, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f2.u32l;
    // 0x800C6E28: swc1        $f4, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->f4.u32l;
    // 0x800C6E2C: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x800C6E30: addiu       $v0, $v0, 0x28
    ctx->r2 = ADD32(ctx->r2, 0X28);
L_800C6E34:
    // 0x800C6E34: lw          $t1, 0x0($s1)
    ctx->r9 = MEM_W(ctx->r17, 0X0);
    // 0x800C6E38: lw          $t2, 0x4($s1)
    ctx->r10 = MEM_W(ctx->r17, 0X4);
    // 0x800C6E3C: lw          $t3, 0x8($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X8);
    // 0x800C6E40: lw          $t0, 0xC($s1)
    ctx->r8 = MEM_W(ctx->r17, 0XC);
    // 0x800C6E44: sw          $t1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r9;
    // 0x800C6E48: sw          $t2, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r10;
    // 0x800C6E4C: sw          $t3, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r11;
    // 0x800C6E50: sw          $t0, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r8;
    // 0x800C6E54: addiu       $s1, $s1, 0x10
    ctx->r17 = ADD32(ctx->r17, 0X10);
    // 0x800C6E58: bne         $s1, $s0, L_800C6E34
    if (ctx->r17 != ctx->r16) {
        // 0x800C6E5C: addiu       $v0, $v0, 0x10
        ctx->r2 = ADD32(ctx->r2, 0X10);
            goto L_800C6E34;
    }
    // 0x800C6E5C: addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
    // 0x800C6E60: lw          $a0, 0x4($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X4);
    // 0x800C6E64: jal         0x8006C940
    // 0x800C6E68: nop

    getPlayerVehicleId(rdram, ctx);
        goto after_18;
    // 0x800C6E68: nop

    after_18:
    // 0x800C6E6C: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // 0x800C6E70: lw          $a2, 0x0($s3)
    ctx->r6 = MEM_W(ctx->r19, 0X0);
    // 0x800C6E74: jal         0x800C65CC
    // 0x800C6E78: andi        $a1, $v0, 0xFF
    ctx->r5 = ctx->r2 & 0XFF;
    func_800C65CC(rdram, ctx);
        goto after_19;
    // 0x800C6E78: andi        $a1, $v0, 0xFF
    ctx->r5 = ctx->r2 & 0XFF;
    after_19:
    // 0x800C6E7C: j           L_800C6FD8
    // 0x800C6E80: nop

        goto L_800C6FD8;
    // 0x800C6E80: nop

L_800C6E84:
    // 0x800C6E84: lw          $a0, 0x4($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X4);
    // 0x800C6E88: addiu       $v1, $v1, -0x72E8
    ctx->r3 = ADD32(ctx->r3, -0X72E8);
    // 0x800C6E8C: sll         $a1, $a0, 2
    ctx->r5 = S32(ctx->r4 << 2);
    // 0x800C6E90: addu        $a2, $a1, $a0
    ctx->r6 = ADD32(ctx->r5, ctx->r4);
    // 0x800C6E94: sll         $v0, $a2, 4
    ctx->r2 = S32(ctx->r6 << 4);
    // 0x800C6E98: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x800C6E9C: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800C6EA0: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800C6EA4: lw          $v0, 0x4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X4);
    // 0x800C6EA8: lhu         $v0, 0x4($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X4);
    // 0x800C6EAC: bne         $v0, $a3, L_800C6FD8
    if (ctx->r2 != ctx->r7) {
        // 0x800C6EB0: addu        $s1, $s0, $zero
        ctx->r17 = ADD32(ctx->r16, 0);
            goto L_800C6FD8;
    }
    // 0x800C6EB0: addu        $s1, $s0, $zero
    ctx->r17 = ADD32(ctx->r16, 0);
    // 0x800C6EB4: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800C6EB8: addiu       $v0, $v0, 0xB40
    ctx->r2 = ADD32(ctx->r2, 0XB40);
    // 0x800C6EBC: addu        $v0, $a1, $v0
    ctx->r2 = ADD32(ctx->r5, ctx->r2);
    // 0x800C6EC0: lw          $v0, 0xC($v0)
    ctx->r2 = MEM_W(ctx->r2, 0XC);
    // 0x800C6EC4: andi        $v0, $v0, 0x10
    ctx->r2 = ctx->r2 & 0X10;
    // 0x800C6EC8: beq         $v0, $zero, L_800C6FD8
    if (ctx->r2 == 0) {
        // 0x800C6ECC: lui         $v0, 0x8013
        ctx->r2 = S32(0X8013 << 16);
            goto L_800C6FD8;
    }
    // 0x800C6ECC: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800C6ED0: addiu       $s0, $v0, 0x7DB8
    ctx->r16 = ADD32(ctx->r2, 0X7DB8);
    // 0x800C6ED4: sll         $v0, $a2, 2
    ctx->r2 = S32(ctx->r6 << 2);
    // 0x800C6ED8: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x800C6EDC: sll         $v0, $v0, 5
    ctx->r2 = S32(ctx->r2 << 5);
    // 0x800C6EE0: addu        $v0, $v0, $s0
    ctx->r2 = ADD32(ctx->r2, ctx->r16);
    // 0x800C6EE4: lhu         $v0, 0x184($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X184);
    // 0x800C6EE8: andi        $v0, $v0, 0x100
    ctx->r2 = ctx->r2 & 0X100;
    // 0x800C6EEC: bne         $v0, $zero, L_800C6FD8
    if (ctx->r2 != 0) {
        // 0x800C6EF0: nop
    
            goto L_800C6FD8;
    }
    // 0x800C6EF0: nop

    // 0x800C6EF4: lwc1        $f2, 0x14($s2)
    ctx->f2.u32l = MEM_W(ctx->r18, 0X14);
    // 0x800C6EF8: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800C6EFC: c.eq.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl == ctx->f0.fl;
    // 0x800C6F00: nop

    // 0x800C6F04: bc1f        L_800C6FD8
    if (!c1cs) {
        // 0x800C6F08: nop
    
            goto L_800C6FD8;
    }
    // 0x800C6F08: nop

    // 0x800C6F0C: jal         0x800FEECC
    // 0x800C6F10: nop

    func_800FEECC(rdram, ctx);
        goto after_20;
    // 0x800C6F10: nop

    after_20:
    // 0x800C6F14: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x800C6F18: beql        $v0, $zero, L_800C6F60
    if (ctx->r2 == 0) {
        // 0x800C6F1C: lui         $s0, 0x8011
        ctx->r16 = S32(0X8011 << 16);
            goto L_800C6F60;
    }
    goto skip_8;
    // 0x800C6F1C: lui         $s0, 0x8011
    ctx->r16 = S32(0X8011 << 16);
    skip_8:
    // 0x800C6F20: jal         0x800FEEF4
    // 0x800C6F24: nop

    getHudSecondaryWeponCount(rdram, ctx);
        goto after_21;
    // 0x800C6F24: nop

    after_21:
    // 0x800C6F28: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x800C6F2C: beql        $v0, $zero, L_800C6F60
    if (ctx->r2 == 0) {
        // 0x800C6F30: lui         $s0, 0x8011
        ctx->r16 = S32(0X8011 << 16);
            goto L_800C6F60;
    }
    goto skip_9;
    // 0x800C6F30: lui         $s0, 0x8011
    ctx->r16 = S32(0X8011 << 16);
    skip_9:
    // 0x800C6F34: lw          $v0, 0x4($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X4);
    // 0x800C6F38: sll         $v1, $v0, 2
    ctx->r3 = S32(ctx->r2 << 2);
    // 0x800C6F3C: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x800C6F40: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x800C6F44: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x800C6F48: sll         $v1, $v1, 5
    ctx->r3 = S32(ctx->r3 << 5);
    // 0x800C6F4C: addu        $v1, $v1, $s0
    ctx->r3 = ADD32(ctx->r3, ctx->r16);
    // 0x800C6F50: lhu         $v0, 0x184($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X184);
    // 0x800C6F54: andi        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 & 0X1;
    // 0x800C6F58: bne         $v0, $zero, L_800C6FD8
    if (ctx->r2 != 0) {
        // 0x800C6F5C: lui         $s0, 0x8011
        ctx->r16 = S32(0X8011 << 16);
            goto L_800C6FD8;
    }
    // 0x800C6F5C: lui         $s0, 0x8011
    ctx->r16 = S32(0X8011 << 16);
L_800C6F60:
    // 0x800C6F60: lw          $a0, 0x4($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X4);
    // 0x800C6F64: jal         0x8006C940
    // 0x800C6F68: addiu       $s0, $s0, -0x5E2C
    ctx->r16 = ADD32(ctx->r16, -0X5E2C);
    getPlayerVehicleId(rdram, ctx);
        goto after_22;
    // 0x800C6F68: addiu       $s0, $s0, -0x5E2C
    ctx->r16 = ADD32(ctx->r16, -0X5E2C);
    after_22:
    // 0x800C6F6C: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800C6F70: addu        $v0, $v0, $s0
    ctx->r2 = ADD32(ctx->r2, ctx->r16);
    // 0x800C6F74: lwc1        $f0, 0x0($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X0);
    // 0x800C6F78: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800C6F7C: lui         $s0, 0x8011
    ctx->r16 = S32(0X8011 << 16);
    // 0x800C6F80: lw          $a0, 0x4($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X4);
    // 0x800C6F84: addiu       $s0, $s0, -0x5E50
    ctx->r16 = ADD32(ctx->r16, -0X5E50);
    // 0x800C6F88: jal         0x8006C940
    // 0x800C6F8C: swc1        $f0, -0x5E04($v0)
    MEM_W(-0X5E04, ctx->r2) = ctx->f0.u32l;
    getPlayerVehicleId(rdram, ctx);
        goto after_23;
    // 0x800C6F8C: swc1        $f0, -0x5E04($v0)
    MEM_W(-0X5E04, ctx->r2) = ctx->f0.u32l;
    after_23:
    // 0x800C6F90: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800C6F94: addu        $v0, $v0, $s0
    ctx->r2 = ADD32(ctx->r2, ctx->r16);
    // 0x800C6F98: lwc1        $f0, 0x0($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X0);
    // 0x800C6F9C: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800C6FA0: swc1        $f0, -0x5E08($v0)
    MEM_W(-0X5E08, ctx->r2) = ctx->f0.u32l;
    // 0x800C6FA4: lw          $v0, 0xC($s1)
    ctx->r2 = MEM_W(ctx->r17, 0XC);
    // 0x800C6FA8: lw          $v1, 0x0($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X0);
    // 0x800C6FAC: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x800C6FB0: beq         $v0, $zero, L_800C6FC8
    if (ctx->r2 == 0) {
        // 0x800C6FB4: sw          $v0, 0xC($v1)
        MEM_W(0XC, ctx->r3) = ctx->r2;
            goto L_800C6FC8;
    }
    // 0x800C6FB4: sw          $v0, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r2;
    // 0x800C6FB8: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x800C6FBC: lw          $v1, 0xC($v0)
    ctx->r3 = MEM_W(ctx->r2, 0XC);
    // 0x800C6FC0: addiu       $v0, $v0, 0xC
    ctx->r2 = ADD32(ctx->r2, 0XC);
    // 0x800C6FC4: sw          $v0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r2;
L_800C6FC8:
    // 0x800C6FC8: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x800C6FCC: lw          $v1, 0xC($s1)
    ctx->r3 = MEM_W(ctx->r17, 0XC);
    // 0x800C6FD0: addiu       $v0, $v0, 0xC
    ctx->r2 = ADD32(ctx->r2, 0XC);
    // 0x800C6FD4: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
L_800C6FD8:
    // 0x800C6FD8: lw          $ra, 0xB0($sp)
    ctx->r31 = MEM_W(ctx->r29, 0XB0);
    // 0x800C6FDC: lw          $s3, 0xAC($sp)
    ctx->r19 = MEM_W(ctx->r29, 0XAC);
    // 0x800C6FE0: lw          $s2, 0xA8($sp)
    ctx->r18 = MEM_W(ctx->r29, 0XA8);
    // 0x800C6FE4: lw          $s1, 0xA4($sp)
    ctx->r17 = MEM_W(ctx->r29, 0XA4);
    // 0x800C6FE8: lw          $s0, 0xA0($sp)
    ctx->r16 = MEM_W(ctx->r29, 0XA0);
    // 0x800C6FEC: ldc1        $f20, 0xB8($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0XB8);
    // 0x800C6FF0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800C6FF4: jr          $ra
    // 0x800C6FF8: addiu       $sp, $sp, 0xC0
    ctx->r29 = ADD32(ctx->r29, 0XC0);
    return;
    // 0x800C6FF8: addiu       $sp, $sp, 0xC0
    ctx->r29 = ADD32(ctx->r29, 0XC0);
;}
RECOMP_FUNC void getLevelIntroCrawlId(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C6900: andi        $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 & 0XFF;
    // 0x800C6904: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
    // 0x800C6908: beq         $a0, $v0, L_800C6948
    if (ctx->r4 == ctx->r2) {
        // 0x800C690C: slti        $v0, $a0, 0x6
        ctx->r2 = SIGNED(ctx->r4) < 0X6 ? 1 : 0;
            goto L_800C6948;
    }
    // 0x800C690C: slti        $v0, $a0, 0x6
    ctx->r2 = SIGNED(ctx->r4) < 0X6 ? 1 : 0;
    // 0x800C6910: beq         $v0, $zero, L_800C6928
    if (ctx->r2 == 0) {
        // 0x800C6914: addiu       $v0, $zero, 0xA
        ctx->r2 = ADD32(0, 0XA);
            goto L_800C6928;
    }
    // 0x800C6914: addiu       $v0, $zero, 0xA
    ctx->r2 = ADD32(0, 0XA);
    // 0x800C6918: beq         $a0, $zero, L_800C6940
    if (ctx->r4 == 0) {
        // 0x800C691C: addiu       $v0, $zero, 0xFF
        ctx->r2 = ADD32(0, 0XFF);
            goto L_800C6940;
    }
    // 0x800C691C: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // 0x800C6920: j           L_800C6960
    // 0x800C6924: nop

        goto L_800C6960;
    // 0x800C6924: nop

L_800C6928:
    // 0x800C6928: beq         $a0, $v0, L_800C6950
    if (ctx->r4 == ctx->r2) {
        // 0x800C692C: addiu       $v0, $zero, 0xF
        ctx->r2 = ADD32(0, 0XF);
            goto L_800C6950;
    }
    // 0x800C692C: addiu       $v0, $zero, 0xF
    ctx->r2 = ADD32(0, 0XF);
    // 0x800C6930: beq         $a0, $v0, L_800C6958
    if (ctx->r4 == ctx->r2) {
        // 0x800C6934: addiu       $v0, $zero, 0xFF
        ctx->r2 = ADD32(0, 0XFF);
            goto L_800C6958;
    }
    // 0x800C6934: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // 0x800C6938: j           L_800C6960
    // 0x800C693C: nop

        goto L_800C6960;
    // 0x800C693C: nop

L_800C6940:
    // 0x800C6940: jr          $ra
    // 0x800C6944: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    return;
    // 0x800C6944: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_800C6948:
    // 0x800C6948: jr          $ra
    // 0x800C694C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x800C694C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800C6950:
    // 0x800C6950: jr          $ra
    // 0x800C6954: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    return;
    // 0x800C6954: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
L_800C6958:
    // 0x800C6958: jr          $ra
    // 0x800C695C: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    return;
    // 0x800C695C: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
L_800C6960:
    // 0x800C6960: jr          $ra
    // 0x800C6964: nop

    return;
    // 0x800C6964: nop

;}
RECOMP_FUNC void fake_func_800C6968(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
;}
RECOMP_FUNC void loadJfifAsset(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C6970: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x800C6974: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x800C6978: addu        $s5, $a0, $zero
    ctx->r21 = ADD32(ctx->r4, 0);
    // 0x800C697C: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x800C6980: addu        $s1, $a1, $zero
    ctx->r17 = ADD32(ctx->r5, 0);
    // 0x800C6984: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x800C6988: addu        $s3, $a2, $zero
    ctx->r19 = ADD32(ctx->r6, 0);
    // 0x800C698C: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x800C6990: addu        $s4, $a3, $zero
    ctx->r20 = ADD32(ctx->r7, 0);
    // 0x800C6994: addiu       $a0, $zero, 0x7F0
    ctx->r4 = ADD32(0, 0X7F0);
    // 0x800C6998: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x800C699C: sw          $ra, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r31;
    // 0x800C69A0: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x800C69A4: jal         0x80001ACC
    // 0x800C69A8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    rs_malloc(rdram, ctx);
        goto after_0;
    // 0x800C69A8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    after_0:
    // 0x800C69AC: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    // 0x800C69B0: beq         $s0, $zero, L_800C6BE8
    if (ctx->r16 == 0) {
        // 0x800C69B4: addu        $a0, $s0, $zero
        ctx->r4 = ADD32(ctx->r16, 0);
            goto L_800C6BE8;
    }
    // 0x800C69B4: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x800C69B8: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x800C69BC: jal         0x800078E0
    // 0x800C69C0: addiu       $a2, $zero, 0x7F0
    ctx->r6 = ADD32(0, 0X7F0);
    rs_memset(rdram, ctx);
        goto after_1;
    // 0x800C69C0: addiu       $a2, $zero, 0x7F0
    ctx->r6 = ADD32(0, 0X7F0);
    after_1:
    // 0x800C69C4: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x800C69C8: jal         0x800C6C40
    // 0x800C69CC: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    func_800C6C40(rdram, ctx);
        goto after_2;
    // 0x800C69CC: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    after_2:
    // 0x800C69D0: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // 0x800C69D4: andi        $v0, $v1, 0xFF
    ctx->r2 = ctx->r3 & 0XFF;
    // 0x800C69D8: bnel        $v0, $zero, L_800C6C18
    if (ctx->r2 != 0) {
        // 0x800C69DC: sb          $v1, 0x0($s3)
        MEM_B(0X0, ctx->r19) = ctx->r3;
            goto L_800C6C18;
    }
    goto skip_0;
    // 0x800C69DC: sb          $v1, 0x0($s3)
    MEM_B(0X0, ctx->r19) = ctx->r3;
    skip_0:
    // 0x800C69E0: lui         $s2, 0x8013
    ctx->r18 = S32(0X8013 << 16);
    // 0x800C69E4: lw          $a0, 0x7CFC($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X7CFC);
    // 0x800C69E8: jal         0x80004D5C
    // 0x800C69EC: addu        $a1, $s5, $zero
    ctx->r5 = ADD32(ctx->r21, 0);
    get_asset_size_extra(rdram, ctx);
        goto after_3;
    // 0x800C69EC: addu        $a1, $s5, $zero
    ctx->r5 = ADD32(ctx->r21, 0);
    after_3:
    // 0x800C69F0: addu        $s1, $v0, $zero
    ctx->r17 = ADD32(ctx->r2, 0);
    // 0x800C69F4: beq         $s1, $zero, L_800C6BF4
    if (ctx->r17 == 0) {
        // 0x800C69F8: addiu       $v0, $zero, -0x1
        ctx->r2 = ADD32(0, -0X1);
            goto L_800C6BF4;
    }
    // 0x800C69F8: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x800C69FC: beq         $s1, $v0, L_800C6BF8
    if (ctx->r17 == ctx->r2) {
        // 0x800C6A00: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_800C6BF8;
    }
    // 0x800C6A00: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800C6A04: lhu         $a1, 0xE($s0)
    ctx->r5 = MEM_HU(ctx->r16, 0XE);
    // 0x800C6A08: jal         0x80001ACC
    // 0x800C6A0C: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    rs_malloc(rdram, ctx);
        goto after_4;
    // 0x800C6A0C: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    after_4:
    // 0x800C6A10: beq         $v0, $zero, L_800C6BE8
    if (ctx->r2 == 0) {
        // 0x800C6A14: sw          $v0, 0x30($s0)
        MEM_W(0X30, ctx->r16) = ctx->r2;
            goto L_800C6BE8;
    }
    // 0x800C6A14: sw          $v0, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->r2;
    // 0x800C6A18: addu        $a0, $s4, $zero
    ctx->r4 = ADD32(ctx->r20, 0);
    // 0x800C6A1C: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x800C6A20: lw          $a2, 0x7CFC($s2)
    ctx->r6 = MEM_W(ctx->r18, 0X7CFC);
    // 0x800C6A24: addu        $a3, $s5, $zero
    ctx->r7 = ADD32(ctx->r21, 0);
    // 0x800C6A28: jal         0x80004AAC
    // 0x800C6A2C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    func_80004AAC(rdram, ctx);
        goto after_5;
    // 0x800C6A2C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_5:
    // 0x800C6A30: addu        $a0, $s4, $zero
    ctx->r4 = ADD32(ctx->r20, 0);
    // 0x800C6A34: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x800C6A38: addu        $s2, $v0, $zero
    ctx->r18 = ADD32(ctx->r2, 0);
    // 0x800C6A3C: addu        $a2, $s2, $zero
    ctx->r6 = ADD32(ctx->r18, 0);
    // 0x800C6A40: sw          $s1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r17;
    // 0x800C6A44: lw          $v0, 0x30($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X30);
    // 0x800C6A48: addu        $a3, $a1, $zero
    ctx->r7 = ADD32(ctx->r5, 0);
    // 0x800C6A4C: jal         0x80004E70
    // 0x800C6A50: sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    setupAssetDma(rdram, ctx);
        goto after_6;
    // 0x800C6A50: sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    after_6:
    // 0x800C6A54: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x800C6A58: bne         $v0, $zero, L_800C6C00
    if (ctx->r2 != 0) {
        // 0x800C6A5C: addiu       $v0, $zero, 0x2
        ctx->r2 = ADD32(0, 0X2);
            goto L_800C6C00;
    }
    // 0x800C6A5C: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x800C6A60: addu        $a0, $s4, $zero
    ctx->r4 = ADD32(ctx->r20, 0);
    // 0x800C6A64: jal         0x80004C70
    // 0x800C6A68: addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    teardownAssetDma(rdram, ctx);
        goto after_7;
    // 0x800C6A68: addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    after_7:
    // 0x800C6A6C: jal         0x800C9B8C
    // 0x800C6A70: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_800C9B8C(rdram, ctx);
        goto after_8;
    // 0x800C6A70: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_8:
    // 0x800C6A74: addu        $s2, $zero, $zero
    ctx->r18 = ADD32(0, 0);
    // 0x800C6A78: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x800C6A7C: addiu       $s4, $v0, 0x7770
    ctx->r20 = ADD32(ctx->r2, 0X7770);
    // 0x800C6A80: lw          $v0, 0x30($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X30);
    // 0x800C6A84: addiu       $s1, $zero, 0xB
    ctx->r17 = ADD32(0, 0XB);
    // 0x800C6A88: sw          $v0, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->r2;
L_800C6A8C:
    // 0x800C6A8C: lw          $v1, 0x34($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X34);
    // 0x800C6A90: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // 0x800C6A94: lbu         $a0, 0x0($v1)
    ctx->r4 = MEM_BU(ctx->r3, 0X0);
    // 0x800C6A98: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800C6A9C: bne         $a0, $v0, L_800C6C08
    if (ctx->r4 != ctx->r2) {
        // 0x800C6AA0: sw          $v1, 0x34($s0)
        MEM_W(0X34, ctx->r16) = ctx->r3;
            goto L_800C6C08;
    }
    // 0x800C6AA0: sw          $v1, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->r3;
    // 0x800C6AA4: lbu         $v0, 0x0($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X0);
    // 0x800C6AA8: bne         $v0, $a0, L_800C6ACC
    if (ctx->r2 != ctx->r4) {
        // 0x800C6AAC: nop
    
            goto L_800C6ACC;
    }
    // 0x800C6AAC: nop

    // 0x800C6AB0: addiu       $a0, $zero, 0xFF
    ctx->r4 = ADD32(0, 0XFF);
L_800C6AB4:
    // 0x800C6AB4: lw          $v0, 0x34($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X34);
    // 0x800C6AB8: addiu       $v1, $v0, 0x1
    ctx->r3 = ADD32(ctx->r2, 0X1);
    // 0x800C6ABC: sw          $v1, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->r3;
    // 0x800C6AC0: lbu         $v0, 0x1($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X1);
    // 0x800C6AC4: beq         $v0, $a0, L_800C6AB4
    if (ctx->r2 == ctx->r4) {
        // 0x800C6AC8: nop
    
            goto L_800C6AB4;
    }
    // 0x800C6AC8: nop

L_800C6ACC:
    // 0x800C6ACC: lw          $v0, 0x34($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X34);
    // 0x800C6AD0: lbu         $v1, 0x0($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X0);
    // 0x800C6AD4: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800C6AD8: sw          $v0, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->r2;
    // 0x800C6ADC: andi        $v0, $v1, 0xFF
    ctx->r2 = ctx->r3 & 0XFF;
    // 0x800C6AE0: addiu       $v1, $v0, -0xC0
    ctx->r3 = ADD32(ctx->r2, -0XC0);
    // 0x800C6AE4: sltiu       $v0, $v1, 0x3F
    ctx->r2 = ctx->r3 < 0X3F ? 1 : 0;
    // 0x800C6AE8: beq         $v0, $zero, L_800C6BCC
    if (ctx->r2 == 0) {
        // 0x800C6AEC: sll         $v0, $v1, 2
        ctx->r2 = S32(ctx->r3 << 2);
            goto L_800C6BCC;
    }
    // 0x800C6AEC: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x800C6AF0: addu        $v0, $v0, $s4
    gpr jr_addend_800C6AF8 = ctx->r2;
    ctx->r2 = ADD32(ctx->r2, ctx->r20);
    // 0x800C6AF4: lw          $v0, 0x0($v0)
    ctx->r2 = ADD32(ctx->r2, 0X0);
    // 0x800C6AF8: jr          $v0
    // 0x800C6AFC: nop

    switch (jr_addend_800C6AF8 >> 2) {
        case 0: goto L_800C6B1C; break;
        case 1: goto L_800C6B10; break;
        case 2: goto L_800C6B10; break;
        case 3: goto L_800C6B10; break;
        case 4: goto L_800C6B3C; break;
        case 5: goto L_800C6B10; break;
        case 6: goto L_800C6B10; break;
        case 7: goto L_800C6B10; break;
        case 8: goto L_800C6B10; break;
        case 9: goto L_800C6B10; break;
        case 10: goto L_800C6B10; break;
        case 11: goto L_800C6B10; break;
        case 12: goto L_800C6BCC; break;
        case 13: goto L_800C6B10; break;
        case 14: goto L_800C6B10; break;
        case 15: goto L_800C6B10; break;
        case 16: goto L_800C6BCC; break;
        case 17: goto L_800C6BCC; break;
        case 18: goto L_800C6BCC; break;
        case 19: goto L_800C6BCC; break;
        case 20: goto L_800C6BCC; break;
        case 21: goto L_800C6BCC; break;
        case 22: goto L_800C6BCC; break;
        case 23: goto L_800C6BCC; break;
        case 24: goto L_800C6B00; break;
        case 25: goto L_800C6BCC; break;
        case 26: goto L_800C6B5C; break;
        case 27: goto L_800C6B2C; break;
        case 28: goto L_800C6BCC; break;
        case 29: goto L_800C6BCC; break;
        case 30: goto L_800C6BCC; break;
        case 31: goto L_800C6BCC; break;
        case 32: goto L_800C6BCC; break;
        case 33: goto L_800C6BCC; break;
        case 34: goto L_800C6BCC; break;
        case 35: goto L_800C6BCC; break;
        case 36: goto L_800C6BCC; break;
        case 37: goto L_800C6BCC; break;
        case 38: goto L_800C6BCC; break;
        case 39: goto L_800C6BCC; break;
        case 40: goto L_800C6BCC; break;
        case 41: goto L_800C6BCC; break;
        case 42: goto L_800C6BCC; break;
        case 43: goto L_800C6BCC; break;
        case 44: goto L_800C6BCC; break;
        case 45: goto L_800C6BCC; break;
        case 46: goto L_800C6BCC; break;
        case 47: goto L_800C6BCC; break;
        case 48: goto L_800C6BCC; break;
        case 49: goto L_800C6BCC; break;
        case 50: goto L_800C6BCC; break;
        case 51: goto L_800C6BCC; break;
        case 52: goto L_800C6BCC; break;
        case 53: goto L_800C6BCC; break;
        case 54: goto L_800C6BCC; break;
        case 55: goto L_800C6BCC; break;
        case 56: goto L_800C6BCC; break;
        case 57: goto L_800C6BCC; break;
        case 58: goto L_800C6BCC; break;
        case 59: goto L_800C6BCC; break;
        case 60: goto L_800C6BCC; break;
        case 61: goto L_800C6BCC; break;
        case 62: goto L_800C6B80; break;
        default: switch_error(__func__, 0x800C6AF8, 0x800A7770);
    }
    // 0x800C6AFC: nop

L_800C6B00:
    // 0x800C6B00: jal         0x800C6F24
    // 0x800C6B04: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    parseJfifSOIMarker(rdram, ctx);
        goto after_9;
    // 0x800C6B04: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_9:
    // 0x800C6B08: j           L_800C6B48
    // 0x800C6B0C: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
        goto L_800C6B48;
    // 0x800C6B0C: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
L_800C6B10:
    // 0x800C6B10: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
    // 0x800C6B14: j           L_800C6C18
    // 0x800C6B18: sb          $v0, 0x0($s3)
    MEM_B(0X0, ctx->r19) = ctx->r2;
        goto L_800C6C18;
    // 0x800C6B18: sb          $v0, 0x0($s3)
    MEM_B(0X0, ctx->r19) = ctx->r2;
L_800C6B1C:
    // 0x800C6B1C: jal         0x800C7070
    // 0x800C6B20: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    parseJfifSOF0Marker(rdram, ctx);
        goto after_10;
    // 0x800C6B20: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_10:
    // 0x800C6B24: j           L_800C6B48
    // 0x800C6B28: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
        goto L_800C6B48;
    // 0x800C6B28: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
L_800C6B2C:
    // 0x800C6B2C: jal         0x800C73E4
    // 0x800C6B30: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    parseJfifDQTMarker(rdram, ctx);
        goto after_11;
    // 0x800C6B30: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_11:
    // 0x800C6B34: j           L_800C6B48
    // 0x800C6B38: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
        goto L_800C6B48;
    // 0x800C6B38: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
L_800C6B3C:
    // 0x800C6B3C: jal         0x800C7534
    // 0x800C6B40: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    parseJfifDHTMarker(rdram, ctx);
        goto after_12;
    // 0x800C6B40: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_12:
    // 0x800C6B44: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
L_800C6B48:
    // 0x800C6B48: andi        $v0, $v1, 0xFF
    ctx->r2 = ctx->r3 & 0XFF;
    // 0x800C6B4C: bne         $v0, $zero, L_800C6C14
    if (ctx->r2 != 0) {
        // 0x800C6B50: andi        $v0, $s2, 0xFF
        ctx->r2 = ctx->r18 & 0XFF;
            goto L_800C6C14;
    }
    // 0x800C6B50: andi        $v0, $s2, 0xFF
    ctx->r2 = ctx->r18 & 0XFF;
    // 0x800C6B54: j           L_800C6BD8
    // 0x800C6B58: nop

        goto L_800C6BD8;
    // 0x800C6B58: nop

L_800C6B5C:
    // 0x800C6B5C: jal         0x800C76B8
    // 0x800C6B60: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    paserJfifSOSMarker(rdram, ctx);
        goto after_13;
    // 0x800C6B60: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_13:
    // 0x800C6B64: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // 0x800C6B68: andi        $v0, $v1, 0xFF
    ctx->r2 = ctx->r3 & 0XFF;
    // 0x800C6B6C: bne         $v0, $zero, L_800C6C14
    if (ctx->r2 != 0) {
        // 0x800C6B70: addiu       $s2, $zero, 0x1
        ctx->r18 = ADD32(0, 0X1);
            goto L_800C6C14;
    }
    // 0x800C6B70: addiu       $s2, $zero, 0x1
    ctx->r18 = ADD32(0, 0X1);
    // 0x800C6B74: lw          $v0, 0x34($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X34);
    // 0x800C6B78: j           L_800C6BD4
    // 0x800C6B7C: sw          $v0, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->r2;
        goto L_800C6BD4;
    // 0x800C6B7C: sw          $v0, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->r2;
L_800C6B80:
    // 0x800C6B80: lw          $v0, 0x34($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X34);
    // 0x800C6B84: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x800C6B88: lbu         $v1, 0x0($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X0);
    // 0x800C6B8C: lbu         $a0, 0x1($v0)
    ctx->r4 = MEM_BU(ctx->r2, 0X1);
    // 0x800C6B90: addiu       $v0, $v0, 0x2
    ctx->r2 = ADD32(ctx->r2, 0X2);
    // 0x800C6B94: sll         $v1, $v1, 8
    ctx->r3 = S32(ctx->r3 << 8);
    // 0x800C6B98: or          $a0, $a0, $v1
    ctx->r4 = ctx->r4 | ctx->r3;
    // 0x800C6B9C: addiu       $a0, $a0, -0x2
    ctx->r4 = ADD32(ctx->r4, -0X2);
    // 0x800C6BA0: beq         $a0, $zero, L_800C6BD4
    if (ctx->r4 == 0) {
        // 0x800C6BA4: sw          $v0, 0x34($s0)
        MEM_W(0X34, ctx->r16) = ctx->r2;
            goto L_800C6BD4;
    }
    // 0x800C6BA4: sw          $v0, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->r2;
L_800C6BA8:
    // 0x800C6BA8: lw          $v0, 0x34($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X34);
    // 0x800C6BAC: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x800C6BB0: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800C6BB4: sw          $v0, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->r2;
    // 0x800C6BB8: sltu        $v0, $a1, $a0
    ctx->r2 = ctx->r5 < ctx->r4 ? 1 : 0;
    // 0x800C6BBC: bne         $v0, $zero, L_800C6BA8
    if (ctx->r2 != 0) {
        // 0x800C6BC0: andi        $v0, $s2, 0xFF
        ctx->r2 = ctx->r18 & 0XFF;
            goto L_800C6BA8;
    }
    // 0x800C6BC0: andi        $v0, $s2, 0xFF
    ctx->r2 = ctx->r18 & 0XFF;
    // 0x800C6BC4: j           L_800C6BD8
    // 0x800C6BC8: nop

        goto L_800C6BD8;
    // 0x800C6BC8: nop

L_800C6BCC:
    // 0x800C6BCC: j           L_800C6C18
    // 0x800C6BD0: sb          $s1, 0x0($s3)
    MEM_B(0X0, ctx->r19) = ctx->r17;
        goto L_800C6C18;
    // 0x800C6BD0: sb          $s1, 0x0($s3)
    MEM_B(0X0, ctx->r19) = ctx->r17;
L_800C6BD4:
    // 0x800C6BD4: andi        $v0, $s2, 0xFF
    ctx->r2 = ctx->r18 & 0XFF;
L_800C6BD8:
    // 0x800C6BD8: beq         $v0, $zero, L_800C6A8C
    if (ctx->r2 == 0) {
        // 0x800C6BDC: addu        $v0, $s0, $zero
        ctx->r2 = ADD32(ctx->r16, 0);
            goto L_800C6A8C;
    }
    // 0x800C6BDC: addu        $v0, $s0, $zero
    ctx->r2 = ADD32(ctx->r16, 0);
    // 0x800C6BE0: j           L_800C6C1C
    // 0x800C6BE4: sb          $zero, 0x0($s3)
    MEM_B(0X0, ctx->r19) = 0;
        goto L_800C6C1C;
    // 0x800C6BE4: sb          $zero, 0x0($s3)
    MEM_B(0X0, ctx->r19) = 0;
L_800C6BE8:
    // 0x800C6BE8: addiu       $v0, $zero, 0x6
    ctx->r2 = ADD32(0, 0X6);
    // 0x800C6BEC: j           L_800C6C18
    // 0x800C6BF0: sb          $v0, 0x0($s3)
    MEM_B(0X0, ctx->r19) = ctx->r2;
        goto L_800C6C18;
    // 0x800C6BF0: sb          $v0, 0x0($s3)
    MEM_B(0X0, ctx->r19) = ctx->r2;
L_800C6BF4:
    // 0x800C6BF4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800C6BF8:
    // 0x800C6BF8: j           L_800C6C18
    // 0x800C6BFC: sb          $v0, 0x0($s3)
    MEM_B(0X0, ctx->r19) = ctx->r2;
        goto L_800C6C18;
    // 0x800C6BFC: sb          $v0, 0x0($s3)
    MEM_B(0X0, ctx->r19) = ctx->r2;
L_800C6C00:
    // 0x800C6C00: j           L_800C6C18
    // 0x800C6C04: sb          $v0, 0x0($s3)
    MEM_B(0X0, ctx->r19) = ctx->r2;
        goto L_800C6C18;
    // 0x800C6C04: sb          $v0, 0x0($s3)
    MEM_B(0X0, ctx->r19) = ctx->r2;
L_800C6C08:
    // 0x800C6C08: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x800C6C0C: j           L_800C6C18
    // 0x800C6C10: sb          $v0, 0x0($s3)
    MEM_B(0X0, ctx->r19) = ctx->r2;
        goto L_800C6C18;
    // 0x800C6C10: sb          $v0, 0x0($s3)
    MEM_B(0X0, ctx->r19) = ctx->r2;
L_800C6C14:
    // 0x800C6C14: sb          $v1, 0x0($s3)
    MEM_B(0X0, ctx->r19) = ctx->r3;
L_800C6C18:
    // 0x800C6C18: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_800C6C1C:
    // 0x800C6C1C: lw          $ra, 0x30($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X30);
    // 0x800C6C20: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x800C6C24: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x800C6C28: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x800C6C2C: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x800C6C30: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x800C6C34: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800C6C38: jr          $ra
    // 0x800C6C3C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x800C6C3C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_800C6C40(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C6C40: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800C6C44: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x800C6C48: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x800C6C4C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C6C50: jal         0x80018EF4
    // 0x800C6C54: addiu       $a2, $zero, 0x30
    ctx->r6 = ADD32(0, 0X30);
    zmemcpy(rdram, ctx);
        goto after_0;
    // 0x800C6C54: addiu       $a2, $zero, 0x30
    ctx->r6 = ADD32(0, 0X30);
    after_0:
    // 0x800C6C58: lhu         $v0, 0x4($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X4);
    // 0x800C6C5C: andi        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 & 0X1;
    // 0x800C6C60: beq         $v0, $zero, L_800C6C80
    if (ctx->r2 == 0) {
        // 0x800C6C64: nop
    
            goto L_800C6C80;
    }
    // 0x800C6C64: nop

    // 0x800C6C68: lhu         $v0, 0x10($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X10);
    // 0x800C6C6C: addiu       $v0, $v0, 0x100
    ctx->r2 = ADD32(ctx->r2, 0X100);
    // 0x800C6C70: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x800C6C74: sltiu       $v0, $v0, 0x201
    ctx->r2 = ctx->r2 < 0X201 ? 1 : 0;
    // 0x800C6C78: beq         $v0, $zero, L_800C6DAC
    if (ctx->r2 == 0) {
        // 0x800C6C7C: addiu       $v0, $zero, 0x12
        ctx->r2 = ADD32(0, 0X12);
            goto L_800C6DAC;
    }
    // 0x800C6C7C: addiu       $v0, $zero, 0x12
    ctx->r2 = ADD32(0, 0X12);
L_800C6C80:
    // 0x800C6C80: lhu         $v0, 0x4($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X4);
    // 0x800C6C84: andi        $v0, $v0, 0x2
    ctx->r2 = ctx->r2 & 0X2;
    // 0x800C6C88: beq         $v0, $zero, L_800C6CA8
    if (ctx->r2 == 0) {
        // 0x800C6C8C: nop
    
            goto L_800C6CA8;
    }
    // 0x800C6C8C: nop

    // 0x800C6C90: lhu         $v0, 0x12($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X12);
    // 0x800C6C94: addiu       $v0, $v0, 0x100
    ctx->r2 = ADD32(ctx->r2, 0X100);
    // 0x800C6C98: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x800C6C9C: sltiu       $v0, $v0, 0x201
    ctx->r2 = ctx->r2 < 0X201 ? 1 : 0;
    // 0x800C6CA0: beq         $v0, $zero, L_800C6DAC
    if (ctx->r2 == 0) {
        // 0x800C6CA4: addiu       $v0, $zero, 0x12
        ctx->r2 = ADD32(0, 0X12);
            goto L_800C6DAC;
    }
    // 0x800C6CA4: addiu       $v0, $zero, 0x12
    ctx->r2 = ADD32(0, 0X12);
L_800C6CA8:
    // 0x800C6CA8: lhu         $v0, 0x4($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X4);
    // 0x800C6CAC: andi        $v0, $v0, 0x4
    ctx->r2 = ctx->r2 & 0X4;
    // 0x800C6CB0: beq         $v0, $zero, L_800C6CD0
    if (ctx->r2 == 0) {
        // 0x800C6CB4: nop
    
            goto L_800C6CD0;
    }
    // 0x800C6CB4: nop

    // 0x800C6CB8: lhu         $v0, 0x14($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X14);
    // 0x800C6CBC: addiu       $v0, $v0, 0x100
    ctx->r2 = ADD32(ctx->r2, 0X100);
    // 0x800C6CC0: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x800C6CC4: sltiu       $v0, $v0, 0x201
    ctx->r2 = ctx->r2 < 0X201 ? 1 : 0;
    // 0x800C6CC8: beq         $v0, $zero, L_800C6DAC
    if (ctx->r2 == 0) {
        // 0x800C6CCC: addiu       $v0, $zero, 0x12
        ctx->r2 = ADD32(0, 0X12);
            goto L_800C6DAC;
    }
    // 0x800C6CCC: addiu       $v0, $zero, 0x12
    ctx->r2 = ADD32(0, 0X12);
L_800C6CD0:
    // 0x800C6CD0: lw          $v1, 0xC($s0)
    ctx->r3 = MEM_W(ctx->r16, 0XC);
    // 0x800C6CD4: beq         $v1, $zero, L_800C6CE4
    if (ctx->r3 == 0) {
        // 0x800C6CD8: addiu       $v0, $zero, 0x4
        ctx->r2 = ADD32(0, 0X4);
            goto L_800C6CE4;
    }
    // 0x800C6CD8: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // 0x800C6CDC: bne         $v1, $v0, L_800C6DAC
    if (ctx->r3 != ctx->r2) {
        // 0x800C6CE0: addiu       $v0, $zero, 0x12
        ctx->r2 = ADD32(0, 0X12);
            goto L_800C6DAC;
    }
    // 0x800C6CE0: addiu       $v0, $zero, 0x12
    ctx->r2 = ADD32(0, 0X12);
L_800C6CE4:
    // 0x800C6CE4: lw          $a0, 0x50($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X50);
    // 0x800C6CE8: beq         $a0, $zero, L_800C6CF8
    if (ctx->r4 == 0) {
        // 0x800C6CEC: addiu       $a0, $a0, -0x100
        ctx->r4 = ADD32(ctx->r4, -0X100);
            goto L_800C6CF8;
    }
    // 0x800C6CEC: addiu       $a0, $a0, -0x100
    ctx->r4 = ADD32(ctx->r4, -0X100);
    // 0x800C6CF0: jal         0x80001C98
    // 0x800C6CF4: sw          $a0, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->r4;
    rs_free(rdram, ctx);
        goto after_1;
    // 0x800C6CF4: sw          $a0, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->r4;
    after_1:
L_800C6CF8:
    // 0x800C6CF8: lw          $a0, 0x54($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X54);
    // 0x800C6CFC: beq         $a0, $zero, L_800C6D0C
    if (ctx->r4 == 0) {
        // 0x800C6D00: addiu       $a0, $a0, -0x100
        ctx->r4 = ADD32(ctx->r4, -0X100);
            goto L_800C6D0C;
    }
    // 0x800C6D00: addiu       $a0, $a0, -0x100
    ctx->r4 = ADD32(ctx->r4, -0X100);
    // 0x800C6D04: jal         0x80001C98
    // 0x800C6D08: sw          $a0, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->r4;
    rs_free(rdram, ctx);
        goto after_2;
    // 0x800C6D08: sw          $a0, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->r4;
    after_2:
L_800C6D0C:
    // 0x800C6D0C: jal         0x800C9A88
    // 0x800C6D10: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_800C9A88(rdram, ctx);
        goto after_3;
    // 0x800C6D10: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_3:
    // 0x800C6D14: lw          $a0, 0x7D8($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X7D8);
    // 0x800C6D18: beq         $a0, $zero, L_800C6D28
    if (ctx->r4 == 0) {
        // 0x800C6D1C: nop
    
            goto L_800C6D28;
    }
    // 0x800C6D1C: nop

    // 0x800C6D20: jal         0x80001C98
    // 0x800C6D24: nop

    rs_free(rdram, ctx);
        goto after_4;
    // 0x800C6D24: nop

    after_4:
L_800C6D28:
    // 0x800C6D28: lw          $a0, 0x7DC($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X7DC);
    // 0x800C6D2C: beq         $a0, $zero, L_800C6D3C
    if (ctx->r4 == 0) {
        // 0x800C6D30: nop
    
            goto L_800C6D3C;
    }
    // 0x800C6D30: nop

    // 0x800C6D34: jal         0x80001C98
    // 0x800C6D38: nop

    rs_free(rdram, ctx);
        goto after_5;
    // 0x800C6D38: nop

    after_5:
L_800C6D3C:
    // 0x800C6D3C: lw          $a0, 0x7E0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X7E0);
    // 0x800C6D40: beq         $a0, $zero, L_800C6D50
    if (ctx->r4 == 0) {
        // 0x800C6D44: nop
    
            goto L_800C6D50;
    }
    // 0x800C6D44: nop

    // 0x800C6D48: jal         0x80001C98
    // 0x800C6D4C: nop

    rs_free(rdram, ctx);
        goto after_6;
    // 0x800C6D4C: nop

    after_6:
L_800C6D50:
    // 0x800C6D50: lw          $a0, 0x7E4($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X7E4);
    // 0x800C6D54: beq         $a0, $zero, L_800C6D64
    if (ctx->r4 == 0) {
        // 0x800C6D58: nop
    
            goto L_800C6D64;
    }
    // 0x800C6D58: nop

    // 0x800C6D5C: jal         0x80001C98
    // 0x800C6D60: nop

    rs_free(rdram, ctx);
        goto after_7;
    // 0x800C6D60: nop

    after_7:
L_800C6D64:
    // 0x800C6D64: jal         0x800C8A64
    // 0x800C6D68: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_800C8A64(rdram, ctx);
        goto after_8;
    // 0x800C6D68: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_8:
    // 0x800C6D6C: lw          $v0, 0x8($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X8);
    // 0x800C6D70: addiu       $v0, $v0, -0x2
    ctx->r2 = ADD32(ctx->r2, -0X2);
    // 0x800C6D74: sltiu       $v0, $v0, 0x4
    ctx->r2 = ctx->r2 < 0X4 ? 1 : 0;
    // 0x800C6D78: beq         $v0, $zero, L_800C6DA8
    if (ctx->r2 == 0) {
        // 0x800C6D7C: addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
            goto L_800C6DA8;
    }
    // 0x800C6D7C: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // 0x800C6D80: lw          $v1, 0x38($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X38);
    // 0x800C6D84: sh          $zero, 0x46($s0)
    MEM_H(0X46, ctx->r16) = 0;
    // 0x800C6D88: sh          $zero, 0x7EC($s0)
    MEM_H(0X7EC, ctx->r16) = 0;
    // 0x800C6D8C: sh          $zero, 0x7EE($s0)
    MEM_H(0X7EE, ctx->r16) = 0;
    // 0x800C6D90: sh          $zero, 0x7D2($s0)
    MEM_H(0X7D2, ctx->r16) = 0;
    // 0x800C6D94: sh          $zero, 0x7E8($s0)
    MEM_H(0X7E8, ctx->r16) = 0;
    // 0x800C6D98: sh          $zero, 0x7EA($s0)
    MEM_H(0X7EA, ctx->r16) = 0;
    // 0x800C6D9C: sb          $zero, 0x4D($s0)
    MEM_B(0X4D, ctx->r16) = 0;
    // 0x800C6DA0: j           L_800C6DAC
    // 0x800C6DA4: sw          $v1, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->r3;
        goto L_800C6DAC;
    // 0x800C6DA4: sw          $v1, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->r3;
L_800C6DA8:
    // 0x800C6DA8: addiu       $v0, $zero, 0x16
    ctx->r2 = ADD32(0, 0X16);
L_800C6DAC:
    // 0x800C6DAC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800C6DB0: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x800C6DB4: jr          $ra
    // 0x800C6DB8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x800C6DB8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_800C6DBC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C6DBC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800C6DC0: sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // 0x800C6DC4: addu        $s2, $a0, $zero
    ctx->r18 = ADD32(ctx->r4, 0);
    // 0x800C6DC8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800C6DCC: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x800C6DD0: beq         $s2, $zero, L_800C6F04
    if (ctx->r18 == 0) {
        // 0x800C6DD4: sw          $s0, 0x10($sp)
        MEM_W(0X10, ctx->r29) = ctx->r16;
            goto L_800C6F04;
    }
    // 0x800C6DD4: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x800C6DD8: addu        $s1, $zero, $zero
    ctx->r17 = ADD32(0, 0);
L_800C6DDC:
    // 0x800C6DDC: lbu         $v0, 0x48($s2)
    ctx->r2 = MEM_BU(ctx->r18, 0X48);
    // 0x800C6DE0: andi        $v1, $s1, 0xFF
    ctx->r3 = ctx->r17 & 0XFF;
    // 0x800C6DE4: srav        $v0, $v0, $v1
    ctx->r2 = S32(SIGNED(ctx->r2) >> (ctx->r3 & 31));
    // 0x800C6DE8: andi        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 & 0X1;
    // 0x800C6DEC: beq         $v0, $zero, L_800C6E20
    if (ctx->r2 == 0) {
        // 0x800C6DF0: sll         $s0, $v1, 2
        ctx->r16 = S32(ctx->r3 << 2);
            goto L_800C6E20;
    }
    // 0x800C6DF0: sll         $s0, $v1, 2
    ctx->r16 = S32(ctx->r3 << 2);
    // 0x800C6DF4: addu        $s0, $s0, $v1
    ctx->r16 = ADD32(ctx->r16, ctx->r3);
    // 0x800C6DF8: sll         $s0, $s0, 2
    ctx->r16 = S32(ctx->r16 << 2);
    // 0x800C6DFC: addu        $s0, $s0, $v1
    ctx->r16 = ADD32(ctx->r16, ctx->r3);
    // 0x800C6E00: sll         $s0, $s0, 3
    ctx->r16 = S32(ctx->r16 << 3);
    // 0x800C6E04: addu        $s0, $s2, $s0
    ctx->r16 = ADD32(ctx->r18, ctx->r16);
    // 0x800C6E08: lw          $a0, 0x5C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X5C);
    // 0x800C6E0C: jal         0x80001C98
    // 0x800C6E10: nop

    rs_free(rdram, ctx);
        goto after_0;
    // 0x800C6E10: nop

    after_0:
    // 0x800C6E14: lw          $a0, 0x60($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X60);
    // 0x800C6E18: jal         0x80001C98
    // 0x800C6E1C: nop

    rs_free(rdram, ctx);
        goto after_1;
    // 0x800C6E1C: nop

    after_1:
L_800C6E20:
    // 0x800C6E20: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x800C6E24: andi        $v0, $s1, 0xFF
    ctx->r2 = ctx->r17 & 0XFF;
    // 0x800C6E28: sltiu       $v0, $v0, 0x4
    ctx->r2 = ctx->r2 < 0X4 ? 1 : 0;
    // 0x800C6E2C: bne         $v0, $zero, L_800C6DDC
    if (ctx->r2 != 0) {
        // 0x800C6E30: nop
    
            goto L_800C6DDC;
    }
    // 0x800C6E30: nop

    // 0x800C6E34: addu        $s1, $zero, $zero
    ctx->r17 = ADD32(0, 0);
    // 0x800C6E38: andi        $v1, $s1, 0xFF
    ctx->r3 = ctx->r17 & 0XFF;
L_800C6E3C:
    // 0x800C6E3C: sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3 << 1);
    // 0x800C6E40: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800C6E44: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800C6E48: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x800C6E4C: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800C6E50: addu        $v0, $s2, $v0
    ctx->r2 = ADD32(ctx->r18, ctx->r2);
    // 0x800C6E54: lw          $a0, 0x708($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X708);
    // 0x800C6E58: beq         $a0, $zero, L_800C6E68
    if (ctx->r4 == 0) {
        // 0x800C6E5C: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_800C6E68;
    }
    // 0x800C6E5C: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x800C6E60: jal         0x80001C98
    // 0x800C6E64: nop

    rs_free(rdram, ctx);
        goto after_2;
    // 0x800C6E64: nop

    after_2:
L_800C6E68:
    // 0x800C6E68: andi        $v0, $s1, 0xFF
    ctx->r2 = ctx->r17 & 0XFF;
    // 0x800C6E6C: sltiu       $v0, $v0, 0x3
    ctx->r2 = ctx->r2 < 0X3 ? 1 : 0;
    // 0x800C6E70: bne         $v0, $zero, L_800C6E3C
    if (ctx->r2 != 0) {
        // 0x800C6E74: andi        $v1, $s1, 0xFF
        ctx->r3 = ctx->r17 & 0XFF;
            goto L_800C6E3C;
    }
    // 0x800C6E74: andi        $v1, $s1, 0xFF
    ctx->r3 = ctx->r17 & 0XFF;
    // 0x800C6E78: lw          $a0, 0x77C($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X77C);
    // 0x800C6E7C: beq         $a0, $zero, L_800C6E8C
    if (ctx->r4 == 0) {
        // 0x800C6E80: nop
    
            goto L_800C6E8C;
    }
    // 0x800C6E80: nop

    // 0x800C6E84: jal         0x80001C98
    // 0x800C6E88: nop

    rs_free(rdram, ctx);
        goto after_3;
    // 0x800C6E88: nop

    after_3:
L_800C6E8C:
    // 0x800C6E8C: lw          $a0, 0x50($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X50);
    // 0x800C6E90: beq         $a0, $zero, L_800C6EA0
    if (ctx->r4 == 0) {
        // 0x800C6E94: addiu       $a0, $a0, -0x100
        ctx->r4 = ADD32(ctx->r4, -0X100);
            goto L_800C6EA0;
    }
    // 0x800C6E94: addiu       $a0, $a0, -0x100
    ctx->r4 = ADD32(ctx->r4, -0X100);
    // 0x800C6E98: jal         0x80001C98
    // 0x800C6E9C: sw          $a0, 0x50($s2)
    MEM_W(0X50, ctx->r18) = ctx->r4;
    rs_free(rdram, ctx);
        goto after_4;
    // 0x800C6E9C: sw          $a0, 0x50($s2)
    MEM_W(0X50, ctx->r18) = ctx->r4;
    after_4:
L_800C6EA0:
    // 0x800C6EA0: lw          $a0, 0x7D8($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X7D8);
    // 0x800C6EA4: beq         $a0, $zero, L_800C6EB4
    if (ctx->r4 == 0) {
        // 0x800C6EA8: nop
    
            goto L_800C6EB4;
    }
    // 0x800C6EA8: nop

    // 0x800C6EAC: jal         0x80001C98
    // 0x800C6EB0: nop

    rs_free(rdram, ctx);
        goto after_5;
    // 0x800C6EB0: nop

    after_5:
L_800C6EB4:
    // 0x800C6EB4: lw          $a0, 0x7DC($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X7DC);
    // 0x800C6EB8: beq         $a0, $zero, L_800C6EC8
    if (ctx->r4 == 0) {
        // 0x800C6EBC: nop
    
            goto L_800C6EC8;
    }
    // 0x800C6EBC: nop

    // 0x800C6EC0: jal         0x80001C98
    // 0x800C6EC4: nop

    rs_free(rdram, ctx);
        goto after_6;
    // 0x800C6EC4: nop

    after_6:
L_800C6EC8:
    // 0x800C6EC8: lw          $a0, 0x7E0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X7E0);
    // 0x800C6ECC: beq         $a0, $zero, L_800C6EDC
    if (ctx->r4 == 0) {
        // 0x800C6ED0: nop
    
            goto L_800C6EDC;
    }
    // 0x800C6ED0: nop

    // 0x800C6ED4: jal         0x80001C98
    // 0x800C6ED8: nop

    rs_free(rdram, ctx);
        goto after_7;
    // 0x800C6ED8: nop

    after_7:
L_800C6EDC:
    // 0x800C6EDC: lw          $a0, 0x7E4($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X7E4);
    // 0x800C6EE0: beq         $a0, $zero, L_800C6EF0
    if (ctx->r4 == 0) {
        // 0x800C6EE4: nop
    
            goto L_800C6EF0;
    }
    // 0x800C6EE4: nop

    // 0x800C6EE8: jal         0x80001C98
    // 0x800C6EEC: nop

    rs_free(rdram, ctx);
        goto after_8;
    // 0x800C6EEC: nop

    after_8:
L_800C6EF0:
    // 0x800C6EF0: lw          $a0, 0x30($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X30);
    // 0x800C6EF4: beq         $a0, $zero, L_800C6F04
    if (ctx->r4 == 0) {
        // 0x800C6EF8: nop
    
            goto L_800C6F04;
    }
    // 0x800C6EF8: nop

    // 0x800C6EFC: jal         0x80001C98
    // 0x800C6F00: nop

    rs_free(rdram, ctx);
        goto after_9;
    // 0x800C6F00: nop

    after_9:
L_800C6F04:
    // 0x800C6F04: jal         0x80001C98
    // 0x800C6F08: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    rs_free(rdram, ctx);
        goto after_10;
    // 0x800C6F08: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    after_10:
    // 0x800C6F0C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800C6F10: lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X18);
    // 0x800C6F14: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x800C6F18: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x800C6F1C: jr          $ra
    // 0x800C6F20: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x800C6F20: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void parseJfifSOIMarker(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C6F24: addiu       $sp, $sp, -0x10
    ctx->r29 = ADD32(ctx->r29, -0X10);
    // 0x800C6F28: addu        $a3, $a0, $zero
    ctx->r7 = ADD32(ctx->r4, 0);
    // 0x800C6F2C: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // 0x800C6F30: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // 0x800C6F34: sb          $v0, 0x0($sp)
    MEM_B(0X0, ctx->r29) = ctx->r2;
    // 0x800C6F38: addiu       $v0, $zero, 0xE0
    ctx->r2 = ADD32(0, 0XE0);
    // 0x800C6F3C: sb          $v0, 0x1($sp)
    MEM_B(0X1, ctx->r29) = ctx->r2;
    // 0x800C6F40: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x800C6F44: addiu       $t5, $v0, 0x786C
    ctx->r13 = ADD32(ctx->r2, 0X786C);
    // 0x800C6F48: lwl         $t2, 0x0($t5)
    ctx->r10 = do_lwl(rdram, ctx->r10, ctx->r13, 0X0);
    // 0x800C6F4C: lwr         $t2, 0x3($t5)
    ctx->r10 = do_lwr(rdram, ctx->r10, ctx->r13, 0X3);
    // 0x800C6F50: lb          $t3, 0x4($t5)
    ctx->r11 = MEM_B(ctx->r13, 0X4);
    // 0x800C6F54: swl         $t2, 0x8($sp)
    do_swl(rdram, 0X8, ctx->r29, ctx->r10);
    // 0x800C6F58: swr         $t2, 0xB($sp)
    do_swr(rdram, 0XB, ctx->r29, ctx->r10);
    // 0x800C6F5C: sb          $t3, 0xC($sp)
    MEM_B(0XC, ctx->r29) = ctx->r11;
    // 0x800C6F60: addu        $v0, $sp, $a2
    ctx->r2 = ADD32(ctx->r29, ctx->r6);
L_800C6F64:
    // 0x800C6F64: lw          $a1, 0x34($a3)
    ctx->r5 = MEM_W(ctx->r7, 0X34);
    // 0x800C6F68: lbu         $v0, 0x0($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X0);
    // 0x800C6F6C: lbu         $v1, 0x0($a1)
    ctx->r3 = MEM_BU(ctx->r5, 0X0);
    // 0x800C6F70: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x800C6F74: bne         $v1, $v0, L_800C704C
    if (ctx->r3 != ctx->r2) {
        // 0x800C6F78: sw          $a1, 0x34($a3)
        MEM_W(0X34, ctx->r7) = ctx->r5;
            goto L_800C704C;
    }
    // 0x800C6F78: sw          $a1, 0x34($a3)
    MEM_W(0X34, ctx->r7) = ctx->r5;
    // 0x800C6F7C: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x800C6F80: sltiu       $v0, $a2, 0x2
    ctx->r2 = ctx->r6 < 0X2 ? 1 : 0;
    // 0x800C6F84: bne         $v0, $zero, L_800C6F64
    if (ctx->r2 != 0) {
        // 0x800C6F88: addu        $v0, $sp, $a2
        ctx->r2 = ADD32(ctx->r29, ctx->r6);
            goto L_800C6F64;
    }
    // 0x800C6F88: addu        $v0, $sp, $a2
    ctx->r2 = ADD32(ctx->r29, ctx->r6);
    // 0x800C6F8C: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // 0x800C6F90: addiu       $t0, $sp, 0x8
    ctx->r8 = ADD32(ctx->r29, 0X8);
    // 0x800C6F94: lbu         $v0, 0x0($a1)
    ctx->r2 = MEM_BU(ctx->r5, 0X0);
    // 0x800C6F98: lbu         $a0, 0x1($a1)
    ctx->r4 = MEM_BU(ctx->r5, 0X1);
    // 0x800C6F9C: addiu       $v1, $a1, 0x2
    ctx->r3 = ADD32(ctx->r5, 0X2);
    // 0x800C6FA0: sw          $v1, 0x34($a3)
    MEM_W(0X34, ctx->r7) = ctx->r3;
    // 0x800C6FA4: sll         $v0, $v0, 8
    ctx->r2 = S32(ctx->r2 << 8);
    // 0x800C6FA8: or          $t1, $a0, $v0
    ctx->r9 = ctx->r4 | ctx->r2;
    // 0x800C6FAC: addu        $v0, $t0, $a2
    ctx->r2 = ADD32(ctx->r8, ctx->r6);
L_800C6FB0:
    // 0x800C6FB0: lw          $a1, 0x34($a3)
    ctx->r5 = MEM_W(ctx->r7, 0X34);
    // 0x800C6FB4: lbu         $v0, 0x0($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X0);
    // 0x800C6FB8: lbu         $v1, 0x0($a1)
    ctx->r3 = MEM_BU(ctx->r5, 0X0);
    // 0x800C6FBC: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x800C6FC0: bne         $v1, $v0, L_800C704C
    if (ctx->r3 != ctx->r2) {
        // 0x800C6FC4: sw          $a1, 0x34($a3)
        MEM_W(0X34, ctx->r7) = ctx->r5;
            goto L_800C704C;
    }
    // 0x800C6FC4: sw          $a1, 0x34($a3)
    MEM_W(0X34, ctx->r7) = ctx->r5;
    // 0x800C6FC8: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x800C6FCC: sltiu       $v0, $a2, 0x5
    ctx->r2 = ctx->r6 < 0X5 ? 1 : 0;
    // 0x800C6FD0: bne         $v0, $zero, L_800C6FB0
    if (ctx->r2 != 0) {
        // 0x800C6FD4: addu        $v0, $t0, $a2
        ctx->r2 = ADD32(ctx->r8, ctx->r6);
            goto L_800C6FB0;
    }
    // 0x800C6FD4: addu        $v0, $t0, $a2
    ctx->r2 = ADD32(ctx->r8, ctx->r6);
    // 0x800C6FD8: lbu         $v1, 0x0($a1)
    ctx->r3 = MEM_BU(ctx->r5, 0X0);
    // 0x800C6FDC: lbu         $a0, 0x1($a1)
    ctx->r4 = MEM_BU(ctx->r5, 0X1);
    // 0x800C6FE0: addiu       $v0, $a1, 0x2
    ctx->r2 = ADD32(ctx->r5, 0X2);
    // 0x800C6FE4: sw          $v0, 0x34($a3)
    MEM_W(0X34, ctx->r7) = ctx->r2;
    // 0x800C6FE8: addiu       $v0, $zero, 0x101
    ctx->r2 = ADD32(0, 0X101);
    // 0x800C6FEC: sll         $v1, $v1, 8
    ctx->r3 = S32(ctx->r3 << 8);
    // 0x800C6FF0: or          $a0, $a0, $v1
    ctx->r4 = ctx->r4 | ctx->r3;
    // 0x800C6FF4: bne         $a0, $v0, L_800C7068
    if (ctx->r4 != ctx->r2) {
        // 0x800C6FF8: addiu       $v0, $zero, 0x4
        ctx->r2 = ADD32(0, 0X4);
            goto L_800C7068;
    }
    // 0x800C6FF8: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // 0x800C6FFC: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
L_800C7000:
    // 0x800C7000: lw          $a0, 0x34($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X34);
    // 0x800C7004: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x800C7008: addiu       $v0, $a0, 0x1
    ctx->r2 = ADD32(ctx->r4, 0X1);
    // 0x800C700C: sw          $v0, 0x34($a3)
    MEM_W(0X34, ctx->r7) = ctx->r2;
    // 0x800C7010: sltiu       $v0, $a2, 0x5
    ctx->r2 = ctx->r6 < 0X5 ? 1 : 0;
    // 0x800C7014: bne         $v0, $zero, L_800C7000
    if (ctx->r2 != 0) {
        // 0x800C7018: addiu       $v0, $a0, 0x2
        ctx->r2 = ADD32(ctx->r4, 0X2);
            goto L_800C7000;
    }
    // 0x800C7018: addiu       $v0, $a0, 0x2
    ctx->r2 = ADD32(ctx->r4, 0X2);
    // 0x800C701C: lbu         $v1, 0x1($a0)
    ctx->r3 = MEM_BU(ctx->r4, 0X1);
    // 0x800C7020: sw          $v0, 0x34($a3)
    MEM_W(0X34, ctx->r7) = ctx->r2;
    // 0x800C7024: lbu         $v0, 0x2($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X2);
    // 0x800C7028: addiu       $a0, $a0, 0x3
    ctx->r4 = ADD32(ctx->r4, 0X3);
    // 0x800C702C: andi        $v1, $v1, 0xFF
    ctx->r3 = ctx->r3 & 0XFF;
    // 0x800C7030: bne         $v1, $zero, L_800C7044
    if (ctx->r3 != 0) {
        // 0x800C7034: sw          $a0, 0x34($a3)
        MEM_W(0X34, ctx->r7) = ctx->r4;
            goto L_800C7044;
    }
    // 0x800C7034: sw          $a0, 0x34($a3)
    MEM_W(0X34, ctx->r7) = ctx->r4;
    // 0x800C7038: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x800C703C: beq         $v0, $zero, L_800C7054
    if (ctx->r2 == 0) {
        // 0x800C7040: addiu       $v1, $t1, 0x4
        ctx->r3 = ADD32(ctx->r9, 0X4);
            goto L_800C7054;
    }
    // 0x800C7040: addiu       $v1, $t1, 0x4
    ctx->r3 = ADD32(ctx->r9, 0X4);
L_800C7044:
    // 0x800C7044: j           L_800C7068
    // 0x800C7048: addiu       $v0, $zero, 0x7
    ctx->r2 = ADD32(0, 0X7);
        goto L_800C7068;
    // 0x800C7048: addiu       $v0, $zero, 0x7
    ctx->r2 = ADD32(0, 0X7);
L_800C704C:
    // 0x800C704C: j           L_800C7068
    // 0x800C7050: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
        goto L_800C7068;
    // 0x800C7050: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
L_800C7054:
    // 0x800C7054: lw          $v0, 0x30($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X30);
    // 0x800C7058: subu        $v0, $a0, $v0
    ctx->r2 = SUB32(ctx->r4, ctx->r2);
    // 0x800C705C: xor         $v0, $v0, $v1
    ctx->r2 = ctx->r2 ^ ctx->r3;
    // 0x800C7060: sltu        $v0, $zero, $v0
    ctx->r2 = 0 < ctx->r2 ? 1 : 0;
    // 0x800C7064: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
L_800C7068:
    // 0x800C7068: jr          $ra
    // 0x800C706C: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
    return;
    // 0x800C706C: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
;}
RECOMP_FUNC void func_800C6FFC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C6FFC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800C7000: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x800C7004: addu        $s1, $a0, $zero
    ctx->r17 = ADD32(ctx->r4, 0);
    // 0x800C7008: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800C700C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800C7010: sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // 0x800C7014: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x800C7018: lw          $v1, 0xB8($s1)
    ctx->r3 = MEM_W(ctx->r17, 0XB8);
    // 0x800C701C: addiu       $a0, $a0, 0x7DB8
    ctx->r4 = ADD32(ctx->r4, 0X7DB8);
    // 0x800C7020: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x800C7024: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800C7028: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800C702C: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800C7030: sll         $v0, $v0, 5
    ctx->r2 = S32(ctx->r2 << 5);
    // 0x800C7034: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x800C7038: lhu         $a0, 0x292($v0)
    ctx->r4 = MEM_HU(ctx->r2, 0X292);
    // 0x800C703C: jal         0x8004013C
    // 0x800C7040: addu        $s2, $a1, $zero
    ctx->r18 = ADD32(ctx->r5, 0);
    func_8004013C(rdram, ctx);
        goto after_0;
    // 0x800C7040: addu        $s2, $a1, $zero
    ctx->r18 = ADD32(ctx->r5, 0);
    after_0:
    // 0x800C7044: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // 0x800C7048: lw          $s0, 0x4($v0)
    ctx->r16 = MEM_W(ctx->r2, 0X4);
    // 0x800C704C: jal         0x8001CFE8
    // 0x800C7050: addiu       $a1, $s1, 0x10
    ctx->r5 = ADD32(ctx->r17, 0X10);
    func_8001CFE8(rdram, ctx);
        goto after_1;
    // 0x800C7050: addiu       $a1, $s1, 0x10
    ctx->r5 = ADD32(ctx->r17, 0X10);
    after_1:
    // 0x800C7054: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x800C7058: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x800C705C: nop

    // 0x800C7060: bc1f        L_800C707C
    if (!c1cs) {
        // 0x800C7064: nop
    
            goto L_800C707C;
    }
    // 0x800C7064: nop

    // 0x800C7068: lwc1        $f0, 0x8($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X8);
    // 0x800C706C: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800C7070: lwc1        $f2, 0x694C($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X694C);
    // 0x800C7074: j           L_800C708C
    // 0x800C7078: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
        goto L_800C708C;
    // 0x800C7078: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
L_800C707C:
    // 0x800C707C: lwc1        $f0, 0x8($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X8);
    // 0x800C7080: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800C7084: lwc1        $f2, 0x6950($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X6950);
    // 0x800C7088: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
L_800C708C:
    // 0x800C708C: swc1        $f0, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f0.u32l;
    // 0x800C7090: lwc1        $f4, 0x4($s2)
    ctx->f4.u32l = MEM_W(ctx->r18, 0X4);
    // 0x800C7094: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x800C7098: c.lt.s      $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f2.fl < ctx->f4.fl;
    // 0x800C709C: nop

    // 0x800C70A0: bc1f        L_800C70BC
    if (!c1cs) {
        // 0x800C70A4: nop
    
            goto L_800C70BC;
    }
    // 0x800C70A4: nop

    // 0x800C70A8: lwc1        $f0, 0x20($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X20);
    // 0x800C70AC: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x800C70B0: nop

    // 0x800C70B4: bc1t        L_800C70E0
    if (c1cs) {
        // 0x800C70B8: nop
    
            goto L_800C70E0;
    }
    // 0x800C70B8: nop

L_800C70BC:
    // 0x800C70BC: c.lt.s      $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f4.fl < ctx->f2.fl;
    // 0x800C70C0: nop

    // 0x800C70C4: bc1f        L_800C70F4
    if (!c1cs) {
        // 0x800C70C8: nop
    
            goto L_800C70F4;
    }
    // 0x800C70C8: nop

    // 0x800C70CC: lwc1        $f0, 0x20($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X20);
    // 0x800C70D0: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x800C70D4: nop

    // 0x800C70D8: bc1f        L_800C70F4
    if (!c1cs) {
        // 0x800C70DC: nop
    
            goto L_800C70F4;
    }
    // 0x800C70DC: nop

L_800C70E0:
    // 0x800C70E0: lwc1        $f0, 0xC($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0XC);
    // 0x800C70E4: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800C70E8: lwc1        $f2, 0x6954($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X6954);
    // 0x800C70EC: j           L_800C7104
    // 0x800C70F0: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
        goto L_800C7104;
    // 0x800C70F0: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
L_800C70F4:
    // 0x800C70F4: lwc1        $f0, 0xC($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0XC);
    // 0x800C70F8: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800C70FC: lwc1        $f2, 0x6958($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X6958);
    // 0x800C7100: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
L_800C7104:
    // 0x800C7104: swc1        $f0, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f0.u32l;
    // 0x800C7108: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800C710C: lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X18);
    // 0x800C7110: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x800C7114: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x800C7118: jr          $ra
    // 0x800C711C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x800C711C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void parseJfifSOF0Marker(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C7070: addu        $t0, $a0, $zero
    ctx->r8 = ADD32(ctx->r4, 0);
    // 0x800C7074: lw          $a0, 0x34($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X34);
    // 0x800C7078: addiu       $v0, $a0, 0x2
    ctx->r2 = ADD32(ctx->r4, 0X2);
    // 0x800C707C: addiu       $a1, $a0, 0x3
    ctx->r5 = ADD32(ctx->r4, 0X3);
    // 0x800C7080: sw          $v0, 0x34($t0)
    MEM_W(0X34, ctx->r8) = ctx->r2;
    // 0x800C7084: lbu         $v1, 0x2($a0)
    ctx->r3 = MEM_BU(ctx->r4, 0X2);
    // 0x800C7088: addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
    // 0x800C708C: andi        $v1, $v1, 0xFF
    ctx->r3 = ctx->r3 & 0XFF;
    // 0x800C7090: beq         $v1, $v0, L_800C70A0
    if (ctx->r3 == ctx->r2) {
        // 0x800C7094: sw          $a1, 0x34($t0)
        MEM_W(0X34, ctx->r8) = ctx->r5;
            goto L_800C70A0;
    }
    // 0x800C7094: sw          $a1, 0x34($t0)
    MEM_W(0X34, ctx->r8) = ctx->r5;
    // 0x800C7098: jr          $ra
    // 0x800C709C: addiu       $v0, $zero, 0xA
    ctx->r2 = ADD32(0, 0XA);
    return;
    // 0x800C709C: addiu       $v0, $zero, 0xA
    ctx->r2 = ADD32(0, 0XA);
L_800C70A0:
    // 0x800C70A0: lbu         $v1, 0x3($a0)
    ctx->r3 = MEM_BU(ctx->r4, 0X3);
    // 0x800C70A4: lbu         $v0, 0x1($a1)
    ctx->r2 = MEM_BU(ctx->r5, 0X1);
    // 0x800C70A8: lw          $a0, 0x34($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X34);
    // 0x800C70AC: sll         $v1, $v1, 8
    ctx->r3 = S32(ctx->r3 << 8);
    // 0x800C70B0: or          $v0, $v0, $v1
    ctx->r2 = ctx->r2 | ctx->r3;
    // 0x800C70B4: addiu       $v1, $a0, 0x2
    ctx->r3 = ADD32(ctx->r4, 0X2);
    // 0x800C70B8: sh          $v0, 0x3E($t0)
    MEM_H(0X3E, ctx->r8) = ctx->r2;
    // 0x800C70BC: sw          $v1, 0x34($t0)
    MEM_W(0X34, ctx->r8) = ctx->r3;
    // 0x800C70C0: lbu         $v0, 0x2($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X2);
    // 0x800C70C4: lbu         $v1, 0x1($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X1);
    // 0x800C70C8: sll         $v0, $v0, 8
    ctx->r2 = S32(ctx->r2 << 8);
    // 0x800C70CC: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x800C70D0: lw          $v0, 0x34($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X34);
    // 0x800C70D4: sh          $v1, 0x3C($t0)
    MEM_H(0X3C, ctx->r8) = ctx->r3;
    // 0x800C70D8: lhu         $v1, 0x4($t0)
    ctx->r3 = MEM_HU(ctx->r8, 0X4);
    // 0x800C70DC: addiu       $v0, $v0, 0x2
    ctx->r2 = ADD32(ctx->r2, 0X2);
    // 0x800C70E0: andi        $v1, $v1, 0x40
    ctx->r3 = ctx->r3 & 0X40;
    // 0x800C70E4: bne         $v1, $zero, L_800C713C
    if (ctx->r3 != 0) {
        // 0x800C70E8: sw          $v0, 0x34($t0)
        MEM_W(0X34, ctx->r8) = ctx->r2;
            goto L_800C713C;
    }
    // 0x800C70E8: sw          $v0, 0x34($t0)
    MEM_W(0X34, ctx->r8) = ctx->r2;
    // 0x800C70EC: lhu         $v0, 0x3C($t0)
    ctx->r2 = MEM_HU(ctx->r8, 0X3C);
    // 0x800C70F0: lhu         $v1, 0x0($t0)
    ctx->r3 = MEM_HU(ctx->r8, 0X0);
    // 0x800C70F4: divu        $zero, $v0, $v1
    lo = S32(U32(ctx->r2) / U32(ctx->r3)); hi = S32(U32(ctx->r2) % U32(ctx->r3));
    // 0x800C70F8: bne         $v1, $zero, L_800C7104
    if (ctx->r3 != 0) {
        // 0x800C70FC: nop
    
            goto L_800C7104;
    }
    // 0x800C70FC: nop

    // 0x800C7100: break       7
    do_break(2148299008);
L_800C7104:
    // 0x800C7104: mfhi        $v1
    ctx->r3 = hi;
    // 0x800C7108: bne         $v1, $zero, L_800C7134
    if (ctx->r3 != 0) {
        // 0x800C710C: nop
    
            goto L_800C7134;
    }
    // 0x800C710C: nop

    // 0x800C7110: lhu         $v0, 0x3E($t0)
    ctx->r2 = MEM_HU(ctx->r8, 0X3E);
    // 0x800C7114: lhu         $v1, 0x2($t0)
    ctx->r3 = MEM_HU(ctx->r8, 0X2);
    // 0x800C7118: divu        $zero, $v0, $v1
    lo = S32(U32(ctx->r2) / U32(ctx->r3)); hi = S32(U32(ctx->r2) % U32(ctx->r3));
    // 0x800C711C: bne         $v1, $zero, L_800C7128
    if (ctx->r3 != 0) {
        // 0x800C7120: nop
    
            goto L_800C7128;
    }
    // 0x800C7120: nop

    // 0x800C7124: break       7
    do_break(2148299044);
L_800C7128:
    // 0x800C7128: mfhi        $v1
    ctx->r3 = hi;
    // 0x800C712C: beq         $v1, $zero, L_800C713C
    if (ctx->r3 == 0) {
        // 0x800C7130: nop
    
            goto L_800C713C;
    }
    // 0x800C7130: nop

L_800C7134:
    // 0x800C7134: jr          $ra
    // 0x800C7138: addiu       $v0, $zero, 0x15
    ctx->r2 = ADD32(0, 0X15);
    return;
    // 0x800C7138: addiu       $v0, $zero, 0x15
    ctx->r2 = ADD32(0, 0X15);
L_800C713C:
    // 0x800C713C: lw          $v0, 0x34($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X34);
    // 0x800C7140: lbu         $v1, 0x0($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X0);
    // 0x800C7144: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800C7148: sw          $v0, 0x34($t0)
    MEM_W(0X34, ctx->r8) = ctx->r2;
    // 0x800C714C: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x800C7150: sb          $v1, 0x4C($t0)
    MEM_B(0X4C, ctx->r8) = ctx->r3;
    // 0x800C7154: andi        $v1, $v1, 0xFF
    ctx->r3 = ctx->r3 & 0XFF;
    // 0x800C7158: beq         $v1, $v0, L_800C7178
    if (ctx->r3 == ctx->r2) {
        // 0x800C715C: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_800C7178;
    }
    // 0x800C715C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800C7160: beq         $v1, $v0, L_800C7178
    if (ctx->r3 == ctx->r2) {
        // 0x800C7164: addiu       $v0, $zero, 0xC
        ctx->r2 = ADD32(0, 0XC);
            goto L_800C7178;
    }
    // 0x800C7164: addiu       $v0, $zero, 0xC
    ctx->r2 = ADD32(0, 0XC);
    // 0x800C7168: jr          $ra
    // 0x800C716C: nop

    return;
    // 0x800C716C: nop

L_800C7170:
    // 0x800C7170: jr          $ra
    // 0x800C7174: addiu       $v0, $zero, 0x13
    ctx->r2 = ADD32(0, 0X13);
    return;
    // 0x800C7174: addiu       $v0, $zero, 0x13
    ctx->r2 = ADD32(0, 0X13);
L_800C7178:
    // 0x800C7178: lbu         $v0, 0x4C($t0)
    ctx->r2 = MEM_BU(ctx->r8, 0X4C);
    // 0x800C717C: beq         $v0, $zero, L_800C720C
    if (ctx->r2 == 0) {
        // 0x800C7180: addu        $a3, $zero, $zero
        ctx->r7 = ADD32(0, 0);
            goto L_800C720C;
    }
    // 0x800C7180: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    // 0x800C7184: andi        $v1, $a3, 0xFF
    ctx->r3 = ctx->r7 & 0XFF;
L_800C7188:
    // 0x800C7188: sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3 << 1);
    // 0x800C718C: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800C7190: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800C7194: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x800C7198: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800C719C: lw          $a1, 0x34($t0)
    ctx->r5 = MEM_W(ctx->r8, 0X34);
    // 0x800C71A0: addu        $a2, $t0, $v0
    ctx->r6 = ADD32(ctx->r8, ctx->r2);
    // 0x800C71A4: lbu         $a0, 0x0($a1)
    ctx->r4 = MEM_BU(ctx->r5, 0X0);
    // 0x800C71A8: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x800C71AC: sb          $a0, 0x6F8($a2)
    MEM_B(0X6F8, ctx->r6) = ctx->r4;
    // 0x800C71B0: sw          $a1, 0x34($t0)
    MEM_W(0X34, ctx->r8) = ctx->r5;
    // 0x800C71B4: lbu         $v0, 0x6F8($a2)
    ctx->r2 = MEM_BU(ctx->r6, 0X6F8);
    // 0x800C71B8: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800C71BC: bne         $v0, $v1, L_800C7170
    if (ctx->r2 != ctx->r3) {
        // 0x800C71C0: addiu       $v0, $a1, 0x1
        ctx->r2 = ADD32(ctx->r5, 0X1);
            goto L_800C7170;
    }
    // 0x800C71C0: addiu       $v0, $a1, 0x1
    ctx->r2 = ADD32(ctx->r5, 0X1);
    // 0x800C71C4: lbu         $v1, 0x0($a1)
    ctx->r3 = MEM_BU(ctx->r5, 0X0);
    // 0x800C71C8: sw          $v0, 0x34($t0)
    MEM_W(0X34, ctx->r8) = ctx->r2;
    // 0x800C71CC: andi        $v0, $v1, 0xFF
    ctx->r2 = ctx->r3 & 0XFF;
    // 0x800C71D0: srl         $v0, $v0, 4
    ctx->r2 = S32(U32(ctx->r2) >> 4);
    // 0x800C71D4: sb          $v0, 0x6F9($a2)
    MEM_B(0X6F9, ctx->r6) = ctx->r2;
    // 0x800C71D8: andi        $v0, $v1, 0xF
    ctx->r2 = ctx->r3 & 0XF;
    // 0x800C71DC: sb          $v0, 0x6FA($a2)
    MEM_B(0X6FA, ctx->r6) = ctx->r2;
    // 0x800C71E0: lw          $v0, 0x34($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X34);
    // 0x800C71E4: lbu         $v1, 0x0($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X0);
    // 0x800C71E8: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x800C71EC: sb          $v1, 0x6FB($a2)
    MEM_B(0X6FB, ctx->r6) = ctx->r3;
    // 0x800C71F0: lbu         $v1, 0x4C($t0)
    ctx->r3 = MEM_BU(ctx->r8, 0X4C);
    // 0x800C71F4: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800C71F8: sw          $v0, 0x34($t0)
    MEM_W(0X34, ctx->r8) = ctx->r2;
    // 0x800C71FC: andi        $v0, $a3, 0xFF
    ctx->r2 = ctx->r7 & 0XFF;
    // 0x800C7200: sltu        $v0, $v0, $v1
    ctx->r2 = ctx->r2 < ctx->r3 ? 1 : 0;
    // 0x800C7204: bne         $v0, $zero, L_800C7188
    if (ctx->r2 != 0) {
        // 0x800C7208: andi        $v1, $a3, 0xFF
        ctx->r3 = ctx->r7 & 0XFF;
            goto L_800C7188;
    }
    // 0x800C7208: andi        $v1, $a3, 0xFF
    ctx->r3 = ctx->r7 & 0XFF;
L_800C720C:
    // 0x800C720C: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    // 0x800C7210: lbu         $v1, 0x4C($t0)
    ctx->r3 = MEM_BU(ctx->r8, 0X4C);
    // 0x800C7214: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800C7218: sb          $v0, 0x4A($t0)
    MEM_B(0X4A, ctx->r8) = ctx->r2;
    // 0x800C721C: beq         $v1, $zero, L_800C7288
    if (ctx->r3 == 0) {
        // 0x800C7220: sb          $v0, 0x4B($t0)
        MEM_B(0X4B, ctx->r8) = ctx->r2;
            goto L_800C7288;
    }
    // 0x800C7220: sb          $v0, 0x4B($t0)
    MEM_B(0X4B, ctx->r8) = ctx->r2;
    // 0x800C7224: addu        $a2, $v1, $zero
    ctx->r6 = ADD32(ctx->r3, 0);
L_800C7228:
    // 0x800C7228: andi        $v0, $a3, 0xFF
    ctx->r2 = ctx->r7 & 0XFF;
    // 0x800C722C: sll         $v1, $v0, 1
    ctx->r3 = S32(ctx->r2 << 1);
    // 0x800C7230: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x800C7234: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x800C7238: subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // 0x800C723C: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x800C7240: addiu       $v1, $v1, 0x6F8
    ctx->r3 = ADD32(ctx->r3, 0X6F8);
    // 0x800C7244: addu        $a1, $t0, $v1
    ctx->r5 = ADD32(ctx->r8, ctx->r3);
    // 0x800C7248: lbu         $v1, 0x1($a1)
    ctx->r3 = MEM_BU(ctx->r5, 0X1);
    // 0x800C724C: lbu         $a0, 0x4A($t0)
    ctx->r4 = MEM_BU(ctx->r8, 0X4A);
    // 0x800C7250: sltu        $v0, $v1, $a0
    ctx->r2 = ctx->r3 < ctx->r4 ? 1 : 0;
    // 0x800C7254: bnel        $v0, $zero, L_800C725C
    if (ctx->r2 != 0) {
        // 0x800C7258: addu        $v1, $a0, $zero
        ctx->r3 = ADD32(ctx->r4, 0);
            goto L_800C725C;
    }
    goto skip_0;
    // 0x800C7258: addu        $v1, $a0, $zero
    ctx->r3 = ADD32(ctx->r4, 0);
    skip_0:
L_800C725C:
    // 0x800C725C: sb          $v1, 0x4A($t0)
    MEM_B(0X4A, ctx->r8) = ctx->r3;
    // 0x800C7260: lbu         $v1, 0x2($a1)
    ctx->r3 = MEM_BU(ctx->r5, 0X2);
    // 0x800C7264: lbu         $a0, 0x4B($t0)
    ctx->r4 = MEM_BU(ctx->r8, 0X4B);
    // 0x800C7268: sltu        $v0, $v1, $a0
    ctx->r2 = ctx->r3 < ctx->r4 ? 1 : 0;
    // 0x800C726C: bnel        $v0, $zero, L_800C7274
    if (ctx->r2 != 0) {
        // 0x800C7270: addu        $v1, $a0, $zero
        ctx->r3 = ADD32(ctx->r4, 0);
            goto L_800C7274;
    }
    goto skip_1;
    // 0x800C7270: addu        $v1, $a0, $zero
    ctx->r3 = ADD32(ctx->r4, 0);
    skip_1:
L_800C7274:
    // 0x800C7274: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x800C7278: andi        $v0, $a3, 0xFF
    ctx->r2 = ctx->r7 & 0XFF;
    // 0x800C727C: sltu        $v0, $v0, $a2
    ctx->r2 = ctx->r2 < ctx->r6 ? 1 : 0;
    // 0x800C7280: bne         $v0, $zero, L_800C7228
    if (ctx->r2 != 0) {
        // 0x800C7284: sb          $v1, 0x4B($t0)
        MEM_B(0X4B, ctx->r8) = ctx->r3;
            goto L_800C7228;
    }
    // 0x800C7284: sb          $v1, 0x4B($t0)
    MEM_B(0X4B, ctx->r8) = ctx->r3;
L_800C7288:
    // 0x800C7288: lhu         $v1, 0x3E($t0)
    ctx->r3 = MEM_HU(ctx->r8, 0X3E);
    // 0x800C728C: lbu         $a0, 0x4B($t0)
    ctx->r4 = MEM_BU(ctx->r8, 0X4B);
    // 0x800C7290: addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
    // 0x800C7294: sll         $a0, $a0, 3
    ctx->r4 = S32(ctx->r4 << 3);
    // 0x800C7298: addu        $v0, $v1, $a0
    ctx->r2 = ADD32(ctx->r3, ctx->r4);
    // 0x800C729C: div         $zero, $v0, $a0
    lo = S32(S64(S32(ctx->r2)) / S64(S32(ctx->r4))); hi = S32(S64(S32(ctx->r2)) % S64(S32(ctx->r4)));
    // 0x800C72A0: bne         $a0, $zero, L_800C72AC
    if (ctx->r4 != 0) {
        // 0x800C72A4: nop
    
            goto L_800C72AC;
    }
    // 0x800C72A4: nop

    // 0x800C72A8: break       7
    do_break(2148299432);
L_800C72AC:
    // 0x800C72AC: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800C72B0: bne         $a0, $at, L_800C72C4
    if (ctx->r4 != ctx->r1) {
        // 0x800C72B4: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800C72C4;
    }
    // 0x800C72B4: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800C72B8: bne         $v0, $at, L_800C72C4
    if (ctx->r2 != ctx->r1) {
        // 0x800C72BC: nop
    
            goto L_800C72C4;
    }
    // 0x800C72BC: nop

    // 0x800C72C0: break       6
    do_break(2148299456);
L_800C72C4:
    // 0x800C72C4: mflo        $v0
    ctx->r2 = lo;
    // 0x800C72C8: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x800C72CC: nop

    // 0x800C72D0: div         $zero, $v1, $v0
    lo = S32(S64(S32(ctx->r3)) / S64(S32(ctx->r2))); hi = S32(S64(S32(ctx->r3)) % S64(S32(ctx->r2)));
    // 0x800C72D4: bne         $v0, $zero, L_800C72E0
    if (ctx->r2 != 0) {
        // 0x800C72D8: nop
    
            goto L_800C72E0;
    }
    // 0x800C72D8: nop

    // 0x800C72DC: break       7
    do_break(2148299484);
L_800C72E0:
    // 0x800C72E0: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800C72E4: bne         $v0, $at, L_800C72F8
    if (ctx->r2 != ctx->r1) {
        // 0x800C72E8: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800C72F8;
    }
    // 0x800C72E8: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800C72EC: bne         $v1, $at, L_800C72F8
    if (ctx->r3 != ctx->r1) {
        // 0x800C72F0: nop
    
            goto L_800C72F8;
    }
    // 0x800C72F0: nop

    // 0x800C72F4: break       6
    do_break(2148299508);
L_800C72F8:
    // 0x800C72F8: mflo        $v1
    ctx->r3 = lo;
    // 0x800C72FC: lbu         $v0, 0x4C($t0)
    ctx->r2 = MEM_BU(ctx->r8, 0X4C);
    // 0x800C7300: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    // 0x800C7304: beq         $v0, $zero, L_800C73DC
    if (ctx->r2 == 0) {
        // 0x800C7308: sh          $v1, 0x7D4($t0)
        MEM_H(0X7D4, ctx->r8) = ctx->r3;
            goto L_800C73DC;
    }
    // 0x800C7308: sh          $v1, 0x7D4($t0)
    MEM_H(0X7D4, ctx->r8) = ctx->r3;
    // 0x800C730C: andi        $v1, $a3, 0xFF
    ctx->r3 = ctx->r7 & 0XFF;
L_800C7310:
    // 0x800C7310: sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3 << 1);
    // 0x800C7314: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800C7318: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800C731C: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x800C7320: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800C7324: addiu       $v0, $v0, 0x6F8
    ctx->r2 = ADD32(ctx->r2, 0X6F8);
    // 0x800C7328: addu        $a1, $t0, $v0
    ctx->r5 = ADD32(ctx->r8, ctx->r2);
    // 0x800C732C: lhu         $v1, 0x3C($t0)
    ctx->r3 = MEM_HU(ctx->r8, 0X3C);
    // 0x800C7330: lbu         $v0, 0x1($a1)
    ctx->r2 = MEM_BU(ctx->r5, 0X1);
    // 0x800C7334: mult        $v1, $v0
    result = S64(S32(ctx->r3)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800C7338: lbu         $v1, 0x4A($t0)
    ctx->r3 = MEM_BU(ctx->r8, 0X4A);
    // 0x800C733C: mflo        $a2
    ctx->r6 = lo;
    // 0x800C7340: addiu       $v0, $a2, -0x1
    ctx->r2 = ADD32(ctx->r6, -0X1);
    // 0x800C7344: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800C7348: div         $zero, $v0, $v1
    lo = S32(S64(S32(ctx->r2)) / S64(S32(ctx->r3))); hi = S32(S64(S32(ctx->r2)) % S64(S32(ctx->r3)));
    // 0x800C734C: bne         $v1, $zero, L_800C7358
    if (ctx->r3 != 0) {
        // 0x800C7350: nop
    
            goto L_800C7358;
    }
    // 0x800C7350: nop

    // 0x800C7354: break       7
    do_break(2148299604);
L_800C7358:
    // 0x800C7358: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800C735C: bne         $v1, $at, L_800C7370
    if (ctx->r3 != ctx->r1) {
        // 0x800C7360: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800C7370;
    }
    // 0x800C7360: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800C7364: bne         $v0, $at, L_800C7370
    if (ctx->r2 != ctx->r1) {
        // 0x800C7368: nop
    
            goto L_800C7370;
    }
    // 0x800C7368: nop

    // 0x800C736C: break       6
    do_break(2148299628);
L_800C7370:
    // 0x800C7370: mflo        $v0
    ctx->r2 = lo;
    // 0x800C7374: sw          $v0, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->r2;
    // 0x800C7378: lhu         $v1, 0x3E($t0)
    ctx->r3 = MEM_HU(ctx->r8, 0X3E);
    // 0x800C737C: lbu         $v0, 0x2($a1)
    ctx->r2 = MEM_BU(ctx->r5, 0X2);
    // 0x800C7380: mult        $v1, $v0
    result = S64(S32(ctx->r3)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800C7384: lbu         $v1, 0x4B($t0)
    ctx->r3 = MEM_BU(ctx->r8, 0X4B);
    // 0x800C7388: mflo        $a2
    ctx->r6 = lo;
    // 0x800C738C: addiu       $v0, $a2, -0x1
    ctx->r2 = ADD32(ctx->r6, -0X1);
    // 0x800C7390: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800C7394: div         $zero, $v0, $v1
    lo = S32(S64(S32(ctx->r2)) / S64(S32(ctx->r3))); hi = S32(S64(S32(ctx->r2)) % S64(S32(ctx->r3)));
    // 0x800C7398: bne         $v1, $zero, L_800C73A4
    if (ctx->r3 != 0) {
        // 0x800C739C: nop
    
            goto L_800C73A4;
    }
    // 0x800C739C: nop

    // 0x800C73A0: break       7
    do_break(2148299680);
L_800C73A4:
    // 0x800C73A4: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800C73A8: bne         $v1, $at, L_800C73BC
    if (ctx->r3 != ctx->r1) {
        // 0x800C73AC: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800C73BC;
    }
    // 0x800C73AC: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800C73B0: bne         $v0, $at, L_800C73BC
    if (ctx->r2 != ctx->r1) {
        // 0x800C73B4: nop
    
            goto L_800C73BC;
    }
    // 0x800C73B4: nop

    // 0x800C73B8: break       6
    do_break(2148299704);
L_800C73BC:
    // 0x800C73BC: mflo        $v0
    ctx->r2 = lo;
    // 0x800C73C0: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x800C73C4: sw          $v0, 0xC($a1)
    MEM_W(0XC, ctx->r5) = ctx->r2;
    // 0x800C73C8: lbu         $v1, 0x4C($t0)
    ctx->r3 = MEM_BU(ctx->r8, 0X4C);
    // 0x800C73CC: andi        $v0, $a3, 0xFF
    ctx->r2 = ctx->r7 & 0XFF;
    // 0x800C73D0: sltu        $v0, $v0, $v1
    ctx->r2 = ctx->r2 < ctx->r3 ? 1 : 0;
    // 0x800C73D4: bne         $v0, $zero, L_800C7310
    if (ctx->r2 != 0) {
        // 0x800C73D8: andi        $v1, $a3, 0xFF
        ctx->r3 = ctx->r7 & 0XFF;
            goto L_800C7310;
    }
    // 0x800C73D8: andi        $v1, $a3, 0xFF
    ctx->r3 = ctx->r7 & 0XFF;
L_800C73DC:
    // 0x800C73DC: jr          $ra
    // 0x800C73E0: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    return;
    // 0x800C73E0: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
;}
RECOMP_FUNC void func_800C7120(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C7120: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800C7124: lwc1        $f0, -0x5E08($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, -0X5E08);
    // 0x800C7128: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800C712C: swc1        $f0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f0.u32l;
    // 0x800C7130: lwc1        $f0, -0x5E04($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, -0X5E04);
    // 0x800C7134: jr          $ra
    // 0x800C7138: swc1        $f0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f0.u32l;
    return;
    // 0x800C7138: swc1        $f0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f0.u32l;
;}
RECOMP_FUNC void func_800C713C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C713C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800C7140: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x800C7144: addu        $s2, $a0, $zero
    ctx->r18 = ADD32(ctx->r4, 0);
    // 0x800C7148: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x800C714C: addu        $s0, $a1, $zero
    ctx->r16 = ADD32(ctx->r5, 0);
    // 0x800C7150: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x800C7154: addu        $s1, $a2, $zero
    ctx->r17 = ADD32(ctx->r6, 0);
    // 0x800C7158: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    // 0x800C715C: addiu       $a1, $s1, 0x1C
    ctx->r5 = ADD32(ctx->r17, 0X1C);
    // 0x800C7160: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x800C7164: jal         0x80019548
    // 0x800C7168: addiu       $a2, $s1, 0x10
    ctx->r6 = ADD32(ctx->r17, 0X10);
    func_80019548(rdram, ctx);
        goto after_0;
    // 0x800C7168: addiu       $a2, $s1, 0x10
    ctx->r6 = ADD32(ctx->r17, 0X10);
    after_0:
    // 0x800C716C: lwc1        $f2, 0x10($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X10);
    // 0x800C7170: lwc1        $f0, 0x0($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X0);
    // 0x800C7174: mul.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x800C7178: lwc1        $f6, 0x1C($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X1C);
    // 0x800C717C: lwc1        $f0, 0x4($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X4);
    // 0x800C7180: mul.s       $f6, $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x800C7184: lwc1        $f4, 0x8($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X8);
    // 0x800C7188: lwc1        $f0, 0x10($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X10);
    // 0x800C718C: mul.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x800C7190: add.s       $f2, $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f6.fl;
    // 0x800C7194: add.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x800C7198: lwc1        $f0, 0x0($s2)
    ctx->f0.u32l = MEM_W(ctx->r18, 0X0);
    // 0x800C719C: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x800C71A0: swc1        $f0, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->f0.u32l;
    // 0x800C71A4: lwc1        $f2, 0x14($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X14);
    // 0x800C71A8: lwc1        $f0, 0x0($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X0);
    // 0x800C71AC: mul.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x800C71B0: lwc1        $f6, 0x20($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X20);
    // 0x800C71B4: lwc1        $f0, 0x4($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X4);
    // 0x800C71B8: mul.s       $f6, $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x800C71BC: lwc1        $f4, 0x8($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X8);
    // 0x800C71C0: lwc1        $f0, 0x14($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X14);
    // 0x800C71C4: mul.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x800C71C8: add.s       $f2, $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f6.fl;
    // 0x800C71CC: add.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x800C71D0: lwc1        $f0, 0x4($s2)
    ctx->f0.u32l = MEM_W(ctx->r18, 0X4);
    // 0x800C71D4: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x800C71D8: swc1        $f0, 0x4($s2)
    MEM_W(0X4, ctx->r18) = ctx->f0.u32l;
    // 0x800C71DC: lwc1        $f2, 0x18($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X18);
    // 0x800C71E0: lwc1        $f0, 0x0($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X0);
    // 0x800C71E4: mul.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x800C71E8: lwc1        $f6, 0x24($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X24);
    // 0x800C71EC: lwc1        $f0, 0x4($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X4);
    // 0x800C71F0: mul.s       $f6, $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x800C71F4: lwc1        $f4, 0x8($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X8);
    // 0x800C71F8: lwc1        $f0, 0x18($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X18);
    // 0x800C71FC: mul.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x800C7200: add.s       $f2, $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f6.fl;
    // 0x800C7204: add.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x800C7208: lwc1        $f0, 0x8($s2)
    ctx->f0.u32l = MEM_W(ctx->r18, 0X8);
    // 0x800C720C: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x800C7210: swc1        $f0, 0x8($s2)
    MEM_W(0X8, ctx->r18) = ctx->f0.u32l;
    // 0x800C7214: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x800C7218: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x800C721C: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x800C7220: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x800C7224: jr          $ra
    // 0x800C7228: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x800C7228: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_800C722C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C722C: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800C7230: lwc1        $f0, -0x5E00($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, -0X5E00);
    // 0x800C7234: jr          $ra
    // 0x800C7238: nop

    return;
    // 0x800C7238: nop

;}
RECOMP_FUNC void func_800C723C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C723C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800C7240: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800C7244: lw          $v0, -0x3F70($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X3F70);
    // 0x800C7248: addu        $a1, $a0, $zero
    ctx->r5 = ADD32(ctx->r4, 0);
    // 0x800C724C: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x800C7250: lw          $a0, 0x0($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X0);
    // 0x800C7254: jal         0x800594F8
    // 0x800C7258: nop

    func_800594F8(rdram, ctx);
        goto after_0;
    // 0x800C7258: nop

    after_0:
    // 0x800C725C: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x800C7260: jr          $ra
    // 0x800C7264: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x800C7264: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_800C7268(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C7268: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800C726C: lw          $v0, -0x3F70($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X3F70);
    // 0x800C7270: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x800C7274: addiu       $v1, $v0, 0x28
    ctx->r3 = ADD32(ctx->r2, 0X28);
    // 0x800C7278: addiu       $v0, $v0, 0x58
    ctx->r2 = ADD32(ctx->r2, 0X58);
L_800C727C:
    // 0x800C727C: lw          $a1, 0x0($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X0);
    // 0x800C7280: lw          $a2, 0x4($v1)
    ctx->r6 = MEM_W(ctx->r3, 0X4);
    // 0x800C7284: lw          $a3, 0x8($v1)
    ctx->r7 = MEM_W(ctx->r3, 0X8);
    // 0x800C7288: lw          $t0, 0xC($v1)
    ctx->r8 = MEM_W(ctx->r3, 0XC);
    // 0x800C728C: sw          $a1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r5;
    // 0x800C7290: sw          $a2, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r6;
    // 0x800C7294: sw          $a3, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r7;
    // 0x800C7298: sw          $t0, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r8;
    // 0x800C729C: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
    // 0x800C72A0: bne         $v1, $v0, L_800C727C
    if (ctx->r3 != ctx->r2) {
        // 0x800C72A4: addiu       $a0, $a0, 0x10
        ctx->r4 = ADD32(ctx->r4, 0X10);
            goto L_800C727C;
    }
    // 0x800C72A4: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    // 0x800C72A8: jr          $ra
    // 0x800C72AC: nop

    return;
    // 0x800C72AC: nop

;}
RECOMP_FUNC void initializeObjectiveTracking(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C72B0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800C72B4: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
    // 0x800C72B8: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800C72BC: lw          $v0, 0xB70($v0)
    ctx->r2 = MEM_W(ctx->r2, 0XB70);
    // 0x800C72C0: addiu       $v1, $v1, -0x5BB0
    ctx->r3 = ADD32(ctx->r3, -0X5BB0);
    // 0x800C72C4: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x800C72C8: sll         $v0, $v0, 4
    ctx->r2 = S32(ctx->r2 << 4);
    // 0x800C72CC: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800C72D0: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x800C72D4: jalr        $v0
    // 0x800C72D8: nop

    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_0;
    // 0x800C72D8: nop

    after_0:
    // 0x800C72DC: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x800C72E0: jr          $ra
    // 0x800C72E4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x800C72E4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_800C72E8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C72E8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800C72EC: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
    // 0x800C72F0: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800C72F4: lw          $v0, 0xB70($v0)
    ctx->r2 = MEM_W(ctx->r2, 0XB70);
    // 0x800C72F8: addiu       $v1, $v1, -0x5BB0
    ctx->r3 = ADD32(ctx->r3, -0X5BB0);
    // 0x800C72FC: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x800C7300: sll         $v0, $v0, 4
    ctx->r2 = S32(ctx->r2 << 4);
    // 0x800C7304: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800C7308: lw          $v0, 0x4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X4);
    // 0x800C730C: jalr        $v0
    // 0x800C7310: nop

    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_0;
    // 0x800C7310: nop

    after_0:
    // 0x800C7314: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x800C7318: jr          $ra
    // 0x800C731C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x800C731C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void calculateFriendliesSaved(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C7320: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800C7324: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
    // 0x800C7328: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800C732C: lw          $v0, 0xB70($v0)
    ctx->r2 = MEM_W(ctx->r2, 0XB70);
    // 0x800C7330: addiu       $v1, $v1, -0x5BB0
    ctx->r3 = ADD32(ctx->r3, -0X5BB0);
    // 0x800C7334: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x800C7338: sll         $v0, $v0, 4
    ctx->r2 = S32(ctx->r2 << 4);
    // 0x800C733C: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800C7340: lw          $v0, 0x8($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X8);
    // 0x800C7344: jalr        $v0
    // 0x800C7348: nop

    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_0;
    // 0x800C7348: nop

    after_0:
    // 0x800C734C: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x800C7350: jr          $ra
    // 0x800C7354: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x800C7354: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void checkComplexObjectives(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C7358: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800C735C: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
    // 0x800C7360: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800C7364: lw          $v0, 0xB70($v0)
    ctx->r2 = MEM_W(ctx->r2, 0XB70);
    // 0x800C7368: addiu       $v1, $v1, -0x5BB0
    ctx->r3 = ADD32(ctx->r3, -0X5BB0);
    // 0x800C736C: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x800C7370: sll         $v0, $v0, 4
    ctx->r2 = S32(ctx->r2 << 4);
    // 0x800C7374: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800C7378: lw          $v0, 0xC($v0)
    ctx->r2 = MEM_W(ctx->r2, 0XC);
    // 0x800C737C: jalr        $v0
    // 0x800C7380: nop

    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_0;
    // 0x800C7380: nop

    after_0:
    // 0x800C7384: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x800C7388: jr          $ra
    // 0x800C738C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x800C738C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void dealDamagetoDatItem(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C7390: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x800C7394: sw          $s2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r18;
    // 0x800C7398: addu        $s2, $a1, $zero
    ctx->r18 = ADD32(ctx->r5, 0);
    // 0x800C739C: sw          $s1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r17;
    // 0x800C73A0: addu        $s1, $zero, $zero
    ctx->r17 = ADD32(0, 0);
    // 0x800C73A4: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x800C73A8: jal         0x80047B48
    // 0x800C73AC: sw          $s0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r16;
    getLevelDatItemByName(rdram, ctx);
        goto after_0;
    // 0x800C73AC: sw          $s0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r16;
    after_0:
    // 0x800C73B0: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    // 0x800C73B4: beq         $s0, $zero, L_800C74E8
    if (ctx->r16 == 0) {
        // 0x800C73B8: ori         $v1, $zero, 0xFFFF
        ctx->r3 = 0 | 0XFFFF;
            goto L_800C74E8;
    }
    // 0x800C73B8: ori         $v1, $zero, 0xFFFF
    ctx->r3 = 0 | 0XFFFF;
    // 0x800C73BC: lhu         $v0, 0x6($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X6);
    // 0x800C73C0: beq         $v0, $v1, L_800C748C
    if (ctx->r2 == ctx->r3) {
        // 0x800C73C4: addiu       $v0, $zero, 0x7
        ctx->r2 = ADD32(0, 0X7);
            goto L_800C748C;
    }
    // 0x800C73C4: addiu       $v0, $zero, 0x7
    ctx->r2 = ADD32(0, 0X7);
    // 0x800C73C8: sh          $v0, 0x1C($sp)
    MEM_H(0X1C, ctx->r29) = ctx->r2;
    // 0x800C73CC: slt         $v0, $v1, $s2
    ctx->r2 = SIGNED(ctx->r3) < SIGNED(ctx->r18) ? 1 : 0;
    // 0x800C73D0: sh          $v1, 0x18($sp)
    MEM_H(0X18, ctx->r29) = ctx->r3;
    // 0x800C73D4: bne         $v0, $zero, L_800C73E4
    if (ctx->r2 != 0) {
        // 0x800C73D8: sh          $v1, 0x1A($sp)
        MEM_H(0X1A, ctx->r29) = ctx->r3;
            goto L_800C73E4;
    }
    // 0x800C73D8: sh          $v1, 0x1A($sp)
    MEM_H(0X1A, ctx->r29) = ctx->r3;
    // 0x800C73DC: j           L_800C73EC
    // 0x800C73E0: sh          $s2, 0x1E($sp)
    MEM_H(0X1E, ctx->r29) = ctx->r18;
        goto L_800C73EC;
    // 0x800C73E0: sh          $s2, 0x1E($sp)
    MEM_H(0X1E, ctx->r29) = ctx->r18;
L_800C73E4:
    // 0x800C73E4: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x800C73E8: sh          $v0, 0x1E($sp)
    MEM_H(0X1E, ctx->r29) = ctx->r2;
L_800C73EC:
    // 0x800C73EC: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    // 0x800C73F0: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    // 0x800C73F4: lhu         $a0, 0x6($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X6);
    // 0x800C73F8: jal         0x8003E8DC
    // 0x800C73FC: addiu       $a2, $sp, 0x18
    ctx->r6 = ADD32(ctx->r29, 0X18);
    slotDispatcherIter(rdram, ctx);
        goto after_1;
    // 0x800C73FC: addiu       $a2, $sp, 0x18
    ctx->r6 = ADD32(ctx->r29, 0X18);
    after_1:
    // 0x800C7400: lhu         $a0, 0x6($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X6);
    // 0x800C7404: jal         0x8004013C
    // 0x800C7408: nop

    func_8004013C(rdram, ctx);
        goto after_2;
    // 0x800C7408: nop

    after_2:
    // 0x800C740C: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // 0x800C7410: lw          $v0, 0x10($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X10);
    // 0x800C7414: beq         $v0, $zero, L_800C743C
    if (ctx->r2 == 0) {
        // 0x800C7418: addiu       $a1, $zero, 0xB
        ctx->r5 = ADD32(0, 0XB);
            goto L_800C743C;
    }
    // 0x800C7418: addiu       $a1, $zero, 0xB
    ctx->r5 = ADD32(0, 0XB);
    // 0x800C741C: lhu         $a0, 0x6($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X6);
    // 0x800C7420: jal         0x8004013C
    // 0x800C7424: nop

    func_8004013C(rdram, ctx);
        goto after_3;
    // 0x800C7424: nop

    after_3:
    // 0x800C7428: lw          $a0, 0x10($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X10);
    // 0x800C742C: jal         0x800F20EC
    // 0x800C7430: nop

    getNpcCurrentHealth(rdram, ctx);
        goto after_4;
    // 0x800C7430: nop

    after_4:
    // 0x800C7434: j           L_800C74E8
    // 0x800C7438: addu        $s1, $v0, $zero
    ctx->r17 = ADD32(ctx->r2, 0);
        goto L_800C74E8;
    // 0x800C7438: addu        $s1, $v0, $zero
    ctx->r17 = ADD32(ctx->r2, 0);
L_800C743C:
    // 0x800C743C: ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
    // 0x800C7440: sh          $v0, 0x28($sp)
    MEM_H(0X28, ctx->r29) = ctx->r2;
    // 0x800C7444: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x800C7448: sh          $v0, 0x2A($sp)
    MEM_H(0X2A, ctx->r29) = ctx->r2;
    // 0x800C744C: lhu         $a0, 0x16($v1)
    ctx->r4 = MEM_HU(ctx->r3, 0X16);
    // 0x800C7450: jal         0x8003E8DC
    // 0x800C7454: addiu       $a2, $sp, 0x28
    ctx->r6 = ADD32(ctx->r29, 0X28);
    slotDispatcherIter(rdram, ctx);
        goto after_5;
    // 0x800C7454: addiu       $a2, $sp, 0x28
    ctx->r6 = ADD32(ctx->r29, 0X28);
    after_5:
    // 0x800C7458: lh          $v1, 0x2A($sp)
    ctx->r3 = MEM_H(ctx->r29, 0X2A);
    // 0x800C745C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x800C7460: beq         $v1, $v0, L_800C7474
    if (ctx->r3 == ctx->r2) {
        // 0x800C7464: lui         $v0, 0x8013
        ctx->r2 = S32(0X8013 << 16);
            goto L_800C7474;
    }
    // 0x800C7464: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800C7468: lw          $s1, 0x2C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X2C);
    // 0x800C746C: j           L_800C74EC
    // 0x800C7470: addu        $v0, $s1, $zero
    ctx->r2 = ADD32(ctx->r17, 0);
        goto L_800C74EC;
    // 0x800C7470: addu        $v0, $s1, $zero
    ctx->r2 = ADD32(ctx->r17, 0);
L_800C7474:
    // 0x800C7474: lw          $v0, 0x7CE4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X7CE4);
    // 0x800C7478: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800C747C: addu        $v0, $v0, $s0
    ctx->r2 = ADD32(ctx->r2, ctx->r16);
    // 0x800C7480: lw          $s1, 0x6C($v0)
    ctx->r17 = MEM_W(ctx->r2, 0X6C);
    // 0x800C7484: j           L_800C74EC
    // 0x800C7488: addu        $v0, $s1, $zero
    ctx->r2 = ADD32(ctx->r17, 0);
        goto L_800C74EC;
    // 0x800C7488: addu        $v0, $s1, $zero
    ctx->r2 = ADD32(ctx->r17, 0);
L_800C748C:
    // 0x800C748C: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800C7490: lw          $v1, 0x7CE4($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X7CE4);
    // 0x800C7494: addu        $a3, $s0, $zero
    ctx->r7 = ADD32(ctx->r16, 0);
    // 0x800C7498: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x800C749C: addu        $v1, $v1, $a3
    ctx->r3 = ADD32(ctx->r3, ctx->r7);
    // 0x800C74A0: lw          $v0, 0x6C($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X6C);
    // 0x800C74A4: subu        $v0, $v0, $s2
    ctx->r2 = SUB32(ctx->r2, ctx->r18);
    // 0x800C74A8: addu        $s1, $v0, $zero
    ctx->r17 = ADD32(ctx->r2, 0);
    // 0x800C74AC: sw          $s1, 0x6C($v1)
    MEM_W(0X6C, ctx->r3) = ctx->r17;
    // 0x800C74B0: lhu         $v1, 0x0($a3)
    ctx->r3 = MEM_HU(ctx->r7, 0X0);
    // 0x800C74B4: addiu       $v0, $zero, 0x14
    ctx->r2 = ADD32(0, 0X14);
    // 0x800C74B8: bne         $v1, $v0, L_800C74EC
    if (ctx->r3 != ctx->r2) {
        // 0x800C74BC: addu        $v0, $s1, $zero
        ctx->r2 = ADD32(ctx->r17, 0);
            goto L_800C74EC;
    }
    // 0x800C74BC: addu        $v0, $s1, $zero
    ctx->r2 = ADD32(ctx->r17, 0);
    // 0x800C74C0: lw          $v0, 0x80($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X80);
    // 0x800C74C4: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // 0x800C74C8: lw          $v0, 0x84($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X84);
    // 0x800C74CC: sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    // 0x800C74D0: lw          $a0, 0x78($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X78);
    // 0x800C74D4: lw          $a1, 0x7C($a3)
    ctx->r5 = MEM_W(ctx->r7, 0X7C);
    // 0x800C74D8: lw          $a2, 0x70($a3)
    ctx->r6 = MEM_W(ctx->r7, 0X70);
    // 0x800C74DC: lw          $a3, 0x74($a3)
    ctx->r7 = MEM_W(ctx->r7, 0X74);
    // 0x800C74E0: jal         0x80065914
    // 0x800C74E4: nop

    datItemSetObjectiveBooleanCount(rdram, ctx);
        goto after_6;
    // 0x800C74E4: nop

    after_6:
L_800C74E8:
    // 0x800C74E8: addu        $v0, $s1, $zero
    ctx->r2 = ADD32(ctx->r17, 0);
L_800C74EC:
    // 0x800C74EC: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x800C74F0: lw          $s2, 0x38($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X38);
    // 0x800C74F4: lw          $s1, 0x34($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X34);
    // 0x800C74F8: lw          $s0, 0x30($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X30);
    // 0x800C74FC: jr          $ra
    // 0x800C7500: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x800C7500: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void parseJfifDQTMarker(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C73E4: addiu       $sp, $sp, -0x100
    ctx->r29 = ADD32(ctx->r29, -0X100);
    // 0x800C73E8: addu        $a3, $a0, $zero
    ctx->r7 = ADD32(ctx->r4, 0);
    // 0x800C73EC: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x800C73F0: addiu       $t3, $v0, 0x76E0
    ctx->r11 = ADD32(ctx->r2, 0X76E0);
    // 0x800C73F4: lui         $v1, 0x800A
    ctx->r3 = S32(0X800A << 16);
    // 0x800C73F8: lw          $v0, 0x34($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X34);
    // 0x800C73FC: addiu       $t2, $v1, 0x7730
    ctx->r10 = ADD32(ctx->r3, 0X7730);
    // 0x800C7400: lbu         $v1, 0x0($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X0);
    // 0x800C7404: lbu         $a0, 0x1($v0)
    ctx->r4 = MEM_BU(ctx->r2, 0X1);
    // 0x800C7408: addiu       $v0, $v0, 0x2
    ctx->r2 = ADD32(ctx->r2, 0X2);
    // 0x800C740C: sw          $v0, 0x34($a3)
    MEM_W(0X34, ctx->r7) = ctx->r2;
    // 0x800C7410: sll         $v1, $v1, 8
    ctx->r3 = S32(ctx->r3 << 8);
    // 0x800C7414: or          $a0, $a0, $v1
    ctx->r4 = ctx->r4 | ctx->r3;
    // 0x800C7418: addiu       $t1, $a0, -0x2
    ctx->r9 = ADD32(ctx->r4, -0X2);
L_800C741C:
    // 0x800C741C: lw          $v0, 0x34($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X34);
    // 0x800C7420: lbu         $t0, 0x0($v0)
    ctx->r8 = MEM_BU(ctx->r2, 0X0);
    // 0x800C7424: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800C7428: sw          $v0, 0x34($a3)
    MEM_W(0X34, ctx->r7) = ctx->r2;
    // 0x800C742C: sltiu       $v0, $t0, 0x4
    ctx->r2 = ctx->r8 < 0X4 ? 1 : 0;
    // 0x800C7430: bne         $v0, $zero, L_800C7440
    if (ctx->r2 != 0) {
        // 0x800C7434: addu        $a1, $zero, $zero
        ctx->r5 = ADD32(0, 0);
            goto L_800C7440;
    }
    // 0x800C7434: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x800C7438: j           L_800C752C
    // 0x800C743C: addiu       $v0, $zero, 0x9
    ctx->r2 = ADD32(0, 0X9);
        goto L_800C752C;
    // 0x800C743C: addiu       $v0, $zero, 0x9
    ctx->r2 = ADD32(0, 0X9);
L_800C7440:
    // 0x800C7440: andi        $v0, $a1, 0xFFFF
    ctx->r2 = ctx->r5 & 0XFFFF;
    // 0x800C7444: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x800C7448: addu        $v0, $v0, $t3
    ctx->r2 = ADD32(ctx->r2, ctx->r11);
    // 0x800C744C: lw          $v1, 0x34($a3)
    ctx->r3 = MEM_W(ctx->r7, 0X34);
    // 0x800C7450: lbu         $v0, 0x0($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X0);
    // 0x800C7454: lbu         $a0, 0x0($v1)
    ctx->r4 = MEM_BU(ctx->r3, 0X0);
    // 0x800C7458: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800C745C: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800C7460: addu        $v0, $sp, $v0
    ctx->r2 = ADD32(ctx->r29, ctx->r2);
    // 0x800C7464: mtc1        $a0, $f0
    ctx->f0.u32l = ctx->r4;
    // 0x800C7468: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x800C746C: swc1        $f0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f0.u32l;
    // 0x800C7470: andi        $v0, $a1, 0xFFFF
    ctx->r2 = ctx->r5 & 0XFFFF;
    // 0x800C7474: sltiu       $v0, $v0, 0x40
    ctx->r2 = ctx->r2 < 0X40 ? 1 : 0;
    // 0x800C7478: bne         $v0, $zero, L_800C7440
    if (ctx->r2 != 0) {
        // 0x800C747C: sw          $v1, 0x34($a3)
        MEM_W(0X34, ctx->r7) = ctx->r3;
            goto L_800C7440;
    }
    // 0x800C747C: sw          $v1, 0x34($a3)
    MEM_W(0X34, ctx->r7) = ctx->r3;
    // 0x800C7480: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x800C7484: addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    // 0x800C7488: andi        $v0, $t0, 0xFFFF
    ctx->r2 = ctx->r8 & 0XFFFF;
    // 0x800C748C: sll         $t0, $v0, 8
    ctx->r8 = S32(ctx->r2 << 8);
    // 0x800C7490: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x800C7494: lbu         $a0, 0x49($a3)
    ctx->r4 = MEM_BU(ctx->r7, 0X49);
    // 0x800C7498: sllv        $v1, $v1, $v0
    ctx->r3 = S32(ctx->r3 << (ctx->r2 & 31));
    // 0x800C749C: or          $a0, $a0, $v1
    ctx->r4 = ctx->r4 | ctx->r3;
    // 0x800C74A0: sb          $a0, 0x49($a3)
    MEM_B(0X49, ctx->r7) = ctx->r4;
    // 0x800C74A4: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
L_800C74A8:
    // 0x800C74A8: andi        $v0, $a2, 0xFFFF
    ctx->r2 = ctx->r6 & 0XFFFF;
    // 0x800C74AC: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x800C74B0: addu        $v0, $v0, $t2
    ctx->r2 = ADD32(ctx->r2, ctx->r10);
    // 0x800C74B4: ldc1        $f4, 0x0($v0)
    CHECK_FR(ctx, 4);
    ctx->f4.u64 = LD(ctx->r2, 0X0);
L_800C74B8:
    // 0x800C74B8: andi        $v1, $a1, 0xFFFF
    ctx->r3 = ctx->r5 & 0XFFFF;
    // 0x800C74BC: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x800C74C0: addu        $v0, $sp, $v1
    ctx->r2 = ADD32(ctx->r29, ctx->r3);
    // 0x800C74C4: lwc1        $f2, 0x0($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X0);
    // 0x800C74C8: cvt.d.s     $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f2.d = CVT_D_S(ctx->f2.fl);
    // 0x800C74CC: mul.d       $f2, $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f4.d); 
    ctx->f2.d = MUL_D(ctx->f2.d, ctx->f4.d);
    // 0x800C74D0: andi        $v0, $a0, 0xFFFF
    ctx->r2 = ctx->r4 & 0XFFFF;
    // 0x800C74D4: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x800C74D8: addu        $v0, $v0, $t2
    ctx->r2 = ADD32(ctx->r2, ctx->r10);
    // 0x800C74DC: ldc1        $f0, 0x0($v0)
    CHECK_FR(ctx, 0);
    ctx->f0.u64 = LD(ctx->r2, 0X0);
    // 0x800C74E0: mul.d       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f0.d); 
    ctx->f2.d = MUL_D(ctx->f2.d, ctx->f0.d);
    // 0x800C74E4: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x800C74E8: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x800C74EC: addu        $v1, $v1, $t0
    ctx->r3 = ADD32(ctx->r3, ctx->r8);
    // 0x800C74F0: addu        $v1, $a3, $v1
    ctx->r3 = ADD32(ctx->r7, ctx->r3);
    // 0x800C74F4: andi        $v0, $a0, 0xFFFF
    ctx->r2 = ctx->r4 & 0XFFFF;
    // 0x800C74F8: sltiu       $v0, $v0, 0x8
    ctx->r2 = ctx->r2 < 0X8 ? 1 : 0;
    // 0x800C74FC: cvt.s.d     $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.d); 
    ctx->f2.fl = CVT_S_D(ctx->f2.d);
    // 0x800C7500: bne         $v0, $zero, L_800C74B8
    if (ctx->r2 != 0) {
        // 0x800C7504: swc1        $f2, 0x2F8($v1)
        MEM_W(0X2F8, ctx->r3) = ctx->f2.u32l;
            goto L_800C74B8;
    }
    // 0x800C7504: swc1        $f2, 0x2F8($v1)
    MEM_W(0X2F8, ctx->r3) = ctx->f2.u32l;
    // 0x800C7508: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x800C750C: andi        $v0, $a2, 0xFFFF
    ctx->r2 = ctx->r6 & 0XFFFF;
    // 0x800C7510: sltiu       $v0, $v0, 0x8
    ctx->r2 = ctx->r2 < 0X8 ? 1 : 0;
    // 0x800C7514: bnel        $v0, $zero, L_800C74A8
    if (ctx->r2 != 0) {
        // 0x800C7518: addu        $a0, $zero, $zero
        ctx->r4 = ADD32(0, 0);
            goto L_800C74A8;
    }
    goto skip_0;
    // 0x800C7518: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    skip_0:
    // 0x800C751C: addiu       $t1, $t1, -0x41
    ctx->r9 = ADD32(ctx->r9, -0X41);
    // 0x800C7520: andi        $v0, $t1, 0xFFFF
    ctx->r2 = ctx->r9 & 0XFFFF;
    // 0x800C7524: bne         $v0, $zero, L_800C741C
    if (ctx->r2 != 0) {
        // 0x800C7528: addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
            goto L_800C741C;
    }
    // 0x800C7528: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_800C752C:
    // 0x800C752C: jr          $ra
    // 0x800C7530: addiu       $sp, $sp, 0x100
    ctx->r29 = ADD32(ctx->r29, 0X100);
    return;
    // 0x800C7530: addiu       $sp, $sp, 0x100
    ctx->r29 = ADD32(ctx->r29, 0X100);
;}
RECOMP_FUNC void getCurrentLevel(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C7504: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800C7508: lw          $v0, 0xB70($v0)
    ctx->r2 = MEM_W(ctx->r2, 0XB70);
    // 0x800C750C: jr          $ra
    // 0x800C7510: nop

    return;
    // 0x800C7510: nop

;}
RECOMP_FUNC void func_800C7514(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C7514: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800C7518: lw          $v0, 0x7CE4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X7CE4);
    // 0x800C751C: jr          $ra
    // 0x800C7520: nop

    return;
    // 0x800C7520: nop

;}
RECOMP_FUNC void func_800C7524(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C7524: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800C7528: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x800C752C: jal         0x8006C940
    // 0x800C7530: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    getPlayerVehicleId(rdram, ctx);
        goto after_0;
    // 0x800C7530: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    after_0:
    // 0x800C7534: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x800C7538: jr          $ra
    // 0x800C753C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x800C753C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void parseJfifDHTMarker(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C7534: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800C7538: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x800C753C: addu        $s1, $a0, $zero
    ctx->r17 = ADD32(ctx->r4, 0);
    // 0x800C7540: sw          $ra, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r31;
    // 0x800C7544: sw          $s3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r19;
    // 0x800C7548: sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // 0x800C754C: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x800C7550: lw          $v0, 0x34($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X34);
    // 0x800C7554: lbu         $v1, 0x0($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X0);
    // 0x800C7558: lbu         $a0, 0x1($v0)
    ctx->r4 = MEM_BU(ctx->r2, 0X1);
    // 0x800C755C: addiu       $v0, $v0, 0x2
    ctx->r2 = ADD32(ctx->r2, 0X2);
    // 0x800C7560: sw          $v0, 0x34($s1)
    MEM_W(0X34, ctx->r17) = ctx->r2;
    // 0x800C7564: sll         $v1, $v1, 8
    ctx->r3 = S32(ctx->r3 << 8);
    // 0x800C7568: or          $a0, $a0, $v1
    ctx->r4 = ctx->r4 | ctx->r3;
    // 0x800C756C: addiu       $s3, $a0, -0x2
    ctx->r19 = ADD32(ctx->r4, -0X2);
L_800C7570:
    // 0x800C7570: lw          $v0, 0x34($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X34);
    // 0x800C7574: lbu         $a0, 0x0($v0)
    ctx->r4 = MEM_BU(ctx->r2, 0X0);
    // 0x800C7578: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800C757C: addu        $a2, $v0, $zero
    ctx->r6 = ADD32(ctx->r2, 0);
    // 0x800C7580: sw          $v0, 0x34($s1)
    MEM_W(0X34, ctx->r17) = ctx->r2;
    // 0x800C7584: andi        $a1, $a0, 0xF
    ctx->r5 = ctx->r4 & 0XF;
    // 0x800C7588: andi        $v1, $a0, 0xFF
    ctx->r3 = ctx->r4 & 0XFF;
    // 0x800C758C: srl         $v1, $v1, 4
    ctx->r3 = S32(U32(ctx->r3) >> 4);
    // 0x800C7590: sltiu       $v0, $v1, 0x2
    ctx->r2 = ctx->r3 < 0X2 ? 1 : 0;
    // 0x800C7594: beq         $v0, $zero, L_800C75A8
    if (ctx->r2 == 0) {
        // 0x800C7598: addu        $a3, $a1, $zero
        ctx->r7 = ADD32(ctx->r5, 0);
            goto L_800C75A8;
    }
    // 0x800C7598: addu        $a3, $a1, $zero
    ctx->r7 = ADD32(ctx->r5, 0);
    // 0x800C759C: sltiu       $v0, $a3, 0x2
    ctx->r2 = ctx->r7 < 0X2 ? 1 : 0;
    // 0x800C75A0: bne         $v0, $zero, L_800C75B0
    if (ctx->r2 != 0) {
        // 0x800C75A4: sll         $v0, $a1, 1
        ctx->r2 = S32(ctx->r5 << 1);
            goto L_800C75B0;
    }
    // 0x800C75A4: sll         $v0, $a1, 1
    ctx->r2 = S32(ctx->r5 << 1);
L_800C75A8:
    // 0x800C75A8: j           L_800C769C
    // 0x800C75AC: addiu       $v0, $zero, 0xD
    ctx->r2 = ADD32(0, 0XD);
        goto L_800C769C;
    // 0x800C75AC: addiu       $v0, $zero, 0xD
    ctx->r2 = ADD32(0, 0XD);
L_800C75B0:
    // 0x800C75B0: addu        $a1, $v1, $v0
    ctx->r5 = ADD32(ctx->r3, ctx->r2);
    // 0x800C75B4: addu        $s2, $zero, $zero
    ctx->r18 = ADD32(0, 0);
    // 0x800C75B8: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
L_800C75BC:
    // 0x800C75BC: lw          $v0, 0x34($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X34);
    // 0x800C75C0: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x800C75C4: lbu         $v1, 0x0($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X0);
    // 0x800C75C8: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800C75CC: sw          $v0, 0x34($s1)
    MEM_W(0X34, ctx->r17) = ctx->r2;
    // 0x800C75D0: andi        $v0, $a0, 0xFF
    ctx->r2 = ctx->r4 & 0XFF;
    // 0x800C75D4: sltiu       $v0, $v0, 0x10
    ctx->r2 = ctx->r2 < 0X10 ? 1 : 0;
    // 0x800C75D8: addu        $a3, $s2, $v1
    ctx->r7 = ADD32(ctx->r18, ctx->r3);
    // 0x800C75DC: bne         $v0, $zero, L_800C75BC
    if (ctx->r2 != 0) {
        // 0x800C75E0: addu        $s2, $a3, $zero
        ctx->r18 = ADD32(ctx->r7, 0);
            goto L_800C75BC;
    }
    // 0x800C75E0: addu        $s2, $a3, $zero
    ctx->r18 = ADD32(ctx->r7, 0);
    // 0x800C75E4: andi        $v0, $a1, 0xFF
    ctx->r2 = ctx->r5 & 0XFF;
    // 0x800C75E8: sll         $v1, $v0, 2
    ctx->r3 = S32(ctx->r2 << 2);
    // 0x800C75EC: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x800C75F0: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x800C75F4: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x800C75F8: sll         $v1, $v1, 3
    ctx->r3 = S32(ctx->r3 << 3);
    // 0x800C75FC: addu        $v1, $s1, $v1
    ctx->r3 = ADD32(ctx->r17, ctx->r3);
    // 0x800C7600: sw          $a2, 0x58($v1)
    MEM_W(0X58, ctx->r3) = ctx->r6;
    // 0x800C7604: lw          $v0, 0x34($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X34);
    // 0x800C7608: sh          $a3, 0x64($v1)
    MEM_H(0X64, ctx->r3) = ctx->r7;
    // 0x800C760C: sw          $v0, 0x68($v1)
    MEM_W(0X68, ctx->r3) = ctx->r2;
    // 0x800C7610: andi        $v1, $s2, 0xFFFF
    ctx->r3 = ctx->r18 & 0XFFFF;
    // 0x800C7614: beq         $v1, $zero, L_800C763C
    if (ctx->r3 == 0) {
        // 0x800C7618: addu        $a0, $zero, $zero
        ctx->r4 = ADD32(0, 0);
            goto L_800C763C;
    }
    // 0x800C7618: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
L_800C761C:
    // 0x800C761C: lw          $v0, 0x34($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X34);
    // 0x800C7620: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x800C7624: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800C7628: sw          $v0, 0x34($s1)
    MEM_W(0X34, ctx->r17) = ctx->r2;
    // 0x800C762C: andi        $v0, $a0, 0xFF
    ctx->r2 = ctx->r4 & 0XFF;
    // 0x800C7630: sltu        $v0, $v0, $v1
    ctx->r2 = ctx->r2 < ctx->r3 ? 1 : 0;
    // 0x800C7634: bne         $v0, $zero, L_800C761C
    if (ctx->r2 != 0) {
        // 0x800C7638: nop
    
            goto L_800C761C;
    }
    // 0x800C7638: nop

L_800C763C:
    // 0x800C763C: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x800C7640: andi        $s0, $a1, 0xFF
    ctx->r16 = ctx->r5 & 0XFF;
    // 0x800C7644: jal         0x800C83E4
    // 0x800C7648: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    func_800C83E4(rdram, ctx);
        goto after_0;
    // 0x800C7648: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    after_0:
    // 0x800C764C: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x800C7650: bne         $v0, $zero, L_800C769C
    if (ctx->r2 != 0) {
        // 0x800C7654: addu        $a0, $s1, $zero
        ctx->r4 = ADD32(ctx->r17, 0);
            goto L_800C769C;
    }
    // 0x800C7654: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x800C7658: jal         0x800C8520
    // 0x800C765C: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    func_800C8520(rdram, ctx);
        goto after_1;
    // 0x800C765C: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    after_1:
    // 0x800C7660: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x800C7664: bne         $v0, $zero, L_800C769C
    if (ctx->r2 != 0) {
        // 0x800C7668: addu        $a0, $s1, $zero
        ctx->r4 = ADD32(ctx->r17, 0);
            goto L_800C769C;
    }
    // 0x800C7668: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x800C766C: jal         0x800C86C8
    // 0x800C7670: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    func_800C86C8(rdram, ctx);
        goto after_2;
    // 0x800C7670: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    after_2:
    // 0x800C7674: addiu       $v0, $s3, -0x11
    ctx->r2 = ADD32(ctx->r19, -0X11);
    // 0x800C7678: subu        $s3, $v0, $s2
    ctx->r19 = SUB32(ctx->r2, ctx->r18);
    // 0x800C767C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800C7680: lbu         $v1, 0x48($s1)
    ctx->r3 = MEM_BU(ctx->r17, 0X48);
    // 0x800C7684: sllv        $v0, $v0, $s0
    ctx->r2 = S32(ctx->r2 << (ctx->r16 & 31));
    // 0x800C7688: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x800C768C: andi        $v0, $s3, 0xFFFF
    ctx->r2 = ctx->r19 & 0XFFFF;
    // 0x800C7690: bne         $v0, $zero, L_800C7570
    if (ctx->r2 != 0) {
        // 0x800C7694: sb          $v1, 0x48($s1)
        MEM_B(0X48, ctx->r17) = ctx->r3;
            goto L_800C7570;
    }
    // 0x800C7694: sb          $v1, 0x48($s1)
    MEM_B(0X48, ctx->r17) = ctx->r3;
    // 0x800C7698: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_800C769C:
    // 0x800C769C: lw          $ra, 0x20($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X20);
    // 0x800C76A0: lw          $s3, 0x1C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X1C);
    // 0x800C76A4: lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X18);
    // 0x800C76A8: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x800C76AC: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x800C76B0: jr          $ra
    // 0x800C76B4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x800C76B4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void setObjectiveBoolean(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C7540: bne         $a0, $zero, L_800C7550
    if (ctx->r4 != 0) {
        // 0x800C7544: lui         $v0, 0x8014
        ctx->r2 = S32(0X8014 << 16);
            goto L_800C7550;
    }
    // 0x800C7544: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x800C7548: jr          $ra
    // 0x800C754C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x800C754C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800C7550:
    // 0x800C7550: addiu       $v0, $v0, -0x7760
    ctx->r2 = ADD32(ctx->r2, -0X7760);
    // 0x800C7554: addiu       $v1, $a0, -0x1
    ctx->r3 = ADD32(ctx->r4, -0X1);
    // 0x800C7558: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x800C755C: lbu         $v0, 0x0($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X0);
    // 0x800C7560: jr          $ra
    // 0x800C7564: sb          $a1, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r5;
    return;
    // 0x800C7564: sb          $a1, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r5;
;}
RECOMP_FUNC void setObjectiveBooleans(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C7568: lbu         $v0, 0x0($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X0);
    // 0x800C756C: beq         $v0, $zero, L_800C7594
    if (ctx->r2 == 0) {
        // 0x800C7570: lui         $v0, 0x8014
        ctx->r2 = S32(0X8014 << 16);
            goto L_800C7594;
    }
    // 0x800C7570: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x800C7574: addiu       $v1, $v0, -0x7760
    ctx->r3 = ADD32(ctx->r2, -0X7760);
    // 0x800C7578: lbu         $v0, 0x0($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X0);
    // 0x800C757C: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
L_800C7580:
    // 0x800C7580: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800C7584: sb          $a1, -0x1($v0)
    MEM_B(-0X1, ctx->r2) = ctx->r5;
    // 0x800C7588: lbu         $v0, 0x0($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X0);
    // 0x800C758C: bne         $v0, $zero, L_800C7580
    if (ctx->r2 != 0) {
        // 0x800C7590: addiu       $a0, $a0, 0x1
        ctx->r4 = ADD32(ctx->r4, 0X1);
            goto L_800C7580;
    }
    // 0x800C7590: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
L_800C7594:
    // 0x800C7594: jr          $ra
    // 0x800C7598: nop

    return;
    // 0x800C7598: nop

;}
RECOMP_FUNC void getObjectiveBoolean(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C759C: bne         $a0, $zero, L_800C75AC
    if (ctx->r4 != 0) {
        // 0x800C75A0: lui         $v0, 0x8014
        ctx->r2 = S32(0X8014 << 16);
            goto L_800C75AC;
    }
    // 0x800C75A0: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x800C75A4: jr          $ra
    // 0x800C75A8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x800C75A8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800C75AC:
    // 0x800C75AC: addiu       $v0, $v0, -0x7760
    ctx->r2 = ADD32(ctx->r2, -0X7760);
    // 0x800C75B0: addu        $v0, $a0, $v0
    ctx->r2 = ADD32(ctx->r4, ctx->r2);
    // 0x800C75B4: lbu         $v0, -0x1($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X1);
    // 0x800C75B8: jr          $ra
    // 0x800C75BC: nop

    return;
    // 0x800C75BC: nop

;}
RECOMP_FUNC void setObjectiveCount(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C75C0: bne         $a0, $zero, L_800C75D0
    if (ctx->r4 != 0) {
        // 0x800C75C4: lui         $v0, 0x8014
        ctx->r2 = S32(0X8014 << 16);
            goto L_800C75D0;
    }
    // 0x800C75C4: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x800C75C8: jr          $ra
    // 0x800C75CC: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    return;
    // 0x800C75CC: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_800C75D0:
    // 0x800C75D0: addiu       $v0, $v0, -0x7FA0
    ctx->r2 = ADD32(ctx->r2, -0X7FA0);
    // 0x800C75D4: addiu       $v1, $a0, -0x1
    ctx->r3 = ADD32(ctx->r4, -0X1);
    // 0x800C75D8: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x800C75DC: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x800C75E0: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x800C75E4: jr          $ra
    // 0x800C75E8: sw          $a1, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r5;
    return;
    // 0x800C75E8: sw          $a1, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r5;
;}
RECOMP_FUNC void increaseObjectiveCount(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C75EC: bne         $a0, $zero, L_800C75FC
    if (ctx->r4 != 0) {
        // 0x800C75F0: lui         $v0, 0x8014
        ctx->r2 = S32(0X8014 << 16);
            goto L_800C75FC;
    }
    // 0x800C75F0: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x800C75F4: jr          $ra
    // 0x800C75F8: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    return;
    // 0x800C75F8: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_800C75FC:
    // 0x800C75FC: addiu       $v0, $v0, -0x7FA0
    ctx->r2 = ADD32(ctx->r2, -0X7FA0);
    // 0x800C7600: addiu       $v1, $a0, -0x1
    ctx->r3 = ADD32(ctx->r4, -0X1);
    // 0x800C7604: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x800C7608: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x800C760C: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x800C7610: addu        $v0, $v0, $a1
    ctx->r2 = ADD32(ctx->r2, ctx->r5);
    // 0x800C7614: jr          $ra
    // 0x800C7618: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    return;
    // 0x800C7618: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
;}
RECOMP_FUNC void getObjectiveCount(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C761C: bne         $a0, $zero, L_800C762C
    if (ctx->r4 != 0) {
        // 0x800C7620: lui         $v1, 0x8014
        ctx->r3 = S32(0X8014 << 16);
            goto L_800C762C;
    }
    // 0x800C7620: lui         $v1, 0x8014
    ctx->r3 = S32(0X8014 << 16);
    // 0x800C7624: jr          $ra
    // 0x800C7628: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    return;
    // 0x800C7628: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_800C762C:
    // 0x800C762C: addiu       $v1, $v1, -0x7FA0
    ctx->r3 = ADD32(ctx->r3, -0X7FA0);
    // 0x800C7630: addiu       $v0, $a0, -0x1
    ctx->r2 = ADD32(ctx->r4, -0X1);
    // 0x800C7634: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800C7638: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800C763C: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x800C7640: jr          $ra
    // 0x800C7644: nop

    return;
    // 0x800C7644: nop

;}
RECOMP_FUNC void func_800C7648(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C7648: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x800C764C: addiu       $v0, $v0, -0x6608
    ctx->r2 = ADD32(ctx->r2, -0X6608);
    // 0x800C7650: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // 0x800C7654: lbu         $v0, 0x0($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X0);
    // 0x800C7658: jr          $ra
    // 0x800C765C: sb          $a1, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r5;
    return;
    // 0x800C765C: sb          $a1, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r5;
;}
RECOMP_FUNC void setObjectiveHiddenFlag(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C7660: addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
    // 0x800C7664: sltiu       $v0, $a1, 0x8
    ctx->r2 = ctx->r5 < 0X8 ? 1 : 0;
    // 0x800C7668: beq         $v0, $zero, L_800C76A8
    if (ctx->r2 == 0) {
        // 0x800C766C: lui         $v0, 0x8013
        ctx->r2 = S32(0X8013 << 16);
            goto L_800C76A8;
    }
    // 0x800C766C: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800C7670: beq         $a0, $zero, L_800C7690
    if (ctx->r4 == 0) {
        // 0x800C7674: addiu       $a2, $v0, 0xB10
        ctx->r6 = ADD32(ctx->r2, 0XB10);
            goto L_800C7690;
    }
    // 0x800C7674: addiu       $a2, $v0, 0xB10
    ctx->r6 = ADD32(ctx->r2, 0XB10);
    // 0x800C7678: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800C767C: lbu         $v1, 0x6($a2)
    ctx->r3 = MEM_BU(ctx->r6, 0X6);
    // 0x800C7680: sllv        $v0, $v0, $a1
    ctx->r2 = S32(ctx->r2 << (ctx->r5 & 31));
    // 0x800C7684: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x800C7688: jr          $ra
    // 0x800C768C: sb          $v1, 0x6($a2)
    MEM_B(0X6, ctx->r6) = ctx->r3;
    return;
    // 0x800C768C: sb          $v1, 0x6($a2)
    MEM_B(0X6, ctx->r6) = ctx->r3;
L_800C7690:
    // 0x800C7690: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800C7694: sllv        $v0, $v0, $a1
    ctx->r2 = S32(ctx->r2 << (ctx->r5 & 31));
    // 0x800C7698: lbu         $v1, 0x6($a2)
    ctx->r3 = MEM_BU(ctx->r6, 0X6);
    // 0x800C769C: nor         $v0, $zero, $v0
    ctx->r2 = ~(0 | ctx->r2);
    // 0x800C76A0: and         $v1, $v1, $v0
    ctx->r3 = ctx->r3 & ctx->r2;
    // 0x800C76A4: sb          $v1, 0x6($a2)
    MEM_B(0X6, ctx->r6) = ctx->r3;
L_800C76A8:
    // 0x800C76A8: jr          $ra
    // 0x800C76AC: nop

    return;
    // 0x800C76AC: nop

;}
RECOMP_FUNC void activateObjectiveCompleteFlag(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C76B0: addiu       $a1, $a0, -0x1
    ctx->r5 = ADD32(ctx->r4, -0X1);
    // 0x800C76B4: sltiu       $v0, $a1, 0x8
    ctx->r2 = ctx->r5 < 0X8 ? 1 : 0;
    // 0x800C76B8: beq         $v0, $zero, L_800C76D8
    if (ctx->r2 == 0) {
        // 0x800C76BC: lui         $v0, 0x8013
        ctx->r2 = S32(0X8013 << 16);
            goto L_800C76D8;
    }
    // 0x800C76BC: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800C76C0: addiu       $v0, $v0, 0xB10
    ctx->r2 = ADD32(ctx->r2, 0XB10);
    // 0x800C76C4: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x800C76C8: lbu         $a0, 0x5($v0)
    ctx->r4 = MEM_BU(ctx->r2, 0X5);
    // 0x800C76CC: sllv        $v1, $v1, $a1
    ctx->r3 = S32(ctx->r3 << (ctx->r5 & 31));
    // 0x800C76D0: or          $a0, $a0, $v1
    ctx->r4 = ctx->r4 | ctx->r3;
    // 0x800C76D4: sb          $a0, 0x5($v0)
    MEM_B(0X5, ctx->r2) = ctx->r4;
L_800C76D8:
    // 0x800C76D8: jr          $ra
    // 0x800C76DC: nop

    return;
    // 0x800C76DC: nop

;}
RECOMP_FUNC void paserJfifSOSMarker(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C76B8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800C76BC: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x800C76C0: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x800C76C4: sw          $ra, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r31;
    // 0x800C76C8: sw          $s3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r19;
    // 0x800C76CC: sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // 0x800C76D0: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x800C76D4: lw          $v0, 0x34($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X34);
    // 0x800C76D8: addiu       $v1, $v0, 0x2
    ctx->r3 = ADD32(ctx->r2, 0X2);
    // 0x800C76DC: sw          $v1, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->r3;
    // 0x800C76E0: lbu         $s3, 0x2($v0)
    ctx->r19 = MEM_BU(ctx->r2, 0X2);
    // 0x800C76E4: addiu       $v0, $v0, 0x3
    ctx->r2 = ADD32(ctx->r2, 0X3);
    // 0x800C76E8: sw          $v0, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->r2;
    // 0x800C76EC: lbu         $v0, 0x4C($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X4C);
    // 0x800C76F0: andi        $v1, $s3, 0xFF
    ctx->r3 = ctx->r19 & 0XFF;
    // 0x800C76F4: bne         $v1, $v0, L_800C7954
    if (ctx->r3 != ctx->r2) {
        // 0x800C76F8: addiu       $v0, $zero, 0xC
        ctx->r2 = ADD32(0, 0XC);
            goto L_800C7954;
    }
    // 0x800C76F8: addiu       $v0, $zero, 0xC
    ctx->r2 = ADD32(0, 0XC);
    // 0x800C76FC: beq         $v1, $zero, L_800C78E0
    if (ctx->r3 == 0) {
        // 0x800C7700: addu        $s2, $zero, $zero
        ctx->r18 = ADD32(0, 0);
            goto L_800C78E0;
    }
    // 0x800C7700: addu        $s2, $zero, $zero
    ctx->r18 = ADD32(0, 0);
    // 0x800C7704: andi        $a1, $s2, 0xFF
    ctx->r5 = ctx->r18 & 0XFF;
L_800C7708:
    // 0x800C7708: lw          $a0, 0x34($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X34);
    // 0x800C770C: addiu       $v0, $a1, 0x1
    ctx->r2 = ADD32(ctx->r5, 0X1);
    // 0x800C7710: lbu         $v1, 0x0($a0)
    ctx->r3 = MEM_BU(ctx->r4, 0X0);
    // 0x800C7714: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x800C7718: andi        $v1, $v1, 0xFF
    ctx->r3 = ctx->r3 & 0XFF;
    // 0x800C771C: bne         $v1, $v0, L_800C792C
    if (ctx->r3 != ctx->r2) {
        // 0x800C7720: sw          $a0, 0x34($s0)
        MEM_W(0X34, ctx->r16) = ctx->r4;
            goto L_800C792C;
    }
    // 0x800C7720: sw          $a0, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->r4;
    // 0x800C7724: lbu         $v1, 0x0($a0)
    ctx->r3 = MEM_BU(ctx->r4, 0X0);
    // 0x800C7728: addiu       $v0, $a0, 0x1
    ctx->r2 = ADD32(ctx->r4, 0X1);
    // 0x800C772C: sw          $v0, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->r2;
    // 0x800C7730: sll         $v0, $a1, 1
    ctx->r2 = S32(ctx->r5 << 1);
    // 0x800C7734: addu        $v0, $v0, $a1
    ctx->r2 = ADD32(ctx->r2, ctx->r5);
    // 0x800C7738: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800C773C: subu        $v0, $v0, $a1
    ctx->r2 = SUB32(ctx->r2, ctx->r5);
    // 0x800C7740: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800C7744: addu        $s1, $s0, $v0
    ctx->r17 = ADD32(ctx->r16, ctx->r2);
    // 0x800C7748: andi        $v0, $v1, 0xFF
    ctx->r2 = ctx->r3 & 0XFF;
    // 0x800C774C: srl         $v0, $v0, 4
    ctx->r2 = S32(U32(ctx->r2) >> 4);
    // 0x800C7750: andi        $v1, $v1, 0xF
    ctx->r3 = ctx->r3 & 0XF;
    // 0x800C7754: sb          $v0, 0x6FC($s1)
    MEM_B(0X6FC, ctx->r17) = ctx->r2;
    // 0x800C7758: sb          $v1, 0x6FD($s1)
    MEM_B(0X6FD, ctx->r17) = ctx->r3;
    // 0x800C775C: lbu         $a0, 0x48($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X48);
    // 0x800C7760: srav        $v0, $a0, $v0
    ctx->r2 = S32(SIGNED(ctx->r4) >> (ctx->r2 & 31));
    // 0x800C7764: andi        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 & 0X1;
    // 0x800C7768: beq         $v0, $zero, L_800C7934
    if (ctx->r2 == 0) {
        // 0x800C776C: addiu       $v0, $v1, 0x1
        ctx->r2 = ADD32(ctx->r3, 0X1);
            goto L_800C7934;
    }
    // 0x800C776C: addiu       $v0, $v1, 0x1
    ctx->r2 = ADD32(ctx->r3, 0X1);
    // 0x800C7770: srav        $v0, $a0, $v0
    ctx->r2 = S32(SIGNED(ctx->r4) >> (ctx->r2 & 31));
    // 0x800C7774: andi        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 & 0X1;
    // 0x800C7778: beq         $v0, $zero, L_800C7954
    if (ctx->r2 == 0) {
        // 0x800C777C: addiu       $v0, $zero, 0xF
        ctx->r2 = ADD32(0, 0XF);
            goto L_800C7954;
    }
    // 0x800C777C: addiu       $v0, $zero, 0xF
    ctx->r2 = ADD32(0, 0XF);
    // 0x800C7780: lhu         $v0, 0x0($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X0);
    // 0x800C7784: lhu         $v1, 0x4($s0)
    ctx->r3 = MEM_HU(ctx->r16, 0X4);
    // 0x800C7788: lhu         $a0, 0x2($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X2);
    // 0x800C778C: andi        $v1, $v1, 0x80
    ctx->r3 = ctx->r3 & 0X80;
    // 0x800C7790: sh          $v0, 0x40($s0)
    MEM_H(0X40, ctx->r16) = ctx->r2;
    // 0x800C7794: beq         $v1, $zero, L_800C782C
    if (ctx->r3 == 0) {
        // 0x800C7798: sh          $a0, 0x42($s0)
        MEM_H(0X42, ctx->r16) = ctx->r4;
            goto L_800C782C;
    }
    // 0x800C7798: sh          $a0, 0x42($s0)
    MEM_H(0X42, ctx->r16) = ctx->r4;
    // 0x800C779C: lhu         $v1, 0x3C($s0)
    ctx->r3 = MEM_HU(ctx->r16, 0X3C);
    // 0x800C77A0: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x800C77A4: mult        $v1, $v0
    result = S64(S32(ctx->r3)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800C77A8: mflo        $a2
    ctx->r6 = lo;
    // 0x800C77AC: lhu         $v1, 0x28($s0)
    ctx->r3 = MEM_HU(ctx->r16, 0X28);
    // 0x800C77B0: nop

    // 0x800C77B4: div         $zero, $a2, $v1
    lo = S32(S64(S32(ctx->r6)) / S64(S32(ctx->r3))); hi = S32(S64(S32(ctx->r6)) % S64(S32(ctx->r3)));
    // 0x800C77B8: bne         $v1, $zero, L_800C77C4
    if (ctx->r3 != 0) {
        // 0x800C77BC: nop
    
            goto L_800C77C4;
    }
    // 0x800C77BC: nop

    // 0x800C77C0: break       7
    do_break(2148300736);
L_800C77C4:
    // 0x800C77C4: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800C77C8: bne         $v1, $at, L_800C77DC
    if (ctx->r3 != ctx->r1) {
        // 0x800C77CC: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800C77DC;
    }
    // 0x800C77CC: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800C77D0: bne         $a2, $at, L_800C77DC
    if (ctx->r6 != ctx->r1) {
        // 0x800C77D4: nop
    
            goto L_800C77DC;
    }
    // 0x800C77D4: nop

    // 0x800C77D8: break       6
    do_break(2148300760);
L_800C77DC:
    // 0x800C77DC: mflo        $v1
    ctx->r3 = lo;
    // 0x800C77E0: lhu         $a0, 0x3E($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X3E);
    // 0x800C77E4: lhu         $v0, 0x2($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X2);
    // 0x800C77E8: mult        $a0, $v0
    result = S64(S32(ctx->r4)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800C77EC: mflo        $a2
    ctx->r6 = lo;
    // 0x800C77F0: lhu         $v0, 0x2A($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X2A);
    // 0x800C77F4: nop

    // 0x800C77F8: div         $zero, $a2, $v0
    lo = S32(S64(S32(ctx->r6)) / S64(S32(ctx->r2))); hi = S32(S64(S32(ctx->r6)) % S64(S32(ctx->r2)));
    // 0x800C77FC: bne         $v0, $zero, L_800C7808
    if (ctx->r2 != 0) {
        // 0x800C7800: nop
    
            goto L_800C7808;
    }
    // 0x800C7800: nop

    // 0x800C7804: break       7
    do_break(2148300804);
L_800C7808:
    // 0x800C7808: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800C780C: bne         $v0, $at, L_800C7820
    if (ctx->r2 != ctx->r1) {
        // 0x800C7810: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800C7820;
    }
    // 0x800C7810: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800C7814: bne         $a2, $at, L_800C7820
    if (ctx->r6 != ctx->r1) {
        // 0x800C7818: nop
    
            goto L_800C7820;
    }
    // 0x800C7818: nop

    // 0x800C781C: break       6
    do_break(2148300828);
L_800C7820:
    // 0x800C7820: mflo        $v0
    ctx->r2 = lo;
    // 0x800C7824: sh          $v1, 0x40($s0)
    MEM_H(0X40, ctx->r16) = ctx->r3;
    // 0x800C7828: sh          $v0, 0x42($s0)
    MEM_H(0X42, ctx->r16) = ctx->r2;
L_800C782C:
    // 0x800C782C: lhu         $a0, 0x42($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X42);
    // 0x800C7830: lhu         $a1, 0x7D4($s0)
    ctx->r5 = MEM_HU(ctx->r16, 0X7D4);
    // 0x800C7834: addiu       $v0, $a0, -0x1
    ctx->r2 = ADD32(ctx->r4, -0X1);
    // 0x800C7838: addu        $v0, $v0, $a1
    ctx->r2 = ADD32(ctx->r2, ctx->r5);
    // 0x800C783C: div         $zero, $v0, $a1
    lo = S32(S64(S32(ctx->r2)) / S64(S32(ctx->r5))); hi = S32(S64(S32(ctx->r2)) % S64(S32(ctx->r5)));
    // 0x800C7840: bne         $a1, $zero, L_800C784C
    if (ctx->r5 != 0) {
        // 0x800C7844: nop
    
            goto L_800C784C;
    }
    // 0x800C7844: nop

    // 0x800C7848: break       7
    do_break(2148300872);
L_800C784C:
    // 0x800C784C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800C7850: bne         $a1, $at, L_800C7864
    if (ctx->r5 != ctx->r1) {
        // 0x800C7854: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800C7864;
    }
    // 0x800C7854: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800C7858: bne         $v0, $at, L_800C7864
    if (ctx->r2 != ctx->r1) {
        // 0x800C785C: nop
    
            goto L_800C7864;
    }
    // 0x800C785C: nop

    // 0x800C7860: break       6
    do_break(2148300896);
L_800C7864:
    // 0x800C7864: mflo        $v0
    ctx->r2 = lo;
    // 0x800C7868: nop

    // 0x800C786C: nop

    // 0x800C7870: divu        $zero, $a0, $a1
    lo = S32(U32(ctx->r4) / U32(ctx->r5)); hi = S32(U32(ctx->r4) % U32(ctx->r5));
    // 0x800C7874: bne         $a1, $zero, L_800C7880
    if (ctx->r5 != 0) {
        // 0x800C7878: nop
    
            goto L_800C7880;
    }
    // 0x800C7878: nop

    // 0x800C787C: break       7
    do_break(2148300924);
L_800C7880:
    // 0x800C7880: mfhi        $v1
    ctx->r3 = hi;
    // 0x800C7884: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x800C7888: sltu        $v1, $zero, $v1
    ctx->r3 = 0 < ctx->r3 ? 1 : 0;
    // 0x800C788C: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800C7890: mult        $v0, $a1
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800C7894: lbu         $v0, 0x4B($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X4B);
    // 0x800C7898: lbu         $v1, 0x6FA($s1)
    ctx->r3 = MEM_BU(ctx->r17, 0X6FA);
    // 0x800C789C: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x800C78A0: mflo        $a0
    ctx->r4 = lo;
    // 0x800C78A4: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    // 0x800C78A8: srav        $a0, $a0, $v0
    ctx->r4 = S32(SIGNED(ctx->r4) >> (ctx->r2 & 31));
    // 0x800C78AC: lhu         $v0, 0x702($s1)
    ctx->r2 = MEM_HU(ctx->r17, 0X702);
    // 0x800C78B0: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    // 0x800C78B4: mult        $v0, $a0
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800C78B8: lhu         $a1, 0xE($s0)
    ctx->r5 = MEM_HU(ctx->r16, 0XE);
    // 0x800C78BC: mflo        $a0
    ctx->r4 = lo;
    // 0x800C78C0: jal         0x80001ACC
    // 0x800C78C4: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    rs_malloc(rdram, ctx);
        goto after_0;
    // 0x800C78C4: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    after_0:
    // 0x800C78C8: sw          $v0, 0x708($s1)
    MEM_W(0X708, ctx->r17) = ctx->r2;
    // 0x800C78CC: andi        $v0, $s2, 0xFF
    ctx->r2 = ctx->r18 & 0XFF;
    // 0x800C78D0: andi        $v1, $s3, 0xFF
    ctx->r3 = ctx->r19 & 0XFF;
    // 0x800C78D4: sltu        $v0, $v0, $v1
    ctx->r2 = ctx->r2 < ctx->r3 ? 1 : 0;
    // 0x800C78D8: bne         $v0, $zero, L_800C7708
    if (ctx->r2 != 0) {
        // 0x800C78DC: andi        $a1, $s2, 0xFF
        ctx->r5 = ctx->r18 & 0XFF;
            goto L_800C7708;
    }
    // 0x800C78DC: andi        $a1, $s2, 0xFF
    ctx->r5 = ctx->r18 & 0XFF;
L_800C78E0:
    // 0x800C78E0: lw          $v0, 0x34($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X34);
    // 0x800C78E4: lbu         $a0, 0x0($v0)
    ctx->r4 = MEM_BU(ctx->r2, 0X0);
    // 0x800C78E8: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800C78EC: sw          $v0, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->r2;
    // 0x800C78F0: lbu         $a1, 0x0($v0)
    ctx->r5 = MEM_BU(ctx->r2, 0X0);
    // 0x800C78F4: addiu       $v1, $v0, 0x1
    ctx->r3 = ADD32(ctx->r2, 0X1);
    // 0x800C78F8: sw          $v1, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->r3;
    // 0x800C78FC: lbu         $a2, 0x1($v0)
    ctx->r6 = MEM_BU(ctx->r2, 0X1);
    // 0x800C7900: addiu       $v0, $v0, 0x2
    ctx->r2 = ADD32(ctx->r2, 0X2);
    // 0x800C7904: andi        $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 & 0XFF;
    // 0x800C7908: bne         $a0, $zero, L_800C792C
    if (ctx->r4 != 0) {
        // 0x800C790C: sw          $v0, 0x34($s0)
        MEM_W(0X34, ctx->r16) = ctx->r2;
            goto L_800C792C;
    }
    // 0x800C790C: sw          $v0, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->r2;
    // 0x800C7910: andi        $v1, $a1, 0xFF
    ctx->r3 = ctx->r5 & 0XFF;
    // 0x800C7914: addiu       $v0, $zero, 0x3F
    ctx->r2 = ADD32(0, 0X3F);
    // 0x800C7918: bne         $v1, $v0, L_800C7954
    if (ctx->r3 != ctx->r2) {
        // 0x800C791C: addiu       $v0, $zero, 0xE
        ctx->r2 = ADD32(0, 0XE);
            goto L_800C7954;
    }
    // 0x800C791C: addiu       $v0, $zero, 0xE
    ctx->r2 = ADD32(0, 0XE);
    // 0x800C7920: andi        $v0, $a2, 0xFF
    ctx->r2 = ctx->r6 & 0XFF;
    // 0x800C7924: beq         $v0, $zero, L_800C793C
    if (ctx->r2 == 0) {
        // 0x800C7928: nop
    
            goto L_800C793C;
    }
    // 0x800C7928: nop

L_800C792C:
    // 0x800C792C: j           L_800C7954
    // 0x800C7930: addiu       $v0, $zero, 0xE
    ctx->r2 = ADD32(0, 0XE);
        goto L_800C7954;
    // 0x800C7930: addiu       $v0, $zero, 0xE
    ctx->r2 = ADD32(0, 0XE);
L_800C7934:
    // 0x800C7934: j           L_800C7954
    // 0x800C7938: addiu       $v0, $zero, 0xF
    ctx->r2 = ADD32(0, 0XF);
        goto L_800C7954;
    // 0x800C7938: addiu       $v0, $zero, 0xF
    ctx->r2 = ADD32(0, 0XF);
L_800C793C:
    // 0x800C793C: jal         0x800C804C
    // 0x800C7940: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_800C804C(rdram, ctx);
        goto after_1;
    // 0x800C7940: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_1:
    // 0x800C7944: andi        $v1, $v0, 0xFF
    ctx->r3 = ctx->r2 & 0XFF;
    // 0x800C7948: bne         $v1, $zero, L_800C7954
    if (ctx->r3 != 0) {
        // 0x800C794C: addu        $v0, $v1, $zero
        ctx->r2 = ADD32(ctx->r3, 0);
            goto L_800C7954;
    }
    // 0x800C794C: addu        $v0, $v1, $zero
    ctx->r2 = ADD32(ctx->r3, 0);
    // 0x800C7950: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_800C7954:
    // 0x800C7954: lw          $ra, 0x20($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X20);
    // 0x800C7958: lw          $s3, 0x1C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X1C);
    // 0x800C795C: lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X18);
    // 0x800C7960: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x800C7964: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x800C7968: jr          $ra
    // 0x800C796C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x800C796C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void getObjectiveTimer(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C76E0: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800C76E4: addiu       $v0, $v0, -0x3608
    ctx->r2 = ADD32(ctx->r2, -0X3608);
    // 0x800C76E8: sll         $a0, $a0, 2
    ctx->r4 = S32(ctx->r4 << 2);
    // 0x800C76EC: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // 0x800C76F0: lwc1        $f0, 0x0($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X0);
    // 0x800C76F4: jr          $ra
    // 0x800C76F8: nop

    return;
    // 0x800C76F8: nop

;}
RECOMP_FUNC void setObjectiveTimer(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C76FC: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800C7700: addiu       $v0, $v0, -0x3608
    ctx->r2 = ADD32(ctx->r2, -0X3608);
    // 0x800C7704: sll         $a0, $a0, 2
    ctx->r4 = S32(ctx->r4 << 2);
    // 0x800C7708: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // 0x800C770C: lwc1        $f0, 0x0($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X0);
    // 0x800C7710: jr          $ra
    // 0x800C7714: sw          $a1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r5;
    return;
    // 0x800C7714: sw          $a1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r5;
;}
