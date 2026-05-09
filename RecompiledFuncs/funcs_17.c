#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void func_8006C994(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006C994: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x8006C998: addiu       $v1, $v1, 0x7DB8
    ctx->r3 = ADD32(ctx->r3, 0X7DB8);
    // 0x8006C99C: sll         $v0, $a0, 2
    ctx->r2 = S32(ctx->r4 << 2);
    // 0x8006C9A0: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x8006C9A4: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8006C9A8: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x8006C9AC: sll         $v0, $v0, 5
    ctx->r2 = S32(ctx->r2 << 5);
    // 0x8006C9B0: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8006C9B4: lhu         $v0, 0x2($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X2);
    // 0x8006C9B8: jr          $ra
    // 0x8006C9BC: nop

    return;
    // 0x8006C9BC: nop

;}
RECOMP_FUNC void func_8006C9C0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006C9C0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8006C9C4: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x8006C9C8: addu        $s1, $a0, $zero
    ctx->r17 = ADD32(ctx->r4, 0);
    // 0x8006C9CC: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x8006C9D0: addu        $s0, $a1, $zero
    ctx->r16 = ADD32(ctx->r5, 0);
    // 0x8006C9D4: sw          $ra, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r31;
    // 0x8006C9D8: sdc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X20, ctx->r29);
    // 0x8006C9DC: lw          $a0, 0x30($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X30);
    // 0x8006C9E0: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8006C9E4: lwc1        $f20, 0x34($v0)
    ctx->f20.u32l = MEM_W(ctx->r2, 0X34);
    // 0x8006C9E8: jal         0x8005779C
    // 0x8006C9EC: nop

    func_8005779C(rdram, ctx);
        goto after_0;
    // 0x8006C9EC: nop

    after_0:
    // 0x8006C9F0: lw          $a0, 0x34($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X34);
    // 0x8006C9F4: lw          $v0, 0x90($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X90);
    // 0x8006C9F8: addiu       $v1, $v0, -0x1
    ctx->r3 = ADD32(ctx->r2, -0X1);
    // 0x8006C9FC: sltiu       $v0, $v1, 0x5
    ctx->r2 = ctx->r3 < 0X5 ? 1 : 0;
    // 0x8006CA00: beq         $v0, $zero, L_8006CA20
    if (ctx->r2 == 0) {
        // 0x8006CA04: lui         $v0, 0x8004
        ctx->r2 = S32(0X8004 << 16);
            goto L_8006CA20;
    }
    // 0x8006CA04: lui         $v0, 0x8004
    ctx->r2 = S32(0X8004 << 16);
    // 0x8006CA08: addiu       $v0, $v0, -0x3600
    ctx->r2 = ADD32(ctx->r2, -0X3600);
    // 0x8006CA0C: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x8006CA10: addu        $v1, $v1, $v0
    gpr jr_addend_8006CA18 = ctx->r3;
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x8006CA14: lw          $v0, 0x0($v1)
    ctx->r2 = ADD32(ctx->r3, 0X0);
    // 0x8006CA18: jr          $v0
    // 0x8006CA1C: nop

    switch (jr_addend_8006CA18 >> 2) {
        case 0: goto L_8006CA2C; break;
        case 1: goto L_8006CA38; break;
        case 2: goto L_8006CA44; break;
        case 3: goto L_8006CA50; break;
        case 4: goto L_8006CA5C; break;
        default: switch_error(__func__, 0x8006CA18, 0x8003CA00);
    }
    // 0x8006CA1C: nop

L_8006CA20:
    // 0x8006CA20: lw          $a0, 0x5C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5C);
    // 0x8006CA24: j           L_8006CA68
    // 0x8006CA28: nop

        goto L_8006CA68;
    // 0x8006CA28: nop

L_8006CA2C:
    // 0x8006CA2C: lui         $v0, 0x8004
    ctx->r2 = S32(0X8004 << 16);
    // 0x8006CA30: j           L_8006CA68
    // 0x8006CA34: addiu       $a0, $v0, -0x3630
    ctx->r4 = ADD32(ctx->r2, -0X3630);
        goto L_8006CA68;
    // 0x8006CA34: addiu       $a0, $v0, -0x3630
    ctx->r4 = ADD32(ctx->r2, -0X3630);
L_8006CA38:
    // 0x8006CA38: lui         $v0, 0x8004
    ctx->r2 = S32(0X8004 << 16);
    // 0x8006CA3C: j           L_8006CA68
    // 0x8006CA40: addiu       $a0, $v0, -0x3624
    ctx->r4 = ADD32(ctx->r2, -0X3624);
        goto L_8006CA68;
    // 0x8006CA40: addiu       $a0, $v0, -0x3624
    ctx->r4 = ADD32(ctx->r2, -0X3624);
L_8006CA44:
    // 0x8006CA44: lui         $v0, 0x8004
    ctx->r2 = S32(0X8004 << 16);
    // 0x8006CA48: j           L_8006CA68
    // 0x8006CA4C: addiu       $a0, $v0, -0x3618
    ctx->r4 = ADD32(ctx->r2, -0X3618);
        goto L_8006CA68;
    // 0x8006CA4C: addiu       $a0, $v0, -0x3618
    ctx->r4 = ADD32(ctx->r2, -0X3618);
L_8006CA50:
    // 0x8006CA50: lui         $v0, 0x8004
    ctx->r2 = S32(0X8004 << 16);
    // 0x8006CA54: j           L_8006CA68
    // 0x8006CA58: addiu       $a0, $v0, -0x360C
    ctx->r4 = ADD32(ctx->r2, -0X360C);
        goto L_8006CA68;
    // 0x8006CA58: addiu       $a0, $v0, -0x360C
    ctx->r4 = ADD32(ctx->r2, -0X360C);
L_8006CA5C:
    // 0x8006CA5C: sw          $zero, 0x30($s0)
    MEM_W(0X30, ctx->r16) = 0;
    // 0x8006CA60: j           L_8006CB98
    // 0x8006CA64: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
        goto L_8006CB98;
    // 0x8006CA64: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_8006CA68:
    // 0x8006CA68: jal         0x80056EB0
    // 0x8006CA6C: sw          $zero, 0xC($s1)
    MEM_W(0XC, ctx->r17) = 0;
    func_80056EB0(rdram, ctx);
        goto after_1;
    // 0x8006CA6C: sw          $zero, 0xC($s1)
    MEM_W(0XC, ctx->r17) = 0;
    after_1:
    // 0x8006CA70: lw          $v1, 0x34($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X34);
    // 0x8006CA74: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8006CA78: sw          $v0, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->r2;
    // 0x8006CA7C: lwc1        $f2, 0x94($v1)
    ctx->f2.u32l = MEM_W(ctx->r3, 0X94);
    // 0x8006CA80: c.eq.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl == ctx->f0.fl;
    // 0x8006CA84: nop

    // 0x8006CA88: bc1t        L_8006CAA4
    if (c1cs) {
        // 0x8006CA8C: addiu       $a0, $v0, 0x28
        ctx->r4 = ADD32(ctx->r2, 0X28);
            goto L_8006CAA4;
    }
    // 0x8006CA8C: addiu       $a0, $v0, 0x28
    ctx->r4 = ADD32(ctx->r2, 0X28);
    // 0x8006CA90: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8006CA94: lwc1        $f0, -0x35EC($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X35EC);
    // 0x8006CA98: mul.s       $f6, $f2, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x8006CA9C: j           L_8006CAAC
    // 0x8006CAA0: nop

        goto L_8006CAAC;
    // 0x8006CAA0: nop

L_8006CAA4:
    // 0x8006CAA4: lwc1        $f0, 0x28($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X28);
    // 0x8006CAA8: mul.s       $f6, $f0, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f20.fl);
L_8006CAAC:
    // 0x8006CAAC: lw          $v1, 0x34($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X34);
    // 0x8006CAB0: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8006CAB4: lwc1        $f2, 0x98($v1)
    ctx->f2.u32l = MEM_W(ctx->r3, 0X98);
    // 0x8006CAB8: c.eq.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl == ctx->f0.fl;
    // 0x8006CABC: nop

    // 0x8006CAC0: bc1t        L_8006CADC
    if (c1cs) {
        // 0x8006CAC4: nop
    
            goto L_8006CADC;
    }
    // 0x8006CAC4: nop

    // 0x8006CAC8: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8006CACC: lwc1        $f0, -0x35E8($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X35E8);
    // 0x8006CAD0: mul.s       $f4, $f2, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x8006CAD4: j           L_8006CAE4
    // 0x8006CAD8: nop

        goto L_8006CAE4;
    // 0x8006CAD8: nop

L_8006CADC:
    // 0x8006CADC: lwc1        $f0, 0x2C($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X2C);
    // 0x8006CAE0: mul.s       $f4, $f0, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f20.fl);
L_8006CAE4:
    // 0x8006CAE4: lw          $v1, 0x34($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X34);
    // 0x8006CAE8: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8006CAEC: lwc1        $f2, 0x9C($v1)
    ctx->f2.u32l = MEM_W(ctx->r3, 0X9C);
    // 0x8006CAF0: c.eq.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl == ctx->f0.fl;
    // 0x8006CAF4: nop

    // 0x8006CAF8: bc1t        L_8006CB14
    if (c1cs) {
        // 0x8006CAFC: nop
    
            goto L_8006CB14;
    }
    // 0x8006CAFC: nop

    // 0x8006CB00: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8006CB04: lwc1        $f0, -0x35E4($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X35E4);
    // 0x8006CB08: mul.s       $f0, $f2, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x8006CB0C: j           L_8006CB1C
    // 0x8006CB10: nop

        goto L_8006CB1C;
    // 0x8006CB10: nop

L_8006CB14:
    // 0x8006CB14: lwc1        $f0, 0x30($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X30);
    // 0x8006CB18: mul.s       $f0, $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f20.fl);
L_8006CB1C:
    // 0x8006CB1C: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x8006CB20: mfc1        $a2, $f4
    ctx->r6 = (int32_t)ctx->f4.u32l;
    // 0x8006CB24: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x8006CB28: jal         0x8001CB64
    // 0x8006CB2C: nop

    func_8001CB64(rdram, ctx);
        goto after_2;
    // 0x8006CB2C: nop

    after_2:
    // 0x8006CB30: lw          $v0, 0x34($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X34);
    // 0x8006CB34: lw          $a0, 0x30($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X30);
    // 0x8006CB38: lw          $a1, 0x1C($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X1C);
    // 0x8006CB3C: jal         0x8001CB9C
    // 0x8006CB40: addiu       $a0, $a0, 0x28
    ctx->r4 = ADD32(ctx->r4, 0X28);
    func_8001CB9C(rdram, ctx);
        goto after_3;
    // 0x8006CB40: addiu       $a0, $a0, 0x28
    ctx->r4 = ADD32(ctx->r4, 0X28);
    after_3:
    // 0x8006CB44: lw          $v0, 0x34($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X34);
    // 0x8006CB48: lw          $a0, 0x30($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X30);
    // 0x8006CB4C: lw          $a1, 0x20($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X20);
    // 0x8006CB50: jal         0x8001CCCC
    // 0x8006CB54: addiu       $a0, $a0, 0x28
    ctx->r4 = ADD32(ctx->r4, 0X28);
    func_8001CCCC(rdram, ctx);
        goto after_4;
    // 0x8006CB54: addiu       $a0, $a0, 0x28
    ctx->r4 = ADD32(ctx->r4, 0X28);
    after_4:
    // 0x8006CB58: lw          $v0, 0x34($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X34);
    // 0x8006CB5C: lw          $a0, 0x30($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X30);
    // 0x8006CB60: lw          $a1, 0x24($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X24);
    // 0x8006CB64: jal         0x8001CDFC
    // 0x8006CB68: addiu       $a0, $a0, 0x28
    ctx->r4 = ADD32(ctx->r4, 0X28);
    func_8001CDFC(rdram, ctx);
        goto after_5;
    // 0x8006CB68: addiu       $a0, $a0, 0x28
    ctx->r4 = ADD32(ctx->r4, 0X28);
    after_5:
    // 0x8006CB6C: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    // 0x8006CB70: lw          $a2, 0x4($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X4);
    // 0x8006CB74: lw          $a0, 0x30($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X30);
    // 0x8006CB78: lw          $a3, 0x8($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X8);
    // 0x8006CB7C: jal         0x8001CA90
    // 0x8006CB80: addiu       $a0, $a0, 0x28
    ctx->r4 = ADD32(ctx->r4, 0X28);
    func_8001CA90(rdram, ctx);
        goto after_6;
    // 0x8006CB80: addiu       $a0, $a0, 0x28
    ctx->r4 = ADD32(ctx->r4, 0X28);
    after_6:
    // 0x8006CB84: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x8006CB88: lhu         $a0, -0x6A8C($v0)
    ctx->r4 = MEM_HU(ctx->r2, -0X6A8C);
    // 0x8006CB8C: jal         0x8003E684
    // 0x8006CB90: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    func_8003E684(rdram, ctx);
        goto after_7;
    // 0x8006CB90: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    after_7:
    // 0x8006CB94: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8006CB98:
    // 0x8006CB98: lw          $ra, 0x18($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X18);
    // 0x8006CB9C: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x8006CBA0: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x8006CBA4: ldc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X20);
    // 0x8006CBA8: jr          $ra
    // 0x8006CBAC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x8006CBAC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_8006CBB0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006CBB0: addiu       $sp, $sp, -0xE0
    ctx->r29 = ADD32(ctx->r29, -0XE0);
    // 0x8006CBB4: sw          $s5, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->r21;
    // 0x8006CBB8: addu        $s5, $a0, $zero
    ctx->r21 = ADD32(ctx->r4, 0);
    // 0x8006CBBC: sw          $s0, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->r16;
    // 0x8006CBC0: andi        $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 & 0XFFFF;
    // 0x8006CBC4: addiu       $v1, $a1, -0x1
    ctx->r3 = ADD32(ctx->r5, -0X1);
    // 0x8006CBC8: sltiu       $v0, $v1, 0xB
    ctx->r2 = ctx->r3 < 0XB ? 1 : 0;
    // 0x8006CBCC: sw          $ra, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->r31;
    // 0x8006CBD0: sw          $s6, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->r22;
    // 0x8006CBD4: sw          $s4, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->r20;
    // 0x8006CBD8: sw          $s3, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->r19;
    // 0x8006CBDC: sw          $s2, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->r18;
    // 0x8006CBE0: sw          $s1, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->r17;
    // 0x8006CBE4: sdc1        $f28, 0xD8($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0XD8, ctx->r29);
    // 0x8006CBE8: sdc1        $f26, 0xD0($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0XD0, ctx->r29);
    // 0x8006CBEC: sdc1        $f24, 0xC8($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0XC8, ctx->r29);
    // 0x8006CBF0: sdc1        $f22, 0xC0($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0XC0, ctx->r29);
    // 0x8006CBF4: sdc1        $f20, 0xB8($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0XB8, ctx->r29);
    // 0x8006CBF8: lw          $s1, 0x4($s5)
    ctx->r17 = MEM_W(ctx->r21, 0X4);
    // 0x8006CBFC: beq         $v0, $zero, L_8006D8BC
    if (ctx->r2 == 0) {
        // 0x8006CC00: addu        $s0, $a2, $zero
        ctx->r16 = ADD32(ctx->r6, 0);
            goto L_8006D8BC;
    }
    // 0x8006CC00: addu        $s0, $a2, $zero
    ctx->r16 = ADD32(ctx->r6, 0);
    // 0x8006CC04: lui         $v0, 0x8004
    ctx->r2 = S32(0X8004 << 16);
    // 0x8006CC08: addiu       $v0, $v0, -0x35E0
    ctx->r2 = ADD32(ctx->r2, -0X35E0);
    // 0x8006CC0C: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x8006CC10: addu        $v1, $v1, $v0
    gpr jr_addend_8006CC18 = ctx->r3;
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x8006CC14: lw          $v0, 0x0($v1)
    ctx->r2 = ADD32(ctx->r3, 0X0);
    // 0x8006CC18: jr          $v0
    // 0x8006CC1C: nop

    switch (jr_addend_8006CC18 >> 2) {
        case 0: goto L_8006CC20; break;
        case 1: goto L_8006CE88; break;
        case 2: goto L_8006CED4; break;
        case 3: goto L_8006CF44; break;
        case 4: goto L_8006CF88; break;
        case 5: goto L_8006D8BC; break;
        case 6: goto L_8006D8BC; break;
        case 7: goto L_8006D8BC; break;
        case 8: goto L_8006D76C; break;
        case 9: goto L_8006D8BC; break;
        case 10: goto L_8006D890; break;
        default: switch_error(__func__, 0x8006CC18, 0x8003CA20);
    }
    // 0x8006CC1C: nop

L_8006CC20:
    // 0x8006CC20: sw          $s1, 0x8($s5)
    MEM_W(0X8, ctx->r21) = ctx->r17;
    // 0x8006CC24: sw          $s0, 0x34($s1)
    MEM_W(0X34, ctx->r17) = ctx->r16;
    // 0x8006CC28: lwc1        $f0, 0x10($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X10);
    // 0x8006CC2C: swc1        $f0, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->f0.u32l;
    // 0x8006CC30: lwc1        $f0, 0x14($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X14);
    // 0x8006CC34: swc1        $f0, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->f0.u32l;
    // 0x8006CC38: lwc1        $f0, 0x18($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X18);
    // 0x8006CC3C: swc1        $f0, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->f0.u32l;
    // 0x8006CC40: lw          $a1, 0x1C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X1C);
    // 0x8006CC44: lw          $a2, 0x20($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X20);
    // 0x8006CC48: lw          $a3, 0x24($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X24);
    // 0x8006CC4C: jal         0x80059D78
    // 0x8006CC50: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    func_80059D78(rdram, ctx);
        goto after_0;
    // 0x8006CC50: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    after_0:
    // 0x8006CC54: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8006CC58: sb          $zero, 0x44($s1)
    MEM_B(0X44, ctx->r17) = 0;
    // 0x8006CC5C: sb          $zero, 0x45($s1)
    MEM_B(0X45, ctx->r17) = 0;
    // 0x8006CC60: swc1        $f0, 0x2C($s1)
    MEM_W(0X2C, ctx->r17) = ctx->f0.u32l;
    // 0x8006CC64: swc1        $f0, 0x28($s1)
    MEM_W(0X28, ctx->r17) = ctx->f0.u32l;
    // 0x8006CC68: swc1        $f0, 0x24($s1)
    MEM_W(0X24, ctx->r17) = ctx->f0.u32l;
    // 0x8006CC6C: lw          $a0, 0x5C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X5C);
    // 0x8006CC70: jal         0x80056EB0
    // 0x8006CC74: nop

    func_80056EB0(rdram, ctx);
        goto after_1;
    // 0x8006CC74: nop

    after_1:
    // 0x8006CC78: lw          $a0, 0x34($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X34);
    // 0x8006CC7C: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // 0x8006CC80: sw          $v1, 0x30($s1)
    MEM_W(0X30, ctx->r17) = ctx->r3;
    // 0x8006CC84: lwc1        $f4, 0x2C($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X2C);
    // 0x8006CC88: lwc1        $f2, 0x28($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X28);
    // 0x8006CC8C: c.lt.s      $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f2.fl < ctx->f4.fl;
    // 0x8006CC90: nop

    // 0x8006CC94: bc1f        L_8006CCCC
    if (!c1cs) {
        // 0x8006CC98: nop
    
            goto L_8006CCCC;
    }
    // 0x8006CC98: nop

    // 0x8006CC9C: lwc1        $f0, 0x30($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X30);
    // 0x8006CCA0: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x8006CCA4: nop

    // 0x8006CCA8: bc1f        L_8006CCE0
    if (!c1cs) {
        // 0x8006CCAC: nop
    
            goto L_8006CCE0;
    }
    // 0x8006CCAC: nop

    // 0x8006CCB0: lhu         $v0, 0x8($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X8);
    // 0x8006CCB4: ori         $v0, $v0, 0x400
    ctx->r2 = ctx->r2 | 0X400;
    // 0x8006CCB8: sh          $v0, 0x8($v1)
    MEM_H(0X8, ctx->r3) = ctx->r2;
    // 0x8006CCBC: lw          $v0, 0x34($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X34);
    // 0x8006CCC0: lwc1        $f2, 0x2C($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X2C);
    // 0x8006CCC4: j           L_8006CCF4
    // 0x8006CCC8: nop

        goto L_8006CCF4;
    // 0x8006CCC8: nop

L_8006CCCC:
    // 0x8006CCCC: lwc1        $f0, 0x30($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X30);
    // 0x8006CCD0: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x8006CCD4: nop

    // 0x8006CCD8: bc1f        L_8006CCF4
    if (!c1cs) {
        // 0x8006CCDC: nop
    
            goto L_8006CCF4;
    }
    // 0x8006CCDC: nop

L_8006CCE0:
    // 0x8006CCE0: lhu         $v0, 0x8($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X8);
    // 0x8006CCE4: ori         $v0, $v0, 0x800
    ctx->r2 = ctx->r2 | 0X800;
    // 0x8006CCE8: sh          $v0, 0x8($v1)
    MEM_H(0X8, ctx->r3) = ctx->r2;
    // 0x8006CCEC: lw          $v0, 0x34($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X34);
    // 0x8006CCF0: lwc1        $f2, 0x30($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X30);
L_8006CCF4:
    // 0x8006CCF4: lw          $v0, 0x30($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X30);
    // 0x8006CCF8: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x8006CCFC: lwc1        $f0, 0x44($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X44);
    // 0x8006CD00: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x8006CD04: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8006CD08: lbu         $v0, 0xB39($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0XB39);
    // 0x8006CD0C: beq         $v0, $zero, L_8006CD34
    if (ctx->r2 == 0) {
        // 0x8006CD10: swc1        $f0, 0x38($s1)
        MEM_W(0X38, ctx->r17) = ctx->f0.u32l;
            goto L_8006CD34;
    }
    // 0x8006CD10: swc1        $f0, 0x38($s1)
    MEM_W(0X38, ctx->r17) = ctx->f0.u32l;
    // 0x8006CD14: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x8006CD18: lw          $v0, 0x34($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X34);
    // 0x8006CD1C: lw          $a0, 0x5C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X5C);
    // 0x8006CD20: lbu         $a3, 0x93($v0)
    ctx->r7 = MEM_BU(ctx->r2, 0X93);
    // 0x8006CD24: jal         0x800AA850
    // 0x8006CD28: addiu       $a2, $s0, 0x10
    ctx->r6 = ADD32(ctx->r16, 0X10);
    func_800AA850(rdram, ctx);
        goto after_2;
    // 0x8006CD28: addiu       $a2, $s0, 0x10
    ctx->r6 = ADD32(ctx->r16, 0X10);
    after_2:
    // 0x8006CD2C: j           L_8006CD54
    // 0x8006CD30: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
        goto L_8006CD54;
    // 0x8006CD30: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
L_8006CD34:
    // 0x8006CD34: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8006CD38: lw          $v0, 0x7CE4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X7CE4);
    // 0x8006CD3C: lw          $v1, 0x34($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X34);
    // 0x8006CD40: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8006CD44: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8006CD48: lw          $v0, 0x6C($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X6C);
    // 0x8006CD4C: slti        $v0, $v0, 0x1
    ctx->r2 = SIGNED(ctx->r2) < 0X1 ? 1 : 0;
    // 0x8006CD50: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
L_8006CD54:
    // 0x8006CD54: bnel        $v0, $zero, L_8006CE68
    if (ctx->r2 != 0) {
        // 0x8006CD58: addu        $a0, $s5, $zero
        ctx->r4 = ADD32(ctx->r21, 0);
            goto L_8006CE68;
    }
    goto skip_0;
    // 0x8006CD58: addu        $a0, $s5, $zero
    ctx->r4 = ADD32(ctx->r21, 0);
    skip_0:
    // 0x8006CD5C: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    // 0x8006CD60: lw          $a0, 0x30($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X30);
    // 0x8006CD64: addiu       $a2, $s0, 0x28
    ctx->r6 = ADD32(ctx->r16, 0X28);
    // 0x8006CD68: jal         0x80059C24
    // 0x8006CD6C: addiu       $a0, $a0, 0x28
    ctx->r4 = ADD32(ctx->r4, 0X28);
    func_80059C24(rdram, ctx);
        goto after_3;
    // 0x8006CD6C: addiu       $a0, $a0, 0x28
    ctx->r4 = ADD32(ctx->r4, 0X28);
    after_3:
    // 0x8006CD70: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x8006CD74: addiu       $s3, $v0, -0x6AA0
    ctx->r19 = ADD32(ctx->r2, -0X6AA0);
    // 0x8006CD78: lw          $v0, 0x88($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X88);
    // 0x8006CD7C: addiu       $s2, $zero, 0x1
    ctx->r18 = ADD32(0, 0X1);
    // 0x8006CD80: bne         $v0, $s2, L_8006CD8C
    if (ctx->r2 != ctx->r18) {
        // 0x8006CD84: addiu       $v1, $zero, 0x10
        ctx->r3 = ADD32(0, 0X10);
            goto L_8006CD8C;
    }
    // 0x8006CD84: addiu       $v1, $zero, 0x10
    ctx->r3 = ADD32(0, 0X10);
    // 0x8006CD88: addiu       $v1, $zero, 0xC
    ctx->r3 = ADD32(0, 0XC);
L_8006CD8C:
    // 0x8006CD8C: addu        $v0, $v1, $s3
    ctx->r2 = ADD32(ctx->r3, ctx->r19);
    // 0x8006CD90: lhu         $a0, 0x0($v0)
    ctx->r4 = MEM_HU(ctx->r2, 0X0);
    // 0x8006CD94: jal         0x8003E684
    // 0x8006CD98: addu        $a1, $s5, $zero
    ctx->r5 = ADD32(ctx->r21, 0);
    func_8003E684(rdram, ctx);
        goto after_4;
    // 0x8006CD98: addu        $a1, $s5, $zero
    ctx->r5 = ADD32(ctx->r21, 0);
    after_4:
    // 0x8006CD9C: sh          $v0, 0x40($s1)
    MEM_H(0X40, ctx->r17) = ctx->r2;
    // 0x8006CDA0: lw          $v0, 0xA4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0XA4);
    // 0x8006CDA4: bne         $v0, $zero, L_8006CDE4
    if (ctx->r2 != 0) {
        // 0x8006CDA8: ori         $v0, $zero, 0xFFFF
        ctx->r2 = 0 | 0XFFFF;
            goto L_8006CDE4;
    }
    // 0x8006CDA8: ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
    // 0x8006CDAC: lw          $a0, 0x88($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X88);
    // 0x8006CDB0: beq         $a0, $s2, L_8006CDC8
    if (ctx->r4 == ctx->r18) {
        // 0x8006CDB4: addu        $v0, $s3, $zero
        ctx->r2 = ADD32(ctx->r19, 0);
            goto L_8006CDC8;
    }
    // 0x8006CDB4: addu        $v0, $s3, $zero
    ctx->r2 = ADD32(ctx->r19, 0);
    // 0x8006CDB8: bne         $a0, $zero, L_8006CDCC
    if (ctx->r4 != 0) {
        // 0x8006CDBC: addiu       $v1, $zero, 0x2A
        ctx->r3 = ADD32(0, 0X2A);
            goto L_8006CDCC;
    }
    // 0x8006CDBC: addiu       $v1, $zero, 0x2A
    ctx->r3 = ADD32(0, 0X2A);
    // 0x8006CDC0: j           L_8006CDCC
    // 0x8006CDC4: addiu       $v1, $zero, 0x28
    ctx->r3 = ADD32(0, 0X28);
        goto L_8006CDCC;
    // 0x8006CDC4: addiu       $v1, $zero, 0x28
    ctx->r3 = ADD32(0, 0X28);
L_8006CDC8:
    // 0x8006CDC8: addiu       $v1, $zero, 0x26
    ctx->r3 = ADD32(0, 0X26);
L_8006CDCC:
    // 0x8006CDCC: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8006CDD0: lhu         $a0, 0x0($v0)
    ctx->r4 = MEM_HU(ctx->r2, 0X0);
    // 0x8006CDD4: jal         0x8003E684
    // 0x8006CDD8: addu        $a1, $s5, $zero
    ctx->r5 = ADD32(ctx->r21, 0);
    func_8003E684(rdram, ctx);
        goto after_5;
    // 0x8006CDD8: addu        $a1, $s5, $zero
    ctx->r5 = ADD32(ctx->r21, 0);
    after_5:
    // 0x8006CDDC: j           L_8006CDF4
    // 0x8006CDE0: sh          $v0, 0x3E($s1)
    MEM_H(0X3E, ctx->r17) = ctx->r2;
        goto L_8006CDF4;
    // 0x8006CDE0: sh          $v0, 0x3E($s1)
    MEM_H(0X3E, ctx->r17) = ctx->r2;
L_8006CDE4:
    // 0x8006CDE4: sh          $v0, 0x3E($s1)
    MEM_H(0X3E, ctx->r17) = ctx->r2;
    // 0x8006CDE8: lhu         $v0, 0x14($s5)
    ctx->r2 = MEM_HU(ctx->r21, 0X14);
    // 0x8006CDEC: ori         $v0, $v0, 0x100
    ctx->r2 = ctx->r2 | 0X100;
    // 0x8006CDF0: sh          $v0, 0x14($s5)
    MEM_H(0X14, ctx->r21) = ctx->r2;
L_8006CDF4:
    // 0x8006CDF4: lw          $v0, 0x8C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X8C);
    // 0x8006CDF8: beq         $v0, $zero, L_8006CE30
    if (ctx->r2 == 0) {
        // 0x8006CDFC: lui         $v0, 0x8014
        ctx->r2 = S32(0X8014 << 16);
            goto L_8006CE30;
    }
    // 0x8006CDFC: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x8006CE00: addiu       $a1, $v0, -0x6AA0
    ctx->r5 = ADD32(ctx->r2, -0X6AA0);
    // 0x8006CE04: lw          $v1, 0x88($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X88);
    // 0x8006CE08: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8006CE0C: bne         $v1, $v0, L_8006CE18
    if (ctx->r3 != ctx->r2) {
        // 0x8006CE10: addiu       $a0, $zero, 0x18
        ctx->r4 = ADD32(0, 0X18);
            goto L_8006CE18;
    }
    // 0x8006CE10: addiu       $a0, $zero, 0x18
    ctx->r4 = ADD32(0, 0X18);
    // 0x8006CE14: addiu       $a0, $zero, 0x1A
    ctx->r4 = ADD32(0, 0X1A);
L_8006CE18:
    // 0x8006CE18: addu        $v0, $a0, $a1
    ctx->r2 = ADD32(ctx->r4, ctx->r5);
    // 0x8006CE1C: lhu         $a0, 0x0($v0)
    ctx->r4 = MEM_HU(ctx->r2, 0X0);
    // 0x8006CE20: jal         0x8003E684
    // 0x8006CE24: addu        $a1, $s5, $zero
    ctx->r5 = ADD32(ctx->r21, 0);
    func_8003E684(rdram, ctx);
        goto after_6;
    // 0x8006CE24: addu        $a1, $s5, $zero
    ctx->r5 = ADD32(ctx->r21, 0);
    after_6:
    // 0x8006CE28: j           L_8006CE38
    // 0x8006CE2C: sh          $v0, 0x42($s1)
    MEM_H(0X42, ctx->r17) = ctx->r2;
        goto L_8006CE38;
    // 0x8006CE2C: sh          $v0, 0x42($s1)
    MEM_H(0X42, ctx->r17) = ctx->r2;
L_8006CE30:
    // 0x8006CE30: ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
    // 0x8006CE34: sh          $v0, 0x42($s1)
    MEM_H(0X42, ctx->r17) = ctx->r2;
L_8006CE38:
    // 0x8006CE38: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x8006CE3C: lhu         $a0, -0x6A84($v0)
    ctx->r4 = MEM_HU(ctx->r2, -0X6A84);
    // 0x8006CE40: jal         0x8003E684
    // 0x8006CE44: addu        $a1, $s5, $zero
    ctx->r5 = ADD32(ctx->r21, 0);
    func_8003E684(rdram, ctx);
        goto after_7;
    // 0x8006CE44: addu        $a1, $s5, $zero
    ctx->r5 = ADD32(ctx->r21, 0);
    after_7:
    // 0x8006CE48: lw          $v1, 0x30($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X30);
    // 0x8006CE4C: sh          $v0, 0x3C($s1)
    MEM_H(0X3C, ctx->r17) = ctx->r2;
    // 0x8006CE50: sw          $v1, 0xC($s5)
    MEM_W(0XC, ctx->r21) = ctx->r3;
    // 0x8006CE54: lw          $v1, 0x30($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X30);
    // 0x8006CE58: lhu         $v0, 0x8($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X8);
    // 0x8006CE5C: ori         $v0, $v0, 0x20
    ctx->r2 = ctx->r2 | 0X20;
    // 0x8006CE60: j           L_8006CE70
    // 0x8006CE64: sh          $v0, 0x8($v1)
    MEM_H(0X8, ctx->r3) = ctx->r2;
        goto L_8006CE70;
    // 0x8006CE64: sh          $v0, 0x8($v1)
    MEM_H(0X8, ctx->r3) = ctx->r2;
L_8006CE68:
    // 0x8006CE68: jal         0x8006C9C0
    // 0x8006CE6C: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    func_8006C9C0(rdram, ctx);
        goto after_8;
    // 0x8006CE6C: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    after_8:
L_8006CE70:
    // 0x8006CE70: lw          $a1, 0x30($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X30);
    // 0x8006CE74: jal         0x80071308
    // 0x8006CE78: addiu       $a0, $s1, 0x48
    ctx->r4 = ADD32(ctx->r17, 0X48);
    func_80071308(rdram, ctx);
        goto after_9;
    // 0x8006CE78: addiu       $a0, $s1, 0x48
    ctx->r4 = ADD32(ctx->r17, 0X48);
    after_9:
    // 0x8006CE7C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8006CE80: j           L_8006D8BC
    // 0x8006CE84: sb          $v0, 0x46($s1)
    MEM_B(0X46, ctx->r17) = ctx->r2;
        goto L_8006D8BC;
    // 0x8006CE84: sb          $v0, 0x46($s1)
    MEM_B(0X46, ctx->r17) = ctx->r2;
L_8006CE88:
    // 0x8006CE88: lw          $v0, 0x34($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X34);
    // 0x8006CE8C: ori         $v1, $zero, 0xFFFF
    ctx->r3 = 0 | 0XFFFF;
    // 0x8006CE90: sh          $v1, 0x6($v0)
    MEM_H(0X6, ctx->r2) = ctx->r3;
    // 0x8006CE94: lbu         $v0, 0x45($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X45);
    // 0x8006CE98: bne         $v0, $zero, L_8006CEAC
    if (ctx->r2 != 0) {
        // 0x8006CE9C: nop
    
            goto L_8006CEAC;
    }
    // 0x8006CE9C: nop

    // 0x8006CEA0: lw          $a0, 0x34($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X34);
    // 0x8006CEA4: jal         0x80046620
    // 0x8006CEA8: addiu       $a1, $a0, 0x10
    ctx->r5 = ADD32(ctx->r4, 0X10);
    func_80046620(rdram, ctx);
        goto after_10;
    // 0x8006CEA8: addiu       $a1, $a0, 0x10
    ctx->r5 = ADD32(ctx->r4, 0X10);
    after_10:
L_8006CEAC:
    // 0x8006CEAC: lw          $a1, 0x30($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X30);
    // 0x8006CEB0: jal         0x80072AF8
    // 0x8006CEB4: addiu       $a0, $s1, 0x48
    ctx->r4 = ADD32(ctx->r17, 0X48);
    func_80072AF8(rdram, ctx);
        goto after_11;
    // 0x8006CEB4: addiu       $a0, $s1, 0x48
    ctx->r4 = ADD32(ctx->r17, 0X48);
    after_11:
    // 0x8006CEB8: lw          $a0, 0x30($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X30);
    // 0x8006CEBC: beq         $a0, $zero, L_8006D8C0
    if (ctx->r4 == 0) {
        // 0x8006CEC0: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_8006D8C0;
    }
    // 0x8006CEC0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8006CEC4: jal         0x8005779C
    // 0x8006CEC8: nop

    func_8005779C(rdram, ctx);
        goto after_12;
    // 0x8006CEC8: nop

    after_12:
    // 0x8006CECC: j           L_8006D8C0
    // 0x8006CED0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8006D8C0;
    // 0x8006CED0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8006CED4:
    // 0x8006CED4: jal         0x80047D40
    // 0x8006CED8: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    func_80047D40(rdram, ctx);
        goto after_13;
    // 0x8006CED8: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    after_13:
    // 0x8006CEDC: bnel        $v0, $zero, L_8006CF14
    if (ctx->r2 != 0) {
        // 0x8006CEE0: sb          $zero, 0x44($s1)
        MEM_B(0X44, ctx->r17) = 0;
            goto L_8006CF14;
    }
    goto skip_1;
    // 0x8006CEE0: sb          $zero, 0x44($s1)
    MEM_B(0X44, ctx->r17) = 0;
    skip_1:
    // 0x8006CEE4: lbu         $v0, 0x44($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X44);
    // 0x8006CEE8: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8006CEEC: sb          $v0, 0x44($s1)
    MEM_B(0X44, ctx->r17) = ctx->r2;
    // 0x8006CEF0: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x8006CEF4: sltiu       $v0, $v0, 0x15
    ctx->r2 = ctx->r2 < 0X15 ? 1 : 0;
    // 0x8006CEF8: bne         $v0, $zero, L_8006CF14
    if (ctx->r2 != 0) {
        // 0x8006CEFC: nop
    
            goto L_8006CF14;
    }
    // 0x8006CEFC: nop

L_8006CF00:
    // 0x8006CF00: lhu         $a0, 0x16($s5)
    ctx->r4 = MEM_HU(ctx->r21, 0X16);
    // 0x8006CF04: jal         0x8003ED74
    // 0x8006CF08: nop

    func_8003ED74(rdram, ctx);
        goto after_14;
    // 0x8006CF08: nop

    after_14:
    // 0x8006CF0C: j           L_8006D8C0
    // 0x8006CF10: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8006D8C0;
    // 0x8006CF10: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8006CF14:
    // 0x8006CF14: lbu         $v0, 0x46($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X46);
    // 0x8006CF18: beq         $v0, $zero, L_8006D8BC
    if (ctx->r2 == 0) {
        // 0x8006CF1C: addiu       $v0, $zero, 0xFF
        ctx->r2 = ADD32(0, 0XFF);
            goto L_8006D8BC;
    }
    // 0x8006CF1C: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // 0x8006CF20: lbu         $v1, 0x48($s1)
    ctx->r3 = MEM_BU(ctx->r17, 0X48);
    // 0x8006CF24: beq         $v1, $v0, L_8006D8C0
    if (ctx->r3 == ctx->r2) {
        // 0x8006CF28: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_8006D8C0;
    }
    // 0x8006CF28: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8006CF2C: lw          $a1, 0x30($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X30);
    // 0x8006CF30: lw          $a2, 0x0($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X0);
    // 0x8006CF34: jal         0x80072BE0
    // 0x8006CF38: addiu       $a0, $s1, 0x48
    ctx->r4 = ADD32(ctx->r17, 0X48);
    func_80072BE0(rdram, ctx);
        goto after_15;
    // 0x8006CF38: addiu       $a0, $s1, 0x48
    ctx->r4 = ADD32(ctx->r17, 0X48);
    after_15:
    // 0x8006CF3C: j           L_8006D8C0
    // 0x8006CF40: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8006D8C0;
    // 0x8006CF40: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8006CF44:
    // 0x8006CF44: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x8006CF48: lw          $a1, 0x30($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X30);
    // 0x8006CF4C: lw          $a3, 0x38($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X38);
    // 0x8006CF50: jal         0x80057C8C
    // 0x8006CF54: addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    func_80057C8C(rdram, ctx);
        goto after_16;
    // 0x8006CF54: addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    after_16:
    // 0x8006CF58: sb          $v0, 0x46($s1)
    MEM_B(0X46, ctx->r17) = ctx->r2;
    // 0x8006CF5C: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x8006CF60: beq         $v0, $zero, L_8006D8BC
    if (ctx->r2 == 0) {
        // 0x8006CF64: addiu       $v0, $zero, 0xFF
        ctx->r2 = ADD32(0, 0XFF);
            goto L_8006D8BC;
    }
    // 0x8006CF64: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // 0x8006CF68: lbu         $v1, 0x48($s1)
    ctx->r3 = MEM_BU(ctx->r17, 0X48);
    // 0x8006CF6C: beq         $v1, $v0, L_8006D8BC
    if (ctx->r3 == ctx->r2) {
        // 0x8006CF70: addiu       $a0, $s1, 0x48
        ctx->r4 = ADD32(ctx->r17, 0X48);
            goto L_8006D8BC;
    }
    // 0x8006CF70: addiu       $a0, $s1, 0x48
    ctx->r4 = ADD32(ctx->r17, 0X48);
    // 0x8006CF74: lw          $a1, 0x30($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X30);
    // 0x8006CF78: jal         0x80071928
    // 0x8006CF7C: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    func_80071928(rdram, ctx);
        goto after_17;
    // 0x8006CF7C: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    after_17:
    // 0x8006CF80: j           L_8006D8C0
    // 0x8006CF84: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8006D8C0;
    // 0x8006CF84: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8006CF88:
    // 0x8006CF88: lui         $s2, 0x8013
    ctx->r18 = S32(0X8013 << 16);
    // 0x8006CF8C: lw          $v1, 0x34($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X34);
    // 0x8006CF90: lw          $v0, 0x7CE4($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X7CE4);
    // 0x8006CF94: addiu       $s3, $v1, 0x6C
    ctx->r19 = ADD32(ctx->r3, 0X6C);
    // 0x8006CF98: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8006CF9C: addu        $v0, $v0, $s3
    ctx->r2 = ADD32(ctx->r2, ctx->r19);
    // 0x8006CFA0: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x8006CFA4: blez        $v0, L_8006D74C
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8006CFA8: addu        $s6, $s0, $zero
        ctx->r22 = ADD32(ctx->r16, 0);
            goto L_8006D74C;
    }
    // 0x8006CFA8: addu        $s6, $s0, $zero
    ctx->r22 = ADD32(ctx->r16, 0);
    // 0x8006CFAC: lw          $v0, 0xA0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0XA0);
    // 0x8006CFB0: beq         $v0, $zero, L_8006CFD0
    if (ctx->r2 == 0) {
        // 0x8006CFB4: nop
    
            goto L_8006CFD0;
    }
    // 0x8006CFB4: nop

    // 0x8006CFB8: jal         0x8006C994
    // 0x8006CFBC: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    func_8006C994(rdram, ctx);
        goto after_18;
    // 0x8006CFBC: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    after_18:
    // 0x8006CFC0: lhu         $v1, 0x2($s0)
    ctx->r3 = MEM_HU(ctx->r16, 0X2);
    // 0x8006CFC4: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x8006CFC8: beq         $v1, $v0, L_8006CFEC
    if (ctx->r3 == ctx->r2) {
        // 0x8006CFCC: nop
    
            goto L_8006CFEC;
    }
    // 0x8006CFCC: nop

L_8006CFD0:
    // 0x8006CFD0: lw          $v0, 0x7CE4($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X7CE4);
    // 0x8006CFD4: lhu         $a0, 0x6($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X6);
    // 0x8006CFD8: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8006CFDC: addu        $v0, $v0, $s3
    ctx->r2 = ADD32(ctx->r2, ctx->r19);
    // 0x8006CFE0: lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X0);
    // 0x8006CFE4: subu        $v1, $v1, $a0
    ctx->r3 = SUB32(ctx->r3, ctx->r4);
    // 0x8006CFE8: sw          $v1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r3;
L_8006CFEC:
    // 0x8006CFEC: lw          $a0, 0x8($s6)
    ctx->r4 = MEM_W(ctx->r22, 0X8);
    // 0x8006CFF0: beq         $a0, $zero, L_8006D228
    if (ctx->r4 == 0) {
        // 0x8006CFF4: lui         $v0, 0x8013
        ctx->r2 = S32(0X8013 << 16);
            goto L_8006D228;
    }
    // 0x8006CFF4: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8006CFF8: lbu         $v0, 0xB39($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0XB39);
    // 0x8006CFFC: bne         $v0, $zero, L_8006D02C
    if (ctx->r2 != 0) {
        // 0x8006D000: addu        $s0, $zero, $zero
        ctx->r16 = ADD32(0, 0);
            goto L_8006D02C;
    }
    // 0x8006D000: addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
    // 0x8006D004: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x8006D008: lw          $v0, -0x35E0($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X35E0);
    // 0x8006D00C: bne         $v0, $zero, L_8006D02C
    if (ctx->r2 != 0) {
        // 0x8006D010: addu        $a1, $zero, $zero
        ctx->r5 = ADD32(0, 0);
            goto L_8006D02C;
    }
    // 0x8006D010: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x8006D014: lui         $a3, 0x3E4C
    ctx->r7 = S32(0X3E4C << 16);
    // 0x8006D018: ori         $a3, $a3, 0xCCCD
    ctx->r7 = ctx->r7 | 0XCCCD;
    // 0x8006D01C: jal         0x80077784
    // 0x8006D020: addiu       $a2, $sp, 0x28
    ctx->r6 = ADD32(ctx->r29, 0X28);
    func_80077784(rdram, ctx);
        goto after_19;
    // 0x8006D020: addiu       $a2, $sp, 0x28
    ctx->r6 = ADD32(ctx->r29, 0X28);
    after_19:
    // 0x8006D024: j           L_8006D044
    // 0x8006D028: nop

        goto L_8006D044;
    // 0x8006D028: nop

L_8006D02C:
    // 0x8006D02C: lw          $t0, 0x0($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X0);
    // 0x8006D030: lw          $t1, 0x4($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X4);
    // 0x8006D034: lw          $t2, 0x8($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X8);
    // 0x8006D038: sw          $t0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r8;
    // 0x8006D03C: sw          $t1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r9;
    // 0x8006D040: sw          $t2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r10;
L_8006D044:
    // 0x8006D044: lhu         $v0, 0x4($s6)
    ctx->r2 = MEM_HU(ctx->r22, 0X4);
    // 0x8006D048: addiu       $v1, $v0, -0x8
    ctx->r3 = ADD32(ctx->r2, -0X8);
    // 0x8006D04C: sltiu       $v0, $v1, 0x7
    ctx->r2 = ctx->r3 < 0X7 ? 1 : 0;
    // 0x8006D050: beq         $v0, $zero, L_8006D0AC
    if (ctx->r2 == 0) {
        // 0x8006D054: lui         $v0, 0x8004
        ctx->r2 = S32(0X8004 << 16);
            goto L_8006D0AC;
    }
    // 0x8006D054: lui         $v0, 0x8004
    ctx->r2 = S32(0X8004 << 16);
    // 0x8006D058: addiu       $v0, $v0, -0x35B0
    ctx->r2 = ADD32(ctx->r2, -0X35B0);
    // 0x8006D05C: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x8006D060: addu        $v1, $v1, $v0
    gpr jr_addend_8006D068 = ctx->r3;
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x8006D064: lw          $v0, 0x0($v1)
    ctx->r2 = ADD32(ctx->r3, 0X0);
    // 0x8006D068: jr          $v0
    // 0x8006D06C: nop

    switch (jr_addend_8006D068 >> 2) {
        case 0: goto L_8006D0D8; break;
        case 1: goto L_8006D0D8; break;
        case 2: goto L_8006D090; break;
        case 3: goto L_8006D090; break;
        case 4: goto L_8006D070; break;
        case 5: goto L_8006D090; break;
        case 6: goto L_8006D090; break;
        default: switch_error(__func__, 0x8006D068, 0x8003CA50);
    }
    // 0x8006D06C: nop

L_8006D070:
    // 0x8006D070: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    // 0x8006D074: ori         $a1, $zero, 0xFFFF
    ctx->r5 = 0 | 0XFFFF;
    // 0x8006D078: lui         $a2, 0x3ECC
    ctx->r6 = S32(0X3ECC << 16);
    // 0x8006D07C: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x8006D080: jal         0x80077570
    // 0x8006D084: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    func_80077570(rdram, ctx);
        goto after_20;
    // 0x8006D084: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    after_20:
    // 0x8006D088: j           L_8006D0DC
    // 0x8006D08C: andi        $v0, $s0, 0xFF
    ctx->r2 = ctx->r16 & 0XFF;
        goto L_8006D0DC;
    // 0x8006D08C: andi        $v0, $s0, 0xFF
    ctx->r2 = ctx->r16 & 0XFF;
L_8006D090:
    // 0x8006D090: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    // 0x8006D094: lui         $a1, 0x3F19
    ctx->r5 = S32(0X3F19 << 16);
    // 0x8006D098: ori         $a1, $a1, 0x999A
    ctx->r5 = ctx->r5 | 0X999A;
    // 0x8006D09C: jal         0x800612A4
    // 0x8006D0A0: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
    func_800612A4(rdram, ctx);
        goto after_21;
    // 0x8006D0A0: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
    after_21:
    // 0x8006D0A4: j           L_8006D0DC
    // 0x8006D0A8: andi        $v0, $s0, 0xFF
    ctx->r2 = ctx->r16 & 0XFF;
        goto L_8006D0DC;
    // 0x8006D0A8: andi        $v0, $s0, 0xFF
    ctx->r2 = ctx->r16 & 0XFF;
L_8006D0AC:
    // 0x8006D0AC: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8006D0B0: lwc1        $f20, -0x3594($at)
    ctx->f20.u32l = MEM_W(ctx->r1, -0X3594);
    // 0x8006D0B4: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    // 0x8006D0B8: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x8006D0BC: jal         0x800612A4
    // 0x8006D0C0: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
    func_800612A4(rdram, ctx);
        goto after_22;
    // 0x8006D0C0: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
    after_22:
    // 0x8006D0C4: lui         $a1, 0x3D4C
    ctx->r5 = S32(0X3D4C << 16);
    // 0x8006D0C8: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    // 0x8006D0CC: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x8006D0D0: jal         0x80073E4C
    // 0x8006D0D4: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    func_80073E4C(rdram, ctx);
        goto after_23;
    // 0x8006D0D4: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    after_23:
L_8006D0D8:
    // 0x8006D0D8: andi        $v0, $s0, 0xFF
    ctx->r2 = ctx->r16 & 0XFF;
L_8006D0DC:
    // 0x8006D0DC: beq         $v0, $zero, L_8006D22C
    if (ctx->r2 == 0) {
        // 0x8006D0E0: addu        $a0, $zero, $zero
        ctx->r4 = ADD32(0, 0);
            goto L_8006D22C;
    }
    // 0x8006D0E0: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x8006D0E4: jal         0x80003430
    // 0x8006D0E8: nop

    rand_recomp(rdram, ctx);
        goto after_24;
    // 0x8006D0E8: nop

    after_24:
    // 0x8006D0EC: lui         $a0, 0x51EB
    ctx->r4 = S32(0X51EB << 16);
    // 0x8006D0F0: ori         $a0, $a0, 0x851F
    ctx->r4 = ctx->r4 | 0X851F;
    // 0x8006D0F4: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x8006D0F8: sra         $v1, $v0, 16
    ctx->r3 = S32(SIGNED(ctx->r2) >> 16);
    // 0x8006D0FC: mult        $v1, $a0
    result = S64(S32(ctx->r3)) * S64(S32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8006D100: sra         $v0, $v0, 31
    ctx->r2 = S32(SIGNED(ctx->r2) >> 31);
    // 0x8006D104: mfhi        $t0
    ctx->r8 = hi;
    // 0x8006D108: sra         $a0, $t0, 5
    ctx->r4 = S32(SIGNED(ctx->r8) >> 5);
    // 0x8006D10C: subu        $a0, $a0, $v0
    ctx->r4 = SUB32(ctx->r4, ctx->r2);
    // 0x8006D110: sll         $v0, $a0, 1
    ctx->r2 = S32(ctx->r4 << 1);
    // 0x8006D114: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x8006D118: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x8006D11C: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x8006D120: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8006D124: subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // 0x8006D128: sll         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3 << 16);
    // 0x8006D12C: sra         $v1, $v1, 16
    ctx->r3 = S32(SIGNED(ctx->r3) >> 16);
    // 0x8006D130: slti        $v1, $v1, 0x5
    ctx->r3 = SIGNED(ctx->r3) < 0X5 ? 1 : 0;
    // 0x8006D134: beq         $v1, $zero, L_8006D228
    if (ctx->r3 == 0) {
        // 0x8006D138: addu        $a0, $zero, $zero
        ctx->r4 = ADD32(0, 0);
            goto L_8006D228;
    }
    // 0x8006D138: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x8006D13C: addiu       $s0, $sp, 0x48
    ctx->r16 = ADD32(ctx->r29, 0X48);
    // 0x8006D140: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x8006D144: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // 0x8006D148: addiu       $a3, $zero, 0x14
    ctx->r7 = ADD32(0, 0X14);
    // 0x8006D14C: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
    // 0x8006D150: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // 0x8006D154: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8006D158: jal         0x80075218
    // 0x8006D15C: sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    func_80075218(rdram, ctx);
        goto after_25;
    // 0x8006D15C: sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    after_25:
    // 0x8006D160: lui         $a1, 0xBF33
    ctx->r5 = S32(0XBF33 << 16);
    // 0x8006D164: ori         $a1, $a1, 0x3333
    ctx->r5 = ctx->r5 | 0X3333;
    // 0x8006D168: lui         $a2, 0xBFC0
    ctx->r6 = S32(0XBFC0 << 16);
    // 0x8006D16C: jal         0x80072300
    // 0x8006D170: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_80072300(rdram, ctx);
        goto after_26;
    // 0x8006D170: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_26:
    // 0x8006D174: jal         0x80003430
    // 0x8006D178: nop

    rand_recomp(rdram, ctx);
        goto after_27;
    // 0x8006D178: nop

    after_27:
    // 0x8006D17C: andi        $v0, $v0, 0x7F
    ctx->r2 = ctx->r2 & 0X7F;
    // 0x8006D180: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8006D184: lwc1        $f22, -0x3590($at)
    ctx->f22.u32l = MEM_W(ctx->r1, -0X3590);
    // 0x8006D188: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x8006D18C: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x8006D190: sub.s       $f0, $f0, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f22.fl;
    // 0x8006D194: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8006D198: lwc1        $f2, -0x358C($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X358C);
    // 0x8006D19C: div.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f2.fl);
    // 0x8006D1A0: abs.s       $f24, $f0
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f24.fl = fabsf(ctx->f0.fl);
    // 0x8006D1A4: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8006D1A8: lwc1        $f0, -0x3588($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X3588);
    // 0x8006D1AC: jal         0x80003430
    // 0x8006D1B0: add.s       $f24, $f24, $f0
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f24.fl = ctx->f24.fl + ctx->f0.fl;
    rand_recomp(rdram, ctx);
        goto after_28;
    // 0x8006D1B0: add.s       $f24, $f24, $f0
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f24.fl = ctx->f24.fl + ctx->f0.fl;
    after_28:
    // 0x8006D1B4: andi        $v0, $v0, 0x7F
    ctx->r2 = ctx->r2 & 0X7F;
    // 0x8006D1B8: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x8006D1BC: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x8006D1C0: sub.s       $f0, $f0, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f22.fl;
    // 0x8006D1C4: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8006D1C8: lwc1        $f2, -0x3584($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X3584);
    // 0x8006D1CC: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x8006D1D0: abs.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f20.fl = fabsf(ctx->f0.fl);
    // 0x8006D1D4: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8006D1D8: lwc1        $f0, -0x3580($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X3580);
    // 0x8006D1DC: jal         0x80003430
    // 0x8006D1E0: add.s       $f20, $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f20.fl = ctx->f20.fl + ctx->f0.fl;
    rand_recomp(rdram, ctx);
        goto after_29;
    // 0x8006D1E0: add.s       $f20, $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f20.fl = ctx->f20.fl + ctx->f0.fl;
    after_29:
    // 0x8006D1E4: andi        $v0, $v0, 0x7F
    ctx->r2 = ctx->r2 & 0X7F;
    // 0x8006D1E8: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x8006D1EC: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x8006D1F0: sub.s       $f0, $f0, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f22.fl;
    // 0x8006D1F4: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8006D1F8: lwc1        $f2, -0x357C($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X357C);
    // 0x8006D1FC: div.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f2.fl);
    // 0x8006D200: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x8006D204: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    // 0x8006D208: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8006D20C: lwc1        $f2, -0x3578($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X3578);
    // 0x8006D210: mfc1        $a2, $f24
    ctx->r6 = (int32_t)ctx->f24.u32l;
    // 0x8006D214: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x8006D218: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x8006D21C: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x8006D220: jal         0x80072384
    // 0x8006D224: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    func_80072384(rdram, ctx);
        goto after_30;
    // 0x8006D224: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    after_30:
L_8006D228:
    // 0x8006D228: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
L_8006D22C:
    // 0x8006D22C: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    // 0x8006D230: addiu       $a2, $s1, 0x24
    ctx->r6 = ADD32(ctx->r17, 0X24);
    // 0x8006D234: lui         $a3, 0x41C0
    ctx->r7 = S32(0X41C0 << 16);
    // 0x8006D238: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8006D23C: lwc1        $f24, -0x3574($at)
    ctx->f24.u32l = MEM_W(ctx->r1, -0X3574);
    // 0x8006D240: addiu       $v0, $zero, 0xC
    ctx->r2 = ADD32(0, 0XC);
    // 0x8006D244: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // 0x8006D248: addiu       $v0, $zero, 0x7F
    ctx->r2 = ADD32(0, 0X7F);
    // 0x8006D24C: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x8006D250: addiu       $v0, $zero, 0x50
    ctx->r2 = ADD32(0, 0X50);
    // 0x8006D254: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x8006D258: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x8006D25C: jal         0x800989D8
    // 0x8006D260: swc1        $f24, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f24.u32l;
    func_800989D8(rdram, ctx);
        goto after_31;
    // 0x8006D260: swc1        $f24, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f24.u32l;
    after_31:
    // 0x8006D264: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8006D268: lw          $v0, 0x7CE4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X7CE4);
    // 0x8006D26C: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8006D270: addu        $v0, $v0, $s3
    ctx->r2 = ADD32(ctx->r2, ctx->r19);
    // 0x8006D274: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x8006D278: bgtz        $v0, L_8006D74C
    if (SIGNED(ctx->r2) > 0) {
        // 0x8006D27C: nop
    
            goto L_8006D74C;
    }
    // 0x8006D27C: nop

    // 0x8006D280: lw          $a0, 0x30($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X30);
    // 0x8006D284: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8006D288: lwc1        $f8, 0x48($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X48);
    // 0x8006D28C: sqrt.s      $f20, $f8
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f20.fl = sqrtf(ctx->f8.fl);
    // 0x8006D290: addiu       $s0, $sp, 0x58
    ctx->r16 = ADD32(ctx->r29, 0X58);
    // 0x8006D294: jal         0x8006AC7C
    // 0x8006D298: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    func_8006AC7C(rdram, ctx);
        goto after_32;
    // 0x8006D298: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    after_32:
    // 0x8006D29C: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x8006D2A0: jal         0x800612A4
    // 0x8006D2A4: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_800612A4(rdram, ctx);
        goto after_33;
    // 0x8006D2A4: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_33:
    // 0x8006D2A8: lw          $v0, 0x8($s6)
    ctx->r2 = MEM_W(ctx->r22, 0X8);
    // 0x8006D2AC: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8006D2B0: lwc1        $f20, -0x3570($at)
    ctx->f20.u32l = MEM_W(ctx->r1, -0X3570);
    // 0x8006D2B4: beq         $v0, $zero, L_8006D2C0
    if (ctx->r2 == 0) {
        // 0x8006D2B8: nop
    
            goto L_8006D2C0;
    }
    // 0x8006D2B8: nop

    // 0x8006D2BC: lwc1        $f20, 0x20($v0)
    ctx->f20.u32l = MEM_W(ctx->r2, 0X20);
L_8006D2C0:
    // 0x8006D2C0: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8006D2C4: lwc1        $f22, -0x356C($at)
    ctx->f22.u32l = MEM_W(ctx->r1, -0X356C);
    // 0x8006D2C8: c.lt.s      $f22, $f20
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f22.fl < ctx->f20.fl;
    // 0x8006D2CC: nop

    // 0x8006D2D0: bc1f        L_8006D324
    if (!c1cs) {
        // 0x8006D2D4: addiu       $s0, $sp, 0x68
        ctx->r16 = ADD32(ctx->r29, 0X68);
            goto L_8006D324;
    }
    // 0x8006D2D4: addiu       $s0, $sp, 0x68
    ctx->r16 = ADD32(ctx->r29, 0X68);
    // 0x8006D2D8: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x8006D2DC: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    // 0x8006D2E0: jal         0x80018EF4
    // 0x8006D2E4: addiu       $a2, $zero, 0x30
    ctx->r6 = ADD32(0, 0X30);
    zmemcpy(rdram, ctx);
        goto after_34;
    // 0x8006D2E4: addiu       $a2, $zero, 0x30
    ctx->r6 = ADD32(0, 0X30);
    after_34:
    // 0x8006D2E8: addiu       $a1, $sp, 0x8C
    ctx->r5 = ADD32(ctx->r29, 0X8C);
    // 0x8006D2EC: lhu         $a0, 0x16($s5)
    ctx->r4 = MEM_HU(ctx->r21, 0X16);
    // 0x8006D2F0: jal         0x80074B74
    // 0x8006D2F4: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    func_80074B74(rdram, ctx);
        goto after_35;
    // 0x8006D2F4: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    after_35:
    // 0x8006D2F8: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x8006D2FC: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x8006D300: mfc1        $a3, $f24
    ctx->r7 = (int32_t)ctx->f24.u32l;
    // 0x8006D304: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8006D308: lwc1        $f0, -0x3568($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X3568);
    // 0x8006D30C: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8006D310: lwc1        $f2, -0x3564($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X3564);
    // 0x8006D314: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // 0x8006D318: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    // 0x8006D31C: jal         0x800727C0
    // 0x8006D320: swc1        $f2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f2.u32l;
    func_800727C0(rdram, ctx);
        goto after_36;
    // 0x8006D320: swc1        $f2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f2.u32l;
    after_36:
L_8006D324:
    // 0x8006D324: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8006D328: lwc1        $f0, -0x3560($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X3560);
    // 0x8006D32C: c.lt.s      $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f0.fl < ctx->f20.fl;
    // 0x8006D330: nop

    // 0x8006D334: bc1tl       L_8006D33C
    if (c1cs) {
        // 0x8006D338: mov.s       $f20, $f0
        CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
            goto L_8006D33C;
    }
    goto skip_2;
    // 0x8006D338: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    skip_2:
L_8006D33C:
    // 0x8006D33C: c.lt.s      $f22, $f20
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f22.fl < ctx->f20.fl;
    // 0x8006D340: nop

    // 0x8006D344: bc1t        L_8006D368
    if (c1cs) {
        // 0x8006D348: mov.s       $f26, $f22
        CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 22);
    ctx->f26.fl = ctx->f22.fl;
            goto L_8006D368;
    }
    // 0x8006D348: mov.s       $f26, $f22
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 22);
    ctx->f26.fl = ctx->f22.fl;
    // 0x8006D34C: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8006D350: lwc1        $f0, -0x355C($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X355C);
    // 0x8006D354: c.lt.s      $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f20.fl < ctx->f0.fl;
    // 0x8006D358: nop

    // 0x8006D35C: bc1f        L_8006D368
    if (!c1cs) {
        // 0x8006D360: mov.s       $f26, $f20
        CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 20);
    ctx->f26.fl = ctx->f20.fl;
            goto L_8006D368;
    }
    // 0x8006D360: mov.s       $f26, $f20
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 20);
    ctx->f26.fl = ctx->f20.fl;
    // 0x8006D364: mov.s       $f26, $f0
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 0);
    ctx->f26.fl = ctx->f0.fl;
L_8006D368:
    // 0x8006D368: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8006D36C: lwc1        $f2, -0x3558($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X3558);
    // 0x8006D370: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8006D374: lwc1        $f0, -0x3554($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X3554);
    // 0x8006D378: c.lt.s      $f20, $f2
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f20.fl < ctx->f2.fl;
    // 0x8006D37C: mul.s       $f28, $f20, $f0
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f28.fl = MUL_S(ctx->f20.fl, ctx->f0.fl);
    // 0x8006D380: bc1tl       L_8006D388
    if (c1cs) {
        // 0x8006D384: mov.s       $f20, $f2
        CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    ctx->f20.fl = ctx->f2.fl;
            goto L_8006D388;
    }
    goto skip_3;
    // 0x8006D384: mov.s       $f20, $f2
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    ctx->f20.fl = ctx->f2.fl;
    skip_3:
L_8006D388:
    // 0x8006D388: jal         0x80003430
    // 0x8006D38C: nop

    rand_recomp(rdram, ctx);
        goto after_37;
    // 0x8006D38C: nop

    after_37:
    // 0x8006D390: lui         $v1, 0x5555
    ctx->r3 = S32(0X5555 << 16);
    // 0x8006D394: ori         $v1, $v1, 0x5556
    ctx->r3 = ctx->r3 | 0X5556;
    // 0x8006D398: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x8006D39C: sra         $a0, $v0, 16
    ctx->r4 = S32(SIGNED(ctx->r2) >> 16);
    // 0x8006D3A0: mult        $a0, $v1
    result = S64(S32(ctx->r4)) * S64(S32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8006D3A4: sra         $v0, $v0, 31
    ctx->r2 = S32(SIGNED(ctx->r2) >> 31);
    // 0x8006D3A8: mfhi        $t0
    ctx->r8 = hi;
    // 0x8006D3AC: subu        $v0, $t0, $v0
    ctx->r2 = SUB32(ctx->r8, ctx->r2);
    // 0x8006D3B0: sll         $v1, $v0, 1
    ctx->r3 = S32(ctx->r2 << 1);
    // 0x8006D3B4: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x8006D3B8: subu        $a0, $a0, $v1
    ctx->r4 = SUB32(ctx->r4, ctx->r3);
    // 0x8006D3BC: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x8006D3C0: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    // 0x8006D3C4: addiu       $s2, $a0, 0x4
    ctx->r18 = ADD32(ctx->r4, 0X4);
    // 0x8006D3C8: mtc1        $s2, $f0
    ctx->f0.u32l = ctx->r18;
    // 0x8006D3CC: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x8006D3D0: mul.s       $f0, $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f20.fl);
    // 0x8006D3D4: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8006D3D8: lw          $v1, 0xB70($v0)
    ctx->r3 = MEM_W(ctx->r2, 0XB70);
    // 0x8006D3DC: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x8006D3E0: trunc.w.s   $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    ctx->f8.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x8006D3E4: mfc1        $s2, $f8
    ctx->r18 = (int32_t)ctx->f8.u32l;
    // 0x8006D3E8: beq         $v1, $v0, L_8006D408
    if (ctx->r3 == ctx->r2) {
        // 0x8006D3EC: addiu       $v0, $zero, 0x6
        ctx->r2 = ADD32(0, 0X6);
            goto L_8006D408;
    }
    // 0x8006D3EC: addiu       $v0, $zero, 0x6
    ctx->r2 = ADD32(0, 0X6);
    // 0x8006D3F0: beq         $v1, $v0, L_8006D408
    if (ctx->r3 == ctx->r2) {
        // 0x8006D3F4: addiu       $v0, $zero, 0x9
        ctx->r2 = ADD32(0, 0X9);
            goto L_8006D408;
    }
    // 0x8006D3F4: addiu       $v0, $zero, 0x9
    ctx->r2 = ADD32(0, 0X9);
    // 0x8006D3F8: beq         $v1, $v0, L_8006D408
    if (ctx->r3 == ctx->r2) {
        // 0x8006D3FC: addiu       $v0, $zero, 0xD
        ctx->r2 = ADD32(0, 0XD);
            goto L_8006D408;
    }
    // 0x8006D3FC: addiu       $v0, $zero, 0xD
    ctx->r2 = ADD32(0, 0XD);
    // 0x8006D400: bne         $v1, $v0, L_8006D420
    if (ctx->r3 != ctx->r2) {
        // 0x8006D404: nop
    
            goto L_8006D420;
    }
    // 0x8006D404: nop

L_8006D408:
    // 0x8006D408: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8006D40C: lbu         $v0, 0xB63($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0XB63);
    // 0x8006D410: bne         $v0, $zero, L_8006D420
    if (ctx->r2 != 0) {
        // 0x8006D414: slti        $v0, $s2, 0xD
        ctx->r2 = SIGNED(ctx->r18) < 0XD ? 1 : 0;
            goto L_8006D420;
    }
    // 0x8006D414: slti        $v0, $s2, 0xD
    ctx->r2 = SIGNED(ctx->r18) < 0XD ? 1 : 0;
    // 0x8006D418: beql        $v0, $zero, L_8006D420
    if (ctx->r2 == 0) {
        // 0x8006D41C: addiu       $s2, $zero, 0xC
        ctx->r18 = ADD32(0, 0XC);
            goto L_8006D420;
    }
    goto skip_4;
    // 0x8006D41C: addiu       $s2, $zero, 0xC
    ctx->r18 = ADD32(0, 0XC);
    skip_4:
L_8006D420:
    // 0x8006D420: blez        $s2, L_8006D560
    if (SIGNED(ctx->r18) <= 0) {
        // 0x8006D424: addu        $s0, $zero, $zero
        ctx->r16 = ADD32(0, 0);
            goto L_8006D560;
    }
    // 0x8006D424: addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
    // 0x8006D428: addiu       $s4, $sp, 0x38
    ctx->r20 = ADD32(ctx->r29, 0X38);
    // 0x8006D42C: addiu       $s3, $sp, 0x48
    ctx->r19 = ADD32(ctx->r29, 0X48);
    // 0x8006D430: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8006D434: lwc1        $f24, -0x3550($at)
    ctx->f24.u32l = MEM_W(ctx->r1, -0X3550);
L_8006D438:
    // 0x8006D438: lwc1        $f2, 0x38($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0X38);
    // 0x8006D43C: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8006D440: lwc1        $f0, -0x354C($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X354C);
    // 0x8006D444: mul.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x8006D448: addu        $a0, $s4, $zero
    ctx->r4 = ADD32(ctx->r20, 0);
    // 0x8006D44C: addu        $a1, $s3, $zero
    ctx->r5 = ADD32(ctx->r19, 0);
    // 0x8006D450: mfc1        $a2, $f2
    ctx->r6 = (int32_t)ctx->f2.u32l;
    // 0x8006D454: addiu       $a3, $zero, 0x3C
    ctx->r7 = ADD32(0, 0X3C);
    // 0x8006D458: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x8006D45C: jal         0x8007202C
    // 0x8006D460: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    func_8007202C(rdram, ctx);
        goto after_38;
    // 0x8006D460: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    after_38:
    // 0x8006D464: lwc1        $f0, 0x38($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X38);
    // 0x8006D468: lwc1        $f2, 0x0($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0X0);
    // 0x8006D46C: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x8006D470: swc1        $f0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f0.u32l;
    // 0x8006D474: lwc1        $f0, 0x3C($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x8006D478: lwc1        $f2, 0x4($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0X4);
    // 0x8006D47C: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x8006D480: swc1        $f0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f0.u32l;
    // 0x8006D484: lwc1        $f0, 0x40($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X40);
    // 0x8006D488: lwc1        $f2, 0x8($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0X8);
    // 0x8006D48C: lui         $a1, 0x4000
    ctx->r5 = S32(0X4000 << 16);
    // 0x8006D490: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x8006D494: lui         $a2, 0x4060
    ctx->r6 = S32(0X4060 << 16);
    // 0x8006D498: addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    // 0x8006D49C: jal         0x80072300
    // 0x8006D4A0: swc1        $f0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f0.u32l;
    func_80072300(rdram, ctx);
        goto after_39;
    // 0x8006D4A0: swc1        $f0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f0.u32l;
    after_39:
    // 0x8006D4A4: jal         0x80003430
    // 0x8006D4A8: nop

    rand_recomp(rdram, ctx);
        goto after_40;
    // 0x8006D4A8: nop

    after_40:
    // 0x8006D4AC: andi        $v0, $v0, 0x7F
    ctx->r2 = ctx->r2 & 0X7F;
    // 0x8006D4B0: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x8006D4B4: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x8006D4B8: sub.s       $f0, $f0, $f24
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f24.fl;
    // 0x8006D4BC: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8006D4C0: lwc1        $f2, -0x3548($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X3548);
    // 0x8006D4C4: div.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f2.fl);
    // 0x8006D4C8: abs.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f22.fl = fabsf(ctx->f0.fl);
    // 0x8006D4CC: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8006D4D0: lwc1        $f0, -0x3544($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X3544);
    // 0x8006D4D4: jal         0x80003430
    // 0x8006D4D8: add.s       $f22, $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f22.fl = ctx->f22.fl + ctx->f0.fl;
    rand_recomp(rdram, ctx);
        goto after_41;
    // 0x8006D4D8: add.s       $f22, $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f22.fl = ctx->f22.fl + ctx->f0.fl;
    after_41:
    // 0x8006D4DC: andi        $v0, $v0, 0x7F
    ctx->r2 = ctx->r2 & 0X7F;
    // 0x8006D4E0: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x8006D4E4: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x8006D4E8: sub.s       $f0, $f0, $f24
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f24.fl;
    // 0x8006D4EC: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8006D4F0: lwc1        $f2, -0x3540($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X3540);
    // 0x8006D4F4: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x8006D4F8: abs.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f20.fl = fabsf(ctx->f0.fl);
    // 0x8006D4FC: mul.s       $f20, $f20, $f26
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f20.fl = MUL_S(ctx->f20.fl, ctx->f26.fl);
    // 0x8006D500: jal         0x80003430
    // 0x8006D504: add.s       $f20, $f20, $f26
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f20.fl = ctx->f20.fl + ctx->f26.fl;
    rand_recomp(rdram, ctx);
        goto after_42;
    // 0x8006D504: add.s       $f20, $f20, $f26
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f20.fl = ctx->f20.fl + ctx->f26.fl;
    after_42:
    // 0x8006D508: andi        $v0, $v0, 0x7F
    ctx->r2 = ctx->r2 & 0X7F;
    // 0x8006D50C: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x8006D510: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x8006D514: sub.s       $f0, $f0, $f24
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f24.fl;
    // 0x8006D518: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8006D51C: lwc1        $f2, -0x353C($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X353C);
    // 0x8006D520: div.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f2.fl);
    // 0x8006D524: abs.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = fabsf(ctx->f0.fl);
    // 0x8006D528: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8006D52C: lwc1        $f0, -0x3538($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X3538);
    // 0x8006D530: add.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x8006D534: addu        $a0, $s4, $zero
    ctx->r4 = ADD32(ctx->r20, 0);
    // 0x8006D538: mul.s       $f2, $f2, $f28
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f28.fl);
    // 0x8006D53C: addu        $a1, $s3, $zero
    ctx->r5 = ADD32(ctx->r19, 0);
    // 0x8006D540: mfc1        $a2, $f22
    ctx->r6 = (int32_t)ctx->f22.u32l;
    // 0x8006D544: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x8006D548: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8006D54C: jal         0x80072384
    // 0x8006D550: swc1        $f2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f2.u32l;
    func_80072384(rdram, ctx);
        goto after_43;
    // 0x8006D550: swc1        $f2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f2.u32l;
    after_43:
    // 0x8006D554: slt         $v0, $s0, $s2
    ctx->r2 = SIGNED(ctx->r16) < SIGNED(ctx->r18) ? 1 : 0;
    // 0x8006D558: bne         $v0, $zero, L_8006D438
    if (ctx->r2 != 0) {
        // 0x8006D55C: nop
    
            goto L_8006D438;
    }
    // 0x8006D55C: nop

L_8006D560:
    // 0x8006D560: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8006D564: lwc1        $f0, -0x3534($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X3534);
    // 0x8006D568: mul.s       $f20, $f28, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f28.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f20.fl = MUL_S(ctx->f28.fl, ctx->f0.fl);
    // 0x8006D56C: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8006D570: lwc1        $f0, -0x3530($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X3530);
    // 0x8006D574: c.lt.s      $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f20.fl < ctx->f0.fl;
    // 0x8006D578: nop

    // 0x8006D57C: bc1tl       L_8006D584
    if (c1cs) {
        // 0x8006D580: mov.s       $f20, $f0
        CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
            goto L_8006D584;
    }
    goto skip_5;
    // 0x8006D580: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    skip_5:
L_8006D584:
    // 0x8006D584: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8006D588: lwc1        $f0, -0x352C($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X352C);
    // 0x8006D58C: c.lt.s      $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f0.fl < ctx->f20.fl;
    // 0x8006D590: nop

    // 0x8006D594: bc1tl       L_8006D59C
    if (c1cs) {
        // 0x8006D598: mov.s       $f20, $f0
        CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
            goto L_8006D59C;
    }
    goto skip_6;
    // 0x8006D598: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    skip_6:
L_8006D59C:
    // 0x8006D59C: addiu       $s0, $sp, 0x58
    ctx->r16 = ADD32(ctx->r29, 0X58);
    // 0x8006D5A0: lw          $a0, 0x30($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X30);
    // 0x8006D5A4: jal         0x8006AC7C
    // 0x8006D5A8: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    func_8006AC7C(rdram, ctx);
        goto after_44;
    // 0x8006D5A8: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    after_44:
    // 0x8006D5AC: lui         $a2, 0x8014
    ctx->r6 = S32(0X8014 << 16);
    // 0x8006D5B0: addiu       $a2, $a2, -0x7FA8
    ctx->r6 = ADD32(ctx->r6, -0X7FA8);
    // 0x8006D5B4: lwc1        $f12, 0x58($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X58);
    // 0x8006D5B8: lwc1        $f14, 0x60($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X60);
    // 0x8006D5BC: jal         0x80067D90
    // 0x8006D5C0: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    func_80067D90(rdram, ctx);
        goto after_45;
    // 0x8006D5C0: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    after_45:
    // 0x8006D5C4: jal         0x80003430
    // 0x8006D5C8: swc1        $f0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f0.u32l;
    rand_recomp(rdram, ctx);
        goto after_46;
    // 0x8006D5C8: swc1        $f0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f0.u32l;
    after_46:
    // 0x8006D5CC: andi        $v0, $v0, 0x7F
    ctx->r2 = ctx->r2 & 0X7F;
    // 0x8006D5D0: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8006D5D4: lwc1        $f2, -0x3528($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X3528);
    // 0x8006D5D8: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x8006D5DC: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x8006D5E0: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x8006D5E4: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8006D5E8: lwc1        $f2, -0x3524($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X3524);
    // 0x8006D5EC: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x8006D5F0: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x8006D5F4: mov.s       $f2, $f20
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    ctx->f2.fl = ctx->f20.fl;
    // 0x8006D5F8: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8006D5FC: lw          $v0, 0xB50($v0)
    ctx->r2 = MEM_W(ctx->r2, 0XB50);
    // 0x8006D600: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8006D604: lwc1        $f4, -0x3520($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X3520);
    // 0x8006D608: andi        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 & 0X1;
    // 0x8006D60C: beq         $v0, $zero, L_8006D618
    if (ctx->r2 == 0) {
        // 0x8006D610: add.s       $f6, $f0, $f4
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f0.fl + ctx->f4.fl;
            goto L_8006D618;
    }
    // 0x8006D610: add.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f0.fl + ctx->f4.fl;
    // 0x8006D614: div.s       $f2, $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = DIV_S(ctx->f2.fl, ctx->f4.fl);
L_8006D618:
    // 0x8006D618: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8006D61C: lwc1        $f20, -0x351C($at)
    ctx->f20.u32l = MEM_W(ctx->r1, -0X351C);
    // 0x8006D620: mul.s       $f0, $f26, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = MUL_S(ctx->f26.fl, ctx->f20.fl);
    // 0x8006D624: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x8006D628: mfc1        $a2, $f2
    ctx->r6 = (int32_t)ctx->f2.u32l;
    // 0x8006D62C: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x8006D630: ori         $a1, $zero, 0xFFFF
    ctx->r5 = 0 | 0XFFFF;
    // 0x8006D634: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    // 0x8006D638: jal         0x80073750
    // 0x8006D63C: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    func_80073750(rdram, ctx);
        goto after_47;
    // 0x8006D63C: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    after_47:
    // 0x8006D640: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x8006D644: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    // 0x8006D648: addiu       $a2, $s1, 0x24
    ctx->r6 = ADD32(ctx->r17, 0X24);
    // 0x8006D64C: lui         $a3, 0x41C0
    ctx->r7 = S32(0X41C0 << 16);
    // 0x8006D650: addiu       $v0, $zero, 0x22
    ctx->r2 = ADD32(0, 0X22);
    // 0x8006D654: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // 0x8006D658: addiu       $v0, $zero, 0x7F
    ctx->r2 = ADD32(0, 0X7F);
    // 0x8006D65C: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x8006D660: addiu       $v0, $zero, 0x50
    ctx->r2 = ADD32(0, 0X50);
    // 0x8006D664: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    // 0x8006D668: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x8006D66C: jal         0x800989D8
    // 0x8006D670: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    func_800989D8(rdram, ctx);
        goto after_48;
    // 0x8006D670: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    after_48:
    // 0x8006D674: lhu         $a0, 0x3C($s1)
    ctx->r4 = MEM_HU(ctx->r17, 0X3C);
    // 0x8006D678: jal         0x8003E7D0
    // 0x8006D67C: addu        $a1, $s5, $zero
    ctx->r5 = ADD32(ctx->r21, 0);
    func_8003E7D0(rdram, ctx);
        goto after_49;
    // 0x8006D67C: addu        $a1, $s5, $zero
    ctx->r5 = ADD32(ctx->r21, 0);
    after_49:
    // 0x8006D680: lhu         $a0, 0x40($s1)
    ctx->r4 = MEM_HU(ctx->r17, 0X40);
    // 0x8006D684: jal         0x8003E7D0
    // 0x8006D688: addu        $a1, $s5, $zero
    ctx->r5 = ADD32(ctx->r21, 0);
    func_8003E7D0(rdram, ctx);
        goto after_50;
    // 0x8006D688: addu        $a1, $s5, $zero
    ctx->r5 = ADD32(ctx->r21, 0);
    after_50:
    // 0x8006D68C: lhu         $v0, 0x42($s1)
    ctx->r2 = MEM_HU(ctx->r17, 0X42);
    // 0x8006D690: ori         $s0, $zero, 0xFFFF
    ctx->r16 = 0 | 0XFFFF;
    // 0x8006D694: beq         $v0, $s0, L_8006D6A4
    if (ctx->r2 == ctx->r16) {
        // 0x8006D698: addu        $a0, $v0, $zero
        ctx->r4 = ADD32(ctx->r2, 0);
            goto L_8006D6A4;
    }
    // 0x8006D698: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // 0x8006D69C: jal         0x8003E7D0
    // 0x8006D6A0: addu        $a1, $s5, $zero
    ctx->r5 = ADD32(ctx->r21, 0);
    func_8003E7D0(rdram, ctx);
        goto after_51;
    // 0x8006D6A0: addu        $a1, $s5, $zero
    ctx->r5 = ADD32(ctx->r21, 0);
    after_51:
L_8006D6A4:
    // 0x8006D6A4: lhu         $v0, 0x3E($s1)
    ctx->r2 = MEM_HU(ctx->r17, 0X3E);
    // 0x8006D6A8: beq         $v0, $s0, L_8006D6B8
    if (ctx->r2 == ctx->r16) {
        // 0x8006D6AC: addu        $a0, $v0, $zero
        ctx->r4 = ADD32(ctx->r2, 0);
            goto L_8006D6B8;
    }
    // 0x8006D6AC: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // 0x8006D6B0: jal         0x8003E7D0
    // 0x8006D6B4: addu        $a1, $s5, $zero
    ctx->r5 = ADD32(ctx->r21, 0);
    func_8003E7D0(rdram, ctx);
        goto after_52;
    // 0x8006D6B4: addu        $a1, $s5, $zero
    ctx->r5 = ADD32(ctx->r21, 0);
    after_52:
L_8006D6B8:
    // 0x8006D6B8: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8006D6BC: lbu         $v0, 0xB39($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0XB39);
    // 0x8006D6C0: bnel        $v0, $zero, L_8006D70C
    if (ctx->r2 != 0) {
        // 0x8006D6C4: addu        $a0, $s5, $zero
        ctx->r4 = ADD32(ctx->r21, 0);
            goto L_8006D70C;
    }
    goto skip_7;
    // 0x8006D6C4: addu        $a0, $s5, $zero
    ctx->r4 = ADD32(ctx->r21, 0);
    skip_7:
    // 0x8006D6C8: lw          $v1, 0x34($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X34);
    // 0x8006D6CC: lw          $v0, 0x80($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X80);
    // 0x8006D6D0: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // 0x8006D6D4: lw          $v0, 0x34($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X34);
    // 0x8006D6D8: lw          $v0, 0x84($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X84);
    // 0x8006D6DC: sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    // 0x8006D6E0: lw          $a0, 0x78($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X78);
    // 0x8006D6E4: lw          $a1, 0x7C($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X7C);
    // 0x8006D6E8: lw          $a2, 0x70($v1)
    ctx->r6 = MEM_W(ctx->r3, 0X70);
    // 0x8006D6EC: lw          $a3, 0x74($v1)
    ctx->r7 = MEM_W(ctx->r3, 0X74);
    // 0x8006D6F0: jal         0x80065914
    // 0x8006D6F4: nop

    datItemSetObjectiveBooleanCount(rdram, ctx);
        goto after_53;
    // 0x8006D6F4: nop

    after_53:
    // 0x8006D6F8: jal         0x800F3260
    // 0x8006D6FC: addu        $a0, $s5, $zero
    ctx->r4 = ADD32(ctx->r21, 0);
    func_800F3260(rdram, ctx);
        goto after_54;
    // 0x8006D6FC: addu        $a0, $s5, $zero
    ctx->r4 = ADD32(ctx->r21, 0);
    after_54:
    // 0x8006D700: jal         0x800F2AA4
    // 0x8006D704: addu        $a0, $s5, $zero
    ctx->r4 = ADD32(ctx->r21, 0);
    func_800F2AA4(rdram, ctx);
        goto after_55;
    // 0x8006D704: addu        $a0, $s5, $zero
    ctx->r4 = ADD32(ctx->r21, 0);
    after_55:
    // 0x8006D708: addu        $a0, $s5, $zero
    ctx->r4 = ADD32(ctx->r21, 0);
L_8006D70C:
    // 0x8006D70C: jal         0x8006C9C0
    // 0x8006D710: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    func_8006C9C0(rdram, ctx);
        goto after_56;
    // 0x8006D710: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    after_56:
    // 0x8006D714: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x8006D718: bne         $v0, $zero, L_8006D740
    if (ctx->r2 != 0) {
        // 0x8006D71C: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_8006D740;
    }
    // 0x8006D71C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8006D720: sb          $v0, 0x45($s1)
    MEM_B(0X45, ctx->r17) = ctx->r2;
    // 0x8006D724: lhu         $v0, 0x0($s6)
    ctx->r2 = MEM_HU(ctx->r22, 0X0);
    // 0x8006D728: beq         $v0, $s0, L_8006CF00
    if (ctx->r2 == ctx->r16) {
        // 0x8006D72C: nop
    
            goto L_8006CF00;
    }
    // 0x8006D72C: nop

    // 0x8006D730: jal         0x8003ED74
    // 0x8006D734: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    func_8003ED74(rdram, ctx);
        goto after_57;
    // 0x8006D734: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    after_57:
    // 0x8006D738: j           L_8006CF00
    // 0x8006D73C: nop

        goto L_8006CF00;
    // 0x8006D73C: nop

L_8006D740:
    // 0x8006D740: lw          $a1, 0x30($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X30);
    // 0x8006D744: jal         0x80072AF8
    // 0x8006D748: addiu       $a0, $s1, 0x48
    ctx->r4 = ADD32(ctx->r17, 0X48);
    func_80072AF8(rdram, ctx);
        goto after_58;
    // 0x8006D748: addiu       $a0, $s1, 0x48
    ctx->r4 = ADD32(ctx->r17, 0X48);
    after_58:
L_8006D74C:
    // 0x8006D74C: lhu         $v1, 0x0($s6)
    ctx->r3 = MEM_HU(ctx->r22, 0X0);
    // 0x8006D750: ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
    // 0x8006D754: beq         $v1, $v0, L_8006D8C0
    if (ctx->r3 == ctx->r2) {
        // 0x8006D758: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_8006D8C0;
    }
    // 0x8006D758: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8006D75C: jal         0x8003ED74
    // 0x8006D760: addu        $a0, $v1, $zero
    ctx->r4 = ADD32(ctx->r3, 0);
    func_8003ED74(rdram, ctx);
        goto after_59;
    // 0x8006D760: addu        $a0, $v1, $zero
    ctx->r4 = ADD32(ctx->r3, 0);
    after_59:
    // 0x8006D764: j           L_8006D8C0
    // 0x8006D768: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8006D8C0;
    // 0x8006D768: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8006D76C:
    // 0x8006D76C: lbu         $v1, 0x18($s0)
    ctx->r3 = MEM_BU(ctx->r16, 0X18);
    // 0x8006D770: addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
    // 0x8006D774: bne         $v1, $v0, L_8006D890
    if (ctx->r3 != ctx->r2) {
        // 0x8006D778: addu        $s2, $s0, $zero
        ctx->r18 = ADD32(ctx->r16, 0);
            goto L_8006D890;
    }
    // 0x8006D778: addu        $s2, $s0, $zero
    ctx->r18 = ADD32(ctx->r16, 0);
    // 0x8006D77C: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8006D780: lw          $v0, 0x7CE4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X7CE4);
    // 0x8006D784: lw          $v1, 0x34($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X34);
    // 0x8006D788: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8006D78C: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8006D790: lw          $v0, 0x6C($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X6C);
    // 0x8006D794: blez        $v0, L_8006D890
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8006D798: ori         $v0, $zero, 0xFFFF
        ctx->r2 = 0 | 0XFFFF;
            goto L_8006D890;
    }
    // 0x8006D798: ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
    // 0x8006D79C: lhu         $v1, 0x3E($s1)
    ctx->r3 = MEM_HU(ctx->r17, 0X3E);
    // 0x8006D7A0: beq         $v1, $v0, L_8006D7B0
    if (ctx->r3 == ctx->r2) {
        // 0x8006D7A4: addu        $a0, $v1, $zero
        ctx->r4 = ADD32(ctx->r3, 0);
            goto L_8006D7B0;
    }
    // 0x8006D7A4: addu        $a0, $v1, $zero
    ctx->r4 = ADD32(ctx->r3, 0);
    // 0x8006D7A8: jal         0x8003E7D0
    // 0x8006D7AC: addu        $a1, $s5, $zero
    ctx->r5 = ADD32(ctx->r21, 0);
    func_8003E7D0(rdram, ctx);
        goto after_60;
    // 0x8006D7AC: addu        $a1, $s5, $zero
    ctx->r5 = ADD32(ctx->r21, 0);
    after_60:
L_8006D7B0:
    // 0x8006D7B0: lw          $v0, 0x34($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X34);
    // 0x8006D7B4: lw          $v0, 0xA4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0XA4);
    // 0x8006D7B8: bne         $v0, $zero, L_8006D7EC
    if (ctx->r2 != 0) {
        // 0x8006D7BC: lui         $v0, 0x8014
        ctx->r2 = S32(0X8014 << 16);
            goto L_8006D7EC;
    }
    // 0x8006D7BC: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x8006D7C0: addiu       $a1, $v0, -0x6AA0
    ctx->r5 = ADD32(ctx->r2, -0X6AA0);
    // 0x8006D7C4: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x8006D7C8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8006D7CC: bne         $v1, $v0, L_8006D7D8
    if (ctx->r3 != ctx->r2) {
        // 0x8006D7D0: addiu       $a0, $zero, 0x2C
        ctx->r4 = ADD32(0, 0X2C);
            goto L_8006D7D8;
    }
    // 0x8006D7D0: addiu       $a0, $zero, 0x2C
    ctx->r4 = ADD32(0, 0X2C);
    // 0x8006D7D4: addiu       $a0, $zero, 0x2E
    ctx->r4 = ADD32(0, 0X2E);
L_8006D7D8:
    // 0x8006D7D8: addu        $v0, $a0, $a1
    ctx->r2 = ADD32(ctx->r4, ctx->r5);
    // 0x8006D7DC: lhu         $a0, 0x0($v0)
    ctx->r4 = MEM_HU(ctx->r2, 0X0);
    // 0x8006D7E0: jal         0x8003E684
    // 0x8006D7E4: addu        $a1, $s5, $zero
    ctx->r5 = ADD32(ctx->r21, 0);
    func_8003E684(rdram, ctx);
        goto after_61;
    // 0x8006D7E4: addu        $a1, $s5, $zero
    ctx->r5 = ADD32(ctx->r21, 0);
    after_61:
    // 0x8006D7E8: sh          $v0, 0x3E($s1)
    MEM_H(0X3E, ctx->r17) = ctx->r2;
L_8006D7EC:
    // 0x8006D7EC: lhu         $a0, 0x40($s1)
    ctx->r4 = MEM_HU(ctx->r17, 0X40);
    // 0x8006D7F0: jal         0x8003E7D0
    // 0x8006D7F4: addu        $a1, $s5, $zero
    ctx->r5 = ADD32(ctx->r21, 0);
    func_8003E7D0(rdram, ctx);
        goto after_62;
    // 0x8006D7F4: addu        $a1, $s5, $zero
    ctx->r5 = ADD32(ctx->r21, 0);
    after_62:
    // 0x8006D7F8: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x8006D7FC: addiu       $s4, $v0, -0x6AA0
    ctx->r20 = ADD32(ctx->r2, -0X6AA0);
    // 0x8006D800: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x8006D804: addiu       $s3, $zero, 0x1
    ctx->r19 = ADD32(0, 0X1);
    // 0x8006D808: bne         $v0, $s3, L_8006D814
    if (ctx->r2 != ctx->r19) {
        // 0x8006D80C: addiu       $v1, $zero, 0x12
        ctx->r3 = ADD32(0, 0X12);
            goto L_8006D814;
    }
    // 0x8006D80C: addiu       $v1, $zero, 0x12
    ctx->r3 = ADD32(0, 0X12);
    // 0x8006D810: addiu       $v1, $zero, 0xE
    ctx->r3 = ADD32(0, 0XE);
L_8006D814:
    // 0x8006D814: addu        $v0, $v1, $s4
    ctx->r2 = ADD32(ctx->r3, ctx->r20);
    // 0x8006D818: lhu         $a0, 0x0($v0)
    ctx->r4 = MEM_HU(ctx->r2, 0X0);
    // 0x8006D81C: jal         0x8003E684
    // 0x8006D820: addu        $a1, $s5, $zero
    ctx->r5 = ADD32(ctx->r21, 0);
    func_8003E684(rdram, ctx);
        goto after_63;
    // 0x8006D820: addu        $a1, $s5, $zero
    ctx->r5 = ADD32(ctx->r21, 0);
    after_63:
    // 0x8006D824: lhu         $v1, 0x42($s1)
    ctx->r3 = MEM_HU(ctx->r17, 0X42);
    // 0x8006D828: sh          $v0, 0x40($s1)
    MEM_H(0X40, ctx->r17) = ctx->r2;
    // 0x8006D82C: ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
    // 0x8006D830: beq         $v1, $v0, L_8006D874
    if (ctx->r3 == ctx->r2) {
        // 0x8006D834: addu        $a0, $v1, $zero
        ctx->r4 = ADD32(ctx->r3, 0);
            goto L_8006D874;
    }
    // 0x8006D834: addu        $a0, $v1, $zero
    ctx->r4 = ADD32(ctx->r3, 0);
    // 0x8006D838: jal         0x8003E7D0
    // 0x8006D83C: addu        $a1, $s5, $zero
    ctx->r5 = ADD32(ctx->r21, 0);
    func_8003E7D0(rdram, ctx);
        goto after_64;
    // 0x8006D83C: addu        $a1, $s5, $zero
    ctx->r5 = ADD32(ctx->r21, 0);
    after_64:
    // 0x8006D840: lw          $v0, 0x34($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X34);
    // 0x8006D844: lw          $v0, 0x8C($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X8C);
    // 0x8006D848: beq         $v0, $zero, L_8006D874
    if (ctx->r2 == 0) {
        // 0x8006D84C: nop
    
            goto L_8006D874;
    }
    // 0x8006D84C: nop

    // 0x8006D850: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x8006D854: bne         $v0, $s3, L_8006D860
    if (ctx->r2 != ctx->r19) {
        // 0x8006D858: addiu       $v1, $zero, 0x18
        ctx->r3 = ADD32(0, 0X18);
            goto L_8006D860;
    }
    // 0x8006D858: addiu       $v1, $zero, 0x18
    ctx->r3 = ADD32(0, 0X18);
    // 0x8006D85C: addiu       $v1, $zero, 0x1A
    ctx->r3 = ADD32(0, 0X1A);
L_8006D860:
    // 0x8006D860: addu        $v0, $v1, $s4
    ctx->r2 = ADD32(ctx->r3, ctx->r20);
    // 0x8006D864: lhu         $a0, 0x0($v0)
    ctx->r4 = MEM_HU(ctx->r2, 0X0);
    // 0x8006D868: jal         0x8003E684
    // 0x8006D86C: addu        $a1, $s5, $zero
    ctx->r5 = ADD32(ctx->r21, 0);
    func_8003E684(rdram, ctx);
        goto after_65;
    // 0x8006D86C: addu        $a1, $s5, $zero
    ctx->r5 = ADD32(ctx->r21, 0);
    after_65:
    // 0x8006D870: sh          $v0, 0x42($s1)
    MEM_H(0X42, ctx->r17) = ctx->r2;
L_8006D874:
    // 0x8006D874: lhu         $v0, 0x2($s2)
    ctx->r2 = MEM_HU(ctx->r18, 0X2);
    // 0x8006D878: addiu       $v1, $zero, 0x3
    ctx->r3 = ADD32(0, 0X3);
    // 0x8006D87C: subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // 0x8006D880: lhu         $v0, 0x14($s5)
    ctx->r2 = MEM_HU(ctx->r21, 0X14);
    // 0x8006D884: sll         $v1, $v1, 6
    ctx->r3 = S32(ctx->r3 << 6);
    // 0x8006D888: or          $v0, $v0, $v1
    ctx->r2 = ctx->r2 | ctx->r3;
    // 0x8006D88C: sh          $v0, 0x14($s5)
    MEM_H(0X14, ctx->r21) = ctx->r2;
L_8006D890:
    // 0x8006D890: addiu       $v0, $zero, 0x14
    ctx->r2 = ADD32(0, 0X14);
    // 0x8006D894: sh          $v0, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r2;
    // 0x8006D898: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8006D89C: lw          $v0, 0x7CE4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X7CE4);
    // 0x8006D8A0: lw          $v1, 0x34($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X34);
    // 0x8006D8A4: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8006D8A8: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8006D8AC: lw          $v1, 0x6C($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X6C);
    // 0x8006D8B0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8006D8B4: j           L_8006D8C0
    // 0x8006D8B8: sw          $v1, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r3;
        goto L_8006D8C0;
    // 0x8006D8B8: sw          $v1, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r3;
L_8006D8BC:
    // 0x8006D8BC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8006D8C0:
    // 0x8006D8C0: lw          $ra, 0xB4($sp)
    ctx->r31 = MEM_W(ctx->r29, 0XB4);
    // 0x8006D8C4: lw          $s6, 0xB0($sp)
    ctx->r22 = MEM_W(ctx->r29, 0XB0);
    // 0x8006D8C8: lw          $s5, 0xAC($sp)
    ctx->r21 = MEM_W(ctx->r29, 0XAC);
    // 0x8006D8CC: lw          $s4, 0xA8($sp)
    ctx->r20 = MEM_W(ctx->r29, 0XA8);
    // 0x8006D8D0: lw          $s3, 0xA4($sp)
    ctx->r19 = MEM_W(ctx->r29, 0XA4);
    // 0x8006D8D4: lw          $s2, 0xA0($sp)
    ctx->r18 = MEM_W(ctx->r29, 0XA0);
    // 0x8006D8D8: lw          $s1, 0x9C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X9C);
    // 0x8006D8DC: lw          $s0, 0x98($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X98);
    // 0x8006D8E0: ldc1        $f28, 0xD8($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0XD8);
    // 0x8006D8E4: ldc1        $f26, 0xD0($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0XD0);
    // 0x8006D8E8: ldc1        $f24, 0xC8($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0XC8);
    // 0x8006D8EC: ldc1        $f22, 0xC0($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0XC0);
    // 0x8006D8F0: ldc1        $f20, 0xB8($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0XB8);
    // 0x8006D8F4: jr          $ra
    // 0x8006D8F8: addiu       $sp, $sp, 0xE0
    ctx->r29 = ADD32(ctx->r29, 0XE0);
    return;
    // 0x8006D8F8: addiu       $sp, $sp, 0xE0
    ctx->r29 = ADD32(ctx->r29, 0XE0);
;}
RECOMP_FUNC void fake_func_8006D8FC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
;}
RECOMP_FUNC void func_8006D900(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006D900: addiu       $sp, $sp, -0x80
    ctx->r29 = ADD32(ctx->r29, -0X80);
    // 0x8006D904: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    // 0x8006D908: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x8006D90C: addiu       $a2, $zero, 0x5C
    ctx->r6 = ADD32(0, 0X5C);
    // 0x8006D910: sw          $ra, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r31;
    // 0x8006D914: sw          $s1, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r17;
    // 0x8006D918: jal         0x800078E0
    // 0x8006D91C: sw          $s0, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r16;
    rs_memset(rdram, ctx);
        goto after_0;
    // 0x8006D91C: sw          $s0, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r16;
    after_0:
    // 0x8006D920: addiu       $a0, $sp, 0x3C
    ctx->r4 = ADD32(ctx->r29, 0X3C);
    // 0x8006D924: addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
    // 0x8006D928: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8006D92C: lwc1        $f0, -0x34FC($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X34FC);
    // 0x8006D930: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8006D934: lwc1        $f2, -0x34F8($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X34F8);
    // 0x8006D938: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8006D93C: lwc1        $f4, -0x34F4($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X34F4);
    // 0x8006D940: addiu       $v0, $zero, 0x140
    ctx->r2 = ADD32(0, 0X140);
    // 0x8006D944: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x8006D948: addiu       $v0, $zero, 0xE0
    ctx->r2 = ADD32(0, 0XE0);
    // 0x8006D94C: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x8006D950: addiu       $v0, $zero, 0xA0
    ctx->r2 = ADD32(0, 0XA0);
    // 0x8006D954: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    // 0x8006D958: addiu       $v0, $zero, 0x70
    ctx->r2 = ADD32(0, 0X70);
    // 0x8006D95C: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x8006D960: swc1        $f0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f0.u32l;
    // 0x8006D964: swc1        $f2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f2.u32l;
    // 0x8006D968: jal         0x8001CA50
    // 0x8006D96C: swc1        $f4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f4.u32l;
    func_8001CA50(rdram, ctx);
        goto after_1;
    // 0x8006D96C: swc1        $f4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f4.u32l;
    after_1:
    // 0x8006D970: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x8006D974: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x8006D978: jal         0x80017A90
    // 0x8006D97C: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    func_80017A90(rdram, ctx);
        goto after_2;
    // 0x8006D97C: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    after_2:
L_8006D980:
    // 0x8006D980: jal         0x80002FF4
    // 0x8006D984: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    func_80002FF4(rdram, ctx);
        goto after_3;
    // 0x8006D984: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    after_3:
    // 0x8006D988: jal         0x8000A86C
    // 0x8006D98C: nop

    func_8000A86C(rdram, ctx);
        goto after_4;
    // 0x8006D98C: nop

    after_4:
    // 0x8006D990: jal         0x8000A6CC
    // 0x8006D994: nop

    func_8000A6CC(rdram, ctx);
        goto after_5;
    // 0x8006D994: nop

    after_5:
    // 0x8006D998: jal         0x80016C44
    // 0x8006D99C: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    func_80016C44(rdram, ctx);
        goto after_6;
    // 0x8006D99C: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    after_6:
    // 0x8006D9A0: jal         0x8000B6F4
    // 0x8006D9A4: nop

    func_8000B6F4(rdram, ctx);
        goto after_7;
    // 0x8006D9A4: nop

    after_7:
    // 0x8006D9A8: jal         0x8000C07C
    // 0x8006D9AC: nop

    func_8000C07C(rdram, ctx);
        goto after_8;
    // 0x8006D9AC: nop

    after_8:
    // 0x8006D9B0: sltiu       $v0, $s0, 0x20
    ctx->r2 = ctx->r16 < 0X20 ? 1 : 0;
    // 0x8006D9B4: bne         $v0, $zero, L_8006D980
    if (ctx->r2 != 0) {
        // 0x8006D9B8: lui         $a0, 0x8014
        ctx->r4 = S32(0X8014 << 16);
            goto L_8006D980;
    }
    // 0x8006D9B8: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8006D9BC: addiu       $a0, $a0, -0x5A40
    ctx->r4 = ADD32(ctx->r4, -0X5A40);
    // 0x8006D9C0: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x8006D9C4: jal         0x800078E0
    // 0x8006D9C8: addiu       $a2, $zero, 0xB0
    ctx->r6 = ADD32(0, 0XB0);
    rs_memset(rdram, ctx);
        goto after_9;
    // 0x8006D9C8: addiu       $a2, $zero, 0xB0
    ctx->r6 = ADD32(0, 0XB0);
    after_9:
    // 0x8006D9CC: jal         0x8006E53C
    // 0x8006D9D0: lui         $s1, 0x8014
    ctx->r17 = S32(0X8014 << 16);
    func_8006E53C(rdram, ctx);
        goto after_10;
    // 0x8006D9D0: lui         $s1, 0x8014
    ctx->r17 = S32(0X8014 << 16);
    after_10:
    // 0x8006D9D4: lui         $a0, 0x8004
    ctx->r4 = S32(0X8004 << 16);
    // 0x8006D9D8: jal         0x800047F4
    // 0x8006D9DC: addiu       $a0, $a0, -0x3510
    ctx->r4 = ADD32(ctx->r4, -0X3510);
    func_800047F4(rdram, ctx);
        goto after_11;
    // 0x8006D9DC: addiu       $a0, $a0, -0x3510
    ctx->r4 = ADD32(ctx->r4, -0X3510);
    after_11:
    // 0x8006D9E0: lui         $a0, 0x8004
    ctx->r4 = S32(0X8004 << 16);
    // 0x8006D9E4: addiu       $a0, $a0, -0x3508
    ctx->r4 = ADD32(ctx->r4, -0X3508);
    // 0x8006D9E8: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x8006D9EC: sw          $v0, 0x7CFC($v1)
    MEM_W(0X7CFC, ctx->r3) = ctx->r2;
    // 0x8006D9F0: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x8006D9F4: sb          $zero, -0x5A50($s1)
    MEM_B(-0X5A50, ctx->r17) = 0;
    // 0x8006D9F8: jal         0x8006488C
    // 0x8006D9FC: sb          $zero, -0x5A4F($v0)
    MEM_B(-0X5A4F, ctx->r2) = 0;
    load_asset(rdram, ctx);
        goto after_12;
    // 0x8006D9FC: sb          $zero, -0x5A4F($v0)
    MEM_B(-0X5A4F, ctx->r2) = 0;
    after_12:
    // 0x8006DA00: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    // 0x8006DA04: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x8006DA08: lui         $a1, 0x8007
    ctx->r5 = S32(0X8007 << 16);
    // 0x8006DA0C: jal         0x80006338
    // 0x8006DA10: addiu       $a1, $a1, -0xF48
    ctx->r5 = ADD32(ctx->r5, -0XF48);
    func_80006338(rdram, ctx);
        goto after_13;
    // 0x8006DA10: addiu       $a1, $a1, -0xF48
    ctx->r5 = ADD32(ctx->r5, -0XF48);
    after_13:
    // 0x8006DA14: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x8006DA18: bne         $v0, $zero, L_8006DA28
    if (ctx->r2 != 0) {
        // 0x8006DA1C: lui         $v1, 0x8013
        ctx->r3 = S32(0X8013 << 16);
            goto L_8006DA28;
    }
    // 0x8006DA1C: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x8006DA20: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8006DA24: sb          $v0, 0xB6C($v1)
    MEM_B(0XB6C, ctx->r3) = ctx->r2;
L_8006DA28:
    // 0x8006DA28: jal         0x80001C98
    // 0x8006DA2C: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    rs_free(rdram, ctx);
        goto after_14;
    // 0x8006DA2C: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_14:
    // 0x8006DA30: lbu         $v1, -0x5A50($s1)
    ctx->r3 = MEM_BU(ctx->r17, -0X5A50);
    // 0x8006DA34: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8006DA38: bne         $v1, $v0, L_8006DA54
    if (ctx->r3 != ctx->r2) {
        // 0x8006DA3C: nop
    
            goto L_8006DA54;
    }
    // 0x8006DA3C: nop

L_8006DA40:
    // 0x8006DA40: jal         0x8006EC8C
    // 0x8006DA44: nop

    func_8006EC8C(rdram, ctx);
        goto after_15;
    // 0x8006DA44: nop

    after_15:
    // 0x8006DA48: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x8006DA4C: j           L_8006DA7C
    // 0x8006DA50: sb          $zero, -0x5A50($v0)
    MEM_B(-0X5A50, ctx->r2) = 0;
        goto L_8006DA7C;
    // 0x8006DA50: sb          $zero, -0x5A50($v0)
    MEM_B(-0X5A50, ctx->r2) = 0;
L_8006DA54:
    // 0x8006DA54: jal         0x8006F10C
    // 0x8006DA58: nop

    func_8006F10C(rdram, ctx);
        goto after_16;
    // 0x8006DA58: nop

    after_16:
    // 0x8006DA5C: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x8006DA60: beq         $v0, $zero, L_8006DA40
    if (ctx->r2 == 0) {
        // 0x8006DA64: nop
    
            goto L_8006DA40;
    }
    // 0x8006DA64: nop

    // 0x8006DA68: jal         0x8006F388
    // 0x8006DA6C: nop

    func_8006F388(rdram, ctx);
        goto after_17;
    // 0x8006DA6C: nop

    after_17:
    // 0x8006DA70: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x8006DA74: bne         $v0, $zero, L_8006DA40
    if (ctx->r2 != 0) {
        // 0x8006DA78: nop
    
            goto L_8006DA40;
    }
    // 0x8006DA78: nop

L_8006DA7C:
    // 0x8006DA7C: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8006DA80: lw          $a0, 0x7CFC($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X7CFC);
    // 0x8006DA84: jal         0x80004994
    // 0x8006DA88: addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
    func_80004994(rdram, ctx);
        goto after_18;
    // 0x8006DA88: addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
    after_18:
    // 0x8006DA8C: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8006DA90: sb          $zero, 0xB3A($v0)
    MEM_B(0XB3A, ctx->r2) = 0;
    // 0x8006DA94: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8006DA98: sb          $zero, 0xB39($v0)
    MEM_B(0XB39, ctx->r2) = 0;
    // 0x8006DA9C: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8006DAA0: sb          $zero, 0xBA0($v0)
    MEM_B(0XBA0, ctx->r2) = 0;
    // 0x8006DAA4: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8006DAA8: sb          $zero, 0xB38($v0)
    MEM_B(0XB38, ctx->r2) = 0;
    // 0x8006DAAC: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8006DAB0: addiu       $v0, $v0, 0xB10
    ctx->r2 = ADD32(ctx->r2, 0XB10);
    // 0x8006DAB4: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x8006DAB8: sb          $v1, 0x20($v0)
    MEM_B(0X20, ctx->r2) = ctx->r3;
    // 0x8006DABC: sb          $zero, 0x21($v0)
    MEM_B(0X21, ctx->r2) = 0;
L_8006DAC0:
    // 0x8006DAC0: jal         0x80002FF4
    // 0x8006DAC4: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    func_80002FF4(rdram, ctx);
        goto after_19;
    // 0x8006DAC4: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    after_19:
    // 0x8006DAC8: jal         0x8000A86C
    // 0x8006DACC: nop

    func_8000A86C(rdram, ctx);
        goto after_20;
    // 0x8006DACC: nop

    after_20:
    // 0x8006DAD0: jal         0x8000A6CC
    // 0x8006DAD4: nop

    func_8000A6CC(rdram, ctx);
        goto after_21;
    // 0x8006DAD4: nop

    after_21:
    // 0x8006DAD8: jal         0x80016C44
    // 0x8006DADC: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    func_80016C44(rdram, ctx);
        goto after_22;
    // 0x8006DADC: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    after_22:
    // 0x8006DAE0: jal         0x8000B6F4
    // 0x8006DAE4: nop

    func_8000B6F4(rdram, ctx);
        goto after_23;
    // 0x8006DAE4: nop

    after_23:
    // 0x8006DAE8: jal         0x8000C07C
    // 0x8006DAEC: nop

    func_8000C07C(rdram, ctx);
        goto after_24;
    // 0x8006DAEC: nop

    after_24:
    // 0x8006DAF0: sltiu       $v0, $s0, 0x8
    ctx->r2 = ctx->r16 < 0X8 ? 1 : 0;
    // 0x8006DAF4: bne         $v0, $zero, L_8006DAC0
    if (ctx->r2 != 0) {
        // 0x8006DAF8: nop
    
            goto L_8006DAC0;
    }
    // 0x8006DAF8: nop

    // 0x8006DAFC: jal         0x80079EF4
    // 0x8006DB00: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    func_80079EF4(rdram, ctx);
        goto after_25;
    // 0x8006DB00: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    after_25:
    // 0x8006DB04: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x8006DB08: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x8006DB0C: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8006DB10: jal         0x8006E018
    // 0x8006DB14: sb          $v0, 0xB56($v1)
    MEM_B(0XB56, ctx->r3) = ctx->r2;
    func_8006E018(rdram, ctx);
        goto after_26;
    // 0x8006DB14: sb          $v0, 0xB56($v1)
    MEM_B(0XB56, ctx->r3) = ctx->r2;
    after_26:
    // 0x8006DB18: lw          $ra, 0x78($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X78);
    // 0x8006DB1C: lw          $s1, 0x74($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X74);
    // 0x8006DB20: lw          $s0, 0x70($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X70);
    // 0x8006DB24: jr          $ra
    // 0x8006DB28: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
    return;
    // 0x8006DB28: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
;}
RECOMP_FUNC void func_8006DB2C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006DB2C: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x8006DB30: sw          $s5, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r21;
    // 0x8006DB34: addu        $s5, $a0, $zero
    ctx->r21 = ADD32(ctx->r4, 0);
    // 0x8006DB38: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
    // 0x8006DB3C: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8006DB40: addiu       $a1, $v0, 0xB10
    ctx->r5 = ADD32(ctx->r2, 0XB10);
    // 0x8006DB44: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x8006DB48: sw          $ra, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r31;
    // 0x8006DB4C: sw          $s7, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r23;
    // 0x8006DB50: sw          $s6, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r22;
    // 0x8006DB54: sw          $s4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r20;
    // 0x8006DB58: sw          $s3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r19;
    // 0x8006DB5C: sw          $s2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r18;
    // 0x8006DB60: sw          $s1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r17;
    // 0x8006DB64: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x8006DB68: andi        $v0, $v1, 0xFF
    ctx->r2 = ctx->r3 & 0XFF;
    // 0x8006DB6C: addu        $v0, $v0, $a1
    ctx->r2 = ADD32(ctx->r2, ctx->r5);
L_8006DB70:
    // 0x8006DB70: sb          $a0, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r4;
    // 0x8006DB74: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8006DB78: andi        $v0, $v1, 0xFF
    ctx->r2 = ctx->r3 & 0XFF;
    // 0x8006DB7C: beq         $v0, $zero, L_8006DB70
    if (ctx->r2 == 0) {
        // 0x8006DB80: addu        $v0, $v0, $a1
        ctx->r2 = ADD32(ctx->r2, ctx->r5);
            goto L_8006DB70;
    }
    // 0x8006DB80: addu        $v0, $v0, $a1
    ctx->r2 = ADD32(ctx->r2, ctx->r5);
    // 0x8006DB84: andi        $v0, $s5, 0xFF
    ctx->r2 = ctx->r21 & 0XFF;
    // 0x8006DB88: sll         $v1, $v0, 2
    ctx->r3 = S32(ctx->r2 << 2);
    // 0x8006DB8C: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x8006DB90: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x8006DB94: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x8006DB98: addiu       $v0, $v0, -0x5A2C
    ctx->r2 = ADD32(ctx->r2, -0X5A2C);
    // 0x8006DB9C: addu        $s2, $v1, $v0
    ctx->r18 = ADD32(ctx->r3, ctx->r2);
    // 0x8006DBA0: addu        $s1, $zero, $zero
    ctx->r17 = ADD32(0, 0);
    // 0x8006DBA4: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8006DBA8: addiu       $s7, $v0, 0xB10
    ctx->r23 = ADD32(ctx->r2, 0XB10);
    // 0x8006DBAC: lui         $s6, 0xFF80
    ctx->r22 = S32(0XFF80 << 16);
    // 0x8006DBB0: ori         $s6, $s6, 0x1FF
    ctx->r22 = ctx->r22 | 0X1FF;
    // 0x8006DBB4: lui         $s4, 0x7F
    ctx->r20 = S32(0X7F << 16);
    // 0x8006DBB8: ori         $s4, $s4, 0xFE00
    ctx->r20 = ctx->r20 | 0XFE00;
    // 0x8006DBBC: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8006DBC0: addiu       $v0, $v0, 0xB47
    ctx->r2 = ADD32(ctx->r2, 0XB47);
    // 0x8006DBC4: addiu       $s0, $v0, -0x7
    ctx->r16 = ADD32(ctx->r2, -0X7);
    // 0x8006DBC8: addu        $s3, $v0, $zero
    ctx->r19 = ADD32(ctx->r2, 0);
L_8006DBCC:
    // 0x8006DBCC: addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    // 0x8006DBD0: addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    // 0x8006DBD4: addiu       $s3, $s3, 0x4
    ctx->r19 = ADD32(ctx->r19, 0X4);
    // 0x8006DBD8: addu        $v1, $s1, $s7
    ctx->r3 = ADD32(ctx->r17, ctx->r23);
    // 0x8006DBDC: lbu         $v0, 0x4($s2)
    ctx->r2 = MEM_BU(ctx->r18, 0X4);
    // 0x8006DBE0: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x8006DBE4: jal         0x8000761C
    // 0x8006DBE8: sb          $v0, 0x1($v1)
    MEM_B(0X1, ctx->r3) = ctx->r2;
    rs_strcpy(rdram, ctx);
        goto after_0;
    // 0x8006DBE8: sb          $v0, 0x1($v1)
    MEM_B(0X1, ctx->r3) = ctx->r2;
    after_0:
    // 0x8006DBEC: lw          $v1, 0xC($s0)
    ctx->r3 = MEM_W(ctx->r16, 0XC);
    // 0x8006DBF0: lw          $v0, 0xC($s2)
    ctx->r2 = MEM_W(ctx->r18, 0XC);
    // 0x8006DBF4: and         $v1, $v1, $s6
    ctx->r3 = ctx->r3 & ctx->r22;
    // 0x8006DBF8: and         $v0, $v0, $s4
    ctx->r2 = ctx->r2 & ctx->r20;
    // 0x8006DBFC: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x8006DC00: sw          $v1, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r3;
    // 0x8006DC04: beq         $s1, $zero, L_8006DBCC
    if (ctx->r17 == 0) {
        // 0x8006DC08: addiu       $s0, $s0, 0x4
        ctx->r16 = ADD32(ctx->r16, 0X4);
            goto L_8006DBCC;
    }
    // 0x8006DC08: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x8006DC0C: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // 0x8006DC10: addiu       $a1, $sp, 0x10
    ctx->r5 = ADD32(ctx->r29, 0X10);
    // 0x8006DC14: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x8006DC18: lbu         $v0, 0x5($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X5);
    // 0x8006DC1C: addiu       $s0, $s0, 0xB10
    ctx->r16 = ADD32(ctx->r16, 0XB10);
    // 0x8006DC20: sb          $v0, 0x1F($s0)
    MEM_B(0X1F, ctx->r16) = ctx->r2;
    // 0x8006DC24: lbu         $v0, 0x5($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X5);
    // 0x8006DC28: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x8006DC2C: sb          $v0, 0xB40($v1)
    MEM_B(0XB40, ctx->r3) = ctx->r2;
    // 0x8006DC30: lbu         $v0, 0x10($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X10);
    // 0x8006DC34: addiu       $s1, $v1, 0xB40
    ctx->r17 = ADD32(ctx->r3, 0XB40);
    // 0x8006DC38: sb          $s5, 0x4($s1)
    MEM_B(0X4, ctx->r17) = ctx->r21;
    // 0x8006DC3C: jal         0x8006EB48
    // 0x8006DC40: sb          $v0, 0x24($s0)
    MEM_B(0X24, ctx->r16) = ctx->r2;
    func_8006EB48(rdram, ctx);
        goto after_1;
    // 0x8006DC40: sb          $v0, 0x24($s0)
    MEM_B(0X24, ctx->r16) = ctx->r2;
    after_1:
    // 0x8006DC44: addiu       $a0, $s0, 0xC
    ctx->r4 = ADD32(ctx->r16, 0XC);
    // 0x8006DC48: addiu       $a1, $sp, 0x10
    ctx->r5 = ADD32(ctx->r29, 0X10);
    // 0x8006DC4C: jal         0x80018EF4
    // 0x8006DC50: addiu       $a2, $zero, 0x13
    ctx->r6 = ADD32(0, 0X13);
    zmemcpy(rdram, ctx);
        goto after_2;
    // 0x8006DC50: addiu       $a2, $zero, 0x13
    ctx->r6 = ADD32(0, 0X13);
    after_2:
    // 0x8006DC54: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8006DC58: sb          $v0, 0x21($s0)
    MEM_B(0X21, ctx->r16) = ctx->r2;
    // 0x8006DC5C: lw          $v0, 0x18($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X18);
    // 0x8006DC60: lui         $v1, 0x100
    ctx->r3 = S32(0X100 << 16);
    // 0x8006DC64: and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // 0x8006DC68: beq         $v0, $zero, L_8006DC80
    if (ctx->r2 == 0) {
        // 0x8006DC6C: lui         $v1, 0x1
        ctx->r3 = S32(0X1 << 16);
            goto L_8006DC80;
    }
    // 0x8006DC6C: lui         $v1, 0x1
    ctx->r3 = S32(0X1 << 16);
    // 0x8006DC70: lw          $v0, 0xC($s1)
    ctx->r2 = MEM_W(ctx->r17, 0XC);
    // 0x8006DC74: ori         $v1, $v1, 0xFE00
    ctx->r3 = ctx->r3 | 0XFE00;
    // 0x8006DC78: or          $v0, $v0, $v1
    ctx->r2 = ctx->r2 | ctx->r3;
    // 0x8006DC7C: sw          $v0, 0xC($s1)
    MEM_W(0XC, ctx->r17) = ctx->r2;
L_8006DC80:
    // 0x8006DC80: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x8006DC84: addiu       $a0, $v0, -0x5A40
    ctx->r4 = ADD32(ctx->r2, -0X5A40);
    // 0x8006DC88: lbu         $v1, 0x51($a0)
    ctx->r3 = MEM_BU(ctx->r4, 0X51);
    // 0x8006DC8C: andi        $v0, $s5, 0xFF
    ctx->r2 = ctx->r21 & 0XFF;
    // 0x8006DC90: beq         $v1, $v0, L_8006DCA0
    if (ctx->r3 == ctx->r2) {
        // 0x8006DC94: nop
    
            goto L_8006DCA0;
    }
    // 0x8006DC94: nop

    // 0x8006DC98: jal         0x8006F1A8
    // 0x8006DC9C: sb          $s5, 0x51($a0)
    MEM_B(0X51, ctx->r4) = ctx->r21;
    func_8006F1A8(rdram, ctx);
        goto after_3;
    // 0x8006DC9C: sb          $s5, 0x51($a0)
    MEM_B(0X51, ctx->r4) = ctx->r21;
    after_3:
L_8006DCA0:
    // 0x8006DCA0: lw          $ra, 0x48($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X48);
    // 0x8006DCA4: lw          $s7, 0x44($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X44);
    // 0x8006DCA8: lw          $s6, 0x40($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X40);
    // 0x8006DCAC: lw          $s5, 0x3C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X3C);
    // 0x8006DCB0: lw          $s4, 0x38($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X38);
    // 0x8006DCB4: lw          $s3, 0x34($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X34);
    // 0x8006DCB8: lw          $s2, 0x30($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X30);
    // 0x8006DCBC: lw          $s1, 0x2C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X2C);
    // 0x8006DCC0: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x8006DCC4: jr          $ra
    // 0x8006DCC8: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x8006DCC8: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}
RECOMP_FUNC void loadDefaultHighscores(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006DCCC: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    // 0x8006DCD0: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x8006DCD4: addiu       $t2, $v0, -0x5A40
    ctx->r10 = ADD32(ctx->r2, -0X5A40);
    // 0x8006DCD8: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x8006DCDC: addiu       $t1, $v0, 0xA64
    ctx->r9 = ADD32(ctx->r2, 0XA64);
    // 0x8006DCE0: addiu       $t0, $zero, 0x9
    ctx->r8 = ADD32(0, 0X9);
L_8006DCE4:
    // 0x8006DCE4: sll         $a1, $a3, 24
    ctx->r5 = S32(ctx->r7 << 24);
    // 0x8006DCE8: sra         $a1, $a1, 24
    ctx->r5 = S32(SIGNED(ctx->r5) >> 24);
    // 0x8006DCEC: sll         $a0, $a1, 2
    ctx->r4 = S32(ctx->r5 << 2);
    // 0x8006DCF0: addu        $a0, $a0, $t1
    ctx->r4 = ADD32(ctx->r4, ctx->r9);
    // 0x8006DCF4: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8006DCF8: sll         $v1, $a1, 3
    ctx->r3 = S32(ctx->r5 << 3);
    // 0x8006DCFC: lbu         $v0, 0x0($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X0);
    // 0x8006DD00: addu        $v1, $v1, $t2
    ctx->r3 = ADD32(ctx->r3, ctx->r10);
    // 0x8006DD04: sb          $v0, 0x52($v1)
    MEM_B(0X52, ctx->r3) = ctx->r2;
    // 0x8006DD08: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8006DD0C: subu        $a2, $t0, $a3
    ctx->r6 = SUB32(ctx->r8, ctx->r7);
    // 0x8006DD10: lbu         $v0, 0x1($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X1);
    // 0x8006DD14: subu        $a1, $t0, $a1
    ctx->r5 = SUB32(ctx->r8, ctx->r5);
    // 0x8006DD18: sb          $v0, 0x53($v1)
    MEM_B(0X53, ctx->r3) = ctx->r2;
    // 0x8006DD1C: addiu       $v0, $a3, 0x1
    ctx->r2 = ADD32(ctx->r7, 0X1);
    // 0x8006DD20: addu        $a3, $v0, $zero
    ctx->r7 = ADD32(ctx->r2, 0);
    // 0x8006DD24: sll         $v0, $v0, 24
    ctx->r2 = S32(ctx->r2 << 24);
    // 0x8006DD28: lw          $a0, 0x0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X0);
    // 0x8006DD2C: sra         $v0, $v0, 24
    ctx->r2 = S32(SIGNED(ctx->r2) >> 24);
    // 0x8006DD30: lbu         $a0, 0x2($a0)
    ctx->r4 = MEM_BU(ctx->r4, 0X2);
    // 0x8006DD34: slti        $v0, $v0, 0xA
    ctx->r2 = SIGNED(ctx->r2) < 0XA ? 1 : 0;
    // 0x8006DD38: sh          $a1, 0x56($v1)
    MEM_H(0X56, ctx->r3) = ctx->r5;
    // 0x8006DD3C: sb          $a2, 0x55($v1)
    MEM_B(0X55, ctx->r3) = ctx->r6;
    // 0x8006DD40: bne         $v0, $zero, L_8006DCE4
    if (ctx->r2 != 0) {
        // 0x8006DD44: sb          $a0, 0x54($v1)
        MEM_B(0X54, ctx->r3) = ctx->r4;
            goto L_8006DCE4;
    }
    // 0x8006DD44: sb          $a0, 0x54($v1)
    MEM_B(0X54, ctx->r3) = ctx->r4;
    // 0x8006DD48: jr          $ra
    // 0x8006DD4C: nop

    return;
    // 0x8006DD4C: nop

;}
RECOMP_FUNC void func_8006DD50(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006DD50: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8006DD54: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x8006DD58: addu        $s2, $a0, $zero
    ctx->r18 = ADD32(ctx->r4, 0);
    // 0x8006DD5C: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x8006DD60: addu        $s3, $zero, $zero
    ctx->r19 = ADD32(0, 0);
    // 0x8006DD64: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8006DD68: addiu       $a1, $v0, 0xB10
    ctx->r5 = ADD32(ctx->r2, 0XB10);
    // 0x8006DD6C: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    // 0x8006DD70: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8006DD74: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x8006DD78: sw          $s6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r22;
    // 0x8006DD7C: sw          $s5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r21;
    // 0x8006DD80: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x8006DD84: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x8006DD88: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8006DD8C: sb          $zero, 0xB64($v0)
    MEM_B(0XB64, ctx->r2) = 0;
    // 0x8006DD90: sb          $zero, 0x12($sp)
    MEM_B(0X12, ctx->r29) = 0;
    // 0x8006DD94: sb          $zero, 0x11($sp)
    MEM_B(0X11, ctx->r29) = 0;
    // 0x8006DD98: sb          $zero, 0x10($sp)
    MEM_B(0X10, ctx->r29) = 0;
    // 0x8006DD9C: addu        $v1, $s3, $a1
    ctx->r3 = ADD32(ctx->r19, ctx->r5);
L_8006DDA0:
    // 0x8006DDA0: lbu         $v0, 0xC($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0XC);
    // 0x8006DDA4: beq         $v0, $zero, L_8006DDC4
    if (ctx->r2 == 0) {
        // 0x8006DDA8: addiu       $s3, $s3, 0x1
        ctx->r19 = ADD32(ctx->r19, 0X1);
            goto L_8006DDC4;
    }
    // 0x8006DDA8: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x8006DDAC: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // 0x8006DDB0: addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
    // 0x8006DDB4: addu        $v1, $a0, $v1
    ctx->r3 = ADD32(ctx->r4, ctx->r3);
    // 0x8006DDB8: lbu         $v0, 0x0($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X0);
    // 0x8006DDBC: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8006DDC0: sb          $v0, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r2;
L_8006DDC4:
    // 0x8006DDC4: slti        $v0, $s3, 0x13
    ctx->r2 = SIGNED(ctx->r19) < 0X13 ? 1 : 0;
    // 0x8006DDC8: bne         $v0, $zero, L_8006DDA0
    if (ctx->r2 != 0) {
        // 0x8006DDCC: addu        $v1, $s3, $a1
        ctx->r3 = ADD32(ctx->r19, ctx->r5);
            goto L_8006DDA0;
    }
    // 0x8006DDCC: addu        $v1, $s3, $a1
    ctx->r3 = ADD32(ctx->r19, ctx->r5);
    // 0x8006DDD0: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
    // 0x8006DDD4: addu        $s3, $zero, $zero
    ctx->r19 = ADD32(0, 0);
    // 0x8006DDD8: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x8006DDDC: addiu       $a1, $v0, -0x5A40
    ctx->r5 = ADD32(ctx->r2, -0X5A40);
    // 0x8006DDE0: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8006DDE4: lbu         $a0, 0x11($sp)
    ctx->r4 = MEM_BU(ctx->r29, 0X11);
    // 0x8006DDE8: lbu         $a3, 0xB34($v0)
    ctx->r7 = MEM_BU(ctx->r2, 0XB34);
    // 0x8006DDEC: lbu         $v1, 0x10($sp)
    ctx->r3 = MEM_BU(ctx->r29, 0X10);
    // 0x8006DDF0: lbu         $v0, 0x12($sp)
    ctx->r2 = MEM_BU(ctx->r29, 0X12);
    // 0x8006DDF4: sll         $a0, $a0, 5
    ctx->r4 = S32(ctx->r4 << 5);
    // 0x8006DDF8: or          $v1, $v1, $a0
    ctx->r3 = ctx->r3 | ctx->r4;
    // 0x8006DDFC: sll         $v0, $v0, 10
    ctx->r2 = S32(ctx->r2 << 10);
    // 0x8006DE00: or          $s1, $v1, $v0
    ctx->r17 = ctx->r3 | ctx->r2;
L_8006DE04:
    // 0x8006DE04: lbu         $v0, 0x58($a1)
    ctx->r2 = MEM_BU(ctx->r5, 0X58);
    // 0x8006DE08: beql        $v0, $a3, L_8006DE20
    if (ctx->r2 == ctx->r7) {
        // 0x8006DE0C: addu        $a2, $s3, $zero
        ctx->r6 = ADD32(ctx->r19, 0);
            goto L_8006DE20;
    }
    goto skip_0;
    // 0x8006DE0C: addu        $a2, $s3, $zero
    ctx->r6 = ADD32(ctx->r19, 0);
    skip_0:
    // 0x8006DE10: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x8006DE14: slti        $v0, $s3, 0xA
    ctx->r2 = SIGNED(ctx->r19) < 0XA ? 1 : 0;
    // 0x8006DE18: bne         $v0, $zero, L_8006DE04
    if (ctx->r2 != 0) {
        // 0x8006DE1C: addiu       $a1, $a1, 0x8
        ctx->r5 = ADD32(ctx->r5, 0X8);
            goto L_8006DE04;
    }
    // 0x8006DE1C: addiu       $a1, $a1, 0x8
    ctx->r5 = ADD32(ctx->r5, 0X8);
L_8006DE20:
    // 0x8006DE20: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x8006DE24: beq         $a2, $v0, L_8006DE40
    if (ctx->r6 == ctx->r2) {
        // 0x8006DE28: andi        $a0, $a2, 0xFF
        ctx->r4 = ctx->r6 & 0XFF;
            goto L_8006DE40;
    }
    // 0x8006DE28: andi        $a0, $a2, 0xFF
    ctx->r4 = ctx->r6 & 0XFF;
    // 0x8006DE2C: j           L_8006DEB8
    // 0x8006DE30: andi        $a2, $s2, 0xFF
    ctx->r6 = ctx->r18 & 0XFF;
        goto L_8006DEB8;
    // 0x8006DE30: andi        $a2, $s2, 0xFF
    ctx->r6 = ctx->r18 & 0XFF;
L_8006DE34:
    // 0x8006DE34: addiu       $v0, $s3, 0x1
    ctx->r2 = ADD32(ctx->r19, 0X1);
    // 0x8006DE38: j           L_8006DFF0
    // 0x8006DE3C: sb          $v0, 0xB64($v1)
    MEM_B(0XB64, ctx->r3) = ctx->r2;
        goto L_8006DFF0;
    // 0x8006DE3C: sb          $v0, 0xB64($v1)
    MEM_B(0XB64, ctx->r3) = ctx->r2;
L_8006DE40:
    // 0x8006DE40: addu        $s3, $zero, $zero
    ctx->r19 = ADD32(0, 0);
    // 0x8006DE44: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x8006DE48: addiu       $s0, $v0, -0x5A40
    ctx->r16 = ADD32(ctx->r2, -0X5A40);
L_8006DE4C:
    // 0x8006DE4C: jal         0x8006F3E8
    // 0x8006DE50: andi        $a0, $s3, 0xFF
    ctx->r4 = ctx->r19 & 0XFF;
    getAccountHighscore(rdram, ctx);
        goto after_0;
    // 0x8006DE50: andi        $a0, $s3, 0xFF
    ctx->r4 = ctx->r19 & 0XFF;
    after_0:
    // 0x8006DE54: slt         $v0, $s1, $v0
    ctx->r2 = SIGNED(ctx->r17) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8006DE58: bnel        $v0, $zero, L_8006DEE4
    if (ctx->r2 != 0) {
        // 0x8006DE5C: addiu       $s3, $s3, 0x1
        ctx->r19 = ADD32(ctx->r19, 0X1);
            goto L_8006DEE4;
    }
    goto skip_1;
    // 0x8006DE5C: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    skip_1:
    // 0x8006DE60: addiu       $s1, $zero, 0x8
    ctx->r17 = ADD32(0, 0X8);
    // 0x8006DE64: slt         $v0, $s1, $s3
    ctx->r2 = SIGNED(ctx->r17) < SIGNED(ctx->r19) ? 1 : 0;
    // 0x8006DE68: bne         $v0, $zero, L_8006DEB4
    if (ctx->r2 != 0) {
        // 0x8006DE6C: andi        $a0, $s3, 0xFF
        ctx->r4 = ctx->r19 & 0XFF;
            goto L_8006DEB4;
    }
    // 0x8006DE6C: andi        $a0, $s3, 0xFF
    ctx->r4 = ctx->r19 & 0XFF;
    // 0x8006DE70: addiu       $a0, $s0, 0x40
    ctx->r4 = ADD32(ctx->r16, 0X40);
    // 0x8006DE74: addiu       $v1, $zero, 0x48
    ctx->r3 = ADD32(0, 0X48);
L_8006DE78:
    // 0x8006DE78: addu        $v0, $v1, $s0
    ctx->r2 = ADD32(ctx->r3, ctx->r16);
    // 0x8006DE7C: lwl         $t0, 0x52($a0)
    ctx->r8 = do_lwl(rdram, ctx->r8, ctx->r4, 0X52);
    // 0x8006DE80: lwr         $t0, 0x55($a0)
    ctx->r8 = do_lwr(rdram, ctx->r8, ctx->r4, 0X55);
    // 0x8006DE84: lwl         $t1, 0x56($a0)
    ctx->r9 = do_lwl(rdram, ctx->r9, ctx->r4, 0X56);
    // 0x8006DE88: lwr         $t1, 0x59($a0)
    ctx->r9 = do_lwr(rdram, ctx->r9, ctx->r4, 0X59);
    // 0x8006DE8C: swl         $t0, 0x52($v0)
    do_swl(rdram, 0X52, ctx->r2, ctx->r8);
    // 0x8006DE90: swr         $t0, 0x55($v0)
    do_swr(rdram, 0X55, ctx->r2, ctx->r8);
    // 0x8006DE94: swl         $t1, 0x56($v0)
    do_swl(rdram, 0X56, ctx->r2, ctx->r9);
    // 0x8006DE98: swr         $t1, 0x59($v0)
    do_swr(rdram, 0X59, ctx->r2, ctx->r9);
    // 0x8006DE9C: addiu       $a0, $a0, -0x8
    ctx->r4 = ADD32(ctx->r4, -0X8);
    // 0x8006DEA0: addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
    // 0x8006DEA4: slt         $v0, $s1, $s3
    ctx->r2 = SIGNED(ctx->r17) < SIGNED(ctx->r19) ? 1 : 0;
    // 0x8006DEA8: beq         $v0, $zero, L_8006DE78
    if (ctx->r2 == 0) {
        // 0x8006DEAC: addiu       $v1, $v1, -0x8
        ctx->r3 = ADD32(ctx->r3, -0X8);
            goto L_8006DE78;
    }
    // 0x8006DEAC: addiu       $v1, $v1, -0x8
    ctx->r3 = ADD32(ctx->r3, -0X8);
    // 0x8006DEB0: andi        $a0, $s3, 0xFF
    ctx->r4 = ctx->r19 & 0XFF;
L_8006DEB4:
    // 0x8006DEB4: andi        $a2, $s2, 0xFF
    ctx->r6 = ctx->r18 & 0XFF;
L_8006DEB8:
    // 0x8006DEB8: lbu         $v1, 0x11($sp)
    ctx->r3 = MEM_BU(ctx->r29, 0X11);
    // 0x8006DEBC: lbu         $a1, 0x10($sp)
    ctx->r5 = MEM_BU(ctx->r29, 0X10);
    // 0x8006DEC0: lbu         $v0, 0x12($sp)
    ctx->r2 = MEM_BU(ctx->r29, 0X12);
    // 0x8006DEC4: sll         $v1, $v1, 5
    ctx->r3 = S32(ctx->r3 << 5);
    // 0x8006DEC8: or          $a1, $a1, $v1
    ctx->r5 = ctx->r5 | ctx->r3;
    // 0x8006DECC: sll         $v0, $v0, 10
    ctx->r2 = S32(ctx->r2 << 10);
    // 0x8006DED0: or          $a1, $a1, $v0
    ctx->r5 = ctx->r5 | ctx->r2;
    // 0x8006DED4: jal         0x8006F39C
    // 0x8006DED8: andi        $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 & 0XFFFF;
    setAccountHighscore(rdram, ctx);
        goto after_1;
    // 0x8006DED8: andi        $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 & 0XFFFF;
    after_1:
    // 0x8006DEDC: j           L_8006DEF4
    // 0x8006DEE0: addu        $s3, $zero, $zero
    ctx->r19 = ADD32(0, 0);
        goto L_8006DEF4;
    // 0x8006DEE0: addu        $s3, $zero, $zero
    ctx->r19 = ADD32(0, 0);
L_8006DEE4:
    // 0x8006DEE4: slti        $v0, $s3, 0xA
    ctx->r2 = SIGNED(ctx->r19) < 0XA ? 1 : 0;
    // 0x8006DEE8: bne         $v0, $zero, L_8006DE4C
    if (ctx->r2 != 0) {
        // 0x8006DEEC: nop
    
            goto L_8006DE4C;
    }
    // 0x8006DEEC: nop

    // 0x8006DEF0: addu        $s3, $zero, $zero
    ctx->r19 = ADD32(0, 0);
L_8006DEF4:
    // 0x8006DEF4: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x8006DEF8: addiu       $s6, $v0, -0x5A40
    ctx->r22 = ADD32(ctx->r2, -0X5A40);
    // 0x8006DEFC: addu        $s5, $s6, $zero
    ctx->r21 = ADD32(ctx->r22, 0);
L_8006DF00:
    // 0x8006DF00: addiu       $s1, $s3, 0x1
    ctx->r17 = ADD32(ctx->r19, 0X1);
    // 0x8006DF04: slti        $v0, $s1, 0xA
    ctx->r2 = SIGNED(ctx->r17) < 0XA ? 1 : 0;
    // 0x8006DF08: beql        $v0, $zero, L_8006DFAC
    if (ctx->r2 == 0) {
        // 0x8006DF0C: addiu       $s3, $s3, 0x1
        ctx->r19 = ADD32(ctx->r19, 0X1);
            goto L_8006DFAC;
    }
    goto skip_2;
    // 0x8006DF0C: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    skip_2:
    // 0x8006DF10: addu        $s4, $s5, $zero
    ctx->r20 = ADD32(ctx->r21, 0);
    // 0x8006DF14: sll         $v0, $s1, 3
    ctx->r2 = S32(ctx->r17 << 3);
    // 0x8006DF18: addu        $s2, $v0, $s6
    ctx->r18 = ADD32(ctx->r2, ctx->r22);
L_8006DF1C:
    // 0x8006DF1C: jal         0x8006F3E8
    // 0x8006DF20: andi        $a0, $s3, 0xFF
    ctx->r4 = ctx->r19 & 0XFF;
    getAccountHighscore(rdram, ctx);
        goto after_2;
    // 0x8006DF20: andi        $a0, $s3, 0xFF
    ctx->r4 = ctx->r19 & 0XFF;
    after_2:
    // 0x8006DF24: andi        $a0, $s1, 0xFF
    ctx->r4 = ctx->r17 & 0XFF;
    // 0x8006DF28: jal         0x8006F3E8
    // 0x8006DF2C: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    getAccountHighscore(rdram, ctx);
        goto after_3;
    // 0x8006DF2C: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    after_3:
    // 0x8006DF30: slt         $s0, $s0, $v0
    ctx->r16 = SIGNED(ctx->r16) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8006DF34: beq         $s0, $zero, L_8006DF9C
    if (ctx->r16 == 0) {
        // 0x8006DF38: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_8006DF9C;
    }
    // 0x8006DF38: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x8006DF3C: lwl         $t0, 0x52($s4)
    ctx->r8 = do_lwl(rdram, ctx->r8, ctx->r20, 0X52);
    // 0x8006DF40: lwr         $t0, 0x55($s4)
    ctx->r8 = do_lwr(rdram, ctx->r8, ctx->r20, 0X55);
    // 0x8006DF44: lwl         $t1, 0x56($s4)
    ctx->r9 = do_lwl(rdram, ctx->r9, ctx->r20, 0X56);
    // 0x8006DF48: lwr         $t1, 0x59($s4)
    ctx->r9 = do_lwr(rdram, ctx->r9, ctx->r20, 0X59);
    // 0x8006DF4C: swl         $t0, 0x18($sp)
    do_swl(rdram, 0X18, ctx->r29, ctx->r8);
    // 0x8006DF50: swr         $t0, 0x1B($sp)
    do_swr(rdram, 0X1B, ctx->r29, ctx->r8);
    // 0x8006DF54: swl         $t1, 0x1C($sp)
    do_swl(rdram, 0X1C, ctx->r29, ctx->r9);
    // 0x8006DF58: swr         $t1, 0x1F($sp)
    do_swr(rdram, 0X1F, ctx->r29, ctx->r9);
    // 0x8006DF5C: lwl         $t0, 0x52($s2)
    ctx->r8 = do_lwl(rdram, ctx->r8, ctx->r18, 0X52);
    // 0x8006DF60: lwr         $t0, 0x55($s2)
    ctx->r8 = do_lwr(rdram, ctx->r8, ctx->r18, 0X55);
    // 0x8006DF64: lwl         $t1, 0x56($s2)
    ctx->r9 = do_lwl(rdram, ctx->r9, ctx->r18, 0X56);
    // 0x8006DF68: lwr         $t1, 0x59($s2)
    ctx->r9 = do_lwr(rdram, ctx->r9, ctx->r18, 0X59);
    // 0x8006DF6C: swl         $t0, 0x52($s4)
    do_swl(rdram, 0X52, ctx->r20, ctx->r8);
    // 0x8006DF70: swr         $t0, 0x55($s4)
    do_swr(rdram, 0X55, ctx->r20, ctx->r8);
    // 0x8006DF74: swl         $t1, 0x56($s4)
    do_swl(rdram, 0X56, ctx->r20, ctx->r9);
    // 0x8006DF78: swr         $t1, 0x59($s4)
    do_swr(rdram, 0X59, ctx->r20, ctx->r9);
    // 0x8006DF7C: lwl         $t0, 0x18($sp)
    ctx->r8 = do_lwl(rdram, ctx->r8, ctx->r29, 0X18);
    // 0x8006DF80: lwr         $t0, 0x1B($sp)
    ctx->r8 = do_lwr(rdram, ctx->r8, ctx->r29, 0X1B);
    // 0x8006DF84: lwl         $t1, 0x1C($sp)
    ctx->r9 = do_lwl(rdram, ctx->r9, ctx->r29, 0X1C);
    // 0x8006DF88: lwr         $t1, 0x1F($sp)
    ctx->r9 = do_lwr(rdram, ctx->r9, ctx->r29, 0X1F);
    // 0x8006DF8C: swl         $t0, 0x52($s2)
    do_swl(rdram, 0X52, ctx->r18, ctx->r8);
    // 0x8006DF90: swr         $t0, 0x55($s2)
    do_swr(rdram, 0X55, ctx->r18, ctx->r8);
    // 0x8006DF94: swl         $t1, 0x56($s2)
    do_swl(rdram, 0X56, ctx->r18, ctx->r9);
    // 0x8006DF98: swr         $t1, 0x59($s2)
    do_swr(rdram, 0X59, ctx->r18, ctx->r9);
L_8006DF9C:
    // 0x8006DF9C: slti        $v0, $s1, 0xA
    ctx->r2 = SIGNED(ctx->r17) < 0XA ? 1 : 0;
    // 0x8006DFA0: bne         $v0, $zero, L_8006DF1C
    if (ctx->r2 != 0) {
        // 0x8006DFA4: addiu       $s2, $s2, 0x8
        ctx->r18 = ADD32(ctx->r18, 0X8);
            goto L_8006DF1C;
    }
    // 0x8006DFA4: addiu       $s2, $s2, 0x8
    ctx->r18 = ADD32(ctx->r18, 0X8);
    // 0x8006DFA8: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
L_8006DFAC:
    // 0x8006DFAC: slti        $v0, $s3, 0xA
    ctx->r2 = SIGNED(ctx->r19) < 0XA ? 1 : 0;
    // 0x8006DFB0: bne         $v0, $zero, L_8006DF00
    if (ctx->r2 != 0) {
        // 0x8006DFB4: addiu       $s5, $s5, 0x8
        ctx->r21 = ADD32(ctx->r21, 0X8);
            goto L_8006DF00;
    }
    // 0x8006DFB4: addiu       $s5, $s5, 0x8
    ctx->r21 = ADD32(ctx->r21, 0X8);
    // 0x8006DFB8: addu        $s3, $zero, $zero
    ctx->r19 = ADD32(0, 0);
    // 0x8006DFBC: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x8006DFC0: addiu       $v1, $v0, -0x5A40
    ctx->r3 = ADD32(ctx->r2, -0X5A40);
    // 0x8006DFC4: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8006DFC8: lbu         $a0, 0xB34($v0)
    ctx->r4 = MEM_BU(ctx->r2, 0XB34);
    // 0x8006DFCC: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8006DFD0: sb          $zero, 0xB64($v0)
    MEM_B(0XB64, ctx->r2) = 0;
L_8006DFD4:
    // 0x8006DFD4: lbu         $v0, 0x58($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X58);
    // 0x8006DFD8: beql        $v0, $a0, L_8006DE34
    if (ctx->r2 == ctx->r4) {
        // 0x8006DFDC: lui         $v1, 0x8013
        ctx->r3 = S32(0X8013 << 16);
            goto L_8006DE34;
    }
    goto skip_3;
    // 0x8006DFDC: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    skip_3:
    // 0x8006DFE0: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x8006DFE4: slti        $v0, $s3, 0xA
    ctx->r2 = SIGNED(ctx->r19) < 0XA ? 1 : 0;
    // 0x8006DFE8: bne         $v0, $zero, L_8006DFD4
    if (ctx->r2 != 0) {
        // 0x8006DFEC: addiu       $v1, $v1, 0x8
        ctx->r3 = ADD32(ctx->r3, 0X8);
            goto L_8006DFD4;
    }
    // 0x8006DFEC: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
L_8006DFF0:
    // 0x8006DFF0: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x8006DFF4: lw          $s6, 0x38($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X38);
    // 0x8006DFF8: lw          $s5, 0x34($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X34);
    // 0x8006DFFC: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x8006E000: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x8006E004: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x8006E008: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x8006E00C: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8006E010: jr          $ra
    // 0x8006E014: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x8006E014: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void func_8006E018(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006E018: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8006E01C: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x8006E020: addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
    // 0x8006E024: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8006E028: addiu       $v0, $v0, 0xB40
    ctx->r2 = ADD32(ctx->r2, 0XB40);
    // 0x8006E02C: addu        $a1, $v0, $zero
    ctx->r5 = ADD32(ctx->r2, 0);
    // 0x8006E030: addiu       $a3, $zero, -0x8C
    ctx->r7 = ADD32(0, -0X8C);
    // 0x8006E034: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x8006E038: lw          $v1, -0x5A40($v0)
    ctx->r3 = MEM_W(ctx->r2, -0X5A40);
    // 0x8006E03C: addiu       $a2, $v0, -0x5A40
    ctx->r6 = ADD32(ctx->r2, -0X5A40);
    // 0x8006E040: sw          $ra, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r31;
    // 0x8006E044: sw          $s5, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r21;
    // 0x8006E048: sw          $s4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r20;
    // 0x8006E04C: sw          $s3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r19;
    // 0x8006E050: sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // 0x8006E054: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x8006E058: sw          $v1, 0x10($a1)
    MEM_W(0X10, ctx->r5) = ctx->r3;
L_8006E05C:
    // 0x8006E05C: andi        $a0, $s0, 0xFF
    ctx->r4 = ctx->r16 & 0XFF;
    // 0x8006E060: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8006E064: sll         $a0, $a0, 2
    ctx->r4 = S32(ctx->r4 << 2);
    // 0x8006E068: addu        $a0, $a0, $a1
    ctx->r4 = ADD32(ctx->r4, ctx->r5);
    // 0x8006E06C: lw          $v1, 0xC($a0)
    ctx->r3 = MEM_W(ctx->r4, 0XC);
    // 0x8006E070: lw          $v0, 0x4($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X4);
    // 0x8006E074: and         $v1, $v1, $a3
    ctx->r3 = ctx->r3 & ctx->r7;
    // 0x8006E078: andi        $v0, $v0, 0x8B
    ctx->r2 = ctx->r2 & 0X8B;
    // 0x8006E07C: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x8006E080: andi        $v0, $s0, 0xFF
    ctx->r2 = ctx->r16 & 0XFF;
    // 0x8006E084: beq         $v0, $zero, L_8006E05C
    if (ctx->r2 == 0) {
        // 0x8006E088: sw          $v1, 0xC($a0)
        MEM_W(0XC, ctx->r4) = ctx->r3;
            goto L_8006E05C;
    }
    // 0x8006E088: sw          $v1, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r3;
    // 0x8006E08C: addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
    // 0x8006E090: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x8006E094: addiu       $v0, $v0, -0x5A40
    ctx->r2 = ADD32(ctx->r2, -0X5A40);
    // 0x8006E098: addu        $s4, $v0, $zero
    ctx->r20 = ADD32(ctx->r2, 0);
    // 0x8006E09C: addiu       $s5, $zero, 0x1
    ctx->r21 = ADD32(0, 0X1);
    // 0x8006E0A0: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8006E0A4: addiu       $v0, $v0, 0xB40
    ctx->r2 = ADD32(ctx->r2, 0XB40);
    // 0x8006E0A8: lbu         $v1, 0x10($s4)
    ctx->r3 = MEM_BU(ctx->r20, 0X10);
    // 0x8006E0AC: lbu         $a0, 0x11($s4)
    ctx->r4 = MEM_BU(ctx->r20, 0X11);
    // 0x8006E0B0: lbu         $a1, 0x12($s4)
    ctx->r5 = MEM_BU(ctx->r20, 0X12);
    // 0x8006E0B4: lbu         $a2, 0x13($s4)
    ctx->r6 = MEM_BU(ctx->r20, 0X13);
    // 0x8006E0B8: lbu         $a3, 0xA8($s4)
    ctx->r7 = MEM_BU(ctx->r20, 0XA8);
    // 0x8006E0BC: addu        $s3, $v0, $zero
    ctx->r19 = ADD32(ctx->r2, 0);
    // 0x8006E0C0: sw          $zero, 0x18($s3)
    MEM_W(0X18, ctx->r19) = 0;
    // 0x8006E0C4: sw          $zero, 0x1C($s3)
    MEM_W(0X1C, ctx->r19) = 0;
    // 0x8006E0C8: sb          $v1, 0x20($s3)
    MEM_B(0X20, ctx->r19) = ctx->r3;
    // 0x8006E0CC: sb          $a0, 0x21($s3)
    MEM_B(0X21, ctx->r19) = ctx->r4;
    // 0x8006E0D0: sb          $a1, 0x22($s3)
    MEM_B(0X22, ctx->r19) = ctx->r5;
    // 0x8006E0D4: sb          $a2, 0x5($s3)
    MEM_B(0X5, ctx->r19) = ctx->r6;
    // 0x8006E0D8: sb          $a3, 0x6($s3)
    MEM_B(0X6, ctx->r19) = ctx->r7;
    // 0x8006E0DC: andi        $a0, $s0, 0xFF
    ctx->r4 = ctx->r16 & 0XFF;
L_8006E0E0:
    // 0x8006E0E0: srl         $v0, $a0, 5
    ctx->r2 = S32(U32(ctx->r4) >> 5);
    // 0x8006E0E4: sll         $s2, $v0, 2
    ctx->r18 = S32(ctx->r2 << 2);
    // 0x8006E0E8: addu        $v0, $s2, $s4
    ctx->r2 = ADD32(ctx->r18, ctx->r20);
    // 0x8006E0EC: andi        $v1, $s0, 0x1F
    ctx->r3 = ctx->r16 & 0X1F;
    // 0x8006E0F0: lw          $v0, 0x8($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X8);
    // 0x8006E0F4: sllv        $s1, $s5, $v1
    ctx->r17 = S32(ctx->r21 << (ctx->r3 & 31));
    // 0x8006E0F8: and         $v0, $v0, $s1
    ctx->r2 = ctx->r2 & ctx->r17;
    // 0x8006E0FC: beql        $v0, $zero, L_8006E128
    if (ctx->r2 == 0) {
        // 0x8006E100: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_8006E128;
    }
    goto skip_0;
    // 0x8006E100: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    skip_0:
    // 0x8006E104: jal         0x800824B8
    // 0x8006E108: nop

    func_800824B8(rdram, ctx);
        goto after_0;
    // 0x8006E108: nop

    after_0:
    // 0x8006E10C: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x8006E110: beq         $v0, $zero, L_8006E124
    if (ctx->r2 == 0) {
        // 0x8006E114: addu        $v1, $s2, $s3
        ctx->r3 = ADD32(ctx->r18, ctx->r19);
            goto L_8006E124;
    }
    // 0x8006E114: addu        $v1, $s2, $s3
    ctx->r3 = ADD32(ctx->r18, ctx->r19);
    // 0x8006E118: lw          $v0, 0x18($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X18);
    // 0x8006E11C: or          $v0, $v0, $s1
    ctx->r2 = ctx->r2 | ctx->r17;
    // 0x8006E120: sw          $v0, 0x18($v1)
    MEM_W(0X18, ctx->r3) = ctx->r2;
L_8006E124:
    // 0x8006E124: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_8006E128:
    // 0x8006E128: andi        $v0, $s0, 0xFF
    ctx->r2 = ctx->r16 & 0XFF;
    // 0x8006E12C: sltiu       $v0, $v0, 0x1D
    ctx->r2 = ctx->r2 < 0X1D ? 1 : 0;
    // 0x8006E130: bne         $v0, $zero, L_8006E0E0
    if (ctx->r2 != 0) {
        // 0x8006E134: andi        $a0, $s0, 0xFF
        ctx->r4 = ctx->r16 & 0XFF;
            goto L_8006E0E0;
    }
    // 0x8006E134: andi        $a0, $s0, 0xFF
    ctx->r4 = ctx->r16 & 0XFF;
    // 0x8006E138: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8006E13C: addiu       $a0, $v0, 0xB40
    ctx->r4 = ADD32(ctx->r2, 0XB40);
    // 0x8006E140: lbu         $v0, 0x23($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X23);
    // 0x8006E144: bne         $v0, $zero, L_8006E178
    if (ctx->r2 != 0) {
        // 0x8006E148: lui         $v0, 0x8014
        ctx->r2 = S32(0X8014 << 16);
            goto L_8006E178;
    }
    // 0x8006E148: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x8006E14C: lw          $v0, 0x10($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X10);
    // 0x8006E150: addiu       $v1, $zero, -0x2
    ctx->r3 = ADD32(0, -0X2);
    // 0x8006E154: and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // 0x8006E158: sw          $v0, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->r2;
    // 0x8006E15C: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x8006E160: lbu         $v1, -0x5997($v0)
    ctx->r3 = MEM_BU(ctx->r2, -0X5997);
    // 0x8006E164: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8006E168: beq         $v1, $v0, L_8006E190
    if (ctx->r3 == ctx->r2) {
        // 0x8006E16C: nop
    
            goto L_8006E190;
    }
    // 0x8006E16C: nop

    // 0x8006E170: j           L_8006E198
    // 0x8006E174: nop

        goto L_8006E198;
    // 0x8006E174: nop

L_8006E178:
    // 0x8006E178: lbu         $v0, -0x5997($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X5997);
    // 0x8006E17C: bne         $v0, $zero, L_8006E198
    if (ctx->r2 != 0) {
        // 0x8006E180: nop
    
            goto L_8006E198;
    }
    // 0x8006E180: nop

    // 0x8006E184: lw          $v0, 0x10($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X10);
    // 0x8006E188: ori         $v0, $v0, 0x1
    ctx->r2 = ctx->r2 | 0X1;
    // 0x8006E18C: sw          $v0, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->r2;
L_8006E190:
    // 0x8006E190: jal         0x8006E1BC
    // 0x8006E194: nop

    func_8006E1BC(rdram, ctx);
        goto after_1;
    // 0x8006E194: nop

    after_1:
L_8006E198:
    // 0x8006E198: lw          $ra, 0x28($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X28);
    // 0x8006E19C: lw          $s5, 0x24($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X24);
    // 0x8006E1A0: lw          $s4, 0x20($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X20);
    // 0x8006E1A4: lw          $s3, 0x1C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X1C);
    // 0x8006E1A8: lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X18);
    // 0x8006E1AC: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x8006E1B0: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x8006E1B4: jr          $ra
    // 0x8006E1B8: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x8006E1B8: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_8006E1BC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006E1BC: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x8006E1C0: sw          $s2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r18;
    // 0x8006E1C4: addu        $s2, $zero, $zero
    ctx->r18 = ADD32(0, 0);
    // 0x8006E1C8: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8006E1CC: addiu       $v0, $v0, 0xB40
    ctx->r2 = ADD32(ctx->r2, 0XB40);
    // 0x8006E1D0: sw          $s4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r20;
    // 0x8006E1D4: addu        $s4, $v0, $zero
    ctx->r20 = ADD32(ctx->r2, 0);
    // 0x8006E1D8: sw          $s5, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r21;
    // 0x8006E1DC: addiu       $s5, $zero, 0x1
    ctx->r21 = ADD32(0, 0X1);
    // 0x8006E1E0: lui         $v1, 0x8014
    ctx->r3 = S32(0X8014 << 16);
    // 0x8006E1E4: addiu       $v0, $v1, -0x5A40
    ctx->r2 = ADD32(ctx->r3, -0X5A40);
    // 0x8006E1E8: sw          $ra, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r31;
    // 0x8006E1EC: sw          $s3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r19;
    // 0x8006E1F0: sw          $s1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r17;
    // 0x8006E1F4: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x8006E1F8: lw          $a0, 0x10($s4)
    ctx->r4 = MEM_W(ctx->r20, 0X10);
    // 0x8006E1FC: addu        $s3, $v0, $zero
    ctx->r19 = ADD32(ctx->r2, 0);
    // 0x8006E200: sw          $zero, 0x8($s3)
    MEM_W(0X8, ctx->r19) = 0;
    // 0x8006E204: sw          $zero, 0xC($s3)
    MEM_W(0XC, ctx->r19) = 0;
    // 0x8006E208: sw          $a0, -0x5A40($v1)
    MEM_W(-0X5A40, ctx->r3) = ctx->r4;
    // 0x8006E20C: lw          $v0, 0xC($s4)
    ctx->r2 = MEM_W(ctx->r20, 0XC);
    // 0x8006E210: lbu         $v1, 0x20($s4)
    ctx->r3 = MEM_BU(ctx->r20, 0X20);
    // 0x8006E214: lbu         $a0, 0x21($s4)
    ctx->r4 = MEM_BU(ctx->r20, 0X21);
    // 0x8006E218: lbu         $a1, 0x22($s4)
    ctx->r5 = MEM_BU(ctx->r20, 0X22);
    // 0x8006E21C: lbu         $a2, 0x5($s4)
    ctx->r6 = MEM_BU(ctx->r20, 0X5);
    // 0x8006E220: lbu         $a3, 0x6($s4)
    ctx->r7 = MEM_BU(ctx->r20, 0X6);
    // 0x8006E224: andi        $v0, $v0, 0x8B
    ctx->r2 = ctx->r2 & 0X8B;
    // 0x8006E228: sw          $v0, 0x4($s3)
    MEM_W(0X4, ctx->r19) = ctx->r2;
    // 0x8006E22C: sb          $v1, 0x10($s3)
    MEM_B(0X10, ctx->r19) = ctx->r3;
    // 0x8006E230: sb          $a0, 0x11($s3)
    MEM_B(0X11, ctx->r19) = ctx->r4;
    // 0x8006E234: sb          $a1, 0x12($s3)
    MEM_B(0X12, ctx->r19) = ctx->r5;
    // 0x8006E238: sb          $a2, 0x13($s3)
    MEM_B(0X13, ctx->r19) = ctx->r6;
    // 0x8006E23C: sb          $a3, 0xA8($s3)
    MEM_B(0XA8, ctx->r19) = ctx->r7;
    // 0x8006E240: andi        $a0, $s2, 0xFF
    ctx->r4 = ctx->r18 & 0XFF;
L_8006E244:
    // 0x8006E244: srl         $v0, $a0, 5
    ctx->r2 = S32(U32(ctx->r4) >> 5);
    // 0x8006E248: sll         $s1, $v0, 2
    ctx->r17 = S32(ctx->r2 << 2);
    // 0x8006E24C: addu        $v0, $s1, $s4
    ctx->r2 = ADD32(ctx->r17, ctx->r20);
    // 0x8006E250: andi        $v1, $s2, 0x1F
    ctx->r3 = ctx->r18 & 0X1F;
    // 0x8006E254: lw          $v0, 0x18($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X18);
    // 0x8006E258: sllv        $s0, $s5, $v1
    ctx->r16 = S32(ctx->r21 << (ctx->r3 & 31));
    // 0x8006E25C: and         $v0, $v0, $s0
    ctx->r2 = ctx->r2 & ctx->r16;
    // 0x8006E260: beql        $v0, $zero, L_8006E28C
    if (ctx->r2 == 0) {
        // 0x8006E264: addiu       $s2, $s2, 0x1
        ctx->r18 = ADD32(ctx->r18, 0X1);
            goto L_8006E28C;
    }
    goto skip_0;
    // 0x8006E264: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    skip_0:
    // 0x8006E268: jal         0x800824B8
    // 0x8006E26C: nop

    func_800824B8(rdram, ctx);
        goto after_0;
    // 0x8006E26C: nop

    after_0:
    // 0x8006E270: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x8006E274: beq         $v0, $zero, L_8006E288
    if (ctx->r2 == 0) {
        // 0x8006E278: addu        $v1, $s1, $s3
        ctx->r3 = ADD32(ctx->r17, ctx->r19);
            goto L_8006E288;
    }
    // 0x8006E278: addu        $v1, $s1, $s3
    ctx->r3 = ADD32(ctx->r17, ctx->r19);
    // 0x8006E27C: lw          $v0, 0x8($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X8);
    // 0x8006E280: or          $v0, $v0, $s0
    ctx->r2 = ctx->r2 | ctx->r16;
    // 0x8006E284: sw          $v0, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r2;
L_8006E288:
    // 0x8006E288: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
L_8006E28C:
    // 0x8006E28C: andi        $v0, $s2, 0xFF
    ctx->r2 = ctx->r18 & 0XFF;
    // 0x8006E290: sltiu       $v0, $v0, 0x1D
    ctx->r2 = ctx->r2 < 0X1D ? 1 : 0;
    // 0x8006E294: bne         $v0, $zero, L_8006E244
    if (ctx->r2 != 0) {
        // 0x8006E298: andi        $a0, $s2, 0xFF
        ctx->r4 = ctx->r18 & 0XFF;
            goto L_8006E244;
    }
    // 0x8006E298: andi        $a0, $s2, 0xFF
    ctx->r4 = ctx->r18 & 0XFF;
    // 0x8006E29C: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x8006E2A0: addiu       $s0, $v0, -0x5A40
    ctx->r16 = ADD32(ctx->r2, -0X5A40);
    // 0x8006E2A4: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8006E2A8: addiu       $s1, $v0, 0xB40
    ctx->r17 = ADD32(ctx->r2, 0XB40);
    // 0x8006E2AC: lbu         $v1, 0x23($s1)
    ctx->r3 = MEM_BU(ctx->r17, 0X23);
    // 0x8006E2B0: lw          $a0, 0x28($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X28);
    // 0x8006E2B4: addiu       $v0, $zero, 0x3A
    ctx->r2 = ADD32(0, 0X3A);
    // 0x8006E2B8: sb          $v0, 0xA2($s0)
    MEM_B(0XA2, ctx->r16) = ctx->r2;
    // 0x8006E2BC: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x8006E2C0: sb          $v1, 0xA9($s0)
    MEM_B(0XA9, ctx->r16) = ctx->r3;
    // 0x8006E2C4: lw          $v1, 0xA60($v0)
    ctx->r3 = MEM_W(ctx->r2, 0XA60);
    // 0x8006E2C8: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x8006E2CC: bne         $v1, $v0, L_8006E334
    if (ctx->r3 != ctx->r2) {
        // 0x8006E2D0: sw          $a0, 0xAC($s0)
        MEM_W(0XAC, ctx->r16) = ctx->r4;
            goto L_8006E334;
    }
    // 0x8006E2D0: sw          $a0, 0xAC($s0)
    MEM_W(0XAC, ctx->r16) = ctx->r4;
    // 0x8006E2D4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8006E2D8: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x8006E2DC: addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    // 0x8006E2E0: addiu       $a3, $sp, 0x18
    ctx->r7 = ADD32(ctx->r29, 0X18);
    // 0x8006E2E4: addiu       $s2, $zero, 0xB0
    ctx->r18 = ADD32(0, 0XB0);
    // 0x8006E2E8: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x8006E2EC: jal         0x80006798
    // 0x8006E2F0: sw          $s2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r18;
    func_80006798(rdram, ctx);
        goto after_1;
    // 0x8006E2F0: sw          $s2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r18;
    after_1:
    // 0x8006E2F4: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x8006E2F8: bne         $v0, $zero, L_8006E308
    if (ctx->r2 != 0) {
        // 0x8006E2FC: addiu       $a0, $zero, 0x1
        ctx->r4 = ADD32(0, 0X1);
            goto L_8006E308;
    }
    // 0x8006E2FC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8006E300: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8006E304: sb          $v0, 0x2C($s1)
    MEM_B(0X2C, ctx->r17) = ctx->r2;
L_8006E308:
    // 0x8006E308: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x8006E30C: addu        $a2, $a0, $zero
    ctx->r6 = ADD32(ctx->r4, 0);
    // 0x8006E310: addiu       $a3, $sp, 0x18
    ctx->r7 = ADD32(ctx->r29, 0X18);
    // 0x8006E314: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x8006E318: jal         0x80006798
    // 0x8006E31C: sw          $s2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r18;
    func_80006798(rdram, ctx);
        goto after_2;
    // 0x8006E31C: sw          $s2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r18;
    after_2:
    // 0x8006E320: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x8006E324: bne         $v0, $zero, L_8006E33C
    if (ctx->r2 != 0) {
        // 0x8006E328: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_8006E33C;
    }
    // 0x8006E328: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8006E32C: j           L_8006E33C
    // 0x8006E330: sb          $v0, 0x2C($s1)
    MEM_B(0X2C, ctx->r17) = ctx->r2;
        goto L_8006E33C;
    // 0x8006E330: sb          $v0, 0x2C($s1)
    MEM_B(0X2C, ctx->r17) = ctx->r2;
L_8006E334:
    // 0x8006E334: jal         0x8006F274
    // 0x8006E338: nop

    func_8006F274(rdram, ctx);
        goto after_3;
    // 0x8006E338: nop

    after_3:
L_8006E33C:
    // 0x8006E33C: lw          $ra, 0x40($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X40);
    // 0x8006E340: lw          $s5, 0x3C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X3C);
    // 0x8006E344: lw          $s4, 0x38($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X38);
    // 0x8006E348: lw          $s3, 0x34($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X34);
    // 0x8006E34C: lw          $s2, 0x30($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X30);
    // 0x8006E350: lw          $s1, 0x2C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X2C);
    // 0x8006E354: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x8006E358: jr          $ra
    // 0x8006E35C: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x8006E35C: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void func_8006E360(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006E360: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8006E364: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x8006E368: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x8006E36C: addiu       $s0, $v0, -0x5A40
    ctx->r16 = ADD32(ctx->r2, -0X5A40);
    // 0x8006E370: andi        $v0, $a0, 0xFF
    ctx->r2 = ctx->r4 & 0XFF;
    // 0x8006E374: srl         $v1, $v0, 3
    ctx->r3 = S32(U32(ctx->r2) >> 3);
    // 0x8006E378: addu        $v0, $v1, $s0
    ctx->r2 = ADD32(ctx->r3, ctx->r16);
    // 0x8006E37C: sw          $ra, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r31;
    // 0x8006E380: sw          $s3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r19;
    // 0x8006E384: sw          $s2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r18;
    // 0x8006E388: sw          $s1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r17;
    // 0x8006E38C: lbu         $v0, 0xA3($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0XA3);
    // 0x8006E390: andi        $a0, $a0, 0x7
    ctx->r4 = ctx->r4 & 0X7;
    // 0x8006E394: srav        $v0, $v0, $a0
    ctx->r2 = S32(SIGNED(ctx->r2) >> (ctx->r4 & 31));
    // 0x8006E398: andi        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 & 0X1;
    // 0x8006E39C: bne         $v0, $zero, L_8006E44C
    if (ctx->r2 != 0) {
        // 0x8006E3A0: addu        $v0, $v1, $s0
        ctx->r2 = ADD32(ctx->r3, ctx->r16);
            goto L_8006E44C;
    }
    // 0x8006E3A0: addu        $v0, $v1, $s0
    ctx->r2 = ADD32(ctx->r3, ctx->r16);
    // 0x8006E3A4: addiu       $s3, $zero, 0x1
    ctx->r19 = ADD32(0, 0X1);
    // 0x8006E3A8: sllv        $a0, $s3, $a0
    ctx->r4 = S32(ctx->r19 << (ctx->r4 & 31));
    // 0x8006E3AC: lbu         $v1, 0xA3($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0XA3);
    // 0x8006E3B0: lui         $s2, 0x800A
    ctx->r18 = S32(0X800A << 16);
    // 0x8006E3B4: or          $v1, $v1, $a0
    ctx->r3 = ctx->r3 | ctx->r4;
    // 0x8006E3B8: sb          $v1, 0xA3($v0)
    MEM_B(0XA3, ctx->r2) = ctx->r3;
    // 0x8006E3BC: lw          $a0, 0xA60($s2)
    ctx->r4 = MEM_W(ctx->r18, 0XA60);
    // 0x8006E3C0: addiu       $s1, $zero, -0x1
    ctx->r17 = ADD32(0, -0X1);
    // 0x8006E3C4: beql        $a0, $s1, L_8006E3D8
    if (ctx->r4 == ctx->r17) {
        // 0x8006E3C8: addiu       $a0, $zero, 0x1
        ctx->r4 = ADD32(0, 0X1);
            goto L_8006E3D8;
    }
    goto skip_0;
    // 0x8006E3C8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    skip_0:
    // 0x8006E3CC: jal         0x800070BC
    // 0x8006E3D0: nop

    func_800070BC(rdram, ctx);
        goto after_0;
    // 0x8006E3D0: nop

    after_0:
    // 0x8006E3D4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_8006E3D8:
    // 0x8006E3D8: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x8006E3DC: addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    // 0x8006E3E0: addiu       $a3, $sp, 0x18
    ctx->r7 = ADD32(ctx->r29, 0X18);
    // 0x8006E3E4: addiu       $v0, $zero, 0x3A
    ctx->r2 = ADD32(0, 0X3A);
    // 0x8006E3E8: sw          $s1, 0xA60($s2)
    MEM_W(0XA60, ctx->r18) = ctx->r17;
    // 0x8006E3EC: sb          $v0, 0xA2($s0)
    MEM_B(0XA2, ctx->r16) = ctx->r2;
    // 0x8006E3F0: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8006E3F4: addiu       $s1, $v0, 0xB40
    ctx->r17 = ADD32(ctx->r2, 0XB40);
    // 0x8006E3F8: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x8006E3FC: lbu         $v0, 0x23($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X23);
    // 0x8006E400: lw          $v1, 0x28($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X28);
    // 0x8006E404: addiu       $s2, $zero, 0xB0
    ctx->r18 = ADD32(0, 0XB0);
    // 0x8006E408: sw          $s2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r18;
    // 0x8006E40C: sb          $v0, 0xA9($s0)
    MEM_B(0XA9, ctx->r16) = ctx->r2;
    // 0x8006E410: jal         0x80006798
    // 0x8006E414: sw          $v1, 0xAC($s0)
    MEM_W(0XAC, ctx->r16) = ctx->r3;
    func_80006798(rdram, ctx);
        goto after_1;
    // 0x8006E414: sw          $v1, 0xAC($s0)
    MEM_W(0XAC, ctx->r16) = ctx->r3;
    after_1:
    // 0x8006E418: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x8006E41C: beql        $v0, $zero, L_8006E424
    if (ctx->r2 == 0) {
        // 0x8006E420: sb          $s3, 0x2C($s1)
        MEM_B(0X2C, ctx->r17) = ctx->r19;
            goto L_8006E424;
    }
    goto skip_1;
    // 0x8006E420: sb          $s3, 0x2C($s1)
    MEM_B(0X2C, ctx->r17) = ctx->r19;
    skip_1:
L_8006E424:
    // 0x8006E424: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8006E428: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x8006E42C: addu        $a2, $a0, $zero
    ctx->r6 = ADD32(ctx->r4, 0);
    // 0x8006E430: addiu       $a3, $sp, 0x18
    ctx->r7 = ADD32(ctx->r29, 0X18);
    // 0x8006E434: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x8006E438: jal         0x80006798
    // 0x8006E43C: sw          $s2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r18;
    func_80006798(rdram, ctx);
        goto after_2;
    // 0x8006E43C: sw          $s2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r18;
    after_2:
    // 0x8006E440: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x8006E444: beql        $v0, $zero, L_8006E44C
    if (ctx->r2 == 0) {
        // 0x8006E448: sb          $s3, 0x2C($s1)
        MEM_B(0X2C, ctx->r17) = ctx->r19;
            goto L_8006E44C;
    }
    goto skip_2;
    // 0x8006E448: sb          $s3, 0x2C($s1)
    MEM_B(0X2C, ctx->r17) = ctx->r19;
    skip_2:
L_8006E44C:
    // 0x8006E44C: lw          $ra, 0x38($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X38);
    // 0x8006E450: lw          $s3, 0x34($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X34);
    // 0x8006E454: lw          $s2, 0x30($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X30);
    // 0x8006E458: lw          $s1, 0x2C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X2C);
    // 0x8006E45C: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x8006E460: jr          $ra
    // 0x8006E464: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x8006E464: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void func_8006E468(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006E468: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8006E46C: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8006E470: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x8006E474: addiu       $s0, $v0, 0xB40
    ctx->r16 = ADD32(ctx->r2, 0XB40);
    // 0x8006E478: addiu       $v0, $zero, -0x3
    ctx->r2 = ADD32(0, -0X3);
    // 0x8006E47C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8006E480: sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // 0x8006E484: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x8006E488: lw          $v1, 0x10($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X10);
    // 0x8006E48C: lbu         $a0, 0x20($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X20);
    // 0x8006E490: and         $v1, $v1, $v0
    ctx->r3 = ctx->r3 & ctx->r2;
    // 0x8006E494: addiu       $v0, $zero, -0x5
    ctx->r2 = ADD32(0, -0X5);
    // 0x8006E498: and         $v1, $v1, $v0
    ctx->r3 = ctx->r3 & ctx->r2;
    // 0x8006E49C: addiu       $v0, $zero, -0x9
    ctx->r2 = ADD32(0, -0X9);
    // 0x8006E4A0: and         $v0, $v1, $v0
    ctx->r2 = ctx->r3 & ctx->r2;
    // 0x8006E4A4: andi        $a1, $a0, 0xFF
    ctx->r5 = ctx->r4 & 0XFF;
    // 0x8006E4A8: lbu         $a0, 0x21($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X21);
    // 0x8006E4AC: lbu         $v1, 0x22($s0)
    ctx->r3 = MEM_BU(ctx->r16, 0X22);
    // 0x8006E4B0: bne         $a1, $zero, L_8006E4C0
    if (ctx->r5 != 0) {
        // 0x8006E4B4: sw          $v0, 0x10($s0)
        MEM_W(0X10, ctx->r16) = ctx->r2;
            goto L_8006E4C0;
    }
    // 0x8006E4B4: sw          $v0, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->r2;
    // 0x8006E4B8: ori         $v0, $v0, 0x2
    ctx->r2 = ctx->r2 | 0X2;
    // 0x8006E4BC: sw          $v0, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->r2;
L_8006E4C0:
    // 0x8006E4C0: andi        $s1, $a0, 0xFF
    ctx->r17 = ctx->r4 & 0XFF;
    // 0x8006E4C4: bne         $s1, $zero, L_8006E4D8
    if (ctx->r17 != 0) {
        // 0x8006E4C8: andi        $s2, $v1, 0xFF
        ctx->r18 = ctx->r3 & 0XFF;
            goto L_8006E4D8;
    }
    // 0x8006E4C8: andi        $s2, $v1, 0xFF
    ctx->r18 = ctx->r3 & 0XFF;
    // 0x8006E4CC: lw          $v0, 0x10($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X10);
    // 0x8006E4D0: ori         $v0, $v0, 0x4
    ctx->r2 = ctx->r2 | 0X4;
    // 0x8006E4D4: sw          $v0, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->r2;
L_8006E4D8:
    // 0x8006E4D8: bne         $s2, $zero, L_8006E4EC
    if (ctx->r18 != 0) {
        // 0x8006E4DC: addu        $a0, $a1, $zero
        ctx->r4 = ADD32(ctx->r5, 0);
            goto L_8006E4EC;
    }
    // 0x8006E4DC: addu        $a0, $a1, $zero
    ctx->r4 = ADD32(ctx->r5, 0);
    // 0x8006E4E0: lw          $v0, 0x10($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X10);
    // 0x8006E4E4: ori         $v0, $v0, 0x8
    ctx->r2 = ctx->r2 | 0X8;
    // 0x8006E4E8: sw          $v0, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->r2;
L_8006E4EC:
    // 0x8006E4EC: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x8006E4F0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8006E4F4: jal         0x8008E120
    // 0x8006E4F8: addu        $a3, $a1, $zero
    ctx->r7 = ADD32(ctx->r5, 0);
    func_8008E120(rdram, ctx);
        goto after_0;
    // 0x8006E4F8: addu        $a3, $a1, $zero
    ctx->r7 = ADD32(ctx->r5, 0);
    after_0:
    // 0x8006E4FC: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x8006E500: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x8006E504: addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    // 0x8006E508: jal         0x8008E120
    // 0x8006E50C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    func_8008E120(rdram, ctx);
        goto after_1;
    // 0x8006E50C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_1:
    // 0x8006E510: jal         0x80067AFC
    // 0x8006E514: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    func_80067AFC(rdram, ctx);
        goto after_2;
    // 0x8006E514: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    after_2:
    // 0x8006E518: lbu         $a0, 0x13($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X13);
    // 0x8006E51C: jal         0x8008DD50
    // 0x8006E520: andi        $a0, $a0, 0x80
    ctx->r4 = ctx->r4 & 0X80;
    func_8008DD50(rdram, ctx);
        goto after_3;
    // 0x8006E520: andi        $a0, $a0, 0x80
    ctx->r4 = ctx->r4 & 0X80;
    after_3:
    // 0x8006E524: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8006E528: lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X18);
    // 0x8006E52C: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x8006E530: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x8006E534: jr          $ra
    // 0x8006E538: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x8006E538: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_8006E53C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006E53C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006E540: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x8006E544: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x8006E548: addiu       $s0, $s0, 0xB40
    ctx->r16 = ADD32(ctx->r16, 0XB40);
    // 0x8006E54C: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x8006E550: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x8006E554: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006E558: jal         0x800078E0
    // 0x8006E55C: addiu       $a2, $zero, 0x30
    ctx->r6 = ADD32(0, 0X30);
    rs_memset(rdram, ctx);
        goto after_0;
    // 0x8006E55C: addiu       $a2, $zero, 0x30
    ctx->r6 = ADD32(0, 0X30);
    after_0:
    // 0x8006E560: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x8006E564: addiu       $a0, $a0, 0xB10
    ctx->r4 = ADD32(ctx->r4, 0XB10);
    // 0x8006E568: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x8006E56C: jal         0x800078E0
    // 0x8006E570: addiu       $a2, $zero, 0x28
    ctx->r6 = ADD32(0, 0X28);
    rs_memset(rdram, ctx);
        goto after_1;
    // 0x8006E570: addiu       $a2, $zero, 0x28
    ctx->r6 = ADD32(0, 0X28);
    after_1:
    // 0x8006E574: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x8006E578: addiu       $a0, $a0, 0xB78
    ctx->r4 = ADD32(ctx->r4, 0XB78);
    // 0x8006E57C: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x8006E580: jal         0x800078E0
    // 0x8006E584: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    rs_memset(rdram, ctx);
        goto after_2;
    // 0x8006E584: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    after_2:
    // 0x8006E588: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
    // 0x8006E58C: addiu       $a0, $zero, 0x19B
    ctx->r4 = ADD32(0, 0X19B);
    // 0x8006E590: addiu       $v0, $zero, 0x10
    ctx->r2 = ADD32(0, 0X10);
    // 0x8006E594: sw          $v0, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->r2;
    // 0x8006E598: sb          $zero, 0x2C($s0)
    MEM_B(0X2C, ctx->r16) = 0;
    // 0x8006E59C: andi        $v0, $v1, 0xFF
    ctx->r2 = ctx->r3 & 0XFF;
    // 0x8006E5A0: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
L_8006E5A4:
    // 0x8006E5A4: addu        $v0, $v0, $s0
    ctx->r2 = ADD32(ctx->r2, ctx->r16);
    // 0x8006E5A8: sw          $a0, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r4;
    // 0x8006E5AC: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8006E5B0: andi        $v0, $v1, 0xFF
    ctx->r2 = ctx->r3 & 0XFF;
    // 0x8006E5B4: beq         $v0, $zero, L_8006E5A4
    if (ctx->r2 == 0) {
        // 0x8006E5B8: sll         $v0, $v0, 2
        ctx->r2 = S32(ctx->r2 << 2);
            goto L_8006E5A4;
    }
    // 0x8006E5B8: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8006E5BC: jal         0x80002664
    // 0x8006E5C0: nop

    func_80002664(rdram, ctx);
        goto after_3;
    // 0x8006E5C0: nop

    after_3:
    // 0x8006E5C4: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x8006E5C8: addiu       $a1, $v1, 0xB40
    ctx->r5 = ADD32(ctx->r3, 0XB40);
    // 0x8006E5CC: lui         $v1, 0x40
    ctx->r3 = S32(0X40 << 16);
    // 0x8006E5D0: sltu        $v1, $v1, $v0
    ctx->r3 = ctx->r3 < ctx->r2 ? 1 : 0;
    // 0x8006E5D4: lw          $a0, 0x10($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X10);
    // 0x8006E5D8: addiu       $v0, $zero, -0x2
    ctx->r2 = ADD32(0, -0X2);
    // 0x8006E5DC: sb          $v1, 0x23($a1)
    MEM_B(0X23, ctx->r5) = ctx->r3;
    // 0x8006E5E0: and         $v0, $a0, $v0
    ctx->r2 = ctx->r4 & ctx->r2;
    // 0x8006E5E4: beq         $v1, $zero, L_8006E5F4
    if (ctx->r3 == 0) {
        // 0x8006E5E8: sw          $v0, 0x10($a1)
        MEM_W(0X10, ctx->r5) = ctx->r2;
            goto L_8006E5F4;
    }
    // 0x8006E5E8: sw          $v0, 0x10($a1)
    MEM_W(0X10, ctx->r5) = ctx->r2;
    // 0x8006E5EC: ori         $v0, $v0, 0x1
    ctx->r2 = ctx->r2 | 0X1;
    // 0x8006E5F0: sw          $v0, 0x10($a1)
    MEM_W(0X10, ctx->r5) = ctx->r2;
L_8006E5F4:
    // 0x8006E5F4: addiu       $v0, $zero, 0x7F
    ctx->r2 = ADD32(0, 0X7F);
    // 0x8006E5F8: sb          $v0, 0x20($a1)
    MEM_B(0X20, ctx->r5) = ctx->r2;
    // 0x8006E5FC: sb          $v0, 0x21($a1)
    MEM_B(0X21, ctx->r5) = ctx->r2;
    // 0x8006E600: sb          $v0, 0x22($a1)
    MEM_B(0X22, ctx->r5) = ctx->r2;
    // 0x8006E604: lw          $v0, 0x10($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X10);
    // 0x8006E608: addiu       $v1, $zero, -0x81
    ctx->r3 = ADD32(0, -0X81);
    // 0x8006E60C: and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // 0x8006E610: addiu       $v1, $zero, -0x5
    ctx->r3 = ADD32(0, -0X5);
    // 0x8006E614: and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // 0x8006E618: addiu       $v1, $zero, -0x9
    ctx->r3 = ADD32(0, -0X9);
    // 0x8006E61C: and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // 0x8006E620: ori         $v0, $v0, 0x10
    ctx->r2 = ctx->r2 | 0X10;
    // 0x8006E624: sw          $v0, 0x10($a1)
    MEM_W(0X10, ctx->r5) = ctx->r2;
    // 0x8006E628: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006E62C: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x8006E630: jr          $ra
    // 0x8006E634: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8006E634: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void generateUnlockString(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006E638: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8006E63C: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    // 0x8006E640: lui         $a2, 0x7F
    ctx->r6 = S32(0X7F << 16);
    // 0x8006E644: ori         $a2, $a2, 0xFE00
    ctx->r6 = ctx->r6 | 0XFE00;
    // 0x8006E648: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8006E64C: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x8006E650: lw          $a1, 0xB4C($v0)
    ctx->r5 = MEM_W(ctx->r2, 0XB4C);
    // 0x8006E654: lw          $v0, 0xB18($v1)
    ctx->r2 = MEM_W(ctx->r3, 0XB18);
    // 0x8006E658: andi        $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 & 0XFF;
    // 0x8006E65C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8006E660: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8006E664: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8006E668: and         $s1, $a1, $a2
    ctx->r17 = ctx->r5 & ctx->r6;
    // 0x8006E66C: nor         $v0, $zero, $v0
    ctx->r2 = ~(0 | ctx->r2);
    // 0x8006E670: and         $s1, $s1, $v0
    ctx->r17 = ctx->r17 & ctx->r2;
    // 0x8006E674: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // 0x8006E678: beq         $a0, $v0, L_8006E68C
    if (ctx->r4 == ctx->r2) {
        // 0x8006E67C: sw          $s0, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r16;
            goto L_8006E68C;
    }
    // 0x8006E67C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8006E680: addiu       $v0, $zero, 0x9
    ctx->r2 = ADD32(0, 0X9);
    // 0x8006E684: bne         $a0, $v0, L_8006E694
    if (ctx->r4 != ctx->r2) {
        // 0x8006E688: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_8006E694;
    }
    // 0x8006E688: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8006E68C:
    // 0x8006E68C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x8006E690: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8006E694:
    // 0x8006E694: bne         $a3, $v0, L_8006E6A0
    if (ctx->r7 != ctx->r2) {
        // 0x8006E698: addiu       $a0, $zero, 0xD2
        ctx->r4 = ADD32(0, 0XD2);
            goto L_8006E6A0;
    }
    // 0x8006E698: addiu       $a0, $zero, 0xD2
    ctx->r4 = ADD32(0, 0XD2);
    // 0x8006E69C: addiu       $a0, $zero, 0xD3
    ctx->r4 = ADD32(0, 0XD3);
L_8006E6A0:
    // 0x8006E6A0: jal         0x8005589C
    // 0x8006E6A4: nop

    getGameOrFrontText(rdram, ctx);
        goto after_0;
    // 0x8006E6A4: nop

    after_0:
    // 0x8006E6A8: addu        $s2, $v0, $zero
    ctx->r18 = ADD32(ctx->r2, 0);
    // 0x8006E6AC: andi        $v0, $s1, 0x200
    ctx->r2 = ctx->r17 & 0X200;
    // 0x8006E6B0: beq         $v0, $zero, L_8006E6F0
    if (ctx->r2 == 0) {
        // 0x8006E6B4: andi        $v0, $s1, 0x400
        ctx->r2 = ctx->r17 & 0X400;
            goto L_8006E6F0;
    }
    // 0x8006E6B4: andi        $v0, $s1, 0x400
    ctx->r2 = ctx->r17 & 0X400;
    // 0x8006E6B8: jal         0x8005589C
    // 0x8006E6BC: addiu       $a0, $zero, 0x4B
    ctx->r4 = ADD32(0, 0X4B);
    getGameOrFrontText(rdram, ctx);
        goto after_1;
    // 0x8006E6BC: addiu       $a0, $zero, 0x4B
    ctx->r4 = ADD32(0, 0X4B);
    after_1:
    // 0x8006E6C0: addiu       $a0, $zero, 0x4D
    ctx->r4 = ADD32(0, 0X4D);
    // 0x8006E6C4: jal         0x8005589C
    // 0x8006E6C8: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    getGameOrFrontText(rdram, ctx);
        goto after_2;
    // 0x8006E6C8: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    after_2:
    // 0x8006E6CC: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // 0x8006E6D0: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8006E6D4: addiu       $a0, $a0, -0x5A90
    ctx->r4 = ADD32(ctx->r4, -0X5A90);
    // 0x8006E6D8: lui         $a1, 0x8004
    ctx->r5 = S32(0X8004 << 16);
    // 0x8006E6DC: addiu       $a1, $a1, -0x34C8
    ctx->r5 = ADD32(ctx->r5, -0X34C8);
    // 0x8006E6E0: addu        $a2, $s2, $zero
    ctx->r6 = ADD32(ctx->r18, 0);
    // 0x8006E6E4: jal         0x80033CC4
    // 0x8006E6E8: addu        $a3, $s0, $zero
    ctx->r7 = ADD32(ctx->r16, 0);
    sprintf_recomp(rdram, ctx);
        goto after_3;
    // 0x8006E6E8: addu        $a3, $s0, $zero
    ctx->r7 = ADD32(ctx->r16, 0);
    after_3:
    // 0x8006E6EC: andi        $v0, $s1, 0x400
    ctx->r2 = ctx->r17 & 0X400;
L_8006E6F0:
    // 0x8006E6F0: beq         $v0, $zero, L_8006E730
    if (ctx->r2 == 0) {
        // 0x8006E6F4: andi        $v0, $s1, 0x800
        ctx->r2 = ctx->r17 & 0X800;
            goto L_8006E730;
    }
    // 0x8006E6F4: andi        $v0, $s1, 0x800
    ctx->r2 = ctx->r17 & 0X800;
    // 0x8006E6F8: jal         0x8005589C
    // 0x8006E6FC: addiu       $a0, $zero, 0x4B
    ctx->r4 = ADD32(0, 0X4B);
    getGameOrFrontText(rdram, ctx);
        goto after_4;
    // 0x8006E6FC: addiu       $a0, $zero, 0x4B
    ctx->r4 = ADD32(0, 0X4B);
    after_4:
    // 0x8006E700: addiu       $a0, $zero, 0x50
    ctx->r4 = ADD32(0, 0X50);
    // 0x8006E704: jal         0x8005589C
    // 0x8006E708: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    getGameOrFrontText(rdram, ctx);
        goto after_5;
    // 0x8006E708: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    after_5:
    // 0x8006E70C: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // 0x8006E710: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8006E714: addiu       $a0, $a0, -0x5A90
    ctx->r4 = ADD32(ctx->r4, -0X5A90);
    // 0x8006E718: lui         $a1, 0x8004
    ctx->r5 = S32(0X8004 << 16);
    // 0x8006E71C: addiu       $a1, $a1, -0x34C8
    ctx->r5 = ADD32(ctx->r5, -0X34C8);
    // 0x8006E720: addu        $a2, $s2, $zero
    ctx->r6 = ADD32(ctx->r18, 0);
    // 0x8006E724: jal         0x80033CC4
    // 0x8006E728: addu        $a3, $s0, $zero
    ctx->r7 = ADD32(ctx->r16, 0);
    sprintf_recomp(rdram, ctx);
        goto after_6;
    // 0x8006E728: addu        $a3, $s0, $zero
    ctx->r7 = ADD32(ctx->r16, 0);
    after_6:
    // 0x8006E72C: andi        $v0, $s1, 0x800
    ctx->r2 = ctx->r17 & 0X800;
L_8006E730:
    // 0x8006E730: beq         $v0, $zero, L_8006E760
    if (ctx->r2 == 0) {
        // 0x8006E734: andi        $v0, $s1, 0x1000
        ctx->r2 = ctx->r17 & 0X1000;
            goto L_8006E760;
    }
    // 0x8006E734: andi        $v0, $s1, 0x1000
    ctx->r2 = ctx->r17 & 0X1000;
    // 0x8006E738: jal         0x8005589C
    // 0x8006E73C: addiu       $a0, $zero, 0x51
    ctx->r4 = ADD32(0, 0X51);
    getGameOrFrontText(rdram, ctx);
        goto after_7;
    // 0x8006E73C: addiu       $a0, $zero, 0x51
    ctx->r4 = ADD32(0, 0X51);
    after_7:
    // 0x8006E740: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8006E744: addiu       $a0, $a0, -0x5A90
    ctx->r4 = ADD32(ctx->r4, -0X5A90);
    // 0x8006E748: lui         $a1, 0x8004
    ctx->r5 = S32(0X8004 << 16);
    // 0x8006E74C: addiu       $a1, $a1, -0x34C0
    ctx->r5 = ADD32(ctx->r5, -0X34C0);
    // 0x8006E750: addu        $a2, $s2, $zero
    ctx->r6 = ADD32(ctx->r18, 0);
    // 0x8006E754: jal         0x80033CC4
    // 0x8006E758: addu        $a3, $v0, $zero
    ctx->r7 = ADD32(ctx->r2, 0);
    sprintf_recomp(rdram, ctx);
        goto after_8;
    // 0x8006E758: addu        $a3, $v0, $zero
    ctx->r7 = ADD32(ctx->r2, 0);
    after_8:
    // 0x8006E75C: andi        $v0, $s1, 0x1000
    ctx->r2 = ctx->r17 & 0X1000;
L_8006E760:
    // 0x8006E760: beq         $v0, $zero, L_8006E7A0
    if (ctx->r2 == 0) {
        // 0x8006E764: andi        $v0, $s1, 0x2000
        ctx->r2 = ctx->r17 & 0X2000;
            goto L_8006E7A0;
    }
    // 0x8006E764: andi        $v0, $s1, 0x2000
    ctx->r2 = ctx->r17 & 0X2000;
    // 0x8006E768: jal         0x8005589C
    // 0x8006E76C: addiu       $a0, $zero, 0x4B
    ctx->r4 = ADD32(0, 0X4B);
    getGameOrFrontText(rdram, ctx);
        goto after_9;
    // 0x8006E76C: addiu       $a0, $zero, 0x4B
    ctx->r4 = ADD32(0, 0X4B);
    after_9:
    // 0x8006E770: addiu       $a0, $zero, 0x53
    ctx->r4 = ADD32(0, 0X53);
    // 0x8006E774: jal         0x8005589C
    // 0x8006E778: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    getGameOrFrontText(rdram, ctx);
        goto after_10;
    // 0x8006E778: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    after_10:
    // 0x8006E77C: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // 0x8006E780: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8006E784: addiu       $a0, $a0, -0x5A90
    ctx->r4 = ADD32(ctx->r4, -0X5A90);
    // 0x8006E788: lui         $a1, 0x8004
    ctx->r5 = S32(0X8004 << 16);
    // 0x8006E78C: addiu       $a1, $a1, -0x34C8
    ctx->r5 = ADD32(ctx->r5, -0X34C8);
    // 0x8006E790: addu        $a2, $s2, $zero
    ctx->r6 = ADD32(ctx->r18, 0);
    // 0x8006E794: jal         0x80033CC4
    // 0x8006E798: addu        $a3, $s0, $zero
    ctx->r7 = ADD32(ctx->r16, 0);
    sprintf_recomp(rdram, ctx);
        goto after_11;
    // 0x8006E798: addu        $a3, $s0, $zero
    ctx->r7 = ADD32(ctx->r16, 0);
    after_11:
    // 0x8006E79C: andi        $v0, $s1, 0x2000
    ctx->r2 = ctx->r17 & 0X2000;
L_8006E7A0:
    // 0x8006E7A0: beq         $v0, $zero, L_8006E7D0
    if (ctx->r2 == 0) {
        // 0x8006E7A4: andi        $v0, $s1, 0x4000
        ctx->r2 = ctx->r17 & 0X4000;
            goto L_8006E7D0;
    }
    // 0x8006E7A4: andi        $v0, $s1, 0x4000
    ctx->r2 = ctx->r17 & 0X4000;
    // 0x8006E7A8: jal         0x8005589C
    // 0x8006E7AC: addiu       $a0, $zero, 0x55
    ctx->r4 = ADD32(0, 0X55);
    getGameOrFrontText(rdram, ctx);
        goto after_12;
    // 0x8006E7AC: addiu       $a0, $zero, 0x55
    ctx->r4 = ADD32(0, 0X55);
    after_12:
    // 0x8006E7B0: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8006E7B4: addiu       $a0, $a0, -0x5A90
    ctx->r4 = ADD32(ctx->r4, -0X5A90);
    // 0x8006E7B8: lui         $a1, 0x8004
    ctx->r5 = S32(0X8004 << 16);
    // 0x8006E7BC: addiu       $a1, $a1, -0x34C0
    ctx->r5 = ADD32(ctx->r5, -0X34C0);
    // 0x8006E7C0: addu        $a2, $s2, $zero
    ctx->r6 = ADD32(ctx->r18, 0);
    // 0x8006E7C4: jal         0x80033CC4
    // 0x8006E7C8: addu        $a3, $v0, $zero
    ctx->r7 = ADD32(ctx->r2, 0);
    sprintf_recomp(rdram, ctx);
        goto after_13;
    // 0x8006E7C8: addu        $a3, $v0, $zero
    ctx->r7 = ADD32(ctx->r2, 0);
    after_13:
    // 0x8006E7CC: andi        $v0, $s1, 0x4000
    ctx->r2 = ctx->r17 & 0X4000;
L_8006E7D0:
    // 0x8006E7D0: beq         $v0, $zero, L_8006E800
    if (ctx->r2 == 0) {
        // 0x8006E7D4: andi        $v0, $s1, 0x8000
        ctx->r2 = ctx->r17 & 0X8000;
            goto L_8006E800;
    }
    // 0x8006E7D4: andi        $v0, $s1, 0x8000
    ctx->r2 = ctx->r17 & 0X8000;
    // 0x8006E7D8: jal         0x8005589C
    // 0x8006E7DC: addiu       $a0, $zero, 0x56
    ctx->r4 = ADD32(0, 0X56);
    getGameOrFrontText(rdram, ctx);
        goto after_14;
    // 0x8006E7DC: addiu       $a0, $zero, 0x56
    ctx->r4 = ADD32(0, 0X56);
    after_14:
    // 0x8006E7E0: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8006E7E4: addiu       $a0, $a0, -0x5A90
    ctx->r4 = ADD32(ctx->r4, -0X5A90);
    // 0x8006E7E8: lui         $a1, 0x8004
    ctx->r5 = S32(0X8004 << 16);
    // 0x8006E7EC: addiu       $a1, $a1, -0x34C0
    ctx->r5 = ADD32(ctx->r5, -0X34C0);
    // 0x8006E7F0: addu        $a2, $s2, $zero
    ctx->r6 = ADD32(ctx->r18, 0);
    // 0x8006E7F4: jal         0x80033CC4
    // 0x8006E7F8: addu        $a3, $v0, $zero
    ctx->r7 = ADD32(ctx->r2, 0);
    sprintf_recomp(rdram, ctx);
        goto after_15;
    // 0x8006E7F8: addu        $a3, $v0, $zero
    ctx->r7 = ADD32(ctx->r2, 0);
    after_15:
    // 0x8006E7FC: andi        $v0, $s1, 0x8000
    ctx->r2 = ctx->r17 & 0X8000;
L_8006E800:
    // 0x8006E800: beq         $v0, $zero, L_8006E840
    if (ctx->r2 == 0) {
        // 0x8006E804: lui         $v0, 0x1
        ctx->r2 = S32(0X1 << 16);
            goto L_8006E840;
    }
    // 0x8006E804: lui         $v0, 0x1
    ctx->r2 = S32(0X1 << 16);
    // 0x8006E808: jal         0x8005589C
    // 0x8006E80C: addiu       $a0, $zero, 0x4B
    ctx->r4 = ADD32(0, 0X4B);
    getGameOrFrontText(rdram, ctx);
        goto after_16;
    // 0x8006E80C: addiu       $a0, $zero, 0x4B
    ctx->r4 = ADD32(0, 0X4B);
    after_16:
    // 0x8006E810: addiu       $a0, $zero, 0x52
    ctx->r4 = ADD32(0, 0X52);
    // 0x8006E814: jal         0x8005589C
    // 0x8006E818: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    getGameOrFrontText(rdram, ctx);
        goto after_17;
    // 0x8006E818: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    after_17:
    // 0x8006E81C: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // 0x8006E820: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8006E824: addiu       $a0, $a0, -0x5A90
    ctx->r4 = ADD32(ctx->r4, -0X5A90);
    // 0x8006E828: lui         $a1, 0x8004
    ctx->r5 = S32(0X8004 << 16);
    // 0x8006E82C: addiu       $a1, $a1, -0x34C8
    ctx->r5 = ADD32(ctx->r5, -0X34C8);
    // 0x8006E830: addu        $a2, $s2, $zero
    ctx->r6 = ADD32(ctx->r18, 0);
    // 0x8006E834: jal         0x80033CC4
    // 0x8006E838: addu        $a3, $s0, $zero
    ctx->r7 = ADD32(ctx->r16, 0);
    sprintf_recomp(rdram, ctx);
        goto after_18;
    // 0x8006E838: addu        $a3, $s0, $zero
    ctx->r7 = ADD32(ctx->r16, 0);
    after_18:
    // 0x8006E83C: lui         $v0, 0x1
    ctx->r2 = S32(0X1 << 16);
L_8006E840:
    // 0x8006E840: and         $v0, $s1, $v0
    ctx->r2 = ctx->r17 & ctx->r2;
    // 0x8006E844: beq         $v0, $zero, L_8006E880
    if (ctx->r2 == 0) {
        // 0x8006E848: nop
    
            goto L_8006E880;
    }
    // 0x8006E848: nop

    // 0x8006E84C: jal         0x8005589C
    // 0x8006E850: addiu       $a0, $zero, 0x4B
    ctx->r4 = ADD32(0, 0X4B);
    getGameOrFrontText(rdram, ctx);
        goto after_19;
    // 0x8006E850: addiu       $a0, $zero, 0x4B
    ctx->r4 = ADD32(0, 0X4B);
    after_19:
    // 0x8006E854: addiu       $a0, $zero, 0x4C
    ctx->r4 = ADD32(0, 0X4C);
    // 0x8006E858: jal         0x8005589C
    // 0x8006E85C: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    getGameOrFrontText(rdram, ctx);
        goto after_20;
    // 0x8006E85C: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    after_20:
    // 0x8006E860: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // 0x8006E864: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8006E868: addiu       $a0, $a0, -0x5A90
    ctx->r4 = ADD32(ctx->r4, -0X5A90);
    // 0x8006E86C: lui         $a1, 0x8004
    ctx->r5 = S32(0X8004 << 16);
    // 0x8006E870: addiu       $a1, $a1, -0x34C8
    ctx->r5 = ADD32(ctx->r5, -0X34C8);
    // 0x8006E874: addu        $a2, $s2, $zero
    ctx->r6 = ADD32(ctx->r18, 0);
    // 0x8006E878: jal         0x80033CC4
    // 0x8006E87C: addu        $a3, $s0, $zero
    ctx->r7 = ADD32(ctx->r16, 0);
    sprintf_recomp(rdram, ctx);
        goto after_21;
    // 0x8006E87C: addu        $a3, $s0, $zero
    ctx->r7 = ADD32(ctx->r16, 0);
    after_21:
L_8006E880:
    // 0x8006E880: beq         $s1, $zero, L_8006E890
    if (ctx->r17 == 0) {
        // 0x8006E884: lui         $v0, 0x8014
        ctx->r2 = S32(0X8014 << 16);
            goto L_8006E890;
    }
    // 0x8006E884: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x8006E888: j           L_8006E894
    // 0x8006E88C: addiu       $v0, $v0, -0x5A90
    ctx->r2 = ADD32(ctx->r2, -0X5A90);
        goto L_8006E894;
    // 0x8006E88C: addiu       $v0, $v0, -0x5A90
    ctx->r2 = ADD32(ctx->r2, -0X5A90);
L_8006E890:
    // 0x8006E890: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_8006E894:
    // 0x8006E894: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8006E898: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8006E89C: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8006E8A0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8006E8A4: jr          $ra
    // 0x8006E8A8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x8006E8A8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_8006E8AC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006E8AC: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x8006E8B0: lbu         $v0, -0x59F0($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X59F0);
    // 0x8006E8B4: jr          $ra
    // 0x8006E8B8: nop

    return;
    // 0x8006E8B8: nop

;}
RECOMP_FUNC void func_8006E8BC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006E8BC: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x8006E8C0: lbu         $v0, -0x59EF($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X59EF);
    // 0x8006E8C4: jr          $ra
    // 0x8006E8C8: nop

    return;
    // 0x8006E8C8: nop

;}
RECOMP_FUNC void func_8006E8CC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006E8CC: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8006E8D0: sw          $s5, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r21;
    // 0x8006E8D4: addu        $s5, $a0, $zero
    ctx->r21 = ADD32(ctx->r4, 0);
    // 0x8006E8D8: sw          $s6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r22;
    // 0x8006E8DC: addu        $s6, $a1, $zero
    ctx->r22 = ADD32(ctx->r5, 0);
    // 0x8006E8E0: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8006E8E4: sw          $s4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r20;
    // 0x8006E8E8: sw          $s3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r19;
    // 0x8006E8EC: sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // 0x8006E8F0: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x8006E8F4: jal         0x8006EA78
    // 0x8006E8F8: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    initializeNumLives(rdram, ctx);
        goto after_0;
    // 0x8006E8F8: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    after_0:
    // 0x8006E8FC: addu        $s1, $zero, $zero
    ctx->r17 = ADD32(0, 0);
    // 0x8006E900: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8006E904: addiu       $s4, $v0, 0xB10
    ctx->r20 = ADD32(ctx->r2, 0XB10);
    // 0x8006E908: lui         $s3, 0xFF80
    ctx->r19 = S32(0XFF80 << 16);
    // 0x8006E90C: ori         $s3, $s3, 0x1FF
    ctx->r19 = ctx->r19 | 0X1FF;
    // 0x8006E910: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8006E914: addiu       $v0, $v0, 0xB47
    ctx->r2 = ADD32(ctx->r2, 0XB47);
    // 0x8006E918: addiu       $s0, $v0, -0x7
    ctx->r16 = ADD32(ctx->r2, -0X7);
    // 0x8006E91C: addu        $s2, $v0, $zero
    ctx->r18 = ADD32(ctx->r2, 0);
L_8006E920:
    // 0x8006E920: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // 0x8006E924: addu        $a1, $s5, $zero
    ctx->r5 = ADD32(ctx->r21, 0);
    // 0x8006E928: addu        $v0, $s1, $s4
    ctx->r2 = ADD32(ctx->r17, ctx->r20);
    // 0x8006E92C: jal         0x8000761C
    // 0x8006E930: sb          $zero, 0x1($v0)
    MEM_B(0X1, ctx->r2) = 0;
    rs_strcpy(rdram, ctx);
        goto after_1;
    // 0x8006E930: sb          $zero, 0x1($v0)
    MEM_B(0X1, ctx->r2) = 0;
    after_1:
    // 0x8006E934: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
    // 0x8006E938: lw          $v0, 0xC($s0)
    ctx->r2 = MEM_W(ctx->r16, 0XC);
    // 0x8006E93C: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x8006E940: and         $v0, $v0, $s3
    ctx->r2 = ctx->r2 & ctx->r19;
    // 0x8006E944: sw          $v0, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r2;
    // 0x8006E948: beq         $s1, $zero, L_8006E920
    if (ctx->r17 == 0) {
        // 0x8006E94C: addiu       $s0, $s0, 0x4
        ctx->r16 = ADD32(ctx->r16, 0X4);
            goto L_8006E920;
    }
    // 0x8006E94C: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x8006E950: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8006E954: addiu       $s0, $v0, 0xB10
    ctx->r16 = ADD32(ctx->r2, 0XB10);
    // 0x8006E958: addiu       $a0, $s0, 0xC
    ctx->r4 = ADD32(ctx->r16, 0XC);
    // 0x8006E95C: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x8006E960: addiu       $a2, $zero, 0x13
    ctx->r6 = ADD32(0, 0X13);
    // 0x8006E964: jal         0x800078E0
    // 0x8006E968: sb          $zero, 0x1F($s0)
    MEM_B(0X1F, ctx->r16) = 0;
    rs_memset(rdram, ctx);
        goto after_2;
    // 0x8006E968: sb          $zero, 0x1F($s0)
    MEM_B(0X1F, ctx->r16) = 0;
    after_2:
    // 0x8006E96C: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8006E970: addiu       $a0, $v0, 0xB40
    ctx->r4 = ADD32(ctx->r2, 0XB40);
    // 0x8006E974: sb          $zero, 0xB40($v0)
    MEM_B(0XB40, ctx->r2) = 0;
    // 0x8006E978: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8006E97C: sb          $s6, 0x4($a0)
    MEM_B(0X4, ctx->r4) = ctx->r22;
    // 0x8006E980: sb          $v0, 0x21($s0)
    MEM_B(0X21, ctx->r16) = ctx->r2;
    // 0x8006E984: lw          $v0, 0x18($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X18);
    // 0x8006E988: lui         $v1, 0x100
    ctx->r3 = S32(0X100 << 16);
    // 0x8006E98C: and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // 0x8006E990: beq         $v0, $zero, L_8006E9A8
    if (ctx->r2 == 0) {
        // 0x8006E994: lui         $v1, 0x1
        ctx->r3 = S32(0X1 << 16);
            goto L_8006E9A8;
    }
    // 0x8006E994: lui         $v1, 0x1
    ctx->r3 = S32(0X1 << 16);
    // 0x8006E998: lw          $v0, 0xC($a0)
    ctx->r2 = MEM_W(ctx->r4, 0XC);
    // 0x8006E99C: ori         $v1, $v1, 0xFE00
    ctx->r3 = ctx->r3 | 0XFE00;
    // 0x8006E9A0: or          $v0, $v0, $v1
    ctx->r2 = ctx->r2 | ctx->r3;
    // 0x8006E9A4: sw          $v0, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r2;
L_8006E9A8:
    // 0x8006E9A8: jal         0x8006EC1C
    // 0x8006E9AC: nop

    func_8006EC1C(rdram, ctx);
        goto after_3;
    // 0x8006E9AC: nop

    after_3:
    // 0x8006E9B0: andi        $a0, $s6, 0xFF
    ctx->r4 = ctx->r22 & 0XFF;
    // 0x8006E9B4: jal         0x8006EAAC
    // 0x8006E9B8: sb          $v0, 0x24($s0)
    MEM_B(0X24, ctx->r16) = ctx->r2;
    func_8006EAAC(rdram, ctx);
        goto after_4;
    // 0x8006E9B8: sb          $v0, 0x24($s0)
    MEM_B(0X24, ctx->r16) = ctx->r2;
    after_4:
    // 0x8006E9BC: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x8006E9C0: lw          $s6, 0x28($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X28);
    // 0x8006E9C4: lw          $s5, 0x24($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X24);
    // 0x8006E9C8: lw          $s4, 0x20($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X20);
    // 0x8006E9CC: lw          $s3, 0x1C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X1C);
    // 0x8006E9D0: lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X18);
    // 0x8006E9D4: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x8006E9D8: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x8006E9DC: jr          $ra
    // 0x8006E9E0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x8006E9E0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_8006E9E4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006E9E4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8006E9E8: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x8006E9EC: addu        $s1, $zero, $zero
    ctx->r17 = ADD32(0, 0);
    // 0x8006E9F0: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8006E9F4: sw          $s3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r19;
    // 0x8006E9F8: addiu       $s3, $v0, 0xB10
    ctx->r19 = ADD32(ctx->r2, 0XB10);
    // 0x8006E9FC: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8006EA00: sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // 0x8006EA04: addiu       $s2, $v0, 0xB40
    ctx->r18 = ADD32(ctx->r2, 0XB40);
    // 0x8006EA08: sw          $ra, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r31;
    // 0x8006EA0C: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
L_8006EA10:
    // 0x8006EA10: lbu         $v0, 0x3($s2)
    ctx->r2 = MEM_BU(ctx->r18, 0X3);
    // 0x8006EA14: addu        $s0, $s1, $s3
    ctx->r16 = ADD32(ctx->r17, ctx->r19);
    // 0x8006EA18: sb          $v0, 0x2($s0)
    MEM_B(0X2, ctx->r16) = ctx->r2;
    // 0x8006EA1C: lbu         $a0, 0x1($s2)
    ctx->r4 = MEM_BU(ctx->r18, 0X1);
    // 0x8006EA20: lbu         $a1, 0x3($s2)
    ctx->r5 = MEM_BU(ctx->r18, 0X3);
    // 0x8006EA24: jal         0x8006F43C
    // 0x8006EA28: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    getSecondaryWeaponCount(rdram, ctx);
        goto after_0;
    // 0x8006EA28: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    after_0:
    // 0x8006EA2C: beq         $s1, $zero, L_8006EA10
    if (ctx->r17 == 0) {
        // 0x8006EA30: sb          $v0, 0x3($s0)
        MEM_B(0X3, ctx->r16) = ctx->r2;
            goto L_8006EA10;
    }
    // 0x8006EA30: sb          $v0, 0x3($s0)
    MEM_B(0X3, ctx->r16) = ctx->r2;
    // 0x8006EA34: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x8006EA38: addiu       $a0, $a0, 0xB78
    ctx->r4 = ADD32(ctx->r4, 0XB78);
    // 0x8006EA3C: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x8006EA40: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8006EA44: addiu       $v0, $v0, 0xB10
    ctx->r2 = ADD32(ctx->r2, 0XB10);
    // 0x8006EA48: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    // 0x8006EA4C: sb          $zero, 0x5($v0)
    MEM_B(0X5, ctx->r2) = 0;
    // 0x8006EA50: sb          $zero, 0x6($v0)
    MEM_B(0X6, ctx->r2) = 0;
    // 0x8006EA54: jal         0x800078E0
    // 0x8006EA58: sb          $zero, 0x7($v0)
    MEM_B(0X7, ctx->r2) = 0;
    rs_memset(rdram, ctx);
        goto after_1;
    // 0x8006EA58: sb          $zero, 0x7($v0)
    MEM_B(0X7, ctx->r2) = 0;
    after_1:
    // 0x8006EA5C: lw          $ra, 0x20($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X20);
    // 0x8006EA60: lw          $s3, 0x1C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X1C);
    // 0x8006EA64: lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X18);
    // 0x8006EA68: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x8006EA6C: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x8006EA70: jr          $ra
    // 0x8006EA74: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x8006EA74: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void initializeNumLives(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006EA78: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
    // 0x8006EA7C: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8006EA80: addiu       $a1, $v0, 0xB10
    ctx->r5 = ADD32(ctx->r2, 0XB10);
    // 0x8006EA84: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x8006EA88: andi        $v0, $v1, 0xFF
    ctx->r2 = ctx->r3 & 0XFF;
    // 0x8006EA8C: addu        $v0, $v0, $a1
    ctx->r2 = ADD32(ctx->r2, ctx->r5);
L_8006EA90:
    // 0x8006EA90: sb          $a0, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r4;
    // 0x8006EA94: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8006EA98: andi        $v0, $v1, 0xFF
    ctx->r2 = ctx->r3 & 0XFF;
    // 0x8006EA9C: beq         $v0, $zero, L_8006EA90
    if (ctx->r2 == 0) {
        // 0x8006EAA0: addu        $v0, $v0, $a1
        ctx->r2 = ADD32(ctx->r2, ctx->r5);
            goto L_8006EA90;
    }
    // 0x8006EAA0: addu        $v0, $v0, $a1
    ctx->r2 = ADD32(ctx->r2, ctx->r5);
    // 0x8006EAA4: jr          $ra
    // 0x8006EAA8: nop

    return;
    // 0x8006EAA8: nop

;}
RECOMP_FUNC void func_8006EAAC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006EAAC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8006EAB0: sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // 0x8006EAB4: addu        $s2, $a0, $zero
    ctx->r18 = ADD32(ctx->r4, 0);
    // 0x8006EAB8: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x8006EABC: lui         $s0, 0x8014
    ctx->r16 = S32(0X8014 << 16);
    // 0x8006EAC0: addiu       $s0, $s0, -0x5AB0
    ctx->r16 = ADD32(ctx->r16, -0X5AB0);
    // 0x8006EAC4: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x8006EAC8: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x8006EACC: lui         $s1, 0x8013
    ctx->r17 = S32(0X8013 << 16);
    // 0x8006EAD0: addiu       $s1, $s1, 0xB47
    ctx->r17 = ADD32(ctx->r17, 0XB47);
    // 0x8006EAD4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8006EAD8: jal         0x8000761C
    // 0x8006EADC: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    rs_strcpy(rdram, ctx);
        goto after_0;
    // 0x8006EADC: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    after_0:
    // 0x8006EAE0: lui         $a3, 0x7F
    ctx->r7 = S32(0X7F << 16);
    // 0x8006EAE4: ori         $a3, $a3, 0xFE00
    ctx->r7 = ctx->r7 | 0XFE00;
    // 0x8006EAE8: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x8006EAEC: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x8006EAF0: addiu       $v1, $v1, 0xB10
    ctx->r3 = ADD32(ctx->r3, 0XB10);
    // 0x8006EAF4: lbu         $v0, 0x1($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X1);
    // 0x8006EAF8: lbu         $a2, 0x1F($v1)
    ctx->r6 = MEM_BU(ctx->r3, 0X1F);
    // 0x8006EAFC: addiu       $a1, $v1, 0xC
    ctx->r5 = ADD32(ctx->r3, 0XC);
    // 0x8006EB00: sb          $v0, 0x4($s0)
    MEM_B(0X4, ctx->r16) = ctx->r2;
    // 0x8006EB04: sb          $a2, 0x5($s0)
    MEM_B(0X5, ctx->r16) = ctx->r6;
    // 0x8006EB08: lw          $v0, 0x5($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X5);
    // 0x8006EB0C: lbu         $v1, 0x24($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X24);
    // 0x8006EB10: and         $v0, $v0, $a3
    ctx->r2 = ctx->r2 & ctx->r7;
    // 0x8006EB14: sw          $v0, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r2;
    // 0x8006EB18: jal         0x8006EB94
    // 0x8006EB1C: sb          $v1, 0x10($s0)
    MEM_B(0X10, ctx->r16) = ctx->r3;
    func_8006EB94(rdram, ctx);
        goto after_1;
    // 0x8006EB1C: sb          $v1, 0x10($s0)
    MEM_B(0X10, ctx->r16) = ctx->r3;
    after_1:
    // 0x8006EB20: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x8006EB24: jal         0x8006EE94
    // 0x8006EB28: andi        $a1, $s2, 0xFF
    ctx->r5 = ctx->r18 & 0XFF;
    func_8006EE94(rdram, ctx);
        goto after_2;
    // 0x8006EB28: andi        $a1, $s2, 0xFF
    ctx->r5 = ctx->r18 & 0XFF;
    after_2:
    // 0x8006EB2C: addu        $v0, $s0, $zero
    ctx->r2 = ADD32(ctx->r16, 0);
    // 0x8006EB30: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8006EB34: lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X18);
    // 0x8006EB38: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x8006EB3C: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x8006EB40: jr          $ra
    // 0x8006EB44: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x8006EB44: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_8006EB48(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006EB48: addu        $a3, $a0, $zero
    ctx->r7 = ADD32(ctx->r4, 0);
    // 0x8006EB4C: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // 0x8006EB50: andi        $v0, $a2, 0xFF
    ctx->r2 = ctx->r6 & 0XFF;
L_8006EB54:
    // 0x8006EB54: andi        $v1, $a2, 0x3
    ctx->r3 = ctx->r6 & 0X3;
    // 0x8006EB58: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x8006EB5C: addu        $a0, $a1, $v0
    ctx->r4 = ADD32(ctx->r5, ctx->r2);
    // 0x8006EB60: srl         $v0, $v0, 2
    ctx->r2 = S32(U32(ctx->r2) >> 2);
    // 0x8006EB64: addu        $v0, $a3, $v0
    ctx->r2 = ADD32(ctx->r7, ctx->r2);
    // 0x8006EB68: lbu         $v0, 0x6($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X6);
    // 0x8006EB6C: sll         $v1, $v1, 1
    ctx->r3 = S32(ctx->r3 << 1);
    // 0x8006EB70: srav        $v0, $v0, $v1
    ctx->r2 = S32(SIGNED(ctx->r2) >> (ctx->r3 & 31));
    // 0x8006EB74: andi        $v0, $v0, 0x3
    ctx->r2 = ctx->r2 & 0X3;
    // 0x8006EB78: sb          $v0, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r2;
    // 0x8006EB7C: andi        $v0, $a2, 0xFF
    ctx->r2 = ctx->r6 & 0XFF;
    // 0x8006EB80: sltiu       $v0, $v0, 0x13
    ctx->r2 = ctx->r2 < 0X13 ? 1 : 0;
    // 0x8006EB84: bne         $v0, $zero, L_8006EB54
    if (ctx->r2 != 0) {
        // 0x8006EB88: andi        $v0, $a2, 0xFF
        ctx->r2 = ctx->r6 & 0XFF;
            goto L_8006EB54;
    }
    // 0x8006EB88: andi        $v0, $a2, 0xFF
    ctx->r2 = ctx->r6 & 0XFF;
    // 0x8006EB8C: jr          $ra
    // 0x8006EB90: nop

    return;
    // 0x8006EB90: nop

;}
RECOMP_FUNC void func_8006EB94(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006EB94: addu        $a3, $a0, $zero
    ctx->r7 = ADD32(ctx->r4, 0);
    // 0x8006EB98: addu        $t0, $a1, $zero
    ctx->r8 = ADD32(ctx->r5, 0);
    // 0x8006EB9C: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // 0x8006EBA0: andi        $v0, $a2, 0xFF
    ctx->r2 = ctx->r6 & 0XFF;
L_8006EBA4:
    // 0x8006EBA4: addu        $v0, $a3, $v0
    ctx->r2 = ADD32(ctx->r7, ctx->r2);
    // 0x8006EBA8: sb          $zero, 0x6($v0)
    MEM_B(0X6, ctx->r2) = 0;
    // 0x8006EBAC: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x8006EBB0: andi        $v0, $a2, 0xFF
    ctx->r2 = ctx->r6 & 0XFF;
    // 0x8006EBB4: sltiu       $v0, $v0, 0x5
    ctx->r2 = ctx->r2 < 0X5 ? 1 : 0;
    // 0x8006EBB8: bne         $v0, $zero, L_8006EBA4
    if (ctx->r2 != 0) {
        // 0x8006EBBC: andi        $v0, $a2, 0xFF
        ctx->r2 = ctx->r6 & 0XFF;
            goto L_8006EBA4;
    }
    // 0x8006EBBC: andi        $v0, $a2, 0xFF
    ctx->r2 = ctx->r6 & 0XFF;
    // 0x8006EBC0: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // 0x8006EBC4: andi        $v0, $a2, 0xFF
    ctx->r2 = ctx->r6 & 0XFF;
L_8006EBC8:
    // 0x8006EBC8: andi        $a1, $a2, 0x3
    ctx->r5 = ctx->r6 & 0X3;
    // 0x8006EBCC: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x8006EBD0: srl         $a0, $v0, 2
    ctx->r4 = S32(U32(ctx->r2) >> 2);
    // 0x8006EBD4: addu        $v0, $t0, $v0
    ctx->r2 = ADD32(ctx->r8, ctx->r2);
    // 0x8006EBD8: addu        $a0, $a3, $a0
    ctx->r4 = ADD32(ctx->r7, ctx->r4);
    // 0x8006EBDC: sll         $a1, $a1, 1
    ctx->r5 = S32(ctx->r5 << 1);
    // 0x8006EBE0: lbu         $v1, 0x0($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X0);
    // 0x8006EBE4: lbu         $v0, 0x6($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X6);
    // 0x8006EBE8: andi        $v1, $v1, 0x3
    ctx->r3 = ctx->r3 & 0X3;
    // 0x8006EBEC: sllv        $v1, $v1, $a1
    ctx->r3 = S32(ctx->r3 << (ctx->r5 & 31));
    // 0x8006EBF0: or          $v0, $v0, $v1
    ctx->r2 = ctx->r2 | ctx->r3;
    // 0x8006EBF4: sb          $v0, 0x6($a0)
    MEM_B(0X6, ctx->r4) = ctx->r2;
    // 0x8006EBF8: andi        $v0, $a2, 0xFF
    ctx->r2 = ctx->r6 & 0XFF;
    // 0x8006EBFC: sltiu       $v0, $v0, 0x13
    ctx->r2 = ctx->r2 < 0X13 ? 1 : 0;
    // 0x8006EC00: bne         $v0, $zero, L_8006EBC8
    if (ctx->r2 != 0) {
        // 0x8006EC04: andi        $v0, $a2, 0xFF
        ctx->r2 = ctx->r6 & 0XFF;
            goto L_8006EBC8;
    }
    // 0x8006EC04: andi        $v0, $a2, 0xFF
    ctx->r2 = ctx->r6 & 0XFF;
    // 0x8006EC08: jr          $ra
    // 0x8006EC0C: nop

    return;
    // 0x8006EC0C: nop

;}
RECOMP_FUNC void func_8006EC10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006EC10: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x8006EC14: jr          $ra
    // 0x8006EC18: addiu       $v0, $v0, -0x59EE
    ctx->r2 = ADD32(ctx->r2, -0X59EE);
    return;
    // 0x8006EC18: addiu       $v0, $v0, -0x59EE
    ctx->r2 = ADD32(ctx->r2, -0X59EE);
;}
RECOMP_FUNC void func_8006EC1C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006EC1C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8006EC20: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x8006EC24: addiu       $a3, $v0, -0x5A40
    ctx->r7 = ADD32(ctx->r2, -0X5A40);
    // 0x8006EC28: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
L_8006EC2C:
    // 0x8006EC2C: addu        $v1, $a2, $zero
    ctx->r3 = ADD32(ctx->r6, 0);
    // 0x8006EC30: andi        $a1, $a0, 0xFF
    ctx->r5 = ctx->r4 & 0XFF;
    // 0x8006EC34: andi        $v0, $v1, 0xFF
    ctx->r2 = ctx->r3 & 0XFF;
L_8006EC38:
    // 0x8006EC38: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x8006EC3C: addu        $v0, $v0, $a3
    ctx->r2 = ADD32(ctx->r2, ctx->r7);
    // 0x8006EC40: lbu         $v0, 0x58($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X58);
    // 0x8006EC44: bnel        $v0, $a1, L_8006EC54
    if (ctx->r2 != ctx->r5) {
        // 0x8006EC48: addiu       $v1, $v1, 0x1
        ctx->r3 = ADD32(ctx->r3, 0X1);
            goto L_8006EC54;
    }
    goto skip_0;
    // 0x8006EC48: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    skip_0:
    // 0x8006EC4C: j           L_8006EC64
    // 0x8006EC50: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
        goto L_8006EC64;
    // 0x8006EC50: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
L_8006EC54:
    // 0x8006EC54: andi        $v0, $v1, 0xFF
    ctx->r2 = ctx->r3 & 0XFF;
    // 0x8006EC58: sltiu       $v0, $v0, 0xA
    ctx->r2 = ctx->r2 < 0XA ? 1 : 0;
    // 0x8006EC5C: bne         $v0, $zero, L_8006EC38
    if (ctx->r2 != 0) {
        // 0x8006EC60: andi        $v0, $v1, 0xFF
        ctx->r2 = ctx->r3 & 0XFF;
            goto L_8006EC38;
    }
    // 0x8006EC60: andi        $v0, $v1, 0xFF
    ctx->r2 = ctx->r3 & 0XFF;
L_8006EC64:
    // 0x8006EC64: andi        $v0, $a2, 0xFF
    ctx->r2 = ctx->r6 & 0XFF;
    // 0x8006EC68: beq         $v0, $zero, L_8006EC84
    if (ctx->r2 == 0) {
        // 0x8006EC6C: nop
    
            goto L_8006EC84;
    }
    // 0x8006EC6C: nop

    // 0x8006EC70: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x8006EC74: andi        $v0, $a0, 0xFF
    ctx->r2 = ctx->r4 & 0XFF;
    // 0x8006EC78: sltiu       $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 < 0XFF ? 1 : 0;
    // 0x8006EC7C: bne         $v0, $zero, L_8006EC2C
    if (ctx->r2 != 0) {
        // 0x8006EC80: addu        $a2, $zero, $zero
        ctx->r6 = ADD32(0, 0);
            goto L_8006EC2C;
    }
    // 0x8006EC80: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
L_8006EC84:
    // 0x8006EC84: jr          $ra
    // 0x8006EC88: andi        $v0, $a0, 0xFF
    ctx->r2 = ctx->r4 & 0XFF;
    return;
    // 0x8006EC88: andi        $v0, $a0, 0xFF
    ctx->r2 = ctx->r4 & 0XFF;
;}
RECOMP_FUNC void func_8006EC8C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006EC8C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006EC90: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x8006EC94: jal         0x8006E53C
    // 0x8006EC98: nop

    func_8006E53C(rdram, ctx);
        goto after_0;
    // 0x8006EC98: nop

    after_0:
    // 0x8006EC9C: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8006ECA0: addiu       $a0, $a0, -0x5A40
    ctx->r4 = ADD32(ctx->r4, -0X5A40);
    // 0x8006ECA4: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x8006ECA8: jal         0x800078E0
    // 0x8006ECAC: addiu       $a2, $zero, 0xB0
    ctx->r6 = ADD32(0, 0XB0);
    rs_memset(rdram, ctx);
        goto after_1;
    // 0x8006ECAC: addiu       $a2, $zero, 0xB0
    ctx->r6 = ADD32(0, 0XB0);
    after_1:
    // 0x8006ECB0: jal         0x8006DCCC
    // 0x8006ECB4: nop

    loadDefaultHighscores(rdram, ctx);
        goto after_2;
    // 0x8006ECB4: nop

    after_2:
    // 0x8006ECB8: jal         0x8006F1A8
    // 0x8006ECBC: nop

    func_8006F1A8(rdram, ctx);
        goto after_3;
    // 0x8006ECBC: nop

    after_3:
    // 0x8006ECC0: jal         0x8006E1BC
    // 0x8006ECC4: nop

    func_8006E1BC(rdram, ctx);
        goto after_4;
    // 0x8006ECC4: nop

    after_4:
    // 0x8006ECC8: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x8006ECCC: jr          $ra
    // 0x8006ECD0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8006ECD0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_8006ECD4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006ECD4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006ECD8: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x8006ECDC: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
    // 0x8006ECE0: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8006ECE4: addiu       $a1, $v0, 0xB40
    ctx->r5 = ADD32(ctx->r2, 0XB40);
    // 0x8006ECE8: addiu       $a0, $zero, 0x19B
    ctx->r4 = ADD32(0, 0X19B);
    // 0x8006ECEC: andi        $v0, $v1, 0xFF
    ctx->r2 = ctx->r3 & 0XFF;
    // 0x8006ECF0: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
L_8006ECF4:
    // 0x8006ECF4: addu        $v0, $v0, $a1
    ctx->r2 = ADD32(ctx->r2, ctx->r5);
    // 0x8006ECF8: sw          $a0, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r4;
    // 0x8006ECFC: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8006ED00: andi        $v0, $v1, 0xFF
    ctx->r2 = ctx->r3 & 0XFF;
    // 0x8006ED04: beq         $v0, $zero, L_8006ECF4
    if (ctx->r2 == 0) {
        // 0x8006ED08: sll         $v0, $v0, 2
        ctx->r2 = S32(ctx->r2 << 2);
            goto L_8006ECF4;
    }
    // 0x8006ED08: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8006ED0C: jal         0x80002664
    // 0x8006ED10: nop

    func_80002664(rdram, ctx);
        goto after_0;
    // 0x8006ED10: nop

    after_0:
    // 0x8006ED14: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x8006ED18: addiu       $a1, $v1, 0xB40
    ctx->r5 = ADD32(ctx->r3, 0XB40);
    // 0x8006ED1C: lui         $v1, 0x40
    ctx->r3 = S32(0X40 << 16);
    // 0x8006ED20: sltu        $v1, $v1, $v0
    ctx->r3 = ctx->r3 < ctx->r2 ? 1 : 0;
    // 0x8006ED24: lw          $a0, 0x10($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X10);
    // 0x8006ED28: addiu       $v0, $zero, -0x2
    ctx->r2 = ADD32(0, -0X2);
    // 0x8006ED2C: sb          $v1, 0x23($a1)
    MEM_B(0X23, ctx->r5) = ctx->r3;
    // 0x8006ED30: and         $v0, $a0, $v0
    ctx->r2 = ctx->r4 & ctx->r2;
    // 0x8006ED34: beq         $v1, $zero, L_8006ED44
    if (ctx->r3 == 0) {
        // 0x8006ED38: sw          $v0, 0x10($a1)
        MEM_W(0X10, ctx->r5) = ctx->r2;
            goto L_8006ED44;
    }
    // 0x8006ED38: sw          $v0, 0x10($a1)
    MEM_W(0X10, ctx->r5) = ctx->r2;
    // 0x8006ED3C: ori         $v0, $v0, 0x1
    ctx->r2 = ctx->r2 | 0X1;
    // 0x8006ED40: sw          $v0, 0x10($a1)
    MEM_W(0X10, ctx->r5) = ctx->r2;
L_8006ED44:
    // 0x8006ED44: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x8006ED48: jr          $ra
    // 0x8006ED4C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8006ED4C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_8006ED50(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006ED50: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x8006ED54: addiu       $a0, $a0, 0xB40
    ctx->r4 = ADD32(ctx->r4, 0XB40);
    // 0x8006ED58: addiu       $v0, $zero, 0x7F
    ctx->r2 = ADD32(0, 0X7F);
    // 0x8006ED5C: sb          $v0, 0x20($a0)
    MEM_B(0X20, ctx->r4) = ctx->r2;
    // 0x8006ED60: sb          $v0, 0x21($a0)
    MEM_B(0X21, ctx->r4) = ctx->r2;
    // 0x8006ED64: sb          $v0, 0x22($a0)
    MEM_B(0X22, ctx->r4) = ctx->r2;
    // 0x8006ED68: lw          $v0, 0x10($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X10);
    // 0x8006ED6C: addiu       $v1, $zero, -0x81
    ctx->r3 = ADD32(0, -0X81);
    // 0x8006ED70: and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // 0x8006ED74: addiu       $v1, $zero, -0x5
    ctx->r3 = ADD32(0, -0X5);
    // 0x8006ED78: and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // 0x8006ED7C: addiu       $v1, $zero, -0x9
    ctx->r3 = ADD32(0, -0X9);
    // 0x8006ED80: and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // 0x8006ED84: ori         $v0, $v0, 0x10
    ctx->r2 = ctx->r2 | 0X10;
    // 0x8006ED88: jr          $ra
    // 0x8006ED8C: sw          $v0, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->r2;
    return;
    // 0x8006ED8C: sw          $v0, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->r2;
;}
RECOMP_FUNC void func_8006ED90(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006ED90: lui         $v1, 0x8014
    ctx->r3 = S32(0X8014 << 16);
    // 0x8006ED94: addiu       $v1, $v1, -0x5A40
    ctx->r3 = ADD32(ctx->r3, -0X5A40);
    // 0x8006ED98: andi        $v0, $a0, 0xFF
    ctx->r2 = ctx->r4 & 0XFF;
    // 0x8006ED9C: srl         $v0, $v0, 3
    ctx->r2 = S32(U32(ctx->r2) >> 3);
    // 0x8006EDA0: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8006EDA4: lbu         $v0, 0xA3($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0XA3);
    // 0x8006EDA8: andi        $a0, $a0, 0x7
    ctx->r4 = ctx->r4 & 0X7;
    // 0x8006EDAC: srav        $v0, $v0, $a0
    ctx->r2 = S32(SIGNED(ctx->r2) >> (ctx->r4 & 31));
    // 0x8006EDB0: jr          $ra
    // 0x8006EDB4: andi        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 & 0X1;
    return;
    // 0x8006EDB4: andi        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 & 0X1;
;}
RECOMP_FUNC void gatherActiveUnlockFlags(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006EDB8: lui         $a0, 0x7F
    ctx->r4 = S32(0X7F << 16);
    // 0x8006EDBC: ori         $a0, $a0, 0xFE00
    ctx->r4 = ctx->r4 | 0XFE00;
    // 0x8006EDC0: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8006EDC4: lw          $v0, 0xB4C($v0)
    ctx->r2 = MEM_W(ctx->r2, 0XB4C);
    // 0x8006EDC8: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x8006EDCC: and         $v0, $v0, $a0
    ctx->r2 = ctx->r2 & ctx->r4;
    // 0x8006EDD0: jr          $ra
    // 0x8006EDD4: sw          $v0, 0xB18($v1)
    MEM_W(0XB18, ctx->r3) = ctx->r2;
    return;
    // 0x8006EDD4: sw          $v0, 0xB18($v1)
    MEM_W(0XB18, ctx->r3) = ctx->r2;
;}
RECOMP_FUNC void func_8006EDD8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006EDD8: lui         $v1, 0x7F
    ctx->r3 = S32(0X7F << 16);
    // 0x8006EDDC: ori         $v1, $v1, 0xFE00
    ctx->r3 = ctx->r3 | 0XFE00;
    // 0x8006EDE0: lui         $a2, 0xFF80
    ctx->r6 = S32(0XFF80 << 16);
    // 0x8006EDE4: ori         $a2, $a2, 0x1FF
    ctx->r6 = ctx->r6 | 0X1FF;
    // 0x8006EDE8: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x8006EDEC: addiu       $a0, $a0, 0xB40
    ctx->r4 = ADD32(ctx->r4, 0XB40);
    // 0x8006EDF0: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x8006EDF4: lw          $v0, 0xC($a0)
    ctx->r2 = MEM_W(ctx->r4, 0XC);
    // 0x8006EDF8: lw          $a1, 0xB18($a1)
    ctx->r5 = MEM_W(ctx->r5, 0XB18);
    // 0x8006EDFC: and         $v1, $v0, $v1
    ctx->r3 = ctx->r2 & ctx->r3;
    // 0x8006EE00: and         $v1, $v1, $a1
    ctx->r3 = ctx->r3 & ctx->r5;
    // 0x8006EE04: and         $v0, $v0, $a2
    ctx->r2 = ctx->r2 & ctx->r6;
    // 0x8006EE08: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x8006EE0C: jr          $ra
    // 0x8006EE10: sw          $v1, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r3;
    return;
    // 0x8006EE10: sw          $v1, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r3;
;}
RECOMP_FUNC void unlockMissleUpgradeOnLevelCompletion(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006EE14: andi        $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 & 0XFF;
    // 0x8006EE18: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // 0x8006EE1C: bne         $a0, $v0, L_8006EE3C
    if (ctx->r4 != ctx->r2) {
        // 0x8006EE20: addiu       $v0, $zero, 0x9
        ctx->r2 = ADD32(0, 0X9);
            goto L_8006EE3C;
    }
    // 0x8006EE20: addiu       $v0, $zero, 0x9
    ctx->r2 = ADD32(0, 0X9);
    // 0x8006EE24: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x8006EE28: addiu       $v1, $v1, 0xB40
    ctx->r3 = ADD32(ctx->r3, 0XB40);
    // 0x8006EE2C: lw          $v0, 0xC($v1)
    ctx->r2 = MEM_W(ctx->r3, 0XC);
    // 0x8006EE30: ori         $v0, $v0, 0x1000
    ctx->r2 = ctx->r2 | 0X1000;
    // 0x8006EE34: sw          $v0, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r2;
    // 0x8006EE38: addiu       $v0, $zero, 0x9
    ctx->r2 = ADD32(0, 0X9);
L_8006EE3C:
    // 0x8006EE3C: bne         $a0, $v0, L_8006EE54
    if (ctx->r4 != ctx->r2) {
        // 0x8006EE40: lui         $v1, 0x8013
        ctx->r3 = S32(0X8013 << 16);
            goto L_8006EE54;
    }
    // 0x8006EE40: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x8006EE44: addiu       $v1, $v1, 0xB40
    ctx->r3 = ADD32(ctx->r3, 0XB40);
    // 0x8006EE48: lw          $v0, 0xC($v1)
    ctx->r2 = MEM_W(ctx->r3, 0XC);
    // 0x8006EE4C: ori         $v0, $v0, 0x400
    ctx->r2 = ctx->r2 | 0X400;
    // 0x8006EE50: sw          $v0, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r2;
L_8006EE54:
    // 0x8006EE54: jr          $ra
    // 0x8006EE58: nop

    return;
    // 0x8006EE58: nop

;}
RECOMP_FUNC void func_8006EE5C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006EE5C: andi        $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 & 0XFF;
    // 0x8006EE60: sll         $v1, $a0, 2
    ctx->r3 = S32(ctx->r4 << 2);
    // 0x8006EE64: addu        $v1, $v1, $a0
    ctx->r3 = ADD32(ctx->r3, ctx->r4);
    // 0x8006EE68: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x8006EE6C: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x8006EE70: addiu       $v0, $v0, -0x5A2C
    ctx->r2 = ADD32(ctx->r2, -0X5A2C);
    // 0x8006EE74: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x8006EE78: lbu         $v0, 0x5($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X5);
    // 0x8006EE7C: sltiu       $v0, $v0, 0x11
    ctx->r2 = ctx->r2 < 0X11 ? 1 : 0;
    // 0x8006EE80: bne         $v0, $zero, L_8006EE8C
    if (ctx->r2 != 0) {
        // 0x8006EE84: addiu       $v0, $zero, 0x10
        ctx->r2 = ADD32(0, 0X10);
            goto L_8006EE8C;
    }
    // 0x8006EE84: addiu       $v0, $zero, 0x10
    ctx->r2 = ADD32(0, 0X10);
    // 0x8006EE88: sb          $v0, 0x5($v1)
    MEM_B(0X5, ctx->r3) = ctx->r2;
L_8006EE8C:
    // 0x8006EE8C: jr          $ra
    // 0x8006EE90: addu        $v0, $v1, $zero
    ctx->r2 = ADD32(ctx->r3, 0);
    return;
    // 0x8006EE90: addu        $v0, $v1, $zero
    ctx->r2 = ADD32(ctx->r3, 0);
;}
RECOMP_FUNC void func_8006EE94(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006EE94: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8006EE98: addu        $a2, $a0, $zero
    ctx->r6 = ADD32(ctx->r4, 0);
    // 0x8006EE9C: sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // 0x8006EEA0: addu        $s2, $a1, $zero
    ctx->r18 = ADD32(ctx->r5, 0);
    // 0x8006EEA4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8006EEA8: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x8006EEAC: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x8006EEB0: lbu         $v0, 0x5($a2)
    ctx->r2 = MEM_BU(ctx->r6, 0X5);
    // 0x8006EEB4: sltiu       $v0, $v0, 0x11
    ctx->r2 = ctx->r2 < 0X11 ? 1 : 0;
    // 0x8006EEB8: bne         $v0, $zero, L_8006EEC8
    if (ctx->r2 != 0) {
        // 0x8006EEBC: addu        $v1, $s2, $zero
        ctx->r3 = ADD32(ctx->r18, 0);
            goto L_8006EEC8;
    }
    // 0x8006EEBC: addu        $v1, $s2, $zero
    ctx->r3 = ADD32(ctx->r18, 0);
    // 0x8006EEC0: addiu       $v0, $zero, 0x10
    ctx->r2 = ADD32(0, 0X10);
    // 0x8006EEC4: sb          $v0, 0x5($a2)
    MEM_B(0X5, ctx->r6) = ctx->r2;
L_8006EEC8:
    // 0x8006EEC8: andi        $s0, $v1, 0xFF
    ctx->r16 = ctx->r3 & 0XFF;
    // 0x8006EECC: sll         $v0, $s0, 2
    ctx->r2 = S32(ctx->r16 << 2);
    // 0x8006EED0: addu        $v0, $v0, $s0
    ctx->r2 = ADD32(ctx->r2, ctx->r16);
    // 0x8006EED4: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8006EED8: lui         $v1, 0x8014
    ctx->r3 = S32(0X8014 << 16);
    // 0x8006EEDC: addiu       $s1, $v1, -0x5A2C
    ctx->r17 = ADD32(ctx->r3, -0X5A2C);
    // 0x8006EEE0: addu        $a0, $v0, $s1
    ctx->r4 = ADD32(ctx->r2, ctx->r17);
    // 0x8006EEE4: beq         $a2, $a0, L_8006EEF4
    if (ctx->r6 == ctx->r4) {
        // 0x8006EEE8: addu        $a1, $a2, $zero
        ctx->r5 = ADD32(ctx->r6, 0);
            goto L_8006EEF4;
    }
    // 0x8006EEE8: addu        $a1, $a2, $zero
    ctx->r5 = ADD32(ctx->r6, 0);
    // 0x8006EEEC: jal         0x80018EF4
    // 0x8006EEF0: addiu       $a2, $zero, 0x14
    ctx->r6 = ADD32(0, 0X14);
    zmemcpy(rdram, ctx);
        goto after_0;
    // 0x8006EEF0: addiu       $a2, $zero, 0x14
    ctx->r6 = ADD32(0, 0X14);
    after_0:
L_8006EEF4:
    // 0x8006EEF4: addiu       $v0, $s1, -0x14
    ctx->r2 = ADD32(ctx->r17, -0X14);
    // 0x8006EEF8: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x8006EEFC: lbu         $a0, 0x50($v0)
    ctx->r4 = MEM_BU(ctx->r2, 0X50);
    // 0x8006EF00: sllv        $v1, $v1, $s0
    ctx->r3 = S32(ctx->r3 << (ctx->r16 & 31));
    // 0x8006EF04: sb          $s2, 0x51($v0)
    MEM_B(0X51, ctx->r2) = ctx->r18;
    // 0x8006EF08: or          $a0, $a0, $v1
    ctx->r4 = ctx->r4 | ctx->r3;
    // 0x8006EF0C: jal         0x8006F1A8
    // 0x8006EF10: sb          $a0, 0x50($v0)
    MEM_B(0X50, ctx->r2) = ctx->r4;
    func_8006F1A8(rdram, ctx);
        goto after_1;
    // 0x8006EF10: sb          $a0, 0x50($v0)
    MEM_B(0X50, ctx->r2) = ctx->r4;
    after_1:
    // 0x8006EF14: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8006EF18: lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X18);
    // 0x8006EF1C: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x8006EF20: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x8006EF24: jr          $ra
    // 0x8006EF28: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x8006EF28: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_8006EF2C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006EF2C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8006EF30: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x8006EF34: andi        $s1, $a0, 0xFF
    ctx->r17 = ctx->r4 & 0XFF;
    // 0x8006EF38: sll         $a0, $s1, 2
    ctx->r4 = S32(ctx->r17 << 2);
    // 0x8006EF3C: addu        $a0, $a0, $s1
    ctx->r4 = ADD32(ctx->r4, ctx->r17);
    // 0x8006EF40: sll         $a0, $a0, 2
    ctx->r4 = S32(ctx->r4 << 2);
    // 0x8006EF44: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x8006EF48: lui         $s0, 0x8014
    ctx->r16 = S32(0X8014 << 16);
    // 0x8006EF4C: addiu       $s0, $s0, -0x5A2C
    ctx->r16 = ADD32(ctx->r16, -0X5A2C);
    // 0x8006EF50: addu        $a0, $a0, $s0
    ctx->r4 = ADD32(ctx->r4, ctx->r16);
    // 0x8006EF54: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x8006EF58: sw          $ra, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r31;
    // 0x8006EF5C: jal         0x800078E0
    // 0x8006EF60: addiu       $a2, $zero, 0x14
    ctx->r6 = ADD32(0, 0X14);
    rs_memset(rdram, ctx);
        goto after_0;
    // 0x8006EF60: addiu       $a2, $zero, 0x14
    ctx->r6 = ADD32(0, 0X14);
    after_0:
    // 0x8006EF64: addiu       $s0, $s0, -0x14
    ctx->r16 = ADD32(ctx->r16, -0X14);
    // 0x8006EF68: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8006EF6C: sllv        $v0, $v0, $s1
    ctx->r2 = S32(ctx->r2 << (ctx->r17 & 31));
    // 0x8006EF70: lbu         $v1, 0x50($s0)
    ctx->r3 = MEM_BU(ctx->r16, 0X50);
    // 0x8006EF74: nor         $v0, $zero, $v0
    ctx->r2 = ~(0 | ctx->r2);
    // 0x8006EF78: and         $v1, $v1, $v0
    ctx->r3 = ctx->r3 & ctx->r2;
    // 0x8006EF7C: jal         0x8006F1A8
    // 0x8006EF80: sb          $v1, 0x50($s0)
    MEM_B(0X50, ctx->r16) = ctx->r3;
    func_8006F1A8(rdram, ctx);
        goto after_1;
    // 0x8006EF80: sb          $v1, 0x50($s0)
    MEM_B(0X50, ctx->r16) = ctx->r3;
    after_1:
    // 0x8006EF84: lw          $ra, 0x18($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X18);
    // 0x8006EF88: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x8006EF8C: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x8006EF90: jr          $ra
    // 0x8006EF94: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x8006EF94: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_8006EF98(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006EF98: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006EF9C: andi        $a2, $a0, 0xFF
    ctx->r6 = ctx->r4 & 0XFF;
    // 0x8006EFA0: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    // 0x8006EFA4: lui         $a3, 0x8007
    ctx->r7 = S32(0X8007 << 16);
    // 0x8006EFA8: addiu       $a1, $zero, 0x800
    ctx->r5 = ADD32(0, 0X800);
    // 0x8006EFAC: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x8006EFB0: jal         0x80006C28
    // 0x8006EFB4: addiu       $a3, $a3, -0xD34
    ctx->r7 = ADD32(ctx->r7, -0XD34);
    func_80006C28(rdram, ctx);
        goto after_0;
    // 0x8006EFB4: addiu       $a3, $a3, -0xD34
    ctx->r7 = ADD32(ctx->r7, -0XD34);
    after_0:
    // 0x8006EFB8: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // 0x8006EFBC: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x8006EFC0: jal         0x80006D9C
    // 0x8006EFC4: sw          $a0, 0xA60($v0)
    MEM_W(0XA60, ctx->r2) = ctx->r4;
    func_80006D9C(rdram, ctx);
        goto after_1;
    // 0x8006EFC4: sw          $a0, 0xA60($v0)
    MEM_W(0XA60, ctx->r2) = ctx->r4;
    after_1:
    // 0x8006EFC8: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x8006EFCC: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x8006EFD0: sb          $zero, -0x5A4F($v0)
    MEM_B(-0X5A4F, ctx->r2) = 0;
    // 0x8006EFD4: jr          $ra
    // 0x8006EFD8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8006EFD8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_8006EFDC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006EFDC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8006EFE0: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x8006EFE4: lui         $s1, 0x800A
    ctx->r17 = S32(0X800A << 16);
    // 0x8006EFE8: lw          $a0, 0xA60($s1)
    ctx->r4 = MEM_W(ctx->r17, 0XA60);
    // 0x8006EFEC: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x8006EFF0: addiu       $s0, $zero, -0x1
    ctx->r16 = ADD32(0, -0X1);
    // 0x8006EFF4: beq         $a0, $s0, L_8006F004
    if (ctx->r4 == ctx->r16) {
        // 0x8006EFF8: sw          $ra, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r31;
            goto L_8006F004;
    }
    // 0x8006EFF8: sw          $ra, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r31;
    // 0x8006EFFC: jal         0x800070BC
    // 0x8006F000: nop

    func_800070BC(rdram, ctx);
        goto after_0;
    // 0x8006F000: nop

    after_0:
L_8006F004:
    // 0x8006F004: lw          $ra, 0x18($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X18);
    // 0x8006F008: sw          $s0, 0xA60($s1)
    MEM_W(0XA60, ctx->r17) = ctx->r16;
    // 0x8006F00C: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x8006F010: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x8006F014: jr          $ra
    // 0x8006F018: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x8006F018: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void isViModeTypePal(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006F01C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006F020: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x8006F024: jal         0x8000273C
    // 0x8006F028: nop

    getViModeType(rdram, ctx);
        goto after_0;
    // 0x8006F028: nop

    after_0:
    // 0x8006F02C: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x8006F030: xori        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 ^ 0X1;
    // 0x8006F034: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x8006F038: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8006F03C: jr          $ra
    // 0x8006F040: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8006F040: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_8006F044(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006F044: lui         $v1, 0x2AAA
    ctx->r3 = S32(0X2AAA << 16);
    // 0x8006F048: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8006F04C: addiu       $a1, $v0, 0xB40
    ctx->r5 = ADD32(ctx->r2, 0XB40);
    // 0x8006F050: lbu         $a0, 0x14($a1)
    ctx->r4 = MEM_BU(ctx->r5, 0X14);
    // 0x8006F054: ori         $v1, $v1, 0xAAAB
    ctx->r3 = ctx->r3 | 0XAAAB;
    // 0x8006F058: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x8006F05C: mult        $a0, $v1
    result = S64(S32(ctx->r4)) * S64(S32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8006F060: sra         $v1, $a0, 31
    ctx->r3 = S32(SIGNED(ctx->r4) >> 31);
    // 0x8006F064: mfhi        $a2
    ctx->r6 = hi;
    // 0x8006F068: subu        $v1, $a2, $v1
    ctx->r3 = SUB32(ctx->r6, ctx->r3);
    // 0x8006F06C: sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3 << 1);
    // 0x8006F070: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8006F074: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x8006F078: subu        $a0, $a0, $v0
    ctx->r4 = SUB32(ctx->r4, ctx->r2);
    // 0x8006F07C: sb          $a0, 0x14($a1)
    MEM_B(0X14, ctx->r5) = ctx->r4;
    // 0x8006F080: andi        $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 & 0XFF;
    // 0x8006F084: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
    // 0x8006F088: bne         $a0, $v0, L_8006F0B0
    if (ctx->r4 != ctx->r2) {
        // 0x8006F08C: nop
    
            goto L_8006F0B0;
    }
    // 0x8006F08C: nop

    // 0x8006F090: lbu         $v1, 0x15($a1)
    ctx->r3 = MEM_BU(ctx->r5, 0X15);
    // 0x8006F094: sltiu       $v0, $v1, 0x4
    ctx->r2 = ctx->r3 < 0X4 ? 1 : 0;
    // 0x8006F098: beql        $v0, $zero, L_8006F0B0
    if (ctx->r2 == 0) {
        // 0x8006F09C: sb          $zero, 0x15($a1)
        MEM_B(0X15, ctx->r5) = 0;
            goto L_8006F0B0;
    }
    goto skip_0;
    // 0x8006F09C: sb          $zero, 0x15($a1)
    MEM_B(0X15, ctx->r5) = 0;
    skip_0:
    // 0x8006F0A0: addiu       $v0, $v1, 0x1
    ctx->r2 = ADD32(ctx->r3, 0X1);
    // 0x8006F0A4: sb          $v0, 0x15($a1)
    MEM_B(0X15, ctx->r5) = ctx->r2;
    // 0x8006F0A8: jr          $ra
    // 0x8006F0AC: sb          $zero, 0x14($a1)
    MEM_B(0X14, ctx->r5) = 0;
    return;
    // 0x8006F0AC: sb          $zero, 0x14($a1)
    MEM_B(0X14, ctx->r5) = 0;
L_8006F0B0:
    // 0x8006F0B0: jr          $ra
    // 0x8006F0B4: nop

    return;
    // 0x8006F0B4: nop

;}
RECOMP_FUNC void func_8006F0B8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006F0B8: addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
    // 0x8006F0BC: beq         $a0, $v0, L_8006F0F4
    if (ctx->r4 == ctx->r2) {
        // 0x8006F0C0: lui         $v1, 0x8014
        ctx->r3 = S32(0X8014 << 16);
            goto L_8006F0F4;
    }
    // 0x8006F0C0: lui         $v1, 0x8014
    ctx->r3 = S32(0X8014 << 16);
    // 0x8006F0C4: slti        $v0, $a0, 0x9
    ctx->r2 = SIGNED(ctx->r4) < 0X9 ? 1 : 0;
    // 0x8006F0C8: beq         $v0, $zero, L_8006F0E0
    if (ctx->r2 == 0) {
        // 0x8006F0CC: addiu       $v0, $zero, 0x6
        ctx->r2 = ADD32(0, 0X6);
            goto L_8006F0E0;
    }
    // 0x8006F0CC: addiu       $v0, $zero, 0x6
    ctx->r2 = ADD32(0, 0X6);
    // 0x8006F0D0: beq         $a0, $v0, L_8006F0EC
    if (ctx->r4 == ctx->r2) {
        // 0x8006F0D4: addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
            goto L_8006F0EC;
    }
    // 0x8006F0D4: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // 0x8006F0D8: j           L_8006F104
    // 0x8006F0DC: nop

        goto L_8006F104;
    // 0x8006F0DC: nop

L_8006F0E0:
    // 0x8006F0E0: addiu       $v0, $zero, 0x9
    ctx->r2 = ADD32(0, 0X9);
    // 0x8006F0E4: bne         $a0, $v0, L_8006F104
    if (ctx->r4 != ctx->r2) {
        // 0x8006F0E8: addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
            goto L_8006F104;
    }
    // 0x8006F0E8: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_8006F0EC:
    // 0x8006F0EC: jr          $ra
    // 0x8006F0F0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x8006F0F0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8006F0F4:
    // 0x8006F0F4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8006F0F8: sb          $v0, -0x5A50($v1)
    MEM_B(-0X5A50, ctx->r3) = ctx->r2;
    // 0x8006F0FC: jr          $ra
    // 0x8006F100: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    return;
    // 0x8006F100: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
L_8006F104:
    // 0x8006F104: jr          $ra
    // 0x8006F108: nop

    return;
    // 0x8006F108: nop

;}
RECOMP_FUNC void func_8006F10C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006F10C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8006F110: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8006F114: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8006F118: addiu       $s2, $v0, 0xB40
    ctx->r18 = ADD32(ctx->r2, 0XB40);
    // 0x8006F11C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8006F120: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8006F124: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8006F128: lbu         $v0, 0x2C($s2)
    ctx->r2 = MEM_BU(ctx->r18, 0X2C);
    // 0x8006F12C: bne         $v0, $zero, L_8006F190
    if (ctx->r2 != 0) {
        // 0x8006F130: addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
            goto L_8006F190;
    }
    // 0x8006F130: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // 0x8006F134: addiu       $s1, $zero, 0xB0
    ctx->r17 = ADD32(0, 0XB0);
    // 0x8006F138: sw          $s1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r17;
    // 0x8006F13C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8006F140: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x8006F144: addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    // 0x8006F148: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x8006F14C: addiu       $s0, $v0, -0x5A40
    ctx->r16 = ADD32(ctx->r2, -0X5A40);
    // 0x8006F150: jal         0x80006934
    // 0x8006F154: addu        $a3, $s0, $zero
    ctx->r7 = ADD32(ctx->r16, 0);
    func_80006934(rdram, ctx);
        goto after_0;
    // 0x8006F154: addu        $a3, $s0, $zero
    ctx->r7 = ADD32(ctx->r16, 0);
    after_0:
    // 0x8006F158: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // 0x8006F15C: andi        $v0, $v1, 0xFF
    ctx->r2 = ctx->r3 & 0XFF;
    // 0x8006F160: beq         $v0, $zero, L_8006F184
    if (ctx->r2 == 0) {
        // 0x8006F164: addiu       $a0, $zero, 0x1
        ctx->r4 = ADD32(0, 0X1);
            goto L_8006F184;
    }
    // 0x8006F164: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8006F168: sw          $s1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r17;
    // 0x8006F16C: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x8006F170: addu        $a2, $a0, $zero
    ctx->r6 = ADD32(ctx->r4, 0);
    // 0x8006F174: jal         0x80006934
    // 0x8006F178: addu        $a3, $s0, $zero
    ctx->r7 = ADD32(ctx->r16, 0);
    func_80006934(rdram, ctx);
        goto after_1;
    // 0x8006F178: addu        $a3, $s0, $zero
    ctx->r7 = ADD32(ctx->r16, 0);
    after_1:
    // 0x8006F17C: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // 0x8006F180: andi        $v0, $v1, 0xFF
    ctx->r2 = ctx->r3 & 0XFF;
L_8006F184:
    // 0x8006F184: lw          $v1, 0xAC($s0)
    ctx->r3 = MEM_W(ctx->r16, 0XAC);
    // 0x8006F188: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8006F18C: sw          $v1, 0x28($s2)
    MEM_W(0X28, ctx->r18) = ctx->r3;
L_8006F190:
    // 0x8006F190: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8006F194: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8006F198: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8006F19C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8006F1A0: jr          $ra
    // 0x8006F1A4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x8006F1A4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_8006F1A8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006F1A8: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8006F1AC: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x8006F1B0: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x8006F1B4: addiu       $s0, $v0, -0x5A40
    ctx->r16 = ADD32(ctx->r2, -0X5A40);
    // 0x8006F1B8: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8006F1BC: sw          $s1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r17;
    // 0x8006F1C0: addiu       $s1, $v0, 0xB40
    ctx->r17 = ADD32(ctx->r2, 0XB40);
    // 0x8006F1C4: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x8006F1C8: sw          $s2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r18;
    // 0x8006F1CC: lbu         $v1, 0x23($s1)
    ctx->r3 = MEM_BU(ctx->r17, 0X23);
    // 0x8006F1D0: lw          $a0, 0x28($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X28);
    // 0x8006F1D4: addiu       $v0, $zero, 0x3A
    ctx->r2 = ADD32(0, 0X3A);
    // 0x8006F1D8: sb          $v0, 0xA2($s0)
    MEM_B(0XA2, ctx->r16) = ctx->r2;
    // 0x8006F1DC: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x8006F1E0: sb          $v1, 0xA9($s0)
    MEM_B(0XA9, ctx->r16) = ctx->r3;
    // 0x8006F1E4: lw          $v1, 0xA60($v0)
    ctx->r3 = MEM_W(ctx->r2, 0XA60);
    // 0x8006F1E8: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x8006F1EC: bne         $v1, $v0, L_8006F254
    if (ctx->r3 != ctx->r2) {
        // 0x8006F1F0: sw          $a0, 0xAC($s0)
        MEM_W(0XAC, ctx->r16) = ctx->r4;
            goto L_8006F254;
    }
    // 0x8006F1F0: sw          $a0, 0xAC($s0)
    MEM_W(0XAC, ctx->r16) = ctx->r4;
    // 0x8006F1F4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8006F1F8: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x8006F1FC: addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    // 0x8006F200: addiu       $a3, $sp, 0x18
    ctx->r7 = ADD32(ctx->r29, 0X18);
    // 0x8006F204: addiu       $s2, $zero, 0xB0
    ctx->r18 = ADD32(0, 0XB0);
    // 0x8006F208: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x8006F20C: jal         0x80006798
    // 0x8006F210: sw          $s2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r18;
    func_80006798(rdram, ctx);
        goto after_0;
    // 0x8006F210: sw          $s2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r18;
    after_0:
    // 0x8006F214: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x8006F218: bne         $v0, $zero, L_8006F228
    if (ctx->r2 != 0) {
        // 0x8006F21C: addiu       $a0, $zero, 0x1
        ctx->r4 = ADD32(0, 0X1);
            goto L_8006F228;
    }
    // 0x8006F21C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8006F220: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8006F224: sb          $v0, 0x2C($s1)
    MEM_B(0X2C, ctx->r17) = ctx->r2;
L_8006F228:
    // 0x8006F228: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x8006F22C: addu        $a2, $a0, $zero
    ctx->r6 = ADD32(ctx->r4, 0);
    // 0x8006F230: addiu       $a3, $sp, 0x18
    ctx->r7 = ADD32(ctx->r29, 0X18);
    // 0x8006F234: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x8006F238: jal         0x80006798
    // 0x8006F23C: sw          $s2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r18;
    func_80006798(rdram, ctx);
        goto after_1;
    // 0x8006F23C: sw          $s2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r18;
    after_1:
    // 0x8006F240: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x8006F244: bne         $v0, $zero, L_8006F25C
    if (ctx->r2 != 0) {
        // 0x8006F248: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_8006F25C;
    }
    // 0x8006F248: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8006F24C: j           L_8006F25C
    // 0x8006F250: sb          $v0, 0x2C($s1)
    MEM_B(0X2C, ctx->r17) = ctx->r2;
        goto L_8006F25C;
    // 0x8006F250: sb          $v0, 0x2C($s1)
    MEM_B(0X2C, ctx->r17) = ctx->r2;
L_8006F254:
    // 0x8006F254: jal         0x8006F274
    // 0x8006F258: nop

    func_8006F274(rdram, ctx);
        goto after_2;
    // 0x8006F258: nop

    after_2:
L_8006F25C:
    // 0x8006F25C: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x8006F260: lw          $s2, 0x30($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X30);
    // 0x8006F264: lw          $s1, 0x2C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X2C);
    // 0x8006F268: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x8006F26C: jr          $ra
    // 0x8006F270: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x8006F270: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_8006F274(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006F274: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006F278: addiu       $a0, $zero, 0x14
    ctx->r4 = ADD32(0, 0X14);
    // 0x8006F27C: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x8006F280: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006F284: jal         0x80001ACC
    // 0x8006F288: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    rs_malloc(rdram, ctx);
        goto after_0;
    // 0x8006F288: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    after_0:
    // 0x8006F28C: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    // 0x8006F290: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x8006F294: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x8006F298: jal         0x800078E0
    // 0x8006F29C: addiu       $a2, $zero, 0x14
    ctx->r6 = ADD32(0, 0X14);
    rs_memset(rdram, ctx);
        goto after_1;
    // 0x8006F29C: addiu       $a2, $zero, 0x14
    ctx->r6 = ADD32(0, 0X14);
    after_1:
    // 0x8006F2A0: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    // 0x8006F2A4: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x8006F2A8: lw          $a0, -0x76E0($v0)
    ctx->r4 = MEM_W(ctx->r2, -0X76E0);
    // 0x8006F2AC: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x8006F2B0: lw          $a1, 0xA60($v0)
    ctx->r5 = MEM_W(ctx->r2, 0XA60);
    // 0x8006F2B4: jal         0x80006F78
    // 0x8006F2B8: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    func_80006F78(rdram, ctx);
        goto after_2;
    // 0x8006F2B8: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    after_2:
    // 0x8006F2BC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006F2C0: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x8006F2C4: jr          $ra
    // 0x8006F2C8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8006F2C8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_8006F2CC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006F2CC: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x8006F2D0: sw          $s5, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r21;
    // 0x8006F2D4: addu        $s5, $a0, $zero
    ctx->r21 = ADD32(ctx->r4, 0);
    // 0x8006F2D8: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    // 0x8006F2DC: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x8006F2E0: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    // 0x8006F2E4: sw          $ra, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r31;
    // 0x8006F2E8: sw          $s4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r20;
    // 0x8006F2EC: sw          $s3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r19;
    // 0x8006F2F0: sw          $s2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r18;
    // 0x8006F2F4: sw          $s1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r17;
    // 0x8006F2F8: jal         0x800078E0
    // 0x8006F2FC: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    rs_memset(rdram, ctx);
        goto after_0;
    // 0x8006F2FC: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    after_0:
    // 0x8006F300: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x8006F304: addiu       $s4, $v0, -0x5A40
    ctx->r20 = ADD32(ctx->r2, -0X5A40);
    // 0x8006F308: addiu       $s3, $zero, 0xB0
    ctx->r19 = ADD32(0, 0XB0);
    // 0x8006F30C: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8006F310: addiu       $s2, $v0, 0xB40
    ctx->r18 = ADD32(ctx->r2, 0XB40);
    // 0x8006F314: addiu       $s1, $zero, 0x1
    ctx->r17 = ADD32(0, 0X1);
L_8006F318:
    // 0x8006F318: lw          $a0, 0x0($s5)
    ctx->r4 = MEM_W(ctx->r21, 0X0);
    // 0x8006F31C: jal         0x80006F24
    // 0x8006F320: nop

    func_80006F24(rdram, ctx);
        goto after_1;
    // 0x8006F320: nop

    after_1:
    // 0x8006F324: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8006F328: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x8006F32C: addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    // 0x8006F330: addiu       $a3, $sp, 0x18
    ctx->r7 = ADD32(ctx->r29, 0X18);
    // 0x8006F334: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    // 0x8006F338: sw          $s4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r20;
    // 0x8006F33C: jal         0x80006798
    // 0x8006F340: sw          $s3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r19;
    func_80006798(rdram, ctx);
        goto after_2;
    // 0x8006F340: sw          $s3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r19;
    after_2:
    // 0x8006F344: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x8006F348: beql        $v0, $zero, L_8006F350
    if (ctx->r2 == 0) {
        // 0x8006F34C: sb          $s1, 0x2C($s2)
        MEM_B(0X2C, ctx->r18) = ctx->r17;
            goto L_8006F350;
    }
    goto skip_0;
    // 0x8006F34C: sb          $s1, 0x2C($s2)
    MEM_B(0X2C, ctx->r18) = ctx->r17;
    skip_0:
L_8006F350:
    // 0x8006F350: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8006F354: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x8006F358: addu        $a2, $a0, $zero
    ctx->r6 = ADD32(ctx->r4, 0);
    // 0x8006F35C: addiu       $a3, $sp, 0x18
    ctx->r7 = ADD32(ctx->r29, 0X18);
    // 0x8006F360: sw          $s4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r20;
    // 0x8006F364: jal         0x80006798
    // 0x8006F368: sw          $s3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r19;
    func_80006798(rdram, ctx);
        goto after_3;
    // 0x8006F368: sw          $s3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r19;
    after_3:
    // 0x8006F36C: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x8006F370: beql        $v0, $zero, L_8006F378
    if (ctx->r2 == 0) {
        // 0x8006F374: sb          $s1, 0x2C($s2)
        MEM_B(0X2C, ctx->r18) = ctx->r17;
            goto L_8006F378;
    }
    goto skip_1;
    // 0x8006F374: sb          $s1, 0x2C($s2)
    MEM_B(0X2C, ctx->r18) = ctx->r17;
    skip_1:
L_8006F378:
    // 0x8006F378: jal         0x80001C98
    // 0x8006F37C: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    rs_free(rdram, ctx);
        goto after_4;
    // 0x8006F37C: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_4:
    // 0x8006F380: j           L_8006F318
    // 0x8006F384: nop

        goto L_8006F318;
    // 0x8006F384: nop

;}
RECOMP_FUNC void func_8006F388(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006F388: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x8006F38C: lbu         $v0, -0x599E($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X599E);
    // 0x8006F390: xori        $v0, $v0, 0x3A
    ctx->r2 = ctx->r2 ^ 0X3A;
    // 0x8006F394: jr          $ra
    // 0x8006F398: sltu        $v0, $zero, $v0
    ctx->r2 = 0 < ctx->r2 ? 1 : 0;
    return;
    // 0x8006F398: sltu        $v0, $zero, $v0
    ctx->r2 = 0 < ctx->r2 ? 1 : 0;
;}
RECOMP_FUNC void setAccountHighscore(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006F39C: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x8006F3A0: addiu       $v0, $v0, -0x5A40
    ctx->r2 = ADD32(ctx->r2, -0X5A40);
    // 0x8006F3A4: andi        $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 & 0XFF;
    // 0x8006F3A8: sll         $a0, $a0, 3
    ctx->r4 = S32(ctx->r4 << 3);
    // 0x8006F3AC: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x8006F3B0: addiu       $v1, $v1, 0xB40
    ctx->r3 = ADD32(ctx->r3, 0XB40);
    // 0x8006F3B4: lbu         $a3, 0x7($v1)
    ctx->r7 = MEM_BU(ctx->r3, 0X7);
    // 0x8006F3B8: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // 0x8006F3BC: sb          $a3, 0x52($a0)
    MEM_B(0X52, ctx->r4) = ctx->r7;
    // 0x8006F3C0: lbu         $v0, 0x8($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X8);
    // 0x8006F3C4: sb          $v0, 0x53($a0)
    MEM_B(0X53, ctx->r4) = ctx->r2;
    // 0x8006F3C8: lbu         $v0, 0x9($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X9);
    // 0x8006F3CC: sb          $a2, 0x55($a0)
    MEM_B(0X55, ctx->r4) = ctx->r6;
    // 0x8006F3D0: sh          $a1, 0x56($a0)
    MEM_H(0X56, ctx->r4) = ctx->r5;
    // 0x8006F3D4: sb          $v0, 0x54($a0)
    MEM_B(0X54, ctx->r4) = ctx->r2;
    // 0x8006F3D8: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8006F3DC: lbu         $v0, 0xB34($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0XB34);
    // 0x8006F3E0: jr          $ra
    // 0x8006F3E4: sb          $v0, 0x58($a0)
    MEM_B(0X58, ctx->r4) = ctx->r2;
    return;
    // 0x8006F3E4: sb          $v0, 0x58($a0)
    MEM_B(0X58, ctx->r4) = ctx->r2;
;}
RECOMP_FUNC void getAccountHighscore(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006F3E8: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x8006F3EC: addiu       $v0, $v0, -0x5A40
    ctx->r2 = ADD32(ctx->r2, -0X5A40);
    // 0x8006F3F0: andi        $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 & 0XFF;
    // 0x8006F3F4: sll         $a0, $a0, 3
    ctx->r4 = S32(ctx->r4 << 3);
    // 0x8006F3F8: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // 0x8006F3FC: lhu         $a1, 0x56($a0)
    ctx->r5 = MEM_HU(ctx->r4, 0X56);
    // 0x8006F400: lbu         $a0, 0x58($a0)
    ctx->r4 = MEM_BU(ctx->r4, 0X58);
    // 0x8006F404: andi        $v1, $a1, 0x1F
    ctx->r3 = ctx->r5 & 0X1F;
    // 0x8006F408: srl         $v0, $a1, 4
    ctx->r2 = S32(U32(ctx->r5) >> 4);
    // 0x8006F40C: andi        $v0, $v0, 0x3E
    ctx->r2 = ctx->r2 & 0X3E;
    // 0x8006F410: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x8006F414: srl         $v0, $a1, 8
    ctx->r2 = S32(U32(ctx->r5) >> 8);
    // 0x8006F418: andi        $v0, $v0, 0x7C
    ctx->r2 = ctx->r2 & 0X7C;
    // 0x8006F41C: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x8006F420: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8006F424: lbu         $v0, 0xB34($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0XB34);
    // 0x8006F428: bne         $a0, $v0, L_8006F434
    if (ctx->r4 != ctx->r2) {
        // 0x8006F42C: sll         $a1, $v1, 1
        ctx->r5 = S32(ctx->r3 << 1);
            goto L_8006F434;
    }
    // 0x8006F42C: sll         $a1, $v1, 1
    ctx->r5 = S32(ctx->r3 << 1);
    // 0x8006F430: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
L_8006F434:
    // 0x8006F434: jr          $ra
    // 0x8006F438: addu        $v0, $a1, $zero
    ctx->r2 = ADD32(ctx->r5, 0);
    return;
    // 0x8006F438: addu        $v0, $a1, $zero
    ctx->r2 = ADD32(ctx->r5, 0);
;}
RECOMP_FUNC void getSecondaryWeaponCount(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006F43C: andi        $v1, $a0, 0xFF
    ctx->r3 = ctx->r4 & 0XFF;
    // 0x8006F440: sltiu       $v0, $v1, 0x9
    ctx->r2 = ctx->r3 < 0X9 ? 1 : 0;
    // 0x8006F444: beq         $v0, $zero, L_8006F4A4
    if (ctx->r2 == 0) {
        // 0x8006F448: addu        $a2, $zero, $zero
        ctx->r6 = ADD32(0, 0);
            goto L_8006F4A4;
    }
    // 0x8006F448: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // 0x8006F44C: lui         $v0, 0x8004
    ctx->r2 = S32(0X8004 << 16);
    // 0x8006F450: addiu       $v0, $v0, -0x34B8
    ctx->r2 = ADD32(ctx->r2, -0X34B8);
    // 0x8006F454: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x8006F458: addu        $v1, $v1, $v0
    gpr jr_addend_8006F460 = ctx->r3;
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x8006F45C: lw          $v0, 0x0($v1)
    ctx->r2 = ADD32(ctx->r3, 0X0);
    // 0x8006F460: jr          $v0
    // 0x8006F464: nop

    switch (jr_addend_8006F460 >> 2) {
        case 0: goto L_8006F468; break;
        case 1: goto L_8006F480; break;
        case 2: goto L_8006F498; break;
        case 3: goto L_8006F488; break;
        case 4: goto L_8006F488; break;
        case 5: goto L_8006F490; break;
        case 6: goto L_8006F498; break;
        case 7: goto L_8006F478; break;
        case 8: goto L_8006F4A0; break;
        default: switch_error(__func__, 0x8006F460, 0x8003CB48);
    }
    // 0x8006F464: nop

L_8006F468:
    // 0x8006F468: andi        $v1, $a1, 0xFF
    ctx->r3 = ctx->r5 & 0XFF;
    // 0x8006F46C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8006F470: bne         $v1, $v0, L_8006F4A4
    if (ctx->r3 != ctx->r2) {
        // 0x8006F474: addiu       $a2, $zero, 0x6
        ctx->r6 = ADD32(0, 0X6);
            goto L_8006F4A4;
    }
    // 0x8006F474: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
L_8006F478:
    // 0x8006F478: j           L_8006F4A4
    // 0x8006F47C: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
        goto L_8006F4A4;
    // 0x8006F47C: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
L_8006F480:
    // 0x8006F480: j           L_8006F4A4
    // 0x8006F484: addiu       $a2, $zero, 0x14
    ctx->r6 = ADD32(0, 0X14);
        goto L_8006F4A4;
    // 0x8006F484: addiu       $a2, $zero, 0x14
    ctx->r6 = ADD32(0, 0X14);
L_8006F488:
    // 0x8006F488: j           L_8006F4A4
    // 0x8006F48C: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
        goto L_8006F4A4;
    // 0x8006F48C: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
L_8006F490:
    // 0x8006F490: j           L_8006F4A4
    // 0x8006F494: addiu       $a2, $zero, 0xF
    ctx->r6 = ADD32(0, 0XF);
        goto L_8006F4A4;
    // 0x8006F494: addiu       $a2, $zero, 0xF
    ctx->r6 = ADD32(0, 0XF);
L_8006F498:
    // 0x8006F498: j           L_8006F4A4
    // 0x8006F49C: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
        goto L_8006F4A4;
    // 0x8006F49C: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
L_8006F4A0:
    // 0x8006F4A0: addiu       $a2, $zero, 0xA
    ctx->r6 = ADD32(0, 0XA);
L_8006F4A4:
    // 0x8006F4A4: jr          $ra
    // 0x8006F4A8: addu        $v0, $a2, $zero
    ctx->r2 = ADD32(ctx->r6, 0);
    return;
    // 0x8006F4A8: addu        $v0, $a2, $zero
    ctx->r2 = ADD32(ctx->r6, 0);
;}
RECOMP_FUNC void fake_func_8006F4AC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
;}
RECOMP_FUNC void func_8006F4B0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006F4B0: addiu       $sp, $sp, -0xC8
    ctx->r29 = ADD32(ctx->r29, -0XC8);
    // 0x8006F4B4: sdc1        $f22, 0xB8($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0XB8, ctx->r29);
    // 0x8006F4B8: mtc1        $a2, $f22
    ctx->f22.u32l = ctx->r6;
    // 0x8006F4BC: sw          $s1, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->r17;
    // 0x8006F4C0: addu        $s1, $a0, $zero
    ctx->r17 = ADD32(ctx->r4, 0);
    // 0x8006F4C4: sdc1        $f24, 0xC0($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0XC0, ctx->r29);
    // 0x8006F4C8: mtc1        $a3, $f24
    ctx->f24.u32l = ctx->r7;
    // 0x8006F4CC: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    // 0x8006F4D0: sdc1        $f20, 0xB0($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0XB0, ctx->r29);
    // 0x8006F4D4: lwc1        $f20, 0xD8($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0XD8);
    // 0x8006F4D8: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // 0x8006F4DC: sw          $ra, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->r31;
    // 0x8006F4E0: jal         0x80041B8C
    // 0x8006F4E4: sw          $s0, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->r16;
    func_80041B8C(rdram, ctx);
        goto after_0;
    // 0x8006F4E4: sw          $s0, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->r16;
    after_0:
    // 0x8006F4E8: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x8006F4EC: addiu       $v0, $v0, -0x6790
    ctx->r2 = ADD32(ctx->r2, -0X6790);
    // 0x8006F4F0: sw          $v0, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r2;
    // 0x8006F4F4: addiu       $v0, $zero, 0xB
    ctx->r2 = ADD32(0, 0XB);
    // 0x8006F4F8: sb          $v0, 0x7C($sp)
    MEM_B(0X7C, ctx->r29) = ctx->r2;
    // 0x8006F4FC: addiu       $v0, $zero, 0x1E00
    ctx->r2 = ADD32(0, 0X1E00);
    // 0x8006F500: sh          $v0, 0x7E($sp)
    MEM_H(0X7E, ctx->r29) = ctx->r2;
    // 0x8006F504: addiu       $v0, $zero, 0x10
    ctx->r2 = ADD32(0, 0X10);
    // 0x8006F508: sb          $v0, 0x7D($sp)
    MEM_B(0X7D, ctx->r29) = ctx->r2;
    // 0x8006F50C: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8006F510: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8006F514: lw          $v0, 0xC04($v0)
    ctx->r2 = MEM_W(ctx->r2, 0XC04);
    // 0x8006F518: lhu         $v1, 0x8C($sp)
    ctx->r3 = MEM_HU(ctx->r29, 0X8C);
    // 0x8006F51C: addiu       $v0, $v0, 0x40
    ctx->r2 = ADD32(ctx->r2, 0X40);
    // 0x8006F520: ori         $v1, $v1, 0x18
    ctx->r3 = ctx->r3 | 0X18;
    // 0x8006F524: c.lt.s      $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f22.fl < ctx->f0.fl;
    // 0x8006F528: sw          $v0, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r2;
    // 0x8006F52C: bc1f        L_8006F554
    if (!c1cs) {
        // 0x8006F530: sh          $v1, 0x8C($sp)
        MEM_H(0X8C, ctx->r29) = ctx->r3;
            goto L_8006F554;
    }
    // 0x8006F530: sh          $v1, 0x8C($sp)
    MEM_H(0X8C, ctx->r29) = ctx->r3;
    // 0x8006F534: addiu       $v0, $zero, 0x14
    ctx->r2 = ADD32(0, 0X14);
    // 0x8006F538: sb          $v0, 0x7C($sp)
    MEM_B(0X7C, ctx->r29) = ctx->r2;
    // 0x8006F53C: andi        $v0, $v1, 0xFFEF
    ctx->r2 = ctx->r3 & 0XFFEF;
    // 0x8006F540: neg.s       $f22, $f22
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f22.fl); 
    ctx->f22.fl = -ctx->f22.fl;
    // 0x8006F544: sh          $zero, 0x7E($sp)
    MEM_H(0X7E, ctx->r29) = 0;
    // 0x8006F548: sw          $zero, 0x78($sp)
    MEM_W(0X78, ctx->r29) = 0;
    // 0x8006F54C: sb          $zero, 0x7D($sp)
    MEM_B(0X7D, ctx->r29) = 0;
    // 0x8006F550: sh          $v0, 0x8C($sp)
    MEM_H(0X8C, ctx->r29) = ctx->r2;
L_8006F554:
    // 0x8006F554: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8006F558: lwc1        $f0, -0x3490($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X3490);
    // 0x8006F55C: mul.s       $f0, $f20, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = MUL_S(ctx->f20.fl, ctx->f0.fl);
    // 0x8006F560: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8006F564: lwc1        $f2, -0x348C($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X348C);
    // 0x8006F568: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x8006F56C: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8006F570: lwc1        $f2, -0x3488($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X3488);
    // 0x8006F574: c.le.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl <= ctx->f0.fl;
    // 0x8006F578: nop

    // 0x8006F57C: bc1tl       L_8006F594
    if (c1cs) {
        // 0x8006F580: sub.s       $f0, $f0, $f2
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
            goto L_8006F594;
    }
    goto skip_0;
    // 0x8006F580: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    skip_0:
    // 0x8006F584: trunc.w.s   $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    ctx->f4.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x8006F588: mfc1        $v1, $f4
    ctx->r3 = (int32_t)ctx->f4.u32l;
    // 0x8006F58C: j           L_8006F5A4
    // 0x8006F590: nop

        goto L_8006F5A4;
    // 0x8006F590: nop

L_8006F594:
    // 0x8006F594: lui         $v0, 0x8000
    ctx->r2 = S32(0X8000 << 16);
    // 0x8006F598: trunc.w.s   $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    ctx->f4.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x8006F59C: mfc1        $v1, $f4
    ctx->r3 = (int32_t)ctx->f4.u32l;
    // 0x8006F5A0: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
L_8006F5A4:
    // 0x8006F5A4: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8006F5A8: lwc1        $f0, -0x3484($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X3484);
    // 0x8006F5AC: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8006F5B0: lwc1        $f2, -0x3480($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X3480);
    // 0x8006F5B4: div.s       $f0, $f20, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = DIV_S(ctx->f20.fl, ctx->f0.fl);
    // 0x8006F5B8: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x8006F5BC: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8006F5C0: lwc1        $f2, -0x347C($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X347C);
    // 0x8006F5C4: c.le.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl <= ctx->f0.fl;
    // 0x8006F5C8: nop

    // 0x8006F5CC: bc1t        L_8006F5E4
    if (c1cs) {
        // 0x8006F5D0: sh          $v1, 0x80($sp)
        MEM_H(0X80, ctx->r29) = ctx->r3;
            goto L_8006F5E4;
    }
    // 0x8006F5D0: sh          $v1, 0x80($sp)
    MEM_H(0X80, ctx->r29) = ctx->r3;
    // 0x8006F5D4: trunc.w.s   $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    ctx->f4.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x8006F5D8: mfc1        $v1, $f4
    ctx->r3 = (int32_t)ctx->f4.u32l;
    // 0x8006F5DC: j           L_8006F5F8
    // 0x8006F5E0: nop

        goto L_8006F5F8;
    // 0x8006F5E0: nop

L_8006F5E4:
    // 0x8006F5E4: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x8006F5E8: lui         $v0, 0x8000
    ctx->r2 = S32(0X8000 << 16);
    // 0x8006F5EC: trunc.w.s   $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    ctx->f4.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x8006F5F0: mfc1        $v1, $f4
    ctx->r3 = (int32_t)ctx->f4.u32l;
    // 0x8006F5F4: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
L_8006F5F8:
    // 0x8006F5F8: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8006F5FC: lwc1        $f0, -0x3478($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X3478);
    // 0x8006F600: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x8006F604: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8006F608: lwc1        $f2, -0x3474($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X3474);
    // 0x8006F60C: lw          $v0, 0x88($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X88);
    // 0x8006F610: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    // 0x8006F614: sh          $v1, 0x82($sp)
    MEM_H(0X82, ctx->r29) = ctx->r3;
    // 0x8006F618: lui         $v1, 0x900
    ctx->r3 = S32(0X900 << 16);
    // 0x8006F61C: sh          $zero, 0x4C($sp)
    MEM_H(0X4C, ctx->r29) = 0;
    // 0x8006F620: sh          $zero, 0x4E($sp)
    MEM_H(0X4E, ctx->r29) = 0;
    // 0x8006F624: swc1        $f24, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f24.u32l;
    // 0x8006F628: swc1        $f22, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f22.u32l;
    // 0x8006F62C: or          $v0, $v0, $v1
    ctx->r2 = ctx->r2 | ctx->r3;
    // 0x8006F630: swc1        $f0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f0.u32l;
    // 0x8006F634: swc1        $f20, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f20.u32l;
    // 0x8006F638: swc1        $f20, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f20.u32l;
    // 0x8006F63C: swc1        $f20, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f20.u32l;
    // 0x8006F640: swc1        $f20, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f20.u32l;
    // 0x8006F644: swc1        $f2, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f2.u32l;
    // 0x8006F648: jal         0x80041CBC
    // 0x8006F64C: sw          $v0, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r2;
    func_80041CBC(rdram, ctx);
        goto after_1;
    // 0x8006F64C: sw          $v0, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r2;
    after_1:
    // 0x8006F650: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    // 0x8006F654: andi        $a1, $s1, 0xFFFF
    ctx->r5 = ctx->r17 & 0XFFFF;
    // 0x8006F658: ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
    // 0x8006F65C: beq         $a1, $v0, L_8006F67C
    if (ctx->r5 == ctx->r2) {
        // 0x8006F660: andi        $a0, $s0, 0xFFFF
        ctx->r4 = ctx->r16 & 0XFFFF;
            goto L_8006F67C;
    }
    // 0x8006F660: andi        $a0, $s0, 0xFFFF
    ctx->r4 = ctx->r16 & 0XFFFF;
    // 0x8006F664: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x8006F668: addiu       $a2, $sp, 0x90
    ctx->r6 = ADD32(ctx->r29, 0X90);
    // 0x8006F66C: sw          $a3, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->r7;
    // 0x8006F670: sw          $a3, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->r7;
    // 0x8006F674: jal         0x80041D8C
    // 0x8006F678: sw          $a3, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->r7;
    func_80041D8C(rdram, ctx);
        goto after_2;
    // 0x8006F678: sw          $a3, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->r7;
    after_2:
L_8006F67C:
    // 0x8006F67C: andi        $v0, $s0, 0xFFFF
    ctx->r2 = ctx->r16 & 0XFFFF;
    // 0x8006F680: lw          $ra, 0xA8($sp)
    ctx->r31 = MEM_W(ctx->r29, 0XA8);
    // 0x8006F684: lw          $s1, 0xA4($sp)
    ctx->r17 = MEM_W(ctx->r29, 0XA4);
    // 0x8006F688: lw          $s0, 0xA0($sp)
    ctx->r16 = MEM_W(ctx->r29, 0XA0);
    // 0x8006F68C: ldc1        $f24, 0xC0($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0XC0);
    // 0x8006F690: ldc1        $f22, 0xB8($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0XB8);
    // 0x8006F694: ldc1        $f20, 0xB0($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0XB0);
    // 0x8006F698: jr          $ra
    // 0x8006F69C: addiu       $sp, $sp, 0xC8
    ctx->r29 = ADD32(ctx->r29, 0XC8);
    return;
    // 0x8006F69C: addiu       $sp, $sp, 0xC8
    ctx->r29 = ADD32(ctx->r29, 0XC8);
;}
RECOMP_FUNC void func_8006F6A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006F6A0: addiu       $sp, $sp, -0x80
    ctx->r29 = ADD32(ctx->r29, -0X80);
    // 0x8006F6A4: sw          $s1, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r17;
    // 0x8006F6A8: addu        $s1, $a0, $zero
    ctx->r17 = ADD32(ctx->r4, 0);
    // 0x8006F6AC: sw          $s0, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r16;
    // 0x8006F6B0: andi        $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 & 0XFFFF;
    // 0x8006F6B4: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x8006F6B8: sw          $ra, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r31;
    // 0x8006F6BC: sw          $s2, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r18;
    // 0x8006F6C0: sdc1        $f22, 0x78($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X78, ctx->r29);
    // 0x8006F6C4: sdc1        $f20, 0x70($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X70, ctx->r29);
    // 0x8006F6C8: lw          $s2, 0x4($s1)
    ctx->r18 = MEM_W(ctx->r17, 0X4);
    // 0x8006F6CC: beq         $a1, $v0, L_8006F904
    if (ctx->r5 == ctx->r2) {
        // 0x8006F6D0: addu        $s0, $a2, $zero
        ctx->r16 = ADD32(ctx->r6, 0);
            goto L_8006F904;
    }
    // 0x8006F6D0: addu        $s0, $a2, $zero
    ctx->r16 = ADD32(ctx->r6, 0);
    // 0x8006F6D4: slti        $v0, $a1, 0x3
    ctx->r2 = SIGNED(ctx->r5) < 0X3 ? 1 : 0;
    // 0x8006F6D8: beq         $v0, $zero, L_8006F6F0
    if (ctx->r2 == 0) {
        // 0x8006F6DC: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_8006F6F0;
    }
    // 0x8006F6DC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8006F6E0: beq         $a1, $v0, L_8006F70C
    if (ctx->r5 == ctx->r2) {
        // 0x8006F6E4: nop
    
            goto L_8006F70C;
    }
    // 0x8006F6E4: nop

    // 0x8006F6E8: j           L_8006FC6C
    // 0x8006F6EC: nop

        goto L_8006FC6C;
    // 0x8006F6EC: nop

L_8006F6F0:
    // 0x8006F6F0: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x8006F6F4: beq         $a1, $v0, L_8006F920
    if (ctx->r5 == ctx->r2) {
        // 0x8006F6F8: addiu       $v0, $zero, 0x4
        ctx->r2 = ADD32(0, 0X4);
            goto L_8006F920;
    }
    // 0x8006F6F8: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // 0x8006F6FC: beq         $a1, $v0, L_8006FC40
    if (ctx->r5 == ctx->r2) {
        // 0x8006F700: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_8006FC40;
    }
    // 0x8006F700: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8006F704: j           L_8006FC70
    // 0x8006F708: nop

        goto L_8006FC70;
    // 0x8006F708: nop

L_8006F70C:
    // 0x8006F70C: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8006F710: lw          $t0, 0x0($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X0);
    // 0x8006F714: lw          $t1, 0x4($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X4);
    // 0x8006F718: lw          $t2, 0x8($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X8);
    // 0x8006F71C: sw          $t0, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r8;
    // 0x8006F720: sw          $t1, 0x4($s2)
    MEM_W(0X4, ctx->r18) = ctx->r9;
    // 0x8006F724: sw          $t2, 0x8($s2)
    MEM_W(0X8, ctx->r18) = ctx->r10;
    // 0x8006F728: lw          $v0, 0x4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X4);
    // 0x8006F72C: lw          $t0, 0x0($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X0);
    // 0x8006F730: lw          $t1, 0x4($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X4);
    // 0x8006F734: lw          $t2, 0x8($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X8);
    // 0x8006F738: sw          $t0, 0x24($s2)
    MEM_W(0X24, ctx->r18) = ctx->r8;
    // 0x8006F73C: sw          $t1, 0x28($s2)
    MEM_W(0X28, ctx->r18) = ctx->r9;
    // 0x8006F740: sw          $t2, 0x2C($s2)
    MEM_W(0X2C, ctx->r18) = ctx->r10;
    // 0x8006F744: lw          $t0, 0x24($s2)
    ctx->r8 = MEM_W(ctx->r18, 0X24);
    // 0x8006F748: lw          $t1, 0x28($s2)
    ctx->r9 = MEM_W(ctx->r18, 0X28);
    // 0x8006F74C: lw          $t2, 0x2C($s2)
    ctx->r10 = MEM_W(ctx->r18, 0X2C);
    // 0x8006F750: sw          $t0, 0xC($s2)
    MEM_W(0XC, ctx->r18) = ctx->r8;
    // 0x8006F754: sw          $t1, 0x10($s2)
    MEM_W(0X10, ctx->r18) = ctx->r9;
    // 0x8006F758: sw          $t2, 0x14($s2)
    MEM_W(0X14, ctx->r18) = ctx->r10;
    // 0x8006F75C: lwc1        $f0, 0xC($s2)
    ctx->f0.u32l = MEM_W(ctx->r18, 0XC);
    // 0x8006F760: sw          $zero, 0x14($s2)
    MEM_W(0X14, ctx->r18) = 0;
    // 0x8006F764: lwc1        $f4, 0x14($s2)
    ctx->f4.u32l = MEM_W(ctx->r18, 0X14);
    // 0x8006F768: c.eq.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl == ctx->f4.fl;
    // 0x8006F76C: nop

    // 0x8006F770: bc1f        L_8006F79C
    if (!c1cs) {
        // 0x8006F774: addiu       $a0, $s2, 0xC
        ctx->r4 = ADD32(ctx->r18, 0XC);
            goto L_8006F79C;
    }
    // 0x8006F774: addiu       $a0, $s2, 0xC
    ctx->r4 = ADD32(ctx->r18, 0XC);
    // 0x8006F778: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8006F77C: lwc1        $f0, -0x3468($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X3468);
    // 0x8006F780: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8006F784: lwc1        $f2, -0x3464($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X3464);
    // 0x8006F788: swc1        $f4, 0xC($s2)
    MEM_W(0XC, ctx->r18) = ctx->f4.u32l;
    // 0x8006F78C: swc1        $f4, 0x10($s2)
    MEM_W(0X10, ctx->r18) = ctx->f4.u32l;
    // 0x8006F790: swc1        $f0, 0x14($s2)
    MEM_W(0X14, ctx->r18) = ctx->f0.u32l;
    // 0x8006F794: j           L_8006F7B4
    // 0x8006F798: swc1        $f2, 0x40($s2)
    MEM_W(0X40, ctx->r18) = ctx->f2.u32l;
        goto L_8006F7B4;
    // 0x8006F798: swc1        $f2, 0x40($s2)
    MEM_W(0X40, ctx->r18) = ctx->f2.u32l;
L_8006F79C:
    // 0x8006F79C: jal         0x8001CF58
    // 0x8006F7A0: nop

    normalize_vector(rdram, ctx);
        goto after_0;
    // 0x8006F7A0: nop

    after_0:
    // 0x8006F7A4: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8006F7A8: lwc1        $f2, -0x3460($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X3460);
    // 0x8006F7AC: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x8006F7B0: swc1        $f0, 0x40($s2)
    MEM_W(0X40, ctx->r18) = ctx->f0.u32l;
L_8006F7B4:
    // 0x8006F7B4: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8006F7B8: lwc1        $f6, -0x345C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X345C);
    // 0x8006F7BC: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8006F7C0: sw          $zero, 0x18($s2)
    MEM_W(0X18, ctx->r18) = 0;
    // 0x8006F7C4: sw          $zero, 0x20($s2)
    MEM_W(0X20, ctx->r18) = 0;
    // 0x8006F7C8: swc1        $f6, 0x1C($s2)
    MEM_W(0X1C, ctx->r18) = ctx->f6.u32l;
    // 0x8006F7CC: sw          $s2, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->r18;
    // 0x8006F7D0: lwc1        $f0, 0x2C($s2)
    ctx->f0.u32l = MEM_W(ctx->r18, 0X2C);
    // 0x8006F7D4: lwc1        $f2, 0x24($s2)
    ctx->f2.u32l = MEM_W(ctx->r18, 0X24);
    // 0x8006F7D8: swc1        $f4, 0x38($s2)
    MEM_W(0X38, ctx->r18) = ctx->f4.u32l;
    // 0x8006F7DC: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
    // 0x8006F7E0: c.eq.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl == ctx->f4.fl;
    // 0x8006F7E4: swc1        $f0, 0x34($s2)
    MEM_W(0X34, ctx->r18) = ctx->f0.u32l;
    // 0x8006F7E8: bc1f        L_8006F800
    if (!c1cs) {
        // 0x8006F7EC: swc1        $f2, 0x3C($s2)
        MEM_W(0X3C, ctx->r18) = ctx->f2.u32l;
            goto L_8006F800;
    }
    // 0x8006F7EC: swc1        $f2, 0x3C($s2)
    MEM_W(0X3C, ctx->r18) = ctx->f2.u32l;
    // 0x8006F7F0: c.eq.s      $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f2.fl == ctx->f4.fl;
    // 0x8006F7F4: nop

    // 0x8006F7F8: bc1tl       L_8006F800
    if (c1cs) {
        // 0x8006F7FC: swc1        $f6, 0x34($s2)
        MEM_W(0X34, ctx->r18) = ctx->f6.u32l;
            goto L_8006F800;
    }
    goto skip_0;
    // 0x8006F7FC: swc1        $f6, 0x34($s2)
    MEM_W(0X34, ctx->r18) = ctx->f6.u32l;
    skip_0:
L_8006F800:
    // 0x8006F800: jal         0x8001CF58
    // 0x8006F804: addiu       $a0, $s2, 0x34
    ctx->r4 = ADD32(ctx->r18, 0X34);
    normalize_vector(rdram, ctx);
        goto after_1;
    // 0x8006F804: addiu       $a0, $s2, 0x34
    ctx->r4 = ADD32(ctx->r18, 0X34);
    after_1:
    // 0x8006F808: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8006F80C: lwc1        $f0, -0x3458($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X3458);
    // 0x8006F810: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8006F814: lwc1        $f22, -0x3454($at)
    ctx->f22.u32l = MEM_W(ctx->r1, -0X3454);
    // 0x8006F818: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8006F81C: lwc1        $f2, -0x3450($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X3450);
    // 0x8006F820: sw          $zero, 0x50($s2)
    MEM_W(0X50, ctx->r18) = 0;
    // 0x8006F824: sw          $zero, 0x44($s2)
    MEM_W(0X44, ctx->r18) = 0;
    // 0x8006F828: swc1        $f0, 0x4C($s2)
    MEM_W(0X4C, ctx->r18) = ctx->f0.u32l;
    // 0x8006F82C: swc1        $f22, 0x48($s2)
    MEM_W(0X48, ctx->r18) = ctx->f22.u32l;
    // 0x8006F830: swc1        $f2, 0x54($s2)
    MEM_W(0X54, ctx->r18) = ctx->f2.u32l;
    // 0x8006F834: lwc1        $f0, 0x10($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X10);
    // 0x8006F838: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8006F83C: lwc1        $f2, -0x344C($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X344C);
    // 0x8006F840: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x8006F844: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x8006F848: c.lt.s      $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f0.fl < ctx->f20.fl;
    // 0x8006F84C: nop

    // 0x8006F850: bc1t        L_8006F86C
    if (c1cs) {
        // 0x8006F854: swc1        $f0, 0x58($s2)
        MEM_W(0X58, ctx->r18) = ctx->f0.u32l;
            goto L_8006F86C;
    }
    // 0x8006F854: swc1        $f0, 0x58($s2)
    MEM_W(0X58, ctx->r18) = ctx->f0.u32l;
    // 0x8006F858: jal         0x80003430
    // 0x8006F85C: nop

    rand_recomp(rdram, ctx);
        goto after_2;
    // 0x8006F85C: nop

    after_2:
    // 0x8006F860: andi        $v0, $v0, 0x3
    ctx->r2 = ctx->r2 & 0X3;
    // 0x8006F864: bne         $v0, $zero, L_8006F8B0
    if (ctx->r2 != 0) {
        // 0x8006F868: lui         $a0, 0x8004
        ctx->r4 = S32(0X8004 << 16);
            goto L_8006F8B0;
    }
    // 0x8006F868: lui         $a0, 0x8004
    ctx->r4 = S32(0X8004 << 16);
L_8006F86C:
    // 0x8006F86C: lwc1        $f0, 0x58($s2)
    ctx->f0.u32l = MEM_W(ctx->r18, 0X58);
    // 0x8006F870: c.lt.s      $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f0.fl < ctx->f20.fl;
    // 0x8006F874: nop

    // 0x8006F878: bc1f        L_8006F88C
    if (!c1cs) {
        // 0x8006F87C: nop
    
            goto L_8006F88C;
    }
    // 0x8006F87C: nop

    // 0x8006F880: lwc1        $f0, 0x10($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X10);
    // 0x8006F884: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
    // 0x8006F888: swc1        $f0, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f0.u32l;
L_8006F88C:
    // 0x8006F88C: lwc1        $f0, 0x54($s2)
    ctx->f0.u32l = MEM_W(ctx->r18, 0X54);
    // 0x8006F890: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8006F894: lwc1        $f2, -0x3448($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X3448);
    // 0x8006F898: mul.s       $f0, $f0, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f22.fl);
    // 0x8006F89C: swc1        $f20, 0x4C($s2)
    MEM_W(0X4C, ctx->r18) = ctx->f20.u32l;
    // 0x8006F8A0: sw          $zero, 0x30($s2)
    MEM_W(0X30, ctx->r18) = 0;
    // 0x8006F8A4: swc1        $f2, 0x50($s2)
    MEM_W(0X50, ctx->r18) = ctx->f2.u32l;
    // 0x8006F8A8: j           L_8006F8BC
    // 0x8006F8AC: swc1        $f0, 0x54($s2)
    MEM_W(0X54, ctx->r18) = ctx->f0.u32l;
        goto L_8006F8BC;
    // 0x8006F8AC: swc1        $f0, 0x54($s2)
    MEM_W(0X54, ctx->r18) = ctx->f0.u32l;
L_8006F8B0:
    // 0x8006F8B0: jal         0x80056EB0
    // 0x8006F8B4: addiu       $a0, $a0, -0x3470
    ctx->r4 = ADD32(ctx->r4, -0X3470);
    func_80056EB0(rdram, ctx);
        goto after_3;
    // 0x8006F8B4: addiu       $a0, $a0, -0x3470
    ctx->r4 = ADD32(ctx->r4, -0X3470);
    after_3:
    // 0x8006F8B8: sw          $v0, 0x30($s2)
    MEM_W(0X30, ctx->r18) = ctx->r2;
L_8006F8BC:
    // 0x8006F8BC: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x8006F8C0: lhu         $a0, -0x6A8C($v0)
    ctx->r4 = MEM_HU(ctx->r2, -0X6A8C);
    // 0x8006F8C4: jal         0x8003E684
    // 0x8006F8C8: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    func_8003E684(rdram, ctx);
        goto after_4;
    // 0x8006F8C8: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    after_4:
    // 0x8006F8CC: lwc1        $f0, 0x8($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8006F8D0: lw          $v0, 0x30($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X30);
    // 0x8006F8D4: lhu         $a0, 0x16($s1)
    ctx->r4 = MEM_HU(ctx->r17, 0X16);
    // 0x8006F8D8: beql        $v0, $zero, L_8006F8E0
    if (ctx->r2 == 0) {
        // 0x8006F8DC: neg.s       $f0, $f0
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
            goto L_8006F8E0;
    }
    goto skip_1;
    // 0x8006F8DC: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
    skip_1:
L_8006F8E0:
    // 0x8006F8E0: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8006F8E4: lwc1        $f0, 0x10($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X10);
    // 0x8006F8E8: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    // 0x8006F8EC: lw          $a1, 0x8($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X8);
    // 0x8006F8F0: lw          $a3, 0xC($s0)
    ctx->r7 = MEM_W(ctx->r16, 0XC);
    // 0x8006F8F4: jal         0x8006F4B0
    // 0x8006F8F8: nop

    func_8006F4B0(rdram, ctx);
        goto after_5;
    // 0x8006F8F8: nop

    after_5:
    // 0x8006F8FC: j           L_8006FC6C
    // 0x8006F900: sh          $v0, 0x5C($s2)
    MEM_H(0X5C, ctx->r18) = ctx->r2;
        goto L_8006FC6C;
    // 0x8006F900: sh          $v0, 0x5C($s2)
    MEM_H(0X5C, ctx->r18) = ctx->r2;
L_8006F904:
    // 0x8006F904: lw          $a0, 0x30($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X30);
    // 0x8006F908: beq         $a0, $zero, L_8006FC70
    if (ctx->r4 == 0) {
        // 0x8006F90C: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_8006FC70;
    }
    // 0x8006F90C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8006F910: jal         0x8005779C
    // 0x8006F914: nop

    func_8005779C(rdram, ctx);
        goto after_6;
    // 0x8006F914: nop

    after_6:
    // 0x8006F918: j           L_8006FC70
    // 0x8006F91C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8006FC70;
    // 0x8006F91C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8006F920:
    // 0x8006F920: lwc1        $f0, 0x54($s2)
    ctx->f0.u32l = MEM_W(ctx->r18, 0X54);
    // 0x8006F924: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x8006F928: lwc1        $f22, 0x0($s0)
    ctx->f22.u32l = MEM_W(ctx->r16, 0X0);
    // 0x8006F92C: c.le.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl <= ctx->f0.fl;
    // 0x8006F930: nop

    // 0x8006F934: bc1f        L_8006F964
    if (!c1cs) {
        // 0x8006F938: lui         $a2, 0x8014
        ctx->r6 = S32(0X8014 << 16);
            goto L_8006F964;
    }
    // 0x8006F938: lui         $a2, 0x8014
    ctx->r6 = S32(0X8014 << 16);
    // 0x8006F93C: sub.s       $f0, $f0, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f22.fl;
    // 0x8006F940: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x8006F944: nop

    // 0x8006F948: bc1f        L_8006F964
    if (!c1cs) {
        // 0x8006F94C: swc1        $f0, 0x54($s2)
        MEM_W(0X54, ctx->r18) = ctx->f0.u32l;
            goto L_8006F964;
    }
    // 0x8006F94C: swc1        $f0, 0x54($s2)
    MEM_W(0X54, ctx->r18) = ctx->f0.u32l;
    // 0x8006F950: lhu         $a0, 0x16($s1)
    ctx->r4 = MEM_HU(ctx->r17, 0X16);
    // 0x8006F954: jal         0x8003ED74
    // 0x8006F958: nop

    func_8003ED74(rdram, ctx);
        goto after_7;
    // 0x8006F958: nop

    after_7:
    // 0x8006F95C: j           L_8006FC70
    // 0x8006F960: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8006FC70;
    // 0x8006F960: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8006F964:
    // 0x8006F964: addiu       $a2, $a2, -0x7FA8
    ctx->r6 = ADD32(ctx->r6, -0X7FA8);
    // 0x8006F968: lwc1        $f0, 0x44($s2)
    ctx->f0.u32l = MEM_W(ctx->r18, 0X44);
    // 0x8006F96C: lwc1        $f12, 0x0($s2)
    ctx->f12.u32l = MEM_W(ctx->r18, 0X0);
    // 0x8006F970: add.s       $f0, $f0, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f22.fl;
    // 0x8006F974: lwc1        $f14, 0x8($s2)
    ctx->f14.u32l = MEM_W(ctx->r18, 0X8);
    // 0x8006F978: addiu       $a3, $sp, 0x28
    ctx->r7 = ADD32(ctx->r29, 0X28);
    // 0x8006F97C: jal         0x80067D90
    // 0x8006F980: swc1        $f0, 0x44($s2)
    MEM_W(0X44, ctx->r18) = ctx->f0.u32l;
    func_80067D90(rdram, ctx);
        goto after_8;
    // 0x8006F980: swc1        $f0, 0x44($s2)
    MEM_W(0X44, ctx->r18) = ctx->f0.u32l;
    after_8:
    // 0x8006F984: lwc1        $f2, 0x4($s2)
    ctx->f2.u32l = MEM_W(ctx->r18, 0X4);
    // 0x8006F988: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x8006F98C: nop

    // 0x8006F990: bc1f        L_8006FB1C
    if (!c1cs) {
        // 0x8006F994: nop
    
            goto L_8006FB1C;
    }
    // 0x8006F994: nop

    // 0x8006F998: lwc1        $f12, 0x0($s2)
    ctx->f12.u32l = MEM_W(ctx->r18, 0X0);
    // 0x8006F99C: lwc1        $f14, 0x8($s2)
    ctx->f14.u32l = MEM_W(ctx->r18, 0X8);
    // 0x8006F9A0: jal         0x800698F4
    // 0x8006F9A4: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    func_800698F4(rdram, ctx);
        goto after_9;
    // 0x8006F9A4: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    after_9:
    // 0x8006F9A8: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x8006F9AC: bne         $v0, $v1, L_8006F9D0
    if (ctx->r2 != ctx->r3) {
        // 0x8006F9B0: addiu       $a0, $sp, 0x18
        ctx->r4 = ADD32(ctx->r29, 0X18);
            goto L_8006F9D0;
    }
    // 0x8006F9B0: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    // 0x8006F9B4: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // 0x8006F9B8: addiu       $a1, $s2, 0xC
    ctx->r5 = ADD32(ctx->r18, 0XC);
    // 0x8006F9BC: ori         $a2, $zero, 0xFFFF
    ctx->r6 = 0 | 0XFFFF;
    // 0x8006F9C0: jal         0x8007483C
    // 0x8006F9C4: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    func_8007483C(rdram, ctx);
        goto after_10;
    // 0x8006F9C4: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    after_10:
    // 0x8006F9C8: j           L_8006FC6C
    // 0x8006F9CC: sw          $zero, 0x54($s2)
    MEM_W(0X54, ctx->r18) = 0;
        goto L_8006FC6C;
    // 0x8006F9CC: sw          $zero, 0x54($s2)
    MEM_W(0X54, ctx->r18) = 0;
L_8006F9D0:
    // 0x8006F9D0: jal         0x8001CFA0
    // 0x8006F9D4: addiu       $a1, $s2, 0x24
    ctx->r5 = ADD32(ctx->r18, 0X24);
    func_8001CFA0(rdram, ctx);
        goto after_11;
    // 0x8006F9D4: addiu       $a1, $s2, 0x24
    ctx->r5 = ADD32(ctx->r18, 0X24);
    after_11:
    // 0x8006F9D8: lwc1        $f2, 0x18($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X18);
    // 0x8006F9DC: lwc1        $f4, 0x34($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X34);
    // 0x8006F9E0: mul.s       $f2, $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f4.fl);
    // 0x8006F9E4: lwc1        $f8, 0x1C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x8006F9E8: lwc1        $f4, 0x38($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X38);
    // 0x8006F9EC: mul.s       $f8, $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = MUL_S(ctx->f8.fl, ctx->f4.fl);
    // 0x8006F9F0: lwc1        $f6, 0x3C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x8006F9F4: lwc1        $f4, 0x20($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X20);
    // 0x8006F9F8: mul.s       $f4, $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8006F9FC: add.s       $f2, $f2, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f8.fl;
    // 0x8006FA00: add.s       $f2, $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f4.fl;
    // 0x8006FA04: add.s       $f8, $f2, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = ctx->f2.fl + ctx->f2.fl;
    // 0x8006FA08: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8006FA0C: c.lt.s      $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f6.fl < ctx->f8.fl;
    // 0x8006FA10: nop

    // 0x8006FA14: bc1f        L_8006FB1C
    if (!c1cs) {
        // 0x8006FA18: mov.s       $f4, $f0
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    ctx->f4.fl = ctx->f0.fl;
            goto L_8006FB1C;
    }
    // 0x8006FA18: mov.s       $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    ctx->f4.fl = ctx->f0.fl;
    // 0x8006FA1C: lwc1        $f2, 0x44($s2)
    ctx->f2.u32l = MEM_W(ctx->r18, 0X44);
    // 0x8006FA20: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8006FA24: lwc1        $f0, -0x3444($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X3444);
    // 0x8006FA28: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x8006FA2C: nop

    // 0x8006FA30: bc1f        L_8006FA64
    if (!c1cs) {
        // 0x8006FA34: nop
    
            goto L_8006FA64;
    }
    // 0x8006FA34: nop

    // 0x8006FA38: lwc1        $f0, 0x24($s2)
    ctx->f0.u32l = MEM_W(ctx->r18, 0X24);
    // 0x8006FA3C: mul.s       $f0, $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x8006FA40: lwc1        $f2, 0x2C($s2)
    ctx->f2.u32l = MEM_W(ctx->r18, 0X2C);
    // 0x8006FA44: mul.s       $f2, $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x8006FA48: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x8006FA4C: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8006FA50: lwc1        $f2, -0x3440($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X3440);
    // 0x8006FA54: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x8006FA58: nop

    // 0x8006FA5C: bc1tl       L_8006FA64
    if (c1cs) {
        // 0x8006FA60: mov.s       $f4, $f6
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    ctx->f4.fl = ctx->f6.fl;
            goto L_8006FA64;
    }
    goto skip_2;
    // 0x8006FA60: mov.s       $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    ctx->f4.fl = ctx->f6.fl;
    skip_2:
L_8006FA64:
    // 0x8006FA64: lwc1        $f0, 0x48($s2)
    ctx->f0.u32l = MEM_W(ctx->r18, 0X48);
    // 0x8006FA68: mul.s       $f4, $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x8006FA6C: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8006FA70: lwc1        $f0, -0x343C($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X343C);
    // 0x8006FA74: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x8006FA78: nop

    // 0x8006FA7C: bc1f        L_8006FA98
    if (!c1cs) {
        // 0x8006FA80: sw          $zero, 0x44($s2)
        MEM_W(0X44, ctx->r18) = 0;
            goto L_8006FA98;
    }
    // 0x8006FA80: sw          $zero, 0x44($s2)
    MEM_W(0X44, ctx->r18) = 0;
    // 0x8006FA84: lwc1        $f0, 0x44($s2)
    ctx->f0.u32l = MEM_W(ctx->r18, 0X44);
    // 0x8006FA88: swc1        $f0, 0x2C($s2)
    MEM_W(0X2C, ctx->r18) = ctx->f0.u32l;
    // 0x8006FA8C: swc1        $f0, 0x28($s2)
    MEM_W(0X28, ctx->r18) = ctx->f0.u32l;
    // 0x8006FA90: j           L_8006FB1C
    // 0x8006FA94: swc1        $f0, 0x24($s2)
    MEM_W(0X24, ctx->r18) = ctx->f0.u32l;
        goto L_8006FB1C;
    // 0x8006FA94: swc1        $f0, 0x24($s2)
    MEM_W(0X24, ctx->r18) = ctx->f0.u32l;
L_8006FA98:
    // 0x8006FA98: lwc1        $f2, 0x54($s2)
    ctx->f2.u32l = MEM_W(ctx->r18, 0X54);
    // 0x8006FA9C: lwc1        $f6, 0x44($s2)
    ctx->f6.u32l = MEM_W(ctx->r18, 0X44);
    // 0x8006FAA0: c.lt.s      $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f2.fl < ctx->f6.fl;
    // 0x8006FAA4: nop

    // 0x8006FAA8: bc1f        L_8006FAD4
    if (!c1cs) {
        // 0x8006FAAC: nop
    
            goto L_8006FAD4;
    }
    // 0x8006FAAC: nop

    // 0x8006FAB0: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8006FAB4: lwc1        $f0, -0x3438($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X3438);
    // 0x8006FAB8: add.s       $f0, $f2, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x8006FABC: c.le.s      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.fl <= ctx->f0.fl;
    // 0x8006FAC0: nop

    // 0x8006FAC4: bc1f        L_8006FAD4
    if (!c1cs) {
        // 0x8006FAC8: swc1        $f0, 0x54($s2)
        MEM_W(0X54, ctx->r18) = ctx->f0.u32l;
            goto L_8006FAD4;
    }
    // 0x8006FAC8: swc1        $f0, 0x54($s2)
    MEM_W(0X54, ctx->r18) = ctx->f0.u32l;
    // 0x8006FACC: j           L_8006FC6C
    // 0x8006FAD0: swc1        $f6, 0x54($s2)
    MEM_W(0X54, ctx->r18) = ctx->f6.u32l;
        goto L_8006FC6C;
    // 0x8006FAD0: swc1        $f6, 0x54($s2)
    MEM_W(0X54, ctx->r18) = ctx->f6.u32l;
L_8006FAD4:
    // 0x8006FAD4: lwc1        $f2, 0x34($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X34);
    // 0x8006FAD8: mul.s       $f2, $f8, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = MUL_S(ctx->f8.fl, ctx->f2.fl);
    // 0x8006FADC: lwc1        $f0, 0x18($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X18);
    // 0x8006FAE0: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x8006FAE4: mul.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x8006FAE8: swc1        $f0, 0x24($s2)
    MEM_W(0X24, ctx->r18) = ctx->f0.u32l;
    // 0x8006FAEC: lwc1        $f2, 0x38($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X38);
    // 0x8006FAF0: mul.s       $f2, $f8, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = MUL_S(ctx->f8.fl, ctx->f2.fl);
    // 0x8006FAF4: lwc1        $f0, 0x1C($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x8006FAF8: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x8006FAFC: mul.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x8006FB00: swc1        $f0, 0x28($s2)
    MEM_W(0X28, ctx->r18) = ctx->f0.u32l;
    // 0x8006FB04: lwc1        $f2, 0x3C($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x8006FB08: mul.s       $f2, $f8, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = MUL_S(ctx->f8.fl, ctx->f2.fl);
    // 0x8006FB0C: lwc1        $f0, 0x20($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X20);
    // 0x8006FB10: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x8006FB14: mul.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x8006FB18: swc1        $f0, 0x2C($s2)
    MEM_W(0X2C, ctx->r18) = ctx->f0.u32l;
L_8006FB1C:
    // 0x8006FB1C: lwc1        $f0, 0x40($s2)
    ctx->f0.u32l = MEM_W(ctx->r18, 0X40);
    // 0x8006FB20: mul.s       $f0, $f0, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f22.fl);
    // 0x8006FB24: lwc1        $f6, 0x24($s2)
    ctx->f6.u32l = MEM_W(ctx->r18, 0X24);
    // 0x8006FB28: mul.s       $f6, $f6, $f22
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f6.fl = MUL_S(ctx->f6.fl, ctx->f22.fl);
    // 0x8006FB2C: lwc1        $f16, 0x28($s2)
    ctx->f16.u32l = MEM_W(ctx->r18, 0X28);
    // 0x8006FB30: mul.s       $f16, $f16, $f22
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f16.fl = MUL_S(ctx->f16.fl, ctx->f22.fl);
    // 0x8006FB34: lwc1        $f18, 0x2C($s2)
    ctx->f18.u32l = MEM_W(ctx->r18, 0X2C);
    // 0x8006FB38: mul.s       $f18, $f18, $f22
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f18.fl = MUL_S(ctx->f18.fl, ctx->f22.fl);
    // 0x8006FB3C: lwc1        $f20, 0x24($s2)
    ctx->f20.u32l = MEM_W(ctx->r18, 0X24);
    // 0x8006FB40: lwc1        $f10, 0x50($s2)
    ctx->f10.u32l = MEM_W(ctx->r18, 0X50);
    // 0x8006FB44: mul.s       $f10, $f20, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = MUL_S(ctx->f20.fl, ctx->f10.fl);
    // 0x8006FB48: lwc1        $f2, 0x4C($s2)
    ctx->f2.u32l = MEM_W(ctx->r18, 0X4C);
    // 0x8006FB4C: mul.s       $f2, $f2, $f22
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f22.fl);
    // 0x8006FB50: nop

    // 0x8006FB54: mul.s       $f10, $f10, $f22
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f10.fl = MUL_S(ctx->f10.fl, ctx->f22.fl);
    // 0x8006FB58: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8006FB5C: lwc1        $f0, 0x28($s2)
    ctx->f0.u32l = MEM_W(ctx->r18, 0X28);
    // 0x8006FB60: lwc1        $f12, 0x2C($s2)
    ctx->f12.u32l = MEM_W(ctx->r18, 0X2C);
    // 0x8006FB64: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x8006FB68: lwc1        $f2, 0x50($s2)
    ctx->f2.u32l = MEM_W(ctx->r18, 0X50);
    // 0x8006FB6C: mul.s       $f2, $f12, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = MUL_S(ctx->f12.fl, ctx->f2.fl);
    // 0x8006FB70: lwc1        $f8, 0x50($s2)
    ctx->f8.u32l = MEM_W(ctx->r18, 0X50);
    // 0x8006FB74: swc1        $f0, 0x28($s2)
    MEM_W(0X28, ctx->r18) = ctx->f0.u32l;
    // 0x8006FB78: mov.s       $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    ctx->f14.fl = ctx->f0.fl;
    // 0x8006FB7C: mul.s       $f8, $f14, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f8.fl = MUL_S(ctx->f14.fl, ctx->f8.fl);
    // 0x8006FB80: nop

    // 0x8006FB84: mul.s       $f2, $f2, $f22
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f22.fl);
    // 0x8006FB88: nop

    // 0x8006FB8C: mul.s       $f8, $f8, $f22
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f8.fl = MUL_S(ctx->f8.fl, ctx->f22.fl);
    // 0x8006FB90: lwc1        $f4, 0x0($s2)
    ctx->f4.u32l = MEM_W(ctx->r18, 0X0);
    // 0x8006FB94: add.s       $f4, $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8006FB98: lwc1        $f6, 0x4($s2)
    ctx->f6.u32l = MEM_W(ctx->r18, 0X4);
    // 0x8006FB9C: add.s       $f6, $f6, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f16.fl;
    // 0x8006FBA0: lwc1        $f0, 0x8($s2)
    ctx->f0.u32l = MEM_W(ctx->r18, 0X8);
    // 0x8006FBA4: add.s       $f0, $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f18.fl;
    // 0x8006FBA8: addiu       $s1, $sp, 0x50
    ctx->r17 = ADD32(ctx->r29, 0X50);
    // 0x8006FBAC: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x8006FBB0: sub.s       $f20, $f20, $f10
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f20.fl = ctx->f20.fl - ctx->f10.fl;
    // 0x8006FBB4: addiu       $a1, $s2, 0x34
    ctx->r5 = ADD32(ctx->r18, 0X34);
    // 0x8006FBB8: swc1        $f4, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->f4.u32l;
    // 0x8006FBBC: sub.s       $f12, $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f12.fl = ctx->f12.fl - ctx->f2.fl;
    // 0x8006FBC0: swc1        $f6, 0x4($s2)
    MEM_W(0X4, ctx->r18) = ctx->f6.u32l;
    // 0x8006FBC4: swc1        $f0, 0x8($s2)
    MEM_W(0X8, ctx->r18) = ctx->f0.u32l;
    // 0x8006FBC8: sub.s       $f14, $f14, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f14.fl = ctx->f14.fl - ctx->f8.fl;
    // 0x8006FBCC: swc1        $f20, 0x24($s2)
    MEM_W(0X24, ctx->r18) = ctx->f20.u32l;
    // 0x8006FBD0: swc1        $f12, 0x2C($s2)
    MEM_W(0X2C, ctx->r18) = ctx->f12.u32l;
    // 0x8006FBD4: jal         0x8001D240
    // 0x8006FBD8: swc1        $f14, 0x28($s2)
    MEM_W(0X28, ctx->r18) = ctx->f14.u32l;
    func_8001D240(rdram, ctx);
        goto after_12;
    // 0x8006FBD8: swc1        $f14, 0x28($s2)
    MEM_W(0X28, ctx->r18) = ctx->f14.u32l;
    after_12:
    // 0x8006FBDC: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x8006FBE0: addiu       $s0, $sp, 0x18
    ctx->r16 = ADD32(ctx->r29, 0X18);
    // 0x8006FBE4: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x8006FBE8: lw          $t0, 0xC($s2)
    ctx->r8 = MEM_W(ctx->r18, 0XC);
    // 0x8006FBEC: lw          $t1, 0x10($s2)
    ctx->r9 = MEM_W(ctx->r18, 0X10);
    // 0x8006FBF0: lw          $t2, 0x14($s2)
    ctx->r10 = MEM_W(ctx->r18, 0X14);
    // 0x8006FBF4: sw          $t0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r8;
    // 0x8006FBF8: sw          $t1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r9;
    // 0x8006FBFC: sw          $t2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r10;
    // 0x8006FC00: jal         0x8001D3C4
    // 0x8006FC04: addiu       $a2, $s2, 0xC
    ctx->r6 = ADD32(ctx->r18, 0XC);
    func_8001D3C4(rdram, ctx);
        goto after_13;
    // 0x8006FC04: addiu       $a2, $s2, 0xC
    ctx->r6 = ADD32(ctx->r18, 0XC);
    after_13:
    // 0x8006FC08: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x8006FC0C: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x8006FC10: lw          $t0, 0x18($s2)
    ctx->r8 = MEM_W(ctx->r18, 0X18);
    // 0x8006FC14: lw          $t1, 0x1C($s2)
    ctx->r9 = MEM_W(ctx->r18, 0X1C);
    // 0x8006FC18: lw          $t2, 0x20($s2)
    ctx->r10 = MEM_W(ctx->r18, 0X20);
    // 0x8006FC1C: sw          $t0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r8;
    // 0x8006FC20: sw          $t1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r9;
    // 0x8006FC24: sw          $t2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r10;
    // 0x8006FC28: jal         0x8001D3C4
    // 0x8006FC2C: addiu       $a2, $s2, 0x18
    ctx->r6 = ADD32(ctx->r18, 0X18);
    func_8001D3C4(rdram, ctx);
        goto after_14;
    // 0x8006FC2C: addiu       $a2, $s2, 0x18
    ctx->r6 = ADD32(ctx->r18, 0X18);
    after_14:
    // 0x8006FC30: jal         0x80059F10
    // 0x8006FC34: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    func_80059F10(rdram, ctx);
        goto after_15;
    // 0x8006FC34: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    after_15:
    // 0x8006FC38: j           L_8006FC70
    // 0x8006FC3C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8006FC70;
    // 0x8006FC3C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8006FC40:
    // 0x8006FC40: lw          $a0, 0x30($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X30);
    // 0x8006FC44: beq         $a0, $zero, L_8006FC6C
    if (ctx->r4 == 0) {
        // 0x8006FC48: addiu       $a0, $a0, 0x28
        ctx->r4 = ADD32(ctx->r4, 0X28);
            goto L_8006FC6C;
    }
    // 0x8006FC48: addiu       $a0, $a0, 0x28
    ctx->r4 = ADD32(ctx->r4, 0X28);
    // 0x8006FC4C: lw          $a2, 0x58($s2)
    ctx->r6 = MEM_W(ctx->r18, 0X58);
    // 0x8006FC50: jal         0x80059B50
    // 0x8006FC54: addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    func_80059B50(rdram, ctx);
        goto after_16;
    // 0x8006FC54: addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    after_16:
    // 0x8006FC58: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x8006FC5C: lw          $a1, 0x30($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X30);
    // 0x8006FC60: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x8006FC64: jal         0x80057C8C
    // 0x8006FC68: addu        $a2, $s2, $zero
    ctx->r6 = ADD32(ctx->r18, 0);
    func_80057C8C(rdram, ctx);
        goto after_17;
    // 0x8006FC68: addu        $a2, $s2, $zero
    ctx->r6 = ADD32(ctx->r18, 0);
    after_17:
L_8006FC6C:
    // 0x8006FC6C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8006FC70:
    // 0x8006FC70: lw          $ra, 0x6C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X6C);
    // 0x8006FC74: lw          $s2, 0x68($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X68);
    // 0x8006FC78: lw          $s1, 0x64($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X64);
    // 0x8006FC7C: lw          $s0, 0x60($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X60);
    // 0x8006FC80: ldc1        $f22, 0x78($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X78);
    // 0x8006FC84: ldc1        $f20, 0x70($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X70);
    // 0x8006FC88: jr          $ra
    // 0x8006FC8C: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
    return;
    // 0x8006FC8C: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
;}
