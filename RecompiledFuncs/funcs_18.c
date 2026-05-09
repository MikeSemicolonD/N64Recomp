#include "recomp.h"
#include "funcs.h"
#include <stdio.h>

RECOMP_FUNC void func_8006FC90(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    {
        static uint32_t last = 0; static int init = 0;
        uint32_t cur = *(uint32_t*)(rdram + 0x3CBC4);
        static int n = 0; ++n;
        if (!init) { init = 1; last = cur; fprintf(stderr, "[wp@FC90 #%d] enter rdram@0x3CBC4=0x%08X\n", n, cur); fflush(stderr); }
        else if (cur != last) { fprintf(stderr, "[wp@FC90 #%d] enter rdram@0x3CBC4 CHANGED 0x%08X->0x%08X\n", n, last, cur); fflush(stderr); last = cur; }
    }
    // 0x8006FC90: addiu       $sp, $sp, -0x70
    ctx->r29 = ADD32(ctx->r29, -0X70);
    // 0x8006FC94: sw          $s1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r17;
    // 0x8006FC98: addu        $s1, $a0, $zero
    ctx->r17 = ADD32(ctx->r4, 0);
    // 0x8006FC9C: sw          $s0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r16;
    // 0x8006FCA0: andi        $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 & 0XFFFF;
    // 0x8006FCA4: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x8006FCA8: sw          $ra, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r31;
    // 0x8006FCAC: sw          $s3, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r19;
    // 0x8006FCB0: sw          $s2, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r18;
    // 0x8006FCB4: sdc1        $f20, 0x68($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X68, ctx->r29);
    // 0x8006FCB8: lw          $s2, 0x4($s1)
    ctx->r18 = MEM_W(ctx->r17, 0X4);
    // 0x8006FCBC: beq         $a1, $v0, L_8006FE04
    if (ctx->r5 == ctx->r2) {
        // 0x8006FCC0: addu        $s0, $a2, $zero
        ctx->r16 = ADD32(ctx->r6, 0);
            goto L_8006FE04;
    }
    // 0x8006FCC0: addu        $s0, $a2, $zero
    ctx->r16 = ADD32(ctx->r6, 0);
    // 0x8006FCC4: slti        $v0, $a1, 0x3
    ctx->r2 = SIGNED(ctx->r5) < 0X3 ? 1 : 0;
    // 0x8006FCC8: beq         $v0, $zero, L_8006FCE0
    if (ctx->r2 == 0) {
        // 0x8006FCCC: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_8006FCE0;
    }
    // 0x8006FCCC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8006FCD0: beq         $a1, $v0, L_8006FCFC
    if (ctx->r5 == ctx->r2) {
        // 0x8006FCD4: addiu       $v1, $s2, 0x4
        ctx->r3 = ADD32(ctx->r18, 0X4);
            goto L_8006FCFC;
    }
    // 0x8006FCD4: addiu       $v1, $s2, 0x4
    ctx->r3 = ADD32(ctx->r18, 0X4);
    // 0x8006FCD8: j           L_80070084
    // 0x8006FCDC: nop

        goto L_80070084;
    // 0x8006FCDC: nop

L_8006FCE0:
    // 0x8006FCE0: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x8006FCE4: beq         $a1, $v0, L_8006FE18
    if (ctx->r5 == ctx->r2) {
        // 0x8006FCE8: addiu       $v0, $zero, 0x4
        ctx->r2 = ADD32(0, 0X4);
            goto L_8006FE18;
    }
    // 0x8006FCE8: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // 0x8006FCEC: beq         $a1, $v0, L_8006FE6C
    if (ctx->r5 == ctx->r2) {
        // 0x8006FCF0: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_8006FE6C;
    }
    // 0x8006FCF0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8006FCF4: j           L_80070088
    // 0x8006FCF8: nop

        goto L_80070088;
    // 0x8006FCF8: nop

L_8006FCFC:
    // 0x8006FCFC: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8006FD00: addiu       $a0, $v0, 0x30
    ctx->r4 = ADD32(ctx->r2, 0X30);
L_8006FD04:
    // 0x8006FD04: lw          $t0, 0x0($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X0);
    // 0x8006FD08: lw          $t1, 0x4($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X4);
    // 0x8006FD0C: lw          $t2, 0x8($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X8);
    // 0x8006FD10: lw          $t3, 0xC($v0)
    ctx->r11 = MEM_W(ctx->r2, 0XC);
    // 0x8006FD14: sw          $t0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r8;
    // 0x8006FD18: sw          $t1, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r9;
    // 0x8006FD1C: sw          $t2, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r10;
    // 0x8006FD20: sw          $t3, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r11;
    // 0x8006FD24: addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
    // 0x8006FD28: bne         $v0, $a0, L_8006FD04
    if (ctx->r2 != ctx->r4) {
        // 0x8006FD2C: addiu       $v1, $v1, 0x10
        ctx->r3 = ADD32(ctx->r3, 0X10);
            goto L_8006FD04;
    }
    // 0x8006FD2C: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
    // 0x8006FD30: addiu       $v0, $s2, 0x4
    ctx->r2 = ADD32(ctx->r18, 0X4);
    // 0x8006FD34: lui         $v1, 0x800A
    ctx->r3 = S32(0X800A << 16);
    // 0x8006FD38: sw          $v0, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->r2;
    // 0x8006FD3C: lw          $v0, 0x8($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X8);
    // 0x8006FD40: addiu       $v1, $v1, 0xA90
    ctx->r3 = ADD32(ctx->r3, 0XA90);
    // 0x8006FD44: sw          $v0, 0x38($s2)
    MEM_W(0X38, ctx->r18) = ctx->r2;
    // 0x8006FD48: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x8006FD4C: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8006FD50: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8006FD54: lw          $a0, 0x0($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X0);
    // 0x8006FD58: jal         0x80057338
    // 0x8006FD5C: nop

    func_80057338(rdram, ctx);
        goto after_0;
    // 0x8006FD5C: nop

    after_0:
    // Patch: hash-table lookup at func_80057338 returns the asset pointer in
    // r2. If it's NULL or out-of-MIPS-range, the original code crashes at
    // MEM_W(r2, 0x64). MIPS pointers in 64-bit ctx are sign-extended:
    // valid pointers have the upper 32 bits = 0xFFFFFFFF (because 0x8xxxxxxx
    // sign-extends that way) or 0x00000000 (NULL). Anything else is garbage.
    {
        uint64_t v = (uint64_t)ctx->r2;
        uint32_t hi32 = (uint32_t)(v >> 32);
        if (v == 0 || (hi32 != 0xFFFFFFFFu && hi32 != 0x00000000u)) {
            static int n = 0; if (++n <= 5) {
                fprintf(stderr, "[patch] func_8006FC90: bogus asset ptr 0x%016llX from func_80057338 — bailing\n",
                    (unsigned long long)v);
                fflush(stderr);
            }
            // Set v0 = 0 (return "not found") and jump to the function epilogue
            // which restores callee-saved regs and sp.
            ctx->r2 = 0;
            goto L_80070088;
        }
    }
    // 0x8006FD60: lui         $a0, 0xF03F
    ctx->r4 = S32(0XF03F << 16);
    // 0x8006FD64: ori         $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 | 0XFFFF;
    // 0x8006FD68: sw          $v0, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r2;
    // 0x8006FD6C: lw          $v1, 0x64($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X64);
    // 0x8006FD70: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8006FD74: lwc1        $f4, -0x3410($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X3410);
    // 0x8006FD78: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8006FD7C: lwc1        $f2, -0x340C($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X340C);
    // 0x8006FD80: and         $v1, $v1, $a0
    ctx->r3 = ctx->r3 & ctx->r4;
    // 0x8006FD84: lui         $a0, 0x900
    ctx->r4 = S32(0X900 << 16);
    // 0x8006FD88: or          $v1, $v1, $a0
    ctx->r3 = ctx->r3 | ctx->r4;
    // 0x8006FD8C: sw          $v1, 0x64($v0)
    MEM_W(0X64, ctx->r2) = ctx->r3;
    // 0x8006FD90: lwc1        $f0, 0xC($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8006FD94: swc1        $f0, 0x3C($s2)
    MEM_W(0X3C, ctx->r18) = ctx->f0.u32l;
    // 0x8006FD98: lwc1        $f0, 0x10($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X10);
    // 0x8006FD9C: lwc1        $f6, 0xC($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8006FDA0: swc1        $f4, 0x44($s2)
    MEM_W(0X44, ctx->r18) = ctx->f4.u32l;
    // 0x8006FDA4: sub.s       $f0, $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f6.fl;
    // 0x8006FDA8: swc1        $f2, 0x4C($s2)
    MEM_W(0X4C, ctx->r18) = ctx->f2.u32l;
    // 0x8006FDAC: sw          $zero, 0x50($s2)
    MEM_W(0X50, ctx->r18) = 0;
    // 0x8006FDB0: swc1        $f0, 0x40($s2)
    MEM_W(0X40, ctx->r18) = ctx->f0.u32l;
    // 0x8006FDB4: lwc1        $f0, 0x14($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X14);
    // 0x8006FDB8: div.s       $f4, $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = DIV_S(ctx->f4.fl, ctx->f0.fl);
    // 0x8006FDBC: swc1        $f4, 0x48($s2)
    MEM_W(0X48, ctx->r18) = ctx->f4.u32l;
    // 0x8006FDC0: lw          $a2, 0x4($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X4);
    // 0x8006FDC4: bne         $a2, $zero, L_8006FDDC
    if (ctx->r6 != 0) {
        // 0x8006FDC8: addiu       $v0, $zero, 0xFF
        ctx->r2 = ADD32(0, 0XFF);
            goto L_8006FDDC;
    }
    // 0x8006FDC8: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // 0x8006FDCC: sb          $v0, 0x34($s2)
    MEM_B(0X34, ctx->r18) = ctx->r2;
    // 0x8006FDD0: sb          $v0, 0x35($s2)
    MEM_B(0X35, ctx->r18) = ctx->r2;
    // 0x8006FDD4: j           L_8006FDEC
    // 0x8006FDD8: sb          $v0, 0x36($s2)
    MEM_B(0X36, ctx->r18) = ctx->r2;
        goto L_8006FDEC;
    // 0x8006FDD8: sb          $v0, 0x36($s2)
    MEM_B(0X36, ctx->r18) = ctx->r2;
L_8006FDDC:
    // 0x8006FDDC: lwl         $t0, 0x0($a2)
    ctx->r8 = do_lwl(rdram, ctx->r8, ctx->r6, 0X0);
    // 0x8006FDE0: lwr         $t0, 0x3($a2)
    ctx->r8 = do_lwr(rdram, ctx->r8, ctx->r6, 0X3);
    // 0x8006FDE4: swl         $t0, 0x34($s2)
    do_swl(rdram, 0X34, ctx->r18, ctx->r8);
    // 0x8006FDE8: swr         $t0, 0x37($s2)
    do_swr(rdram, 0X37, ctx->r18, ctx->r8);
L_8006FDEC:
    // 0x8006FDEC: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x8006FDF0: lhu         $a0, -0x6A8C($v0)
    ctx->r4 = MEM_HU(ctx->r2, -0X6A8C);
    // 0x8006FDF4: jal         0x8003E684
    // 0x8006FDF8: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    func_8003E684(rdram, ctx);
        goto after_1;
    // 0x8006FDF8: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    after_1:
    // 0x8006FDFC: j           L_80070088
    // 0x8006FE00: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80070088;
    // 0x8006FE00: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8006FE04:
    // 0x8006FE04: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    // 0x8006FE08: jal         0x8005779C
    // 0x8006FE0C: nop

    func_8005779C(rdram, ctx);
        goto after_2;
    // 0x8006FE0C: nop

    after_2:
    // 0x8006FE10: j           L_80070088
    // 0x8006FE14: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80070088;
    // 0x8006FE14: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8006FE18:
    // 0x8006FE18: lwc1        $f4, 0x0($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X0);
    // 0x8006FE1C: lwc1        $f0, 0x48($s2)
    ctx->f0.u32l = MEM_W(ctx->r18, 0X48);
    // 0x8006FE20: mul.s       $f0, $f4, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x8006FE24: lwc1        $f2, 0x44($s2)
    ctx->f2.u32l = MEM_W(ctx->r18, 0X44);
    // 0x8006FE28: sub.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl - ctx->f0.fl;
    // 0x8006FE2C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8006FE30: c.le.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl <= ctx->f0.fl;
    // 0x8006FE34: nop

    // 0x8006FE38: bc1f        L_8006FE54
    if (!c1cs) {
        // 0x8006FE3C: swc1        $f2, 0x44($s2)
        MEM_W(0X44, ctx->r18) = ctx->f2.u32l;
            goto L_8006FE54;
    }
    // 0x8006FE3C: swc1        $f2, 0x44($s2)
    MEM_W(0X44, ctx->r18) = ctx->f2.u32l;
    // 0x8006FE40: lhu         $a0, 0x16($s1)
    ctx->r4 = MEM_HU(ctx->r17, 0X16);
    // 0x8006FE44: jal         0x8003ED74
    // 0x8006FE48: nop

    func_8003ED74(rdram, ctx);
        goto after_3;
    // 0x8006FE48: nop

    after_3:
    // 0x8006FE4C: j           L_80070088
    // 0x8006FE50: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80070088;
    // 0x8006FE50: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8006FE54:
    // 0x8006FE54: lwc1        $f2, 0x4C($s2)
    ctx->f2.u32l = MEM_W(ctx->r18, 0X4C);
    // 0x8006FE58: mul.s       $f2, $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f4.fl);
    // 0x8006FE5C: lwc1        $f0, 0x50($s2)
    ctx->f0.u32l = MEM_W(ctx->r18, 0X50);
    // 0x8006FE60: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x8006FE64: j           L_80070084
    // 0x8006FE68: swc1        $f0, 0x50($s2)
    MEM_W(0X50, ctx->r18) = ctx->f0.u32l;
        goto L_80070084;
    // 0x8006FE68: swc1        $f0, 0x50($s2)
    MEM_W(0X50, ctx->r18) = ctx->f0.u32l;
L_8006FE6C:
    // 0x8006FE6C: lwc1        $f2, 0x44($s2)
    ctx->f2.u32l = MEM_W(ctx->r18, 0X44);
    // 0x8006FE70: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8006FE74: lwc1        $f0, -0x3408($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X3408);
    // 0x8006FE78: mul.s       $f0, $f2, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x8006FE7C: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8006FE80: lwc1        $f2, -0x3404($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X3404);
    // 0x8006FE84: c.le.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl <= ctx->f0.fl;
    // 0x8006FE88: nop

    // 0x8006FE8C: bc1t        L_8006FEA4
    if (c1cs) {
        // 0x8006FE90: addu        $s3, $s0, $zero
        ctx->r19 = ADD32(ctx->r16, 0);
            goto L_8006FEA4;
    }
    // 0x8006FE90: addu        $s3, $s0, $zero
    ctx->r19 = ADD32(ctx->r16, 0);
    // 0x8006FE94: trunc.w.s   $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    ctx->f8.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x8006FE98: mfc1        $v1, $f8
    ctx->r3 = (int32_t)ctx->f8.u32l;
    // 0x8006FE9C: j           L_8006FEB8
    // 0x8006FEA0: nop

        goto L_8006FEB8;
    // 0x8006FEA0: nop

L_8006FEA4:
    // 0x8006FEA4: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x8006FEA8: lui         $v0, 0x8000
    ctx->r2 = S32(0X8000 << 16);
    // 0x8006FEAC: trunc.w.s   $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    ctx->f8.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x8006FEB0: mfc1        $v1, $f8
    ctx->r3 = (int32_t)ctx->f8.u32l;
    // 0x8006FEB4: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
L_8006FEB8:
    // 0x8006FEB8: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    // 0x8006FEBC: addiu       $a1, $s2, 0x34
    ctx->r5 = ADD32(ctx->r18, 0X34);
    // 0x8006FEC0: jal         0x80057548
    // 0x8006FEC4: sb          $v1, 0x37($s2)
    MEM_B(0X37, ctx->r18) = ctx->r3;
    func_80057548(rdram, ctx);
        goto after_4;
    // 0x8006FEC4: sb          $v1, 0x37($s2)
    MEM_B(0X37, ctx->r18) = ctx->r3;
    after_4:
    // 0x8006FEC8: lbu         $v1, 0x3B($s2)
    ctx->r3 = MEM_BU(ctx->r18, 0X3B);
    // 0x8006FECC: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x8006FED0: bne         $v1, $v0, L_8006FF04
    if (ctx->r3 != ctx->r2) {
        // 0x8006FED4: addiu       $v0, $zero, 0x3
        ctx->r2 = ADD32(0, 0X3);
            goto L_8006FF04;
    }
    // 0x8006FED4: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x8006FED8: lwc1        $f0, 0x44($s2)
    ctx->f0.u32l = MEM_W(ctx->r18, 0X44);
    // 0x8006FEDC: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8006FEE0: lwc1        $f2, -0x3400($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X3400);
    // 0x8006FEE4: sub.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl - ctx->f0.fl;
    // 0x8006FEE8: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8006FEEC: lwc1        $f0, -0x33FC($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X33FC);
    // 0x8006FEF0: mul.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x8006FEF4: ori         $a1, $zero, 0xFFFF
    ctx->r5 = 0 | 0XFFFF;
    // 0x8006FEF8: lui         $v1, 0x8014
    ctx->r3 = S32(0X8014 << 16);
    // 0x8006FEFC: j           L_8006FF30
    // 0x8006FF00: addiu       $v1, $v1, -0x6790
    ctx->r3 = ADD32(ctx->r3, -0X6790);
        goto L_8006FF30;
    // 0x8006FF00: addiu       $v1, $v1, -0x6790
    ctx->r3 = ADD32(ctx->r3, -0X6790);
L_8006FF04:
    // 0x8006FF04: bne         $v1, $v0, L_8006FF50
    if (ctx->r3 != ctx->r2) {
        // 0x8006FF08: ori         $a1, $zero, 0xFFFF
        ctx->r5 = 0 | 0XFFFF;
            goto L_8006FF50;
    }
    // 0x8006FF08: ori         $a1, $zero, 0xFFFF
    ctx->r5 = 0 | 0XFFFF;
    // 0x8006FF0C: lwc1        $f0, 0x44($s2)
    ctx->f0.u32l = MEM_W(ctx->r18, 0X44);
    // 0x8006FF10: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8006FF14: lwc1        $f2, -0x33F8($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X33F8);
    // 0x8006FF18: sub.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl - ctx->f0.fl;
    // 0x8006FF1C: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8006FF20: lwc1        $f0, -0x33F4($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X33F4);
    // 0x8006FF24: mul.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x8006FF28: lui         $v1, 0x8014
    ctx->r3 = S32(0X8014 << 16);
    // 0x8006FF2C: addiu       $v1, $v1, -0x6700
    ctx->r3 = ADD32(ctx->r3, -0X6700);
L_8006FF30:
    // 0x8006FF30: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    // 0x8006FF34: trunc.w.s   $f8, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    ctx->f8.u32l = TRUNC_W_S(ctx->f2.fl);
    // 0x8006FF38: mfc1        $v0, $f8
    ctx->r2 = (int32_t)ctx->f8.u32l;
    // 0x8006FF3C: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x8006FF40: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8006FF44: lhu         $a2, 0x0($v0)
    ctx->r6 = MEM_HU(ctx->r2, 0X0);
    // 0x8006FF48: jal         0x800595A0
    // 0x8006FF4C: addiu       $a0, $a0, 0x58
    ctx->r4 = ADD32(ctx->r4, 0X58);
    func_800595A0(rdram, ctx);
        goto after_5;
    // 0x8006FF4C: addiu       $a0, $a0, 0x58
    ctx->r4 = ADD32(ctx->r4, 0X58);
    after_5:
L_8006FF50:
    // 0x8006FF50: lw          $v0, 0x38($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X38);
    // 0x8006FF54: andi        $v0, $v0, 0x8000
    ctx->r2 = ctx->r2 & 0X8000;
    // 0x8006FF58: bne         $v0, $zero, L_8006FF8C
    if (ctx->r2 != 0) {
        // 0x8006FF5C: nop
    
            goto L_8006FF8C;
    }
    // 0x8006FF5C: nop

    // 0x8006FF60: lwc1        $f0, 0x44($s2)
    ctx->f0.u32l = MEM_W(ctx->r18, 0X44);
    // 0x8006FF64: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8006FF68: lwc1        $f12, -0x33F0($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X33F0);
    // 0x8006FF6C: sub.s       $f12, $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = ctx->f12.fl - ctx->f0.fl;
    // 0x8006FF70: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8006FF74: lwc1        $f0, -0x33EC($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X33EC);
    // 0x8006FF78: mul.s       $f12, $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = MUL_S(ctx->f12.fl, ctx->f0.fl);
    // 0x8006FF7C: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8006FF80: lwc1        $f0, -0x33E8($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X33E8);
    // 0x8006FF84: j           L_8006FFBC
    // 0x8006FF88: nop

        goto L_8006FFBC;
    // 0x8006FF88: nop

L_8006FF8C:
    // 0x8006FF8C: lwc1        $f2, 0x44($s2)
    ctx->f2.u32l = MEM_W(ctx->r18, 0X44);
    // 0x8006FF90: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8006FF94: lwc1        $f0, -0x33E4($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X33E4);
    // 0x8006FF98: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x8006FF9C: nop

    // 0x8006FFA0: bc1f        L_8006FFDC
    if (!c1cs) {
        // 0x8006FFA4: nop
    
            goto L_8006FFDC;
    }
    // 0x8006FFA4: nop

    // 0x8006FFA8: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8006FFAC: lwc1        $f12, -0x33E0($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X33E0);
    // 0x8006FFB0: sub.s       $f12, $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f12.fl = ctx->f12.fl - ctx->f2.fl;
    // 0x8006FFB4: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8006FFB8: lwc1        $f0, -0x33DC($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X33DC);
L_8006FFBC:
    // 0x8006FFBC: mul.s       $f12, $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = MUL_S(ctx->f12.fl, ctx->f0.fl);
    // 0x8006FFC0: jal         0x80033960
    // 0x8006FFC4: nop

    sinf_recomp(rdram, ctx);
        goto after_6;
    // 0x8006FFC4: nop

    after_6:
    // 0x8006FFC8: lwc1        $f2, 0x40($s2)
    ctx->f2.u32l = MEM_W(ctx->r18, 0X40);
    // 0x8006FFCC: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x8006FFD0: lwc1        $f2, 0x3C($s2)
    ctx->f2.u32l = MEM_W(ctx->r18, 0X3C);
    // 0x8006FFD4: j           L_8007000C
    // 0x8006FFD8: add.s       $f20, $f2, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f20.fl = ctx->f2.fl + ctx->f0.fl;
        goto L_8007000C;
    // 0x8006FFD8: add.s       $f20, $f2, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f20.fl = ctx->f2.fl + ctx->f0.fl;
L_8006FFDC:
    // 0x8006FFDC: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8006FFE0: lwc1        $f12, -0x33D8($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X33D8);
    // 0x8006FFE4: sub.s       $f12, $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f12.fl = ctx->f12.fl - ctx->f2.fl;
    // 0x8006FFE8: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8006FFEC: lwc1        $f0, -0x33D4($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X33D4);
    // 0x8006FFF0: mul.s       $f12, $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = MUL_S(ctx->f12.fl, ctx->f0.fl);
    // 0x8006FFF4: jal         0x80033960
    // 0x8006FFF8: nop

    sinf_recomp(rdram, ctx);
        goto after_7;
    // 0x8006FFF8: nop

    after_7:
    // 0x8006FFFC: lwc1        $f2, 0x3C($s2)
    ctx->f2.u32l = MEM_W(ctx->r18, 0X3C);
    // 0x80070000: lwc1        $f4, 0x40($s2)
    ctx->f4.u32l = MEM_W(ctx->r18, 0X40);
    // 0x80070004: add.s       $f2, $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f4.fl;
    // 0x80070008: mul.s       $f20, $f0, $f2
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f20.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
L_8007000C:
    // 0x8007000C: lwc1        $f0, 0x28($s2)
    ctx->f0.u32l = MEM_W(ctx->r18, 0X28);
    // 0x80070010: mul.s       $f0, $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f20.fl);
    // 0x80070014: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    // 0x80070018: lwc1        $f0, 0x2C($s2)
    ctx->f0.u32l = MEM_W(ctx->r18, 0X2C);
    // 0x8007001C: mul.s       $f0, $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f20.fl);
    // 0x80070020: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    // 0x80070024: lwc1        $f0, 0x30($s2)
    ctx->f0.u32l = MEM_W(ctx->r18, 0X30);
    // 0x80070028: mul.s       $f0, $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f20.fl);
    // 0x8007002C: addiu       $s1, $s2, 0x4
    ctx->r17 = ADD32(ctx->r18, 0X4);
    // 0x80070030: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    // 0x80070034: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    // 0x80070038: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    // 0x8007003C: addiu       $a2, $sp, 0x10
    ctx->r6 = ADD32(ctx->r29, 0X10);
    // 0x80070040: jal         0x80059C24
    // 0x80070044: addiu       $a0, $a0, 0x28
    ctx->r4 = ADD32(ctx->r4, 0X28);
    func_80059C24(rdram, ctx);
        goto after_8;
    // 0x80070044: addiu       $a0, $a0, 0x28
    ctx->r4 = ADD32(ctx->r4, 0X28);
    after_8:
    // 0x80070048: addiu       $s0, $sp, 0x20
    ctx->r16 = ADD32(ctx->r29, 0X20);
    // 0x8007004C: lw          $a1, 0x50($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X50);
    // 0x80070050: jal         0x8001CD6C
    // 0x80070054: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_8001CD6C(rdram, ctx);
        goto after_9;
    // 0x80070054: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_9:
    // 0x80070058: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    // 0x8007005C: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x80070060: addiu       $a0, $a0, 0x28
    ctx->r4 = ADD32(ctx->r4, 0X28);
    // 0x80070064: jal         0x800191C4
    // 0x80070068: addu        $a2, $a0, $zero
    ctx->r6 = ADD32(ctx->r4, 0);
    func_800191C4(rdram, ctx);
        goto after_10;
    // 0x80070068: addu        $a2, $a0, $zero
    ctx->r6 = ADD32(ctx->r4, 0);
    after_10:
    // 0x8007006C: add.s       $f20, $f20, $f20
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f20.fl = ctx->f20.fl + ctx->f20.fl;
    // 0x80070070: lw          $a0, 0x0($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X0);
    // 0x80070074: lw          $a1, 0x0($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X0);
    // 0x80070078: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x8007007C: jal         0x80057C8C
    // 0x80070080: addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    func_80057C8C(rdram, ctx);
        goto after_11;
    // 0x80070080: addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    after_11:
L_80070084:
    // 0x80070084: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80070088:
    // 0x80070088: lw          $ra, 0x60($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X60);
    // 0x8007008C: lw          $s3, 0x5C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X5C);
    // 0x80070090: lw          $s2, 0x58($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X58);
    // 0x80070094: lw          $s1, 0x54($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X54);
    // 0x80070098: lw          $s0, 0x50($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X50);
    // 0x8007009C: ldc1        $f20, 0x68($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X68);
    // 0x800700A0: jr          $ra
    // 0x800700A4: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
    return;
    // 0x800700A4: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
;}
RECOMP_FUNC void func_800700A8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800700A8: addiu       $sp, $sp, -0xD8
    ctx->r29 = ADD32(ctx->r29, -0XD8);
    // 0x800700AC: sw          $s4, 0xC0($sp)
    MEM_W(0XC0, ctx->r29) = ctx->r20;
    // 0x800700B0: addu        $s4, $a0, $zero
    ctx->r20 = ADD32(ctx->r4, 0);
    // 0x800700B4: sw          $s3, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->r19;
    // 0x800700B8: andi        $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 & 0XFFFF;
    // 0x800700BC: addiu       $v1, $a1, -0x1
    ctx->r3 = ADD32(ctx->r5, -0X1);
    // 0x800700C0: sltiu       $v0, $v1, 0xC
    ctx->r2 = ctx->r3 < 0XC ? 1 : 0;
    // 0x800700C4: sw          $ra, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->r31;
    // 0x800700C8: sw          $s2, 0xB8($sp)
    MEM_W(0XB8, ctx->r29) = ctx->r18;
    // 0x800700CC: sw          $s1, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->r17;
    // 0x800700D0: sw          $s0, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->r16;
    // 0x800700D4: sdc1        $f22, 0xD0($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0XD0, ctx->r29);
    // 0x800700D8: sdc1        $f20, 0xC8($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0XC8, ctx->r29);
    // 0x800700DC: lw          $s1, 0x4($s4)
    ctx->r17 = MEM_W(ctx->r20, 0X4);
    // 0x800700E0: beq         $v0, $zero, L_80071038
    if (ctx->r2 == 0) {
        // 0x800700E4: addu        $s3, $a2, $zero
        ctx->r19 = ADD32(ctx->r6, 0);
            goto L_80071038;
    }
    // 0x800700E4: addu        $s3, $a2, $zero
    ctx->r19 = ADD32(ctx->r6, 0);
    // 0x800700E8: lui         $v0, 0x8004
    ctx->r2 = S32(0X8004 << 16);
    // 0x800700EC: addiu       $v0, $v0, -0x33D0
    ctx->r2 = ADD32(ctx->r2, -0X33D0);
    // 0x800700F0: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x800700F4: addu        $v1, $v1, $v0
    gpr jr_addend_800700FC = ctx->r3;
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x800700F8: lw          $v0, 0x0($v1)
    ctx->r2 = ADD32(ctx->r3, 0X0);
    // 0x800700FC: jr          $v0
    // 0x80070100: nop

    switch (jr_addend_800700FC >> 2) {
        case 0: goto L_80070104; break;
        case 1: goto L_800702B4; break;
        case 2: goto L_800702E0; break;
        case 3: goto L_800704B4; break;
        case 4: goto L_80071038; break;
        case 5: goto L_80071038; break;
        case 6: goto L_80071038; break;
        case 7: goto L_80071038; break;
        case 8: goto L_80071038; break;
        case 9: goto L_80071038; break;
        case 10: goto L_80071038; break;
        case 11: goto L_800702D4; break;
        default: switch_error(__func__, 0x800700FC, 0x8003CC30);
    }
    // 0x80070100: nop

L_80070104:
    // 0x80070104: addiu       $a0, $zero, 0x2E0
    ctx->r4 = ADD32(0, 0X2E0);
    // 0x80070108: jal         0x80001ACC
    // 0x8007010C: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    rs_malloc(rdram, ctx);
        goto after_0;
    // 0x8007010C: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    after_0:
    // 0x80070110: addu        $s1, $v0, $zero
    ctx->r17 = ADD32(ctx->r2, 0);
    // 0x80070114: sw          $s1, 0x4($s4)
    MEM_W(0X4, ctx->r20) = ctx->r17;
    // 0x80070118: lbu         $v0, 0x18($s3)
    ctx->r2 = MEM_BU(ctx->r19, 0X18);
    // 0x8007011C: bne         $v0, $zero, L_80070138
    if (ctx->r2 != 0) {
        // 0x80070120: addiu       $v0, $zero, -0x1
        ctx->r2 = ADD32(0, -0X1);
            goto L_80070138;
    }
    // 0x80070120: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x80070124: lhu         $a1, 0x0($s3)
    ctx->r5 = MEM_HU(ctx->r19, 0X0);
    // 0x80070128: jal         0x80040188
    // 0x8007012C: ori         $a0, $zero, 0xFFFF
    ctx->r4 = 0 | 0XFFFF;
    func_80040188(rdram, ctx);
        goto after_1;
    // 0x8007012C: ori         $a0, $zero, 0xFFFF
    ctx->r4 = 0 | 0XFFFF;
    after_1:
    // 0x80070130: j           L_8007013C
    // 0x80070134: addiu       $a0, $s1, 0x3C
    ctx->r4 = ADD32(ctx->r17, 0X3C);
        goto L_8007013C;
    // 0x80070134: addiu       $a0, $s1, 0x3C
    ctx->r4 = ADD32(ctx->r17, 0X3C);
L_80070138:
    // 0x80070138: addiu       $a0, $s1, 0x3C
    ctx->r4 = ADD32(ctx->r17, 0X3C);
L_8007013C:
    // 0x8007013C: lui         $a1, 0x8014
    ctx->r5 = S32(0X8014 << 16);
    // 0x80070140: addiu       $a1, $a1, -0x5990
    ctx->r5 = ADD32(ctx->r5, -0X5990);
    // 0x80070144: sh          $v0, 0x0($s1)
    MEM_H(0X0, ctx->r17) = ctx->r2;
    // 0x80070148: lhu         $v0, 0x0($s3)
    ctx->r2 = MEM_HU(ctx->r19, 0X0);
    // 0x8007014C: addiu       $a2, $zero, 0x224
    ctx->r6 = ADD32(0, 0X224);
    // 0x80070150: jal         0x80018EF4
    // 0x80070154: sh          $v0, 0x2($s1)
    MEM_H(0X2, ctx->r17) = ctx->r2;
    zmemcpy(rdram, ctx);
        goto after_2;
    // 0x80070154: sh          $v0, 0x2($s1)
    MEM_H(0X2, ctx->r17) = ctx->r2;
    after_2:
    // 0x80070158: addiu       $v0, $s1, 0x88
    ctx->r2 = ADD32(ctx->r17, 0X88);
    // 0x8007015C: sw          $v0, 0x4C($s1)
    MEM_W(0X4C, ctx->r17) = ctx->r2;
    // 0x80070160: addiu       $v0, $s1, 0xE4
    ctx->r2 = ADD32(ctx->r17, 0XE4);
    // 0x80070164: sw          $v0, 0xA8($s1)
    MEM_W(0XA8, ctx->r17) = ctx->r2;
    // 0x80070168: addiu       $v0, $s1, 0x260
    ctx->r2 = ADD32(ctx->r17, 0X260);
    // 0x8007016C: sw          $v0, 0xAC($s1)
    MEM_W(0XAC, ctx->r17) = ctx->r2;
    // 0x80070170: addiu       $v0, $s1, 0xF4
    ctx->r2 = ADD32(ctx->r17, 0XF4);
    // 0x80070174: sw          $v0, 0xEC($s1)
    MEM_W(0XEC, ctx->r17) = ctx->r2;
    // 0x80070178: lw          $v0, 0x14($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X14);
    // 0x8007017C: bne         $v0, $zero, L_800701A0
    if (ctx->r2 != 0) {
        // 0x80070180: nop
    
            goto L_800701A0;
    }
    // 0x80070180: nop

    // 0x80070184: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // 0x80070188: sb          $v0, 0x36($s1)
    MEM_B(0X36, ctx->r17) = ctx->r2;
    // 0x8007018C: sb          $v0, 0x35($s1)
    MEM_B(0X35, ctx->r17) = ctx->r2;
    // 0x80070190: sb          $v0, 0x34($s1)
    MEM_B(0X34, ctx->r17) = ctx->r2;
    // 0x80070194: addiu       $v0, $zero, 0x80
    ctx->r2 = ADD32(0, 0X80);
    // 0x80070198: j           L_800701B0
    // 0x8007019C: sb          $v0, 0x37($s1)
    MEM_B(0X37, ctx->r17) = ctx->r2;
        goto L_800701B0;
    // 0x8007019C: sb          $v0, 0x37($s1)
    MEM_B(0X37, ctx->r17) = ctx->r2;
L_800701A0:
    // 0x800701A0: lwl         $t2, 0x0($v0)
    ctx->r10 = do_lwl(rdram, ctx->r10, ctx->r2, 0X0);
    // 0x800701A4: lwr         $t2, 0x3($v0)
    ctx->r10 = do_lwr(rdram, ctx->r10, ctx->r2, 0X3);
    // 0x800701A8: swl         $t2, 0x34($s1)
    do_swl(rdram, 0X34, ctx->r17, ctx->r10);
    // 0x800701AC: swr         $t2, 0x37($s1)
    do_swr(rdram, 0X37, ctx->r17, ctx->r10);
L_800701B0:
    // 0x800701B0: addu        $s2, $zero, $zero
    ctx->r18 = ADD32(0, 0);
    // 0x800701B4: addiu       $v1, $s1, 0x124
    ctx->r3 = ADD32(ctx->r17, 0X124);
L_800701B8:
    // 0x800701B8: lwl         $t2, 0x34($s1)
    ctx->r10 = do_lwl(rdram, ctx->r10, ctx->r17, 0X34);
    // 0x800701BC: lwr         $t2, 0x37($s1)
    ctx->r10 = do_lwr(rdram, ctx->r10, ctx->r17, 0X37);
    // 0x800701C0: swl         $t2, -0xC($v1)
    do_swl(rdram, -0XC, ctx->r3, ctx->r10);
    // 0x800701C4: swr         $t2, -0x9($v1)
    do_swr(rdram, -0X9, ctx->r3, ctx->r10);
    // 0x800701C8: lwl         $t2, 0x34($s1)
    ctx->r10 = do_lwl(rdram, ctx->r10, ctx->r17, 0X34);
    // 0x800701CC: lwr         $t2, 0x37($s1)
    ctx->r10 = do_lwr(rdram, ctx->r10, ctx->r17, 0X37);
    // 0x800701D0: swl         $t2, -0x8($v1)
    do_swl(rdram, -0X8, ctx->r3, ctx->r10);
    // 0x800701D4: swr         $t2, -0x5($v1)
    do_swr(rdram, -0X5, ctx->r3, ctx->r10);
    // 0x800701D8: lwl         $t2, 0x34($s1)
    ctx->r10 = do_lwl(rdram, ctx->r10, ctx->r17, 0X34);
    // 0x800701DC: lwr         $t2, 0x37($s1)
    ctx->r10 = do_lwr(rdram, ctx->r10, ctx->r17, 0X37);
    // 0x800701E0: swl         $t2, -0x4($v1)
    do_swl(rdram, -0X4, ctx->r3, ctx->r10);
    // 0x800701E4: swr         $t2, -0x1($v1)
    do_swr(rdram, -0X1, ctx->r3, ctx->r10);
    // 0x800701E8: lwl         $t2, 0x34($s1)
    ctx->r10 = do_lwl(rdram, ctx->r10, ctx->r17, 0X34);
    // 0x800701EC: lwr         $t2, 0x37($s1)
    ctx->r10 = do_lwr(rdram, ctx->r10, ctx->r17, 0X37);
    // 0x800701F0: swl         $t2, 0x0($v1)
    do_swl(rdram, 0X0, ctx->r3, ctx->r10);
    // 0x800701F4: swr         $t2, 0x3($v1)
    do_swr(rdram, 0X3, ctx->r3, ctx->r10);
    // 0x800701F8: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x800701FC: slti        $v0, $s2, 0x7
    ctx->r2 = SIGNED(ctx->r18) < 0X7 ? 1 : 0;
    // 0x80070200: bne         $v0, $zero, L_800701B8
    if (ctx->r2 != 0) {
        // 0x80070204: addiu       $v1, $v1, 0x34
        ctx->r3 = ADD32(ctx->r3, 0X34);
            goto L_800701B8;
    }
    // 0x80070204: addiu       $v1, $v1, 0x34
    ctx->r3 = ADD32(ctx->r3, 0X34);
    // 0x80070208: sb          $zero, 0x8($s1)
    MEM_B(0X8, ctx->r17) = 0;
    // 0x8007020C: sb          $zero, 0x9($s1)
    MEM_B(0X9, ctx->r17) = 0;
    // 0x80070210: sb          $zero, 0xA($s1)
    MEM_B(0XA, ctx->r17) = 0;
    // 0x80070214: lbu         $v0, 0x19($s3)
    ctx->r2 = MEM_BU(ctx->r19, 0X19);
    // 0x80070218: beq         $v0, $zero, L_80070224
    if (ctx->r2 == 0) {
        // 0x8007021C: addu        $v1, $zero, $zero
        ctx->r3 = ADD32(0, 0);
            goto L_80070224;
    }
    // 0x8007021C: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
    // 0x80070220: lw          $v1, 0x14($s3)
    ctx->r3 = MEM_W(ctx->r19, 0X14);
L_80070224:
    // 0x80070224: addiu       $v0, $zero, 0x6
    ctx->r2 = ADD32(0, 0X6);
    // 0x80070228: sw          $v1, 0x38($s1)
    MEM_W(0X38, ctx->r17) = ctx->r3;
    // 0x8007022C: sh          $zero, 0x4($s1)
    MEM_H(0X4, ctx->r17) = 0;
    // 0x80070230: sh          $v0, 0x6($s1)
    MEM_H(0X6, ctx->r17) = ctx->r2;
    // 0x80070234: lwc1        $f0, 0xC($s3)
    ctx->f0.u32l = MEM_W(ctx->r19, 0XC);
    // 0x80070238: swc1        $f0, 0x10($s1)
    MEM_W(0X10, ctx->r17) = ctx->f0.u32l;
    // 0x8007023C: lw          $v0, 0x8($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X8);
    // 0x80070240: sw          $v0, 0xC($s1)
    MEM_W(0XC, ctx->r17) = ctx->r2;
    // 0x80070244: lbu         $v0, 0x4($s3)
    ctx->r2 = MEM_BU(ctx->r19, 0X4);
    // 0x80070248: sb          $v0, 0xB($s1)
    MEM_B(0XB, ctx->r17) = ctx->r2;
    // 0x8007024C: lw          $v0, 0x10($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X10);
    // 0x80070250: beql        $v0, $zero, L_80070274
    if (ctx->r2 == 0) {
        // 0x80070254: sw          $zero, 0x14($s1)
        MEM_W(0X14, ctx->r17) = 0;
            goto L_80070274;
    }
    goto skip_0;
    // 0x80070254: sw          $zero, 0x14($s1)
    MEM_W(0X14, ctx->r17) = 0;
    skip_0:
    // 0x80070258: lw          $t2, 0x0($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X0);
    // 0x8007025C: lw          $t3, 0x4($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X4);
    // 0x80070260: lw          $t4, 0x8($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X8);
    // 0x80070264: sw          $t2, 0x28($s1)
    MEM_W(0X28, ctx->r17) = ctx->r10;
    // 0x80070268: sw          $t3, 0x2C($s1)
    MEM_W(0X2C, ctx->r17) = ctx->r11;
    // 0x8007026C: sw          $t4, 0x30($s1)
    MEM_W(0X30, ctx->r17) = ctx->r12;
    // 0x80070270: sw          $zero, 0x14($s1)
    MEM_W(0X14, ctx->r17) = 0;
L_80070274:
    // 0x80070274: lh          $v0, 0x2($s3)
    ctx->r2 = MEM_H(ctx->r19, 0X2);
    // 0x80070278: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8007027C: lwc1        $f0, -0x33A0($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X33A0);
    // 0x80070280: mtc1        $v0, $f2
    ctx->f2.u32l = ctx->r2;
    // 0x80070284: cvt.s.w     $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    ctx->f2.fl = CVT_S_W(ctx->f2.u32l);
    // 0x80070288: div.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f2.fl);
    // 0x8007028C: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x80070290: swc1        $f0, 0x18($s1)
    MEM_W(0X18, ctx->r17) = ctx->f0.u32l;
    // 0x80070294: lhu         $a0, -0x6A8C($v0)
    ctx->r4 = MEM_HU(ctx->r2, -0X6A8C);
    // 0x80070298: jal         0x8003E684
    // 0x8007029C: addu        $a1, $s4, $zero
    ctx->r5 = ADD32(ctx->r20, 0);
    func_8003E684(rdram, ctx);
        goto after_3;
    // 0x8007029C: addu        $a1, $s4, $zero
    ctx->r5 = ADD32(ctx->r20, 0);
    after_3:
    // 0x800702A0: lui         $v1, 0x8014
    ctx->r3 = S32(0X8014 << 16);
    // 0x800702A4: lw          $v0, -0x576C($v1)
    ctx->r2 = MEM_W(ctx->r3, -0X576C);
    // 0x800702A8: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800702AC: j           L_80071038
    // 0x800702B0: sw          $v0, -0x576C($v1)
    MEM_W(-0X576C, ctx->r3) = ctx->r2;
        goto L_80071038;
    // 0x800702B0: sw          $v0, -0x576C($v1)
    MEM_W(-0X576C, ctx->r3) = ctx->r2;
L_800702B4:
    // 0x800702B4: lhu         $a0, 0x0($s1)
    ctx->r4 = MEM_HU(ctx->r17, 0X0);
    // 0x800702B8: jal         0x8003F0C8
    // 0x800702BC: nop

    func_8003F0C8(rdram, ctx);
        goto after_4;
    // 0x800702BC: nop

    after_4:
    // 0x800702C0: lui         $v1, 0x8014
    ctx->r3 = S32(0X8014 << 16);
    // 0x800702C4: lw          $v0, -0x576C($v1)
    ctx->r2 = MEM_W(ctx->r3, -0X576C);
    // 0x800702C8: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x800702CC: j           L_80071038
    // 0x800702D0: sw          $v0, -0x576C($v1)
    MEM_W(-0X576C, ctx->r3) = ctx->r2;
        goto L_80071038;
    // 0x800702D0: sw          $v0, -0x576C($v1)
    MEM_W(-0X576C, ctx->r3) = ctx->r2;
L_800702D4:
    // 0x800702D4: addiu       $v0, $zero, 0x80
    ctx->r2 = ADD32(0, 0X80);
    // 0x800702D8: j           L_80071038
    // 0x800702DC: sb          $v0, 0xA($s1)
    MEM_B(0XA, ctx->r17) = ctx->r2;
        goto L_80071038;
    // 0x800702DC: sb          $v0, 0xA($s1)
    MEM_B(0XA, ctx->r17) = ctx->r2;
L_800702E0:
    // 0x800702E0: lbu         $v0, 0x9($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X9);
    // 0x800702E4: bne         $v0, $zero, L_8007030C
    if (ctx->r2 != 0) {
        // 0x800702E8: ori         $s0, $zero, 0xFFFF
        ctx->r16 = 0 | 0XFFFF;
            goto L_8007030C;
    }
    // 0x800702E8: ori         $s0, $zero, 0xFFFF
    ctx->r16 = 0 | 0XFFFF;
    // 0x800702EC: lhu         $v0, 0x0($s1)
    ctx->r2 = MEM_HU(ctx->r17, 0X0);
    // 0x800702F0: beq         $v0, $s0, L_80070338
    if (ctx->r2 == ctx->r16) {
        // 0x800702F4: nop
    
            goto L_80070338;
    }
    // 0x800702F4: nop

    // 0x800702F8: jal         0x80040218
    // 0x800702FC: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    func_80040218(rdram, ctx);
        goto after_5;
    // 0x800702FC: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    after_5:
    // 0x80070300: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x80070304: bne         $v0, $s0, L_80070338
    if (ctx->r2 != ctx->r16) {
        // 0x80070308: nop
    
            goto L_80070338;
    }
    // 0x80070308: nop

L_8007030C:
    // 0x8007030C: lhu         $v0, 0x6($s1)
    ctx->r2 = MEM_HU(ctx->r17, 0X6);
    // 0x80070310: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x80070314: sh          $v0, 0x6($s1)
    MEM_H(0X6, ctx->r17) = ctx->r2;
    // 0x80070318: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x8007031C: bne         $v0, $zero, L_8007103C
    if (ctx->r2 != 0) {
        // 0x80070320: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_8007103C;
    }
    // 0x80070320: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80070324:
    // 0x80070324: lhu         $a0, 0x16($s4)
    ctx->r4 = MEM_HU(ctx->r20, 0X16);
    // 0x80070328: jal         0x8003ED74
    // 0x8007032C: nop

    func_8003ED74(rdram, ctx);
        goto after_6;
    // 0x8007032C: nop

    after_6:
    // 0x80070330: j           L_8007103C
    // 0x80070334: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8007103C;
    // 0x80070334: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80070338:
    // 0x80070338: lwc1        $f2, 0x18($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0X18);
    // 0x8007033C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80070340: sb          $v0, 0x8($s1)
    MEM_B(0X8, ctx->r17) = ctx->r2;
    // 0x80070344: lwc1        $f0, 0x0($s3)
    ctx->f0.u32l = MEM_W(ctx->r19, 0X0);
    // 0x80070348: mul.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x8007034C: lwc1        $f0, 0x14($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X14);
    // 0x80070350: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x80070354: lbu         $v0, 0xA($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0XA);
    // 0x80070358: beq         $v0, $zero, L_80071038
    if (ctx->r2 == 0) {
        // 0x8007035C: swc1        $f0, 0x14($s1)
        MEM_W(0X14, ctx->r17) = ctx->f0.u32l;
            goto L_80071038;
    }
    // 0x8007035C: swc1        $f0, 0x14($s1)
    MEM_W(0X14, ctx->r17) = ctx->f0.u32l;
    // 0x80070360: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x80070364: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x80070368: add.s       $f0, $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f0.fl;
    // 0x8007036C: lwc1        $f2, 0x0($s3)
    ctx->f2.u32l = MEM_W(ctx->r19, 0X0);
    // 0x80070370: mul.s       $f6, $f0, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x80070374: lbu         $v0, 0x11B($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X11B);
    // 0x80070378: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x8007037C: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x80070380: c.le.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl <= ctx->f6.fl;
    // 0x80070384: nop

    // 0x80070388: bc1t        L_80070324
    if (c1cs) {
        // 0x8007038C: addiu       $s2, $zero, 0x7
        ctx->r18 = ADD32(0, 0X7);
            goto L_80070324;
    }
    // 0x8007038C: addiu       $s2, $zero, 0x7
    ctx->r18 = ADD32(0, 0X7);
    // 0x80070390: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80070394: lwc1        $f2, -0x339C($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X339C);
    // 0x80070398: lui         $a1, 0x8000
    ctx->r5 = S32(0X8000 << 16);
    // 0x8007039C: addiu       $a0, $s1, 0x127
    ctx->r4 = ADD32(ctx->r17, 0X127);
L_800703A0:
    // 0x800703A0: lbu         $v0, -0xC($a0)
    ctx->r2 = MEM_BU(ctx->r4, -0XC);
    // 0x800703A4: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x800703A8: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x800703AC: sub.s       $f0, $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f6.fl;
    // 0x800703B0: c.le.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl <= ctx->f0.fl;
    // 0x800703B4: nop

    // 0x800703B8: bc1tl       L_800703D0
    if (c1cs) {
        // 0x800703BC: sub.s       $f0, $f0, $f2
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
            goto L_800703D0;
    }
    goto skip_1;
    // 0x800703BC: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    skip_1:
    // 0x800703C0: trunc.w.s   $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800703C4: mfc1        $v1, $f22
    ctx->r3 = (int32_t)ctx->f22.u32l;
    // 0x800703C8: j           L_800703DC
    // 0x800703CC: nop

        goto L_800703DC;
    // 0x800703CC: nop

L_800703D0:
    // 0x800703D0: trunc.w.s   $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800703D4: mfc1        $v1, $f22
    ctx->r3 = (int32_t)ctx->f22.u32l;
    // 0x800703D8: or          $v1, $v1, $a1
    ctx->r3 = ctx->r3 | ctx->r5;
L_800703DC:
    // 0x800703DC: lbu         $v0, -0x8($a0)
    ctx->r2 = MEM_BU(ctx->r4, -0X8);
    // 0x800703E0: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x800703E4: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x800703E8: sub.s       $f0, $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f6.fl;
    // 0x800703EC: c.le.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl <= ctx->f0.fl;
    // 0x800703F0: nop

    // 0x800703F4: bc1t        L_8007040C
    if (c1cs) {
        // 0x800703F8: sb          $v1, -0xC($a0)
        MEM_B(-0XC, ctx->r4) = ctx->r3;
            goto L_8007040C;
    }
    // 0x800703F8: sb          $v1, -0xC($a0)
    MEM_B(-0XC, ctx->r4) = ctx->r3;
    // 0x800703FC: trunc.w.s   $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x80070400: mfc1        $v1, $f22
    ctx->r3 = (int32_t)ctx->f22.u32l;
    // 0x80070404: j           L_8007041C
    // 0x80070408: nop

        goto L_8007041C;
    // 0x80070408: nop

L_8007040C:
    // 0x8007040C: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x80070410: trunc.w.s   $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x80070414: mfc1        $v1, $f22
    ctx->r3 = (int32_t)ctx->f22.u32l;
    // 0x80070418: or          $v1, $v1, $a1
    ctx->r3 = ctx->r3 | ctx->r5;
L_8007041C:
    // 0x8007041C: lbu         $v0, -0x4($a0)
    ctx->r2 = MEM_BU(ctx->r4, -0X4);
    // 0x80070420: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x80070424: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x80070428: sub.s       $f0, $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f6.fl;
    // 0x8007042C: c.le.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl <= ctx->f0.fl;
    // 0x80070430: nop

    // 0x80070434: bc1t        L_8007044C
    if (c1cs) {
        // 0x80070438: sb          $v1, -0x8($a0)
        MEM_B(-0X8, ctx->r4) = ctx->r3;
            goto L_8007044C;
    }
    // 0x80070438: sb          $v1, -0x8($a0)
    MEM_B(-0X8, ctx->r4) = ctx->r3;
    // 0x8007043C: trunc.w.s   $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x80070440: mfc1        $v1, $f22
    ctx->r3 = (int32_t)ctx->f22.u32l;
    // 0x80070444: j           L_8007045C
    // 0x80070448: nop

        goto L_8007045C;
    // 0x80070448: nop

L_8007044C:
    // 0x8007044C: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x80070450: trunc.w.s   $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x80070454: mfc1        $v1, $f22
    ctx->r3 = (int32_t)ctx->f22.u32l;
    // 0x80070458: or          $v1, $v1, $a1
    ctx->r3 = ctx->r3 | ctx->r5;
L_8007045C:
    // 0x8007045C: lbu         $v0, 0x0($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X0);
    // 0x80070460: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x80070464: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x80070468: sub.s       $f0, $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f6.fl;
    // 0x8007046C: c.le.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl <= ctx->f0.fl;
    // 0x80070470: nop

    // 0x80070474: bc1t        L_8007048C
    if (c1cs) {
        // 0x80070478: sb          $v1, -0x4($a0)
        MEM_B(-0X4, ctx->r4) = ctx->r3;
            goto L_8007048C;
    }
    // 0x80070478: sb          $v1, -0x4($a0)
    MEM_B(-0X4, ctx->r4) = ctx->r3;
    // 0x8007047C: trunc.w.s   $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x80070480: mfc1        $v0, $f22
    ctx->r2 = (int32_t)ctx->f22.u32l;
    // 0x80070484: j           L_800704A0
    // 0x80070488: sb          $v0, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r2;
        goto L_800704A0;
    // 0x80070488: sb          $v0, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r2;
L_8007048C:
    // 0x8007048C: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x80070490: trunc.w.s   $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x80070494: mfc1        $v0, $f22
    ctx->r2 = (int32_t)ctx->f22.u32l;
    // 0x80070498: or          $v0, $v0, $a1
    ctx->r2 = ctx->r2 | ctx->r5;
    // 0x8007049C: sb          $v0, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r2;
L_800704A0:
    // 0x800704A0: addiu       $s2, $s2, -0x1
    ctx->r18 = ADD32(ctx->r18, -0X1);
    // 0x800704A4: bgtz        $s2, L_800703A0
    if (SIGNED(ctx->r18) > 0) {
        // 0x800704A8: addiu       $a0, $a0, 0x34
        ctx->r4 = ADD32(ctx->r4, 0X34);
            goto L_800703A0;
    }
    // 0x800704A8: addiu       $a0, $a0, 0x34
    ctx->r4 = ADD32(ctx->r4, 0X34);
    // 0x800704AC: j           L_8007103C
    // 0x800704B0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8007103C;
    // 0x800704B0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800704B4:
    // 0x800704B4: lbu         $v0, 0x8($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X8);
    // 0x800704B8: beq         $v0, $zero, L_80070CAC
    if (ctx->r2 == 0) {
        // 0x800704BC: addu        $s4, $s3, $zero
        ctx->r20 = ADD32(ctx->r19, 0);
            goto L_80070CAC;
    }
    // 0x800704BC: addu        $s4, $s3, $zero
    ctx->r20 = ADD32(ctx->r19, 0);
    // 0x800704C0: lhu         $v0, 0x0($s1)
    ctx->r2 = MEM_HU(ctx->r17, 0X0);
    // 0x800704C4: ori         $s0, $zero, 0xFFFF
    ctx->r16 = 0 | 0XFFFF;
    // 0x800704C8: beq         $v0, $s0, L_80070500
    if (ctx->r2 == ctx->r16) {
        // 0x800704CC: nop
    
            goto L_80070500;
    }
    // 0x800704CC: nop

    // 0x800704D0: jal         0x80040218
    // 0x800704D4: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    func_80040218(rdram, ctx);
        goto after_7;
    // 0x800704D4: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    after_7:
    // 0x800704D8: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x800704DC: beq         $v0, $s0, L_80070CAC
    if (ctx->r2 == ctx->r16) {
        // 0x800704E0: nop
    
            goto L_80070CAC;
    }
    // 0x800704E0: nop

    // 0x800704E4: lhu         $v0, 0x0($s1)
    ctx->r2 = MEM_HU(ctx->r17, 0X0);
    // 0x800704E8: beq         $v0, $s0, L_80070500
    if (ctx->r2 == ctx->r16) {
        // 0x800704EC: nop
    
            goto L_80070500;
    }
    // 0x800704EC: nop

    // 0x800704F0: jal         0x80040218
    // 0x800704F4: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    func_80040218(rdram, ctx);
        goto after_8;
    // 0x800704F4: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    after_8:
    // 0x800704F8: j           L_80070504
    // 0x800704FC: andi        $a0, $v0, 0xFFFF
    ctx->r4 = ctx->r2 & 0XFFFF;
        goto L_80070504;
    // 0x800704FC: andi        $a0, $v0, 0xFFFF
    ctx->r4 = ctx->r2 & 0XFFFF;
L_80070500:
    // 0x80070500: lhu         $a0, 0x2($s1)
    ctx->r4 = MEM_HU(ctx->r17, 0X2);
L_80070504:
    // 0x80070504: jal         0x8004015C
    // 0x80070508: nop

    func_8004015C(rdram, ctx);
        goto after_9;
    // 0x80070508: nop

    after_9:
    // 0x8007050C: addu        $s2, $v0, $zero
    ctx->r18 = ADD32(ctx->r2, 0);
    // 0x80070510: beq         $s2, $zero, L_80070CAC
    if (ctx->r18 == 0) {
        // 0x80070514: nop
    
            goto L_80070CAC;
    }
    // 0x80070514: nop

    // 0x80070518: lhu         $v0, 0x4($s1)
    ctx->r2 = MEM_HU(ctx->r17, 0X4);
    // 0x8007051C: bne         $v0, $zero, L_80070550
    if (ctx->r2 != 0) {
        // 0x80070520: nop
    
            goto L_80070550;
    }
    // 0x80070520: nop

    // 0x80070524: lw          $t3, 0x0($s2)
    ctx->r11 = MEM_W(ctx->r18, 0X0);
    // 0x80070528: lw          $t4, 0x4($s2)
    ctx->r12 = MEM_W(ctx->r18, 0X4);
    // 0x8007052C: lw          $t5, 0x8($s2)
    ctx->r13 = MEM_W(ctx->r18, 0X8);
    // 0x80070530: sw          $t3, 0x1C($s1)
    MEM_W(0X1C, ctx->r17) = ctx->r11;
    // 0x80070534: sw          $t4, 0x20($s1)
    MEM_W(0X20, ctx->r17) = ctx->r12;
    // 0x80070538: sw          $t5, 0x24($s1)
    MEM_W(0X24, ctx->r17) = ctx->r13;
    // 0x8007053C: lw          $a1, 0x1C($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X1C);
    // 0x80070540: lw          $a2, 0x20($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X20);
    // 0x80070544: lw          $a3, 0x24($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X24);
    // 0x80070548: jal         0x8001CAC4
    // 0x8007054C: addiu       $a0, $s1, 0x58
    ctx->r4 = ADD32(ctx->r17, 0X58);
    func_8001CAC4(rdram, ctx);
        goto after_10;
    // 0x8007054C: addiu       $a0, $s1, 0x58
    ctx->r4 = ADD32(ctx->r17, 0X58);
    after_10:
L_80070550:
    // 0x80070550: lw          $v0, 0xC($s1)
    ctx->r2 = MEM_W(ctx->r17, 0XC);
    // 0x80070554: bltz        $v0, L_800705D8
    if (SIGNED(ctx->r2) < 0) {
        // 0x80070558: ori         $v0, $zero, 0xFFFF
        ctx->r2 = 0 | 0XFFFF;
            goto L_800705D8;
    }
    // 0x80070558: ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
    // 0x8007055C: lhu         $v1, 0x0($s1)
    ctx->r3 = MEM_HU(ctx->r17, 0X0);
    // 0x80070560: beq         $v1, $v0, L_80070578
    if (ctx->r3 == ctx->r2) {
        // 0x80070564: nop
    
            goto L_80070578;
    }
    // 0x80070564: nop

    // 0x80070568: jal         0x80040218
    // 0x8007056C: addu        $a0, $v1, $zero
    ctx->r4 = ADD32(ctx->r3, 0);
    func_80040218(rdram, ctx);
        goto after_11;
    // 0x8007056C: addu        $a0, $v1, $zero
    ctx->r4 = ADD32(ctx->r3, 0);
    after_11:
    // 0x80070570: j           L_8007057C
    // 0x80070574: andi        $a0, $v0, 0xFFFF
    ctx->r4 = ctx->r2 & 0XFFFF;
        goto L_8007057C;
    // 0x80070574: andi        $a0, $v0, 0xFFFF
    ctx->r4 = ctx->r2 & 0XFFFF;
L_80070578:
    // 0x80070578: lhu         $a0, 0x2($s1)
    ctx->r4 = MEM_HU(ctx->r17, 0X2);
L_8007057C:
    // 0x8007057C: jal         0x8004013C
    // 0x80070580: nop

    func_8004013C(rdram, ctx);
        goto after_12;
    // 0x80070580: nop

    after_12:
    // 0x80070584: lw          $a0, 0xC($v0)
    ctx->r4 = MEM_W(ctx->r2, 0XC);
    // 0x80070588: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x8007058C: addiu       $a3, $s1, 0xC
    ctx->r7 = ADD32(ctx->r17, 0XC);
    // 0x80070590: lbu         $a2, 0xB($s1)
    ctx->r6 = MEM_BU(ctx->r17, 0XB);
    // 0x80070594: addiu       $v0, $sp, 0x20
    ctx->r2 = ADD32(ctx->r29, 0X20);
    // 0x80070598: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // 0x8007059C: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x800705A0: jal         0x8005857C
    // 0x800705A4: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    func_8005857C(rdram, ctx);
        goto after_13;
    // 0x800705A4: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    after_13:
    // 0x800705A8: addiu       $a0, $sp, 0x70
    ctx->r4 = ADD32(ctx->r29, 0X70);
    // 0x800705AC: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    // 0x800705B0: jal         0x80019548
    // 0x800705B4: addiu       $a2, $sp, 0x38
    ctx->r6 = ADD32(ctx->r29, 0X38);
    func_80019548(rdram, ctx);
        goto after_14;
    // 0x800705B4: addiu       $a2, $sp, 0x38
    ctx->r6 = ADD32(ctx->r29, 0X38);
    after_14:
    // 0x800705B8: lw          $t3, 0x20($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X20);
    // 0x800705BC: lw          $t4, 0x24($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X24);
    // 0x800705C0: lw          $t5, 0x28($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X28);
    // 0x800705C4: sw          $t3, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r11;
    // 0x800705C8: sw          $t4, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r12;
    // 0x800705CC: sw          $t5, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r13;
    // 0x800705D0: j           L_80070688
    // 0x800705D4: nop

        goto L_80070688;
    // 0x800705D4: nop

L_800705D8:
    // 0x800705D8: addiu       $s0, $sp, 0x80
    ctx->r16 = ADD32(ctx->r29, 0X80);
    // 0x800705DC: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x800705E0: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x800705E4: jal         0x80059B50
    // 0x800705E8: addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    func_80059B50(rdram, ctx);
        goto after_15;
    // 0x800705E8: addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    after_15:
    // 0x800705EC: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x800705F0: addiu       $a1, $s1, 0x28
    ctx->r5 = ADD32(ctx->r17, 0X28);
    // 0x800705F4: jal         0x800193E8
    // 0x800705F8: addiu       $a2, $sp, 0x60
    ctx->r6 = ADD32(ctx->r29, 0X60);
    func_800193E8(rdram, ctx);
        goto after_16;
    // 0x800705F8: addiu       $a2, $sp, 0x60
    ctx->r6 = ADD32(ctx->r29, 0X60);
    after_16:
    // 0x800705FC: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x80070600: lw          $v0, -0x72E4($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X72E4);
    // 0x80070604: lwc1        $f0, 0x60($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X60);
    // 0x80070608: lwc1        $f2, 0x4C($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X4C);
    // 0x8007060C: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x80070610: swc1        $f0, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->f0.u32l;
    // 0x80070614: lwc1        $f0, 0x64($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X64);
    // 0x80070618: lwc1        $f2, 0x50($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X50);
    // 0x8007061C: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x80070620: addiu       $s0, $sp, 0x70
    ctx->r16 = ADD32(ctx->r29, 0X70);
    // 0x80070624: swc1        $f0, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->f0.u32l;
    // 0x80070628: lwc1        $f0, 0x68($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X68);
    // 0x8007062C: lwc1        $f2, 0x54($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X54);
    // 0x80070630: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x80070634: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x80070638: addiu       $a1, $s2, 0xC
    ctx->r5 = ADD32(ctx->r18, 0XC);
    // 0x8007063C: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    // 0x80070640: jal         0x80019548
    // 0x80070644: swc1        $f0, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->f0.u32l;
    func_80019548(rdram, ctx);
        goto after_17;
    // 0x80070644: swc1        $f0, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->f0.u32l;
    after_17:
    // 0x80070648: jal         0x8001CF58
    // 0x8007064C: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    normalize_vector(rdram, ctx);
        goto after_18;
    // 0x8007064C: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_18:
    // 0x80070650: lwc1        $f2, 0x70($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X70);
    // 0x80070654: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80070658: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x8007065C: nop

    // 0x80070660: bc1f        L_80070688
    if (!c1cs) {
        // 0x80070664: nop
    
            goto L_80070688;
    }
    // 0x80070664: nop

    // 0x80070668: neg.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = -ctx->f2.fl;
    // 0x8007066C: swc1        $f0, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->f0.u32l;
    // 0x80070670: lwc1        $f0, 0x74($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X74);
    // 0x80070674: lwc1        $f2, 0x78($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X78);
    // 0x80070678: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
    // 0x8007067C: neg.s       $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = -ctx->f2.fl;
    // 0x80070680: swc1        $f0, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->f0.u32l;
    // 0x80070684: swc1        $f2, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->f2.u32l;
L_80070688:
    // 0x80070688: lwc1        $f2, 0x60($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X60);
    // 0x8007068C: lwc1        $f0, 0x1C($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X1C);
    // 0x80070690: sub.s       $f8, $f2, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f2.fl - ctx->f0.fl;
    // 0x80070694: lwc1        $f2, 0x64($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X64);
    // 0x80070698: mul.s       $f4, $f8, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f8.fl);
    // 0x8007069C: swc1        $f8, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f8.u32l;
    // 0x800706A0: lwc1        $f0, 0x20($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X20);
    // 0x800706A4: sub.s       $f10, $f2, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f2.fl - ctx->f0.fl;
    // 0x800706A8: lwc1        $f2, 0x68($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X68);
    // 0x800706AC: mul.s       $f6, $f10, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = MUL_S(ctx->f10.fl, ctx->f10.fl);
    // 0x800706B0: swc1        $f10, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f10.u32l;
    // 0x800706B4: lwc1        $f0, 0x24($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X24);
    // 0x800706B8: sub.s       $f12, $f2, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = ctx->f2.fl - ctx->f0.fl;
    // 0x800706BC: mul.s       $f0, $f12, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = MUL_S(ctx->f12.fl, ctx->f12.fl);
    // 0x800706C0: add.s       $f4, $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x800706C4: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x800706C8: lwc1        $f2, -0x3398($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X3398);
    // 0x800706CC: add.s       $f4, $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f0.fl;
    // 0x800706D0: c.lt.s      $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f2.fl < ctx->f4.fl;
    // 0x800706D4: nop

    // 0x800706D8: bc1f        L_80070808
    if (!c1cs) {
        // 0x800706DC: swc1        $f12, 0x68($sp)
        MEM_W(0X68, ctx->r29) = ctx->f12.u32l;
            goto L_80070808;
    }
    // 0x800706DC: swc1        $f12, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f12.u32l;
    // 0x800706E0: lwc1        $f0, 0x0($s2)
    ctx->f0.u32l = MEM_W(ctx->r18, 0X0);
    // 0x800706E4: lwc1        $f2, 0x1C($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0X1C);
    // 0x800706E8: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x800706EC: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x800706F0: lwc1        $f4, -0x3394($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X3394);
    // 0x800706F4: mul.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x800706F8: swc1        $f0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f0.u32l;
    // 0x800706FC: lwc1        $f0, 0x4($s2)
    ctx->f0.u32l = MEM_W(ctx->r18, 0X4);
    // 0x80070700: lwc1        $f2, 0x20($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0X20);
    // 0x80070704: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x80070708: mul.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x8007070C: swc1        $f0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f0.u32l;
    // 0x80070710: lwc1        $f0, 0x8($s2)
    ctx->f0.u32l = MEM_W(ctx->r18, 0X8);
    // 0x80070714: lwc1        $f2, 0x24($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0X24);
    // 0x80070718: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x8007071C: mul.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x80070720: swc1        $f0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f0.u32l;
    // 0x80070724: lwc1        $f0, 0x0($s2)
    ctx->f0.u32l = MEM_W(ctx->r18, 0X0);
    // 0x80070728: lwc1        $f2, 0x1C($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0X1C);
    // 0x8007072C: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x80070730: sub.s       $f0, $f8, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f8.fl - ctx->f0.fl;
    // 0x80070734: swc1        $f0, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f0.u32l;
    // 0x80070738: lwc1        $f0, 0x4($s2)
    ctx->f0.u32l = MEM_W(ctx->r18, 0X4);
    // 0x8007073C: lwc1        $f2, 0x20($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0X20);
    // 0x80070740: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x80070744: sub.s       $f0, $f10, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f10.fl - ctx->f0.fl;
    // 0x80070748: swc1        $f0, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f0.u32l;
    // 0x8007074C: lwc1        $f0, 0x8($s2)
    ctx->f0.u32l = MEM_W(ctx->r18, 0X8);
    // 0x80070750: lwc1        $f2, 0x24($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0X24);
    // 0x80070754: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x80070758: sub.s       $f0, $f12, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f12.fl - ctx->f0.fl;
    // 0x8007075C: addiu       $s0, $s1, 0x260
    ctx->r16 = ADD32(ctx->r17, 0X260);
    // 0x80070760: addiu       $a0, $s1, 0x58
    ctx->r4 = ADD32(ctx->r17, 0X58);
    // 0x80070764: swc1        $f0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f0.u32l;
    // 0x80070768: lw          $t3, 0x0($s2)
    ctx->r11 = MEM_W(ctx->r18, 0X0);
    // 0x8007076C: lw          $t4, 0x4($s2)
    ctx->r12 = MEM_W(ctx->r18, 0X4);
    // 0x80070770: lw          $t5, 0x8($s2)
    ctx->r13 = MEM_W(ctx->r18, 0X8);
    // 0x80070774: sw          $t3, 0x1C($s1)
    MEM_W(0X1C, ctx->r17) = ctx->r11;
    // 0x80070778: sw          $t4, 0x20($s1)
    MEM_W(0X20, ctx->r17) = ctx->r12;
    // 0x8007077C: sw          $t5, 0x24($s1)
    MEM_W(0X24, ctx->r17) = ctx->r13;
    // 0x80070780: lw          $a1, 0x1C($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X1C);
    // 0x80070784: lw          $a2, 0x20($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X20);
    // 0x80070788: lw          $a3, 0x24($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X24);
    // 0x8007078C: jal         0x8001CAC4
    // 0x80070790: addiu       $s3, $zero, 0x10
    ctx->r19 = ADD32(0, 0X10);
    func_8001CAC4(rdram, ctx);
        goto after_19;
    // 0x80070790: addiu       $s3, $zero, 0x10
    ctx->r19 = ADD32(0, 0X10);
    after_19:
    // 0x80070794: addiu       $v1, $s1, 0x264
    ctx->r3 = ADD32(ctx->r17, 0X264);
L_80070798:
    // 0x80070798: lh          $v0, 0x0($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X0);
    // 0x8007079C: lwc1        $f2, 0x20($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X20);
    // 0x800707A0: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x800707A4: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x800707A8: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x800707AC: trunc.w.s   $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800707B0: mfc1        $v0, $f22
    ctx->r2 = (int32_t)ctx->f22.u32l;
    // 0x800707B4: sh          $v0, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r2;
    // 0x800707B8: lh          $v0, -0x2($v1)
    ctx->r2 = MEM_H(ctx->r3, -0X2);
    // 0x800707BC: lwc1        $f2, 0x24($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X24);
    // 0x800707C0: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x800707C4: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x800707C8: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x800707CC: trunc.w.s   $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800707D0: mfc1        $v0, $f22
    ctx->r2 = (int32_t)ctx->f22.u32l;
    // 0x800707D4: sh          $v0, -0x2($v1)
    MEM_H(-0X2, ctx->r3) = ctx->r2;
    // 0x800707D8: lh          $v0, 0x0($v1)
    ctx->r2 = MEM_H(ctx->r3, 0X0);
    // 0x800707DC: lwc1        $f2, 0x28($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X28);
    // 0x800707E0: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x800707E4: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x800707E8: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x800707EC: addiu       $s3, $s3, -0x1
    ctx->r19 = ADD32(ctx->r19, -0X1);
    // 0x800707F0: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x800707F4: trunc.w.s   $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800707F8: mfc1        $v0, $f22
    ctx->r2 = (int32_t)ctx->f22.u32l;
    // 0x800707FC: sh          $v0, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r2;
    // 0x80070800: bgtz        $s3, L_80070798
    if (SIGNED(ctx->r19) > 0) {
        // 0x80070804: addiu       $v1, $v1, 0x8
        ctx->r3 = ADD32(ctx->r3, 0X8);
            goto L_80070798;
    }
    // 0x80070804: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
L_80070808:
    // 0x80070808: lwc1        $f2, 0x70($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X70);
    // 0x8007080C: lwc1        $f0, 0x10($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X10);
    // 0x80070810: mul.s       $f4, $f2, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x80070814: lwc1        $f0, 0x74($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X74);
    // 0x80070818: swc1        $f4, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->f4.u32l;
    // 0x8007081C: lwc1        $f2, 0x10($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0X10);
    // 0x80070820: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x80070824: swc1        $f0, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->f0.u32l;
    // 0x80070828: lwc1        $f0, 0x78($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X78);
    // 0x8007082C: lwc1        $f2, 0x10($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0X10);
    // 0x80070830: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x80070834: swc1        $f0, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->f0.u32l;
    // 0x80070838: lhu         $v0, 0x4($s1)
    ctx->r2 = MEM_HU(ctx->r17, 0X4);
    // 0x8007083C: bne         $v0, $zero, L_80070904
    if (ctx->r2 != 0) {
        // 0x80070840: addiu       $s0, $s1, 0x260
        ctx->r16 = ADD32(ctx->r17, 0X260);
            goto L_80070904;
    }
    // 0x80070840: addiu       $s0, $s1, 0x260
    ctx->r16 = ADD32(ctx->r17, 0X260);
    // 0x80070844: lwc1        $f0, 0x60($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X60);
    // 0x80070848: sub.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f4.fl;
    // 0x8007084C: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80070850: lwc1        $f4, -0x3390($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X3390);
    // 0x80070854: mul.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x80070858: trunc.w.s   $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x8007085C: mfc1        $v0, $f22
    ctx->r2 = (int32_t)ctx->f22.u32l;
    // 0x80070860: sh          $v0, 0x260($s1)
    MEM_H(0X260, ctx->r17) = ctx->r2;
    // 0x80070864: lwc1        $f0, 0x64($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X64);
    // 0x80070868: lwc1        $f2, 0x74($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X74);
    // 0x8007086C: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x80070870: mul.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x80070874: trunc.w.s   $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x80070878: mfc1        $v0, $f22
    ctx->r2 = (int32_t)ctx->f22.u32l;
    // 0x8007087C: sh          $v0, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r2;
    // 0x80070880: lwc1        $f0, 0x68($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X68);
    // 0x80070884: lwc1        $f2, 0x78($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X78);
    // 0x80070888: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x8007088C: mul.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x80070890: trunc.w.s   $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x80070894: mfc1        $v0, $f22
    ctx->r2 = (int32_t)ctx->f22.u32l;
    // 0x80070898: sh          $v0, 0x4($s0)
    MEM_H(0X4, ctx->r16) = ctx->r2;
    // 0x8007089C: lwc1        $f0, 0x60($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X60);
    // 0x800708A0: lwc1        $f2, 0x70($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X70);
    // 0x800708A4: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x800708A8: mul.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x800708AC: trunc.w.s   $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800708B0: mfc1        $v0, $f22
    ctx->r2 = (int32_t)ctx->f22.u32l;
    // 0x800708B4: sh          $v0, 0x8($s0)
    MEM_H(0X8, ctx->r16) = ctx->r2;
    // 0x800708B8: lwc1        $f0, 0x64($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X64);
    // 0x800708BC: lwc1        $f2, 0x74($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X74);
    // 0x800708C0: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x800708C4: mul.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x800708C8: trunc.w.s   $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800708CC: mfc1        $v0, $f22
    ctx->r2 = (int32_t)ctx->f22.u32l;
    // 0x800708D0: sh          $v0, 0xA($s0)
    MEM_H(0XA, ctx->r16) = ctx->r2;
    // 0x800708D4: lwc1        $f0, 0x68($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X68);
    // 0x800708D8: lwc1        $f2, 0x78($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X78);
    // 0x800708DC: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x800708E0: mul.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x800708E4: trunc.w.s   $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800708E8: mfc1        $v0, $f22
    ctx->r2 = (int32_t)ctx->f22.u32l;
    // 0x800708EC: sh          $v0, 0xC($s0)
    MEM_H(0XC, ctx->r16) = ctx->r2;
    // 0x800708F0: lhu         $v0, 0x4($s1)
    ctx->r2 = MEM_HU(ctx->r17, 0X4);
    // 0x800708F4: sw          $zero, 0x14($s1)
    MEM_W(0X14, ctx->r17) = 0;
    // 0x800708F8: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800708FC: j           L_80070BCC
    // 0x80070900: sh          $v0, 0x4($s1)
    MEM_H(0X4, ctx->r17) = ctx->r2;
        goto L_80070BCC;
    // 0x80070900: sh          $v0, 0x4($s1)
    MEM_H(0X4, ctx->r17) = ctx->r2;
L_80070904:
    // 0x80070904: lwc1        $f0, 0x14($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X14);
    // 0x80070908: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8007090C: lwc1        $f20, -0x338C($at)
    ctx->f20.u32l = MEM_W(ctx->r1, -0X338C);
    // 0x80070910: c.lt.s      $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f20.fl < ctx->f0.fl;
    // 0x80070914: nop

    // 0x80070918: bc1f        L_80070BCC
    if (!c1cs) {
        // 0x8007091C: nop
    
            goto L_80070BCC;
    }
    // 0x8007091C: nop

    // 0x80070920: lhu         $a0, 0x4($s1)
    ctx->r4 = MEM_HU(ctx->r17, 0X4);
    // 0x80070924: addiu       $v1, $a0, -0x1
    ctx->r3 = ADD32(ctx->r4, -0X1);
    // 0x80070928: bgez        $v1, L_80070934
    if (SIGNED(ctx->r3) >= 0) {
        // 0x8007092C: addu        $v0, $v1, $zero
        ctx->r2 = ADD32(ctx->r3, 0);
            goto L_80070934;
    }
    // 0x8007092C: addu        $v0, $v1, $zero
    ctx->r2 = ADD32(ctx->r3, 0);
    // 0x80070930: addiu       $v0, $a0, 0x6
    ctx->r2 = ADD32(ctx->r4, 0X6);
L_80070934:
    // 0x80070934: sra         $v0, $v0, 3
    ctx->r2 = S32(SIGNED(ctx->r2) >> 3);
    // 0x80070938: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x8007093C: subu        $v0, $v1, $v0
    ctx->r2 = SUB32(ctx->r3, ctx->r2);
    // 0x80070940: sll         $v0, $v0, 4
    ctx->r2 = S32(ctx->r2 << 4);
    // 0x80070944: addu        $v0, $s1, $v0
    ctx->r2 = ADD32(ctx->r17, ctx->r2);
    // 0x80070948: lwl         $t3, 0x260($v0)
    ctx->r11 = do_lwl(rdram, ctx->r11, ctx->r2, 0X260);
    // 0x8007094C: lwr         $t3, 0x263($v0)
    ctx->r11 = do_lwr(rdram, ctx->r11, ctx->r2, 0X263);
    // 0x80070950: lwl         $t4, 0x264($v0)
    ctx->r12 = do_lwl(rdram, ctx->r12, ctx->r2, 0X264);
    // 0x80070954: lwr         $t4, 0x267($v0)
    ctx->r12 = do_lwr(rdram, ctx->r12, ctx->r2, 0X267);
    // 0x80070958: swl         $t3, 0x50($sp)
    do_swl(rdram, 0X50, ctx->r29, ctx->r11);
    // 0x8007095C: swr         $t3, 0x53($sp)
    do_swr(rdram, 0X53, ctx->r29, ctx->r11);
    // 0x80070960: swl         $t4, 0x54($sp)
    do_swl(rdram, 0X54, ctx->r29, ctx->r12);
    // 0x80070964: swr         $t4, 0x57($sp)
    do_swr(rdram, 0X57, ctx->r29, ctx->r12);
    // 0x80070968: lhu         $a0, 0x4($s1)
    ctx->r4 = MEM_HU(ctx->r17, 0X4);
    // 0x8007096C: addiu       $v1, $a0, -0x1
    ctx->r3 = ADD32(ctx->r4, -0X1);
    // 0x80070970: bgez        $v1, L_8007097C
    if (SIGNED(ctx->r3) >= 0) {
        // 0x80070974: addu        $v0, $v1, $zero
        ctx->r2 = ADD32(ctx->r3, 0);
            goto L_8007097C;
    }
    // 0x80070974: addu        $v0, $v1, $zero
    ctx->r2 = ADD32(ctx->r3, 0);
    // 0x80070978: addiu       $v0, $a0, 0x6
    ctx->r2 = ADD32(ctx->r4, 0X6);
L_8007097C:
    // 0x8007097C: sra         $v0, $v0, 3
    ctx->r2 = S32(SIGNED(ctx->r2) >> 3);
    // 0x80070980: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x80070984: subu        $v0, $v1, $v0
    ctx->r2 = SUB32(ctx->r3, ctx->r2);
    // 0x80070988: sll         $v0, $v0, 4
    ctx->r2 = S32(ctx->r2 << 4);
    // 0x8007098C: ori         $v0, $v0, 0x8
    ctx->r2 = ctx->r2 | 0X8;
    // 0x80070990: addu        $v0, $s1, $v0
    ctx->r2 = ADD32(ctx->r17, ctx->r2);
    // 0x80070994: lwl         $t3, 0x260($v0)
    ctx->r11 = do_lwl(rdram, ctx->r11, ctx->r2, 0X260);
    // 0x80070998: lwr         $t3, 0x263($v0)
    ctx->r11 = do_lwr(rdram, ctx->r11, ctx->r2, 0X263);
    // 0x8007099C: lwl         $t4, 0x264($v0)
    ctx->r12 = do_lwl(rdram, ctx->r12, ctx->r2, 0X264);
    // 0x800709A0: lwr         $t4, 0x267($v0)
    ctx->r12 = do_lwr(rdram, ctx->r12, ctx->r2, 0X267);
    // 0x800709A4: swl         $t3, 0x58($sp)
    do_swl(rdram, 0X58, ctx->r29, ctx->r11);
    // 0x800709A8: swr         $t3, 0x5B($sp)
    do_swr(rdram, 0X5B, ctx->r29, ctx->r11);
    // 0x800709AC: swl         $t4, 0x5C($sp)
    do_swl(rdram, 0X5C, ctx->r29, ctx->r12);
    // 0x800709B0: swr         $t4, 0x5F($sp)
    do_swr(rdram, 0X5F, ctx->r29, ctx->r12);
    // 0x800709B4: lwc1        $f6, 0x60($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X60);
    // 0x800709B8: lwc1        $f16, 0x70($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X70);
    // 0x800709BC: sub.s       $f12, $f6, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = ctx->f6.fl - ctx->f16.fl;
    // 0x800709C0: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x800709C4: lwc1        $f8, -0x3388($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X3388);
    // 0x800709C8: mul.s       $f12, $f12, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = MUL_S(ctx->f12.fl, ctx->f8.fl);
    // 0x800709CC: lwc1        $f4, 0x64($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X64);
    // 0x800709D0: lwc1        $f0, 0x74($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X74);
    // 0x800709D4: sub.s       $f10, $f4, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f4.fl - ctx->f0.fl;
    // 0x800709D8: mul.s       $f10, $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f10.fl, ctx->f8.fl);
    // 0x800709DC: lwc1        $f2, 0x68($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X68);
    // 0x800709E0: lwc1        $f18, 0x78($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X78);
    // 0x800709E4: sub.s       $f14, $f2, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f14.fl = ctx->f2.fl - ctx->f18.fl;
    // 0x800709E8: mul.s       $f14, $f14, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f14.fl = MUL_S(ctx->f14.fl, ctx->f8.fl);
    // 0x800709EC: add.s       $f6, $f6, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f16.fl;
    // 0x800709F0: mul.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x800709F4: add.s       $f4, $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f0.fl;
    // 0x800709F8: mul.s       $f4, $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = MUL_S(ctx->f4.fl, ctx->f8.fl);
    // 0x800709FC: add.s       $f2, $f2, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f18.fl;
    // 0x80070A00: mul.s       $f2, $f2, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f8.fl);
    // 0x80070A04: lh          $v0, 0x50($sp)
    ctx->r2 = MEM_H(ctx->r29, 0X50);
    // 0x80070A08: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x80070A0C: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x80070A10: lh          $v0, 0x52($sp)
    ctx->r2 = MEM_H(ctx->r29, 0X52);
    // 0x80070A14: sub.s       $f12, $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = ctx->f12.fl - ctx->f0.fl;
    // 0x80070A18: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x80070A1C: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x80070A20: lh          $v0, 0x54($sp)
    ctx->r2 = MEM_H(ctx->r29, 0X54);
    // 0x80070A24: sub.s       $f10, $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f10.fl - ctx->f0.fl;
    // 0x80070A28: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x80070A2C: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x80070A30: lh          $v0, 0x58($sp)
    ctx->r2 = MEM_H(ctx->r29, 0X58);
    // 0x80070A34: sub.s       $f14, $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = ctx->f14.fl - ctx->f0.fl;
    // 0x80070A38: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x80070A3C: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x80070A40: lh          $v0, 0x5A($sp)
    ctx->r2 = MEM_H(ctx->r29, 0X5A);
    // 0x80070A44: swc1        $f12, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f12.u32l;
    // 0x80070A48: swc1        $f10, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f10.u32l;
    // 0x80070A4C: sub.s       $f6, $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f6.fl - ctx->f0.fl;
    // 0x80070A50: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x80070A54: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x80070A58: lh          $v0, 0x5C($sp)
    ctx->r2 = MEM_H(ctx->r29, 0X5C);
    // 0x80070A5C: sub.s       $f4, $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f4.fl - ctx->f0.fl;
    // 0x80070A60: swc1        $f14, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f14.u32l;
    // 0x80070A64: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x80070A68: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x80070A6C: sub.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl - ctx->f0.fl;
    // 0x80070A70: swc1        $f6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f6.u32l;
    // 0x80070A74: swc1        $f4, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f4.u32l;
    // 0x80070A78: swc1        $f2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f2.u32l;
    // 0x80070A7C: lwc1        $f2, 0x14($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0X14);
    // 0x80070A80: mov.s       $f6, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    ctx->f6.fl = ctx->f20.fl;
    // 0x80070A84: sub.s       $f0, $f2, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f2.fl - ctx->f6.fl;
    // 0x80070A88: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80070A8C: c.lt.s      $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f8.fl < ctx->f0.fl;
    // 0x80070A90: nop

    // 0x80070A94: bc1f        L_80070BB4
    if (!c1cs) {
        // 0x80070A98: nop
    
            goto L_80070BB4;
    }
    // 0x80070A98: nop

    // 0x80070A9C: mov.s       $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.fl = ctx->f6.fl;
L_80070AA0:
    // 0x80070AA0: div.s       $f4, $f6, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = DIV_S(ctx->f6.fl, ctx->f2.fl);
    // 0x80070AA4: lwc1        $f2, 0x2C($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80070AA8: lhu         $v0, 0x4($s1)
    ctx->r2 = MEM_HU(ctx->r17, 0X4);
    // 0x80070AAC: mul.s       $f2, $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f4.fl);
    // 0x80070AB0: lh          $v1, 0x50($sp)
    ctx->r3 = MEM_H(ctx->r29, 0X50);
    // 0x80070AB4: andi        $v0, $v0, 0x7
    ctx->r2 = ctx->r2 & 0X7;
    // 0x80070AB8: sll         $v0, $v0, 4
    ctx->r2 = S32(ctx->r2 << 4);
    // 0x80070ABC: mtc1        $v1, $f0
    ctx->f0.u32l = ctx->r3;
    // 0x80070AC0: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x80070AC4: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x80070AC8: addiu       $v0, $v0, 0x260
    ctx->r2 = ADD32(ctx->r2, 0X260);
    // 0x80070ACC: addu        $s0, $s1, $v0
    ctx->r16 = ADD32(ctx->r17, ctx->r2);
    // 0x80070AD0: trunc.w.s   $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x80070AD4: mfc1        $v0, $f22
    ctx->r2 = (int32_t)ctx->f22.u32l;
    // 0x80070AD8: sh          $v0, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r2;
    // 0x80070ADC: lwc1        $f2, 0x30($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X30);
    // 0x80070AE0: mul.s       $f2, $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f4.fl);
    // 0x80070AE4: lh          $v0, 0x52($sp)
    ctx->r2 = MEM_H(ctx->r29, 0X52);
    // 0x80070AE8: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x80070AEC: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x80070AF0: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x80070AF4: trunc.w.s   $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x80070AF8: mfc1        $v0, $f22
    ctx->r2 = (int32_t)ctx->f22.u32l;
    // 0x80070AFC: sh          $v0, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r2;
    // 0x80070B00: lwc1        $f2, 0x34($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X34);
    // 0x80070B04: mul.s       $f2, $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f4.fl);
    // 0x80070B08: lh          $v0, 0x54($sp)
    ctx->r2 = MEM_H(ctx->r29, 0X54);
    // 0x80070B0C: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x80070B10: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x80070B14: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x80070B18: trunc.w.s   $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x80070B1C: mfc1        $v0, $f22
    ctx->r2 = (int32_t)ctx->f22.u32l;
    // 0x80070B20: sh          $v0, 0x4($s0)
    MEM_H(0X4, ctx->r16) = ctx->r2;
    // 0x80070B24: lwc1        $f2, 0x38($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X38);
    // 0x80070B28: mul.s       $f2, $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f4.fl);
    // 0x80070B2C: lh          $v0, 0x58($sp)
    ctx->r2 = MEM_H(ctx->r29, 0X58);
    // 0x80070B30: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x80070B34: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x80070B38: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x80070B3C: trunc.w.s   $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x80070B40: mfc1        $v0, $f22
    ctx->r2 = (int32_t)ctx->f22.u32l;
    // 0x80070B44: sh          $v0, 0x8($s0)
    MEM_H(0X8, ctx->r16) = ctx->r2;
    // 0x80070B48: lwc1        $f2, 0x3C($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x80070B4C: mul.s       $f2, $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f4.fl);
    // 0x80070B50: lh          $v0, 0x5A($sp)
    ctx->r2 = MEM_H(ctx->r29, 0X5A);
    // 0x80070B54: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x80070B58: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x80070B5C: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x80070B60: trunc.w.s   $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x80070B64: mfc1        $v0, $f22
    ctx->r2 = (int32_t)ctx->f22.u32l;
    // 0x80070B68: sh          $v0, 0xA($s0)
    MEM_H(0XA, ctx->r16) = ctx->r2;
    // 0x80070B6C: lwc1        $f2, 0x40($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X40);
    // 0x80070B70: mul.s       $f2, $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f4.fl);
    // 0x80070B74: lh          $v0, 0x5C($sp)
    ctx->r2 = MEM_H(ctx->r29, 0X5C);
    // 0x80070B78: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x80070B7C: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x80070B80: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x80070B84: add.s       $f6, $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x80070B88: trunc.w.s   $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x80070B8C: mfc1        $v0, $f22
    ctx->r2 = (int32_t)ctx->f22.u32l;
    // 0x80070B90: sh          $v0, 0xC($s0)
    MEM_H(0XC, ctx->r16) = ctx->r2;
    // 0x80070B94: lwc1        $f2, 0x14($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0X14);
    // 0x80070B98: lhu         $v0, 0x4($s1)
    ctx->r2 = MEM_HU(ctx->r17, 0X4);
    // 0x80070B9C: sub.s       $f0, $f2, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f2.fl - ctx->f6.fl;
    // 0x80070BA0: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80070BA4: c.lt.s      $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f8.fl < ctx->f0.fl;
    // 0x80070BA8: nop

    // 0x80070BAC: bc1t        L_80070AA0
    if (c1cs) {
        // 0x80070BB0: sh          $v0, 0x4($s1)
        MEM_H(0X4, ctx->r17) = ctx->r2;
            goto L_80070AA0;
    }
    // 0x80070BB0: sh          $v0, 0x4($s1)
    MEM_H(0X4, ctx->r17) = ctx->r2;
L_80070BB4:
    // 0x80070BB4: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80070BB8: lwc1        $f2, -0x3384($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X3384);
    // 0x80070BBC: sub.s       $f2, $f6, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = ctx->f6.fl - ctx->f2.fl;
    // 0x80070BC0: lwc1        $f0, 0x14($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X14);
    // 0x80070BC4: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x80070BC8: swc1        $f0, 0x14($s1)
    MEM_W(0X14, ctx->r17) = ctx->f0.u32l;
L_80070BCC:
    // 0x80070BCC: lwc1        $f2, 0x14($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0X14);
    // 0x80070BD0: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80070BD4: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x80070BD8: nop

    // 0x80070BDC: bc1fl       L_80070CAC
    if (!c1cs) {
        // 0x80070BE0: sb          $zero, 0x8($s1)
        MEM_B(0X8, ctx->r17) = 0;
            goto L_80070CAC;
    }
    goto skip_2;
    // 0x80070BE0: sb          $zero, 0x8($s1)
    MEM_B(0X8, ctx->r17) = 0;
    skip_2:
    // 0x80070BE4: lwc1        $f2, 0x60($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X60);
    // 0x80070BE8: lwc1        $f0, 0x70($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X70);
    // 0x80070BEC: sub.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl - ctx->f0.fl;
    // 0x80070BF0: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80070BF4: lwc1        $f4, -0x3380($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X3380);
    // 0x80070BF8: lhu         $v0, 0x4($s1)
    ctx->r2 = MEM_HU(ctx->r17, 0X4);
    // 0x80070BFC: mul.s       $f2, $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f4.fl);
    // 0x80070C00: andi        $v0, $v0, 0x7
    ctx->r2 = ctx->r2 & 0X7;
    // 0x80070C04: sll         $v0, $v0, 4
    ctx->r2 = S32(ctx->r2 << 4);
    // 0x80070C08: addiu       $v0, $v0, 0x260
    ctx->r2 = ADD32(ctx->r2, 0X260);
    // 0x80070C0C: addu        $s0, $s1, $v0
    ctx->r16 = ADD32(ctx->r17, ctx->r2);
    // 0x80070C10: trunc.w.s   $f22, $f2
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 2);
    ctx->f22.u32l = TRUNC_W_S(ctx->f2.fl);
    // 0x80070C14: mfc1        $v0, $f22
    ctx->r2 = (int32_t)ctx->f22.u32l;
    // 0x80070C18: sh          $v0, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r2;
    // 0x80070C1C: lwc1        $f0, 0x64($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X64);
    // 0x80070C20: lwc1        $f2, 0x74($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X74);
    // 0x80070C24: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x80070C28: mul.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x80070C2C: trunc.w.s   $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x80070C30: mfc1        $v0, $f22
    ctx->r2 = (int32_t)ctx->f22.u32l;
    // 0x80070C34: sh          $v0, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r2;
    // 0x80070C38: lwc1        $f0, 0x68($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X68);
    // 0x80070C3C: lwc1        $f2, 0x78($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X78);
    // 0x80070C40: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x80070C44: mul.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x80070C48: trunc.w.s   $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x80070C4C: mfc1        $v0, $f22
    ctx->r2 = (int32_t)ctx->f22.u32l;
    // 0x80070C50: sh          $v0, 0x4($s0)
    MEM_H(0X4, ctx->r16) = ctx->r2;
    // 0x80070C54: lwc1        $f0, 0x60($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X60);
    // 0x80070C58: lwc1        $f2, 0x70($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X70);
    // 0x80070C5C: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x80070C60: mul.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x80070C64: trunc.w.s   $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x80070C68: mfc1        $v0, $f22
    ctx->r2 = (int32_t)ctx->f22.u32l;
    // 0x80070C6C: sh          $v0, 0x8($s0)
    MEM_H(0X8, ctx->r16) = ctx->r2;
    // 0x80070C70: lwc1        $f0, 0x64($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X64);
    // 0x80070C74: lwc1        $f2, 0x74($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X74);
    // 0x80070C78: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x80070C7C: mul.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x80070C80: trunc.w.s   $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x80070C84: mfc1        $v0, $f22
    ctx->r2 = (int32_t)ctx->f22.u32l;
    // 0x80070C88: sh          $v0, 0xA($s0)
    MEM_H(0XA, ctx->r16) = ctx->r2;
    // 0x80070C8C: lwc1        $f0, 0x68($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X68);
    // 0x80070C90: lwc1        $f2, 0x78($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X78);
    // 0x80070C94: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x80070C98: mul.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x80070C9C: trunc.w.s   $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x80070CA0: mfc1        $v0, $f22
    ctx->r2 = (int32_t)ctx->f22.u32l;
    // 0x80070CA4: sh          $v0, 0xC($s0)
    MEM_H(0XC, ctx->r16) = ctx->r2;
    // 0x80070CA8: sb          $zero, 0x8($s1)
    MEM_B(0X8, ctx->r17) = 0;
L_80070CAC:
    // 0x80070CAC: lhu         $v1, 0x4($s1)
    ctx->r3 = MEM_HU(ctx->r17, 0X4);
    // 0x80070CB0: sltiu       $v0, $v1, 0x2
    ctx->r2 = ctx->r3 < 0X2 ? 1 : 0;
    // 0x80070CB4: beq         $v0, $zero, L_80070CDC
    if (ctx->r2 == 0) {
        // 0x80070CB8: nop
    
            goto L_80070CDC;
    }
    // 0x80070CB8: nop

    // 0x80070CBC: beq         $v1, $zero, L_8007103C
    if (ctx->r3 == 0) {
        // 0x80070CC0: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_8007103C;
    }
    // 0x80070CC0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80070CC4: lwc1        $f2, 0x14($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0X14);
    // 0x80070CC8: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80070CCC: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x80070CD0: nop

    // 0x80070CD4: bc1f        L_8007103C
    if (!c1cs) {
        // 0x80070CD8: nop
    
            goto L_8007103C;
    }
    // 0x80070CD8: nop

L_80070CDC:
    // 0x80070CDC: lwc1        $f2, 0x14($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0X14);
    // 0x80070CE0: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80070CE4: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x80070CE8: nop

    // 0x80070CEC: bc1f        L_80070D1C
    if (!c1cs) {
        // 0x80070CF0: nop
    
            goto L_80070D1C;
    }
    // 0x80070CF0: nop

    // 0x80070CF4: lhu         $s2, 0x4($s1)
    ctx->r18 = MEM_HU(ctx->r17, 0X4);
    // 0x80070CF8: lhu         $v0, 0x6($s1)
    ctx->r2 = MEM_HU(ctx->r17, 0X6);
    // 0x80070CFC: addiu       $v1, $v0, 0x1
    ctx->r3 = ADD32(ctx->r2, 0X1);
    // 0x80070D00: slt         $v0, $v1, $s2
    ctx->r2 = SIGNED(ctx->r3) < SIGNED(ctx->r18) ? 1 : 0;
    // 0x80070D04: beq         $v0, $zero, L_80070D10
    if (ctx->r2 == 0) {
        // 0x80070D08: addu        $a0, $s2, $zero
        ctx->r4 = ADD32(ctx->r18, 0);
            goto L_80070D10;
    }
    // 0x80070D08: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // 0x80070D0C: addu        $s2, $v1, $zero
    ctx->r18 = ADD32(ctx->r3, 0);
L_80070D10:
    // 0x80070D10: subu        $s3, $a0, $s2
    ctx->r19 = SUB32(ctx->r4, ctx->r18);
    // 0x80070D14: j           L_80070D54
    // 0x80070D18: andi        $v0, $a0, 0x7
    ctx->r2 = ctx->r4 & 0X7;
        goto L_80070D54;
    // 0x80070D18: andi        $v0, $a0, 0x7
    ctx->r2 = ctx->r4 & 0X7;
L_80070D1C:
    // 0x80070D1C: lhu         $a1, 0x4($s1)
    ctx->r5 = MEM_HU(ctx->r17, 0X4);
    // 0x80070D20: lhu         $a0, 0x6($s1)
    ctx->r4 = MEM_HU(ctx->r17, 0X6);
    // 0x80070D24: addiu       $s2, $a1, -0x1
    ctx->r18 = ADD32(ctx->r5, -0X1);
    // 0x80070D28: slt         $v0, $a0, $s2
    ctx->r2 = SIGNED(ctx->r4) < SIGNED(ctx->r18) ? 1 : 0;
    // 0x80070D2C: beq         $v0, $zero, L_80070D38
    if (ctx->r2 == 0) {
        // 0x80070D30: addu        $v1, $s2, $zero
        ctx->r3 = ADD32(ctx->r18, 0);
            goto L_80070D38;
    }
    // 0x80070D30: addu        $v1, $s2, $zero
    ctx->r3 = ADD32(ctx->r18, 0);
    // 0x80070D34: addu        $s2, $a0, $zero
    ctx->r18 = ADD32(ctx->r4, 0);
L_80070D38:
    // 0x80070D38: subu        $s3, $v1, $s2
    ctx->r19 = SUB32(ctx->r3, ctx->r18);
    // 0x80070D3C: bgez        $v1, L_80070D48
    if (SIGNED(ctx->r3) >= 0) {
        // 0x80070D40: addu        $v0, $v1, $zero
        ctx->r2 = ADD32(ctx->r3, 0);
            goto L_80070D48;
    }
    // 0x80070D40: addu        $v0, $v1, $zero
    ctx->r2 = ADD32(ctx->r3, 0);
    // 0x80070D44: addiu       $v0, $a1, 0x6
    ctx->r2 = ADD32(ctx->r5, 0X6);
L_80070D48:
    // 0x80070D48: sra         $v0, $v0, 3
    ctx->r2 = S32(SIGNED(ctx->r2) >> 3);
    // 0x80070D4C: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x80070D50: subu        $v0, $v1, $v0
    ctx->r2 = SUB32(ctx->r3, ctx->r2);
L_80070D54:
    // 0x80070D54: sll         $v0, $v0, 4
    ctx->r2 = S32(ctx->r2 << 4);
    // 0x80070D58: addiu       $v0, $v0, 0x260
    ctx->r2 = ADD32(ctx->r2, 0X260);
    // 0x80070D5C: addu        $s0, $s1, $v0
    ctx->r16 = ADD32(ctx->r17, ctx->r2);
    // 0x80070D60: bgez        $s3, L_80070D6C
    if (SIGNED(ctx->r19) >= 0) {
        // 0x80070D64: addu        $v0, $s3, $zero
        ctx->r2 = ADD32(ctx->r19, 0);
            goto L_80070D6C;
    }
    // 0x80070D64: addu        $v0, $s3, $zero
    ctx->r2 = ADD32(ctx->r19, 0);
    // 0x80070D68: addiu       $v0, $s3, 0x7
    ctx->r2 = ADD32(ctx->r19, 0X7);
L_80070D6C:
    // 0x80070D6C: sra         $v0, $v0, 3
    ctx->r2 = S32(SIGNED(ctx->r2) >> 3);
    // 0x80070D70: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x80070D74: subu        $s3, $s3, $v0
    ctx->r19 = SUB32(ctx->r19, ctx->r2);
    // 0x80070D78: sll         $a0, $s3, 4
    ctx->r4 = S32(ctx->r19 << 4);
    // 0x80070D7C: addu        $a0, $s1, $a0
    ctx->r4 = ADD32(ctx->r17, ctx->r4);
    // 0x80070D80: lh          $v0, 0x260($a0)
    ctx->r2 = MEM_H(ctx->r4, 0X260);
    // 0x80070D84: lh          $v1, 0x0($s0)
    ctx->r3 = MEM_H(ctx->r16, 0X0);
    // 0x80070D88: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80070D8C: lwc1        $f0, -0x337C($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X337C);
    // 0x80070D90: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x80070D94: mtc1        $v0, $f4
    ctx->f4.u32l = ctx->r2;
    // 0x80070D98: cvt.s.w     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80070D9C: mul.s       $f4, $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x80070DA0: swc1        $f4, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f4.u32l;
    // 0x80070DA4: lh          $v0, 0x262($a0)
    ctx->r2 = MEM_H(ctx->r4, 0X262);
    // 0x80070DA8: lh          $v1, 0x2($s0)
    ctx->r3 = MEM_H(ctx->r16, 0X2);
    // 0x80070DAC: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x80070DB0: mtc1        $v0, $f6
    ctx->f6.u32l = ctx->r2;
    // 0x80070DB4: cvt.s.w     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80070DB8: mul.s       $f6, $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x80070DBC: swc1        $f6, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f6.u32l;
    // 0x80070DC0: lh          $v0, 0x264($a0)
    ctx->r2 = MEM_H(ctx->r4, 0X264);
    // 0x80070DC4: lh          $v1, 0x4($s0)
    ctx->r3 = MEM_H(ctx->r16, 0X4);
    // 0x80070DC8: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x80070DCC: mtc1        $v0, $f8
    ctx->f8.u32l = ctx->r2;
    // 0x80070DD0: cvt.s.w     $f8, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    ctx->f8.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80070DD4: mul.s       $f8, $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x80070DD8: swc1        $f8, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f8.u32l;
    // 0x80070DDC: lh          $v0, 0x0($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X0);
    // 0x80070DE0: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80070DE4: lwc1        $f10, -0x3378($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X3378);
    // 0x80070DE8: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x80070DEC: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x80070DF0: mul.s       $f0, $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x80070DF4: lwc1        $f2, 0x1C($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0X1C);
    // 0x80070DF8: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x80070DFC: add.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f4.fl;
    // 0x80070E00: mul.s       $f4, $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f4.fl = MUL_S(ctx->f4.fl, ctx->f4.fl);
    // 0x80070E04: swc1        $f0, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->f0.u32l;
    // 0x80070E08: lh          $v0, 0x2($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X2);
    // 0x80070E0C: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x80070E10: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x80070E14: mul.s       $f0, $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x80070E18: lwc1        $f2, 0x20($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0X20);
    // 0x80070E1C: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x80070E20: add.s       $f0, $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f6.fl;
    // 0x80070E24: mul.s       $f6, $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f6.fl = MUL_S(ctx->f6.fl, ctx->f6.fl);
    // 0x80070E28: swc1        $f0, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->f0.u32l;
    // 0x80070E2C: lh          $v0, 0x4($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X4);
    // 0x80070E30: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x80070E34: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x80070E38: mul.s       $f0, $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x80070E3C: nop

    // 0x80070E40: mul.s       $f10, $f8, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f8.fl);
    // 0x80070E44: add.s       $f4, $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80070E48: lwc1        $f2, 0x24($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0X24);
    // 0x80070E4C: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x80070E50: add.s       $f0, $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f8.fl;
    // 0x80070E54: add.s       $f4, $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x80070E58: swc1        $f0, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->f0.u32l;
    // 0x80070E5C: sqrt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = sqrtf(ctx->f4.fl);
    // 0x80070E60: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x80070E64: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80070E68: lw          $a0, 0x0($s4)
    ctx->r4 = MEM_W(ctx->r20, 0X0);
    // 0x80070E6C: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x80070E70: jal         0x8001DC34
    // 0x80070E74: addiu       $a2, $sp, 0x70
    ctx->r6 = ADD32(ctx->r29, 0X70);
    func_8001DC34(rdram, ctx);
        goto after_20;
    // 0x80070E74: addiu       $a2, $sp, 0x70
    ctx->r6 = ADD32(ctx->r29, 0X70);
    after_20:
    // 0x80070E78: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x80070E7C: beq         $v0, $zero, L_80071038
    if (ctx->r2 == 0) {
        // 0x80070E80: addiu       $a1, $s1, 0xF4
        ctx->r5 = ADD32(ctx->r17, 0XF4);
            goto L_80071038;
    }
    // 0x80070E80: addiu       $a1, $s1, 0xF4
    ctx->r5 = ADD32(ctx->r17, 0XF4);
    // 0x80070E84: lw          $a3, 0x38($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X38);
    // 0x80070E88: lhu         $v0, 0x4($s1)
    ctx->r2 = MEM_HU(ctx->r17, 0X4);
    // 0x80070E8C: sltiu       $v0, $v0, 0x9
    ctx->r2 = ctx->r2 < 0X9 ? 1 : 0;
    // 0x80070E90: beq         $v0, $zero, L_80070EA4
    if (ctx->r2 == 0) {
        // 0x80070E94: sw          $s2, 0xF0($s1)
        MEM_W(0XF0, ctx->r17) = ctx->r18;
            goto L_80070EA4;
    }
    // 0x80070E94: sw          $s2, 0xF0($s1)
    MEM_W(0XF0, ctx->r17) = ctx->r18;
    // 0x80070E98: lhu         $v0, 0x4($s1)
    ctx->r2 = MEM_HU(ctx->r17, 0X4);
    // 0x80070E9C: j           L_80070EA8
    // 0x80070EA0: sll         $a0, $v0, 1
    ctx->r4 = S32(ctx->r2 << 1);
        goto L_80070EA8;
    // 0x80070EA0: sll         $a0, $v0, 1
    ctx->r4 = S32(ctx->r2 << 1);
L_80070EA4:
    // 0x80070EA4: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
L_80070EA8:
    // 0x80070EA8: addiu       $v0, $zero, 0x1000
    ctx->r2 = ADD32(0, 0X1000);
    // 0x80070EAC: div         $zero, $v0, $s2
    if (S32(ctx->r18) != 0) { lo = S32(S64(S32(ctx->r2)) / S64(S32(ctx->r18))); hi = S32(S64(S32(ctx->r2)) % S64(S32(ctx->r18))); } else { lo = 0; hi = S32(ctx->r2); }
    // 0x80070EB0: bne         $s2, $zero, L_80070EBC
    if (ctx->r18 != 0) {
        // 0x80070EB4: nop
    
            goto L_80070EBC;
    }
    // 0x80070EB4: nop

    // 0x80070EB8: break       7
    do_break(2147946168);
L_80070EBC:
    // 0x80070EBC: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80070EC0: bne         $s2, $at, L_80070ED4
    if (ctx->r18 != ctx->r1) {
        // 0x80070EC4: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80070ED4;
    }
    // 0x80070EC4: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80070EC8: bne         $v0, $at, L_80070ED4
    if (ctx->r2 != ctx->r1) {
        // 0x80070ECC: nop
    
            goto L_80070ED4;
    }
    // 0x80070ECC: nop

    // 0x80070ED0: break       6
    do_break(2147946192);
L_80070ED4:
    // 0x80070ED4: mflo        $v0
    ctx->r2 = lo;
    // 0x80070ED8: sw          $a0, 0x9C($s1)
    MEM_W(0X9C, ctx->r17) = ctx->r4;
    // 0x80070EDC: addiu       $t0, $zero, 0x1000
    ctx->r8 = ADD32(0, 0X1000);
    // 0x80070EE0: blez        $s2, L_80070FA4
    if (SIGNED(ctx->r18) <= 0) {
        // 0x80070EE4: addu        $t1, $v0, $zero
        ctx->r9 = ADD32(ctx->r2, 0);
            goto L_80070FA4;
    }
    // 0x80070EE4: addu        $t1, $v0, $zero
    ctx->r9 = ADD32(ctx->r2, 0);
    // 0x80070EE8: addiu       $a0, $a1, 0x2E
    ctx->r4 = ADD32(ctx->r5, 0X2E);
    // 0x80070EEC: addiu       $a2, $a3, 0x2
    ctx->r6 = ADD32(ctx->r7, 0X2);
L_80070EF0:
    // 0x80070EF0: addiu       $v1, $s3, 0x1
    ctx->r3 = ADD32(ctx->r19, 0X1);
    // 0x80070EF4: addu        $a1, $v1, $zero
    ctx->r5 = ADD32(ctx->r3, 0);
    // 0x80070EF8: sll         $v0, $s3, 1
    ctx->r2 = S32(ctx->r19 << 1);
    // 0x80070EFC: sh          $v0, -0x22($a0)
    MEM_H(-0X22, ctx->r4) = ctx->r2;
    // 0x80070F00: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80070F04: bgez        $v1, L_80070F10
    if (SIGNED(ctx->r3) >= 0) {
        // 0x80070F08: sh          $v0, -0x20($a0)
        MEM_H(-0X20, ctx->r4) = ctx->r2;
            goto L_80070F10;
    }
    // 0x80070F08: sh          $v0, -0x20($a0)
    MEM_H(-0X20, ctx->r4) = ctx->r2;
    // 0x80070F0C: addiu       $a1, $s3, 0x8
    ctx->r5 = ADD32(ctx->r19, 0X8);
L_80070F10:
    // 0x80070F10: sra         $s3, $a1, 3
    ctx->r19 = S32(SIGNED(ctx->r5) >> 3);
    // 0x80070F14: sll         $v0, $s3, 3
    ctx->r2 = S32(ctx->r19 << 3);
    // 0x80070F18: subu        $s3, $v1, $v0
    ctx->r19 = SUB32(ctx->r3, ctx->r2);
    // 0x80070F1C: subu        $v1, $t0, $t1
    ctx->r3 = SUB32(ctx->r8, ctx->r9);
    // 0x80070F20: sh          $t0, -0x14($a0)
    MEM_H(-0X14, ctx->r4) = ctx->r8;
    // 0x80070F24: sh          $t0, -0x18($a0)
    MEM_H(-0X18, ctx->r4) = ctx->r8;
    // 0x80070F28: addu        $t0, $v1, $zero
    ctx->r8 = ADD32(ctx->r3, 0);
    // 0x80070F2C: sll         $v0, $s3, 1
    ctx->r2 = S32(ctx->r19 << 1);
    // 0x80070F30: sh          $v0, -0x1C($a0)
    MEM_H(-0X1C, ctx->r4) = ctx->r2;
    // 0x80070F34: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80070F38: sh          $v0, -0x1E($a0)
    MEM_H(-0X1E, ctx->r4) = ctx->r2;
    // 0x80070F3C: sh          $v1, -0xC($a0)
    MEM_H(-0XC, ctx->r4) = ctx->r3;
    // 0x80070F40: beq         $a3, $zero, L_80070F98
    if (ctx->r7 == 0) {
        // 0x80070F44: sh          $v1, -0x10($a0)
        MEM_H(-0X10, ctx->r4) = ctx->r3;
            goto L_80070F98;
    }
    // 0x80070F44: sh          $v1, -0x10($a0)
    MEM_H(-0X10, ctx->r4) = ctx->r3;
    // 0x80070F48: lbu         $v0, 0x0($a3)
    ctx->r2 = MEM_BU(ctx->r7, 0X0);
    // 0x80070F4C: sb          $v0, -0x6($a0)
    MEM_B(-0X6, ctx->r4) = ctx->r2;
    // 0x80070F50: sb          $v0, -0xA($a0)
    MEM_B(-0XA, ctx->r4) = ctx->r2;
    // 0x80070F54: lbu         $v0, -0x1($a2)
    ctx->r2 = MEM_BU(ctx->r6, -0X1);
    // 0x80070F58: sb          $v0, -0x5($a0)
    MEM_B(-0X5, ctx->r4) = ctx->r2;
    // 0x80070F5C: sb          $v0, -0x9($a0)
    MEM_B(-0X9, ctx->r4) = ctx->r2;
    // 0x80070F60: lbu         $v0, 0x0($a2)
    ctx->r2 = MEM_BU(ctx->r6, 0X0);
    // 0x80070F64: addiu       $a3, $a3, 0x4
    ctx->r7 = ADD32(ctx->r7, 0X4);
    // 0x80070F68: sb          $v0, -0x4($a0)
    MEM_B(-0X4, ctx->r4) = ctx->r2;
    // 0x80070F6C: sb          $v0, -0x8($a0)
    MEM_B(-0X8, ctx->r4) = ctx->r2;
    // 0x80070F70: lbu         $v0, 0x0($a3)
    ctx->r2 = MEM_BU(ctx->r7, 0X0);
    // 0x80070F74: addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
    // 0x80070F78: sb          $v0, 0x2($a0)
    MEM_B(0X2, ctx->r4) = ctx->r2;
    // 0x80070F7C: sb          $v0, -0x2($a0)
    MEM_B(-0X2, ctx->r4) = ctx->r2;
    // 0x80070F80: lbu         $v0, -0x1($a2)
    ctx->r2 = MEM_BU(ctx->r6, -0X1);
    // 0x80070F84: sb          $v0, 0x3($a0)
    MEM_B(0X3, ctx->r4) = ctx->r2;
    // 0x80070F88: sb          $v0, -0x1($a0)
    MEM_B(-0X1, ctx->r4) = ctx->r2;
    // 0x80070F8C: lbu         $v0, 0x0($a2)
    ctx->r2 = MEM_BU(ctx->r6, 0X0);
    // 0x80070F90: sb          $v0, 0x4($a0)
    MEM_B(0X4, ctx->r4) = ctx->r2;
    // 0x80070F94: sb          $v0, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r2;
L_80070F98:
    // 0x80070F98: addiu       $s2, $s2, -0x1
    ctx->r18 = ADD32(ctx->r18, -0X1);
    // 0x80070F9C: bgtz        $s2, L_80070EF0
    if (SIGNED(ctx->r18) > 0) {
        // 0x80070FA0: addiu       $a0, $a0, 0x34
        ctx->r4 = ADD32(ctx->r4, 0X34);
            goto L_80070EF0;
    }
    // 0x80070FA0: addiu       $a0, $a0, 0x34
    ctx->r4 = ADD32(ctx->r4, 0X34);
L_80070FA4:
    // 0x80070FA4: jal         0x8006C994
    // 0x80070FA8: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    func_8006C994(rdram, ctx);
        goto after_21;
    // 0x80070FA8: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    after_21:
    // 0x80070FAC: andi        $s0, $v0, 0xFFFF
    ctx->r16 = ctx->r2 & 0XFFFF;
    // 0x80070FB0: lhu         $v1, 0x0($s1)
    ctx->r3 = MEM_HU(ctx->r17, 0X0);
    // 0x80070FB4: ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
    // 0x80070FB8: beq         $v1, $v0, L_80070FDC
    if (ctx->r3 == ctx->r2) {
        // 0x80070FBC: nop
    
            goto L_80070FDC;
    }
    // 0x80070FBC: nop

    // 0x80070FC0: jal         0x80040218
    // 0x80070FC4: addu        $a0, $v1, $zero
    ctx->r4 = ADD32(ctx->r3, 0);
    func_80040218(rdram, ctx);
        goto after_22;
    // 0x80070FC4: addu        $a0, $v1, $zero
    ctx->r4 = ADD32(ctx->r3, 0);
    after_22:
    // 0x80070FC8: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x80070FCC: beq         $v0, $s0, L_80070FE8
    if (ctx->r2 == ctx->r16) {
        // 0x80070FD0: lui         $v0, 0x8013
        ctx->r2 = S32(0X8013 << 16);
            goto L_80070FE8;
    }
    // 0x80070FD0: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80070FD4: j           L_80071010
    // 0x80070FD8: nop

        goto L_80071010;
    // 0x80070FD8: nop

L_80070FDC:
    // 0x80070FDC: lhu         $v0, 0x2($s1)
    ctx->r2 = MEM_HU(ctx->r17, 0X2);
    // 0x80070FE0: bne         $v0, $s0, L_80071010
    if (ctx->r2 != ctx->r16) {
        // 0x80070FE4: lui         $v0, 0x8013
        ctx->r2 = S32(0X8013 << 16);
            goto L_80071010;
    }
    // 0x80070FE4: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
L_80070FE8:
    // 0x80070FE8: lhu         $v0, 0x7F3C($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X7F3C);
    // 0x80070FEC: andi        $v0, $v0, 0x100
    ctx->r2 = ctx->r2 & 0X100;
    // 0x80070FF0: bne         $v0, $zero, L_8007103C
    if (ctx->r2 != 0) {
        // 0x80070FF4: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_8007103C;
    }
    // 0x80070FF4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80070FF8: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x80070FFC: lw          $v0, -0x72E4($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X72E4);
    // 0x80071000: lhu         $v1, 0x4($v0)
    ctx->r3 = MEM_HU(ctx->r2, 0X4);
    // 0x80071004: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x80071008: beq         $v1, $v0, L_8007103C
    if (ctx->r3 == ctx->r2) {
        // 0x8007100C: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_8007103C;
    }
    // 0x8007100C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80071010:
    // 0x80071010: lw          $v0, 0x0($s4)
    ctx->r2 = MEM_W(ctx->r20, 0X0);
    // 0x80071014: lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X0);
    // 0x80071018: beq         $v1, $zero, L_80071028
    if (ctx->r3 == 0) {
        // 0x8007101C: sw          $v1, 0x3C($s1)
        MEM_W(0X3C, ctx->r17) = ctx->r3;
            goto L_80071028;
    }
    // 0x8007101C: sw          $v1, 0x3C($s1)
    MEM_W(0X3C, ctx->r17) = ctx->r3;
    // 0x80071020: addiu       $v0, $s1, 0x3C
    ctx->r2 = ADD32(ctx->r17, 0X3C);
    // 0x80071024: sw          $v0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r2;
L_80071028:
    // 0x80071028: lw          $v1, 0x0($s4)
    ctx->r3 = MEM_W(ctx->r20, 0X0);
    // 0x8007102C: addiu       $v0, $s1, 0x3C
    ctx->r2 = ADD32(ctx->r17, 0X3C);
    // 0x80071030: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x80071034: sw          $zero, 0x40($s1)
    MEM_W(0X40, ctx->r17) = 0;
L_80071038:
    // 0x80071038: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8007103C:
    // 0x8007103C: lw          $ra, 0xC4($sp)
    ctx->r31 = MEM_W(ctx->r29, 0XC4);
    // 0x80071040: lw          $s4, 0xC0($sp)
    ctx->r20 = MEM_W(ctx->r29, 0XC0);
    // 0x80071044: lw          $s3, 0xBC($sp)
    ctx->r19 = MEM_W(ctx->r29, 0XBC);
    // 0x80071048: lw          $s2, 0xB8($sp)
    ctx->r18 = MEM_W(ctx->r29, 0XB8);
    // 0x8007104C: lw          $s1, 0xB4($sp)
    ctx->r17 = MEM_W(ctx->r29, 0XB4);
    // 0x80071050: lw          $s0, 0xB0($sp)
    ctx->r16 = MEM_W(ctx->r29, 0XB0);
    // 0x80071054: ldc1        $f22, 0xD0($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0XD0);
    // 0x80071058: ldc1        $f20, 0xC8($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0XC8);
    // 0x8007105C: jr          $ra
    // 0x80071060: addiu       $sp, $sp, 0xD8
    ctx->r29 = ADD32(ctx->r29, 0XD8);
    return;
    // 0x80071060: addiu       $sp, $sp, 0xD8
    ctx->r29 = ADD32(ctx->r29, 0XD8);
;}
RECOMP_FUNC void func_80071064(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80071064: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x80071068: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8007106C: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x80071070: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x80071074: addu        $s3, $a1, $zero
    ctx->r19 = ADD32(ctx->r5, 0);
    // 0x80071078: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x8007107C: addu        $s4, $a2, $zero
    ctx->r20 = ADD32(ctx->r6, 0);
    // 0x80071080: sw          $s5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r21;
    // 0x80071084: addu        $s5, $a3, $zero
    ctx->r21 = ADD32(ctx->r7, 0);
    // 0x80071088: addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    // 0x8007108C: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x80071090: lw          $s2, 0x58($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X58);
    // 0x80071094: addu        $a1, $s4, $zero
    ctx->r5 = ADD32(ctx->r20, 0);
    // 0x80071098: sw          $s6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r22;
    // 0x8007109C: lw          $s6, 0x5C($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X5C);
    // 0x800710A0: addiu       $a2, $sp, 0x18
    ctx->r6 = ADD32(ctx->r29, 0X18);
    // 0x800710A4: sw          $ra, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r31;
    // 0x800710A8: sw          $s7, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r23;
    // 0x800710AC: jal         0x80059728
    // 0x800710B0: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    func_80059728(rdram, ctx);
        goto after_0;
    // 0x800710B0: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    after_0:
    // 0x800710B4: addu        $s1, $v0, $zero
    ctx->r17 = ADD32(ctx->r2, 0);
    // 0x800710B8: blez        $s1, L_800712D0
    if (SIGNED(ctx->r17) <= 0) {
        // 0x800710BC: slti        $v0, $s1, 0x2
        ctx->r2 = SIGNED(ctx->r17) < 0X2 ? 1 : 0;
            goto L_800712D0;
    }
    // 0x800710BC: slti        $v0, $s1, 0x2
    ctx->r2 = SIGNED(ctx->r17) < 0X2 ? 1 : 0;
    // 0x800710C0: beq         $v0, $zero, L_800710D0
    if (ctx->r2 == 0) {
        // 0x800710C4: andi        $v0, $s5, 0x80
        ctx->r2 = ctx->r21 & 0X80;
            goto L_800710D0;
    }
    // 0x800710C4: andi        $v0, $s5, 0x80
    ctx->r2 = ctx->r21 & 0X80;
    // 0x800710C8: beq         $v0, $zero, L_800711A4
    if (ctx->r2 == 0) {
        // 0x800710CC: nop
    
            goto L_800711A4;
    }
    // 0x800710CC: nop

L_800710D0:
    // 0x800710D0: bgez        $s2, L_800711A4
    if (SIGNED(ctx->r18) >= 0) {
        // 0x800710D4: addiu       $v0, $zero, 0xFF
        ctx->r2 = ADD32(0, 0XFF);
            goto L_800711A4;
    }
    // 0x800710D4: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // 0x800710D8: lbu         $v1, 0x0($s0)
    ctx->r3 = MEM_BU(ctx->r16, 0X0);
    // 0x800710DC: bnel        $v1, $v0, L_80071104
    if (ctx->r3 != ctx->r2) {
        // 0x800710E0: sw          $zero, 0x18($sp)
        MEM_W(0X18, ctx->r29) = 0;
            goto L_80071104;
    }
    goto skip_0;
    // 0x800710E0: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    skip_0:
    // 0x800710E4: addiu       $a0, $zero, 0x2A0
    ctx->r4 = ADD32(0, 0X2A0);
    // 0x800710E8: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x800710EC: addiu       $v0, $zero, 0x80
    ctx->r2 = ADD32(0, 0X80);
    // 0x800710F0: sb          $v0, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r2;
    // 0x800710F4: jal         0x80001ACC
    // 0x800710F8: sb          $zero, 0x4($s0)
    MEM_B(0X4, ctx->r16) = 0;
    rs_malloc(rdram, ctx);
        goto after_1;
    // 0x800710F8: sb          $zero, 0x4($s0)
    MEM_B(0X4, ctx->r16) = 0;
    after_1:
    // 0x800710FC: sw          $v0, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r2;
    // 0x80071100: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
L_80071104:
    // 0x80071104: lbu         $v0, 0x4($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X4);
    // 0x80071108: sltiu       $v0, $v0, 0xC
    ctx->r2 = ctx->r2 < 0XC ? 1 : 0;
    // 0x8007110C: beq         $v0, $zero, L_8007119C
    if (ctx->r2 == 0) {
        // 0x80071110: addiu       $s7, $zero, 0xFF
        ctx->r23 = ADD32(0, 0XFF);
            goto L_8007119C;
    }
    // 0x80071110: addiu       $s7, $zero, 0xFF
    ctx->r23 = ADD32(0, 0XFF);
    // 0x80071114: addiu       $s2, $zero, -0x81
    ctx->r18 = ADD32(0, -0X81);
L_80071118:
    // 0x80071118: lw          $v0, 0x18($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X18);
    // 0x8007111C: slt         $v0, $v0, $s1
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r17) ? 1 : 0;
    // 0x80071120: beq         $v0, $zero, L_8007119C
    if (ctx->r2 == 0) {
        // 0x80071124: addu        $a1, $s3, $zero
        ctx->r5 = ADD32(ctx->r19, 0);
            goto L_8007119C;
    }
    // 0x80071124: addu        $a1, $s3, $zero
    ctx->r5 = ADD32(ctx->r19, 0);
    // 0x80071128: lbu         $v1, 0x4($s0)
    ctx->r3 = MEM_BU(ctx->r16, 0X4);
    // 0x8007112C: sll         $v0, $v1, 3
    ctx->r2 = S32(ctx->r3 << 3);
    // 0x80071130: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x80071134: lw          $v1, 0x8($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X8);
    // 0x80071138: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x8007113C: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80071140: sb          $s7, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r23;
    // 0x80071144: lbu         $v0, 0x4($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X4);
    // 0x80071148: lw          $v1, 0x8($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X8);
    // 0x8007114C: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
    // 0x80071150: addu        $a2, $s4, $zero
    ctx->r6 = ADD32(ctx->r20, 0);
    // 0x80071154: sw          $s6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r22;
    // 0x80071158: sll         $a0, $v0, 3
    ctx->r4 = S32(ctx->r2 << 3);
    // 0x8007115C: subu        $a0, $a0, $v0
    ctx->r4 = SUB32(ctx->r4, ctx->r2);
    // 0x80071160: sll         $a0, $a0, 3
    ctx->r4 = S32(ctx->r4 << 3);
    // 0x80071164: addu        $a0, $v1, $a0
    ctx->r4 = ADD32(ctx->r3, ctx->r4);
    // 0x80071168: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    // 0x8007116C: jal         0x80071064
    // 0x80071170: and         $a3, $s5, $s2
    ctx->r7 = ctx->r21 & ctx->r18;
    func_80071064(rdram, ctx);
        goto after_2;
    // 0x80071170: and         $a3, $s5, $s2
    ctx->r7 = ctx->r21 & ctx->r18;
    after_2:
    // 0x80071174: lw          $v0, 0x18($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X18);
    // 0x80071178: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8007117C: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // 0x80071180: lbu         $v0, 0x4($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X4);
    // 0x80071184: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80071188: sb          $v0, 0x4($s0)
    MEM_B(0X4, ctx->r16) = ctx->r2;
    // 0x8007118C: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x80071190: sltiu       $v0, $v0, 0xC
    ctx->r2 = ctx->r2 < 0XC ? 1 : 0;
    // 0x80071194: bne         $v0, $zero, L_80071118
    if (ctx->r2 != 0) {
        // 0x80071198: nop
    
            goto L_80071118;
    }
    // 0x80071198: nop

L_8007119C:
    // 0x8007119C: j           L_800712DC
    // 0x800711A0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_800712DC;
    // 0x800711A0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800711A4:
    // 0x800711A4: lbu         $v1, 0x0($s0)
    ctx->r3 = MEM_BU(ctx->r16, 0X0);
    // 0x800711A8: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // 0x800711AC: beq         $v1, $v0, L_800711EC
    if (ctx->r3 == ctx->r2) {
        // 0x800711B0: andi        $v0, $v1, 0x80
        ctx->r2 = ctx->r3 & 0X80;
            goto L_800711EC;
    }
    // 0x800711B0: andi        $v0, $v1, 0x80
    ctx->r2 = ctx->r3 & 0X80;
    // 0x800711B4: beql        $v0, $zero, L_800711F0
    if (ctx->r2 == 0) {
        // 0x800711B8: sb          $s5, 0x0($s0)
        MEM_B(0X0, ctx->r16) = ctx->r21;
            goto L_800711F0;
    }
    goto skip_1;
    // 0x800711B8: sb          $s5, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r21;
    skip_1:
    // 0x800711BC: lbu         $v1, 0x4($s0)
    ctx->r3 = MEM_BU(ctx->r16, 0X4);
    // 0x800711C0: sltiu       $v0, $v1, 0xC
    ctx->r2 = ctx->r3 < 0XC ? 1 : 0;
    // 0x800711C4: beq         $v0, $zero, L_800712D8
    if (ctx->r2 == 0) {
        // 0x800711C8: addiu       $v0, $v1, 0x1
        ctx->r2 = ADD32(ctx->r3, 0X1);
            goto L_800712D8;
    }
    // 0x800711C8: addiu       $v0, $v1, 0x1
    ctx->r2 = ADD32(ctx->r3, 0X1);
    // 0x800711CC: sb          $v0, 0x4($s0)
    MEM_B(0X4, ctx->r16) = ctx->r2;
    // 0x800711D0: andi        $v1, $v0, 0xFF
    ctx->r3 = ctx->r2 & 0XFF;
    // 0x800711D4: sll         $v0, $v1, 3
    ctx->r2 = S32(ctx->r3 << 3);
    // 0x800711D8: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x800711DC: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x800711E0: lw          $v1, 0x8($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X8);
    // 0x800711E4: addiu       $v0, $v0, -0x38
    ctx->r2 = ADD32(ctx->r2, -0X38);
    // 0x800711E8: addu        $s0, $v1, $v0
    ctx->r16 = ADD32(ctx->r3, ctx->r2);
L_800711EC:
    // 0x800711EC: sb          $s5, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r21;
L_800711F0:
    // 0x800711F0: sb          $zero, 0x1($s0)
    MEM_B(0X1, ctx->r16) = 0;
    // 0x800711F4: lbu         $v0, 0x1B($sp)
    ctx->r2 = MEM_BU(ctx->r29, 0X1B);
    // 0x800711F8: sh          $s6, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r22;
    // 0x800711FC: bltz        $s2, L_8007120C
    if (SIGNED(ctx->r18) < 0) {
        // 0x80071200: sb          $v0, 0x4($s0)
        MEM_B(0X4, ctx->r16) = ctx->r2;
            goto L_8007120C;
    }
    // 0x80071200: sb          $v0, 0x4($s0)
    MEM_B(0X4, ctx->r16) = ctx->r2;
    // 0x80071204: j           L_80071210
    // 0x80071208: sb          $s2, 0x5($s0)
    MEM_B(0X5, ctx->r16) = ctx->r18;
        goto L_80071210;
    // 0x80071208: sb          $s2, 0x5($s0)
    MEM_B(0X5, ctx->r16) = ctx->r18;
L_8007120C:
    // 0x8007120C: sb          $zero, 0x5($s0)
    MEM_B(0X5, ctx->r16) = 0;
L_80071210:
    // 0x80071210: addiu       $v0, $zero, 0x301
    ctx->r2 = ADD32(0, 0X301);
    // 0x80071214: lui         $v1, 0x800A
    ctx->r3 = S32(0X800A << 16);
    // 0x80071218: addiu       $v1, $v1, 0xB84
    ctx->r3 = ADD32(ctx->r3, 0XB84);
    // 0x8007121C: sh          $v0, 0x18($s0)
    MEM_H(0X18, ctx->r16) = ctx->r2;
    // 0x80071220: andi        $v0, $s5, 0x1F
    ctx->r2 = ctx->r21 & 0X1F;
    // 0x80071224: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80071228: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8007122C: lwc1        $f0, -0x3374($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X3374);
    // 0x80071230: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80071234: sb          $zero, 0x6($s0)
    MEM_B(0X6, ctx->r16) = 0;
    // 0x80071238: sh          $zero, 0x32($s0)
    MEM_H(0X32, ctx->r16) = 0;
    // 0x8007123C: sh          $zero, 0x30($s0)
    MEM_H(0X30, ctx->r16) = 0;
    // 0x80071240: swc1        $f0, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f0.u32l;
    // 0x80071244: lwc1        $f2, 0x0($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X0);
    // 0x80071248: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8007124C: lwc1        $f0, -0x3370($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X3370);
    // 0x80071250: c.le.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl <= ctx->f0.fl;
    // 0x80071254: nop

    // 0x80071258: bc1f        L_80071290
    if (!c1cs) {
        // 0x8007125C: lui         $v0, 0x8013
        ctx->r2 = S32(0X8013 << 16);
            goto L_80071290;
    }
    // 0x8007125C: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80071260: lw          $v0, 0xB50($v0)
    ctx->r2 = MEM_W(ctx->r2, 0XB50);
    // 0x80071264: andi        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 & 0X1;
    // 0x80071268: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8007126C: lwc1        $f0, -0x336C($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X336C);
    // 0x80071270: beq         $v0, $zero, L_80071280
    if (ctx->r2 == 0) {
        // 0x80071274: nop
    
            goto L_80071280;
    }
    // 0x80071274: nop

    // 0x80071278: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8007127C: lwc1        $f0, -0x3368($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X3368);
L_80071280:
    // 0x80071280: mul.s       $f0, $f2, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x80071284: swc1        $f0, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f0.u32l;
    // 0x80071288: j           L_80071298
    // 0x8007128C: swc1        $f0, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->f0.u32l;
        goto L_80071298;
    // 0x8007128C: swc1        $f0, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->f0.u32l;
L_80071290:
    // 0x80071290: swc1        $f2, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f2.u32l;
    // 0x80071294: swc1        $f2, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->f2.u32l;
L_80071298:
    // 0x80071298: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x8007129C: addiu       $a0, $a0, 0xB38
    ctx->r4 = ADD32(ctx->r4, 0XB38);
    // 0x800712A0: andi        $v0, $s5, 0x1F
    ctx->r2 = ctx->r21 & 0X1F;
    // 0x800712A4: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800712A8: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x800712AC: lw          $v1, 0xC08($v1)
    ctx->r3 = MEM_W(ctx->r3, 0XC08);
    // 0x800712B0: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x800712B4: lwl         $t0, 0x0($v0)
    ctx->r8 = do_lwl(rdram, ctx->r8, ctx->r2, 0X0);
    // 0x800712B8: lwr         $t0, 0x3($v0)
    ctx->r8 = do_lwr(rdram, ctx->r8, ctx->r2, 0X3);
    // 0x800712BC: swl         $t0, 0x34($s0)
    do_swl(rdram, 0X34, ctx->r16, ctx->r8);
    // 0x800712C0: swr         $t0, 0x37($s0)
    do_swr(rdram, 0X37, ctx->r16, ctx->r8);
    // 0x800712C4: lhu         $v0, 0x24($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X24);
    // 0x800712C8: j           L_800712D8
    // 0x800712CC: sh          $v0, 0x1A($s0)
    MEM_H(0X1A, ctx->r16) = ctx->r2;
        goto L_800712D8;
    // 0x800712CC: sh          $v0, 0x1A($s0)
    MEM_H(0X1A, ctx->r16) = ctx->r2;
L_800712D0:
    // 0x800712D0: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // 0x800712D4: sb          $v0, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r2;
L_800712D8:
    // 0x800712D8: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_800712DC:
    // 0x800712DC: lw          $ra, 0x40($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X40);
    // 0x800712E0: lw          $s7, 0x3C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X3C);
    // 0x800712E4: lw          $s6, 0x38($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X38);
    // 0x800712E8: lw          $s5, 0x34($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X34);
    // 0x800712EC: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x800712F0: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x800712F4: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x800712F8: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x800712FC: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80071300: jr          $ra
    // 0x80071304: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x80071304: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void func_80071308(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80071308: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8007130C: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x80071310: addu        $s4, $a0, $zero
    ctx->r20 = ADD32(ctx->r4, 0);
    // 0x80071314: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80071318: addu        $s2, $a1, $zero
    ctx->r18 = ADD32(ctx->r5, 0);
    // 0x8007131C: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80071320: addu        $s1, $zero, $zero
    ctx->r17 = ADD32(0, 0);
    // 0x80071324: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80071328: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x8007132C: jal         0x80003430
    // 0x80071330: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    rand_recomp(rdram, ctx);
        goto after_0;
    // 0x80071330: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    after_0:
    // 0x80071334: addiu       $v1, $zero, 0xFF
    ctx->r3 = ADD32(0, 0XFF);
    // 0x80071338: sb          $v1, 0x0($s4)
    MEM_B(0X0, ctx->r20) = ctx->r3;
    // 0x8007133C: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    // 0x80071340: lui         $v1, 0xF
    ctx->r3 = S32(0XF << 16);
    // 0x80071344: lw          $a0, 0x10($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X10);
    // 0x80071348: ori         $v1, $v1, 0xFFFF
    ctx->r3 = ctx->r3 | 0XFFFF;
    // 0x8007134C: lw          $a0, 0x18($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X18);
    // 0x80071350: and         $v1, $a0, $v1
    ctx->r3 = ctx->r4 & ctx->r3;
    // 0x80071354: beq         $v1, $zero, L_80071904
    if (ctx->r3 == 0) {
        // 0x80071358: andi        $s3, $v0, 0x7FF
        ctx->r19 = ctx->r2 & 0X7FF;
            goto L_80071904;
    }
    // 0x80071358: andi        $s3, $v0, 0x7FF
    ctx->r19 = ctx->r2 & 0X7FF;
    // 0x8007135C: andi        $v0, $a0, 0x1
    ctx->r2 = ctx->r4 & 0X1;
    // 0x80071360: beq         $v0, $zero, L_8007138C
    if (ctx->r2 == 0) {
        // 0x80071364: addu        $a0, $s4, $zero
        ctx->r4 = ADD32(ctx->r20, 0);
            goto L_8007138C;
    }
    // 0x80071364: addu        $a0, $s4, $zero
    ctx->r4 = ADD32(ctx->r20, 0);
    // 0x80071368: addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    // 0x8007136C: lui         $a2, 0x8004
    ctx->r6 = S32(0X8004 << 16);
    // 0x80071370: addiu       $a2, $a2, -0x3364
    ctx->r6 = ADD32(ctx->r6, -0X3364);
    // 0x80071374: addu        $a3, $s1, $zero
    ctx->r7 = ADD32(ctx->r17, 0);
    // 0x80071378: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x8007137C: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // 0x80071380: jal         0x80071064
    // 0x80071384: sw          $s3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r19;
    func_80071064(rdram, ctx);
        goto after_1;
    // 0x80071384: sw          $s3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r19;
    after_1:
    // 0x80071388: andi        $s1, $v0, 0xFF
    ctx->r17 = ctx->r2 & 0XFF;
L_8007138C:
    // 0x8007138C: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x80071390: lw          $v0, 0x10($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X10);
    // 0x80071394: lw          $v0, 0x18($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X18);
    // 0x80071398: andi        $v0, $v0, 0x200
    ctx->r2 = ctx->r2 & 0X200;
    // 0x8007139C: beq         $v0, $zero, L_800713CC
    if (ctx->r2 == 0) {
        // 0x800713A0: addu        $a0, $s4, $zero
        ctx->r4 = ADD32(ctx->r20, 0);
            goto L_800713CC;
    }
    // 0x800713A0: addu        $a0, $s4, $zero
    ctx->r4 = ADD32(ctx->r20, 0);
    // 0x800713A4: addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    // 0x800713A8: lui         $a2, 0x8004
    ctx->r6 = S32(0X8004 << 16);
    // 0x800713AC: addiu       $a2, $a2, -0x3364
    ctx->r6 = ADD32(ctx->r6, -0X3364);
    // 0x800713B0: addiu       $a3, $zero, 0xB
    ctx->r7 = ADD32(0, 0XB);
    // 0x800713B4: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x800713B8: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // 0x800713BC: jal         0x80071064
    // 0x800713C0: sw          $s3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r19;
    func_80071064(rdram, ctx);
        goto after_2;
    // 0x800713C0: sw          $s3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r19;
    after_2:
    // 0x800713C4: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x800713C8: or          $s1, $s1, $v0
    ctx->r17 = ctx->r17 | ctx->r2;
L_800713CC:
    // 0x800713CC: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x800713D0: lw          $v0, 0x10($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X10);
    // 0x800713D4: lw          $v0, 0x18($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X18);
    // 0x800713D8: andi        $v0, $v0, 0x20
    ctx->r2 = ctx->r2 & 0X20;
    // 0x800713DC: beq         $v0, $zero, L_8007140C
    if (ctx->r2 == 0) {
        // 0x800713E0: addu        $a0, $s4, $zero
        ctx->r4 = ADD32(ctx->r20, 0);
            goto L_8007140C;
    }
    // 0x800713E0: addu        $a0, $s4, $zero
    ctx->r4 = ADD32(ctx->r20, 0);
    // 0x800713E4: addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    // 0x800713E8: lui         $a2, 0x8004
    ctx->r6 = S32(0X8004 << 16);
    // 0x800713EC: addiu       $a2, $a2, -0x3364
    ctx->r6 = ADD32(ctx->r6, -0X3364);
    // 0x800713F0: addiu       $a3, $zero, 0x5
    ctx->r7 = ADD32(0, 0X5);
    // 0x800713F4: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x800713F8: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // 0x800713FC: jal         0x80071064
    // 0x80071400: sw          $s3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r19;
    func_80071064(rdram, ctx);
        goto after_3;
    // 0x80071400: sw          $s3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r19;
    after_3:
    // 0x80071404: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x80071408: or          $s1, $s1, $v0
    ctx->r17 = ctx->r17 | ctx->r2;
L_8007140C:
    // 0x8007140C: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x80071410: lw          $v0, 0x10($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X10);
    // 0x80071414: lw          $v0, 0x18($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X18);
    // 0x80071418: andi        $v0, $v0, 0x4000
    ctx->r2 = ctx->r2 & 0X4000;
    // 0x8007141C: beq         $v0, $zero, L_8007144C
    if (ctx->r2 == 0) {
        // 0x80071420: addu        $a0, $s4, $zero
        ctx->r4 = ADD32(ctx->r20, 0);
            goto L_8007144C;
    }
    // 0x80071420: addu        $a0, $s4, $zero
    ctx->r4 = ADD32(ctx->r20, 0);
    // 0x80071424: addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    // 0x80071428: lui         $a2, 0x8004
    ctx->r6 = S32(0X8004 << 16);
    // 0x8007142C: addiu       $a2, $a2, -0x3364
    ctx->r6 = ADD32(ctx->r6, -0X3364);
    // 0x80071430: addiu       $a3, $zero, 0xF
    ctx->r7 = ADD32(0, 0XF);
    // 0x80071434: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x80071438: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // 0x8007143C: jal         0x80071064
    // 0x80071440: sw          $s3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r19;
    func_80071064(rdram, ctx);
        goto after_4;
    // 0x80071440: sw          $s3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r19;
    after_4:
    // 0x80071444: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x80071448: or          $s1, $s1, $v0
    ctx->r17 = ctx->r17 | ctx->r2;
L_8007144C:
    // 0x8007144C: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x80071450: lw          $v0, 0x10($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X10);
    // 0x80071454: lw          $v0, 0x18($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X18);
    // 0x80071458: andi        $v0, $v0, 0x2
    ctx->r2 = ctx->r2 & 0X2;
    // 0x8007145C: beq         $v0, $zero, L_8007148C
    if (ctx->r2 == 0) {
        // 0x80071460: addu        $a0, $s4, $zero
        ctx->r4 = ADD32(ctx->r20, 0);
            goto L_8007148C;
    }
    // 0x80071460: addu        $a0, $s4, $zero
    ctx->r4 = ADD32(ctx->r20, 0);
    // 0x80071464: addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    // 0x80071468: lui         $a2, 0x8004
    ctx->r6 = S32(0X8004 << 16);
    // 0x8007146C: addiu       $a2, $a2, -0x335C
    ctx->r6 = ADD32(ctx->r6, -0X335C);
    // 0x80071470: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    // 0x80071474: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x80071478: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // 0x8007147C: jal         0x80071064
    // 0x80071480: sw          $s3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r19;
    func_80071064(rdram, ctx);
        goto after_5;
    // 0x80071480: sw          $s3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r19;
    after_5:
    // 0x80071484: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x80071488: or          $s1, $s1, $v0
    ctx->r17 = ctx->r17 | ctx->r2;
L_8007148C:
    // 0x8007148C: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x80071490: lw          $v0, 0x10($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X10);
    // 0x80071494: lw          $v0, 0x18($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X18);
    // 0x80071498: andi        $v0, $v0, 0x400
    ctx->r2 = ctx->r2 & 0X400;
    // 0x8007149C: beq         $v0, $zero, L_800714CC
    if (ctx->r2 == 0) {
        // 0x800714A0: addu        $a0, $s4, $zero
        ctx->r4 = ADD32(ctx->r20, 0);
            goto L_800714CC;
    }
    // 0x800714A0: addu        $a0, $s4, $zero
    ctx->r4 = ADD32(ctx->r20, 0);
    // 0x800714A4: addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    // 0x800714A8: lui         $a2, 0x8004
    ctx->r6 = S32(0X8004 << 16);
    // 0x800714AC: addiu       $a2, $a2, -0x335C
    ctx->r6 = ADD32(ctx->r6, -0X335C);
    // 0x800714B0: addiu       $a3, $zero, 0xC
    ctx->r7 = ADD32(0, 0XC);
    // 0x800714B4: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x800714B8: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // 0x800714BC: jal         0x80071064
    // 0x800714C0: sw          $s3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r19;
    func_80071064(rdram, ctx);
        goto after_6;
    // 0x800714C0: sw          $s3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r19;
    after_6:
    // 0x800714C4: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x800714C8: or          $s1, $s1, $v0
    ctx->r17 = ctx->r17 | ctx->r2;
L_800714CC:
    // 0x800714CC: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x800714D0: lw          $v0, 0x10($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X10);
    // 0x800714D4: lw          $v0, 0x18($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X18);
    // 0x800714D8: andi        $v0, $v0, 0x4
    ctx->r2 = ctx->r2 & 0X4;
    // 0x800714DC: beq         $v0, $zero, L_8007155C
    if (ctx->r2 == 0) {
        // 0x800714E0: addu        $a0, $s4, $zero
        ctx->r4 = ADD32(ctx->r20, 0);
            goto L_8007155C;
    }
    // 0x800714E0: addu        $a0, $s4, $zero
    ctx->r4 = ADD32(ctx->r20, 0);
    // 0x800714E4: addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    // 0x800714E8: lui         $a2, 0x8004
    ctx->r6 = S32(0X8004 << 16);
    // 0x800714EC: addiu       $a2, $a2, -0x3364
    ctx->r6 = ADD32(ctx->r6, -0X3364);
    // 0x800714F0: addiu       $a3, $zero, 0x81
    ctx->r7 = ADD32(0, 0X81);
    // 0x800714F4: addiu       $s0, $zero, -0x1
    ctx->r16 = ADD32(0, -0X1);
    // 0x800714F8: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x800714FC: jal         0x80071064
    // 0x80071500: sw          $s3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r19;
    func_80071064(rdram, ctx);
        goto after_7;
    // 0x80071500: sw          $s3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r19;
    after_7:
    // 0x80071504: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x80071508: or          $s1, $s1, $v0
    ctx->r17 = ctx->r17 | ctx->r2;
    // 0x8007150C: addu        $a0, $s4, $zero
    ctx->r4 = ADD32(ctx->r20, 0);
    // 0x80071510: addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    // 0x80071514: lui         $a2, 0x8004
    ctx->r6 = S32(0X8004 << 16);
    // 0x80071518: addiu       $a2, $a2, -0x335C
    ctx->r6 = ADD32(ctx->r6, -0X335C);
    // 0x8007151C: addiu       $a3, $zero, 0x81
    ctx->r7 = ADD32(0, 0X81);
    // 0x80071520: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x80071524: jal         0x80071064
    // 0x80071528: sw          $s3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r19;
    func_80071064(rdram, ctx);
        goto after_8;
    // 0x80071528: sw          $s3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r19;
    after_8:
    // 0x8007152C: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x80071530: or          $s1, $s1, $v0
    ctx->r17 = ctx->r17 | ctx->r2;
    // 0x80071534: addu        $a0, $s4, $zero
    ctx->r4 = ADD32(ctx->r20, 0);
    // 0x80071538: addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    // 0x8007153C: lui         $a2, 0x8004
    ctx->r6 = S32(0X8004 << 16);
    // 0x80071540: addiu       $a2, $a2, -0x3354
    ctx->r6 = ADD32(ctx->r6, -0X3354);
    // 0x80071544: addiu       $a3, $zero, 0x81
    ctx->r7 = ADD32(0, 0X81);
    // 0x80071548: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x8007154C: jal         0x80071064
    // 0x80071550: sw          $s3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r19;
    func_80071064(rdram, ctx);
        goto after_9;
    // 0x80071550: sw          $s3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r19;
    after_9:
    // 0x80071554: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x80071558: or          $s1, $s1, $v0
    ctx->r17 = ctx->r17 | ctx->r2;
L_8007155C:
    // 0x8007155C: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x80071560: lw          $v0, 0x10($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X10);
    // 0x80071564: lw          $v0, 0x18($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X18);
    // 0x80071568: andi        $v0, $v0, 0x8
    ctx->r2 = ctx->r2 & 0X8;
    // 0x8007156C: beq         $v0, $zero, L_8007159C
    if (ctx->r2 == 0) {
        // 0x80071570: addu        $a0, $s4, $zero
        ctx->r4 = ADD32(ctx->r20, 0);
            goto L_8007159C;
    }
    // 0x80071570: addu        $a0, $s4, $zero
    ctx->r4 = ADD32(ctx->r20, 0);
    // 0x80071574: addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    // 0x80071578: lui         $a2, 0x8004
    ctx->r6 = S32(0X8004 << 16);
    // 0x8007157C: addiu       $a2, $a2, -0x3364
    ctx->r6 = ADD32(ctx->r6, -0X3364);
    // 0x80071580: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    // 0x80071584: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x80071588: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // 0x8007158C: jal         0x80071064
    // 0x80071590: sw          $s3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r19;
    func_80071064(rdram, ctx);
        goto after_10;
    // 0x80071590: sw          $s3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r19;
    after_10:
    // 0x80071594: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x80071598: or          $s1, $s1, $v0
    ctx->r17 = ctx->r17 | ctx->r2;
L_8007159C:
    // 0x8007159C: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x800715A0: lw          $v0, 0x10($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X10);
    // 0x800715A4: lw          $v0, 0x18($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X18);
    // 0x800715A8: andi        $v0, $v0, 0x10
    ctx->r2 = ctx->r2 & 0X10;
    // 0x800715AC: beq         $v0, $zero, L_800715DC
    if (ctx->r2 == 0) {
        // 0x800715B0: addu        $a0, $s4, $zero
        ctx->r4 = ADD32(ctx->r20, 0);
            goto L_800715DC;
    }
    // 0x800715B0: addu        $a0, $s4, $zero
    ctx->r4 = ADD32(ctx->r20, 0);
    // 0x800715B4: addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    // 0x800715B8: lui         $a2, 0x8004
    ctx->r6 = S32(0X8004 << 16);
    // 0x800715BC: addiu       $a2, $a2, -0x3364
    ctx->r6 = ADD32(ctx->r6, -0X3364);
    // 0x800715C0: addiu       $a3, $zero, 0x6
    ctx->r7 = ADD32(0, 0X6);
    // 0x800715C4: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x800715C8: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // 0x800715CC: jal         0x80071064
    // 0x800715D0: sw          $s3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r19;
    func_80071064(rdram, ctx);
        goto after_11;
    // 0x800715D0: sw          $s3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r19;
    after_11:
    // 0x800715D4: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x800715D8: or          $s1, $s1, $v0
    ctx->r17 = ctx->r17 | ctx->r2;
L_800715DC:
    // 0x800715DC: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x800715E0: lw          $v0, 0x10($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X10);
    // 0x800715E4: lw          $v0, 0x18($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X18);
    // 0x800715E8: andi        $v0, $v0, 0x40
    ctx->r2 = ctx->r2 & 0X40;
    // 0x800715EC: beq         $v0, $zero, L_8007161C
    if (ctx->r2 == 0) {
        // 0x800715F0: addu        $a0, $s4, $zero
        ctx->r4 = ADD32(ctx->r20, 0);
            goto L_8007161C;
    }
    // 0x800715F0: addu        $a0, $s4, $zero
    ctx->r4 = ADD32(ctx->r20, 0);
    // 0x800715F4: addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    // 0x800715F8: lui         $a2, 0x8004
    ctx->r6 = S32(0X8004 << 16);
    // 0x800715FC: addiu       $a2, $a2, -0x3364
    ctx->r6 = ADD32(ctx->r6, -0X3364);
    // 0x80071600: addiu       $a3, $zero, 0x7
    ctx->r7 = ADD32(0, 0X7);
    // 0x80071604: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x80071608: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // 0x8007160C: jal         0x80071064
    // 0x80071610: sw          $s3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r19;
    func_80071064(rdram, ctx);
        goto after_12;
    // 0x80071610: sw          $s3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r19;
    after_12:
    // 0x80071614: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x80071618: or          $s1, $s1, $v0
    ctx->r17 = ctx->r17 | ctx->r2;
L_8007161C:
    // 0x8007161C: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x80071620: lw          $v0, 0x10($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X10);
    // 0x80071624: lw          $v0, 0x18($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X18);
    // 0x80071628: andi        $v0, $v0, 0x80
    ctx->r2 = ctx->r2 & 0X80;
    // 0x8007162C: beq         $v0, $zero, L_8007165C
    if (ctx->r2 == 0) {
        // 0x80071630: addu        $a0, $s4, $zero
        ctx->r4 = ADD32(ctx->r20, 0);
            goto L_8007165C;
    }
    // 0x80071630: addu        $a0, $s4, $zero
    ctx->r4 = ADD32(ctx->r20, 0);
    // 0x80071634: addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    // 0x80071638: lui         $a2, 0x8004
    ctx->r6 = S32(0X8004 << 16);
    // 0x8007163C: addiu       $a2, $a2, -0x335C
    ctx->r6 = ADD32(ctx->r6, -0X335C);
    // 0x80071640: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    // 0x80071644: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x80071648: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // 0x8007164C: jal         0x80071064
    // 0x80071650: sw          $s3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r19;
    func_80071064(rdram, ctx);
        goto after_13;
    // 0x80071650: sw          $s3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r19;
    after_13:
    // 0x80071654: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x80071658: or          $s1, $s1, $v0
    ctx->r17 = ctx->r17 | ctx->r2;
L_8007165C:
    // 0x8007165C: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x80071660: lw          $v0, 0x10($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X10);
    // 0x80071664: lw          $v0, 0x18($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X18);
    // 0x80071668: andi        $v0, $v0, 0x100
    ctx->r2 = ctx->r2 & 0X100;
    // 0x8007166C: beq         $v0, $zero, L_800716C4
    if (ctx->r2 == 0) {
        // 0x80071670: addu        $a0, $s4, $zero
        ctx->r4 = ADD32(ctx->r20, 0);
            goto L_800716C4;
    }
    // 0x80071670: addu        $a0, $s4, $zero
    ctx->r4 = ADD32(ctx->r20, 0);
    // 0x80071674: addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    // 0x80071678: lui         $a2, 0x8004
    ctx->r6 = S32(0X8004 << 16);
    // 0x8007167C: addiu       $a2, $a2, -0x3364
    ctx->r6 = ADD32(ctx->r6, -0X3364);
    // 0x80071680: addiu       $a3, $zero, 0x8A
    ctx->r7 = ADD32(0, 0X8A);
    // 0x80071684: addiu       $s0, $zero, -0x1
    ctx->r16 = ADD32(0, -0X1);
    // 0x80071688: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x8007168C: jal         0x80071064
    // 0x80071690: sw          $s3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r19;
    func_80071064(rdram, ctx);
        goto after_14;
    // 0x80071690: sw          $s3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r19;
    after_14:
    // 0x80071694: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x80071698: or          $s1, $s1, $v0
    ctx->r17 = ctx->r17 | ctx->r2;
    // 0x8007169C: addu        $a0, $s4, $zero
    ctx->r4 = ADD32(ctx->r20, 0);
    // 0x800716A0: addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    // 0x800716A4: lui         $a2, 0x8004
    ctx->r6 = S32(0X8004 << 16);
    // 0x800716A8: addiu       $a2, $a2, -0x335C
    ctx->r6 = ADD32(ctx->r6, -0X335C);
    // 0x800716AC: addiu       $a3, $zero, 0xC9
    ctx->r7 = ADD32(0, 0XC9);
    // 0x800716B0: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x800716B4: jal         0x80071064
    // 0x800716B8: sw          $s3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r19;
    func_80071064(rdram, ctx);
        goto after_15;
    // 0x800716B8: sw          $s3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r19;
    after_15:
    // 0x800716BC: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x800716C0: or          $s1, $s1, $v0
    ctx->r17 = ctx->r17 | ctx->r2;
L_800716C4:
    // 0x800716C4: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x800716C8: lw          $v0, 0x10($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X10);
    // 0x800716CC: lw          $v0, 0x18($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X18);
    // 0x800716D0: andi        $v0, $v0, 0x800
    ctx->r2 = ctx->r2 & 0X800;
    // 0x800716D4: beq         $v0, $zero, L_80071704
    if (ctx->r2 == 0) {
        // 0x800716D8: addu        $a0, $s4, $zero
        ctx->r4 = ADD32(ctx->r20, 0);
            goto L_80071704;
    }
    // 0x800716D8: addu        $a0, $s4, $zero
    ctx->r4 = ADD32(ctx->r20, 0);
    // 0x800716DC: addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    // 0x800716E0: lui         $a2, 0x8004
    ctx->r6 = S32(0X8004 << 16);
    // 0x800716E4: addiu       $a2, $a2, -0x3364
    ctx->r6 = ADD32(ctx->r6, -0X3364);
    // 0x800716E8: addiu       $a3, $zero, 0xC
    ctx->r7 = ADD32(0, 0XC);
    // 0x800716EC: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x800716F0: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // 0x800716F4: jal         0x80071064
    // 0x800716F8: sw          $s3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r19;
    func_80071064(rdram, ctx);
        goto after_16;
    // 0x800716F8: sw          $s3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r19;
    after_16:
    // 0x800716FC: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x80071700: or          $s1, $s1, $v0
    ctx->r17 = ctx->r17 | ctx->r2;
L_80071704:
    // 0x80071704: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x80071708: lw          $v0, 0x10($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X10);
    // 0x8007170C: lw          $v0, 0x18($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X18);
    // 0x80071710: andi        $v0, $v0, 0x1000
    ctx->r2 = ctx->r2 & 0X1000;
    // 0x80071714: beq         $v0, $zero, L_80071744
    if (ctx->r2 == 0) {
        // 0x80071718: addu        $a0, $s4, $zero
        ctx->r4 = ADD32(ctx->r20, 0);
            goto L_80071744;
    }
    // 0x80071718: addu        $a0, $s4, $zero
    ctx->r4 = ADD32(ctx->r20, 0);
    // 0x8007171C: addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    // 0x80071720: lui         $a2, 0x8004
    ctx->r6 = S32(0X8004 << 16);
    // 0x80071724: addiu       $a2, $a2, -0x3364
    ctx->r6 = ADD32(ctx->r6, -0X3364);
    // 0x80071728: addiu       $a3, $zero, 0xD
    ctx->r7 = ADD32(0, 0XD);
    // 0x8007172C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x80071730: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // 0x80071734: jal         0x80071064
    // 0x80071738: sw          $s3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r19;
    func_80071064(rdram, ctx);
        goto after_17;
    // 0x80071738: sw          $s3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r19;
    after_17:
    // 0x8007173C: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x80071740: or          $s1, $s1, $v0
    ctx->r17 = ctx->r17 | ctx->r2;
L_80071744:
    // 0x80071744: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x80071748: lw          $v0, 0x10($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X10);
    // 0x8007174C: lw          $v0, 0x18($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X18);
    // 0x80071750: andi        $v0, $v0, 0x2000
    ctx->r2 = ctx->r2 & 0X2000;
    // 0x80071754: beq         $v0, $zero, L_80071784
    if (ctx->r2 == 0) {
        // 0x80071758: addu        $a0, $s4, $zero
        ctx->r4 = ADD32(ctx->r20, 0);
            goto L_80071784;
    }
    // 0x80071758: addu        $a0, $s4, $zero
    ctx->r4 = ADD32(ctx->r20, 0);
    // 0x8007175C: addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    // 0x80071760: lui         $a2, 0x8004
    ctx->r6 = S32(0X8004 << 16);
    // 0x80071764: addiu       $a2, $a2, -0x3364
    ctx->r6 = ADD32(ctx->r6, -0X3364);
    // 0x80071768: addiu       $a3, $zero, 0xE
    ctx->r7 = ADD32(0, 0XE);
    // 0x8007176C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x80071770: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // 0x80071774: jal         0x80071064
    // 0x80071778: sw          $s3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r19;
    func_80071064(rdram, ctx);
        goto after_18;
    // 0x80071778: sw          $s3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r19;
    after_18:
    // 0x8007177C: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x80071780: or          $s1, $s1, $v0
    ctx->r17 = ctx->r17 | ctx->r2;
L_80071784:
    // 0x80071784: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x80071788: lw          $v0, 0x10($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X10);
    // 0x8007178C: lw          $v0, 0x18($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X18);
    // 0x80071790: andi        $v0, $v0, 0x8000
    ctx->r2 = ctx->r2 & 0X8000;
    // 0x80071794: beq         $v0, $zero, L_800717C4
    if (ctx->r2 == 0) {
        // 0x80071798: addu        $a0, $s4, $zero
        ctx->r4 = ADD32(ctx->r20, 0);
            goto L_800717C4;
    }
    // 0x80071798: addu        $a0, $s4, $zero
    ctx->r4 = ADD32(ctx->r20, 0);
    // 0x8007179C: addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    // 0x800717A0: lui         $a2, 0x8004
    ctx->r6 = S32(0X8004 << 16);
    // 0x800717A4: addiu       $a2, $a2, -0x3364
    ctx->r6 = ADD32(ctx->r6, -0X3364);
    // 0x800717A8: addiu       $a3, $zero, 0x50
    ctx->r7 = ADD32(0, 0X50);
    // 0x800717AC: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x800717B0: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // 0x800717B4: jal         0x80071064
    // 0x800717B8: sw          $s3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r19;
    func_80071064(rdram, ctx);
        goto after_19;
    // 0x800717B8: sw          $s3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r19;
    after_19:
    // 0x800717BC: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x800717C0: or          $s1, $s1, $v0
    ctx->r17 = ctx->r17 | ctx->r2;
L_800717C4:
    // 0x800717C4: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x800717C8: lw          $v0, 0x10($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X10);
    // 0x800717CC: lw          $v0, 0x18($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X18);
    // 0x800717D0: lui         $v1, 0x1
    ctx->r3 = S32(0X1 << 16);
    // 0x800717D4: and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // 0x800717D8: beq         $v0, $zero, L_80071830
    if (ctx->r2 == 0) {
        // 0x800717DC: addu        $a0, $s4, $zero
        ctx->r4 = ADD32(ctx->r20, 0);
            goto L_80071830;
    }
    // 0x800717DC: addu        $a0, $s4, $zero
    ctx->r4 = ADD32(ctx->r20, 0);
    // 0x800717E0: addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    // 0x800717E4: lui         $a2, 0x8004
    ctx->r6 = S32(0X8004 << 16);
    // 0x800717E8: addiu       $a2, $a2, -0x335C
    ctx->r6 = ADD32(ctx->r6, -0X335C);
    // 0x800717EC: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    // 0x800717F0: addiu       $s0, $zero, -0x1
    ctx->r16 = ADD32(0, -0X1);
    // 0x800717F4: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x800717F8: jal         0x80071064
    // 0x800717FC: sw          $s3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r19;
    func_80071064(rdram, ctx);
        goto after_20;
    // 0x800717FC: sw          $s3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r19;
    after_20:
    // 0x80071800: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x80071804: or          $s1, $s1, $v0
    ctx->r17 = ctx->r17 | ctx->r2;
    // 0x80071808: addu        $a0, $s4, $zero
    ctx->r4 = ADD32(ctx->r20, 0);
    // 0x8007180C: addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    // 0x80071810: lui         $a2, 0x8004
    ctx->r6 = S32(0X8004 << 16);
    // 0x80071814: addiu       $a2, $a2, -0x3364
    ctx->r6 = ADD32(ctx->r6, -0X3364);
    // 0x80071818: addiu       $a3, $zero, 0xC
    ctx->r7 = ADD32(0, 0XC);
    // 0x8007181C: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x80071820: jal         0x80071064
    // 0x80071824: sw          $s3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r19;
    func_80071064(rdram, ctx);
        goto after_21;
    // 0x80071824: sw          $s3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r19;
    after_21:
    // 0x80071828: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x8007182C: or          $s1, $s1, $v0
    ctx->r17 = ctx->r17 | ctx->r2;
L_80071830:
    // 0x80071830: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x80071834: lw          $v0, 0x10($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X10);
    // 0x80071838: lw          $v0, 0x18($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X18);
    // 0x8007183C: lui         $v1, 0x2
    ctx->r3 = S32(0X2 << 16);
    // 0x80071840: and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // 0x80071844: beq         $v0, $zero, L_80071874
    if (ctx->r2 == 0) {
        // 0x80071848: addu        $a0, $s4, $zero
        ctx->r4 = ADD32(ctx->r20, 0);
            goto L_80071874;
    }
    // 0x80071848: addu        $a0, $s4, $zero
    ctx->r4 = ADD32(ctx->r20, 0);
    // 0x8007184C: addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    // 0x80071850: lui         $a2, 0x8004
    ctx->r6 = S32(0X8004 << 16);
    // 0x80071854: addiu       $a2, $a2, -0x3364
    ctx->r6 = ADD32(ctx->r6, -0X3364);
    // 0x80071858: addiu       $a3, $zero, 0x11
    ctx->r7 = ADD32(0, 0X11);
    // 0x8007185C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x80071860: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // 0x80071864: jal         0x80071064
    // 0x80071868: sw          $s3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r19;
    func_80071064(rdram, ctx);
        goto after_22;
    // 0x80071868: sw          $s3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r19;
    after_22:
    // 0x8007186C: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x80071870: or          $s1, $s1, $v0
    ctx->r17 = ctx->r17 | ctx->r2;
L_80071874:
    // 0x80071874: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x80071878: lw          $v0, 0x10($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X10);
    // 0x8007187C: lw          $v0, 0x18($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X18);
    // 0x80071880: lui         $v1, 0x4
    ctx->r3 = S32(0X4 << 16);
    // 0x80071884: and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // 0x80071888: beq         $v0, $zero, L_800718B8
    if (ctx->r2 == 0) {
        // 0x8007188C: addu        $a0, $s4, $zero
        ctx->r4 = ADD32(ctx->r20, 0);
            goto L_800718B8;
    }
    // 0x8007188C: addu        $a0, $s4, $zero
    ctx->r4 = ADD32(ctx->r20, 0);
    // 0x80071890: addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    // 0x80071894: lui         $a2, 0x8004
    ctx->r6 = S32(0X8004 << 16);
    // 0x80071898: addiu       $a2, $a2, -0x3364
    ctx->r6 = ADD32(ctx->r6, -0X3364);
    // 0x8007189C: addiu       $a3, $zero, 0x12
    ctx->r7 = ADD32(0, 0X12);
    // 0x800718A0: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x800718A4: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // 0x800718A8: jal         0x80071064
    // 0x800718AC: sw          $s3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r19;
    func_80071064(rdram, ctx);
        goto after_23;
    // 0x800718AC: sw          $s3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r19;
    after_23:
    // 0x800718B0: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x800718B4: or          $s1, $s1, $v0
    ctx->r17 = ctx->r17 | ctx->r2;
L_800718B8:
    // 0x800718B8: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x800718BC: lw          $v0, 0x10($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X10);
    // 0x800718C0: lw          $v0, 0x18($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X18);
    // 0x800718C4: lui         $v1, 0x8
    ctx->r3 = S32(0X8 << 16);
    // 0x800718C8: and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // 0x800718CC: beq         $v0, $zero, L_800718FC
    if (ctx->r2 == 0) {
        // 0x800718D0: addu        $a0, $s4, $zero
        ctx->r4 = ADD32(ctx->r20, 0);
            goto L_800718FC;
    }
    // 0x800718D0: addu        $a0, $s4, $zero
    ctx->r4 = ADD32(ctx->r20, 0);
    // 0x800718D4: addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    // 0x800718D8: lui         $a2, 0x8004
    ctx->r6 = S32(0X8004 << 16);
    // 0x800718DC: addiu       $a2, $a2, -0x335C
    ctx->r6 = ADD32(ctx->r6, -0X335C);
    // 0x800718E0: addiu       $a3, $zero, 0x12
    ctx->r7 = ADD32(0, 0X12);
    // 0x800718E4: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x800718E8: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // 0x800718EC: jal         0x80071064
    // 0x800718F0: sw          $s3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r19;
    func_80071064(rdram, ctx);
        goto after_24;
    // 0x800718F0: sw          $s3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r19;
    after_24:
    // 0x800718F4: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x800718F8: or          $s1, $s1, $v0
    ctx->r17 = ctx->r17 | ctx->r2;
L_800718FC:
    // 0x800718FC: j           L_80071908
    // 0x80071900: slt         $v0, $zero, $s1
    ctx->r2 = SIGNED(0) < SIGNED(ctx->r17) ? 1 : 0;
        goto L_80071908;
    // 0x80071900: slt         $v0, $zero, $s1
    ctx->r2 = SIGNED(0) < SIGNED(ctx->r17) ? 1 : 0;
L_80071904:
    // 0x80071904: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_80071908:
    // 0x80071908: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x8007190C: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x80071910: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x80071914: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80071918: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8007191C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80071920: jr          $ra
    // 0x80071924: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x80071924: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_80071928(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80071928: addiu       $sp, $sp, -0x90
    ctx->r29 = ADD32(ctx->r29, -0X90);
    // 0x8007192C: sw          $s1, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r17;
    // 0x80071930: addu        $s1, $a0, $zero
    ctx->r17 = ADD32(ctx->r4, 0);
    // 0x80071934: sw          $ra, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r31;
    // 0x80071938: sw          $s3, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r19;
    // 0x8007193C: sw          $s2, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r18;
    // 0x80071940: sw          $s0, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r16;
    // 0x80071944: lbu         $v0, 0x4($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X4);
    // 0x80071948: addu        $s2, $a1, $zero
    ctx->r18 = ADD32(ctx->r5, 0);
    // 0x8007194C: sw          $v0, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r2;
    // 0x80071950: lbu         $v0, 0x0($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X0);
    // 0x80071954: andi        $v0, $v0, 0x80
    ctx->r2 = ctx->r2 & 0X80;
    // 0x80071958: beq         $v0, $zero, L_800719B4
    if (ctx->r2 == 0) {
        // 0x8007195C: addu        $s3, $a2, $zero
        ctx->r19 = ADD32(ctx->r6, 0);
            goto L_800719B4;
    }
    // 0x8007195C: addu        $s3, $a2, $zero
    ctx->r19 = ADD32(ctx->r6, 0);
    // 0x80071960: sw          $zero, 0x70($sp)
    MEM_W(0X70, ctx->r29) = 0;
    // 0x80071964: lbu         $v0, 0x4($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X4);
    // 0x80071968: beq         $v0, $zero, L_80071D04
    if (ctx->r2 == 0) {
        // 0x8007196C: addu        $a1, $s2, $zero
        ctx->r5 = ADD32(ctx->r18, 0);
            goto L_80071D04;
    }
    // 0x8007196C: addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
L_80071970:
    // 0x80071970: lw          $v0, 0x70($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X70);
    // 0x80071974: addu        $a2, $s3, $zero
    ctx->r6 = ADD32(ctx->r19, 0);
    // 0x80071978: sll         $a0, $v0, 3
    ctx->r4 = S32(ctx->r2 << 3);
    // 0x8007197C: subu        $a0, $a0, $v0
    ctx->r4 = SUB32(ctx->r4, ctx->r2);
    // 0x80071980: lw          $v0, 0x8($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X8);
    // 0x80071984: sll         $a0, $a0, 3
    ctx->r4 = S32(ctx->r4 << 3);
    // 0x80071988: jal         0x80071928
    // 0x8007198C: addu        $a0, $v0, $a0
    ctx->r4 = ADD32(ctx->r2, ctx->r4);
    func_80071928(rdram, ctx);
        goto after_0;
    // 0x8007198C: addu        $a0, $v0, $a0
    ctx->r4 = ADD32(ctx->r2, ctx->r4);
    after_0:
    // 0x80071990: lw          $v0, 0x70($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X70);
    // 0x80071994: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80071998: sw          $v0, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r2;
    // 0x8007199C: lbu         $v1, 0x4($s1)
    ctx->r3 = MEM_BU(ctx->r17, 0X4);
    // 0x800719A0: slt         $v0, $v0, $v1
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800719A4: bne         $v0, $zero, L_80071970
    if (ctx->r2 != 0) {
        // 0x800719A8: addu        $a1, $s2, $zero
        ctx->r5 = ADD32(ctx->r18, 0);
            goto L_80071970;
    }
    // 0x800719A8: addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    // 0x800719AC: j           L_80071D04
    // 0x800719B0: nop

        goto L_80071D04;
    // 0x800719B0: nop

L_800719B4:
    // 0x800719B4: lbu         $v0, 0x6($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X6);
    // 0x800719B8: beq         $v0, $zero, L_800719DC
    if (ctx->r2 == 0) {
        // 0x800719BC: addu        $v1, $v0, $zero
        ctx->r3 = ADD32(ctx->r2, 0);
            goto L_800719DC;
    }
    // 0x800719BC: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // 0x800719C0: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x800719C4: sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3 << 1);
    // 0x800719C8: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800719CC: lw          $v1, -0x5760($a0)
    ctx->r3 = MEM_W(ctx->r4, -0X5760);
    // 0x800719D0: sll         $v0, $v0, 4
    ctx->r2 = S32(ctx->r2 << 4);
    // 0x800719D4: j           L_80071A78
    // 0x800719D8: addu        $s0, $v1, $v0
    ctx->r16 = ADD32(ctx->r3, ctx->r2);
        goto L_80071A78;
    // 0x800719D8: addu        $s0, $v1, $v0
    ctx->r16 = ADD32(ctx->r3, ctx->r2);
L_800719DC:
    // 0x800719DC: lhu         $v0, 0x8($s2)
    ctx->r2 = MEM_HU(ctx->r18, 0X8);
    // 0x800719E0: andi        $v0, $v0, 0x20
    ctx->r2 = ctx->r2 & 0X20;
    // 0x800719E4: beq         $v0, $zero, L_80071A50
    if (ctx->r2 == 0) {
        // 0x800719E8: lui         $v0, 0x8014
        ctx->r2 = S32(0X8014 << 16);
            goto L_80071A50;
    }
    // 0x800719E8: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x800719EC: lbu         $v1, -0x5768($v0)
    ctx->r3 = MEM_BU(ctx->r2, -0X5768);
    // 0x800719F0: beq         $v1, $zero, L_80071A50
    if (ctx->r3 == 0) {
        // 0x800719F4: addu        $a0, $s2, $zero
        ctx->r4 = ADD32(ctx->r18, 0);
            goto L_80071A50;
    }
    // 0x800719F4: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // 0x800719F8: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x800719FC: addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
    // 0x80071A00: sb          $v1, -0x5768($v0)
    MEM_B(-0X5768, ctx->r2) = ctx->r3;
    // 0x80071A04: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x80071A08: andi        $v1, $v1, 0xFF
    ctx->r3 = ctx->r3 & 0XFF;
    // 0x80071A0C: addiu       $a3, $sp, 0x70
    ctx->r7 = ADD32(ctx->r29, 0X70);
    // 0x80071A10: lw          $v0, -0x5764($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X5764);
    // 0x80071A14: lbu         $a2, 0x5($s1)
    ctx->r6 = MEM_BU(ctx->r17, 0X5);
    // 0x80071A18: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80071A1C: lbu         $v0, 0x0($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X0);
    // 0x80071A20: lui         $v1, 0x8014
    ctx->r3 = S32(0X8014 << 16);
    // 0x80071A24: sb          $v0, 0x6($s1)
    MEM_B(0X6, ctx->r17) = ctx->r2;
    // 0x80071A28: andi        $t0, $v0, 0xFF
    ctx->r8 = ctx->r2 & 0XFF;
    // 0x80071A2C: sll         $v0, $t0, 1
    ctx->r2 = S32(ctx->r8 << 1);
    // 0x80071A30: addu        $v0, $v0, $t0
    ctx->r2 = ADD32(ctx->r2, ctx->r8);
    // 0x80071A34: lw          $v1, -0x5760($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X5760);
    // 0x80071A38: sll         $v0, $v0, 4
    ctx->r2 = S32(ctx->r2 << 4);
    // 0x80071A3C: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x80071A40: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x80071A44: addu        $s0, $v1, $v0
    ctx->r16 = ADD32(ctx->r3, ctx->r2);
    // 0x80071A48: j           L_80071A70
    // 0x80071A4C: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
        goto L_80071A70;
    // 0x80071A4C: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
L_80071A50:
    // 0x80071A50: addiu       $s0, $sp, 0x20
    ctx->r16 = ADD32(ctx->r29, 0X20);
    // 0x80071A54: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // 0x80071A58: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x80071A5C: lbu         $a2, 0x5($s1)
    ctx->r6 = MEM_BU(ctx->r17, 0X5);
    // 0x80071A60: addiu       $a3, $sp, 0x70
    ctx->r7 = ADD32(ctx->r29, 0X70);
    // 0x80071A64: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x80071A68: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x80071A6C: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
L_80071A70:
    // 0x80071A70: jal         0x8005857C
    // 0x80071A74: nop

    func_8005857C(rdram, ctx);
        goto after_1;
    // 0x80071A74: nop

    after_1:
L_80071A78:
    // 0x80071A78: lwc1        $f0, 0x0($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X0);
    // 0x80071A7C: lwc1        $f2, 0x18($s3)
    ctx->f2.u32l = MEM_W(ctx->r19, 0X18);
    // 0x80071A80: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x80071A84: swc1        $f0, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f0.u32l;
    // 0x80071A88: lwc1        $f0, 0x4($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X4);
    // 0x80071A8C: lwc1        $f2, 0x1C($s3)
    ctx->f2.u32l = MEM_W(ctx->r19, 0X1C);
    // 0x80071A90: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x80071A94: swc1        $f0, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f0.u32l;
    // 0x80071A98: lwc1        $f2, 0x8($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X8);
    // 0x80071A9C: lwc1        $f0, 0x20($s3)
    ctx->f0.u32l = MEM_W(ctx->r19, 0X20);
    // 0x80071AA0: sub.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl - ctx->f0.fl;
    // 0x80071AA4: addiu       $a0, $sp, 0x50
    ctx->r4 = ADD32(ctx->r29, 0X50);
    // 0x80071AA8: addiu       $a1, $sp, 0x60
    ctx->r5 = ADD32(ctx->r29, 0X60);
    // 0x80071AAC: jal         0x8001CFA0
    // 0x80071AB0: swc1        $f2, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f2.u32l;
    func_8001CFA0(rdram, ctx);
        goto after_2;
    // 0x80071AB0: swc1        $f2, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f2.u32l;
    after_2:
    // 0x80071AB4: lwc1        $f0, 0xC($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0XC);
    // 0x80071AB8: lwc1        $f2, 0x50($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X50);
    // 0x80071ABC: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x80071AC0: lwc1        $f6, 0x10($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X10);
    // 0x80071AC4: lwc1        $f2, 0x54($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X54);
    // 0x80071AC8: mul.s       $f6, $f6, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f6.fl, ctx->f2.fl);
    // 0x80071ACC: lwc1        $f4, 0x58($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X58);
    // 0x80071AD0: lwc1        $f2, 0x14($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X14);
    // 0x80071AD4: mul.s       $f2, $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f4.fl);
    // 0x80071AD8: add.s       $f0, $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f6.fl;
    // 0x80071ADC: lbu         $v0, 0x0($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X0);
    // 0x80071AE0: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x80071AE4: andi        $v0, $v0, 0x40
    ctx->r2 = ctx->r2 & 0X40;
    // 0x80071AE8: neg.s       $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = -ctx->f0.fl;
    // 0x80071AEC: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80071AF0: lwc1        $f0, -0x334C($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X334C);
    // 0x80071AF4: bnel        $v0, $zero, L_80071B08
    if (ctx->r2 != 0) {
        // 0x80071AF8: add.s       $f6, $f6, $f0
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f0.fl;
            goto L_80071B08;
    }
    goto skip_0;
    // 0x80071AF8: add.s       $f6, $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f0.fl;
    skip_0:
    // 0x80071AFC: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80071B00: lwc1        $f0, -0x3348($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X3348);
    // 0x80071B04: add.s       $f6, $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f0.fl;
L_80071B08:
    // 0x80071B08: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80071B0C: c.lt.s      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.fl < ctx->f0.fl;
    // 0x80071B10: nop

    // 0x80071B14: bc1tl       L_80071B34
    if (c1cs) {
        // 0x80071B18: mov.s       $f6, $f0
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    ctx->f6.fl = ctx->f0.fl;
            goto L_80071B34;
    }
    goto skip_1;
    // 0x80071B18: mov.s       $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    ctx->f6.fl = ctx->f0.fl;
    skip_1:
    // 0x80071B1C: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80071B20: lwc1        $f0, -0x3344($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X3344);
    // 0x80071B24: c.lt.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl < ctx->f6.fl;
    // 0x80071B28: nop

    // 0x80071B2C: bc1tl       L_80071B34
    if (c1cs) {
        // 0x80071B30: mov.s       $f6, $f0
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    ctx->f6.fl = ctx->f0.fl;
            goto L_80071B34;
    }
    goto skip_2;
    // 0x80071B30: mov.s       $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    ctx->f6.fl = ctx->f0.fl;
    skip_2:
L_80071B34:
    // 0x80071B34: lbu         $v1, 0x1($s1)
    ctx->r3 = MEM_BU(ctx->r17, 0X1);
    // 0x80071B38: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80071B3C: beq         $v1, $v0, L_80071B6C
    if (ctx->r3 == ctx->r2) {
        // 0x80071B40: addiu       $v0, $zero, 0x100
        ctx->r2 = ADD32(0, 0X100);
            goto L_80071B6C;
    }
    // 0x80071B40: addiu       $v0, $zero, 0x100
    ctx->r2 = ADD32(0, 0X100);
    // 0x80071B44: slti        $v0, $v1, 0x2
    ctx->r2 = SIGNED(ctx->r3) < 0X2 ? 1 : 0;
    // 0x80071B48: bnel        $v0, $zero, L_80071BB0
    if (ctx->r2 != 0) {
        // 0x80071B4C: lui         $v1, 0x800A
        ctx->r3 = S32(0X800A << 16);
            goto L_80071BB0;
    }
    goto skip_3;
    // 0x80071B4C: lui         $v1, 0x800A
    ctx->r3 = S32(0X800A << 16);
    skip_3:
    // 0x80071B50: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x80071B54: beq         $v1, $v0, L_80071B80
    if (ctx->r3 == ctx->r2) {
        // 0x80071B58: addiu       $v0, $zero, 0x3
        ctx->r2 = ADD32(0, 0X3);
            goto L_80071B80;
    }
    // 0x80071B58: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x80071B5C: beq         $v1, $v0, L_80071B8C
    if (ctx->r3 == ctx->r2) {
        // 0x80071B60: lui         $v1, 0x800A
        ctx->r3 = S32(0X800A << 16);
            goto L_80071B8C;
    }
    // 0x80071B60: lui         $v1, 0x800A
    ctx->r3 = S32(0X800A << 16);
    // 0x80071B64: j           L_80071BB0
    // 0x80071B68: nop

        goto L_80071BB0;
    // 0x80071B68: nop

L_80071B6C:
    // 0x80071B6C: lh          $v1, 0x2($s1)
    ctx->r3 = MEM_H(ctx->r17, 0X2);
    // 0x80071B70: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80071B74: lwc1        $f2, -0x3340($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X3340);
    // 0x80071B78: j           L_80071B98
    // 0x80071B7C: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
        goto L_80071B98;
    // 0x80071B7C: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
L_80071B80:
    // 0x80071B80: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80071B84: j           L_80071BB0
    // 0x80071B88: lui         $v1, 0x800A
    ctx->r3 = S32(0X800A << 16);
        goto L_80071BB0;
    // 0x80071B88: lui         $v1, 0x800A
    ctx->r3 = S32(0X800A << 16);
L_80071B8C:
    // 0x80071B8C: lh          $v0, 0x2($s1)
    ctx->r2 = MEM_H(ctx->r17, 0X2);
    // 0x80071B90: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80071B94: lwc1        $f2, -0x333C($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X333C);
L_80071B98:
    // 0x80071B98: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x80071B9C: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x80071BA0: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x80071BA4: nop

    // 0x80071BA8: mul.s       $f6, $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x80071BAC: lui         $v1, 0x800A
    ctx->r3 = S32(0X800A << 16);
L_80071BB0:
    // 0x80071BB0: lbu         $v0, 0x0($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X0);
    // 0x80071BB4: addiu       $v1, $v1, 0xB38
    ctx->r3 = ADD32(ctx->r3, 0XB38);
    // 0x80071BB8: andi        $v0, $v0, 0x1F
    ctx->r2 = ctx->r2 & 0X1F;
    // 0x80071BBC: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80071BC0: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80071BC4: lbu         $v0, 0x3($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X3);
    // 0x80071BC8: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x80071BCC: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x80071BD0: mul.s       $f0, $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x80071BD4: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80071BD8: lwc1        $f2, -0x3338($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X3338);
    // 0x80071BDC: c.le.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl <= ctx->f0.fl;
    // 0x80071BE0: nop

    // 0x80071BE4: bc1tl       L_80071BFC
    if (c1cs) {
        // 0x80071BE8: sub.s       $f0, $f0, $f2
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
            goto L_80071BFC;
    }
    goto skip_4;
    // 0x80071BE8: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    skip_4:
    // 0x80071BEC: trunc.w.s   $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    ctx->f8.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x80071BF0: mfc1        $v1, $f8
    ctx->r3 = (int32_t)ctx->f8.u32l;
    // 0x80071BF4: j           L_80071C10
    // 0x80071BF8: sb          $v1, 0x37($s1)
    MEM_B(0X37, ctx->r17) = ctx->r3;
        goto L_80071C10;
    // 0x80071BF8: sb          $v1, 0x37($s1)
    MEM_B(0X37, ctx->r17) = ctx->r3;
L_80071BFC:
    // 0x80071BFC: lui         $v0, 0x8000
    ctx->r2 = S32(0X8000 << 16);
    // 0x80071C00: trunc.w.s   $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    ctx->f8.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x80071C04: mfc1        $v1, $f8
    ctx->r3 = (int32_t)ctx->f8.u32l;
    // 0x80071C08: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x80071C0C: sb          $v1, 0x37($s1)
    MEM_B(0X37, ctx->r17) = ctx->r3;
L_80071C10:
    // 0x80071C10: andi        $v0, $v1, 0xFF
    ctx->r2 = ctx->r3 & 0XFF;
    // 0x80071C14: sltiu       $v0, $v0, 0x4
    ctx->r2 = ctx->r2 < 0X4 ? 1 : 0;
    // 0x80071C18: bne         $v0, $zero, L_80071D04
    if (ctx->r2 != 0) {
        // 0x80071C1C: lui         $v1, 0x800A
        ctx->r3 = S32(0X800A << 16);
            goto L_80071D04;
    }
    // 0x80071C1C: lui         $v1, 0x800A
    ctx->r3 = S32(0X800A << 16);
    // 0x80071C20: lwc1        $f6, 0x50($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X50);
    // 0x80071C24: lwc1        $f0, 0x24($s3)
    ctx->f0.u32l = MEM_W(ctx->r19, 0X24);
    // 0x80071C28: mul.s       $f6, $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x80071C2C: lwc1        $f4, 0x54($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X54);
    // 0x80071C30: lwc1        $f0, 0x28($s3)
    ctx->f0.u32l = MEM_W(ctx->r19, 0X28);
    // 0x80071C34: mul.s       $f4, $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x80071C38: lwc1        $f2, 0x2C($s3)
    ctx->f2.u32l = MEM_W(ctx->r19, 0X2C);
    // 0x80071C3C: lwc1        $f0, 0x58($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X58);
    // 0x80071C40: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x80071C44: add.s       $f6, $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f4.fl;
    // 0x80071C48: add.s       $f6, $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f0.fl;
    // 0x80071C4C: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80071C50: lwc1        $f0, -0x3334($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X3334);
    // 0x80071C54: lbu         $v0, 0x0($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X0);
    // 0x80071C58: mul.s       $f0, $f6, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x80071C5C: addiu       $v1, $v1, 0xBD0
    ctx->r3 = ADD32(ctx->r3, 0XBD0);
    // 0x80071C60: andi        $v0, $v0, 0x1F
    ctx->r2 = ctx->r2 & 0X1F;
    // 0x80071C64: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80071C68: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80071C6C: swc1        $f0, 0x24($s1)
    MEM_W(0X24, ctx->r17) = ctx->f0.u32l;
    // 0x80071C70: lwc1        $f6, 0x0($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X0);
    // 0x80071C74: lwc1        $f2, 0x50($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X50);
    // 0x80071C78: mul.s       $f2, $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f6.fl);
    // 0x80071C7C: lwc1        $f0, 0x60($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X60);
    // 0x80071C80: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x80071C84: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80071C88: lwc1        $f4, -0x3330($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X3330);
    // 0x80071C8C: mul.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x80071C90: trunc.w.s   $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    ctx->f8.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x80071C94: mfc1        $v0, $f8
    ctx->r2 = (int32_t)ctx->f8.u32l;
    // 0x80071C98: sh          $v0, 0x10($s1)
    MEM_H(0X10, ctx->r17) = ctx->r2;
    // 0x80071C9C: lwc1        $f2, 0x54($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X54);
    // 0x80071CA0: mul.s       $f2, $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f6.fl);
    // 0x80071CA4: lwc1        $f0, 0x64($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X64);
    // 0x80071CA8: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x80071CAC: mul.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x80071CB0: trunc.w.s   $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    ctx->f8.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x80071CB4: mfc1        $v0, $f8
    ctx->r2 = (int32_t)ctx->f8.u32l;
    // 0x80071CB8: sh          $v0, 0x12($s1)
    MEM_H(0X12, ctx->r17) = ctx->r2;
    // 0x80071CBC: lwc1        $f2, 0x58($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X58);
    // 0x80071CC0: mul.s       $f2, $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f6.fl);
    // 0x80071CC4: lwc1        $f0, 0x68($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X68);
    // 0x80071CC8: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x80071CCC: mul.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x80071CD0: trunc.w.s   $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    ctx->f8.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x80071CD4: mfc1        $v0, $f8
    ctx->r2 = (int32_t)ctx->f8.u32l;
    // 0x80071CD8: sh          $v0, 0x14($s1)
    MEM_H(0X14, ctx->r17) = ctx->r2;
    // 0x80071CDC: lw          $v0, 0x48($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X48);
    // 0x80071CE0: lw          $v1, 0x20($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X20);
    // 0x80071CE4: beq         $v1, $zero, L_80071CF4
    if (ctx->r3 == 0) {
        // 0x80071CE8: sw          $v1, 0x8($s1)
        MEM_W(0X8, ctx->r17) = ctx->r3;
            goto L_80071CF4;
    }
    // 0x80071CE8: sw          $v1, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->r3;
    // 0x80071CEC: addiu       $v0, $s1, 0x8
    ctx->r2 = ADD32(ctx->r17, 0X8);
    // 0x80071CF0: sw          $v0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r2;
L_80071CF4:
    // 0x80071CF4: sw          $zero, 0xC($s1)
    MEM_W(0XC, ctx->r17) = 0;
    // 0x80071CF8: lw          $v1, 0x48($s3)
    ctx->r3 = MEM_W(ctx->r19, 0X48);
    // 0x80071CFC: addiu       $v0, $s1, 0x8
    ctx->r2 = ADD32(ctx->r17, 0X8);
    // 0x80071D00: sw          $v0, 0x20($v1)
    MEM_W(0X20, ctx->r3) = ctx->r2;
L_80071D04:
    // 0x80071D04: lw          $ra, 0x88($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X88);
    // 0x80071D08: lw          $s3, 0x84($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X84);
    // 0x80071D0C: lw          $s2, 0x80($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X80);
    // 0x80071D10: lw          $s1, 0x7C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X7C);
    // 0x80071D14: lw          $s0, 0x78($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X78);
    // 0x80071D18: jr          $ra
    // 0x80071D1C: addiu       $sp, $sp, 0x90
    ctx->r29 = ADD32(ctx->r29, 0X90);
    return;
    // 0x80071D1C: addiu       $sp, $sp, 0x90
    ctx->r29 = ADD32(ctx->r29, 0X90);
;}
RECOMP_FUNC void func_80071D20(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80071D20: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80071D24: lui         $a0, 0x8004
    ctx->r4 = S32(0X8004 << 16);
    // 0x80071D28: addiu       $a0, $a0, -0x314C
    ctx->r4 = ADD32(ctx->r4, -0X314C);
    // 0x80071D2C: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x80071D30: addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    // 0x80071D34: addu        $a3, $a1, $zero
    ctx->r7 = ADD32(ctx->r5, 0);
    // 0x80071D38: sw          $ra, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r31;
    // 0x80071D3C: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x80071D40: jal         0x8005645C
    // 0x80071D44: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    load_hmt_and_hob(rdram, ctx);
        goto after_0;
    // 0x80071D44: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    after_0:
    // 0x80071D48: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x80071D4C: addiu       $s0, $v0, -0x5990
    ctx->r16 = ADD32(ctx->r2, -0X5990);
    // 0x80071D50: addiu       $a0, $s0, 0x1C
    ctx->r4 = ADD32(ctx->r16, 0X1C);
    // 0x80071D54: addiu       $s1, $s0, 0x4C
    ctx->r17 = ADD32(ctx->r16, 0X4C);
    // 0x80071D58: sw          $zero, 0xC($s0)
    MEM_W(0XC, ctx->r16) = 0;
    // 0x80071D5C: sw          $zero, 0x8($s0)
    MEM_W(0X8, ctx->r16) = 0;
    // 0x80071D60: sw          $zero, 0x4($s0)
    MEM_W(0X4, ctx->r16) = 0;
    // 0x80071D64: sw          $zero, -0x5990($v0)
    MEM_W(-0X5990, ctx->r2) = 0;
    // 0x80071D68: sw          $s1, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->r17;
    // 0x80071D6C: jal         0x8001CA50
    // 0x80071D70: sw          $zero, 0x14($s0)
    MEM_W(0X14, ctx->r16) = 0;
    func_8001CA50(rdram, ctx);
        goto after_1;
    // 0x80071D70: sw          $zero, 0x14($s0)
    MEM_W(0X14, ctx->r16) = 0;
    after_1:
    // 0x80071D74: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x80071D78: lui         $v0, 0x10
    ctx->r2 = S32(0X10 << 16);
    // 0x80071D7C: sw          $v0, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->r2;
    // 0x80071D80: addiu       $v0, $s0, 0xA8
    ctx->r2 = ADD32(ctx->r16, 0XA8);
    // 0x80071D84: sw          $zero, 0x50($s0)
    MEM_W(0X50, ctx->r16) = 0;
    // 0x80071D88: sw          $zero, 0x4C($s0)
    MEM_W(0X4C, ctx->r16) = 0;
    // 0x80071D8C: sw          $zero, 0x54($s0)
    MEM_W(0X54, ctx->r16) = 0;
    // 0x80071D90: sw          $zero, 0x68($s0)
    MEM_W(0X68, ctx->r16) = 0;
    // 0x80071D94: sw          $zero, 0x5C($s0)
    MEM_W(0X5C, ctx->r16) = 0;
    // 0x80071D98: sw          $zero, 0x60($s0)
    MEM_W(0X60, ctx->r16) = 0;
    // 0x80071D9C: sw          $zero, 0x64($s0)
    MEM_W(0X64, ctx->r16) = 0;
    // 0x80071DA0: sw          $v0, 0x6C($s0)
    MEM_W(0X6C, ctx->r16) = ctx->r2;
    // 0x80071DA4: sw          $zero, 0x70($s0)
    MEM_W(0X70, ctx->r16) = 0;
    // 0x80071DA8: jal         0x8000A85C
    // 0x80071DAC: sw          $zero, 0x74($s0)
    MEM_W(0X74, ctx->r16) = 0;
    func_8000A85C(rdram, ctx);
        goto after_2;
    // 0x80071DAC: sw          $zero, 0x74($s0)
    MEM_W(0X74, ctx->r16) = 0;
    after_2:
    // 0x80071DB0: addiu       $v0, $s0, 0xB8
    ctx->r2 = ADD32(ctx->r16, 0XB8);
    // 0x80071DB4: addu        $a3, $v0, $zero
    ctx->r7 = ADD32(ctx->r2, 0);
    // 0x80071DB8: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // 0x80071DBC: addiu       $t6, $zero, 0x9E
    ctx->r14 = ADD32(0, 0X9E);
    // 0x80071DC0: lui         $t3, 0xD0C
    ctx->r11 = S32(0XD0C << 16);
    // 0x80071DC4: ori         $t3, $t3, 0x9005
    ctx->r11 = ctx->r11 | 0X9005;
    // 0x80071DC8: addiu       $t5, $zero, 0x7
    ctx->r13 = ADD32(0, 0X7);
    // 0x80071DCC: lui         $t0, 0x9249
    ctx->r8 = S32(0X9249 << 16);
    // 0x80071DD0: ori         $t0, $t0, 0x2493
    ctx->r8 = ctx->r8 | 0X2493;
    // 0x80071DD4: addiu       $t4, $zero, 0x6
    ctx->r12 = ADD32(0, 0X6);
    // 0x80071DD8: addiu       $t1, $zero, 0x1000
    ctx->r9 = ADD32(0, 0X1000);
    // 0x80071DDC: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80071DE0: lw          $v0, 0xC08($v0)
    ctx->r2 = MEM_W(ctx->r2, 0XC08);
    // 0x80071DE4: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x80071DE8: sw          $zero, 0xAC($s0)
    MEM_W(0XAC, ctx->r16) = 0;
    // 0x80071DEC: sw          $zero, 0xA8($s0)
    MEM_W(0XA8, ctx->r16) = 0;
    // 0x80071DF0: sw          $a3, 0xB0($s0)
    MEM_W(0XB0, ctx->r16) = ctx->r7;
    // 0x80071DF4: sw          $zero, 0xB4($s0)
    MEM_W(0XB4, ctx->r16) = 0;
    // 0x80071DF8: lhu         $v0, 0x22($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X22);
    // 0x80071DFC: addiu       $s0, $s0, 0xEB
    ctx->r16 = ADD32(ctx->r16, 0XEB);
    // 0x80071E00: sll         $t2, $v0, 16
    ctx->r10 = S32(ctx->r2 << 16);
L_80071E04:
    // 0x80071E04: sw          $t6, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r14;
    // 0x80071E08: addiu       $a3, $a3, 0x34
    ctx->r7 = ADD32(ctx->r7, 0X34);
    // 0x80071E0C: subu        $v1, $t5, $a2
    ctx->r3 = SUB32(ctx->r13, ctx->r6);
    // 0x80071E10: subu        $a0, $t4, $a2
    ctx->r4 = SUB32(ctx->r12, ctx->r6);
    // 0x80071E14: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x80071E18: sll         $v1, $v1, 12
    ctx->r3 = S32(ctx->r3 << 12);
    // 0x80071E1C: sll         $a0, $a0, 12
    ctx->r4 = S32(ctx->r4 << 12);
    // 0x80071E20: mult        $v1, $t0
    result = S64(S32(ctx->r3)) * S64(S32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80071E24: sw          $t3, -0x2F($s0)
    MEM_W(-0X2F, ctx->r16) = ctx->r11;
    // 0x80071E28: sw          $t2, -0x2B($s0)
    MEM_W(-0X2B, ctx->r16) = ctx->r10;
    // 0x80071E2C: sh          $zero, -0x13($s0)
    MEM_H(-0X13, ctx->r16) = 0;
    // 0x80071E30: sh          $zero, -0x1F($s0)
    MEM_H(-0X1F, ctx->r16) = 0;
    // 0x80071E34: sh          $t1, -0x17($s0)
    MEM_H(-0X17, ctx->r16) = ctx->r9;
    // 0x80071E38: sh          $t1, -0x1B($s0)
    MEM_H(-0X1B, ctx->r16) = ctx->r9;
    // 0x80071E3C: sb          $a1, -0xF($s0)
    MEM_B(-0XF, ctx->r16) = ctx->r5;
    // 0x80071E40: sb          $a1, -0xE($s0)
    MEM_B(-0XE, ctx->r16) = ctx->r5;
    // 0x80071E44: sb          $a1, -0xD($s0)
    MEM_B(-0XD, ctx->r16) = ctx->r5;
    // 0x80071E48: sb          $a1, -0xC($s0)
    MEM_B(-0XC, ctx->r16) = ctx->r5;
    // 0x80071E4C: sb          $a1, -0xB($s0)
    MEM_B(-0XB, ctx->r16) = ctx->r5;
    // 0x80071E50: sb          $a1, -0xA($s0)
    MEM_B(-0XA, ctx->r16) = ctx->r5;
    // 0x80071E54: sb          $a1, -0x9($s0)
    MEM_B(-0X9, ctx->r16) = ctx->r5;
    // 0x80071E58: sb          $a1, -0x8($s0)
    MEM_B(-0X8, ctx->r16) = ctx->r5;
    // 0x80071E5C: sb          $a1, -0x7($s0)
    MEM_B(-0X7, ctx->r16) = ctx->r5;
    // 0x80071E60: sb          $a1, -0x6($s0)
    MEM_B(-0X6, ctx->r16) = ctx->r5;
    // 0x80071E64: sb          $a1, -0x5($s0)
    MEM_B(-0X5, ctx->r16) = ctx->r5;
    // 0x80071E68: sb          $a1, -0x4($s0)
    MEM_B(-0X4, ctx->r16) = ctx->r5;
    // 0x80071E6C: sb          $a1, -0x3($s0)
    MEM_B(-0X3, ctx->r16) = ctx->r5;
    // 0x80071E70: sb          $a1, -0x2($s0)
    MEM_B(-0X2, ctx->r16) = ctx->r5;
    // 0x80071E74: sb          $a1, -0x1($s0)
    MEM_B(-0X1, ctx->r16) = ctx->r5;
    // 0x80071E78: sb          $a1, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r5;
    // 0x80071E7C: mfhi        $t7
    ctx->r15 = hi;
    // 0x80071E80: addu        $v0, $t7, $v1
    ctx->r2 = ADD32(ctx->r15, ctx->r3);
    // 0x80071E84: sra         $v0, $v0, 2
    ctx->r2 = S32(SIGNED(ctx->r2) >> 2);
    // 0x80071E88: mult        $a0, $t0
    result = S64(S32(ctx->r4)) * S64(S32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80071E8C: sra         $v1, $v1, 31
    ctx->r3 = S32(SIGNED(ctx->r3) >> 31);
    // 0x80071E90: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x80071E94: sh          $v0, -0x19($s0)
    MEM_H(-0X19, ctx->r16) = ctx->r2;
    // 0x80071E98: sh          $v0, -0x1D($s0)
    MEM_H(-0X1D, ctx->r16) = ctx->r2;
    // 0x80071E9C: mfhi        $t7
    ctx->r15 = hi;
    // 0x80071EA0: addu        $v0, $t7, $a0
    ctx->r2 = ADD32(ctx->r15, ctx->r4);
    // 0x80071EA4: sra         $v0, $v0, 2
    ctx->r2 = S32(SIGNED(ctx->r2) >> 2);
    // 0x80071EA8: sra         $a0, $a0, 31
    ctx->r4 = S32(SIGNED(ctx->r4) >> 31);
    // 0x80071EAC: subu        $v0, $v0, $a0
    ctx->r2 = SUB32(ctx->r2, ctx->r4);
    // 0x80071EB0: sh          $v0, -0x11($s0)
    MEM_H(-0X11, ctx->r16) = ctx->r2;
    // 0x80071EB4: sh          $v0, -0x15($s0)
    MEM_H(-0X15, ctx->r16) = ctx->r2;
    // 0x80071EB8: slti        $v0, $a2, 0x7
    ctx->r2 = SIGNED(ctx->r6) < 0X7 ? 1 : 0;
    // 0x80071EBC: bne         $v0, $zero, L_80071E04
    if (ctx->r2 != 0) {
        // 0x80071EC0: addiu       $s0, $s0, 0x34
        ctx->r16 = ADD32(ctx->r16, 0X34);
            goto L_80071E04;
    }
    // 0x80071EC0: addiu       $s0, $s0, 0x34
    ctx->r16 = ADD32(ctx->r16, 0X34);
    // 0x80071EC4: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x80071EC8: lw          $v1, 0xC1C($a0)
    ctx->r3 = MEM_W(ctx->r4, 0XC1C);
    // 0x80071ECC: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x80071ED0: beq         $v1, $zero, L_80071F30
    if (ctx->r3 == 0) {
        // 0x80071ED4: sw          $zero, -0x576C($v0)
        MEM_W(-0X576C, ctx->r2) = 0;
            goto L_80071F30;
    }
    // 0x80071ED4: sw          $zero, -0x576C($v0)
    MEM_W(-0X576C, ctx->r2) = 0;
    // 0x80071ED8: addiu       $s0, $a0, 0xC1C
    ctx->r16 = ADD32(ctx->r4, 0XC1C);
L_80071EDC:
    // 0x80071EDC: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80071EE0: jal         0x80056DA4
    // 0x80071EE4: nop

    isHobObjectLoaded(rdram, ctx);
        goto after_3;
    // 0x80071EE4: nop

    after_3:
    // 0x80071EE8: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x80071EEC: beql        $v0, $zero, L_80071F24
    if (ctx->r2 == 0) {
        // 0x80071EF0: addiu       $s0, $s0, 0x8
        ctx->r16 = ADD32(ctx->r16, 0X8);
            goto L_80071F24;
    }
    goto skip_0;
    // 0x80071EF0: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    skip_0:
    // 0x80071EF4: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80071EF8: jal         0x80056EB0
    // 0x80071EFC: nop

    func_80056EB0(rdram, ctx);
        goto after_4;
    // 0x80071EFC: nop

    after_4:
    // 0x80071F00: lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X0);
    // 0x80071F04: lw          $a2, 0x10($v1)
    ctx->r6 = MEM_W(ctx->r3, 0X10);
    // 0x80071F08: lw          $a1, 0x4($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X4);
    // 0x80071F0C: lw          $v1, 0x18($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X18);
    // 0x80071F10: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // 0x80071F14: or          $v1, $v1, $a1
    ctx->r3 = ctx->r3 | ctx->r5;
    // 0x80071F18: jal         0x8005779C
    // 0x80071F1C: sw          $v1, 0x18($a2)
    MEM_W(0X18, ctx->r6) = ctx->r3;
    func_8005779C(rdram, ctx);
        goto after_5;
    // 0x80071F1C: sw          $v1, 0x18($a2)
    MEM_W(0X18, ctx->r6) = ctx->r3;
    after_5:
    // 0x80071F20: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
L_80071F24:
    // 0x80071F24: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80071F28: bne         $v0, $zero, L_80071EDC
    if (ctx->r2 != 0) {
        // 0x80071F2C: nop
    
            goto L_80071EDC;
    }
    // 0x80071F2C: nop

L_80071F30:
    // 0x80071F30: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80071F34: lbu         $v0, 0xB63($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0XB63);
    // 0x80071F38: beq         $v0, $zero, L_80071F4C
    if (ctx->r2 == 0) {
        // 0x80071F3C: lui         $v1, 0x8014
        ctx->r3 = S32(0X8014 << 16);
            goto L_80071F4C;
    }
    // 0x80071F3C: lui         $v1, 0x8014
    ctx->r3 = S32(0X8014 << 16);
    // 0x80071F40: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // 0x80071F44: j           L_80071FA0
    // 0x80071F48: sb          $v0, -0x5768($v1)
    MEM_B(-0X5768, ctx->r3) = ctx->r2;
        goto L_80071FA0;
    // 0x80071F48: sb          $v0, -0x5768($v1)
    MEM_B(-0X5768, ctx->r3) = ctx->r2;
L_80071F4C:
    // 0x80071F4C: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80071F50: lw          $v1, 0xB70($v0)
    ctx->r3 = MEM_W(ctx->r2, 0XB70);
    // 0x80071F54: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // 0x80071F58: beq         $v1, $v0, L_80071F88
    if (ctx->r3 == ctx->r2) {
        // 0x80071F5C: slti        $v0, $v1, 0x5
        ctx->r2 = SIGNED(ctx->r3) < 0X5 ? 1 : 0;
            goto L_80071F88;
    }
    // 0x80071F5C: slti        $v0, $v1, 0x5
    ctx->r2 = SIGNED(ctx->r3) < 0X5 ? 1 : 0;
    // 0x80071F60: beq         $v0, $zero, L_80071F78
    if (ctx->r2 == 0) {
        // 0x80071F64: slti        $v0, $v1, 0xB
        ctx->r2 = SIGNED(ctx->r3) < 0XB ? 1 : 0;
            goto L_80071F78;
    }
    // 0x80071F64: slti        $v0, $v1, 0xB
    ctx->r2 = SIGNED(ctx->r3) < 0XB ? 1 : 0;
    // 0x80071F68: beq         $v1, $zero, L_80071F88
    if (ctx->r3 == 0) {
        // 0x80071F6C: lui         $v0, 0x8014
        ctx->r2 = S32(0X8014 << 16);
            goto L_80071F88;
    }
    // 0x80071F6C: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x80071F70: j           L_80071FA0
    // 0x80071F74: sb          $zero, -0x5768($v0)
    MEM_B(-0X5768, ctx->r2) = 0;
        goto L_80071FA0;
    // 0x80071F74: sb          $zero, -0x5768($v0)
    MEM_B(-0X5768, ctx->r2) = 0;
L_80071F78:
    // 0x80071F78: beq         $v0, $zero, L_80071F98
    if (ctx->r2 == 0) {
        // 0x80071F7C: slti        $v0, $v1, 0x9
        ctx->r2 = SIGNED(ctx->r3) < 0X9 ? 1 : 0;
            goto L_80071F98;
    }
    // 0x80071F7C: slti        $v0, $v1, 0x9
    ctx->r2 = SIGNED(ctx->r3) < 0X9 ? 1 : 0;
    // 0x80071F80: bne         $v0, $zero, L_80071F9C
    if (ctx->r2 != 0) {
        // 0x80071F84: lui         $v0, 0x8014
        ctx->r2 = S32(0X8014 << 16);
            goto L_80071F9C;
    }
    // 0x80071F84: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
L_80071F88:
    // 0x80071F88: lui         $v1, 0x8014
    ctx->r3 = S32(0X8014 << 16);
    // 0x80071F8C: addiu       $v0, $zero, 0xAA
    ctx->r2 = ADD32(0, 0XAA);
    // 0x80071F90: j           L_80071FA0
    // 0x80071F94: sb          $v0, -0x5768($v1)
    MEM_B(-0X5768, ctx->r3) = ctx->r2;
        goto L_80071FA0;
    // 0x80071F94: sb          $v0, -0x5768($v1)
    MEM_B(-0X5768, ctx->r3) = ctx->r2;
L_80071F98:
    // 0x80071F98: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
L_80071F9C:
    // 0x80071F9C: sb          $zero, -0x5768($v0)
    MEM_B(-0X5768, ctx->r2) = 0;
L_80071FA0:
    // 0x80071FA0: lui         $s0, 0x8014
    ctx->r16 = S32(0X8014 << 16);
    // 0x80071FA4: lbu         $v0, -0x5768($s0)
    ctx->r2 = MEM_BU(ctx->r16, -0X5768);
    // 0x80071FA8: beq         $v0, $zero, L_80072018
    if (ctx->r2 == 0) {
        // 0x80071FAC: nop
    
            goto L_80072018;
    }
    // 0x80071FAC: nop

    // 0x80071FB0: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // 0x80071FB4: jal         0x80001ACC
    // 0x80071FB8: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    rs_malloc(rdram, ctx);
        goto after_6;
    // 0x80071FB8: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    after_6:
    // 0x80071FBC: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x80071FC0: lbu         $v1, -0x5768($s0)
    ctx->r3 = MEM_BU(ctx->r16, -0X5768);
    // 0x80071FC4: lui         $s1, 0x8014
    ctx->r17 = S32(0X8014 << 16);
    // 0x80071FC8: sw          $v0, -0x5764($s1)
    MEM_W(-0X5764, ctx->r17) = ctx->r2;
    // 0x80071FCC: sll         $a0, $v1, 1
    ctx->r4 = S32(ctx->r3 << 1);
    // 0x80071FD0: addu        $a0, $a0, $v1
    ctx->r4 = ADD32(ctx->r4, ctx->r3);
    // 0x80071FD4: jal         0x80001ACC
    // 0x80071FD8: sll         $a0, $a0, 4
    ctx->r4 = S32(ctx->r4 << 4);
    rs_malloc(rdram, ctx);
        goto after_7;
    // 0x80071FD8: sll         $a0, $a0, 4
    ctx->r4 = S32(ctx->r4 << 4);
    after_7:
    // 0x80071FDC: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // 0x80071FE0: lbu         $a0, -0x5768($s0)
    ctx->r4 = MEM_BU(ctx->r16, -0X5768);
    // 0x80071FE4: lui         $v1, 0x8014
    ctx->r3 = S32(0X8014 << 16);
    // 0x80071FE8: beq         $a0, $zero, L_80072018
    if (ctx->r4 == 0) {
        // 0x80071FEC: sw          $v0, -0x5760($v1)
        MEM_W(-0X5760, ctx->r3) = ctx->r2;
            goto L_80072018;
    }
    // 0x80071FEC: sw          $v0, -0x5760($v1)
    MEM_W(-0X5760, ctx->r3) = ctx->r2;
    // 0x80071FF0: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x80071FF4: addu        $v1, $s0, $zero
    ctx->r3 = ADD32(ctx->r16, 0);
L_80071FF8:
    // 0x80071FF8: lw          $v0, -0x5764($a0)
    ctx->r2 = MEM_W(ctx->r4, -0X5764);
    // 0x80071FFC: addu        $v0, $v0, $a2
    ctx->r2 = ADD32(ctx->r2, ctx->r6);
    // 0x80072000: sb          $a2, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r6;
    // 0x80072004: lbu         $v0, -0x5768($v1)
    ctx->r2 = MEM_BU(ctx->r3, -0X5768);
    // 0x80072008: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x8007200C: slt         $v0, $a2, $v0
    ctx->r2 = SIGNED(ctx->r6) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80072010: bne         $v0, $zero, L_80071FF8
    if (ctx->r2 != 0) {
        // 0x80072014: nop
    
            goto L_80071FF8;
    }
    // 0x80072014: nop

L_80072018:
    // 0x80072018: lw          $ra, 0x18($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X18);
    // 0x8007201C: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x80072020: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x80072024: jr          $ra
    // 0x80072028: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80072028: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_8007202C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007202C: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x80072030: sdc1        $f20, 0x58($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X58, ctx->r29);
    // 0x80072034: mtc1        $a2, $f20
    ctx->f20.u32l = ctx->r6;
    // 0x80072038: sw          $s3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r19;
    // 0x8007203C: lw          $s3, 0x70($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X70);
    // 0x80072040: sw          $s4, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r20;
    // 0x80072044: lw          $s4, 0x74($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X74);
    // 0x80072048: sw          $s2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r18;
    // 0x8007204C: addu        $s2, $a0, $zero
    ctx->r18 = ADD32(ctx->r4, 0);
    // 0x80072050: sw          $s1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r17;
    // 0x80072054: addu        $s1, $a1, $zero
    ctx->r17 = ADD32(ctx->r5, 0);
    // 0x80072058: sw          $s0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r16;
    // 0x8007205C: addu        $s0, $a3, $zero
    ctx->r16 = ADD32(ctx->r7, 0);
    // 0x80072060: beq         $s0, $zero, L_800720B4
    if (ctx->r16 == 0) {
        // 0x80072064: sw          $ra, 0x54($sp)
        MEM_W(0X54, ctx->r29) = ctx->r31;
            goto L_800720B4;
    }
    // 0x80072064: sw          $ra, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r31;
    // 0x80072068: jal         0x80003430
    // 0x8007206C: nop

    rand_recomp(rdram, ctx);
        goto after_0;
    // 0x8007206C: nop

    after_0:
    // 0x80072070: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x80072074: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x80072078: div         $zero, $v0, $s0
    if (S32(ctx->r16) != 0) { lo = S32(S64(S32(ctx->r2)) / S64(S32(ctx->r16))); hi = S32(S64(S32(ctx->r2)) % S64(S32(ctx->r16))); } else { lo = 0; hi = S32(ctx->r2); }
    // 0x8007207C: bne         $s0, $zero, L_80072088
    if (ctx->r16 != 0) {
        // 0x80072080: nop
    
            goto L_80072088;
    }
    // 0x80072080: nop

    // 0x80072084: break       7
    do_break(2147950724);
L_80072088:
    // 0x80072088: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8007208C: bne         $s0, $at, L_800720A0
    if (ctx->r16 != ctx->r1) {
        // 0x80072090: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800720A0;
    }
    // 0x80072090: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80072094: bne         $v0, $at, L_800720A0
    if (ctx->r2 != ctx->r1) {
        // 0x80072098: nop
    
            goto L_800720A0;
    }
    // 0x80072098: nop

    // 0x8007209C: break       6
    do_break(2147950748);
L_800720A0:
    // 0x800720A0: mfhi        $v1
    ctx->r3 = hi;
    // 0x800720A4: mtc1        $v1, $f0
    ctx->f0.u32l = ctx->r3;
    // 0x800720A8: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x800720AC: j           L_800720B8
    // 0x800720B0: nop

        goto L_800720B8;
    // 0x800720B0: nop

L_800720B4:
    // 0x800720B4: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
L_800720B8:
    // 0x800720B8: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x800720BC: jal         0x8001CC3C
    // 0x800720C0: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    func_8001CC3C(rdram, ctx);
        goto after_1;
    // 0x800720C0: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    after_1:
    // 0x800720C4: jal         0x80003430
    // 0x800720C8: nop

    rand_recomp(rdram, ctx);
        goto after_2;
    // 0x800720C8: nop

    after_2:
    // 0x800720CC: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x800720D0: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x800720D4: mtc1        $v0, $f4
    ctx->f4.u32l = ctx->r2;
    // 0x800720D8: cvt.s.w     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800720DC: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x800720E0: jal         0x8001CCCC
    // 0x800720E4: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    func_8001CCCC(rdram, ctx);
        goto after_3;
    // 0x800720E4: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    after_3:
    // 0x800720E8: beq         $s3, $zero, L_80072104
    if (ctx->r19 == 0) {
        // 0x800720EC: nop
    
            goto L_80072104;
    }
    // 0x800720EC: nop

    // 0x800720F0: mtc1        $s3, $f4
    ctx->f4.u32l = ctx->r19;
    // 0x800720F4: cvt.s.w     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800720F8: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x800720FC: jal         0x8001CB9C
    // 0x80072100: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    func_8001CB9C(rdram, ctx);
        goto after_4;
    // 0x80072100: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    after_4:
L_80072104:
    // 0x80072104: beq         $s4, $zero, L_80072120
    if (ctx->r20 == 0) {
        // 0x80072108: nop
    
            goto L_80072120;
    }
    // 0x80072108: nop

    // 0x8007210C: mtc1        $s4, $f4
    ctx->f4.u32l = ctx->r20;
    // 0x80072110: cvt.s.w     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80072114: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x80072118: jal         0x8001CCCC
    // 0x8007211C: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    func_8001CCCC(rdram, ctx);
        goto after_5;
    // 0x8007211C: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    after_5:
L_80072120:
    // 0x80072120: lwc1        $f0, 0x14($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X14);
    // 0x80072124: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
    // 0x80072128: swc1        $f0, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->f0.u32l;
    // 0x8007212C: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
    // 0x80072130: mul.s       $f2, $f2, $f20
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f20.fl);
    // 0x80072134: lwc1        $f0, 0x20($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X20);
    // 0x80072138: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
    // 0x8007213C: swc1        $f0, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->f0.u32l;
    // 0x80072140: lwc1        $f0, 0x2C($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80072144: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
    // 0x80072148: swc1        $f0, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->f0.u32l;
    // 0x8007214C: swc1        $f2, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->f2.u32l;
    // 0x80072150: lwc1        $f0, 0x4($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X4);
    // 0x80072154: mul.s       $f0, $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f20.fl);
    // 0x80072158: swc1        $f0, 0x4($s2)
    MEM_W(0X4, ctx->r18) = ctx->f0.u32l;
    // 0x8007215C: lwc1        $f0, 0x8($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X8);
    // 0x80072160: mul.s       $f0, $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f20.fl);
    // 0x80072164: swc1        $f0, 0x8($s2)
    MEM_W(0X8, ctx->r18) = ctx->f0.u32l;
    // 0x80072168: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
    // 0x8007216C: lw          $s4, 0x50($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X50);
    // 0x80072170: lw          $s3, 0x4C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X4C);
    // 0x80072174: lw          $s2, 0x48($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X48);
    // 0x80072178: lw          $s1, 0x44($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X44);
    // 0x8007217C: lw          $s0, 0x40($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X40);
    // 0x80072180: ldc1        $f20, 0x58($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X58);
    // 0x80072184: jr          $ra
    // 0x80072188: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    return;
    // 0x80072188: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
;}
RECOMP_FUNC void func_8007218C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007218C: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x80072190: sdc1        $f20, 0x60($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X60, ctx->r29);
    // 0x80072194: mtc1        $a2, $f20
    ctx->f20.u32l = ctx->r6;
    // 0x80072198: sw          $s2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r18;
    // 0x8007219C: lw          $s2, 0x78($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X78);
    // 0x800721A0: sw          $s4, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r20;
    // 0x800721A4: lw          $s4, 0x7C($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X7C);
    // 0x800721A8: sw          $s5, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r21;
    // 0x800721AC: lw          $s5, 0x80($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X80);
    // 0x800721B0: sw          $s3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r19;
    // 0x800721B4: addu        $s3, $a0, $zero
    ctx->r19 = ADD32(ctx->r4, 0);
    // 0x800721B8: sw          $s1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r17;
    // 0x800721BC: addu        $s1, $a1, $zero
    ctx->r17 = ADD32(ctx->r5, 0);
    // 0x800721C0: sw          $s0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r16;
    // 0x800721C4: addu        $s0, $a3, $zero
    ctx->r16 = ADD32(ctx->r7, 0);
    // 0x800721C8: beq         $s0, $zero, L_80072220
    if (ctx->r16 == 0) {
        // 0x800721CC: sw          $ra, 0x58($sp)
        MEM_W(0X58, ctx->r29) = ctx->r31;
            goto L_80072220;
    }
    // 0x800721CC: sw          $ra, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r31;
    // 0x800721D0: jal         0x80003430
    // 0x800721D4: nop

    rand_recomp(rdram, ctx);
        goto after_0;
    // 0x800721D4: nop

    after_0:
    // 0x800721D8: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x800721DC: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x800721E0: div         $zero, $v0, $s0
    if (S32(ctx->r16) != 0) { lo = S32(S64(S32(ctx->r2)) / S64(S32(ctx->r16))); hi = S32(S64(S32(ctx->r2)) % S64(S32(ctx->r16))); } else { lo = 0; hi = S32(ctx->r2); }
    // 0x800721E4: bne         $s0, $zero, L_800721F0
    if (ctx->r16 != 0) {
        // 0x800721E8: nop
    
            goto L_800721F0;
    }
    // 0x800721E8: nop

    // 0x800721EC: break       7
    do_break(2147951084);
L_800721F0:
    // 0x800721F0: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800721F4: bne         $s0, $at, L_80072208
    if (ctx->r16 != ctx->r1) {
        // 0x800721F8: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80072208;
    }
    // 0x800721F8: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800721FC: bne         $v0, $at, L_80072208
    if (ctx->r2 != ctx->r1) {
        // 0x80072200: nop
    
            goto L_80072208;
    }
    // 0x80072200: nop

    // 0x80072204: break       6
    do_break(2147951108);
L_80072208:
    // 0x80072208: mfhi        $v1
    ctx->r3 = hi;
    // 0x8007220C: addu        $v1, $s2, $v1
    ctx->r3 = ADD32(ctx->r18, ctx->r3);
    // 0x80072210: mtc1        $v1, $f0
    ctx->f0.u32l = ctx->r3;
    // 0x80072214: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x80072218: j           L_80072228
    // 0x8007221C: nop

        goto L_80072228;
    // 0x8007221C: nop

L_80072220:
    // 0x80072220: mtc1        $s2, $f0
    ctx->f0.u32l = ctx->r18;
    // 0x80072224: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
L_80072228:
    // 0x80072228: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8007222C: jal         0x8001CC3C
    // 0x80072230: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    func_8001CC3C(rdram, ctx);
        goto after_1;
    // 0x80072230: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    after_1:
    // 0x80072234: jal         0x80003430
    // 0x80072238: nop

    rand_recomp(rdram, ctx);
        goto after_2;
    // 0x80072238: nop

    after_2:
    // 0x8007223C: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x80072240: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x80072244: mtc1        $v0, $f4
    ctx->f4.u32l = ctx->r2;
    // 0x80072248: cvt.s.w     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8007224C: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x80072250: jal         0x8001CCCC
    // 0x80072254: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    func_8001CCCC(rdram, ctx);
        goto after_3;
    // 0x80072254: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    after_3:
    // 0x80072258: beq         $s4, $zero, L_80072274
    if (ctx->r20 == 0) {
        // 0x8007225C: nop
    
            goto L_80072274;
    }
    // 0x8007225C: nop

    // 0x80072260: mtc1        $s4, $f4
    ctx->f4.u32l = ctx->r20;
    // 0x80072264: cvt.s.w     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80072268: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x8007226C: jal         0x8001CB9C
    // 0x80072270: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    func_8001CB9C(rdram, ctx);
        goto after_4;
    // 0x80072270: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    after_4:
L_80072274:
    // 0x80072274: beq         $s5, $zero, L_80072290
    if (ctx->r21 == 0) {
        // 0x80072278: nop
    
            goto L_80072290;
    }
    // 0x80072278: nop

    // 0x8007227C: mtc1        $s5, $f4
    ctx->f4.u32l = ctx->r21;
    // 0x80072280: cvt.s.w     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80072284: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x80072288: jal         0x8001CCCC
    // 0x8007228C: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    func_8001CCCC(rdram, ctx);
        goto after_5;
    // 0x8007228C: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    after_5:
L_80072290:
    // 0x80072290: lwc1        $f0, 0x14($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X14);
    // 0x80072294: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
    // 0x80072298: swc1        $f0, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->f0.u32l;
    // 0x8007229C: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
    // 0x800722A0: mul.s       $f2, $f2, $f20
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f20.fl);
    // 0x800722A4: lwc1        $f0, 0x20($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X20);
    // 0x800722A8: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
    // 0x800722AC: swc1        $f0, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->f0.u32l;
    // 0x800722B0: lwc1        $f0, 0x2C($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x800722B4: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
    // 0x800722B8: swc1        $f0, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->f0.u32l;
    // 0x800722BC: swc1        $f2, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->f2.u32l;
    // 0x800722C0: lwc1        $f0, 0x4($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X4);
    // 0x800722C4: mul.s       $f0, $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f20.fl);
    // 0x800722C8: swc1        $f0, 0x4($s3)
    MEM_W(0X4, ctx->r19) = ctx->f0.u32l;
    // 0x800722CC: lwc1        $f0, 0x8($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X8);
    // 0x800722D0: mul.s       $f0, $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f20.fl);
    // 0x800722D4: swc1        $f0, 0x8($s3)
    MEM_W(0X8, ctx->r19) = ctx->f0.u32l;
    // 0x800722D8: lw          $ra, 0x58($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X58);
    // 0x800722DC: lw          $s5, 0x54($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X54);
    // 0x800722E0: lw          $s4, 0x50($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X50);
    // 0x800722E4: lw          $s3, 0x4C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X4C);
    // 0x800722E8: lw          $s2, 0x48($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X48);
    // 0x800722EC: lw          $s1, 0x44($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X44);
    // 0x800722F0: lw          $s0, 0x40($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X40);
    // 0x800722F4: ldc1        $f20, 0x60($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X60);
    // 0x800722F8: jr          $ra
    // 0x800722FC: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    return;
    // 0x800722FC: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
;}
RECOMP_FUNC void func_80072300(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80072300: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80072304: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x80072308: mtc1        $a1, $f22
    ctx->f22.u32l = ctx->r5;
    // 0x8007230C: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x80072310: mtc1        $a2, $f20
    ctx->f20.u32l = ctx->r6;
    // 0x80072314: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x80072318: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8007231C: jal         0x80003430
    // 0x80072320: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    rand_recomp(rdram, ctx);
        goto after_0;
    // 0x80072320: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    after_0:
    // 0x80072324: sub.s       $f20, $f20, $f22
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f20.fl = ctx->f20.fl - ctx->f22.fl;
    // 0x80072328: andi        $v0, $v0, 0xFFF
    ctx->r2 = ctx->r2 & 0XFFF;
    // 0x8007232C: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x80072330: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x80072334: mul.s       $f0, $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f20.fl);
    // 0x80072338: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8007233C: lwc1        $f2, -0x313C($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X313C);
    // 0x80072340: div.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f2.fl);
    // 0x80072344: add.s       $f0, $f0, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f22.fl;
    // 0x80072348: lwc1        $f6, 0x0($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X0);
    // 0x8007234C: mul.s       $f6, $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x80072350: lwc1        $f4, 0x4($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X4);
    // 0x80072354: mul.s       $f4, $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x80072358: lwc1        $f2, 0x8($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8007235C: mul.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x80072360: swc1        $f6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f6.u32l;
    // 0x80072364: swc1        $f4, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f4.u32l;
    // 0x80072368: swc1        $f2, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f2.u32l;
    // 0x8007236C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80072370: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x80072374: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x80072378: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x8007237C: jr          $ra
    // 0x80072380: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80072380: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_80072384(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80072384: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x80072388: sdc1        $f22, 0x40($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X40, ctx->r29);
    // 0x8007238C: mtc1        $a2, $f22
    ctx->f22.u32l = ctx->r6;
    // 0x80072390: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80072394: sdc1        $f20, 0x38($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X38, ctx->r29);
    // 0x80072398: mtc1        $a3, $f20
    ctx->f20.u32l = ctx->r7;
    // 0x8007239C: lbu         $v0, 0xB63($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0XB63);
    // 0x800723A0: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x800723A4: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x800723A8: sw          $s1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r17;
    // 0x800723AC: addu        $s1, $a1, $zero
    ctx->r17 = ADD32(ctx->r5, 0);
    // 0x800723B0: bne         $v0, $zero, L_800723CC
    if (ctx->r2 != 0) {
        // 0x800723B4: sw          $ra, 0x30($sp)
        MEM_W(0X30, ctx->r29) = ctx->r31;
            goto L_800723CC;
    }
    // 0x800723B4: sw          $ra, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r31;
    // 0x800723B8: jal         0x80001A48
    // 0x800723BC: nop

    func_80001A48(rdram, ctx);
        goto after_0;
    // 0x800723BC: nop

    after_0:
    // 0x800723C0: sltiu       $v0, $v0, 0x3A98
    ctx->r2 = ctx->r2 < 0X3A98 ? 1 : 0;
    // 0x800723C4: bne         $v0, $zero, L_800723FC
    if (ctx->r2 != 0) {
        // 0x800723C8: nop
    
            goto L_800723FC;
    }
    // 0x800723C8: nop

L_800723CC:
    // 0x800723CC: lui         $a0, 0x8007
    ctx->r4 = S32(0X8007 << 16);
    // 0x800723D0: addiu       $a0, $a0, -0x960
    ctx->r4 = ADD32(ctx->r4, -0X960);
    // 0x800723D4: addiu       $a1, $sp, 0x10
    ctx->r5 = ADD32(ctx->r29, 0X10);
    // 0x800723D8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x800723DC: lwc1        $f0, 0x58($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X58);
    // 0x800723E0: addiu       $a3, $zero, 0xF
    ctx->r7 = ADD32(0, 0XF);
    // 0x800723E4: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x800723E8: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x800723EC: swc1        $f20, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f20.u32l;
    // 0x800723F0: swc1        $f22, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f22.u32l;
    // 0x800723F4: jal         0x8003FFEC
    // 0x800723F8: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    func_8003FFEC(rdram, ctx);
        goto after_1;
    // 0x800723F8: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    after_1:
L_800723FC:
    // 0x800723FC: lw          $ra, 0x30($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X30);
    // 0x80072400: lw          $s1, 0x2C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X2C);
    // 0x80072404: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x80072408: ldc1        $f22, 0x40($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X40);
    // 0x8007240C: ldc1        $f20, 0x38($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X38);
    // 0x80072410: jr          $ra
    // 0x80072414: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x80072414: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void func_80072418(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80072418: addiu       $sp, $sp, -0x70
    ctx->r29 = ADD32(ctx->r29, -0X70);
    // 0x8007241C: sdc1        $f20, 0x68($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X68, ctx->r29);
    // 0x80072420: mtc1        $a3, $f20
    ctx->f20.u32l = ctx->r7;
    // 0x80072424: sw          $s1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r17;
    // 0x80072428: sw          $ra, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r31;
    // 0x8007242C: sw          $s0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r16;
    // 0x80072430: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x80072434: lw          $t0, 0x4($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X4);
    // 0x80072438: lw          $t1, 0x8($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X8);
    // 0x8007243C: sw          $v1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r3;
    // 0x80072440: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    // 0x80072444: sw          $t1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r9;
    // 0x80072448: beq         $a1, $zero, L_80072470
    if (ctx->r5 == 0) {
        // 0x8007244C: addu        $s1, $a2, $zero
        ctx->r17 = ADD32(ctx->r6, 0);
            goto L_80072470;
    }
    // 0x8007244C: addu        $s1, $a2, $zero
    ctx->r17 = ADD32(ctx->r6, 0);
    // 0x80072450: lw          $v1, 0x0($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X0);
    // 0x80072454: lw          $t0, 0x4($a1)
    ctx->r8 = MEM_W(ctx->r5, 0X4);
    // 0x80072458: lw          $t1, 0x8($a1)
    ctx->r9 = MEM_W(ctx->r5, 0X8);
    // 0x8007245C: sw          $v1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r3;
    // 0x80072460: sw          $t0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r8;
    // 0x80072464: sw          $t1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r9;
    // 0x80072468: j           L_80072484
    // 0x8007246C: nop

        goto L_80072484;
    // 0x8007246C: nop

L_80072470:
    // 0x80072470: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80072474: lwc1        $f0, -0x3138($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X3138);
    // 0x80072478: sw          $zero, 0x28($sp)
    MEM_W(0X28, ctx->r29) = 0;
    // 0x8007247C: sw          $zero, 0x30($sp)
    MEM_W(0X30, ctx->r29) = 0;
    // 0x80072480: swc1        $f0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f0.u32l;
L_80072484:
    // 0x80072484: lwc1        $f4, 0x28($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X28);
    // 0x80072488: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8007248C: lwc1        $f0, -0x3134($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X3134);
    // 0x80072490: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    // 0x80072494: sub.s       $f4, $f0, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f4.fl = ctx->f0.fl - ctx->f4.fl;
    // 0x80072498: lwc1        $f2, 0x2C($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x8007249C: lwc1        $f6, 0x30($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X30);
    // 0x800724A0: sub.s       $f2, $f0, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x800724A4: swc1        $f0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f0.u32l;
    // 0x800724A8: swc1        $f0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f0.u32l;
    // 0x800724AC: swc1        $f0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f0.u32l;
    // 0x800724B0: sub.s       $f0, $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f6.fl;
    // 0x800724B4: swc1        $f4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f4.u32l;
    // 0x800724B8: swc1        $f2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f2.u32l;
    // 0x800724BC: jal         0x80059F10
    // 0x800724C0: swc1        $f0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f0.u32l;
    func_80059F10(rdram, ctx);
        goto after_0;
    // 0x800724C0: swc1        $f0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f0.u32l;
    after_0:
    // 0x800724C4: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800724C8: lbu         $v0, 0xB63($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0XB63);
    // 0x800724CC: bne         $v0, $zero, L_800724FC
    if (ctx->r2 != 0) {
        // 0x800724D0: addiu       $s0, $sp, 0x10
        ctx->r16 = ADD32(ctx->r29, 0X10);
            goto L_800724FC;
    }
    // 0x800724D0: addiu       $s0, $sp, 0x10
    ctx->r16 = ADD32(ctx->r29, 0X10);
    // 0x800724D4: jal         0x80001A48
    // 0x800724D8: nop

    func_80001A48(rdram, ctx);
        goto after_1;
    // 0x800724D8: nop

    after_1:
    // 0x800724DC: sltiu       $v0, $v0, 0x3A98
    ctx->r2 = ctx->r2 < 0X3A98 ? 1 : 0;
    // 0x800724E0: bne         $v0, $zero, L_80072538
    if (ctx->r2 != 0) {
        // 0x800724E4: nop
    
            goto L_80072538;
    }
    // 0x800724E4: nop

    // 0x800724E8: jal         0x80007CB8
    // 0x800724EC: nop

    func_80007CB8(rdram, ctx);
        goto after_2;
    // 0x800724EC: nop

    after_2:
    // 0x800724F0: slti        $v0, $v0, 0x4E20
    ctx->r2 = SIGNED(ctx->r2) < 0X4E20 ? 1 : 0;
    // 0x800724F4: bne         $v0, $zero, L_80072538
    if (ctx->r2 != 0) {
        // 0x800724F8: nop
    
            goto L_80072538;
    }
    // 0x800724F8: nop

L_800724FC:
    // 0x800724FC: lui         $a0, 0x8007
    ctx->r4 = S32(0X8007 << 16);
    // 0x80072500: addiu       $a0, $a0, -0x370
    ctx->r4 = ADD32(ctx->r4, -0X370);
    // 0x80072504: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    // 0x80072508: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8007250C: lwc1        $f0, -0x3130($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X3130);
    // 0x80072510: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80072514: swc1        $f0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f0.u32l;
    // 0x80072518: lwc1        $f0, 0x80($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X80);
    // 0x8007251C: addiu       $a3, $zero, 0xF
    ctx->r7 = ADD32(0, 0XF);
    // 0x80072520: sw          $s0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r16;
    // 0x80072524: sw          $s1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r17;
    // 0x80072528: sw          $zero, 0x48($sp)
    MEM_W(0X48, ctx->r29) = 0;
    // 0x8007252C: swc1        $f20, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f20.u32l;
    // 0x80072530: jal         0x8003FFEC
    // 0x80072534: swc1        $f0, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f0.u32l;
    func_8003FFEC(rdram, ctx);
        goto after_3;
    // 0x80072534: swc1        $f0, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f0.u32l;
    after_3:
L_80072538:
    // 0x80072538: lw          $ra, 0x60($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X60);
    // 0x8007253C: lw          $s1, 0x5C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X5C);
    // 0x80072540: lw          $s0, 0x58($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X58);
    // 0x80072544: ldc1        $f20, 0x68($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X68);
    // 0x80072548: jr          $ra
    // 0x8007254C: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
    return;
    // 0x8007254C: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
;}
RECOMP_FUNC void func_80072550(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80072550: addiu       $sp, $sp, -0x70
    ctx->r29 = ADD32(ctx->r29, -0X70);
    // 0x80072554: sdc1        $f20, 0x68($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X68, ctx->r29);
    // 0x80072558: mtc1        $a3, $f20
    ctx->f20.u32l = ctx->r7;
    // 0x8007255C: sw          $s1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r17;
    // 0x80072560: sw          $ra, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r31;
    // 0x80072564: sw          $s0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r16;
    // 0x80072568: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x8007256C: lw          $t0, 0x4($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X4);
    // 0x80072570: lw          $t1, 0x8($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X8);
    // 0x80072574: sw          $v1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r3;
    // 0x80072578: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    // 0x8007257C: sw          $t1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r9;
    // 0x80072580: beq         $a1, $zero, L_800725A8
    if (ctx->r5 == 0) {
        // 0x80072584: addu        $s1, $a2, $zero
        ctx->r17 = ADD32(ctx->r6, 0);
            goto L_800725A8;
    }
    // 0x80072584: addu        $s1, $a2, $zero
    ctx->r17 = ADD32(ctx->r6, 0);
    // 0x80072588: lw          $v1, 0x0($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X0);
    // 0x8007258C: lw          $t0, 0x4($a1)
    ctx->r8 = MEM_W(ctx->r5, 0X4);
    // 0x80072590: lw          $t1, 0x8($a1)
    ctx->r9 = MEM_W(ctx->r5, 0X8);
    // 0x80072594: sw          $v1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r3;
    // 0x80072598: sw          $t0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r8;
    // 0x8007259C: sw          $t1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r9;
    // 0x800725A0: j           L_800725BC
    // 0x800725A4: nop

        goto L_800725BC;
    // 0x800725A4: nop

L_800725A8:
    // 0x800725A8: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x800725AC: lwc1        $f0, -0x312C($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X312C);
    // 0x800725B0: sw          $zero, 0x28($sp)
    MEM_W(0X28, ctx->r29) = 0;
    // 0x800725B4: sw          $zero, 0x30($sp)
    MEM_W(0X30, ctx->r29) = 0;
    // 0x800725B8: swc1        $f0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f0.u32l;
L_800725BC:
    // 0x800725BC: lwc1        $f4, 0x28($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X28);
    // 0x800725C0: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x800725C4: lwc1        $f0, -0x3128($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X3128);
    // 0x800725C8: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    // 0x800725CC: sub.s       $f4, $f0, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f4.fl = ctx->f0.fl - ctx->f4.fl;
    // 0x800725D0: lwc1        $f2, 0x2C($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x800725D4: lwc1        $f6, 0x30($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X30);
    // 0x800725D8: sub.s       $f2, $f0, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x800725DC: swc1        $f0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f0.u32l;
    // 0x800725E0: swc1        $f0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f0.u32l;
    // 0x800725E4: swc1        $f0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f0.u32l;
    // 0x800725E8: sub.s       $f0, $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f6.fl;
    // 0x800725EC: swc1        $f4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f4.u32l;
    // 0x800725F0: swc1        $f2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f2.u32l;
    // 0x800725F4: jal         0x80059F10
    // 0x800725F8: swc1        $f0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f0.u32l;
    func_80059F10(rdram, ctx);
        goto after_0;
    // 0x800725F8: swc1        $f0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f0.u32l;
    after_0:
    // 0x800725FC: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80072600: lbu         $v0, 0xB63($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0XB63);
    // 0x80072604: bne         $v0, $zero, L_80072634
    if (ctx->r2 != 0) {
        // 0x80072608: addiu       $s0, $sp, 0x10
        ctx->r16 = ADD32(ctx->r29, 0X10);
            goto L_80072634;
    }
    // 0x80072608: addiu       $s0, $sp, 0x10
    ctx->r16 = ADD32(ctx->r29, 0X10);
    // 0x8007260C: jal         0x80001A48
    // 0x80072610: nop

    func_80001A48(rdram, ctx);
        goto after_1;
    // 0x80072610: nop

    after_1:
    // 0x80072614: sltiu       $v0, $v0, 0x3A98
    ctx->r2 = ctx->r2 < 0X3A98 ? 1 : 0;
    // 0x80072618: bne         $v0, $zero, L_8007266C
    if (ctx->r2 != 0) {
        // 0x8007261C: nop
    
            goto L_8007266C;
    }
    // 0x8007261C: nop

    // 0x80072620: jal         0x80007CB8
    // 0x80072624: nop

    func_80007CB8(rdram, ctx);
        goto after_2;
    // 0x80072624: nop

    after_2:
    // 0x80072628: slti        $v0, $v0, 0x4E20
    ctx->r2 = SIGNED(ctx->r2) < 0X4E20 ? 1 : 0;
    // 0x8007262C: bne         $v0, $zero, L_8007266C
    if (ctx->r2 != 0) {
        // 0x80072630: nop
    
            goto L_8007266C;
    }
    // 0x80072630: nop

L_80072634:
    // 0x80072634: lui         $a0, 0x8007
    ctx->r4 = S32(0X8007 << 16);
    // 0x80072638: addiu       $a0, $a0, -0x370
    ctx->r4 = ADD32(ctx->r4, -0X370);
    // 0x8007263C: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    // 0x80072640: lwc1        $f0, 0x80($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X80);
    // 0x80072644: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80072648: swc1        $f0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f0.u32l;
    // 0x8007264C: lwc1        $f0, 0x84($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X84);
    // 0x80072650: addiu       $a3, $zero, 0xF
    ctx->r7 = ADD32(0, 0XF);
    // 0x80072654: sw          $s0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r16;
    // 0x80072658: sw          $s1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r17;
    // 0x8007265C: sw          $zero, 0x48($sp)
    MEM_W(0X48, ctx->r29) = 0;
    // 0x80072660: swc1        $f20, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f20.u32l;
    // 0x80072664: jal         0x8003FFEC
    // 0x80072668: swc1        $f0, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f0.u32l;
    func_8003FFEC(rdram, ctx);
        goto after_3;
    // 0x80072668: swc1        $f0, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f0.u32l;
    after_3:
L_8007266C:
    // 0x8007266C: lw          $ra, 0x60($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X60);
    // 0x80072670: lw          $s1, 0x5C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X5C);
    // 0x80072674: lw          $s0, 0x58($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X58);
    // 0x80072678: ldc1        $f20, 0x68($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X68);
    // 0x8007267C: jr          $ra
    // 0x80072680: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
    return;
    // 0x80072680: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
;}
RECOMP_FUNC void func_80072684(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80072684: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x80072688: sw          $s2, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r18;
    // 0x8007268C: addu        $s2, $a0, $zero
    ctx->r18 = ADD32(ctx->r4, 0);
    // 0x80072690: sw          $s1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r17;
    // 0x80072694: sw          $ra, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r31;
    // 0x80072698: sw          $s0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r16;
    // 0x8007269C: lw          $v1, 0x0($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X0);
    // 0x800726A0: lw          $t0, 0x4($a1)
    ctx->r8 = MEM_W(ctx->r5, 0X4);
    // 0x800726A4: lw          $t1, 0x8($a1)
    ctx->r9 = MEM_W(ctx->r5, 0X8);
    // 0x800726A8: sw          $v1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r3;
    // 0x800726AC: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    // 0x800726B0: sw          $t1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r9;
    // 0x800726B4: beq         $a2, $zero, L_800726DC
    if (ctx->r6 == 0) {
        // 0x800726B8: addu        $s1, $a3, $zero
        ctx->r17 = ADD32(ctx->r7, 0);
            goto L_800726DC;
    }
    // 0x800726B8: addu        $s1, $a3, $zero
    ctx->r17 = ADD32(ctx->r7, 0);
    // 0x800726BC: lw          $v1, 0x0($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X0);
    // 0x800726C0: lw          $t0, 0x4($a2)
    ctx->r8 = MEM_W(ctx->r6, 0X4);
    // 0x800726C4: lw          $t1, 0x8($a2)
    ctx->r9 = MEM_W(ctx->r6, 0X8);
    // 0x800726C8: sw          $v1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r3;
    // 0x800726CC: sw          $t0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r8;
    // 0x800726D0: sw          $t1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r9;
    // 0x800726D4: j           L_800726F4
    // 0x800726D8: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
        goto L_800726F4;
    // 0x800726D8: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
L_800726DC:
    // 0x800726DC: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x800726E0: lwc1        $f0, -0x3124($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X3124);
    // 0x800726E4: sw          $zero, 0x28($sp)
    MEM_W(0X28, ctx->r29) = 0;
    // 0x800726E8: sw          $zero, 0x30($sp)
    MEM_W(0X30, ctx->r29) = 0;
    // 0x800726EC: swc1        $f0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f0.u32l;
    // 0x800726F0: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
L_800726F4:
    // 0x800726F4: lwc1        $f4, 0x28($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X28);
    // 0x800726F8: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x800726FC: lwc1        $f2, -0x3120($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X3120);
    // 0x80072700: lwc1        $f0, 0x80($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X80);
    // 0x80072704: sub.s       $f4, $f2, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f4.fl = ctx->f2.fl - ctx->f4.fl;
    // 0x80072708: swc1        $f0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f0.u32l;
    // 0x8007270C: lwc1        $f0, 0x2C($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80072710: lwc1        $f6, 0x30($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X30);
    // 0x80072714: sub.s       $f0, $f2, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f2.fl - ctx->f0.fl;
    // 0x80072718: swc1        $f2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f2.u32l;
    // 0x8007271C: swc1        $f2, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f2.u32l;
    // 0x80072720: sub.s       $f2, $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = ctx->f2.fl - ctx->f6.fl;
    // 0x80072724: swc1        $f4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f4.u32l;
    // 0x80072728: swc1        $f0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f0.u32l;
    // 0x8007272C: jal         0x80059F10
    // 0x80072730: swc1        $f2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f2.u32l;
    func_80059F10(rdram, ctx);
        goto after_0;
    // 0x80072730: swc1        $f2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f2.u32l;
    after_0:
    // 0x80072734: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80072738: lbu         $v0, 0xB63($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0XB63);
    // 0x8007273C: bne         $v0, $zero, L_8007276C
    if (ctx->r2 != 0) {
        // 0x80072740: addiu       $s0, $sp, 0x10
        ctx->r16 = ADD32(ctx->r29, 0X10);
            goto L_8007276C;
    }
    // 0x80072740: addiu       $s0, $sp, 0x10
    ctx->r16 = ADD32(ctx->r29, 0X10);
    // 0x80072744: jal         0x80001A48
    // 0x80072748: nop

    func_80001A48(rdram, ctx);
        goto after_1;
    // 0x80072748: nop

    after_1:
    // 0x8007274C: sltiu       $v0, $v0, 0x3A98
    ctx->r2 = ctx->r2 < 0X3A98 ? 1 : 0;
    // 0x80072750: bne         $v0, $zero, L_800727A8
    if (ctx->r2 != 0) {
        // 0x80072754: nop
    
            goto L_800727A8;
    }
    // 0x80072754: nop

    // 0x80072758: jal         0x80007CB8
    // 0x8007275C: nop

    func_80007CB8(rdram, ctx);
        goto after_2;
    // 0x8007275C: nop

    after_2:
    // 0x80072760: slti        $v0, $v0, 0x4E20
    ctx->r2 = SIGNED(ctx->r2) < 0X4E20 ? 1 : 0;
    // 0x80072764: bne         $v0, $zero, L_800727A8
    if (ctx->r2 != 0) {
        // 0x80072768: nop
    
            goto L_800727A8;
    }
    // 0x80072768: nop

L_8007276C:
    // 0x8007276C: lui         $a0, 0x8007
    ctx->r4 = S32(0X8007 << 16);
    // 0x80072770: addiu       $a0, $a0, -0x370
    ctx->r4 = ADD32(ctx->r4, -0X370);
    // 0x80072774: lwc1        $f0, 0x78($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X78);
    // 0x80072778: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    // 0x8007277C: swc1        $f0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f0.u32l;
    // 0x80072780: lwc1        $f0, 0x7C($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X7C);
    // 0x80072784: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80072788: swc1        $f0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f0.u32l;
    // 0x8007278C: lwc1        $f0, 0x84($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X84);
    // 0x80072790: addiu       $a3, $zero, 0xF
    ctx->r7 = ADD32(0, 0XF);
    // 0x80072794: sw          $s0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r16;
    // 0x80072798: sw          $s1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r17;
    // 0x8007279C: sw          $s2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r18;
    // 0x800727A0: jal         0x8003FFEC
    // 0x800727A4: swc1        $f0, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f0.u32l;
    func_8003FFEC(rdram, ctx);
        goto after_3;
    // 0x800727A4: swc1        $f0, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f0.u32l;
    after_3:
L_800727A8:
    // 0x800727A8: lw          $ra, 0x64($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X64);
    // 0x800727AC: lw          $s2, 0x60($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X60);
    // 0x800727B0: lw          $s1, 0x5C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X5C);
    // 0x800727B4: lw          $s0, 0x58($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X58);
    // 0x800727B8: jr          $ra
    // 0x800727BC: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    return;
    // 0x800727BC: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
;}
RECOMP_FUNC void func_800727C0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800727C0: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x800727C4: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800727C8: sdc1        $f20, 0x38($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X38, ctx->r29);
    // 0x800727CC: mtc1        $a3, $f20
    ctx->f20.u32l = ctx->r7;
    // 0x800727D0: lbu         $v0, 0xB63($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0XB63);
    // 0x800727D4: sw          $s2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r18;
    // 0x800727D8: addu        $s2, $a0, $zero
    ctx->r18 = ADD32(ctx->r4, 0);
    // 0x800727DC: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x800727E0: addu        $s0, $a1, $zero
    ctx->r16 = ADD32(ctx->r5, 0);
    // 0x800727E4: sw          $s1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r17;
    // 0x800727E8: addu        $s1, $a2, $zero
    ctx->r17 = ADD32(ctx->r6, 0);
    // 0x800727EC: bne         $v0, $zero, L_8007281C
    if (ctx->r2 != 0) {
        // 0x800727F0: sw          $ra, 0x34($sp)
        MEM_W(0X34, ctx->r29) = ctx->r31;
            goto L_8007281C;
    }
    // 0x800727F0: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x800727F4: jal         0x80001A48
    // 0x800727F8: nop

    func_80001A48(rdram, ctx);
        goto after_0;
    // 0x800727F8: nop

    after_0:
    // 0x800727FC: sltiu       $v0, $v0, 0x3A98
    ctx->r2 = ctx->r2 < 0X3A98 ? 1 : 0;
    // 0x80072800: bne         $v0, $zero, L_80072854
    if (ctx->r2 != 0) {
        // 0x80072804: nop
    
            goto L_80072854;
    }
    // 0x80072804: nop

    // 0x80072808: jal         0x80007CB8
    // 0x8007280C: nop

    func_80007CB8(rdram, ctx);
        goto after_1;
    // 0x8007280C: nop

    after_1:
    // 0x80072810: slti        $v0, $v0, 0x4E20
    ctx->r2 = SIGNED(ctx->r2) < 0X4E20 ? 1 : 0;
    // 0x80072814: bne         $v0, $zero, L_80072854
    if (ctx->r2 != 0) {
        // 0x80072818: nop
    
            goto L_80072854;
    }
    // 0x80072818: nop

L_8007281C:
    // 0x8007281C: lui         $a0, 0x8007
    ctx->r4 = S32(0X8007 << 16);
    // 0x80072820: addiu       $a0, $a0, -0x370
    ctx->r4 = ADD32(ctx->r4, -0X370);
    // 0x80072824: addiu       $a1, $sp, 0x10
    ctx->r5 = ADD32(ctx->r29, 0X10);
    // 0x80072828: lwc1        $f0, 0x50($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X50);
    // 0x8007282C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80072830: swc1        $f0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f0.u32l;
    // 0x80072834: lwc1        $f0, 0x54($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X54);
    // 0x80072838: addiu       $a3, $zero, 0xF
    ctx->r7 = ADD32(0, 0XF);
    // 0x8007283C: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x80072840: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x80072844: sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // 0x80072848: swc1        $f20, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f20.u32l;
    // 0x8007284C: jal         0x8003FFEC
    // 0x80072850: swc1        $f0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f0.u32l;
    func_8003FFEC(rdram, ctx);
        goto after_2;
    // 0x80072850: swc1        $f0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f0.u32l;
    after_2:
L_80072854:
    // 0x80072854: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x80072858: lw          $s2, 0x30($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X30);
    // 0x8007285C: lw          $s1, 0x2C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X2C);
    // 0x80072860: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x80072864: ldc1        $f20, 0x38($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X38);
    // 0x80072868: jr          $ra
    // 0x8007286C: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x8007286C: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void func_80072870(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80072870: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x80072874: sdc1        $f20, 0x50($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X50, ctx->r29);
    // 0x80072878: mtc1        $a1, $f20
    ctx->f20.u32l = ctx->r5;
    // 0x8007287C: sw          $s2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r18;
    // 0x80072880: lbu         $s2, 0x6F($sp)
    ctx->r18 = MEM_BU(ctx->r29, 0X6F);
    // 0x80072884: sw          $s5, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r21;
    // 0x80072888: addu        $s5, $a2, $zero
    ctx->r21 = ADD32(ctx->r6, 0);
    // 0x8007288C: sw          $s6, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r22;
    // 0x80072890: addu        $s6, $a3, $zero
    ctx->r22 = ADD32(ctx->r7, 0);
    // 0x80072894: sw          $s1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r17;
    // 0x80072898: addu        $s1, $a0, $zero
    ctx->r17 = ADD32(ctx->r4, 0);
    // 0x8007289C: sw          $s0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r16;
    // 0x800728A0: andi        $s0, $s1, 0xFFFF
    ctx->r16 = ctx->r17 & 0XFFFF;
    // 0x800728A4: sw          $s3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r19;
    // 0x800728A8: lbu         $s3, 0x73($sp)
    ctx->r19 = MEM_BU(ctx->r29, 0X73);
    // 0x800728AC: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x800728B0: sw          $ra, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r31;
    // 0x800728B4: jal         0x8004013C
    // 0x800728B8: sw          $s4, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r20;
    func_8004013C(rdram, ctx);
        goto after_0;
    // 0x800728B8: sw          $s4, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r20;
    after_0:
    // 0x800728BC: addu        $s4, $v0, $zero
    ctx->r20 = ADD32(ctx->r2, 0);
    // 0x800728C0: beq         $s4, $zero, L_80072958
    if (ctx->r20 == 0) {
        // 0x800728C4: lui         $v0, 0x8013
        ctx->r2 = S32(0X8013 << 16);
            goto L_80072958;
    }
    // 0x800728C4: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800728C8: lbu         $v0, 0xB63($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0XB63);
    // 0x800728CC: bne         $v0, $zero, L_800728FC
    if (ctx->r2 != 0) {
        // 0x800728D0: sll         $v0, $s5, 16
        ctx->r2 = S32(ctx->r21 << 16);
            goto L_800728FC;
    }
    // 0x800728D0: sll         $v0, $s5, 16
    ctx->r2 = S32(ctx->r21 << 16);
    // 0x800728D4: jal         0x8006C994
    // 0x800728D8: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    func_8006C994(rdram, ctx);
        goto after_1;
    // 0x800728D8: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    after_1:
    // 0x800728DC: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x800728E0: beq         $s0, $v0, L_800728F8
    if (ctx->r16 == ctx->r2) {
        // 0x800728E4: lui         $v0, 0x8014
        ctx->r2 = S32(0X8014 << 16);
            goto L_800728F8;
    }
    // 0x800728E4: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x800728E8: lw          $v0, -0x576C($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X576C);
    // 0x800728EC: slti        $v0, $v0, 0xB
    ctx->r2 = SIGNED(ctx->r2) < 0XB ? 1 : 0;
    // 0x800728F0: beq         $v0, $zero, L_8007295C
    if (ctx->r2 == 0) {
        // 0x800728F4: ori         $v0, $zero, 0xFFFF
        ctx->r2 = 0 | 0XFFFF;
            goto L_8007295C;
    }
    // 0x800728F4: ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
L_800728F8:
    // 0x800728F8: sll         $v0, $s5, 16
    ctx->r2 = S32(ctx->r21 << 16);
L_800728FC:
    // 0x800728FC: sh          $s1, 0x10($sp)
    MEM_H(0X10, ctx->r29) = ctx->r17;
    // 0x80072900: sb          $s2, 0x28($sp)
    MEM_B(0X28, ctx->r29) = ctx->r18;
    // 0x80072904: sb          $s3, 0x29($sp)
    MEM_B(0X29, ctx->r29) = ctx->r19;
    // 0x80072908: sw          $s6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r22;
    // 0x8007290C: bgtz        $v0, L_8007291C
    if (SIGNED(ctx->r2) > 0) {
        // 0x80072910: sh          $s5, 0x12($sp)
        MEM_H(0X12, ctx->r29) = ctx->r21;
            goto L_8007291C;
    }
    // 0x80072910: sh          $s5, 0x12($sp)
    MEM_H(0X12, ctx->r29) = ctx->r21;
    // 0x80072914: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80072918: sh          $v0, 0x12($sp)
    MEM_H(0X12, ctx->r29) = ctx->r2;
L_8007291C:
    // 0x8007291C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x80072920: lui         $a0, 0x8007
    ctx->r4 = S32(0X8007 << 16);
    // 0x80072924: addiu       $a0, $a0, 0xA8
    ctx->r4 = ADD32(ctx->r4, 0XA8);
    // 0x80072928: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // 0x8007292C: lw          $v0, 0x68($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X68);
    // 0x80072930: addiu       $a1, $sp, 0x10
    ctx->r5 = ADD32(ctx->r29, 0X10);
    // 0x80072934: swc1        $f20, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f20.u32l;
    // 0x80072938: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x8007293C: lbu         $a3, 0x19($s4)
    ctx->r7 = MEM_BU(ctx->r20, 0X19);
    // 0x80072940: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x80072944: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x80072948: jal         0x8003FFEC
    // 0x8007294C: andi        $a3, $a3, 0xFF
    ctx->r7 = ctx->r7 & 0XFF;
    func_8003FFEC(rdram, ctx);
        goto after_2;
    // 0x8007294C: andi        $a3, $a3, 0xFF
    ctx->r7 = ctx->r7 & 0XFF;
    after_2:
    // 0x80072950: j           L_8007295C
    // 0x80072954: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
        goto L_8007295C;
    // 0x80072954: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
L_80072958:
    // 0x80072958: ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
L_8007295C:
    // 0x8007295C: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
    // 0x80072960: lw          $s6, 0x48($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X48);
    // 0x80072964: lw          $s5, 0x44($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X44);
    // 0x80072968: lw          $s4, 0x40($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X40);
    // 0x8007296C: lw          $s3, 0x3C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X3C);
    // 0x80072970: lw          $s2, 0x38($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X38);
    // 0x80072974: lw          $s1, 0x34($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X34);
    // 0x80072978: lw          $s0, 0x30($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X30);
    // 0x8007297C: ldc1        $f20, 0x50($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X50);
    // 0x80072980: jr          $ra
    // 0x80072984: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    return;
    // 0x80072984: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
;}
RECOMP_FUNC void func_80072988(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80072988: addiu       $sp, $sp, -0x98
    ctx->r29 = ADD32(ctx->r29, -0X98);
    // 0x8007298C: sdc1        $f20, 0x90($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X90, ctx->r29);
    // 0x80072990: mtc1        $a1, $f20
    ctx->f20.u32l = ctx->r5;
    // 0x80072994: sw          $s2, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r18;
    // 0x80072998: lbu         $s2, 0xAB($sp)
    ctx->r18 = MEM_BU(ctx->r29, 0XAB);
    // 0x8007299C: sw          $s6, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r22;
    // 0x800729A0: addu        $s6, $a2, $zero
    ctx->r22 = ADD32(ctx->r6, 0);
    // 0x800729A4: sw          $s5, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r21;
    // 0x800729A8: addu        $s5, $a3, $zero
    ctx->r21 = ADD32(ctx->r7, 0);
    // 0x800729AC: sw          $s3, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r19;
    // 0x800729B0: addu        $s3, $a0, $zero
    ctx->r19 = ADD32(ctx->r4, 0);
    // 0x800729B4: sw          $s1, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r17;
    // 0x800729B8: andi        $s1, $s3, 0xFFFF
    ctx->r17 = ctx->r19 & 0XFFFF;
    // 0x800729BC: sw          $s4, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r20;
    // 0x800729C0: lbu         $s4, 0xB3($sp)
    ctx->r20 = MEM_BU(ctx->r29, 0XB3);
    // 0x800729C4: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x800729C8: sw          $ra, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->r31;
    // 0x800729CC: jal         0x8004013C
    // 0x800729D0: sw          $s0, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r16;
    func_8004013C(rdram, ctx);
        goto after_0;
    // 0x800729D0: sw          $s0, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r16;
    after_0:
    // 0x800729D4: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    // 0x800729D8: beq         $s0, $zero, L_80072A9C
    if (ctx->r16 == 0) {
        // 0x800729DC: lui         $v0, 0x8013
        ctx->r2 = S32(0X8013 << 16);
            goto L_80072A9C;
    }
    // 0x800729DC: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800729E0: lbu         $v0, 0xB63($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0XB63);
    // 0x800729E4: bne         $v0, $zero, L_80072A10
    if (ctx->r2 != 0) {
        // 0x800729E8: nop
    
            goto L_80072A10;
    }
    // 0x800729E8: nop

    // 0x800729EC: jal         0x8006C994
    // 0x800729F0: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    func_8006C994(rdram, ctx);
        goto after_1;
    // 0x800729F0: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    after_1:
    // 0x800729F4: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x800729F8: beq         $s1, $v0, L_80072A10
    if (ctx->r17 == ctx->r2) {
        // 0x800729FC: lui         $v0, 0x8014
        ctx->r2 = S32(0X8014 << 16);
            goto L_80072A10;
    }
    // 0x800729FC: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x80072A00: lw          $v0, -0x576C($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X576C);
    // 0x80072A04: slti        $v0, $v0, 0xB
    ctx->r2 = SIGNED(ctx->r2) < 0XB ? 1 : 0;
    // 0x80072A08: beq         $v0, $zero, L_80072AA0
    if (ctx->r2 == 0) {
        // 0x80072A0C: ori         $v0, $zero, 0xFFFF
        ctx->r2 = 0 | 0XFFFF;
            goto L_80072AA0;
    }
    // 0x80072A0C: ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
L_80072A10:
    // 0x80072A10: lw          $v0, 0xC($s0)
    ctx->r2 = MEM_W(ctx->r16, 0XC);
    // 0x80072A14: beq         $v0, $zero, L_80072A9C
    if (ctx->r2 == 0) {
        // 0x80072A18: addu        $a1, $s5, $zero
        ctx->r5 = ADD32(ctx->r21, 0);
            goto L_80072A9C;
    }
    // 0x80072A18: addu        $a1, $s5, $zero
    ctx->r5 = ADD32(ctx->r21, 0);
    // 0x80072A1C: andi        $a2, $s2, 0xFF
    ctx->r6 = ctx->r18 & 0XFF;
    // 0x80072A20: addiu       $v0, $sp, 0x40
    ctx->r2 = ADD32(ctx->r29, 0X40);
    // 0x80072A24: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // 0x80072A28: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x80072A2C: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x80072A30: lw          $a0, 0xC($s0)
    ctx->r4 = MEM_W(ctx->r16, 0XC);
    // 0x80072A34: jal         0x8005857C
    // 0x80072A38: addiu       $a3, $sp, 0x28
    ctx->r7 = ADD32(ctx->r29, 0X28);
    func_8005857C(rdram, ctx);
        goto after_2;
    // 0x80072A38: addiu       $a3, $sp, 0x28
    ctx->r7 = ADD32(ctx->r29, 0X28);
    after_2:
    // 0x80072A3C: beq         $v0, $zero, L_80072A9C
    if (ctx->r2 == 0) {
        // 0x80072A40: sll         $v0, $s6, 16
        ctx->r2 = S32(ctx->r22 << 16);
            goto L_80072A9C;
    }
    // 0x80072A40: sll         $v0, $s6, 16
    ctx->r2 = S32(ctx->r22 << 16);
    // 0x80072A44: sb          $s2, 0x24($sp)
    MEM_B(0X24, ctx->r29) = ctx->r18;
    // 0x80072A48: sh          $s3, 0x20($sp)
    MEM_H(0X20, ctx->r29) = ctx->r19;
    // 0x80072A4C: sb          $s4, 0x38($sp)
    MEM_B(0X38, ctx->r29) = ctx->r20;
    // 0x80072A50: sb          $zero, 0x39($sp)
    MEM_B(0X39, ctx->r29) = 0;
    // 0x80072A54: sw          $zero, 0x30($sp)
    MEM_W(0X30, ctx->r29) = 0;
    // 0x80072A58: bgtz        $v0, L_80072A68
    if (SIGNED(ctx->r2) > 0) {
        // 0x80072A5C: sh          $s6, 0x22($sp)
        MEM_H(0X22, ctx->r29) = ctx->r22;
            goto L_80072A68;
    }
    // 0x80072A5C: sh          $s6, 0x22($sp)
    MEM_H(0X22, ctx->r29) = ctx->r22;
    // 0x80072A60: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80072A64: sh          $v0, 0x22($sp)
    MEM_H(0X22, ctx->r29) = ctx->r2;
L_80072A68:
    // 0x80072A68: lui         $a0, 0x8007
    ctx->r4 = S32(0X8007 << 16);
    // 0x80072A6C: addiu       $a0, $a0, 0xA8
    ctx->r4 = ADD32(ctx->r4, 0XA8);
    // 0x80072A70: lw          $v0, 0xAC($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XAC);
    // 0x80072A74: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    // 0x80072A78: swc1        $f20, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f20.u32l;
    // 0x80072A7C: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    // 0x80072A80: lbu         $a3, 0x19($s0)
    ctx->r7 = MEM_BU(ctx->r16, 0X19);
    // 0x80072A84: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x80072A88: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x80072A8C: jal         0x8003FFEC
    // 0x80072A90: andi        $a3, $a3, 0xFF
    ctx->r7 = ctx->r7 & 0XFF;
    func_8003FFEC(rdram, ctx);
        goto after_3;
    // 0x80072A90: andi        $a3, $a3, 0xFF
    ctx->r7 = ctx->r7 & 0XFF;
    after_3:
    // 0x80072A94: j           L_80072AA0
    // 0x80072A98: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
        goto L_80072AA0;
    // 0x80072A98: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
L_80072A9C:
    // 0x80072A9C: ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
L_80072AA0:
    // 0x80072AA0: lw          $ra, 0x8C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X8C);
    // 0x80072AA4: lw          $s6, 0x88($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X88);
    // 0x80072AA8: lw          $s5, 0x84($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X84);
    // 0x80072AAC: lw          $s4, 0x80($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X80);
    // 0x80072AB0: lw          $s3, 0x7C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X7C);
    // 0x80072AB4: lw          $s2, 0x78($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X78);
    // 0x80072AB8: lw          $s1, 0x74($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X74);
    // 0x80072ABC: lw          $s0, 0x70($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X70);
    // 0x80072AC0: ldc1        $f20, 0x90($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X90);
    // 0x80072AC4: jr          $ra
    // 0x80072AC8: addiu       $sp, $sp, 0x98
    ctx->r29 = ADD32(ctx->r29, 0X98);
    return;
    // 0x80072AC8: addiu       $sp, $sp, 0x98
    ctx->r29 = ADD32(ctx->r29, 0X98);
;}
RECOMP_FUNC void func_80072ACC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80072ACC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80072AD0: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    // 0x80072AD4: ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
    // 0x80072AD8: beq         $a0, $v0, L_80072AEC
    if (ctx->r4 == ctx->r2) {
        // 0x80072ADC: sw          $ra, 0x10($sp)
        MEM_W(0X10, ctx->r29) = ctx->r31;
            goto L_80072AEC;
    }
    // 0x80072ADC: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x80072AE0: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    // 0x80072AE4: jal         0x8003E8DC
    // 0x80072AE8: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    func_8003E8DC(rdram, ctx);
        goto after_0;
    // 0x80072AE8: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    after_0:
L_80072AEC:
    // 0x80072AEC: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x80072AF0: jr          $ra
    // 0x80072AF4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80072AF4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_80072AF8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80072AF8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80072AFC: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x80072B00: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x80072B04: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80072B08: lbu         $v1, 0x0($s0)
    ctx->r3 = MEM_BU(ctx->r16, 0X0);
    // 0x80072B0C: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // 0x80072B10: beq         $v1, $v0, L_80072BD0
    if (ctx->r3 == ctx->r2) {
        // 0x80072B14: andi        $v0, $v1, 0x80
        ctx->r2 = ctx->r3 & 0X80;
            goto L_80072BD0;
    }
    // 0x80072B14: andi        $v0, $v1, 0x80
    ctx->r2 = ctx->r3 & 0X80;
    // 0x80072B18: beq         $v0, $zero, L_80072BA0
    if (ctx->r2 == 0) {
        // 0x80072B1C: nop
    
            goto L_80072BA0;
    }
    // 0x80072B1C: nop

    // 0x80072B20: lbu         $v0, 0x4($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X4);
    // 0x80072B24: beq         $v0, $zero, L_80072B88
    if (ctx->r2 == 0) {
        // 0x80072B28: addu        $a2, $zero, $zero
        ctx->r6 = ADD32(0, 0);
            goto L_80072B88;
    }
    // 0x80072B28: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // 0x80072B2C: lui         $a3, 0x8014
    ctx->r7 = S32(0X8014 << 16);
    // 0x80072B30: lui         $t0, 0x8014
    ctx->r8 = S32(0X8014 << 16);
    // 0x80072B34: addu        $a1, $a2, $zero
    ctx->r5 = ADD32(ctx->r6, 0);
L_80072B38:
    // 0x80072B38: lw          $v0, 0x8($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X8);
    // 0x80072B3C: addu        $v0, $a1, $v0
    ctx->r2 = ADD32(ctx->r5, ctx->r2);
    // 0x80072B40: lbu         $v0, 0x6($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X6);
    // 0x80072B44: beq         $v0, $zero, L_80072B74
    if (ctx->r2 == 0) {
        // 0x80072B48: nop
    
            goto L_80072B74;
    }
    // 0x80072B48: nop

    // 0x80072B4C: lbu         $a0, -0x5768($a3)
    ctx->r4 = MEM_BU(ctx->r7, -0X5768);
    // 0x80072B50: lw          $v1, 0x8($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X8);
    // 0x80072B54: addiu       $v0, $a0, 0x1
    ctx->r2 = ADD32(ctx->r4, 0X1);
    // 0x80072B58: andi        $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 & 0XFF;
    // 0x80072B5C: addu        $v1, $a1, $v1
    ctx->r3 = ADD32(ctx->r5, ctx->r3);
    // 0x80072B60: sb          $v0, -0x5768($a3)
    MEM_B(-0X5768, ctx->r7) = ctx->r2;
    // 0x80072B64: lw          $v0, -0x5764($t0)
    ctx->r2 = MEM_W(ctx->r8, -0X5764);
    // 0x80072B68: lbu         $v1, 0x6($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X6);
    // 0x80072B6C: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x80072B70: sb          $v1, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r3;
L_80072B74:
    // 0x80072B74: lbu         $v0, 0x4($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X4);
    // 0x80072B78: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x80072B7C: slt         $v0, $a2, $v0
    ctx->r2 = SIGNED(ctx->r6) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80072B80: bne         $v0, $zero, L_80072B38
    if (ctx->r2 != 0) {
        // 0x80072B84: addiu       $a1, $a1, 0x38
        ctx->r5 = ADD32(ctx->r5, 0X38);
            goto L_80072B38;
    }
    // 0x80072B84: addiu       $a1, $a1, 0x38
    ctx->r5 = ADD32(ctx->r5, 0X38);
L_80072B88:
    // 0x80072B88: lw          $a0, 0x8($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X8);
    // 0x80072B8C: jal         0x80001C98
    // 0x80072B90: nop

    rs_free(rdram, ctx);
        goto after_0;
    // 0x80072B90: nop

    after_0:
    // 0x80072B94: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // 0x80072B98: j           L_80072BD0
    // 0x80072B9C: sb          $v0, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r2;
        goto L_80072BD0;
    // 0x80072B9C: sb          $v0, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r2;
L_80072BA0:
    // 0x80072BA0: lbu         $v0, 0x6($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X6);
    // 0x80072BA4: beq         $v0, $zero, L_80072BD0
    if (ctx->r2 == 0) {
        // 0x80072BA8: lui         $a0, 0x8014
        ctx->r4 = S32(0X8014 << 16);
            goto L_80072BD0;
    }
    // 0x80072BA8: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80072BAC: lbu         $v1, -0x5768($a0)
    ctx->r3 = MEM_BU(ctx->r4, -0X5768);
    // 0x80072BB0: addiu       $v0, $v1, 0x1
    ctx->r2 = ADD32(ctx->r3, 0X1);
    // 0x80072BB4: andi        $v1, $v1, 0xFF
    ctx->r3 = ctx->r3 & 0XFF;
    // 0x80072BB8: sb          $v0, -0x5768($a0)
    MEM_B(-0X5768, ctx->r4) = ctx->r2;
    // 0x80072BBC: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x80072BC0: lw          $v0, -0x5764($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X5764);
    // 0x80072BC4: lbu         $a0, 0x6($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X6);
    // 0x80072BC8: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80072BCC: sb          $a0, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r4;
L_80072BD0:
    // 0x80072BD0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80072BD4: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x80072BD8: jr          $ra
    // 0x80072BDC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80072BDC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_80072BE0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80072BE0: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80072BE4: sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // 0x80072BE8: addu        $s2, $a0, $zero
    ctx->r18 = ADD32(ctx->r4, 0);
    // 0x80072BEC: sw          $s3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r19;
    // 0x80072BF0: addu        $s3, $a1, $zero
    ctx->r19 = ADD32(ctx->r5, 0);
    // 0x80072BF4: sw          $ra, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r31;
    // 0x80072BF8: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x80072BFC: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x80072C00: sdc1        $f20, 0x28($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X28, ctx->r29);
    // 0x80072C04: lbu         $a1, 0x0($s2)
    ctx->r5 = MEM_BU(ctx->r18, 0X0);
    // 0x80072C08: mtc1        $a2, $f20
    ctx->f20.u32l = ctx->r6;
    // 0x80072C0C: andi        $v0, $a1, 0x80
    ctx->r2 = ctx->r5 & 0X80;
    // 0x80072C10: beql        $v0, $zero, L_80072C58
    if (ctx->r2 == 0) {
        // 0x80072C14: lui         $a0, 0x800A
        ctx->r4 = S32(0X800A << 16);
            goto L_80072C58;
    }
    goto skip_0;
    // 0x80072C14: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    skip_0:
    // 0x80072C18: lbu         $v0, 0x4($s2)
    ctx->r2 = MEM_BU(ctx->r18, 0X4);
    // 0x80072C1C: beq         $v0, $zero, L_80072CC8
    if (ctx->r2 == 0) {
        // 0x80072C20: addu        $s0, $zero, $zero
        ctx->r16 = ADD32(0, 0);
            goto L_80072CC8;
    }
    // 0x80072C20: addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
    // 0x80072C24: addu        $s1, $s0, $zero
    ctx->r17 = ADD32(ctx->r16, 0);
L_80072C28:
    // 0x80072C28: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80072C2C: addu        $a1, $s3, $zero
    ctx->r5 = ADD32(ctx->r19, 0);
    // 0x80072C30: lw          $a0, 0x8($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X8);
    // 0x80072C34: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x80072C38: jal         0x80072BE0
    // 0x80072C3C: addu        $a0, $a0, $s1
    ctx->r4 = ADD32(ctx->r4, ctx->r17);
    func_80072BE0(rdram, ctx);
        goto after_0;
    // 0x80072C3C: addu        $a0, $a0, $s1
    ctx->r4 = ADD32(ctx->r4, ctx->r17);
    after_0:
    // 0x80072C40: lbu         $v0, 0x4($s2)
    ctx->r2 = MEM_BU(ctx->r18, 0X4);
    // 0x80072C44: slt         $v0, $s0, $v0
    ctx->r2 = SIGNED(ctx->r16) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80072C48: bne         $v0, $zero, L_80072C28
    if (ctx->r2 != 0) {
        // 0x80072C4C: addiu       $s1, $s1, 0x38
        ctx->r17 = ADD32(ctx->r17, 0X38);
            goto L_80072C28;
    }
    // 0x80072C4C: addiu       $s1, $s1, 0x38
    ctx->r17 = ADD32(ctx->r17, 0X38);
    // 0x80072C50: j           L_80072CC8
    // 0x80072C54: nop

        goto L_80072CC8;
    // 0x80072C54: nop

L_80072C58:
    // 0x80072C58: addiu       $a0, $a0, 0xAA0
    ctx->r4 = ADD32(ctx->r4, 0XAA0);
    // 0x80072C5C: andi        $v0, $a1, 0x1F
    ctx->r2 = ctx->r5 & 0X1F;
    // 0x80072C60: lbu         $v1, 0x1($s2)
    ctx->r3 = MEM_BU(ctx->r18, 0X1);
    // 0x80072C64: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x80072C68: sll         $v1, $v1, 1
    ctx->r3 = S32(ctx->r3 << 1);
    // 0x80072C6C: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x80072C70: addu        $v1, $v1, $a0
    ctx->r3 = ADD32(ctx->r3, ctx->r4);
    // 0x80072C74: lhu         $v0, 0x0($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X0);
    // 0x80072C78: mtc1        $v0, $f2
    ctx->f2.u32l = ctx->r2;
    // 0x80072C7C: cvt.s.w     $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    ctx->f2.fl = CVT_S_W(ctx->f2.u32l);
    // 0x80072C80: mul.s       $f2, $f2, $f20
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f20.fl);
    // 0x80072C84: lh          $v0, 0x2($s2)
    ctx->r2 = MEM_H(ctx->r18, 0X2);
    // 0x80072C88: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x80072C8C: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x80072C90: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x80072C94: trunc.w.s   $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    ctx->f4.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x80072C98: mfc1        $v0, $f4
    ctx->r2 = (int32_t)ctx->f4.u32l;
    // 0x80072C9C: sh          $v0, 0x2($s2)
    MEM_H(0X2, ctx->r18) = ctx->r2;
    // 0x80072CA0: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x80072CA4: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x80072CA8: slti        $v0, $v0, 0x101
    ctx->r2 = SIGNED(ctx->r2) < 0X101 ? 1 : 0;
    // 0x80072CAC: bne         $v0, $zero, L_80072CC8
    if (ctx->r2 != 0) {
        // 0x80072CB0: nop
    
            goto L_80072CC8;
    }
    // 0x80072CB0: nop

    // 0x80072CB4: lbu         $v0, 0x1($s2)
    ctx->r2 = MEM_BU(ctx->r18, 0X1);
    // 0x80072CB8: sh          $zero, 0x2($s2)
    MEM_H(0X2, ctx->r18) = 0;
    // 0x80072CBC: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80072CC0: andi        $v0, $v0, 0x3
    ctx->r2 = ctx->r2 & 0X3;
    // 0x80072CC4: sb          $v0, 0x1($s2)
    MEM_B(0X1, ctx->r18) = ctx->r2;
L_80072CC8:
    // 0x80072CC8: lw          $ra, 0x20($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X20);
    // 0x80072CCC: lw          $s3, 0x1C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X1C);
    // 0x80072CD0: lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X18);
    // 0x80072CD4: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x80072CD8: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x80072CDC: ldc1        $f20, 0x28($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X28);
    // 0x80072CE0: jr          $ra
    // 0x80072CE4: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x80072CE4: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void fake_func_80072CE8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
;}
RECOMP_FUNC void func_80072CF0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    { static uint32_t L=0; static int I=0; uint32_t C=*(uint32_t*)(rdram+0x3CBC4);
      if(!I){I=1;L=C;fprintf(stderr,"[wp@72CF0:entry] 0x%08X\n",C);fflush(stderr);}
      else if(C!=L){fprintf(stderr,"[wp@72CF0:entry] CHANGED 0x%08X->0x%08X\n",L,C);fflush(stderr);L=C;} }
    // 0x80072CF0: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x80072CF4: lui         $a0, 0x8004
    ctx->r4 = S32(0X8004 << 16);
    // 0x80072CF8: addiu       $a0, $a0, -0x3110
    ctx->r4 = ADD32(ctx->r4, -0X3110);
    // 0x80072CFC: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x80072D00: addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    // 0x80072D04: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x80072D08: lui         $a3, 0x8014
    ctx->r7 = S32(0X8014 << 16);
    // 0x80072D0C: addiu       $a3, $a3, -0x5740
    ctx->r7 = ADD32(ctx->r7, -0X5740);
    // 0x80072D10: lui         $v1, 0x8014
    ctx->r3 = S32(0X8014 << 16);
    // 0x80072D14: addiu       $v1, $v1, -0x5710
    ctx->r3 = ADD32(ctx->r3, -0X5710);
    // 0x80072D18: sw          $zero, -0x5750($v0)
    MEM_W(-0X5750, ctx->r2) = 0;
    // 0x80072D1C: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x80072D20: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80072D24: lwc1        $f0, -0x30C8($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X30C8);
    // 0x80072D28: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80072D2C: lwc1        $f2, -0x30C4($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X30C4);
    // 0x80072D30: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80072D34: lwc1        $f4, -0x30C0($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X30C0);
    // 0x80072D38: addiu       $v0, $v0, -0x56E0
    ctx->r2 = ADD32(ctx->r2, -0X56E0);
    // 0x80072D3C: sw          $ra, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r31;
    // 0x80072D40: sw          $s7, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r23;
    // 0x80072D44: sw          $s6, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r22;
    // 0x80072D48: sw          $s5, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r21;
    // 0x80072D4C: sw          $s4, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r20;
    // 0x80072D50: sw          $s3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r19;
    // 0x80072D54: sw          $s2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r18;
    // 0x80072D58: sw          $s1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r17;
    // 0x80072D5C: sw          $s0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r16;
    // 0x80072D60: sb          $zero, 0x20($a3)
    MEM_B(0X20, ctx->r7) = 0;
    // 0x80072D64: sw          $zero, 0xC($a3)
    MEM_W(0XC, ctx->r7) = 0;
    // 0x80072D68: sw          $zero, 0x14($a3)
    MEM_W(0X14, ctx->r7) = 0;
    // 0x80072D6C: sb          $zero, 0x20($v1)
    MEM_B(0X20, ctx->r3) = 0;
    // 0x80072D70: sw          $zero, 0xC($v1)
    MEM_W(0XC, ctx->r3) = 0;
    // 0x80072D74: sw          $zero, 0x14($v1)
    MEM_W(0X14, ctx->r3) = 0;
    // 0x80072D78: sb          $zero, 0x20($v0)
    MEM_B(0X20, ctx->r2) = 0;
    // 0x80072D7C: sw          $zero, 0xC($v0)
    MEM_W(0XC, ctx->r2) = 0;
    // 0x80072D80: sw          $zero, 0x14($v0)
    MEM_W(0X14, ctx->r2) = 0;
    // 0x80072D84: swc1        $f0, 0x10($a3)
    MEM_W(0X10, ctx->r7) = ctx->f0.u32l;
    // 0x80072D88: addu        $a3, $a1, $zero
    ctx->r7 = ADD32(ctx->r5, 0);
    // 0x80072D8C: swc1        $f2, 0x10($v1)
    MEM_W(0X10, ctx->r3) = ctx->f2.u32l;
    // 0x80072D90: jal         0x8005645C
    // 0x80072D94: swc1        $f4, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->f4.u32l;
    load_hmt_and_hob(rdram, ctx);
    { static uint32_t L=0; static int I=0; uint32_t C=*(uint32_t*)(rdram+0x3CBC4);
      if(!I){I=1;L=C;fprintf(stderr,"[wp@72CF0:after_hmt] 0x%08X\n",C);fflush(stderr);}
      else if(C!=L){fprintf(stderr,"[wp@72CF0:after_hmt] CHANGED 0x%08X->0x%08X\n",L,C);fflush(stderr);L=C;} }
        goto after_0;
    // 0x80072D94: swc1        $f4, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->f4.u32l;
    after_0:
    // 0x80072D98: lui         $a0, 0x8004
    ctx->r4 = S32(0X8004 << 16);
    // 0x80072D9C: jal         0x80056EB0
    // 0x80072DA0: addiu       $a0, $a0, -0x30FC
    ctx->r4 = ADD32(ctx->r4, -0X30FC);
    func_80056EB0(rdram, ctx);
    { static uint32_t L=0; static int I=0; uint32_t C=*(uint32_t*)(rdram+0x3CBC4);
      if(!I){I=1;L=C;fprintf(stderr,"[wp@72CF0:after_56EB0] 0x%08X\n",C);fflush(stderr);}
      else if(C!=L){fprintf(stderr,"[wp@72CF0:after_56EB0] CHANGED 0x%08X->0x%08X\n",L,C);fflush(stderr);L=C;} }
        goto after_1;
    // 0x80072DA0: addiu       $a0, $a0, -0x30FC
    ctx->r4 = ADD32(ctx->r4, -0X30FC);
    after_1:
    // 0x80072DA4: lui         $s4, 0x8004
    ctx->r20 = S32(0X8004 << 16);
    // 0x80072DA8: addiu       $s7, $s4, -0x30F0
    ctx->r23 = ADD32(ctx->r20, -0X30F0);
    // 0x80072DAC: addu        $a0, $s7, $zero
    ctx->r4 = ADD32(ctx->r23, 0);
    // 0x80072DB0: jal         0x80022D68
    // 0x80072DB4: addu        $s6, $v0, $zero
    ctx->r22 = ADD32(ctx->r2, 0);
    func_80022D68(rdram, ctx);
        goto after_2;
    // 0x80072DB4: addu        $s6, $v0, $zero
    ctx->r22 = ADD32(ctx->r2, 0);
    after_2:
    // 0x80072DB8: andi        $s5, $v0, 0xFFFF
    ctx->r21 = ctx->r2 & 0XFFFF;
    // 0x80072DBC: jal         0x80022790
    // 0x80072DC0: addu        $a0, $s5, $zero
    ctx->r4 = ADD32(ctx->r21, 0);
    func_80022790(rdram, ctx);
        goto after_3;
    // 0x80072DC0: addu        $a0, $s5, $zero
    ctx->r4 = ADD32(ctx->r21, 0);
    after_3:
    // 0x80072DC4: lui         $s1, 0x8004
    ctx->r17 = S32(0X8004 << 16);
    // 0x80072DC8: addiu       $s1, $s1, -0x30E0
    ctx->r17 = ADD32(ctx->r17, -0X30E0);
    // 0x80072DCC: jal         0x8006488C
    // 0x80072DD0: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    load_asset(rdram, ctx);
        goto after_4;
    // 0x80072DD0: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    after_4:
    // 0x80072DD4: addu        $s3, $v0, $zero
    ctx->r19 = ADD32(ctx->r2, 0);
    // 0x80072DD8: addiu       $s0, $s3, 0x4
    ctx->r16 = ADD32(ctx->r19, 0X4);
    // 0x80072DDC: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x80072DE0: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80072DE4: lwc1        $f0, -0x30BC($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X30BC);
    // 0x80072DE8: addiu       $s2, $zero, 0x1
    ctx->r18 = ADD32(0, 0X1);
    // 0x80072DEC: sh          $s2, 0x10($sp)
    MEM_H(0X10, ctx->r29) = ctx->r18;
    // 0x80072DF0: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x80072DF4: sb          $s2, 0x20($sp)
    MEM_B(0X20, ctx->r29) = ctx->r18;
    // 0x80072DF8: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    // 0x80072DFC: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    // 0x80072E00: addiu       $t3, $s4, -0x30F0
    ctx->r11 = ADD32(ctx->r20, -0X30F0);
    // 0x80072E04: lw          $t0, 0x0($t3)
    ctx->r8 = MEM_W(ctx->r11, 0X0);
    // 0x80072E08: lw          $t1, 0x4($t3)
    ctx->r9 = MEM_W(ctx->r11, 0X4);
    // 0x80072E0C: lw          $t2, 0x8($t3)
    ctx->r10 = MEM_W(ctx->r11, 0X8);
    // 0x80072E10: sw          $t0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r8;
    // 0x80072E14: sw          $t1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r9;
    // 0x80072E18: sw          $t2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r10;
    // 0x80072E1C: lb          $t0, 0xC($t3)
    ctx->r8 = MEM_B(ctx->r11, 0XC);
    // 0x80072E20: sb          $t0, 0x30($sp)
    MEM_B(0X30, ctx->r29) = ctx->r8;
    // 0x80072E24: jal         0x80055488
    // 0x80072E28: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    full_header_image_offset_convert(rdram, ctx);
    { static uint32_t L=0; static int I=0; uint32_t C=*(uint32_t*)(rdram+0x3CBC4);
      if(!I){I=1;L=C;fprintf(stderr,"[wp@72CF0:after_fhioc] 0x%08X\n",C);fflush(stderr);}
      else if(C!=L){fprintf(stderr,"[wp@72CF0:after_fhioc] CHANGED 0x%08X->0x%08X\n",L,C);fflush(stderr);L=C;} }
        goto after_5;
    // 0x80072E28: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    after_5:
    // 0x80072E2C: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    // 0x80072E30: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x80072E34: jal         0x80022B90
    // 0x80072E38: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    func_80022B90(rdram, ctx);
        goto after_6;
    // 0x80072E38: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    after_6:
    // 0x80072E3C: addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    // 0x80072E40: jal         0x80001C98
    // 0x80072E44: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    rs_free(rdram, ctx);
        goto after_7;
    // 0x80072E44: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    after_7:
    // 0x80072E48: lw          $v0, 0x1C($s6)
    ctx->r2 = MEM_W(ctx->r22, 0X1C);
    // 0x80072E4C: addu        $a1, $s5, $zero
    ctx->r5 = ADD32(ctx->r21, 0);
    // 0x80072E50: lw          $a0, 0x8($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X8);
    // 0x80072E54: jal         0x800595A0
    // 0x80072E58: andi        $a2, $s0, 0xFFFF
    ctx->r6 = ctx->r16 & 0XFFFF;
    func_800595A0(rdram, ctx);
        goto after_8;
    // 0x80072E58: andi        $a2, $s0, 0xFFFF
    ctx->r6 = ctx->r16 & 0XFFFF;
    after_8:
    // 0x80072E5C: jal         0x8005779C
    // 0x80072E60: addu        $a0, $s6, $zero
    ctx->r4 = ADD32(ctx->r22, 0);
    func_8005779C(rdram, ctx);
        goto after_9;
    // 0x80072E60: addu        $a0, $s6, $zero
    ctx->r4 = ADD32(ctx->r22, 0);
    after_9:
    // 0x80072E64: addu        $a0, $s7, $zero
    ctx->r4 = ADD32(ctx->r23, 0);
    // 0x80072E68: jal         0x800547C0
    // 0x80072E6C: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    func_800547C0(rdram, ctx);
        goto after_10;
    // 0x80072E6C: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    after_10:
    // 0x80072E70: andi        $a0, $v0, 0xFFFF
    ctx->r4 = ctx->r2 & 0XFFFF;
    // 0x80072E74: lui         $a1, 0x4140
    ctx->r5 = S32(0X4140 << 16);
    // 0x80072E78: jal         0x80054B0C
    // 0x80072E7C: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    func_80054B0C(rdram, ctx);
    { static uint32_t L=0; static int I=0; uint32_t C=*(uint32_t*)(rdram+0x3CBC4);
      if(!I){I=1;L=C;fprintf(stderr,"[wp@72CF0:after_54B0C] 0x%08X\n",C);fflush(stderr);}
      else if(C!=L){fprintf(stderr,"[wp@72CF0:after_54B0C] CHANGED 0x%08X->0x%08X\n",L,C);fflush(stderr);L=C;} }
        goto after_11;
    // 0x80072E7C: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    after_11:
    // 0x80072E80: lw          $ra, 0x58($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X58);
    // 0x80072E84: lw          $s7, 0x54($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X54);
    // 0x80072E88: lw          $s6, 0x50($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X50);
    // 0x80072E8C: lw          $s5, 0x4C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X4C);
    // 0x80072E90: lw          $s4, 0x48($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X48);
    // 0x80072E94: lw          $s3, 0x44($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X44);
    // 0x80072E98: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x80072E9C: sb          $s2, -0x56BC($v0)
    MEM_B(-0X56BC, ctx->r2) = ctx->r18;
    // 0x80072EA0: lw          $s2, 0x40($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X40);
    // 0x80072EA4: lw          $s1, 0x3C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X3C);
    // 0x80072EA8: lw          $s0, 0x38($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X38);
    // 0x80072EAC: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x80072EB0: sw          $zero, -0x574C($v0)
    MEM_W(-0X574C, ctx->r2) = 0;
    // 0x80072EB4: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x80072EB8: sw          $zero, -0x5748($v0)
    MEM_W(-0X5748, ctx->r2) = 0;
    // 0x80072EBC: jr          $ra
    // 0x80072EC0: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    return;
    // 0x80072EC0: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
;}
RECOMP_FUNC void func_80072EC4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80072EC4: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x80072EC8: sw          $s3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r19;
    // 0x80072ECC: addu        $s3, $a0, $zero
    ctx->r19 = ADD32(ctx->r4, 0);
    // 0x80072ED0: sw          $s2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r18;
    // 0x80072ED4: andi        $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 & 0XFFFF;
    // 0x80072ED8: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x80072EDC: sw          $ra, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r31;
    // 0x80072EE0: sw          $s1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r17;
    // 0x80072EE4: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x80072EE8: sdc1        $f22, 0x48($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X48, ctx->r29);
    // 0x80072EEC: sdc1        $f20, 0x40($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X40, ctx->r29);
    // 0x80072EF0: lw          $s1, 0x4($s3)
    ctx->r17 = MEM_W(ctx->r19, 0X4);
    // 0x80072EF4: beq         $a1, $v0, L_8007328C
    if (ctx->r5 == ctx->r2) {
        // 0x80072EF8: addu        $s2, $a2, $zero
        ctx->r18 = ADD32(ctx->r6, 0);
            goto L_8007328C;
    }
    // 0x80072EF8: addu        $s2, $a2, $zero
    ctx->r18 = ADD32(ctx->r6, 0);
    // 0x80072EFC: slti        $v0, $a1, 0x3
    ctx->r2 = SIGNED(ctx->r5) < 0X3 ? 1 : 0;
    // 0x80072F00: beq         $v0, $zero, L_80072F18
    if (ctx->r2 == 0) {
        // 0x80072F04: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80072F18;
    }
    // 0x80072F04: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80072F08: beq         $a1, $v0, L_80072F34
    if (ctx->r5 == ctx->r2) {
        // 0x80072F0C: lui         $v0, 0x8013
        ctx->r2 = S32(0X8013 << 16);
            goto L_80072F34;
    }
    // 0x80072F0C: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80072F10: j           L_8007372C
    // 0x80072F14: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8007372C;
    // 0x80072F14: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80072F18:
    // 0x80072F18: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x80072F1C: beq         $a1, $v0, L_800732DC
    if (ctx->r5 == ctx->r2) {
        // 0x80072F20: addiu       $v0, $zero, 0x4
        ctx->r2 = ADD32(0, 0X4);
            goto L_800732DC;
    }
    // 0x80072F20: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // 0x80072F24: beq         $a1, $v0, L_800736A4
    if (ctx->r5 == ctx->r2) {
        // 0x80072F28: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_800736A4;
    }
    // 0x80072F28: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80072F2C: j           L_8007372C
    // 0x80072F30: nop

        goto L_8007372C;
    // 0x80072F30: nop

L_80072F34:
    // 0x80072F34: lbu         $v0, 0xB63($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0XB63);
    // 0x80072F38: bne         $v0, $zero, L_80072F94
    if (ctx->r2 != 0) {
        // 0x80072F3C: addu        $s0, $s2, $zero
        ctx->r16 = ADD32(ctx->r18, 0);
            goto L_80072F94;
    }
    // 0x80072F3C: addu        $s0, $s2, $zero
    ctx->r16 = ADD32(ctx->r18, 0);
    // 0x80072F40: lhu         $s2, 0x1C($s2)
    ctx->r18 = MEM_HU(ctx->r18, 0X1C);
    // 0x80072F44: ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
    // 0x80072F48: bne         $s2, $v0, L_80072F94
    if (ctx->r18 != ctx->r2) {
        // 0x80072F4C: nop
    
            goto L_80072F94;
    }
    // 0x80072F4C: nop

    // 0x80072F50: jal         0x80001A48
    // 0x80072F54: nop

    func_80001A48(rdram, ctx);
        goto after_0;
    // 0x80072F54: nop

    after_0:
    // 0x80072F58: sltiu       $v0, $v0, 0x4E20
    ctx->r2 = ctx->r2 < 0X4E20 ? 1 : 0;
    // 0x80072F5C: bnel        $v0, $zero, L_80072F7C
    if (ctx->r2 != 0) {
        // 0x80072F60: sh          $s2, 0x66($s1)
        MEM_H(0X66, ctx->r17) = ctx->r18;
            goto L_80072F7C;
    }
    goto skip_0;
    // 0x80072F60: sh          $s2, 0x66($s1)
    MEM_H(0X66, ctx->r17) = ctx->r18;
    skip_0:
    // 0x80072F64: jal         0x80007CB8
    // 0x80072F68: nop

    func_80007CB8(rdram, ctx);
        goto after_1;
    // 0x80072F68: nop

    after_1:
    // 0x80072F6C: slti        $v0, $v0, 0x7530
    ctx->r2 = SIGNED(ctx->r2) < 0X7530 ? 1 : 0;
    // 0x80072F70: beq         $v0, $zero, L_80072F94
    if (ctx->r2 == 0) {
        // 0x80072F74: nop
    
            goto L_80072F94;
    }
    // 0x80072F74: nop

    // 0x80072F78: sh          $s2, 0x66($s1)
    MEM_H(0X66, ctx->r17) = ctx->r18;
L_80072F7C:
    // 0x80072F7C: sw          $zero, 0x30($s1)
    MEM_W(0X30, ctx->r17) = 0;
L_80072F80:
    // 0x80072F80: lhu         $a0, 0x16($s3)
    ctx->r4 = MEM_HU(ctx->r19, 0X16);
    // 0x80072F84: jal         0x8003ED74
    // 0x80072F88: nop

    func_8003ED74(rdram, ctx);
        goto after_2;
    // 0x80072F88: nop

    after_2:
    // 0x80072F8C: j           L_8007372C
    // 0x80072F90: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8007372C;
    // 0x80072F90: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80072F94:
    // 0x80072F94: lhu         $v0, 0x1C($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X1C);
    // 0x80072F98: sh          $v0, 0x64($s1)
    MEM_H(0X64, ctx->r17) = ctx->r2;
    // 0x80072F9C: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80072FA0: lw          $t0, 0x0($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X0);
    // 0x80072FA4: lw          $t1, 0x4($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X4);
    // 0x80072FA8: lw          $t2, 0x8($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X8);
    // 0x80072FAC: sw          $t0, 0x34($s1)
    MEM_W(0X34, ctx->r17) = ctx->r8;
    // 0x80072FB0: sw          $t1, 0x38($s1)
    MEM_W(0X38, ctx->r17) = ctx->r9;
    // 0x80072FB4: sw          $t2, 0x3C($s1)
    MEM_W(0X3C, ctx->r17) = ctx->r10;
    // 0x80072FB8: lwc1        $f0, 0x38($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X38);
    // 0x80072FBC: lwc1        $f2, 0x34($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0X34);
    // 0x80072FC0: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x80072FC4: c.lt.s      $f20, $f2
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f20.fl < ctx->f2.fl;
    // 0x80072FC8: nop

    // 0x80072FCC: bc1tl       L_80072FD4
    if (c1cs) {
        // 0x80072FD0: mov.s       $f20, $f2
        CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    ctx->f20.fl = ctx->f2.fl;
            goto L_80072FD4;
    }
    goto skip_1;
    // 0x80072FD0: mov.s       $f20, $f2
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    ctx->f20.fl = ctx->f2.fl;
    skip_1:
L_80072FD4:
    // 0x80072FD4: lwc1        $f0, 0x3C($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X3C);
    // 0x80072FD8: c.lt.s      $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f20.fl < ctx->f0.fl;
    // 0x80072FDC: nop

    // 0x80072FE0: bc1tl       L_80072FE8
    if (c1cs) {
        // 0x80072FE4: mov.s       $f20, $f0
        CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
            goto L_80072FE8;
    }
    goto skip_2;
    // 0x80072FE4: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    skip_2:
L_80072FE8:
    // 0x80072FE8: lbu         $v0, 0x1F($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X1F);
    // 0x80072FEC: sb          $v0, 0x68($s1)
    MEM_B(0X68, ctx->r17) = ctx->r2;
    // 0x80072FF0: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x80072FF4: beq         $v0, $zero, L_80073014
    if (ctx->r2 == 0) {
        // 0x80072FF8: lui         $a0, 0x8004
        ctx->r4 = S32(0X8004 << 16);
            goto L_80073014;
    }
    // 0x80072FF8: lui         $a0, 0x8004
    ctx->r4 = S32(0X8004 << 16);
    // 0x80072FFC: bltz        $v0, L_80073274
    if (SIGNED(ctx->r2) < 0) {
        // 0x80073000: slti        $v0, $v0, 0x4
        ctx->r2 = SIGNED(ctx->r2) < 0X4 ? 1 : 0;
            goto L_80073274;
    }
    // 0x80073000: slti        $v0, $v0, 0x4
    ctx->r2 = SIGNED(ctx->r2) < 0X4 ? 1 : 0;
    // 0x80073004: beq         $v0, $zero, L_80073278
    if (ctx->r2 == 0) {
        // 0x80073008: lui         $v0, 0x8014
        ctx->r2 = S32(0X8014 << 16);
            goto L_80073278;
    }
    // 0x80073008: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x8007300C: j           L_80073144
    // 0x80073010: nop

        goto L_80073144;
    // 0x80073010: nop

L_80073014:
    // 0x80073014: jal         0x80056EB0
    // 0x80073018: addiu       $a0, $a0, -0x30FC
    ctx->r4 = ADD32(ctx->r4, -0X30FC);
    func_80056EB0(rdram, ctx);
        goto after_3;
    // 0x80073018: addiu       $a0, $a0, -0x30FC
    ctx->r4 = ADD32(ctx->r4, -0X30FC);
    after_3:
    // 0x8007301C: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // 0x80073020: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x80073024: lui         $a2, 0x901
    ctx->r6 = S32(0X901 << 16);
    // 0x80073028: addu        $a3, $a1, $zero
    ctx->r7 = ADD32(ctx->r5, 0);
    // 0x8007302C: jal         0x8005955C
    // 0x80073030: sw          $a0, 0x30($s1)
    MEM_W(0X30, ctx->r17) = ctx->r4;
    func_8005955C(rdram, ctx);
        goto after_4;
    // 0x80073030: sw          $a0, 0x30($s1)
    MEM_W(0X30, ctx->r17) = ctx->r4;
    after_4:
    // 0x80073034: lhu         $a0, 0x64($s1)
    ctx->r4 = MEM_HU(ctx->r17, 0X64);
    // 0x80073038: jal         0x8004015C
    // 0x8007303C: nop

    func_8004015C(rdram, ctx);
        goto after_5;
    // 0x8007303C: nop

    after_5:
    // 0x80073040: addu        $v1, $s1, $zero
    ctx->r3 = ADD32(ctx->r17, 0);
    // 0x80073044: addiu       $a0, $v0, 0x30
    ctx->r4 = ADD32(ctx->r2, 0X30);
L_80073048:
    // 0x80073048: lw          $t0, 0x0($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X0);
    // 0x8007304C: lw          $t1, 0x4($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X4);
    // 0x80073050: lw          $t2, 0x8($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X8);
    // 0x80073054: lw          $t3, 0xC($v0)
    ctx->r11 = MEM_W(ctx->r2, 0XC);
    // 0x80073058: sw          $t0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r8;
    // 0x8007305C: sw          $t1, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r9;
    // 0x80073060: sw          $t2, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r10;
    // 0x80073064: sw          $t3, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r11;
    // 0x80073068: addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
    // 0x8007306C: bne         $v0, $a0, L_80073048
    if (ctx->r2 != ctx->r4) {
        // 0x80073070: addiu       $v1, $v1, 0x10
        ctx->r3 = ADD32(ctx->r3, 0X10);
            goto L_80073048;
    }
    // 0x80073070: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
    // 0x80073074: lui         $a2, 0x8014
    ctx->r6 = S32(0X8014 << 16);
    // 0x80073078: addiu       $a2, $a2, -0x7FA8
    ctx->r6 = ADD32(ctx->r6, -0X7FA8);
    // 0x8007307C: lwc1        $f12, 0x0($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X0);
    // 0x80073080: lwc1        $f14, 0x8($s1)
    ctx->f14.u32l = MEM_W(ctx->r17, 0X8);
    // 0x80073084: jal         0x80067D90
    // 0x80073088: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    func_80067D90(rdram, ctx);
        goto after_6;
    // 0x80073088: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    after_6:
    // 0x8007308C: lhu         $a1, 0x64($s1)
    ctx->r5 = MEM_HU(ctx->r17, 0X64);
    // 0x80073090: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x80073094: ori         $a0, $zero, 0xFFFF
    ctx->r4 = 0 | 0XFFFF;
    // 0x80073098: swc1        $f0, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->f0.u32l;
    // 0x8007309C: swc1        $f2, 0x2C($s1)
    MEM_W(0X2C, ctx->r17) = ctx->f2.u32l;
    // 0x800730A0: swc1        $f2, 0x28($s1)
    MEM_W(0X28, ctx->r17) = ctx->f2.u32l;
    // 0x800730A4: jal         0x80040188
    // 0x800730A8: swc1        $f2, 0x24($s1)
    MEM_W(0X24, ctx->r17) = ctx->f2.u32l;
    func_80040188(rdram, ctx);
        goto after_7;
    // 0x800730A8: swc1        $f2, 0x24($s1)
    MEM_W(0X24, ctx->r17) = ctx->f2.u32l;
    after_7:
    // 0x800730AC: sh          $v0, 0x66($s1)
    MEM_H(0X66, ctx->r17) = ctx->r2;
    // 0x800730B0: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x800730B4: ori         $v1, $zero, 0xFFFF
    ctx->r3 = 0 | 0XFFFF;
    // 0x800730B8: beq         $v0, $v1, L_80072F80
    if (ctx->r2 == ctx->r3) {
        // 0x800730BC: nop
    
            goto L_80072F80;
    }
    // 0x800730BC: nop

    // 0x800730C0: lw          $v0, 0x30($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X30);
    // 0x800730C4: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x800730C8: lwc1        $f0, 0x44($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X44);
    // 0x800730CC: mul.s       $f0, $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f20.fl);
    // 0x800730D0: jal         0x80003430
    // 0x800730D4: swc1        $f0, 0x44($s1)
    MEM_W(0X44, ctx->r17) = ctx->f0.u32l;
    rand_recomp(rdram, ctx);
        goto after_8;
    // 0x800730D4: swc1        $f0, 0x44($s1)
    MEM_W(0X44, ctx->r17) = ctx->f0.u32l;
    after_8:
    // 0x800730D8: andi        $v0, $v0, 0x7F
    ctx->r2 = ctx->r2 & 0X7F;
    // 0x800730DC: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x800730E0: lwc1        $f22, -0x30B8($at)
    ctx->f22.u32l = MEM_W(ctx->r1, -0X30B8);
    // 0x800730E4: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x800730E8: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x800730EC: sub.s       $f0, $f0, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f22.fl;
    // 0x800730F0: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x800730F4: lwc1        $f20, -0x30B4($at)
    ctx->f20.u32l = MEM_W(ctx->r1, -0X30B4);
    // 0x800730F8: mul.s       $f0, $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f20.fl);
    // 0x800730FC: abs.s       $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = fabsf(ctx->f0.fl);
    // 0x80073100: lwc1        $f0, 0x38($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X38);
    // 0x80073104: swc1        $f16, 0x50($s1)
    MEM_W(0X50, ctx->r17) = ctx->f16.u32l;
    // 0x80073108: jal         0x80003430
    // 0x8007310C: swc1        $f0, 0x54($s1)
    MEM_W(0X54, ctx->r17) = ctx->f0.u32l;
    rand_recomp(rdram, ctx);
        goto after_9;
    // 0x8007310C: swc1        $f0, 0x54($s1)
    MEM_W(0X54, ctx->r17) = ctx->f0.u32l;
    after_9:
    // 0x80073110: andi        $v0, $v0, 0x7F
    ctx->r2 = ctx->r2 & 0X7F;
    // 0x80073114: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x80073118: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x8007311C: sub.s       $f0, $f0, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f22.fl;
    // 0x80073120: mul.s       $f0, $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f20.fl);
    // 0x80073124: abs.s       $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = fabsf(ctx->f0.fl);
    // 0x80073128: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8007312C: lwc1        $f0, -0x30B0($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X30B0);
    // 0x80073130: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80073134: swc1        $f16, 0x4C($s1)
    MEM_W(0X4C, ctx->r17) = ctx->f16.u32l;
    // 0x80073138: sb          $v0, 0x69($s1)
    MEM_B(0X69, ctx->r17) = ctx->r2;
    // 0x8007313C: j           L_80073274
    // 0x80073140: swc1        $f0, 0x58($s1)
    MEM_W(0X58, ctx->r17) = ctx->f0.u32l;
        goto L_80073274;
    // 0x80073140: swc1        $f0, 0x58($s1)
    MEM_W(0X58, ctx->r17) = ctx->f0.u32l;
L_80073144:
    // 0x80073144: jal         0x80057338
    // 0x80073148: addiu       $a0, $a0, -0x30FC
    ctx->r4 = ADD32(ctx->r4, -0X30FC);
    func_80057338(rdram, ctx);
        goto after_10;
    // 0x80073148: addiu       $a0, $a0, -0x30FC
    ctx->r4 = ADD32(ctx->r4, -0X30FC);
    after_10:
    // 0x8007314C: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // 0x80073150: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x80073154: lui         $a2, 0x901
    ctx->r6 = S32(0X901 << 16);
    // 0x80073158: addu        $a3, $a1, $zero
    ctx->r7 = ADD32(ctx->r5, 0);
    // 0x8007315C: jal         0x8005955C
    // 0x80073160: sw          $a0, 0x30($s1)
    MEM_W(0X30, ctx->r17) = ctx->r4;
    func_8005955C(rdram, ctx);
        goto after_11;
    // 0x80073160: sw          $a0, 0x30($s1)
    MEM_W(0X30, ctx->r17) = ctx->r4;
    after_11:
    // 0x80073164: lw          $v0, 0x4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X4);
    // 0x80073168: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8007316C: lwc1        $f0, -0x30AC($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X30AC);
    // 0x80073170: lw          $t0, 0x0($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X0);
    // 0x80073174: lw          $t1, 0x4($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X4);
    // 0x80073178: lw          $t2, 0x8($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X8);
    // 0x8007317C: sw          $t0, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r8;
    // 0x80073180: sw          $t1, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->r9;
    // 0x80073184: sw          $t2, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->r10;
    // 0x80073188: sw          $zero, 0x20($s1)
    MEM_W(0X20, ctx->r17) = 0;
    // 0x8007318C: lwc1        $f2, 0x20($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0X20);
    // 0x80073190: lbu         $v1, 0x68($s1)
    ctx->r3 = MEM_BU(ctx->r17, 0X68);
    // 0x80073194: sw          $zero, 0xC($s1)
    MEM_W(0XC, ctx->r17) = 0;
    // 0x80073198: sw          $zero, 0x10($s1)
    MEM_W(0X10, ctx->r17) = 0;
    // 0x8007319C: swc1        $f0, 0x14($s1)
    MEM_W(0X14, ctx->r17) = ctx->f0.u32l;
    // 0x800731A0: sw          $zero, 0x18($s1)
    MEM_W(0X18, ctx->r17) = 0;
    // 0x800731A4: swc1        $f0, 0x1C($s1)
    MEM_W(0X1C, ctx->r17) = ctx->f0.u32l;
    // 0x800731A8: swc1        $f2, 0x2C($s1)
    MEM_W(0X2C, ctx->r17) = ctx->f2.u32l;
    // 0x800731AC: swc1        $f2, 0x28($s1)
    MEM_W(0X28, ctx->r17) = ctx->f2.u32l;
    // 0x800731B0: swc1        $f2, 0x24($s1)
    MEM_W(0X24, ctx->r17) = ctx->f2.u32l;
    // 0x800731B4: lwc1        $f0, 0xC($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0XC);
    // 0x800731B8: swc1        $f0, 0x5C($s1)
    MEM_W(0X5C, ctx->r17) = ctx->f0.u32l;
    // 0x800731BC: lwc1        $f0, 0x10($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X10);
    // 0x800731C0: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x800731C4: swc1        $f2, 0x48($s1)
    MEM_W(0X48, ctx->r17) = ctx->f2.u32l;
    // 0x800731C8: bne         $v1, $v0, L_800731EC
    if (ctx->r3 != ctx->r2) {
        // 0x800731CC: swc1        $f0, 0x60($s1)
        MEM_W(0X60, ctx->r17) = ctx->f0.u32l;
            goto L_800731EC;
    }
    // 0x800731CC: swc1        $f0, 0x60($s1)
    MEM_W(0X60, ctx->r17) = ctx->f0.u32l;
    // 0x800731D0: lw          $v0, 0x8($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X8);
    // 0x800731D4: lwl         $t0, 0x0($v0)
    ctx->r8 = do_lwl(rdram, ctx->r8, ctx->r2, 0X0);
    // 0x800731D8: lwr         $t0, 0x3($v0)
    ctx->r8 = do_lwr(rdram, ctx->r8, ctx->r2, 0X3);
    // 0x800731DC: swl         $t0, 0x40($s1)
    do_swl(rdram, 0X40, ctx->r17, ctx->r8);
    // 0x800731E0: swr         $t0, 0x43($s1)
    do_swr(rdram, 0X43, ctx->r17, ctx->r8);
    // 0x800731E4: j           L_80073200
    // 0x800731E8: nop

        goto L_80073200;
    // 0x800731E8: nop

L_800731EC:
    // 0x800731EC: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // 0x800731F0: sb          $v0, 0x40($s1)
    MEM_B(0X40, ctx->r17) = ctx->r2;
    // 0x800731F4: sb          $v0, 0x41($s1)
    MEM_B(0X41, ctx->r17) = ctx->r2;
    // 0x800731F8: sb          $v0, 0x42($s1)
    MEM_B(0X42, ctx->r17) = ctx->r2;
    // 0x800731FC: sb          $v0, 0x43($s1)
    MEM_B(0X43, ctx->r17) = ctx->r2;
L_80073200:
    // 0x80073200: lw          $a0, 0x30($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X30);
    // 0x80073204: jal         0x80057548
    // 0x80073208: addiu       $a1, $s1, 0x40
    ctx->r5 = ADD32(ctx->r17, 0X40);
    func_80057548(rdram, ctx);
        goto after_12;
    // 0x80073208: addiu       $a1, $s1, 0x40
    ctx->r5 = ADD32(ctx->r17, 0X40);
    after_12:
    // 0x8007320C: lw          $v1, 0x30($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X30);
    // 0x80073210: ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
    // 0x80073214: sh          $v0, 0x66($s1)
    MEM_H(0X66, ctx->r17) = ctx->r2;
    // 0x80073218: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8007321C: lwc1        $f0, 0x44($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X44);
    // 0x80073220: mul.s       $f0, $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f20.fl);
    // 0x80073224: lbu         $v0, 0x68($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X68);
    // 0x80073228: addiu       $v0, $v0, -0x2
    ctx->r2 = ADD32(ctx->r2, -0X2);
    // 0x8007322C: sltiu       $v0, $v0, 0x2
    ctx->r2 = ctx->r2 < 0X2 ? 1 : 0;
    // 0x80073230: beq         $v0, $zero, L_80073274
    if (ctx->r2 == 0) {
        // 0x80073234: swc1        $f0, 0x44($s1)
        MEM_W(0X44, ctx->r17) = ctx->f0.u32l;
            goto L_80073274;
    }
    // 0x80073234: swc1        $f0, 0x44($s1)
    MEM_W(0X44, ctx->r17) = ctx->f0.u32l;
    // 0x80073238: lwc1        $f0, 0x18($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X18);
    // 0x8007323C: lwc1        $f12, 0x38($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X38);
    // 0x80073240: div.s       $f12, $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = DIV_S(ctx->f12.fl, ctx->f0.fl);
    // 0x80073244: jal         0x8001C400
    // 0x80073248: swc1        $f0, 0x4C($s1)
    MEM_W(0X4C, ctx->r17) = ctx->f0.u32l;
    func_8001C400(rdram, ctx);
        goto after_13;
    // 0x80073248: swc1        $f0, 0x4C($s1)
    MEM_W(0X4C, ctx->r17) = ctx->f0.u32l;
    after_13:
    // 0x8007324C: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80073250: lwc1        $f4, -0x30A8($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X30A8);
    // 0x80073254: lwc1        $f2, 0x34($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0X34);
    // 0x80073258: lwc1        $f6, 0x5C($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X5C);
    // 0x8007325C: sub.s       $f4, $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f4.fl - ctx->f0.fl;
    // 0x80073260: swc1        $f0, 0x50($s1)
    MEM_W(0X50, ctx->r17) = ctx->f0.u32l;
    // 0x80073264: add.s       $f2, $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f6.fl;
    // 0x80073268: sb          $zero, 0x69($s1)
    MEM_B(0X69, ctx->r17) = 0;
    // 0x8007326C: swc1        $f4, 0x54($s1)
    MEM_W(0X54, ctx->r17) = ctx->f4.u32l;
    // 0x80073270: swc1        $f2, 0x58($s1)
    MEM_W(0X58, ctx->r17) = ctx->f2.u32l;
L_80073274:
    // 0x80073274: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
L_80073278:
    // 0x80073278: lhu         $a0, -0x6A8C($v0)
    ctx->r4 = MEM_HU(ctx->r2, -0X6A8C);
    // 0x8007327C: jal         0x8003E684
    // 0x80073280: addu        $a1, $s3, $zero
    ctx->r5 = ADD32(ctx->r19, 0);
    func_8003E684(rdram, ctx);
        goto after_14;
    // 0x80073280: addu        $a1, $s3, $zero
    ctx->r5 = ADD32(ctx->r19, 0);
    after_14:
    // 0x80073284: j           L_8007372C
    // 0x80073288: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8007372C;
    // 0x80073288: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8007328C:
    // 0x8007328C: lhu         $v1, 0x66($s1)
    ctx->r3 = MEM_HU(ctx->r17, 0X66);
    // 0x80073290: ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
    // 0x80073294: beq         $v1, $v0, L_800732A4
    if (ctx->r3 == ctx->r2) {
        // 0x80073298: nop
    
            goto L_800732A4;
    }
    // 0x80073298: nop

    // 0x8007329C: jal         0x8003F0C8
    // 0x800732A0: addu        $a0, $v1, $zero
    ctx->r4 = ADD32(ctx->r3, 0);
    func_8003F0C8(rdram, ctx);
        goto after_15;
    // 0x800732A0: addu        $a0, $v1, $zero
    ctx->r4 = ADD32(ctx->r3, 0);
    after_15:
L_800732A4:
    // 0x800732A4: lw          $a0, 0x30($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X30);
    // 0x800732A8: beq         $a0, $zero, L_8007372C
    if (ctx->r4 == 0) {
        // 0x800732AC: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_8007372C;
    }
    // 0x800732AC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800732B0: lbu         $v0, 0x68($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X68);
    // 0x800732B4: beq         $v0, $zero, L_800732CC
    if (ctx->r2 == 0) {
        // 0x800732B8: nop
    
            goto L_800732CC;
    }
    // 0x800732B8: nop

    // 0x800732BC: bltz        $v0, L_80073728
    if (SIGNED(ctx->r2) < 0) {
        // 0x800732C0: slti        $v0, $v0, 0x4
        ctx->r2 = SIGNED(ctx->r2) < 0X4 ? 1 : 0;
            goto L_80073728;
    }
    // 0x800732C0: slti        $v0, $v0, 0x4
    ctx->r2 = SIGNED(ctx->r2) < 0X4 ? 1 : 0;
    // 0x800732C4: beq         $v0, $zero, L_8007372C
    if (ctx->r2 == 0) {
        // 0x800732C8: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_8007372C;
    }
    // 0x800732C8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800732CC:
    // 0x800732CC: jal         0x8005779C
    // 0x800732D0: nop

    func_8005779C(rdram, ctx);
        goto after_16;
    // 0x800732D0: nop

    after_16:
    // 0x800732D4: j           L_8007372C
    // 0x800732D8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8007372C;
    // 0x800732D8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800732DC:
    // 0x800732DC: lbu         $v0, 0x68($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X68);
    // 0x800732E0: lwc1        $f20, 0x0($s2)
    ctx->f20.u32l = MEM_W(ctx->r18, 0X0);
    // 0x800732E4: beq         $v0, $zero, L_80073304
    if (ctx->r2 == 0) {
        // 0x800732E8: nop
    
            goto L_80073304;
    }
    // 0x800732E8: nop

    // 0x800732EC: bltz        $v0, L_80073728
    if (SIGNED(ctx->r2) < 0) {
        // 0x800732F0: slti        $v0, $v0, 0x4
        ctx->r2 = SIGNED(ctx->r2) < 0X4 ? 1 : 0;
            goto L_80073728;
    }
    // 0x800732F0: slti        $v0, $v0, 0x4
    ctx->r2 = SIGNED(ctx->r2) < 0X4 ? 1 : 0;
    // 0x800732F4: beq         $v0, $zero, L_8007372C
    if (ctx->r2 == 0) {
        // 0x800732F8: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_8007372C;
    }
    // 0x800732F8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800732FC: j           L_800734CC
    // 0x80073300: nop

        goto L_800734CC;
    // 0x80073300: nop

L_80073304:
    // 0x80073304: lhu         $a0, 0x66($s1)
    ctx->r4 = MEM_HU(ctx->r17, 0X66);
    // 0x80073308: jal         0x80040218
    // 0x8007330C: nop

    func_80040218(rdram, ctx);
        goto after_17;
    // 0x8007330C: nop

    after_17:
    // 0x80073310: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x80073314: ori         $v1, $zero, 0xFFFF
    ctx->r3 = 0 | 0XFFFF;
    // 0x80073318: beq         $v0, $v1, L_80072F80
    if (ctx->r2 == ctx->r3) {
        // 0x8007331C: nop
    
            goto L_80072F80;
    }
    // 0x8007331C: nop

    // 0x80073320: lhu         $a0, 0x64($s1)
    ctx->r4 = MEM_HU(ctx->r17, 0X64);
    // 0x80073324: jal         0x8004015C
    // 0x80073328: nop

    func_8004015C(rdram, ctx);
        goto after_18;
    // 0x80073328: nop

    after_18:
    // 0x8007332C: addu        $v1, $s1, $zero
    ctx->r3 = ADD32(ctx->r17, 0);
    // 0x80073330: addiu       $a0, $v0, 0x30
    ctx->r4 = ADD32(ctx->r2, 0X30);
L_80073334:
    // 0x80073334: lw          $t0, 0x0($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X0);
    // 0x80073338: lw          $t1, 0x4($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X4);
    // 0x8007333C: lw          $t2, 0x8($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X8);
    // 0x80073340: lw          $t3, 0xC($v0)
    ctx->r11 = MEM_W(ctx->r2, 0XC);
    // 0x80073344: sw          $t0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r8;
    // 0x80073348: sw          $t1, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r9;
    // 0x8007334C: sw          $t2, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r10;
    // 0x80073350: sw          $t3, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r11;
    // 0x80073354: addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
    // 0x80073358: bne         $v0, $a0, L_80073334
    if (ctx->r2 != ctx->r4) {
        // 0x8007335C: addiu       $v1, $v1, 0x10
        ctx->r3 = ADD32(ctx->r3, 0X10);
            goto L_80073334;
    }
    // 0x8007335C: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
    // 0x80073360: lui         $s0, 0x8014
    ctx->r16 = S32(0X8014 << 16);
    // 0x80073364: addiu       $s0, $s0, -0x7FA8
    ctx->r16 = ADD32(ctx->r16, -0X7FA8);
    // 0x80073368: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    // 0x8007336C: lwc1        $f12, 0x0($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X0);
    // 0x80073370: lwc1        $f14, 0x8($s1)
    ctx->f14.u32l = MEM_W(ctx->r17, 0X8);
    // 0x80073374: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80073378: lwc1        $f22, -0x30A4($at)
    ctx->f22.u32l = MEM_W(ctx->r1, -0X30A4);
    // 0x8007337C: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    // 0x80073380: sw          $zero, 0xC($s1)
    MEM_W(0XC, ctx->r17) = 0;
    // 0x80073384: sw          $zero, 0x10($s1)
    MEM_W(0X10, ctx->r17) = 0;
    // 0x80073388: sw          $zero, 0x18($s1)
    MEM_W(0X18, ctx->r17) = 0;
    // 0x8007338C: sw          $zero, 0x20($s1)
    MEM_W(0X20, ctx->r17) = 0;
    // 0x80073390: swc1        $f22, 0x14($s1)
    MEM_W(0X14, ctx->r17) = ctx->f22.u32l;
    // 0x80073394: jal         0x80067D90
    // 0x80073398: swc1        $f22, 0x1C($s1)
    MEM_W(0X1C, ctx->r17) = ctx->f22.u32l;
    func_80067D90(rdram, ctx);
        goto after_19;
    // 0x80073398: swc1        $f22, 0x1C($s1)
    MEM_W(0X1C, ctx->r17) = ctx->f22.u32l;
    after_19:
    // 0x8007339C: lwc1        $f12, 0x0($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X0);
    // 0x800733A0: lwc1        $f14, 0x8($s1)
    ctx->f14.u32l = MEM_W(ctx->r17, 0X8);
    // 0x800733A4: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    // 0x800733A8: jal         0x800698F4
    // 0x800733AC: swc1        $f0, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->f0.u32l;
    func_800698F4(rdram, ctx);
        goto after_20;
    // 0x800733AC: swc1        $f0, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->f0.u32l;
    after_20:
    // 0x800733B0: sltu        $v0, $zero, $v0
    ctx->r2 = 0 < ctx->r2 ? 1 : 0;
    // 0x800733B4: bne         $v0, $zero, L_800733E4
    if (ctx->r2 != 0) {
        // 0x800733B8: sb          $v0, 0x69($s1)
        MEM_B(0X69, ctx->r17) = ctx->r2;
            goto L_800733E4;
    }
    // 0x800733B8: sb          $v0, 0x69($s1)
    MEM_B(0X69, ctx->r17) = ctx->r2;
    // 0x800733BC: add.s       $f2, $f20, $f20
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f2.fl = ctx->f20.fl + ctx->f20.fl;
    // 0x800733C0: lwc1        $f0, 0x58($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X58);
    // 0x800733C4: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x800733C8: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x800733CC: c.le.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl <= ctx->f2.fl;
    // 0x800733D0: nop

    // 0x800733D4: bc1f        L_80073400
    if (!c1cs) {
        // 0x800733D8: swc1        $f0, 0x58($s1)
        MEM_W(0X58, ctx->r17) = ctx->f0.u32l;
            goto L_80073400;
    }
    // 0x800733D8: swc1        $f0, 0x58($s1)
    MEM_W(0X58, ctx->r17) = ctx->f0.u32l;
    // 0x800733DC: j           L_80073400
    // 0x800733E0: swc1        $f2, 0x58($s1)
    MEM_W(0X58, ctx->r17) = ctx->f2.u32l;
        goto L_80073400;
    // 0x800733E0: swc1        $f2, 0x58($s1)
    MEM_W(0X58, ctx->r17) = ctx->f2.u32l;
L_800733E4:
    // 0x800733E4: lwc1        $f0, 0x58($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X58);
    // 0x800733E8: add.s       $f0, $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f20.fl;
    // 0x800733EC: c.lt.s      $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f22.fl < ctx->f0.fl;
    // 0x800733F0: nop

    // 0x800733F4: bc1f        L_80073400
    if (!c1cs) {
        // 0x800733F8: swc1        $f0, 0x58($s1)
        MEM_W(0X58, ctx->r17) = ctx->f0.u32l;
            goto L_80073400;
    }
    // 0x800733F8: swc1        $f0, 0x58($s1)
    MEM_W(0X58, ctx->r17) = ctx->f0.u32l;
    // 0x800733FC: swc1        $f22, 0x58($s1)
    MEM_W(0X58, ctx->r17) = ctx->f22.u32l;
L_80073400:
    // 0x80073400: lwc1        $f0, 0x50($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X50);
    // 0x80073404: add.s       $f0, $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f20.fl;
    // 0x80073408: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8007340C: lwc1        $f22, -0x30A0($at)
    ctx->f22.u32l = MEM_W(ctx->r1, -0X30A0);
    // 0x80073410: c.le.s      $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f22.fl <= ctx->f0.fl;
    // 0x80073414: nop

    // 0x80073418: bc1f        L_80073428
    if (!c1cs) {
        // 0x8007341C: swc1        $f0, 0x50($s1)
        MEM_W(0X50, ctx->r17) = ctx->f0.u32l;
            goto L_80073428;
    }
    // 0x8007341C: swc1        $f0, 0x50($s1)
    MEM_W(0X50, ctx->r17) = ctx->f0.u32l;
    // 0x80073420: sub.s       $f0, $f0, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f22.fl;
    // 0x80073424: swc1        $f0, 0x50($s1)
    MEM_W(0X50, ctx->r17) = ctx->f0.u32l;
L_80073428:
    // 0x80073428: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8007342C: lwc1        $f0, -0x309C($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X309C);
    // 0x80073430: mul.s       $f0, $f20, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = MUL_S(ctx->f20.fl, ctx->f0.fl);
    // 0x80073434: lwc1        $f2, 0x4C($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0X4C);
    // 0x80073438: add.s       $f0, $f2, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x8007343C: c.le.s      $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f22.fl <= ctx->f0.fl;
    // 0x80073440: nop

    // 0x80073444: bc1f        L_80073454
    if (!c1cs) {
        // 0x80073448: swc1        $f0, 0x4C($s1)
        MEM_W(0X4C, ctx->r17) = ctx->f0.u32l;
            goto L_80073454;
    }
    // 0x80073448: swc1        $f0, 0x4C($s1)
    MEM_W(0X4C, ctx->r17) = ctx->f0.u32l;
    // 0x8007344C: sub.s       $f0, $f0, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f22.fl;
    // 0x80073450: swc1        $f0, 0x4C($s1)
    MEM_W(0X4C, ctx->r17) = ctx->f0.u32l;
L_80073454:
    // 0x80073454: lwc1        $f12, 0x50($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X50);
    // 0x80073458: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8007345C: lwc1        $f20, -0x3098($at)
    ctx->f20.u32l = MEM_W(ctx->r1, -0X3098);
    // 0x80073460: mul.s       $f12, $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f12.fl = MUL_S(ctx->f12.fl, ctx->f20.fl);
    // 0x80073464: jal         0x80033960
    // 0x80073468: add.s       $f12, $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = ctx->f12.fl + ctx->f12.fl;
    sinf_recomp(rdram, ctx);
        goto after_21;
    // 0x80073468: add.s       $f12, $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = ctx->f12.fl + ctx->f12.fl;
    after_21:
    // 0x8007346C: lwc1        $f12, 0x4C($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X4C);
    // 0x80073470: mul.s       $f12, $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f12.fl = MUL_S(ctx->f12.fl, ctx->f20.fl);
    // 0x80073474: add.s       $f12, $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = ctx->f12.fl + ctx->f12.fl;
    // 0x80073478: jal         0x80033960
    // 0x8007347C: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    sinf_recomp(rdram, ctx);
        goto after_22;
    // 0x8007347C: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    after_22:
    // 0x80073480: add.s       $f0, $f0, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f22.fl;
    // 0x80073484: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80073488: lwc1        $f2, -0x3094($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X3094);
    // 0x8007348C: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x80073490: add.s       $f20, $f20, $f22
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f20.fl = ctx->f20.fl + ctx->f22.fl;
    // 0x80073494: mul.s       $f20, $f20, $f2
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f20.fl = MUL_S(ctx->f20.fl, ctx->f2.fl);
    // 0x80073498: add.s       $f0, $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f0.fl;
    // 0x8007349C: mul.s       $f20, $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f20.fl = MUL_S(ctx->f20.fl, ctx->f0.fl);
    // 0x800734A0: lwc1        $f0, 0x54($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X54);
    // 0x800734A4: add.s       $f0, $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f20.fl;
    // 0x800734A8: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x800734AC: c.le.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl <= ctx->f2.fl;
    // 0x800734B0: nop

    // 0x800734B4: bc1f        L_80073728
    if (!c1cs) {
        // 0x800734B8: swc1        $f0, 0x38($s1)
        MEM_W(0X38, ctx->r17) = ctx->f0.u32l;
            goto L_80073728;
    }
    // 0x800734B8: swc1        $f0, 0x38($s1)
    MEM_W(0X38, ctx->r17) = ctx->f0.u32l;
    // 0x800734BC: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x800734C0: lwc1        $f0, -0x3090($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X3090);
    // 0x800734C4: j           L_80073728
    // 0x800734C8: swc1        $f0, 0x38($s1)
    MEM_W(0X38, ctx->r17) = ctx->f0.u32l;
        goto L_80073728;
    // 0x800734C8: swc1        $f0, 0x38($s1)
    MEM_W(0X38, ctx->r17) = ctx->f0.u32l;
L_800734CC:
    // 0x800734CC: lwc1        $f0, 0x60($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X60);
    // 0x800734D0: mul.s       $f0, $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f20.fl);
    // 0x800734D4: lwc1        $f2, 0x48($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0X48);
    // 0x800734D8: add.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x800734DC: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x800734E0: lwc1        $f0, -0x308C($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X308C);
    // 0x800734E4: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x800734E8: nop

    // 0x800734EC: bc1f        L_80072F80
    if (!c1cs) {
        // 0x800734F0: swc1        $f2, 0x48($s1)
        MEM_W(0X48, ctx->r17) = ctx->f2.u32l;
            goto L_80072F80;
    }
    // 0x800734F0: swc1        $f2, 0x48($s1)
    MEM_W(0X48, ctx->r17) = ctx->f2.u32l;
    // 0x800734F4: lwc1        $f8, 0x5C($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X5C);
    // 0x800734F8: lwc1        $f0, 0x60($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X60);
    // 0x800734FC: mul.s       $f8, $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x80073500: lwc1        $f6, 0x5C($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X5C);
    // 0x80073504: mul.s       $f6, $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x80073508: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8007350C: lwc1        $f10, -0x3088($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X3088);
    // 0x80073510: mul.s       $f2, $f2, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f10.fl);
    // 0x80073514: nop

    // 0x80073518: mul.s       $f8, $f8, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = MUL_S(ctx->f8.fl, ctx->f20.fl);
    // 0x8007351C: nop

    // 0x80073520: mul.s       $f6, $f6, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = MUL_S(ctx->f6.fl, ctx->f20.fl);
    // 0x80073524: sub.s       $f10, $f10, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = ctx->f10.fl - ctx->f2.fl;
    // 0x80073528: lwc1        $f4, 0x34($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X34);
    // 0x8007352C: add.s       $f4, $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x80073530: lwc1        $f0, 0x3C($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X3C);
    // 0x80073534: add.s       $f0, $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f6.fl;
    // 0x80073538: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8007353C: lwc1        $f2, -0x3084($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X3084);
    // 0x80073540: c.le.s      $f2, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f2.fl <= ctx->f10.fl;
    // 0x80073544: swc1        $f4, 0x34($s1)
    MEM_W(0X34, ctx->r17) = ctx->f4.u32l;
    // 0x80073548: bc1t        L_80073560
    if (c1cs) {
        // 0x8007354C: swc1        $f0, 0x3C($s1)
        MEM_W(0X3C, ctx->r17) = ctx->f0.u32l;
            goto L_80073560;
    }
    // 0x8007354C: swc1        $f0, 0x3C($s1)
    MEM_W(0X3C, ctx->r17) = ctx->f0.u32l;
    // 0x80073550: trunc.w.s   $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x80073554: mfc1        $v1, $f16
    ctx->r3 = (int32_t)ctx->f16.u32l;
    // 0x80073558: j           L_80073574
    // 0x8007355C: nop

        goto L_80073574;
    // 0x8007355C: nop

L_80073560:
    // 0x80073560: sub.s       $f0, $f10, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f10.fl - ctx->f2.fl;
    // 0x80073564: lui         $v0, 0x8000
    ctx->r2 = S32(0X8000 << 16);
    // 0x80073568: trunc.w.s   $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    ctx->f16.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x8007356C: mfc1        $v1, $f16
    ctx->r3 = (int32_t)ctx->f16.u32l;
    // 0x80073570: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
L_80073574:
    // 0x80073574: lw          $a0, 0x30($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X30);
    // 0x80073578: addiu       $a1, $s1, 0x40
    ctx->r5 = ADD32(ctx->r17, 0X40);
    // 0x8007357C: jal         0x80057548
    // 0x80073580: sb          $v1, 0x43($s1)
    MEM_B(0X43, ctx->r17) = ctx->r3;
    func_80057548(rdram, ctx);
        goto after_23;
    // 0x80073580: sb          $v1, 0x43($s1)
    MEM_B(0X43, ctx->r17) = ctx->r3;
    after_23:
    // 0x80073584: lbu         $v0, 0x68($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X68);
    // 0x80073588: addiu       $v0, $v0, -0x2
    ctx->r2 = ADD32(ctx->r2, -0X2);
    // 0x8007358C: sltiu       $v0, $v0, 0x2
    ctx->r2 = ctx->r2 < 0X2 ? 1 : 0;
    // 0x80073590: beq         $v0, $zero, L_800735E4
    if (ctx->r2 == 0) {
        // 0x80073594: nop
    
            goto L_800735E4;
    }
    // 0x80073594: nop

    // 0x80073598: lwc1        $f0, 0x54($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X54);
    // 0x8007359C: lwc1        $f2, 0x60($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0X60);
    // 0x800735A0: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x800735A4: nop

    // 0x800735A8: mul.s       $f0, $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f20.fl);
    // 0x800735AC: lwc1        $f12, 0x50($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X50);
    // 0x800735B0: add.s       $f12, $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = ctx->f12.fl + ctx->f0.fl;
    // 0x800735B4: jal         0x80033960
    // 0x800735B8: swc1        $f12, 0x50($s1)
    MEM_W(0X50, ctx->r17) = ctx->f12.u32l;
    sinf_recomp(rdram, ctx);
        goto after_24;
    // 0x800735B8: swc1        $f12, 0x50($s1)
    MEM_W(0X50, ctx->r17) = ctx->f12.u32l;
    after_24:
    // 0x800735BC: lwc1        $f2, 0x4C($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0X4C);
    // 0x800735C0: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x800735C4: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x800735C8: c.le.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl <= ctx->f2.fl;
    // 0x800735CC: nop

    // 0x800735D0: bc1f        L_800735E4
    if (!c1cs) {
        // 0x800735D4: swc1        $f0, 0x38($s1)
        MEM_W(0X38, ctx->r17) = ctx->f0.u32l;
            goto L_800735E4;
    }
    // 0x800735D4: swc1        $f0, 0x38($s1)
    MEM_W(0X38, ctx->r17) = ctx->f0.u32l;
    // 0x800735D8: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x800735DC: lwc1        $f0, -0x3080($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X3080);
    // 0x800735E0: swc1        $f0, 0x38($s1)
    MEM_W(0X38, ctx->r17) = ctx->f0.u32l;
L_800735E4:
    // 0x800735E4: lbu         $v1, 0x68($s1)
    ctx->r3 = MEM_BU(ctx->r17, 0X68);
    // 0x800735E8: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x800735EC: bne         $v1, $v0, L_8007372C
    if (ctx->r3 != ctx->r2) {
        // 0x800735F0: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_8007372C;
    }
    // 0x800735F0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800735F4: lbu         $v0, 0x69($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X69);
    // 0x800735F8: bne         $v0, $zero, L_8007372C
    if (ctx->r2 != 0) {
        // 0x800735FC: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_8007372C;
    }
    // 0x800735FC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80073600: lwc1        $f2, 0x48($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0X48);
    // 0x80073604: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80073608: lwc1        $f0, -0x307C($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X307C);
    // 0x8007360C: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x80073610: nop

    // 0x80073614: bc1f        L_80073728
    if (!c1cs) {
        // 0x80073618: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80073728;
    }
    // 0x80073618: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8007361C: sb          $v0, 0x69($s1)
    MEM_B(0X69, ctx->r17) = ctx->r2;
    // 0x80073620: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80073624: lwc1        $f0, 0x0($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X0);
    // 0x80073628: lwc1        $f2, 0x6FA8($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X6FA8);
    // 0x8007362C: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    // 0x80073630: lwc1        $f0, 0x4($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X4);
    // 0x80073634: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x80073638: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8007363C: lwc1        $f2, -0x3078($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X3078);
    // 0x80073640: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x80073644: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80073648: lwc1        $f2, -0x3074($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X3074);
    // 0x8007364C: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    // 0x80073650: lwc1        $f0, 0x8($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X8);
    // 0x80073654: swc1        $f0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f0.u32l;
    // 0x80073658: lwc1        $f0, 0x58($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X58);
    // 0x8007365C: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x80073660: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    // 0x80073664: lwc1        $f4, 0x60($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X60);
    // 0x80073668: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8007366C: lwc1        $f0, -0x3070($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X3070);
    // 0x80073670: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80073674: lwc1        $f2, -0x306C($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X306C);
    // 0x80073678: div.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f4.fl);
    // 0x8007367C: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x80073680: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    // 0x80073684: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x80073688: lui         $a3, 0x3C23
    ctx->r7 = S32(0X3C23 << 16);
    // 0x8007368C: ori         $a3, $a3, 0xD70A
    ctx->r7 = ctx->r7 | 0XD70A;
    // 0x80073690: addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    // 0x80073694: jal         0x80072550
    // 0x80073698: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    func_80072550(rdram, ctx);
        goto after_25;
    // 0x80073698: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    after_25:
    // 0x8007369C: j           L_8007372C
    // 0x800736A0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8007372C;
    // 0x800736A0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800736A4:
    // 0x800736A4: lbu         $v0, 0x68($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X68);
    // 0x800736A8: bne         $v0, $zero, L_800736F4
    if (ctx->r2 != 0) {
        // 0x800736AC: nop
    
            goto L_800736F4;
    }
    // 0x800736AC: nop

    // 0x800736B0: lwc1        $f0, 0x34($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X34);
    // 0x800736B4: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    // 0x800736B8: lwc1        $f0, 0x38($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X38);
    // 0x800736BC: lwc1        $f2, 0x58($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0X58);
    // 0x800736C0: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x800736C4: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    // 0x800736C8: lwc1        $f0, 0x3C($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X3C);
    // 0x800736CC: swc1        $f0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f0.u32l;
    // 0x800736D0: lwc1        $f2, 0x58($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0X58);
    // 0x800736D4: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800736D8: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x800736DC: nop

    // 0x800736E0: bc1f        L_80073728
    if (!c1cs) {
        // 0x800736E4: addu        $a1, $s1, $zero
        ctx->r5 = ADD32(ctx->r17, 0);
            goto L_80073728;
    }
    // 0x800736E4: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    // 0x800736E8: lw          $a0, 0x30($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X30);
    // 0x800736EC: j           L_8007370C
    // 0x800736F0: addiu       $a2, $sp, 0x18
    ctx->r6 = ADD32(ctx->r29, 0X18);
        goto L_8007370C;
    // 0x800736F0: addiu       $a2, $sp, 0x18
    ctx->r6 = ADD32(ctx->r29, 0X18);
L_800736F4:
    // 0x800736F4: bltz        $v0, L_80073728
    if (SIGNED(ctx->r2) < 0) {
        // 0x800736F8: slti        $v0, $v0, 0x4
        ctx->r2 = SIGNED(ctx->r2) < 0X4 ? 1 : 0;
            goto L_80073728;
    }
    // 0x800736F8: slti        $v0, $v0, 0x4
    ctx->r2 = SIGNED(ctx->r2) < 0X4 ? 1 : 0;
    // 0x800736FC: beq         $v0, $zero, L_80073728
    if (ctx->r2 == 0) {
        // 0x80073700: addu        $a1, $s1, $zero
        ctx->r5 = ADD32(ctx->r17, 0);
            goto L_80073728;
    }
    // 0x80073700: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    // 0x80073704: lw          $a0, 0x30($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X30);
    // 0x80073708: addiu       $a2, $s1, 0x34
    ctx->r6 = ADD32(ctx->r17, 0X34);
L_8007370C:
    // 0x8007370C: jal         0x80059C24
    // 0x80073710: addiu       $a0, $a0, 0x28
    ctx->r4 = ADD32(ctx->r4, 0X28);
    func_80059C24(rdram, ctx);
        goto after_26;
    // 0x80073710: addiu       $a0, $a0, 0x28
    ctx->r4 = ADD32(ctx->r4, 0X28);
    after_26:
    // 0x80073714: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    // 0x80073718: lw          $a1, 0x30($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X30);
    // 0x8007371C: lw          $a3, 0x44($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X44);
    // 0x80073720: jal         0x80057C8C
    // 0x80073724: addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    func_80057C8C(rdram, ctx);
        goto after_27;
    // 0x80073724: addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    after_27:
L_80073728:
    // 0x80073728: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8007372C:
    // 0x8007372C: lw          $ra, 0x38($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X38);
    // 0x80073730: lw          $s3, 0x34($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X34);
    // 0x80073734: lw          $s2, 0x30($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X30);
    // 0x80073738: lw          $s1, 0x2C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X2C);
    // 0x8007373C: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x80073740: ldc1        $f22, 0x48($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X48);
    // 0x80073744: ldc1        $f20, 0x40($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X40);
    // 0x80073748: jr          $ra
    // 0x8007374C: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x8007374C: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}
RECOMP_FUNC void func_80073750(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80073750: addiu       $sp, $sp, -0xA0
    ctx->r29 = ADD32(ctx->r29, -0XA0);
    // 0x80073754: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80073758: mtc1        $a2, $f10
    ctx->f10.u32l = ctx->r6;
    // 0x8007375C: mtc1        $a3, $f14
    ctx->f14.u32l = ctx->r7;
    // 0x80073760: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80073764: lwc1        $f0, -0x3068($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X3068);
    // 0x80073768: lwc1        $f6, 0xB0($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XB0);
    // 0x8007376C: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80073770: lwc1        $f16, -0x3064($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X3064);
    // 0x80073774: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80073778: lwc1        $f12, -0x3060($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X3060);
    // 0x8007377C: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80073780: lwc1        $f4, -0x305C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X305C);
    // 0x80073784: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80073788: lwc1        $f2, -0x3058($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X3058);
    // 0x8007378C: lw          $v0, 0xC08($v0)
    ctx->r2 = MEM_W(ctx->r2, 0XC08);
    // 0x80073790: mul.s       $f8, $f14, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = MUL_S(ctx->f14.fl, ctx->f16.fl);
    // 0x80073794: sw          $ra, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->r31;
    // 0x80073798: sw          $s1, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->r17;
    // 0x8007379C: sw          $s0, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->r16;
    // 0x800737A0: addiu       $v0, $v0, 0x18
    ctx->r2 = ADD32(ctx->r2, 0X18);
    // 0x800737A4: mul.s       $f4, $f10, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f4.fl);
    // 0x800737A8: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    // 0x800737AC: lw          $t0, 0x0($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X0);
    // 0x800737B0: lw          $t1, 0x4($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X4);
    // 0x800737B4: lw          $t2, 0x8($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X8);
    // 0x800737B8: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    // 0x800737BC: sw          $t1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r9;
    // 0x800737C0: sw          $t2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r10;
    // 0x800737C4: sw          $v0, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r2;
    // 0x800737C8: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x800737CC: sb          $v0, 0x7C($sp)
    MEM_B(0X7C, ctx->r29) = ctx->r2;
    // 0x800737D0: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800737D4: neg.s       $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = -ctx->f6.fl;
    // 0x800737D8: swc1        $f0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f0.u32l;
    // 0x800737DC: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x800737E0: lwc1        $f0, -0x3054($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X3054);
    // 0x800737E4: lw          $v0, 0xC04($v0)
    ctx->r2 = MEM_W(ctx->r2, 0XC04);
    // 0x800737E8: mul.s       $f14, $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = MUL_S(ctx->f14.fl, ctx->f0.fl);
    // 0x800737EC: addu        $s1, $a1, $zero
    ctx->r17 = ADD32(ctx->r5, 0);
    // 0x800737F0: swc1        $f2, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f2.u32l;
    // 0x800737F4: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x800737F8: lwc1        $f0, -0x3050($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X3050);
    // 0x800737FC: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80073800: lwc1        $f2, -0x304C($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X304C);
    // 0x80073804: mul.s       $f4, $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x80073808: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8007380C: lwc1        $f0, -0x3048($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X3048);
    // 0x80073810: div.s       $f6, $f10, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f6.fl = DIV_S(ctx->f10.fl, ctx->f6.fl);
    // 0x80073814: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    // 0x80073818: sw          $zero, 0x28($sp)
    MEM_W(0X28, ctx->r29) = 0;
    // 0x8007381C: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x80073820: sw          $zero, 0x30($sp)
    MEM_W(0X30, ctx->r29) = 0;
    // 0x80073824: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    // 0x80073828: swc1        $f12, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f12.u32l;
    // 0x8007382C: swc1        $f12, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f12.u32l;
    // 0x80073830: sw          $zero, 0x40($sp)
    MEM_W(0X40, ctx->r29) = 0;
    // 0x80073834: sw          $zero, 0x44($sp)
    MEM_W(0X44, ctx->r29) = 0;
    // 0x80073838: mul.s       $f10, $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x8007383C: sh          $zero, 0x4C($sp)
    MEM_H(0X4C, ctx->r29) = 0;
    // 0x80073840: sh          $zero, 0x4E($sp)
    MEM_H(0X4E, ctx->r29) = 0;
    // 0x80073844: sw          $zero, 0x54($sp)
    MEM_W(0X54, ctx->r29) = 0;
    // 0x80073848: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8007384C: lwc1        $f0, -0x3044($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X3044);
    // 0x80073850: mul.s       $f14, $f14, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f14.fl = MUL_S(ctx->f14.fl, ctx->f16.fl);
    // 0x80073854: sw          $zero, 0x58($sp)
    MEM_W(0X58, ctx->r29) = 0;
    // 0x80073858: swc1        $f6, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f6.u32l;
    // 0x8007385C: sw          $zero, 0x60($sp)
    MEM_W(0X60, ctx->r29) = 0;
    // 0x80073860: swc1        $f12, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f12.u32l;
    // 0x80073864: mul.s       $f8, $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x80073868: sw          $zero, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = 0;
    // 0x8007386C: sw          $v0, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r2;
    // 0x80073870: addiu       $v0, $zero, 0x10
    ctx->r2 = ADD32(0, 0X10);
    // 0x80073874: sb          $v0, 0x7D($sp)
    MEM_B(0X7D, ctx->r29) = ctx->r2;
    // 0x80073878: add.s       $f0, $f8, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = ctx->f8.fl + ctx->f12.fl;
    // 0x8007387C: swc1        $f10, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f10.u32l;
    // 0x80073880: c.le.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl <= ctx->f0.fl;
    // 0x80073884: nop

    // 0x80073888: bc1t        L_800738A0
    if (c1cs) {
        // 0x8007388C: swc1        $f4, 0x48($sp)
        MEM_W(0X48, ctx->r29) = ctx->f4.u32l;
            goto L_800738A0;
    }
    // 0x8007388C: swc1        $f4, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f4.u32l;
    // 0x80073890: trunc.w.s   $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    ctx->f18.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x80073894: mfc1        $v1, $f18
    ctx->r3 = (int32_t)ctx->f18.u32l;
    // 0x80073898: j           L_800738B4
    // 0x8007389C: nop

        goto L_800738B4;
    // 0x8007389C: nop

L_800738A0:
    // 0x800738A0: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x800738A4: lui         $v0, 0x8000
    ctx->r2 = S32(0X8000 << 16);
    // 0x800738A8: trunc.w.s   $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    ctx->f18.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800738AC: mfc1        $v1, $f18
    ctx->r3 = (int32_t)ctx->f18.u32l;
    // 0x800738B0: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
L_800738B4:
    // 0x800738B4: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x800738B8: lwc1        $f0, -0x3040($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X3040);
    // 0x800738BC: mul.s       $f0, $f14, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = MUL_S(ctx->f14.fl, ctx->f0.fl);
    // 0x800738C0: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x800738C4: lwc1        $f2, -0x303C($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X303C);
    // 0x800738C8: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x800738CC: lwc1        $f4, -0x3038($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X3038);
    // 0x800738D0: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x800738D4: c.le.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl <= ctx->f0.fl;
    // 0x800738D8: nop

    // 0x800738DC: bc1t        L_800738F4
    if (c1cs) {
        // 0x800738E0: sh          $v1, 0x80($sp)
        MEM_H(0X80, ctx->r29) = ctx->r3;
            goto L_800738F4;
    }
    // 0x800738E0: sh          $v1, 0x80($sp)
    MEM_H(0X80, ctx->r29) = ctx->r3;
    // 0x800738E4: trunc.w.s   $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    ctx->f18.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800738E8: mfc1        $v1, $f18
    ctx->r3 = (int32_t)ctx->f18.u32l;
    // 0x800738EC: j           L_80073908
    // 0x800738F0: nop

        goto L_80073908;
    // 0x800738F0: nop

L_800738F4:
    // 0x800738F4: sub.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f4.fl;
    // 0x800738F8: lui         $v0, 0x8000
    ctx->r2 = S32(0X8000 << 16);
    // 0x800738FC: trunc.w.s   $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    ctx->f18.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x80073900: mfc1        $v1, $f18
    ctx->r3 = (int32_t)ctx->f18.u32l;
    // 0x80073904: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
L_80073908:
    // 0x80073908: lwc1        $f2, 0x50($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X50);
    // 0x8007390C: lwc1        $f0, 0xB4($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0XB4);
    // 0x80073910: mul.s       $f0, $f2, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x80073914: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80073918: lwc1        $f2, -0x3034($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X3034);
    // 0x8007391C: c.le.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl <= ctx->f0.fl;
    // 0x80073920: nop

    // 0x80073924: bc1t        L_8007393C
    if (c1cs) {
        // 0x80073928: sh          $v1, 0x82($sp)
        MEM_H(0X82, ctx->r29) = ctx->r3;
            goto L_8007393C;
    }
    // 0x80073928: sh          $v1, 0x82($sp)
    MEM_H(0X82, ctx->r29) = ctx->r3;
    // 0x8007392C: trunc.w.s   $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    ctx->f18.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x80073930: mfc1        $v1, $f18
    ctx->r3 = (int32_t)ctx->f18.u32l;
    // 0x80073934: j           L_80073954
    // 0x80073938: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
        goto L_80073954;
    // 0x80073938: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
L_8007393C:
    // 0x8007393C: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x80073940: lui         $v0, 0x8000
    ctx->r2 = S32(0X8000 << 16);
    // 0x80073944: trunc.w.s   $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    ctx->f18.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x80073948: mfc1        $v1, $f18
    ctx->r3 = (int32_t)ctx->f18.u32l;
    // 0x8007394C: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x80073950: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
L_80073954:
    // 0x80073954: lui         $v0, 0x900
    ctx->r2 = S32(0X900 << 16);
    // 0x80073958: sw          $v0, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r2;
    // 0x8007395C: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x80073960: sh          $v1, 0x84($sp)
    MEM_H(0X84, ctx->r29) = ctx->r3;
    // 0x80073964: jal         0x80041CBC
    // 0x80073968: sh          $v0, 0x8C($sp)
    MEM_H(0X8C, ctx->r29) = ctx->r2;
    func_80041CBC(rdram, ctx);
        goto after_0;
    // 0x80073968: sh          $v0, 0x8C($sp)
    MEM_H(0X8C, ctx->r29) = ctx->r2;
    after_0:
    // 0x8007396C: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    // 0x80073970: andi        $a1, $s1, 0xFFFF
    ctx->r5 = ctx->r17 & 0XFFFF;
    // 0x80073974: ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
    // 0x80073978: beq         $a1, $v0, L_8007398C
    if (ctx->r5 == ctx->r2) {
        // 0x8007397C: andi        $a0, $s0, 0xFFFF
        ctx->r4 = ctx->r16 & 0XFFFF;
            goto L_8007398C;
    }
    // 0x8007397C: andi        $a0, $s0, 0xFFFF
    ctx->r4 = ctx->r16 & 0XFFFF;
    // 0x80073980: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // 0x80073984: jal         0x80041D8C
    // 0x80073988: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    func_80041D8C(rdram, ctx);
        goto after_1;
    // 0x80073988: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    after_1:
L_8007398C:
    // 0x8007398C: andi        $v0, $s0, 0xFFFF
    ctx->r2 = ctx->r16 & 0XFFFF;
    // 0x80073990: lw          $ra, 0x98($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X98);
    // 0x80073994: lw          $s1, 0x94($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X94);
    // 0x80073998: lw          $s0, 0x90($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X90);
    // 0x8007399C: jr          $ra
    // 0x800739A0: addiu       $sp, $sp, 0xA0
    ctx->r29 = ADD32(ctx->r29, 0XA0);
    return;
    // 0x800739A0: addiu       $sp, $sp, 0xA0
    ctx->r29 = ADD32(ctx->r29, 0XA0);
;}
RECOMP_FUNC void func_800739A4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800739A4: addiu       $sp, $sp, -0xA8
    ctx->r29 = ADD32(ctx->r29, -0XA8);
    // 0x800739A8: sdc1        $f22, 0xA0($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0XA0, ctx->r29);
    // 0x800739AC: mtc1        $a1, $f22
    ctx->f22.u32l = ctx->r5;
    // 0x800739B0: sw          $s0, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->r16;
    // 0x800739B4: sdc1        $f20, 0x98($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X98, ctx->r29);
    // 0x800739B8: mtc1        $a2, $f20
    ctx->f20.u32l = ctx->r6;
    // 0x800739BC: sw          $ra, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->r31;
    // 0x800739C0: jal         0x800775F4
    // 0x800739C4: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    func_800775F4(rdram, ctx);
        goto after_0;
    // 0x800739C4: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    after_0:
    // 0x800739C8: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x800739CC: lwc1        $f2, -0x3030($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X3030);
    // 0x800739D0: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x800739D4: lwc1        $f4, -0x302C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X302C);
    // 0x800739D8: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x800739DC: lwc1        $f6, -0x3028($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X3028);
    // 0x800739E0: div.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f2.fl);
    // 0x800739E4: mul.s       $f22, $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f22.fl = MUL_S(ctx->f22.fl, ctx->f0.fl);
    // 0x800739E8: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x800739EC: lwc1        $f2, -0x3024($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X3024);
    // 0x800739F0: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x800739F4: lwc1        $f0, -0x3020($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X3020);
    // 0x800739F8: addiu       $v0, $zero, 0x1E
    ctx->r2 = ADD32(0, 0X1E);
    // 0x800739FC: swc1        $f2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f2.u32l;
    // 0x80073A00: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80073A04: lwc1        $f2, -0x301C($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X301C);
    // 0x80073A08: addiu       $v1, $zero, 0x4
    ctx->r3 = ADD32(0, 0X4);
    // 0x80073A0C: lw          $a3, 0x0($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X0);
    // 0x80073A10: lw          $t0, 0x4($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X4);
    // 0x80073A14: lw          $t1, 0x8($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X8);
    // 0x80073A18: sw          $a3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r7;
    // 0x80073A1C: sw          $t0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r8;
    // 0x80073A20: sw          $t1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r9;
    // 0x80073A24: sh          $v0, 0x4C($sp)
    MEM_H(0X4C, ctx->r29) = ctx->r2;
    // 0x80073A28: sh          $v0, 0x4E($sp)
    MEM_H(0X4E, ctx->r29) = ctx->r2;
    // 0x80073A2C: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80073A30: swc1        $f0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f0.u32l;
    // 0x80073A34: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80073A38: lwc1        $f0, -0x3018($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X3018);
    // 0x80073A3C: lw          $v0, 0xC08($v0)
    ctx->r2 = MEM_W(ctx->r2, 0XC08);
    // 0x80073A40: neg.s       $f20, $f20
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); 
    ctx->f20.fl = -ctx->f20.fl;
    // 0x80073A44: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    // 0x80073A48: swc1        $f20, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f20.u32l;
    // 0x80073A4C: sw          $zero, 0x28($sp)
    MEM_W(0X28, ctx->r29) = 0;
    // 0x80073A50: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x80073A54: sw          $zero, 0x30($sp)
    MEM_W(0X30, ctx->r29) = 0;
    // 0x80073A58: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    // 0x80073A5C: sw          $zero, 0x40($sp)
    MEM_W(0X40, ctx->r29) = 0;
    // 0x80073A60: sw          $zero, 0x44($sp)
    MEM_W(0X44, ctx->r29) = 0;
    // 0x80073A64: sw          $zero, 0x54($sp)
    MEM_W(0X54, ctx->r29) = 0;
    // 0x80073A68: sw          $zero, 0x58($sp)
    MEM_W(0X58, ctx->r29) = 0;
    // 0x80073A6C: swc1        $f4, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f4.u32l;
    // 0x80073A70: sw          $zero, 0x60($sp)
    MEM_W(0X60, ctx->r29) = 0;
    // 0x80073A74: swc1        $f6, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f6.u32l;
    // 0x80073A78: sw          $zero, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = 0;
    // 0x80073A7C: swc1        $f2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f2.u32l;
    // 0x80073A80: swc1        $f2, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f2.u32l;
    // 0x80073A84: swc1        $f2, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f2.u32l;
    // 0x80073A88: mul.s       $f2, $f22, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = MUL_S(ctx->f22.fl, ctx->f4.fl);
    // 0x80073A8C: swc1        $f0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f0.u32l;
    // 0x80073A90: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80073A94: lwc1        $f0, -0x3014($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X3014);
    // 0x80073A98: addiu       $v0, $v0, 0x1C
    ctx->r2 = ADD32(ctx->r2, 0X1C);
    // 0x80073A9C: sw          $v0, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r2;
    // 0x80073AA0: mul.s       $f22, $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f22.fl = MUL_S(ctx->f22.fl, ctx->f0.fl);
    // 0x80073AA4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80073AA8: sb          $v0, 0x7C($sp)
    MEM_B(0X7C, ctx->r29) = ctx->r2;
    // 0x80073AAC: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80073AB0: lw          $v0, 0xB70($v0)
    ctx->r2 = MEM_W(ctx->r2, 0XB70);
    // 0x80073AB4: mul.s       $f22, $f22, $f4
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f22.fl = MUL_S(ctx->f22.fl, ctx->f4.fl);
    // 0x80073AB8: bne         $v0, $v1, L_80073ACC
    if (ctx->r2 != ctx->r3) {
        // 0x80073ABC: lui         $v0, 0x8013
        ctx->r2 = S32(0X8013 << 16);
            goto L_80073ACC;
    }
    // 0x80073ABC: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80073AC0: lw          $v0, 0xC04($v0)
    ctx->r2 = MEM_W(ctx->r2, 0XC04);
    // 0x80073AC4: j           L_80073AD4
    // 0x80073AC8: addiu       $v0, $v0, 0xC0
    ctx->r2 = ADD32(ctx->r2, 0XC0);
        goto L_80073AD4;
    // 0x80073AC8: addiu       $v0, $v0, 0xC0
    ctx->r2 = ADD32(ctx->r2, 0XC0);
L_80073ACC:
    // 0x80073ACC: lw          $v0, 0xC04($v0)
    ctx->r2 = MEM_W(ctx->r2, 0XC04);
    // 0x80073AD0: addiu       $v0, $v0, 0x80
    ctx->r2 = ADD32(ctx->r2, 0X80);
L_80073AD4:
    // 0x80073AD4: sw          $v0, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r2;
    // 0x80073AD8: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80073ADC: lwc1        $f0, -0x3010($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X3010);
    // 0x80073AE0: mul.s       $f0, $f2, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x80073AE4: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80073AE8: lwc1        $f2, -0x300C($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X300C);
    // 0x80073AEC: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80073AF0: lwc1        $f4, -0x3008($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X3008);
    // 0x80073AF4: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x80073AF8: addiu       $v0, $zero, 0x10
    ctx->r2 = ADD32(0, 0X10);
    // 0x80073AFC: c.le.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl <= ctx->f0.fl;
    // 0x80073B00: nop

    // 0x80073B04: bc1t        L_80073B1C
    if (c1cs) {
        // 0x80073B08: sb          $v0, 0x7D($sp)
        MEM_B(0X7D, ctx->r29) = ctx->r2;
            goto L_80073B1C;
    }
    // 0x80073B08: sb          $v0, 0x7D($sp)
    MEM_B(0X7D, ctx->r29) = ctx->r2;
    // 0x80073B0C: trunc.w.s   $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    ctx->f8.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x80073B10: mfc1        $v1, $f8
    ctx->r3 = (int32_t)ctx->f8.u32l;
    // 0x80073B14: j           L_80073B30
    // 0x80073B18: nop

        goto L_80073B30;
    // 0x80073B18: nop

L_80073B1C:
    // 0x80073B1C: sub.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f4.fl;
    // 0x80073B20: lui         $v0, 0x8000
    ctx->r2 = S32(0X8000 << 16);
    // 0x80073B24: trunc.w.s   $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    ctx->f8.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x80073B28: mfc1        $v1, $f8
    ctx->r3 = (int32_t)ctx->f8.u32l;
    // 0x80073B2C: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
L_80073B30:
    // 0x80073B30: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80073B34: lwc1        $f0, -0x3004($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X3004);
    // 0x80073B38: mul.s       $f0, $f22, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = MUL_S(ctx->f22.fl, ctx->f0.fl);
    // 0x80073B3C: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80073B40: lwc1        $f2, -0x3000($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X3000);
    // 0x80073B44: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80073B48: lwc1        $f4, -0x2FFC($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X2FFC);
    // 0x80073B4C: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x80073B50: c.le.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl <= ctx->f0.fl;
    // 0x80073B54: nop

    // 0x80073B58: bc1t        L_80073B70
    if (c1cs) {
        // 0x80073B5C: sh          $v1, 0x80($sp)
        MEM_H(0X80, ctx->r29) = ctx->r3;
            goto L_80073B70;
    }
    // 0x80073B5C: sh          $v1, 0x80($sp)
    MEM_H(0X80, ctx->r29) = ctx->r3;
    // 0x80073B60: trunc.w.s   $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    ctx->f8.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x80073B64: mfc1        $v1, $f8
    ctx->r3 = (int32_t)ctx->f8.u32l;
    // 0x80073B68: j           L_80073B88
    // 0x80073B6C: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
        goto L_80073B88;
    // 0x80073B6C: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
L_80073B70:
    // 0x80073B70: sub.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f4.fl;
    // 0x80073B74: lui         $v0, 0x8000
    ctx->r2 = S32(0X8000 << 16);
    // 0x80073B78: trunc.w.s   $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    ctx->f8.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x80073B7C: mfc1        $v1, $f8
    ctx->r3 = (int32_t)ctx->f8.u32l;
    // 0x80073B80: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x80073B84: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
L_80073B88:
    // 0x80073B88: addiu       $v0, $zero, 0x14
    ctx->r2 = ADD32(0, 0X14);
    // 0x80073B8C: sh          $v0, 0x84($sp)
    MEM_H(0X84, ctx->r29) = ctx->r2;
    // 0x80073B90: lui         $v0, 0x900
    ctx->r2 = S32(0X900 << 16);
    // 0x80073B94: sw          $v0, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r2;
    // 0x80073B98: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x80073B9C: sh          $v1, 0x82($sp)
    MEM_H(0X82, ctx->r29) = ctx->r3;
    // 0x80073BA0: jal         0x80041CBC
    // 0x80073BA4: sh          $v0, 0x8C($sp)
    MEM_H(0X8C, ctx->r29) = ctx->r2;
    func_80041CBC(rdram, ctx);
        goto after_1;
    // 0x80073BA4: sh          $v0, 0x8C($sp)
    MEM_H(0X8C, ctx->r29) = ctx->r2;
    after_1:
    // 0x80073BA8: andi        $s0, $v0, 0xFFFF
    ctx->r16 = ctx->r2 & 0XFFFF;
    // 0x80073BAC: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x80073BB0: lui         $a1, 0x8014
    ctx->r5 = S32(0X8014 << 16);
    // 0x80073BB4: jal         0x80041D08
    // 0x80073BB8: addiu       $a1, $a1, -0x5740
    ctx->r5 = ADD32(ctx->r5, -0X5740);
    func_80041D08(rdram, ctx);
        goto after_2;
    // 0x80073BB8: addiu       $a1, $a1, -0x5740
    ctx->r5 = ADD32(ctx->r5, -0X5740);
    after_2:
    // 0x80073BBC: addu        $v0, $s0, $zero
    ctx->r2 = ADD32(ctx->r16, 0);
    // 0x80073BC0: lw          $ra, 0x94($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X94);
    // 0x80073BC4: lw          $s0, 0x90($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X90);
    // 0x80073BC8: ldc1        $f22, 0xA0($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0XA0);
    // 0x80073BCC: ldc1        $f20, 0x98($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X98);
    // 0x80073BD0: jr          $ra
    // 0x80073BD4: addiu       $sp, $sp, 0xA8
    ctx->r29 = ADD32(ctx->r29, 0XA8);
    return;
    // 0x80073BD4: addiu       $sp, $sp, 0xA8
    ctx->r29 = ADD32(ctx->r29, 0XA8);
;}
RECOMP_FUNC void func_80073BD8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80073BD8: addiu       $sp, $sp, -0xA0
    ctx->r29 = ADD32(ctx->r29, -0XA0);
    // 0x80073BDC: sw          $s1, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->r17;
    // 0x80073BE0: addu        $s1, $a1, $zero
    ctx->r17 = ADD32(ctx->r5, 0);
    // 0x80073BE4: andi        $v1, $s1, 0xFFFF
    ctx->r3 = ctx->r17 & 0XFFFF;
    // 0x80073BE8: lwc1        $f4, 0xB0($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XB0);
    // 0x80073BEC: mtc1        $a2, $f12
    ctx->f12.u32l = ctx->r6;
    // 0x80073BF0: mtc1        $a3, $f6
    ctx->f6.u32l = ctx->r7;
    // 0x80073BF4: ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
    // 0x80073BF8: sw          $ra, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->r31;
    // 0x80073BFC: beq         $v1, $v0, L_80073E38
    if (ctx->r3 == ctx->r2) {
        // 0x80073C00: sw          $s0, 0x90($sp)
        MEM_W(0X90, ctx->r29) = ctx->r16;
            goto L_80073E38;
    }
    // 0x80073C00: sw          $s0, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->r16;
    // 0x80073C04: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80073C08: lwc1        $f2, -0x2FF8($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X2FF8);
    // 0x80073C0C: mul.s       $f14, $f6, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f14.fl = MUL_S(ctx->f6.fl, ctx->f2.fl);
    // 0x80073C10: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80073C14: lwc1        $f0, -0x2FF4($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X2FF4);
    // 0x80073C18: mul.s       $f0, $f6, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x80073C1C: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80073C20: c.eq.s      $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f4.fl == ctx->f10.fl;
    // 0x80073C24: mul.s       $f16, $f0, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x80073C28: bc1f        L_80073C38
    if (!c1cs) {
        // 0x80073C2C: nop
    
            goto L_80073C38;
    }
    // 0x80073C2C: nop

    // 0x80073C30: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80073C34: lwc1        $f4, -0x2FF0($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X2FF0);
L_80073C38:
    // 0x80073C38: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80073C3C: lwc1        $f0, -0x2FEC($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X2FEC);
    // 0x80073C40: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80073C44: lwc1        $f2, -0x2FE8($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X2FE8);
    // 0x80073C48: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80073C4C: lwc1        $f8, -0x2FE4($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X2FE4);
    // 0x80073C50: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80073C54: lwc1        $f6, -0x2FE0($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X2FE0);
    // 0x80073C58: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    // 0x80073C5C: lw          $t0, 0x0($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X0);
    // 0x80073C60: lw          $t1, 0x4($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X4);
    // 0x80073C64: lw          $t2, 0x8($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X8);
    // 0x80073C68: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    // 0x80073C6C: sw          $t1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r9;
    // 0x80073C70: sw          $t2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r10;
    // 0x80073C74: swc1        $f2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f2.u32l;
    // 0x80073C78: div.s       $f2, $f12, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = DIV_S(ctx->f12.fl, ctx->f4.fl);
    // 0x80073C7C: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80073C80: lwc1        $f4, -0x2FDC($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X2FDC);
    // 0x80073C84: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80073C88: lwc1        $f0, -0x2FD8($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X2FD8);
    // 0x80073C8C: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x80073C90: swc1        $f2, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f2.u32l;
    // 0x80073C94: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80073C98: lwc1        $f2, -0x2FD4($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X2FD4);
    // 0x80073C9C: addiu       $v0, $v0, -0x6790
    ctx->r2 = ADD32(ctx->r2, -0X6790);
    // 0x80073CA0: sw          $v0, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r2;
    // 0x80073CA4: addiu       $v0, $zero, 0x14
    ctx->r2 = ADD32(0, 0X14);
    // 0x80073CA8: sb          $v0, 0x7C($sp)
    MEM_B(0X7C, ctx->r29) = ctx->r2;
    // 0x80073CAC: addiu       $v0, $zero, 0x1400
    ctx->r2 = ADD32(0, 0X1400);
    // 0x80073CB0: swc1        $f10, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f10.u32l;
    // 0x80073CB4: swc1        $f10, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f10.u32l;
    // 0x80073CB8: swc1        $f10, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f10.u32l;
    // 0x80073CBC: swc1        $f10, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f10.u32l;
    // 0x80073CC0: swc1        $f10, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f10.u32l;
    // 0x80073CC4: mul.s       $f4, $f12, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f4.fl = MUL_S(ctx->f12.fl, ctx->f4.fl);
    // 0x80073CC8: swc1        $f8, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f8.u32l;
    // 0x80073CCC: swc1        $f8, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f8.u32l;
    // 0x80073CD0: swc1        $f0, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f0.u32l;
    // 0x80073CD4: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80073CD8: lwc1        $f0, -0x2FD0($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X2FD0);
    // 0x80073CDC: mul.s       $f2, $f12, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = MUL_S(ctx->f12.fl, ctx->f2.fl);
    // 0x80073CE0: swc1        $f10, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f10.u32l;
    // 0x80073CE4: swc1        $f10, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f10.u32l;
    // 0x80073CE8: sh          $zero, 0x4C($sp)
    MEM_H(0X4C, ctx->r29) = 0;
    // 0x80073CEC: sh          $zero, 0x4E($sp)
    MEM_H(0X4E, ctx->r29) = 0;
    // 0x80073CF0: mul.s       $f0, $f14, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = MUL_S(ctx->f14.fl, ctx->f0.fl);
    // 0x80073CF4: swc1        $f10, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f10.u32l;
    // 0x80073CF8: swc1        $f10, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f10.u32l;
    // 0x80073CFC: swc1        $f10, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f10.u32l;
    // 0x80073D00: swc1        $f8, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f8.u32l;
    // 0x80073D04: mul.s       $f4, $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80073D08: swc1        $f10, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->f10.u32l;
    // 0x80073D0C: sh          $v0, 0x7E($sp)
    MEM_H(0X7E, ctx->r29) = ctx->r2;
    // 0x80073D10: sw          $zero, 0x78($sp)
    MEM_W(0X78, ctx->r29) = 0;
    // 0x80073D14: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80073D18: lwc1        $f6, -0x2FCC($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X2FCC);
    // 0x80073D1C: add.s       $f0, $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f8.fl;
    // 0x80073D20: sb          $zero, 0x7D($sp)
    MEM_B(0X7D, ctx->r29) = 0;
    // 0x80073D24: swc1        $f2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f2.u32l;
    // 0x80073D28: c.le.s      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.fl <= ctx->f0.fl;
    // 0x80073D2C: nop

    // 0x80073D30: bc1t        L_80073D48
    if (c1cs) {
        // 0x80073D34: swc1        $f4, 0x48($sp)
        MEM_W(0X48, ctx->r29) = ctx->f4.u32l;
            goto L_80073D48;
    }
    // 0x80073D34: swc1        $f4, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f4.u32l;
    // 0x80073D38: trunc.w.s   $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    ctx->f18.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x80073D3C: mfc1        $v1, $f18
    ctx->r3 = (int32_t)ctx->f18.u32l;
    // 0x80073D40: j           L_80073D5C
    // 0x80073D44: nop

        goto L_80073D5C;
    // 0x80073D44: nop

L_80073D48:
    // 0x80073D48: sub.s       $f0, $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f6.fl;
    // 0x80073D4C: lui         $v0, 0x8000
    ctx->r2 = S32(0X8000 << 16);
    // 0x80073D50: trunc.w.s   $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    ctx->f18.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x80073D54: mfc1        $v1, $f18
    ctx->r3 = (int32_t)ctx->f18.u32l;
    // 0x80073D58: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
L_80073D5C:
    // 0x80073D5C: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80073D60: lwc1        $f0, -0x2FC8($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X2FC8);
    // 0x80073D64: mul.s       $f0, $f16, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x80073D68: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80073D6C: lwc1        $f2, -0x2FC4($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X2FC4);
    // 0x80073D70: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80073D74: lwc1        $f4, -0x2FC0($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X2FC0);
    // 0x80073D78: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x80073D7C: c.le.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl <= ctx->f0.fl;
    // 0x80073D80: nop

    // 0x80073D84: bc1t        L_80073D9C
    if (c1cs) {
        // 0x80073D88: sh          $v1, 0x80($sp)
        MEM_H(0X80, ctx->r29) = ctx->r3;
            goto L_80073D9C;
    }
    // 0x80073D88: sh          $v1, 0x80($sp)
    MEM_H(0X80, ctx->r29) = ctx->r3;
    // 0x80073D8C: trunc.w.s   $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    ctx->f18.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x80073D90: mfc1        $v1, $f18
    ctx->r3 = (int32_t)ctx->f18.u32l;
    // 0x80073D94: j           L_80073DB0
    // 0x80073D98: nop

        goto L_80073DB0;
    // 0x80073D98: nop

L_80073D9C:
    // 0x80073D9C: sub.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f4.fl;
    // 0x80073DA0: lui         $v0, 0x8000
    ctx->r2 = S32(0X8000 << 16);
    // 0x80073DA4: trunc.w.s   $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    ctx->f18.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x80073DA8: mfc1        $v1, $f18
    ctx->r3 = (int32_t)ctx->f18.u32l;
    // 0x80073DAC: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
L_80073DB0:
    // 0x80073DB0: lwc1        $f2, 0x50($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X50);
    // 0x80073DB4: lwc1        $f0, 0xB4($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0XB4);
    // 0x80073DB8: mul.s       $f0, $f2, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x80073DBC: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80073DC0: lwc1        $f2, -0x2FBC($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X2FBC);
    // 0x80073DC4: c.le.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl <= ctx->f0.fl;
    // 0x80073DC8: nop

    // 0x80073DCC: bc1t        L_80073DE4
    if (c1cs) {
        // 0x80073DD0: sh          $v1, 0x82($sp)
        MEM_H(0X82, ctx->r29) = ctx->r3;
            goto L_80073DE4;
    }
    // 0x80073DD0: sh          $v1, 0x82($sp)
    MEM_H(0X82, ctx->r29) = ctx->r3;
    // 0x80073DD4: trunc.w.s   $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    ctx->f18.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x80073DD8: mfc1        $v1, $f18
    ctx->r3 = (int32_t)ctx->f18.u32l;
    // 0x80073DDC: j           L_80073DFC
    // 0x80073DE0: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
        goto L_80073DFC;
    // 0x80073DE0: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
L_80073DE4:
    // 0x80073DE4: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x80073DE8: lui         $v0, 0x8000
    ctx->r2 = S32(0X8000 << 16);
    // 0x80073DEC: trunc.w.s   $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    ctx->f18.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x80073DF0: mfc1        $v1, $f18
    ctx->r3 = (int32_t)ctx->f18.u32l;
    // 0x80073DF4: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x80073DF8: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
L_80073DFC:
    // 0x80073DFC: lui         $v0, 0x900
    ctx->r2 = S32(0X900 << 16);
    // 0x80073E00: sw          $v0, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r2;
    // 0x80073E04: addiu       $v0, $zero, 0x1B
    ctx->r2 = ADD32(0, 0X1B);
    // 0x80073E08: sh          $v1, 0x84($sp)
    MEM_H(0X84, ctx->r29) = ctx->r3;
    // 0x80073E0C: jal         0x80041CBC
    // 0x80073E10: sh          $v0, 0x8C($sp)
    MEM_H(0X8C, ctx->r29) = ctx->r2;
    func_80041CBC(rdram, ctx);
        goto after_0;
    // 0x80073E10: sh          $v0, 0x8C($sp)
    MEM_H(0X8C, ctx->r29) = ctx->r2;
    after_0:
    // 0x80073E14: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    // 0x80073E18: andi        $a1, $s1, 0xFFFF
    ctx->r5 = ctx->r17 & 0XFFFF;
    // 0x80073E1C: ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
    // 0x80073E20: beq         $a1, $v0, L_80073E34
    if (ctx->r5 == ctx->r2) {
        // 0x80073E24: andi        $a0, $s0, 0xFFFF
        ctx->r4 = ctx->r16 & 0XFFFF;
            goto L_80073E34;
    }
    // 0x80073E24: andi        $a0, $s0, 0xFFFF
    ctx->r4 = ctx->r16 & 0XFFFF;
    // 0x80073E28: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // 0x80073E2C: jal         0x80041D8C
    // 0x80073E30: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    func_80041D8C(rdram, ctx);
        goto after_1;
    // 0x80073E30: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    after_1:
L_80073E34:
    // 0x80073E34: andi        $v0, $s0, 0xFFFF
    ctx->r2 = ctx->r16 & 0XFFFF;
L_80073E38:
    // 0x80073E38: lw          $ra, 0x98($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X98);
    // 0x80073E3C: lw          $s1, 0x94($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X94);
    // 0x80073E40: lw          $s0, 0x90($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X90);
    // 0x80073E44: jr          $ra
    // 0x80073E48: addiu       $sp, $sp, 0xA0
    ctx->r29 = ADD32(ctx->r29, 0XA0);
    return;
    // 0x80073E48: addiu       $sp, $sp, 0xA0
    ctx->r29 = ADD32(ctx->r29, 0XA0);
;}
RECOMP_FUNC void func_80073E4C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80073E4C: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x80073E50: lw          $v0, -0x72E4($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X72E4);
    // 0x80073E54: addiu       $sp, $sp, -0xD0
    ctx->r29 = ADD32(ctx->r29, -0XD0);
    // 0x80073E58: sw          $s0, 0xB8($sp)
    MEM_W(0XB8, ctx->r29) = ctx->r16;
    // 0x80073E5C: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x80073E60: sw          $ra, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->r31;
    // 0x80073E64: sdc1        $f22, 0xC8($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0XC8, ctx->r29);
    // 0x80073E68: sdc1        $f20, 0xC0($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0XC0, ctx->r29);
    // 0x80073E6C: lwc1        $f0, 0x0($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X0);
    // 0x80073E70: addiu       $v0, $v0, 0x28
    ctx->r2 = ADD32(ctx->r2, 0X28);
    // 0x80073E74: lwc1        $f2, 0x24($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X24);
    // 0x80073E78: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x80073E7C: swc1        $f0, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->f0.u32l;
    // 0x80073E80: lwc1        $f0, 0x4($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X4);
    // 0x80073E84: lwc1        $f2, 0x28($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X28);
    // 0x80073E88: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x80073E8C: swc1        $f0, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->f0.u32l;
    // 0x80073E90: lwc1        $f0, 0x8($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X8);
    // 0x80073E94: lwc1        $f2, 0x2C($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X2C);
    // 0x80073E98: mtc1        $a1, $f20
    ctx->f20.u32l = ctx->r5;
    // 0x80073E9C: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x80073EA0: mtc1        $a2, $f22
    ctx->f22.u32l = ctx->r6;
    // 0x80073EA4: swc1        $f0, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->f0.u32l;
    // 0x80073EA8: lwc1        $f0, 0x8($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X8);
    // 0x80073EAC: swc1        $f0, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->f0.u32l;
    // 0x80073EB0: lwc1        $f0, 0x14($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X14);
    // 0x80073EB4: swc1        $f0, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->f0.u32l;
    // 0x80073EB8: lwc1        $f0, 0x20($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X20);
    // 0x80073EBC: addiu       $a0, $sp, 0x90
    ctx->r4 = ADD32(ctx->r29, 0X90);
    // 0x80073EC0: jal         0x8001CF2C
    // 0x80073EC4: swc1        $f0, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->f0.u32l;
    func_8001CF2C(rdram, ctx);
        goto after_0;
    // 0x80073EC4: swc1        $f0, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->f0.u32l;
    after_0:
    // 0x80073EC8: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x80073ECC: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x80073ED0: nop

    // 0x80073ED4: bc1f        L_80073F08
    if (!c1cs) {
        // 0x80073ED8: swc1        $f0, 0xB0($sp)
        MEM_W(0XB0, ctx->r29) = ctx->f0.u32l;
            goto L_80073F08;
    }
    // 0x80073ED8: swc1        $f0, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->f0.u32l;
    // 0x80073EDC: addiu       $a0, $sp, 0xA0
    ctx->r4 = ADD32(ctx->r29, 0XA0);
    // 0x80073EE0: jal         0x8001CFE8
    // 0x80073EE4: addiu       $a1, $sp, 0x90
    ctx->r5 = ADD32(ctx->r29, 0X90);
    func_8001CFE8(rdram, ctx);
        goto after_1;
    // 0x80073EE4: addiu       $a1, $sp, 0x90
    ctx->r5 = ADD32(ctx->r29, 0X90);
    after_1:
    // 0x80073EE8: lwc1        $f2, 0xB0($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0XB0);
    // 0x80073EEC: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80073EF0: lwc1        $f4, -0x2FB8($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X2FB8);
    // 0x80073EF4: div.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f2.fl);
    // 0x80073EF8: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x80073EFC: nop

    // 0x80073F00: bc1t        L_80073F0C
    if (c1cs) {
        // 0x80073F04: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80073F0C;
    }
    // 0x80073F04: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80073F08:
    // 0x80073F08: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_80073F0C:
    // 0x80073F0C: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x80073F10: beq         $v0, $zero, L_80074124
    if (ctx->r2 == 0) {
        // 0x80073F14: ori         $v0, $zero, 0xFFFF
        ctx->r2 = 0 | 0XFFFF;
            goto L_80074124;
    }
    // 0x80073F14: ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
    // 0x80073F18: lwc1        $f2, 0xB0($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0XB0);
    // 0x80073F1C: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80073F20: lwc1        $f0, -0x2FB4($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X2FB4);
    // 0x80073F24: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x80073F28: nop

    // 0x80073F2C: bc1f        L_80073F50
    if (!c1cs) {
        // 0x80073F30: addiu       $a1, $zero, 0x14
        ctx->r5 = ADD32(0, 0X14);
            goto L_80073F50;
    }
    // 0x80073F30: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    // 0x80073F34: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80073F38: lwc1        $f0, -0x2FB0($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X2FB0);
    // 0x80073F3C: div.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f2.fl);
    // 0x80073F40: trunc.w.s   $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    ctx->f8.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x80073F44: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x80073F48: blezl       $a1, L_80073F50
    if (SIGNED(ctx->r5) <= 0) {
        // 0x80073F4C: addiu       $a1, $zero, 0x1
        ctx->r5 = ADD32(0, 0X1);
            goto L_80073F50;
    }
    goto skip_0;
    // 0x80073F4C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    skip_0:
L_80073F50:
    // 0x80073F50: lwc1        $f0, 0xB0($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0XB0);
    // 0x80073F54: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80073F58: lwc1        $f2, -0x2FAC($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X2FAC);
    // 0x80073F5C: div.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f2.fl);
    // 0x80073F60: mul.s       $f20, $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f20.fl = MUL_S(ctx->f20.fl, ctx->f0.fl);
    // 0x80073F64: addiu       $v0, $zero, 0x168
    ctx->r2 = ADD32(0, 0X168);
    // 0x80073F68: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80073F6C: lwc1        $f4, -0x2FA8($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X2FA8);
    // 0x80073F70: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80073F74: lwc1        $f2, -0x2FA4($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X2FA4);
    // 0x80073F78: neg.s       $f0, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f22.fl); 
    ctx->f0.fl = -ctx->f22.fl;
    // 0x80073F7C: swc1        $f2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f2.u32l;
    // 0x80073F80: lw          $t0, 0x0($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X0);
    // 0x80073F84: lw          $t1, 0x4($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X4);
    // 0x80073F88: lw          $t2, 0x8($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X8);
    // 0x80073F8C: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    // 0x80073F90: sw          $t1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r9;
    // 0x80073F94: sw          $t2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r10;
    // 0x80073F98: sh          $v0, 0x4C($sp)
    MEM_H(0X4C, ctx->r29) = ctx->r2;
    // 0x80073F9C: sh          $v0, 0x4E($sp)
    MEM_H(0X4E, ctx->r29) = ctx->r2;
    // 0x80073FA0: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80073FA4: swc1        $f0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f0.u32l;
    // 0x80073FA8: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80073FAC: lwc1        $f0, -0x2FA0($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X2FA0);
    // 0x80073FB0: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80073FB4: lwc1        $f2, -0x2F9C($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X2F9C);
    // 0x80073FB8: lw          $v0, 0xC08($v0)
    ctx->r2 = MEM_W(ctx->r2, 0XC08);
    // 0x80073FBC: swc1        $f0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f0.u32l;
    // 0x80073FC0: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80073FC4: lwc1        $f0, -0x2F98($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X2F98);
    // 0x80073FC8: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    // 0x80073FCC: sw          $zero, 0x28($sp)
    MEM_W(0X28, ctx->r29) = 0;
    // 0x80073FD0: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x80073FD4: sw          $zero, 0x30($sp)
    MEM_W(0X30, ctx->r29) = 0;
    // 0x80073FD8: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    // 0x80073FDC: swc1        $f4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f4.u32l;
    // 0x80073FE0: swc1        $f4, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f4.u32l;
    // 0x80073FE4: sw          $zero, 0x40($sp)
    MEM_W(0X40, ctx->r29) = 0;
    // 0x80073FE8: sw          $zero, 0x44($sp)
    MEM_W(0X44, ctx->r29) = 0;
    // 0x80073FEC: sw          $zero, 0x54($sp)
    MEM_W(0X54, ctx->r29) = 0;
    // 0x80073FF0: sw          $zero, 0x58($sp)
    MEM_W(0X58, ctx->r29) = 0;
    // 0x80073FF4: swc1        $f2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f2.u32l;
    // 0x80073FF8: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80073FFC: lwc1        $f2, -0x2F94($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X2F94);
    // 0x80074000: mul.s       $f0, $f20, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = MUL_S(ctx->f20.fl, ctx->f0.fl);
    // 0x80074004: swc1        $f4, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f4.u32l;
    // 0x80074008: sw          $zero, 0x60($sp)
    MEM_W(0X60, ctx->r29) = 0;
    // 0x8007400C: sw          $zero, 0x64($sp)
    MEM_W(0X64, ctx->r29) = 0;
    // 0x80074010: swc1        $f4, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f4.u32l;
    // 0x80074014: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x80074018: sw          $zero, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = 0;
    // 0x8007401C: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80074020: lwc1        $f2, -0x2F90($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X2F90);
    // 0x80074024: addiu       $v0, $v0, 0x1E
    ctx->r2 = ADD32(ctx->r2, 0X1E);
    // 0x80074028: sw          $v0, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r2;
    // 0x8007402C: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x80074030: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80074034: sb          $v0, 0x7C($sp)
    MEM_B(0X7C, ctx->r29) = ctx->r2;
    // 0x80074038: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8007403C: lw          $v0, 0xC04($v0)
    ctx->r2 = MEM_W(ctx->r2, 0XC04);
    // 0x80074040: add.s       $f2, $f0, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = ctx->f0.fl + ctx->f4.fl;
    // 0x80074044: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80074048: lwc1        $f0, -0x2F8C($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X2F8C);
    // 0x8007404C: addiu       $v0, $v0, 0x100
    ctx->r2 = ADD32(ctx->r2, 0X100);
    // 0x80074050: mul.s       $f6, $f20, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f20.fl, ctx->f0.fl);
    // 0x80074054: sw          $v0, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r2;
    // 0x80074058: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8007405C: lwc1        $f4, -0x2F88($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X2F88);
    // 0x80074060: addiu       $v0, $zero, 0x10
    ctx->r2 = ADD32(0, 0X10);
    // 0x80074064: c.le.s      $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f4.fl <= ctx->f2.fl;
    // 0x80074068: nop

    // 0x8007406C: bc1t        L_80074084
    if (c1cs) {
        // 0x80074070: sb          $v0, 0x7D($sp)
        MEM_B(0X7D, ctx->r29) = ctx->r2;
            goto L_80074084;
    }
    // 0x80074070: sb          $v0, 0x7D($sp)
    MEM_B(0X7D, ctx->r29) = ctx->r2;
    // 0x80074074: trunc.w.s   $f8, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    ctx->f8.u32l = TRUNC_W_S(ctx->f2.fl);
    // 0x80074078: mfc1        $v1, $f8
    ctx->r3 = (int32_t)ctx->f8.u32l;
    // 0x8007407C: j           L_80074098
    // 0x80074080: nop

        goto L_80074098;
    // 0x80074080: nop

L_80074084:
    // 0x80074084: sub.s       $f0, $f2, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f2.fl - ctx->f4.fl;
    // 0x80074088: lui         $v0, 0x8000
    ctx->r2 = S32(0X8000 << 16);
    // 0x8007408C: trunc.w.s   $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    ctx->f8.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x80074090: mfc1        $v1, $f8
    ctx->r3 = (int32_t)ctx->f8.u32l;
    // 0x80074094: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
L_80074098:
    // 0x80074098: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8007409C: lwc1        $f0, -0x2F84($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X2F84);
    // 0x800740A0: mul.s       $f0, $f6, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x800740A4: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x800740A8: lwc1        $f2, -0x2F80($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X2F80);
    // 0x800740AC: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x800740B0: lwc1        $f4, -0x2F7C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X2F7C);
    // 0x800740B4: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x800740B8: c.le.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl <= ctx->f0.fl;
    // 0x800740BC: nop

    // 0x800740C0: bc1t        L_800740D8
    if (c1cs) {
        // 0x800740C4: sh          $v1, 0x80($sp)
        MEM_H(0X80, ctx->r29) = ctx->r3;
            goto L_800740D8;
    }
    // 0x800740C4: sh          $v1, 0x80($sp)
    MEM_H(0X80, ctx->r29) = ctx->r3;
    // 0x800740C8: trunc.w.s   $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    ctx->f8.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800740CC: mfc1        $v1, $f8
    ctx->r3 = (int32_t)ctx->f8.u32l;
    // 0x800740D0: j           L_800740F0
    // 0x800740D4: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
        goto L_800740F0;
    // 0x800740D4: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
L_800740D8:
    // 0x800740D8: sub.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f4.fl;
    // 0x800740DC: lui         $v0, 0x8000
    ctx->r2 = S32(0X8000 << 16);
    // 0x800740E0: trunc.w.s   $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    ctx->f8.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800740E4: mfc1        $v1, $f8
    ctx->r3 = (int32_t)ctx->f8.u32l;
    // 0x800740E8: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x800740EC: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
L_800740F0:
    // 0x800740F0: lui         $v0, 0x900
    ctx->r2 = S32(0X900 << 16);
    // 0x800740F4: sw          $v0, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r2;
    // 0x800740F8: addiu       $v0, $zero, 0xB
    ctx->r2 = ADD32(0, 0XB);
    // 0x800740FC: sh          $v1, 0x82($sp)
    MEM_H(0X82, ctx->r29) = ctx->r3;
    // 0x80074100: sh          $a1, 0x84($sp)
    MEM_H(0X84, ctx->r29) = ctx->r5;
    // 0x80074104: jal         0x80041CBC
    // 0x80074108: sh          $v0, 0x8C($sp)
    MEM_H(0X8C, ctx->r29) = ctx->r2;
    func_80041CBC(rdram, ctx);
        goto after_2;
    // 0x80074108: sh          $v0, 0x8C($sp)
    MEM_H(0X8C, ctx->r29) = ctx->r2;
    after_2:
    // 0x8007410C: andi        $s0, $v0, 0xFFFF
    ctx->r16 = ctx->r2 & 0XFFFF;
    // 0x80074110: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x80074114: lui         $a1, 0x8014
    ctx->r5 = S32(0X8014 << 16);
    // 0x80074118: jal         0x80041D08
    // 0x8007411C: addiu       $a1, $a1, -0x56E0
    ctx->r5 = ADD32(ctx->r5, -0X56E0);
    func_80041D08(rdram, ctx);
        goto after_3;
    // 0x8007411C: addiu       $a1, $a1, -0x56E0
    ctx->r5 = ADD32(ctx->r5, -0X56E0);
    after_3:
    // 0x80074120: addu        $v0, $s0, $zero
    ctx->r2 = ADD32(ctx->r16, 0);
L_80074124:
    // 0x80074124: lw          $ra, 0xBC($sp)
    ctx->r31 = MEM_W(ctx->r29, 0XBC);
    // 0x80074128: lw          $s0, 0xB8($sp)
    ctx->r16 = MEM_W(ctx->r29, 0XB8);
    // 0x8007412C: ldc1        $f22, 0xC8($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0XC8);
    // 0x80074130: ldc1        $f20, 0xC0($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0XC0);
    // 0x80074134: jr          $ra
    // 0x80074138: addiu       $sp, $sp, 0xD0
    ctx->r29 = ADD32(ctx->r29, 0XD0);
    return;
    // 0x80074138: addiu       $sp, $sp, 0xD0
    ctx->r29 = ADD32(ctx->r29, 0XD0);
;}
RECOMP_FUNC void func_8007413C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007413C: addiu       $sp, $sp, -0x90
    ctx->r29 = ADD32(ctx->r29, -0X90);
    // 0x80074140: sw          $s3, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r19;
    // 0x80074144: addu        $s3, $a0, $zero
    ctx->r19 = ADD32(ctx->r4, 0);
    // 0x80074148: sw          $s0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r16;
    // 0x8007414C: andi        $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 & 0XFFFF;
    // 0x80074150: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x80074154: sw          $ra, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r31;
    // 0x80074158: sw          $s2, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r18;
    // 0x8007415C: sw          $s1, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r17;
    // 0x80074160: sdc1        $f22, 0x88($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X88, ctx->r29);
    // 0x80074164: sdc1        $f20, 0x80($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X80, ctx->r29);
    // 0x80074168: lw          $s2, 0x4($s3)
    ctx->r18 = MEM_W(ctx->r19, 0X4);
    // 0x8007416C: beq         $a1, $v0, L_800745D8
    if (ctx->r5 == ctx->r2) {
        // 0x80074170: addu        $s0, $a2, $zero
        ctx->r16 = ADD32(ctx->r6, 0);
            goto L_800745D8;
    }
    // 0x80074170: addu        $s0, $a2, $zero
    ctx->r16 = ADD32(ctx->r6, 0);
    // 0x80074174: slti        $v0, $a1, 0x3
    ctx->r2 = SIGNED(ctx->r5) < 0X3 ? 1 : 0;
    // 0x80074178: beq         $v0, $zero, L_80074190
    if (ctx->r2 == 0) {
        // 0x8007417C: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80074190;
    }
    // 0x8007417C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80074180: beq         $a1, $v0, L_800741AC
    if (ctx->r5 == ctx->r2) {
        // 0x80074184: addiu       $v0, $zero, 0x201
        ctx->r2 = ADD32(0, 0X201);
            goto L_800741AC;
    }
    // 0x80074184: addiu       $v0, $zero, 0x201
    ctx->r2 = ADD32(0, 0X201);
    // 0x80074188: j           L_800745DC
    // 0x8007418C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_800745DC;
    // 0x8007418C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80074190:
    // 0x80074190: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x80074194: beq         $a1, $v0, L_800742B0
    if (ctx->r5 == ctx->r2) {
        // 0x80074198: addiu       $v0, $zero, 0x4
        ctx->r2 = ADD32(0, 0X4);
            goto L_800742B0;
    }
    // 0x80074198: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // 0x8007419C: beq         $a1, $v0, L_80074510
    if (ctx->r5 == ctx->r2) {
        // 0x800741A0: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80074510;
    }
    // 0x800741A0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800741A4: j           L_800745DC
    // 0x800741A8: nop

        goto L_800745DC;
    // 0x800741A8: nop

L_800741AC:
    // 0x800741AC: sh          $v0, 0x40($s2)
    MEM_H(0X40, ctx->r18) = ctx->r2;
    // 0x800741B0: lw          $v0, 0x4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X4);
    // 0x800741B4: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x800741B8: lwl         $t0, 0x0($v0)
    ctx->r8 = do_lwl(rdram, ctx->r8, ctx->r2, 0X0);
    // 0x800741BC: lwr         $t0, 0x3($v0)
    ctx->r8 = do_lwr(rdram, ctx->r8, ctx->r2, 0X3);
    // 0x800741C0: swl         $t0, 0x5C($s2)
    do_swl(rdram, 0X5C, ctx->r18, ctx->r8);
    // 0x800741C4: swr         $t0, 0x5F($s2)
    do_swr(rdram, 0X5F, ctx->r18, ctx->r8);
    // 0x800741C8: sh          $zero, 0x5A($s2)
    MEM_H(0X5A, ctx->r18) = 0;
    // 0x800741CC: sh          $zero, 0x58($s2)
    MEM_H(0X58, ctx->r18) = 0;
    // 0x800741D0: lwc1        $f0, 0xC($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0XC);
    // 0x800741D4: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x800741D8: swc1        $f0, 0x50($s2)
    MEM_W(0X50, ctx->r18) = ctx->f0.u32l;
    // 0x800741DC: lwc1        $f0, 0xC($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0XC);
    // 0x800741E0: addiu       $a0, $s2, 0x18
    ctx->r4 = ADD32(ctx->r18, 0X18);
    // 0x800741E4: swc1        $f20, 0x4C($s2)
    MEM_W(0X4C, ctx->r18) = ctx->f20.u32l;
    // 0x800741E8: swc1        $f0, 0x54($s2)
    MEM_W(0X54, ctx->r18) = ctx->f0.u32l;
    // 0x800741EC: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x800741F0: addiu       $a1, $s2, 0xC
    ctx->r5 = ADD32(ctx->r18, 0XC);
    // 0x800741F4: lw          $t0, 0x0($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X0);
    // 0x800741F8: lw          $t1, 0x4($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X4);
    // 0x800741FC: lw          $t2, 0x8($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X8);
    // 0x80074200: sw          $t0, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r8;
    // 0x80074204: sw          $t1, 0x4($s2)
    MEM_W(0X4, ctx->r18) = ctx->r9;
    // 0x80074208: sw          $t2, 0x8($s2)
    MEM_W(0X8, ctx->r18) = ctx->r10;
    // 0x8007420C: swc1        $f20, 0x68($s2)
    MEM_W(0X68, ctx->r18) = ctx->f20.u32l;
    // 0x80074210: lw          $v0, 0x8($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X8);
    // 0x80074214: addiu       $a3, $zero, 0x32
    ctx->r7 = ADD32(0, 0X32);
    // 0x80074218: lwl         $t0, 0x0($v0)
    ctx->r8 = do_lwl(rdram, ctx->r8, ctx->r2, 0X0);
    // 0x8007421C: lwr         $t0, 0x3($v0)
    ctx->r8 = do_lwr(rdram, ctx->r8, ctx->r2, 0X3);
    // 0x80074220: swl         $t0, 0x60($s2)
    do_swl(rdram, 0X60, ctx->r18, ctx->r8);
    // 0x80074224: swr         $t0, 0x63($s2)
    do_swr(rdram, 0X63, ctx->r18, ctx->r8);
    // 0x80074228: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x8007422C: jal         0x8007202C
    // 0x80074230: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    func_8007202C(rdram, ctx);
        goto after_0;
    // 0x80074230: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    after_0:
    // 0x80074234: lwc1        $f4, 0xC($s2)
    ctx->f4.u32l = MEM_W(ctx->r18, 0XC);
    // 0x80074238: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8007423C: lwc1        $f0, -0x2F6C($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X2F6C);
    // 0x80074240: sub.s       $f4, $f0, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f4.fl = ctx->f0.fl - ctx->f4.fl;
    // 0x80074244: lwc1        $f2, 0x10($s2)
    ctx->f2.u32l = MEM_W(ctx->r18, 0X10);
    // 0x80074248: sub.s       $f2, $f0, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x8007424C: lwc1        $f6, 0x14($s2)
    ctx->f6.u32l = MEM_W(ctx->r18, 0X14);
    // 0x80074250: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // 0x80074254: sub.s       $f0, $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f6.fl;
    // 0x80074258: swc1        $f4, 0x18($s2)
    MEM_W(0X18, ctx->r18) = ctx->f4.u32l;
    // 0x8007425C: swc1        $f2, 0x1C($s2)
    MEM_W(0X1C, ctx->r18) = ctx->f2.u32l;
    // 0x80074260: jal         0x80059F10
    // 0x80074264: swc1        $f0, 0x20($s2)
    MEM_W(0X20, ctx->r18) = ctx->f0.u32l;
    func_80059F10(rdram, ctx);
        goto after_1;
    // 0x80074264: swc1        $f0, 0x20($s2)
    MEM_W(0X20, ctx->r18) = ctx->f0.u32l;
    after_1:
    // 0x80074268: lui         $a1, 0x3F4C
    ctx->r5 = S32(0X3F4C << 16);
    // 0x8007426C: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    // 0x80074270: lui         $a2, 0x4060
    ctx->r6 = S32(0X4060 << 16);
    // 0x80074274: lw          $t0, 0xC($s2)
    ctx->r8 = MEM_W(ctx->r18, 0XC);
    // 0x80074278: lw          $t1, 0x10($s2)
    ctx->r9 = MEM_W(ctx->r18, 0X10);
    // 0x8007427C: lw          $t2, 0x14($s2)
    ctx->r10 = MEM_W(ctx->r18, 0X14);
    // 0x80074280: sw          $t0, 0x24($s2)
    MEM_W(0X24, ctx->r18) = ctx->r8;
    // 0x80074284: sw          $t1, 0x28($s2)
    MEM_W(0X28, ctx->r18) = ctx->r9;
    // 0x80074288: sw          $t2, 0x2C($s2)
    MEM_W(0X2C, ctx->r18) = ctx->r10;
    // 0x8007428C: jal         0x80072300
    // 0x80074290: addiu       $a0, $s2, 0x24
    ctx->r4 = ADD32(ctx->r18, 0X24);
    func_80072300(rdram, ctx);
        goto after_2;
    // 0x80074290: addiu       $a0, $s2, 0x24
    ctx->r4 = ADD32(ctx->r18, 0X24);
    after_2:
    // 0x80074294: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x80074298: swc1        $f20, 0x64($s2)
    MEM_W(0X64, ctx->r18) = ctx->f20.u32l;
    // 0x8007429C: lhu         $a0, -0x6A8C($v0)
    ctx->r4 = MEM_HU(ctx->r2, -0X6A8C);
    // 0x800742A0: jal         0x8003E684
    // 0x800742A4: addu        $a1, $s3, $zero
    ctx->r5 = ADD32(ctx->r19, 0);
    func_8003E684(rdram, ctx);
        goto after_3;
    // 0x800742A4: addu        $a1, $s3, $zero
    ctx->r5 = ADD32(ctx->r19, 0);
    after_3:
    // 0x800742A8: j           L_800745DC
    // 0x800742AC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_800745DC;
    // 0x800742AC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800742B0:
    // 0x800742B0: lui         $v0, 0x8004
    ctx->r2 = S32(0X8004 << 16);
    // 0x800742B4: addiu       $t3, $v0, -0x2F78
    ctx->r11 = ADD32(ctx->r2, -0X2F78);
    // 0x800742B8: lw          $t0, 0x0($t3)
    ctx->r8 = MEM_W(ctx->r11, 0X0);
    // 0x800742BC: lw          $t1, 0x4($t3)
    ctx->r9 = MEM_W(ctx->r11, 0X4);
    // 0x800742C0: lw          $t2, 0x8($t3)
    ctx->r10 = MEM_W(ctx->r11, 0X8);
    // 0x800742C4: sw          $t0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r8;
    // 0x800742C8: sw          $t1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r9;
    // 0x800742CC: sw          $t2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r10;
    // 0x800742D0: lwc1        $f22, 0x0($s0)
    ctx->f22.u32l = MEM_W(ctx->r16, 0X0);
    // 0x800742D4: lwc1        $f0, 0x24($s2)
    ctx->f0.u32l = MEM_W(ctx->r18, 0X24);
    // 0x800742D8: mul.s       $f0, $f0, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f22.fl);
    // 0x800742DC: lwc1        $f2, 0x28($s2)
    ctx->f2.u32l = MEM_W(ctx->r18, 0X28);
    // 0x800742E0: mul.s       $f2, $f2, $f22
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f22.fl);
    // 0x800742E4: lwc1        $f8, 0x2C($s2)
    ctx->f8.u32l = MEM_W(ctx->r18, 0X2C);
    // 0x800742E8: mul.s       $f8, $f8, $f22
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f8.fl = MUL_S(ctx->f8.fl, ctx->f22.fl);
    // 0x800742EC: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x800742F0: lwc1        $f10, -0x2F68($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X2F68);
    // 0x800742F4: mul.s       $f10, $f22, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = MUL_S(ctx->f22.fl, ctx->f10.fl);
    // 0x800742F8: lwc1        $f4, 0x0($s2)
    ctx->f4.u32l = MEM_W(ctx->r18, 0X0);
    // 0x800742FC: add.s       $f4, $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f0.fl;
    // 0x80074300: lwc1        $f6, 0x4($s2)
    ctx->f6.u32l = MEM_W(ctx->r18, 0X4);
    // 0x80074304: addiu       $s0, $s2, 0xC
    ctx->r16 = ADD32(ctx->r18, 0XC);
    // 0x80074308: add.s       $f6, $f6, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f2.fl;
    // 0x8007430C: lwc1        $f2, 0x8($s2)
    ctx->f2.u32l = MEM_W(ctx->r18, 0X8);
    // 0x80074310: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x80074314: add.s       $f2, $f2, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f8.fl;
    // 0x80074318: lwc1        $f0, 0x28($s2)
    ctx->f0.u32l = MEM_W(ctx->r18, 0X28);
    // 0x8007431C: addiu       $a1, $s2, 0x24
    ctx->r5 = ADD32(ctx->r18, 0X24);
    // 0x80074320: add.s       $f0, $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f10.fl;
    // 0x80074324: swc1        $f4, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->f4.u32l;
    // 0x80074328: swc1        $f6, 0x4($s2)
    MEM_W(0X4, ctx->r18) = ctx->f6.u32l;
    // 0x8007432C: swc1        $f2, 0x8($s2)
    MEM_W(0X8, ctx->r18) = ctx->f2.u32l;
    // 0x80074330: jal         0x8001CFA0
    // 0x80074334: swc1        $f0, 0x28($s2)
    MEM_W(0X28, ctx->r18) = ctx->f0.u32l;
    func_8001CFA0(rdram, ctx);
        goto after_4;
    // 0x80074334: swc1        $f0, 0x28($s2)
    MEM_W(0X28, ctx->r18) = ctx->f0.u32l;
    after_4:
    // 0x80074338: addiu       $s1, $sp, 0x28
    ctx->r17 = ADD32(ctx->r29, 0X28);
    // 0x8007433C: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x80074340: jal         0x8001CFE8
    // 0x80074344: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    func_8001CFE8(rdram, ctx);
        goto after_5;
    // 0x80074344: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    after_5:
    // 0x80074348: jal         0x8001C5CC
    // 0x8007434C: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    func_8001C5CC(rdram, ctx);
        goto after_6;
    // 0x8007434C: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    after_6:
    // 0x80074350: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x80074354: lw          $v0, -0x72E4($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X72E4);
    // 0x80074358: lwc1        $f2, 0x0($s2)
    ctx->f2.u32l = MEM_W(ctx->r18, 0X0);
    // 0x8007435C: addiu       $v0, $v0, 0x28
    ctx->r2 = ADD32(ctx->r2, 0X28);
    // 0x80074360: lwc1        $f4, 0x24($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X24);
    // 0x80074364: sub.s       $f2, $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = ctx->f2.fl - ctx->f4.fl;
    // 0x80074368: swc1        $f2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f2.u32l;
    // 0x8007436C: lwc1        $f2, 0x4($s2)
    ctx->f2.u32l = MEM_W(ctx->r18, 0X4);
    // 0x80074370: lwc1        $f4, 0x28($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X28);
    // 0x80074374: sub.s       $f2, $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = ctx->f2.fl - ctx->f4.fl;
    // 0x80074378: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    // 0x8007437C: swc1        $f2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f2.u32l;
    // 0x80074380: lwc1        $f2, 0x8($s2)
    ctx->f2.u32l = MEM_W(ctx->r18, 0X8);
    // 0x80074384: lwc1        $f4, 0x2C($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X2C);
    // 0x80074388: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    // 0x8007438C: sub.s       $f2, $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = ctx->f2.fl - ctx->f4.fl;
    // 0x80074390: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80074394: lwc1        $f4, -0x2F64($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X2F64);
    // 0x80074398: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    // 0x8007439C: mul.s       $f20, $f0, $f4
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f20.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x800743A0: jal         0x80019548
    // 0x800743A4: swc1        $f2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f2.u32l;
    func_80019548(rdram, ctx);
        goto after_7;
    // 0x800743A4: swc1        $f2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f2.u32l;
    after_7:
    // 0x800743A8: lwc1        $f2, 0x1C($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x800743AC: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800743B0: c.le.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl <= ctx->f2.fl;
    // 0x800743B4: nop

    // 0x800743B8: bc1f        L_800743D4
    if (!c1cs) {
        // 0x800743BC: nop
    
            goto L_800743D4;
    }
    // 0x800743BC: nop

    // 0x800743C0: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x800743C4: lwc1        $f2, -0x2F60($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X2F60);
    // 0x800743C8: neg.s       $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = -ctx->f20.fl;
    // 0x800743CC: j           L_800743E0
    // 0x800743D0: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
        goto L_800743E0;
    // 0x800743D0: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
L_800743D4:
    // 0x800743D4: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x800743D8: lwc1        $f0, -0x2F5C($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X2F5C);
    // 0x800743DC: add.s       $f0, $f20, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f20.fl + ctx->f0.fl;
L_800743E0:
    // 0x800743E0: swc1        $f0, 0x4C($s2)
    MEM_W(0X4C, ctx->r18) = ctx->f0.u32l;
    // 0x800743E4: lwc1        $f2, 0x28($s2)
    ctx->f2.u32l = MEM_W(ctx->r18, 0X28);
    // 0x800743E8: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800743EC: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x800743F0: nop

    // 0x800743F4: bc1f        L_80074430
    if (!c1cs) {
        // 0x800743F8: lui         $a2, 0x8014
        ctx->r6 = S32(0X8014 << 16);
            goto L_80074430;
    }
    // 0x800743F8: lui         $a2, 0x8014
    ctx->r6 = S32(0X8014 << 16);
    // 0x800743FC: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80074400: lwc1        $f0, -0x2F58($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X2F58);
    // 0x80074404: mul.s       $f0, $f22, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = MUL_S(ctx->f22.fl, ctx->f0.fl);
    // 0x80074408: lwc1        $f2, 0x68($s2)
    ctx->f2.u32l = MEM_W(ctx->r18, 0X68);
    // 0x8007440C: add.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x80074410: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80074414: lwc1        $f0, -0x2F54($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X2F54);
    // 0x80074418: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x8007441C: nop

    // 0x80074420: bc1f        L_80074430
    if (!c1cs) {
        // 0x80074424: swc1        $f2, 0x68($s2)
        MEM_W(0X68, ctx->r18) = ctx->f2.u32l;
            goto L_80074430;
    }
    // 0x80074424: swc1        $f2, 0x68($s2)
    MEM_W(0X68, ctx->r18) = ctx->f2.u32l;
    // 0x80074428: swc1        $f0, 0x68($s2)
    MEM_W(0X68, ctx->r18) = ctx->f0.u32l;
    // 0x8007442C: lui         $a2, 0x8014
    ctx->r6 = S32(0X8014 << 16);
L_80074430:
    // 0x80074430: addiu       $a2, $a2, -0x7FA8
    ctx->r6 = ADD32(ctx->r6, -0X7FA8);
    // 0x80074434: lwc1        $f12, 0x0($s2)
    ctx->f12.u32l = MEM_W(ctx->r18, 0X0);
    // 0x80074438: lwc1        $f14, 0x8($s2)
    ctx->f14.u32l = MEM_W(ctx->r18, 0X8);
    // 0x8007443C: jal         0x80067D90
    // 0x80074440: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    func_80067D90(rdram, ctx);
        goto after_8;
    // 0x80074440: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    after_8:
    // 0x80074444: lwc1        $f2, 0x4($s2)
    ctx->f2.u32l = MEM_W(ctx->r18, 0X4);
    // 0x80074448: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x8007444C: c.lt.s      $f20, $f2
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f20.fl < ctx->f2.fl;
    // 0x80074450: nop

    // 0x80074454: bc1f        L_800745D8
    if (!c1cs) {
        // 0x80074458: addiu       $a1, $sp, 0x38
        ctx->r5 = ADD32(ctx->r29, 0X38);
            goto L_800745D8;
    }
    // 0x80074458: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    // 0x8007445C: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x80074460: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80074464: lwc1        $f4, -0x2F50($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X2F50);
    // 0x80074468: lwc1        $f0, 0x0($s2)
    ctx->f0.u32l = MEM_W(ctx->r18, 0X0);
    // 0x8007446C: lbu         $v0, -0x56BC($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X56BC);
    // 0x80074470: sub.s       $f2, $f20, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = ctx->f20.fl - ctx->f4.fl;
    // 0x80074474: addiu       $v1, $sp, 0x28
    ctx->r3 = ADD32(ctx->r29, 0X28);
    // 0x80074478: swc1        $f0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f0.u32l;
    // 0x8007447C: swc1        $f2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f2.u32l;
    // 0x80074480: lwc1        $f0, 0x8($s2)
    ctx->f0.u32l = MEM_W(ctx->r18, 0X8);
    // 0x80074484: swc1        $f0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f0.u32l;
    // 0x80074488: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8007448C: lwc1        $f0, -0x2F4C($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X2F4C);
    // 0x80074490: beq         $v0, $zero, L_800744FC
    if (ctx->r2 == 0) {
        // 0x80074494: addiu       $s0, $s2, 0x60
        ctx->r16 = ADD32(ctx->r18, 0X60);
            goto L_800744FC;
    }
    // 0x80074494: addiu       $s0, $s2, 0x60
    ctx->r16 = ADD32(ctx->r18, 0X60);
    // 0x80074498: lui         $a0, 0x8007
    ctx->r4 = S32(0X8007 << 16);
    // 0x8007449C: addiu       $a0, $a0, 0x2EC4
    ctx->r4 = ADD32(ctx->r4, 0X2EC4);
    // 0x800744A0: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x800744A4: lwc1        $f2, -0x2F48($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X2F48);
    // 0x800744A8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x800744AC: swc1        $f4, 0x24($a1)
    MEM_W(0X24, ctx->r5) = ctx->f4.u32l;
    // 0x800744B0: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x800744B4: lwc1        $f4, -0x2F44($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X2F44);
    // 0x800744B8: addiu       $a3, $zero, 0xF
    ctx->r7 = ADD32(0, 0XF);
    // 0x800744BC: swc1        $f0, 0x20($a1)
    MEM_W(0X20, ctx->r5) = ctx->f0.u32l;
    // 0x800744C0: swc1        $f0, 0x28($a1)
    MEM_W(0X28, ctx->r5) = ctx->f0.u32l;
    // 0x800744C4: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x800744C8: lwc1        $f0, -0x2F40($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X2F40);
    // 0x800744CC: ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
    // 0x800744D0: sh          $v0, 0x1C($a1)
    MEM_H(0X1C, ctx->r5) = ctx->r2;
    // 0x800744D4: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x800744D8: sh          $v0, 0x1E($a1)
    MEM_H(0X1E, ctx->r5) = ctx->r2;
    // 0x800744DC: addiu       $v0, $sp, 0x58
    ctx->r2 = ADD32(ctx->r29, 0X58);
    // 0x800744E0: sw          $v1, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r3;
    // 0x800744E4: sw          $v0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r2;
    // 0x800744E8: swc1        $f0, 0x18($a1)
    MEM_W(0X18, ctx->r5) = ctx->f0.u32l;
    // 0x800744EC: swc1        $f2, 0x10($a1)
    MEM_W(0X10, ctx->r5) = ctx->f2.u32l;
    // 0x800744F0: swc1        $f4, 0xC($a1)
    MEM_W(0XC, ctx->r5) = ctx->f4.u32l;
    // 0x800744F4: jal         0x8003FFEC
    // 0x800744F8: sw          $s0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r16;
    func_8003FFEC(rdram, ctx);
        goto after_9;
    // 0x800744F8: sw          $s0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r16;
    after_9:
L_800744FC:
    // 0x800744FC: lhu         $a0, 0x16($s3)
    ctx->r4 = MEM_HU(ctx->r19, 0X16);
    // 0x80074500: jal         0x8003ED74
    // 0x80074504: nop

    func_8003ED74(rdram, ctx);
        goto after_10;
    // 0x80074504: nop

    after_10:
    // 0x80074508: j           L_800745DC
    // 0x8007450C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_800745DC;
    // 0x8007450C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80074510:
    // 0x80074510: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x80074514: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80074518: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x8007451C: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x80074520: jal         0x8001DC34
    // 0x80074524: addu        $a2, $s2, $zero
    ctx->r6 = ADD32(ctx->r18, 0);
    func_8001DC34(rdram, ctx);
        goto after_11;
    // 0x80074524: addu        $a2, $s2, $zero
    ctx->r6 = ADD32(ctx->r18, 0);
    after_11:
    // 0x80074528: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x8007452C: beq         $v0, $zero, L_800745D8
    if (ctx->r2 == 0) {
        // 0x80074530: lui         $v1, 0x8013
        ctx->r3 = S32(0X8013 << 16);
            goto L_800745D8;
    }
    // 0x80074530: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x80074534: lwc1        $f0, 0x68($s2)
    ctx->f0.u32l = MEM_W(ctx->r18, 0X68);
    // 0x80074538: lw          $v1, 0xC08($v1)
    ctx->r3 = MEM_W(ctx->r3, 0XC08);
    // 0x8007453C: trunc.w.s   $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    ctx->f16.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x80074540: mfc1        $v0, $f16
    ctx->r2 = (int32_t)ctx->f16.u32l;
    // 0x80074544: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x80074548: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8007454C: lhu         $v0, 0xC($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0XC);
    // 0x80074550: lwc1        $f0, 0x0($s2)
    ctx->f0.u32l = MEM_W(ctx->r18, 0X0);
    // 0x80074554: sh          $v0, 0x42($s2)
    MEM_H(0X42, ctx->r18) = ctx->r2;
    // 0x80074558: lwc1        $f2, 0x18($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X18);
    // 0x8007455C: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x80074560: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80074564: lwc1        $f4, -0x2F3C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X2F3C);
    // 0x80074568: mul.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x8007456C: trunc.w.s   $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    ctx->f16.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x80074570: mfc1        $v0, $f16
    ctx->r2 = (int32_t)ctx->f16.u32l;
    // 0x80074574: lwc1        $f0, 0x4($s2)
    ctx->f0.u32l = MEM_W(ctx->r18, 0X4);
    // 0x80074578: sh          $v0, 0x38($s2)
    MEM_H(0X38, ctx->r18) = ctx->r2;
    // 0x8007457C: lwc1        $f2, 0x1C($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X1C);
    // 0x80074580: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x80074584: mul.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x80074588: trunc.w.s   $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    ctx->f16.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x8007458C: mfc1        $v0, $f16
    ctx->r2 = (int32_t)ctx->f16.u32l;
    // 0x80074590: lwc1        $f0, 0x8($s2)
    ctx->f0.u32l = MEM_W(ctx->r18, 0X8);
    // 0x80074594: sh          $v0, 0x3A($s2)
    MEM_H(0X3A, ctx->r18) = ctx->r2;
    // 0x80074598: lwc1        $f2, 0x20($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X20);
    // 0x8007459C: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x800745A0: mul.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x800745A4: trunc.w.s   $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    ctx->f16.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800745A8: mfc1        $v0, $f16
    ctx->r2 = (int32_t)ctx->f16.u32l;
    // 0x800745AC: sh          $v0, 0x3C($s2)
    MEM_H(0X3C, ctx->r18) = ctx->r2;
    // 0x800745B0: lw          $v0, 0x48($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X48);
    // 0x800745B4: lw          $v1, 0x20($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X20);
    // 0x800745B8: beq         $v1, $zero, L_800745C8
    if (ctx->r3 == 0) {
        // 0x800745BC: sw          $v1, 0x30($s2)
        MEM_W(0X30, ctx->r18) = ctx->r3;
            goto L_800745C8;
    }
    // 0x800745BC: sw          $v1, 0x30($s2)
    MEM_W(0X30, ctx->r18) = ctx->r3;
    // 0x800745C0: addiu       $v0, $s2, 0x30
    ctx->r2 = ADD32(ctx->r18, 0X30);
    // 0x800745C4: sw          $v0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r2;
L_800745C8:
    // 0x800745C8: sw          $zero, 0x34($s2)
    MEM_W(0X34, ctx->r18) = 0;
    // 0x800745CC: lw          $v1, 0x48($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X48);
    // 0x800745D0: addiu       $v0, $s2, 0x30
    ctx->r2 = ADD32(ctx->r18, 0X30);
    // 0x800745D4: sw          $v0, 0x20($v1)
    MEM_W(0X20, ctx->r3) = ctx->r2;
L_800745D8:
    // 0x800745D8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800745DC:
    // 0x800745DC: lw          $ra, 0x78($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X78);
    // 0x800745E0: lw          $s3, 0x74($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X74);
    // 0x800745E4: lw          $s2, 0x70($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X70);
    // 0x800745E8: lw          $s1, 0x6C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X6C);
    // 0x800745EC: lw          $s0, 0x68($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X68);
    // 0x800745F0: ldc1        $f22, 0x88($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X88);
    // 0x800745F4: ldc1        $f20, 0x80($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X80);
    // 0x800745F8: jr          $ra
    // 0x800745FC: addiu       $sp, $sp, 0x90
    ctx->r29 = ADD32(ctx->r29, 0X90);
    return;
    // 0x800745FC: addiu       $sp, $sp, 0x90
    ctx->r29 = ADD32(ctx->r29, 0X90);
;}
RECOMP_FUNC void func_80074600(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80074600: addiu       $sp, $sp, -0xA0
    ctx->r29 = ADD32(ctx->r29, -0XA0);
    // 0x80074604: sw          $s0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r16;
    // 0x80074608: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x8007460C: lui         $v0, 0x8004
    ctx->r2 = S32(0X8004 << 16);
    // 0x80074610: sw          $ra, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r31;
    // 0x80074614: sw          $s2, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r18;
    // 0x80074618: sw          $s1, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r17;
    // 0x8007461C: sdc1        $f28, 0x98($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0X98, ctx->r29);
    // 0x80074620: sdc1        $f26, 0x90($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X90, ctx->r29);
    // 0x80074624: sdc1        $f24, 0x88($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X88, ctx->r29);
    // 0x80074628: sdc1        $f22, 0x80($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X80, ctx->r29);
    // 0x8007462C: sdc1        $f20, 0x78($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X78, ctx->r29);
    // 0x80074630: addiu       $t3, $v0, -0x2F38
    ctx->r11 = ADD32(ctx->r2, -0X2F38);
    // 0x80074634: lwl         $t0, 0x0($t3)
    ctx->r8 = do_lwl(rdram, ctx->r8, ctx->r11, 0X0);
    // 0x80074638: lwr         $t0, 0x3($t3)
    ctx->r8 = do_lwr(rdram, ctx->r8, ctx->r11, 0X3);
    // 0x8007463C: swl         $t0, 0x38($sp)
    do_swl(rdram, 0X38, ctx->r29, ctx->r8);
    // 0x80074640: swr         $t0, 0x3B($sp)
    do_swr(rdram, 0X3B, ctx->r29, ctx->r8);
    // 0x80074644: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x80074648: lw          $v1, -0x72E4($v0)
    ctx->r3 = MEM_W(ctx->r2, -0X72E4);
    // 0x8007464C: lui         $v0, 0x8004
    ctx->r2 = S32(0X8004 << 16);
    // 0x80074650: addiu       $t3, $v0, -0x2F34
    ctx->r11 = ADD32(ctx->r2, -0X2F34);
    // 0x80074654: lwl         $t0, 0x0($t3)
    ctx->r8 = do_lwl(rdram, ctx->r8, ctx->r11, 0X0);
    // 0x80074658: lwr         $t0, 0x3($t3)
    ctx->r8 = do_lwr(rdram, ctx->r8, ctx->r11, 0X3);
    // 0x8007465C: swl         $t0, 0x40($sp)
    do_swl(rdram, 0X40, ctx->r29, ctx->r8);
    // 0x80074660: swr         $t0, 0x43($sp)
    do_swr(rdram, 0X43, ctx->r29, ctx->r8);
    // 0x80074664: lwc1        $f0, 0x0($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X0);
    // 0x80074668: addiu       $v1, $v1, 0x28
    ctx->r3 = ADD32(ctx->r3, 0X28);
    // 0x8007466C: lwc1        $f2, 0x24($v1)
    ctx->f2.u32l = MEM_W(ctx->r3, 0X24);
    // 0x80074670: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x80074674: swc1        $f0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f0.u32l;
    // 0x80074678: lwc1        $f0, 0x4($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X4);
    // 0x8007467C: lwc1        $f2, 0x28($v1)
    ctx->f2.u32l = MEM_W(ctx->r3, 0X28);
    // 0x80074680: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x80074684: swc1        $f0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f0.u32l;
    // 0x80074688: lwc1        $f0, 0x8($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8007468C: lwc1        $f2, 0x2C($v1)
    ctx->f2.u32l = MEM_W(ctx->r3, 0X2C);
    // 0x80074690: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x80074694: mtc1        $a1, $f20
    ctx->f20.u32l = ctx->r5;
    // 0x80074698: addiu       $a0, $sp, 0x58
    ctx->r4 = ADD32(ctx->r29, 0X58);
    // 0x8007469C: jal         0x8001CF2C
    // 0x800746A0: swc1        $f0, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f0.u32l;
    func_8001CF2C(rdram, ctx);
        goto after_0;
    // 0x800746A0: swc1        $f0, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f0.u32l;
    after_0:
    // 0x800746A4: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x800746A8: lwc1        $f2, -0x2F30($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X2F30);
    // 0x800746AC: div.s       $f2, $f0, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = DIV_S(ctx->f0.fl, ctx->f2.fl);
    // 0x800746B0: mul.s       $f20, $f20, $f2
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f20.fl = MUL_S(ctx->f20.fl, ctx->f2.fl);
    // 0x800746B4: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800746B8: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x800746BC: nop

    // 0x800746C0: bc1f        L_800746E4
    if (!c1cs) {
        // 0x800746C4: addiu       $s1, $zero, 0x1
        ctx->r17 = ADD32(0, 0X1);
            goto L_800746E4;
    }
    // 0x800746C4: addiu       $s1, $zero, 0x1
    ctx->r17 = ADD32(0, 0X1);
    // 0x800746C8: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x800746CC: lwc1        $f0, -0x2F2C($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X2F2C);
    // 0x800746D0: div.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f2.fl);
    // 0x800746D4: trunc.w.s   $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    ctx->f6.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800746D8: mfc1        $s1, $f6
    ctx->r17 = (int32_t)ctx->f6.u32l;
    // 0x800746DC: j           L_800746E8
    // 0x800746E0: slti        $v0, $s1, 0x8
    ctx->r2 = SIGNED(ctx->r17) < 0X8 ? 1 : 0;
        goto L_800746E8;
    // 0x800746E0: slti        $v0, $s1, 0x8
    ctx->r2 = SIGNED(ctx->r17) < 0X8 ? 1 : 0;
L_800746E4:
    // 0x800746E4: slti        $v0, $s1, 0x8
    ctx->r2 = SIGNED(ctx->r17) < 0X8 ? 1 : 0;
L_800746E8:
    // 0x800746E8: beql        $v0, $zero, L_800746F0
    if (ctx->r2 == 0) {
        // 0x800746EC: addiu       $s1, $zero, 0x7
        ctx->r17 = ADD32(0, 0X7);
            goto L_800746F0;
    }
    goto skip_0;
    // 0x800746EC: addiu       $s1, $zero, 0x7
    ctx->r17 = ADD32(0, 0X7);
    skip_0:
L_800746F0:
    // 0x800746F0: lui         $a2, 0x8014
    ctx->r6 = S32(0X8014 << 16);
    // 0x800746F4: addiu       $a2, $a2, -0x7FA8
    ctx->r6 = ADD32(ctx->r6, -0X7FA8);
    // 0x800746F8: lwc1        $f12, 0x0($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X0);
    // 0x800746FC: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    // 0x80074700: swc1        $f12, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f12.u32l;
    // 0x80074704: lwc1        $f14, 0x8($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X8);
    // 0x80074708: addu        $s0, $a3, $zero
    ctx->r16 = ADD32(ctx->r7, 0);
    // 0x8007470C: jal         0x80067D90
    // 0x80074710: swc1        $f14, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f14.u32l;
    func_80067D90(rdram, ctx);
        goto after_1;
    // 0x80074710: swc1        $f14, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f14.u32l;
    after_1:
    // 0x80074714: addiu       $v0, $sp, 0x48
    ctx->r2 = ADD32(ctx->r29, 0X48);
    // 0x80074718: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x8007471C: ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
    // 0x80074720: sh          $v0, 0x30($sp)
    MEM_H(0X30, ctx->r29) = ctx->r2;
    // 0x80074724: addiu       $v0, $sp, 0x38
    ctx->r2 = ADD32(ctx->r29, 0X38);
    // 0x80074728: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x8007472C: addiu       $v0, $sp, 0x40
    ctx->r2 = ADD32(ctx->r29, 0X40);
    // 0x80074730: swc1        $f0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f0.u32l;
    // 0x80074734: blez        $s1, L_800747B4
    if (SIGNED(ctx->r17) <= 0) {
        // 0x80074738: sw          $v0, 0x28($sp)
        MEM_W(0X28, ctx->r29) = ctx->r2;
            goto L_800747B4;
    }
    // 0x80074738: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    // 0x8007473C: lui         $s2, 0x8007
    ctx->r18 = S32(0X8007 << 16);
    // 0x80074740: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80074744: lwc1        $f28, -0x2F28($at)
    ctx->f28.u32l = MEM_W(ctx->r1, -0X2F28);
    // 0x80074748: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8007474C: lwc1        $f26, -0x2F24($at)
    ctx->f26.u32l = MEM_W(ctx->r1, -0X2F24);
    // 0x80074750: mtc1        $zero, $f24
    ctx->f24.u32l = 0;
    // 0x80074754: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80074758: lwc1        $f22, -0x2F20($at)
    ctx->f22.u32l = MEM_W(ctx->r1, -0X2F20);
L_8007475C:
    // 0x8007475C: jal         0x80003430
    // 0x80074760: nop

    rand_recomp(rdram, ctx);
        goto after_2;
    // 0x80074760: nop

    after_2:
    // 0x80074764: andi        $v0, $v0, 0x7F
    ctx->r2 = ctx->r2 & 0X7F;
    // 0x80074768: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x8007476C: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x80074770: sub.s       $f0, $f0, $f28
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f28.fl;
    // 0x80074774: div.s       $f0, $f0, $f26
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f26.fl);
    // 0x80074778: add.s       $f0, $f20, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f20.fl + ctx->f0.fl;
    // 0x8007477C: c.le.s      $f0, $f24
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 24);
    c1cs = ctx->f0.fl <= ctx->f24.fl;
    // 0x80074780: nop

    // 0x80074784: bc1f        L_80074790
    if (!c1cs) {
        // 0x80074788: swc1        $f0, 0x2C($sp)
        MEM_W(0X2C, ctx->r29) = ctx->f0.u32l;
            goto L_80074790;
    }
    // 0x80074788: swc1        $f0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f0.u32l;
    // 0x8007478C: swc1        $f22, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f22.u32l;
L_80074790:
    // 0x80074790: addiu       $a0, $s2, 0x413C
    ctx->r4 = ADD32(ctx->r18, 0X413C);
    // 0x80074794: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    // 0x80074798: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8007479C: jal         0x8003FFEC
    // 0x800747A0: addiu       $a3, $zero, 0xA
    ctx->r7 = ADD32(0, 0XA);
    func_8003FFEC(rdram, ctx);
        goto after_3;
    // 0x800747A0: addiu       $a3, $zero, 0xA
    ctx->r7 = ADD32(0, 0XA);
    after_3:
    // 0x800747A4: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x800747A8: slt         $v0, $s0, $s1
    ctx->r2 = SIGNED(ctx->r16) < SIGNED(ctx->r17) ? 1 : 0;
    // 0x800747AC: bne         $v0, $zero, L_8007475C
    if (ctx->r2 != 0) {
        // 0x800747B0: nop
    
            goto L_8007475C;
    }
    // 0x800747B0: nop

L_800747B4:
    // 0x800747B4: ori         $a0, $zero, 0x8002
    ctx->r4 = 0 | 0X8002;
    // 0x800747B8: addiu       $s0, $sp, 0x48
    ctx->r16 = ADD32(ctx->r29, 0X48);
    // 0x800747BC: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x800747C0: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // 0x800747C4: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x800747C8: lwc1        $f0, -0x2F1C($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X2F1C);
    // 0x800747CC: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x800747D0: lwc1        $f2, -0x2F18($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X2F18);
    // 0x800747D4: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x800747D8: lwc1        $f20, -0x2F14($at)
    ctx->f20.u32l = MEM_W(ctx->r1, -0X2F14);
    // 0x800747DC: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x800747E0: lwc1        $f4, -0x2F10($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X2F10);
    // 0x800747E4: addiu       $a3, $sp, 0x38
    ctx->r7 = ADD32(ctx->r29, 0X38);
    // 0x800747E8: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    // 0x800747EC: swc1        $f2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f2.u32l;
    // 0x800747F0: swc1        $f20, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f20.u32l;
    // 0x800747F4: jal         0x80072684
    // 0x800747F8: swc1        $f4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f4.u32l;
    func_80072684(rdram, ctx);
        goto after_4;
    // 0x800747F8: swc1        $f4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f4.u32l;
    after_4:
    // 0x800747FC: lui         $a1, 0x3DCC
    ctx->r5 = S32(0X3DCC << 16);
    // 0x80074800: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    // 0x80074804: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x80074808: jal         0x80073E4C
    // 0x8007480C: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_80073E4C(rdram, ctx);
        goto after_5;
    // 0x8007480C: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_5:
    // 0x80074810: lw          $ra, 0x74($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X74);
    // 0x80074814: lw          $s2, 0x70($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X70);
    // 0x80074818: lw          $s1, 0x6C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X6C);
    // 0x8007481C: lw          $s0, 0x68($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X68);
    // 0x80074820: ldc1        $f28, 0x98($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0X98);
    // 0x80074824: ldc1        $f26, 0x90($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X90);
    // 0x80074828: ldc1        $f24, 0x88($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X88);
    // 0x8007482C: ldc1        $f22, 0x80($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X80);
    // 0x80074830: ldc1        $f20, 0x78($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X78);
    // 0x80074834: jr          $ra
    // 0x80074838: addiu       $sp, $sp, 0xA0
    ctx->r29 = ADD32(ctx->r29, 0XA0);
    return;
    // 0x80074838: addiu       $sp, $sp, 0xA0
    ctx->r29 = ADD32(ctx->r29, 0XA0);
;}
RECOMP_FUNC void func_8007483C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007483C: addiu       $sp, $sp, -0x80
    ctx->r29 = ADD32(ctx->r29, -0X80);
    // 0x80074840: sw          $s2, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r18;
    // 0x80074844: addu        $s2, $a0, $zero
    ctx->r18 = ADD32(ctx->r4, 0);
    // 0x80074848: sw          $s4, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r20;
    // 0x8007484C: addu        $s4, $a1, $zero
    ctx->r20 = ADD32(ctx->r5, 0);
    // 0x80074850: sw          $s3, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r19;
    // 0x80074854: addu        $s3, $a2, $zero
    ctx->r19 = ADD32(ctx->r6, 0);
    // 0x80074858: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x8007485C: sw          $s1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r17;
    // 0x80074860: addiu       $s1, $v0, -0x7FA8
    ctx->r17 = ADD32(ctx->r2, -0X7FA8);
    // 0x80074864: sw          $ra, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r31;
    // 0x80074868: sw          $s0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r16;
    // 0x8007486C: sdc1        $f22, 0x78($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X78, ctx->r29);
    // 0x80074870: sdc1        $f20, 0x70($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X70, ctx->r29);
    // 0x80074874: lwc1        $f12, 0x0($s2)
    ctx->f12.u32l = MEM_W(ctx->r18, 0X0);
    // 0x80074878: lwc1        $f14, 0x8($s2)
    ctx->f14.u32l = MEM_W(ctx->r18, 0X8);
    // 0x8007487C: jal         0x800698F4
    // 0x80074880: addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    func_800698F4(rdram, ctx);
        goto after_0;
    // 0x80074880: addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    after_0:
    // 0x80074884: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    // 0x80074888: bne         $s0, $zero, L_80074A24
    if (ctx->r16 != 0) {
        // 0x8007488C: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80074A24;
    }
    // 0x8007488C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80074890: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // 0x80074894: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80074898: lwc1        $f20, -0x2F0C($at)
    ctx->f20.u32l = MEM_W(ctx->r1, -0X2F0C);
    // 0x8007489C: lui         $a2, 0x8014
    ctx->r6 = S32(0X8014 << 16);
    // 0x800748A0: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x800748A4: jal         0x80061380
    // 0x800748A8: addiu       $a2, $a2, -0x66E0
    ctx->r6 = ADD32(ctx->r6, -0X66E0);
    func_80061380(rdram, ctx);
        goto after_1;
    // 0x800748A8: addiu       $a2, $a2, -0x66E0
    ctx->r6 = ADD32(ctx->r6, -0X66E0);
    after_1:
    // 0x800748AC: jal         0x8006C994
    // 0x800748B0: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    func_8006C994(rdram, ctx);
        goto after_2;
    // 0x800748B0: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    after_2:
    // 0x800748B4: andi        $v1, $s3, 0xFFFF
    ctx->r3 = ctx->r19 & 0XFFFF;
    // 0x800748B8: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x800748BC: bne         $v1, $v0, L_80074B4C
    if (ctx->r3 != ctx->r2) {
        // 0x800748C0: addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
            goto L_80074B4C;
    }
    // 0x800748C0: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // 0x800748C4: lui         $v1, 0x8014
    ctx->r3 = S32(0X8014 << 16);
    // 0x800748C8: lwc1        $f0, -0x5750($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, -0X5750);
    // 0x800748CC: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x800748D0: lwc1        $f22, -0x2F08($at)
    ctx->f22.u32l = MEM_W(ctx->r1, -0X2F08);
    // 0x800748D4: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800748D8: add.s       $f0, $f0, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f22.fl;
    // 0x800748DC: lwc1        $f2, 0xBA4($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0XBA4);
    // 0x800748E0: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x800748E4: nop

    // 0x800748E8: bc1f        L_80074914
    if (!c1cs) {
        // 0x800748EC: addiu       $v0, $zero, 0xC
        ctx->r2 = ADD32(0, 0XC);
            goto L_80074914;
    }
    // 0x800748EC: addiu       $v0, $zero, 0xC
    ctx->r2 = ADD32(0, 0XC);
    // 0x800748F0: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // 0x800748F4: lwc1        $f12, 0x0($s2)
    ctx->f12.u32l = MEM_W(ctx->r18, 0X0);
    // 0x800748F8: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x800748FC: lwc1        $f0, -0x2F04($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X2F04);
    // 0x80074900: lwc1        $f14, 0x8($s2)
    ctx->f14.u32l = MEM_W(ctx->r18, 0X8);
    // 0x80074904: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80074908: swc1        $f2, -0x5750($v1)
    MEM_W(-0X5750, ctx->r3) = ctx->f2.u32l;
    // 0x8007490C: jal         0x8006C738
    // 0x80074910: addu        $a3, $a2, $zero
    ctx->r7 = ADD32(ctx->r6, 0);
    func_8006C738(rdram, ctx);
        goto after_3;
    // 0x80074910: addu        $a3, $a2, $zero
    ctx->r7 = ADD32(ctx->r6, 0);
    after_3:
L_80074914:
    // 0x80074914: jal         0x80003430
    // 0x80074918: nop

    rand_recomp(rdram, ctx);
        goto after_4;
    // 0x80074918: nop

    after_4:
    // 0x8007491C: lui         $v1, 0x51EB
    ctx->r3 = S32(0X51EB << 16);
    // 0x80074920: ori         $v1, $v1, 0x851F
    ctx->r3 = ctx->r3 | 0X851F;
    // 0x80074924: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x80074928: sra         $a0, $v0, 16
    ctx->r4 = S32(SIGNED(ctx->r2) >> 16);
    // 0x8007492C: mult        $a0, $v1
    result = S64(S32(ctx->r4)) * S64(S32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80074930: sra         $v0, $v0, 31
    ctx->r2 = S32(SIGNED(ctx->r2) >> 31);
    // 0x80074934: mfhi        $t0
    ctx->r8 = hi;
    // 0x80074938: sra         $v1, $t0, 5
    ctx->r3 = S32(SIGNED(ctx->r8) >> 5);
    // 0x8007493C: subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // 0x80074940: sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3 << 1);
    // 0x80074944: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80074948: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x8007494C: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80074950: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80074954: subu        $a0, $a0, $v0
    ctx->r4 = SUB32(ctx->r4, ctx->r2);
    // 0x80074958: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x8007495C: sra         $s0, $a0, 16
    ctx->r16 = S32(SIGNED(ctx->r4) >> 16);
    // 0x80074960: slti        $v0, $s0, 0x2
    ctx->r2 = SIGNED(ctx->r16) < 0X2 ? 1 : 0;
    // 0x80074964: beq         $v0, $zero, L_800749A4
    if (ctx->r2 == 0) {
        // 0x80074968: addu        $a0, $s2, $zero
        ctx->r4 = ADD32(ctx->r18, 0);
            goto L_800749A4;
    }
    // 0x80074968: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // 0x8007496C: lui         $a2, 0x41A0
    ctx->r6 = S32(0X41A0 << 16);
    // 0x80074970: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x80074974: lwc1        $f0, 0x0($s4)
    ctx->f0.u32l = MEM_W(ctx->r20, 0X0);
    // 0x80074978: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8007497C: lwc1        $f2, -0x2F00($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X2F00);
    // 0x80074980: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    // 0x80074984: swc1        $f2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f2.u32l;
    // 0x80074988: lwc1        $f0, 0x8($s4)
    ctx->f0.u32l = MEM_W(ctx->r20, 0X8);
    // 0x8007498C: addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    // 0x80074990: swc1        $f0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f0.u32l;
    // 0x80074994: jal         0x80072384
    // 0x80074998: swc1        $f22, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f22.u32l;
    func_80072384(rdram, ctx);
        goto after_5;
    // 0x80074998: swc1        $f22, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f22.u32l;
    after_5:
    // 0x8007499C: j           L_800749D4
    // 0x800749A0: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
        goto L_800749D4;
    // 0x800749A0: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
L_800749A4:
    // 0x800749A4: slti        $v0, $s0, 0xA
    ctx->r2 = SIGNED(ctx->r16) < 0XA ? 1 : 0;
    // 0x800749A8: beq         $v0, $zero, L_800749D0
    if (ctx->r2 == 0) {
        // 0x800749AC: ori         $a1, $zero, 0xFFFF
        ctx->r5 = 0 | 0XFFFF;
            goto L_800749D0;
    }
    // 0x800749AC: ori         $a1, $zero, 0xFFFF
    ctx->r5 = 0 | 0XFFFF;
    // 0x800749B0: lui         $a2, 0x3F99
    ctx->r6 = S32(0X3F99 << 16);
    // 0x800749B4: ori         $a2, $a2, 0x999A
    ctx->r6 = ctx->r6 | 0X999A;
    // 0x800749B8: lui         $a3, 0x3E80
    ctx->r7 = S32(0X3E80 << 16);
    // 0x800749BC: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x800749C0: lwc1        $f0, -0x2EFC($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X2EFC);
    // 0x800749C4: swc1        $f20, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f20.u32l;
    // 0x800749C8: jal         0x80073750
    // 0x800749CC: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    func_80073750(rdram, ctx);
        goto after_6;
    // 0x800749CC: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    after_6:
L_800749D0:
    // 0x800749D0: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
L_800749D4:
    // 0x800749D4: lw          $v1, 0xB70($v0)
    ctx->r3 = MEM_W(ctx->r2, 0XB70);
    // 0x800749D8: addiu       $v0, $zero, 0xD
    ctx->r2 = ADD32(0, 0XD);
    // 0x800749DC: bne         $v1, $v0, L_80074B4C
    if (ctx->r3 != ctx->r2) {
        // 0x800749E0: addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
            goto L_80074B4C;
    }
    // 0x800749E0: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // 0x800749E4: lwc1        $f2, 0x4($s2)
    ctx->f2.u32l = MEM_W(ctx->r18, 0X4);
    // 0x800749E8: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x800749EC: lwc1        $f0, -0x2EF8($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X2EF8);
    // 0x800749F0: c.le.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl <= ctx->f2.fl;
    // 0x800749F4: nop

    // 0x800749F8: bc1f        L_80074B4C
    if (!c1cs) {
        // 0x800749FC: nop
    
            goto L_80074B4C;
    }
    // 0x800749FC: nop

    // 0x80074A00: lui         $a1, 0x3DCC
    ctx->r5 = S32(0X3DCC << 16);
    // 0x80074A04: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    // 0x80074A08: lui         $a2, 0x3ECC
    ctx->r6 = S32(0X3ECC << 16);
    // 0x80074A0C: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x80074A10: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x80074A14: jal         0x80074600
    // 0x80074A18: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    func_80074600(rdram, ctx);
        goto after_7;
    // 0x80074A18: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    after_7:
    // 0x80074A1C: j           L_80074B4C
    // 0x80074A20: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
        goto L_80074B4C;
    // 0x80074A20: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_80074A24:
    // 0x80074A24: bne         $s0, $v0, L_80074B4C
    if (ctx->r16 != ctx->r2) {
        // 0x80074A28: addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
            goto L_80074B4C;
    }
    // 0x80074A28: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // 0x80074A2C: lwc1        $f12, 0x0($s2)
    ctx->f12.u32l = MEM_W(ctx->r18, 0X0);
    // 0x80074A30: addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    // 0x80074A34: swc1        $f12, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f12.u32l;
    // 0x80074A38: lwc1        $f14, 0x8($s2)
    ctx->f14.u32l = MEM_W(ctx->r18, 0X8);
    // 0x80074A3C: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    // 0x80074A40: jal         0x80067D90
    // 0x80074A44: swc1        $f14, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f14.u32l;
    func_80067D90(rdram, ctx);
        goto after_8;
    // 0x80074A44: swc1        $f14, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f14.u32l;
    after_8:
    // 0x80074A48: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80074A4C: lwc1        $f2, 0x6FA8($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X6FA8);
    // 0x80074A50: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80074A54: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x80074A58: lw          $v1, 0xB70($v0)
    ctx->r3 = MEM_W(ctx->r2, 0XB70);
    // 0x80074A5C: addiu       $v0, $zero, 0xD
    ctx->r2 = ADD32(0, 0XD);
    // 0x80074A60: beq         $v1, $v0, L_80074B14
    if (ctx->r3 == ctx->r2) {
        // 0x80074A64: swc1        $f0, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
            goto L_80074B14;
    }
    // 0x80074A64: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    // 0x80074A68: lui         $a1, 0x3DCC
    ctx->r5 = S32(0X3DCC << 16);
    // 0x80074A6C: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    // 0x80074A70: lui         $a2, 0x3ECC
    ctx->r6 = S32(0X3ECC << 16);
    // 0x80074A74: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x80074A78: jal         0x800739A4
    // 0x80074A7C: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    func_800739A4(rdram, ctx);
        goto after_9;
    // 0x80074A7C: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    after_9:
    // 0x80074A80: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    // 0x80074A84: lui         $a2, 0x8014
    ctx->r6 = S32(0X8014 << 16);
    // 0x80074A88: lui         $a1, 0x3F00
    ctx->r5 = S32(0X3F00 << 16);
    // 0x80074A8C: jal         0x80061380
    // 0x80074A90: addiu       $a2, $a2, -0x6740
    ctx->r6 = ADD32(ctx->r6, -0X6740);
    func_80061380(rdram, ctx);
        goto after_10;
    // 0x80074A90: addiu       $a2, $a2, -0x6740
    ctx->r6 = ADD32(ctx->r6, -0X6740);
    after_10:
    // 0x80074A94: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    // 0x80074A98: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x80074A9C: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80074AA0: lwc1        $f0, -0x2EF4($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X2EF4);
    // 0x80074AA4: lbu         $v0, -0x56BC($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X56BC);
    // 0x80074AA8: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80074AAC: lwc1        $f4, -0x2EF0($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X2EF0);
    // 0x80074AB0: beq         $v0, $zero, L_80074B48
    if (ctx->r2 == 0) {
        // 0x80074AB4: addiu       $v1, $sp, 0x18
        ctx->r3 = ADD32(ctx->r29, 0X18);
            goto L_80074B48;
    }
    // 0x80074AB4: addiu       $v1, $sp, 0x18
    ctx->r3 = ADD32(ctx->r29, 0X18);
    // 0x80074AB8: lui         $a0, 0x8007
    ctx->r4 = S32(0X8007 << 16);
    // 0x80074ABC: addiu       $a0, $a0, 0x2EC4
    ctx->r4 = ADD32(ctx->r4, 0X2EC4);
    // 0x80074AC0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80074AC4: addiu       $a3, $zero, 0xF
    ctx->r7 = ADD32(0, 0XF);
    // 0x80074AC8: ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
    // 0x80074ACC: sh          $v0, 0x1C($a1)
    MEM_H(0X1C, ctx->r5) = ctx->r2;
    // 0x80074AD0: sh          $s0, 0x1E($a1)
    MEM_H(0X1E, ctx->r5) = ctx->r16;
    // 0x80074AD4: sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    // 0x80074AD8: swc1        $f0, 0x20($a1)
    MEM_W(0X20, ctx->r5) = ctx->f0.u32l;
    // 0x80074ADC: swc1        $f0, 0x28($a1)
    MEM_W(0X28, ctx->r5) = ctx->f0.u32l;
    // 0x80074AE0: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80074AE4: lwc1        $f0, -0x2EEC($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X2EEC);
    // 0x80074AE8: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80074AEC: lwc1        $f2, -0x2EE8($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X2EE8);
    // 0x80074AF0: addiu       $v0, $sp, 0x48
    ctx->r2 = ADD32(ctx->r29, 0X48);
    // 0x80074AF4: swc1        $f4, 0x24($a1)
    MEM_W(0X24, ctx->r5) = ctx->f4.u32l;
    // 0x80074AF8: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    // 0x80074AFC: swc1        $f4, 0x18($a1)
    MEM_W(0X18, ctx->r5) = ctx->f4.u32l;
    // 0x80074B00: swc1        $f0, 0x10($a1)
    MEM_W(0X10, ctx->r5) = ctx->f0.u32l;
    // 0x80074B04: jal         0x8003FFEC
    // 0x80074B08: swc1        $f2, 0xC($a1)
    MEM_W(0XC, ctx->r5) = ctx->f2.u32l;
    func_8003FFEC(rdram, ctx);
        goto after_11;
    // 0x80074B08: swc1        $f2, 0xC($a1)
    MEM_W(0XC, ctx->r5) = ctx->f2.u32l;
    after_11:
    // 0x80074B0C: j           L_80074B4C
    // 0x80074B10: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80074B4C;
    // 0x80074B10: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80074B14:
    // 0x80074B14: jal         0x8006C994
    // 0x80074B18: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    func_8006C994(rdram, ctx);
        goto after_12;
    // 0x80074B18: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    after_12:
    // 0x80074B1C: andi        $v1, $s3, 0xFFFF
    ctx->r3 = ctx->r19 & 0XFFFF;
    // 0x80074B20: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x80074B24: bne         $v1, $v0, L_80074B4C
    if (ctx->r3 != ctx->r2) {
        // 0x80074B28: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80074B4C;
    }
    // 0x80074B28: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80074B2C: lui         $a1, 0x3DCC
    ctx->r5 = S32(0X3DCC << 16);
    // 0x80074B30: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    // 0x80074B34: lui         $a2, 0x3ECC
    ctx->r6 = S32(0X3ECC << 16);
    // 0x80074B38: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x80074B3C: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x80074B40: jal         0x80074600
    // 0x80074B44: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    func_80074600(rdram, ctx);
        goto after_13;
    // 0x80074B44: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    after_13:
L_80074B48:
    // 0x80074B48: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80074B4C:
    // 0x80074B4C: lw          $ra, 0x6C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X6C);
    // 0x80074B50: lw          $s4, 0x68($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X68);
    // 0x80074B54: lw          $s3, 0x64($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X64);
    // 0x80074B58: lw          $s2, 0x60($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X60);
    // 0x80074B5C: lw          $s1, 0x5C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X5C);
    // 0x80074B60: lw          $s0, 0x58($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X58);
    // 0x80074B64: ldc1        $f22, 0x78($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X78);
    // 0x80074B68: ldc1        $f20, 0x70($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X70);
    // 0x80074B6C: jr          $ra
    // 0x80074B70: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
    return;
    // 0x80074B70: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
;}
RECOMP_FUNC void func_80074B74(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80074B74: addiu       $sp, $sp, -0xB8
    ctx->r29 = ADD32(ctx->r29, -0XB8);
    // 0x80074B78: sw          $s5, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->r21;
    // 0x80074B7C: addu        $s5, $a1, $zero
    ctx->r21 = ADD32(ctx->r5, 0);
    // 0x80074B80: sw          $s6, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->r22;
    // 0x80074B84: addu        $s6, $a2, $zero
    ctx->r22 = ADD32(ctx->r6, 0);
    // 0x80074B88: sw          $s7, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->r23;
    // 0x80074B8C: andi        $s7, $a0, 0xFFFF
    ctx->r23 = ctx->r4 & 0XFFFF;
    // 0x80074B90: addu        $a0, $s7, $zero
    ctx->r4 = ADD32(ctx->r23, 0);
    // 0x80074B94: sw          $ra, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->r31;
    // 0x80074B98: sw          $s4, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->r20;
    // 0x80074B9C: sw          $s3, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->r19;
    // 0x80074BA0: sw          $s2, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->r18;
    // 0x80074BA4: sw          $s1, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->r17;
    // 0x80074BA8: jal         0x8004013C
    // 0x80074BAC: sw          $s0, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->r16;
    func_8004013C(rdram, ctx);
        goto after_0;
    // 0x80074BAC: sw          $s0, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->r16;
    after_0:
    // 0x80074BB0: lw          $s1, 0xC($v0)
    ctx->r17 = MEM_W(ctx->r2, 0XC);
    // 0x80074BB4: addiu       $a2, $sp, 0x70
    ctx->r6 = ADD32(ctx->r29, 0X70);
    // 0x80074BB8: addiu       $s0, $s1, 0x28
    ctx->r16 = ADD32(ctx->r17, 0X28);
    // 0x80074BBC: lw          $s2, 0x0($s1)
    ctx->r18 = MEM_W(ctx->r17, 0X0);
    // 0x80074BC0: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x80074BC4: addiu       $s4, $s2, 0x5C
    ctx->r20 = ADD32(ctx->r18, 0X5C);
    // 0x80074BC8: jal         0x800193E8
    // 0x80074BCC: addu        $a1, $s4, $zero
    ctx->r5 = ADD32(ctx->r20, 0);
    func_800193E8(rdram, ctx);
        goto after_1;
    // 0x80074BCC: addu        $a1, $s4, $zero
    ctx->r5 = ADD32(ctx->r20, 0);
    after_1:
    // 0x80074BD0: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x80074BD4: addiu       $s3, $s2, 0x68
    ctx->r19 = ADD32(ctx->r18, 0X68);
    // 0x80074BD8: addu        $a1, $s3, $zero
    ctx->r5 = ADD32(ctx->r19, 0);
    // 0x80074BDC: jal         0x800193E8
    // 0x80074BE0: addiu       $a2, $sp, 0x80
    ctx->r6 = ADD32(ctx->r29, 0X80);
    func_800193E8(rdram, ctx);
        goto after_2;
    // 0x80074BE0: addiu       $a2, $sp, 0x80
    ctx->r6 = ADD32(ctx->r29, 0X80);
    after_2:
    // 0x80074BE4: lwc1        $f0, 0x28($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X28);
    // 0x80074BE8: mul.s       $f0, $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x80074BEC: lwc1        $f4, 0xC($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XC);
    // 0x80074BF0: mul.s       $f4, $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f4.fl = MUL_S(ctx->f4.fl, ctx->f4.fl);
    // 0x80074BF4: lwc1        $f2, 0x18($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X18);
    // 0x80074BF8: mul.s       $f2, $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x80074BFC: add.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f4.fl;
    // 0x80074C00: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x80074C04: sqrt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = sqrtf(ctx->f0.fl);
    // 0x80074C08: lwc1        $f0, 0x68($s2)
    ctx->f0.u32l = MEM_W(ctx->r18, 0X68);
    // 0x80074C0C: lwc1        $f2, 0x5C($s2)
    ctx->f2.u32l = MEM_W(ctx->r18, 0X5C);
    // 0x80074C10: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x80074C14: mul.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x80074C18: swc1        $f0, 0x0($s5)
    MEM_W(0X0, ctx->r21) = ctx->f0.u32l;
    // 0x80074C1C: lwc1        $f0, 0x4($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X4);
    // 0x80074C20: mul.s       $f0, $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x80074C24: lwc1        $f4, 0x10($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X10);
    // 0x80074C28: mul.s       $f4, $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f4.fl = MUL_S(ctx->f4.fl, ctx->f4.fl);
    // 0x80074C2C: lwc1        $f2, 0x1C($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X1C);
    // 0x80074C30: mul.s       $f2, $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x80074C34: add.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f4.fl;
    // 0x80074C38: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x80074C3C: sqrt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = sqrtf(ctx->f0.fl);
    // 0x80074C40: lwc1        $f0, 0x4($s3)
    ctx->f0.u32l = MEM_W(ctx->r19, 0X4);
    // 0x80074C44: lwc1        $f2, 0x4($s4)
    ctx->f2.u32l = MEM_W(ctx->r20, 0X4);
    // 0x80074C48: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x80074C4C: mul.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x80074C50: swc1        $f0, 0x4($s5)
    MEM_W(0X4, ctx->r21) = ctx->f0.u32l;
    // 0x80074C54: lwc1        $f0, 0x8($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X8);
    // 0x80074C58: mul.s       $f0, $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x80074C5C: lwc1        $f4, 0x14($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X14);
    // 0x80074C60: mul.s       $f4, $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f4.fl = MUL_S(ctx->f4.fl, ctx->f4.fl);
    // 0x80074C64: lwc1        $f2, 0x20($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X20);
    // 0x80074C68: mul.s       $f2, $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x80074C6C: add.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f4.fl;
    // 0x80074C70: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x80074C74: sqrt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = sqrtf(ctx->f0.fl);
    // 0x80074C78: lwc1        $f0, 0x8($s3)
    ctx->f0.u32l = MEM_W(ctx->r19, 0X8);
    // 0x80074C7C: lwc1        $f2, 0x8($s4)
    ctx->f2.u32l = MEM_W(ctx->r20, 0X8);
    // 0x80074C80: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x80074C84: mul.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x80074C88: beq         $s6, $zero, L_80074D18
    if (ctx->r22 == 0) {
        // 0x80074C8C: swc1        $f0, 0x8($s5)
        MEM_W(0X8, ctx->r21) = ctx->f0.u32l;
            goto L_80074D18;
    }
    // 0x80074C8C: swc1        $f0, 0x8($s5)
    MEM_W(0X8, ctx->r21) = ctx->f0.u32l;
    // 0x80074C90: lwc1        $f0, 0x80($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X80);
    // 0x80074C94: lwc1        $f2, 0x70($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X70);
    // 0x80074C98: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x80074C9C: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80074CA0: lwc1        $f4, -0x2EE4($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X2EE4);
    // 0x80074CA4: mul.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x80074CA8: add.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x80074CAC: swc1        $f2, 0x0($s6)
    MEM_W(0X0, ctx->r22) = ctx->f2.u32l;
    // 0x80074CB0: lwc1        $f0, 0x84($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X84);
    // 0x80074CB4: lwc1        $f2, 0x74($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X74);
    // 0x80074CB8: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x80074CBC: mul.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x80074CC0: add.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x80074CC4: swc1        $f2, 0x4($s6)
    MEM_W(0X4, ctx->r22) = ctx->f2.u32l;
    // 0x80074CC8: lwc1        $f0, 0x88($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X88);
    // 0x80074CCC: lwc1        $f2, 0x78($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X78);
    // 0x80074CD0: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x80074CD4: mul.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x80074CD8: add.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x80074CDC: addu        $a0, $s7, $zero
    ctx->r4 = ADD32(ctx->r23, 0);
    // 0x80074CE0: jal         0x8004015C
    // 0x80074CE4: swc1        $f2, 0x8($s6)
    MEM_W(0X8, ctx->r22) = ctx->f2.u32l;
    func_8004015C(rdram, ctx);
        goto after_3;
    // 0x80074CE4: swc1        $f2, 0x8($s6)
    MEM_W(0X8, ctx->r22) = ctx->f2.u32l;
    after_3:
    // 0x80074CE8: addiu       $s0, $sp, 0x40
    ctx->r16 = ADD32(ctx->r29, 0X40);
    // 0x80074CEC: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x80074CF0: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x80074CF4: jal         0x80059B50
    // 0x80074CF8: addu        $a1, $v0, $zero
    ctx->r5 = ADD32(ctx->r2, 0);
    func_80059B50(rdram, ctx);
        goto after_4;
    // 0x80074CF8: addu        $a1, $v0, $zero
    ctx->r5 = ADD32(ctx->r2, 0);
    after_4:
    // 0x80074CFC: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    // 0x80074D00: jal         0x8001C774
    // 0x80074D04: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    func_8001C774(rdram, ctx);
        goto after_5;
    // 0x80074D04: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    after_5:
    // 0x80074D08: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    // 0x80074D0C: addu        $a1, $s6, $zero
    ctx->r5 = ADD32(ctx->r22, 0);
    // 0x80074D10: jal         0x800193E8
    // 0x80074D14: addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    func_800193E8(rdram, ctx);
        goto after_6;
    // 0x80074D14: addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    after_6:
L_80074D18:
    // 0x80074D18: lw          $ra, 0xB0($sp)
    ctx->r31 = MEM_W(ctx->r29, 0XB0);
    // 0x80074D1C: lw          $s7, 0xAC($sp)
    ctx->r23 = MEM_W(ctx->r29, 0XAC);
    // 0x80074D20: lw          $s6, 0xA8($sp)
    ctx->r22 = MEM_W(ctx->r29, 0XA8);
    // 0x80074D24: lw          $s5, 0xA4($sp)
    ctx->r21 = MEM_W(ctx->r29, 0XA4);
    // 0x80074D28: lw          $s4, 0xA0($sp)
    ctx->r20 = MEM_W(ctx->r29, 0XA0);
    // 0x80074D2C: lw          $s3, 0x9C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X9C);
    // 0x80074D30: lw          $s2, 0x98($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X98);
    // 0x80074D34: lw          $s1, 0x94($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X94);
    // 0x80074D38: lw          $s0, 0x90($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X90);
    // 0x80074D3C: jr          $ra
    // 0x80074D40: addiu       $sp, $sp, 0xB8
    ctx->r29 = ADD32(ctx->r29, 0XB8);
    return;
    // 0x80074D40: addiu       $sp, $sp, 0xB8
    ctx->r29 = ADD32(ctx->r29, 0XB8);
;}
RECOMP_FUNC void func_80074D44(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80074D44: addiu       $sp, $sp, -0x70
    ctx->r29 = ADD32(ctx->r29, -0X70);
    // 0x80074D48: sw          $s3, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r19;
    // 0x80074D4C: addu        $s3, $a0, $zero
    ctx->r19 = ADD32(ctx->r4, 0);
    // 0x80074D50: sw          $s2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r18;
    // 0x80074D54: andi        $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 & 0XFFFF;
    // 0x80074D58: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x80074D5C: sw          $ra, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r31;
    // 0x80074D60: sw          $s1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r17;
    // 0x80074D64: sw          $s0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r16;
    // 0x80074D68: sdc1        $f22, 0x68($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X68, ctx->r29);
    // 0x80074D6C: sdc1        $f20, 0x60($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X60, ctx->r29);
    // 0x80074D70: lw          $s1, 0x4($s3)
    ctx->r17 = MEM_W(ctx->r19, 0X4);
    // 0x80074D74: beq         $a1, $v0, L_80074FA4
    if (ctx->r5 == ctx->r2) {
        // 0x80074D78: addu        $s2, $a2, $zero
        ctx->r18 = ADD32(ctx->r6, 0);
            goto L_80074FA4;
    }
    // 0x80074D78: addu        $s2, $a2, $zero
    ctx->r18 = ADD32(ctx->r6, 0);
    // 0x80074D7C: slti        $v0, $a1, 0x3
    ctx->r2 = SIGNED(ctx->r5) < 0X3 ? 1 : 0;
    // 0x80074D80: beq         $v0, $zero, L_80074D98
    if (ctx->r2 == 0) {
        // 0x80074D84: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80074D98;
    }
    // 0x80074D84: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80074D88: beq         $a1, $v0, L_80074DB4
    if (ctx->r5 == ctx->r2) {
        // 0x80074D8C: addiu       $a0, $zero, 0x110
        ctx->r4 = ADD32(0, 0X110);
            goto L_80074DB4;
    }
    // 0x80074D8C: addiu       $a0, $zero, 0x110
    ctx->r4 = ADD32(0, 0X110);
    // 0x80074D90: j           L_800751F0
    // 0x80074D94: nop

        goto L_800751F0;
    // 0x80074D94: nop

L_80074D98:
    // 0x80074D98: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x80074D9C: beq         $a1, $v0, L_80074FC4
    if (ctx->r5 == ctx->r2) {
        // 0x80074DA0: addiu       $v0, $zero, 0x4
        ctx->r2 = ADD32(0, 0X4);
            goto L_80074FC4;
    }
    // 0x80074DA0: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // 0x80074DA4: beq         $a1, $v0, L_8007514C
    if (ctx->r5 == ctx->r2) {
        // 0x80074DA8: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_8007514C;
    }
    // 0x80074DA8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80074DAC: j           L_800751F4
    // 0x80074DB0: nop

        goto L_800751F4;
    // 0x80074DB0: nop

L_80074DB4:
    // 0x80074DB4: jal         0x80001ACC
    // 0x80074DB8: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    rs_malloc(rdram, ctx);
        goto after_0;
    // 0x80074DB8: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    after_0:
    // 0x80074DBC: addu        $s1, $v0, $zero
    ctx->r17 = ADD32(ctx->r2, 0);
    // 0x80074DC0: addiu       $s0, $s1, 0x5C
    ctx->r16 = ADD32(ctx->r17, 0X5C);
    // 0x80074DC4: lui         $v0, 0x4900
    ctx->r2 = S32(0X4900 << 16);
    // 0x80074DC8: sw          $s1, 0x4($s3)
    MEM_W(0X4, ctx->r19) = ctx->r17;
    // 0x80074DCC: sw          $v0, 0x68($s1)
    MEM_W(0X68, ctx->r17) = ctx->r2;
    // 0x80074DD0: addiu       $v0, $s1, 0xB8
    ctx->r2 = ADD32(ctx->r17, 0XB8);
    // 0x80074DD4: sw          $v0, 0x7C($s1)
    MEM_W(0X7C, ctx->r17) = ctx->r2;
    // 0x80074DD8: addiu       $v0, $zero, 0x300
    ctx->r2 = ADD32(0, 0X300);
    // 0x80074DDC: sw          $zero, 0x1C($s1)
    MEM_W(0X1C, ctx->r17) = 0;
    // 0x80074DE0: sw          $zero, 0x18($s1)
    MEM_W(0X18, ctx->r17) = 0;
    // 0x80074DE4: sw          $zero, 0x14($s1)
    MEM_W(0X14, ctx->r17) = 0;
    // 0x80074DE8: sw          $zero, 0x10($s1)
    MEM_W(0X10, ctx->r17) = 0;
    // 0x80074DEC: sw          $zero, 0x24($s1)
    MEM_W(0X24, ctx->r17) = 0;
    // 0x80074DF0: sw          $s0, 0x20($s1)
    MEM_W(0X20, ctx->r17) = ctx->r16;
    // 0x80074DF4: sw          $zero, 0x64($s1)
    MEM_W(0X64, ctx->r17) = 0;
    // 0x80074DF8: sw          $zero, 0x60($s1)
    MEM_W(0X60, ctx->r17) = 0;
    // 0x80074DFC: sw          $zero, 0x5C($s1)
    MEM_W(0X5C, ctx->r17) = 0;
    // 0x80074E00: sw          $zero, 0x6C($s1)
    MEM_W(0X6C, ctx->r17) = 0;
    // 0x80074E04: sw          $zero, 0x74($s1)
    MEM_W(0X74, ctx->r17) = 0;
    // 0x80074E08: sw          $zero, 0x70($s1)
    MEM_W(0X70, ctx->r17) = 0;
    // 0x80074E0C: sw          $zero, 0xBC($s1)
    MEM_W(0XBC, ctx->r17) = 0;
    // 0x80074E10: sw          $zero, 0xB8($s1)
    MEM_W(0XB8, ctx->r17) = 0;
    // 0x80074E14: sh          $zero, 0xC4($s1)
    MEM_H(0XC4, ctx->r17) = 0;
    // 0x80074E18: sh          $zero, 0xC2($s1)
    MEM_H(0XC2, ctx->r17) = 0;
    // 0x80074E1C: sh          $zero, 0xC0($s1)
    MEM_H(0XC0, ctx->r17) = 0;
    // 0x80074E20: jal         0x80003430
    // 0x80074E24: sh          $v0, 0xC8($s1)
    MEM_H(0XC8, ctx->r17) = ctx->r2;
    rand_recomp(rdram, ctx);
        goto after_1;
    // 0x80074E24: sh          $v0, 0xC8($s1)
    MEM_H(0XC8, ctx->r17) = ctx->r2;
    after_1:
    // 0x80074E28: addiu       $v1, $zero, 0xFF
    ctx->r3 = ADD32(0, 0XFF);
    // 0x80074E2C: andi        $v0, $v0, 0x1C00
    ctx->r2 = ctx->r2 & 0X1C00;
    // 0x80074E30: sb          $v1, 0xE6($s1)
    MEM_B(0XE6, ctx->r17) = ctx->r3;
    // 0x80074E34: sb          $v1, 0xE5($s1)
    MEM_B(0XE5, ctx->r17) = ctx->r3;
    // 0x80074E38: sb          $v1, 0xE4($s1)
    MEM_B(0XE4, ctx->r17) = ctx->r3;
    // 0x80074E3C: sb          $v1, 0xE7($s1)
    MEM_B(0XE7, ctx->r17) = ctx->r3;
    // 0x80074E40: lhu         $v1, 0xC8($s1)
    ctx->r3 = MEM_HU(ctx->r17, 0XC8);
    // 0x80074E44: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80074E48: lwc1        $f20, -0x2EE0($at)
    ctx->f20.u32l = MEM_W(ctx->r1, -0X2EE0);
    // 0x80074E4C: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x80074E50: sh          $v1, 0xC8($s1)
    MEM_H(0XC8, ctx->r17) = ctx->r3;
    // 0x80074E54: swc1        $f20, 0xEC($s1)
    MEM_W(0XEC, ctx->r17) = ctx->f20.u32l;
    // 0x80074E58: lwc1        $f0, 0x4($s2)
    ctx->f0.u32l = MEM_W(ctx->r18, 0X4);
    // 0x80074E5C: jal         0x80003430
    // 0x80074E60: swc1        $f0, 0xF0($s1)
    MEM_W(0XF0, ctx->r17) = ctx->f0.u32l;
    rand_recomp(rdram, ctx);
        goto after_2;
    // 0x80074E60: swc1        $f0, 0xF0($s1)
    MEM_W(0XF0, ctx->r17) = ctx->f0.u32l;
    after_2:
    // 0x80074E64: andi        $v0, $v0, 0x7F
    ctx->r2 = ctx->r2 & 0X7F;
    // 0x80074E68: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80074E6C: lwc1        $f22, -0x2EDC($at)
    ctx->f22.u32l = MEM_W(ctx->r1, -0X2EDC);
    // 0x80074E70: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x80074E74: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x80074E78: sub.s       $f0, $f0, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f22.fl;
    // 0x80074E7C: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80074E80: lwc1        $f2, -0x2ED8($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X2ED8);
    // 0x80074E84: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x80074E88: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x80074E8C: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80074E90: lwc1        $f2, -0x2ED4($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X2ED4);
    // 0x80074E94: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x80074E98: lwc1        $f2, 0xF0($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0XF0);
    // 0x80074E9C: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x80074EA0: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80074EA4: lwc1        $f4, -0x2ED0($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X2ED0);
    // 0x80074EA8: add.s       $f6, $f0, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f0.fl + ctx->f0.fl;
    // 0x80074EAC: swc1        $f0, 0xF4($s1)
    MEM_W(0XF4, ctx->r17) = ctx->f0.u32l;
    // 0x80074EB0: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
    // 0x80074EB4: add.s       $f2, $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f4.fl;
    // 0x80074EB8: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x80074EBC: sub.s       $f6, $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f6.fl - ctx->f0.fl;
    // 0x80074EC0: swc1        $f2, 0xDC($s1)
    MEM_W(0XDC, ctx->r17) = ctx->f2.u32l;
    // 0x80074EC4: swc1        $f2, 0xD8($s1)
    MEM_W(0XD8, ctx->r17) = ctx->f2.u32l;
    // 0x80074EC8: swc1        $f6, 0xF8($s1)
    MEM_W(0XF8, ctx->r17) = ctx->f6.u32l;
    // 0x80074ECC: lhu         $v0, -0x66F0($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X66F0);
    // 0x80074ED0: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x80074ED4: jal         0x8000A85C
    // 0x80074ED8: sh          $v0, 0xCA($s1)
    MEM_H(0XCA, ctx->r17) = ctx->r2;
    func_8000A85C(rdram, ctx);
        goto after_3;
    // 0x80074ED8: sh          $v0, 0xCA($s1)
    MEM_H(0XCA, ctx->r17) = ctx->r2;
    after_3:
    // 0x80074EDC: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80074EE0: lwc1        $f0, -0x2ECC($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X2ECC);
    // 0x80074EE4: swc1        $f0, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->f0.u32l;
    // 0x80074EE8: swc1        $f0, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->f0.u32l;
    // 0x80074EEC: jal         0x80003430
    // 0x80074EF0: swc1        $f0, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->f0.u32l;
    rand_recomp(rdram, ctx);
        goto after_4;
    // 0x80074EF0: swc1        $f0, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->f0.u32l;
    after_4:
    // 0x80074EF4: andi        $v0, $v0, 0x7F
    ctx->r2 = ctx->r2 & 0X7F;
    // 0x80074EF8: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x80074EFC: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x80074F00: sub.s       $f0, $f0, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f22.fl;
    // 0x80074F04: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80074F08: lwc1        $f2, -0x2EC8($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X2EC8);
    // 0x80074F0C: div.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f2.fl);
    // 0x80074F10: abs.s       $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = fabsf(ctx->f0.fl);
    // 0x80074F14: swc1        $f4, 0xE8($s1)
    MEM_W(0XE8, ctx->r17) = ctx->f4.u32l;
    // 0x80074F18: mov.s       $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.fl = ctx->f4.fl;
    // 0x80074F1C: mul.s       $f0, $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f20.fl);
    // 0x80074F20: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80074F24: lwc1        $f2, -0x2EC4($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X2EC4);
    // 0x80074F28: mul.s       $f4, $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f4.fl, ctx->f2.fl);
    // 0x80074F2C: add.s       $f0, $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f0.fl;
    // 0x80074F30: sub.s       $f20, $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f20.fl = ctx->f20.fl - ctx->f0.fl;
    // 0x80074F34: swc1        $f4, 0xC($s1)
    MEM_W(0XC, ctx->r17) = ctx->f4.u32l;
    // 0x80074F38: swc1        $f20, 0xEC($s1)
    MEM_W(0XEC, ctx->r17) = ctx->f20.u32l;
    // 0x80074F3C: lhu         $v0, 0x8($s2)
    ctx->r2 = MEM_HU(ctx->r18, 0X8);
    // 0x80074F40: sh          $v0, 0x10C($s1)
    MEM_H(0X10C, ctx->r17) = ctx->r2;
    // 0x80074F44: lhu         $a1, 0x8($s2)
    ctx->r5 = MEM_HU(ctx->r18, 0X8);
    // 0x80074F48: jal         0x80040188
    // 0x80074F4C: ori         $a0, $zero, 0xFFFF
    ctx->r4 = 0 | 0XFFFF;
    func_80040188(rdram, ctx);
        goto after_5;
    // 0x80074F4C: ori         $a0, $zero, 0xFFFF
    ctx->r4 = 0 | 0XFFFF;
    after_5:
    // 0x80074F50: sh          $v0, 0x10E($s1)
    MEM_H(0X10E, ctx->r17) = ctx->r2;
    // 0x80074F54: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x80074F58: ori         $v1, $zero, 0xFFFF
    ctx->r3 = 0 | 0XFFFF;
    // 0x80074F5C: bne         $v0, $v1, L_80074F78
    if (ctx->r2 != ctx->r3) {
        // 0x80074F60: lui         $v0, 0x8014
        ctx->r2 = S32(0X8014 << 16);
            goto L_80074F78;
    }
    // 0x80074F60: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
L_80074F64:
    // 0x80074F64: lhu         $a0, 0x16($s3)
    ctx->r4 = MEM_HU(ctx->r19, 0X16);
    // 0x80074F68: jal         0x8003ED74
    // 0x80074F6C: nop

    func_8003ED74(rdram, ctx);
        goto after_6;
    // 0x80074F6C: nop

    after_6:
    // 0x80074F70: j           L_800751F4
    // 0x80074F74: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_800751F4;
    // 0x80074F74: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80074F78:
    // 0x80074F78: lwc1        $f0, 0x0($s2)
    ctx->f0.u32l = MEM_W(ctx->r18, 0X0);
    // 0x80074F7C: swc1        $f0, 0xFC($s1)
    MEM_W(0XFC, ctx->r17) = ctx->f0.u32l;
    // 0x80074F80: lhu         $a0, -0x6A8C($v0)
    ctx->r4 = MEM_HU(ctx->r2, -0X6A8C);
    // 0x80074F84: jal         0x8003E684
    // 0x80074F88: addu        $a1, $s3, $zero
    ctx->r5 = ADD32(ctx->r19, 0);
    func_8003E684(rdram, ctx);
        goto after_7;
    // 0x80074F88: addu        $a1, $s3, $zero
    ctx->r5 = ADD32(ctx->r19, 0);
    after_7:
    // 0x80074F8C: lhu         $a0, 0x10C($s1)
    ctx->r4 = MEM_HU(ctx->r17, 0X10C);
    // 0x80074F90: lw          $a2, 0xFC($s1)
    ctx->r6 = MEM_W(ctx->r17, 0XFC);
    // 0x80074F94: jal         0x80077AC0
    // 0x80074F98: addiu       $a1, $s1, 0x100
    ctx->r5 = ADD32(ctx->r17, 0X100);
    func_80077AC0(rdram, ctx);
        goto after_8;
    // 0x80074F98: addiu       $a1, $s1, 0x100
    ctx->r5 = ADD32(ctx->r17, 0X100);
    after_8:
    // 0x80074F9C: j           L_800751F4
    // 0x80074FA0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_800751F4;
    // 0x80074FA0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80074FA4:
    // 0x80074FA4: lhu         $v1, 0x10E($s1)
    ctx->r3 = MEM_HU(ctx->r17, 0X10E);
    // 0x80074FA8: ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
    // 0x80074FAC: beq         $v1, $v0, L_800751F4
    if (ctx->r3 == ctx->r2) {
        // 0x80074FB0: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_800751F4;
    }
    // 0x80074FB0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80074FB4: jal         0x8003F0C8
    // 0x80074FB8: addu        $a0, $v1, $zero
    ctx->r4 = ADD32(ctx->r3, 0);
    func_8003F0C8(rdram, ctx);
        goto after_9;
    // 0x80074FB8: addu        $a0, $v1, $zero
    ctx->r4 = ADD32(ctx->r3, 0);
    after_9:
    // 0x80074FBC: j           L_800751F4
    // 0x80074FC0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_800751F4;
    // 0x80074FC0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80074FC4:
    // 0x80074FC4: lhu         $a0, 0x10E($s1)
    ctx->r4 = MEM_HU(ctx->r17, 0X10E);
    // 0x80074FC8: jal         0x80040218
    // 0x80074FCC: nop

    func_80040218(rdram, ctx);
        goto after_10;
    // 0x80074FCC: nop

    after_10:
    // 0x80074FD0: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x80074FD4: ori         $v1, $zero, 0xFFFF
    ctx->r3 = 0 | 0XFFFF;
    // 0x80074FD8: beq         $v0, $v1, L_80074F64
    if (ctx->r2 == ctx->r3) {
        // 0x80074FDC: nop
    
            goto L_80074F64;
    }
    // 0x80074FDC: nop

    // 0x80074FE0: lwc1        $f4, 0xE8($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0XE8);
    // 0x80074FE4: lwc1        $f0, 0x0($s2)
    ctx->f0.u32l = MEM_W(ctx->r18, 0X0);
    // 0x80074FE8: add.s       $f4, $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f0.fl;
    // 0x80074FEC: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80074FF0: lwc1        $f6, -0x2EC0($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X2EC0);
    // 0x80074FF4: swc1        $f4, 0xE8($s1)
    MEM_W(0XE8, ctx->r17) = ctx->f4.u32l;
    // 0x80074FF8: mov.s       $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.fl = ctx->f4.fl;
    // 0x80074FFC: mul.s       $f0, $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x80075000: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80075004: lwc1        $f2, -0x2EBC($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X2EBC);
    // 0x80075008: mul.s       $f4, $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f4.fl, ctx->f2.fl);
    // 0x8007500C: add.s       $f0, $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f0.fl;
    // 0x80075010: lwc1        $f2, 0xF8($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0XF8);
    // 0x80075014: sub.s       $f0, $f6, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f6.fl - ctx->f0.fl;
    // 0x80075018: swc1        $f4, 0xC($s1)
    MEM_W(0XC, ctx->r17) = ctx->f4.u32l;
    // 0x8007501C: swc1        $f0, 0xEC($s1)
    MEM_W(0XEC, ctx->r17) = ctx->f0.u32l;
    // 0x80075020: lwc1        $f0, 0x0($s2)
    ctx->f0.u32l = MEM_W(ctx->r18, 0X0);
    // 0x80075024: mul.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x80075028: lwc1        $f4, 0xE8($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0XE8);
    // 0x8007502C: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80075030: lwc1        $f0, -0x2EB8($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X2EB8);
    // 0x80075034: c.le.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl <= ctx->f0.fl;
    // 0x80075038: add.s       $f2, $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f2.fl;
    // 0x8007503C: lwc1        $f0, 0xF4($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0XF4);
    // 0x80075040: lwc1        $f4, 0xF0($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0XF0);
    // 0x80075044: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x80075048: swc1        $f4, 0xDC($s1)
    MEM_W(0XDC, ctx->r17) = ctx->f4.u32l;
    // 0x8007504C: swc1        $f4, 0xD8($s1)
    MEM_W(0XD8, ctx->r17) = ctx->f4.u32l;
    // 0x80075050: bc1f        L_8007509C
    if (!c1cs) {
        // 0x80075054: swc1        $f0, 0xF4($s1)
        MEM_W(0XF4, ctx->r17) = ctx->f0.u32l;
            goto L_8007509C;
    }
    // 0x80075054: swc1        $f0, 0xF4($s1)
    MEM_W(0XF4, ctx->r17) = ctx->f0.u32l;
    // 0x80075058: lwc1        $f0, 0xEC($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0XEC);
    // 0x8007505C: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80075060: lwc1        $f2, -0x2EB4($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X2EB4);
    // 0x80075064: c.le.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl <= ctx->f0.fl;
    // 0x80075068: nop

    // 0x8007506C: bc1tl       L_80075084
    if (c1cs) {
        // 0x80075070: sub.s       $f0, $f0, $f2
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
            goto L_80075084;
    }
    goto skip_0;
    // 0x80075070: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    skip_0:
    // 0x80075074: trunc.w.s   $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    ctx->f8.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x80075078: mfc1        $v1, $f8
    ctx->r3 = (int32_t)ctx->f8.u32l;
    // 0x8007507C: j           L_80075118
    // 0x80075080: sb          $v1, 0xE7($s1)
    MEM_B(0XE7, ctx->r17) = ctx->r3;
        goto L_80075118;
    // 0x80075080: sb          $v1, 0xE7($s1)
    MEM_B(0XE7, ctx->r17) = ctx->r3;
L_80075084:
    // 0x80075084: lui         $v0, 0x8000
    ctx->r2 = S32(0X8000 << 16);
    // 0x80075088: trunc.w.s   $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    ctx->f8.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x8007508C: mfc1        $v1, $f8
    ctx->r3 = (int32_t)ctx->f8.u32l;
    // 0x80075090: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x80075094: j           L_80075118
    // 0x80075098: sb          $v1, 0xE7($s1)
    MEM_B(0XE7, ctx->r17) = ctx->r3;
        goto L_80075118;
    // 0x80075098: sb          $v1, 0xE7($s1)
    MEM_B(0XE7, ctx->r17) = ctx->r3;
L_8007509C:
    // 0x8007509C: lhu         $a0, 0x10C($s1)
    ctx->r4 = MEM_HU(ctx->r17, 0X10C);
    // 0x800750A0: lw          $a2, 0xFC($s1)
    ctx->r6 = MEM_W(ctx->r17, 0XFC);
    // 0x800750A4: addiu       $a1, $s1, 0x100
    ctx->r5 = ADD32(ctx->r17, 0X100);
    // 0x800750A8: swc1        $f6, 0xEC($s1)
    MEM_W(0XEC, ctx->r17) = ctx->f6.u32l;
    // 0x800750AC: sw          $zero, 0xE8($s1)
    MEM_W(0XE8, ctx->r17) = 0;
    // 0x800750B0: jal         0x80077AC0
    // 0x800750B4: sw          $zero, 0xC($s1)
    MEM_W(0XC, ctx->r17) = 0;
    func_80077AC0(rdram, ctx);
        goto after_11;
    // 0x800750B4: sw          $zero, 0xC($s1)
    MEM_W(0XC, ctx->r17) = 0;
    after_11:
    // 0x800750B8: jal         0x80003430
    // 0x800750BC: nop

    rand_recomp(rdram, ctx);
        goto after_12;
    // 0x800750BC: nop

    after_12:
    // 0x800750C0: andi        $v0, $v0, 0x7F
    ctx->r2 = ctx->r2 & 0X7F;
    // 0x800750C4: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x800750C8: lwc1        $f2, -0x2EB0($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X2EB0);
    // 0x800750CC: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x800750D0: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x800750D4: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x800750D8: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x800750DC: lwc1        $f2, -0x2EAC($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X2EAC);
    // 0x800750E0: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x800750E4: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x800750E8: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x800750EC: lwc1        $f2, -0x2EA8($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X2EA8);
    // 0x800750F0: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x800750F4: lwc1        $f2, 0xF0($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0XF0);
    // 0x800750F8: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x800750FC: add.s       $f2, $f0, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f0.fl + ctx->f0.fl;
    // 0x80075100: swc1        $f0, 0xF4($s1)
    MEM_W(0XF4, ctx->r17) = ctx->f0.u32l;
    // 0x80075104: mov.s       $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    ctx->f4.fl = ctx->f0.fl;
    // 0x80075108: sub.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl - ctx->f0.fl;
    // 0x8007510C: swc1        $f4, 0xDC($s1)
    MEM_W(0XDC, ctx->r17) = ctx->f4.u32l;
    // 0x80075110: swc1        $f4, 0xD8($s1)
    MEM_W(0XD8, ctx->r17) = ctx->f4.u32l;
    // 0x80075114: swc1        $f2, 0xF8($s1)
    MEM_W(0XF8, ctx->r17) = ctx->f2.u32l;
L_80075118:
    // 0x80075118: lhu         $a0, 0x10C($s1)
    ctx->r4 = MEM_HU(ctx->r17, 0X10C);
    // 0x8007511C: jal         0x8004015C
    // 0x80075120: nop

    func_8004015C(rdram, ctx);
        goto after_13;
    // 0x80075120: nop

    after_13:
    // 0x80075124: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    // 0x80075128: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x8007512C: jal         0x80059B50
    // 0x80075130: addu        $a1, $v0, $zero
    ctx->r5 = ADD32(ctx->r2, 0);
    func_80059B50(rdram, ctx);
        goto after_14;
    // 0x80075130: addu        $a1, $v0, $zero
    ctx->r5 = ADD32(ctx->r2, 0);
    after_14:
    // 0x80075134: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    // 0x80075138: addiu       $a1, $s1, 0x100
    ctx->r5 = ADD32(ctx->r17, 0X100);
    // 0x8007513C: jal         0x800193E8
    // 0x80075140: addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    func_800193E8(rdram, ctx);
        goto after_15;
    // 0x80075140: addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    after_15:
    // 0x80075144: j           L_800751F4
    // 0x80075148: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_800751F4;
    // 0x80075148: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8007514C:
    // 0x8007514C: lw          $a1, 0x0($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X0);
    // 0x80075150: lw          $a2, 0x4($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X4);
    // 0x80075154: lw          $a3, 0x8($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X8);
    // 0x80075158: jal         0x8001CAC4
    // 0x8007515C: addiu       $a0, $s1, 0x2C
    ctx->r4 = ADD32(ctx->r17, 0X2C);
    func_8001CAC4(rdram, ctx);
        goto after_16;
    // 0x8007515C: addiu       $a0, $s1, 0x2C
    ctx->r4 = ADD32(ctx->r17, 0X2C);
    after_16:
    // 0x80075160: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x80075164: lwc1        $f0, 0xC($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0XC);
    // 0x80075168: addiu       $a1, $v0, -0x66F0
    ctx->r5 = ADD32(ctx->r2, -0X66F0);
    // 0x8007516C: trunc.w.s   $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    ctx->f8.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x80075170: mfc1        $v1, $f8
    ctx->r3 = (int32_t)ctx->f8.u32l;
    // 0x80075174: bgez        $v1, L_80075180
    if (SIGNED(ctx->r3) >= 0) {
        // 0x80075178: addu        $a0, $v1, $zero
        ctx->r4 = ADD32(ctx->r3, 0);
            goto L_80075180;
    }
    // 0x80075178: addu        $a0, $v1, $zero
    ctx->r4 = ADD32(ctx->r3, 0);
    // 0x8007517C: addiu       $a0, $v1, 0x7
    ctx->r4 = ADD32(ctx->r3, 0X7);
L_80075180:
    // 0x80075180: sra         $v0, $a0, 3
    ctx->r2 = S32(SIGNED(ctx->r4) >> 3);
    // 0x80075184: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x80075188: subu        $v0, $v1, $v0
    ctx->r2 = SUB32(ctx->r3, ctx->r2);
    // 0x8007518C: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x80075190: addu        $v0, $v0, $a1
    ctx->r2 = ADD32(ctx->r2, ctx->r5);
    // 0x80075194: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x80075198: lhu         $v0, 0x0($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X0);
    // 0x8007519C: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x800751A0: sh          $v0, 0xCA($s1)
    MEM_H(0XCA, ctx->r17) = ctx->r2;
    // 0x800751A4: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x800751A8: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    // 0x800751AC: jal         0x8001DC34
    // 0x800751B0: addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    func_8001DC34(rdram, ctx);
        goto after_17;
    // 0x800751B0: addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    after_17:
    // 0x800751B4: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x800751B8: beq         $v0, $zero, L_800751F4
    if (ctx->r2 == 0) {
        // 0x800751BC: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_800751F4;
    }
    // 0x800751BC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800751C0: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x800751C4: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x800751C8: beq         $v0, $zero, L_800751E0
    if (ctx->r2 == 0) {
        // 0x800751CC: sw          $v0, 0x10($s1)
        MEM_W(0X10, ctx->r17) = ctx->r2;
            goto L_800751E0;
    }
    // 0x800751CC: sw          $v0, 0x10($s1)
    MEM_W(0X10, ctx->r17) = ctx->r2;
    // 0x800751D0: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x800751D4: lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X0);
    // 0x800751D8: addiu       $v0, $s1, 0x10
    ctx->r2 = ADD32(ctx->r17, 0X10);
    // 0x800751DC: sw          $v0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r2;
L_800751E0:
    // 0x800751E0: lw          $v1, 0x0($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X0);
    // 0x800751E4: addiu       $v0, $s1, 0x10
    ctx->r2 = ADD32(ctx->r17, 0X10);
    // 0x800751E8: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x800751EC: sw          $zero, 0x14($s1)
    MEM_W(0X14, ctx->r17) = 0;
L_800751F0:
    // 0x800751F0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800751F4:
    // 0x800751F4: lw          $ra, 0x58($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X58);
    // 0x800751F8: lw          $s3, 0x54($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X54);
    // 0x800751FC: lw          $s2, 0x50($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X50);
    // 0x80075200: lw          $s1, 0x4C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X4C);
    // 0x80075204: lw          $s0, 0x48($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X48);
    // 0x80075208: ldc1        $f22, 0x68($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X68);
    // 0x8007520C: ldc1        $f20, 0x60($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X60);
    // 0x80075210: jr          $ra
    // 0x80075214: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
    return;
    // 0x80075214: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
;}
RECOMP_FUNC void func_80075218(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80075218: addiu       $sp, $sp, -0xD8
    ctx->r29 = ADD32(ctx->r29, -0XD8);
    // 0x8007521C: sw          $s6, 0xB8($sp)
    MEM_W(0XB8, ctx->r29) = ctx->r22;
    // 0x80075220: addu        $s6, $a1, $zero
    ctx->r22 = ADD32(ctx->r5, 0);
    // 0x80075224: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x80075228: sdc1        $f22, 0xD0($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0XD0, ctx->r29);
    // 0x8007522C: mtc1        $a2, $f22
    ctx->f22.u32l = ctx->r6;
    // 0x80075230: lw          $a1, -0x72E4($v0)
    ctx->r5 = MEM_W(ctx->r2, -0X72E4);
    // 0x80075234: sw          $s5, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->r21;
    // 0x80075238: lw          $s5, 0xE8($sp)
    ctx->r21 = MEM_W(ctx->r29, 0XE8);
    // 0x8007523C: sw          $s7, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->r23;
    // 0x80075240: addu        $s7, $a0, $zero
    ctx->r23 = ADD32(ctx->r4, 0);
    // 0x80075244: sw          $s1, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->r17;
    // 0x80075248: addu        $s1, $a3, $zero
    ctx->r17 = ADD32(ctx->r7, 0);
    // 0x8007524C: sw          $s0, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->r16;
    // 0x80075250: lbu         $s0, 0xEF($sp)
    ctx->r16 = MEM_BU(ctx->r29, 0XEF);
    // 0x80075254: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    // 0x80075258: sw          $ra, 0xC0($sp)
    MEM_W(0XC0, ctx->r29) = ctx->r31;
    // 0x8007525C: sw          $s4, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->r20;
    // 0x80075260: sw          $s3, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->r19;
    // 0x80075264: sw          $s2, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->r18;
    // 0x80075268: sdc1        $f20, 0xC8($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0XC8, ctx->r29);
    // 0x8007526C: jal         0x80059D18
    // 0x80075270: addiu       $a1, $a1, 0x28
    ctx->r5 = ADD32(ctx->r5, 0X28);
    func_80059D18(rdram, ctx);
        goto after_0;
    // 0x80075270: addiu       $a1, $a1, 0x28
    ctx->r5 = ADD32(ctx->r5, 0X28);
    after_0:
    // 0x80075274: andi        $s0, $s0, 0xFF
    ctx->r16 = ctx->r16 & 0XFF;
    // 0x80075278: bne         $s0, $zero, L_80075348
    if (ctx->r16 != 0) {
        // 0x8007527C: nop
    
            goto L_80075348;
    }
    // 0x8007527C: nop

    // 0x80075280: bne         $s1, $zero, L_800752A4
    if (ctx->r17 != 0) {
        // 0x80075284: addiu       $a0, $sp, 0x40
        ctx->r4 = ADD32(ctx->r29, 0X40);
            goto L_800752A4;
    }
    // 0x80075284: addiu       $a0, $sp, 0x40
    ctx->r4 = ADD32(ctx->r29, 0X40);
    // 0x80075288: mtc1        $s5, $f6
    ctx->f6.u32l = ctx->r21;
    // 0x8007528C: cvt.s.w     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80075290: mfc1        $a2, $f6
    ctx->r6 = (int32_t)ctx->f6.u32l;
    // 0x80075294: jal         0x8001D240
    // 0x80075298: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    func_8001D240(rdram, ctx);
        goto after_1;
    // 0x80075298: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    after_1:
    // 0x8007529C: j           L_80075340
    // 0x800752A0: addiu       $a0, $sp, 0x40
    ctx->r4 = ADD32(ctx->r29, 0X40);
        goto L_80075340;
    // 0x800752A0: addiu       $a0, $sp, 0x40
    ctx->r4 = ADD32(ctx->r29, 0X40);
L_800752A4:
    // 0x800752A4: jal         0x80003430
    // 0x800752A8: nop

    rand_recomp(rdram, ctx);
        goto after_2;
    // 0x800752A8: nop

    after_2:
    // 0x800752AC: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x800752B0: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x800752B4: div         $zero, $v0, $s1
    if (S32(ctx->r17) != 0) { lo = S32(S64(S32(ctx->r2)) / S64(S32(ctx->r17))); hi = S32(S64(S32(ctx->r2)) % S64(S32(ctx->r17))); } else { lo = 0; hi = S32(ctx->r2); }
    // 0x800752B8: bne         $s1, $zero, L_800752C4
    if (ctx->r17 != 0) {
        // 0x800752BC: nop
    
            goto L_800752C4;
    }
    // 0x800752BC: nop

    // 0x800752C0: break       7
    do_break(2147963584);
L_800752C4:
    // 0x800752C4: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800752C8: bne         $s1, $at, L_800752DC
    if (ctx->r17 != ctx->r1) {
        // 0x800752CC: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800752DC;
    }
    // 0x800752CC: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800752D0: bne         $v0, $at, L_800752DC
    if (ctx->r2 != ctx->r1) {
        // 0x800752D4: nop
    
            goto L_800752DC;
    }
    // 0x800752D4: nop

    // 0x800752D8: break       6
    do_break(2147963608);
L_800752DC:
    // 0x800752DC: mfhi        $v1
    ctx->r3 = hi;
    // 0x800752E0: addiu       $s1, $sp, 0x50
    ctx->r17 = ADD32(ctx->r29, 0X50);
    // 0x800752E4: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x800752E8: addu        $v1, $s5, $v1
    ctx->r3 = ADD32(ctx->r21, ctx->r3);
    // 0x800752EC: mtc1        $v1, $f6
    ctx->f6.u32l = ctx->r3;
    // 0x800752F0: cvt.s.w     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800752F4: mfc1        $a2, $f6
    ctx->r6 = (int32_t)ctx->f6.u32l;
    // 0x800752F8: jal         0x8001D240
    // 0x800752FC: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    func_8001D240(rdram, ctx);
        goto after_3;
    // 0x800752FC: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    after_3:
    // 0x80075300: jal         0x80003430
    // 0x80075304: nop

    rand_recomp(rdram, ctx);
        goto after_4;
    // 0x80075304: nop

    after_4:
    // 0x80075308: addiu       $s0, $sp, 0x60
    ctx->r16 = ADD32(ctx->r29, 0X60);
    // 0x8007530C: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x80075310: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x80075314: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x80075318: mtc1        $v0, $f6
    ctx->f6.u32l = ctx->r2;
    // 0x8007531C: cvt.s.w     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80075320: mfc1        $a2, $f6
    ctx->r6 = (int32_t)ctx->f6.u32l;
    // 0x80075324: jal         0x8001D240
    // 0x80075328: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    func_8001D240(rdram, ctx);
        goto after_5;
    // 0x80075328: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    after_5:
    // 0x8007532C: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x80075330: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    // 0x80075334: jal         0x8001D2C0
    // 0x80075338: addiu       $a2, $sp, 0x40
    ctx->r6 = ADD32(ctx->r29, 0X40);
    func_8001D2C0(rdram, ctx);
        goto after_6;
    // 0x80075338: addiu       $a2, $sp, 0x40
    ctx->r6 = ADD32(ctx->r29, 0X40);
    after_6:
    // 0x8007533C: addiu       $a0, $sp, 0x40
    ctx->r4 = ADD32(ctx->r29, 0X40);
L_80075340:
    // 0x80075340: j           L_80075534
    // 0x80075344: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
        goto L_80075534;
    // 0x80075344: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
L_80075348:
    // 0x80075348: bne         $s1, $zero, L_8007548C
    if (ctx->r17 != 0) {
        // 0x8007534C: addiu       $s3, $sp, 0x70
        ctx->r19 = ADD32(ctx->r29, 0X70);
            goto L_8007548C;
    }
    // 0x8007534C: addiu       $s3, $sp, 0x70
    ctx->r19 = ADD32(ctx->r29, 0X70);
    // 0x80075350: addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    // 0x80075354: addiu       $s4, $sp, 0x28
    ctx->r20 = ADD32(ctx->r29, 0X28);
    // 0x80075358: addu        $a1, $s4, $zero
    ctx->r5 = ADD32(ctx->r20, 0);
    // 0x8007535C: addiu       $s2, $sp, 0x1C
    ctx->r18 = ADD32(ctx->r29, 0X1C);
    // 0x80075360: lui         $v0, 0x8004
    ctx->r2 = S32(0X8004 << 16);
    // 0x80075364: addiu       $t3, $v0, -0x2EA4
    ctx->r11 = ADD32(ctx->r2, -0X2EA4);
    // 0x80075368: lw          $t0, 0x0($t3)
    ctx->r8 = MEM_W(ctx->r11, 0X0);
    // 0x8007536C: lw          $t1, 0x4($t3)
    ctx->r9 = MEM_W(ctx->r11, 0X4);
    // 0x80075370: lw          $t2, 0x8($t3)
    ctx->r10 = MEM_W(ctx->r11, 0X8);
    // 0x80075374: sw          $t0, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r8;
    // 0x80075378: sw          $t1, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r9;
    // 0x8007537C: sw          $t2, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r10;
    // 0x80075380: jal         0x80019548
    // 0x80075384: addu        $a2, $s2, $zero
    ctx->r6 = ADD32(ctx->r18, 0);
    func_80019548(rdram, ctx);
        goto after_7;
    // 0x80075384: addu        $a2, $s2, $zero
    ctx->r6 = ADD32(ctx->r18, 0);
    after_7:
    // 0x80075388: addiu       $s1, $sp, 0x90
    ctx->r17 = ADD32(ctx->r29, 0X90);
    // 0x8007538C: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x80075390: addiu       $s0, $sp, 0x80
    ctx->r16 = ADD32(ctx->r29, 0X80);
    // 0x80075394: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x80075398: jal         0x80019548
    // 0x8007539C: addu        $a2, $s2, $zero
    ctx->r6 = ADD32(ctx->r18, 0);
    func_80019548(rdram, ctx);
        goto after_8;
    // 0x8007539C: addu        $a2, $s2, $zero
    ctx->r6 = ADD32(ctx->r18, 0);
    after_8:
    // 0x800753A0: jal         0x8001CF2C
    // 0x800753A4: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    func_8001CF2C(rdram, ctx);
        goto after_9;
    // 0x800753A4: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    after_9:
    // 0x800753A8: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x800753AC: lwc1        $f20, -0x2E98($at)
    ctx->f20.u32l = MEM_W(ctx->r1, -0X2E98);
    // 0x800753B0: mov.s       $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    ctx->f4.fl = ctx->f0.fl;
    // 0x800753B4: c.lt.s      $f20, $f4
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f20.fl < ctx->f4.fl;
    // 0x800753B8: nop

    // 0x800753BC: bc1f        L_80075444
    if (!c1cs) {
        // 0x800753C0: addu        $a1, $s2, $zero
        ctx->r5 = ADD32(ctx->r18, 0);
            goto L_80075444;
    }
    // 0x800753C0: addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    // 0x800753C4: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x800753C8: addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    // 0x800753CC: lwc1        $f0, 0x90($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X90);
    // 0x800753D0: lwc1        $f2, 0x98($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X98);
    // 0x800753D4: div.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f4.fl);
    // 0x800753D8: swc1        $f0, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->f0.u32l;
    // 0x800753DC: lwc1        $f0, 0x94($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X94);
    // 0x800753E0: div.s       $f2, $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = DIV_S(ctx->f2.fl, ctx->f4.fl);
    // 0x800753E4: swc1        $f2, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->f2.u32l;
    // 0x800753E8: div.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f4.fl);
    // 0x800753EC: jal         0x80019548
    // 0x800753F0: swc1        $f0, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->f0.u32l;
    func_80019548(rdram, ctx);
        goto after_10;
    // 0x800753F0: swc1        $f0, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->f0.u32l;
    after_10:
    // 0x800753F4: jal         0x8001CF58
    // 0x800753F8: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    normalize_vector(rdram, ctx);
        goto after_11;
    // 0x800753F8: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_11:
    // 0x800753FC: addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    // 0x80075400: jal         0x8001CFE8
    // 0x80075404: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    func_8001CFE8(rdram, ctx);
        goto after_12;
    // 0x80075404: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    after_12:
    // 0x80075408: jal         0x8001C400
    // 0x8007540C: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    func_8001C400(rdram, ctx);
        goto after_13;
    // 0x8007540C: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    after_13:
    // 0x80075410: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80075414: lwc1        $f2, -0x2E94($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X2E94);
    // 0x80075418: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
    // 0x8007541C: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x80075420: addiu       $s0, $sp, 0x40
    ctx->r16 = ADD32(ctx->r29, 0X40);
    // 0x80075424: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x80075428: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8007542C: jal         0x8001D240
    // 0x80075430: addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    func_8001D240(rdram, ctx);
        goto after_14;
    // 0x80075430: addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    after_14:
    // 0x80075434: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x80075438: addu        $a1, $s4, $zero
    ctx->r5 = ADD32(ctx->r20, 0);
    // 0x8007543C: jal         0x8001D3C4
    // 0x80075440: addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    func_8001D3C4(rdram, ctx);
        goto after_15;
    // 0x80075440: addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    after_15:
L_80075444:
    // 0x80075444: addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    // 0x80075448: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    // 0x8007544C: jal         0x80019548
    // 0x80075450: addu        $a2, $s2, $zero
    ctx->r6 = ADD32(ctx->r18, 0);
    func_80019548(rdram, ctx);
        goto after_16;
    // 0x80075450: addu        $a2, $s2, $zero
    ctx->r6 = ADD32(ctx->r18, 0);
    after_16:
    // 0x80075454: jal         0x8001CF2C
    // 0x80075458: addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    func_8001CF2C(rdram, ctx);
        goto after_17;
    // 0x80075458: addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    after_17:
    // 0x8007545C: c.lt.s      $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f20.fl < ctx->f0.fl;
    // 0x80075460: nop

    // 0x80075464: bc1f        L_8007553C
    if (!c1cs) {
        // 0x80075468: addiu       $s0, $sp, 0x40
        ctx->r16 = ADD32(ctx->r29, 0X40);
            goto L_8007553C;
    }
    // 0x80075468: addiu       $s0, $sp, 0x40
    ctx->r16 = ADD32(ctx->r29, 0X40);
    // 0x8007546C: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x80075470: mtc1        $s5, $f6
    ctx->f6.u32l = ctx->r21;
    // 0x80075474: cvt.s.w     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80075478: mfc1        $a2, $f6
    ctx->r6 = (int32_t)ctx->f6.u32l;
    // 0x8007547C: jal         0x8001D144
    // 0x80075480: addu        $a1, $s3, $zero
    ctx->r5 = ADD32(ctx->r19, 0);
    func_8001D144(rdram, ctx);
        goto after_18;
    // 0x80075480: addu        $a1, $s3, $zero
    ctx->r5 = ADD32(ctx->r19, 0);
    after_18:
    // 0x80075484: j           L_80075530
    // 0x80075488: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
        goto L_80075530;
    // 0x80075488: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
L_8007548C:
    // 0x8007548C: jal         0x80003430
    // 0x80075490: nop

    rand_recomp(rdram, ctx);
        goto after_19;
    // 0x80075490: nop

    after_19:
    // 0x80075494: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x80075498: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x8007549C: div         $zero, $v0, $s1
    if (S32(ctx->r17) != 0) { lo = S32(S64(S32(ctx->r2)) / S64(S32(ctx->r17))); hi = S32(S64(S32(ctx->r2)) % S64(S32(ctx->r17))); } else { lo = 0; hi = S32(ctx->r2); }
    // 0x800754A0: bne         $s1, $zero, L_800754AC
    if (ctx->r17 != 0) {
        // 0x800754A4: nop
    
            goto L_800754AC;
    }
    // 0x800754A4: nop

    // 0x800754A8: break       7
    do_break(2147964072);
L_800754AC:
    // 0x800754AC: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800754B0: bne         $s1, $at, L_800754C4
    if (ctx->r17 != ctx->r1) {
        // 0x800754B4: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800754C4;
    }
    // 0x800754B4: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800754B8: bne         $v0, $at, L_800754C4
    if (ctx->r2 != ctx->r1) {
        // 0x800754BC: nop
    
            goto L_800754C4;
    }
    // 0x800754BC: nop

    // 0x800754C0: break       6
    do_break(2147964096);
L_800754C4:
    // 0x800754C4: mfhi        $v1
    ctx->r3 = hi;
    // 0x800754C8: addiu       $s2, $sp, 0x50
    ctx->r18 = ADD32(ctx->r29, 0X50);
    // 0x800754CC: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // 0x800754D0: addu        $v1, $s5, $v1
    ctx->r3 = ADD32(ctx->r21, ctx->r3);
    // 0x800754D4: mtc1        $v1, $f6
    ctx->f6.u32l = ctx->r3;
    // 0x800754D8: cvt.s.w     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800754DC: mfc1        $a2, $f6
    ctx->r6 = (int32_t)ctx->f6.u32l;
    // 0x800754E0: jal         0x8001D240
    // 0x800754E4: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    func_8001D240(rdram, ctx);
        goto after_20;
    // 0x800754E4: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    after_20:
    // 0x800754E8: jal         0x80003430
    // 0x800754EC: nop

    rand_recomp(rdram, ctx);
        goto after_21;
    // 0x800754EC: nop

    after_21:
    // 0x800754F0: addiu       $s0, $sp, 0x60
    ctx->r16 = ADD32(ctx->r29, 0X60);
    // 0x800754F4: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x800754F8: addiu       $s1, $sp, 0x28
    ctx->r17 = ADD32(ctx->r29, 0X28);
    // 0x800754FC: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x80075500: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x80075504: mtc1        $v0, $f6
    ctx->f6.u32l = ctx->r2;
    // 0x80075508: cvt.s.w     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8007550C: mfc1        $a2, $f6
    ctx->r6 = (int32_t)ctx->f6.u32l;
    // 0x80075510: jal         0x8001D240
    // 0x80075514: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    func_8001D240(rdram, ctx);
        goto after_22;
    // 0x80075514: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    after_22:
    // 0x80075518: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x8007551C: addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    // 0x80075520: addiu       $s0, $sp, 0x40
    ctx->r16 = ADD32(ctx->r29, 0X40);
    // 0x80075524: jal         0x8001D2C0
    // 0x80075528: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    func_8001D2C0(rdram, ctx);
        goto after_23;
    // 0x80075528: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    after_23:
    // 0x8007552C: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
L_80075530:
    // 0x80075530: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
L_80075534:
    // 0x80075534: jal         0x8001D3C4
    // 0x80075538: addu        $a2, $s6, $zero
    ctx->r6 = ADD32(ctx->r22, 0);
    func_8001D3C4(rdram, ctx);
        goto after_24;
    // 0x80075538: addu        $a2, $s6, $zero
    ctx->r6 = ADD32(ctx->r22, 0);
    after_24:
L_8007553C:
    // 0x8007553C: beq         $s7, $zero, L_80075568
    if (ctx->r23 == 0) {
        // 0x80075540: nop
    
            goto L_80075568;
    }
    // 0x80075540: nop

    // 0x80075544: lwc1        $f0, 0x0($s6)
    ctx->f0.u32l = MEM_W(ctx->r22, 0X0);
    // 0x80075548: mul.s       $f0, $f0, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f22.fl);
    // 0x8007554C: swc1        $f0, 0x0($s7)
    MEM_W(0X0, ctx->r23) = ctx->f0.u32l;
    // 0x80075550: lwc1        $f0, 0x4($s6)
    ctx->f0.u32l = MEM_W(ctx->r22, 0X4);
    // 0x80075554: mul.s       $f0, $f0, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f22.fl);
    // 0x80075558: swc1        $f0, 0x4($s7)
    MEM_W(0X4, ctx->r23) = ctx->f0.u32l;
    // 0x8007555C: lwc1        $f0, 0x8($s6)
    ctx->f0.u32l = MEM_W(ctx->r22, 0X8);
    // 0x80075560: mul.s       $f0, $f0, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f22.fl);
    // 0x80075564: swc1        $f0, 0x8($s7)
    MEM_W(0X8, ctx->r23) = ctx->f0.u32l;
L_80075568:
    // 0x80075568: lw          $ra, 0xC0($sp)
    ctx->r31 = MEM_W(ctx->r29, 0XC0);
    // 0x8007556C: lw          $s7, 0xBC($sp)
    ctx->r23 = MEM_W(ctx->r29, 0XBC);
    // 0x80075570: lw          $s6, 0xB8($sp)
    ctx->r22 = MEM_W(ctx->r29, 0XB8);
    // 0x80075574: lw          $s5, 0xB4($sp)
    ctx->r21 = MEM_W(ctx->r29, 0XB4);
    // 0x80075578: lw          $s4, 0xB0($sp)
    ctx->r20 = MEM_W(ctx->r29, 0XB0);
    // 0x8007557C: lw          $s3, 0xAC($sp)
    ctx->r19 = MEM_W(ctx->r29, 0XAC);
    // 0x80075580: lw          $s2, 0xA8($sp)
    ctx->r18 = MEM_W(ctx->r29, 0XA8);
    // 0x80075584: lw          $s1, 0xA4($sp)
    ctx->r17 = MEM_W(ctx->r29, 0XA4);
    // 0x80075588: lw          $s0, 0xA0($sp)
    ctx->r16 = MEM_W(ctx->r29, 0XA0);
    // 0x8007558C: ldc1        $f22, 0xD0($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0XD0);
    // 0x80075590: ldc1        $f20, 0xC8($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0XC8);
    // 0x80075594: jr          $ra
    // 0x80075598: addiu       $sp, $sp, 0xD8
    ctx->r29 = ADD32(ctx->r29, 0XD8);
    return;
    // 0x80075598: addiu       $sp, $sp, 0xD8
    ctx->r29 = ADD32(ctx->r29, 0XD8);
;}
RECOMP_FUNC void func_8007559C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007559C: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x800755A0: sw          $s1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r17;
    // 0x800755A4: addu        $s1, $a0, $zero
    ctx->r17 = ADD32(ctx->r4, 0);
    // 0x800755A8: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x800755AC: sdc1        $f20, 0x58($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X58, ctx->r29);
    // 0x800755B0: mtc1        $a1, $f20
    ctx->f20.u32l = ctx->r5;
    // 0x800755B4: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x800755B8: lwc1        $f2, -0x2E8C($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X2E8C);
    // 0x800755BC: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    // 0x800755C0: sdc1        $f22, 0x60($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X60, ctx->r29);
    // 0x800755C4: mul.s       $f2, $f20, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = MUL_S(ctx->f20.fl, ctx->f2.fl);
    // 0x800755C8: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x800755CC: lwc1        $f22, -0x2E88($at)
    ctx->f22.u32l = MEM_W(ctx->r1, -0X2E88);
    // 0x800755D0: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // 0x800755D4: sw          $s0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r16;
    // 0x800755D8: addiu       $s0, $sp, 0x20
    ctx->r16 = ADD32(ctx->r29, 0X20);
    // 0x800755DC: mul.s       $f22, $f20, $f22
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f22.fl = MUL_S(ctx->f20.fl, ctx->f22.fl);
    // 0x800755E0: addu        $a3, $s0, $zero
    ctx->r7 = ADD32(ctx->r16, 0);
    // 0x800755E4: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x800755E8: lwc1        $f0, -0x2E84($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X2E84);
    // 0x800755EC: lui         $v0, 0x8004
    ctx->r2 = S32(0X8004 << 16);
    // 0x800755F0: sw          $ra, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r31;
    // 0x800755F4: mul.s       $f0, $f20, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = MUL_S(ctx->f20.fl, ctx->f0.fl);
    // 0x800755F8: addiu       $t2, $v0, -0x2E90
    ctx->r10 = ADD32(ctx->r2, -0X2E90);
    // 0x800755FC: lwl         $v1, 0x0($t2)
    ctx->r3 = do_lwl(rdram, ctx->r3, ctx->r10, 0X0);
    // 0x80075600: lwr         $v1, 0x3($t2)
    ctx->r3 = do_lwr(rdram, ctx->r3, ctx->r10, 0X3);
    // 0x80075604: swl         $v1, 0x20($sp)
    do_swl(rdram, 0X20, ctx->r29, ctx->r3);
    // 0x80075608: swr         $v1, 0x23($sp)
    do_swr(rdram, 0X23, ctx->r29, ctx->r3);
    // 0x8007560C: swc1        $f2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f2.u32l;
    // 0x80075610: swc1        $f22, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f22.u32l;
    // 0x80075614: swc1        $f22, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f22.u32l;
    // 0x80075618: jal         0x80072684
    // 0x8007561C: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    func_80072684(rdram, ctx);
        goto after_0;
    // 0x8007561C: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    after_0:
    // 0x80075620: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80075624: lwc1        $f4, -0x2E80($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X2E80);
    // 0x80075628: mul.s       $f4, $f20, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f4.fl = MUL_S(ctx->f20.fl, ctx->f4.fl);
    // 0x8007562C: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80075630: lwc1        $f2, -0x2E7C($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X2E7C);
    // 0x80075634: mul.s       $f2, $f20, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = MUL_S(ctx->f20.fl, ctx->f2.fl);
    // 0x80075638: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8007563C: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    // 0x80075640: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80075644: lwc1        $f0, -0x2E78($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X2E78);
    // 0x80075648: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // 0x8007564C: mul.s       $f20, $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f20.fl = MUL_S(ctx->f20.fl, ctx->f0.fl);
    // 0x80075650: addu        $a3, $s0, $zero
    ctx->r7 = ADD32(ctx->r16, 0);
    // 0x80075654: swc1        $f22, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f22.u32l;
    // 0x80075658: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x8007565C: swc1        $f2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f2.u32l;
    // 0x80075660: jal         0x80072684
    // 0x80075664: swc1        $f20, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f20.u32l;
    func_80072684(rdram, ctx);
        goto after_1;
    // 0x80075664: swc1        $f20, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f20.u32l;
    after_1:
    // 0x80075668: lui         $a2, 0x8014
    ctx->r6 = S32(0X8014 << 16);
    // 0x8007566C: addiu       $a2, $a2, -0x7FA8
    ctx->r6 = ADD32(ctx->r6, -0X7FA8);
    // 0x80075670: lwc1        $f12, 0x0($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X0);
    // 0x80075674: lwc1        $f14, 0x8($s1)
    ctx->f14.u32l = MEM_W(ctx->r17, 0X8);
    // 0x80075678: jal         0x80067D90
    // 0x8007567C: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    func_80067D90(rdram, ctx);
        goto after_2;
    // 0x8007567C: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    after_2:
    // 0x80075680: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80075684: lwc1        $f2, -0x2E74($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X2E74);
    // 0x80075688: sub.s       $f2, $f0, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x8007568C: lwc1        $f0, 0x4($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X4);
    // 0x80075690: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x80075694: nop

    // 0x80075698: bc1f        L_80075704
    if (!c1cs) {
        // 0x8007569C: lui         $a0, 0x8005
        ctx->r4 = S32(0X8005 << 16);
            goto L_80075704;
    }
    // 0x8007569C: lui         $a0, 0x8005
    ctx->r4 = S32(0X8005 << 16);
    // 0x800756A0: addiu       $a0, $a0, -0x3938
    ctx->r4 = ADD32(ctx->r4, -0X3938);
    // 0x800756A4: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    // 0x800756A8: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x800756AC: lwc1        $f0, 0x0($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X0);
    // 0x800756B0: lw          $v0, -0x68C0($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X68C0);
    // 0x800756B4: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x800756B8: swc1        $f2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f2.u32l;
    // 0x800756BC: swc1        $f0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f0.u32l;
    // 0x800756C0: lwc1        $f2, 0x8($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0X8);
    // 0x800756C4: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x800756C8: lwc1        $f0, -0x2E70($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X2E70);
    // 0x800756CC: addiu       $a3, $zero, 0xF
    ctx->r7 = ADD32(0, 0XF);
    // 0x800756D0: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
    // 0x800756D4: addiu       $v0, $zero, 0x30
    ctx->r2 = ADD32(0, 0X30);
    // 0x800756D8: sb          $v0, 0x40($sp)
    MEM_B(0X40, ctx->r29) = ctx->r2;
    // 0x800756DC: addiu       $v0, $zero, 0x40
    ctx->r2 = ADD32(0, 0X40);
    // 0x800756E0: sb          $v0, 0x41($sp)
    MEM_B(0X41, ctx->r29) = ctx->r2;
    // 0x800756E4: swc1        $f0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f0.u32l;
    // 0x800756E8: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x800756EC: lwc1        $f0, -0x2E6C($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X2E6C);
    // 0x800756F0: addiu       $v0, $zero, 0x300
    ctx->r2 = ADD32(0, 0X300);
    // 0x800756F4: sh          $v0, 0x38($sp)
    MEM_H(0X38, ctx->r29) = ctx->r2;
    // 0x800756F8: swc1        $f2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f2.u32l;
    // 0x800756FC: jal         0x8003FFEC
    // 0x80075700: swc1        $f0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f0.u32l;
    func_8003FFEC(rdram, ctx);
        goto after_3;
    // 0x80075700: swc1        $f0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f0.u32l;
    after_3:
L_80075704:
    // 0x80075704: lw          $ra, 0x50($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X50);
    // 0x80075708: lw          $s1, 0x4C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X4C);
    // 0x8007570C: lw          $s0, 0x48($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X48);
    // 0x80075710: ldc1        $f22, 0x60($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X60);
    // 0x80075714: ldc1        $f20, 0x58($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X58);
    // 0x80075718: jr          $ra
    // 0x8007571C: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    return;
    // 0x8007571C: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
;}
RECOMP_FUNC void func_80075720(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80075720: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x80075724: addu        $v1, $a0, $zero
    ctx->r3 = ADD32(ctx->r4, 0);
    // 0x80075728: sw          $s2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r18;
    // 0x8007572C: andi        $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 & 0XFFFF;
    // 0x80075730: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x80075734: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x80075738: sw          $s1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r17;
    // 0x8007573C: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x80075740: sdc1        $f26, 0x50($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X50, ctx->r29);
    // 0x80075744: sdc1        $f24, 0x48($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X48, ctx->r29);
    // 0x80075748: sdc1        $f22, 0x40($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X40, ctx->r29);
    // 0x8007574C: sdc1        $f20, 0x38($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X38, ctx->r29);
    // 0x80075750: lw          $s0, 0x4($v1)
    ctx->r16 = MEM_W(ctx->r3, 0X4);
    // 0x80075754: beq         $a1, $v0, L_80075B84
    if (ctx->r5 == ctx->r2) {
        // 0x80075758: addu        $s2, $a2, $zero
        ctx->r18 = ADD32(ctx->r6, 0);
            goto L_80075B84;
    }
    // 0x80075758: addu        $s2, $a2, $zero
    ctx->r18 = ADD32(ctx->r6, 0);
    // 0x8007575C: slti        $v0, $a1, 0x3
    ctx->r2 = SIGNED(ctx->r5) < 0X3 ? 1 : 0;
    // 0x80075760: beq         $v0, $zero, L_80075778
    if (ctx->r2 == 0) {
        // 0x80075764: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80075778;
    }
    // 0x80075764: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80075768: beq         $a1, $v0, L_80075794
    if (ctx->r5 == ctx->r2) {
        // 0x8007576C: addiu       $v0, $zero, 0x301
        ctx->r2 = ADD32(0, 0X301);
            goto L_80075794;
    }
    // 0x8007576C: addiu       $v0, $zero, 0x301
    ctx->r2 = ADD32(0, 0X301);
    // 0x80075770: j           L_80075B88
    // 0x80075774: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80075B88;
    // 0x80075774: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80075778:
    // 0x80075778: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x8007577C: beq         $a1, $v0, L_80075890
    if (ctx->r5 == ctx->r2) {
        // 0x80075780: addiu       $v0, $zero, 0x4
        ctx->r2 = ADD32(0, 0X4);
            goto L_80075890;
    }
    // 0x80075780: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // 0x80075784: beq         $a1, $v0, L_80075AC8
    if (ctx->r5 == ctx->r2) {
        // 0x80075788: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80075AC8;
    }
    // 0x80075788: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8007578C: j           L_80075B88
    // 0x80075790: nop

        goto L_80075B88;
    // 0x80075790: nop

L_80075794:
    // 0x80075794: sh          $v0, 0x10($s0)
    MEM_H(0X10, ctx->r16) = ctx->r2;
    // 0x80075798: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // 0x8007579C: sb          $v0, 0x2C($s0)
    MEM_B(0X2C, ctx->r16) = ctx->r2;
    // 0x800757A0: sb          $v0, 0x2D($s0)
    MEM_B(0X2D, ctx->r16) = ctx->r2;
    // 0x800757A4: sb          $v0, 0x2E($s0)
    MEM_B(0X2E, ctx->r16) = ctx->r2;
    // 0x800757A8: sb          $v0, 0x2F($s0)
    MEM_B(0X2F, ctx->r16) = ctx->r2;
    // 0x800757AC: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800757B0: sh          $zero, 0xC($s0)
    MEM_H(0XC, ctx->r16) = 0;
    // 0x800757B4: sh          $zero, 0xA($s0)
    MEM_H(0XA, ctx->r16) = 0;
    // 0x800757B8: sh          $zero, 0x8($s0)
    MEM_H(0X8, ctx->r16) = 0;
    // 0x800757BC: sh          $zero, 0x2A($s0)
    MEM_H(0X2A, ctx->r16) = 0;
    // 0x800757C0: sh          $zero, 0x28($s0)
    MEM_H(0X28, ctx->r16) = 0;
    // 0x800757C4: sw          $zero, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = 0;
    // 0x800757C8: lwc1        $f0, 0x4($s2)
    ctx->f0.u32l = MEM_W(ctx->r18, 0X4);
    // 0x800757CC: lw          $v0, 0xC08($v0)
    ctx->r2 = MEM_W(ctx->r2, 0XC08);
    // 0x800757D0: swc1        $f0, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = ctx->f0.u32l;
    // 0x800757D4: lwc1        $f0, 0x10($s2)
    ctx->f0.u32l = MEM_W(ctx->r18, 0X10);
    // 0x800757D8: swc1        $f0, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->f0.u32l;
    // 0x800757DC: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x800757E0: lwc1        $f0, -0x2E68($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X2E68);
    // 0x800757E4: lhu         $v0, 0x20($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X20);
    // 0x800757E8: swc1        $f0, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->f0.u32l;
    // 0x800757EC: swc1        $f0, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f0.u32l;
    // 0x800757F0: sh          $v0, 0x12($s0)
    MEM_H(0X12, ctx->r16) = ctx->r2;
    // 0x800757F4: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x800757F8: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x800757FC: lwc1        $f0, -0x2E64($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X2E64);
    // 0x80075800: lw          $t0, 0x0($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X0);
    // 0x80075804: lw          $t1, 0x4($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X4);
    // 0x80075808: lw          $t2, 0x8($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X8);
    // 0x8007580C: sw          $t0, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->r8;
    // 0x80075810: sw          $t1, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->r9;
    // 0x80075814: sw          $t2, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->r10;
    // 0x80075818: sw          $zero, 0x60($s0)
    MEM_W(0X60, ctx->r16) = 0;
    // 0x8007581C: lwc1        $f2, 0xC($s2)
    ctx->f2.u32l = MEM_W(ctx->r18, 0XC);
    // 0x80075820: swc1        $f0, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f0.u32l;
    // 0x80075824: swc1        $f0, 0x5C($s0)
    MEM_W(0X5C, ctx->r16) = ctx->f0.u32l;
    // 0x80075828: swc1        $f2, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->f2.u32l;
    // 0x8007582C: lwc1        $f0, 0x8($s2)
    ctx->f0.u32l = MEM_W(ctx->r18, 0X8);
    // 0x80075830: lwc1        $f2, 0x4($s2)
    ctx->f2.u32l = MEM_W(ctx->r18, 0X4);
    // 0x80075834: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x80075838: swc1        $f0, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f0.u32l;
    // 0x8007583C: lwc1        $f0, 0x1C($s2)
    ctx->f0.u32l = MEM_W(ctx->r18, 0X1C);
    // 0x80075840: swc1        $f0, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->f0.u32l;
    // 0x80075844: lwc1        $f0, 0x14($s2)
    ctx->f0.u32l = MEM_W(ctx->r18, 0X14);
    // 0x80075848: swc1        $f0, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->f0.u32l;
    // 0x8007584C: lwc1        $f0, 0x18($s2)
    ctx->f0.u32l = MEM_W(ctx->r18, 0X18);
    // 0x80075850: swc1        $f0, 0x4C($s0)
    MEM_W(0X4C, ctx->r16) = ctx->f0.u32l;
    // 0x80075854: lwc1        $f2, 0x20($s2)
    ctx->f2.u32l = MEM_W(ctx->r18, 0X20);
    // 0x80075858: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8007585C: c.eq.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl == ctx->f0.fl;
    // 0x80075860: nop

    // 0x80075864: bc1f        L_80075878
    if (!c1cs) {
        // 0x80075868: swc1        $f2, 0x64($s0)
        MEM_W(0X64, ctx->r16) = ctx->f2.u32l;
            goto L_80075878;
    }
    // 0x80075868: swc1        $f2, 0x64($s0)
    MEM_W(0X64, ctx->r16) = ctx->f2.u32l;
    // 0x8007586C: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80075870: lwc1        $f0, -0x2E60($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X2E60);
    // 0x80075874: swc1        $f0, 0x64($s0)
    MEM_W(0X64, ctx->r16) = ctx->f0.u32l;
L_80075878:
    // 0x80075878: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x8007587C: lhu         $a0, -0x6A8C($v0)
    ctx->r4 = MEM_HU(ctx->r2, -0X6A8C);
    // 0x80075880: jal         0x8003E684
    // 0x80075884: addu        $a1, $v1, $zero
    ctx->r5 = ADD32(ctx->r3, 0);
    func_8003E684(rdram, ctx);
        goto after_0;
    // 0x80075884: addu        $a1, $v1, $zero
    ctx->r5 = ADD32(ctx->r3, 0);
    after_0:
    // 0x80075888: j           L_80075B88
    // 0x8007588C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80075B88;
    // 0x8007588C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80075890:
    // 0x80075890: lwc1        $f26, 0x0($s2)
    ctx->f26.u32l = MEM_W(ctx->r18, 0X0);
    // 0x80075894: lwc1        $f0, 0x40($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X40);
    // 0x80075898: mul.s       $f0, $f0, $f26
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f26.fl);
    // 0x8007589C: lwc1        $f2, 0x60($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X60);
    // 0x800758A0: add.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x800758A4: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x800758A8: lwc1        $f24, -0x2E5C($at)
    ctx->f24.u32l = MEM_W(ctx->r1, -0X2E5C);
    // 0x800758AC: c.lt.s      $f2, $f24
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 24);
    c1cs = ctx->f2.fl < ctx->f24.fl;
    // 0x800758B0: nop

    // 0x800758B4: bc1f        L_80075AB4
    if (!c1cs) {
        // 0x800758B8: swc1        $f2, 0x60($s0)
        MEM_W(0X60, ctx->r16) = ctx->f2.u32l;
            goto L_80075AB4;
    }
    // 0x800758B8: swc1        $f2, 0x60($s0)
    MEM_W(0X60, ctx->r16) = ctx->f2.u32l;
    // 0x800758BC: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x800758C0: lwc1        $f22, -0x2E58($at)
    ctx->f22.u32l = MEM_W(ctx->r1, -0X2E58);
    // 0x800758C4: mul.s       $f12, $f2, $f22
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f12.fl = MUL_S(ctx->f2.fl, ctx->f22.fl);
    // 0x800758C8: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x800758CC: lwc1        $f20, -0x2E54($at)
    ctx->f20.u32l = MEM_W(ctx->r1, -0X2E54);
    // 0x800758D0: mul.s       $f12, $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f12.fl = MUL_S(ctx->f12.fl, ctx->f20.fl);
    // 0x800758D4: jal         0x8002B190
    // 0x800758D8: nop

    cosf_recomp(rdram, ctx);
        goto after_1;
    // 0x800758D8: nop

    after_1:
    // 0x800758DC: lwc1        $f12, 0x60($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X60);
    // 0x800758E0: mul.s       $f12, $f12, $f22
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f12.fl = MUL_S(ctx->f12.fl, ctx->f22.fl);
    // 0x800758E4: sub.s       $f0, $f24, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f24.fl - ctx->f0.fl;
    // 0x800758E8: lwc1        $f2, 0x54($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X54);
    // 0x800758EC: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x800758F0: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x800758F4: lwc1        $f4, -0x2E50($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X2E50);
    // 0x800758F8: lwc1        $f2, 0x44($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X44);
    // 0x800758FC: mul.s       $f2, $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f4.fl);
    // 0x80075900: nop

    // 0x80075904: mul.s       $f12, $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f12.fl = MUL_S(ctx->f12.fl, ctx->f20.fl);
    // 0x80075908: nop

    // 0x8007590C: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x80075910: lwc1        $f2, 0x48($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X48);
    // 0x80075914: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x80075918: lwc1        $f2, 0x3C($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X3C);
    // 0x8007591C: add.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x80075920: jal         0x8002B190
    // 0x80075924: swc1        $f2, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f2.u32l;
    cosf_recomp(rdram, ctx);
        goto after_2;
    // 0x80075924: swc1        $f2, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f2.u32l;
    after_2:
    // 0x80075928: sub.s       $f0, $f24, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f24.fl - ctx->f0.fl;
    // 0x8007592C: lwc1        $f2, 0x54($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X54);
    // 0x80075930: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x80075934: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80075938: lwc1        $f4, -0x2E4C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X2E4C);
    // 0x8007593C: lwc1        $f2, 0x44($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X44);
    // 0x80075940: mul.s       $f2, $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f4.fl);
    // 0x80075944: nop

    // 0x80075948: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x8007594C: lwc1        $f2, 0x4C($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X4C);
    // 0x80075950: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x80075954: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80075958: lwc1        $f6, -0x2E48($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X2E48);
    // 0x8007595C: lwc1        $f2, 0x3C($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X3C);
    // 0x80075960: lwc1        $f4, 0x58($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X58);
    // 0x80075964: add.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x80075968: swc1        $f4, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->f4.u32l;
    // 0x8007596C: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x80075970: nop

    // 0x80075974: bc1f        L_80075980
    if (!c1cs) {
        // 0x80075978: swc1        $f2, 0x5C($s0)
        MEM_W(0X5C, ctx->r16) = ctx->f2.u32l;
            goto L_80075980;
    }
    // 0x80075978: swc1        $f2, 0x5C($s0)
    MEM_W(0X5C, ctx->r16) = ctx->f2.u32l;
    // 0x8007597C: swc1        $f6, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->f6.u32l;
L_80075980:
    // 0x80075980: lwc1        $f0, 0x5C($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X5C);
    // 0x80075984: c.lt.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl < ctx->f6.fl;
    // 0x80075988: nop

    // 0x8007598C: bc1f        L_80075998
    if (!c1cs) {
        // 0x80075990: swc1        $f0, 0x24($s0)
        MEM_W(0X24, ctx->r16) = ctx->f0.u32l;
            goto L_80075998;
    }
    // 0x80075990: swc1        $f0, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f0.u32l;
    // 0x80075994: swc1        $f6, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f6.u32l;
L_80075998:
    // 0x80075998: lwc1        $f0, 0x60($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X60);
    // 0x8007599C: lwc1        $f2, 0x64($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X64);
    // 0x800759A0: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x800759A4: nop

    // 0x800759A8: bc1f        L_80075A04
    if (!c1cs) {
        // 0x800759AC: nop
    
            goto L_80075A04;
    }
    // 0x800759AC: nop

    // 0x800759B0: sub.s       $f0, $f24, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f24.fl - ctx->f0.fl;
    // 0x800759B4: div.s       $f2, $f24, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = DIV_S(ctx->f24.fl, ctx->f2.fl);
    // 0x800759B8: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x800759BC: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x800759C0: lwc1        $f2, -0x2E44($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X2E44);
    // 0x800759C4: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x800759C8: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x800759CC: lwc1        $f2, -0x2E40($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X2E40);
    // 0x800759D0: c.le.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl <= ctx->f0.fl;
    // 0x800759D4: nop

    // 0x800759D8: bc1tl       L_800759F0
    if (c1cs) {
        // 0x800759DC: sub.s       $f0, $f0, $f2
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
            goto L_800759F0;
    }
    goto skip_0;
    // 0x800759DC: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    skip_0:
    // 0x800759E0: trunc.w.s   $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    ctx->f8.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800759E4: mfc1        $v1, $f8
    ctx->r3 = (int32_t)ctx->f8.u32l;
    // 0x800759E8: j           L_80075A04
    // 0x800759EC: sb          $v1, 0x2F($s0)
    MEM_B(0X2F, ctx->r16) = ctx->r3;
        goto L_80075A04;
    // 0x800759EC: sb          $v1, 0x2F($s0)
    MEM_B(0X2F, ctx->r16) = ctx->r3;
L_800759F0:
    // 0x800759F0: lui         $v0, 0x8000
    ctx->r2 = S32(0X8000 << 16);
    // 0x800759F4: trunc.w.s   $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    ctx->f8.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800759F8: mfc1        $v1, $f8
    ctx->r3 = (int32_t)ctx->f8.u32l;
    // 0x800759FC: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x80075A00: sb          $v1, 0x2F($s0)
    MEM_B(0X2F, ctx->r16) = ctx->r3;
L_80075A04:
    // 0x80075A04: lwc1        $f2, 0x50($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X50);
    // 0x80075A08: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80075A0C: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x80075A10: nop

    // 0x80075A14: bc1f        L_80075B84
    if (!c1cs) {
        // 0x80075A18: lui         $v0, 0x8014
        ctx->r2 = S32(0X8014 << 16);
            goto L_80075B84;
    }
    // 0x80075A18: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x80075A1C: lw          $v0, -0x72E4($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X72E4);
    // 0x80075A20: lwc1        $f0, 0x30($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X30);
    // 0x80075A24: addiu       $v0, $v0, 0x28
    ctx->r2 = ADD32(ctx->r2, 0X28);
    // 0x80075A28: lwc1        $f4, 0x24($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X24);
    // 0x80075A2C: sub.s       $f4, $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f4.fl - ctx->f0.fl;
    // 0x80075A30: swc1        $f4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f4.u32l;
    // 0x80075A34: lwc1        $f0, 0x28($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X28);
    // 0x80075A38: lwc1        $f2, 0x34($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X34);
    // 0x80075A3C: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x80075A40: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    // 0x80075A44: lwc1        $f0, 0x2C($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X2C);
    // 0x80075A48: lwc1        $f2, 0x38($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X38);
    // 0x80075A4C: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x80075A50: swc1        $f0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f0.u32l;
    // 0x80075A54: lwc1        $f0, 0x50($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X50);
    // 0x80075A58: mul.s       $f4, $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x80075A5C: nop

    // 0x80075A60: mul.s       $f4, $f4, $f26
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f4.fl = MUL_S(ctx->f4.fl, ctx->f26.fl);
    // 0x80075A64: lwc1        $f0, 0x30($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X30);
    // 0x80075A68: add.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f4.fl;
    // 0x80075A6C: swc1        $f0, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->f0.u32l;
    // 0x80075A70: lwc1        $f2, 0x1C($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x80075A74: lwc1        $f0, 0x50($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X50);
    // 0x80075A78: mul.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x80075A7C: nop

    // 0x80075A80: mul.s       $f2, $f2, $f26
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f26.fl);
    // 0x80075A84: lwc1        $f0, 0x34($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X34);
    // 0x80075A88: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x80075A8C: swc1        $f0, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->f0.u32l;
    // 0x80075A90: lwc1        $f2, 0x20($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X20);
    // 0x80075A94: lwc1        $f0, 0x50($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X50);
    // 0x80075A98: mul.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x80075A9C: nop

    // 0x80075AA0: mul.s       $f2, $f2, $f26
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f26.fl);
    // 0x80075AA4: lwc1        $f0, 0x38($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X38);
    // 0x80075AA8: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x80075AAC: j           L_80075B84
    // 0x80075AB0: swc1        $f0, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->f0.u32l;
        goto L_80075B84;
    // 0x80075AB0: swc1        $f0, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->f0.u32l;
L_80075AB4:
    // 0x80075AB4: lhu         $a0, 0x16($v1)
    ctx->r4 = MEM_HU(ctx->r3, 0X16);
    // 0x80075AB8: jal         0x8003ED74
    // 0x80075ABC: nop

    func_8003ED74(rdram, ctx);
        goto after_3;
    // 0x80075ABC: nop

    after_3:
    // 0x80075AC0: j           L_80075B88
    // 0x80075AC4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80075B88;
    // 0x80075AC4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80075AC8:
    // 0x80075AC8: addu        $s1, $s2, $zero
    ctx->r17 = ADD32(ctx->r18, 0);
    // 0x80075ACC: lwc1        $f0, 0x5C($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X5C);
    // 0x80075AD0: lwc1        $f2, 0x58($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X58);
    // 0x80075AD4: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x80075AD8: nop

    // 0x80075ADC: bc1f        L_80075AE8
    if (!c1cs) {
        // 0x80075AE0: addiu       $a2, $s0, 0x30
        ctx->r6 = ADD32(ctx->r16, 0X30);
            goto L_80075AE8;
    }
    // 0x80075AE0: addiu       $a2, $s0, 0x30
    ctx->r6 = ADD32(ctx->r16, 0X30);
    // 0x80075AE4: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
L_80075AE8:
    // 0x80075AE8: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80075AEC: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x80075AF0: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x80075AF4: jal         0x8001DC34
    // 0x80075AF8: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    func_8001DC34(rdram, ctx);
        goto after_4;
    // 0x80075AF8: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    after_4:
    // 0x80075AFC: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x80075B00: beq         $v0, $zero, L_80075B88
    if (ctx->r2 == 0) {
        // 0x80075B04: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80075B88;
    }
    // 0x80075B04: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80075B08: lwc1        $f0, 0x30($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X30);
    // 0x80075B0C: lwc1        $f2, 0x18($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0X18);
    // 0x80075B10: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x80075B14: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80075B18: lwc1        $f4, -0x2E3C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X2E3C);
    // 0x80075B1C: mul.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x80075B20: trunc.w.s   $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    ctx->f8.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x80075B24: mfc1        $v0, $f8
    ctx->r2 = (int32_t)ctx->f8.u32l;
    // 0x80075B28: lwc1        $f0, 0x34($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X34);
    // 0x80075B2C: sh          $v0, 0x8($s0)
    MEM_H(0X8, ctx->r16) = ctx->r2;
    // 0x80075B30: lwc1        $f2, 0x1C($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0X1C);
    // 0x80075B34: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x80075B38: mul.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x80075B3C: trunc.w.s   $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    ctx->f8.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x80075B40: mfc1        $v0, $f8
    ctx->r2 = (int32_t)ctx->f8.u32l;
    // 0x80075B44: lwc1        $f0, 0x38($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X38);
    // 0x80075B48: sh          $v0, 0xA($s0)
    MEM_H(0XA, ctx->r16) = ctx->r2;
    // 0x80075B4C: lwc1        $f2, 0x20($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0X20);
    // 0x80075B50: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x80075B54: mul.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x80075B58: trunc.w.s   $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    ctx->f8.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x80075B5C: mfc1        $v0, $f8
    ctx->r2 = (int32_t)ctx->f8.u32l;
    // 0x80075B60: sh          $v0, 0xC($s0)
    MEM_H(0XC, ctx->r16) = ctx->r2;
    // 0x80075B64: lw          $v0, 0x48($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X48);
    // 0x80075B68: lw          $v0, 0x20($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X20);
    // 0x80075B6C: beq         $v0, $zero, L_80075B78
    if (ctx->r2 == 0) {
        // 0x80075B70: sw          $v0, 0x0($s0)
        MEM_W(0X0, ctx->r16) = ctx->r2;
            goto L_80075B78;
    }
    // 0x80075B70: sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
    // 0x80075B74: sw          $s0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r16;
L_80075B78:
    // 0x80075B78: sw          $zero, 0x4($s0)
    MEM_W(0X4, ctx->r16) = 0;
    // 0x80075B7C: lw          $v0, 0x48($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X48);
    // 0x80075B80: sw          $s0, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->r16;
L_80075B84:
    // 0x80075B84: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80075B88:
    // 0x80075B88: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x80075B8C: lw          $s2, 0x30($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X30);
    // 0x80075B90: lw          $s1, 0x2C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X2C);
    // 0x80075B94: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x80075B98: ldc1        $f26, 0x50($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X50);
    // 0x80075B9C: ldc1        $f24, 0x48($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X48);
    // 0x80075BA0: ldc1        $f22, 0x40($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X40);
    // 0x80075BA4: ldc1        $f20, 0x38($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X38);
    // 0x80075BA8: jr          $ra
    // 0x80075BAC: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    return;
    // 0x80075BAC: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
;}
RECOMP_FUNC void func_80075BB0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80075BB0: addiu       $sp, $sp, -0xB8
    ctx->r29 = ADD32(ctx->r29, -0XB8);
    // 0x80075BB4: sw          $s6, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r22;
    // 0x80075BB8: addu        $s6, $a1, $zero
    ctx->r22 = ADD32(ctx->r5, 0);
    // 0x80075BBC: sw          $s5, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r21;
    // 0x80075BC0: addu        $s5, $a2, $zero
    ctx->r21 = ADD32(ctx->r6, 0);
    // 0x80075BC4: sw          $s4, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r20;
    // 0x80075BC8: andi        $s4, $a0, 0xFFFF
    ctx->r20 = ctx->r4 & 0XFFFF;
    // 0x80075BCC: sdc1        $f26, 0xA8($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0XA8, ctx->r29);
    // 0x80075BD0: mtc1        $a3, $f26
    ctx->f26.u32l = ctx->r7;
    // 0x80075BD4: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x80075BD8: sw          $s0, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r16;
    // 0x80075BDC: lw          $s0, -0x72E4($v0)
    ctx->r16 = MEM_W(ctx->r2, -0X72E4);
    // 0x80075BE0: sw          $ra, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->r31;
    // 0x80075BE4: sw          $s3, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r19;
    // 0x80075BE8: sw          $s2, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r18;
    // 0x80075BEC: sw          $s1, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r17;
    // 0x80075BF0: sdc1        $f28, 0xB0($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0XB0, ctx->r29);
    // 0x80075BF4: sdc1        $f24, 0xA0($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0XA0, ctx->r29);
    // 0x80075BF8: sdc1        $f22, 0x98($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X98, ctx->r29);
    // 0x80075BFC: sdc1        $f20, 0x90($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X90, ctx->r29);
    // 0x80075C00: jal         0x8004015C
    // 0x80075C04: addu        $a0, $s4, $zero
    ctx->r4 = ADD32(ctx->r20, 0);
    func_8004015C(rdram, ctx);
        goto after_0;
    // 0x80075C04: addu        $a0, $s4, $zero
    ctx->r4 = ADD32(ctx->r20, 0);
    after_0:
    // 0x80075C08: addu        $s3, $v0, $zero
    ctx->r19 = ADD32(ctx->r2, 0);
    // 0x80075C0C: lwc1        $f0, 0x0($s3)
    ctx->f0.u32l = MEM_W(ctx->r19, 0X0);
    // 0x80075C10: lwc1        $f2, 0x4C($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X4C);
    // 0x80075C14: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x80075C18: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    // 0x80075C1C: lwc1        $f0, 0x4($s3)
    ctx->f0.u32l = MEM_W(ctx->r19, 0X4);
    // 0x80075C20: lwc1        $f2, 0x50($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X50);
    // 0x80075C24: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x80075C28: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    // 0x80075C2C: lwc1        $f0, 0x8($s3)
    ctx->f0.u32l = MEM_W(ctx->r19, 0X8);
    // 0x80075C30: lwc1        $f2, 0x54($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X54);
    // 0x80075C34: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x80075C38: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    // 0x80075C3C: jal         0x8001CF2C
    // 0x80075C40: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    func_8001CF2C(rdram, ctx);
        goto after_1;
    // 0x80075C40: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    after_1:
    // 0x80075C44: mtc1        $zero, $f28
    ctx->f28.u32l = 0;
    // 0x80075C48: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
    // 0x80075C4C: c.eq.s      $f22, $f28
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 28);
    c1cs = ctx->f22.fl == ctx->f28.fl;
    // 0x80075C50: nop

    // 0x80075C54: bc1f        L_80075C78
    if (!c1cs) {
        // 0x80075C58: addiu       $s2, $s3, 0xC
        ctx->r18 = ADD32(ctx->r19, 0XC);
            goto L_80075C78;
    }
    // 0x80075C58: addiu       $s2, $s3, 0xC
    ctx->r18 = ADD32(ctx->r19, 0XC);
    // 0x80075C5C: lw          $t0, 0x0($s3)
    ctx->r8 = MEM_W(ctx->r19, 0X0);
    // 0x80075C60: lw          $t1, 0x4($s3)
    ctx->r9 = MEM_W(ctx->r19, 0X4);
    // 0x80075C64: lw          $t2, 0x8($s3)
    ctx->r10 = MEM_W(ctx->r19, 0X8);
    // 0x80075C68: sw          $t0, 0x0($s6)
    MEM_W(0X0, ctx->r22) = ctx->r8;
    // 0x80075C6C: sw          $t1, 0x4($s6)
    MEM_W(0X4, ctx->r22) = ctx->r9;
    // 0x80075C70: j           L_80075FF0
    // 0x80075C74: sw          $t2, 0x8($s6)
    MEM_W(0X8, ctx->r22) = ctx->r10;
        goto L_80075FF0;
    // 0x80075C74: sw          $t2, 0x8($s6)
    MEM_W(0X8, ctx->r22) = ctx->r10;
L_80075C78:
    // 0x80075C78: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // 0x80075C7C: addiu       $a1, $sp, 0x10
    ctx->r5 = ADD32(ctx->r29, 0X10);
    // 0x80075C80: lwc1        $f0, 0x10($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X10);
    // 0x80075C84: lwc1        $f2, 0x18($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X18);
    // 0x80075C88: div.s       $f0, $f0, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f22.fl);
    // 0x80075C8C: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    // 0x80075C90: lwc1        $f0, 0x14($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X14);
    // 0x80075C94: div.s       $f2, $f2, $f22
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f2.fl = DIV_S(ctx->f2.fl, ctx->f22.fl);
    // 0x80075C98: swc1        $f2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f2.u32l;
    // 0x80075C9C: div.s       $f0, $f0, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f22.fl);
    // 0x80075CA0: jal         0x8001CFE8
    // 0x80075CA4: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    func_8001CFE8(rdram, ctx);
        goto after_2;
    // 0x80075CA4: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    after_2:
    // 0x80075CA8: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
    // 0x80075CAC: addiu       $s0, $s3, 0x18
    ctx->r16 = ADD32(ctx->r19, 0X18);
    // 0x80075CB0: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x80075CB4: jal         0x8001CFE8
    // 0x80075CB8: addiu       $a1, $sp, 0x10
    ctx->r5 = ADD32(ctx->r29, 0X10);
    func_8001CFE8(rdram, ctx);
        goto after_3;
    // 0x80075CB8: addiu       $a1, $sp, 0x10
    ctx->r5 = ADD32(ctx->r29, 0X10);
    after_3:
    // 0x80075CBC: addiu       $s1, $sp, 0x20
    ctx->r17 = ADD32(ctx->r29, 0X20);
    // 0x80075CC0: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x80075CC4: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x80075CC8: addu        $a2, $s2, $zero
    ctx->r6 = ADD32(ctx->r18, 0);
    // 0x80075CCC: jal         0x80019548
    // 0x80075CD0: mov.s       $f24, $f0
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 0);
    ctx->f24.fl = ctx->f0.fl;
    func_80019548(rdram, ctx);
        goto after_4;
    // 0x80075CD0: mov.s       $f24, $f0
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 0);
    ctx->f24.fl = ctx->f0.fl;
    after_4:
    // 0x80075CD4: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x80075CD8: jal         0x8001CFE8
    // 0x80075CDC: addiu       $a1, $sp, 0x10
    ctx->r5 = ADD32(ctx->r29, 0X10);
    func_8001CFE8(rdram, ctx);
        goto after_5;
    // 0x80075CDC: addiu       $a1, $sp, 0x10
    ctx->r5 = ADD32(ctx->r29, 0X10);
    after_5:
    // 0x80075CE0: addu        $a0, $s4, $zero
    ctx->r4 = ADD32(ctx->r20, 0);
    // 0x80075CE4: addiu       $a1, $sp, 0x10
    ctx->r5 = ADD32(ctx->r29, 0X10);
    // 0x80075CE8: addiu       $a2, $sp, 0x30
    ctx->r6 = ADD32(ctx->r29, 0X30);
    // 0x80075CEC: jal         0x80074B74
    // 0x80075CF0: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    func_80074B74(rdram, ctx);
        goto after_6;
    // 0x80075CF0: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    after_6:
    // 0x80075CF4: jal         0x80003430
    // 0x80075CF8: nop

    rand_recomp(rdram, ctx);
        goto after_7;
    // 0x80075CF8: nop

    after_7:
    // 0x80075CFC: lui         $v1, 0x5555
    ctx->r3 = S32(0X5555 << 16);
    // 0x80075D00: ori         $v1, $v1, 0x5556
    ctx->r3 = ctx->r3 | 0X5556;
    // 0x80075D04: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x80075D08: sra         $a0, $v0, 16
    ctx->r4 = S32(SIGNED(ctx->r2) >> 16);
    // 0x80075D0C: mult        $a0, $v1
    result = S64(S32(ctx->r4)) * S64(S32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80075D10: sra         $v0, $v0, 31
    ctx->r2 = S32(SIGNED(ctx->r2) >> 31);
    // 0x80075D14: mfhi        $t0
    ctx->r8 = hi;
    // 0x80075D18: subu        $v0, $t0, $v0
    ctx->r2 = SUB32(ctx->r8, ctx->r2);
    // 0x80075D1C: sll         $v1, $v0, 1
    ctx->r3 = S32(ctx->r2 << 1);
    // 0x80075D20: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x80075D24: subu        $a0, $a0, $v1
    ctx->r4 = SUB32(ctx->r4, ctx->r3);
    // 0x80075D28: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x80075D2C: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    // 0x80075D30: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80075D34: beq         $a0, $v0, L_80075E18
    if (ctx->r4 == ctx->r2) {
        // 0x80075D38: slti        $v0, $a0, 0x2
        ctx->r2 = SIGNED(ctx->r4) < 0X2 ? 1 : 0;
            goto L_80075E18;
    }
    // 0x80075D38: slti        $v0, $a0, 0x2
    ctx->r2 = SIGNED(ctx->r4) < 0X2 ? 1 : 0;
    // 0x80075D3C: beql        $v0, $zero, L_80075D54
    if (ctx->r2 == 0) {
        // 0x80075D40: addiu       $v0, $zero, 0x2
        ctx->r2 = ADD32(0, 0X2);
            goto L_80075D54;
    }
    goto skip_0;
    // 0x80075D40: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    skip_0:
    // 0x80075D44: beq         $a0, $zero, L_80075D64
    if (ctx->r4 == 0) {
        // 0x80075D48: nop
    
            goto L_80075D64;
    }
    // 0x80075D48: nop

    // 0x80075D4C: j           L_80075F80
    // 0x80075D50: nop

        goto L_80075F80;
    // 0x80075D50: nop

L_80075D54:
    // 0x80075D54: beq         $a0, $v0, L_80075ED0
    if (ctx->r4 == ctx->r2) {
        // 0x80075D58: nop
    
            goto L_80075ED0;
    }
    // 0x80075D58: nop

    // 0x80075D5C: j           L_80075F80
    // 0x80075D60: nop

        goto L_80075F80;
    // 0x80075D60: nop

L_80075D64:
    // 0x80075D64: jal         0x80003430
    // 0x80075D68: nop

    rand_recomp(rdram, ctx);
        goto after_8;
    // 0x80075D68: nop

    after_8:
    // 0x80075D6C: lwc1        $f2, 0x10($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X10);
    // 0x80075D70: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80075D74: lwc1        $f24, -0x2E38($at)
    ctx->f24.u32l = MEM_W(ctx->r1, -0X2E38);
    // 0x80075D78: mul.s       $f2, $f2, $f24
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f24.fl);
    // 0x80075D7C: nop

    // 0x80075D80: mul.s       $f2, $f2, $f26
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f26.fl);
    // 0x80075D84: andi        $v0, $v0, 0x7F
    ctx->r2 = ctx->r2 & 0X7F;
    // 0x80075D88: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80075D8C: lwc1        $f20, -0x2E34($at)
    ctx->f20.u32l = MEM_W(ctx->r1, -0X2E34);
    // 0x80075D90: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x80075D94: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x80075D98: sub.s       $f0, $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f20.fl;
    // 0x80075D9C: div.s       $f2, $f20, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = DIV_S(ctx->f20.fl, ctx->f2.fl);
    // 0x80075DA0: div.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f2.fl);
    // 0x80075DA4: jal         0x80003430
    // 0x80075DA8: swc1        $f0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f0.u32l;
    rand_recomp(rdram, ctx);
        goto after_9;
    // 0x80075DA8: swc1        $f0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f0.u32l;
    after_9:
    // 0x80075DAC: lwc1        $f2, 0x14($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X14);
    // 0x80075DB0: mul.s       $f2, $f2, $f24
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f24.fl);
    // 0x80075DB4: nop

    // 0x80075DB8: mul.s       $f2, $f2, $f26
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f26.fl);
    // 0x80075DBC: andi        $v0, $v0, 0x7F
    ctx->r2 = ctx->r2 & 0X7F;
    // 0x80075DC0: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x80075DC4: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x80075DC8: sub.s       $f0, $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f20.fl;
    // 0x80075DCC: c.le.s      $f28, $f22
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 22);
    c1cs = ctx->f28.fl <= ctx->f22.fl;
    // 0x80075DD0: div.s       $f20, $f20, $f2
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f20.fl = DIV_S(ctx->f20.fl, ctx->f2.fl);
    // 0x80075DD4: div.s       $f0, $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f20.fl);
    // 0x80075DD8: bc1f        L_80075E00
    if (!c1cs) {
        // 0x80075DDC: swc1        $f0, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->f0.u32l;
            goto L_80075E00;
    }
    // 0x80075DDC: swc1        $f0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f0.u32l;
    // 0x80075DE0: lwc1        $f0, 0x18($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X18);
    // 0x80075DE4: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80075DE8: lwc1        $f2, -0x2E30($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X2E30);
    // 0x80075DEC: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x80075DF0: nop

    // 0x80075DF4: mul.s       $f0, $f0, $f26
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f26.fl);
    // 0x80075DF8: j           L_80075F80
    // 0x80075DFC: swc1        $f0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f0.u32l;
        goto L_80075F80;
    // 0x80075DFC: swc1        $f0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f0.u32l;
L_80075E00:
    // 0x80075E00: lwc1        $f0, 0x18($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X18);
    // 0x80075E04: mul.s       $f0, $f0, $f24
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f24.fl);
    // 0x80075E08: nop

    // 0x80075E0C: mul.s       $f0, $f0, $f26
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f26.fl);
    // 0x80075E10: j           L_80075F80
    // 0x80075E14: swc1        $f0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f0.u32l;
        goto L_80075F80;
    // 0x80075E14: swc1        $f0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f0.u32l;
L_80075E18:
    // 0x80075E18: jal         0x80003430
    // 0x80075E1C: nop

    rand_recomp(rdram, ctx);
        goto after_10;
    // 0x80075E1C: nop

    after_10:
    // 0x80075E20: lwc1        $f4, 0x10($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X10);
    // 0x80075E24: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80075E28: lwc1        $f6, -0x2E2C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X2E2C);
    // 0x80075E2C: mul.s       $f4, $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80075E30: nop

    // 0x80075E34: mul.s       $f4, $f4, $f26
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f4.fl = MUL_S(ctx->f4.fl, ctx->f26.fl);
    // 0x80075E38: andi        $v0, $v0, 0x7F
    ctx->r2 = ctx->r2 & 0X7F;
    // 0x80075E3C: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80075E40: lwc1        $f2, -0x2E28($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X2E28);
    // 0x80075E44: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x80075E48: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x80075E4C: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x80075E50: c.le.s      $f28, $f24
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 24);
    c1cs = ctx->f28.fl <= ctx->f24.fl;
    // 0x80075E54: div.s       $f2, $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = DIV_S(ctx->f2.fl, ctx->f4.fl);
    // 0x80075E58: div.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f2.fl);
    // 0x80075E5C: bc1f        L_80075E7C
    if (!c1cs) {
        // 0x80075E60: swc1        $f0, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->f0.u32l;
            goto L_80075E7C;
    }
    // 0x80075E60: swc1        $f0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f0.u32l;
    // 0x80075E64: lwc1        $f0, 0x14($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X14);
    // 0x80075E68: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80075E6C: lwc1        $f2, -0x2E24($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X2E24);
    // 0x80075E70: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x80075E74: j           L_80075E84
    // 0x80075E78: nop

        goto L_80075E84;
    // 0x80075E78: nop

L_80075E7C:
    // 0x80075E7C: lwc1        $f0, 0x14($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X14);
    // 0x80075E80: mul.s       $f0, $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
L_80075E84:
    // 0x80075E84: nop

    // 0x80075E88: mul.s       $f0, $f0, $f26
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f26.fl);
    // 0x80075E8C: jal         0x80003430
    // 0x80075E90: swc1        $f0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f0.u32l;
    rand_recomp(rdram, ctx);
        goto after_11;
    // 0x80075E90: swc1        $f0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f0.u32l;
    after_11:
    // 0x80075E94: lwc1        $f4, 0x18($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X18);
    // 0x80075E98: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80075E9C: lwc1        $f0, -0x2E20($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X2E20);
    // 0x80075EA0: mul.s       $f4, $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x80075EA4: nop

    // 0x80075EA8: mul.s       $f4, $f4, $f26
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f4.fl = MUL_S(ctx->f4.fl, ctx->f26.fl);
    // 0x80075EAC: andi        $v0, $v0, 0x7F
    ctx->r2 = ctx->r2 & 0X7F;
    // 0x80075EB0: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80075EB4: lwc1        $f2, -0x2E1C($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X2E1C);
    // 0x80075EB8: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x80075EBC: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x80075EC0: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x80075EC4: div.s       $f2, $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = DIV_S(ctx->f2.fl, ctx->f4.fl);
    // 0x80075EC8: j           L_80075F7C
    // 0x80075ECC: div.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f2.fl);
        goto L_80075F7C;
    // 0x80075ECC: div.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f2.fl);
L_80075ED0:
    // 0x80075ED0: c.le.s      $f28, $f20
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f28.fl <= ctx->f20.fl;
    // 0x80075ED4: nop

    // 0x80075ED8: bc1f        L_80075EF4
    if (!c1cs) {
        // 0x80075EDC: nop
    
            goto L_80075EF4;
    }
    // 0x80075EDC: nop

    // 0x80075EE0: lwc1        $f0, 0x10($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X10);
    // 0x80075EE4: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80075EE8: lwc1        $f2, -0x2E18($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X2E18);
    // 0x80075EEC: j           L_80075F00
    // 0x80075EF0: nop

        goto L_80075F00;
    // 0x80075EF0: nop

L_80075EF4:
    // 0x80075EF4: lwc1        $f0, 0x10($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X10);
    // 0x80075EF8: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80075EFC: lwc1        $f2, -0x2E14($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X2E14);
L_80075F00:
    // 0x80075F00: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x80075F04: nop

    // 0x80075F08: mul.s       $f0, $f0, $f26
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f26.fl);
    // 0x80075F0C: jal         0x80003430
    // 0x80075F10: swc1        $f0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f0.u32l;
    rand_recomp(rdram, ctx);
        goto after_12;
    // 0x80075F10: swc1        $f0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f0.u32l;
    after_12:
    // 0x80075F14: lwc1        $f2, 0x14($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X14);
    // 0x80075F18: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80075F1C: lwc1        $f22, -0x2E10($at)
    ctx->f22.u32l = MEM_W(ctx->r1, -0X2E10);
    // 0x80075F20: mul.s       $f2, $f2, $f22
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f22.fl);
    // 0x80075F24: nop

    // 0x80075F28: mul.s       $f2, $f2, $f26
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f26.fl);
    // 0x80075F2C: andi        $v0, $v0, 0x7F
    ctx->r2 = ctx->r2 & 0X7F;
    // 0x80075F30: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80075F34: lwc1        $f20, -0x2E0C($at)
    ctx->f20.u32l = MEM_W(ctx->r1, -0X2E0C);
    // 0x80075F38: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x80075F3C: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x80075F40: sub.s       $f0, $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f20.fl;
    // 0x80075F44: div.s       $f2, $f20, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = DIV_S(ctx->f20.fl, ctx->f2.fl);
    // 0x80075F48: div.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f2.fl);
    // 0x80075F4C: jal         0x80003430
    // 0x80075F50: swc1        $f0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f0.u32l;
    rand_recomp(rdram, ctx);
        goto after_13;
    // 0x80075F50: swc1        $f0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f0.u32l;
    after_13:
    // 0x80075F54: lwc1        $f2, 0x18($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X18);
    // 0x80075F58: mul.s       $f2, $f2, $f22
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f22.fl);
    // 0x80075F5C: nop

    // 0x80075F60: mul.s       $f2, $f2, $f26
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f26.fl);
    // 0x80075F64: andi        $v0, $v0, 0x7F
    ctx->r2 = ctx->r2 & 0X7F;
    // 0x80075F68: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x80075F6C: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x80075F70: sub.s       $f0, $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f20.fl;
    // 0x80075F74: div.s       $f20, $f20, $f2
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f20.fl = DIV_S(ctx->f20.fl, ctx->f2.fl);
    // 0x80075F78: div.s       $f0, $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f20.fl);
L_80075F7C:
    // 0x80075F7C: swc1        $f0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f0.u32l;
L_80075F80:
    // 0x80075F80: lwc1        $f6, 0x30($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X30);
    // 0x80075F84: lwc1        $f0, 0x20($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X20);
    // 0x80075F88: lwc1        $f4, 0x34($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X34);
    // 0x80075F8C: add.s       $f6, $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f0.fl;
    // 0x80075F90: lwc1        $f0, 0x24($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X24);
    // 0x80075F94: lwc1        $f2, 0x38($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X38);
    // 0x80075F98: add.s       $f4, $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f0.fl;
    // 0x80075F9C: lwc1        $f0, 0x28($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X28);
    // 0x80075FA0: add.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x80075FA4: swc1        $f6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f6.u32l;
    // 0x80075FA8: swc1        $f4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f4.u32l;
    // 0x80075FAC: beq         $s5, $zero, L_80075FCC
    if (ctx->r21 == 0) {
        // 0x80075FB0: swc1        $f2, 0x28($sp)
        MEM_W(0X28, ctx->r29) = ctx->f2.u32l;
            goto L_80075FCC;
    }
    // 0x80075FB0: swc1        $f2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f2.u32l;
    // 0x80075FB4: lw          $t1, 0x20($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X20);
    // 0x80075FB8: lw          $t2, 0x24($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X24);
    // 0x80075FBC: lw          $t3, 0x28($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X28);
    // 0x80075FC0: sw          $t1, 0x0($s5)
    MEM_W(0X0, ctx->r21) = ctx->r9;
    // 0x80075FC4: sw          $t2, 0x4($s5)
    MEM_W(0X4, ctx->r21) = ctx->r10;
    // 0x80075FC8: sw          $t3, 0x8($s5)
    MEM_W(0X8, ctx->r21) = ctx->r11;
L_80075FCC:
    // 0x80075FCC: addiu       $s0, $sp, 0x40
    ctx->r16 = ADD32(ctx->r29, 0X40);
    // 0x80075FD0: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x80075FD4: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x80075FD8: jal         0x80059B50
    // 0x80075FDC: addu        $a1, $s3, $zero
    ctx->r5 = ADD32(ctx->r19, 0);
    func_80059B50(rdram, ctx);
        goto after_14;
    // 0x80075FDC: addu        $a1, $s3, $zero
    ctx->r5 = ADD32(ctx->r19, 0);
    after_14:
    // 0x80075FE0: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x80075FE4: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    // 0x80075FE8: jal         0x800193E8
    // 0x80075FEC: addu        $a2, $s6, $zero
    ctx->r6 = ADD32(ctx->r22, 0);
    func_800193E8(rdram, ctx);
        goto after_15;
    // 0x80075FEC: addu        $a2, $s6, $zero
    ctx->r6 = ADD32(ctx->r22, 0);
    after_15:
L_80075FF0:
    // 0x80075FF0: lw          $ra, 0x8C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X8C);
    // 0x80075FF4: lw          $s6, 0x88($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X88);
    // 0x80075FF8: lw          $s5, 0x84($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X84);
    // 0x80075FFC: lw          $s4, 0x80($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X80);
    // 0x80076000: lw          $s3, 0x7C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X7C);
    // 0x80076004: lw          $s2, 0x78($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X78);
    // 0x80076008: lw          $s1, 0x74($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X74);
    // 0x8007600C: lw          $s0, 0x70($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X70);
    // 0x80076010: ldc1        $f28, 0xB0($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0XB0);
    // 0x80076014: ldc1        $f26, 0xA8($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0XA8);
    // 0x80076018: ldc1        $f24, 0xA0($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0XA0);
    // 0x8007601C: ldc1        $f22, 0x98($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X98);
    // 0x80076020: ldc1        $f20, 0x90($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X90);
    // 0x80076024: jr          $ra
    // 0x80076028: addiu       $sp, $sp, 0xB8
    ctx->r29 = ADD32(ctx->r29, 0XB8);
    return;
    // 0x80076028: addiu       $sp, $sp, 0xB8
    ctx->r29 = ADD32(ctx->r29, 0XB8);
;}
RECOMP_FUNC void func_8007602C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007602C: addiu       $sp, $sp, -0x98
    ctx->r29 = ADD32(ctx->r29, -0X98);
    // 0x80076030: sw          $s1, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r17;
    // 0x80076034: addu        $s1, $a1, $zero
    ctx->r17 = ADD32(ctx->r5, 0);
    // 0x80076038: sw          $s3, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r19;
    // 0x8007603C: addu        $s3, $a2, $zero
    ctx->r19 = ADD32(ctx->r6, 0);
    // 0x80076040: sw          $s4, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r20;
    // 0x80076044: addu        $s4, $a3, $zero
    ctx->r20 = ADD32(ctx->r7, 0);
    // 0x80076048: sw          $s0, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r16;
    // 0x8007604C: andi        $s0, $a0, 0xFFFF
    ctx->r16 = ctx->r4 & 0XFFFF;
    // 0x80076050: sdc1        $f22, 0x90($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X90, ctx->r29);
    // 0x80076054: lwc1        $f22, 0xA8($sp)
    ctx->f22.u32l = MEM_W(ctx->r29, 0XA8);
    // 0x80076058: sw          $ra, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r31;
    // 0x8007605C: sw          $s2, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r18;
    // 0x80076060: sdc1        $f20, 0x88($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X88, ctx->r29);
    // 0x80076064: jal         0x8004015C
    // 0x80076068: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_8004015C(rdram, ctx);
        goto after_0;
    // 0x80076068: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_0:
    // 0x8007606C: addiu       $s2, $sp, 0x40
    ctx->r18 = ADD32(ctx->r29, 0X40);
    // 0x80076070: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // 0x80076074: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x80076078: jal         0x80059B50
    // 0x8007607C: addu        $a1, $v0, $zero
    ctx->r5 = ADD32(ctx->r2, 0);
    func_80059B50(rdram, ctx);
        goto after_1;
    // 0x8007607C: addu        $a1, $v0, $zero
    ctx->r5 = ADD32(ctx->r2, 0);
    after_1:
    // 0x80076080: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x80076084: addiu       $a1, $sp, 0x10
    ctx->r5 = ADD32(ctx->r29, 0X10);
    // 0x80076088: jal         0x80074B74
    // 0x8007608C: addiu       $a2, $sp, 0x20
    ctx->r6 = ADD32(ctx->r29, 0X20);
    func_80074B74(rdram, ctx);
        goto after_2;
    // 0x8007608C: addiu       $a2, $sp, 0x20
    ctx->r6 = ADD32(ctx->r29, 0X20);
    after_2:
    // 0x80076090: lwc1        $f2, 0x10($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X10);
    // 0x80076094: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80076098: lwc1        $f20, -0x2E08($at)
    ctx->f20.u32l = MEM_W(ctx->r1, -0X2E08);
    // 0x8007609C: mul.s       $f2, $f2, $f20
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f20.fl);
    // 0x800760A0: lwc1        $f0, 0x14($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X14);
    // 0x800760A4: mul.s       $f0, $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f20.fl);
    // 0x800760A8: lwc1        $f4, 0x18($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X18);
    // 0x800760AC: mul.s       $f4, $f4, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = MUL_S(ctx->f4.fl, ctx->f20.fl);
    // 0x800760B0: nop

    // 0x800760B4: mul.s       $f2, $f2, $f22
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f22.fl);
    // 0x800760B8: nop

    // 0x800760BC: mul.s       $f0, $f0, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f22.fl);
    // 0x800760C0: nop

    // 0x800760C4: mul.s       $f4, $f4, $f22
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f4.fl = MUL_S(ctx->f4.fl, ctx->f22.fl);
    // 0x800760C8: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // 0x800760CC: lwc1        $f6, 0x20($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X20);
    // 0x800760D0: addiu       $s0, $sp, 0x30
    ctx->r16 = ADD32(ctx->r29, 0X30);
    // 0x800760D4: sub.s       $f6, $f6, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = ctx->f6.fl - ctx->f2.fl;
    // 0x800760D8: lwc1        $f2, 0x24($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X24);
    // 0x800760DC: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x800760E0: add.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x800760E4: lwc1        $f0, 0x28($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X28);
    // 0x800760E8: addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    // 0x800760EC: sub.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f4.fl;
    // 0x800760F0: swc1        $f6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f6.u32l;
    // 0x800760F4: swc1        $f2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f2.u32l;
    // 0x800760F8: jal         0x800193E8
    // 0x800760FC: swc1        $f0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f0.u32l;
    func_800193E8(rdram, ctx);
        goto after_3;
    // 0x800760FC: swc1        $f0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f0.u32l;
    after_3:
    // 0x80076100: lwc1        $f0, 0x10($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X10);
    // 0x80076104: mul.s       $f0, $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f20.fl);
    // 0x80076108: lwc1        $f4, 0x14($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X14);
    // 0x8007610C: mul.s       $f4, $f4, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = MUL_S(ctx->f4.fl, ctx->f20.fl);
    // 0x80076110: lwc1        $f6, 0x18($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X18);
    // 0x80076114: mul.s       $f6, $f6, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = MUL_S(ctx->f6.fl, ctx->f20.fl);
    // 0x80076118: nop

    // 0x8007611C: mul.s       $f0, $f0, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f22.fl);
    // 0x80076120: nop

    // 0x80076124: mul.s       $f4, $f4, $f22
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f4.fl = MUL_S(ctx->f4.fl, ctx->f22.fl);
    // 0x80076128: nop

    // 0x8007612C: mul.s       $f6, $f6, $f22
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f6.fl = MUL_S(ctx->f6.fl, ctx->f22.fl);
    // 0x80076130: lwc1        $f8, 0x20($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X20);
    // 0x80076134: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // 0x80076138: add.s       $f8, $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f8.fl + ctx->f0.fl;
    // 0x8007613C: lwc1        $f2, 0x24($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X24);
    // 0x80076140: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x80076144: add.s       $f2, $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f4.fl;
    // 0x80076148: lwc1        $f0, 0x28($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X28);
    // 0x8007614C: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    // 0x80076150: sub.s       $f0, $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f6.fl;
    // 0x80076154: swc1        $f8, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f8.u32l;
    // 0x80076158: swc1        $f2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f2.u32l;
    // 0x8007615C: jal         0x800193E8
    // 0x80076160: swc1        $f0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f0.u32l;
    func_800193E8(rdram, ctx);
        goto after_4;
    // 0x80076160: swc1        $f0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f0.u32l;
    after_4:
    // 0x80076164: lwc1        $f0, 0x30($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X30);
    // 0x80076168: lwc1        $f2, 0x0($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0X0);
    // 0x8007616C: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x80076170: swc1        $f0, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->f0.u32l;
    // 0x80076174: lwc1        $f0, 0x34($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X34);
    // 0x80076178: lwc1        $f2, 0x4($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0X4);
    // 0x8007617C: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x80076180: swc1        $f0, 0x4($s3)
    MEM_W(0X4, ctx->r19) = ctx->f0.u32l;
    // 0x80076184: lwc1        $f0, 0x38($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X38);
    // 0x80076188: lwc1        $f2, 0x8($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0X8);
    // 0x8007618C: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x80076190: swc1        $f0, 0x8($s3)
    MEM_W(0X8, ctx->r19) = ctx->f0.u32l;
    // 0x80076194: lwc1        $f0, 0x10($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X10);
    // 0x80076198: mul.s       $f0, $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f20.fl);
    // 0x8007619C: lwc1        $f4, 0x14($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X14);
    // 0x800761A0: mul.s       $f4, $f4, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = MUL_S(ctx->f4.fl, ctx->f20.fl);
    // 0x800761A4: lwc1        $f6, 0x18($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X18);
    // 0x800761A8: mul.s       $f6, $f6, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = MUL_S(ctx->f6.fl, ctx->f20.fl);
    // 0x800761AC: nop

    // 0x800761B0: mul.s       $f0, $f0, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f22.fl);
    // 0x800761B4: nop

    // 0x800761B8: mul.s       $f4, $f4, $f22
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f4.fl = MUL_S(ctx->f4.fl, ctx->f22.fl);
    // 0x800761BC: nop

    // 0x800761C0: mul.s       $f6, $f6, $f22
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f6.fl = MUL_S(ctx->f6.fl, ctx->f22.fl);
    // 0x800761C4: lwc1        $f8, 0x20($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X20);
    // 0x800761C8: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // 0x800761CC: sub.s       $f8, $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f8.fl - ctx->f0.fl;
    // 0x800761D0: lwc1        $f2, 0x24($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X24);
    // 0x800761D4: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x800761D8: add.s       $f2, $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f4.fl;
    // 0x800761DC: lwc1        $f0, 0x28($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X28);
    // 0x800761E0: addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    // 0x800761E4: add.s       $f0, $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f6.fl;
    // 0x800761E8: swc1        $f8, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f8.u32l;
    // 0x800761EC: swc1        $f2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f2.u32l;
    // 0x800761F0: jal         0x800193E8
    // 0x800761F4: swc1        $f0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f0.u32l;
    func_800193E8(rdram, ctx);
        goto after_5;
    // 0x800761F4: swc1        $f0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f0.u32l;
    after_5:
    // 0x800761F8: lwc1        $f0, 0x30($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X30);
    // 0x800761FC: lwc1        $f2, 0x0($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0X0);
    // 0x80076200: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x80076204: swc1        $f0, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->f0.u32l;
    // 0x80076208: lwc1        $f0, 0x34($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X34);
    // 0x8007620C: lwc1        $f2, 0x4($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0X4);
    // 0x80076210: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x80076214: swc1        $f0, 0x4($s4)
    MEM_W(0X4, ctx->r20) = ctx->f0.u32l;
    // 0x80076218: lwc1        $f0, 0x38($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X38);
    // 0x8007621C: lwc1        $f2, 0x8($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0X8);
    // 0x80076220: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x80076224: swc1        $f0, 0x8($s4)
    MEM_W(0X8, ctx->r20) = ctx->f0.u32l;
    // 0x80076228: lw          $ra, 0x84($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X84);
    // 0x8007622C: lw          $s4, 0x80($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X80);
    // 0x80076230: lw          $s3, 0x7C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X7C);
    // 0x80076234: lw          $s2, 0x78($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X78);
    // 0x80076238: lw          $s1, 0x74($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X74);
    // 0x8007623C: lw          $s0, 0x70($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X70);
    // 0x80076240: ldc1        $f22, 0x90($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X90);
    // 0x80076244: ldc1        $f20, 0x88($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X88);
    // 0x80076248: jr          $ra
    // 0x8007624C: addiu       $sp, $sp, 0x98
    ctx->r29 = ADD32(ctx->r29, 0X98);
    return;
    // 0x8007624C: addiu       $sp, $sp, 0x98
    ctx->r29 = ADD32(ctx->r29, 0X98);
;}
RECOMP_FUNC void func_80076250(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80076250: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80076254: sw          $ra, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r31;
    // 0x80076258: sdc1        $f20, 0x38($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X38, ctx->r29);
    // 0x8007625C: lw          $v1, 0x8($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X8);
    // 0x80076260: beq         $v1, $zero, L_8007635C
    if (ctx->r3 == 0) {
        // 0x80076264: lui         $v0, 0x8011
        ctx->r2 = S32(0X8011 << 16);
            goto L_8007635C;
    }
    // 0x80076264: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x80076268: lw          $v0, -0x35E0($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X35E0);
    // 0x8007626C: bne         $v0, $zero, L_800762BC
    if (ctx->r2 != 0) {
        // 0x80076270: addiu       $v0, $sp, 0x10
        ctx->r2 = ADD32(ctx->r29, 0X10);
            goto L_800762BC;
    }
    // 0x80076270: addiu       $v0, $sp, 0x10
    ctx->r2 = ADD32(ctx->r29, 0X10);
    // 0x80076274: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80076278: lwc1        $f4, -0x2E04($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X2E04);
    // 0x8007627C: lwc1        $f2, 0xC($v1)
    ctx->f2.u32l = MEM_W(ctx->r3, 0XC);
    // 0x80076280: mul.s       $f2, $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f4.fl);
    // 0x80076284: lwc1        $f0, 0x0($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X0);
    // 0x80076288: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x8007628C: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    // 0x80076290: lwc1        $f0, 0x10($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X10);
    // 0x80076294: mul.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x80076298: lwc1        $f2, 0x4($v1)
    ctx->f2.u32l = MEM_W(ctx->r3, 0X4);
    // 0x8007629C: sub.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl - ctx->f0.fl;
    // 0x800762A0: swc1        $f2, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f2.u32l;
    // 0x800762A4: lwc1        $f2, 0x14($v1)
    ctx->f2.u32l = MEM_W(ctx->r3, 0X14);
    // 0x800762A8: mul.s       $f2, $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f4.fl);
    // 0x800762AC: lwc1        $f0, 0x8($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X8);
    // 0x800762B0: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x800762B4: j           L_800762D4
    // 0x800762B8: swc1        $f0, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f0.u32l;
        goto L_800762D4;
    // 0x800762B8: swc1        $f0, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f0.u32l;
L_800762BC:
    // 0x800762BC: lw          $t0, 0x0($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X0);
    // 0x800762C0: lw          $t1, 0x4($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X4);
    // 0x800762C4: lw          $t2, 0x8($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X8);
    // 0x800762C8: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x800762CC: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    // 0x800762D0: sw          $t2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r10;
L_800762D4:
    // 0x800762D4: lhu         $v0, 0x4($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X4);
    // 0x800762D8: addiu       $v1, $v0, -0x8
    ctx->r3 = ADD32(ctx->r2, -0X8);
    // 0x800762DC: sltiu       $v0, $v1, 0x7
    ctx->r2 = ctx->r3 < 0X7 ? 1 : 0;
    // 0x800762E0: beq         $v0, $zero, L_80076334
    if (ctx->r2 == 0) {
        // 0x800762E4: lui         $v0, 0x8004
        ctx->r2 = S32(0X8004 << 16);
            goto L_80076334;
    }
    // 0x800762E4: lui         $v0, 0x8004
    ctx->r2 = S32(0X8004 << 16);
    // 0x800762E8: addiu       $v0, $v0, -0x2E00
    ctx->r2 = ADD32(ctx->r2, -0X2E00);
    // 0x800762EC: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x800762F0: addu        $v1, $v1, $v0
    gpr jr_addend_800762F8 = ctx->r3;
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x800762F4: lw          $v0, 0x0($v1)
    ctx->r2 = ADD32(ctx->r3, 0X0);
    // 0x800762F8: jr          $v0
    // 0x800762FC: nop

    switch (jr_addend_800762F8 >> 2) {
        case 0: goto L_8007635C; break;
        case 1: goto L_8007635C; break;
        case 2: goto L_80076324; break;
        case 3: goto L_80076324; break;
        case 4: goto L_80076300; break;
        case 5: goto L_80076324; break;
        case 6: goto L_80076324; break;
        default: switch_error(__func__, 0x800762F8, 0x8003D200);
    }
    // 0x800762FC: nop

L_80076300:
    // 0x80076300: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    // 0x80076304: lui         $a1, 0x3ECC
    ctx->r5 = S32(0X3ECC << 16);
    // 0x80076308: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    // 0x8007630C: lui         $a2, 0x3F4C
    ctx->r6 = S32(0X3F4C << 16);
    // 0x80076310: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x80076314: jal         0x8006133C
    // 0x80076318: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    func_8006133C(rdram, ctx);
        goto after_0;
    // 0x80076318: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    after_0:
    // 0x8007631C: j           L_8007635C
    // 0x80076320: nop

        goto L_8007635C;
    // 0x80076320: nop

L_80076324:
    // 0x80076324: lui         $a1, 0x3F19
    ctx->r5 = S32(0X3F19 << 16);
    // 0x80076328: ori         $a1, $a1, 0x999A
    ctx->r5 = ctx->r5 | 0X999A;
    // 0x8007632C: j           L_80076354
    // 0x80076330: nop

        goto L_80076354;
    // 0x80076330: nop

L_80076334:
    // 0x80076334: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80076338: lwc1        $f20, -0x2DE4($at)
    ctx->f20.u32l = MEM_W(ctx->r1, -0X2DE4);
    // 0x8007633C: lui         $a1, 0x3D4C
    ctx->r5 = S32(0X3D4C << 16);
    // 0x80076340: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    // 0x80076344: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x80076348: jal         0x80073E4C
    // 0x8007634C: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    func_80073E4C(rdram, ctx);
        goto after_1;
    // 0x8007634C: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    after_1:
    // 0x80076350: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
L_80076354:
    // 0x80076354: jal         0x800612A4
    // 0x80076358: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    func_800612A4(rdram, ctx);
        goto after_2;
    // 0x80076358: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    after_2:
L_8007635C:
    // 0x8007635C: lw          $ra, 0x30($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X30);
    // 0x80076360: ldc1        $f20, 0x38($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X38);
    // 0x80076364: jr          $ra
    // 0x80076368: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x80076368: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void func_8007636C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007636C: addiu       $sp, $sp, -0x118
    ctx->r29 = ADD32(ctx->r29, -0X118);
    // 0x80076370: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80076374: lw          $v1, 0xB70($v0)
    ctx->r3 = MEM_W(ctx->r2, 0XB70);
    // 0x80076378: addiu       $v0, $zero, 0xD
    ctx->r2 = ADD32(0, 0XD);
    // 0x8007637C: sw          $ra, 0xE8($sp)
    MEM_W(0XE8, ctx->r29) = ctx->r31;
    // 0x80076380: sw          $s5, 0xE4($sp)
    MEM_W(0XE4, ctx->r29) = ctx->r21;
    // 0x80076384: sw          $s4, 0xE0($sp)
    MEM_W(0XE0, ctx->r29) = ctx->r20;
    // 0x80076388: sw          $s3, 0xDC($sp)
    MEM_W(0XDC, ctx->r29) = ctx->r19;
    // 0x8007638C: sw          $s2, 0xD8($sp)
    MEM_W(0XD8, ctx->r29) = ctx->r18;
    // 0x80076390: sw          $s1, 0xD4($sp)
    MEM_W(0XD4, ctx->r29) = ctx->r17;
    // 0x80076394: sw          $s0, 0xD0($sp)
    MEM_W(0XD0, ctx->r29) = ctx->r16;
    // 0x80076398: sdc1        $f28, 0x110($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0X110, ctx->r29);
    // 0x8007639C: sdc1        $f26, 0x108($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X108, ctx->r29);
    // 0x800763A0: sdc1        $f24, 0x100($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X100, ctx->r29);
    // 0x800763A4: sdc1        $f22, 0xF8($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0XF8, ctx->r29);
    // 0x800763A8: sdc1        $f20, 0xF0($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0XF0, ctx->r29);
    // 0x800763AC: bne         $v1, $v0, L_80076960
    if (ctx->r3 != ctx->r2) {
        // 0x800763B0: lui         $v0, 0x8013
        ctx->r2 = S32(0X8013 << 16);
            goto L_80076960;
    }
    // 0x800763B0: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800763B4: lui         $v1, 0x8014
    ctx->r3 = S32(0X8014 << 16);
    // 0x800763B8: lwc1        $f2, 0xBA4($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0XBA4);
    // 0x800763BC: lwc1        $f0, -0x574C($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, -0X574C);
    // 0x800763C0: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x800763C4: nop

    // 0x800763C8: bc1f        L_80076960
    if (!c1cs) {
        // 0x800763CC: lui         $v0, 0x8014
        ctx->r2 = S32(0X8014 << 16);
            goto L_80076960;
    }
    // 0x800763CC: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x800763D0: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x800763D4: lwc1        $f24, -0x2DD8($at)
    ctx->f24.u32l = MEM_W(ctx->r1, -0X2DD8);
    // 0x800763D8: lw          $v0, -0x72E4($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X72E4);
    // 0x800763DC: mtc1        $zero, $f22
    ctx->f22.u32l = 0;
    // 0x800763E0: addiu       $v0, $v0, 0x28
    ctx->r2 = ADD32(ctx->r2, 0X28);
    // 0x800763E4: lwc1        $f0, 0x24($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X24);
    // 0x800763E8: swc1        $f0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f0.u32l;
    // 0x800763EC: lwc1        $f0, 0x28($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X28);
    // 0x800763F0: addu        $s1, $zero, $zero
    ctx->r17 = ADD32(0, 0);
    // 0x800763F4: swc1        $f0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f0.u32l;
    // 0x800763F8: lwc1        $f0, 0x2C($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X2C);
    // 0x800763FC: addu        $s3, $s1, $zero
    ctx->r19 = ADD32(ctx->r17, 0);
    // 0x80076400: swc1        $f0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f0.u32l;
    // 0x80076404: lwc1        $f0, 0x8($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X8);
    // 0x80076408: lui         $s5, 0x8013
    ctx->r21 = S32(0X8013 << 16);
    // 0x8007640C: swc1        $f0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f0.u32l;
    // 0x80076410: lwc1        $f0, 0x14($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X14);
    // 0x80076414: addiu       $s2, $sp, 0x68
    ctx->r18 = ADD32(ctx->r29, 0X68);
    // 0x80076418: swc1        $f0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f0.u32l;
    // 0x8007641C: lwc1        $f0, 0x20($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X20);
    // 0x80076420: addiu       $s4, $zero, 0x1
    ctx->r20 = ADD32(0, 0X1);
    // 0x80076424: swc1        $f0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f0.u32l;
L_80076428:
    // 0x80076428: lw          $v1, 0x75D8($s5)
    ctx->r3 = MEM_W(ctx->r21, 0X75D8);
    // 0x8007642C: lw          $v0, 0x10($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X10);
    // 0x80076430: sltu        $v0, $s1, $v0
    ctx->r2 = ctx->r17 < ctx->r2 ? 1 : 0;
    // 0x80076434: beq         $v0, $zero, L_800764D8
    if (ctx->r2 == 0) {
        // 0x80076438: sll         $v0, $s1, 2
        ctx->r2 = S32(ctx->r17 << 2);
            goto L_800764D8;
    }
    // 0x80076438: sll         $v0, $s1, 2
    ctx->r2 = S32(ctx->r17 << 2);
    // 0x8007643C: lw          $v1, 0x14($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X14);
    // 0x80076440: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80076444: lw          $s0, 0x0($v0)
    ctx->r16 = MEM_W(ctx->r2, 0X0);
    // 0x80076448: lwc1        $f2, 0x38($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X38);
    // 0x8007644C: lwc1        $f0, 0x10($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X10);
    // 0x80076450: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x80076454: lwc1        $f2, 0x3C($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x80076458: mul.s       $f4, $f0, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x8007645C: swc1        $f0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f0.u32l;
    // 0x80076460: lwc1        $f0, 0x14($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X14);
    // 0x80076464: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x80076468: mul.s       $f6, $f0, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x8007646C: swc1        $f0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f0.u32l;
    // 0x80076470: lwc1        $f2, 0x18($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X18);
    // 0x80076474: lwc1        $f0, 0x40($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X40);
    // 0x80076478: sub.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl - ctx->f0.fl;
    // 0x8007647C: mul.s       $f0, $f2, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x80076480: add.s       $f4, $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80076484: add.s       $f4, $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f0.fl;
    // 0x80076488: c.lt.s      $f4, $f24
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 24);
    c1cs = ctx->f4.fl < ctx->f24.fl;
    // 0x8007648C: nop

    // 0x80076490: bc1f        L_800764D0
    if (!c1cs) {
        // 0x80076494: swc1        $f2, 0x30($sp)
        MEM_W(0X30, ctx->r29) = ctx->f2.u32l;
            goto L_800764D0;
    }
    // 0x80076494: swc1        $f2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f2.u32l;
    // 0x80076498: sqrt.s      $f20, $f4
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f20.fl = sqrtf(ctx->f4.fl);
    // 0x8007649C: c.lt.s      $f22, $f20
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f22.fl < ctx->f20.fl;
    // 0x800764A0: nop

    // 0x800764A4: bc1f        L_800764D0
    if (!c1cs) {
        // 0x800764A8: addiu       $a0, $sp, 0x48
        ctx->r4 = ADD32(ctx->r29, 0X48);
            goto L_800764D0;
    }
    // 0x800764A8: addiu       $a0, $sp, 0x48
    ctx->r4 = ADD32(ctx->r29, 0X48);
    // 0x800764AC: jal         0x8001CFE8
    // 0x800764B0: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    func_8001CFE8(rdram, ctx);
        goto after_0;
    // 0x800764B0: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    after_0:
    // 0x800764B4: div.s       $f0, $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f20.fl);
    // 0x800764B8: c.le.s      $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f22.fl <= ctx->f0.fl;
    // 0x800764BC: nop

    // 0x800764C0: bc1f        L_800764D0
    if (!c1cs) {
        // 0x800764C4: addu        $v0, $s2, $s3
        ctx->r2 = ADD32(ctx->r18, ctx->r19);
            goto L_800764D0;
    }
    // 0x800764C4: addu        $v0, $s2, $s3
    ctx->r2 = ADD32(ctx->r18, ctx->r19);
    // 0x800764C8: sb          $s1, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r17;
    // 0x800764CC: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
L_800764D0:
    // 0x800764D0: bne         $s4, $zero, L_80076428
    if (ctx->r20 != 0) {
        // 0x800764D4: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_80076428;
    }
    // 0x800764D4: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
L_800764D8:
    // 0x800764D8: beq         $s3, $zero, L_80076950
    if (ctx->r19 == 0) {
        // 0x800764DC: lui         $v0, 0x8004
        ctx->r2 = S32(0X8004 << 16);
            goto L_80076950;
    }
    // 0x800764DC: lui         $v0, 0x8004
    ctx->r2 = S32(0X8004 << 16);
    // 0x800764E0: addiu       $t3, $v0, -0x2DE0
    ctx->r11 = ADD32(ctx->r2, -0X2DE0);
    // 0x800764E4: lwl         $t0, 0x0($t3)
    ctx->r8 = do_lwl(rdram, ctx->r8, ctx->r11, 0X0);
    // 0x800764E8: lwr         $t0, 0x3($t3)
    ctx->r8 = do_lwr(rdram, ctx->r8, ctx->r11, 0X3);
    // 0x800764EC: swl         $t0, 0x90($sp)
    do_swl(rdram, 0X90, ctx->r29, ctx->r8);
    // 0x800764F0: swr         $t0, 0x93($sp)
    do_swr(rdram, 0X93, ctx->r29, ctx->r8);
    // 0x800764F4: lui         $v0, 0x8004
    ctx->r2 = S32(0X8004 << 16);
    // 0x800764F8: addiu       $t3, $v0, -0x2DDC
    ctx->r11 = ADD32(ctx->r2, -0X2DDC);
    // 0x800764FC: lwl         $t0, 0x0($t3)
    ctx->r8 = do_lwl(rdram, ctx->r8, ctx->r11, 0X0);
    // 0x80076500: lwr         $t0, 0x3($t3)
    ctx->r8 = do_lwr(rdram, ctx->r8, ctx->r11, 0X3);
    // 0x80076504: swl         $t0, 0x98($sp)
    do_swl(rdram, 0X98, ctx->r29, ctx->r8);
    // 0x80076508: swr         $t0, 0x9B($sp)
    do_swr(rdram, 0X9B, ctx->r29, ctx->r8);
    // 0x8007650C: jal         0x80003430
    // 0x80076510: nop

    rand_recomp(rdram, ctx);
        goto after_1;
    // 0x80076510: nop

    after_1:
    // 0x80076514: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x80076518: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x8007651C: div         $zero, $v0, $s3
    if (S32(ctx->r19) != 0) { lo = S32(S64(S32(ctx->r2)) / S64(S32(ctx->r19))); hi = S32(S64(S32(ctx->r2)) % S64(S32(ctx->r19))); } else { lo = 0; hi = S32(ctx->r2); }
    // 0x80076520: bne         $s3, $zero, L_8007652C
    if (ctx->r19 != 0) {
        // 0x80076524: nop
    
            goto L_8007652C;
    }
    // 0x80076524: nop

    // 0x80076528: break       7
    do_break(2147968296);
L_8007652C:
    // 0x8007652C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80076530: bne         $s3, $at, L_80076544
    if (ctx->r19 != ctx->r1) {
        // 0x80076534: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80076544;
    }
    // 0x80076534: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80076538: bne         $v0, $at, L_80076544
    if (ctx->r2 != ctx->r1) {
        // 0x8007653C: nop
    
            goto L_80076544;
    }
    // 0x8007653C: nop

    // 0x80076540: break       6
    do_break(2147968320);
L_80076544:
    // 0x80076544: mfhi        $v1
    ctx->r3 = hi;
    // 0x80076548: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8007654C: lw          $a0, 0x75D8($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X75D8);
    // 0x80076550: addu        $v1, $sp, $v1
    ctx->r3 = ADD32(ctx->r29, ctx->r3);
    // 0x80076554: lbu         $v0, 0x68($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X68);
    // 0x80076558: lw          $v1, 0x14($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X14);
    // 0x8007655C: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80076560: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80076564: lui         $v1, 0x8014
    ctx->r3 = S32(0X8014 << 16);
    // 0x80076568: lw          $v1, -0x72E4($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X72E4);
    // 0x8007656C: lw          $s0, 0x0($v0)
    ctx->r16 = MEM_W(ctx->r2, 0X0);
    // 0x80076570: addiu       $v1, $v1, 0x28
    ctx->r3 = ADD32(ctx->r3, 0X28);
    // 0x80076574: lwc1        $f0, 0x10($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X10);
    // 0x80076578: lwc1        $f2, 0x24($v1)
    ctx->f2.u32l = MEM_W(ctx->r3, 0X24);
    // 0x8007657C: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x80076580: addiu       $v0, $s0, 0x10
    ctx->r2 = ADD32(ctx->r16, 0X10);
    // 0x80076584: swc1        $f0, 0xC0($sp)
    MEM_W(0XC0, ctx->r29) = ctx->f0.u32l;
    // 0x80076588: lwc1        $f0, 0x4($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X4);
    // 0x8007658C: lwc1        $f2, 0x28($v1)
    ctx->f2.u32l = MEM_W(ctx->r3, 0X28);
    // 0x80076590: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x80076594: swc1        $f0, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->f0.u32l;
    // 0x80076598: lwc1        $f2, 0x8($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X8);
    // 0x8007659C: lwc1        $f0, 0x2C($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X2C);
    // 0x800765A0: sub.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl - ctx->f0.fl;
    // 0x800765A4: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x800765A8: lwc1        $f24, -0x2DD4($at)
    ctx->f24.u32l = MEM_W(ctx->r1, -0X2DD4);
    // 0x800765AC: addiu       $a0, $sp, 0xC0
    ctx->r4 = ADD32(ctx->r29, 0XC0);
    // 0x800765B0: jal         0x8001CF2C
    // 0x800765B4: swc1        $f2, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->f2.u32l;
    func_8001CF2C(rdram, ctx);
        goto after_2;
    // 0x800765B4: swc1        $f2, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->f2.u32l;
    after_2:
    // 0x800765B8: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x800765BC: lwc1        $f4, -0x2DD0($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X2DD0);
    // 0x800765C0: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
    // 0x800765C4: c.lt.s      $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f4.fl < ctx->f2.fl;
    // 0x800765C8: nop

    // 0x800765CC: bc1tl       L_800765D4
    if (c1cs) {
        // 0x800765D0: mov.s       $f2, $f4
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    ctx->f2.fl = ctx->f4.fl;
            goto L_800765D4;
    }
    goto skip_0;
    // 0x800765D0: mov.s       $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    ctx->f2.fl = ctx->f4.fl;
    skip_0:
L_800765D4:
    // 0x800765D4: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x800765D8: lwc1        $f0, -0x2DCC($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X2DCC);
    // 0x800765DC: div.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = DIV_S(ctx->f2.fl, ctx->f0.fl);
    // 0x800765E0: mul.s       $f24, $f2, $f24
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f24.fl = MUL_S(ctx->f2.fl, ctx->f24.fl);
    // 0x800765E4: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800765E8: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x800765EC: nop

    // 0x800765F0: bc1f        L_80076614
    if (!c1cs) {
        // 0x800765F4: addiu       $s2, $zero, 0x1
        ctx->r18 = ADD32(0, 0X1);
            goto L_80076614;
    }
    // 0x800765F4: addiu       $s2, $zero, 0x1
    ctx->r18 = ADD32(0, 0X1);
    // 0x800765F8: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x800765FC: lwc1        $f0, -0x2DC8($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X2DC8);
    // 0x80076600: div.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f2.fl);
    // 0x80076604: trunc.w.s   $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    ctx->f8.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x80076608: mfc1        $s2, $f8
    ctx->r18 = (int32_t)ctx->f8.u32l;
    // 0x8007660C: j           L_80076618
    // 0x80076610: slti        $v0, $s2, 0x8
    ctx->r2 = SIGNED(ctx->r18) < 0X8 ? 1 : 0;
        goto L_80076618;
    // 0x80076610: slti        $v0, $s2, 0x8
    ctx->r2 = SIGNED(ctx->r18) < 0X8 ? 1 : 0;
L_80076614:
    // 0x80076614: slti        $v0, $s2, 0x8
    ctx->r2 = SIGNED(ctx->r18) < 0X8 ? 1 : 0;
L_80076618:
    // 0x80076618: beql        $v0, $zero, L_80076620
    if (ctx->r2 == 0) {
        // 0x8007661C: addiu       $s2, $zero, 0xC
        ctx->r18 = ADD32(0, 0XC);
            goto L_80076620;
    }
    goto skip_1;
    // 0x8007661C: addiu       $s2, $zero, 0xC
    ctx->r18 = ADD32(0, 0XC);
    skip_1:
L_80076620:
    // 0x80076620: lui         $a2, 0x8014
    ctx->r6 = S32(0X8014 << 16);
    // 0x80076624: addiu       $a2, $a2, -0x7FA8
    ctx->r6 = ADD32(ctx->r6, -0X7FA8);
    // 0x80076628: lwc1        $f12, 0x10($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X10);
    // 0x8007662C: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    // 0x80076630: swc1        $f12, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->f12.u32l;
    // 0x80076634: lwc1        $f14, 0x18($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X18);
    // 0x80076638: addu        $s1, $a3, $zero
    ctx->r17 = ADD32(ctx->r7, 0);
    // 0x8007663C: jal         0x80067D90
    // 0x80076640: swc1        $f14, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->f14.u32l;
    func_80067D90(rdram, ctx);
        goto after_3;
    // 0x80076640: swc1        $f14, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->f14.u32l;
    after_3:
    // 0x80076644: ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
    // 0x80076648: sh          $v0, 0x88($sp)
    MEM_H(0X88, ctx->r29) = ctx->r2;
    // 0x8007664C: addiu       $v0, $sp, 0x90
    ctx->r2 = ADD32(ctx->r29, 0X90);
    // 0x80076650: sw          $v0, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r2;
    // 0x80076654: addiu       $v0, $sp, 0x98
    ctx->r2 = ADD32(ctx->r29, 0X98);
    // 0x80076658: sw          $v0, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r2;
    // 0x8007665C: addiu       $v0, $sp, 0xB0
    ctx->r2 = ADD32(ctx->r29, 0XB0);
    // 0x80076660: swc1        $f0, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->f0.u32l;
    // 0x80076664: sw          $v0, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r2;
    // 0x80076668: blez        $s2, L_80076738
    if (SIGNED(ctx->r18) <= 0) {
        // 0x8007666C: swc1        $f0, 0xB4($sp)
        MEM_W(0XB4, ctx->r29) = ctx->f0.u32l;
            goto L_80076738;
    }
    // 0x8007666C: swc1        $f0, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->f0.u32l;
    // 0x80076670: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80076674: lwc1        $f20, -0x2DC4($at)
    ctx->f20.u32l = MEM_W(ctx->r1, -0X2DC4);
    // 0x80076678: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8007667C: lwc1        $f22, -0x2DC0($at)
    ctx->f22.u32l = MEM_W(ctx->r1, -0X2DC0);
    // 0x80076680: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80076684: lwc1        $f28, -0x2DBC($at)
    ctx->f28.u32l = MEM_W(ctx->r1, -0X2DBC);
    // 0x80076688: mtc1        $zero, $f26
    ctx->f26.u32l = 0;
L_8007668C:
    // 0x8007668C: jal         0x80003430
    // 0x80076690: nop

    rand_recomp(rdram, ctx);
        goto after_4;
    // 0x80076690: nop

    after_4:
    // 0x80076694: andi        $v0, $v0, 0x7F
    ctx->r2 = ctx->r2 & 0X7F;
    // 0x80076698: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x8007669C: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x800766A0: sub.s       $f0, $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f20.fl;
    // 0x800766A4: lwc1        $f2, 0xA0($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0XA0);
    // 0x800766A8: div.s       $f0, $f0, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f22.fl);
    // 0x800766AC: add.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x800766B0: jal         0x80003430
    // 0x800766B4: swc1        $f2, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->f2.u32l;
    rand_recomp(rdram, ctx);
        goto after_5;
    // 0x800766B4: swc1        $f2, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->f2.u32l;
    after_5:
    // 0x800766B8: andi        $v0, $v0, 0x7F
    ctx->r2 = ctx->r2 & 0X7F;
    // 0x800766BC: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x800766C0: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x800766C4: sub.s       $f0, $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f20.fl;
    // 0x800766C8: lwc1        $f2, 0xA8($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0XA8);
    // 0x800766CC: div.s       $f0, $f0, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f22.fl);
    // 0x800766D0: add.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x800766D4: jal         0x80003430
    // 0x800766D8: swc1        $f2, 0xB8($sp)
    MEM_W(0XB8, ctx->r29) = ctx->f2.u32l;
    rand_recomp(rdram, ctx);
        goto after_6;
    // 0x800766D8: swc1        $f2, 0xB8($sp)
    MEM_W(0XB8, ctx->r29) = ctx->f2.u32l;
    after_6:
    // 0x800766DC: andi        $v0, $v0, 0x7F
    ctx->r2 = ctx->r2 & 0X7F;
    // 0x800766E0: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x800766E4: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x800766E8: sub.s       $f0, $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f20.fl;
    // 0x800766EC: div.s       $f0, $f0, $f28
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f28.fl);
    // 0x800766F0: add.s       $f0, $f24, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f24.fl + ctx->f0.fl;
    // 0x800766F4: c.le.s      $f0, $f26
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 26);
    c1cs = ctx->f0.fl <= ctx->f26.fl;
    // 0x800766F8: nop

    // 0x800766FC: bc1f        L_80076710
    if (!c1cs) {
        // 0x80076700: swc1        $f0, 0x84($sp)
        MEM_W(0X84, ctx->r29) = ctx->f0.u32l;
            goto L_80076710;
    }
    // 0x80076700: swc1        $f0, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->f0.u32l;
    // 0x80076704: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80076708: lwc1        $f0, -0x2DB8($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X2DB8);
    // 0x8007670C: swc1        $f0, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->f0.u32l;
L_80076710:
    // 0x80076710: lui         $a0, 0x8007
    ctx->r4 = S32(0X8007 << 16);
    // 0x80076714: addiu       $a0, $a0, 0x413C
    ctx->r4 = ADD32(ctx->r4, 0X413C);
    // 0x80076718: addiu       $a1, $sp, 0x78
    ctx->r5 = ADD32(ctx->r29, 0X78);
    // 0x8007671C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80076720: jal         0x8003FFEC
    // 0x80076724: addiu       $a3, $zero, 0xA
    ctx->r7 = ADD32(0, 0XA);
    func_8003FFEC(rdram, ctx);
        goto after_7;
    // 0x80076724: addiu       $a3, $zero, 0xA
    ctx->r7 = ADD32(0, 0XA);
    after_7:
    // 0x80076728: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x8007672C: slt         $v0, $s1, $s2
    ctx->r2 = SIGNED(ctx->r17) < SIGNED(ctx->r18) ? 1 : 0;
    // 0x80076730: bne         $v0, $zero, L_8007668C
    if (ctx->r2 != 0) {
        // 0x80076734: nop
    
            goto L_8007668C;
    }
    // 0x80076734: nop

L_80076738:
    // 0x80076738: ori         $a0, $zero, 0x8002
    ctx->r4 = 0 | 0X8002;
    // 0x8007673C: addiu       $s1, $sp, 0xA0
    ctx->r17 = ADD32(ctx->r29, 0XA0);
    // 0x80076740: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    // 0x80076744: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // 0x80076748: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8007674C: lwc1        $f20, -0x2DB4($at)
    ctx->f20.u32l = MEM_W(ctx->r1, -0X2DB4);
    // 0x80076750: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80076754: lwc1        $f0, -0x2DB0($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X2DB0);
    // 0x80076758: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8007675C: lwc1        $f24, -0x2DAC($at)
    ctx->f24.u32l = MEM_W(ctx->r1, -0X2DAC);
    // 0x80076760: addiu       $a3, $sp, 0x90
    ctx->r7 = ADD32(ctx->r29, 0X90);
    // 0x80076764: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    // 0x80076768: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    // 0x8007676C: swc1        $f20, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f20.u32l;
    // 0x80076770: jal         0x80072684
    // 0x80076774: swc1        $f24, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f24.u32l;
    func_80072684(rdram, ctx);
        goto after_8;
    // 0x80076774: swc1        $f24, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f24.u32l;
    after_8:
    // 0x80076778: lwc1        $f0, 0xA4($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0XA4);
    // 0x8007677C: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80076780: lwc1        $f2, -0x2DA8($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X2DA8);
    // 0x80076784: lui         $a1, 0x3E4C
    ctx->r5 = S32(0X3E4C << 16);
    // 0x80076788: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    // 0x8007678C: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x80076790: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x80076794: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x80076798: jal         0x80073E4C
    // 0x8007679C: swc1        $f0, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->f0.u32l;
    func_80073E4C(rdram, ctx);
        goto after_9;
    // 0x8007679C: swc1        $f0, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->f0.u32l;
    after_9:
    // 0x800767A0: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x800767A4: lui         $a2, 0x8014
    ctx->r6 = S32(0X8014 << 16);
    // 0x800767A8: lui         $a1, 0x4020
    ctx->r5 = S32(0X4020 << 16);
    // 0x800767AC: jal         0x80061380
    // 0x800767B0: addiu       $a2, $a2, -0x6740
    ctx->r6 = ADD32(ctx->r6, -0X6740);
    func_80061380(rdram, ctx);
        goto after_10;
    // 0x800767B0: addiu       $a2, $a2, -0x6740
    ctx->r6 = ADD32(ctx->r6, -0X6740);
    after_10:
    // 0x800767B4: jal         0x80003430
    // 0x800767B8: nop

    rand_recomp(rdram, ctx);
        goto after_11;
    // 0x800767B8: nop

    after_11:
    // 0x800767BC: andi        $v0, $v0, 0x3
    ctx->r2 = ctx->r2 & 0X3;
    // 0x800767C0: beq         $v0, $zero, L_800768A8
    if (ctx->r2 == 0) {
        // 0x800767C4: addiu       $a0, $sp, 0x48
        ctx->r4 = ADD32(ctx->r29, 0X48);
            goto L_800768A8;
    }
    // 0x800767C4: addiu       $a0, $sp, 0x48
    ctx->r4 = ADD32(ctx->r29, 0X48);
    // 0x800767C8: addiu       $s0, $sp, 0x58
    ctx->r16 = ADD32(ctx->r29, 0X58);
    // 0x800767CC: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x800767D0: lui         $a2, 0x3F19
    ctx->r6 = S32(0X3F19 << 16);
    // 0x800767D4: ori         $a2, $a2, 0x999A
    ctx->r6 = ctx->r6 | 0X999A;
    // 0x800767D8: addiu       $a3, $zero, 0x28
    ctx->r7 = ADD32(0, 0X28);
    // 0x800767DC: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x800767E0: jal         0x8007202C
    // 0x800767E4: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    func_8007202C(rdram, ctx);
        goto after_12;
    // 0x800767E4: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    after_12:
    // 0x800767E8: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x800767EC: lwc1        $f6, 0xA0($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XA0);
    // 0x800767F0: lwc1        $f0, 0x48($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X48);
    // 0x800767F4: lwc1        $f4, 0xA4($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XA4);
    // 0x800767F8: mfc1        $a1, $f24
    ctx->r5 = (int32_t)ctx->f24.u32l;
    // 0x800767FC: add.s       $f6, $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f0.fl;
    // 0x80076800: lwc1        $f0, 0x4C($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x80076804: lwc1        $f2, 0x50($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X50);
    // 0x80076808: add.s       $f4, $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f0.fl;
    // 0x8007680C: lwc1        $f0, 0xA8($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0XA8);
    // 0x80076810: lui         $a2, 0x3FC0
    ctx->r6 = S32(0X3FC0 << 16);
    // 0x80076814: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x80076818: swc1        $f6, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->f6.u32l;
    // 0x8007681C: swc1        $f4, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->f4.u32l;
    // 0x80076820: jal         0x80072300
    // 0x80076824: swc1        $f0, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->f0.u32l;
    func_80072300(rdram, ctx);
        goto after_13;
    // 0x80076824: swc1        $f0, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->f0.u32l;
    after_13:
    // 0x80076828: jal         0x80003430
    // 0x8007682C: nop

    rand_recomp(rdram, ctx);
        goto after_14;
    // 0x8007682C: nop

    after_14:
    // 0x80076830: andi        $v0, $v0, 0x7F
    ctx->r2 = ctx->r2 & 0X7F;
    // 0x80076834: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80076838: lwc1        $f22, -0x2DA4($at)
    ctx->f22.u32l = MEM_W(ctx->r1, -0X2DA4);
    // 0x8007683C: mtc1        $v0, $f20
    ctx->f20.u32l = ctx->r2;
    // 0x80076840: cvt.s.w     $f20, $f20
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    ctx->f20.fl = CVT_S_W(ctx->f20.u32l);
    // 0x80076844: sub.s       $f20, $f20, $f22
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f20.fl = ctx->f20.fl - ctx->f22.fl;
    // 0x80076848: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8007684C: lwc1        $f0, -0x2DA0($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X2DA0);
    // 0x80076850: mul.s       $f20, $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f20.fl = MUL_S(ctx->f20.fl, ctx->f0.fl);
    // 0x80076854: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80076858: lwc1        $f0, -0x2D9C($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X2D9C);
    // 0x8007685C: add.s       $f20, $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f20.fl = ctx->f20.fl + ctx->f0.fl;
    // 0x80076860: jal         0x80003430
    // 0x80076864: neg.s       $f20, $f20
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); 
    ctx->f20.fl = -ctx->f20.fl;
    rand_recomp(rdram, ctx);
        goto after_15;
    // 0x80076864: neg.s       $f20, $f20
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); 
    ctx->f20.fl = -ctx->f20.fl;
    after_15:
    // 0x80076868: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x8007686C: andi        $v0, $v0, 0x7F
    ctx->r2 = ctx->r2 & 0X7F;
    // 0x80076870: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x80076874: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x80076878: sub.s       $f0, $f0, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f22.fl;
    // 0x8007687C: lui         $a2, 0x4120
    ctx->r6 = S32(0X4120 << 16);
    // 0x80076880: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80076884: lwc1        $f2, -0x2D98($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X2D98);
    // 0x80076888: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8007688C: lwc1        $f4, -0x2D94($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X2D94);
    // 0x80076890: div.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f2.fl);
    // 0x80076894: add.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f4.fl;
    // 0x80076898: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x8007689C: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x800768A0: jal         0x80072384
    // 0x800768A4: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    func_80072384(rdram, ctx);
        goto after_16;
    // 0x800768A4: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    after_16:
L_800768A8:
    // 0x800768A8: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x800768AC: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    // 0x800768B0: addiu       $a2, $sp, 0x48
    ctx->r6 = ADD32(ctx->r29, 0X48);
    // 0x800768B4: lui         $a3, 0x4190
    ctx->r7 = S32(0X4190 << 16);
    // 0x800768B8: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800768BC: addiu       $v0, $zero, 0x7D
    ctx->r2 = ADD32(0, 0X7D);
    // 0x800768C0: swc1        $f0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f0.u32l;
    // 0x800768C4: swc1        $f0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f0.u32l;
    // 0x800768C8: swc1        $f0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f0.u32l;
    // 0x800768CC: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // 0x800768D0: addiu       $v0, $zero, 0x5A
    ctx->r2 = ADD32(0, 0X5A);
    // 0x800768D4: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x800768D8: addiu       $v0, $zero, 0x14
    ctx->r2 = ADD32(0, 0X14);
    // 0x800768DC: swc1        $f24, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f24.u32l;
    // 0x800768E0: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x800768E4: jal         0x800989D8
    // 0x800768E8: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    func_800989D8(rdram, ctx);
        goto after_17;
    // 0x800768E8: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    after_17:
    // 0x800768EC: jal         0x80003430
    // 0x800768F0: nop

    rand_recomp(rdram, ctx);
        goto after_18;
    // 0x800768F0: nop

    after_18:
    // 0x800768F4: andi        $v0, $v0, 0x7F
    ctx->r2 = ctx->r2 & 0X7F;
    // 0x800768F8: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x800768FC: lwc1        $f2, -0x2D90($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X2D90);
    // 0x80076900: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x80076904: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x80076908: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x8007690C: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80076910: lwc1        $f2, -0x2D8C($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X2D8C);
    // 0x80076914: lui         $v1, 0x8014
    ctx->r3 = S32(0X8014 << 16);
    // 0x80076918: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x8007691C: abs.s       $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = fabsf(ctx->f0.fl);
    // 0x80076920: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80076924: mtc1        $s3, $f2
    ctx->f2.u32l = ctx->r19;
    // 0x80076928: cvt.s.w     $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    ctx->f2.fl = CVT_S_W(ctx->f2.u32l);
    // 0x8007692C: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80076930: lwc1        $f0, -0x2D88($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X2D88);
    // 0x80076934: add.s       $f4, $f4, $f24
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f24.fl;
    // 0x80076938: div.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = DIV_S(ctx->f2.fl, ctx->f0.fl);
    // 0x8007693C: lwc1        $f0, 0xBA4($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0XBA4);
    // 0x80076940: div.s       $f4, $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = DIV_S(ctx->f4.fl, ctx->f2.fl);
    // 0x80076944: add.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f4.fl;
    // 0x80076948: j           L_80076960
    // 0x8007694C: swc1        $f0, -0x574C($v1)
    MEM_W(-0X574C, ctx->r3) = ctx->f0.u32l;
        goto L_80076960;
    // 0x8007694C: swc1        $f0, -0x574C($v1)
    MEM_W(-0X574C, ctx->r3) = ctx->f0.u32l;
L_80076950:
    // 0x80076950: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80076954: lwc1        $f0, 0xBA4($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0XBA4);
    // 0x80076958: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x8007695C: swc1        $f0, -0x574C($v0)
    MEM_W(-0X574C, ctx->r2) = ctx->f0.u32l;
L_80076960:
    // 0x80076960: lw          $ra, 0xE8($sp)
    ctx->r31 = MEM_W(ctx->r29, 0XE8);
    // 0x80076964: lw          $s5, 0xE4($sp)
    ctx->r21 = MEM_W(ctx->r29, 0XE4);
    // 0x80076968: lw          $s4, 0xE0($sp)
    ctx->r20 = MEM_W(ctx->r29, 0XE0);
    // 0x8007696C: lw          $s3, 0xDC($sp)
    ctx->r19 = MEM_W(ctx->r29, 0XDC);
    // 0x80076970: lw          $s2, 0xD8($sp)
    ctx->r18 = MEM_W(ctx->r29, 0XD8);
    // 0x80076974: lw          $s1, 0xD4($sp)
    ctx->r17 = MEM_W(ctx->r29, 0XD4);
    // 0x80076978: lw          $s0, 0xD0($sp)
    ctx->r16 = MEM_W(ctx->r29, 0XD0);
    // 0x8007697C: ldc1        $f28, 0x110($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0X110);
    // 0x80076980: ldc1        $f26, 0x108($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X108);
    // 0x80076984: ldc1        $f24, 0x100($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X100);
    // 0x80076988: ldc1        $f22, 0xF8($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0XF8);
    // 0x8007698C: ldc1        $f20, 0xF0($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0XF0);
    // 0x80076990: jr          $ra
    // 0x80076994: addiu       $sp, $sp, 0x118
    ctx->r29 = ADD32(ctx->r29, 0X118);
    return;
    // 0x80076994: addiu       $sp, $sp, 0x118
    ctx->r29 = ADD32(ctx->r29, 0X118);
;}
RECOMP_FUNC void func_80076998(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80076998: addiu       $sp, $sp, -0xA0
    ctx->r29 = ADD32(ctx->r29, -0XA0);
    // 0x8007699C: mtc1        $a3, $f6
    ctx->f6.u32l = ctx->r7;
    // 0x800769A0: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x800769A4: lwc1        $f2, -0x2D84($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X2D84);
    // 0x800769A8: lwc1        $f0, 0xB0($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0XB0);
    // 0x800769AC: lw          $v1, 0xB4($sp)
    ctx->r3 = MEM_W(ctx->r29, 0XB4);
    // 0x800769B0: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x800769B4: lwc1        $f4, -0x2D80($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X2D80);
    // 0x800769B8: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x800769BC: lwc1        $f8, -0x2D7C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X2D7C);
    // 0x800769C0: addiu       $v0, $zero, 0x1E
    ctx->r2 = ADD32(0, 0X1E);
    // 0x800769C4: sw          $ra, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->r31;
    // 0x800769C8: sw          $s2, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->r18;
    // 0x800769CC: sw          $s1, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->r17;
    // 0x800769D0: sw          $s0, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->r16;
    // 0x800769D4: swc1        $f2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f2.u32l;
    // 0x800769D8: lw          $t0, 0x0($a1)
    ctx->r8 = MEM_W(ctx->r5, 0X0);
    // 0x800769DC: lw          $t1, 0x4($a1)
    ctx->r9 = MEM_W(ctx->r5, 0X4);
    // 0x800769E0: lw          $t2, 0x8($a1)
    ctx->r10 = MEM_W(ctx->r5, 0X8);
    // 0x800769E4: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    // 0x800769E8: sw          $t1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r9;
    // 0x800769EC: sw          $t2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r10;
    // 0x800769F0: sh          $v0, 0x4C($sp)
    MEM_H(0X4C, ctx->r29) = ctx->r2;
    // 0x800769F4: sh          $v0, 0x4E($sp)
    MEM_H(0X4E, ctx->r29) = ctx->r2;
    // 0x800769F8: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800769FC: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80076A00: lwc1        $f2, -0x2D78($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X2D78);
    // 0x80076A04: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
    // 0x80076A08: swc1        $f0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f0.u32l;
    // 0x80076A0C: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80076A10: lwc1        $f0, -0x2D74($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X2D74);
    // 0x80076A14: lw          $v0, 0xC08($v0)
    ctx->r2 = MEM_W(ctx->r2, 0XC08);
    // 0x80076A18: addu        $s2, $a2, $zero
    ctx->r18 = ADD32(ctx->r6, 0);
    // 0x80076A1C: swc1        $f2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f2.u32l;
    // 0x80076A20: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80076A24: lwc1        $f2, -0x2D70($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X2D70);
    // 0x80076A28: addu        $s1, $a0, $zero
    ctx->r17 = ADD32(ctx->r4, 0);
    // 0x80076A2C: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    // 0x80076A30: sw          $zero, 0x28($sp)
    MEM_W(0X28, ctx->r29) = 0;
    // 0x80076A34: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x80076A38: sw          $zero, 0x30($sp)
    MEM_W(0X30, ctx->r29) = 0;
    // 0x80076A3C: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    // 0x80076A40: swc1        $f4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f4.u32l;
    // 0x80076A44: swc1        $f4, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f4.u32l;
    // 0x80076A48: sw          $zero, 0x40($sp)
    MEM_W(0X40, ctx->r29) = 0;
    // 0x80076A4C: sw          $zero, 0x44($sp)
    MEM_W(0X44, ctx->r29) = 0;
    // 0x80076A50: sw          $zero, 0x54($sp)
    MEM_W(0X54, ctx->r29) = 0;
    // 0x80076A54: sw          $zero, 0x58($sp)
    MEM_W(0X58, ctx->r29) = 0;
    // 0x80076A58: sw          $zero, 0x60($sp)
    MEM_W(0X60, ctx->r29) = 0;
    // 0x80076A5C: swc1        $f8, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f8.u32l;
    // 0x80076A60: swc1        $f4, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f4.u32l;
    // 0x80076A64: mul.s       $f4, $f6, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f6.fl, ctx->f2.fl);
    // 0x80076A68: sw          $zero, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = 0;
    // 0x80076A6C: swc1        $f0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f0.u32l;
    // 0x80076A70: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80076A74: lwc1        $f0, -0x2D6C($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X2D6C);
    // 0x80076A78: addiu       $v0, $v0, 0x1C
    ctx->r2 = ADD32(ctx->r2, 0X1C);
    // 0x80076A7C: mul.s       $f6, $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x80076A80: sw          $v0, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r2;
    // 0x80076A84: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80076A88: sb          $v0, 0x7C($sp)
    MEM_B(0X7C, ctx->r29) = ctx->r2;
    // 0x80076A8C: mul.s       $f6, $f6, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f6.fl, ctx->f2.fl);
    // 0x80076A90: bne         $v1, $zero, L_80076ACC
    if (ctx->r3 != 0) {
        // 0x80076A94: swc1        $f2, 0x5C($sp)
        MEM_W(0X5C, ctx->r29) = ctx->f2.u32l;
            goto L_80076ACC;
    }
    // 0x80076A94: swc1        $f2, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f2.u32l;
    // 0x80076A98: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80076A9C: lw          $v1, 0xB70($v0)
    ctx->r3 = MEM_W(ctx->r2, 0XB70);
    // 0x80076AA0: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // 0x80076AA4: bne         $v1, $v0, L_80076AB8
    if (ctx->r3 != ctx->r2) {
        // 0x80076AA8: lui         $v0, 0x8013
        ctx->r2 = S32(0X8013 << 16);
            goto L_80076AB8;
    }
    // 0x80076AA8: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80076AAC: lw          $v0, 0xC04($v0)
    ctx->r2 = MEM_W(ctx->r2, 0XC04);
    // 0x80076AB0: j           L_80076AC0
    // 0x80076AB4: addiu       $v0, $v0, 0xC0
    ctx->r2 = ADD32(ctx->r2, 0XC0);
        goto L_80076AC0;
    // 0x80076AB4: addiu       $v0, $v0, 0xC0
    ctx->r2 = ADD32(ctx->r2, 0XC0);
L_80076AB8:
    // 0x80076AB8: lw          $v0, 0xC04($v0)
    ctx->r2 = MEM_W(ctx->r2, 0XC04);
    // 0x80076ABC: addiu       $v0, $v0, 0x80
    ctx->r2 = ADD32(ctx->r2, 0X80);
L_80076AC0:
    // 0x80076AC0: sw          $v0, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r2;
    // 0x80076AC4: j           L_80076AD4
    // 0x80076AC8: addiu       $v0, $zero, 0x10
    ctx->r2 = ADD32(0, 0X10);
        goto L_80076AD4;
    // 0x80076AC8: addiu       $v0, $zero, 0x10
    ctx->r2 = ADD32(0, 0X10);
L_80076ACC:
    // 0x80076ACC: addiu       $v0, $zero, 0x10
    ctx->r2 = ADD32(0, 0X10);
    // 0x80076AD0: sw          $v1, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r3;
L_80076AD4:
    // 0x80076AD4: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80076AD8: lwc1        $f0, -0x2D68($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X2D68);
    // 0x80076ADC: mul.s       $f0, $f4, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x80076AE0: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80076AE4: lwc1        $f2, -0x2D64($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X2D64);
    // 0x80076AE8: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x80076AEC: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80076AF0: lwc1        $f2, -0x2D60($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X2D60);
    // 0x80076AF4: c.le.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl <= ctx->f0.fl;
    // 0x80076AF8: nop

    // 0x80076AFC: bc1t        L_80076B14
    if (c1cs) {
        // 0x80076B00: sb          $v0, 0x7D($sp)
        MEM_B(0X7D, ctx->r29) = ctx->r2;
            goto L_80076B14;
    }
    // 0x80076B00: sb          $v0, 0x7D($sp)
    MEM_B(0X7D, ctx->r29) = ctx->r2;
    // 0x80076B04: trunc.w.s   $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    ctx->f10.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x80076B08: mfc1        $v1, $f10
    ctx->r3 = (int32_t)ctx->f10.u32l;
    // 0x80076B0C: j           L_80076B28
    // 0x80076B10: nop

        goto L_80076B28;
    // 0x80076B10: nop

L_80076B14:
    // 0x80076B14: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x80076B18: lui         $v0, 0x8000
    ctx->r2 = S32(0X8000 << 16);
    // 0x80076B1C: trunc.w.s   $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    ctx->f10.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x80076B20: mfc1        $v1, $f10
    ctx->r3 = (int32_t)ctx->f10.u32l;
    // 0x80076B24: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
L_80076B28:
    // 0x80076B28: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80076B2C: lwc1        $f0, -0x2D5C($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X2D5C);
    // 0x80076B30: mul.s       $f0, $f6, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x80076B34: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80076B38: lwc1        $f2, -0x2D58($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X2D58);
    // 0x80076B3C: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80076B40: lwc1        $f4, -0x2D54($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X2D54);
    // 0x80076B44: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x80076B48: c.le.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl <= ctx->f0.fl;
    // 0x80076B4C: nop

    // 0x80076B50: bc1t        L_80076B68
    if (c1cs) {
        // 0x80076B54: sh          $v1, 0x80($sp)
        MEM_H(0X80, ctx->r29) = ctx->r3;
            goto L_80076B68;
    }
    // 0x80076B54: sh          $v1, 0x80($sp)
    MEM_H(0X80, ctx->r29) = ctx->r3;
    // 0x80076B58: trunc.w.s   $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    ctx->f10.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x80076B5C: mfc1        $v1, $f10
    ctx->r3 = (int32_t)ctx->f10.u32l;
    // 0x80076B60: j           L_80076B80
    // 0x80076B64: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
        goto L_80076B80;
    // 0x80076B64: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
L_80076B68:
    // 0x80076B68: sub.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f4.fl;
    // 0x80076B6C: lui         $v0, 0x8000
    ctx->r2 = S32(0X8000 << 16);
    // 0x80076B70: trunc.w.s   $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    ctx->f10.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x80076B74: mfc1        $v1, $f10
    ctx->r3 = (int32_t)ctx->f10.u32l;
    // 0x80076B78: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x80076B7C: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
L_80076B80:
    // 0x80076B80: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
    // 0x80076B84: sh          $v0, 0x84($sp)
    MEM_H(0X84, ctx->r29) = ctx->r2;
    // 0x80076B88: lui         $v0, 0x900
    ctx->r2 = S32(0X900 << 16);
    // 0x80076B8C: sw          $v0, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r2;
    // 0x80076B90: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x80076B94: sh          $v1, 0x82($sp)
    MEM_H(0X82, ctx->r29) = ctx->r3;
    // 0x80076B98: jal         0x80041CBC
    // 0x80076B9C: sh          $v0, 0x8C($sp)
    MEM_H(0X8C, ctx->r29) = ctx->r2;
    func_80041CBC(rdram, ctx);
        goto after_0;
    // 0x80076B9C: sh          $v0, 0x8C($sp)
    MEM_H(0X8C, ctx->r29) = ctx->r2;
    after_0:
    // 0x80076BA0: andi        $s0, $v0, 0xFFFF
    ctx->r16 = ctx->r2 & 0XFFFF;
    // 0x80076BA4: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x80076BA8: lui         $a1, 0x8014
    ctx->r5 = S32(0X8014 << 16);
    // 0x80076BAC: jal         0x80041D08
    // 0x80076BB0: addiu       $a1, $a1, -0x5740
    ctx->r5 = ADD32(ctx->r5, -0X5740);
    func_80041D08(rdram, ctx);
        goto after_1;
    // 0x80076BB0: addiu       $a1, $a1, -0x5740
    ctx->r5 = ADD32(ctx->r5, -0X5740);
    after_1:
    // 0x80076BB4: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x80076BB8: andi        $a1, $s1, 0xFFFF
    ctx->r5 = ctx->r17 & 0XFFFF;
    // 0x80076BBC: addu        $a2, $s2, $zero
    ctx->r6 = ADD32(ctx->r18, 0);
    // 0x80076BC0: jal         0x80041D8C
    // 0x80076BC4: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    func_80041D8C(rdram, ctx);
        goto after_2;
    // 0x80076BC4: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    after_2:
    // 0x80076BC8: addu        $v0, $s0, $zero
    ctx->r2 = ADD32(ctx->r16, 0);
    // 0x80076BCC: lw          $ra, 0x9C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X9C);
    // 0x80076BD0: lw          $s2, 0x98($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X98);
    // 0x80076BD4: lw          $s1, 0x94($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X94);
    // 0x80076BD8: lw          $s0, 0x90($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X90);
    // 0x80076BDC: jr          $ra
    // 0x80076BE0: addiu       $sp, $sp, 0xA0
    ctx->r29 = ADD32(ctx->r29, 0XA0);
    return;
    // 0x80076BE0: addiu       $sp, $sp, 0xA0
    ctx->r29 = ADD32(ctx->r29, 0XA0);
;}
RECOMP_FUNC void func_80076BE4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80076BE4: addiu       $sp, $sp, -0x98
    ctx->r29 = ADD32(ctx->r29, -0X98);
    // 0x80076BE8: sw          $s7, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r23;
    // 0x80076BEC: addu        $s7, $a0, $zero
    ctx->r23 = ADD32(ctx->r4, 0);
    // 0x80076BF0: sw          $s2, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r18;
    // 0x80076BF4: andi        $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 & 0XFFFF;
    // 0x80076BF8: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x80076BFC: sw          $ra, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r31;
    // 0x80076C00: sw          $s6, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r22;
    // 0x80076C04: sw          $s5, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r21;
    // 0x80076C08: sw          $s4, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r20;
    // 0x80076C0C: sw          $s3, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r19;
    // 0x80076C10: sw          $s1, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r17;
    // 0x80076C14: sw          $s0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r16;
    // 0x80076C18: sdc1        $f20, 0x90($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X90, ctx->r29);
    // 0x80076C1C: lw          $s5, 0x4($s7)
    ctx->r21 = MEM_W(ctx->r23, 0X4);
    // 0x80076C20: beq         $a1, $v0, L_80077080
    if (ctx->r5 == ctx->r2) {
        // 0x80076C24: addu        $s2, $a2, $zero
        ctx->r18 = ADD32(ctx->r6, 0);
            goto L_80077080;
    }
    // 0x80076C24: addu        $s2, $a2, $zero
    ctx->r18 = ADD32(ctx->r6, 0);
    // 0x80076C28: slti        $v0, $a1, 0x3
    ctx->r2 = SIGNED(ctx->r5) < 0X3 ? 1 : 0;
    // 0x80076C2C: beq         $v0, $zero, L_80076C44
    if (ctx->r2 == 0) {
        // 0x80076C30: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80076C44;
    }
    // 0x80076C30: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80076C34: beq         $a1, $v0, L_80076C60
    if (ctx->r5 == ctx->r2) {
        // 0x80076C38: lui         $s0, 0x8004
        ctx->r16 = S32(0X8004 << 16);
            goto L_80076C60;
    }
    // 0x80076C38: lui         $s0, 0x8004
    ctx->r16 = S32(0X8004 << 16);
    // 0x80076C3C: j           L_8007721C
    // 0x80076C40: nop

        goto L_8007721C;
    // 0x80076C40: nop

L_80076C44:
    // 0x80076C44: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x80076C48: beq         $a1, $v0, L_800770A0
    if (ctx->r5 == ctx->r2) {
        // 0x80076C4C: addiu       $v0, $zero, 0x4
        ctx->r2 = ADD32(0, 0X4);
            goto L_800770A0;
    }
    // 0x80076C4C: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // 0x80076C50: beq         $a1, $v0, L_800771C4
    if (ctx->r5 == ctx->r2) {
        // 0x80076C54: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_800771C4;
    }
    // 0x80076C54: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80076C58: j           L_80077220
    // 0x80076C5C: nop

        goto L_80077220;
    // 0x80076C5C: nop

L_80076C60:
    // 0x80076C60: addiu       $s0, $s0, -0x2D50
    ctx->r16 = ADD32(ctx->r16, -0X2D50);
    // 0x80076C64: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x80076C68: jal         0x80057338
    // 0x80076C6C: addu        $s6, $s2, $zero
    ctx->r22 = ADD32(ctx->r18, 0);
    func_80057338(rdram, ctx);
        goto after_0;
    // 0x80076C6C: addu        $s6, $s2, $zero
    ctx->r22 = ADD32(ctx->r18, 0);
    after_0:
    // 0x80076C70: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // 0x80076C74: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x80076C78: lui         $a2, 0x901
    ctx->r6 = S32(0X901 << 16);
    // 0x80076C7C: addu        $a3, $a1, $zero
    ctx->r7 = ADD32(ctx->r5, 0);
    // 0x80076C80: jal         0x8005955C
    // 0x80076C84: sw          $a0, 0x78($s5)
    MEM_W(0X78, ctx->r21) = ctx->r4;
    func_8005955C(rdram, ctx);
        goto after_1;
    // 0x80076C84: sw          $a0, 0x78($s5)
    MEM_W(0X78, ctx->r21) = ctx->r4;
    after_1:
    // 0x80076C88: jal         0x80057338
    // 0x80076C8C: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_80057338(rdram, ctx);
        goto after_2;
    // 0x80076C8C: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_2:
    // 0x80076C90: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // 0x80076C94: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x80076C98: lui         $a2, 0x901
    ctx->r6 = S32(0X901 << 16);
    // 0x80076C9C: addu        $a3, $a1, $zero
    ctx->r7 = ADD32(ctx->r5, 0);
    // 0x80076CA0: jal         0x8005955C
    // 0x80076CA4: sw          $a0, 0x7C($s5)
    MEM_W(0X7C, ctx->r21) = ctx->r4;
    func_8005955C(rdram, ctx);
        goto after_3;
    // 0x80076CA4: sw          $a0, 0x7C($s5)
    MEM_W(0X7C, ctx->r21) = ctx->r4;
    after_3:
    // 0x80076CA8: lw          $v0, 0x0($s6)
    ctx->r2 = MEM_W(ctx->r22, 0X0);
    // 0x80076CAC: addu        $v1, $s5, $zero
    ctx->r3 = ADD32(ctx->r21, 0);
    // 0x80076CB0: addiu       $a0, $v0, 0x30
    ctx->r4 = ADD32(ctx->r2, 0X30);
L_80076CB4:
    // 0x80076CB4: lw          $t0, 0x0($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X0);
    // 0x80076CB8: lw          $t1, 0x4($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X4);
    // 0x80076CBC: lw          $t2, 0x8($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X8);
    // 0x80076CC0: lw          $t3, 0xC($v0)
    ctx->r11 = MEM_W(ctx->r2, 0XC);
    // 0x80076CC4: sw          $t0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r8;
    // 0x80076CC8: sw          $t1, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r9;
    // 0x80076CCC: sw          $t2, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r10;
    // 0x80076CD0: sw          $t3, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r11;
    // 0x80076CD4: addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
    // 0x80076CD8: bne         $v0, $a0, L_80076CB4
    if (ctx->r2 != ctx->r4) {
        // 0x80076CDC: addiu       $v1, $v1, 0x10
        ctx->r3 = ADD32(ctx->r3, 0X10);
            goto L_80076CB4;
    }
    // 0x80076CDC: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
    // 0x80076CE0: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    // 0x80076CE4: addiu       $s4, $s5, 0x18
    ctx->r20 = ADD32(ctx->r21, 0X18);
    // 0x80076CE8: addu        $a1, $s4, $zero
    ctx->r5 = ADD32(ctx->r20, 0);
    // 0x80076CEC: addiu       $s3, $s5, 0xC
    ctx->r19 = ADD32(ctx->r21, 0XC);
    // 0x80076CF0: jal         0x80019548
    // 0x80076CF4: addu        $a2, $s3, $zero
    ctx->r6 = ADD32(ctx->r19, 0);
    func_80019548(rdram, ctx);
        goto after_4;
    // 0x80076CF4: addu        $a2, $s3, $zero
    ctx->r6 = ADD32(ctx->r19, 0);
    after_4:
    // 0x80076CF8: jal         0x80003430
    // 0x80076CFC: nop

    rand_recomp(rdram, ctx);
        goto after_5;
    // 0x80076CFC: nop

    after_5:
    // 0x80076D00: andi        $v0, $v0, 0x7F
    ctx->r2 = ctx->r2 & 0X7F;
    // 0x80076D04: mtc1        $v0, $f4
    ctx->f4.u32l = ctx->r2;
    // 0x80076D08: cvt.s.w     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80076D0C: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80076D10: lwc1        $f0, -0x2D48($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X2D48);
    // 0x80076D14: lwc1        $f2, 0x10($s6)
    ctx->f2.u32l = MEM_W(ctx->r22, 0X10);
    // 0x80076D18: sub.s       $f4, $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f4.fl - ctx->f0.fl;
    // 0x80076D1C: div.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f2.fl);
    // 0x80076D20: lwc1        $f2, 0x18($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X18);
    // 0x80076D24: div.s       $f4, $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = DIV_S(ctx->f4.fl, ctx->f0.fl);
    // 0x80076D28: mul.s       $f2, $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f4.fl);
    // 0x80076D2C: lwc1        $f0, 0x0($s5)
    ctx->f0.u32l = MEM_W(ctx->r21, 0X0);
    // 0x80076D30: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x80076D34: lwc1        $f2, 0x1C($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x80076D38: mul.s       $f2, $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f4.fl);
    // 0x80076D3C: swc1        $f0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f0.u32l;
    // 0x80076D40: lwc1        $f0, 0x4($s5)
    ctx->f0.u32l = MEM_W(ctx->r21, 0X4);
    // 0x80076D44: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x80076D48: lwc1        $f2, 0x20($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X20);
    // 0x80076D4C: mul.s       $f2, $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f4.fl);
    // 0x80076D50: swc1        $f0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f0.u32l;
    // 0x80076D54: lwc1        $f0, 0x8($s5)
    ctx->f0.u32l = MEM_W(ctx->r21, 0X8);
    // 0x80076D58: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x80076D5C: swc1        $f0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f0.u32l;
    // 0x80076D60: lwc1        $f0, 0x28($s6)
    ctx->f0.u32l = MEM_W(ctx->r22, 0X28);
    // 0x80076D64: lhu         $a0, 0x2C($s6)
    ctx->r4 = MEM_HU(ctx->r22, 0X2C);
    // 0x80076D68: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    // 0x80076D6C: lw          $v0, 0xC($s6)
    ctx->r2 = MEM_W(ctx->r22, 0XC);
    // 0x80076D70: sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    // 0x80076D74: lw          $a2, 0x4($s6)
    ctx->r6 = MEM_W(ctx->r22, 0X4);
    // 0x80076D78: lw          $a3, 0x24($s6)
    ctx->r7 = MEM_W(ctx->r22, 0X24);
    // 0x80076D7C: jal         0x80076998
    // 0x80076D80: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    func_80076998(rdram, ctx);
        goto after_6;
    // 0x80076D80: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    after_6:
    // 0x80076D84: lw          $t0, 0xC($s5)
    ctx->r8 = MEM_W(ctx->r21, 0XC);
    // 0x80076D88: lw          $t1, 0x10($s5)
    ctx->r9 = MEM_W(ctx->r21, 0X10);
    // 0x80076D8C: lw          $t2, 0x14($s5)
    ctx->r10 = MEM_W(ctx->r21, 0X14);
    // 0x80076D90: sw          $t0, 0x60($s5)
    MEM_W(0X60, ctx->r21) = ctx->r8;
    // 0x80076D94: sw          $t1, 0x64($s5)
    MEM_W(0X64, ctx->r21) = ctx->r9;
    // 0x80076D98: sw          $t2, 0x68($s5)
    MEM_W(0X68, ctx->r21) = ctx->r10;
    // 0x80076D9C: lw          $t0, 0x18($s5)
    ctx->r8 = MEM_W(ctx->r21, 0X18);
    // 0x80076DA0: lw          $t1, 0x1C($s5)
    ctx->r9 = MEM_W(ctx->r21, 0X1C);
    // 0x80076DA4: lw          $t2, 0x20($s5)
    ctx->r10 = MEM_W(ctx->r21, 0X20);
    // 0x80076DA8: sw          $t0, 0x6C($s5)
    MEM_W(0X6C, ctx->r21) = ctx->r8;
    // 0x80076DAC: sw          $t1, 0x70($s5)
    MEM_W(0X70, ctx->r21) = ctx->r9;
    // 0x80076DB0: sw          $t2, 0x74($s5)
    MEM_W(0X74, ctx->r21) = ctx->r10;
    // 0x80076DB4: lwc1        $f2, 0x18($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X18);
    // 0x80076DB8: lwc1        $f0, 0x10($s6)
    ctx->f0.u32l = MEM_W(ctx->r22, 0X10);
    // 0x80076DBC: mul.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x80076DC0: lwc1        $f0, 0x0($s5)
    ctx->f0.u32l = MEM_W(ctx->r21, 0X0);
    // 0x80076DC4: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x80076DC8: swc1        $f0, 0x0($s5)
    MEM_W(0X0, ctx->r21) = ctx->f0.u32l;
    // 0x80076DCC: lwc1        $f2, 0x1C($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x80076DD0: lwc1        $f0, 0x10($s6)
    ctx->f0.u32l = MEM_W(ctx->r22, 0X10);
    // 0x80076DD4: mul.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x80076DD8: lwc1        $f0, 0x4($s5)
    ctx->f0.u32l = MEM_W(ctx->r21, 0X4);
    // 0x80076DDC: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x80076DE0: swc1        $f0, 0x4($s5)
    MEM_W(0X4, ctx->r21) = ctx->f0.u32l;
    // 0x80076DE4: lwc1        $f2, 0x20($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X20);
    // 0x80076DE8: lwc1        $f0, 0x10($s6)
    ctx->f0.u32l = MEM_W(ctx->r22, 0X10);
    // 0x80076DEC: mul.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x80076DF0: addiu       $s2, $sp, 0x38
    ctx->r18 = ADD32(ctx->r29, 0X38);
    // 0x80076DF4: lwc1        $f0, 0x8($s5)
    ctx->f0.u32l = MEM_W(ctx->r21, 0X8);
    // 0x80076DF8: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // 0x80076DFC: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x80076E00: lui         $a2, 0x40A0
    ctx->r6 = S32(0X40A0 << 16);
    // 0x80076E04: addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    // 0x80076E08: jal         0x8001D240
    // 0x80076E0C: swc1        $f0, 0x8($s5)
    MEM_W(0X8, ctx->r21) = ctx->f0.u32l;
    func_8001D240(rdram, ctx);
        goto after_7;
    // 0x80076E0C: swc1        $f0, 0x8($s5)
    MEM_W(0X8, ctx->r21) = ctx->f0.u32l;
    after_7:
    // 0x80076E10: addiu       $s1, $sp, 0x48
    ctx->r17 = ADD32(ctx->r29, 0X48);
    // 0x80076E14: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x80076E18: lw          $a2, 0x1C($s6)
    ctx->r6 = MEM_W(ctx->r22, 0X1C);
    // 0x80076E1C: jal         0x8001D240
    // 0x80076E20: addu        $a1, $s3, $zero
    ctx->r5 = ADD32(ctx->r19, 0);
    func_8001D240(rdram, ctx);
        goto after_8;
    // 0x80076E20: addu        $a1, $s3, $zero
    ctx->r5 = ADD32(ctx->r19, 0);
    after_8:
    // 0x80076E24: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // 0x80076E28: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    // 0x80076E2C: addiu       $s0, $sp, 0x58
    ctx->r16 = ADD32(ctx->r29, 0X58);
    // 0x80076E30: jal         0x8001D2C0
    // 0x80076E34: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    func_8001D2C0(rdram, ctx);
        goto after_9;
    // 0x80076E34: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    after_9:
    // 0x80076E38: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x80076E3C: lw          $t0, 0x58($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X58);
    // 0x80076E40: lw          $t1, 0x5C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X5C);
    // 0x80076E44: lw          $t2, 0x60($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X60);
    // 0x80076E48: lw          $t3, 0x64($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X64);
    // 0x80076E4C: sw          $t0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r8;
    // 0x80076E50: sw          $t1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r9;
    // 0x80076E54: sw          $t2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r10;
    // 0x80076E58: sw          $t3, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r11;
    // 0x80076E5C: lw          $a2, 0x18($s6)
    ctx->r6 = MEM_W(ctx->r22, 0X18);
    // 0x80076E60: jal         0x8001D240
    // 0x80076E64: addu        $a1, $s4, $zero
    ctx->r5 = ADD32(ctx->r20, 0);
    func_8001D240(rdram, ctx);
        goto after_10;
    // 0x80076E64: addu        $a1, $s4, $zero
    ctx->r5 = ADD32(ctx->r20, 0);
    after_10:
    // 0x80076E68: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x80076E6C: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x80076E70: jal         0x8001D2C0
    // 0x80076E74: addu        $a2, $s2, $zero
    ctx->r6 = ADD32(ctx->r18, 0);
    func_8001D2C0(rdram, ctx);
        goto after_11;
    // 0x80076E74: addu        $a2, $s2, $zero
    ctx->r6 = ADD32(ctx->r18, 0);
    after_11:
    // 0x80076E78: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // 0x80076E7C: addu        $a1, $s3, $zero
    ctx->r5 = ADD32(ctx->r19, 0);
    // 0x80076E80: jal         0x8001D3C4
    // 0x80076E84: addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    func_8001D3C4(rdram, ctx);
        goto after_12;
    // 0x80076E84: addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    after_12:
    // 0x80076E88: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // 0x80076E8C: addu        $a1, $s4, $zero
    ctx->r5 = ADD32(ctx->r20, 0);
    // 0x80076E90: jal         0x8001D3C4
    // 0x80076E94: addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    func_8001D3C4(rdram, ctx);
        goto after_13;
    // 0x80076E94: addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    after_13:
    // 0x80076E98: lw          $v0, 0x0($s6)
    ctx->r2 = MEM_W(ctx->r22, 0X0);
    // 0x80076E9C: addiu       $v1, $s5, 0x30
    ctx->r3 = ADD32(ctx->r21, 0X30);
    // 0x80076EA0: addiu       $a0, $v0, 0x30
    ctx->r4 = ADD32(ctx->r2, 0X30);
L_80076EA4:
    // 0x80076EA4: lw          $t0, 0x0($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X0);
    // 0x80076EA8: lw          $t1, 0x4($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X4);
    // 0x80076EAC: lw          $t2, 0x8($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X8);
    // 0x80076EB0: lw          $t3, 0xC($v0)
    ctx->r11 = MEM_W(ctx->r2, 0XC);
    // 0x80076EB4: sw          $t0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r8;
    // 0x80076EB8: sw          $t1, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r9;
    // 0x80076EBC: sw          $t2, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r10;
    // 0x80076EC0: sw          $t3, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r11;
    // 0x80076EC4: addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
    // 0x80076EC8: bne         $v0, $a0, L_80076EA4
    if (ctx->r2 != ctx->r4) {
        // 0x80076ECC: addiu       $v1, $v1, 0x10
        ctx->r3 = ADD32(ctx->r3, 0X10);
            goto L_80076EA4;
    }
    // 0x80076ECC: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
    // 0x80076ED0: lwc1        $f2, 0x18($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X18);
    // 0x80076ED4: lwc1        $f0, 0x10($s6)
    ctx->f0.u32l = MEM_W(ctx->r22, 0X10);
    // 0x80076ED8: mul.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x80076EDC: lwc1        $f0, 0x30($s5)
    ctx->f0.u32l = MEM_W(ctx->r21, 0X30);
    // 0x80076EE0: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x80076EE4: swc1        $f0, 0x30($s5)
    MEM_W(0X30, ctx->r21) = ctx->f0.u32l;
    // 0x80076EE8: lwc1        $f2, 0x1C($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x80076EEC: lwc1        $f0, 0x10($s6)
    ctx->f0.u32l = MEM_W(ctx->r22, 0X10);
    // 0x80076EF0: mul.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x80076EF4: lwc1        $f0, 0x34($s5)
    ctx->f0.u32l = MEM_W(ctx->r21, 0X34);
    // 0x80076EF8: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x80076EFC: swc1        $f0, 0x34($s5)
    MEM_W(0X34, ctx->r21) = ctx->f0.u32l;
    // 0x80076F00: lwc1        $f2, 0x20($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X20);
    // 0x80076F04: lwc1        $f0, 0x10($s6)
    ctx->f0.u32l = MEM_W(ctx->r22, 0X10);
    // 0x80076F08: mul.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x80076F0C: addiu       $s2, $sp, 0x38
    ctx->r18 = ADD32(ctx->r29, 0X38);
    // 0x80076F10: lwc1        $f0, 0x38($s5)
    ctx->f0.u32l = MEM_W(ctx->r21, 0X38);
    // 0x80076F14: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // 0x80076F18: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x80076F1C: lui         $a2, 0x40A0
    ctx->r6 = S32(0X40A0 << 16);
    // 0x80076F20: addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    // 0x80076F24: jal         0x8001D240
    // 0x80076F28: swc1        $f0, 0x38($s5)
    MEM_W(0X38, ctx->r21) = ctx->f0.u32l;
    func_8001D240(rdram, ctx);
        goto after_14;
    // 0x80076F28: swc1        $f0, 0x38($s5)
    MEM_W(0X38, ctx->r21) = ctx->f0.u32l;
    after_14:
    // 0x80076F2C: addiu       $s1, $sp, 0x48
    ctx->r17 = ADD32(ctx->r29, 0X48);
    // 0x80076F30: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x80076F34: lwc1        $f0, 0x1C($s6)
    ctx->f0.u32l = MEM_W(ctx->r22, 0X1C);
    // 0x80076F38: addiu       $s4, $s5, 0x3C
    ctx->r20 = ADD32(ctx->r21, 0X3C);
    // 0x80076F3C: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
    // 0x80076F40: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80076F44: jal         0x8001D240
    // 0x80076F48: addu        $a1, $s4, $zero
    ctx->r5 = ADD32(ctx->r20, 0);
    func_8001D240(rdram, ctx);
        goto after_15;
    // 0x80076F48: addu        $a1, $s4, $zero
    ctx->r5 = ADD32(ctx->r20, 0);
    after_15:
    // 0x80076F4C: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // 0x80076F50: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    // 0x80076F54: addiu       $s0, $sp, 0x58
    ctx->r16 = ADD32(ctx->r29, 0X58);
    // 0x80076F58: jal         0x8001D2C0
    // 0x80076F5C: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    func_8001D2C0(rdram, ctx);
        goto after_16;
    // 0x80076F5C: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    after_16:
    // 0x80076F60: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x80076F64: lw          $t0, 0x58($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X58);
    // 0x80076F68: lw          $t1, 0x5C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X5C);
    // 0x80076F6C: lw          $t2, 0x60($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X60);
    // 0x80076F70: lw          $t3, 0x64($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X64);
    // 0x80076F74: sw          $t0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r8;
    // 0x80076F78: sw          $t1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r9;
    // 0x80076F7C: sw          $t2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r10;
    // 0x80076F80: sw          $t3, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r11;
    // 0x80076F84: lwc1        $f0, 0x18($s6)
    ctx->f0.u32l = MEM_W(ctx->r22, 0X18);
    // 0x80076F88: addiu       $s3, $s5, 0x48
    ctx->r19 = ADD32(ctx->r21, 0X48);
    // 0x80076F8C: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
    // 0x80076F90: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80076F94: jal         0x8001D240
    // 0x80076F98: addu        $a1, $s3, $zero
    ctx->r5 = ADD32(ctx->r19, 0);
    func_8001D240(rdram, ctx);
        goto after_17;
    // 0x80076F98: addu        $a1, $s3, $zero
    ctx->r5 = ADD32(ctx->r19, 0);
    after_17:
    // 0x80076F9C: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x80076FA0: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x80076FA4: jal         0x8001D2C0
    // 0x80076FA8: addu        $a2, $s2, $zero
    ctx->r6 = ADD32(ctx->r18, 0);
    func_8001D2C0(rdram, ctx);
        goto after_18;
    // 0x80076FA8: addu        $a2, $s2, $zero
    ctx->r6 = ADD32(ctx->r18, 0);
    after_18:
    // 0x80076FAC: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // 0x80076FB0: addu        $a1, $s4, $zero
    ctx->r5 = ADD32(ctx->r20, 0);
    // 0x80076FB4: jal         0x8001D3C4
    // 0x80076FB8: addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    func_8001D3C4(rdram, ctx);
        goto after_19;
    // 0x80076FB8: addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    after_19:
    // 0x80076FBC: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // 0x80076FC0: addu        $a1, $s3, $zero
    ctx->r5 = ADD32(ctx->r19, 0);
    // 0x80076FC4: jal         0x8001D3C4
    // 0x80076FC8: addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    func_8001D3C4(rdram, ctx);
        goto after_20;
    // 0x80076FC8: addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    after_20:
    // 0x80076FCC: lw          $v0, 0x8($s6)
    ctx->r2 = MEM_W(ctx->r22, 0X8);
    // 0x80076FD0: lbu         $v0, 0x0($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X0);
    // 0x80076FD4: sb          $v0, 0x98($s5)
    MEM_B(0X98, ctx->r21) = ctx->r2;
    // 0x80076FD8: lw          $v0, 0x8($s6)
    ctx->r2 = MEM_W(ctx->r22, 0X8);
    // 0x80076FDC: addiu       $s0, $s5, 0x98
    ctx->r16 = ADD32(ctx->r21, 0X98);
    // 0x80076FE0: lbu         $v0, 0x1($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X1);
    // 0x80076FE4: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x80076FE8: sb          $v0, 0x99($s5)
    MEM_B(0X99, ctx->r21) = ctx->r2;
    // 0x80076FEC: lw          $v0, 0x8($s6)
    ctx->r2 = MEM_W(ctx->r22, 0X8);
    // 0x80076FF0: lw          $a0, 0x78($s5)
    ctx->r4 = MEM_W(ctx->r21, 0X78);
    // 0x80076FF4: lbu         $v1, 0x2($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X2);
    // 0x80076FF8: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // 0x80076FFC: sb          $v0, 0x9B($s5)
    MEM_B(0X9B, ctx->r21) = ctx->r2;
    // 0x80077000: jal         0x80057548
    // 0x80077004: sb          $v1, 0x9A($s5)
    MEM_B(0X9A, ctx->r21) = ctx->r3;
    func_80057548(rdram, ctx);
        goto after_21;
    // 0x80077004: sb          $v1, 0x9A($s5)
    MEM_B(0X9A, ctx->r21) = ctx->r3;
    after_21:
    // 0x80077008: lw          $a0, 0x7C($s5)
    ctx->r4 = MEM_W(ctx->r21, 0X7C);
    // 0x8007700C: jal         0x80057548
    // 0x80077010: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    func_80057548(rdram, ctx);
        goto after_22;
    // 0x80077010: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    after_22:
    // 0x80077014: lw          $v0, 0x78($s5)
    ctx->r2 = MEM_W(ctx->r21, 0X78);
    // 0x80077018: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x8007701C: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80077020: lwc1        $f2, -0x2D44($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X2D44);
    // 0x80077024: lwc1        $f0, 0x44($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X44);
    // 0x80077028: swc1        $f2, 0x80($s5)
    MEM_W(0X80, ctx->r21) = ctx->f2.u32l;
    // 0x8007702C: swc1        $f2, 0x84($s5)
    MEM_W(0X84, ctx->r21) = ctx->f2.u32l;
    // 0x80077030: swc1        $f0, 0x9C($s5)
    MEM_W(0X9C, ctx->r21) = ctx->f0.u32l;
    // 0x80077034: lwc1        $f0, 0x14($s6)
    ctx->f0.u32l = MEM_W(ctx->r22, 0X14);
    // 0x80077038: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x8007703C: swc1        $f2, 0x8C($s5)
    MEM_W(0X8C, ctx->r21) = ctx->f2.u32l;
    // 0x80077040: swc1        $f2, 0x90($s5)
    MEM_W(0X90, ctx->r21) = ctx->f2.u32l;
    // 0x80077044: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80077048: lwc1        $f2, -0x2D40($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X2D40);
    // 0x8007704C: swc1        $f0, 0x88($s5)
    MEM_W(0X88, ctx->r21) = ctx->f0.u32l;
    // 0x80077050: lwc1        $f0, 0x14($s6)
    ctx->f0.u32l = MEM_W(ctx->r22, 0X14);
    // 0x80077054: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x80077058: sw          $zero, 0xA4($s5)
    MEM_W(0XA4, ctx->r21) = 0;
    // 0x8007705C: swc1        $f0, 0x94($s5)
    MEM_W(0X94, ctx->r21) = ctx->f0.u32l;
    // 0x80077060: lwc1        $f0, 0x20($s6)
    ctx->f0.u32l = MEM_W(ctx->r22, 0X20);
    // 0x80077064: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x80077068: swc1        $f0, 0xA0($s5)
    MEM_W(0XA0, ctx->r21) = ctx->f0.u32l;
    // 0x8007706C: lhu         $a0, -0x6A8C($v0)
    ctx->r4 = MEM_HU(ctx->r2, -0X6A8C);
    // 0x80077070: jal         0x8003E684
    // 0x80077074: addu        $a1, $s7, $zero
    ctx->r5 = ADD32(ctx->r23, 0);
    func_8003E684(rdram, ctx);
        goto after_23;
    // 0x80077074: addu        $a1, $s7, $zero
    ctx->r5 = ADD32(ctx->r23, 0);
    after_23:
    // 0x80077078: j           L_80077220
    // 0x8007707C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80077220;
    // 0x8007707C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80077080:
    // 0x80077080: lw          $a0, 0x78($s5)
    ctx->r4 = MEM_W(ctx->r21, 0X78);
    // 0x80077084: jal         0x8005779C
    // 0x80077088: nop

    func_8005779C(rdram, ctx);
        goto after_24;
    // 0x80077088: nop

    after_24:
    // 0x8007708C: lw          $a0, 0x7C($s5)
    ctx->r4 = MEM_W(ctx->r21, 0X7C);
    // 0x80077090: jal         0x8005779C
    // 0x80077094: nop

    func_8005779C(rdram, ctx);
        goto after_25;
    // 0x80077094: nop

    after_25:
    // 0x80077098: j           L_80077220
    // 0x8007709C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80077220;
    // 0x8007709C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800770A0:
    // 0x800770A0: lwc1        $f20, 0x0($s2)
    ctx->f20.u32l = MEM_W(ctx->r18, 0X0);
    // 0x800770A4: lwc1        $f0, 0xA0($s5)
    ctx->f0.u32l = MEM_W(ctx->r21, 0XA0);
    // 0x800770A8: mul.s       $f0, $f20, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = MUL_S(ctx->f20.fl, ctx->f0.fl);
    // 0x800770AC: lwc1        $f2, 0xA4($s5)
    ctx->f2.u32l = MEM_W(ctx->r21, 0XA4);
    // 0x800770B0: add.s       $f4, $f2, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x800770B4: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x800770B8: lwc1        $f0, -0x2D3C($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X2D3C);
    // 0x800770BC: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x800770C0: nop

    // 0x800770C4: bc1f        L_800771B0
    if (!c1cs) {
        // 0x800770C8: swc1        $f4, 0xA4($s5)
        MEM_W(0XA4, ctx->r21) = ctx->f4.u32l;
            goto L_800771B0;
    }
    // 0x800770C8: swc1        $f4, 0xA4($s5)
    MEM_W(0XA4, ctx->r21) = ctx->f4.u32l;
    // 0x800770CC: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x800770D0: lwc1        $f2, -0x2D38($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X2D38);
    // 0x800770D4: mul.s       $f0, $f4, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f4.fl, ctx->f2.fl);
    // 0x800770D8: sub.s       $f0, $f2, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f2.fl - ctx->f0.fl;
    // 0x800770DC: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x800770E0: lwc1        $f2, -0x2D34($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X2D34);
    // 0x800770E4: c.le.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl <= ctx->f0.fl;
    // 0x800770E8: nop

    // 0x800770EC: bc1tl       L_80077104
    if (c1cs) {
        // 0x800770F0: sub.s       $f0, $f0, $f2
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
            goto L_80077104;
    }
    goto skip_0;
    // 0x800770F0: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    skip_0:
    // 0x800770F4: trunc.w.s   $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    ctx->f14.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800770F8: mfc1        $v1, $f14
    ctx->r3 = (int32_t)ctx->f14.u32l;
    // 0x800770FC: j           L_80077118
    // 0x80077100: addiu       $s0, $s5, 0x98
    ctx->r16 = ADD32(ctx->r21, 0X98);
        goto L_80077118;
    // 0x80077100: addiu       $s0, $s5, 0x98
    ctx->r16 = ADD32(ctx->r21, 0X98);
L_80077104:
    // 0x80077104: lui         $v0, 0x8000
    ctx->r2 = S32(0X8000 << 16);
    // 0x80077108: trunc.w.s   $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    ctx->f14.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x8007710C: mfc1        $v1, $f14
    ctx->r3 = (int32_t)ctx->f14.u32l;
    // 0x80077110: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x80077114: addiu       $s0, $s5, 0x98
    ctx->r16 = ADD32(ctx->r21, 0X98);
L_80077118:
    // 0x80077118: lw          $a0, 0x78($s5)
    ctx->r4 = MEM_W(ctx->r21, 0X78);
    // 0x8007711C: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x80077120: jal         0x80057548
    // 0x80077124: sb          $v1, 0x9B($s5)
    MEM_B(0X9B, ctx->r21) = ctx->r3;
    func_80057548(rdram, ctx);
        goto after_26;
    // 0x80077124: sb          $v1, 0x9B($s5)
    MEM_B(0X9B, ctx->r21) = ctx->r3;
    after_26:
    // 0x80077128: lw          $a0, 0x7C($s5)
    ctx->r4 = MEM_W(ctx->r21, 0X7C);
    // 0x8007712C: jal         0x80057548
    // 0x80077130: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    func_80057548(rdram, ctx);
        goto after_27;
    // 0x80077130: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    after_27:
    // 0x80077134: lwc1        $f2, 0x8C($s5)
    ctx->f2.u32l = MEM_W(ctx->r21, 0X8C);
    // 0x80077138: mul.s       $f2, $f2, $f20
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f20.fl);
    // 0x8007713C: lwc1        $f10, 0x90($s5)
    ctx->f10.u32l = MEM_W(ctx->r21, 0X90);
    // 0x80077140: mul.s       $f10, $f10, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = MUL_S(ctx->f10.fl, ctx->f20.fl);
    // 0x80077144: lwc1        $f8, 0x94($s5)
    ctx->f8.u32l = MEM_W(ctx->r21, 0X94);
    // 0x80077148: mul.s       $f8, $f8, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = MUL_S(ctx->f8.fl, ctx->f20.fl);
    // 0x8007714C: lwc1        $f0, 0xA0($s5)
    ctx->f0.u32l = MEM_W(ctx->r21, 0XA0);
    // 0x80077150: mul.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x80077154: nop

    // 0x80077158: mul.s       $f10, $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x8007715C: nop

    // 0x80077160: mul.s       $f8, $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x80077164: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80077168: lwc1        $f0, -0x2D30($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X2D30);
    // 0x8007716C: mul.s       $f0, $f20, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = MUL_S(ctx->f20.fl, ctx->f0.fl);
    // 0x80077170: lwc1        $f12, 0x80($s5)
    ctx->f12.u32l = MEM_W(ctx->r21, 0X80);
    // 0x80077174: add.s       $f12, $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f12.fl = ctx->f12.fl + ctx->f2.fl;
    // 0x80077178: lwc1        $f6, 0x88($s5)
    ctx->f6.u32l = MEM_W(ctx->r21, 0X88);
    // 0x8007717C: add.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x80077180: lwc1        $f4, 0x4($s5)
    ctx->f4.u32l = MEM_W(ctx->r21, 0X4);
    // 0x80077184: add.s       $f4, $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f0.fl;
    // 0x80077188: lwc1        $f2, 0x34($s5)
    ctx->f2.u32l = MEM_W(ctx->r21, 0X34);
    // 0x8007718C: add.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x80077190: lwc1        $f0, 0x84($s5)
    ctx->f0.u32l = MEM_W(ctx->r21, 0X84);
    // 0x80077194: swc1        $f12, 0x80($s5)
    MEM_W(0X80, ctx->r21) = ctx->f12.u32l;
    // 0x80077198: swc1        $f6, 0x88($s5)
    MEM_W(0X88, ctx->r21) = ctx->f6.u32l;
    // 0x8007719C: add.s       $f0, $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f10.fl;
    // 0x800771A0: swc1        $f4, 0x4($s5)
    MEM_W(0X4, ctx->r21) = ctx->f4.u32l;
    // 0x800771A4: swc1        $f2, 0x34($s5)
    MEM_W(0X34, ctx->r21) = ctx->f2.u32l;
    // 0x800771A8: j           L_8007721C
    // 0x800771AC: swc1        $f0, 0x84($s5)
    MEM_W(0X84, ctx->r21) = ctx->f0.u32l;
        goto L_8007721C;
    // 0x800771AC: swc1        $f0, 0x84($s5)
    MEM_W(0X84, ctx->r21) = ctx->f0.u32l;
L_800771B0:
    // 0x800771B0: lhu         $a0, 0x16($s7)
    ctx->r4 = MEM_HU(ctx->r23, 0X16);
    // 0x800771B4: jal         0x8003ED74
    // 0x800771B8: nop

    func_8003ED74(rdram, ctx);
        goto after_28;
    // 0x800771B8: nop

    after_28:
    // 0x800771BC: j           L_80077220
    // 0x800771C0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80077220;
    // 0x800771C0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800771C4:
    // 0x800771C4: addu        $a1, $s5, $zero
    ctx->r5 = ADD32(ctx->r21, 0);
    // 0x800771C8: addiu       $s1, $s5, 0x80
    ctx->r17 = ADD32(ctx->r21, 0X80);
    // 0x800771CC: lw          $a0, 0x78($s5)
    ctx->r4 = MEM_W(ctx->r21, 0X78);
    // 0x800771D0: addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    // 0x800771D4: jal         0x80059C24
    // 0x800771D8: addiu       $a0, $a0, 0x28
    ctx->r4 = ADD32(ctx->r4, 0X28);
    func_80059C24(rdram, ctx);
        goto after_29;
    // 0x800771D8: addiu       $a0, $a0, 0x28
    ctx->r4 = ADD32(ctx->r4, 0X28);
    after_29:
    // 0x800771DC: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    // 0x800771E0: lw          $a1, 0x78($s5)
    ctx->r5 = MEM_W(ctx->r21, 0X78);
    // 0x800771E4: lw          $a3, 0x9C($s5)
    ctx->r7 = MEM_W(ctx->r21, 0X9C);
    // 0x800771E8: jal         0x80057C8C
    // 0x800771EC: addu        $a2, $s5, $zero
    ctx->r6 = ADD32(ctx->r21, 0);
    func_80057C8C(rdram, ctx);
        goto after_30;
    // 0x800771EC: addu        $a2, $s5, $zero
    ctx->r6 = ADD32(ctx->r21, 0);
    after_30:
    // 0x800771F0: addiu       $s0, $s5, 0x30
    ctx->r16 = ADD32(ctx->r21, 0X30);
    // 0x800771F4: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x800771F8: lw          $a0, 0x7C($s5)
    ctx->r4 = MEM_W(ctx->r21, 0X7C);
    // 0x800771FC: addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    // 0x80077200: jal         0x80059C24
    // 0x80077204: addiu       $a0, $a0, 0x28
    ctx->r4 = ADD32(ctx->r4, 0X28);
    func_80059C24(rdram, ctx);
        goto after_31;
    // 0x80077204: addiu       $a0, $a0, 0x28
    ctx->r4 = ADD32(ctx->r4, 0X28);
    after_31:
    // 0x80077208: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    // 0x8007720C: lw          $a1, 0x7C($s5)
    ctx->r5 = MEM_W(ctx->r21, 0X7C);
    // 0x80077210: lw          $a3, 0x9C($s5)
    ctx->r7 = MEM_W(ctx->r21, 0X9C);
    // 0x80077214: jal         0x80057C8C
    // 0x80077218: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    func_80057C8C(rdram, ctx);
        goto after_32;
    // 0x80077218: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    after_32:
L_8007721C:
    // 0x8007721C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80077220:
    // 0x80077220: lw          $ra, 0x88($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X88);
    // 0x80077224: lw          $s7, 0x84($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X84);
    // 0x80077228: lw          $s6, 0x80($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X80);
    // 0x8007722C: lw          $s5, 0x7C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X7C);
    // 0x80077230: lw          $s4, 0x78($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X78);
    // 0x80077234: lw          $s3, 0x74($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X74);
    // 0x80077238: lw          $s2, 0x70($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X70);
    // 0x8007723C: lw          $s1, 0x6C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X6C);
    // 0x80077240: lw          $s0, 0x68($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X68);
    // 0x80077244: ldc1        $f20, 0x90($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X90);
    // 0x80077248: jr          $ra
    // 0x8007724C: addiu       $sp, $sp, 0x98
    ctx->r29 = ADD32(ctx->r29, 0X98);
    return;
    // 0x8007724C: addiu       $sp, $sp, 0x98
    ctx->r29 = ADD32(ctx->r29, 0X98);
;}
RECOMP_FUNC void func_80077250(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80077250: addiu       $sp, $sp, -0xC0
    ctx->r29 = ADD32(ctx->r29, -0XC0);
    // 0x80077254: sdc1        $f26, 0xB0($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0XB0, ctx->r29);
    // 0x80077258: mtc1        $a2, $f26
    ctx->f26.u32l = ctx->r6;
    // 0x8007725C: sdc1        $f24, 0xA8($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0XA8, ctx->r29);
    // 0x80077260: mtc1        $a3, $f24
    ctx->f24.u32l = ctx->r7;
    // 0x80077264: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x80077268: sdc1        $f22, 0xA0($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0XA0, ctx->r29);
    // 0x8007726C: lwc1        $f22, 0xD4($sp)
    ctx->f22.u32l = MEM_W(ctx->r29, 0XD4);
    // 0x80077270: lbu         $v0, -0x56BC($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X56BC);
    // 0x80077274: sw          $s2, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->r18;
    // 0x80077278: addu        $s2, $a1, $zero
    ctx->r18 = ADD32(ctx->r5, 0);
    // 0x8007727C: sw          $s0, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r16;
    // 0x80077280: sw          $ra, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->r31;
    // 0x80077284: sw          $s1, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->r17;
    // 0x80077288: sdc1        $f28, 0xB8($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0XB8, ctx->r29);
    // 0x8007728C: sdc1        $f20, 0x98($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X98, ctx->r29);
    // 0x80077290: beq         $v0, $zero, L_80077544
    if (ctx->r2 == 0) {
        // 0x80077294: addu        $s0, $a0, $zero
        ctx->r16 = ADD32(ctx->r4, 0);
            goto L_80077544;
    }
    // 0x80077294: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x80077298: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8007729C: lui         $v1, 0x8014
    ctx->r3 = S32(0X8014 << 16);
    // 0x800772A0: lwc1        $f2, 0xBA4($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0XBA4);
    // 0x800772A4: lwc1        $f0, -0x5748($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, -0X5748);
    // 0x800772A8: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x800772AC: nop

    // 0x800772B0: bc1t        L_80077544
    if (c1cs) {
        // 0x800772B4: nop
    
            goto L_80077544;
    }
    // 0x800772B4: nop

    // 0x800772B8: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x800772BC: lwc1        $f0, -0x2D28($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X2D28);
    // 0x800772C0: add.s       $f0, $f2, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x800772C4: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x800772C8: c.lt.s      $f20, $f22
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 22);
    c1cs = ctx->f20.fl < ctx->f22.fl;
    // 0x800772CC: nop

    // 0x800772D0: bc1f        L_80077398
    if (!c1cs) {
        // 0x800772D4: swc1        $f0, -0x5748($v1)
        MEM_W(-0X5748, ctx->r3) = ctx->f0.u32l;
            goto L_80077398;
    }
    // 0x800772D4: swc1        $f0, -0x5748($v1)
    MEM_W(-0X5748, ctx->r3) = ctx->f0.u32l;
    // 0x800772D8: jal         0x8001CF2C
    // 0x800772DC: addiu       $a0, $s2, 0x24
    ctx->r4 = ADD32(ctx->r18, 0X24);
    func_8001CF2C(rdram, ctx);
        goto after_0;
    // 0x800772DC: addiu       $a0, $s2, 0x24
    ctx->r4 = ADD32(ctx->r18, 0X24);
    after_0:
    // 0x800772E0: c.lt.s      $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f20.fl < ctx->f0.fl;
    // 0x800772E4: nop

    // 0x800772E8: bc1f        L_80077398
    if (!c1cs) {
        // 0x800772EC: lui         $a2, 0x8014
        ctx->r6 = S32(0X8014 << 16);
            goto L_80077398;
    }
    // 0x800772EC: lui         $a2, 0x8014
    ctx->r6 = S32(0X8014 << 16);
    // 0x800772F0: lwc1        $f12, 0x0($s2)
    ctx->f12.u32l = MEM_W(ctx->r18, 0X0);
    // 0x800772F4: lwc1        $f14, 0x8($s2)
    ctx->f14.u32l = MEM_W(ctx->r18, 0X8);
    // 0x800772F8: jal         0x800698F4
    // 0x800772FC: addiu       $a2, $a2, -0x7FA8
    ctx->r6 = ADD32(ctx->r6, -0X7FA8);
    func_800698F4(rdram, ctx);
        goto after_1;
    // 0x800772FC: addiu       $a2, $a2, -0x7FA8
    ctx->r6 = ADD32(ctx->r6, -0X7FA8);
    after_1:
    // 0x80077300: bne         $v0, $zero, L_8007731C
    if (ctx->r2 != 0) {
        // 0x80077304: lui         $v0, 0x800A
        ctx->r2 = S32(0X800A << 16);
            goto L_8007731C;
    }
    // 0x80077304: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x80077308: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x8007730C: addiu       $v0, $v0, -0x66E0
    ctx->r2 = ADD32(ctx->r2, -0X66E0);
    // 0x80077310: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x80077314: j           L_80077328
    // 0x80077318: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
        goto L_80077328;
    // 0x80077318: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
L_8007731C:
    // 0x8007731C: addiu       $v0, $v0, 0xD70
    ctx->r2 = ADD32(ctx->r2, 0XD70);
    // 0x80077320: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // 0x80077324: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
L_80077328:
    // 0x80077328: lui         $a0, 0x8007
    ctx->r4 = S32(0X8007 << 16);
    // 0x8007732C: addiu       $a0, $a0, 0x6BE4
    ctx->r4 = ADD32(ctx->r4, 0X6BE4);
    // 0x80077330: addiu       $a1, $sp, 0x10
    ctx->r5 = ADD32(ctx->r29, 0X10);
    // 0x80077334: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80077338: lwc1        $f6, -0x2D24($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X2D24);
    // 0x8007733C: lwc1        $f0, 0xD0($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0XD0);
    // 0x80077340: lw          $v0, 0xDC($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XDC);
    // 0x80077344: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80077348: lwc1        $f4, -0x2D20($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X2D20);
    // 0x8007734C: lwc1        $f2, 0xD8($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0XD8);
    // 0x80077350: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x80077354: swc1        $f0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f0.u32l;
    // 0x80077358: lwc1        $f0, 0xE0($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0XE0);
    // 0x8007735C: addiu       $a3, $zero, 0xF
    ctx->r7 = ADD32(0, 0XF);
    // 0x80077360: sw          $s2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r18;
    // 0x80077364: swc1        $f22, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f22.u32l;
    // 0x80077368: swc1        $f24, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f24.u32l;
    // 0x8007736C: sh          $s0, 0x3C($sp)
    MEM_H(0X3C, ctx->r29) = ctx->r16;
    // 0x80077370: swc1        $f0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f0.u32l;
    // 0x80077374: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80077378: lwc1        $f0, -0x2D1C($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X2D1C);
    // 0x8007737C: mul.s       $f6, $f26, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f6.fl = MUL_S(ctx->f26.fl, ctx->f6.fl);
    // 0x80077380: sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    // 0x80077384: swc1        $f4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f4.u32l;
    // 0x80077388: div.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f2.fl);
    // 0x8007738C: swc1        $f0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f0.u32l;
    // 0x80077390: jal         0x8003FFEC
    // 0x80077394: swc1        $f6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f6.u32l;
    func_8003FFEC(rdram, ctx);
        goto after_2;
    // 0x80077394: swc1        $f6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f6.u32l;
    after_2:
L_80077398:
    // 0x80077398: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8007739C: lw          $v1, 0xB70($v0)
    ctx->r3 = MEM_W(ctx->r2, 0XB70);
    // 0x800773A0: addiu       $v0, $zero, 0xD
    ctx->r2 = ADD32(0, 0XD);
    // 0x800773A4: bne         $v1, $v0, L_80077544
    if (ctx->r3 != ctx->r2) {
        // 0x800773A8: lui         $v0, 0x8004
        ctx->r2 = S32(0X8004 << 16);
            goto L_80077544;
    }
    // 0x800773A8: lui         $v0, 0x8004
    ctx->r2 = S32(0X8004 << 16);
    // 0x800773AC: addiu       $t3, $v0, -0x2D2C
    ctx->r11 = ADD32(ctx->r2, -0X2D2C);
    // 0x800773B0: lwl         $t0, 0x0($t3)
    ctx->r8 = do_lwl(rdram, ctx->r8, ctx->r11, 0X0);
    // 0x800773B4: lwr         $t0, 0x3($t3)
    ctx->r8 = do_lwr(rdram, ctx->r8, ctx->r11, 0X3);
    // 0x800773B8: swl         $t0, 0x58($sp)
    do_swl(rdram, 0X58, ctx->r29, ctx->r8);
    // 0x800773BC: swr         $t0, 0x5B($sp)
    do_swr(rdram, 0X5B, ctx->r29, ctx->r8);
    // 0x800773C0: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x800773C4: lw          $v1, -0x72E4($v0)
    ctx->r3 = MEM_W(ctx->r2, -0X72E4);
    // 0x800773C8: lui         $v0, 0x8004
    ctx->r2 = S32(0X8004 << 16);
    // 0x800773CC: addiu       $t3, $v0, -0x2DDC
    ctx->r11 = ADD32(ctx->r2, -0X2DDC);
    // 0x800773D0: lwl         $t0, 0x0($t3)
    ctx->r8 = do_lwl(rdram, ctx->r8, ctx->r11, 0X0);
    // 0x800773D4: lwr         $t0, 0x3($t3)
    ctx->r8 = do_lwr(rdram, ctx->r8, ctx->r11, 0X3);
    // 0x800773D8: swl         $t0, 0x60($sp)
    do_swl(rdram, 0X60, ctx->r29, ctx->r8);
    // 0x800773DC: swr         $t0, 0x63($sp)
    do_swr(rdram, 0X63, ctx->r29, ctx->r8);
    // 0x800773E0: lwc1        $f0, 0x0($s2)
    ctx->f0.u32l = MEM_W(ctx->r18, 0X0);
    // 0x800773E4: addiu       $v1, $v1, 0x28
    ctx->r3 = ADD32(ctx->r3, 0X28);
    // 0x800773E8: lwc1        $f2, 0x24($v1)
    ctx->f2.u32l = MEM_W(ctx->r3, 0X24);
    // 0x800773EC: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x800773F0: swc1        $f0, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->f0.u32l;
    // 0x800773F4: lwc1        $f0, 0x4($s2)
    ctx->f0.u32l = MEM_W(ctx->r18, 0X4);
    // 0x800773F8: lwc1        $f2, 0x28($v1)
    ctx->f2.u32l = MEM_W(ctx->r3, 0X28);
    // 0x800773FC: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x80077400: swc1        $f0, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->f0.u32l;
    // 0x80077404: lwc1        $f0, 0x8($s2)
    ctx->f0.u32l = MEM_W(ctx->r18, 0X8);
    // 0x80077408: lwc1        $f2, 0x2C($v1)
    ctx->f2.u32l = MEM_W(ctx->r3, 0X2C);
    // 0x8007740C: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x80077410: addiu       $a0, $sp, 0x78
    ctx->r4 = ADD32(ctx->r29, 0X78);
    // 0x80077414: jal         0x8001CF2C
    // 0x80077418: swc1        $f0, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->f0.u32l;
    func_8001CF2C(rdram, ctx);
        goto after_3;
    // 0x80077418: swc1        $f0, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->f0.u32l;
    after_3:
    // 0x8007741C: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80077420: lwc1        $f2, -0x2D18($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X2D18);
    // 0x80077424: div.s       $f4, $f0, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = DIV_S(ctx->f0.fl, ctx->f2.fl);
    // 0x80077428: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8007742C: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80077430: lwc1        $f2, -0x2D14($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X2D14);
    // 0x80077434: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x80077438: mul.s       $f28, $f4, $f2
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f28.fl = MUL_S(ctx->f4.fl, ctx->f2.fl);
    // 0x8007743C: bc1f        L_80077460
    if (!c1cs) {
        // 0x80077440: addiu       $s1, $zero, 0x1
        ctx->r17 = ADD32(0, 0X1);
            goto L_80077460;
    }
    // 0x80077440: addiu       $s1, $zero, 0x1
    ctx->r17 = ADD32(0, 0X1);
    // 0x80077444: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80077448: lwc1        $f0, -0x2D10($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X2D10);
    // 0x8007744C: div.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f4.fl);
    // 0x80077450: trunc.w.s   $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    ctx->f8.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x80077454: mfc1        $s1, $f8
    ctx->r17 = (int32_t)ctx->f8.u32l;
    // 0x80077458: j           L_80077464
    // 0x8007745C: slti        $v0, $s1, 0x8
    ctx->r2 = SIGNED(ctx->r17) < 0X8 ? 1 : 0;
        goto L_80077464;
    // 0x8007745C: slti        $v0, $s1, 0x8
    ctx->r2 = SIGNED(ctx->r17) < 0X8 ? 1 : 0;
L_80077460:
    // 0x80077460: slti        $v0, $s1, 0x8
    ctx->r2 = SIGNED(ctx->r17) < 0X8 ? 1 : 0;
L_80077464:
    // 0x80077464: beql        $v0, $zero, L_8007746C
    if (ctx->r2 == 0) {
        // 0x80077468: addiu       $s1, $zero, 0x7
        ctx->r17 = ADD32(0, 0X7);
            goto L_8007746C;
    }
    goto skip_0;
    // 0x80077468: addiu       $s1, $zero, 0x7
    ctx->r17 = ADD32(0, 0X7);
    skip_0:
L_8007746C:
    // 0x8007746C: lui         $a2, 0x8014
    ctx->r6 = S32(0X8014 << 16);
    // 0x80077470: addiu       $a2, $a2, -0x7FA8
    ctx->r6 = ADD32(ctx->r6, -0X7FA8);
    // 0x80077474: lwc1        $f12, 0x0($s2)
    ctx->f12.u32l = MEM_W(ctx->r18, 0X0);
    // 0x80077478: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    // 0x8007747C: swc1        $f12, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f12.u32l;
    // 0x80077480: lwc1        $f14, 0x8($s2)
    ctx->f14.u32l = MEM_W(ctx->r18, 0X8);
    // 0x80077484: addu        $s0, $a3, $zero
    ctx->r16 = ADD32(ctx->r7, 0);
    // 0x80077488: jal         0x80067D90
    // 0x8007748C: swc1        $f14, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->f14.u32l;
    func_80067D90(rdram, ctx);
        goto after_4;
    // 0x8007748C: swc1        $f14, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->f14.u32l;
    after_4:
    // 0x80077490: addiu       $v0, $sp, 0x68
    ctx->r2 = ADD32(ctx->r29, 0X68);
    // 0x80077494: sw          $v0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r2;
    // 0x80077498: ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
    // 0x8007749C: sh          $v0, 0x50($sp)
    MEM_H(0X50, ctx->r29) = ctx->r2;
    // 0x800774A0: addiu       $v0, $sp, 0x58
    ctx->r2 = ADD32(ctx->r29, 0X58);
    // 0x800774A4: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    // 0x800774A8: addiu       $v0, $sp, 0x60
    ctx->r2 = ADD32(ctx->r29, 0X60);
    // 0x800774AC: swc1        $f0, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->f0.u32l;
    // 0x800774B0: blez        $s1, L_80077530
    if (SIGNED(ctx->r17) <= 0) {
        // 0x800774B4: sw          $v0, 0x48($sp)
        MEM_W(0X48, ctx->r29) = ctx->r2;
            goto L_80077530;
    }
    // 0x800774B4: sw          $v0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r2;
    // 0x800774B8: lui         $s2, 0x8007
    ctx->r18 = S32(0X8007 << 16);
    // 0x800774BC: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x800774C0: lwc1        $f26, -0x2D0C($at)
    ctx->f26.u32l = MEM_W(ctx->r1, -0X2D0C);
    // 0x800774C4: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x800774C8: lwc1        $f24, -0x2D08($at)
    ctx->f24.u32l = MEM_W(ctx->r1, -0X2D08);
    // 0x800774CC: mtc1        $zero, $f22
    ctx->f22.u32l = 0;
    // 0x800774D0: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x800774D4: lwc1        $f20, -0x2D04($at)
    ctx->f20.u32l = MEM_W(ctx->r1, -0X2D04);
L_800774D8:
    // 0x800774D8: jal         0x80003430
    // 0x800774DC: nop

    rand_recomp(rdram, ctx);
        goto after_5;
    // 0x800774DC: nop

    after_5:
    // 0x800774E0: andi        $v0, $v0, 0x7F
    ctx->r2 = ctx->r2 & 0X7F;
    // 0x800774E4: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x800774E8: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x800774EC: sub.s       $f0, $f0, $f26
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f26.fl;
    // 0x800774F0: div.s       $f0, $f0, $f24
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f24.fl);
    // 0x800774F4: add.s       $f0, $f28, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f28.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f28.fl + ctx->f0.fl;
    // 0x800774F8: c.le.s      $f0, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    c1cs = ctx->f0.fl <= ctx->f22.fl;
    // 0x800774FC: nop

    // 0x80077500: bc1f        L_8007750C
    if (!c1cs) {
        // 0x80077504: swc1        $f0, 0x4C($sp)
        MEM_W(0X4C, ctx->r29) = ctx->f0.u32l;
            goto L_8007750C;
    }
    // 0x80077504: swc1        $f0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f0.u32l;
    // 0x80077508: swc1        $f20, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f20.u32l;
L_8007750C:
    // 0x8007750C: addiu       $a0, $s2, 0x413C
    ctx->r4 = ADD32(ctx->r18, 0X413C);
    // 0x80077510: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    // 0x80077514: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80077518: jal         0x8003FFEC
    // 0x8007751C: addiu       $a3, $zero, 0xA
    ctx->r7 = ADD32(0, 0XA);
    func_8003FFEC(rdram, ctx);
        goto after_6;
    // 0x8007751C: addiu       $a3, $zero, 0xA
    ctx->r7 = ADD32(0, 0XA);
    after_6:
    // 0x80077520: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80077524: slt         $v0, $s0, $s1
    ctx->r2 = SIGNED(ctx->r16) < SIGNED(ctx->r17) ? 1 : 0;
    // 0x80077528: bne         $v0, $zero, L_800774D8
    if (ctx->r2 != 0) {
        // 0x8007752C: nop
    
            goto L_800774D8;
    }
    // 0x8007752C: nop

L_80077530:
    // 0x80077530: lui         $a1, 0x3DCC
    ctx->r5 = S32(0X3DCC << 16);
    // 0x80077534: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    // 0x80077538: lui         $a2, 0x3F00
    ctx->r6 = S32(0X3F00 << 16);
    // 0x8007753C: jal         0x80073E4C
    // 0x80077540: addiu       $a0, $sp, 0x68
    ctx->r4 = ADD32(ctx->r29, 0X68);
    func_80073E4C(rdram, ctx);
        goto after_7;
    // 0x80077540: addiu       $a0, $sp, 0x68
    ctx->r4 = ADD32(ctx->r29, 0X68);
    after_7:
L_80077544:
    // 0x80077544: lw          $ra, 0x94($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X94);
    // 0x80077548: lw          $s2, 0x90($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X90);
    // 0x8007754C: lw          $s1, 0x8C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X8C);
    // 0x80077550: lw          $s0, 0x88($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X88);
    // 0x80077554: ldc1        $f28, 0xB8($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0XB8);
    // 0x80077558: ldc1        $f26, 0xB0($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0XB0);
    // 0x8007755C: ldc1        $f24, 0xA8($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0XA8);
    // 0x80077560: ldc1        $f22, 0xA0($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0XA0);
    // 0x80077564: ldc1        $f20, 0x98($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X98);
    // 0x80077568: jr          $ra
    // 0x8007756C: addiu       $sp, $sp, 0xC0
    ctx->r29 = ADD32(ctx->r29, 0XC0);
    return;
    // 0x8007756C: addiu       $sp, $sp, 0xC0
    ctx->r29 = ADD32(ctx->r29, 0XC0);
;}
RECOMP_FUNC void func_80077570(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80077570: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80077574: sdc1        $f20, 0x30($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X30, ctx->r29);
    // 0x80077578: mtc1        $a2, $f20
    ctx->f20.u32l = ctx->r6;
    // 0x8007757C: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x80077580: addu        $s1, $a1, $zero
    ctx->r17 = ADD32(ctx->r5, 0);
    // 0x80077584: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80077588: addu        $s0, $a3, $zero
    ctx->r16 = ADD32(ctx->r7, 0);
    // 0x8007758C: beq         $a0, $zero, L_800775A8
    if (ctx->r4 == 0) {
        // 0x80077590: sw          $ra, 0x28($sp)
        MEM_W(0X28, ctx->r29) = ctx->r31;
            goto L_800775A8;
    }
    // 0x80077590: sw          $ra, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r31;
    // 0x80077594: add.s       $f2, $f20, $f20
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f2.fl = ctx->f20.fl + ctx->f20.fl;
    // 0x80077598: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x8007759C: mfc1        $a2, $f2
    ctx->r6 = (int32_t)ctx->f2.u32l;
    // 0x800775A0: jal         0x8006133C
    // 0x800775A4: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    func_8006133C(rdram, ctx);
        goto after_0;
    // 0x800775A4: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    after_0:
L_800775A8:
    // 0x800775A8: andi        $v0, $s0, 0xFF
    ctx->r2 = ctx->r16 & 0XFF;
    // 0x800775AC: beq         $v0, $zero, L_800775DC
    if (ctx->r2 == 0) {
        // 0x800775B0: lui         $a0, 0x8007
        ctx->r4 = S32(0X8007 << 16);
            goto L_800775DC;
    }
    // 0x800775B0: lui         $a0, 0x8007
    ctx->r4 = S32(0X8007 << 16);
    // 0x800775B4: addiu       $a0, $a0, 0x4D44
    ctx->r4 = ADD32(ctx->r4, 0X4D44);
    // 0x800775B8: addiu       $a1, $sp, 0x10
    ctx->r5 = ADD32(ctx->r29, 0X10);
    // 0x800775BC: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x800775C0: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x800775C4: lwc1        $f0, -0x2D00($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X2D00);
    // 0x800775C8: addiu       $a3, $zero, 0xA
    ctx->r7 = ADD32(0, 0XA);
    // 0x800775CC: sh          $s1, 0x18($sp)
    MEM_H(0X18, ctx->r29) = ctx->r17;
    // 0x800775D0: swc1        $f20, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f20.u32l;
    // 0x800775D4: jal         0x8003FFEC
    // 0x800775D8: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    func_8003FFEC(rdram, ctx);
        goto after_1;
    // 0x800775D8: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    after_1:
L_800775DC:
    // 0x800775DC: lw          $ra, 0x28($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X28);
    // 0x800775E0: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x800775E4: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x800775E8: ldc1        $f20, 0x30($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X30);
    // 0x800775EC: jr          $ra
    // 0x800775F0: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x800775F0: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_800775F4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800775F4: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x800775F8: lw          $v0, -0x72E4($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X72E4);
    // 0x800775FC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80077600: sw          $ra, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r31;
    // 0x80077604: lwc1        $f0, 0x0($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X0);
    // 0x80077608: addiu       $v0, $v0, 0x28
    ctx->r2 = ADD32(ctx->r2, 0X28);
    // 0x8007760C: lwc1        $f2, 0x24($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X24);
    // 0x80077610: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x80077614: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    // 0x80077618: lwc1        $f0, 0x4($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X4);
    // 0x8007761C: lwc1        $f2, 0x28($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X28);
    // 0x80077620: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x80077624: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    // 0x80077628: lwc1        $f0, 0x8($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X8);
    // 0x8007762C: lwc1        $f2, 0x2C($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X2C);
    // 0x80077630: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x80077634: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    // 0x80077638: jal         0x8001CF2C
    // 0x8007763C: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    func_8001CF2C(rdram, ctx);
        goto after_0;
    // 0x8007763C: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    after_0:
    // 0x80077640: lw          $ra, 0x20($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X20);
    // 0x80077644: jr          $ra
    // 0x80077648: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80077648: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_8007764C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007764C: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80077650: mtc1        $a2, $f8
    ctx->f8.u32l = ctx->r6;
    // 0x80077654: mtc1        $a3, $f10
    ctx->f10.u32l = ctx->r7;
    // 0x80077658: lwc1        $f4, 0x50($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X50);
    // 0x8007765C: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80077660: lwc1        $f2, -0x2CFC($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X2CFC);
    // 0x80077664: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80077668: sw          $ra, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r31;
    // 0x8007766C: sw          $a0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r4;
    // 0x80077670: mov.s       $f6, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    ctx->f6.fl = ctx->f2.fl;
    // 0x80077674: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x80077678: nop

    // 0x8007767C: bc1f        L_8007768C
    if (!c1cs) {
        // 0x80077680: swc1        $f2, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->f2.u32l;
            goto L_8007768C;
    }
    // 0x80077680: swc1        $f2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f2.u32l;
    // 0x80077684: div.s       $f0, $f2, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = DIV_S(ctx->f2.fl, ctx->f4.fl);
    // 0x80077688: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
L_8007768C:
    // 0x8007768C: lui         $a0, 0x8007
    ctx->r4 = S32(0X8007 << 16);
    // 0x80077690: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80077694: lwc1        $f0, -0x2CF8($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X2CF8);
    // 0x80077698: addiu       $a0, $a0, 0x5720
    ctx->r4 = ADD32(ctx->r4, 0X5720);
    // 0x8007769C: sh          $a1, 0x34($sp)
    MEM_H(0X34, ctx->r29) = ctx->r5;
    // 0x800776A0: addiu       $a1, $sp, 0x10
    ctx->r5 = ADD32(ctx->r29, 0X10);
    // 0x800776A4: swc1        $f0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f0.u32l;
    // 0x800776A8: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x800776AC: lwc1        $f0, -0x2CF4($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X2CF4);
    // 0x800776B0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x800776B4: swc1        $f0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f0.u32l;
    // 0x800776B8: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x800776BC: lwc1        $f0, -0x2CF0($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X2CF0);
    // 0x800776C0: addiu       $a3, $zero, 0x64
    ctx->r7 = ADD32(0, 0X64);
    // 0x800776C4: swc1        $f8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f8.u32l;
    // 0x800776C8: swc1        $f10, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f10.u32l;
    // 0x800776CC: swc1        $f6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f6.u32l;
    // 0x800776D0: swc1        $f6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f6.u32l;
    // 0x800776D4: jal         0x8003FFEC
    // 0x800776D8: swc1        $f0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f0.u32l;
    func_8003FFEC(rdram, ctx);
        goto after_0;
    // 0x800776D8: swc1        $f0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f0.u32l;
    after_0:
    // 0x800776DC: lw          $ra, 0x38($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X38);
    // 0x800776E0: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x800776E4: jr          $ra
    // 0x800776E8: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x800776E8: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void func_800776EC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800776EC: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x800776F0: mtc1        $a2, $f6
    ctx->f6.u32l = ctx->r6;
    // 0x800776F4: mtc1        $a3, $f8
    ctx->f8.u32l = ctx->r7;
    // 0x800776F8: lwc1        $f4, 0x64($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X64);
    // 0x800776FC: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80077700: lwc1        $f2, -0x2CEC($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X2CEC);
    // 0x80077704: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80077708: sw          $ra, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r31;
    // 0x8007770C: sw          $a0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r4;
    // 0x80077710: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x80077714: nop

    // 0x80077718: bc1f        L_80077728
    if (!c1cs) {
        // 0x8007771C: swc1        $f2, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->f2.u32l;
            goto L_80077728;
    }
    // 0x8007771C: swc1        $f2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f2.u32l;
    // 0x80077720: div.s       $f0, $f2, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = DIV_S(ctx->f2.fl, ctx->f4.fl);
    // 0x80077724: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
L_80077728:
    // 0x80077728: lwc1        $f0, 0x50($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X50);
    // 0x8007772C: lui         $a0, 0x8007
    ctx->r4 = S32(0X8007 << 16);
    // 0x80077730: swc1        $f0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f0.u32l;
    // 0x80077734: lwc1        $f0, 0x54($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X54);
    // 0x80077738: addiu       $a0, $a0, 0x5720
    ctx->r4 = ADD32(ctx->r4, 0X5720);
    // 0x8007773C: sh          $a1, 0x34($sp)
    MEM_H(0X34, ctx->r29) = ctx->r5;
    // 0x80077740: swc1        $f0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f0.u32l;
    // 0x80077744: lwc1        $f0, 0x58($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X58);
    // 0x80077748: addiu       $a1, $sp, 0x10
    ctx->r5 = ADD32(ctx->r29, 0X10);
    // 0x8007774C: swc1        $f0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f0.u32l;
    // 0x80077750: lwc1        $f0, 0x5C($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x80077754: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80077758: swc1        $f0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f0.u32l;
    // 0x8007775C: lwc1        $f0, 0x60($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X60);
    // 0x80077760: addiu       $a3, $zero, 0x64
    ctx->r7 = ADD32(0, 0X64);
    // 0x80077764: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    // 0x80077768: swc1        $f8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f8.u32l;
    // 0x8007776C: jal         0x8003FFEC
    // 0x80077770: swc1        $f0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f0.u32l;
    func_8003FFEC(rdram, ctx);
        goto after_0;
    // 0x80077770: swc1        $f0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f0.u32l;
    after_0:
    // 0x80077774: lw          $ra, 0x38($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X38);
    // 0x80077778: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x8007777C: jr          $ra
    // 0x80077780: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x80077780: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void func_80077784(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80077784: mtc1        $a3, $f4
    ctx->f4.u32l = ctx->r7;
    // 0x80077788: lwc1        $f2, 0xC($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0XC);
    // 0x8007778C: mul.s       $f2, $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f4.fl);
    // 0x80077790: lwc1        $f0, 0x0($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X0);
    // 0x80077794: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x80077798: swc1        $f0, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->f0.u32l;
    // 0x8007779C: lwc1        $f2, 0x10($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X10);
    // 0x800777A0: mul.s       $f2, $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f4.fl);
    // 0x800777A4: lwc1        $f0, 0x4($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X4);
    // 0x800777A8: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x800777AC: swc1        $f0, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->f0.u32l;
    // 0x800777B0: lwc1        $f2, 0x14($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X14);
    // 0x800777B4: mul.s       $f2, $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f4.fl);
    // 0x800777B8: lwc1        $f0, 0x8($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X8);
    // 0x800777BC: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x800777C0: jr          $ra
    // 0x800777C4: swc1        $f0, 0x8($a2)
    MEM_W(0X8, ctx->r6) = ctx->f0.u32l;
    return;
    // 0x800777C4: swc1        $f0, 0x8($a2)
    MEM_W(0X8, ctx->r6) = ctx->f0.u32l;
;}
RECOMP_FUNC void func_800777C8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800777C8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800777CC: mtc1        $a2, $f0
    ctx->f0.u32l = ctx->r6;
    // 0x800777D0: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    // 0x800777D4: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x800777D8: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x800777DC: jal         0x80075BB0
    // 0x800777E0: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    func_80075BB0(rdram, ctx);
        goto after_0;
    // 0x800777E0: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    after_0:
    // 0x800777E4: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x800777E8: jr          $ra
    // 0x800777EC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x800777EC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_800777F0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800777F0: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x800777F4: addu        $v1, $a0, $zero
    ctx->r3 = ADD32(ctx->r4, 0);
    // 0x800777F8: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x800777FC: lbu         $v0, -0x56BC($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X56BC);
    // 0x80077800: addu        $a0, $v1, $zero
    ctx->r4 = ADD32(ctx->r3, 0);
    // 0x80077804: bne         $v0, $zero, L_80077814
    if (ctx->r2 != 0) {
        // 0x80077808: sw          $ra, 0x30($sp)
        MEM_W(0X30, ctx->r29) = ctx->r31;
            goto L_80077814;
    }
    // 0x80077808: sw          $ra, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r31;
    // 0x8007780C: j           L_8007784C
    // 0x80077810: ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
        goto L_8007784C;
    // 0x80077810: ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
L_80077814:
    // 0x80077814: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    // 0x80077818: sh          $v1, 0x2C($sp)
    MEM_H(0X2C, ctx->r29) = ctx->r3;
    // 0x8007781C: sw          $a1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r5;
    // 0x80077820: jal         0x8004013C
    // 0x80077824: sh          $zero, 0x2E($sp)
    MEM_H(0X2E, ctx->r29) = 0;
    func_8004013C(rdram, ctx);
        goto after_0;
    // 0x80077824: sh          $zero, 0x2E($sp)
    MEM_H(0X2E, ctx->r29) = 0;
    after_0:
    // 0x80077828: lui         $a0, 0x8007
    ctx->r4 = S32(0X8007 << 16);
    // 0x8007782C: addiu       $a0, $a0, 0x2EC4
    ctx->r4 = ADD32(ctx->r4, 0X2EC4);
    // 0x80077830: addiu       $a1, $sp, 0x10
    ctx->r5 = ADD32(ctx->r29, 0X10);
    // 0x80077834: lbu         $a3, 0x19($v0)
    ctx->r7 = MEM_BU(ctx->r2, 0X19);
    // 0x80077838: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8007783C: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x80077840: jal         0x8003FFEC
    // 0x80077844: andi        $a3, $a3, 0xFF
    ctx->r7 = ctx->r7 & 0XFF;
    func_8003FFEC(rdram, ctx);
        goto after_1;
    // 0x80077844: andi        $a3, $a3, 0xFF
    ctx->r7 = ctx->r7 & 0XFF;
    after_1:
    // 0x80077848: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
L_8007784C:
    // 0x8007784C: lw          $ra, 0x30($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X30);
    // 0x80077850: jr          $ra
    // 0x80077854: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x80077854: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_80077858(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80077858: addiu       $sp, $sp, -0x78
    ctx->r29 = ADD32(ctx->r29, -0X78);
    // 0x8007785C: sdc1        $f20, 0x58($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X58, ctx->r29);
    // 0x80077860: mtc1        $a1, $f20
    ctx->f20.u32l = ctx->r5;
    // 0x80077864: sdc1        $f22, 0x60($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X60, ctx->r29);
    // 0x80077868: mtc1        $a2, $f22
    ctx->f22.u32l = ctx->r6;
    // 0x8007786C: mtc1        $a3, $f0
    ctx->f0.u32l = ctx->r7;
    // 0x80077870: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x80077874: sdc1        $f24, 0x68($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X68, ctx->r29);
    // 0x80077878: lwc1        $f24, 0x88($sp)
    ctx->f24.u32l = MEM_W(ctx->r29, 0X88);
    // 0x8007787C: lbu         $v0, -0x56BC($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X56BC);
    // 0x80077880: sdc1        $f26, 0x70($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X70, ctx->r29);
    // 0x80077884: lwc1        $f26, 0x8C($sp)
    ctx->f26.u32l = MEM_W(ctx->r29, 0X8C);
    // 0x80077888: sw          $s1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r17;
    // 0x8007788C: addu        $s1, $a0, $zero
    ctx->r17 = ADD32(ctx->r4, 0);
    // 0x80077890: sw          $ra, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r31;
    // 0x80077894: beq         $v0, $zero, L_80077990
    if (ctx->r2 == 0) {
        // 0x80077898: sw          $s0, 0x48($sp)
        MEM_W(0X48, ctx->r29) = ctx->r16;
            goto L_80077990;
    }
    // 0x80077898: sw          $s0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r16;
    // 0x8007789C: lui         $a0, 0x8007
    ctx->r4 = S32(0X8007 << 16);
    // 0x800778A0: addiu       $a0, $a0, 0x2EC4
    ctx->r4 = ADD32(ctx->r4, 0X2EC4);
    // 0x800778A4: addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    // 0x800778A8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x800778AC: addiu       $a3, $zero, 0xF
    ctx->r7 = ADD32(0, 0XF);
    // 0x800778B0: ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
    // 0x800778B4: sh          $v0, 0x34($sp)
    MEM_H(0X34, ctx->r29) = ctx->r2;
    // 0x800778B8: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x800778BC: addiu       $s0, $sp, 0x38
    ctx->r16 = ADD32(ctx->r29, 0X38);
    // 0x800778C0: swc1        $f0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f0.u32l;
    // 0x800778C4: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x800778C8: lwc1        $f0, -0x2CE8($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X2CE8);
    // 0x800778CC: sub.s       $f2, $f22, $f20
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f2.fl = ctx->f22.fl - ctx->f20.fl;
    // 0x800778D0: sh          $v0, 0x36($sp)
    MEM_H(0X36, ctx->r29) = ctx->r2;
    // 0x800778D4: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x800778D8: swc1        $f20, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f20.u32l;
    // 0x800778DC: swc1        $f20, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f20.u32l;
    // 0x800778E0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800778E4: swc1        $f24, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f24.u32l;
    // 0x800778E8: div.s       $f0, $f0, $f26
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f26.fl);
    // 0x800778EC: swc1        $f0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f0.u32l;
    // 0x800778F0: jal         0x8003FFEC
    // 0x800778F4: swc1        $f2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f2.u32l;
    func_8003FFEC(rdram, ctx);
        goto after_0;
    // 0x800778F4: swc1        $f2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f2.u32l;
    after_0:
    // 0x800778F8: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x800778FC: lwc1        $f0, -0x2CE4($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X2CE4);
    // 0x80077900: mul.s       $f0, $f22, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = MUL_S(ctx->f22.fl, ctx->f0.fl);
    // 0x80077904: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80077908: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8007790C: lwc1        $f0, -0x2CE0($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X2CE0);
    // 0x80077910: mul.s       $f24, $f24, $f0
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f24.fl = MUL_S(ctx->f24.fl, ctx->f0.fl);
    // 0x80077914: mfc1        $a2, $f24
    ctx->r6 = (int32_t)ctx->f24.u32l;
    // 0x80077918: jal         0x800739A4
    // 0x8007791C: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    func_800739A4(rdram, ctx);
        goto after_1;
    // 0x8007791C: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    after_1:
    // 0x80077920: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80077924: lwc1        $f0, -0x2CDC($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X2CDC);
    // 0x80077928: mul.s       $f20, $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f20.fl = MUL_S(ctx->f20.fl, ctx->f0.fl);
    // 0x8007792C: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80077930: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80077934: lwc1        $f4, -0x2CD8($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X2CD8);
    // 0x80077938: lwc1        $f0, 0x0($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X0);
    // 0x8007793C: mul.s       $f4, $f22, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f4.fl = MUL_S(ctx->f22.fl, ctx->f4.fl);
    // 0x80077940: swc1        $f0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f0.u32l;
    // 0x80077944: lwc1        $f2, 0x4($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0X4);
    // 0x80077948: lwc1        $f0, 0x6FA8($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X6FA8);
    // 0x8007794C: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x80077950: sub.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl - ctx->f0.fl;
    // 0x80077954: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80077958: lwc1        $f0, -0x2CD4($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X2CD4);
    // 0x8007795C: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x80077960: sub.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl - ctx->f0.fl;
    // 0x80077964: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80077968: lwc1        $f0, -0x2CD0($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X2CD0);
    // 0x8007796C: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x80077970: mul.s       $f0, $f26, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = MUL_S(ctx->f26.fl, ctx->f0.fl);
    // 0x80077974: swc1        $f2, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f2.u32l;
    // 0x80077978: lwc1        $f2, 0x8($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0X8);
    // 0x8007797C: addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    // 0x80077980: swc1        $f2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f2.u32l;
    // 0x80077984: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x80077988: jal         0x80072550
    // 0x8007798C: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    func_80072550(rdram, ctx);
        goto after_2;
    // 0x8007798C: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    after_2:
L_80077990:
    // 0x80077990: lw          $ra, 0x50($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X50);
    // 0x80077994: lw          $s1, 0x4C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X4C);
    // 0x80077998: lw          $s0, 0x48($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X48);
    // 0x8007799C: ldc1        $f26, 0x70($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X70);
    // 0x800779A0: ldc1        $f24, 0x68($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X68);
    // 0x800779A4: ldc1        $f22, 0x60($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X60);
    // 0x800779A8: ldc1        $f20, 0x58($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X58);
    // 0x800779AC: jr          $ra
    // 0x800779B0: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
    return;
    // 0x800779B0: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
;}
RECOMP_FUNC void func_800779B4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800779B4: addiu       $sp, $sp, -0x70
    ctx->r29 = ADD32(ctx->r29, -0X70);
    // 0x800779B8: sdc1        $f26, 0x68($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X68, ctx->r29);
    // 0x800779BC: mtc1        $a2, $f26
    ctx->f26.u32l = ctx->r6;
    // 0x800779C0: sdc1        $f24, 0x60($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X60, ctx->r29);
    // 0x800779C4: mtc1        $a3, $f24
    ctx->f24.u32l = ctx->r7;
    // 0x800779C8: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x800779CC: sdc1        $f22, 0x58($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X58, ctx->r29);
    // 0x800779D0: lwc1        $f22, 0x84($sp)
    ctx->f22.u32l = MEM_W(ctx->r29, 0X84);
    // 0x800779D4: lbu         $v0, -0x56BC($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X56BC);
    // 0x800779D8: sw          $s0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r16;
    // 0x800779DC: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x800779E0: sw          $s1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r17;
    // 0x800779E4: sw          $ra, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r31;
    // 0x800779E8: sdc1        $f20, 0x50($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X50, ctx->r29);
    // 0x800779EC: beq         $v0, $zero, L_80077A9C
    if (ctx->r2 == 0) {
        // 0x800779F0: addu        $s1, $a1, $zero
        ctx->r17 = ADD32(ctx->r5, 0);
            goto L_80077A9C;
    }
    // 0x800779F0: addu        $s1, $a1, $zero
    ctx->r17 = ADD32(ctx->r5, 0);
    // 0x800779F4: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x800779F8: c.lt.s      $f20, $f22
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 22);
    c1cs = ctx->f20.fl < ctx->f22.fl;
    // 0x800779FC: nop

    // 0x80077A00: bc1f        L_80077A9C
    if (!c1cs) {
        // 0x80077A04: nop
    
            goto L_80077A9C;
    }
    // 0x80077A04: nop

    // 0x80077A08: jal         0x8001CF2C
    // 0x80077A0C: addiu       $a0, $s1, 0x24
    ctx->r4 = ADD32(ctx->r17, 0X24);
    func_8001CF2C(rdram, ctx);
        goto after_0;
    // 0x80077A0C: addiu       $a0, $s1, 0x24
    ctx->r4 = ADD32(ctx->r17, 0X24);
    after_0:
    // 0x80077A10: c.lt.s      $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f20.fl < ctx->f0.fl;
    // 0x80077A14: nop

    // 0x80077A18: bc1f        L_80077A9C
    if (!c1cs) {
        // 0x80077A1C: lui         $a0, 0x8007
        ctx->r4 = S32(0X8007 << 16);
            goto L_80077A9C;
    }
    // 0x80077A1C: lui         $a0, 0x8007
    ctx->r4 = S32(0X8007 << 16);
    // 0x80077A20: addiu       $a0, $a0, 0x6BE4
    ctx->r4 = ADD32(ctx->r4, 0X6BE4);
    // 0x80077A24: addiu       $a1, $sp, 0x10
    ctx->r5 = ADD32(ctx->r29, 0X10);
    // 0x80077A28: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x80077A2C: lwc1        $f0, 0x80($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X80);
    // 0x80077A30: lw          $v0, 0x8C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X8C);
    // 0x80077A34: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80077A38: lwc1        $f4, -0x2CCC($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X2CCC);
    // 0x80077A3C: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80077A40: lwc1        $f6, -0x2CC8($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X2CC8);
    // 0x80077A44: lwc1        $f2, 0x88($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X88);
    // 0x80077A48: addiu       $a3, $zero, 0xF
    ctx->r7 = ADD32(0, 0XF);
    // 0x80077A4C: sw          $s1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r17;
    // 0x80077A50: swc1        $f22, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f22.u32l;
    // 0x80077A54: swc1        $f24, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f24.u32l;
    // 0x80077A58: sh          $s0, 0x3C($sp)
    MEM_H(0X3C, ctx->r29) = ctx->r16;
    // 0x80077A5C: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x80077A60: sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    // 0x80077A64: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x80077A68: swc1        $f0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f0.u32l;
    // 0x80077A6C: lwc1        $f0, 0x90($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X90);
    // 0x80077A70: addiu       $v0, $v0, 0xD70
    ctx->r2 = ADD32(ctx->r2, 0XD70);
    // 0x80077A74: swc1        $f0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f0.u32l;
    // 0x80077A78: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80077A7C: lwc1        $f0, -0x2CC4($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X2CC4);
    // 0x80077A80: mul.s       $f4, $f26, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f4.fl = MUL_S(ctx->f26.fl, ctx->f4.fl);
    // 0x80077A84: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // 0x80077A88: swc1        $f6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f6.u32l;
    // 0x80077A8C: div.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f2.fl);
    // 0x80077A90: swc1        $f0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f0.u32l;
    // 0x80077A94: jal         0x8003FFEC
    // 0x80077A98: swc1        $f4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f4.u32l;
    func_8003FFEC(rdram, ctx);
        goto after_1;
    // 0x80077A98: swc1        $f4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f4.u32l;
    after_1:
L_80077A9C:
    // 0x80077A9C: lw          $ra, 0x48($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X48);
    // 0x80077AA0: lw          $s1, 0x44($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X44);
    // 0x80077AA4: lw          $s0, 0x40($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X40);
    // 0x80077AA8: ldc1        $f26, 0x68($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X68);
    // 0x80077AAC: ldc1        $f24, 0x60($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X60);
    // 0x80077AB0: ldc1        $f22, 0x58($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X58);
    // 0x80077AB4: ldc1        $f20, 0x50($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X50);
    // 0x80077AB8: jr          $ra
    // 0x80077ABC: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
    return;
    // 0x80077ABC: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
;}
