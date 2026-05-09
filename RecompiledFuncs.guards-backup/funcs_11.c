#include "recomp.h"
#include "funcs.h"
#include <stdio.h>

RECOMP_FUNC void func_8004D2B0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8004D2B0: addiu       $sp, $sp, -0xD0
    ctx->r29 = ADD32(ctx->r29, -0XD0);
    // 0x8004D2B4: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8004D2B8: sdc1        $f20, 0xC0($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0XC0, ctx->r29);
    // 0x8004D2BC: mtc1        $a1, $f20
    ctx->f20.u32l = ctx->r5;
    // 0x8004D2C0: lbu         $v0, 0x7CF4($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7CF4);
    // 0x8004D2C4: sdc1        $f22, 0xC8($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0XC8, ctx->r29);
    // 0x8004D2C8: mtc1        $zero, $f22
    ctx->f22.u32l = 0;
    // 0x8004D2CC: sw          $s2, 0xB8($sp)
    MEM_W(0XB8, ctx->r29) = ctx->r18;
    // 0x8004D2D0: addu        $s2, $a0, $zero
    ctx->r18 = ADD32(ctx->r4, 0);
    // 0x8004D2D4: sw          $ra, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->r31;
    // 0x8004D2D8: sw          $s1, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->r17;
    // 0x8004D2DC: bne         $v0, $zero, L_8004DBB0
    if (ctx->r2 != 0) {
        // 0x8004D2E0: sw          $s0, 0xB0($sp)
        MEM_W(0XB0, ctx->r29) = ctx->r16;
            goto L_8004DBB0;
    }
    // 0x8004D2E0: sw          $s0, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->r16;
    // 0x8004D2E4: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x8004D2E8: lbu         $v0, -0x77C8($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X77C8);
    // 0x8004D2EC: beq         $v0, $zero, L_8004D300
    if (ctx->r2 == 0) {
        // 0x8004D2F0: addiu       $v0, $zero, 0x4
        ctx->r2 = ADD32(0, 0X4);
            goto L_8004D300;
    }
    // 0x8004D2F0: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // 0x8004D2F4: lhu         $v1, 0x2($s2)
    ctx->r3 = MEM_HU(ctx->r18, 0X2);
    // 0x8004D2F8: bne         $v1, $v0, L_8004DBB0
    if (ctx->r3 != ctx->r2) {
        // 0x8004D2FC: nop
    
            goto L_8004DBB0;
    }
    // 0x8004D2FC: nop

L_8004D300:
    // 0x8004D300: lw          $t0, 0x10($s2)
    ctx->r8 = MEM_W(ctx->r18, 0X10);
    // 0x8004D304: lw          $t1, 0x14($s2)
    ctx->r9 = MEM_W(ctx->r18, 0X14);
    // 0x8004D308: lw          $t2, 0x18($s2)
    ctx->r10 = MEM_W(ctx->r18, 0X18);
    // 0x8004D30C: sw          $t0, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->r8;
    // 0x8004D310: sw          $t1, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->r9;
    // 0x8004D314: sw          $t2, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->r10;
    // 0x8004D318: lhu         $v1, 0x2($s2)
    ctx->r3 = MEM_HU(ctx->r18, 0X2);
    // 0x8004D31C: sltiu       $v0, $v1, 0x5
    ctx->r2 = ctx->r3 < 0X5 ? 1 : 0;
    // 0x8004D320: beq         $v0, $zero, L_8004D988
    if (ctx->r2 == 0) {
        // 0x8004D324: lui         $v0, 0x8004
        ctx->r2 = S32(0X8004 << 16);
            goto L_8004D988;
    }
    // 0x8004D324: lui         $v0, 0x8004
    ctx->r2 = S32(0X8004 << 16);
    // 0x8004D328: addiu       $v0, $v0, -0x5700
    ctx->r2 = ADD32(ctx->r2, -0X5700);
    // 0x8004D32C: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x8004D330: addu        $v1, $v1, $v0
    gpr jr_addend_8004D338 = ctx->r3;
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x8004D334: lw          $v0, 0x0($v1)
    ctx->r2 = ADD32(ctx->r3, 0X0);
    // 0x8004D338: jr          $v0
    // 0x8004D33C: nop

    switch (jr_addend_8004D338 >> 2) {
        case 0: goto L_8004D340; break;
        case 1: goto L_8004D388; break;
        case 2: goto L_8004D358; break;
        case 3: goto L_8004D4D4; break;
        case 4: goto L_8004D86C; break;
        default: switch_error(__func__, 0x8004D338, 0x8003A900);
    }
    // 0x8004D33C: nop

L_8004D340:
    // 0x8004D340: addiu       $a0, $s2, 0x28
    ctx->r4 = ADD32(ctx->r18, 0X28);
    // 0x8004D344: addiu       $a1, $s2, 0x10
    ctx->r5 = ADD32(ctx->r18, 0X10);
    // 0x8004D348: jal         0x800A9E70
    // 0x8004D34C: addiu       $a2, $s2, 0x1C
    ctx->r6 = ADD32(ctx->r18, 0X1C);
    func_800A9E70(rdram, ctx);
        goto after_0;
    // 0x8004D34C: addiu       $a2, $s2, 0x1C
    ctx->r6 = ADD32(ctx->r18, 0X1C);
    after_0:
    // 0x8004D350: j           L_8004D988
    // 0x8004D354: nop

        goto L_8004D988;
    // 0x8004D354: nop

L_8004D358:
    // 0x8004D358: addiu       $a0, $s2, 0x28
    ctx->r4 = ADD32(ctx->r18, 0X28);
    // 0x8004D35C: addiu       $a1, $s2, 0x10
    ctx->r5 = ADD32(ctx->r18, 0X10);
    // 0x8004D360: lw          $t0, 0x58($s2)
    ctx->r8 = MEM_W(ctx->r18, 0X58);
    // 0x8004D364: lw          $t1, 0x5C($s2)
    ctx->r9 = MEM_W(ctx->r18, 0X5C);
    // 0x8004D368: lw          $t2, 0x60($s2)
    ctx->r10 = MEM_W(ctx->r18, 0X60);
    // 0x8004D36C: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x8004D370: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    // 0x8004D374: sw          $t2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r10;
    // 0x8004D378: jal         0x800A9E70
    // 0x8004D37C: addiu       $a2, $s2, 0x1C
    ctx->r6 = ADD32(ctx->r18, 0X1C);
    func_800A9E70(rdram, ctx);
        goto after_1;
    // 0x8004D37C: addiu       $a2, $s2, 0x1C
    ctx->r6 = ADD32(ctx->r18, 0X1C);
    after_1:
    // 0x8004D380: j           L_8004D46C
    // 0x8004D384: nop

        goto L_8004D46C;
    // 0x8004D384: nop

L_8004D388:
    // 0x8004D388: lhu         $v0, 0x0($s2)
    ctx->r2 = MEM_HU(ctx->r18, 0X0);
    // 0x8004D38C: andi        $v0, $v0, 0x200
    ctx->r2 = ctx->r2 & 0X200;
    // 0x8004D390: beq         $v0, $zero, L_8004D3CC
    if (ctx->r2 == 0) {
        // 0x8004D394: addiu       $s1, $s2, 0x10
        ctx->r17 = ADD32(ctx->r18, 0X10);
            goto L_8004D3CC;
    }
    // 0x8004D394: addiu       $s1, $s2, 0x10
    ctx->r17 = ADD32(ctx->r18, 0X10);
    // 0x8004D398: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    // 0x8004D39C: addiu       $s0, $s2, 0x1C
    ctx->r16 = ADD32(ctx->r18, 0X1C);
    // 0x8004D3A0: lw          $a0, 0x70($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X70);
    // 0x8004D3A4: jal         0x800A9B80
    // 0x8004D3A8: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    func_800A9B80(rdram, ctx);
        goto after_2;
    // 0x8004D3A8: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    after_2:
    // 0x8004D3AC: addiu       $a0, $s2, 0x28
    ctx->r4 = ADD32(ctx->r18, 0X28);
    // 0x8004D3B0: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    // 0x8004D3B4: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    // 0x8004D3B8: sw          $zero, 0x20($s2)
    MEM_W(0X20, ctx->r18) = 0;
    // 0x8004D3BC: jal         0x800A9E70
    // 0x8004D3C0: sw          $zero, 0x24($s2)
    MEM_W(0X24, ctx->r18) = 0;
    func_800A9E70(rdram, ctx);
        goto after_3;
    // 0x8004D3C0: sw          $zero, 0x24($s2)
    MEM_W(0X24, ctx->r18) = 0;
    after_3:
    // 0x8004D3C4: j           L_8004D404
    // 0x8004D3C8: nop

        goto L_8004D404;
    // 0x8004D3C8: nop

L_8004D3CC:
    // 0x8004D3CC: lw          $v0, 0x70($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X70);
    // 0x8004D3D0: addiu       $v1, $s2, 0x28
    ctx->r3 = ADD32(ctx->r18, 0X28);
    // 0x8004D3D4: addiu       $a0, $v0, 0x30
    ctx->r4 = ADD32(ctx->r2, 0X30);
L_8004D3D8:
    // 0x8004D3D8: lw          $t0, 0x0($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X0);
    // 0x8004D3DC: lw          $t1, 0x4($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X4);
    // 0x8004D3E0: lw          $t2, 0x8($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X8);
    // 0x8004D3E4: lw          $t3, 0xC($v0)
    ctx->r11 = MEM_W(ctx->r2, 0XC);
    // 0x8004D3E8: sw          $t0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r8;
    // 0x8004D3EC: sw          $t1, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r9;
    // 0x8004D3F0: sw          $t2, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r10;
    // 0x8004D3F4: sw          $t3, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r11;
    // 0x8004D3F8: addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
    // 0x8004D3FC: bne         $v0, $a0, L_8004D3D8
    if (ctx->r2 != ctx->r4) {
        // 0x8004D400: addiu       $v1, $v1, 0x10
        ctx->r3 = ADD32(ctx->r3, 0X10);
            goto L_8004D3D8;
    }
    // 0x8004D400: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
L_8004D404:
    // 0x8004D404: lw          $v0, 0x90($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X90);
    // 0x8004D408: beq         $v0, $zero, L_8004D448
    if (ctx->r2 == 0) {
        // 0x8004D40C: addiu       $a0, $s2, 0x28
        ctx->r4 = ADD32(ctx->r18, 0X28);
            goto L_8004D448;
    }
    // 0x8004D40C: addiu       $a0, $s2, 0x28
    ctx->r4 = ADD32(ctx->r18, 0X28);
    // 0x8004D410: lw          $t0, 0x0($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X0);
    // 0x8004D414: lw          $t1, 0x4($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X4);
    // 0x8004D418: lw          $t2, 0x8($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X8);
    // 0x8004D41C: sw          $t0, 0x1C($s2)
    MEM_W(0X1C, ctx->r18) = ctx->r8;
    // 0x8004D420: sw          $t1, 0x20($s2)
    MEM_W(0X20, ctx->r18) = ctx->r9;
    // 0x8004D424: sw          $t2, 0x24($s2)
    MEM_W(0X24, ctx->r18) = ctx->r10;
    // 0x8004D428: lw          $v0, 0x70($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X70);
    // 0x8004D42C: lwc1        $f0, 0x24($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X24);
    // 0x8004D430: swc1        $f0, 0x10($s2)
    MEM_W(0X10, ctx->r18) = ctx->f0.u32l;
    // 0x8004D434: lwc1        $f0, 0x28($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X28);
    // 0x8004D438: swc1        $f0, 0x14($s2)
    MEM_W(0X14, ctx->r18) = ctx->f0.u32l;
    // 0x8004D43C: lwc1        $f0, 0x2C($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X2C);
    // 0x8004D440: j           L_8004D454
    // 0x8004D444: swc1        $f0, 0x18($s2)
    MEM_W(0X18, ctx->r18) = ctx->f0.u32l;
        goto L_8004D454;
    // 0x8004D444: swc1        $f0, 0x18($s2)
    MEM_W(0X18, ctx->r18) = ctx->f0.u32l;
L_8004D448:
    // 0x8004D448: addiu       $a1, $s2, 0x10
    ctx->r5 = ADD32(ctx->r18, 0X10);
    // 0x8004D44C: jal         0x800A9B80
    // 0x8004D450: addiu       $a2, $s2, 0x1C
    ctx->r6 = ADD32(ctx->r18, 0X1C);
    func_800A9B80(rdram, ctx);
        goto after_4;
    // 0x8004D450: addiu       $a2, $s2, 0x1C
    ctx->r6 = ADD32(ctx->r18, 0X1C);
    after_4:
L_8004D454:
    // 0x8004D454: lw          $t0, 0x58($s2)
    ctx->r8 = MEM_W(ctx->r18, 0X58);
    // 0x8004D458: lw          $t1, 0x5C($s2)
    ctx->r9 = MEM_W(ctx->r18, 0X5C);
    // 0x8004D45C: lw          $t2, 0x60($s2)
    ctx->r10 = MEM_W(ctx->r18, 0X60);
    // 0x8004D460: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x8004D464: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    // 0x8004D468: sw          $t2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r10;
L_8004D46C:
    // 0x8004D46C: lwc1        $f0, 0x10($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X10);
    // 0x8004D470: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x8004D474: c.eq.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl == ctx->f2.fl;
    // 0x8004D478: nop

    // 0x8004D47C: bc1f        L_8004D4AC
    if (!c1cs) {
        // 0x8004D480: addiu       $a0, $s2, 0x28
        ctx->r4 = ADD32(ctx->r18, 0X28);
            goto L_8004D4AC;
    }
    // 0x8004D480: addiu       $a0, $s2, 0x28
    ctx->r4 = ADD32(ctx->r18, 0X28);
    // 0x8004D484: lwc1        $f0, 0x14($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X14);
    // 0x8004D488: c.eq.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl == ctx->f2.fl;
    // 0x8004D48C: nop

    // 0x8004D490: bc1f        L_8004D4B0
    if (!c1cs) {
        // 0x8004D494: addiu       $a1, $sp, 0x10
        ctx->r5 = ADD32(ctx->r29, 0X10);
            goto L_8004D4B0;
    }
    // 0x8004D494: addiu       $a1, $sp, 0x10
    ctx->r5 = ADD32(ctx->r29, 0X10);
    // 0x8004D498: lwc1        $f0, 0x18($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X18);
    // 0x8004D49C: c.eq.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl == ctx->f2.fl;
    // 0x8004D4A0: nop

    // 0x8004D4A4: bc1t        L_8004D988
    if (c1cs) {
        // 0x8004D4A8: nop
    
            goto L_8004D988;
    }
    // 0x8004D4A8: nop

L_8004D4AC:
    // 0x8004D4AC: addiu       $a1, $sp, 0x10
    ctx->r5 = ADD32(ctx->r29, 0X10);
L_8004D4B0:
    // 0x8004D4B0: jal         0x800193E8
    // 0x8004D4B4: addiu       $a2, $sp, 0x20
    ctx->r6 = ADD32(ctx->r29, 0X20);
    func_800193E8(rdram, ctx);
        goto after_5;
    // 0x8004D4B4: addiu       $a2, $sp, 0x20
    ctx->r6 = ADD32(ctx->r29, 0X20);
    after_5:
    // 0x8004D4B8: lwc1        $f0, 0x20($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X20);
    // 0x8004D4BC: swc1        $f0, 0x4C($s2)
    MEM_W(0X4C, ctx->r18) = ctx->f0.u32l;
    // 0x8004D4C0: lwc1        $f0, 0x24($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X24);
    // 0x8004D4C4: swc1        $f0, 0x50($s2)
    MEM_W(0X50, ctx->r18) = ctx->f0.u32l;
    // 0x8004D4C8: lwc1        $f0, 0x28($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X28);
    // 0x8004D4CC: j           L_8004D988
    // 0x8004D4D0: swc1        $f0, 0x54($s2)
    MEM_W(0X54, ctx->r18) = ctx->f0.u32l;
        goto L_8004D988;
    // 0x8004D4D0: swc1        $f0, 0x54($s2)
    MEM_W(0X54, ctx->r18) = ctx->f0.u32l;
L_8004D4D4:
    // 0x8004D4D4: lw          $v0, 0x70($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X70);
    // 0x8004D4D8: addiu       $v1, $sp, 0x40
    ctx->r3 = ADD32(ctx->r29, 0X40);
    // 0x8004D4DC: addiu       $a0, $v0, 0x30
    ctx->r4 = ADD32(ctx->r2, 0X30);
L_8004D4E0:
    // 0x8004D4E0: lw          $t0, 0x0($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X0);
    // 0x8004D4E4: lw          $t1, 0x4($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X4);
    // 0x8004D4E8: lw          $t2, 0x8($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X8);
    // 0x8004D4EC: lw          $t3, 0xC($v0)
    ctx->r11 = MEM_W(ctx->r2, 0XC);
    // 0x8004D4F0: sw          $t0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r8;
    // 0x8004D4F4: sw          $t1, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r9;
    // 0x8004D4F8: sw          $t2, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r10;
    // 0x8004D4FC: sw          $t3, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r11;
    // 0x8004D500: addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
    // 0x8004D504: bne         $v0, $a0, L_8004D4E0
    if (ctx->r2 != ctx->r4) {
        // 0x8004D508: addiu       $v1, $v1, 0x10
        ctx->r3 = ADD32(ctx->r3, 0X10);
            goto L_8004D4E0;
    }
    // 0x8004D508: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
    // 0x8004D50C: lw          $t0, 0x58($s2)
    ctx->r8 = MEM_W(ctx->r18, 0X58);
    // 0x8004D510: lw          $t1, 0x5C($s2)
    ctx->r9 = MEM_W(ctx->r18, 0X5C);
    // 0x8004D514: lw          $t2, 0x60($s2)
    ctx->r10 = MEM_W(ctx->r18, 0X60);
    // 0x8004D518: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x8004D51C: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    // 0x8004D520: sw          $t2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r10;
    // 0x8004D524: lwc1        $f0, 0x10($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X10);
    // 0x8004D528: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x8004D52C: c.eq.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl == ctx->f2.fl;
    // 0x8004D530: nop

    // 0x8004D534: bc1f        L_8004D564
    if (!c1cs) {
        // 0x8004D538: addiu       $a0, $sp, 0x40
        ctx->r4 = ADD32(ctx->r29, 0X40);
            goto L_8004D564;
    }
    // 0x8004D538: addiu       $a0, $sp, 0x40
    ctx->r4 = ADD32(ctx->r29, 0X40);
    // 0x8004D53C: lwc1        $f0, 0x14($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X14);
    // 0x8004D540: c.eq.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl == ctx->f2.fl;
    // 0x8004D544: nop

    // 0x8004D548: bc1f        L_8004D564
    if (!c1cs) {
        // 0x8004D54C: nop
    
            goto L_8004D564;
    }
    // 0x8004D54C: nop

    // 0x8004D550: lwc1        $f0, 0x18($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X18);
    // 0x8004D554: c.eq.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl == ctx->f2.fl;
    // 0x8004D558: nop

    // 0x8004D55C: bc1t        L_8004D58C
    if (c1cs) {
        // 0x8004D560: nop
    
            goto L_8004D58C;
    }
    // 0x8004D560: nop

L_8004D564:
    // 0x8004D564: addiu       $a1, $sp, 0x10
    ctx->r5 = ADD32(ctx->r29, 0X10);
    // 0x8004D568: jal         0x800193E8
    // 0x8004D56C: addiu       $a2, $sp, 0x20
    ctx->r6 = ADD32(ctx->r29, 0X20);
    func_800193E8(rdram, ctx);
        goto after_6;
    // 0x8004D56C: addiu       $a2, $sp, 0x20
    ctx->r6 = ADD32(ctx->r29, 0X20);
    after_6:
    // 0x8004D570: lwc1        $f0, 0x20($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X20);
    // 0x8004D574: lwc1        $f2, 0x24($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X24);
    // 0x8004D578: lwc1        $f4, 0x28($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X28);
    // 0x8004D57C: swc1        $f0, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f0.u32l;
    // 0x8004D580: swc1        $f2, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f2.u32l;
    // 0x8004D584: j           L_8004D5A4
    // 0x8004D588: swc1        $f4, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->f4.u32l;
        goto L_8004D5A4;
    // 0x8004D588: swc1        $f4, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->f4.u32l;
L_8004D58C:
    // 0x8004D58C: lwc1        $f0, 0x64($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X64);
    // 0x8004D590: lwc1        $f2, 0x68($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X68);
    // 0x8004D594: lwc1        $f4, 0x6C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x8004D598: swc1        $f0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f0.u32l;
    // 0x8004D59C: swc1        $f2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f2.u32l;
    // 0x8004D5A0: swc1        $f4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f4.u32l;
L_8004D5A4:
    // 0x8004D5A4: lwc1        $f2, 0xA4($s2)
    ctx->f2.u32l = MEM_W(ctx->r18, 0XA4);
    // 0x8004D5A8: c.lt.s      $f2, $f20
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f2.fl < ctx->f20.fl;
    // 0x8004D5AC: nop

    // 0x8004D5B0: bc1fl       L_8004D690
    if (!c1cs) {
        // 0x8004D5B4: swc1        $f20, 0xA4($s2)
        MEM_W(0XA4, ctx->r18) = ctx->f20.u32l;
            goto L_8004D690;
    }
    goto skip_0;
    // 0x8004D5B4: swc1        $f20, 0xA4($s2)
    MEM_W(0XA4, ctx->r18) = ctx->f20.u32l;
    skip_0:
    // 0x8004D5B8: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8004D5BC: c.eq.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl == ctx->f0.fl;
    // 0x8004D5C0: nop

    // 0x8004D5C4: bc1tl       L_8004D690
    if (c1cs) {
        // 0x8004D5C8: swc1        $f20, 0xA4($s2)
        MEM_W(0XA4, ctx->r18) = ctx->f20.u32l;
            goto L_8004D690;
    }
    goto skip_1;
    // 0x8004D5C8: swc1        $f20, 0xA4($s2)
    MEM_W(0XA4, ctx->r18) = ctx->f20.u32l;
    skip_1:
    // 0x8004D5CC: lwc1        $f0, 0x20($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X20);
    // 0x8004D5D0: lwc1        $f2, 0x10($s2)
    ctx->f2.u32l = MEM_W(ctx->r18, 0X10);
    // 0x8004D5D4: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x8004D5D8: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    // 0x8004D5DC: lwc1        $f0, 0x24($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X24);
    // 0x8004D5E0: lwc1        $f2, 0x14($s2)
    ctx->f2.u32l = MEM_W(ctx->r18, 0X14);
    // 0x8004D5E4: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x8004D5E8: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    // 0x8004D5EC: lwc1        $f0, 0x28($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X28);
    // 0x8004D5F0: lwc1        $f2, 0x18($s2)
    ctx->f2.u32l = MEM_W(ctx->r18, 0X18);
    // 0x8004D5F4: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x8004D5F8: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    // 0x8004D5FC: jal         0x800AA350
    // 0x8004D600: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    func_800AA350(rdram, ctx);
        goto after_7;
    // 0x8004D600: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    after_7:
    // 0x8004D604: lwc1        $f0, 0xA4($s2)
    ctx->f0.u32l = MEM_W(ctx->r18, 0XA4);
    // 0x8004D608: sub.s       $f0, $f20, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f20.fl - ctx->f0.fl;
    // 0x8004D60C: lwc1        $f2, 0x98($s2)
    ctx->f2.u32l = MEM_W(ctx->r18, 0X98);
    // 0x8004D610: mul.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x8004D614: lwc1        $f0, 0x10($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X10);
    // 0x8004D618: mul.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x8004D61C: lwc1        $f0, 0xA4($s2)
    ctx->f0.u32l = MEM_W(ctx->r18, 0XA4);
    // 0x8004D620: sub.s       $f0, $f20, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f20.fl - ctx->f0.fl;
    // 0x8004D624: lwc1        $f4, 0x10($s2)
    ctx->f4.u32l = MEM_W(ctx->r18, 0X10);
    // 0x8004D628: add.s       $f4, $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f2.fl;
    // 0x8004D62C: lwc1        $f2, 0x98($s2)
    ctx->f2.u32l = MEM_W(ctx->r18, 0X98);
    // 0x8004D630: mul.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x8004D634: swc1        $f4, 0x10($s2)
    MEM_W(0X10, ctx->r18) = ctx->f4.u32l;
    // 0x8004D638: lwc1        $f0, 0x14($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X14);
    // 0x8004D63C: mul.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x8004D640: lwc1        $f0, 0xA4($s2)
    ctx->f0.u32l = MEM_W(ctx->r18, 0XA4);
    // 0x8004D644: sub.s       $f0, $f20, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f20.fl - ctx->f0.fl;
    // 0x8004D648: lwc1        $f4, 0x14($s2)
    ctx->f4.u32l = MEM_W(ctx->r18, 0X14);
    // 0x8004D64C: add.s       $f4, $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f2.fl;
    // 0x8004D650: lwc1        $f2, 0x98($s2)
    ctx->f2.u32l = MEM_W(ctx->r18, 0X98);
    // 0x8004D654: mul.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x8004D658: swc1        $f4, 0x14($s2)
    MEM_W(0X14, ctx->r18) = ctx->f4.u32l;
    // 0x8004D65C: lwc1        $f0, 0x18($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X18);
    // 0x8004D660: mul.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x8004D664: lwc1        $f0, 0x18($s2)
    ctx->f0.u32l = MEM_W(ctx->r18, 0X18);
    // 0x8004D668: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x8004D66C: lwc1        $f20, 0xA4($s2)
    ctx->f20.u32l = MEM_W(ctx->r18, 0XA4);
    // 0x8004D670: mov.s       $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    ctx->f2.fl = ctx->f4.fl;
    // 0x8004D674: swc1        $f0, 0x18($s2)
    MEM_W(0X18, ctx->r18) = ctx->f0.u32l;
    // 0x8004D678: lwc1        $f0, 0x10($s2)
    ctx->f0.u32l = MEM_W(ctx->r18, 0X10);
    // 0x8004D67C: lwc1        $f4, 0x18($s2)
    ctx->f4.u32l = MEM_W(ctx->r18, 0X18);
    // 0x8004D680: swc1        $f2, 0x50($s2)
    MEM_W(0X50, ctx->r18) = ctx->f2.u32l;
    // 0x8004D684: swc1        $f0, 0x4C($s2)
    MEM_W(0X4C, ctx->r18) = ctx->f0.u32l;
    // 0x8004D688: swc1        $f4, 0x54($s2)
    MEM_W(0X54, ctx->r18) = ctx->f4.u32l;
    // 0x8004D68C: swc1        $f20, 0xA4($s2)
    MEM_W(0XA4, ctx->r18) = ctx->f20.u32l;
L_8004D690:
    // 0x8004D690: lwc1        $f0, 0x20($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X20);
    // 0x8004D694: lwc1        $f2, 0x10($s2)
    ctx->f2.u32l = MEM_W(ctx->r18, 0X10);
    // 0x8004D698: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x8004D69C: swc1        $f0, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->f0.u32l;
    // 0x8004D6A0: lwc1        $f0, 0x24($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X24);
    // 0x8004D6A4: lwc1        $f2, 0x14($s2)
    ctx->f2.u32l = MEM_W(ctx->r18, 0X14);
    // 0x8004D6A8: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x8004D6AC: swc1        $f0, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->f0.u32l;
    // 0x8004D6B0: lwc1        $f0, 0x28($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X28);
    // 0x8004D6B4: lwc1        $f2, 0x18($s2)
    ctx->f2.u32l = MEM_W(ctx->r18, 0X18);
    // 0x8004D6B8: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x8004D6BC: addiu       $a0, $sp, 0x70
    ctx->r4 = ADD32(ctx->r29, 0X70);
    // 0x8004D6C0: jal         0x8001CF2C
    // 0x8004D6C4: swc1        $f0, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->f0.u32l;
    func_8001CF2C(rdram, ctx);
        goto after_8;
    // 0x8004D6C4: swc1        $f0, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->f0.u32l;
    after_8:
    // 0x8004D6C8: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8004D6CC: lwc1        $f8, -0x56EC($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X56EC);
    // 0x8004D6D0: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
    // 0x8004D6D4: c.lt.s      $f8, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f8.fl < ctx->f2.fl;
    // 0x8004D6D8: nop

    // 0x8004D6DC: bc1f        L_8004D7F0
    if (!c1cs) {
        // 0x8004D6E0: nop
    
            goto L_8004D7F0;
    }
    // 0x8004D6E0: nop

    // 0x8004D6E4: lwc1        $f0, 0x94($s2)
    ctx->f0.u32l = MEM_W(ctx->r18, 0X94);
    // 0x8004D6E8: sub.s       $f0, $f2, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f2.fl - ctx->f0.fl;
    // 0x8004D6EC: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x8004D6F0: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8004D6F4: lwc1        $f2, -0x56E8($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X56E8);
    // 0x8004D6F8: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x8004D6FC: nop

    // 0x8004D700: bc1tl       L_8004D708
    if (c1cs) {
        // 0x8004D704: mov.s       $f0, $f2
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
            goto L_8004D708;
    }
    goto skip_2;
    // 0x8004D704: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    skip_2:
L_8004D708:
    // 0x8004D708: lwc1        $f2, 0x9C($s2)
    ctx->f2.u32l = MEM_W(ctx->r18, 0X9C);
    // 0x8004D70C: mul.s       $f22, $f0, $f2
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f22.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x8004D710: lwc1        $f4, 0x98($s2)
    ctx->f4.u32l = MEM_W(ctx->r18, 0X98);
    // 0x8004D714: sub.s       $f6, $f22, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f22.fl - ctx->f4.fl;
    // 0x8004D718: abs.s       $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = fabsf(ctx->f6.fl);
    // 0x8004D71C: mul.s       $f2, $f2, $f20
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f20.fl);
    // 0x8004D720: nop

    // 0x8004D724: mul.s       $f0, $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f20.fl);
    // 0x8004D728: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x8004D72C: nop

    // 0x8004D730: bc1tl       L_8004D738
    if (c1cs) {
        // 0x8004D734: mov.s       $f2, $f0
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
            goto L_8004D738;
    }
    goto skip_3;
    // 0x8004D734: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
    skip_3:
L_8004D738:
    // 0x8004D738: c.lt.s      $f2, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f2.fl < ctx->f8.fl;
    // 0x8004D73C: nop

    // 0x8004D740: bc1f        L_8004D74C
    if (!c1cs) {
        // 0x8004D744: nop
    
            goto L_8004D74C;
    }
    // 0x8004D744: nop

    // 0x8004D748: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
L_8004D74C:
    // 0x8004D74C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8004D750: c.lt.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl < ctx->f6.fl;
    // 0x8004D754: nop

    // 0x8004D758: bc1fl       L_8004D764
    if (!c1cs) {
        // 0x8004D75C: sub.s       $f0, $f4, $f2
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f2.fl;
            goto L_8004D764;
    }
    goto skip_4;
    // 0x8004D75C: sub.s       $f0, $f4, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f2.fl;
    skip_4:
    // 0x8004D760: add.s       $f0, $f4, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f4.fl + ctx->f2.fl;
L_8004D764:
    // 0x8004D764: swc1        $f0, 0x98($s2)
    MEM_W(0X98, ctx->r18) = ctx->f0.u32l;
    // 0x8004D768: lwc1        $f0, 0x98($s2)
    ctx->f0.u32l = MEM_W(ctx->r18, 0X98);
    // 0x8004D76C: c.lt.s      $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f22.fl < ctx->f0.fl;
    // 0x8004D770: nop

    // 0x8004D774: bc1tl       L_8004D77C
    if (c1cs) {
        // 0x8004D778: swc1        $f22, 0x98($s2)
        MEM_W(0X98, ctx->r18) = ctx->f22.u32l;
            goto L_8004D77C;
    }
    goto skip_5;
    // 0x8004D778: swc1        $f22, 0x98($s2)
    MEM_W(0X98, ctx->r18) = ctx->f22.u32l;
    skip_5:
L_8004D77C:
    // 0x8004D77C: jal         0x800AA350
    // 0x8004D780: addiu       $a0, $sp, 0x70
    ctx->r4 = ADD32(ctx->r29, 0X70);
    func_800AA350(rdram, ctx);
        goto after_9;
    // 0x8004D780: addiu       $a0, $sp, 0x70
    ctx->r4 = ADD32(ctx->r29, 0X70);
    after_9:
    // 0x8004D784: lwc1        $f0, 0x98($s2)
    ctx->f0.u32l = MEM_W(ctx->r18, 0X98);
    // 0x8004D788: mul.s       $f0, $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f20.fl);
    // 0x8004D78C: lwc1        $f2, 0x70($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X70);
    // 0x8004D790: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x8004D794: lwc1        $f2, 0x10($s2)
    ctx->f2.u32l = MEM_W(ctx->r18, 0X10);
    // 0x8004D798: add.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x8004D79C: lwc1        $f0, 0x98($s2)
    ctx->f0.u32l = MEM_W(ctx->r18, 0X98);
    // 0x8004D7A0: mul.s       $f0, $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f20.fl);
    // 0x8004D7A4: swc1        $f2, 0x10($s2)
    MEM_W(0X10, ctx->r18) = ctx->f2.u32l;
    // 0x8004D7A8: lwc1        $f2, 0x74($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X74);
    // 0x8004D7AC: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x8004D7B0: lwc1        $f2, 0x14($s2)
    ctx->f2.u32l = MEM_W(ctx->r18, 0X14);
    // 0x8004D7B4: add.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x8004D7B8: lwc1        $f4, 0x98($s2)
    ctx->f4.u32l = MEM_W(ctx->r18, 0X98);
    // 0x8004D7BC: mul.s       $f4, $f4, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = MUL_S(ctx->f4.fl, ctx->f20.fl);
    // 0x8004D7C0: swc1        $f2, 0x14($s2)
    MEM_W(0X14, ctx->r18) = ctx->f2.u32l;
    // 0x8004D7C4: lwc1        $f0, 0x78($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X78);
    // 0x8004D7C8: mul.s       $f4, $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x8004D7CC: lwc1        $f0, 0x18($s2)
    ctx->f0.u32l = MEM_W(ctx->r18, 0X18);
    // 0x8004D7D0: add.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f4.fl;
    // 0x8004D7D4: swc1        $f0, 0x18($s2)
    MEM_W(0X18, ctx->r18) = ctx->f0.u32l;
    // 0x8004D7D8: lwc1        $f0, 0x10($s2)
    ctx->f0.u32l = MEM_W(ctx->r18, 0X10);
    // 0x8004D7DC: lwc1        $f4, 0x18($s2)
    ctx->f4.u32l = MEM_W(ctx->r18, 0X18);
    // 0x8004D7E0: swc1        $f2, 0x50($s2)
    MEM_W(0X50, ctx->r18) = ctx->f2.u32l;
    // 0x8004D7E4: swc1        $f0, 0x4C($s2)
    MEM_W(0X4C, ctx->r18) = ctx->f0.u32l;
    // 0x8004D7E8: j           L_8004D820
    // 0x8004D7EC: swc1        $f4, 0x54($s2)
    MEM_W(0X54, ctx->r18) = ctx->f4.u32l;
        goto L_8004D820;
    // 0x8004D7EC: swc1        $f4, 0x54($s2)
    MEM_W(0X54, ctx->r18) = ctx->f4.u32l;
L_8004D7F0:
    // 0x8004D7F0: lwc1        $f0, 0x64($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X64);
    // 0x8004D7F4: swc1        $f0, 0x4C($s2)
    MEM_W(0X4C, ctx->r18) = ctx->f0.u32l;
    // 0x8004D7F8: lwc1        $f0, 0x68($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X68);
    // 0x8004D7FC: swc1        $f0, 0x50($s2)
    MEM_W(0X50, ctx->r18) = ctx->f0.u32l;
    // 0x8004D800: lwc1        $f0, 0x6C($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x8004D804: lwc1        $f2, 0x50($s2)
    ctx->f2.u32l = MEM_W(ctx->r18, 0X50);
    // 0x8004D808: swc1        $f0, 0x54($s2)
    MEM_W(0X54, ctx->r18) = ctx->f0.u32l;
    // 0x8004D80C: lwc1        $f0, 0x4C($s2)
    ctx->f0.u32l = MEM_W(ctx->r18, 0X4C);
    // 0x8004D810: lwc1        $f4, 0x54($s2)
    ctx->f4.u32l = MEM_W(ctx->r18, 0X54);
    // 0x8004D814: swc1        $f2, 0x14($s2)
    MEM_W(0X14, ctx->r18) = ctx->f2.u32l;
    // 0x8004D818: swc1        $f0, 0x10($s2)
    MEM_W(0X10, ctx->r18) = ctx->f0.u32l;
    // 0x8004D81C: swc1        $f4, 0x18($s2)
    MEM_W(0X18, ctx->r18) = ctx->f4.u32l;
L_8004D820:
    // 0x8004D820: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8004D824: lw          $v1, 0xC($s2)
    ctx->r3 = MEM_W(ctx->r18, 0XC);
    // 0x8004D828: addiu       $a0, $a0, -0x72E8
    ctx->r4 = ADD32(ctx->r4, -0X72E8);
    // 0x8004D82C: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x8004D830: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8004D834: sll         $v0, $v0, 4
    ctx->r2 = S32(ctx->r2 << 4);
    // 0x8004D838: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8004D83C: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8004D840: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x8004D844: lw          $a0, 0x4($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X4);
    // 0x8004D848: lhu         $v1, 0x2($a0)
    ctx->r3 = MEM_HU(ctx->r4, 0X2);
    // 0x8004D84C: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // 0x8004D850: bne         $v1, $v0, L_8004D988
    if (ctx->r3 != ctx->r2) {
        // 0x8004D854: nop
    
            goto L_8004D988;
    }
    // 0x8004D854: nop

    // 0x8004D858: lw          $v0, 0xC0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0XC0);
    // 0x8004D85C: beql        $v0, $s2, L_8004D988
    if (ctx->r2 == ctx->r18) {
        // 0x8004D860: swc1        $f22, 0x98($s2)
        MEM_W(0X98, ctx->r18) = ctx->f22.u32l;
            goto L_8004D988;
    }
    goto skip_6;
    // 0x8004D860: swc1        $f22, 0x98($s2)
    MEM_W(0X98, ctx->r18) = ctx->f22.u32l;
    skip_6:
    // 0x8004D864: j           L_8004D988
    // 0x8004D868: nop

        goto L_8004D988;
    // 0x8004D868: nop

L_8004D86C:
    // 0x8004D86C: lwc1        $f2, 0xCC($s2)
    ctx->f2.u32l = MEM_W(ctx->r18, 0XCC);
    // 0x8004D870: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8004D874: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x8004D878: nop

    // 0x8004D87C: bc1t        L_8004D988
    if (c1cs) {
        // 0x8004D880: nop
    
            goto L_8004D988;
    }
    // 0x8004D880: nop

    // 0x8004D884: lwc1        $f2, 0xC4($s2)
    ctx->f2.u32l = MEM_W(ctx->r18, 0XC4);
    // 0x8004D888: lwc1        $f0, 0xC8($s2)
    ctx->f0.u32l = MEM_W(ctx->r18, 0XC8);
    // 0x8004D88C: div.s       $f6, $f2, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = DIV_S(ctx->f2.fl, ctx->f0.fl);
    // 0x8004D890: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8004D894: ldc1        $f2, -0x56E0($at)
    CHECK_FR(ctx, 2);
    ctx->f2.u64 = LD(ctx->r1, -0X56E0);
    // 0x8004D898: cvt.d.s     $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f0.d = CVT_D_S(ctx->f6.fl);
    // 0x8004D89C: c.lt.d      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.d < ctx->f0.d;
    // 0x8004D8A0: nop

    // 0x8004D8A4: bc1f        L_8004D8B4
    if (!c1cs) {
        // 0x8004D8A8: nop
    
            goto L_8004D8B4;
    }
    // 0x8004D8A8: nop

    // 0x8004D8AC: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8004D8B0: lwc1        $f6, -0x56D8($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X56D8);
L_8004D8B4:
    // 0x8004D8B4: lw          $v0, 0xBC($s2)
    ctx->r2 = MEM_W(ctx->r18, 0XBC);
    // 0x8004D8B8: lwc1        $f4, 0x4C($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X4C);
    // 0x8004D8BC: swc1        $f4, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->f4.u32l;
    // 0x8004D8C0: lw          $v0, 0xBC($s2)
    ctx->r2 = MEM_W(ctx->r18, 0XBC);
    // 0x8004D8C4: lwc1        $f0, 0x50($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X50);
    // 0x8004D8C8: swc1        $f0, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->f0.u32l;
    // 0x8004D8CC: lw          $v0, 0xBC($s2)
    ctx->r2 = MEM_W(ctx->r18, 0XBC);
    // 0x8004D8D0: lwc1        $f0, 0x54($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X54);
    // 0x8004D8D4: swc1        $f0, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->f0.u32l;
    // 0x8004D8D8: lw          $v0, 0xC0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0XC0);
    // 0x8004D8DC: lwc1        $f2, 0x4C($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X4C);
    // 0x8004D8E0: swc1        $f2, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->f2.u32l;
    // 0x8004D8E4: lw          $v0, 0xC0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0XC0);
    // 0x8004D8E8: lwc1        $f0, 0x50($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X50);
    // 0x8004D8EC: swc1        $f0, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->f0.u32l;
    // 0x8004D8F0: lw          $v0, 0xC0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0XC0);
    // 0x8004D8F4: sub.s       $f2, $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = ctx->f2.fl - ctx->f4.fl;
    // 0x8004D8F8: lwc1        $f0, 0x54($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X54);
    // 0x8004D8FC: swc1        $f0, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->f0.u32l;
    // 0x8004D900: swc1        $f2, 0x10($s2)
    MEM_W(0X10, ctx->r18) = ctx->f2.u32l;
    // 0x8004D904: lwc1        $f2, 0x94($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X94);
    // 0x8004D908: lwc1        $f0, 0x84($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X84);
    // 0x8004D90C: sub.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl - ctx->f0.fl;
    // 0x8004D910: addiu       $a0, $s2, 0x10
    ctx->r4 = ADD32(ctx->r18, 0X10);
    // 0x8004D914: swc1        $f2, 0x14($s2)
    MEM_W(0X14, ctx->r18) = ctx->f2.u32l;
    // 0x8004D918: lwc1        $f0, 0x98($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X98);
    // 0x8004D91C: lwc1        $f2, 0x88($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X88);
    // 0x8004D920: addiu       $a1, $sp, 0x80
    ctx->r5 = ADD32(ctx->r29, 0X80);
    // 0x8004D924: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x8004D928: mfc1        $a2, $f6
    ctx->r6 = (int32_t)ctx->f6.u32l;
    // 0x8004D92C: addu        $a3, $a0, $zero
    ctx->r7 = ADD32(ctx->r4, 0);
    // 0x8004D930: jal         0x800AA3E0
    // 0x8004D934: swc1        $f0, 0x18($s2)
    MEM_W(0X18, ctx->r18) = ctx->f0.u32l;
    func_800AA3E0(rdram, ctx);
        goto after_10;
    // 0x8004D934: swc1        $f0, 0x18($s2)
    MEM_W(0X18, ctx->r18) = ctx->f0.u32l;
    after_10:
    // 0x8004D938: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8004D93C: addiu       $a0, $a0, -0x72E8
    ctx->r4 = ADD32(ctx->r4, -0X72E8);
    // 0x8004D940: lwc1        $f0, 0x10($s2)
    ctx->f0.u32l = MEM_W(ctx->r18, 0X10);
    // 0x8004D944: lwc1        $f2, 0x14($s2)
    ctx->f2.u32l = MEM_W(ctx->r18, 0X14);
    // 0x8004D948: lw          $v1, 0xC($s2)
    ctx->r3 = MEM_W(ctx->r18, 0XC);
    // 0x8004D94C: lwc1        $f4, 0x18($s2)
    ctx->f4.u32l = MEM_W(ctx->r18, 0X18);
    // 0x8004D950: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x8004D954: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8004D958: sll         $v0, $v0, 4
    ctx->r2 = S32(ctx->r2 << 4);
    // 0x8004D95C: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8004D960: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8004D964: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x8004D968: swc1        $f0, 0x4C($s2)
    MEM_W(0X4C, ctx->r18) = ctx->f0.u32l;
    // 0x8004D96C: swc1        $f2, 0x50($s2)
    MEM_W(0X50, ctx->r18) = ctx->f2.u32l;
    // 0x8004D970: swc1        $f4, 0x54($s2)
    MEM_W(0X54, ctx->r18) = ctx->f4.u32l;
    // 0x8004D974: lw          $v0, 0x4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X4);
    // 0x8004D978: bne         $s2, $v0, L_8004D988
    if (ctx->r18 != ctx->r2) {
        // 0x8004D97C: nop
    
            goto L_8004D988;
    }
    // 0x8004D97C: nop

    // 0x8004D980: jal         0x80066A50
    // 0x8004D984: nop

    func_80066A50(rdram, ctx);
        goto after_11;
    // 0x8004D984: nop

    after_11:
L_8004D988:
    // 0x8004D988: lhu         $v1, 0x4($s2)
    ctx->r3 = MEM_HU(ctx->r18, 0X4);
    // 0x8004D98C: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // 0x8004D990: bne         $v1, $v0, L_8004D9A4
    if (ctx->r3 != ctx->r2) {
        // 0x8004D994: nop
    
            goto L_8004D9A4;
    }
    // 0x8004D994: nop

    // 0x8004D998: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x8004D99C: jal         0x8004D078
    // 0x8004D9A0: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    func_8004D078(rdram, ctx);
        goto after_12;
    // 0x8004D9A0: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    after_12:
L_8004D9A4:
    // 0x8004D9A4: lhu         $v0, 0x0($s2)
    ctx->r2 = MEM_HU(ctx->r18, 0X0);
    // 0x8004D9A8: andi        $v0, $v0, 0x8
    ctx->r2 = ctx->r2 & 0X8;
    // 0x8004D9AC: beq         $v0, $zero, L_8004DAE0
    if (ctx->r2 == 0) {
        // 0x8004D9B0: addiu       $a0, $sp, 0x10
        ctx->r4 = ADD32(ctx->r29, 0X10);
            goto L_8004DAE0;
    }
    // 0x8004D9B0: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    // 0x8004D9B4: lw          $v0, 0x74($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X74);
    // 0x8004D9B8: lwc1        $f0, 0x8($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X8);
    // 0x8004D9BC: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    // 0x8004D9C0: lw          $v0, 0x74($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X74);
    // 0x8004D9C4: lwc1        $f0, 0x14($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X14);
    // 0x8004D9C8: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    // 0x8004D9CC: lw          $v0, 0x74($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X74);
    // 0x8004D9D0: lwc1        $f0, 0x20($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X20);
    // 0x8004D9D4: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x8004D9D8: jal         0x800AA350
    // 0x8004D9DC: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    func_800AA350(rdram, ctx);
        goto after_13;
    // 0x8004D9DC: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    after_13:
    // 0x8004D9E0: lwc1        $f0, 0x30($s2)
    ctx->f0.u32l = MEM_W(ctx->r18, 0X30);
    // 0x8004D9E4: swc1        $f0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f0.u32l;
    // 0x8004D9E8: lwc1        $f0, 0x3C($s2)
    ctx->f0.u32l = MEM_W(ctx->r18, 0X3C);
    // 0x8004D9EC: addiu       $s0, $sp, 0x30
    ctx->r16 = ADD32(ctx->r29, 0X30);
    // 0x8004D9F0: swc1        $f0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f0.u32l;
    // 0x8004D9F4: lwc1        $f0, 0x48($s2)
    ctx->f0.u32l = MEM_W(ctx->r18, 0X48);
    // 0x8004D9F8: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x8004D9FC: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    // 0x8004DA00: jal         0x800AA350
    // 0x8004DA04: swc1        $f0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f0.u32l;
    func_800AA350(rdram, ctx);
        goto after_14;
    // 0x8004DA04: swc1        $f0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f0.u32l;
    after_14:
    // 0x8004DA08: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    // 0x8004DA0C: jal         0x8001CFE8
    // 0x8004DA10: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    func_8001CFE8(rdram, ctx);
        goto after_15;
    // 0x8004DA10: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    after_15:
    // 0x8004DA14: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x8004DA18: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x8004DA1C: nop

    // 0x8004DA20: bc1f        L_8004DA48
    if (!c1cs) {
        // 0x8004DA24: addiu       $a1, $s2, 0x78
        ctx->r5 = ADD32(ctx->r18, 0X78);
            goto L_8004DA48;
    }
    // 0x8004DA24: addiu       $a1, $s2, 0x78
    ctx->r5 = ADD32(ctx->r18, 0X78);
    // 0x8004DA28: lw          $t0, 0xA0($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XA0);
    // 0x8004DA2C: lw          $t1, 0xA4($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XA4);
    // 0x8004DA30: lw          $t2, 0xA8($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XA8);
    // 0x8004DA34: sw          $t0, 0x10($s2)
    MEM_W(0X10, ctx->r18) = ctx->r8;
    // 0x8004DA38: sw          $t1, 0x14($s2)
    MEM_W(0X14, ctx->r18) = ctx->r9;
    // 0x8004DA3C: sw          $t2, 0x18($s2)
    MEM_W(0X18, ctx->r18) = ctx->r10;
    // 0x8004DA40: j           L_8004DAC8
    // 0x8004DA44: nop

        goto L_8004DAC8;
    // 0x8004DA44: nop

L_8004DA48:
    // 0x8004DA48: addiu       $s1, $sp, 0x20
    ctx->r17 = ADD32(ctx->r29, 0X20);
    // 0x8004DA4C: lw          $a0, 0x74($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X74);
    // 0x8004DA50: jal         0x800193E8
    // 0x8004DA54: addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    func_800193E8(rdram, ctx);
        goto after_16;
    // 0x8004DA54: addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    after_16:
    // 0x8004DA58: lwc1        $f0, 0x10($s2)
    ctx->f0.u32l = MEM_W(ctx->r18, 0X10);
    // 0x8004DA5C: lwc1        $f2, 0x20($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X20);
    // 0x8004DA60: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x8004DA64: lwc1        $f2, 0x24($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X24);
    // 0x8004DA68: swc1        $f0, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->f0.u32l;
    // 0x8004DA6C: lwc1        $f0, 0x14($s2)
    ctx->f0.u32l = MEM_W(ctx->r18, 0X14);
    // 0x8004DA70: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x8004DA74: swc1        $f0, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->f0.u32l;
    // 0x8004DA78: lwc1        $f2, 0x18($s2)
    ctx->f2.u32l = MEM_W(ctx->r18, 0X18);
    // 0x8004DA7C: lwc1        $f0, 0x28($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X28);
    // 0x8004DA80: addiu       $s0, $sp, 0x70
    ctx->r16 = ADD32(ctx->r29, 0X70);
    // 0x8004DA84: sub.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl - ctx->f0.fl;
    // 0x8004DA88: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8004DA8C: lwc1        $f20, -0x56D4($at)
    ctx->f20.u32l = MEM_W(ctx->r1, -0X56D4);
    // 0x8004DA90: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x8004DA94: jal         0x8001CF2C
    // 0x8004DA98: swc1        $f2, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->f2.u32l;
    func_8001CF2C(rdram, ctx);
        goto after_17;
    // 0x8004DA98: swc1        $f2, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->f2.u32l;
    after_17:
    // 0x8004DA9C: c.le.s      $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f20.fl <= ctx->f0.fl;
    // 0x8004DAA0: nop

    // 0x8004DAA4: bc1f        L_8004DAE0
    if (!c1cs) {
        // 0x8004DAA8: nop
    
            goto L_8004DAE0;
    }
    // 0x8004DAA8: nop

    // 0x8004DAAC: jal         0x800AA350
    // 0x8004DAB0: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_800AA350(rdram, ctx);
        goto after_18;
    // 0x8004DAB0: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_18:
    // 0x8004DAB4: addiu       $a0, $s2, 0x10
    ctx->r4 = ADD32(ctx->r18, 0X10);
    // 0x8004DAB8: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    // 0x8004DABC: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x8004DAC0: jal         0x800AA3E0
    // 0x8004DAC4: addu        $a3, $s0, $zero
    ctx->r7 = ADD32(ctx->r16, 0);
    func_800AA3E0(rdram, ctx);
        goto after_19;
    // 0x8004DAC4: addu        $a3, $s0, $zero
    ctx->r7 = ADD32(ctx->r16, 0);
    after_19:
L_8004DAC8:
    // 0x8004DAC8: lwc1        $f0, 0x10($s2)
    ctx->f0.u32l = MEM_W(ctx->r18, 0X10);
    // 0x8004DACC: lwc1        $f2, 0x14($s2)
    ctx->f2.u32l = MEM_W(ctx->r18, 0X14);
    // 0x8004DAD0: lwc1        $f4, 0x18($s2)
    ctx->f4.u32l = MEM_W(ctx->r18, 0X18);
    // 0x8004DAD4: swc1        $f0, 0x4C($s2)
    MEM_W(0X4C, ctx->r18) = ctx->f0.u32l;
    // 0x8004DAD8: swc1        $f2, 0x50($s2)
    MEM_W(0X50, ctx->r18) = ctx->f2.u32l;
    // 0x8004DADC: swc1        $f4, 0x54($s2)
    MEM_W(0X54, ctx->r18) = ctx->f4.u32l;
L_8004DAE0:
    // 0x8004DAE0: lhu         $v0, 0x4($s2)
    ctx->r2 = MEM_HU(ctx->r18, 0X4);
    // 0x8004DAE4: bne         $v0, $zero, L_8004DBA8
    if (ctx->r2 != 0) {
        // 0x8004DAE8: lui         $v1, 0x410
        ctx->r3 = S32(0X410 << 16);
            goto L_8004DBA8;
    }
    // 0x8004DAE8: lui         $v1, 0x410
    ctx->r3 = S32(0X410 << 16);
    // 0x8004DAEC: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x8004DAF0: and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // 0x8004DAF4: bne         $v0, $zero, L_8004DBA8
    if (ctx->r2 != 0) {
        // 0x8004DAF8: addiu       $a1, $s2, 0x78
        ctx->r5 = ADD32(ctx->r18, 0X78);
            goto L_8004DBA8;
    }
    // 0x8004DAF8: addiu       $a1, $s2, 0x78
    ctx->r5 = ADD32(ctx->r18, 0X78);
    // 0x8004DAFC: lw          $a0, 0x74($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X74);
    // 0x8004DB00: jal         0x800193E8
    // 0x8004DB04: addiu       $a2, $sp, 0x20
    ctx->r6 = ADD32(ctx->r29, 0X20);
    func_800193E8(rdram, ctx);
        goto after_20;
    // 0x8004DB04: addiu       $a2, $sp, 0x20
    ctx->r6 = ADD32(ctx->r29, 0X20);
    after_20:
    // 0x8004DB08: lwc1        $f0, 0x10($s2)
    ctx->f0.u32l = MEM_W(ctx->r18, 0X10);
    // 0x8004DB0C: lwc1        $f2, 0x20($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X20);
    // 0x8004DB10: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x8004DB14: lwc1        $f2, 0x24($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X24);
    // 0x8004DB18: swc1        $f0, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->f0.u32l;
    // 0x8004DB1C: lwc1        $f0, 0x14($s2)
    ctx->f0.u32l = MEM_W(ctx->r18, 0X14);
    // 0x8004DB20: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x8004DB24: lwc1        $f2, 0x28($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X28);
    // 0x8004DB28: swc1        $f0, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->f0.u32l;
    // 0x8004DB2C: lwc1        $f0, 0x18($s2)
    ctx->f0.u32l = MEM_W(ctx->r18, 0X18);
    // 0x8004DB30: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x8004DB34: addiu       $a0, $sp, 0x70
    ctx->r4 = ADD32(ctx->r29, 0X70);
    // 0x8004DB38: jal         0x8001CF2C
    // 0x8004DB3C: swc1        $f0, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->f0.u32l;
    func_8001CF2C(rdram, ctx);
        goto after_21;
    // 0x8004DB3C: swc1        $f0, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->f0.u32l;
    after_21:
    // 0x8004DB40: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8004DB44: lwc1        $f2, -0x56D0($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X56D0);
    // 0x8004DB48: c.le.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl <= ctx->f0.fl;
    // 0x8004DB4C: nop

    // 0x8004DB50: bc1f        L_8004DBA8
    if (!c1cs) {
        // 0x8004DB54: addiu       $v1, $s2, 0x28
        ctx->r3 = ADD32(ctx->r18, 0X28);
            goto L_8004DBA8;
    }
    // 0x8004DB54: addiu       $v1, $s2, 0x28
    ctx->r3 = ADD32(ctx->r18, 0X28);
    // 0x8004DB58: lw          $v0, 0x74($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X74);
    // 0x8004DB5C: addiu       $a0, $v0, 0x30
    ctx->r4 = ADD32(ctx->r2, 0X30);
L_8004DB60:
    // 0x8004DB60: lw          $t0, 0x0($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X0);
    // 0x8004DB64: lw          $t1, 0x4($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X4);
    // 0x8004DB68: lw          $t2, 0x8($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X8);
    // 0x8004DB6C: lw          $t3, 0xC($v0)
    ctx->r11 = MEM_W(ctx->r2, 0XC);
    // 0x8004DB70: sw          $t0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r8;
    // 0x8004DB74: sw          $t1, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r9;
    // 0x8004DB78: sw          $t2, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r10;
    // 0x8004DB7C: sw          $t3, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r11;
    // 0x8004DB80: addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
    // 0x8004DB84: bne         $v0, $a0, L_8004DB60
    if (ctx->r2 != ctx->r4) {
        // 0x8004DB88: addiu       $v1, $v1, 0x10
        ctx->r3 = ADD32(ctx->r3, 0X10);
            goto L_8004DB60;
    }
    // 0x8004DB88: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
    // 0x8004DB8C: lwc1        $f0, 0x4C($s2)
    ctx->f0.u32l = MEM_W(ctx->r18, 0X4C);
    // 0x8004DB90: lwc1        $f2, 0x50($s2)
    ctx->f2.u32l = MEM_W(ctx->r18, 0X50);
    // 0x8004DB94: lwc1        $f4, 0x54($s2)
    ctx->f4.u32l = MEM_W(ctx->r18, 0X54);
    // 0x8004DB98: swc1        $f0, 0x10($s2)
    MEM_W(0X10, ctx->r18) = ctx->f0.u32l;
    // 0x8004DB9C: swc1        $f2, 0x14($s2)
    MEM_W(0X14, ctx->r18) = ctx->f2.u32l;
    // 0x8004DBA0: jal         0x80066A50
    // 0x8004DBA4: swc1        $f4, 0x18($s2)
    MEM_W(0X18, ctx->r18) = ctx->f4.u32l;
    func_80066A50(rdram, ctx);
        goto after_22;
    // 0x8004DBA4: swc1        $f4, 0x18($s2)
    MEM_W(0X18, ctx->r18) = ctx->f4.u32l;
    after_22:
L_8004DBA8:
    // 0x8004DBA8: jal         0x8004CD00
    // 0x8004DBAC: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    func_8004CD00(rdram, ctx);
        goto after_23;
    // 0x8004DBAC: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    after_23:
L_8004DBB0:
    // 0x8004DBB0: lw          $ra, 0xBC($sp)
    ctx->r31 = MEM_W(ctx->r29, 0XBC);
    // 0x8004DBB4: lw          $s2, 0xB8($sp)
    ctx->r18 = MEM_W(ctx->r29, 0XB8);
    // 0x8004DBB8: lw          $s1, 0xB4($sp)
    ctx->r17 = MEM_W(ctx->r29, 0XB4);
    // 0x8004DBBC: lw          $s0, 0xB0($sp)
    ctx->r16 = MEM_W(ctx->r29, 0XB0);
    // 0x8004DBC0: ldc1        $f22, 0xC8($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0XC8);
    // 0x8004DBC4: ldc1        $f20, 0xC0($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0XC0);
    // 0x8004DBC8: jr          $ra
    // 0x8004DBCC: addiu       $sp, $sp, 0xD0
    ctx->r29 = ADD32(ctx->r29, 0XD0);
    return;
    // 0x8004DBCC: addiu       $sp, $sp, 0xD0
    ctx->r29 = ADD32(ctx->r29, 0XD0);
;}
RECOMP_FUNC void func_8004DBD0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8004DBD0: addiu       $sp, $sp, -0x90
    ctx->r29 = ADD32(ctx->r29, -0X90);
    // 0x8004DBD4: sw          $s2, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r18;
    // 0x8004DBD8: lui         $s2, 0x8011
    ctx->r18 = S32(0X8011 << 16);
    // 0x8004DBDC: sdc1        $f20, 0x88($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X88, ctx->r29);
    // 0x8004DBE0: mtc1        $a1, $f20
    ctx->f20.u32l = ctx->r5;
    // 0x8004DBE4: lw          $v0, -0x35E0($s2)
    ctx->r2 = MEM_W(ctx->r18, -0X35E0);
    // 0x8004DBE8: sw          $s1, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r17;
    // 0x8004DBEC: addu        $s1, $a0, $zero
    ctx->r17 = ADD32(ctx->r4, 0);
    // 0x8004DBF0: sw          $s3, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r19;
    // 0x8004DBF4: addiu       $s3, $zero, 0x5
    ctx->r19 = ADD32(0, 0X5);
    // 0x8004DBF8: sw          $ra, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r31;
    // 0x8004DBFC: sw          $s4, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r20;
    // 0x8004DC00: beq         $v0, $s3, L_8004DE30
    if (ctx->r2 == ctx->r19) {
        // 0x8004DC04: sw          $s0, 0x70($sp)
        MEM_W(0X70, ctx->r29) = ctx->r16;
            goto L_8004DE30;
    }
    // 0x8004DC04: sw          $s0, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r16;
    // 0x8004DC08: lw          $v0, 0x74($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X74);
    // 0x8004DC0C: beq         $v0, $zero, L_8004DE30
    if (ctx->r2 == 0) {
        // 0x8004DC10: addiu       $s0, $sp, 0x20
        ctx->r16 = ADD32(ctx->r29, 0X20);
            goto L_8004DE30;
    }
    // 0x8004DC10: addiu       $s0, $sp, 0x20
    ctx->r16 = ADD32(ctx->r29, 0X20);
    // 0x8004DC14: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x8004DC18: lw          $t0, 0x78($s1)
    ctx->r8 = MEM_W(ctx->r17, 0X78);
    // 0x8004DC1C: lw          $t1, 0x7C($s1)
    ctx->r9 = MEM_W(ctx->r17, 0X7C);
    // 0x8004DC20: lw          $t2, 0x80($s1)
    ctx->r10 = MEM_W(ctx->r17, 0X80);
    // 0x8004DC24: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    // 0x8004DC28: sw          $t1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r9;
    // 0x8004DC2C: sw          $t2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r10;
    // 0x8004DC30: lw          $a0, 0x74($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X74);
    // 0x8004DC34: jal         0x800193E8
    // 0x8004DC38: addiu       $a2, $sp, 0x10
    ctx->r6 = ADD32(ctx->r29, 0X10);
    func_800193E8(rdram, ctx);
        goto after_0;
    // 0x8004DC38: addiu       $a2, $sp, 0x10
    ctx->r6 = ADD32(ctx->r29, 0X10);
    after_0:
    // 0x8004DC3C: lwc1        $f0, 0x10($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X10);
    // 0x8004DC40: lwc1        $f2, 0x10($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X10);
    // 0x8004DC44: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x8004DC48: swc1        $f0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f0.u32l;
    // 0x8004DC4C: lwc1        $f2, 0x14($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0X14);
    // 0x8004DC50: lwc1        $f0, 0x14($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X14);
    // 0x8004DC54: sub.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl - ctx->f0.fl;
    // 0x8004DC58: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    // 0x8004DC5C: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x8004DC60: swc1        $f2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f2.u32l;
    // 0x8004DC64: lwc1        $f0, 0x18($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X18);
    // 0x8004DC68: lwc1        $f2, 0x18($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X18);
    // 0x8004DC6C: lui         $a2, 0x8014
    ctx->r6 = S32(0X8014 << 16);
    // 0x8004DC70: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x8004DC74: addiu       $a2, $a2, -0x7FA8
    ctx->r6 = ADD32(ctx->r6, -0X7FA8);
    // 0x8004DC78: addiu       $a3, $sp, 0x40
    ctx->r7 = ADD32(ctx->r29, 0X40);
    // 0x8004DC7C: jal         0x80068D5C
    // 0x8004DC80: swc1        $f0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f0.u32l;
    func_80068D5C(rdram, ctx);
        goto after_1;
    // 0x8004DC80: swc1        $f0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f0.u32l;
    after_1:
    // 0x8004DC84: beq         $v0, $zero, L_8004DCF4
    if (ctx->r2 == 0) {
        // 0x8004DC88: lui         $v1, 0x8014
        ctx->r3 = S32(0X8014 << 16);
            goto L_8004DCF4;
    }
    // 0x8004DC88: lui         $v1, 0x8014
    ctx->r3 = S32(0X8014 << 16);
    // 0x8004DC8C: lwc1        $f0, 0xB4($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0XB4);
    // 0x8004DC90: add.s       $f0, $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f20.fl;
    // 0x8004DC94: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8004DC98: lwc1        $f2, -0x56CC($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X56CC);
    // 0x8004DC9C: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x8004DCA0: nop

    // 0x8004DCA4: bc1f        L_8004DE30
    if (!c1cs) {
        // 0x8004DCA8: swc1        $f0, 0xB4($s1)
        MEM_W(0XB4, ctx->r17) = ctx->f0.u32l;
            goto L_8004DE30;
    }
    // 0x8004DCA8: swc1        $f0, 0xB4($s1)
    MEM_W(0XB4, ctx->r17) = ctx->f0.u32l;
    // 0x8004DCAC: lw          $t0, 0x40($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X40);
    // 0x8004DCB0: lw          $t1, 0x44($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X44);
    // 0x8004DCB4: lw          $t2, 0x48($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X48);
    // 0x8004DCB8: sw          $t0, 0x10($s1)
    MEM_W(0X10, ctx->r17) = ctx->r8;
    // 0x8004DCBC: sw          $t1, 0x14($s1)
    MEM_W(0X14, ctx->r17) = ctx->r9;
    // 0x8004DCC0: sw          $t2, 0x18($s1)
    MEM_W(0X18, ctx->r17) = ctx->r10;
    // 0x8004DCC4: lwc1        $f0, 0x10($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X10);
    // 0x8004DCC8: lwc1        $f2, 0x14($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0X14);
    // 0x8004DCCC: lwc1        $f4, 0x18($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X18);
    // 0x8004DCD0: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x8004DCD4: swc1        $f0, 0x4C($s1)
    MEM_W(0X4C, ctx->r17) = ctx->f0.u32l;
    // 0x8004DCD8: swc1        $f2, 0x50($s1)
    MEM_W(0X50, ctx->r17) = ctx->f2.u32l;
    // 0x8004DCDC: jal         0x8004CD00
    // 0x8004DCE0: swc1        $f4, 0x54($s1)
    MEM_W(0X54, ctx->r17) = ctx->f4.u32l;
    func_8004CD00(rdram, ctx);
        goto after_2;
    // 0x8004DCE0: swc1        $f4, 0x54($s1)
    MEM_W(0X54, ctx->r17) = ctx->f4.u32l;
    after_2:
    // 0x8004DCE4: jal         0x80066A50
    // 0x8004DCE8: nop

    func_80066A50(rdram, ctx);
        goto after_3;
    // 0x8004DCE8: nop

    after_3:
    // 0x8004DCEC: j           L_8004DE30
    // 0x8004DCF0: sw          $zero, 0xB4($s1)
    MEM_W(0XB4, ctx->r17) = 0;
        goto L_8004DE30;
    // 0x8004DCF0: sw          $zero, 0xB4($s1)
    MEM_W(0XB4, ctx->r17) = 0;
L_8004DCF4:
    // 0x8004DCF4: lw          $a2, 0xC($s1)
    ctx->r6 = MEM_W(ctx->r17, 0XC);
    // 0x8004DCF8: lw          $v0, -0x35E0($s2)
    ctx->r2 = MEM_W(ctx->r18, -0X35E0);
    // 0x8004DCFC: lhu         $a0, -0x6A84($v1)
    ctx->r4 = MEM_HU(ctx->r3, -0X6A84);
    // 0x8004DD00: bne         $v0, $s3, L_8004DD10
    if (ctx->r2 != ctx->r19) {
        // 0x8004DD04: addiu       $s4, $sp, 0x10
        ctx->r20 = ADD32(ctx->r29, 0X10);
            goto L_8004DD10;
    }
    // 0x8004DD04: addiu       $s4, $sp, 0x10
    ctx->r20 = ADD32(ctx->r29, 0X10);
    // 0x8004DD08: j           L_8004DDA8
    // 0x8004DD0C: ori         $a0, $zero, 0xFFFF
    ctx->r4 = 0 | 0XFFFF;
        goto L_8004DDA8;
    // 0x8004DD0C: ori         $a0, $zero, 0xFFFF
    ctx->r4 = 0 | 0XFFFF;
L_8004DD10:
    // 0x8004DD10: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x8004DD14: addiu       $v1, $v1, 0x7DB8
    ctx->r3 = ADD32(ctx->r3, 0X7DB8);
    // 0x8004DD18: sll         $v0, $a2, 2
    ctx->r2 = S32(ctx->r6 << 2);
    // 0x8004DD1C: addu        $v0, $v0, $a2
    ctx->r2 = ADD32(ctx->r2, ctx->r6);
    // 0x8004DD20: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8004DD24: addu        $v0, $v0, $a2
    ctx->r2 = ADD32(ctx->r2, ctx->r6);
    // 0x8004DD28: sll         $v0, $v0, 5
    ctx->r2 = S32(ctx->r2 << 5);
    // 0x8004DD2C: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8004DD30: lhu         $s0, 0x2($v0)
    ctx->r16 = MEM_HU(ctx->r2, 0X2);
    // 0x8004DD34: jal         0x8003FC28
    // 0x8004DD38: addiu       $a1, $sp, 0x68
    ctx->r5 = ADD32(ctx->r29, 0X68);
    func_8003FC28(rdram, ctx);
        goto after_4;
    // 0x8004DD38: addiu       $a1, $sp, 0x68
    ctx->r5 = ADD32(ctx->r29, 0X68);
    after_4:
    // 0x8004DD3C: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // 0x8004DD40: andi        $v1, $a0, 0xFFFF
    ctx->r3 = ctx->r4 & 0XFFFF;
    // 0x8004DD44: ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
    // 0x8004DD48: beql        $v1, $v0, L_8004DDA8
    if (ctx->r3 == ctx->r2) {
        // 0x8004DD4C: ori         $a0, $zero, 0xFFFF
        ctx->r4 = 0 | 0XFFFF;
            goto L_8004DDA8;
    }
    goto skip_0;
    // 0x8004DD4C: ori         $a0, $zero, 0xFFFF
    ctx->r4 = 0 | 0XFFFF;
    skip_0:
    // 0x8004DD50: andi        $s2, $s0, 0xFFFF
    ctx->r18 = ctx->r16 & 0XFFFF;
    // 0x8004DD54: addu        $s3, $v0, $zero
    ctx->r19 = ADD32(ctx->r2, 0);
    // 0x8004DD58: andi        $s0, $a0, 0xFFFF
    ctx->r16 = ctx->r4 & 0XFFFF;
L_8004DD5C:
    // 0x8004DD5C: jal         0x8004013C
    // 0x8004DD60: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_8004013C(rdram, ctx);
        goto after_5;
    // 0x8004DD60: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_5:
    // 0x8004DD64: lw          $a0, 0xC($v0)
    ctx->r4 = MEM_W(ctx->r2, 0XC);
    // 0x8004DD68: beq         $a0, $zero, L_8004DD8C
    if (ctx->r4 == 0) {
        // 0x8004DD6C: nop
    
            goto L_8004DD8C;
    }
    // 0x8004DD6C: nop

    // 0x8004DD70: beq         $s0, $s2, L_8004DD8C
    if (ctx->r16 == ctx->r18) {
        // 0x8004DD74: addu        $a1, $s4, $zero
        ctx->r5 = ADD32(ctx->r20, 0);
            goto L_8004DD8C;
    }
    // 0x8004DD74: addu        $a1, $s4, $zero
    ctx->r5 = ADD32(ctx->r20, 0);
    // 0x8004DD78: addiu       $a2, $sp, 0x20
    ctx->r6 = ADD32(ctx->r29, 0X20);
    // 0x8004DD7C: jal         0x8006A944
    // 0x8004DD80: addiu       $a3, $sp, 0x40
    ctx->r7 = ADD32(ctx->r29, 0X40);
    func_8006A944(rdram, ctx);
        goto after_6;
    // 0x8004DD80: addiu       $a3, $sp, 0x40
    ctx->r7 = ADD32(ctx->r29, 0X40);
    after_6:
    // 0x8004DD84: bne         $v0, $zero, L_8004DDA8
    if (ctx->r2 != 0) {
        // 0x8004DD88: addu        $a0, $s0, $zero
        ctx->r4 = ADD32(ctx->r16, 0);
            goto L_8004DDA8;
    }
    // 0x8004DD88: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
L_8004DD8C:
    // 0x8004DD8C: jal         0x8003EEF4
    // 0x8004DD90: addiu       $a0, $sp, 0x68
    ctx->r4 = ADD32(ctx->r29, 0X68);
    func_8003EEF4(rdram, ctx);
        goto after_7;
    // 0x8004DD90: addiu       $a0, $sp, 0x68
    ctx->r4 = ADD32(ctx->r29, 0X68);
    after_7:
    // 0x8004DD94: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // 0x8004DD98: andi        $v0, $a0, 0xFFFF
    ctx->r2 = ctx->r4 & 0XFFFF;
    // 0x8004DD9C: bnel        $v0, $s3, L_8004DD5C
    if (ctx->r2 != ctx->r19) {
        // 0x8004DDA0: andi        $s0, $a0, 0xFFFF
        ctx->r16 = ctx->r4 & 0XFFFF;
            goto L_8004DD5C;
    }
    goto skip_1;
    // 0x8004DDA0: andi        $s0, $a0, 0xFFFF
    ctx->r16 = ctx->r4 & 0XFFFF;
    skip_1:
    // 0x8004DDA4: ori         $a0, $zero, 0xFFFF
    ctx->r4 = 0 | 0XFFFF;
L_8004DDA8:
    // 0x8004DDA8: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    // 0x8004DDAC: ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
    // 0x8004DDB0: beql        $a0, $v0, L_8004DE30
    if (ctx->r4 == ctx->r2) {
        // 0x8004DDB4: sw          $zero, 0xB4($s1)
        MEM_W(0XB4, ctx->r17) = 0;
            goto L_8004DE30;
    }
    goto skip_2;
    // 0x8004DDB4: sw          $zero, 0xB4($s1)
    MEM_W(0XB4, ctx->r17) = 0;
    skip_2:
    // 0x8004DDB8: lwc1        $f0, 0xB4($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0XB4);
    // 0x8004DDBC: add.s       $f0, $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f20.fl;
    // 0x8004DDC0: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8004DDC4: lwc1        $f2, -0x56C8($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X56C8);
    // 0x8004DDC8: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x8004DDCC: nop

    // 0x8004DDD0: bc1f        L_8004DE30
    if (!c1cs) {
        // 0x8004DDD4: swc1        $f0, 0xB4($s1)
        MEM_W(0XB4, ctx->r17) = ctx->f0.u32l;
            goto L_8004DE30;
    }
    // 0x8004DDD4: swc1        $f0, 0xB4($s1)
    MEM_W(0XB4, ctx->r17) = ctx->f0.u32l;
    // 0x8004DDD8: jal         0x8004015C
    // 0x8004DDDC: nop

    func_8004015C(rdram, ctx);
        goto after_8;
    // 0x8004DDDC: nop

    after_8:
    // 0x8004DDE0: lwc1        $f0, 0x10($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X10);
    // 0x8004DDE4: lwc1        $f2, 0x0($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8004DDE8: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x8004DDEC: swc1        $f0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f0.u32l;
    // 0x8004DDF0: lwc1        $f0, 0x14($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X14);
    // 0x8004DDF4: lwc1        $f2, 0x4($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X4);
    // 0x8004DDF8: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x8004DDFC: swc1        $f0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f0.u32l;
    // 0x8004DE00: lwc1        $f0, 0x18($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X18);
    // 0x8004DE04: lwc1        $f2, 0x8($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X8);
    // 0x8004DE08: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x8004DE0C: swc1        $f0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f0.u32l;
    // 0x8004DE10: lwc1        $f0, 0x14($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X14);
    // 0x8004DE14: sub.s       $f0, $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f20.fl;
    // 0x8004DE18: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x8004DE1C: swc1        $f0, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->f0.u32l;
    // 0x8004DE20: jal         0x8004CD00
    // 0x8004DE24: swc1        $f0, 0x50($a0)
    MEM_W(0X50, ctx->r4) = ctx->f0.u32l;
    func_8004CD00(rdram, ctx);
        goto after_9;
    // 0x8004DE24: swc1        $f0, 0x50($a0)
    MEM_W(0X50, ctx->r4) = ctx->f0.u32l;
    after_9:
    // 0x8004DE28: jal         0x80066A50
    // 0x8004DE2C: nop

    func_80066A50(rdram, ctx);
        goto after_10;
    // 0x8004DE2C: nop

    after_10:
L_8004DE30:
    // 0x8004DE30: lw          $ra, 0x84($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X84);
    // 0x8004DE34: lw          $s4, 0x80($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X80);
    // 0x8004DE38: lw          $s3, 0x7C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X7C);
    // 0x8004DE3C: lw          $s2, 0x78($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X78);
    // 0x8004DE40: lw          $s1, 0x74($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X74);
    // 0x8004DE44: lw          $s0, 0x70($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X70);
    // 0x8004DE48: ldc1        $f20, 0x88($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X88);
    // 0x8004DE4C: jr          $ra
    // 0x8004DE50: addiu       $sp, $sp, 0x90
    ctx->r29 = ADD32(ctx->r29, 0X90);
    return;
    // 0x8004DE50: addiu       $sp, $sp, 0x90
    ctx->r29 = ADD32(ctx->r29, 0X90);
;}
RECOMP_FUNC void func_8004DE54(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8004DE54: addiu       $sp, $sp, -0x70
    ctx->r29 = ADD32(ctx->r29, -0X70);
    // 0x8004DE58: sw          $s1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r17;
    // 0x8004DE5C: addu        $s1, $a0, $zero
    ctx->r17 = ADD32(ctx->r4, 0);
    // 0x8004DE60: sw          $ra, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r31;
    // 0x8004DE64: sw          $s0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r16;
    // 0x8004DE68: sdc1        $f22, 0x68($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X68, ctx->r29);
    // 0x8004DE6C: sdc1        $f20, 0x60($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X60, ctx->r29);
    // 0x8004DE70: lhu         $v0, 0x4($s1)
    ctx->r2 = MEM_HU(ctx->r17, 0X4);
    // 0x8004DE74: mtc1        $a1, $f22
    ctx->f22.u32l = ctx->r5;
    // 0x8004DE78: bne         $v0, $zero, L_8004E124
    if (ctx->r2 != 0) {
        // 0x8004DE7C: lui         $v0, 0x8013
        ctx->r2 = S32(0X8013 << 16);
            goto L_8004E124;
    }
    // 0x8004DE7C: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8004DE80: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
    // 0x8004DE84: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x8004DE88: lhu         $v0, 0xB88($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0XB88);
    // 0x8004DE8C: lhu         $v1, -0x41E2($v1)
    ctx->r3 = MEM_HU(ctx->r3, -0X41E2);
    // 0x8004DE90: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    // 0x8004DE94: mov.s       $f10, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    ctx->f10.fl = ctx->f20.fl;
    // 0x8004DE98: and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // 0x8004DE9C: beq         $v0, $zero, L_8004DF40
    if (ctx->r2 == 0) {
        // 0x8004DEA0: mov.s       $f8, $f20
        CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    ctx->f8.fl = ctx->f20.fl;
            goto L_8004DF40;
    }
    // 0x8004DEA0: mov.s       $f8, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    ctx->f8.fl = ctx->f20.fl;
    // 0x8004DEA4: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x8004DEA8: addiu       $v1, $v0, -0x4228
    ctx->r3 = ADD32(ctx->r2, -0X4228);
    // 0x8004DEAC: lwc1        $f2, -0x4228($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, -0X4228);
    // 0x8004DEB0: abs.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = fabsf(ctx->f2.fl);
    // 0x8004DEB4: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8004DEB8: lwc1        $f4, -0x56C4($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X56C4);
    // 0x8004DEBC: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x8004DEC0: nop

    // 0x8004DEC4: bc1t        L_8004DEE4
    if (c1cs) {
        // 0x8004DEC8: nop
    
            goto L_8004DEE4;
    }
    // 0x8004DEC8: nop

    // 0x8004DECC: lwc1        $f14, 0x4($v1)
    ctx->f14.u32l = MEM_W(ctx->r3, 0X4);
    // 0x8004DED0: abs.s       $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f0.fl = fabsf(ctx->f14.fl);
    // 0x8004DED4: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x8004DED8: nop

    // 0x8004DEDC: bc1f        L_8004DF44
    if (!c1cs) {
        // 0x8004DEE0: lui         $v0, 0x8013
        ctx->r2 = S32(0X8013 << 16);
            goto L_8004DF44;
    }
    // 0x8004DEE0: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
L_8004DEE4:
    // 0x8004DEE4: abs.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = fabsf(ctx->f2.fl);
    // 0x8004DEE8: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x8004DEEC: nop

    // 0x8004DEF0: bc1f        L_8004DF0C
    if (!c1cs) {
        // 0x8004DEF4: nop
    
            goto L_8004DF0C;
    }
    // 0x8004DEF4: nop

    // 0x8004DEF8: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8004DEFC: lwc1        $f0, -0x56C0($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X56C0);
    // 0x8004DF00: mul.s       $f0, $f2, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x8004DF04: nop

    // 0x8004DF08: mul.s       $f8, $f0, $f22
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f22.fl);
L_8004DF0C:
    // 0x8004DF0C: lwc1        $f2, 0x4($v1)
    ctx->f2.u32l = MEM_W(ctx->r3, 0X4);
    // 0x8004DF10: abs.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = fabsf(ctx->f2.fl);
    // 0x8004DF14: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x8004DF18: nop

    // 0x8004DF1C: bc1f        L_8004E000
    if (!c1cs) {
        // 0x8004DF20: lui         $v0, 0x8013
        ctx->r2 = S32(0X8013 << 16);
            goto L_8004E000;
    }
    // 0x8004DF20: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8004DF24: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8004DF28: lwc1        $f0, -0x56BC($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X56BC);
    // 0x8004DF2C: mul.s       $f0, $f2, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x8004DF30: nop

    // 0x8004DF34: mul.s       $f10, $f0, $f22
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f22.fl);
    // 0x8004DF38: j           L_8004E004
    // 0x8004DF3C: nop

        goto L_8004E004;
    // 0x8004DF3C: nop

L_8004DF40:
    // 0x8004DF40: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
L_8004DF44:
    // 0x8004DF44: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
    // 0x8004DF48: lhu         $v0, 0xB88($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0XB88);
    // 0x8004DF4C: lhu         $v1, -0x41C8($v1)
    ctx->r3 = MEM_HU(ctx->r3, -0X41C8);
    // 0x8004DF50: and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // 0x8004DF54: beq         $v0, $zero, L_8004DF98
    if (ctx->r2 == 0) {
        // 0x8004DF58: lui         $v0, 0x8011
        ctx->r2 = S32(0X8011 << 16);
            goto L_8004DF98;
    }
    // 0x8004DF58: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x8004DF5C: lwc1        $f4, -0x4228($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, -0X4228);
    // 0x8004DF60: abs.s       $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = fabsf(ctx->f4.fl);
    // 0x8004DF64: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8004DF68: lwc1        $f0, -0x56B8($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X56B8);
    // 0x8004DF6C: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x8004DF70: nop

    // 0x8004DF74: bc1f        L_8004E000
    if (!c1cs) {
        // 0x8004DF78: lui         $v0, 0x8013
        ctx->r2 = S32(0X8013 << 16);
            goto L_8004E000;
    }
    // 0x8004DF78: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8004DF7C: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8004DF80: lwc1        $f0, -0x56B4($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X56B4);
    // 0x8004DF84: mul.s       $f0, $f4, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x8004DF88: nop

    // 0x8004DF8C: mul.s       $f12, $f0, $f22
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f12.fl = MUL_S(ctx->f0.fl, ctx->f22.fl);
    // 0x8004DF90: j           L_8004E004
    // 0x8004DF94: nop

        goto L_8004E004;
    // 0x8004DF94: nop

L_8004DF98:
    // 0x8004DF98: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
    // 0x8004DF9C: addiu       $v0, $v1, -0x4228
    ctx->r2 = ADD32(ctx->r3, -0X4228);
    // 0x8004DFA0: lwc1        $f4, 0x4($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X4);
    // 0x8004DFA4: abs.s       $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = fabsf(ctx->f4.fl);
    // 0x8004DFA8: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8004DFAC: lwc1        $f6, -0x56B0($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X56B0);
    // 0x8004DFB0: c.lt.s      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.fl < ctx->f0.fl;
    // 0x8004DFB4: nop

    // 0x8004DFB8: bc1f        L_8004DFD4
    if (!c1cs) {
        // 0x8004DFBC: nop
    
            goto L_8004DFD4;
    }
    // 0x8004DFBC: nop

    // 0x8004DFC0: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8004DFC4: ldc1        $f2, -0x56A8($at)
    CHECK_FR(ctx, 2);
    ctx->f2.u64 = LD(ctx->r1, -0X56A8);
    // 0x8004DFC8: cvt.d.s     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f0.d = CVT_D_S(ctx->f4.fl);
    // 0x8004DFCC: mul.d       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f2.d); 
    ctx->f0.d = MUL_D(ctx->f0.d, ctx->f2.d);
    // 0x8004DFD0: cvt.s.d     $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); 
    ctx->f20.fl = CVT_S_D(ctx->f0.d);
L_8004DFD4:
    // 0x8004DFD4: lwc1        $f2, -0x4228($v1)
    ctx->f2.u32l = MEM_W(ctx->r3, -0X4228);
    // 0x8004DFD8: abs.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = fabsf(ctx->f2.fl);
    // 0x8004DFDC: c.lt.s      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.fl < ctx->f0.fl;
    // 0x8004DFE0: nop

    // 0x8004DFE4: bc1f        L_8004E004
    if (!c1cs) {
        // 0x8004DFE8: lui         $v0, 0x8013
        ctx->r2 = S32(0X8013 << 16);
            goto L_8004E004;
    }
    // 0x8004DFE8: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8004DFEC: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8004DFF0: lwc1        $f0, -0x56A0($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X56A0);
    // 0x8004DFF4: mul.s       $f0, $f2, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x8004DFF8: nop

    // 0x8004DFFC: mul.s       $f8, $f0, $f22
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f22.fl);
L_8004E000:
    // 0x8004E000: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
L_8004E004:
    // 0x8004E004: lhu         $v1, 0xB88($v0)
    ctx->r3 = MEM_HU(ctx->r2, 0XB88);
    // 0x8004E008: andi        $v0, $v1, 0x2000
    ctx->r2 = ctx->r3 & 0X2000;
    // 0x8004E00C: beq         $v0, $zero, L_8004E020
    if (ctx->r2 == 0) {
        // 0x8004E010: andi        $v0, $v1, 0x2
        ctx->r2 = ctx->r3 & 0X2;
            goto L_8004E020;
    }
    // 0x8004E010: andi        $v0, $v1, 0x2
    ctx->r2 = ctx->r3 & 0X2;
    // 0x8004E014: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8004E018: lwc1        $f0, -0x569C($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X569C);
    // 0x8004E01C: mul.s       $f20, $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f20.fl = MUL_S(ctx->f20.fl, ctx->f0.fl);
L_8004E020:
    // 0x8004E020: beq         $v0, $zero, L_8004E034
    if (ctx->r2 == 0) {
        // 0x8004E024: nop
    
            goto L_8004E034;
    }
    // 0x8004E024: nop

    // 0x8004E028: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8004E02C: lwc1        $f0, -0x5698($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X5698);
    // 0x8004E030: div.s       $f20, $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f20.fl = DIV_S(ctx->f20.fl, ctx->f0.fl);
L_8004E034:
    // 0x8004E034: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x8004E038: mfc1        $a2, $f10
    ctx->r6 = (int32_t)ctx->f10.u32l;
    // 0x8004E03C: mfc1        $a3, $f12
    ctx->r7 = (int32_t)ctx->f12.u32l;
    // 0x8004E040: jal         0x800AA570
    // 0x8004E044: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    func_800AA570(rdram, ctx);
        goto after_0;
    // 0x8004E044: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    after_0:
    // 0x8004E048: addiu       $s0, $s1, 0x28
    ctx->r16 = ADD32(ctx->r17, 0X28);
    // 0x8004E04C: lwc1        $f0, 0x4C($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X4C);
    // 0x8004E050: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x8004E054: swc1        $f0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f0.u32l;
    // 0x8004E058: lwc1        $f0, 0x50($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X50);
    // 0x8004E05C: addiu       $a1, $sp, 0x10
    ctx->r5 = ADD32(ctx->r29, 0X10);
    // 0x8004E060: swc1        $f0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f0.u32l;
    // 0x8004E064: lwc1        $f0, 0x54($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X54);
    // 0x8004E068: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    // 0x8004E06C: jal         0x800191C4
    // 0x8004E070: swc1        $f0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f0.u32l;
    func_800191C4(rdram, ctx);
        goto after_1;
    // 0x8004E070: swc1        $f0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f0.u32l;
    after_1:
    // 0x8004E074: lwc1        $f0, 0x40($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X40);
    // 0x8004E078: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x8004E07C: swc1        $f0, 0x4C($s1)
    MEM_W(0X4C, ctx->r17) = ctx->f0.u32l;
    // 0x8004E080: lwc1        $f0, 0x44($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X44);
    // 0x8004E084: addiu       $a1, $s1, 0x10
    ctx->r5 = ADD32(ctx->r17, 0X10);
    // 0x8004E088: swc1        $f0, 0x50($s1)
    MEM_W(0X50, ctx->r17) = ctx->f0.u32l;
    // 0x8004E08C: lwc1        $f0, 0x48($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X48);
    // 0x8004E090: addiu       $a2, $s1, 0x1C
    ctx->r6 = ADD32(ctx->r17, 0X1C);
    // 0x8004E094: jal         0x800A9B80
    // 0x8004E098: swc1        $f0, 0x54($s1)
    MEM_W(0X54, ctx->r17) = ctx->f0.u32l;
    func_800A9B80(rdram, ctx);
        goto after_2;
    // 0x8004E098: swc1        $f0, 0x54($s1)
    MEM_W(0X54, ctx->r17) = ctx->f0.u32l;
    after_2:
    // 0x8004E09C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8004E0A0: c.eq.s      $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f20.fl == ctx->f0.fl;
    // 0x8004E0A4: nop

    // 0x8004E0A8: bc1t        L_8004E11C
    if (c1cs) {
        // 0x8004E0AC: nop
    
            goto L_8004E11C;
    }
    // 0x8004E0AC: nop

    // 0x8004E0B0: lwc1        $f2, 0x30($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0X30);
    // 0x8004E0B4: mul.s       $f4, $f20, $f22
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f4.fl = MUL_S(ctx->f20.fl, ctx->f22.fl);
    // 0x8004E0B8: swc1        $f2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f2.u32l;
    // 0x8004E0BC: lwc1        $f0, 0x3C($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X3C);
    // 0x8004E0C0: swc1        $f0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f0.u32l;
    // 0x8004E0C4: lwc1        $f0, 0x48($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X48);
    // 0x8004E0C8: mul.s       $f2, $f4, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = MUL_S(ctx->f4.fl, ctx->f2.fl);
    // 0x8004E0CC: swc1        $f0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f0.u32l;
    // 0x8004E0D0: lwc1        $f0, 0x10($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X10);
    // 0x8004E0D4: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x8004E0D8: swc1        $f0, 0x10($s1)
    MEM_W(0X10, ctx->r17) = ctx->f0.u32l;
    // 0x8004E0DC: lwc1        $f2, 0x44($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X44);
    // 0x8004E0E0: mul.s       $f2, $f4, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = MUL_S(ctx->f4.fl, ctx->f2.fl);
    // 0x8004E0E4: lwc1        $f0, 0x14($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X14);
    // 0x8004E0E8: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x8004E0EC: swc1        $f0, 0x14($s1)
    MEM_W(0X14, ctx->r17) = ctx->f0.u32l;
    // 0x8004E0F0: lwc1        $f0, 0x48($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X48);
    // 0x8004E0F4: mul.s       $f4, $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x8004E0F8: lwc1        $f0, 0x18($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X18);
    // 0x8004E0FC: add.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f4.fl;
    // 0x8004E100: lwc1        $f2, 0x14($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0X14);
    // 0x8004E104: swc1        $f0, 0x18($s1)
    MEM_W(0X18, ctx->r17) = ctx->f0.u32l;
    // 0x8004E108: lwc1        $f0, 0x10($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X10);
    // 0x8004E10C: lwc1        $f4, 0x18($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X18);
    // 0x8004E110: swc1        $f2, 0x50($s1)
    MEM_W(0X50, ctx->r17) = ctx->f2.u32l;
    // 0x8004E114: swc1        $f0, 0x4C($s1)
    MEM_W(0X4C, ctx->r17) = ctx->f0.u32l;
    // 0x8004E118: swc1        $f4, 0x54($s1)
    MEM_W(0X54, ctx->r17) = ctx->f4.u32l;
L_8004E11C:
    // 0x8004E11C: jal         0x8004CD00
    // 0x8004E120: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    func_8004CD00(rdram, ctx);
        goto after_3;
    // 0x8004E120: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    after_3:
L_8004E124:
    // 0x8004E124: lw          $ra, 0x58($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X58);
    // 0x8004E128: lw          $s1, 0x54($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X54);
    // 0x8004E12C: lw          $s0, 0x50($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X50);
    // 0x8004E130: ldc1        $f22, 0x68($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X68);
    // 0x8004E134: ldc1        $f20, 0x60($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X60);
    // 0x8004E138: jr          $ra
    // 0x8004E13C: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
    return;
    // 0x8004E13C: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
;}
RECOMP_FUNC void func_8004E140(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8004E140: addiu       $sp, $sp, -0x130
    ctx->r29 = ADD32(ctx->r29, -0X130);
    // 0x8004E144: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8004E148: sdc1        $f22, 0x120($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X120, ctx->r29);
    // 0x8004E14C: mtc1        $a2, $f22
    ctx->f22.u32l = ctx->r6;
    // 0x8004E150: lbu         $v0, 0x7CF4($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7CF4);
    // 0x8004E154: sw          $s0, 0x100($sp)
    MEM_W(0X100, ctx->r29) = ctx->r16;
    // 0x8004E158: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x8004E15C: sw          $s2, 0x108($sp)
    MEM_W(0X108, ctx->r29) = ctx->r18;
    // 0x8004E160: sw          $ra, 0x114($sp)
    MEM_W(0X114, ctx->r29) = ctx->r31;
    // 0x8004E164: sw          $s4, 0x110($sp)
    MEM_W(0X110, ctx->r29) = ctx->r20;
    // 0x8004E168: sw          $s3, 0x10C($sp)
    MEM_W(0X10C, ctx->r29) = ctx->r19;
    // 0x8004E16C: sw          $s1, 0x104($sp)
    MEM_W(0X104, ctx->r29) = ctx->r17;
    // 0x8004E170: sdc1        $f24, 0x128($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X128, ctx->r29);
    // 0x8004E174: sdc1        $f20, 0x118($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X118, ctx->r29);
    // 0x8004E178: bne         $v0, $zero, L_8004ED60
    if (ctx->r2 != 0) {
        // 0x8004E17C: addu        $s2, $a1, $zero
        ctx->r18 = ADD32(ctx->r5, 0);
            goto L_8004ED60;
    }
    // 0x8004E17C: addu        $s2, $a1, $zero
    ctx->r18 = ADD32(ctx->r5, 0);
    // 0x8004E180: lwc1        $f2, 0xC4($s2)
    ctx->f2.u32l = MEM_W(ctx->r18, 0XC4);
    // 0x8004E184: lwc1        $f0, 0xC8($s2)
    ctx->f0.u32l = MEM_W(ctx->r18, 0XC8);
    // 0x8004E188: div.s       $f20, $f2, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f20.fl = DIV_S(ctx->f2.fl, ctx->f0.fl);
    // 0x8004E18C: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8004E190: ldc1        $f2, -0x5690($at)
    CHECK_FR(ctx, 2);
    ctx->f2.u64 = LD(ctx->r1, -0X5690);
    // 0x8004E194: cvt.d.s     $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); 
    ctx->f0.d = CVT_D_S(ctx->f20.fl);
    // 0x8004E198: c.lt.d      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.d < ctx->f0.d;
    // 0x8004E19C: nop

    // 0x8004E1A0: bc1f        L_8004E1B0
    if (!c1cs) {
        // 0x8004E1A4: nop
    
            goto L_8004E1B0;
    }
    // 0x8004E1A4: nop

    // 0x8004E1A8: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8004E1AC: lwc1        $f20, -0x5688($at)
    ctx->f20.u32l = MEM_W(ctx->r1, -0X5688);
L_8004E1B0:
    // 0x8004E1B0: lhu         $v0, 0x0($s2)
    ctx->r2 = MEM_HU(ctx->r18, 0X0);
    // 0x8004E1B4: andi        $v0, $v0, 0x20
    ctx->r2 = ctx->r2 & 0X20;
    // 0x8004E1B8: beq         $v0, $zero, L_8004E224
    if (ctx->r2 == 0) {
        // 0x8004E1BC: lui         $v0, 0x8014
        ctx->r2 = S32(0X8014 << 16);
            goto L_8004E224;
    }
    // 0x8004E1BC: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x8004E1C0: lwc1        $f0, 0xEC($s2)
    ctx->f0.u32l = MEM_W(ctx->r18, 0XEC);
    // 0x8004E1C4: sub.s       $f0, $f0, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f22.fl;
    // 0x8004E1C8: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x8004E1CC: c.le.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl <= ctx->f2.fl;
    // 0x8004E1D0: nop

    // 0x8004E1D4: bc1f        L_8004E224
    if (!c1cs) {
        // 0x8004E1D8: swc1        $f0, 0xEC($s2)
        MEM_W(0XEC, ctx->r18) = ctx->f0.u32l;
            goto L_8004E224;
    }
    // 0x8004E1D8: swc1        $f0, 0xEC($s2)
    MEM_W(0XEC, ctx->r18) = ctx->f0.u32l;
    // 0x8004E1DC: lui         $a2, 0x800A
    ctx->r6 = S32(0X800A << 16);
    // 0x8004E1E0: lbu         $v0, -0x1444($a2)
    ctx->r2 = MEM_BU(ctx->r6, -0X1444);
    // 0x8004E1E4: beq         $v0, $zero, L_8004E204
    if (ctx->r2 == 0) {
        // 0x8004E1E8: addiu       $v0, $zero, 0x3
        ctx->r2 = ADD32(0, 0X3);
            goto L_8004E204;
    }
    // 0x8004E1E8: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x8004E1EC: lw          $v1, 0x8($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X8);
    // 0x8004E1F0: bne         $v1, $v0, L_8004E204
    if (ctx->r3 != ctx->r2) {
        // 0x8004E1F4: addu        $a1, $zero, $zero
        ctx->r5 = ADD32(0, 0);
            goto L_8004E204;
    }
    // 0x8004E1F4: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x8004E1F8: lw          $a0, 0xC($s2)
    ctx->r4 = MEM_W(ctx->r18, 0XC);
    // 0x8004E1FC: j           L_8004E20C
    // 0x8004E200: sb          $zero, -0x1444($a2)
    MEM_B(-0X1444, ctx->r6) = 0;
        goto L_8004E20C;
    // 0x8004E200: sb          $zero, -0x1444($a2)
    MEM_B(-0X1444, ctx->r6) = 0;
L_8004E204:
    // 0x8004E204: lw          $a0, 0xC($s2)
    ctx->r4 = MEM_W(ctx->r18, 0XC);
    // 0x8004E208: lw          $a1, 0xF0($s2)
    ctx->r5 = MEM_W(ctx->r18, 0XF0);
L_8004E20C:
    // 0x8004E20C: jal         0x80052D4C
    // 0x8004E210: nop

    func_80052D4C(rdram, ctx);
        goto after_0;
    // 0x8004E210: nop

    after_0:
    // 0x8004E214: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8004E218: lwc1        $f0, -0x5684($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X5684);
    // 0x8004E21C: swc1        $f0, 0xEC($s2)
    MEM_W(0XEC, ctx->r18) = ctx->f0.u32l;
    // 0x8004E220: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
L_8004E224:
    // 0x8004E224: lbu         $v0, -0x76DB($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X76DB);
    // 0x8004E228: bne         $v0, $zero, L_8004E240
    if (ctx->r2 != 0) {
        // 0x8004E22C: lui         $v0, 0x8014
        ctx->r2 = S32(0X8014 << 16);
            goto L_8004E240;
    }
    // 0x8004E22C: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x8004E230: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x8004E234: lbu         $v0, -0x76DA($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X76DA);
    // 0x8004E238: beq         $v0, $zero, L_8004E270
    if (ctx->r2 == 0) {
        // 0x8004E23C: lui         $v0, 0x8014
        ctx->r2 = S32(0X8014 << 16);
            goto L_8004E270;
    }
    // 0x8004E23C: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
L_8004E240:
    // 0x8004E240: lbu         $v0, -0x77C8($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X77C8);
    // 0x8004E244: beq         $v0, $zero, L_8004E270
    if (ctx->r2 == 0) {
        // 0x8004E248: nop
    
            goto L_8004E270;
    }
    // 0x8004E248: nop

    // 0x8004E24C: lhu         $v0, 0x0($s2)
    ctx->r2 = MEM_HU(ctx->r18, 0X0);
    // 0x8004E250: andi        $v0, $v0, 0x80
    ctx->r2 = ctx->r2 & 0X80;
    // 0x8004E254: beq         $v0, $zero, L_8004E270
    if (ctx->r2 == 0) {
        // 0x8004E258: nop
    
            goto L_8004E270;
    }
    // 0x8004E258: nop

    // 0x8004E25C: mfc1        $a1, $f22
    ctx->r5 = (int32_t)ctx->f22.u32l;
    // 0x8004E260: jal         0x8004DE54
    // 0x8004E264: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    func_8004DE54(rdram, ctx);
        goto after_1;
    // 0x8004E264: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    after_1:
    // 0x8004E268: j           L_8004ED60
    // 0x8004E26C: nop

        goto L_8004ED60;
    // 0x8004E26C: nop

L_8004E270:
    // 0x8004E270: lhu         $v1, 0x2($s2)
    ctx->r3 = MEM_HU(ctx->r18, 0X2);
    // 0x8004E274: slti        $v0, $v1, 0x4
    ctx->r2 = SIGNED(ctx->r3) < 0X4 ? 1 : 0;
    // 0x8004E278: beq         $v0, $zero, L_8004E298
    if (ctx->r2 == 0) {
        // 0x8004E27C: slti        $v0, $v1, 0x2
        ctx->r2 = SIGNED(ctx->r3) < 0X2 ? 1 : 0;
            goto L_8004E298;
    }
    // 0x8004E27C: slti        $v0, $v1, 0x2
    ctx->r2 = SIGNED(ctx->r3) < 0X2 ? 1 : 0;
    // 0x8004E280: beq         $v0, $zero, L_8004E2AC
    if (ctx->r2 == 0) {
        // 0x8004E284: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_8004E2AC;
    }
    // 0x8004E284: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8004E288: beq         $v1, $v0, L_8004E8EC
    if (ctx->r3 == ctx->r2) {
        // 0x8004E28C: addiu       $a0, $s2, 0x28
        ctx->r4 = ADD32(ctx->r18, 0X28);
            goto L_8004E8EC;
    }
    // 0x8004E28C: addiu       $a0, $s2, 0x28
    ctx->r4 = ADD32(ctx->r18, 0X28);
    // 0x8004E290: j           L_8004ECF0
    // 0x8004E294: addiu       $a1, $s2, 0x10
    ctx->r5 = ADD32(ctx->r18, 0X10);
        goto L_8004ECF0;
    // 0x8004E294: addiu       $a1, $s2, 0x10
    ctx->r5 = ADD32(ctx->r18, 0X10);
L_8004E298:
    // 0x8004E298: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // 0x8004E29C: beq         $v1, $v0, L_8004E9F8
    if (ctx->r3 == ctx->r2) {
        // 0x8004E2A0: addiu       $a0, $s2, 0x28
        ctx->r4 = ADD32(ctx->r18, 0X28);
            goto L_8004E9F8;
    }
    // 0x8004E2A0: addiu       $a0, $s2, 0x28
    ctx->r4 = ADD32(ctx->r18, 0X28);
    // 0x8004E2A4: j           L_8004ECF0
    // 0x8004E2A8: addiu       $a1, $s2, 0x10
    ctx->r5 = ADD32(ctx->r18, 0X10);
        goto L_8004ECF0;
    // 0x8004E2A8: addiu       $a1, $s2, 0x10
    ctx->r5 = ADD32(ctx->r18, 0X10);
L_8004E2AC:
    // 0x8004E2AC: lw          $v0, 0x74($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X74);
    // 0x8004E2B0: addiu       $v1, $sp, 0x10
    ctx->r3 = ADD32(ctx->r29, 0X10);
    // 0x8004E2B4: addiu       $a0, $v0, 0x30
    ctx->r4 = ADD32(ctx->r2, 0X30);
L_8004E2B8:
    // 0x8004E2B8: lw          $t0, 0x0($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X0);
    // 0x8004E2BC: lw          $t1, 0x4($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X4);
    // 0x8004E2C0: lw          $t2, 0x8($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X8);
    // 0x8004E2C4: lw          $t3, 0xC($v0)
    ctx->r11 = MEM_W(ctx->r2, 0XC);
    // 0x8004E2C8: sw          $t0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r8;
    // 0x8004E2CC: sw          $t1, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r9;
    // 0x8004E2D0: sw          $t2, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r10;
    // 0x8004E2D4: sw          $t3, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r11;
    // 0x8004E2D8: addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
    // 0x8004E2DC: bne         $v0, $a0, L_8004E2B8
    if (ctx->r2 != ctx->r4) {
        // 0x8004E2E0: addiu       $v1, $v1, 0x10
        ctx->r3 = ADD32(ctx->r3, 0X10);
            goto L_8004E2B8;
    }
    // 0x8004E2E0: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
    // 0x8004E2E4: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    // 0x8004E2E8: addiu       $s3, $sp, 0x70
    ctx->r19 = ADD32(ctx->r29, 0X70);
    // 0x8004E2EC: addu        $a1, $s3, $zero
    ctx->r5 = ADD32(ctx->r19, 0);
    // 0x8004E2F0: addiu       $s1, $sp, 0x80
    ctx->r17 = ADD32(ctx->r29, 0X80);
    // 0x8004E2F4: lw          $t0, 0x78($s2)
    ctx->r8 = MEM_W(ctx->r18, 0X78);
    // 0x8004E2F8: lw          $t1, 0x7C($s2)
    ctx->r9 = MEM_W(ctx->r18, 0X7C);
    // 0x8004E2FC: lw          $t2, 0x80($s2)
    ctx->r10 = MEM_W(ctx->r18, 0X80);
    // 0x8004E300: sw          $t0, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r8;
    // 0x8004E304: sw          $t1, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r9;
    // 0x8004E308: sw          $t2, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r10;
    // 0x8004E30C: jal         0x800193E8
    // 0x8004E310: addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    func_800193E8(rdram, ctx);
        goto after_2;
    // 0x8004E310: addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    after_2:
    // 0x8004E314: lwc1        $f0, 0x80($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X80);
    // 0x8004E318: lwc1        $f2, 0x84($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X84);
    // 0x8004E31C: lwc1        $f4, 0x88($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X88);
    // 0x8004E320: swc1        $f0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f0.u32l;
    // 0x8004E324: swc1        $f2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f2.u32l;
    // 0x8004E328: swc1        $f4, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f4.u32l;
    // 0x8004E32C: lhu         $v1, 0x4($s2)
    ctx->r3 = MEM_HU(ctx->r18, 0X4);
    // 0x8004E330: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8004E334: bne         $v1, $v0, L_8004E7A8
    if (ctx->r3 != ctx->r2) {
        // 0x8004E338: addiu       $s0, $s2, 0x28
        ctx->r16 = ADD32(ctx->r18, 0X28);
            goto L_8004E7A8;
    }
    // 0x8004E338: addiu       $s0, $s2, 0x28
    ctx->r16 = ADD32(ctx->r18, 0X28);
    // 0x8004E33C: lwc1        $f0, 0x30($s2)
    ctx->f0.u32l = MEM_W(ctx->r18, 0X30);
    // 0x8004E340: swc1        $f0, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->f0.u32l;
    // 0x8004E344: lwc1        $f0, 0x3C($s2)
    ctx->f0.u32l = MEM_W(ctx->r18, 0X3C);
    // 0x8004E348: swc1        $f0, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->f0.u32l;
    // 0x8004E34C: lwc1        $f0, 0x48($s2)
    ctx->f0.u32l = MEM_W(ctx->r18, 0X48);
    // 0x8004E350: addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    // 0x8004E354: jal         0x800AA350
    // 0x8004E358: swc1        $f0, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->f0.u32l;
    func_800AA350(rdram, ctx);
        goto after_3;
    // 0x8004E358: swc1        $f0, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->f0.u32l;
    after_3:
    // 0x8004E35C: lwc1        $f0, 0x4C($s2)
    ctx->f0.u32l = MEM_W(ctx->r18, 0X4C);
    // 0x8004E360: lwc1        $f4, 0x34($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X34);
    // 0x8004E364: lwc1        $f2, 0x38($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X38);
    // 0x8004E368: swc1        $f0, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->f0.u32l;
    // 0x8004E36C: lwc1        $f6, 0x50($s2)
    ctx->f6.u32l = MEM_W(ctx->r18, 0X50);
    // 0x8004E370: swc1        $f6, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->f6.u32l;
    // 0x8004E374: lwc1        $f8, 0x54($s2)
    ctx->f8.u32l = MEM_W(ctx->r18, 0X54);
    // 0x8004E378: swc1        $f4, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->f4.u32l;
    // 0x8004E37C: sub.s       $f4, $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f4.fl - ctx->f0.fl;
    // 0x8004E380: swc1        $f2, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->f2.u32l;
    // 0x8004E384: sub.s       $f2, $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = ctx->f2.fl - ctx->f6.fl;
    // 0x8004E388: lwc1        $f0, 0x3C($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x8004E38C: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x8004E390: swc1        $f0, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->f0.u32l;
    // 0x8004E394: sub.s       $f0, $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f8.fl;
    // 0x8004E398: swc1        $f8, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->f8.u32l;
    // 0x8004E39C: swc1        $f4, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->f4.u32l;
    // 0x8004E3A0: swc1        $f2, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->f2.u32l;
    // 0x8004E3A4: jal         0x800AA350
    // 0x8004E3A8: swc1        $f0, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->f0.u32l;
    func_800AA350(rdram, ctx);
        goto after_4;
    // 0x8004E3A8: swc1        $f0, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->f0.u32l;
    after_4:
    // 0x8004E3AC: addiu       $s4, $sp, 0x90
    ctx->r20 = ADD32(ctx->r29, 0X90);
    // 0x8004E3B0: addu        $a0, $s4, $zero
    ctx->r4 = ADD32(ctx->r20, 0);
    // 0x8004E3B4: addu        $a1, $s3, $zero
    ctx->r5 = ADD32(ctx->r19, 0);
    // 0x8004E3B8: jal         0x80019548
    // 0x8004E3BC: addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    func_80019548(rdram, ctx);
        goto after_5;
    // 0x8004E3BC: addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    after_5:
    // 0x8004E3C0: jal         0x800AA350
    // 0x8004E3C4: addu        $a0, $s4, $zero
    ctx->r4 = ADD32(ctx->r20, 0);
    func_800AA350(rdram, ctx);
        goto after_6;
    // 0x8004E3C4: addu        $a0, $s4, $zero
    ctx->r4 = ADD32(ctx->r20, 0);
    after_6:
    // 0x8004E3C8: addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    // 0x8004E3CC: jal         0x8001CFE8
    // 0x8004E3D0: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    func_8001CFE8(rdram, ctx);
        goto after_7;
    // 0x8004E3D0: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    after_7:
    // 0x8004E3D4: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8004E3D8: lwc1        $f22, -0x5680($at)
    ctx->f22.u32l = MEM_W(ctx->r1, -0X5680);
    // 0x8004E3DC: jal         0x8001C400
    // 0x8004E3E0: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    func_8001C400(rdram, ctx);
        goto after_8;
    // 0x8004E3E0: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    after_8:
    // 0x8004E3E4: mul.s       $f0, $f0, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f22.fl);
    // 0x8004E3E8: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8004E3EC: lwc1        $f24, -0x567C($at)
    ctx->f24.u32l = MEM_W(ctx->r1, -0X567C);
    // 0x8004E3F0: sub.s       $f20, $f24, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f20.fl = ctx->f24.fl - ctx->f0.fl;
    // 0x8004E3F4: abs.s       $f2, $f20
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); 
    ctx->f2.fl = fabsf(ctx->f20.fl);
    // 0x8004E3F8: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8004E3FC: lwc1        $f0, -0x5678($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X5678);
    // 0x8004E400: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x8004E404: nop

    // 0x8004E408: bc1f        L_8004E47C
    if (!c1cs) {
        // 0x8004E40C: addiu       $s0, $sp, 0xE0
        ctx->r16 = ADD32(ctx->r29, 0XE0);
            goto L_8004E47C;
    }
    // 0x8004E40C: addiu       $s0, $sp, 0xE0
    ctx->r16 = ADD32(ctx->r29, 0XE0);
    // 0x8004E410: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x8004E414: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x8004E418: jal         0x8001D144
    // 0x8004E41C: addu        $a1, $s4, $zero
    ctx->r5 = ADD32(ctx->r20, 0);
    func_8001D144(rdram, ctx);
        goto after_9;
    // 0x8004E41C: addu        $a1, $s4, $zero
    ctx->r5 = ADD32(ctx->r20, 0);
    after_9:
    // 0x8004E420: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x8004E424: addiu       $s0, $sp, 0x40
    ctx->r16 = ADD32(ctx->r29, 0X40);
    // 0x8004E428: jal         0x8001D548
    // 0x8004E42C: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    func_8001D548(rdram, ctx);
        goto after_10;
    // 0x8004E42C: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    after_10:
    // 0x8004E430: sw          $zero, 0x64($sp)
    MEM_W(0X64, ctx->r29) = 0;
    // 0x8004E434: sw          $zero, 0x68($sp)
    MEM_W(0X68, ctx->r29) = 0;
    // 0x8004E438: sw          $zero, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = 0;
    // 0x8004E43C: lwc1        $f0, 0x4C($s2)
    ctx->f0.u32l = MEM_W(ctx->r18, 0X4C);
    // 0x8004E440: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x8004E444: swc1        $f0, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->f0.u32l;
    // 0x8004E448: lwc1        $f0, 0x50($s2)
    ctx->f0.u32l = MEM_W(ctx->r18, 0X50);
    // 0x8004E44C: addiu       $a1, $s2, 0x28
    ctx->r5 = ADD32(ctx->r18, 0X28);
    // 0x8004E450: swc1        $f0, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->f0.u32l;
    // 0x8004E454: lwc1        $f0, 0x54($s2)
    ctx->f0.u32l = MEM_W(ctx->r18, 0X54);
    // 0x8004E458: addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    // 0x8004E45C: jal         0x800191C4
    // 0x8004E460: swc1        $f0, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->f0.u32l;
    func_800191C4(rdram, ctx);
        goto after_11;
    // 0x8004E460: swc1        $f0, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->f0.u32l;
    after_11:
    // 0x8004E464: lwc1        $f0, 0x70($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X70);
    // 0x8004E468: swc1        $f0, 0x4C($s2)
    MEM_W(0X4C, ctx->r18) = ctx->f0.u32l;
    // 0x8004E46C: lwc1        $f0, 0x74($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X74);
    // 0x8004E470: swc1        $f0, 0x50($s2)
    MEM_W(0X50, ctx->r18) = ctx->f0.u32l;
    // 0x8004E474: lwc1        $f0, 0x78($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X78);
    // 0x8004E478: swc1        $f0, 0x54($s2)
    MEM_W(0X54, ctx->r18) = ctx->f0.u32l;
L_8004E47C:
    // 0x8004E47C: lwc1        $f0, 0x30($s2)
    ctx->f0.u32l = MEM_W(ctx->r18, 0X30);
    // 0x8004E480: swc1        $f0, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->f0.u32l;
    // 0x8004E484: lwc1        $f0, 0x3C($s2)
    ctx->f0.u32l = MEM_W(ctx->r18, 0X3C);
    // 0x8004E488: swc1        $f0, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->f0.u32l;
    // 0x8004E48C: lwc1        $f0, 0x48($s2)
    ctx->f0.u32l = MEM_W(ctx->r18, 0X48);
    // 0x8004E490: addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    // 0x8004E494: jal         0x800AA350
    // 0x8004E498: swc1        $f0, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->f0.u32l;
    func_800AA350(rdram, ctx);
        goto after_12;
    // 0x8004E498: swc1        $f0, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->f0.u32l;
    after_12:
    // 0x8004E49C: lwc1        $f0, 0x18($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X18);
    // 0x8004E4A0: lwc1        $f2, 0x24($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X24);
    // 0x8004E4A4: lwc1        $f4, 0x30($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X30);
    // 0x8004E4A8: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x8004E4AC: swc1        $f0, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->f0.u32l;
    // 0x8004E4B0: swc1        $f2, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->f2.u32l;
    // 0x8004E4B4: jal         0x800AA350
    // 0x8004E4B8: swc1        $f4, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->f4.u32l;
    func_800AA350(rdram, ctx);
        goto after_13;
    // 0x8004E4B8: swc1        $f4, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->f4.u32l;
    after_13:
    // 0x8004E4BC: addu        $a0, $s4, $zero
    ctx->r4 = ADD32(ctx->r20, 0);
    // 0x8004E4C0: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    // 0x8004E4C4: jal         0x80019548
    // 0x8004E4C8: addu        $a2, $s3, $zero
    ctx->r6 = ADD32(ctx->r19, 0);
    func_80019548(rdram, ctx);
        goto after_14;
    // 0x8004E4C8: addu        $a2, $s3, $zero
    ctx->r6 = ADD32(ctx->r19, 0);
    after_14:
    // 0x8004E4CC: jal         0x800AA350
    // 0x8004E4D0: addu        $a0, $s4, $zero
    ctx->r4 = ADD32(ctx->r20, 0);
    func_800AA350(rdram, ctx);
        goto after_15;
    // 0x8004E4D0: addu        $a0, $s4, $zero
    ctx->r4 = ADD32(ctx->r20, 0);
    after_15:
    // 0x8004E4D4: addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    // 0x8004E4D8: jal         0x8001CFE8
    // 0x8004E4DC: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    func_8001CFE8(rdram, ctx);
        goto after_16;
    // 0x8004E4DC: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    after_16:
    // 0x8004E4E0: jal         0x8001C400
    // 0x8004E4E4: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    func_8001C400(rdram, ctx);
        goto after_17;
    // 0x8004E4E4: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    after_17:
    // 0x8004E4E8: mul.s       $f0, $f0, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f22.fl);
    // 0x8004E4EC: sub.s       $f20, $f24, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f20.fl = ctx->f24.fl - ctx->f0.fl;
    // 0x8004E4F0: addiu       $s0, $sp, 0xE0
    ctx->r16 = ADD32(ctx->r29, 0XE0);
    // 0x8004E4F4: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x8004E4F8: neg.s       $f20, $f20
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); 
    ctx->f20.fl = -ctx->f20.fl;
    // 0x8004E4FC: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x8004E500: jal         0x8001D144
    // 0x8004E504: addu        $a1, $s4, $zero
    ctx->r5 = ADD32(ctx->r20, 0);
    func_8001D144(rdram, ctx);
        goto after_18;
    // 0x8004E504: addu        $a1, $s4, $zero
    ctx->r5 = ADD32(ctx->r20, 0);
    after_18:
    // 0x8004E508: lwc1        $f0, 0x2C($s2)
    ctx->f0.u32l = MEM_W(ctx->r18, 0X2C);
    // 0x8004E50C: swc1        $f0, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->f0.u32l;
    // 0x8004E510: lwc1        $f0, 0x38($s2)
    ctx->f0.u32l = MEM_W(ctx->r18, 0X38);
    // 0x8004E514: swc1        $f0, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->f0.u32l;
    // 0x8004E518: lwc1        $f0, 0x44($s2)
    ctx->f0.u32l = MEM_W(ctx->r18, 0X44);
    // 0x8004E51C: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x8004E520: jal         0x800AA350
    // 0x8004E524: swc1        $f0, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->f0.u32l;
    func_800AA350(rdram, ctx);
        goto after_19;
    // 0x8004E524: swc1        $f0, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->f0.u32l;
    after_19:
    // 0x8004E528: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x8004E52C: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    // 0x8004E530: jal         0x8001D3C4
    // 0x8004E534: addu        $a2, $s3, $zero
    ctx->r6 = ADD32(ctx->r19, 0);
    func_8001D3C4(rdram, ctx);
        goto after_20;
    // 0x8004E534: addu        $a2, $s3, $zero
    ctx->r6 = ADD32(ctx->r19, 0);
    after_20:
    // 0x8004E538: jal         0x800AA350
    // 0x8004E53C: addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    func_800AA350(rdram, ctx);
        goto after_21;
    // 0x8004E53C: addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    after_21:
    // 0x8004E540: lwc1        $f0, 0x14($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X14);
    // 0x8004E544: lwc1        $f2, 0x20($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X20);
    // 0x8004E548: lwc1        $f4, 0x2C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x8004E54C: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x8004E550: swc1        $f0, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->f0.u32l;
    // 0x8004E554: swc1        $f2, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->f2.u32l;
    // 0x8004E558: jal         0x800AA350
    // 0x8004E55C: swc1        $f4, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->f4.u32l;
    func_800AA350(rdram, ctx);
        goto after_22;
    // 0x8004E55C: swc1        $f4, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->f4.u32l;
    after_22:
    // 0x8004E560: addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    // 0x8004E564: jal         0x8001CFE8
    // 0x8004E568: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    func_8001CFE8(rdram, ctx);
        goto after_23;
    // 0x8004E568: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    after_23:
    // 0x8004E56C: jal         0x8001C400
    // 0x8004E570: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    func_8001C400(rdram, ctx);
        goto after_24;
    // 0x8004E570: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    after_24:
    // 0x8004E574: mul.s       $f0, $f0, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f22.fl);
    // 0x8004E578: addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    // 0x8004E57C: addu        $a1, $s3, $zero
    ctx->r5 = ADD32(ctx->r19, 0);
    // 0x8004E580: addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    // 0x8004E584: jal         0x80019548
    // 0x8004E588: sub.s       $f20, $f24, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f20.fl = ctx->f24.fl - ctx->f0.fl;
    func_80019548(rdram, ctx);
        goto after_25;
    // 0x8004E588: sub.s       $f20, $f24, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f20.fl = ctx->f24.fl - ctx->f0.fl;
    after_25:
    // 0x8004E58C: lwc1        $f0, 0x18($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X18);
    // 0x8004E590: lwc1        $f2, 0x24($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X24);
    // 0x8004E594: lwc1        $f4, 0x30($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X30);
    // 0x8004E598: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x8004E59C: swc1        $f0, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->f0.u32l;
    // 0x8004E5A0: swc1        $f2, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->f2.u32l;
    // 0x8004E5A4: jal         0x800AA350
    // 0x8004E5A8: swc1        $f4, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->f4.u32l;
    func_800AA350(rdram, ctx);
        goto after_26;
    // 0x8004E5A8: swc1        $f4, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->f4.u32l;
    after_26:
    // 0x8004E5AC: addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    // 0x8004E5B0: jal         0x8001CFE8
    // 0x8004E5B4: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    func_8001CFE8(rdram, ctx);
        goto after_27;
    // 0x8004E5B4: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    after_27:
    // 0x8004E5B8: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x8004E5BC: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x8004E5C0: nop

    // 0x8004E5C4: bc1tl       L_8004E5CC
    if (c1cs) {
        // 0x8004E5C8: neg.s       $f20, $f20
        CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); 
    ctx->f20.fl = -ctx->f20.fl;
            goto L_8004E5CC;
    }
    goto skip_0;
    // 0x8004E5C8: neg.s       $f20, $f20
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); 
    ctx->f20.fl = -ctx->f20.fl;
    skip_0:
L_8004E5CC:
    // 0x8004E5CC: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x8004E5D0: lw          $a1, 0xC($s2)
    ctx->r5 = MEM_W(ctx->r18, 0XC);
    // 0x8004E5D4: addiu       $v1, $v1, 0xB40
    ctx->r3 = ADD32(ctx->r3, 0XB40);
    // 0x8004E5D8: sll         $v0, $a1, 2
    ctx->r2 = S32(ctx->r5 << 2);
    // 0x8004E5DC: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8004E5E0: lw          $v0, 0xC($v0)
    ctx->r2 = MEM_W(ctx->r2, 0XC);
    // 0x8004E5E4: lui         $v1, 0x100
    ctx->r3 = S32(0X100 << 16);
    // 0x8004E5E8: and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // 0x8004E5EC: beq         $v0, $zero, L_8004E648
    if (ctx->r2 == 0) {
        // 0x8004E5F0: lui         $v0, 0x8013
        ctx->r2 = S32(0X8013 << 16);
            goto L_8004E648;
    }
    // 0x8004E5F0: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8004E5F4: addiu       $v0, $v0, 0xB88
    ctx->r2 = ADD32(ctx->r2, 0XB88);
    // 0x8004E5F8: sll         $v1, $a1, 1
    ctx->r3 = S32(ctx->r5 << 1);
    // 0x8004E5FC: addu        $v1, $v1, $a1
    ctx->r3 = ADD32(ctx->r3, ctx->r5);
    // 0x8004E600: sll         $v1, $v1, 1
    ctx->r3 = S32(ctx->r3 << 1);
    // 0x8004E604: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x8004E608: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x8004E60C: addiu       $a0, $a0, -0x41E8
    ctx->r4 = ADD32(ctx->r4, -0X41E8);
    // 0x8004E610: sll         $v0, $a1, 3
    ctx->r2 = S32(ctx->r5 << 3);
    // 0x8004E614: addu        $v0, $v0, $a1
    ctx->r2 = ADD32(ctx->r2, ctx->r5);
    // 0x8004E618: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8004E61C: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x8004E620: lhu         $v1, 0x0($v1)
    ctx->r3 = MEM_HU(ctx->r3, 0X0);
    // 0x8004E624: lhu         $v0, 0x20($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X20);
    // 0x8004E628: and         $v1, $v1, $v0
    ctx->r3 = ctx->r3 & ctx->r2;
    // 0x8004E62C: bne         $v1, $zero, L_8004E658
    if (ctx->r3 != 0) {
        // 0x8004E630: lui         $v0, 0x8013
        ctx->r2 = S32(0X8013 << 16);
            goto L_8004E658;
    }
    // 0x8004E630: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8004E634: lwc1        $f0, 0xA8($s2)
    ctx->f0.u32l = MEM_W(ctx->r18, 0XA8);
    // 0x8004E638: c.eq.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl == ctx->f2.fl;
    // 0x8004E63C: nop

    // 0x8004E640: bc1f        L_8004E65C
    if (!c1cs) {
        // 0x8004E644: addiu       $v0, $v0, 0xB40
        ctx->r2 = ADD32(ctx->r2, 0XB40);
            goto L_8004E65C;
    }
    // 0x8004E644: addiu       $v0, $v0, 0xB40
    ctx->r2 = ADD32(ctx->r2, 0XB40);
L_8004E648:
    // 0x8004E648: lwc1        $f0, 0xAC($s2)
    ctx->f0.u32l = MEM_W(ctx->r18, 0XAC);
    // 0x8004E64C: mul.s       $f20, $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f20.fl = MUL_S(ctx->f20.fl, ctx->f0.fl);
    // 0x8004E650: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8004E654: lw          $a1, 0xC($s2)
    ctx->r5 = MEM_W(ctx->r18, 0XC);
L_8004E658:
    // 0x8004E658: addiu       $v0, $v0, 0xB40
    ctx->r2 = ADD32(ctx->r2, 0XB40);
L_8004E65C:
    // 0x8004E65C: sll         $a2, $a1, 2
    ctx->r6 = S32(ctx->r5 << 2);
    // 0x8004E660: addu        $v0, $a2, $v0
    ctx->r2 = ADD32(ctx->r6, ctx->r2);
    // 0x8004E664: lw          $v0, 0xC($v0)
    ctx->r2 = MEM_W(ctx->r2, 0XC);
    // 0x8004E668: lui         $v1, 0x100
    ctx->r3 = S32(0X100 << 16);
    // 0x8004E66C: and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // 0x8004E670: beq         $v0, $zero, L_8004E6FC
    if (ctx->r2 == 0) {
        // 0x8004E674: lui         $v0, 0x8013
        ctx->r2 = S32(0X8013 << 16);
            goto L_8004E6FC;
    }
    // 0x8004E674: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8004E678: addiu       $v0, $v0, 0xB88
    ctx->r2 = ADD32(ctx->r2, 0XB88);
    // 0x8004E67C: sll         $v1, $a1, 1
    ctx->r3 = S32(ctx->r5 << 1);
    // 0x8004E680: addu        $v1, $v1, $a1
    ctx->r3 = ADD32(ctx->r3, ctx->r5);
    // 0x8004E684: sll         $v1, $v1, 1
    ctx->r3 = S32(ctx->r3 << 1);
    // 0x8004E688: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x8004E68C: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x8004E690: addiu       $a0, $a0, -0x41E8
    ctx->r4 = ADD32(ctx->r4, -0X41E8);
    // 0x8004E694: sll         $v0, $a1, 3
    ctx->r2 = S32(ctx->r5 << 3);
    // 0x8004E698: addu        $v0, $v0, $a1
    ctx->r2 = ADD32(ctx->r2, ctx->r5);
    // 0x8004E69C: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8004E6A0: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x8004E6A4: lhu         $v1, 0x0($v1)
    ctx->r3 = MEM_HU(ctx->r3, 0X0);
    // 0x8004E6A8: lhu         $v0, 0x20($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X20);
    // 0x8004E6AC: and         $v1, $v1, $v0
    ctx->r3 = ctx->r3 & ctx->r2;
    // 0x8004E6B0: beq         $v1, $zero, L_8004E6FC
    if (ctx->r3 == 0) {
        // 0x8004E6B4: nop
    
            goto L_8004E6FC;
    }
    // 0x8004E6B4: nop

    // 0x8004E6B8: lwc1        $f2, 0xA8($s2)
    ctx->f2.u32l = MEM_W(ctx->r18, 0XA8);
    // 0x8004E6BC: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8004E6C0: c.eq.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl == ctx->f0.fl;
    // 0x8004E6C4: nop

    // 0x8004E6C8: bc1t        L_8004E6FC
    if (c1cs) {
        // 0x8004E6CC: lui         $v0, 0x8013
        ctx->r2 = S32(0X8013 << 16);
            goto L_8004E6FC;
    }
    // 0x8004E6CC: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8004E6D0: addiu       $v0, $v0, 0x7DB8
    ctx->r2 = ADD32(ctx->r2, 0X7DB8);
    // 0x8004E6D4: addu        $v1, $a2, $a1
    ctx->r3 = ADD32(ctx->r6, ctx->r5);
    // 0x8004E6D8: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x8004E6DC: addu        $v1, $v1, $a1
    ctx->r3 = ADD32(ctx->r3, ctx->r5);
    // 0x8004E6E0: sll         $v1, $v1, 5
    ctx->r3 = S32(ctx->r3 << 5);
    // 0x8004E6E4: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x8004E6E8: lhu         $v0, 0x184($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X184);
    // 0x8004E6EC: andi        $v0, $v0, 0x2
    ctx->r2 = ctx->r2 & 0X2;
    // 0x8004E6F0: bne         $v0, $zero, L_8004E6FC
    if (ctx->r2 != 0) {
        // 0x8004E6F4: nop
    
            goto L_8004E6FC;
    }
    // 0x8004E6F4: nop

    // 0x8004E6F8: mul.s       $f20, $f20, $f2
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f20.fl = MUL_S(ctx->f20.fl, ctx->f2.fl);
L_8004E6FC:
    // 0x8004E6FC: abs.s       $f2, $f20
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); 
    ctx->f2.fl = fabsf(ctx->f20.fl);
    // 0x8004E700: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8004E704: lwc1        $f0, -0x5674($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X5674);
    // 0x8004E708: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x8004E70C: nop

    // 0x8004E710: bc1f        L_8004E874
    if (!c1cs) {
        // 0x8004E714: addiu       $s1, $sp, 0x90
        ctx->r17 = ADD32(ctx->r29, 0X90);
            goto L_8004E874;
    }
    // 0x8004E714: addiu       $s1, $sp, 0x90
    ctx->r17 = ADD32(ctx->r29, 0X90);
    // 0x8004E718: lwc1        $f0, 0x30($s2)
    ctx->f0.u32l = MEM_W(ctx->r18, 0X30);
    // 0x8004E71C: swc1        $f0, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->f0.u32l;
    // 0x8004E720: lwc1        $f0, 0x3C($s2)
    ctx->f0.u32l = MEM_W(ctx->r18, 0X3C);
    // 0x8004E724: swc1        $f0, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->f0.u32l;
    // 0x8004E728: lwc1        $f0, 0x48($s2)
    ctx->f0.u32l = MEM_W(ctx->r18, 0X48);
    // 0x8004E72C: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x8004E730: jal         0x800AA350
    // 0x8004E734: swc1        $f0, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->f0.u32l;
    func_800AA350(rdram, ctx);
        goto after_28;
    // 0x8004E734: swc1        $f0, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->f0.u32l;
    after_28:
    // 0x8004E738: addiu       $s0, $sp, 0xE0
    ctx->r16 = ADD32(ctx->r29, 0XE0);
    // 0x8004E73C: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x8004E740: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x8004E744: jal         0x8001D144
    // 0x8004E748: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    func_8001D144(rdram, ctx);
        goto after_29;
    // 0x8004E748: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    after_29:
    // 0x8004E74C: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x8004E750: jal         0x8001D548
    // 0x8004E754: addiu       $a1, $sp, 0x10
    ctx->r5 = ADD32(ctx->r29, 0X10);
    func_8001D548(rdram, ctx);
        goto after_30;
    // 0x8004E754: addiu       $a1, $sp, 0x10
    ctx->r5 = ADD32(ctx->r29, 0X10);
    after_30:
    // 0x8004E758: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    // 0x8004E75C: sw          $zero, 0x38($sp)
    MEM_W(0X38, ctx->r29) = 0;
    // 0x8004E760: sw          $zero, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = 0;
    // 0x8004E764: lwc1        $f0, 0x4C($s2)
    ctx->f0.u32l = MEM_W(ctx->r18, 0X4C);
    // 0x8004E768: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    // 0x8004E76C: swc1        $f0, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->f0.u32l;
    // 0x8004E770: lwc1        $f0, 0x50($s2)
    ctx->f0.u32l = MEM_W(ctx->r18, 0X50);
    // 0x8004E774: addiu       $a1, $s2, 0x28
    ctx->r5 = ADD32(ctx->r18, 0X28);
    // 0x8004E778: swc1        $f0, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->f0.u32l;
    // 0x8004E77C: lwc1        $f0, 0x54($s2)
    ctx->f0.u32l = MEM_W(ctx->r18, 0X54);
    // 0x8004E780: addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    // 0x8004E784: jal         0x800191C4
    // 0x8004E788: swc1        $f0, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->f0.u32l;
    func_800191C4(rdram, ctx);
        goto after_31;
    // 0x8004E788: swc1        $f0, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->f0.u32l;
    after_31:
    // 0x8004E78C: lwc1        $f0, 0x70($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X70);
    // 0x8004E790: swc1        $f0, 0x4C($s2)
    MEM_W(0X4C, ctx->r18) = ctx->f0.u32l;
    // 0x8004E794: lwc1        $f0, 0x74($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X74);
    // 0x8004E798: swc1        $f0, 0x50($s2)
    MEM_W(0X50, ctx->r18) = ctx->f0.u32l;
    // 0x8004E79C: lwc1        $f0, 0x78($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X78);
    // 0x8004E7A0: j           L_8004E874
    // 0x8004E7A4: swc1        $f0, 0x54($s2)
    MEM_W(0X54, ctx->r18) = ctx->f0.u32l;
        goto L_8004E874;
    // 0x8004E7A4: swc1        $f0, 0x54($s2)
    MEM_W(0X54, ctx->r18) = ctx->f0.u32l;
L_8004E7A8:
    // 0x8004E7A8: addiu       $v0, $sp, 0x10
    ctx->r2 = ADD32(ctx->r29, 0X10);
    // 0x8004E7AC: lwc1        $f0, 0x24($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X24);
    // 0x8004E7B0: lwc1        $f2, 0x24($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X24);
    // 0x8004E7B4: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x8004E7B8: swc1        $f0, 0xF0($sp)
    MEM_W(0XF0, ctx->r29) = ctx->f0.u32l;
    // 0x8004E7BC: lwc1        $f0, 0x28($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X28);
    // 0x8004E7C0: lwc1        $f2, 0x28($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X28);
    // 0x8004E7C4: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x8004E7C8: swc1        $f0, 0xF4($sp)
    MEM_W(0XF4, ctx->r29) = ctx->f0.u32l;
    // 0x8004E7CC: lwc1        $f0, 0x2C($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X2C);
    // 0x8004E7D0: lwc1        $f2, 0x2C($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x8004E7D4: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x8004E7D8: addiu       $a0, $sp, 0xF0
    ctx->r4 = ADD32(ctx->r29, 0XF0);
    // 0x8004E7DC: addiu       $s1, $s2, 0x1C
    ctx->r17 = ADD32(ctx->r18, 0X1C);
    // 0x8004E7E0: jal         0x8001CF2C
    // 0x8004E7E4: swc1        $f0, 0xF8($sp)
    MEM_W(0XF8, ctx->r29) = ctx->f0.u32l;
    func_8001CF2C(rdram, ctx);
        goto after_32;
    // 0x8004E7E4: swc1        $f0, 0xF8($sp)
    MEM_W(0XF8, ctx->r29) = ctx->f0.u32l;
    after_32:
    // 0x8004E7E8: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8004E7EC: lwc1        $f2, -0x5670($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X5670);
    // 0x8004E7F0: mov.s       $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    ctx->f6.fl = ctx->f0.fl;
    // 0x8004E7F4: c.lt.s      $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f2.fl < ctx->f6.fl;
    // 0x8004E7F8: nop

    // 0x8004E7FC: bc1f        L_8004E860
    if (!c1cs) {
        // 0x8004E800: sw          $zero, 0x8($s1)
        MEM_W(0X8, ctx->r17) = 0;
            goto L_8004E860;
    }
    // 0x8004E800: sw          $zero, 0x8($s1)
    MEM_W(0X8, ctx->r17) = 0;
    // 0x8004E804: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8004E808: lwc1        $f0, -0x566C($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X566C);
    // 0x8004E80C: lwc1        $f4, 0xF0($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XF0);
    // 0x8004E810: div.s       $f0, $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f6.fl);
    // 0x8004E814: mul.s       $f4, $f0, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x8004E818: lwc1        $f12, 0xF4($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0XF4);
    // 0x8004E81C: mul.s       $f12, $f0, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = MUL_S(ctx->f0.fl, ctx->f12.fl);
    // 0x8004E820: lwc1        $f2, 0xF8($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0XF8);
    // 0x8004E824: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x8004E828: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8004E82C: lwc1        $f20, -0x5668($at)
    ctx->f20.u32l = MEM_W(ctx->r1, -0X5668);
    // 0x8004E830: swc1        $f4, 0xF0($sp)
    MEM_W(0XF0, ctx->r29) = ctx->f4.u32l;
    // 0x8004E834: swc1        $f12, 0xF4($sp)
    MEM_W(0XF4, ctx->r29) = ctx->f12.u32l;
    // 0x8004E838: jal         0x8001C400
    // 0x8004E83C: swc1        $f0, 0xF8($sp)
    MEM_W(0XF8, ctx->r29) = ctx->f0.u32l;
    func_8001C400(rdram, ctx);
        goto after_33;
    // 0x8004E83C: swc1        $f0, 0xF8($sp)
    MEM_W(0XF8, ctx->r29) = ctx->f0.u32l;
    after_33:
    // 0x8004E840: mul.s       $f0, $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f20.fl);
    // 0x8004E844: swc1        $f0, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->f0.u32l;
    // 0x8004E848: lwc1        $f12, 0xF0($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0XF0);
    // 0x8004E84C: lwc1        $f14, 0xF8($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0XF8);
    // 0x8004E850: jal         0x8001C5F4
    // 0x8004E854: neg.s       $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = -ctx->f12.fl;
    func_8001C5F4(rdram, ctx);
        goto after_34;
    // 0x8004E854: neg.s       $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = -ctx->f12.fl;
    after_34:
    // 0x8004E858: mul.s       $f0, $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f20.fl);
    // 0x8004E85C: swc1        $f0, 0x1C($s2)
    MEM_W(0X1C, ctx->r18) = ctx->f0.u32l;
L_8004E860:
    // 0x8004E860: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x8004E864: lw          $a1, 0x1C($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X1C);
    // 0x8004E868: lw          $a2, 0x20($s2)
    ctx->r6 = MEM_W(ctx->r18, 0X20);
    // 0x8004E86C: jal         0x800AA424
    // 0x8004E870: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    func_800AA424(rdram, ctx);
        goto after_35;
    // 0x8004E870: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    after_35:
L_8004E874:
    // 0x8004E874: lw          $v0, 0x90($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X90);
    // 0x8004E878: beq         $v0, $zero, L_8004ECF8
    if (ctx->r2 == 0) {
        // 0x8004E87C: addiu       $v0, $zero, 0x2
        ctx->r2 = ADD32(0, 0X2);
            goto L_8004ECF8;
    }
    // 0x8004E87C: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x8004E880: lhu         $v1, 0x4($s2)
    ctx->r3 = MEM_HU(ctx->r18, 0X4);
    // 0x8004E884: bne         $v1, $v0, L_8004ECFC
    if (ctx->r3 != ctx->r2) {
        // 0x8004E888: addiu       $s0, $s2, 0x28
        ctx->r16 = ADD32(ctx->r18, 0X28);
            goto L_8004ECFC;
    }
    // 0x8004E888: addiu       $s0, $s2, 0x28
    ctx->r16 = ADD32(ctx->r18, 0X28);
    // 0x8004E88C: lwc1        $f0, 0x10($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X10);
    // 0x8004E890: swc1        $f0, 0x28($s2)
    MEM_W(0X28, ctx->r18) = ctx->f0.u32l;
    // 0x8004E894: lwc1        $f0, 0x14($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X14);
    // 0x8004E898: swc1        $f0, 0x2C($s2)
    MEM_W(0X2C, ctx->r18) = ctx->f0.u32l;
    // 0x8004E89C: lwc1        $f0, 0x18($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X18);
    // 0x8004E8A0: swc1        $f0, 0x30($s2)
    MEM_W(0X30, ctx->r18) = ctx->f0.u32l;
    // 0x8004E8A4: lwc1        $f0, 0x1C($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x8004E8A8: swc1        $f0, 0x34($s2)
    MEM_W(0X34, ctx->r18) = ctx->f0.u32l;
    // 0x8004E8AC: lwc1        $f0, 0x20($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X20);
    // 0x8004E8B0: swc1        $f0, 0x38($s2)
    MEM_W(0X38, ctx->r18) = ctx->f0.u32l;
    // 0x8004E8B4: lwc1        $f0, 0x24($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X24);
    // 0x8004E8B8: swc1        $f0, 0x3C($s2)
    MEM_W(0X3C, ctx->r18) = ctx->f0.u32l;
    // 0x8004E8BC: lwc1        $f0, 0x28($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X28);
    // 0x8004E8C0: addiu       $a0, $s2, 0x28
    ctx->r4 = ADD32(ctx->r18, 0X28);
    // 0x8004E8C4: swc1        $f0, 0x40($s2)
    MEM_W(0X40, ctx->r18) = ctx->f0.u32l;
    // 0x8004E8C8: lwc1        $f0, 0x2C($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x8004E8CC: addiu       $a1, $s2, 0x10
    ctx->r5 = ADD32(ctx->r18, 0X10);
    // 0x8004E8D0: swc1        $f0, 0x44($s2)
    MEM_W(0X44, ctx->r18) = ctx->f0.u32l;
    // 0x8004E8D4: lwc1        $f0, 0x30($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X30);
    // 0x8004E8D8: addiu       $a2, $s2, 0x1C
    ctx->r6 = ADD32(ctx->r18, 0X1C);
    // 0x8004E8DC: jal         0x800A9B80
    // 0x8004E8E0: swc1        $f0, 0x48($s2)
    MEM_W(0X48, ctx->r18) = ctx->f0.u32l;
    func_800A9B80(rdram, ctx);
        goto after_36;
    // 0x8004E8E0: swc1        $f0, 0x48($s2)
    MEM_W(0X48, ctx->r18) = ctx->f0.u32l;
    after_36:
    // 0x8004E8E4: j           L_8004ECFC
    // 0x8004E8E8: addiu       $s0, $s2, 0x28
    ctx->r16 = ADD32(ctx->r18, 0X28);
        goto L_8004ECFC;
    // 0x8004E8E8: addiu       $s0, $s2, 0x28
    ctx->r16 = ADD32(ctx->r18, 0X28);
L_8004E8EC:
    // 0x8004E8EC: lw          $v0, 0x74($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X74);
    // 0x8004E8F0: beq         $v0, $zero, L_8004ECF8
    if (ctx->r2 == 0) {
        // 0x8004E8F4: addiu       $v1, $sp, 0x10
        ctx->r3 = ADD32(ctx->r29, 0X10);
            goto L_8004ECF8;
    }
    // 0x8004E8F4: addiu       $v1, $sp, 0x10
    ctx->r3 = ADD32(ctx->r29, 0X10);
    // 0x8004E8F8: addiu       $a0, $v0, 0x30
    ctx->r4 = ADD32(ctx->r2, 0X30);
L_8004E8FC:
    // 0x8004E8FC: lw          $t0, 0x0($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X0);
    // 0x8004E900: lw          $t1, 0x4($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X4);
    // 0x8004E904: lw          $t2, 0x8($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X8);
    // 0x8004E908: lw          $t3, 0xC($v0)
    ctx->r11 = MEM_W(ctx->r2, 0XC);
    // 0x8004E90C: sw          $t0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r8;
    // 0x8004E910: sw          $t1, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r9;
    // 0x8004E914: sw          $t2, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r10;
    // 0x8004E918: sw          $t3, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r11;
    // 0x8004E91C: addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
    // 0x8004E920: bne         $v0, $a0, L_8004E8FC
    if (ctx->r2 != ctx->r4) {
        // 0x8004E924: addiu       $v1, $v1, 0x10
        ctx->r3 = ADD32(ctx->r3, 0X10);
            goto L_8004E8FC;
    }
    // 0x8004E924: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
    // 0x8004E928: lw          $t0, 0x78($s2)
    ctx->r8 = MEM_W(ctx->r18, 0X78);
    // 0x8004E92C: lw          $t1, 0x7C($s2)
    ctx->r9 = MEM_W(ctx->r18, 0X7C);
    // 0x8004E930: lw          $t2, 0x80($s2)
    ctx->r10 = MEM_W(ctx->r18, 0X80);
    // 0x8004E934: sw          $t0, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r8;
    // 0x8004E938: sw          $t1, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r9;
    // 0x8004E93C: sw          $t2, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r10;
    // 0x8004E940: lwc1        $f0, 0x70($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X70);
    // 0x8004E944: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x8004E948: c.eq.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl == ctx->f2.fl;
    // 0x8004E94C: nop

    // 0x8004E950: bc1f        L_8004E984
    if (!c1cs) {
        // 0x8004E954: addiu       $a0, $sp, 0x10
        ctx->r4 = ADD32(ctx->r29, 0X10);
            goto L_8004E984;
    }
    // 0x8004E954: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    // 0x8004E958: lwc1        $f0, 0x74($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X74);
    // 0x8004E95C: c.eq.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl == ctx->f2.fl;
    // 0x8004E960: nop

    // 0x8004E964: bc1f        L_8004E988
    if (!c1cs) {
        // 0x8004E968: addiu       $a1, $sp, 0x70
        ctx->r5 = ADD32(ctx->r29, 0X70);
            goto L_8004E988;
    }
    // 0x8004E968: addiu       $a1, $sp, 0x70
    ctx->r5 = ADD32(ctx->r29, 0X70);
    // 0x8004E96C: lwc1        $f0, 0x78($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X78);
    // 0x8004E970: c.eq.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl == ctx->f2.fl;
    // 0x8004E974: nop

    // 0x8004E978: bc1t        L_8004E9B0
    if (c1cs) {
        // 0x8004E97C: addiu       $a1, $sp, 0xA0
        ctx->r5 = ADD32(ctx->r29, 0XA0);
            goto L_8004E9B0;
    }
    // 0x8004E97C: addiu       $a1, $sp, 0xA0
    ctx->r5 = ADD32(ctx->r29, 0XA0);
    // 0x8004E980: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
L_8004E984:
    // 0x8004E984: addiu       $a1, $sp, 0x70
    ctx->r5 = ADD32(ctx->r29, 0X70);
L_8004E988:
    // 0x8004E988: jal         0x800193E8
    // 0x8004E98C: addiu       $a2, $sp, 0x80
    ctx->r6 = ADD32(ctx->r29, 0X80);
    func_800193E8(rdram, ctx);
        goto after_37;
    // 0x8004E98C: addiu       $a2, $sp, 0x80
    ctx->r6 = ADD32(ctx->r29, 0X80);
    after_37:
    // 0x8004E990: lwc1        $f0, 0x80($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X80);
    // 0x8004E994: lwc1        $f2, 0x84($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X84);
    // 0x8004E998: lwc1        $f4, 0x88($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X88);
    // 0x8004E99C: swc1        $f0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f0.u32l;
    // 0x8004E9A0: swc1        $f2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f2.u32l;
    // 0x8004E9A4: swc1        $f4, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f4.u32l;
    // 0x8004E9A8: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    // 0x8004E9AC: addiu       $a1, $sp, 0xA0
    ctx->r5 = ADD32(ctx->r29, 0XA0);
L_8004E9B0:
    // 0x8004E9B0: jal         0x800A9B80
    // 0x8004E9B4: addiu       $a2, $sp, 0xB0
    ctx->r6 = ADD32(ctx->r29, 0XB0);
    func_800A9B80(rdram, ctx);
        goto after_38;
    // 0x8004E9B4: addiu       $a2, $sp, 0xB0
    ctx->r6 = ADD32(ctx->r29, 0XB0);
    after_38:
    // 0x8004E9B8: addiu       $s0, $s2, 0x28
    ctx->r16 = ADD32(ctx->r18, 0X28);
    // 0x8004E9BC: addiu       $v0, $sp, 0x10
    ctx->r2 = ADD32(ctx->r29, 0X10);
    // 0x8004E9C0: lwc1        $f0, 0x24($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X24);
    // 0x8004E9C4: lwc1        $f2, 0x24($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X24);
    // 0x8004E9C8: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x8004E9CC: swc1        $f0, 0xF0($sp)
    MEM_W(0XF0, ctx->r29) = ctx->f0.u32l;
    // 0x8004E9D0: lwc1        $f0, 0x28($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X28);
    // 0x8004E9D4: lwc1        $f2, 0x28($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X28);
    // 0x8004E9D8: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x8004E9DC: swc1        $f0, 0xF4($sp)
    MEM_W(0XF4, ctx->r29) = ctx->f0.u32l;
    // 0x8004E9E0: lwc1        $f0, 0x2C($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X2C);
    // 0x8004E9E4: lwc1        $f2, 0x2C($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x8004E9E8: addiu       $a0, $sp, 0xF0
    ctx->r4 = ADD32(ctx->r29, 0XF0);
    // 0x8004E9EC: lwc1        $f20, 0xB8($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0XB8);
    // 0x8004E9F0: j           L_8004EBF0
    // 0x8004E9F4: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
        goto L_8004EBF0;
    // 0x8004E9F4: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
L_8004E9F8:
    // 0x8004E9F8: lwc1        $f2, 0xCC($s2)
    ctx->f2.u32l = MEM_W(ctx->r18, 0XCC);
    // 0x8004E9FC: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8004EA00: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x8004EA04: nop

    // 0x8004EA08: bc1f        L_8004EA50
    if (!c1cs) {
        // 0x8004EA0C: nop
    
            goto L_8004EA50;
    }
    // 0x8004EA0C: nop

    // 0x8004EA10: lw          $v0, 0xBC($s2)
    ctx->r2 = MEM_W(ctx->r18, 0XBC);
    // 0x8004EA14: addiu       $v1, $v0, 0x28
    ctx->r3 = ADD32(ctx->r2, 0X28);
    // 0x8004EA18: addiu       $v0, $v0, 0x58
    ctx->r2 = ADD32(ctx->r2, 0X58);
L_8004EA1C:
    // 0x8004EA1C: lw          $t0, 0x0($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X0);
    // 0x8004EA20: lw          $t1, 0x4($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X4);
    // 0x8004EA24: lw          $t2, 0x8($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X8);
    // 0x8004EA28: lw          $t3, 0xC($v1)
    ctx->r11 = MEM_W(ctx->r3, 0XC);
    // 0x8004EA2C: sw          $t0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r8;
    // 0x8004EA30: sw          $t1, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r9;
    // 0x8004EA34: sw          $t2, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r10;
    // 0x8004EA38: sw          $t3, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r11;
    // 0x8004EA3C: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
    // 0x8004EA40: bne         $v1, $v0, L_8004EA1C
    if (ctx->r3 != ctx->r2) {
        // 0x8004EA44: addiu       $a0, $a0, 0x10
        ctx->r4 = ADD32(ctx->r4, 0X10);
            goto L_8004EA1C;
    }
    // 0x8004EA44: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    // 0x8004EA48: j           L_8004ECFC
    // 0x8004EA4C: addiu       $s0, $s2, 0x28
    ctx->r16 = ADD32(ctx->r18, 0X28);
        goto L_8004ECFC;
    // 0x8004EA4C: addiu       $s0, $s2, 0x28
    ctx->r16 = ADD32(ctx->r18, 0X28);
L_8004EA50:
    // 0x8004EA50: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8004EA54: lwc1        $f0, -0x5664($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X5664);
    // 0x8004EA58: c.le.s      $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f0.fl <= ctx->f20.fl;
    // 0x8004EA5C: nop

    // 0x8004EA60: bc1f        L_8004EAC4
    if (!c1cs) {
        // 0x8004EA64: ori         $s1, $zero, 0xFFFF
        ctx->r17 = 0 | 0XFFFF;
            goto L_8004EAC4;
    }
    // 0x8004EA64: ori         $s1, $zero, 0xFFFF
    ctx->r17 = 0 | 0XFFFF;
    // 0x8004EA68: lhu         $v0, 0x0($s2)
    ctx->r2 = MEM_HU(ctx->r18, 0X0);
    // 0x8004EA6C: andi        $v0, $v0, 0xFFFE
    ctx->r2 = ctx->r2 & 0XFFFE;
    // 0x8004EA70: sh          $v0, 0x0($s2)
    MEM_H(0X0, ctx->r18) = ctx->r2;
    // 0x8004EA74: lhu         $v0, 0xF4($s2)
    ctx->r2 = MEM_HU(ctx->r18, 0XF4);
    // 0x8004EA78: beq         $v0, $s1, L_8004EA8C
    if (ctx->r2 == ctx->r17) {
        // 0x8004EA7C: nop
    
            goto L_8004EA8C;
    }
    // 0x8004EA7C: nop

    // 0x8004EA80: jal         0x8003F0C8
    // 0x8004EA84: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    func_8003F0C8(rdram, ctx);
        goto after_39;
    // 0x8004EA84: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    after_39:
    // 0x8004EA88: sh          $s1, 0xF4($s2)
    MEM_H(0XF4, ctx->r18) = ctx->r17;
L_8004EA8C:
    // 0x8004EA8C: lw          $v0, 0xC0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0XC0);
    // 0x8004EA90: sw          $v0, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r2;
    // 0x8004EA94: lw          $v1, 0xBC($s2)
    ctx->r3 = MEM_W(ctx->r18, 0XBC);
    // 0x8004EA98: lhu         $v0, 0x0($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X0);
    // 0x8004EA9C: andi        $v0, $v0, 0xFFFE
    ctx->r2 = ctx->r2 & 0XFFFE;
    // 0x8004EAA0: sh          $v0, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r2;
    // 0x8004EAA4: lw          $s0, 0xBC($s2)
    ctx->r16 = MEM_W(ctx->r18, 0XBC);
    // 0x8004EAA8: lhu         $v0, 0xF4($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0XF4);
    // 0x8004EAAC: beql        $v0, $s1, L_8004ECFC
    if (ctx->r2 == ctx->r17) {
        // 0x8004EAB0: addiu       $s0, $s2, 0x28
        ctx->r16 = ADD32(ctx->r18, 0X28);
            goto L_8004ECFC;
    }
    goto skip_1;
    // 0x8004EAB0: addiu       $s0, $s2, 0x28
    ctx->r16 = ADD32(ctx->r18, 0X28);
    skip_1:
    // 0x8004EAB4: jal         0x8003F0C8
    // 0x8004EAB8: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    func_8003F0C8(rdram, ctx);
        goto after_40;
    // 0x8004EAB8: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    after_40:
    // 0x8004EABC: j           L_8004ECF8
    // 0x8004EAC0: sh          $s1, 0xF4($s0)
    MEM_H(0XF4, ctx->r16) = ctx->r17;
        goto L_8004ECF8;
    // 0x8004EAC0: sh          $s1, 0xF4($s0)
    MEM_H(0XF4, ctx->r16) = ctx->r17;
L_8004EAC4:
    // 0x8004EAC4: lw          $a1, 0xBC($s2)
    ctx->r5 = MEM_W(ctx->r18, 0XBC);
    // 0x8004EAC8: lhu         $a0, 0x2($a1)
    ctx->r4 = MEM_HU(ctx->r5, 0X2);
    // 0x8004EACC: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x8004EAD0: bne         $a0, $v0, L_8004EC90
    if (ctx->r4 != ctx->r2) {
        // 0x8004EAD4: addiu       $s0, $sp, 0x70
        ctx->r16 = ADD32(ctx->r29, 0X70);
            goto L_8004EC90;
    }
    // 0x8004EAD4: addiu       $s0, $sp, 0x70
    ctx->r16 = ADD32(ctx->r29, 0X70);
    // 0x8004EAD8: lw          $v1, 0xC0($s2)
    ctx->r3 = MEM_W(ctx->r18, 0XC0);
    // 0x8004EADC: lhu         $v0, 0x2($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X2);
    // 0x8004EAE0: bnel        $v0, $a0, L_8004EC94
    if (ctx->r2 != ctx->r4) {
        // 0x8004EAE4: addu        $a1, $s0, $zero
        ctx->r5 = ADD32(ctx->r16, 0);
            goto L_8004EC94;
    }
    goto skip_2;
    // 0x8004EAE4: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    skip_2:
    // 0x8004EAE8: lw          $a0, 0x74($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X74);
    // 0x8004EAEC: lw          $v0, 0x74($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X74);
    // 0x8004EAF0: bne         $a0, $v0, L_8004EC94
    if (ctx->r4 != ctx->r2) {
        // 0x8004EAF4: addu        $a1, $s0, $zero
        ctx->r5 = ADD32(ctx->r16, 0);
            goto L_8004EC94;
    }
    // 0x8004EAF4: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x8004EAF8: addiu       $v1, $sp, 0x10
    ctx->r3 = ADD32(ctx->r29, 0X10);
    // 0x8004EAFC: addu        $v0, $a0, $zero
    ctx->r2 = ADD32(ctx->r4, 0);
    // 0x8004EB00: addiu       $a0, $v0, 0x30
    ctx->r4 = ADD32(ctx->r2, 0X30);
L_8004EB04:
    // 0x8004EB04: lw          $t0, 0x0($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X0);
    // 0x8004EB08: lw          $t1, 0x4($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X4);
    // 0x8004EB0C: lw          $t2, 0x8($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X8);
    // 0x8004EB10: lw          $t3, 0xC($v0)
    ctx->r11 = MEM_W(ctx->r2, 0XC);
    // 0x8004EB14: sw          $t0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r8;
    // 0x8004EB18: sw          $t1, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r9;
    // 0x8004EB1C: sw          $t2, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r10;
    // 0x8004EB20: sw          $t3, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r11;
    // 0x8004EB24: addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
    // 0x8004EB28: bne         $v0, $a0, L_8004EB04
    if (ctx->r2 != ctx->r4) {
        // 0x8004EB2C: addiu       $v1, $v1, 0x10
        ctx->r3 = ADD32(ctx->r3, 0X10);
            goto L_8004EB04;
    }
    // 0x8004EB2C: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
    // 0x8004EB30: lw          $v0, 0xBC($s2)
    ctx->r2 = MEM_W(ctx->r18, 0XBC);
    // 0x8004EB34: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x8004EB38: lw          $t0, 0x78($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X78);
    // 0x8004EB3C: lw          $t1, 0x7C($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X7C);
    // 0x8004EB40: lw          $t2, 0x80($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X80);
    // 0x8004EB44: sw          $t0, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r8;
    // 0x8004EB48: sw          $t1, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r9;
    // 0x8004EB4C: sw          $t2, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r10;
    // 0x8004EB50: lwc1        $f0, 0x70($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X70);
    // 0x8004EB54: c.eq.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl == ctx->f2.fl;
    // 0x8004EB58: nop

    // 0x8004EB5C: bc1f        L_8004EB90
    if (!c1cs) {
        // 0x8004EB60: addiu       $a0, $sp, 0x10
        ctx->r4 = ADD32(ctx->r29, 0X10);
            goto L_8004EB90;
    }
    // 0x8004EB60: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    // 0x8004EB64: lwc1        $f0, 0x74($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X74);
    // 0x8004EB68: c.eq.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl == ctx->f2.fl;
    // 0x8004EB6C: nop

    // 0x8004EB70: bc1f        L_8004EB94
    if (!c1cs) {
        // 0x8004EB74: addiu       $a1, $sp, 0x70
        ctx->r5 = ADD32(ctx->r29, 0X70);
            goto L_8004EB94;
    }
    // 0x8004EB74: addiu       $a1, $sp, 0x70
    ctx->r5 = ADD32(ctx->r29, 0X70);
    // 0x8004EB78: lwc1        $f0, 0x78($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X78);
    // 0x8004EB7C: c.eq.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl == ctx->f2.fl;
    // 0x8004EB80: nop

    // 0x8004EB84: bc1t        L_8004EBB8
    if (c1cs) {
        // 0x8004EB88: addiu       $s0, $s2, 0x28
        ctx->r16 = ADD32(ctx->r18, 0X28);
            goto L_8004EBB8;
    }
    // 0x8004EB88: addiu       $s0, $s2, 0x28
    ctx->r16 = ADD32(ctx->r18, 0X28);
    // 0x8004EB8C: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
L_8004EB90:
    // 0x8004EB90: addiu       $a1, $sp, 0x70
    ctx->r5 = ADD32(ctx->r29, 0X70);
L_8004EB94:
    // 0x8004EB94: jal         0x800193E8
    // 0x8004EB98: addiu       $a2, $sp, 0x80
    ctx->r6 = ADD32(ctx->r29, 0X80);
    func_800193E8(rdram, ctx);
        goto after_41;
    // 0x8004EB98: addiu       $a2, $sp, 0x80
    ctx->r6 = ADD32(ctx->r29, 0X80);
    after_41:
    // 0x8004EB9C: lwc1        $f0, 0x80($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X80);
    // 0x8004EBA0: lwc1        $f2, 0x84($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X84);
    // 0x8004EBA4: lwc1        $f4, 0x88($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X88);
    // 0x8004EBA8: swc1        $f0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f0.u32l;
    // 0x8004EBAC: swc1        $f2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f2.u32l;
    // 0x8004EBB0: swc1        $f4, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f4.u32l;
    // 0x8004EBB4: addiu       $s0, $s2, 0x28
    ctx->r16 = ADD32(ctx->r18, 0X28);
L_8004EBB8:
    // 0x8004EBB8: addiu       $v0, $sp, 0x10
    ctx->r2 = ADD32(ctx->r29, 0X10);
    // 0x8004EBBC: lwc1        $f0, 0x24($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X24);
    // 0x8004EBC0: lwc1        $f2, 0x24($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X24);
    // 0x8004EBC4: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x8004EBC8: lwc1        $f20, 0x24($s2)
    ctx->f20.u32l = MEM_W(ctx->r18, 0X24);
    // 0x8004EBCC: swc1        $f0, 0xF0($sp)
    MEM_W(0XF0, ctx->r29) = ctx->f0.u32l;
    // 0x8004EBD0: lwc1        $f0, 0x28($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X28);
    // 0x8004EBD4: lwc1        $f2, 0x28($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X28);
    // 0x8004EBD8: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x8004EBDC: swc1        $f0, 0xF4($sp)
    MEM_W(0XF4, ctx->r29) = ctx->f0.u32l;
    // 0x8004EBE0: lwc1        $f0, 0x2C($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X2C);
    // 0x8004EBE4: lwc1        $f2, 0x2C($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x8004EBE8: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x8004EBEC: addiu       $a0, $sp, 0xF0
    ctx->r4 = ADD32(ctx->r29, 0XF0);
L_8004EBF0:
    // 0x8004EBF0: addiu       $s1, $s2, 0x1C
    ctx->r17 = ADD32(ctx->r18, 0X1C);
    // 0x8004EBF4: jal         0x8001CF2C
    // 0x8004EBF8: swc1        $f0, 0xF8($sp)
    MEM_W(0XF8, ctx->r29) = ctx->f0.u32l;
    func_8001CF2C(rdram, ctx);
        goto after_42;
    // 0x8004EBF8: swc1        $f0, 0xF8($sp)
    MEM_W(0XF8, ctx->r29) = ctx->f0.u32l;
    after_42:
    // 0x8004EBFC: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8004EC00: lwc1        $f2, -0x5660($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X5660);
    // 0x8004EC04: mov.s       $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    ctx->f6.fl = ctx->f0.fl;
    // 0x8004EC08: c.lt.s      $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f2.fl < ctx->f6.fl;
    // 0x8004EC0C: nop

    // 0x8004EC10: bc1f        L_8004EC74
    if (!c1cs) {
        // 0x8004EC14: swc1        $f20, 0x8($s1)
        MEM_W(0X8, ctx->r17) = ctx->f20.u32l;
            goto L_8004EC74;
    }
    // 0x8004EC14: swc1        $f20, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->f20.u32l;
    // 0x8004EC18: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8004EC1C: lwc1        $f0, -0x565C($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X565C);
    // 0x8004EC20: lwc1        $f4, 0xF0($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XF0);
    // 0x8004EC24: div.s       $f0, $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f6.fl);
    // 0x8004EC28: mul.s       $f4, $f0, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x8004EC2C: lwc1        $f12, 0xF4($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0XF4);
    // 0x8004EC30: mul.s       $f12, $f0, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = MUL_S(ctx->f0.fl, ctx->f12.fl);
    // 0x8004EC34: lwc1        $f2, 0xF8($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0XF8);
    // 0x8004EC38: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x8004EC3C: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8004EC40: lwc1        $f20, -0x5658($at)
    ctx->f20.u32l = MEM_W(ctx->r1, -0X5658);
    // 0x8004EC44: swc1        $f4, 0xF0($sp)
    MEM_W(0XF0, ctx->r29) = ctx->f4.u32l;
    // 0x8004EC48: swc1        $f12, 0xF4($sp)
    MEM_W(0XF4, ctx->r29) = ctx->f12.u32l;
    // 0x8004EC4C: jal         0x8001C400
    // 0x8004EC50: swc1        $f0, 0xF8($sp)
    MEM_W(0XF8, ctx->r29) = ctx->f0.u32l;
    func_8001C400(rdram, ctx);
        goto after_43;
    // 0x8004EC50: swc1        $f0, 0xF8($sp)
    MEM_W(0XF8, ctx->r29) = ctx->f0.u32l;
    after_43:
    // 0x8004EC54: mul.s       $f0, $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f20.fl);
    // 0x8004EC58: swc1        $f0, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->f0.u32l;
    // 0x8004EC5C: lwc1        $f12, 0xF0($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0XF0);
    // 0x8004EC60: lwc1        $f14, 0xF8($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0XF8);
    // 0x8004EC64: jal         0x8001C5F4
    // 0x8004EC68: neg.s       $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = -ctx->f12.fl;
    func_8001C5F4(rdram, ctx);
        goto after_44;
    // 0x8004EC68: neg.s       $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = -ctx->f12.fl;
    after_44:
    // 0x8004EC6C: mul.s       $f0, $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f20.fl);
    // 0x8004EC70: swc1        $f0, 0x1C($s2)
    MEM_W(0X1C, ctx->r18) = ctx->f0.u32l;
L_8004EC74:
    // 0x8004EC74: lw          $a1, 0x1C($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X1C);
    // 0x8004EC78: lw          $a2, 0x20($s2)
    ctx->r6 = MEM_W(ctx->r18, 0X20);
    // 0x8004EC7C: lw          $a3, 0x24($s2)
    ctx->r7 = MEM_W(ctx->r18, 0X24);
    // 0x8004EC80: jal         0x800AA424
    // 0x8004EC84: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_800AA424(rdram, ctx);
        goto after_45;
    // 0x8004EC84: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_45:
    // 0x8004EC88: j           L_8004ECFC
    // 0x8004EC8C: addiu       $s0, $s2, 0x28
    ctx->r16 = ADD32(ctx->r18, 0X28);
        goto L_8004ECFC;
    // 0x8004EC8C: addiu       $s0, $s2, 0x28
    ctx->r16 = ADD32(ctx->r18, 0X28);
L_8004EC90:
    // 0x8004EC90: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
L_8004EC94:
    // 0x8004EC94: addiu       $s1, $sp, 0xC0
    ctx->r17 = ADD32(ctx->r29, 0XC0);
    // 0x8004EC98: lw          $a0, 0xBC($s2)
    ctx->r4 = MEM_W(ctx->r18, 0XBC);
    // 0x8004EC9C: addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    // 0x8004ECA0: jal         0x800A9B80
    // 0x8004ECA4: addiu       $a0, $a0, 0x28
    ctx->r4 = ADD32(ctx->r4, 0X28);
    func_800A9B80(rdram, ctx);
        goto after_46;
    // 0x8004ECA4: addiu       $a0, $a0, 0x28
    ctx->r4 = ADD32(ctx->r4, 0X28);
    after_46:
    // 0x8004ECA8: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x8004ECAC: addiu       $s0, $sp, 0xD0
    ctx->r16 = ADD32(ctx->r29, 0XD0);
    // 0x8004ECB0: lw          $a0, 0xC0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0XC0);
    // 0x8004ECB4: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    // 0x8004ECB8: jal         0x800A9B80
    // 0x8004ECBC: addiu       $a0, $a0, 0x28
    ctx->r4 = ADD32(ctx->r4, 0X28);
    func_800A9B80(rdram, ctx);
        goto after_47;
    // 0x8004ECBC: addiu       $a0, $a0, 0x28
    ctx->r4 = ADD32(ctx->r4, 0X28);
    after_47:
    // 0x8004ECC0: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x8004ECC4: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x8004ECC8: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x8004ECCC: jal         0x800A9FCC
    // 0x8004ECD0: addiu       $a3, $s2, 0x1C
    ctx->r7 = ADD32(ctx->r18, 0X1C);
    func_800A9FCC(rdram, ctx);
        goto after_48;
    // 0x8004ECD0: addiu       $a3, $s2, 0x1C
    ctx->r7 = ADD32(ctx->r18, 0X1C);
    after_48:
    // 0x8004ECD4: lw          $a1, 0x1C($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X1C);
    // 0x8004ECD8: lw          $a2, 0x20($s2)
    ctx->r6 = MEM_W(ctx->r18, 0X20);
    // 0x8004ECDC: lw          $a3, 0x24($s2)
    ctx->r7 = MEM_W(ctx->r18, 0X24);
    // 0x8004ECE0: jal         0x800AA424
    // 0x8004ECE4: addiu       $a0, $s2, 0x28
    ctx->r4 = ADD32(ctx->r18, 0X28);
    func_800AA424(rdram, ctx);
        goto after_49;
    // 0x8004ECE4: addiu       $a0, $s2, 0x28
    ctx->r4 = ADD32(ctx->r18, 0X28);
    after_49:
    // 0x8004ECE8: j           L_8004ECFC
    // 0x8004ECEC: addiu       $s0, $s2, 0x28
    ctx->r16 = ADD32(ctx->r18, 0X28);
        goto L_8004ECFC;
    // 0x8004ECEC: addiu       $s0, $s2, 0x28
    ctx->r16 = ADD32(ctx->r18, 0X28);
L_8004ECF0:
    // 0x8004ECF0: jal         0x800A9E70
    // 0x8004ECF4: addiu       $a2, $s2, 0x1C
    ctx->r6 = ADD32(ctx->r18, 0X1C);
    func_800A9E70(rdram, ctx);
        goto after_50;
    // 0x8004ECF4: addiu       $a2, $s2, 0x1C
    ctx->r6 = ADD32(ctx->r18, 0X1C);
    after_50:
L_8004ECF8:
    // 0x8004ECF8: addiu       $s0, $s2, 0x28
    ctx->r16 = ADD32(ctx->r18, 0X28);
L_8004ECFC:
    // 0x8004ECFC: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x8004ED00: addiu       $a1, $s2, 0x10
    ctx->r5 = ADD32(ctx->r18, 0X10);
    // 0x8004ED04: jal         0x800A9B80
    // 0x8004ED08: addiu       $a2, $s2, 0x1C
    ctx->r6 = ADD32(ctx->r18, 0X1C);
    func_800A9B80(rdram, ctx);
        goto after_51;
    // 0x8004ED08: addiu       $a2, $s2, 0x1C
    ctx->r6 = ADD32(ctx->r18, 0X1C);
    after_51:
    // 0x8004ED0C: lhu         $v0, 0x0($s2)
    ctx->r2 = MEM_HU(ctx->r18, 0X0);
    // 0x8004ED10: andi        $v0, $v0, 0x2
    ctx->r2 = ctx->r2 & 0X2;
    // 0x8004ED14: bne         $v0, $zero, L_8004ED48
    if (ctx->r2 != 0) {
        // 0x8004ED18: lui         $v1, 0x8013
        ctx->r3 = S32(0X8013 << 16);
            goto L_8004ED48;
    }
    // 0x8004ED18: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x8004ED1C: lw          $v0, 0xC($s2)
    ctx->r2 = MEM_W(ctx->r18, 0XC);
    // 0x8004ED20: addiu       $v1, $v1, 0xB40
    ctx->r3 = ADD32(ctx->r3, 0XB40);
    // 0x8004ED24: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8004ED28: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8004ED2C: lw          $v0, 0xC($v0)
    ctx->r2 = MEM_W(ctx->r2, 0XC);
    // 0x8004ED30: andi        $v0, $v0, 0x20
    ctx->r2 = ctx->r2 & 0X20;
    // 0x8004ED34: beq         $v0, $zero, L_8004ED60
    if (ctx->r2 == 0) {
        // 0x8004ED38: addiu       $v0, $zero, 0x3
        ctx->r2 = ADD32(0, 0X3);
            goto L_8004ED60;
    }
    // 0x8004ED38: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x8004ED3C: lhu         $v1, 0x4($s2)
    ctx->r3 = MEM_HU(ctx->r18, 0X4);
    // 0x8004ED40: beq         $v1, $v0, L_8004ED60
    if (ctx->r3 == ctx->r2) {
        // 0x8004ED44: nop
    
            goto L_8004ED60;
    }
    // 0x8004ED44: nop

L_8004ED48:
    // 0x8004ED48: lw          $a1, 0x1C($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X1C);
    // 0x8004ED4C: lw          $a2, 0x20($s2)
    ctx->r6 = MEM_W(ctx->r18, 0X20);
    // 0x8004ED50: sw          $zero, 0x24($s2)
    MEM_W(0X24, ctx->r18) = 0;
    // 0x8004ED54: lw          $a3, 0x24($s2)
    ctx->r7 = MEM_W(ctx->r18, 0X24);
    // 0x8004ED58: jal         0x800AA424
    // 0x8004ED5C: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_800AA424(rdram, ctx);
        goto after_52;
    // 0x8004ED5C: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_52:
L_8004ED60:
    // 0x8004ED60: lw          $ra, 0x114($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X114);
    // 0x8004ED64: lw          $s4, 0x110($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X110);
    // 0x8004ED68: lw          $s3, 0x10C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X10C);
    // 0x8004ED6C: lw          $s2, 0x108($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X108);
    // 0x8004ED70: lw          $s1, 0x104($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X104);
    // 0x8004ED74: lw          $s0, 0x100($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X100);
    // 0x8004ED78: ldc1        $f24, 0x128($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X128);
    // 0x8004ED7C: ldc1        $f22, 0x120($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X120);
    // 0x8004ED80: ldc1        $f20, 0x118($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X118);
    // 0x8004ED84: jr          $ra
    // 0x8004ED88: addiu       $sp, $sp, 0x130
    ctx->r29 = ADD32(ctx->r29, 0X130);
    return;
    // 0x8004ED88: addiu       $sp, $sp, 0x130
    ctx->r29 = ADD32(ctx->r29, 0X130);
;}
RECOMP_FUNC void func_8004ED8C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8004ED8C: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8004ED90: sw          $s4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r20;
    // 0x8004ED94: addu        $s4, $a0, $zero
    ctx->r20 = ADD32(ctx->r4, 0);
    // 0x8004ED98: sw          $s5, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r21;
    // 0x8004ED9C: lui         $v1, 0x8014
    ctx->r3 = S32(0X8014 << 16);
    // 0x8004EDA0: addiu       $v1, $v1, -0x72E8
    ctx->r3 = ADD32(ctx->r3, -0X72E8);
    // 0x8004EDA4: sll         $v0, $s4, 2
    ctx->r2 = S32(ctx->r20 << 2);
    // 0x8004EDA8: addu        $v0, $v0, $s4
    ctx->r2 = ADD32(ctx->r2, ctx->r20);
    // 0x8004EDAC: sll         $v0, $v0, 4
    ctx->r2 = S32(ctx->r2 << 4);
    // 0x8004EDB0: addu        $v0, $v0, $s4
    ctx->r2 = ADD32(ctx->r2, ctx->r20);
    // 0x8004EDB4: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8004EDB8: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8004EDBC: sw          $ra, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r31;
    // 0x8004EDC0: sw          $s3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r19;
    // 0x8004EDC4: sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // 0x8004EDC8: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x8004EDCC: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x8004EDD0: sdc1        $f20, 0x30($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X30, ctx->r29);
    // 0x8004EDD4: lw          $s2, 0x4($v0)
    ctx->r18 = MEM_W(ctx->r2, 0X4);
    // 0x8004EDD8: sll         $v0, $s4, 1
    ctx->r2 = S32(ctx->r20 << 1);
    // 0x8004EDDC: addu        $v0, $v0, $s4
    ctx->r2 = ADD32(ctx->r2, ctx->r20);
    // 0x8004EDE0: sll         $a0, $v0, 5
    ctx->r4 = S32(ctx->r2 << 5);
    // 0x8004EDE4: subu        $a0, $a0, $v0
    ctx->r4 = SUB32(ctx->r4, ctx->r2);
    // 0x8004EDE8: sll         $a0, $a0, 4
    ctx->r4 = S32(ctx->r4 << 4);
    // 0x8004EDEC: sll         $v0, $a1, 5
    ctx->r2 = S32(ctx->r5 << 5);
    // 0x8004EDF0: subu        $v0, $v0, $a1
    ctx->r2 = SUB32(ctx->r2, ctx->r5);
    // 0x8004EDF4: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x8004EDF8: lui         $v1, 0x8014
    ctx->r3 = S32(0X8014 << 16);
    // 0x8004EDFC: addiu       $v1, $v1, -0x7D98
    ctx->r3 = ADD32(ctx->r3, -0X7D98);
    // 0x8004EE00: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8004EE04: addu        $s1, $a0, $v0
    ctx->r17 = ADD32(ctx->r4, ctx->r2);
    // 0x8004EE08: beq         $s2, $s1, L_8004EF84
    if (ctx->r18 == ctx->r17) {
        // 0x8004EE0C: addu        $s5, $a2, $zero
        ctx->r21 = ADD32(ctx->r6, 0);
            goto L_8004EF84;
    }
    // 0x8004EE0C: addu        $s5, $a2, $zero
    ctx->r21 = ADD32(ctx->r6, 0);
    // 0x8004EE10: lhu         $v0, 0x0($s2)
    ctx->r2 = MEM_HU(ctx->r18, 0X0);
    // 0x8004EE14: lhu         $v1, 0x2($s2)
    ctx->r3 = MEM_HU(ctx->r18, 0X2);
    // 0x8004EE18: andi        $v0, $v0, 0xFFFE
    ctx->r2 = ctx->r2 & 0XFFFE;
    // 0x8004EE1C: sh          $v0, 0x0($s2)
    MEM_H(0X0, ctx->r18) = ctx->r2;
    // 0x8004EE20: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // 0x8004EE24: bne         $v1, $v0, L_8004EE84
    if (ctx->r3 != ctx->r2) {
        // 0x8004EE28: ori         $s3, $zero, 0xFFFF
        ctx->r19 = 0 | 0XFFFF;
            goto L_8004EE84;
    }
    // 0x8004EE28: ori         $s3, $zero, 0xFFFF
    ctx->r19 = 0 | 0XFFFF;
    // 0x8004EE2C: lw          $s0, 0xBC($s2)
    ctx->r16 = MEM_W(ctx->r18, 0XBC);
    // 0x8004EE30: lhu         $v0, 0xF4($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0XF4);
    // 0x8004EE34: beq         $v0, $s3, L_8004EE48
    if (ctx->r2 == ctx->r19) {
        // 0x8004EE38: nop
    
            goto L_8004EE48;
    }
    // 0x8004EE38: nop

    // 0x8004EE3C: jal         0x8003F0C8
    // 0x8004EE40: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    func_8003F0C8(rdram, ctx);
        goto after_0;
    // 0x8004EE40: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    after_0:
    // 0x8004EE44: sh          $s3, 0xF4($s0)
    MEM_H(0XF4, ctx->r16) = ctx->r19;
L_8004EE48:
    // 0x8004EE48: lw          $v0, 0xBC($s2)
    ctx->r2 = MEM_W(ctx->r18, 0XBC);
    // 0x8004EE4C: lhu         $v1, 0x0($v0)
    ctx->r3 = MEM_HU(ctx->r2, 0X0);
    // 0x8004EE50: andi        $v1, $v1, 0xFFFE
    ctx->r3 = ctx->r3 & 0XFFFE;
    // 0x8004EE54: sh          $v1, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r3;
    // 0x8004EE58: lw          $s0, 0xC0($s2)
    ctx->r16 = MEM_W(ctx->r18, 0XC0);
    // 0x8004EE5C: lhu         $v0, 0xF4($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0XF4);
    // 0x8004EE60: beq         $v0, $s3, L_8004EE74
    if (ctx->r2 == ctx->r19) {
        // 0x8004EE64: nop
    
            goto L_8004EE74;
    }
    // 0x8004EE64: nop

    // 0x8004EE68: jal         0x8003F0C8
    // 0x8004EE6C: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    func_8003F0C8(rdram, ctx);
        goto after_1;
    // 0x8004EE6C: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    after_1:
    // 0x8004EE70: sh          $s3, 0xF4($s0)
    MEM_H(0XF4, ctx->r16) = ctx->r19;
L_8004EE74:
    // 0x8004EE74: lw          $v1, 0xC0($s2)
    ctx->r3 = MEM_W(ctx->r18, 0XC0);
    // 0x8004EE78: lhu         $v0, 0x0($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X0);
    // 0x8004EE7C: andi        $v0, $v0, 0xFFFE
    ctx->r2 = ctx->r2 & 0XFFFE;
    // 0x8004EE80: sh          $v0, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r2;
L_8004EE84:
    // 0x8004EE84: lhu         $v0, 0xF4($s2)
    ctx->r2 = MEM_HU(ctx->r18, 0XF4);
    // 0x8004EE88: ori         $s0, $zero, 0xFFFF
    ctx->r16 = 0 | 0XFFFF;
    // 0x8004EE8C: beq         $v0, $s0, L_8004EEA4
    if (ctx->r2 == ctx->r16) {
        // 0x8004EE90: lui         $v1, 0x8014
        ctx->r3 = S32(0X8014 << 16);
            goto L_8004EEA4;
    }
    // 0x8004EE90: lui         $v1, 0x8014
    ctx->r3 = S32(0X8014 << 16);
    // 0x8004EE94: jal         0x8003F0C8
    // 0x8004EE98: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    func_8003F0C8(rdram, ctx);
        goto after_2;
    // 0x8004EE98: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    after_2:
    // 0x8004EE9C: sh          $s0, 0xF4($s2)
    MEM_H(0XF4, ctx->r18) = ctx->r16;
    // 0x8004EEA0: lui         $v1, 0x8014
    ctx->r3 = S32(0X8014 << 16);
L_8004EEA4:
    // 0x8004EEA4: addiu       $v1, $v1, -0x72E8
    ctx->r3 = ADD32(ctx->r3, -0X72E8);
    // 0x8004EEA8: sll         $v0, $s4, 2
    ctx->r2 = S32(ctx->r20 << 2);
    // 0x8004EEAC: addu        $v0, $v0, $s4
    ctx->r2 = ADD32(ctx->r2, ctx->r20);
    // 0x8004EEB0: sll         $v0, $v0, 4
    ctx->r2 = S32(ctx->r2 << 4);
    // 0x8004EEB4: addu        $v0, $v0, $s4
    ctx->r2 = ADD32(ctx->r2, ctx->r20);
    // 0x8004EEB8: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8004EEBC: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8004EEC0: sw          $s1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r17;
    // 0x8004EEC4: lhu         $v0, 0x0($s1)
    ctx->r2 = MEM_HU(ctx->r17, 0X0);
    // 0x8004EEC8: ori         $v0, $v0, 0x1
    ctx->r2 = ctx->r2 | 0X1;
    // 0x8004EECC: sh          $v0, 0x0($s1)
    MEM_H(0X0, ctx->r17) = ctx->r2;
    // 0x8004EED0: andi        $v0, $s5, 0xFF
    ctx->r2 = ctx->r21 & 0XFF;
    // 0x8004EED4: beq         $v0, $zero, L_8004EF28
    if (ctx->r2 == 0) {
        // 0x8004EED8: addiu       $v1, $s2, 0x28
        ctx->r3 = ADD32(ctx->r18, 0X28);
            goto L_8004EF28;
    }
    // 0x8004EED8: addiu       $v1, $s2, 0x28
    ctx->r3 = ADD32(ctx->r18, 0X28);
    // 0x8004EEDC: addiu       $a0, $s1, 0x28
    ctx->r4 = ADD32(ctx->r17, 0X28);
    // 0x8004EEE0: addiu       $v0, $s2, 0x58
    ctx->r2 = ADD32(ctx->r18, 0X58);
L_8004EEE4:
    // 0x8004EEE4: lw          $a3, 0x0($v1)
    ctx->r7 = MEM_W(ctx->r3, 0X0);
    // 0x8004EEE8: lw          $t0, 0x4($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X4);
    // 0x8004EEEC: lw          $t1, 0x8($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X8);
    // 0x8004EEF0: lw          $t2, 0xC($v1)
    ctx->r10 = MEM_W(ctx->r3, 0XC);
    // 0x8004EEF4: sw          $a3, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r7;
    // 0x8004EEF8: sw          $t0, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r8;
    // 0x8004EEFC: sw          $t1, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r9;
    // 0x8004EF00: sw          $t2, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r10;
    // 0x8004EF04: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
    // 0x8004EF08: bne         $v1, $v0, L_8004EEE4
    if (ctx->r3 != ctx->r2) {
        // 0x8004EF0C: addiu       $a0, $a0, 0x10
        ctx->r4 = ADD32(ctx->r4, 0X10);
            goto L_8004EEE4;
    }
    // 0x8004EF0C: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    // 0x8004EF10: lwc1        $f0, 0x4C($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X4C);
    // 0x8004EF14: lwc1        $f2, 0x50($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0X50);
    // 0x8004EF18: lwc1        $f4, 0x54($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X54);
    // 0x8004EF1C: swc1        $f0, 0x10($s1)
    MEM_W(0X10, ctx->r17) = ctx->f0.u32l;
    // 0x8004EF20: swc1        $f2, 0x14($s1)
    MEM_W(0X14, ctx->r17) = ctx->f2.u32l;
    // 0x8004EF24: swc1        $f4, 0x18($s1)
    MEM_W(0X18, ctx->r17) = ctx->f4.u32l;
L_8004EF28:
    // 0x8004EF28: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x8004EF2C: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8004EF30: lwc1        $f20, -0x5654($at)
    ctx->f20.u32l = MEM_W(ctx->r1, -0X5654);
    // 0x8004EF34: lwc1        $f0, 0xA0($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0XA0);
    // 0x8004EF38: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x8004EF3C: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
    // 0x8004EF40: swc1        $f0, 0x98($s1)
    MEM_W(0X98, ctx->r17) = ctx->f0.u32l;
    // 0x8004EF44: jal         0x8004D2B0
    // 0x8004EF48: swc1        $f2, 0x9C($s1)
    MEM_W(0X9C, ctx->r17) = ctx->f2.u32l;
    func_8004D2B0(rdram, ctx);
        goto after_3;
    // 0x8004EF48: swc1        $f2, 0x9C($s1)
    MEM_W(0X9C, ctx->r17) = ctx->f2.u32l;
    after_3:
    // 0x8004EF4C: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    // 0x8004EF50: lw          $v0, 0xC($s1)
    ctx->r2 = MEM_W(ctx->r17, 0XC);
    // 0x8004EF54: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x8004EF58: sll         $a0, $v0, 2
    ctx->r4 = S32(ctx->r2 << 2);
    // 0x8004EF5C: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // 0x8004EF60: sll         $a0, $a0, 4
    ctx->r4 = S32(ctx->r4 << 4);
    // 0x8004EF64: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // 0x8004EF68: sll         $a0, $a0, 2
    ctx->r4 = S32(ctx->r4 << 2);
    // 0x8004EF6C: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x8004EF70: addiu       $v0, $v0, -0x72E8
    ctx->r2 = ADD32(ctx->r2, -0X72E8);
    // 0x8004EF74: jal         0x8004E140
    // 0x8004EF78: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    func_8004E140(rdram, ctx);
        goto after_4;
    // 0x8004EF78: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    after_4:
    // 0x8004EF7C: jal         0x80066A50
    // 0x8004EF80: nop

    func_80066A50(rdram, ctx);
        goto after_5;
    // 0x8004EF80: nop

    after_5:
L_8004EF84:
    // 0x8004EF84: lw          $ra, 0x28($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X28);
    // 0x8004EF88: lw          $s5, 0x24($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X24);
    // 0x8004EF8C: lw          $s4, 0x20($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X20);
    // 0x8004EF90: lw          $s3, 0x1C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X1C);
    // 0x8004EF94: lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X18);
    // 0x8004EF98: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x8004EF9C: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x8004EFA0: ldc1        $f20, 0x30($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X30);
    // 0x8004EFA4: jr          $ra
    // 0x8004EFA8: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x8004EFA8: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_8004EFAC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8004EFAC: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8004EFB0: sw          $s4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r20;
    // 0x8004EFB4: addu        $s4, $a0, $zero
    ctx->r20 = ADD32(ctx->r4, 0);
    // 0x8004EFB8: sw          $s5, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r21;
    // 0x8004EFBC: lui         $v1, 0x8014
    ctx->r3 = S32(0X8014 << 16);
    // 0x8004EFC0: addiu       $v1, $v1, -0x72E8
    ctx->r3 = ADD32(ctx->r3, -0X72E8);
    // 0x8004EFC4: sll         $v0, $s4, 2
    ctx->r2 = S32(ctx->r20 << 2);
    // 0x8004EFC8: addu        $v0, $v0, $s4
    ctx->r2 = ADD32(ctx->r2, ctx->r20);
    // 0x8004EFCC: sll         $v0, $v0, 4
    ctx->r2 = S32(ctx->r2 << 4);
    // 0x8004EFD0: addu        $v0, $v0, $s4
    ctx->r2 = ADD32(ctx->r2, ctx->r20);
    // 0x8004EFD4: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8004EFD8: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8004EFDC: sll         $a0, $s4, 5
    ctx->r4 = S32(ctx->r20 << 5);
    // 0x8004EFE0: subu        $a0, $a0, $s4
    ctx->r4 = SUB32(ctx->r4, ctx->r20);
    // 0x8004EFE4: sll         $a0, $a0, 5
    ctx->r4 = S32(ctx->r4 << 5);
    // 0x8004EFE8: sw          $ra, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r31;
    // 0x8004EFEC: sw          $s3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r19;
    // 0x8004EFF0: sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // 0x8004EFF4: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x8004EFF8: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x8004EFFC: sdc1        $f20, 0x30($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X30, ctx->r29);
    // 0x8004F000: lw          $s2, 0x4($v0)
    ctx->r18 = MEM_W(ctx->r2, 0X4);
    // 0x8004F004: sll         $v0, $a1, 5
    ctx->r2 = S32(ctx->r5 << 5);
    // 0x8004F008: subu        $v0, $v0, $a1
    ctx->r2 = SUB32(ctx->r2, ctx->r5);
    // 0x8004F00C: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x8004F010: lui         $v1, 0x8014
    ctx->r3 = S32(0X8014 << 16);
    // 0x8004F014: addiu       $v1, $v1, -0x76D0
    ctx->r3 = ADD32(ctx->r3, -0X76D0);
    // 0x8004F018: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8004F01C: addu        $s1, $a0, $v0
    ctx->r17 = ADD32(ctx->r4, ctx->r2);
    // 0x8004F020: beq         $s2, $s1, L_8004F1A4
    if (ctx->r18 == ctx->r17) {
        // 0x8004F024: addu        $s5, $a2, $zero
        ctx->r21 = ADD32(ctx->r6, 0);
            goto L_8004F1A4;
    }
    // 0x8004F024: addu        $s5, $a2, $zero
    ctx->r21 = ADD32(ctx->r6, 0);
    // 0x8004F028: lhu         $v0, 0x0($s2)
    ctx->r2 = MEM_HU(ctx->r18, 0X0);
    // 0x8004F02C: lhu         $v1, 0x2($s2)
    ctx->r3 = MEM_HU(ctx->r18, 0X2);
    // 0x8004F030: andi        $v0, $v0, 0xFFFE
    ctx->r2 = ctx->r2 & 0XFFFE;
    // 0x8004F034: sh          $v0, 0x0($s2)
    MEM_H(0X0, ctx->r18) = ctx->r2;
    // 0x8004F038: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // 0x8004F03C: bne         $v1, $v0, L_8004F09C
    if (ctx->r3 != ctx->r2) {
        // 0x8004F040: ori         $s3, $zero, 0xFFFF
        ctx->r19 = 0 | 0XFFFF;
            goto L_8004F09C;
    }
    // 0x8004F040: ori         $s3, $zero, 0xFFFF
    ctx->r19 = 0 | 0XFFFF;
    // 0x8004F044: lw          $s0, 0xBC($s2)
    ctx->r16 = MEM_W(ctx->r18, 0XBC);
    // 0x8004F048: lhu         $v0, 0xF4($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0XF4);
    // 0x8004F04C: beq         $v0, $s3, L_8004F060
    if (ctx->r2 == ctx->r19) {
        // 0x8004F050: nop
    
            goto L_8004F060;
    }
    // 0x8004F050: nop

    // 0x8004F054: jal         0x8003F0C8
    // 0x8004F058: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    func_8003F0C8(rdram, ctx);
        goto after_0;
    // 0x8004F058: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    after_0:
    // 0x8004F05C: sh          $s3, 0xF4($s0)
    MEM_H(0XF4, ctx->r16) = ctx->r19;
L_8004F060:
    // 0x8004F060: lw          $v0, 0xBC($s2)
    ctx->r2 = MEM_W(ctx->r18, 0XBC);
    // 0x8004F064: lhu         $v1, 0x0($v0)
    ctx->r3 = MEM_HU(ctx->r2, 0X0);
    // 0x8004F068: andi        $v1, $v1, 0xFFFE
    ctx->r3 = ctx->r3 & 0XFFFE;
    // 0x8004F06C: sh          $v1, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r3;
    // 0x8004F070: lw          $s0, 0xC0($s2)
    ctx->r16 = MEM_W(ctx->r18, 0XC0);
    // 0x8004F074: lhu         $v0, 0xF4($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0XF4);
    // 0x8004F078: beq         $v0, $s3, L_8004F08C
    if (ctx->r2 == ctx->r19) {
        // 0x8004F07C: nop
    
            goto L_8004F08C;
    }
    // 0x8004F07C: nop

    // 0x8004F080: jal         0x8003F0C8
    // 0x8004F084: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    func_8003F0C8(rdram, ctx);
        goto after_1;
    // 0x8004F084: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    after_1:
    // 0x8004F088: sh          $s3, 0xF4($s0)
    MEM_H(0XF4, ctx->r16) = ctx->r19;
L_8004F08C:
    // 0x8004F08C: lw          $v1, 0xC0($s2)
    ctx->r3 = MEM_W(ctx->r18, 0XC0);
    // 0x8004F090: lhu         $v0, 0x0($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X0);
    // 0x8004F094: andi        $v0, $v0, 0xFFFE
    ctx->r2 = ctx->r2 & 0XFFFE;
    // 0x8004F098: sh          $v0, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r2;
L_8004F09C:
    // 0x8004F09C: lhu         $v0, 0xF4($s2)
    ctx->r2 = MEM_HU(ctx->r18, 0XF4);
    // 0x8004F0A0: ori         $s0, $zero, 0xFFFF
    ctx->r16 = 0 | 0XFFFF;
    // 0x8004F0A4: beql        $v0, $s0, L_8004F0BC
    if (ctx->r2 == ctx->r16) {
        // 0x8004F0A8: lui         $v0, 0x8014
        ctx->r2 = S32(0X8014 << 16);
            goto L_8004F0BC;
    }
    goto skip_0;
    // 0x8004F0A8: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    skip_0:
    // 0x8004F0AC: jal         0x8003F0C8
    // 0x8004F0B0: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    func_8003F0C8(rdram, ctx);
        goto after_2;
    // 0x8004F0B0: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    after_2:
    // 0x8004F0B4: sh          $s0, 0xF4($s2)
    MEM_H(0XF4, ctx->r18) = ctx->r16;
    // 0x8004F0B8: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
L_8004F0BC:
    // 0x8004F0BC: addiu       $v0, $v0, -0x72E8
    ctx->r2 = ADD32(ctx->r2, -0X72E8);
    // 0x8004F0C0: sll         $v1, $s4, 2
    ctx->r3 = S32(ctx->r20 << 2);
    // 0x8004F0C4: addu        $v1, $v1, $s4
    ctx->r3 = ADD32(ctx->r3, ctx->r20);
    // 0x8004F0C8: sll         $v1, $v1, 4
    ctx->r3 = S32(ctx->r3 << 4);
    // 0x8004F0CC: addu        $v1, $v1, $s4
    ctx->r3 = ADD32(ctx->r3, ctx->r20);
    // 0x8004F0D0: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x8004F0D4: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x8004F0D8: sw          $s1, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r17;
    // 0x8004F0DC: lhu         $v0, 0x0($s1)
    ctx->r2 = MEM_HU(ctx->r17, 0X0);
    // 0x8004F0E0: ori         $v0, $v0, 0x1
    ctx->r2 = ctx->r2 | 0X1;
    // 0x8004F0E4: sh          $v0, 0x0($s1)
    MEM_H(0X0, ctx->r17) = ctx->r2;
    // 0x8004F0E8: andi        $v0, $v0, 0x20
    ctx->r2 = ctx->r2 & 0X20;
    // 0x8004F0EC: bne         $v0, $zero, L_8004F158
    if (ctx->r2 != 0) {
        // 0x8004F0F0: andi        $v0, $s5, 0xFF
        ctx->r2 = ctx->r21 & 0XFF;
            goto L_8004F158;
    }
    // 0x8004F0F0: andi        $v0, $s5, 0xFF
    ctx->r2 = ctx->r21 & 0XFF;
    // 0x8004F0F4: beq         $v0, $zero, L_8004F158
    if (ctx->r2 == 0) {
        // 0x8004F0F8: addiu       $v1, $s2, 0x28
        ctx->r3 = ADD32(ctx->r18, 0X28);
            goto L_8004F158;
    }
    // 0x8004F0F8: addiu       $v1, $s2, 0x28
    ctx->r3 = ADD32(ctx->r18, 0X28);
    // 0x8004F0FC: addiu       $a0, $s1, 0x28
    ctx->r4 = ADD32(ctx->r17, 0X28);
    // 0x8004F100: addiu       $v0, $s2, 0x58
    ctx->r2 = ADD32(ctx->r18, 0X58);
L_8004F104:
    // 0x8004F104: lw          $a3, 0x0($v1)
    ctx->r7 = MEM_W(ctx->r3, 0X0);
    // 0x8004F108: lw          $t0, 0x4($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X4);
    // 0x8004F10C: lw          $t1, 0x8($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X8);
    // 0x8004F110: lw          $t2, 0xC($v1)
    ctx->r10 = MEM_W(ctx->r3, 0XC);
    // 0x8004F114: sw          $a3, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r7;
    // 0x8004F118: sw          $t0, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r8;
    // 0x8004F11C: sw          $t1, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r9;
    // 0x8004F120: sw          $t2, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r10;
    // 0x8004F124: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
    // 0x8004F128: bne         $v1, $v0, L_8004F104
    if (ctx->r3 != ctx->r2) {
        // 0x8004F12C: addiu       $a0, $a0, 0x10
        ctx->r4 = ADD32(ctx->r4, 0X10);
            goto L_8004F104;
    }
    // 0x8004F12C: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    // 0x8004F130: lwc1        $f0, 0x4C($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X4C);
    // 0x8004F134: lwc1        $f2, 0x50($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0X50);
    // 0x8004F138: lwc1        $f6, 0xA0($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0XA0);
    // 0x8004F13C: lwc1        $f4, 0x54($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X54);
    // 0x8004F140: mov.s       $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = ctx->f6.fl;
    // 0x8004F144: swc1        $f0, 0x10($s1)
    MEM_W(0X10, ctx->r17) = ctx->f0.u32l;
    // 0x8004F148: swc1        $f2, 0x14($s1)
    MEM_W(0X14, ctx->r17) = ctx->f2.u32l;
    // 0x8004F14C: swc1        $f4, 0x18($s1)
    MEM_W(0X18, ctx->r17) = ctx->f4.u32l;
    // 0x8004F150: swc1        $f6, 0x98($s1)
    MEM_W(0X98, ctx->r17) = ctx->f6.u32l;
    // 0x8004F154: swc1        $f8, 0x9C($s1)
    MEM_W(0X9C, ctx->r17) = ctx->f8.u32l;
L_8004F158:
    // 0x8004F158: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8004F15C: lwc1        $f20, -0x5650($at)
    ctx->f20.u32l = MEM_W(ctx->r1, -0X5650);
    // 0x8004F160: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x8004F164: jal         0x8004D2B0
    // 0x8004F168: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    func_8004D2B0(rdram, ctx);
        goto after_3;
    // 0x8004F168: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    after_3:
    // 0x8004F16C: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    // 0x8004F170: lw          $v0, 0xC($s1)
    ctx->r2 = MEM_W(ctx->r17, 0XC);
    // 0x8004F174: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x8004F178: sll         $a0, $v0, 2
    ctx->r4 = S32(ctx->r2 << 2);
    // 0x8004F17C: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // 0x8004F180: sll         $a0, $a0, 4
    ctx->r4 = S32(ctx->r4 << 4);
    // 0x8004F184: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // 0x8004F188: sll         $a0, $a0, 2
    ctx->r4 = S32(ctx->r4 << 2);
    // 0x8004F18C: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x8004F190: addiu       $v0, $v0, -0x72E8
    ctx->r2 = ADD32(ctx->r2, -0X72E8);
    // 0x8004F194: jal         0x8004E140
    // 0x8004F198: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    func_8004E140(rdram, ctx);
        goto after_4;
    // 0x8004F198: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    after_4:
    // 0x8004F19C: jal         0x80066A50
    // 0x8004F1A0: nop

    func_80066A50(rdram, ctx);
        goto after_5;
    // 0x8004F1A0: nop

    after_5:
L_8004F1A4:
    // 0x8004F1A4: lw          $ra, 0x28($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X28);
    // 0x8004F1A8: lw          $s5, 0x24($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X24);
    // 0x8004F1AC: lw          $s4, 0x20($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X20);
    // 0x8004F1B0: lw          $s3, 0x1C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X1C);
    // 0x8004F1B4: lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X18);
    // 0x8004F1B8: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x8004F1BC: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x8004F1C0: ldc1        $f20, 0x30($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X30);
    // 0x8004F1C4: jr          $ra
    // 0x8004F1C8: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x8004F1C8: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_8004F1CC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8004F1CC: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x8004F1D0: sw          $s0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r16;
    // 0x8004F1D4: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x8004F1D8: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x8004F1DC: sw          $ra, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r31;
    // 0x8004F1E0: lhu         $v1, 0x4($s0)
    ctx->r3 = MEM_HU(ctx->r16, 0X4);
    // 0x8004F1E4: mtc1        $a1, $f10
    ctx->f10.u32l = ctx->r5;
    // 0x8004F1E8: bne         $v1, $v0, L_8004F2A8
    if (ctx->r3 != ctx->r2) {
        // 0x8004F1EC: lui         $a1, 0x8011
        ctx->r5 = S32(0X8011 << 16);
            goto L_8004F2A8;
    }
    // 0x8004F1EC: lui         $a1, 0x8011
    ctx->r5 = S32(0X8011 << 16);
    // 0x8004F1F0: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x8004F1F4: lw          $v1, 0xC($s0)
    ctx->r3 = MEM_W(ctx->r16, 0XC);
    // 0x8004F1F8: addiu       $a0, $a0, 0x7DB8
    ctx->r4 = ADD32(ctx->r4, 0X7DB8);
    // 0x8004F1FC: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x8004F200: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8004F204: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8004F208: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8004F20C: sll         $v0, $v0, 5
    ctx->r2 = S32(ctx->r2 << 5);
    // 0x8004F210: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x8004F214: lhu         $v1, 0xB8($v0)
    ctx->r3 = MEM_HU(ctx->r2, 0XB8);
    // 0x8004F218: addiu       $a1, $a1, -0x5EBC
    ctx->r5 = ADD32(ctx->r5, -0X5EBC);
    // 0x8004F21C: sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3 << 1);
    // 0x8004F220: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8004F224: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8004F228: addu        $v0, $v0, $a1
    ctx->r2 = ADD32(ctx->r2, ctx->r5);
    // 0x8004F22C: lw          $v1, 0xC($s0)
    ctx->r3 = MEM_W(ctx->r16, 0XC);
    // 0x8004F230: lwc1        $f0, 0x0($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8004F234: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x8004F238: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8004F23C: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8004F240: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8004F244: sll         $v0, $v0, 5
    ctx->r2 = S32(ctx->r2 << 5);
    // 0x8004F248: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x8004F24C: swc1        $f0, 0xD4($s0)
    MEM_W(0XD4, ctx->r16) = ctx->f0.u32l;
    // 0x8004F250: lhu         $v1, 0xB8($v0)
    ctx->r3 = MEM_HU(ctx->r2, 0XB8);
    // 0x8004F254: sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3 << 1);
    // 0x8004F258: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8004F25C: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8004F260: addu        $v0, $v0, $a1
    ctx->r2 = ADD32(ctx->r2, ctx->r5);
    // 0x8004F264: lw          $v1, 0xC($s0)
    ctx->r3 = MEM_W(ctx->r16, 0XC);
    // 0x8004F268: lwc1        $f0, 0x4($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X4);
    // 0x8004F26C: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x8004F270: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8004F274: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8004F278: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8004F27C: sll         $v0, $v0, 5
    ctx->r2 = S32(ctx->r2 << 5);
    // 0x8004F280: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x8004F284: swc1        $f0, 0xE4($s0)
    MEM_W(0XE4, ctx->r16) = ctx->f0.u32l;
    // 0x8004F288: lhu         $v1, 0xB8($v0)
    ctx->r3 = MEM_HU(ctx->r2, 0XB8);
    // 0x8004F28C: sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3 << 1);
    // 0x8004F290: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8004F294: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8004F298: addu        $v0, $v0, $a1
    ctx->r2 = ADD32(ctx->r2, ctx->r5);
    // 0x8004F29C: lwc1        $f0, 0x8($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X8);
    // 0x8004F2A0: j           L_8004F2CC
    // 0x8004F2A4: swc1        $f0, 0xE8($s0)
    MEM_W(0XE8, ctx->r16) = ctx->f0.u32l;
        goto L_8004F2CC;
    // 0x8004F2A4: swc1        $f0, 0xE8($s0)
    MEM_W(0XE8, ctx->r16) = ctx->f0.u32l;
L_8004F2A8:
    // 0x8004F2A8: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8004F2AC: lwc1        $f0, -0x564C($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X564C);
    // 0x8004F2B0: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8004F2B4: lwc1        $f2, -0x5648($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X5648);
    // 0x8004F2B8: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8004F2BC: lwc1        $f4, -0x5644($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X5644);
    // 0x8004F2C0: swc1        $f0, 0xD4($s0)
    MEM_W(0XD4, ctx->r16) = ctx->f0.u32l;
    // 0x8004F2C4: swc1        $f2, 0xE4($s0)
    MEM_W(0XE4, ctx->r16) = ctx->f2.u32l;
    // 0x8004F2C8: swc1        $f4, 0xE8($s0)
    MEM_W(0XE8, ctx->r16) = ctx->f4.u32l;
L_8004F2CC:
    // 0x8004F2CC: lhu         $v0, 0x0($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X0);
    // 0x8004F2D0: andi        $v0, $v0, 0x10
    ctx->r2 = ctx->r2 & 0X10;
    // 0x8004F2D4: bne         $v0, $zero, L_8004F8CC
    if (ctx->r2 != 0) {
        // 0x8004F2D8: lui         $v0, 0x8014
        ctx->r2 = S32(0X8014 << 16);
            goto L_8004F8CC;
    }
    // 0x8004F2D8: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x8004F2DC: lbu         $v0, -0x77C8($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X77C8);
    // 0x8004F2E0: bne         $v0, $zero, L_8004F8CC
    if (ctx->r2 != 0) {
        // 0x8004F2E4: lui         $v0, 0x8013
        ctx->r2 = S32(0X8013 << 16);
            goto L_8004F8CC;
    }
    // 0x8004F2E4: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8004F2E8: lw          $a1, 0xC($s0)
    ctx->r5 = MEM_W(ctx->r16, 0XC);
    // 0x8004F2EC: addiu       $v0, $v0, 0x7DB8
    ctx->r2 = ADD32(ctx->r2, 0X7DB8);
    // 0x8004F2F0: sll         $v1, $a1, 2
    ctx->r3 = S32(ctx->r5 << 2);
    // 0x8004F2F4: addu        $v1, $v1, $a1
    ctx->r3 = ADD32(ctx->r3, ctx->r5);
    // 0x8004F2F8: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x8004F2FC: addu        $v1, $v1, $a1
    ctx->r3 = ADD32(ctx->r3, ctx->r5);
    // 0x8004F300: sll         $v1, $v1, 5
    ctx->r3 = S32(ctx->r3 << 5);
    // 0x8004F304: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x8004F308: lhu         $v0, 0x184($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X184);
    // 0x8004F30C: andi        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 & 0X1;
    // 0x8004F310: beq         $v0, $zero, L_8004F8CC
    if (ctx->r2 == 0) {
        // 0x8004F314: lui         $v0, 0x8011
        ctx->r2 = S32(0X8011 << 16);
            goto L_8004F8CC;
    }
    // 0x8004F314: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x8004F318: lw          $v0, -0x35E0($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X35E0);
    // 0x8004F31C: bne         $v0, $zero, L_8004F800
    if (ctx->r2 != 0) {
        // 0x8004F320: nop
    
            goto L_8004F800;
    }
    // 0x8004F320: nop

    // 0x8004F324: lhu         $v1, 0x4($s0)
    ctx->r3 = MEM_HU(ctx->r16, 0X4);
    // 0x8004F328: slti        $v0, $v1, 0x4
    ctx->r2 = SIGNED(ctx->r3) < 0X4 ? 1 : 0;
    // 0x8004F32C: beq         $v0, $zero, L_8004F800
    if (ctx->r2 == 0) {
        // 0x8004F330: nop
    
            goto L_8004F800;
    }
    // 0x8004F330: nop

    // 0x8004F334: beq         $v1, $zero, L_8004F800
    if (ctx->r3 == 0) {
        // 0x8004F338: lui         $v0, 0x8013
        ctx->r2 = S32(0X8013 << 16);
            goto L_8004F800;
    }
    // 0x8004F338: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8004F33C: addiu       $v0, $v0, 0xB88
    ctx->r2 = ADD32(ctx->r2, 0XB88);
    // 0x8004F340: sll         $v1, $a1, 1
    ctx->r3 = S32(ctx->r5 << 1);
    // 0x8004F344: addu        $v1, $v1, $a1
    ctx->r3 = ADD32(ctx->r3, ctx->r5);
    // 0x8004F348: sll         $v1, $v1, 1
    ctx->r3 = S32(ctx->r3 << 1);
    // 0x8004F34C: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x8004F350: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x8004F354: addiu       $a0, $a0, -0x41E8
    ctx->r4 = ADD32(ctx->r4, -0X41E8);
    // 0x8004F358: sll         $a2, $a1, 3
    ctx->r6 = S32(ctx->r5 << 3);
    // 0x8004F35C: addu        $v0, $a2, $a1
    ctx->r2 = ADD32(ctx->r6, ctx->r5);
    // 0x8004F360: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8004F364: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x8004F368: lhu         $v1, 0x0($v1)
    ctx->r3 = MEM_HU(ctx->r3, 0X0);
    // 0x8004F36C: lhu         $v0, 0x6($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X6);
    // 0x8004F370: and         $v1, $v1, $v0
    ctx->r3 = ctx->r3 & ctx->r2;
    // 0x8004F374: beq         $v1, $zero, L_8004F564
    if (ctx->r3 == 0) {
        // 0x8004F378: lui         $v0, 0x8011
        ctx->r2 = S32(0X8011 << 16);
            goto L_8004F564;
    }
    // 0x8004F378: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x8004F37C: addiu       $v1, $v0, -0x4228
    ctx->r3 = ADD32(ctx->r2, -0X4228);
    // 0x8004F380: addu        $v0, $a2, $v1
    ctx->r2 = ADD32(ctx->r6, ctx->r3);
    // 0x8004F384: lwc1        $f2, 0x0($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8004F388: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8004F38C: c.eq.s      $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f2.fl == ctx->f4.fl;
    // 0x8004F390: nop

    // 0x8004F394: bc1f        L_8004F3B4
    if (!c1cs) {
        // 0x8004F398: nop
    
            goto L_8004F3B4;
    }
    // 0x8004F398: nop

    // 0x8004F39C: lwc1        $f0, 0x4($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X4);
    // 0x8004F3A0: c.eq.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl == ctx->f4.fl;
    // 0x8004F3A4: nop

    // 0x8004F3A8: bc1t        L_8004F424
    if (c1cs) {
        // 0x8004F3AC: lui         $v0, 0x8013
        ctx->r2 = S32(0X8013 << 16);
            goto L_8004F424;
    }
    // 0x8004F3AC: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8004F3B0: c.eq.s      $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f2.fl == ctx->f4.fl;
L_8004F3B4:
    // 0x8004F3B4: nop

    // 0x8004F3B8: bc1t        L_8004F3E4
    if (c1cs) {
        // 0x8004F3BC: nop
    
            goto L_8004F3E4;
    }
    // 0x8004F3BC: nop

    // 0x8004F3C0: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8004F3C4: lwc1        $f0, -0x5640($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X5640);
    // 0x8004F3C8: neg.s       $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = -ctx->f2.fl;
    // 0x8004F3CC: mul.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x8004F3D0: nop

    // 0x8004F3D4: mul.s       $f2, $f2, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f10.fl);
    // 0x8004F3D8: lwc1        $f0, 0xD0($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0XD0);
    // 0x8004F3DC: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x8004F3E0: swc1        $f0, 0xD0($s0)
    MEM_W(0XD0, ctx->r16) = ctx->f0.u32l;
L_8004F3E4:
    // 0x8004F3E4: lw          $v0, 0xC($s0)
    ctx->r2 = MEM_W(ctx->r16, 0XC);
    // 0x8004F3E8: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x8004F3EC: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8004F3F0: lwc1        $f0, 0x4($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X4);
    // 0x8004F3F4: c.eq.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl == ctx->f4.fl;
    // 0x8004F3F8: nop

    // 0x8004F3FC: bc1t        L_8004F424
    if (c1cs) {
        // 0x8004F400: lui         $v0, 0x8013
        ctx->r2 = S32(0X8013 << 16);
            goto L_8004F424;
    }
    // 0x8004F400: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8004F404: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8004F408: lwc1        $f2, -0x563C($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X563C);
    // 0x8004F40C: mul.s       $f2, $f0, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x8004F410: nop

    // 0x8004F414: mul.s       $f2, $f2, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f10.fl);
    // 0x8004F418: lwc1        $f0, 0xE0($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0XE0);
    // 0x8004F41C: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x8004F420: swc1        $f0, 0xE0($s0)
    MEM_W(0XE0, ctx->r16) = ctx->f0.u32l;
L_8004F424:
    // 0x8004F424: addiu       $v0, $v0, 0xB88
    ctx->r2 = ADD32(ctx->r2, 0XB88);
    // 0x8004F428: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x8004F42C: lw          $a1, 0xC($s0)
    ctx->r5 = MEM_W(ctx->r16, 0XC);
    // 0x8004F430: addiu       $a0, $a0, -0x41E8
    ctx->r4 = ADD32(ctx->r4, -0X41E8);
    // 0x8004F434: sll         $v1, $a1, 1
    ctx->r3 = S32(ctx->r5 << 1);
    // 0x8004F438: addu        $v1, $v1, $a1
    ctx->r3 = ADD32(ctx->r3, ctx->r5);
    // 0x8004F43C: sll         $v1, $v1, 1
    ctx->r3 = S32(ctx->r3 << 1);
    // 0x8004F440: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x8004F444: sll         $a2, $a1, 3
    ctx->r6 = S32(ctx->r5 << 3);
    // 0x8004F448: addu        $v0, $a2, $a1
    ctx->r2 = ADD32(ctx->r6, ctx->r5);
    // 0x8004F44C: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8004F450: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x8004F454: lhu         $v1, 0x0($v1)
    ctx->r3 = MEM_HU(ctx->r3, 0X0);
    // 0x8004F458: lhu         $v0, 0x6($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X6);
    // 0x8004F45C: and         $v1, $v1, $v0
    ctx->r3 = ctx->r3 & ctx->r2;
    // 0x8004F460: beq         $v1, $zero, L_8004F564
    if (ctx->r3 == 0) {
        // 0x8004F464: lui         $v0, 0x8011
        ctx->r2 = S32(0X8011 << 16);
            goto L_8004F564;
    }
    // 0x8004F464: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x8004F468: addiu       $v0, $v0, -0x4228
    ctx->r2 = ADD32(ctx->r2, -0X4228);
    // 0x8004F46C: addu        $v0, $a2, $v0
    ctx->r2 = ADD32(ctx->r6, ctx->r2);
    // 0x8004F470: lwc1        $f0, 0x0($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8004F474: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8004F478: c.eq.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl == ctx->f8.fl;
    // 0x8004F47C: nop

    // 0x8004F480: bc1f        L_8004F49C
    if (!c1cs) {
        // 0x8004F484: lui         $v1, 0x8014
        ctx->r3 = S32(0X8014 << 16);
            goto L_8004F49C;
    }
    // 0x8004F484: lui         $v1, 0x8014
    ctx->r3 = S32(0X8014 << 16);
    // 0x8004F488: lwc1        $f0, 0x4($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X4);
    // 0x8004F48C: c.eq.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl == ctx->f8.fl;
    // 0x8004F490: nop

    // 0x8004F494: bc1t        L_8004F564
    if (c1cs) {
        // 0x8004F498: nop
    
            goto L_8004F564;
    }
    // 0x8004F498: nop

L_8004F49C:
    // 0x8004F49C: addiu       $v1, $v1, -0x72E8
    ctx->r3 = ADD32(ctx->r3, -0X72E8);
    // 0x8004F4A0: sll         $v0, $a1, 2
    ctx->r2 = S32(ctx->r5 << 2);
    // 0x8004F4A4: addu        $v0, $v0, $a1
    ctx->r2 = ADD32(ctx->r2, ctx->r5);
    // 0x8004F4A8: sll         $v0, $v0, 4
    ctx->r2 = S32(ctx->r2 << 4);
    // 0x8004F4AC: addu        $v0, $v0, $a1
    ctx->r2 = ADD32(ctx->r2, ctx->r5);
    // 0x8004F4B0: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8004F4B4: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8004F4B8: lw          $v0, 0x4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X4);
    // 0x8004F4BC: lhu         $v1, 0x4($v0)
    ctx->r3 = MEM_HU(ctx->r2, 0X4);
    // 0x8004F4C0: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x8004F4C4: bne         $v1, $v0, L_8004F4EC
    if (ctx->r3 != ctx->r2) {
        // 0x8004F4C8: nop
    
            goto L_8004F4EC;
    }
    // 0x8004F4C8: nop

    // 0x8004F4CC: lwc1        $f0, 0xE0($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0XE0);
    // 0x8004F4D0: lwc1        $f2, 0xE4($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0XE4);
    // 0x8004F4D4: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x8004F4D8: nop

    // 0x8004F4DC: bc1tl       L_8004F528
    if (c1cs) {
        // 0x8004F4E0: swc1        $f2, 0xE0($s0)
        MEM_W(0XE0, ctx->r16) = ctx->f2.u32l;
            goto L_8004F528;
    }
    goto skip_0;
    // 0x8004F4E0: swc1        $f2, 0xE0($s0)
    MEM_W(0XE0, ctx->r16) = ctx->f2.u32l;
    skip_0:
    // 0x8004F4E4: j           L_8004F528
    // 0x8004F4E8: nop

        goto L_8004F528;
    // 0x8004F4E8: nop

L_8004F4EC:
    // 0x8004F4EC: lwc1        $f6, 0xE0($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XE0);
    // 0x8004F4F0: abs.s       $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = fabsf(ctx->f6.fl);
    // 0x8004F4F4: lwc1        $f4, 0xE4($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XE4);
    // 0x8004F4F8: abs.s       $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = fabsf(ctx->f4.fl);
    // 0x8004F4FC: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x8004F500: nop

    // 0x8004F504: bc1f        L_8004F528
    if (!c1cs) {
        // 0x8004F508: nop
    
            goto L_8004F528;
    }
    // 0x8004F508: nop

    // 0x8004F50C: c.lt.s      $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f6.fl < ctx->f8.fl;
    // 0x8004F510: nop

    // 0x8004F514: bc1fl       L_8004F524
    if (!c1cs) {
        // 0x8004F518: neg.s       $f0, $f4
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = -ctx->f4.fl;
            goto L_8004F524;
    }
    goto skip_1;
    // 0x8004F518: neg.s       $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = -ctx->f4.fl;
    skip_1:
    // 0x8004F51C: j           L_8004F528
    // 0x8004F520: swc1        $f4, 0xE0($s0)
    MEM_W(0XE0, ctx->r16) = ctx->f4.u32l;
        goto L_8004F528;
    // 0x8004F520: swc1        $f4, 0xE0($s0)
    MEM_W(0XE0, ctx->r16) = ctx->f4.u32l;
L_8004F524:
    // 0x8004F524: swc1        $f0, 0xE0($s0)
    MEM_W(0XE0, ctx->r16) = ctx->f0.u32l;
L_8004F528:
    // 0x8004F528: lwc1        $f4, 0xD0($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XD0);
    // 0x8004F52C: abs.s       $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = fabsf(ctx->f4.fl);
    // 0x8004F530: lwc1        $f2, 0xD4($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0XD4);
    // 0x8004F534: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x8004F538: nop

    // 0x8004F53C: bc1f        L_8004F564
    if (!c1cs) {
        // 0x8004F540: nop
    
            goto L_8004F564;
    }
    // 0x8004F540: nop

    // 0x8004F544: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8004F548: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x8004F54C: nop

    // 0x8004F550: bc1fl       L_8004F560
    if (!c1cs) {
        // 0x8004F554: neg.s       $f0, $f2
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = -ctx->f2.fl;
            goto L_8004F560;
    }
    goto skip_2;
    // 0x8004F554: neg.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = -ctx->f2.fl;
    skip_2:
    // 0x8004F558: j           L_8004F564
    // 0x8004F55C: swc1        $f2, 0xD0($s0)
    MEM_W(0XD0, ctx->r16) = ctx->f2.u32l;
        goto L_8004F564;
    // 0x8004F55C: swc1        $f2, 0xD0($s0)
    MEM_W(0XD0, ctx->r16) = ctx->f2.u32l;
L_8004F560:
    // 0x8004F560: swc1        $f0, 0xD0($s0)
    MEM_W(0XD0, ctx->r16) = ctx->f0.u32l;
L_8004F564:
    // 0x8004F564: lwc1        $f0, 0xE0($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0XE0);
    // 0x8004F568: lwc1        $f2, 0xE8($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0XE8);
    // 0x8004F56C: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x8004F570: nop

    // 0x8004F574: bc1tl       L_8004F57C
    if (c1cs) {
        // 0x8004F578: swc1        $f2, 0xE0($s0)
        MEM_W(0XE0, ctx->r16) = ctx->f2.u32l;
            goto L_8004F57C;
    }
    goto skip_3;
    // 0x8004F578: swc1        $f2, 0xE0($s0)
    MEM_W(0XE0, ctx->r16) = ctx->f2.u32l;
    skip_3:
L_8004F57C:
    // 0x8004F57C: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8004F580: lw          $a1, 0xC($s0)
    ctx->r5 = MEM_W(ctx->r16, 0XC);
    // 0x8004F584: addiu       $v0, $v0, 0xB40
    ctx->r2 = ADD32(ctx->r2, 0XB40);
    // 0x8004F588: sll         $a0, $a1, 2
    ctx->r4 = S32(ctx->r5 << 2);
    // 0x8004F58C: addu        $v0, $a0, $v0
    ctx->r2 = ADD32(ctx->r4, ctx->r2);
    // 0x8004F590: lw          $v0, 0xC($v0)
    ctx->r2 = MEM_W(ctx->r2, 0XC);
    // 0x8004F594: andi        $v0, $v0, 0x100
    ctx->r2 = ctx->r2 & 0X100;
    // 0x8004F598: bne         $v0, $zero, L_8004F5D0
    if (ctx->r2 != 0) {
        // 0x8004F59C: lui         $v0, 0x8013
        ctx->r2 = S32(0X8013 << 16);
            goto L_8004F5D0;
    }
    // 0x8004F59C: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8004F5A0: lui         $v1, 0x8014
    ctx->r3 = S32(0X8014 << 16);
    // 0x8004F5A4: addiu       $v1, $v1, -0x72E8
    ctx->r3 = ADD32(ctx->r3, -0X72E8);
    // 0x8004F5A8: addu        $v0, $a0, $a1
    ctx->r2 = ADD32(ctx->r4, ctx->r5);
    // 0x8004F5AC: sll         $v0, $v0, 4
    ctx->r2 = S32(ctx->r2 << 4);
    // 0x8004F5B0: addu        $v0, $v0, $a1
    ctx->r2 = ADD32(ctx->r2, ctx->r5);
    // 0x8004F5B4: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8004F5B8: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8004F5BC: lw          $v0, 0x4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X4);
    // 0x8004F5C0: lhu         $v1, 0x4($v0)
    ctx->r3 = MEM_HU(ctx->r2, 0X4);
    // 0x8004F5C4: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x8004F5C8: beq         $v1, $v0, L_8004F748
    if (ctx->r3 == ctx->r2) {
        // 0x8004F5CC: lui         $v0, 0x8013
        ctx->r2 = S32(0X8013 << 16);
            goto L_8004F748;
    }
    // 0x8004F5CC: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
L_8004F5D0:
    // 0x8004F5D0: addiu       $v0, $v0, 0xB88
    ctx->r2 = ADD32(ctx->r2, 0XB88);
    // 0x8004F5D4: sll         $v1, $a1, 1
    ctx->r3 = S32(ctx->r5 << 1);
    // 0x8004F5D8: addu        $v1, $v1, $a1
    ctx->r3 = ADD32(ctx->r3, ctx->r5);
    // 0x8004F5DC: sll         $v1, $v1, 1
    ctx->r3 = S32(ctx->r3 << 1);
    // 0x8004F5E0: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x8004F5E4: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x8004F5E8: addiu       $a0, $a0, -0x41E8
    ctx->r4 = ADD32(ctx->r4, -0X41E8);
    // 0x8004F5EC: sll         $a2, $a1, 3
    ctx->r6 = S32(ctx->r5 << 3);
    // 0x8004F5F0: addu        $v0, $a2, $a1
    ctx->r2 = ADD32(ctx->r6, ctx->r5);
    // 0x8004F5F4: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8004F5F8: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x8004F5FC: lhu         $v1, 0x0($v1)
    ctx->r3 = MEM_HU(ctx->r3, 0X0);
    // 0x8004F600: lhu         $v0, 0x6($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X6);
    // 0x8004F604: and         $v1, $v1, $v0
    ctx->r3 = ctx->r3 & ctx->r2;
    // 0x8004F608: beq         $v1, $zero, L_8004F630
    if (ctx->r3 == 0) {
        // 0x8004F60C: lui         $v0, 0x8011
        ctx->r2 = S32(0X8011 << 16);
            goto L_8004F630;
    }
    // 0x8004F60C: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x8004F610: addiu       $v0, $v0, -0x4228
    ctx->r2 = ADD32(ctx->r2, -0X4228);
    // 0x8004F614: addu        $v0, $a2, $v0
    ctx->r2 = ADD32(ctx->r6, ctx->r2);
    // 0x8004F618: lwc1        $f2, 0x0($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8004F61C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8004F620: c.eq.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl == ctx->f0.fl;
    // 0x8004F624: nop

    // 0x8004F628: bc1f        L_8004F68C
    if (!c1cs) {
        // 0x8004F62C: lui         $a0, 0x8013
        ctx->r4 = S32(0X8013 << 16);
            goto L_8004F68C;
    }
    // 0x8004F62C: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
L_8004F630:
    // 0x8004F630: lwc1        $f2, 0xD0($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0XD0);
    // 0x8004F634: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8004F638: c.lt.s      $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f4.fl < ctx->f2.fl;
    // 0x8004F63C: nop

    // 0x8004F640: bc1f        L_8004F664
    if (!c1cs) {
        // 0x8004F644: nop
    
            goto L_8004F664;
    }
    // 0x8004F644: nop

    // 0x8004F648: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8004F64C: lwc1        $f0, -0x5638($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X5638);
    // 0x8004F650: mul.s       $f0, $f10, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x8004F654: sub.s       $f0, $f2, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f2.fl - ctx->f0.fl;
    // 0x8004F658: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x8004F65C: j           L_8004F67C
    // 0x8004F660: swc1        $f0, 0xD0($s0)
    MEM_W(0XD0, ctx->r16) = ctx->f0.u32l;
        goto L_8004F67C;
    // 0x8004F660: swc1        $f0, 0xD0($s0)
    MEM_W(0XD0, ctx->r16) = ctx->f0.u32l;
L_8004F664:
    // 0x8004F664: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8004F668: lwc1        $f0, -0x5634($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X5634);
    // 0x8004F66C: mul.s       $f0, $f10, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x8004F670: add.s       $f0, $f2, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x8004F674: swc1        $f0, 0xD0($s0)
    MEM_W(0XD0, ctx->r16) = ctx->f0.u32l;
    // 0x8004F678: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
L_8004F67C:
    // 0x8004F67C: nop

    // 0x8004F680: bc1tl       L_8004F688
    if (c1cs) {
        // 0x8004F684: swc1        $f4, 0xD0($s0)
        MEM_W(0XD0, ctx->r16) = ctx->f4.u32l;
            goto L_8004F688;
    }
    goto skip_4;
    // 0x8004F684: swc1        $f4, 0xD0($s0)
    MEM_W(0XD0, ctx->r16) = ctx->f4.u32l;
    skip_4:
L_8004F688:
    // 0x8004F688: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
L_8004F68C:
    // 0x8004F68C: lw          $v1, 0xC($s0)
    ctx->r3 = MEM_W(ctx->r16, 0XC);
    // 0x8004F690: addiu       $a0, $a0, 0xB88
    ctx->r4 = ADD32(ctx->r4, 0XB88);
    // 0x8004F694: sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3 << 1);
    // 0x8004F698: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8004F69C: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x8004F6A0: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x8004F6A4: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x8004F6A8: addiu       $a0, $a0, -0x41E8
    ctx->r4 = ADD32(ctx->r4, -0X41E8);
    // 0x8004F6AC: sll         $a1, $v1, 3
    ctx->r5 = S32(ctx->r3 << 3);
    // 0x8004F6B0: addu        $v1, $a1, $v1
    ctx->r3 = ADD32(ctx->r5, ctx->r3);
    // 0x8004F6B4: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x8004F6B8: addu        $v1, $v1, $a0
    ctx->r3 = ADD32(ctx->r3, ctx->r4);
    // 0x8004F6BC: lhu         $v0, 0x0($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X0);
    // 0x8004F6C0: lhu         $v1, 0x6($v1)
    ctx->r3 = MEM_HU(ctx->r3, 0X6);
    // 0x8004F6C4: and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // 0x8004F6C8: beq         $v0, $zero, L_8004F6F0
    if (ctx->r2 == 0) {
        // 0x8004F6CC: lui         $v0, 0x8011
        ctx->r2 = S32(0X8011 << 16);
            goto L_8004F6F0;
    }
    // 0x8004F6CC: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x8004F6D0: addiu       $v0, $v0, -0x4228
    ctx->r2 = ADD32(ctx->r2, -0X4228);
    // 0x8004F6D4: addu        $v0, $a1, $v0
    ctx->r2 = ADD32(ctx->r5, ctx->r2);
    // 0x8004F6D8: lwc1        $f2, 0x4($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X4);
    // 0x8004F6DC: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8004F6E0: c.eq.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl == ctx->f0.fl;
    // 0x8004F6E4: nop

    // 0x8004F6E8: bc1f        L_8004F74C
    if (!c1cs) {
        // 0x8004F6EC: lui         $a0, 0x8013
        ctx->r4 = S32(0X8013 << 16);
            goto L_8004F74C;
    }
    // 0x8004F6EC: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
L_8004F6F0:
    // 0x8004F6F0: lwc1        $f2, 0xE0($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0XE0);
    // 0x8004F6F4: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8004F6F8: c.lt.s      $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f4.fl < ctx->f2.fl;
    // 0x8004F6FC: nop

    // 0x8004F700: bc1f        L_8004F724
    if (!c1cs) {
        // 0x8004F704: nop
    
            goto L_8004F724;
    }
    // 0x8004F704: nop

    // 0x8004F708: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8004F70C: lwc1        $f0, -0x5630($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X5630);
    // 0x8004F710: mul.s       $f0, $f10, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x8004F714: sub.s       $f0, $f2, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f2.fl - ctx->f0.fl;
    // 0x8004F718: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x8004F71C: j           L_8004F73C
    // 0x8004F720: swc1        $f0, 0xE0($s0)
    MEM_W(0XE0, ctx->r16) = ctx->f0.u32l;
        goto L_8004F73C;
    // 0x8004F720: swc1        $f0, 0xE0($s0)
    MEM_W(0XE0, ctx->r16) = ctx->f0.u32l;
L_8004F724:
    // 0x8004F724: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8004F728: lwc1        $f0, -0x562C($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X562C);
    // 0x8004F72C: mul.s       $f0, $f10, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x8004F730: add.s       $f0, $f2, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x8004F734: swc1        $f0, 0xE0($s0)
    MEM_W(0XE0, ctx->r16) = ctx->f0.u32l;
    // 0x8004F738: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
L_8004F73C:
    // 0x8004F73C: nop

    // 0x8004F740: bc1tl       L_8004F748
    if (c1cs) {
        // 0x8004F744: swc1        $f4, 0xE0($s0)
        MEM_W(0XE0, ctx->r16) = ctx->f4.u32l;
            goto L_8004F748;
    }
    goto skip_5;
    // 0x8004F744: swc1        $f4, 0xE0($s0)
    MEM_W(0XE0, ctx->r16) = ctx->f4.u32l;
    skip_5:
L_8004F748:
    // 0x8004F748: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
L_8004F74C:
    // 0x8004F74C: lw          $v1, 0xC($s0)
    ctx->r3 = MEM_W(ctx->r16, 0XC);
    // 0x8004F750: addiu       $a0, $a0, 0x7DB8
    ctx->r4 = ADD32(ctx->r4, 0X7DB8);
    // 0x8004F754: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x8004F758: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8004F75C: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8004F760: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8004F764: sll         $v0, $v0, 5
    ctx->r2 = S32(ctx->r2 << 5);
    // 0x8004F768: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x8004F76C: lhu         $v1, 0xB8($v0)
    ctx->r3 = MEM_HU(ctx->r2, 0XB8);
    // 0x8004F770: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8004F774: bne         $v1, $v0, L_8004F800
    if (ctx->r3 != ctx->r2) {
        // 0x8004F778: nop
    
            goto L_8004F800;
    }
    // 0x8004F778: nop

    // 0x8004F77C: jal         0x800FEEF4
    // 0x8004F780: nop

    getHudSecondaryWeponCount(rdram, ctx);
        goto after_0;
    // 0x8004F780: nop

    after_0:
    // 0x8004F784: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x8004F788: beq         $v0, $zero, L_8004F800
    if (ctx->r2 == 0) {
        // 0x8004F78C: lui         $a0, 0x8014
        ctx->r4 = S32(0X8014 << 16);
            goto L_8004F800;
    }
    // 0x8004F78C: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8004F790: lw          $v1, 0xC($s0)
    ctx->r3 = MEM_W(ctx->r16, 0XC);
    // 0x8004F794: addiu       $a0, $a0, -0x72E8
    ctx->r4 = ADD32(ctx->r4, -0X72E8);
    // 0x8004F798: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x8004F79C: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8004F7A0: sll         $v0, $v0, 4
    ctx->r2 = S32(ctx->r2 << 4);
    // 0x8004F7A4: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8004F7A8: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8004F7AC: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x8004F7B0: lw          $v0, 0x4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X4);
    // 0x8004F7B4: lhu         $v1, 0x4($v0)
    ctx->r3 = MEM_HU(ctx->r2, 0X4);
    // 0x8004F7B8: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x8004F7BC: bne         $v1, $v0, L_8004F800
    if (ctx->r3 != ctx->r2) {
        // 0x8004F7C0: nop
    
            goto L_8004F800;
    }
    // 0x8004F7C0: nop

    // 0x8004F7C4: jal         0x800C722C
    // 0x8004F7C8: nop

    func_800C722C(rdram, ctx);
        goto after_1;
    // 0x8004F7C8: nop

    after_1:
    // 0x8004F7CC: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x8004F7D0: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x8004F7D4: nop

    // 0x8004F7D8: bc1t        L_8004F7F4
    if (c1cs) {
        // 0x8004F7DC: nop
    
            goto L_8004F7F4;
    }
    // 0x8004F7DC: nop

    // 0x8004F7E0: jal         0x800FEECC
    // 0x8004F7E4: nop

    func_800FEECC(rdram, ctx);
        goto after_2;
    // 0x8004F7E4: nop

    after_2:
    // 0x8004F7E8: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x8004F7EC: beq         $v0, $zero, L_8004F800
    if (ctx->r2 == 0) {
        // 0x8004F7F0: nop
    
            goto L_8004F800;
    }
    // 0x8004F7F0: nop

L_8004F7F4:
    // 0x8004F7F4: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8004F7F8: lwc1        $f0, -0x5628($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X5628);
    // 0x8004F7FC: swc1        $f0, 0xE0($s0)
    MEM_W(0XE0, ctx->r16) = ctx->f0.u32l;
L_8004F800:
    // 0x8004F800: lwc1        $f0, 0x4C($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X4C);
    // 0x8004F804: swc1        $f0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f0.u32l;
    // 0x8004F808: lwc1        $f0, 0x50($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X50);
    // 0x8004F80C: swc1        $f0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f0.u32l;
    // 0x8004F810: lwc1        $f0, 0x54($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X54);
    // 0x8004F814: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8004F818: swc1        $f0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f0.u32l;
    // 0x8004F81C: lw          $v1, 0xC($s0)
    ctx->r3 = MEM_W(ctx->r16, 0XC);
    // 0x8004F820: addiu       $a0, $a0, -0x72E8
    ctx->r4 = ADD32(ctx->r4, -0X72E8);
    // 0x8004F824: sw          $zero, 0x4C($s0)
    MEM_W(0X4C, ctx->r16) = 0;
    // 0x8004F828: sw          $zero, 0x50($s0)
    MEM_W(0X50, ctx->r16) = 0;
    // 0x8004F82C: sw          $zero, 0x54($s0)
    MEM_W(0X54, ctx->r16) = 0;
    // 0x8004F830: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x8004F834: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8004F838: sll         $v0, $v0, 4
    ctx->r2 = S32(ctx->r2 << 4);
    // 0x8004F83C: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8004F840: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8004F844: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x8004F848: lw          $v0, 0x4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X4);
    // 0x8004F84C: lhu         $v1, 0x4($v0)
    ctx->r3 = MEM_HU(ctx->r2, 0X4);
    // 0x8004F850: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x8004F854: bne         $v1, $v0, L_8004F880
    if (ctx->r3 != ctx->r2) {
        // 0x8004F858: lui         $v0, 0x8013
        ctx->r2 = S32(0X8013 << 16);
            goto L_8004F880;
    }
    // 0x8004F858: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8004F85C: lw          $a1, 0xD0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0XD0);
    // 0x8004F860: lw          $a2, 0xE0($s0)
    ctx->r6 = MEM_W(ctx->r16, 0XE0);
    // 0x8004F864: lw          $a3, 0x54($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X54);
    // 0x8004F868: jal         0x800AA570
    // 0x8004F86C: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    func_800AA570(rdram, ctx);
        goto after_3;
    // 0x8004F86C: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    after_3:
    // 0x8004F870: addiu       $a1, $sp, 0x10
    ctx->r5 = ADD32(ctx->r29, 0X10);
    // 0x8004F874: lw          $a0, 0x70($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X70);
    // 0x8004F878: j           L_8004F8AC
    // 0x8004F87C: addiu       $a2, $s0, 0x28
    ctx->r6 = ADD32(ctx->r16, 0X28);
        goto L_8004F8AC;
    // 0x8004F87C: addiu       $a2, $s0, 0x28
    ctx->r6 = ADD32(ctx->r16, 0X28);
L_8004F880:
    // 0x8004F880: lbu         $v0, 0x7CF4($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7CF4);
    // 0x8004F884: bne         $v0, $zero, L_8004F8B4
    if (ctx->r2 != 0) {
        // 0x8004F888: addiu       $a0, $sp, 0x10
        ctx->r4 = ADD32(ctx->r29, 0X10);
            goto L_8004F8B4;
    }
    // 0x8004F888: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    // 0x8004F88C: lwc1        $f0, 0x54($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X54);
    // 0x8004F890: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8004F894: lw          $a1, 0xD0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0XD0);
    // 0x8004F898: jal         0x800AA570
    // 0x8004F89C: addu        $a3, $a2, $zero
    ctx->r7 = ADD32(ctx->r6, 0);
    func_800AA570(rdram, ctx);
        goto after_4;
    // 0x8004F89C: addu        $a3, $a2, $zero
    ctx->r7 = ADD32(ctx->r6, 0);
    after_4:
    // 0x8004F8A0: addiu       $a0, $s0, 0x28
    ctx->r4 = ADD32(ctx->r16, 0X28);
    // 0x8004F8A4: addiu       $a1, $sp, 0x10
    ctx->r5 = ADD32(ctx->r29, 0X10);
    // 0x8004F8A8: addu        $a2, $a0, $zero
    ctx->r6 = ADD32(ctx->r4, 0);
L_8004F8AC:
    // 0x8004F8AC: jal         0x800191C4
    // 0x8004F8B0: nop

    func_800191C4(rdram, ctx);
        goto after_5;
    // 0x8004F8B0: nop

    after_5:
L_8004F8B4:
    // 0x8004F8B4: lwc1        $f0, 0x40($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X40);
    // 0x8004F8B8: swc1        $f0, 0x4C($s0)
    MEM_W(0X4C, ctx->r16) = ctx->f0.u32l;
    // 0x8004F8BC: lwc1        $f0, 0x44($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X44);
    // 0x8004F8C0: swc1        $f0, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->f0.u32l;
    // 0x8004F8C4: lwc1        $f0, 0x48($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X48);
    // 0x8004F8C8: swc1        $f0, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f0.u32l;
L_8004F8CC:
    // 0x8004F8CC: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
    // 0x8004F8D0: lw          $s0, 0x50($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X50);
    // 0x8004F8D4: jr          $ra
    // 0x8004F8D8: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    return;
    // 0x8004F8D8: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
;}
RECOMP_FUNC void func_8004F8DC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8004F8DC: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x8004F8E0: sdc1        $f20, 0x40($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X40, ctx->r29);
    // 0x8004F8E4: mov.s       $f20, $f12
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 12);
    ctx->f20.fl = ctx->f12.fl;
    // 0x8004F8E8: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x8004F8EC: ori         $s5, $zero, 0xFFFF
    ctx->r21 = 0 | 0XFFFF;
    // 0x8004F8F0: sdc1        $f22, 0x48($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X48, ctx->r29);
    // 0x8004F8F4: mtc1        $zero, $f22
    ctx->f22.u32l = 0;
    // 0x8004F8F8: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x8004F8FC: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x8004F900: addiu       $s4, $v0, -0x72E8
    ctx->r20 = ADD32(ctx->r2, -0X72E8);
    // 0x8004F904: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x8004F908: addu        $fp, $zero, $zero
    ctx->r30 = ADD32(0, 0);
    // 0x8004F90C: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x8004F910: addu        $s7, $fp, $zero
    ctx->r23 = ADD32(ctx->r30, 0);
    // 0x8004F914: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x8004F918: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x8004F91C: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x8004F920: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8004F924: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8004F928: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8004F92C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
L_8004F930:
    // 0x8004F930: lbu         $v0, 0x0($s4)
    ctx->r2 = MEM_BU(ctx->r20, 0X0);
    // 0x8004F934: beq         $v0, $zero, L_8004FB50
    if (ctx->r2 == 0) {
        // 0x8004F938: lui         $v0, 0x8011
        ctx->r2 = S32(0X8011 << 16);
            goto L_8004FB50;
    }
    // 0x8004F938: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x8004F93C: lw          $v1, -0x35E0($v0)
    ctx->r3 = MEM_W(ctx->r2, -0X35E0);
    // 0x8004F940: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
    // 0x8004F944: bne         $v1, $v0, L_8004F9B4
    if (ctx->r3 != ctx->r2) {
        // 0x8004F948: addu        $s2, $zero, $zero
        ctx->r18 = ADD32(0, 0);
            goto L_8004F9B4;
    }
    // 0x8004F948: addu        $s2, $zero, $zero
    ctx->r18 = ADD32(0, 0);
    // 0x8004F94C: lw          $s0, 0x4($s4)
    ctx->r16 = MEM_W(ctx->r20, 0X4);
    // 0x8004F950: lhu         $v0, 0xF4($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0XF4);
    // 0x8004F954: beq         $v0, $s5, L_8004F98C
    if (ctx->r2 == ctx->r21) {
        // 0x8004F958: nop
    
            goto L_8004F98C;
    }
    // 0x8004F958: nop

    // 0x8004F95C: jal         0x80040218
    // 0x8004F960: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    func_80040218(rdram, ctx);
        goto after_0;
    // 0x8004F960: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    after_0:
    // 0x8004F964: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x8004F968: bne         $v0, $s5, L_8004F98C
    if (ctx->r2 != ctx->r21) {
        // 0x8004F96C: nop
    
            goto L_8004F98C;
    }
    // 0x8004F96C: nop

    // 0x8004F970: lhu         $v0, 0xF4($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0XF4);
    // 0x8004F974: sh          $zero, 0x2($s0)
    MEM_H(0X2, ctx->r16) = 0;
    // 0x8004F978: beq         $v0, $s5, L_8004F98C
    if (ctx->r2 == ctx->r21) {
        // 0x8004F97C: sh          $zero, 0x4($s0)
        MEM_H(0X4, ctx->r16) = 0;
            goto L_8004F98C;
    }
    // 0x8004F97C: sh          $zero, 0x4($s0)
    MEM_H(0X4, ctx->r16) = 0;
    // 0x8004F980: jal         0x8003F0C8
    // 0x8004F984: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    func_8003F0C8(rdram, ctx);
        goto after_1;
    // 0x8004F984: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    after_1:
    // 0x8004F988: sh          $s5, 0xF4($s0)
    MEM_H(0XF4, ctx->r16) = ctx->r21;
L_8004F98C:
    // 0x8004F98C: lw          $a0, 0x4($s4)
    ctx->r4 = MEM_W(ctx->r20, 0X4);
    // 0x8004F990: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x8004F994: jal         0x8004D2B0
    // 0x8004F998: nop

    func_8004D2B0(rdram, ctx);
        goto after_2;
    // 0x8004F998: nop

    after_2:
    // 0x8004F99C: lw          $a1, 0x4($s4)
    ctx->r5 = MEM_W(ctx->r20, 0X4);
    // 0x8004F9A0: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x8004F9A4: jal         0x8004E140
    // 0x8004F9A8: addu        $a0, $s4, $zero
    ctx->r4 = ADD32(ctx->r20, 0);
    func_8004E140(rdram, ctx);
        goto after_3;
    // 0x8004F9A8: addu        $a0, $s4, $zero
    ctx->r4 = ADD32(ctx->r20, 0);
    after_3:
    // 0x8004F9AC: j           L_8004FB50
    // 0x8004F9B0: nop

        goto L_8004FB50;
    // 0x8004F9B0: nop

L_8004F9B4:
    // 0x8004F9B4: addu        $s3, $s7, $zero
    ctx->r19 = ADD32(ctx->r23, 0);
    // 0x8004F9B8: lui         $s1, 0x8014
    ctx->r17 = S32(0X8014 << 16);
    // 0x8004F9BC: addiu       $s1, $s1, -0x7D98
    ctx->r17 = ADD32(ctx->r17, -0X7D98);
L_8004F9C0:
    // 0x8004F9C0: addu        $s0, $s3, $s1
    ctx->r16 = ADD32(ctx->r19, ctx->r17);
    // 0x8004F9C4: lhu         $v0, 0x0($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X0);
    // 0x8004F9C8: andi        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 & 0X1;
    // 0x8004F9CC: beql        $v0, $zero, L_8004FA74
    if (ctx->r2 == 0) {
        // 0x8004F9D0: addiu       $s2, $s2, 0x1
        ctx->r18 = ADD32(ctx->r18, 0X1);
            goto L_8004FA74;
    }
    goto skip_0;
    // 0x8004F9D0: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    skip_0:
    // 0x8004F9D4: lwc1        $f0, 0xCC($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0XCC);
    // 0x8004F9D8: c.lt.s      $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f22.fl < ctx->f0.fl;
    // 0x8004F9DC: nop

    // 0x8004F9E0: bc1f        L_8004FA0C
    if (!c1cs) {
        // 0x8004F9E4: nop
    
            goto L_8004FA0C;
    }
    // 0x8004F9E4: nop

    // 0x8004F9E8: sub.s       $f0, $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f20.fl;
    // 0x8004F9EC: c.lt.s      $f0, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    c1cs = ctx->f0.fl < ctx->f22.fl;
    // 0x8004F9F0: nop

    // 0x8004F9F4: bc1f        L_8004FA18
    if (!c1cs) {
        // 0x8004F9F8: swc1        $f0, 0xCC($s0)
        MEM_W(0XCC, ctx->r16) = ctx->f0.u32l;
            goto L_8004FA18;
    }
    // 0x8004F9F8: swc1        $f0, 0xCC($s0)
    MEM_W(0XCC, ctx->r16) = ctx->f0.u32l;
    // 0x8004F9FC: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
    // 0x8004FA00: swc1        $f0, 0xC4($s0)
    MEM_W(0XC4, ctx->r16) = ctx->f0.u32l;
    // 0x8004FA04: j           L_8004FA18
    // 0x8004FA08: swc1        $f22, 0xCC($s0)
    MEM_W(0XCC, ctx->r16) = ctx->f22.u32l;
        goto L_8004FA18;
    // 0x8004FA08: swc1        $f22, 0xCC($s0)
    MEM_W(0XCC, ctx->r16) = ctx->f22.u32l;
L_8004FA0C:
    // 0x8004FA0C: lwc1        $f0, 0xC4($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0XC4);
    // 0x8004FA10: add.s       $f0, $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f20.fl;
    // 0x8004FA14: swc1        $f0, 0xC4($s0)
    MEM_W(0XC4, ctx->r16) = ctx->f0.u32l;
L_8004FA18:
    // 0x8004FA18: lhu         $v0, 0xF4($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0XF4);
    // 0x8004FA1C: beq         $v0, $s5, L_8004FA54
    if (ctx->r2 == ctx->r21) {
        // 0x8004FA20: nop
    
            goto L_8004FA54;
    }
    // 0x8004FA20: nop

    // 0x8004FA24: jal         0x80040218
    // 0x8004FA28: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    func_80040218(rdram, ctx);
        goto after_4;
    // 0x8004FA28: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    after_4:
    // 0x8004FA2C: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x8004FA30: bne         $v0, $s5, L_8004FA54
    if (ctx->r2 != ctx->r21) {
        // 0x8004FA34: nop
    
            goto L_8004FA54;
    }
    // 0x8004FA34: nop

    // 0x8004FA38: lhu         $v0, 0xF4($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0XF4);
    // 0x8004FA3C: sh          $zero, 0x2($s0)
    MEM_H(0X2, ctx->r16) = 0;
    // 0x8004FA40: beq         $v0, $s5, L_8004FA54
    if (ctx->r2 == ctx->r21) {
        // 0x8004FA44: sh          $zero, 0x4($s0)
        MEM_H(0X4, ctx->r16) = 0;
            goto L_8004FA54;
    }
    // 0x8004FA44: sh          $zero, 0x4($s0)
    MEM_H(0X4, ctx->r16) = 0;
    // 0x8004FA48: jal         0x8003F0C8
    // 0x8004FA4C: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    func_8003F0C8(rdram, ctx);
        goto after_5;
    // 0x8004FA4C: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    after_5:
    // 0x8004FA50: sh          $s5, 0xF4($s0)
    MEM_H(0XF4, ctx->r16) = ctx->r21;
L_8004FA54:
    // 0x8004FA54: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x8004FA58: jal         0x8004D2B0
    // 0x8004FA5C: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_8004D2B0(rdram, ctx);
        goto after_6;
    // 0x8004FA5C: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_6:
    // 0x8004FA60: addu        $a0, $s4, $zero
    ctx->r4 = ADD32(ctx->r20, 0);
    // 0x8004FA64: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x8004FA68: jal         0x8004E140
    // 0x8004FA6C: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    func_8004E140(rdram, ctx);
        goto after_7;
    // 0x8004FA6C: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    after_7:
    // 0x8004FA70: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
L_8004FA74:
    // 0x8004FA74: slti        $v0, $s2, 0x6
    ctx->r2 = SIGNED(ctx->r18) < 0X6 ? 1 : 0;
    // 0x8004FA78: bne         $v0, $zero, L_8004F9C0
    if (ctx->r2 != 0) {
        // 0x8004FA7C: addiu       $s1, $s1, 0xF8
        ctx->r17 = ADD32(ctx->r17, 0XF8);
            goto L_8004F9C0;
    }
    // 0x8004FA7C: addiu       $s1, $s1, 0xF8
    ctx->r17 = ADD32(ctx->r17, 0XF8);
    // 0x8004FA80: addu        $s2, $zero, $zero
    ctx->r18 = ADD32(0, 0);
    // 0x8004FA84: addu        $s6, $fp, $zero
    ctx->r22 = ADD32(ctx->r30, 0);
    // 0x8004FA88: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x8004FA8C: addiu       $s3, $v0, -0x76D0
    ctx->r19 = ADD32(ctx->r2, -0X76D0);
L_8004FA90:
    // 0x8004FA90: addu        $s0, $s6, $s3
    ctx->r16 = ADD32(ctx->r22, ctx->r19);
    // 0x8004FA94: lhu         $v0, 0x0($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X0);
    // 0x8004FA98: andi        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 & 0X1;
    // 0x8004FA9C: beql        $v0, $zero, L_8004FB44
    if (ctx->r2 == 0) {
        // 0x8004FAA0: addiu       $s2, $s2, 0x1
        ctx->r18 = ADD32(ctx->r18, 0X1);
            goto L_8004FB44;
    }
    goto skip_1;
    // 0x8004FAA0: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    skip_1:
    // 0x8004FAA4: lwc1        $f0, 0xCC($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0XCC);
    // 0x8004FAA8: c.lt.s      $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f22.fl < ctx->f0.fl;
    // 0x8004FAAC: nop

    // 0x8004FAB0: bc1f        L_8004FADC
    if (!c1cs) {
        // 0x8004FAB4: nop
    
            goto L_8004FADC;
    }
    // 0x8004FAB4: nop

    // 0x8004FAB8: sub.s       $f0, $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f20.fl;
    // 0x8004FABC: c.lt.s      $f0, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    c1cs = ctx->f0.fl < ctx->f22.fl;
    // 0x8004FAC0: nop

    // 0x8004FAC4: bc1f        L_8004FAE8
    if (!c1cs) {
        // 0x8004FAC8: swc1        $f0, 0xCC($s0)
        MEM_W(0XCC, ctx->r16) = ctx->f0.u32l;
            goto L_8004FAE8;
    }
    // 0x8004FAC8: swc1        $f0, 0xCC($s0)
    MEM_W(0XCC, ctx->r16) = ctx->f0.u32l;
    // 0x8004FACC: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
    // 0x8004FAD0: swc1        $f0, 0xC4($s0)
    MEM_W(0XC4, ctx->r16) = ctx->f0.u32l;
    // 0x8004FAD4: j           L_8004FAE8
    // 0x8004FAD8: swc1        $f22, 0xCC($s0)
    MEM_W(0XCC, ctx->r16) = ctx->f22.u32l;
        goto L_8004FAE8;
    // 0x8004FAD8: swc1        $f22, 0xCC($s0)
    MEM_W(0XCC, ctx->r16) = ctx->f22.u32l;
L_8004FADC:
    // 0x8004FADC: lwc1        $f0, 0xC4($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0XC4);
    // 0x8004FAE0: add.s       $f0, $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f20.fl;
    // 0x8004FAE4: swc1        $f0, 0xC4($s0)
    MEM_W(0XC4, ctx->r16) = ctx->f0.u32l;
L_8004FAE8:
    // 0x8004FAE8: lhu         $v0, 0xF4($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0XF4);
    // 0x8004FAEC: beq         $v0, $s5, L_8004FB24
    if (ctx->r2 == ctx->r21) {
        // 0x8004FAF0: nop
    
            goto L_8004FB24;
    }
    // 0x8004FAF0: nop

    // 0x8004FAF4: jal         0x80040218
    // 0x8004FAF8: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    func_80040218(rdram, ctx);
        goto after_8;
    // 0x8004FAF8: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    after_8:
    // 0x8004FAFC: andi        $s1, $v0, 0xFFFF
    ctx->r17 = ctx->r2 & 0XFFFF;
    // 0x8004FB00: bne         $s1, $s5, L_8004FB24
    if (ctx->r17 != ctx->r21) {
        // 0x8004FB04: nop
    
            goto L_8004FB24;
    }
    // 0x8004FB04: nop

    // 0x8004FB08: lhu         $v0, 0xF4($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0XF4);
    // 0x8004FB0C: sh          $zero, 0x2($s0)
    MEM_H(0X2, ctx->r16) = 0;
    // 0x8004FB10: beq         $v0, $s1, L_8004FB24
    if (ctx->r2 == ctx->r17) {
        // 0x8004FB14: sh          $zero, 0x4($s0)
        MEM_H(0X4, ctx->r16) = 0;
            goto L_8004FB24;
    }
    // 0x8004FB14: sh          $zero, 0x4($s0)
    MEM_H(0X4, ctx->r16) = 0;
    // 0x8004FB18: jal         0x8003F0C8
    // 0x8004FB1C: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    func_8003F0C8(rdram, ctx);
        goto after_9;
    // 0x8004FB1C: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    after_9:
    // 0x8004FB20: sh          $s1, 0xF4($s0)
    MEM_H(0XF4, ctx->r16) = ctx->r17;
L_8004FB24:
    // 0x8004FB24: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x8004FB28: jal         0x8004D2B0
    // 0x8004FB2C: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_8004D2B0(rdram, ctx);
        goto after_10;
    // 0x8004FB2C: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_10:
    // 0x8004FB30: addu        $a0, $s4, $zero
    ctx->r4 = ADD32(ctx->r20, 0);
    // 0x8004FB34: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x8004FB38: jal         0x8004E140
    // 0x8004FB3C: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    func_8004E140(rdram, ctx);
        goto after_11;
    // 0x8004FB3C: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    after_11:
    // 0x8004FB40: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
L_8004FB44:
    // 0x8004FB44: slti        $v0, $s2, 0x4
    ctx->r2 = SIGNED(ctx->r18) < 0X4 ? 1 : 0;
    // 0x8004FB48: bne         $v0, $zero, L_8004FA90
    if (ctx->r2 != 0) {
        // 0x8004FB4C: addiu       $s3, $s3, 0xF8
        ctx->r19 = ADD32(ctx->r19, 0XF8);
            goto L_8004FA90;
    }
    // 0x8004FB4C: addiu       $s3, $s3, 0xF8
    ctx->r19 = ADD32(ctx->r19, 0XF8);
L_8004FB50:
    // 0x8004FB50: lw          $a0, 0x4($s4)
    ctx->r4 = MEM_W(ctx->r20, 0X4);
    // 0x8004FB54: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x8004FB58: jal         0x8004F1CC
    // 0x8004FB5C: nop

    func_8004F1CC(rdram, ctx);
        goto after_12;
    // 0x8004FB5C: nop

    after_12:
    // 0x8004FB60: lw          $a0, 0x4($s4)
    ctx->r4 = MEM_W(ctx->r20, 0X4);
    // 0x8004FB64: lhu         $v0, 0x0($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X0);
    // 0x8004FB68: andi        $v0, $v0, 0x40
    ctx->r2 = ctx->r2 & 0X40;
    // 0x8004FB6C: beq         $v0, $zero, L_8004FB80
    if (ctx->r2 == 0) {
        // 0x8004FB70: addiu       $s4, $s4, 0x144
        ctx->r20 = ADD32(ctx->r20, 0X144);
            goto L_8004FB80;
    }
    // 0x8004FB70: addiu       $s4, $s4, 0x144
    ctx->r20 = ADD32(ctx->r20, 0X144);
    // 0x8004FB74: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x8004FB78: jal         0x8004DBD0
    // 0x8004FB7C: nop

    func_8004DBD0(rdram, ctx);
        goto after_13;
    // 0x8004FB7C: nop

    after_13:
L_8004FB80:
    // 0x8004FB80: addiu       $fp, $fp, 0x3E0
    ctx->r30 = ADD32(ctx->r30, 0X3E0);
    // 0x8004FB84: lw          $a3, 0x10($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X10);
    // 0x8004FB88: addiu       $s7, $s7, 0x5D0
    ctx->r23 = ADD32(ctx->r23, 0X5D0);
    // 0x8004FB8C: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x8004FB90: blez        $a3, L_8004F930
    if (SIGNED(ctx->r7) <= 0) {
        // 0x8004FB94: sw          $a3, 0x10($sp)
        MEM_W(0X10, ctx->r29) = ctx->r7;
            goto L_8004F930;
    }
    // 0x8004FB94: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    // 0x8004FB98: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x8004FB9C: lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X38);
    // 0x8004FBA0: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x8004FBA4: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x8004FBA8: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x8004FBAC: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x8004FBB0: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x8004FBB4: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8004FBB8: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8004FBBC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8004FBC0: ldc1        $f22, 0x48($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X48);
    // 0x8004FBC4: ldc1        $f20, 0x40($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X40);
    // 0x8004FBC8: jr          $ra
    // 0x8004FBCC: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x8004FBCC: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}
RECOMP_FUNC void func_8004FBD0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8004FBD0: addiu       $sp, $sp, -0x98
    ctx->r29 = ADD32(ctx->r29, -0X98);
    // 0x8004FBD4: sdc1        $f24, 0x88($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X88, ctx->r29);
    // 0x8004FBD8: mtc1        $a1, $f24
    ctx->f24.u32l = ctx->r5;
    // 0x8004FBDC: sdc1        $f20, 0x78($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X78, ctx->r29);
    // 0x8004FBE0: mtc1        $a2, $f20
    ctx->f20.u32l = ctx->r6;
    // 0x8004FBE4: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x8004FBE8: sdc1        $f26, 0x90($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X90, ctx->r29);
    // 0x8004FBEC: lwc1        $f26, 0xA8($sp)
    ctx->f26.u32l = MEM_W(ctx->r29, 0XA8);
    // 0x8004FBF0: lbu         $v0, -0x76DB($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X76DB);
    // 0x8004FBF4: sdc1        $f22, 0x80($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X80, ctx->r29);
    // 0x8004FBF8: lwc1        $f22, 0xAC($sp)
    ctx->f22.u32l = MEM_W(ctx->r29, 0XAC);
    // 0x8004FBFC: sw          $s1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r17;
    // 0x8004FC00: addu        $s1, $a0, $zero
    ctx->r17 = ADD32(ctx->r4, 0);
    // 0x8004FC04: sw          $ra, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r31;
    // 0x8004FC08: sw          $fp, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r30;
    // 0x8004FC0C: sw          $s7, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r23;
    // 0x8004FC10: sw          $s6, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r22;
    // 0x8004FC14: sw          $s5, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r21;
    // 0x8004FC18: sw          $s4, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r20;
    // 0x8004FC1C: sw          $s3, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r19;
    // 0x8004FC20: sw          $s2, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r18;
    // 0x8004FC24: sw          $s0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r16;
    // 0x8004FC28: bne         $v0, $zero, L_8004FF68
    if (ctx->r2 != 0) {
        // 0x8004FC2C: sw          $a3, 0xA4($sp)
        MEM_W(0XA4, ctx->r29) = ctx->r7;
            goto L_8004FF68;
    }
    // 0x8004FC2C: sw          $a3, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->r7;
    // 0x8004FC30: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x8004FC34: lbu         $v0, -0x76DA($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X76DA);
    // 0x8004FC38: bne         $v0, $zero, L_8004FF68
    if (ctx->r2 != 0) {
        // 0x8004FC3C: lui         $v0, 0x8013
        ctx->r2 = S32(0X8013 << 16);
            goto L_8004FF68;
    }
    // 0x8004FC3C: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8004FC40: lbu         $v0, 0x7CF4($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7CF4);
    // 0x8004FC44: bne         $v0, $zero, L_8004FF68
    if (ctx->r2 != 0) {
        // 0x8004FC48: addu        $s3, $zero, $zero
        ctx->r19 = ADD32(0, 0);
            goto L_8004FF68;
    }
    // 0x8004FC48: addu        $s3, $zero, $zero
    ctx->r19 = ADD32(0, 0);
    // 0x8004FC4C: sll         $v1, $s1, 1
    ctx->r3 = S32(ctx->r17 << 1);
    // 0x8004FC50: addu        $v1, $v1, $s1
    ctx->r3 = ADD32(ctx->r3, ctx->r17);
    // 0x8004FC54: sll         $v0, $v1, 5
    ctx->r2 = S32(ctx->r3 << 5);
    // 0x8004FC58: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x8004FC5C: sll         $v0, $v0, 4
    ctx->r2 = S32(ctx->r2 << 4);
    // 0x8004FC60: sw          $v0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r2;
    // 0x8004FC64: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8004FC68: addiu       $v0, $v0, 0xB40
    ctx->r2 = ADD32(ctx->r2, 0XB40);
    // 0x8004FC6C: sll         $a0, $s1, 2
    ctx->r4 = S32(ctx->r17 << 2);
    // 0x8004FC70: addu        $v0, $a0, $v0
    ctx->r2 = ADD32(ctx->r4, ctx->r2);
    // 0x8004FC74: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    // 0x8004FC78: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8004FC7C: addiu       $s6, $v0, 0xB88
    ctx->r22 = ADD32(ctx->r2, 0XB88);
    // 0x8004FC80: sll         $v1, $v1, 1
    ctx->r3 = S32(ctx->r3 << 1);
    // 0x8004FC84: addu        $v1, $v1, $s6
    ctx->r3 = ADD32(ctx->r3, ctx->r22);
    // 0x8004FC88: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x8004FC8C: addiu       $s5, $v0, -0x41E8
    ctx->r21 = ADD32(ctx->r2, -0X41E8);
    // 0x8004FC90: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8004FC94: addiu       $s7, $v0, 0x7DB8
    ctx->r23 = ADD32(ctx->r2, 0X7DB8);
    // 0x8004FC98: addu        $s4, $a0, $s1
    ctx->r20 = ADD32(ctx->r4, ctx->r17);
    // 0x8004FC9C: sll         $v0, $s4, 4
    ctx->r2 = S32(ctx->r20 << 4);
    // 0x8004FCA0: addu        $v0, $v0, $s1
    ctx->r2 = ADD32(ctx->r2, ctx->r17);
    // 0x8004FCA4: sll         $fp, $v0, 2
    ctx->r30 = S32(ctx->r2 << 2);
    // 0x8004FCA8: addu        $s2, $s3, $zero
    ctx->r18 = ADD32(ctx->r19, 0);
    // 0x8004FCAC: sw          $v1, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r3;
L_8004FCB0:
    // 0x8004FCB0: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x8004FCB4: addiu       $v0, $v0, -0x7D98
    ctx->r2 = ADD32(ctx->r2, -0X7D98);
    // 0x8004FCB8: lw          $t0, 0x40($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X40);
    // 0x8004FCBC: addu        $v0, $s2, $v0
    ctx->r2 = ADD32(ctx->r18, ctx->r2);
    // 0x8004FCC0: addu        $s0, $t0, $v0
    ctx->r16 = ADD32(ctx->r8, ctx->r2);
    // 0x8004FCC4: lhu         $v0, 0x0($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X0);
    // 0x8004FCC8: andi        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 & 0X1;
    // 0x8004FCCC: beql        $v0, $zero, L_8004FF5C
    if (ctx->r2 == 0) {
        // 0x8004FCD0: addiu       $s3, $s3, 0x1
        ctx->r19 = ADD32(ctx->r19, 0X1);
            goto L_8004FF5C;
    }
    goto skip_0;
    // 0x8004FCD0: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    skip_0:
    // 0x8004FCD4: lhu         $a0, 0x2($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X2);
    // 0x8004FCD8: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x8004FCDC: bnel        $a0, $v0, L_8004FF5C
    if (ctx->r4 != ctx->r2) {
        // 0x8004FCE0: addiu       $s3, $s3, 0x1
        ctx->r19 = ADD32(ctx->r19, 0X1);
            goto L_8004FF5C;
    }
    goto skip_1;
    // 0x8004FCE0: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    skip_1:
    // 0x8004FCE4: lw          $v0, 0x74($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X74);
    // 0x8004FCE8: lw          $t0, 0xA4($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XA4);
    // 0x8004FCEC: bnel        $v0, $t0, L_8004FF5C
    if (ctx->r2 != ctx->r8) {
        // 0x8004FCF0: addiu       $s3, $s3, 0x1
        ctx->r19 = ADD32(ctx->r19, 0X1);
            goto L_8004FF5C;
    }
    goto skip_2;
    // 0x8004FCF0: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    skip_2:
    // 0x8004FCF4: lhu         $v1, 0x4($s0)
    ctx->r3 = MEM_HU(ctx->r16, 0X4);
    // 0x8004FCF8: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x8004FCFC: beq         $v1, $v0, L_8004FD14
    if (ctx->r3 == ctx->r2) {
        // 0x8004FD00: nop
    
            goto L_8004FD14;
    }
    // 0x8004FD00: nop

    // 0x8004FD04: beql        $v1, $a0, L_8004FD38
    if (ctx->r3 == ctx->r4) {
        // 0x8004FD08: swc1        $f20, 0x94($s0)
        MEM_W(0X94, ctx->r16) = ctx->f20.u32l;
            goto L_8004FD38;
    }
    goto skip_3;
    // 0x8004FD08: swc1        $f20, 0x94($s0)
    MEM_W(0X94, ctx->r16) = ctx->f20.u32l;
    skip_3:
    // 0x8004FD0C: j           L_8004FD28
    // 0x8004FD10: nop

        goto L_8004FD28;
    // 0x8004FD10: nop

L_8004FD14:
    // 0x8004FD14: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8004FD18: lwc1        $f0, -0x5624($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X5624);
    // 0x8004FD1C: div.s       $f0, $f20, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = DIV_S(ctx->f20.fl, ctx->f0.fl);
    // 0x8004FD20: j           L_8004FD38
    // 0x8004FD24: swc1        $f0, 0x94($s0)
    MEM_W(0X94, ctx->r16) = ctx->f0.u32l;
        goto L_8004FD38;
    // 0x8004FD24: swc1        $f0, 0x94($s0)
    MEM_W(0X94, ctx->r16) = ctx->f0.u32l;
L_8004FD28:
    // 0x8004FD28: lwc1        $f0, 0xA0($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0XA0);
    // 0x8004FD2C: mul.s       $f0, $f26, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = MUL_S(ctx->f26.fl, ctx->f0.fl);
    // 0x8004FD30: swc1        $f24, 0x94($s0)
    MEM_W(0X94, ctx->r16) = ctx->f24.u32l;
    // 0x8004FD34: swc1        $f0, 0x9C($s0)
    MEM_W(0X9C, ctx->r16) = ctx->f0.u32l;
L_8004FD38:
    // 0x8004FD38: lw          $t0, 0x44($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X44);
    // 0x8004FD3C: lw          $v0, 0xC($t0)
    ctx->r2 = MEM_W(ctx->r8, 0XC);
    // 0x8004FD40: lui         $v1, 0x100
    ctx->r3 = S32(0X100 << 16);
    // 0x8004FD44: and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // 0x8004FD48: beq         $v0, $zero, L_8004FDC8
    if (ctx->r2 == 0) {
        // 0x8004FD4C: sll         $v0, $s1, 3
        ctx->r2 = S32(ctx->r17 << 3);
            goto L_8004FDC8;
    }
    // 0x8004FD4C: sll         $v0, $s1, 3
    ctx->r2 = S32(ctx->r17 << 3);
    // 0x8004FD50: addu        $v0, $v0, $s1
    ctx->r2 = ADD32(ctx->r2, ctx->r17);
    // 0x8004FD54: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8004FD58: addu        $v0, $v0, $s5
    ctx->r2 = ADD32(ctx->r2, ctx->r21);
    // 0x8004FD5C: lw          $t0, 0x48($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X48);
    // 0x8004FD60: lhu         $v0, 0x20($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X20);
    // 0x8004FD64: lhu         $v1, 0x0($t0)
    ctx->r3 = MEM_HU(ctx->r8, 0X0);
    // 0x8004FD68: and         $v1, $v1, $v0
    ctx->r3 = ctx->r3 & ctx->r2;
    // 0x8004FD6C: beq         $v1, $zero, L_8004FDC8
    if (ctx->r3 == 0) {
        // 0x8004FD70: sll         $v0, $s4, 2
        ctx->r2 = S32(ctx->r20 << 2);
            goto L_8004FDC8;
    }
    // 0x8004FD70: sll         $v0, $s4, 2
    ctx->r2 = S32(ctx->r20 << 2);
    // 0x8004FD74: addu        $v0, $v0, $s1
    ctx->r2 = ADD32(ctx->r2, ctx->r17);
    // 0x8004FD78: sll         $v0, $v0, 5
    ctx->r2 = S32(ctx->r2 << 5);
    // 0x8004FD7C: addu        $v0, $v0, $s7
    ctx->r2 = ADD32(ctx->r2, ctx->r23);
    // 0x8004FD80: lhu         $v0, 0x184($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X184);
    // 0x8004FD84: andi        $v0, $v0, 0x2
    ctx->r2 = ctx->r2 & 0X2;
    // 0x8004FD88: bne         $v0, $zero, L_8004FDC8
    if (ctx->r2 != 0) {
        // 0x8004FD8C: lui         $v0, 0x8014
        ctx->r2 = S32(0X8014 << 16);
            goto L_8004FDC8;
    }
    // 0x8004FD8C: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x8004FD90: addiu       $v0, $v0, -0x72E8
    ctx->r2 = ADD32(ctx->r2, -0X72E8);
    // 0x8004FD94: addu        $v0, $fp, $v0
    ctx->r2 = ADD32(ctx->r30, ctx->r2);
    // 0x8004FD98: lw          $v0, 0x4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X4);
    // 0x8004FD9C: lhu         $v0, 0x0($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X0);
    // 0x8004FDA0: andi        $v0, $v0, 0x10
    ctx->r2 = ctx->r2 & 0X10;
    // 0x8004FDA4: bne         $v0, $zero, L_8004FDC8
    if (ctx->r2 != 0) {
        // 0x8004FDA8: nop
    
            goto L_8004FDC8;
    }
    // 0x8004FDA8: nop

    // 0x8004FDAC: lwc1        $f0, 0xA8($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0XA8);
    // 0x8004FDB0: add.s       $f0, $f0, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f22.fl;
    // 0x8004FDB4: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8004FDB8: lwc1        $f2, -0x5620($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X5620);
    // 0x8004FDBC: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x8004FDC0: j           L_8004FDDC
    // 0x8004FDC4: swc1        $f0, 0xA8($s0)
    MEM_W(0XA8, ctx->r16) = ctx->f0.u32l;
        goto L_8004FDDC;
    // 0x8004FDC4: swc1        $f0, 0xA8($s0)
    MEM_W(0XA8, ctx->r16) = ctx->f0.u32l;
L_8004FDC8:
    // 0x8004FDC8: lwc1        $f0, 0xA8($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0XA8);
    // 0x8004FDCC: sub.s       $f0, $f0, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f22.fl;
    // 0x8004FDD0: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x8004FDD4: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x8004FDD8: swc1        $f0, 0xA8($s0)
    MEM_W(0XA8, ctx->r16) = ctx->f0.u32l;
L_8004FDDC:
    // 0x8004FDDC: bc1tl       L_8004FDE4
    if (c1cs) {
        // 0x8004FDE0: swc1        $f2, 0xA8($s0)
        MEM_W(0XA8, ctx->r16) = ctx->f2.u32l;
            goto L_8004FDE4;
    }
    goto skip_4;
    // 0x8004FDE0: swc1        $f2, 0xA8($s0)
    MEM_W(0XA8, ctx->r16) = ctx->f2.u32l;
    skip_4:
L_8004FDE4:
    // 0x8004FDE4: lw          $a0, 0xC($s0)
    ctx->r4 = MEM_W(ctx->r16, 0XC);
    // 0x8004FDE8: sll         $v0, $a0, 2
    ctx->r2 = S32(ctx->r4 << 2);
    // 0x8004FDEC: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x8004FDF0: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8004FDF4: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x8004FDF8: sll         $v0, $v0, 5
    ctx->r2 = S32(ctx->r2 << 5);
    // 0x8004FDFC: addu        $v0, $v0, $s7
    ctx->r2 = ADD32(ctx->r2, ctx->r23);
    // 0x8004FE00: lhu         $v1, 0xB8($v0)
    ctx->r3 = MEM_HU(ctx->r2, 0XB8);
    // 0x8004FE04: addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
    // 0x8004FE08: bnel        $v1, $v0, L_8004FEA8
    if (ctx->r3 != ctx->r2) {
        // 0x8004FE0C: sw          $zero, 0x10($sp)
        MEM_W(0X10, ctx->r29) = 0;
            goto L_8004FEA8;
    }
    goto skip_5;
    // 0x8004FE0C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    skip_5:
    // 0x8004FE10: lw          $v0, 0x8($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X8);
    // 0x8004FE14: slti        $v0, $v0, 0x2
    ctx->r2 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // 0x8004FE18: beq         $v0, $zero, L_8004FEA4
    if (ctx->r2 == 0) {
        // 0x8004FE1C: sll         $v1, $a0, 1
        ctx->r3 = S32(ctx->r4 << 1);
            goto L_8004FEA4;
    }
    // 0x8004FE1C: sll         $v1, $a0, 1
    ctx->r3 = S32(ctx->r4 << 1);
    // 0x8004FE20: addu        $v1, $v1, $a0
    ctx->r3 = ADD32(ctx->r3, ctx->r4);
    // 0x8004FE24: sll         $v1, $v1, 1
    ctx->r3 = S32(ctx->r3 << 1);
    // 0x8004FE28: addu        $v1, $v1, $s6
    ctx->r3 = ADD32(ctx->r3, ctx->r22);
    // 0x8004FE2C: sll         $v0, $a0, 3
    ctx->r2 = S32(ctx->r4 << 3);
    // 0x8004FE30: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x8004FE34: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8004FE38: addu        $v0, $v0, $s5
    ctx->r2 = ADD32(ctx->r2, ctx->r21);
    // 0x8004FE3C: lhu         $v1, 0x0($v1)
    ctx->r3 = MEM_HU(ctx->r3, 0X0);
    // 0x8004FE40: lhu         $v0, 0x20($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X20);
    // 0x8004FE44: and         $v1, $v1, $v0
    ctx->r3 = ctx->r3 & ctx->r2;
    // 0x8004FE48: beq         $v1, $zero, L_8004FEA4
    if (ctx->r3 == 0) {
        // 0x8004FE4C: sll         $v1, $a0, 1
        ctx->r3 = S32(ctx->r4 << 1);
            goto L_8004FEA4;
    }
    // 0x8004FE4C: sll         $v1, $a0, 1
    ctx->r3 = S32(ctx->r4 << 1);
    // 0x8004FE50: addu        $v1, $v1, $a0
    ctx->r3 = ADD32(ctx->r3, ctx->r4);
    // 0x8004FE54: sll         $v1, $v1, 1
    ctx->r3 = S32(ctx->r3 << 1);
    // 0x8004FE58: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8004FE5C: lwc1        $f0, -0x561C($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X561C);
    // 0x8004FE60: addu        $v1, $v1, $s6
    ctx->r3 = ADD32(ctx->r3, ctx->r22);
    // 0x8004FE64: mul.s       $f0, $f20, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = MUL_S(ctx->f20.fl, ctx->f0.fl);
    // 0x8004FE68: sll         $v0, $a0, 3
    ctx->r2 = S32(ctx->r4 << 3);
    // 0x8004FE6C: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x8004FE70: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8004FE74: addu        $a0, $v0, $s5
    ctx->r4 = ADD32(ctx->r2, ctx->r21);
    // 0x8004FE78: swc1        $f0, 0x94($s0)
    MEM_W(0X94, ctx->r16) = ctx->f0.u32l;
    // 0x8004FE7C: lhu         $v1, 0x0($v1)
    ctx->r3 = MEM_HU(ctx->r3, 0X0);
    // 0x8004FE80: lhu         $v0, 0x14($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X14);
    // 0x8004FE84: and         $v0, $v1, $v0
    ctx->r2 = ctx->r3 & ctx->r2;
    // 0x8004FE88: bnel        $v0, $zero, L_8004FEA4
    if (ctx->r2 != 0) {
        // 0x8004FE8C: swc1        $f20, 0x94($s0)
        MEM_W(0X94, ctx->r16) = ctx->f20.u32l;
            goto L_8004FEA4;
    }
    goto skip_6;
    // 0x8004FE8C: swc1        $f20, 0x94($s0)
    MEM_W(0X94, ctx->r16) = ctx->f20.u32l;
    skip_6:
    // 0x8004FE90: lhu         $v0, 0x16($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X16);
    // 0x8004FE94: and         $v0, $v1, $v0
    ctx->r2 = ctx->r3 & ctx->r2;
    // 0x8004FE98: beql        $v0, $zero, L_8004FEA8
    if (ctx->r2 == 0) {
        // 0x8004FE9C: sw          $zero, 0x10($sp)
        MEM_W(0X10, ctx->r29) = 0;
            goto L_8004FEA8;
    }
    goto skip_7;
    // 0x8004FE9C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    skip_7:
    // 0x8004FEA0: swc1        $f20, 0x94($s0)
    MEM_W(0X94, ctx->r16) = ctx->f20.u32l;
L_8004FEA4:
    // 0x8004FEA4: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
L_8004FEA8:
    // 0x8004FEA8: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x8004FEAC: lwc1        $f0, 0x6C($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X6C);
    // 0x8004FEB0: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    // 0x8004FEB4: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    // 0x8004FEB8: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x8004FEBC: lwc1        $f0, 0x8C($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X8C);
    // 0x8004FEC0: lwc1        $f2, 0x10($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X10);
    // 0x8004FEC4: swc1        $f0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f0.u32l;
    // 0x8004FEC8: lwc1        $f0, 0x64($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X64);
    // 0x8004FECC: addiu       $v0, $sp, 0x10
    ctx->r2 = ADD32(ctx->r29, 0X10);
    // 0x8004FED0: sub.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl - ctx->f0.fl;
    // 0x8004FED4: lwc1        $f4, 0xA8($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XA8);
    // 0x8004FED8: addiu       $a1, $s0, 0x64
    ctx->r5 = ADD32(ctx->r16, 0X64);
    // 0x8004FEDC: swc1        $f2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f2.u32l;
    // 0x8004FEE0: lwc1        $f2, 0x4($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X4);
    // 0x8004FEE4: lwc1        $f0, 0x4($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0X4);
    // 0x8004FEE8: sub.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl - ctx->f0.fl;
    // 0x8004FEEC: swc1        $f2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f2.u32l;
    // 0x8004FEF0: lwc1        $f0, 0x8($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X8);
    // 0x8004FEF4: lwc1        $f2, 0x8($a1)
    ctx->f2.u32l = MEM_W(ctx->r5, 0X8);
    // 0x8004FEF8: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    // 0x8004FEFC: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x8004FF00: mfc1        $a2, $f4
    ctx->r6 = (int32_t)ctx->f4.u32l;
    // 0x8004FF04: addiu       $a3, $sp, 0x30
    ctx->r7 = ADD32(ctx->r29, 0X30);
    // 0x8004FF08: jal         0x800AA3E0
    // 0x8004FF0C: swc1        $f0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f0.u32l;
    func_800AA3E0(rdram, ctx);
        goto after_0;
    // 0x8004FF0C: swc1        $f0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f0.u32l;
    after_0:
    // 0x8004FF10: lwc1        $f2, 0x20($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X20);
    // 0x8004FF14: lwc1        $f0, 0x84($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X84);
    // 0x8004FF18: sub.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl - ctx->f0.fl;
    // 0x8004FF1C: lwc1        $f4, 0xA8($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XA8);
    // 0x8004FF20: addiu       $a1, $s0, 0x84
    ctx->r5 = ADD32(ctx->r16, 0X84);
    // 0x8004FF24: swc1        $f2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f2.u32l;
    // 0x8004FF28: lwc1        $f2, 0x24($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X24);
    // 0x8004FF2C: lwc1        $f0, 0x4($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0X4);
    // 0x8004FF30: sub.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl - ctx->f0.fl;
    // 0x8004FF34: lwc1        $f0, 0x28($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X28);
    // 0x8004FF38: swc1        $f2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f2.u32l;
    // 0x8004FF3C: lwc1        $f2, 0x8($a1)
    ctx->f2.u32l = MEM_W(ctx->r5, 0X8);
    // 0x8004FF40: addiu       $a0, $s0, 0x78
    ctx->r4 = ADD32(ctx->r16, 0X78);
    // 0x8004FF44: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x8004FF48: mfc1        $a2, $f4
    ctx->r6 = (int32_t)ctx->f4.u32l;
    // 0x8004FF4C: addiu       $a3, $sp, 0x30
    ctx->r7 = ADD32(ctx->r29, 0X30);
    // 0x8004FF50: jal         0x800AA3E0
    // 0x8004FF54: swc1        $f0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f0.u32l;
    func_800AA3E0(rdram, ctx);
        goto after_1;
    // 0x8004FF54: swc1        $f0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f0.u32l;
    after_1:
    // 0x8004FF58: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
L_8004FF5C:
    // 0x8004FF5C: slti        $v0, $s3, 0x6
    ctx->r2 = SIGNED(ctx->r19) < 0X6 ? 1 : 0;
    // 0x8004FF60: bne         $v0, $zero, L_8004FCB0
    if (ctx->r2 != 0) {
        // 0x8004FF64: addiu       $s2, $s2, 0xF8
        ctx->r18 = ADD32(ctx->r18, 0XF8);
            goto L_8004FCB0;
    }
    // 0x8004FF64: addiu       $s2, $s2, 0xF8
    ctx->r18 = ADD32(ctx->r18, 0XF8);
L_8004FF68:
    // 0x8004FF68: lw          $ra, 0x74($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X74);
    // 0x8004FF6C: lw          $fp, 0x70($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X70);
    // 0x8004FF70: lw          $s7, 0x6C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X6C);
    // 0x8004FF74: lw          $s6, 0x68($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X68);
    // 0x8004FF78: lw          $s5, 0x64($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X64);
    // 0x8004FF7C: lw          $s4, 0x60($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X60);
    // 0x8004FF80: lw          $s3, 0x5C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X5C);
    // 0x8004FF84: lw          $s2, 0x58($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X58);
    // 0x8004FF88: lw          $s1, 0x54($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X54);
    // 0x8004FF8C: lw          $s0, 0x50($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X50);
    // 0x8004FF90: ldc1        $f26, 0x90($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X90);
    // 0x8004FF94: ldc1        $f24, 0x88($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X88);
    // 0x8004FF98: ldc1        $f22, 0x80($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X80);
    // 0x8004FF9C: ldc1        $f20, 0x78($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X78);
    // 0x8004FFA0: jr          $ra
    // 0x8004FFA4: addiu       $sp, $sp, 0x98
    ctx->r29 = ADD32(ctx->r29, 0X98);
    return;
    // 0x8004FFA4: addiu       $sp, $sp, 0x98
    ctx->r29 = ADD32(ctx->r29, 0X98);
;}
RECOMP_FUNC void func_8004FFA8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8004FFA8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8004FFAC: lui         $v1, 0x8014
    ctx->r3 = S32(0X8014 << 16);
    // 0x8004FFB0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8004FFB4: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x8004FFB8: addu        $s1, $zero, $zero
    ctx->r17 = ADD32(0, 0);
    // 0x8004FFBC: sw          $v0, -0x7DA0($v1)
    MEM_W(-0X7DA0, ctx->r3) = ctx->r2;
    // 0x8004FFC0: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x8004FFC4: sw          $s3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r19;
    // 0x8004FFC8: addiu       $s3, $v0, -0x2120
    ctx->r19 = ADD32(ctx->r2, -0X2120);
    // 0x8004FFCC: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x8004FFD0: sw          $s4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r20;
    // 0x8004FFD4: addiu       $s4, $v0, -0x7D98
    ctx->r20 = ADD32(ctx->r2, -0X7D98);
    // 0x8004FFD8: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x8004FFDC: sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // 0x8004FFE0: addiu       $s2, $v0, -0x72E8
    ctx->r18 = ADD32(ctx->r2, -0X72E8);
    // 0x8004FFE4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8004FFE8: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
L_8004FFEC:
    // 0x8004FFEC: jal         0x80050AC8
    // 0x8004FFF0: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    func_80050AC8(rdram, ctx);
        goto after_0;
    // 0x8004FFF0: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    after_0:
    // 0x8004FFF4: addiu       $s0, $s2, 0x8
    ctx->r16 = ADD32(ctx->r18, 0X8);
    // 0x8004FFF8: addiu       $a0, $s2, 0x34
    ctx->r4 = ADD32(ctx->r18, 0X34);
    // 0x8004FFFC: sb          $zero, 0x0($s2)
    MEM_B(0X0, ctx->r18) = 0;
    // 0x80050000: sw          $s4, 0x4($s2)
    MEM_W(0X4, ctx->r18) = ctx->r20;
    // 0x80050004: sw          $zero, 0x8($s2)
    MEM_W(0X8, ctx->r18) = 0;
    // 0x80050008: sw          $zero, 0x4($s0)
    MEM_W(0X4, ctx->r16) = 0;
    // 0x8005000C: sw          $zero, 0xC($s0)
    MEM_W(0XC, ctx->r16) = 0;
    // 0x80050010: sw          $zero, 0x8($s0)
    MEM_W(0X8, ctx->r16) = 0;
    // 0x80050014: lw          $v0, 0x0($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X0);
    // 0x80050018: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8005001C: lwc1        $f0, -0x5618($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X5618);
    // 0x80050020: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80050024: lwc1        $f2, -0x5614($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X5614);
    // 0x80050028: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8005002C: lwc1        $f4, -0x5610($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X5610);
    // 0x80050030: addiu       $s4, $s4, 0x5D0
    ctx->r20 = ADD32(ctx->r20, 0X5D0);
    // 0x80050034: sw          $v0, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->r2;
    // 0x80050038: lw          $v0, 0x4($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X4);
    // 0x8005003C: addiu       $s2, $s2, 0x144
    ctx->r18 = ADD32(ctx->r18, 0X144);
    // 0x80050040: sw          $v0, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->r2;
    // 0x80050044: lw          $v0, 0x8($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X8);
    // 0x80050048: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x8005004C: sw          $v0, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->r2;
    // 0x80050050: lw          $v0, 0xC($s3)
    ctx->r2 = MEM_W(ctx->r19, 0XC);
    // 0x80050054: addiu       $s3, $s3, 0x10
    ctx->r19 = ADD32(ctx->r19, 0X10);
    // 0x80050058: swc1        $f0, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->f0.u32l;
    // 0x8005005C: swc1        $f2, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f2.u32l;
    // 0x80050060: swc1        $f4, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->f4.u32l;
    // 0x80050064: jal         0x8001CA50
    // 0x80050068: sw          $v0, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->r2;
    func_8001CA50(rdram, ctx);
        goto after_1;
    // 0x80050068: sw          $v0, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->r2;
    after_1:
    // 0x8005006C: blez        $s1, L_8004FFEC
    if (SIGNED(ctx->r17) <= 0) {
        // 0x80050070: lui         $v0, 0x8014
        ctx->r2 = S32(0X8014 << 16);
            goto L_8004FFEC;
    }
    // 0x80050070: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x80050074: lui         $a1, 0x8014
    ctx->r5 = S32(0X8014 << 16);
    // 0x80050078: addiu       $a0, $a1, -0x72E8
    ctx->r4 = ADD32(ctx->r5, -0X72E8);
    // 0x8005007C: sw          $a0, -0x776C($v0)
    MEM_W(-0X776C, ctx->r2) = ctx->r4;
    // 0x80050080: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x80050084: lw          $v1, -0x7DA0($v0)
    ctx->r3 = MEM_W(ctx->r2, -0X7DA0);
    // 0x80050088: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8005008C: bne         $v1, $v0, L_800500D4
    if (ctx->r3 != ctx->r2) {
        // 0x80050090: addu        $s1, $zero, $zero
        ctx->r17 = ADD32(0, 0);
            goto L_800500D4;
    }
    // 0x80050090: addu        $s1, $zero, $zero
    ctx->r17 = ADD32(0, 0);
    // 0x80050094: addiu       $s0, $a0, 0x8
    ctx->r16 = ADD32(ctx->r4, 0X8);
    // 0x80050098: jal         0x8006B3D0
    // 0x8005009C: sb          $v1, -0x72E8($a1)
    MEM_B(-0X72E8, ctx->r5) = ctx->r3;
    func_8006B3D0(rdram, ctx);
        goto after_2;
    // 0x8005009C: sb          $v1, -0x72E8($a1)
    MEM_B(-0X72E8, ctx->r5) = ctx->r3;
    after_2:
    // 0x800500A0: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x800500A4: jal         0x8006B3E0
    // 0x800500A8: sw          $v0, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->r2;
    func_8006B3E0(rdram, ctx);
        goto after_3;
    // 0x800500A8: sw          $v0, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->r2;
    after_3:
    // 0x800500AC: lw          $v1, 0x10($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X10);
    // 0x800500B0: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x800500B4: sw          $v0, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->r2;
    // 0x800500B8: srl         $v0, $v0, 1
    ctx->r2 = S32(U32(ctx->r2) >> 1);
    // 0x800500BC: sw          $v0, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->r2;
    // 0x800500C0: srl         $v0, $v1, 31
    ctx->r2 = S32(U32(ctx->r3) >> 31);
    // 0x800500C4: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x800500C8: sra         $v1, $v1, 1
    ctx->r3 = S32(SIGNED(ctx->r3) >> 1);
    // 0x800500CC: j           L_800500EC
    // 0x800500D0: sw          $v1, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->r3;
        goto L_800500EC;
    // 0x800500D0: sw          $v1, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->r3;
L_800500D4:
    // 0x800500D4: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x800500D8: addu        $v0, $a0, $zero
    ctx->r2 = ADD32(ctx->r4, 0);
L_800500DC:
    // 0x800500DC: sb          $v1, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r3;
    // 0x800500E0: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x800500E4: blez        $s1, L_800500DC
    if (SIGNED(ctx->r17) <= 0) {
        // 0x800500E8: addiu       $v0, $v0, 0x144
        ctx->r2 = ADD32(ctx->r2, 0X144);
            goto L_800500DC;
    }
    // 0x800500E8: addiu       $v0, $v0, 0x144
    ctx->r2 = ADD32(ctx->r2, 0X144);
L_800500EC:
    // 0x800500EC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800500F0: lw          $s4, 0x20($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X20);
    // 0x800500F4: lw          $s3, 0x1C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X1C);
    // 0x800500F8: lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X18);
    // 0x800500FC: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x80050100: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x80050104: jr          $ra
    // 0x80050108: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80050108: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_8005010C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005010C: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80050110: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x80050114: addu        $s6, $zero, $zero
    ctx->r22 = ADD32(0, 0);
    // 0x80050118: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x8005011C: lui         $fp, 0x8011
    ctx->r30 = S32(0X8011 << 16);
    // 0x80050120: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x80050124: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80050128: addiu       $s2, $v0, -0x72E8
    ctx->r18 = ADD32(ctx->r2, -0X72E8);
    // 0x8005012C: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x80050130: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80050134: addiu       $s1, $v0, -0x76D0
    ctx->r17 = ADD32(ctx->r2, -0X76D0);
    // 0x80050138: lui         $a3, 0x8013
    ctx->r7 = S32(0X8013 << 16);
    // 0x8005013C: addiu       $a3, $a3, 0x7DBC
    ctx->r7 = ADD32(ctx->r7, 0X7DBC);
    // 0x80050140: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x80050144: addiu       $s3, $a3, 0x250
    ctx->r19 = ADD32(ctx->r7, 0X250);
    // 0x80050148: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x8005014C: addu        $s4, $s6, $zero
    ctx->r20 = ADD32(ctx->r22, 0);
    // 0x80050150: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x80050154: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x80050158: addiu       $s5, $v0, -0x41E8
    ctx->r21 = ADD32(ctx->r2, -0X41E8);
    // 0x8005015C: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x80050160: lui         $s7, 0x8013
    ctx->r23 = S32(0X8013 << 16);
    // 0x80050164: addiu       $s7, $s7, 0x7DBC
    ctx->r23 = ADD32(ctx->r23, 0X7DBC);
    // 0x80050168: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x8005016C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80050170: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80050174: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
L_80050178:
    // 0x80050178: lw          $a1, 0x4($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X4);
    // 0x8005017C: lhu         $a0, 0x0($a1)
    ctx->r4 = MEM_HU(ctx->r5, 0X0);
    // 0x80050180: andi        $v0, $a0, 0x10
    ctx->r2 = ctx->r4 & 0X10;
    // 0x80050184: beq         $v0, $zero, L_800501A4
    if (ctx->r2 == 0) {
        // 0x80050188: addiu       $v0, $zero, 0x3
        ctx->r2 = ADD32(0, 0X3);
            goto L_800501A4;
    }
    // 0x80050188: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x8005018C: lw          $v1, 0x8($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X8);
    // 0x80050190: bnel        $v1, $v0, L_80050A64
    if (ctx->r3 != ctx->r2) {
        // 0x80050194: addiu       $s2, $s2, 0x144
        ctx->r18 = ADD32(ctx->r18, 0X144);
            goto L_80050A64;
    }
    goto skip_0;
    // 0x80050194: addiu       $s2, $s2, 0x144
    ctx->r18 = ADD32(ctx->r18, 0X144);
    skip_0:
    // 0x80050198: andi        $v0, $a0, 0x20
    ctx->r2 = ctx->r4 & 0X20;
    // 0x8005019C: bnel        $v0, $zero, L_80050A64
    if (ctx->r2 != 0) {
        // 0x800501A0: addiu       $s2, $s2, 0x144
        ctx->r18 = ADD32(ctx->r18, 0X144);
            goto L_80050A64;
    }
    goto skip_1;
    // 0x800501A0: addiu       $s2, $s2, 0x144
    ctx->r18 = ADD32(ctx->r18, 0X144);
    skip_1:
L_800501A4:
    // 0x800501A4: lui         $t0, 0x8013
    ctx->r8 = S32(0X8013 << 16);
    // 0x800501A8: addiu       $t0, $t0, 0x7DBC
    ctx->r8 = ADD32(ctx->r8, 0X7DBC);
    // 0x800501AC: lw          $t1, 0x10($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X10);
    // 0x800501B0: addiu       $v0, $t0, -0x4
    ctx->r2 = ADD32(ctx->r8, -0X4);
    // 0x800501B4: addu        $a0, $t1, $v0
    ctx->r4 = ADD32(ctx->r9, ctx->r2);
    // 0x800501B8: lbu         $v0, 0x0($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X0);
    // 0x800501BC: beql        $v0, $zero, L_80050A64
    if (ctx->r2 == 0) {
        // 0x800501C0: addiu       $s2, $s2, 0x144
        ctx->r18 = ADD32(ctx->r18, 0X144);
            goto L_80050A64;
    }
    goto skip_2;
    // 0x800501C0: addiu       $s2, $s2, 0x144
    ctx->r18 = ADD32(ctx->r18, 0X144);
    skip_2:
    // 0x800501C4: lhu         $v1, 0x184($a0)
    ctx->r3 = MEM_HU(ctx->r4, 0X184);
    // 0x800501C8: andi        $v0, $v1, 0x2
    ctx->r2 = ctx->r3 & 0X2;
    // 0x800501CC: bnel        $v0, $zero, L_80050A64
    if (ctx->r2 != 0) {
        // 0x800501D0: addiu       $s2, $s2, 0x144
        ctx->r18 = ADD32(ctx->r18, 0X144);
            goto L_80050A64;
    }
    goto skip_3;
    // 0x800501D0: addiu       $s2, $s2, 0x144
    ctx->r18 = ADD32(ctx->r18, 0X144);
    skip_3:
    // 0x800501D4: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800501D8: lbu         $v0, 0x7CF4($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7CF4);
    // 0x800501DC: bnel        $v0, $zero, L_80050A64
    if (ctx->r2 != 0) {
        // 0x800501E0: addiu       $s2, $s2, 0x144
        ctx->r18 = ADD32(ctx->r18, 0X144);
            goto L_80050A64;
    }
    goto skip_4;
    // 0x800501E0: addiu       $s2, $s2, 0x144
    ctx->r18 = ADD32(ctx->r18, 0X144);
    skip_4:
    // 0x800501E4: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x800501E8: lbu         $v0, -0x77C8($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X77C8);
    // 0x800501EC: bnel        $v0, $zero, L_80050A64
    if (ctx->r2 != 0) {
        // 0x800501F0: addiu       $s2, $s2, 0x144
        ctx->r18 = ADD32(ctx->r18, 0X144);
            goto L_80050A64;
    }
    goto skip_5;
    // 0x800501F0: addiu       $s2, $s2, 0x144
    ctx->r18 = ADD32(ctx->r18, 0X144);
    skip_5:
    // 0x800501F4: andi        $v0, $v1, 0x1
    ctx->r2 = ctx->r3 & 0X1;
    // 0x800501F8: beq         $v0, $zero, L_80050A60
    if (ctx->r2 == 0) {
        // 0x800501FC: lui         $v0, 0x8013
        ctx->r2 = S32(0X8013 << 16);
            goto L_80050A60;
    }
    // 0x800501FC: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80050200: lw          $t2, 0x14($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X14);
    // 0x80050204: addiu       $v0, $v0, 0xB88
    ctx->r2 = ADD32(ctx->r2, 0XB88);
    // 0x80050208: sll         $v1, $t2, 1
    ctx->r3 = S32(ctx->r10 << 1);
    // 0x8005020C: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x80050210: lhu         $v1, 0x0($v1)
    ctx->r3 = MEM_HU(ctx->r3, 0X0);
    // 0x80050214: lhu         $v0, 0x4($s5)
    ctx->r2 = MEM_HU(ctx->r21, 0X4);
    // 0x80050218: and         $v0, $v1, $v0
    ctx->r2 = ctx->r3 & ctx->r2;
    // 0x8005021C: beq         $v0, $zero, L_800502DC
    if (ctx->r2 == 0) {
        // 0x80050220: lui         $v0, 0x8014
        ctx->r2 = S32(0X8014 << 16);
            goto L_800502DC;
    }
    // 0x80050220: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x80050224: addiu       $v0, $v0, -0x78C0
    ctx->r2 = ADD32(ctx->r2, -0X78C0);
    // 0x80050228: addu        $s0, $s4, $v0
    ctx->r16 = ADD32(ctx->r20, ctx->r2);
    // 0x8005022C: lhu         $v0, 0x0($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X0);
    // 0x80050230: andi        $v0, $v0, 0xFBFF
    ctx->r2 = ctx->r2 & 0XFBFF;
    // 0x80050234: sh          $v0, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r2;
    // 0x80050238: lwc1        $f0, 0x278($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X278);
    // 0x8005023C: addiu       $v1, $s0, 0x28
    ctx->r3 = ADD32(ctx->r16, 0X28);
    // 0x80050240: swc1        $f0, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f0.u32l;
    // 0x80050244: lwc1        $f0, 0x27C($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X27C);
    // 0x80050248: addu        $v0, $s3, $zero
    ctx->r2 = ADD32(ctx->r19, 0);
    // 0x8005024C: swc1        $f0, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f0.u32l;
    // 0x80050250: lwc1        $f0, 0x280($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X280);
    // 0x80050254: addiu       $a0, $s3, 0x30
    ctx->r4 = ADD32(ctx->r19, 0X30);
    // 0x80050258: swc1        $f0, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f0.u32l;
L_8005025C:
    // 0x8005025C: lw          $a3, 0x0($v0)
    ctx->r7 = MEM_W(ctx->r2, 0X0);
    // 0x80050260: lw          $t0, 0x4($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X4);
    // 0x80050264: lw          $t1, 0x8($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X8);
    // 0x80050268: lw          $t2, 0xC($v0)
    ctx->r10 = MEM_W(ctx->r2, 0XC);
    // 0x8005026C: sw          $a3, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r7;
    // 0x80050270: sw          $t0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r8;
    // 0x80050274: sw          $t1, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r9;
    // 0x80050278: sw          $t2, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r10;
    // 0x8005027C: addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
    // 0x80050280: bne         $v0, $a0, L_8005025C
    if (ctx->r2 != ctx->r4) {
        // 0x80050284: addiu       $v1, $v1, 0x10
        ctx->r3 = ADD32(ctx->r3, 0X10);
            goto L_8005025C;
    }
    // 0x80050284: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
    // 0x80050288: beq         $a1, $s0, L_800502A8
    if (ctx->r5 == ctx->r16) {
        // 0x8005028C: addu        $a0, $s6, $zero
        ctx->r4 = ADD32(ctx->r22, 0);
            goto L_800502A8;
    }
    // 0x8005028C: addu        $a0, $s6, $zero
    ctx->r4 = ADD32(ctx->r22, 0);
    // 0x80050290: lw          $a1, 0x8($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X8);
    // 0x80050294: jal         0x8004ED8C
    // 0x80050298: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    func_8004ED8C(rdram, ctx);
        goto after_0;
    // 0x80050298: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    after_0:
    // 0x8005029C: lw          $v0, -0x35E4($fp)
    ctx->r2 = MEM_W(ctx->r30, -0X35E4);
    // 0x800502A0: ori         $v0, $v0, 0x100
    ctx->r2 = ctx->r2 | 0X100;
    // 0x800502A4: sw          $v0, -0x35E4($fp)
    MEM_W(-0X35E4, ctx->r30) = ctx->r2;
L_800502A8:
    // 0x800502A8: jal         0x80066A50
    // 0x800502AC: addiu       $s2, $s2, 0x144
    ctx->r18 = ADD32(ctx->r18, 0X144);
    func_80066A50(rdram, ctx);
        goto after_1;
    // 0x800502AC: addiu       $s2, $s2, 0x144
    ctx->r18 = ADD32(ctx->r18, 0X144);
    after_1:
    // 0x800502B0: lhu         $a0, 0x4($s5)
    ctx->r4 = MEM_HU(ctx->r21, 0X4);
    // 0x800502B4: jal         0x800BF2F4
    // 0x800502B8: addiu       $s1, $s1, 0x3E0
    ctx->r17 = ADD32(ctx->r17, 0X3E0);
    func_800BF2F4(rdram, ctx);
        goto after_2;
    // 0x800502B8: addiu       $s1, $s1, 0x3E0
    ctx->r17 = ADD32(ctx->r17, 0X3E0);
    after_2:
    // 0x800502BC: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
    // 0x800502C0: addiu       $v1, $v1, -0x4158
    ctx->r3 = ADD32(ctx->r3, -0X4158);
    // 0x800502C4: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800502C8: sll         $a0, $s6, 6
    ctx->r4 = S32(ctx->r22 << 6);
    // 0x800502CC: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x800502D0: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800502D4: j           L_80050A68
    // 0x800502D8: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
        goto L_80050A68;
    // 0x800502D8: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
L_800502DC:
    // 0x800502DC: lhu         $v0, 0x2($s5)
    ctx->r2 = MEM_HU(ctx->r21, 0X2);
    // 0x800502E0: and         $v0, $v1, $v0
    ctx->r2 = ctx->r3 & ctx->r2;
    // 0x800502E4: beq         $v0, $zero, L_800506F4
    if (ctx->r2 == 0) {
        // 0x800502E8: nop
    
            goto L_800506F4;
    }
    // 0x800502E8: nop

    // 0x800502EC: lhu         $v0, 0x4($a1)
    ctx->r2 = MEM_HU(ctx->r5, 0X4);
    // 0x800502F0: bne         $v0, $zero, L_80050304
    if (ctx->r2 != 0) {
        // 0x800502F4: addiu       $v1, $zero, -0x101
        ctx->r3 = ADD32(0, -0X101);
            goto L_80050304;
    }
    // 0x800502F4: addiu       $v1, $zero, -0x101
    ctx->r3 = ADD32(0, -0X101);
    // 0x800502F8: lw          $v0, -0x35E4($fp)
    ctx->r2 = MEM_W(ctx->r30, -0X35E4);
    // 0x800502FC: and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // 0x80050300: sw          $v0, -0x35E4($fp)
    MEM_W(-0X35E4, ctx->r30) = ctx->r2;
L_80050304:
    // 0x80050304: lhu         $v0, 0x0($a1)
    ctx->r2 = MEM_HU(ctx->r5, 0X0);
    // 0x80050308: andi        $v0, $v0, 0x10
    ctx->r2 = ctx->r2 & 0X10;
    // 0x8005030C: beq         $v0, $zero, L_80050358
    if (ctx->r2 == 0) {
        // 0x80050310: addiu       $v0, $zero, 0x3
        ctx->r2 = ADD32(0, 0X3);
            goto L_80050358;
    }
    // 0x80050310: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x80050314: lw          $v1, 0x8($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X8);
    // 0x80050318: bnel        $v1, $v0, L_80050A64
    if (ctx->r3 != ctx->r2) {
        // 0x8005031C: addiu       $s2, $s2, 0x144
        ctx->r18 = ADD32(ctx->r18, 0X144);
            goto L_80050A64;
    }
    goto skip_6;
    // 0x8005031C: addiu       $s2, $s2, 0x144
    ctx->r18 = ADD32(ctx->r18, 0X144);
    skip_6:
    // 0x80050320: addu        $a0, $s6, $zero
    ctx->r4 = ADD32(ctx->r22, 0);
    // 0x80050324: lui         $a3, 0x8014
    ctx->r7 = S32(0X8014 << 16);
    // 0x80050328: lw          $v1, 0x1C8($s7)
    ctx->r3 = MEM_W(ctx->r23, 0X1C8);
    // 0x8005032C: addiu       $a3, $a3, -0x7D98
    ctx->r7 = ADD32(ctx->r7, -0X7D98);
    // 0x80050330: sll         $v0, $v1, 5
    ctx->r2 = S32(ctx->r3 << 5);
    // 0x80050334: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x80050338: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x8005033C: addu        $v0, $v0, $a3
    ctx->r2 = ADD32(ctx->r2, ctx->r7);
    // 0x80050340: addu        $s0, $s4, $v0
    ctx->r16 = ADD32(ctx->r20, ctx->r2);
    // 0x80050344: lw          $a1, 0x8($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X8);
    // 0x80050348: jal         0x8004ED8C
    // 0x8005034C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_8004ED8C(rdram, ctx);
        goto after_3;
    // 0x8005034C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_3:
    // 0x80050350: j           L_80050A64
    // 0x80050354: addiu       $s2, $s2, 0x144
    ctx->r18 = ADD32(ctx->r18, 0X144);
        goto L_80050A64;
    // 0x80050354: addiu       $s2, $s2, 0x144
    ctx->r18 = ADD32(ctx->r18, 0X144);
L_80050358:
    // 0x80050358: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8005035C: lw          $v1, 0xB70($v0)
    ctx->r3 = MEM_W(ctx->r2, 0XB70);
    // 0x80050360: addiu       $v0, $zero, 0x14
    ctx->r2 = ADD32(0, 0X14);
    // 0x80050364: bne         $v1, $v0, L_800504D8
    if (ctx->r3 != ctx->r2) {
        // 0x80050368: nop
    
            goto L_800504D8;
    }
    // 0x80050368: nop

    // 0x8005036C: lw          $v0, 0x8($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X8);
    // 0x80050370: slti        $v0, $v0, 0x4
    ctx->r2 = SIGNED(ctx->r2) < 0X4 ? 1 : 0;
    // 0x80050374: bne         $v0, $zero, L_8005055C
    if (ctx->r2 != 0) {
        // 0x80050378: lui         $v0, 0x6666
        ctx->r2 = S32(0X6666 << 16);
            goto L_8005055C;
    }
    // 0x80050378: lui         $v0, 0x6666
    ctx->r2 = S32(0X6666 << 16);
    // 0x8005037C: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x80050380: addiu       $v0, $v0, -0x7BA8
    ctx->r2 = ADD32(ctx->r2, -0X7BA8);
    // 0x80050384: addu        $s0, $s4, $v0
    ctx->r16 = ADD32(ctx->r20, ctx->r2);
    // 0x80050388: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8005038C: lwc1        $f0, -0x560C($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X560C);
    // 0x80050390: beq         $a1, $s0, L_800504CC
    if (ctx->r5 == ctx->r16) {
        // 0x80050394: addiu       $v0, $zero, 0x4
        ctx->r2 = ADD32(0, 0X4);
            goto L_800504CC;
    }
    // 0x80050394: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // 0x80050398: sh          $v0, 0x2($s1)
    MEM_H(0X2, ctx->r17) = ctx->r2;
    // 0x8005039C: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x800503A0: addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    // 0x800503A4: lhu         $v1, 0x0($s1)
    ctx->r3 = MEM_HU(ctx->r17, 0X0);
    // 0x800503A8: lw          $v0, -0x7DA0($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7DA0);
    // 0x800503AC: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x800503B0: sw          $a1, 0xBC($s1)
    MEM_W(0XBC, ctx->r17) = ctx->r5;
    // 0x800503B4: sw          $s0, 0xC0($s1)
    MEM_W(0XC0, ctx->r17) = ctx->r16;
    // 0x800503B8: sw          $zero, 0xC4($s1)
    MEM_W(0XC4, ctx->r17) = 0;
    // 0x800503BC: swc1        $f0, 0xC8($s1)
    MEM_W(0XC8, ctx->r17) = ctx->f0.u32l;
    // 0x800503C0: sw          $zero, 0xCC($s1)
    MEM_W(0XCC, ctx->r17) = 0;
    // 0x800503C4: sw          $s3, 0x74($s1)
    MEM_W(0X74, ctx->r17) = ctx->r19;
    // 0x800503C8: ori         $v1, $v1, 0x1
    ctx->r3 = ctx->r3 | 0X1;
    // 0x800503CC: bne         $v0, $t0, L_800503E0
    if (ctx->r2 != ctx->r8) {
        // 0x800503D0: sh          $v1, 0x0($s1)
        MEM_H(0X0, ctx->r17) = ctx->r3;
            goto L_800503E0;
    }
    // 0x800503D0: sh          $v1, 0x0($s1)
    MEM_H(0X0, ctx->r17) = ctx->r3;
    // 0x800503D4: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x800503D8: lw          $v0, -0x776C($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X776C);
    // 0x800503DC: sw          $s1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r17;
L_800503E0:
    // 0x800503E0: sw          $s1, 0x4($s2)
    MEM_W(0X4, ctx->r18) = ctx->r17;
    // 0x800503E4: addiu       $v1, $a2, 0x28
    ctx->r3 = ADD32(ctx->r6, 0X28);
    // 0x800503E8: addiu       $v0, $a1, 0x28
    ctx->r2 = ADD32(ctx->r5, 0X28);
    // 0x800503EC: addiu       $a0, $a1, 0x58
    ctx->r4 = ADD32(ctx->r5, 0X58);
L_800503F0:
    // 0x800503F0: lw          $t1, 0x0($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X0);
    // 0x800503F4: lw          $t2, 0x4($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X4);
    // 0x800503F8: lw          $a3, 0x8($v0)
    ctx->r7 = MEM_W(ctx->r2, 0X8);
    // 0x800503FC: lw          $t0, 0xC($v0)
    ctx->r8 = MEM_W(ctx->r2, 0XC);
    // 0x80050400: sw          $t1, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r9;
    // 0x80050404: sw          $t2, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r10;
    // 0x80050408: sw          $a3, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r7;
    // 0x8005040C: sw          $t0, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r8;
    // 0x80050410: addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
    // 0x80050414: bne         $v0, $a0, L_800503F0
    if (ctx->r2 != ctx->r4) {
        // 0x80050418: addiu       $v1, $v1, 0x10
        ctx->r3 = ADD32(ctx->r3, 0X10);
            goto L_800503F0;
    }
    // 0x80050418: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
    // 0x8005041C: addiu       $a0, $s0, 0x28
    ctx->r4 = ADD32(ctx->r16, 0X28);
    // 0x80050420: lw          $t1, 0x10($a1)
    ctx->r9 = MEM_W(ctx->r5, 0X10);
    // 0x80050424: lw          $t2, 0x14($a1)
    ctx->r10 = MEM_W(ctx->r5, 0X14);
    // 0x80050428: lw          $a3, 0x18($a1)
    ctx->r7 = MEM_W(ctx->r5, 0X18);
    // 0x8005042C: sw          $t1, 0x10($a2)
    MEM_W(0X10, ctx->r6) = ctx->r9;
    // 0x80050430: sw          $t2, 0x14($a2)
    MEM_W(0X14, ctx->r6) = ctx->r10;
    // 0x80050434: sw          $a3, 0x18($a2)
    MEM_W(0X18, ctx->r6) = ctx->r7;
    // 0x80050438: lw          $t1, 0x1C($a1)
    ctx->r9 = MEM_W(ctx->r5, 0X1C);
    // 0x8005043C: lw          $t2, 0x20($a1)
    ctx->r10 = MEM_W(ctx->r5, 0X20);
    // 0x80050440: lw          $a3, 0x24($a1)
    ctx->r7 = MEM_W(ctx->r5, 0X24);
    // 0x80050444: sw          $t1, 0x1C($a2)
    MEM_W(0X1C, ctx->r6) = ctx->r9;
    // 0x80050448: sw          $t2, 0x20($a2)
    MEM_W(0X20, ctx->r6) = ctx->r10;
    // 0x8005044C: sw          $a3, 0x24($a2)
    MEM_W(0X24, ctx->r6) = ctx->r7;
    // 0x80050450: lhu         $v0, 0x0($a1)
    ctx->r2 = MEM_HU(ctx->r5, 0X0);
    // 0x80050454: addiu       $v1, $a1, 0x28
    ctx->r3 = ADD32(ctx->r5, 0X28);
    // 0x80050458: ori         $v0, $v0, 0x1
    ctx->r2 = ctx->r2 | 0X1;
    // 0x8005045C: sh          $v0, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r2;
    // 0x80050460: lhu         $v0, 0x0($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X0);
    // 0x80050464: addiu       $a1, $a1, 0x58
    ctx->r5 = ADD32(ctx->r5, 0X58);
    // 0x80050468: ori         $v0, $v0, 0x1
    ctx->r2 = ctx->r2 | 0X1;
    // 0x8005046C: sh          $v0, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r2;
L_80050470:
    // 0x80050470: lw          $t1, 0x0($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X0);
    // 0x80050474: lw          $t2, 0x4($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X4);
    // 0x80050478: lw          $a3, 0x8($v1)
    ctx->r7 = MEM_W(ctx->r3, 0X8);
    // 0x8005047C: lw          $t0, 0xC($v1)
    ctx->r8 = MEM_W(ctx->r3, 0XC);
    // 0x80050480: sw          $t1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r9;
    // 0x80050484: sw          $t2, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r10;
    // 0x80050488: sw          $a3, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r7;
    // 0x8005048C: sw          $t0, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r8;
    // 0x80050490: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
    // 0x80050494: bne         $v1, $a1, L_80050470
    if (ctx->r3 != ctx->r5) {
        // 0x80050498: addiu       $a0, $a0, 0x10
        ctx->r4 = ADD32(ctx->r4, 0X10);
            goto L_80050470;
    }
    // 0x80050498: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    // 0x8005049C: lwc1        $f0, 0x4C($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X4C);
    // 0x800504A0: lwc1        $f2, 0x50($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X50);
    // 0x800504A4: lwc1        $f6, 0xA0($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XA0);
    // 0x800504A8: lwc1        $f4, 0x54($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X54);
    // 0x800504AC: mov.s       $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = ctx->f6.fl;
    // 0x800504B0: swc1        $f0, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f0.u32l;
    // 0x800504B4: swc1        $f2, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f2.u32l;
    // 0x800504B8: swc1        $f4, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f4.u32l;
    // 0x800504BC: swc1        $f6, 0x98($s0)
    MEM_W(0X98, ctx->r16) = ctx->f6.u32l;
    // 0x800504C0: swc1        $f8, 0x9C($s0)
    MEM_W(0X9C, ctx->r16) = ctx->f8.u32l;
    // 0x800504C4: jal         0x80066A50
    // 0x800504C8: sw          $a2, 0x4($s2)
    MEM_W(0X4, ctx->r18) = ctx->r6;
    func_80066A50(rdram, ctx);
        goto after_4;
    // 0x800504C8: sw          $a2, 0x4($s2)
    MEM_W(0X4, ctx->r18) = ctx->r6;
    after_4:
L_800504CC:
    // 0x800504CC: lw          $v0, 0x8($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X8);
    // 0x800504D0: j           L_80050A98
    // 0x800504D4: sw          $v0, 0x1C8($s7)
    MEM_W(0X1C8, ctx->r23) = ctx->r2;
        goto L_80050A98;
    // 0x800504D4: sw          $v0, 0x1C8($s7)
    MEM_W(0X1C8, ctx->r23) = ctx->r2;
L_800504D8:
    // 0x800504D8: lw          $v0, 0x8($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X8);
    // 0x800504DC: slti        $v0, $v0, 0x4
    ctx->r2 = SIGNED(ctx->r2) < 0X4 ? 1 : 0;
    // 0x800504E0: bne         $v0, $zero, L_8005055C
    if (ctx->r2 != 0) {
        // 0x800504E4: lui         $v0, 0x6666
        ctx->r2 = S32(0X6666 << 16);
            goto L_8005055C;
    }
    // 0x800504E4: lui         $v0, 0x6666
    ctx->r2 = S32(0X6666 << 16);
    // 0x800504E8: lui         $t1, 0x8014
    ctx->r9 = S32(0X8014 << 16);
    // 0x800504EC: addiu       $t1, $t1, -0x7D98
    ctx->r9 = ADD32(ctx->r9, -0X7D98);
    // 0x800504F0: addu        $s0, $s4, $t1
    ctx->r16 = ADD32(ctx->r20, ctx->r9);
    // 0x800504F4: lwc1        $f0, 0x278($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X278);
    // 0x800504F8: addiu       $v1, $s0, 0x28
    ctx->r3 = ADD32(ctx->r16, 0X28);
    // 0x800504FC: swc1        $f0, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f0.u32l;
    // 0x80050500: lwc1        $f0, 0x27C($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X27C);
    // 0x80050504: addu        $v0, $s3, $zero
    ctx->r2 = ADD32(ctx->r19, 0);
    // 0x80050508: swc1        $f0, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f0.u32l;
    // 0x8005050C: lwc1        $f0, 0x280($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X280);
    // 0x80050510: addiu       $a0, $s3, 0x30
    ctx->r4 = ADD32(ctx->r19, 0X30);
    // 0x80050514: swc1        $f0, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f0.u32l;
L_80050518:
    // 0x80050518: lw          $t2, 0x0($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X0);
    // 0x8005051C: lw          $a3, 0x4($v0)
    ctx->r7 = MEM_W(ctx->r2, 0X4);
    // 0x80050520: lw          $t0, 0x8($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X8);
    // 0x80050524: lw          $t1, 0xC($v0)
    ctx->r9 = MEM_W(ctx->r2, 0XC);
    // 0x80050528: sw          $t2, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r10;
    // 0x8005052C: sw          $a3, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r7;
    // 0x80050530: sw          $t0, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r8;
    // 0x80050534: sw          $t1, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r9;
    // 0x80050538: addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
    // 0x8005053C: bne         $v0, $a0, L_80050518
    if (ctx->r2 != ctx->r4) {
        // 0x80050540: addiu       $v1, $v1, 0x10
        ctx->r3 = ADD32(ctx->r3, 0X10);
            goto L_80050518;
    }
    // 0x80050540: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
    // 0x80050544: addu        $a0, $s6, $zero
    ctx->r4 = ADD32(ctx->r22, 0);
    // 0x80050548: lw          $a1, 0x8($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X8);
    // 0x8005054C: jal         0x8004ED8C
    // 0x80050550: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    func_8004ED8C(rdram, ctx);
        goto after_5;
    // 0x80050550: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    after_5:
    // 0x80050554: j           L_800506E8
    // 0x80050558: nop

        goto L_800506E8;
    // 0x80050558: nop

L_8005055C:
    // 0x8005055C: lw          $a0, 0x8($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X8);
    // 0x80050560: ori         $v0, $v0, 0x6667
    ctx->r2 = ctx->r2 | 0X6667;
    // 0x80050564: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x80050568: mult        $a0, $v0
    result = S64(S32(ctx->r4)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8005056C: lui         $t0, 0x8014
    ctx->r8 = S32(0X8014 << 16);
    // 0x80050570: addiu       $t0, $t0, -0x7D98
    ctx->r8 = ADD32(ctx->r8, -0X7D98);
    // 0x80050574: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80050578: lwc1        $f0, -0x5608($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X5608);
    // 0x8005057C: sra         $v0, $a0, 31
    ctx->r2 = S32(SIGNED(ctx->r4) >> 31);
    // 0x80050580: mfhi        $a3
    ctx->r7 = hi;
    // 0x80050584: sra         $v1, $a3, 1
    ctx->r3 = S32(SIGNED(ctx->r7) >> 1);
    // 0x80050588: subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // 0x8005058C: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x80050590: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80050594: subu        $a0, $a0, $v0
    ctx->r4 = SUB32(ctx->r4, ctx->r2);
    // 0x80050598: sll         $v0, $a0, 5
    ctx->r2 = S32(ctx->r4 << 5);
    // 0x8005059C: subu        $v0, $v0, $a0
    ctx->r2 = SUB32(ctx->r2, ctx->r4);
    // 0x800505A0: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x800505A4: addu        $v0, $v0, $t0
    ctx->r2 = ADD32(ctx->r2, ctx->r8);
    // 0x800505A8: addu        $s0, $s4, $v0
    ctx->r16 = ADD32(ctx->r20, ctx->r2);
    // 0x800505AC: beq         $a1, $s0, L_800506E8
    if (ctx->r5 == ctx->r16) {
        // 0x800505B0: addiu       $v0, $zero, 0x4
        ctx->r2 = ADD32(0, 0X4);
            goto L_800506E8;
    }
    // 0x800505B0: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // 0x800505B4: sh          $v0, 0x2($s1)
    MEM_H(0X2, ctx->r17) = ctx->r2;
    // 0x800505B8: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x800505BC: addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    // 0x800505C0: lhu         $v1, 0x0($s1)
    ctx->r3 = MEM_HU(ctx->r17, 0X0);
    // 0x800505C4: lw          $v0, -0x7DA0($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7DA0);
    // 0x800505C8: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x800505CC: sw          $a1, 0xBC($s1)
    MEM_W(0XBC, ctx->r17) = ctx->r5;
    // 0x800505D0: sw          $s0, 0xC0($s1)
    MEM_W(0XC0, ctx->r17) = ctx->r16;
    // 0x800505D4: sw          $zero, 0xC4($s1)
    MEM_W(0XC4, ctx->r17) = 0;
    // 0x800505D8: swc1        $f0, 0xC8($s1)
    MEM_W(0XC8, ctx->r17) = ctx->f0.u32l;
    // 0x800505DC: sw          $zero, 0xCC($s1)
    MEM_W(0XCC, ctx->r17) = 0;
    // 0x800505E0: sw          $s3, 0x74($s1)
    MEM_W(0X74, ctx->r17) = ctx->r19;
    // 0x800505E4: ori         $v1, $v1, 0x1
    ctx->r3 = ctx->r3 | 0X1;
    // 0x800505E8: bne         $v0, $t1, L_800505FC
    if (ctx->r2 != ctx->r9) {
        // 0x800505EC: sh          $v1, 0x0($s1)
        MEM_H(0X0, ctx->r17) = ctx->r3;
            goto L_800505FC;
    }
    // 0x800505EC: sh          $v1, 0x0($s1)
    MEM_H(0X0, ctx->r17) = ctx->r3;
    // 0x800505F0: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x800505F4: lw          $v0, -0x776C($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X776C);
    // 0x800505F8: sw          $s1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r17;
L_800505FC:
    // 0x800505FC: sw          $s1, 0x4($s2)
    MEM_W(0X4, ctx->r18) = ctx->r17;
    // 0x80050600: addiu       $v1, $a2, 0x28
    ctx->r3 = ADD32(ctx->r6, 0X28);
    // 0x80050604: addiu       $v0, $a1, 0x28
    ctx->r2 = ADD32(ctx->r5, 0X28);
    // 0x80050608: addiu       $a0, $a1, 0x58
    ctx->r4 = ADD32(ctx->r5, 0X58);
L_8005060C:
    // 0x8005060C: lw          $t2, 0x0($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X0);
    // 0x80050610: lw          $a3, 0x4($v0)
    ctx->r7 = MEM_W(ctx->r2, 0X4);
    // 0x80050614: lw          $t0, 0x8($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X8);
    // 0x80050618: lw          $t1, 0xC($v0)
    ctx->r9 = MEM_W(ctx->r2, 0XC);
    // 0x8005061C: sw          $t2, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r10;
    // 0x80050620: sw          $a3, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r7;
    // 0x80050624: sw          $t0, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r8;
    // 0x80050628: sw          $t1, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r9;
    // 0x8005062C: addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
    // 0x80050630: bne         $v0, $a0, L_8005060C
    if (ctx->r2 != ctx->r4) {
        // 0x80050634: addiu       $v1, $v1, 0x10
        ctx->r3 = ADD32(ctx->r3, 0X10);
            goto L_8005060C;
    }
    // 0x80050634: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
    // 0x80050638: addiu       $a0, $s0, 0x28
    ctx->r4 = ADD32(ctx->r16, 0X28);
    // 0x8005063C: lw          $t2, 0x10($a1)
    ctx->r10 = MEM_W(ctx->r5, 0X10);
    // 0x80050640: lw          $a3, 0x14($a1)
    ctx->r7 = MEM_W(ctx->r5, 0X14);
    // 0x80050644: lw          $t0, 0x18($a1)
    ctx->r8 = MEM_W(ctx->r5, 0X18);
    // 0x80050648: sw          $t2, 0x10($a2)
    MEM_W(0X10, ctx->r6) = ctx->r10;
    // 0x8005064C: sw          $a3, 0x14($a2)
    MEM_W(0X14, ctx->r6) = ctx->r7;
    // 0x80050650: sw          $t0, 0x18($a2)
    MEM_W(0X18, ctx->r6) = ctx->r8;
    // 0x80050654: lw          $t2, 0x1C($a1)
    ctx->r10 = MEM_W(ctx->r5, 0X1C);
    // 0x80050658: lw          $a3, 0x20($a1)
    ctx->r7 = MEM_W(ctx->r5, 0X20);
    // 0x8005065C: lw          $t0, 0x24($a1)
    ctx->r8 = MEM_W(ctx->r5, 0X24);
    // 0x80050660: sw          $t2, 0x1C($a2)
    MEM_W(0X1C, ctx->r6) = ctx->r10;
    // 0x80050664: sw          $a3, 0x20($a2)
    MEM_W(0X20, ctx->r6) = ctx->r7;
    // 0x80050668: sw          $t0, 0x24($a2)
    MEM_W(0X24, ctx->r6) = ctx->r8;
    // 0x8005066C: lhu         $v0, 0x0($a1)
    ctx->r2 = MEM_HU(ctx->r5, 0X0);
    // 0x80050670: addiu       $v1, $a1, 0x28
    ctx->r3 = ADD32(ctx->r5, 0X28);
    // 0x80050674: ori         $v0, $v0, 0x1
    ctx->r2 = ctx->r2 | 0X1;
    // 0x80050678: sh          $v0, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r2;
    // 0x8005067C: lhu         $v0, 0x0($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X0);
    // 0x80050680: addiu       $a1, $a1, 0x58
    ctx->r5 = ADD32(ctx->r5, 0X58);
    // 0x80050684: ori         $v0, $v0, 0x1
    ctx->r2 = ctx->r2 | 0X1;
    // 0x80050688: sh          $v0, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r2;
L_8005068C:
    // 0x8005068C: lw          $t2, 0x0($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X0);
    // 0x80050690: lw          $a3, 0x4($v1)
    ctx->r7 = MEM_W(ctx->r3, 0X4);
    // 0x80050694: lw          $t0, 0x8($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X8);
    // 0x80050698: lw          $t1, 0xC($v1)
    ctx->r9 = MEM_W(ctx->r3, 0XC);
    // 0x8005069C: sw          $t2, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r10;
    // 0x800506A0: sw          $a3, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r7;
    // 0x800506A4: sw          $t0, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r8;
    // 0x800506A8: sw          $t1, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r9;
    // 0x800506AC: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
    // 0x800506B0: bne         $v1, $a1, L_8005068C
    if (ctx->r3 != ctx->r5) {
        // 0x800506B4: addiu       $a0, $a0, 0x10
        ctx->r4 = ADD32(ctx->r4, 0X10);
            goto L_8005068C;
    }
    // 0x800506B4: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    // 0x800506B8: lwc1        $f0, 0x4C($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X4C);
    // 0x800506BC: lwc1        $f2, 0x50($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X50);
    // 0x800506C0: lwc1        $f6, 0xA0($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XA0);
    // 0x800506C4: lwc1        $f4, 0x54($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X54);
    // 0x800506C8: mov.s       $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = ctx->f6.fl;
    // 0x800506CC: swc1        $f0, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f0.u32l;
    // 0x800506D0: swc1        $f2, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f2.u32l;
    // 0x800506D4: swc1        $f4, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f4.u32l;
    // 0x800506D8: swc1        $f6, 0x98($s0)
    MEM_W(0X98, ctx->r16) = ctx->f6.u32l;
    // 0x800506DC: swc1        $f8, 0x9C($s0)
    MEM_W(0X9C, ctx->r16) = ctx->f8.u32l;
    // 0x800506E0: jal         0x80066A50
    // 0x800506E4: sw          $a2, 0x4($s2)
    MEM_W(0X4, ctx->r18) = ctx->r6;
    func_80066A50(rdram, ctx);
        goto after_6;
    // 0x800506E4: sw          $a2, 0x4($s2)
    MEM_W(0X4, ctx->r18) = ctx->r6;
    after_6:
L_800506E8:
    // 0x800506E8: lw          $v0, 0x8($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X8);
    // 0x800506EC: j           L_80050A60
    // 0x800506F0: sw          $v0, 0x1C8($s7)
    MEM_W(0X1C8, ctx->r23) = ctx->r2;
        goto L_80050A60;
    // 0x800506F0: sw          $v0, 0x1C8($s7)
    MEM_W(0X1C8, ctx->r23) = ctx->r2;
L_800506F4:
    // 0x800506F4: lhu         $v0, 0x8($s5)
    ctx->r2 = MEM_HU(ctx->r21, 0X8);
    // 0x800506F8: and         $v0, $v1, $v0
    ctx->r2 = ctx->r3 & ctx->r2;
    // 0x800506FC: beq         $v0, $zero, L_8005077C
    if (ctx->r2 == 0) {
        // 0x80050700: lui         $t2, 0x8014
        ctx->r10 = S32(0X8014 << 16);
            goto L_8005077C;
    }
    // 0x80050700: lui         $t2, 0x8014
    ctx->r10 = S32(0X8014 << 16);
    // 0x80050704: addiu       $t2, $t2, -0x7D98
    ctx->r10 = ADD32(ctx->r10, -0X7D98);
    // 0x80050708: addu        $s0, $s4, $t2
    ctx->r16 = ADD32(ctx->r20, ctx->r10);
    // 0x8005070C: lwc1        $f0, 0x278($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X278);
    // 0x80050710: addiu       $v1, $s0, 0x28
    ctx->r3 = ADD32(ctx->r16, 0X28);
    // 0x80050714: swc1        $f0, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f0.u32l;
    // 0x80050718: lwc1        $f0, 0x27C($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X27C);
    // 0x8005071C: addu        $v0, $s3, $zero
    ctx->r2 = ADD32(ctx->r19, 0);
    // 0x80050720: swc1        $f0, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f0.u32l;
    // 0x80050724: lwc1        $f0, 0x280($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X280);
    // 0x80050728: addiu       $a0, $s3, 0x30
    ctx->r4 = ADD32(ctx->r19, 0X30);
    // 0x8005072C: swc1        $f0, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f0.u32l;
L_80050730:
    // 0x80050730: lw          $a3, 0x0($v0)
    ctx->r7 = MEM_W(ctx->r2, 0X0);
    // 0x80050734: lw          $t0, 0x4($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X4);
    // 0x80050738: lw          $t1, 0x8($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X8);
    // 0x8005073C: lw          $t2, 0xC($v0)
    ctx->r10 = MEM_W(ctx->r2, 0XC);
    // 0x80050740: sw          $a3, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r7;
    // 0x80050744: sw          $t0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r8;
    // 0x80050748: sw          $t1, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r9;
    // 0x8005074C: sw          $t2, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r10;
    // 0x80050750: addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
    // 0x80050754: bne         $v0, $a0, L_80050730
    if (ctx->r2 != ctx->r4) {
        // 0x80050758: addiu       $v1, $v1, 0x10
        ctx->r3 = ADD32(ctx->r3, 0X10);
            goto L_80050730;
    }
    // 0x80050758: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
    // 0x8005075C: addu        $a0, $s6, $zero
    ctx->r4 = ADD32(ctx->r22, 0);
    // 0x80050760: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x80050764: jal         0x8004ED8C
    // 0x80050768: addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    func_8004ED8C(rdram, ctx);
        goto after_7;
    // 0x80050768: addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    after_7:
    // 0x8005076C: lw          $v0, -0x35E4($fp)
    ctx->r2 = MEM_W(ctx->r30, -0X35E4);
    // 0x80050770: addiu       $v1, $zero, -0x101
    ctx->r3 = ADD32(0, -0X101);
    // 0x80050774: j           L_80050A58
    // 0x80050778: sw          $zero, 0x1C8($s7)
    MEM_W(0X1C8, ctx->r23) = 0;
        goto L_80050A58;
    // 0x80050778: sw          $zero, 0x1C8($s7)
    MEM_W(0X1C8, ctx->r23) = 0;
L_8005077C:
    // 0x8005077C: lhu         $v0, 0xA($s5)
    ctx->r2 = MEM_HU(ctx->r21, 0XA);
    // 0x80050780: and         $v0, $v1, $v0
    ctx->r2 = ctx->r3 & ctx->r2;
    // 0x80050784: beq         $v0, $zero, L_800508EC
    if (ctx->r2 == 0) {
        // 0x80050788: lui         $v0, 0x8014
        ctx->r2 = S32(0X8014 << 16);
            goto L_800508EC;
    }
    // 0x80050788: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x8005078C: addiu       $v0, $v0, -0x7CA0
    ctx->r2 = ADD32(ctx->r2, -0X7CA0);
    // 0x80050790: addu        $s0, $s4, $v0
    ctx->r16 = ADD32(ctx->r20, ctx->r2);
    // 0x80050794: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80050798: lwc1        $f0, -0x5604($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X5604);
    // 0x8005079C: beq         $a1, $s0, L_800508D8
    if (ctx->r5 == ctx->r16) {
        // 0x800507A0: addiu       $v0, $zero, 0x4
        ctx->r2 = ADD32(0, 0X4);
            goto L_800508D8;
    }
    // 0x800507A0: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // 0x800507A4: sh          $v0, 0x2($s1)
    MEM_H(0X2, ctx->r17) = ctx->r2;
    // 0x800507A8: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x800507AC: addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    // 0x800507B0: lhu         $v1, 0x0($s1)
    ctx->r3 = MEM_HU(ctx->r17, 0X0);
    // 0x800507B4: lw          $v0, -0x7DA0($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7DA0);
    // 0x800507B8: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x800507BC: sw          $a1, 0xBC($s1)
    MEM_W(0XBC, ctx->r17) = ctx->r5;
    // 0x800507C0: sw          $s0, 0xC0($s1)
    MEM_W(0XC0, ctx->r17) = ctx->r16;
    // 0x800507C4: sw          $zero, 0xC4($s1)
    MEM_W(0XC4, ctx->r17) = 0;
    // 0x800507C8: swc1        $f0, 0xC8($s1)
    MEM_W(0XC8, ctx->r17) = ctx->f0.u32l;
    // 0x800507CC: sw          $zero, 0xCC($s1)
    MEM_W(0XCC, ctx->r17) = 0;
    // 0x800507D0: sw          $s3, 0x74($s1)
    MEM_W(0X74, ctx->r17) = ctx->r19;
    // 0x800507D4: ori         $v1, $v1, 0x1
    ctx->r3 = ctx->r3 | 0X1;
    // 0x800507D8: bne         $v0, $a3, L_800507EC
    if (ctx->r2 != ctx->r7) {
        // 0x800507DC: sh          $v1, 0x0($s1)
        MEM_H(0X0, ctx->r17) = ctx->r3;
            goto L_800507EC;
    }
    // 0x800507DC: sh          $v1, 0x0($s1)
    MEM_H(0X0, ctx->r17) = ctx->r3;
    // 0x800507E0: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x800507E4: lw          $v0, -0x776C($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X776C);
    // 0x800507E8: sw          $s1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r17;
L_800507EC:
    // 0x800507EC: sw          $s1, 0x4($s2)
    MEM_W(0X4, ctx->r18) = ctx->r17;
    // 0x800507F0: addiu       $v1, $a2, 0x28
    ctx->r3 = ADD32(ctx->r6, 0X28);
    // 0x800507F4: addiu       $v0, $a1, 0x28
    ctx->r2 = ADD32(ctx->r5, 0X28);
    // 0x800507F8: addiu       $a0, $a1, 0x58
    ctx->r4 = ADD32(ctx->r5, 0X58);
L_800507FC:
    // 0x800507FC: lw          $t0, 0x0($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X0);
    // 0x80050800: lw          $t1, 0x4($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X4);
    // 0x80050804: lw          $t2, 0x8($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X8);
    // 0x80050808: lw          $a3, 0xC($v0)
    ctx->r7 = MEM_W(ctx->r2, 0XC);
    // 0x8005080C: sw          $t0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r8;
    // 0x80050810: sw          $t1, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r9;
    // 0x80050814: sw          $t2, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r10;
    // 0x80050818: sw          $a3, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r7;
    // 0x8005081C: addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
    // 0x80050820: bne         $v0, $a0, L_800507FC
    if (ctx->r2 != ctx->r4) {
        // 0x80050824: addiu       $v1, $v1, 0x10
        ctx->r3 = ADD32(ctx->r3, 0X10);
            goto L_800507FC;
    }
    // 0x80050824: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
    // 0x80050828: addiu       $a0, $s0, 0x28
    ctx->r4 = ADD32(ctx->r16, 0X28);
    // 0x8005082C: lw          $t0, 0x10($a1)
    ctx->r8 = MEM_W(ctx->r5, 0X10);
    // 0x80050830: lw          $t1, 0x14($a1)
    ctx->r9 = MEM_W(ctx->r5, 0X14);
    // 0x80050834: lw          $t2, 0x18($a1)
    ctx->r10 = MEM_W(ctx->r5, 0X18);
    // 0x80050838: sw          $t0, 0x10($a2)
    MEM_W(0X10, ctx->r6) = ctx->r8;
    // 0x8005083C: sw          $t1, 0x14($a2)
    MEM_W(0X14, ctx->r6) = ctx->r9;
    // 0x80050840: sw          $t2, 0x18($a2)
    MEM_W(0X18, ctx->r6) = ctx->r10;
    // 0x80050844: lw          $t0, 0x1C($a1)
    ctx->r8 = MEM_W(ctx->r5, 0X1C);
    // 0x80050848: lw          $t1, 0x20($a1)
    ctx->r9 = MEM_W(ctx->r5, 0X20);
    // 0x8005084C: lw          $t2, 0x24($a1)
    ctx->r10 = MEM_W(ctx->r5, 0X24);
    // 0x80050850: sw          $t0, 0x1C($a2)
    MEM_W(0X1C, ctx->r6) = ctx->r8;
    // 0x80050854: sw          $t1, 0x20($a2)
    MEM_W(0X20, ctx->r6) = ctx->r9;
    // 0x80050858: sw          $t2, 0x24($a2)
    MEM_W(0X24, ctx->r6) = ctx->r10;
    // 0x8005085C: lhu         $v0, 0x0($a1)
    ctx->r2 = MEM_HU(ctx->r5, 0X0);
    // 0x80050860: addiu       $v1, $a1, 0x28
    ctx->r3 = ADD32(ctx->r5, 0X28);
    // 0x80050864: ori         $v0, $v0, 0x1
    ctx->r2 = ctx->r2 | 0X1;
    // 0x80050868: sh          $v0, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r2;
    // 0x8005086C: lhu         $v0, 0x0($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X0);
    // 0x80050870: addiu       $a1, $a1, 0x58
    ctx->r5 = ADD32(ctx->r5, 0X58);
    // 0x80050874: ori         $v0, $v0, 0x1
    ctx->r2 = ctx->r2 | 0X1;
    // 0x80050878: sh          $v0, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r2;
L_8005087C:
    // 0x8005087C: lw          $t0, 0x0($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X0);
    // 0x80050880: lw          $t1, 0x4($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X4);
    // 0x80050884: lw          $t2, 0x8($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X8);
    // 0x80050888: lw          $a3, 0xC($v1)
    ctx->r7 = MEM_W(ctx->r3, 0XC);
    // 0x8005088C: sw          $t0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r8;
    // 0x80050890: sw          $t1, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r9;
    // 0x80050894: sw          $t2, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r10;
    // 0x80050898: sw          $a3, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r7;
    // 0x8005089C: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
    // 0x800508A0: bne         $v1, $a1, L_8005087C
    if (ctx->r3 != ctx->r5) {
        // 0x800508A4: addiu       $a0, $a0, 0x10
        ctx->r4 = ADD32(ctx->r4, 0X10);
            goto L_8005087C;
    }
    // 0x800508A4: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    // 0x800508A8: lwc1        $f0, 0x4C($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X4C);
    // 0x800508AC: lwc1        $f2, 0x50($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X50);
    // 0x800508B0: lwc1        $f6, 0xA0($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XA0);
    // 0x800508B4: lwc1        $f4, 0x54($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X54);
    // 0x800508B8: mov.s       $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = ctx->f6.fl;
    // 0x800508BC: swc1        $f0, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f0.u32l;
    // 0x800508C0: swc1        $f2, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f2.u32l;
    // 0x800508C4: swc1        $f4, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f4.u32l;
    // 0x800508C8: swc1        $f6, 0x98($s0)
    MEM_W(0X98, ctx->r16) = ctx->f6.u32l;
    // 0x800508CC: swc1        $f8, 0x9C($s0)
    MEM_W(0X9C, ctx->r16) = ctx->f8.u32l;
    // 0x800508D0: jal         0x80066A50
    // 0x800508D4: sw          $a2, 0x4($s2)
    MEM_W(0X4, ctx->r18) = ctx->r6;
    func_80066A50(rdram, ctx);
        goto after_8;
    // 0x800508D4: sw          $a2, 0x4($s2)
    MEM_W(0X4, ctx->r18) = ctx->r6;
    after_8:
L_800508D8:
    // 0x800508D8: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x800508DC: lw          $v0, -0x35E4($fp)
    ctx->r2 = MEM_W(ctx->r30, -0X35E4);
    // 0x800508E0: addiu       $v1, $zero, -0x101
    ctx->r3 = ADD32(0, -0X101);
    // 0x800508E4: j           L_80050A58
    // 0x800508E8: sw          $t0, 0x1C8($s7)
    MEM_W(0X1C8, ctx->r23) = ctx->r8;
        goto L_80050A58;
    // 0x800508E8: sw          $t0, 0x1C8($s7)
    MEM_W(0X1C8, ctx->r23) = ctx->r8;
L_800508EC:
    // 0x800508EC: lhu         $v0, 0xC($s5)
    ctx->r2 = MEM_HU(ctx->r21, 0XC);
    // 0x800508F0: and         $v0, $v1, $v0
    ctx->r2 = ctx->r3 & ctx->r2;
    // 0x800508F4: beq         $v0, $zero, L_80050A60
    if (ctx->r2 == 0) {
        // 0x800508F8: lui         $v0, 0x8014
        ctx->r2 = S32(0X8014 << 16);
            goto L_80050A60;
    }
    // 0x800508F8: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x800508FC: addiu       $v0, $v0, -0x7BA8
    ctx->r2 = ADD32(ctx->r2, -0X7BA8);
    // 0x80050900: addu        $s0, $s4, $v0
    ctx->r16 = ADD32(ctx->r20, ctx->r2);
    // 0x80050904: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80050908: lwc1        $f0, -0x5600($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X5600);
    // 0x8005090C: beq         $a1, $s0, L_80050A48
    if (ctx->r5 == ctx->r16) {
        // 0x80050910: addiu       $v0, $zero, 0x4
        ctx->r2 = ADD32(0, 0X4);
            goto L_80050A48;
    }
    // 0x80050910: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // 0x80050914: sh          $v0, 0x2($s1)
    MEM_H(0X2, ctx->r17) = ctx->r2;
    // 0x80050918: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x8005091C: addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    // 0x80050920: lhu         $v1, 0x0($s1)
    ctx->r3 = MEM_HU(ctx->r17, 0X0);
    // 0x80050924: lw          $v0, -0x7DA0($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7DA0);
    // 0x80050928: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8005092C: sw          $a1, 0xBC($s1)
    MEM_W(0XBC, ctx->r17) = ctx->r5;
    // 0x80050930: sw          $s0, 0xC0($s1)
    MEM_W(0XC0, ctx->r17) = ctx->r16;
    // 0x80050934: sw          $zero, 0xC4($s1)
    MEM_W(0XC4, ctx->r17) = 0;
    // 0x80050938: swc1        $f0, 0xC8($s1)
    MEM_W(0XC8, ctx->r17) = ctx->f0.u32l;
    // 0x8005093C: sw          $zero, 0xCC($s1)
    MEM_W(0XCC, ctx->r17) = 0;
    // 0x80050940: sw          $s3, 0x74($s1)
    MEM_W(0X74, ctx->r17) = ctx->r19;
    // 0x80050944: ori         $v1, $v1, 0x1
    ctx->r3 = ctx->r3 | 0X1;
    // 0x80050948: bne         $v0, $t1, L_8005095C
    if (ctx->r2 != ctx->r9) {
        // 0x8005094C: sh          $v1, 0x0($s1)
        MEM_H(0X0, ctx->r17) = ctx->r3;
            goto L_8005095C;
    }
    // 0x8005094C: sh          $v1, 0x0($s1)
    MEM_H(0X0, ctx->r17) = ctx->r3;
    // 0x80050950: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x80050954: lw          $v0, -0x776C($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X776C);
    // 0x80050958: sw          $s1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r17;
L_8005095C:
    // 0x8005095C: sw          $s1, 0x4($s2)
    MEM_W(0X4, ctx->r18) = ctx->r17;
    // 0x80050960: addiu       $v1, $a2, 0x28
    ctx->r3 = ADD32(ctx->r6, 0X28);
    // 0x80050964: addiu       $v0, $a1, 0x28
    ctx->r2 = ADD32(ctx->r5, 0X28);
    // 0x80050968: addiu       $a0, $a1, 0x58
    ctx->r4 = ADD32(ctx->r5, 0X58);
L_8005096C:
    // 0x8005096C: lw          $t2, 0x0($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X0);
    // 0x80050970: lw          $a3, 0x4($v0)
    ctx->r7 = MEM_W(ctx->r2, 0X4);
    // 0x80050974: lw          $t0, 0x8($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X8);
    // 0x80050978: lw          $t1, 0xC($v0)
    ctx->r9 = MEM_W(ctx->r2, 0XC);
    // 0x8005097C: sw          $t2, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r10;
    // 0x80050980: sw          $a3, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r7;
    // 0x80050984: sw          $t0, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r8;
    // 0x80050988: sw          $t1, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r9;
    // 0x8005098C: addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
    // 0x80050990: bne         $v0, $a0, L_8005096C
    if (ctx->r2 != ctx->r4) {
        // 0x80050994: addiu       $v1, $v1, 0x10
        ctx->r3 = ADD32(ctx->r3, 0X10);
            goto L_8005096C;
    }
    // 0x80050994: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
    // 0x80050998: addiu       $a0, $s0, 0x28
    ctx->r4 = ADD32(ctx->r16, 0X28);
    // 0x8005099C: lw          $t2, 0x10($a1)
    ctx->r10 = MEM_W(ctx->r5, 0X10);
    // 0x800509A0: lw          $a3, 0x14($a1)
    ctx->r7 = MEM_W(ctx->r5, 0X14);
    // 0x800509A4: lw          $t0, 0x18($a1)
    ctx->r8 = MEM_W(ctx->r5, 0X18);
    // 0x800509A8: sw          $t2, 0x10($a2)
    MEM_W(0X10, ctx->r6) = ctx->r10;
    // 0x800509AC: sw          $a3, 0x14($a2)
    MEM_W(0X14, ctx->r6) = ctx->r7;
    // 0x800509B0: sw          $t0, 0x18($a2)
    MEM_W(0X18, ctx->r6) = ctx->r8;
    // 0x800509B4: lw          $t2, 0x1C($a1)
    ctx->r10 = MEM_W(ctx->r5, 0X1C);
    // 0x800509B8: lw          $a3, 0x20($a1)
    ctx->r7 = MEM_W(ctx->r5, 0X20);
    // 0x800509BC: lw          $t0, 0x24($a1)
    ctx->r8 = MEM_W(ctx->r5, 0X24);
    // 0x800509C0: sw          $t2, 0x1C($a2)
    MEM_W(0X1C, ctx->r6) = ctx->r10;
    // 0x800509C4: sw          $a3, 0x20($a2)
    MEM_W(0X20, ctx->r6) = ctx->r7;
    // 0x800509C8: sw          $t0, 0x24($a2)
    MEM_W(0X24, ctx->r6) = ctx->r8;
    // 0x800509CC: lhu         $v0, 0x0($a1)
    ctx->r2 = MEM_HU(ctx->r5, 0X0);
    // 0x800509D0: addiu       $v1, $a1, 0x28
    ctx->r3 = ADD32(ctx->r5, 0X28);
    // 0x800509D4: ori         $v0, $v0, 0x1
    ctx->r2 = ctx->r2 | 0X1;
    // 0x800509D8: sh          $v0, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r2;
    // 0x800509DC: lhu         $v0, 0x0($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X0);
    // 0x800509E0: addiu       $a1, $a1, 0x58
    ctx->r5 = ADD32(ctx->r5, 0X58);
    // 0x800509E4: ori         $v0, $v0, 0x1
    ctx->r2 = ctx->r2 | 0X1;
    // 0x800509E8: sh          $v0, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r2;
L_800509EC:
    // 0x800509EC: lw          $t2, 0x0($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X0);
    // 0x800509F0: lw          $a3, 0x4($v1)
    ctx->r7 = MEM_W(ctx->r3, 0X4);
    // 0x800509F4: lw          $t0, 0x8($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X8);
    // 0x800509F8: lw          $t1, 0xC($v1)
    ctx->r9 = MEM_W(ctx->r3, 0XC);
    // 0x800509FC: sw          $t2, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r10;
    // 0x80050A00: sw          $a3, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r7;
    // 0x80050A04: sw          $t0, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r8;
    // 0x80050A08: sw          $t1, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r9;
    // 0x80050A0C: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
    // 0x80050A10: bne         $v1, $a1, L_800509EC
    if (ctx->r3 != ctx->r5) {
        // 0x80050A14: addiu       $a0, $a0, 0x10
        ctx->r4 = ADD32(ctx->r4, 0X10);
            goto L_800509EC;
    }
    // 0x80050A14: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    // 0x80050A18: lwc1        $f0, 0x4C($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X4C);
    // 0x80050A1C: lwc1        $f2, 0x50($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X50);
    // 0x80050A20: lwc1        $f6, 0xA0($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XA0);
    // 0x80050A24: lwc1        $f4, 0x54($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X54);
    // 0x80050A28: mov.s       $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = ctx->f6.fl;
    // 0x80050A2C: swc1        $f0, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f0.u32l;
    // 0x80050A30: swc1        $f2, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f2.u32l;
    // 0x80050A34: swc1        $f4, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f4.u32l;
    // 0x80050A38: swc1        $f6, 0x98($s0)
    MEM_W(0X98, ctx->r16) = ctx->f6.u32l;
    // 0x80050A3C: swc1        $f8, 0x9C($s0)
    MEM_W(0X9C, ctx->r16) = ctx->f8.u32l;
    // 0x80050A40: jal         0x80066A50
    // 0x80050A44: sw          $a2, 0x4($s2)
    MEM_W(0X4, ctx->r18) = ctx->r6;
    func_80066A50(rdram, ctx);
        goto after_9;
    // 0x80050A44: sw          $a2, 0x4($s2)
    MEM_W(0X4, ctx->r18) = ctx->r6;
    after_9:
L_80050A48:
    // 0x80050A48: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x80050A4C: sw          $v0, 0x1C8($s7)
    MEM_W(0X1C8, ctx->r23) = ctx->r2;
    // 0x80050A50: lw          $v0, -0x35E4($fp)
    ctx->r2 = MEM_W(ctx->r30, -0X35E4);
    // 0x80050A54: addiu       $v1, $zero, -0x101
    ctx->r3 = ADD32(0, -0X101);
L_80050A58:
    // 0x80050A58: and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // 0x80050A5C: sw          $v0, -0x35E4($fp)
    MEM_W(-0X35E4, ctx->r30) = ctx->r2;
L_80050A60:
    // 0x80050A60: addiu       $s2, $s2, 0x144
    ctx->r18 = ADD32(ctx->r18, 0X144);
L_80050A64:
    // 0x80050A64: addiu       $s1, $s1, 0x3E0
    ctx->r17 = ADD32(ctx->r17, 0X3E0);
L_80050A68:
    // 0x80050A68: addiu       $s3, $s3, 0x2A0
    ctx->r19 = ADD32(ctx->r19, 0X2A0);
    // 0x80050A6C: addiu       $s4, $s4, 0x5D0
    ctx->r20 = ADD32(ctx->r20, 0X5D0);
    // 0x80050A70: addiu       $s5, $s5, 0x24
    ctx->r21 = ADD32(ctx->r21, 0X24);
    // 0x80050A74: addiu       $s7, $s7, 0x2A0
    ctx->r23 = ADD32(ctx->r23, 0X2A0);
    // 0x80050A78: addiu       $s6, $s6, 0x1
    ctx->r22 = ADD32(ctx->r22, 0X1);
    // 0x80050A7C: lw          $t2, 0x10($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X10);
    // 0x80050A80: lw          $a3, 0x14($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X14);
    // 0x80050A84: addiu       $t2, $t2, 0x2A0
    ctx->r10 = ADD32(ctx->r10, 0X2A0);
    // 0x80050A88: addiu       $a3, $a3, 0x3
    ctx->r7 = ADD32(ctx->r7, 0X3);
    // 0x80050A8C: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x80050A90: blez        $s6, L_80050178
    if (SIGNED(ctx->r22) <= 0) {
        // 0x80050A94: sw          $a3, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r7;
            goto L_80050178;
    }
    // 0x80050A94: sw          $a3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r7;
L_80050A98:
    // 0x80050A98: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x80050A9C: lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X38);
    // 0x80050AA0: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x80050AA4: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x80050AA8: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x80050AAC: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x80050AB0: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x80050AB4: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80050AB8: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80050ABC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80050AC0: jr          $ra
    // 0x80050AC4: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x80050AC4: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void func_80050AC8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80050AC8: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80050ACC: sw          $s4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r20;
    // 0x80050AD0: addu        $s4, $a0, $zero
    ctx->r20 = ADD32(ctx->r4, 0);
    // 0x80050AD4: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x80050AD8: addiu       $v0, $v0, -0x72E8
    ctx->r2 = ADD32(ctx->r2, -0X72E8);
    // 0x80050ADC: sll         $v1, $s4, 2
    ctx->r3 = S32(ctx->r20 << 2);
    // 0x80050AE0: addu        $v1, $v1, $s4
    ctx->r3 = ADD32(ctx->r3, ctx->r20);
    // 0x80050AE4: sll         $v1, $v1, 4
    ctx->r3 = S32(ctx->r3 << 4);
    // 0x80050AE8: addu        $v1, $v1, $s4
    ctx->r3 = ADD32(ctx->r3, ctx->r20);
    // 0x80050AEC: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x80050AF0: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x80050AF4: sll         $v0, $s4, 1
    ctx->r2 = S32(ctx->r20 << 1);
    // 0x80050AF8: addu        $v0, $v0, $s4
    ctx->r2 = ADD32(ctx->r2, ctx->r20);
    // 0x80050AFC: sll         $a0, $v0, 5
    ctx->r4 = S32(ctx->r2 << 5);
    // 0x80050B00: subu        $a0, $a0, $v0
    ctx->r4 = SUB32(ctx->r4, ctx->r2);
    // 0x80050B04: sll         $a0, $a0, 4
    ctx->r4 = S32(ctx->r4 << 4);
    // 0x80050B08: lui         $a1, 0x8014
    ctx->r5 = S32(0X8014 << 16);
    // 0x80050B0C: addiu       $a1, $a1, -0x7BA8
    ctx->r5 = ADD32(ctx->r5, -0X7BA8);
    // 0x80050B10: addu        $v0, $a0, $a1
    ctx->r2 = ADD32(ctx->r4, ctx->r5);
    // 0x80050B14: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x80050B18: addu        $s1, $zero, $zero
    ctx->r17 = ADD32(0, 0);
    // 0x80050B1C: sw          $s6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r22;
    // 0x80050B20: addu        $s6, $a0, $zero
    ctx->r22 = ADD32(ctx->r4, 0);
    // 0x80050B24: sw          $ra, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r31;
    // 0x80050B28: sw          $s7, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r23;
    // 0x80050B2C: sw          $s5, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r21;
    // 0x80050B30: sw          $s3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r19;
    // 0x80050B34: sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // 0x80050B38: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x80050B3C: sw          $v0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r2;
    // 0x80050B40: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x80050B44: addiu       $s5, $v0, -0x13EC
    ctx->r21 = ADD32(ctx->r2, -0X13EC);
    // 0x80050B48: addiu       $s3, $a1, -0x1F0
    ctx->r19 = ADD32(ctx->r5, -0X1F0);
    // 0x80050B4C: addu        $s2, $s3, $zero
    ctx->r18 = ADD32(ctx->r19, 0);
L_80050B50:
    // 0x80050B50: addu        $s0, $s6, $s2
    ctx->r16 = ADD32(ctx->r22, ctx->r18);
    // 0x80050B54: addiu       $a0, $s0, 0x28
    ctx->r4 = ADD32(ctx->r16, 0X28);
    // 0x80050B58: sw          $s1, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r17;
    // 0x80050B5C: sw          $s4, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r20;
    // 0x80050B60: sh          $zero, 0x2($s0)
    MEM_H(0X2, ctx->r16) = 0;
    // 0x80050B64: sh          $zero, 0x4($s0)
    MEM_H(0X4, ctx->r16) = 0;
    // 0x80050B68: jal         0x8001CA50
    // 0x80050B6C: sh          $zero, 0x0($s0)
    MEM_H(0X0, ctx->r16) = 0;
    func_8001CA50(rdram, ctx);
        goto after_0;
    // 0x80050B6C: sh          $zero, 0x0($s0)
    MEM_H(0X0, ctx->r16) = 0;
    after_0:
    // 0x80050B70: addiu       $s2, $s2, 0xF8
    ctx->r18 = ADD32(ctx->r18, 0XF8);
    // 0x80050B74: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80050B78: lwc1        $f0, -0x55FC($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X55FC);
    // 0x80050B7C: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80050B80: lwc1        $f2, -0x55F8($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X55F8);
    // 0x80050B84: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80050B88: lwc1        $f4, -0x55F4($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X55F4);
    // 0x80050B8C: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80050B90: lwc1        $f6, -0x55F0($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X55F0);
    // 0x80050B94: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80050B98: lwc1        $f8, -0x55EC($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X55EC);
    // 0x80050B9C: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80050BA0: lwc1        $f10, -0x55E8($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X55E8);
    // 0x80050BA4: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80050BA8: lwc1        $f12, -0x55E4($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X55E4);
    // 0x80050BAC: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80050BB0: swc1        $f0, 0xC8($s0)
    MEM_W(0XC8, ctx->r16) = ctx->f0.u32l;
    // 0x80050BB4: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80050BB8: lwc1        $f0, -0x55E0($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X55E0);
    // 0x80050BBC: ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
    // 0x80050BC0: sw          $zero, 0x58($s0)
    MEM_W(0X58, ctx->r16) = 0;
    // 0x80050BC4: sw          $zero, 0x5C($s0)
    MEM_W(0X5C, ctx->r16) = 0;
    // 0x80050BC8: sw          $zero, 0x60($s0)
    MEM_W(0X60, ctx->r16) = 0;
    // 0x80050BCC: sw          $zero, 0x64($s0)
    MEM_W(0X64, ctx->r16) = 0;
    // 0x80050BD0: sw          $zero, 0x68($s0)
    MEM_W(0X68, ctx->r16) = 0;
    // 0x80050BD4: sw          $zero, 0x6C($s0)
    MEM_W(0X6C, ctx->r16) = 0;
    // 0x80050BD8: sw          $zero, 0x78($s0)
    MEM_W(0X78, ctx->r16) = 0;
    // 0x80050BDC: sw          $zero, 0x7C($s0)
    MEM_W(0X7C, ctx->r16) = 0;
    // 0x80050BE0: sw          $zero, 0x80($s0)
    MEM_W(0X80, ctx->r16) = 0;
    // 0x80050BE4: sw          $zero, 0x84($s0)
    MEM_W(0X84, ctx->r16) = 0;
    // 0x80050BE8: sw          $zero, 0x88($s0)
    MEM_W(0X88, ctx->r16) = 0;
    // 0x80050BEC: sw          $zero, 0x8C($s0)
    MEM_W(0X8C, ctx->r16) = 0;
    // 0x80050BF0: sw          $zero, 0x10($s0)
    MEM_W(0X10, ctx->r16) = 0;
    // 0x80050BF4: sw          $zero, 0x14($s0)
    MEM_W(0X14, ctx->r16) = 0;
    // 0x80050BF8: sw          $zero, 0x18($s0)
    MEM_W(0X18, ctx->r16) = 0;
    // 0x80050BFC: sw          $zero, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = 0;
    // 0x80050C00: sw          $zero, 0x20($s0)
    MEM_W(0X20, ctx->r16) = 0;
    // 0x80050C04: sw          $zero, 0x24($s0)
    MEM_W(0X24, ctx->r16) = 0;
    // 0x80050C08: sw          $s5, 0x70($s0)
    MEM_W(0X70, ctx->r16) = ctx->r21;
    // 0x80050C0C: sw          $s5, 0x74($s0)
    MEM_W(0X74, ctx->r16) = ctx->r21;
    // 0x80050C10: sw          $zero, 0x90($s0)
    MEM_W(0X90, ctx->r16) = 0;
    // 0x80050C14: sw          $zero, 0x94($s0)
    MEM_W(0X94, ctx->r16) = 0;
    // 0x80050C18: sw          $zero, 0x98($s0)
    MEM_W(0X98, ctx->r16) = 0;
    // 0x80050C1C: sw          $zero, 0x9C($s0)
    MEM_W(0X9C, ctx->r16) = 0;
    // 0x80050C20: sw          $zero, 0xA0($s0)
    MEM_W(0XA0, ctx->r16) = 0;
    // 0x80050C24: sw          $s3, 0xBC($s0)
    MEM_W(0XBC, ctx->r16) = ctx->r19;
    // 0x80050C28: sw          $s3, 0xC0($s0)
    MEM_W(0XC0, ctx->r16) = ctx->r19;
    // 0x80050C2C: sw          $zero, 0xC4($s0)
    MEM_W(0XC4, ctx->r16) = 0;
    // 0x80050C30: sw          $zero, 0xCC($s0)
    MEM_W(0XCC, ctx->r16) = 0;
    // 0x80050C34: sw          $zero, 0xD0($s0)
    MEM_W(0XD0, ctx->r16) = 0;
    // 0x80050C38: sw          $zero, 0xD8($s0)
    MEM_W(0XD8, ctx->r16) = 0;
    // 0x80050C3C: sw          $zero, 0xE0($s0)
    MEM_W(0XE0, ctx->r16) = 0;
    // 0x80050C40: sw          $zero, 0xDC($s0)
    MEM_W(0XDC, ctx->r16) = 0;
    // 0x80050C44: sh          $v0, 0xF4($s0)
    MEM_H(0XF4, ctx->r16) = ctx->r2;
    // 0x80050C48: slti        $v0, $s1, 0x6
    ctx->r2 = SIGNED(ctx->r17) < 0X6 ? 1 : 0;
    // 0x80050C4C: swc1        $f2, 0xD4($s0)
    MEM_W(0XD4, ctx->r16) = ctx->f2.u32l;
    // 0x80050C50: swc1        $f4, 0xE4($s0)
    MEM_W(0XE4, ctx->r16) = ctx->f4.u32l;
    // 0x80050C54: swc1        $f6, 0xE8($s0)
    MEM_W(0XE8, ctx->r16) = ctx->f6.u32l;
    // 0x80050C58: swc1        $f8, 0xA4($s0)
    MEM_W(0XA4, ctx->r16) = ctx->f8.u32l;
    // 0x80050C5C: sw          $zero, 0xA8($s0)
    MEM_W(0XA8, ctx->r16) = 0;
    // 0x80050C60: swc1        $f10, 0xAC($s0)
    MEM_W(0XAC, ctx->r16) = ctx->f10.u32l;
    // 0x80050C64: swc1        $f12, 0xB0($s0)
    MEM_W(0XB0, ctx->r16) = ctx->f12.u32l;
    // 0x80050C68: sw          $zero, 0xEC($s0)
    MEM_W(0XEC, ctx->r16) = 0;
    // 0x80050C6C: sw          $zero, 0xF0($s0)
    MEM_W(0XF0, ctx->r16) = 0;
    // 0x80050C70: sw          $zero, 0xB4($s0)
    MEM_W(0XB4, ctx->r16) = 0;
    // 0x80050C74: bne         $v0, $zero, L_80050B50
    if (ctx->r2 != 0) {
        // 0x80050C78: swc1        $f0, 0xB8($s0)
        MEM_W(0XB8, ctx->r16) = ctx->f0.u32l;
            goto L_80050B50;
    }
    // 0x80050C78: swc1        $f0, 0xB8($s0)
    MEM_W(0XB8, ctx->r16) = ctx->f0.u32l;
    // 0x80050C7C: addu        $s1, $zero, $zero
    ctx->r17 = ADD32(0, 0);
    // 0x80050C80: sll         $v0, $s4, 5
    ctx->r2 = S32(ctx->r20 << 5);
    // 0x80050C84: subu        $v0, $v0, $s4
    ctx->r2 = SUB32(ctx->r2, ctx->r20);
    // 0x80050C88: sll         $s7, $v0, 5
    ctx->r23 = S32(ctx->r2 << 5);
    // 0x80050C8C: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x80050C90: addiu       $s6, $v0, -0x13EC
    ctx->r22 = ADD32(ctx->r2, -0X13EC);
    // 0x80050C94: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x80050C98: addiu       $s5, $v0, -0x7D98
    ctx->r21 = ADD32(ctx->r2, -0X7D98);
    // 0x80050C9C: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x80050CA0: addiu       $s3, $v0, -0x76D0
    ctx->r19 = ADD32(ctx->r2, -0X76D0);
L_80050CA4:
    // 0x80050CA4: addu        $s0, $s7, $s3
    ctx->r16 = ADD32(ctx->r23, ctx->r19);
    // 0x80050CA8: addiu       $a0, $s0, 0x28
    ctx->r4 = ADD32(ctx->r16, 0X28);
    // 0x80050CAC: sw          $s1, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r17;
    // 0x80050CB0: sw          $s4, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r20;
    // 0x80050CB4: sh          $zero, 0x2($s0)
    MEM_H(0X2, ctx->r16) = 0;
    // 0x80050CB8: sh          $zero, 0x4($s0)
    MEM_H(0X4, ctx->r16) = 0;
    // 0x80050CBC: jal         0x8001CA50
    // 0x80050CC0: sh          $zero, 0x0($s0)
    MEM_H(0X0, ctx->r16) = 0;
    func_8001CA50(rdram, ctx);
        goto after_1;
    // 0x80050CC0: sh          $zero, 0x0($s0)
    MEM_H(0X0, ctx->r16) = 0;
    after_1:
    // 0x80050CC4: addiu       $s3, $s3, 0xF8
    ctx->r19 = ADD32(ctx->r19, 0XF8);
    // 0x80050CC8: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80050CCC: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80050CD0: lwc1        $f0, -0x55DC($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X55DC);
    // 0x80050CD4: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80050CD8: lwc1        $f2, -0x55D8($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X55D8);
    // 0x80050CDC: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80050CE0: lwc1        $f4, -0x55D4($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X55D4);
    // 0x80050CE4: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80050CE8: lwc1        $f6, -0x55D0($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X55D0);
    // 0x80050CEC: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80050CF0: lwc1        $f8, -0x55CC($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X55CC);
    // 0x80050CF4: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80050CF8: lwc1        $f10, -0x55C8($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X55C8);
    // 0x80050CFC: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80050D00: lwc1        $f12, -0x55C4($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X55C4);
    // 0x80050D04: ori         $s2, $zero, 0xFFFF
    ctx->r18 = 0 | 0XFFFF;
    // 0x80050D08: swc1        $f0, 0xC8($s0)
    MEM_W(0XC8, ctx->r16) = ctx->f0.u32l;
    // 0x80050D0C: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80050D10: lwc1        $f0, -0x55C0($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X55C0);
    // 0x80050D14: addiu       $v0, $zero, 0x10
    ctx->r2 = ADD32(0, 0X10);
    // 0x80050D18: sw          $zero, 0x58($s0)
    MEM_W(0X58, ctx->r16) = 0;
    // 0x80050D1C: sw          $zero, 0x5C($s0)
    MEM_W(0X5C, ctx->r16) = 0;
    // 0x80050D20: sw          $zero, 0x60($s0)
    MEM_W(0X60, ctx->r16) = 0;
    // 0x80050D24: sw          $zero, 0x64($s0)
    MEM_W(0X64, ctx->r16) = 0;
    // 0x80050D28: sw          $zero, 0x68($s0)
    MEM_W(0X68, ctx->r16) = 0;
    // 0x80050D2C: sw          $zero, 0x6C($s0)
    MEM_W(0X6C, ctx->r16) = 0;
    // 0x80050D30: sw          $zero, 0x78($s0)
    MEM_W(0X78, ctx->r16) = 0;
    // 0x80050D34: sw          $zero, 0x7C($s0)
    MEM_W(0X7C, ctx->r16) = 0;
    // 0x80050D38: sw          $zero, 0x80($s0)
    MEM_W(0X80, ctx->r16) = 0;
    // 0x80050D3C: sw          $zero, 0x84($s0)
    MEM_W(0X84, ctx->r16) = 0;
    // 0x80050D40: sw          $zero, 0x88($s0)
    MEM_W(0X88, ctx->r16) = 0;
    // 0x80050D44: sw          $zero, 0x8C($s0)
    MEM_W(0X8C, ctx->r16) = 0;
    // 0x80050D48: sw          $zero, 0x10($s0)
    MEM_W(0X10, ctx->r16) = 0;
    // 0x80050D4C: sw          $zero, 0x14($s0)
    MEM_W(0X14, ctx->r16) = 0;
    // 0x80050D50: sw          $zero, 0x18($s0)
    MEM_W(0X18, ctx->r16) = 0;
    // 0x80050D54: sw          $zero, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = 0;
    // 0x80050D58: sw          $zero, 0x20($s0)
    MEM_W(0X20, ctx->r16) = 0;
    // 0x80050D5C: sw          $zero, 0x24($s0)
    MEM_W(0X24, ctx->r16) = 0;
    // 0x80050D60: sw          $s6, 0x70($s0)
    MEM_W(0X70, ctx->r16) = ctx->r22;
    // 0x80050D64: sw          $s6, 0x74($s0)
    MEM_W(0X74, ctx->r16) = ctx->r22;
    // 0x80050D68: sw          $zero, 0x90($s0)
    MEM_W(0X90, ctx->r16) = 0;
    // 0x80050D6C: sw          $zero, 0x94($s0)
    MEM_W(0X94, ctx->r16) = 0;
    // 0x80050D70: sw          $zero, 0x98($s0)
    MEM_W(0X98, ctx->r16) = 0;
    // 0x80050D74: sw          $zero, 0x9C($s0)
    MEM_W(0X9C, ctx->r16) = 0;
    // 0x80050D78: sw          $zero, 0xA0($s0)
    MEM_W(0XA0, ctx->r16) = 0;
    // 0x80050D7C: sw          $s5, 0xBC($s0)
    MEM_W(0XBC, ctx->r16) = ctx->r21;
    // 0x80050D80: sw          $s5, 0xC0($s0)
    MEM_W(0XC0, ctx->r16) = ctx->r21;
    // 0x80050D84: sw          $zero, 0xC4($s0)
    MEM_W(0XC4, ctx->r16) = 0;
    // 0x80050D88: sw          $zero, 0xCC($s0)
    MEM_W(0XCC, ctx->r16) = 0;
    // 0x80050D8C: sw          $zero, 0xD0($s0)
    MEM_W(0XD0, ctx->r16) = 0;
    // 0x80050D90: sw          $zero, 0xD8($s0)
    MEM_W(0XD8, ctx->r16) = 0;
    // 0x80050D94: sw          $zero, 0xE0($s0)
    MEM_W(0XE0, ctx->r16) = 0;
    // 0x80050D98: sw          $zero, 0xDC($s0)
    MEM_W(0XDC, ctx->r16) = 0;
    // 0x80050D9C: sh          $v0, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r2;
    // 0x80050DA0: slti        $v0, $s1, 0x4
    ctx->r2 = SIGNED(ctx->r17) < 0X4 ? 1 : 0;
    // 0x80050DA4: swc1        $f2, 0xD4($s0)
    MEM_W(0XD4, ctx->r16) = ctx->f2.u32l;
    // 0x80050DA8: swc1        $f4, 0xE4($s0)
    MEM_W(0XE4, ctx->r16) = ctx->f4.u32l;
    // 0x80050DAC: swc1        $f6, 0xE8($s0)
    MEM_W(0XE8, ctx->r16) = ctx->f6.u32l;
    // 0x80050DB0: swc1        $f8, 0xA4($s0)
    MEM_W(0XA4, ctx->r16) = ctx->f8.u32l;
    // 0x80050DB4: sw          $zero, 0xA8($s0)
    MEM_W(0XA8, ctx->r16) = 0;
    // 0x80050DB8: swc1        $f10, 0xAC($s0)
    MEM_W(0XAC, ctx->r16) = ctx->f10.u32l;
    // 0x80050DBC: swc1        $f12, 0xB0($s0)
    MEM_W(0XB0, ctx->r16) = ctx->f12.u32l;
    // 0x80050DC0: sw          $zero, 0xEC($s0)
    MEM_W(0XEC, ctx->r16) = 0;
    // 0x80050DC4: sh          $s2, 0xF4($s0)
    MEM_H(0XF4, ctx->r16) = ctx->r18;
    // 0x80050DC8: sw          $zero, 0xF0($s0)
    MEM_W(0XF0, ctx->r16) = 0;
    // 0x80050DCC: sw          $zero, 0xB4($s0)
    MEM_W(0XB4, ctx->r16) = 0;
    // 0x80050DD0: bne         $v0, $zero, L_80050CA4
    if (ctx->r2 != 0) {
        // 0x80050DD4: swc1        $f0, 0xB8($s0)
        MEM_W(0XB8, ctx->r16) = ctx->f0.u32l;
            goto L_80050CA4;
    }
    // 0x80050DD4: swc1        $f0, 0xB8($s0)
    MEM_W(0XB8, ctx->r16) = ctx->f0.u32l;
    // 0x80050DD8: jal         0x80066A50
    // 0x80050DDC: nop

    func_80066A50(rdram, ctx);
        goto after_2;
    // 0x80050DDC: nop

    after_2:
    // 0x80050DE0: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80050DE4: addiu       $a0, $a0, 0x7A80
    ctx->r4 = ADD32(ctx->r4, 0X7A80);
    // 0x80050DE8: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x80050DEC: sb          $zero, -0x1444($v0)
    MEM_B(-0X1444, ctx->r2) = 0;
    // 0x80050DF0: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x80050DF4: jal         0x8001CA50
    // 0x80050DF8: sh          $s2, -0x143C($v0)
    MEM_H(-0X143C, ctx->r2) = ctx->r18;
    func_8001CA50(rdram, ctx);
        goto after_3;
    // 0x80050DF8: sh          $s2, -0x143C($v0)
    MEM_H(-0X143C, ctx->r2) = ctx->r18;
    after_3:
    // 0x80050DFC: lw          $ra, 0x30($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X30);
    // 0x80050E00: lw          $s7, 0x2C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X2C);
    // 0x80050E04: lw          $s6, 0x28($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X28);
    // 0x80050E08: lw          $s5, 0x24($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X24);
    // 0x80050E0C: lw          $s4, 0x20($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X20);
    // 0x80050E10: lw          $s3, 0x1C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X1C);
    // 0x80050E14: lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X18);
    // 0x80050E18: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x80050E1C: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x80050E20: jr          $ra
    // 0x80050E24: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x80050E24: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_80050E28(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80050E28: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80050E2C: sw          $s4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r20;
    // 0x80050E30: addu        $s4, $a0, $zero
    ctx->r20 = ADD32(ctx->r4, 0);
    // 0x80050E34: sll         $v0, $s4, 1
    ctx->r2 = S32(ctx->r20 << 1);
    // 0x80050E38: addu        $v0, $v0, $s4
    ctx->r2 = ADD32(ctx->r2, ctx->r20);
    // 0x80050E3C: sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // 0x80050E40: sll         $s2, $v0, 5
    ctx->r18 = S32(ctx->r2 << 5);
    // 0x80050E44: subu        $s2, $s2, $v0
    ctx->r18 = SUB32(ctx->r18, ctx->r2);
    // 0x80050E48: sll         $s2, $s2, 4
    ctx->r18 = S32(ctx->r18 << 4);
    // 0x80050E4C: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x80050E50: lui         $s1, 0x8014
    ctx->r17 = S32(0X8014 << 16);
    // 0x80050E54: addiu       $s1, $s1, -0x78C0
    ctx->r17 = ADD32(ctx->r17, -0X78C0);
    // 0x80050E58: addu        $a1, $s2, $s1
    ctx->r5 = ADD32(ctx->r18, ctx->r17);
    // 0x80050E5C: lui         $v1, 0x8014
    ctx->r3 = S32(0X8014 << 16);
    // 0x80050E60: addiu       $v1, $v1, -0x72E8
    ctx->r3 = ADD32(ctx->r3, -0X72E8);
    // 0x80050E64: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x80050E68: sll         $s0, $s4, 2
    ctx->r16 = S32(ctx->r20 << 2);
    // 0x80050E6C: addu        $s0, $s0, $s4
    ctx->r16 = ADD32(ctx->r16, ctx->r20);
    // 0x80050E70: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80050E74: sw          $s3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r19;
    // 0x80050E78: sdc1        $f20, 0x28($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X28, ctx->r29);
    // 0x80050E7C: lhu         $v0, 0x0($a1)
    ctx->r2 = MEM_HU(ctx->r5, 0X0);
    // 0x80050E80: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x80050E84: ori         $v0, $v0, 0x400
    ctx->r2 = ctx->r2 | 0X400;
    // 0x80050E88: sh          $v0, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r2;
    // 0x80050E8C: sll         $v0, $s0, 4
    ctx->r2 = S32(ctx->r16 << 4);
    // 0x80050E90: addu        $v0, $v0, $s4
    ctx->r2 = ADD32(ctx->r2, ctx->r20);
    // 0x80050E94: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80050E98: addu        $s3, $v0, $v1
    ctx->r19 = ADD32(ctx->r2, ctx->r3);
    // 0x80050E9C: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x80050EA0: addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    // 0x80050EA4: jal         0x8004E140
    // 0x80050EA8: sw          $a1, 0x4($s3)
    MEM_W(0X4, ctx->r19) = ctx->r5;
    func_8004E140(rdram, ctx);
        goto after_0;
    // 0x80050EA8: sw          $a1, 0x4($s3)
    MEM_W(0X4, ctx->r19) = ctx->r5;
    after_0:
    // 0x80050EAC: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80050EB0: addiu       $a0, $a0, 0x7DB8
    ctx->r4 = ADD32(ctx->r4, 0X7DB8);
    // 0x80050EB4: sll         $s0, $s0, 2
    ctx->r16 = S32(ctx->r16 << 2);
    // 0x80050EB8: addu        $s0, $s0, $s4
    ctx->r16 = ADD32(ctx->r16, ctx->r20);
    // 0x80050EBC: sll         $s0, $s0, 5
    ctx->r16 = S32(ctx->r16 << 5);
    // 0x80050EC0: addu        $v0, $s0, $a0
    ctx->r2 = ADD32(ctx->r16, ctx->r4);
    // 0x80050EC4: addiu       $s1, $s1, -0x4D8
    ctx->r17 = ADD32(ctx->r17, -0X4D8);
    // 0x80050EC8: addiu       $a0, $a0, 0x254
    ctx->r4 = ADD32(ctx->r4, 0X254);
    // 0x80050ECC: lw          $v1, 0x1CC($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X1CC);
    // 0x80050ED0: lw          $a2, 0x4($s3)
    ctx->r6 = MEM_W(ctx->r19, 0X4);
    // 0x80050ED4: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80050ED8: lwc1        $f0, -0x55BC($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X55BC);
    // 0x80050EDC: sll         $v0, $v1, 5
    ctx->r2 = S32(ctx->r3 << 5);
    // 0x80050EE0: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x80050EE4: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x80050EE8: addu        $v0, $v0, $s1
    ctx->r2 = ADD32(ctx->r2, ctx->r17);
    // 0x80050EEC: addu        $a1, $s2, $v0
    ctx->r5 = ADD32(ctx->r18, ctx->r2);
    // 0x80050EF0: beq         $a2, $a1, L_80051068
    if (ctx->r6 == ctx->r5) {
        // 0x80050EF4: addu        $s0, $s0, $a0
        ctx->r16 = ADD32(ctx->r16, ctx->r4);
            goto L_80051068;
    }
    // 0x80050EF4: addu        $s0, $s0, $a0
    ctx->r16 = ADD32(ctx->r16, ctx->r4);
    // 0x80050EF8: sll         $v1, $s4, 5
    ctx->r3 = S32(ctx->r20 << 5);
    // 0x80050EFC: subu        $v1, $v1, $s4
    ctx->r3 = SUB32(ctx->r3, ctx->r20);
    // 0x80050F00: sll         $v1, $v1, 5
    ctx->r3 = S32(ctx->r3 << 5);
    // 0x80050F04: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x80050F08: addiu       $v0, $v0, -0x76D0
    ctx->r2 = ADD32(ctx->r2, -0X76D0);
    // 0x80050F0C: addu        $a0, $v1, $v0
    ctx->r4 = ADD32(ctx->r3, ctx->r2);
    // 0x80050F10: lhu         $v1, 0x0($a0)
    ctx->r3 = MEM_HU(ctx->r4, 0X0);
    // 0x80050F14: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // 0x80050F18: sh          $v0, 0x2($a0)
    MEM_H(0X2, ctx->r4) = ctx->r2;
    // 0x80050F1C: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x80050F20: sw          $a2, 0xBC($a0)
    MEM_W(0XBC, ctx->r4) = ctx->r6;
    // 0x80050F24: sw          $a1, 0xC0($a0)
    MEM_W(0XC0, ctx->r4) = ctx->r5;
    // 0x80050F28: swc1        $f20, 0xC4($a0)
    MEM_W(0XC4, ctx->r4) = ctx->f20.u32l;
    // 0x80050F2C: swc1        $f0, 0xC8($a0)
    MEM_W(0XC8, ctx->r4) = ctx->f0.u32l;
    // 0x80050F30: swc1        $f0, 0xCC($a0)
    MEM_W(0XCC, ctx->r4) = ctx->f0.u32l;
    // 0x80050F34: sw          $s0, 0x74($a0)
    MEM_W(0X74, ctx->r4) = ctx->r16;
    // 0x80050F38: ori         $v1, $v1, 0x1
    ctx->r3 = ctx->r3 | 0X1;
    // 0x80050F3C: sh          $v1, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r3;
    // 0x80050F40: lw          $v1, -0x7DA0($v0)
    ctx->r3 = MEM_W(ctx->r2, -0X7DA0);
    // 0x80050F44: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80050F48: bnel        $v1, $v0, L_80050F60
    if (ctx->r3 != ctx->r2) {
        // 0x80050F4C: sw          $a0, 0x4($s3)
        MEM_W(0X4, ctx->r19) = ctx->r4;
            goto L_80050F60;
    }
    goto skip_0;
    // 0x80050F4C: sw          $a0, 0x4($s3)
    MEM_W(0X4, ctx->r19) = ctx->r4;
    skip_0:
    // 0x80050F50: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x80050F54: lw          $v0, -0x776C($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X776C);
    // 0x80050F58: sw          $a0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r4;
    // 0x80050F5C: sw          $a0, 0x4($s3)
    MEM_W(0X4, ctx->r19) = ctx->r4;
L_80050F60:
    // 0x80050F60: addiu       $v1, $a0, 0x28
    ctx->r3 = ADD32(ctx->r4, 0X28);
    // 0x80050F64: addiu       $v0, $a2, 0x28
    ctx->r2 = ADD32(ctx->r6, 0X28);
    // 0x80050F68: addiu       $a3, $a2, 0x58
    ctx->r7 = ADD32(ctx->r6, 0X58);
L_80050F6C:
    // 0x80050F6C: lw          $t0, 0x0($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X0);
    // 0x80050F70: lw          $t1, 0x4($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X4);
    // 0x80050F74: lw          $t2, 0x8($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X8);
    // 0x80050F78: lw          $t3, 0xC($v0)
    ctx->r11 = MEM_W(ctx->r2, 0XC);
    // 0x80050F7C: sw          $t0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r8;
    // 0x80050F80: sw          $t1, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r9;
    // 0x80050F84: sw          $t2, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r10;
    // 0x80050F88: sw          $t3, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r11;
    // 0x80050F8C: addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
    // 0x80050F90: bne         $v0, $a3, L_80050F6C
    if (ctx->r2 != ctx->r7) {
        // 0x80050F94: addiu       $v1, $v1, 0x10
        ctx->r3 = ADD32(ctx->r3, 0X10);
            goto L_80050F6C;
    }
    // 0x80050F94: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
    // 0x80050F98: addiu       $a3, $a1, 0x28
    ctx->r7 = ADD32(ctx->r5, 0X28);
    // 0x80050F9C: lw          $t0, 0x10($a2)
    ctx->r8 = MEM_W(ctx->r6, 0X10);
    // 0x80050FA0: lw          $t1, 0x14($a2)
    ctx->r9 = MEM_W(ctx->r6, 0X14);
    // 0x80050FA4: lw          $t2, 0x18($a2)
    ctx->r10 = MEM_W(ctx->r6, 0X18);
    // 0x80050FA8: sw          $t0, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->r8;
    // 0x80050FAC: sw          $t1, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->r9;
    // 0x80050FB0: sw          $t2, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->r10;
    // 0x80050FB4: lw          $t0, 0x1C($a2)
    ctx->r8 = MEM_W(ctx->r6, 0X1C);
    // 0x80050FB8: lw          $t1, 0x20($a2)
    ctx->r9 = MEM_W(ctx->r6, 0X20);
    // 0x80050FBC: lw          $t2, 0x24($a2)
    ctx->r10 = MEM_W(ctx->r6, 0X24);
    // 0x80050FC0: sw          $t0, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = ctx->r8;
    // 0x80050FC4: sw          $t1, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r9;
    // 0x80050FC8: sw          $t2, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->r10;
    // 0x80050FCC: lhu         $v0, 0x0($a2)
    ctx->r2 = MEM_HU(ctx->r6, 0X0);
    // 0x80050FD0: addiu       $v1, $a2, 0x28
    ctx->r3 = ADD32(ctx->r6, 0X28);
    // 0x80050FD4: ori         $v0, $v0, 0x1
    ctx->r2 = ctx->r2 | 0X1;
    // 0x80050FD8: sh          $v0, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r2;
    // 0x80050FDC: lhu         $v0, 0x0($a1)
    ctx->r2 = MEM_HU(ctx->r5, 0X0);
    // 0x80050FE0: addiu       $a2, $a2, 0x58
    ctx->r6 = ADD32(ctx->r6, 0X58);
    // 0x80050FE4: ori         $v0, $v0, 0x1
    ctx->r2 = ctx->r2 | 0X1;
    // 0x80050FE8: sh          $v0, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r2;
L_80050FEC:
    // 0x80050FEC: lw          $t0, 0x0($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X0);
    // 0x80050FF0: lw          $t1, 0x4($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X4);
    // 0x80050FF4: lw          $t2, 0x8($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X8);
    // 0x80050FF8: lw          $t3, 0xC($v1)
    ctx->r11 = MEM_W(ctx->r3, 0XC);
    // 0x80050FFC: sw          $t0, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r8;
    // 0x80051000: sw          $t1, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r9;
    // 0x80051004: sw          $t2, 0x8($a3)
    MEM_W(0X8, ctx->r7) = ctx->r10;
    // 0x80051008: sw          $t3, 0xC($a3)
    MEM_W(0XC, ctx->r7) = ctx->r11;
    // 0x8005100C: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
    // 0x80051010: bne         $v1, $a2, L_80050FEC
    if (ctx->r3 != ctx->r6) {
        // 0x80051014: addiu       $a3, $a3, 0x10
        ctx->r7 = ADD32(ctx->r7, 0X10);
            goto L_80050FEC;
    }
    // 0x80051014: addiu       $a3, $a3, 0x10
    ctx->r7 = ADD32(ctx->r7, 0X10);
    // 0x80051018: lui         $v1, 0x8014
    ctx->r3 = S32(0X8014 << 16);
    // 0x8005101C: addiu       $v1, $v1, -0x72E8
    ctx->r3 = ADD32(ctx->r3, -0X72E8);
    // 0x80051020: sll         $v0, $s4, 2
    ctx->r2 = S32(ctx->r20 << 2);
    // 0x80051024: addu        $v0, $v0, $s4
    ctx->r2 = ADD32(ctx->r2, ctx->r20);
    // 0x80051028: sll         $v0, $v0, 4
    ctx->r2 = S32(ctx->r2 << 4);
    // 0x8005102C: addu        $v0, $v0, $s4
    ctx->r2 = ADD32(ctx->r2, ctx->r20);
    // 0x80051030: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80051034: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80051038: lwc1        $f0, 0x4C($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0X4C);
    // 0x8005103C: lwc1        $f2, 0x50($a1)
    ctx->f2.u32l = MEM_W(ctx->r5, 0X50);
    // 0x80051040: lwc1        $f6, 0xA0($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0XA0);
    // 0x80051044: lwc1        $f4, 0x54($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X54);
    // 0x80051048: mov.s       $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = ctx->f6.fl;
    // 0x8005104C: swc1        $f0, 0x10($a1)
    MEM_W(0X10, ctx->r5) = ctx->f0.u32l;
    // 0x80051050: swc1        $f2, 0x14($a1)
    MEM_W(0X14, ctx->r5) = ctx->f2.u32l;
    // 0x80051054: swc1        $f4, 0x18($a1)
    MEM_W(0X18, ctx->r5) = ctx->f4.u32l;
    // 0x80051058: swc1        $f6, 0x98($a1)
    MEM_W(0X98, ctx->r5) = ctx->f6.u32l;
    // 0x8005105C: swc1        $f8, 0x9C($a1)
    MEM_W(0X9C, ctx->r5) = ctx->f8.u32l;
    // 0x80051060: jal         0x80066A50
    // 0x80051064: sw          $a0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r4;
    func_80066A50(rdram, ctx);
        goto after_1;
    // 0x80051064: sw          $a0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r4;
    after_1:
L_80051068:
    // 0x80051068: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8005106C: lw          $s4, 0x20($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X20);
    // 0x80051070: lw          $s3, 0x1C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X1C);
    // 0x80051074: lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X18);
    // 0x80051078: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x8005107C: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x80051080: ldc1        $f20, 0x28($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X28);
    // 0x80051084: jr          $ra
    // 0x80051088: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x80051088: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_8005108C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005108C: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x80051090: sw          $s3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r19;
    // 0x80051094: addu        $s3, $a0, $zero
    ctx->r19 = ADD32(ctx->r4, 0);
    // 0x80051098: sw          $fp, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r30;
    // 0x8005109C: addu        $fp, $a1, $zero
    ctx->r30 = ADD32(ctx->r5, 0);
    // 0x800510A0: sdc1        $f20, 0x60($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X60, ctx->r29);
    // 0x800510A4: mtc1        $a3, $f20
    ctx->f20.u32l = ctx->r7;
    // 0x800510A8: addu        $a0, $fp, $zero
    ctx->r4 = ADD32(ctx->r30, 0);
    // 0x800510AC: sw          $ra, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r31;
    // 0x800510B0: sw          $s7, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r23;
    // 0x800510B4: sw          $s6, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r22;
    // 0x800510B8: sw          $s5, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r21;
    // 0x800510BC: sw          $s4, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r20;
    // 0x800510C0: sw          $s2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r18;
    // 0x800510C4: sw          $s1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r17;
    // 0x800510C8: jal         0x80050AC8
    // 0x800510CC: sw          $s0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r16;
    func_80050AC8(rdram, ctx);
        goto after_0;
    // 0x800510CC: sw          $s0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r16;
    after_0:
    // 0x800510D0: addu        $s7, $zero, $zero
    ctx->r23 = ADD32(0, 0);
    // 0x800510D4: sll         $v0, $fp, 1
    ctx->r2 = S32(ctx->r30 << 1);
    // 0x800510D8: addu        $v0, $v0, $fp
    ctx->r2 = ADD32(ctx->r2, ctx->r30);
    // 0x800510DC: sll         $v1, $fp, 2
    ctx->r3 = S32(ctx->r30 << 2);
    // 0x800510E0: addu        $v1, $v1, $fp
    ctx->r3 = ADD32(ctx->r3, ctx->r30);
    // 0x800510E4: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x800510E8: addu        $v1, $v1, $fp
    ctx->r3 = ADD32(ctx->r3, ctx->r30);
    // 0x800510EC: sll         $v1, $v1, 5
    ctx->r3 = S32(ctx->r3 << 5);
    // 0x800510F0: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    // 0x800510F4: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x800510F8: addiu       $v0, $v0, -0x7FF4
    ctx->r2 = ADD32(ctx->r2, -0X7FF4);
    // 0x800510FC: addu        $s4, $v1, $v0
    ctx->r20 = ADD32(ctx->r3, ctx->r2);
    // 0x80051100: addiu       $v0, $v0, -0x254
    ctx->r2 = ADD32(ctx->r2, -0X254);
    // 0x80051104: addu        $s6, $v1, $v0
    ctx->r22 = ADD32(ctx->r3, ctx->r2);
    // 0x80051108: addiu       $v0, $v0, 0x284
    ctx->r2 = ADD32(ctx->r2, 0X284);
    // 0x8005110C: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x80051110: addu        $s5, $s7, $zero
    ctx->r21 = ADD32(ctx->r23, 0);
    // 0x80051114: addiu       $s2, $s3, 0xC
    ctx->r18 = ADD32(ctx->r19, 0XC);
    // 0x80051118: sw          $v1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r3;
L_8005111C:
    // 0x8005111C: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x80051120: addiu       $v0, $v0, -0x7D98
    ctx->r2 = ADD32(ctx->r2, -0X7D98);
    // 0x80051124: addu        $v0, $s5, $v0
    ctx->r2 = ADD32(ctx->r21, ctx->r2);
    // 0x80051128: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x8005112C: lw          $t0, 0x30($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X30);
    // 0x80051130: lhu         $a0, 0x0($s3)
    ctx->r4 = MEM_HU(ctx->r19, 0X0);
    // 0x80051134: sll         $v1, $t0, 5
    ctx->r3 = S32(ctx->r8 << 5);
    // 0x80051138: subu        $v1, $v1, $t0
    ctx->r3 = SUB32(ctx->r3, ctx->r8);
    // 0x8005113C: sll         $v1, $v1, 4
    ctx->r3 = S32(ctx->r3 << 4);
    // 0x80051140: addu        $s1, $v1, $v0
    ctx->r17 = ADD32(ctx->r3, ctx->r2);
    // 0x80051144: sh          $a0, 0x4($s1)
    MEM_H(0X4, ctx->r17) = ctx->r4;
    // 0x80051148: lhu         $v0, -0xA($s2)
    ctx->r2 = MEM_HU(ctx->r18, -0XA);
    // 0x8005114C: sh          $v0, 0x2($s1)
    MEM_H(0X2, ctx->r17) = ctx->r2;
    // 0x80051150: lhu         $v0, -0x8($s2)
    ctx->r2 = MEM_HU(ctx->r18, -0X8);
    // 0x80051154: sh          $v0, 0x0($s1)
    MEM_H(0X0, ctx->r17) = ctx->r2;
    // 0x80051158: lwc1        $f0, -0x4($s2)
    ctx->f0.u32l = MEM_W(ctx->r18, -0X4);
    // 0x8005115C: swc1        $f0, 0x9C($s1)
    MEM_W(0X9C, ctx->r17) = ctx->f0.u32l;
    // 0x80051160: lwc1        $f0, -0x4($s2)
    ctx->f0.u32l = MEM_W(ctx->r18, -0X4);
    // 0x80051164: addu        $a2, $s2, $zero
    ctx->r6 = ADD32(ctx->r18, 0);
    // 0x80051168: swc1        $f0, 0xA0($s1)
    MEM_W(0XA0, ctx->r17) = ctx->f0.u32l;
    // 0x8005116C: lwc1        $f0, -0x4($s2)
    ctx->f0.u32l = MEM_W(ctx->r18, -0X4);
    // 0x80051170: addiu       $a0, $s1, 0x10
    ctx->r4 = ADD32(ctx->r17, 0X10);
    // 0x80051174: jal         0x800AA3B4
    // 0x80051178: swc1        $f0, 0x98($s1)
    MEM_W(0X98, ctx->r17) = ctx->f0.u32l;
    func_800AA3B4(rdram, ctx);
        goto after_1;
    // 0x80051178: swc1        $f0, 0x98($s1)
    MEM_W(0X98, ctx->r17) = ctx->f0.u32l;
    after_1:
    // 0x8005117C: addiu       $a0, $s1, 0x1C
    ctx->r4 = ADD32(ctx->r17, 0X1C);
    // 0x80051180: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80051184: lwc1        $f0, 0x10($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X10);
    // 0x80051188: lwc1        $f2, 0x14($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0X14);
    // 0x8005118C: lwc1        $f4, 0x18($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X18);
    // 0x80051190: addiu       $a2, $s3, 0x18
    ctx->r6 = ADD32(ctx->r19, 0X18);
    // 0x80051194: swc1        $f0, 0x4C($s1)
    MEM_W(0X4C, ctx->r17) = ctx->f0.u32l;
    // 0x80051198: swc1        $f2, 0x50($s1)
    MEM_W(0X50, ctx->r17) = ctx->f2.u32l;
    // 0x8005119C: jal         0x800AA3B4
    // 0x800511A0: swc1        $f4, 0x54($s1)
    MEM_W(0X54, ctx->r17) = ctx->f4.u32l;
    func_800AA3B4(rdram, ctx);
        goto after_2;
    // 0x800511A0: swc1        $f4, 0x54($s1)
    MEM_W(0X54, ctx->r17) = ctx->f4.u32l;
    after_2:
    // 0x800511A4: addiu       $a0, $s1, 0x58
    ctx->r4 = ADD32(ctx->r17, 0X58);
    // 0x800511A8: addiu       $s0, $s3, 0x24
    ctx->r16 = ADD32(ctx->r19, 0X24);
    // 0x800511AC: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x800511B0: jal         0x800AA3B4
    // 0x800511B4: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    func_800AA3B4(rdram, ctx);
        goto after_3;
    // 0x800511B4: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    after_3:
    // 0x800511B8: addiu       $a0, $s1, 0x64
    ctx->r4 = ADD32(ctx->r17, 0X64);
    // 0x800511BC: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x800511C0: jal         0x800AA3B4
    // 0x800511C4: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    func_800AA3B4(rdram, ctx);
        goto after_4;
    // 0x800511C4: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    after_4:
    // 0x800511C8: addiu       $a0, $s1, 0x78
    ctx->r4 = ADD32(ctx->r17, 0X78);
    // 0x800511CC: addiu       $s0, $s3, 0x30
    ctx->r16 = ADD32(ctx->r19, 0X30);
    // 0x800511D0: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x800511D4: jal         0x800AA3B4
    // 0x800511D8: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    func_800AA3B4(rdram, ctx);
        goto after_5;
    // 0x800511D8: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    after_5:
    // 0x800511DC: addiu       $a0, $s1, 0x84
    ctx->r4 = ADD32(ctx->r17, 0X84);
    // 0x800511E0: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x800511E4: jal         0x800AA3B4
    // 0x800511E8: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    func_800AA3B4(rdram, ctx);
        goto after_6;
    // 0x800511E8: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    after_6:
    // 0x800511EC: lhu         $v1, 0x2($s1)
    ctx->r3 = MEM_HU(ctx->r17, 0X2);
    // 0x800511F0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800511F4: beq         $v1, $v0, L_80051214
    if (ctx->r3 == ctx->r2) {
        // 0x800511F8: addiu       $v0, $zero, 0x3
        ctx->r2 = ADD32(0, 0X3);
            goto L_80051214;
    }
    // 0x800511F8: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x800511FC: beq         $v1, $zero, L_800513D0
    if (ctx->r3 == 0) {
        // 0x80051200: slti        $v0, $v1, 0x4
        ctx->r2 = SIGNED(ctx->r3) < 0X4 ? 1 : 0;
            goto L_800513D0;
    }
    // 0x80051200: slti        $v0, $v1, 0x4
    ctx->r2 = SIGNED(ctx->r3) < 0X4 ? 1 : 0;
    // 0x80051204: beq         $v0, $zero, L_800513D0
    if (ctx->r2 == 0) {
        // 0x80051208: addiu       $v0, $zero, 0x2
        ctx->r2 = ADD32(0, 0X2);
            goto L_800513D0;
    }
    // 0x80051208: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x8005120C: j           L_80051320
    // 0x80051210: nop

        goto L_80051320;
    // 0x80051210: nop

L_80051214:
    // 0x80051214: lhu         $v1, 0x4($s1)
    ctx->r3 = MEM_HU(ctx->r17, 0X4);
    // 0x80051218: beq         $v1, $v0, L_80051228
    if (ctx->r3 == ctx->r2) {
        // 0x8005121C: sw          $s4, 0x70($s1)
        MEM_W(0X70, ctx->r17) = ctx->r20;
            goto L_80051228;
    }
    // 0x8005121C: sw          $s4, 0x70($s1)
    MEM_W(0X70, ctx->r17) = ctx->r20;
    // 0x80051220: j           L_80051280
    // 0x80051224: sw          $s4, 0x74($s1)
    MEM_W(0X74, ctx->r17) = ctx->r20;
        goto L_80051280;
    // 0x80051224: sw          $s4, 0x74($s1)
    MEM_W(0X74, ctx->r17) = ctx->r20;
L_80051228:
    // 0x80051228: lui         $t1, 0x8011
    ctx->r9 = S32(0X8011 << 16);
    // 0x8005122C: addiu       $t1, $t1, -0x5EBC
    ctx->r9 = ADD32(ctx->r9, -0X5EBC);
    // 0x80051230: sw          $zero, 0x74($s1)
    MEM_W(0X74, ctx->r17) = 0;
    // 0x80051234: lhu         $v1, 0xB8($s6)
    ctx->r3 = MEM_HU(ctx->r22, 0XB8);
    // 0x80051238: lui         $t2, 0x8011
    ctx->r10 = S32(0X8011 << 16);
    // 0x8005123C: sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3 << 1);
    // 0x80051240: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80051244: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80051248: addu        $v0, $v0, $t1
    ctx->r2 = ADD32(ctx->r2, ctx->r9);
    // 0x8005124C: lwc1        $f0, 0x0($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X0);
    // 0x80051250: addiu       $t2, $t2, -0x5EBC
    ctx->r10 = ADD32(ctx->r10, -0X5EBC);
    // 0x80051254: swc1        $f0, 0xD4($s1)
    MEM_W(0XD4, ctx->r17) = ctx->f0.u32l;
    // 0x80051258: lhu         $v1, 0xB8($s6)
    ctx->r3 = MEM_HU(ctx->r22, 0XB8);
    // 0x8005125C: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80051260: lwc1        $f0, -0x55B8($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X55B8);
    // 0x80051264: sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3 << 1);
    // 0x80051268: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8005126C: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80051270: addu        $v0, $v0, $t2
    ctx->r2 = ADD32(ctx->r2, ctx->r10);
    // 0x80051274: lwc1        $f2, 0x4($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X4);
    // 0x80051278: swc1        $f0, 0xE8($s1)
    MEM_W(0XE8, ctx->r17) = ctx->f0.u32l;
    // 0x8005127C: swc1        $f2, 0xE4($s1)
    MEM_W(0XE4, ctx->r17) = ctx->f2.u32l;
L_80051280:
    // 0x80051280: addiu       $v1, $s1, 0x28
    ctx->r3 = ADD32(ctx->r17, 0X28);
    // 0x80051284: lw          $v0, 0x70($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X70);
    // 0x80051288: lw          $t3, 0x34($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X34);
    // 0x8005128C: addiu       $a0, $v0, 0x30
    ctx->r4 = ADD32(ctx->r2, 0X30);
    // 0x80051290: sw          $t3, 0x90($s1)
    MEM_W(0X90, ctx->r17) = ctx->r11;
L_80051294:
    // 0x80051294: lw          $t0, 0x0($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X0);
    // 0x80051298: lw          $t1, 0x4($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X4);
    // 0x8005129C: lw          $t2, 0x8($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X8);
    // 0x800512A0: lw          $t3, 0xC($v0)
    ctx->r11 = MEM_W(ctx->r2, 0XC);
    // 0x800512A4: sw          $t0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r8;
    // 0x800512A8: sw          $t1, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r9;
    // 0x800512AC: sw          $t2, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r10;
    // 0x800512B0: sw          $t3, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r11;
    // 0x800512B4: addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
    // 0x800512B8: bne         $v0, $a0, L_80051294
    if (ctx->r2 != ctx->r4) {
        // 0x800512BC: addiu       $v1, $v1, 0x10
        ctx->r3 = ADD32(ctx->r3, 0X10);
            goto L_80051294;
    }
    // 0x800512BC: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
    // 0x800512C0: addiu       $a0, $s1, 0x28
    ctx->r4 = ADD32(ctx->r17, 0X28);
    // 0x800512C4: addiu       $a1, $sp, 0x10
    ctx->r5 = ADD32(ctx->r29, 0X10);
    // 0x800512C8: lw          $t0, 0x58($s1)
    ctx->r8 = MEM_W(ctx->r17, 0X58);
    // 0x800512CC: lw          $t1, 0x5C($s1)
    ctx->r9 = MEM_W(ctx->r17, 0X5C);
    // 0x800512D0: lw          $t2, 0x60($s1)
    ctx->r10 = MEM_W(ctx->r17, 0X60);
    // 0x800512D4: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x800512D8: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    // 0x800512DC: sw          $t2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r10;
    // 0x800512E0: jal         0x800193E8
    // 0x800512E4: addiu       $a2, $sp, 0x20
    ctx->r6 = ADD32(ctx->r29, 0X20);
    func_800193E8(rdram, ctx);
        goto after_7;
    // 0x800512E4: addiu       $a2, $sp, 0x20
    ctx->r6 = ADD32(ctx->r29, 0X20);
    after_7:
    // 0x800512E8: lwc1        $f0, 0x20($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X20);
    // 0x800512EC: swc1        $f0, 0x4C($s1)
    MEM_W(0X4C, ctx->r17) = ctx->f0.u32l;
    // 0x800512F0: lwc1        $f0, 0x24($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X24);
    // 0x800512F4: swc1        $f0, 0x50($s1)
    MEM_W(0X50, ctx->r17) = ctx->f0.u32l;
    // 0x800512F8: lwc1        $f0, 0x28($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X28);
    // 0x800512FC: swc1        $f0, 0x54($s1)
    MEM_W(0X54, ctx->r17) = ctx->f0.u32l;
    // 0x80051300: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x80051304: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
    // 0x80051308: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
    // 0x8005130C: sw          $t0, 0x10($s1)
    MEM_W(0X10, ctx->r17) = ctx->r8;
    // 0x80051310: sw          $t1, 0x14($s1)
    MEM_W(0X14, ctx->r17) = ctx->r9;
    // 0x80051314: sw          $t2, 0x18($s1)
    MEM_W(0X18, ctx->r17) = ctx->r10;
    // 0x80051318: j           L_800513DC
    // 0x8005131C: nop

        goto L_800513DC;
    // 0x8005131C: nop

L_80051320:
    // 0x80051320: lhu         $v1, 0x4($s1)
    ctx->r3 = MEM_HU(ctx->r17, 0X4);
    // 0x80051324: bne         $v1, $v0, L_80051334
    if (ctx->r3 != ctx->r2) {
        // 0x80051328: addiu       $v1, $s1, 0x28
        ctx->r3 = ADD32(ctx->r17, 0X28);
            goto L_80051334;
    }
    // 0x80051328: addiu       $v1, $s1, 0x28
    ctx->r3 = ADD32(ctx->r17, 0X28);
    // 0x8005132C: lw          $t0, 0x34($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X34);
    // 0x80051330: sw          $t0, 0x90($s1)
    MEM_W(0X90, ctx->r17) = ctx->r8;
L_80051334:
    // 0x80051334: addu        $v0, $s4, $zero
    ctx->r2 = ADD32(ctx->r20, 0);
    // 0x80051338: lwc1        $f0, 0x9C($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X9C);
    // 0x8005133C: addiu       $a0, $v0, 0x30
    ctx->r4 = ADD32(ctx->r2, 0X30);
    // 0x80051340: sw          $s4, 0x70($s1)
    MEM_W(0X70, ctx->r17) = ctx->r20;
    // 0x80051344: sw          $s4, 0x74($s1)
    MEM_W(0X74, ctx->r17) = ctx->r20;
    // 0x80051348: swc1        $f0, 0x98($s1)
    MEM_W(0X98, ctx->r17) = ctx->f0.u32l;
L_8005134C:
    // 0x8005134C: lw          $t1, 0x0($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X0);
    // 0x80051350: lw          $t2, 0x4($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X4);
    // 0x80051354: lw          $t3, 0x8($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X8);
    // 0x80051358: lw          $t0, 0xC($v0)
    ctx->r8 = MEM_W(ctx->r2, 0XC);
    // 0x8005135C: sw          $t1, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r9;
    // 0x80051360: sw          $t2, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r10;
    // 0x80051364: sw          $t3, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r11;
    // 0x80051368: sw          $t0, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r8;
    // 0x8005136C: addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
    // 0x80051370: bne         $v0, $a0, L_8005134C
    if (ctx->r2 != ctx->r4) {
        // 0x80051374: addiu       $v1, $v1, 0x10
        ctx->r3 = ADD32(ctx->r3, 0X10);
            goto L_8005134C;
    }
    // 0x80051374: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
    // 0x80051378: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    // 0x8005137C: lui         $a1, 0x3E80
    ctx->r5 = S32(0X3E80 << 16);
    // 0x80051380: jal         0x800AA3B4
    // 0x80051384: addu        $a2, $s2, $zero
    ctx->r6 = ADD32(ctx->r18, 0);
    func_800AA3B4(rdram, ctx);
        goto after_8;
    // 0x80051384: addu        $a2, $s2, $zero
    ctx->r6 = ADD32(ctx->r18, 0);
    after_8:
    // 0x80051388: addiu       $a0, $s1, 0x28
    ctx->r4 = ADD32(ctx->r17, 0X28);
    // 0x8005138C: addiu       $a1, $sp, 0x10
    ctx->r5 = ADD32(ctx->r29, 0X10);
    // 0x80051390: jal         0x800193E8
    // 0x80051394: addiu       $a2, $sp, 0x20
    ctx->r6 = ADD32(ctx->r29, 0X20);
    func_800193E8(rdram, ctx);
        goto after_9;
    // 0x80051394: addiu       $a2, $sp, 0x20
    ctx->r6 = ADD32(ctx->r29, 0X20);
    after_9:
    // 0x80051398: lwc1        $f0, 0x20($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X20);
    // 0x8005139C: swc1        $f0, 0x4C($s1)
    MEM_W(0X4C, ctx->r17) = ctx->f0.u32l;
    // 0x800513A0: lwc1        $f0, 0x24($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X24);
    // 0x800513A4: swc1        $f0, 0x50($s1)
    MEM_W(0X50, ctx->r17) = ctx->f0.u32l;
    // 0x800513A8: lwc1        $f0, 0x28($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X28);
    // 0x800513AC: swc1        $f0, 0x54($s1)
    MEM_W(0X54, ctx->r17) = ctx->f0.u32l;
    // 0x800513B0: lw          $t1, 0x20($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X20);
    // 0x800513B4: lw          $t2, 0x24($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X24);
    // 0x800513B8: lw          $t3, 0x28($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X28);
    // 0x800513BC: sw          $t1, 0x10($s1)
    MEM_W(0X10, ctx->r17) = ctx->r9;
    // 0x800513C0: sw          $t2, 0x14($s1)
    MEM_W(0X14, ctx->r17) = ctx->r10;
    // 0x800513C4: sw          $t3, 0x18($s1)
    MEM_W(0X18, ctx->r17) = ctx->r11;
    // 0x800513C8: j           L_800513DC
    // 0x800513CC: nop

        goto L_800513DC;
    // 0x800513CC: nop

L_800513D0:
    // 0x800513D0: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x800513D4: addiu       $v0, $v0, -0x13EC
    ctx->r2 = ADD32(ctx->r2, -0X13EC);
    // 0x800513D8: sw          $v0, 0x74($s1)
    MEM_W(0X74, ctx->r17) = ctx->r2;
L_800513DC:
    // 0x800513DC: lhu         $v1, 0xB8($s6)
    ctx->r3 = MEM_HU(ctx->r22, 0XB8);
    // 0x800513E0: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x800513E4: beq         $v1, $v0, L_80051404
    if (ctx->r3 == ctx->r2) {
        // 0x800513E8: addiu       $v0, $zero, 0x4
        ctx->r2 = ADD32(0, 0X4);
            goto L_80051404;
    }
    // 0x800513E8: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // 0x800513EC: bne         $v1, $v0, L_80051414
    if (ctx->r3 != ctx->r2) {
        // 0x800513F0: nop
    
            goto L_80051414;
    }
    // 0x800513F0: nop

    // 0x800513F4: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x800513F8: lwc1        $f0, -0x55B4($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X55B4);
    // 0x800513FC: j           L_80051420
    // 0x80051400: swc1        $f0, 0xAC($s1)
    MEM_W(0XAC, ctx->r17) = ctx->f0.u32l;
        goto L_80051420;
    // 0x80051400: swc1        $f0, 0xAC($s1)
    MEM_W(0XAC, ctx->r17) = ctx->f0.u32l;
L_80051404:
    // 0x80051404: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80051408: lwc1        $f0, -0x55B0($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X55B0);
    // 0x8005140C: j           L_80051420
    // 0x80051410: swc1        $f0, 0xAC($s1)
    MEM_W(0XAC, ctx->r17) = ctx->f0.u32l;
        goto L_80051420;
    // 0x80051410: swc1        $f0, 0xAC($s1)
    MEM_W(0XAC, ctx->r17) = ctx->f0.u32l;
L_80051414:
    // 0x80051414: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80051418: lwc1        $f0, -0x55AC($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X55AC);
    // 0x8005141C: swc1        $f0, 0xAC($s1)
    MEM_W(0XAC, ctx->r17) = ctx->f0.u32l;
L_80051420:
    // 0x80051420: jal         0x8004CD00
    // 0x80051424: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    func_8004CD00(rdram, ctx);
        goto after_10;
    // 0x80051424: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    after_10:
    // 0x80051428: addiu       $s2, $s2, 0x3C
    ctx->r18 = ADD32(ctx->r18, 0X3C);
    // 0x8005142C: addiu       $s3, $s3, 0x3C
    ctx->r19 = ADD32(ctx->r19, 0X3C);
    // 0x80051430: addiu       $s7, $s7, 0x1
    ctx->r23 = ADD32(ctx->r23, 0X1);
    // 0x80051434: slti        $v0, $s7, 0x6
    ctx->r2 = SIGNED(ctx->r23) < 0X6 ? 1 : 0;
    // 0x80051438: bne         $v0, $zero, L_8005111C
    if (ctx->r2 != 0) {
        // 0x8005143C: addiu       $s5, $s5, 0xF8
        ctx->r21 = ADD32(ctx->r21, 0XF8);
            goto L_8005111C;
    }
    // 0x8005143C: addiu       $s5, $s5, 0xF8
    ctx->r21 = ADD32(ctx->r21, 0XF8);
    // 0x80051440: jal         0x80050E28
    // 0x80051444: addu        $a0, $fp, $zero
    ctx->r4 = ADD32(ctx->r30, 0);
    func_80050E28(rdram, ctx);
        goto after_11;
    // 0x80051444: addu        $a0, $fp, $zero
    ctx->r4 = ADD32(ctx->r30, 0);
    after_11:
    // 0x80051448: jal         0x80066A50
    // 0x8005144C: nop

    func_80066A50(rdram, ctx);
        goto after_12;
    // 0x8005144C: nop

    after_12:
    // 0x80051450: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80051454: addiu       $a0, $a0, 0x7A80
    ctx->r4 = ADD32(ctx->r4, 0X7A80);
    // 0x80051458: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x8005145C: lui         $v1, 0x800A
    ctx->r3 = S32(0X800A << 16);
    // 0x80051460: sb          $zero, -0x1444($v0)
    MEM_B(-0X1444, ctx->r2) = 0;
    // 0x80051464: ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
    // 0x80051468: jal         0x8001CA50
    // 0x8005146C: sh          $v0, -0x143C($v1)
    MEM_H(-0X143C, ctx->r3) = ctx->r2;
    func_8001CA50(rdram, ctx);
        goto after_13;
    // 0x8005146C: sh          $v0, -0x143C($v1)
    MEM_H(-0X143C, ctx->r3) = ctx->r2;
    after_13:
    // 0x80051470: lw          $ra, 0x5C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X5C);
    // 0x80051474: lw          $fp, 0x58($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X58);
    // 0x80051478: lw          $s7, 0x54($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X54);
    // 0x8005147C: lw          $s6, 0x50($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X50);
    // 0x80051480: lw          $s5, 0x4C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X4C);
    // 0x80051484: lw          $s4, 0x48($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X48);
    // 0x80051488: lw          $s3, 0x44($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X44);
    // 0x8005148C: lw          $s2, 0x40($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X40);
    // 0x80051490: lw          $s1, 0x3C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X3C);
    // 0x80051494: lw          $s0, 0x38($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X38);
    // 0x80051498: ldc1        $f20, 0x60($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X60);
    // 0x8005149C: jr          $ra
    // 0x800514A0: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    return;
    // 0x800514A0: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
;}
RECOMP_FUNC void func_800514A4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800514A4: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x800514A8: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x800514AC: addu        $s3, $a0, $zero
    ctx->r19 = ADD32(ctx->r4, 0);
    // 0x800514B0: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x800514B4: sw          $ra, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r31;
    // 0x800514B8: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x800514BC: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x800514C0: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x800514C4: sdc1        $f24, 0x48($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X48, ctx->r29);
    // 0x800514C8: sdc1        $f22, 0x40($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X40, ctx->r29);
    // 0x800514CC: sdc1        $f20, 0x38($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X38, ctx->r29);
    // 0x800514D0: lw          $a1, 0xB8($s3)
    ctx->r5 = MEM_W(ctx->r19, 0XB8);
    // 0x800514D4: addiu       $v0, $v0, -0x75D8
    ctx->r2 = ADD32(ctx->r2, -0X75D8);
    // 0x800514D8: sll         $v1, $a1, 5
    ctx->r3 = S32(ctx->r5 << 5);
    // 0x800514DC: subu        $v1, $v1, $a1
    ctx->r3 = SUB32(ctx->r3, ctx->r5);
    // 0x800514E0: sll         $v1, $v1, 5
    ctx->r3 = S32(ctx->r3 << 5);
    // 0x800514E4: addu        $s1, $v1, $v0
    ctx->r17 = ADD32(ctx->r3, ctx->r2);
    // 0x800514E8: addiu       $s0, $s1, 0x28
    ctx->r16 = ADD32(ctx->r17, 0X28);
    // 0x800514EC: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x800514F0: sll         $v0, $a1, 2
    ctx->r2 = S32(ctx->r5 << 2);
    // 0x800514F4: addu        $v0, $v0, $a1
    ctx->r2 = ADD32(ctx->r2, ctx->r5);
    // 0x800514F8: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800514FC: addu        $v0, $v0, $a1
    ctx->r2 = ADD32(ctx->r2, ctx->r5);
    // 0x80051500: sll         $v0, $v0, 5
    ctx->r2 = S32(ctx->r2 << 5);
    // 0x80051504: lui         $v1, 0x8014
    ctx->r3 = S32(0X8014 << 16);
    // 0x80051508: addiu       $v1, $v1, -0x7FF4
    ctx->r3 = ADD32(ctx->r3, -0X7FF4);
    // 0x8005150C: addu        $s2, $v0, $v1
    ctx->r18 = ADD32(ctx->r2, ctx->r3);
    // 0x80051510: sh          $zero, 0x2($s1)
    MEM_H(0X2, ctx->r17) = 0;
    // 0x80051514: sh          $zero, 0x4($s1)
    MEM_H(0X4, ctx->r17) = 0;
    // 0x80051518: jal         0x8001CA50
    // 0x8005151C: sh          $zero, 0x0($s1)
    MEM_H(0X0, ctx->r17) = 0;
    func_8001CA50(rdram, ctx);
        goto after_0;
    // 0x8005151C: sh          $zero, 0x0($s1)
    MEM_H(0X0, ctx->r17) = 0;
    after_0:
    // 0x80051520: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x80051524: addiu       $v0, $v0, -0x13EC
    ctx->r2 = ADD32(ctx->r2, -0X13EC);
    // 0x80051528: sw          $v0, 0x70($s1)
    MEM_W(0X70, ctx->r17) = ctx->r2;
    // 0x8005152C: sw          $v0, 0x74($s1)
    MEM_W(0X74, ctx->r17) = ctx->r2;
    // 0x80051530: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x80051534: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80051538: lwc1        $f8, -0x55A8($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X55A8);
    // 0x8005153C: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80051540: lwc1        $f0, -0x55A4($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X55A4);
    // 0x80051544: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80051548: lwc1        $f2, -0x55A0($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X55A0);
    // 0x8005154C: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80051550: lwc1        $f4, -0x559C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X559C);
    // 0x80051554: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80051558: lwc1        $f6, -0x5598($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X5598);
    // 0x8005155C: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80051560: lwc1        $f24, -0x5594($at)
    ctx->f24.u32l = MEM_W(ctx->r1, -0X5594);
    // 0x80051564: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80051568: lwc1        $f22, -0x5590($at)
    ctx->f22.u32l = MEM_W(ctx->r1, -0X5590);
    // 0x8005156C: addiu       $v0, $v0, -0x7D98
    ctx->r2 = ADD32(ctx->r2, -0X7D98);
    // 0x80051570: sw          $zero, 0x58($s1)
    MEM_W(0X58, ctx->r17) = 0;
    // 0x80051574: sw          $zero, 0x5C($s1)
    MEM_W(0X5C, ctx->r17) = 0;
    // 0x80051578: sw          $zero, 0x60($s1)
    MEM_W(0X60, ctx->r17) = 0;
    // 0x8005157C: sw          $zero, 0x64($s1)
    MEM_W(0X64, ctx->r17) = 0;
    // 0x80051580: sw          $zero, 0x68($s1)
    MEM_W(0X68, ctx->r17) = 0;
    // 0x80051584: sw          $zero, 0x6C($s1)
    MEM_W(0X6C, ctx->r17) = 0;
    // 0x80051588: sw          $zero, 0x78($s1)
    MEM_W(0X78, ctx->r17) = 0;
    // 0x8005158C: sw          $zero, 0x7C($s1)
    MEM_W(0X7C, ctx->r17) = 0;
    // 0x80051590: sw          $zero, 0x80($s1)
    MEM_W(0X80, ctx->r17) = 0;
    // 0x80051594: sw          $zero, 0x84($s1)
    MEM_W(0X84, ctx->r17) = 0;
    // 0x80051598: sw          $zero, 0x88($s1)
    MEM_W(0X88, ctx->r17) = 0;
    // 0x8005159C: sw          $zero, 0x8C($s1)
    MEM_W(0X8C, ctx->r17) = 0;
    // 0x800515A0: sw          $zero, 0x10($s1)
    MEM_W(0X10, ctx->r17) = 0;
    // 0x800515A4: sw          $zero, 0x14($s1)
    MEM_W(0X14, ctx->r17) = 0;
    // 0x800515A8: sw          $zero, 0x18($s1)
    MEM_W(0X18, ctx->r17) = 0;
    // 0x800515AC: sw          $zero, 0x1C($s1)
    MEM_W(0X1C, ctx->r17) = 0;
    // 0x800515B0: sw          $zero, 0x20($s1)
    MEM_W(0X20, ctx->r17) = 0;
    // 0x800515B4: sw          $zero, 0x24($s1)
    MEM_W(0X24, ctx->r17) = 0;
    // 0x800515B8: sw          $zero, 0x90($s1)
    MEM_W(0X90, ctx->r17) = 0;
    // 0x800515BC: sw          $zero, 0x94($s1)
    MEM_W(0X94, ctx->r17) = 0;
    // 0x800515C0: sw          $zero, 0x98($s1)
    MEM_W(0X98, ctx->r17) = 0;
    // 0x800515C4: sw          $zero, 0x9C($s1)
    MEM_W(0X9C, ctx->r17) = 0;
    // 0x800515C8: sw          $zero, 0xA0($s1)
    MEM_W(0XA0, ctx->r17) = 0;
    // 0x800515CC: sw          $v0, 0xBC($s1)
    MEM_W(0XBC, ctx->r17) = ctx->r2;
    // 0x800515D0: sw          $v0, 0xC0($s1)
    MEM_W(0XC0, ctx->r17) = ctx->r2;
    // 0x800515D4: sw          $zero, 0xC4($s1)
    MEM_W(0XC4, ctx->r17) = 0;
    // 0x800515D8: sw          $zero, 0xCC($s1)
    MEM_W(0XCC, ctx->r17) = 0;
    // 0x800515DC: sw          $zero, 0xD0($s1)
    MEM_W(0XD0, ctx->r17) = 0;
    // 0x800515E0: sw          $zero, 0xD8($s1)
    MEM_W(0XD8, ctx->r17) = 0;
    // 0x800515E4: sw          $zero, 0xE0($s1)
    MEM_W(0XE0, ctx->r17) = 0;
    // 0x800515E8: swc1        $f8, 0xC8($s1)
    MEM_W(0XC8, ctx->r17) = ctx->f8.u32l;
    // 0x800515EC: sw          $zero, 0xDC($s1)
    MEM_W(0XDC, ctx->r17) = 0;
    // 0x800515F0: swc1        $f0, 0xD4($s1)
    MEM_W(0XD4, ctx->r17) = ctx->f0.u32l;
    // 0x800515F4: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x800515F8: lwc1        $f0, -0x558C($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X558C);
    // 0x800515FC: ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
    // 0x80051600: sh          $v0, 0xF4($s1)
    MEM_H(0XF4, ctx->r17) = ctx->r2;
    // 0x80051604: swc1        $f0, 0xB8($s1)
    MEM_W(0XB8, ctx->r17) = ctx->f0.u32l;
    // 0x80051608: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8005160C: lwc1        $f0, -0x5588($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X5588);
    // 0x80051610: addiu       $v0, $zero, 0x53
    ctx->r2 = ADD32(0, 0X53);
    // 0x80051614: swc1        $f2, 0xE4($s1)
    MEM_W(0XE4, ctx->r17) = ctx->f2.u32l;
    // 0x80051618: swc1        $f4, 0xE8($s1)
    MEM_W(0XE8, ctx->r17) = ctx->f4.u32l;
    // 0x8005161C: swc1        $f6, 0xA4($s1)
    MEM_W(0XA4, ctx->r17) = ctx->f6.u32l;
    // 0x80051620: sw          $zero, 0xA8($s1)
    MEM_W(0XA8, ctx->r17) = 0;
    // 0x80051624: swc1        $f24, 0xAC($s1)
    MEM_W(0XAC, ctx->r17) = ctx->f24.u32l;
    // 0x80051628: swc1        $f22, 0xB0($s1)
    MEM_W(0XB0, ctx->r17) = ctx->f22.u32l;
    // 0x8005162C: sw          $zero, 0xEC($s1)
    MEM_W(0XEC, ctx->r17) = 0;
    // 0x80051630: sw          $zero, 0xF0($s1)
    MEM_W(0XF0, ctx->r17) = 0;
    // 0x80051634: sw          $zero, 0xB4($s1)
    MEM_W(0XB4, ctx->r17) = 0;
    // 0x80051638: sh          $v0, 0x0($s1)
    MEM_H(0X0, ctx->r17) = ctx->r2;
    // 0x8005163C: swc1        $f8, 0x94($s1)
    MEM_W(0X94, ctx->r17) = ctx->f8.u32l;
    // 0x80051640: swc1        $f0, 0xB8($s1)
    MEM_W(0XB8, ctx->r17) = ctx->f0.u32l;
    // 0x80051644: lwc1        $f0, 0x8($s2)
    ctx->f0.u32l = MEM_W(ctx->r18, 0X8);
    // 0x80051648: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    // 0x8005164C: lwc1        $f0, 0x14($s2)
    ctx->f0.u32l = MEM_W(ctx->r18, 0X14);
    // 0x80051650: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    // 0x80051654: lwc1        $f0, 0x20($s2)
    ctx->f0.u32l = MEM_W(ctx->r18, 0X20);
    // 0x80051658: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x8005165C: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    // 0x80051660: sh          $v0, 0x2($s1)
    MEM_H(0X2, ctx->r17) = ctx->r2;
    // 0x80051664: sh          $zero, 0x4($s1)
    MEM_H(0X4, ctx->r17) = 0;
    // 0x80051668: sw          $zero, 0x9C($s1)
    MEM_W(0X9C, ctx->r17) = 0;
    // 0x8005166C: jal         0x80003430
    // 0x80051670: sw          $zero, 0x98($s1)
    MEM_W(0X98, ctx->r17) = 0;
    rand_recomp(rdram, ctx);
        goto after_1;
    // 0x80051670: sw          $zero, 0x98($s1)
    MEM_W(0X98, ctx->r17) = 0;
    after_1:
    // 0x80051674: andi        $v0, $v0, 0x7F
    ctx->r2 = ctx->r2 & 0X7F;
    // 0x80051678: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8005167C: lwc1        $f20, -0x5584($at)
    ctx->f20.u32l = MEM_W(ctx->r1, -0X5584);
    // 0x80051680: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x80051684: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x80051688: sub.s       $f0, $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f20.fl;
    // 0x8005168C: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80051690: lwc1        $f2, -0x5580($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X5580);
    // 0x80051694: div.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f2.fl);
    // 0x80051698: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x8005169C: add.s       $f0, $f0, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f22.fl;
    // 0x800516A0: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x800516A4: lwc1        $f2, -0x557C($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X557C);
    // 0x800516A8: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x800516AC: sw          $zero, 0xDC($s1)
    MEM_W(0XDC, ctx->r17) = 0;
    // 0x800516B0: swc1        $f24, 0xAC($s1)
    MEM_W(0XAC, ctx->r17) = ctx->f24.u32l;
    // 0x800516B4: jal         0x80003430
    // 0x800516B8: swc1        $f0, 0x94($s1)
    MEM_W(0X94, ctx->r17) = ctx->f0.u32l;
    rand_recomp(rdram, ctx);
        goto after_2;
    // 0x800516B8: swc1        $f0, 0x94($s1)
    MEM_W(0X94, ctx->r17) = ctx->f0.u32l;
    after_2:
    // 0x800516BC: andi        $v0, $v0, 0x7F
    ctx->r2 = ctx->r2 & 0X7F;
    // 0x800516C0: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x800516C4: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x800516C8: sub.s       $f0, $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f20.fl;
    // 0x800516CC: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x800516D0: lwc1        $f2, -0x5578($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X5578);
    // 0x800516D4: div.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f2.fl);
    // 0x800516D8: abs.s       $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = fabsf(ctx->f0.fl);
    // 0x800516DC: swc1        $f10, 0xD0($s1)
    MEM_W(0XD0, ctx->r17) = ctx->f10.u32l;
    // 0x800516E0: jal         0x80003430
    // 0x800516E4: sw          $zero, 0xD8($s1)
    MEM_W(0XD8, ctx->r17) = 0;
    rand_recomp(rdram, ctx);
        goto after_3;
    // 0x800516E4: sw          $zero, 0xD8($s1)
    MEM_W(0XD8, ctx->r17) = 0;
    after_3:
    // 0x800516E8: andi        $v0, $v0, 0x7F
    ctx->r2 = ctx->r2 & 0X7F;
    // 0x800516EC: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x800516F0: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x800516F4: sub.s       $f0, $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f20.fl;
    // 0x800516F8: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x800516FC: lwc1        $f2, -0x5574($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X5574);
    // 0x80051700: div.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f2.fl);
    // 0x80051704: abs.s       $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = fabsf(ctx->f0.fl);
    // 0x80051708: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8005170C: swc1        $f10, 0xE0($s1)
    MEM_W(0XE0, ctx->r17) = ctx->f10.u32l;
    // 0x80051710: sw          $zero, 0x58($s1)
    MEM_W(0X58, ctx->r17) = 0;
    // 0x80051714: sw          $zero, 0x5C($s1)
    MEM_W(0X5C, ctx->r17) = 0;
    // 0x80051718: sw          $zero, 0x60($s1)
    MEM_W(0X60, ctx->r17) = 0;
    // 0x8005171C: lw          $a3, 0x58($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X58);
    // 0x80051720: lw          $t0, 0x5C($s1)
    ctx->r8 = MEM_W(ctx->r17, 0X5C);
    // 0x80051724: lw          $t1, 0x60($s1)
    ctx->r9 = MEM_W(ctx->r17, 0X60);
    // 0x80051728: sw          $a3, 0x64($s1)
    MEM_W(0X64, ctx->r17) = ctx->r7;
    // 0x8005172C: sw          $t0, 0x68($s1)
    MEM_W(0X68, ctx->r17) = ctx->r8;
    // 0x80051730: sw          $t1, 0x6C($s1)
    MEM_W(0X6C, ctx->r17) = ctx->r9;
    // 0x80051734: lw          $v1, 0xB8($s3)
    ctx->r3 = MEM_W(ctx->r19, 0XB8);
    // 0x80051738: addiu       $a0, $a0, -0x72E8
    ctx->r4 = ADD32(ctx->r4, -0X72E8);
    // 0x8005173C: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x80051740: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80051744: sll         $v0, $v0, 4
    ctx->r2 = S32(ctx->r2 << 4);
    // 0x80051748: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8005174C: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80051750: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x80051754: lw          $v0, 0x4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X4);
    // 0x80051758: addiu       $v1, $v0, 0x28
    ctx->r3 = ADD32(ctx->r2, 0X28);
    // 0x8005175C: addiu       $v0, $v0, 0x58
    ctx->r2 = ADD32(ctx->r2, 0X58);
L_80051760:
    // 0x80051760: lw          $a3, 0x0($v1)
    ctx->r7 = MEM_W(ctx->r3, 0X0);
    // 0x80051764: lw          $t0, 0x4($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X4);
    // 0x80051768: lw          $t1, 0x8($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X8);
    // 0x8005176C: lw          $t2, 0xC($v1)
    ctx->r10 = MEM_W(ctx->r3, 0XC);
    // 0x80051770: sw          $a3, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r7;
    // 0x80051774: sw          $t0, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r8;
    // 0x80051778: sw          $t1, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r9;
    // 0x8005177C: sw          $t2, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r10;
    // 0x80051780: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
    // 0x80051784: bne         $v1, $v0, L_80051760
    if (ctx->r3 != ctx->r2) {
        // 0x80051788: addiu       $s0, $s0, 0x10
        ctx->r16 = ADD32(ctx->r16, 0X10);
            goto L_80051760;
    }
    // 0x80051788: addiu       $s0, $s0, 0x10
    ctx->r16 = ADD32(ctx->r16, 0X10);
    // 0x8005178C: lwc1        $f0, 0x4C($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X4C);
    // 0x80051790: lwc1        $f2, 0x50($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0X50);
    // 0x80051794: lwc1        $f4, 0x54($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X54);
    // 0x80051798: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x8005179C: swc1        $f0, 0x10($s1)
    MEM_W(0X10, ctx->r17) = ctx->f0.u32l;
    // 0x800517A0: swc1        $f2, 0x14($s1)
    MEM_W(0X14, ctx->r17) = ctx->f2.u32l;
    // 0x800517A4: jal         0x8004CD00
    // 0x800517A8: swc1        $f4, 0x18($s1)
    MEM_W(0X18, ctx->r17) = ctx->f4.u32l;
    func_8004CD00(rdram, ctx);
        goto after_4;
    // 0x800517A8: swc1        $f4, 0x18($s1)
    MEM_W(0X18, ctx->r17) = ctx->f4.u32l;
    after_4:
    // 0x800517AC: lui         $a1, 0x3D08
    ctx->r5 = S32(0X3D08 << 16);
    // 0x800517B0: ori         $a1, $a1, 0x8889
    ctx->r5 = ctx->r5 | 0X8889;
    // 0x800517B4: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x800517B8: sw          $s2, 0x70($a0)
    MEM_W(0X70, ctx->r4) = ctx->r18;
    // 0x800517BC: sw          $s2, 0x74($a0)
    MEM_W(0X74, ctx->r4) = ctx->r18;
    // 0x800517C0: sw          $zero, 0x78($a0)
    MEM_W(0X78, ctx->r4) = 0;
    // 0x800517C4: sw          $zero, 0x7C($a0)
    MEM_W(0X7C, ctx->r4) = 0;
    // 0x800517C8: sw          $zero, 0x80($a0)
    MEM_W(0X80, ctx->r4) = 0;
    // 0x800517CC: sw          $zero, 0x84($a0)
    MEM_W(0X84, ctx->r4) = 0;
    // 0x800517D0: sw          $zero, 0x88($a0)
    MEM_W(0X88, ctx->r4) = 0;
    // 0x800517D4: jal         0x8004D078
    // 0x800517D8: sw          $zero, 0x8C($a0)
    MEM_W(0X8C, ctx->r4) = 0;
    func_8004D078(rdram, ctx);
        goto after_5;
    // 0x800517D8: sw          $zero, 0x8C($a0)
    MEM_W(0X8C, ctx->r4) = 0;
    after_5:
    // 0x800517DC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x800517E0: lw          $a0, 0xB8($s3)
    ctx->r4 = MEM_W(ctx->r19, 0XB8);
    // 0x800517E4: jal         0x8004EFAC
    // 0x800517E8: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    func_8004EFAC(rdram, ctx);
        goto after_6;
    // 0x800517E8: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    after_6:
    // 0x800517EC: lw          $ra, 0x30($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X30);
    // 0x800517F0: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x800517F4: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x800517F8: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x800517FC: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80051800: ldc1        $f24, 0x48($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X48);
    // 0x80051804: ldc1        $f22, 0x40($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X40);
    // 0x80051808: ldc1        $f20, 0x38($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X38);
    // 0x8005180C: jr          $ra
    // 0x80051810: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x80051810: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}
RECOMP_FUNC void func_80051814(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80051814: addiu       $sp, $sp, -0x98
    ctx->r29 = ADD32(ctx->r29, -0X98);
    // 0x80051818: sw          $s4, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r20;
    // 0x8005181C: addu        $s4, $a0, $zero
    ctx->r20 = ADD32(ctx->r4, 0);
    // 0x80051820: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x80051824: sw          $ra, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r31;
    // 0x80051828: sw          $s5, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r21;
    // 0x8005182C: sw          $s3, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r19;
    // 0x80051830: sw          $s2, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r18;
    // 0x80051834: sw          $s1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r17;
    // 0x80051838: sw          $s0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r16;
    // 0x8005183C: sdc1        $f28, 0x90($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0X90, ctx->r29);
    // 0x80051840: sdc1        $f26, 0x88($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X88, ctx->r29);
    // 0x80051844: sdc1        $f24, 0x80($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X80, ctx->r29);
    // 0x80051848: sdc1        $f22, 0x78($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X78, ctx->r29);
    // 0x8005184C: sdc1        $f20, 0x70($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X70, ctx->r29);
    // 0x80051850: lw          $v1, 0xB8($s4)
    ctx->r3 = MEM_W(ctx->r20, 0XB8);
    // 0x80051854: addiu       $s1, $v0, -0x72E8
    ctx->r17 = ADD32(ctx->r2, -0X72E8);
    // 0x80051858: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x8005185C: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80051860: sll         $v0, $v0, 4
    ctx->r2 = S32(ctx->r2 << 4);
    // 0x80051864: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80051868: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8005186C: addu        $v0, $v0, $s1
    ctx->r2 = ADD32(ctx->r2, ctx->r17);
    // 0x80051870: lw          $v0, 0x4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X4);
    // 0x80051874: lhu         $v0, 0x4($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X4);
    // 0x80051878: addiu       $s5, $zero, 0x3
    ctx->r21 = ADD32(0, 0X3);
    // 0x8005187C: bne         $v0, $s5, L_80051898
    if (ctx->r2 != ctx->r21) {
        // 0x80051880: lui         $v0, 0x8014
        ctx->r2 = S32(0X8014 << 16);
            goto L_80051898;
    }
    // 0x80051880: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x80051884: jal         0x80003430
    // 0x80051888: nop

    rand_recomp(rdram, ctx);
        goto after_0;
    // 0x80051888: nop

    after_0:
    // 0x8005188C: and         $v0, $v0, $s5
    ctx->r2 = ctx->r2 & ctx->r21;
    // 0x80051890: bne         $v0, $zero, L_80052074
    if (ctx->r2 != 0) {
        // 0x80051894: lui         $v0, 0x8014
        ctx->r2 = S32(0X8014 << 16);
            goto L_80052074;
    }
    // 0x80051894: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
L_80051898:
    // 0x80051898: lw          $a1, 0xB8($s4)
    ctx->r5 = MEM_W(ctx->r20, 0XB8);
    // 0x8005189C: addiu       $v0, $v0, -0x75D8
    ctx->r2 = ADD32(ctx->r2, -0X75D8);
    // 0x800518A0: sll         $v1, $a1, 5
    ctx->r3 = S32(ctx->r5 << 5);
    // 0x800518A4: subu        $v1, $v1, $a1
    ctx->r3 = SUB32(ctx->r3, ctx->r5);
    // 0x800518A8: sll         $v1, $v1, 5
    ctx->r3 = S32(ctx->r3 << 5);
    // 0x800518AC: addu        $s2, $v1, $v0
    ctx->r18 = ADD32(ctx->r3, ctx->r2);
    // 0x800518B0: addiu       $s0, $s2, 0x28
    ctx->r16 = ADD32(ctx->r18, 0X28);
    // 0x800518B4: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x800518B8: sll         $v0, $a1, 2
    ctx->r2 = S32(ctx->r5 << 2);
    // 0x800518BC: addu        $v0, $v0, $a1
    ctx->r2 = ADD32(ctx->r2, ctx->r5);
    // 0x800518C0: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800518C4: addu        $v0, $v0, $a1
    ctx->r2 = ADD32(ctx->r2, ctx->r5);
    // 0x800518C8: sll         $v0, $v0, 5
    ctx->r2 = S32(ctx->r2 << 5);
    // 0x800518CC: lui         $v1, 0x8014
    ctx->r3 = S32(0X8014 << 16);
    // 0x800518D0: addiu       $v1, $v1, -0x7FF4
    ctx->r3 = ADD32(ctx->r3, -0X7FF4);
    // 0x800518D4: addu        $s3, $v0, $v1
    ctx->r19 = ADD32(ctx->r2, ctx->r3);
    // 0x800518D8: sh          $zero, 0x2($s2)
    MEM_H(0X2, ctx->r18) = 0;
    // 0x800518DC: sh          $zero, 0x4($s2)
    MEM_H(0X4, ctx->r18) = 0;
    // 0x800518E0: jal         0x8001CA50
    // 0x800518E4: sh          $zero, 0x0($s2)
    MEM_H(0X0, ctx->r18) = 0;
    func_8001CA50(rdram, ctx);
        goto after_1;
    // 0x800518E4: sh          $zero, 0x0($s2)
    MEM_H(0X0, ctx->r18) = 0;
    after_1:
    // 0x800518E8: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x800518EC: addiu       $v0, $v0, -0x13EC
    ctx->r2 = ADD32(ctx->r2, -0X13EC);
    // 0x800518F0: sw          $v0, 0x70($s2)
    MEM_W(0X70, ctx->r18) = ctx->r2;
    // 0x800518F4: sw          $v0, 0x74($s2)
    MEM_W(0X74, ctx->r18) = ctx->r2;
    // 0x800518F8: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x800518FC: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80051900: lwc1        $f4, -0x5570($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X5570);
    // 0x80051904: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80051908: lwc1        $f0, -0x556C($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X556C);
    // 0x8005190C: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80051910: lwc1        $f28, -0x5568($at)
    ctx->f28.u32l = MEM_W(ctx->r1, -0X5568);
    // 0x80051914: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80051918: lwc1        $f26, -0x5564($at)
    ctx->f26.u32l = MEM_W(ctx->r1, -0X5564);
    // 0x8005191C: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80051920: lwc1        $f2, -0x5560($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X5560);
    // 0x80051924: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80051928: lwc1        $f24, -0x555C($at)
    ctx->f24.u32l = MEM_W(ctx->r1, -0X555C);
    // 0x8005192C: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80051930: lwc1        $f22, -0x5558($at)
    ctx->f22.u32l = MEM_W(ctx->r1, -0X5558);
    // 0x80051934: addiu       $v0, $v0, -0x7D98
    ctx->r2 = ADD32(ctx->r2, -0X7D98);
    // 0x80051938: sw          $zero, 0x58($s2)
    MEM_W(0X58, ctx->r18) = 0;
    // 0x8005193C: sw          $zero, 0x5C($s2)
    MEM_W(0X5C, ctx->r18) = 0;
    // 0x80051940: sw          $zero, 0x60($s2)
    MEM_W(0X60, ctx->r18) = 0;
    // 0x80051944: sw          $zero, 0x64($s2)
    MEM_W(0X64, ctx->r18) = 0;
    // 0x80051948: sw          $zero, 0x68($s2)
    MEM_W(0X68, ctx->r18) = 0;
    // 0x8005194C: sw          $zero, 0x6C($s2)
    MEM_W(0X6C, ctx->r18) = 0;
    // 0x80051950: sw          $zero, 0x78($s2)
    MEM_W(0X78, ctx->r18) = 0;
    // 0x80051954: sw          $zero, 0x7C($s2)
    MEM_W(0X7C, ctx->r18) = 0;
    // 0x80051958: sw          $zero, 0x80($s2)
    MEM_W(0X80, ctx->r18) = 0;
    // 0x8005195C: sw          $zero, 0x84($s2)
    MEM_W(0X84, ctx->r18) = 0;
    // 0x80051960: sw          $zero, 0x88($s2)
    MEM_W(0X88, ctx->r18) = 0;
    // 0x80051964: sw          $zero, 0x8C($s2)
    MEM_W(0X8C, ctx->r18) = 0;
    // 0x80051968: sw          $zero, 0x10($s2)
    MEM_W(0X10, ctx->r18) = 0;
    // 0x8005196C: sw          $zero, 0x14($s2)
    MEM_W(0X14, ctx->r18) = 0;
    // 0x80051970: sw          $zero, 0x18($s2)
    MEM_W(0X18, ctx->r18) = 0;
    // 0x80051974: sw          $zero, 0x1C($s2)
    MEM_W(0X1C, ctx->r18) = 0;
    // 0x80051978: sw          $zero, 0x20($s2)
    MEM_W(0X20, ctx->r18) = 0;
    // 0x8005197C: sw          $zero, 0x24($s2)
    MEM_W(0X24, ctx->r18) = 0;
    // 0x80051980: sw          $zero, 0x90($s2)
    MEM_W(0X90, ctx->r18) = 0;
    // 0x80051984: sw          $zero, 0x94($s2)
    MEM_W(0X94, ctx->r18) = 0;
    // 0x80051988: sw          $zero, 0x98($s2)
    MEM_W(0X98, ctx->r18) = 0;
    // 0x8005198C: sw          $zero, 0x9C($s2)
    MEM_W(0X9C, ctx->r18) = 0;
    // 0x80051990: sw          $zero, 0xA0($s2)
    MEM_W(0XA0, ctx->r18) = 0;
    // 0x80051994: sw          $v0, 0xBC($s2)
    MEM_W(0XBC, ctx->r18) = ctx->r2;
    // 0x80051998: sw          $v0, 0xC0($s2)
    MEM_W(0XC0, ctx->r18) = ctx->r2;
    // 0x8005199C: sw          $zero, 0xC4($s2)
    MEM_W(0XC4, ctx->r18) = 0;
    // 0x800519A0: sw          $zero, 0xCC($s2)
    MEM_W(0XCC, ctx->r18) = 0;
    // 0x800519A4: sw          $zero, 0xD0($s2)
    MEM_W(0XD0, ctx->r18) = 0;
    // 0x800519A8: sw          $zero, 0xD8($s2)
    MEM_W(0XD8, ctx->r18) = 0;
    // 0x800519AC: sw          $zero, 0xE0($s2)
    MEM_W(0XE0, ctx->r18) = 0;
    // 0x800519B0: swc1        $f4, 0xC8($s2)
    MEM_W(0XC8, ctx->r18) = ctx->f4.u32l;
    // 0x800519B4: sw          $zero, 0xDC($s2)
    MEM_W(0XDC, ctx->r18) = 0;
    // 0x800519B8: swc1        $f0, 0xD4($s2)
    MEM_W(0XD4, ctx->r18) = ctx->f0.u32l;
    // 0x800519BC: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x800519C0: lwc1        $f0, -0x5554($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X5554);
    // 0x800519C4: lhu         $v1, 0x0($s2)
    ctx->r3 = MEM_HU(ctx->r18, 0X0);
    // 0x800519C8: swc1        $f2, 0xA4($s2)
    MEM_W(0XA4, ctx->r18) = ctx->f2.u32l;
    // 0x800519CC: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x800519D0: lwc1        $f2, -0x5550($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X5550);
    // 0x800519D4: ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
    // 0x800519D8: swc1        $f28, 0xE4($s2)
    MEM_W(0XE4, ctx->r18) = ctx->f28.u32l;
    // 0x800519DC: swc1        $f26, 0xE8($s2)
    MEM_W(0XE8, ctx->r18) = ctx->f26.u32l;
    // 0x800519E0: sw          $zero, 0xA8($s2)
    MEM_W(0XA8, ctx->r18) = 0;
    // 0x800519E4: swc1        $f24, 0xAC($s2)
    MEM_W(0XAC, ctx->r18) = ctx->f24.u32l;
    // 0x800519E8: swc1        $f22, 0xB0($s2)
    MEM_W(0XB0, ctx->r18) = ctx->f22.u32l;
    // 0x800519EC: sw          $zero, 0xEC($s2)
    MEM_W(0XEC, ctx->r18) = 0;
    // 0x800519F0: sh          $v0, 0xF4($s2)
    MEM_H(0XF4, ctx->r18) = ctx->r2;
    // 0x800519F4: sw          $zero, 0xF0($s2)
    MEM_W(0XF0, ctx->r18) = 0;
    // 0x800519F8: sw          $zero, 0xB4($s2)
    MEM_W(0XB4, ctx->r18) = 0;
    // 0x800519FC: swc1        $f4, 0x94($s2)
    MEM_W(0X94, ctx->r18) = ctx->f4.u32l;
    // 0x80051A00: ori         $v1, $v1, 0x53
    ctx->r3 = ctx->r3 | 0X53;
    // 0x80051A04: swc1        $f0, 0xB8($s2)
    MEM_W(0XB8, ctx->r18) = ctx->f0.u32l;
    // 0x80051A08: swc1        $f2, 0xB8($s2)
    MEM_W(0XB8, ctx->r18) = ctx->f2.u32l;
    // 0x80051A0C: jal         0x80003430
    // 0x80051A10: sh          $v1, 0x0($s2)
    MEM_H(0X0, ctx->r18) = ctx->r3;
    rand_recomp(rdram, ctx);
        goto after_2;
    // 0x80051A10: sh          $v1, 0x0($s2)
    MEM_H(0X0, ctx->r18) = ctx->r3;
    after_2:
    // 0x80051A14: lw          $a0, 0xB8($s4)
    ctx->r4 = MEM_W(ctx->r20, 0XB8);
    // 0x80051A18: sll         $v1, $a0, 2
    ctx->r3 = S32(ctx->r4 << 2);
    // 0x80051A1C: addu        $v1, $v1, $a0
    ctx->r3 = ADD32(ctx->r3, ctx->r4);
    // 0x80051A20: sll         $v1, $v1, 4
    ctx->r3 = S32(ctx->r3 << 4);
    // 0x80051A24: addu        $v1, $v1, $a0
    ctx->r3 = ADD32(ctx->r3, ctx->r4);
    // 0x80051A28: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x80051A2C: addu        $v1, $v1, $s1
    ctx->r3 = ADD32(ctx->r3, ctx->r17);
    // 0x80051A30: lw          $v1, 0x4($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X4);
    // 0x80051A34: andi        $a0, $v0, 0x3
    ctx->r4 = ctx->r2 & 0X3;
    // 0x80051A38: lhu         $v0, 0x4($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X4);
    // 0x80051A3C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80051A40: beql        $v0, $a1, L_80051A48
    if (ctx->r2 == ctx->r5) {
        // 0x80051A44: addiu       $a0, $zero, 0x3
        ctx->r4 = ADD32(0, 0X3);
            goto L_80051A48;
    }
    goto skip_0;
    // 0x80051A44: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    skip_0:
L_80051A48:
    // 0x80051A48: lwc1        $f0, 0x8($s3)
    ctx->f0.u32l = MEM_W(ctx->r19, 0X8);
    // 0x80051A4C: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    // 0x80051A50: lwc1        $f0, 0x14($s3)
    ctx->f0.u32l = MEM_W(ctx->r19, 0X14);
    // 0x80051A54: andi        $v1, $a0, 0xFFFF
    ctx->r3 = ctx->r4 & 0XFFFF;
    // 0x80051A58: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    // 0x80051A5C: lwc1        $f0, 0x20($s3)
    ctx->f0.u32l = MEM_W(ctx->r19, 0X20);
    // 0x80051A60: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80051A64: beq         $v1, $a0, L_80051C34
    if (ctx->r3 == ctx->r4) {
        // 0x80051A68: swc1        $f0, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
            goto L_80051C34;
    }
    // 0x80051A68: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    // 0x80051A6C: slti        $v0, $v1, 0x2
    ctx->r2 = SIGNED(ctx->r3) < 0X2 ? 1 : 0;
    // 0x80051A70: bnel        $v0, $zero, L_80051A8C
    if (ctx->r2 != 0) {
        // 0x80051A74: addu        $a0, $s0, $zero
        ctx->r4 = ADD32(ctx->r16, 0);
            goto L_80051A8C;
    }
    goto skip_1;
    // 0x80051A74: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    skip_1:
    // 0x80051A78: beq         $v1, $a1, L_80051D74
    if (ctx->r3 == ctx->r5) {
        // 0x80051A7C: addiu       $v0, $zero, 0x4
        ctx->r2 = ADD32(0, 0X4);
            goto L_80051D74;
    }
    // 0x80051A7C: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // 0x80051A80: beql        $v1, $s5, L_80051EEC
    if (ctx->r3 == ctx->r21) {
        // 0x80051A84: sh          $v1, 0x2($s2)
        MEM_H(0X2, ctx->r18) = ctx->r3;
            goto L_80051EEC;
    }
    goto skip_2;
    // 0x80051A84: sh          $v1, 0x2($s2)
    MEM_H(0X2, ctx->r18) = ctx->r3;
    skip_2:
    // 0x80051A88: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
L_80051A8C:
    // 0x80051A8C: addu        $v1, $s3, $zero
    ctx->r3 = ADD32(ctx->r19, 0);
    // 0x80051A90: lhu         $v0, 0x0($s2)
    ctx->r2 = MEM_HU(ctx->r18, 0X0);
    // 0x80051A94: addiu       $a2, $s3, 0x30
    ctx->r6 = ADD32(ctx->r19, 0X30);
    // 0x80051A98: sh          $a1, 0x2($s2)
    MEM_H(0X2, ctx->r18) = ctx->r5;
    // 0x80051A9C: sh          $zero, 0x4($s2)
    MEM_H(0X4, ctx->r18) = 0;
    // 0x80051AA0: ori         $v0, $v0, 0x48
    ctx->r2 = ctx->r2 | 0X48;
    // 0x80051AA4: sh          $v0, 0x0($s2)
    MEM_H(0X0, ctx->r18) = ctx->r2;
L_80051AA8:
    // 0x80051AA8: lw          $a3, 0x0($v1)
    ctx->r7 = MEM_W(ctx->r3, 0X0);
    // 0x80051AAC: lw          $t0, 0x4($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X4);
    // 0x80051AB0: lw          $t1, 0x8($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X8);
    // 0x80051AB4: lw          $t2, 0xC($v1)
    ctx->r10 = MEM_W(ctx->r3, 0XC);
    // 0x80051AB8: sw          $a3, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r7;
    // 0x80051ABC: sw          $t0, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r8;
    // 0x80051AC0: sw          $t1, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r9;
    // 0x80051AC4: sw          $t2, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r10;
    // 0x80051AC8: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
    // 0x80051ACC: bne         $v1, $a2, L_80051AA8
    if (ctx->r3 != ctx->r6) {
        // 0x80051AD0: addiu       $a0, $a0, 0x10
        ctx->r4 = ADD32(ctx->r4, 0X10);
            goto L_80051AA8;
    }
    // 0x80051AD0: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    // 0x80051AD4: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    // 0x80051AD8: sw          $zero, 0x78($s2)
    MEM_W(0X78, ctx->r18) = 0;
    // 0x80051ADC: sw          $zero, 0x7C($s2)
    MEM_W(0X7C, ctx->r18) = 0;
    // 0x80051AE0: sw          $zero, 0x80($s2)
    MEM_W(0X80, ctx->r18) = 0;
    // 0x80051AE4: jal         0x800AA350
    // 0x80051AE8: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    func_800AA350(rdram, ctx);
        goto after_3;
    // 0x80051AE8: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    after_3:
    // 0x80051AEC: lwc1        $f0, 0xE8($s4)
    ctx->f0.u32l = MEM_W(ctx->r20, 0XE8);
    // 0x80051AF0: add.s       $f0, $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f0.fl;
    // 0x80051AF4: addiu       $s1, $sp, 0x30
    ctx->r17 = ADD32(ctx->r29, 0X30);
    // 0x80051AF8: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x80051AFC: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80051B00: jal         0x800AA3B4
    // 0x80051B04: addiu       $a2, $sp, 0x10
    ctx->r6 = ADD32(ctx->r29, 0X10);
    func_800AA3B4(rdram, ctx);
        goto after_4;
    // 0x80051B04: addiu       $a2, $sp, 0x10
    ctx->r6 = ADD32(ctx->r29, 0X10);
    after_4:
    // 0x80051B08: lwc1        $f0, 0x24($s3)
    ctx->f0.u32l = MEM_W(ctx->r19, 0X24);
    // 0x80051B0C: lwc1        $f6, 0x30($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X30);
    // 0x80051B10: lwc1        $f2, 0x34($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X34);
    // 0x80051B14: add.s       $f6, $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f0.fl;
    // 0x80051B18: swc1        $f0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f0.u32l;
    // 0x80051B1C: lwc1        $f0, 0x28($s3)
    ctx->f0.u32l = MEM_W(ctx->r19, 0X28);
    // 0x80051B20: add.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x80051B24: swc1        $f0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f0.u32l;
    // 0x80051B28: lwc1        $f4, 0x2C($s3)
    ctx->f4.u32l = MEM_W(ctx->r19, 0X2C);
    // 0x80051B2C: lwc1        $f0, 0x38($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X38);
    // 0x80051B30: add.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f4.fl;
    // 0x80051B34: swc1        $f4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f4.u32l;
    // 0x80051B38: swc1        $f6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f6.u32l;
    // 0x80051B3C: swc1        $f2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f2.u32l;
    // 0x80051B40: jal         0x80003430
    // 0x80051B44: swc1        $f0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f0.u32l;
    rand_recomp(rdram, ctx);
        goto after_5;
    // 0x80051B44: swc1        $f0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f0.u32l;
    after_5:
    // 0x80051B48: addiu       $s0, $sp, 0x40
    ctx->r16 = ADD32(ctx->r29, 0X40);
    // 0x80051B4C: andi        $v0, $v0, 0x7F
    ctx->r2 = ctx->r2 & 0X7F;
    // 0x80051B50: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80051B54: lwc1        $f20, -0x554C($at)
    ctx->f20.u32l = MEM_W(ctx->r1, -0X554C);
    // 0x80051B58: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x80051B5C: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x80051B60: sub.s       $f0, $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f20.fl;
    // 0x80051B64: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80051B68: lwc1        $f2, -0x5548($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X5548);
    // 0x80051B6C: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x80051B70: div.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f2.fl);
    // 0x80051B74: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80051B78: jal         0x8001D038
    // 0x80051B7C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8001D038(rdram, ctx);
        goto after_6;
    // 0x80051B7C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_6:
    // 0x80051B80: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    // 0x80051B84: jal         0x800AA350
    // 0x80051B88: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    func_800AA350(rdram, ctx);
        goto after_7;
    // 0x80051B88: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    after_7:
    // 0x80051B8C: jal         0x80003430
    // 0x80051B90: nop

    rand_recomp(rdram, ctx);
        goto after_8;
    // 0x80051B90: nop

    after_8:
    // 0x80051B94: andi        $v0, $v0, 0x7F
    ctx->r2 = ctx->r2 & 0X7F;
    // 0x80051B98: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x80051B9C: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x80051BA0: sub.s       $f0, $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f20.fl;
    // 0x80051BA4: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80051BA8: lwc1        $f2, -0x5544($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X5544);
    // 0x80051BAC: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x80051BB0: abs.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = fabsf(ctx->f0.fl);
    // 0x80051BB4: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80051BB8: lwc1        $f0, -0x5540($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X5540);
    // 0x80051BBC: add.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x80051BC0: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    // 0x80051BC4: mfc1        $a1, $f2
    ctx->r5 = (int32_t)ctx->f2.u32l;
    // 0x80051BC8: jal         0x800AA3B4
    // 0x80051BCC: addu        $a2, $a0, $zero
    ctx->r6 = ADD32(ctx->r4, 0);
    func_800AA3B4(rdram, ctx);
        goto after_9;
    // 0x80051BCC: addu        $a2, $a0, $zero
    ctx->r6 = ADD32(ctx->r4, 0);
    after_9:
    // 0x80051BD0: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x80051BD4: addiu       $a1, $sp, 0x10
    ctx->r5 = ADD32(ctx->r29, 0X10);
    // 0x80051BD8: jal         0x8001D3C4
    // 0x80051BDC: addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    func_8001D3C4(rdram, ctx);
        goto after_10;
    // 0x80051BDC: addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    after_10:
    // 0x80051BE0: lwc1        $f6, 0x30($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X30);
    // 0x80051BE4: lwc1        $f0, 0x20($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X20);
    // 0x80051BE8: lwc1        $f4, 0x34($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X34);
    // 0x80051BEC: add.s       $f6, $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f0.fl;
    // 0x80051BF0: lwc1        $f0, 0x24($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X24);
    // 0x80051BF4: lwc1        $f2, 0x38($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X38);
    // 0x80051BF8: add.s       $f4, $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f0.fl;
    // 0x80051BFC: lwc1        $f0, 0x28($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X28);
    // 0x80051C00: add.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x80051C04: swc1        $f6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f6.u32l;
    // 0x80051C08: swc1        $f4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f4.u32l;
    // 0x80051C0C: swc1        $f2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f2.u32l;
    // 0x80051C10: swc1        $f6, 0x4C($s2)
    MEM_W(0X4C, ctx->r18) = ctx->f6.u32l;
    // 0x80051C14: lwc1        $f0, 0x24($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X24);
    // 0x80051C18: swc1        $f0, 0x50($s2)
    MEM_W(0X50, ctx->r18) = ctx->f0.u32l;
    // 0x80051C1C: lwc1        $f0, 0x28($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X28);
    // 0x80051C20: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // 0x80051C24: jal         0x8004CD00
    // 0x80051C28: swc1        $f0, 0x54($s2)
    MEM_W(0X54, ctx->r18) = ctx->f0.u32l;
    func_8004CD00(rdram, ctx);
        goto after_11;
    // 0x80051C28: swc1        $f0, 0x54($s2)
    MEM_W(0X54, ctx->r18) = ctx->f0.u32l;
    after_11:
    // 0x80051C2C: j           L_80051FC8
    // 0x80051C30: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
        goto L_80051FC8;
    // 0x80051C30: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
L_80051C34:
    // 0x80051C34: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // 0x80051C38: sh          $a1, 0x2($s2)
    MEM_H(0X2, ctx->r18) = ctx->r5;
    // 0x80051C3C: jal         0x80003430
    // 0x80051C40: sh          $v0, 0x4($s2)
    MEM_H(0X4, ctx->r18) = ctx->r2;
    rand_recomp(rdram, ctx);
        goto after_12;
    // 0x80051C40: sh          $v0, 0x4($s2)
    MEM_H(0X4, ctx->r18) = ctx->r2;
    after_12:
    // 0x80051C44: andi        $v0, $v0, 0x7F
    ctx->r2 = ctx->r2 & 0X7F;
    // 0x80051C48: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80051C4C: lwc1        $f20, -0x553C($at)
    ctx->f20.u32l = MEM_W(ctx->r1, -0X553C);
    // 0x80051C50: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x80051C54: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x80051C58: sub.s       $f0, $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f20.fl;
    // 0x80051C5C: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80051C60: lwc1        $f2, -0x5538($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X5538);
    // 0x80051C64: div.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f2.fl);
    // 0x80051C68: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x80051C6C: add.s       $f0, $f0, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f22.fl;
    // 0x80051C70: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80051C74: lwc1        $f2, -0x5534($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X5534);
    // 0x80051C78: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x80051C7C: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80051C80: lwc1        $f2, -0x5530($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X5530);
    // 0x80051C84: swc1        $f2, 0xDC($s2)
    MEM_W(0XDC, ctx->r18) = ctx->f2.u32l;
    // 0x80051C88: jal         0x80003430
    // 0x80051C8C: swc1        $f0, 0x94($s2)
    MEM_W(0X94, ctx->r18) = ctx->f0.u32l;
    rand_recomp(rdram, ctx);
        goto after_13;
    // 0x80051C8C: swc1        $f0, 0x94($s2)
    MEM_W(0X94, ctx->r18) = ctx->f0.u32l;
    after_13:
    // 0x80051C90: andi        $v0, $v0, 0x7F
    ctx->r2 = ctx->r2 & 0X7F;
    // 0x80051C94: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x80051C98: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x80051C9C: sub.s       $f0, $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f20.fl;
    // 0x80051CA0: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80051CA4: lwc1        $f2, -0x552C($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X552C);
    // 0x80051CA8: div.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f2.fl);
    // 0x80051CAC: abs.s       $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = fabsf(ctx->f0.fl);
    // 0x80051CB0: jal         0x80003430
    // 0x80051CB4: swc1        $f8, 0xD0($s2)
    MEM_W(0XD0, ctx->r18) = ctx->f8.u32l;
    rand_recomp(rdram, ctx);
        goto after_14;
    // 0x80051CB4: swc1        $f8, 0xD0($s2)
    MEM_W(0XD0, ctx->r18) = ctx->f8.u32l;
    after_14:
    // 0x80051CB8: andi        $v0, $v0, 0x7F
    ctx->r2 = ctx->r2 & 0X7F;
    // 0x80051CBC: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x80051CC0: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x80051CC4: sub.s       $f0, $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f20.fl;
    // 0x80051CC8: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80051CCC: lwc1        $f2, -0x5528($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X5528);
    // 0x80051CD0: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x80051CD4: abs.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = fabsf(ctx->f0.fl);
    // 0x80051CD8: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80051CDC: lwc1        $f0, -0x5524($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X5524);
    // 0x80051CE0: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x80051CE4: nop

    // 0x80051CE8: bc1fl       L_80051CF4
    if (!c1cs) {
        // 0x80051CEC: swc1        $f28, 0xD8($s2)
        MEM_W(0XD8, ctx->r18) = ctx->f28.u32l;
            goto L_80051CF4;
    }
    goto skip_3;
    // 0x80051CEC: swc1        $f28, 0xD8($s2)
    MEM_W(0XD8, ctx->r18) = ctx->f28.u32l;
    skip_3:
    // 0x80051CF0: swc1        $f26, 0xD8($s2)
    MEM_W(0XD8, ctx->r18) = ctx->f26.u32l;
L_80051CF4:
    // 0x80051CF4: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80051CF8: lwc1        $f0, -0x5520($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X5520);
    // 0x80051CFC: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80051D00: sw          $zero, 0x58($s2)
    MEM_W(0X58, ctx->r18) = 0;
    // 0x80051D04: sw          $zero, 0x5C($s2)
    MEM_W(0X5C, ctx->r18) = 0;
    // 0x80051D08: sw          $zero, 0x60($s2)
    MEM_W(0X60, ctx->r18) = 0;
    // 0x80051D0C: swc1        $f0, 0xE0($s2)
    MEM_W(0XE0, ctx->r18) = ctx->f0.u32l;
    // 0x80051D10: lw          $v1, 0xB8($s4)
    ctx->r3 = MEM_W(ctx->r20, 0XB8);
    // 0x80051D14: addiu       $a0, $a0, -0x72E8
    ctx->r4 = ADD32(ctx->r4, -0X72E8);
    // 0x80051D18: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x80051D1C: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80051D20: sll         $v0, $v0, 4
    ctx->r2 = S32(ctx->r2 << 4);
    // 0x80051D24: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80051D28: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80051D2C: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x80051D30: lw          $v0, 0x4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X4);
    // 0x80051D34: addiu       $a0, $s2, 0x28
    ctx->r4 = ADD32(ctx->r18, 0X28);
    // 0x80051D38: addiu       $v1, $v0, 0x28
    ctx->r3 = ADD32(ctx->r2, 0X28);
    // 0x80051D3C: addiu       $v0, $v0, 0x58
    ctx->r2 = ADD32(ctx->r2, 0X58);
L_80051D40:
    // 0x80051D40: lw          $a3, 0x0($v1)
    ctx->r7 = MEM_W(ctx->r3, 0X0);
    // 0x80051D44: lw          $t0, 0x4($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X4);
    // 0x80051D48: lw          $t1, 0x8($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X8);
    // 0x80051D4C: lw          $t2, 0xC($v1)
    ctx->r10 = MEM_W(ctx->r3, 0XC);
    // 0x80051D50: sw          $a3, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r7;
    // 0x80051D54: sw          $t0, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r8;
    // 0x80051D58: sw          $t1, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r9;
    // 0x80051D5C: sw          $t2, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r10;
    // 0x80051D60: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
    // 0x80051D64: bne         $v1, $v0, L_80051D40
    if (ctx->r3 != ctx->r2) {
        // 0x80051D68: addiu       $a0, $a0, 0x10
        ctx->r4 = ADD32(ctx->r4, 0X10);
            goto L_80051D40;
    }
    // 0x80051D68: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    // 0x80051D6C: j           L_80051FC8
    // 0x80051D70: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
        goto L_80051FC8;
    // 0x80051D70: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
L_80051D74:
    // 0x80051D74: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80051D78: lwc1        $f0, -0x551C($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X551C);
    // 0x80051D7C: sh          $v1, 0x2($s2)
    MEM_H(0X2, ctx->r18) = ctx->r3;
    // 0x80051D80: sh          $v0, 0x4($s2)
    MEM_H(0X4, ctx->r18) = ctx->r2;
    // 0x80051D84: swc1        $f0, 0x9C($s2)
    MEM_W(0X9C, ctx->r18) = ctx->f0.u32l;
    // 0x80051D88: jal         0x80003430
    // 0x80051D8C: swc1        $f0, 0x98($s2)
    MEM_W(0X98, ctx->r18) = ctx->f0.u32l;
    rand_recomp(rdram, ctx);
        goto after_15;
    // 0x80051D8C: swc1        $f0, 0x98($s2)
    MEM_W(0X98, ctx->r18) = ctx->f0.u32l;
    after_15:
    // 0x80051D90: andi        $v0, $v0, 0x7F
    ctx->r2 = ctx->r2 & 0X7F;
    // 0x80051D94: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80051D98: lwc1        $f20, -0x5518($at)
    ctx->f20.u32l = MEM_W(ctx->r1, -0X5518);
    // 0x80051D9C: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x80051DA0: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x80051DA4: sub.s       $f0, $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f20.fl;
    // 0x80051DA8: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80051DAC: lwc1        $f2, -0x5514($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X5514);
    // 0x80051DB0: div.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f2.fl);
    // 0x80051DB4: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x80051DB8: add.s       $f0, $f0, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f22.fl;
    // 0x80051DBC: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80051DC0: lwc1        $f2, -0x5510($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X5510);
    // 0x80051DC4: lhu         $v0, 0x0($s2)
    ctx->r2 = MEM_HU(ctx->r18, 0X0);
    // 0x80051DC8: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x80051DCC: sw          $zero, 0xDC($s2)
    MEM_W(0XDC, ctx->r18) = 0;
    // 0x80051DD0: swc1        $f24, 0xAC($s2)
    MEM_W(0XAC, ctx->r18) = ctx->f24.u32l;
    // 0x80051DD4: ori         $v0, $v0, 0x40
    ctx->r2 = ctx->r2 | 0X40;
    // 0x80051DD8: sh          $v0, 0x0($s2)
    MEM_H(0X0, ctx->r18) = ctx->r2;
    // 0x80051DDC: jal         0x80003430
    // 0x80051DE0: swc1        $f0, 0x94($s2)
    MEM_W(0X94, ctx->r18) = ctx->f0.u32l;
    rand_recomp(rdram, ctx);
        goto after_16;
    // 0x80051DE0: swc1        $f0, 0x94($s2)
    MEM_W(0X94, ctx->r18) = ctx->f0.u32l;
    after_16:
    // 0x80051DE4: andi        $v0, $v0, 0x7F
    ctx->r2 = ctx->r2 & 0X7F;
    // 0x80051DE8: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x80051DEC: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x80051DF0: sub.s       $f0, $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f20.fl;
    // 0x80051DF4: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80051DF8: lwc1        $f2, -0x550C($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X550C);
    // 0x80051DFC: div.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f2.fl);
    // 0x80051E00: abs.s       $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = fabsf(ctx->f0.fl);
    // 0x80051E04: swc1        $f8, 0xD0($s2)
    MEM_W(0XD0, ctx->r18) = ctx->f8.u32l;
    // 0x80051E08: jal         0x80003430
    // 0x80051E0C: sw          $zero, 0xD8($s2)
    MEM_W(0XD8, ctx->r18) = 0;
    rand_recomp(rdram, ctx);
        goto after_17;
    // 0x80051E0C: sw          $zero, 0xD8($s2)
    MEM_W(0XD8, ctx->r18) = 0;
    after_17:
    // 0x80051E10: andi        $v0, $v0, 0x7F
    ctx->r2 = ctx->r2 & 0X7F;
    // 0x80051E14: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x80051E18: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x80051E1C: sub.s       $f0, $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f20.fl;
    // 0x80051E20: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80051E24: lwc1        $f2, -0x5508($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X5508);
    // 0x80051E28: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x80051E2C: abs.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = fabsf(ctx->f0.fl);
    // 0x80051E30: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80051E34: lwc1        $f0, -0x5504($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X5504);
    // 0x80051E38: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x80051E3C: nop

    // 0x80051E40: bc1f        L_80051E54
    if (!c1cs) {
        // 0x80051E44: nop
    
            goto L_80051E54;
    }
    // 0x80051E44: nop

    // 0x80051E48: lwc1        $f0, 0xD0($s2)
    ctx->f0.u32l = MEM_W(ctx->r18, 0XD0);
    // 0x80051E4C: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
    // 0x80051E50: swc1        $f0, 0xD0($s2)
    MEM_W(0XD0, ctx->r18) = ctx->f0.u32l;
L_80051E54:
    // 0x80051E54: jal         0x80003430
    // 0x80051E58: nop

    rand_recomp(rdram, ctx);
        goto after_18;
    // 0x80051E58: nop

    after_18:
    // 0x80051E5C: andi        $v0, $v0, 0x7F
    ctx->r2 = ctx->r2 & 0X7F;
    // 0x80051E60: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x80051E64: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x80051E68: sub.s       $f0, $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f20.fl;
    // 0x80051E6C: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80051E70: lwc1        $f2, -0x5500($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X5500);
    // 0x80051E74: div.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f2.fl);
    // 0x80051E78: abs.s       $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = fabsf(ctx->f0.fl);
    // 0x80051E7C: swc1        $f8, 0xE0($s2)
    MEM_W(0XE0, ctx->r18) = ctx->f8.u32l;
    // 0x80051E80: sw          $zero, 0x58($s2)
    MEM_W(0X58, ctx->r18) = 0;
    // 0x80051E84: sw          $zero, 0x5C($s2)
    MEM_W(0X5C, ctx->r18) = 0;
    // 0x80051E88: sw          $zero, 0x60($s2)
    MEM_W(0X60, ctx->r18) = 0;
    // 0x80051E8C: lw          $v1, 0xB8($s4)
    ctx->r3 = MEM_W(ctx->r20, 0XB8);
    // 0x80051E90: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x80051E94: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80051E98: sll         $v0, $v0, 4
    ctx->r2 = S32(ctx->r2 << 4);
    // 0x80051E9C: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80051EA0: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80051EA4: addu        $v0, $v0, $s1
    ctx->r2 = ADD32(ctx->r2, ctx->r17);
    // 0x80051EA8: lw          $v0, 0x4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X4);
    // 0x80051EAC: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x80051EB0: addiu       $v1, $v0, 0x28
    ctx->r3 = ADD32(ctx->r2, 0X28);
    // 0x80051EB4: addiu       $v0, $v0, 0x58
    ctx->r2 = ADD32(ctx->r2, 0X58);
L_80051EB8:
    // 0x80051EB8: lw          $a3, 0x0($v1)
    ctx->r7 = MEM_W(ctx->r3, 0X0);
    // 0x80051EBC: lw          $t0, 0x4($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X4);
    // 0x80051EC0: lw          $t1, 0x8($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X8);
    // 0x80051EC4: lw          $t2, 0xC($v1)
    ctx->r10 = MEM_W(ctx->r3, 0XC);
    // 0x80051EC8: sw          $a3, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r7;
    // 0x80051ECC: sw          $t0, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r8;
    // 0x80051ED0: sw          $t1, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r9;
    // 0x80051ED4: sw          $t2, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r10;
    // 0x80051ED8: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
    // 0x80051EDC: bne         $v1, $v0, L_80051EB8
    if (ctx->r3 != ctx->r2) {
        // 0x80051EE0: addiu       $a0, $a0, 0x10
        ctx->r4 = ADD32(ctx->r4, 0X10);
            goto L_80051EB8;
    }
    // 0x80051EE0: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    // 0x80051EE4: j           L_80051FC8
    // 0x80051EE8: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
        goto L_80051FC8;
    // 0x80051EE8: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
L_80051EEC:
    // 0x80051EEC: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80051EF0: lwc1        $f0, -0x54FC($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X54FC);
    // 0x80051EF4: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80051EF8: lwc1        $f2, -0x54F8($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X54F8);
    // 0x80051EFC: sh          $a0, 0x4($s2)
    MEM_H(0X4, ctx->r18) = ctx->r4;
    // 0x80051F00: sw          $zero, 0xDC($s2)
    MEM_W(0XDC, ctx->r18) = 0;
    // 0x80051F04: swc1        $f0, 0x9C($s2)
    MEM_W(0X9C, ctx->r18) = ctx->f0.u32l;
    // 0x80051F08: swc1        $f0, 0x98($s2)
    MEM_W(0X98, ctx->r18) = ctx->f0.u32l;
    // 0x80051F0C: jal         0x80003430
    // 0x80051F10: swc1        $f2, 0x94($s2)
    MEM_W(0X94, ctx->r18) = ctx->f2.u32l;
    rand_recomp(rdram, ctx);
        goto after_19;
    // 0x80051F10: swc1        $f2, 0x94($s2)
    MEM_W(0X94, ctx->r18) = ctx->f2.u32l;
    after_19:
    // 0x80051F14: andi        $v0, $v0, 0x7F
    ctx->r2 = ctx->r2 & 0X7F;
    // 0x80051F18: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x80051F1C: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x80051F20: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80051F24: lwc1        $f2, -0x54F4($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X54F4);
    // 0x80051F28: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80051F2C: lwc1        $f4, -0x54F0($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X54F0);
    // 0x80051F30: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x80051F34: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80051F38: lwc1        $f2, -0x54EC($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X54EC);
    // 0x80051F3C: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80051F40: lwc1        $f6, -0x54E8($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X54E8);
    // 0x80051F44: div.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f2.fl);
    // 0x80051F48: mul.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x80051F4C: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80051F50: lwc1        $f2, -0x54E4($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X54E4);
    // 0x80051F54: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80051F58: lwc1        $f4, -0x54E0($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X54E0);
    // 0x80051F5C: swc1        $f6, 0xAC($s2)
    MEM_W(0XAC, ctx->r18) = ctx->f6.u32l;
    // 0x80051F60: swc1        $f2, 0x5C($s2)
    MEM_W(0X5C, ctx->r18) = ctx->f2.u32l;
    // 0x80051F64: swc1        $f4, 0x60($s2)
    MEM_W(0X60, ctx->r18) = ctx->f4.u32l;
    // 0x80051F68: swc1        $f0, 0x58($s2)
    MEM_W(0X58, ctx->r18) = ctx->f0.u32l;
    // 0x80051F6C: lw          $v1, 0xB8($s4)
    ctx->r3 = MEM_W(ctx->r20, 0XB8);
    // 0x80051F70: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x80051F74: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80051F78: sll         $v0, $v0, 4
    ctx->r2 = S32(ctx->r2 << 4);
    // 0x80051F7C: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80051F80: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80051F84: addu        $v0, $v0, $s1
    ctx->r2 = ADD32(ctx->r2, ctx->r17);
    // 0x80051F88: lw          $v0, 0x4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X4);
    // 0x80051F8C: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x80051F90: addiu       $v1, $v0, 0x28
    ctx->r3 = ADD32(ctx->r2, 0X28);
    // 0x80051F94: addiu       $v0, $v0, 0x58
    ctx->r2 = ADD32(ctx->r2, 0X58);
L_80051F98:
    // 0x80051F98: lw          $a3, 0x0($v1)
    ctx->r7 = MEM_W(ctx->r3, 0X0);
    // 0x80051F9C: lw          $t0, 0x4($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X4);
    // 0x80051FA0: lw          $t1, 0x8($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X8);
    // 0x80051FA4: lw          $t2, 0xC($v1)
    ctx->r10 = MEM_W(ctx->r3, 0XC);
    // 0x80051FA8: sw          $a3, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r7;
    // 0x80051FAC: sw          $t0, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r8;
    // 0x80051FB0: sw          $t1, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r9;
    // 0x80051FB4: sw          $t2, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r10;
    // 0x80051FB8: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
    // 0x80051FBC: bne         $v1, $v0, L_80051F98
    if (ctx->r3 != ctx->r2) {
        // 0x80051FC0: addiu       $a0, $a0, 0x10
        ctx->r4 = ADD32(ctx->r4, 0X10);
            goto L_80051F98;
    }
    // 0x80051FC0: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    // 0x80051FC4: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
L_80051FC8:
    // 0x80051FC8: lw          $v1, 0xB8($s4)
    ctx->r3 = MEM_W(ctx->r20, 0XB8);
    // 0x80051FCC: addiu       $a0, $a0, -0x72E8
    ctx->r4 = ADD32(ctx->r4, -0X72E8);
    // 0x80051FD0: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x80051FD4: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80051FD8: sll         $v0, $v0, 4
    ctx->r2 = S32(ctx->r2 << 4);
    // 0x80051FDC: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80051FE0: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80051FE4: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x80051FE8: lw          $v0, 0x4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X4);
    // 0x80051FEC: lhu         $v1, 0x4($v0)
    ctx->r3 = MEM_HU(ctx->r2, 0X4);
    // 0x80051FF0: lwc1        $f0, 0x4C($s2)
    ctx->f0.u32l = MEM_W(ctx->r18, 0X4C);
    // 0x80051FF4: lwc1        $f2, 0x50($s2)
    ctx->f2.u32l = MEM_W(ctx->r18, 0X50);
    // 0x80051FF8: lwc1        $f4, 0x54($s2)
    ctx->f4.u32l = MEM_W(ctx->r18, 0X54);
    // 0x80051FFC: swc1        $f0, 0x10($s2)
    MEM_W(0X10, ctx->r18) = ctx->f0.u32l;
    // 0x80052000: swc1        $f2, 0x14($s2)
    MEM_W(0X14, ctx->r18) = ctx->f2.u32l;
    // 0x80052004: swc1        $f4, 0x18($s2)
    MEM_W(0X18, ctx->r18) = ctx->f4.u32l;
    // 0x80052008: lw          $a3, 0x58($s2)
    ctx->r7 = MEM_W(ctx->r18, 0X58);
    // 0x8005200C: lw          $t0, 0x5C($s2)
    ctx->r8 = MEM_W(ctx->r18, 0X5C);
    // 0x80052010: lw          $t1, 0x60($s2)
    ctx->r9 = MEM_W(ctx->r18, 0X60);
    // 0x80052014: sw          $a3, 0x64($s2)
    MEM_W(0X64, ctx->r18) = ctx->r7;
    // 0x80052018: sw          $t0, 0x68($s2)
    MEM_W(0X68, ctx->r18) = ctx->r8;
    // 0x8005201C: sw          $t1, 0x6C($s2)
    MEM_W(0X6C, ctx->r18) = ctx->r9;
    // 0x80052020: jal         0x8004CD00
    // 0x80052024: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    func_8004CD00(rdram, ctx);
        goto after_20;
    // 0x80052024: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    after_20:
    // 0x80052028: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8005202C: lwc1        $f0, -0x54DC($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X54DC);
    // 0x80052030: lwc1        $f2, 0x9C($s2)
    ctx->f2.u32l = MEM_W(ctx->r18, 0X9C);
    // 0x80052034: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80052038: sw          $s3, 0x70($s2)
    MEM_W(0X70, ctx->r18) = ctx->r19;
    // 0x8005203C: sw          $s3, 0x74($s2)
    MEM_W(0X74, ctx->r18) = ctx->r19;
    // 0x80052040: sw          $zero, 0x78($s2)
    MEM_W(0X78, ctx->r18) = 0;
    // 0x80052044: sw          $zero, 0x7C($s2)
    MEM_W(0X7C, ctx->r18) = 0;
    // 0x80052048: sw          $zero, 0x80($s2)
    MEM_W(0X80, ctx->r18) = 0;
    // 0x8005204C: sw          $zero, 0x84($s2)
    MEM_W(0X84, ctx->r18) = 0;
    // 0x80052050: sw          $zero, 0x88($s2)
    MEM_W(0X88, ctx->r18) = 0;
    // 0x80052054: sw          $zero, 0x8C($s2)
    MEM_W(0X8C, ctx->r18) = 0;
    // 0x80052058: sw          $zero, 0x90($s2)
    MEM_W(0X90, ctx->r18) = 0;
    // 0x8005205C: sw          $zero, 0xA4($s2)
    MEM_W(0XA4, ctx->r18) = 0;
    // 0x80052060: swc1        $f0, 0xB8($s2)
    MEM_W(0XB8, ctx->r18) = ctx->f0.u32l;
    // 0x80052064: swc1        $f2, 0xA0($s2)
    MEM_W(0XA0, ctx->r18) = ctx->f2.u32l;
    // 0x80052068: lw          $a0, 0xB8($s4)
    ctx->r4 = MEM_W(ctx->r20, 0XB8);
    // 0x8005206C: jal         0x8004EFAC
    // 0x80052070: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    func_8004EFAC(rdram, ctx);
        goto after_21;
    // 0x80052070: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    after_21:
L_80052074:
    // 0x80052074: lw          $ra, 0x68($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X68);
    // 0x80052078: lw          $s5, 0x64($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X64);
    // 0x8005207C: lw          $s4, 0x60($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X60);
    // 0x80052080: lw          $s3, 0x5C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X5C);
    // 0x80052084: lw          $s2, 0x58($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X58);
    // 0x80052088: lw          $s1, 0x54($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X54);
    // 0x8005208C: lw          $s0, 0x50($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X50);
    // 0x80052090: ldc1        $f28, 0x90($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0X90);
    // 0x80052094: ldc1        $f26, 0x88($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X88);
    // 0x80052098: ldc1        $f24, 0x80($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X80);
    // 0x8005209C: ldc1        $f22, 0x78($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X78);
    // 0x800520A0: ldc1        $f20, 0x70($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X70);
    // 0x800520A4: jr          $ra
    // 0x800520A8: addiu       $sp, $sp, 0x98
    ctx->r29 = ADD32(ctx->r29, 0X98);
    return;
    // 0x800520A8: addiu       $sp, $sp, 0x98
    ctx->r29 = ADD32(ctx->r29, 0X98);
;}
RECOMP_FUNC void func_800520AC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800520AC: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x800520B0: lbu         $v0, -0x1444($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X1444);
    // 0x800520B4: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x800520B8: sw          $ra, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r31;
    // 0x800520BC: sw          $s1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r17;
    // 0x800520C0: bne         $v0, $zero, L_80052264
    if (ctx->r2 != 0) {
        // 0x800520C4: sw          $s0, 0x40($sp)
        MEM_W(0X40, ctx->r29) = ctx->r16;
            goto L_80052264;
    }
    // 0x800520C4: sw          $s0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r16;
    // 0x800520C8: sll         $v0, $a0, 5
    ctx->r2 = S32(ctx->r4 << 5);
    // 0x800520CC: subu        $v0, $v0, $a0
    ctx->r2 = SUB32(ctx->r2, ctx->r4);
    // 0x800520D0: sll         $v0, $v0, 5
    ctx->r2 = S32(ctx->r2 << 5);
    // 0x800520D4: lui         $v1, 0x8014
    ctx->r3 = S32(0X8014 << 16);
    // 0x800520D8: addiu       $v1, $v1, -0x73E8
    ctx->r3 = ADD32(ctx->r3, -0X73E8);
    // 0x800520DC: addu        $s1, $v0, $v1
    ctx->r17 = ADD32(ctx->r2, ctx->r3);
    // 0x800520E0: lhu         $v0, 0x0($s1)
    ctx->r2 = MEM_HU(ctx->r17, 0X0);
    // 0x800520E4: andi        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 & 0X1;
    // 0x800520E8: beq         $v0, $zero, L_80052264
    if (ctx->r2 == 0) {
        // 0x800520EC: lui         $v1, 0x8014
        ctx->r3 = S32(0X8014 << 16);
            goto L_80052264;
    }
    // 0x800520EC: lui         $v1, 0x8014
    ctx->r3 = S32(0X8014 << 16);
    // 0x800520F0: lw          $a1, 0x70($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X70);
    // 0x800520F4: addiu       $v1, $v1, -0x7FF4
    ctx->r3 = ADD32(ctx->r3, -0X7FF4);
    // 0x800520F8: sll         $v0, $a0, 2
    ctx->r2 = S32(ctx->r4 << 2);
    // 0x800520FC: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x80052100: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80052104: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x80052108: sll         $v0, $v0, 5
    ctx->r2 = S32(ctx->r2 << 5);
    // 0x8005210C: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80052110: addiu       $v1, $v0, 0x30
    ctx->r3 = ADD32(ctx->r2, 0X30);
L_80052114:
    // 0x80052114: lw          $a3, 0x0($v0)
    ctx->r7 = MEM_W(ctx->r2, 0X0);
    // 0x80052118: lw          $t0, 0x4($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X4);
    // 0x8005211C: lw          $t1, 0x8($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X8);
    // 0x80052120: lw          $t2, 0xC($v0)
    ctx->r10 = MEM_W(ctx->r2, 0XC);
    // 0x80052124: sw          $a3, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r7;
    // 0x80052128: sw          $t0, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r8;
    // 0x8005212C: sw          $t1, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->r9;
    // 0x80052130: sw          $t2, 0xC($a1)
    MEM_W(0XC, ctx->r5) = ctx->r10;
    // 0x80052134: addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
    // 0x80052138: bne         $v0, $v1, L_80052114
    if (ctx->r2 != ctx->r3) {
        // 0x8005213C: addiu       $a1, $a1, 0x10
        ctx->r5 = ADD32(ctx->r5, 0X10);
            goto L_80052114;
    }
    // 0x8005213C: addiu       $a1, $a1, 0x10
    ctx->r5 = ADD32(ctx->r5, 0X10);
    // 0x80052140: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80052144: lwc1        $f0, -0x54D8($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X54D8);
    // 0x80052148: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8005214C: lwc1        $f2, -0x54D4($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X54D4);
    // 0x80052150: addiu       $a1, $sp, 0x10
    ctx->r5 = ADD32(ctx->r29, 0X10);
    // 0x80052154: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80052158: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    // 0x8005215C: swc1        $f2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f2.u32l;
    // 0x80052160: lw          $a0, 0x70($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X70);
    // 0x80052164: jal         0x800193E8
    // 0x80052168: addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    func_800193E8(rdram, ctx);
        goto after_0;
    // 0x80052168: addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    after_0:
    // 0x8005216C: lw          $v0, 0x74($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X74);
    // 0x80052170: lwc1        $f2, 0x10($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X10);
    // 0x80052174: lwc1        $f0, 0x24($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X24);
    // 0x80052178: lwc1        $f4, 0x14($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X14);
    // 0x8005217C: sub.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl - ctx->f0.fl;
    // 0x80052180: swc1        $f0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f0.u32l;
    // 0x80052184: lw          $v0, 0x74($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X74);
    // 0x80052188: lwc1        $f0, 0x18($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X18);
    // 0x8005218C: lwc1        $f6, 0x28($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X28);
    // 0x80052190: addiu       $s0, $sp, 0x30
    ctx->r16 = ADD32(ctx->r29, 0X30);
    // 0x80052194: swc1        $f6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f6.u32l;
    // 0x80052198: lw          $v0, 0x74($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X74);
    // 0x8005219C: sub.s       $f4, $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x800521A0: lwc1        $f6, 0x2C($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X2C);
    // 0x800521A4: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x800521A8: swc1        $f2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f2.u32l;
    // 0x800521AC: sub.s       $f0, $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f6.fl;
    // 0x800521B0: swc1        $f6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f6.u32l;
    // 0x800521B4: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    // 0x800521B8: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    // 0x800521BC: lw          $a3, 0x10($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X10);
    // 0x800521C0: lw          $t0, 0x14($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X14);
    // 0x800521C4: lw          $t1, 0x18($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X18);
    // 0x800521C8: sw          $a3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r7;
    // 0x800521CC: sw          $t0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r8;
    // 0x800521D0: sw          $t1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r9;
    // 0x800521D4: jal         0x800AA350
    // 0x800521D8: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    func_800AA350(rdram, ctx);
        goto after_1;
    // 0x800521D8: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    after_1:
    // 0x800521DC: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x800521E0: lui         $a1, 0x4000
    ctx->r5 = S32(0X4000 << 16);
    // 0x800521E4: jal         0x800AA3B4
    // 0x800521E8: addu        $a2, $a0, $zero
    ctx->r6 = ADD32(ctx->r4, 0);
    func_800AA3B4(rdram, ctx);
        goto after_2;
    // 0x800521E8: addu        $a2, $a0, $zero
    ctx->r6 = ADD32(ctx->r4, 0);
    after_2:
    // 0x800521EC: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800521F0: lwc1        $f2, 0x10($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X10);
    // 0x800521F4: lwc1        $f0, 0x30($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X30);
    // 0x800521F8: lwc1        $f6, 0x14($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X14);
    // 0x800521FC: add.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x80052200: lwc1        $f0, 0x34($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X34);
    // 0x80052204: lwc1        $f4, 0x18($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X18);
    // 0x80052208: add.s       $f6, $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f0.fl;
    // 0x8005220C: lwc1        $f0, 0x38($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X38);
    // 0x80052210: lwc1        $f10, 0x20($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X20);
    // 0x80052214: add.s       $f4, $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f0.fl;
    // 0x80052218: lwc1        $f8, 0x28($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X28);
    // 0x8005221C: lwc1        $f0, 0x24($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X24);
    // 0x80052220: add.s       $f10, $f10, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = ctx->f10.fl + ctx->f2.fl;
    // 0x80052224: swc1        $f2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f2.u32l;
    // 0x80052228: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8005222C: lwc1        $f2, -0x54D0($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X54D0);
    // 0x80052230: add.s       $f0, $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f6.fl;
    // 0x80052234: addiu       $v0, $v0, 0x7A80
    ctx->r2 = ADD32(ctx->r2, 0X7A80);
    // 0x80052238: swc1        $f6, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f6.u32l;
    // 0x8005223C: add.s       $f8, $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f8.fl + ctx->f4.fl;
    // 0x80052240: swc1        $f4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f4.u32l;
    // 0x80052244: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    // 0x80052248: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    // 0x8005224C: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x80052250: swc1        $f8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f8.u32l;
    // 0x80052254: swc1        $f10, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->f10.u32l;
    // 0x80052258: swc1        $f8, 0x2C($v0)
    MEM_W(0X2C, ctx->r2) = ctx->f8.u32l;
    // 0x8005225C: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    // 0x80052260: swc1        $f0, 0x28($v0)
    MEM_W(0X28, ctx->r2) = ctx->f0.u32l;
L_80052264:
    // 0x80052264: lw          $ra, 0x48($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X48);
    // 0x80052268: lw          $s1, 0x44($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X44);
    // 0x8005226C: lw          $s0, 0x40($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X40);
    // 0x80052270: jr          $ra
    // 0x80052274: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x80052274: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}
RECOMP_FUNC void func_80052278(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80052278: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8005227C: sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // 0x80052280: addu        $s2, $a0, $zero
    ctx->r18 = ADD32(ctx->r4, 0);
    // 0x80052284: sw          $s4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r20;
    // 0x80052288: addu        $s4, $a1, $zero
    ctx->r20 = ADD32(ctx->r5, 0);
    // 0x8005228C: sll         $v1, $s2, 5
    ctx->r3 = S32(ctx->r18 << 5);
    // 0x80052290: subu        $v1, $v1, $s2
    ctx->r3 = SUB32(ctx->r3, ctx->r18);
    // 0x80052294: sll         $v1, $v1, 5
    ctx->r3 = S32(ctx->r3 << 5);
    // 0x80052298: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x8005229C: addiu       $v0, $v0, -0x73E8
    ctx->r2 = ADD32(ctx->r2, -0X73E8);
    // 0x800522A0: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x800522A4: addu        $s0, $v1, $v0
    ctx->r16 = ADD32(ctx->r3, ctx->r2);
    // 0x800522A8: sw          $s5, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r21;
    // 0x800522AC: addiu       $s5, $s0, 0x28
    ctx->r21 = ADD32(ctx->r16, 0X28);
    // 0x800522B0: addu        $a0, $s5, $zero
    ctx->r4 = ADD32(ctx->r21, 0);
    // 0x800522B4: sw          $ra, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r31;
    // 0x800522B8: sw          $s3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r19;
    // 0x800522BC: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x800522C0: sdc1        $f22, 0x38($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X38, ctx->r29);
    // 0x800522C4: sdc1        $f20, 0x30($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X30, ctx->r29);
    // 0x800522C8: sh          $zero, 0x2($s0)
    MEM_H(0X2, ctx->r16) = 0;
    // 0x800522CC: sh          $zero, 0x4($s0)
    MEM_H(0X4, ctx->r16) = 0;
    // 0x800522D0: jal         0x8001CA50
    // 0x800522D4: sh          $zero, 0x0($s0)
    MEM_H(0X0, ctx->r16) = 0;
    func_8001CA50(rdram, ctx);
        goto after_0;
    // 0x800522D4: sh          $zero, 0x0($s0)
    MEM_H(0X0, ctx->r16) = 0;
    after_0:
    // 0x800522D8: addu        $v0, $s4, $zero
    ctx->r2 = ADD32(ctx->r20, 0);
    // 0x800522DC: andi        $s3, $v0, 0xFFFF
    ctx->r19 = ctx->r2 & 0XFFFF;
    // 0x800522E0: addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    // 0x800522E4: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x800522E8: addiu       $v0, $v0, -0x13EC
    ctx->r2 = ADD32(ctx->r2, -0X13EC);
    // 0x800522EC: sw          $v0, 0x70($s0)
    MEM_W(0X70, ctx->r16) = ctx->r2;
    // 0x800522F0: sw          $v0, 0x74($s0)
    MEM_W(0X74, ctx->r16) = ctx->r2;
    // 0x800522F4: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x800522F8: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x800522FC: lwc1        $f0, -0x54CC($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X54CC);
    // 0x80052300: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80052304: lwc1        $f2, -0x54C8($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X54C8);
    // 0x80052308: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8005230C: lwc1        $f4, -0x54C4($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X54C4);
    // 0x80052310: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80052314: lwc1        $f6, -0x54C0($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X54C0);
    // 0x80052318: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8005231C: lwc1        $f8, -0x54BC($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X54BC);
    // 0x80052320: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80052324: lwc1        $f10, -0x54B8($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X54B8);
    // 0x80052328: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8005232C: lwc1        $f12, -0x54B4($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X54B4);
    // 0x80052330: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80052334: lwc1        $f22, -0x54B0($at)
    ctx->f22.u32l = MEM_W(ctx->r1, -0X54B0);
    // 0x80052338: addiu       $v0, $v0, -0x7D98
    ctx->r2 = ADD32(ctx->r2, -0X7D98);
    // 0x8005233C: sw          $v0, 0xBC($s0)
    MEM_W(0XBC, ctx->r16) = ctx->r2;
    // 0x80052340: sw          $v0, 0xC0($s0)
    MEM_W(0XC0, ctx->r16) = ctx->r2;
    // 0x80052344: ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
    // 0x80052348: sw          $zero, 0x58($s0)
    MEM_W(0X58, ctx->r16) = 0;
    // 0x8005234C: sw          $zero, 0x5C($s0)
    MEM_W(0X5C, ctx->r16) = 0;
    // 0x80052350: sw          $zero, 0x60($s0)
    MEM_W(0X60, ctx->r16) = 0;
    // 0x80052354: sw          $zero, 0x64($s0)
    MEM_W(0X64, ctx->r16) = 0;
    // 0x80052358: sw          $zero, 0x68($s0)
    MEM_W(0X68, ctx->r16) = 0;
    // 0x8005235C: sw          $zero, 0x6C($s0)
    MEM_W(0X6C, ctx->r16) = 0;
    // 0x80052360: sw          $zero, 0x78($s0)
    MEM_W(0X78, ctx->r16) = 0;
    // 0x80052364: sw          $zero, 0x7C($s0)
    MEM_W(0X7C, ctx->r16) = 0;
    // 0x80052368: sw          $zero, 0x80($s0)
    MEM_W(0X80, ctx->r16) = 0;
    // 0x8005236C: sw          $zero, 0x84($s0)
    MEM_W(0X84, ctx->r16) = 0;
    // 0x80052370: sw          $zero, 0x88($s0)
    MEM_W(0X88, ctx->r16) = 0;
    // 0x80052374: sw          $zero, 0x8C($s0)
    MEM_W(0X8C, ctx->r16) = 0;
    // 0x80052378: sw          $zero, 0x10($s0)
    MEM_W(0X10, ctx->r16) = 0;
    // 0x8005237C: sw          $zero, 0x14($s0)
    MEM_W(0X14, ctx->r16) = 0;
    // 0x80052380: sw          $zero, 0x18($s0)
    MEM_W(0X18, ctx->r16) = 0;
    // 0x80052384: sw          $zero, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = 0;
    // 0x80052388: sw          $zero, 0x20($s0)
    MEM_W(0X20, ctx->r16) = 0;
    // 0x8005238C: sw          $zero, 0x24($s0)
    MEM_W(0X24, ctx->r16) = 0;
    // 0x80052390: sw          $zero, 0x90($s0)
    MEM_W(0X90, ctx->r16) = 0;
    // 0x80052394: sw          $zero, 0x94($s0)
    MEM_W(0X94, ctx->r16) = 0;
    // 0x80052398: sw          $zero, 0x98($s0)
    MEM_W(0X98, ctx->r16) = 0;
    // 0x8005239C: sw          $zero, 0x9C($s0)
    MEM_W(0X9C, ctx->r16) = 0;
    // 0x800523A0: sw          $zero, 0xA0($s0)
    MEM_W(0XA0, ctx->r16) = 0;
    // 0x800523A4: sw          $zero, 0xC4($s0)
    MEM_W(0XC4, ctx->r16) = 0;
    // 0x800523A8: sw          $zero, 0xCC($s0)
    MEM_W(0XCC, ctx->r16) = 0;
    // 0x800523AC: sw          $zero, 0xD0($s0)
    MEM_W(0XD0, ctx->r16) = 0;
    // 0x800523B0: sw          $zero, 0xD8($s0)
    MEM_W(0XD8, ctx->r16) = 0;
    // 0x800523B4: sw          $zero, 0xE0($s0)
    MEM_W(0XE0, ctx->r16) = 0;
    // 0x800523B8: swc1        $f0, 0xC8($s0)
    MEM_W(0XC8, ctx->r16) = ctx->f0.u32l;
    // 0x800523BC: sw          $zero, 0xDC($s0)
    MEM_W(0XDC, ctx->r16) = 0;
    // 0x800523C0: swc1        $f2, 0xD4($s0)
    MEM_W(0XD4, ctx->r16) = ctx->f2.u32l;
    // 0x800523C4: swc1        $f4, 0xE4($s0)
    MEM_W(0XE4, ctx->r16) = ctx->f4.u32l;
    // 0x800523C8: swc1        $f6, 0xE8($s0)
    MEM_W(0XE8, ctx->r16) = ctx->f6.u32l;
    // 0x800523CC: swc1        $f8, 0xA4($s0)
    MEM_W(0XA4, ctx->r16) = ctx->f8.u32l;
    // 0x800523D0: sw          $zero, 0xA8($s0)
    MEM_W(0XA8, ctx->r16) = 0;
    // 0x800523D4: swc1        $f10, 0xAC($s0)
    MEM_W(0XAC, ctx->r16) = ctx->f10.u32l;
    // 0x800523D8: swc1        $f12, 0xB0($s0)
    MEM_W(0XB0, ctx->r16) = ctx->f12.u32l;
    // 0x800523DC: sw          $zero, 0xEC($s0)
    MEM_W(0XEC, ctx->r16) = 0;
    // 0x800523E0: sh          $v0, 0xF4($s0)
    MEM_H(0XF4, ctx->r16) = ctx->r2;
    // 0x800523E4: sw          $zero, 0xF0($s0)
    MEM_W(0XF0, ctx->r16) = 0;
    // 0x800523E8: sw          $zero, 0xB4($s0)
    MEM_W(0XB4, ctx->r16) = 0;
    // 0x800523EC: jal         0x8004013C
    // 0x800523F0: swc1        $f22, 0xB8($s0)
    MEM_W(0XB8, ctx->r16) = ctx->f22.u32l;
    func_8004013C(rdram, ctx);
        goto after_1;
    // 0x800523F0: swc1        $f22, 0xB8($s0)
    MEM_W(0XB8, ctx->r16) = ctx->f22.u32l;
    after_1:
    // 0x800523F4: lw          $s1, 0xC($v0)
    ctx->r17 = MEM_W(ctx->r2, 0XC);
    // 0x800523F8: beq         $s1, $zero, L_8005270C
    if (ctx->r17 == 0) {
        // 0x800523FC: ori         $a0, $zero, 0xFFFF
        ctx->r4 = 0 | 0XFFFF;
            goto L_8005270C;
    }
    // 0x800523FC: ori         $a0, $zero, 0xFFFF
    ctx->r4 = 0 | 0XFFFF;
    // 0x80052400: jal         0x80040188
    // 0x80052404: addu        $a1, $s3, $zero
    ctx->r5 = ADD32(ctx->r19, 0);
    func_80040188(rdram, ctx);
        goto after_2;
    // 0x80052404: addu        $a1, $s3, $zero
    ctx->r5 = ADD32(ctx->r19, 0);
    after_2:
    // 0x80052408: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // 0x8005240C: sh          $v0, 0xF4($s0)
    MEM_H(0XF4, ctx->r16) = ctx->r2;
    // 0x80052410: addiu       $v0, $zero, 0x13
    ctx->r2 = ADD32(0, 0X13);
    // 0x80052414: sh          $v0, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r2;
    // 0x80052418: addiu       $v0, $s1, 0x28
    ctx->r2 = ADD32(ctx->r17, 0X28);
    // 0x8005241C: sw          $v0, 0x74($s0)
    MEM_W(0X74, ctx->r16) = ctx->r2;
    // 0x80052420: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80052424: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x80052428: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8005242C: lwc1        $f0, -0x54AC($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X54AC);
    // 0x80052430: addiu       $v0, $v0, 0x7A80
    ctx->r2 = ADD32(ctx->r2, 0X7A80);
    // 0x80052434: sw          $v0, 0x70($s0)
    MEM_W(0X70, ctx->r16) = ctx->r2;
    // 0x80052438: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x8005243C: sb          $zero, -0x1444($v0)
    MEM_B(-0X1444, ctx->r2) = 0;
    // 0x80052440: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80052444: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x80052448: sw          $zero, 0x58($s0)
    MEM_W(0X58, ctx->r16) = 0;
    // 0x8005244C: sw          $zero, 0x5C($s0)
    MEM_W(0X5C, ctx->r16) = 0;
    // 0x80052450: sw          $zero, 0x60($s0)
    MEM_W(0X60, ctx->r16) = 0;
    // 0x80052454: lw          $t0, 0x58($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X58);
    // 0x80052458: lw          $t1, 0x5C($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X5C);
    // 0x8005245C: lw          $t2, 0x60($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X60);
    // 0x80052460: sw          $t0, 0x64($s0)
    MEM_W(0X64, ctx->r16) = ctx->r8;
    // 0x80052464: sw          $t1, 0x68($s0)
    MEM_W(0X68, ctx->r16) = ctx->r9;
    // 0x80052468: sw          $t2, 0x6C($s0)
    MEM_W(0X6C, ctx->r16) = ctx->r10;
    // 0x8005246C: sw          $zero, 0x78($s0)
    MEM_W(0X78, ctx->r16) = 0;
    // 0x80052470: sw          $zero, 0x80($s0)
    MEM_W(0X80, ctx->r16) = 0;
    // 0x80052474: sh          $s4, -0x143C($v0)
    MEM_H(-0X143C, ctx->r2) = ctx->r20;
    // 0x80052478: swc1        $f0, 0x7C($s0)
    MEM_W(0X7C, ctx->r16) = ctx->f0.u32l;
    // 0x8005247C: lw          $t0, 0x78($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X78);
    // 0x80052480: lw          $t1, 0x7C($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X7C);
    // 0x80052484: lw          $t2, 0x80($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X80);
    // 0x80052488: sw          $t0, 0x84($s0)
    MEM_W(0X84, ctx->r16) = ctx->r8;
    // 0x8005248C: sw          $t1, 0x88($s0)
    MEM_W(0X88, ctx->r16) = ctx->r9;
    // 0x80052490: sw          $t2, 0x8C($s0)
    MEM_W(0X8C, ctx->r16) = ctx->r10;
    // 0x80052494: sw          $zero, 0x90($s0)
    MEM_W(0X90, ctx->r16) = 0;
    // 0x80052498: swc1        $f20, 0xA8($s0)
    MEM_W(0XA8, ctx->r16) = ctx->f20.u32l;
    // 0x8005249C: swc1        $f20, 0xA4($s0)
    MEM_W(0XA4, ctx->r16) = ctx->f20.u32l;
    // 0x800524A0: jal         0x800520AC
    // 0x800524A4: swc1        $f20, 0xEC($s0)
    MEM_W(0XEC, ctx->r16) = ctx->f20.u32l;
    func_800520AC(rdram, ctx);
        goto after_3;
    // 0x800524A4: swc1        $f20, 0xEC($s0)
    MEM_W(0XEC, ctx->r16) = ctx->f20.u32l;
    after_3:
    // 0x800524A8: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x800524AC: sh          $v0, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r2;
    // 0x800524B0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800524B4: lui         $v1, 0x8014
    ctx->r3 = S32(0X8014 << 16);
    // 0x800524B8: addiu       $v1, $v1, -0x72E8
    ctx->r3 = ADD32(ctx->r3, -0X72E8);
    // 0x800524BC: sh          $v0, 0x4($s0)
    MEM_H(0X4, ctx->r16) = ctx->r2;
    // 0x800524C0: sll         $v0, $s2, 2
    ctx->r2 = S32(ctx->r18 << 2);
    // 0x800524C4: addu        $v0, $v0, $s2
    ctx->r2 = ADD32(ctx->r2, ctx->r18);
    // 0x800524C8: sll         $v0, $v0, 4
    ctx->r2 = S32(ctx->r2 << 4);
    // 0x800524CC: addu        $v0, $v0, $s2
    ctx->r2 = ADD32(ctx->r2, ctx->r18);
    // 0x800524D0: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800524D4: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x800524D8: lwc1        $f2, -0x54A8($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X54A8);
    // 0x800524DC: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x800524E0: lwc1        $f0, -0x54A4($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X54A4);
    // 0x800524E4: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800524E8: swc1        $f20, 0xDC($s0)
    MEM_W(0XDC, ctx->r16) = ctx->f20.u32l;
    // 0x800524EC: swc1        $f20, 0x98($s0)
    MEM_W(0X98, ctx->r16) = ctx->f20.u32l;
    // 0x800524F0: swc1        $f22, 0xB8($s0)
    MEM_W(0XB8, ctx->r16) = ctx->f22.u32l;
    // 0x800524F4: swc1        $f2, 0x94($s0)
    MEM_W(0X94, ctx->r16) = ctx->f2.u32l;
    // 0x800524F8: swc1        $f0, 0x9C($s0)
    MEM_W(0X9C, ctx->r16) = ctx->f0.u32l;
    // 0x800524FC: swc1        $f0, 0xA0($s0)
    MEM_W(0XA0, ctx->r16) = ctx->f0.u32l;
    // 0x80052500: lw          $v0, 0x4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X4);
    // 0x80052504: addu        $a0, $s5, $zero
    ctx->r4 = ADD32(ctx->r21, 0);
    // 0x80052508: addiu       $v1, $v0, 0x28
    ctx->r3 = ADD32(ctx->r2, 0X28);
    // 0x8005250C: addiu       $v0, $v0, 0x58
    ctx->r2 = ADD32(ctx->r2, 0X58);
L_80052510:
    // 0x80052510: lw          $t0, 0x0($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X0);
    // 0x80052514: lw          $t1, 0x4($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X4);
    // 0x80052518: lw          $t2, 0x8($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X8);
    // 0x8005251C: lw          $t3, 0xC($v1)
    ctx->r11 = MEM_W(ctx->r3, 0XC);
    // 0x80052520: sw          $t0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r8;
    // 0x80052524: sw          $t1, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r9;
    // 0x80052528: sw          $t2, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r10;
    // 0x8005252C: sw          $t3, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r11;
    // 0x80052530: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
    // 0x80052534: bne         $v1, $v0, L_80052510
    if (ctx->r3 != ctx->r2) {
        // 0x80052538: addiu       $a0, $a0, 0x10
        ctx->r4 = ADD32(ctx->r4, 0X10);
            goto L_80052510;
    }
    // 0x80052538: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    // 0x8005253C: addiu       $a0, $s0, 0x28
    ctx->r4 = ADD32(ctx->r16, 0X28);
    // 0x80052540: addiu       $a1, $s0, 0x10
    ctx->r5 = ADD32(ctx->r16, 0X10);
    // 0x80052544: jal         0x800A9B80
    // 0x80052548: addiu       $a2, $s0, 0x1C
    ctx->r6 = ADD32(ctx->r16, 0X1C);
    func_800A9B80(rdram, ctx);
        goto after_4;
    // 0x80052548: addiu       $a2, $s0, 0x1C
    ctx->r6 = ADD32(ctx->r16, 0X1C);
    after_4:
    // 0x8005254C: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x80052550: addiu       $v0, $v0, -0x72E8
    ctx->r2 = ADD32(ctx->r2, -0X72E8);
    // 0x80052554: sll         $v1, $s2, 2
    ctx->r3 = S32(ctx->r18 << 2);
    // 0x80052558: addu        $v1, $v1, $s2
    ctx->r3 = ADD32(ctx->r3, ctx->r18);
    // 0x8005255C: sll         $v1, $v1, 4
    ctx->r3 = S32(ctx->r3 << 4);
    // 0x80052560: addu        $v1, $v1, $s2
    ctx->r3 = ADD32(ctx->r3, ctx->r18);
    // 0x80052564: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x80052568: addu        $a2, $v1, $v0
    ctx->r6 = ADD32(ctx->r3, ctx->r2);
    // 0x8005256C: lw          $v1, 0x4($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X4);
    // 0x80052570: lhu         $v0, 0x2($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X2);
    // 0x80052574: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    // 0x80052578: bne         $v0, $a3, L_80052598
    if (ctx->r2 != ctx->r7) {
        // 0x8005257C: addu        $a1, $v1, $zero
        ctx->r5 = ADD32(ctx->r3, 0);
            goto L_80052598;
    }
    // 0x8005257C: addu        $a1, $v1, $zero
    ctx->r5 = ADD32(ctx->r3, 0);
    // 0x80052580: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // 0x80052584: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x80052588: jal         0x8004EFAC
    // 0x8005258C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_8004EFAC(rdram, ctx);
        goto after_5;
    // 0x8005258C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_5:
    // 0x80052590: j           L_8005270C
    // 0x80052594: nop

        goto L_8005270C;
    // 0x80052594: nop

L_80052598:
    // 0x80052598: beq         $a1, $s0, L_8005270C
    if (ctx->r5 == ctx->r16) {
        // 0x8005259C: sll         $v1, $s2, 5
        ctx->r3 = S32(ctx->r18 << 5);
            goto L_8005270C;
    }
    // 0x8005259C: sll         $v1, $s2, 5
    ctx->r3 = S32(ctx->r18 << 5);
    // 0x800525A0: subu        $v1, $v1, $s2
    ctx->r3 = SUB32(ctx->r3, ctx->r18);
    // 0x800525A4: sll         $v1, $v1, 5
    ctx->r3 = S32(ctx->r3 << 5);
    // 0x800525A8: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x800525AC: addiu       $v0, $v0, -0x76D0
    ctx->r2 = ADD32(ctx->r2, -0X76D0);
    // 0x800525B0: addu        $a0, $v1, $v0
    ctx->r4 = ADD32(ctx->r3, ctx->r2);
    // 0x800525B4: lhu         $v0, 0x0($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X0);
    // 0x800525B8: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x800525BC: lwc1        $f0, -0x54A0($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X54A0);
    // 0x800525C0: sh          $a3, 0x2($a0)
    MEM_H(0X2, ctx->r4) = ctx->r7;
    // 0x800525C4: sw          $a1, 0xBC($a0)
    MEM_W(0XBC, ctx->r4) = ctx->r5;
    // 0x800525C8: sw          $s0, 0xC0($a0)
    MEM_W(0XC0, ctx->r4) = ctx->r16;
    // 0x800525CC: sw          $zero, 0xC4($a0)
    MEM_W(0XC4, ctx->r4) = 0;
    // 0x800525D0: sw          $zero, 0xCC($a0)
    MEM_W(0XCC, ctx->r4) = 0;
    // 0x800525D4: sw          $zero, 0x74($a0)
    MEM_W(0X74, ctx->r4) = 0;
    // 0x800525D8: ori         $v0, $v0, 0x1
    ctx->r2 = ctx->r2 | 0X1;
    // 0x800525DC: sh          $v0, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r2;
    // 0x800525E0: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x800525E4: lw          $v1, -0x7DA0($v0)
    ctx->r3 = MEM_W(ctx->r2, -0X7DA0);
    // 0x800525E8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800525EC: bne         $v1, $v0, L_80052600
    if (ctx->r3 != ctx->r2) {
        // 0x800525F0: swc1        $f0, 0xC8($a0)
        MEM_W(0XC8, ctx->r4) = ctx->f0.u32l;
            goto L_80052600;
    }
    // 0x800525F0: swc1        $f0, 0xC8($a0)
    MEM_W(0XC8, ctx->r4) = ctx->f0.u32l;
    // 0x800525F4: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x800525F8: lw          $v0, -0x776C($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X776C);
    // 0x800525FC: sw          $a0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r4;
L_80052600:
    // 0x80052600: sw          $a0, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r4;
    // 0x80052604: addiu       $v1, $a0, 0x28
    ctx->r3 = ADD32(ctx->r4, 0X28);
    // 0x80052608: addiu       $v0, $a1, 0x28
    ctx->r2 = ADD32(ctx->r5, 0X28);
    // 0x8005260C: addiu       $a2, $a1, 0x58
    ctx->r6 = ADD32(ctx->r5, 0X58);
L_80052610:
    // 0x80052610: lw          $t0, 0x0($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X0);
    // 0x80052614: lw          $t1, 0x4($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X4);
    // 0x80052618: lw          $t2, 0x8($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X8);
    // 0x8005261C: lw          $t3, 0xC($v0)
    ctx->r11 = MEM_W(ctx->r2, 0XC);
    // 0x80052620: sw          $t0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r8;
    // 0x80052624: sw          $t1, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r9;
    // 0x80052628: sw          $t2, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r10;
    // 0x8005262C: sw          $t3, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r11;
    // 0x80052630: addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
    // 0x80052634: bne         $v0, $a2, L_80052610
    if (ctx->r2 != ctx->r6) {
        // 0x80052638: addiu       $v1, $v1, 0x10
        ctx->r3 = ADD32(ctx->r3, 0X10);
            goto L_80052610;
    }
    // 0x80052638: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
    // 0x8005263C: addiu       $a2, $s0, 0x28
    ctx->r6 = ADD32(ctx->r16, 0X28);
    // 0x80052640: lw          $t0, 0x10($a1)
    ctx->r8 = MEM_W(ctx->r5, 0X10);
    // 0x80052644: lw          $t1, 0x14($a1)
    ctx->r9 = MEM_W(ctx->r5, 0X14);
    // 0x80052648: lw          $t2, 0x18($a1)
    ctx->r10 = MEM_W(ctx->r5, 0X18);
    // 0x8005264C: sw          $t0, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->r8;
    // 0x80052650: sw          $t1, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->r9;
    // 0x80052654: sw          $t2, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->r10;
    // 0x80052658: lw          $t0, 0x1C($a1)
    ctx->r8 = MEM_W(ctx->r5, 0X1C);
    // 0x8005265C: lw          $t1, 0x20($a1)
    ctx->r9 = MEM_W(ctx->r5, 0X20);
    // 0x80052660: lw          $t2, 0x24($a1)
    ctx->r10 = MEM_W(ctx->r5, 0X24);
    // 0x80052664: sw          $t0, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = ctx->r8;
    // 0x80052668: sw          $t1, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r9;
    // 0x8005266C: sw          $t2, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->r10;
    // 0x80052670: lhu         $v0, 0x0($a1)
    ctx->r2 = MEM_HU(ctx->r5, 0X0);
    // 0x80052674: addiu       $v1, $a1, 0x28
    ctx->r3 = ADD32(ctx->r5, 0X28);
    // 0x80052678: ori         $v0, $v0, 0x1
    ctx->r2 = ctx->r2 | 0X1;
    // 0x8005267C: sh          $v0, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r2;
    // 0x80052680: lhu         $v0, 0x0($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X0);
    // 0x80052684: addiu       $a1, $a1, 0x58
    ctx->r5 = ADD32(ctx->r5, 0X58);
    // 0x80052688: ori         $v0, $v0, 0x1
    ctx->r2 = ctx->r2 | 0X1;
    // 0x8005268C: sh          $v0, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r2;
L_80052690:
    // 0x80052690: lw          $t0, 0x0($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X0);
    // 0x80052694: lw          $t1, 0x4($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X4);
    // 0x80052698: lw          $t2, 0x8($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X8);
    // 0x8005269C: lw          $t3, 0xC($v1)
    ctx->r11 = MEM_W(ctx->r3, 0XC);
    // 0x800526A0: sw          $t0, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r8;
    // 0x800526A4: sw          $t1, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r9;
    // 0x800526A8: sw          $t2, 0x8($a2)
    MEM_W(0X8, ctx->r6) = ctx->r10;
    // 0x800526AC: sw          $t3, 0xC($a2)
    MEM_W(0XC, ctx->r6) = ctx->r11;
    // 0x800526B0: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
    // 0x800526B4: bne         $v1, $a1, L_80052690
    if (ctx->r3 != ctx->r5) {
        // 0x800526B8: addiu       $a2, $a2, 0x10
        ctx->r6 = ADD32(ctx->r6, 0X10);
            goto L_80052690;
    }
    // 0x800526B8: addiu       $a2, $a2, 0x10
    ctx->r6 = ADD32(ctx->r6, 0X10);
    // 0x800526BC: lui         $v1, 0x8014
    ctx->r3 = S32(0X8014 << 16);
    // 0x800526C0: addiu       $v1, $v1, -0x72E8
    ctx->r3 = ADD32(ctx->r3, -0X72E8);
    // 0x800526C4: sll         $v0, $s2, 2
    ctx->r2 = S32(ctx->r18 << 2);
    // 0x800526C8: addu        $v0, $v0, $s2
    ctx->r2 = ADD32(ctx->r2, ctx->r18);
    // 0x800526CC: sll         $v0, $v0, 4
    ctx->r2 = S32(ctx->r2 << 4);
    // 0x800526D0: addu        $v0, $v0, $s2
    ctx->r2 = ADD32(ctx->r2, ctx->r18);
    // 0x800526D4: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800526D8: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800526DC: lwc1        $f0, 0x4C($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X4C);
    // 0x800526E0: lwc1        $f2, 0x50($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X50);
    // 0x800526E4: lwc1        $f6, 0xA0($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XA0);
    // 0x800526E8: lwc1        $f4, 0x54($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X54);
    // 0x800526EC: mov.s       $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = ctx->f6.fl;
    // 0x800526F0: swc1        $f0, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f0.u32l;
    // 0x800526F4: swc1        $f2, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f2.u32l;
    // 0x800526F8: swc1        $f4, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f4.u32l;
    // 0x800526FC: swc1        $f6, 0x98($s0)
    MEM_W(0X98, ctx->r16) = ctx->f6.u32l;
    // 0x80052700: swc1        $f8, 0x9C($s0)
    MEM_W(0X9C, ctx->r16) = ctx->f8.u32l;
    // 0x80052704: jal         0x80066A50
    // 0x80052708: sw          $a0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r4;
    func_80066A50(rdram, ctx);
        goto after_6;
    // 0x80052708: sw          $a0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r4;
    after_6:
L_8005270C:
    // 0x8005270C: lw          $ra, 0x28($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X28);
    // 0x80052710: lw          $s5, 0x24($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X24);
    // 0x80052714: lw          $s4, 0x20($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X20);
    // 0x80052718: lw          $s3, 0x1C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X1C);
    // 0x8005271C: lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X18);
    // 0x80052720: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x80052724: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x80052728: ldc1        $f22, 0x38($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X38);
    // 0x8005272C: ldc1        $f20, 0x30($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X30);
    // 0x80052730: jr          $ra
    // 0x80052734: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x80052734: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void func_80052738(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80052738: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8005273C: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x80052740: addiu       $v0, $v0, -0x72E8
    ctx->r2 = ADD32(ctx->r2, -0X72E8);
    // 0x80052744: sll         $v1, $a0, 2
    ctx->r3 = S32(ctx->r4 << 2);
    // 0x80052748: addu        $v1, $v1, $a0
    ctx->r3 = ADD32(ctx->r3, ctx->r4);
    // 0x8005274C: sll         $v1, $v1, 4
    ctx->r3 = S32(ctx->r3 << 4);
    // 0x80052750: addu        $v1, $v1, $a0
    ctx->r3 = ADD32(ctx->r3, ctx->r4);
    // 0x80052754: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x80052758: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x8005275C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80052760: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80052764: sdc1        $f24, 0x38($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X38, ctx->r29);
    // 0x80052768: sdc1        $f22, 0x30($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X30, ctx->r29);
    // 0x8005276C: sdc1        $f20, 0x28($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X28, ctx->r29);
    // 0x80052770: lw          $v1, 0x4($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X4);
    // 0x80052774: lhu         $v0, 0x0($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X0);
    // 0x80052778: andi        $v0, $v0, 0x10
    ctx->r2 = ctx->r2 & 0X10;
    // 0x8005277C: beq         $v0, $zero, L_8005279C
    if (ctx->r2 == 0) {
        // 0x80052780: addu        $s0, $a1, $zero
        ctx->r16 = ADD32(ctx->r5, 0);
            goto L_8005279C;
    }
    // 0x80052780: addu        $s0, $a1, $zero
    ctx->r16 = ADD32(ctx->r5, 0);
    // 0x80052784: lw          $v1, 0x8($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X8);
    // 0x80052788: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x8005278C: beq         $v1, $v0, L_8005279C
    if (ctx->r3 == ctx->r2) {
        // 0x80052790: lui         $v0, 0x800A
        ctx->r2 = S32(0X800A << 16);
            goto L_8005279C;
    }
    // 0x80052790: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x80052794: j           L_800529F4
    // 0x80052798: sb          $zero, -0x1444($v0)
    MEM_B(-0X1444, ctx->r2) = 0;
        goto L_800529F4;
    // 0x80052798: sb          $zero, -0x1444($v0)
    MEM_B(-0X1444, ctx->r2) = 0;
L_8005279C:
    // 0x8005279C: lui         $v1, 0x8014
    ctx->r3 = S32(0X8014 << 16);
    // 0x800527A0: addiu       $v1, $v1, -0x72E8
    ctx->r3 = ADD32(ctx->r3, -0X72E8);
    // 0x800527A4: sll         $v0, $a0, 2
    ctx->r2 = S32(ctx->r4 << 2);
    // 0x800527A8: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x800527AC: sll         $v0, $v0, 4
    ctx->r2 = S32(ctx->r2 << 4);
    // 0x800527B0: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x800527B4: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800527B8: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800527BC: lw          $v0, 0x4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X4);
    // 0x800527C0: addu        $v1, $s0, $zero
    ctx->r3 = ADD32(ctx->r16, 0);
    // 0x800527C4: addiu       $a1, $v0, 0xF0
    ctx->r5 = ADD32(ctx->r2, 0XF0);
L_800527C8:
    // 0x800527C8: lw          $a3, 0x0($v0)
    ctx->r7 = MEM_W(ctx->r2, 0X0);
    // 0x800527CC: lw          $t0, 0x4($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X4);
    // 0x800527D0: lw          $t1, 0x8($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X8);
    // 0x800527D4: lw          $t2, 0xC($v0)
    ctx->r10 = MEM_W(ctx->r2, 0XC);
    // 0x800527D8: sw          $a3, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r7;
    // 0x800527DC: sw          $t0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r8;
    // 0x800527E0: sw          $t1, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r9;
    // 0x800527E4: sw          $t2, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r10;
    // 0x800527E8: addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
    // 0x800527EC: bne         $v0, $a1, L_800527C8
    if (ctx->r2 != ctx->r5) {
        // 0x800527F0: addiu       $v1, $v1, 0x10
        ctx->r3 = ADD32(ctx->r3, 0X10);
            goto L_800527C8;
    }
    // 0x800527F0: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
    // 0x800527F4: lw          $a3, 0x0($v0)
    ctx->r7 = MEM_W(ctx->r2, 0X0);
    // 0x800527F8: lw          $t0, 0x4($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X4);
    // 0x800527FC: sw          $a3, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r7;
    // 0x80052800: sw          $t0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r8;
    // 0x80052804: lui         $v1, 0x8014
    ctx->r3 = S32(0X8014 << 16);
    // 0x80052808: addiu       $v1, $v1, -0x72E8
    ctx->r3 = ADD32(ctx->r3, -0X72E8);
    // 0x8005280C: sll         $v0, $a0, 2
    ctx->r2 = S32(ctx->r4 << 2);
    // 0x80052810: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x80052814: sll         $v0, $v0, 4
    ctx->r2 = S32(ctx->r2 << 4);
    // 0x80052818: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x8005281C: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80052820: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80052824: lw          $v1, 0x4($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X4);
    // 0x80052828: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8005282C: lwc1        $f0, -0x549C($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X549C);
    // 0x80052830: ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
    // 0x80052834: sh          $v0, 0xF4($v1)
    MEM_H(0XF4, ctx->r3) = ctx->r2;
    // 0x80052838: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x8005283C: sw          $v0, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r2;
    // 0x80052840: sh          $v0, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r2;
    // 0x80052844: sh          $zero, 0x4($s0)
    MEM_H(0X4, ctx->r16) = 0;
    // 0x80052848: swc1        $f0, 0xEC($s0)
    MEM_W(0XEC, ctx->r16) = ctx->f0.u32l;
    // 0x8005284C: sw          $zero, 0x98($s0)
    MEM_W(0X98, ctx->r16) = 0;
    // 0x80052850: jal         0x80003430
    // 0x80052854: sw          $zero, 0x9C($s0)
    MEM_W(0X9C, ctx->r16) = 0;
    rand_recomp(rdram, ctx);
        goto after_0;
    // 0x80052854: sw          $zero, 0x9C($s0)
    MEM_W(0X9C, ctx->r16) = 0;
    after_0:
    // 0x80052858: andi        $v0, $v0, 0x7F
    ctx->r2 = ctx->r2 & 0X7F;
    // 0x8005285C: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80052860: lwc1        $f22, -0x5498($at)
    ctx->f22.u32l = MEM_W(ctx->r1, -0X5498);
    // 0x80052864: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x80052868: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x8005286C: sub.s       $f0, $f0, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f22.fl;
    // 0x80052870: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80052874: lwc1        $f20, -0x5494($at)
    ctx->f20.u32l = MEM_W(ctx->r1, -0X5494);
    // 0x80052878: mul.s       $f0, $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f20.fl);
    // 0x8005287C: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x80052880: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80052884: lwc1        $f24, -0x5490($at)
    ctx->f24.u32l = MEM_W(ctx->r1, -0X5490);
    // 0x80052888: c.lt.s      $f24, $f0
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f24.fl < ctx->f0.fl;
    // 0x8005288C: nop

    // 0x80052890: bc1f        L_80052904
    if (!c1cs) {
        // 0x80052894: nop
    
            goto L_80052904;
    }
    // 0x80052894: nop

    // 0x80052898: jal         0x80003430
    // 0x8005289C: nop

    rand_recomp(rdram, ctx);
        goto after_1;
    // 0x8005289C: nop

    after_1:
    // 0x800528A0: andi        $v0, $v0, 0x7F
    ctx->r2 = ctx->r2 & 0X7F;
    // 0x800528A4: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x800528A8: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x800528AC: sub.s       $f0, $f0, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f22.fl;
    // 0x800528B0: mul.s       $f0, $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f20.fl);
    // 0x800528B4: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x800528B8: lwc1        $f20, -0x548C($at)
    ctx->f20.u32l = MEM_W(ctx->r1, -0X548C);
    // 0x800528BC: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x800528C0: c.lt.s      $f24, $f0
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f24.fl < ctx->f0.fl;
    // 0x800528C4: nop

    // 0x800528C8: bc1f        L_800528D8
    if (!c1cs) {
        // 0x800528CC: nop
    
            goto L_800528D8;
    }
    // 0x800528CC: nop

    // 0x800528D0: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x800528D4: lwc1        $f20, -0x5488($at)
    ctx->f20.u32l = MEM_W(ctx->r1, -0X5488);
L_800528D8:
    // 0x800528D8: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x800528DC: lwc1        $f0, -0x5484($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X5484);
    // 0x800528E0: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x800528E4: lwc1        $f2, -0x5480($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X5480);
    // 0x800528E8: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    // 0x800528EC: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    // 0x800528F0: swc1        $f2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f2.u32l;
    // 0x800528F4: sw          $zero, 0x78($s0)
    MEM_W(0X78, ctx->r16) = 0;
    // 0x800528F8: sw          $zero, 0x7C($s0)
    MEM_W(0X7C, ctx->r16) = 0;
    // 0x800528FC: j           L_80052974
    // 0x80052900: sw          $zero, 0x80($s0)
    MEM_W(0X80, ctx->r16) = 0;
        goto L_80052974;
    // 0x80052900: sw          $zero, 0x80($s0)
    MEM_W(0X80, ctx->r16) = 0;
L_80052904:
    // 0x80052904: jal         0x80003430
    // 0x80052908: nop

    rand_recomp(rdram, ctx);
        goto after_2;
    // 0x80052908: nop

    after_2:
    // 0x8005290C: andi        $v0, $v0, 0x7F
    ctx->r2 = ctx->r2 & 0X7F;
    // 0x80052910: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x80052914: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x80052918: sub.s       $f0, $f0, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f22.fl;
    // 0x8005291C: mul.s       $f0, $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f20.fl);
    // 0x80052920: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80052924: lwc1        $f20, -0x547C($at)
    ctx->f20.u32l = MEM_W(ctx->r1, -0X547C);
    // 0x80052928: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x8005292C: c.lt.s      $f24, $f0
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f24.fl < ctx->f0.fl;
    // 0x80052930: nop

    // 0x80052934: bc1f        L_80052944
    if (!c1cs) {
        // 0x80052938: nop
    
            goto L_80052944;
    }
    // 0x80052938: nop

    // 0x8005293C: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80052940: lwc1        $f20, -0x5478($at)
    ctx->f20.u32l = MEM_W(ctx->r1, -0X5478);
L_80052944:
    // 0x80052944: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80052948: lwc1        $f0, -0x5474($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X5474);
    // 0x8005294C: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80052950: lwc1        $f2, -0x5470($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X5470);
    // 0x80052954: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80052958: lwc1        $f4, -0x546C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X546C);
    // 0x8005295C: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    // 0x80052960: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x80052964: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    // 0x80052968: sw          $zero, 0x78($s0)
    MEM_W(0X78, ctx->r16) = 0;
    // 0x8005296C: swc1        $f2, 0x7C($s0)
    MEM_W(0X7C, ctx->r16) = ctx->f2.u32l;
    // 0x80052970: swc1        $f4, 0x80($s0)
    MEM_W(0X80, ctx->r16) = ctx->f4.u32l;
L_80052974:
    // 0x80052974: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x80052978: lhu         $v1, -0x143C($a0)
    ctx->r3 = MEM_HU(ctx->r4, -0X143C);
    // 0x8005297C: ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
    // 0x80052980: beq         $v1, $v0, L_800529F4
    if (ctx->r3 == ctx->r2) {
        // 0x80052984: nop
    
            goto L_800529F4;
    }
    // 0x80052984: nop

    // 0x80052988: jal         0x8004013C
    // 0x8005298C: addu        $a0, $v1, $zero
    ctx->r4 = ADD32(ctx->r3, 0);
    func_8004013C(rdram, ctx);
        goto after_3;
    // 0x8005298C: addu        $a0, $v1, $zero
    ctx->r4 = ADD32(ctx->r3, 0);
    after_3:
    // 0x80052990: lw          $a0, 0xC($v0)
    ctx->r4 = MEM_W(ctx->r2, 0XC);
    // 0x80052994: beq         $a0, $zero, L_800529F4
    if (ctx->r4 == 0) {
        // 0x80052998: addiu       $a0, $a0, 0x28
        ctx->r4 = ADD32(ctx->r4, 0X28);
            goto L_800529F4;
    }
    // 0x80052998: addiu       $a0, $a0, 0x28
    ctx->r4 = ADD32(ctx->r4, 0X28);
    // 0x8005299C: addiu       $v0, $zero, 0x33
    ctx->r2 = ADD32(0, 0X33);
    // 0x800529A0: addiu       $a1, $sp, 0x10
    ctx->r5 = ADD32(ctx->r29, 0X10);
    // 0x800529A4: addiu       $a2, $s0, 0x10
    ctx->r6 = ADD32(ctx->r16, 0X10);
    // 0x800529A8: sh          $v0, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r2;
    // 0x800529AC: jal         0x800193E8
    // 0x800529B0: sw          $a0, 0x74($s0)
    MEM_W(0X74, ctx->r16) = ctx->r4;
    func_800193E8(rdram, ctx);
        goto after_4;
    // 0x800529B0: sw          $a0, 0x74($s0)
    MEM_W(0X74, ctx->r16) = ctx->r4;
    after_4:
    // 0x800529B4: lw          $a3, 0x78($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X78);
    // 0x800529B8: lw          $t0, 0x7C($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X7C);
    // 0x800529BC: lw          $t1, 0x80($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X80);
    // 0x800529C0: sw          $a3, 0x84($s0)
    MEM_W(0X84, ctx->r16) = ctx->r7;
    // 0x800529C4: sw          $t0, 0x88($s0)
    MEM_W(0X88, ctx->r16) = ctx->r8;
    // 0x800529C8: sw          $t1, 0x8C($s0)
    MEM_W(0X8C, ctx->r16) = ctx->r9;
    // 0x800529CC: lwc1        $f0, 0x10($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X10);
    // 0x800529D0: lwc1        $f2, 0x14($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X14);
    // 0x800529D4: lwc1        $f4, 0x18($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X18);
    // 0x800529D8: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x800529DC: sw          $zero, 0x70($a0)
    MEM_W(0X70, ctx->r4) = 0;
    // 0x800529E0: sw          $zero, 0x90($a0)
    MEM_W(0X90, ctx->r4) = 0;
    // 0x800529E4: swc1        $f0, 0x4C($a0)
    MEM_W(0X4C, ctx->r4) = ctx->f0.u32l;
    // 0x800529E8: swc1        $f2, 0x50($a0)
    MEM_W(0X50, ctx->r4) = ctx->f2.u32l;
    // 0x800529EC: jal         0x8004CD00
    // 0x800529F0: swc1        $f4, 0x54($a0)
    MEM_W(0X54, ctx->r4) = ctx->f4.u32l;
    func_8004CD00(rdram, ctx);
        goto after_5;
    // 0x800529F0: swc1        $f4, 0x54($a0)
    MEM_W(0X54, ctx->r4) = ctx->f4.u32l;
    after_5:
L_800529F4:
    // 0x800529F4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800529F8: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x800529FC: ldc1        $f24, 0x38($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X38);
    // 0x80052A00: ldc1        $f22, 0x30($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X30);
    // 0x80052A04: ldc1        $f20, 0x28($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X28);
    // 0x80052A08: jr          $ra
    // 0x80052A0C: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x80052A0C: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void func_80052A10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80052A10: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80052A14: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x80052A18: addu        $s3, $a0, $zero
    ctx->r19 = ADD32(ctx->r4, 0);
    // 0x80052A1C: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x80052A20: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x80052A24: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x80052A28: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x80052A2C: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80052A30: sdc1        $f20, 0x38($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X38, ctx->r29);
    // 0x80052A34: jal         0x800FC108
    // 0x80052A38: addu        $s4, $a1, $zero
    ctx->r20 = ADD32(ctx->r5, 0);
    func_800FC108(rdram, ctx);
        goto after_0;
    // 0x80052A38: addu        $s4, $a1, $zero
    ctx->r20 = ADD32(ctx->r5, 0);
    after_0:
    // 0x80052A3C: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x80052A40: lw          $v1, -0x35E0($v0)
    ctx->r3 = MEM_W(ctx->r2, -0X35E0);
    // 0x80052A44: beq         $v1, $zero, L_80052A54
    if (ctx->r3 == 0) {
        // 0x80052A48: addiu       $v0, $zero, 0x7
        ctx->r2 = ADD32(0, 0X7);
            goto L_80052A54;
    }
    // 0x80052A48: addiu       $v0, $zero, 0x7
    ctx->r2 = ADD32(0, 0X7);
    // 0x80052A4C: bne         $v1, $v0, L_80052D28
    if (ctx->r3 != ctx->r2) {
        // 0x80052A50: nop
    
            goto L_80052D28;
    }
    // 0x80052A50: nop

L_80052A54:
    // 0x80052A54: sll         $a0, $s3, 5
    ctx->r4 = S32(ctx->r19 << 5);
    // 0x80052A58: subu        $a0, $a0, $s3
    ctx->r4 = SUB32(ctx->r4, ctx->r19);
    // 0x80052A5C: sll         $a0, $a0, 5
    ctx->r4 = S32(ctx->r4 << 5);
    // 0x80052A60: lui         $a1, 0x8014
    ctx->r5 = S32(0X8014 << 16);
    // 0x80052A64: lui         $v1, 0x8014
    ctx->r3 = S32(0X8014 << 16);
    // 0x80052A68: addiu       $v1, $v1, -0x72E8
    ctx->r3 = ADD32(ctx->r3, -0X72E8);
    // 0x80052A6C: sll         $v0, $s3, 2
    ctx->r2 = S32(ctx->r19 << 2);
    // 0x80052A70: addu        $v0, $v0, $s3
    ctx->r2 = ADD32(ctx->r2, ctx->r19);
    // 0x80052A74: sll         $v0, $v0, 4
    ctx->r2 = S32(ctx->r2 << 4);
    // 0x80052A78: addu        $v0, $v0, $s3
    ctx->r2 = ADD32(ctx->r2, ctx->r19);
    // 0x80052A7C: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80052A80: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80052A84: lw          $v0, 0x4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X4);
    // 0x80052A88: addiu       $a1, $a1, -0x74E0
    ctx->r5 = ADD32(ctx->r5, -0X74E0);
    // 0x80052A8C: lhu         $v0, 0x0($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X0);
    // 0x80052A90: andi        $v0, $v0, 0x20
    ctx->r2 = ctx->r2 & 0X20;
    // 0x80052A94: beq         $v0, $zero, L_80052AA4
    if (ctx->r2 == 0) {
        // 0x80052A98: addu        $s1, $a0, $a1
        ctx->r17 = ADD32(ctx->r4, ctx->r5);
            goto L_80052AA4;
    }
    // 0x80052A98: addu        $s1, $a0, $a1
    ctx->r17 = ADD32(ctx->r4, ctx->r5);
    // 0x80052A9C: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x80052AA0: sb          $zero, -0x1444($v0)
    MEM_B(-0X1444, ctx->r2) = 0;
L_80052AA4:
    // 0x80052AA4: addiu       $s2, $s1, 0x28
    ctx->r18 = ADD32(ctx->r17, 0X28);
    // 0x80052AA8: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // 0x80052AAC: sh          $zero, 0x2($s1)
    MEM_H(0X2, ctx->r17) = 0;
    // 0x80052AB0: sh          $zero, 0x4($s1)
    MEM_H(0X4, ctx->r17) = 0;
    // 0x80052AB4: jal         0x8001CA50
    // 0x80052AB8: sh          $zero, 0x0($s1)
    MEM_H(0X0, ctx->r17) = 0;
    func_8001CA50(rdram, ctx);
        goto after_1;
    // 0x80052AB8: sh          $zero, 0x0($s1)
    MEM_H(0X0, ctx->r17) = 0;
    after_1:
    // 0x80052ABC: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x80052AC0: addiu       $v0, $v0, -0x13EC
    ctx->r2 = ADD32(ctx->r2, -0X13EC);
    // 0x80052AC4: sw          $v0, 0x70($s1)
    MEM_W(0X70, ctx->r17) = ctx->r2;
    // 0x80052AC8: sw          $v0, 0x74($s1)
    MEM_W(0X74, ctx->r17) = ctx->r2;
    // 0x80052ACC: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x80052AD0: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80052AD4: lwc1        $f0, -0x5468($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X5468);
    // 0x80052AD8: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80052ADC: lwc1        $f2, -0x5464($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X5464);
    // 0x80052AE0: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80052AE4: lwc1        $f4, -0x5460($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X5460);
    // 0x80052AE8: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80052AEC: lwc1        $f6, -0x545C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X545C);
    // 0x80052AF0: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80052AF4: lwc1        $f8, -0x5458($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X5458);
    // 0x80052AF8: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80052AFC: lwc1        $f10, -0x5454($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X5454);
    // 0x80052B00: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80052B04: lwc1        $f12, -0x5450($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X5450);
    // 0x80052B08: addiu       $v0, $v0, -0x7D98
    ctx->r2 = ADD32(ctx->r2, -0X7D98);
    // 0x80052B0C: sw          $v0, 0xBC($s1)
    MEM_W(0XBC, ctx->r17) = ctx->r2;
    // 0x80052B10: sw          $v0, 0xC0($s1)
    MEM_W(0XC0, ctx->r17) = ctx->r2;
    // 0x80052B14: ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
    // 0x80052B18: sw          $zero, 0x58($s1)
    MEM_W(0X58, ctx->r17) = 0;
    // 0x80052B1C: sw          $zero, 0x5C($s1)
    MEM_W(0X5C, ctx->r17) = 0;
    // 0x80052B20: sw          $zero, 0x60($s1)
    MEM_W(0X60, ctx->r17) = 0;
    // 0x80052B24: sw          $zero, 0x64($s1)
    MEM_W(0X64, ctx->r17) = 0;
    // 0x80052B28: sw          $zero, 0x68($s1)
    MEM_W(0X68, ctx->r17) = 0;
    // 0x80052B2C: sw          $zero, 0x6C($s1)
    MEM_W(0X6C, ctx->r17) = 0;
    // 0x80052B30: sw          $zero, 0x78($s1)
    MEM_W(0X78, ctx->r17) = 0;
    // 0x80052B34: sw          $zero, 0x7C($s1)
    MEM_W(0X7C, ctx->r17) = 0;
    // 0x80052B38: sw          $zero, 0x80($s1)
    MEM_W(0X80, ctx->r17) = 0;
    // 0x80052B3C: sw          $zero, 0x84($s1)
    MEM_W(0X84, ctx->r17) = 0;
    // 0x80052B40: sw          $zero, 0x88($s1)
    MEM_W(0X88, ctx->r17) = 0;
    // 0x80052B44: sw          $zero, 0x8C($s1)
    MEM_W(0X8C, ctx->r17) = 0;
    // 0x80052B48: sw          $zero, 0x10($s1)
    MEM_W(0X10, ctx->r17) = 0;
    // 0x80052B4C: sw          $zero, 0x14($s1)
    MEM_W(0X14, ctx->r17) = 0;
    // 0x80052B50: sw          $zero, 0x18($s1)
    MEM_W(0X18, ctx->r17) = 0;
    // 0x80052B54: sw          $zero, 0x1C($s1)
    MEM_W(0X1C, ctx->r17) = 0;
    // 0x80052B58: sw          $zero, 0x20($s1)
    MEM_W(0X20, ctx->r17) = 0;
    // 0x80052B5C: sw          $zero, 0x24($s1)
    MEM_W(0X24, ctx->r17) = 0;
    // 0x80052B60: sw          $zero, 0x90($s1)
    MEM_W(0X90, ctx->r17) = 0;
    // 0x80052B64: sw          $zero, 0x94($s1)
    MEM_W(0X94, ctx->r17) = 0;
    // 0x80052B68: sw          $zero, 0x98($s1)
    MEM_W(0X98, ctx->r17) = 0;
    // 0x80052B6C: sw          $zero, 0x9C($s1)
    MEM_W(0X9C, ctx->r17) = 0;
    // 0x80052B70: sw          $zero, 0xA0($s1)
    MEM_W(0XA0, ctx->r17) = 0;
    // 0x80052B74: sw          $zero, 0xC4($s1)
    MEM_W(0XC4, ctx->r17) = 0;
    // 0x80052B78: sw          $zero, 0xCC($s1)
    MEM_W(0XCC, ctx->r17) = 0;
    // 0x80052B7C: sw          $zero, 0xD0($s1)
    MEM_W(0XD0, ctx->r17) = 0;
    // 0x80052B80: sw          $zero, 0xD8($s1)
    MEM_W(0XD8, ctx->r17) = 0;
    // 0x80052B84: sw          $zero, 0xE0($s1)
    MEM_W(0XE0, ctx->r17) = 0;
    // 0x80052B88: swc1        $f0, 0xC8($s1)
    MEM_W(0XC8, ctx->r17) = ctx->f0.u32l;
    // 0x80052B8C: sw          $zero, 0xDC($s1)
    MEM_W(0XDC, ctx->r17) = 0;
    // 0x80052B90: sh          $v0, 0xF4($s1)
    MEM_H(0XF4, ctx->r17) = ctx->r2;
    // 0x80052B94: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x80052B98: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80052B9C: lwc1        $f0, -0x544C($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X544C);
    // 0x80052BA0: lbu         $v1, -0x1444($v0)
    ctx->r3 = MEM_BU(ctx->r2, -0X1444);
    // 0x80052BA4: addiu       $v0, $zero, 0x33
    ctx->r2 = ADD32(0, 0X33);
    // 0x80052BA8: swc1        $f2, 0xD4($s1)
    MEM_W(0XD4, ctx->r17) = ctx->f2.u32l;
    // 0x80052BAC: swc1        $f4, 0xE4($s1)
    MEM_W(0XE4, ctx->r17) = ctx->f4.u32l;
    // 0x80052BB0: swc1        $f6, 0xE8($s1)
    MEM_W(0XE8, ctx->r17) = ctx->f6.u32l;
    // 0x80052BB4: swc1        $f8, 0xA4($s1)
    MEM_W(0XA4, ctx->r17) = ctx->f8.u32l;
    // 0x80052BB8: sw          $zero, 0xA8($s1)
    MEM_W(0XA8, ctx->r17) = 0;
    // 0x80052BBC: swc1        $f10, 0xAC($s1)
    MEM_W(0XAC, ctx->r17) = ctx->f10.u32l;
    // 0x80052BC0: swc1        $f12, 0xB0($s1)
    MEM_W(0XB0, ctx->r17) = ctx->f12.u32l;
    // 0x80052BC4: sw          $zero, 0xEC($s1)
    MEM_W(0XEC, ctx->r17) = 0;
    // 0x80052BC8: sw          $zero, 0xF0($s1)
    MEM_W(0XF0, ctx->r17) = 0;
    // 0x80052BCC: sw          $zero, 0xB4($s1)
    MEM_W(0XB4, ctx->r17) = 0;
    // 0x80052BD0: sh          $v0, 0x0($s1)
    MEM_H(0X0, ctx->r17) = ctx->r2;
    // 0x80052BD4: bne         $v1, $zero, L_80052D08
    if (ctx->r3 != 0) {
        // 0x80052BD8: swc1        $f0, 0xB8($s1)
        MEM_W(0XB8, ctx->r17) = ctx->f0.u32l;
            goto L_80052D08;
    }
    // 0x80052BD8: swc1        $f0, 0xB8($s1)
    MEM_W(0XB8, ctx->r17) = ctx->f0.u32l;
    // 0x80052BDC: jal         0x80047B48
    // 0x80052BE0: addu        $a0, $s4, $zero
    ctx->r4 = ADD32(ctx->r20, 0);
    getLevelDatItemByName(rdram, ctx);
        goto after_2;
    // 0x80052BE0: addu        $a0, $s4, $zero
    ctx->r4 = ADD32(ctx->r20, 0);
    after_2:
    // 0x80052BE4: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x80052BE8: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80052BEC: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x80052BF0: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x80052BF4: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    // 0x80052BF8: lw          $t0, 0x10($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X10);
    // 0x80052BFC: lw          $t1, 0x14($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X14);
    // 0x80052C00: lw          $t2, 0x18($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X18);
    // 0x80052C04: sw          $t0, 0x10($s1)
    MEM_W(0X10, ctx->r17) = ctx->r8;
    // 0x80052C08: sw          $t1, 0x14($s1)
    MEM_W(0X14, ctx->r17) = ctx->r9;
    // 0x80052C0C: sw          $t2, 0x18($s1)
    MEM_W(0X18, ctx->r17) = ctx->r10;
    // 0x80052C10: jal         0x800AA570
    // 0x80052C14: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    func_800AA570(rdram, ctx);
        goto after_3;
    // 0x80052C14: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    after_3:
    // 0x80052C18: lw          $a1, 0x1C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X1C);
    // 0x80052C1C: jal         0x8001CB9C
    // 0x80052C20: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    func_8001CB9C(rdram, ctx);
        goto after_4;
    // 0x80052C20: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    after_4:
    // 0x80052C24: lw          $a1, 0x20($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X20);
    // 0x80052C28: jal         0x8001CCCC
    // 0x80052C2C: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    func_8001CCCC(rdram, ctx);
        goto after_5;
    // 0x80052C2C: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    after_5:
    // 0x80052C30: lw          $a1, 0x24($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X24);
    // 0x80052C34: jal         0x8001CDFC
    // 0x80052C38: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    func_8001CDFC(rdram, ctx);
        goto after_6;
    // 0x80052C38: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    after_6:
    // 0x80052C3C: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // 0x80052C40: addiu       $a1, $sp, 0x10
    ctx->r5 = ADD32(ctx->r29, 0X10);
    // 0x80052C44: lwc1        $f0, 0x10($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X10);
    // 0x80052C48: lwc1        $f2, 0x14($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0X14);
    // 0x80052C4C: lwc1        $f4, 0x18($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X18);
    // 0x80052C50: addiu       $a2, $s1, 0x1C
    ctx->r6 = ADD32(ctx->r17, 0X1C);
    // 0x80052C54: swc1        $f0, 0x4C($s1)
    MEM_W(0X4C, ctx->r17) = ctx->f0.u32l;
    // 0x80052C58: swc1        $f2, 0x50($s1)
    MEM_W(0X50, ctx->r17) = ctx->f2.u32l;
    // 0x80052C5C: jal         0x800A9B80
    // 0x80052C60: swc1        $f4, 0x54($s1)
    MEM_W(0X54, ctx->r17) = ctx->f4.u32l;
    func_800A9B80(rdram, ctx);
        goto after_7;
    // 0x80052C60: swc1        $f4, 0x54($s1)
    MEM_W(0X54, ctx->r17) = ctx->f4.u32l;
    after_7:
    // 0x80052C64: jal         0x8004CD00
    // 0x80052C68: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    func_8004CD00(rdram, ctx);
        goto after_8;
    // 0x80052C68: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    after_8:
    // 0x80052C6C: lwc1        $f0, 0x60($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X60);
    // 0x80052C70: swc1        $f0, 0xEC($s1)
    MEM_W(0XEC, ctx->r17) = ctx->f0.u32l;
    // 0x80052C74: lw          $v0, 0x64($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X64);
    // 0x80052C78: addu        $a0, $v0, $s0
    ctx->r4 = ADD32(ctx->r2, ctx->r16);
    // 0x80052C7C: lbu         $v1, 0x0($a0)
    ctx->r3 = MEM_BU(ctx->r4, 0X0);
    // 0x80052C80: addiu       $v0, $zero, 0x2D
    ctx->r2 = ADD32(0, 0X2D);
    // 0x80052C84: beql        $v1, $v0, L_80052D18
    if (ctx->r3 == ctx->r2) {
        // 0x80052C88: addu        $a0, $s3, $zero
        ctx->r4 = ADD32(ctx->r19, 0);
            goto L_80052D18;
    }
    goto skip_0;
    // 0x80052C88: addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    skip_0:
    // 0x80052C8C: jal         0x80047B48
    // 0x80052C90: nop

    getLevelDatItemByName(rdram, ctx);
        goto after_9;
    // 0x80052C90: nop

    after_9:
    // 0x80052C94: beq         $v0, $zero, L_80052D18
    if (ctx->r2 == 0) {
        // 0x80052C98: addu        $a0, $s3, $zero
        ctx->r4 = ADD32(ctx->r19, 0);
            goto L_80052D18;
    }
    // 0x80052C98: addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    // 0x80052C9C: lhu         $s0, 0x6($v0)
    ctx->r16 = MEM_HU(ctx->r2, 0X6);
    // 0x80052CA0: ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
    // 0x80052CA4: beq         $s0, $v0, L_80052D1C
    if (ctx->r16 == ctx->r2) {
        // 0x80052CA8: addiu       $a1, $zero, 0x2
        ctx->r5 = ADD32(0, 0X2);
            goto L_80052D1C;
    }
    // 0x80052CA8: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80052CAC: jal         0x8004013C
    // 0x80052CB0: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_8004013C(rdram, ctx);
        goto after_10;
    // 0x80052CB0: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_10:
    // 0x80052CB4: lw          $v0, 0xC($v0)
    ctx->r2 = MEM_W(ctx->r2, 0XC);
    // 0x80052CB8: beq         $v0, $zero, L_80052D14
    if (ctx->r2 == 0) {
        // 0x80052CBC: ori         $a0, $zero, 0xFFFF
        ctx->r4 = 0 | 0XFFFF;
            goto L_80052D14;
    }
    // 0x80052CBC: ori         $a0, $zero, 0xFFFF
    ctx->r4 = 0 | 0XFFFF;
    // 0x80052CC0: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x80052CC4: addiu       $v0, $v0, 0x28
    ctx->r2 = ADD32(ctx->r2, 0X28);
    // 0x80052CC8: sw          $v0, 0x74($s1)
    MEM_W(0X74, ctx->r17) = ctx->r2;
    // 0x80052CCC: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x80052CD0: swc1        $f20, 0x58($s1)
    MEM_W(0X58, ctx->r17) = ctx->f20.u32l;
    // 0x80052CD4: swc1        $f20, 0x5C($s1)
    MEM_W(0X5C, ctx->r17) = ctx->f20.u32l;
    // 0x80052CD8: swc1        $f20, 0x60($s1)
    MEM_W(0X60, ctx->r17) = ctx->f20.u32l;
    // 0x80052CDC: swc1        $f20, 0x78($s1)
    MEM_W(0X78, ctx->r17) = ctx->f20.u32l;
    // 0x80052CE0: swc1        $f20, 0x7C($s1)
    MEM_W(0X7C, ctx->r17) = ctx->f20.u32l;
    // 0x80052CE4: swc1        $f20, 0x80($s1)
    MEM_W(0X80, ctx->r17) = ctx->f20.u32l;
    // 0x80052CE8: swc1        $f20, 0x84($s1)
    MEM_W(0X84, ctx->r17) = ctx->f20.u32l;
    // 0x80052CEC: swc1        $f20, 0x88($s1)
    MEM_W(0X88, ctx->r17) = ctx->f20.u32l;
    // 0x80052CF0: swc1        $f20, 0x8C($s1)
    MEM_W(0X8C, ctx->r17) = ctx->f20.u32l;
    // 0x80052CF4: sh          $v0, 0x2($s1)
    MEM_H(0X2, ctx->r17) = ctx->r2;
    // 0x80052CF8: jal         0x80040188
    // 0x80052CFC: sh          $zero, 0x4($s1)
    MEM_H(0X4, ctx->r17) = 0;
    func_80040188(rdram, ctx);
        goto after_11;
    // 0x80052CFC: sh          $zero, 0x4($s1)
    MEM_H(0X4, ctx->r17) = 0;
    after_11:
    // 0x80052D00: j           L_80052D14
    // 0x80052D04: sh          $v0, 0xF4($s1)
    MEM_H(0XF4, ctx->r17) = ctx->r2;
        goto L_80052D14;
    // 0x80052D04: sh          $v0, 0xF4($s1)
    MEM_H(0XF4, ctx->r17) = ctx->r2;
L_80052D08:
    // 0x80052D08: addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    // 0x80052D0C: jal         0x80052738
    // 0x80052D10: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    func_80052738(rdram, ctx);
        goto after_12;
    // 0x80052D10: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    after_12:
L_80052D14:
    // 0x80052D14: addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
L_80052D18:
    // 0x80052D18: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
L_80052D1C:
    // 0x80052D1C: jal         0x8004EFAC
    // 0x80052D20: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    func_8004EFAC(rdram, ctx);
        goto after_13;
    // 0x80052D20: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    after_13:
    // 0x80052D24: sw          $s4, 0xF0($s1)
    MEM_W(0XF0, ctx->r17) = ctx->r20;
L_80052D28:
    // 0x80052D28: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x80052D2C: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x80052D30: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x80052D34: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x80052D38: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x80052D3C: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80052D40: ldc1        $f20, 0x38($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X38);
    // 0x80052D44: jr          $ra
    // 0x80052D48: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x80052D48: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void func_80052D4C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80052D4C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80052D50: sw          $s3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r19;
    // 0x80052D54: addu        $s3, $a1, $zero
    ctx->r19 = ADD32(ctx->r5, 0);
    // 0x80052D58: sll         $v0, $a0, 2
    ctx->r2 = S32(ctx->r4 << 2);
    // 0x80052D5C: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x80052D60: sll         $a1, $v0, 2
    ctx->r5 = S32(ctx->r2 << 2);
    // 0x80052D64: addu        $a1, $a1, $a0
    ctx->r5 = ADD32(ctx->r5, ctx->r4);
    // 0x80052D68: sll         $a1, $a1, 5
    ctx->r5 = S32(ctx->r5 << 5);
    // 0x80052D6C: lui         $a2, 0x8013
    ctx->r6 = S32(0X8013 << 16);
    // 0x80052D70: addiu       $a2, $a2, 0x7DBC
    ctx->r6 = ADD32(ctx->r6, 0X7DBC);
    // 0x80052D74: lui         $v1, 0x8014
    ctx->r3 = S32(0X8014 << 16);
    // 0x80052D78: addiu       $v1, $v1, -0x72E8
    ctx->r3 = ADD32(ctx->r3, -0X72E8);
    // 0x80052D7C: sll         $v0, $v0, 4
    ctx->r2 = S32(ctx->r2 << 4);
    // 0x80052D80: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x80052D84: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80052D88: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80052D8C: sw          $ra, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r31;
    // 0x80052D90: sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // 0x80052D94: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x80052D98: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x80052D9C: lw          $s0, 0x4($v0)
    ctx->r16 = MEM_W(ctx->r2, 0X4);
    // 0x80052DA0: lhu         $v0, 0xF4($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0XF4);
    // 0x80052DA4: ori         $s1, $zero, 0xFFFF
    ctx->r17 = 0 | 0XFFFF;
    // 0x80052DA8: beq         $v0, $s1, L_80052DBC
    if (ctx->r2 == ctx->r17) {
        // 0x80052DAC: addu        $s2, $a1, $a2
        ctx->r18 = ADD32(ctx->r5, ctx->r6);
            goto L_80052DBC;
    }
    // 0x80052DAC: addu        $s2, $a1, $a2
    ctx->r18 = ADD32(ctx->r5, ctx->r6);
    // 0x80052DB0: jal         0x8003F0C8
    // 0x80052DB4: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    func_8003F0C8(rdram, ctx);
        goto after_0;
    // 0x80052DB4: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    after_0:
    // 0x80052DB8: sh          $s1, 0xF4($s0)
    MEM_H(0XF4, ctx->r16) = ctx->r17;
L_80052DBC:
    // 0x80052DBC: beq         $s3, $zero, L_80052E98
    if (ctx->r19 == 0) {
        // 0x80052DC0: lui         $v1, 0x8011
        ctx->r3 = S32(0X8011 << 16);
            goto L_80052E98;
    }
    // 0x80052DC0: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
    // 0x80052DC4: jal         0x80047B48
    // 0x80052DC8: addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    getLevelDatItemByName(rdram, ctx);
        goto after_1;
    // 0x80052DC8: addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    after_1:
    // 0x80052DCC: lw          $v1, 0x68($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X68);
    // 0x80052DD0: addu        $s0, $v1, $v0
    ctx->r16 = ADD32(ctx->r3, ctx->r2);
    // 0x80052DD4: lbu         $v1, 0x0($s0)
    ctx->r3 = MEM_BU(ctx->r16, 0X0);
    // 0x80052DD8: addiu       $v0, $zero, 0x2D
    ctx->r2 = ADD32(0, 0X2D);
    // 0x80052DDC: beql        $v1, $v0, L_80052E98
    if (ctx->r3 == ctx->r2) {
        // 0x80052DE0: lui         $v1, 0x8011
        ctx->r3 = S32(0X8011 << 16);
            goto L_80052E98;
    }
    goto skip_0;
    // 0x80052DE0: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
    skip_0:
    // 0x80052DE4: beq         $v1, $zero, L_80052E98
    if (ctx->r3 == 0) {
        // 0x80052DE8: lui         $v1, 0x8011
        ctx->r3 = S32(0X8011 << 16);
            goto L_80052E98;
    }
    // 0x80052DE8: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
    // 0x80052DEC: jal         0x80047B48
    // 0x80052DF0: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    getLevelDatItemByName(rdram, ctx);
        goto after_2;
    // 0x80052DF0: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_2:
    // 0x80052DF4: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // 0x80052DF8: lhu         $a0, 0x0($v1)
    ctx->r4 = MEM_HU(ctx->r3, 0X0);
    // 0x80052DFC: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x80052E00: beq         $a0, $v0, L_80052E34
    if (ctx->r4 == ctx->r2) {
        // 0x80052E04: slti        $v0, $a0, 0x3
        ctx->r2 = SIGNED(ctx->r4) < 0X3 ? 1 : 0;
            goto L_80052E34;
    }
    // 0x80052E04: slti        $v0, $a0, 0x3
    ctx->r2 = SIGNED(ctx->r4) < 0X3 ? 1 : 0;
    // 0x80052E08: beq         $v0, $zero, L_80052E20
    if (ctx->r2 == 0) {
        // 0x80052E0C: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80052E20;
    }
    // 0x80052E0C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80052E10: beq         $a0, $v0, L_80052E60
    if (ctx->r4 == ctx->r2) {
        // 0x80052E14: lui         $v1, 0x8011
        ctx->r3 = S32(0X8011 << 16);
            goto L_80052E60;
    }
    // 0x80052E14: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
    // 0x80052E18: j           L_80052E98
    // 0x80052E1C: nop

        goto L_80052E98;
    // 0x80052E1C: nop

L_80052E20:
    // 0x80052E20: addiu       $v0, $zero, 0x26
    ctx->r2 = ADD32(0, 0X26);
    // 0x80052E24: beq         $a0, $v0, L_80052E7C
    if (ctx->r4 == ctx->r2) {
        // 0x80052E28: lui         $v1, 0x8011
        ctx->r3 = S32(0X8011 << 16);
            goto L_80052E7C;
    }
    // 0x80052E28: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
    // 0x80052E2C: j           L_80052E98
    // 0x80052E30: nop

        goto L_80052E98;
    // 0x80052E30: nop

L_80052E34:
    // 0x80052E34: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x80052E38: lwc1        $f0, 0x10($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X10);
    // 0x80052E3C: lw          $v0, -0x3620($a0)
    ctx->r2 = MEM_W(ctx->r4, -0X3620);
    // 0x80052E40: swc1        $f0, 0x4($s2)
    MEM_W(0X4, ctx->r18) = ctx->f0.u32l;
    // 0x80052E44: lwc1        $f0, 0x14($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X14);
    // 0x80052E48: swc1        $f0, 0x8($s2)
    MEM_W(0X8, ctx->r18) = ctx->f0.u32l;
    // 0x80052E4C: lwc1        $f0, 0x18($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X18);
    // 0x80052E50: ori         $v0, $v0, 0x80
    ctx->r2 = ctx->r2 | 0X80;
    // 0x80052E54: sw          $v0, -0x3620($a0)
    MEM_W(-0X3620, ctx->r4) = ctx->r2;
    // 0x80052E58: j           L_80052EA4
    // 0x80052E5C: swc1        $f0, 0xC($s2)
    MEM_W(0XC, ctx->r18) = ctx->f0.u32l;
        goto L_80052EA4;
    // 0x80052E5C: swc1        $f0, 0xC($s2)
    MEM_W(0XC, ctx->r18) = ctx->f0.u32l;
L_80052E60:
    // 0x80052E60: jal         0x80100594
    // 0x80052E64: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    func_80100594(rdram, ctx);
        goto after_3;
    // 0x80052E64: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    after_3:
    // 0x80052E68: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // 0x80052E6C: jal         0x800AFE4C
    // 0x80052E70: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    func_800AFE4C(rdram, ctx);
        goto after_4;
    // 0x80052E70: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    after_4:
    // 0x80052E74: j           L_80052E98
    // 0x80052E78: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
        goto L_80052E98;
    // 0x80052E78: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
L_80052E7C:
    // 0x80052E7C: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x80052E80: lw          $v1, -0x3620($v0)
    ctx->r3 = MEM_W(ctx->r2, -0X3620);
    // 0x80052E84: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x80052E88: sw          $s0, -0x13F0($a0)
    MEM_W(-0X13F0, ctx->r4) = ctx->r16;
    // 0x80052E8C: ori         $v1, $v1, 0x40
    ctx->r3 = ctx->r3 | 0X40;
    // 0x80052E90: j           L_80052EA4
    // 0x80052E94: sw          $v1, -0x3620($v0)
    MEM_W(-0X3620, ctx->r2) = ctx->r3;
        goto L_80052EA4;
    // 0x80052E94: sw          $v1, -0x3620($v0)
    MEM_W(-0X3620, ctx->r2) = ctx->r3;
L_80052E98:
    // 0x80052E98: lw          $v0, -0x3620($v1)
    ctx->r2 = MEM_W(ctx->r3, -0X3620);
    // 0x80052E9C: ori         $v0, $v0, 0x80
    ctx->r2 = ctx->r2 | 0X80;
    // 0x80052EA0: sw          $v0, -0x3620($v1)
    MEM_W(-0X3620, ctx->r3) = ctx->r2;
L_80052EA4:
    // 0x80052EA4: lw          $ra, 0x20($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X20);
    // 0x80052EA8: lw          $s3, 0x1C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X1C);
    // 0x80052EAC: lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X18);
    // 0x80052EB0: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x80052EB4: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x80052EB8: jr          $ra
    // 0x80052EBC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80052EBC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_80052EC0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80052EC0: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80052EC4: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80052EC8: addu        $s2, $a0, $zero
    ctx->r18 = ADD32(ctx->r4, 0);
    // 0x80052ECC: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80052ED0: addiu       $a0, $a0, -0x72E8
    ctx->r4 = ADD32(ctx->r4, -0X72E8);
    // 0x80052ED4: sll         $v0, $s2, 2
    ctx->r2 = S32(ctx->r18 << 2);
    // 0x80052ED8: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x80052EDC: addu        $s3, $v0, $s2
    ctx->r19 = ADD32(ctx->r2, ctx->r18);
    // 0x80052EE0: sll         $v1, $s3, 4
    ctx->r3 = S32(ctx->r19 << 4);
    // 0x80052EE4: addu        $v1, $v1, $s2
    ctx->r3 = ADD32(ctx->r3, ctx->r18);
    // 0x80052EE8: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x80052EEC: addu        $v1, $v1, $a0
    ctx->r3 = ADD32(ctx->r3, ctx->r4);
    // 0x80052EF0: sw          $ra, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r31;
    // 0x80052EF4: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80052EF8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80052EFC: lw          $a0, 0x4($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X4);
    // 0x80052F00: lhu         $v0, 0x0($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X0);
    // 0x80052F04: andi        $v0, $v0, 0xFFFE
    ctx->r2 = ctx->r2 & 0XFFFE;
    // 0x80052F08: sh          $v0, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r2;
    // 0x80052F0C: lw          $s0, 0x4($v1)
    ctx->r16 = MEM_W(ctx->r3, 0X4);
    // 0x80052F10: lhu         $v0, 0xF4($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0XF4);
    // 0x80052F14: ori         $s1, $zero, 0xFFFF
    ctx->r17 = 0 | 0XFFFF;
    // 0x80052F18: beq         $v0, $s1, L_80052F30
    if (ctx->r2 == ctx->r17) {
        // 0x80052F1C: lui         $t0, 0x8013
        ctx->r8 = S32(0X8013 << 16);
            goto L_80052F30;
    }
    // 0x80052F1C: lui         $t0, 0x8013
    ctx->r8 = S32(0X8013 << 16);
    // 0x80052F20: jal         0x8003F0C8
    // 0x80052F24: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    func_8003F0C8(rdram, ctx);
        goto after_0;
    // 0x80052F24: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    after_0:
    // 0x80052F28: sh          $s1, 0xF4($s0)
    MEM_H(0XF4, ctx->r16) = ctx->r17;
    // 0x80052F2C: lui         $t0, 0x8013
    ctx->r8 = S32(0X8013 << 16);
L_80052F30:
    // 0x80052F30: addiu       $t0, $t0, 0x7DB8
    ctx->r8 = ADD32(ctx->r8, 0X7DB8);
    // 0x80052F34: sll         $a2, $s3, 2
    ctx->r6 = S32(ctx->r19 << 2);
    // 0x80052F38: addu        $a2, $a2, $s2
    ctx->r6 = ADD32(ctx->r6, ctx->r18);
    // 0x80052F3C: sll         $a2, $a2, 5
    ctx->r6 = S32(ctx->r6 << 5);
    // 0x80052F40: addu        $v0, $a2, $t0
    ctx->r2 = ADD32(ctx->r6, ctx->r8);
    // 0x80052F44: lw          $a0, 0x1CC($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X1CC);
    // 0x80052F48: lhu         $v1, 0xB8($v0)
    ctx->r3 = MEM_HU(ctx->r2, 0XB8);
    // 0x80052F4C: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x80052F50: addiu       $v0, $v0, -0x1468
    ctx->r2 = ADD32(ctx->r2, -0X1468);
    // 0x80052F54: addiu       $t0, $t0, 0x8
    ctx->r8 = ADD32(ctx->r8, 0X8);
    // 0x80052F58: addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    // 0x80052F5C: lui         $a3, 0x3D40
    ctx->r7 = S32(0X3D40 << 16);
    // 0x80052F60: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x80052F64: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x80052F68: sw          $a0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r4;
    // 0x80052F6C: lw          $a0, 0x0($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X0);
    // 0x80052F70: jal         0x8005108C
    // 0x80052F74: addu        $a2, $a2, $t0
    ctx->r6 = ADD32(ctx->r6, ctx->r8);
    func_8005108C(rdram, ctx);
        goto after_1;
    // 0x80052F74: addu        $a2, $a2, $t0
    ctx->r6 = ADD32(ctx->r6, ctx->r8);
    after_1:
    // 0x80052F78: lw          $ra, 0x28($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X28);
    // 0x80052F7C: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x80052F80: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80052F84: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80052F88: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80052F8C: jr          $ra
    // 0x80052F90: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x80052F90: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_80052F94(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    {
        static int n = 0;
        ++n;
        if (n <= 10 || (n % 60) == 0) {
            if(0) fprintf(stderr, "[trace] func_80052F94 #%d (intro draw)\n", n);
            fflush(stderr);
        }
    }
    // 0x80052F94: addiu       $sp, $sp, -0x70
    ctx->r29 = ADD32(ctx->r29, -0X70);
    // 0x80052F98: sw          $s5, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r21;
    // 0x80052F9C: addu        $s5, $zero, $zero
    ctx->r21 = ADD32(0, 0);
    // 0x80052FA0: sw          $s6, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r22;
    // 0x80052FA4: addiu       $s6, $sp, 0x40
    ctx->r22 = ADD32(ctx->r29, 0X40);
    // 0x80052FA8: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x80052FAC: sw          $s1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r17;
    // 0x80052FB0: addiu       $s1, $v0, -0x72E8
    ctx->r17 = ADD32(ctx->r2, -0X72E8);
    // 0x80052FB4: sw          $ra, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r31;
    // 0x80052FB8: sw          $s4, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r20;
    // 0x80052FBC: sw          $s3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r19;
    // 0x80052FC0: sw          $s2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r18;
    // 0x80052FC4: sw          $s0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r16;
    // 0x80052FC8: sdc1        $f22, 0x68($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X68, ctx->r29);
    // 0x80052FCC: sdc1        $f20, 0x60($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X60, ctx->r29);
L_80052FD0:
    // 0x80052FD0: lbu         $v0, 0x0($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X0);
    // 0x80052FD4: beql        $v0, $zero, L_80053184
    if (ctx->r2 == 0) {
        // 0x80052FD8: addiu       $s5, $s5, 0x1
        ctx->r21 = ADD32(ctx->r21, 0X1);
            goto L_80053184;
    }
    goto skip_0;
    // 0x80052FD8: addiu       $s5, $s5, 0x1
    ctx->r21 = ADD32(ctx->r21, 0X1);
    skip_0:
    // 0x80052FDC: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80052FE0: lw          $v1, 0xB70($v0)
    ctx->r3 = MEM_W(ctx->r2, 0XB70);
    // 0x80052FE4: addiu       $v0, $zero, 0xA
    ctx->r2 = ADD32(0, 0XA);
    // 0x80052FE8: beq         $v1, $v0, L_80053014
    if (ctx->r3 == ctx->r2) {
        // 0x80052FEC: addu        $a0, $zero, $zero
        ctx->r4 = ADD32(0, 0);
            goto L_80053014;
    }
    // 0x80052FEC: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x80052FF0: lw          $v0, 0x74($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X74);
    // 0x80052FF4: bnel        $v0, $zero, L_80053008
    if (ctx->r2 != 0) {
        // 0x80052FF8: addiu       $a0, $s1, 0x74
        ctx->r4 = ADD32(ctx->r17, 0X74);
            goto L_80053008;
    }
    goto skip_1;
    // 0x80052FF8: addiu       $a0, $s1, 0x74
    ctx->r4 = ADD32(ctx->r17, 0X74);
    skip_1:
    // 0x80052FFC: addiu       $v0, $zero, 0x7
    ctx->r2 = ADD32(0, 0X7);
    // 0x80053000: bne         $v1, $v0, L_80053014
    if (ctx->r3 != ctx->r2) {
        // 0x80053004: nop
    
            goto L_80053014;
    }
    // 0x80053004: nop

L_80053008:
    // 0x80053008: jal         0x80009B48
    // 0x8005300C: nop

    func_80009B48(rdram, ctx);
        goto after_0;
    // 0x8005300C: nop

    after_0:
    // 0x80053010: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_80053014:
    // 0x80053014: jal         0x80017AB0
    // 0x80053018: addiu       $s2, $s1, 0x8
    ctx->r18 = ADD32(ctx->r17, 0X8);
    func_80017AB0(rdram, ctx);
        goto after_1;
    // 0x80053018: addiu       $s2, $s1, 0x8
    ctx->r18 = ADD32(ctx->r17, 0X8);
    after_1:
    // 0x8005301C: lw          $s0, 0x8($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X8);
    // 0x80053020: lw          $v0, 0x64($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X64);
    // 0x80053024: lw          $s3, 0x10($s1)
    ctx->r19 = MEM_W(ctx->r17, 0X10);
    // 0x80053028: lw          $s4, 0x14($s1)
    ctx->r20 = MEM_W(ctx->r17, 0X14);
    // 0x8005302C: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // 0x80053030: sw          $zero, 0x14($s1)
    MEM_W(0X14, ctx->r17) = 0;
    // 0x80053034: sw          $zero, 0x10($s1)
    MEM_W(0X10, ctx->r17) = 0;
    // 0x80053038: jal         0x80016C44
    // 0x8005303C: sw          $v0, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->r2;
    func_80016C44(rdram, ctx);
        goto after_2;
    // 0x8005303C: sw          $v0, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->r2;
    after_2:
    // 0x80053040: jal         0x8000B654
    // 0x80053044: nop

    func_8000B654(rdram, ctx);
        goto after_3;
    // 0x80053044: nop

    after_3:
    // 0x80053048: jal         0x80017AB0
    // 0x8005304C: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    func_80017AB0(rdram, ctx);
        goto after_4;
    // 0x8005304C: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    after_4:
    // 0x80053050: lw          $v0, 0x68($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X68);
    // 0x80053054: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // 0x80053058: sw          $zero, 0x14($s1)
    MEM_W(0X14, ctx->r17) = 0;
    // 0x8005305C: sw          $zero, 0x10($s1)
    MEM_W(0X10, ctx->r17) = 0;
    // 0x80053060: jal         0x80016C44
    // 0x80053064: sw          $v0, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->r2;
    func_80016C44(rdram, ctx);
        goto after_5;
    // 0x80053064: sw          $v0, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->r2;
    after_5:
    // 0x80053068: jal         0x8000B654
    // 0x8005306C: nop

    func_8000B654(rdram, ctx);
        goto after_6;
    // 0x8005306C: nop

    after_6:
    // 0x80053070: jal         0x80017AB0
    // 0x80053074: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    func_80017AB0(rdram, ctx);
        goto after_7;
    // 0x80053074: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    after_7:
    // 0x80053078: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // 0x8005307C: jal         0x80016C44
    // 0x80053080: sw          $s0, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->r16;
    func_80016C44(rdram, ctx);
        goto after_8;
    // 0x80053080: sw          $s0, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->r16;
    after_8:
    // 0x80053084: lw          $v0, 0x6C($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X6C);
    // 0x80053088: beq         $v0, $zero, L_800530EC
    if (ctx->r2 == 0) {
        // 0x8005308C: sw          $v0, 0x8($s1)
        MEM_W(0X8, ctx->r17) = ctx->r2;
            goto L_800530EC;
    }
    // 0x8005308C: sw          $v0, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->r2;
    // 0x80053090: jal         0x8000B654
    // 0x80053094: nop

    func_8000B654(rdram, ctx);
        goto after_9;
    // 0x80053094: nop

    after_9:
    // 0x80053098: addiu       $a0, $s1, 0x2C
    ctx->r4 = ADD32(ctx->r17, 0X2C);
    // 0x8005309C: lwc1        $f20, 0x2C($s1)
    ctx->f20.u32l = MEM_W(ctx->r17, 0X2C);
    // 0x800530A0: lwc1        $f22, 0x30($s1)
    ctx->f22.u32l = MEM_W(ctx->r17, 0X30);
    // 0x800530A4: jal         0x800C7120
    // 0x800530A8: addiu       $a1, $s1, 0x30
    ctx->r5 = ADD32(ctx->r17, 0X30);
    func_800C7120(rdram, ctx);
        goto after_10;
    // 0x800530A8: addiu       $a1, $s1, 0x30
    ctx->r5 = ADD32(ctx->r17, 0X30);
    after_10:
    // 0x800530AC: jal         0x80017AB0
    // 0x800530B0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_80017AB0(rdram, ctx);
        goto after_11;
    // 0x800530B0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_11:
    // 0x800530B4: jal         0x80017AD0
    // 0x800530B8: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    func_80017AD0(rdram, ctx);
        goto after_12;
    // 0x800530B8: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    after_12:
    // 0x800530BC: jal         0x80017AC0
    // 0x800530C0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_80017AC0(rdram, ctx);
        goto after_13;
    // 0x800530C0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_13:
    // 0x800530C4: jal         0x80009B48
    // 0x800530C8: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    func_80009B48(rdram, ctx);
        goto after_14;
    // 0x800530C8: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    after_14:
    // 0x800530CC: jal         0x80016C44
    // 0x800530D0: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    func_80016C44(rdram, ctx);
        goto after_15;
    // 0x800530D0: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    after_15:
    // 0x800530D4: jal         0x80017AD0
    // 0x800530D8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_80017AD0(rdram, ctx);
        goto after_16;
    // 0x800530D8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_16:
    // 0x800530DC: jal         0x80017AB0
    // 0x800530E0: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    func_80017AB0(rdram, ctx);
        goto after_17;
    // 0x800530E0: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    after_17:
    // 0x800530E4: swc1        $f20, 0x2C($s1)
    MEM_W(0X2C, ctx->r17) = ctx->f20.u32l;
    // 0x800530E8: swc1        $f22, 0x30($s1)
    MEM_W(0X30, ctx->r17) = ctx->f22.u32l;
L_800530EC:
    // 0x800530EC: jal         0x8000B654
    // 0x800530F0: nop

    func_8000B654(rdram, ctx);
        goto after_18;
    // 0x800530F0: nop

    after_18:
    // 0x800530F4: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    // 0x800530F8: addiu       $v1, $s1, 0x34
    ctx->r3 = ADD32(ctx->r17, 0X34);
    // 0x800530FC: lw          $v0, 0x70($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X70);
    // 0x80053100: addiu       $a1, $s1, 0x64
    ctx->r5 = ADD32(ctx->r17, 0X64);
    // 0x80053104: sw          $s3, 0x10($s1)
    MEM_W(0X10, ctx->r17) = ctx->r19;
    // 0x80053108: sw          $s4, 0x14($s1)
    MEM_W(0X14, ctx->r17) = ctx->r20;
    // 0x8005310C: sw          $v0, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->r2;
L_80053110:
    // 0x80053110: lw          $a2, 0x0($v1)
    ctx->r6 = MEM_W(ctx->r3, 0X0);
    // 0x80053114: lw          $a3, 0x4($v1)
    ctx->r7 = MEM_W(ctx->r3, 0X4);
    // 0x80053118: lw          $t0, 0x8($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X8);
    // 0x8005311C: lw          $t1, 0xC($v1)
    ctx->r9 = MEM_W(ctx->r3, 0XC);
    // 0x80053120: sw          $a2, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r6;
    // 0x80053124: sw          $a3, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r7;
    // 0x80053128: sw          $t0, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r8;
    // 0x8005312C: sw          $t1, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r9;
    // 0x80053130: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
    // 0x80053134: bne         $v1, $a1, L_80053110
    if (ctx->r3 != ctx->r5) {
        // 0x80053138: addiu       $a0, $a0, 0x10
        ctx->r4 = ADD32(ctx->r4, 0X10);
            goto L_80053110;
    }
    // 0x80053138: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    // 0x8005313C: addiu       $s0, $s1, 0x34
    ctx->r16 = ADD32(ctx->r17, 0X34);
    // 0x80053140: jal         0x8001CA50
    // 0x80053144: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_8001CA50(rdram, ctx);
        goto after_19;
    // 0x80053144: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_19:
    // 0x80053148: jal         0x80016C44
    // 0x8005314C: addiu       $a0, $s1, 0x8
    ctx->r4 = ADD32(ctx->r17, 0X8);
    func_80016C44(rdram, ctx);
        goto after_20;
    // 0x8005314C: addiu       $a0, $s1, 0x8
    ctx->r4 = ADD32(ctx->r17, 0X8);
    after_20:
    // 0x80053150: addiu       $v0, $sp, 0x10
    ctx->r2 = ADD32(ctx->r29, 0X10);
L_80053154:
    // 0x80053154: lw          $a2, 0x0($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X0);
    // 0x80053158: lw          $a3, 0x4($v0)
    ctx->r7 = MEM_W(ctx->r2, 0X4);
    // 0x8005315C: lw          $t0, 0x8($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X8);
    // 0x80053160: lw          $t1, 0xC($v0)
    ctx->r9 = MEM_W(ctx->r2, 0XC);
    // 0x80053164: sw          $a2, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r6;
    // 0x80053168: sw          $a3, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r7;
    // 0x8005316C: sw          $t0, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r8;
    // 0x80053170: sw          $t1, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r9;
    // 0x80053174: addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
    // 0x80053178: bne         $v0, $s6, L_80053154
    if (ctx->r2 != ctx->r22) {
        // 0x8005317C: addiu       $s0, $s0, 0x10
        ctx->r16 = ADD32(ctx->r16, 0X10);
            goto L_80053154;
    }
    // 0x8005317C: addiu       $s0, $s0, 0x10
    ctx->r16 = ADD32(ctx->r16, 0X10);
    // 0x80053180: addiu       $s5, $s5, 0x1
    ctx->r21 = ADD32(ctx->r21, 0X1);
L_80053184:
    // 0x80053184: blez        $s5, L_80052FD0
    if (SIGNED(ctx->r21) <= 0) {
        // 0x80053188: addiu       $s1, $s1, 0x144
        ctx->r17 = ADD32(ctx->r17, 0X144);
            goto L_80052FD0;
    }
    // 0x80053188: addiu       $s1, $s1, 0x144
    ctx->r17 = ADD32(ctx->r17, 0X144);
    // 0x8005318C: lw          $ra, 0x5C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X5C);
    // 0x80053190: lw          $s6, 0x58($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X58);
    // 0x80053194: lw          $s5, 0x54($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X54);
    // 0x80053198: lw          $s4, 0x50($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X50);
    // 0x8005319C: lw          $s3, 0x4C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X4C);
    // 0x800531A0: lw          $s2, 0x48($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X48);
    // 0x800531A4: lw          $s1, 0x44($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X44);
    // 0x800531A8: lw          $s0, 0x40($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X40);
    // 0x800531AC: ldc1        $f22, 0x68($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X68);
    // 0x800531B0: ldc1        $f20, 0x60($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X60);
    // 0x800531B4: jr          $ra
    // 0x800531B8: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
    return;
    // 0x800531B8: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
;}
RECOMP_FUNC void func_800531BC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800531BC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800531C0: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x800531C4: addiu       $v1, $v1, 0x7DB8
    ctx->r3 = ADD32(ctx->r3, 0X7DB8);
    // 0x800531C8: sll         $v0, $a0, 2
    ctx->r2 = S32(ctx->r4 << 2);
    // 0x800531CC: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x800531D0: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800531D4: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x800531D8: sll         $v0, $v0, 5
    ctx->r2 = S32(ctx->r2 << 5);
    // 0x800531DC: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800531E0: sll         $v1, $a1, 2
    ctx->r3 = S32(ctx->r5 << 2);
    // 0x800531E4: sw          $ra, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r31;
    // 0x800531E8: lw          $v0, 0x1CC($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X1CC);
    // 0x800531EC: lui         $a3, 0x3D40
    ctx->r7 = S32(0X3D40 << 16);
    // 0x800531F0: addu        $a1, $a0, $zero
    ctx->r5 = ADD32(ctx->r4, 0);
    // 0x800531F4: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // 0x800531F8: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x800531FC: addiu       $v0, $v0, -0x1468
    ctx->r2 = ADD32(ctx->r2, -0X1468);
    // 0x80053200: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x80053204: lw          $a0, 0x0($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X0);
    // 0x80053208: jal         0x8005108C
    // 0x8005320C: nop

    func_8005108C(rdram, ctx);
        goto after_0;
    // 0x8005320C: nop

    after_0:
    // 0x80053210: lw          $ra, 0x18($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X18);
    // 0x80053214: jr          $ra
    // 0x80053218: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80053218: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_8005321C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005321C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80053220: addu        $a2, $a0, $zero
    ctx->r6 = ADD32(ctx->r4, 0);
    // 0x80053224: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x80053228: lw          $v1, -0x7DA0($v0)
    ctx->r3 = MEM_W(ctx->r2, -0X7DA0);
    // 0x8005322C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80053230: bne         $v1, $v0, L_80053248
    if (ctx->r3 != ctx->r2) {
        // 0x80053234: sw          $ra, 0x10($sp)
        MEM_W(0X10, ctx->r29) = ctx->r31;
            goto L_80053248;
    }
    // 0x80053234: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x80053238: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x8005323C: lw          $v0, -0x776C($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X776C);
    // 0x80053240: j           L_80053270
    // 0x80053244: sw          $a1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r5;
        goto L_80053270;
    // 0x80053244: sw          $a1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r5;
L_80053248:
    // 0x80053248: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8005324C: lw          $v1, 0xC($a1)
    ctx->r3 = MEM_W(ctx->r5, 0XC);
    // 0x80053250: addiu       $a0, $a0, -0x72E8
    ctx->r4 = ADD32(ctx->r4, -0X72E8);
    // 0x80053254: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x80053258: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8005325C: sll         $v0, $v0, 4
    ctx->r2 = S32(ctx->r2 << 4);
    // 0x80053260: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80053264: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80053268: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x8005326C: sw          $a1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r5;
L_80053270:
    // 0x80053270: addiu       $a0, $a2, 0x2C
    ctx->r4 = ADD32(ctx->r6, 0X2C);
    // 0x80053274: jal         0x8001C774
    // 0x80053278: addiu       $a1, $a1, 0x28
    ctx->r5 = ADD32(ctx->r5, 0X28);
    func_8001C774(rdram, ctx);
        goto after_0;
    // 0x80053278: addiu       $a1, $a1, 0x28
    ctx->r5 = ADD32(ctx->r5, 0X28);
    after_0:
    // 0x8005327C: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x80053280: jr          $ra
    // 0x80053284: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80053284: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_80053288(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80053288: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8005328C: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x80053290: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x80053294: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x80053298: addu        $s1, $a1, $zero
    ctx->r17 = ADD32(ctx->r5, 0);
    // 0x8005329C: sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // 0x800532A0: addu        $s2, $a2, $zero
    ctx->r18 = ADD32(ctx->r6, 0);
    // 0x800532A4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800532A8: jal         0x800A9E70
    // 0x800532AC: addiu       $a0, $s0, 0x28
    ctx->r4 = ADD32(ctx->r16, 0X28);
    func_800A9E70(rdram, ctx);
        goto after_0;
    // 0x800532AC: addiu       $a0, $s0, 0x28
    ctx->r4 = ADD32(ctx->r16, 0X28);
    after_0:
    // 0x800532B0: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x800532B4: lw          $v1, 0x4($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X4);
    // 0x800532B8: lw          $a3, 0x8($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X8);
    // 0x800532BC: sw          $v0, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->r2;
    // 0x800532C0: sw          $v1, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->r3;
    // 0x800532C4: sw          $a3, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->r7;
    // 0x800532C8: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x800532CC: lw          $v1, 0x4($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X4);
    // 0x800532D0: lw          $a3, 0x8($s2)
    ctx->r7 = MEM_W(ctx->r18, 0X8);
    // 0x800532D4: sw          $v0, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->r2;
    // 0x800532D8: sw          $v1, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->r3;
    // 0x800532DC: sw          $a3, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->r7;
    // 0x800532E0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800532E4: lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X18);
    // 0x800532E8: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x800532EC: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x800532F0: jr          $ra
    // 0x800532F4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x800532F4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_800532F8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800532F8: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800532FC: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80053300: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80053304: sdc1        $f20, 0x28($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X28, ctx->r29);
    // 0x80053308: lwc1        $f0, 0x24($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0X24);
    // 0x8005330C: lwc1        $f2, 0x24($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X24);
    // 0x80053310: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x80053314: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    // 0x80053318: lwc1        $f0, 0x28($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0X28);
    // 0x8005331C: lwc1        $f2, 0x28($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X28);
    // 0x80053320: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x80053324: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    // 0x80053328: lwc1        $f0, 0x2C($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0X2C);
    // 0x8005332C: lwc1        $f2, 0x2C($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X2C);
    // 0x80053330: addu        $s0, $a2, $zero
    ctx->r16 = ADD32(ctx->r6, 0);
    // 0x80053334: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x80053338: mtc1        $a3, $f20
    ctx->f20.u32l = ctx->r7;
    // 0x8005333C: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    // 0x80053340: jal         0x8001CF2C
    // 0x80053344: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    func_8001CF2C(rdram, ctx);
        goto after_0;
    // 0x80053344: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    after_0:
    // 0x80053348: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8005334C: lwc1        $f2, -0x5448($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X5448);
    // 0x80053350: mov.s       $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    ctx->f6.fl = ctx->f0.fl;
    // 0x80053354: c.lt.s      $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f2.fl < ctx->f6.fl;
    // 0x80053358: nop

    // 0x8005335C: bc1f        L_800533C0
    if (!c1cs) {
        // 0x80053360: swc1        $f20, 0x8($s0)
        MEM_W(0X8, ctx->r16) = ctx->f20.u32l;
            goto L_800533C0;
    }
    // 0x80053360: swc1        $f20, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f20.u32l;
    // 0x80053364: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80053368: lwc1        $f0, -0x5444($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X5444);
    // 0x8005336C: lwc1        $f4, 0x10($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X10);
    // 0x80053370: div.s       $f0, $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f6.fl);
    // 0x80053374: mul.s       $f4, $f0, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x80053378: lwc1        $f12, 0x14($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X14);
    // 0x8005337C: mul.s       $f12, $f0, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = MUL_S(ctx->f0.fl, ctx->f12.fl);
    // 0x80053380: lwc1        $f2, 0x18($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X18);
    // 0x80053384: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x80053388: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8005338C: lwc1        $f20, -0x5440($at)
    ctx->f20.u32l = MEM_W(ctx->r1, -0X5440);
    // 0x80053390: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x80053394: swc1        $f12, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f12.u32l;
    // 0x80053398: jal         0x8001C400
    // 0x8005339C: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    func_8001C400(rdram, ctx);
        goto after_1;
    // 0x8005339C: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    after_1:
    // 0x800533A0: mul.s       $f0, $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f20.fl);
    // 0x800533A4: swc1        $f0, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f0.u32l;
    // 0x800533A8: lwc1        $f12, 0x10($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X10);
    // 0x800533AC: lwc1        $f14, 0x18($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X18);
    // 0x800533B0: jal         0x8001C5F4
    // 0x800533B4: neg.s       $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = -ctx->f12.fl;
    func_8001C5F4(rdram, ctx);
        goto after_2;
    // 0x800533B4: neg.s       $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = -ctx->f12.fl;
    after_2:
    // 0x800533B8: mul.s       $f0, $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f20.fl);
    // 0x800533BC: swc1        $f0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f0.u32l;
L_800533C0:
    // 0x800533C0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800533C4: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x800533C8: ldc1        $f20, 0x28($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X28);
    // 0x800533CC: jr          $ra
    // 0x800533D0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x800533D0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_800533D4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800533D4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800533D8: beq         $a1, $a2, L_80053580
    if (ctx->r5 == ctx->r6) {
        // 0x800533DC: sw          $ra, 0x10($sp)
        MEM_W(0X10, ctx->r29) = ctx->r31;
            goto L_80053580;
    }
    // 0x800533DC: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x800533E0: sll         $v1, $a0, 5
    ctx->r3 = S32(ctx->r4 << 5);
    // 0x800533E4: subu        $v1, $v1, $a0
    ctx->r3 = SUB32(ctx->r3, ctx->r4);
    // 0x800533E8: sll         $v1, $v1, 5
    ctx->r3 = S32(ctx->r3 << 5);
    // 0x800533EC: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x800533F0: addiu       $v0, $v0, -0x76D0
    ctx->r2 = ADD32(ctx->r2, -0X76D0);
    // 0x800533F4: addu        $t0, $v1, $v0
    ctx->r8 = ADD32(ctx->r3, ctx->r2);
    // 0x800533F8: lhu         $v1, 0x0($t0)
    ctx->r3 = MEM_HU(ctx->r8, 0X0);
    // 0x800533FC: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // 0x80053400: sh          $v0, 0x2($t0)
    MEM_H(0X2, ctx->r8) = ctx->r2;
    // 0x80053404: sw          $a1, 0xBC($t0)
    MEM_W(0XBC, ctx->r8) = ctx->r5;
    // 0x80053408: sw          $a2, 0xC0($t0)
    MEM_W(0XC0, ctx->r8) = ctx->r6;
    // 0x8005340C: sw          $zero, 0xC4($t0)
    MEM_W(0XC4, ctx->r8) = 0;
    // 0x80053410: lwc1        $f0, 0x28($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X28);
    // 0x80053414: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x80053418: swc1        $f0, 0xC8($t0)
    MEM_W(0XC8, ctx->r8) = ctx->f0.u32l;
    // 0x8005341C: lwc1        $f0, 0x2C($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80053420: ori         $v1, $v1, 0x1
    ctx->r3 = ctx->r3 | 0X1;
    // 0x80053424: sh          $v1, 0x0($t0)
    MEM_H(0X0, ctx->r8) = ctx->r3;
    // 0x80053428: lw          $v1, -0x7DA0($v0)
    ctx->r3 = MEM_W(ctx->r2, -0X7DA0);
    // 0x8005342C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80053430: sw          $a3, 0x74($t0)
    MEM_W(0X74, ctx->r8) = ctx->r7;
    // 0x80053434: bne         $v1, $v0, L_80053454
    if (ctx->r3 != ctx->r2) {
        // 0x80053438: swc1        $f0, 0xCC($t0)
        MEM_W(0XCC, ctx->r8) = ctx->f0.u32l;
            goto L_80053454;
    }
    // 0x80053438: swc1        $f0, 0xCC($t0)
    MEM_W(0XCC, ctx->r8) = ctx->f0.u32l;
    // 0x8005343C: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x80053440: lui         $v1, 0x8014
    ctx->r3 = S32(0X8014 << 16);
    // 0x80053444: lw          $v0, -0x776C($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X776C);
    // 0x80053448: addiu       $v1, $v1, -0x72E8
    ctx->r3 = ADD32(ctx->r3, -0X72E8);
    // 0x8005344C: j           L_8005345C
    // 0x80053450: sw          $t0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r8;
        goto L_8005345C;
    // 0x80053450: sw          $t0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r8;
L_80053454:
    // 0x80053454: lui         $v1, 0x8014
    ctx->r3 = S32(0X8014 << 16);
    // 0x80053458: addiu       $v1, $v1, -0x72E8
    ctx->r3 = ADD32(ctx->r3, -0X72E8);
L_8005345C:
    // 0x8005345C: sll         $v0, $a0, 2
    ctx->r2 = S32(ctx->r4 << 2);
    // 0x80053460: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x80053464: sll         $v0, $v0, 4
    ctx->r2 = S32(ctx->r2 << 4);
    // 0x80053468: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x8005346C: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80053470: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80053474: sw          $t0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r8;
    // 0x80053478: addiu       $v1, $t0, 0x28
    ctx->r3 = ADD32(ctx->r8, 0X28);
    // 0x8005347C: addiu       $v0, $a1, 0x28
    ctx->r2 = ADD32(ctx->r5, 0X28);
    // 0x80053480: addiu       $a3, $a1, 0x58
    ctx->r7 = ADD32(ctx->r5, 0X58);
L_80053484:
    // 0x80053484: lw          $t1, 0x0($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X0);
    // 0x80053488: lw          $t2, 0x4($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X4);
    // 0x8005348C: lw          $t3, 0x8($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X8);
    // 0x80053490: lw          $t4, 0xC($v0)
    ctx->r12 = MEM_W(ctx->r2, 0XC);
    // 0x80053494: sw          $t1, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r9;
    // 0x80053498: sw          $t2, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r10;
    // 0x8005349C: sw          $t3, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r11;
    // 0x800534A0: sw          $t4, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r12;
    // 0x800534A4: addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
    // 0x800534A8: bne         $v0, $a3, L_80053484
    if (ctx->r2 != ctx->r7) {
        // 0x800534AC: addiu       $v1, $v1, 0x10
        ctx->r3 = ADD32(ctx->r3, 0X10);
            goto L_80053484;
    }
    // 0x800534AC: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
    // 0x800534B0: addiu       $a3, $a2, 0x28
    ctx->r7 = ADD32(ctx->r6, 0X28);
    // 0x800534B4: lw          $t1, 0x10($a1)
    ctx->r9 = MEM_W(ctx->r5, 0X10);
    // 0x800534B8: lw          $t2, 0x14($a1)
    ctx->r10 = MEM_W(ctx->r5, 0X14);
    // 0x800534BC: lw          $t3, 0x18($a1)
    ctx->r11 = MEM_W(ctx->r5, 0X18);
    // 0x800534C0: sw          $t1, 0x10($t0)
    MEM_W(0X10, ctx->r8) = ctx->r9;
    // 0x800534C4: sw          $t2, 0x14($t0)
    MEM_W(0X14, ctx->r8) = ctx->r10;
    // 0x800534C8: sw          $t3, 0x18($t0)
    MEM_W(0X18, ctx->r8) = ctx->r11;
    // 0x800534CC: lw          $t1, 0x1C($a1)
    ctx->r9 = MEM_W(ctx->r5, 0X1C);
    // 0x800534D0: lw          $t2, 0x20($a1)
    ctx->r10 = MEM_W(ctx->r5, 0X20);
    // 0x800534D4: lw          $t3, 0x24($a1)
    ctx->r11 = MEM_W(ctx->r5, 0X24);
    // 0x800534D8: sw          $t1, 0x1C($t0)
    MEM_W(0X1C, ctx->r8) = ctx->r9;
    // 0x800534DC: sw          $t2, 0x20($t0)
    MEM_W(0X20, ctx->r8) = ctx->r10;
    // 0x800534E0: sw          $t3, 0x24($t0)
    MEM_W(0X24, ctx->r8) = ctx->r11;
    // 0x800534E4: lhu         $v0, 0x0($a1)
    ctx->r2 = MEM_HU(ctx->r5, 0X0);
    // 0x800534E8: addiu       $v1, $a1, 0x28
    ctx->r3 = ADD32(ctx->r5, 0X28);
    // 0x800534EC: ori         $v0, $v0, 0x1
    ctx->r2 = ctx->r2 | 0X1;
    // 0x800534F0: sh          $v0, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r2;
    // 0x800534F4: lhu         $v0, 0x0($a2)
    ctx->r2 = MEM_HU(ctx->r6, 0X0);
    // 0x800534F8: addiu       $a1, $a1, 0x58
    ctx->r5 = ADD32(ctx->r5, 0X58);
    // 0x800534FC: ori         $v0, $v0, 0x1
    ctx->r2 = ctx->r2 | 0X1;
    // 0x80053500: sh          $v0, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r2;
L_80053504:
    // 0x80053504: lw          $t1, 0x0($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X0);
    // 0x80053508: lw          $t2, 0x4($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X4);
    // 0x8005350C: lw          $t3, 0x8($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X8);
    // 0x80053510: lw          $t4, 0xC($v1)
    ctx->r12 = MEM_W(ctx->r3, 0XC);
    // 0x80053514: sw          $t1, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r9;
    // 0x80053518: sw          $t2, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r10;
    // 0x8005351C: sw          $t3, 0x8($a3)
    MEM_W(0X8, ctx->r7) = ctx->r11;
    // 0x80053520: sw          $t4, 0xC($a3)
    MEM_W(0XC, ctx->r7) = ctx->r12;
    // 0x80053524: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
    // 0x80053528: bne         $v1, $a1, L_80053504
    if (ctx->r3 != ctx->r5) {
        // 0x8005352C: addiu       $a3, $a3, 0x10
        ctx->r7 = ADD32(ctx->r7, 0X10);
            goto L_80053504;
    }
    // 0x8005352C: addiu       $a3, $a3, 0x10
    ctx->r7 = ADD32(ctx->r7, 0X10);
    // 0x80053530: lui         $v1, 0x8014
    ctx->r3 = S32(0X8014 << 16);
    // 0x80053534: addiu       $v1, $v1, -0x72E8
    ctx->r3 = ADD32(ctx->r3, -0X72E8);
    // 0x80053538: sll         $v0, $a0, 2
    ctx->r2 = S32(ctx->r4 << 2);
    // 0x8005353C: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x80053540: sll         $v0, $v0, 4
    ctx->r2 = S32(ctx->r2 << 4);
    // 0x80053544: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x80053548: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8005354C: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80053550: lwc1        $f0, 0x4C($a2)
    ctx->f0.u32l = MEM_W(ctx->r6, 0X4C);
    // 0x80053554: lwc1        $f2, 0x50($a2)
    ctx->f2.u32l = MEM_W(ctx->r6, 0X50);
    // 0x80053558: lwc1        $f6, 0xA0($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0XA0);
    // 0x8005355C: lwc1        $f4, 0x54($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0X54);
    // 0x80053560: mov.s       $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = ctx->f6.fl;
    // 0x80053564: swc1        $f0, 0x10($a2)
    MEM_W(0X10, ctx->r6) = ctx->f0.u32l;
    // 0x80053568: swc1        $f2, 0x14($a2)
    MEM_W(0X14, ctx->r6) = ctx->f2.u32l;
    // 0x8005356C: swc1        $f4, 0x18($a2)
    MEM_W(0X18, ctx->r6) = ctx->f4.u32l;
    // 0x80053570: swc1        $f6, 0x98($a2)
    MEM_W(0X98, ctx->r6) = ctx->f6.u32l;
    // 0x80053574: swc1        $f8, 0x9C($a2)
    MEM_W(0X9C, ctx->r6) = ctx->f8.u32l;
    // 0x80053578: jal         0x80066A50
    // 0x8005357C: sw          $t0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r8;
    func_80066A50(rdram, ctx);
        goto after_0;
    // 0x8005357C: sw          $t0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r8;
    after_0:
L_80053580:
    // 0x80053580: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x80053584: jr          $ra
    // 0x80053588: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80053588: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_8005358C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005358C: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x80053590: lw          $v0, -0x35E0($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X35E0);
    // 0x80053594: bne         $v0, $zero, L_80053604
    if (ctx->r2 != 0) {
        // 0x80053598: lui         $v0, 0x8014
        ctx->r2 = S32(0X8014 << 16);
            goto L_80053604;
    }
    // 0x80053598: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x8005359C: addiu       $v0, $v0, -0x72E8
    ctx->r2 = ADD32(ctx->r2, -0X72E8);
    // 0x800535A0: sll         $v1, $a0, 2
    ctx->r3 = S32(ctx->r4 << 2);
    // 0x800535A4: addu        $v1, $v1, $a0
    ctx->r3 = ADD32(ctx->r3, ctx->r4);
    // 0x800535A8: sll         $v1, $v1, 4
    ctx->r3 = S32(ctx->r3 << 4);
    // 0x800535AC: addu        $v1, $v1, $a0
    ctx->r3 = ADD32(ctx->r3, ctx->r4);
    // 0x800535B0: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x800535B4: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x800535B8: lw          $v1, 0x4($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X4);
    // 0x800535BC: lhu         $v0, 0x0($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X0);
    // 0x800535C0: andi        $v0, $v0, 0x10
    ctx->r2 = ctx->r2 & 0X10;
    // 0x800535C4: beq         $v0, $zero, L_800535D8
    if (ctx->r2 == 0) {
        // 0x800535C8: addiu       $v0, $zero, 0x3
        ctx->r2 = ADD32(0, 0X3);
            goto L_800535D8;
    }
    // 0x800535C8: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x800535CC: lw          $v1, 0x8($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X8);
    // 0x800535D0: bne         $v1, $v0, L_80053604
    if (ctx->r3 != ctx->r2) {
        // 0x800535D4: nop
    
            goto L_80053604;
    }
    // 0x800535D4: nop

L_800535D8:
    // 0x800535D8: lui         $v1, 0x800A
    ctx->r3 = S32(0X800A << 16);
    // 0x800535DC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800535E0: sb          $v0, -0x1444($v1)
    MEM_B(-0X1444, ctx->r3) = ctx->r2;
    // 0x800535E4: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x800535E8: lui         $a1, 0x8011
    ctx->r5 = S32(0X8011 << 16);
    // 0x800535EC: lw          $a0, -0x1440($v0)
    ctx->r4 = MEM_W(ctx->r2, -0X1440);
    // 0x800535F0: lw          $v0, -0x3620($a1)
    ctx->r2 = MEM_W(ctx->r5, -0X3620);
    // 0x800535F4: lui         $v1, 0x800A
    ctx->r3 = S32(0X800A << 16);
    // 0x800535F8: ori         $v0, $v0, 0x40
    ctx->r2 = ctx->r2 | 0X40;
    // 0x800535FC: sw          $a0, -0x13F0($v1)
    MEM_W(-0X13F0, ctx->r3) = ctx->r4;
    // 0x80053600: sw          $v0, -0x3620($a1)
    MEM_W(-0X3620, ctx->r5) = ctx->r2;
L_80053604:
    // 0x80053604: jr          $ra
    // 0x80053608: nop

    return;
    // 0x80053608: nop

;}
RECOMP_FUNC void func_8005360C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005360C: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // 0x80053610: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80053614: addiu       $a3, $v0, 0x7D08
    ctx->r7 = ADD32(ctx->r2, 0X7D08);
    // 0x80053618: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8005361C: lwc1        $f0, -0x543C($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X543C);
    // 0x80053620: addu        $a1, $a2, $zero
    ctx->r5 = ADD32(ctx->r6, 0);
L_80053624:
    // 0x80053624: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x80053628: addu        $v1, $a3, $zero
    ctx->r3 = ADD32(ctx->r7, 0);
L_8005362C:
    // 0x8005362C: addu        $v0, $a1, $v1
    ctx->r2 = ADD32(ctx->r5, ctx->r3);
    // 0x80053630: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x80053634: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
    // 0x80053638: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8005363C: sb          $zero, 0x8($v0)
    MEM_B(0X8, ctx->r2) = 0;
    // 0x80053640: sw          $zero, 0xC($v0)
    MEM_W(0XC, ctx->r2) = 0;
    // 0x80053644: sw          $zero, 0x10($v0)
    MEM_W(0X10, ctx->r2) = 0;
    // 0x80053648: sw          $zero, 0x14($v0)
    MEM_W(0X14, ctx->r2) = 0;
    // 0x8005364C: sw          $zero, 0x18($v0)
    MEM_W(0X18, ctx->r2) = 0;
    // 0x80053650: sw          $zero, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = 0;
    // 0x80053654: sw          $zero, 0x20($v0)
    MEM_W(0X20, ctx->r2) = 0;
    // 0x80053658: swc1        $f0, 0x2C($v0)
    MEM_W(0X2C, ctx->r2) = ctx->f0.u32l;
    // 0x8005365C: swc1        $f0, 0x28($v0)
    MEM_W(0X28, ctx->r2) = ctx->f0.u32l;
    // 0x80053660: swc1        $f0, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->f0.u32l;
    // 0x80053664: sw          $zero, 0x30($v0)
    MEM_W(0X30, ctx->r2) = 0;
    // 0x80053668: swc1        $f0, 0x34($v0)
    MEM_W(0X34, ctx->r2) = ctx->f0.u32l;
    // 0x8005366C: slti        $v0, $a0, 0x2
    ctx->r2 = SIGNED(ctx->r4) < 0X2 ? 1 : 0;
    // 0x80053670: bne         $v0, $zero, L_8005362C
    if (ctx->r2 != 0) {
        // 0x80053674: addiu       $v1, $v1, 0x58
        ctx->r3 = ADD32(ctx->r3, 0X58);
            goto L_8005362C;
    }
    // 0x80053674: addiu       $v1, $v1, 0x58
    ctx->r3 = ADD32(ctx->r3, 0X58);
    // 0x80053678: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x8005367C: blez        $a2, L_80053624
    if (SIGNED(ctx->r6) <= 0) {
        // 0x80053680: addiu       $a1, $a1, 0xB0
        ctx->r5 = ADD32(ctx->r5, 0XB0);
            goto L_80053624;
    }
    // 0x80053680: addiu       $a1, $a1, 0xB0
    ctx->r5 = ADD32(ctx->r5, 0XB0);
    // 0x80053684: jr          $ra
    // 0x80053688: nop

    return;
    // 0x80053688: nop

;}
RECOMP_FUNC void func_8005368C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005368C: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x80053690: lw          $v1, -0x7DA0($v0)
    ctx->r3 = MEM_W(ctx->r2, -0X7DA0);
    // 0x80053694: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80053698: bne         $v1, $v0, L_800536C8
    if (ctx->r3 != ctx->r2) {
        // 0x8005369C: addu        $v1, $zero, $zero
        ctx->r3 = ADD32(0, 0);
            goto L_800536C8;
    }
    // 0x8005369C: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
    // 0x800536A0: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x800536A4: lw          $v0, -0x776C($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X776C);
    // 0x800536A8: sw          $zero, 0x8($v0)
    MEM_W(0X8, ctx->r2) = 0;
    // 0x800536AC: sw          $zero, 0x14($v0)
    MEM_W(0X14, ctx->r2) = 0;
    // 0x800536B0: sw          $zero, 0x10($v0)
    MEM_W(0X10, ctx->r2) = 0;
    // 0x800536B4: sw          $zero, 0x70($v0)
    MEM_W(0X70, ctx->r2) = 0;
    // 0x800536B8: sw          $zero, 0x6C($v0)
    MEM_W(0X6C, ctx->r2) = 0;
    // 0x800536BC: sw          $zero, 0x68($v0)
    MEM_W(0X68, ctx->r2) = 0;
    // 0x800536C0: jr          $ra
    // 0x800536C4: sw          $zero, 0x64($v0)
    MEM_W(0X64, ctx->r2) = 0;
    return;
    // 0x800536C4: sw          $zero, 0x64($v0)
    MEM_W(0X64, ctx->r2) = 0;
L_800536C8:
    // 0x800536C8: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x800536CC: addiu       $v0, $v0, -0x72E8
    ctx->r2 = ADD32(ctx->r2, -0X72E8);
L_800536D0:
    // 0x800536D0: sw          $zero, 0x8($v0)
    MEM_W(0X8, ctx->r2) = 0;
    // 0x800536D4: sw          $zero, 0x14($v0)
    MEM_W(0X14, ctx->r2) = 0;
    // 0x800536D8: sw          $zero, 0x10($v0)
    MEM_W(0X10, ctx->r2) = 0;
    // 0x800536DC: sw          $zero, 0x70($v0)
    MEM_W(0X70, ctx->r2) = 0;
    // 0x800536E0: sw          $zero, 0x6C($v0)
    MEM_W(0X6C, ctx->r2) = 0;
    // 0x800536E4: sw          $zero, 0x68($v0)
    MEM_W(0X68, ctx->r2) = 0;
    // 0x800536E8: sw          $zero, 0x64($v0)
    MEM_W(0X64, ctx->r2) = 0;
    // 0x800536EC: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800536F0: blez        $v1, L_800536D0
    if (SIGNED(ctx->r3) <= 0) {
        // 0x800536F4: addiu       $v0, $v0, 0x144
        ctx->r2 = ADD32(ctx->r2, 0X144);
            goto L_800536D0;
    }
    // 0x800536F4: addiu       $v0, $v0, 0x144
    ctx->r2 = ADD32(ctx->r2, 0X144);
    // 0x800536F8: jr          $ra
    // 0x800536FC: nop

    return;
    // 0x800536FC: nop

;}
RECOMP_FUNC void func_80053700(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80053700: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80053704: sw          $ra, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r31;
    // 0x80053708: sw          $s5, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r21;
    // 0x8005370C: sw          $s4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r20;
    // 0x80053710: sw          $s3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r19;
    // 0x80053714: sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // 0x80053718: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x8005371C: jal         0x8004F8DC
    // 0x80053720: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    func_8004F8DC(rdram, ctx);
        goto after_0;
    // 0x80053720: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    after_0:
    // 0x80053724: addu        $s1, $zero, $zero
    ctx->r17 = ADD32(0, 0);
    // 0x80053728: lui         $s5, 0x8014
    ctx->r21 = S32(0X8014 << 16);
    // 0x8005372C: addiu       $s4, $zero, 0x1
    ctx->r20 = ADD32(0, 0X1);
    // 0x80053730: lui         $s3, 0x8014
    ctx->r19 = S32(0X8014 << 16);
    // 0x80053734: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x80053738: addiu       $s2, $v0, -0x72E8
    ctx->r18 = ADD32(ctx->r2, -0X72E8);
    // 0x8005373C: addu        $s0, $s2, $zero
    ctx->r16 = ADD32(ctx->r18, 0);
L_80053740:
    // 0x80053740: lbu         $v0, 0x0($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X0);
    // 0x80053744: beql        $v0, $zero, L_80053798
    if (ctx->r2 == 0) {
        // 0x80053748: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_80053798;
    }
    goto skip_0;
    // 0x80053748: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    skip_0:
    // 0x8005374C: lw          $v0, -0x7DA0($s5)
    ctx->r2 = MEM_W(ctx->r21, -0X7DA0);
    // 0x80053750: lw          $a1, 0x4($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X4);
    // 0x80053754: bne         $v0, $s4, L_80053768
    if (ctx->r2 != ctx->r20) {
        // 0x80053758: addiu       $a0, $s0, 0x8
        ctx->r4 = ADD32(ctx->r16, 0X8);
            goto L_80053768;
    }
    // 0x80053758: addiu       $a0, $s0, 0x8
    ctx->r4 = ADD32(ctx->r16, 0X8);
    // 0x8005375C: lw          $v0, -0x776C($s3)
    ctx->r2 = MEM_W(ctx->r19, -0X776C);
    // 0x80053760: j           L_80053788
    // 0x80053764: sw          $a1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r5;
        goto L_80053788;
    // 0x80053764: sw          $a1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r5;
L_80053768:
    // 0x80053768: lw          $v1, 0xC($a1)
    ctx->r3 = MEM_W(ctx->r5, 0XC);
    // 0x8005376C: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x80053770: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80053774: sll         $v0, $v0, 4
    ctx->r2 = S32(ctx->r2 << 4);
    // 0x80053778: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8005377C: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80053780: addu        $v0, $v0, $s2
    ctx->r2 = ADD32(ctx->r2, ctx->r18);
    // 0x80053784: sw          $a1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r5;
L_80053788:
    // 0x80053788: addiu       $a0, $a0, 0x2C
    ctx->r4 = ADD32(ctx->r4, 0X2C);
    // 0x8005378C: jal         0x8001C774
    // 0x80053790: addiu       $a1, $a1, 0x28
    ctx->r5 = ADD32(ctx->r5, 0X28);
    func_8001C774(rdram, ctx);
        goto after_1;
    // 0x80053790: addiu       $a1, $a1, 0x28
    ctx->r5 = ADD32(ctx->r5, 0X28);
    after_1:
    // 0x80053794: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
L_80053798:
    // 0x80053798: blez        $s1, L_80053740
    if (SIGNED(ctx->r17) <= 0) {
        // 0x8005379C: addiu       $s0, $s0, 0x144
        ctx->r16 = ADD32(ctx->r16, 0X144);
            goto L_80053740;
    }
    // 0x8005379C: addiu       $s0, $s0, 0x144
    ctx->r16 = ADD32(ctx->r16, 0X144);
    // 0x800537A0: lw          $ra, 0x28($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X28);
    // 0x800537A4: lw          $s5, 0x24($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X24);
    // 0x800537A8: lw          $s4, 0x20($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X20);
    // 0x800537AC: lw          $s3, 0x1C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X1C);
    // 0x800537B0: lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X18);
    // 0x800537B4: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x800537B8: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x800537BC: jr          $ra
    // 0x800537C0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x800537C0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_800537C4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800537C4: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x800537C8: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800537CC: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x800537D0: sdc1        $f22, 0x30($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X30, ctx->r29);
    // 0x800537D4: sdc1        $f20, 0x28($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X28, ctx->r29);
    // 0x800537D8: lwc1        $f0, 0x0($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0X0);
    // 0x800537DC: lwc1        $f2, 0x0($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X0);
    // 0x800537E0: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x800537E4: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    // 0x800537E8: lwc1        $f0, 0x4($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0X4);
    // 0x800537EC: lwc1        $f2, 0x4($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X4);
    // 0x800537F0: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x800537F4: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    // 0x800537F8: lwc1        $f0, 0x8($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0X8);
    // 0x800537FC: lwc1        $f2, 0x8($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X8);
    // 0x80053800: addu        $s0, $a2, $zero
    ctx->r16 = ADD32(ctx->r6, 0);
    // 0x80053804: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x80053808: mtc1        $a3, $f22
    ctx->f22.u32l = ctx->r7;
    // 0x8005380C: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    // 0x80053810: jal         0x8001CF2C
    // 0x80053814: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    func_8001CF2C(rdram, ctx);
        goto after_0;
    // 0x80053814: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    after_0:
    // 0x80053818: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8005381C: lwc1        $f2, -0x5438($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X5438);
    // 0x80053820: mov.s       $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    ctx->f6.fl = ctx->f0.fl;
    // 0x80053824: c.lt.s      $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f2.fl < ctx->f6.fl;
    // 0x80053828: nop

    // 0x8005382C: bc1f        L_80053894
    if (!c1cs) {
        // 0x80053830: nop
    
            goto L_80053894;
    }
    // 0x80053830: nop

    // 0x80053834: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80053838: lwc1        $f0, -0x5434($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X5434);
    // 0x8005383C: lwc1        $f4, 0x10($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X10);
    // 0x80053840: div.s       $f0, $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f6.fl);
    // 0x80053844: mul.s       $f4, $f0, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x80053848: lwc1        $f12, 0x14($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X14);
    // 0x8005384C: mul.s       $f12, $f0, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = MUL_S(ctx->f0.fl, ctx->f12.fl);
    // 0x80053850: lwc1        $f2, 0x18($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X18);
    // 0x80053854: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x80053858: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8005385C: lwc1        $f20, -0x5430($at)
    ctx->f20.u32l = MEM_W(ctx->r1, -0X5430);
    // 0x80053860: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x80053864: swc1        $f12, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f12.u32l;
    // 0x80053868: jal         0x8001C400
    // 0x8005386C: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    func_8001C400(rdram, ctx);
        goto after_1;
    // 0x8005386C: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    after_1:
    // 0x80053870: mul.s       $f0, $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f20.fl);
    // 0x80053874: swc1        $f22, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f22.u32l;
    // 0x80053878: swc1        $f0, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f0.u32l;
    // 0x8005387C: lwc1        $f12, 0x10($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X10);
    // 0x80053880: lwc1        $f14, 0x18($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X18);
    // 0x80053884: jal         0x8001C5F4
    // 0x80053888: neg.s       $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = -ctx->f12.fl;
    func_8001C5F4(rdram, ctx);
        goto after_2;
    // 0x80053888: neg.s       $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = -ctx->f12.fl;
    after_2:
    // 0x8005388C: mul.s       $f0, $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f20.fl);
    // 0x80053890: swc1        $f0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f0.u32l;
L_80053894:
    // 0x80053894: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80053898: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8005389C: ldc1        $f22, 0x30($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X30);
    // 0x800538A0: ldc1        $f20, 0x28($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X28);
    // 0x800538A4: jr          $ra
    // 0x800538A8: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x800538A8: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void fake_func_800538AC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
;}
RECOMP_FUNC void func_800538B0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800538B0: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x800538B4: sw          $fp, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r30;
    // 0x800538B8: addu        $fp, $a2, $zero
    ctx->r30 = ADD32(ctx->r6, 0);
    // 0x800538BC: sw          $a1, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r5;
    // 0x800538C0: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x800538C4: ori         $a2, $zero, 0xFFFF
    ctx->r6 = 0 | 0XFFFF;
    // 0x800538C8: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800538CC: sw          $a0, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r4;
    // 0x800538D0: addiu       $a0, $v0, 0x7AB0
    ctx->r4 = ADD32(ctx->r2, 0X7AB0);
    // 0x800538D4: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800538D8: addiu       $v1, $v0, 0x7AD0
    ctx->r3 = ADD32(ctx->r2, 0X7AD0);
    // 0x800538DC: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x800538E0: sw          $s7, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r23;
    // 0x800538E4: sw          $s6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r22;
    // 0x800538E8: sw          $s5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r21;
    // 0x800538EC: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x800538F0: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x800538F4: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x800538F8: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x800538FC: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80053900: sdc1        $f24, 0x58($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X58, ctx->r29);
    // 0x80053904: sdc1        $f22, 0x50($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X50, ctx->r29);
    // 0x80053908: sdc1        $f20, 0x48($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X48, ctx->r29);
L_8005390C:
    // 0x8005390C: sh          $a2, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r6;
    // 0x80053910: sh          $a2, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r6;
    // 0x80053914: addiu       $a0, $a0, 0x2
    ctx->r4 = ADD32(ctx->r4, 0X2);
    // 0x80053918: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x8005391C: slti        $v0, $a1, 0x10
    ctx->r2 = SIGNED(ctx->r5) < 0X10 ? 1 : 0;
    // 0x80053920: bne         $v0, $zero, L_8005390C
    if (ctx->r2 != 0) {
        // 0x80053924: addiu       $v1, $v1, 0x2
        ctx->r3 = ADD32(ctx->r3, 0X2);
            goto L_8005390C;
    }
    // 0x80053924: addiu       $v1, $v1, 0x2
    ctx->r3 = ADD32(ctx->r3, 0X2);
    // 0x80053928: lw          $a3, 0x60($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X60);
    // 0x8005392C: lw          $v0, 0x20($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X20);
    // 0x80053930: lw          $s6, 0xC($v0)
    ctx->r22 = MEM_W(ctx->r2, 0XC);
    // 0x80053934: lw          $s1, 0x8($v0)
    ctx->r17 = MEM_W(ctx->r2, 0X8);
    // 0x80053938: blez        $s6, L_80053BC8
    if (SIGNED(ctx->r22) <= 0) {
        // 0x8005393C: nop
    
            goto L_80053BC8;
    }
    // 0x8005393C: nop

L_80053940:
    // 0x80053940: lw          $v1, 0x4($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X4);
    // 0x80053944: addiu       $s3, $zero, 0x2
    ctx->r19 = ADD32(0, 0X2);
    // 0x80053948: andi        $v0, $v1, 0xFC0
    ctx->r2 = ctx->r3 & 0XFC0;
    // 0x8005394C: srl         $v0, $v0, 4
    ctx->r2 = S32(U32(ctx->r2) >> 4);
    // 0x80053950: addu        $s5, $s1, $v0
    ctx->r21 = ADD32(ctx->r17, ctx->r2);
    // 0x80053954: srl         $v0, $v1, 16
    ctx->r2 = S32(U32(ctx->r3) >> 16);
    // 0x80053958: andi        $v0, $v0, 0xFC
    ctx->r2 = ctx->r2 & 0XFC;
    // 0x8005395C: addu        $s4, $s1, $v0
    ctx->r20 = ADD32(ctx->r17, ctx->r2);
    // 0x80053960: andi        $v1, $v1, 0x3F
    ctx->r3 = ctx->r3 & 0X3F;
    // 0x80053964: sllv        $v1, $v1, $s3
    ctx->r3 = S32(ctx->r3 << (ctx->r19 & 31));
    // 0x80053968: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x8005396C: andi        $v0, $v0, 0x8
    ctx->r2 = ctx->r2 & 0X8;
    // 0x80053970: beq         $v0, $zero, L_8005397C
    if (ctx->r2 == 0) {
        // 0x80053974: addu        $s2, $s1, $v1
        ctx->r18 = ADD32(ctx->r17, ctx->r3);
            goto L_8005397C;
    }
    // 0x80053974: addu        $s2, $s1, $v1
    ctx->r18 = ADD32(ctx->r17, ctx->r3);
    // 0x80053978: addiu       $s3, $zero, 0x3
    ctx->r19 = ADD32(0, 0X3);
L_8005397C:
    // 0x8005397C: bltz        $s3, L_80053BB0
    if (SIGNED(ctx->r19) < 0) {
        // 0x80053980: nop
    
            goto L_80053BB0;
    }
    // 0x80053980: nop

    // 0x80053984: lui         $s7, 0x8000
    ctx->r23 = S32(0X8000 << 16);
    // 0x80053988: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8005398C: lwc1        $f22, -0x5420($at)
    ctx->f22.u32l = MEM_W(ctx->r1, -0X5420);
    // 0x80053990: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80053994: lwc1        $f24, -0x541C($at)
    ctx->f24.u32l = MEM_W(ctx->r1, -0X541C);
    // 0x80053998: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8005399C: lwc1        $f20, -0x5418($at)
    ctx->f20.u32l = MEM_W(ctx->r1, -0X5418);
L_800539A0:
    // 0x800539A0: lhu         $a1, 0x0($s5)
    ctx->r5 = MEM_HU(ctx->r21, 0X0);
    // 0x800539A4: addiu       $s5, $s5, 0x2
    ctx->r21 = ADD32(ctx->r21, 0X2);
    // 0x800539A8: lui         $a3, 0x8013
    ctx->r7 = S32(0X8013 << 16);
    // 0x800539AC: addiu       $a3, $a3, 0x7AB0
    ctx->r7 = ADD32(ctx->r7, 0X7AB0);
    // 0x800539B0: andi        $v0, $a1, 0xF
    ctx->r2 = ctx->r5 & 0XF;
    // 0x800539B4: sll         $v1, $v0, 1
    ctx->r3 = S32(ctx->r2 << 1);
    // 0x800539B8: addu        $v0, $v1, $v0
    ctx->r2 = ADD32(ctx->r3, ctx->r2);
    // 0x800539BC: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800539C0: addu        $a0, $v1, $a3
    ctx->r4 = ADD32(ctx->r3, ctx->r7);
    // 0x800539C4: lui         $a3, 0x8013
    ctx->r7 = S32(0X8013 << 16);
    // 0x800539C8: addiu       $a3, $a3, 0x7AF0
    ctx->r7 = ADD32(ctx->r7, 0X7AF0);
    // 0x800539CC: lhu         $v1, 0x0($a0)
    ctx->r3 = MEM_HU(ctx->r4, 0X0);
    // 0x800539D0: beq         $v1, $a1, L_80053A34
    if (ctx->r3 == ctx->r5) {
        // 0x800539D4: addu        $s0, $v0, $a3
        ctx->r16 = ADD32(ctx->r2, ctx->r7);
            goto L_80053A34;
    }
    // 0x800539D4: addu        $s0, $v0, $a3
    ctx->r16 = ADD32(ctx->r2, ctx->r7);
    // 0x800539D8: sh          $a1, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r5;
    // 0x800539DC: lw          $a3, 0x60($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X60);
    // 0x800539E0: lw          $v1, 0x28($a3)
    ctx->r3 = MEM_W(ctx->r7, 0X28);
    // 0x800539E4: sll         $v0, $a1, 3
    ctx->r2 = S32(ctx->r5 << 3);
    // 0x800539E8: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x800539EC: lh          $v0, 0x0($v1)
    ctx->r2 = MEM_H(ctx->r3, 0X0);
    // 0x800539F0: addiu       $a1, $sp, 0x10
    ctx->r5 = ADD32(ctx->r29, 0X10);
    // 0x800539F4: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x800539F8: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x800539FC: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    // 0x80053A00: lh          $v0, 0x2($v1)
    ctx->r2 = MEM_H(ctx->r3, 0X2);
    // 0x80053A04: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    // 0x80053A08: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x80053A0C: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x80053A10: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    // 0x80053A14: lh          $v0, 0x4($v1)
    ctx->r2 = MEM_H(ctx->r3, 0X4);
    // 0x80053A18: lw          $a0, 0x64($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X64);
    // 0x80053A1C: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x80053A20: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x80053A24: jal         0x800194A4
    // 0x80053A28: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    func_800194A4(rdram, ctx);
        goto after_0;
    // 0x80053A28: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    after_0:
    // 0x80053A2C: jal         0x8001CF58
    // 0x80053A30: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    normalize_vector(rdram, ctx);
        goto after_1;
    // 0x80053A30: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_1:
L_80053A34:
    // 0x80053A34: lhu         $a1, 0x0($s4)
    ctx->r5 = MEM_HU(ctx->r20, 0X0);
    // 0x80053A38: addiu       $s4, $s4, 0x2
    ctx->r20 = ADD32(ctx->r20, 0X2);
    // 0x80053A3C: lui         $a3, 0x8013
    ctx->r7 = S32(0X8013 << 16);
    // 0x80053A40: addiu       $a3, $a3, 0x7AD0
    ctx->r7 = ADD32(ctx->r7, 0X7AD0);
    // 0x80053A44: andi        $v0, $a1, 0xF
    ctx->r2 = ctx->r5 & 0XF;
    // 0x80053A48: sll         $v1, $v0, 1
    ctx->r3 = S32(ctx->r2 << 1);
    // 0x80053A4C: addu        $v0, $v1, $v0
    ctx->r2 = ADD32(ctx->r3, ctx->r2);
    // 0x80053A50: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80053A54: addu        $a0, $v1, $a3
    ctx->r4 = ADD32(ctx->r3, ctx->r7);
    // 0x80053A58: lui         $a3, 0x8013
    ctx->r7 = S32(0X8013 << 16);
    // 0x80053A5C: addiu       $a3, $a3, 0x7BB0
    ctx->r7 = ADD32(ctx->r7, 0X7BB0);
    // 0x80053A60: lhu         $v1, 0x0($a0)
    ctx->r3 = MEM_HU(ctx->r4, 0X0);
    // 0x80053A64: beq         $v1, $a1, L_80053B04
    if (ctx->r3 == ctx->r5) {
        // 0x80053A68: addu        $s0, $v0, $a3
        ctx->r16 = ADD32(ctx->r2, ctx->r7);
            goto L_80053B04;
    }
    // 0x80053A68: addu        $s0, $v0, $a3
    ctx->r16 = ADD32(ctx->r2, ctx->r7);
    // 0x80053A6C: sh          $a1, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r5;
    // 0x80053A70: lw          $a3, 0x60($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X60);
    // 0x80053A74: lw          $v1, 0x24($a3)
    ctx->r3 = MEM_W(ctx->r7, 0X24);
    // 0x80053A78: sll         $v0, $a1, 3
    ctx->r2 = S32(ctx->r5 << 3);
    // 0x80053A7C: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x80053A80: lh          $v0, 0x0($v1)
    ctx->r2 = MEM_H(ctx->r3, 0X0);
    // 0x80053A84: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x80053A88: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x80053A8C: mul.s       $f0, $f0, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f22.fl);
    // 0x80053A90: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    // 0x80053A94: lh          $v0, 0x2($v1)
    ctx->r2 = MEM_H(ctx->r3, 0X2);
    // 0x80053A98: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x80053A9C: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x80053AA0: mul.s       $f0, $f0, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f22.fl);
    // 0x80053AA4: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    // 0x80053AA8: lh          $v0, 0x4($v1)
    ctx->r2 = MEM_H(ctx->r3, 0X4);
    // 0x80053AAC: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x80053AB0: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x80053AB4: mul.s       $f0, $f0, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f22.fl);
    // 0x80053AB8: addiu       $a1, $sp, 0x10
    ctx->r5 = ADD32(ctx->r29, 0X10);
    // 0x80053ABC: lw          $a0, 0x64($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X64);
    // 0x80053AC0: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    // 0x80053AC4: jal         0x800193E8
    // 0x80053AC8: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    func_800193E8(rdram, ctx);
        goto after_2;
    // 0x80053AC8: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    after_2:
    // 0x80053ACC: lwc1        $f0, 0x0($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X0);
    // 0x80053AD0: lwc1        $f2, 0x0($fp)
    ctx->f2.u32l = MEM_W(ctx->r30, 0X0);
    // 0x80053AD4: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x80053AD8: swc1        $f0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f0.u32l;
    // 0x80053ADC: lwc1        $f0, 0x4($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X4);
    // 0x80053AE0: lwc1        $f2, 0x4($fp)
    ctx->f2.u32l = MEM_W(ctx->r30, 0X4);
    // 0x80053AE4: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x80053AE8: lwc1        $f2, 0x8($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X8);
    // 0x80053AEC: swc1        $f0, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f0.u32l;
    // 0x80053AF0: lwc1        $f0, 0x8($fp)
    ctx->f0.u32l = MEM_W(ctx->r30, 0X8);
    // 0x80053AF4: sub.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl - ctx->f0.fl;
    // 0x80053AF8: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x80053AFC: jal         0x8001CF58
    // 0x80053B00: swc1        $f2, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f2.u32l;
    normalize_vector(rdram, ctx);
        goto after_3;
    // 0x80053B00: swc1        $f2, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f2.u32l;
    after_3:
L_80053B04:
    // 0x80053B04: lwc1        $f0, 0x0($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X0);
    // 0x80053B08: sub.s       $f0, $f24, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f24.fl - ctx->f0.fl;
    // 0x80053B0C: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80053B10: lwc1        $f2, -0x5414($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X5414);
    // 0x80053B14: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x80053B18: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80053B1C: lwc1        $f2, -0x5410($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X5410);
    // 0x80053B20: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x80053B24: c.le.s      $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f20.fl <= ctx->f0.fl;
    // 0x80053B28: nop

    // 0x80053B2C: bc1tl       L_80053B44
    if (c1cs) {
        // 0x80053B30: sub.s       $f0, $f0, $f20
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f20.fl;
            goto L_80053B44;
    }
    goto skip_0;
    // 0x80053B30: sub.s       $f0, $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f20.fl;
    skip_0:
    // 0x80053B34: trunc.w.s   $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    ctx->f4.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x80053B38: mfc1        $v0, $f4
    ctx->r2 = (int32_t)ctx->f4.u32l;
    // 0x80053B3C: j           L_80053B54
    // 0x80053B40: sh          $v0, 0x0($s2)
    MEM_H(0X0, ctx->r18) = ctx->r2;
        goto L_80053B54;
    // 0x80053B40: sh          $v0, 0x0($s2)
    MEM_H(0X0, ctx->r18) = ctx->r2;
L_80053B44:
    // 0x80053B44: trunc.w.s   $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    ctx->f4.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x80053B48: mfc1        $v0, $f4
    ctx->r2 = (int32_t)ctx->f4.u32l;
    // 0x80053B4C: or          $v0, $v0, $s7
    ctx->r2 = ctx->r2 | ctx->r23;
    // 0x80053B50: sh          $v0, 0x0($s2)
    MEM_H(0X0, ctx->r18) = ctx->r2;
L_80053B54:
    // 0x80053B54: lwc1        $f0, 0x8($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X8);
    // 0x80053B58: sub.s       $f0, $f24, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f24.fl - ctx->f0.fl;
    // 0x80053B5C: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80053B60: lwc1        $f2, -0x540C($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X540C);
    // 0x80053B64: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x80053B68: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80053B6C: lwc1        $f2, -0x5408($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X5408);
    // 0x80053B70: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x80053B74: c.le.s      $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f20.fl <= ctx->f0.fl;
    // 0x80053B78: nop

    // 0x80053B7C: bc1tl       L_80053B94
    if (c1cs) {
        // 0x80053B80: sub.s       $f0, $f0, $f20
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f20.fl;
            goto L_80053B94;
    }
    goto skip_1;
    // 0x80053B80: sub.s       $f0, $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f20.fl;
    skip_1:
    // 0x80053B84: trunc.w.s   $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    ctx->f4.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x80053B88: mfc1        $v0, $f4
    ctx->r2 = (int32_t)ctx->f4.u32l;
    // 0x80053B8C: j           L_80053BA4
    // 0x80053B90: sh          $v0, 0x2($s2)
    MEM_H(0X2, ctx->r18) = ctx->r2;
        goto L_80053BA4;
    // 0x80053B90: sh          $v0, 0x2($s2)
    MEM_H(0X2, ctx->r18) = ctx->r2;
L_80053B94:
    // 0x80053B94: trunc.w.s   $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    ctx->f4.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x80053B98: mfc1        $v0, $f4
    ctx->r2 = (int32_t)ctx->f4.u32l;
    // 0x80053B9C: or          $v0, $v0, $s7
    ctx->r2 = ctx->r2 | ctx->r23;
    // 0x80053BA0: sh          $v0, 0x2($s2)
    MEM_H(0X2, ctx->r18) = ctx->r2;
L_80053BA4:
    // 0x80053BA4: addiu       $s3, $s3, -0x1
    ctx->r19 = ADD32(ctx->r19, -0X1);
    // 0x80053BA8: bgez        $s3, L_800539A0
    if (SIGNED(ctx->r19) >= 0) {
        // 0x80053BAC: addiu       $s2, $s2, 0x4
        ctx->r18 = ADD32(ctx->r18, 0X4);
            goto L_800539A0;
    }
    // 0x80053BAC: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
L_80053BB0:
    // 0x80053BB0: lw          $v0, 0x4($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X4);
    // 0x80053BB4: addiu       $s6, $s6, -0x1
    ctx->r22 = ADD32(ctx->r22, -0X1);
    // 0x80053BB8: srl         $v0, $v0, 22
    ctx->r2 = S32(U32(ctx->r2) >> 22);
    // 0x80053BBC: andi        $v0, $v0, 0xFC
    ctx->r2 = ctx->r2 & 0XFC;
    // 0x80053BC0: bgtz        $s6, L_80053940
    if (SIGNED(ctx->r22) > 0) {
        // 0x80053BC4: addu        $s1, $s1, $v0
        ctx->r17 = ADD32(ctx->r17, ctx->r2);
            goto L_80053940;
    }
    // 0x80053BC4: addu        $s1, $s1, $v0
    ctx->r17 = ADD32(ctx->r17, ctx->r2);
L_80053BC8:
    // 0x80053BC8: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x80053BCC: lw          $fp, 0x40($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X40);
    // 0x80053BD0: lw          $s7, 0x3C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X3C);
    // 0x80053BD4: lw          $s6, 0x38($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X38);
    // 0x80053BD8: lw          $s5, 0x34($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X34);
    // 0x80053BDC: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x80053BE0: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x80053BE4: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x80053BE8: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x80053BEC: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80053BF0: ldc1        $f24, 0x58($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X58);
    // 0x80053BF4: ldc1        $f22, 0x50($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X50);
    // 0x80053BF8: ldc1        $f20, 0x48($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X48);
    // 0x80053BFC: jr          $ra
    // 0x80053C00: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    return;
    // 0x80053C00: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
;}
RECOMP_FUNC void func_80053C04(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80053C04: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80053C08: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x80053C0C: addu        $s4, $a0, $zero
    ctx->r20 = ADD32(ctx->r4, 0);
    // 0x80053C10: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x80053C14: addu        $s3, $a1, $zero
    ctx->r19 = ADD32(ctx->r5, 0);
    // 0x80053C18: lui         $a1, 0x8004
    ctx->r5 = S32(0X8004 << 16);
    // 0x80053C1C: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x80053C20: sw          $s6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r22;
    // 0x80053C24: sw          $s5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r21;
    // 0x80053C28: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x80053C2C: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x80053C30: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80053C34: lw          $s0, 0x0($s4)
    ctx->r16 = MEM_W(ctx->r20, 0X0);
    // 0x80053C38: addiu       $a1, $a1, -0x5404
    ctx->r5 = ADD32(ctx->r5, -0X5404);
    // 0x80053C3C: jal         0x800076F8
    // 0x80053C40: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    rs_strcmp(rdram, ctx);
        goto after_0;
    // 0x80053C40: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_0:
    // 0x80053C44: beq         $v0, $zero, L_80053D2C
    if (ctx->r2 == 0) {
        // 0x80053C48: addu        $a0, $s0, $zero
        ctx->r4 = ADD32(ctx->r16, 0);
            goto L_80053D2C;
    }
    // 0x80053C48: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x80053C4C: lui         $a1, 0x8004
    ctx->r5 = S32(0X8004 << 16);
    // 0x80053C50: jal         0x800076F8
    // 0x80053C54: addiu       $a1, $a1, -0x53FC
    ctx->r5 = ADD32(ctx->r5, -0X53FC);
    rs_strcmp(rdram, ctx);
        goto after_1;
    // 0x80053C54: addiu       $a1, $a1, -0x53FC
    ctx->r5 = ADD32(ctx->r5, -0X53FC);
    after_1:
    // 0x80053C58: beq         $v0, $zero, L_80053D24
    if (ctx->r2 == 0) {
        // 0x80053C5C: addu        $a0, $s0, $zero
        ctx->r4 = ADD32(ctx->r16, 0);
            goto L_80053D24;
    }
    // 0x80053C5C: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x80053C60: lui         $a1, 0x8004
    ctx->r5 = S32(0X8004 << 16);
    // 0x80053C64: jal         0x800076F8
    // 0x80053C68: addiu       $a1, $a1, -0x53F4
    ctx->r5 = ADD32(ctx->r5, -0X53F4);
    rs_strcmp(rdram, ctx);
        goto after_2;
    // 0x80053C68: addiu       $a1, $a1, -0x53F4
    ctx->r5 = ADD32(ctx->r5, -0X53F4);
    after_2:
    // 0x80053C6C: beq         $v0, $zero, L_80053D1C
    if (ctx->r2 == 0) {
        // 0x80053C70: addu        $a0, $s0, $zero
        ctx->r4 = ADD32(ctx->r16, 0);
            goto L_80053D1C;
    }
    // 0x80053C70: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x80053C74: lui         $a1, 0x8004
    ctx->r5 = S32(0X8004 << 16);
    // 0x80053C78: jal         0x800076F8
    // 0x80053C7C: addiu       $a1, $a1, -0x53EC
    ctx->r5 = ADD32(ctx->r5, -0X53EC);
    rs_strcmp(rdram, ctx);
        goto after_3;
    // 0x80053C7C: addiu       $a1, $a1, -0x53EC
    ctx->r5 = ADD32(ctx->r5, -0X53EC);
    after_3:
    // 0x80053C80: beq         $v0, $zero, L_80053D14
    if (ctx->r2 == 0) {
        // 0x80053C84: addu        $a0, $s0, $zero
        ctx->r4 = ADD32(ctx->r16, 0);
            goto L_80053D14;
    }
    // 0x80053C84: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x80053C88: lui         $a1, 0x8004
    ctx->r5 = S32(0X8004 << 16);
    // 0x80053C8C: jal         0x800076F8
    // 0x80053C90: addiu       $a1, $a1, -0x53E4
    ctx->r5 = ADD32(ctx->r5, -0X53E4);
    rs_strcmp(rdram, ctx);
        goto after_4;
    // 0x80053C90: addiu       $a1, $a1, -0x53E4
    ctx->r5 = ADD32(ctx->r5, -0X53E4);
    after_4:
    // 0x80053C94: beq         $v0, $zero, L_80053D0C
    if (ctx->r2 == 0) {
        // 0x80053C98: addu        $a0, $s0, $zero
        ctx->r4 = ADD32(ctx->r16, 0);
            goto L_80053D0C;
    }
    // 0x80053C98: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x80053C9C: lui         $a1, 0x8004
    ctx->r5 = S32(0X8004 << 16);
    // 0x80053CA0: jal         0x800076F8
    // 0x80053CA4: addiu       $a1, $a1, -0x53D8
    ctx->r5 = ADD32(ctx->r5, -0X53D8);
    rs_strcmp(rdram, ctx);
        goto after_5;
    // 0x80053CA4: addiu       $a1, $a1, -0x53D8
    ctx->r5 = ADD32(ctx->r5, -0X53D8);
    after_5:
    // 0x80053CA8: beq         $v0, $zero, L_80053D04
    if (ctx->r2 == 0) {
        // 0x80053CAC: addu        $a0, $s0, $zero
        ctx->r4 = ADD32(ctx->r16, 0);
            goto L_80053D04;
    }
    // 0x80053CAC: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x80053CB0: lui         $a1, 0x8004
    ctx->r5 = S32(0X8004 << 16);
    // 0x80053CB4: jal         0x800076F8
    // 0x80053CB8: addiu       $a1, $a1, -0x53D0
    ctx->r5 = ADD32(ctx->r5, -0X53D0);
    rs_strcmp(rdram, ctx);
        goto after_6;
    // 0x80053CB8: addiu       $a1, $a1, -0x53D0
    ctx->r5 = ADD32(ctx->r5, -0X53D0);
    after_6:
    // 0x80053CBC: beq         $v0, $zero, L_80053CFC
    if (ctx->r2 == 0) {
        // 0x80053CC0: addu        $a0, $s0, $zero
        ctx->r4 = ADD32(ctx->r16, 0);
            goto L_80053CFC;
    }
    // 0x80053CC0: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x80053CC4: lui         $a1, 0x8004
    ctx->r5 = S32(0X8004 << 16);
    // 0x80053CC8: jal         0x800076F8
    // 0x80053CCC: addiu       $a1, $a1, -0x53C4
    ctx->r5 = ADD32(ctx->r5, -0X53C4);
    rs_strcmp(rdram, ctx);
        goto after_7;
    // 0x80053CCC: addiu       $a1, $a1, -0x53C4
    ctx->r5 = ADD32(ctx->r5, -0X53C4);
    after_7:
    // 0x80053CD0: beq         $v0, $zero, L_80053CF4
    if (ctx->r2 == 0) {
        // 0x80053CD4: addu        $a0, $s0, $zero
        ctx->r4 = ADD32(ctx->r16, 0);
            goto L_80053CF4;
    }
    // 0x80053CD4: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x80053CD8: lui         $a1, 0x8004
    ctx->r5 = S32(0X8004 << 16);
    // 0x80053CDC: jal         0x800076F8
    // 0x80053CE0: addiu       $a1, $a1, -0x53BC
    ctx->r5 = ADD32(ctx->r5, -0X53BC);
    rs_strcmp(rdram, ctx);
        goto after_8;
    // 0x80053CE0: addiu       $a1, $a1, -0x53BC
    ctx->r5 = ADD32(ctx->r5, -0X53BC);
    after_8:
    // 0x80053CE4: bne         $v0, $zero, L_80053D30
    if (ctx->r2 != 0) {
        // 0x80053CE8: addiu       $v1, $zero, -0x1
        ctx->r3 = ADD32(0, -0X1);
            goto L_80053D30;
    }
    // 0x80053CE8: addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
    // 0x80053CEC: j           L_80053D30
    // 0x80053CF0: addiu       $v1, $zero, 0x7
    ctx->r3 = ADD32(0, 0X7);
        goto L_80053D30;
    // 0x80053CF0: addiu       $v1, $zero, 0x7
    ctx->r3 = ADD32(0, 0X7);
L_80053CF4:
    // 0x80053CF4: j           L_80053D30
    // 0x80053CF8: addiu       $v1, $zero, 0x8
    ctx->r3 = ADD32(0, 0X8);
        goto L_80053D30;
    // 0x80053CF8: addiu       $v1, $zero, 0x8
    ctx->r3 = ADD32(0, 0X8);
L_80053CFC:
    // 0x80053CFC: j           L_80053D30
    // 0x80053D00: addiu       $v1, $zero, 0x6
    ctx->r3 = ADD32(0, 0X6);
        goto L_80053D30;
    // 0x80053D00: addiu       $v1, $zero, 0x6
    ctx->r3 = ADD32(0, 0X6);
L_80053D04:
    // 0x80053D04: j           L_80053D30
    // 0x80053D08: addiu       $v1, $zero, 0x5
    ctx->r3 = ADD32(0, 0X5);
        goto L_80053D30;
    // 0x80053D08: addiu       $v1, $zero, 0x5
    ctx->r3 = ADD32(0, 0X5);
L_80053D0C:
    // 0x80053D0C: j           L_80053D30
    // 0x80053D10: addiu       $v1, $zero, 0x4
    ctx->r3 = ADD32(0, 0X4);
        goto L_80053D30;
    // 0x80053D10: addiu       $v1, $zero, 0x4
    ctx->r3 = ADD32(0, 0X4);
L_80053D14:
    // 0x80053D14: j           L_80053D30
    // 0x80053D18: addiu       $v1, $zero, 0x3
    ctx->r3 = ADD32(0, 0X3);
        goto L_80053D30;
    // 0x80053D18: addiu       $v1, $zero, 0x3
    ctx->r3 = ADD32(0, 0X3);
L_80053D1C:
    // 0x80053D1C: j           L_80053D30
    // 0x80053D20: addiu       $v1, $zero, 0x2
    ctx->r3 = ADD32(0, 0X2);
        goto L_80053D30;
    // 0x80053D20: addiu       $v1, $zero, 0x2
    ctx->r3 = ADD32(0, 0X2);
L_80053D24:
    // 0x80053D24: j           L_80053D30
    // 0x80053D28: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
        goto L_80053D30;
    // 0x80053D28: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_80053D2C:
    // 0x80053D2C: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
L_80053D30:
    // 0x80053D30: sll         $v0, $v1, 16
    ctx->r2 = S32(ctx->r3 << 16);
    // 0x80053D34: bltz        $v0, L_80053F54
    if (SIGNED(ctx->r2) < 0) {
        // 0x80053D38: sh          $v1, 0x2($s3)
        MEM_H(0X2, ctx->r19) = ctx->r3;
            goto L_80053F54;
    }
    // 0x80053D38: sh          $v1, 0x2($s3)
    MEM_H(0X2, ctx->r19) = ctx->r3;
    // 0x80053D3C: addu        $a0, $s4, $zero
    ctx->r4 = ADD32(ctx->r20, 0);
    // 0x80053D40: lui         $a1, 0x8004
    ctx->r5 = S32(0X8004 << 16);
    // 0x80053D44: addiu       $a1, $a1, -0x53B8
    ctx->r5 = ADD32(ctx->r5, -0X53B8);
    // 0x80053D48: jal         0x800594F8
    // 0x80053D4C: sw          $s4, 0x4($s3)
    MEM_W(0X4, ctx->r19) = ctx->r20;
    func_800594F8(rdram, ctx);
        goto after_9;
    // 0x80053D4C: sw          $s4, 0x4($s3)
    MEM_W(0X4, ctx->r19) = ctx->r20;
    after_9:
    // 0x80053D50: beq         $v0, $zero, L_80053D84
    if (ctx->r2 == 0) {
        // 0x80053D54: sw          $v0, 0x8($s3)
        MEM_W(0X8, ctx->r19) = ctx->r2;
            goto L_80053D84;
    }
    // 0x80053D54: sw          $v0, 0x8($s3)
    MEM_W(0X8, ctx->r19) = ctx->r2;
    // 0x80053D58: lw          $a0, 0x0($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X0);
    // 0x80053D5C: lw          $v0, 0xC($a0)
    ctx->r2 = MEM_W(ctx->r4, 0XC);
    // 0x80053D60: addiu       $v1, $zero, -0x9
    ctx->r3 = ADD32(0, -0X9);
    // 0x80053D64: and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // 0x80053D68: sw          $v0, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r2;
    // 0x80053D6C: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80053D70: lw          $v1, 0x8($s3)
    ctx->r3 = MEM_W(ctx->r19, 0X8);
    // 0x80053D74: lhu         $a2, 0x7C70($v0)
    ctx->r6 = MEM_HU(ctx->r2, 0X7C70);
    // 0x80053D78: lw          $a0, 0x0($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X0);
    // 0x80053D7C: jal         0x800595A0
    // 0x80053D80: ori         $a1, $zero, 0xFFFF
    ctx->r5 = 0 | 0XFFFF;
    func_800595A0(rdram, ctx);
        goto after_10;
    // 0x80053D80: ori         $a1, $zero, 0xFFFF
    ctx->r5 = 0 | 0XFFFF;
    after_10:
L_80053D84:
    // 0x80053D84: addu        $s2, $zero, $zero
    ctx->r18 = ADD32(0, 0);
    // 0x80053D88: lui         $s6, 0x8004
    ctx->r22 = S32(0X8004 << 16);
    // 0x80053D8C: addiu       $s5, $zero, -0x9
    ctx->r21 = ADD32(0, -0X9);
    // 0x80053D90: addu        $s1, $s3, $zero
    ctx->r17 = ADD32(ctx->r19, 0);
    // 0x80053D94: addu        $s0, $s3, $zero
    ctx->r16 = ADD32(ctx->r19, 0);
    // 0x80053D98: sw          $zero, 0xC($s3)
    MEM_W(0XC, ctx->r19) = 0;
    // 0x80053D9C: sw          $zero, 0x10($s3)
    MEM_W(0X10, ctx->r19) = 0;
L_80053DA0:
    // 0x80053DA0: addiu       $a0, $zero, 0x80
    ctx->r4 = ADD32(0, 0X80);
    // 0x80053DA4: jal         0x80001ACC
    // 0x80053DA8: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    rs_malloc(rdram, ctx);
        goto after_11;
    // 0x80053DA8: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    after_11:
    // 0x80053DAC: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    // 0x80053DB0: addiu       $a1, $s6, -0x53B0
    ctx->r5 = ADD32(ctx->r22, -0X53B0);
    // 0x80053DB4: addiu       $a2, $s2, 0x61
    ctx->r6 = ADD32(ctx->r18, 0X61);
    // 0x80053DB8: jal         0x80033CC4
    // 0x80053DBC: sw          $v0, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->r2;
    sprintf_recomp(rdram, ctx);
        goto after_12;
    // 0x80053DBC: sw          $v0, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->r2;
    after_12:
    // 0x80053DC0: addu        $a0, $s4, $zero
    ctx->r4 = ADD32(ctx->r20, 0);
    // 0x80053DC4: jal         0x800594F8
    // 0x80053DC8: addiu       $a1, $sp, 0x10
    ctx->r5 = ADD32(ctx->r29, 0X10);
    func_800594F8(rdram, ctx);
        goto after_13;
    // 0x80053DC8: addiu       $a1, $sp, 0x10
    ctx->r5 = ADD32(ctx->r29, 0X10);
    after_13:
    // 0x80053DCC: beq         $v0, $zero, L_80053DFC
    if (ctx->r2 == 0) {
        // 0x80053DD0: sw          $v0, 0x14($s0)
        MEM_W(0X14, ctx->r16) = ctx->r2;
            goto L_80053DFC;
    }
    // 0x80053DD0: sw          $v0, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->r2;
    // 0x80053DD4: lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X0);
    // 0x80053DD8: lw          $v0, 0xC($v1)
    ctx->r2 = MEM_W(ctx->r3, 0XC);
    // 0x80053DDC: and         $v0, $v0, $s5
    ctx->r2 = ctx->r2 & ctx->r21;
    // 0x80053DE0: sw          $v0, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r2;
    // 0x80053DE4: lw          $v0, 0x14($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X14);
    // 0x80053DE8: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x80053DEC: lw          $a0, 0x1C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X1C);
    // 0x80053DF0: lw          $a1, 0x24($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X24);
    // 0x80053DF4: jal         0x80018EF4
    // 0x80053DF8: addiu       $a2, $zero, 0x80
    ctx->r6 = ADD32(0, 0X80);
    zmemcpy(rdram, ctx);
        goto after_14;
    // 0x80053DF8: addiu       $a2, $zero, 0x80
    ctx->r6 = ADD32(0, 0X80);
    after_14:
L_80053DFC:
    // 0x80053DFC: sh          $zero, 0x24($s1)
    MEM_H(0X24, ctx->r17) = 0;
    // 0x80053E00: addiu       $s1, $s1, 0x2
    ctx->r17 = ADD32(ctx->r17, 0X2);
    // 0x80053E04: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x80053E08: slti        $v0, $s2, 0x2
    ctx->r2 = SIGNED(ctx->r18) < 0X2 ? 1 : 0;
    // 0x80053E0C: bne         $v0, $zero, L_80053DA0
    if (ctx->r2 != 0) {
        // 0x80053E10: addiu       $s0, $s0, 0x4
        ctx->r16 = ADD32(ctx->r16, 0X4);
            goto L_80053DA0;
    }
    // 0x80053E10: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x80053E14: lh          $v1, 0x2($s3)
    ctx->r3 = MEM_H(ctx->r19, 0X2);
    // 0x80053E18: sltiu       $v0, $v1, 0x9
    ctx->r2 = ctx->r3 < 0X9 ? 1 : 0;
    // 0x80053E1C: beq         $v0, $zero, L_80053F54
    if (ctx->r2 == 0) {
        // 0x80053E20: lui         $v0, 0x8004
        ctx->r2 = S32(0X8004 << 16);
            goto L_80053F54;
    }
    // 0x80053E20: lui         $v0, 0x8004
    ctx->r2 = S32(0X8004 << 16);
    // 0x80053E24: addiu       $v0, $v0, -0x5398
    ctx->r2 = ADD32(ctx->r2, -0X5398);
    // 0x80053E28: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x80053E2C: addu        $v1, $v1, $v0
    gpr jr_addend_80053E34 = ctx->r3;
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x80053E30: lw          $v0, 0x0($v1)
    ctx->r2 = ADD32(ctx->r3, 0X0);
    // 0x80053E34: jr          $v0
    // 0x80053E38: nop

    switch (jr_addend_80053E34 >> 2) {
        case 0: goto L_80053E3C; break;
        case 1: goto L_80053E54; break;
        case 2: goto L_80053E6C; break;
        case 3: goto L_80053E84; break;
        case 4: goto L_80053E9C; break;
        case 5: goto L_80053EB4; break;
        case 6: goto L_80053ECC; break;
        case 7: goto L_80053F3C; break;
        case 8: goto L_80053EE4; break;
        default: switch_error(__func__, 0x80053E34, 0x8003AC68);
    }
    // 0x80053E38: nop

L_80053E3C:
    // 0x80053E3C: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80053E40: lwc1        $f0, -0x5374($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X5374);
    // 0x80053E44: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80053E48: lwc1        $f2, -0x5370($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X5370);
    // 0x80053E4C: j           L_80053F50
    // 0x80053E50: swc1        $f0, 0x2C($s3)
    MEM_W(0X2C, ctx->r19) = ctx->f0.u32l;
        goto L_80053F50;
    // 0x80053E50: swc1        $f0, 0x2C($s3)
    MEM_W(0X2C, ctx->r19) = ctx->f0.u32l;
L_80053E54:
    // 0x80053E54: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80053E58: lwc1        $f0, -0x536C($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X536C);
    // 0x80053E5C: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80053E60: lwc1        $f2, -0x5368($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X5368);
    // 0x80053E64: j           L_80053F50
    // 0x80053E68: swc1        $f0, 0x2C($s3)
    MEM_W(0X2C, ctx->r19) = ctx->f0.u32l;
        goto L_80053F50;
    // 0x80053E68: swc1        $f0, 0x2C($s3)
    MEM_W(0X2C, ctx->r19) = ctx->f0.u32l;
L_80053E6C:
    // 0x80053E6C: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80053E70: lwc1        $f0, -0x5364($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X5364);
    // 0x80053E74: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80053E78: lwc1        $f2, -0x5360($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X5360);
    // 0x80053E7C: j           L_80053F50
    // 0x80053E80: swc1        $f0, 0x2C($s3)
    MEM_W(0X2C, ctx->r19) = ctx->f0.u32l;
        goto L_80053F50;
    // 0x80053E80: swc1        $f0, 0x2C($s3)
    MEM_W(0X2C, ctx->r19) = ctx->f0.u32l;
L_80053E84:
    // 0x80053E84: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80053E88: lwc1        $f0, -0x535C($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X535C);
    // 0x80053E8C: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80053E90: lwc1        $f2, -0x5358($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X5358);
    // 0x80053E94: j           L_80053F50
    // 0x80053E98: swc1        $f0, 0x2C($s3)
    MEM_W(0X2C, ctx->r19) = ctx->f0.u32l;
        goto L_80053F50;
    // 0x80053E98: swc1        $f0, 0x2C($s3)
    MEM_W(0X2C, ctx->r19) = ctx->f0.u32l;
L_80053E9C:
    // 0x80053E9C: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80053EA0: lwc1        $f0, -0x5354($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X5354);
    // 0x80053EA4: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80053EA8: lwc1        $f2, -0x5350($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X5350);
    // 0x80053EAC: j           L_80053F50
    // 0x80053EB0: swc1        $f0, 0x2C($s3)
    MEM_W(0X2C, ctx->r19) = ctx->f0.u32l;
        goto L_80053F50;
    // 0x80053EB0: swc1        $f0, 0x2C($s3)
    MEM_W(0X2C, ctx->r19) = ctx->f0.u32l;
L_80053EB4:
    // 0x80053EB4: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80053EB8: lwc1        $f0, -0x534C($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X534C);
    // 0x80053EBC: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80053EC0: lwc1        $f2, -0x5348($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X5348);
    // 0x80053EC4: j           L_80053F50
    // 0x80053EC8: swc1        $f0, 0x2C($s3)
    MEM_W(0X2C, ctx->r19) = ctx->f0.u32l;
        goto L_80053F50;
    // 0x80053EC8: swc1        $f0, 0x2C($s3)
    MEM_W(0X2C, ctx->r19) = ctx->f0.u32l;
L_80053ECC:
    // 0x80053ECC: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80053ED0: lwc1        $f0, -0x5344($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X5344);
    // 0x80053ED4: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80053ED8: lwc1        $f2, -0x5340($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X5340);
    // 0x80053EDC: j           L_80053F50
    // 0x80053EE0: swc1        $f0, 0x2C($s3)
    MEM_W(0X2C, ctx->r19) = ctx->f0.u32l;
        goto L_80053F50;
    // 0x80053EE0: swc1        $f0, 0x2C($s3)
    MEM_W(0X2C, ctx->r19) = ctx->f0.u32l;
L_80053EE4:
    // 0x80053EE4: addu        $a0, $s4, $zero
    ctx->r4 = ADD32(ctx->r20, 0);
    // 0x80053EE8: lui         $a1, 0x8004
    ctx->r5 = S32(0X8004 << 16);
    // 0x80053EEC: jal         0x800594F8
    // 0x80053EF0: addiu       $a1, $a1, -0x53A8
    ctx->r5 = ADD32(ctx->r5, -0X53A8);
    func_800594F8(rdram, ctx);
        goto after_15;
    // 0x80053EF0: addiu       $a1, $a1, -0x53A8
    ctx->r5 = ADD32(ctx->r5, -0X53A8);
    after_15:
    // 0x80053EF4: beq         $v0, $zero, L_80053F10
    if (ctx->r2 == 0) {
        // 0x80053EF8: sw          $v0, 0xC($s3)
        MEM_W(0XC, ctx->r19) = ctx->r2;
            goto L_80053F10;
    }
    // 0x80053EF8: sw          $v0, 0xC($s3)
    MEM_W(0XC, ctx->r19) = ctx->r2;
    // 0x80053EFC: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x80053F00: lw          $v1, 0xC($v0)
    ctx->r3 = MEM_W(ctx->r2, 0XC);
    // 0x80053F04: addiu       $a0, $zero, -0x9
    ctx->r4 = ADD32(0, -0X9);
    // 0x80053F08: and         $v1, $v1, $a0
    ctx->r3 = ctx->r3 & ctx->r4;
    // 0x80053F0C: sw          $v1, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r3;
L_80053F10:
    // 0x80053F10: addu        $a0, $s4, $zero
    ctx->r4 = ADD32(ctx->r20, 0);
    // 0x80053F14: lui         $a1, 0x8004
    ctx->r5 = S32(0X8004 << 16);
    // 0x80053F18: jal         0x800594F8
    // 0x80053F1C: addiu       $a1, $a1, -0x53A0
    ctx->r5 = ADD32(ctx->r5, -0X53A0);
    func_800594F8(rdram, ctx);
        goto after_16;
    // 0x80053F1C: addiu       $a1, $a1, -0x53A0
    ctx->r5 = ADD32(ctx->r5, -0X53A0);
    after_16:
    // 0x80053F20: beq         $v0, $zero, L_80053F3C
    if (ctx->r2 == 0) {
        // 0x80053F24: sw          $v0, 0x10($s3)
        MEM_W(0X10, ctx->r19) = ctx->r2;
            goto L_80053F3C;
    }
    // 0x80053F24: sw          $v0, 0x10($s3)
    MEM_W(0X10, ctx->r19) = ctx->r2;
    // 0x80053F28: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x80053F2C: lw          $v1, 0xC($v0)
    ctx->r3 = MEM_W(ctx->r2, 0XC);
    // 0x80053F30: addiu       $a0, $zero, -0x9
    ctx->r4 = ADD32(0, -0X9);
    // 0x80053F34: and         $v1, $v1, $a0
    ctx->r3 = ctx->r3 & ctx->r4;
    // 0x80053F38: sw          $v1, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r3;
L_80053F3C:
    // 0x80053F3C: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80053F40: lwc1        $f0, -0x533C($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X533C);
    // 0x80053F44: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80053F48: lwc1        $f2, -0x5338($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X5338);
    // 0x80053F4C: swc1        $f0, 0x2C($s3)
    MEM_W(0X2C, ctx->r19) = ctx->f0.u32l;
L_80053F50:
    // 0x80053F50: swc1        $f2, 0x30($s3)
    MEM_W(0X30, ctx->r19) = ctx->f2.u32l;
L_80053F54:
    // 0x80053F54: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x80053F58: lw          $s6, 0x38($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X38);
    // 0x80053F5C: lw          $s5, 0x34($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X34);
    // 0x80053F60: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x80053F64: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x80053F68: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x80053F6C: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x80053F70: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80053F74: jr          $ra
    // 0x80053F78: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x80053F78: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void func_80053F7C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80053F7C: mtc1        $a2, $f10
    ctx->f10.u32l = ctx->r6;
    // 0x80053F80: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80053F84: ldc1        $f0, -0x5330($at)
    CHECK_FR(ctx, 0);
    ctx->f0.u64 = LD(ctx->r1, -0X5330);
    // 0x80053F88: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80053F8C: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80053F90: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x80053F94: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x80053F98: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x80053F9C: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x80053FA0: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x80053FA4: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x80053FA8: lwc1        $f4, 0x2C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x80053FAC: cvt.d.s     $f2, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f2.d = CVT_D_S(ctx->f10.fl);
    // 0x80053FB0: add.d       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f0.d); 
    ctx->f2.d = ctx->f2.d + ctx->f0.d;
    // 0x80053FB4: lwc1        $f0, 0x30($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X30);
    // 0x80053FB8: sub.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f4.fl;
    // 0x80053FBC: cvt.d.s     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f4.d = CVT_D_S(ctx->f4.fl);
    // 0x80053FC0: sub.d       $f2, $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f4.d); 
    ctx->f2.d = ctx->f2.d - ctx->f4.d;
    // 0x80053FC4: cvt.d.s     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.d = CVT_D_S(ctx->f0.fl);
    // 0x80053FC8: div.d       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f0.d); 
    ctx->f2.d = DIV_D(ctx->f2.d, ctx->f0.d);
    // 0x80053FCC: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80053FD0: cvt.s.d     $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.d); 
    ctx->f2.fl = CVT_S_D(ctx->f2.d);
    // 0x80053FD4: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x80053FD8: nop

    // 0x80053FDC: bc1f        L_80053FE8
    if (!c1cs) {
        // 0x80053FE0: addu        $s1, $a1, $zero
        ctx->r17 = ADD32(ctx->r5, 0);
            goto L_80053FE8;
    }
    // 0x80053FE0: addu        $s1, $a1, $zero
    ctx->r17 = ADD32(ctx->r5, 0);
    // 0x80053FE4: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
L_80053FE8:
    // 0x80053FE8: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80053FEC: lwc1        $f0, -0x5328($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X5328);
    // 0x80053FF0: mul.s       $f0, $f2, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x80053FF4: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80053FF8: lwc1        $f2, -0x5324($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X5324);
    // 0x80053FFC: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x80054000: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80054004: lwc1        $f2, -0x5320($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X5320);
    // 0x80054008: c.le.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl <= ctx->f0.fl;
    // 0x8005400C: nop

    // 0x80054010: bc1tl       L_80054028
    if (c1cs) {
        // 0x80054014: sub.s       $f0, $f0, $f2
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
            goto L_80054028;
    }
    goto skip_0;
    // 0x80054014: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    skip_0:
    // 0x80054018: trunc.w.s   $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    ctx->f10.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x8005401C: mfc1        $v1, $f10
    ctx->r3 = (int32_t)ctx->f10.u32l;
    // 0x80054020: j           L_80054038
    // 0x80054024: nop

        goto L_80054038;
    // 0x80054024: nop

L_80054028:
    // 0x80054028: lui         $v0, 0x8000
    ctx->r2 = S32(0X8000 << 16);
    // 0x8005402C: trunc.w.s   $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    ctx->f10.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x80054030: mfc1        $v1, $f10
    ctx->r3 = (int32_t)ctx->f10.u32l;
    // 0x80054034: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
L_80054038:
    // 0x80054038: lw          $a0, 0x8($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X8);
    // 0x8005403C: beq         $a0, $zero, L_80054058
    if (ctx->r4 == 0) {
        // 0x80054040: addu        $s2, $v1, $zero
        ctx->r18 = ADD32(ctx->r3, 0);
            goto L_80054058;
    }
    // 0x80054040: addu        $s2, $v1, $zero
    ctx->r18 = ADD32(ctx->r3, 0);
    // 0x80054044: addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    // 0x80054048: lw          $a1, 0x4($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X4);
    // 0x8005404C: lw          $a0, 0x0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X0);
    // 0x80054050: jal         0x800538B0
    // 0x80054054: addiu       $a1, $a1, 0x28
    ctx->r5 = ADD32(ctx->r5, 0X28);
    func_800538B0(rdram, ctx);
        goto after_0;
    // 0x80054054: addiu       $a1, $a1, 0x28
    ctx->r5 = ADD32(ctx->r5, 0X28);
    after_0:
L_80054058:
    // 0x80054058: lw          $v0, 0xC($s0)
    ctx->r2 = MEM_W(ctx->r16, 0XC);
    // 0x8005405C: beq         $v0, $zero, L_80054140
    if (ctx->r2 == 0) {
        // 0x80054060: lui         $v0, 0x8013
        ctx->r2 = S32(0X8013 << 16);
            goto L_80054140;
    }
    // 0x80054060: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80054064: lbu         $v0, 0xB3A($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0XB3A);
    // 0x80054068: beq         $v0, $zero, L_800540F4
    if (ctx->r2 == 0) {
        // 0x8005406C: nop
    
            goto L_800540F4;
    }
    // 0x8005406C: nop

    // 0x80054070: lw          $v0, 0x4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X4);
    // 0x80054074: lwc1        $f2, 0x0($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0X0);
    // 0x80054078: lwc1        $f0, 0x4C($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X4C);
    // 0x8005407C: sub.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl - ctx->f0.fl;
    // 0x80054080: swc1        $f2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f2.u32l;
    // 0x80054084: lw          $v0, 0x4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X4);
    // 0x80054088: lwc1        $f4, 0x4($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X4);
    // 0x8005408C: lwc1        $f0, 0x50($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X50);
    // 0x80054090: sub.s       $f4, $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f4.fl - ctx->f0.fl;
    // 0x80054094: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    // 0x80054098: lw          $v0, 0x4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X4);
    // 0x8005409C: lwc1        $f6, 0x8($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X8);
    // 0x800540A0: lwc1        $f0, 0x54($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X54);
    // 0x800540A4: sub.s       $f6, $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f6.fl - ctx->f0.fl;
    // 0x800540A8: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x800540AC: lwc1        $f8, -0x531C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X531C);
    // 0x800540B0: mul.s       $f2, $f2, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f8.fl);
    // 0x800540B4: swc1        $f6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f6.u32l;
    // 0x800540B8: lw          $v0, 0x4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X4);
    // 0x800540BC: lwc1        $f0, 0x4C($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X4C);
    // 0x800540C0: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x800540C4: mul.s       $f4, $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = MUL_S(ctx->f4.fl, ctx->f8.fl);
    // 0x800540C8: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    // 0x800540CC: lw          $v0, 0x4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X4);
    // 0x800540D0: lwc1        $f0, 0x50($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X50);
    // 0x800540D4: add.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f4.fl;
    // 0x800540D8: mul.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x800540DC: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    // 0x800540E0: lw          $v0, 0x4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X4);
    // 0x800540E4: lwc1        $f0, 0x54($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X54);
    // 0x800540E8: add.s       $f0, $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f6.fl;
    // 0x800540EC: j           L_8005410C
    // 0x800540F0: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
        goto L_8005410C;
    // 0x800540F0: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
L_800540F4:
    // 0x800540F4: lw          $t0, 0x0($s1)
    ctx->r8 = MEM_W(ctx->r17, 0X0);
    // 0x800540F8: lw          $t1, 0x4($s1)
    ctx->r9 = MEM_W(ctx->r17, 0X4);
    // 0x800540FC: lw          $t2, 0x8($s1)
    ctx->r10 = MEM_W(ctx->r17, 0X8);
    // 0x80054100: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x80054104: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    // 0x80054108: sw          $t2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r10;
L_8005410C:
    // 0x8005410C: addiu       $a2, $sp, 0x10
    ctx->r6 = ADD32(ctx->r29, 0X10);
    // 0x80054110: lw          $v0, 0xC($s0)
    ctx->r2 = MEM_W(ctx->r16, 0XC);
    // 0x80054114: lw          $a1, 0x4($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X4);
    // 0x80054118: lw          $a0, 0x0($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X0);
    // 0x8005411C: jal         0x800538B0
    // 0x80054120: addiu       $a1, $a1, 0x28
    ctx->r5 = ADD32(ctx->r5, 0X28);
    func_800538B0(rdram, ctx);
        goto after_1;
    // 0x80054120: addiu       $a1, $a1, 0x28
    ctx->r5 = ADD32(ctx->r5, 0X28);
    after_1:
    // 0x80054124: lw          $a0, 0x10($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X10);
    // 0x80054128: beq         $a0, $zero, L_80054140
    if (ctx->r4 == 0) {
        // 0x8005412C: addiu       $a2, $sp, 0x10
        ctx->r6 = ADD32(ctx->r29, 0X10);
            goto L_80054140;
    }
    // 0x8005412C: addiu       $a2, $sp, 0x10
    ctx->r6 = ADD32(ctx->r29, 0X10);
    // 0x80054130: lw          $a1, 0x4($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X4);
    // 0x80054134: lw          $a0, 0x0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X0);
    // 0x80054138: jal         0x800538B0
    // 0x8005413C: addiu       $a1, $a1, 0x28
    ctx->r5 = ADD32(ctx->r5, 0X28);
    func_800538B0(rdram, ctx);
        goto after_2;
    // 0x8005413C: addiu       $a1, $a1, 0x28
    ctx->r5 = ADD32(ctx->r5, 0X28);
    after_2:
L_80054140:
    // 0x80054140: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x80054144: lw          $v0, -0x7764($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7764);
    // 0x80054148: andi        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 & 0X1;
    // 0x8005414C: beq         $v0, $zero, L_800541DC
    if (ctx->r2 == 0) {
        // 0x80054150: nop
    
            goto L_800541DC;
    }
    // 0x80054150: nop

    // 0x80054154: lw          $v0, 0x14($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X14);
    // 0x80054158: beq         $v0, $zero, L_8005425C
    if (ctx->r2 == 0) {
        // 0x8005415C: andi        $s3, $s2, 0xFFFF
        ctx->r19 = ctx->r18 & 0XFFFF;
            goto L_8005425C;
    }
    // 0x8005415C: andi        $s3, $s2, 0xFFFF
    ctx->r19 = ctx->r18 & 0XFFFF;
    // 0x80054160: lw          $s4, 0x1C($s0)
    ctx->r20 = MEM_W(ctx->r16, 0X1C);
    // 0x80054164: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x80054168: addu        $s2, $s4, $zero
    ctx->r18 = ADD32(ctx->r20, 0);
    // 0x8005416C: lhu         $s0, 0x4($s4)
    ctx->r16 = MEM_HU(ctx->r20, 0X4);
    // 0x80054170: lw          $s1, 0x24($v0)
    ctx->r17 = MEM_W(ctx->r2, 0X24);
L_80054174:
    // 0x80054174: jal         0x80003430
    // 0x80054178: addiu       $s2, $s2, 0x8
    ctx->r18 = ADD32(ctx->r18, 0X8);
    rand_recomp(rdram, ctx);
        goto after_3;
    // 0x80054178: addiu       $s2, $s2, 0x8
    ctx->r18 = ADD32(ctx->r18, 0X8);
    after_3:
    // 0x8005417C: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x80054180: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x80054184: div         $zero, $v0, $s3
    if (S32(ctx->r19) != 0) { lo = S32(S64(S32(ctx->r2)) / S64(S32(ctx->r19))); hi = S32(S64(S32(ctx->r2)) % S64(S32(ctx->r19))); } else { lo = 0; hi = S32(ctx->r2); }
    // 0x80054188: bne         $s3, $zero, L_80054194
    if (ctx->r19 != 0) {
        // 0x8005418C: nop
    
            goto L_80054194;
    }
    // 0x8005418C: nop

    // 0x80054190: break       7
    do_break(2147828112);
L_80054194:
    // 0x80054194: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80054198: bne         $s3, $at, L_800541AC
    if (ctx->r19 != ctx->r1) {
        // 0x8005419C: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800541AC;
    }
    // 0x8005419C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800541A0: bne         $v0, $at, L_800541AC
    if (ctx->r2 != ctx->r1) {
        // 0x800541A4: nop
    
            goto L_800541AC;
    }
    // 0x800541A4: nop

    // 0x800541A8: break       6
    do_break(2147828136);
L_800541AC:
    // 0x800541AC: mfhi        $v1
    ctx->r3 = hi;
    // 0x800541B0: subu        $v1, $s0, $v1
    ctx->r3 = SUB32(ctx->r16, ctx->r3);
    // 0x800541B4: sh          $v1, 0x4($s1)
    MEM_H(0X4, ctx->r17) = ctx->r3;
    // 0x800541B8: lh          $v0, 0x4($s2)
    ctx->r2 = MEM_H(ctx->r18, 0X4);
    // 0x800541BC: lh          $v1, 0x4($s4)
    ctx->r3 = MEM_H(ctx->r20, 0X4);
    // 0x800541C0: lhu         $s0, 0x4($s2)
    ctx->r16 = MEM_HU(ctx->r18, 0X4);
    // 0x800541C4: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x800541C8: slti        $v0, $v0, 0x10
    ctx->r2 = SIGNED(ctx->r2) < 0X10 ? 1 : 0;
    // 0x800541CC: bne         $v0, $zero, L_80054174
    if (ctx->r2 != 0) {
        // 0x800541D0: addiu       $s1, $s1, 0x8
        ctx->r17 = ADD32(ctx->r17, 0X8);
            goto L_80054174;
    }
    // 0x800541D0: addiu       $s1, $s1, 0x8
    ctx->r17 = ADD32(ctx->r17, 0X8);
    // 0x800541D4: j           L_8005425C
    // 0x800541D8: nop

        goto L_8005425C;
    // 0x800541D8: nop

L_800541DC:
    // 0x800541DC: lw          $v0, 0x18($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X18);
    // 0x800541E0: beq         $v0, $zero, L_8005425C
    if (ctx->r2 == 0) {
        // 0x800541E4: andi        $s3, $s2, 0xFFFF
        ctx->r19 = ctx->r18 & 0XFFFF;
            goto L_8005425C;
    }
    // 0x800541E4: andi        $s3, $s2, 0xFFFF
    ctx->r19 = ctx->r18 & 0XFFFF;
    // 0x800541E8: lw          $s4, 0x20($s0)
    ctx->r20 = MEM_W(ctx->r16, 0X20);
    // 0x800541EC: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x800541F0: addu        $s2, $s4, $zero
    ctx->r18 = ADD32(ctx->r20, 0);
    // 0x800541F4: lhu         $s0, 0x4($s4)
    ctx->r16 = MEM_HU(ctx->r20, 0X4);
    // 0x800541F8: lw          $s1, 0x24($v0)
    ctx->r17 = MEM_W(ctx->r2, 0X24);
L_800541FC:
    // 0x800541FC: jal         0x80003430
    // 0x80054200: addiu       $s2, $s2, 0x8
    ctx->r18 = ADD32(ctx->r18, 0X8);
    rand_recomp(rdram, ctx);
        goto after_4;
    // 0x80054200: addiu       $s2, $s2, 0x8
    ctx->r18 = ADD32(ctx->r18, 0X8);
    after_4:
    // 0x80054204: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x80054208: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x8005420C: div         $zero, $v0, $s3
    if (S32(ctx->r19) != 0) { lo = S32(S64(S32(ctx->r2)) / S64(S32(ctx->r19))); hi = S32(S64(S32(ctx->r2)) % S64(S32(ctx->r19))); } else { lo = 0; hi = S32(ctx->r2); }
    // 0x80054210: bne         $s3, $zero, L_8005421C
    if (ctx->r19 != 0) {
        // 0x80054214: nop
    
            goto L_8005421C;
    }
    // 0x80054214: nop

    // 0x80054218: break       7
    do_break(2147828248);
L_8005421C:
    // 0x8005421C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80054220: bne         $s3, $at, L_80054234
    if (ctx->r19 != ctx->r1) {
        // 0x80054224: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80054234;
    }
    // 0x80054224: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80054228: bne         $v0, $at, L_80054234
    if (ctx->r2 != ctx->r1) {
        // 0x8005422C: nop
    
            goto L_80054234;
    }
    // 0x8005422C: nop

    // 0x80054230: break       6
    do_break(2147828272);
L_80054234:
    // 0x80054234: mfhi        $v1
    ctx->r3 = hi;
    // 0x80054238: subu        $v1, $s0, $v1
    ctx->r3 = SUB32(ctx->r16, ctx->r3);
    // 0x8005423C: sh          $v1, 0x4($s1)
    MEM_H(0X4, ctx->r17) = ctx->r3;
    // 0x80054240: lh          $v0, 0x4($s2)
    ctx->r2 = MEM_H(ctx->r18, 0X4);
    // 0x80054244: lh          $v1, 0x4($s4)
    ctx->r3 = MEM_H(ctx->r20, 0X4);
    // 0x80054248: lhu         $s0, 0x4($s2)
    ctx->r16 = MEM_HU(ctx->r18, 0X4);
    // 0x8005424C: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x80054250: slti        $v0, $v0, 0x10
    ctx->r2 = SIGNED(ctx->r2) < 0X10 ? 1 : 0;
    // 0x80054254: bne         $v0, $zero, L_800541FC
    if (ctx->r2 != 0) {
        // 0x80054258: addiu       $s1, $s1, 0x8
        ctx->r17 = ADD32(ctx->r17, 0X8);
            goto L_800541FC;
    }
    // 0x80054258: addiu       $s1, $s1, 0x8
    ctx->r17 = ADD32(ctx->r17, 0X8);
L_8005425C:
    // 0x8005425C: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x80054260: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x80054264: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x80054268: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x8005426C: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x80054270: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80054274: jr          $ra
    // 0x80054278: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x80054278: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_8005427C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005427C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80054280: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x80054284: addu        $s1, $a0, $zero
    ctx->r17 = ADD32(ctx->r4, 0);
    // 0x80054288: andi        $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 & 0XFFFF;
    // 0x8005428C: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x80054290: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80054294: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x80054298: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8005429C: lw          $s2, 0x4($s1)
    ctx->r18 = MEM_W(ctx->r17, 0X4);
    // 0x800542A0: beq         $a1, $v0, L_80054334
    if (ctx->r5 == ctx->r2) {
        // 0x800542A4: slti        $v0, $a1, 0x3
        ctx->r2 = SIGNED(ctx->r5) < 0X3 ? 1 : 0;
            goto L_80054334;
    }
    // 0x800542A4: slti        $v0, $a1, 0x3
    ctx->r2 = SIGNED(ctx->r5) < 0X3 ? 1 : 0;
    // 0x800542A8: beq         $v0, $zero, L_800542C0
    if (ctx->r2 == 0) {
        // 0x800542AC: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_800542C0;
    }
    // 0x800542AC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800542B0: beq         $a1, $v0, L_800542D4
    if (ctx->r5 == ctx->r2) {
        // 0x800542B4: nop
    
            goto L_800542D4;
    }
    // 0x800542B4: nop

    // 0x800542B8: j           L_800543D8
    // 0x800542BC: nop

        goto L_800543D8;
    // 0x800542BC: nop

L_800542C0:
    // 0x800542C0: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // 0x800542C4: beq         $a1, $v0, L_80054360
    if (ctx->r5 == ctx->r2) {
        // 0x800542C8: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80054360;
    }
    // 0x800542C8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800542CC: j           L_800543DC
    // 0x800542D0: nop

        goto L_800543DC;
    // 0x800542D0: nop

L_800542D4:
    // 0x800542D4: lhu         $v0, 0x0($a2)
    ctx->r2 = MEM_HU(ctx->r6, 0X0);
    // 0x800542D8: sh          $v0, 0x0($s2)
    MEM_H(0X0, ctx->r18) = ctx->r2;
    // 0x800542DC: jal         0x8004013C
    // 0x800542E0: andi        $a0, $v0, 0xFFFF
    ctx->r4 = ctx->r2 & 0XFFFF;
    func_8004013C(rdram, ctx);
        goto after_0;
    // 0x800542E0: andi        $a0, $v0, 0xFFFF
    ctx->r4 = ctx->r2 & 0XFFFF;
    after_0:
    // 0x800542E4: lw          $s0, 0xC($v0)
    ctx->r16 = MEM_W(ctx->r2, 0XC);
    // 0x800542E8: bne         $s0, $zero, L_80054304
    if (ctx->r16 != 0) {
        // 0x800542EC: addu        $a0, $s0, $zero
        ctx->r4 = ADD32(ctx->r16, 0);
            goto L_80054304;
    }
    // 0x800542EC: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x800542F0: lhu         $a0, 0x16($s1)
    ctx->r4 = MEM_HU(ctx->r17, 0X16);
    // 0x800542F4: jal         0x8003ED74
    // 0x800542F8: nop

    func_8003ED74(rdram, ctx);
        goto after_1;
    // 0x800542F8: nop

    after_1:
    // 0x800542FC: j           L_800543DC
    // 0x80054300: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_800543DC;
    // 0x80054300: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80054304:
    // 0x80054304: lhu         $a2, 0x0($s2)
    ctx->r6 = MEM_HU(ctx->r18, 0X0);
    // 0x80054308: jal         0x80053C04
    // 0x8005430C: addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    func_80053C04(rdram, ctx);
        goto after_2;
    // 0x8005430C: addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    after_2:
    // 0x80054310: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x80054314: addiu       $v0, $v0, -0x1430
    ctx->r2 = ADD32(ctx->r2, -0X1430);
    // 0x80054318: sw          $v0, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r2;
    // 0x8005431C: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x80054320: lhu         $a0, -0x6A6C($v0)
    ctx->r4 = MEM_HU(ctx->r2, -0X6A6C);
    // 0x80054324: jal         0x8003E684
    // 0x80054328: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    func_8003E684(rdram, ctx);
        goto after_3;
    // 0x80054328: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    after_3:
    // 0x8005432C: j           L_800543DC
    // 0x80054330: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_800543DC;
    // 0x80054330: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80054334:
    // 0x80054334: addu        $s1, $zero, $zero
    ctx->r17 = ADD32(0, 0);
    // 0x80054338: addu        $s0, $s2, $zero
    ctx->r16 = ADD32(ctx->r18, 0);
L_8005433C:
    // 0x8005433C: lw          $a0, 0x1C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X1C);
    // 0x80054340: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x80054344: jal         0x80001C98
    // 0x80054348: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    rs_free(rdram, ctx);
        goto after_4;
    // 0x80054348: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    after_4:
    // 0x8005434C: slti        $v0, $s1, 0x2
    ctx->r2 = SIGNED(ctx->r17) < 0X2 ? 1 : 0;
    // 0x80054350: bne         $v0, $zero, L_8005433C
    if (ctx->r2 != 0) {
        // 0x80054354: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_8005433C;
    }
    // 0x80054354: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80054358: j           L_800543DC
    // 0x8005435C: nop

        goto L_800543DC;
    // 0x8005435C: nop

L_80054360:
    // 0x80054360: lhu         $a0, 0x0($s2)
    ctx->r4 = MEM_HU(ctx->r18, 0X0);
    // 0x80054364: jal         0x8004013C
    // 0x80054368: nop

    func_8004013C(rdram, ctx);
        goto after_5;
    // 0x80054368: nop

    after_5:
    // 0x8005436C: lw          $s0, 0xC($v0)
    ctx->r16 = MEM_W(ctx->r2, 0XC);
    // 0x80054370: beq         $s0, $zero, L_800543DC
    if (ctx->r16 == 0) {
        // 0x80054374: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_800543DC;
    }
    // 0x80054374: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80054378: lhu         $a0, 0x0($s2)
    ctx->r4 = MEM_HU(ctx->r18, 0X0);
    // 0x8005437C: jal         0x8004015C
    // 0x80054380: nop

    func_8004015C(rdram, ctx);
        goto after_6;
    // 0x80054380: nop

    after_6:
    // 0x80054384: lwc1        $f0, 0x24($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X24);
    // 0x80054388: mul.s       $f0, $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x8005438C: lwc1        $f4, 0x28($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X28);
    // 0x80054390: mul.s       $f4, $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f4.fl = MUL_S(ctx->f4.fl, ctx->f4.fl);
    // 0x80054394: lwc1        $f2, 0x2C($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X2C);
    // 0x80054398: mul.s       $f2, $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x8005439C: add.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f4.fl;
    // 0x800543A0: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x800543A4: sqrt.s      $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = sqrtf(ctx->f0.fl);
    // 0x800543A8: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x800543AC: lw          $v0, -0x72E4($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X72E4);
    // 0x800543B0: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x800543B4: lwc1        $f0, 0x4C($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X4C);
    // 0x800543B8: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    // 0x800543BC: lwc1        $f0, 0x50($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X50);
    // 0x800543C0: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // 0x800543C4: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    // 0x800543C8: lwc1        $f0, 0x54($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X54);
    // 0x800543CC: addiu       $a1, $sp, 0x10
    ctx->r5 = ADD32(ctx->r29, 0X10);
    // 0x800543D0: jal         0x80053F7C
    // 0x800543D4: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    func_80053F7C(rdram, ctx);
        goto after_7;
    // 0x800543D4: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    after_7:
L_800543D8:
    // 0x800543D8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800543DC:
    // 0x800543DC: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x800543E0: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x800543E4: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x800543E8: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x800543EC: jr          $ra
    // 0x800543F0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x800543F0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void load_full_header_image(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800543F4: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x800543F8: sw          $s2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r18;
    // 0x800543FC: addu        $s2, $a0, $zero
    ctx->r18 = ADD32(ctx->r4, 0);
    // 0x80054400: sw          $s1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r17;
    // 0x80054404: lui         $s1, 0x8013
    ctx->r17 = S32(0X8013 << 16);
    // 0x80054408: lw          $a0, 0x7CFC($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X7CFC);
    // 0x8005440C: addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    // 0x80054410: sw          $ra, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r31;
    // 0x80054414: sw          $s3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r19;
    // 0x80054418: jal         0x80004D5C
    // 0x8005441C: sw          $s0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r16;
    get_asset_size_extra(rdram, ctx);
        goto after_0;
    // 0x8005441C: sw          $s0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r16;
    after_0:
    // 0x80054420: addu        $s3, $v0, $zero
    ctx->r19 = ADD32(ctx->r2, 0);
    // 0x80054424: addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    // 0x80054428: jal         0x80001ACC
    // 0x8005442C: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    rs_malloc(rdram, ctx);
        goto after_1;
    // 0x8005442C: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    after_1:
    // 0x80054430: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x80054434: lui         $s0, 0x8014
    ctx->r16 = S32(0X8014 << 16);
    // 0x80054438: addu        $a3, $s2, $zero
    ctx->r7 = ADD32(ctx->r18, 0);
    // 0x8005443C: lw          $a0, -0x76E0($s0)
    ctx->r4 = MEM_W(ctx->r16, -0X76E0);
    // 0x80054440: lw          $a2, 0x7CFC($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X7CFC);
    // 0x80054444: addu        $s1, $v0, $zero
    ctx->r17 = ADD32(ctx->r2, 0);
    // 0x80054448: jal         0x80004AAC
    // 0x8005444C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    func_80004AAC(rdram, ctx);
        goto after_2;
    // 0x8005444C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_2:
    // 0x80054450: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x80054454: addu        $s2, $v0, $zero
    ctx->r18 = ADD32(ctx->r2, 0);
    // 0x80054458: addu        $a2, $s2, $zero
    ctx->r6 = ADD32(ctx->r18, 0);
    // 0x8005445C: lw          $a0, -0x76E0($s0)
    ctx->r4 = MEM_W(ctx->r16, -0X76E0);
    // 0x80054460: addu        $a3, $a1, $zero
    ctx->r7 = ADD32(ctx->r5, 0);
    // 0x80054464: sw          $s3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r19;
    // 0x80054468: jal         0x80004E70
    // 0x8005446C: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    func_80004E70(rdram, ctx);
        goto after_3;
    // 0x8005446C: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    after_3:
    // 0x80054470: lw          $a0, -0x76E0($s0)
    ctx->r4 = MEM_W(ctx->r16, -0X76E0);
    // 0x80054474: jal         0x80004C70
    // 0x80054478: addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    func_80004C70(rdram, ctx);
        goto after_4;
    // 0x80054478: addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    after_4:
    // 0x8005447C: addiu       $s0, $s1, 0x4
    ctx->r16 = ADD32(ctx->r17, 0X4);
    // 0x80054480: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x80054484: jal         0x80055488
    // 0x80054488: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    full_header_image_offset_convert(rdram, ctx);
        goto after_5;
    // 0x80054488: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    after_5:
    // 0x8005448C: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    // 0x80054490: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x80054494: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80054498: lwc1        $f0, -0x5318($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X5318);
    // 0x8005449C: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x800544A0: lwc1        $f2, -0x5314($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X5314);
    // 0x800544A4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800544A8: sh          $v0, 0x18($sp)
    MEM_H(0X18, ctx->r29) = ctx->r2;
    // 0x800544AC: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x800544B0: sb          $v0, 0x28($sp)
    MEM_B(0X28, ctx->r29) = ctx->r2;
    // 0x800544B4: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    // 0x800544B8: swc1        $f2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f2.u32l;
    // 0x800544BC: lhu         $v0, 0x32($s1)
    ctx->r2 = MEM_HU(ctx->r17, 0X32);
    // 0x800544C0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x800544C4: ori         $v0, $v0, 0x300
    ctx->r2 = ctx->r2 | 0X300;
    // 0x800544C8: jal         0x80022B90
    // 0x800544CC: sh          $v0, 0x32($s1)
    MEM_H(0X32, ctx->r17) = ctx->r2;
    func_80022B90(rdram, ctx);
        goto after_6;
    // 0x800544CC: sh          $v0, 0x32($s1)
    MEM_H(0X32, ctx->r17) = ctx->r2;
    after_6:
    // 0x800544D0: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x800544D4: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x800544D8: jal         0x80001C98
    // 0x800544DC: sh          $v0, 0x7C70($s0)
    MEM_H(0X7C70, ctx->r16) = ctx->r2;
    rs_free(rdram, ctx);
        goto after_7;
    // 0x800544DC: sh          $v0, 0x7C70($s0)
    MEM_H(0X7C70, ctx->r16) = ctx->r2;
    after_7:
    // 0x800544E0: lhu         $v0, 0x7C70($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X7C70);
    // 0x800544E4: lw          $ra, 0x50($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X50);
    // 0x800544E8: lw          $s3, 0x4C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X4C);
    // 0x800544EC: lw          $s2, 0x48($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X48);
    // 0x800544F0: lw          $s1, 0x44($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X44);
    // 0x800544F4: lw          $s0, 0x40($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X40);
    // 0x800544F8: jr          $ra
    // 0x800544FC: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    return;
    // 0x800544FC: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
;}
RECOMP_FUNC void func_80054500(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80054500: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80054504: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x80054508: addu        $s1, $a0, $zero
    ctx->r17 = ADD32(ctx->r4, 0);
    // 0x8005450C: addiu       $a0, $zero, 0x34
    ctx->r4 = ADD32(0, 0X34);
    // 0x80054510: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x80054514: sw          $ra, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r31;
    // 0x80054518: jal         0x80001ACC
    // 0x8005451C: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    rs_malloc(rdram, ctx);
        goto after_0;
    // 0x8005451C: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    after_0:
    // 0x80054520: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    // 0x80054524: beq         $s0, $zero, L_80054538
    if (ctx->r16 == 0) {
        // 0x80054528: addu        $a0, $s1, $zero
        ctx->r4 = ADD32(ctx->r17, 0);
            goto L_80054538;
    }
    // 0x80054528: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x8005452C: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x80054530: jal         0x80053C04
    // 0x80054534: ori         $a2, $zero, 0xFFFF
    ctx->r6 = 0 | 0XFFFF;
    func_80053C04(rdram, ctx);
        goto after_1;
    // 0x80054534: ori         $a2, $zero, 0xFFFF
    ctx->r6 = 0 | 0XFFFF;
    after_1:
L_80054538:
    // 0x80054538: addu        $v0, $s0, $zero
    ctx->r2 = ADD32(ctx->r16, 0);
    // 0x8005453C: lw          $ra, 0x18($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X18);
    // 0x80054540: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x80054544: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x80054548: jr          $ra
    // 0x8005454C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x8005454C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_80054550(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80054550: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80054554: sw          $s4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r20;
    // 0x80054558: addu        $s4, $a1, $zero
    ctx->r20 = ADD32(ctx->r5, 0);
    // 0x8005455C: sw          $s3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r19;
    // 0x80054560: andi        $s3, $a2, 0xFFFF
    ctx->r19 = ctx->r6 & 0XFFFF;
    // 0x80054564: sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // 0x80054568: addu        $s2, $s4, $zero
    ctx->r18 = ADD32(ctx->r20, 0);
    // 0x8005456C: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x80054570: addu        $s1, $a0, $zero
    ctx->r17 = ADD32(ctx->r4, 0);
    // 0x80054574: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80054578: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x8005457C: lhu         $s0, 0x4($s4)
    ctx->r16 = MEM_HU(ctx->r20, 0X4);
L_80054580:
    // 0x80054580: jal         0x80003430
    // 0x80054584: addiu       $s2, $s2, 0x8
    ctx->r18 = ADD32(ctx->r18, 0X8);
    rand_recomp(rdram, ctx);
        goto after_0;
    // 0x80054584: addiu       $s2, $s2, 0x8
    ctx->r18 = ADD32(ctx->r18, 0X8);
    after_0:
    // 0x80054588: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x8005458C: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x80054590: div         $zero, $v0, $s3
    if (S32(ctx->r19) != 0) { lo = S32(S64(S32(ctx->r2)) / S64(S32(ctx->r19))); hi = S32(S64(S32(ctx->r2)) % S64(S32(ctx->r19))); } else { lo = 0; hi = S32(ctx->r2); }
    // 0x80054594: bne         $s3, $zero, L_800545A0
    if (ctx->r19 != 0) {
        // 0x80054598: nop
    
            goto L_800545A0;
    }
    // 0x80054598: nop

    // 0x8005459C: break       7
    do_break(2147829148);
L_800545A0:
    // 0x800545A0: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800545A4: bne         $s3, $at, L_800545B8
    if (ctx->r19 != ctx->r1) {
        // 0x800545A8: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800545B8;
    }
    // 0x800545A8: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800545AC: bne         $v0, $at, L_800545B8
    if (ctx->r2 != ctx->r1) {
        // 0x800545B0: nop
    
            goto L_800545B8;
    }
    // 0x800545B0: nop

    // 0x800545B4: break       6
    do_break(2147829172);
L_800545B8:
    // 0x800545B8: mfhi        $v1
    ctx->r3 = hi;
    // 0x800545BC: subu        $v1, $s0, $v1
    ctx->r3 = SUB32(ctx->r16, ctx->r3);
    // 0x800545C0: sh          $v1, 0x4($s1)
    MEM_H(0X4, ctx->r17) = ctx->r3;
    // 0x800545C4: lh          $v0, 0x4($s2)
    ctx->r2 = MEM_H(ctx->r18, 0X4);
    // 0x800545C8: lh          $v1, 0x4($s4)
    ctx->r3 = MEM_H(ctx->r20, 0X4);
    // 0x800545CC: lhu         $s0, 0x4($s2)
    ctx->r16 = MEM_HU(ctx->r18, 0X4);
    // 0x800545D0: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x800545D4: slti        $v0, $v0, 0x10
    ctx->r2 = SIGNED(ctx->r2) < 0X10 ? 1 : 0;
    // 0x800545D8: bne         $v0, $zero, L_80054580
    if (ctx->r2 != 0) {
        // 0x800545DC: addiu       $s1, $s1, 0x8
        ctx->r17 = ADD32(ctx->r17, 0X8);
            goto L_80054580;
    }
    // 0x800545DC: addiu       $s1, $s1, 0x8
    ctx->r17 = ADD32(ctx->r17, 0X8);
    // 0x800545E0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800545E4: lw          $s4, 0x20($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X20);
    // 0x800545E8: lw          $s3, 0x1C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X1C);
    // 0x800545EC: lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X18);
    // 0x800545F0: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x800545F4: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x800545F8: jr          $ra
    // 0x800545FC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x800545FC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_80054600(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80054600: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80054604: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x80054608: addu        $s1, $zero, $zero
    ctx->r17 = ADD32(0, 0);
    // 0x8005460C: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x80054610: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x80054614: sw          $ra, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r31;
L_80054618:
    // 0x80054618: lw          $a0, 0x1C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X1C);
    // 0x8005461C: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x80054620: jal         0x80001C98
    // 0x80054624: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    rs_free(rdram, ctx);
        goto after_0;
    // 0x80054624: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    after_0:
    // 0x80054628: slti        $v0, $s1, 0x2
    ctx->r2 = SIGNED(ctx->r17) < 0X2 ? 1 : 0;
    // 0x8005462C: bne         $v0, $zero, L_80054618
    if (ctx->r2 != 0) {
        // 0x80054630: nop
    
            goto L_80054618;
    }
    // 0x80054630: nop

    // 0x80054634: lw          $ra, 0x18($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X18);
    // 0x80054638: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x8005463C: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x80054640: jr          $ra
    // 0x80054644: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80054644: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void fake_func_80054648(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
;}
RECOMP_FUNC void func_80054650(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80054650: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80054654: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80054658: sw          $s3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r19;
    // 0x8005465C: lw          $s3, 0x7C80($v0)
    ctx->r19 = MEM_W(ctx->r2, 0X7C80);
    // 0x80054660: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80054664: sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // 0x80054668: lw          $s2, 0x7C84($v0)
    ctx->r18 = MEM_W(ctx->r2, 0X7C84);
    // 0x8005466C: sdc1        $f24, 0x38($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X38, ctx->r29);
    // 0x80054670: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80054674: sw          $s4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r20;
    // 0x80054678: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x8005467C: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x80054680: sdc1        $f22, 0x30($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X30, ctx->r29);
    // 0x80054684: sdc1        $f20, 0x28($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X28, ctx->r29);
    // 0x80054688: blez        $s3, L_80054794
    if (SIGNED(ctx->r19) <= 0) {
        // 0x8005468C: mov.s       $f24, $f12
        CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 12);
    ctx->f24.fl = ctx->f12.fl;
            goto L_80054794;
    }
    // 0x8005468C: mov.s       $f24, $f12
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 12);
    ctx->f24.fl = ctx->f12.fl;
    // 0x80054690: lui         $s4, 0x8000
    ctx->r20 = S32(0X8000 << 16);
    // 0x80054694: addiu       $s0, $s2, 0x4
    ctx->r16 = ADD32(ctx->r18, 0X4);
    // 0x80054698: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8005469C: ldc1        $f20, -0x5310($at)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r1, -0X5310);
    // 0x800546A0: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x800546A4: lwc1        $f22, -0x5308($at)
    ctx->f22.u32l = MEM_W(ctx->r1, -0X5308);
L_800546A8:
    // 0x800546A8: lhu         $v0, 0x2($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X2);
    // 0x800546AC: andi        $v0, $v0, 0x4000
    ctx->r2 = ctx->r2 & 0X4000;
    // 0x800546B0: beql        $v0, $zero, L_80054788
    if (ctx->r2 == 0) {
        // 0x800546B4: addiu       $s3, $s3, -0x1
        ctx->r19 = ADD32(ctx->r19, -0X1);
            goto L_80054788;
    }
    goto skip_0;
    // 0x800546B4: addiu       $s3, $s3, -0x1
    ctx->r19 = ADD32(ctx->r19, -0X1);
    skip_0:
    // 0x800546B8: lw          $v0, 0x4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X4);
    // 0x800546BC: mtc1        $v0, $f2
    ctx->f2.u32l = ctx->r2;
    // 0x800546C0: cvt.d.w     $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    ctx->f2.d = CVT_D_W(ctx->f2.u32l);
    // 0x800546C4: bgez        $v0, L_800546D0
    if (SIGNED(ctx->r2) >= 0) {
        // 0x800546C8: srl         $s1, $v0, 8
        ctx->r17 = S32(U32(ctx->r2) >> 8);
            goto L_800546D0;
    }
    // 0x800546C8: srl         $s1, $v0, 8
    ctx->r17 = S32(U32(ctx->r2) >> 8);
    // 0x800546CC: add.d       $f2, $f2, $f20
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f20.d); 
    ctx->f2.d = ctx->f2.d + ctx->f20.d;
L_800546D0:
    // 0x800546D0: lw          $v0, 0x8($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X8);
    // 0x800546D4: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x800546D8: cvt.d.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.d = CVT_D_W(ctx->f0.u32l);
    // 0x800546DC: bgez        $v0, L_800546E8
    if (SIGNED(ctx->r2) >= 0) {
        // 0x800546E0: cvt.s.d     $f2, $f2
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.d); 
    ctx->f2.fl = CVT_S_D(ctx->f2.d);
            goto L_800546E8;
    }
    // 0x800546E0: cvt.s.d     $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.d); 
    ctx->f2.fl = CVT_S_D(ctx->f2.d);
    // 0x800546E4: add.d       $f0, $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f20.d); 
    ctx->f0.d = ctx->f0.d + ctx->f20.d;
L_800546E8:
    // 0x800546E8: cvt.s.d     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); 
    ctx->f0.fl = CVT_S_D(ctx->f0.d);
    // 0x800546EC: mul.s       $f0, $f0, $f24
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f24.fl);
    // 0x800546F0: add.s       $f0, $f2, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x800546F4: c.le.s      $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f22.fl <= ctx->f0.fl;
    // 0x800546F8: nop

    // 0x800546FC: bc1tl       L_80054714
    if (c1cs) {
        // 0x80054700: sub.s       $f0, $f0, $f22
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f22.fl;
            goto L_80054714;
    }
    goto skip_1;
    // 0x80054700: sub.s       $f0, $f0, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f22.fl;
    skip_1:
    // 0x80054704: trunc.w.s   $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    ctx->f4.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x80054708: mfc1        $v1, $f4
    ctx->r3 = (int32_t)ctx->f4.u32l;
    // 0x8005470C: j           L_80054724
    // 0x80054710: sw          $v1, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r3;
        goto L_80054724;
    // 0x80054710: sw          $v1, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r3;
L_80054714:
    // 0x80054714: trunc.w.s   $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    ctx->f4.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x80054718: mfc1        $v1, $f4
    ctx->r3 = (int32_t)ctx->f4.u32l;
    // 0x8005471C: or          $v1, $v1, $s4
    ctx->r3 = ctx->r3 | ctx->r20;
    // 0x80054720: sw          $v1, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r3;
L_80054724:
    // 0x80054724: andi        $v0, $s1, 0xFFFF
    ctx->r2 = ctx->r17 & 0XFFFF;
    // 0x80054728: srl         $v1, $v1, 8
    ctx->r3 = S32(U32(ctx->r3) >> 8);
    // 0x8005472C: beql        $v0, $v1, L_80054788
    if (ctx->r2 == ctx->r3) {
        // 0x80054730: addiu       $s3, $s3, -0x1
        ctx->r19 = ADD32(ctx->r19, -0X1);
            goto L_80054788;
    }
    goto skip_2;
    // 0x80054730: addiu       $s3, $s3, -0x1
    ctx->r19 = ADD32(ctx->r19, -0X1);
    skip_2:
    // 0x80054734: lh          $v0, 0x0($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X0);
    // 0x80054738: divu        $zero, $v1, $v0
    if (U32(ctx->r2) != 0) { lo = S32(U32(ctx->r3) / U32(ctx->r2)); hi = S32(U32(ctx->r3) % U32(ctx->r2)); } else { lo = 0; hi = S32(ctx->r3); }
    // 0x8005473C: bne         $v0, $zero, L_80054748
    if (ctx->r2 != 0) {
        // 0x80054740: nop
    
            goto L_80054748;
    }
    // 0x80054740: nop

    // 0x80054744: break       7
    do_break(2147829572);
L_80054748:
    // 0x80054748: mfhi        $v1
    ctx->r3 = hi;
    // 0x8005474C: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x80054750: lhu         $a0, 0x0($v0)
    ctx->r4 = MEM_HU(ctx->r2, 0X0);
    // 0x80054754: jal         0x800232F8
    // 0x80054758: addu        $s1, $v1, $zero
    ctx->r17 = ADD32(ctx->r3, 0);
    func_800232F8(rdram, ctx);
        goto after_0;
    // 0x80054758: addu        $s1, $v1, $zero
    ctx->r17 = ADD32(ctx->r3, 0);
    after_0:
    // 0x8005475C: lw          $v1, 0x0($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X0);
    // 0x80054760: sw          $v0, 0x10($v1)
    MEM_W(0X10, ctx->r3) = ctx->r2;
    // 0x80054764: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    // 0x80054768: lw          $v1, 0xC($a0)
    ctx->r3 = MEM_W(ctx->r4, 0XC);
    // 0x8005476C: andi        $v0, $s1, 0xFFFF
    ctx->r2 = ctx->r17 & 0XFFFF;
    // 0x80054770: mult        $v1, $v0
    result = S64(S32(ctx->r3)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80054774: mflo        $v1
    ctx->r3 = lo;
    // 0x80054778: addiu       $a1, $v1, 0x14
    ctx->r5 = ADD32(ctx->r3, 0X14);
    // 0x8005477C: jal         0x80023274
    // 0x80054780: addu        $a1, $a0, $a1
    ctx->r5 = ADD32(ctx->r4, ctx->r5);
    func_80023274(rdram, ctx);
        goto after_1;
    // 0x80054780: addu        $a1, $a0, $a1
    ctx->r5 = ADD32(ctx->r4, ctx->r5);
    after_1:
    // 0x80054784: addiu       $s3, $s3, -0x1
    ctx->r19 = ADD32(ctx->r19, -0X1);
L_80054788:
    // 0x80054788: addiu       $s0, $s0, 0x10
    ctx->r16 = ADD32(ctx->r16, 0X10);
    // 0x8005478C: bgtz        $s3, L_800546A8
    if (SIGNED(ctx->r19) > 0) {
        // 0x80054790: addiu       $s2, $s2, 0x10
        ctx->r18 = ADD32(ctx->r18, 0X10);
            goto L_800546A8;
    }
    // 0x80054790: addiu       $s2, $s2, 0x10
    ctx->r18 = ADD32(ctx->r18, 0X10);
L_80054794:
    // 0x80054794: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80054798: lw          $s4, 0x20($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X20);
    // 0x8005479C: lw          $s3, 0x1C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X1C);
    // 0x800547A0: lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X18);
    // 0x800547A4: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x800547A8: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x800547AC: ldc1        $f24, 0x38($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X38);
    // 0x800547B0: ldc1        $f22, 0x30($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X30);
    // 0x800547B4: ldc1        $f20, 0x28($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X28);
    // 0x800547B8: jr          $ra
    // 0x800547BC: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x800547BC: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void func_800547C0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800547C0: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x800547C4: sw          $s2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r18;
    // 0x800547C8: addu        $s2, $a1, $zero
    ctx->r18 = ADD32(ctx->r5, 0);
    // 0x800547CC: sw          $ra, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r31;
    // 0x800547D0: sw          $s6, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r22;
    // 0x800547D4: sw          $s5, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r21;
    // 0x800547D8: sw          $s4, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r20;
    // 0x800547DC: sw          $s3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r19;
    // 0x800547E0: sw          $s1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r17;
    // 0x800547E4: jal         0x80022D68
    // 0x800547E8: sw          $s0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r16;
    func_80022D68(rdram, ctx);
        goto after_0;
    // 0x800547E8: sw          $s0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r16;
    after_0:
    // 0x800547EC: andi        $a0, $v0, 0xFFFF
    ctx->r4 = ctx->r2 & 0XFFFF;
    // 0x800547F0: ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
    // 0x800547F4: beq         $a0, $v0, L_800549F0
    if (ctx->r4 == ctx->r2) {
        // 0x800547F8: nop
    
            goto L_800549F0;
    }
    // 0x800547F8: nop

    // 0x800547FC: jal         0x80022F48
    // 0x80054800: addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    func_80022F48(rdram, ctx);
        goto after_1;
    // 0x80054800: addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    after_1:
    // 0x80054804: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x80054808: bne         $v0, $zero, L_80054818
    if (ctx->r2 != 0) {
        // 0x8005480C: lui         $v0, 0x8013
        ctx->r2 = S32(0X8013 << 16);
            goto L_80054818;
    }
    // 0x8005480C: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
L_80054810:
    // 0x80054810: j           L_800549F0
    // 0x80054814: ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
        goto L_800549F0;
    // 0x80054814: ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
L_80054818:
    // 0x80054818: lw          $v1, 0x7C80($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X7C80);
    // 0x8005481C: blez        $v1, L_80054810
    if (SIGNED(ctx->r3) <= 0) {
        // 0x80054820: addu        $s5, $zero, $zero
        ctx->r21 = ADD32(0, 0);
            goto L_80054810;
    }
    // 0x80054820: addu        $s5, $zero, $zero
    ctx->r21 = ADD32(0, 0);
    // 0x80054824: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80054828: lw          $a2, 0x7C84($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X7C84);
    // 0x8005482C: andi        $v0, $s5, 0xFFFF
    ctx->r2 = ctx->r21 & 0XFFFF;
L_80054830:
    // 0x80054830: sll         $v0, $v0, 4
    ctx->r2 = S32(ctx->r2 << 4);
    // 0x80054834: addu        $v0, $v0, $a2
    ctx->r2 = ADD32(ctx->r2, ctx->r6);
    // 0x80054838: lhu         $v0, 0x6($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X6);
    // 0x8005483C: andi        $v0, $v0, 0x8000
    ctx->r2 = ctx->r2 & 0X8000;
    // 0x80054840: beq         $v0, $zero, L_80054860
    if (ctx->r2 == 0) {
        // 0x80054844: lui         $v0, 0x8013
        ctx->r2 = S32(0X8013 << 16);
            goto L_80054860;
    }
    // 0x80054844: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80054848: addiu       $s5, $s5, 0x1
    ctx->r21 = ADD32(ctx->r21, 0X1);
    // 0x8005484C: andi        $v0, $s5, 0xFFFF
    ctx->r2 = ctx->r21 & 0XFFFF;
    // 0x80054850: slt         $v0, $v0, $v1
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80054854: bne         $v0, $zero, L_80054830
    if (ctx->r2 != 0) {
        // 0x80054858: andi        $v0, $s5, 0xFFFF
        ctx->r2 = ctx->r21 & 0XFFFF;
            goto L_80054830;
    }
    // 0x80054858: andi        $v0, $s5, 0xFFFF
    ctx->r2 = ctx->r21 & 0XFFFF;
    // 0x8005485C: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
L_80054860:
    // 0x80054860: lw          $v0, 0x7C80($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X7C80);
    // 0x80054864: andi        $v1, $s5, 0xFFFF
    ctx->r3 = ctx->r21 & 0XFFFF;
    // 0x80054868: slt         $v0, $v1, $v0
    ctx->r2 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8005486C: beq         $v0, $zero, L_80054810
    if (ctx->r2 == 0) {
        // 0x80054870: addu        $a1, $s2, $zero
        ctx->r5 = ADD32(ctx->r18, 0);
            goto L_80054810;
    }
    // 0x80054870: addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    // 0x80054874: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x80054878: sll         $v0, $v1, 4
    ctx->r2 = S32(ctx->r3 << 4);
    // 0x8005487C: addu        $s4, $a2, $v0
    ctx->r20 = ADD32(ctx->r6, ctx->r2);
    // 0x80054880: lw          $a0, 0x7CFC($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X7CFC);
    // 0x80054884: ori         $v0, $zero, 0x8000
    ctx->r2 = 0 | 0X8000;
    // 0x80054888: sh          $v0, 0x6($s4)
    MEM_H(0X6, ctx->r20) = ctx->r2;
    // 0x8005488C: sw          $zero, 0xC($s4)
    MEM_W(0XC, ctx->r20) = 0;
    // 0x80054890: jal         0x80004D5C
    // 0x80054894: sw          $zero, 0x8($s4)
    MEM_W(0X8, ctx->r20) = 0;
    get_asset_size_extra(rdram, ctx);
        goto after_2;
    // 0x80054894: sw          $zero, 0x8($s4)
    MEM_W(0X8, ctx->r20) = 0;
    after_2:
    // 0x80054898: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // 0x8005489C: jal         0x80001ACC
    // 0x800548A0: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    rs_malloc(rdram, ctx);
        goto after_3;
    // 0x800548A0: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    after_3:
    // 0x800548A4: addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    // 0x800548A8: addu        $s6, $v0, $zero
    ctx->r22 = ADD32(ctx->r2, 0);
    // 0x800548AC: lw          $a0, 0x7CFC($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X7CFC);
    // 0x800548B0: jal         0x80005134
    // 0x800548B4: addu        $s3, $s6, $zero
    ctx->r19 = ADD32(ctx->r22, 0);
    get_asset_size_simple(rdram, ctx);
        goto after_4;
    // 0x800548B4: addu        $s3, $s6, $zero
    ctx->r19 = ADD32(ctx->r22, 0);
    after_4:
    // 0x800548B8: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x800548BC: lui         $s1, 0x8014
    ctx->r17 = S32(0X8014 << 16);
    // 0x800548C0: addu        $a3, $s2, $zero
    ctx->r7 = ADD32(ctx->r18, 0);
    // 0x800548C4: lw          $a0, -0x76E0($s1)
    ctx->r4 = MEM_W(ctx->r17, -0X76E0);
    // 0x800548C8: lw          $a2, 0x7CFC($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X7CFC);
    // 0x800548CC: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    // 0x800548D0: jal         0x80004AAC
    // 0x800548D4: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    func_80004AAC(rdram, ctx);
        goto after_5;
    // 0x800548D4: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_5:
    // 0x800548D8: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x800548DC: addu        $s2, $v0, $zero
    ctx->r18 = ADD32(ctx->r2, 0);
    // 0x800548E0: addu        $a2, $s2, $zero
    ctx->r6 = ADD32(ctx->r18, 0);
    // 0x800548E4: lw          $a0, -0x76E0($s1)
    ctx->r4 = MEM_W(ctx->r17, -0X76E0);
    // 0x800548E8: addu        $a3, $a1, $zero
    ctx->r7 = ADD32(ctx->r5, 0);
    // 0x800548EC: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x800548F0: jal         0x80004E70
    // 0x800548F4: sw          $s6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r22;
    func_80004E70(rdram, ctx);
        goto after_6;
    // 0x800548F4: sw          $s6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r22;
    after_6:
    // 0x800548F8: lw          $a0, -0x76E0($s1)
    ctx->r4 = MEM_W(ctx->r17, -0X76E0);
    // 0x800548FC: jal         0x80004C70
    // 0x80054900: addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    func_80004C70(rdram, ctx);
        goto after_7;
    // 0x80054900: addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    after_7:
    // 0x80054904: addu        $a0, $s6, $s0
    ctx->r4 = ADD32(ctx->r22, ctx->r16);
    // 0x80054908: sltiu       $s0, $s0, 0x11
    ctx->r16 = ctx->r16 < 0X11 ? 1 : 0;
    // 0x8005490C: bne         $s0, $zero, L_80054940
    if (ctx->r16 != 0) {
        // 0x80054910: sh          $zero, 0x4($s4)
        MEM_H(0X4, ctx->r20) = 0;
            goto L_80054940;
    }
    // 0x80054910: sh          $zero, 0x4($s4)
    MEM_H(0X4, ctx->r20) = 0;
    // 0x80054914: addiu       $a1, $zero, -0x4
    ctx->r5 = ADD32(0, -0X4);
L_80054918:
    // 0x80054918: lw          $v0, 0x0($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X0);
    // 0x8005491C: lhu         $v1, 0x4($s4)
    ctx->r3 = MEM_HU(ctx->r20, 0X4);
    // 0x80054920: addu        $v0, $s3, $v0
    ctx->r2 = ADD32(ctx->r19, ctx->r2);
    // 0x80054924: addiu       $v0, $v0, 0x7
    ctx->r2 = ADD32(ctx->r2, 0X7);
    // 0x80054928: and         $s3, $v0, $a1
    ctx->r19 = ctx->r2 & ctx->r5;
    // 0x8005492C: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80054930: subu        $v0, $a0, $s3
    ctx->r2 = SUB32(ctx->r4, ctx->r19);
    // 0x80054934: sltiu       $v0, $v0, 0x11
    ctx->r2 = ctx->r2 < 0X11 ? 1 : 0;
    // 0x80054938: beq         $v0, $zero, L_80054918
    if (ctx->r2 == 0) {
        // 0x8005493C: sh          $v1, 0x4($s4)
        MEM_H(0X4, ctx->r20) = ctx->r3;
            goto L_80054918;
    }
    // 0x8005493C: sh          $v1, 0x4($s4)
    MEM_H(0X4, ctx->r20) = ctx->r3;
L_80054940:
    // 0x80054940: lh          $v1, 0x4($s4)
    ctx->r3 = MEM_H(ctx->r20, 0X4);
    // 0x80054944: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x80054948: mult        $v1, $v0
    result = S64(S32(ctx->r3)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8005494C: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x80054950: addu        $s3, $s6, $zero
    ctx->r19 = ADD32(ctx->r22, 0);
    // 0x80054954: mflo        $t0
    ctx->r8 = lo;
    // 0x80054958: jal         0x80001ACC
    // 0x8005495C: addiu       $a0, $t0, 0x14
    ctx->r4 = ADD32(ctx->r8, 0X14);
    rs_malloc(rdram, ctx);
        goto after_8;
    // 0x8005495C: addiu       $a0, $t0, 0x14
    ctx->r4 = ADD32(ctx->r8, 0X14);
    after_8:
    // 0x80054960: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // 0x80054964: addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    // 0x80054968: addiu       $a2, $zero, 0x14
    ctx->r6 = ADD32(0, 0X14);
    // 0x8005496C: jal         0x80018EF4
    // 0x80054970: sw          $a0, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->r4;
    zmemcpy(rdram, ctx);
        goto after_9;
    // 0x80054970: sw          $a0, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->r4;
    after_9:
    // 0x80054974: lh          $v0, 0x4($s4)
    ctx->r2 = MEM_H(ctx->r20, 0X4);
    // 0x80054978: blez        $v0, L_800549E4
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8005497C: addu        $s1, $zero, $zero
        ctx->r17 = ADD32(0, 0);
            goto L_800549E4;
    }
    // 0x8005497C: addu        $s1, $zero, $zero
    ctx->r17 = ADD32(0, 0);
    // 0x80054980: addiu       $s2, $zero, -0x4
    ctx->r18 = ADD32(0, -0X4);
L_80054984:
    // 0x80054984: addiu       $s0, $s3, 0x4
    ctx->r16 = ADD32(ctx->r19, 0X4);
    // 0x80054988: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x8005498C: jal         0x80055488
    // 0x80054990: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    full_header_image_offset_convert(rdram, ctx);
        goto after_10;
    // 0x80054990: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    after_10:
    // 0x80054994: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x80054998: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    // 0x8005499C: mult        $v0, $s1
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r17)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800549A0: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    // 0x800549A4: lw          $a0, 0x0($s4)
    ctx->r4 = MEM_W(ctx->r20, 0X0);
    // 0x800549A8: lw          $a3, 0x24($s3)
    ctx->r7 = MEM_W(ctx->r19, 0X24);
    // 0x800549AC: addu        $v0, $a0, $zero
    ctx->r2 = ADD32(ctx->r4, 0);
    // 0x800549B0: mflo        $t0
    ctx->r8 = lo;
    // 0x800549B4: addiu       $v1, $t0, 0x14
    ctx->r3 = ADD32(ctx->r8, 0X14);
    // 0x800549B8: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800549BC: jal         0x80022FF8
    // 0x800549C0: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    func_80022FF8(rdram, ctx);
        goto after_11;
    // 0x800549C0: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    after_11:
    // 0x800549C4: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x800549C8: lw          $v1, 0x0($s3)
    ctx->r3 = MEM_W(ctx->r19, 0X0);
    // 0x800549CC: lh          $v0, 0x4($s4)
    ctx->r2 = MEM_H(ctx->r20, 0X4);
    // 0x800549D0: addu        $v1, $s3, $v1
    ctx->r3 = ADD32(ctx->r19, ctx->r3);
    // 0x800549D4: addiu       $v1, $v1, 0x7
    ctx->r3 = ADD32(ctx->r3, 0X7);
    // 0x800549D8: slt         $v0, $s1, $v0
    ctx->r2 = SIGNED(ctx->r17) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800549DC: bne         $v0, $zero, L_80054984
    if (ctx->r2 != 0) {
        // 0x800549E0: and         $s3, $v1, $s2
        ctx->r19 = ctx->r3 & ctx->r18;
            goto L_80054984;
    }
    // 0x800549E0: and         $s3, $v1, $s2
    ctx->r19 = ctx->r3 & ctx->r18;
L_800549E4:
    // 0x800549E4: jal         0x80001C98
    // 0x800549E8: addu        $a0, $s6, $zero
    ctx->r4 = ADD32(ctx->r22, 0);
    rs_free(rdram, ctx);
        goto after_12;
    // 0x800549E8: addu        $a0, $s6, $zero
    ctx->r4 = ADD32(ctx->r22, 0);
    after_12:
    // 0x800549EC: andi        $v0, $s5, 0xFFFF
    ctx->r2 = ctx->r21 & 0XFFFF;
L_800549F0:
    // 0x800549F0: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
    // 0x800549F4: lw          $s6, 0x50($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X50);
    // 0x800549F8: lw          $s5, 0x4C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X4C);
    // 0x800549FC: lw          $s4, 0x48($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X48);
    // 0x80054A00: lw          $s3, 0x44($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X44);
    // 0x80054A04: lw          $s2, 0x40($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X40);
    // 0x80054A08: lw          $s1, 0x3C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X3C);
    // 0x80054A0C: lw          $s0, 0x38($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X38);
    // 0x80054A10: jr          $ra
    // 0x80054A14: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    return;
    // 0x80054A14: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
;}
RECOMP_FUNC void func_80054A18(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80054A18: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80054A1C: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x80054A20: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x80054A24: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80054A28: sll         $a0, $s0, 3
    ctx->r4 = S32(ctx->r16 << 3);
    // 0x80054A2C: subu        $a0, $a0, $s0
    ctx->r4 = SUB32(ctx->r4, ctx->r16);
    // 0x80054A30: sll         $a0, $a0, 2
    ctx->r4 = S32(ctx->r4 << 2);
    // 0x80054A34: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x80054A38: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80054A3C: jal         0x80001ACC
    // 0x80054A40: sw          $s0, 0x7C80($v0)
    MEM_W(0X7C80, ctx->r2) = ctx->r16;
    rs_malloc(rdram, ctx);
        goto after_0;
    // 0x80054A40: sw          $s0, 0x7C80($v0)
    MEM_W(0X7C80, ctx->r2) = ctx->r16;
    after_0:
    // 0x80054A44: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x80054A48: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x80054A4C: blez        $s0, L_80054A6C
    if (SIGNED(ctx->r16) <= 0) {
        // 0x80054A50: sw          $v0, 0x7C84($v1)
        MEM_W(0X7C84, ctx->r3) = ctx->r2;
            goto L_80054A6C;
    }
    // 0x80054A50: sw          $v0, 0x7C84($v1)
    MEM_W(0X7C84, ctx->r3) = ctx->r2;
    // 0x80054A54: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
L_80054A58:
    // 0x80054A58: sh          $zero, 0x6($v1)
    MEM_H(0X6, ctx->r3) = 0;
    // 0x80054A5C: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x80054A60: slt         $v0, $a0, $s0
    ctx->r2 = SIGNED(ctx->r4) < SIGNED(ctx->r16) ? 1 : 0;
    // 0x80054A64: bne         $v0, $zero, L_80054A58
    if (ctx->r2 != 0) {
        // 0x80054A68: addiu       $v1, $v1, 0x10
        ctx->r3 = ADD32(ctx->r3, 0X10);
            goto L_80054A58;
    }
    // 0x80054A68: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
L_80054A6C:
    // 0x80054A6C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80054A70: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x80054A74: jr          $ra
    // 0x80054A78: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80054A78: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_80054A7C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80054A7C: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x80054A80: lw          $v0, 0x7C80($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X7C80);
    // 0x80054A84: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80054A88: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x80054A8C: addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
    // 0x80054A90: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80054A94: sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // 0x80054A98: blez        $v0, L_80054AE4
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80054A9C: sw          $s1, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r17;
            goto L_80054AE4;
    }
    // 0x80054A9C: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x80054AA0: lui         $s2, 0x8013
    ctx->r18 = S32(0X8013 << 16);
    // 0x80054AA4: addu        $s1, $v1, $zero
    ctx->r17 = ADD32(ctx->r3, 0);
L_80054AA8:
    // 0x80054AA8: lw          $v1, 0x7C84($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X7C84);
    // 0x80054AAC: sll         $v0, $s0, 4
    ctx->r2 = S32(ctx->r16 << 4);
    // 0x80054AB0: addu        $a0, $v0, $v1
    ctx->r4 = ADD32(ctx->r2, ctx->r3);
    // 0x80054AB4: lhu         $v0, 0x6($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X6);
    // 0x80054AB8: andi        $v0, $v0, 0x8000
    ctx->r2 = ctx->r2 & 0X8000;
    // 0x80054ABC: beq         $v0, $zero, L_80054AD0
    if (ctx->r2 == 0) {
        // 0x80054AC0: nop
    
            goto L_80054AD0;
    }
    // 0x80054AC0: nop

    // 0x80054AC4: lw          $a0, 0x0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X0);
    // 0x80054AC8: jal         0x80001C98
    // 0x80054ACC: nop

    rs_free(rdram, ctx);
        goto after_0;
    // 0x80054ACC: nop

    after_0:
L_80054AD0:
    // 0x80054AD0: lw          $v0, 0x7C80($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X7C80);
    // 0x80054AD4: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80054AD8: slt         $v0, $s0, $v0
    ctx->r2 = SIGNED(ctx->r16) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80054ADC: bne         $v0, $zero, L_80054AA8
    if (ctx->r2 != 0) {
        // 0x80054AE0: nop
    
            goto L_80054AA8;
    }
    // 0x80054AE0: nop

L_80054AE4:
    // 0x80054AE4: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80054AE8: lw          $a0, 0x7C84($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X7C84);
    // 0x80054AEC: jal         0x80001C98
    // 0x80054AF0: nop

    rs_free(rdram, ctx);
        goto after_1;
    // 0x80054AF0: nop

    after_1:
    // 0x80054AF4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80054AF8: lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X18);
    // 0x80054AFC: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x80054B00: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x80054B04: jr          $ra
    // 0x80054B08: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80054B08: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_80054B0C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80054B0C: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80054B10: andi        $v1, $a0, 0xFFFF
    ctx->r3 = ctx->r4 & 0XFFFF;
    // 0x80054B14: lw          $v0, 0x7C80($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X7C80);
    // 0x80054B18: mtc1        $a1, $f2
    ctx->f2.u32l = ctx->r5;
    // 0x80054B1C: slt         $v0, $v1, $v0
    ctx->r2 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80054B20: beq         $v0, $zero, L_80054B98
    if (ctx->r2 == 0) {
        // 0x80054B24: lui         $v0, 0x8013
        ctx->r2 = S32(0X8013 << 16);
            goto L_80054B98;
    }
    // 0x80054B24: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80054B28: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80054B2C: lwc1        $f0, -0x5304($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X5304);
    // 0x80054B30: mul.s       $f0, $f2, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x80054B34: sll         $v1, $v1, 4
    ctx->r3 = S32(ctx->r3 << 4);
    // 0x80054B38: lw          $v0, 0x7C84($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X7C84);
    // 0x80054B3C: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80054B40: lwc1        $f2, -0x5300($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X5300);
    // 0x80054B44: c.le.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl <= ctx->f0.fl;
    // 0x80054B48: nop

    // 0x80054B4C: bc1t        L_80054B64
    if (c1cs) {
        // 0x80054B50: addu        $v1, $v1, $v0
        ctx->r3 = ADD32(ctx->r3, ctx->r2);
            goto L_80054B64;
    }
    // 0x80054B50: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x80054B54: trunc.w.s   $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    ctx->f4.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x80054B58: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x80054B5C: j           L_80054B7C
    // 0x80054B60: andi        $v0, $a0, 0xFFFF
    ctx->r2 = ctx->r4 & 0XFFFF;
        goto L_80054B7C;
    // 0x80054B60: andi        $v0, $a0, 0xFFFF
    ctx->r2 = ctx->r4 & 0XFFFF;
L_80054B64:
    // 0x80054B64: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x80054B68: lui         $v0, 0x8000
    ctx->r2 = S32(0X8000 << 16);
    // 0x80054B6C: trunc.w.s   $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    ctx->f4.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x80054B70: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x80054B74: or          $a1, $a1, $v0
    ctx->r5 = ctx->r5 | ctx->r2;
    // 0x80054B78: andi        $v0, $a0, 0xFFFF
    ctx->r2 = ctx->r4 & 0XFFFF;
L_80054B7C:
    // 0x80054B7C: sw          $a1, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r5;
    // 0x80054B80: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x80054B84: lw          $v1, 0x7C84($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X7C84);
    // 0x80054B88: sll         $v0, $v0, 4
    ctx->r2 = S32(ctx->r2 << 4);
    // 0x80054B8C: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80054B90: ori         $v1, $a2, 0xC000
    ctx->r3 = ctx->r6 | 0XC000;
    // 0x80054B94: sh          $v1, 0x6($v0)
    MEM_H(0X6, ctx->r2) = ctx->r3;
L_80054B98:
    // 0x80054B98: jr          $ra
    // 0x80054B9C: nop

    return;
    // 0x80054B9C: nop

;}
RECOMP_FUNC void func_80054BA0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80054BA0: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80054BA4: andi        $v1, $a0, 0xFFFF
    ctx->r3 = ctx->r4 & 0XFFFF;
    // 0x80054BA8: lw          $v0, 0x7C80($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X7C80);
    // 0x80054BAC: mtc1        $a1, $f2
    ctx->f2.u32l = ctx->r5;
    // 0x80054BB0: slt         $v0, $v1, $v0
    ctx->r2 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80054BB4: beq         $v0, $zero, L_80054C10
    if (ctx->r2 == 0) {
        // 0x80054BB8: lui         $v0, 0x8013
        ctx->r2 = S32(0X8013 << 16);
            goto L_80054C10;
    }
    // 0x80054BB8: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80054BBC: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80054BC0: lwc1        $f0, -0x52FC($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X52FC);
    // 0x80054BC4: mul.s       $f0, $f2, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x80054BC8: sll         $v1, $v1, 4
    ctx->r3 = S32(ctx->r3 << 4);
    // 0x80054BCC: lw          $v0, 0x7C84($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X7C84);
    // 0x80054BD0: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80054BD4: lwc1        $f2, -0x52F8($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X52F8);
    // 0x80054BD8: c.le.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl <= ctx->f0.fl;
    // 0x80054BDC: nop

    // 0x80054BE0: bc1t        L_80054BF8
    if (c1cs) {
        // 0x80054BE4: addu        $v1, $v1, $v0
        ctx->r3 = ADD32(ctx->r3, ctx->r2);
            goto L_80054BF8;
    }
    // 0x80054BE4: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x80054BE8: trunc.w.s   $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    ctx->f4.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x80054BEC: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x80054BF0: jr          $ra
    // 0x80054BF4: sw          $a1, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r5;
    return;
    // 0x80054BF4: sw          $a1, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r5;
L_80054BF8:
    // 0x80054BF8: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x80054BFC: lui         $v0, 0x8000
    ctx->r2 = S32(0X8000 << 16);
    // 0x80054C00: trunc.w.s   $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    ctx->f4.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x80054C04: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x80054C08: or          $a1, $a1, $v0
    ctx->r5 = ctx->r5 | ctx->r2;
    // 0x80054C0C: sw          $a1, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r5;
L_80054C10:
    // 0x80054C10: jr          $ra
    // 0x80054C14: nop

    return;
    // 0x80054C14: nop

;}
RECOMP_FUNC void func_80054C18(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80054C18: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    // 0x80054C1C: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80054C20: lw          $v0, 0x7C84($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X7C84);
    // 0x80054C24: sll         $a0, $a0, 4
    ctx->r4 = S32(ctx->r4 << 4);
    // 0x80054C28: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // 0x80054C2C: lw          $v1, 0x8($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X8);
    // 0x80054C30: lh          $v0, 0x4($a0)
    ctx->r2 = MEM_H(ctx->r4, 0X4);
    // 0x80054C34: srl         $v1, $v1, 8
    ctx->r3 = S32(U32(ctx->r3) >> 8);
    // 0x80054C38: divu        $zero, $v1, $v0
    if (U32(ctx->r2) != 0) { lo = S32(U32(ctx->r3) / U32(ctx->r2)); hi = S32(U32(ctx->r3) % U32(ctx->r2)); } else { lo = 0; hi = S32(ctx->r3); }
    // 0x80054C3C: bne         $v0, $zero, L_80054C48
    if (ctx->r2 != 0) {
        // 0x80054C40: nop
    
            goto L_80054C48;
    }
    // 0x80054C40: nop

    // 0x80054C44: break       7
    do_break(2147830852);
L_80054C48:
    // 0x80054C48: mfhi        $v0
    ctx->r2 = hi;
    // 0x80054C4C: jr          $ra
    // 0x80054C50: nop

    return;
    // 0x80054C50: nop

;}
