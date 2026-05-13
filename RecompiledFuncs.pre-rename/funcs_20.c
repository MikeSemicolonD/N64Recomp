#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void func_8007E810(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007E810: addiu       $sp, $sp, -0x110
    ctx->r29 = ADD32(ctx->r29, -0X110);
    // 0x8007E814: sw          $s1, 0xE4($sp)
    MEM_W(0XE4, ctx->r29) = ctx->r17;
    // 0x8007E818: addu        $s1, $a0, $zero
    ctx->r17 = ADD32(ctx->r4, 0);
    // 0x8007E81C: sw          $ra, 0xE8($sp)
    MEM_W(0XE8, ctx->r29) = ctx->r31;
    // 0x8007E820: sw          $s0, 0xE0($sp)
    MEM_W(0XE0, ctx->r29) = ctx->r16;
    // 0x8007E824: sdc1        $f26, 0x108($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X108, ctx->r29);
    // 0x8007E828: sdc1        $f24, 0x100($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X100, ctx->r29);
    // 0x8007E82C: sdc1        $f22, 0xF8($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0XF8, ctx->r29);
    // 0x8007E830: sdc1        $f20, 0xF0($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0XF0, ctx->r29);
    // 0x8007E834: lwc1        $f0, 0x2B8($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X2B8);
    // 0x8007E838: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8007E83C: lwc1        $f2, -0x27FC($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X27FC);
    // 0x8007E840: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x8007E844: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x8007E848: c.le.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl <= ctx->f2.fl;
    // 0x8007E84C: nop

    // 0x8007E850: bc1f        L_8007EEF8
    if (!c1cs) {
        // 0x8007E854: swc1        $f0, 0x2B8($s1)
        MEM_W(0X2B8, ctx->r17) = ctx->f0.u32l;
            goto L_8007EEF8;
    }
    // 0x8007E854: swc1        $f0, 0x2B8($s1)
    MEM_W(0X2B8, ctx->r17) = ctx->f0.u32l;
    // 0x8007E858: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8007E85C: lwc1        $f0, -0x27F8($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X27F8);
    // 0x8007E860: addiu       $v0, $zero, 0x76
    ctx->r2 = ADD32(0, 0X76);
    // 0x8007E864: swc1        $f0, 0x2B8($s1)
    MEM_W(0X2B8, ctx->r17) = ctx->f0.u32l;
    // 0x8007E868: sb          $v0, 0x58($sp)
    MEM_B(0X58, ctx->r29) = ctx->r2;
    // 0x8007E86C: addiu       $v0, $zero, 0x61
    ctx->r2 = ADD32(0, 0X61);
    // 0x8007E870: sb          $v0, 0x59($sp)
    MEM_B(0X59, ctx->r29) = ctx->r2;
    // 0x8007E874: addiu       $v0, $zero, 0x63
    ctx->r2 = ADD32(0, 0X63);
    // 0x8007E878: sb          $v0, 0x5A($sp)
    MEM_B(0X5A, ctx->r29) = ctx->r2;
    // 0x8007E87C: addiu       $v0, $zero, 0x75
    ctx->r2 = ADD32(0, 0X75);
    // 0x8007E880: jal         0x80003430
    // 0x8007E884: sb          $v0, 0x5B($sp)
    MEM_B(0X5B, ctx->r29) = ctx->r2;
    rand_recomp(rdram, ctx);
        goto after_0;
    // 0x8007E884: sb          $v0, 0x5B($sp)
    MEM_B(0X5B, ctx->r29) = ctx->r2;
    after_0:
    // 0x8007E888: lui         $v1, 0x9249
    ctx->r3 = S32(0X9249 << 16);
    // 0x8007E88C: ori         $v1, $v1, 0x2493
    ctx->r3 = ctx->r3 | 0X2493;
    // 0x8007E890: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x8007E894: sra         $a0, $v0, 16
    ctx->r4 = S32(SIGNED(ctx->r2) >> 16);
    // 0x8007E898: mult        $a0, $v1
    result = S64(S32(ctx->r4)) * S64(S32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8007E89C: sra         $v0, $v0, 31
    ctx->r2 = S32(SIGNED(ctx->r2) >> 31);
    // 0x8007E8A0: mfhi        $t0
    ctx->r8 = hi;
    // 0x8007E8A4: addu        $v1, $t0, $a0
    ctx->r3 = ADD32(ctx->r8, ctx->r4);
    // 0x8007E8A8: sra         $v1, $v1, 2
    ctx->r3 = S32(SIGNED(ctx->r3) >> 2);
    // 0x8007E8AC: subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // 0x8007E8B0: sll         $v0, $v1, 3
    ctx->r2 = S32(ctx->r3 << 3);
    // 0x8007E8B4: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x8007E8B8: subu        $a0, $a0, $v0
    ctx->r4 = SUB32(ctx->r4, ctx->r2);
    // 0x8007E8BC: addiu       $a0, $a0, 0x30
    ctx->r4 = ADD32(ctx->r4, 0X30);
    // 0x8007E8C0: sb          $a0, 0x5C($sp)
    MEM_B(0X5C, ctx->r29) = ctx->r4;
    // 0x8007E8C4: andi        $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 & 0XFF;
    // 0x8007E8C8: addiu       $v0, $zero, 0x33
    ctx->r2 = ADD32(0, 0X33);
    // 0x8007E8CC: beq         $a0, $v0, L_8007E8DC
    if (ctx->r4 == ctx->r2) {
        // 0x8007E8D0: addiu       $v0, $zero, 0x36
        ctx->r2 = ADD32(0, 0X36);
            goto L_8007E8DC;
    }
    // 0x8007E8D0: addiu       $v0, $zero, 0x36
    ctx->r2 = ADD32(0, 0X36);
    // 0x8007E8D4: bne         $a0, $v0, L_8007E8E8
    if (ctx->r4 != ctx->r2) {
        // 0x8007E8D8: addiu       $a1, $sp, 0x58
        ctx->r5 = ADD32(ctx->r29, 0X58);
            goto L_8007E8E8;
    }
    // 0x8007E8D8: addiu       $a1, $sp, 0x58
    ctx->r5 = ADD32(ctx->r29, 0X58);
L_8007E8DC:
    // 0x8007E8DC: addiu       $v0, $zero, 0x30
    ctx->r2 = ADD32(0, 0X30);
    // 0x8007E8E0: sb          $v0, 0x5C($sp)
    MEM_B(0X5C, ctx->r29) = ctx->r2;
    // 0x8007E8E4: addiu       $a1, $sp, 0x58
    ctx->r5 = ADD32(ctx->r29, 0X58);
L_8007E8E8:
    // 0x8007E8E8: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // 0x8007E8EC: sb          $zero, 0x5D($sp)
    MEM_B(0X5D, ctx->r29) = 0;
    // 0x8007E8F0: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x8007E8F4: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x8007E8F8: lw          $a0, 0x30($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X30);
    // 0x8007E8FC: jal         0x80058360
    // 0x8007E900: addiu       $a3, $sp, 0x18
    ctx->r7 = ADD32(ctx->r29, 0X18);
    func_80058360(rdram, ctx);
        goto after_1;
    // 0x8007E900: addiu       $a3, $sp, 0x18
    ctx->r7 = ADD32(ctx->r29, 0X18);
    after_1:
    // 0x8007E904: lwc1        $f0, 0x24($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X24);
    // 0x8007E908: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8007E90C: lwc1        $f4, -0x27F4($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X27F4);
    // 0x8007E910: mul.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x8007E914: lwc1        $f2, 0x2C($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x8007E918: mul.s       $f2, $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f4.fl);
    // 0x8007E91C: lwc1        $f12, 0x18($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X18);
    // 0x8007E920: lui         $a2, 0x8014
    ctx->r6 = S32(0X8014 << 16);
    // 0x8007E924: add.s       $f12, $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = ctx->f12.fl + ctx->f0.fl;
    // 0x8007E928: lwc1        $f14, 0x20($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X20);
    // 0x8007E92C: addiu       $a2, $a2, -0x7FA8
    ctx->r6 = ADD32(ctx->r6, -0X7FA8);
    // 0x8007E930: add.s       $f14, $f14, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f14.fl = ctx->f14.fl + ctx->f2.fl;
    // 0x8007E934: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    // 0x8007E938: swc1        $f12, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f12.u32l;
    // 0x8007E93C: jal         0x80067D90
    // 0x8007E940: swc1        $f14, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f14.u32l;
    func_80067D90(rdram, ctx);
        goto after_2;
    // 0x8007E940: swc1        $f14, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f14.u32l;
    after_2:
    // 0x8007E944: swc1        $f0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f0.u32l;
    // 0x8007E948: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8007E94C: lwc1        $f0, -0x27F0($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X27F0);
    // 0x8007E950: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8007E954: lwc1        $f12, -0x27EC($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X27EC);
    // 0x8007E958: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8007E95C: lwc1        $f6, -0x27E8($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X27E8);
    // 0x8007E960: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
    // 0x8007E964: lw          $t1, 0x18($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X18);
    // 0x8007E968: lw          $t2, 0x1C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X1C);
    // 0x8007E96C: lw          $t3, 0x20($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X20);
    // 0x8007E970: sw          $t1, 0x228($s1)
    MEM_W(0X228, ctx->r17) = ctx->r9;
    // 0x8007E974: sw          $t2, 0x22C($s1)
    MEM_W(0X22C, ctx->r17) = ctx->r10;
    // 0x8007E978: sw          $t3, 0x230($s1)
    MEM_W(0X230, ctx->r17) = ctx->r11;
    // 0x8007E97C: sw          $zero, 0x234($s1)
    MEM_W(0X234, ctx->r17) = 0;
    // 0x8007E980: sw          $zero, 0x238($s1)
    MEM_W(0X238, ctx->r17) = 0;
    // 0x8007E984: sw          $zero, 0x23C($s1)
    MEM_W(0X23C, ctx->r17) = 0;
    // 0x8007E988: sb          $s0, 0x248($s1)
    MEM_B(0X248, ctx->r17) = ctx->r16;
    // 0x8007E98C: swc1        $f0, 0x240($s1)
    MEM_W(0X240, ctx->r17) = ctx->f0.u32l;
    // 0x8007E990: swc1        $f12, 0x244($s1)
    MEM_W(0X244, ctx->r17) = ctx->f12.u32l;
    // 0x8007E994: lwc1        $f2, 0x24($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X24);
    // 0x8007E998: mul.s       $f2, $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f6.fl);
    // 0x8007E99C: lwc1        $f0, 0x18($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X18);
    // 0x8007E9A0: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x8007E9A4: swc1        $f0, 0x24C($s1)
    MEM_W(0X24C, ctx->r17) = ctx->f0.u32l;
    // 0x8007E9A8: lwc1        $f2, 0x28($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X28);
    // 0x8007E9AC: mul.s       $f2, $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f6.fl);
    // 0x8007E9B0: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8007E9B4: lwc1        $f4, -0x27E4($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X27E4);
    // 0x8007E9B8: lwc1        $f0, 0x1C($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x8007E9BC: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8007E9C0: lwc1        $f8, -0x27E0($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X27E0);
    // 0x8007E9C4: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x8007E9C8: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8007E9CC: lwc1        $f10, -0x27DC($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X27DC);
    // 0x8007E9D0: swc1        $f0, 0x250($s1)
    MEM_W(0X250, ctx->r17) = ctx->f0.u32l;
    // 0x8007E9D4: lwc1        $f0, 0x2C($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x8007E9D8: lwc1        $f2, 0x20($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X20);
    // 0x8007E9DC: mul.s       $f0, $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x8007E9E0: sw          $zero, 0x258($s1)
    MEM_W(0X258, ctx->r17) = 0;
    // 0x8007E9E4: sw          $zero, 0x25C($s1)
    MEM_W(0X25C, ctx->r17) = 0;
    // 0x8007E9E8: sw          $zero, 0x260($s1)
    MEM_W(0X260, ctx->r17) = 0;
    // 0x8007E9EC: swc1        $f12, 0x264($s1)
    MEM_W(0X264, ctx->r17) = ctx->f12.u32l;
    // 0x8007E9F0: add.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x8007E9F4: swc1        $f4, 0x268($s1)
    MEM_W(0X268, ctx->r17) = ctx->f4.u32l;
    // 0x8007E9F8: sb          $s0, 0x26C($s1)
    MEM_B(0X26C, ctx->r17) = ctx->r16;
    // 0x8007E9FC: swc1        $f2, 0x254($s1)
    MEM_W(0X254, ctx->r17) = ctx->f2.u32l;
    // 0x8007EA00: lw          $t1, 0x18($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X18);
    // 0x8007EA04: lw          $t2, 0x1C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X1C);
    // 0x8007EA08: lw          $t3, 0x20($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X20);
    // 0x8007EA0C: sw          $t1, 0x270($s1)
    MEM_W(0X270, ctx->r17) = ctx->r9;
    // 0x8007EA10: sw          $t2, 0x274($s1)
    MEM_W(0X274, ctx->r17) = ctx->r10;
    // 0x8007EA14: sw          $t3, 0x278($s1)
    MEM_W(0X278, ctx->r17) = ctx->r11;
    // 0x8007EA18: sw          $zero, 0x27C($s1)
    MEM_W(0X27C, ctx->r17) = 0;
    // 0x8007EA1C: sw          $zero, 0x280($s1)
    MEM_W(0X280, ctx->r17) = 0;
    // 0x8007EA20: sw          $zero, 0x284($s1)
    MEM_W(0X284, ctx->r17) = 0;
    // 0x8007EA24: swc1        $f8, 0x288($s1)
    MEM_W(0X288, ctx->r17) = ctx->f8.u32l;
    // 0x8007EA28: swc1        $f10, 0x28C($s1)
    MEM_W(0X28C, ctx->r17) = ctx->f10.u32l;
    // 0x8007EA2C: sb          $s0, 0x290($s1)
    MEM_B(0X290, ctx->r17) = ctx->r16;
    // 0x8007EA30: lwc1        $f2, 0x24($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X24);
    // 0x8007EA34: mul.s       $f2, $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f6.fl);
    // 0x8007EA38: lwc1        $f0, 0x18($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X18);
    // 0x8007EA3C: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x8007EA40: swc1        $f0, 0x294($s1)
    MEM_W(0X294, ctx->r17) = ctx->f0.u32l;
    // 0x8007EA44: lwc1        $f2, 0x28($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X28);
    // 0x8007EA48: mul.s       $f2, $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f6.fl);
    // 0x8007EA4C: lwc1        $f0, 0x1C($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x8007EA50: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x8007EA54: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8007EA58: lwc1        $f2, -0x27D8($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X27D8);
    // 0x8007EA5C: swc1        $f0, 0x298($s1)
    MEM_W(0X298, ctx->r17) = ctx->f0.u32l;
    // 0x8007EA60: lwc1        $f0, 0x2C($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x8007EA64: lwc1        $f4, 0x20($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X20);
    // 0x8007EA68: mul.s       $f0, $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x8007EA6C: sw          $zero, 0x2A0($s1)
    MEM_W(0X2A0, ctx->r17) = 0;
    // 0x8007EA70: sw          $zero, 0x2A4($s1)
    MEM_W(0X2A4, ctx->r17) = 0;
    // 0x8007EA74: sw          $zero, 0x2A8($s1)
    MEM_W(0X2A8, ctx->r17) = 0;
    // 0x8007EA78: swc1        $f12, 0x2AC($s1)
    MEM_W(0X2AC, ctx->r17) = ctx->f12.u32l;
    // 0x8007EA7C: add.s       $f4, $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f0.fl;
    // 0x8007EA80: swc1        $f2, 0x2B0($s1)
    MEM_W(0X2B0, ctx->r17) = ctx->f2.u32l;
    // 0x8007EA84: sb          $s0, 0x2B4($s1)
    MEM_B(0X2B4, ctx->r17) = ctx->r16;
    // 0x8007EA88: jal         0x80003430
    // 0x8007EA8C: swc1        $f4, 0x29C($s1)
    MEM_W(0X29C, ctx->r17) = ctx->f4.u32l;
    rand_recomp(rdram, ctx);
        goto after_3;
    // 0x8007EA8C: swc1        $f4, 0x29C($s1)
    MEM_W(0X29C, ctx->r17) = ctx->f4.u32l;
    after_3:
    // 0x8007EA90: andi        $v0, $v0, 0x7F
    ctx->r2 = ctx->r2 & 0X7F;
    // 0x8007EA94: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8007EA98: lwc1        $f22, -0x27D4($at)
    ctx->f22.u32l = MEM_W(ctx->r1, -0X27D4);
    // 0x8007EA9C: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x8007EAA0: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x8007EAA4: sub.s       $f0, $f0, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f22.fl;
    // 0x8007EAA8: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8007EAAC: lwc1        $f20, -0x27D0($at)
    ctx->f20.u32l = MEM_W(ctx->r1, -0X27D0);
    // 0x8007EAB0: div.s       $f0, $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f20.fl);
    // 0x8007EAB4: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x8007EAB8: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8007EABC: lwc1        $f24, -0x27CC($at)
    ctx->f24.u32l = MEM_W(ctx->r1, -0X27CC);
    // 0x8007EAC0: add.s       $f0, $f0, $f24
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f24.fl;
    // 0x8007EAC4: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8007EAC8: lwc1        $f2, -0x27C8($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X27C8);
    // 0x8007EACC: mul.s       $f26, $f0, $f2
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f26.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x8007EAD0: jal         0x80003430
    // 0x8007EAD4: nop

    rand_recomp(rdram, ctx);
        goto after_4;
    // 0x8007EAD4: nop

    after_4:
    // 0x8007EAD8: andi        $v0, $v0, 0x7F
    ctx->r2 = ctx->r2 & 0X7F;
    // 0x8007EADC: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x8007EAE0: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x8007EAE4: sub.s       $f0, $f0, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f22.fl;
    // 0x8007EAE8: div.s       $f0, $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f20.fl);
    // 0x8007EAEC: abs.s       $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = fabsf(ctx->f0.fl);
    // 0x8007EAF0: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8007EAF4: add.s       $f6, $f6, $f24
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f24.fl;
    // 0x8007EAF8: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8007EAFC: lwc1        $f2, -0x27C4($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X27C4);
    // 0x8007EB00: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8007EB04: lwc1        $f4, -0x27C0($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X27C0);
    // 0x8007EB08: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8007EB0C: lwc1        $f0, -0x27BC($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X27BC);
    // 0x8007EB10: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8007EB14: lwc1        $f8, -0x27B8($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X27B8);
    // 0x8007EB18: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8007EB1C: lwc1        $f10, -0x27B4($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X27B4);
    // 0x8007EB20: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8007EB24: lwc1        $f12, -0x27B0($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X27B0);
    // 0x8007EB28: lw          $v0, 0xC08($v0)
    ctx->r2 = MEM_W(ctx->r2, 0XC08);
    // 0x8007EB2C: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8007EB30: lwc1        $f14, -0x27AC($at)
    ctx->f14.u32l = MEM_W(ctx->r1, -0X27AC);
    // 0x8007EB34: addiu       $v0, $v0, 0x1C
    ctx->r2 = ADD32(ctx->r2, 0X1C);
    // 0x8007EB38: swc1        $f2, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f2.u32l;
    // 0x8007EB3C: lw          $t1, 0x48($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X48);
    // 0x8007EB40: lw          $t2, 0x4C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X4C);
    // 0x8007EB44: lw          $t3, 0x50($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X50);
    // 0x8007EB48: sw          $t1, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r9;
    // 0x8007EB4C: sw          $t2, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r10;
    // 0x8007EB50: sw          $t3, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r11;
    // 0x8007EB54: sw          $v0, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->r2;
    // 0x8007EB58: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8007EB5C: swc1        $f0, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->f0.u32l;
    // 0x8007EB60: swc1        $f0, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->f0.u32l;
    // 0x8007EB64: swc1        $f0, 0xB8($sp)
    MEM_W(0XB8, ctx->r29) = ctx->f0.u32l;
    // 0x8007EB68: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8007EB6C: lwc1        $f0, -0x27A8($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X27A8);
    // 0x8007EB70: lw          $v0, 0xC04($v0)
    ctx->r2 = MEM_W(ctx->r2, 0XC04);
    // 0x8007EB74: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8007EB78: lwc1        $f2, -0x27A4($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X27A4);
    // 0x8007EB7C: swc1        $f12, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->f12.u32l;
    // 0x8007EB80: mul.s       $f12, $f6, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x8007EB84: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8007EB88: lwc1        $f0, -0x27A0($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X27A0);
    // 0x8007EB8C: sw          $zero, 0x70($sp)
    MEM_W(0X70, ctx->r29) = 0;
    // 0x8007EB90: swc1        $f4, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->f4.u32l;
    // 0x8007EB94: sw          $zero, 0x78($sp)
    MEM_W(0X78, ctx->r29) = 0;
    // 0x8007EB98: sw          $zero, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = 0;
    // 0x8007EB9C: sw          $zero, 0x80($sp)
    MEM_W(0X80, ctx->r29) = 0;
    // 0x8007EBA0: sw          $zero, 0x84($sp)
    MEM_W(0X84, ctx->r29) = 0;
    // 0x8007EBA4: sw          $zero, 0x90($sp)
    MEM_W(0X90, ctx->r29) = 0;
    // 0x8007EBA8: sw          $zero, 0x94($sp)
    MEM_W(0X94, ctx->r29) = 0;
    // 0x8007EBAC: swc1        $f8, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->f8.u32l;
    // 0x8007EBB0: sh          $zero, 0x9C($sp)
    MEM_H(0X9C, ctx->r29) = 0;
    // 0x8007EBB4: sh          $zero, 0x9E($sp)
    MEM_H(0X9E, ctx->r29) = 0;
    // 0x8007EBB8: swc1        $f10, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->f10.u32l;
    // 0x8007EBBC: sw          $zero, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = 0;
    // 0x8007EBC0: sw          $zero, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = 0;
    // 0x8007EBC4: sw          $zero, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = 0;
    // 0x8007EBC8: swc1        $f14, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->f14.u32l;
    // 0x8007EBCC: sw          $zero, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = 0;
    // 0x8007EBD0: mul.s       $f0, $f26, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = MUL_S(ctx->f26.fl, ctx->f0.fl);
    // 0x8007EBD4: sb          $s0, 0xCC($sp)
    MEM_B(0XCC, ctx->r29) = ctx->r16;
    // 0x8007EBD8: sw          $v0, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->r2;
    // 0x8007EBDC: addiu       $v0, $zero, 0x10
    ctx->r2 = ADD32(0, 0X10);
    // 0x8007EBE0: c.le.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl <= ctx->f0.fl;
    // 0x8007EBE4: nop

    // 0x8007EBE8: bc1t        L_8007EC00
    if (c1cs) {
        // 0x8007EBEC: sb          $v0, 0xCD($sp)
        MEM_B(0XCD, ctx->r29) = ctx->r2;
            goto L_8007EC00;
    }
    // 0x8007EBEC: sb          $v0, 0xCD($sp)
    MEM_B(0XCD, ctx->r29) = ctx->r2;
    // 0x8007EBF0: trunc.w.s   $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    ctx->f16.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x8007EBF4: mfc1        $v1, $f16
    ctx->r3 = (int32_t)ctx->f16.u32l;
    // 0x8007EBF8: j           L_8007EC14
    // 0x8007EBFC: nop

        goto L_8007EC14;
    // 0x8007EBFC: nop

L_8007EC00:
    // 0x8007EC00: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x8007EC04: lui         $v0, 0x8000
    ctx->r2 = S32(0X8000 << 16);
    // 0x8007EC08: trunc.w.s   $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    ctx->f16.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x8007EC0C: mfc1        $v1, $f16
    ctx->r3 = (int32_t)ctx->f16.u32l;
    // 0x8007EC10: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
L_8007EC14:
    // 0x8007EC14: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8007EC18: lwc1        $f0, -0x279C($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X279C);
    // 0x8007EC1C: mul.s       $f0, $f12, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = MUL_S(ctx->f12.fl, ctx->f0.fl);
    // 0x8007EC20: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8007EC24: lwc1        $f2, -0x2798($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X2798);
    // 0x8007EC28: c.le.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl <= ctx->f0.fl;
    // 0x8007EC2C: nop

    // 0x8007EC30: bc1t        L_8007EC48
    if (c1cs) {
        // 0x8007EC34: sh          $v1, 0xD0($sp)
        MEM_H(0XD0, ctx->r29) = ctx->r3;
            goto L_8007EC48;
    }
    // 0x8007EC34: sh          $v1, 0xD0($sp)
    MEM_H(0XD0, ctx->r29) = ctx->r3;
    // 0x8007EC38: trunc.w.s   $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    ctx->f16.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x8007EC3C: mfc1        $v1, $f16
    ctx->r3 = (int32_t)ctx->f16.u32l;
    // 0x8007EC40: j           L_8007EC5C
    // 0x8007EC44: nop

        goto L_8007EC5C;
    // 0x8007EC44: nop

L_8007EC48:
    // 0x8007EC48: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x8007EC4C: lui         $v0, 0x8000
    ctx->r2 = S32(0X8000 << 16);
    // 0x8007EC50: trunc.w.s   $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    ctx->f16.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x8007EC54: mfc1        $v1, $f16
    ctx->r3 = (int32_t)ctx->f16.u32l;
    // 0x8007EC58: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
L_8007EC5C:
    // 0x8007EC5C: lwc1        $f0, 0xA0($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0XA0);
    // 0x8007EC60: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8007EC64: lwc1        $f2, -0x2794($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X2794);
    // 0x8007EC68: c.le.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl <= ctx->f0.fl;
    // 0x8007EC6C: nop

    // 0x8007EC70: bc1t        L_8007EC88
    if (c1cs) {
        // 0x8007EC74: sh          $v1, 0xD2($sp)
        MEM_H(0XD2, ctx->r29) = ctx->r3;
            goto L_8007EC88;
    }
    // 0x8007EC74: sh          $v1, 0xD2($sp)
    MEM_H(0XD2, ctx->r29) = ctx->r3;
    // 0x8007EC78: trunc.w.s   $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    ctx->f16.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x8007EC7C: mfc1        $v1, $f16
    ctx->r3 = (int32_t)ctx->f16.u32l;
    // 0x8007EC80: j           L_8007ECA0
    // 0x8007EC84: addiu       $a0, $sp, 0x60
    ctx->r4 = ADD32(ctx->r29, 0X60);
        goto L_8007ECA0;
    // 0x8007EC84: addiu       $a0, $sp, 0x60
    ctx->r4 = ADD32(ctx->r29, 0X60);
L_8007EC88:
    // 0x8007EC88: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x8007EC8C: lui         $v0, 0x8000
    ctx->r2 = S32(0X8000 << 16);
    // 0x8007EC90: trunc.w.s   $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    ctx->f16.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x8007EC94: mfc1        $v1, $f16
    ctx->r3 = (int32_t)ctx->f16.u32l;
    // 0x8007EC98: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x8007EC9C: addiu       $a0, $sp, 0x60
    ctx->r4 = ADD32(ctx->r29, 0X60);
L_8007ECA0:
    // 0x8007ECA0: lui         $v0, 0x900
    ctx->r2 = S32(0X900 << 16);
    // 0x8007ECA4: sw          $v0, 0xD8($sp)
    MEM_W(0XD8, ctx->r29) = ctx->r2;
    // 0x8007ECA8: addiu       $v0, $zero, 0x41
    ctx->r2 = ADD32(0, 0X41);
    // 0x8007ECAC: sh          $v0, 0xDC($sp)
    MEM_H(0XDC, ctx->r29) = ctx->r2;
    // 0x8007ECB0: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x8007ECB4: addiu       $v0, $v0, -0x1AFC
    ctx->r2 = ADD32(ctx->r2, -0X1AFC);
    // 0x8007ECB8: sh          $v1, 0xD4($sp)
    MEM_H(0XD4, ctx->r29) = ctx->r3;
    // 0x8007ECBC: jal         0x80041CBC
    // 0x8007ECC0: sw          $v0, 0xC0($sp)
    MEM_W(0XC0, ctx->r29) = ctx->r2;
    func_80041CBC(rdram, ctx);
        goto after_5;
    // 0x8007ECC0: sw          $v0, 0xC0($sp)
    MEM_W(0XC0, ctx->r29) = ctx->r2;
    after_5:
    // 0x8007ECC4: andi        $s0, $v0, 0xFFFF
    ctx->r16 = ctx->r2 & 0XFFFF;
    // 0x8007ECC8: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x8007ECCC: jal         0x80041D08
    // 0x8007ECD0: addiu       $a1, $s1, 0x228
    ctx->r5 = ADD32(ctx->r17, 0X228);
    func_80041D08(rdram, ctx);
        goto after_6;
    // 0x8007ECD0: addiu       $a1, $s1, 0x228
    ctx->r5 = ADD32(ctx->r17, 0X228);
    after_6:
    // 0x8007ECD4: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x8007ECD8: jal         0x80041D08
    // 0x8007ECDC: addiu       $a1, $s1, 0x24C
    ctx->r5 = ADD32(ctx->r17, 0X24C);
    func_80041D08(rdram, ctx);
        goto after_7;
    // 0x8007ECDC: addiu       $a1, $s1, 0x24C
    ctx->r5 = ADD32(ctx->r17, 0X24C);
    after_7:
    // 0x8007ECE0: jal         0x80003430
    // 0x8007ECE4: nop

    rand_recomp(rdram, ctx);
        goto after_8;
    // 0x8007ECE4: nop

    after_8:
    // 0x8007ECE8: andi        $v0, $v0, 0x7F
    ctx->r2 = ctx->r2 & 0X7F;
    // 0x8007ECEC: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8007ECF0: lwc1        $f2, -0x2790($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X2790);
    // 0x8007ECF4: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x8007ECF8: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x8007ECFC: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x8007ED00: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8007ED04: lwc1        $f2, -0x278C($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X278C);
    // 0x8007ED08: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x8007ED0C: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x8007ED10: abs.s       $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = fabsf(ctx->f0.fl);
    // 0x8007ED14: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8007ED18: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8007ED1C: lwc1        $f12, -0x2788($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X2788);
    // 0x8007ED20: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8007ED24: lwc1        $f2, -0x2784($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X2784);
    // 0x8007ED28: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8007ED2C: lwc1        $f4, -0x2780($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X2780);
    // 0x8007ED30: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8007ED34: lwc1        $f0, -0x277C($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X277C);
    // 0x8007ED38: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8007ED3C: lwc1        $f8, -0x2778($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X2778);
    // 0x8007ED40: lw          $v0, 0xC08($v0)
    ctx->r2 = MEM_W(ctx->r2, 0XC08);
    // 0x8007ED44: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8007ED48: lwc1        $f10, -0x2774($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X2774);
    // 0x8007ED4C: addiu       $v0, $v0, 0x1C
    ctx->r2 = ADD32(ctx->r2, 0X1C);
    // 0x8007ED50: swc1        $f2, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f2.u32l;
    // 0x8007ED54: lw          $t1, 0x48($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X48);
    // 0x8007ED58: lw          $t2, 0x4C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X4C);
    // 0x8007ED5C: lw          $t3, 0x50($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X50);
    // 0x8007ED60: sw          $t1, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r9;
    // 0x8007ED64: sw          $t2, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r10;
    // 0x8007ED68: sw          $t3, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r11;
    // 0x8007ED6C: sw          $v0, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->r2;
    // 0x8007ED70: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8007ED74: swc1        $f0, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->f0.u32l;
    // 0x8007ED78: swc1        $f0, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->f0.u32l;
    // 0x8007ED7C: swc1        $f0, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->f0.u32l;
    // 0x8007ED80: swc1        $f0, 0xB8($sp)
    MEM_W(0XB8, ctx->r29) = ctx->f0.u32l;
    // 0x8007ED84: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8007ED88: lwc1        $f0, -0x2770($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X2770);
    // 0x8007ED8C: lw          $v0, 0xC04($v0)
    ctx->r2 = MEM_W(ctx->r2, 0XC04);
    // 0x8007ED90: add.s       $f6, $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f0.fl;
    // 0x8007ED94: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8007ED98: lwc1        $f0, -0x276C($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X276C);
    // 0x8007ED9C: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8007EDA0: lwc1        $f2, -0x2768($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X2768);
    // 0x8007EDA4: mul.s       $f26, $f6, $f0
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f26.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x8007EDA8: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8007EDAC: lwc1        $f0, -0x2764($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X2764);
    // 0x8007EDB0: sw          $zero, 0x70($sp)
    MEM_W(0X70, ctx->r29) = 0;
    // 0x8007EDB4: swc1        $f4, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->f4.u32l;
    // 0x8007EDB8: sw          $zero, 0x78($sp)
    MEM_W(0X78, ctx->r29) = 0;
    // 0x8007EDBC: sw          $zero, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = 0;
    // 0x8007EDC0: sw          $zero, 0x80($sp)
    MEM_W(0X80, ctx->r29) = 0;
    // 0x8007EDC4: sw          $zero, 0x84($sp)
    MEM_W(0X84, ctx->r29) = 0;
    // 0x8007EDC8: sw          $zero, 0x90($sp)
    MEM_W(0X90, ctx->r29) = 0;
    // 0x8007EDCC: sw          $zero, 0x94($sp)
    MEM_W(0X94, ctx->r29) = 0;
    // 0x8007EDD0: swc1        $f8, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->f8.u32l;
    // 0x8007EDD4: sh          $zero, 0x9C($sp)
    MEM_H(0X9C, ctx->r29) = 0;
    // 0x8007EDD8: sh          $zero, 0x9E($sp)
    MEM_H(0X9E, ctx->r29) = 0;
    // 0x8007EDDC: swc1        $f10, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->f10.u32l;
    // 0x8007EDE0: sw          $zero, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = 0;
    // 0x8007EDE4: sw          $zero, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = 0;
    // 0x8007EDE8: sw          $zero, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = 0;
    // 0x8007EDEC: swc1        $f8, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->f8.u32l;
    // 0x8007EDF0: sw          $zero, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = 0;
    // 0x8007EDF4: mul.s       $f0, $f26, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = MUL_S(ctx->f26.fl, ctx->f0.fl);
    // 0x8007EDF8: sb          $v1, 0xCC($sp)
    MEM_B(0XCC, ctx->r29) = ctx->r3;
    // 0x8007EDFC: sw          $v0, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->r2;
    // 0x8007EE00: addiu       $v0, $zero, 0x10
    ctx->r2 = ADD32(0, 0X10);
    // 0x8007EE04: c.le.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl <= ctx->f0.fl;
    // 0x8007EE08: nop

    // 0x8007EE0C: bc1t        L_8007EE24
    if (c1cs) {
        // 0x8007EE10: sb          $v0, 0xCD($sp)
        MEM_B(0XCD, ctx->r29) = ctx->r2;
            goto L_8007EE24;
    }
    // 0x8007EE10: sb          $v0, 0xCD($sp)
    MEM_B(0XCD, ctx->r29) = ctx->r2;
    // 0x8007EE14: trunc.w.s   $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    ctx->f16.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x8007EE18: mfc1        $v1, $f16
    ctx->r3 = (int32_t)ctx->f16.u32l;
    // 0x8007EE1C: j           L_8007EE38
    // 0x8007EE20: nop

        goto L_8007EE38;
    // 0x8007EE20: nop

L_8007EE24:
    // 0x8007EE24: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x8007EE28: lui         $v0, 0x8000
    ctx->r2 = S32(0X8000 << 16);
    // 0x8007EE2C: trunc.w.s   $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    ctx->f16.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x8007EE30: mfc1        $v1, $f16
    ctx->r3 = (int32_t)ctx->f16.u32l;
    // 0x8007EE34: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
L_8007EE38:
    // 0x8007EE38: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8007EE3C: lwc1        $f0, -0x2760($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X2760);
    // 0x8007EE40: mul.s       $f0, $f12, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = MUL_S(ctx->f12.fl, ctx->f0.fl);
    // 0x8007EE44: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8007EE48: lwc1        $f2, -0x275C($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X275C);
    // 0x8007EE4C: c.le.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl <= ctx->f0.fl;
    // 0x8007EE50: nop

    // 0x8007EE54: bc1t        L_8007EE6C
    if (c1cs) {
        // 0x8007EE58: sh          $v1, 0xD0($sp)
        MEM_H(0XD0, ctx->r29) = ctx->r3;
            goto L_8007EE6C;
    }
    // 0x8007EE58: sh          $v1, 0xD0($sp)
    MEM_H(0XD0, ctx->r29) = ctx->r3;
    // 0x8007EE5C: trunc.w.s   $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    ctx->f16.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x8007EE60: mfc1        $v1, $f16
    ctx->r3 = (int32_t)ctx->f16.u32l;
    // 0x8007EE64: j           L_8007EE80
    // 0x8007EE68: nop

        goto L_8007EE80;
    // 0x8007EE68: nop

L_8007EE6C:
    // 0x8007EE6C: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x8007EE70: lui         $v0, 0x8000
    ctx->r2 = S32(0X8000 << 16);
    // 0x8007EE74: trunc.w.s   $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    ctx->f16.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x8007EE78: mfc1        $v1, $f16
    ctx->r3 = (int32_t)ctx->f16.u32l;
    // 0x8007EE7C: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
L_8007EE80:
    // 0x8007EE80: lwc1        $f0, 0xA0($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0XA0);
    // 0x8007EE84: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8007EE88: lwc1        $f2, -0x2758($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X2758);
    // 0x8007EE8C: c.le.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl <= ctx->f0.fl;
    // 0x8007EE90: nop

    // 0x8007EE94: bc1t        L_8007EEAC
    if (c1cs) {
        // 0x8007EE98: sh          $v1, 0xD2($sp)
        MEM_H(0XD2, ctx->r29) = ctx->r3;
            goto L_8007EEAC;
    }
    // 0x8007EE98: sh          $v1, 0xD2($sp)
    MEM_H(0XD2, ctx->r29) = ctx->r3;
    // 0x8007EE9C: trunc.w.s   $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    ctx->f16.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x8007EEA0: mfc1        $v1, $f16
    ctx->r3 = (int32_t)ctx->f16.u32l;
    // 0x8007EEA4: j           L_8007EEC4
    // 0x8007EEA8: addiu       $a0, $sp, 0x60
    ctx->r4 = ADD32(ctx->r29, 0X60);
        goto L_8007EEC4;
    // 0x8007EEA8: addiu       $a0, $sp, 0x60
    ctx->r4 = ADD32(ctx->r29, 0X60);
L_8007EEAC:
    // 0x8007EEAC: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x8007EEB0: lui         $v0, 0x8000
    ctx->r2 = S32(0X8000 << 16);
    // 0x8007EEB4: trunc.w.s   $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    ctx->f16.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x8007EEB8: mfc1        $v1, $f16
    ctx->r3 = (int32_t)ctx->f16.u32l;
    // 0x8007EEBC: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x8007EEC0: addiu       $a0, $sp, 0x60
    ctx->r4 = ADD32(ctx->r29, 0X60);
L_8007EEC4:
    // 0x8007EEC4: lui         $v0, 0x900
    ctx->r2 = S32(0X900 << 16);
    // 0x8007EEC8: sw          $v0, 0xD8($sp)
    MEM_W(0XD8, ctx->r29) = ctx->r2;
    // 0x8007EECC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8007EED0: sh          $v1, 0xD4($sp)
    MEM_H(0XD4, ctx->r29) = ctx->r3;
    // 0x8007EED4: jal         0x80041CBC
    // 0x8007EED8: sh          $v0, 0xDC($sp)
    MEM_H(0XDC, ctx->r29) = ctx->r2;
    func_80041CBC(rdram, ctx);
        goto after_9;
    // 0x8007EED8: sh          $v0, 0xDC($sp)
    MEM_H(0XDC, ctx->r29) = ctx->r2;
    after_9:
    // 0x8007EEDC: andi        $s0, $v0, 0xFFFF
    ctx->r16 = ctx->r2 & 0XFFFF;
    // 0x8007EEE0: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x8007EEE4: jal         0x80041D08
    // 0x8007EEE8: addiu       $a1, $s1, 0x270
    ctx->r5 = ADD32(ctx->r17, 0X270);
    func_80041D08(rdram, ctx);
        goto after_10;
    // 0x8007EEE8: addiu       $a1, $s1, 0x270
    ctx->r5 = ADD32(ctx->r17, 0X270);
    after_10:
    // 0x8007EEEC: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x8007EEF0: jal         0x80041D08
    // 0x8007EEF4: addiu       $a1, $s1, 0x294
    ctx->r5 = ADD32(ctx->r17, 0X294);
    func_80041D08(rdram, ctx);
        goto after_11;
    // 0x8007EEF4: addiu       $a1, $s1, 0x294
    ctx->r5 = ADD32(ctx->r17, 0X294);
    after_11:
L_8007EEF8:
    // 0x8007EEF8: lw          $ra, 0xE8($sp)
    ctx->r31 = MEM_W(ctx->r29, 0XE8);
    // 0x8007EEFC: lw          $s1, 0xE4($sp)
    ctx->r17 = MEM_W(ctx->r29, 0XE4);
    // 0x8007EF00: lw          $s0, 0xE0($sp)
    ctx->r16 = MEM_W(ctx->r29, 0XE0);
    // 0x8007EF04: ldc1        $f26, 0x108($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X108);
    // 0x8007EF08: ldc1        $f24, 0x100($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X100);
    // 0x8007EF0C: ldc1        $f22, 0xF8($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0XF8);
    // 0x8007EF10: ldc1        $f20, 0xF0($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0XF0);
    // 0x8007EF14: jr          $ra
    // 0x8007EF18: addiu       $sp, $sp, 0x110
    ctx->r29 = ADD32(ctx->r29, 0X110);
    return;
    // 0x8007EF18: addiu       $sp, $sp, 0x110
    ctx->r29 = ADD32(ctx->r29, 0X110);
;}
RECOMP_FUNC void npcWordDevastatorUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007EF1C: addiu       $sp, $sp, -0x148
    ctx->r29 = ADD32(ctx->r29, -0X148);
    // 0x8007EF20: sw          $s7, 0x114($sp)
    MEM_W(0X114, ctx->r29) = ctx->r23;
    // 0x8007EF24: addu        $s7, $a0, $zero
    ctx->r23 = ADD32(ctx->r4, 0);
    // 0x8007EF28: sw          $s4, 0x108($sp)
    MEM_W(0X108, ctx->r29) = ctx->r20;
    // 0x8007EF2C: andi        $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 & 0XFFFF;
    // 0x8007EF30: addiu       $v1, $a1, -0x1
    ctx->r3 = ADD32(ctx->r5, -0X1);
    // 0x8007EF34: sltiu       $v0, $v1, 0xF
    ctx->r2 = ctx->r3 < 0XF ? 1 : 0;
    // 0x8007EF38: sw          $ra, 0x11C($sp)
    MEM_W(0X11C, ctx->r29) = ctx->r31;
    // 0x8007EF3C: sw          $fp, 0x118($sp)
    MEM_W(0X118, ctx->r29) = ctx->r30;
    // 0x8007EF40: sw          $s6, 0x110($sp)
    MEM_W(0X110, ctx->r29) = ctx->r22;
    // 0x8007EF44: sw          $s5, 0x10C($sp)
    MEM_W(0X10C, ctx->r29) = ctx->r21;
    // 0x8007EF48: sw          $s3, 0x104($sp)
    MEM_W(0X104, ctx->r29) = ctx->r19;
    // 0x8007EF4C: sw          $s2, 0x100($sp)
    MEM_W(0X100, ctx->r29) = ctx->r18;
    // 0x8007EF50: sw          $s1, 0xFC($sp)
    MEM_W(0XFC, ctx->r29) = ctx->r17;
    // 0x8007EF54: sw          $s0, 0xF8($sp)
    MEM_W(0XF8, ctx->r29) = ctx->r16;
    // 0x8007EF58: sdc1        $f28, 0x140($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0X140, ctx->r29);
    // 0x8007EF5C: sdc1        $f26, 0x138($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X138, ctx->r29);
    // 0x8007EF60: sdc1        $f24, 0x130($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X130, ctx->r29);
    // 0x8007EF64: sdc1        $f22, 0x128($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X128, ctx->r29);
    // 0x8007EF68: sdc1        $f20, 0x120($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X120, ctx->r29);
    // 0x8007EF6C: lw          $s3, 0x4($s7)
    ctx->r19 = MEM_W(ctx->r23, 0X4);
    // 0x8007EF70: beq         $v0, $zero, L_80080078
    if (ctx->r2 == 0) {
        // 0x8007EF74: addu        $s4, $a2, $zero
        ctx->r20 = ADD32(ctx->r6, 0);
            goto L_80080078;
    }
    // 0x8007EF74: addu        $s4, $a2, $zero
    ctx->r20 = ADD32(ctx->r6, 0);
    // 0x8007EF78: lui         $v0, 0x8004
    ctx->r2 = S32(0X8004 << 16);
    // 0x8007EF7C: addiu       $v0, $v0, -0x2738
    ctx->r2 = ADD32(ctx->r2, -0X2738);
    // 0x8007EF80: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x8007EF84: addu        $v1, $v1, $v0
    gpr jr_addend_8007EF8C = ctx->r3;
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x8007EF88: lw          $v0, 0x0($v1)
    ctx->r2 = ADD32(ctx->r3, 0X0);
    // 0x8007EF8C: jr          $v0
    // 0x8007EF90: nop

    switch (jr_addend_8007EF8C >> 2) {
        case 0: goto L_8007EF94; break;
        case 1: goto L_8007F32C; break;
        case 2: goto L_8007F444; break;
        case 3: goto L_8007F908; break;
        case 4: goto L_8007F9E4; break;
        case 5: goto L_80080078; break;
        case 6: goto L_8008006C; break;
        case 7: goto L_80080078; break;
        case 8: goto L_8007FEF8; break;
        case 9: goto L_80080078; break;
        case 10: goto L_80080078; break;
        case 11: goto L_80080078; break;
        case 12: goto L_80080078; break;
        case 13: goto L_80080078; break;
        case 14: goto L_8007FC5C; break;
        default: switch_error(__func__, 0x8007EF8C, 0x8003D8C8);
    }
    // 0x8007EF90: nop

L_8007EF94:
    // 0x8007EF94: addiu       $a0, $zero, 0x2F4
    ctx->r4 = ADD32(0, 0X2F4);
    // 0x8007EF98: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x8007EF9C: jal         0x80001ACC
    // 0x8007EFA0: addu        $s2, $s4, $zero
    ctx->r18 = ADD32(ctx->r20, 0);
    rs_malloc(rdram, ctx);
        goto after_0;
    // 0x8007EFA0: addu        $s2, $s4, $zero
    ctx->r18 = ADD32(ctx->r20, 0);
    after_0:
    // 0x8007EFA4: addu        $s3, $v0, $zero
    ctx->r19 = ADD32(ctx->r2, 0);
    // 0x8007EFA8: lui         $a0, 0x8004
    ctx->r4 = S32(0X8004 << 16);
    // 0x8007EFAC: lhu         $v0, 0x14($s7)
    ctx->r2 = MEM_HU(ctx->r23, 0X14);
    // 0x8007EFB0: addiu       $a0, $a0, -0x2754
    ctx->r4 = ADD32(ctx->r4, -0X2754);
    // 0x8007EFB4: sw          $s3, 0x4($s7)
    MEM_W(0X4, ctx->r23) = ctx->r19;
    // 0x8007EFB8: ori         $v0, $v0, 0x100
    ctx->r2 = ctx->r2 | 0X100;
    // 0x8007EFBC: sh          $v0, 0x14($s7)
    MEM_H(0X14, ctx->r23) = ctx->r2;
    // 0x8007EFC0: jal         0x80056EB0
    // 0x8007EFC4: sw          $s4, 0x34($s3)
    MEM_W(0X34, ctx->r19) = ctx->r20;
    walkMeshdef0List(rdram, ctx);
        goto after_1;
    // 0x8007EFC4: sw          $s4, 0x34($s3)
    MEM_W(0X34, ctx->r19) = ctx->r20;
    after_1:
    // 0x8007EFC8: lui         $t0, 0x8014
    ctx->r8 = S32(0X8014 << 16);
    // 0x8007EFCC: lbu         $v1, -0x5680($t0)
    ctx->r3 = MEM_BU(ctx->r8, -0X5680);
    // 0x8007EFD0: bne         $v1, $zero, L_8007F054
    if (ctx->r3 != 0) {
        // 0x8007EFD4: sw          $v0, 0x30($s3)
        MEM_W(0X30, ctx->r19) = ctx->r2;
            goto L_8007F054;
    }
    // 0x8007EFD4: sw          $v0, 0x30($s3)
    MEM_W(0X30, ctx->r19) = ctx->r2;
    // 0x8007EFD8: lui         $s0, 0x8004
    ctx->r16 = S32(0X8004 << 16);
    // 0x8007EFDC: addiu       $s0, $s0, -0x2748
    ctx->r16 = ADD32(ctx->r16, -0X2748);
    // 0x8007EFE0: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x8007EFE4: addiu       $a1, $zero, 0x80
    ctx->r5 = ADD32(0, 0X80);
    // 0x8007EFE8: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    // 0x8007EFEC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8007EFF0: lui         $a3, 0x4120
    ctx->r7 = S32(0X4120 << 16);
    // 0x8007EFF4: addiu       $s1, $zero, 0x1
    ctx->r17 = ADD32(0, 0X1);
    // 0x8007EFF8: sb          $v0, -0x5680($t0)
    MEM_B(-0X5680, ctx->r8) = ctx->r2;
    // 0x8007EFFC: jal         0x80054C7C
    // 0x8007F000: sw          $s1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r17;
    func_80054C7C(rdram, ctx);
        goto after_2;
    // 0x8007F000: sw          $s1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r17;
    after_2:
    // 0x8007F004: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x8007F008: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8007F00C: lwc1        $f20, -0x26FC($at)
    ctx->f20.u32l = MEM_W(ctx->r1, -0X26FC);
    // 0x8007F010: addiu       $a1, $zero, 0x90
    ctx->r5 = ADD32(0, 0X90);
    // 0x8007F014: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x8007F018: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    // 0x8007F01C: jal         0x80054C7C
    // 0x8007F020: sw          $s1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r17;
    func_80054C7C(rdram, ctx);
        goto after_3;
    // 0x8007F020: sw          $s1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r17;
    after_3:
    // 0x8007F024: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x8007F028: addiu       $a1, $zero, 0xA0
    ctx->r5 = ADD32(0, 0XA0);
    // 0x8007F02C: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x8007F030: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    // 0x8007F034: jal         0x80054C7C
    // 0x8007F038: sw          $s1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r17;
    func_80054C7C(rdram, ctx);
        goto after_4;
    // 0x8007F038: sw          $s1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r17;
    after_4:
    // 0x8007F03C: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x8007F040: addiu       $a1, $zero, 0xB0
    ctx->r5 = ADD32(0, 0XB0);
    // 0x8007F044: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x8007F048: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    // 0x8007F04C: jal         0x80054C7C
    // 0x8007F050: sw          $s1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r17;
    func_80054C7C(rdram, ctx);
        goto after_5;
    // 0x8007F050: sw          $s1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r17;
    after_5:
L_8007F054:
    // 0x8007F054: lwc1        $f0, 0x10($s4)
    ctx->f0.u32l = MEM_W(ctx->r20, 0X10);
    // 0x8007F058: swc1        $f0, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->f0.u32l;
    // 0x8007F05C: lwc1        $f0, 0x14($s4)
    ctx->f0.u32l = MEM_W(ctx->r20, 0X14);
    // 0x8007F060: swc1        $f0, 0x4($s3)
    MEM_W(0X4, ctx->r19) = ctx->f0.u32l;
    // 0x8007F064: lwc1        $f0, 0x18($s4)
    ctx->f0.u32l = MEM_W(ctx->r20, 0X18);
    // 0x8007F068: swc1        $f0, 0x8($s3)
    MEM_W(0X8, ctx->r19) = ctx->f0.u32l;
    // 0x8007F06C: lw          $a1, 0x1C($s4)
    ctx->r5 = MEM_W(ctx->r20, 0X1C);
    // 0x8007F070: lw          $a2, 0x20($s4)
    ctx->r6 = MEM_W(ctx->r20, 0X20);
    // 0x8007F074: lw          $a3, 0x24($s4)
    ctx->r7 = MEM_W(ctx->r20, 0X24);
    // 0x8007F078: jal         0x80059D78
    // 0x8007F07C: addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    func_80059D78(rdram, ctx);
        goto after_6;
    // 0x8007F07C: addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    after_6:
    // 0x8007F080: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8007F084: lw          $v0, 0x30($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X30);
    // 0x8007F088: swc1        $f0, 0x2C($s3)
    MEM_W(0X2C, ctx->r19) = ctx->f0.u32l;
    // 0x8007F08C: swc1        $f0, 0x28($s3)
    MEM_W(0X28, ctx->r19) = ctx->f0.u32l;
    // 0x8007F090: swc1        $f0, 0x24($s3)
    MEM_W(0X24, ctx->r19) = ctx->f0.u32l;
    // 0x8007F094: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x8007F098: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8007F09C: lwc1        $f2, -0x26F8($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X26F8);
    // 0x8007F0A0: lwc1        $f4, 0x34($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X34);
    // 0x8007F0A4: lwc1        $f0, 0x28($s4)
    ctx->f0.u32l = MEM_W(ctx->r20, 0X28);
    // 0x8007F0A8: div.s       $f2, $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = DIV_S(ctx->f2.fl, ctx->f4.fl);
    // 0x8007F0AC: mul.s       $f0, $f2, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x8007F0B0: swc1        $f0, 0x40($s3)
    MEM_W(0X40, ctx->r19) = ctx->f0.u32l;
    // 0x8007F0B4: lwc1        $f0, 0x28($s4)
    ctx->f0.u32l = MEM_W(ctx->r20, 0X28);
    // 0x8007F0B8: mul.s       $f0, $f2, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x8007F0BC: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8007F0C0: lwc1        $f0, 0x2C($s4)
    ctx->f0.u32l = MEM_W(ctx->r20, 0X2C);
    // 0x8007F0C4: mul.s       $f0, $f2, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x8007F0C8: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8007F0CC: lwc1        $f0, 0x30($s4)
    ctx->f0.u32l = MEM_W(ctx->r20, 0X30);
    // 0x8007F0D0: mul.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x8007F0D4: lw          $a0, 0x30($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X30);
    // 0x8007F0D8: mfc1        $a3, $f2
    ctx->r7 = (int32_t)ctx->f2.u32l;
    // 0x8007F0DC: jal         0x8001CB64
    // 0x8007F0E0: addiu       $a0, $a0, 0x28
    ctx->r4 = ADD32(ctx->r4, 0X28);
    func_8001CB64(rdram, ctx);
        goto after_7;
    // 0x8007F0E0: addiu       $a0, $a0, 0x28
    ctx->r4 = ADD32(ctx->r4, 0X28);
    after_7:
    // 0x8007F0E4: lw          $a0, 0x30($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X30);
    // 0x8007F0E8: lw          $a1, 0x1C($s4)
    ctx->r5 = MEM_W(ctx->r20, 0X1C);
    // 0x8007F0EC: jal         0x8001CB9C
    // 0x8007F0F0: addiu       $a0, $a0, 0x28
    ctx->r4 = ADD32(ctx->r4, 0X28);
    func_8001CB9C(rdram, ctx);
        goto after_8;
    // 0x8007F0F0: addiu       $a0, $a0, 0x28
    ctx->r4 = ADD32(ctx->r4, 0X28);
    after_8:
    // 0x8007F0F4: lw          $a0, 0x30($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X30);
    // 0x8007F0F8: lw          $a1, 0x20($s4)
    ctx->r5 = MEM_W(ctx->r20, 0X20);
    // 0x8007F0FC: jal         0x8001CCCC
    // 0x8007F100: addiu       $a0, $a0, 0x28
    ctx->r4 = ADD32(ctx->r4, 0X28);
    func_8001CCCC(rdram, ctx);
        goto after_9;
    // 0x8007F100: addiu       $a0, $a0, 0x28
    ctx->r4 = ADD32(ctx->r4, 0X28);
    after_9:
    // 0x8007F104: lw          $a0, 0x30($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X30);
    // 0x8007F108: lw          $a1, 0x24($s4)
    ctx->r5 = MEM_W(ctx->r20, 0X24);
    // 0x8007F10C: jal         0x8001CDFC
    // 0x8007F110: addiu       $a0, $a0, 0x28
    ctx->r4 = ADD32(ctx->r4, 0X28);
    func_8001CDFC(rdram, ctx);
        goto after_10;
    // 0x8007F110: addiu       $a0, $a0, 0x28
    ctx->r4 = ADD32(ctx->r4, 0X28);
    after_10:
    // 0x8007F114: lw          $a1, 0x0($s3)
    ctx->r5 = MEM_W(ctx->r19, 0X0);
    // 0x8007F118: lw          $a2, 0x4($s3)
    ctx->r6 = MEM_W(ctx->r19, 0X4);
    // 0x8007F11C: lw          $a0, 0x30($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X30);
    // 0x8007F120: lw          $a3, 0x8($s3)
    ctx->r7 = MEM_W(ctx->r19, 0X8);
    // 0x8007F124: jal         0x8001CA90
    // 0x8007F128: addiu       $a0, $a0, 0x28
    ctx->r4 = ADD32(ctx->r4, 0X28);
    func_8001CA90(rdram, ctx);
        goto after_11;
    // 0x8007F128: addiu       $a0, $a0, 0x28
    ctx->r4 = ADD32(ctx->r4, 0X28);
    after_11:
    // 0x8007F12C: sw          $s3, 0x8($s7)
    MEM_W(0X8, ctx->r23) = ctx->r19;
    // 0x8007F130: lw          $v0, 0x30($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X30);
    // 0x8007F134: sw          $v0, 0xC($s7)
    MEM_W(0XC, ctx->r23) = ctx->r2;
    // 0x8007F138: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x8007F13C: addiu       $s0, $v0, -0x6AA0
    ctx->r16 = ADD32(ctx->r2, -0X6AA0);
    // 0x8007F140: lhu         $a0, 0x1C($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X1C);
    // 0x8007F144: jal         0x8003E684
    // 0x8007F148: addu        $a1, $s7, $zero
    ctx->r5 = ADD32(ctx->r23, 0);
    func_8003E684(rdram, ctx);
        goto after_12;
    // 0x8007F148: addu        $a1, $s7, $zero
    ctx->r5 = ADD32(ctx->r23, 0);
    after_12:
    // 0x8007F14C: sh          $v0, 0x4C($s3)
    MEM_H(0X4C, ctx->r19) = ctx->r2;
    // 0x8007F150: lw          $v0, 0xB4($s4)
    ctx->r2 = MEM_W(ctx->r20, 0XB4);
    // 0x8007F154: addiu       $s1, $zero, 0x1
    ctx->r17 = ADD32(0, 0X1);
    // 0x8007F158: bne         $v0, $s1, L_8007F164
    if (ctx->r2 != ctx->r17) {
        // 0x8007F15C: addiu       $v1, $zero, 0x30
        ctx->r3 = ADD32(0, 0X30);
            goto L_8007F164;
    }
    // 0x8007F15C: addiu       $v1, $zero, 0x30
    ctx->r3 = ADD32(0, 0X30);
    // 0x8007F160: addiu       $v1, $zero, 0x32
    ctx->r3 = ADD32(0, 0X32);
L_8007F164:
    // 0x8007F164: addu        $v0, $v1, $s0
    ctx->r2 = ADD32(ctx->r3, ctx->r16);
    // 0x8007F168: lhu         $a0, 0x0($v0)
    ctx->r4 = MEM_HU(ctx->r2, 0X0);
    // 0x8007F16C: jal         0x8003E684
    // 0x8007F170: addu        $a1, $s7, $zero
    ctx->r5 = ADD32(ctx->r23, 0);
    func_8003E684(rdram, ctx);
        goto after_13;
    // 0x8007F170: addu        $a1, $s7, $zero
    ctx->r5 = ADD32(ctx->r23, 0);
    after_13:
    // 0x8007F174: sh          $v0, 0x4E($s3)
    MEM_H(0X4E, ctx->r19) = ctx->r2;
    // 0x8007F178: lhu         $a0, 0xA($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0XA);
    // 0x8007F17C: jal         0x8003E684
    // 0x8007F180: addu        $a1, $s7, $zero
    ctx->r5 = ADD32(ctx->r23, 0);
    func_8003E684(rdram, ctx);
        goto after_14;
    // 0x8007F180: addu        $a1, $s7, $zero
    ctx->r5 = ADD32(ctx->r23, 0);
    after_14:
    // 0x8007F184: sh          $v0, 0x50($s3)
    MEM_H(0X50, ctx->r19) = ctx->r2;
    // 0x8007F188: lw          $v0, 0xB8($s4)
    ctx->r2 = MEM_W(ctx->r20, 0XB8);
    // 0x8007F18C: beq         $v0, $zero, L_8007F1BC
    if (ctx->r2 == 0) {
        // 0x8007F190: ori         $v0, $zero, 0xFFFF
        ctx->r2 = 0 | 0XFFFF;
            goto L_8007F1BC;
    }
    // 0x8007F190: ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
    // 0x8007F194: lw          $v0, 0xB4($s4)
    ctx->r2 = MEM_W(ctx->r20, 0XB4);
    // 0x8007F198: bne         $v0, $s1, L_8007F1A4
    if (ctx->r2 != ctx->r17) {
        // 0x8007F19C: addiu       $v1, $zero, 0x18
        ctx->r3 = ADD32(0, 0X18);
            goto L_8007F1A4;
    }
    // 0x8007F19C: addiu       $v1, $zero, 0x18
    ctx->r3 = ADD32(0, 0X18);
    // 0x8007F1A0: addiu       $v1, $zero, 0x1A
    ctx->r3 = ADD32(0, 0X1A);
L_8007F1A4:
    // 0x8007F1A4: addu        $v0, $v1, $s0
    ctx->r2 = ADD32(ctx->r3, ctx->r16);
    // 0x8007F1A8: lhu         $a0, 0x0($v0)
    ctx->r4 = MEM_HU(ctx->r2, 0X0);
    // 0x8007F1AC: jal         0x8003E684
    // 0x8007F1B0: addu        $a1, $s7, $zero
    ctx->r5 = ADD32(ctx->r23, 0);
    func_8003E684(rdram, ctx);
        goto after_15;
    // 0x8007F1B0: addu        $a1, $s7, $zero
    ctx->r5 = ADD32(ctx->r23, 0);
    after_15:
    // 0x8007F1B4: j           L_8007F1C0
    // 0x8007F1B8: sh          $v0, 0x52($s3)
    MEM_H(0X52, ctx->r19) = ctx->r2;
        goto L_8007F1C0;
    // 0x8007F1B8: sh          $v0, 0x52($s3)
    MEM_H(0X52, ctx->r19) = ctx->r2;
L_8007F1BC:
    // 0x8007F1BC: sh          $v0, 0x52($s3)
    MEM_H(0X52, ctx->r19) = ctx->r2;
L_8007F1C0:
    // 0x8007F1C0: lw          $v0, 0x30($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X30);
    // 0x8007F1C4: addiu       $a0, $s3, 0x38
    ctx->r4 = ADD32(ctx->r19, 0X38);
    // 0x8007F1C8: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x8007F1CC: lwc1        $f2, 0x40($s3)
    ctx->f2.u32l = MEM_W(ctx->r19, 0X40);
    // 0x8007F1D0: lwc1        $f0, 0x44($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X44);
    // 0x8007F1D4: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x8007F1D8: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x8007F1DC: addu        $a2, $s7, $zero
    ctx->r6 = ADD32(ctx->r23, 0);
    // 0x8007F1E0: lui         $a3, 0x8008
    ctx->r7 = S32(0X8008 << 16);
    // 0x8007F1E4: addiu       $a3, $a3, 0x20F0
    ctx->r7 = ADD32(ctx->r7, 0X20F0);
    // 0x8007F1E8: sw          $zero, 0x124($s3)
    MEM_W(0X124, ctx->r19) = 0;
    // 0x8007F1EC: swc1        $f0, 0x3C($s3)
    MEM_W(0X3C, ctx->r19) = ctx->f0.u32l;
    // 0x8007F1F0: jal         0x800EC588
    // 0x8007F1F4: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    func_800EC588(rdram, ctx);
        goto after_16;
    // 0x8007F1F4: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_16:
    // 0x8007F1F8: jal         0x8007D1BC
    // 0x8007F1FC: addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    func_8007D1BC(rdram, ctx);
        goto after_17;
    // 0x8007F1FC: addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    after_17:
    // 0x8007F200: addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    // 0x8007F204: jal         0x8007D470
    // 0x8007F208: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    func_8007D470(rdram, ctx);
        goto after_18;
    // 0x8007F208: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    after_18:
    // 0x8007F20C: lw          $v0, 0x8C($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X8C);
    // 0x8007F210: addu        $a0, $v0, $s2
    ctx->r4 = ADD32(ctx->r2, ctx->r18);
    // 0x8007F214: lbu         $v1, 0x0($a0)
    ctx->r3 = MEM_BU(ctx->r4, 0X0);
    // 0x8007F218: addiu       $v0, $zero, 0x2D
    ctx->r2 = ADD32(0, 0X2D);
    // 0x8007F21C: beql        $v1, $v0, L_8007F284
    if (ctx->r3 == ctx->r2) {
        // 0x8007F220: addiu       $a0, $s3, 0x128
        ctx->r4 = ADD32(ctx->r19, 0X128);
            goto L_8007F284;
    }
    goto skip_0;
    // 0x8007F220: addiu       $a0, $s3, 0x128
    ctx->r4 = ADD32(ctx->r19, 0X128);
    skip_0:
    // 0x8007F224: jal         0x80047B48
    // 0x8007F228: nop

    getLevelDatItemByName(rdram, ctx);
        goto after_19;
    // 0x8007F228: nop

    after_19:
    // 0x8007F22C: lw          $a1, 0x34($s3)
    ctx->r5 = MEM_W(ctx->r19, 0X34);
    // 0x8007F230: lwc1        $f0, 0x94($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0X94);
    // 0x8007F234: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    // 0x8007F238: lw          $v1, 0x34($s3)
    ctx->r3 = MEM_W(ctx->r19, 0X34);
    // 0x8007F23C: lwc1        $f0, 0x98($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X98);
    // 0x8007F240: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x8007F244: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    // 0x8007F248: lw          $a0, 0x38($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X38);
    // 0x8007F24C: lw          $a2, 0x90($a1)
    ctx->r6 = MEM_W(ctx->r5, 0X90);
    // 0x8007F250: lw          $a3, 0x9C($a1)
    ctx->r7 = MEM_W(ctx->r5, 0X9C);
    // 0x8007F254: jal         0x800F947C
    // 0x8007F258: addu        $a1, $v0, $zero
    ctx->r5 = ADD32(ctx->r2, 0);
    func_800F947C(rdram, ctx);
        goto after_20;
    // 0x8007F258: addu        $a1, $v0, $zero
    ctx->r5 = ADD32(ctx->r2, 0);
    after_20:
    // 0x8007F25C: lw          $v0, 0x34($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X34);
    // 0x8007F260: lw          $a0, 0x38($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X38);
    // 0x8007F264: lw          $a1, 0xA0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0XA0);
    // 0x8007F268: jal         0x800F97F4
    // 0x8007F26C: nop

    func_800F97F4(rdram, ctx);
        goto after_21;
    // 0x8007F26C: nop

    after_21:
    // 0x8007F270: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x8007F274: lw          $a0, 0x38($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X38);
    // 0x8007F278: jal         0x800F9AF4
    // 0x8007F27C: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    func_800F9AF4(rdram, ctx);
        goto after_22;
    // 0x8007F27C: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    after_22:
    // 0x8007F280: addiu       $a0, $s3, 0x128
    ctx->r4 = ADD32(ctx->r19, 0X128);
L_8007F284:
    // 0x8007F284: addu        $a1, $s3, $zero
    ctx->r5 = ADD32(ctx->r19, 0);
    // 0x8007F288: addiu       $s2, $s3, 0x24
    ctx->r18 = ADD32(ctx->r19, 0X24);
    // 0x8007F28C: addu        $a2, $s2, $zero
    ctx->r6 = ADD32(ctx->r18, 0);
    // 0x8007F290: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8007F294: addiu       $s1, $zero, 0x7
    ctx->r17 = ADD32(0, 0X7);
    // 0x8007F298: sb          $v0, 0x1B0($s3)
    MEM_B(0X1B0, ctx->r19) = ctx->r2;
    // 0x8007F29C: addiu       $v0, $zero, 0x38
    ctx->r2 = ADD32(0, 0X38);
    // 0x8007F2A0: lui         $a3, 0x4208
    ctx->r7 = S32(0X4208 << 16);
    // 0x8007F2A4: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8007F2A8: lwc1        $f0, -0x26F4($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X26F4);
    // 0x8007F2AC: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
    // 0x8007F2B0: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // 0x8007F2B4: addiu       $v0, $zero, 0x7F
    ctx->r2 = ADD32(0, 0X7F);
    // 0x8007F2B8: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x8007F2BC: addiu       $v0, $zero, 0x50
    ctx->r2 = ADD32(0, 0X50);
    // 0x8007F2C0: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x8007F2C4: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x8007F2C8: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x8007F2CC: jal         0x80098BDC
    // 0x8007F2D0: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    func_80098BDC(rdram, ctx);
        goto after_23;
    // 0x8007F2D0: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    after_23:
    // 0x8007F2D4: addiu       $a0, $s3, 0x16C
    ctx->r4 = ADD32(ctx->r19, 0X16C);
    // 0x8007F2D8: addu        $a1, $s3, $zero
    ctx->r5 = ADD32(ctx->r19, 0);
    // 0x8007F2DC: addu        $a2, $s2, $zero
    ctx->r6 = ADD32(ctx->r18, 0);
    // 0x8007F2E0: lui         $a3, 0x4160
    ctx->r7 = S32(0X4160 << 16);
    // 0x8007F2E4: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8007F2E8: lwc1        $f0, -0x26F0($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X26F0);
    // 0x8007F2EC: addiu       $v0, $zero, 0x14
    ctx->r2 = ADD32(0, 0X14);
    // 0x8007F2F0: sb          $s0, 0x1B1($s3)
    MEM_B(0X1B1, ctx->r19) = ctx->r16;
    // 0x8007F2F4: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // 0x8007F2F8: addiu       $v0, $zero, 0x78
    ctx->r2 = ADD32(0, 0X78);
    // 0x8007F2FC: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x8007F300: addiu       $v0, $zero, 0x28
    ctx->r2 = ADD32(0, 0X28);
    // 0x8007F304: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x8007F308: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x8007F30C: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x8007F310: jal         0x80098BDC
    // 0x8007F314: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    func_80098BDC(rdram, ctx);
        goto after_24;
    // 0x8007F314: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    after_24:
    // 0x8007F318: lw          $a1, 0x30($s3)
    ctx->r5 = MEM_W(ctx->r19, 0X30);
    // 0x8007F31C: jal         0x80071308
    // 0x8007F320: addiu       $a0, $s3, 0x2BC
    ctx->r4 = ADD32(ctx->r19, 0X2BC);
    func_80071308(rdram, ctx);
        goto after_25;
    // 0x8007F320: addiu       $a0, $s3, 0x2BC
    ctx->r4 = ADD32(ctx->r19, 0X2BC);
    after_25:
    // 0x8007F324: j           L_8008007C
    // 0x8007F328: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8008007C;
    // 0x8007F328: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8007F32C:
    // 0x8007F32C: lh          $v0, 0x1B4($s3)
    ctx->r2 = MEM_H(ctx->r19, 0X1B4);
    // 0x8007F330: blez        $v0, L_8007F368
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8007F334: addu        $s1, $zero, $zero
        ctx->r17 = ADD32(0, 0);
            goto L_8007F368;
    }
    // 0x8007F334: addu        $s1, $zero, $zero
    ctx->r17 = ADD32(0, 0);
    // 0x8007F338: ori         $s2, $zero, 0xFFFF
    ctx->r18 = 0 | 0XFFFF;
    // 0x8007F33C: addu        $s0, $s3, $zero
    ctx->r16 = ADD32(ctx->r19, 0);
L_8007F340:
    // 0x8007F340: lhu         $v0, 0x1B6($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X1B6);
    // 0x8007F344: beq         $v0, $s2, L_8007F354
    if (ctx->r2 == ctx->r18) {
        // 0x8007F348: nop
    
            goto L_8007F354;
    }
    // 0x8007F348: nop

    // 0x8007F34C: jal         0x8003ED74
    // 0x8007F350: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    func_8003ED74(rdram, ctx);
        goto after_26;
    // 0x8007F350: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    after_26:
L_8007F354:
    // 0x8007F354: lh          $v0, 0x1B4($s3)
    ctx->r2 = MEM_H(ctx->r19, 0X1B4);
    // 0x8007F358: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x8007F35C: slt         $v0, $s1, $v0
    ctx->r2 = SIGNED(ctx->r17) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8007F360: bne         $v0, $zero, L_8007F340
    if (ctx->r2 != 0) {
        // 0x8007F364: addiu       $s0, $s0, 0x2
        ctx->r16 = ADD32(ctx->r16, 0X2);
            goto L_8007F340;
    }
    // 0x8007F364: addiu       $s0, $s0, 0x2
    ctx->r16 = ADD32(ctx->r16, 0X2);
L_8007F368:
    // 0x8007F368: addu        $s1, $zero, $zero
    ctx->r17 = ADD32(0, 0);
    // 0x8007F36C: ori         $s2, $zero, 0xFFFF
    ctx->r18 = 0 | 0XFFFF;
    // 0x8007F370: addu        $s0, $s3, $zero
    ctx->r16 = ADD32(ctx->r19, 0);
L_8007F374:
    // 0x8007F374: lhu         $v0, 0x10C($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X10C);
    // 0x8007F378: beq         $v0, $s2, L_8007F388
    if (ctx->r2 == ctx->r18) {
        // 0x8007F37C: nop
    
            goto L_8007F388;
    }
    // 0x8007F37C: nop

    // 0x8007F380: jal         0x8003ED74
    // 0x8007F384: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    func_8003ED74(rdram, ctx);
        goto after_27;
    // 0x8007F384: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    after_27:
L_8007F388:
    // 0x8007F388: lhu         $v0, 0xFC($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0XFC);
    // 0x8007F38C: beql        $v0, $s2, L_8007F3A0
    if (ctx->r2 == ctx->r18) {
        // 0x8007F390: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_8007F3A0;
    }
    goto skip_1;
    // 0x8007F390: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    skip_1:
    // 0x8007F394: jal         0x8003ED74
    // 0x8007F398: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    func_8003ED74(rdram, ctx);
        goto after_28;
    // 0x8007F398: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    after_28:
    // 0x8007F39C: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
L_8007F3A0:
    // 0x8007F3A0: slti        $v0, $s1, 0x4
    ctx->r2 = SIGNED(ctx->r17) < 0X4 ? 1 : 0;
    // 0x8007F3A4: bne         $v0, $zero, L_8007F374
    if (ctx->r2 != 0) {
        // 0x8007F3A8: addiu       $s0, $s0, 0x2
        ctx->r16 = ADD32(ctx->r16, 0X2);
            goto L_8007F374;
    }
    // 0x8007F3A8: addiu       $s0, $s0, 0x2
    ctx->r16 = ADD32(ctx->r16, 0X2);
    // 0x8007F3AC: lhu         $v1, 0x1F6($s3)
    ctx->r3 = MEM_HU(ctx->r19, 0X1F6);
    // 0x8007F3B0: ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
    // 0x8007F3B4: beq         $v1, $v0, L_8007F3C4
    if (ctx->r3 == ctx->r2) {
        // 0x8007F3B8: nop
    
            goto L_8007F3C4;
    }
    // 0x8007F3B8: nop

    // 0x8007F3BC: jal         0x8003ED74
    // 0x8007F3C0: addu        $a0, $v1, $zero
    ctx->r4 = ADD32(ctx->r3, 0);
    func_8003ED74(rdram, ctx);
        goto after_29;
    // 0x8007F3C0: addu        $a0, $v1, $zero
    ctx->r4 = ADD32(ctx->r3, 0);
    after_29:
L_8007F3C4:
    // 0x8007F3C4: lbu         $v0, 0x1B0($s3)
    ctx->r2 = MEM_BU(ctx->r19, 0X1B0);
    // 0x8007F3C8: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
    // 0x8007F3CC: bne         $v0, $s0, L_8007F3DC
    if (ctx->r2 != ctx->r16) {
        // 0x8007F3D0: nop
    
            goto L_8007F3DC;
    }
    // 0x8007F3D0: nop

    // 0x8007F3D4: jal         0x80098DE0
    // 0x8007F3D8: addiu       $a0, $s3, 0x128
    ctx->r4 = ADD32(ctx->r19, 0X128);
    func_80098DE0(rdram, ctx);
        goto after_30;
    // 0x8007F3D8: addiu       $a0, $s3, 0x128
    ctx->r4 = ADD32(ctx->r19, 0X128);
    after_30:
L_8007F3DC:
    // 0x8007F3DC: lbu         $v0, 0x1B1($s3)
    ctx->r2 = MEM_BU(ctx->r19, 0X1B1);
    // 0x8007F3E0: bne         $v0, $s0, L_8007F3F0
    if (ctx->r2 != ctx->r16) {
        // 0x8007F3E4: nop
    
            goto L_8007F3F0;
    }
    // 0x8007F3E4: nop

    // 0x8007F3E8: jal         0x80098DE0
    // 0x8007F3EC: addiu       $a0, $s3, 0x16C
    ctx->r4 = ADD32(ctx->r19, 0X16C);
    func_80098DE0(rdram, ctx);
        goto after_31;
    // 0x8007F3EC: addiu       $a0, $s3, 0x16C
    ctx->r4 = ADD32(ctx->r19, 0X16C);
    after_31:
L_8007F3F0:
    // 0x8007F3F0: lw          $a0, 0x38($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X38);
    // 0x8007F3F4: jal         0x800F20EC
    // 0x8007F3F8: nop

    getNpcCurrentHealth(rdram, ctx);
        goto after_32;
    // 0x8007F3F8: nop

    after_32:
    // 0x8007F3FC: lw          $v1, 0x34($s3)
    ctx->r3 = MEM_W(ctx->r19, 0X34);
    // 0x8007F400: slti        $a1, $v0, 0x1
    ctx->r5 = SIGNED(ctx->r2) < 0X1 ? 1 : 0;
    // 0x8007F404: addiu       $v1, $v1, 0x70
    ctx->r3 = ADD32(ctx->r3, 0X70);
    // 0x8007F408: sw          $v1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r3;
    // 0x8007F40C: lw          $a0, 0x38($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X38);
    // 0x8007F410: lw          $a2, 0x34($s3)
    ctx->r6 = MEM_W(ctx->r19, 0X34);
    // 0x8007F414: jal         0x800F1E7C
    // 0x8007F418: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    func_800F1E7C(rdram, ctx);
        goto after_33;
    // 0x8007F418: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    after_33:
    // 0x8007F41C: jal         0x800EC684
    // 0x8007F420: addiu       $a0, $s3, 0x38
    ctx->r4 = ADD32(ctx->r19, 0X38);
    func_800EC684(rdram, ctx);
        goto after_34;
    // 0x8007F420: addiu       $a0, $s3, 0x38
    ctx->r4 = ADD32(ctx->r19, 0X38);
    after_34:
    // 0x8007F424: lw          $a1, 0x30($s3)
    ctx->r5 = MEM_W(ctx->r19, 0X30);
    // 0x8007F428: jal         0x80072AF8
    // 0x8007F42C: addiu       $a0, $s3, 0x2BC
    ctx->r4 = ADD32(ctx->r19, 0X2BC);
    func_80072AF8(rdram, ctx);
        goto after_35;
    // 0x8007F42C: addiu       $a0, $s3, 0x2BC
    ctx->r4 = ADD32(ctx->r19, 0X2BC);
    after_35:
    // 0x8007F430: lw          $a0, 0x30($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X30);
    // 0x8007F434: jal         0x8005779C
    // 0x8007F438: nop

    func_8005779C(rdram, ctx);
        goto after_36;
    // 0x8007F438: nop

    after_36:
    // 0x8007F43C: j           L_8008007C
    // 0x8007F440: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8008007C;
    // 0x8007F440: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8007F444:
    // 0x8007F444: lh          $v1, 0x1B2($s3)
    ctx->r3 = MEM_H(ctx->r19, 0X1B2);
    // 0x8007F448: lwc1        $f20, 0x0($s4)
    ctx->f20.u32l = MEM_W(ctx->r20, 0X0);
    // 0x8007F44C: sltiu       $v0, $v1, 0x5
    ctx->r2 = ctx->r3 < 0X5 ? 1 : 0;
    // 0x8007F450: beq         $v0, $zero, L_8007F894
    if (ctx->r2 == 0) {
        // 0x8007F454: lui         $v0, 0x8004
        ctx->r2 = S32(0X8004 << 16);
            goto L_8007F894;
    }
    // 0x8007F454: lui         $v0, 0x8004
    ctx->r2 = S32(0X8004 << 16);
    // 0x8007F458: addiu       $v0, $v0, -0x26E8
    ctx->r2 = ADD32(ctx->r2, -0X26E8);
    // 0x8007F45C: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x8007F460: addu        $v1, $v1, $v0
    gpr jr_addend_8007F468 = ctx->r3;
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x8007F464: lw          $v0, 0x0($v1)
    ctx->r2 = ADD32(ctx->r3, 0X0);
    // 0x8007F468: jr          $v0
    // 0x8007F46C: nop

    switch (jr_addend_8007F468 >> 2) {
        case 0: goto L_8007F470; break;
        case 1: goto L_8007F478; break;
        case 2: goto L_8007F7A4; break;
        case 3: goto L_8007F7EC; break;
        case 4: goto L_8007F828; break;
        default: switch_error(__func__, 0x8007F468, 0x8003D918);
    }
    // 0x8007F46C: nop

L_8007F470:
    // 0x8007F470: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8007F474: sh          $v0, 0x1B2($s3)
    MEM_H(0X1B2, ctx->r19) = ctx->r2;
L_8007F478:
    // 0x8007F478: addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    // 0x8007F47C: lw          $a2, 0x34($s3)
    ctx->r6 = MEM_W(ctx->r19, 0X34);
    // 0x8007F480: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x8007F484: jal         0x800AA6D0
    // 0x8007F488: addiu       $a2, $a2, 0x34
    ctx->r6 = ADD32(ctx->r6, 0X34);
    func_800AA6D0(rdram, ctx);
        goto after_37;
    // 0x8007F488: addiu       $a2, $a2, 0x34
    ctx->r6 = ADD32(ctx->r6, 0X34);
    after_37:
    // 0x8007F48C: lw          $a0, 0x38($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X38);
    // 0x8007F490: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x8007F494: jal         0x800F9A14
    // 0x8007F498: nop

    func_800F9A14(rdram, ctx);
        goto after_38;
    // 0x8007F498: nop

    after_38:
    // 0x8007F49C: lw          $v0, 0x38($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X38);
    // 0x8007F4A0: lbu         $v0, 0x112($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X112);
    // 0x8007F4A4: bnel        $v0, $zero, L_8007F4C8
    if (ctx->r2 != 0) {
        // 0x8007F4A8: addiu       $v1, $s3, 0x1F8
        ctx->r3 = ADD32(ctx->r19, 0X1F8);
            goto L_8007F4C8;
    }
    goto skip_2;
    // 0x8007F4A8: addiu       $v1, $s3, 0x1F8
    ctx->r3 = ADD32(ctx->r19, 0X1F8);
    skip_2:
    // 0x8007F4AC: lw          $v0, 0x34($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X34);
    // 0x8007F4B0: lw          $a1, 0x1C($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X1C);
    // 0x8007F4B4: lw          $a2, 0x20($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X20);
    // 0x8007F4B8: lw          $a3, 0x24($v0)
    ctx->r7 = MEM_W(ctx->r2, 0X24);
    // 0x8007F4BC: jal         0x80059D78
    // 0x8007F4C0: addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    func_80059D78(rdram, ctx);
        goto after_39;
    // 0x8007F4C0: addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    after_39:
    // 0x8007F4C4: addiu       $v1, $s3, 0x1F8
    ctx->r3 = ADD32(ctx->r19, 0X1F8);
L_8007F4C8:
    // 0x8007F4C8: addu        $v0, $s3, $zero
    ctx->r2 = ADD32(ctx->r19, 0);
    // 0x8007F4CC: addiu       $a0, $s3, 0x30
    ctx->r4 = ADD32(ctx->r19, 0X30);
L_8007F4D0:
    // 0x8007F4D0: lw          $t1, 0x0($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X0);
    // 0x8007F4D4: lw          $t2, 0x4($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X4);
    // 0x8007F4D8: lw          $t3, 0x8($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X8);
    // 0x8007F4DC: lw          $t4, 0xC($v0)
    ctx->r12 = MEM_W(ctx->r2, 0XC);
    // 0x8007F4E0: sw          $t1, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r9;
    // 0x8007F4E4: sw          $t2, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r10;
    // 0x8007F4E8: sw          $t3, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r11;
    // 0x8007F4EC: sw          $t4, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r12;
    // 0x8007F4F0: addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
    // 0x8007F4F4: bne         $v0, $a0, L_8007F4D0
    if (ctx->r2 != ctx->r4) {
        // 0x8007F4F8: addiu       $v1, $v1, 0x10
        ctx->r3 = ADD32(ctx->r3, 0X10);
            goto L_8007F4D0;
    }
    // 0x8007F4F8: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
    // 0x8007F4FC: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x8007F500: jal         0x8007D81C
    // 0x8007F504: addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    func_8007D81C(rdram, ctx);
        goto after_40;
    // 0x8007F504: addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    after_40:
    // 0x8007F508: lwc1        $f0, 0x58($s3)
    ctx->f0.u32l = MEM_W(ctx->r19, 0X58);
    // 0x8007F50C: mul.s       $f0, $f20, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = MUL_S(ctx->f20.fl, ctx->f0.fl);
    // 0x8007F510: lwc1        $f2, 0x54($s3)
    ctx->f2.u32l = MEM_W(ctx->r19, 0X54);
    // 0x8007F514: add.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x8007F518: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8007F51C: lwc1        $f4, -0x26D4($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X26D4);
    // 0x8007F520: c.lt.s      $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f4.fl < ctx->f2.fl;
    // 0x8007F524: nop

    // 0x8007F528: bc1f        L_8007F540
    if (!c1cs) {
        // 0x8007F52C: swc1        $f2, 0x54($s3)
        MEM_W(0X54, ctx->r19) = ctx->f2.u32l;
            goto L_8007F540;
    }
    // 0x8007F52C: swc1        $f2, 0x54($s3)
    MEM_W(0X54, ctx->r19) = ctx->f2.u32l;
    // 0x8007F530: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8007F534: lwc1        $f0, -0x26D0($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X26D0);
    // 0x8007F538: sub.s       $f0, $f2, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f2.fl - ctx->f0.fl;
    // 0x8007F53C: swc1        $f0, 0x54($s3)
    MEM_W(0X54, ctx->r19) = ctx->f0.u32l;
L_8007F540:
    // 0x8007F540: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    // 0x8007F544: mfc1        $a2, $f4
    ctx->r6 = (int32_t)ctx->f4.u32l;
    // 0x8007F548: jal         0x80059B50
    // 0x8007F54C: addu        $a1, $s3, $zero
    ctx->r5 = ADD32(ctx->r19, 0);
    func_80059B50(rdram, ctx);
        goto after_41;
    // 0x8007F54C: addu        $a1, $s3, $zero
    ctx->r5 = ADD32(ctx->r19, 0);
    after_41:
    // 0x8007F550: sw          $zero, 0x54($sp)
    MEM_W(0X54, ctx->r29) = 0;
    // 0x8007F554: sw          $zero, 0x50($sp)
    MEM_W(0X50, ctx->r29) = 0;
    // 0x8007F558: sw          $zero, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = 0;
    // 0x8007F55C: sw          $zero, 0x60($sp)
    MEM_W(0X60, ctx->r29) = 0;
    // 0x8007F560: sw          $zero, 0x58($sp)
    MEM_W(0X58, ctx->r29) = 0;
    // 0x8007F564: lwc1        $f0, 0x54($s3)
    ctx->f0.u32l = MEM_W(ctx->r19, 0X54);
    // 0x8007F568: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8007F56C: lwc1        $f12, -0x26CC($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X26CC);
    // 0x8007F570: mul.s       $f12, $f0, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = MUL_S(ctx->f0.fl, ctx->f12.fl);
    // 0x8007F574: jal         0x80033960
    // 0x8007F578: nop

    sinf_recomp(rdram, ctx);
        goto after_42;
    // 0x8007F578: nop

    after_42:
    // 0x8007F57C: lw          $v0, 0x34($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X34);
    // 0x8007F580: lwc1        $f2, 0xA4($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0XA4);
    // 0x8007F584: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x8007F588: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8007F58C: lwc1        $f2, -0x26C8($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X26C8);
    // 0x8007F590: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x8007F594: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    // 0x8007F598: addiu       $a1, $sp, 0x58
    ctx->r5 = ADD32(ctx->r29, 0X58);
    // 0x8007F59C: addiu       $a2, $sp, 0x68
    ctx->r6 = ADD32(ctx->r29, 0X68);
    // 0x8007F5A0: jal         0x800193E8
    // 0x8007F5A4: swc1        $f0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f0.u32l;
    func_800193E8(rdram, ctx);
        goto after_43;
    // 0x8007F5A4: swc1        $f0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f0.u32l;
    after_43:
    // 0x8007F5A8: lwc1        $f0, 0x0($s3)
    ctx->f0.u32l = MEM_W(ctx->r19, 0X0);
    // 0x8007F5AC: lwc1        $f2, 0x68($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X68);
    // 0x8007F5B0: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x8007F5B4: swc1        $f0, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->f0.u32l;
    // 0x8007F5B8: lwc1        $f0, 0x4($s3)
    ctx->f0.u32l = MEM_W(ctx->r19, 0X4);
    // 0x8007F5BC: lwc1        $f2, 0x6C($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x8007F5C0: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x8007F5C4: addu        $a1, $s3, $zero
    ctx->r5 = ADD32(ctx->r19, 0);
    // 0x8007F5C8: swc1        $f0, 0x4($s3)
    MEM_W(0X4, ctx->r19) = ctx->f0.u32l;
    // 0x8007F5CC: lwc1        $f0, 0x8($s3)
    ctx->f0.u32l = MEM_W(ctx->r19, 0X8);
    // 0x8007F5D0: lwc1        $f2, 0x70($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X70);
    // 0x8007F5D4: lw          $a0, 0x30($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X30);
    // 0x8007F5D8: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x8007F5DC: lw          $a2, 0x40($s3)
    ctx->r6 = MEM_W(ctx->r19, 0X40);
    // 0x8007F5E0: addiu       $a0, $a0, 0x28
    ctx->r4 = ADD32(ctx->r4, 0X28);
    // 0x8007F5E4: jal         0x80059B50
    // 0x8007F5E8: swc1        $f0, 0x8($s3)
    MEM_W(0X8, ctx->r19) = ctx->f0.u32l;
    func_80059B50(rdram, ctx);
        goto after_44;
    // 0x8007F5E8: swc1        $f0, 0x8($s3)
    MEM_W(0X8, ctx->r19) = ctx->f0.u32l;
    after_44:
    // 0x8007F5EC: jal         0x8007E810
    // 0x8007F5F0: addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    func_8007E810(rdram, ctx);
        goto after_45;
    // 0x8007F5F0: addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    after_45:
    // 0x8007F5F4: lui         $a1, 0x8004
    ctx->r5 = S32(0X8004 << 16);
    // 0x8007F5F8: addiu       $a1, $a1, -0x28F8
    ctx->r5 = ADD32(ctx->r5, -0X28F8);
    // 0x8007F5FC: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // 0x8007F600: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x8007F604: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x8007F608: lw          $a0, 0x30($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X30);
    // 0x8007F60C: jal         0x80058360
    // 0x8007F610: addiu       $a3, $sp, 0x28
    ctx->r7 = ADD32(ctx->r29, 0X28);
    func_80058360(rdram, ctx);
        goto after_46;
    // 0x8007F610: addiu       $a3, $sp, 0x28
    ctx->r7 = ADD32(ctx->r29, 0X28);
    after_46:
    // 0x8007F614: jal         0x8006C8F0
    // 0x8007F618: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    func_8006C8F0(rdram, ctx);
        goto after_47;
    // 0x8007F618: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    after_47:
    // 0x8007F61C: lwc1        $f0, 0x0($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8007F620: lwc1        $f2, 0x28($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X28);
    // 0x8007F624: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x8007F628: lwc1        $f2, 0x2C($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x8007F62C: swc1        $f0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f0.u32l;
    // 0x8007F630: lwc1        $f0, 0x4($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X4);
    // 0x8007F634: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x8007F638: lwc1        $f2, 0x30($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X30);
    // 0x8007F63C: swc1        $f0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f0.u32l;
    // 0x8007F640: lwc1        $f0, 0x8($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X8);
    // 0x8007F644: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x8007F648: addiu       $a0, $sp, 0x58
    ctx->r4 = ADD32(ctx->r29, 0X58);
    // 0x8007F64C: jal         0x8001CF58
    // 0x8007F650: swc1        $f0, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f0.u32l;
    normalize_vector(rdram, ctx);
        goto after_48;
    // 0x8007F650: swc1        $f0, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f0.u32l;
    after_48:
    // 0x8007F654: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x8007F658: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    // 0x8007F65C: jal         0x8001CFE8
    // 0x8007F660: addiu       $a1, $sp, 0x58
    ctx->r5 = ADD32(ctx->r29, 0X58);
    func_8001CFE8(rdram, ctx);
        goto after_49;
    // 0x8007F660: addiu       $a1, $sp, 0x58
    ctx->r5 = ADD32(ctx->r29, 0X58);
    after_49:
    // 0x8007F664: lwc1        $f2, 0xDC($s3)
    ctx->f2.u32l = MEM_W(ctx->r19, 0XDC);
    // 0x8007F668: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x8007F66C: nop

    // 0x8007F670: bc1f        L_8007F6CC
    if (!c1cs) {
        // 0x8007F674: nop
    
            goto L_8007F6CC;
    }
    // 0x8007F674: nop

    // 0x8007F678: lwc1        $f0, 0xE0($s3)
    ctx->f0.u32l = MEM_W(ctx->r19, 0XE0);
    // 0x8007F67C: c.lt.s      $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f20.fl < ctx->f0.fl;
    // 0x8007F680: nop

    // 0x8007F684: bc1f        L_8007F6CC
    if (!c1cs) {
        // 0x8007F688: addu        $a0, $zero, $zero
        ctx->r4 = ADD32(0, 0);
            goto L_8007F6CC;
    }
    // 0x8007F688: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x8007F68C: sub.s       $f20, $f0, $f20
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f20.fl = ctx->f0.fl - ctx->f20.fl;
    // 0x8007F690: lwc1        $f0, 0xE4($s3)
    ctx->f0.u32l = MEM_W(ctx->r19, 0XE4);
    // 0x8007F694: mul.s       $f20, $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f20.fl = MUL_S(ctx->f20.fl, ctx->f0.fl);
    // 0x8007F698: neg.s       $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = -ctx->f20.fl;
    // 0x8007F69C: mul.s       $f20, $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f20.fl = MUL_S(ctx->f20.fl, ctx->f0.fl);
    // 0x8007F6A0: lwc1        $f4, 0x58($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X58);
    // 0x8007F6A4: mul.s       $f4, $f4, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = MUL_S(ctx->f4.fl, ctx->f20.fl);
    // 0x8007F6A8: lwc1        $f2, 0x5C($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x8007F6AC: mul.s       $f2, $f2, $f20
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f20.fl);
    // 0x8007F6B0: lwc1        $f0, 0x60($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X60);
    // 0x8007F6B4: mul.s       $f0, $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f20.fl);
    // 0x8007F6B8: addiu       $a1, $sp, 0x58
    ctx->r5 = ADD32(ctx->r29, 0X58);
    // 0x8007F6BC: swc1        $f4, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f4.u32l;
    // 0x8007F6C0: swc1        $f2, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f2.u32l;
    // 0x8007F6C4: jal         0x800B40F0
    // 0x8007F6C8: swc1        $f0, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f0.u32l;
    func_800B40F0(rdram, ctx);
        goto after_50;
    // 0x8007F6C8: swc1        $f0, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f0.u32l;
    after_50:
L_8007F6CC:
    // 0x8007F6CC: lbu         $v0, 0xD9($s3)
    ctx->r2 = MEM_BU(ctx->r19, 0XD9);
    // 0x8007F6D0: beq         $v0, $zero, L_8007F894
    if (ctx->r2 == 0) {
        // 0x8007F6D4: addu        $s1, $zero, $zero
        ctx->r17 = ADD32(0, 0);
            goto L_8007F894;
    }
    // 0x8007F6D4: addu        $s1, $zero, $zero
    ctx->r17 = ADD32(0, 0);
    // 0x8007F6D8: ori         $s2, $zero, 0xFFFF
    ctx->r18 = 0 | 0XFFFF;
    // 0x8007F6DC: addiu       $v0, $zero, 0x10
    ctx->r2 = ADD32(0, 0X10);
    // 0x8007F6E0: sb          $v0, 0x40($sp)
    MEM_B(0X40, ctx->r29) = ctx->r2;
    // 0x8007F6E4: lhu         $v0, 0x16($s7)
    ctx->r2 = MEM_HU(ctx->r23, 0X16);
    // 0x8007F6E8: addu        $s0, $s3, $zero
    ctx->r16 = ADD32(ctx->r19, 0);
    // 0x8007F6EC: sh          $zero, 0x2A($sp)
    MEM_H(0X2A, ctx->r29) = 0;
    // 0x8007F6F0: sh          $v0, 0x28($sp)
    MEM_H(0X28, ctx->r29) = ctx->r2;
L_8007F6F4:
    // 0x8007F6F4: lhu         $v0, 0xFC($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0XFC);
    // 0x8007F6F8: beql        $v0, $s2, L_8007F718
    if (ctx->r2 == ctx->r18) {
        // 0x8007F6FC: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_8007F718;
    }
    goto skip_3;
    // 0x8007F6FC: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    skip_3:
    // 0x8007F700: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    // 0x8007F704: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // 0x8007F708: jal         0x8003E8DC
    // 0x8007F70C: addiu       $a2, $sp, 0x28
    ctx->r6 = ADD32(ctx->r29, 0X28);
    slotDispatcherIter(rdram, ctx);
        goto after_51;
    // 0x8007F70C: addiu       $a2, $sp, 0x28
    ctx->r6 = ADD32(ctx->r29, 0X28);
    after_51:
    // 0x8007F710: sh          $s2, 0xFC($s0)
    MEM_H(0XFC, ctx->r16) = ctx->r18;
    // 0x8007F714: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
L_8007F718:
    // 0x8007F718: slti        $v0, $s1, 0x4
    ctx->r2 = SIGNED(ctx->r17) < 0X4 ? 1 : 0;
    // 0x8007F71C: bne         $v0, $zero, L_8007F6F4
    if (ctx->r2 != 0) {
        // 0x8007F720: addiu       $s0, $s0, 0x2
        ctx->r16 = ADD32(ctx->r16, 0X2);
            goto L_8007F6F4;
    }
    // 0x8007F720: addiu       $s0, $s0, 0x2
    ctx->r16 = ADD32(ctx->r16, 0X2);
    // 0x8007F724: lbu         $v1, 0x1B1($s3)
    ctx->r3 = MEM_BU(ctx->r19, 0X1B1);
    // 0x8007F728: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x8007F72C: sh          $v0, 0x1B2($s3)
    MEM_H(0X1B2, ctx->r19) = ctx->r2;
    // 0x8007F730: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8007F734: bne         $v1, $v0, L_8007F748
    if (ctx->r3 != ctx->r2) {
        // 0x8007F738: nop
    
            goto L_8007F748;
    }
    // 0x8007F738: nop

    // 0x8007F73C: sb          $zero, 0x1B1($s3)
    MEM_B(0X1B1, ctx->r19) = 0;
    // 0x8007F740: jal         0x80098DE0
    // 0x8007F744: addiu       $a0, $s3, 0x16C
    ctx->r4 = ADD32(ctx->r19, 0X16C);
    func_80098DE0(rdram, ctx);
        goto after_52;
    // 0x8007F744: addiu       $a0, $s3, 0x16C
    ctx->r4 = ADD32(ctx->r19, 0X16C);
    after_52:
L_8007F748:
    // 0x8007F748: lw          $v1, 0x34($s3)
    ctx->r3 = MEM_W(ctx->r19, 0X34);
    // 0x8007F74C: lw          $v0, 0x80($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X80);
    // 0x8007F750: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // 0x8007F754: lw          $v0, 0x34($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X34);
    // 0x8007F758: lw          $v0, 0x84($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X84);
    // 0x8007F75C: sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    // 0x8007F760: lw          $a0, 0x78($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X78);
    // 0x8007F764: lw          $a1, 0x7C($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X7C);
    // 0x8007F768: lw          $a2, 0x70($v1)
    ctx->r6 = MEM_W(ctx->r3, 0X70);
    // 0x8007F76C: lw          $a3, 0x74($v1)
    ctx->r7 = MEM_W(ctx->r3, 0X74);
    // 0x8007F770: jal         0x80065914
    // 0x8007F774: nop

    datItemSetObjectiveBooleanCount(rdram, ctx);
        goto after_53;
    // 0x8007F774: nop

    after_53:
    // 0x8007F778: lhu         $a0, 0x4E($s3)
    ctx->r4 = MEM_HU(ctx->r19, 0X4E);
    // 0x8007F77C: jal         0x8003E7D0
    // 0x8007F780: addu        $a1, $s7, $zero
    ctx->r5 = ADD32(ctx->r23, 0);
    func_8003E7D0(rdram, ctx);
        goto after_54;
    // 0x8007F780: addu        $a1, $s7, $zero
    ctx->r5 = ADD32(ctx->r23, 0);
    after_54:
    // 0x8007F784: addu        $a0, $s7, $zero
    ctx->r4 = ADD32(ctx->r23, 0);
    // 0x8007F788: ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
    // 0x8007F78C: jal         0x800F2AA4
    // 0x8007F790: sh          $v0, 0x4E($s3)
    MEM_H(0X4E, ctx->r19) = ctx->r2;
    func_800F2AA4(rdram, ctx);
        goto after_55;
    // 0x8007F790: sh          $v0, 0x4E($s3)
    MEM_H(0X4E, ctx->r19) = ctx->r2;
    after_55:
    // 0x8007F794: jal         0x800F3260
    // 0x8007F798: addu        $a0, $s7, $zero
    ctx->r4 = ADD32(ctx->r23, 0);
    func_800F3260(rdram, ctx);
        goto after_56;
    // 0x8007F798: addu        $a0, $s7, $zero
    ctx->r4 = ADD32(ctx->r23, 0);
    after_56:
    // 0x8007F79C: j           L_8007F894
    // 0x8007F7A0: nop

        goto L_8007F894;
    // 0x8007F7A0: nop

L_8007F7A4:
    // 0x8007F7A4: addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    // 0x8007F7A8: lw          $a2, 0x34($s3)
    ctx->r6 = MEM_W(ctx->r19, 0X34);
    // 0x8007F7AC: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x8007F7B0: jal         0x800AA6D0
    // 0x8007F7B4: addiu       $a2, $a2, 0x34
    ctx->r6 = ADD32(ctx->r6, 0X34);
    func_800AA6D0(rdram, ctx);
        goto after_57;
    // 0x8007F7B4: addiu       $a2, $a2, 0x34
    ctx->r6 = ADD32(ctx->r6, 0X34);
    after_57:
    // 0x8007F7B8: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x8007F7BC: jal         0x8007E154
    // 0x8007F7C0: addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    func_8007E154(rdram, ctx);
        goto after_58;
    // 0x8007F7C0: addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    after_58:
    // 0x8007F7C4: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x8007F7C8: jal         0x8007D81C
    // 0x8007F7CC: addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    func_8007D81C(rdram, ctx);
        goto after_59;
    // 0x8007F7CC: addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    after_59:
    // 0x8007F7D0: addu        $a1, $s3, $zero
    ctx->r5 = ADD32(ctx->r19, 0);
    // 0x8007F7D4: lw          $a0, 0x30($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X30);
    // 0x8007F7D8: lw          $a2, 0x40($s3)
    ctx->r6 = MEM_W(ctx->r19, 0X40);
    // 0x8007F7DC: jal         0x80059B50
    // 0x8007F7E0: addiu       $a0, $a0, 0x28
    ctx->r4 = ADD32(ctx->r4, 0X28);
    func_80059B50(rdram, ctx);
        goto after_60;
    // 0x8007F7E0: addiu       $a0, $a0, 0x28
    ctx->r4 = ADD32(ctx->r4, 0X28);
    after_60:
    // 0x8007F7E4: j           L_8007F894
    // 0x8007F7E8: nop

        goto L_8007F894;
    // 0x8007F7E8: nop

L_8007F7EC:
    // 0x8007F7EC: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x8007F7F0: jal         0x8007E360
    // 0x8007F7F4: addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    func_8007E360(rdram, ctx);
        goto after_61;
    // 0x8007F7F4: addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    after_61:
    // 0x8007F7F8: lwc1        $f0, 0x40($s3)
    ctx->f0.u32l = MEM_W(ctx->r19, 0X40);
    // 0x8007F7FC: swc1        $f0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f0.u32l;
    // 0x8007F800: swc1        $f0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f0.u32l;
    // 0x8007F804: lwc1        $f0, 0x44($s3)
    ctx->f0.u32l = MEM_W(ctx->r19, 0X44);
    // 0x8007F808: addu        $a1, $s3, $zero
    ctx->r5 = ADD32(ctx->r19, 0);
    // 0x8007F80C: swc1        $f0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f0.u32l;
    // 0x8007F810: lw          $a0, 0x30($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X30);
    // 0x8007F814: addiu       $a2, $sp, 0x28
    ctx->r6 = ADD32(ctx->r29, 0X28);
    // 0x8007F818: jal         0x80059C24
    // 0x8007F81C: addiu       $a0, $a0, 0x28
    ctx->r4 = ADD32(ctx->r4, 0X28);
    func_80059C24(rdram, ctx);
        goto after_62;
    // 0x8007F81C: addiu       $a0, $a0, 0x28
    ctx->r4 = ADD32(ctx->r4, 0X28);
    after_62:
    // 0x8007F820: j           L_8007F894
    // 0x8007F824: nop

        goto L_8007F894;
    // 0x8007F824: nop

L_8007F828:
    // 0x8007F828: lwc1        $f2, 0x3C($s3)
    ctx->f2.u32l = MEM_W(ctx->r19, 0X3C);
    // 0x8007F82C: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8007F830: lwc1        $f0, -0x26C4($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X26C4);
    // 0x8007F834: mul.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x8007F838: mfc1        $a1, $f2
    ctx->r5 = (int32_t)ctx->f2.u32l;
    // 0x8007F83C: jal         0x800612A4
    // 0x8007F840: addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    func_800612A4(rdram, ctx);
        goto after_63;
    // 0x8007F840: addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    after_63:
    // 0x8007F844: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x8007F848: addu        $a1, $s3, $zero
    ctx->r5 = ADD32(ctx->r19, 0);
    // 0x8007F84C: addiu       $a2, $a1, 0x24
    ctx->r6 = ADD32(ctx->r5, 0X24);
    // 0x8007F850: lui         $a3, 0x41C8
    ctx->r7 = S32(0X41C8 << 16);
    // 0x8007F854: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8007F858: lwc1        $f0, -0x26C0($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X26C0);
    // 0x8007F85C: addiu       $v0, $zero, 0x23
    ctx->r2 = ADD32(0, 0X23);
    // 0x8007F860: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // 0x8007F864: addiu       $v0, $zero, 0x7F
    ctx->r2 = ADD32(0, 0X7F);
    // 0x8007F868: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x8007F86C: addiu       $v0, $zero, 0x64
    ctx->r2 = ADD32(0, 0X64);
    // 0x8007F870: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x8007F874: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x8007F878: jal         0x800989D8
    // 0x8007F87C: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    func_800989D8(rdram, ctx);
        goto after_64;
    // 0x8007F87C: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    after_64:
L_8007F880:
    // 0x8007F880: lhu         $a0, 0x16($s7)
    ctx->r4 = MEM_HU(ctx->r23, 0X16);
    // 0x8007F884: jal         0x8003ED74
    // 0x8007F888: nop

    func_8003ED74(rdram, ctx);
        goto after_65;
    // 0x8007F888: nop

    after_65:
    // 0x8007F88C: j           L_8008007C
    // 0x8007F890: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8008007C;
    // 0x8007F890: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8007F894:
    // 0x8007F894: lw          $v0, 0x34($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X34);
    // 0x8007F898: lw          $v0, 0x88($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X88);
    // 0x8007F89C: beql        $v0, $zero, L_8007F8D4
    if (ctx->r2 == 0) {
        // 0x8007F8A0: sw          $zero, 0x124($s3)
        MEM_W(0X124, ctx->r19) = 0;
            goto L_8007F8D4;
    }
    goto skip_4;
    // 0x8007F8A0: sw          $zero, 0x124($s3)
    MEM_W(0X124, ctx->r19) = 0;
    skip_4:
    // 0x8007F8A4: jal         0x80047D40
    // 0x8007F8A8: addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    func_80047D40(rdram, ctx);
        goto after_66;
    // 0x8007F8A8: addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    after_66:
    // 0x8007F8AC: beq         $v0, $zero, L_8007F8BC
    if (ctx->r2 == 0) {
        // 0x8007F8B0: nop
    
            goto L_8007F8BC;
    }
    // 0x8007F8B0: nop

    // 0x8007F8B4: j           L_8007F8D4
    // 0x8007F8B8: sw          $zero, 0x124($s3)
    MEM_W(0X124, ctx->r19) = 0;
        goto L_8007F8D4;
    // 0x8007F8B8: sw          $zero, 0x124($s3)
    MEM_W(0X124, ctx->r19) = 0;
L_8007F8BC:
    // 0x8007F8BC: lw          $v0, 0x124($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X124);
    // 0x8007F8C0: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8007F8C4: sw          $v0, 0x124($s3)
    MEM_W(0X124, ctx->r19) = ctx->r2;
    // 0x8007F8C8: slti        $v0, $v0, 0x15
    ctx->r2 = SIGNED(ctx->r2) < 0X15 ? 1 : 0;
    // 0x8007F8CC: beq         $v0, $zero, L_8007F880
    if (ctx->r2 == 0) {
        // 0x8007F8D0: nop
    
            goto L_8007F880;
    }
    // 0x8007F8D0: nop

L_8007F8D4:
    // 0x8007F8D4: lbu         $v1, 0x2BC($s3)
    ctx->r3 = MEM_BU(ctx->r19, 0X2BC);
    // 0x8007F8D8: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // 0x8007F8DC: beq         $v1, $v0, L_8007F8F4
    if (ctx->r3 == ctx->r2) {
        // 0x8007F8E0: nop
    
            goto L_8007F8F4;
    }
    // 0x8007F8E0: nop

    // 0x8007F8E4: lw          $a1, 0x30($s3)
    ctx->r5 = MEM_W(ctx->r19, 0X30);
    // 0x8007F8E8: lw          $a2, 0x0($s4)
    ctx->r6 = MEM_W(ctx->r20, 0X0);
    // 0x8007F8EC: jal         0x80072BE0
    // 0x8007F8F0: addiu       $a0, $s3, 0x2BC
    ctx->r4 = ADD32(ctx->r19, 0X2BC);
    func_80072BE0(rdram, ctx);
        goto after_67;
    // 0x8007F8F0: addiu       $a0, $s3, 0x2BC
    ctx->r4 = ADD32(ctx->r19, 0X2BC);
    after_67:
L_8007F8F4:
    // 0x8007F8F4: lw          $a0, 0x38($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X38);
    // 0x8007F8F8: jal         0x800EC6C0
    // 0x8007F8FC: nop

    func_800EC6C0(rdram, ctx);
        goto after_68;
    // 0x8007F8FC: nop

    after_68:
    // 0x8007F900: j           L_8008007C
    // 0x8007F904: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8008007C;
    // 0x8007F904: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8007F908:
    // 0x8007F908: lw          $a0, 0x0($s4)
    ctx->r4 = MEM_W(ctx->r20, 0X0);
    // 0x8007F90C: lw          $a1, 0x30($s3)
    ctx->r5 = MEM_W(ctx->r19, 0X30);
    // 0x8007F910: lw          $a3, 0x3C($s3)
    ctx->r7 = MEM_W(ctx->r19, 0X3C);
    // 0x8007F914: jal         0x80057C8C
    // 0x8007F918: addu        $a2, $s3, $zero
    ctx->r6 = ADD32(ctx->r19, 0);
    func_80057C8C(rdram, ctx);
        goto after_69;
    // 0x8007F918: addu        $a2, $s3, $zero
    ctx->r6 = ADD32(ctx->r19, 0);
    after_69:
    // 0x8007F91C: beq         $v0, $zero, L_8007F93C
    if (ctx->r2 == 0) {
        // 0x8007F920: addiu       $v0, $zero, 0xFF
        ctx->r2 = ADD32(0, 0XFF);
            goto L_8007F93C;
    }
    // 0x8007F920: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // 0x8007F924: lbu         $v1, 0x2BC($s3)
    ctx->r3 = MEM_BU(ctx->r19, 0X2BC);
    // 0x8007F928: beq         $v1, $v0, L_8007F93C
    if (ctx->r3 == ctx->r2) {
        // 0x8007F92C: addiu       $a0, $s3, 0x2BC
        ctx->r4 = ADD32(ctx->r19, 0X2BC);
            goto L_8007F93C;
    }
    // 0x8007F92C: addiu       $a0, $s3, 0x2BC
    ctx->r4 = ADD32(ctx->r19, 0X2BC);
    // 0x8007F930: lw          $a1, 0x30($s3)
    ctx->r5 = MEM_W(ctx->r19, 0X30);
    // 0x8007F934: jal         0x80071928
    // 0x8007F938: addu        $a2, $s4, $zero
    ctx->r6 = ADD32(ctx->r20, 0);
    func_80071928(rdram, ctx);
        goto after_70;
    // 0x8007F938: addu        $a2, $s4, $zero
    ctx->r6 = ADD32(ctx->r20, 0);
    after_70:
L_8007F93C:
    // 0x8007F93C: lbu         $v0, 0x1B0($s3)
    ctx->r2 = MEM_BU(ctx->r19, 0X1B0);
    // 0x8007F940: beq         $v0, $zero, L_8007F968
    if (ctx->r2 == 0) {
        // 0x8007F944: addiu       $s0, $sp, 0x58
        ctx->r16 = ADD32(ctx->r29, 0X58);
            goto L_8007F968;
    }
    // 0x8007F944: addiu       $s0, $sp, 0x58
    ctx->r16 = ADD32(ctx->r29, 0X58);
    // 0x8007F948: lw          $a0, 0x30($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X30);
    // 0x8007F94C: jal         0x8006AC7C
    // 0x8007F950: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    func_8006AC7C(rdram, ctx);
        goto after_71;
    // 0x8007F950: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    after_71:
    // 0x8007F954: addiu       $a0, $s3, 0x128
    ctx->r4 = ADD32(ctx->r19, 0X128);
    // 0x8007F958: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x8007F95C: addiu       $a2, $s3, 0x24
    ctx->r6 = ADD32(ctx->r19, 0X24);
    // 0x8007F960: jal         0x800988E8
    // 0x8007F964: addiu       $a3, $zero, 0x7F
    ctx->r7 = ADD32(0, 0X7F);
    func_800988E8(rdram, ctx);
        goto after_72;
    // 0x8007F964: addiu       $a3, $zero, 0x7F
    ctx->r7 = ADD32(0, 0X7F);
    after_72:
L_8007F968:
    // 0x8007F968: lbu         $v0, 0x1B1($s3)
    ctx->r2 = MEM_BU(ctx->r19, 0X1B1);
    // 0x8007F96C: beq         $v0, $zero, L_8007F9A4
    if (ctx->r2 == 0) {
        // 0x8007F970: lui         $a1, 0x8004
        ctx->r5 = S32(0X8004 << 16);
            goto L_8007F9A4;
    }
    // 0x8007F970: lui         $a1, 0x8004
    ctx->r5 = S32(0X8004 << 16);
    // 0x8007F974: addiu       $a1, $a1, -0x28F8
    ctx->r5 = ADD32(ctx->r5, -0X28F8);
    // 0x8007F978: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // 0x8007F97C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x8007F980: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x8007F984: lw          $a0, 0x30($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X30);
    // 0x8007F988: jal         0x80058360
    // 0x8007F98C: addiu       $a3, $sp, 0x28
    ctx->r7 = ADD32(ctx->r29, 0X28);
    func_80058360(rdram, ctx);
        goto after_73;
    // 0x8007F98C: addiu       $a3, $sp, 0x28
    ctx->r7 = ADD32(ctx->r29, 0X28);
    after_73:
    // 0x8007F990: addiu       $a0, $s3, 0x16C
    ctx->r4 = ADD32(ctx->r19, 0X16C);
    // 0x8007F994: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    // 0x8007F998: addiu       $a2, $s3, 0x24
    ctx->r6 = ADD32(ctx->r19, 0X24);
    // 0x8007F99C: jal         0x800988E8
    // 0x8007F9A0: addiu       $a3, $zero, 0x78
    ctx->r7 = ADD32(0, 0X78);
    func_800988E8(rdram, ctx);
        goto after_74;
    // 0x8007F9A0: addiu       $a3, $zero, 0x78
    ctx->r7 = ADD32(0, 0X78);
    after_74:
L_8007F9A4:
    // 0x8007F9A4: addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
    // 0x8007F9A8: ori         $s1, $zero, 0xFFFF
    ctx->r17 = 0 | 0XFFFF;
    // 0x8007F9AC: addu        $s2, $s3, $zero
    ctx->r18 = ADD32(ctx->r19, 0);
L_8007F9B0:
    // 0x8007F9B0: lhu         $v0, 0x11C($s2)
    ctx->r2 = MEM_HU(ctx->r18, 0X11C);
    // 0x8007F9B4: beql        $v0, $s1, L_8007F9D0
    if (ctx->r2 == ctx->r17) {
        // 0x8007F9B8: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_8007F9D0;
    }
    goto skip_5;
    // 0x8007F9B8: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    skip_5:
    // 0x8007F9BC: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // 0x8007F9C0: addiu       $a1, $zero, 0xE
    ctx->r5 = ADD32(0, 0XE);
    // 0x8007F9C4: jal         0x8003E8DC
    // 0x8007F9C8: addu        $a2, $s4, $zero
    ctx->r6 = ADD32(ctx->r20, 0);
    slotDispatcherIter(rdram, ctx);
        goto after_75;
    // 0x8007F9C8: addu        $a2, $s4, $zero
    ctx->r6 = ADD32(ctx->r20, 0);
    after_75:
    // 0x8007F9CC: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_8007F9D0:
    // 0x8007F9D0: slti        $v0, $s0, 0x4
    ctx->r2 = SIGNED(ctx->r16) < 0X4 ? 1 : 0;
    // 0x8007F9D4: bne         $v0, $zero, L_8007F9B0
    if (ctx->r2 != 0) {
        // 0x8007F9D8: addiu       $s2, $s2, 0x2
        ctx->r18 = ADD32(ctx->r18, 0X2);
            goto L_8007F9B0;
    }
    // 0x8007F9D8: addiu       $s2, $s2, 0x2
    ctx->r18 = ADD32(ctx->r18, 0X2);
    // 0x8007F9DC: j           L_8008007C
    // 0x8007F9E0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8008007C;
    // 0x8007F9E0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8007F9E4:
    // 0x8007F9E4: lw          $a0, 0x8($s4)
    ctx->r4 = MEM_W(ctx->r20, 0X8);
    // 0x8007F9E8: beq         $a0, $zero, L_8007FC3C
    if (ctx->r4 == 0) {
        // 0x8007F9EC: addu        $fp, $s4, $zero
        ctx->r30 = ADD32(ctx->r20, 0);
            goto L_8007FC3C;
    }
    // 0x8007F9EC: addu        $fp, $s4, $zero
    ctx->r30 = ADD32(ctx->r20, 0);
    // 0x8007F9F0: lbu         $v0, 0xF8($s3)
    ctx->r2 = MEM_BU(ctx->r19, 0XF8);
    // 0x8007F9F4: bne         $v0, $zero, L_8007FA34
    if (ctx->r2 != 0) {
        // 0x8007F9F8: addu        $a1, $zero, $zero
        ctx->r5 = ADD32(0, 0);
            goto L_8007FA34;
    }
    // 0x8007F9F8: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x8007F9FC: jal         0x80076250
    // 0x8007FA00: addu        $a0, $s4, $zero
    ctx->r4 = ADD32(ctx->r20, 0);
    func_80076250(rdram, ctx);
        goto after_76;
    // 0x8007FA00: addu        $a0, $s4, $zero
    ctx->r4 = ADD32(ctx->r20, 0);
    after_76:
    // 0x8007FA04: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x8007FA08: addu        $a1, $s3, $zero
    ctx->r5 = ADD32(ctx->r19, 0);
    // 0x8007FA0C: addiu       $a2, $s3, 0x24
    ctx->r6 = ADD32(ctx->r19, 0X24);
    // 0x8007FA10: lui         $a3, 0x41C0
    ctx->r7 = S32(0X41C0 << 16);
    // 0x8007FA14: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8007FA18: lwc1        $f0, -0x26BC($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X26BC);
    // 0x8007FA1C: addiu       $v0, $zero, 0x2A
    ctx->r2 = ADD32(0, 0X2A);
    // 0x8007FA20: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // 0x8007FA24: addiu       $v0, $zero, 0x7F
    ctx->r2 = ADD32(0, 0X7F);
    // 0x8007FA28: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x8007FA2C: j           L_8007FA90
    // 0x8007FA30: addiu       $v0, $zero, 0x50
    ctx->r2 = ADD32(0, 0X50);
        goto L_8007FA90;
    // 0x8007FA30: addiu       $v0, $zero, 0x50
    ctx->r2 = ADD32(0, 0X50);
L_8007FA34:
    // 0x8007FA34: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8007FA38: lwc1        $f20, -0x26B8($at)
    ctx->f20.u32l = MEM_W(ctx->r1, -0X26B8);
    // 0x8007FA3C: addiu       $s0, $sp, 0x68
    ctx->r16 = ADD32(ctx->r29, 0X68);
    // 0x8007FA40: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x8007FA44: jal         0x80077784
    // 0x8007FA48: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    func_80077784(rdram, ctx);
        goto after_77;
    // 0x8007FA48: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    after_77:
    // 0x8007FA4C: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x8007FA50: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x8007FA54: lui         $a2, 0x3F4C
    ctx->r6 = S32(0X3F4C << 16);
    // 0x8007FA58: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x8007FA5C: jal         0x8006133C
    // 0x8007FA60: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    func_8006133C(rdram, ctx);
        goto after_78;
    // 0x8007FA60: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    after_78:
    // 0x8007FA64: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x8007FA68: addu        $a1, $s3, $zero
    ctx->r5 = ADD32(ctx->r19, 0);
    // 0x8007FA6C: addiu       $a2, $s3, 0x24
    ctx->r6 = ADD32(ctx->r19, 0X24);
    // 0x8007FA70: lui         $a3, 0x41C0
    ctx->r7 = S32(0X41C0 << 16);
    // 0x8007FA74: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8007FA78: lwc1        $f0, -0x26B4($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X26B4);
    // 0x8007FA7C: addiu       $v0, $zero, 0x35
    ctx->r2 = ADD32(0, 0X35);
    // 0x8007FA80: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // 0x8007FA84: addiu       $v0, $zero, 0x7F
    ctx->r2 = ADD32(0, 0X7F);
    // 0x8007FA88: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x8007FA8C: addiu       $v0, $zero, 0x46
    ctx->r2 = ADD32(0, 0X46);
L_8007FA90:
    // 0x8007FA90: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x8007FA94: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x8007FA98: jal         0x800989D8
    // 0x8007FA9C: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    func_800989D8(rdram, ctx);
        goto after_79;
    // 0x8007FA9C: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    after_79:
    // 0x8007FAA0: lh          $v0, 0x1B2($s3)
    ctx->r2 = MEM_H(ctx->r19, 0X1B2);
    // 0x8007FAA4: slti        $v0, $v0, 0x3
    ctx->r2 = SIGNED(ctx->r2) < 0X3 ? 1 : 0;
    // 0x8007FAA8: beq         $v0, $zero, L_8007FC3C
    if (ctx->r2 == 0) {
        // 0x8007FAAC: nop
    
            goto L_8007FC3C;
    }
    // 0x8007FAAC: nop

    // 0x8007FAB0: lw          $v0, 0x8($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X8);
    // 0x8007FAB4: lw          $s4, 0x24($v0)
    ctx->r20 = MEM_W(ctx->r2, 0X24);
    // 0x8007FAB8: beq         $s4, $zero, L_8007FC3C
    if (ctx->r20 == 0) {
        // 0x8007FABC: addiu       $v0, $zero, 0x66
        ctx->r2 = ADD32(0, 0X66);
            goto L_8007FC3C;
    }
    // 0x8007FABC: addiu       $v0, $zero, 0x66
    ctx->r2 = ADD32(0, 0X66);
    // 0x8007FAC0: lbu         $v1, 0x0($s4)
    ctx->r3 = MEM_BU(ctx->r20, 0X0);
    // 0x8007FAC4: bne         $v1, $v0, L_8007FC3C
    if (ctx->r3 != ctx->r2) {
        // 0x8007FAC8: addiu       $v0, $zero, 0x5F
        ctx->r2 = ADD32(0, 0X5F);
            goto L_8007FC3C;
    }
    // 0x8007FAC8: addiu       $v0, $zero, 0x5F
    ctx->r2 = ADD32(0, 0X5F);
    // 0x8007FACC: lbu         $v1, 0x1($s4)
    ctx->r3 = MEM_BU(ctx->r20, 0X1);
    // 0x8007FAD0: bne         $v1, $v0, L_8007FC3C
    if (ctx->r3 != ctx->r2) {
        // 0x8007FAD4: nop
    
            goto L_8007FC3C;
    }
    // 0x8007FAD4: nop

    // 0x8007FAD8: lbu         $v0, 0xF8($s3)
    ctx->r2 = MEM_BU(ctx->r19, 0XF8);
    // 0x8007FADC: bne         $v0, $zero, L_8007FC3C
    if (ctx->r2 != 0) {
        // 0x8007FAE0: nop
    
            goto L_8007FC3C;
    }
    // 0x8007FAE0: nop

    // 0x8007FAE4: lbu         $v0, 0x3($s4)
    ctx->r2 = MEM_BU(ctx->r20, 0X3);
    // 0x8007FAE8: addiu       $s5, $v0, -0x31
    ctx->r21 = ADD32(ctx->r2, -0X31);
    // 0x8007FAEC: sll         $v0, $s5, 2
    ctx->r2 = S32(ctx->r21 << 2);
    // 0x8007FAF0: addu        $a0, $s3, $v0
    ctx->r4 = ADD32(ctx->r19, ctx->r2);
    // 0x8007FAF4: lw          $v1, 0xE8($a0)
    ctx->r3 = MEM_W(ctx->r4, 0XE8);
    // 0x8007FAF8: blez        $v1, L_8007FC3C
    if (SIGNED(ctx->r3) <= 0) {
        // 0x8007FAFC: nop
    
            goto L_8007FC3C;
    }
    // 0x8007FAFC: nop

    // 0x8007FB00: lhu         $v0, 0x6($fp)
    ctx->r2 = MEM_HU(ctx->r30, 0X6);
    // 0x8007FB04: subu        $v0, $v1, $v0
    ctx->r2 = SUB32(ctx->r3, ctx->r2);
    // 0x8007FB08: bgtz        $v0, L_8007FC3C
    if (SIGNED(ctx->r2) > 0) {
        // 0x8007FB0C: sw          $v0, 0xE8($a0)
        MEM_W(0XE8, ctx->r4) = ctx->r2;
            goto L_8007FC3C;
    }
    // 0x8007FB0C: sw          $v0, 0xE8($a0)
    MEM_W(0XE8, ctx->r4) = ctx->r2;
    // 0x8007FB10: sll         $v0, $s5, 1
    ctx->r2 = S32(ctx->r21 << 1);
    // 0x8007FB14: addu        $s2, $s3, $v0
    ctx->r18 = ADD32(ctx->r19, ctx->r2);
    // 0x8007FB18: lhu         $v0, 0xFC($s2)
    ctx->r2 = MEM_HU(ctx->r18, 0XFC);
    // 0x8007FB1C: ori         $s6, $zero, 0xFFFF
    ctx->r22 = 0 | 0XFFFF;
    // 0x8007FB20: beq         $v0, $s6, L_8007FB54
    if (ctx->r2 == ctx->r22) {
        // 0x8007FB24: addiu       $v0, $zero, 0x10
        ctx->r2 = ADD32(0, 0X10);
            goto L_8007FB54;
    }
    // 0x8007FB24: addiu       $v0, $zero, 0x10
    ctx->r2 = ADD32(0, 0X10);
    // 0x8007FB28: sb          $v0, 0x90($sp)
    MEM_B(0X90, ctx->r29) = ctx->r2;
    // 0x8007FB2C: lhu         $v0, 0x16($s7)
    ctx->r2 = MEM_HU(ctx->r23, 0X16);
    // 0x8007FB30: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    // 0x8007FB34: sh          $zero, 0x7A($sp)
    MEM_H(0X7A, ctx->r29) = 0;
    // 0x8007FB38: sh          $v0, 0x78($sp)
    MEM_H(0X78, ctx->r29) = ctx->r2;
    // 0x8007FB3C: lhu         $a0, 0xFC($s2)
    ctx->r4 = MEM_HU(ctx->r18, 0XFC);
    // 0x8007FB40: jal         0x8003E8DC
    // 0x8007FB44: addiu       $a2, $sp, 0x78
    ctx->r6 = ADD32(ctx->r29, 0X78);
    slotDispatcherIter(rdram, ctx);
        goto after_80;
    // 0x8007FB44: addiu       $a2, $sp, 0x78
    ctx->r6 = ADD32(ctx->r29, 0X78);
    after_80:
    // 0x8007FB48: lhu         $v0, 0xFC($s2)
    ctx->r2 = MEM_HU(ctx->r18, 0XFC);
    // 0x8007FB4C: sh          $s6, 0xFC($s2)
    MEM_H(0XFC, ctx->r18) = ctx->r22;
    // 0x8007FB50: sh          $v0, 0x104($s2)
    MEM_H(0X104, ctx->r18) = ctx->r2;
L_8007FB54:
    // 0x8007FB54: lhu         $v0, 0x114($s2)
    ctx->r2 = MEM_HU(ctx->r18, 0X114);
    // 0x8007FB58: beq         $v0, $s6, L_8007FC3C
    if (ctx->r2 == ctx->r22) {
        // 0x8007FB5C: addiu       $s1, $sp, 0x98
        ctx->r17 = ADD32(ctx->r29, 0X98);
            goto L_8007FC3C;
    }
    // 0x8007FB5C: addiu       $s1, $sp, 0x98
    ctx->r17 = ADD32(ctx->r29, 0X98);
    // 0x8007FB60: jal         0x80079A94
    // 0x8007FB64: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    func_80079A94(rdram, ctx);
        goto after_81;
    // 0x8007FB64: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    after_81:
    // 0x8007FB68: lhu         $a0, 0x114($s2)
    ctx->r4 = MEM_HU(ctx->r18, 0X114);
    // 0x8007FB6C: jal         0x8004015C
    // 0x8007FB70: nop

    func_8004015C(rdram, ctx);
        goto after_82;
    // 0x8007FB70: nop

    after_82:
    // 0x8007FB74: addu        $a1, $s4, $zero
    ctx->r5 = ADD32(ctx->r20, 0);
    // 0x8007FB78: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // 0x8007FB7C: lw          $a0, 0x30($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X30);
    // 0x8007FB80: jal         0x80059434
    // 0x8007FB84: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    func_80059434(rdram, ctx);
        goto after_83;
    // 0x8007FB84: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    after_83:
    // 0x8007FB88: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // 0x8007FB8C: jal         0x800799C0
    // 0x8007FB90: addiu       $a1, $sp, 0xC8
    ctx->r5 = ADD32(ctx->r29, 0XC8);
    func_800799C0(rdram, ctx);
        goto after_84;
    // 0x8007FB90: addiu       $a1, $sp, 0xC8
    ctx->r5 = ADD32(ctx->r29, 0XC8);
    after_84:
    // 0x8007FB94: lwc1        $f0, 0x0($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X0);
    // 0x8007FB98: lwc1        $f2, 0xEC($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0XEC);
    // 0x8007FB9C: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x8007FBA0: swc1        $f0, 0xB8($sp)
    MEM_W(0XB8, ctx->r29) = ctx->f0.u32l;
    // 0x8007FBA4: lwc1        $f2, 0x4($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X4);
    // 0x8007FBA8: lwc1        $f0, 0xF0($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0XF0);
    // 0x8007FBAC: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8007FBB0: lwc1        $f4, -0x26B0($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X26B0);
    // 0x8007FBB4: sub.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl - ctx->f0.fl;
    // 0x8007FBB8: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8007FBBC: lwc1        $f0, -0x26AC($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X26AC);
    // 0x8007FBC0: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x8007FBC4: swc1        $f2, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->f2.u32l;
    // 0x8007FBC8: lwc1        $f6, 0x8($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8007FBCC: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8007FBD0: lwc1        $f2, -0x26A8($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X26A8);
    // 0x8007FBD4: addu        $a1, $s7, $zero
    ctx->r5 = ADD32(ctx->r23, 0);
    // 0x8007FBD8: swc1        $f0, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->f0.u32l;
    // 0x8007FBDC: lwc1        $f0, 0xF4($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0XF4);
    // 0x8007FBE0: addu        $a2, $s4, $zero
    ctx->r6 = ADD32(ctx->r20, 0);
    // 0x8007FBE4: sw          $zero, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = 0;
    // 0x8007FBE8: sw          $zero, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = 0;
    // 0x8007FBEC: swc1        $f2, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->f2.u32l;
    // 0x8007FBF0: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8007FBF4: lwc1        $f2, -0x26A4($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X26A4);
    // 0x8007FBF8: sub.s       $f6, $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f6.fl - ctx->f0.fl;
    // 0x8007FBFC: swc1        $f4, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->f4.u32l;
    // 0x8007FC00: swc1        $f2, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->f2.u32l;
    // 0x8007FC04: jal         0x80079BC8
    // 0x8007FC08: swc1        $f6, 0xC0($sp)
    MEM_W(0XC0, ctx->r29) = ctx->f6.u32l;
    func_80079BC8(rdram, ctx);
        goto after_85;
    // 0x8007FC08: swc1        $f6, 0xC0($sp)
    MEM_W(0XC0, ctx->r29) = ctx->f6.u32l;
    after_85:
    // 0x8007FC0C: lhu         $a0, 0x114($s2)
    ctx->r4 = MEM_HU(ctx->r18, 0X114);
    // 0x8007FC10: jal         0x8003ED74
    // 0x8007FC14: sh          $v0, 0x11C($s2)
    MEM_H(0X11C, ctx->r18) = ctx->r2;
    func_8003ED74(rdram, ctx);
        goto after_86;
    // 0x8007FC14: sh          $v0, 0x11C($s2)
    MEM_H(0X11C, ctx->r18) = ctx->r2;
    after_86:
    // 0x8007FC18: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x8007FC1C: sllv        $v1, $v1, $s5
    ctx->r3 = S32(ctx->r3 << (ctx->r21 & 31));
    // 0x8007FC20: sh          $s6, 0x114($s2)
    MEM_H(0X114, ctx->r18) = ctx->r22;
    // 0x8007FC24: lbu         $v0, 0xF9($s3)
    ctx->r2 = MEM_BU(ctx->r19, 0XF9);
    // 0x8007FC28: lhu         $a0, 0xFA($s3)
    ctx->r4 = MEM_HU(ctx->r19, 0XFA);
    // 0x8007FC2C: or          $v0, $v0, $v1
    ctx->r2 = ctx->r2 | ctx->r3;
    // 0x8007FC30: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x8007FC34: sb          $v0, 0xF9($s3)
    MEM_B(0XF9, ctx->r19) = ctx->r2;
    // 0x8007FC38: sh          $a0, 0xFA($s3)
    MEM_H(0XFA, ctx->r19) = ctx->r4;
L_8007FC3C:
    // 0x8007FC3C: lhu         $v1, 0x0($fp)
    ctx->r3 = MEM_HU(ctx->r30, 0X0);
    // 0x8007FC40: ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
    // 0x8007FC44: beq         $v1, $v0, L_8008007C
    if (ctx->r3 == ctx->r2) {
        // 0x8007FC48: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_8008007C;
    }
    // 0x8007FC48: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8007FC4C: jal         0x8003ED74
    // 0x8007FC50: addu        $a0, $v1, $zero
    ctx->r4 = ADD32(ctx->r3, 0);
    func_8003ED74(rdram, ctx);
        goto after_87;
    // 0x8007FC50: addu        $a0, $v1, $zero
    ctx->r4 = ADD32(ctx->r3, 0);
    after_87:
    // 0x8007FC54: j           L_8008007C
    // 0x8007FC58: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8008007C;
    // 0x8007FC58: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8007FC5C:
    // 0x8007FC5C: addu        $s2, $s4, $zero
    ctx->r18 = ADD32(ctx->r20, 0);
    // 0x8007FC60: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x8007FC64: addiu       $s7, $sp, 0x98
    ctx->r23 = ADD32(ctx->r29, 0X98);
    // 0x8007FC68: ori         $s5, $zero, 0xFFFF
    ctx->r21 = 0 | 0XFFFF;
    // 0x8007FC6C: addiu       $s1, $sp, 0x68
    ctx->r17 = ADD32(ctx->r29, 0X68);
    // 0x8007FC70: addiu       $s6, $sp, 0x78
    ctx->r22 = ADD32(ctx->r29, 0X78);
    // 0x8007FC74: addiu       $s4, $sp, 0x88
    ctx->r20 = ADD32(ctx->r29, 0X88);
    // 0x8007FC78: addu        $s0, $s3, $zero
    ctx->r16 = ADD32(ctx->r19, 0);
    // 0x8007FC7C: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8007FC80: lwc1        $f20, -0x26A0($at)
    ctx->f20.u32l = MEM_W(ctx->r1, -0X26A0);
    // 0x8007FC84: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8007FC88: lwc1        $f22, -0x269C($at)
    ctx->f22.u32l = MEM_W(ctx->r1, -0X269C);
    // 0x8007FC8C: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8007FC90: lwc1        $f26, -0x2698($at)
    ctx->f26.u32l = MEM_W(ctx->r1, -0X2698);
    // 0x8007FC94: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8007FC98: lwc1        $f24, -0x2694($at)
    ctx->f24.u32l = MEM_W(ctx->r1, -0X2694);
L_8007FC9C:
    // 0x8007FC9C: lhu         $v1, 0x11C($s0)
    ctx->r3 = MEM_HU(ctx->r16, 0X11C);
    // 0x8007FCA0: lhu         $v0, 0x0($s2)
    ctx->r2 = MEM_HU(ctx->r18, 0X0);
    // 0x8007FCA4: bnel        $v1, $v0, L_8007FEE4
    if (ctx->r3 != ctx->r2) {
        // 0x8007FCA8: addiu       $a0, $a0, 0x1
        ctx->r4 = ADD32(ctx->r4, 0X1);
            goto L_8007FEE4;
    }
    goto skip_6;
    // 0x8007FCA8: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    skip_6:
    // 0x8007FCAC: lui         $v0, 0x8004
    ctx->r2 = S32(0X8004 << 16);
    // 0x8007FCB0: addiu       $t4, $v0, -0x2740
    ctx->r12 = ADD32(ctx->r2, -0X2740);
    // 0x8007FCB4: lwl         $t1, 0x0($t4)
    ctx->r9 = do_lwl(rdram, ctx->r9, ctx->r12, 0X0);
    // 0x8007FCB8: lwr         $t1, 0x3($t4)
    ctx->r9 = do_lwr(rdram, ctx->r9, ctx->r12, 0X3);
    // 0x8007FCBC: swl         $t1, 0x98($sp)
    do_swl(rdram, 0X98, ctx->r29, ctx->r9);
    // 0x8007FCC0: swr         $t1, 0x9B($sp)
    do_swr(rdram, 0X9B, ctx->r29, ctx->r9);
    // 0x8007FCC4: lhu         $v1, 0x104($s0)
    ctx->r3 = MEM_HU(ctx->r16, 0X104);
    // 0x8007FCC8: ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
    // 0x8007FCCC: beq         $v1, $s5, L_8007FCE0
    if (ctx->r3 == ctx->r21) {
        // 0x8007FCD0: sh          $v0, 0x11C($s0)
        MEM_H(0X11C, ctx->r16) = ctx->r2;
            goto L_8007FCE0;
    }
    // 0x8007FCD0: sh          $v0, 0x11C($s0)
    MEM_H(0X11C, ctx->r16) = ctx->r2;
    // 0x8007FCD4: jal         0x8003ED74
    // 0x8007FCD8: addu        $a0, $v1, $zero
    ctx->r4 = ADD32(ctx->r3, 0);
    func_8003ED74(rdram, ctx);
        goto after_88;
    // 0x8007FCD8: addu        $a0, $v1, $zero
    ctx->r4 = ADD32(ctx->r3, 0);
    after_88:
    // 0x8007FCDC: sh          $s5, 0x104($s0)
    MEM_H(0X104, ctx->r16) = ctx->r21;
L_8007FCE0:
    // 0x8007FCE0: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x8007FCE4: addiu       $s5, $zero, 0x28
    ctx->r21 = ADD32(0, 0X28);
    // 0x8007FCE8: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8007FCEC: lwc1        $f28, -0x2690($at)
    ctx->f28.u32l = MEM_W(ctx->r1, -0X2690);
    // 0x8007FCF0: lui         $a1, 0x4170
    ctx->r5 = S32(0X4170 << 16);
    // 0x8007FCF4: lw          $t1, 0x4($s2)
    ctx->r9 = MEM_W(ctx->r18, 0X4);
    // 0x8007FCF8: lw          $t2, 0x8($s2)
    ctx->r10 = MEM_W(ctx->r18, 0X8);
    // 0x8007FCFC: lw          $t3, 0xC($s2)
    ctx->r11 = MEM_W(ctx->r18, 0XC);
    // 0x8007FD00: sw          $t1, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r9;
    // 0x8007FD04: sw          $t2, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r10;
    // 0x8007FD08: sw          $t3, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r11;
    // 0x8007FD0C: jal         0x800612A4
    // 0x8007FD10: addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
    func_800612A4(rdram, ctx);
        goto after_89;
    // 0x8007FD10: addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
    after_89:
    // 0x8007FD14: jal         0x8005EBD8
    // 0x8007FD18: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    func_8005EBD8(rdram, ctx);
        goto after_90;
    // 0x8007FD18: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    after_90:
    // 0x8007FD1C: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x8007FD20: addu        $a1, $s3, $zero
    ctx->r5 = ADD32(ctx->r19, 0);
    // 0x8007FD24: addiu       $a2, $a1, 0x24
    ctx->r6 = ADD32(ctx->r5, 0X24);
    // 0x8007FD28: lui         $a3, 0x41C8
    ctx->r7 = S32(0X41C8 << 16);
    // 0x8007FD2C: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8007FD30: lwc1        $f0, -0x268C($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X268C);
    // 0x8007FD34: addiu       $v0, $zero, 0x23
    ctx->r2 = ADD32(0, 0X23);
    // 0x8007FD38: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // 0x8007FD3C: addiu       $v0, $zero, 0x7F
    ctx->r2 = ADD32(0, 0X7F);
    // 0x8007FD40: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x8007FD44: addiu       $v0, $zero, 0x64
    ctx->r2 = ADD32(0, 0X64);
    // 0x8007FD48: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x8007FD4C: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x8007FD50: jal         0x800989D8
    // 0x8007FD54: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    func_800989D8(rdram, ctx);
        goto after_91;
    // 0x8007FD54: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    after_91:
    // 0x8007FD58: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x8007FD5C: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    // 0x8007FD60: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    // 0x8007FD64: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8007FD68: lwc1        $f0, -0x2688($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X2688);
    // 0x8007FD6C: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8007FD70: lwc1        $f2, -0x2684($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X2684);
    // 0x8007FD74: addu        $a3, $s0, $zero
    ctx->r7 = ADD32(ctx->r16, 0);
    // 0x8007FD78: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    // 0x8007FD7C: swc1        $f22, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f22.u32l;
    // 0x8007FD80: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    // 0x8007FD84: jal         0x80072684
    // 0x8007FD88: swc1        $f2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f2.u32l;
    func_80072684(rdram, ctx);
        goto after_92;
    // 0x8007FD88: swc1        $f2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f2.u32l;
    after_92:
    // 0x8007FD8C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8007FD90: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    // 0x8007FD94: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    // 0x8007FD98: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8007FD9C: lwc1        $f0, -0x2680($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X2680);
    // 0x8007FDA0: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8007FDA4: lwc1        $f2, -0x267C($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X267C);
    // 0x8007FDA8: addu        $a3, $s7, $zero
    ctx->r7 = ADD32(ctx->r23, 0);
    // 0x8007FDAC: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    // 0x8007FDB0: swc1        $f22, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f22.u32l;
    // 0x8007FDB4: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    // 0x8007FDB8: jal         0x80072684
    // 0x8007FDBC: swc1        $f2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f2.u32l;
    func_80072684(rdram, ctx);
        goto after_93;
    // 0x8007FDBC: swc1        $f2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f2.u32l;
    after_93:
L_8007FDC0:
    // 0x8007FDC0: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8007FDC4: lwc1        $f0, -0x2678($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X2678);
    // 0x8007FDC8: mul.s       $f0, $f28, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f28.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = MUL_S(ctx->f28.fl, ctx->f0.fl);
    // 0x8007FDCC: addu        $a0, $s6, $zero
    ctx->r4 = ADD32(ctx->r22, 0);
    // 0x8007FDD0: addu        $a1, $s4, $zero
    ctx->r5 = ADD32(ctx->r20, 0);
    // 0x8007FDD4: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8007FDD8: addiu       $a3, $zero, 0x3C
    ctx->r7 = ADD32(0, 0X3C);
    // 0x8007FDDC: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x8007FDE0: jal         0x8007202C
    // 0x8007FDE4: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    func_8007202C(rdram, ctx);
        goto after_94;
    // 0x8007FDE4: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    after_94:
    // 0x8007FDE8: addu        $a0, $s4, $zero
    ctx->r4 = ADD32(ctx->r20, 0);
    // 0x8007FDEC: lwc1        $f6, 0x78($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X78);
    // 0x8007FDF0: lwc1        $f0, 0x68($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X68);
    // 0x8007FDF4: lwc1        $f4, 0x7C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X7C);
    // 0x8007FDF8: lui         $a1, 0x3FC0
    ctx->r5 = S32(0X3FC0 << 16);
    // 0x8007FDFC: add.s       $f6, $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f0.fl;
    // 0x8007FE00: lwc1        $f0, 0x6C($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x8007FE04: lwc1        $f2, 0x70($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X70);
    // 0x8007FE08: add.s       $f4, $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f0.fl;
    // 0x8007FE0C: lwc1        $f0, 0x80($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X80);
    // 0x8007FE10: mfc1        $a2, $f26
    ctx->r6 = (int32_t)ctx->f26.u32l;
    // 0x8007FE14: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x8007FE18: swc1        $f6, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->f6.u32l;
    // 0x8007FE1C: swc1        $f4, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->f4.u32l;
    // 0x8007FE20: jal         0x80072300
    // 0x8007FE24: swc1        $f0, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->f0.u32l;
    func_80072300(rdram, ctx);
        goto after_95;
    // 0x8007FE24: swc1        $f0, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->f0.u32l;
    after_95:
    // 0x8007FE28: jal         0x80003430
    // 0x8007FE2C: nop

    rand_recomp(rdram, ctx);
        goto after_96;
    // 0x8007FE2C: nop

    after_96:
    // 0x8007FE30: andi        $v0, $v0, 0x7F
    ctx->r2 = ctx->r2 & 0X7F;
    // 0x8007FE34: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x8007FE38: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x8007FE3C: sub.s       $f0, $f0, $f24
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f24.fl;
    // 0x8007FE40: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8007FE44: lwc1        $f2, -0x2674($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X2674);
    // 0x8007FE48: div.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f2.fl);
    // 0x8007FE4C: abs.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f22.fl = fabsf(ctx->f0.fl);
    // 0x8007FE50: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8007FE54: lwc1        $f0, -0x2670($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X2670);
    // 0x8007FE58: jal         0x80003430
    // 0x8007FE5C: add.s       $f22, $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f22.fl = ctx->f22.fl + ctx->f0.fl;
    rand_recomp(rdram, ctx);
        goto after_97;
    // 0x8007FE5C: add.s       $f22, $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f22.fl = ctx->f22.fl + ctx->f0.fl;
    after_97:
    // 0x8007FE60: andi        $v0, $v0, 0x7F
    ctx->r2 = ctx->r2 & 0X7F;
    // 0x8007FE64: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x8007FE68: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x8007FE6C: sub.s       $f0, $f0, $f24
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f24.fl;
    // 0x8007FE70: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8007FE74: lwc1        $f2, -0x266C($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X266C);
    // 0x8007FE78: div.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f2.fl);
    // 0x8007FE7C: abs.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f20.fl = fabsf(ctx->f0.fl);
    // 0x8007FE80: jal         0x80003430
    // 0x8007FE84: add.s       $f20, $f20, $f26
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f20.fl = ctx->f20.fl + ctx->f26.fl;
    rand_recomp(rdram, ctx);
        goto after_98;
    // 0x8007FE84: add.s       $f20, $f20, $f26
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f20.fl = ctx->f20.fl + ctx->f26.fl;
    after_98:
    // 0x8007FE88: andi        $v0, $v0, 0x7F
    ctx->r2 = ctx->r2 & 0X7F;
    // 0x8007FE8C: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x8007FE90: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x8007FE94: sub.s       $f0, $f0, $f24
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f24.fl;
    // 0x8007FE98: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8007FE9C: lwc1        $f2, -0x2668($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X2668);
    // 0x8007FEA0: div.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f2.fl);
    // 0x8007FEA4: abs.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = fabsf(ctx->f0.fl);
    // 0x8007FEA8: addu        $a0, $s6, $zero
    ctx->r4 = ADD32(ctx->r22, 0);
    // 0x8007FEAC: addu        $a1, $s4, $zero
    ctx->r5 = ADD32(ctx->r20, 0);
    // 0x8007FEB0: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8007FEB4: lwc1        $f0, -0x2664($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X2664);
    // 0x8007FEB8: mfc1        $a2, $f22
    ctx->r6 = (int32_t)ctx->f22.u32l;
    // 0x8007FEBC: add.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x8007FEC0: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x8007FEC4: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8007FEC8: jal         0x80072384
    // 0x8007FECC: swc1        $f2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f2.u32l;
    func_80072384(rdram, ctx);
        goto after_99;
    // 0x8007FECC: swc1        $f2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f2.u32l;
    after_99:
    // 0x8007FED0: slt         $v0, $s0, $s5
    ctx->r2 = SIGNED(ctx->r16) < SIGNED(ctx->r21) ? 1 : 0;
    // 0x8007FED4: bne         $v0, $zero, L_8007FDC0
    if (ctx->r2 != 0) {
        // 0x8007FED8: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_8007FDC0;
    }
    // 0x8007FED8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8007FEDC: j           L_8008007C
    // 0x8007FEE0: nop

        goto L_8008007C;
    // 0x8007FEE0: nop

L_8007FEE4:
    // 0x8007FEE4: slti        $v0, $a0, 0x4
    ctx->r2 = SIGNED(ctx->r4) < 0X4 ? 1 : 0;
    // 0x8007FEE8: bne         $v0, $zero, L_8007FC9C
    if (ctx->r2 != 0) {
        // 0x8007FEEC: addiu       $s0, $s0, 0x2
        ctx->r16 = ADD32(ctx->r16, 0X2);
            goto L_8007FC9C;
    }
    // 0x8007FEEC: addiu       $s0, $s0, 0x2
    ctx->r16 = ADD32(ctx->r16, 0X2);
    // 0x8007FEF0: j           L_8008007C
    // 0x8007FEF4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8008007C;
    // 0x8007FEF4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8007FEF8:
    // 0x8007FEF8: lbu         $v1, 0x18($s4)
    ctx->r3 = MEM_BU(ctx->r20, 0X18);
    // 0x8007FEFC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8007FF00: beq         $v1, $a2, L_8007FF1C
    if (ctx->r3 == ctx->r6) {
        // 0x8007FF04: addu        $a1, $s4, $zero
        ctx->r5 = ADD32(ctx->r20, 0);
            goto L_8007FF1C;
    }
    // 0x8007FF04: addu        $a1, $s4, $zero
    ctx->r5 = ADD32(ctx->r20, 0);
    // 0x8007FF08: addiu       $v0, $zero, 0xF
    ctx->r2 = ADD32(0, 0XF);
    // 0x8007FF0C: beq         $v1, $v0, L_8007FF4C
    if (ctx->r3 == ctx->r2) {
        // 0x8007FF10: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_8007FF4C;
    }
    // 0x8007FF10: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8007FF14: j           L_8008007C
    // 0x8007FF18: nop

        goto L_8008007C;
    // 0x8007FF18: nop

L_8007FF1C:
    // 0x8007FF1C: lbu         $v0, 0x8($s4)
    ctx->r2 = MEM_BU(ctx->r20, 0X8);
    // 0x8007FF20: lbu         $a2, 0x9($s4)
    ctx->r6 = MEM_BU(ctx->r20, 0X9);
    // 0x8007FF24: lbu         $a3, 0xA($s4)
    ctx->r7 = MEM_BU(ctx->r20, 0XA);
    // 0x8007FF28: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // 0x8007FF2C: lw          $v0, 0x4($s4)
    ctx->r2 = MEM_W(ctx->r20, 0X4);
    // 0x8007FF30: sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    // 0x8007FF34: lw          $a0, 0x38($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X38);
    // 0x8007FF38: lw          $a1, 0x0($s4)
    ctx->r5 = MEM_W(ctx->r20, 0X0);
    // 0x8007FF3C: jal         0x800F9AB8
    // 0x8007FF40: nop

    func_800F9AB8(rdram, ctx);
        goto after_100;
    // 0x8007FF40: nop

    after_100:
    // 0x8007FF44: j           L_8008007C
    // 0x8007FF48: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8008007C;
    // 0x8007FF48: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8007FF4C:
    // 0x8007FF4C: lh          $a0, 0x2($s4)
    ctx->r4 = MEM_H(ctx->r20, 0X2);
    // 0x8007FF50: beq         $a0, $a2, L_8007FFC0
    if (ctx->r4 == ctx->r6) {
        // 0x8007FF54: slti        $v0, $a0, 0x2
        ctx->r2 = SIGNED(ctx->r4) < 0X2 ? 1 : 0;
            goto L_8007FFC0;
    }
    // 0x8007FF54: slti        $v0, $a0, 0x2
    ctx->r2 = SIGNED(ctx->r4) < 0X2 ? 1 : 0;
    // 0x8007FF58: beq         $v0, $zero, L_8007FF70
    if (ctx->r2 == 0) {
        // 0x8007FF5C: addiu       $v0, $zero, 0x2
        ctx->r2 = ADD32(0, 0X2);
            goto L_8007FF70;
    }
    // 0x8007FF5C: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x8007FF60: beq         $a0, $zero, L_8007FF80
    if (ctx->r4 == 0) {
        // 0x8007FF64: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_8007FF80;
    }
    // 0x8007FF64: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8007FF68: j           L_8008007C
    // 0x8007FF6C: nop

        goto L_8008007C;
    // 0x8007FF6C: nop

L_8007FF70:
    // 0x8007FF70: beq         $a0, $v0, L_80080038
    if (ctx->r4 == ctx->r2) {
        // 0x8007FF74: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80080038;
    }
    // 0x8007FF74: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8007FF78: j           L_8008007C
    // 0x8007FF7C: nop

        goto L_8008007C;
    // 0x8007FF7C: nop

L_8007FF80:
    // 0x8007FF80: lh          $v0, 0x1B4($s3)
    ctx->r2 = MEM_H(ctx->r19, 0X1B4);
    // 0x8007FF84: blez        $v0, L_80080078
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8007FF88: addu        $s1, $zero, $zero
        ctx->r17 = ADD32(0, 0);
            goto L_80080078;
    }
    // 0x8007FF88: addu        $s1, $zero, $zero
    ctx->r17 = ADD32(0, 0);
    // 0x8007FF8C: ori         $a2, $zero, 0xFFFF
    ctx->r6 = 0 | 0XFFFF;
    // 0x8007FF90: addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
L_8007FF94:
    // 0x8007FF94: lhu         $v1, 0x1B6($a0)
    ctx->r3 = MEM_HU(ctx->r4, 0X1B6);
    // 0x8007FF98: lhu         $v0, 0x0($a1)
    ctx->r2 = MEM_HU(ctx->r5, 0X0);
    // 0x8007FF9C: beql        $v1, $v0, L_8007FFA4
    if (ctx->r3 == ctx->r2) {
        // 0x8007FFA0: sh          $a2, 0x1B6($a0)
        MEM_H(0X1B6, ctx->r4) = ctx->r6;
            goto L_8007FFA4;
    }
    goto skip_7;
    // 0x8007FFA0: sh          $a2, 0x1B6($a0)
    MEM_H(0X1B6, ctx->r4) = ctx->r6;
    skip_7:
L_8007FFA4:
    // 0x8007FFA4: lh          $v0, 0x1B4($s3)
    ctx->r2 = MEM_H(ctx->r19, 0X1B4);
    // 0x8007FFA8: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x8007FFAC: slt         $v0, $s1, $v0
    ctx->r2 = SIGNED(ctx->r17) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8007FFB0: bne         $v0, $zero, L_8007FF94
    if (ctx->r2 != 0) {
        // 0x8007FFB4: addiu       $a0, $a0, 0x2
        ctx->r4 = ADD32(ctx->r4, 0X2);
            goto L_8007FF94;
    }
    // 0x8007FFB4: addiu       $a0, $a0, 0x2
    ctx->r4 = ADD32(ctx->r4, 0X2);
    // 0x8007FFB8: j           L_8008007C
    // 0x8007FFBC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8008007C;
    // 0x8007FFBC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8007FFC0:
    // 0x8007FFC0: addu        $s1, $zero, $zero
    ctx->r17 = ADD32(0, 0);
    // 0x8007FFC4: ori         $s2, $zero, 0xFFFF
    ctx->r18 = 0 | 0XFFFF;
    // 0x8007FFC8: addu        $s0, $s3, $zero
    ctx->r16 = ADD32(ctx->r19, 0);
    // 0x8007FFCC: addu        $v0, $s2, $zero
    ctx->r2 = ADD32(ctx->r18, 0);
    // 0x8007FFD0: sh          $v0, 0x1F6($s3)
    MEM_H(0X1F6, ctx->r19) = ctx->r2;
    // 0x8007FFD4: sb          $zero, 0xF8($s3)
    MEM_B(0XF8, ctx->r19) = 0;
L_8007FFD8:
    // 0x8007FFD8: lhu         $v0, 0x10C($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X10C);
    // 0x8007FFDC: beql        $v0, $s2, L_8007FFF4
    if (ctx->r2 == ctx->r18) {
        // 0x8007FFE0: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_8007FFF4;
    }
    goto skip_8;
    // 0x8007FFE0: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    skip_8:
    // 0x8007FFE4: jal         0x8003ED74
    // 0x8007FFE8: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    func_8003ED74(rdram, ctx);
        goto after_101;
    // 0x8007FFE8: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    after_101:
    // 0x8007FFEC: sh          $s2, 0x10C($s0)
    MEM_H(0X10C, ctx->r16) = ctx->r18;
    // 0x8007FFF0: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
L_8007FFF4:
    // 0x8007FFF4: slti        $v0, $s1, 0x4
    ctx->r2 = SIGNED(ctx->r17) < 0X4 ? 1 : 0;
    // 0x8007FFF8: bne         $v0, $zero, L_8007FFD8
    if (ctx->r2 != 0) {
        // 0x8007FFFC: addiu       $s0, $s0, 0x2
        ctx->r16 = ADD32(ctx->r16, 0X2);
            goto L_8007FFD8;
    }
    // 0x8007FFFC: addiu       $s0, $s0, 0x2
    ctx->r16 = ADD32(ctx->r16, 0X2);
    // 0x80080000: lw          $v1, 0x34($s3)
    ctx->r3 = MEM_W(ctx->r19, 0X34);
    // 0x80080004: lw          $v0, 0xD0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0XD0);
    // 0x80080008: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // 0x8008000C: lw          $v0, 0x34($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X34);
    // 0x80080010: lw          $v0, 0xD4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0XD4);
    // 0x80080014: sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    // 0x80080018: lw          $a0, 0xC8($v1)
    ctx->r4 = MEM_W(ctx->r3, 0XC8);
    // 0x8008001C: lw          $a1, 0xCC($v1)
    ctx->r5 = MEM_W(ctx->r3, 0XCC);
    // 0x80080020: lw          $a2, 0xC0($v1)
    ctx->r6 = MEM_W(ctx->r3, 0XC0);
    // 0x80080024: lw          $a3, 0xC4($v1)
    ctx->r7 = MEM_W(ctx->r3, 0XC4);
    // 0x80080028: jal         0x80065914
    // 0x8008002C: nop

    datItemSetObjectiveBooleanCount(rdram, ctx);
        goto after_102;
    // 0x8008002C: nop

    after_102:
    // 0x80080030: j           L_8008007C
    // 0x80080034: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8008007C;
    // 0x80080034: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80080038:
    // 0x80080038: addu        $s1, $zero, $zero
    ctx->r17 = ADD32(0, 0);
    // 0x8008003C: ori         $a2, $zero, 0xFFFF
    ctx->r6 = 0 | 0XFFFF;
    // 0x80080040: addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
L_80080044:
    // 0x80080044: lhu         $v1, 0x104($a0)
    ctx->r3 = MEM_HU(ctx->r4, 0X104);
    // 0x80080048: lhu         $v0, 0x0($a1)
    ctx->r2 = MEM_HU(ctx->r5, 0X0);
    // 0x8008004C: beql        $v1, $v0, L_80080054
    if (ctx->r3 == ctx->r2) {
        // 0x80080050: sh          $a2, 0x104($a0)
        MEM_H(0X104, ctx->r4) = ctx->r6;
            goto L_80080054;
    }
    goto skip_9;
    // 0x80080050: sh          $a2, 0x104($a0)
    MEM_H(0X104, ctx->r4) = ctx->r6;
    skip_9:
L_80080054:
    // 0x80080054: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80080058: slti        $v0, $s1, 0x4
    ctx->r2 = SIGNED(ctx->r17) < 0X4 ? 1 : 0;
    // 0x8008005C: bne         $v0, $zero, L_80080044
    if (ctx->r2 != 0) {
        // 0x80080060: addiu       $a0, $a0, 0x2
        ctx->r4 = ADD32(ctx->r4, 0X2);
            goto L_80080044;
    }
    // 0x80080060: addiu       $a0, $a0, 0x2
    ctx->r4 = ADD32(ctx->r4, 0X2);
    // 0x80080064: j           L_8008007C
    // 0x80080068: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8008007C;
    // 0x80080068: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8008006C:
    // 0x8008006C: addu        $a0, $s7, $zero
    ctx->r4 = ADD32(ctx->r23, 0);
    // 0x80080070: jal         0x800EFD80
    // 0x80080074: addu        $a1, $s4, $zero
    ctx->r5 = ADD32(ctx->r20, 0);
    func_800EFD80(rdram, ctx);
        goto after_103;
    // 0x80080074: addu        $a1, $s4, $zero
    ctx->r5 = ADD32(ctx->r20, 0);
    after_103:
L_80080078:
    // 0x80080078: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8008007C:
    // 0x8008007C: lw          $ra, 0x11C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X11C);
    // 0x80080080: lw          $fp, 0x118($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X118);
    // 0x80080084: lw          $s7, 0x114($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X114);
    // 0x80080088: lw          $s6, 0x110($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X110);
    // 0x8008008C: lw          $s5, 0x10C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X10C);
    // 0x80080090: lw          $s4, 0x108($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X108);
    // 0x80080094: lw          $s3, 0x104($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X104);
    // 0x80080098: lw          $s2, 0x100($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X100);
    // 0x8008009C: lw          $s1, 0xFC($sp)
    ctx->r17 = MEM_W(ctx->r29, 0XFC);
    // 0x800800A0: lw          $s0, 0xF8($sp)
    ctx->r16 = MEM_W(ctx->r29, 0XF8);
    // 0x800800A4: ldc1        $f28, 0x140($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0X140);
    // 0x800800A8: ldc1        $f26, 0x138($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X138);
    // 0x800800AC: ldc1        $f24, 0x130($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X130);
    // 0x800800B0: ldc1        $f22, 0x128($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X128);
    // 0x800800B4: ldc1        $f20, 0x120($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X120);
    // 0x800800B8: jr          $ra
    // 0x800800BC: addiu       $sp, $sp, 0x148
    ctx->r29 = ADD32(ctx->r29, 0X148);
    return;
    // 0x800800BC: addiu       $sp, $sp, 0x148
    ctx->r29 = ADD32(ctx->r29, 0X148);
;}
RECOMP_FUNC void func_800800C0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800800C0: addiu       $sp, $sp, -0x1B0
    ctx->r29 = ADD32(ctx->r29, -0X1B0);
    // 0x800800C4: sw          $s3, 0x194($sp)
    MEM_W(0X194, ctx->r29) = ctx->r19;
    // 0x800800C8: addu        $s3, $a0, $zero
    ctx->r19 = ADD32(ctx->r4, 0);
    // 0x800800CC: sw          $s0, 0x188($sp)
    MEM_W(0X188, ctx->r29) = ctx->r16;
    // 0x800800D0: andi        $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 & 0XFFFF;
    // 0x800800D4: addiu       $v1, $a1, -0x1
    ctx->r3 = ADD32(ctx->r5, -0X1);
    // 0x800800D8: sltiu       $v0, $v1, 0x7
    ctx->r2 = ctx->r3 < 0X7 ? 1 : 0;
    // 0x800800DC: sw          $ra, 0x198($sp)
    MEM_W(0X198, ctx->r29) = ctx->r31;
    // 0x800800E0: sw          $s2, 0x190($sp)
    MEM_W(0X190, ctx->r29) = ctx->r18;
    // 0x800800E4: sw          $s1, 0x18C($sp)
    MEM_W(0X18C, ctx->r29) = ctx->r17;
    // 0x800800E8: sdc1        $f22, 0x1A8($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X1A8, ctx->r29);
    // 0x800800EC: sdc1        $f20, 0x1A0($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X1A0, ctx->r29);
    // 0x800800F0: lw          $s2, 0x4($s3)
    ctx->r18 = MEM_W(ctx->r19, 0X4);
    // 0x800800F4: beq         $v0, $zero, L_80081328
    if (ctx->r2 == 0) {
        // 0x800800F8: addu        $s0, $a2, $zero
        ctx->r16 = ADD32(ctx->r6, 0);
            goto L_80081328;
    }
    // 0x800800F8: addu        $s0, $a2, $zero
    ctx->r16 = ADD32(ctx->r6, 0);
    // 0x800800FC: lui         $v0, 0x8004
    ctx->r2 = S32(0X8004 << 16);
    // 0x80080100: addiu       $v0, $v0, -0x2648
    ctx->r2 = ADD32(ctx->r2, -0X2648);
    // 0x80080104: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x80080108: addu        $v1, $v1, $v0
    gpr jr_addend_80080110 = ctx->r3;
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x8008010C: lw          $v0, 0x0($v1)
    ctx->r2 = ADD32(ctx->r3, 0X0);
    // 0x80080110: jr          $v0
    // 0x80080114: nop

    switch (jr_addend_80080110 >> 2) {
        case 0: goto L_80080118; break;
        case 1: goto L_800803CC; break;
        case 2: goto L_800803E8; break;
        case 3: goto L_80080884; break;
        case 4: goto L_800811EC; break;
        case 5: goto L_80081328; break;
        case 6: goto L_8008131C; break;
        default: switch_error(__func__, 0x80080110, 0x8003D9B8);
    }
    // 0x80080114: nop

L_80080118:
    // 0x80080118: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8008011C: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x80080120: sw          $v0, 0x34($s2)
    MEM_W(0X34, ctx->r18) = ctx->r2;
    // 0x80080124: lh          $v1, 0x3A($s0)
    ctx->r3 = MEM_H(ctx->r16, 0X3A);
    // 0x80080128: sltiu       $v0, $v1, 0x5
    ctx->r2 = ctx->r3 < 0X5 ? 1 : 0;
    // 0x8008012C: beq         $v0, $zero, L_80080188
    if (ctx->r2 == 0) {
        // 0x80080130: addu        $s1, $s0, $zero
        ctx->r17 = ADD32(ctx->r16, 0);
            goto L_80080188;
    }
    // 0x80080130: addu        $s1, $s0, $zero
    ctx->r17 = ADD32(ctx->r16, 0);
    // 0x80080134: lui         $v0, 0x8004
    ctx->r2 = S32(0X8004 << 16);
    // 0x80080138: addiu       $v0, $v0, -0x2628
    ctx->r2 = ADD32(ctx->r2, -0X2628);
    // 0x8008013C: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x80080140: addu        $v1, $v1, $v0
    gpr jr_addend_80080148 = ctx->r3;
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x80080144: lw          $v0, 0x0($v1)
    ctx->r2 = ADD32(ctx->r3, 0X0);
    // 0x80080148: jr          $v0
    // 0x8008014C: nop

    switch (jr_addend_80080148 >> 2) {
        case 0: goto L_80080150; break;
        case 1: goto L_8008015C; break;
        case 2: goto L_80080168; break;
        case 3: goto L_80080174; break;
        case 4: goto L_80080180; break;
        default: switch_error(__func__, 0x80080148, 0x8003D9D8);
    }
    // 0x8008014C: nop

L_80080150:
    // 0x80080150: lui         $v0, 0x8004
    ctx->r2 = S32(0X8004 << 16);
    // 0x80080154: j           L_80080188
    // 0x80080158: addiu       $a0, $v0, -0x2660
    ctx->r4 = ADD32(ctx->r2, -0X2660);
        goto L_80080188;
    // 0x80080158: addiu       $a0, $v0, -0x2660
    ctx->r4 = ADD32(ctx->r2, -0X2660);
L_8008015C:
    // 0x8008015C: lui         $v0, 0x8004
    ctx->r2 = S32(0X8004 << 16);
    // 0x80080160: j           L_80080188
    // 0x80080164: addiu       $a0, $v0, -0x265C
    ctx->r4 = ADD32(ctx->r2, -0X265C);
        goto L_80080188;
    // 0x80080164: addiu       $a0, $v0, -0x265C
    ctx->r4 = ADD32(ctx->r2, -0X265C);
L_80080168:
    // 0x80080168: lui         $v0, 0x8004
    ctx->r2 = S32(0X8004 << 16);
    // 0x8008016C: j           L_80080188
    // 0x80080170: addiu       $a0, $v0, -0x2658
    ctx->r4 = ADD32(ctx->r2, -0X2658);
        goto L_80080188;
    // 0x80080170: addiu       $a0, $v0, -0x2658
    ctx->r4 = ADD32(ctx->r2, -0X2658);
L_80080174:
    // 0x80080174: lui         $v0, 0x8004
    ctx->r2 = S32(0X8004 << 16);
    // 0x80080178: j           L_80080188
    // 0x8008017C: addiu       $a0, $v0, -0x2654
    ctx->r4 = ADD32(ctx->r2, -0X2654);
        goto L_80080188;
    // 0x8008017C: addiu       $a0, $v0, -0x2654
    ctx->r4 = ADD32(ctx->r2, -0X2654);
L_80080180:
    // 0x80080180: lui         $v0, 0x8004
    ctx->r2 = S32(0X8004 << 16);
    // 0x80080184: addiu       $a0, $v0, -0x2650
    ctx->r4 = ADD32(ctx->r2, -0X2650);
L_80080188:
    // 0x80080188: jal         0x80056EB0
    // 0x8008018C: nop

    walkMeshdef0List(rdram, ctx);
        goto after_0;
    // 0x8008018C: nop

    after_0:
    // 0x80080190: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // 0x80080194: addiu       $v1, $s1, 0x4
    ctx->r3 = ADD32(ctx->r17, 0X4);
    // 0x80080198: sw          $v0, 0x30($s2)
    MEM_W(0X30, ctx->r18) = ctx->r2;
    // 0x8008019C: lhu         $v0, 0x3A($s1)
    ctx->r2 = MEM_HU(ctx->r17, 0X3A);
    // 0x800801A0: addiu       $a1, $s1, 0x34
    ctx->r5 = ADD32(ctx->r17, 0X34);
    // 0x800801A4: sh          $v0, 0xA4($s2)
    MEM_H(0XA4, ctx->r18) = ctx->r2;
L_800801A8:
    // 0x800801A8: lw          $t0, 0x0($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X0);
    // 0x800801AC: lw          $t1, 0x4($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X4);
    // 0x800801B0: lw          $t2, 0x8($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X8);
    // 0x800801B4: lw          $t3, 0xC($v1)
    ctx->r11 = MEM_W(ctx->r3, 0XC);
    // 0x800801B8: sw          $t0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r8;
    // 0x800801BC: sw          $t1, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r9;
    // 0x800801C0: sw          $t2, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r10;
    // 0x800801C4: sw          $t3, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r11;
    // 0x800801C8: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
    // 0x800801CC: bne         $v1, $a1, L_800801A8
    if (ctx->r3 != ctx->r5) {
        // 0x800801D0: addiu       $a0, $a0, 0x10
        ctx->r4 = ADD32(ctx->r4, 0X10);
            goto L_800801A8;
    }
    // 0x800801D0: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    // 0x800801D4: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x800801D8: lw          $v0, 0x30($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X30);
    // 0x800801DC: swc1        $f20, 0x2C($s2)
    MEM_W(0X2C, ctx->r18) = ctx->f20.u32l;
    // 0x800801E0: swc1        $f20, 0x28($s2)
    MEM_W(0X28, ctx->r18) = ctx->f20.u32l;
    // 0x800801E4: swc1        $f20, 0x24($s2)
    MEM_W(0X24, ctx->r18) = ctx->f20.u32l;
    // 0x800801E8: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x800801EC: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x800801F0: lwc1        $f22, -0x2614($at)
    ctx->f22.u32l = MEM_W(ctx->r1, -0X2614);
    // 0x800801F4: lwc1        $f0, 0x34($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X34);
    // 0x800801F8: lwc1        $f2, 0x34($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0X34);
    // 0x800801FC: div.s       $f0, $f22, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = DIV_S(ctx->f22.fl, ctx->f0.fl);
    // 0x80080200: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x80080204: addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    // 0x80080208: lw          $a0, 0x30($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X30);
    // 0x8008020C: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80080210: addiu       $a0, $a0, 0x28
    ctx->r4 = ADD32(ctx->r4, 0X28);
    // 0x80080214: jal         0x80059B50
    // 0x80080218: sw          $a2, 0x84($s2)
    MEM_W(0X84, ctx->r18) = ctx->r6;
    func_80059B50(rdram, ctx);
        goto after_1;
    // 0x80080218: sw          $a2, 0x84($s2)
    MEM_W(0X84, ctx->r18) = ctx->r6;
    after_1:
    // 0x8008021C: lui         $s0, 0x8014
    ctx->r16 = S32(0X8014 << 16);
    // 0x80080220: sw          $s2, 0x8($s3)
    MEM_W(0X8, ctx->r19) = ctx->r18;
    // 0x80080224: lw          $v0, 0x30($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X30);
    // 0x80080228: addiu       $s0, $s0, -0x6AA0
    ctx->r16 = ADD32(ctx->r16, -0X6AA0);
    // 0x8008022C: sw          $v0, 0xC($s3)
    MEM_W(0XC, ctx->r19) = ctx->r2;
    // 0x80080230: lhu         $a0, 0x1C($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X1C);
    // 0x80080234: jal         0x8003E684
    // 0x80080238: addu        $a1, $s3, $zero
    ctx->r5 = ADD32(ctx->r19, 0);
    func_8003E684(rdram, ctx);
        goto after_2;
    // 0x80080238: addu        $a1, $s3, $zero
    ctx->r5 = ADD32(ctx->r19, 0);
    after_2:
    // 0x8008023C: sh          $v0, 0xA8($s2)
    MEM_H(0XA8, ctx->r18) = ctx->r2;
    // 0x80080240: lhu         $a0, 0xC($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0XC);
    // 0x80080244: jal         0x8003E684
    // 0x80080248: addu        $a1, $s3, $zero
    ctx->r5 = ADD32(ctx->r19, 0);
    func_8003E684(rdram, ctx);
        goto after_3;
    // 0x80080248: addu        $a1, $s3, $zero
    ctx->r5 = ADD32(ctx->r19, 0);
    after_3:
    // 0x8008024C: lui         $s0, 0x800A
    ctx->r16 = S32(0X800A << 16);
    // 0x80080250: lw          $a0, 0x30($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X30);
    // 0x80080254: lh          $v1, 0xA4($s2)
    ctx->r3 = MEM_H(ctx->r18, 0XA4);
    // 0x80080258: addiu       $s0, $s0, 0xD9C
    ctx->r16 = ADD32(ctx->r16, 0XD9C);
    // 0x8008025C: sh          $v0, 0xAA($s2)
    MEM_H(0XAA, ctx->r18) = ctx->r2;
    // 0x80080260: sll         $v0, $v1, 4
    ctx->r2 = S32(ctx->r3 << 4);
    // 0x80080264: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x80080268: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8008026C: addu        $v0, $v0, $s0
    ctx->r2 = ADD32(ctx->r2, ctx->r16);
    // 0x80080270: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    // 0x80080274: jal         0x80059434
    // 0x80080278: addiu       $a2, $s2, 0x48
    ctx->r6 = ADD32(ctx->r18, 0X48);
    func_80059434(rdram, ctx);
        goto after_4;
    // 0x80080278: addiu       $a2, $s2, 0x48
    ctx->r6 = ADD32(ctx->r18, 0X48);
    after_4:
    // 0x8008027C: lw          $a0, 0x30($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X30);
    // 0x80080280: lh          $v1, 0xA4($s2)
    ctx->r3 = MEM_H(ctx->r18, 0XA4);
    // 0x80080284: sw          $v0, 0x3C($s2)
    MEM_W(0X3C, ctx->r18) = ctx->r2;
    // 0x80080288: sll         $v0, $v1, 4
    ctx->r2 = S32(ctx->r3 << 4);
    // 0x8008028C: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x80080290: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80080294: addu        $v0, $v0, $s0
    ctx->r2 = ADD32(ctx->r2, ctx->r16);
    // 0x80080298: lw          $a1, 0x4($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X4);
    // 0x8008029C: jal         0x80059434
    // 0x800802A0: addiu       $a2, $s2, 0x4C
    ctx->r6 = ADD32(ctx->r18, 0X4C);
    func_80059434(rdram, ctx);
        goto after_5;
    // 0x800802A0: addiu       $a2, $s2, 0x4C
    ctx->r6 = ADD32(ctx->r18, 0X4C);
    after_5:
    // 0x800802A4: lw          $a0, 0x30($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X30);
    // 0x800802A8: lh          $v1, 0xA4($s2)
    ctx->r3 = MEM_H(ctx->r18, 0XA4);
    // 0x800802AC: sw          $v0, 0x40($s2)
    MEM_W(0X40, ctx->r18) = ctx->r2;
    // 0x800802B0: sll         $v0, $v1, 4
    ctx->r2 = S32(ctx->r3 << 4);
    // 0x800802B4: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x800802B8: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800802BC: addu        $v0, $v0, $s0
    ctx->r2 = ADD32(ctx->r2, ctx->r16);
    // 0x800802C0: lw          $a1, 0x8($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X8);
    // 0x800802C4: jal         0x80059434
    // 0x800802C8: addiu       $a2, $s2, 0x50
    ctx->r6 = ADD32(ctx->r18, 0X50);
    func_80059434(rdram, ctx);
        goto after_6;
    // 0x800802C8: addiu       $a2, $s2, 0x50
    ctx->r6 = ADD32(ctx->r18, 0X50);
    after_6:
    // 0x800802CC: lw          $v1, 0x30($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X30);
    // 0x800802D0: sw          $v0, 0x44($s2)
    MEM_W(0X44, ctx->r18) = ctx->r2;
    // 0x800802D4: swc1        $f20, 0x8C($s2)
    MEM_W(0X8C, ctx->r18) = ctx->f20.u32l;
    // 0x800802D8: swc1        $f20, 0x90($s2)
    MEM_W(0X90, ctx->r18) = ctx->f20.u32l;
    // 0x800802DC: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x800802E0: lwc1        $f2, 0x84($s2)
    ctx->f2.u32l = MEM_W(ctx->r18, 0X84);
    // 0x800802E4: lwc1        $f0, 0x44($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X44);
    // 0x800802E8: addiu       $a0, $s2, 0x38
    ctx->r4 = ADD32(ctx->r18, 0X38);
    // 0x800802EC: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x800802F0: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x800802F4: addu        $a2, $s3, $zero
    ctx->r6 = ADD32(ctx->r19, 0);
    // 0x800802F8: lui         $a3, 0x8008
    ctx->r7 = S32(0X8008 << 16);
    // 0x800802FC: addiu       $a3, $a3, -0x3D60
    ctx->r7 = ADD32(ctx->r7, -0X3D60);
    // 0x80080300: swc1        $f0, 0x88($s2)
    MEM_W(0X88, ctx->r18) = ctx->f0.u32l;
    // 0x80080304: jal         0x800EC588
    // 0x80080308: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    func_800EC588(rdram, ctx);
        goto after_7;
    // 0x80080308: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_7:
    // 0x8008030C: lhu         $v0, 0x38($s1)
    ctx->r2 = MEM_HU(ctx->r17, 0X38);
    // 0x80080310: sh          $v0, 0xA6($s2)
    MEM_H(0XA6, ctx->r18) = ctx->r2;
    // 0x80080314: lhu         $a0, 0x38($s1)
    ctx->r4 = MEM_HU(ctx->r17, 0X38);
    // 0x80080318: jal         0x8004015C
    // 0x8008031C: nop

    func_8004015C(rdram, ctx);
        goto after_8;
    // 0x8008031C: nop

    after_8:
    // 0x80080320: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    // 0x80080324: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    // 0x80080328: mfc1        $a2, $f22
    ctx->r6 = (int32_t)ctx->f22.u32l;
    // 0x8008032C: jal         0x80059B50
    // 0x80080330: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    func_80059B50(rdram, ctx);
        goto after_9;
    // 0x80080330: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    after_9:
    // 0x80080334: addiu       $s1, $sp, 0x58
    ctx->r17 = ADD32(ctx->r29, 0X58);
    // 0x80080338: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x8008033C: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    // 0x80080340: swc1        $f20, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f20.u32l;
    // 0x80080344: swc1        $f20, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f20.u32l;
    // 0x80080348: jal         0x8001C774
    // 0x8008034C: swc1        $f20, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f20.u32l;
    func_8001C774(rdram, ctx);
        goto after_10;
    // 0x8008034C: swc1        $f20, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f20.u32l;
    after_10:
    // 0x80080350: lwc1        $f0, 0x0($s2)
    ctx->f0.u32l = MEM_W(ctx->r18, 0X0);
    // 0x80080354: lwc1        $f2, 0x0($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X0);
    // 0x80080358: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x8008035C: swc1        $f0, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->f0.u32l;
    // 0x80080360: lwc1        $f0, 0x4($s2)
    ctx->f0.u32l = MEM_W(ctx->r18, 0X4);
    // 0x80080364: lwc1        $f2, 0x4($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X4);
    // 0x80080368: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x8008036C: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x80080370: swc1        $f0, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->f0.u32l;
    // 0x80080374: lwc1        $f0, 0x8($s2)
    ctx->f0.u32l = MEM_W(ctx->r18, 0X8);
    // 0x80080378: lwc1        $f2, 0x8($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8008037C: addiu       $a1, $sp, 0x88
    ctx->r5 = ADD32(ctx->r29, 0X88);
    // 0x80080380: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x80080384: addiu       $s0, $sp, 0x98
    ctx->r16 = ADD32(ctx->r29, 0X98);
    // 0x80080388: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    // 0x8008038C: jal         0x800193E8
    // 0x80080390: swc1        $f0, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->f0.u32l;
    func_800193E8(rdram, ctx);
        goto after_11;
    // 0x80080390: swc1        $f0, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->f0.u32l;
    after_11:
    // 0x80080394: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x80080398: addiu       $a1, $s2, 0xC
    ctx->r5 = ADD32(ctx->r18, 0XC);
    // 0x8008039C: jal         0x800193E8
    // 0x800803A0: addiu       $a2, $sp, 0xA4
    ctx->r6 = ADD32(ctx->r29, 0XA4);
    func_800193E8(rdram, ctx);
        goto after_12;
    // 0x800803A0: addiu       $a2, $sp, 0xA4
    ctx->r6 = ADD32(ctx->r29, 0XA4);
    after_12:
    // 0x800803A4: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x800803A8: addiu       $a1, $s2, 0x18
    ctx->r5 = ADD32(ctx->r18, 0X18);
    // 0x800803AC: jal         0x800193E8
    // 0x800803B0: addiu       $a2, $sp, 0xB0
    ctx->r6 = ADD32(ctx->r29, 0XB0);
    func_800193E8(rdram, ctx);
        goto after_13;
    // 0x800803B0: addiu       $a2, $sp, 0xB0
    ctx->r6 = ADD32(ctx->r29, 0XB0);
    after_13:
    // 0x800803B4: addiu       $a0, $s2, 0x54
    ctx->r4 = ADD32(ctx->r18, 0X54);
    // 0x800803B8: mfc1        $a2, $f22
    ctx->r6 = (int32_t)ctx->f22.u32l;
    // 0x800803BC: jal         0x80059B50
    // 0x800803C0: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    func_80059B50(rdram, ctx);
        goto after_14;
    // 0x800803C0: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    after_14:
    // 0x800803C4: j           L_8008132C
    // 0x800803C8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8008132C;
    // 0x800803C8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800803CC:
    // 0x800803CC: jal         0x800EC684
    // 0x800803D0: addiu       $a0, $s2, 0x38
    ctx->r4 = ADD32(ctx->r18, 0X38);
    func_800EC684(rdram, ctx);
        goto after_15;
    // 0x800803D0: addiu       $a0, $s2, 0x38
    ctx->r4 = ADD32(ctx->r18, 0X38);
    after_15:
    // 0x800803D4: lw          $a0, 0x30($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X30);
    // 0x800803D8: jal         0x8005779C
    // 0x800803DC: nop

    func_8005779C(rdram, ctx);
        goto after_16;
    // 0x800803DC: nop

    after_16:
    // 0x800803E0: j           L_8008132C
    // 0x800803E4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8008132C;
    // 0x800803E4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800803E8:
    // 0x800803E8: lhu         $a0, 0xA6($s2)
    ctx->r4 = MEM_HU(ctx->r18, 0XA6);
    // 0x800803EC: lwc1        $f22, 0x0($s0)
    ctx->f22.u32l = MEM_W(ctx->r16, 0X0);
    // 0x800803F0: jal         0x8004015C
    // 0x800803F4: nop

    func_8004015C(rdram, ctx);
        goto after_17;
    // 0x800803F4: nop

    after_17:
    // 0x800803F8: addiu       $s0, $sp, 0xC8
    ctx->r16 = ADD32(ctx->r29, 0XC8);
    // 0x800803FC: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x80080400: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80080404: lwc1        $f20, -0x2610($at)
    ctx->f20.u32l = MEM_W(ctx->r1, -0X2610);
    // 0x80080408: addu        $s1, $v0, $zero
    ctx->r17 = ADD32(ctx->r2, 0);
    // 0x8008040C: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x80080410: jal         0x80059B50
    // 0x80080414: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    func_80059B50(rdram, ctx);
        goto after_18;
    // 0x80080414: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    after_18:
    // 0x80080418: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x8008041C: addiu       $a1, $s2, 0x54
    ctx->r5 = ADD32(ctx->r18, 0X54);
    // 0x80080420: addiu       $s0, $sp, 0xF8
    ctx->r16 = ADD32(ctx->r29, 0XF8);
    // 0x80080424: jal         0x800191C4
    // 0x80080428: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    func_800191C4(rdram, ctx);
        goto after_19;
    // 0x80080428: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    after_19:
    // 0x8008042C: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // 0x80080430: jal         0x80059D18
    // 0x80080434: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    func_80059D18(rdram, ctx);
        goto after_20;
    // 0x80080434: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    after_20:
    // 0x80080438: lw          $t0, 0x24($s1)
    ctx->r8 = MEM_W(ctx->r17, 0X24);
    // 0x8008043C: lw          $t1, 0x28($s1)
    ctx->r9 = MEM_W(ctx->r17, 0X28);
    // 0x80080440: lw          $t2, 0x2C($s1)
    ctx->r10 = MEM_W(ctx->r17, 0X2C);
    // 0x80080444: sw          $t0, 0x24($s2)
    MEM_W(0X24, ctx->r18) = ctx->r8;
    // 0x80080448: sw          $t1, 0x28($s2)
    MEM_W(0X28, ctx->r18) = ctx->r9;
    // 0x8008044C: sw          $t2, 0x2C($s2)
    MEM_W(0X2C, ctx->r18) = ctx->r10;
    // 0x80080450: lh          $v1, 0xAC($s2)
    ctx->r3 = MEM_H(ctx->r18, 0XAC);
    // 0x80080454: beq         $v1, $zero, L_8008046C
    if (ctx->r3 == 0) {
        // 0x80080458: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_8008046C;
    }
    // 0x80080458: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8008045C: beq         $v1, $v0, L_80080614
    if (ctx->r3 == ctx->r2) {
        // 0x80080460: nop
    
            goto L_80080614;
    }
    // 0x80080460: nop

    // 0x80080464: j           L_80080870
    // 0x80080468: nop

        goto L_80080870;
    // 0x80080468: nop

L_8008046C:
    // 0x8008046C: lwc1        $f2, 0x98($s2)
    ctx->f2.u32l = MEM_W(ctx->r18, 0X98);
    // 0x80080470: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80080474: lwc1        $f0, -0x260C($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X260C);
    // 0x80080478: c.lt.s      $f2, $f20
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f2.fl < ctx->f20.fl;
    // 0x8008047C: mul.s       $f0, $f22, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = MUL_S(ctx->f22.fl, ctx->f0.fl);
    // 0x80080480: bc1f        L_800804E8
    if (!c1cs) {
        // 0x80080484: nop
    
            goto L_800804E8;
    }
    // 0x80080484: nop

    // 0x80080488: add.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x8008048C: c.lt.s      $f20, $f2
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f20.fl < ctx->f2.fl;
    // 0x80080490: nop

    // 0x80080494: bc1f        L_800804A8
    if (!c1cs) {
        // 0x80080498: swc1        $f2, 0x98($s2)
        MEM_W(0X98, ctx->r18) = ctx->f2.u32l;
            goto L_800804A8;
    }
    // 0x80080498: swc1        $f2, 0x98($s2)
    MEM_W(0X98, ctx->r18) = ctx->f2.u32l;
    // 0x8008049C: swc1        $f20, 0x98($s2)
    MEM_W(0X98, ctx->r18) = ctx->f20.u32l;
    // 0x800804A0: j           L_800804E8
    // 0x800804A4: sw          $zero, 0x9C($s2)
    MEM_W(0X9C, ctx->r18) = 0;
        goto L_800804E8;
    // 0x800804A4: sw          $zero, 0x9C($s2)
    MEM_W(0X9C, ctx->r18) = 0;
L_800804A8:
    // 0x800804A8: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x800804AC: lwc1        $f0, -0x2608($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X2608);
    // 0x800804B0: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x800804B4: nop

    // 0x800804B8: bc1fl       L_800804D4
    if (!c1cs) {
        // 0x800804BC: sub.s       $f0, $f2, $f0
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f2.fl - ctx->f0.fl;
            goto L_800804D4;
    }
    goto skip_0;
    // 0x800804BC: sub.s       $f0, $f2, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f2.fl - ctx->f0.fl;
    skip_0:
    // 0x800804C0: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x800804C4: lwc1        $f0, -0x2604($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X2604);
    // 0x800804C8: mul.s       $f0, $f2, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x800804CC: j           L_800804E8
    // 0x800804D0: swc1        $f0, 0x9C($s2)
    MEM_W(0X9C, ctx->r18) = ctx->f0.u32l;
        goto L_800804E8;
    // 0x800804D0: swc1        $f0, 0x9C($s2)
    MEM_W(0X9C, ctx->r18) = ctx->f0.u32l;
L_800804D4:
    // 0x800804D4: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x800804D8: lwc1        $f2, -0x2600($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X2600);
    // 0x800804DC: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x800804E0: sub.s       $f0, $f20, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f20.fl - ctx->f0.fl;
    // 0x800804E4: swc1        $f0, 0x9C($s2)
    MEM_W(0X9C, ctx->r18) = ctx->f0.u32l;
L_800804E8:
    // 0x800804E8: lw          $a0, 0x38($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X38);
    // 0x800804EC: lw          $v0, 0x34($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X34);
    // 0x800804F0: mfc1        $a3, $f22
    ctx->r7 = (int32_t)ctx->f22.u32l;
    // 0x800804F4: lw          $a1, 0x7C($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X7C);
    // 0x800804F8: lw          $a2, 0x80($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X80);
    // 0x800804FC: jal         0x800EFDE0
    // 0x80080500: addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
    func_800EFDE0(rdram, ctx);
        goto after_21;
    // 0x80080500: addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
    after_21:
    // 0x80080504: mfc1        $a1, $f22
    ctx->r5 = (int32_t)ctx->f22.u32l;
    // 0x80080508: jal         0x8007CD84
    // 0x8008050C: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    func_8007CD84(rdram, ctx);
        goto after_22;
    // 0x8008050C: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    after_22:
    // 0x80080510: lw          $a0, 0x38($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X38);
    // 0x80080514: jal         0x800F06BC
    // 0x80080518: nop

    func_800F06BC(rdram, ctx);
        goto after_23;
    // 0x80080518: nop

    after_23:
    // 0x8008051C: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x80080520: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x80080524: bne         $v0, $v1, L_800805F4
    if (ctx->r2 != ctx->r3) {
        // 0x80080528: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_800805F4;
    }
    // 0x80080528: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8008052C: addiu       $v1, $sp, 0x128
    ctx->r3 = ADD32(ctx->r29, 0X128);
    // 0x80080530: addu        $v0, $s2, $zero
    ctx->r2 = ADD32(ctx->r18, 0);
    // 0x80080534: addiu       $a0, $s2, 0x30
    ctx->r4 = ADD32(ctx->r18, 0X30);
L_80080538:
    // 0x80080538: lw          $t0, 0x0($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X0);
    // 0x8008053C: lw          $t1, 0x4($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X4);
    // 0x80080540: lw          $t2, 0x8($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X8);
    // 0x80080544: lw          $t3, 0xC($v0)
    ctx->r11 = MEM_W(ctx->r2, 0XC);
    // 0x80080548: sw          $t0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r8;
    // 0x8008054C: sw          $t1, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r9;
    // 0x80080550: sw          $t2, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r10;
    // 0x80080554: sw          $t3, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r11;
    // 0x80080558: addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
    // 0x8008055C: bne         $v0, $a0, L_80080538
    if (ctx->r2 != ctx->r4) {
        // 0x80080560: addiu       $v1, $v1, 0x10
        ctx->r3 = ADD32(ctx->r3, 0X10);
            goto L_80080538;
    }
    // 0x80080560: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
    // 0x80080564: lw          $a1, 0x90($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X90);
    // 0x80080568: jal         0x8001CC3C
    // 0x8008056C: addiu       $a0, $sp, 0x158
    ctx->r4 = ADD32(ctx->r29, 0X158);
    func_8001CC3C(rdram, ctx);
        goto after_24;
    // 0x8008056C: addiu       $a0, $sp, 0x158
    ctx->r4 = ADD32(ctx->r29, 0X158);
    after_24:
    // 0x80080570: lw          $a1, 0x8C($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X8C);
    // 0x80080574: jal         0x8001CCCC
    // 0x80080578: addiu       $a0, $sp, 0x158
    ctx->r4 = ADD32(ctx->r29, 0X158);
    func_8001CCCC(rdram, ctx);
        goto after_25;
    // 0x80080578: addiu       $a0, $sp, 0x158
    ctx->r4 = ADD32(ctx->r29, 0X158);
    after_25:
    // 0x8008057C: addiu       $a0, $sp, 0x158
    ctx->r4 = ADD32(ctx->r29, 0X158);
    // 0x80080580: addiu       $a1, $sp, 0x134
    ctx->r5 = ADD32(ctx->r29, 0X134);
    // 0x80080584: jal         0x800193E8
    // 0x80080588: addiu       $a2, $s2, 0xC
    ctx->r6 = ADD32(ctx->r18, 0XC);
    func_800193E8(rdram, ctx);
        goto after_26;
    // 0x80080588: addiu       $a2, $s2, 0xC
    ctx->r6 = ADD32(ctx->r18, 0XC);
    after_26:
    // 0x8008058C: addiu       $a0, $sp, 0x158
    ctx->r4 = ADD32(ctx->r29, 0X158);
    // 0x80080590: addiu       $a1, $sp, 0x140
    ctx->r5 = ADD32(ctx->r29, 0X140);
    // 0x80080594: jal         0x800193E8
    // 0x80080598: addiu       $a2, $s2, 0x18
    ctx->r6 = ADD32(ctx->r18, 0X18);
    func_800193E8(rdram, ctx);
        goto after_27;
    // 0x80080598: addiu       $a2, $s2, 0x18
    ctx->r6 = ADD32(ctx->r18, 0X18);
    after_27:
    // 0x8008059C: lw          $a0, 0x38($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X38);
    // 0x800805A0: jal         0x800F07AC
    // 0x800805A4: nop

    func_800F07AC(rdram, ctx);
        goto after_28;
    // 0x800805A4: nop

    after_28:
    // 0x800805A8: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x800805AC: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x800805B0: beql        $v0, $v1, L_800805B8
    if (ctx->r2 == ctx->r3) {
        // 0x800805B4: addu        $s0, $v1, $zero
        ctx->r16 = ADD32(ctx->r3, 0);
            goto L_800805B8;
    }
    goto skip_1;
    // 0x800805B4: addu        $s0, $v1, $zero
    ctx->r16 = ADD32(ctx->r3, 0);
    skip_1:
L_800805B8:
    // 0x800805B8: addu        $v1, $s2, $zero
    ctx->r3 = ADD32(ctx->r18, 0);
    // 0x800805BC: addiu       $v0, $sp, 0x128
    ctx->r2 = ADD32(ctx->r29, 0X128);
    // 0x800805C0: addiu       $a0, $sp, 0x158
    ctx->r4 = ADD32(ctx->r29, 0X158);
L_800805C4:
    // 0x800805C4: lw          $t0, 0x0($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X0);
    // 0x800805C8: lw          $t1, 0x4($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X4);
    // 0x800805CC: lw          $t2, 0x8($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X8);
    // 0x800805D0: lw          $t3, 0xC($v0)
    ctx->r11 = MEM_W(ctx->r2, 0XC);
    // 0x800805D4: sw          $t0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r8;
    // 0x800805D8: sw          $t1, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r9;
    // 0x800805DC: sw          $t2, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r10;
    // 0x800805E0: sw          $t3, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r11;
    // 0x800805E4: addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
    // 0x800805E8: bne         $v0, $a0, L_800805C4
    if (ctx->r2 != ctx->r4) {
        // 0x800805EC: addiu       $v1, $v1, 0x10
        ctx->r3 = ADD32(ctx->r3, 0X10);
            goto L_800805C4;
    }
    // 0x800805EC: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
    // 0x800805F0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800805F4:
    // 0x800805F4: bne         $s0, $v0, L_80080870
    if (ctx->r16 != ctx->r2) {
        // 0x800805F8: addu        $a2, $zero, $zero
        ctx->r6 = ADD32(0, 0);
            goto L_80080870;
    }
    // 0x800805F8: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // 0x800805FC: lw          $a0, 0x38($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X38);
    // 0x80080600: mfc1        $a1, $f22
    ctx->r5 = (int32_t)ctx->f22.u32l;
    // 0x80080604: jal         0x800F2D38
    // 0x80080608: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    func_800F2D38(rdram, ctx);
        goto after_29;
    // 0x80080608: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    after_29:
    // 0x8008060C: j           L_80080870
    // 0x80080610: nop

        goto L_80080870;
    // 0x80080610: nop

L_80080614:
    // 0x80080614: lwc1        $f2, 0x98($s2)
    ctx->f2.u32l = MEM_W(ctx->r18, 0X98);
    // 0x80080618: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8008061C: lwc1        $f0, -0x25FC($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X25FC);
    // 0x80080620: c.lt.s      $f2, $f20
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f2.fl < ctx->f20.fl;
    // 0x80080624: mul.s       $f0, $f22, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = MUL_S(ctx->f22.fl, ctx->f0.fl);
    // 0x80080628: bc1f        L_80080690
    if (!c1cs) {
        // 0x8008062C: nop
    
            goto L_80080690;
    }
    // 0x8008062C: nop

    // 0x80080630: add.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x80080634: c.lt.s      $f20, $f2
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f20.fl < ctx->f2.fl;
    // 0x80080638: nop

    // 0x8008063C: bc1f        L_80080650
    if (!c1cs) {
        // 0x80080640: swc1        $f2, 0x98($s2)
        MEM_W(0X98, ctx->r18) = ctx->f2.u32l;
            goto L_80080650;
    }
    // 0x80080640: swc1        $f2, 0x98($s2)
    MEM_W(0X98, ctx->r18) = ctx->f2.u32l;
    // 0x80080644: swc1        $f20, 0x98($s2)
    MEM_W(0X98, ctx->r18) = ctx->f20.u32l;
    // 0x80080648: j           L_80080690
    // 0x8008064C: sw          $zero, 0x9C($s2)
    MEM_W(0X9C, ctx->r18) = 0;
        goto L_80080690;
    // 0x8008064C: sw          $zero, 0x9C($s2)
    MEM_W(0X9C, ctx->r18) = 0;
L_80080650:
    // 0x80080650: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80080654: lwc1        $f0, -0x25F8($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X25F8);
    // 0x80080658: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x8008065C: nop

    // 0x80080660: bc1fl       L_8008067C
    if (!c1cs) {
        // 0x80080664: sub.s       $f0, $f2, $f0
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f2.fl - ctx->f0.fl;
            goto L_8008067C;
    }
    goto skip_2;
    // 0x80080664: sub.s       $f0, $f2, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f2.fl - ctx->f0.fl;
    skip_2:
    // 0x80080668: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8008066C: lwc1        $f0, -0x25F4($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X25F4);
    // 0x80080670: mul.s       $f0, $f2, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x80080674: j           L_80080690
    // 0x80080678: swc1        $f0, 0x9C($s2)
    MEM_W(0X9C, ctx->r18) = ctx->f0.u32l;
        goto L_80080690;
    // 0x80080678: swc1        $f0, 0x9C($s2)
    MEM_W(0X9C, ctx->r18) = ctx->f0.u32l;
L_8008067C:
    // 0x8008067C: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80080680: lwc1        $f2, -0x25F0($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X25F0);
    // 0x80080684: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x80080688: sub.s       $f0, $f20, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f20.fl - ctx->f0.fl;
    // 0x8008068C: swc1        $f0, 0x9C($s2)
    MEM_W(0X9C, ctx->r18) = ctx->f0.u32l;
L_80080690:
    // 0x80080690: lwc1        $f0, 0xB0($s2)
    ctx->f0.u32l = MEM_W(ctx->r18, 0XB0);
    // 0x80080694: sub.s       $f0, $f0, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f22.fl;
    // 0x80080698: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x8008069C: c.le.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl <= ctx->f2.fl;
    // 0x800806A0: nop

    // 0x800806A4: bc1f        L_80080870
    if (!c1cs) {
        // 0x800806A8: swc1        $f0, 0xB0($s2)
        MEM_W(0XB0, ctx->r18) = ctx->f0.u32l;
            goto L_80080870;
    }
    // 0x800806A8: swc1        $f0, 0xB0($s2)
    MEM_W(0XB0, ctx->r18) = ctx->f0.u32l;
    // 0x800806AC: lhu         $v0, 0xB4($s2)
    ctx->r2 = MEM_HU(ctx->r18, 0XB4);
    // 0x800806B0: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x800806B4: sh          $v0, 0xB4($s2)
    MEM_H(0XB4, ctx->r18) = ctx->r2;
    // 0x800806B8: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x800806BC: bgtz        $v0, L_80080730
    if (SIGNED(ctx->r2) > 0) {
        // 0x800806C0: nop
    
            goto L_80080730;
    }
    // 0x800806C0: nop

    // 0x800806C4: lwc1        $f2, 0x88($s2)
    ctx->f2.u32l = MEM_W(ctx->r18, 0X88);
    // 0x800806C8: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x800806CC: lwc1        $f0, -0x25EC($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X25EC);
    // 0x800806D0: mul.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x800806D4: mfc1        $a1, $f2
    ctx->r5 = (int32_t)ctx->f2.u32l;
    // 0x800806D8: jal         0x800612A4
    // 0x800806DC: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    func_800612A4(rdram, ctx);
        goto after_30;
    // 0x800806DC: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    after_30:
    // 0x800806E0: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x800806E4: addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    // 0x800806E8: addiu       $a2, $a1, 0x24
    ctx->r6 = ADD32(ctx->r5, 0X24);
    // 0x800806EC: lui         $a3, 0x41C0
    ctx->r7 = S32(0X41C0 << 16);
    // 0x800806F0: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x800806F4: lwc1        $f0, -0x25E8($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X25E8);
    // 0x800806F8: addiu       $v0, $zero, 0x22
    ctx->r2 = ADD32(0, 0X22);
    // 0x800806FC: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // 0x80080700: addiu       $v0, $zero, 0x7D
    ctx->r2 = ADD32(0, 0X7D);
    // 0x80080704: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x80080708: addiu       $v0, $zero, 0x50
    ctx->r2 = ADD32(0, 0X50);
    // 0x8008070C: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x80080710: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x80080714: jal         0x800989D8
    // 0x80080718: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    func_800989D8(rdram, ctx);
        goto after_31;
    // 0x80080718: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    after_31:
    // 0x8008071C: lhu         $a0, 0x16($s3)
    ctx->r4 = MEM_HU(ctx->r19, 0X16);
    // 0x80080720: jal         0x8003ED74
    // 0x80080724: nop

    func_8003ED74(rdram, ctx);
        goto after_32;
    // 0x80080724: nop

    after_32:
    // 0x80080728: j           L_8008132C
    // 0x8008072C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8008132C;
    // 0x8008072C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80080730:
    // 0x80080730: jal         0x80003430
    // 0x80080734: nop

    rand_recomp(rdram, ctx);
        goto after_33;
    // 0x80080734: nop

    after_33:
    // 0x80080738: lui         $v1, 0x5555
    ctx->r3 = S32(0X5555 << 16);
    // 0x8008073C: ori         $v1, $v1, 0x5556
    ctx->r3 = ctx->r3 | 0X5556;
    // 0x80080740: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x80080744: sra         $a1, $v0, 16
    ctx->r5 = S32(SIGNED(ctx->r2) >> 16);
    // 0x80080748: mult        $a1, $v1
    result = S64(S32(ctx->r5)) * S64(S32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8008074C: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x80080750: sra         $v0, $v0, 31
    ctx->r2 = S32(SIGNED(ctx->r2) >> 31);
    // 0x80080754: addiu       $a2, $s2, 0x24
    ctx->r6 = ADD32(ctx->r18, 0X24);
    // 0x80080758: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8008075C: lwc1        $f2, -0x25E4($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X25E4);
    // 0x80080760: mfhi        $t0
    ctx->r8 = hi;
    // 0x80080764: subu        $v0, $t0, $v0
    ctx->r2 = SUB32(ctx->r8, ctx->r2);
    // 0x80080768: sll         $v1, $v0, 1
    ctx->r3 = S32(ctx->r2 << 1);
    // 0x8008076C: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x80080770: subu        $a1, $a1, $v1
    ctx->r5 = SUB32(ctx->r5, ctx->r3);
    // 0x80080774: sll         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5 << 16);
    // 0x80080778: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
    // 0x8008077C: mtc1        $a1, $f0
    ctx->f0.u32l = ctx->r5;
    // 0x80080780: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x80080784: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x80080788: lui         $a3, 0x41C0
    ctx->r7 = S32(0X41C0 << 16);
    // 0x8008078C: addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    // 0x80080790: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80080794: lwc1        $f2, -0x25E0($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X25E0);
    // 0x80080798: addiu       $v0, $zero, 0x2A
    ctx->r2 = ADD32(0, 0X2A);
    // 0x8008079C: swc1        $f0, 0xB0($s2)
    MEM_W(0XB0, ctx->r18) = ctx->f0.u32l;
    // 0x800807A0: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // 0x800807A4: addiu       $v0, $zero, 0x7E
    ctx->r2 = ADD32(0, 0X7E);
    // 0x800807A8: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x800807AC: addiu       $v0, $zero, 0x3C
    ctx->r2 = ADD32(0, 0X3C);
    // 0x800807B0: swc1        $f2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f2.u32l;
    // 0x800807B4: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x800807B8: jal         0x800989D8
    // 0x800807BC: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    func_800989D8(rdram, ctx);
        goto after_34;
    // 0x800807BC: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    after_34:
    // 0x800807C0: jal         0x80003430
    // 0x800807C4: nop

    rand_recomp(rdram, ctx);
        goto after_35;
    // 0x800807C4: nop

    after_35:
    // 0x800807C8: lwc1        $f4, 0x88($s2)
    ctx->f4.u32l = MEM_W(ctx->r18, 0X88);
    // 0x800807CC: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x800807D0: lwc1        $f22, -0x25DC($at)
    ctx->f22.u32l = MEM_W(ctx->r1, -0X25DC);
    // 0x800807D4: mul.s       $f4, $f4, $f22
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f4.fl = MUL_S(ctx->f4.fl, ctx->f22.fl);
    // 0x800807D8: andi        $v0, $v0, 0x7F
    ctx->r2 = ctx->r2 & 0X7F;
    // 0x800807DC: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x800807E0: lwc1        $f20, -0x25D8($at)
    ctx->f20.u32l = MEM_W(ctx->r1, -0X25D8);
    // 0x800807E4: mtc1        $v0, $f2
    ctx->f2.u32l = ctx->r2;
    // 0x800807E8: cvt.s.w     $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    ctx->f2.fl = CVT_S_W(ctx->f2.u32l);
    // 0x800807EC: sub.s       $f2, $f2, $f20
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f2.fl = ctx->f2.fl - ctx->f20.fl;
    // 0x800807F0: lwc1        $f0, 0x0($s2)
    ctx->f0.u32l = MEM_W(ctx->r18, 0X0);
    // 0x800807F4: div.s       $f4, $f20, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f4.fl = DIV_S(ctx->f20.fl, ctx->f4.fl);
    // 0x800807F8: div.s       $f2, $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = DIV_S(ctx->f2.fl, ctx->f4.fl);
    // 0x800807FC: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x80080800: jal         0x80003430
    // 0x80080804: swc1        $f0, 0x128($sp)
    MEM_W(0X128, ctx->r29) = ctx->f0.u32l;
    rand_recomp(rdram, ctx);
        goto after_36;
    // 0x80080804: swc1        $f0, 0x128($sp)
    MEM_W(0X128, ctx->r29) = ctx->f0.u32l;
    after_36:
    // 0x80080808: lwc1        $f2, 0x88($s2)
    ctx->f2.u32l = MEM_W(ctx->r18, 0X88);
    // 0x8008080C: mul.s       $f2, $f2, $f22
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f22.fl);
    // 0x80080810: andi        $v0, $v0, 0x7F
    ctx->r2 = ctx->r2 & 0X7F;
    // 0x80080814: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x80080818: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x8008081C: sub.s       $f0, $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f20.fl;
    // 0x80080820: div.s       $f2, $f20, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = DIV_S(ctx->f20.fl, ctx->f2.fl);
    // 0x80080824: div.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f2.fl);
    // 0x80080828: abs.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = fabsf(ctx->f0.fl);
    // 0x8008082C: lwc1        $f0, 0x4($s2)
    ctx->f0.u32l = MEM_W(ctx->r18, 0X4);
    // 0x80080830: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x80080834: jal         0x80003430
    // 0x80080838: swc1        $f0, 0x12C($sp)
    MEM_W(0X12C, ctx->r29) = ctx->f0.u32l;
    rand_recomp(rdram, ctx);
        goto after_37;
    // 0x80080838: swc1        $f0, 0x12C($sp)
    MEM_W(0X12C, ctx->r29) = ctx->f0.u32l;
    after_37:
    // 0x8008083C: lwc1        $f2, 0x88($s2)
    ctx->f2.u32l = MEM_W(ctx->r18, 0X88);
    // 0x80080840: mul.s       $f2, $f2, $f22
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f22.fl);
    // 0x80080844: andi        $v0, $v0, 0x7F
    ctx->r2 = ctx->r2 & 0X7F;
    // 0x80080848: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x8008084C: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x80080850: sub.s       $f0, $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f20.fl;
    // 0x80080854: div.s       $f20, $f20, $f2
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f20.fl = DIV_S(ctx->f20.fl, ctx->f2.fl);
    // 0x80080858: lwc1        $f2, 0x8($s2)
    ctx->f2.u32l = MEM_W(ctx->r18, 0X8);
    // 0x8008085C: div.s       $f0, $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f20.fl);
    // 0x80080860: add.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x80080864: addiu       $a0, $sp, 0x128
    ctx->r4 = ADD32(ctx->r29, 0X128);
    // 0x80080868: jal         0x80061268
    // 0x8008086C: swc1        $f2, 0x130($sp)
    MEM_W(0X130, ctx->r29) = ctx->f2.u32l;
    func_80061268(rdram, ctx);
        goto after_38;
    // 0x8008086C: swc1        $f2, 0x130($sp)
    MEM_W(0X130, ctx->r29) = ctx->f2.u32l;
    after_38:
L_80080870:
    // 0x80080870: lw          $a0, 0x38($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X38);
    // 0x80080874: jal         0x800EC6C0
    // 0x80080878: nop

    func_800EC6C0(rdram, ctx);
        goto after_39;
    // 0x80080878: nop

    after_39:
    // 0x8008087C: j           L_8008132C
    // 0x80080880: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8008132C;
    // 0x80080880: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80080884:
    // 0x80080884: addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    // 0x80080888: addu        $s3, $s0, $zero
    ctx->r19 = ADD32(ctx->r16, 0);
    // 0x8008088C: lw          $a0, 0x30($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X30);
    // 0x80080890: lw          $a2, 0x84($s2)
    ctx->r6 = MEM_W(ctx->r18, 0X84);
    // 0x80080894: jal         0x80059B50
    // 0x80080898: addiu       $a0, $a0, 0x28
    ctx->r4 = ADD32(ctx->r4, 0X28);
    func_80059B50(rdram, ctx);
        goto after_40;
    // 0x80080898: addiu       $a0, $a0, 0x28
    ctx->r4 = ADD32(ctx->r4, 0X28);
    after_40:
    // 0x8008089C: lh          $v1, 0xA4($s2)
    ctx->r3 = MEM_H(ctx->r18, 0XA4);
    // 0x800808A0: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x800808A4: beq         $v1, $v0, L_80080F58
    if (ctx->r3 == ctx->r2) {
        // 0x800808A8: addiu       $v0, $zero, 0x4
        ctx->r2 = ADD32(0, 0X4);
            goto L_80080F58;
    }
    // 0x800808A8: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // 0x800808AC: beq         $v1, $v0, L_80080C20
    if (ctx->r3 == ctx->r2) {
        // 0x800808B0: nop
    
            goto L_80080C20;
    }
    // 0x800808B0: nop

    // 0x800808B4: lw          $v0, 0x3C($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X3C);
    // 0x800808B8: lw          $s0, 0x48($s2)
    ctx->r16 = MEM_W(ctx->r18, 0X48);
    // 0x800808BC: addiu       $s1, $v0, 0x1C
    ctx->r17 = ADD32(ctx->r2, 0X1C);
    // 0x800808C0: jal         0x8001CA50
    // 0x800808C4: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    func_8001CA50(rdram, ctx);
        goto after_41;
    // 0x800808C4: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    after_41:
    // 0x800808C8: lw          $v0, 0x4C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X4C);
    // 0x800808CC: andi        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 & 0X1;
    // 0x800808D0: beq         $v0, $zero, L_80080904
    if (ctx->r2 == 0) {
        // 0x800808D4: nop
    
            goto L_80080904;
    }
    // 0x800808D4: nop

    // 0x800808D8: lwc1        $f0, 0x50($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X50);
    // 0x800808DC: lwc1        $f2, 0x58($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X58);
    // 0x800808E0: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
    // 0x800808E4: neg.s       $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = -ctx->f2.fl;
    // 0x800808E8: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x800808EC: lwc1        $f0, 0x54($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X54);
    // 0x800808F0: mfc1        $a3, $f2
    ctx->r7 = (int32_t)ctx->f2.u32l;
    // 0x800808F4: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
    // 0x800808F8: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x800808FC: jal         0x8001CA90
    // 0x80080900: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    func_8001CA90(rdram, ctx);
        goto after_42;
    // 0x80080900: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    after_42:
L_80080904:
    // 0x80080904: lw          $v0, 0x4C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X4C);
    // 0x80080908: andi        $v0, $v0, 0x2
    ctx->r2 = ctx->r2 & 0X2;
    // 0x8008090C: beq         $v0, $zero, L_80080928
    if (ctx->r2 == 0) {
        // 0x80080910: nop
    
            goto L_80080928;
    }
    // 0x80080910: nop

    // 0x80080914: lw          $a1, 0x5C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X5C);
    // 0x80080918: lw          $a2, 0x60($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X60);
    // 0x8008091C: lw          $a3, 0x64($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X64);
    // 0x80080920: jal         0x8001CB04
    // 0x80080924: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    func_8001CB04(rdram, ctx);
        goto after_43;
    // 0x80080924: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    after_43:
L_80080928:
    // 0x80080928: lw          $v0, 0x4C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X4C);
    // 0x8008092C: andi        $v0, $v0, 0x4
    ctx->r2 = ctx->r2 & 0X4;
    // 0x80080930: beq         $v0, $zero, L_80080940
    if (ctx->r2 == 0) {
        // 0x80080934: addu        $a0, $s1, $zero
        ctx->r4 = ADD32(ctx->r17, 0);
            goto L_80080940;
    }
    // 0x80080934: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x80080938: jal         0x8001DAEC
    // 0x8008093C: addiu       $a1, $s0, 0x68
    ctx->r5 = ADD32(ctx->r16, 0X68);
    func_8001DAEC(rdram, ctx);
        goto after_44;
    // 0x8008093C: addiu       $a1, $s0, 0x68
    ctx->r5 = ADD32(ctx->r16, 0X68);
    after_44:
L_80080940:
    // 0x80080940: lw          $a1, 0x8C($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X8C);
    // 0x80080944: jal         0x8001CCCC
    // 0x80080948: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    func_8001CCCC(rdram, ctx);
        goto after_45;
    // 0x80080948: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    after_45:
    // 0x8008094C: lw          $a0, 0x4C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X4C);
    // 0x80080950: addiu       $v0, $zero, 0x9
    ctx->r2 = ADD32(0, 0X9);
    // 0x80080954: andi        $v1, $a0, 0x9
    ctx->r3 = ctx->r4 & 0X9;
    // 0x80080958: bne         $v1, $v0, L_80080998
    if (ctx->r3 != ctx->r2) {
        // 0x8008095C: addiu       $v0, $zero, 0x8
        ctx->r2 = ADD32(0, 0X8);
            goto L_80080998;
    }
    // 0x8008095C: addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
    // 0x80080960: lwc1        $f2, 0x78($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X78);
    // 0x80080964: lwc1        $f0, 0x50($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X50);
    // 0x80080968: add.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x8008096C: lwc1        $f0, 0x54($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X54);
    // 0x80080970: mfc1        $a1, $f2
    ctx->r5 = (int32_t)ctx->f2.u32l;
    // 0x80080974: lwc1        $f2, 0x7C($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X7C);
    // 0x80080978: add.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x8008097C: lwc1        $f0, 0x58($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X58);
    // 0x80080980: mfc1        $a2, $f2
    ctx->r6 = (int32_t)ctx->f2.u32l;
    // 0x80080984: lwc1        $f2, 0x80($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X80);
    // 0x80080988: add.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x8008098C: mfc1        $a3, $f2
    ctx->r7 = (int32_t)ctx->f2.u32l;
    // 0x80080990: j           L_800809C8
    // 0x80080994: nop

        goto L_800809C8;
    // 0x80080994: nop

L_80080998:
    // 0x80080998: bne         $v1, $v0, L_800809B4
    if (ctx->r3 != ctx->r2) {
        // 0x8008099C: andi        $v0, $a0, 0x1
        ctx->r2 = ctx->r4 & 0X1;
            goto L_800809B4;
    }
    // 0x8008099C: andi        $v0, $a0, 0x1
    ctx->r2 = ctx->r4 & 0X1;
    // 0x800809A0: lw          $a1, 0x78($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X78);
    // 0x800809A4: lw          $a2, 0x7C($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X7C);
    // 0x800809A8: lw          $a3, 0x80($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X80);
    // 0x800809AC: j           L_800809C8
    // 0x800809B0: nop

        goto L_800809C8;
    // 0x800809B0: nop

L_800809B4:
    // 0x800809B4: beq         $v0, $zero, L_800809D0
    if (ctx->r2 == 0) {
        // 0x800809B8: nop
    
            goto L_800809D0;
    }
    // 0x800809B8: nop

    // 0x800809BC: lw          $a1, 0x50($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X50);
    // 0x800809C0: lw          $a2, 0x54($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X54);
    // 0x800809C4: lw          $a3, 0x58($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X58);
L_800809C8:
    // 0x800809C8: jal         0x8001CA90
    // 0x800809CC: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    func_8001CA90(rdram, ctx);
        goto after_46;
    // 0x800809CC: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    after_46:
L_800809D0:
    // 0x800809D0: lw          $v0, 0x40($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X40);
    // 0x800809D4: lw          $s0, 0x4C($s2)
    ctx->r16 = MEM_W(ctx->r18, 0X4C);
    // 0x800809D8: addiu       $s1, $v0, 0x1C
    ctx->r17 = ADD32(ctx->r2, 0X1C);
    // 0x800809DC: jal         0x8001CA50
    // 0x800809E0: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    func_8001CA50(rdram, ctx);
        goto after_47;
    // 0x800809E0: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    after_47:
    // 0x800809E4: lw          $v0, 0x4C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X4C);
    // 0x800809E8: andi        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 & 0X1;
    // 0x800809EC: beq         $v0, $zero, L_80080A20
    if (ctx->r2 == 0) {
        // 0x800809F0: nop
    
            goto L_80080A20;
    }
    // 0x800809F0: nop

    // 0x800809F4: lwc1        $f0, 0x50($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X50);
    // 0x800809F8: lwc1        $f2, 0x58($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X58);
    // 0x800809FC: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
    // 0x80080A00: neg.s       $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = -ctx->f2.fl;
    // 0x80080A04: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80080A08: lwc1        $f0, 0x54($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X54);
    // 0x80080A0C: mfc1        $a3, $f2
    ctx->r7 = (int32_t)ctx->f2.u32l;
    // 0x80080A10: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
    // 0x80080A14: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80080A18: jal         0x8001CA90
    // 0x80080A1C: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    func_8001CA90(rdram, ctx);
        goto after_48;
    // 0x80080A1C: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    after_48:
L_80080A20:
    // 0x80080A20: lw          $v0, 0x4C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X4C);
    // 0x80080A24: andi        $v0, $v0, 0x2
    ctx->r2 = ctx->r2 & 0X2;
    // 0x80080A28: beq         $v0, $zero, L_80080A44
    if (ctx->r2 == 0) {
        // 0x80080A2C: nop
    
            goto L_80080A44;
    }
    // 0x80080A2C: nop

    // 0x80080A30: lw          $a1, 0x5C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X5C);
    // 0x80080A34: lw          $a2, 0x60($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X60);
    // 0x80080A38: lw          $a3, 0x64($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X64);
    // 0x80080A3C: jal         0x8001CB04
    // 0x80080A40: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    func_8001CB04(rdram, ctx);
        goto after_49;
    // 0x80080A40: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    after_49:
L_80080A44:
    // 0x80080A44: lw          $v0, 0x4C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X4C);
    // 0x80080A48: andi        $v0, $v0, 0x4
    ctx->r2 = ctx->r2 & 0X4;
    // 0x80080A4C: beq         $v0, $zero, L_80080A5C
    if (ctx->r2 == 0) {
        // 0x80080A50: addu        $a0, $s1, $zero
        ctx->r4 = ADD32(ctx->r17, 0);
            goto L_80080A5C;
    }
    // 0x80080A50: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x80080A54: jal         0x8001DAEC
    // 0x80080A58: addiu       $a1, $s0, 0x68
    ctx->r5 = ADD32(ctx->r16, 0X68);
    func_8001DAEC(rdram, ctx);
        goto after_50;
    // 0x80080A58: addiu       $a1, $s0, 0x68
    ctx->r5 = ADD32(ctx->r16, 0X68);
    after_50:
L_80080A5C:
    // 0x80080A5C: lw          $a1, 0x90($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X90);
    // 0x80080A60: jal         0x8001CB9C
    // 0x80080A64: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    func_8001CB9C(rdram, ctx);
        goto after_51;
    // 0x80080A64: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    after_51:
    // 0x80080A68: lw          $a0, 0x4C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X4C);
    // 0x80080A6C: addiu       $v0, $zero, 0x9
    ctx->r2 = ADD32(0, 0X9);
    // 0x80080A70: andi        $v1, $a0, 0x9
    ctx->r3 = ctx->r4 & 0X9;
    // 0x80080A74: bne         $v1, $v0, L_80080AB4
    if (ctx->r3 != ctx->r2) {
        // 0x80080A78: addiu       $v0, $zero, 0x8
        ctx->r2 = ADD32(0, 0X8);
            goto L_80080AB4;
    }
    // 0x80080A78: addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
    // 0x80080A7C: lwc1        $f2, 0x78($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X78);
    // 0x80080A80: lwc1        $f0, 0x50($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X50);
    // 0x80080A84: add.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x80080A88: lwc1        $f0, 0x54($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X54);
    // 0x80080A8C: mfc1        $a1, $f2
    ctx->r5 = (int32_t)ctx->f2.u32l;
    // 0x80080A90: lwc1        $f2, 0x7C($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X7C);
    // 0x80080A94: add.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x80080A98: lwc1        $f0, 0x58($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X58);
    // 0x80080A9C: mfc1        $a2, $f2
    ctx->r6 = (int32_t)ctx->f2.u32l;
    // 0x80080AA0: lwc1        $f2, 0x80($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X80);
    // 0x80080AA4: add.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x80080AA8: mfc1        $a3, $f2
    ctx->r7 = (int32_t)ctx->f2.u32l;
    // 0x80080AAC: j           L_80080AE4
    // 0x80080AB0: nop

        goto L_80080AE4;
    // 0x80080AB0: nop

L_80080AB4:
    // 0x80080AB4: bne         $v1, $v0, L_80080AD0
    if (ctx->r3 != ctx->r2) {
        // 0x80080AB8: andi        $v0, $a0, 0x1
        ctx->r2 = ctx->r4 & 0X1;
            goto L_80080AD0;
    }
    // 0x80080AB8: andi        $v0, $a0, 0x1
    ctx->r2 = ctx->r4 & 0X1;
    // 0x80080ABC: lw          $a1, 0x78($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X78);
    // 0x80080AC0: lw          $a2, 0x7C($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X7C);
    // 0x80080AC4: lw          $a3, 0x80($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X80);
    // 0x80080AC8: j           L_80080AE4
    // 0x80080ACC: nop

        goto L_80080AE4;
    // 0x80080ACC: nop

L_80080AD0:
    // 0x80080AD0: beq         $v0, $zero, L_80080AEC
    if (ctx->r2 == 0) {
        // 0x80080AD4: nop
    
            goto L_80080AEC;
    }
    // 0x80080AD4: nop

    // 0x80080AD8: lw          $a1, 0x50($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X50);
    // 0x80080ADC: lw          $a2, 0x54($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X54);
    // 0x80080AE0: lw          $a3, 0x58($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X58);
L_80080AE4:
    // 0x80080AE4: jal         0x8001CA90
    // 0x80080AE8: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    func_8001CA90(rdram, ctx);
        goto after_52;
    // 0x80080AE8: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    after_52:
L_80080AEC:
    // 0x80080AEC: lw          $v0, 0x44($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X44);
    // 0x80080AF0: lw          $s0, 0x50($s2)
    ctx->r16 = MEM_W(ctx->r18, 0X50);
    // 0x80080AF4: addiu       $s1, $v0, 0x1C
    ctx->r17 = ADD32(ctx->r2, 0X1C);
    // 0x80080AF8: jal         0x8001CA50
    // 0x80080AFC: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    func_8001CA50(rdram, ctx);
        goto after_53;
    // 0x80080AFC: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    after_53:
    // 0x80080B00: lw          $v0, 0x4C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X4C);
    // 0x80080B04: andi        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 & 0X1;
    // 0x80080B08: beq         $v0, $zero, L_80080B3C
    if (ctx->r2 == 0) {
        // 0x80080B0C: nop
    
            goto L_80080B3C;
    }
    // 0x80080B0C: nop

    // 0x80080B10: lwc1        $f0, 0x50($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X50);
    // 0x80080B14: lwc1        $f2, 0x58($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X58);
    // 0x80080B18: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
    // 0x80080B1C: neg.s       $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = -ctx->f2.fl;
    // 0x80080B20: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80080B24: lwc1        $f0, 0x54($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X54);
    // 0x80080B28: mfc1        $a3, $f2
    ctx->r7 = (int32_t)ctx->f2.u32l;
    // 0x80080B2C: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
    // 0x80080B30: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80080B34: jal         0x8001CA90
    // 0x80080B38: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    func_8001CA90(rdram, ctx);
        goto after_54;
    // 0x80080B38: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    after_54:
L_80080B3C:
    // 0x80080B3C: lw          $v0, 0x4C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X4C);
    // 0x80080B40: andi        $v0, $v0, 0x2
    ctx->r2 = ctx->r2 & 0X2;
    // 0x80080B44: beq         $v0, $zero, L_80080B60
    if (ctx->r2 == 0) {
        // 0x80080B48: nop
    
            goto L_80080B60;
    }
    // 0x80080B48: nop

    // 0x80080B4C: lw          $a1, 0x5C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X5C);
    // 0x80080B50: lw          $a2, 0x60($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X60);
    // 0x80080B54: lw          $a3, 0x64($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X64);
    // 0x80080B58: jal         0x8001CB04
    // 0x80080B5C: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    func_8001CB04(rdram, ctx);
        goto after_55;
    // 0x80080B5C: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    after_55:
L_80080B60:
    // 0x80080B60: lw          $v0, 0x4C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X4C);
    // 0x80080B64: andi        $v0, $v0, 0x4
    ctx->r2 = ctx->r2 & 0X4;
    // 0x80080B68: beq         $v0, $zero, L_80080B78
    if (ctx->r2 == 0) {
        // 0x80080B6C: addu        $a0, $s1, $zero
        ctx->r4 = ADD32(ctx->r17, 0);
            goto L_80080B78;
    }
    // 0x80080B6C: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x80080B70: jal         0x8001DAEC
    // 0x80080B74: addiu       $a1, $s0, 0x68
    ctx->r5 = ADD32(ctx->r16, 0X68);
    func_8001DAEC(rdram, ctx);
        goto after_56;
    // 0x80080B74: addiu       $a1, $s0, 0x68
    ctx->r5 = ADD32(ctx->r16, 0X68);
    after_56:
L_80080B78:
    // 0x80080B78: lui         $v1, 0x800A
    ctx->r3 = S32(0X800A << 16);
    // 0x80080B7C: addiu       $v1, $v1, 0xD9C
    ctx->r3 = ADD32(ctx->r3, 0XD9C);
    // 0x80080B80: lh          $a0, 0xA4($s2)
    ctx->r4 = MEM_H(ctx->r18, 0XA4);
    // 0x80080B84: lwc1        $f2, 0x9C($s2)
    ctx->f2.u32l = MEM_W(ctx->r18, 0X9C);
    // 0x80080B88: sll         $v0, $a0, 4
    ctx->r2 = S32(ctx->r4 << 4);
    // 0x80080B8C: subu        $v0, $v0, $a0
    ctx->r2 = SUB32(ctx->r2, ctx->r4);
    // 0x80080B90: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80080B94: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80080B98: lwc1        $f0, 0x38($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X38);
    // 0x80080B9C: mul.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x80080BA0: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80080BA4: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x80080BA8: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80080BAC: mfc1        $a3, $f2
    ctx->r7 = (int32_t)ctx->f2.u32l;
    // 0x80080BB0: jal         0x8001CA90
    // 0x80080BB4: addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    func_8001CA90(rdram, ctx);
        goto after_57;
    // 0x80080BB4: addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    after_57:
    // 0x80080BB8: lw          $a0, 0x4C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X4C);
    // 0x80080BBC: addiu       $v0, $zero, 0x9
    ctx->r2 = ADD32(0, 0X9);
    // 0x80080BC0: andi        $v1, $a0, 0x9
    ctx->r3 = ctx->r4 & 0X9;
    // 0x80080BC4: bne         $v1, $v0, L_80080C04
    if (ctx->r3 != ctx->r2) {
        // 0x80080BC8: addiu       $v0, $zero, 0x8
        ctx->r2 = ADD32(0, 0X8);
            goto L_80080C04;
    }
    // 0x80080BC8: addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
    // 0x80080BCC: lwc1        $f2, 0x78($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X78);
    // 0x80080BD0: lwc1        $f0, 0x50($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X50);
    // 0x80080BD4: add.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x80080BD8: lwc1        $f0, 0x54($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X54);
    // 0x80080BDC: mfc1        $a1, $f2
    ctx->r5 = (int32_t)ctx->f2.u32l;
    // 0x80080BE0: lwc1        $f2, 0x7C($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X7C);
    // 0x80080BE4: add.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x80080BE8: lwc1        $f0, 0x58($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X58);
    // 0x80080BEC: mfc1        $a2, $f2
    ctx->r6 = (int32_t)ctx->f2.u32l;
    // 0x80080BF0: lwc1        $f2, 0x80($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X80);
    // 0x80080BF4: add.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x80080BF8: mfc1        $a3, $f2
    ctx->r7 = (int32_t)ctx->f2.u32l;
    // 0x80080BFC: j           L_800811C8
    // 0x80080C00: nop

        goto L_800811C8;
    // 0x80080C00: nop

L_80080C04:
    // 0x80080C04: bne         $v1, $v0, L_800811B4
    if (ctx->r3 != ctx->r2) {
        // 0x80080C08: andi        $v0, $a0, 0x1
        ctx->r2 = ctx->r4 & 0X1;
            goto L_800811B4;
    }
    // 0x80080C08: andi        $v0, $a0, 0x1
    ctx->r2 = ctx->r4 & 0X1;
    // 0x80080C0C: lw          $a1, 0x78($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X78);
    // 0x80080C10: lw          $a2, 0x7C($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X7C);
    // 0x80080C14: lw          $a3, 0x80($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X80);
    // 0x80080C18: j           L_800811C8
    // 0x80080C1C: nop

        goto L_800811C8;
    // 0x80080C1C: nop

L_80080C20:
    // 0x80080C20: lw          $v0, 0x3C($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X3C);
    // 0x80080C24: lw          $s0, 0x48($s2)
    ctx->r16 = MEM_W(ctx->r18, 0X48);
    // 0x80080C28: addiu       $s1, $v0, 0x1C
    ctx->r17 = ADD32(ctx->r2, 0X1C);
    // 0x80080C2C: jal         0x8001CA50
    // 0x80080C30: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    func_8001CA50(rdram, ctx);
        goto after_58;
    // 0x80080C30: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    after_58:
    // 0x80080C34: lw          $v0, 0x4C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X4C);
    // 0x80080C38: andi        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 & 0X1;
    // 0x80080C3C: beq         $v0, $zero, L_80080C70
    if (ctx->r2 == 0) {
        // 0x80080C40: nop
    
            goto L_80080C70;
    }
    // 0x80080C40: nop

    // 0x80080C44: lwc1        $f0, 0x50($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X50);
    // 0x80080C48: lwc1        $f2, 0x58($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X58);
    // 0x80080C4C: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
    // 0x80080C50: neg.s       $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = -ctx->f2.fl;
    // 0x80080C54: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80080C58: lwc1        $f0, 0x54($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X54);
    // 0x80080C5C: mfc1        $a3, $f2
    ctx->r7 = (int32_t)ctx->f2.u32l;
    // 0x80080C60: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
    // 0x80080C64: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80080C68: jal         0x8001CA90
    // 0x80080C6C: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    func_8001CA90(rdram, ctx);
        goto after_59;
    // 0x80080C6C: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    after_59:
L_80080C70:
    // 0x80080C70: lw          $v0, 0x4C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X4C);
    // 0x80080C74: andi        $v0, $v0, 0x2
    ctx->r2 = ctx->r2 & 0X2;
    // 0x80080C78: beq         $v0, $zero, L_80080C94
    if (ctx->r2 == 0) {
        // 0x80080C7C: nop
    
            goto L_80080C94;
    }
    // 0x80080C7C: nop

    // 0x80080C80: lw          $a1, 0x5C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X5C);
    // 0x80080C84: lw          $a2, 0x60($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X60);
    // 0x80080C88: lw          $a3, 0x64($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X64);
    // 0x80080C8C: jal         0x8001CB04
    // 0x80080C90: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    func_8001CB04(rdram, ctx);
        goto after_60;
    // 0x80080C90: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    after_60:
L_80080C94:
    // 0x80080C94: lw          $v0, 0x4C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X4C);
    // 0x80080C98: andi        $v0, $v0, 0x4
    ctx->r2 = ctx->r2 & 0X4;
    // 0x80080C9C: beq         $v0, $zero, L_80080CAC
    if (ctx->r2 == 0) {
        // 0x80080CA0: addu        $a0, $s1, $zero
        ctx->r4 = ADD32(ctx->r17, 0);
            goto L_80080CAC;
    }
    // 0x80080CA0: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x80080CA4: jal         0x8001DAEC
    // 0x80080CA8: addiu       $a1, $s0, 0x68
    ctx->r5 = ADD32(ctx->r16, 0X68);
    func_8001DAEC(rdram, ctx);
        goto after_61;
    // 0x80080CA8: addiu       $a1, $s0, 0x68
    ctx->r5 = ADD32(ctx->r16, 0X68);
    after_61:
L_80080CAC:
    // 0x80080CAC: lw          $a1, 0x8C($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X8C);
    // 0x80080CB0: jal         0x8001CCCC
    // 0x80080CB4: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    func_8001CCCC(rdram, ctx);
        goto after_62;
    // 0x80080CB4: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    after_62:
    // 0x80080CB8: lw          $a0, 0x4C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X4C);
    // 0x80080CBC: addiu       $v0, $zero, 0x9
    ctx->r2 = ADD32(0, 0X9);
    // 0x80080CC0: andi        $v1, $a0, 0x9
    ctx->r3 = ctx->r4 & 0X9;
    // 0x80080CC4: bne         $v1, $v0, L_80080D04
    if (ctx->r3 != ctx->r2) {
        // 0x80080CC8: addiu       $v0, $zero, 0x8
        ctx->r2 = ADD32(0, 0X8);
            goto L_80080D04;
    }
    // 0x80080CC8: addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
    // 0x80080CCC: lwc1        $f2, 0x78($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X78);
    // 0x80080CD0: lwc1        $f0, 0x50($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X50);
    // 0x80080CD4: add.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x80080CD8: lwc1        $f0, 0x54($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X54);
    // 0x80080CDC: mfc1        $a1, $f2
    ctx->r5 = (int32_t)ctx->f2.u32l;
    // 0x80080CE0: lwc1        $f2, 0x7C($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X7C);
    // 0x80080CE4: add.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x80080CE8: lwc1        $f0, 0x58($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X58);
    // 0x80080CEC: mfc1        $a2, $f2
    ctx->r6 = (int32_t)ctx->f2.u32l;
    // 0x80080CF0: lwc1        $f2, 0x80($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X80);
    // 0x80080CF4: add.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x80080CF8: mfc1        $a3, $f2
    ctx->r7 = (int32_t)ctx->f2.u32l;
    // 0x80080CFC: j           L_80080D34
    // 0x80080D00: nop

        goto L_80080D34;
    // 0x80080D00: nop

L_80080D04:
    // 0x80080D04: bne         $v1, $v0, L_80080D20
    if (ctx->r3 != ctx->r2) {
        // 0x80080D08: andi        $v0, $a0, 0x1
        ctx->r2 = ctx->r4 & 0X1;
            goto L_80080D20;
    }
    // 0x80080D08: andi        $v0, $a0, 0x1
    ctx->r2 = ctx->r4 & 0X1;
    // 0x80080D0C: lw          $a1, 0x78($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X78);
    // 0x80080D10: lw          $a2, 0x7C($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X7C);
    // 0x80080D14: lw          $a3, 0x80($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X80);
    // 0x80080D18: j           L_80080D34
    // 0x80080D1C: nop

        goto L_80080D34;
    // 0x80080D1C: nop

L_80080D20:
    // 0x80080D20: beq         $v0, $zero, L_80080D3C
    if (ctx->r2 == 0) {
        // 0x80080D24: nop
    
            goto L_80080D3C;
    }
    // 0x80080D24: nop

    // 0x80080D28: lw          $a1, 0x50($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X50);
    // 0x80080D2C: lw          $a2, 0x54($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X54);
    // 0x80080D30: lw          $a3, 0x58($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X58);
L_80080D34:
    // 0x80080D34: jal         0x8001CA90
    // 0x80080D38: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    func_8001CA90(rdram, ctx);
        goto after_63;
    // 0x80080D38: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    after_63:
L_80080D3C:
    // 0x80080D3C: lw          $v0, 0x40($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X40);
    // 0x80080D40: lw          $s0, 0x4C($s2)
    ctx->r16 = MEM_W(ctx->r18, 0X4C);
    // 0x80080D44: addiu       $s1, $v0, 0x1C
    ctx->r17 = ADD32(ctx->r2, 0X1C);
    // 0x80080D48: jal         0x8001CA50
    // 0x80080D4C: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    func_8001CA50(rdram, ctx);
        goto after_64;
    // 0x80080D4C: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    after_64:
    // 0x80080D50: lw          $v0, 0x4C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X4C);
    // 0x80080D54: andi        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 & 0X1;
    // 0x80080D58: beq         $v0, $zero, L_80080D8C
    if (ctx->r2 == 0) {
        // 0x80080D5C: nop
    
            goto L_80080D8C;
    }
    // 0x80080D5C: nop

    // 0x80080D60: lwc1        $f0, 0x50($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X50);
    // 0x80080D64: lwc1        $f2, 0x58($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X58);
    // 0x80080D68: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
    // 0x80080D6C: neg.s       $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = -ctx->f2.fl;
    // 0x80080D70: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80080D74: lwc1        $f0, 0x54($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X54);
    // 0x80080D78: mfc1        $a3, $f2
    ctx->r7 = (int32_t)ctx->f2.u32l;
    // 0x80080D7C: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
    // 0x80080D80: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80080D84: jal         0x8001CA90
    // 0x80080D88: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    func_8001CA90(rdram, ctx);
        goto after_65;
    // 0x80080D88: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    after_65:
L_80080D8C:
    // 0x80080D8C: lw          $v0, 0x4C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X4C);
    // 0x80080D90: andi        $v0, $v0, 0x2
    ctx->r2 = ctx->r2 & 0X2;
    // 0x80080D94: beq         $v0, $zero, L_80080DB0
    if (ctx->r2 == 0) {
        // 0x80080D98: nop
    
            goto L_80080DB0;
    }
    // 0x80080D98: nop

    // 0x80080D9C: lw          $a1, 0x5C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X5C);
    // 0x80080DA0: lw          $a2, 0x60($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X60);
    // 0x80080DA4: lw          $a3, 0x64($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X64);
    // 0x80080DA8: jal         0x8001CB04
    // 0x80080DAC: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    func_8001CB04(rdram, ctx);
        goto after_66;
    // 0x80080DAC: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    after_66:
L_80080DB0:
    // 0x80080DB0: lw          $v0, 0x4C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X4C);
    // 0x80080DB4: andi        $v0, $v0, 0x4
    ctx->r2 = ctx->r2 & 0X4;
    // 0x80080DB8: beq         $v0, $zero, L_80080DC8
    if (ctx->r2 == 0) {
        // 0x80080DBC: addu        $a0, $s1, $zero
        ctx->r4 = ADD32(ctx->r17, 0);
            goto L_80080DC8;
    }
    // 0x80080DBC: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x80080DC0: jal         0x8001DAEC
    // 0x80080DC4: addiu       $a1, $s0, 0x68
    ctx->r5 = ADD32(ctx->r16, 0X68);
    func_8001DAEC(rdram, ctx);
        goto after_67;
    // 0x80080DC4: addiu       $a1, $s0, 0x68
    ctx->r5 = ADD32(ctx->r16, 0X68);
    after_67:
L_80080DC8:
    // 0x80080DC8: lw          $a1, 0x90($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X90);
    // 0x80080DCC: jal         0x8001CB9C
    // 0x80080DD0: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    func_8001CB9C(rdram, ctx);
        goto after_68;
    // 0x80080DD0: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    after_68:
    // 0x80080DD4: lw          $a0, 0x4C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X4C);
    // 0x80080DD8: addiu       $v0, $zero, 0x9
    ctx->r2 = ADD32(0, 0X9);
    // 0x80080DDC: andi        $v1, $a0, 0x9
    ctx->r3 = ctx->r4 & 0X9;
    // 0x80080DE0: bne         $v1, $v0, L_80080E20
    if (ctx->r3 != ctx->r2) {
        // 0x80080DE4: addiu       $v0, $zero, 0x8
        ctx->r2 = ADD32(0, 0X8);
            goto L_80080E20;
    }
    // 0x80080DE4: addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
    // 0x80080DE8: lwc1        $f2, 0x78($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X78);
    // 0x80080DEC: lwc1        $f0, 0x50($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X50);
    // 0x80080DF0: add.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x80080DF4: lwc1        $f0, 0x54($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X54);
    // 0x80080DF8: mfc1        $a1, $f2
    ctx->r5 = (int32_t)ctx->f2.u32l;
    // 0x80080DFC: lwc1        $f2, 0x7C($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X7C);
    // 0x80080E00: add.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x80080E04: lwc1        $f0, 0x58($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X58);
    // 0x80080E08: mfc1        $a2, $f2
    ctx->r6 = (int32_t)ctx->f2.u32l;
    // 0x80080E0C: lwc1        $f2, 0x80($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X80);
    // 0x80080E10: add.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x80080E14: mfc1        $a3, $f2
    ctx->r7 = (int32_t)ctx->f2.u32l;
    // 0x80080E18: j           L_80080E50
    // 0x80080E1C: nop

        goto L_80080E50;
    // 0x80080E1C: nop

L_80080E20:
    // 0x80080E20: bne         $v1, $v0, L_80080E3C
    if (ctx->r3 != ctx->r2) {
        // 0x80080E24: andi        $v0, $a0, 0x1
        ctx->r2 = ctx->r4 & 0X1;
            goto L_80080E3C;
    }
    // 0x80080E24: andi        $v0, $a0, 0x1
    ctx->r2 = ctx->r4 & 0X1;
    // 0x80080E28: lw          $a1, 0x78($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X78);
    // 0x80080E2C: lw          $a2, 0x7C($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X7C);
    // 0x80080E30: lw          $a3, 0x80($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X80);
    // 0x80080E34: j           L_80080E50
    // 0x80080E38: nop

        goto L_80080E50;
    // 0x80080E38: nop

L_80080E3C:
    // 0x80080E3C: beq         $v0, $zero, L_80080E58
    if (ctx->r2 == 0) {
        // 0x80080E40: nop
    
            goto L_80080E58;
    }
    // 0x80080E40: nop

    // 0x80080E44: lw          $a1, 0x50($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X50);
    // 0x80080E48: lw          $a2, 0x54($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X54);
    // 0x80080E4C: lw          $a3, 0x58($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X58);
L_80080E50:
    // 0x80080E50: jal         0x8001CA90
    // 0x80080E54: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    func_8001CA90(rdram, ctx);
        goto after_69;
    // 0x80080E54: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    after_69:
L_80080E58:
    // 0x80080E58: lw          $v0, 0x44($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X44);
    // 0x80080E5C: lw          $s0, 0x50($s2)
    ctx->r16 = MEM_W(ctx->r18, 0X50);
    // 0x80080E60: addiu       $s1, $v0, 0x1C
    ctx->r17 = ADD32(ctx->r2, 0X1C);
    // 0x80080E64: jal         0x8001CA50
    // 0x80080E68: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    func_8001CA50(rdram, ctx);
        goto after_70;
    // 0x80080E68: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    after_70:
    // 0x80080E6C: lw          $v0, 0x4C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X4C);
    // 0x80080E70: andi        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 & 0X1;
    // 0x80080E74: beq         $v0, $zero, L_80080EA8
    if (ctx->r2 == 0) {
        // 0x80080E78: nop
    
            goto L_80080EA8;
    }
    // 0x80080E78: nop

    // 0x80080E7C: lwc1        $f0, 0x50($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X50);
    // 0x80080E80: lwc1        $f2, 0x58($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X58);
    // 0x80080E84: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
    // 0x80080E88: neg.s       $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = -ctx->f2.fl;
    // 0x80080E8C: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80080E90: lwc1        $f0, 0x54($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X54);
    // 0x80080E94: mfc1        $a3, $f2
    ctx->r7 = (int32_t)ctx->f2.u32l;
    // 0x80080E98: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
    // 0x80080E9C: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80080EA0: jal         0x8001CA90
    // 0x80080EA4: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    func_8001CA90(rdram, ctx);
        goto after_71;
    // 0x80080EA4: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    after_71:
L_80080EA8:
    // 0x80080EA8: lw          $v0, 0x4C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X4C);
    // 0x80080EAC: andi        $v0, $v0, 0x2
    ctx->r2 = ctx->r2 & 0X2;
    // 0x80080EB0: beq         $v0, $zero, L_80080ECC
    if (ctx->r2 == 0) {
        // 0x80080EB4: nop
    
            goto L_80080ECC;
    }
    // 0x80080EB4: nop

    // 0x80080EB8: lw          $a1, 0x5C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X5C);
    // 0x80080EBC: lw          $a2, 0x60($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X60);
    // 0x80080EC0: lw          $a3, 0x64($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X64);
    // 0x80080EC4: jal         0x8001CB04
    // 0x80080EC8: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    func_8001CB04(rdram, ctx);
        goto after_72;
    // 0x80080EC8: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    after_72:
L_80080ECC:
    // 0x80080ECC: lw          $v0, 0x4C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X4C);
    // 0x80080ED0: andi        $v0, $v0, 0x4
    ctx->r2 = ctx->r2 & 0X4;
    // 0x80080ED4: beq         $v0, $zero, L_80080EE4
    if (ctx->r2 == 0) {
        // 0x80080ED8: addu        $a0, $s1, $zero
        ctx->r4 = ADD32(ctx->r17, 0);
            goto L_80080EE4;
    }
    // 0x80080ED8: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x80080EDC: jal         0x8001DAEC
    // 0x80080EE0: addiu       $a1, $s0, 0x68
    ctx->r5 = ADD32(ctx->r16, 0X68);
    func_8001DAEC(rdram, ctx);
        goto after_73;
    // 0x80080EE0: addiu       $a1, $s0, 0x68
    ctx->r5 = ADD32(ctx->r16, 0X68);
    after_73:
L_80080EE4:
    // 0x80080EE4: lw          $a1, 0x90($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X90);
    // 0x80080EE8: jal         0x8001CB9C
    // 0x80080EEC: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    func_8001CB9C(rdram, ctx);
        goto after_74;
    // 0x80080EEC: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    after_74:
    // 0x80080EF0: lw          $a0, 0x4C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X4C);
    // 0x80080EF4: addiu       $v0, $zero, 0x9
    ctx->r2 = ADD32(0, 0X9);
    // 0x80080EF8: andi        $v1, $a0, 0x9
    ctx->r3 = ctx->r4 & 0X9;
    // 0x80080EFC: bne         $v1, $v0, L_80080F3C
    if (ctx->r3 != ctx->r2) {
        // 0x80080F00: addiu       $v0, $zero, 0x8
        ctx->r2 = ADD32(0, 0X8);
            goto L_80080F3C;
    }
    // 0x80080F00: addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
    // 0x80080F04: lwc1        $f2, 0x78($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X78);
    // 0x80080F08: lwc1        $f0, 0x50($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X50);
    // 0x80080F0C: add.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x80080F10: lwc1        $f0, 0x54($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X54);
    // 0x80080F14: mfc1        $a1, $f2
    ctx->r5 = (int32_t)ctx->f2.u32l;
    // 0x80080F18: lwc1        $f2, 0x7C($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X7C);
    // 0x80080F1C: add.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x80080F20: lwc1        $f0, 0x58($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X58);
    // 0x80080F24: mfc1        $a2, $f2
    ctx->r6 = (int32_t)ctx->f2.u32l;
    // 0x80080F28: lwc1        $f2, 0x80($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X80);
    // 0x80080F2C: add.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x80080F30: mfc1        $a3, $f2
    ctx->r7 = (int32_t)ctx->f2.u32l;
    // 0x80080F34: j           L_800811C8
    // 0x80080F38: nop

        goto L_800811C8;
    // 0x80080F38: nop

L_80080F3C:
    // 0x80080F3C: bne         $v1, $v0, L_800811B4
    if (ctx->r3 != ctx->r2) {
        // 0x80080F40: andi        $v0, $a0, 0x1
        ctx->r2 = ctx->r4 & 0X1;
            goto L_800811B4;
    }
    // 0x80080F40: andi        $v0, $a0, 0x1
    ctx->r2 = ctx->r4 & 0X1;
    // 0x80080F44: lw          $a1, 0x78($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X78);
    // 0x80080F48: lw          $a2, 0x7C($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X7C);
    // 0x80080F4C: lw          $a3, 0x80($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X80);
    // 0x80080F50: j           L_800811C8
    // 0x80080F54: nop

        goto L_800811C8;
    // 0x80080F54: nop

L_80080F58:
    // 0x80080F58: lw          $v0, 0x40($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X40);
    // 0x80080F5C: lw          $s0, 0x4C($s2)
    ctx->r16 = MEM_W(ctx->r18, 0X4C);
    // 0x80080F60: addiu       $s1, $v0, 0x1C
    ctx->r17 = ADD32(ctx->r2, 0X1C);
    // 0x80080F64: jal         0x8001CA50
    // 0x80080F68: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    func_8001CA50(rdram, ctx);
        goto after_75;
    // 0x80080F68: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    after_75:
    // 0x80080F6C: lw          $v0, 0x4C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X4C);
    // 0x80080F70: andi        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 & 0X1;
    // 0x80080F74: beq         $v0, $zero, L_80080FA8
    if (ctx->r2 == 0) {
        // 0x80080F78: nop
    
            goto L_80080FA8;
    }
    // 0x80080F78: nop

    // 0x80080F7C: lwc1        $f0, 0x50($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X50);
    // 0x80080F80: lwc1        $f2, 0x58($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X58);
    // 0x80080F84: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
    // 0x80080F88: neg.s       $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = -ctx->f2.fl;
    // 0x80080F8C: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80080F90: lwc1        $f0, 0x54($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X54);
    // 0x80080F94: mfc1        $a3, $f2
    ctx->r7 = (int32_t)ctx->f2.u32l;
    // 0x80080F98: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
    // 0x80080F9C: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80080FA0: jal         0x8001CA90
    // 0x80080FA4: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    func_8001CA90(rdram, ctx);
        goto after_76;
    // 0x80080FA4: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    after_76:
L_80080FA8:
    // 0x80080FA8: lw          $v0, 0x4C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X4C);
    // 0x80080FAC: andi        $v0, $v0, 0x2
    ctx->r2 = ctx->r2 & 0X2;
    // 0x80080FB0: beq         $v0, $zero, L_80080FCC
    if (ctx->r2 == 0) {
        // 0x80080FB4: nop
    
            goto L_80080FCC;
    }
    // 0x80080FB4: nop

    // 0x80080FB8: lw          $a1, 0x5C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X5C);
    // 0x80080FBC: lw          $a2, 0x60($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X60);
    // 0x80080FC0: lw          $a3, 0x64($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X64);
    // 0x80080FC4: jal         0x8001CB04
    // 0x80080FC8: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    func_8001CB04(rdram, ctx);
        goto after_77;
    // 0x80080FC8: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    after_77:
L_80080FCC:
    // 0x80080FCC: lw          $v0, 0x4C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X4C);
    // 0x80080FD0: andi        $v0, $v0, 0x4
    ctx->r2 = ctx->r2 & 0X4;
    // 0x80080FD4: beq         $v0, $zero, L_80080FE4
    if (ctx->r2 == 0) {
        // 0x80080FD8: addu        $a0, $s1, $zero
        ctx->r4 = ADD32(ctx->r17, 0);
            goto L_80080FE4;
    }
    // 0x80080FD8: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x80080FDC: jal         0x8001DAEC
    // 0x80080FE0: addiu       $a1, $s0, 0x68
    ctx->r5 = ADD32(ctx->r16, 0X68);
    func_8001DAEC(rdram, ctx);
        goto after_78;
    // 0x80080FE0: addiu       $a1, $s0, 0x68
    ctx->r5 = ADD32(ctx->r16, 0X68);
    after_78:
L_80080FE4:
    // 0x80080FE4: lw          $a1, 0x90($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X90);
    // 0x80080FE8: jal         0x8001CB9C
    // 0x80080FEC: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    func_8001CB9C(rdram, ctx);
        goto after_79;
    // 0x80080FEC: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    after_79:
    // 0x80080FF0: lw          $a1, 0x8C($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X8C);
    // 0x80080FF4: jal         0x8001CCCC
    // 0x80080FF8: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    func_8001CCCC(rdram, ctx);
        goto after_80;
    // 0x80080FF8: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    after_80:
    // 0x80080FFC: lw          $a0, 0x4C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X4C);
    // 0x80081000: addiu       $v0, $zero, 0x9
    ctx->r2 = ADD32(0, 0X9);
    // 0x80081004: andi        $v1, $a0, 0x9
    ctx->r3 = ctx->r4 & 0X9;
    // 0x80081008: bne         $v1, $v0, L_80081048
    if (ctx->r3 != ctx->r2) {
        // 0x8008100C: addiu       $v0, $zero, 0x8
        ctx->r2 = ADD32(0, 0X8);
            goto L_80081048;
    }
    // 0x8008100C: addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
    // 0x80081010: lwc1        $f2, 0x78($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X78);
    // 0x80081014: lwc1        $f0, 0x50($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X50);
    // 0x80081018: add.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x8008101C: lwc1        $f0, 0x54($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X54);
    // 0x80081020: mfc1        $a1, $f2
    ctx->r5 = (int32_t)ctx->f2.u32l;
    // 0x80081024: lwc1        $f2, 0x7C($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X7C);
    // 0x80081028: add.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x8008102C: lwc1        $f0, 0x58($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X58);
    // 0x80081030: mfc1        $a2, $f2
    ctx->r6 = (int32_t)ctx->f2.u32l;
    // 0x80081034: lwc1        $f2, 0x80($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X80);
    // 0x80081038: add.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x8008103C: mfc1        $a3, $f2
    ctx->r7 = (int32_t)ctx->f2.u32l;
    // 0x80081040: j           L_80081078
    // 0x80081044: nop

        goto L_80081078;
    // 0x80081044: nop

L_80081048:
    // 0x80081048: bne         $v1, $v0, L_80081064
    if (ctx->r3 != ctx->r2) {
        // 0x8008104C: andi        $v0, $a0, 0x1
        ctx->r2 = ctx->r4 & 0X1;
            goto L_80081064;
    }
    // 0x8008104C: andi        $v0, $a0, 0x1
    ctx->r2 = ctx->r4 & 0X1;
    // 0x80081050: lw          $a1, 0x78($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X78);
    // 0x80081054: lw          $a2, 0x7C($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X7C);
    // 0x80081058: lw          $a3, 0x80($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X80);
    // 0x8008105C: j           L_80081078
    // 0x80081060: nop

        goto L_80081078;
    // 0x80081060: nop

L_80081064:
    // 0x80081064: beq         $v0, $zero, L_80081080
    if (ctx->r2 == 0) {
        // 0x80081068: nop
    
            goto L_80081080;
    }
    // 0x80081068: nop

    // 0x8008106C: lw          $a1, 0x50($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X50);
    // 0x80081070: lw          $a2, 0x54($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X54);
    // 0x80081074: lw          $a3, 0x58($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X58);
L_80081078:
    // 0x80081078: jal         0x8001CA90
    // 0x8008107C: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    func_8001CA90(rdram, ctx);
        goto after_81;
    // 0x8008107C: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    after_81:
L_80081080:
    // 0x80081080: lw          $v0, 0x44($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X44);
    // 0x80081084: lw          $s0, 0x50($s2)
    ctx->r16 = MEM_W(ctx->r18, 0X50);
    // 0x80081088: addiu       $s1, $v0, 0x1C
    ctx->r17 = ADD32(ctx->r2, 0X1C);
    // 0x8008108C: jal         0x8001CA50
    // 0x80081090: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    func_8001CA50(rdram, ctx);
        goto after_82;
    // 0x80081090: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    after_82:
    // 0x80081094: lw          $v0, 0x4C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X4C);
    // 0x80081098: andi        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 & 0X1;
    // 0x8008109C: beq         $v0, $zero, L_800810D0
    if (ctx->r2 == 0) {
        // 0x800810A0: nop
    
            goto L_800810D0;
    }
    // 0x800810A0: nop

    // 0x800810A4: lwc1        $f0, 0x50($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X50);
    // 0x800810A8: lwc1        $f2, 0x58($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X58);
    // 0x800810AC: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
    // 0x800810B0: neg.s       $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = -ctx->f2.fl;
    // 0x800810B4: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x800810B8: lwc1        $f0, 0x54($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X54);
    // 0x800810BC: mfc1        $a3, $f2
    ctx->r7 = (int32_t)ctx->f2.u32l;
    // 0x800810C0: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
    // 0x800810C4: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x800810C8: jal         0x8001CA90
    // 0x800810CC: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    func_8001CA90(rdram, ctx);
        goto after_83;
    // 0x800810CC: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    after_83:
L_800810D0:
    // 0x800810D0: lw          $v0, 0x4C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X4C);
    // 0x800810D4: andi        $v0, $v0, 0x2
    ctx->r2 = ctx->r2 & 0X2;
    // 0x800810D8: beq         $v0, $zero, L_800810F4
    if (ctx->r2 == 0) {
        // 0x800810DC: nop
    
            goto L_800810F4;
    }
    // 0x800810DC: nop

    // 0x800810E0: lw          $a1, 0x5C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X5C);
    // 0x800810E4: lw          $a2, 0x60($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X60);
    // 0x800810E8: lw          $a3, 0x64($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X64);
    // 0x800810EC: jal         0x8001CB04
    // 0x800810F0: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    func_8001CB04(rdram, ctx);
        goto after_84;
    // 0x800810F0: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    after_84:
L_800810F4:
    // 0x800810F4: lw          $v0, 0x4C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X4C);
    // 0x800810F8: andi        $v0, $v0, 0x4
    ctx->r2 = ctx->r2 & 0X4;
    // 0x800810FC: beq         $v0, $zero, L_8008110C
    if (ctx->r2 == 0) {
        // 0x80081100: addu        $a0, $s1, $zero
        ctx->r4 = ADD32(ctx->r17, 0);
            goto L_8008110C;
    }
    // 0x80081100: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x80081104: jal         0x8001DAEC
    // 0x80081108: addiu       $a1, $s0, 0x68
    ctx->r5 = ADD32(ctx->r16, 0X68);
    func_8001DAEC(rdram, ctx);
        goto after_85;
    // 0x80081108: addiu       $a1, $s0, 0x68
    ctx->r5 = ADD32(ctx->r16, 0X68);
    after_85:
L_8008110C:
    // 0x8008110C: lui         $v1, 0x800A
    ctx->r3 = S32(0X800A << 16);
    // 0x80081110: addiu       $v1, $v1, 0xD9C
    ctx->r3 = ADD32(ctx->r3, 0XD9C);
    // 0x80081114: lh          $a0, 0xA4($s2)
    ctx->r4 = MEM_H(ctx->r18, 0XA4);
    // 0x80081118: lwc1        $f2, 0x9C($s2)
    ctx->f2.u32l = MEM_W(ctx->r18, 0X9C);
    // 0x8008111C: sll         $v0, $a0, 4
    ctx->r2 = S32(ctx->r4 << 4);
    // 0x80081120: subu        $v0, $v0, $a0
    ctx->r2 = SUB32(ctx->r2, ctx->r4);
    // 0x80081124: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80081128: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8008112C: lwc1        $f0, 0x38($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X38);
    // 0x80081130: mul.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x80081134: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80081138: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x8008113C: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80081140: mfc1        $a3, $f2
    ctx->r7 = (int32_t)ctx->f2.u32l;
    // 0x80081144: jal         0x8001CA90
    // 0x80081148: addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    func_8001CA90(rdram, ctx);
        goto after_86;
    // 0x80081148: addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    after_86:
    // 0x8008114C: lw          $a0, 0x4C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X4C);
    // 0x80081150: addiu       $v0, $zero, 0x9
    ctx->r2 = ADD32(0, 0X9);
    // 0x80081154: andi        $v1, $a0, 0x9
    ctx->r3 = ctx->r4 & 0X9;
    // 0x80081158: bne         $v1, $v0, L_80081198
    if (ctx->r3 != ctx->r2) {
        // 0x8008115C: addiu       $v0, $zero, 0x8
        ctx->r2 = ADD32(0, 0X8);
            goto L_80081198;
    }
    // 0x8008115C: addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
    // 0x80081160: lwc1        $f2, 0x78($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X78);
    // 0x80081164: lwc1        $f0, 0x50($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X50);
    // 0x80081168: add.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x8008116C: lwc1        $f0, 0x54($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X54);
    // 0x80081170: mfc1        $a1, $f2
    ctx->r5 = (int32_t)ctx->f2.u32l;
    // 0x80081174: lwc1        $f2, 0x7C($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X7C);
    // 0x80081178: add.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x8008117C: lwc1        $f0, 0x58($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X58);
    // 0x80081180: mfc1        $a2, $f2
    ctx->r6 = (int32_t)ctx->f2.u32l;
    // 0x80081184: lwc1        $f2, 0x80($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X80);
    // 0x80081188: add.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x8008118C: mfc1        $a3, $f2
    ctx->r7 = (int32_t)ctx->f2.u32l;
    // 0x80081190: j           L_800811C8
    // 0x80081194: nop

        goto L_800811C8;
    // 0x80081194: nop

L_80081198:
    // 0x80081198: bne         $v1, $v0, L_800811B4
    if (ctx->r3 != ctx->r2) {
        // 0x8008119C: andi        $v0, $a0, 0x1
        ctx->r2 = ctx->r4 & 0X1;
            goto L_800811B4;
    }
    // 0x8008119C: andi        $v0, $a0, 0x1
    ctx->r2 = ctx->r4 & 0X1;
    // 0x800811A0: lw          $a1, 0x78($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X78);
    // 0x800811A4: lw          $a2, 0x7C($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X7C);
    // 0x800811A8: lw          $a3, 0x80($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X80);
    // 0x800811AC: j           L_800811C8
    // 0x800811B0: nop

        goto L_800811C8;
    // 0x800811B0: nop

L_800811B4:
    // 0x800811B4: beq         $v0, $zero, L_800811D0
    if (ctx->r2 == 0) {
        // 0x800811B8: nop
    
            goto L_800811D0;
    }
    // 0x800811B8: nop

    // 0x800811BC: lw          $a1, 0x50($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X50);
    // 0x800811C0: lw          $a2, 0x54($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X54);
    // 0x800811C4: lw          $a3, 0x58($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X58);
L_800811C8:
    // 0x800811C8: jal         0x8001CA90
    // 0x800811CC: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    func_8001CA90(rdram, ctx);
        goto after_87;
    // 0x800811CC: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    after_87:
L_800811D0:
    // 0x800811D0: lw          $a0, 0x0($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X0);
    // 0x800811D4: lw          $a1, 0x30($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X30);
    // 0x800811D8: lw          $a3, 0x88($s2)
    ctx->r7 = MEM_W(ctx->r18, 0X88);
    // 0x800811DC: jal         0x80057C8C
    // 0x800811E0: addu        $a2, $s2, $zero
    ctx->r6 = ADD32(ctx->r18, 0);
    func_80057C8C(rdram, ctx);
        goto after_88;
    // 0x800811E0: addu        $a2, $s2, $zero
    ctx->r6 = ADD32(ctx->r18, 0);
    after_88:
    // 0x800811E4: j           L_8008132C
    // 0x800811E8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8008132C;
    // 0x800811E8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800811EC:
    // 0x800811EC: lw          $a0, 0x38($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X38);
    // 0x800811F0: jal         0x800F20EC
    // 0x800811F4: addu        $s1, $s0, $zero
    ctx->r17 = ADD32(ctx->r16, 0);
    getNpcCurrentHealth(rdram, ctx);
        goto after_89;
    // 0x800811F4: addu        $s1, $s0, $zero
    ctx->r17 = ADD32(ctx->r16, 0);
    after_89:
    // 0x800811F8: blez        $v0, L_800812FC
    if (SIGNED(ctx->r2) <= 0) {
        // 0x800811FC: nop
    
            goto L_800812FC;
    }
    // 0x800811FC: nop

    // 0x80081200: jal         0x80076250
    // 0x80081204: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_80076250(rdram, ctx);
        goto after_90;
    // 0x80081204: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_90:
    // 0x80081208: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x8008120C: addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    // 0x80081210: addiu       $a2, $s2, 0x24
    ctx->r6 = ADD32(ctx->r18, 0X24);
    // 0x80081214: lui         $a3, 0x41C0
    ctx->r7 = S32(0X41C0 << 16);
    // 0x80081218: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8008121C: lwc1        $f0, -0x25D4($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X25D4);
    // 0x80081220: addiu       $v0, $zero, 0x2A
    ctx->r2 = ADD32(0, 0X2A);
    // 0x80081224: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // 0x80081228: addiu       $v0, $zero, 0x7E
    ctx->r2 = ADD32(0, 0X7E);
    // 0x8008122C: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x80081230: addiu       $v0, $zero, 0x3C
    ctx->r2 = ADD32(0, 0X3C);
    // 0x80081234: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x80081238: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x8008123C: jal         0x800989D8
    // 0x80081240: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    func_800989D8(rdram, ctx);
        goto after_91;
    // 0x80081240: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    after_91:
    // 0x80081244: lw          $a0, 0x38($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X38);
    // 0x80081248: lhu         $a1, 0x6($s0)
    ctx->r5 = MEM_HU(ctx->r16, 0X6);
    // 0x8008124C: jal         0x800F2120
    // 0x80081250: nop

    dealDamageToNpc(rdram, ctx);
        goto after_92;
    // 0x80081250: nop

    after_92:
    // 0x80081254: bgtz        $v0, L_800812FC
    if (SIGNED(ctx->r2) > 0) {
        // 0x80081258: addu        $a1, $s3, $zero
        ctx->r5 = ADD32(ctx->r19, 0);
            goto L_800812FC;
    }
    // 0x80081258: addu        $a1, $s3, $zero
    ctx->r5 = ADD32(ctx->r19, 0);
    // 0x8008125C: lhu         $a0, 0xA8($s2)
    ctx->r4 = MEM_HU(ctx->r18, 0XA8);
    // 0x80081260: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80081264: sh          $v0, 0xAC($s2)
    MEM_H(0XAC, ctx->r18) = ctx->r2;
    // 0x80081268: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x8008126C: sh          $v0, 0xB4($s2)
    MEM_H(0XB4, ctx->r18) = ctx->r2;
    // 0x80081270: jal         0x8003E7D0
    // 0x80081274: sw          $zero, 0xB0($s2)
    MEM_W(0XB0, ctx->r18) = 0;
    func_8003E7D0(rdram, ctx);
        goto after_93;
    // 0x80081274: sw          $zero, 0xB0($s2)
    MEM_W(0XB0, ctx->r18) = 0;
    after_93:
    // 0x80081278: lhu         $a0, 0xAA($s2)
    ctx->r4 = MEM_HU(ctx->r18, 0XAA);
    // 0x8008127C: jal         0x8003E7D0
    // 0x80081280: addu        $a1, $s3, $zero
    ctx->r5 = ADD32(ctx->r19, 0);
    func_8003E7D0(rdram, ctx);
        goto after_94;
    // 0x80081280: addu        $a1, $s3, $zero
    ctx->r5 = ADD32(ctx->r19, 0);
    after_94:
    // 0x80081284: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x80081288: lhu         $a0, -0x6A8C($v0)
    ctx->r4 = MEM_HU(ctx->r2, -0X6A8C);
    // 0x8008128C: jal         0x8003E684
    // 0x80081290: addu        $a1, $s3, $zero
    ctx->r5 = ADD32(ctx->r19, 0);
    func_8003E684(rdram, ctx);
        goto after_95;
    // 0x80081290: addu        $a1, $s3, $zero
    ctx->r5 = ADD32(ctx->r19, 0);
    after_95:
    // 0x80081294: lw          $v1, 0x34($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X34);
    // 0x80081298: lw          $v0, 0x74($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X74);
    // 0x8008129C: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // 0x800812A0: lw          $v0, 0x34($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X34);
    // 0x800812A4: lw          $v0, 0x78($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X78);
    // 0x800812A8: sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    // 0x800812AC: lw          $a0, 0x6C($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X6C);
    // 0x800812B0: lw          $a1, 0x70($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X70);
    // 0x800812B4: lw          $a2, 0x64($v1)
    ctx->r6 = MEM_W(ctx->r3, 0X64);
    // 0x800812B8: lw          $a3, 0x68($v1)
    ctx->r7 = MEM_W(ctx->r3, 0X68);
    // 0x800812BC: jal         0x80065914
    // 0x800812C0: nop

    datItemSetObjectiveBooleanCount(rdram, ctx);
        goto after_96;
    // 0x800812C0: nop

    after_96:
    // 0x800812C4: lw          $a0, 0x38($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X38);
    // 0x800812C8: jal         0x800F2A24
    // 0x800812CC: nop

    func_800F2A24(rdram, ctx);
        goto after_97;
    // 0x800812CC: nop

    after_97:
    // 0x800812D0: jal         0x800F2AA4
    // 0x800812D4: addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    func_800F2AA4(rdram, ctx);
        goto after_98;
    // 0x800812D4: addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    after_98:
    // 0x800812D8: addiu       $v0, $zero, 0xF
    ctx->r2 = ADD32(0, 0XF);
    // 0x800812DC: sb          $v0, 0x140($sp)
    MEM_B(0X140, ctx->r29) = ctx->r2;
    // 0x800812E0: lhu         $v0, 0x16($s3)
    ctx->r2 = MEM_HU(ctx->r19, 0X16);
    // 0x800812E4: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    // 0x800812E8: sh          $zero, 0x12A($sp)
    MEM_H(0X12A, ctx->r29) = 0;
    // 0x800812EC: sh          $v0, 0x128($sp)
    MEM_H(0X128, ctx->r29) = ctx->r2;
    // 0x800812F0: lhu         $a0, 0xA6($s2)
    ctx->r4 = MEM_HU(ctx->r18, 0XA6);
    // 0x800812F4: jal         0x8003E8DC
    // 0x800812F8: addiu       $a2, $sp, 0x128
    ctx->r6 = ADD32(ctx->r29, 0X128);
    slotDispatcherIter(rdram, ctx);
        goto after_99;
    // 0x800812F8: addiu       $a2, $sp, 0x128
    ctx->r6 = ADD32(ctx->r29, 0X128);
    after_99:
L_800812FC:
    // 0x800812FC: lhu         $v1, 0x0($s1)
    ctx->r3 = MEM_HU(ctx->r17, 0X0);
    // 0x80081300: ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
    // 0x80081304: beq         $v1, $v0, L_8008132C
    if (ctx->r3 == ctx->r2) {
        // 0x80081308: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_8008132C;
    }
    // 0x80081308: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8008130C: jal         0x8003ED74
    // 0x80081310: addu        $a0, $v1, $zero
    ctx->r4 = ADD32(ctx->r3, 0);
    func_8003ED74(rdram, ctx);
        goto after_100;
    // 0x80081310: addu        $a0, $v1, $zero
    ctx->r4 = ADD32(ctx->r3, 0);
    after_100:
    // 0x80081314: j           L_8008132C
    // 0x80081318: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8008132C;
    // 0x80081318: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8008131C:
    // 0x8008131C: addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    // 0x80081320: jal         0x800EFD80
    // 0x80081324: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    func_800EFD80(rdram, ctx);
        goto after_101;
    // 0x80081324: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    after_101:
L_80081328:
    // 0x80081328: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8008132C:
    // 0x8008132C: lw          $ra, 0x198($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X198);
    // 0x80081330: lw          $s3, 0x194($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X194);
    // 0x80081334: lw          $s2, 0x190($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X190);
    // 0x80081338: lw          $s1, 0x18C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18C);
    // 0x8008133C: lw          $s0, 0x188($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X188);
    // 0x80081340: ldc1        $f22, 0x1A8($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X1A8);
    // 0x80081344: ldc1        $f20, 0x1A0($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X1A0);
    // 0x80081348: jr          $ra
    // 0x8008134C: addiu       $sp, $sp, 0x1B0
    ctx->r29 = ADD32(ctx->r29, 0X1B0);
    return;
    // 0x8008134C: addiu       $sp, $sp, 0x1B0
    ctx->r29 = ADD32(ctx->r29, 0X1B0);
;}
RECOMP_FUNC void npcShieldGeneratorUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80081350: addiu       $sp, $sp, -0x1B0
    ctx->r29 = ADD32(ctx->r29, -0X1B0);
    // 0x80081354: sw          $s5, 0x17C($sp)
    MEM_W(0X17C, ctx->r29) = ctx->r21;
    // 0x80081358: addu        $s5, $a0, $zero
    ctx->r21 = ADD32(ctx->r4, 0);
    // 0x8008135C: sw          $s0, 0x168($sp)
    MEM_W(0X168, ctx->r29) = ctx->r16;
    // 0x80081360: andi        $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 & 0XFFFF;
    // 0x80081364: addiu       $v1, $a1, -0x1
    ctx->r3 = ADD32(ctx->r5, -0X1);
    // 0x80081368: sltiu       $v0, $v1, 0x7
    ctx->r2 = ctx->r3 < 0X7 ? 1 : 0;
    // 0x8008136C: sw          $ra, 0x180($sp)
    MEM_W(0X180, ctx->r29) = ctx->r31;
    // 0x80081370: sw          $s4, 0x178($sp)
    MEM_W(0X178, ctx->r29) = ctx->r20;
    // 0x80081374: sw          $s3, 0x174($sp)
    MEM_W(0X174, ctx->r29) = ctx->r19;
    // 0x80081378: sw          $s2, 0x170($sp)
    MEM_W(0X170, ctx->r29) = ctx->r18;
    // 0x8008137C: sw          $s1, 0x16C($sp)
    MEM_W(0X16C, ctx->r29) = ctx->r17;
    // 0x80081380: sdc1        $f28, 0x1A8($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0X1A8, ctx->r29);
    // 0x80081384: sdc1        $f26, 0x1A0($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X1A0, ctx->r29);
    // 0x80081388: sdc1        $f24, 0x198($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X198, ctx->r29);
    // 0x8008138C: sdc1        $f22, 0x190($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X190, ctx->r29);
    // 0x80081390: sdc1        $f20, 0x188($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X188, ctx->r29);
    // 0x80081394: lw          $s2, 0x4($s5)
    ctx->r18 = MEM_W(ctx->r21, 0X4);
    // 0x80081398: beq         $v0, $zero, L_80081A80
    if (ctx->r2 == 0) {
        // 0x8008139C: addu        $s0, $a2, $zero
        ctx->r16 = ADD32(ctx->r6, 0);
            goto L_80081A80;
    }
    // 0x8008139C: addu        $s0, $a2, $zero
    ctx->r16 = ADD32(ctx->r6, 0);
    // 0x800813A0: lui         $v0, 0x8004
    ctx->r2 = S32(0X8004 << 16);
    // 0x800813A4: addiu       $v0, $v0, -0x25C8
    ctx->r2 = ADD32(ctx->r2, -0X25C8);
    // 0x800813A8: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x800813AC: addu        $v1, $v1, $v0
    gpr jr_addend_800813B4 = ctx->r3;
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x800813B0: lw          $v0, 0x0($v1)
    ctx->r2 = ADD32(ctx->r3, 0X0);
    // 0x800813B4: jr          $v0
    // 0x800813B8: nop

    switch (jr_addend_800813B4 >> 2) {
        case 0: goto L_800813BC; break;
        case 1: goto L_800815C8; break;
        case 2: goto L_800815FC; break;
        case 3: goto L_80081914; break;
        case 4: goto L_80081960; break;
        case 5: goto L_80081A80; break;
        case 6: goto L_80081A74; break;
        default: switch_error(__func__, 0x800813B4, 0x8003DA38);
    }
    // 0x800813B8: nop

L_800813BC:
    // 0x800813BC: lui         $a0, 0x8004
    ctx->r4 = S32(0X8004 << 16);
    // 0x800813C0: addiu       $a0, $a0, -0x25D0
    ctx->r4 = ADD32(ctx->r4, -0X25D0);
    // 0x800813C4: jal         0x80056EB0
    // 0x800813C8: addu        $s1, $s0, $zero
    ctx->r17 = ADD32(ctx->r16, 0);
    walkMeshdef0List(rdram, ctx);
        goto after_0;
    // 0x800813C8: addu        $s1, $s0, $zero
    ctx->r17 = ADD32(ctx->r16, 0);
    after_0:
    // 0x800813CC: sw          $v0, 0x30($s2)
    MEM_W(0X30, ctx->r18) = ctx->r2;
    // 0x800813D0: addu        $v1, $s2, $zero
    ctx->r3 = ADD32(ctx->r18, 0);
    // 0x800813D4: addu        $v0, $s1, $zero
    ctx->r2 = ADD32(ctx->r17, 0);
    // 0x800813D8: addiu       $a0, $s1, 0x30
    ctx->r4 = ADD32(ctx->r17, 0X30);
L_800813DC:
    // 0x800813DC: lw          $t0, 0x0($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X0);
    // 0x800813E0: lw          $t1, 0x4($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X4);
    // 0x800813E4: lw          $t2, 0x8($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X8);
    // 0x800813E8: lw          $t3, 0xC($v0)
    ctx->r11 = MEM_W(ctx->r2, 0XC);
    // 0x800813EC: sw          $t0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r8;
    // 0x800813F0: sw          $t1, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r9;
    // 0x800813F4: sw          $t2, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r10;
    // 0x800813F8: sw          $t3, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r11;
    // 0x800813FC: addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
    // 0x80081400: bne         $v0, $a0, L_800813DC
    if (ctx->r2 != ctx->r4) {
        // 0x80081404: addiu       $v1, $v1, 0x10
        ctx->r3 = ADD32(ctx->r3, 0X10);
            goto L_800813DC;
    }
    // 0x80081404: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
    // 0x80081408: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x8008140C: lw          $v0, 0x30($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X30);
    // 0x80081410: swc1        $f20, 0x2C($s2)
    MEM_W(0X2C, ctx->r18) = ctx->f20.u32l;
    // 0x80081414: swc1        $f20, 0x28($s2)
    MEM_W(0X28, ctx->r18) = ctx->f20.u32l;
    // 0x80081418: swc1        $f20, 0x24($s2)
    MEM_W(0X24, ctx->r18) = ctx->f20.u32l;
    // 0x8008141C: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x80081420: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80081424: lwc1        $f22, -0x25AC($at)
    ctx->f22.u32l = MEM_W(ctx->r1, -0X25AC);
    // 0x80081428: lwc1        $f0, 0x34($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X34);
    // 0x8008142C: lwc1        $f2, 0x30($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0X30);
    // 0x80081430: div.s       $f0, $f22, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = DIV_S(ctx->f22.fl, ctx->f0.fl);
    // 0x80081434: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x80081438: addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    // 0x8008143C: lw          $a0, 0x30($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X30);
    // 0x80081440: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80081444: addiu       $a0, $a0, 0x28
    ctx->r4 = ADD32(ctx->r4, 0X28);
    // 0x80081448: jal         0x80059B50
    // 0x8008144C: sw          $a2, 0x3C($s2)
    MEM_W(0X3C, ctx->r18) = ctx->r6;
    func_80059B50(rdram, ctx);
        goto after_1;
    // 0x8008144C: sw          $a2, 0x3C($s2)
    MEM_W(0X3C, ctx->r18) = ctx->r6;
    after_1:
    // 0x80081450: lui         $s0, 0x8014
    ctx->r16 = S32(0X8014 << 16);
    // 0x80081454: sw          $s2, 0x8($s5)
    MEM_W(0X8, ctx->r21) = ctx->r18;
    // 0x80081458: lw          $v0, 0x30($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X30);
    // 0x8008145C: addiu       $s0, $s0, -0x6AA0
    ctx->r16 = ADD32(ctx->r16, -0X6AA0);
    // 0x80081460: sw          $v0, 0xC($s5)
    MEM_W(0XC, ctx->r21) = ctx->r2;
    // 0x80081464: lhu         $a0, 0x1C($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X1C);
    // 0x80081468: jal         0x8003E684
    // 0x8008146C: addu        $a1, $s5, $zero
    ctx->r5 = ADD32(ctx->r21, 0);
    func_8003E684(rdram, ctx);
        goto after_2;
    // 0x8008146C: addu        $a1, $s5, $zero
    ctx->r5 = ADD32(ctx->r21, 0);
    after_2:
    // 0x80081470: sh          $v0, 0x78($s2)
    MEM_H(0X78, ctx->r18) = ctx->r2;
    // 0x80081474: lhu         $a0, 0xC($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0XC);
    // 0x80081478: jal         0x8003E684
    // 0x8008147C: addu        $a1, $s5, $zero
    ctx->r5 = ADD32(ctx->r21, 0);
    func_8003E684(rdram, ctx);
        goto after_3;
    // 0x8008147C: addu        $a1, $s5, $zero
    ctx->r5 = ADD32(ctx->r21, 0);
    after_3:
    // 0x80081480: lw          $v1, 0x30($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X30);
    // 0x80081484: sh          $v0, 0x7A($s2)
    MEM_H(0X7A, ctx->r18) = ctx->r2;
    // 0x80081488: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8008148C: lwc1        $f2, 0x3C($s2)
    ctx->f2.u32l = MEM_W(ctx->r18, 0X3C);
    // 0x80081490: lwc1        $f0, 0x44($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X44);
    // 0x80081494: addiu       $a0, $s2, 0x34
    ctx->r4 = ADD32(ctx->r18, 0X34);
    // 0x80081498: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x8008149C: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x800814A0: addu        $a2, $s5, $zero
    ctx->r6 = ADD32(ctx->r21, 0);
    // 0x800814A4: lui         $a3, 0x8008
    ctx->r7 = S32(0X8008 << 16);
    // 0x800814A8: addiu       $a3, $a3, 0x221C
    ctx->r7 = ADD32(ctx->r7, 0X221C);
    // 0x800814AC: swc1        $f0, 0x38($s2)
    MEM_W(0X38, ctx->r18) = ctx->f0.u32l;
    // 0x800814B0: jal         0x800EC588
    // 0x800814B4: sw          $s1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r17;
    func_800EC588(rdram, ctx);
        goto after_4;
    // 0x800814B4: sw          $s1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r17;
    after_4:
    // 0x800814B8: lhu         $v0, 0x44($s1)
    ctx->r2 = MEM_HU(ctx->r17, 0X44);
    // 0x800814BC: sh          $v0, 0x70($s2)
    MEM_H(0X70, ctx->r18) = ctx->r2;
    // 0x800814C0: lhu         $a0, 0x44($s1)
    ctx->r4 = MEM_HU(ctx->r17, 0X44);
    // 0x800814C4: jal         0x8004015C
    // 0x800814C8: nop

    func_8004015C(rdram, ctx);
        goto after_5;
    // 0x800814C8: nop

    after_5:
    // 0x800814CC: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    // 0x800814D0: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    // 0x800814D4: mfc1        $a2, $f22
    ctx->r6 = (int32_t)ctx->f22.u32l;
    // 0x800814D8: jal         0x80059B50
    // 0x800814DC: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    func_80059B50(rdram, ctx);
        goto after_6;
    // 0x800814DC: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    after_6:
    // 0x800814E0: addiu       $s1, $sp, 0x58
    ctx->r17 = ADD32(ctx->r29, 0X58);
    // 0x800814E4: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x800814E8: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    // 0x800814EC: swc1        $f20, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f20.u32l;
    // 0x800814F0: swc1        $f20, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f20.u32l;
    // 0x800814F4: jal         0x8001C774
    // 0x800814F8: swc1        $f20, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f20.u32l;
    func_8001C774(rdram, ctx);
        goto after_7;
    // 0x800814F8: swc1        $f20, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f20.u32l;
    after_7:
    // 0x800814FC: lwc1        $f0, 0x0($s2)
    ctx->f0.u32l = MEM_W(ctx->r18, 0X0);
    // 0x80081500: lwc1        $f2, 0x0($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X0);
    // 0x80081504: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x80081508: swc1        $f0, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->f0.u32l;
    // 0x8008150C: lwc1        $f0, 0x4($s2)
    ctx->f0.u32l = MEM_W(ctx->r18, 0X4);
    // 0x80081510: lwc1        $f2, 0x4($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X4);
    // 0x80081514: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x80081518: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x8008151C: swc1        $f0, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->f0.u32l;
    // 0x80081520: lwc1        $f0, 0x8($s2)
    ctx->f0.u32l = MEM_W(ctx->r18, 0X8);
    // 0x80081524: lwc1        $f2, 0x8($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X8);
    // 0x80081528: addiu       $a1, $sp, 0x88
    ctx->r5 = ADD32(ctx->r29, 0X88);
    // 0x8008152C: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x80081530: addiu       $s0, $sp, 0x98
    ctx->r16 = ADD32(ctx->r29, 0X98);
    // 0x80081534: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    // 0x80081538: jal         0x800193E8
    // 0x8008153C: swc1        $f0, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->f0.u32l;
    func_800193E8(rdram, ctx);
        goto after_8;
    // 0x8008153C: swc1        $f0, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->f0.u32l;
    after_8:
    // 0x80081540: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x80081544: addiu       $a1, $s2, 0xC
    ctx->r5 = ADD32(ctx->r18, 0XC);
    // 0x80081548: jal         0x800193E8
    // 0x8008154C: addiu       $a2, $sp, 0xA4
    ctx->r6 = ADD32(ctx->r29, 0XA4);
    func_800193E8(rdram, ctx);
        goto after_9;
    // 0x8008154C: addiu       $a2, $sp, 0xA4
    ctx->r6 = ADD32(ctx->r29, 0XA4);
    after_9:
    // 0x80081550: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x80081554: addiu       $a1, $s2, 0x18
    ctx->r5 = ADD32(ctx->r18, 0X18);
    // 0x80081558: jal         0x800193E8
    // 0x8008155C: addiu       $a2, $sp, 0xB0
    ctx->r6 = ADD32(ctx->r29, 0XB0);
    func_800193E8(rdram, ctx);
        goto after_10;
    // 0x8008155C: addiu       $a2, $sp, 0xB0
    ctx->r6 = ADD32(ctx->r29, 0XB0);
    after_10:
    // 0x80081560: addiu       $a0, $s2, 0x40
    ctx->r4 = ADD32(ctx->r18, 0X40);
    // 0x80081564: mfc1        $a2, $f22
    ctx->r6 = (int32_t)ctx->f22.u32l;
    // 0x80081568: jal         0x80059B50
    // 0x8008156C: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    func_80059B50(rdram, ctx);
        goto after_11;
    // 0x8008156C: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    after_11:
    // 0x80081570: addiu       $a0, $s2, 0x80
    ctx->r4 = ADD32(ctx->r18, 0X80);
    // 0x80081574: addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    // 0x80081578: addiu       $a2, $a1, 0x24
    ctx->r6 = ADD32(ctx->r5, 0X24);
    // 0x8008157C: lui         $a3, 0x4190
    ctx->r7 = S32(0X4190 << 16);
    // 0x80081580: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80081584: lwc1        $f0, -0x25A8($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X25A8);
    // 0x80081588: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8008158C: sb          $v0, 0xC4($a1)
    MEM_B(0XC4, ctx->r5) = ctx->r2;
    // 0x80081590: addiu       $v0, $zero, 0x7
    ctx->r2 = ADD32(0, 0X7);
    // 0x80081594: sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    // 0x80081598: addiu       $v0, $zero, 0x66
    ctx->r2 = ADD32(0, 0X66);
    // 0x8008159C: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // 0x800815A0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800815A4: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x800815A8: addiu       $v0, $zero, 0x7D
    ctx->r2 = ADD32(0, 0X7D);
    // 0x800815AC: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x800815B0: addiu       $v0, $zero, 0x50
    ctx->r2 = ADD32(0, 0X50);
    // 0x800815B4: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x800815B8: jal         0x80098BDC
    // 0x800815BC: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    func_80098BDC(rdram, ctx);
        goto after_12;
    // 0x800815BC: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    after_12:
    // 0x800815C0: j           L_80081A84
    // 0x800815C4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80081A84;
    // 0x800815C4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800815C8:
    // 0x800815C8: lbu         $v1, 0xC4($s2)
    ctx->r3 = MEM_BU(ctx->r18, 0XC4);
    // 0x800815CC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800815D0: bne         $v1, $v0, L_800815E0
    if (ctx->r3 != ctx->r2) {
        // 0x800815D4: nop
    
            goto L_800815E0;
    }
    // 0x800815D4: nop

    // 0x800815D8: jal         0x80098DE0
    // 0x800815DC: addiu       $a0, $s2, 0x80
    ctx->r4 = ADD32(ctx->r18, 0X80);
    func_80098DE0(rdram, ctx);
        goto after_13;
    // 0x800815DC: addiu       $a0, $s2, 0x80
    ctx->r4 = ADD32(ctx->r18, 0X80);
    after_13:
L_800815E0:
    // 0x800815E0: jal         0x800EC684
    // 0x800815E4: addiu       $a0, $s2, 0x34
    ctx->r4 = ADD32(ctx->r18, 0X34);
    func_800EC684(rdram, ctx);
        goto after_14;
    // 0x800815E4: addiu       $a0, $s2, 0x34
    ctx->r4 = ADD32(ctx->r18, 0X34);
    after_14:
    // 0x800815E8: lw          $a0, 0x30($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X30);
    // 0x800815EC: jal         0x8005779C
    // 0x800815F0: nop

    func_8005779C(rdram, ctx);
        goto after_15;
    // 0x800815F0: nop

    after_15:
    // 0x800815F4: j           L_80081A84
    // 0x800815F8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80081A84;
    // 0x800815F8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800815FC:
    // 0x800815FC: lhu         $a0, 0x70($s2)
    ctx->r4 = MEM_HU(ctx->r18, 0X70);
    // 0x80081600: jal         0x8004015C
    // 0x80081604: nop

    func_8004015C(rdram, ctx);
        goto after_16;
    // 0x80081604: nop

    after_16:
    // 0x80081608: addiu       $s0, $sp, 0xC8
    ctx->r16 = ADD32(ctx->r29, 0XC8);
    // 0x8008160C: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x80081610: addu        $s1, $v0, $zero
    ctx->r17 = ADD32(ctx->r2, 0);
    // 0x80081614: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x80081618: jal         0x80059B50
    // 0x8008161C: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    func_80059B50(rdram, ctx);
        goto after_17;
    // 0x8008161C: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    after_17:
    // 0x80081620: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x80081624: addiu       $a1, $s2, 0x40
    ctx->r5 = ADD32(ctx->r18, 0X40);
    // 0x80081628: addiu       $s0, $sp, 0xF8
    ctx->r16 = ADD32(ctx->r29, 0XF8);
    // 0x8008162C: jal         0x800191C4
    // 0x80081630: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    func_800191C4(rdram, ctx);
        goto after_18;
    // 0x80081630: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    after_18:
    // 0x80081634: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // 0x80081638: jal         0x80059D18
    // 0x8008163C: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    func_80059D18(rdram, ctx);
        goto after_19;
    // 0x8008163C: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    after_19:
    // 0x80081640: lw          $t0, 0x24($s1)
    ctx->r8 = MEM_W(ctx->r17, 0X24);
    // 0x80081644: lw          $t1, 0x28($s1)
    ctx->r9 = MEM_W(ctx->r17, 0X28);
    // 0x80081648: lw          $t2, 0x2C($s1)
    ctx->r10 = MEM_W(ctx->r17, 0X2C);
    // 0x8008164C: sw          $t0, 0x24($s2)
    MEM_W(0X24, ctx->r18) = ctx->r8;
    // 0x80081650: sw          $t1, 0x28($s2)
    MEM_W(0X28, ctx->r18) = ctx->r9;
    // 0x80081654: sw          $t2, 0x2C($s2)
    MEM_W(0X2C, ctx->r18) = ctx->r10;
    // 0x80081658: lh          $v1, 0x7C($s2)
    ctx->r3 = MEM_H(ctx->r18, 0X7C);
    // 0x8008165C: beq         $v1, $zero, L_80081900
    if (ctx->r3 == 0) {
        // 0x80081660: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80081900;
    }
    // 0x80081660: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80081664: bne         $v1, $v0, L_80081900
    if (ctx->r3 != ctx->r2) {
        // 0x80081668: nop
    
            goto L_80081900;
    }
    // 0x80081668: nop

    // 0x8008166C: jal         0x80003430
    // 0x80081670: addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
    rand_recomp(rdram, ctx);
        goto after_20;
    // 0x80081670: addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
    after_20:
    // 0x80081674: lui         $v1, 0x5555
    ctx->r3 = S32(0X5555 << 16);
    // 0x80081678: ori         $v1, $v1, 0x5556
    ctx->r3 = ctx->r3 | 0X5556;
    // 0x8008167C: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x80081680: sra         $a0, $v0, 16
    ctx->r4 = S32(SIGNED(ctx->r2) >> 16);
    // 0x80081684: mult        $a0, $v1
    result = S64(S32(ctx->r4)) * S64(S32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80081688: sra         $v0, $v0, 31
    ctx->r2 = S32(SIGNED(ctx->r2) >> 31);
    // 0x8008168C: mfhi        $t0
    ctx->r8 = hi;
    // 0x80081690: subu        $v0, $t0, $v0
    ctx->r2 = SUB32(ctx->r8, ctx->r2);
    // 0x80081694: sll         $v1, $v0, 1
    ctx->r3 = S32(ctx->r2 << 1);
    // 0x80081698: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x8008169C: subu        $a0, $a0, $v1
    ctx->r4 = SUB32(ctx->r4, ctx->r3);
    // 0x800816A0: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x800816A4: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    // 0x800816A8: addiu       $s4, $a0, 0x7
    ctx->r20 = ADD32(ctx->r4, 0X7);
    // 0x800816AC: blez        $s4, L_800817FC
    if (SIGNED(ctx->r20) <= 0) {
        // 0x800816B0: addiu       $s3, $sp, 0x128
        ctx->r19 = ADD32(ctx->r29, 0X128);
            goto L_800817FC;
    }
    // 0x800816B0: addiu       $s3, $sp, 0x128
    ctx->r19 = ADD32(ctx->r29, 0X128);
    // 0x800816B4: addiu       $s1, $sp, 0x138
    ctx->r17 = ADD32(ctx->r29, 0X138);
    // 0x800816B8: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x800816BC: lwc1        $f28, -0x25A4($at)
    ctx->f28.u32l = MEM_W(ctx->r1, -0X25A4);
    // 0x800816C0: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x800816C4: lwc1        $f26, -0x25A0($at)
    ctx->f26.u32l = MEM_W(ctx->r1, -0X25A0);
    // 0x800816C8: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x800816CC: lwc1        $f24, -0x259C($at)
    ctx->f24.u32l = MEM_W(ctx->r1, -0X259C);
    // 0x800816D0: addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
L_800816D4:
    // 0x800816D4: lwc1        $f0, 0x38($s2)
    ctx->f0.u32l = MEM_W(ctx->r18, 0X38);
    // 0x800816D8: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    // 0x800816DC: div.s       $f0, $f0, $f28
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f28.fl);
    // 0x800816E0: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x800816E4: addiu       $a3, $zero, 0x3C
    ctx->r7 = ADD32(0, 0X3C);
    // 0x800816E8: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x800816EC: jal         0x8007202C
    // 0x800816F0: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    func_8007202C(rdram, ctx);
        goto after_21;
    // 0x800816F0: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    after_21:
    // 0x800816F4: lwc1        $f0, 0x128($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X128);
    // 0x800816F8: lwc1        $f2, 0x0($s2)
    ctx->f2.u32l = MEM_W(ctx->r18, 0X0);
    // 0x800816FC: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x80081700: swc1        $f0, 0x128($sp)
    MEM_W(0X128, ctx->r29) = ctx->f0.u32l;
    // 0x80081704: lwc1        $f0, 0x12C($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X12C);
    // 0x80081708: lwc1        $f2, 0x4($s2)
    ctx->f2.u32l = MEM_W(ctx->r18, 0X4);
    // 0x8008170C: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x80081710: swc1        $f0, 0x12C($sp)
    MEM_W(0X12C, ctx->r29) = ctx->f0.u32l;
    // 0x80081714: lwc1        $f0, 0x130($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X130);
    // 0x80081718: lwc1        $f2, 0x8($s2)
    ctx->f2.u32l = MEM_W(ctx->r18, 0X8);
    // 0x8008171C: mfc1        $a1, $f26
    ctx->r5 = (int32_t)ctx->f26.u32l;
    // 0x80081720: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x80081724: mfc1        $a2, $f28
    ctx->r6 = (int32_t)ctx->f28.u32l;
    // 0x80081728: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x8008172C: jal         0x80072300
    // 0x80081730: swc1        $f0, 0x130($sp)
    MEM_W(0X130, ctx->r29) = ctx->f0.u32l;
    func_80072300(rdram, ctx);
        goto after_22;
    // 0x80081730: swc1        $f0, 0x130($sp)
    MEM_W(0X130, ctx->r29) = ctx->f0.u32l;
    after_22:
    // 0x80081734: jal         0x80003430
    // 0x80081738: nop

    rand_recomp(rdram, ctx);
        goto after_23;
    // 0x80081738: nop

    after_23:
    // 0x8008173C: andi        $v0, $v0, 0x7F
    ctx->r2 = ctx->r2 & 0X7F;
    // 0x80081740: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x80081744: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x80081748: sub.s       $f0, $f0, $f24
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f24.fl;
    // 0x8008174C: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80081750: lwc1        $f2, -0x2598($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X2598);
    // 0x80081754: div.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f2.fl);
    // 0x80081758: abs.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f22.fl = fabsf(ctx->f0.fl);
    // 0x8008175C: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80081760: lwc1        $f0, -0x2594($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X2594);
    // 0x80081764: jal         0x80003430
    // 0x80081768: add.s       $f22, $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f22.fl = ctx->f22.fl + ctx->f0.fl;
    rand_recomp(rdram, ctx);
        goto after_24;
    // 0x80081768: add.s       $f22, $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f22.fl = ctx->f22.fl + ctx->f0.fl;
    after_24:
    // 0x8008176C: andi        $v0, $v0, 0x7F
    ctx->r2 = ctx->r2 & 0X7F;
    // 0x80081770: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x80081774: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x80081778: sub.s       $f0, $f0, $f24
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f24.fl;
    // 0x8008177C: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80081780: lwc1        $f2, -0x2590($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X2590);
    // 0x80081784: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x80081788: abs.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f20.fl = fabsf(ctx->f0.fl);
    // 0x8008178C: jal         0x80003430
    // 0x80081790: add.s       $f20, $f20, $f26
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f20.fl = ctx->f20.fl + ctx->f26.fl;
    rand_recomp(rdram, ctx);
        goto after_25;
    // 0x80081790: add.s       $f20, $f20, $f26
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f20.fl = ctx->f20.fl + ctx->f26.fl;
    after_25:
    // 0x80081794: andi        $v0, $v0, 0x7F
    ctx->r2 = ctx->r2 & 0X7F;
    // 0x80081798: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x8008179C: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x800817A0: sub.s       $f0, $f0, $f24
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f24.fl;
    // 0x800817A4: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x800817A8: lwc1        $f2, -0x258C($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X258C);
    // 0x800817AC: div.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f2.fl);
    // 0x800817B0: abs.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = fabsf(ctx->f0.fl);
    // 0x800817B4: addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    // 0x800817B8: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    // 0x800817BC: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x800817C0: lwc1        $f0, -0x2588($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X2588);
    // 0x800817C4: mfc1        $a2, $f22
    ctx->r6 = (int32_t)ctx->f22.u32l;
    // 0x800817C8: add.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x800817CC: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x800817D0: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x800817D4: jal         0x80072384
    // 0x800817D8: swc1        $f2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f2.u32l;
    func_80072384(rdram, ctx);
        goto after_26;
    // 0x800817D8: swc1        $f2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f2.u32l;
    after_26:
    // 0x800817DC: lui         $a1, 0x3DCC
    ctx->r5 = S32(0X3DCC << 16);
    // 0x800817E0: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    // 0x800817E4: lui         $a2, 0x4000
    ctx->r6 = S32(0X4000 << 16);
    // 0x800817E8: jal         0x80073E4C
    // 0x800817EC: addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    func_80073E4C(rdram, ctx);
        goto after_27;
    // 0x800817EC: addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    after_27:
    // 0x800817F0: slt         $v0, $s0, $s4
    ctx->r2 = SIGNED(ctx->r16) < SIGNED(ctx->r20) ? 1 : 0;
    // 0x800817F4: bne         $v0, $zero, L_800816D4
    if (ctx->r2 != 0) {
        // 0x800817F8: addu        $a0, $s3, $zero
        ctx->r4 = ADD32(ctx->r19, 0);
            goto L_800816D4;
    }
    // 0x800817F8: addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
L_800817FC:
    // 0x800817FC: lwc1        $f2, 0x3C($s2)
    ctx->f2.u32l = MEM_W(ctx->r18, 0X3C);
    // 0x80081800: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80081804: lwc1        $f0, -0x2584($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X2584);
    // 0x80081808: mul.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x8008180C: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x80081810: addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    // 0x80081814: swc1        $f2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f2.u32l;
    // 0x80081818: lwc1        $f0, 0x3C($s2)
    ctx->f0.u32l = MEM_W(ctx->r18, 0X3C);
    // 0x8008181C: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80081820: lwc1        $f2, -0x2580($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X2580);
    // 0x80081824: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // 0x80081828: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x8008182C: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80081830: lwc1        $f20, -0x257C($at)
    ctx->f20.u32l = MEM_W(ctx->r1, -0X257C);
    // 0x80081834: addu        $a3, $a2, $zero
    ctx->r7 = ADD32(ctx->r6, 0);
    // 0x80081838: swc1        $f20, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f20.u32l;
    // 0x8008183C: swc1        $f20, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f20.u32l;
    // 0x80081840: jal         0x80072684
    // 0x80081844: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    func_80072684(rdram, ctx);
        goto after_28;
    // 0x80081844: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    after_28:
    // 0x80081848: lwc1        $f2, 0x3C($s2)
    ctx->f2.u32l = MEM_W(ctx->r18, 0X3C);
    // 0x8008184C: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80081850: lwc1        $f0, -0x2578($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X2578);
    // 0x80081854: mul.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x80081858: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x8008185C: addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    // 0x80081860: swc1        $f2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f2.u32l;
    // 0x80081864: lwc1        $f0, 0x3C($s2)
    ctx->f0.u32l = MEM_W(ctx->r18, 0X3C);
    // 0x80081868: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8008186C: lwc1        $f2, -0x2574($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X2574);
    // 0x80081870: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // 0x80081874: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x80081878: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8008187C: lwc1        $f2, -0x2570($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X2570);
    // 0x80081880: addu        $a3, $a2, $zero
    ctx->r7 = ADD32(ctx->r6, 0);
    // 0x80081884: swc1        $f20, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f20.u32l;
    // 0x80081888: swc1        $f2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f2.u32l;
    // 0x8008188C: jal         0x80072684
    // 0x80081890: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    func_80072684(rdram, ctx);
        goto after_29;
    // 0x80081890: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    after_29:
    // 0x80081894: lwc1        $f2, 0x38($s2)
    ctx->f2.u32l = MEM_W(ctx->r18, 0X38);
    // 0x80081898: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8008189C: lwc1        $f0, -0x256C($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X256C);
    // 0x800818A0: mul.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x800818A4: mfc1        $a1, $f2
    ctx->r5 = (int32_t)ctx->f2.u32l;
    // 0x800818A8: jal         0x800612A4
    // 0x800818AC: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    func_800612A4(rdram, ctx);
        goto after_30;
    // 0x800818AC: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    after_30:
    // 0x800818B0: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x800818B4: addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    // 0x800818B8: addiu       $a2, $a1, 0x24
    ctx->r6 = ADD32(ctx->r5, 0X24);
    // 0x800818BC: lui         $a3, 0x41C0
    ctx->r7 = S32(0X41C0 << 16);
    // 0x800818C0: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x800818C4: lwc1        $f0, -0x2568($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X2568);
    // 0x800818C8: addiu       $v0, $zero, 0x22
    ctx->r2 = ADD32(0, 0X22);
    // 0x800818CC: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // 0x800818D0: addiu       $v0, $zero, 0x7F
    ctx->r2 = ADD32(0, 0X7F);
    // 0x800818D4: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x800818D8: addiu       $v0, $zero, 0x50
    ctx->r2 = ADD32(0, 0X50);
    // 0x800818DC: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x800818E0: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x800818E4: jal         0x800989D8
    // 0x800818E8: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    func_800989D8(rdram, ctx);
        goto after_31;
    // 0x800818E8: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    after_31:
    // 0x800818EC: lhu         $a0, 0x16($s5)
    ctx->r4 = MEM_HU(ctx->r21, 0X16);
    // 0x800818F0: jal         0x8003ED74
    // 0x800818F4: nop

    func_8003ED74(rdram, ctx);
        goto after_32;
    // 0x800818F4: nop

    after_32:
    // 0x800818F8: j           L_80081A84
    // 0x800818FC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80081A84;
    // 0x800818FC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80081900:
    // 0x80081900: lw          $a0, 0x34($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X34);
    // 0x80081904: jal         0x800EC6C0
    // 0x80081908: nop

    func_800EC6C0(rdram, ctx);
        goto after_33;
    // 0x80081908: nop

    after_33:
    // 0x8008190C: j           L_80081A84
    // 0x80081910: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80081A84;
    // 0x80081910: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80081914:
    // 0x80081914: addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    // 0x80081918: lw          $a0, 0x30($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X30);
    // 0x8008191C: lw          $a2, 0x3C($s2)
    ctx->r6 = MEM_W(ctx->r18, 0X3C);
    // 0x80081920: jal         0x80059B50
    // 0x80081924: addiu       $a0, $a0, 0x28
    ctx->r4 = ADD32(ctx->r4, 0X28);
    func_80059B50(rdram, ctx);
        goto after_34;
    // 0x80081924: addiu       $a0, $a0, 0x28
    ctx->r4 = ADD32(ctx->r4, 0X28);
    after_34:
    // 0x80081928: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x8008192C: lw          $a1, 0x30($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X30);
    // 0x80081930: lw          $a3, 0x38($s2)
    ctx->r7 = MEM_W(ctx->r18, 0X38);
    // 0x80081934: jal         0x80057C8C
    // 0x80081938: addu        $a2, $s2, $zero
    ctx->r6 = ADD32(ctx->r18, 0);
    func_80057C8C(rdram, ctx);
        goto after_35;
    // 0x80081938: addu        $a2, $s2, $zero
    ctx->r6 = ADD32(ctx->r18, 0);
    after_35:
    // 0x8008193C: lbu         $v0, 0xC4($s2)
    ctx->r2 = MEM_BU(ctx->r18, 0XC4);
    // 0x80081940: beq         $v0, $zero, L_80081A80
    if (ctx->r2 == 0) {
        // 0x80081944: addiu       $a0, $s2, 0x80
        ctx->r4 = ADD32(ctx->r18, 0X80);
            goto L_80081A80;
    }
    // 0x80081944: addiu       $a0, $s2, 0x80
    ctx->r4 = ADD32(ctx->r18, 0X80);
    // 0x80081948: addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    // 0x8008194C: addiu       $a2, $a1, 0x24
    ctx->r6 = ADD32(ctx->r5, 0X24);
    // 0x80081950: jal         0x800988E8
    // 0x80081954: addiu       $a3, $zero, 0x7D
    ctx->r7 = ADD32(0, 0X7D);
    func_800988E8(rdram, ctx);
        goto after_36;
    // 0x80081954: addiu       $a3, $zero, 0x7D
    ctx->r7 = ADD32(0, 0X7D);
    after_36:
    // 0x80081958: j           L_80081A84
    // 0x8008195C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80081A84;
    // 0x8008195C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80081960:
    // 0x80081960: lhu         $v1, 0x4($s0)
    ctx->r3 = MEM_HU(ctx->r16, 0X4);
    // 0x80081964: addiu       $v0, $zero, 0x7
    ctx->r2 = ADD32(0, 0X7);
    // 0x80081968: bne         $v1, $v0, L_80081984
    if (ctx->r3 != ctx->r2) {
        // 0x8008196C: addu        $s1, $s0, $zero
        ctx->r17 = ADD32(ctx->r16, 0);
            goto L_80081984;
    }
    // 0x8008196C: addu        $s1, $s0, $zero
    ctx->r17 = ADD32(ctx->r16, 0);
    // 0x80081970: lw          $a0, 0x34($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X34);
    // 0x80081974: jal         0x800F20EC
    // 0x80081978: nop

    getNpcCurrentHealth(rdram, ctx);
        goto after_37;
    // 0x80081978: nop

    after_37:
    // 0x8008197C: bltz        $v0, L_80081A54
    if (SIGNED(ctx->r2) < 0) {
        // 0x80081980: nop
    
            goto L_80081A54;
    }
    // 0x80081980: nop

L_80081984:
    // 0x80081984: jal         0x80076250
    // 0x80081988: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_80076250(rdram, ctx);
        goto after_38;
    // 0x80081988: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_38:
    // 0x8008198C: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x80081990: addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    // 0x80081994: addiu       $a2, $s2, 0x24
    ctx->r6 = ADD32(ctx->r18, 0X24);
    // 0x80081998: lui         $a3, 0x41A0
    ctx->r7 = S32(0X41A0 << 16);
    // 0x8008199C: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x800819A0: lwc1        $f0, -0x2564($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X2564);
    // 0x800819A4: addiu       $v0, $zero, 0x2A
    ctx->r2 = ADD32(0, 0X2A);
    // 0x800819A8: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // 0x800819AC: addiu       $v0, $zero, 0x78
    ctx->r2 = ADD32(0, 0X78);
    // 0x800819B0: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x800819B4: addiu       $v0, $zero, 0x3C
    ctx->r2 = ADD32(0, 0X3C);
    // 0x800819B8: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x800819BC: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x800819C0: jal         0x800989D8
    // 0x800819C4: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    func_800989D8(rdram, ctx);
        goto after_39;
    // 0x800819C4: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    after_39:
    // 0x800819C8: lw          $a0, 0x34($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X34);
    // 0x800819CC: lhu         $a1, 0x6($s0)
    ctx->r5 = MEM_HU(ctx->r16, 0X6);
    // 0x800819D0: jal         0x800F2120
    // 0x800819D4: nop

    dealDamageToNpc(rdram, ctx);
        goto after_40;
    // 0x800819D4: nop

    after_40:
    // 0x800819D8: bgtz        $v0, L_80081A54
    if (SIGNED(ctx->r2) > 0) {
        // 0x800819DC: addu        $a1, $s5, $zero
        ctx->r5 = ADD32(ctx->r21, 0);
            goto L_80081A54;
    }
    // 0x800819DC: addu        $a1, $s5, $zero
    ctx->r5 = ADD32(ctx->r21, 0);
    // 0x800819E0: lhu         $a0, 0x78($s2)
    ctx->r4 = MEM_HU(ctx->r18, 0X78);
    // 0x800819E4: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
    // 0x800819E8: jal         0x8003E7D0
    // 0x800819EC: sh          $s0, 0x7C($s2)
    MEM_H(0X7C, ctx->r18) = ctx->r16;
    func_8003E7D0(rdram, ctx);
        goto after_41;
    // 0x800819EC: sh          $s0, 0x7C($s2)
    MEM_H(0X7C, ctx->r18) = ctx->r16;
    after_41:
    // 0x800819F0: lhu         $a0, 0x7A($s2)
    ctx->r4 = MEM_HU(ctx->r18, 0X7A);
    // 0x800819F4: jal         0x8003E7D0
    // 0x800819F8: addu        $a1, $s5, $zero
    ctx->r5 = ADD32(ctx->r21, 0);
    func_8003E7D0(rdram, ctx);
        goto after_42;
    // 0x800819F8: addu        $a1, $s5, $zero
    ctx->r5 = ADD32(ctx->r21, 0);
    after_42:
    // 0x800819FC: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x80081A00: lhu         $a0, -0x6A8C($v0)
    ctx->r4 = MEM_HU(ctx->r2, -0X6A8C);
    // 0x80081A04: jal         0x8003E684
    // 0x80081A08: addu        $a1, $s5, $zero
    ctx->r5 = ADD32(ctx->r21, 0);
    func_8003E684(rdram, ctx);
        goto after_43;
    // 0x80081A08: addu        $a1, $s5, $zero
    ctx->r5 = ADD32(ctx->r21, 0);
    after_43:
    // 0x80081A0C: jal         0x800F2AA4
    // 0x80081A10: addu        $a0, $s5, $zero
    ctx->r4 = ADD32(ctx->r21, 0);
    func_800F2AA4(rdram, ctx);
        goto after_44;
    // 0x80081A10: addu        $a0, $s5, $zero
    ctx->r4 = ADD32(ctx->r21, 0);
    after_44:
    // 0x80081A14: addiu       $v0, $zero, 0xF
    ctx->r2 = ADD32(0, 0XF);
    // 0x80081A18: sb          $v0, 0x160($sp)
    MEM_B(0X160, ctx->r29) = ctx->r2;
    // 0x80081A1C: lhu         $v0, 0x16($s5)
    ctx->r2 = MEM_HU(ctx->r21, 0X16);
    // 0x80081A20: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    // 0x80081A24: sh          $s0, 0x14A($sp)
    MEM_H(0X14A, ctx->r29) = ctx->r16;
    // 0x80081A28: sh          $v0, 0x148($sp)
    MEM_H(0X148, ctx->r29) = ctx->r2;
    // 0x80081A2C: lhu         $a0, 0x70($s2)
    ctx->r4 = MEM_HU(ctx->r18, 0X70);
    // 0x80081A30: jal         0x8003E8DC
    // 0x80081A34: addiu       $a2, $sp, 0x148
    ctx->r6 = ADD32(ctx->r29, 0X148);
    slotDispatcherIter(rdram, ctx);
        goto after_45;
    // 0x80081A34: addiu       $a2, $sp, 0x148
    ctx->r6 = ADD32(ctx->r29, 0X148);
    after_45:
    // 0x80081A38: lbu         $v1, 0xC4($s2)
    ctx->r3 = MEM_BU(ctx->r18, 0XC4);
    // 0x80081A3C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80081A40: bnel        $v1, $v0, L_80081A54
    if (ctx->r3 != ctx->r2) {
        // 0x80081A44: sb          $zero, 0xC4($s2)
        MEM_B(0XC4, ctx->r18) = 0;
            goto L_80081A54;
    }
    goto skip_0;
    // 0x80081A44: sb          $zero, 0xC4($s2)
    MEM_B(0XC4, ctx->r18) = 0;
    skip_0:
    // 0x80081A48: jal         0x80098DE0
    // 0x80081A4C: addiu       $a0, $s2, 0x80
    ctx->r4 = ADD32(ctx->r18, 0X80);
    func_80098DE0(rdram, ctx);
        goto after_46;
    // 0x80081A4C: addiu       $a0, $s2, 0x80
    ctx->r4 = ADD32(ctx->r18, 0X80);
    after_46:
    // 0x80081A50: sb          $zero, 0xC4($s2)
    MEM_B(0XC4, ctx->r18) = 0;
L_80081A54:
    // 0x80081A54: lhu         $v1, 0x0($s1)
    ctx->r3 = MEM_HU(ctx->r17, 0X0);
    // 0x80081A58: ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
    // 0x80081A5C: beq         $v1, $v0, L_80081A84
    if (ctx->r3 == ctx->r2) {
        // 0x80081A60: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80081A84;
    }
    // 0x80081A60: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80081A64: jal         0x8003ED74
    // 0x80081A68: addu        $a0, $v1, $zero
    ctx->r4 = ADD32(ctx->r3, 0);
    func_8003ED74(rdram, ctx);
        goto after_47;
    // 0x80081A68: addu        $a0, $v1, $zero
    ctx->r4 = ADD32(ctx->r3, 0);
    after_47:
    // 0x80081A6C: j           L_80081A84
    // 0x80081A70: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80081A84;
    // 0x80081A70: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80081A74:
    // 0x80081A74: addu        $a0, $s5, $zero
    ctx->r4 = ADD32(ctx->r21, 0);
    // 0x80081A78: jal         0x800EFD80
    // 0x80081A7C: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    func_800EFD80(rdram, ctx);
        goto after_48;
    // 0x80081A7C: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    after_48:
L_80081A80:
    // 0x80081A80: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80081A84:
    // 0x80081A84: lw          $ra, 0x180($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X180);
    // 0x80081A88: lw          $s5, 0x17C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X17C);
    // 0x80081A8C: lw          $s4, 0x178($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X178);
    // 0x80081A90: lw          $s3, 0x174($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X174);
    // 0x80081A94: lw          $s2, 0x170($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X170);
    // 0x80081A98: lw          $s1, 0x16C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X16C);
    // 0x80081A9C: lw          $s0, 0x168($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X168);
    // 0x80081AA0: ldc1        $f28, 0x1A8($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0X1A8);
    // 0x80081AA4: ldc1        $f26, 0x1A0($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X1A0);
    // 0x80081AA8: ldc1        $f24, 0x198($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X198);
    // 0x80081AAC: ldc1        $f22, 0x190($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X190);
    // 0x80081AB0: ldc1        $f20, 0x188($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X188);
    // 0x80081AB4: jr          $ra
    // 0x80081AB8: addiu       $sp, $sp, 0x1B0
    ctx->r29 = ADD32(ctx->r29, 0X1B0);
    return;
    // 0x80081AB8: addiu       $sp, $sp, 0x1B0
    ctx->r29 = ADD32(ctx->r29, 0X1B0);
;}
RECOMP_FUNC void func_80081ABC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80081ABC: addiu       $sp, $sp, -0x98
    ctx->r29 = ADD32(ctx->r29, -0X98);
    // 0x80081AC0: sw          $s3, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r19;
    // 0x80081AC4: addu        $s3, $a0, $zero
    ctx->r19 = ADD32(ctx->r4, 0);
    // 0x80081AC8: sw          $s0, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r16;
    // 0x80081ACC: andi        $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 & 0XFFFF;
    // 0x80081AD0: addiu       $v1, $a1, -0x1
    ctx->r3 = ADD32(ctx->r5, -0X1);
    // 0x80081AD4: sltiu       $v0, $v1, 0x9
    ctx->r2 = ctx->r3 < 0X9 ? 1 : 0;
    // 0x80081AD8: sw          $ra, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r31;
    // 0x80081ADC: sw          $s2, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r18;
    // 0x80081AE0: sw          $s1, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r17;
    // 0x80081AE4: sdc1        $f22, 0x90($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X90, ctx->r29);
    // 0x80081AE8: sdc1        $f20, 0x88($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X88, ctx->r29);
    // 0x80081AEC: lw          $s1, 0x4($s3)
    ctx->r17 = MEM_W(ctx->r19, 0X4);
    // 0x80081AF0: beq         $v0, $zero, L_800820BC
    if (ctx->r2 == 0) {
        // 0x80081AF4: addu        $s0, $a2, $zero
        ctx->r16 = ADD32(ctx->r6, 0);
            goto L_800820BC;
    }
    // 0x80081AF4: addu        $s0, $a2, $zero
    ctx->r16 = ADD32(ctx->r6, 0);
    // 0x80081AF8: lui         $v0, 0x8004
    ctx->r2 = S32(0X8004 << 16);
    // 0x80081AFC: addiu       $v0, $v0, -0x2558
    ctx->r2 = ADD32(ctx->r2, -0X2558);
    // 0x80081B00: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x80081B04: addu        $v1, $v1, $v0
    gpr jr_addend_80081B0C = ctx->r3;
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x80081B08: lw          $v0, 0x0($v1)
    ctx->r2 = ADD32(ctx->r3, 0X0);
    // 0x80081B0C: jr          $v0
    // 0x80081B10: nop

    switch (jr_addend_80081B0C >> 2) {
        case 0: goto L_80081B14; break;
        case 1: goto L_80081D00; break;
        case 2: goto L_80081D2C; break;
        case 3: goto L_80081F90; break;
        case 4: goto L_8008202C; break;
        case 5: goto L_800820BC; break;
        case 6: goto L_800820BC; break;
        case 7: goto L_800820BC; break;
        case 8: goto L_800820A4; break;
        default: switch_error(__func__, 0x80081B0C, 0x8003DAA8);
    }
    // 0x80081B10: nop

L_80081B14:
    // 0x80081B14: addiu       $a0, $zero, 0xA0
    ctx->r4 = ADD32(0, 0XA0);
    // 0x80081B18: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x80081B1C: jal         0x80001ACC
    // 0x80081B20: addu        $s2, $s0, $zero
    ctx->r18 = ADD32(ctx->r16, 0);
    rs_malloc(rdram, ctx);
        goto after_0;
    // 0x80081B20: addu        $s2, $s0, $zero
    ctx->r18 = ADD32(ctx->r16, 0);
    after_0:
    // 0x80081B24: addu        $s1, $v0, $zero
    ctx->r17 = ADD32(ctx->r2, 0);
    // 0x80081B28: lui         $a0, 0x8004
    ctx->r4 = S32(0X8004 << 16);
    // 0x80081B2C: lhu         $v0, 0x14($s3)
    ctx->r2 = MEM_HU(ctx->r19, 0X14);
    // 0x80081B30: addiu       $a0, $a0, -0x2560
    ctx->r4 = ADD32(ctx->r4, -0X2560);
    // 0x80081B34: sw          $s1, 0x4($s3)
    MEM_W(0X4, ctx->r19) = ctx->r17;
    // 0x80081B38: ori         $v0, $v0, 0x100
    ctx->r2 = ctx->r2 | 0X100;
    // 0x80081B3C: jal         0x80056EB0
    // 0x80081B40: sh          $v0, 0x14($s3)
    MEM_H(0X14, ctx->r19) = ctx->r2;
    walkMeshdef0List(rdram, ctx);
        goto after_1;
    // 0x80081B40: sh          $v0, 0x14($s3)
    MEM_H(0X14, ctx->r19) = ctx->r2;
    after_1:
    // 0x80081B44: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // 0x80081B48: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x80081B4C: lui         $a2, 0x1
    ctx->r6 = S32(0X1 << 16);
    // 0x80081B50: addu        $a3, $a1, $zero
    ctx->r7 = ADD32(ctx->r5, 0);
    // 0x80081B54: jal         0x8005955C
    // 0x80081B58: sw          $a0, 0x30($s1)
    MEM_W(0X30, ctx->r17) = ctx->r4;
    func_8005955C(rdram, ctx);
        goto after_2;
    // 0x80081B58: sw          $a0, 0x30($s1)
    MEM_W(0X30, ctx->r17) = ctx->r4;
    after_2:
    // 0x80081B5C: addu        $v1, $s1, $zero
    ctx->r3 = ADD32(ctx->r17, 0);
    // 0x80081B60: addu        $v0, $s2, $zero
    ctx->r2 = ADD32(ctx->r18, 0);
    // 0x80081B64: addiu       $a0, $s2, 0x30
    ctx->r4 = ADD32(ctx->r18, 0X30);
L_80081B68:
    // 0x80081B68: lw          $t0, 0x0($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X0);
    // 0x80081B6C: lw          $t1, 0x4($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X4);
    // 0x80081B70: lw          $t2, 0x8($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X8);
    // 0x80081B74: lw          $t3, 0xC($v0)
    ctx->r11 = MEM_W(ctx->r2, 0XC);
    // 0x80081B78: sw          $t0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r8;
    // 0x80081B7C: sw          $t1, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r9;
    // 0x80081B80: sw          $t2, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r10;
    // 0x80081B84: sw          $t3, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r11;
    // 0x80081B88: addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
    // 0x80081B8C: bne         $v0, $a0, L_80081B68
    if (ctx->r2 != ctx->r4) {
        // 0x80081B90: addiu       $v1, $v1, 0x10
        ctx->r3 = ADD32(ctx->r3, 0X10);
            goto L_80081B68;
    }
    // 0x80081B90: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
    // 0x80081B94: mtc1        $zero, $f22
    ctx->f22.u32l = 0;
    // 0x80081B98: lw          $v0, 0x30($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X30);
    // 0x80081B9C: swc1        $f22, 0x2C($s1)
    MEM_W(0X2C, ctx->r17) = ctx->f22.u32l;
    // 0x80081BA0: swc1        $f22, 0x28($s1)
    MEM_W(0X28, ctx->r17) = ctx->f22.u32l;
    // 0x80081BA4: swc1        $f22, 0x24($s1)
    MEM_W(0X24, ctx->r17) = ctx->f22.u32l;
    // 0x80081BA8: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x80081BAC: lwc1        $f0, 0x30($s2)
    ctx->f0.u32l = MEM_W(ctx->r18, 0X30);
    // 0x80081BB0: lwc1        $f20, 0x34($v0)
    ctx->f20.u32l = MEM_W(ctx->r2, 0X34);
    // 0x80081BB4: mul.s       $f0, $f20, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = MUL_S(ctx->f20.fl, ctx->f0.fl);
    // 0x80081BB8: swc1        $f0, 0x34($s1)
    MEM_W(0X34, ctx->r17) = ctx->f0.u32l;
    // 0x80081BBC: lwc1        $f0, 0x30($s2)
    ctx->f0.u32l = MEM_W(ctx->r18, 0X30);
    // 0x80081BC0: mul.s       $f0, $f20, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = MUL_S(ctx->f20.fl, ctx->f0.fl);
    // 0x80081BC4: swc1        $f0, 0x38($s1)
    MEM_W(0X38, ctx->r17) = ctx->f0.u32l;
    // 0x80081BC8: lwc1        $f0, 0x34($s2)
    ctx->f0.u32l = MEM_W(ctx->r18, 0X34);
    // 0x80081BCC: mul.s       $f0, $f20, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = MUL_S(ctx->f20.fl, ctx->f0.fl);
    // 0x80081BD0: swc1        $f0, 0x3C($s1)
    MEM_W(0X3C, ctx->r17) = ctx->f0.u32l;
    // 0x80081BD4: lwc1        $f0, 0x38($s2)
    ctx->f0.u32l = MEM_W(ctx->r18, 0X38);
    // 0x80081BD8: mul.s       $f0, $f20, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = MUL_S(ctx->f20.fl, ctx->f0.fl);
    // 0x80081BDC: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    // 0x80081BE0: lw          $a0, 0x30($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X30);
    // 0x80081BE4: addiu       $a2, $s1, 0x38
    ctx->r6 = ADD32(ctx->r17, 0X38);
    // 0x80081BE8: addiu       $a0, $a0, 0x28
    ctx->r4 = ADD32(ctx->r4, 0X28);
    // 0x80081BEC: jal         0x80059C24
    // 0x80081BF0: swc1        $f0, 0x40($s1)
    MEM_W(0X40, ctx->r17) = ctx->f0.u32l;
    func_80059C24(rdram, ctx);
        goto after_3;
    // 0x80081BF0: swc1        $f0, 0x40($s1)
    MEM_W(0X40, ctx->r17) = ctx->f0.u32l;
    after_3:
    // 0x80081BF4: lui         $s0, 0x8014
    ctx->r16 = S32(0X8014 << 16);
    // 0x80081BF8: sw          $s1, 0x8($s3)
    MEM_W(0X8, ctx->r19) = ctx->r17;
    // 0x80081BFC: lw          $v0, 0x30($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X30);
    // 0x80081C00: addiu       $s0, $s0, -0x6AA0
    ctx->r16 = ADD32(ctx->r16, -0X6AA0);
    // 0x80081C04: sw          $v0, 0xC($s3)
    MEM_W(0XC, ctx->r19) = ctx->r2;
    // 0x80081C08: lhu         $a0, 0x1C($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X1C);
    // 0x80081C0C: jal         0x8003E684
    // 0x80081C10: addu        $a1, $s3, $zero
    ctx->r5 = ADD32(ctx->r19, 0);
    func_8003E684(rdram, ctx);
        goto after_4;
    // 0x80081C10: addu        $a1, $s3, $zero
    ctx->r5 = ADD32(ctx->r19, 0);
    after_4:
    // 0x80081C14: sh          $v0, 0x4E($s1)
    MEM_H(0X4E, ctx->r17) = ctx->r2;
    // 0x80081C18: lhu         $a0, 0xC($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0XC);
    // 0x80081C1C: jal         0x8003E684
    // 0x80081C20: addu        $a1, $s3, $zero
    ctx->r5 = ADD32(ctx->r19, 0);
    func_8003E684(rdram, ctx);
        goto after_5;
    // 0x80081C20: addu        $a1, $s3, $zero
    ctx->r5 = ADD32(ctx->r19, 0);
    after_5:
    // 0x80081C24: lw          $v1, 0x30($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X30);
    // 0x80081C28: sh          $v0, 0x50($s1)
    MEM_H(0X50, ctx->r17) = ctx->r2;
    // 0x80081C2C: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80081C30: lwc1        $f0, 0x44($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X44);
    // 0x80081C34: mul.s       $f0, $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f20.fl);
    // 0x80081C38: lwc1        $f2, 0x34($s2)
    ctx->f2.u32l = MEM_W(ctx->r18, 0X34);
    // 0x80081C3C: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x80081C40: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80081C44: lwc1        $f2, -0x2534($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X2534);
    // 0x80081C48: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x80081C4C: lui         $a3, 0x4120
    ctx->r7 = S32(0X4120 << 16);
    // 0x80081C50: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80081C54: lwc1        $f20, -0x2530($at)
    ctx->f20.u32l = MEM_W(ctx->r1, -0X2530);
    // 0x80081C58: addiu       $a0, $s1, 0x54
    ctx->r4 = ADD32(ctx->r17, 0X54);
    // 0x80081C5C: sb          $zero, 0x99($s1)
    MEM_B(0X99, ctx->r17) = 0;
    // 0x80081C60: swc1        $f0, 0x44($s1)
    MEM_W(0X44, ctx->r17) = ctx->f0.u32l;
    // 0x80081C64: lhu         $v0, 0x3C($s2)
    ctx->r2 = MEM_HU(ctx->r18, 0X3C);
    // 0x80081C68: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    // 0x80081C6C: sh          $v0, 0x4C($s1)
    MEM_H(0X4C, ctx->r17) = ctx->r2;
    // 0x80081C70: lw          $v0, 0x40($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X40);
    // 0x80081C74: addiu       $a2, $s1, 0x24
    ctx->r6 = ADD32(ctx->r17, 0X24);
    // 0x80081C78: sw          $v0, 0x9C($s1)
    MEM_W(0X9C, ctx->r17) = ctx->r2;
    // 0x80081C7C: lhu         $v1, 0x3E($s2)
    ctx->r3 = MEM_HU(ctx->r18, 0X3E);
    // 0x80081C80: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80081C84: sb          $v0, 0x98($s1)
    MEM_B(0X98, ctx->r17) = ctx->r2;
    // 0x80081C88: addiu       $v0, $zero, 0xF
    ctx->r2 = ADD32(0, 0XF);
    // 0x80081C8C: swc1        $f22, 0x48($s1)
    MEM_W(0X48, ctx->r17) = ctx->f22.u32l;
    // 0x80081C90: sh          $v1, 0x52($s1)
    MEM_H(0X52, ctx->r17) = ctx->r3;
    // 0x80081C94: sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    // 0x80081C98: addiu       $v0, $zero, 0x66
    ctx->r2 = ADD32(0, 0X66);
    // 0x80081C9C: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // 0x80081CA0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80081CA4: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x80081CA8: addiu       $v0, $zero, 0x78
    ctx->r2 = ADD32(0, 0X78);
    // 0x80081CAC: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x80081CB0: addiu       $v0, $zero, 0x28
    ctx->r2 = ADD32(0, 0X28);
    // 0x80081CB4: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    // 0x80081CB8: jal         0x80098BDC
    // 0x80081CBC: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    func_80098BDC(rdram, ctx);
        goto after_6;
    // 0x80081CBC: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    after_6:
    // 0x80081CC0: lwc1        $f0, 0x34($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X34);
    // 0x80081CC4: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80081CC8: lwc1        $f2, -0x252C($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X252C);
    // 0x80081CCC: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x80081CD0: swc1        $f0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f0.u32l;
    // 0x80081CD4: lwc1        $f0, 0x34($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X34);
    // 0x80081CD8: mul.s       $f0, $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f20.fl);
    // 0x80081CDC: swc1        $f0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f0.u32l;
    // 0x80081CE0: lwc1        $f0, 0x34($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X34);
    // 0x80081CE4: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x80081CE8: swc1        $f0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f0.u32l;
    // 0x80081CEC: lhu         $a0, 0x16($s3)
    ctx->r4 = MEM_HU(ctx->r19, 0X16);
    // 0x80081CF0: jal         0x800777F0
    // 0x80081CF4: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    func_800777F0(rdram, ctx);
        goto after_7;
    // 0x80081CF4: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    after_7:
    // 0x80081CF8: j           L_800820BC
    // 0x80081CFC: sh          $v0, 0x9A($s1)
    MEM_H(0X9A, ctx->r17) = ctx->r2;
        goto L_800820BC;
    // 0x80081CFC: sh          $v0, 0x9A($s1)
    MEM_H(0X9A, ctx->r17) = ctx->r2;
L_80081D00:
    // 0x80081D00: lbu         $v1, 0x98($s1)
    ctx->r3 = MEM_BU(ctx->r17, 0X98);
    // 0x80081D04: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80081D08: bne         $v1, $v0, L_80081D18
    if (ctx->r3 != ctx->r2) {
        // 0x80081D0C: nop
    
            goto L_80081D18;
    }
    // 0x80081D0C: nop

    // 0x80081D10: jal         0x80098DE0
    // 0x80081D14: addiu       $a0, $s1, 0x54
    ctx->r4 = ADD32(ctx->r17, 0X54);
    func_80098DE0(rdram, ctx);
        goto after_8;
    // 0x80081D14: addiu       $a0, $s1, 0x54
    ctx->r4 = ADD32(ctx->r17, 0X54);
    after_8:
L_80081D18:
    // 0x80081D18: lw          $a0, 0x30($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X30);
    // 0x80081D1C: jal         0x8005779C
    // 0x80081D20: nop

    func_8005779C(rdram, ctx);
        goto after_9;
    // 0x80081D20: nop

    after_9:
    // 0x80081D24: j           L_800820C0
    // 0x80081D28: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_800820C0;
    // 0x80081D28: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80081D2C:
    // 0x80081D2C: lwc1        $f20, 0x0($s0)
    ctx->f20.u32l = MEM_W(ctx->r16, 0X0);
    // 0x80081D30: addiu       $v0, $zero, 0x30
    ctx->r2 = ADD32(0, 0X30);
    // 0x80081D34: sb          $v0, 0x38($sp)
    MEM_B(0X38, ctx->r29) = ctx->r2;
    // 0x80081D38: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80081D3C: lbu         $v1, 0x53($s1)
    ctx->r3 = MEM_BU(ctx->r17, 0X53);
    // 0x80081D40: lbu         $v0, 0xB39($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0XB39);
    // 0x80081D44: sb          $zero, 0x3A($sp)
    MEM_B(0X3A, ctx->r29) = 0;
    // 0x80081D48: addiu       $v1, $v1, 0x31
    ctx->r3 = ADD32(ctx->r3, 0X31);
    // 0x80081D4C: beq         $v0, $zero, L_80081D60
    if (ctx->r2 == 0) {
        // 0x80081D50: sb          $v1, 0x39($sp)
        MEM_B(0X39, ctx->r29) = ctx->r3;
            goto L_80081D60;
    }
    // 0x80081D50: sb          $v1, 0x39($sp)
    MEM_B(0X39, ctx->r29) = ctx->r3;
    // 0x80081D54: lw          $a0, 0x9C($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X9C);
    // 0x80081D58: j           L_80081D74
    // 0x80081D5C: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
        goto L_80081D74;
    // 0x80081D5C: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
L_80081D60:
    // 0x80081D60: lhu         $a0, 0x4C($s1)
    ctx->r4 = MEM_HU(ctx->r17, 0X4C);
    // 0x80081D64: jal         0x8004013C
    // 0x80081D68: nop

    func_8004013C(rdram, ctx);
        goto after_10;
    // 0x80081D68: nop

    after_10:
    // 0x80081D6C: lw          $a0, 0xC($v0)
    ctx->r4 = MEM_W(ctx->r2, 0XC);
    // 0x80081D70: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
L_80081D74:
    // 0x80081D74: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // 0x80081D78: addu        $a3, $s1, $zero
    ctx->r7 = ADD32(ctx->r17, 0);
    // 0x80081D7C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80081D80: jal         0x80058360
    // 0x80081D84: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    func_80058360(rdram, ctx);
        goto after_11;
    // 0x80081D84: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    after_11:
    // 0x80081D88: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80081D8C: lwc1        $f0, 0x18($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X18);
    // 0x80081D90: lwc1        $f2, 0x1C($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0X1C);
    // 0x80081D94: lbu         $v0, 0xB39($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0XB39);
    // 0x80081D98: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
    // 0x80081D9C: swc1        $f0, 0x18($s1)
    MEM_W(0X18, ctx->r17) = ctx->f0.u32l;
    // 0x80081DA0: lwc1        $f0, 0x20($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X20);
    // 0x80081DA4: neg.s       $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = -ctx->f2.fl;
    // 0x80081DA8: swc1        $f2, 0x1C($s1)
    MEM_W(0X1C, ctx->r17) = ctx->f2.u32l;
    // 0x80081DAC: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
    // 0x80081DB0: bne         $v0, $zero, L_80081DE4
    if (ctx->r2 != 0) {
        // 0x80081DB4: swc1        $f0, 0x20($s1)
        MEM_W(0X20, ctx->r17) = ctx->f0.u32l;
            goto L_80081DE4;
    }
    // 0x80081DB4: swc1        $f0, 0x20($s1)
    MEM_W(0X20, ctx->r17) = ctx->f0.u32l;
    // 0x80081DB8: lhu         $a0, 0x4C($s1)
    ctx->r4 = MEM_HU(ctx->r17, 0X4C);
    // 0x80081DBC: jal         0x8004015C
    // 0x80081DC0: nop

    func_8004015C(rdram, ctx);
        goto after_12;
    // 0x80081DC0: nop

    after_12:
    // 0x80081DC4: lw          $t0, 0x24($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X24);
    // 0x80081DC8: lw          $t1, 0x28($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X28);
    // 0x80081DCC: lw          $t2, 0x2C($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X2C);
    // 0x80081DD0: sw          $t0, 0x24($s1)
    MEM_W(0X24, ctx->r17) = ctx->r8;
    // 0x80081DD4: sw          $t1, 0x28($s1)
    MEM_W(0X28, ctx->r17) = ctx->r9;
    // 0x80081DD8: sw          $t2, 0x2C($s1)
    MEM_W(0X2C, ctx->r17) = ctx->r10;
    // 0x80081DDC: j           L_80081DF0
    // 0x80081DE0: nop

        goto L_80081DF0;
    // 0x80081DE0: nop

L_80081DE4:
    // 0x80081DE4: sw          $zero, 0x24($s1)
    MEM_W(0X24, ctx->r17) = 0;
    // 0x80081DE8: sw          $zero, 0x28($s1)
    MEM_W(0X28, ctx->r17) = 0;
    // 0x80081DEC: sw          $zero, 0x2C($s1)
    MEM_W(0X2C, ctx->r17) = 0;
L_80081DF0:
    // 0x80081DF0: lwc1        $f0, 0x48($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X48);
    // 0x80081DF4: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80081DF8: lwc1        $f12, -0x2528($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X2528);
    // 0x80081DFC: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80081E00: lwc1        $f14, -0x2524($at)
    ctx->f14.u32l = MEM_W(ctx->r1, -0X2524);
    // 0x80081E04: jal         0x8001E20C
    // 0x80081E08: add.s       $f12, $f0, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = ctx->f0.fl + ctx->f12.fl;
    floatModulo(rdram, ctx);
        goto after_13;
    // 0x80081E08: add.s       $f12, $f0, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = ctx->f0.fl + ctx->f12.fl;
    after_13:
    // 0x80081E0C: addiu       $s0, $sp, 0x40
    ctx->r16 = ADD32(ctx->r29, 0X40);
    // 0x80081E10: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x80081E14: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80081E18: addiu       $a1, $s1, 0x18
    ctx->r5 = ADD32(ctx->r17, 0X18);
    // 0x80081E1C: jal         0x8001D240
    // 0x80081E20: sw          $a2, 0x48($s1)
    MEM_W(0X48, ctx->r17) = ctx->r6;
    func_8001D240(rdram, ctx);
        goto after_14;
    // 0x80081E20: sw          $a2, 0x48($s1)
    MEM_W(0X48, ctx->r17) = ctx->r6;
    after_14:
    // 0x80081E24: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x80081E28: addiu       $a1, $s1, 0xC
    ctx->r5 = ADD32(ctx->r17, 0XC);
    // 0x80081E2C: jal         0x8001D3C4
    // 0x80081E30: addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    func_8001D3C4(rdram, ctx);
        goto after_15;
    // 0x80081E30: addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    after_15:
    // 0x80081E34: lbu         $v0, 0x99($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X99);
    // 0x80081E38: bnel        $v0, $zero, L_80081EEC
    if (ctx->r2 != 0) {
        // 0x80081E3C: ori         $s0, $zero, 0xFFFF
        ctx->r16 = 0 | 0XFFFF;
            goto L_80081EEC;
    }
    goto skip_0;
    // 0x80081E3C: ori         $s0, $zero, 0xFFFF
    ctx->r16 = 0 | 0XFFFF;
    skip_0:
    // 0x80081E40: lui         $a2, 0x8014
    ctx->r6 = S32(0X8014 << 16);
    // 0x80081E44: addiu       $a2, $a2, -0x7FA8
    ctx->r6 = ADD32(ctx->r6, -0X7FA8);
    // 0x80081E48: lwc1        $f12, 0x0($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X0);
    // 0x80081E4C: lwc1        $f14, 0x8($s1)
    ctx->f14.u32l = MEM_W(ctx->r17, 0X8);
    // 0x80081E50: jal         0x80067D90
    // 0x80081E54: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    func_80067D90(rdram, ctx);
        goto after_16;
    // 0x80081E54: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    after_16:
    // 0x80081E58: lwc1        $f2, 0x4($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0X4);
    // 0x80081E5C: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x80081E60: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80081E64: lwc1        $f2, -0x2520($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X2520);
    // 0x80081E68: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80081E6C: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x80081E70: lwc1        $f2, 0x34($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0X34);
    // 0x80081E74: lbu         $v0, 0xB39($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0XB39);
    // 0x80081E78: div.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f2.fl);
    // 0x80081E7C: beq         $v0, $zero, L_80081EC4
    if (ctx->r2 == 0) {
        // 0x80081E80: swc1        $f0, 0x3C($s1)
        MEM_W(0X3C, ctx->r17) = ctx->f0.u32l;
            goto L_80081EC4;
    }
    // 0x80081E80: swc1        $f0, 0x3C($s1)
    MEM_W(0X3C, ctx->r17) = ctx->f0.u32l;
    // 0x80081E84: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80081E88: lwc1        $f0, 0xBA4($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0XBA4);
    // 0x80081E8C: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80081E90: lwc1        $f12, -0x251C($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X251C);
    // 0x80081E94: mul.s       $f12, $f0, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = MUL_S(ctx->f0.fl, ctx->f12.fl);
    // 0x80081E98: jal         0x80033960
    // 0x80081E9C: nop

    sinf_recomp(rdram, ctx);
        goto after_17;
    // 0x80081E9C: nop

    after_17:
    // 0x80081EA0: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80081EA4: lwc1        $f2, -0x2518($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X2518);
    // 0x80081EA8: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x80081EAC: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80081EB0: lwc1        $f2, -0x2514($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X2514);
    // 0x80081EB4: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x80081EB8: lwc1        $f2, 0x3C($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0X3C);
    // 0x80081EBC: mul.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x80081EC0: swc1        $f2, 0x3C($s1)
    MEM_W(0X3C, ctx->r17) = ctx->f2.u32l;
L_80081EC4:
    // 0x80081EC4: lwc1        $f2, 0x3C($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0X3C);
    // 0x80081EC8: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80081ECC: c.le.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl <= ctx->f0.fl;
    // 0x80081ED0: nop

    // 0x80081ED4: bc1f        L_80081F74
    if (!c1cs) {
        // 0x80081ED8: nop
    
            goto L_80081F74;
    }
    // 0x80081ED8: nop

    // 0x80081EDC: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80081EE0: lwc1        $f0, -0x2510($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X2510);
    // 0x80081EE4: j           L_80081F74
    // 0x80081EE8: swc1        $f0, 0x3C($s1)
    MEM_W(0X3C, ctx->r17) = ctx->f0.u32l;
        goto L_80081F74;
    // 0x80081EE8: swc1        $f0, 0x3C($s1)
    MEM_W(0X3C, ctx->r17) = ctx->f0.u32l;
L_80081EEC:
    // 0x80081EEC: lhu         $v0, 0x9A($s1)
    ctx->r2 = MEM_HU(ctx->r17, 0X9A);
    // 0x80081EF0: beq         $v0, $s0, L_80081F04
    if (ctx->r2 == ctx->r16) {
        // 0x80081EF4: nop
    
            goto L_80081F04;
    }
    // 0x80081EF4: nop

    // 0x80081EF8: jal         0x8003ED74
    // 0x80081EFC: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    func_8003ED74(rdram, ctx);
        goto after_18;
    // 0x80081EFC: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    after_18:
    // 0x80081F00: sh          $s0, 0x9A($s1)
    MEM_H(0X9A, ctx->r17) = ctx->r16;
L_80081F04:
    // 0x80081F04: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80081F08: lwc1        $f0, -0x250C($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X250C);
    // 0x80081F0C: mul.s       $f0, $f20, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = MUL_S(ctx->f20.fl, ctx->f0.fl);
    // 0x80081F10: lwc1        $f2, 0x3C($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0X3C);
    // 0x80081F14: sub.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl - ctx->f0.fl;
    // 0x80081F18: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80081F1C: c.le.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl <= ctx->f0.fl;
    // 0x80081F20: nop

    // 0x80081F24: bc1f        L_80081F74
    if (!c1cs) {
        // 0x80081F28: swc1        $f2, 0x3C($s1)
        MEM_W(0X3C, ctx->r17) = ctx->f2.u32l;
            goto L_80081F74;
    }
    // 0x80081F28: swc1        $f2, 0x3C($s1)
    MEM_W(0X3C, ctx->r17) = ctx->f2.u32l;
    // 0x80081F2C: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80081F30: lbu         $v0, 0xB39($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0XB39);
    // 0x80081F34: bne         $v0, $zero, L_80081F60
    if (ctx->r2 != 0) {
        // 0x80081F38: addiu       $a1, $zero, 0x9
        ctx->r5 = ADD32(0, 0X9);
            goto L_80081F60;
    }
    // 0x80081F38: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    // 0x80081F3C: addiu       $v0, $zero, 0xF
    ctx->r2 = ADD32(0, 0XF);
    // 0x80081F40: sb          $v0, 0x68($sp)
    MEM_B(0X68, ctx->r29) = ctx->r2;
    // 0x80081F44: lhu         $v1, 0x16($s3)
    ctx->r3 = MEM_HU(ctx->r19, 0X16);
    // 0x80081F48: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x80081F4C: sh          $v0, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r2;
    // 0x80081F50: sh          $v1, 0x50($sp)
    MEM_H(0X50, ctx->r29) = ctx->r3;
    // 0x80081F54: lhu         $a0, 0x4C($s1)
    ctx->r4 = MEM_HU(ctx->r17, 0X4C);
    // 0x80081F58: jal         0x8003E8DC
    // 0x80081F5C: addiu       $a2, $sp, 0x50
    ctx->r6 = ADD32(ctx->r29, 0X50);
    slotDispatcherIter(rdram, ctx);
        goto after_19;
    // 0x80081F5C: addiu       $a2, $sp, 0x50
    ctx->r6 = ADD32(ctx->r29, 0X50);
    after_19:
L_80081F60:
    // 0x80081F60: lhu         $a0, 0x16($s3)
    ctx->r4 = MEM_HU(ctx->r19, 0X16);
    // 0x80081F64: jal         0x8003ED74
    // 0x80081F68: nop

    func_8003ED74(rdram, ctx);
        goto after_20;
    // 0x80081F68: nop

    after_20:
    // 0x80081F6C: j           L_800820C0
    // 0x80081F70: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_800820C0;
    // 0x80081F70: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80081F74:
    // 0x80081F74: lw          $v0, 0x30($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X30);
    // 0x80081F78: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x80081F7C: lwc1        $f2, 0x3C($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0X3C);
    // 0x80081F80: lwc1        $f0, 0x44($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X44);
    // 0x80081F84: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x80081F88: j           L_800820BC
    // 0x80081F8C: swc1        $f0, 0x44($s1)
    MEM_W(0X44, ctx->r17) = ctx->f0.u32l;
        goto L_800820BC;
    // 0x80081F8C: swc1        $f0, 0x44($s1)
    MEM_W(0X44, ctx->r17) = ctx->f0.u32l;
L_80081F90:
    // 0x80081F90: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    // 0x80081F94: lw          $a0, 0x30($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X30);
    // 0x80081F98: addiu       $a2, $s1, 0x38
    ctx->r6 = ADD32(ctx->r17, 0X38);
    // 0x80081F9C: jal         0x80059C24
    // 0x80081FA0: addiu       $a0, $a0, 0x28
    ctx->r4 = ADD32(ctx->r4, 0X28);
    func_80059C24(rdram, ctx);
        goto after_21;
    // 0x80081FA0: addiu       $a0, $a0, 0x28
    ctx->r4 = ADD32(ctx->r4, 0X28);
    after_21:
    // 0x80081FA4: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80081FA8: lbu         $v0, 0xB39($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0XB39);
    // 0x80081FAC: beq         $v0, $zero, L_80081FF4
    if (ctx->r2 == 0) {
        // 0x80081FB0: nop
    
            goto L_80081FF4;
    }
    // 0x80081FB0: nop

    // 0x80081FB4: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80081FB8: lw          $v1, 0x30($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X30);
    // 0x80081FBC: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x80081FC0: beq         $v0, $zero, L_80081FD8
    if (ctx->r2 == 0) {
        // 0x80081FC4: sw          $v0, 0xC($v1)
        MEM_W(0XC, ctx->r3) = ctx->r2;
            goto L_80081FD8;
    }
    // 0x80081FC4: sw          $v0, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r2;
    // 0x80081FC8: lw          $v0, 0x30($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X30);
    // 0x80081FCC: lw          $v1, 0xC($v0)
    ctx->r3 = MEM_W(ctx->r2, 0XC);
    // 0x80081FD0: addiu       $v0, $v0, 0xC
    ctx->r2 = ADD32(ctx->r2, 0XC);
    // 0x80081FD4: sw          $v0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r2;
L_80081FD8:
    // 0x80081FD8: lw          $v0, 0x30($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X30);
    // 0x80081FDC: sw          $zero, 0x10($v0)
    MEM_W(0X10, ctx->r2) = 0;
    // 0x80081FE0: lw          $v0, 0x30($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X30);
    // 0x80081FE4: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x80081FE8: addiu       $v0, $v0, 0xC
    ctx->r2 = ADD32(ctx->r2, 0XC);
    // 0x80081FEC: j           L_80082008
    // 0x80081FF0: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
        goto L_80082008;
    // 0x80081FF0: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
L_80081FF4:
    // 0x80081FF4: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80081FF8: lw          $a1, 0x30($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X30);
    // 0x80081FFC: lui         $a3, 0x42C8
    ctx->r7 = S32(0X42C8 << 16);
    // 0x80082000: jal         0x80057C8C
    // 0x80082004: addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    func_80057C8C(rdram, ctx);
        goto after_22;
    // 0x80082004: addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    after_22:
L_80082008:
    // 0x80082008: lbu         $v0, 0x98($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X98);
    // 0x8008200C: beq         $v0, $zero, L_800820BC
    if (ctx->r2 == 0) {
        // 0x80082010: addiu       $a0, $s1, 0x54
        ctx->r4 = ADD32(ctx->r17, 0X54);
            goto L_800820BC;
    }
    // 0x80082010: addiu       $a0, $s1, 0x54
    ctx->r4 = ADD32(ctx->r17, 0X54);
    // 0x80082014: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    // 0x80082018: addiu       $a2, $a1, 0x24
    ctx->r6 = ADD32(ctx->r5, 0X24);
    // 0x8008201C: jal         0x800988E8
    // 0x80082020: addiu       $a3, $zero, 0x78
    ctx->r7 = ADD32(0, 0X78);
    func_800988E8(rdram, ctx);
        goto after_23;
    // 0x80082020: addiu       $a3, $zero, 0x78
    ctx->r7 = ADD32(0, 0X78);
    after_23:
    // 0x80082024: j           L_800820C0
    // 0x80082028: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_800820C0;
    // 0x80082028: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8008202C:
    // 0x8008202C: lw          $a0, 0x8($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X8);
    // 0x80082030: beql        $a0, $zero, L_8008204C
    if (ctx->r4 == 0) {
        // 0x80082034: addu        $a0, $zero, $zero
        ctx->r4 = ADD32(0, 0);
            goto L_8008204C;
    }
    goto skip_1;
    // 0x80082034: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    skip_1:
    // 0x80082038: lui         $a1, 0x3ECC
    ctx->r5 = S32(0X3ECC << 16);
    // 0x8008203C: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    // 0x80082040: jal         0x800612E0
    // 0x80082044: nop

    func_800612E0(rdram, ctx);
        goto after_24;
    // 0x80082044: nop

    after_24:
    // 0x80082048: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
L_8008204C:
    // 0x8008204C: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    // 0x80082050: addiu       $a2, $a1, 0x24
    ctx->r6 = ADD32(ctx->r5, 0X24);
    // 0x80082054: lui         $a3, 0x41A0
    ctx->r7 = S32(0X41A0 << 16);
    // 0x80082058: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8008205C: lwc1        $f0, -0x2508($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X2508);
    // 0x80082060: addiu       $v0, $zero, 0x2A
    ctx->r2 = ADD32(0, 0X2A);
    // 0x80082064: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // 0x80082068: addiu       $v0, $zero, 0x78
    ctx->r2 = ADD32(0, 0X78);
    // 0x8008206C: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x80082070: addiu       $v0, $zero, 0x50
    ctx->r2 = ADD32(0, 0X50);
    // 0x80082074: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x80082078: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x8008207C: jal         0x800989D8
    // 0x80082080: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    func_800989D8(rdram, ctx);
        goto after_25;
    // 0x80082080: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    after_25:
    // 0x80082084: lhu         $v1, 0x0($s0)
    ctx->r3 = MEM_HU(ctx->r16, 0X0);
    // 0x80082088: ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
    // 0x8008208C: beq         $v1, $v0, L_800820C0
    if (ctx->r3 == ctx->r2) {
        // 0x80082090: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_800820C0;
    }
    // 0x80082090: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80082094: jal         0x8003ED74
    // 0x80082098: addu        $a0, $v1, $zero
    ctx->r4 = ADD32(ctx->r3, 0);
    func_8003ED74(rdram, ctx);
        goto after_26;
    // 0x80082098: addu        $a0, $v1, $zero
    ctx->r4 = ADD32(ctx->r3, 0);
    after_26:
    // 0x8008209C: j           L_800820C0
    // 0x800820A0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_800820C0;
    // 0x800820A0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800820A4:
    // 0x800820A4: lbu         $v1, 0x18($s0)
    ctx->r3 = MEM_BU(ctx->r16, 0X18);
    // 0x800820A8: addiu       $v0, $zero, 0x10
    ctx->r2 = ADD32(0, 0X10);
    // 0x800820AC: bne         $v1, $v0, L_800820C0
    if (ctx->r3 != ctx->r2) {
        // 0x800820B0: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_800820C0;
    }
    // 0x800820B0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800820B4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800820B8: sb          $v0, 0x99($s1)
    MEM_B(0X99, ctx->r17) = ctx->r2;
L_800820BC:
    // 0x800820BC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800820C0:
    // 0x800820C0: lw          $ra, 0x80($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X80);
    // 0x800820C4: lw          $s3, 0x7C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X7C);
    // 0x800820C8: lw          $s2, 0x78($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X78);
    // 0x800820CC: lw          $s1, 0x74($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X74);
    // 0x800820D0: lw          $s0, 0x70($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X70);
    // 0x800820D4: ldc1        $f22, 0x90($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X90);
    // 0x800820D8: ldc1        $f20, 0x88($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X88);
    // 0x800820DC: jr          $ra
    // 0x800820E0: addiu       $sp, $sp, 0x98
    ctx->r29 = ADD32(ctx->r29, 0X98);
    return;
    // 0x800820E0: addiu       $sp, $sp, 0x98
    ctx->r29 = ADD32(ctx->r29, 0X98);
;}
RECOMP_FUNC void func_800820E4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800820E4: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x800820E8: jr          $ra
    // 0x800820EC: sb          $zero, -0x5680($v0)
    MEM_B(-0X5680, ctx->r2) = 0;
    return;
    // 0x800820EC: sb          $zero, -0x5680($v0)
    MEM_B(-0X5680, ctx->r2) = 0;
;}
RECOMP_FUNC void func_800820F0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800820F0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800820F4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800820F8: sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // 0x800820FC: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x80082100: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x80082104: lw          $s0, 0x4($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X4);
    // 0x80082108: lw          $a0, 0x38($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X38);
    // 0x8008210C: lw          $a2, 0x34($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X34);
    // 0x80082110: sh          $zero, 0x1B2($s0)
    MEM_H(0X1B2, ctx->r16) = 0;
    // 0x80082114: addiu       $a1, $a2, 0x6C
    ctx->r5 = ADD32(ctx->r6, 0X6C);
    // 0x80082118: jal         0x800F2070
    // 0x8008211C: addu        $s1, $a2, $zero
    ctx->r17 = ADD32(ctx->r6, 0);
    setNpcHealth(rdram, ctx);
        goto after_0;
    // 0x8008211C: addu        $s1, $a2, $zero
    ctx->r17 = ADD32(ctx->r6, 0);
    after_0:
    // 0x80082120: sw          $v0, 0xF4($s0)
    MEM_W(0XF4, ctx->r16) = ctx->r2;
    // 0x80082124: sw          $v0, 0xF0($s0)
    MEM_W(0XF0, ctx->r16) = ctx->r2;
    // 0x80082128: sw          $v0, 0xEC($s0)
    MEM_W(0XEC, ctx->r16) = ctx->r2;
    // 0x8008212C: sw          $v0, 0xE8($s0)
    MEM_W(0XE8, ctx->r16) = ctx->r2;
    // 0x80082130: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80082134: sb          $zero, 0xF9($s0)
    MEM_B(0XF9, ctx->r16) = 0;
    // 0x80082138: sh          $zero, 0xFA($s0)
    MEM_H(0XFA, ctx->r16) = 0;
    // 0x8008213C: jal         0x80003430
    // 0x80082140: sb          $v0, 0xF8($s0)
    MEM_B(0XF8, ctx->r16) = ctx->r2;
    rand_recomp(rdram, ctx);
        goto after_1;
    // 0x80082140: sb          $v0, 0xF8($s0)
    MEM_B(0XF8, ctx->r16) = ctx->r2;
    after_1:
    // 0x80082144: andi        $v0, $v0, 0x7F
    ctx->r2 = ctx->r2 & 0X7F;
    // 0x80082148: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8008214C: lwc1        $f2, -0x2504($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X2504);
    // 0x80082150: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x80082154: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x80082158: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x8008215C: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80082160: lwc1        $f2, -0x2500($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X2500);
    // 0x80082164: div.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f2.fl);
    // 0x80082168: swc1        $f0, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f0.u32l;
    // 0x8008216C: lwc1        $f0, 0xA8($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0XA8);
    // 0x80082170: sw          $zero, 0x5C($s0)
    MEM_W(0X5C, ctx->r16) = 0;
    // 0x80082174: sw          $zero, 0x60($s0)
    MEM_W(0X60, ctx->r16) = 0;
    // 0x80082178: swc1        $f0, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f0.u32l;
    // 0x8008217C: lwc1        $f2, 0xB0($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0XB0);
    // 0x80082180: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80082184: lwc1        $f0, -0x24FC($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X24FC);
    // 0x80082188: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8008218C: lwc1        $f12, -0x24F8($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X24F8);
    // 0x80082190: div.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f2.fl);
    // 0x80082194: swc1        $f0, 0x64($s0)
    MEM_W(0X64, ctx->r16) = ctx->f0.u32l;
    // 0x80082198: lwc1        $f0, 0xAC($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0XAC);
    // 0x8008219C: lui         $s2, 0x8013
    ctx->r18 = S32(0X8013 << 16);
    // 0x800821A0: sb          $zero, 0xD8($s0)
    MEM_B(0XD8, ctx->r16) = 0;
    // 0x800821A4: sb          $zero, 0xD9($s0)
    MEM_B(0XD9, ctx->r16) = 0;
    // 0x800821A8: lw          $v0, 0x7CE4($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X7CE4);
    // 0x800821AC: sw          $zero, 0x6C($s0)
    MEM_W(0X6C, ctx->r16) = 0;
    // 0x800821B0: sw          $zero, 0x2B8($s0)
    MEM_W(0X2B8, ctx->r16) = 0;
    // 0x800821B4: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800821B8: addu        $v0, $v0, $s1
    ctx->r2 = ADD32(ctx->r2, ctx->r17);
    // 0x800821BC: swc1        $f0, 0x68($s0)
    MEM_W(0X68, ctx->r16) = ctx->f0.u32l;
    // 0x800821C0: lwc1        $f0, 0xDC($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0XDC);
    // 0x800821C4: mul.s       $f12, $f0, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = MUL_S(ctx->f0.fl, ctx->f12.fl);
    // 0x800821C8: jal         0x8002B190
    // 0x800821CC: nop

    cosf_recomp(rdram, ctx);
        goto after_2;
    // 0x800821CC: nop

    after_2:
    // 0x800821D0: lw          $a0, 0x38($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X38);
    // 0x800821D4: lw          $v0, 0x7CE4($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X7CE4);
    // 0x800821D8: swc1        $f0, 0xDC($s0)
    MEM_W(0XDC, ctx->r16) = ctx->f0.u32l;
    // 0x800821DC: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800821E0: addu        $v0, $v0, $s1
    ctx->r2 = ADD32(ctx->r2, ctx->r17);
    // 0x800821E4: lwc1        $f0, 0xD8($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0XD8);
    // 0x800821E8: swc1        $f0, 0xE0($s0)
    MEM_W(0XE0, ctx->r16) = ctx->f0.u32l;
    // 0x800821EC: lwc1        $f0, 0xE0($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0XE0);
    // 0x800821F0: lw          $v0, 0x34($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X34);
    // 0x800821F4: swc1        $f0, 0xE4($s0)
    MEM_W(0XE4, ctx->r16) = ctx->f0.u32l;
    // 0x800821F8: lw          $a1, 0xB4($v0)
    ctx->r5 = MEM_W(ctx->r2, 0XB4);
    // 0x800821FC: jal         0x800F2830
    // 0x80082200: nop

    func_800F2830(rdram, ctx);
        goto after_3;
    // 0x80082200: nop

    after_3:
    // 0x80082204: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80082208: lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X18);
    // 0x8008220C: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x80082210: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x80082214: jr          $ra
    // 0x80082218: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80082218: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_8008221C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008221C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80082220: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80082224: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x80082228: lw          $s0, 0x4($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X4);
    // 0x8008222C: addiu       $a1, $a2, 0x34
    ctx->r5 = ADD32(ctx->r6, 0X34);
    // 0x80082230: lw          $v1, 0x34($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X34);
    // 0x80082234: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80082238: sb          $v0, 0x1A7($v1)
    MEM_B(0X1A7, ctx->r3) = ctx->r2;
    // 0x8008223C: lw          $a0, 0x34($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X34);
    // 0x80082240: jal         0x800F2070
    // 0x80082244: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    setNpcHealth(rdram, ctx);
        goto after_0;
    // 0x80082244: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    after_0:
    // 0x80082248: lw          $a0, 0x34($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X34);
    // 0x8008224C: jal         0x800F2830
    // 0x80082250: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800F2830(rdram, ctx);
        goto after_1;
    // 0x80082250: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x80082254: sh          $zero, 0x7C($s0)
    MEM_H(0X7C, ctx->r16) = 0;
    // 0x80082258: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8008225C: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x80082260: jr          $ra
    // 0x80082264: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80082264: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void fake_func_80082268(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
;}
RECOMP_FUNC void func_80082270(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80082270: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80082274: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x80082278: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x8008227C: sw          $s4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r20;
    // 0x80082280: addu        $s4, $zero, $zero
    ctx->r20 = ADD32(0, 0);
    // 0x80082284: sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // 0x80082288: addu        $s2, $s4, $zero
    ctx->r18 = ADD32(ctx->r20, 0);
    // 0x8008228C: sw          $s6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r22;
    // 0x80082290: addu        $s6, $a2, $zero
    ctx->r22 = ADD32(ctx->r6, 0);
    // 0x80082294: sw          $s3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r19;
    // 0x80082298: addu        $s3, $a1, $zero
    ctx->r19 = ADD32(ctx->r5, 0);
    // 0x8008229C: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x800822A0: sw          $s5, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r21;
    // 0x800822A4: jal         0x80082544
    // 0x800822A8: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    make_crc32_lut(rdram, ctx);
        goto after_0;
    // 0x800822A8: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    after_0:
    // 0x800822AC: addu        $s5, $v0, $zero
    ctx->r21 = ADD32(ctx->r2, 0);
    // 0x800822B0: addu        $a0, $s5, $zero
    ctx->r4 = ADD32(ctx->r21, 0);
    // 0x800822B4: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x800822B8: jal         0x800824F8
    // 0x800822BC: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    rs_crc32(rdram, ctx);
        goto after_1;
    // 0x800822BC: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    after_1:
    // 0x800822C0: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x800822C4: addiu       $s1, $v1, 0xB40
    ctx->r17 = ADD32(ctx->r3, 0XB40);
    // 0x800822C8: lw          $v1, 0x18($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X18);
    // 0x800822CC: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // 0x800822D0: andi        $v0, $v1, 0x10
    ctx->r2 = ctx->r3 & 0X10;
    // 0x800822D4: beq         $v0, $zero, L_800822F4
    if (ctx->r2 == 0) {
        // 0x800822D8: addiu       $v0, $zero, -0x11
        ctx->r2 = ADD32(0, -0X11);
            goto L_800822F4;
    }
    // 0x800822D8: addiu       $v0, $zero, -0x11
    ctx->r2 = ADD32(0, -0X11);
    // 0x800822DC: and         $v0, $v1, $v0
    ctx->r2 = ctx->r3 & ctx->r2;
    // 0x800822E0: jal         0x8006C780
    // 0x800822E4: sw          $v0, 0x18($s1)
    MEM_W(0X18, ctx->r17) = ctx->r2;
    load_naboo_starfighter(rdram, ctx);
        goto after_2;
    // 0x800822E4: sw          $v0, 0x18($s1)
    MEM_W(0X18, ctx->r17) = ctx->r2;
    after_2:
    // 0x800822E8: sw          $v0, 0x28($s1)
    MEM_W(0X28, ctx->r17) = ctx->r2;
    // 0x800822EC: j           L_80082490
    // 0x800822F0: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
        goto L_80082490;
    // 0x800822F0: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_800822F4:
    // 0x800822F4: addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
    // 0x800822F8: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x800822FC: addiu       $t0, $v0, 0xED0
    ctx->r8 = ADD32(ctx->r2, 0XED0);
    // 0x80082300: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80082304: andi        $a1, $s3, 0xFF
    ctx->r5 = ctx->r19 & 0XFF;
    // 0x80082308: addu        $a3, $s1, $zero
    ctx->r7 = ADD32(ctx->r17, 0);
    // 0x8008230C: andi        $v1, $s0, 0xFF
    ctx->r3 = ctx->r16 & 0XFF;
L_80082310:
    // 0x80082310: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x80082314: addu        $v0, $v0, $t0
    ctx->r2 = ADD32(ctx->r2, ctx->r8);
    // 0x80082318: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x8008231C: xor         $v0, $v0, $a0
    ctx->r2 = ctx->r2 ^ ctx->r4;
    // 0x80082320: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80082324: bnel        $v0, $a2, L_80082420
    if (ctx->r2 != ctx->r6) {
        // 0x80082328: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_80082420;
    }
    goto skip_0;
    // 0x80082328: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    skip_0:
    // 0x8008232C: beq         $a1, $zero, L_80082344
    if (ctx->r5 == 0) {
        // 0x80082330: srl         $v0, $v1, 5
        ctx->r2 = S32(U32(ctx->r3) >> 5);
            goto L_80082344;
    }
    // 0x80082330: srl         $v0, $v1, 5
    ctx->r2 = S32(U32(ctx->r3) >> 5);
    // 0x80082334: beq         $a1, $a2, L_80082360
    if (ctx->r5 == ctx->r6) {
        // 0x80082338: addiu       $s2, $zero, 0x1
        ctx->r18 = ADD32(0, 0X1);
            goto L_80082360;
    }
    // 0x80082338: addiu       $s2, $zero, 0x1
    ctx->r18 = ADD32(0, 0X1);
    // 0x8008233C: j           L_80082388
    // 0x80082340: andi        $a1, $s0, 0xFF
    ctx->r5 = ctx->r16 & 0XFF;
        goto L_80082388;
    // 0x80082340: andi        $a1, $s0, 0xFF
    ctx->r5 = ctx->r16 & 0XFF;
L_80082344:
    // 0x80082344: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80082348: addu        $v0, $v0, $a3
    ctx->r2 = ADD32(ctx->r2, ctx->r7);
    // 0x8008234C: andi        $v1, $s0, 0x1F
    ctx->r3 = ctx->r16 & 0X1F;
    // 0x80082350: lw          $a0, 0x18($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X18);
    // 0x80082354: sllv        $v1, $a2, $v1
    ctx->r3 = S32(ctx->r6 << (ctx->r3 & 31));
    // 0x80082358: j           L_8008237C
    // 0x8008235C: or          $a0, $a0, $v1
    ctx->r4 = ctx->r4 | ctx->r3;
        goto L_8008237C;
    // 0x8008235C: or          $a0, $a0, $v1
    ctx->r4 = ctx->r4 | ctx->r3;
L_80082360:
    // 0x80082360: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80082364: addu        $v0, $v0, $a3
    ctx->r2 = ADD32(ctx->r2, ctx->r7);
    // 0x80082368: andi        $v1, $s0, 0x1F
    ctx->r3 = ctx->r16 & 0X1F;
    // 0x8008236C: sllv        $v1, $a2, $v1
    ctx->r3 = S32(ctx->r6 << (ctx->r3 & 31));
    // 0x80082370: lw          $a0, 0x18($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X18);
    // 0x80082374: nor         $v1, $zero, $v1
    ctx->r3 = ~(0 | ctx->r3);
    // 0x80082378: and         $a0, $a0, $v1
    ctx->r4 = ctx->r4 & ctx->r3;
L_8008237C:
    // 0x8008237C: sw          $a0, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->r4;
    // 0x80082380: addiu       $s2, $zero, 0x1
    ctx->r18 = ADD32(0, 0X1);
    // 0x80082384: andi        $a1, $s0, 0xFF
    ctx->r5 = ctx->r16 & 0XFF;
L_80082388:
    // 0x80082388: srl         $v0, $a1, 5
    ctx->r2 = S32(U32(ctx->r5) >> 5);
    // 0x8008238C: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80082390: addu        $v0, $v0, $a3
    ctx->r2 = ADD32(ctx->r2, ctx->r7);
    // 0x80082394: andi        $v1, $s0, 0x1F
    ctx->r3 = ctx->r16 & 0X1F;
    // 0x80082398: lw          $a0, 0x18($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X18);
    // 0x8008239C: sllv        $v1, $a2, $v1
    ctx->r3 = S32(ctx->r6 << (ctx->r3 & 31));
    // 0x800823A0: and         $a0, $a0, $v1
    ctx->r4 = ctx->r4 & ctx->r3;
    // 0x800823A4: sltu        $v0, $zero, $a0
    ctx->r2 = 0 < ctx->r4 ? 1 : 0;
    // 0x800823A8: beq         $a0, $zero, L_80082430
    if (ctx->r4 == 0) {
        // 0x800823AC: addu        $s4, $v0, $zero
        ctx->r20 = ADD32(ctx->r2, 0);
            goto L_80082430;
    }
    // 0x800823AC: addu        $s4, $v0, $zero
    ctx->r20 = ADD32(ctx->r2, 0);
    // 0x800823B0: sltiu       $v0, $a1, 0x7
    ctx->r2 = ctx->r5 < 0X7 ? 1 : 0;
    // 0x800823B4: bne         $v0, $zero, L_80082430
    if (ctx->r2 != 0) {
        // 0x800823B8: sltiu       $v0, $a1, 0x13
        ctx->r2 = ctx->r5 < 0X13 ? 1 : 0;
            goto L_80082430;
    }
    // 0x800823B8: sltiu       $v0, $a1, 0x13
    ctx->r2 = ctx->r5 < 0X13 ? 1 : 0;
    // 0x800823BC: beq         $v0, $zero, L_80082430
    if (ctx->r2 == 0) {
        // 0x800823C0: addiu       $a1, $zero, 0x7
        ctx->r5 = ADD32(0, 0X7);
            goto L_80082430;
    }
    // 0x800823C0: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    // 0x800823C4: srl         $a0, $a1, 3
    ctx->r4 = S32(U32(ctx->r5) >> 3);
L_800823C8:
    // 0x800823C8: andi        $v1, $a1, 0x1F
    ctx->r3 = ctx->r5 & 0X1F;
    // 0x800823CC: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x800823D0: andi        $a0, $a0, 0x1C
    ctx->r4 = ctx->r4 & 0X1C;
    // 0x800823D4: addu        $a0, $a0, $a3
    ctx->r4 = ADD32(ctx->r4, ctx->r7);
    // 0x800823D8: sllv        $v1, $a2, $v1
    ctx->r3 = S32(ctx->r6 << (ctx->r3 & 31));
    // 0x800823DC: lw          $v0, 0x18($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X18);
    // 0x800823E0: nor         $v1, $zero, $v1
    ctx->r3 = ~(0 | ctx->r3);
    // 0x800823E4: and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // 0x800823E8: sw          $v0, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->r2;
    // 0x800823EC: andi        $v0, $a1, 0xFF
    ctx->r2 = ctx->r5 & 0XFF;
    // 0x800823F0: sltiu       $v0, $v0, 0x13
    ctx->r2 = ctx->r2 < 0X13 ? 1 : 0;
    // 0x800823F4: bne         $v0, $zero, L_800823C8
    if (ctx->r2 != 0) {
        // 0x800823F8: srl         $a0, $a1, 3
        ctx->r4 = S32(U32(ctx->r5) >> 3);
            goto L_800823C8;
    }
    // 0x800823F8: srl         $a0, $a1, 3
    ctx->r4 = S32(U32(ctx->r5) >> 3);
    // 0x800823FC: srl         $v0, $s0, 3
    ctx->r2 = S32(U32(ctx->r16) >> 3);
    // 0x80082400: andi        $v0, $v0, 0x1C
    ctx->r2 = ctx->r2 & 0X1C;
    // 0x80082404: addu        $v0, $v0, $a3
    ctx->r2 = ADD32(ctx->r2, ctx->r7);
    // 0x80082408: andi        $v1, $s0, 0x1F
    ctx->r3 = ctx->r16 & 0X1F;
    // 0x8008240C: lw          $a0, 0x18($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X18);
    // 0x80082410: sllv        $v1, $a2, $v1
    ctx->r3 = S32(ctx->r6 << (ctx->r3 & 31));
    // 0x80082414: or          $a0, $a0, $v1
    ctx->r4 = ctx->r4 | ctx->r3;
    // 0x80082418: j           L_80082430
    // 0x8008241C: sw          $a0, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->r4;
        goto L_80082430;
    // 0x8008241C: sw          $a0, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->r4;
L_80082420:
    // 0x80082420: andi        $v0, $s0, 0xFF
    ctx->r2 = ctx->r16 & 0XFF;
    // 0x80082424: sltiu       $v0, $v0, 0x1D
    ctx->r2 = ctx->r2 < 0X1D ? 1 : 0;
    // 0x80082428: bne         $v0, $zero, L_80082310
    if (ctx->r2 != 0) {
        // 0x8008242C: andi        $v1, $s0, 0xFF
        ctx->r3 = ctx->r16 & 0XFF;
            goto L_80082310;
    }
    // 0x8008242C: andi        $v1, $s0, 0xFF
    ctx->r3 = ctx->r16 & 0XFF;
L_80082430:
    // 0x80082430: jal         0x80001C98
    // 0x80082434: addu        $a0, $s5, $zero
    ctx->r4 = ADD32(ctx->r21, 0);
    rs_free(rdram, ctx);
        goto after_3;
    // 0x80082434: addu        $a0, $s5, $zero
    ctx->r4 = ADD32(ctx->r21, 0);
    after_3:
    // 0x80082438: andi        $v0, $s2, 0xFF
    ctx->r2 = ctx->r18 & 0XFF;
    // 0x8008243C: beq         $v0, $zero, L_80082488
    if (ctx->r2 == 0) {
        // 0x80082440: sb          $zero, 0x0($s6)
        MEM_B(0X0, ctx->r22) = 0;
            goto L_80082488;
    }
    // 0x80082440: sb          $zero, 0x0($s6)
    MEM_B(0X0, ctx->r22) = 0;
    // 0x80082444: andi        $s0, $s0, 0xFF
    ctx->r16 = ctx->r16 & 0XFF;
    // 0x80082448: jal         0x800824B8
    // 0x8008244C: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_800824B8(rdram, ctx);
        goto after_4;
    // 0x8008244C: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_4:
    // 0x80082450: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x80082454: beq         $v0, $zero, L_80082460
    if (ctx->r2 == 0) {
        // 0x80082458: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80082460;
    }
    // 0x80082458: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8008245C: sb          $v0, 0x0($s6)
    MEM_B(0X0, ctx->r22) = ctx->r2;
L_80082460:
    // 0x80082460: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // 0x80082464: beql        $s0, $v0, L_8008246C
    if (ctx->r16 == ctx->r2) {
        // 0x80082468: addu        $s2, $zero, $zero
        ctx->r18 = ADD32(0, 0);
            goto L_8008246C;
    }
    goto skip_1;
    // 0x80082468: addu        $s2, $zero, $zero
    ctx->r18 = ADD32(0, 0);
    skip_1:
L_8008246C:
    // 0x8008246C: andi        $v0, $s2, 0xFF
    ctx->r2 = ctx->r18 & 0XFF;
    // 0x80082470: beq         $v0, $zero, L_80082488
    if (ctx->r2 == 0) {
        // 0x80082474: andi        $v0, $s4, 0xFF
        ctx->r2 = ctx->r20 & 0XFF;
            goto L_80082488;
    }
    // 0x80082474: andi        $v0, $s4, 0xFF
    ctx->r2 = ctx->r20 & 0XFF;
    // 0x80082478: beq         $v0, $zero, L_8008248C
    if (ctx->r2 == 0) {
        // 0x8008247C: addiu       $v1, $zero, 0x2
        ctx->r3 = ADD32(0, 0X2);
            goto L_8008248C;
    }
    // 0x8008247C: addiu       $v1, $zero, 0x2
    ctx->r3 = ADD32(0, 0X2);
    // 0x80082480: j           L_8008248C
    // 0x80082484: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
        goto L_8008248C;
    // 0x80082484: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_80082488:
    // 0x80082488: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
L_8008248C:
    // 0x8008248C: addu        $v0, $v1, $zero
    ctx->r2 = ADD32(ctx->r3, 0);
L_80082490:
    // 0x80082490: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80082494: lw          $s6, 0x28($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X28);
    // 0x80082498: lw          $s5, 0x24($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X24);
    // 0x8008249C: lw          $s4, 0x20($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X20);
    // 0x800824A0: lw          $s3, 0x1C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X1C);
    // 0x800824A4: lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X18);
    // 0x800824A8: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x800824AC: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x800824B0: jr          $ra
    // 0x800824B4: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x800824B4: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_800824B8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800824B8: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
    // 0x800824BC: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x800824C0: addiu       $a2, $v0, 0xF44
    ctx->r6 = ADD32(ctx->r2, 0XF44);
    // 0x800824C4: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x800824C8: andi        $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 & 0XFF;
L_800824CC:
    // 0x800824CC: andi        $v0, $v1, 0xFF
    ctx->r2 = ctx->r3 & 0XFF;
    // 0x800824D0: addu        $v0, $v0, $a2
    ctx->r2 = ADD32(ctx->r2, ctx->r6);
    // 0x800824D4: lbu         $v0, 0x0($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X0);
    // 0x800824D8: bne         $v0, $a1, L_800824E8
    if (ctx->r2 != ctx->r5) {
        // 0x800824DC: nop
    
            goto L_800824E8;
    }
    // 0x800824DC: nop

    // 0x800824E0: jr          $ra
    // 0x800824E4: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    return;
    // 0x800824E4: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_800824E8:
    // 0x800824E8: bne         $v0, $a0, L_800824CC
    if (ctx->r2 != ctx->r4) {
        // 0x800824EC: addiu       $v1, $v1, 0x1
        ctx->r3 = ADD32(ctx->r3, 0X1);
            goto L_800824CC;
    }
    // 0x800824EC: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800824F0: jr          $ra
    // 0x800824F4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x800824F4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
;}
RECOMP_FUNC void rs_crc32(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800824F8: lui         $t0, 0xFAC5
    ctx->r8 = S32(0XFAC5 << 16);
    // 0x800824FC: ori         $t0, $t0, 0xFAC5
    ctx->r8 = ctx->r8 | 0XFAC5;
    // 0x80082500: beq         $a2, $zero, L_8008253C
    if (ctx->r6 == 0) {
        // 0x80082504: addu        $a3, $zero, $zero
        ctx->r7 = ADD32(0, 0);
            goto L_8008253C;
    }
    // 0x80082504: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    // 0x80082508: addu        $v0, $a1, $a3
    ctx->r2 = ADD32(ctx->r5, ctx->r7);
L_8008250C:
    // 0x8008250C: lbu         $v0, 0x0($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X0);
    // 0x80082510: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x80082514: xor         $v0, $t0, $v0
    ctx->r2 = ctx->r8 ^ ctx->r2;
    // 0x80082518: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x8008251C: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80082520: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x80082524: lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X0);
    // 0x80082528: srl         $v0, $t0, 8
    ctx->r2 = S32(U32(ctx->r8) >> 8);
    // 0x8008252C: xor         $t0, $v1, $v0
    ctx->r8 = ctx->r3 ^ ctx->r2;
    // 0x80082530: sltu        $v0, $a3, $a2
    ctx->r2 = ctx->r7 < ctx->r6 ? 1 : 0;
    // 0x80082534: bne         $v0, $zero, L_8008250C
    if (ctx->r2 != 0) {
        // 0x80082538: addu        $v0, $a1, $a3
        ctx->r2 = ADD32(ctx->r5, ctx->r7);
            goto L_8008250C;
    }
    // 0x80082538: addu        $v0, $a1, $a3
    ctx->r2 = ADD32(ctx->r5, ctx->r7);
L_8008253C:
    // 0x8008253C: jr          $ra
    // 0x80082540: addu        $v0, $t0, $zero
    ctx->r2 = ADD32(ctx->r8, 0);
    return;
    // 0x80082540: addu        $v0, $t0, $zero
    ctx->r2 = ADD32(ctx->r8, 0);
;}
RECOMP_FUNC void make_crc32_lut(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80082544: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80082548: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x8008254C: addiu       $a0, $zero, 0x400
    ctx->r4 = ADD32(0, 0X400);
    // 0x80082550: jal         0x80001ACC
    // 0x80082554: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    rs_malloc(rdram, ctx);
        goto after_0;
    // 0x80082554: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    after_0:
    // 0x80082558: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x8008255C: lui         $a3, 0xEDB8
    ctx->r7 = S32(0XEDB8 << 16);
    // 0x80082560: ori         $a3, $a3, 0x8320
    ctx->r7 = ctx->r7 | 0X8320;
    // 0x80082564: addu        $t0, $v0, $zero
    ctx->r8 = ADD32(ctx->r2, 0);
    // 0x80082568: addu        $a2, $t0, $zero
    ctx->r6 = ADD32(ctx->r8, 0);
L_8008256C:
    // 0x8008256C: addu        $v1, $a1, $zero
    ctx->r3 = ADD32(ctx->r5, 0);
    // 0x80082570: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x80082574: andi        $v0, $v1, 0x1
    ctx->r2 = ctx->r3 & 0X1;
L_80082578:
    // 0x80082578: beq         $v0, $zero, L_80082588
    if (ctx->r2 == 0) {
        // 0x8008257C: srl         $v0, $v1, 1
        ctx->r2 = S32(U32(ctx->r3) >> 1);
            goto L_80082588;
    }
    // 0x8008257C: srl         $v0, $v1, 1
    ctx->r2 = S32(U32(ctx->r3) >> 1);
    // 0x80082580: j           L_8008258C
    // 0x80082584: xor         $v1, $v0, $a3
    ctx->r3 = ctx->r2 ^ ctx->r7;
        goto L_8008258C;
    // 0x80082584: xor         $v1, $v0, $a3
    ctx->r3 = ctx->r2 ^ ctx->r7;
L_80082588:
    // 0x80082588: srl         $v1, $v1, 1
    ctx->r3 = S32(U32(ctx->r3) >> 1);
L_8008258C:
    // 0x8008258C: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x80082590: sltiu       $v0, $a0, 0x8
    ctx->r2 = ctx->r4 < 0X8 ? 1 : 0;
    // 0x80082594: bne         $v0, $zero, L_80082578
    if (ctx->r2 != 0) {
        // 0x80082598: andi        $v0, $v1, 0x1
        ctx->r2 = ctx->r3 & 0X1;
            goto L_80082578;
    }
    // 0x80082598: andi        $v0, $v1, 0x1
    ctx->r2 = ctx->r3 & 0X1;
    // 0x8008259C: sw          $v1, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r3;
    // 0x800825A0: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x800825A4: sltiu       $v0, $a1, 0x100
    ctx->r2 = ctx->r5 < 0X100 ? 1 : 0;
    // 0x800825A8: bne         $v0, $zero, L_8008256C
    if (ctx->r2 != 0) {
        // 0x800825AC: addiu       $a2, $a2, 0x4
        ctx->r6 = ADD32(ctx->r6, 0X4);
            goto L_8008256C;
    }
    // 0x800825AC: addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
    // 0x800825B0: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x800825B4: addu        $v0, $t0, $zero
    ctx->r2 = ADD32(ctx->r8, 0);
    // 0x800825B8: jr          $ra
    // 0x800825BC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x800825BC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_800825C0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800825C0: jr          $ra
    // 0x800825C4: nop

    return;
    // 0x800825C4: nop

;}
RECOMP_FUNC void fake_func_800825C8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
;}
RECOMP_FUNC void func_800826A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800826A0: addu        $t8, $a0, $zero
    ctx->r24 = ADD32(ctx->r4, 0);
    // 0x800826A4: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x800826A8: lwc1        $f0, -0x24EC($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X24EC);
    // 0x800826AC: addiu       $v1, $t8, -0x1
    ctx->r3 = ADD32(ctx->r24, -0X1);
    // 0x800826B0: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x800826B4: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800826B8: sll         $a3, $v0, 2
    ctx->r7 = S32(ctx->r2 << 2);
    // 0x800826BC: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x800826C0: addu        $at, $at, $a3
    ctx->r1 = ADD32(ctx->r1, ctx->r7);
    // 0x800826C4: lw          $v0, -0x5668($at)
    ctx->r2 = MEM_W(ctx->r1, -0X5668);
    // 0x800826C8: mtc1        $a2, $f4
    ctx->f4.u32l = ctx->r6;
    // 0x800826CC: mul.s       $f0, $f4, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x800826D0: lw          $v0, 0x4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X4);
    // 0x800826D4: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x800826D8: sll         $a2, $a1, 4
    ctx->r6 = S32(ctx->r5 << 4);
    // 0x800826DC: addu        $t7, $v0, $a2
    ctx->r15 = ADD32(ctx->r2, ctx->r6);
    // 0x800826E0: lhu         $v0, 0xE($t7)
    ctx->r2 = MEM_HU(ctx->r15, 0XE);
    // 0x800826E4: trunc.w.s   $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800826E8: mfc1        $a0, $f2
    ctx->r4 = (int32_t)ctx->f2.u32l;
    // 0x800826EC: beq         $v0, $zero, L_8008283C
    if (ctx->r2 == 0) {
        // 0x800826F0: addu        $t5, $zero, $zero
        ctx->r13 = ADD32(0, 0);
            goto L_8008283C;
    }
    // 0x800826F0: addu        $t5, $zero, $zero
    ctx->r13 = ADD32(0, 0);
    // 0x800826F4: sll         $v0, $a0, 16
    ctx->r2 = S32(ctx->r4 << 16);
    // 0x800826F8: sra         $t4, $v0, 16
    ctx->r12 = S32(SIGNED(ctx->r2) >> 16);
    // 0x800826FC: addu        $t3, $a3, $zero
    ctx->r11 = ADD32(ctx->r7, 0);
    // 0x80082700: addu        $t2, $a2, $zero
    ctx->r10 = ADD32(ctx->r6, 0);
    // 0x80082704: addu        $t1, $zero, $zero
    ctx->r9 = ADD32(0, 0);
    // 0x80082708: addu        $t6, $zero, $zero
    ctx->r14 = ADD32(0, 0);
L_8008270C:
    // 0x8008270C: lw          $v0, 0x0($t7)
    ctx->r2 = MEM_W(ctx->r15, 0X0);
    // 0x80082710: addu        $v0, $t6, $v0
    ctx->r2 = ADD32(ctx->r14, ctx->r2);
    // 0x80082714: lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X0);
    // 0x80082718: beq         $v1, $zero, L_800827EC
    if (ctx->r3 == 0) {
        // 0x8008271C: addu        $t0, $v0, $zero
        ctx->r8 = ADD32(ctx->r2, 0);
            goto L_800827EC;
    }
    // 0x8008271C: addu        $t0, $v0, $zero
    ctx->r8 = ADD32(ctx->r2, 0);
    // 0x80082720: lw          $a3, 0x8($t0)
    ctx->r7 = MEM_W(ctx->r8, 0X8);
    // 0x80082724: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80082728: addu        $v0, $a2, $v1
    ctx->r2 = ADD32(ctx->r6, ctx->r3);
L_8008272C:
    // 0x8008272C: sra         $a0, $v0, 1
    ctx->r4 = S32(SIGNED(ctx->r2) >> 1);
    // 0x80082730: sll         $v0, $a0, 1
    ctx->r2 = S32(ctx->r4 << 1);
    // 0x80082734: addu        $v0, $v0, $a3
    ctx->r2 = ADD32(ctx->r2, ctx->r7);
    // 0x80082738: lh          $v0, -0x2($v0)
    ctx->r2 = MEM_H(ctx->r2, -0X2);
    // 0x8008273C: beq         $v0, $t4, L_80082770
    if (ctx->r2 == ctx->r12) {
        // 0x80082740: slt         $v0, $t4, $v0
        ctx->r2 = SIGNED(ctx->r12) < SIGNED(ctx->r2) ? 1 : 0;
            goto L_80082770;
    }
    // 0x80082740: slt         $v0, $t4, $v0
    ctx->r2 = SIGNED(ctx->r12) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80082744: beql        $v0, $zero, L_80082750
    if (ctx->r2 == 0) {
        // 0x80082748: addiu       $a2, $a0, 0x1
        ctx->r6 = ADD32(ctx->r4, 0X1);
            goto L_80082750;
    }
    goto skip_0;
    // 0x80082748: addiu       $a2, $a0, 0x1
    ctx->r6 = ADD32(ctx->r4, 0X1);
    skip_0:
    // 0x8008274C: addiu       $v1, $a0, -0x1
    ctx->r3 = ADD32(ctx->r4, -0X1);
L_80082750:
    // 0x80082750: slt         $v0, $a2, $v1
    ctx->r2 = SIGNED(ctx->r6) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80082754: bne         $v0, $zero, L_8008272C
    if (ctx->r2 != 0) {
        // 0x80082758: addu        $v0, $a2, $v1
        ctx->r2 = ADD32(ctx->r6, ctx->r3);
            goto L_8008272C;
    }
    // 0x80082758: addu        $v0, $a2, $v1
    ctx->r2 = ADD32(ctx->r6, ctx->r3);
    // 0x8008275C: sll         $v0, $a2, 1
    ctx->r2 = S32(ctx->r6 << 1);
    // 0x80082760: addu        $v0, $v0, $a3
    ctx->r2 = ADD32(ctx->r2, ctx->r7);
    // 0x80082764: lh          $v0, -0x2($v0)
    ctx->r2 = MEM_H(ctx->r2, -0X2);
    // 0x80082768: slt         $v0, $t4, $v0
    ctx->r2 = SIGNED(ctx->r12) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8008276C: subu        $a0, $a2, $v0
    ctx->r4 = SUB32(ctx->r6, ctx->r2);
L_80082770:
    // 0x80082770: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x80082774: addu        $at, $at, $t3
    ctx->r1 = ADD32(ctx->r1, ctx->r11);
    // 0x80082778: lw          $v0, -0x5664($at)
    ctx->r2 = MEM_W(ctx->r1, -0X5664);
    // 0x8008277C: addu        $v0, $t2, $v0
    ctx->r2 = ADD32(ctx->r10, ctx->r2);
    // 0x80082780: lw          $v0, 0xC($v0)
    ctx->r2 = MEM_W(ctx->r2, 0XC);
    // 0x80082784: addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
    // 0x80082788: addu        $v0, $t1, $v0
    ctx->r2 = ADD32(ctx->r9, ctx->r2);
    // 0x8008278C: sw          $a0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r4;
    // 0x80082790: lw          $v0, 0x0($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X0);
    // 0x80082794: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x80082798: beq         $a0, $v0, L_80082808
    if (ctx->r4 == ctx->r2) {
        // 0x8008279C: sll         $v0, $a0, 1
        ctx->r2 = S32(ctx->r4 << 1);
            goto L_80082808;
    }
    // 0x8008279C: sll         $v0, $a0, 1
    ctx->r2 = S32(ctx->r4 << 1);
    // 0x800827A0: lw          $v1, 0x8($t0)
    ctx->r3 = MEM_W(ctx->r8, 0X8);
    // 0x800827A4: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800827A8: lh          $a0, 0x0($v0)
    ctx->r4 = MEM_H(ctx->r2, 0X0);
    // 0x800827AC: lh          $v1, 0x2($v0)
    ctx->r3 = MEM_H(ctx->r2, 0X2);
    // 0x800827B0: subu        $v0, $t4, $a0
    ctx->r2 = SUB32(ctx->r12, ctx->r4);
    // 0x800827B4: mtc1        $v0, $f2
    ctx->f2.u32l = ctx->r2;
    // 0x800827B8: cvt.s.w     $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    ctx->f2.fl = CVT_S_W(ctx->f2.u32l);
    // 0x800827BC: subu        $v1, $v1, $a0
    ctx->r3 = SUB32(ctx->r3, ctx->r4);
    // 0x800827C0: mtc1        $v1, $f0
    ctx->f0.u32l = ctx->r3;
    // 0x800827C4: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x800827C8: div.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = DIV_S(ctx->f2.fl, ctx->f0.fl);
    // 0x800827CC: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x800827D0: addu        $at, $at, $t3
    ctx->r1 = ADD32(ctx->r1, ctx->r11);
    // 0x800827D4: lw          $v0, -0x5664($at)
    ctx->r2 = MEM_W(ctx->r1, -0X5664);
    // 0x800827D8: addu        $v0, $t2, $v0
    ctx->r2 = ADD32(ctx->r10, ctx->r2);
    // 0x800827DC: lw          $v0, 0xC($v0)
    ctx->r2 = MEM_W(ctx->r2, 0XC);
    // 0x800827E0: addu        $v0, $t1, $v0
    ctx->r2 = ADD32(ctx->r9, ctx->r2);
    // 0x800827E4: j           L_80082824
    // 0x800827E8: swc1        $f2, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f2.u32l;
        goto L_80082824;
    // 0x800827E8: swc1        $f2, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f2.u32l;
L_800827EC:
    // 0x800827EC: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x800827F0: addu        $at, $at, $t3
    ctx->r1 = ADD32(ctx->r1, ctx->r11);
    // 0x800827F4: lw          $v0, -0x5664($at)
    ctx->r2 = MEM_W(ctx->r1, -0X5664);
    // 0x800827F8: addu        $v0, $t2, $v0
    ctx->r2 = ADD32(ctx->r10, ctx->r2);
    // 0x800827FC: lw          $v0, 0xC($v0)
    ctx->r2 = MEM_W(ctx->r2, 0XC);
    // 0x80082800: addu        $v0, $t1, $v0
    ctx->r2 = ADD32(ctx->r9, ctx->r2);
    // 0x80082804: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
L_80082808:
    // 0x80082808: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x8008280C: addu        $at, $at, $t3
    ctx->r1 = ADD32(ctx->r1, ctx->r11);
    // 0x80082810: lw          $v0, -0x5664($at)
    ctx->r2 = MEM_W(ctx->r1, -0X5664);
    // 0x80082814: addu        $v0, $t2, $v0
    ctx->r2 = ADD32(ctx->r10, ctx->r2);
    // 0x80082818: lw          $v0, 0xC($v0)
    ctx->r2 = MEM_W(ctx->r2, 0XC);
    // 0x8008281C: addu        $v0, $t1, $v0
    ctx->r2 = ADD32(ctx->r9, ctx->r2);
    // 0x80082820: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
L_80082824:
    // 0x80082824: addiu       $t1, $t1, 0x8
    ctx->r9 = ADD32(ctx->r9, 0X8);
    // 0x80082828: lhu         $v0, 0xE($t7)
    ctx->r2 = MEM_HU(ctx->r15, 0XE);
    // 0x8008282C: addiu       $t5, $t5, 0x1
    ctx->r13 = ADD32(ctx->r13, 0X1);
    // 0x80082830: sltu        $v0, $t5, $v0
    ctx->r2 = ctx->r13 < ctx->r2 ? 1 : 0;
    // 0x80082834: bne         $v0, $zero, L_8008270C
    if (ctx->r2 != 0) {
        // 0x80082838: addiu       $t6, $t6, 0x1C
        ctx->r14 = ADD32(ctx->r14, 0X1C);
            goto L_8008270C;
    }
    // 0x80082838: addiu       $t6, $t6, 0x1C
    ctx->r14 = ADD32(ctx->r14, 0X1C);
L_8008283C:
    // 0x8008283C: addiu       $v1, $t8, -0x1
    ctx->r3 = ADD32(ctx->r24, -0X1);
    // 0x80082840: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x80082844: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80082848: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8008284C: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x80082850: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80082854: lw          $v1, -0x5664($at)
    ctx->r3 = MEM_W(ctx->r1, -0X5664);
    // 0x80082858: sll         $v0, $a1, 4
    ctx->r2 = S32(ctx->r5 << 4);
    // 0x8008285C: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80082860: swc1        $f4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f4.u32l;
    // 0x80082864: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    // 0x80082868: jr          $ra
    // 0x8008286C: nop

    return;
    // 0x8008286C: nop

;}
RECOMP_FUNC void func_80082870(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80082870: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x80082874: andi        $v0, $a0, 0xFFFF
    ctx->r2 = ctx->r4 & 0XFFFF;
L_80082878:
    // 0x80082878: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x8008287C: sll         $v1, $v0, 2
    ctx->r3 = S32(ctx->r2 << 2);
    // 0x80082880: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x80082884: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x80082888: andi        $v0, $a0, 0xFFFF
    ctx->r2 = ctx->r4 & 0XFFFF;
    // 0x8008288C: sltiu       $v0, $v0, 0x20
    ctx->r2 = ctx->r2 < 0X20 ? 1 : 0;
    // 0x80082890: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x80082894: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x80082898: sw          $zero, -0x5670($at)
    MEM_W(-0X5670, ctx->r1) = 0;
    // 0x8008289C: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x800828A0: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x800828A4: sw          $zero, -0x566C($at)
    MEM_W(-0X566C, ctx->r1) = 0;
    // 0x800828A8: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x800828AC: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x800828B0: sw          $zero, -0x5668($at)
    MEM_W(-0X5668, ctx->r1) = 0;
    // 0x800828B4: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x800828B8: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x800828BC: sb          $zero, -0x5660($at)
    MEM_B(-0X5660, ctx->r1) = 0;
    // 0x800828C0: bnel        $v0, $zero, L_80082878
    if (ctx->r2 != 0) {
        // 0x800828C4: andi        $v0, $a0, 0xFFFF
        ctx->r2 = ctx->r4 & 0XFFFF;
            goto L_80082878;
    }
    goto skip_0;
    // 0x800828C4: andi        $v0, $a0, 0xFFFF
    ctx->r2 = ctx->r4 & 0XFFFF;
    skip_0:
    // 0x800828C8: jr          $ra
    // 0x800828CC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x800828CC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
;}
RECOMP_FUNC void func_800828D0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800828D0: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x800828D4: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x800828D8: addu        $s4, $a2, $zero
    ctx->r20 = ADD32(ctx->r6, 0);
    // 0x800828DC: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x800828E0: addu        $s3, $zero, $zero
    ctx->r19 = ADD32(0, 0);
    // 0x800828E4: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x800828E8: addu        $s1, $zero, $zero
    ctx->r17 = ADD32(0, 0);
    // 0x800828EC: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
    // 0x800828F0: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x800828F4: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x800828F8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800828FC: sdc1        $f20, 0x30($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X30, ctx->r29);
L_80082900:
    // 0x80082900: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x80082904: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x80082908: lbu         $v0, -0x5660($at)
    ctx->r2 = MEM_BU(ctx->r1, -0X5660);
    // 0x8008290C: bnel        $v0, $zero, L_8008291C
    if (ctx->r2 != 0) {
        // 0x80082910: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_8008291C;
    }
    goto skip_0;
    // 0x80082910: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    skip_0:
    // 0x80082914: j           L_80082928
    // 0x80082918: addiu       $s3, $s1, 0x1
    ctx->r19 = ADD32(ctx->r17, 0X1);
        goto L_80082928;
    // 0x80082918: addiu       $s3, $s1, 0x1
    ctx->r19 = ADD32(ctx->r17, 0X1);
L_8008291C:
    // 0x8008291C: sltiu       $v0, $s1, 0x20
    ctx->r2 = ctx->r17 < 0X20 ? 1 : 0;
    // 0x80082920: bne         $v0, $zero, L_80082900
    if (ctx->r2 != 0) {
        // 0x80082924: addiu       $v1, $v1, 0x14
        ctx->r3 = ADD32(ctx->r3, 0X14);
            goto L_80082900;
    }
    // 0x80082924: addiu       $v1, $v1, 0x14
    ctx->r3 = ADD32(ctx->r3, 0X14);
L_80082928:
    // 0x80082928: beq         $s3, $zero, L_80082A6C
    if (ctx->r19 == 0) {
        // 0x8008292C: addiu       $v1, $s3, -0x1
        ctx->r3 = ADD32(ctx->r19, -0X1);
            goto L_80082A6C;
    }
    // 0x8008292C: addiu       $v1, $s3, -0x1
    ctx->r3 = ADD32(ctx->r19, -0X1);
    // 0x80082930: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x80082934: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80082938: sll         $s0, $v0, 2
    ctx->r16 = S32(ctx->r2 << 2);
    // 0x8008293C: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x80082940: addu        $at, $at, $s0
    ctx->r1 = ADD32(ctx->r1, ctx->r16);
    // 0x80082944: sw          $a0, -0x5670($at)
    MEM_W(-0X5670, ctx->r1) = ctx->r4;
    // 0x80082948: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x8008294C: addu        $at, $at, $s0
    ctx->r1 = ADD32(ctx->r1, ctx->r16);
    // 0x80082950: sw          $s4, -0x566C($at)
    MEM_W(-0X566C, ctx->r1) = ctx->r20;
    // 0x80082954: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x80082958: addu        $at, $at, $s0
    ctx->r1 = ADD32(ctx->r1, ctx->r16);
    // 0x8008295C: sw          $a1, -0x5668($at)
    MEM_W(-0X5668, ctx->r1) = ctx->r5;
    // 0x80082960: lw          $a0, 0x0($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X0);
    // 0x80082964: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x80082968: jal         0x80001ACC
    // 0x8008296C: sll         $a0, $a0, 4
    ctx->r4 = S32(ctx->r4 << 4);
    rs_malloc(rdram, ctx);
        goto after_0;
    // 0x8008296C: sll         $a0, $a0, 4
    ctx->r4 = S32(ctx->r4 << 4);
    after_0:
    // 0x80082970: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x80082974: addu        $at, $at, $s0
    ctx->r1 = ADD32(ctx->r1, ctx->r16);
    // 0x80082978: lw          $v1, -0x5668($at)
    ctx->r3 = MEM_W(ctx->r1, -0X5668);
    // 0x8008297C: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x80082980: addu        $at, $at, $s0
    ctx->r1 = ADD32(ctx->r1, ctx->r16);
    // 0x80082984: sw          $v0, -0x5664($at)
    MEM_W(-0X5664, ctx->r1) = ctx->r2;
    // 0x80082988: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8008298C: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x80082990: addu        $at, $at, $s0
    ctx->r1 = ADD32(ctx->r1, ctx->r16);
    // 0x80082994: sb          $v0, -0x5660($at)
    MEM_B(-0X5660, ctx->r1) = ctx->r2;
    // 0x80082998: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x8008299C: addu        $at, $at, $s0
    ctx->r1 = ADD32(ctx->r1, ctx->r16);
    // 0x800829A0: sb          $zero, -0x565F($at)
    MEM_B(-0X565F, ctx->r1) = 0;
    // 0x800829A4: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x800829A8: beq         $v0, $zero, L_80082A6C
    if (ctx->r2 == 0) {
        // 0x800829AC: addu        $s1, $zero, $zero
        ctx->r17 = ADD32(0, 0);
            goto L_80082A6C;
    }
    // 0x800829AC: addu        $s1, $zero, $zero
    ctx->r17 = ADD32(0, 0);
    // 0x800829B0: addu        $s2, $s0, $zero
    ctx->r18 = ADD32(ctx->r16, 0);
    // 0x800829B4: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x800829B8: lwc1        $f20, -0x24E8($at)
    ctx->f20.u32l = MEM_W(ctx->r1, -0X24E8);
L_800829BC:
    // 0x800829BC: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x800829C0: addu        $at, $at, $s2
    ctx->r1 = ADD32(ctx->r1, ctx->r18);
    // 0x800829C4: lw          $v0, -0x5664($at)
    ctx->r2 = MEM_W(ctx->r1, -0X5664);
    // 0x800829C8: sll         $s0, $s1, 4
    ctx->r16 = S32(ctx->r17 << 4);
    // 0x800829CC: addu        $v0, $s0, $v0
    ctx->r2 = ADD32(ctx->r16, ctx->r2);
    // 0x800829D0: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
    // 0x800829D4: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x800829D8: addu        $at, $at, $s2
    ctx->r1 = ADD32(ctx->r1, ctx->r18);
    // 0x800829DC: lw          $v0, -0x5664($at)
    ctx->r2 = MEM_W(ctx->r1, -0X5664);
    // 0x800829E0: addu        $v0, $s0, $v0
    ctx->r2 = ADD32(ctx->r16, ctx->r2);
    // 0x800829E4: swc1        $f20, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f20.u32l;
    // 0x800829E8: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x800829EC: addu        $at, $at, $s2
    ctx->r1 = ADD32(ctx->r1, ctx->r18);
    // 0x800829F0: lw          $v0, -0x5664($at)
    ctx->r2 = MEM_W(ctx->r1, -0X5664);
    // 0x800829F4: sll         $a0, $s4, 3
    ctx->r4 = S32(ctx->r20 << 3);
    // 0x800829F8: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x800829FC: addu        $v0, $s0, $v0
    ctx->r2 = ADD32(ctx->r16, ctx->r2);
    // 0x80082A00: jal         0x80001ACC
    // 0x80082A04: sb          $zero, 0x8($v0)
    MEM_B(0X8, ctx->r2) = 0;
    rs_malloc(rdram, ctx);
        goto after_1;
    // 0x80082A04: sb          $zero, 0x8($v0)
    MEM_B(0X8, ctx->r2) = 0;
    after_1:
    // 0x80082A08: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x80082A0C: addu        $at, $at, $s2
    ctx->r1 = ADD32(ctx->r1, ctx->r18);
    // 0x80082A10: lw          $v1, -0x5664($at)
    ctx->r3 = MEM_W(ctx->r1, -0X5664);
    // 0x80082A14: addu        $v1, $s0, $v1
    ctx->r3 = ADD32(ctx->r16, ctx->r3);
    // 0x80082A18: sw          $v0, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r2;
    // 0x80082A1C: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x80082A20: addu        $at, $at, $s2
    ctx->r1 = ADD32(ctx->r1, ctx->r18);
    // 0x80082A24: lw          $v0, -0x5664($at)
    ctx->r2 = MEM_W(ctx->r1, -0X5664);
    // 0x80082A28: addu        $v0, $s0, $v0
    ctx->r2 = ADD32(ctx->r16, ctx->r2);
    // 0x80082A2C: lw          $v0, 0xC($v0)
    ctx->r2 = MEM_W(ctx->r2, 0XC);
    // 0x80082A30: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
    // 0x80082A34: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x80082A38: addu        $at, $at, $s2
    ctx->r1 = ADD32(ctx->r1, ctx->r18);
    // 0x80082A3C: lw          $v0, -0x5664($at)
    ctx->r2 = MEM_W(ctx->r1, -0X5664);
    // 0x80082A40: addu        $s0, $s0, $v0
    ctx->r16 = ADD32(ctx->r16, ctx->r2);
    // 0x80082A44: lw          $v0, 0xC($s0)
    ctx->r2 = MEM_W(ctx->r16, 0XC);
    // 0x80082A48: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80082A4C: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x80082A50: addu        $at, $at, $s2
    ctx->r1 = ADD32(ctx->r1, ctx->r18);
    // 0x80082A54: lw          $v0, -0x5668($at)
    ctx->r2 = MEM_W(ctx->r1, -0X5668);
    // 0x80082A58: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x80082A5C: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80082A60: sltu        $v0, $s1, $v0
    ctx->r2 = ctx->r17 < ctx->r2 ? 1 : 0;
    // 0x80082A64: bne         $v0, $zero, L_800829BC
    if (ctx->r2 != 0) {
        // 0x80082A68: nop
    
            goto L_800829BC;
    }
    // 0x80082A68: nop

L_80082A6C:
    // 0x80082A6C: addu        $v0, $s3, $zero
    ctx->r2 = ADD32(ctx->r19, 0);
    // 0x80082A70: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80082A74: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x80082A78: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x80082A7C: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80082A80: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80082A84: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80082A88: ldc1        $f20, 0x30($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X30);
    // 0x80082A8C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80082A90: jr          $ra
    // 0x80082A94: nop

    return;
    // 0x80082A94: nop

;}
RECOMP_FUNC void func_80082A98(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80082A98: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x80082A9C: lw          $v0, -0x53F0($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X53F0);
    // 0x80082AA0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80082AA4: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x80082AA8: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x80082AAC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80082AB0: addiu       $v1, $v0, 0x4
    ctx->r3 = ADD32(ctx->r2, 0X4);
    // 0x80082AB4: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x80082AB8: sw          $v1, -0x53F0($at)
    MEM_W(-0X53F0, ctx->r1) = ctx->r3;
    // 0x80082ABC: addiu       $v1, $s0, 0x1C
    ctx->r3 = ADD32(ctx->r16, 0X1C);
    // 0x80082AC0: sw          $v1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r3;
    // 0x80082AC4: lw          $a0, 0xC($s0)
    ctx->r4 = MEM_W(ctx->r16, 0XC);
    // 0x80082AC8: beq         $a0, $zero, L_80082AD8
    if (ctx->r4 == 0) {
        // 0x80082ACC: nop
    
            goto L_80082AD8;
    }
    // 0x80082ACC: nop

    // 0x80082AD0: jal         0x80082A98
    // 0x80082AD4: nop

    func_80082A98(rdram, ctx);
        goto after_0;
    // 0x80082AD4: nop

    after_0:
L_80082AD8:
    // 0x80082AD8: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80082ADC: beq         $a0, $zero, L_80082AEC
    if (ctx->r4 == 0) {
        // 0x80082AE0: nop
    
            goto L_80082AEC;
    }
    // 0x80082AE0: nop

    // 0x80082AE4: jal         0x80082A98
    // 0x80082AE8: nop

    func_80082A98(rdram, ctx);
        goto after_1;
    // 0x80082AE8: nop

    after_1:
L_80082AEC:
    // 0x80082AEC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80082AF0: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x80082AF4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80082AF8: jr          $ra
    // 0x80082AFC: nop

    return;
    // 0x80082AFC: nop

;}
RECOMP_FUNC void func_80082B00(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80082B00: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80082B04: sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // 0x80082B08: addu        $s2, $a1, $zero
    ctx->r18 = ADD32(ctx->r5, 0);
    // 0x80082B0C: sw          $ra, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r31;
    // 0x80082B10: sw          $s3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r19;
    // 0x80082B14: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x80082B18: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x80082B1C: lw          $v0, 0x4($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X4);
    // 0x80082B20: lhu         $s3, 0xE($v0)
    ctx->r19 = MEM_HU(ctx->r2, 0XE);
    // 0x80082B24: addu        $s1, $a0, $zero
    ctx->r17 = ADD32(ctx->r4, 0);
    // 0x80082B28: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x80082B2C: jal         0x80001ACC
    // 0x80082B30: sll         $a0, $s3, 2
    ctx->r4 = S32(ctx->r19 << 2);
    rs_malloc(rdram, ctx);
        goto after_0;
    // 0x80082B30: sll         $a0, $s3, 2
    ctx->r4 = S32(ctx->r19 << 2);
    after_0:
    // 0x80082B34: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    // 0x80082B38: addiu       $v0, $s0, 0x4
    ctx->r2 = ADD32(ctx->r16, 0X4);
    // 0x80082B3C: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x80082B40: sw          $v0, -0x53F0($at)
    MEM_W(-0X53F0, ctx->r1) = ctx->r2;
    // 0x80082B44: addiu       $v0, $s1, 0x1C
    ctx->r2 = ADD32(ctx->r17, 0X1C);
    // 0x80082B48: sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
    // 0x80082B4C: lw          $a0, 0xC($s1)
    ctx->r4 = MEM_W(ctx->r17, 0XC);
    // 0x80082B50: beq         $a0, $zero, L_80082B60
    if (ctx->r4 == 0) {
        // 0x80082B54: nop
    
            goto L_80082B60;
    }
    // 0x80082B54: nop

    // 0x80082B58: jal         0x80082A98
    // 0x80082B5C: nop

    func_80082A98(rdram, ctx);
        goto after_1;
    // 0x80082B5C: nop

    after_1:
L_80082B60:
    // 0x80082B60: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x80082B64: beql        $a0, $zero, L_80082B78
    if (ctx->r4 == 0) {
        // 0x80082B68: addu        $a0, $s0, $zero
        ctx->r4 = ADD32(ctx->r16, 0);
            goto L_80082B78;
    }
    goto skip_0;
    // 0x80082B68: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    skip_0:
    // 0x80082B6C: jal         0x80082A98
    // 0x80082B70: nop

    func_80082A98(rdram, ctx);
        goto after_2;
    // 0x80082B70: nop

    after_2:
    // 0x80082B74: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
L_80082B78:
    // 0x80082B78: addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    // 0x80082B7C: jal         0x800828D0
    // 0x80082B80: addu        $a2, $s3, $zero
    ctx->r6 = ADD32(ctx->r19, 0);
    func_800828D0(rdram, ctx);
        goto after_3;
    // 0x80082B80: addu        $a2, $s3, $zero
    ctx->r6 = ADD32(ctx->r19, 0);
    after_3:
    // 0x80082B84: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // 0x80082B88: beq         $a0, $zero, L_80082BAC
    if (ctx->r4 == 0) {
        // 0x80082B8C: addiu       $v0, $a0, -0x1
        ctx->r2 = ADD32(ctx->r4, -0X1);
            goto L_80082BAC;
    }
    // 0x80082B8C: addiu       $v0, $a0, -0x1
    ctx->r2 = ADD32(ctx->r4, -0X1);
    // 0x80082B90: sll         $v1, $v0, 2
    ctx->r3 = S32(ctx->r2 << 2);
    // 0x80082B94: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x80082B98: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x80082B9C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80082BA0: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x80082BA4: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x80082BA8: sb          $v0, -0x565F($at)
    MEM_B(-0X565F, ctx->r1) = ctx->r2;
L_80082BAC:
    // 0x80082BAC: addu        $v0, $a0, $zero
    ctx->r2 = ADD32(ctx->r4, 0);
    // 0x80082BB0: lw          $ra, 0x20($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X20);
    // 0x80082BB4: lw          $s3, 0x1C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X1C);
    // 0x80082BB8: lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X18);
    // 0x80082BBC: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x80082BC0: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x80082BC4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80082BC8: jr          $ra
    // 0x80082BCC: nop

    return;
    // 0x80082BCC: nop

;}
RECOMP_FUNC void model_animation_offset_convert(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80082BD0: lw          $v0, 0x4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X4);
    // 0x80082BD4: beq         $v0, $zero, L_80082CF0
    if (ctx->r2 == 0) {
        // 0x80082BD8: addiu       $sp, $sp, -0x10
        ctx->r29 = ADD32(ctx->r29, -0X10);
            goto L_80082CF0;
    }
    // 0x80082BD8: addiu       $sp, $sp, -0x10
    ctx->r29 = ADD32(ctx->r29, -0X10);
    // 0x80082BDC: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x80082BE0: addu        $t0, $zero, $zero
    ctx->r8 = ADD32(0, 0);
    // 0x80082BE4: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x80082BE8: beq         $v1, $zero, L_80082CF0
    if (ctx->r3 == 0) {
        // 0x80082BEC: sw          $v0, 0x4($a0)
        MEM_W(0X4, ctx->r4) = ctx->r2;
            goto L_80082CF0;
    }
    // 0x80082BEC: sw          $v0, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r2;
    // 0x80082BF0: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
L_80082BF4:
    // 0x80082BF4: lw          $v0, 0x4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X4);
    // 0x80082BF8: addu        $v1, $a2, $v0
    ctx->r3 = ADD32(ctx->r6, ctx->r2);
    // 0x80082BFC: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80082C00: beq         $v0, $zero, L_80082CDC
    if (ctx->r2 == 0) {
        // 0x80082C04: addu        $v0, $v0, $a0
        ctx->r2 = ADD32(ctx->r2, ctx->r4);
            goto L_80082CDC;
    }
    // 0x80082C04: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x80082C08: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x80082C0C: lw          $v1, 0x4($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X4);
    // 0x80082C10: addu        $v0, $a2, $v1
    ctx->r2 = ADD32(ctx->r6, ctx->r3);
    // 0x80082C14: lhu         $v0, 0xE($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0XE);
    // 0x80082C18: beq         $v0, $zero, L_80082CDC
    if (ctx->r2 == 0) {
        // 0x80082C1C: addu        $a3, $zero, $zero
        ctx->r7 = ADD32(0, 0);
            goto L_80082CDC;
    }
    // 0x80082C1C: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    // 0x80082C20: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
L_80082C24:
    // 0x80082C24: addu        $v0, $a2, $v1
    ctx->r2 = ADD32(ctx->r6, ctx->r3);
    // 0x80082C28: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x80082C2C: addu        $v1, $a1, $v0
    ctx->r3 = ADD32(ctx->r5, ctx->r2);
    // 0x80082C30: lw          $v0, 0x8($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X8);
    // 0x80082C34: beq         $v0, $zero, L_80082C40
    if (ctx->r2 == 0) {
        // 0x80082C38: addu        $v0, $v0, $a0
        ctx->r2 = ADD32(ctx->r2, ctx->r4);
            goto L_80082C40;
    }
    // 0x80082C38: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x80082C3C: sw          $v0, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r2;
L_80082C40:
    // 0x80082C40: lw          $v0, 0x4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X4);
    // 0x80082C44: addu        $v0, $a2, $v0
    ctx->r2 = ADD32(ctx->r6, ctx->r2);
    // 0x80082C48: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x80082C4C: addu        $v1, $a1, $v0
    ctx->r3 = ADD32(ctx->r5, ctx->r2);
    // 0x80082C50: lw          $v0, 0xC($v1)
    ctx->r2 = MEM_W(ctx->r3, 0XC);
    // 0x80082C54: beq         $v0, $zero, L_80082C60
    if (ctx->r2 == 0) {
        // 0x80082C58: addu        $v0, $v0, $a0
        ctx->r2 = ADD32(ctx->r2, ctx->r4);
            goto L_80082C60;
    }
    // 0x80082C58: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x80082C5C: sw          $v0, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r2;
L_80082C60:
    // 0x80082C60: lw          $v0, 0x4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X4);
    // 0x80082C64: addu        $v0, $a2, $v0
    ctx->r2 = ADD32(ctx->r6, ctx->r2);
    // 0x80082C68: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x80082C6C: addu        $v1, $a1, $v0
    ctx->r3 = ADD32(ctx->r5, ctx->r2);
    // 0x80082C70: lw          $v0, 0x10($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X10);
    // 0x80082C74: beq         $v0, $zero, L_80082C80
    if (ctx->r2 == 0) {
        // 0x80082C78: addu        $v0, $v0, $a0
        ctx->r2 = ADD32(ctx->r2, ctx->r4);
            goto L_80082C80;
    }
    // 0x80082C78: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x80082C7C: sw          $v0, 0x10($v1)
    MEM_W(0X10, ctx->r3) = ctx->r2;
L_80082C80:
    // 0x80082C80: lw          $v0, 0x4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X4);
    // 0x80082C84: addu        $v0, $a2, $v0
    ctx->r2 = ADD32(ctx->r6, ctx->r2);
    // 0x80082C88: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x80082C8C: addu        $v1, $a1, $v0
    ctx->r3 = ADD32(ctx->r5, ctx->r2);
    // 0x80082C90: lw          $v0, 0x14($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X14);
    // 0x80082C94: beq         $v0, $zero, L_80082CA0
    if (ctx->r2 == 0) {
        // 0x80082C98: addu        $v0, $v0, $a0
        ctx->r2 = ADD32(ctx->r2, ctx->r4);
            goto L_80082CA0;
    }
    // 0x80082C98: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x80082C9C: sw          $v0, 0x14($v1)
    MEM_W(0X14, ctx->r3) = ctx->r2;
L_80082CA0:
    // 0x80082CA0: lw          $v0, 0x4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X4);
    // 0x80082CA4: addu        $v0, $a2, $v0
    ctx->r2 = ADD32(ctx->r6, ctx->r2);
    // 0x80082CA8: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x80082CAC: addu        $v1, $a1, $v0
    ctx->r3 = ADD32(ctx->r5, ctx->r2);
    // 0x80082CB0: lw          $v0, 0x18($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X18);
    // 0x80082CB4: beq         $v0, $zero, L_80082CC0
    if (ctx->r2 == 0) {
        // 0x80082CB8: addu        $v0, $v0, $a0
        ctx->r2 = ADD32(ctx->r2, ctx->r4);
            goto L_80082CC0;
    }
    // 0x80082CB8: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x80082CBC: sw          $v0, 0x18($v1)
    MEM_W(0X18, ctx->r3) = ctx->r2;
L_80082CC0:
    // 0x80082CC0: lw          $v1, 0x4($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X4);
    // 0x80082CC4: addu        $v0, $a2, $v1
    ctx->r2 = ADD32(ctx->r6, ctx->r3);
    // 0x80082CC8: lhu         $v0, 0xE($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0XE);
    // 0x80082CCC: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x80082CD0: sltu        $v0, $a3, $v0
    ctx->r2 = ctx->r7 < ctx->r2 ? 1 : 0;
    // 0x80082CD4: bne         $v0, $zero, L_80082C24
    if (ctx->r2 != 0) {
        // 0x80082CD8: addiu       $a1, $a1, 0x1C
        ctx->r5 = ADD32(ctx->r5, 0X1C);
            goto L_80082C24;
    }
    // 0x80082CD8: addiu       $a1, $a1, 0x1C
    ctx->r5 = ADD32(ctx->r5, 0X1C);
L_80082CDC:
    // 0x80082CDC: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x80082CE0: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    // 0x80082CE4: sltu        $v0, $t0, $v0
    ctx->r2 = ctx->r8 < ctx->r2 ? 1 : 0;
    // 0x80082CE8: bne         $v0, $zero, L_80082BF4
    if (ctx->r2 != 0) {
        // 0x80082CEC: addiu       $a2, $a2, 0x10
        ctx->r6 = ADD32(ctx->r6, 0X10);
            goto L_80082BF4;
    }
    // 0x80082CEC: addiu       $a2, $a2, 0x10
    ctx->r6 = ADD32(ctx->r6, 0X10);
L_80082CF0:
    // 0x80082CF0: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
    // 0x80082CF4: jr          $ra
    // 0x80082CF8: nop

    return;
    // 0x80082CF8: nop

;}
RECOMP_FUNC void func_80082CFC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80082CFC: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80082D00: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x80082D04: addiu       $s3, $a0, -0x1
    ctx->r19 = ADD32(ctx->r4, -0X1);
    // 0x80082D08: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80082D0C: sll         $s2, $s3, 2
    ctx->r18 = S32(ctx->r19 << 2);
    // 0x80082D10: addu        $v0, $s2, $s3
    ctx->r2 = ADD32(ctx->r18, ctx->r19);
    // 0x80082D14: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80082D18: sw          $ra, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r31;
    // 0x80082D1C: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80082D20: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80082D24: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x80082D28: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80082D2C: lw          $v0, -0x5668($at)
    ctx->r2 = MEM_W(ctx->r1, -0X5668);
    // 0x80082D30: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x80082D34: beq         $v0, $zero, L_80082D80
    if (ctx->r2 == 0) {
        // 0x80082D38: addu        $s1, $zero, $zero
        ctx->r17 = ADD32(0, 0);
            goto L_80082D80;
    }
    // 0x80082D38: addu        $s1, $zero, $zero
    ctx->r17 = ADD32(0, 0);
    // 0x80082D3C: addu        $s0, $s2, $s3
    ctx->r16 = ADD32(ctx->r18, ctx->r19);
L_80082D40:
    // 0x80082D40: sll         $s0, $s0, 2
    ctx->r16 = S32(ctx->r16 << 2);
    // 0x80082D44: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x80082D48: addu        $at, $at, $s0
    ctx->r1 = ADD32(ctx->r1, ctx->r16);
    // 0x80082D4C: lw          $v1, -0x5664($at)
    ctx->r3 = MEM_W(ctx->r1, -0X5664);
    // 0x80082D50: sll         $v0, $s1, 4
    ctx->r2 = S32(ctx->r17 << 4);
    // 0x80082D54: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80082D58: lw          $a0, 0xC($v0)
    ctx->r4 = MEM_W(ctx->r2, 0XC);
    // 0x80082D5C: jal         0x80001C98
    // 0x80082D60: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    rs_free(rdram, ctx);
        goto after_0;
    // 0x80082D60: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    after_0:
    // 0x80082D64: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x80082D68: addu        $at, $at, $s0
    ctx->r1 = ADD32(ctx->r1, ctx->r16);
    // 0x80082D6C: lw          $v0, -0x5668($at)
    ctx->r2 = MEM_W(ctx->r1, -0X5668);
    // 0x80082D70: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x80082D74: sltu        $v0, $s1, $v0
    ctx->r2 = ctx->r17 < ctx->r2 ? 1 : 0;
    // 0x80082D78: bne         $v0, $zero, L_80082D40
    if (ctx->r2 != 0) {
        // 0x80082D7C: addu        $s0, $s2, $s3
        ctx->r16 = ADD32(ctx->r18, ctx->r19);
            goto L_80082D40;
    }
    // 0x80082D7C: addu        $s0, $s2, $s3
    ctx->r16 = ADD32(ctx->r18, ctx->r19);
L_80082D80:
    // 0x80082D80: sll         $v0, $s3, 2
    ctx->r2 = S32(ctx->r19 << 2);
    // 0x80082D84: addu        $v0, $v0, $s3
    ctx->r2 = ADD32(ctx->r2, ctx->r19);
    // 0x80082D88: sll         $s0, $v0, 2
    ctx->r16 = S32(ctx->r2 << 2);
    // 0x80082D8C: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x80082D90: addu        $at, $at, $s0
    ctx->r1 = ADD32(ctx->r1, ctx->r16);
    // 0x80082D94: lw          $a0, -0x5664($at)
    ctx->r4 = MEM_W(ctx->r1, -0X5664);
    // 0x80082D98: jal         0x80001C98
    // 0x80082D9C: nop

    rs_free(rdram, ctx);
        goto after_1;
    // 0x80082D9C: nop

    after_1:
    // 0x80082DA0: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x80082DA4: addu        $at, $at, $s0
    ctx->r1 = ADD32(ctx->r1, ctx->r16);
    // 0x80082DA8: lbu         $v0, -0x565F($at)
    ctx->r2 = MEM_BU(ctx->r1, -0X565F);
    // 0x80082DAC: beq         $v0, $zero, L_80082DC8
    if (ctx->r2 == 0) {
        // 0x80082DB0: nop
    
            goto L_80082DC8;
    }
    // 0x80082DB0: nop

    // 0x80082DB4: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x80082DB8: addu        $at, $at, $s0
    ctx->r1 = ADD32(ctx->r1, ctx->r16);
    // 0x80082DBC: lw          $a0, -0x5670($at)
    ctx->r4 = MEM_W(ctx->r1, -0X5670);
    // 0x80082DC0: jal         0x80001C98
    // 0x80082DC4: nop

    rs_free(rdram, ctx);
        goto after_2;
    // 0x80082DC4: nop

    after_2:
L_80082DC8:
    // 0x80082DC8: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x80082DCC: addu        $at, $at, $s0
    ctx->r1 = ADD32(ctx->r1, ctx->r16);
    // 0x80082DD0: sw          $zero, -0x5670($at)
    MEM_W(-0X5670, ctx->r1) = 0;
    // 0x80082DD4: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x80082DD8: addu        $at, $at, $s0
    ctx->r1 = ADD32(ctx->r1, ctx->r16);
    // 0x80082DDC: sw          $zero, -0x566C($at)
    MEM_W(-0X566C, ctx->r1) = 0;
    // 0x80082DE0: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x80082DE4: addu        $at, $at, $s0
    ctx->r1 = ADD32(ctx->r1, ctx->r16);
    // 0x80082DE8: sw          $zero, -0x5668($at)
    MEM_W(-0X5668, ctx->r1) = 0;
    // 0x80082DEC: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x80082DF0: addu        $at, $at, $s0
    ctx->r1 = ADD32(ctx->r1, ctx->r16);
    // 0x80082DF4: sb          $zero, -0x5660($at)
    MEM_B(-0X5660, ctx->r1) = 0;
    // 0x80082DF8: lw          $ra, 0x28($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X28);
    // 0x80082DFC: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x80082E00: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80082E04: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80082E08: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80082E0C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80082E10: jr          $ra
    // 0x80082E14: nop

    return;
    // 0x80082E14: nop

;}
RECOMP_FUNC void func_80082E18(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80082E18: addu        $a2, $a0, $zero
    ctx->r6 = ADD32(ctx->r4, 0);
    // 0x80082E1C: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    // 0x80082E20: sltu        $v0, $zero, $a2
    ctx->r2 = 0 < ctx->r6 ? 1 : 0;
    // 0x80082E24: sltiu       $v1, $a2, 0x21
    ctx->r3 = ctx->r6 < 0X21 ? 1 : 0;
    // 0x80082E28: and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // 0x80082E2C: beq         $v0, $zero, L_80082E58
    if (ctx->r2 == 0) {
        // 0x80082E30: addu        $a0, $zero, $zero
        ctx->r4 = ADD32(0, 0);
            goto L_80082E58;
    }
    // 0x80082E30: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x80082E34: addiu       $v0, $a2, -0x1
    ctx->r2 = ADD32(ctx->r6, -0X1);
    // 0x80082E38: sll         $v1, $v0, 2
    ctx->r3 = S32(ctx->r2 << 2);
    // 0x80082E3C: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x80082E40: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x80082E44: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x80082E48: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x80082E4C: lbu         $v0, -0x5660($at)
    ctx->r2 = MEM_BU(ctx->r1, -0X5660);
    // 0x80082E50: xori        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 ^ 0X1;
    // 0x80082E54: sltiu       $a0, $v0, 0x1
    ctx->r4 = ctx->r2 < 0X1 ? 1 : 0;
L_80082E58:
    // 0x80082E58: addu        $v0, $a0, $zero
    ctx->r2 = ADD32(ctx->r4, 0);
    // 0x80082E5C: beq         $v0, $zero, L_80082E98
    if (ctx->r2 == 0) {
        // 0x80082E60: addiu       $v1, $a2, -0x1
        ctx->r3 = ADD32(ctx->r6, -0X1);
            goto L_80082E98;
    }
    // 0x80082E60: addiu       $v1, $a2, -0x1
    ctx->r3 = ADD32(ctx->r6, -0X1);
    // 0x80082E64: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x80082E68: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80082E6C: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80082E70: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x80082E74: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80082E78: lw          $v0, -0x5664($at)
    ctx->r2 = MEM_W(ctx->r1, -0X5664);
    // 0x80082E7C: sll         $a0, $a1, 4
    ctx->r4 = S32(ctx->r5 << 4);
    // 0x80082E80: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // 0x80082E84: lbu         $v0, 0x8($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X8);
    // 0x80082E88: sll         $v1, $a2, 16
    ctx->r3 = S32(ctx->r6 << 16);
    // 0x80082E8C: addu        $a3, $v1, $a1
    ctx->r7 = ADD32(ctx->r3, ctx->r5);
    // 0x80082E90: ori         $v0, $v0, 0x1
    ctx->r2 = ctx->r2 | 0X1;
    // 0x80082E94: sb          $v0, 0x8($a0)
    MEM_B(0X8, ctx->r4) = ctx->r2;
L_80082E98:
    // 0x80082E98: jr          $ra
    // 0x80082E9C: addu        $v0, $a3, $zero
    ctx->r2 = ADD32(ctx->r7, 0);
    return;
    // 0x80082E9C: addu        $v0, $a3, $zero
    ctx->r2 = ADD32(ctx->r7, 0);
;}
RECOMP_FUNC void func_80082EA0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80082EA0: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // 0x80082EA4: srl         $a1, $a0, 16
    ctx->r5 = S32(U32(ctx->r4) >> 16);
    // 0x80082EA8: sltu        $v0, $zero, $a1
    ctx->r2 = 0 < ctx->r5 ? 1 : 0;
    // 0x80082EAC: sltiu       $v1, $a1, 0x21
    ctx->r3 = ctx->r5 < 0X21 ? 1 : 0;
    // 0x80082EB0: and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // 0x80082EB4: beq         $v0, $zero, L_80082EE0
    if (ctx->r2 == 0) {
        // 0x80082EB8: andi        $a0, $a0, 0xFFFF
        ctx->r4 = ctx->r4 & 0XFFFF;
            goto L_80082EE0;
    }
    // 0x80082EB8: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    // 0x80082EBC: addiu       $v0, $a1, -0x1
    ctx->r2 = ADD32(ctx->r5, -0X1);
    // 0x80082EC0: sll         $v1, $v0, 2
    ctx->r3 = S32(ctx->r2 << 2);
    // 0x80082EC4: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x80082EC8: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x80082ECC: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x80082ED0: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x80082ED4: lbu         $v0, -0x5660($at)
    ctx->r2 = MEM_BU(ctx->r1, -0X5660);
    // 0x80082ED8: xori        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 ^ 0X1;
    // 0x80082EDC: sltiu       $a2, $v0, 0x1
    ctx->r6 = ctx->r2 < 0X1 ? 1 : 0;
L_80082EE0:
    // 0x80082EE0: addu        $v0, $a2, $zero
    ctx->r2 = ADD32(ctx->r6, 0);
    // 0x80082EE4: beq         $v0, $zero, L_80082F10
    if (ctx->r2 == 0) {
        // 0x80082EE8: addiu       $v1, $a1, -0x1
        ctx->r3 = ADD32(ctx->r5, -0X1);
            goto L_80082F10;
    }
    // 0x80082EE8: addiu       $v1, $a1, -0x1
    ctx->r3 = ADD32(ctx->r5, -0X1);
    // 0x80082EEC: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x80082EF0: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80082EF4: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80082EF8: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x80082EFC: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80082F00: lw          $v1, -0x5664($at)
    ctx->r3 = MEM_W(ctx->r1, -0X5664);
    // 0x80082F04: sll         $v0, $a0, 4
    ctx->r2 = S32(ctx->r4 << 4);
    // 0x80082F08: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80082F0C: sb          $zero, 0x8($v0)
    MEM_B(0X8, ctx->r2) = 0;
L_80082F10:
    // 0x80082F10: jr          $ra
    // 0x80082F14: nop

    return;
    // 0x80082F14: nop

;}
RECOMP_FUNC void func_80082F18(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80082F18: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80082F1C: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // 0x80082F20: srl         $a3, $a0, 16
    ctx->r7 = S32(U32(ctx->r4) >> 16);
    // 0x80082F24: mtc1        $a1, $f2
    ctx->f2.u32l = ctx->r5;
    // 0x80082F28: andi        $a1, $a0, 0xFFFF
    ctx->r5 = ctx->r4 & 0XFFFF;
    // 0x80082F2C: sltu        $v0, $zero, $a3
    ctx->r2 = 0 < ctx->r7 ? 1 : 0;
    // 0x80082F30: sltiu       $v1, $a3, 0x21
    ctx->r3 = ctx->r7 < 0X21 ? 1 : 0;
    // 0x80082F34: and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // 0x80082F38: beq         $v0, $zero, L_80082F64
    if (ctx->r2 == 0) {
        // 0x80082F3C: sw          $ra, 0x10($sp)
        MEM_W(0X10, ctx->r29) = ctx->r31;
            goto L_80082F64;
    }
    // 0x80082F3C: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x80082F40: addiu       $v0, $a3, -0x1
    ctx->r2 = ADD32(ctx->r7, -0X1);
    // 0x80082F44: sll         $v1, $v0, 2
    ctx->r3 = S32(ctx->r2 << 2);
    // 0x80082F48: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x80082F4C: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x80082F50: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x80082F54: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x80082F58: lbu         $v0, -0x5660($at)
    ctx->r2 = MEM_BU(ctx->r1, -0X5660);
    // 0x80082F5C: xori        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 ^ 0X1;
    // 0x80082F60: sltiu       $a2, $v0, 0x1
    ctx->r6 = ctx->r2 < 0X1 ? 1 : 0;
L_80082F64:
    // 0x80082F64: addu        $v0, $a2, $zero
    ctx->r2 = ADD32(ctx->r6, 0);
    // 0x80082F68: beq         $v0, $zero, L_80082FF8
    if (ctx->r2 == 0) {
        // 0x80082F6C: nop
    
            goto L_80082FF8;
    }
    // 0x80082F6C: nop

    // 0x80082F70: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80082F74: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x80082F78: nop

    // 0x80082F7C: bc1tl       L_80082FC0
    if (c1cs) {
        // 0x80082F80: mov.s       $f2, $f0
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
            goto L_80082FC0;
    }
    goto skip_0;
    // 0x80082F80: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
    skip_0:
    // 0x80082F84: addiu       $v1, $a3, -0x1
    ctx->r3 = ADD32(ctx->r7, -0X1);
    // 0x80082F88: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x80082F8C: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80082F90: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80082F94: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x80082F98: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80082F9C: lw          $v1, -0x5664($at)
    ctx->r3 = MEM_W(ctx->r1, -0X5664);
    // 0x80082FA0: sll         $v0, $a1, 4
    ctx->r2 = S32(ctx->r5 << 4);
    // 0x80082FA4: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80082FA8: lwc1        $f0, 0x4($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X4);
    // 0x80082FAC: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x80082FB0: nop

    // 0x80082FB4: bc1f        L_80082FC4
    if (!c1cs) {
        // 0x80082FB8: addiu       $v1, $a3, -0x1
        ctx->r3 = ADD32(ctx->r7, -0X1);
            goto L_80082FC4;
    }
    // 0x80082FB8: addiu       $v1, $a3, -0x1
    ctx->r3 = ADD32(ctx->r7, -0X1);
    // 0x80082FBC: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
L_80082FC0:
    // 0x80082FC0: addiu       $v1, $a3, -0x1
    ctx->r3 = ADD32(ctx->r7, -0X1);
L_80082FC4:
    // 0x80082FC4: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x80082FC8: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80082FCC: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80082FD0: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x80082FD4: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80082FD8: lw          $v1, -0x5664($at)
    ctx->r3 = MEM_W(ctx->r1, -0X5664);
    // 0x80082FDC: sll         $v0, $a1, 4
    ctx->r2 = S32(ctx->r5 << 4);
    // 0x80082FE0: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80082FE4: lwc1        $f0, 0x4($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X4);
    // 0x80082FE8: div.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = DIV_S(ctx->f2.fl, ctx->f0.fl);
    // 0x80082FEC: mfc1        $a2, $f2
    ctx->r6 = (int32_t)ctx->f2.u32l;
    // 0x80082FF0: jal         0x800826A0
    // 0x80082FF4: addu        $a0, $a3, $zero
    ctx->r4 = ADD32(ctx->r7, 0);
    func_800826A0(rdram, ctx);
        goto after_0;
    // 0x80082FF4: addu        $a0, $a3, $zero
    ctx->r4 = ADD32(ctx->r7, 0);
    after_0:
L_80082FF8:
    // 0x80082FF8: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x80082FFC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80083000: jr          $ra
    // 0x80083004: nop

    return;
    // 0x80083004: nop

;}
RECOMP_FUNC void func_80083008(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083008: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8008300C: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x80083010: addu        $s3, $a0, $zero
    ctx->r19 = ADD32(ctx->r4, 0);
    // 0x80083014: sltu        $v0, $zero, $s3
    ctx->r2 = 0 < ctx->r19 ? 1 : 0;
    // 0x80083018: sltiu       $v1, $s3, 0x21
    ctx->r3 = ctx->r19 < 0X21 ? 1 : 0;
    // 0x8008301C: sdc1        $f20, 0x30($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X30, ctx->r29);
    // 0x80083020: mtc1        $a1, $f20
    ctx->f20.u32l = ctx->r5;
    // 0x80083024: and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // 0x80083028: sw          $ra, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r31;
    // 0x8008302C: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80083030: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80083034: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80083038: sdc1        $f22, 0x38($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X38, ctx->r29);
    // 0x8008303C: beq         $v0, $zero, L_80083068
    if (ctx->r2 == 0) {
        // 0x80083040: addu        $a0, $zero, $zero
        ctx->r4 = ADD32(0, 0);
            goto L_80083068;
    }
    // 0x80083040: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x80083044: addiu       $v0, $s3, -0x1
    ctx->r2 = ADD32(ctx->r19, -0X1);
    // 0x80083048: sll         $v1, $v0, 2
    ctx->r3 = S32(ctx->r2 << 2);
    // 0x8008304C: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x80083050: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x80083054: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x80083058: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x8008305C: lbu         $v0, -0x5660($at)
    ctx->r2 = MEM_BU(ctx->r1, -0X5660);
    // 0x80083060: xori        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 ^ 0X1;
    // 0x80083064: sltiu       $a0, $v0, 0x1
    ctx->r4 = ctx->r2 < 0X1 ? 1 : 0;
L_80083068:
    // 0x80083068: addu        $v0, $a0, $zero
    ctx->r2 = ADD32(ctx->r4, 0);
    // 0x8008306C: beq         $v0, $zero, L_8008312C
    if (ctx->r2 == 0) {
        // 0x80083070: addiu       $v1, $s3, -0x1
        ctx->r3 = ADD32(ctx->r19, -0X1);
            goto L_8008312C;
    }
    // 0x80083070: addiu       $v1, $s3, -0x1
    ctx->r3 = ADD32(ctx->r19, -0X1);
    // 0x80083074: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x80083078: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8008307C: sll         $v1, $v0, 2
    ctx->r3 = S32(ctx->r2 << 2);
    // 0x80083080: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x80083084: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x80083088: lw          $v0, -0x5668($at)
    ctx->r2 = MEM_W(ctx->r1, -0X5668);
    // 0x8008308C: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x80083090: beq         $v0, $zero, L_8008312C
    if (ctx->r2 == 0) {
        // 0x80083094: addu        $s1, $zero, $zero
        ctx->r17 = ADD32(0, 0);
            goto L_8008312C;
    }
    // 0x80083094: addu        $s1, $zero, $zero
    ctx->r17 = ADD32(0, 0);
    // 0x80083098: mtc1        $zero, $f22
    ctx->f22.u32l = 0;
    // 0x8008309C: addu        $s2, $v1, $zero
    ctx->r18 = ADD32(ctx->r3, 0);
    // 0x800830A0: addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
L_800830A4:
    // 0x800830A4: c.lt.s      $f20, $f22
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 22);
    c1cs = ctx->f20.fl < ctx->f22.fl;
    // 0x800830A8: nop

    // 0x800830AC: bc1f        L_800830BC
    if (!c1cs) {
        // 0x800830B0: nop
    
            goto L_800830BC;
    }
    // 0x800830B0: nop

    // 0x800830B4: j           L_800830E4
    // 0x800830B8: mov.s       $f2, $f22
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 22);
    ctx->f2.fl = ctx->f22.fl;
        goto L_800830E4;
    // 0x800830B8: mov.s       $f2, $f22
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 22);
    ctx->f2.fl = ctx->f22.fl;
L_800830BC:
    // 0x800830BC: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x800830C0: addu        $at, $at, $s2
    ctx->r1 = ADD32(ctx->r1, ctx->r18);
    // 0x800830C4: lw          $v0, -0x5664($at)
    ctx->r2 = MEM_W(ctx->r1, -0X5664);
    // 0x800830C8: addu        $v0, $s0, $v0
    ctx->r2 = ADD32(ctx->r16, ctx->r2);
    // 0x800830CC: lwc1        $f0, 0x4($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X4);
    // 0x800830D0: c.lt.s      $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f0.fl < ctx->f20.fl;
    // 0x800830D4: nop

    // 0x800830D8: bc1f        L_800830E4
    if (!c1cs) {
        // 0x800830DC: mov.s       $f2, $f20
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    ctx->f2.fl = ctx->f20.fl;
            goto L_800830E4;
    }
    // 0x800830DC: mov.s       $f2, $f20
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    ctx->f2.fl = ctx->f20.fl;
    // 0x800830E0: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
L_800830E4:
    // 0x800830E4: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x800830E8: addu        $at, $at, $s2
    ctx->r1 = ADD32(ctx->r1, ctx->r18);
    // 0x800830EC: lw          $v0, -0x5664($at)
    ctx->r2 = MEM_W(ctx->r1, -0X5664);
    // 0x800830F0: addu        $v0, $s0, $v0
    ctx->r2 = ADD32(ctx->r16, ctx->r2);
    // 0x800830F4: lwc1        $f0, 0x4($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X4);
    // 0x800830F8: div.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = DIV_S(ctx->f2.fl, ctx->f0.fl);
    // 0x800830FC: addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    // 0x80083100: mfc1        $a2, $f2
    ctx->r6 = (int32_t)ctx->f2.u32l;
    // 0x80083104: jal         0x800826A0
    // 0x80083108: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    func_800826A0(rdram, ctx);
        goto after_0;
    // 0x80083108: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    after_0:
    // 0x8008310C: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x80083110: addu        $at, $at, $s2
    ctx->r1 = ADD32(ctx->r1, ctx->r18);
    // 0x80083114: lw          $v0, -0x5668($at)
    ctx->r2 = MEM_W(ctx->r1, -0X5668);
    // 0x80083118: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x8008311C: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80083120: sltu        $v0, $s1, $v0
    ctx->r2 = ctx->r17 < ctx->r2 ? 1 : 0;
    // 0x80083124: bne         $v0, $zero, L_800830A4
    if (ctx->r2 != 0) {
        // 0x80083128: addiu       $s0, $s0, 0x10
        ctx->r16 = ADD32(ctx->r16, 0X10);
            goto L_800830A4;
    }
    // 0x80083128: addiu       $s0, $s0, 0x10
    ctx->r16 = ADD32(ctx->r16, 0X10);
L_8008312C:
    // 0x8008312C: lw          $ra, 0x28($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X28);
    // 0x80083130: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x80083134: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80083138: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8008313C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80083140: ldc1        $f22, 0x38($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X38);
    // 0x80083144: ldc1        $f20, 0x30($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X30);
    // 0x80083148: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x8008314C: jr          $ra
    // 0x80083150: nop

    return;
    // 0x80083150: nop

;}
RECOMP_FUNC void func_80083154(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083154: mtc1        $a1, $f0
    ctx->f0.u32l = ctx->r5;
    // 0x80083158: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // 0x8008315C: srl         $a1, $a0, 16
    ctx->r5 = S32(U32(ctx->r4) >> 16);
    // 0x80083160: sltu        $v0, $zero, $a1
    ctx->r2 = 0 < ctx->r5 ? 1 : 0;
    // 0x80083164: sltiu       $v1, $a1, 0x21
    ctx->r3 = ctx->r5 < 0X21 ? 1 : 0;
    // 0x80083168: and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // 0x8008316C: beq         $v0, $zero, L_80083198
    if (ctx->r2 == 0) {
        // 0x80083170: andi        $a0, $a0, 0xFFFF
        ctx->r4 = ctx->r4 & 0XFFFF;
            goto L_80083198;
    }
    // 0x80083170: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    // 0x80083174: addiu       $v0, $a1, -0x1
    ctx->r2 = ADD32(ctx->r5, -0X1);
    // 0x80083178: sll         $v1, $v0, 2
    ctx->r3 = S32(ctx->r2 << 2);
    // 0x8008317C: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x80083180: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x80083184: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x80083188: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x8008318C: lbu         $v0, -0x5660($at)
    ctx->r2 = MEM_BU(ctx->r1, -0X5660);
    // 0x80083190: xori        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 ^ 0X1;
    // 0x80083194: sltiu       $a2, $v0, 0x1
    ctx->r6 = ctx->r2 < 0X1 ? 1 : 0;
L_80083198:
    // 0x80083198: addu        $v0, $a2, $zero
    ctx->r2 = ADD32(ctx->r6, 0);
    // 0x8008319C: beq         $v0, $zero, L_800831C8
    if (ctx->r2 == 0) {
        // 0x800831A0: addiu       $v1, $a1, -0x1
        ctx->r3 = ADD32(ctx->r5, -0X1);
            goto L_800831C8;
    }
    // 0x800831A0: addiu       $v1, $a1, -0x1
    ctx->r3 = ADD32(ctx->r5, -0X1);
    // 0x800831A4: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x800831A8: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800831AC: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800831B0: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x800831B4: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x800831B8: lw          $v1, -0x5664($at)
    ctx->r3 = MEM_W(ctx->r1, -0X5664);
    // 0x800831BC: sll         $v0, $a0, 4
    ctx->r2 = S32(ctx->r4 << 4);
    // 0x800831C0: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800831C4: swc1        $f0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f0.u32l;
L_800831C8:
    // 0x800831C8: jr          $ra
    // 0x800831CC: nop

    return;
    // 0x800831CC: nop

;}
RECOMP_FUNC void func_800831D0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800831D0: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // 0x800831D4: srl         $a1, $a0, 16
    ctx->r5 = S32(U32(ctx->r4) >> 16);
    // 0x800831D8: sltu        $v0, $zero, $a1
    ctx->r2 = 0 < ctx->r5 ? 1 : 0;
    // 0x800831DC: sltiu       $v1, $a1, 0x21
    ctx->r3 = ctx->r5 < 0X21 ? 1 : 0;
    // 0x800831E0: and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // 0x800831E4: beq         $v0, $zero, L_80083210
    if (ctx->r2 == 0) {
        // 0x800831E8: andi        $a0, $a0, 0xFFFF
        ctx->r4 = ctx->r4 & 0XFFFF;
            goto L_80083210;
    }
    // 0x800831E8: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    // 0x800831EC: addiu       $v0, $a1, -0x1
    ctx->r2 = ADD32(ctx->r5, -0X1);
    // 0x800831F0: sll         $v1, $v0, 2
    ctx->r3 = S32(ctx->r2 << 2);
    // 0x800831F4: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x800831F8: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x800831FC: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x80083200: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x80083204: lbu         $v0, -0x5660($at)
    ctx->r2 = MEM_BU(ctx->r1, -0X5660);
    // 0x80083208: xori        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 ^ 0X1;
    // 0x8008320C: sltiu       $a2, $v0, 0x1
    ctx->r6 = ctx->r2 < 0X1 ? 1 : 0;
L_80083210:
    // 0x80083210: addu        $v0, $a2, $zero
    ctx->r2 = ADD32(ctx->r6, 0);
    // 0x80083214: beq         $v0, $zero, L_80083248
    if (ctx->r2 == 0) {
        // 0x80083218: addiu       $v1, $a1, -0x1
        ctx->r3 = ADD32(ctx->r5, -0X1);
            goto L_80083248;
    }
    // 0x80083218: addiu       $v1, $a1, -0x1
    ctx->r3 = ADD32(ctx->r5, -0X1);
    // 0x8008321C: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x80083220: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80083224: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80083228: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x8008322C: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80083230: lw          $v1, -0x5664($at)
    ctx->r3 = MEM_W(ctx->r1, -0X5664);
    // 0x80083234: sll         $v0, $a0, 4
    ctx->r2 = S32(ctx->r4 << 4);
    // 0x80083238: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8008323C: lwc1        $f0, 0x4($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X4);
    // 0x80083240: j           L_80083250
    // 0x80083244: nop

        goto L_80083250;
    // 0x80083244: nop

L_80083248:
    // 0x80083248: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8008324C: lwc1        $f0, -0x24E4($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X24E4);
L_80083250:
    // 0x80083250: jr          $ra
    // 0x80083254: nop

    return;
    // 0x80083254: nop

;}
RECOMP_FUNC void func_80083258(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083258: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x8008325C: mtc1        $a1, $f0
    ctx->f0.u32l = ctx->r5;
    // 0x80083260: sltu        $v0, $zero, $a0
    ctx->r2 = 0 < ctx->r4 ? 1 : 0;
    // 0x80083264: sltiu       $v1, $a0, 0x21
    ctx->r3 = ctx->r4 < 0X21 ? 1 : 0;
    // 0x80083268: and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // 0x8008326C: beq         $v0, $zero, L_80083298
    if (ctx->r2 == 0) {
        // 0x80083270: addu        $a1, $zero, $zero
        ctx->r5 = ADD32(0, 0);
            goto L_80083298;
    }
    // 0x80083270: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x80083274: addiu       $v0, $a0, -0x1
    ctx->r2 = ADD32(ctx->r4, -0X1);
    // 0x80083278: sll         $v1, $v0, 2
    ctx->r3 = S32(ctx->r2 << 2);
    // 0x8008327C: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x80083280: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x80083284: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x80083288: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x8008328C: lbu         $v0, -0x5660($at)
    ctx->r2 = MEM_BU(ctx->r1, -0X5660);
    // 0x80083290: xori        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 ^ 0X1;
    // 0x80083294: sltiu       $a1, $v0, 0x1
    ctx->r5 = ctx->r2 < 0X1 ? 1 : 0;
L_80083298:
    // 0x80083298: addu        $v0, $a1, $zero
    ctx->r2 = ADD32(ctx->r5, 0);
    // 0x8008329C: beq         $v0, $zero, L_8008330C
    if (ctx->r2 == 0) {
        // 0x800832A0: addiu       $a2, $a0, -0x1
        ctx->r6 = ADD32(ctx->r4, -0X1);
            goto L_8008330C;
    }
    // 0x800832A0: addiu       $a2, $a0, -0x1
    ctx->r6 = ADD32(ctx->r4, -0X1);
    // 0x800832A4: sll         $v0, $a2, 2
    ctx->r2 = S32(ctx->r6 << 2);
    // 0x800832A8: addu        $v0, $v0, $a2
    ctx->r2 = ADD32(ctx->r2, ctx->r6);
    // 0x800832AC: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800832B0: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x800832B4: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x800832B8: lw          $v0, -0x5668($at)
    ctx->r2 = MEM_W(ctx->r1, -0X5668);
    // 0x800832BC: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x800832C0: beq         $v0, $zero, L_8008330C
    if (ctx->r2 == 0) {
        // 0x800832C4: addu        $a1, $zero, $zero
        ctx->r5 = ADD32(0, 0);
            goto L_8008330C;
    }
    // 0x800832C4: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x800832C8: sll         $v1, $a2, 2
    ctx->r3 = S32(ctx->r6 << 2);
L_800832CC:
    // 0x800832CC: addu        $v1, $v1, $a2
    ctx->r3 = ADD32(ctx->r3, ctx->r6);
    // 0x800832D0: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x800832D4: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x800832D8: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x800832DC: lw          $a0, -0x5664($at)
    ctx->r4 = MEM_W(ctx->r1, -0X5664);
    // 0x800832E0: sll         $v0, $a1, 4
    ctx->r2 = S32(ctx->r5 << 4);
    // 0x800832E4: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x800832E8: swc1        $f0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f0.u32l;
    // 0x800832EC: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x800832F0: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x800832F4: lw          $v0, -0x5668($at)
    ctx->r2 = MEM_W(ctx->r1, -0X5668);
    // 0x800832F8: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x800832FC: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x80083300: sltu        $v0, $a1, $v0
    ctx->r2 = ctx->r5 < ctx->r2 ? 1 : 0;
    // 0x80083304: bne         $v0, $zero, L_800832CC
    if (ctx->r2 != 0) {
        // 0x80083308: sll         $v1, $a2, 2
        ctx->r3 = S32(ctx->r6 << 2);
            goto L_800832CC;
    }
    // 0x80083308: sll         $v1, $a2, 2
    ctx->r3 = S32(ctx->r6 << 2);
L_8008330C:
    // 0x8008330C: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    // 0x80083310: jr          $ra
    // 0x80083314: nop

    return;
    // 0x80083314: nop

;}
RECOMP_FUNC void func_80083318(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083318: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    // 0x8008331C: srl         $a2, $a0, 16
    ctx->r6 = S32(U32(ctx->r4) >> 16);
    // 0x80083320: sltu        $v0, $zero, $a2
    ctx->r2 = 0 < ctx->r6 ? 1 : 0;
    // 0x80083324: sltiu       $v1, $a2, 0x21
    ctx->r3 = ctx->r6 < 0X21 ? 1 : 0;
    // 0x80083328: and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // 0x8008332C: beq         $v0, $zero, L_80083358
    if (ctx->r2 == 0) {
        // 0x80083330: andi        $a0, $a0, 0xFFFF
        ctx->r4 = ctx->r4 & 0XFFFF;
            goto L_80083358;
    }
    // 0x80083330: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    // 0x80083334: addiu       $v0, $a2, -0x1
    ctx->r2 = ADD32(ctx->r6, -0X1);
    // 0x80083338: sll         $v1, $v0, 2
    ctx->r3 = S32(ctx->r2 << 2);
    // 0x8008333C: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x80083340: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x80083344: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x80083348: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x8008334C: lbu         $v0, -0x5660($at)
    ctx->r2 = MEM_BU(ctx->r1, -0X5660);
    // 0x80083350: xori        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 ^ 0X1;
    // 0x80083354: sltiu       $a3, $v0, 0x1
    ctx->r7 = ctx->r2 < 0X1 ? 1 : 0;
L_80083358:
    // 0x80083358: addu        $v0, $a3, $zero
    ctx->r2 = ADD32(ctx->r7, 0);
    // 0x8008335C: beq         $v0, $zero, L_8008345C
    if (ctx->r2 == 0) {
        // 0x80083360: addiu       $v1, $a2, -0x1
        ctx->r3 = ADD32(ctx->r6, -0X1);
            goto L_8008345C;
    }
    // 0x80083360: addiu       $v1, $a2, -0x1
    ctx->r3 = ADD32(ctx->r6, -0X1);
    // 0x80083364: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x80083368: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8008336C: sll         $a2, $v0, 2
    ctx->r6 = S32(ctx->r2 << 2);
    // 0x80083370: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x80083374: addu        $at, $at, $a2
    ctx->r1 = ADD32(ctx->r1, ctx->r6);
    // 0x80083378: lw          $v0, -0x5668($at)
    ctx->r2 = MEM_W(ctx->r1, -0X5668);
    // 0x8008337C: lw          $v0, 0x4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X4);
    // 0x80083380: sll         $a0, $a0, 4
    ctx->r4 = S32(ctx->r4 << 4);
    // 0x80083384: addu        $v1, $a0, $v0
    ctx->r3 = ADD32(ctx->r4, ctx->r2);
    // 0x80083388: lw          $v0, 0x4($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X4);
    // 0x8008338C: andi        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 & 0X1;
    // 0x80083390: beq         $v0, $zero, L_80083460
    if (ctx->r2 == 0) {
        // 0x80083394: addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
            goto L_80083460;
    }
    // 0x80083394: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // 0x80083398: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x8008339C: addu        $at, $at, $a2
    ctx->r1 = ADD32(ctx->r1, ctx->r6);
    // 0x800833A0: lw          $v0, -0x5664($at)
    ctx->r2 = MEM_W(ctx->r1, -0X5664);
    // 0x800833A4: lh          $v1, 0x8($v1)
    ctx->r3 = MEM_H(ctx->r3, 0X8);
    // 0x800833A8: addu        $v0, $a0, $v0
    ctx->r2 = ADD32(ctx->r4, ctx->r2);
    // 0x800833AC: lwc1        $f2, 0x0($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X0);
    // 0x800833B0: mtc1        $v1, $f0
    ctx->f0.u32l = ctx->r3;
    // 0x800833B4: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x800833B8: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x800833BC: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x800833C0: lwc1        $f4, -0x24E0($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X24E0);
    // 0x800833C4: mul.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x800833C8: swc1        $f0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f0.u32l;
    // 0x800833CC: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x800833D0: addu        $at, $at, $a2
    ctx->r1 = ADD32(ctx->r1, ctx->r6);
    // 0x800833D4: lw          $v0, -0x5668($at)
    ctx->r2 = MEM_W(ctx->r1, -0X5668);
    // 0x800833D8: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x800833DC: addu        $at, $at, $a2
    ctx->r1 = ADD32(ctx->r1, ctx->r6);
    // 0x800833E0: lw          $v1, -0x5664($at)
    ctx->r3 = MEM_W(ctx->r1, -0X5664);
    // 0x800833E4: lw          $v0, 0x4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X4);
    // 0x800833E8: addu        $v1, $a0, $v1
    ctx->r3 = ADD32(ctx->r4, ctx->r3);
    // 0x800833EC: addu        $v0, $a0, $v0
    ctx->r2 = ADD32(ctx->r4, ctx->r2);
    // 0x800833F0: lh          $v0, 0xA($v0)
    ctx->r2 = MEM_H(ctx->r2, 0XA);
    // 0x800833F4: lwc1        $f2, 0x0($v1)
    ctx->f2.u32l = MEM_W(ctx->r3, 0X0);
    // 0x800833F8: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x800833FC: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x80083400: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x80083404: nop

    // 0x80083408: mul.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x8008340C: swc1        $f0, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->f0.u32l;
    // 0x80083410: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x80083414: addu        $at, $at, $a2
    ctx->r1 = ADD32(ctx->r1, ctx->r6);
    // 0x80083418: lw          $v0, -0x5668($at)
    ctx->r2 = MEM_W(ctx->r1, -0X5668);
    // 0x8008341C: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x80083420: addu        $at, $at, $a2
    ctx->r1 = ADD32(ctx->r1, ctx->r6);
    // 0x80083424: lw          $v1, -0x5664($at)
    ctx->r3 = MEM_W(ctx->r1, -0X5664);
    // 0x80083428: lw          $v0, 0x4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X4);
    // 0x8008342C: addu        $v1, $a0, $v1
    ctx->r3 = ADD32(ctx->r4, ctx->r3);
    // 0x80083430: addu        $v0, $a0, $v0
    ctx->r2 = ADD32(ctx->r4, ctx->r2);
    // 0x80083434: lh          $v0, 0xC($v0)
    ctx->r2 = MEM_H(ctx->r2, 0XC);
    // 0x80083438: lwc1        $f2, 0x0($v1)
    ctx->f2.u32l = MEM_W(ctx->r3, 0X0);
    // 0x8008343C: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x80083440: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x80083444: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x80083448: nop

    // 0x8008344C: mul.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x80083450: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80083454: j           L_80083460
    // 0x80083458: swc1        $f0, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->f0.u32l;
        goto L_80083460;
    // 0x80083458: swc1        $f0, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->f0.u32l;
L_8008345C:
    // 0x8008345C: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_80083460:
    // 0x80083460: jr          $ra
    // 0x80083464: nop

    return;
    // 0x80083464: nop

;}
RECOMP_FUNC void parseModelAnimType2Entry(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083468: addiu       $sp, $sp, -0xF8
    ctx->r29 = ADD32(ctx->r29, -0XF8);
    // 0x8008346C: sw          $a0, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r4;
    // 0x80083470: lw          $t0, 0x74($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X74);
    // 0x80083474: sw          $ra, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->r31;
    // 0x80083478: sw          $fp, 0xC0($sp)
    MEM_W(0XC0, ctx->r29) = ctx->r30;
    // 0x8008347C: sw          $s7, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->r23;
    // 0x80083480: sw          $s6, 0xB8($sp)
    MEM_W(0XB8, ctx->r29) = ctx->r22;
    // 0x80083484: sw          $s5, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->r21;
    // 0x80083488: sw          $s4, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->r20;
    // 0x8008348C: sw          $s3, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->r19;
    // 0x80083490: sw          $s2, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->r18;
    // 0x80083494: sw          $s1, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->r17;
    // 0x80083498: sw          $s0, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->r16;
    // 0x8008349C: sdc1        $f30, 0xF0($sp)
    CHECK_FR(ctx, 30);
    SD(ctx->f30.u64, 0XF0, ctx->r29);
    // 0x800834A0: sdc1        $f28, 0xE8($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0XE8, ctx->r29);
    // 0x800834A4: sdc1        $f26, 0xE0($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0XE0, ctx->r29);
    // 0x800834A8: sdc1        $f24, 0xD8($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0XD8, ctx->r29);
    // 0x800834AC: sdc1        $f22, 0xD0($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0XD0, ctx->r29);
    // 0x800834B0: sdc1        $f20, 0xC8($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0XC8, ctx->r29);
    // 0x800834B4: sltu        $v0, $zero, $t0
    ctx->r2 = 0 < ctx->r8 ? 1 : 0;
    // 0x800834B8: sltiu       $v1, $t0, 0x21
    ctx->r3 = ctx->r8 < 0X21 ? 1 : 0;
    // 0x800834BC: and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // 0x800834C0: beq         $v0, $zero, L_800834EC
    if (ctx->r2 == 0) {
        // 0x800834C4: addu        $a0, $zero, $zero
        ctx->r4 = ADD32(0, 0);
            goto L_800834EC;
    }
    // 0x800834C4: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x800834C8: addiu       $v0, $t0, -0x1
    ctx->r2 = ADD32(ctx->r8, -0X1);
    // 0x800834CC: sll         $v1, $v0, 2
    ctx->r3 = S32(ctx->r2 << 2);
    // 0x800834D0: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x800834D4: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x800834D8: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x800834DC: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x800834E0: lbu         $v0, -0x5660($at)
    ctx->r2 = MEM_BU(ctx->r1, -0X5660);
    // 0x800834E4: xori        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 ^ 0X1;
    // 0x800834E8: sltiu       $a0, $v0, 0x1
    ctx->r4 = ctx->r2 < 0X1 ? 1 : 0;
L_800834EC:
    // 0x800834EC: addu        $v0, $a0, $zero
    ctx->r2 = ADD32(ctx->r4, 0);
    // 0x800834F0: beq         $v0, $zero, L_80083BDC
    if (ctx->r2 == 0) {
        // 0x800834F4: nop
    
            goto L_80083BDC;
    }
    // 0x800834F4: nop

    // 0x800834F8: lw          $t0, 0x74($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X74);
    // 0x800834FC: addiu       $a0, $t0, -0x1
    ctx->r4 = ADD32(ctx->r8, -0X1);
    // 0x80083500: sll         $v0, $a0, 2
    ctx->r2 = S32(ctx->r4 << 2);
    // 0x80083504: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x80083508: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8008350C: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x80083510: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80083514: lw          $v0, -0x5668($at)
    ctx->r2 = MEM_W(ctx->r1, -0X5668);
    // 0x80083518: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x8008351C: beq         $v0, $zero, L_80083BDC
    if (ctx->r2 == 0) {
        // 0x80083520: sw          $zero, 0x7C($sp)
        MEM_W(0X7C, ctx->r29) = 0;
            goto L_80083BDC;
    }
    // 0x80083520: sw          $zero, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = 0;
    // 0x80083524: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80083528: lwc1        $f14, -0x24DC($at)
    ctx->f14.u32l = MEM_W(ctx->r1, -0X24DC);
    // 0x8008352C: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80083530: lwc1        $f24, -0x24D8($at)
    ctx->f24.u32l = MEM_W(ctx->r1, -0X24D8);
    // 0x80083534: addu        $s7, $zero, $zero
    ctx->r23 = ADD32(0, 0);
L_80083538:
    // 0x80083538: sll         $v0, $a0, 2
    ctx->r2 = S32(ctx->r4 << 2);
    // 0x8008353C: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x80083540: sll         $a2, $v0, 2
    ctx->r6 = S32(ctx->r2 << 2);
    // 0x80083544: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x80083548: addu        $at, $at, $a2
    ctx->r1 = ADD32(ctx->r1, ctx->r6);
    // 0x8008354C: lw          $v0, -0x5664($at)
    ctx->r2 = MEM_W(ctx->r1, -0X5664);
    // 0x80083550: addu        $v0, $s7, $v0
    ctx->r2 = ADD32(ctx->r23, ctx->r2);
    // 0x80083554: lbu         $v1, 0x8($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X8);
    // 0x80083558: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8008355C: bne         $v1, $v0, L_80083BA0
    if (ctx->r3 != ctx->r2) {
        // 0x80083560: addu        $a1, $a0, $zero
        ctx->r5 = ADD32(ctx->r4, 0);
            goto L_80083BA0;
    }
    // 0x80083560: addu        $a1, $a0, $zero
    ctx->r5 = ADD32(ctx->r4, 0);
    // 0x80083564: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x80083568: addu        $at, $at, $a2
    ctx->r1 = ADD32(ctx->r1, ctx->r6);
    // 0x8008356C: lw          $v0, -0x5668($at)
    ctx->r2 = MEM_W(ctx->r1, -0X5668);
    // 0x80083570: lw          $v0, 0x4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X4);
    // 0x80083574: addu        $v0, $s7, $v0
    ctx->r2 = ADD32(ctx->r23, ctx->r2);
    // 0x80083578: lhu         $v0, 0xE($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0XE);
    // 0x8008357C: beq         $v0, $zero, L_80083BA0
    if (ctx->r2 == 0) {
        // 0x80083580: addu        $s5, $zero, $zero
        ctx->r21 = ADD32(0, 0);
            goto L_80083BA0;
    }
    // 0x80083580: addu        $s5, $zero, $zero
    ctx->r21 = ADD32(0, 0);
    // 0x80083584: addu        $fp, $zero, $zero
    ctx->r30 = ADD32(0, 0);
L_80083588:
    // 0x80083588: sll         $a0, $a1, 2
    ctx->r4 = S32(ctx->r5 << 2);
    // 0x8008358C: addu        $a0, $a0, $a1
    ctx->r4 = ADD32(ctx->r4, ctx->r5);
    // 0x80083590: sll         $a0, $a0, 2
    ctx->r4 = S32(ctx->r4 << 2);
    // 0x80083594: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x80083598: addu        $at, $at, $a0
    ctx->r1 = ADD32(ctx->r1, ctx->r4);
    // 0x8008359C: lw          $v0, -0x5668($at)
    ctx->r2 = MEM_W(ctx->r1, -0X5668);
    // 0x800835A0: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x800835A4: addu        $at, $at, $a0
    ctx->r1 = ADD32(ctx->r1, ctx->r4);
    // 0x800835A8: lw          $v1, -0x5664($at)
    ctx->r3 = MEM_W(ctx->r1, -0X5664);
    // 0x800835AC: sll         $a2, $s5, 3
    ctx->r6 = S32(ctx->r21 << 3);
    // 0x800835B0: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x800835B4: lwc1        $f0, -0x24D4($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X24D4);
    // 0x800835B8: lw          $v0, 0x4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X4);
    // 0x800835BC: addu        $v1, $s7, $v1
    ctx->r3 = ADD32(ctx->r23, ctx->r3);
    // 0x800835C0: lw          $a1, 0xC($v1)
    ctx->r5 = MEM_W(ctx->r3, 0XC);
    // 0x800835C4: sll         $v1, $s5, 2
    ctx->r3 = S32(ctx->r21 << 2);
    // 0x800835C8: addu        $v0, $s7, $v0
    ctx->r2 = ADD32(ctx->r23, ctx->r2);
    // 0x800835CC: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x800835D0: addu        $a1, $a1, $a2
    ctx->r5 = ADD32(ctx->r5, ctx->r6);
    // 0x800835D4: lwc1        $f20, 0x4($a1)
    ctx->f20.u32l = MEM_W(ctx->r5, 0X4);
    // 0x800835D8: addu        $s1, $v0, $fp
    ctx->r17 = ADD32(ctx->r2, ctx->r30);
    // 0x800835DC: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x800835E0: addu        $at, $at, $a0
    ctx->r1 = ADD32(ctx->r1, ctx->r4);
    // 0x800835E4: lw          $v0, -0x5670($at)
    ctx->r2 = MEM_W(ctx->r1, -0X5670);
    // 0x800835E8: lw          $s3, 0x0($a1)
    ctx->r19 = MEM_W(ctx->r5, 0X0);
    // 0x800835EC: sub.s       $f22, $f0, $f20
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f22.fl = ctx->f0.fl - ctx->f20.fl;
    // 0x800835F0: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x800835F4: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x800835F8: lw          $s2, 0x0($v1)
    ctx->r18 = MEM_W(ctx->r3, 0X0);
    // 0x800835FC: lw          $v1, 0x4($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X4);
    // 0x80083600: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x80083604: xor         $v0, $s3, $v0
    ctx->r2 = ctx->r19 ^ ctx->r2;
    // 0x80083608: sltu        $v0, $zero, $v0
    ctx->r2 = 0 < ctx->r2 ? 1 : 0;
    // 0x8008360C: andi        $v1, $v1, 0x1
    ctx->r3 = ctx->r3 & 0X1;
    // 0x80083610: beq         $v1, $zero, L_800836B8
    if (ctx->r3 == 0) {
        // 0x80083614: addu        $s4, $s3, $v0
        ctx->r20 = ADD32(ctx->r19, ctx->r2);
            goto L_800836B8;
    }
    // 0x80083614: addu        $s4, $s3, $v0
    ctx->r20 = ADD32(ctx->r19, ctx->r2);
    // 0x80083618: lw          $a1, 0xC($s1)
    ctx->r5 = MEM_W(ctx->r17, 0XC);
    // 0x8008361C: sll         $a0, $s3, 1
    ctx->r4 = S32(ctx->r19 << 1);
    // 0x80083620: addu        $a0, $a0, $s3
    ctx->r4 = ADD32(ctx->r4, ctx->r19);
    // 0x80083624: sll         $a0, $a0, 1
    ctx->r4 = S32(ctx->r4 << 1);
    // 0x80083628: addu        $a0, $a0, $a1
    ctx->r4 = ADD32(ctx->r4, ctx->r5);
    // 0x8008362C: lh          $v0, 0x0($a0)
    ctx->r2 = MEM_H(ctx->r4, 0X0);
    // 0x80083630: sll         $v1, $s4, 1
    ctx->r3 = S32(ctx->r20 << 1);
    // 0x80083634: addu        $v1, $v1, $s4
    ctx->r3 = ADD32(ctx->r3, ctx->r20);
    // 0x80083638: mtc1        $v0, $f2
    ctx->f2.u32l = ctx->r2;
    // 0x8008363C: cvt.s.w     $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    ctx->f2.fl = CVT_S_W(ctx->f2.u32l);
    // 0x80083640: mul.s       $f2, $f22, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = MUL_S(ctx->f22.fl, ctx->f2.fl);
    // 0x80083644: sll         $v1, $v1, 1
    ctx->r3 = S32(ctx->r3 << 1);
    // 0x80083648: addu        $v1, $v1, $a1
    ctx->r3 = ADD32(ctx->r3, ctx->r5);
    // 0x8008364C: lh          $v0, 0x0($v1)
    ctx->r2 = MEM_H(ctx->r3, 0X0);
    // 0x80083650: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x80083654: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x80083658: mul.s       $f0, $f20, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = MUL_S(ctx->f20.fl, ctx->f0.fl);
    // 0x8008365C: lh          $v0, 0x2($a0)
    ctx->r2 = MEM_H(ctx->r4, 0X2);
    // 0x80083660: mtc1        $v0, $f4
    ctx->f4.u32l = ctx->r2;
    // 0x80083664: cvt.s.w     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80083668: mul.s       $f4, $f22, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f4.fl = MUL_S(ctx->f22.fl, ctx->f4.fl);
    // 0x8008366C: lh          $v0, 0x2($v1)
    ctx->r2 = MEM_H(ctx->r3, 0X2);
    // 0x80083670: mtc1        $v0, $f6
    ctx->f6.u32l = ctx->r2;
    // 0x80083674: cvt.s.w     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80083678: mul.s       $f6, $f20, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f6.fl = MUL_S(ctx->f20.fl, ctx->f6.fl);
    // 0x8008367C: lh          $v0, 0x4($a0)
    ctx->r2 = MEM_H(ctx->r4, 0X4);
    // 0x80083680: add.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x80083684: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x80083688: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x8008368C: mul.s       $f0, $f22, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = MUL_S(ctx->f22.fl, ctx->f0.fl);
    // 0x80083690: nop

    // 0x80083694: mul.s       $f30, $f2, $f14
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f30.fl = MUL_S(ctx->f2.fl, ctx->f14.fl);
    // 0x80083698: lh          $v0, 0x4($v1)
    ctx->r2 = MEM_H(ctx->r3, 0X4);
    // 0x8008369C: mtc1        $v0, $f2
    ctx->f2.u32l = ctx->r2;
    // 0x800836A0: cvt.s.w     $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    ctx->f2.fl = CVT_S_W(ctx->f2.u32l);
    // 0x800836A4: mul.s       $f2, $f20, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = MUL_S(ctx->f20.fl, ctx->f2.fl);
    // 0x800836A8: add.s       $f4, $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x800836AC: mul.s       $f26, $f4, $f14
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f26.fl = MUL_S(ctx->f4.fl, ctx->f14.fl);
    // 0x800836B0: j           L_800836E8
    // 0x800836B4: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
        goto L_800836E8;
    // 0x800836B4: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
L_800836B8:
    // 0x800836B8: lw          $v1, 0xC($s1)
    ctx->r3 = MEM_W(ctx->r17, 0XC);
    // 0x800836BC: lh          $v0, 0x0($v1)
    ctx->r2 = MEM_H(ctx->r3, 0X0);
    // 0x800836C0: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x800836C4: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x800836C8: mul.s       $f30, $f0, $f14
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f30.fl = MUL_S(ctx->f0.fl, ctx->f14.fl);
    // 0x800836CC: lh          $v0, 0x2($v1)
    ctx->r2 = MEM_H(ctx->r3, 0X2);
    // 0x800836D0: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x800836D4: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x800836D8: mul.s       $f26, $f0, $f14
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f26.fl = MUL_S(ctx->f0.fl, ctx->f14.fl);
    // 0x800836DC: lh          $v0, 0x4($v1)
    ctx->r2 = MEM_H(ctx->r3, 0X4);
    // 0x800836E0: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x800836E4: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
L_800836E8:
    // 0x800836E8: lw          $v0, 0x4($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X4);
    // 0x800836EC: andi        $v0, $v0, 0x2
    ctx->r2 = ctx->r2 & 0X2;
    // 0x800836F0: mul.s       $f28, $f0, $f14
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f28.fl = MUL_S(ctx->f0.fl, ctx->f14.fl);
    // 0x800836F4: beq         $v0, $zero, L_8008379C
    if (ctx->r2 == 0) {
        // 0x800836F8: nop
    
            goto L_8008379C;
    }
    // 0x800836F8: nop

    // 0x800836FC: lw          $a1, 0x10($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X10);
    // 0x80083700: sll         $a0, $s3, 1
    ctx->r4 = S32(ctx->r19 << 1);
    // 0x80083704: addu        $a0, $a0, $s3
    ctx->r4 = ADD32(ctx->r4, ctx->r19);
    // 0x80083708: sll         $a0, $a0, 1
    ctx->r4 = S32(ctx->r4 << 1);
    // 0x8008370C: addu        $a0, $a0, $a1
    ctx->r4 = ADD32(ctx->r4, ctx->r5);
    // 0x80083710: lh          $v0, 0x0($a0)
    ctx->r2 = MEM_H(ctx->r4, 0X0);
    // 0x80083714: sll         $v1, $s4, 1
    ctx->r3 = S32(ctx->r20 << 1);
    // 0x80083718: addu        $v1, $v1, $s4
    ctx->r3 = ADD32(ctx->r3, ctx->r20);
    // 0x8008371C: mtc1        $v0, $f2
    ctx->f2.u32l = ctx->r2;
    // 0x80083720: cvt.s.w     $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    ctx->f2.fl = CVT_S_W(ctx->f2.u32l);
    // 0x80083724: mul.s       $f2, $f22, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = MUL_S(ctx->f22.fl, ctx->f2.fl);
    // 0x80083728: sll         $v1, $v1, 1
    ctx->r3 = S32(ctx->r3 << 1);
    // 0x8008372C: addu        $v1, $v1, $a1
    ctx->r3 = ADD32(ctx->r3, ctx->r5);
    // 0x80083730: lh          $v0, 0x0($v1)
    ctx->r2 = MEM_H(ctx->r3, 0X0);
    // 0x80083734: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x80083738: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x8008373C: mul.s       $f0, $f20, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = MUL_S(ctx->f20.fl, ctx->f0.fl);
    // 0x80083740: lh          $v0, 0x2($a0)
    ctx->r2 = MEM_H(ctx->r4, 0X2);
    // 0x80083744: mtc1        $v0, $f4
    ctx->f4.u32l = ctx->r2;
    // 0x80083748: cvt.s.w     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8008374C: mul.s       $f4, $f22, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f4.fl = MUL_S(ctx->f22.fl, ctx->f4.fl);
    // 0x80083750: lh          $v0, 0x2($v1)
    ctx->r2 = MEM_H(ctx->r3, 0X2);
    // 0x80083754: mtc1        $v0, $f6
    ctx->f6.u32l = ctx->r2;
    // 0x80083758: cvt.s.w     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8008375C: mul.s       $f6, $f20, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f6.fl = MUL_S(ctx->f20.fl, ctx->f6.fl);
    // 0x80083760: add.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x80083764: mul.s       $f2, $f2, $f24
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f24.fl);
    // 0x80083768: lh          $v0, 0x4($a0)
    ctx->r2 = MEM_H(ctx->r4, 0X4);
    // 0x8008376C: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x80083770: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x80083774: mul.s       $f0, $f22, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = MUL_S(ctx->f22.fl, ctx->f0.fl);
    // 0x80083778: lh          $v0, 0x4($v1)
    ctx->r2 = MEM_H(ctx->r3, 0X4);
    // 0x8008377C: mfc1        $s6, $f2
    ctx->r22 = (int32_t)ctx->f2.u32l;
    // 0x80083780: mtc1        $v0, $f2
    ctx->f2.u32l = ctx->r2;
    // 0x80083784: cvt.s.w     $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    ctx->f2.fl = CVT_S_W(ctx->f2.u32l);
    // 0x80083788: mul.s       $f2, $f20, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = MUL_S(ctx->f20.fl, ctx->f2.fl);
    // 0x8008378C: add.s       $f4, $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80083790: mul.s       $f16, $f4, $f24
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f16.fl = MUL_S(ctx->f4.fl, ctx->f24.fl);
    // 0x80083794: j           L_800837D0
    // 0x80083798: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
        goto L_800837D0;
    // 0x80083798: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
L_8008379C:
    // 0x8008379C: lw          $v1, 0x10($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X10);
    // 0x800837A0: lh          $v0, 0x0($v1)
    ctx->r2 = MEM_H(ctx->r3, 0X0);
    // 0x800837A4: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x800837A8: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x800837AC: mul.s       $f0, $f0, $f24
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f24.fl);
    // 0x800837B0: lh          $v0, 0x2($v1)
    ctx->r2 = MEM_H(ctx->r3, 0X2);
    // 0x800837B4: mfc1        $s6, $f0
    ctx->r22 = (int32_t)ctx->f0.u32l;
    // 0x800837B8: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x800837BC: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x800837C0: mul.s       $f16, $f0, $f24
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f24.fl);
    // 0x800837C4: lh          $v0, 0x4($v1)
    ctx->r2 = MEM_H(ctx->r3, 0X4);
    // 0x800837C8: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x800837CC: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
L_800837D0:
    // 0x800837D0: lw          $v0, 0x4($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X4);
    // 0x800837D4: andi        $v0, $v0, 0x4
    ctx->r2 = ctx->r2 & 0X4;
    // 0x800837D8: mul.s       $f18, $f0, $f24
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f24.fl);
    // 0x800837DC: beq         $v0, $zero, L_80083910
    if (ctx->r2 == 0) {
        // 0x800837E0: nop
    
            goto L_80083910;
    }
    // 0x800837E0: nop

    // 0x800837E4: lw          $v0, 0x14($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X14);
    // 0x800837E8: sll         $v1, $s3, 3
    ctx->r3 = S32(ctx->r19 << 3);
    // 0x800837EC: addu        $v0, $v1, $v0
    ctx->r2 = ADD32(ctx->r3, ctx->r2);
    // 0x800837F0: lh          $v0, 0x0($v0)
    ctx->r2 = MEM_H(ctx->r2, 0X0);
    // 0x800837F4: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x800837F8: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x800837FC: mul.s       $f0, $f0, $f24
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f24.fl);
    // 0x80083800: swc1        $f0, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f0.u32l;
    // 0x80083804: lw          $v0, 0x14($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X14);
    // 0x80083808: addu        $v0, $v1, $v0
    ctx->r2 = ADD32(ctx->r3, ctx->r2);
    // 0x8008380C: lh          $v0, 0x2($v0)
    ctx->r2 = MEM_H(ctx->r2, 0X2);
    // 0x80083810: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x80083814: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x80083818: mul.s       $f0, $f0, $f24
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f24.fl);
    // 0x8008381C: swc1        $f0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f0.u32l;
    // 0x80083820: lw          $v0, 0x14($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X14);
    // 0x80083824: addu        $v0, $v1, $v0
    ctx->r2 = ADD32(ctx->r3, ctx->r2);
    // 0x80083828: lh          $v0, 0x4($v0)
    ctx->r2 = MEM_H(ctx->r2, 0X4);
    // 0x8008382C: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x80083830: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x80083834: mul.s       $f0, $f0, $f24
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f24.fl);
    // 0x80083838: swc1        $f0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f0.u32l;
    // 0x8008383C: lw          $v0, 0x14($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X14);
    // 0x80083840: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x80083844: lh          $v0, 0x6($v1)
    ctx->r2 = MEM_H(ctx->r3, 0X6);
    // 0x80083848: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x8008384C: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x80083850: mul.s       $f0, $f0, $f24
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f24.fl);
    // 0x80083854: swc1        $f0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f0.u32l;
    // 0x80083858: lw          $v0, 0x14($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X14);
    // 0x8008385C: sll         $v1, $s4, 3
    ctx->r3 = S32(ctx->r20 << 3);
    // 0x80083860: addu        $v0, $v1, $v0
    ctx->r2 = ADD32(ctx->r3, ctx->r2);
    // 0x80083864: lh          $v0, 0x0($v0)
    ctx->r2 = MEM_H(ctx->r2, 0X0);
    // 0x80083868: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x8008386C: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x80083870: mul.s       $f0, $f0, $f24
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f24.fl);
    // 0x80083874: swc1        $f0, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f0.u32l;
    // 0x80083878: lw          $v0, 0x14($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X14);
    // 0x8008387C: addu        $v0, $v1, $v0
    ctx->r2 = ADD32(ctx->r3, ctx->r2);
    // 0x80083880: lh          $v0, 0x2($v0)
    ctx->r2 = MEM_H(ctx->r2, 0X2);
    // 0x80083884: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x80083888: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x8008388C: mul.s       $f0, $f0, $f24
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f24.fl);
    // 0x80083890: swc1        $f0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f0.u32l;
    // 0x80083894: lw          $v0, 0x14($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X14);
    // 0x80083898: addu        $v0, $v1, $v0
    ctx->r2 = ADD32(ctx->r3, ctx->r2);
    // 0x8008389C: lh          $v0, 0x4($v0)
    ctx->r2 = MEM_H(ctx->r2, 0X4);
    // 0x800838A0: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x800838A4: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x800838A8: mul.s       $f0, $f0, $f24
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f24.fl);
    // 0x800838AC: swc1        $f0, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->f0.u32l;
    // 0x800838B0: lw          $v0, 0x14($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X14);
    // 0x800838B4: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x800838B8: lh          $v0, 0x6($v1)
    ctx->r2 = MEM_H(ctx->r3, 0X6);
    // 0x800838BC: addiu       $a0, $sp, 0x50
    ctx->r4 = ADD32(ctx->r29, 0X50);
    // 0x800838C0: addiu       $a1, $sp, 0x60
    ctx->r5 = ADD32(ctx->r29, 0X60);
    // 0x800838C4: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x800838C8: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x800838CC: mul.s       $f0, $f0, $f24
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f24.fl);
    // 0x800838D0: addiu       $s0, $sp, 0x40
    ctx->r16 = ADD32(ctx->r29, 0X40);
    // 0x800838D4: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x800838D8: addu        $a3, $s0, $zero
    ctx->r7 = ADD32(ctx->r16, 0);
    // 0x800838DC: swc1        $f14, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->f14.u32l;
    // 0x800838E0: swc1        $f16, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->f16.u32l;
    // 0x800838E4: swc1        $f18, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->f18.u32l;
    // 0x800838E8: jal         0x8001D850
    // 0x800838EC: swc1        $f0, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f0.u32l;
    func_8001D850(rdram, ctx);
        goto after_0;
    // 0x800838EC: swc1        $f0, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f0.u32l;
    after_0:
    // 0x800838F0: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x800838F4: jal         0x8001D548
    // 0x800838F8: addiu       $a1, $sp, 0x10
    ctx->r5 = ADD32(ctx->r29, 0X10);
    func_8001D548(rdram, ctx);
        goto after_1;
    // 0x800838F8: addiu       $a1, $sp, 0x10
    ctx->r5 = ADD32(ctx->r29, 0X10);
    after_1:
    // 0x800838FC: lwc1        $f14, 0x90($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X90);
    // 0x80083900: lwc1        $f16, 0x94($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X94);
    // 0x80083904: lwc1        $f18, 0x98($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X98);
    // 0x80083908: j           L_80083994
    // 0x8008390C: nop

        goto L_80083994;
    // 0x8008390C: nop

L_80083910:
    // 0x80083910: lw          $v0, 0x14($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X14);
    // 0x80083914: lh          $v0, 0x0($v0)
    ctx->r2 = MEM_H(ctx->r2, 0X0);
    // 0x80083918: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x8008391C: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x80083920: mul.s       $f0, $f0, $f24
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f24.fl);
    // 0x80083924: swc1        $f0, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f0.u32l;
    // 0x80083928: lw          $v0, 0x14($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X14);
    // 0x8008392C: lh          $v0, 0x2($v0)
    ctx->r2 = MEM_H(ctx->r2, 0X2);
    // 0x80083930: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x80083934: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x80083938: mul.s       $f0, $f0, $f24
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f24.fl);
    // 0x8008393C: swc1        $f0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f0.u32l;
    // 0x80083940: lw          $v0, 0x14($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X14);
    // 0x80083944: lh          $v0, 0x4($v0)
    ctx->r2 = MEM_H(ctx->r2, 0X4);
    // 0x80083948: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x8008394C: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x80083950: mul.s       $f0, $f0, $f24
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f24.fl);
    // 0x80083954: swc1        $f0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f0.u32l;
    // 0x80083958: lw          $v0, 0x14($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X14);
    // 0x8008395C: lh          $v0, 0x6($v0)
    ctx->r2 = MEM_H(ctx->r2, 0X6);
    // 0x80083960: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x80083964: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x80083968: mul.s       $f0, $f0, $f24
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f24.fl);
    // 0x8008396C: addiu       $a0, $sp, 0x50
    ctx->r4 = ADD32(ctx->r29, 0X50);
    // 0x80083970: addiu       $a1, $sp, 0x10
    ctx->r5 = ADD32(ctx->r29, 0X10);
    // 0x80083974: swc1        $f14, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->f14.u32l;
    // 0x80083978: swc1        $f16, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->f16.u32l;
    // 0x8008397C: swc1        $f18, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->f18.u32l;
    // 0x80083980: jal         0x8001D548
    // 0x80083984: swc1        $f0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f0.u32l;
    func_8001D548(rdram, ctx);
        goto after_2;
    // 0x80083984: swc1        $f0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f0.u32l;
    after_2:
    // 0x80083988: lwc1        $f18, 0x98($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X98);
    // 0x8008398C: lwc1        $f16, 0x94($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X94);
    // 0x80083990: lwc1        $f14, 0x90($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X90);
L_80083994:
    // 0x80083994: lw          $v0, 0x4($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X4);
    // 0x80083998: andi        $v0, $v0, 0x8
    ctx->r2 = ctx->r2 & 0X8;
    // 0x8008399C: beq         $v0, $zero, L_80083A40
    if (ctx->r2 == 0) {
        // 0x800839A0: sll         $a0, $s3, 1
        ctx->r4 = S32(ctx->r19 << 1);
            goto L_80083A40;
    }
    // 0x800839A0: sll         $a0, $s3, 1
    ctx->r4 = S32(ctx->r19 << 1);
    // 0x800839A4: lw          $a1, 0x18($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X18);
    // 0x800839A8: addu        $a0, $a0, $s3
    ctx->r4 = ADD32(ctx->r4, ctx->r19);
    // 0x800839AC: sll         $a0, $a0, 1
    ctx->r4 = S32(ctx->r4 << 1);
    // 0x800839B0: addu        $a0, $a0, $a1
    ctx->r4 = ADD32(ctx->r4, ctx->r5);
    // 0x800839B4: lh          $v0, 0x0($a0)
    ctx->r2 = MEM_H(ctx->r4, 0X0);
    // 0x800839B8: sll         $v1, $s4, 1
    ctx->r3 = S32(ctx->r20 << 1);
    // 0x800839BC: addu        $v1, $v1, $s4
    ctx->r3 = ADD32(ctx->r3, ctx->r20);
    // 0x800839C0: mtc1        $v0, $f2
    ctx->f2.u32l = ctx->r2;
    // 0x800839C4: cvt.s.w     $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    ctx->f2.fl = CVT_S_W(ctx->f2.u32l);
    // 0x800839C8: mul.s       $f2, $f22, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = MUL_S(ctx->f22.fl, ctx->f2.fl);
    // 0x800839CC: sll         $v1, $v1, 1
    ctx->r3 = S32(ctx->r3 << 1);
    // 0x800839D0: addu        $v1, $v1, $a1
    ctx->r3 = ADD32(ctx->r3, ctx->r5);
    // 0x800839D4: lh          $v0, 0x0($v1)
    ctx->r2 = MEM_H(ctx->r3, 0X0);
    // 0x800839D8: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x800839DC: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x800839E0: mul.s       $f0, $f20, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = MUL_S(ctx->f20.fl, ctx->f0.fl);
    // 0x800839E4: lh          $v0, 0x2($a0)
    ctx->r2 = MEM_H(ctx->r4, 0X2);
    // 0x800839E8: mtc1        $v0, $f4
    ctx->f4.u32l = ctx->r2;
    // 0x800839EC: cvt.s.w     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800839F0: mul.s       $f4, $f22, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f4.fl = MUL_S(ctx->f22.fl, ctx->f4.fl);
    // 0x800839F4: lh          $v0, 0x2($v1)
    ctx->r2 = MEM_H(ctx->r3, 0X2);
    // 0x800839F8: mtc1        $v0, $f6
    ctx->f6.u32l = ctx->r2;
    // 0x800839FC: cvt.s.w     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80083A00: mul.s       $f6, $f20, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f6.fl = MUL_S(ctx->f20.fl, ctx->f6.fl);
    // 0x80083A04: add.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x80083A08: mul.s       $f2, $f2, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f14.fl);
    // 0x80083A0C: lh          $v0, 0x4($a0)
    ctx->r2 = MEM_H(ctx->r4, 0X4);
    // 0x80083A10: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x80083A14: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x80083A18: mul.s       $f0, $f22, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = MUL_S(ctx->f22.fl, ctx->f0.fl);
    // 0x80083A1C: lh          $v0, 0x4($v1)
    ctx->r2 = MEM_H(ctx->r3, 0X4);
    // 0x80083A20: mfc1        $t1, $f2
    ctx->r9 = (int32_t)ctx->f2.u32l;
    // 0x80083A24: mtc1        $v0, $f2
    ctx->f2.u32l = ctx->r2;
    // 0x80083A28: cvt.s.w     $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    ctx->f2.fl = CVT_S_W(ctx->f2.u32l);
    // 0x80083A2C: mul.s       $f2, $f20, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = MUL_S(ctx->f20.fl, ctx->f2.fl);
    // 0x80083A30: add.s       $f4, $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80083A34: mul.s       $f10, $f4, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f14.fl);
    // 0x80083A38: j           L_80083A74
    // 0x80083A3C: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
        goto L_80083A74;
    // 0x80083A3C: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
L_80083A40:
    // 0x80083A40: lw          $v1, 0x18($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X18);
    // 0x80083A44: lh          $v0, 0x0($v1)
    ctx->r2 = MEM_H(ctx->r3, 0X0);
    // 0x80083A48: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x80083A4C: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x80083A50: mul.s       $f0, $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f14.fl);
    // 0x80083A54: lh          $v0, 0x2($v1)
    ctx->r2 = MEM_H(ctx->r3, 0X2);
    // 0x80083A58: mfc1        $t1, $f0
    ctx->r9 = (int32_t)ctx->f0.u32l;
    // 0x80083A5C: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x80083A60: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x80083A64: mul.s       $f10, $f0, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f14.fl);
    // 0x80083A68: lh          $v0, 0x4($v1)
    ctx->r2 = MEM_H(ctx->r3, 0X4);
    // 0x80083A6C: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x80083A70: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
L_80083A74:
    // 0x80083A74: mul.s       $f12, $f0, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f12.fl = MUL_S(ctx->f0.fl, ctx->f14.fl);
    // 0x80083A78: lwc1        $f2, 0x10($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X10);
    // 0x80083A7C: mtc1        $s6, $f8
    ctx->f8.u32l = ctx->r22;
    // 0x80083A80: mul.s       $f2, $f2, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f8.fl);
    // 0x80083A84: swc1        $f2, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->f2.u32l;
    // 0x80083A88: mul.s       $f2, $f30, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f30.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = MUL_S(ctx->f30.fl, ctx->f2.fl);
    // 0x80083A8C: lwc1        $f0, 0x14($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X14);
    // 0x80083A90: mul.s       $f0, $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f16.fl);
    // 0x80083A94: nop

    // 0x80083A98: mul.s       $f6, $f26, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f26.fl, ctx->f0.fl);
    // 0x80083A9C: swc1        $f0, 0x4($s2)
    MEM_W(0X4, ctx->r18) = ctx->f0.u32l;
    // 0x80083AA0: lwc1        $f4, 0x18($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X18);
    // 0x80083AA4: mtc1        $t1, $f8
    ctx->f8.u32l = ctx->r9;
    // 0x80083AA8: mul.s       $f4, $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f4.fl, ctx->f18.fl);
    // 0x80083AAC: add.s       $f0, $f30, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f30.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = ctx->f30.fl + ctx->f8.fl;
    // 0x80083AB0: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x80083AB4: mul.s       $f2, $f28, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f28.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = MUL_S(ctx->f28.fl, ctx->f4.fl);
    // 0x80083AB8: sub.s       $f0, $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f6.fl;
    // 0x80083ABC: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x80083AC0: swc1        $f4, 0x8($s2)
    MEM_W(0X8, ctx->r18) = ctx->f4.u32l;
    // 0x80083AC4: swc1        $f0, 0x24($s2)
    MEM_W(0X24, ctx->r18) = ctx->f0.u32l;
    // 0x80083AC8: lwc1        $f2, 0x1C($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x80083ACC: mtc1        $s6, $f8
    ctx->f8.u32l = ctx->r22;
    // 0x80083AD0: mul.s       $f2, $f2, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f8.fl);
    // 0x80083AD4: swc1        $f2, 0xC($s2)
    MEM_W(0XC, ctx->r18) = ctx->f2.u32l;
    // 0x80083AD8: mul.s       $f2, $f30, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f30.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = MUL_S(ctx->f30.fl, ctx->f2.fl);
    // 0x80083ADC: lwc1        $f0, 0x20($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X20);
    // 0x80083AE0: mul.s       $f0, $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f16.fl);
    // 0x80083AE4: nop

    // 0x80083AE8: mul.s       $f6, $f26, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f26.fl, ctx->f0.fl);
    // 0x80083AEC: swc1        $f0, 0x10($s2)
    MEM_W(0X10, ctx->r18) = ctx->f0.u32l;
    // 0x80083AF0: lwc1        $f4, 0x24($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X24);
    // 0x80083AF4: mul.s       $f4, $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f4.fl, ctx->f18.fl);
    // 0x80083AF8: add.s       $f0, $f26, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = ctx->f26.fl + ctx->f10.fl;
    // 0x80083AFC: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x80083B00: mul.s       $f2, $f28, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f28.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = MUL_S(ctx->f28.fl, ctx->f4.fl);
    // 0x80083B04: sub.s       $f0, $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f6.fl;
    // 0x80083B08: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x80083B0C: swc1        $f4, 0x14($s2)
    MEM_W(0X14, ctx->r18) = ctx->f4.u32l;
    // 0x80083B10: swc1        $f0, 0x28($s2)
    MEM_W(0X28, ctx->r18) = ctx->f0.u32l;
    // 0x80083B14: lwc1        $f2, 0x28($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X28);
    // 0x80083B18: mul.s       $f2, $f2, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f8.fl);
    // 0x80083B1C: swc1        $f2, 0x18($s2)
    MEM_W(0X18, ctx->r18) = ctx->f2.u32l;
    // 0x80083B20: mul.s       $f2, $f30, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f30.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = MUL_S(ctx->f30.fl, ctx->f2.fl);
    // 0x80083B24: lwc1        $f0, 0x2C($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80083B28: mul.s       $f0, $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f16.fl);
    // 0x80083B2C: nop

    // 0x80083B30: mul.s       $f6, $f26, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f26.fl, ctx->f0.fl);
    // 0x80083B34: swc1        $f0, 0x1C($s2)
    MEM_W(0X1C, ctx->r18) = ctx->f0.u32l;
    // 0x80083B38: lwc1        $f4, 0x30($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X30);
    // 0x80083B3C: mul.s       $f4, $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f4.fl, ctx->f18.fl);
    // 0x80083B40: add.s       $f0, $f28, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f28.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = ctx->f28.fl + ctx->f12.fl;
    // 0x80083B44: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x80083B48: mul.s       $f2, $f28, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f28.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = MUL_S(ctx->f28.fl, ctx->f4.fl);
    // 0x80083B4C: lw          $t0, 0x74($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X74);
    // 0x80083B50: sub.s       $f0, $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f6.fl;
    // 0x80083B54: addiu       $a1, $t0, -0x1
    ctx->r5 = ADD32(ctx->r8, -0X1);
    // 0x80083B58: sll         $v0, $a1, 2
    ctx->r2 = S32(ctx->r5 << 2);
    // 0x80083B5C: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x80083B60: addu        $v0, $v0, $a1
    ctx->r2 = ADD32(ctx->r2, ctx->r5);
    // 0x80083B64: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80083B68: swc1        $f4, 0x20($s2)
    MEM_W(0X20, ctx->r18) = ctx->f4.u32l;
    // 0x80083B6C: swc1        $f0, 0x2C($s2)
    MEM_W(0X2C, ctx->r18) = ctx->f0.u32l;
    // 0x80083B70: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x80083B74: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80083B78: lw          $v0, -0x5668($at)
    ctx->r2 = MEM_W(ctx->r1, -0X5668);
    // 0x80083B7C: lw          $t0, 0x7C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X7C);
    // 0x80083B80: lw          $v1, 0x4($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X4);
    // 0x80083B84: sll         $v0, $t0, 4
    ctx->r2 = S32(ctx->r8 << 4);
    // 0x80083B88: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80083B8C: lhu         $v0, 0xE($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0XE);
    // 0x80083B90: addiu       $s5, $s5, 0x1
    ctx->r21 = ADD32(ctx->r21, 0X1);
    // 0x80083B94: sltu        $v0, $s5, $v0
    ctx->r2 = ctx->r21 < ctx->r2 ? 1 : 0;
    // 0x80083B98: bne         $v0, $zero, L_80083588
    if (ctx->r2 != 0) {
        // 0x80083B9C: addiu       $fp, $fp, 0x1C
        ctx->r30 = ADD32(ctx->r30, 0X1C);
            goto L_80083588;
    }
    // 0x80083B9C: addiu       $fp, $fp, 0x1C
    ctx->r30 = ADD32(ctx->r30, 0X1C);
L_80083BA0:
    // 0x80083BA0: lw          $t0, 0x74($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X74);
    // 0x80083BA4: addiu       $a0, $t0, -0x1
    ctx->r4 = ADD32(ctx->r8, -0X1);
    // 0x80083BA8: sll         $v0, $a0, 2
    ctx->r2 = S32(ctx->r4 << 2);
    // 0x80083BAC: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x80083BB0: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80083BB4: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x80083BB8: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80083BBC: lw          $v0, -0x5668($at)
    ctx->r2 = MEM_W(ctx->r1, -0X5668);
    // 0x80083BC0: lw          $t0, 0x7C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X7C);
    // 0x80083BC4: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x80083BC8: addiu       $s7, $s7, 0x10
    ctx->r23 = ADD32(ctx->r23, 0X10);
    // 0x80083BCC: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    // 0x80083BD0: sltu        $v0, $t0, $v0
    ctx->r2 = ctx->r8 < ctx->r2 ? 1 : 0;
    // 0x80083BD4: bne         $v0, $zero, L_80083538
    if (ctx->r2 != 0) {
        // 0x80083BD8: sw          $t0, 0x7C($sp)
        MEM_W(0X7C, ctx->r29) = ctx->r8;
            goto L_80083538;
    }
    // 0x80083BD8: sw          $t0, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r8;
L_80083BDC:
    // 0x80083BDC: lw          $ra, 0xC4($sp)
    ctx->r31 = MEM_W(ctx->r29, 0XC4);
    // 0x80083BE0: lw          $fp, 0xC0($sp)
    ctx->r30 = MEM_W(ctx->r29, 0XC0);
    // 0x80083BE4: lw          $s7, 0xBC($sp)
    ctx->r23 = MEM_W(ctx->r29, 0XBC);
    // 0x80083BE8: lw          $s6, 0xB8($sp)
    ctx->r22 = MEM_W(ctx->r29, 0XB8);
    // 0x80083BEC: lw          $s5, 0xB4($sp)
    ctx->r21 = MEM_W(ctx->r29, 0XB4);
    // 0x80083BF0: lw          $s4, 0xB0($sp)
    ctx->r20 = MEM_W(ctx->r29, 0XB0);
    // 0x80083BF4: lw          $s3, 0xAC($sp)
    ctx->r19 = MEM_W(ctx->r29, 0XAC);
    // 0x80083BF8: lw          $s2, 0xA8($sp)
    ctx->r18 = MEM_W(ctx->r29, 0XA8);
    // 0x80083BFC: lw          $s1, 0xA4($sp)
    ctx->r17 = MEM_W(ctx->r29, 0XA4);
    // 0x80083C00: lw          $s0, 0xA0($sp)
    ctx->r16 = MEM_W(ctx->r29, 0XA0);
    // 0x80083C04: ldc1        $f30, 0xF0($sp)
    CHECK_FR(ctx, 30);
    ctx->f30.u64 = LD(ctx->r29, 0XF0);
    // 0x80083C08: ldc1        $f28, 0xE8($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0XE8);
    // 0x80083C0C: ldc1        $f26, 0xE0($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0XE0);
    // 0x80083C10: ldc1        $f24, 0xD8($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0XD8);
    // 0x80083C14: ldc1        $f22, 0xD0($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0XD0);
    // 0x80083C18: ldc1        $f20, 0xC8($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0XC8);
    // 0x80083C1C: addiu       $sp, $sp, 0xF8
    ctx->r29 = ADD32(ctx->r29, 0XF8);
    // 0x80083C20: jr          $ra
    // 0x80083C24: nop

    return;
    // 0x80083C24: nop

;}
RECOMP_FUNC void func_80083C28(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083C28: j           L_80083C38
    // 0x80083C2C: nop

        goto L_80083C38;
    // 0x80083C2C: nop

    // 0x80083C30: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80083C34: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
L_80083C38:
    // 0x80083C38: jal         0x80001ACC
    // 0x80083C3C: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    rs_malloc(rdram, ctx);
        goto after_0;
    // 0x80083C3C: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    after_0:
    // 0x80083C40: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x80083C44: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80083C48: jr          $ra
    // 0x80083C4C: nop

    return;
    // 0x80083C4C: nop

;}
RECOMP_FUNC void func_80083C50(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083C50: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80083C54: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x80083C58: jal         0x80001C98
    // 0x80083C5C: nop

    rs_free(rdram, ctx);
        goto after_0;
    // 0x80083C5C: nop

    after_0:
    // 0x80083C60: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x80083C64: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80083C68: jr          $ra
    // 0x80083C6C: nop

    return;
    // 0x80083C6C: nop

;}
RECOMP_FUNC void unusedRand(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083C70: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x80083C74: lw          $v0, 0xF54($v0)
    ctx->r2 = MEM_W(ctx->r2, 0XF54);
    // 0x80083C78: lui         $v1, 0xA835
    ctx->r3 = S32(0XA835 << 16);
    // 0x80083C7C: ori         $v1, $v1, 0x1D63
    ctx->r3 = ctx->r3 | 0X1D63;
    // 0x80083C80: mult        $v0, $v1
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80083C84: mflo        $v0
    ctx->r2 = lo;
    // 0x80083C88: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x80083C8C: sw          $v0, 0xF54($at)
    MEM_W(0XF54, ctx->r1) = ctx->r2;
    // 0x80083C90: srl         $v0, $v0, 6
    ctx->r2 = S32(U32(ctx->r2) >> 6);
    // 0x80083C94: jr          $ra
    // 0x80083C98: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    return;
    // 0x80083C98: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
;}
RECOMP_FUNC void func_80083C9C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083C9C: andi        $v1, $a0, 0xFFF
    ctx->r3 = ctx->r4 & 0XFFF;
    // 0x80083CA0: sltiu       $v0, $v1, 0x400
    ctx->r2 = ctx->r3 < 0X400 ? 1 : 0;
    // 0x80083CA4: beq         $v0, $zero, L_80083CC0
    if (ctx->r2 == 0) {
        // 0x80083CA8: sll         $v0, $v1, 1
        ctx->r2 = S32(ctx->r3 << 1);
            goto L_80083CC0;
    }
    // 0x80083CA8: sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3 << 1);
    // 0x80083CAC: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x80083CB0: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80083CB4: lh          $v0, 0xF58($at)
    ctx->r2 = MEM_H(ctx->r1, 0XF58);
    // 0x80083CB8: j           L_80083D18
    // 0x80083CBC: nop

        goto L_80083D18;
    // 0x80083CBC: nop

L_80083CC0:
    // 0x80083CC0: sltiu       $v0, $v1, 0x800
    ctx->r2 = ctx->r3 < 0X800 ? 1 : 0;
    // 0x80083CC4: beq         $v0, $zero, L_80083CE8
    if (ctx->r2 == 0) {
        // 0x80083CC8: nor         $v0, $zero, $a0
        ctx->r2 = ~(0 | ctx->r4);
            goto L_80083CE8;
    }
    // 0x80083CC8: nor         $v0, $zero, $a0
    ctx->r2 = ~(0 | ctx->r4);
    // 0x80083CCC: andi        $v0, $v0, 0x3FF
    ctx->r2 = ctx->r2 & 0X3FF;
    // 0x80083CD0: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x80083CD4: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x80083CD8: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80083CDC: lh          $v0, 0xF58($at)
    ctx->r2 = MEM_H(ctx->r1, 0XF58);
    // 0x80083CE0: j           L_80083D18
    // 0x80083CE4: nop

        goto L_80083D18;
    // 0x80083CE4: nop

L_80083CE8:
    // 0x80083CE8: sltiu       $v0, $v1, 0xC00
    ctx->r2 = ctx->r3 < 0XC00 ? 1 : 0;
    // 0x80083CEC: bnel        $v0, $zero, L_80083CFC
    if (ctx->r2 != 0) {
        // 0x80083CF0: andi        $v0, $a0, 0x3FF
        ctx->r2 = ctx->r4 & 0X3FF;
            goto L_80083CFC;
    }
    goto skip_0;
    // 0x80083CF0: andi        $v0, $a0, 0x3FF
    ctx->r2 = ctx->r4 & 0X3FF;
    skip_0:
    // 0x80083CF4: nor         $v0, $zero, $a0
    ctx->r2 = ~(0 | ctx->r4);
    // 0x80083CF8: andi        $v0, $v0, 0x3FF
    ctx->r2 = ctx->r2 & 0X3FF;
L_80083CFC:
    // 0x80083CFC: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x80083D00: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x80083D04: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80083D08: lhu         $v0, 0xF58($at)
    ctx->r2 = MEM_HU(ctx->r1, 0XF58);
    // 0x80083D0C: negu        $v0, $v0
    ctx->r2 = SUB32(0, ctx->r2);
    // 0x80083D10: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x80083D14: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
L_80083D18:
    // 0x80083D18: jr          $ra
    // 0x80083D1C: nop

    return;
    // 0x80083D1C: nop

;}
RECOMP_FUNC void func_80083D20(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083D20: andi        $v1, $a1, 0xFF
    ctx->r3 = ctx->r5 & 0XFF;
    // 0x80083D24: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // 0x80083D28: beql        $v1, $v0, L_80083D30
    if (ctx->r3 == ctx->r2) {
        // 0x80083D2C: addiu       $a1, $zero, 0x8
        ctx->r5 = ADD32(0, 0X8);
            goto L_80083D30;
    }
    goto skip_0;
    // 0x80083D2C: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    skip_0:
L_80083D30:
    // 0x80083D30: sll         $v0, $a0, 1
    ctx->r2 = S32(ctx->r4 << 1);
    // 0x80083D34: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x80083D38: sll         $v0, $v0, 9
    ctx->r2 = S32(ctx->r2 << 9);
    // 0x80083D3C: lui         $v1, 0x8888
    ctx->r3 = S32(0X8888 << 16);
    // 0x80083D40: ori         $v1, $v1, 0x8889
    ctx->r3 = ctx->r3 | 0X8889;
    // 0x80083D44: multu       $v0, $v1
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80083D48: andi        $v0, $a1, 0xFF
    ctx->r2 = ctx->r5 & 0XFF;
    // 0x80083D4C: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80083D50: mfhi        $a2
    ctx->r6 = hi;
    // 0x80083D54: srl         $v1, $a2, 7
    ctx->r3 = S32(U32(ctx->r6) >> 7);
    // 0x80083D58: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x80083D5C: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80083D60: sw          $v1, -0x5330($at)
    MEM_W(-0X5330, ctx->r1) = ctx->r3;
    // 0x80083D64: jr          $ra
    // 0x80083D68: nop

    return;
    // 0x80083D68: nop

;}
RECOMP_FUNC void func_80083D6C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083D6C: lbu         $v1, 0x4F($a0)
    ctx->r3 = MEM_BU(ctx->r4, 0X4F);
    // 0x80083D70: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80083D74: addiu       $a0, $a0, -0x5330
    ctx->r4 = ADD32(ctx->r4, -0X5330);
    // 0x80083D78: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // 0x80083D7C: beq         $v1, $v0, L_80083D8C
    if (ctx->r3 == ctx->r2) {
        // 0x80083D80: sll         $v0, $v1, 2
        ctx->r2 = S32(ctx->r3 << 2);
            goto L_80083D8C;
    }
    // 0x80083D80: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x80083D84: j           L_80083D90
    // 0x80083D88: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
        goto L_80083D90;
    // 0x80083D88: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
L_80083D8C:
    // 0x80083D8C: addiu       $v0, $a0, 0x20
    ctx->r2 = ADD32(ctx->r4, 0X20);
L_80083D90:
    // 0x80083D90: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x80083D94: jr          $ra
    // 0x80083D98: nop

    return;
    // 0x80083D98: nop

;}
RECOMP_FUNC void func_80083D9C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083D9C: andi        $a2, $a2, 0xFF
    ctx->r6 = ctx->r6 & 0XFF;
    // 0x80083DA0: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // 0x80083DA4: beq         $a2, $v0, L_80083DEC
    if (ctx->r6 == ctx->r2) {
        // 0x80083DA8: addu        $t0, $a0, $zero
        ctx->r8 = ADD32(ctx->r4, 0);
            goto L_80083DEC;
    }
    // 0x80083DA8: addu        $t0, $a0, $zero
    ctx->r8 = ADD32(ctx->r4, 0);
    // 0x80083DAC: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x80083DB0: addiu       $v0, $v0, 0x40C8
    ctx->r2 = ADD32(ctx->r2, 0X40C8);
    // 0x80083DB4: sll         $v1, $a2, 4
    ctx->r3 = S32(ctx->r6 << 4);
    // 0x80083DB8: addu        $v1, $v1, $a2
    ctx->r3 = ADD32(ctx->r3, ctx->r6);
    // 0x80083DBC: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x80083DC0: subu        $v1, $v1, $a2
    ctx->r3 = SUB32(ctx->r3, ctx->r6);
    // 0x80083DC4: sll         $v1, $v1, 5
    ctx->r3 = S32(ctx->r3 << 5);
    // 0x80083DC8: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x80083DCC: andi        $a0, $a1, 0xFF
    ctx->r4 = ctx->r5 & 0XFF;
    // 0x80083DD0: sll         $v0, $a0, 4
    ctx->r2 = S32(ctx->r4 << 4);
    // 0x80083DD4: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x80083DD8: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80083DDC: subu        $v0, $v0, $a0
    ctx->r2 = SUB32(ctx->r2, ctx->r4);
    // 0x80083DE0: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x80083DE4: j           L_80083E10
    // 0x80083DE8: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
        goto L_80083E10;
    // 0x80083DE8: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
L_80083DEC:
    // 0x80083DEC: andi        $v1, $a1, 0xFF
    ctx->r3 = ctx->r5 & 0XFF;
    // 0x80083DF0: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80083DF4: addiu       $a0, $a0, 0xA10
    ctx->r4 = ADD32(ctx->r4, 0XA10);
    // 0x80083DF8: sll         $v0, $v1, 4
    ctx->r2 = S32(ctx->r3 << 4);
    // 0x80083DFC: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80083E00: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80083E04: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x80083E08: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x80083E0C: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
L_80083E10:
    // 0x80083E10: andi        $v1, $t0, 0xFF
    ctx->r3 = ctx->r8 & 0XFF;
    // 0x80083E14: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80083E18: andi        $v1, $a3, 0x7F
    ctx->r3 = ctx->r7 & 0X7F;
    // 0x80083E1C: jr          $ra
    // 0x80083E20: sb          $v1, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r3;
    return;
    // 0x80083E20: sb          $v1, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r3;
;}
RECOMP_FUNC void func_80083E24(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083E24: andi        $v1, $a1, 0xFF
    ctx->r3 = ctx->r5 & 0XFF;
    // 0x80083E28: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // 0x80083E2C: beq         $v1, $v0, L_80083E50
    if (ctx->r3 == ctx->r2) {
        // 0x80083E30: sll         $v1, $v1, 4
        ctx->r3 = S32(ctx->r3 << 4);
            goto L_80083E50;
    }
    // 0x80083E30: sll         $v1, $v1, 4
    ctx->r3 = S32(ctx->r3 << 4);
    // 0x80083E34: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x80083E38: addiu       $v0, $v0, 0x2040
    ctx->r2 = ADD32(ctx->r2, 0X2040);
    // 0x80083E3C: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x80083E40: andi        $v0, $a0, 0xFF
    ctx->r2 = ctx->r4 & 0XFF;
    // 0x80083E44: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x80083E48: j           L_80083E60
    // 0x80083E4C: sb          $a2, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r6;
        goto L_80083E60;
    // 0x80083E4C: sb          $a2, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r6;
L_80083E50:
    // 0x80083E50: andi        $v0, $a0, 0xFF
    ctx->r2 = ctx->r4 & 0XFF;
    // 0x80083E54: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x80083E58: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80083E5C: sb          $a2, -0x3BA0($at)
    MEM_B(-0X3BA0, ctx->r1) = ctx->r6;
L_80083E60:
    // 0x80083E60: jr          $ra
    // 0x80083E64: nop

    return;
    // 0x80083E64: nop

;}
RECOMP_FUNC void func_80083E68(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083E68: andi        $v1, $a1, 0xFF
    ctx->r3 = ctx->r5 & 0XFF;
    // 0x80083E6C: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // 0x80083E70: bne         $v1, $v0, L_80083E90
    if (ctx->r3 != ctx->r2) {
        // 0x80083E74: sll         $v1, $v1, 4
        ctx->r3 = S32(ctx->r3 << 4);
            goto L_80083E90;
    }
    // 0x80083E74: sll         $v1, $v1, 4
    ctx->r3 = S32(ctx->r3 << 4);
    // 0x80083E78: andi        $v0, $a0, 0xFF
    ctx->r2 = ctx->r4 & 0XFF;
    // 0x80083E7C: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x80083E80: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80083E84: lbu         $v0, -0x3BA0($at)
    ctx->r2 = MEM_BU(ctx->r1, -0X3BA0);
    // 0x80083E88: j           L_80083EA8
    // 0x80083E8C: nop

        goto L_80083EA8;
    // 0x80083E8C: nop

L_80083E90:
    // 0x80083E90: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x80083E94: addiu       $v0, $v0, 0x2040
    ctx->r2 = ADD32(ctx->r2, 0X2040);
    // 0x80083E98: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x80083E9C: andi        $v0, $a0, 0xFF
    ctx->r2 = ctx->r4 & 0XFF;
    // 0x80083EA0: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x80083EA4: lbu         $v0, 0x0($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X0);
L_80083EA8:
    // 0x80083EA8: jr          $ra
    // 0x80083EAC: nop

    return;
    // 0x80083EAC: nop

;}
RECOMP_FUNC void func_80083EB0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083EB0: andi        $v1, $a1, 0xFF
    ctx->r3 = ctx->r5 & 0XFF;
    // 0x80083EB4: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // 0x80083EB8: beq         $v1, $v0, L_80083EDC
    if (ctx->r3 == ctx->r2) {
        // 0x80083EBC: sll         $v1, $v1, 4
        ctx->r3 = S32(ctx->r3 << 4);
            goto L_80083EDC;
    }
    // 0x80083EBC: sll         $v1, $v1, 4
    ctx->r3 = S32(ctx->r3 << 4);
    // 0x80083EC0: lui         $v0, 0x8015
    ctx->r2 = S32(0X8015 << 16);
    // 0x80083EC4: addiu       $v0, $v0, -0x7C30
    ctx->r2 = ADD32(ctx->r2, -0X7C30);
    // 0x80083EC8: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x80083ECC: andi        $v0, $a0, 0xFF
    ctx->r2 = ctx->r4 & 0XFF;
    // 0x80083ED0: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x80083ED4: j           L_80083EEC
    // 0x80083ED8: sb          $a2, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r6;
        goto L_80083EEC;
    // 0x80083ED8: sb          $a2, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r6;
L_80083EDC:
    // 0x80083EDC: andi        $v0, $a0, 0xFF
    ctx->r2 = ctx->r4 & 0XFF;
    // 0x80083EE0: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x80083EE4: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80083EE8: sb          $a2, 0x2018($at)
    MEM_B(0X2018, ctx->r1) = ctx->r6;
L_80083EEC:
    // 0x80083EEC: jr          $ra
    // 0x80083EF0: nop

    return;
    // 0x80083EF0: nop

;}
RECOMP_FUNC void func_80083EF4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083EF4: andi        $v1, $a1, 0xFF
    ctx->r3 = ctx->r5 & 0XFF;
    // 0x80083EF8: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // 0x80083EFC: bne         $v1, $v0, L_80083F1C
    if (ctx->r3 != ctx->r2) {
        // 0x80083F00: sll         $v1, $v1, 4
        ctx->r3 = S32(ctx->r3 << 4);
            goto L_80083F1C;
    }
    // 0x80083F00: sll         $v1, $v1, 4
    ctx->r3 = S32(ctx->r3 << 4);
    // 0x80083F04: andi        $v0, $a0, 0xFF
    ctx->r2 = ctx->r4 & 0XFF;
    // 0x80083F08: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x80083F0C: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80083F10: lbu         $v0, 0x2018($at)
    ctx->r2 = MEM_BU(ctx->r1, 0X2018);
    // 0x80083F14: j           L_80083F34
    // 0x80083F18: nop

        goto L_80083F34;
    // 0x80083F18: nop

L_80083F1C:
    // 0x80083F1C: lui         $v0, 0x8015
    ctx->r2 = S32(0X8015 << 16);
    // 0x80083F20: addiu       $v0, $v0, -0x7C30
    ctx->r2 = ADD32(ctx->r2, -0X7C30);
    // 0x80083F24: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x80083F28: andi        $v0, $a0, 0xFF
    ctx->r2 = ctx->r4 & 0XFF;
    // 0x80083F2C: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x80083F30: lbu         $v0, 0x0($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X0);
L_80083F34:
    // 0x80083F34: jr          $ra
    // 0x80083F38: nop

    return;
    // 0x80083F38: nop

;}
RECOMP_FUNC void func_80083F3C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083F3C: addu        $a2, $a0, $zero
    ctx->r6 = ADD32(ctx->r4, 0);
    // 0x80083F40: andi        $a0, $a1, 0xFF
    ctx->r4 = ctx->r5 & 0XFF;
    // 0x80083F44: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // 0x80083F48: beq         $a0, $v0, L_80083FA8
    if (ctx->r4 == ctx->r2) {
        // 0x80083F4C: sll         $v1, $a0, 4
        ctx->r3 = S32(ctx->r4 << 4);
            goto L_80083FA8;
    }
    // 0x80083F4C: sll         $v1, $a0, 4
    ctx->r3 = S32(ctx->r4 << 4);
    // 0x80083F50: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x80083F54: addiu       $v0, $v0, 0x40C8
    ctx->r2 = ADD32(ctx->r2, 0X40C8);
    // 0x80083F58: addu        $v1, $v1, $a0
    ctx->r3 = ADD32(ctx->r3, ctx->r4);
    // 0x80083F5C: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x80083F60: subu        $v1, $v1, $a0
    ctx->r3 = SUB32(ctx->r3, ctx->r4);
    // 0x80083F64: sll         $v1, $v1, 5
    ctx->r3 = S32(ctx->r3 << 5);
    // 0x80083F68: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x80083F6C: andi        $a0, $a2, 0xFF
    ctx->r4 = ctx->r6 & 0XFF;
    // 0x80083F70: sll         $v0, $a0, 4
    ctx->r2 = S32(ctx->r4 << 4);
    // 0x80083F74: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x80083F78: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80083F7C: subu        $v0, $v0, $a0
    ctx->r2 = SUB32(ctx->r2, ctx->r4);
    // 0x80083F80: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x80083F84: addu        $v1, $v0, $v1
    ctx->r3 = ADD32(ctx->r2, ctx->r3);
    // 0x80083F88: addiu       $a0, $v1, 0x86
    ctx->r4 = ADD32(ctx->r3, 0X86);
    // 0x80083F8C: sb          $zero, 0x0($v1)
    MEM_B(0X0, ctx->r3) = 0;
L_80083F90:
    // 0x80083F90: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80083F94: sltu        $v0, $v1, $a0
    ctx->r2 = ctx->r3 < ctx->r4 ? 1 : 0;
    // 0x80083F98: bnel        $v0, $zero, L_80083F90
    if (ctx->r2 != 0) {
        // 0x80083F9C: sb          $zero, 0x0($v1)
        MEM_B(0X0, ctx->r3) = 0;
            goto L_80083F90;
    }
    goto skip_0;
    // 0x80083F9C: sb          $zero, 0x0($v1)
    MEM_B(0X0, ctx->r3) = 0;
    skip_0:
    // 0x80083FA0: j           L_80083FE8
    // 0x80083FA4: andi        $a0, $a1, 0xFF
    ctx->r4 = ctx->r5 & 0XFF;
        goto L_80083FE8;
    // 0x80083FA4: andi        $a0, $a1, 0xFF
    ctx->r4 = ctx->r5 & 0XFF;
L_80083FA8:
    // 0x80083FA8: andi        $v0, $a2, 0xFF
    ctx->r2 = ctx->r6 & 0XFF;
    // 0x80083FAC: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80083FB0: addiu       $a0, $a0, 0xA10
    ctx->r4 = ADD32(ctx->r4, 0XA10);
    // 0x80083FB4: sll         $v1, $v0, 4
    ctx->r3 = S32(ctx->r2 << 4);
    // 0x80083FB8: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x80083FBC: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x80083FC0: subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // 0x80083FC4: sll         $v1, $v1, 1
    ctx->r3 = S32(ctx->r3 << 1);
    // 0x80083FC8: addu        $v1, $v1, $a0
    ctx->r3 = ADD32(ctx->r3, ctx->r4);
    // 0x80083FCC: addiu       $a0, $v1, 0x86
    ctx->r4 = ADD32(ctx->r3, 0X86);
    // 0x80083FD0: sb          $zero, 0x0($v1)
    MEM_B(0X0, ctx->r3) = 0;
L_80083FD4:
    // 0x80083FD4: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80083FD8: sltu        $v0, $v1, $a0
    ctx->r2 = ctx->r3 < ctx->r4 ? 1 : 0;
    // 0x80083FDC: bnel        $v0, $zero, L_80083FD4
    if (ctx->r2 != 0) {
        // 0x80083FE0: sb          $zero, 0x0($v1)
        MEM_B(0X0, ctx->r3) = 0;
            goto L_80083FD4;
    }
    goto skip_1;
    // 0x80083FE0: sb          $zero, 0x0($v1)
    MEM_B(0X0, ctx->r3) = 0;
    skip_1:
    // 0x80083FE4: andi        $a0, $a1, 0xFF
    ctx->r4 = ctx->r5 & 0XFF;
L_80083FE8:
    // 0x80083FE8: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // 0x80083FEC: beq         $a0, $v0, L_80084038
    if (ctx->r4 == ctx->r2) {
        // 0x80083FF0: sll         $v1, $a0, 4
        ctx->r3 = S32(ctx->r4 << 4);
            goto L_80084038;
    }
    // 0x80083FF0: sll         $v1, $a0, 4
    ctx->r3 = S32(ctx->r4 << 4);
    // 0x80083FF4: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x80083FF8: addiu       $v0, $v0, 0x40C8
    ctx->r2 = ADD32(ctx->r2, 0X40C8);
    // 0x80083FFC: addu        $v1, $v1, $a0
    ctx->r3 = ADD32(ctx->r3, ctx->r4);
    // 0x80084000: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x80084004: subu        $v1, $v1, $a0
    ctx->r3 = SUB32(ctx->r3, ctx->r4);
    // 0x80084008: sll         $v1, $v1, 5
    ctx->r3 = S32(ctx->r3 << 5);
    // 0x8008400C: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x80084010: andi        $a0, $a2, 0xFF
    ctx->r4 = ctx->r6 & 0XFF;
    // 0x80084014: sll         $v0, $a0, 4
    ctx->r2 = S32(ctx->r4 << 4);
    // 0x80084018: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x8008401C: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80084020: subu        $v0, $v0, $a0
    ctx->r2 = SUB32(ctx->r2, ctx->r4);
    // 0x80084024: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x80084028: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8008402C: addiu       $v1, $zero, 0x7F
    ctx->r3 = ADD32(0, 0X7F);
    // 0x80084030: j           L_80084060
    // 0x80084034: sb          $v1, 0x7($v0)
    MEM_B(0X7, ctx->r2) = ctx->r3;
        goto L_80084060;
    // 0x80084034: sb          $v1, 0x7($v0)
    MEM_B(0X7, ctx->r2) = ctx->r3;
L_80084038:
    // 0x80084038: andi        $v0, $a2, 0xFF
    ctx->r2 = ctx->r6 & 0XFF;
    // 0x8008403C: sll         $v1, $v0, 4
    ctx->r3 = S32(ctx->r2 << 4);
    // 0x80084040: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x80084044: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x80084048: subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // 0x8008404C: sll         $v1, $v1, 1
    ctx->r3 = S32(ctx->r3 << 1);
    // 0x80084050: addiu       $v0, $zero, 0x7F
    ctx->r2 = ADD32(0, 0X7F);
    // 0x80084054: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x80084058: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x8008405C: sb          $v0, 0xA17($at)
    MEM_B(0XA17, ctx->r1) = ctx->r2;
L_80084060:
    // 0x80084060: andi        $a0, $a1, 0xFF
    ctx->r4 = ctx->r5 & 0XFF;
    // 0x80084064: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // 0x80084068: beq         $a0, $v0, L_800840B4
    if (ctx->r4 == ctx->r2) {
        // 0x8008406C: sll         $v1, $a0, 4
        ctx->r3 = S32(ctx->r4 << 4);
            goto L_800840B4;
    }
    // 0x8008406C: sll         $v1, $a0, 4
    ctx->r3 = S32(ctx->r4 << 4);
    // 0x80084070: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x80084074: addiu       $v0, $v0, 0x40C8
    ctx->r2 = ADD32(ctx->r2, 0X40C8);
    // 0x80084078: addu        $v1, $v1, $a0
    ctx->r3 = ADD32(ctx->r3, ctx->r4);
    // 0x8008407C: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x80084080: subu        $v1, $v1, $a0
    ctx->r3 = SUB32(ctx->r3, ctx->r4);
    // 0x80084084: sll         $v1, $v1, 5
    ctx->r3 = S32(ctx->r3 << 5);
    // 0x80084088: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x8008408C: andi        $a0, $a2, 0xFF
    ctx->r4 = ctx->r6 & 0XFF;
    // 0x80084090: sll         $v0, $a0, 4
    ctx->r2 = S32(ctx->r4 << 4);
    // 0x80084094: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x80084098: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8008409C: subu        $v0, $v0, $a0
    ctx->r2 = SUB32(ctx->r2, ctx->r4);
    // 0x800840A0: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x800840A4: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800840A8: addiu       $v1, $zero, 0x40
    ctx->r3 = ADD32(0, 0X40);
    // 0x800840AC: j           L_800840DC
    // 0x800840B0: sb          $v1, 0xA($v0)
    MEM_B(0XA, ctx->r2) = ctx->r3;
        goto L_800840DC;
    // 0x800840B0: sb          $v1, 0xA($v0)
    MEM_B(0XA, ctx->r2) = ctx->r3;
L_800840B4:
    // 0x800840B4: andi        $v0, $a2, 0xFF
    ctx->r2 = ctx->r6 & 0XFF;
    // 0x800840B8: sll         $v1, $v0, 4
    ctx->r3 = S32(ctx->r2 << 4);
    // 0x800840BC: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x800840C0: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x800840C4: subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // 0x800840C8: sll         $v1, $v1, 1
    ctx->r3 = S32(ctx->r3 << 1);
    // 0x800840CC: addiu       $v0, $zero, 0x40
    ctx->r2 = ADD32(0, 0X40);
    // 0x800840D0: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x800840D4: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x800840D8: sb          $v0, 0xA1A($at)
    MEM_B(0XA1A, ctx->r1) = ctx->r2;
L_800840DC:
    // 0x800840DC: andi        $a0, $a1, 0xFF
    ctx->r4 = ctx->r5 & 0XFF;
    // 0x800840E0: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // 0x800840E4: beq         $a0, $v0, L_80084130
    if (ctx->r4 == ctx->r2) {
        // 0x800840E8: sll         $v1, $a0, 4
        ctx->r3 = S32(ctx->r4 << 4);
            goto L_80084130;
    }
    // 0x800840E8: sll         $v1, $a0, 4
    ctx->r3 = S32(ctx->r4 << 4);
    // 0x800840EC: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x800840F0: addiu       $v0, $v0, 0x40C8
    ctx->r2 = ADD32(ctx->r2, 0X40C8);
    // 0x800840F4: addu        $v1, $v1, $a0
    ctx->r3 = ADD32(ctx->r3, ctx->r4);
    // 0x800840F8: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x800840FC: subu        $v1, $v1, $a0
    ctx->r3 = SUB32(ctx->r3, ctx->r4);
    // 0x80084100: sll         $v1, $v1, 5
    ctx->r3 = S32(ctx->r3 << 5);
    // 0x80084104: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x80084108: andi        $a0, $a2, 0xFF
    ctx->r4 = ctx->r6 & 0XFF;
    // 0x8008410C: sll         $v0, $a0, 4
    ctx->r2 = S32(ctx->r4 << 4);
    // 0x80084110: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x80084114: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80084118: subu        $v0, $v0, $a0
    ctx->r2 = SUB32(ctx->r2, ctx->r4);
    // 0x8008411C: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x80084120: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80084124: addiu       $v1, $zero, 0x40
    ctx->r3 = ADD32(0, 0X40);
    // 0x80084128: j           L_80084158
    // 0x8008412C: sb          $v1, 0x80($v0)
    MEM_B(0X80, ctx->r2) = ctx->r3;
        goto L_80084158;
    // 0x8008412C: sb          $v1, 0x80($v0)
    MEM_B(0X80, ctx->r2) = ctx->r3;
L_80084130:
    // 0x80084130: andi        $v0, $a2, 0xFF
    ctx->r2 = ctx->r6 & 0XFF;
    // 0x80084134: sll         $v1, $v0, 4
    ctx->r3 = S32(ctx->r2 << 4);
    // 0x80084138: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x8008413C: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x80084140: subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // 0x80084144: sll         $v1, $v1, 1
    ctx->r3 = S32(ctx->r3 << 1);
    // 0x80084148: addiu       $v0, $zero, 0x40
    ctx->r2 = ADD32(0, 0X40);
    // 0x8008414C: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x80084150: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x80084154: sb          $v0, 0xA90($at)
    MEM_B(0XA90, ctx->r1) = ctx->r2;
L_80084158:
    // 0x80084158: andi        $a0, $a1, 0xFF
    ctx->r4 = ctx->r5 & 0XFF;
    // 0x8008415C: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // 0x80084160: beq         $a0, $v0, L_800841A8
    if (ctx->r4 == ctx->r2) {
        // 0x80084164: sll         $v1, $a0, 4
        ctx->r3 = S32(ctx->r4 << 4);
            goto L_800841A8;
    }
    // 0x80084164: sll         $v1, $a0, 4
    ctx->r3 = S32(ctx->r4 << 4);
    // 0x80084168: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x8008416C: addiu       $v0, $v0, 0x40C8
    ctx->r2 = ADD32(ctx->r2, 0X40C8);
    // 0x80084170: addu        $v1, $v1, $a0
    ctx->r3 = ADD32(ctx->r3, ctx->r4);
    // 0x80084174: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x80084178: subu        $v1, $v1, $a0
    ctx->r3 = SUB32(ctx->r3, ctx->r4);
    // 0x8008417C: sll         $v1, $v1, 5
    ctx->r3 = S32(ctx->r3 << 5);
    // 0x80084180: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x80084184: andi        $a0, $a2, 0xFF
    ctx->r4 = ctx->r6 & 0XFF;
    // 0x80084188: sll         $v0, $a0, 4
    ctx->r2 = S32(ctx->r4 << 4);
    // 0x8008418C: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x80084190: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80084194: subu        $v0, $v0, $a0
    ctx->r2 = SUB32(ctx->r2, ctx->r4);
    // 0x80084198: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x8008419C: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800841A0: j           L_800841CC
    // 0x800841A4: sb          $zero, 0x81($v0)
    MEM_B(0X81, ctx->r2) = 0;
        goto L_800841CC;
    // 0x800841A4: sb          $zero, 0x81($v0)
    MEM_B(0X81, ctx->r2) = 0;
L_800841A8:
    // 0x800841A8: andi        $v1, $a2, 0xFF
    ctx->r3 = ctx->r6 & 0XFF;
    // 0x800841AC: sll         $v0, $v1, 4
    ctx->r2 = S32(ctx->r3 << 4);
    // 0x800841B0: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800841B4: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800841B8: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x800841BC: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x800841C0: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x800841C4: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x800841C8: sb          $zero, 0xA91($at)
    MEM_B(0XA91, ctx->r1) = 0;
L_800841CC:
    // 0x800841CC: andi        $a0, $a1, 0xFF
    ctx->r4 = ctx->r5 & 0XFF;
    // 0x800841D0: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // 0x800841D4: beq         $a0, $v0, L_8008421C
    if (ctx->r4 == ctx->r2) {
        // 0x800841D8: sll         $v1, $a0, 4
        ctx->r3 = S32(ctx->r4 << 4);
            goto L_8008421C;
    }
    // 0x800841D8: sll         $v1, $a0, 4
    ctx->r3 = S32(ctx->r4 << 4);
    // 0x800841DC: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x800841E0: addiu       $v0, $v0, 0x40C8
    ctx->r2 = ADD32(ctx->r2, 0X40C8);
    // 0x800841E4: addu        $v1, $v1, $a0
    ctx->r3 = ADD32(ctx->r3, ctx->r4);
    // 0x800841E8: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x800841EC: subu        $v1, $v1, $a0
    ctx->r3 = SUB32(ctx->r3, ctx->r4);
    // 0x800841F0: sll         $v1, $v1, 5
    ctx->r3 = S32(ctx->r3 << 5);
    // 0x800841F4: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x800841F8: andi        $a0, $a2, 0xFF
    ctx->r4 = ctx->r6 & 0XFF;
    // 0x800841FC: sll         $v0, $a0, 4
    ctx->r2 = S32(ctx->r4 << 4);
    // 0x80084200: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x80084204: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80084208: subu        $v0, $v0, $a0
    ctx->r2 = SUB32(ctx->r2, ctx->r4);
    // 0x8008420C: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x80084210: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80084214: j           L_80084240
    // 0x80084218: sb          $zero, 0x40($v0)
    MEM_B(0X40, ctx->r2) = 0;
        goto L_80084240;
    // 0x80084218: sb          $zero, 0x40($v0)
    MEM_B(0X40, ctx->r2) = 0;
L_8008421C:
    // 0x8008421C: andi        $v1, $a2, 0xFF
    ctx->r3 = ctx->r6 & 0XFF;
    // 0x80084220: sll         $v0, $v1, 4
    ctx->r2 = S32(ctx->r3 << 4);
    // 0x80084224: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80084228: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8008422C: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x80084230: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x80084234: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x80084238: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x8008423C: sb          $zero, 0xA50($at)
    MEM_B(0XA50, ctx->r1) = 0;
L_80084240:
    // 0x80084240: andi        $a0, $a1, 0xFF
    ctx->r4 = ctx->r5 & 0XFF;
    // 0x80084244: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // 0x80084248: beq         $a0, $v0, L_80084290
    if (ctx->r4 == ctx->r2) {
        // 0x8008424C: sll         $v1, $a0, 4
        ctx->r3 = S32(ctx->r4 << 4);
            goto L_80084290;
    }
    // 0x8008424C: sll         $v1, $a0, 4
    ctx->r3 = S32(ctx->r4 << 4);
    // 0x80084250: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x80084254: addiu       $v0, $v0, 0x40C8
    ctx->r2 = ADD32(ctx->r2, 0X40C8);
    // 0x80084258: addu        $v1, $v1, $a0
    ctx->r3 = ADD32(ctx->r3, ctx->r4);
    // 0x8008425C: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x80084260: subu        $v1, $v1, $a0
    ctx->r3 = SUB32(ctx->r3, ctx->r4);
    // 0x80084264: sll         $v1, $v1, 5
    ctx->r3 = S32(ctx->r3 << 5);
    // 0x80084268: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x8008426C: andi        $a0, $a2, 0xFF
    ctx->r4 = ctx->r6 & 0XFF;
    // 0x80084270: sll         $v0, $a0, 4
    ctx->r2 = S32(ctx->r4 << 4);
    // 0x80084274: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x80084278: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8008427C: subu        $v0, $v0, $a0
    ctx->r2 = SUB32(ctx->r2, ctx->r4);
    // 0x80084280: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x80084284: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80084288: j           L_800842B4
    // 0x8008428C: sb          $zero, 0x41($v0)
    MEM_B(0X41, ctx->r2) = 0;
        goto L_800842B4;
    // 0x8008428C: sb          $zero, 0x41($v0)
    MEM_B(0X41, ctx->r2) = 0;
L_80084290:
    // 0x80084290: andi        $v1, $a2, 0xFF
    ctx->r3 = ctx->r6 & 0XFF;
    // 0x80084294: sll         $v0, $v1, 4
    ctx->r2 = S32(ctx->r3 << 4);
    // 0x80084298: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8008429C: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800842A0: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x800842A4: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x800842A8: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x800842AC: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x800842B0: sb          $zero, 0xA51($at)
    MEM_B(0XA51, ctx->r1) = 0;
L_800842B4:
    // 0x800842B4: andi        $a0, $a1, 0xFF
    ctx->r4 = ctx->r5 & 0XFF;
    // 0x800842B8: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // 0x800842BC: beq         $a0, $v0, L_80084304
    if (ctx->r4 == ctx->r2) {
        // 0x800842C0: sll         $v1, $a0, 4
        ctx->r3 = S32(ctx->r4 << 4);
            goto L_80084304;
    }
    // 0x800842C0: sll         $v1, $a0, 4
    ctx->r3 = S32(ctx->r4 << 4);
    // 0x800842C4: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x800842C8: addiu       $v0, $v0, 0x40C8
    ctx->r2 = ADD32(ctx->r2, 0X40C8);
    // 0x800842CC: addu        $v1, $v1, $a0
    ctx->r3 = ADD32(ctx->r3, ctx->r4);
    // 0x800842D0: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x800842D4: subu        $v1, $v1, $a0
    ctx->r3 = SUB32(ctx->r3, ctx->r4);
    // 0x800842D8: sll         $v1, $v1, 5
    ctx->r3 = S32(ctx->r3 << 5);
    // 0x800842DC: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x800842E0: andi        $a0, $a2, 0xFF
    ctx->r4 = ctx->r6 & 0XFF;
    // 0x800842E4: sll         $v0, $a0, 4
    ctx->r2 = S32(ctx->r4 << 4);
    // 0x800842E8: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x800842EC: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800842F0: subu        $v0, $v0, $a0
    ctx->r2 = SUB32(ctx->r2, ctx->r4);
    // 0x800842F4: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x800842F8: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800842FC: j           L_80084328
    // 0x80084300: sb          $zero, 0x5B($v0)
    MEM_B(0X5B, ctx->r2) = 0;
        goto L_80084328;
    // 0x80084300: sb          $zero, 0x5B($v0)
    MEM_B(0X5B, ctx->r2) = 0;
L_80084304:
    // 0x80084304: andi        $v1, $a2, 0xFF
    ctx->r3 = ctx->r6 & 0XFF;
    // 0x80084308: sll         $v0, $v1, 4
    ctx->r2 = S32(ctx->r3 << 4);
    // 0x8008430C: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80084310: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80084314: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x80084318: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x8008431C: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x80084320: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80084324: sb          $zero, 0xA6B($at)
    MEM_B(0XA6B, ctx->r1) = 0;
L_80084328:
    // 0x80084328: andi        $a0, $a1, 0xFF
    ctx->r4 = ctx->r5 & 0XFF;
    // 0x8008432C: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // 0x80084330: beq         $a0, $v0, L_80084378
    if (ctx->r4 == ctx->r2) {
        // 0x80084334: sll         $v1, $a0, 4
        ctx->r3 = S32(ctx->r4 << 4);
            goto L_80084378;
    }
    // 0x80084334: sll         $v1, $a0, 4
    ctx->r3 = S32(ctx->r4 << 4);
    // 0x80084338: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x8008433C: addiu       $v0, $v0, 0x40C8
    ctx->r2 = ADD32(ctx->r2, 0X40C8);
    // 0x80084340: addu        $v1, $v1, $a0
    ctx->r3 = ADD32(ctx->r3, ctx->r4);
    // 0x80084344: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x80084348: subu        $v1, $v1, $a0
    ctx->r3 = SUB32(ctx->r3, ctx->r4);
    // 0x8008434C: sll         $v1, $v1, 5
    ctx->r3 = S32(ctx->r3 << 5);
    // 0x80084350: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x80084354: andi        $a0, $a2, 0xFF
    ctx->r4 = ctx->r6 & 0XFF;
    // 0x80084358: sll         $v0, $a0, 4
    ctx->r2 = S32(ctx->r4 << 4);
    // 0x8008435C: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x80084360: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80084364: subu        $v0, $v0, $a0
    ctx->r2 = SUB32(ctx->r2, ctx->r4);
    // 0x80084368: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x8008436C: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80084370: j           L_8008439C
    // 0x80084374: sb          $zero, 0x83($v0)
    MEM_B(0X83, ctx->r2) = 0;
        goto L_8008439C;
    // 0x80084374: sb          $zero, 0x83($v0)
    MEM_B(0X83, ctx->r2) = 0;
L_80084378:
    // 0x80084378: andi        $v1, $a2, 0xFF
    ctx->r3 = ctx->r6 & 0XFF;
    // 0x8008437C: sll         $v0, $v1, 4
    ctx->r2 = S32(ctx->r3 << 4);
    // 0x80084380: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80084384: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80084388: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x8008438C: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x80084390: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x80084394: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80084398: sb          $zero, 0xA93($at)
    MEM_B(0XA93, ctx->r1) = 0;
L_8008439C:
    // 0x8008439C: andi        $a0, $a1, 0xFF
    ctx->r4 = ctx->r5 & 0XFF;
    // 0x800843A0: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // 0x800843A4: beq         $a0, $v0, L_800843F0
    if (ctx->r4 == ctx->r2) {
        // 0x800843A8: sll         $v1, $a0, 4
        ctx->r3 = S32(ctx->r4 << 4);
            goto L_800843F0;
    }
    // 0x800843A8: sll         $v1, $a0, 4
    ctx->r3 = S32(ctx->r4 << 4);
    // 0x800843AC: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x800843B0: addiu       $v0, $v0, 0x40C8
    ctx->r2 = ADD32(ctx->r2, 0X40C8);
    // 0x800843B4: addu        $v1, $v1, $a0
    ctx->r3 = ADD32(ctx->r3, ctx->r4);
    // 0x800843B8: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x800843BC: subu        $v1, $v1, $a0
    ctx->r3 = SUB32(ctx->r3, ctx->r4);
    // 0x800843C0: sll         $v1, $v1, 5
    ctx->r3 = S32(ctx->r3 << 5);
    // 0x800843C4: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x800843C8: andi        $a0, $a2, 0xFF
    ctx->r4 = ctx->r6 & 0XFF;
    // 0x800843CC: sll         $v0, $a0, 4
    ctx->r2 = S32(ctx->r4 << 4);
    // 0x800843D0: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x800843D4: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800843D8: subu        $v0, $v0, $a0
    ctx->r2 = SUB32(ctx->r2, ctx->r4);
    // 0x800843DC: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x800843E0: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800843E4: addiu       $v1, $zero, 0x40
    ctx->r3 = ADD32(0, 0X40);
    // 0x800843E8: j           L_80084418
    // 0x800843EC: sb          $v1, 0x84($v0)
    MEM_B(0X84, ctx->r2) = ctx->r3;
        goto L_80084418;
    // 0x800843EC: sb          $v1, 0x84($v0)
    MEM_B(0X84, ctx->r2) = ctx->r3;
L_800843F0:
    // 0x800843F0: andi        $v0, $a2, 0xFF
    ctx->r2 = ctx->r6 & 0XFF;
    // 0x800843F4: sll         $v1, $v0, 4
    ctx->r3 = S32(ctx->r2 << 4);
    // 0x800843F8: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x800843FC: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x80084400: subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // 0x80084404: sll         $v1, $v1, 1
    ctx->r3 = S32(ctx->r3 << 1);
    // 0x80084408: addiu       $v0, $zero, 0x40
    ctx->r2 = ADD32(0, 0X40);
    // 0x8008440C: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x80084410: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x80084414: sb          $v0, 0xA94($at)
    MEM_B(0XA94, ctx->r1) = ctx->r2;
L_80084418:
    // 0x80084418: andi        $a0, $a1, 0xFF
    ctx->r4 = ctx->r5 & 0XFF;
    // 0x8008441C: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // 0x80084420: beq         $a0, $v0, L_80084468
    if (ctx->r4 == ctx->r2) {
        // 0x80084424: sll         $v1, $a0, 4
        ctx->r3 = S32(ctx->r4 << 4);
            goto L_80084468;
    }
    // 0x80084424: sll         $v1, $a0, 4
    ctx->r3 = S32(ctx->r4 << 4);
    // 0x80084428: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x8008442C: addiu       $v0, $v0, 0x40C8
    ctx->r2 = ADD32(ctx->r2, 0X40C8);
    // 0x80084430: addu        $v1, $v1, $a0
    ctx->r3 = ADD32(ctx->r3, ctx->r4);
    // 0x80084434: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x80084438: subu        $v1, $v1, $a0
    ctx->r3 = SUB32(ctx->r3, ctx->r4);
    // 0x8008443C: sll         $v1, $v1, 5
    ctx->r3 = S32(ctx->r3 << 5);
    // 0x80084440: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x80084444: andi        $a0, $a2, 0xFF
    ctx->r4 = ctx->r6 & 0XFF;
    // 0x80084448: sll         $v0, $a0, 4
    ctx->r2 = S32(ctx->r4 << 4);
    // 0x8008444C: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x80084450: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80084454: subu        $v0, $v0, $a0
    ctx->r2 = SUB32(ctx->r2, ctx->r4);
    // 0x80084458: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x8008445C: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80084460: j           L_8008448C
    // 0x80084464: sb          $zero, 0x85($v0)
    MEM_B(0X85, ctx->r2) = 0;
        goto L_8008448C;
    // 0x80084464: sb          $zero, 0x85($v0)
    MEM_B(0X85, ctx->r2) = 0;
L_80084468:
    // 0x80084468: andi        $v1, $a2, 0xFF
    ctx->r3 = ctx->r6 & 0XFF;
    // 0x8008446C: sll         $v0, $v1, 4
    ctx->r2 = S32(ctx->r3 << 4);
    // 0x80084470: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80084474: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80084478: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x8008447C: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x80084480: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x80084484: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80084488: sb          $zero, 0xA95($at)
    MEM_B(0XA95, ctx->r1) = 0;
L_8008448C:
    // 0x8008448C: andi        $v1, $a1, 0xFF
    ctx->r3 = ctx->r5 & 0XFF;
    // 0x80084490: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // 0x80084494: beq         $v1, $v0, L_800844BC
    if (ctx->r3 == ctx->r2) {
        // 0x80084498: addiu       $a0, $zero, 0xFF
        ctx->r4 = ADD32(0, 0XFF);
            goto L_800844BC;
    }
    // 0x80084498: addiu       $a0, $zero, 0xFF
    ctx->r4 = ADD32(0, 0XFF);
    // 0x8008449C: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x800844A0: addiu       $v0, $v0, 0x2040
    ctx->r2 = ADD32(ctx->r2, 0X2040);
    // 0x800844A4: sll         $v1, $v1, 4
    ctx->r3 = S32(ctx->r3 << 4);
    // 0x800844A8: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x800844AC: andi        $v0, $a2, 0xFF
    ctx->r2 = ctx->r6 & 0XFF;
    // 0x800844B0: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x800844B4: j           L_800844CC
    // 0x800844B8: sb          $a0, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r4;
        goto L_800844CC;
    // 0x800844B8: sb          $a0, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r4;
L_800844BC:
    // 0x800844BC: andi        $v0, $a2, 0xFF
    ctx->r2 = ctx->r6 & 0XFF;
    // 0x800844C0: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x800844C4: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x800844C8: sb          $a0, -0x3BA0($at)
    MEM_B(-0X3BA0, ctx->r1) = ctx->r4;
L_800844CC:
    // 0x800844CC: andi        $v1, $a1, 0xFF
    ctx->r3 = ctx->r5 & 0XFF;
    // 0x800844D0: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // 0x800844D4: beq         $v1, $v0, L_800844F8
    if (ctx->r3 == ctx->r2) {
        // 0x800844D8: sll         $v1, $v1, 4
        ctx->r3 = S32(ctx->r3 << 4);
            goto L_800844F8;
    }
    // 0x800844D8: sll         $v1, $v1, 4
    ctx->r3 = S32(ctx->r3 << 4);
    // 0x800844DC: lui         $v0, 0x8015
    ctx->r2 = S32(0X8015 << 16);
    // 0x800844E0: addiu       $v0, $v0, -0x7C30
    ctx->r2 = ADD32(ctx->r2, -0X7C30);
    // 0x800844E4: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x800844E8: andi        $v0, $a2, 0xFF
    ctx->r2 = ctx->r6 & 0XFF;
    // 0x800844EC: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x800844F0: j           L_80084508
    // 0x800844F4: sb          $zero, 0x0($v1)
    MEM_B(0X0, ctx->r3) = 0;
        goto L_80084508;
    // 0x800844F4: sb          $zero, 0x0($v1)
    MEM_B(0X0, ctx->r3) = 0;
L_800844F8:
    // 0x800844F8: andi        $v0, $a2, 0xFF
    ctx->r2 = ctx->r6 & 0XFF;
    // 0x800844FC: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x80084500: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80084504: sb          $zero, 0x2018($at)
    MEM_B(0X2018, ctx->r1) = 0;
L_80084508:
    // 0x80084508: jr          $ra
    // 0x8008450C: nop

    return;
    // 0x8008450C: nop

;}
RECOMP_FUNC void func_80084510(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084510: addu        $a3, $a0, $zero
    ctx->r7 = ADD32(ctx->r4, 0);
    // 0x80084514: andi        $a2, $a2, 0xFF
    ctx->r6 = ctx->r6 & 0XFF;
    // 0x80084518: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // 0x8008451C: beq         $a2, $v0, L_80084678
    if (ctx->r6 == ctx->r2) {
        // 0x80084520: addu        $v1, $a3, $zero
        ctx->r3 = ADD32(ctx->r7, 0);
            goto L_80084678;
    }
    // 0x80084520: addu        $v1, $a3, $zero
    ctx->r3 = ADD32(ctx->r7, 0);
    // 0x80084524: andi        $t0, $v1, 0xFF
    ctx->r8 = ctx->r3 & 0XFF;
    // 0x80084528: sltiu       $v0, $t0, 0x40
    ctx->r2 = ctx->r8 < 0X40 ? 1 : 0;
    // 0x8008452C: beq         $v0, $zero, L_80084584
    if (ctx->r2 == 0) {
        // 0x80084530: sll         $v0, $a2, 4
        ctx->r2 = S32(ctx->r6 << 4);
            goto L_80084584;
    }
    // 0x80084530: sll         $v0, $a2, 4
    ctx->r2 = S32(ctx->r6 << 4);
    // 0x80084534: lui         $v1, 0x8014
    ctx->r3 = S32(0X8014 << 16);
    // 0x80084538: addiu       $v1, $v1, 0x40C8
    ctx->r3 = ADD32(ctx->r3, 0X40C8);
    // 0x8008453C: addu        $v0, $v0, $a2
    ctx->r2 = ADD32(ctx->r2, ctx->r6);
    // 0x80084540: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80084544: subu        $v0, $v0, $a2
    ctx->r2 = SUB32(ctx->r2, ctx->r6);
    // 0x80084548: sll         $v0, $v0, 5
    ctx->r2 = S32(ctx->r2 << 5);
    // 0x8008454C: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80084550: andi        $a0, $a1, 0xFF
    ctx->r4 = ctx->r5 & 0XFF;
    // 0x80084554: sll         $v1, $a0, 4
    ctx->r3 = S32(ctx->r4 << 4);
    // 0x80084558: addu        $v1, $v1, $a0
    ctx->r3 = ADD32(ctx->r3, ctx->r4);
    // 0x8008455C: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x80084560: subu        $v1, $v1, $a0
    ctx->r3 = SUB32(ctx->r3, ctx->r4);
    // 0x80084564: sll         $v1, $v1, 1
    ctx->r3 = S32(ctx->r3 << 1);
    // 0x80084568: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x8008456C: andi        $v0, $a3, 0x1F
    ctx->r2 = ctx->r7 & 0X1F;
    // 0x80084570: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x80084574: lbu         $v0, 0x0($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X0);
    // 0x80084578: lbu         $v1, 0x20($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X20);
    // 0x8008457C: j           L_80084708
    // 0x80084580: sll         $v0, $v0, 7
    ctx->r2 = S32(ctx->r2 << 7);
        goto L_80084708;
    // 0x80084580: sll         $v0, $v0, 7
    ctx->r2 = S32(ctx->r2 << 7);
L_80084584:
    // 0x80084584: addiu       $v0, $a3, 0x80
    ctx->r2 = ADD32(ctx->r7, 0X80);
    // 0x80084588: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x8008458C: sltiu       $v0, $v0, 0x2
    ctx->r2 = ctx->r2 < 0X2 ? 1 : 0;
    // 0x80084590: beq         $v0, $zero, L_800845D4
    if (ctx->r2 == 0) {
        // 0x80084594: sll         $v0, $a2, 4
        ctx->r2 = S32(ctx->r6 << 4);
            goto L_800845D4;
    }
    // 0x80084594: sll         $v0, $a2, 4
    ctx->r2 = S32(ctx->r6 << 4);
    // 0x80084598: lui         $v1, 0x8014
    ctx->r3 = S32(0X8014 << 16);
    // 0x8008459C: addiu       $v1, $v1, 0x40C8
    ctx->r3 = ADD32(ctx->r3, 0X40C8);
    // 0x800845A0: addu        $v0, $v0, $a2
    ctx->r2 = ADD32(ctx->r2, ctx->r6);
    // 0x800845A4: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800845A8: subu        $v0, $v0, $a2
    ctx->r2 = SUB32(ctx->r2, ctx->r6);
    // 0x800845AC: sll         $v0, $v0, 5
    ctx->r2 = S32(ctx->r2 << 5);
    // 0x800845B0: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800845B4: andi        $a0, $a1, 0xFF
    ctx->r4 = ctx->r5 & 0XFF;
    // 0x800845B8: sll         $v1, $a0, 4
    ctx->r3 = S32(ctx->r4 << 4);
    // 0x800845BC: addu        $v1, $v1, $a0
    ctx->r3 = ADD32(ctx->r3, ctx->r4);
    // 0x800845C0: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x800845C4: subu        $v1, $v1, $a0
    ctx->r3 = SUB32(ctx->r3, ctx->r4);
    // 0x800845C8: sll         $v1, $v1, 1
    ctx->r3 = S32(ctx->r3 << 1);
    // 0x800845CC: j           L_800846F4
    // 0x800845D0: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
        goto L_800846F4;
    // 0x800845D0: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
L_800845D4:
    // 0x800845D4: sltiu       $v0, $t0, 0x46
    ctx->r2 = ctx->r8 < 0X46 ? 1 : 0;
    // 0x800845D8: beq         $v0, $zero, L_80084620
    if (ctx->r2 == 0) {
        // 0x800845DC: sll         $v1, $a2, 4
        ctx->r3 = S32(ctx->r6 << 4);
            goto L_80084620;
    }
    // 0x800845DC: sll         $v1, $a2, 4
    ctx->r3 = S32(ctx->r6 << 4);
    // 0x800845E0: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x800845E4: addiu       $v0, $v0, 0x40C8
    ctx->r2 = ADD32(ctx->r2, 0X40C8);
    // 0x800845E8: addu        $v1, $v1, $a2
    ctx->r3 = ADD32(ctx->r3, ctx->r6);
    // 0x800845EC: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x800845F0: subu        $v1, $v1, $a2
    ctx->r3 = SUB32(ctx->r3, ctx->r6);
    // 0x800845F4: sll         $v1, $v1, 5
    ctx->r3 = S32(ctx->r3 << 5);
    // 0x800845F8: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x800845FC: andi        $a0, $a1, 0xFF
    ctx->r4 = ctx->r5 & 0XFF;
    // 0x80084600: sll         $v0, $a0, 4
    ctx->r2 = S32(ctx->r4 << 4);
    // 0x80084604: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x80084608: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8008460C: subu        $v0, $v0, $a0
    ctx->r2 = SUB32(ctx->r2, ctx->r4);
    // 0x80084610: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x80084614: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80084618: j           L_80084740
    // 0x8008461C: addu        $v0, $v0, $t0
    ctx->r2 = ADD32(ctx->r2, ctx->r8);
        goto L_80084740;
    // 0x8008461C: addu        $v0, $v0, $t0
    ctx->r2 = ADD32(ctx->r2, ctx->r8);
L_80084620:
    // 0x80084620: addiu       $v0, $a3, -0x60
    ctx->r2 = ADD32(ctx->r7, -0X60);
    // 0x80084624: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x80084628: sltiu       $v0, $v0, 0x6
    ctx->r2 = ctx->r2 < 0X6 ? 1 : 0;
    // 0x8008462C: bnel        $v0, $zero, L_8008479C
    if (ctx->r2 != 0) {
        // 0x80084630: addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
            goto L_8008479C;
    }
    goto skip_0;
    // 0x80084630: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    skip_0:
    // 0x80084634: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x80084638: addiu       $v0, $v0, 0x40C8
    ctx->r2 = ADD32(ctx->r2, 0X40C8);
    // 0x8008463C: sll         $v1, $a2, 4
    ctx->r3 = S32(ctx->r6 << 4);
    // 0x80084640: addu        $v1, $v1, $a2
    ctx->r3 = ADD32(ctx->r3, ctx->r6);
    // 0x80084644: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x80084648: subu        $v1, $v1, $a2
    ctx->r3 = SUB32(ctx->r3, ctx->r6);
    // 0x8008464C: sll         $v1, $v1, 5
    ctx->r3 = S32(ctx->r3 << 5);
    // 0x80084650: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x80084654: andi        $a0, $a1, 0xFF
    ctx->r4 = ctx->r5 & 0XFF;
    // 0x80084658: sll         $v0, $a0, 4
    ctx->r2 = S32(ctx->r4 << 4);
    // 0x8008465C: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x80084660: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80084664: subu        $v0, $v0, $a0
    ctx->r2 = SUB32(ctx->r2, ctx->r4);
    // 0x80084668: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x8008466C: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80084670: j           L_80084794
    // 0x80084674: addu        $v0, $v0, $t0
    ctx->r2 = ADD32(ctx->r2, ctx->r8);
        goto L_80084794;
    // 0x80084674: addu        $v0, $v0, $t0
    ctx->r2 = ADD32(ctx->r2, ctx->r8);
L_80084678:
    // 0x80084678: andi        $a2, $v1, 0xFF
    ctx->r6 = ctx->r3 & 0XFF;
    // 0x8008467C: sltiu       $v0, $a2, 0x40
    ctx->r2 = ctx->r6 < 0X40 ? 1 : 0;
    // 0x80084680: beq         $v0, $zero, L_800846C0
    if (ctx->r2 == 0) {
        // 0x80084684: andi        $v0, $a1, 0xFF
        ctx->r2 = ctx->r5 & 0XFF;
            goto L_800846C0;
    }
    // 0x80084684: andi        $v0, $a1, 0xFF
    ctx->r2 = ctx->r5 & 0XFF;
    // 0x80084688: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8008468C: addiu       $a0, $a0, 0xA10
    ctx->r4 = ADD32(ctx->r4, 0XA10);
    // 0x80084690: sll         $v1, $v0, 4
    ctx->r3 = S32(ctx->r2 << 4);
    // 0x80084694: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x80084698: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x8008469C: subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // 0x800846A0: sll         $v1, $v1, 1
    ctx->r3 = S32(ctx->r3 << 1);
    // 0x800846A4: addu        $v1, $v1, $a0
    ctx->r3 = ADD32(ctx->r3, ctx->r4);
    // 0x800846A8: andi        $v0, $a3, 0x1F
    ctx->r2 = ctx->r7 & 0X1F;
    // 0x800846AC: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x800846B0: lbu         $v0, 0x0($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X0);
    // 0x800846B4: lbu         $v1, 0x20($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X20);
    // 0x800846B8: j           L_80084708
    // 0x800846BC: sll         $v0, $v0, 7
    ctx->r2 = S32(ctx->r2 << 7);
        goto L_80084708;
    // 0x800846BC: sll         $v0, $v0, 7
    ctx->r2 = S32(ctx->r2 << 7);
L_800846C0:
    // 0x800846C0: addiu       $v0, $a3, 0x80
    ctx->r2 = ADD32(ctx->r7, 0X80);
    // 0x800846C4: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x800846C8: sltiu       $v0, $v0, 0x2
    ctx->r2 = ctx->r2 < 0X2 ? 1 : 0;
    // 0x800846CC: beq         $v0, $zero, L_80084710
    if (ctx->r2 == 0) {
        // 0x800846D0: andi        $v0, $a1, 0xFF
        ctx->r2 = ctx->r5 & 0XFF;
            goto L_80084710;
    }
    // 0x800846D0: andi        $v0, $a1, 0xFF
    ctx->r2 = ctx->r5 & 0XFF;
    // 0x800846D4: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x800846D8: addiu       $a0, $a0, 0xA10
    ctx->r4 = ADD32(ctx->r4, 0XA10);
    // 0x800846DC: sll         $v1, $v0, 4
    ctx->r3 = S32(ctx->r2 << 4);
    // 0x800846E0: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x800846E4: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x800846E8: subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // 0x800846EC: sll         $v1, $v1, 1
    ctx->r3 = S32(ctx->r3 << 1);
    // 0x800846F0: addu        $v1, $v1, $a0
    ctx->r3 = ADD32(ctx->r3, ctx->r4);
L_800846F4:
    // 0x800846F4: andi        $v0, $a3, 0xFE
    ctx->r2 = ctx->r7 & 0XFE;
    // 0x800846F8: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x800846FC: lbu         $v0, 0x0($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X0);
    // 0x80084700: lbu         $v1, 0x1($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X1);
    // 0x80084704: sll         $v0, $v0, 7
    ctx->r2 = S32(ctx->r2 << 7);
L_80084708:
    // 0x80084708: j           L_8008479C
    // 0x8008470C: or          $v0, $v1, $v0
    ctx->r2 = ctx->r3 | ctx->r2;
        goto L_8008479C;
    // 0x8008470C: or          $v0, $v1, $v0
    ctx->r2 = ctx->r3 | ctx->r2;
L_80084710:
    // 0x80084710: sltiu       $v0, $a2, 0x46
    ctx->r2 = ctx->r6 < 0X46 ? 1 : 0;
    // 0x80084714: beq         $v0, $zero, L_80084758
    if (ctx->r2 == 0) {
        // 0x80084718: andi        $v1, $a1, 0xFF
        ctx->r3 = ctx->r5 & 0XFF;
            goto L_80084758;
    }
    // 0x80084718: andi        $v1, $a1, 0xFF
    ctx->r3 = ctx->r5 & 0XFF;
    // 0x8008471C: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80084720: addiu       $a0, $a0, 0xA10
    ctx->r4 = ADD32(ctx->r4, 0XA10);
    // 0x80084724: sll         $v0, $v1, 4
    ctx->r2 = S32(ctx->r3 << 4);
    // 0x80084728: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8008472C: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80084730: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x80084734: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x80084738: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x8008473C: addu        $v0, $v0, $a2
    ctx->r2 = ADD32(ctx->r2, ctx->r6);
L_80084740:
    // 0x80084740: lbu         $v0, 0x0($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X0);
    // 0x80084744: sltiu       $v0, $v0, 0x40
    ctx->r2 = ctx->r2 < 0X40 ? 1 : 0;
    // 0x80084748: xori        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 ^ 0X1;
    // 0x8008474C: negu        $v0, $v0
    ctx->r2 = SUB32(0, ctx->r2);
    // 0x80084750: j           L_8008479C
    // 0x80084754: andi        $v0, $v0, 0x3FFF
    ctx->r2 = ctx->r2 & 0X3FFF;
        goto L_8008479C;
    // 0x80084754: andi        $v0, $v0, 0x3FFF
    ctx->r2 = ctx->r2 & 0X3FFF;
L_80084758:
    // 0x80084758: addiu       $v0, $a3, -0x60
    ctx->r2 = ADD32(ctx->r7, -0X60);
    // 0x8008475C: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x80084760: sltiu       $v0, $v0, 0x6
    ctx->r2 = ctx->r2 < 0X6 ? 1 : 0;
    // 0x80084764: bnel        $v0, $zero, L_8008479C
    if (ctx->r2 != 0) {
        // 0x80084768: addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
            goto L_8008479C;
    }
    goto skip_1;
    // 0x80084768: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    skip_1:
    // 0x8008476C: andi        $v1, $a1, 0xFF
    ctx->r3 = ctx->r5 & 0XFF;
    // 0x80084770: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80084774: addiu       $a0, $a0, 0xA10
    ctx->r4 = ADD32(ctx->r4, 0XA10);
    // 0x80084778: sll         $v0, $v1, 4
    ctx->r2 = S32(ctx->r3 << 4);
    // 0x8008477C: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80084780: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80084784: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x80084788: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x8008478C: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x80084790: addu        $v0, $v0, $a2
    ctx->r2 = ADD32(ctx->r2, ctx->r6);
L_80084794:
    // 0x80084794: lbu         $v0, 0x0($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X0);
    // 0x80084798: sll         $v0, $v0, 7
    ctx->r2 = S32(ctx->r2 << 7);
L_8008479C:
    // 0x8008479C: jr          $ra
    // 0x800847A0: nop

    return;
    // 0x800847A0: nop

;}
RECOMP_FUNC void func_800847A4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800847A4: addiu       $v0, $zero, 0x7
    ctx->r2 = ADD32(0, 0X7);
    // 0x800847A8: addiu       $a1, $zero, 0x100
    ctx->r5 = ADD32(0, 0X100);
    // 0x800847AC: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x800847B0: sb          $v0, 0xC0($a0)
    MEM_B(0XC0, ctx->r4) = ctx->r2;
    // 0x800847B4: addiu       $v0, $zero, 0xA
    ctx->r2 = ADD32(0, 0XA);
    // 0x800847B8: sb          $v0, 0xD2($a0)
    MEM_B(0XD2, ctx->r4) = ctx->r2;
    // 0x800847BC: addiu       $v0, $zero, 0x83
    ctx->r2 = ADD32(0, 0X83);
    // 0x800847C0: sb          $v0, 0xE4($a0)
    MEM_B(0XE4, ctx->r4) = ctx->r2;
    // 0x800847C4: addiu       $v0, $zero, 0x80
    ctx->r2 = ADD32(0, 0X80);
    // 0x800847C8: sb          $v0, 0xF6($a0)
    MEM_B(0XF6, ctx->r4) = ctx->r2;
    // 0x800847CC: addiu       $v0, $zero, 0x40
    ctx->r2 = ADD32(0, 0X40);
    // 0x800847D0: sb          $v0, 0x12C($a0)
    MEM_B(0X12C, ctx->r4) = ctx->r2;
    // 0x800847D4: addiu       $v0, $zero, 0x41
    ctx->r2 = ADD32(0, 0X41);
    // 0x800847D8: sb          $v0, 0x13E($a0)
    MEM_B(0X13E, ctx->r4) = ctx->r2;
    // 0x800847DC: addiu       $v0, $zero, 0x5B
    ctx->r2 = ADD32(0, 0X5B);
    // 0x800847E0: sb          $v0, 0x150($a0)
    MEM_B(0X150, ctx->r4) = ctx->r2;
    // 0x800847E4: addiu       $v0, $zero, 0x84
    ctx->r2 = ADD32(0, 0X84);
    // 0x800847E8: sb          $zero, 0xC1($a0)
    MEM_B(0XC1, ctx->r4) = 0;
    // 0x800847EC: sh          $a1, 0xC2($a0)
    MEM_H(0XC2, ctx->r4) = ctx->r5;
    // 0x800847F0: sb          $v1, 0xD0($a0)
    MEM_B(0XD0, ctx->r4) = ctx->r3;
    // 0x800847F4: sb          $zero, 0xD3($a0)
    MEM_B(0XD3, ctx->r4) = 0;
    // 0x800847F8: sh          $a1, 0xD4($a0)
    MEM_H(0XD4, ctx->r4) = ctx->r5;
    // 0x800847FC: sb          $v1, 0xE2($a0)
    MEM_B(0XE2, ctx->r4) = ctx->r3;
    // 0x80084800: sb          $zero, 0xE5($a0)
    MEM_B(0XE5, ctx->r4) = 0;
    // 0x80084804: sh          $a1, 0xE6($a0)
    MEM_H(0XE6, ctx->r4) = ctx->r5;
    // 0x80084808: sb          $v1, 0xF4($a0)
    MEM_B(0XF4, ctx->r4) = ctx->r3;
    // 0x8008480C: sb          $zero, 0xF7($a0)
    MEM_B(0XF7, ctx->r4) = 0;
    // 0x80084810: sh          $a1, 0xF8($a0)
    MEM_H(0XF8, ctx->r4) = ctx->r5;
    // 0x80084814: sb          $v1, 0x106($a0)
    MEM_B(0X106, ctx->r4) = ctx->r3;
    // 0x80084818: sb          $v1, 0x11A($a0)
    MEM_B(0X11A, ctx->r4) = ctx->r3;
    // 0x8008481C: sb          $zero, 0x11B($a0)
    MEM_B(0X11B, ctx->r4) = 0;
    // 0x80084820: sh          $a1, 0x11C($a0)
    MEM_H(0X11C, ctx->r4) = ctx->r5;
    // 0x80084824: sb          $v1, 0x12A($a0)
    MEM_B(0X12A, ctx->r4) = ctx->r3;
    // 0x80084828: sb          $zero, 0x12D($a0)
    MEM_B(0X12D, ctx->r4) = 0;
    // 0x8008482C: sh          $a1, 0x12E($a0)
    MEM_H(0X12E, ctx->r4) = ctx->r5;
    // 0x80084830: sb          $v1, 0x13C($a0)
    MEM_B(0X13C, ctx->r4) = ctx->r3;
    // 0x80084834: sb          $zero, 0x13F($a0)
    MEM_B(0X13F, ctx->r4) = 0;
    // 0x80084838: sh          $a1, 0x140($a0)
    MEM_H(0X140, ctx->r4) = ctx->r5;
    // 0x8008483C: sb          $v1, 0x14E($a0)
    MEM_B(0X14E, ctx->r4) = ctx->r3;
    // 0x80084840: sb          $zero, 0x151($a0)
    MEM_B(0X151, ctx->r4) = 0;
    // 0x80084844: sh          $a1, 0x152($a0)
    MEM_H(0X152, ctx->r4) = ctx->r5;
    // 0x80084848: sb          $v1, 0x160($a0)
    MEM_B(0X160, ctx->r4) = ctx->r3;
    // 0x8008484C: sb          $v0, 0x108($a0)
    MEM_B(0X108, ctx->r4) = ctx->r2;
    // 0x80084850: sb          $zero, 0x109($a0)
    MEM_B(0X109, ctx->r4) = 0;
    // 0x80084854: sh          $a1, 0x10A($a0)
    MEM_H(0X10A, ctx->r4) = ctx->r5;
    // 0x80084858: jr          $ra
    // 0x8008485C: sb          $v1, 0x118($a0)
    MEM_B(0X118, ctx->r4) = ctx->r3;
    return;
    // 0x8008485C: sb          $v1, 0x118($a0)
    MEM_B(0X118, ctx->r4) = ctx->r3;
;}
RECOMP_FUNC void func_80084860(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084860: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80084864: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80084868: addu        $s2, $a0, $zero
    ctx->r18 = ADD32(ctx->r4, 0);
    // 0x8008486C: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x80084870: addu        $s4, $a1, $zero
    ctx->r20 = ADD32(ctx->r5, 0);
    // 0x80084874: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x80084878: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x8008487C: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x80084880: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x80084884: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80084888: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8008488C: lbu         $v0, 0x10($s4)
    ctx->r2 = MEM_BU(ctx->r20, 0X10);
    // 0x80084890: addu        $s3, $zero, $zero
    ctx->r19 = ADD32(0, 0);
    // 0x80084894: beq         $v0, $zero, L_80084AB8
    if (ctx->r2 == 0) {
        // 0x80084898: addu        $s0, $zero, $zero
        ctx->r16 = ADD32(0, 0);
            goto L_80084AB8;
    }
    // 0x80084898: addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
    // 0x8008489C: addiu       $s6, $zero, 0x1
    ctx->r22 = ADD32(0, 0X1);
    // 0x800848A0: addiu       $s5, $zero, 0x2
    ctx->r21 = ADD32(0, 0X2);
    // 0x800848A4: addu        $s1, $s4, $zero
    ctx->r17 = ADD32(ctx->r20, 0);
L_800848A8:
    // 0x800848A8: lbu         $a3, 0x0($s1)
    ctx->r7 = MEM_BU(ctx->r17, 0X0);
    // 0x800848AC: andi        $a0, $a3, 0xFF
    ctx->r4 = ctx->r7 & 0XFF;
    // 0x800848B0: xori        $v1, $a0, 0x80
    ctx->r3 = ctx->r4 ^ 0X80;
    // 0x800848B4: sltiu       $v1, $v1, 0x1
    ctx->r3 = ctx->r3 < 0X1 ? 1 : 0;
    // 0x800848B8: xori        $v0, $a0, 0x1
    ctx->r2 = ctx->r4 ^ 0X1;
    // 0x800848BC: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x800848C0: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x800848C4: bne         $v1, $zero, L_80084910
    if (ctx->r3 != 0) {
        // 0x800848C8: andi        $v1, $a3, 0xFF
        ctx->r3 = ctx->r7 & 0XFF;
            goto L_80084910;
    }
    // 0x800848C8: andi        $v1, $a3, 0xFF
    ctx->r3 = ctx->r7 & 0XFF;
    // 0x800848CC: xori        $v1, $a0, 0xA
    ctx->r3 = ctx->r4 ^ 0XA;
    // 0x800848D0: sltiu       $v1, $v1, 0x1
    ctx->r3 = ctx->r3 < 0X1 ? 1 : 0;
    // 0x800848D4: xori        $v0, $a0, 0xA0
    ctx->r2 = ctx->r4 ^ 0XA0;
    // 0x800848D8: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x800848DC: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x800848E0: bne         $v1, $zero, L_80084910
    if (ctx->r3 != 0) {
        // 0x800848E4: andi        $v1, $a3, 0xFF
        ctx->r3 = ctx->r7 & 0XFF;
            goto L_80084910;
    }
    // 0x800848E4: andi        $v1, $a3, 0xFF
    ctx->r3 = ctx->r7 & 0XFF;
    // 0x800848E8: xori        $v1, $a0, 0xA1
    ctx->r3 = ctx->r4 ^ 0XA1;
    // 0x800848EC: sltiu       $v1, $v1, 0x1
    ctx->r3 = ctx->r3 < 0X1 ? 1 : 0;
    // 0x800848F0: xori        $v0, $a0, 0x83
    ctx->r2 = ctx->r4 ^ 0X83;
    // 0x800848F4: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x800848F8: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x800848FC: bne         $v1, $zero, L_80084910
    if (ctx->r3 != 0) {
        // 0x80084900: andi        $v1, $a3, 0xFF
        ctx->r3 = ctx->r7 & 0XFF;
            goto L_80084910;
    }
    // 0x80084900: andi        $v1, $a3, 0xFF
    ctx->r3 = ctx->r7 & 0XFF;
    // 0x80084904: addiu       $v0, $zero, 0x84
    ctx->r2 = ADD32(0, 0X84);
    // 0x80084908: bne         $a0, $v0, L_80084A14
    if (ctx->r4 != ctx->r2) {
        // 0x8008490C: nop
    
            goto L_80084A14;
    }
    // 0x8008490C: nop

L_80084910:
    // 0x80084910: addiu       $v0, $zero, 0xA0
    ctx->r2 = ADD32(0, 0XA0);
    // 0x80084914: beq         $v1, $v0, L_80084930
    if (ctx->r3 == ctx->r2) {
        // 0x80084918: addiu       $s0, $s0, -0x2000
        ctx->r16 = ADD32(ctx->r16, -0X2000);
            goto L_80084930;
    }
    // 0x80084918: addiu       $s0, $s0, -0x2000
    ctx->r16 = ADD32(ctx->r16, -0X2000);
    // 0x8008491C: addiu       $v0, $zero, 0xA1
    ctx->r2 = ADD32(0, 0XA1);
    // 0x80084920: beq         $v1, $v0, L_8008493C
    if (ctx->r3 == ctx->r2) {
        // 0x80084924: nop
    
            goto L_8008493C;
    }
    // 0x80084924: nop

    // 0x80084928: j           L_80084948
    // 0x8008492C: nop

        goto L_80084948;
    // 0x8008492C: nop

L_80084930:
    // 0x80084930: lh          $v0, 0x16C($s2)
    ctx->r2 = MEM_H(ctx->r18, 0X16C);
    // 0x80084934: j           L_80084960
    // 0x80084938: sll         $v1, $v0, 1
    ctx->r3 = S32(ctx->r2 << 1);
        goto L_80084960;
    // 0x80084938: sll         $v1, $v0, 1
    ctx->r3 = S32(ctx->r2 << 1);
L_8008493C:
    // 0x8008493C: lh          $v0, 0x178($s2)
    ctx->r2 = MEM_H(ctx->r18, 0X178);
    // 0x80084940: j           L_80084960
    // 0x80084944: sll         $v1, $v0, 1
    ctx->r3 = S32(ctx->r2 << 1);
        goto L_80084960;
    // 0x80084944: sll         $v1, $v0, 1
    ctx->r3 = S32(ctx->r2 << 1);
L_80084948:
    // 0x80084948: lbu         $a1, 0x4E($s2)
    ctx->r5 = MEM_BU(ctx->r18, 0X4E);
    // 0x8008494C: lbu         $a2, 0x4F($s2)
    ctx->r6 = MEM_BU(ctx->r18, 0X4F);
    // 0x80084950: jal         0x80084510
    // 0x80084954: addu        $a0, $a3, $zero
    ctx->r4 = ADD32(ctx->r7, 0);
    func_80084510(rdram, ctx);
        goto after_0;
    // 0x80084954: addu        $a0, $a3, $zero
    ctx->r4 = ADD32(ctx->r7, 0);
    after_0:
    // 0x80084958: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x8008495C: addiu       $v1, $v0, -0x2000
    ctx->r3 = ADD32(ctx->r2, -0X2000);
L_80084960:
    // 0x80084960: lh          $v0, 0x2($s1)
    ctx->r2 = MEM_H(ctx->r17, 0X2);
    // 0x80084964: mult        $v1, $v0
    result = S64(S32(ctx->r3)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80084968: mflo        $v0
    ctx->r2 = lo;
    // 0x8008496C: sra         $v1, $v0, 8
    ctx->r3 = S32(SIGNED(ctx->r2) >> 8);
    // 0x80084970: slti        $v0, $v1, -0x2000
    ctx->r2 = SIGNED(ctx->r3) < -0X2000 ? 1 : 0;
    // 0x80084974: beq         $v0, $zero, L_80084984
    if (ctx->r2 == 0) {
        // 0x80084978: slti        $v0, $v1, 0x2000
        ctx->r2 = SIGNED(ctx->r3) < 0X2000 ? 1 : 0;
            goto L_80084984;
    }
    // 0x80084978: slti        $v0, $v1, 0x2000
    ctx->r2 = SIGNED(ctx->r3) < 0X2000 ? 1 : 0;
    // 0x8008497C: j           L_80084990
    // 0x80084980: addiu       $a1, $zero, -0x2000
    ctx->r5 = ADD32(0, -0X2000);
        goto L_80084990;
    // 0x80084980: addiu       $a1, $zero, -0x2000
    ctx->r5 = ADD32(0, -0X2000);
L_80084984:
    // 0x80084984: beq         $v0, $zero, L_80084990
    if (ctx->r2 == 0) {
        // 0x80084988: addiu       $a1, $zero, 0x1FFF
        ctx->r5 = ADD32(0, 0X1FFF);
            goto L_80084990;
    }
    // 0x80084988: addiu       $a1, $zero, 0x1FFF
    ctx->r5 = ADD32(0, 0X1FFF);
    // 0x8008498C: addu        $a1, $v1, $zero
    ctx->r5 = ADD32(ctx->r3, 0);
L_80084990:
    // 0x80084990: lbu         $a0, 0x1($s1)
    ctx->r4 = MEM_BU(ctx->r17, 0X1);
    // 0x80084994: beq         $a0, $s6, L_800849C8
    if (ctx->r4 == ctx->r22) {
        // 0x80084998: addu        $v1, $a1, $zero
        ctx->r3 = ADD32(ctx->r5, 0);
            goto L_800849C8;
    }
    // 0x80084998: addu        $v1, $a1, $zero
    ctx->r3 = ADD32(ctx->r5, 0);
    // 0x8008499C: slti        $v0, $a0, 0x2
    ctx->r2 = SIGNED(ctx->r4) < 0X2 ? 1 : 0;
    // 0x800849A0: beq         $v0, $zero, L_800849B8
    if (ctx->r2 == 0) {
        // 0x800849A4: nop
    
            goto L_800849B8;
    }
    // 0x800849A4: nop

    // 0x800849A8: beql        $a0, $zero, L_80084A0C
    if (ctx->r4 == 0) {
        // 0x800849AC: addu        $s0, $v1, $zero
        ctx->r16 = ADD32(ctx->r3, 0);
            goto L_80084A0C;
    }
    goto skip_0;
    // 0x800849AC: addu        $s0, $v1, $zero
    ctx->r16 = ADD32(ctx->r3, 0);
    skip_0:
    // 0x800849B0: j           L_80084AA4
    // 0x800849B4: addiu       $s0, $s0, 0x2000
    ctx->r16 = ADD32(ctx->r16, 0X2000);
        goto L_80084AA4;
    // 0x800849B4: addiu       $s0, $s0, 0x2000
    ctx->r16 = ADD32(ctx->r16, 0X2000);
L_800849B8:
    // 0x800849B8: beq         $a0, $s5, L_800849E0
    if (ctx->r4 == ctx->r21) {
        // 0x800849BC: nop
    
            goto L_800849E0;
    }
    // 0x800849BC: nop

    // 0x800849C0: j           L_80084AA4
    // 0x800849C4: addiu       $s0, $s0, 0x2000
    ctx->r16 = ADD32(ctx->r16, 0X2000);
        goto L_80084AA4;
    // 0x800849C4: addiu       $s0, $s0, 0x2000
    ctx->r16 = ADD32(ctx->r16, 0X2000);
L_800849C8:
    // 0x800849C8: addu        $s0, $s0, $v1
    ctx->r16 = ADD32(ctx->r16, ctx->r3);
    // 0x800849CC: slti        $v0, $s0, -0x2000
    ctx->r2 = SIGNED(ctx->r16) < -0X2000 ? 1 : 0;
    // 0x800849D0: beq         $v0, $zero, L_800849FC
    if (ctx->r2 == 0) {
        // 0x800849D4: slti        $v0, $s0, 0x2000
        ctx->r2 = SIGNED(ctx->r16) < 0X2000 ? 1 : 0;
            goto L_800849FC;
    }
    // 0x800849D4: slti        $v0, $s0, 0x2000
    ctx->r2 = SIGNED(ctx->r16) < 0X2000 ? 1 : 0;
    // 0x800849D8: j           L_80084A08
    // 0x800849DC: addiu       $v1, $zero, -0x2000
    ctx->r3 = ADD32(0, -0X2000);
        goto L_80084A08;
    // 0x800849DC: addiu       $v1, $zero, -0x2000
    ctx->r3 = ADD32(0, -0X2000);
L_800849E0:
    // 0x800849E0: mult        $s0, $v1
    result = S64(S32(ctx->r16)) * S64(S32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800849E4: mflo        $v0
    ctx->r2 = lo;
    // 0x800849E8: sra         $s0, $v0, 13
    ctx->r16 = S32(SIGNED(ctx->r2) >> 13);
    // 0x800849EC: slti        $v0, $s0, -0x2000
    ctx->r2 = SIGNED(ctx->r16) < -0X2000 ? 1 : 0;
    // 0x800849F0: bnel        $v0, $zero, L_80084A08
    if (ctx->r2 != 0) {
        // 0x800849F4: addiu       $v1, $zero, -0x2000
        ctx->r3 = ADD32(0, -0X2000);
            goto L_80084A08;
    }
    goto skip_1;
    // 0x800849F4: addiu       $v1, $zero, -0x2000
    ctx->r3 = ADD32(0, -0X2000);
    skip_1:
    // 0x800849F8: slti        $v0, $s0, 0x2000
    ctx->r2 = SIGNED(ctx->r16) < 0X2000 ? 1 : 0;
L_800849FC:
    // 0x800849FC: beq         $v0, $zero, L_80084A08
    if (ctx->r2 == 0) {
        // 0x80084A00: addiu       $v1, $zero, 0x1FFF
        ctx->r3 = ADD32(0, 0X1FFF);
            goto L_80084A08;
    }
    // 0x80084A00: addiu       $v1, $zero, 0x1FFF
    ctx->r3 = ADD32(0, 0X1FFF);
    // 0x80084A04: addu        $v1, $s0, $zero
    ctx->r3 = ADD32(ctx->r16, 0);
L_80084A08:
    // 0x80084A08: addu        $s0, $v1, $zero
    ctx->r16 = ADD32(ctx->r3, 0);
L_80084A0C:
    // 0x80084A0C: j           L_80084AA4
    // 0x80084A10: addiu       $s0, $s0, 0x2000
    ctx->r16 = ADD32(ctx->r16, 0X2000);
        goto L_80084AA4;
    // 0x80084A10: addiu       $s0, $s0, 0x2000
    ctx->r16 = ADD32(ctx->r16, 0X2000);
L_80084A14:
    // 0x80084A14: lbu         $a1, 0x4E($s2)
    ctx->r5 = MEM_BU(ctx->r18, 0X4E);
    // 0x80084A18: lbu         $a2, 0x4F($s2)
    ctx->r6 = MEM_BU(ctx->r18, 0X4F);
    // 0x80084A1C: jal         0x80084510
    // 0x80084A20: nop

    func_80084510(rdram, ctx);
        goto after_1;
    // 0x80084A20: nop

    after_1:
    // 0x80084A24: lh          $v1, 0x2($s1)
    ctx->r3 = MEM_H(ctx->r17, 0X2);
    // 0x80084A28: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x80084A2C: mult        $v0, $v1
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80084A30: mflo        $v0
    ctx->r2 = lo;
    // 0x80084A34: sra         $v1, $v0, 8
    ctx->r3 = S32(SIGNED(ctx->r2) >> 8);
    // 0x80084A38: slti        $v0, $v1, 0x4000
    ctx->r2 = SIGNED(ctx->r3) < 0X4000 ? 1 : 0;
    // 0x80084A3C: beql        $v0, $zero, L_80084A44
    if (ctx->r2 == 0) {
        // 0x80084A40: addiu       $v1, $zero, 0x3FFF
        ctx->r3 = ADD32(0, 0X3FFF);
            goto L_80084A44;
    }
    goto skip_2;
    // 0x80084A40: addiu       $v1, $zero, 0x3FFF
    ctx->r3 = ADD32(0, 0X3FFF);
    skip_2:
L_80084A44:
    // 0x80084A44: lbu         $a0, 0x1($s1)
    ctx->r4 = MEM_BU(ctx->r17, 0X1);
    // 0x80084A48: beq         $a0, $s6, L_80084A78
    if (ctx->r4 == ctx->r22) {
        // 0x80084A4C: slti        $v0, $a0, 0x2
        ctx->r2 = SIGNED(ctx->r4) < 0X2 ? 1 : 0;
            goto L_80084A78;
    }
    // 0x80084A4C: slti        $v0, $a0, 0x2
    ctx->r2 = SIGNED(ctx->r4) < 0X2 ? 1 : 0;
    // 0x80084A50: beq         $v0, $zero, L_80084A68
    if (ctx->r2 == 0) {
        // 0x80084A54: nop
    
            goto L_80084A68;
    }
    // 0x80084A54: nop

    // 0x80084A58: beql        $a0, $zero, L_80084AA4
    if (ctx->r4 == 0) {
        // 0x80084A5C: addu        $s0, $v1, $zero
        ctx->r16 = ADD32(ctx->r3, 0);
            goto L_80084AA4;
    }
    goto skip_3;
    // 0x80084A5C: addu        $s0, $v1, $zero
    ctx->r16 = ADD32(ctx->r3, 0);
    skip_3:
    // 0x80084A60: j           L_80084AA4
    // 0x80084A64: nop

        goto L_80084AA4;
    // 0x80084A64: nop

L_80084A68:
    // 0x80084A68: beq         $a0, $s5, L_80084A84
    if (ctx->r4 == ctx->r21) {
        // 0x80084A6C: nop
    
            goto L_80084A84;
    }
    // 0x80084A6C: nop

    // 0x80084A70: j           L_80084AA4
    // 0x80084A74: nop

        goto L_80084AA4;
    // 0x80084A74: nop

L_80084A78:
    // 0x80084A78: addu        $s0, $s0, $v1
    ctx->r16 = ADD32(ctx->r16, ctx->r3);
    // 0x80084A7C: j           L_80084A94
    // 0x80084A80: addiu       $v1, $zero, 0x3FFF
    ctx->r3 = ADD32(0, 0X3FFF);
        goto L_80084A94;
    // 0x80084A80: addiu       $v1, $zero, 0x3FFF
    ctx->r3 = ADD32(0, 0X3FFF);
L_80084A84:
    // 0x80084A84: mult        $s0, $v1
    result = S64(S32(ctx->r16)) * S64(S32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80084A88: mflo        $v0
    ctx->r2 = lo;
    // 0x80084A8C: addiu       $v1, $zero, 0x3FFF
    ctx->r3 = ADD32(0, 0X3FFF);
    // 0x80084A90: srl         $s0, $v0, 14
    ctx->r16 = S32(U32(ctx->r2) >> 14);
L_80084A94:
    // 0x80084A94: sltiu       $v0, $s0, 0x4000
    ctx->r2 = ctx->r16 < 0X4000 ? 1 : 0;
    // 0x80084A98: bnel        $v0, $zero, L_80084AA0
    if (ctx->r2 != 0) {
        // 0x80084A9C: addu        $v1, $s0, $zero
        ctx->r3 = ADD32(ctx->r16, 0);
            goto L_80084AA0;
    }
    goto skip_4;
    // 0x80084A9C: addu        $v1, $s0, $zero
    ctx->r3 = ADD32(ctx->r16, 0);
    skip_4:
L_80084AA0:
    // 0x80084AA0: addu        $s0, $v1, $zero
    ctx->r16 = ADD32(ctx->r3, 0);
L_80084AA4:
    // 0x80084AA4: lbu         $v0, 0x10($s4)
    ctx->r2 = MEM_BU(ctx->r20, 0X10);
    // 0x80084AA8: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x80084AAC: sltu        $v0, $s3, $v0
    ctx->r2 = ctx->r19 < ctx->r2 ? 1 : 0;
    // 0x80084AB0: bne         $v0, $zero, L_800848A8
    if (ctx->r2 != 0) {
        // 0x80084AB4: addiu       $s1, $s1, 0x4
        ctx->r17 = ADD32(ctx->r17, 0X4);
            goto L_800848A8;
    }
    // 0x80084AB4: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
L_80084AB8:
    // 0x80084AB8: andi        $v0, $s0, 0xFFFF
    ctx->r2 = ctx->r16 & 0XFFFF;
    // 0x80084ABC: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x80084AC0: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x80084AC4: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x80084AC8: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x80084ACC: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x80084AD0: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80084AD4: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80084AD8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80084ADC: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80084AE0: jr          $ra
    // 0x80084AE4: nop

    return;
    // 0x80084AE4: nop

;}
RECOMP_FUNC void func_80084AE8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084AE8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80084AEC: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x80084AF0: jal         0x80084860
    // 0x80084AF4: addiu       $a1, $a0, 0xC0
    ctx->r5 = ADD32(ctx->r4, 0XC0);
    func_80084860(rdram, ctx);
        goto after_0;
    // 0x80084AF4: addiu       $a1, $a0, 0xC0
    ctx->r5 = ADD32(ctx->r4, 0XC0);
    after_0:
    // 0x80084AF8: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x80084AFC: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x80084B00: jr          $ra
    // 0x80084B04: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80084B04: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_80084B08(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084B08: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80084B0C: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x80084B10: jal         0x80084860
    // 0x80084B14: addiu       $a1, $a0, 0xD2
    ctx->r5 = ADD32(ctx->r4, 0XD2);
    func_80084860(rdram, ctx);
        goto after_0;
    // 0x80084B14: addiu       $a1, $a0, 0xD2
    ctx->r5 = ADD32(ctx->r4, 0XD2);
    after_0:
    // 0x80084B18: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x80084B1C: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x80084B20: jr          $ra
    // 0x80084B24: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80084B24: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_80084B28(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084B28: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80084B2C: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x80084B30: jal         0x80084860
    // 0x80084B34: addiu       $a1, $a0, 0xE4
    ctx->r5 = ADD32(ctx->r4, 0XE4);
    func_80084860(rdram, ctx);
        goto after_0;
    // 0x80084B34: addiu       $a1, $a0, 0xE4
    ctx->r5 = ADD32(ctx->r4, 0XE4);
    after_0:
    // 0x80084B38: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x80084B3C: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x80084B40: jr          $ra
    // 0x80084B44: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80084B44: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_80084B48(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084B48: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80084B4C: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x80084B50: jal         0x80084860
    // 0x80084B54: addiu       $a1, $a0, 0xF6
    ctx->r5 = ADD32(ctx->r4, 0XF6);
    func_80084860(rdram, ctx);
        goto after_0;
    // 0x80084B54: addiu       $a1, $a0, 0xF6
    ctx->r5 = ADD32(ctx->r4, 0XF6);
    after_0:
    // 0x80084B58: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x80084B5C: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x80084B60: jr          $ra
    // 0x80084B64: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80084B64: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
